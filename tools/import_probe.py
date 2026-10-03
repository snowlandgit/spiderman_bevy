import importlib.util,sys,json
from pathlib import Path
import bpy
root=Path(__file__).resolve().parents[1]
pkg=root/'tools/luna_engine_io_tools-main'
spec=importlib.util.spec_from_file_location('luna_engine_io_tools',pkg/'__init__.py',submodule_search_locations=[str(pkg)])
module=importlib.util.module_from_spec(spec); sys.modules[spec.name]=module; spec.loader.exec_module(module); module.register()
bpy.ops.object.select_all(action='SELECT'); bpy.ops.object.delete(use_global=False)
result=bpy.ops.import_scene.engine_model(filepath=str(root/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model'),import_all_lods=False,import_shape_keys=False)
print('IMPORT_RESULT',result,flush=True)
info=[]
for obj in bpy.context.scene.objects:
    print('OBJECT',obj.name,obj.type,tuple(obj.dimensions),flush=True)
    if obj.type=='ARMATURE': print('BONES',[(b.name,tuple(b.head_local)) for b in obj.data.bones][:35],flush=True)
    info.append({'name':obj.name,'type':obj.type,'dimensions':list(obj.dimensions)})
(root/'tools/model_info.json').write_text(json.dumps(info,indent=2))
bpy.ops.wm.save_as_mainfile(filepath=str(root/'tools/character.blend'))
