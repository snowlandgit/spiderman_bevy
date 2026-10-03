/* SwingRegion_140abf580 @ 0x140abf580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_140abf580(longlong param_1,float *param_2,float *param_3,undefined8 param_4,
                     float param_5,float param_6)

{
  longlong lVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar3 = (float)FUN_1402c2450(param_3);
  uVar2 = _DAT_14382e160 /* None, 0x7fffffff */;
  fVar8 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
  fVar9 = 0.0;
  fVar4 = (float)((uint)param_3[2] & _DAT_14382e160 /* None, 0x7fffffff */);
  fVar7 = (float)((uint)*param_3 & _DAT_14382e160 /* None, 0x7fffffff */);
  if (fVar7 <= fVar4) {
    fVar7 = fVar4;
  }
  fVar6 = *param_3 * (_DAT_14382dce0 /* 1.0, 0x3f800000 */ / fVar7);
  fVar4 = param_3[2] * (_DAT_14382dce0 /* 1.0, 0x3f800000 */ / fVar7);
  if (fVar7 <= 0.0) {
    fVar7 = 0.0;
  }
  else {
    fVar7 = SQRT(fVar4 * fVar4 + fVar6 * fVar6) * fVar7;
  }
  fVar4 = *(float *)(param_1 + 0x430);
  fVar6 = *(float *)(param_1 + 0x51c);
  if (fVar4 < 0.0) {
    lVar1 = *(longlong *)(param_1 + 0x380);
    fVar6 = fVar6 - (float)((uint)fVar4 & _DAT_14382e160 /* None, 0x7fffffff */) * *(float *)(lVar1 + 0x34) * param_6;
    if (fVar6 <= *(float *)(lVar1 + 0x2c)) {
      fVar6 = *(float *)(lVar1 + 0x2c);
    }
    *(float *)(param_1 + 0x51c) = fVar6;
    fVar4 = fVar6 * *(float *)(lVar1 + 0x24);
    if (fVar4 <= *(float *)(lVar1 + 0x28)) {
      fVar4 = *(float *)(lVar1 + 0x28);
    }
    *(float *)(param_1 + 0x524) = fVar6;
    *(float *)(param_1 + 0x520) = fVar4;
  }
  else {
    fVar5 = (fVar6 - *(float *)(param_1 + 0x520)) * fVar4 + *(float *)(param_1 + 0x520);
    fVar4 = fVar5;
    if (((fVar5 <= fVar7) && (fVar4 = fVar6, fVar7 < fVar6)) &&
       (fVar4 = fVar7 - param_6 * *(float *)(*(longlong *)(param_1 + 0x380) + 0x30), fVar4 <= fVar5)
       ) {
      fVar4 = fVar5;
    }
  }
  fVar6 = (float)FUN_140876340(param_4);
  fVar7 = *(float *)(param_1 + 0x430);
  if (fVar7 <= 0.0) {
    fVar7 = 0.0;
  }
  fVar7 = (*(float *)(param_1 + 0x524) - *(float *)(param_1 + 0x51c)) * fVar7 +
          *(float *)(param_1 + 0x51c);
  if (*(int *)(param_1 + 0x574) == 0) {
    if (fVar6 <= _DAT_1438cea44 /* 1.49225652217865, 0x3fbf0243 */) {
      fVar5 = (float)FUN_14366a0e0();
      if (fVar5 <= _DAT_143830ee8 /* 0.0010000000474974513, 0x3a83126f */) {
        fVar5 = _DAT_143830ee8 /* 0.0010000000474974513, 0x3a83126f */;
      }
      fVar6 = fVar4 / fVar5;
      if (fVar7 <= fVar4 / fVar5) {
        fVar6 = fVar7;
      }
      goto LAB_140abf73d;
    }
  }
  else {
    fVar6 = fVar4;
    if (*(int *)(param_1 + 0x574) != 1) goto LAB_140abf73d;
  }
  fVar6 = fVar7;
LAB_140abf73d:
  lVar1 = *(longlong *)(param_1 + 0x380);
  param_5 = param_5 * _DAT_1438627c4 /* 0.0714285746216774, 0x3d924925 */;
  *(undefined8 *)param_2 = *(undefined8 *)param_3;
  if (param_5 <= 0.0) {
    param_5 = 0.0;
  }
  if (fVar8 <= param_5) {
    param_5 = fVar8;
  }
  fVar7 = *(float *)(lVar1 + 0x20);
  fVar5 = param_5 * fVar6;
  if (fVar7 <= param_5 * fVar6) {
    fVar5 = fVar7;
  }
  param_2[2] = param_3[2];
  fVar7 = param_2[2];
  fVar6 = *param_2;
  if (fVar5 < fVar3) {
    fVar5 = fVar5 / fVar3;
    fVar6 = fVar6 * fVar5;
    fVar7 = fVar7 * fVar5;
    param_2[1] = fVar5 * param_2[1];
    *param_2 = fVar6;
    param_2[2] = fVar7;
  }
  fVar5 = (float)((uint)fVar7 & uVar2);
  fVar3 = (float)((uint)fVar6 & uVar2);
  if (fVar3 <= fVar5) {
    fVar3 = fVar5;
  }
  fVar5 = fVar6 * (fVar8 / fVar3);
  fVar8 = (fVar8 / fVar3) * fVar7;
  if (0.0 < fVar3) {
    fVar9 = SQRT(fVar8 * fVar8 + fVar5 * fVar5) * fVar3;
  }
  if (fVar4 < fVar9) {
    fVar4 = fVar4 / fVar9;
    param_2[1] = fVar4 * param_2[1];
    *param_2 = fVar6 * fVar4;
    param_2[2] = fVar7 * fVar4;
  }
  return param_2;
}


