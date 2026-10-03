/* SwingRegion_140ab4450 @ 0x140ab4450 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab4450(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                  float *param_6,char param_7)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float afStack_108 [4];
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  undefined8 uStack_e8;
  undefined4 uStack_e0;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  
  uVar1 = _DAT_14382e160 /* None */;
  fVar5 = _DAT_14382dce0 /* 1.0 */;
  fVar6 = param_1[2] - param_2[2];
  fVar8 = *param_1 - *param_2;
  fVar9 = param_1[1] - param_2[1];
  fVar3 = (float)((uint)fVar6 & _DAT_14382e160 /* None */);
  if ((float)((uint)fVar6 & _DAT_14382e160 /* None */) <= (float)((uint)fVar9 & _DAT_14382e160 /* None */)) {
    fVar3 = (float)((uint)fVar9 & _DAT_14382e160 /* None */);
  }
  if (fVar3 <= (float)((uint)fVar8 & _DAT_14382e160 /* None */)) {
    fVar3 = (float)((uint)fVar8 & _DAT_14382e160 /* None */);
  }
  if (0.0 < fVar3) {
    fVar3 = _DAT_14382dce0 /* 1.0 */ / fVar3;
    fVar6 = fVar3 * fVar6;
    fVar8 = fVar3 * fVar8;
    fVar3 = fVar3 * fVar9;
    fVar7 = _DAT_14382dce0 /* 1.0 */ / SQRT(fVar3 * fVar3 + fVar8 * fVar8 + fVar6 * fVar6);
    fVar8 = fVar7 * fVar8;
    fVar9 = fVar7 * fVar3;
    fVar6 = fVar7 * fVar6;
  }
  fVar3 = *param_3 * fVar8 + param_3[1] * fVar9 + param_3[2] * fVar6;
  fVar4 = *param_3 - fVar8 * fVar3;
  fVar7 = param_3[1] - fVar9 * fVar3;
  fVar3 = param_3[2] - fVar6 * fVar3;
  fStack_118 = fVar7 * fVar6 - fVar3 * fVar9;
  fStack_114 = fVar3 * fVar8 - fVar4 * fVar6;
  fStack_110 = fVar4 * fVar9 - fVar7 * fVar8;
  fVar3 = (float)((uint)fStack_110 & _DAT_14382e160 /* None */);
  if ((float)((uint)fStack_110 & _DAT_14382e160 /* None */) <= (float)((uint)fStack_114 & _DAT_14382e160 /* None */)) {
    fVar3 = (float)((uint)fStack_114 & _DAT_14382e160 /* None */);
  }
  if (fVar3 <= (float)((uint)fStack_118 & _DAT_14382e160 /* None */)) {
    fVar3 = (float)((uint)fStack_118 & _DAT_14382e160 /* None */);
  }
  if (0.0 < fVar3) {
    fVar3 = _DAT_14382dce0 /* 1.0 */ / fVar3;
    fStack_110 = fStack_110 * fVar3;
    fStack_114 = fStack_114 * fVar3;
    fStack_118 = fStack_118 * fVar3;
    fVar3 = _DAT_14382dce0 /* 1.0 */ /
            SQRT(fStack_114 * fStack_114 + fStack_118 * fStack_118 + fStack_110 * fStack_110);
    fStack_118 = fVar3 * fStack_118;
    fStack_114 = fVar3 * fStack_114;
    fStack_110 = fVar3 * fStack_110;
  }
  *(ulonglong *)param_4 = CONCAT44(fStack_114,fStack_118);
  param_4[2] = fStack_110;
  fVar3 = (float)FUN_140876340(param_4);
  uVar2 = _DAT_14382e890 /* -0.0 */;
  fVar3 = fVar3 * _DAT_143830124 /* 57.2957763671875 */;
  if (param_7 == '\0') {
    fVar3 = (float)((uint)fVar3 & uVar1);
  }
  afStack_108[1] = 0.0;
  *param_5 = fVar3;
  fVar3 = param_4[2];
  afStack_108[2] = (float)((uint)*param_4 ^ uVar2);
  fVar7 = (float)((uint)afStack_108[2] & uVar1);
  if (fVar7 <= 0.0) {
    fVar7 = 0.0;
  }
  if (fVar7 <= (float)((uint)fVar3 & uVar1)) {
    fVar7 = (float)((uint)fVar3 & uVar1);
  }
  afStack_108[0] = fVar3;
  if (0.0 < fVar7) {
    afStack_108[2] = afStack_108[2] * (fVar5 / fVar7);
    fVar7 = (fVar5 / fVar7) * fVar3;
    fVar4 = fVar5 / SQRT(afStack_108[2] * afStack_108[2] + fVar7 * fVar7);
    afStack_108[2] = fVar4 * afStack_108[2];
    afStack_108[0] = fVar4 * fVar7;
  }
  fStack_118 = afStack_108[2] * param_4[1];
  fStack_110 = (float)((uint)(afStack_108[0] * param_4[1]) ^ uVar2);
  fStack_114 = afStack_108[0] * fVar3 - afStack_108[2] * *param_4;
  fVar3 = (float)((uint)fStack_114 & uVar1);
  if ((float)((uint)fStack_114 & uVar1) <= (float)((uint)fStack_110 & uVar1)) {
    fVar3 = (float)((uint)fStack_110 & uVar1);
  }
  if (fVar3 <= (float)((uint)fStack_118 & uVar1)) {
    fVar3 = (float)((uint)fStack_118 & uVar1);
  }
  if (0.0 < fVar3) {
    fVar3 = fVar5 / fVar3;
    fStack_114 = fStack_114 * fVar3;
    fStack_110 = fVar3 * fStack_110;
    fVar3 = fVar3 * fStack_118;
    fVar7 = fVar5 / SQRT(fStack_114 * fStack_114 + fVar3 * fVar3 + fStack_110 * fStack_110);
    fStack_118 = fVar7 * fVar3;
    fStack_114 = fVar7 * fStack_114;
    fStack_110 = fVar7 * fStack_110;
  }
  FUN_141c511e0(&fStack_d8,afStack_108,&fStack_118);
  fVar3 = fStack_d4 * (float)((uint)fVar9 ^ uVar2) + fStack_d8 * (float)((uint)fVar8 ^ uVar2) +
          fStack_d0 * (float)((uint)fVar6 ^ uVar2);
  fVar8 = (float)((uint)fVar8 ^ uVar2) - fStack_d8 * fVar3;
  fVar9 = (float)((uint)fVar9 ^ uVar2) - fStack_d4 * fVar3;
  fVar6 = (float)((uint)fVar6 ^ uVar2) - fStack_d0 * fVar3;
  fVar3 = (float)((uint)fVar6 & uVar1);
  if ((float)((uint)fVar6 & uVar1) <= (float)((uint)fVar9 & uVar1)) {
    fVar3 = (float)((uint)fVar9 & uVar1);
  }
  if (fVar3 <= (float)((uint)fVar8 & uVar1)) {
    fVar3 = (float)((uint)fVar8 & uVar1);
  }
  if (0.0 < fVar3) {
    fVar3 = fVar5 / fVar3;
    fVar8 = fVar3 * fVar8;
    fVar9 = fVar3 * fVar9;
    fVar3 = fVar3 * fVar6;
    fVar5 = fVar5 / SQRT(fVar9 * fVar9 + fVar8 * fVar8 + fVar3 * fVar3);
    fVar8 = fVar5 * fVar8;
    fVar9 = fVar5 * fVar9;
    fVar6 = fVar5 * fVar3;
  }
  uStack_e8 = 0;
  uStack_e0 = 0x3f800000;
  fStack_f4 = fStack_cc * fVar8 + fStack_c8 * fVar9 + fStack_c4 * fVar6;
  fStack_f0 = fStack_c0 * fVar8 + fStack_bc * fVar9 + fStack_b8 * fVar6;
  fStack_f8 = fVar8 * fStack_d8 + fStack_d4 * fVar9 + fStack_d0 * fVar6;
  fVar5 = (float)func_0x000141c59090(&fStack_f8,&uStack_e8);
  fVar5 = fVar5 * _DAT_143830124 /* 57.2957763671875 */;
  *param_6 = fVar5;
  if (0.0 < fStack_f4) {
    if (fStack_f0 <= 0.0) {
      *param_6 = _DAT_14386dd08 /* 360.0 */ - fVar5;
    }
    else {
      *param_6 = (float)((uint)fVar5 ^ uVar2);
    }
  }
  return;
}


