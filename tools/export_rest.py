from pathlib import Path
import bpy
from mathutils import Matrix
root=Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'))
arm=bpy.data.objects['SpiderMan']
arm.animation_data.action=None
for track in arm.animation_data.nla_tracks:track.mute=True
for pb in arm.pose.bones:pb.matrix_basis=Matrix.Identity(4)
bpy.context.scene.frame_set(0)
bpy.ops.export_scene.gltf(filepath=str(root/'assets/character/spiderman_rest.glb'),export_format='GLB',export_animations=False,export_skins=True,export_all_influences=False,export_morph=False)
