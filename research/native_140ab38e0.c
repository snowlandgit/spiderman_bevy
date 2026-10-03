/* SwingRegion_140ab38e0 @ 0x140ab38e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_140ab38e0(longlong param_1,float *param_2,float *param_3,float *param_4)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  uVar1 = _DAT_14382e160 /* None */;
  fVar4 = _DAT_14382dce0 /* 1.0 */;
  fVar3 = *param_2 - *param_3;
  fVar7 = 0.0;
  fVar8 = 0.0;
  fVar9 = param_2[2] - param_3[2];
  fVar10 = (float)((uint)fVar3 & _DAT_14382e160 /* None */);
  fVar11 = param_2[1] - param_3[1];
  fVar5 = (float)((uint)fVar9 & _DAT_14382e160 /* None */);
  fVar2 = (float)((uint)fVar11 & _DAT_14382e160 /* None */);
  if ((float)((uint)fVar11 & _DAT_14382e160 /* None */) <= fVar5) {
    fVar2 = fVar5;
  }
  if (fVar2 <= fVar10) {
    fVar2 = fVar10;
  }
  fVar6 = _DAT_14382dce0 /* 1.0 */ / fVar2;
  if (0.0 < fVar2) {
    fVar8 = SQRT(fVar6 * fVar11 * fVar6 * fVar11 + fVar6 * fVar3 * fVar6 * fVar3 +
                 fVar6 * fVar9 * fVar6 * fVar9) * fVar2;
  }
  if (fVar5 <= fVar10) {
    fVar5 = fVar10;
  }
  fVar3 = fVar3 * (_DAT_14382dce0 /* 1.0 */ / fVar5);
  fVar9 = (_DAT_14382dce0 /* 1.0 */ / fVar5) * fVar9;
  if (fVar5 <= 0.0) {
    fVar5 = 0.0;
  }
  else {
    fVar5 = SQRT(fVar3 * fVar3 + fVar9 * fVar9) * fVar5;
  }
  fVar2 = (float)FUN_141c58560(fVar11,fVar5);
  fVar5 = param_4[1];
  fVar9 = fVar2 * _DAT_1438ac3cc /* 2.2918310165405273 */ - _DAT_1438ac3a4 /* 0.3999999761581421 */;
  fVar2 = *(float *)(param_1 + 0xc);
  if (0.0 <= fVar5) {
    fVar5 = 0.0;
  }
  fVar3 = (fVar8 - _DAT_143879c24 /* 22.0 */) * _DAT_1438abcb8 /* 0.04545454680919647 */;
  if (fVar9 <= 0.0) {
    fVar9 = 0.0;
  }
  fVar5 = (float)((uint)fVar5 & uVar1);
  if (fVar4 <= fVar9) {
    fVar9 = fVar4;
  }
  if (fVar3 <= 0.0) {
    fVar3 = 0.0;
  }
  if (fVar4 <= fVar3) {
    fVar3 = fVar4;
  }
  fVar9 = ((fVar4 - fVar9) + fVar3) * _DAT_14382f760 /* 0.75 */;
  if (fVar2 <= fVar5) {
    fVar3 = fVar5;
    if (fVar9 < fVar4) goto LAB_140ab3a94;
  }
  else if (fVar9 < fVar4) {
    fVar3 = fVar5 + (fVar2 - fVar5) * fVar9;
    goto LAB_140ab3a94;
  }
  fVar3 = (((*(float *)(param_1 + 0x10) - fVar2) * _DAT_14382e128 /* 0.5 */ + fVar2) - fVar2) *
          (fVar9 - fVar4) + fVar2;
  if (fVar3 <= fVar5) {
    fVar3 = fVar5;
  }
LAB_140ab3a94:
  if (fVar2 <= fVar3) {
    fVar5 = *(float *)(param_1 + 0x10) - fVar2;
    if ((float)((uint)fVar5 & uVar1) <= _DAT_14382e118 /* 9.999999747378752e-05 */) {
      fVar5 = _DAT_14382e128 /* 0.5 */;
      if (fVar2 < fVar3) {
        fVar5 = fVar4;
      }
    }
    else {
      fVar5 = (fVar3 - fVar2) / fVar5;
      if (fVar5 <= 0.0) {
        fVar5 = 0.0;
      }
      if (fVar4 <= fVar5) {
        fVar5 = fVar4;
      }
    }
    fVar5 = (*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x18)) * fVar5 +
            *(float *)(param_1 + 0x18);
  }
  else {
    fVar5 = *(float *)(param_1 + 8);
    if ((float)((uint)(fVar2 - fVar5) & uVar1) <= _DAT_14382e118 /* 9.999999747378752e-05 */) {
      if (fVar5 <= fVar3) {
        fVar2 = _DAT_14382e128 /* 0.5 */;
        if (fVar5 < fVar3) {
          fVar2 = fVar4;
        }
      }
      else {
        fVar2 = 0.0;
      }
    }
    else {
      fVar2 = (fVar3 - fVar5) / (fVar2 - fVar5);
      if (fVar2 <= 0.0) {
        fVar2 = 0.0;
      }
      if (fVar4 <= fVar2) {
        fVar2 = fVar4;
      }
    }
    fVar5 = (*(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x14)) * fVar2 +
            *(float *)(param_1 + 0x14);
  }
  fVar9 = (float)((uint)param_4[2] & uVar1);
  fVar2 = (float)((uint)*param_4 & uVar1);
  if (fVar2 <= fVar9) {
    fVar2 = fVar9;
  }
  fVar9 = *param_4 * (fVar4 / fVar2);
  fVar4 = param_4[2] * (fVar4 / fVar2);
  if (0.0 < fVar2) {
    fVar7 = SQRT(fVar4 * fVar4 + fVar9 * fVar9) * fVar2;
  }
  if (fVar7 <= fVar5) {
    fVar7 = fVar5;
  }
  return fVar7;
}


