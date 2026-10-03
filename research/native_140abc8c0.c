/* SwingRegion_140abc8c0 @ 0x140abc8c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140abc8c0(longlong param_1,undefined8 *param_2,float *param_3,undefined8 param_4,float *param_5,
             undefined8 param_6,float param_7)

{
  bool bVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  undefined1 auStack_c8 [176];
  
  fVar3 = (float)FUN_1402c2450(param_3);
  fVar8 = _DAT_1438ac390 /* 0.06666667014360428, 0x3d888889 */;
  uVar2 = _DAT_14382e160 /* None, 0x7fffffff */;
  fVar12 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
  fVar3 = (fVar3 - _DAT_143834a14 /* 4.0, 0x40800000 */) * _DAT_14382e124 /* 0.25, 0x3e800000 */;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0;
  }
  if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar3) {
    fVar3 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
  }
  if (_DAT_14382e118 /* 9.999999747378752e-05, 0x38d1b717 */ <= fVar3) {
    fVar11 = 0.0;
    fVar4 = (float)((uint)param_3[2] & _DAT_14382e160 /* None, 0x7fffffff */);
    fVar9 = (float)((uint)*param_3 & _DAT_14382e160 /* None, 0x7fffffff */);
    if (fVar9 <= fVar4) {
      fVar9 = fVar4;
    }
    fVar7 = (_DAT_14382dce0 /* 1.0, 0x3f800000 */ / fVar9) * param_3[2];
    fVar4 = (_DAT_14382dce0 /* 1.0, 0x3f800000 */ / fVar9) * *param_3;
    if (0.0 < fVar9) {
      fVar11 = SQRT(fVar7 * fVar7 + fVar4 * fVar4) * fVar9;
    }
    fVar9 = (fVar11 - _DAT_14382f0e8 /* 25.0, 0x41c80000 */) * _DAT_1438ac390 /* 0.06666667014360428, 0x3d888889 */;
    if (fVar9 <= 0.0) {
      fVar9 = 0.0;
    }
    if (_DAT_14382dce0 /* 1.0, 0x3f800000 */ <= fVar9) {
      fVar9 = _DAT_14382dce0 /* 1.0, 0x3f800000 */;
    }
    *(float *)(param_1 + 0x4f8) = (fVar9 + _DAT_14382dce0 /* 1.0, 0x3f800000 */) * param_7 + *(float *)(param_1 + 0x4f8);
    fVar4 = (float)FUN_140311350(param_5,param_1 + 0x3c8);
    fVar4 = (fVar4 - _DAT_1438957e0 /* 24.0, 0x41c00000 */) * _DAT_1438564c4 /* 0.0833333358168602, 0x3daaaaab */;
    if (fVar4 <= 0.0) {
      fVar4 = 0.0;
    }
    if (fVar12 <= fVar4) {
      fVar4 = fVar12;
    }
    fVar4 = (fVar12 - fVar9) * fVar4;
    fVar11 = fVar4 * _DAT_14382e130 /* 0.699999988079071, 0x3f333333 */;
    FUN_1402d0740(&fStack_e8,param_4);
    fVar7 = (float)FUN_1402c2450(param_3);
    fVar6 = (float)((uint)param_3[2] & uVar2);
    fVar9 = (float)((uint)*param_3 & uVar2);
    if (fVar9 <= fVar6) {
      fVar9 = fVar6;
    }
    fVar13 = 0.0;
    fVar10 = (fVar12 / fVar9) * param_3[2];
    fVar6 = (fVar12 / fVar9) * *param_3;
    if (0.0 < fVar9) {
      fVar13 = SQRT(fVar10 * fVar10 + fVar6 * fVar6) * fVar9;
    }
    fVar9 = (float)((uint)fStack_e0 & uVar2);
    if ((float)((uint)fStack_e0 & uVar2) <= (float)((uint)fStack_e8 & uVar2)) {
      fVar9 = (float)((uint)fStack_e8 & uVar2);
    }
    fStack_e8 = fStack_e8 * (fVar12 / fVar9);
    fStack_e0 = fStack_e0 * (fVar12 / fVar9);
    fVar6 = 0.0;
    if (0.0 < fVar9) {
      fVar6 = SQRT(fStack_e0 * fStack_e0 + fStack_e8 * fStack_e8) * fVar9;
    }
    fVar9 = (float)FUN_141c58560(fStack_e4,fVar6);
    fVar9 = ((float)((uint)(fVar9 * _DAT_143855568 /* -57.2957763671875, 0xc2652ee0 */) & uVar2) - _DAT_1438794d0 /* 35.0, 0x420c0000 */) * _DAT_14386dc70 /* 0.03999999910593033, 0x3d23d70a */;
    if (fVar9 <= 0.0) {
      fVar9 = 0.0;
    }
    fVar8 = (param_3[1] - _DAT_14383f72c /* -10.0, 0xc1200000 */) * fVar8;
    if (fVar8 <= 0.0) {
      fVar8 = 0.0;
    }
    if (fVar12 <= fVar9) {
      fVar9 = fVar12;
    }
    if (fVar12 <= fVar8) {
      fVar8 = fVar12;
    }
    fVar11 = (fVar12 - fVar11) -
             ((fVar12 - fVar9) * _DAT_143837a1c /* 0.19999998807907104, 0x3e4ccccc */ - fVar4 * (fVar12 - fVar9) * _DAT_1438b4f28 /* 0.13999998569488525, 0x3e0f5c28 */);
    fVar8 = fVar12 - fVar8;
    bVar1 = 0.0 < (param_5[1] - *(float *)(param_1 + 0x3cc)) * param_3[1] +
                  (*param_5 - *(float *)(param_1 + 0x3c8)) * *param_3 +
                  (param_5[2] - *(float *)(param_1 + 0x3d0)) * param_3[2];
    fVar4 = _DAT_1438726d4 /* -4.0, 0xc0800000 */ - (fVar8 + fVar8);
    fVar9 = _DAT_1438347a4 /* -1.5, 0xbfc00000 */;
    if (bVar1) {
      fVar9 = (_DAT_1438cea68 /* -1.75, 0xbfe00000 */ - fVar8 * _DAT_14382e128 /* 0.5, 0x3f000000 */) * fVar11;
    }
    fVar8 = (*(float *)(param_1 + 0x4f8) - _DAT_143836d08 /* 0.30000001192092896, 0x3e99999a */) * _DAT_14384ebec /* 3.3333332538604736, 0x40555555 */;
    if (fVar8 <= 0.0) {
      fVar8 = 0.0;
    }
    if (fVar12 <= fVar8) {
      fVar8 = fVar12;
    }
    FUN_1402d0740(auStack_c8,param_3);
    FUN_141c46f80(&fStack_d8,auStack_c8,&fStack_e8,param_1 + 0x4f4,
                  ((fVar4 - fVar9) * fVar8 + fVar9) * fVar3,_DAT_1438414f4 /* -15.0, 0xc1700000 */,
                  ((fVar12 - fVar11) * fVar8 + fVar11) * _DAT_1438cea58 /* 6.981317043304443, 0x40df66f3 */,param_7);
    fVar3 = (float)func_0x000141c59090(&fStack_e8,auStack_c8);
    fVar8 = _DAT_14382e110 /* 1.0000000036274937e-15, 0x26901d7d */;
    fVar9 = fVar3 * _DAT_1438b146c /* 1.4323943853378296, 0x3fb758b3 */ - _DAT_1438398cc /* 0.125, 0x3e000000 */;
    fVar3 = (float)((uint)fStack_d0 & uVar2);
    if ((float)((uint)fStack_d0 & uVar2) <= (float)((uint)fStack_d4 & uVar2)) {
      fVar3 = (float)((uint)fStack_d4 & uVar2);
    }
    if (fVar9 <= 0.0) {
      fVar9 = 0.0;
    }
    if (fVar3 <= (float)((uint)fStack_d8 & uVar2)) {
      fVar3 = (float)((uint)fStack_d8 & uVar2);
    }
    if (fVar12 <= fVar9) {
      fVar9 = fVar12;
    }
    fVar4 = fStack_d8;
    fVar11 = fStack_d0;
    fVar6 = fStack_d4;
    if (0.0 < fVar3) {
      fVar3 = fVar12 / fVar3;
      fVar11 = fStack_d0 * fVar3;
      fVar6 = fStack_d4 * fVar3;
      fVar3 = fStack_d8 * fVar3;
      fVar12 = fVar12 / SQRT(fVar6 * fVar6 + fVar3 * fVar3 + fVar11 * fVar11);
      fVar4 = fVar12 * fVar3;
      fVar11 = fVar12 * fVar11;
      fVar6 = fVar12 * fVar6;
    }
    fVar3 = fStack_d4 * fStack_d4 + fStack_d8 * fStack_d8 + fStack_d0 * fStack_d0;
    fVar7 = ((fVar4 * *param_3 + fVar6 * param_3[1] + fVar11 * param_3[2]) - fVar7) * fVar9 + fVar7;
    fVar12 = fVar7 / SQRT(fVar3);
    if (_DAT_14382e110 /* 1.0000000036274937e-15, 0x26901d7d */ <= fVar3) {
      fVar3 = fStack_d4 * fVar12;
      fVar7 = fStack_d8 * fVar12;
      fVar12 = fStack_d0 * fVar12;
    }
    else {
      fVar3 = 0.0;
      fVar12 = 0.0;
    }
    fStack_e8 = fVar7;
    fStack_e0 = fVar12;
    if (((*(int *)(param_1 + 0x574) == 0) && (0.0 < fVar3)) && (bVar1)) {
      fStack_d4 = 0.0;
      fStack_e4 = fVar3;
      fStack_d8 = fVar7;
      fStack_d0 = fVar12;
      fStack_e8 = (float)FUN_1402c2450(&fStack_d8);
      if (fVar13 <= fStack_e8) {
        fStack_e8 = fVar13;
      }
      fVar9 = fVar12 * fVar12 + fVar7 * fVar7;
      fStack_e0 = 0.0;
      if (fVar8 <= fVar9) {
        fStack_e8 = fStack_e8 / SQRT(fVar9);
        fStack_e0 = fStack_e8 * fVar12;
        fStack_e8 = fStack_e8 * fVar7;
      }
    }
    uVar5 = CONCAT44(fVar3,fStack_e8);
  }
  else {
    *(undefined4 *)(param_1 + 0x4f8) = 0;
    uVar5 = *(undefined8 *)param_3;
    fStack_e0 = param_3[2];
  }
  *param_2 = uVar5;
  *(float *)(param_2 + 1) = fStack_e0;
  return param_2;
}


