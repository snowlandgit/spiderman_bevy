"""Record the verified executable, asset and source versions after successful checks."""
import argparse, datetime, hashlib, json
from pathlib import Path
root=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser()
parser.add_argument('--tests-passed',type=int,required=True)
args=parser.parse_args()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
installed=root/'spiderman_bevy.exe'; build=root/'target/debug/spiderman_bevy.exe'
report={
    'verified_at':datetime.datetime.now(datetime.timezone.utc).isoformat(),
    'tests_passed':args.tests_passed,
    'rendered_check':json.loads((root/'smoke_report.json').read_text()),
    'direction_rendered_check':json.loads((root/'direction_smoke_report.json').read_text()),
    'jump_rendered_check':json.loads((root/'jump_smoke_report.json').read_text()),
    'presentation_tuning_sha256':sha(root/'assets/tuning/sandbox_presentation.json'),
    'swing_tuning_sha256':sha(root/'assets/tuning/sandbox_swing.json'),
    'air_tuning_sha256':sha(root/'assets/tuning/sandbox_air.json'),
    'controller_comparison':json.loads((root/'research/controller_comparison.json').read_text()),
    'jump_tuning_sha256':sha(root/'assets/tuning/sandbox_jump.json'),
    'zip_rendered_check':json.loads((root/'zip_smoke_report.json').read_text()),
    'animation_pose_validation':json.loads((root/'research/animation_pose_validation.json').read_text()),
    'mirror_validation':json.loads((root/'research/mirror_validation.json').read_text()),
    'asset_validation':json.loads((root/'validation_report.json').read_text()),
    'world_validation':json.loads((root/'research/world_validation.json').read_text()),
    'world_layout_sha256':sha(root/'assets/world/layout.json'),
    'world_asset_sha256':{p.name:sha(p) for p in sorted((root/'assets/world').glob('*.glb'))},
    'rig_validation':json.loads((root/'research/rig_validation.json').read_text()),
    'executable_sha256':sha(installed),
    'installed_matches_build':sha(installed)==sha(build) if build.exists() else None,
    'character_glb_sha256':sha(root/'assets/character/spiderman.glb'),
    'source_sha256':{p.name:sha(p) for p in sorted((root/'src').glob('*.rs'))},
    'asset_tool_sha256':{name:sha(root/'tools'/name) for name in
        ['convert_character.py','validate_assets.py','verify_character_rig.py',
         'prepare_world.py','convert_world.py','validate_world.py',
         'mirror_clips.py','sample_native_poses.py','verify_animation_poses.py']},
    'native_source_math_reference_tests':True,
    'original_game_trajectory_measured':False,
    'one_to_one_fidelity_verified':False,
    'known_gaps':['Native traversal coordination remains partial',
                  'Complete animation graph, additive evaluation and IK remain unported',
                  'Camera filtering and layered materials are approximate'],
}
assert report['controller_comparison']['scenarios']['held']['revised']['entry_metrics']['first_arc_minimum_height'] > 13.
assert report['controller_comparison']['scenarios']['held']['revised']['entry_metrics']['first_tick_velocity'][1] > -1.
assert report['world_validation']['passed']
assert report['zip_rendered_check']['passed'] and report['jump_rendered_check']['passed']
assert report['zip_rendered_check']['swing_to_zips'] > 0
assert report['animation_pose_validation']['passed'] and report['mirror_validation']['passed']
assert 0.44 <= report['rendered_check']['presentation']['first_main_swing_age'] < 0.6
assert report['rendered_check']['presentation']['interpolated_frames'] > 0
assert report['rendered_check']['presentation']['max_main_seek_rate'] <= 3.001
assert report['rendered_check']['presentation']['main_swing_captured']
assert report['rendered_check']['web_selection']['new_shots'] > 0
assert report['rendered_check']['web_selection']['behind_shots'] == 0
assert report['rendered_check']['web_selection']['behind_body_shots'] == 0
assert report['direction_rendered_check']['passed']
assert report['direction_rendered_check']['web_selection']['new_shots'] >= 3
assert report['direction_rendered_check']['web_selection']['behind_shots'] == 0
assert report['direction_rendered_check']['web_selection']['behind_body_shots'] == 0
assert report['rendered_check']['passed'] and report['asset_validation']['asset_validation_passed']
(root/'research/revision_validation.json').write_text(json.dumps(report,indent=2))
print('Recorded verified build and character hashes.')
