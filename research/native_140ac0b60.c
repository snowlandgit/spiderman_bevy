/* SwingRegion_140ac0b60 @ 0x140ac0b60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_140ac0b60(longlong param_1,longlong param_2,float param_3,float param_4,float param_5)

{
  int iVar1;
  longlong lVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  fVar5 = (float)FUN_1402c2450(param_2);
  fVar6 = (float)FUN_140876340(param_2);
  uVar4 = _DAT_14382e160 /* None, 0x7fffffff */;
  fVar11 = _DAT_14382e128 /* 0.5, 0x3f000000 */;
  fVar3 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
  lVar2 = *(longlong *)(param_1 + 0x388);
  fVar6 = fVar6 * _DAT_143855568 /* -57.2957763671875, 0xc2652ee0 */;
  fVar10 = *(float *)(lVar2 + 0x1c);
  fVar7 = *(float *)(lVar2 + 0x20) - fVar10;
  if ((float)((uint)fVar7 & _DAT_14382e160 /* None, 0x7fffffff */) <= _DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */) {
    if (fVar10 <= fVar6) {
      fVar7 = _DAT_14382e128 /* 0.5, 0x3f000000 */;
      if (fVar10 < fVar6) {
        fVar7 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
      }
    }
    else {
      fVar7 = 0.0;
    }
  }
  else {
    fVar7 = (fVar6 - fVar10) / fVar7;
    if (fVar7 <= 0.0) {
      fVar7 = 0.0;
    }
    if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar7) {
      fVar7 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
    }
  }
  fVar10 = *(float *)(lVar2 + 0x24);
  fVar6 = *(float *)(lVar2 + 0x28) - fVar10;
  if ((float)((uint)fVar6 & _DAT_14382e160 /* None, 0x7fffffff */) <= _DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */) {
    if (fVar10 <= param_4) {
      fVar6 = _DAT_14382e128 /* 0.5, 0x3f000000 */;
      if (fVar10 < param_4) {
        fVar6 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
      }
    }
    else {
      fVar6 = 0.0;
    }
  }
  else {
    fVar6 = (param_4 - fVar10) / fVar6;
    if (fVar6 <= 0.0) {
      fVar6 = 0.0;
    }
    if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar6) {
      fVar6 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
    }
  }
  fVar10 = *(float *)(lVar2 + 0x2c);
  fVar8 = *(float *)(lVar2 + 0x30) - fVar10;
  if ((float)((uint)fVar8 & _DAT_14382e160 /* None, 0x7fffffff */) <= _DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */) {
    if (fVar10 <= fVar5) {
      fVar8 = _DAT_14382e128 /* 0.5, 0x3f000000 */;
      if (fVar10 < fVar5) {
        fVar8 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
      }
    }
    else {
      fVar8 = 0.0;
    }
  }
  else {
    fVar8 = (fVar5 - fVar10) / fVar8;
    if (fVar8 <= 0.0) {
      fVar8 = 0.0;
    }
    if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar8) {
      fVar8 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
    }
  }
  fVar10 = *(float *)(lVar2 + 0x34);
  fVar9 = *(float *)(lVar2 + 0x38) - fVar10;
  if ((float)((uint)fVar9 & _DAT_14382e160 /* None, 0x7fffffff */) <= _DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */) {
    if (fVar10 <= fVar5) {
      fVar9 = _DAT_14382e128 /* 0.5, 0x3f000000 */;
      if (fVar10 < fVar5) {
        fVar9 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
      }
    }
    else {
      fVar9 = 0.0;
    }
  }
  else {
    fVar9 = (fVar5 - fVar10) / fVar9;
    if (fVar9 <= 0.0) {
      fVar9 = 0.0;
    }
    if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar9) {
      fVar9 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
    }
  }
  fVar10 = *(float *)(param_1 + 0x430);
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  fVar5 = (*(float *)(lVar2 + 0x50) - *(float *)(lVar2 + 0x4c)) * fVar8 + *(float *)(lVar2 + 0x4c);
  fVar5 = (((*(float *)(lVar2 + 0x40) - *(float *)(lVar2 + 0x3c)) * fVar8 + *(float *)(lVar2 + 0x3c)
           ) - fVar5) * fVar10 + fVar5;
  fVar8 = (*(float *)(lVar2 + 0x58) - *(float *)(lVar2 + 0x54)) * fVar9 + *(float *)(lVar2 + 0x54);
  fVar5 = fVar5 + (*(float *)(lVar2 + 0x5c) - fVar5) * fVar6;
  fVar8 = (((*(float *)(lVar2 + 0x48) - *(float *)(lVar2 + 0x44)) * fVar9 + *(float *)(lVar2 + 0x44)
           ) - fVar8) * fVar10 + fVar8;
  fVar5 = (((*(float *)(lVar2 + 0x60) - fVar8) * fVar6 + fVar8) - fVar5) * fVar7 + fVar5;
  if (0.0 < *(float *)(param_2 + 4) || *(float *)(param_2 + 4) == 0.0) {
    if (_DAT_1438388d0 /* 16.0, 0x41800000 */ <= param_5) {
      fVar10 = *(float *)(lVar2 + 0x68);
      fVar6 = *(float *)(lVar2 + 0x6c) - fVar10;
      if ((float)((uint)fVar6 & _DAT_14382e160 /* None, 0x7fffffff */) <= _DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */) {
        if (fVar10 <= param_5) {
          fVar6 = _DAT_14382e128 /* 0.5, 0x3f000000 */;
          if (fVar10 < param_5) {
            fVar6 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
          }
        }
        else {
          fVar6 = 0.0;
        }
      }
      else {
        fVar6 = (param_5 - fVar10) / fVar6;
        if (fVar6 <= 0.0) {
          fVar6 = 0.0;
        }
        if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar6) {
          fVar6 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
        }
      }
      fVar5 = fVar5 * ((*(float *)(lVar2 + 100) - _DAT_14382dce0 /* 1.0, 0x3f800000 */) * fVar6 + _DAT_14382dce0 /* 1.0, 0x3f800000 */);
    }
    else {
      fVar10 = (param_5 - _DAT_143830120 /* 8.0, 0x41000000 */) * _DAT_1438398cc /* 0.125, 0x3e000000 */;
      if (fVar10 <= 0.0) {
        fVar10 = 0.0;
      }
      if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar10) {
        fVar10 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
      }
      fVar5 = fVar5 - (fVar5 + _DAT_1438794d0 /* 35.0, 0x420c0000 */) * fVar10;
    }
  }
  else if (*(int *)(param_1 + 0x574) == 2) {
    fVar5 = *(float *)(param_1 + 0x4b4);
  }
  else {
    fVar10 = (param_3 - _DAT_1438ad6d4 /* 145.0, 0x43110000 */) * _DAT_1438ac378 /* 0.02857142873108387, 0x3cea0ea1 */;
    if (fVar10 <= 0.0) {
      fVar10 = 0.0;
    }
    if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar10) {
      fVar10 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
    }
    fVar5 = (float)FUN_1420dc660(param_1);
    fVar5 = (fVar5 - _DAT_14382e124 /* 0.25, 0x3e800000 */) * _DAT_143834a14 /* 4.0, 0x40800000 */;
    if (fVar5 <= 0.0) {
      fVar5 = 0.0;
    }
    if (fVar3 <= fVar5) {
      fVar5 = fVar3;
    }
    fVar5 = (*(float *)(param_1 + 0x4b0) - *(float *)(param_1 + 0x4ac)) * fVar5 +
            *(float *)(param_1 + 0x4ac);
    fVar5 = fVar5 - (fVar5 + _DAT_1438312b0 /* 50.0, 0x42480000 */) * fVar10;
  }
  iVar1 = *(int *)(param_1 + 0x574);
  fVar10 = fVar5;
  if (_DAT_14383f72c /* -10.0, 0xc1200000 */ <= fVar5) {
    fVar10 = _DAT_14383f72c /* -10.0, 0xc1200000 */;
  }
  fVar10 = (fVar5 - fVar10) * *(float *)(param_1 + 0x510) + fVar10;
  if (iVar1 != 0) {
    fVar5 = fVar10;
    if (((0.0 < *(float *)(param_2 + 4)) && (*(float *)(param_1 + 0x430) < 0.0)) &&
       (fVar8 = (float)((uint)*(float *)(param_1 + 0x430) & uVar4), fVar5 = fVar8 * _DAT_1438388cc /* 15.0, 0x41700000 */,
       fVar6 = _DAT_14386d9b0 /* -25.0, 0xc1c80000 */ - fVar5,
       fVar5 = ((((_DAT_1438acf84 /* -35.0, 0xc20c0000 */ - fVar5) - fVar6) * fVar7 + fVar6) - fVar10) * fVar8 + fVar10,
       fVar10 <= fVar5)) {
      fVar5 = fVar10;
    }
    fVar10 = fVar5;
    if (iVar1 == 1) {
      if (*(char *)(param_1 + 0x5f9) == '\0') {
        fVar11 = fVar3;
      }
      fVar10 = fVar10 * *(float *)(param_1 + 0x468) * fVar11;
    }
    else if ((iVar1 == 2) && (fVar10 = _DAT_1438862e0 /* -14.0, 0xc1600000 */, 0.0 < *(float *)(param_2 + 4))) {
      fVar10 = _DAT_1438cea70 /* -22.0, 0xc1b00000 */;
    }
  }
  return fVar10;
}


