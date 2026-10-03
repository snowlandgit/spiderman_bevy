"""Sample original imported actions before glTF export for independent pose checks."""
import bpy,json,struct,math
from pathlib import Path
from mathutils import Matrix
root=Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'));arm=bpy.data.objects['SpiderMan']
for track in arm.animation_data.nla_tracks:track.mute=True
b=(root/'assets/character/spiderman.glb').read_bytes();size=struct.unpack_from('<I',b,12)[0];g=json.loads(b[20:20+size]);names=[g['nodes'][i]['name'] for i in g['skins'][0]['joints']]
swizzle=Matrix.Rotation(-math.pi/2,4,'X')
clips={'web_swing_fwd_rh_spiderman':[0,.7666667,1.5,2.3666667,3.5,4.7333333],
'web_swing_intro_fromairaggro_fwd_rh_spiderman':[0,.1333333,.3,.5,.7333333],
'web_zip_fwd_2hand_spiderman':[0,.1666667,.3,.6,.9666667],
'web_zip_fwd_fastfall_2h_spiderman':[0,.1666667,.3,.6,.9666667],
'web_zip_fwd_skydive_2h_spiderman':[0,.1666667,.3,.6,.9666667],
'web_zip_attach_short_fwd_spiderman':[0,.1333333,.3,.6],
'stand_jump_spiderman':[0,.3,.6,.9],
'stand_chargejump_up_spiderman':[0,.3,.6,1.,1.6],
'stand_chargejump_fwd_spiderman':[0,.3,.6,1.,2.6],
'stand_sprint_high_jump_fwd_spiderman':[0,.3,.6,1.,1.7],
'web_swing_release_mid1_spiderman':[0,.7,1.4,2.6],
'web_swing_jump_high_spiderman':[0,.7,1.4,2.4],
'wall_run_up_intro_spiderman':[0,.3,.8,1.5666667]}
report={'reference':'Original AnimClip decoding in Blender, sampled before export','bones':names,'clips':[]}
for name,times in clips.items():
    action=bpy.data.actions[name];arm.animation_data.action=action;frames=[]
    for time in times:
        frame=time*60;whole=int(frame);bpy.context.scene.frame_set(whole,subframe=frame-whole);bpy.context.view_layer.update()
        pose=[swizzle@arm.pose.bones[n].matrix for n in names]
        frames.append({'time':time,'matrices':[[[float(m[r][c]) for c in range(4)] for r in range(4)] for m in pose]})
    report['clips'].append({'name':name,'frames':frames});print('NATIVE_POSE',name,len(frames),flush=True)
(root/'research/native_pose_samples.json').write_text(json.dumps(report,separators=(',',':')))
