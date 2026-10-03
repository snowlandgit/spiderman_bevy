// oracle.cpp: runs Spider-Man's own traversal code (the swing, swing jump and fall states of the locally installed
// Spider-Man.exe, mapped without being started) on scripted scenarios, and records every frame. The Rust port in
// crates/sm_traversal is checked against these records. Built on ArkWeb's research harness (H:\arkre\harness: smenv.h
// stand-ins for the engine, turn.h for the mover's turn). Local research tool: nothing from the game is redistributed;
// the outputs are numbers.
//
//   oracle <scenario.txt> <out.bin> [out.json]
//
// Scenario lines (meters, seconds, degrees; # comments):
//   dt 0.0166667          frames 300            momentum 0
//   pos x y z             vel x y z             yaw deg (his facing, 0 = +z)
//   swing t ax ay az px py pz     a swing at time t: anchor (the pivot) and attach (the web's surface point)
//   stick t x y           the left stick from time t (x right, y forward)
//   r2 t 0|1              the swing button from time t (held = 1)
//   jump t                the jump button pressed at t (the swing's release event, buffered 0.05 s)
//   cam fixed yaw pitch   or   cam follow rate pitch   (the camera's yaw closes in on his travel)
//   drift 0|1             the swing processor's pivot drift (exe+ab8410), on by default
//   enter t jump|fall kind kind2 dx dz hspeed vy gravity gravity_after input
//                         at time t, the jump state (HeroStateJumpLocal) or the fall entered with this data (the
//                         launches: the point launch is kind 0x2a = 42, the jump off a perch 0x1d = 29; the fall from a
//                         ledge kind 11 with kind2 53 = none); the other fields from exe+a7d820's defaults
#include "H:/arkre/harness/smenv.h"
#include "H:/SteamLibrary/steamapps/common/Saints Row the Third/ArkWeb/src/ak_host/turn.h"

#include <fstream>
#include <sstream>

using namespace smenv;

namespace
{
	constexpr uint64_t kSwing = 0x6df2690, kSwingJump = 0x6dfa880, kFall = 0x6ded020, kJump = 0x6deda80;
	constexpr uintptr_t kVtSwingJumpLocal = 0x38d4b58, kVtJumpLocal = 0x38c1628;
	using Fn1 = uint64_t (*)(void*);
	using FnF = void (*)(void*, float);
	using Fn2 = void (*)(void*, const void*);
	using Exit = void (*)(void*, void*);
	using TimeFn = float (*)(void*);

	struct SwingCmd
	{
		float t, anchor[3], attach[3];
	};
	struct EnterCmd
	{
		float t;
		bool  fall;
		int   kind, kind2;
		float dx, dz, hspeed, vy, gravity, gravityAfter, input;
	};
	struct Key
	{
		float t, x, y;
	};
	struct Scenario
	{
		float                 dt = 1.0f / 60.0f;
		int                   frames = 300;
		float                 momentum = 0.0f;
		float                 pos[3] = { 0, 40, 0 }, vel[3] = { 0, 0, 20 }, yaw = 0.0f;
		std::vector<SwingCmd> swings;
		std::vector<EnterCmd> enters;
		std::vector<Key>      sticks, r2;
		std::vector<float>    jumps;
		bool                  camFollow = true;
		float                 camYaw = 0.0f, camPitch = -12.0f, camRate = 3.0f;
		bool                  drift = true;
	};

	Scenario Load(const char* a_path)
	{
		Scenario      s;
		std::ifstream in(a_path);
		if (!in) {
			printf("no scenario %s\n", a_path);
			exit(1);
		}
		std::string line;
		while (std::getline(in, line)) {
			if (auto h = line.find('#'); h != std::string::npos) line.resize(h);
			std::istringstream l(line);
			std::string        k;
			if (!(l >> k)) continue;
			if (k == "dt") l >> s.dt;
			else if (k == "frames") l >> s.frames;
			else if (k == "momentum") l >> s.momentum;
			else if (k == "pos") l >> s.pos[0] >> s.pos[1] >> s.pos[2];
			else if (k == "vel") l >> s.vel[0] >> s.vel[1] >> s.vel[2];
			else if (k == "yaw") l >> s.yaw;
			else if (k == "swing") {
				SwingCmd c;
				l >> c.t >> c.anchor[0] >> c.anchor[1] >> c.anchor[2] >> c.attach[0] >> c.attach[1] >> c.attach[2];
				s.swings.push_back(c);
			} else if (k == "stick") {
				Key c;
				l >> c.t >> c.x >> c.y;
				s.sticks.push_back(c);
			} else if (k == "r2") {
				Key c{};
				l >> c.t >> c.x;
				s.r2.push_back(c);
			} else if (k == "jump") {
				float t;
				l >> t;
				s.jumps.push_back(t);
			} else if (k == "cam") {
				std::string m;
				l >> m;
				if (m == "fixed") s.camFollow = false, l >> s.camYaw >> s.camPitch;
				else s.camFollow = true, l >> s.camRate >> s.camPitch;
			} else if (k == "enter") {
				EnterCmd    c{};
				std::string st;
				l >> c.t >> st >> c.kind >> c.kind2 >> c.dx >> c.dz >> c.hspeed >> c.vy >> c.gravity >> c.gravityAfter >> c.input;
				c.fall = st == "fall";
				s.enters.push_back(c);
			} else if (k == "drift") {
				int d;
				l >> d;
				s.drift = d != 0;
			} else {
				printf("unknown scenario key %s\n", k.c_str());
				exit(1);
			}
		}
		return s;
	}
	const Key* At(const std::vector<Key>& a_keys, float a_t)
	{
		const Key* r = nullptr;
		for (auto& k : a_keys)
			if (k.t <= a_t + 1e-6f) r = &k;
		return r;
	}

	// ---- the record ---------------------------------------------------------------------------------------------
	// Blobs per snapshot (offsets in the game's objects): what the Rust port reads and writes.
	struct BlobDef
	{
		const char* name;
		uint8_t*    ptr;
		uint32_t    size;
	};
	std::vector<BlobDef> Blobs()
	{
		return {
			{ "swing", g_state, 0x600 },
			{ "swingProc", g_swingComp, 0x180 },
			{ "tracker", g_tracker, 0x800 },
			{ "jump", g_jump, 0x300 },
			{ "fall", g_fall, 0x320 },
			{ "jumpProc", g_jumpProc, 0x400 },
			{ "fallProc", g_fallProc, 0x400 },
			{ "mover", g_mover, 0x800 },
			{ "anim", g_animComp, 0x100 },
		};
	}
	void WriteSnapshot(FILE* a_f)
	{
		for (auto& b : Blobs()) fwrite(b.ptr, 1, b.size, a_f);
	}

	// exe+15a0560 (entity by handle): as ArkWeb's native.h answers since its facing and ground-jump fixes, the tracker's
	// focus target (+0x19c) and spline target (+0x114) resolve to nothing; every other handle to the component-less
	// stand-in entity
	void* EntityById(void* a_handle)
	{
		if (a_handle == g_tracker + 0x19c || a_handle == g_tracker + 0x114) return nullptr;
		return g_otherEntity;
	}

	void Rows(float a_yaw, float* a_m)
	{
		float fx = std::sin(a_yaw), fz = std::cos(a_yaw);
		float m[16] = { fz, 0, -fx, 0, 0, 1, 0, 0, fx, 0, fz, 0, 0, 0, 0, 1 };
		memcpy(a_m, m, sizeof(m));
	}
}

int main(int argc, char** argv)
{
	if (argc < 3) {
		printf("usage: oracle <scenario.txt> <out.bin> [out.json]\n");
		return 1;
	}
	Scenario sc = Load(argv[1]);
	if (!Init()) return 1;
	Patch(0x15a0560, reinterpret_cast<void*>(&EntityById));
	FILE* out = fopen(argv[2], "wb");
	FILE* js = argc > 3 ? fopen(argv[3], "w") : nullptr;
	if (!out) return 1;

	// header: magic, version, frame count (patched), blob names and sizes
	fwrite("SMORACLE", 1, 8, out);
	uint32_t version = 1, count = 0;
	fwrite(&version, 4, 1, out);
	long countAt = ftell(out);
	fwrite(&count, 4, 1, out);
	uint32_t nb = static_cast<uint32_t>(Blobs().size());
	fwrite(&nb, 4, 1, out);
	for (auto& b : Blobs()) {
		char name[16] = {};
		strncpy(name, b.name, 15);
		fwrite(name, 1, 16, out);
		fwrite(&b.size, 4, 1, out);
	}

	At<float>(g_tracker, 0x1e8) = sc.momentum;
	// +0x396: the tracker's "in the air" flag (its ground update, exe+862830, isn't run here); momentum then decays by
	// the air list (exe+85f650), as while swinging in the game
	At<uint8_t>(g_tracker, 0x396) = 1;
	float pos[3] = { sc.pos[0], sc.pos[1], sc.pos[2] };
	Rows(sc.yaw * 0.01745329f, g_heroMat);
	memcpy(g_heroMat + 12, pos, 12);
	{
		float prev[3] = { pos[0] - sc.vel[0] * sc.dt, pos[1] - sc.vel[1] * sc.dt, pos[2] - sc.vel[2] * sc.dt };
		MoverMoved(prev, pos, sc.dt);
	}
	float camYaw = sc.camFollow ? std::atan2(sc.vel[0], sc.vel[2]) : sc.camYaw * 0.01745329f;

	void* s = g_state;
	At<void*>(s, 0) = reinterpret_cast<void*>(smcall::g_base + 0x38ce990);  // Hero::HeroStateSwingLocal
	At<void*>(s, 8) = g_entity;
	At<float>(s, 0x10) = 1.0f;
	smcall::Fn<Fn1>(0x9c8600)(s);
	void* j = g_jump;
	At<void*>(j, 0) = reinterpret_cast<void*>(smcall::g_base + 0x38d4b58);  // Hero::HeroStateSwingJumpLocal
	At<void*>(j, 8) = g_entity;
	At<float>(j, 0x10) = 1.0f;
	smcall::Fn<Fn1>(0xa85f70)(j);
	void* fall = g_fall;
	At<void*>(fall, 0) = reinterpret_cast<void*>(smcall::g_base + 0x38c9220);  // Hero::HeroStateFallLocal
	At<void*>(fall, 8) = g_entity;
	At<float>(fall, 0x10) = 1.0f;
	smcall::Fn<Fn1>(0xa85f70)(fall);

	// mode 0 swing, 1 swing jump, 2 fall, 3 none yet (air before the first swing: a fall)
	int    mode = 3;
	size_t enteredAt = 0;
	float  turnV = 0.0f;
	size_t nextSwing = 0, nextEnter = 0;
	auto   AirState = [&]() { return mode == 2 ? fall : j; };
	auto   StartSwing = [&](const SwingCmd& c) {
        alignas(16) uint8_t td[0x100] = {};
		smcall::Fn<Fn1>(0xab3820)(td);
		using SetPointsFn = void (*)(void*, const void*, const void*);
		smcall::Fn<SetPointsFn>(0xab5da0)(td, c.anchor, c.attach);
		if (Get<float>(g_tracker, 0x364) < Get<float>(g_swingCfg.data(), 0xa0)) At<uint16_t>(td, 0x6c) |= 0x100;
		memcpy(g_swingComp + 0x150, c.anchor, 12);
		memcpy(g_swingComp + 0x15c, c.anchor, 12);
		memcpy(g_swingComp + 0x168, c.attach, 12);
		At<float>(g_swingComp, 0x174) = 0.0f;
		At<double>(s, 0xd8) = g_time;
		smcall::Fn<Fn2>(0xab97e0)(s, td);
		mode = 0;
	};

	smcall::Fn<FnF>(0x85f580)(g_tracker, sc.dt);
	if (js) fprintf(js, "{\"dt\": %.7f, \"frames\": [\n", sc.dt);
	for (int f = 0; f < sc.frames; ++f) {
		float t = f * sc.dt;
		// inputs
		const Key* st = At(sc.sticks, t);
		g_stick[0] = st ? st->x : 0.0f, g_stick[1] = st ? st->y : 0.0f;
		SetAction(0x4453c00, g_stick[0]);
		SetAction(0x73420c96, g_stick[1]);
		const Key* r2 = At(sc.r2, t);
		float      r2v = r2 ? r2->x : 1.0f;
		SetAction(0xcd07a28, r2v);
		g_releaseEvent = false;
		for (float jt : sc.jumps)
			if (t >= jt - 1e-6f && t < jt + 0.05f) g_releaseEvent = true;
		g_look = 0.0f;
		g_time += sc.dt;
		At<double>(reinterpret_cast<void*>(smcall::g_base), 0x7a7fbd8) = sc.dt;
		// the camera: behind him, its yaw closing in on his travel (or fixed)
		if (sc.camFollow) {
			float vx = g_moverVel[0], vz = g_moverVel[2];
			if (vx * vx + vz * vz > 1.0f) {
				float want = std::atan2(vx, vz), d = arkweb::turn::WrapPi(want - camYaw);
				camYaw = arkweb::turn::WrapPi(camYaw + d * (1.0f - std::exp(-sc.camRate * sc.dt)));
			}
		}
		{
			float p = sc.camPitch * 0.01745329f;
			float fx = std::sin(camYaw) * std::cos(p), fy = std::sin(p), fz = std::cos(camYaw) * std::cos(p);
			float up[3] = { -std::sin(camYaw) * std::sin(p), std::cos(p), -std::cos(camYaw) * std::sin(p) };
			// side = up x fwd (the game's rows; it points to the camera's left)
			float sx = up[1] * fz - up[2] * fy, sy = up[2] * fx - up[0] * fz, sz = up[0] * fy - up[1] * fx;
			float m[16] = { sx, sy, sz, 0, up[0], up[1], up[2], 0, fx, fy, fz, 0, pos[0] - fx * 5.5f, pos[1] - fy * 5.5f + 1.0f, pos[2] - fz * 5.5f, 1 };
			memcpy(g_camMat, m, 64);
		}
		memcpy(g_heroMat + 12, pos, 12);
		uint32_t flags = g_releaseEvent ? 1u : 0u;
		float    heroBefore[16], velBefore[3];
		memcpy(heroBefore, g_heroMat, 64);
		memcpy(velBefore, g_moverVel, 12);
		fwrite(&f, 4, 1, out);
		WriteSnapshot(out);  // "pre": before tracker, transitions and update

		smcall::Fn<FnF>(0x85f580)(g_tracker, sc.dt);
		uint64_t req = 0;
		alignas(16) uint8_t reqData[0x200] = {};
		if (nextEnter < sc.enters.size() && t >= sc.enters[nextEnter].t - 1e-6f) {
			// a launch (or a fall) entered directly: the state he is in ends, the jump or fall state starts with the data
			const EnterCmd& c = sc.enters[nextEnter++];
			if (mode == 0) smcall::Fn<Exit>(0xaba8a0)(s, nullptr);
			if (mode == 1) smcall::Fn<Exit>(0xa86270)(j, nullptr);
			if (mode == 2) smcall::Fn<Exit>(0xa701a0)(fall, nullptr);
			alignas(16) uint8_t td[0x100] = {};
			smcall::Fn<Fn1>(0xa7d820)(td);
			float dir[4] = { c.dx, 0.0f, c.dz, 0.0f }, up[4] = { 0.0f, 1.0f, 0.0f, 0.0f };
			using DirFn = void (*)(void*, const float*, const float*);
			using KindFn = void (*)(void*, uint32_t);
			smcall::Fn<DirFn>(0xa7d8c0)(td, dir, up);
			smcall::Fn<KindFn>(0xa7dc50)(td, static_cast<uint32_t>(c.kind));
			At<uint8_t>(td, 0x82) = static_cast<uint8_t>(c.kind2);
			At<float>(td, 0x58) = c.vy, At<float>(td, 0x5c) = c.hspeed, At<float>(td, 0x60) = c.gravity, At<float>(td, 0x64) = c.gravityAfter;
			At<float>(td, 0x74) = c.input;
			if (c.fall) {
				At<double>(fall, 0xd8) = g_time;
				smcall::Fn<Fn2>(0xa70080)(fall, td);
				mode = 2, req = kFall;
			} else {
				// HeroStateJumpLocal: the swing jump's class with its own identity slots
				At<void*>(j, 0) = reinterpret_cast<void*>(smcall::g_base + kVtJumpLocal);
				At<double>(j, 0xd8) = g_time;
				smcall::Fn<Fn2>(0xa86490)(j, td);
				mode = 1, req = kJump;
			}
			memcpy(reqData, td, sizeof(td));
			enteredAt = f;
			flags |= 8;
		} else if (nextSwing < sc.swings.size() && t >= sc.swings[nextSwing].t - 1e-6f && mode != 0) {
			if (mode == 1) smcall::Fn<Exit>(0xa86270)(j, nullptr);
			if (mode == 2) smcall::Fn<Exit>(0xa701a0)(fall, nullptr);
			StartSwing(sc.swings[nextSwing++]);
			enteredAt = f;
			flags |= 2;
		} else if (mode == 0 && static_cast<size_t>(f) > enteredAt) {
			int before = g_reqCount;
			smcall::Fn<Fn1>(0xaba1f0)(s);
			if (g_reqCount != before) {
				req = g_reqDesc;
				memcpy(reqData, g_reqData, sizeof(g_reqData));
				flags |= 4;
				if (g_reqDesc == kSwingJump) {
					smcall::Fn<Exit>(0xaba8a0)(s, nullptr);
					At<void*>(j, 0) = reinterpret_cast<void*>(smcall::g_base + kVtSwingJumpLocal);
					At<double>(j, 0xd8) = g_time;
					smcall::Fn<Fn2>(0xa86490)(j, g_reqData);
					mode = 1;
					enteredAt = f;
				}
			}
		} else if ((mode == 1 || mode == 2) && static_cast<size_t>(f) > enteredAt) {
			At<uint8_t>(g_animComp, 0x98) = Get<float>(AirState(), 0x1f0) > 0.0f ? 1 : 0;
			int before = g_reqCount;
			smcall::Fn<Fn1>(0xa86ad0)(AirState());
			if (g_reqCount != before) {
				req = g_reqDesc;
				memcpy(reqData, g_reqData, sizeof(g_reqData));
				flags |= 4;
				if (g_reqDesc == kFall && mode == 1) {
					smcall::Fn<Exit>(0xa86270)(j, nullptr);
					At<double>(fall, 0xd8) = g_time;
					smcall::Fn<Fn2>(0xa70080)(fall, g_reqData);
					mode = 2;
					enteredAt = f;
				}
			}
		}
		fwrite(&mode, 4, 1, out);
		fwrite(&flags, 4, 1, out);
		fwrite(&req, 8, 1, out);
		fwrite(reqData, 1, 0x100, out);
		WriteSnapshot(out);  // "mid": after transitions, before the update

		g_bbCalls = 0, g_bb12 = 0, g_facingSet = false, g_snap = -1;
		g_disp[0] = g_disp[1] = g_disp[2] = 0.0f;
		if (mode == 0) {
			if (sc.drift) {
				// the swing processor's pivot drift (exe+ab8410), as swing_chain.cpp / ArkWeb's native.h port it
				uint8_t*     p = g_swingComp;
				const float* pv = reinterpret_cast<const float*>(p + 0x15c);
				const float* ho = reinterpret_cast<const float*>(p + 0x168);
				float        dx = pv[0] - ho[0], dz = pv[2] - ho[2], m = std::max(std::fabs(dx), std::fabs(dz));
				if (m > 0.0f) {
					dx /= m, dz /= m;
					float l = 1.0f / std::sqrt(dx * dx + dz * dz);
					dx *= l, dz *= l;
				}
				float A[3] = { pv[0], ho[1], pv[2] }, B[3] = { ho[0] + dx, ho[1], ho[2] + dz };
				float ab[3] = { B[0] - A[0], B[1] - A[1], B[2] - A[2] }, L = ab[0] * ab[0] + ab[1] * ab[1] + ab[2] * ab[2];
				float u = L >= 1e-8f ? ((pos[0] - A[0]) * ab[0] + (pos[1] - A[1]) * ab[1] + (pos[2] - A[2]) * ab[2]) / L : 0.0f;
				u = std::min(1.0f, std::max(0.0f, u));
				float st2 = smcall::Fn<TimeFn>(0x20dc660)(s);
				float fr = std::min(1.0f, std::max(0.0f, (st2 - 2.0f) * 0.6666667f));
				fr = std::max(std::max(fr, u), Get<float>(p, 0x174));
				At<float>(p, 0x174) = fr;
				At<float>(p, 0x150) = A[0] + ab[0] * fr, At<float>(p, 0x154) = pv[1], At<float>(p, 0x158) = A[2] + ab[2] * fr;
			}
			smcall::Fn<FnF>(0xac30e0)(s, sc.dt);
			smcall::Fn<FnF>(0xac3c80)(s, sc.dt);
		} else if (mode == 1 || mode == 2) {
			smcall::Fn<FnF>(0xa8d5b0)(AirState(), sc.dt);
			if (mode == 2) smcall::Fn<FnF>(0xa71a40)(fall, sc.dt);
		} else {
			// before the first swing: plain gravity (the scenario should start with a swing)
			g_disp[0] = g_moverVel[0] * sc.dt, g_disp[1] = g_moverVel[1] * sc.dt - 13.0f * sc.dt * sc.dt, g_disp[2] = g_moverVel[2] * sc.dt;
		}
		fwrite(g_disp, 4, 3, out);
		fwrite(g_facingSet ? g_facing : heroBefore + 8, 4, 3, out);
		int snap = g_snap;
		fwrite(&snap, 4, 1, out);
		WriteSnapshot(out);  // "post": after the update, before the mover moves and turns him

		float before[3] = { pos[0], pos[1], pos[2] };
		for (int a = 0; a < 3; ++a) pos[a] += g_disp[a];
		MoverMoved(before, pos, sc.dt);
		// the mover's turn toward the facing the state asked for (turn.h; constants per state as set on entry)
		if (g_facingSet && mode != 3) {
			static const float kSwingK[3] = { -1.42f, -44.0f, 4.18879f }, kJumpK[3] = { -1.2f, -33.0f, 7.85398f }, kFallK[3] = { -1.18f, -18.0f, 10.472f };
			// the jump's by its kind (exe+a7d260): the swing jump's for 0x11, the default for the launches
			const float* k = mode == 0 ? kSwingK : (mode == 1 && Get<int>(j, 0x2c0) == 0x11) ? kJumpK : kFallK;
			float        want[3], up[3] = { 0, 1, 0 };
			if (arkweb::turn::WantFacing(g_facing, want)) {
				float fw[3] = { g_heroMat[8], g_heroMat[9], g_heroMat[10] };
				arkweb::turn::Step(fw, up, want, turnV, k, g_snap > 0, sc.dt);
				// rows: side = up x fwd
				g_heroMat[8] = fw[0], g_heroMat[9] = fw[1], g_heroMat[10] = fw[2];
				g_heroMat[0] = fw[2], g_heroMat[1] = 0.0f, g_heroMat[2] = -fw[0];
			}
		}
		memcpy(g_heroMat + 12, pos, 12);
		// the mover's facing (+0x658, which the air states read) after its turn, as the game's mover keeps it
		// (MoverMoved copied the facing from before the turn)
		memcpy(g_mover + 0x658, g_heroMat + 8, 12);
		fwrite(g_heroMat, 4, 16, out);
		fwrite(&turnV, 4, 1, out);
		fwrite(g_camMat, 4, 16, out);
		fwrite(heroBefore, 4, 16, out);
		fwrite(velBefore, 4, 3, out);
		float in[4] = { g_stick[0], g_stick[1], r2v, t };
		fwrite(in, 4, 4, out);
		++count;
		if (js)
			fprintf(js, "%s{\"t\": %.5f, \"mode\": %d, \"pos\": [%.5f, %.5f, %.5f], \"vel\": [%.5f, %.5f, %.5f], \"fwd\": [%.5f, %.5f, %.5f], \"req\": %llu}\n", f ? "," : "", t, mode,
				pos[0], pos[1], pos[2], g_moverVel[0], g_moverVel[1], g_moverVel[2], g_heroMat[8], g_heroMat[9], g_heroMat[10], static_cast<unsigned long long>(req));
	}
	if (js) fprintf(js, "]}\n"), fclose(js);
	fseek(out, countAt, SEEK_SET);
	fwrite(&count, 4, 1, out);
	fclose(out);
	printf("%u frames -> %s\n", count, argv[2]);
	return 0;
}
