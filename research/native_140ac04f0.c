/* SwingRegion_140ac04f0 @ 0x140ac04f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_140ac04f0(longlong param_1,float *param_2,float *param_3,float *param_4,char param_5,
                     float *param_6)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  undefined1 auStack_c8 [176];
  
  uVar1 = _DAT_14382e160 /* None, 0x7fffffff */;
  fVar14 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
  fVar15 = *(float *)(param_1 + 0x440) - param_4[2];
  fVar18 = *(float *)(param_1 + 0x438) - *param_4;
  fVar20 = *(float *)(param_1 + 0x43c) - param_4[1];
  fVar13 = (float)((uint)fVar15 & _DAT_14382e160 /* None, 0x7fffffff */);
  if ((float)((uint)fVar15 & _DAT_14382e160 /* None, 0x7fffffff */) <= (float)((uint)fVar20 & _DAT_14382e160 /* None, 0x7fffffff */)) {
    fVar13 = (float)((uint)fVar20 & _DAT_14382e160 /* None, 0x7fffffff */);
  }
  if (fVar13 <= (float)((uint)fVar18 & _DAT_14382e160 /* None, 0x7fffffff */)) {
    fVar13 = (float)((uint)fVar18 & _DAT_14382e160 /* None, 0x7fffffff */);
  }
  fVar16 = fVar20;
  if (0.0 < fVar13) {
    fVar13 = _DAT_14382dce0 /* 1.0, 0x3f800000 */ / fVar13;
    fVar15 = fVar13 * fVar15;
    fVar18 = fVar13 * fVar18;
    fVar13 = fVar13 * fVar20;
    fVar16 = _DAT_14382dce0 /* 1.0, 0x3f800000 */ / SQRT(fVar13 * fVar13 + fVar18 * fVar18 + fVar15 * fVar15);
    fVar18 = fVar16 * fVar18;
    fVar15 = fVar16 * fVar15;
    fVar16 = fVar16 * fVar13;
  }
  FUN_1402d0740(&fStack_e8,param_3);
  uVar2 = _DAT_14382e890 /* -0.0, 0x80000000 */;
  fVar11 = (float)((uint)fVar18 ^ _DAT_14382e890 /* -0.0, 0x80000000 */);
  fVar13 = (float)((uint)fVar11 & uVar1);
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  if (fVar13 <= (float)((uint)fVar15 & uVar1)) {
    fVar13 = (float)((uint)fVar15 & uVar1);
  }
  fVar19 = fVar15;
  if (0.0 < fVar13) {
    fVar11 = fVar11 * (fVar14 / fVar13);
    fVar13 = (fVar14 / fVar13) * fVar15;
    fVar19 = fVar14 / SQRT(fVar11 * fVar11 + fVar13 * fVar13);
    fVar11 = fVar19 * fVar11;
    fVar19 = fVar19 * fVar13;
  }
  fVar4 = (float)FUN_1402c2450(param_3);
  fVar13 = param_3[2];
  fVar6 = *param_3;
  fVar9 = fVar6 * fVar18 + param_3[1] * fVar16 + fVar13 * fVar15;
  fStack_d8 = *param_3 - fVar9 * fVar18;
  fStack_d4 = param_3[1] - fVar9 * fVar16;
  fStack_d0 = param_3[2] - fVar9 * fVar15;
  fVar9 = fStack_d8 * fVar19 + fStack_d0 * fVar11;
  fVar11 = fVar11 * fVar9;
  fVar9 = fVar9 * fVar19;
  fVar17 = fStack_d0 - fVar11;
  fVar12 = fStack_d8 - fVar9;
  fVar19 = (float)((uint)fVar11 & uVar1);
  if (fVar19 <= 0.0) {
    fVar19 = 0.0;
  }
  if (fVar19 <= (float)((uint)fVar9 & uVar1)) {
    fVar19 = (float)((uint)fVar9 & uVar1);
  }
  fVar10 = fVar9 * (fVar14 / fVar19);
  fVar5 = fVar11 * (fVar14 / fVar19);
  if (fVar19 <= 0.0) {
    fVar19 = 0.0;
  }
  else {
    fVar19 = SQRT(fVar5 * fVar5 + fVar10 * fVar10) * fVar19;
  }
  fVar19 = fVar4 * fVar4 - fVar19 * fVar19;
  if (fVar19 <= 0.0) {
    fVar19 = 0.0;
  }
  fVar19 = SQRT(fVar19);
  fVar5 = fVar12 * fVar12 + fStack_d4 * fStack_d4 + fVar17 * fVar17;
  fVar4 = fVar19 / SQRT(fVar5);
  if (_DAT_14382e110 /* 1.0000000036274937e-15, 0x26901d7d */ <= fVar5) {
    fVar17 = fVar17 * fVar4;
    fVar19 = fVar12 * fVar4;
    fVar4 = fVar4 * fStack_d4;
  }
  else {
    fVar4 = 0.0;
    fVar17 = 0.0;
  }
  if (_DAT_143830ee8 /* 0.0010000000474974513, 0x3a83126f */ <= fVar6 * fVar6 + fVar13 * fVar13) {
    fVar13 = param_3[2];
    fVar6 = *param_3;
  }
  else {
    fVar13 = *(float *)(param_1 + 0x420);
    fVar6 = *(float *)(param_1 + 0x418);
  }
  uVar8 = FUN_141c58560(fVar6,fVar13);
  fVar6 = (float)((uint)(fVar9 + fVar19) & uVar1);
  fVar13 = (float)((uint)(fVar17 + fVar11) & uVar1);
  if (fVar13 <= fVar6) {
    fVar13 = fVar6;
  }
  fVar6 = (fVar14 / fVar13) * (fVar17 + fVar11);
  fVar11 = (fVar14 / fVar13) * (fVar9 + fVar19);
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  else {
    fVar13 = SQRT(fVar6 * fVar6 + fVar11 * fVar11) * fVar13;
  }
  uVar7 = FUN_141c58560(fVar4,fVar13);
  fVar19 = (float)((uint)*param_3 & uVar1);
  fVar11 = (float)((uint)param_3[2] & uVar1);
  fVar13 = (float)((uint)param_3[1] & uVar1);
  if (fVar13 <= fVar11) {
    fVar13 = fVar11;
  }
  if (fVar13 <= fVar19) {
    fVar13 = fVar19;
  }
  fVar19 = fVar14 / fVar13;
  fVar6 = fVar19 * *param_3;
  fVar4 = 0.0;
  fVar11 = fVar19 * param_3[1];
  fVar19 = fVar19 * param_3[2];
  if (0.0 < fVar13) {
    fVar4 = SQRT(fVar11 * fVar11 + fVar6 * fVar6 + fVar19 * fVar19) * fVar13;
  }
  FUN_141c5a450(param_2,uVar8,uVar7,fVar4);
  fVar13 = fStack_e8 * fVar18 + fStack_e4 * fVar16 + fStack_e0 * fVar15;
  if (fVar13 < _DAT_14384e300 /* -0.10000000149011612, 0xbdcccccd */) {
    fVar13 = (float)((uint)fVar13 & uVar1);
    if (_DAT_143836d08 /* 0.30000001192092896, 0x3e99999a */ <= fVar13) {
      fVar13 = (fVar13 - _DAT_143836d08 /* 0.30000001192092896, 0x3e99999a */) * _DAT_143880d88 /* 1.6666667461395264, 0x3fd55556 */;
      if (fVar13 <= 0.0) {
        fVar13 = 0.0;
      }
      if (fVar14 <= fVar13) {
        fVar13 = fVar14;
      }
      fVar14 = fVar13 * _DAT_1438ac3a4 /* 0.3999999761581421, 0x3ecccccc */ + _DAT_143837a24 /* 0.6000000238418579, 0x3f19999a */;
    }
    else {
      fVar13 = (fVar13 - _DAT_14382e120 /* 0.10000000149011612, 0x3dcccccd */) * _DAT_1438ac768 /* 4.999999523162842, 0x409fffff */;
      if (fVar13 <= 0.0) {
        fVar13 = 0.0;
      }
      if (fVar14 <= fVar13) {
        fVar13 = fVar14;
      }
      fVar14 = fVar14 - fVar13 * _DAT_1438ac3a4 /* 0.3999999761581421, 0x3ecccccc */;
    }
    puVar3 = (undefined8 *)FUN_141c5b5d0(&fStack_e8,&fStack_d8,param_2,fVar14);
    *(undefined8 *)param_2 = *puVar3;
    param_2[2] = *(float *)(puVar3 + 1);
  }
  if (param_5 != '\0') {
    if (0.0 <= fVar20) {
      if (0.0 < param_2[1]) {
        if (param_3[1] <= 0.0) {
          fVar14 = (float)((uint)param_2[1] ^ uVar2);
          if ((param_6 == (float *)0x0) ||
             (0.0 < fVar14 * param_6[1] + (float)((uint)*param_2 ^ uVar2) * *param_6 +
                    (float)((uint)param_2[2] ^ uVar2) * param_6[2])) {
            *param_2 = (float)((uint)*param_2 ^ uVar2);
            param_2[1] = fVar14;
            param_2[2] = (float)((uint)param_2[2] ^ uVar2);
          }
        }
        else {
          fStack_e0 = param_3[2];
          fStack_e8 = (float)*(undefined8 *)param_3;
          _fStack_e8 = CONCAT44((uint)((ulonglong)*(undefined8 *)param_3 >> 0x20) ^ uVar2,fStack_e8)
          ;
          puVar3 = (undefined8 *)FUN_140ac04f0(param_1,auStack_c8,&fStack_e8,param_4,0,0);
          *(undefined8 *)param_2 = *puVar3;
          param_2[2] = *(float *)(puVar3 + 1);
        }
      }
    }
    else {
      *(ulonglong *)param_2 = (ulonglong)((uint)param_3[1] & uVar1 ^ uVar2) << 0x20;
      param_2[2] = 0.0;
    }
  }
  return param_2;
}


