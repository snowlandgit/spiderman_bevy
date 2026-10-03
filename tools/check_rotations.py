import bpy
bpy.ops.wm.open_mainfile(filepath=r"H:\SteamLibrary\steamapps\common\Marvel's Spider-Man Remastered\spiderman_bevy\tools\character.blend")
a=bpy.data.objects['SpiderMan']
from collections import Counter
print('BONE_MODES',Counter(p.rotation_mode for p in a.pose.bones))
