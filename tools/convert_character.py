"""Original Remastered mesh/rig + original animation clips -> Bevy-ready GLB.
Mesh decoding: ALERT; AnimClip decoding: Luna Engine IO Tools (both GPL-3.0).
"""
import sys,importlib.util,json,math,struct
from pathlib import Path
import bpy
from mathutils import Matrix,Vector,Quaternion
root=Path(__file__).resolve().parents[1]
pkg=root/'tools/luna_engine_io_tools-main'
spec=importlib.util.spec_from_file_location('luna_engine_io_tools',pkg/'__init__.py',submodule_search_locations=[str(pkg)])
module=importlib.util.module_from_spec(spec); sys.modules[spec.name]=module; spec.loader.exec_module(module); module.register()
# Adapt Remastered's single sample-data section to the newer reader's paged interface.
original_reader=module.anim_import.get_dat1_data
def remastered_reader(filepath):
    data,blocks,table_end=original_reader(filepath)
    if data is None: return data,blocks,table_end
    hashes=module.anim_import.BLOCK_HASHES
    old_data=blocks.get(0x3A7B4855)
    blocks=dict(blocks)
    if old_data:
        blocks[hashes['AnimClipSampleDataPaged']]=old_data
    else:
        blocks[hashes['AnimClipSampleDataPaged']]=(len(data),0)
    if hashes['AnimClipSampleElem'] not in blocks:
        blocks[hashes['AnimClipSampleElem']]=(len(data),0)
    return data,blocks,table_end
module.anim_import.get_dat1_data=remastered_reader
bpy.ops.object.select_all(action='SELECT'); bpy.ops.object.delete(use_global=False)
swizzle=Matrix.Rotation(math.pi/2,4,'X')
lines=iter((root/'tools/character.ascii').read_text().splitlines())
count=int(next(lines)); bones=[]
for i in range(count):
    name=next(lines); parent=int(next(lines)); values=list(map(float,next(lines).split()))
    x,y,z,qx,qy,qz,qw=values
    mat=swizzle@ (Matrix.Translation((x,y,z))@Quaternion((qw,qx,qy,qz)).to_matrix().to_4x4())
    bones.append((name,parent,mat))
bpy.ops.object.armature_add(enter_editmode=True); arm=bpy.context.active_object; arm.name='SpiderMan'
for b in list(arm.data.edit_bones): arm.data.edit_bones.remove(b)
for name,parent,mat in bones:
    eb=arm.data.edit_bones.new(name); eb.length=.07; eb.matrix=mat
for name,parent,mat in bones:
    if parent>=0: arm.data.edit_bones[name].parent=arm.data.edit_bones[bones[parent][0]]
bpy.ops.object.mode_set(mode='OBJECT')
# A new EditBone has zero length. Set its length BEFORE its matrix so Blender
# can retain the native orientation when aligning the bone's head and tail.
rest_error=max(abs(arm.data.bones[name].matrix_local[r][c]-mat[r][c])
               for name,_,mat in bones for r in range(4) for c in range(4))
if rest_error>0.00005:
    raise RuntimeError(f'Blender bind pose differs from native matrices: {rest_error}')
print('BLENDER_BIND_VERIFIED',rest_error,flush=True)
for i,(name,_,_) in enumerate(bones):
    arm.data.bones[name]['engine_joint_index']=i; arm.data.bones[name]['engine_joint_name']=name
arm['engine_mpu']=1/4096
arm.animation_data_create()
texture_dir=root/'assets/character/textures'
material_maps=json.loads((root/'tools/material_textures.json').read_text())
materials={}
base_overrides={'hero_spiderman_body_modcolor':'hero_spiderman_body_c','reviewasset_spiderman_leg_modcolor':'hero_spiderman_leg_modcolor_c','hero_spiderman_leg':'hero_spiderman_leg_modcolor_c','hero_spiderman_shoe':'hero_spiderman_shoe_modcolor_c','reviewasset_spiderman_shoe_modcolor':'hero_spiderman_shoe_modcolor_c','hero_spiderman_head_eyeframe':'hero_spiderman_head_c','hero_spiderman_head_newweb':'hero_spiderman_head_c','hero_spiderman_eye_lense':'hero_spiderman_eye_c','hero_spiderman_eyeshutters':'hero_spiderman_eyeshutters_c','hero_spiderman_glove_modcolor':'hero_spiderman_glove_modcolor_c','hero_spiderman_newgauntlet':'hero_spiderman_newgauntlet_c','hero_spiderman_webshooter':'hero_spiderman_webshooter_c'}
normal_overrides={'hero_spiderman_body_modcolor':'hero_spiderman_body_n','reviewasset_spiderman_leg_modcolor':'reviewasset_spiderman_leg_n','hero_spiderman_head_newweb':'hero_spiderman_head_n','hero_spiderman_head_eyeframe':'hero_spiderman_head_n'}
def material(path):
    name=Path(path.replace('\\','/')).stem.lower()
    if name in materials: return materials[name]
    mat=bpy.data.materials.new(name); mat.use_nodes=True; bsdf=mat.node_tree.nodes.get('Principled BSDF')
    bsdf.inputs['Roughness'].default_value=.47
    if name=='hero_spiderman_spider_sign' or 'white' in name or 'eye' in name and 'frame' not in name and 'shutter' not in name:
        bsdf.inputs['Base Color'].default_value=(.88,.9,.93,1)
    elif 'glass' in name: bsdf.inputs['Base Color'].default_value=(.012,.016,.023,1)
    tex=base_overrides.get(name)
    if tex and (texture_dir/(tex+'.png')).exists():
        node=mat.node_tree.nodes.new('ShaderNodeTexImage'); node.image=bpy.data.images.load(str(texture_dir/(tex+'.png')),check_existing=True)
        mat.node_tree.links.new(node.outputs['Color'],bsdf.inputs['Base Color'])
    ntex=normal_overrides.get(name)
    if ntex is None:
        candidates=[Path(p.replace('\\','/')).stem.lower() for p in material_maps.get(name,[]) if p.lower().endswith('_n.texture') and 'detail' not in p.lower() and 'wrinkle' not in p.lower() and 'waist' not in p.lower() and 'damage' not in p.lower()]
        ntex=candidates[0] if candidates else None
    if ntex and (texture_dir/(ntex+'.png')).exists():
        node=mat.node_tree.nodes.new('ShaderNodeTexImage'); node.image=bpy.data.images.load(str(texture_dir/(ntex+'.png')),check_existing=True); node.image.colorspace_settings.name='Non-Color'
        norm=mat.node_tree.nodes.new('ShaderNodeNormalMap'); norm.inputs['Strength'].default_value=.55
        mat.node_tree.links.new(node.outputs['Color'],norm.inputs['Color']); mat.node_tree.links.new(norm.outputs['Normal'],bsdf.inputs['Normal'])
    materials[name]=mat; return mat
mesh_count=int(next(lines)); total_vertices=0; total_triangles=0
for mi in range(mesh_count):
    name=next(lines); uv_count=int(next(lines)); tex_count=int(next(lines))
    for _ in range(tex_count): next(lines); next(lines)
    vc=int(next(lines)); vertices=[]; normals=[]; uvs=[]; weights=[]
    for vi in range(vc):
        x,y,z=map(float,next(lines).split()); vertices.append((x,-z,y))
        x,y,z=map(float,next(lines).split()); normals.append((x,-z,y)); next(lines)
        uv=list(map(float,next(lines).split())); uvs.append((uv[0],1-uv[1]))
        for _ in range(uv_count-1): next(lines)
        groups=list(map(int,next(lines).split())); ws=list(map(float,next(lines).split())); weights.append([(g,w) for g,w in zip(groups,ws) if w>0])
    fc=int(next(lines)); faces=[tuple(map(int,next(lines).split())) for _ in range(fc)]
    # Index streams pad triangles with repeated indices; ignore those.
    faces=[(f[0],f[2],f[1]) for f in faces if len(set(f))==3 and all(0<=v<vc for v in f)]
    mesh=bpy.data.meshes.new(f'SuitPart_{mi:02}'); mesh.from_pydata(vertices,[],faces); mesh.update()
    uv_layer=mesh.uv_layers.new(name='UVMap')
    for loop in mesh.loops: uv_layer.data[loop.index].uv=uvs[loop.vertex_index]
    for polygon in mesh.polygons: polygon.use_smooth=True
    mesh.normals_split_custom_set_from_vertices(normals)
    obj=bpy.data.objects.new(f'SuitPart_{mi:02}',mesh); bpy.context.collection.objects.link(obj); obj.parent=arm
    obj.data.materials.append(material(name[5:]))
    groups=[obj.vertex_groups.new(name=b[0]) for b in bones]
    for vi,entries in enumerate(weights):
        for g,w in entries:
            if g<len(groups): groups[g].add([vi],w,'REPLACE')
    modifier=obj.modifiers.new('OriginalSkin','ARMATURE'); modifier.object=arm
    total_vertices+=vc; total_triangles+=len(faces)
    print('MESH',mi,vc,len(faces),obj.data.materials[0].name,flush=True)
bpy.context.view_layer.objects.active=arm; bpy.ops.object.select_all(action='DESELECT'); arm.select_set(True)
selection_path=root/'tools/animation_selection.json'
selection=set(json.loads(selection_path.read_text())) if selection_path.exists() else None
clips=[]
for path in sorted((root/'assets/source/characters/hero/hero_spiderman/animations').rglob('*.animclip')):
    if selection is not None and path.stem not in selection: continue
    try:
        bpy.context.view_layer.objects.active=arm
        if arm.animation_data: arm.animation_data.action=None
        result=bpy.ops.import_anim.engine_anim(filepath=str(path))
        if 'FINISHED' not in result: raise RuntimeError(str(result))
        action=arm.animation_data.action
        if not action: raise RuntimeError('Importer produced no action')
        action.name=path.stem; action.use_fake_user=True
        fps=bpy.context.scene.render.fps / bpy.context.scene.render.fps_base
        # Keep all clips on one 60 FPS timeline while retaining original duration.
        curves=[]
        for layer in action.layers:
            for strip in layer.strips:
                for bag in strip.channelbags: curves.extend(bag.fcurves)
        for curve in curves:
            for point in curve.keyframe_points:
                point.co.x*=60/fps; point.handle_left.x*=60/fps; point.handle_right.x*=60/fps
        flags=int(action.get('engine_clip_flags',0)) & 0xffffffff
        if flags & 0x20:
            # The native loop period includes interpolation from the last sample to the first.
            end=action.frame_range[1]+60/fps
            for curve in curves:
                if curve.keyframe_points:
                    point=curve.keyframe_points.insert(end,curve.keyframe_points[0].co.y)
                    point.interpolation='LINEAR'
        arm.animation_data.action=None
        track=arm.animation_data.nla_tracks.new(); track.name=path.stem
        strip=track.strips.new(path.stem,0,action)
        clips.append({'name':path.stem,'duration':(action.frame_range[1]-action.frame_range[0])/60,'source_fps':fps,'looping':bool(flags & 0x20),'additive':bool(flags & 0x40),'native_duration':float(action.get('engine_clip_duration',0))})
        print('CLIP_OK',path.stem,clips[-1],flush=True)
    except Exception as exc:
        print('CLIP_ERROR',path.stem,repr(exc),flush=True)
# Root motion is supplied by the Rust controller. Keep imported auxiliary data in .blend only.
for obj in list(bpy.context.scene.objects):
    if obj.type=='EMPTY': bpy.data.objects.remove(obj,do_unlink=True)
arm.animation_data.action=None
# Placeholder joints absent from this suit have no vertex weights.
bpy.context.view_layer.objects.active=arm
bpy.ops.object.mode_set(mode='EDIT')
original_names={name for name,_,_ in bones}
for bone in list(arm.data.edit_bones):
    if bone.name not in original_names: arm.data.edit_bones.remove(bone)
bpy.ops.object.mode_set(mode='OBJECT')
for track in arm.animation_data.nla_tracks: track.mute=True
bpy.context.scene.render.fps=60; bpy.context.scene.render.fps_base=1
bpy.context.scene.frame_set(0)
# Identity root pose for stable controller space; original root bone animation remains in clips.
bpy.ops.wm.save_as_mainfile(filepath=str(root/'tools/character.blend'))
for track in arm.animation_data.nla_tracks: track.mute=False
bpy.ops.object.select_all(action='SELECT')
(root/'assets/character').mkdir(parents=True,exist_ok=True)
bpy.ops.export_scene.gltf(filepath=str(root/'assets/character/spiderman.glb'),export_format='GLB',export_animation_mode='NLA_TRACKS',export_nla_strips=True,export_skins=True,export_all_influences=False,export_morph=False,export_force_sampling=True,export_anim_slide_to_zero=True,export_yup=True,export_extras=False)
report={'vertices':total_vertices,'triangles':total_triangles,'bones':len(bones),'meshes':mesh_count,'blender_bind_max_matrix_error':rest_error,'clips':clips}
(root/'assets/character/conversion.json').write_text(json.dumps(report,indent=2))
print('EXPORT_COMPLETE',report,flush=True)




