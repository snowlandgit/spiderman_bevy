/* SwingRegion_140abf160 @ 0x140abf160 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_140abf160(longlong param_1,float *param_2,float *param_3,float *param_4,
                     undefined8 param_5,float *param_6,float param_7)

{
  float fVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dacd70);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar4 = FUN_14167ab40(lVar5 + 0x58,0x146dd6340);
  }
  else {
    uVar4 = func_0x0001416799a0(lVar5 + 0x80);
  }
  lVar5 = func_0x000140923770(uVar4);
  fVar1 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
  fVar14 = *(float *)(lVar3 + 0x340);
  fVar13 = *(float *)(lVar3 + 0x344);
  fVar12 = *(float *)(lVar3 + 0x348);
  fVar10 = *(float *)(param_1 + 0x430);
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  fVar6 = (_DAT_14382dce0 /* 1.0, 0x3f800000 */ - fVar14) * *(float *)(lVar5 + 0x208) + fVar14;
  fVar6 = (fVar14 - fVar6) * fVar10 + fVar6;
  fVar7 = (_DAT_14382dce0 /* 1.0, 0x3f800000 */ - fVar13) * *(float *)(lVar5 + 0x20c) + fVar13;
  fVar7 = (fVar13 - fVar7) * fVar10 + fVar7;
  fVar8 = (_DAT_14382dce0 /* 1.0, 0x3f800000 */ - fVar12) * *(float *)(lVar5 + 0x210) + fVar12;
  fVar9 = (float)FUN_140876340(param_5);
  fVar13 = _DAT_1438ac374 /* 0.02222222276031971, 0x3cb60b61 */;
  fVar14 = _DAT_143830124 /* 57.2957763671875, 0x42652ee0 */;
  uVar2 = _DAT_14382e160 /* None, 0x7fffffff */;
  fVar11 = (float)((uint)(fVar9 * _DAT_143830124 /* 57.2957763671875, 0x42652ee0 */) & _DAT_14382e160 /* None, 0x7fffffff */);
  if (fVar9 * _DAT_143830124 /* 57.2957763671875, 0x42652ee0 */ <= 0.0) {
    fVar6 = (fVar11 - _DAT_14382f2cc /* 20.0, 0x41a00000 */) * _DAT_14384421c /* 0.02500000037252903, 0x3ccccccd */;
    if (fVar6 <= 0.0) {
      fVar6 = 0.0;
    }
    if (fVar1 <= fVar6) {
      fVar6 = fVar1;
    }
    fVar6 = (((fVar12 - fVar8) * fVar10 + fVar8) - fVar7) * fVar6 + fVar7;
  }
  else {
    fVar12 = (fVar11 - _DAT_14382f0e0 /* 5.0, 0x40a00000 */) * _DAT_1438ac374 /* 0.02222222276031971, 0x3cb60b61 */;
    if (fVar12 <= 0.0) {
      fVar12 = 0.0;
    }
    if (fVar1 <= fVar12) {
      fVar12 = fVar1;
    }
    fVar6 = (fVar1 - fVar12) * (fVar7 - fVar6) + fVar6;
  }
  if (*(int *)(param_1 + 0x574) == 2) {
    fVar6 = 0.0;
  }
  fVar12 = (fVar6 - fVar1) * _DAT_145d9fe90 /* 1.0, 0x3f800000 */ + fVar1;
  if (*(float *)(param_1 + 0x518) <= fVar12) {
    fVar12 = *(float *)(param_1 + 0x518);
  }
  *(float *)(param_1 + 0x518) = fVar12;
  fVar12 = *(float *)(param_1 + 0x4fc);
  fVar10 = (float)FUN_1420dc660(param_1);
  fVar10 = (fVar10 - _DAT_143839a5c /* 0.4000000059604645, 0x3ecccccd */) * _DAT_1438ad110 /* 2.222222089767456, 0x400e38e3 */;
  fVar13 = ((float)((uint)(fVar12 * fVar14) & uVar2) - _DAT_14384bc0c /* 45.0, 0x42340000 */) * fVar13;
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  if (fVar1 <= fVar10) {
    fVar10 = fVar1;
  }
  if (fVar1 <= fVar13) {
    fVar13 = fVar1;
  }
  fVar14 = *(float *)(param_1 + 0x518) - fVar10 * param_7 * fVar13 * _DAT_143837a24 /* 0.6000000238418579, 0x3f19999a */;
  if (fVar14 <= 0.0) {
    fVar14 = 0.0;
  }
  *(float *)(param_1 + 0x518) = fVar14;
  fVar13 = *param_3;
  fVar12 = param_3[1];
  fVar10 = *param_4;
  fVar1 = param_4[1];
  fVar6 = param_6[1];
  fVar7 = *param_6;
  fVar11 = (fVar13 - fVar10) * fVar7 + (fVar12 - fVar1) * fVar6 +
           (param_3[2] - param_4[2]) * param_6[2];
  fVar8 = *param_4;
  fVar9 = param_4[1];
  param_2[2] = ((((param_3[2] - param_4[2]) - param_6[2] * fVar11) + param_4[2]) - param_3[2]) *
               fVar14 + param_3[2];
  *param_2 = ((((fVar13 - fVar10) - fVar7 * fVar11) + fVar8) - fVar13) * fVar14 + fVar13;
  param_2[1] = ((((fVar12 - fVar1) - fVar6 * fVar11) + fVar9) - fVar12) * fVar14 + fVar12;
  return param_2;
}


