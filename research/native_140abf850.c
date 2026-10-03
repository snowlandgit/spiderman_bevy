/* SwingRegion_140abf850 @ 0x140abf850 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_140abf850(longlong param_1,float *param_2,float *param_3,float *param_4,
                     undefined8 *param_5,undefined8 param_6,float param_7,float param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fStack_c8;
  
  fVar1 = (float)FUN_140311350(param_5,param_6);
  fVar13 = _DAT_143834a14 /* 4.0, 0x40800000 */;
  fVar3 = _DAT_143830ee8 /* 0.0010000000474974513, 0x3a83126f */;
  fVar5 = _DAT_14382f0dc /* 2.0, 0x40000000 */;
  fVar4 = _DAT_14382e128 /* 0.5, 0x3f000000 */;
  fVar15 = (*(float *)(param_1 + 0x43c) - *(float *)(param_1 + 0x4a4)) - _DAT_14382f0dc /* 2.0, 0x40000000 */;
  fVar12 = *(float *)(param_1 + 0x494);
  if (*(float *)(param_1 + 0x494) == _DAT_143830778 /* -1.0000000150474662e+30, 0xf149f2ca */) {
    fVar12 = fVar15;
  }
  *(float *)(param_1 + 0x494) = fVar12;
  if (*(char *)(param_1 + 0x48c) != '\0') {
    fVar2 = (float)FUN_140311350(param_1 + 0x480,param_6);
    fVar11 = fVar2 - _DAT_143834a0c /* 1.5, 0x3fc00000 */;
    if (fVar1 <= fVar2 - _DAT_143834a0c /* 1.5, 0x3fc00000 */) {
      fVar11 = fVar1;
    }
    if ((fVar11 < fVar1 - fVar3) &&
       (*(float *)(param_1 + 0x484) < *(float *)(param_1 + 0x448) - fVar13)) {
      fVar15 = *(float *)(param_1 + 0x484) + fVar5;
      fVar3 = (float)func_0x0001403e3f30(param_3);
      fVar4 = (float)func_0x0001404c4e20(param_1 + 0x480,param_4);
      fVar4 = fVar4 / ((*(float *)(param_1 + 0x51c) - fVar3) * _DAT_14382f760 /* 0.75, 0x3f400000 */ + fVar3);
    }
  }
  fVar11 = _DAT_14384002c /* 30.0, 0x41f00000 */;
  fVar3 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
  if (fVar15 <= fVar12) {
    if (fVar15 < fVar12 - fVar5) {
      fVar12 = ((fVar12 - fVar15) - fVar13) * _DAT_1438564c4 /* 0.0833333358168602, 0x3daaaaab */;
      if (fVar12 <= 0.0) {
        fVar12 = 0.0;
      }
      if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar12) {
        fVar12 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
      }
      uVar8 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x498),fVar12 * _DAT_143830120 /* 8.0, 0x41000000 */ + fVar5,
                                  fVar12 * _DAT_14384002c /* 30.0, 0x41f00000 */ + _DAT_14382f0e4 /* 10.0, 0x41200000 */,param_8);
      *(int *)(param_1 + 0x498) = (int)uVar8;
      fVar12 = (float)func_0x000141c477e0(*(undefined4 *)(param_1 + 0x494),fVar15,uVar8,param_8);
      *(float *)(param_1 + 0x494) = fVar12;
    }
  }
  else {
    *(float *)(param_1 + 0x494) = fVar15;
    *(undefined4 *)(param_1 + 0x498) = 0;
    fVar12 = fVar15;
  }
  uVar8 = *param_5;
  fVar2 = *(float *)(param_5 + 1);
  fVar17 = (float)((ulonglong)uVar8 >> 0x20);
  fVar5 = *(float *)((longlong)param_5 + 4);
  fVar15 = param_4[1];
  *(undefined8 *)param_2 = uVar8;
  fVar16 = _DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */;
  fVar9 = fVar15;
  if (fVar15 <= fVar5) {
    fVar9 = fVar5;
  }
  param_2[2] = fVar2;
  uVar14 = _DAT_14382e160 /* None, 0x7fffffff */;
  fVar10 = _DAT_14382e120 /* 0.10000000149011612, 0x3dcccccd */;
  if (fVar9 < fVar12) {
    fVar1 = (fVar4 - _DAT_143837a20 /* 0.20000000298023224, 0x3e4ccccd */) * _DAT_14382f0e0 /* 5.0, 0x40a00000 */;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    if (fVar3 <= fVar1) {
      fVar1 = fVar3;
    }
    if (fVar4 <= _DAT_143830118 /* 0.009999999776482582, 0x3c23d70a */) {
      fVar4 = 0.0;
    }
    else {
      fVar4 = (fVar12 - fVar5) / fVar4;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
    }
    fVar12 = ((fVar12 - fVar5) - fVar3) * _DAT_143836d0c /* 0.800000011920929, 0x3f4ccccd */;
    if (fVar12 <= 0.0) {
      fVar12 = 0.0;
    }
    if (fVar3 <= fVar12) {
      fVar12 = fVar3;
    }
    fVar13 = fVar12 * (fVar3 - fVar1) * fVar13 + fVar3;
    if (fVar13 <= fVar4) {
      fVar13 = fVar4;
    }
    if (_DAT_14382f0e0 /* 5.0, 0x40a00000 */ <= fVar13) {
      fVar13 = _DAT_14382f0e0 /* 5.0, 0x40a00000 */;
    }
    fVar4 = (float)func_0x000141c477e0(*(undefined4 *)(param_1 + 0x4a0),fVar13,_DAT_1438ac3f4 /* 32.0, 0x42000000 */,
                                       param_8);
    uVar14 = _DAT_14382e160 /* None, 0x7fffffff */;
    fVar13 = *(float *)(param_1 + 0x494) - fVar5;
    *(float *)(param_1 + 0x4a0) = fVar4;
    fVar4 = fVar4 * param_8 + fVar5;
    if ((fVar4 - param_2[1] < fVar13) && (param_8 * param_3[1] < 0.0)) {
      fVar13 = fVar13 - (fVar4 - param_2[1]);
      fVar12 = (float)((uint)(param_8 * param_3[1]) & uVar14);
      if (fVar13 <= fVar12) {
        fVar12 = fVar13;
      }
      fVar4 = fVar4 + fVar12;
    }
    fVar4 = (fVar4 - fVar5) / param_8;
    if (fVar4 <= *(float *)(param_1 + 0x49c)) {
      fVar4 = (float)func_0x000141c477e0(*(float *)(param_1 + 0x49c),fVar4,fVar11,param_8);
    }
    *(float *)(param_1 + 0x49c) = fVar4;
    param_2[1] = fVar4 * param_8 + param_2[1];
    goto LAB_140abfe2c;
  }
  if (0.0 <= fVar5 - fVar15) {
LAB_140abfd63:
    if (fVar16 < (float)((uint)*(float *)(param_1 + 0x49c) & uVar14)) {
      fVar10 = (*(float *)(param_1 + 0x49c) - _DAT_14382f0e0 /* 5.0, 0x40a00000 */) * fVar10;
      if (fVar10 <= 0.0) {
        fVar10 = 0.0;
      }
      if (fVar3 <= fVar10) {
        fVar10 = fVar3;
      }
      fVar4 = (float)FUN_140876340(param_3);
      fVar4 = fVar4 * _DAT_1438cea6c /* -2.2918310165405273, 0xc012ad5c */ - _DAT_1438b4f48 /* 0.7999999523162842, 0x3f4ccccc */;
      fVar5 = fVar10 * _DAT_1438cea60 /* 23.0, 0x41b80000 */ + _DAT_14383f374 /* 7.0, 0x40e00000 */;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
      if (fVar3 <= fVar4) {
        fVar4 = fVar3;
      }
      uVar6 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x49c),0,
                                  (_DAT_14384002c /* 30.0, 0x41f00000 */ - fVar5) * fVar4 + fVar5,param_8);
      *(uint *)(param_1 + 0x49c) = uVar6;
      param_2[1] = (float)(uVar6 & uVar14) * param_8 + param_2[1];
    }
  }
  else {
    fVar13 = (float)func_0x000141c58730(param_7 * _DAT_14382e11c /* 0.01745329238474369, 0x3c8efa35 */);
    fVar12 = (float)((uint)(fVar5 - fVar15) & uVar14);
    fVar4 = *(float *)(param_1 + 0x494);
    fVar5 = ((fVar4 - fVar17) / param_3[1] - fVar10) * _DAT_1438388c4 /* 2.5, 0x40200000 */;
    if (fVar5 <= 0.0) {
      fVar5 = 0.0;
    }
    if (fVar3 <= fVar5) {
      fVar5 = fVar3;
    }
    fVar16 = _DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */;
    if (fVar4 <= *(float *)(param_1 + 0x448) - fVar13 * fVar1) goto LAB_140abfd63;
    fVar13 = (float)FUN_143667c70(((fVar3 - fVar5) * _DAT_14382ee94 /* 3.0, 0x40400000 */ - _DAT_143830120 /* 8.0, 0x41000000 */) * param_8);
    fVar4 = (fVar3 - fVar13) * (param_4[1] - fVar4);
    fVar5 = (float)FUN_143667c70((_DAT_14386d9b0 /* -25.0, 0xc1c80000 */ - (fVar3 - fVar5) * _DAT_1438794d0 /* 35.0, 0x420c0000 */) * param_8);
    fVar5 = fVar5 * fVar12;
    if (fVar5 <= fVar4) {
      fVar4 = fVar5;
    }
    fVar12 = fVar12 - fVar4;
    fVar5 = fVar12 / param_8;
    param_2[1] = fVar12 + param_2[1];
    *(float *)(param_1 + 0x49c) = fVar5;
    fVar4 = param_3[1];
    if (fVar4 < 0.0) {
      fVar13 = (float)((uint)fVar4 & uVar14) * _DAT_143848d00 /* 0.33000001311302185, 0x3ea8f5c3 */;
      fVar5 = fVar5 * _DAT_143854044 /* 0.6600000262260437, 0x3f28f5c3 */ * param_8;
      if (fVar5 <= fVar13) {
        fVar13 = fVar5;
      }
      param_3[1] = fVar13 + fVar4;
    }
  }
  uVar7 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x4a0),0,_DAT_1438ac3f4 /* 32.0, 0x42000000 */,param_8);
  *(undefined4 *)(param_1 + 0x4a0) = uVar7;
LAB_140abfe2c:
  fStack_c8 = (float)uVar8;
  fVar4 = param_4[2];
  fVar17 = fVar17 - param_4[1];
  fVar5 = *param_4;
  fVar2 = fVar2 - fVar4;
  fVar12 = (float)((uint)fVar17 & uVar14);
  fVar13 = (float)((uint)fVar2 & uVar14);
  if (fVar13 <= fVar12) {
    fVar13 = fVar12;
  }
  fVar12 = (float)((uint)(fStack_c8 - fVar5) & uVar14);
  if (fVar13 <= fVar12) {
    fVar13 = fVar12;
  }
  fVar15 = fVar3 / fVar13;
  fVar12 = fVar15 * (fStack_c8 - fVar5);
  fVar1 = 0.0;
  fVar17 = fVar15 * fVar17;
  fVar15 = fVar15 * fVar2;
  if (0.0 < fVar13) {
    fVar1 = SQRT(fVar17 * fVar17 + fVar12 * fVar12 + fVar15 * fVar15) * fVar13;
  }
  fVar2 = *param_2 - fVar5;
  fVar15 = param_2[1] - param_4[1];
  fVar11 = param_2[2] - fVar4;
  fVar16 = (float)((uint)fVar2 & uVar14);
  fVar12 = (float)((uint)fVar15 & uVar14);
  fVar13 = (float)((uint)fVar11 & uVar14);
  if (fVar12 <= fVar13) {
    fVar12 = fVar13;
  }
  if (fVar12 <= fVar16) {
    fVar12 = fVar16;
  }
  fVar9 = fVar3 / fVar12;
  fVar15 = fVar9 * fVar15;
  if (fVar12 <= 0.0) {
    fVar12 = 0.0;
  }
  else {
    fVar12 = SQRT(fVar15 * fVar15 + fVar9 * fVar2 * fVar9 * fVar2 + fVar9 * fVar11 * fVar9 * fVar11)
             * fVar12;
  }
  if (fVar12 < fVar1 - _DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */) {
    if (fVar13 <= 0.0) {
      fVar13 = 0.0;
    }
    fVar15 = 0.0;
    if (fVar13 <= fVar16) {
      fVar13 = fVar16;
    }
    fVar16 = (fVar1 - fVar12) * _DAT_14382e130 /* 0.699999988079071, 0x3f333333 */;
    fVar12 = (fVar3 / fVar13) * fVar11;
    fVar1 = (fVar3 / fVar13) * fVar2;
    if (0.0 < fVar13) {
      fVar15 = SQRT(fVar12 * fVar12 + fVar1 * fVar1) * fVar13;
    }
    fVar15 = fVar15 + fVar16;
    fVar13 = fVar11 * fVar11 + fVar2 * fVar2;
    fVar12 = fVar15 / SQRT(fVar13);
    if (_DAT_14382e110 /* 1.0000000036274937e-15, 0x26901d7d */ <= fVar13) {
      fVar11 = fVar12 * fVar11;
      fVar15 = fVar12 * fVar2;
    }
    else {
      fVar11 = 0.0;
    }
    fVar13 = param_3[2];
    *(ulonglong *)param_2 = CONCAT44(param_2[1] + 0.0,fVar15 + fVar5);
    fVar5 = *param_3;
    param_2[2] = fVar11 + fVar4;
    fVar4 = (float)((uint)fVar5 & uVar14);
    if ((float)((uint)fVar5 & uVar14) <= (float)((uint)fVar13 & uVar14)) {
      fVar4 = (float)((uint)fVar13 & uVar14);
    }
    fVar1 = fVar5 * (fVar3 / fVar4);
    fVar12 = fVar13 * (fVar3 / fVar4);
    if ((0.0 < fVar4) &&
       (fVar4 = SQRT(fVar12 * fVar12 + fVar1 * fVar1) * fVar4, _DAT_143830ee8 /* 0.0010000000474974513, 0x3a83126f */ <= fVar4)) {
      fVar3 = *(float *)(param_1 + 0x51c) - fVar4;
      if (fVar3 <= 0.0) {
        fVar3 = 0.0;
      }
      if (fVar16 <= fVar3) {
        fVar3 = fVar16;
      }
      fVar3 = (fVar3 + fVar4) / fVar4;
    }
    *param_3 = fVar5 * fVar3;
    param_3[2] = fVar13 * fVar3;
  }
  return param_2;
}


