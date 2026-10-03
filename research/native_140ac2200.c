/* SwingRegion_140ac2200 @ 0x140ac2200 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_140ac2200(longlong param_1)

{
  float fVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float afStackX_8 [2];
  float afStackX_10 [2];
  undefined1 auStack_78 [112];
  
  FUN_140ab4450(param_1 + 0x444,param_1 + 0x3c8,param_1 + 0x4d0,auStack_78,afStackX_8,afStackX_10,0)
  ;
  fVar1 = _DAT_14382dce0 /* 1.0 */;
  fVar7 = *(float *)(param_1 + 0x3cc) - *(float *)(param_1 + 0x448);
  fVar4 = *(float *)(param_1 + 0x3d0) - *(float *)(param_1 + 0x44c);
  fVar6 = *(float *)(param_1 + 0x3c8) - *(float *)(param_1 + 0x444);
  fVar3 = (float)((uint)fVar4 & _DAT_14382e160 /* None */);
  if ((float)((uint)fVar4 & _DAT_14382e160 /* None */) <= (float)((uint)fVar7 & _DAT_14382e160 /* None */)) {
    fVar3 = (float)((uint)fVar7 & _DAT_14382e160 /* None */);
  }
  if (fVar3 <= (float)((uint)fVar6 & _DAT_14382e160 /* None */)) {
    fVar3 = (float)((uint)fVar6 & _DAT_14382e160 /* None */);
  }
  if (0.0 < fVar3) {
    fVar3 = _DAT_14382dce0 /* 1.0 */ / fVar3;
    fVar4 = fVar3 * fVar4;
    fVar6 = fVar3 * fVar6;
    fVar3 = fVar3 * fVar7;
    fVar5 = _DAT_14382dce0 /* 1.0 */ / SQRT(fVar3 * fVar3 + fVar6 * fVar6 + fVar4 * fVar4);
    fVar6 = fVar5 * fVar6;
    fVar7 = fVar5 * fVar3;
    fVar4 = fVar5 * fVar4;
  }
  fVar3 = (float)((uint)fVar6 & _DAT_14382e160 /* None */);
  if ((float)((uint)fVar6 & _DAT_14382e160 /* None */) <= (float)((uint)fVar4 & _DAT_14382e160 /* None */)) {
    fVar3 = (float)((uint)fVar4 & _DAT_14382e160 /* None */);
  }
  fVar4 = (_DAT_14382dce0 /* 1.0 */ / fVar3) * fVar4;
  fVar6 = (_DAT_14382dce0 /* 1.0 */ / fVar3) * fVar6;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0;
  }
  else {
    fVar3 = SQRT(fVar4 * fVar4 + fVar6 * fVar6) * fVar3;
  }
  fVar6 = (float)FUN_141c58560(fVar7,fVar3);
  fVar6 = fVar6 * _DAT_143855568 /* -57.2957763671875 */;
  fVar3 = (float)FUN_140311350(param_1 + 0x3c8,param_1 + 0x444);
  fVar3 = (fVar3 - _DAT_14383d264 /* 12.0 */) * _DAT_1438398cc /* 0.125 */;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0;
  }
  if (fVar1 <= fVar3) {
    fVar3 = fVar1;
  }
  fVar4 = (float)FUN_1402c2450(param_1 + 0x4b8);
  fVar3 = _DAT_1438312b0 /* 50.0 */ - fVar3 * _DAT_14384bc0c /* 45.0 */;
  cVar2 = FUN_14098fc80(*(undefined8 *)(param_1 + 0x108));
  if (cVar2 != '\0') {
    fVar3 = *(float *)(param_1 + 0x42c);
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    if (fVar1 <= fVar3) {
      fVar3 = fVar1;
    }
    fVar3 = fVar3 * _DAT_14382f0e4 /* 10.0 */ + _DAT_14384bc0c /* 45.0 */;
  }
  if ((((fVar6 < fVar3) && (0.0 < *(float *)(param_1 + 0x4bc))) && (*(int *)(param_1 + 0x574) != 0))
     || ((afStackX_8[0] <= _DAT_1438416fc /* 60.0 */ && (afStackX_10[0] <= fVar3)))) {
    cVar2 = (fVar4 <= _DAT_14382f2cc /* 20.0 */) + '\x01';
  }
  else {
    cVar2 = '\0';
  }
  return cVar2;
}


