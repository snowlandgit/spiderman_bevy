/* Decompiled from the locally installed Spider-Man.exe.
 * Class names come from RTTI. Vtable slot names are labels, not recovered source names.
 * Types and unnamed callees are incomplete. This is research, not recompilable source. */

/* HeroStateSwingLocal_virtual_1 @ 0x140ab97c0 */

/* WARNING: Removing unreachable block (ram,0x000141676787) */
/* WARNING: Removing unreachable block (ram,0x000141676791) */
/* WARNING: Removing unreachable block (ram,0x0001416767c3) */
/* WARNING: Removing unreachable block (ram,0x0001416767d0) */
/* WARNING: Removing unreachable block (ram,0x0001416767e6) */
/* WARNING: Removing unreachable block (ram,0x0001416767f0) */
/* WARNING: Removing unreachable block (ram,0x000141676801) */
/* WARNING: Removing unreachable block (ram,0x000141676811) */
/* WARNING: Removing unreachable block (ram,0x000141676809) */
/* WARNING: Removing unreachable block (ram,0x00014167680f) */
/* WARNING: Removing unreachable block (ram,0x00014167681e) */

void HeroStateSwingLocal_virtual_1(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    (**(code **)(*param_1 + 0x40))();
    *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) & 0xfe;
    if (((int)param_1[7] != 0) && ((*(ushort *)(param_1[1] + 8) >> 0xd & 1) != 0)) {
      FUN_14167d120(0x147a43720,param_1,(int)param_1[7],*(undefined2 *)(param_1[1] + 0x18));
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  if ((*(ushort *)(param_1[1] + 8) >> 10 & 1) == 0) {
    lVar3 = FUN_141984370(param_1 + 3);
    if (lVar3 != 0) {
      func_0x000141984600(lVar3);
    }
    FUN_14159e150(param_1[1],param_1);
    FUN_1416793a0(0x146046060,param_1);
    lVar3 = func_0x0001416798f0((longlong)param_1 + 0x3c);
    if (lVar3 != 0) {
      *(char *)(lVar3 + 0x1c) = *(char *)(lVar3 + 0x1c) + -1;
    }
  }
  *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) | 2;
  FUN_14190fa90(0x147a42f80,(longlong)param_1 + 0x14);
  plVar2 = (longlong *)param_1[8];
  if (plVar2 != (longlong *)0x0) {
    plVar1 = plVar2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    if ((int)*plVar1 == 0) {
      (**(code **)(*plVar2 + 0x50))(plVar2[2]);
      *plVar2 = 0;
      plVar2[2] = 0;
      func_0x000141757470(plVar2);
    }
    param_1[8] = 0;
  }
  return;
}


/* HeroStateSwingLocal_virtual_2 @ 0x140ab97d0 */

/* WARNING: Removing unreachable block (ram,0x000141676787) */
/* WARNING: Removing unreachable block (ram,0x000141676791) */
/* WARNING: Removing unreachable block (ram,0x0001416767c3) */
/* WARNING: Removing unreachable block (ram,0x0001416767d0) */
/* WARNING: Removing unreachable block (ram,0x0001416767e6) */
/* WARNING: Removing unreachable block (ram,0x0001416767f0) */
/* WARNING: Removing unreachable block (ram,0x000141676801) */
/* WARNING: Removing unreachable block (ram,0x000141676811) */
/* WARNING: Removing unreachable block (ram,0x000141676809) */
/* WARNING: Removing unreachable block (ram,0x00014167680f) */
/* WARNING: Removing unreachable block (ram,0x00014167681e) */

void HeroStateSwingLocal_virtual_2(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    (**(code **)(*param_1 + 0x40))();
    *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) & 0xfe;
    if (((int)param_1[7] != 0) && ((*(ushort *)(param_1[1] + 8) >> 0xd & 1) != 0)) {
      FUN_14167d120(0x147a43720,param_1,(int)param_1[7],*(undefined2 *)(param_1[1] + 0x18));
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  if ((*(ushort *)(param_1[1] + 8) >> 10 & 1) == 0) {
    lVar3 = FUN_141984370(param_1 + 3);
    if (lVar3 != 0) {
      func_0x000141984600(lVar3);
    }
    FUN_14159e150(param_1[1],param_1);
    FUN_1416793a0(0x146046060,param_1);
    lVar3 = func_0x0001416798f0((longlong)param_1 + 0x3c);
    if (lVar3 != 0) {
      *(char *)(lVar3 + 0x1c) = *(char *)(lVar3 + 0x1c) + -1;
    }
  }
  *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) | 2;
  FUN_14190fa90(0x147a42f80,(longlong)param_1 + 0x14);
  plVar2 = (longlong *)param_1[8];
  if (plVar2 != (longlong *)0x0) {
    plVar1 = plVar2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    if ((int)*plVar1 == 0) {
      (**(code **)(*plVar2 + 0x50))(plVar2[2]);
      *plVar2 = 0;
      plVar2[2] = 0;
      func_0x000141757470(plVar2);
    }
    param_1[8] = 0;
  }
  return;
}


/* HeroStateSwingLocal_virtual_3 @ 0x141675fb0 */

void HeroStateSwingLocal_virtual_3(void)

{
  return;
}


/* HeroStateSwingLocal_virtual_4 @ 0x1402bf350 */

void HeroStateSwingLocal_virtual_4(void)

{
  return;
}


/* HeroStateSwingLocal_virtual_6 @ 0x141675fc0 */

byte HeroStateSwingLocal_virtual_6(longlong param_1)

{
  ushort uVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
  lVar4 = *(longlong *)(param_1 + 8);
  cVar2 = func_0x000141982d50();
  if (cVar2 == '\0') {
    return 1;
  }
  lVar3 = FUN_141984400(lVar4 + 0xa8);
  if (lVar3 != 0) {
    return *(byte *)(lVar3 + 0x11f) >> 1 & 1;
  }
  uVar1 = *(ushort *)(lVar4 + 0x70);
  if ((ulonglong)uVar1 != 0) {
    lVar3 = 0;
    puVar5 = (undefined8 *)(*(longlong *)(lVar4 + 0x68) + 8);
    do {
      lVar4 = (**(code **)(*(longlong *)*puVar5 + 0x48))();
      if (*(longlong *)(lVar4 + 0x70) != 0) {
        return 0;
      }
      lVar3 = lVar3 + 1;
      puVar5 = puVar5 + 2;
    } while (lVar3 < (longlong)(ulonglong)uVar1);
  }
  return 1;
}


/* HeroStateSwingLocal_virtual_7 @ 0x141675fd0 */

void HeroStateSwingLocal_virtual_7(void)

{
  return;
}


/* HeroStateSwingLocal_virtual_8 @ 0x141675fe0 */

void HeroStateSwingLocal_virtual_8(void)

{
  return;
}


/* HeroStateSwingLocal_virtual_9 @ 0x140ab97b0 */

undefined8 HeroStateSwingLocal_virtual_9(void)

{
  return 0x146df2790;
}


/* HeroStateSwingLocal_virtual_10 @ 0x1409c8600 */

void FUN_1409c8600(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  FUN_1420e07d0();
  uVar2 = FUN_141f9e890(&UNK_1438bb058);
  *(undefined8 *)(param_1 + 0xe8) = uVar2;
  uVar2 = FUN_141f9e890(&UNK_1438bb070);
  lVar1 = *(longlong *)(param_1 + 8);
  *(undefined8 *)(param_1 + 0xf0) = uVar2;
  if (*(short *)(lVar1 + 0x88) == 0) {
    uVar2 = FUN_14167ab40(lVar1 + 0x58,0x146dd80e0);
  }
  else {
    uVar2 = func_0x0001416799a0(lVar1 + 0x80);
  }
  lVar1 = *(longlong *)(param_1 + 8);
  *(undefined8 *)(param_1 + 0x108) = uVar2;
  if (*(short *)(lVar1 + 0x88) == 0) {
    uVar2 = FUN_14167ab40(lVar1 + 0x58,0x146da9d90);
  }
  else {
    uVar2 = func_0x0001416799a0(lVar1 + 0x80);
  }
  *(undefined1 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x110) = uVar2;
  return;
}


/* HeroStateSwingLocal_virtual_11 @ 0x140ab97e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab97e0(longlong param_1,longlong param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ushort uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float afStackX_8 [2];
  float afStackX_10 [2];
  undefined1 auStackX_18 [8];
  undefined1 auStackX_20 [8];
  undefined4 *puVar20;
  ulonglong uVar21;
  undefined1 *puVar22;
  ulonglong uVar23;
  ulonglong in_stack_fffffffffffffe88;
  uint uVar24;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined4 uStack_128;
  uint uStack_124;
  float afStack_120 [4];
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  undefined8 uStack_100;
  undefined4 uStack_f8;
  undefined8 uStack_f0;
  undefined4 uStack_e8;
  undefined8 uStack_e0;
  undefined4 uStack_d8;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  longlong lStack_b8;
  
  FUN_1420e0800();
  *(undefined8 *)(param_1 + 0x444) = *(undefined8 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0x44c) = *(undefined4 *)(param_2 + 0x38);
  *(undefined8 *)(param_1 + 0x438) = *(undefined8 *)(param_2 + 0x24);
  *(undefined4 *)(param_1 + 0x440) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x450) = *(undefined4 *)(param_2 + 0x54);
  *(byte *)(param_1 + 0x5f9) = *(byte *)(param_2 + 0x6c) >> 6 & 1;
  *(byte *)(param_1 + 0x5fa) = *(byte *)(param_2 + 0x6d) & 1;
  uVar7 = FUN_141676930(param_1);
  uVar13 = FUN_140311350(param_1 + 0x438,uVar7);
  *(undefined4 *)(param_1 + 0x4a4) = uVar13;
  *(undefined4 *)(param_1 + 0x4a8) = 0;
  *(undefined8 *)(param_1 + 0x49c) = 0;
  uVar13 = func_0x0001416769f0(param_1);
  *(undefined8 *)(param_1 + 0x480) = 0;
  *(undefined4 *)(param_1 + 0x488) = 0;
  *(undefined8 *)(param_1 + 0x418) = 0;
  *(undefined4 *)(param_1 + 0x420) = 0;
  *(undefined8 *)(param_1 + 0x574) = 0;
  *(undefined8 *)(param_1 + 0x470) = 0;
  *(undefined4 *)(param_1 + 0x478) = 0;
  *(undefined4 *)(param_1 + 0x530) = uVar13;
  *(undefined8 *)(param_1 + 0x4f4) = 0;
  *(undefined8 *)(param_1 + 0x54c) = 0;
  *(undefined2 *)(param_1 + 0x5fb) = 0xff02;
  *(undefined1 *)(param_1 + 0x48c) = 0;
  *(undefined2 *)(param_1 + 0x5f0) = 0;
  *(undefined1 *)(param_1 + 0x5f8) = 0;
  *(undefined8 *)(param_1 + 0x4fc) = 0;
  *(undefined4 *)(param_1 + 0x47c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x424) = 0;
  *(undefined4 *)(param_1 + 0x434) = 0;
  *(undefined4 *)(param_1 + 0x430) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x42c) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x57c) = 0;
  *(undefined4 *)(param_1 + 0x494) = 0xf149f2ca;
  *(undefined4 *)(param_1 + 0x498) = 0;
  *(undefined4 *)(param_1 + 0x528) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x52c) = 0x3eb33333;
  *(undefined4 *)(param_1 + 0x5f3) = 1;
  *(undefined8 *)(param_1 + 0x504) = 0;
  *(undefined4 *)(param_1 + 0x518) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x5f2) = 1;
  *(undefined2 *)(param_1 + 0x538) = 0;
  *(undefined1 *)(param_1 + 0x5f7) = 0;
  *(undefined4 *)(param_1 + 0x598) = 0;
  puVar8 = (undefined8 *)0x147afdf10;
  if ((undefined8 *)**(longlong **)(param_1 + 8) != (undefined8 *)0x0) {
    puVar8 = (undefined8 *)**(longlong **)(param_1 + 8);
  }
  uVar7 = puVar8[1];
  *(undefined8 *)(param_1 + 0x59c) = *puVar8;
  *(undefined8 *)(param_1 + 0x5a4) = uVar7;
  uVar7 = puVar8[3];
  *(undefined8 *)(param_1 + 0x5ac) = puVar8[2];
  *(undefined8 *)(param_1 + 0x5b4) = uVar7;
  uVar13 = *(undefined4 *)((longlong)puVar8 + 0x24);
  uVar4 = *(undefined4 *)(puVar8 + 5);
  uVar5 = *(undefined4 *)((longlong)puVar8 + 0x2c);
  *(undefined4 *)(param_1 + 0x5bc) = *(undefined4 *)(puVar8 + 4);
  *(undefined4 *)(param_1 + 0x5c0) = uVar13;
  *(undefined4 *)(param_1 + 0x5c4) = uVar4;
  *(undefined4 *)(param_1 + 0x5c8) = uVar5;
  uVar13 = *(undefined4 *)((longlong)puVar8 + 0x34);
  uVar4 = *(undefined4 *)(puVar8 + 7);
  uVar5 = *(undefined4 *)((longlong)puVar8 + 0x3c);
  *(undefined4 *)(param_1 + 0x5cc) = *(undefined4 *)(puVar8 + 6);
  *(undefined4 *)(param_1 + 0x5d0) = uVar13;
  *(undefined4 *)(param_1 + 0x5d4) = uVar4;
  *(undefined4 *)(param_1 + 0x5d8) = uVar5;
  FUN_1420df1c0(param_1 + 0x580,0);
  FUN_1420df1c0(param_1 + 0x58c,0);
  *(undefined4 *)(param_1 + 0x490) = 0xbf800000;
  FUN_140abcf40(param_1,0);
  FUN_140ac00e0(param_1);
  uVar6 = *(ushort *)(param_2 + 0x6c);
  if ((uVar6 & 2) != 0) {
    *(undefined8 *)(param_1 + 0x4b8) = *(undefined8 *)(param_2 + 0x5c);
    *(undefined4 *)(param_1 + 0x4c0) = *(undefined4 *)(param_2 + 100);
    uVar6 = *(ushort *)(param_2 + 0x6c);
  }
  if ((uVar6 & 4) != 0) {
    *(undefined4 *)(param_1 + 0x50c) = *(undefined4 *)(param_2 + 0x68);
  }
  pfVar1 = (float *)(param_1 + 0x4b8);
  *(undefined8 *)(param_1 + 0x4c4) = *(undefined8 *)pfVar1;
  *(undefined4 *)(param_1 + 0x4cc) = *(undefined4 *)(param_1 + 0x4c0);
  if ((0.0 < *(float *)(param_1 + 0x4bc)) && ((*(byte *)(param_2 + 0x6c) & 8) != 0)) {
    *(undefined4 *)(param_1 + 0x574) = 1;
  }
  uVar7 = FUN_141676930(param_1);
  FUN_140ac04f0(param_1,&fStack_110,pfVar1,uVar7,1,0);
  uVar24 = _DAT_14382e160;
  fVar19 = _DAT_14382dce0;
  fVar14 = (float)((uint)fStack_108 & _DAT_14382e160);
  if ((float)((uint)fStack_108 & _DAT_14382e160) <= (float)((uint)fStack_10c & _DAT_14382e160)) {
    fVar14 = (float)((uint)fStack_10c & _DAT_14382e160);
  }
  if (fVar14 <= (float)((uint)fStack_110 & _DAT_14382e160)) {
    fVar14 = (float)((uint)fStack_110 & _DAT_14382e160);
  }
  if (0.0 < fVar14) {
    fVar14 = _DAT_14382dce0 / fVar14;
    fStack_10c = fStack_10c * fVar14;
    fStack_108 = fStack_108 * fVar14;
    fStack_110 = fStack_110 * fVar14;
    fVar14 = _DAT_14382dce0 /
             SQRT(fStack_10c * fStack_10c + fStack_110 * fStack_110 + fStack_108 * fStack_108);
    fStack_110 = fStack_110 * fVar14;
    fStack_10c = fStack_10c * fVar14;
    fStack_108 = fStack_108 * fVar14;
  }
  pfVar2 = (float *)(param_1 + 0x4d0);
  uStack_138 = (code *)CONCAT44(fStack_10c,fStack_110);
  uVar7 = uStack_138;
  *(code **)pfVar2 = uStack_138;
  *(float *)(param_1 + 0x4d8) = fStack_108;
  fVar14 = *(float *)(param_1 + 0x4d4);
  fVar16 = *pfVar2;
  fVar3 = *(float *)(param_1 + 0x4d8);
  fVar17 = fVar16 * fVar16 + fVar14 * fVar14 + fVar3 * fVar3;
  if ((float)((uint)fVar17 & uVar24) <= _DAT_14382e110) {
    fVar17 = 0.0;
  }
  else {
    fVar17 = (fVar14 * *(float *)(param_1 + 0x4bc) + fVar16 * *pfVar1 +
             fVar3 * *(float *)(param_1 + 0x4c0)) / fVar17;
  }
  fVar18 = fVar14 * fVar17;
  fVar15 = fVar16 * fVar17;
  fVar17 = fVar3 * fVar17;
  if (fVar14 * fVar18 + fVar16 * fVar15 + fVar3 * fVar17 < 0.0) {
    fVar15 = (float)((uint)fVar15 ^ _DAT_14382e890);
    fVar18 = (float)((uint)fVar18 ^ _DAT_14382e890);
    fVar17 = (float)((uint)fVar17 ^ _DAT_14382e890);
  }
  uStack_130 = CONCAT44(uStack_130._4_4_,fVar17);
  uStack_138 = (code *)CONCAT44(fVar18,fVar15);
  *(undefined8 *)(param_1 + 0x4e8) = uVar7;
  *(float *)(param_1 + 0x4f0) = fStack_108;
  *(code **)(param_1 + 0x4dc) = uStack_138;
  *(float *)(param_1 + 0x4e4) = fVar17;
  FUN_140abd610(param_1);
  uVar7 = FUN_141f9e890(&UNK_1438ce730);
  *(undefined8 *)(param_1 + 0xe8) = uVar7;
  uVar7 = FUN_141f9e890(&UNK_1438ce748);
  *(undefined8 *)(param_1 + 0xf0) = uVar7;
  func_0x000140b8fe10(param_1 + 0x120,param_1);
  lVar9 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar9 + 0x88) == 0) {
    lVar9 = FUN_14167ab40(lVar9 + 0x58,0x146dacd70);
  }
  else {
    lVar9 = func_0x0001416799a0(lVar9 + 0x80);
  }
  if (*(char *)(param_1 + 0x5f7) != '\0') {
    lVar10 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar10 + 0x88) == 0) {
      uVar7 = FUN_14167ab40(lVar10 + 0x58,0x146dd6340);
    }
    else {
      uVar7 = func_0x0001416799a0(lVar10 + 0x80);
    }
    lVar10 = func_0x000140923770(uVar7);
    FUN_14085f2e0(lVar9,*(undefined4 *)(lVar10 + 0xc38),1);
  }
  puVar22 = auStackX_18;
  FUN_140ab4450(param_1 + 0x444,param_1 + 0x3c8,pfVar2,&uStack_138,afStackX_8,puVar22,
                in_stack_fffffffffffffe88 & 0xffffffffffffff00);
  lVar10 = *(longlong *)(param_1 + 0x388);
  fVar14 = *(float *)(lVar10 + 0x14);
  fVar16 = *(float *)(lVar10 + 0x18) - fVar14;
  if ((float)((uint)fVar16 & uVar24) <= _DAT_14382e118) {
    if (fVar14 <= afStackX_8[0]) {
      fVar16 = _DAT_14382e128;
      if (fVar14 < afStackX_8[0]) {
        fVar16 = fVar19;
      }
    }
    else {
      fVar16 = 0.0;
    }
  }
  else {
    fVar16 = (afStackX_8[0] - fVar14) / fVar16;
    if (fVar16 <= 0.0) {
      fVar16 = 0.0;
    }
    if (fVar19 <= fVar16) {
      fVar16 = fVar19;
    }
  }
  uStack_e0 = *(undefined8 *)(param_1 + 0x444);
  fVar14 = (*(float *)(lVar10 + 0xc) - *(float *)(lVar10 + 8)) * fVar16 + *(float *)(lVar10 + 8);
  *(float *)(param_1 + 0x4b0) = fVar14;
  fVar14 = fVar14 * _DAT_143848d00;
  if (_DAT_14387e6ac <= fVar14) {
    fVar14 = _DAT_14387e6ac;
  }
  *(float *)(param_1 + 0x4ac) = fVar14;
  *(undefined4 *)(param_1 + 0x4b4) = *(undefined4 *)(lVar10 + 0x10);
  uStack_d8 = *(undefined4 *)(param_1 + 0x44c);
  uStack_f0 = *(undefined8 *)(param_1 + 0x3c8);
  uStack_e8 = *(undefined4 *)(param_1 + 0x3d0);
  uStack_100 = *(undefined8 *)pfVar1;
  uStack_f8 = *(undefined4 *)(param_1 + 0x4c0);
  fVar14 = (float)FUN_140ab38e0(*(undefined8 *)(param_1 + 0x380),&uStack_e0,&uStack_f0,&uStack_100);
  *(float *)(param_1 + 0x51c) = fVar14;
  if (*(char *)(param_1 + 0x5f7) != '\0') {
    fVar14 = fVar14 * _DAT_143840c8c;
    *(float *)(param_1 + 0x51c) = fVar14;
  }
  lVar10 = *(longlong *)(param_1 + 0x380);
  fVar16 = *(float *)(lVar9 + 0x324);
  if (*(float *)(lVar9 + 0x324) <= fVar14) {
    fVar16 = fVar14;
  }
  *(float *)(param_1 + 0x51c) = fVar16;
  fVar14 = fVar16 * _DAT_14382ee94;
  *(undefined4 *)(param_1 + 0x468) = *(undefined4 *)(lVar9 + 0x334);
  *(float *)(param_1 + 0x524) = fVar14;
  fVar16 = fVar16 * *(float *)(lVar10 + 0x24);
  if (fVar16 <= *(float *)(lVar10 + 0x28)) {
    fVar16 = *(float *)(lVar10 + 0x28);
  }
  *(float *)(param_1 + 0x520) = fVar16;
  *(undefined4 *)(param_1 + 0x454) = *(undefined4 *)(lVar10 + 0x3c);
  fVar14 = *(float *)(lVar10 + 0x40);
  *(float *)(param_1 + 0x458) = fVar14;
  fVar14 = fVar14 * _DAT_14382ee8c;
  if (fVar14 <= _DAT_143830120) {
    fVar14 = _DAT_143830120;
  }
  *(float *)(param_1 + 0x45c) = fVar14;
  lVar9 = *(longlong *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x460) = *(undefined4 *)(lVar10 + 0x44);
  *(undefined1 *)(param_1 + 0x464) = 1;
  if (*(short *)(lVar9 + 0x88) == 0) {
    lVar9 = FUN_14167ab40(lVar9 + 0x58,0x146da9d90);
  }
  else {
    lVar9 = func_0x0001416799a0(lVar9 + 0x80);
  }
  puVar12 = (undefined4 *)(param_1 + 0x560);
  *(undefined8 *)(param_1 + 0x554) = *(undefined8 *)(param_1 + 0x418);
  *(undefined4 *)(param_1 + 0x55c) = *(undefined4 *)(param_1 + 0x420);
  *(undefined4 *)(param_1 + 0x568) = 0;
  afStackX_10[0] = 0.0;
  puVar20 = puVar12;
  FUN_141f2d8f0(*(undefined8 *)(lVar9 + 0x50),0x4453c00,0x73420c96,afStackX_10,puVar12);
  if (_DAT_14382e120 <= afStackX_10[0]) {
    uVar13 = *puVar12;
  }
  else {
    uVar13 = 0;
  }
  *puVar12 = uVar13;
  uVar6 = *(ushort *)(param_2 + 0x6c);
  if ((uVar6 & 1) != 0) {
    *puVar12 = *(undefined4 *)(param_2 + 0x58);
    uVar6 = *(ushort *)(param_2 + 0x6c);
  }
  if ((uVar6 >> 8 & 1) != 0) {
    *puVar12 = *(undefined4 *)(param_1 + 0x428);
  }
  afStack_120[2] = *(float *)(param_1 + 0x4c0);
  afStack_120[0] = *pfVar1;
  fVar14 = (float)((uint)afStack_120[2] & uVar24);
  afStack_120[1] = 0.0;
  if (fVar14 <= 0.0) {
    fVar14 = 0.0;
  }
  if (fVar14 <= (float)((uint)afStack_120[0] & uVar24)) {
    fVar14 = (float)((uint)afStack_120[0] & uVar24);
  }
  if (0.0 < fVar14) {
    afStack_120[2] = (fVar19 / fVar14) * afStack_120[2];
    afStack_120[0] = (fVar19 / fVar14) * afStack_120[0];
    fVar19 = fVar19 / SQRT(afStack_120[2] * afStack_120[2] + afStack_120[0] * afStack_120[0]);
    afStack_120[2] = fVar19 * afStack_120[2];
    afStack_120[0] = fVar19 * afStack_120[0];
  }
  fVar19 = (float)func_0x000141c59090(param_1 + 0x418,afStack_120);
  fVar19 = fVar19 * _DAT_143830124;
  lVar9 = *(longlong *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x570) = 0x3e99999a;
  *(undefined4 *)(param_1 + 0x56c) = 0;
  *(float *)(param_1 + 0x564) = fVar19;
  *(undefined4 *)(param_1 + 0x46c) = 0x3f800000;
  if (*(short *)(lVar9 + 0x88) == 0) {
    plVar11 = (longlong *)FUN_14167ab40(lVar9 + 0x58,0x146dabca0);
  }
  else {
    plVar11 = (longlong *)func_0x0001416799a0(lVar9 + 0x80);
  }
  (**(code **)(*plVar11 + 0x50))(plVar11,0x2000);
  lVar9 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar9 + 0x88) == 0) {
    lVar9 = FUN_14167ab40(lVar9 + 0x58,0x146dd8370);
  }
  else {
    lVar9 = func_0x0001416799a0(lVar9 + 0x80);
  }
  *(uint *)(lVar9 + 0x62c) = *(uint *)(lVar9 + 0x62c) | 1;
  lVar9 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar9 + 0x88) == 0) {
    uVar7 = FUN_14167ab40(lVar9 + 0x58,0x146dd6030);
  }
  else {
    uVar7 = func_0x0001416799a0(lVar9 + 0x80);
  }
  FUN_14090f7d0(uVar7);
  puVar12 = (undefined4 *)func_0x000141676900(param_1,auStackX_20);
  uVar24 = 0;
  uVar23 = (ulonglong)puVar22 & 0xffffffffffffff00;
  uVar21 = (ulonglong)puVar20 & 0xffffffff00000000;
  FUN_1416d5e80(0x147475690,0x4bda4014,*puVar12,0,uVar21,uVar23,0,0,1,0,0,0,0);
  uStack_138 = FUN_140ac2110;
  *(undefined8 *)(param_1 + 0x5e0) = 0;
  *(undefined4 *)(param_1 + 0x5dc) = 0;
  uStack_130 = 0;
  uStack_128 = 0;
  lStack_b8 = (ulonglong)uStack_124 << 0x20;
  uStack_c8 = 0x40ac2110;
  uStack_c4 = 1;
  uStack_c0 = 0;
  uStack_bc = 0;
  FUN_141676070(param_1,&uStack_c8,_DAT_1473c2658,0,uVar21 & 0xffffffff00000000,
                uVar23 & 0xffffffff00000000,1,1,1,uVar24 & 0xffffff00);
  return;
}


/* HeroStateSwingLocal_virtual_12 @ 0x140aba1f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_140aba1f0(longlong param_1)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  longlong *plVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  char cVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  longlong lVar13;
  char cVar14;
  undefined8 uVar15;
  undefined1 uVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  undefined4 auStackX_8 [2];
  undefined4 auStackX_10 [2];
  undefined8 *puVar21;
  undefined4 uVar23;
  ulonglong uVar22;
  longlong lStack_d8;
  undefined8 uStack_d0;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined1 auStack_c0 [24];
  undefined4 auStack_a8 [6];
  undefined4 uStack_90;
  undefined4 uStack_8c;
  
  lVar13 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar13 + 0x88) == 0) {
    lVar13 = FUN_14167ab40(lVar13 + 0x58,0x146da9d90);
  }
  else {
    lVar13 = func_0x0001416799a0(lVar13 + 0x80);
  }
  lStack_d8 = *(longlong *)(lVar13 + 0x50);
  uStack_c4 = 0xcd07a28;
  uStack_c8 = 0;
  uStack_d0 = 0;
  if ((((lStack_d8 != 0) && (lVar13 = FUN_14169a690(lStack_d8,&lStack_d8), lVar13 != 0)) &&
      (fVar17 = (float)FUN_141697fa0(lStack_d8,lVar13), _DAT_14385a0a0 <= fVar17)) ||
     (*(char *)(param_1 + 0x5f0) != '\0')) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  cVar8 = FUN_14098fc80(*(undefined8 *)(param_1 + 0x108));
  if (cVar8 != '\0') {
    cVar8 = func_0x00014098fc70(*(undefined8 *)(param_1 + 0x108));
    if ((cVar8 == '\0') && (*(char *)(param_1 + 0x5f0) == '\0')) {
      bVar7 = true;
    }
    else {
      bVar7 = false;
    }
  }
  fVar17 = (float)FUN_1420dc660(param_1);
  if ((fVar17 <= _DAT_14382e124) || (*(char *)(param_1 + 0x5f1) == '\0')) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  cVar8 = FUN_140b91970(param_1 + 0x120);
  if ((cVar8 == '\0') || (bVar6)) {
    iVar10 = FUN_140ac2200(param_1);
    cVar8 = '\0';
    if (!bVar6) goto LAB_140aba31b;
  }
  else {
    cVar8 = '\x01';
    iVar10 = FUN_140ac2200(param_1);
LAB_140aba31b:
    if (iVar10 != 1) {
      cVar14 = '\0';
      goto LAB_140aba328;
    }
  }
  cVar14 = '\x01';
LAB_140aba328:
  if ((bVar7) || (iVar10 == 2)) {
    bVar7 = true;
  }
  else {
    bVar7 = false;
  }
  uVar16 = iVar10 == 2;
  bVar6 = true;
  auStackX_8[0] = CONCAT31(auStackX_8[0]._1_3_,uVar16);
  if ((((iVar10 == 0) && (bVar7)) && (cVar14 == '\0')) &&
     ((cVar8 == '\0' &&
      (cVar9 = *(char *)(param_1 + 0x5fb), *(char *)(param_1 + 0x5fb) = cVar9 + -1, '\0' < cVar9))))
  {
    bVar6 = false;
  }
  plVar5 = *(longlong **)(param_1 + 0x108);
  if ((*(byte *)((longlong)plVar5 + 0x157) & 1) != 0) {
    bVar7 = true;
    bVar6 = true;
  }
  if ((((*(char *)(param_1 + 0x580) == '\x03') ||
       ((fVar17 = (float)FUN_1402c2450(param_1 + 0x4b8), fVar17 <= _DAT_143830120 &&
        (*(float *)(param_1 + 0x424) <= _DAT_14382ee88)))) ||
      (cVar9 = (**(code **)(*plVar5 + 0x3e0))(plVar5,0x100,0,0), cVar9 == '\0')) &&
     (cVar9 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x308))
                        (*(longlong **)(param_1 + 0x108),1,1,0), cVar9 == '\0')) {
    fVar17 = (float)FUN_140876340(param_1 + 0x4d0);
    fVar18 = (float)FUN_1420dc660(param_1);
    uVar12 = _DAT_14382e160;
    if ((fVar18 < _DAT_143839a5c) ||
       ((*(int *)(param_1 + 0x574) == 0 &&
        (_DAT_1438388cc < (float)((uint)(fVar17 * _DAT_143830124) & _DAT_14382e160))))) {
      uVar15 = 1;
    }
    else {
      uVar15 = 0;
    }
    cVar9 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x2c8))
                      (*(longlong **)(param_1 + 0x108),uVar15);
    if (cVar9 == '\0') {
      fVar20 = 0.0;
      fVar17 = (float)((uint)*(float *)(param_1 + 0x4b8) & uVar12);
      fVar18 = (float)((uint)*(float *)(param_1 + 0x4c0) & uVar12);
      if (fVar17 <= fVar18) {
        fVar17 = fVar18;
      }
      fVar19 = *(float *)(param_1 + 0x4b8) * (_DAT_14382dce0 / fVar17);
      fVar18 = *(float *)(param_1 + 0x4c0) * (_DAT_14382dce0 / fVar17);
      if (0.0 < fVar17) {
        fVar20 = SQRT(fVar18 * fVar18 + fVar19 * fVar19) * fVar17;
      }
      cVar9 = func_0x000140b8fcf0(param_1 + 0x120,auStack_c0);
      if ((((cVar9 == '\0') || (fVar20 <= _DAT_14382f0e0)) ||
          (cVar9 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x488))
                             (*(longlong **)(param_1 + 0x108),param_1 + 0x4b8,auStack_c0),
          cVar9 == '\0')) &&
         (((cVar9 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x2f0))
                              (*(longlong **)(param_1 + 0x108),0), cVar9 == '\0' &&
           (cVar9 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x2e0))
                              (*(longlong **)(param_1 + 0x108),0), cVar9 == '\0')) &&
          ((fVar17 = (float)FUN_1420dc660(param_1), _DAT_14382ee8c <= fVar17 ||
           (cVar9 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x2a0))
                              (*(longlong **)(param_1 + 0x108),0,0), cVar9 == '\0')))))) {
        fVar17 = (float)FUN_1420dc660(param_1);
        if ((*(float *)(param_1 + 0x450) <= fVar17 && fVar17 != *(float *)(param_1 + 0x450)) &&
           ((((bVar7 || (cVar14 != '\0')) || (cVar8 != '\0')) && (bVar6)))) {
          lVar13 = *(longlong *)(param_1 + 8);
          if (*(short *)(lVar13 + 0x88) == 0) {
            lVar13 = FUN_14167ab40(lVar13 + 0x58,0x146df2690);
          }
          else {
            lVar13 = func_0x0001416799a0(lVar13 + 0x80);
          }
          cVar9 = *(char *)(lVar13 + 0x282);
          puVar1 = (undefined4 *)(param_1 + 0x53c);
          uVar4 = *(undefined1 *)(lVar13 + 0x281);
          puVar2 = (undefined8 *)(param_1 + 0x540);
          puVar21 = puVar2;
          FUN_140ac1680(param_1,cVar14,cVar8,uVar16,puVar2,puVar1,auStackX_10);
          uVar15 = CONCAT44((int)((ulonglong)puVar21 >> 0x20),*puVar1);
          uVar11 = FUN_140ac0ff0(param_1,cVar14,cVar8,puVar2,uVar15);
          uVar23 = (undefined4)((ulonglong)uVar15 >> 0x20);
          *(char *)(param_1 + 0x538) = cVar14;
          uVar12 = func_0x000141bbb790();
          *(byte *)(param_1 + 0x53a) = ~(byte)(uVar12 >> 0xf) & 1;
          if (cVar9 == '\0') {
            *(undefined1 *)(param_1 + 0x53a) = uVar4;
          }
          uStack_8c = auStackX_10[0];
          if ((byte)(*(char *)(param_1 + 0x580) - 2U) < 2) {
            uVar11 = 0xaa782917;
            *puVar2 = CONCAT44(_DAT_14384e300,_DAT_143854908);
            uStack_d0 = CONCAT44(uStack_d0._4_4_,0x80000000);
            *(undefined4 *)(param_1 + 0x548) = 0x80000000;
            uStack_8c = FUN_14085fbb0(*(undefined8 *)(param_1 + 8));
            *puVar1 = uStack_8c;
          }
          func_0x0001408687b0(auStack_a8);
          uStack_90 = *puVar1;
          auStack_a8[0] = uVar11;
          cVar9 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x290))
                            (*(longlong **)(param_1 + 0x108),puVar2,auStack_a8,0xff,
                             CONCAT44(uVar23,-(uint)(*(char *)(param_1 + 0x53a) != '\0')) &
                             0xffffffff00000400);
          if (cVar9 != '\0') {
            return 1;
          }
          uVar16 = (undefined1)auStackX_8[0];
        }
        uVar3 = param_1 + 0x540;
        uVar22 = uVar3;
        FUN_140ac1680(param_1,cVar14,cVar8,uVar16,uVar3,auStackX_8,auStackX_10);
        cVar8 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x158))
                          (*(longlong **)(param_1 + 0x108),uVar3,auStackX_8[0]);
        if (((cVar8 == '\0') &&
            (cVar8 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x160))
                               (*(longlong **)(param_1 + 0x108),0,1), cVar8 == '\0')) &&
           (cVar8 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x2f8))(), cVar8 == '\0')) {
          lVar13 = func_0x0001409c87f0(param_1);
          fVar17 = *(float *)(lVar13 + 0x1b8);
          if ((_DAT_143830128 < fVar17) || (fVar17 < 0.0)) {
            uVar15 = 0;
          }
          else {
            uVar15 = 0x6b0e4660;
            if (fVar17 < _DAT_1438794d0) {
              uVar15 = 0xd865fadc;
            }
          }
          cVar8 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x2c0))
                            (*(longlong **)(param_1 + 0x108),0,uVar15);
          if (((cVar8 == '\0') &&
              (cVar8 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x2e8))
                                 (*(longlong **)(param_1 + 0x108),0,0), cVar8 == '\0')) &&
             (cVar8 = (**(code **)(**(longlong **)(param_1 + 0x108) + 200))
                                (*(longlong **)(param_1 + 0x108),_DAT_143837a20,0,0,
                                 uVar22 & 0xffffffff00000000,0,0,_DAT_14382e13c,0xffffffff),
             cVar8 == '\0')) {
            return 0;
          }
        }
      }
    }
  }
  return 1;
}


/* HeroStateSwingLocal_virtual_14 @ 0x1409c8540 */

undefined1 HeroStateSwingLocal_virtual_14(void)

{
  return 1;
}


/* HeroStateSwingLocal_virtual_15 @ 0x1409c8750 */

undefined1 HeroStateSwingLocal_virtual_15(void)

{
  return 0;
}


/* HeroStateSwingLocal_virtual_16 @ 0x1409c8760 */

undefined8 HeroStateSwingLocal_virtual_16(void)

{
  return 0x140;
}


/* HeroStateSwing_virtual_1 @ 0x140ab2ad0 */

/* WARNING: Removing unreachable block (ram,0x000141676787) */
/* WARNING: Removing unreachable block (ram,0x000141676791) */
/* WARNING: Removing unreachable block (ram,0x0001416767c3) */
/* WARNING: Removing unreachable block (ram,0x0001416767d0) */
/* WARNING: Removing unreachable block (ram,0x0001416767e6) */
/* WARNING: Removing unreachable block (ram,0x0001416767f0) */
/* WARNING: Removing unreachable block (ram,0x000141676801) */
/* WARNING: Removing unreachable block (ram,0x000141676811) */
/* WARNING: Removing unreachable block (ram,0x000141676809) */
/* WARNING: Removing unreachable block (ram,0x00014167680f) */
/* WARNING: Removing unreachable block (ram,0x00014167681e) */

void HeroStateSwing_virtual_1(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    (**(code **)(*param_1 + 0x40))();
    *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) & 0xfe;
    if (((int)param_1[7] != 0) && ((*(ushort *)(param_1[1] + 8) >> 0xd & 1) != 0)) {
      FUN_14167d120(0x147a43720,param_1,(int)param_1[7],*(undefined2 *)(param_1[1] + 0x18));
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  if ((*(ushort *)(param_1[1] + 8) >> 10 & 1) == 0) {
    lVar3 = FUN_141984370(param_1 + 3);
    if (lVar3 != 0) {
      func_0x000141984600(lVar3);
    }
    FUN_14159e150(param_1[1],param_1);
    FUN_1416793a0(0x146046060,param_1);
    lVar3 = func_0x0001416798f0((longlong)param_1 + 0x3c);
    if (lVar3 != 0) {
      *(char *)(lVar3 + 0x1c) = *(char *)(lVar3 + 0x1c) + -1;
    }
  }
  *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) | 2;
  FUN_14190fa90(0x147a42f80,(longlong)param_1 + 0x14);
  plVar2 = (longlong *)param_1[8];
  if (plVar2 != (longlong *)0x0) {
    plVar1 = plVar2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    if ((int)*plVar1 == 0) {
      (**(code **)(*plVar2 + 0x50))(plVar2[2]);
      *plVar2 = 0;
      plVar2[2] = 0;
      func_0x000141757470(plVar2);
    }
    param_1[8] = 0;
  }
  return;
}


/* HeroStateSwing_virtual_2 @ 0x140ab2ae0 */

/* WARNING: Removing unreachable block (ram,0x000141676787) */
/* WARNING: Removing unreachable block (ram,0x000141676791) */
/* WARNING: Removing unreachable block (ram,0x0001416767c3) */
/* WARNING: Removing unreachable block (ram,0x0001416767d0) */
/* WARNING: Removing unreachable block (ram,0x0001416767e6) */
/* WARNING: Removing unreachable block (ram,0x0001416767f0) */
/* WARNING: Removing unreachable block (ram,0x000141676801) */
/* WARNING: Removing unreachable block (ram,0x000141676811) */
/* WARNING: Removing unreachable block (ram,0x000141676809) */
/* WARNING: Removing unreachable block (ram,0x00014167680f) */
/* WARNING: Removing unreachable block (ram,0x00014167681e) */

void HeroStateSwing_virtual_2(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    (**(code **)(*param_1 + 0x40))();
    *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) & 0xfe;
    if (((int)param_1[7] != 0) && ((*(ushort *)(param_1[1] + 8) >> 0xd & 1) != 0)) {
      FUN_14167d120(0x147a43720,param_1,(int)param_1[7],*(undefined2 *)(param_1[1] + 0x18));
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  if ((*(ushort *)(param_1[1] + 8) >> 10 & 1) == 0) {
    lVar3 = FUN_141984370(param_1 + 3);
    if (lVar3 != 0) {
      func_0x000141984600(lVar3);
    }
    FUN_14159e150(param_1[1],param_1);
    FUN_1416793a0(0x146046060,param_1);
    lVar3 = func_0x0001416798f0((longlong)param_1 + 0x3c);
    if (lVar3 != 0) {
      *(char *)(lVar3 + 0x1c) = *(char *)(lVar3 + 0x1c) + -1;
    }
  }
  *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) | 2;
  FUN_14190fa90(0x147a42f80,(longlong)param_1 + 0x14);
  plVar2 = (longlong *)param_1[8];
  if (plVar2 != (longlong *)0x0) {
    plVar1 = plVar2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    if ((int)*plVar1 == 0) {
      (**(code **)(*plVar2 + 0x50))(plVar2[2]);
      *plVar2 = 0;
      plVar2[2] = 0;
      func_0x000141757470(plVar2);
    }
    param_1[8] = 0;
  }
  return;
}


/* HeroStateSwing_virtual_9 @ 0x140ab2ac0 */

undefined8 HeroStateSwing_virtual_9(void)

{
  return 0x146df2690;
}


/* HeroStateSwing_virtual_10 @ 0x1409c7550 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1409c7550(longlong param_1)

{
  uint uStack_34;
  code *pcStack_28;
  undefined8 uStack_20;
  longlong lStack_18;
  
  func_0x0001420dc400();
  lStack_18 = (ulonglong)uStack_34 << 0x20;
  pcStack_28 = FUN_1409c79b0;
  uStack_20 = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  FUN_141676070(param_1,&pcStack_28,_DAT_1473a5038,0,0,0,1,1,1,0);
  return;
}


/* HeroStateSwing_virtual_11 @ 0x140ab2af0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab2af0(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined8 uVar13;
  byte bVar14;
  undefined8 *puVar15;
  float *pfVar16;
  undefined4 uVar17;
  undefined1 auStackX_8 [8];
  code *pcStack_c8;
  undefined8 uStack_c0;
  undefined4 uStack_b8;
  uint uStack_b4;
  code *pcStack_a8;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  longlong lStack_98;
  undefined8 uStack_88;
  undefined4 uStack_80;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  
  func_0x0001420dc410();
  puVar9 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
  uVar17 = *puVar9;
  *(byte *)(param_1 + 0xf2) = *(byte *)(param_1 + 0xf2) & 0xf9;
  *(byte *)(param_1 + 0xf2) = *(byte *)(param_1 + 0xf2) | 8;
  *(undefined4 *)(param_1 + 0xf8) = uVar17;
  *(undefined8 *)(param_1 + 0x15c) = *(undefined8 *)(param_2 + 0x24);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined8 *)(param_1 + 0x168) = *(undefined8 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_2 + 0x38);
  *(undefined8 *)(param_1 + 0x150) = *(undefined8 *)(param_1 + 0x15c);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_1 + 0x164);
  iVar5 = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined8 *)(param_1 + 0x230) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x244) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x240) = 0;
  *(undefined8 *)(param_1 + 0x248) = 0x3f000000;
  *(undefined8 *)(param_1 + 600) = 0x3f000000;
  *(undefined8 *)(param_1 + 0x260) = 0x3f000000;
  *(undefined8 *)(param_1 + 0x268) = 0x3f000000;
  *(undefined8 *)(param_1 + 0x250) = 0x3f000000;
  *(undefined4 *)(param_1 + 500) = 0x7149f2ca;
  *(undefined4 *)(param_1 + 0x1f0) = 0x7149f2ca;
  *(undefined4 *)(param_1 + 0x27c) = 0x7149f2ca;
  *(undefined4 *)(param_1 + 0x278) = 0x7149f2ca;
  *(undefined4 *)(param_1 + 0x270) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(undefined1 *)(param_1 + 0x274) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0x7149f2ca;
  *(undefined4 *)(param_1 + 0x1c0) = 0x7149f2ca;
  *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_2 + 0x44);
  *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_2 + 0x48);
  *(undefined4 *)(param_1 + 0x188) = *(undefined4 *)(param_2 + 0x4c);
  *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_2 + 0x50);
  *(byte *)(param_1 + 400) = *(byte *)(param_2 + 0x6c) >> 5 & 1;
  bVar14 = *(byte *)(param_2 + 0x6c) >> 4 & 1;
  *(byte *)(param_1 + 0x284) = bVar14;
  *(byte *)(param_1 + 0x28a) = *(byte *)(param_2 + 0x6c) >> 6 & 1;
  *(byte *)(param_1 + 0x1fd) = *(byte *)(param_2 + 0x6c) >> 7;
  uVar17 = _DAT_14383fd4c;
  if (bVar14 != 0) {
    uVar17 = _DAT_14382e13c;
  }
  *(undefined4 *)(param_1 + 0x100) = uVar17;
  if (DAT_146df2612 != '\0') {
    *(undefined8 *)(param_1 + 0x178) = 0;
    *(undefined8 *)(param_1 + 0x180) = 0;
    *(undefined8 *)(param_1 + 0x188) = 0;
    *(undefined1 *)(param_1 + 400) = 0;
  }
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined8 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1c4) = 0x7149f2ca;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined1 *)(param_1 + 0x28b) = 1;
  *(undefined4 *)(param_1 + 0x1c8) = 0x7149f2ca;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined8 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x1e8) = 0xbf800000;
  *(undefined2 *)(param_1 + 0x211) = 0;
  *(undefined2 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x289) = 1;
  *(undefined1 *)(param_1 + 0x210) = 0;
  *(undefined2 *)(param_1 + 0x285) = 0;
  *(undefined1 *)(param_1 + 0x287) = 0;
  FUN_1420df1c0(param_1 + 0xf0,0);
  plVar10 = *(longlong **)(param_1 + 8);
  puVar15 = (undefined8 *)0x147afdf10;
  if ((undefined8 *)*plVar10 != (undefined8 *)0x0) {
    puVar15 = (undefined8 *)*plVar10;
  }
  uVar13 = puVar15[1];
  *(undefined8 *)(param_1 + 0x104) = *puVar15;
  *(undefined8 *)(param_1 + 0x10c) = uVar13;
  uVar13 = puVar15[3];
  *(undefined8 *)(param_1 + 0x114) = puVar15[2];
  *(undefined8 *)(param_1 + 0x11c) = uVar13;
  uVar17 = *(undefined4 *)((longlong)puVar15 + 0x24);
  uVar2 = *(undefined4 *)(puVar15 + 5);
  uVar3 = *(undefined4 *)((longlong)puVar15 + 0x2c);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(puVar15 + 4);
  *(undefined4 *)(param_1 + 0x128) = uVar17;
  *(undefined4 *)(param_1 + 300) = uVar2;
  *(undefined4 *)(param_1 + 0x130) = uVar3;
  uVar17 = *(undefined4 *)((longlong)puVar15 + 0x34);
  uVar2 = *(undefined4 *)(puVar15 + 7);
  uVar3 = *(undefined4 *)((longlong)puVar15 + 0x3c);
  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(puVar15 + 6);
  *(undefined4 *)(param_1 + 0x138) = uVar17;
  *(undefined4 *)(param_1 + 0x13c) = uVar2;
  *(undefined4 *)(param_1 + 0x140) = uVar3;
  if ((short)plVar10[0x11] == 0) {
    plVar10 = (longlong *)FUN_14167ab40(plVar10 + 0xb,0x147c40bf0);
  }
  else {
    plVar10 = (longlong *)func_0x0001416799a0(plVar10 + 0x10,0x147c40bf0);
  }
  puVar11 = (undefined8 *)(**(code **)(*plVar10 + 0x80))(plVar10,&pcStack_c8,0);
  puVar15 = (undefined8 *)(param_1 + 0x214);
  *puVar15 = *puVar11;
  *(undefined4 *)(param_1 + 0x21c) = *(undefined4 *)(puVar11 + 1);
  if ((*(byte *)(param_2 + 0x6c) & 2) != 0) {
    *puVar15 = *(undefined8 *)(param_2 + 0x5c);
    *(undefined4 *)(param_1 + 0x21c) = *(undefined4 *)(param_2 + 100);
  }
  *(undefined8 *)(param_1 + 0x144) = *puVar15;
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x21c);
  *(bool *)(param_1 + 0x280) = 0.0 < *(float *)(param_1 + 0x218);
  puVar11 = (undefined8 *)FUN_140ab40c0(param_1,&pcStack_c8,puVar15,1);
  plVar1 = *(longlong **)(param_1 + 8);
  *(undefined8 *)(param_1 + 0x220) = *puVar11;
  *(undefined4 *)(param_1 + 0x228) = *(undefined4 *)(puVar11 + 1);
  pfVar16 = (float *)0x147afdf10;
  if ((float *)*plVar1 != (float *)0x0) {
    pfVar16 = (float *)*plVar1;
  }
  fStack_78 = *pfVar16;
  fStack_74 = pfVar16[1];
  fStack_70 = pfVar16[2];
  fStack_6c = pfVar16[3];
  fStack_48 = pfVar16[0xc];
  fStack_44 = pfVar16[0xd];
  fStack_40 = pfVar16[0xe];
  fStack_3c = pfVar16[0xf];
  if ((short)plVar1[0x11] == 0) {
    lVar12 = FUN_14167ab40(plVar1 + 0xb,0x146dacd70);
  }
  else {
    lVar12 = func_0x0001416799a0(plVar1 + 0x10);
  }
  pcStack_c8 = *(code **)(param_1 + 0x168);
  pcStack_a8 = *(code **)(param_1 + 0x134);
  uStack_c0 = CONCAT44(uStack_c0._4_4_,*(undefined4 *)(param_1 + 0x170));
  uStack_a0 = *(undefined4 *)(param_1 + 0x13c);
  uStack_88 = *puVar15;
  uStack_80 = *(undefined4 *)(param_1 + 0x21c);
  uVar17 = FUN_140ab38e0(lVar12 + 0x410,&pcStack_c8,&pcStack_a8,&uStack_88);
  *(undefined4 *)(param_1 + 0x22c) = uVar17;
  bVar4 = 0.0 < (*(float *)(param_1 + 0x170) - fStack_40) * fStack_70 +
                (*(float *)(param_1 + 0x168) - fStack_48) * fStack_78;
  *(bool *)(param_1 + 0x281) = bVar4;
  if (DAT_146df2615 != '\0') {
    bVar4 = !bVar4;
  }
  lVar12 = *(longlong *)(param_1 + 8);
  *(bool *)(param_1 + 0x281) = bVar4;
  *(undefined4 *)(param_1 + 0x100) = 0x3eb33333;
  if (*(short *)(lVar12 + 0x88) == 0) {
    uVar13 = FUN_14167ab40(lVar12 + 0x58,0x1473d09e0);
  }
  else {
    uVar13 = func_0x0001416799a0(lVar12 + 0x80);
  }
  FUN_1415bf500(uVar13,0);
  FUN_1415bf500(uVar13,1);
  if (_DAT_146df261c != 0) {
    iVar5 = _DAT_146df261c + -1;
  }
  iVar8 = 0;
  iVar6 = iVar8;
  if (_DAT_146df2630 != 0) {
    iVar6 = _DAT_146df2630 + -1;
  }
  iVar7 = iVar8;
  if (_DAT_146df2634 != 0) {
    iVar7 = _DAT_146df2634 + -1;
  }
  if (_DAT_146df2638 != 0) {
    iVar8 = _DAT_146df2638 + -1;
  }
  _DAT_146df261c = iVar5;
  _DAT_146df2630 = iVar6;
  _DAT_146df2634 = iVar7;
  _DAT_146df2638 = iVar8;
  FUN_140ab5e60(param_1,0,uVar13);
  FUN_140ab4cc0(param_1);
  uVar3 = _DAT_1438ce984;
  uVar2 = _DAT_1438ce97c;
  uVar17 = _DAT_1438ce968;
  _DAT_146df263c = _DAT_146df263c + 1;
  *(uint *)(plVar10 + 0xea) = *(uint *)(plVar10 + 0xea) | 0xa0;
  *(uint *)((longlong)plVar10 + 0x144) = *(uint *)((longlong)plVar10 + 0x144) | 0x10;
  func_0x000141fc3540(plVar10,uVar2,uVar3,uVar17);
  FUN_141fcc7b0(*(undefined8 *)(param_1 + 8),1);
  uVar13 = func_0x000141fc2460(plVar10);
  FUN_141fde3f0(uVar13);
  uVar13 = func_0x000141fc2460(plVar10);
  func_0x000141fde440(uVar13);
  lVar12 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar12 + 0x88) == 0) {
    plVar10 = (longlong *)FUN_14167ab40(lVar12 + 0x58,0x146dabca0);
  }
  else {
    plVar10 = (longlong *)func_0x0001416799a0(lVar12 + 0x80);
  }
  (**(code **)(*plVar10 + 0x50))(plVar10,0x2000);
  lVar12 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar12 + 0x88) == 0) {
    lVar12 = FUN_14167ab40(lVar12 + 0x58,0x146d11880);
  }
  else {
    lVar12 = func_0x0001416799a0(lVar12 + 0x80);
  }
  if (lVar12 != 0) {
    FUN_14030d190(lVar12,100);
  }
  pcStack_c8 = (code *)&UNK_140ab4b70;
  uStack_c0 = 0;
  uStack_b8 = 0;
  lStack_98 = (ulonglong)uStack_b4 << 0x20;
  pcStack_a8 = (code *)&UNK_140ab4b70;
  uStack_a0 = 0;
  uStack_9c = 0;
  FUN_141676070(param_1,&pcStack_a8,_DAT_1473a5310,0,0,0,1,1,1,0);
  pcStack_c8 = (code *)&UNK_140ab4b60;
  uStack_c0 = 0;
  uStack_b8 = 0;
  lStack_98 = (ulonglong)uStack_b4 << 0x20;
  pcStack_a8 = (code *)&UNK_140ab4b60;
  uStack_a0 = 0;
  uStack_9c = 0;
  FUN_141676070(param_1,&pcStack_a8,_DAT_1473c2668,0,0,0,1,1,1,0);
  pcStack_c8 = FUN_140ab4a70;
  uStack_c0 = 0;
  uStack_b8 = 0;
  lStack_98 = (ulonglong)uStack_b4 << 0x20;
  pcStack_a8 = FUN_140ab4a70;
  uStack_a0 = 0;
  uStack_9c = 0;
  FUN_141676070(param_1,&pcStack_a8,_DAT_1473c2670,0,0,0,1,1,1,0);
  pcStack_c8 = FUN_140ab4ac0;
  uStack_c0 = 0;
  uStack_b8 = 0;
  lStack_98 = (ulonglong)uStack_b4 << 0x20;
  pcStack_a8 = FUN_140ab4ac0;
  uStack_a0 = 0;
  uStack_9c = 0;
  FUN_141676070(param_1,&pcStack_a8,_DAT_1473c2678,0,0,0,1,1,1,0);
  return;
}


/* HeroStateSwing_virtual_12 @ 0x1409c7740 */

undefined1 HeroStateSwing_virtual_12(void)

{
  return 0;
}


/* HeroStateSwing_virtual_14 @ 0x140ab3280 */

void FUN_140ab3280(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 *puVar3;
  char acStackX_10 [8];
  
  lVar1 = *param_2;
  lVar2 = FUN_141f9e890(&UNK_1438ce748);
  if (lVar1 == lVar2) {
    puVar3 = (undefined1 *)FUN_141bcf3e0(lVar1 + 0x10,0x44d96bd9);
    if (puVar3 != (undefined1 *)0x0) {
      FUN_141f9db60(param_2,*puVar3,param_1 + 0x214,0xc);
    }
    puVar3 = (undefined1 *)FUN_141bcf3e0(*param_2 + 0x10,0x5becae87);
    if (puVar3 != (undefined1 *)0x0) {
      FUN_141f9db60(param_2,*puVar3,param_1 + 0x230,4);
    }
    puVar3 = (undefined1 *)FUN_141bcf3e0(*param_2 + 0x10,0x25f068d0);
    if (puVar3 != (undefined1 *)0x0) {
      FUN_141f9db60(param_2,*puVar3,param_1 + 0x220,0xc);
    }
    acStackX_10[0] = '\0';
    puVar3 = (undefined1 *)FUN_141bcf3e0(*param_2 + 0x10,0x7a248ff0);
    if (puVar3 != (undefined1 *)0x0) {
      FUN_141f9db60(param_2,*puVar3,acStackX_10,1);
    }
    FUN_1420dd4f0(param_1,param_2,acStackX_10[0] != '\0');
  }
  return;
}


/* HeroStateSwing_virtual_15 @ 0x1409c77b0 */

undefined1 HeroStateSwing_virtual_15(void)

{
  return 0;
}


/* HeroStateSwing_virtual_16 @ 0x1409c77c0 */

undefined1 HeroStateSwing_virtual_16(void)

{
  return 0;
}


/* HeroStateSwing_virtual_17 @ 0x1409c77d0 */

void HeroStateSwing_virtual_17(void)

{
  return;
}


/* HeroStateSwingJumpLocal_virtual_1 @ 0x140afc9e0 */

/* WARNING: Removing unreachable block (ram,0x000141676787) */
/* WARNING: Removing unreachable block (ram,0x000141676791) */
/* WARNING: Removing unreachable block (ram,0x0001416767c3) */
/* WARNING: Removing unreachable block (ram,0x0001416767d0) */
/* WARNING: Removing unreachable block (ram,0x0001416767e6) */
/* WARNING: Removing unreachable block (ram,0x0001416767f0) */
/* WARNING: Removing unreachable block (ram,0x000141676801) */
/* WARNING: Removing unreachable block (ram,0x000141676811) */
/* WARNING: Removing unreachable block (ram,0x000141676809) */
/* WARNING: Removing unreachable block (ram,0x00014167680f) */
/* WARNING: Removing unreachable block (ram,0x00014167681e) */

void HeroStateSwingJumpLocal_virtual_1(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    (**(code **)(*param_1 + 0x40))();
    *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) & 0xfe;
    if (((int)param_1[7] != 0) && ((*(ushort *)(param_1[1] + 8) >> 0xd & 1) != 0)) {
      FUN_14167d120(0x147a43720,param_1,(int)param_1[7],*(undefined2 *)(param_1[1] + 0x18));
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  if ((*(ushort *)(param_1[1] + 8) >> 10 & 1) == 0) {
    lVar3 = FUN_141984370(param_1 + 3);
    if (lVar3 != 0) {
      func_0x000141984600(lVar3);
    }
    FUN_14159e150(param_1[1],param_1);
    FUN_1416793a0(0x146046060,param_1);
    lVar3 = func_0x0001416798f0((longlong)param_1 + 0x3c);
    if (lVar3 != 0) {
      *(char *)(lVar3 + 0x1c) = *(char *)(lVar3 + 0x1c) + -1;
    }
  }
  *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) | 2;
  FUN_14190fa90(0x147a42f80,(longlong)param_1 + 0x14);
  plVar2 = (longlong *)param_1[8];
  if (plVar2 != (longlong *)0x0) {
    plVar1 = plVar2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    if ((int)*plVar1 == 0) {
      (**(code **)(*plVar2 + 0x50))(plVar2[2]);
      *plVar2 = 0;
      plVar2[2] = 0;
      func_0x000141757470(plVar2);
    }
    param_1[8] = 0;
  }
  return;
}


/* HeroStateSwingJumpLocal_virtual_2 @ 0x140afc9f0 */

/* WARNING: Removing unreachable block (ram,0x000141676787) */
/* WARNING: Removing unreachable block (ram,0x000141676791) */
/* WARNING: Removing unreachable block (ram,0x0001416767c3) */
/* WARNING: Removing unreachable block (ram,0x0001416767d0) */
/* WARNING: Removing unreachable block (ram,0x0001416767e6) */
/* WARNING: Removing unreachable block (ram,0x0001416767f0) */
/* WARNING: Removing unreachable block (ram,0x000141676801) */
/* WARNING: Removing unreachable block (ram,0x000141676811) */
/* WARNING: Removing unreachable block (ram,0x000141676809) */
/* WARNING: Removing unreachable block (ram,0x00014167680f) */
/* WARNING: Removing unreachable block (ram,0x00014167681e) */

void HeroStateSwingJumpLocal_virtual_2(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    (**(code **)(*param_1 + 0x40))();
    *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) & 0xfe;
    if (((int)param_1[7] != 0) && ((*(ushort *)(param_1[1] + 8) >> 0xd & 1) != 0)) {
      FUN_14167d120(0x147a43720,param_1,(int)param_1[7],*(undefined2 *)(param_1[1] + 0x18));
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  if ((*(ushort *)(param_1[1] + 8) >> 10 & 1) == 0) {
    lVar3 = FUN_141984370(param_1 + 3);
    if (lVar3 != 0) {
      func_0x000141984600(lVar3);
    }
    FUN_14159e150(param_1[1],param_1);
    FUN_1416793a0(0x146046060,param_1);
    lVar3 = func_0x0001416798f0((longlong)param_1 + 0x3c);
    if (lVar3 != 0) {
      *(char *)(lVar3 + 0x1c) = *(char *)(lVar3 + 0x1c) + -1;
    }
  }
  *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) | 2;
  FUN_14190fa90(0x147a42f80,(longlong)param_1 + 0x14);
  plVar2 = (longlong *)param_1[8];
  if (plVar2 != (longlong *)0x0) {
    plVar1 = plVar2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    if ((int)*plVar1 == 0) {
      (**(code **)(*plVar2 + 0x50))(plVar2[2]);
      *plVar2 = 0;
      plVar2[2] = 0;
      func_0x000141757470(plVar2);
    }
    param_1[8] = 0;
  }
  return;
}


/* HeroStateSwingJumpLocal_virtual_9 @ 0x140afc9d0 */

undefined8 HeroStateSwingJumpLocal_virtual_9(void)

{
  return 0x146dfa980;
}


/* HeroStateSwingJumpLocal_virtual_10 @ 0x140a85f70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140a85f70(longlong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uStack_44;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  longlong lStack_28;
  
  func_0x000140a7e4f0();
  *(undefined1 *)(param_1 + 0x120) = 0;
  *(undefined8 *)(param_1 + 0x13c) = 0;
  *(undefined8 *)(param_1 + 0x154) = 0;
  *(undefined8 *)(param_1 + 0x160) = 0;
  *(undefined8 *)(param_1 + 0x16c) = 0;
  *(undefined8 *)(param_1 + 0x178) = 0;
  *(undefined8 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined8 *)(param_1 + 0x1e0) = 0;
  *(undefined8 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined2 *)(param_1 + 0x2cd) = 0x100;
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  *(undefined2 *)(param_1 + 0x2d2) = 0;
  *(undefined2 *)(param_1 + 400) = 0;
  *(undefined2 *)(param_1 + 0x2db) = 0x100;
  *(undefined1 *)(param_1 + 0x228) = 0;
  *(undefined1 *)(param_1 + 0x2dd) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined8 *)(param_1 + 0x250) = 0;
  *(undefined4 *)(param_1 + 600) = 0;
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  *(undefined1 *)(param_1 + 0x2f9) = 0;
  *(undefined4 *)(param_1 + 0x2fc) = 0;
  *(undefined2 *)(param_1 + 0x2c8) = 0;
  *(undefined1 *)(param_1 + 0x24e) = 1;
  *(undefined4 *)(param_1 + 0x248) = 0;
  *(undefined1 *)(param_1 + 0x2d9) = 0;
  *(undefined4 *)(param_1 + 0x1fc) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x20c) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x210) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x218) = 0xbf800000;
  uVar2 = FUN_141f9e890(&UNK_1438c9b18);
  *(undefined8 *)(param_1 + 0xe8) = uVar2;
  uVar2 = FUN_141f9e890(&UNK_1438c77f0);
  lVar3 = *(longlong *)(param_1 + 8);
  *(undefined8 *)(param_1 + 0xf0) = uVar2;
  if (*(short *)(lVar3 + 0x88) == 0) {
    FUN_14167ab40(lVar3 + 0x58,0x146dabca0);
  }
  else {
    func_0x0001416799a0(lVar3 + 0x80);
  }
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dd84e0);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  *(undefined4 *)(lVar3 + 0x744) = 2;
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x1473d09e0);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  *(uint *)(lVar3 + 0x48) = *(uint *)(lVar3 + 0x48) & 0xfffffffd;
  lStack_28 = (ulonglong)uStack_44 << 0x20;
  uStack_38 = 0x40a8d360;
  uStack_34 = 1;
  uStack_30 = 0;
  uStack_2c = 0;
  FUN_141676070(param_1,&uStack_38,_DAT_1473b1da0,0,0,0,1,1,1,0);
  lVar3 = FUN_14159cb80(*(undefined8 *)(param_1 + 8),0x146dab570,0);
  *(undefined4 *)(param_1 + 0x278) = *(undefined4 *)(lVar3 + 0x14);
  *(undefined4 *)(param_1 + 0x2f0) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x2f4) = 0;
  *(undefined1 *)(param_1 + 0x2f8) = 1;
  puVar4 = (undefined8 *)FUN_141676930(param_1);
  *(undefined8 *)(param_1 + 0x148) = *puVar4;
  uVar1 = *(undefined4 *)(puVar4 + 1);
  *(undefined1 *)(param_1 + 0x2da) = 0;
  *(undefined4 *)(param_1 + 0x150) = uVar1;
  *(undefined4 *)(param_1 + 0x224) = 0xbdcccccd;
  return;
}


/* HeroStateSwingJumpLocal_virtual_11 @ 0x140afca00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_140a86490(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined *puVar7;
  longlong *plVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  float fVar11;
  float fVar12;
  undefined4 auStackX_8 [2];
  undefined8 uStack_98;
  uint uStack_90;
  float afStack_88 [2];
  float fStack_80;
  undefined1 auStack_78 [48];
  undefined8 uStack_48;
  undefined4 uStack_40;
  
  FUN_1420e0800();
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    plVar4 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x147c40bf0);
  }
  else {
    plVar4 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
  }
  FUN_1408bc0a0(param_1 + 0x27c,*(undefined8 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x68),
                *(char *)(param_2 + 0x84) != '\0',0);
  *(undefined1 *)(param_1 + 0x120) = *(undefined1 *)(param_2 + 0x80);
  *(byte *)(param_1 + 0x2cb) = ~(*(byte *)(param_2 + 0x83) >> 1) & 1;
  *(byte *)(param_1 + 0x2d1) = *(byte *)(param_2 + 0x83) & 1;
  *(byte *)(param_1 + 0x2cc) = ~(*(byte *)(param_2 + 0x83) >> 2) & 1;
  *(byte *)(param_1 + 0x2d6) = *(byte *)(param_2 + 0x83) >> 6 & 1;
  *(byte *)(param_1 + 0x2d7) = *(byte *)(param_2 + 0x83) >> 7;
  cVar3 = *(char *)(param_2 + 0x87);
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0x3f800000;
  *(undefined8 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined8 *)(param_1 + 0x1ac) = 0x3f800000;
  *(undefined8 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0x3f800000;
  *(bool *)(param_1 + 0x2d8) = cVar3 != '\0';
  *(undefined1 *)(param_1 + 0x2ca) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  *(undefined4 *)(param_1 + 0x220) = 0xf149f2ca;
  *(undefined4 *)(param_1 + 0x204) = 0xbf800000;
  *(undefined8 *)(param_1 + 0x154) = *(undefined8 *)(param_2 + 0x40);
  uVar10 = *(undefined4 *)(param_2 + 0x48);
  *(undefined4 *)(param_1 + 0x15c) = uVar10;
  *(undefined8 *)(param_1 + 0x160) = *(undefined8 *)(param_1 + 0x154);
  *(undefined4 *)(param_1 + 0x168) = uVar10;
  lVar5 = FUN_1402c48c0(*(undefined8 *)(param_1 + 8));
  fVar12 = *(float *)(lVar5 + 4);
  if (*(float *)(lVar5 + 4) <= *(float *)(param_2 + 0x70)) {
    fVar12 = *(float *)(param_2 + 0x70);
  }
  *(float *)(param_1 + 0x26c) = fVar12;
  puVar6 = (undefined8 *)func_0x000140a7d9e0(param_2,&uStack_98);
  uVar2 = _DAT_14382e160;
  fVar12 = _DAT_14382e118;
  puVar1 = (uint *)(param_1 + 0x124);
  *(undefined8 *)puVar1 = *puVar6;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(puVar6 + 1);
  if (((fVar12 < (float)(*puVar1 & uVar2)) || (fVar12 < (float)(*(uint *)(param_1 + 0x128) & uVar2))
      ) || (fVar12 < (float)(*(uint *)(param_1 + 300) & uVar2))) {
    puVar6 = (undefined8 *)FUN_1402d0740(&uStack_98,puVar1);
    *(undefined8 *)puVar1 = *puVar6;
    uVar10 = *(undefined4 *)(puVar6 + 1);
  }
  else {
    puVar7 = &DAT_147afdf10;
    if ((undefined *)**(undefined8 **)(param_1 + 8) != (undefined *)0x0) {
      puVar7 = (undefined *)**(undefined8 **)(param_1 + 8);
    }
    *(undefined8 *)puVar1 = *(undefined8 *)(puVar7 + 0x20);
    uVar10 = *(undefined4 *)(puVar7 + 0x28);
  }
  *(undefined4 *)(param_1 + 300) = uVar10;
  *(undefined8 *)(param_1 + 0x130) = *(undefined8 *)puVar1;
  *(undefined4 *)(param_1 + 0x138) = uVar10;
  uVar9 = *(undefined8 *)(param_2 + 0x4c);
  uStack_90 = *(uint *)(param_2 + 0x54);
  if (((fVar12 < (float)((uint)uVar9 & uVar2)) ||
      (uStack_98._4_4_ = (uint)((ulonglong)uVar9 >> 0x20), fVar12 < (float)(uStack_98._4_4_ & uVar2)
      )) || (fVar12 < (float)(uStack_90 & uVar2))) {
    *(undefined8 *)(param_1 + 0x130) = *(undefined8 *)(param_2 + 0x4c);
    *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_2 + 0x54);
    *(undefined8 *)(param_1 + 0x16c) = *(undefined8 *)(param_2 + 0x4c);
    *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_2 + 0x54);
  }
  *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_2 + 0x74);
  *(uint *)(param_1 + 0x2c0) = (uint)*(byte *)(param_2 + 0x81);
  *(uint *)(param_1 + 0x2c4) = (uint)*(byte *)(param_2 + 0x82);
  *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(param_1 + 0x1f0) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(param_1 + 0x1e0) = *(undefined4 *)(param_2 + 0x60);
  uStack_98 = uVar9;
  uVar10 = func_0x000140a7d9c0(param_2);
  *(undefined4 *)(param_1 + 0x1e4) = uVar10;
  *(undefined4 *)(param_1 + 0x1fc) = *(undefined4 *)(param_2 + 0x7c);
  *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(param_1 + 0x274);
  *(undefined4 *)(param_1 + 0x264) = *(undefined4 *)(param_1 + 0x274);
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(undefined1 *)(param_1 + 0x2d4) = 0;
  *(byte *)(param_1 + 0x2d5) = *(byte *)(param_2 + 0x83) >> 5 & 1;
  if (((*(int *)(param_1 + 0x2c0) - 0xbU < 2) || (*(int *)(param_1 + 0x2c0) == 0x34)) &&
     (*(int *)(param_1 + 0x2c4) != 0x35)) {
    *(undefined4 *)(param_1 + 0x2fc) = _DAT_146deecd0;
    *(undefined8 *)(param_1 + 0x1d0) = _DAT_146deecc0;
    *(undefined4 *)(param_1 + 0x1d8) = _DAT_146deecc8;
  }
  else {
    _DAT_146deeccc = 0;
    _DAT_146deecc0 = 0;
    _DAT_146deecc8 = 0;
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(char *)(param_1 + 0x2cb) == '\0') {
    if (*(short *)(lVar5 + 0x88) == 0) {
      plVar8 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x146dd8370);
    }
    else {
      plVar8 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
    }
    *(uint *)((longlong)plVar8 + 0x62c) = *(uint *)((longlong)plVar8 + 0x62c) | 0x4045;
    (**(code **)(*plVar8 + 200))(plVar8);
  }
  else {
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar9 = FUN_14167ab40(lVar5 + 0x58,0x146dd84e0);
    }
    else {
      uVar9 = func_0x0001416799a0(lVar5 + 0x80);
    }
    func_0x0001409a5590(uVar9,2);
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    plVar8 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x146dd6030);
  }
  else {
    plVar8 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
  }
  uVar10 = FUN_14085fc10(*(undefined8 *)(param_1 + 8));
  *(undefined4 *)(param_1 + 500) = uVar10;
  (**(code **)(*plVar8 + 0x120))(plVar8,auStack_78,0);
  *(undefined8 *)(param_1 + 0x194) = uStack_48;
  *(undefined4 *)(param_1 + 0x19c) = uStack_40;
  *(undefined4 *)(plVar8 + 0xe) = 3;
  *(undefined4 *)((longlong)plVar8 + 0x74) = 2;
  *(undefined1 *)(param_1 + 0x2cf) = 1;
  FUN_1409118f0(plVar8,0,&uStack_48,0);
  cVar3 = FUN_140869db0(*(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x2c0),
                        *(char *)((longlong)plVar8 + 0xb9d) != '\0');
  if (cVar3 != '\0') {
    func_0x00014089f410(plVar8 + 0x55,1);
  }
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_2 + 0x78);
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_2 + 0x5c);
  (**(code **)(*plVar4 + 0x80))(plVar4,afStack_88,0);
  fVar12 = (float)((uint)afStack_88[0] & uVar2);
  if ((float)((uint)afStack_88[0] & uVar2) <= (float)((uint)fStack_80 & uVar2)) {
    fVar12 = (float)((uint)fStack_80 & uVar2);
  }
  afStack_88[0] = afStack_88[0] * (_DAT_14382dce0 / fVar12);
  fStack_80 = fStack_80 * (_DAT_14382dce0 / fVar12);
  fVar11 = 0.0;
  if (0.0 < fVar12) {
    fVar11 = SQRT(fStack_80 * fStack_80 + afStack_88[0] * afStack_88[0]) * fVar12;
  }
  fVar11 = *(float *)(param_1 + 0x2e4) - fVar11;
  if (fVar11 <= 0.0) {
    fVar11 = 0.0;
  }
  *(float *)(param_1 + 0x2ec) = fVar11 / *(float *)(param_1 + 0x2e8);
  auStackX_8[0] = *(undefined4 *)((longlong)plVar8 + 0x194);
  lVar5 = func_0x0001415a0560(auStackX_8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146d03d80);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (lVar5 != 0) {
    func_0x0001405c72b0(lVar5);
  }
  uVar9 = FUN_14159cb80(*(undefined8 *)(param_1 + 8),0x146dac610,0);
  FUN_14085ac40(uVar9);
  if ((*(int *)(param_1 + 0x2c0) - 1U < 2) || (*(int *)(param_1 + 0x2c0) == 0x30)) {
    lVar5 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar9 = FUN_14167ab40(lVar5 + 0x58,0x146dacd70);
    }
    else {
      uVar9 = func_0x0001416799a0(lVar5 + 0x80);
    }
    FUN_140861cd0(uVar9);
  }
  return;
}


/* HeroStateSwingJumpLocal_virtual_12 @ 0x140a86ad0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140a86ad0(longlong *param_1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  undefined1 uVar7;
  char cVar8;
  undefined4 uVar9;
  longlong lVar10;
  longlong *plVar11;
  int *piVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong lVar15;
  undefined4 *puVar16;
  undefined *puVar17;
  undefined *puVar18;
  undefined4 uVar19;
  float extraout_XMM0_Da;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined4 auStackX_8 [2];
  float afStackX_10 [2];
  undefined8 uStackX_18;
  longlong lStackX_20;
  undefined8 in_stack_fffffffffffffe18;
  ulonglong uVar25;
  undefined8 in_stack_fffffffffffffe20;
  undefined8 *puVar26;
  ulonglong uVar27;
  uint uVar28;
  uint uVar29;
  uint in_stack_fffffffffffffe48;
  uint uVar30;
  ulonglong in_stack_fffffffffffffe58;
  undefined8 uStack_198;
  float fStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined1 uStack_16c;
  undefined1 uStack_16b;
  undefined1 uStack_16a;
  undefined8 uStack_168;
  float fStack_160;
  longlong lStack_158;
  undefined8 uStack_150;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined8 uStack_140;
  undefined4 uStack_138;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined4 uStack_dc;
  
  puVar17 = *(undefined **)param_1[1];
  puVar18 = &DAT_147afdf10;
  if (puVar17 != (undefined *)0x0) {
    puVar18 = puVar17;
  }
  bVar4 = false;
  uVar30 = in_stack_fffffffffffffe48 & 0xffffff00;
  uStack_f8 = *(undefined8 *)(puVar18 + 0x30);
  uStack_f0 = *(undefined8 *)(puVar18 + 0x38);
  uVar29 = 0x73420c96;
  uVar28 = 0x4453c00;
  uVar27 = 0;
  puVar26 = (undefined8 *)
            CONCAT44((int)((ulonglong)in_stack_fffffffffffffe20 >> 0x20),_DAT_143834794);
  uVar25 = CONCAT71((int7)((ulonglong)in_stack_fffffffffffffe18 >> 8),1);
  afStackX_10[0] = 0.0;
  FUN_140b7e920(&uStack_140,(undefined8 *)param_1[1],afStackX_10,0,uVar25,puVar26,_DAT_145d9a5cc,0,
                0x4453c00,0x73420c96,uVar30,1,in_stack_fffffffffffffe58 & 0xffffffff00000000);
  if (afStackX_10[0] < _DAT_14382e118) {
    puVar17 = *(undefined **)param_1[1];
    puVar18 = &DAT_147afdf10;
    if (puVar17 != (undefined *)0x0) {
      puVar18 = puVar17;
    }
    uStack_140 = *(undefined8 *)(puVar18 + 0x20);
    uStack_138 = *(undefined4 *)(puVar18 + 0x28);
  }
  FUN_140860b20((undefined8 *)param_1[1],&uStack_140,afStackX_10,0);
  lVar10 = param_1[1];
  if (*(short *)(lVar10 + 0x88) == 0) {
    lVar10 = FUN_14167ab40(lVar10 + 0x58,0x1473d09e0);
  }
  else {
    lVar10 = func_0x0001416799a0(lVar10 + 0x80);
  }
  lVar14 = param_1[1];
  if (*(short *)(lVar14 + 0x88) == 0) {
    plVar11 = (longlong *)FUN_14167ab40(lVar14 + 0x58,0x146deda80);
  }
  else {
    plVar11 = (longlong *)func_0x0001416799a0(lVar14 + 0x80);
  }
  func_0x0001415c6440(lVar10 + 0x68,auStackX_8,0);
  piVar12 = (int *)func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
  lVar10 = param_1[1];
  if (*(short *)(lVar10 + 0x88) == 0) {
    lVar10 = FUN_14167ab40(lVar10 + 0x58,0x147c40bf0);
  }
  else {
    lVar10 = func_0x0001416799a0(lVar10 + 0x80);
  }
  uVar19 = (undefined4)(uVar27 >> 0x20);
  if (piVar12 == (int *)0x0) {
    fVar24 = 0.0;
  }
  else {
    fVar24 = (float)piVar12[0xc0] * (float)piVar12[0xbd];
  }
  *(undefined4 *)(param_1[0x21] + 0x9fc) = _DAT_147a7fbf8;
  if (*(float *)((longlong)param_1 + 0x204) <= 0.0 && *(float *)((longlong)param_1 + 0x204) != 0.0)
  {
    if (*(char *)((longlong)param_1 + 0x2d5) != '\0') {
      fVar20 = (float)FUN_1420dc660(param_1);
      fVar21 = (float)func_0x0001416769f0(param_1);
      if (fVar21 * _DAT_14382ee90 < fVar20) {
        lVar14 = param_1[1];
        if (*(short *)(lVar14 + 0x88) == 0) {
          lVar14 = FUN_14167ab40(lVar14 + 0x58,0x146da9d90);
        }
        else {
          lVar14 = func_0x0001416799a0(lVar14 + 0x80);
        }
        lStack_158 = *(longlong *)(lVar14 + 0x50);
        uStack_144 = 0xcd07a28;
        uStack_148 = 0;
        uStack_150 = 0;
        if ((lStack_158 == 0) || (lVar14 = FUN_14169a690(lStack_158,&lStack_158), lVar14 == 0)) {
          uVar7 = 0;
        }
        else {
          uVar7 = FUN_1416990f0(lStack_158,lVar14,0);
        }
        *(undefined1 *)((longlong)param_1 + 0x2d5) = uVar7;
        cVar8 = FUN_14098fc80(param_1[0x21]);
        if (cVar8 != '\0') {
          uVar7 = func_0x00014098fc70(param_1[0x21]);
          *(undefined1 *)((longlong)param_1 + 0x2d5) = uVar7;
        }
        if ((*(char *)((longlong)param_1 + 0x2d5) != '\0') &&
           (*(float *)(param_1 + 0x3e) <= _DAT_14384e300 &&
            _DAT_14384e300 != *(float *)(param_1 + 0x3e))) {
          fVar20 = (float)(**(code **)(*plVar11 + 0xd0))(plVar11);
          lVar14 = *(longlong *)((longlong)plVar11 + 0x344);
          uStack_150 = CONCAT44(uStack_150._4_4_,*(undefined4 *)((longlong)plVar11 + 0x34c));
          lVar15 = FUN_141676930(param_1);
          lStack_158 = lVar14;
          if ((_DAT_143854044 < fVar20) &&
             (_DAT_143830120 < *(float *)(lVar15 + 4) - (float)((ulonglong)lVar14 >> 0x20))) {
            *(undefined1 *)((longlong)param_1 + 0x2d5) = 0;
          }
        }
      }
    }
    if (((int)param_1[0x58] == 0xb) || ((int)param_1[0x58] == 0xc)) {
      bVar4 = true;
    }
    if ((piVar12 == (int *)0x0) || ((*(byte *)(piVar12 + 1) & 4) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((((*(float *)(param_1 + 0x3e) <= 0.0 && *(float *)(param_1 + 0x3e) != 0.0) || (bVar2)) ||
        (bVar4)) || (*(float *)(param_1 + 0x3c) == 0.0)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    bVar5 = bVar2;
    if (*(char *)((longlong)param_1 + 0x2cc) != '\0') {
      if ((*(char *)(lVar10 + 0x441) == '\0') ||
         (_DAT_145d9f874 < *(float *)(lVar10 + 0x430) ||
          _DAT_145d9f874 == *(float *)(lVar10 + 0x430))) {
        bVar6 = 0;
      }
      else {
        bVar6 = 1;
      }
      bVar5 = (bool)(bVar6 | bVar2);
    }
    fVar21 = (float)FUN_1420dc660(param_1);
    fVar20 = _DAT_143837a20;
    bVar3 = _DAT_143837a20 < fVar21;
    if (((!bVar5) && (_DAT_145d9fe2c <= *(float *)(param_1 + 0x3e) / *(float *)(param_1 + 0x3c))) ||
       (uVar19 = 0, bVar4)) {
      lStackX_20 = param_1[0x56];
      puVar16 = (undefined4 *)FUN_141f7b890(&lStackX_20,&uStackX_18);
      uVar19 = *puVar16;
    }
    if ((bVar2) && (cVar8 = (**(code **)(*param_1 + 0x108))(param_1), cVar8 != '\0')) {
      return 1;
    }
    cVar8 = (**(code **)(*param_1 + 0xb8))(param_1);
    fVar21 = _DAT_14382e128;
    if (cVar8 == '\0') {
      if (bVar3) {
        puVar17 = &DAT_147afdf10;
        if (*(undefined **)param_1[1] != (undefined *)0x0) {
          puVar17 = *(undefined **)param_1[1];
        }
        uStack_168 = *(undefined8 *)(puVar17 + 0x20);
        fVar22 = *(float *)(param_1 + 0x3e);
        fStack_160 = *(float *)(puVar17 + 0x28);
        bVar2 = _DAT_1438374ac < fVar22;
        if (0.0 < fVar22) {
          bVar2 = fVar22 / *(float *)(param_1 + 0x3c) < _DAT_14382ee8c;
        }
        puVar26 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar26 >> 8),bVar2);
        uVar25 = CONCAT71((int7)(uVar25 >> 8),1);
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x1f8))
                          ((longlong *)param_1[0x21],0,&uStack_168,_DAT_143840ed0,uVar25,puVar26);
        if (cVar8 != '\0') {
          return 1;
        }
        fVar22 = (float)FUN_1420dc660(param_1);
        uVar7 = 0;
        if (fVar22 < fVar21) {
          if (((int)param_1[0x58] == 0x11) || ((int)param_1[0x58] == 0x12)) {
            uVar7 = 1;
          }
          else {
            uVar7 = 0;
          }
        }
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x308))
                          ((longlong *)param_1[0x21],0,uVar7,0);
        if (cVar8 != '\0') {
          return 1;
        }
        uVar9 = (**(code **)(*param_1 + 0x118))(param_1);
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x1b0))
                          ((longlong *)param_1[0x21],uVar9,uVar19);
        if (cVar8 != '\0') {
          return 1;
        }
      }
      uVar19 = (undefined4)(uVar27 >> 0x20);
      if (((DAT_145d9f89b != '\0') && ((int)param_1[0x58] != 0x24)) && ((int)param_1[0x58] != 0x25))
      {
        func_0x0001408687b0(&uStack_e8);
        uStack_dc = (undefined4)param_1[0x58];
        puVar26 = &uStack_e8;
        uVar27 = CONCAT44(uVar19,_DAT_14382e13c);
        uVar25 = uVar25 & 0xffffffff00000000;
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 200))
                          ((longlong *)param_1[0x21],fVar20,0,0,uVar25,puVar26,0,uVar27,0xffffffff);
        if (cVar8 != '\0') {
          return 1;
        }
      }
      fVar22 = (float)FUN_1420dc660(param_1);
      if ((fVar20 < fVar22) ||
         ((bVar4 && (*(float *)(param_1 + 0x3e) <= 0.0 && *(float *)(param_1 + 0x3e) != 0.0)))) {
        cVar8 = func_0x00014098fb60(param_1[0x21]);
        if ((cVar8 == '\0') &&
           (cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x4d8))((longlong *)param_1[0x21],0),
           cVar8 != '\0')) {
          return 1;
        }
        if (((int)param_1[0x58] != 0x25) &&
           (cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x128))(), cVar8 != '\0')) {
          return 0;
        }
        cVar8 = (**(code **)(*param_1 + 0x1e0))(param_1);
        if (cVar8 != '\0') {
          uStack_198 = 0;
          fStack_190 = 0.0;
          cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x118))
                            ((longlong *)param_1[0x21],&uStack_198,0,fVar20);
          if (cVar8 != '\0') {
            return 1;
          }
        }
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x170))();
        if (cVar8 != '\0') {
          return 1;
        }
        cVar8 = (**(code **)(*param_1 + 0x1f0))(param_1);
        if ((cVar8 != '\0') &&
           (cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x4a0))((longlong *)param_1[0x21],2,0)
           , cVar8 != '\0')) {
          return 1;
        }
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0xf0))((longlong *)param_1[0x21],0,0,0);
        if (cVar8 != '\0') {
          return 1;
        }
        fVar22 = (float)FUN_1420dc660(param_1);
        if ((fVar22 < _DAT_143836d08) &&
           ((((iVar1 = (int)param_1[0x58], iVar1 == 3 || (iVar1 == 0)) || (iVar1 == 1)) &&
            (cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x1a8))(), cVar8 != '\0')))) {
          return 1;
        }
        uVar13 = 0;
        if ((int)param_1[0x58] == 0x11) {
          uVar13 = 0x10;
        }
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x2a0))((longlong *)param_1[0x21],uVar13);
        if (cVar8 != '\0') {
          return 1;
        }
        if ((int)param_1[0x58] != 0x25) {
          cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x160))((longlong *)param_1[0x21],0,1);
          if (cVar8 != '\0') {
            return 1;
          }
          cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x2f8))();
          if (cVar8 != '\0') {
            return 1;
          }
        }
        fVar22 = _DAT_14382dce0;
        if (*(float *)(lVar10 + 0x434) <= 0.0) {
          fVar23 = 0.0;
        }
        else {
          fVar23 = _DAT_14382dce0 / *(float *)(lVar10 + 0x434);
        }
        uStack_198 = *(undefined8 *)(lVar10 + 700);
        fStack_190 = *(float *)(lVar10 + 0x2c4);
        fStack_160 = ((fStack_190 - *(float *)(lVar10 + 0x3b4)) - *(float *)(lVar10 + 0x2f4)) *
                     fVar23;
        uStack_168 = CONCAT44((int)param_1[0x3e],
                              (((float)uStack_198 - *(float *)(lVar10 + 0x3ac)) -
                              *(float *)(lVar10 + 0x2ec)) * fVar23);
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x158))
                          ((longlong *)param_1[0x21],&uStack_168,(int)param_1[0x3c]);
        if (cVar8 != '\0') {
          return 1;
        }
        lVar14 = param_1[1];
        if (*(short *)(lVar14 + 0x88) == 0) {
          lVar14 = FUN_14167ab40(lVar14 + 0x58,0x146dacd70);
        }
        else {
          lVar14 = func_0x0001416799a0(lVar14 + 0x80);
        }
        uVar13 = 0x800;
        if (*(char *)(lVar14 + 0x396) != '\0') {
          uVar13 = 0;
        }
        if ((*(char *)((longlong)param_1 + 0x2d4) == '\0') &&
           (cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x3e0))
                              ((longlong *)param_1[0x21],uVar13,0,0), cVar8 != '\0')) {
          return 1;
        }
        iVar1 = (int)param_1[0x58];
        if (((iVar1 == 0) || (iVar1 == 1)) || ((iVar1 == 2 || (iVar1 == 3)))) {
          if (*(float *)(lVar10 + 0x434) <= 0.0) {
            fVar22 = 0.0;
          }
          else {
            fVar22 = fVar22 / *(float *)(lVar10 + 0x434);
          }
          lStack_158 = *(longlong *)(lVar10 + 700);
          uStack_150 = CONCAT44(uStack_150._4_4_,*(float *)(lVar10 + 0x2c4));
          uStack_198 = CONCAT44((((float)((ulonglong)lStack_158 >> 0x20) -
                                 *(float *)(lVar10 + 0x3b0)) - *(float *)(lVar10 + 0x2f0)) * fVar22,
                                (((float)lStack_158 - *(float *)(lVar10 + 0x3ac)) -
                                *(float *)(lVar10 + 0x2ec)) * fVar22);
          fStack_190 = ((*(float *)(lVar10 + 0x2c4) - *(float *)(lVar10 + 0x3b4)) -
                       *(float *)(lVar10 + 0x2f4)) * fVar22;
          cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x478))
                            ((longlong *)param_1[0x21],&uStack_198);
          if (cVar8 != '\0') {
            return 1;
          }
        }
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x2c8))((longlong *)param_1[0x21],0);
        if (cVar8 != '\0') {
          return 1;
        }
        func_0x00014098dba0(&uStack_188);
        if ((((*(float *)((longlong)param_1 + 0x244) <= fVar24) || (piVar12 == (int *)0x0)) ||
            (*piVar12 != (int)param_1[0x49])) || (*(char *)((longlong)param_1 + 0x24e) == '\0')) {
          uStack_180 = 0;
          uStack_188 = 0;
          uStack_178 = 0;
          uStack_16c = 0;
          uStack_16a = 0;
        }
        else {
          uStack_180 = *(undefined8 *)((longlong)param_1 + 0x22c);
          uStack_188 = *(undefined8 *)((longlong)param_1 + 0x234);
          uStack_178 = *(undefined8 *)((longlong)param_1 + 0x23c);
          uStack_16c = *(undefined1 *)((longlong)param_1 + 0x24c);
          uStack_16a = *(undefined1 *)((longlong)param_1 + 0x24d);
        }
        uStack_16b = (int)param_1[0x58] == 0xc;
        (**(code **)(*param_1 + 0xe8))(param_1,&uStack_188);
        if ((*(char *)((longlong)param_1 + 0x2d5) == '\0') &&
           (cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x288))
                              ((longlong *)param_1[0x21],&uStack_188), cVar8 != '\0')) {
          return 1;
        }
        cVar8 = (**(code **)(*param_1 + 0x100))(param_1);
        if (cVar8 != '\0') {
          return 1;
        }
        if (((*(float *)(param_1 + 0x43) <= fVar24) &&
            (*(char *)((longlong)param_1 + 0x2dc) != '\0')) &&
           (cVar8 = (**(code **)(*param_1 + 0xf0))(param_1), cVar8 != '\0')) {
          return 1;
        }
      }
      cVar8 = func_0x00014098def0(param_1[0x21]);
      if (cVar8 != '\0') {
        puVar26 = (undefined8 *)CONCAT44((int)((ulonglong)puVar26 >> 0x20),fVar20);
        uVar25 = 0;
        puVar17 = &DAT_147afdf10;
        if (*(undefined **)param_1[1] != (undefined *)0x0) {
          puVar17 = *(undefined **)param_1[1];
        }
        lStack_158 = *(longlong *)(puVar17 + 0x20);
        uStack_150 = CONCAT44(uStack_150._4_4_,*(undefined4 *)(puVar17 + 0x28));
        cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x1a0))
                          ((longlong *)param_1[0x21],1,4,&lStack_158,0,puVar26);
        if (cVar8 != '\0') {
          return 1;
        }
      }
      cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x90))();
      if (cVar8 != '\0') {
        return 1;
      }
    }
    cVar8 = (**(code **)(*param_1 + 0xf8))(param_1);
    if (cVar8 != '\0') {
      return 1;
    }
    if (fVar21 < *(float *)(param_1 + 0x4e)) {
      puVar26 = (undefined8 *)CONCAT44((int)((ulonglong)puVar26 >> 0x20),fVar20);
      uVar25 = 0;
      cVar8 = (**(code **)(*(longlong *)param_1[0x21] + 0x1a0))
                        ((longlong *)param_1[0x21],0,4,0,0,puVar26);
      if (cVar8 != '\0') {
        return 1;
      }
    }
    cVar8 = (**(code **)(*param_1 + 0xc0))(param_1);
    if (cVar8 == '\0') {
      cVar8 = (**(code **)(*param_1 + 200))(param_1);
      if ((cVar8 != '\0') && (cVar8 = (**(code **)(*param_1 + 0xd8))(param_1), cVar8 != '\0')) {
        return 1;
      }
    }
    else {
      cVar8 = (**(code **)(*param_1 + 0xd0))();
      if (cVar8 != '\0') {
        if (*(char *)((longlong)param_1 + 0x2dd) != '\0') {
          return 1;
        }
        puVar16 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
        uVar13 = FUN_1416d5e80(0x147475690,0xb47a06a,*puVar16,0,uVar25 & 0xffffffff00000000,
                               (ulonglong)puVar26 & 0xffffffffffffff00,0,uVar27 & 0xffffffff00000000
                               ,1,0,0,0,0);
        (**(code **)(*param_1 + 0x110))(param_1,uVar13);
        *(undefined1 *)((longlong)param_1 + 0x2dd) = 1;
        return 1;
      }
    }
    if (((int)param_1[0x58] == 0x11) || ((int)param_1[0x58] == 0x2a)) {
      (**(code **)(*(longlong *)param_1[0x21] + 0x2c0))((longlong *)param_1[0x21],0x100010,0);
    }
  }
  else {
    if (*(short *)(param_1[1] + 0x88) == 0) {
      lVar10 = FUN_14167ab40(param_1[1] + 0x58,0x1473d09e0);
      uVar9 = (undefined4)((ulonglong)puVar26 >> 0x20);
    }
    else {
      lVar10 = func_0x0001416799a0();
      uVar9 = (undefined4)((ulonglong)puVar26 >> 0x20);
    }
    if (((lVar10 == 0) || (*(float *)(param_1 + 0x40) <= 0.0 && *(float *)(param_1 + 0x40) != 0.0))
       || (FUN_1415c09c0(lVar10,0), extraout_XMM0_Da < *(float *)(param_1 + 0x40))) {
      bVar4 = false;
      if (lVar10 == 0) {
        return 0;
      }
    }
    else {
      bVar4 = true;
    }
    if ((((*(byte *)(lVar10 + 0x98) & 1) == 0) || ((*(byte *)(lVar10 + 0xa0) & 1) != 0)) || (bVar4))
    {
      uVar13 = (**(code **)(*(longlong *)param_1[0x21] + 0x68))
                         ((longlong *)param_1[0x21],1,0,0,uVar25 & 0xffffffffffffff00,
                          CONCAT44(uVar9,0xffffffff),0,CONCAT44(uVar19,_DAT_14382dce0),
                          uVar28 & 0xffffff00,uVar29 & 0xffffff00,uVar30 & 0xffffff00);
      return uVar13;
    }
  }
  return 0;
}


/* HeroStateSwingJumpLocal_virtual_17 @ 0x140a87850 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_140a87850(longlong param_1)

{
  longlong lVar1;
  float fVar2;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    lVar1 = FUN_14167ab40(lVar1 + 0x58,0x147c40bf0);
  }
  else {
    lVar1 = func_0x0001416799a0(lVar1 + 0x80);
  }
  if (lVar1 == 0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = *(float *)(lVar1 + 0x6b8);
  }
  if (_DAT_145d9a624 <= fVar2) {
    fVar2 = (float)FUN_1420dc610(param_1);
    lVar1 = func_0x0001409c87f0(param_1);
    if (*(float *)(param_1 + 0x210) <= fVar2 && fVar2 != *(float *)(param_1 + 0x210)) {
      fVar2 = (float)FUN_1420dc660(param_1);
      if ((_DAT_143836d08 < fVar2) && (_DAT_143836d0c < *(float *)(lVar1 + 0x394))) {
        return 1;
      }
    }
  }
  return 0;
}


/* HeroStateSwingJumpLocal_virtual_18 @ 0x140a87910 */

longlong FUN_140a87910(longlong param_1)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  
  lVar7 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar7 + 0x88) == 0) {
    FUN_14167ab40(lVar7 + 0x58,0x146dacd70);
  }
  else {
    func_0x0001416799a0(lVar7 + 0x80);
  }
  lVar7 = func_0x00014085fda0();
  if ((*(int *)(param_1 + 0x2c0) == 0xb) || (*(int *)(param_1 + 0x2c0) == 0x34)) {
    cVar3 = func_0x000140869570(*(undefined4 *)(param_1 + 0x2c4));
    bVar2 = true;
    if (cVar3 != '\0') {
      bVar2 = false;
    }
  }
  else {
    bVar2 = false;
  }
  if (lVar7 == 0) {
    if ((!bVar2) || (iVar8 = *(int *)(param_1 + 0x2c4), iVar8 == 0x35)) {
      iVar8 = *(int *)(param_1 + 0x2c0);
    }
    lVar7 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar7 + 0x88) == 0) {
      uVar4 = FUN_14167ab40(lVar7 + 0x58,0x146dd6340);
    }
    else {
      uVar4 = func_0x0001416799a0(lVar7 + 0x80);
    }
    lVar5 = func_0x000140923950(uVar4);
    switch(iVar8) {
    default:
      lVar5 = lVar5 + 0x930;
      break;
    case 1:
    case 0x33:
      lVar5 = lVar5 + 0x9a0;
      break;
    case 2:
      lVar5 = lVar5 + 0xa10;
      break;
    case 6:
      lVar5 = lVar5 + 0xb60;
      break;
    case 7:
      lVar5 = lVar5 + 0xaf0;
      break;
    case 8:
      lVar5 = lVar5 + 0x10a0;
      break;
    case 9:
      lVar5 = lVar5 + 0x1110;
      break;
    case 10:
      lVar5 = lVar5 + 0x1180;
      break;
    case 0xd:
    case 0xe:
    case 0xf:
      lVar5 = lVar5 + 0xbd0;
      break;
    case 0x10:
      lVar5 = lVar5 + 0xc40;
      break;
    case 0x11:
      lVar5 = lVar5 + 0xcb0;
      break;
    case 0x12:
    case 0x1c:
      lVar5 = lVar5 + 0xd20;
      break;
    case 0x13:
      lVar5 = lVar5 + 0xd90;
      break;
    case 0x14:
      lVar5 = lVar5 + 0xe00;
      break;
    case 0x15:
      lVar5 = lVar5 + 0x11f0;
      break;
    case 0x16:
    case 0x18:
    case 0x19:
      lVar5 = lVar5 + 0xee0;
      break;
    case 0x17:
      lVar5 = lVar5 + 0xe70;
      break;
    case 0x1a:
      lVar5 = lVar5 + 0xf50;
      break;
    case 0x1d:
      lVar5 = lVar5 + 0x12d0;
      break;
    case 0x20:
      lVar5 = lVar5 + 0x1340;
      break;
    case 0x21:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x218;
    case 0x22:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x388;
    case 0x23:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x2d0;
    case 0x24:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x440;
    case 0x25:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x500;
    case 0x26:
      lVar5 = lVar5 + 0xfc0;
      break;
    case 0x27:
      lVar5 = lVar5 + 0x1030;
      break;
    case 0x2a:
      lVar5 = lVar5 + 0x1260;
      break;
    case 0x2b:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x5b8;
    case 0x2c:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x670;
    case 0x2d:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x728;
    case 0x2e:
      lVar7 = func_0x000140923630(uVar4);
      return lVar7 + 0x7e0;
    case 0x2f:
      lVar5 = lVar5 + 0x13b0;
      break;
    case 0x30:
      lVar5 = lVar5 + 0xa80;
      break;
    case 0x31:
      lVar5 = lVar5 + 0x1420;
    }
    uVar9 = 0;
    lVar6 = 0;
    if (lVar5 != 0) {
      lVar6 = lVar5 + 8;
      if (*(short *)(lVar7 + 0x88) == 0) {
        lVar7 = FUN_14167ab40(lVar7 + 0x58,0x146dd80e0);
      }
      else {
        lVar7 = func_0x0001416799a0(lVar7 + 0x80);
      }
      if ((lVar7 != 0) &&
         (((cVar3 = func_0x00014098fa90(lVar7), cVar3 != '\0' ||
           (cVar3 = func_0x00014098f920(lVar7), cVar3 != '\0')) &&
          (uVar1 = *(uint *)(lVar5 + 0x68), uVar1 != 0)))) {
        do {
          lVar7 = func_0x0001411a72e0(lVar5,uVar9);
          if (*(int *)(lVar7 + 8) == 0) {
            lVar6 = func_0x0001411a72e0(lVar5,uVar9);
            lVar6 = lVar6 + 0x10;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar1);
      }
    }
    return lVar6;
  }
  return lVar7;
}


/* HeroStateSwingJumpLocal_virtual_19 @ 0x140a879d0 */

longlong FUN_140a879d0(longlong param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  int iVar9;
  uint uVar10;
  
  lVar8 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar8 + 0x88) == 0) {
    uVar7 = FUN_14167ab40(lVar8 + 0x58,0x146dacd70);
  }
  else {
    uVar7 = func_0x0001416799a0(lVar8 + 0x80);
  }
  lVar8 = FUN_14085fdb0(uVar7,*(undefined4 *)(param_1 + 0x2c0));
  iVar2 = *(int *)(param_1 + 0x2c0);
  if ((iVar2 == 0xb) || (iVar2 == 0x34)) {
    bVar3 = true;
    if (*(int *)(param_1 + 0x2c4) - 0x23U < 2) {
      bVar3 = false;
    }
  }
  else {
    bVar3 = false;
  }
  if (lVar8 == 0) {
    if ((!bVar3) || (iVar9 = *(int *)(param_1 + 0x2c4), *(int *)(param_1 + 0x2c4) == 0x35)) {
      iVar9 = iVar2;
    }
    lVar8 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar8 + 0x88) == 0) {
      uVar7 = FUN_14167ab40(lVar8 + 0x58,0x146dd6340);
    }
    else {
      uVar7 = func_0x0001416799a0(lVar8 + 0x80);
    }
    lVar5 = func_0x000140923950(uVar7);
    switch(iVar9) {
    default:
      lVar6 = 0xb68;
      break;
    case 1:
    case 0x13:
    case 0x33:
      lVar6 = 0xbb0;
      break;
    case 2:
      lVar6 = 0xbf8;
      break;
    case 0xc:
      lVar6 = 0xcd0;
      break;
    case 0x11:
    case 0x12:
    case 0x2a:
      lVar6 = 0xc40;
      break;
    case 0x1a:
      lVar6 = 0xc88;
      break;
    case 0x1d:
      lVar6 = 0xd18;
      break;
    case 0x2f:
      lVar6 = 0xd60;
      break;
    case 0x30:
      lVar6 = 0xda8;
    }
    lVar6 = lVar5 + 0x928 + lVar6;
    uVar10 = 0;
    if (lVar6 == 0) {
      return 0;
    }
    lVar5 = lVar6 + 8;
    if (*(short *)(lVar8 + 0x88) == 0) {
      lVar8 = FUN_14167ab40(lVar8 + 0x58,0x146dd80e0);
    }
    else {
      lVar8 = func_0x0001416799a0(lVar8 + 0x80);
    }
    if ((lVar8 != 0) &&
       (((cVar4 = func_0x00014098fa90(lVar8), cVar4 != '\0' ||
         (cVar4 = func_0x00014098f920(lVar8), cVar4 != '\0')) &&
        (uVar1 = *(uint *)(lVar6 + 0x40), uVar1 != 0)))) {
      do {
        lVar8 = func_0x0001411a7300(lVar6,uVar10);
        if (*(int *)(lVar8 + 8) == 0) {
          lVar5 = func_0x0001411a7300(lVar6,uVar10);
          lVar5 = lVar5 + 0x10;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar1);
    }
    return lVar5;
  }
  return lVar8;
}


/* HeroStateSwingJumpLocal_virtual_20 @ 0x140a87a70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140a87a70(longlong *param_1,float *param_2,float *param_3,float *param_4,
                  undefined4 *param_5,float param_6)

{
  float fVar1;
  longlong lVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar2 = (**(code **)(*param_1 + 0x98))();
  fVar4 = *(float *)(lVar2 + 0x18);
  if (*(float *)(lVar2 + 0x18) <= *(float *)((longlong)param_1 + 0x264)) {
    fVar4 = *(float *)((longlong)param_1 + 0x264);
  }
  fVar3 = *(float *)(lVar2 + 0xc);
  fVar1 = *(float *)(lVar2 + 0x10);
  *(float *)((longlong)param_1 + 0x264) = fVar4;
  if (fVar4 < fVar3) {
    fVar1 = *(float *)(lVar2 + 0x1c);
    if (_DAT_146deeccc < *(float *)(lVar2 + 0x20) || _DAT_146deeccc == *(float *)(lVar2 + 0x20))
    goto LAB_140a87b2d;
    if (fVar1 <= 0.0) {
      *(float *)((longlong)param_1 + 0x264) = fVar3;
      fVar4 = fVar3;
      goto LAB_140a87b2d;
    }
    fVar5 = fVar1;
    if ((0.0 < *(float *)(lVar2 + 0x24)) &&
       (fVar5 = *(float *)(lVar2 + 0x24) * param_6 + *(float *)(param_1 + 0x4d), fVar1 <= fVar5)) {
      fVar5 = fVar1;
    }
    *(float *)(param_1 + 0x4d) = fVar5;
    fVar4 = fVar5 * param_6 + fVar4;
    if (fVar3 <= fVar4) {
      fVar4 = fVar3;
    }
  }
  else if (fVar1 <= fVar4) {
    fVar4 = fVar1;
  }
  *(float *)((longlong)param_1 + 0x264) = fVar4;
LAB_140a87b2d:
  *param_4 = fVar4;
  fVar4 = *(float *)(lVar2 + 8);
  if (*(float *)((longlong)param_1 + 0x264) <= *(float *)(lVar2 + 8)) {
    fVar4 = *(float *)((longlong)param_1 + 0x264);
  }
  *param_3 = fVar4;
  fVar3 = fVar4 * _DAT_14382e124;
  if (_DAT_14382e124 <= fVar4 * _DAT_14382e124) {
    fVar3 = _DAT_14382e124;
  }
  *param_2 = fVar3;
  *param_5 = *(undefined4 *)(lVar2 + 0x14);
  return;
}


/* HeroStateSwingJumpLocal_virtual_21 @ 0x140a87b80 */

undefined8 HeroStateSwingJumpLocal_virtual_21(void)

{
  return 0xd69724b0;
}


/* HeroStateSwingJumpLocal_virtual_22 @ 0x140a87b90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140a87b90(longlong *param_1,float param_2)

{
  float fVar1;
  char cVar2;
  longlong lVar3;
  float fVar4;
  float fVar5;
  longlong alStack_38 [2];
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  param_1[0x4a] = 0;
  *(undefined4 *)(param_1 + 0x4b) = 0;
  if ((char)param_1[0x5a] != '\0') {
    return;
  }
  if ((char)param_1[0x59] != '\0') {
    return;
  }
  if (*(float *)(param_1 + 0x3e) <= _DAT_1438726d0 && _DAT_1438726d0 != *(float *)(param_1 + 0x3e))
  {
    *(undefined1 *)(param_1 + 0x5a) = 1;
    return;
  }
  if (0x2e < *(uint *)(param_1 + 0x58)) {
    return;
  }
  if ((0x781e27000009U >> ((longlong)(int)*(uint *)(param_1 + 0x58) & 0x3fU) & 1) == 0) {
    return;
  }
  lVar3 = param_1[1];
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146da9d90);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  uStack_24 = (**(code **)(*param_1 + 0xa8))(param_1);
  alStack_38[0] = *(longlong *)(lVar3 + 0x50);
  uStack_28 = 0;
  alStack_38[1] = 0;
  if ((alStack_38[0] == 0) || (lVar3 = FUN_14169a690(alStack_38[0],alStack_38), lVar3 == 0)) {
    *(undefined1 *)(param_1 + 0x5f) = 0;
  }
  else {
    cVar2 = FUN_1416990f0(alStack_38[0],lVar3,0);
    *(char *)(param_1 + 0x5f) = cVar2;
    if (cVar2 != '\0') goto LAB_140a87ca7;
  }
  if (*(char *)((longlong)param_1 + 0x2d6) == '\0') {
    *(undefined1 *)(param_1 + 0x5a) = 1;
    return;
  }
LAB_140a87ca7:
  lVar3 = (**(code **)(*param_1 + 0x90))(param_1);
  fVar5 = *(float *)(param_1 + 0x5c) + param_2;
  fVar1 = *(float *)(lVar3 + 0x1c);
  fVar4 = *(float *)(param_1 + 0x5c) - fVar1;
  *(undefined4 *)(param_1 + 0x4a) = *(undefined4 *)(lVar3 + 0x14);
  *(undefined4 *)((longlong)param_1 + 0x254) = *(undefined4 *)(lVar3 + 0x18);
  if (fVar4 <= 0.0) {
    fVar4 = 0.0;
  }
  *(float *)(param_1 + 0x5c) = fVar5;
  *(bool *)(param_1 + 0x5a) = fVar1 <= fVar5;
  param_2 = param_2 - fVar4;
  if (param_2 <= 0.0) {
    param_2 = 0.0;
  }
  *(float *)(param_1 + 0x4b) = param_2;
  return;
}


/* HeroStateSwingJumpLocal_virtual_23 @ 0x140a143c0 */

undefined1 HeroStateSwingJumpLocal_virtual_23(void)

{
  return 0;
}


/* HeroStateSwingJumpLocal_virtual_24 @ 0x140a87d50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140a87d50(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint7 uVar6;
  ulonglong uVar5;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 auStackX_8 [2];
  float fStack_24;
  
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    lVar2 = FUN_14167ab40(lVar2 + 0x58,0x1473d09e0);
  }
  else {
    lVar2 = func_0x0001416799a0(lVar2 + 0x80);
  }
  func_0x0001415c6440(lVar2 + 0x68,auStackX_8,0);
  lVar3 = func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    lVar2 = FUN_14167ab40(lVar2 + 0x58,0x146deda80);
  }
  else {
    lVar2 = func_0x0001416799a0(lVar2 + 0x80);
  }
  fVar9 = _DAT_14382f0e0;
  if (lVar3 != 0) {
    fVar9 = *(float *)(lVar3 + 0x300) * *(float *)(lVar3 + 0x2f4);
  }
  lVar4 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    lVar4 = FUN_14167ab40(lVar4 + 0x58,0x147c40bf0);
  }
  else {
    lVar4 = func_0x0001416799a0(lVar4 + 0x80);
  }
  fVar8 = _DAT_14382e13c;
  if (0.0 < *(float *)(param_1 + 0x1f0) || *(float *)(param_1 + 0x1f0) == 0.0) {
    fVar8 = _DAT_14382dce0;
  }
  fStack_24 = (float)((ulonglong)*(undefined8 *)(lVar4 + 0x5d8) >> 0x20);
  fVar7 = _DAT_14382dce0;
  if (fStack_24 < 0.0) {
    fVar7 = _DAT_14382e13c;
  }
  uVar6 = (uint7)((ulonglong)lVar4 >> 8);
  if (fVar8 == fVar7) {
    uVar5 = (ulonglong)uVar6 << 8;
  }
  else {
    uVar5 = CONCAT71(uVar6,1);
  }
  fVar8 = *(float *)(param_1 + 0x21c);
  if ((0.0 <= fVar8) && (fVar9 < fVar8)) goto LAB_140a87ef2;
  if ((char)uVar5 == '\0') {
LAB_140a87ebe:
    if ((lVar3 == 0) || ((*(byte *)(lVar3 + 4) & 4) == 0)) {
      uVar1 = *(int *)(param_1 + 0x2c0) - 0xb;
      uVar5 = (ulonglong)uVar1;
      if ((1 < uVar1) &&
         ((*(int *)(param_1 + 0x2c0) != 0x34 && (*(float *)(param_1 + 0x1e0) != 0.0))))
      goto LAB_140a87ef2;
    }
  }
  else if ((*(char *)(lVar2 + 0x45e) != '\0') && (fVar8 < 0.0)) {
    fVar8 = _DAT_143830118;
    if (lVar3 != 0) {
      fVar8 = *(float *)(lVar3 + 0x300);
    }
    if (fVar9 <= fVar8 - _DAT_14382ee88) goto LAB_140a87ebe;
  }
  if (0.0 < *(float *)(lVar4 + 0x6b4) || *(float *)(lVar4 + 0x6b4) == 0.0) {
    return CONCAT71((int7)(uVar5 >> 8),1);
  }
LAB_140a87ef2:
  return uVar5 & 0xffffffffffffff00;
}


/* HeroStateSwingJumpLocal_virtual_25 @ 0x140a87f10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140a87f10(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  float extraout_XMM0_Da;
  float extraout_XMM0_Da_00;
  float fVar7;
  float extraout_XMM0_Da_01;
  float fVar8;
  float fVar9;
  
  if ((1 < *(int *)(param_1 + 0x2c0) - 0xbU) &&
     (FUN_1420dc660(), _DAT_14382ee88 <= extraout_XMM0_Da)) {
    lVar4 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar4 + 0x88) == 0) {
      lVar4 = FUN_14167ab40(lVar4 + 0x58,0x1473d09e0);
    }
    else {
      lVar4 = func_0x0001416799a0(lVar4 + 0x80);
    }
    lVar5 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      lVar5 = FUN_14167ab40(lVar5 + 0x58,0x147c40bf0);
    }
    else {
      lVar5 = func_0x0001416799a0(lVar5 + 0x80);
    }
    lVar1 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar1 + 0x88) == 0) {
      plVar6 = (longlong *)FUN_14167ab40(lVar1 + 0x58,0x146deda80);
    }
    else {
      plVar6 = (longlong *)func_0x0001416799a0(lVar1 + 0x80);
    }
    FUN_1415c09c0(lVar4,0);
    if ((*(char *)(param_1 + 0x2da) == '\0') || (extraout_XMM0_Da_00 < *(float *)(param_1 + 0x20c)))
    {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (((*(float *)(param_1 + 0x1f8) <= extraout_XMM0_Da_00) || (bVar2)) &&
       (*(float *)(lVar5 + 0x6b4) <= 0.0 && *(float *)(lVar5 + 0x6b4) != 0.0)) {
      fVar9 = *(float *)(param_1 + 0x214);
      if (*(float *)(param_1 + 0x214) <= *(float *)(param_1 + 0x208)) {
        fVar9 = *(float *)(param_1 + 0x208);
      }
      if ((*(char *)((longlong)plVar6 + 0x45e) == '\0') || (bVar2)) {
        if (((0.0 <= fVar9) && (fVar9 < extraout_XMM0_Da_00)) ||
           (((bVar2 || ((*(byte *)(lVar4 + 0x98) & 1) == 0)) || ((*(byte *)(lVar4 + 0xa0) & 1) != 0)
            ))) {
          cVar3 = FUN_1415bfc60(lVar4,_DAT_14382e120,0);
          *(bool *)(param_1 + 0x2d3) = cVar3 == '\0';
          return 1;
        }
      }
      else {
        fVar7 = *(float *)(param_1 + 0x21c);
        if (fVar7 <= 0.0) {
          fVar7 = (float)FUN_1415c05d0(lVar4,0);
        }
        fVar7 = fVar7 - extraout_XMM0_Da_00;
        if (fVar7 <= 0.0) {
          fVar7 = 0.0;
        }
        (**(code **)(*plVar6 + 0xb0))(plVar6);
        fVar8 = _DAT_14382e9ec;
        if (0.0 < extraout_XMM0_Da_01) {
          fVar8 = fVar7 / extraout_XMM0_Da_01;
        }
        if ((((*(byte *)(lVar4 + 0x98) & 1) == 0) || ((*(byte *)(lVar4 + 0xa0) & 1) != 0)) ||
           ((fVar8 < *(float *)((longlong)plVar6 + 0x394) && (fVar9 < extraout_XMM0_Da_00)))) {
          *(undefined1 *)(param_1 + 0x2d3) = 0;
          return 1;
        }
      }
    }
  }
  return 0;
}


/* HeroStateSwingJumpLocal_virtual_26 @ 0x140a88130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140a88130(longlong param_1)

{
  float fVar1;
  float fVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  bool bVar5;
  char cVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  ulonglong *puVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined *puVar13;
  undefined1 uVar14;
  undefined4 uVar15;
  float fVar16;
  undefined4 auStackX_10 [2];
  float afStackX_18 [4];
  undefined8 uStack_248;
  undefined8 uStack_240;
  undefined4 uStack_238;
  float afStack_230 [2];
  float fStack_228;
  undefined1 auStack_218 [51];
  char cStack_1e5;
  undefined4 uStack_1dc;
  float fStack_1d8;
  float fStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined1 uStack_1c8;
  longlong alStack_1b8 [48];
  
  cVar6 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x4d8))(*(longlong **)(param_1 + 0x108),1)
  ;
  if (cVar6 == '\0') {
    lVar7 = FUN_1402c48c0(*(undefined8 *)(param_1 + 8));
    fVar16 = *(float *)(param_1 + 0x26c) - *(float *)(lVar7 + 4);
    FUN_140b7e920(afStack_230,*(undefined8 *)(param_1 + 8),afStackX_18,0,1,_DAT_143834794,
                  _DAT_145d9a5cc,0,0x4453c00,0x73420c96,0,1,0);
    puVar3 = *(undefined8 **)(param_1 + 8);
    puVar13 = &DAT_147afdf10;
    if ((undefined *)*puVar3 != (undefined *)0x0) {
      puVar13 = (undefined *)*puVar3;
    }
    fVar1 = *(float *)(puVar13 + 0x28);
    fVar2 = *(float *)(puVar13 + 0x20);
    if (*(short *)(puVar3 + 0x11) == 0) {
      plVar8 = (longlong *)FUN_14167ab40(puVar3 + 0xb,0x146deda80);
    }
    else {
      plVar8 = (longlong *)func_0x0001416799a0(puVar3 + 0x10,0x146deda80);
    }
    bVar5 = 0.0 < *(float *)(param_1 + 0x21c);
    cVar6 = (**(code **)(*plVar8 + 200))(plVar8);
    if ((cVar6 != '\0') || (bVar5)) {
      uVar14 = 1;
    }
    else {
      uVar14 = 0;
    }
    lVar7 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar7 + 0x88) == 0) {
      lVar7 = FUN_14167ab40(lVar7 + 0x58,0x1473d09e0);
    }
    else {
      lVar7 = func_0x0001416799a0(lVar7 + 0x80);
    }
    func_0x0001415c6440(lVar7 + 0x68,auStackX_10,0);
    lVar7 = func_0x0001415ad2a0(0x1473d0730,auStackX_10[0]);
    if ((((afStackX_18[0] < _DAT_145d9a5c4) ||
         ((*(uint *)(*(longlong *)(param_1 + 0x108) + 0x154) >> 4 & 1) != 0)) ||
        (fStack_228 * fVar1 + afStack_230[0] * fVar2 <= 0.0)) || (bVar5)) {
      FUN_140aed8e0(auStack_218);
      uStack_1dc = *(undefined4 *)(param_1 + 0x1f0);
      uStack_1d0._0_3_ = CONCAT12(bVar5,CONCAT11(uVar14,*(undefined1 *)(param_1 + 0x2c0)));
      fStack_1d8 = fVar16;
      cVar6 = func_0x00014098f950(*(undefined8 *)(param_1 + 0x108));
      cStack_1e5 = (cVar6 != '\0') + '\x01';
      if ((lVar7 != 0) &&
         (puVar10 = (ulonglong *)FUN_141d50b40(*(undefined8 *)(param_1 + 8),lVar7,0x91a6e23c),
         puVar10 != (ulonglong *)0x0)) {
        FUN_14146d8f0(alStack_1b8);
        uVar4 = *puVar10;
        if ((uVar4 & 1) == 0) {
          (**(code **)(alStack_1b8[0] + 0x48))(alStack_1b8);
        }
        else {
          (**(code **)(alStack_1b8[0] + 0x48))();
          lVar7 = (uVar4 & 0xfffffffffffffffe) + 8;
          if (lVar7 != 0) {
            uStack_248 = 0;
            uStack_240 = 0;
            uStack_238 = 0;
            func_0x000141bdb5f0(&uStack_248,lVar7,0,0);
            uVar11 = func_0x000141affb20(alStack_1b8);
            uVar12 = (**(code **)(alStack_1b8[0] + 0x38))(alStack_1b8);
            FUN_141bdd190(alStack_1b8,&uStack_248,uVar12,uVar11);
          }
        }
        FUN_1414798a0(alStack_1b8);
        func_0x00014146efa0(alStack_1b8);
      }
      cVar6 = (**(code **)(**(longlong **)(param_1 + 0x48) + 0x50))
                        (*(longlong **)(param_1 + 0x48),0x146df83a0,auStack_218);
    }
    else {
      lVar9 = *(longlong *)(param_1 + 8);
      if (*(short *)(lVar9 + 0x88) == 0) {
        lVar9 = FUN_14167ab40(lVar9 + 0x58,0x147c40bf0);
      }
      else {
        lVar9 = func_0x0001416799a0(lVar9 + 0x80);
      }
      FUN_14098f280(lVar9 + 0x2a4,&uStack_248,0,1);
      uVar15 = FUN_1402c2450(&uStack_248);
      FUN_140a84190(auStack_218);
      uStack_1c8 = (undefined1)*(undefined4 *)(param_1 + 0x2c0);
      uStack_1d0 = *(undefined4 *)(param_1 + 0x1f0);
      fStack_1d4 = fVar16;
      uStack_1cc = uVar15;
      cVar6 = func_0x00014098f950(*(undefined8 *)(param_1 + 0x108));
      uStack_1dc._0_2_ = CONCAT11((cVar6 != '\0') + '\x01',(undefined1)uStack_1dc);
      if ((lVar7 != 0) &&
         (puVar10 = (ulonglong *)FUN_141d50b40(*(undefined8 *)(param_1 + 8),lVar7,0x91a6e23c),
         puVar10 != (ulonglong *)0x0)) {
        FUN_14146d8f0(alStack_1b8);
        uVar4 = *puVar10;
        if ((uVar4 & 1) == 0) {
          (**(code **)(alStack_1b8[0] + 0x48))(alStack_1b8);
        }
        else {
          (**(code **)(alStack_1b8[0] + 0x48))();
          lVar7 = (uVar4 & 0xfffffffffffffffe) + 8;
          if (lVar7 != 0) {
            uStack_248 = 0;
            uStack_240 = 0;
            uStack_238 = 0;
            func_0x000141bdb5f0(&uStack_248,lVar7,0,0);
            uVar11 = func_0x000141affb20(alStack_1b8);
            uVar12 = (**(code **)(alStack_1b8[0] + 0x38))(alStack_1b8);
            FUN_141bdd190(alStack_1b8,&uStack_248,uVar12,uVar11);
          }
        }
        FUN_1414798a0(alStack_1b8);
        func_0x00014146efa0(alStack_1b8);
      }
      cVar6 = (**(code **)(**(longlong **)(param_1 + 0x48) + 0x50))
                        (*(longlong **)(param_1 + 0x48),0x146dee6c0,auStack_218);
    }
    if (cVar6 == '\0') {
      return 0;
    }
  }
  return 1;
}


/* HeroStateSwingJumpLocal_virtual_27 @ 0x140a885c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_140a885c0(longlong *param_1)

{
  char cVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 auStackX_8 [2];
  undefined4 uStack_b8;
  float fStack_b4;
  undefined4 uStack_b0;
  undefined8 uStack_a8;
  undefined4 uStack_a0;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_3c;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_34;
  undefined1 uStack_32;
  undefined8 uStack_30;
  undefined4 uStack_28;
  
  lVar2 = param_1[1];
  if (*(short *)(lVar2 + 0x88) == 0) {
    lVar2 = FUN_14167ab40(lVar2 + 0x58,0x1473d09e0);
  }
  else {
    lVar2 = func_0x0001416799a0(lVar2 + 0x80);
  }
  (**(code **)(*param_1 + 0x170))(param_1,&uStack_b8);
  fStack_b4 = *(float *)(param_1 + 0x3e);
  if ((*(char *)((longlong)param_1 + 0x2da) != '\0') && (_DAT_1438726d4 <= fStack_b4)) {
    fStack_b4 = _DAT_1438726d4;
  }
  fStack_b4 = fStack_b4 + 0.0;
  func_0x0001415c6440(lVar2 + 0x68,auStackX_8,0);
  puVar3 = (undefined4 *)func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
  uStack_94 = 0;
  if (puVar3 != (undefined4 *)0x0) {
    uStack_94 = *puVar3;
  }
  uVar4 = 0;
  if (*(char *)((longlong)param_1 + 0x2d3) != '\0') {
    uVar4 = uStack_94;
  }
  FUN_14098db20(&uStack_98);
  uStack_4c = (undefined4)param_1[0x58];
  uStack_48 = *(undefined4 *)((longlong)param_1 + 0x26c);
  uStack_44 = (undefined4)param_1[0x3d];
  uStack_38 = *(undefined1 *)((longlong)param_1 + 0x2cb);
  uStack_28 = *(undefined4 *)((longlong)param_1 + 0x15c);
  uStack_34 = *(undefined1 *)((longlong)param_1 + 0x2d9);
  uStack_32 = *(undefined1 *)((longlong)param_1 + 0x2da);
  uStack_30 = *(undefined8 *)((longlong)param_1 + 0x154);
  uStack_3c = *(undefined4 *)((longlong)param_1 + 0x1e4);
  uStack_37 = 0;
  uStack_98 = uVar4;
  (**(code **)(*param_1 + 0xe0))(param_1,&uStack_98);
  uStack_a8 = CONCAT44(fStack_b4,uStack_b8);
  uStack_a0 = uStack_b0;
  cVar1 = (**(code **)(*(longlong *)param_1[0x21] + 0xa0))
                    ((longlong *)param_1[0x21],&uStack_a8,1,&uStack_98);
  return cVar1 != '\0';
}


/* HeroStateSwingJumpLocal_virtual_28 @ 0x140a143d0 */

void HeroStateSwingJumpLocal_virtual_28(void)

{
  return;
}


/* HeroStateSwingJumpLocal_virtual_29 @ 0x140a143e0 */

void HeroStateSwingJumpLocal_virtual_29(void)

{
  return;
}


/* HeroStateSwingJumpLocal_virtual_30 @ 0x140a88750 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140a88750(longlong param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  float extraout_XMM0_Da;
  float extraout_XMM0_Da_00;
  undefined1 auStack_58 [12];
  undefined4 uStack_4c;
  undefined4 uStack_40;
  
  plVar2 = (longlong *)func_0x0001409c87f0();
  (**(code **)(*plVar2 + 0xd0))(plVar2);
  if (_DAT_14382dce0 <= extraout_XMM0_Da) {
    FUN_1420dc660(param_1);
    if (_DAT_14382ee88 <= extraout_XMM0_Da_00) {
      lVar3 = *(longlong *)(param_1 + 8);
      if (*(short *)(lVar3 + 0x88) == 0) {
        lVar3 = FUN_14167ab40(lVar3 + 0x58,0x147c40bf0);
      }
      else {
        lVar3 = func_0x0001416799a0(lVar3 + 0x80);
      }
      if (_DAT_14382f0e4 < *(float *)(lVar3 + 0x6b8) || _DAT_14382f0e4 == *(float *)(lVar3 + 0x6b8))
      {
        func_0x0001408687b0(auStack_58);
        uStack_4c = *(undefined4 *)(param_1 + 0x2c0);
        uStack_40 = *(undefined4 *)(param_1 + 0x1e0);
        cVar1 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x5a8))
                          (*(longlong **)(param_1 + 0x108),auStack_58,0,0);
        if (cVar1 != '\0') {
          return 1;
        }
      }
    }
  }
  return 0;
}


/* HeroStateSwingJumpLocal_virtual_31 @ 0x140a88820 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140a88820(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  longlong *plVar4;
  undefined4 uVar5;
  undefined4 extraout_XMM0_Da;
  
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    plVar4 = (longlong *)FUN_14167ab40(lVar2 + 0x58,0x146dd80e0);
  }
  else {
    plVar4 = (longlong *)func_0x0001416799a0(lVar2 + 0x80);
  }
  uVar1 = *(uint *)(param_1 + 0x2c0);
  if ((2 < uVar1) && (uVar1 != 0x30)) {
    uVar5 = _DAT_14382e13c;
    if (uVar1 == 0x12) {
      uVar5 = FUN_1420dc660(param_1);
      func_0x00014041c590(uVar5,_DAT_14382e120,_DAT_14383fd4c);
      uVar5 = extraout_XMM0_Da;
    }
    if (*(char *)(param_1 + 0x2d1) == '\0') {
      cVar3 = (**(code **)(*plVar4 + 0x480))(plVar4,uVar5,0,_DAT_143840030,0);
      if (cVar3 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}


/* HeroStateSwingJumpLocal_virtual_32 @ 0x140a888e0 */

undefined8 FUN_140a888e0(longlong param_1)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  
  if ((*(char *)(param_1 + 0x2d5) == '\0') && (*(char *)(param_1 + 0x2da) == '\0')) {
    lVar3 = func_0x00014098f500(*(undefined8 *)(param_1 + 0x108));
    if ((lVar3 != 0) && (iVar2 = func_0x00014085fb90(lVar3), iVar2 == 2)) {
      return 0;
    }
    cVar1 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x2a8))();
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


/* HeroStateSwingJumpLocal_virtual_33 @ 0x140a88940 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_140a88940(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  float fVar10;
  float fVar11;
  undefined4 auStackX_8 [2];
  
  lVar4 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    lVar4 = FUN_14167ab40(lVar4 + 0x58,0x147c40bf0);
  }
  else {
    lVar4 = func_0x0001416799a0(lVar4 + 0x80);
  }
  lVar6 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar6 + 0x88) == 0) {
    uVar5 = FUN_14167ab40(lVar6 + 0x58,0x1473d09e0);
  }
  else {
    uVar5 = func_0x0001416799a0(lVar6 + 0x80);
  }
  lVar6 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar6 + 0x88) == 0) {
    lVar6 = FUN_14167ab40(lVar6 + 0x58,0x146deda80);
  }
  else {
    lVar6 = func_0x0001416799a0(lVar6 + 0x80);
  }
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    uVar7 = FUN_14167ab40(lVar1 + 0x58,0x146dacd70);
  }
  else {
    uVar7 = func_0x0001416799a0(lVar1 + 0x80);
  }
  iVar3 = func_0x00014085fb90(uVar7);
  fVar10 = *(float *)(lVar4 + 0x428);
  fVar11 = *(float *)(lVar4 + 0x42c);
  uVar8 = 0x7855324c;
  if (iVar3 == 2) {
    uVar8 = 0xb183da55;
  }
  uVar9 = 0;
  cVar2 = FUN_14098f9a0(*(undefined8 *)(param_1 + 0x108));
  if ((cVar2 == '\0') && (_DAT_145d9f878 < fVar10 - fVar11)) {
    FUN_1415c2240(uVar5,auStackX_8,uVar8,0);
    lVar4 = func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
    if (lVar4 != 0) {
      fVar10 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar4,0xa2db0e32);
      if (0.0 <= fVar10) {
        fVar11 = (float)func_0x0001416769f0(param_1);
        uVar9 = 0;
        if (*(float *)(lVar6 + 0x398) <= fVar11 + fVar10) {
          uVar9 = 1;
        }
      }
    }
    func_0x0001415c0440(uVar5,auStackX_8[0]);
  }
  cVar2 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x508))
                    (*(longlong **)(param_1 + 0x108),uVar8,1,uVar9);
  return cVar2 != '\0';
}


/* HeroStateSwingJumpLocal_virtual_35 @ 0x140a88b50 */

undefined8 HeroStateSwingJumpLocal_virtual_35(void)

{
  return 4;
}


/* HeroStateSwingJumpLocal_virtual_36 @ 0x140a88b60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140a88b60(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  ulonglong *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 auStackX_8 [2];
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined4 uStack_1d8;
  longlong alStack_1c8 [40];
  undefined4 uStack_84;
  undefined4 uStack_74;
  undefined4 uStack_64;
  undefined4 uStack_54;
  undefined4 uStack_44;
  undefined4 uStack_34;
  char cStack_30;
  char cStack_2f;
  
  if (*(char *)(param_1 + 0x2d2) == '\0') {
    *(undefined1 *)(param_1 + 0x2d2) = 1;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0x4ca735f3,0);
    *(undefined4 *)(param_1 + 0x1f8) = uVar7;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0x3bff28c9,0);
    *(undefined4 *)(param_1 + 0x200) = uVar7;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0xa47f1d9e,0);
    *(undefined4 *)(param_1 + 0x208) = uVar7;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0xbdcdbce5,0);
    *(undefined4 *)(param_1 + 0x20c) = uVar7;
    fVar8 = (float)FUN_141d50c00(*(undefined8 *)(param_1 + 8),0x71677b99,0);
    fVar10 = *(float *)(param_1 + 0x20c);
    fVar9 = fVar10;
    if ((0.0 <= fVar8) && (fVar9 = fVar8, fVar10 <= fVar8)) {
      fVar9 = fVar10;
    }
    *(float *)(param_1 + 0x210) = fVar9;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0xae16face,0);
    *(undefined4 *)(param_1 + 0x214) = uVar7;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0x85074850,0);
    *(undefined4 *)(param_1 + 0x21c) = uVar7;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0x9bae7439,0);
    *(undefined4 *)(param_1 + 0x244) = uVar7;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0xbbdfd32d,0);
    *(undefined4 *)(param_1 + 0x204) = uVar7;
    uVar7 = FUN_141d50c00(*(undefined8 *)(param_1 + 8),0x6d366ecc,0);
    *(undefined4 *)(param_1 + 0x218) = uVar7;
    fVar10 = *(float *)(param_1 + 0x244);
    if (fVar10 < 0.0) {
      fVar10 = *(float *)(param_1 + 0x1f8) * _DAT_143834a04;
    }
    *(float *)(param_1 + 0x244) = fVar10;
    *(undefined4 *)(param_1 + 0x248) = 0;
    *(undefined8 *)(param_1 + 0x22c) = 0;
    *(undefined8 *)(param_1 + 0x234) = 0;
    *(undefined8 *)(param_1 + 0x23c) = 0;
    *(undefined2 *)(param_1 + 0x24c) = 0;
    lVar2 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar2 + 0x88) == 0) {
      lVar2 = FUN_14167ab40(lVar2 + 0x58,0x1473d09e0);
    }
    else {
      lVar2 = func_0x0001416799a0(lVar2 + 0x80);
    }
    func_0x0001415c6440(lVar2 + 0x68,auStackX_8,0);
    puVar3 = (undefined4 *)func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = (ulonglong *)FUN_141d50b40(*(undefined8 *)(param_1 + 8),puVar3,0xf1342eac);
      if (puVar4 != (ulonglong *)0x0) {
        FUN_14146db20(alStack_1c8);
        uVar1 = *puVar4;
        if ((uVar1 & 1) == 0) {
          (**(code **)(alStack_1c8[0] + 0x48))(alStack_1c8);
        }
        else {
          (**(code **)(alStack_1c8[0] + 0x48))();
          lVar2 = (uVar1 & 0xfffffffffffffffe) + 8;
          if (lVar2 != 0) {
            uStack_1e8 = 0;
            uStack_1e0 = 0;
            uStack_1d8 = 0;
            func_0x000141bdb5f0(&uStack_1e8,lVar2,0,0);
            uVar5 = func_0x000141affb20(alStack_1c8);
            uVar6 = (**(code **)(alStack_1c8[0] + 0x38))(alStack_1c8);
            FUN_141bdd190(alStack_1c8,&uStack_1e8,uVar6,uVar5);
          }
        }
        *(undefined4 *)(param_1 + 0x22c) = uStack_84;
        *(undefined4 *)(param_1 + 0x230) = uStack_74;
        *(undefined4 *)(param_1 + 0x234) = uStack_64;
        *(undefined4 *)(param_1 + 0x238) = uStack_54;
        *(undefined4 *)(param_1 + 0x23c) = uStack_44;
        *(undefined4 *)(param_1 + 0x240) = uStack_34;
        *(bool *)(param_1 + 0x24c) = cStack_30 != '\0';
        *(bool *)(param_1 + 0x24d) = cStack_2f != '\0';
        FUN_141479990(alStack_1c8);
        func_0x00014146f050(alStack_1c8);
      }
      *(undefined4 *)(param_1 + 0x248) = *puVar3;
      fVar10 = *(float *)(param_1 + 0x1f8);
      if (fVar10 < 0.0) {
        fVar10 = (float)puVar3[0xc0] * _DAT_14382e128;
      }
      *(float *)(param_1 + 0x1f8) = fVar10;
    }
  }
  return;
}


/* HeroStateSwingJumpLocal_virtual_37 @ 0x140a88ec0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140a88ec0(longlong *param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  uint uVar4;
  char cVar5;
  longlong *plVar6;
  float *pfVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  byte *pbVar11;
  longlong lVar12;
  longlong lVar13;
  ulonglong *puVar14;
  byte bVar15;
  longlong *plVar16;
  ulonglong uVar17;
  undefined *puVar18;
  ulonglong uVar19;
  longlong unaff_GS_OFFSET;
  float fVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  undefined1 auStackX_8 [8];
  undefined1 auStackX_18 [8];
  float afStackX_20 [2];
  undefined8 in_stack_fffffffffffff468;
  undefined8 uVar30;
  undefined1 *puVar31;
  undefined8 in_stack_fffffffffffff478;
  undefined4 uVar32;
  undefined8 in_stack_fffffffffffff480;
  undefined4 uVar33;
  float fStack_b48;
  float fStack_b44;
  float fStack_b40;
  undefined8 uStack_b38;
  float fStack_b30;
  undefined8 uStack_b28;
  float fStack_b20;
  float fStack_b18;
  float fStack_b14;
  float fStack_b10;
  ulonglong uStack_b08;
  float fStack_b00;
  float fStack_af8;
  float fStack_af4;
  float fStack_af0;
  float fStack_aec;
  float fStack_ae8;
  float fStack_ae4;
  float fStack_ae0;
  undefined8 uStack_ad8;
  undefined4 uStack_ad0;
  undefined4 uStack_ac8;
  undefined4 uStack_ac4;
  ulonglong uStack_ac0;
  undefined4 uStack_ab8;
  undefined1 auStack_ab0 [8];
  undefined8 uStack_aa8;
  undefined8 uStack_aa0;
  undefined8 uStack_a98;
  undefined8 uStack_a90;
  undefined8 uStack_a88;
  undefined8 uStack_a80;
  undefined8 uStack_a68;
  undefined8 uStack_a60;
  undefined1 auStack_a58 [4];
  undefined4 uStack_a54;
  undefined4 uStack_a50;
  undefined4 uStack_a4c;
  float fStack_a48;
  undefined1 auStack_9d8 [4];
  undefined1 auStack_9d4 [16];
  float fStack_9c4;
  float fStack_9c0;
  float fStack_9bc;
  longlong alStack_958 [130];
  undefined1 auStack_548 [32];
  undefined8 uStack_528;
  longlong alStack_518 [130];
  undefined1 auStack_108 [32];
  undefined8 uStack_e8;
  
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffff480 >> 0x20);
  uVar32 = (undefined4)((ulonglong)in_stack_fffffffffffff478 >> 0x20);
  uVar21 = (undefined4)((ulonglong)in_stack_fffffffffffff468 >> 0x20);
  lVar12 = param_1[1];
  if (*(short *)(lVar12 + 0x88) == 0) {
    plVar6 = (longlong *)FUN_14167ab40(lVar12 + 0x58,0x147c40bf0);
  }
  else {
    plVar6 = (longlong *)func_0x0001416799a0(lVar12 + 0x80);
  }
  lVar12 = param_1[1];
  if (*(short *)(lVar12 + 0x88) == 0) {
    FUN_14167ab40(lVar12 + 0x58,0x146dabca0);
  }
  else {
    func_0x0001416799a0(lVar12 + 0x80);
  }
  plVar16 = (longlong *)param_1[1];
  puVar10 = (undefined8 *)&DAT_147afdf10;
  if ((undefined8 *)*plVar16 != (undefined8 *)0x0) {
    puVar10 = (undefined8 *)*plVar16;
  }
  uStack_a98 = puVar10[2];
  uStack_a90 = puVar10[3];
  uStack_aa8 = *puVar10;
  uStack_aa0 = puVar10[1];
  uStack_ad8 = puVar10[4];
  uStack_a80 = puVar10[5];
  uStack_ad0 = (undefined4)uStack_a80;
  uStack_ac8 = uStack_ad0;
  uStack_a88 = uStack_ad8;
  uStack_a68 = uStack_ad8;
  uStack_a60 = uStack_a80;
  if (*plVar16 == 0) {
    if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)__tls_index * 8)
                 + 0xa0a0) < _DAT_146c6675c) &&
       (FUN_143636f50(&DAT_146c6675c), _DAT_146c6675c == -1)) {
      _DAT_146c66750 = 0xc9800000;
      _DAT_146c66754 = 0xc9800000;
      _DAT_146c66758 = 0xc9800000;
      FUN_143636ef0(&DAT_146c6675c);
    }
    plVar16 = (longlong *)param_1[1];
    pfVar7 = (float *)&DAT_146c66754;
  }
  else {
    pfVar7 = (float *)(*plVar16 + 0x34);
  }
  fVar20 = *pfVar7;
  if ((short)plVar16[0x11] == 0) {
    uVar8 = FUN_14167ab40(plVar16 + 0xb,0x1473d09e0);
  }
  else {
    uVar8 = func_0x0001416799a0(plVar16 + 0x10,0x1473d09e0);
  }
  lVar12 = param_1[1];
  if (*(short *)(lVar12 + 0x88) == 0) {
    uVar9 = FUN_14167ab40(lVar12 + 0x58,0x146dacd70);
  }
  else {
    uVar9 = func_0x0001416799a0(lVar12 + 0x80);
  }
  if (0.0 < *(float *)((longlong)param_1 + 0x204) || *(float *)((longlong)param_1 + 0x204) == 0.0) {
    func_0x0001404af490(uVar8,auStack_9d8);
    puVar10 = (undefined8 *)FUN_141c5b320(&fStack_b48,&uStack_ad8,auStack_9d4);
    uStack_ad8 = *puVar10;
    uStack_ad0 = *(undefined4 *)(puVar10 + 1);
    fStack_b20 = fStack_9c4 * (float)uStack_aa0 + fStack_9c0 * (float)uStack_a90 +
                 fStack_9bc * (float)uStack_a80;
    uStack_b28 = CONCAT44(fStack_9c4 * uStack_aa8._4_4_ + fStack_9c0 * uStack_a98._4_4_ +
                          fStack_9bc * uStack_a88._4_4_,
                          fStack_9c4 * (float)uStack_aa8 + fStack_9c0 * (float)uStack_a98 +
                          fStack_9bc * (float)uStack_a88);
    FUN_140861020(param_1[1],&uStack_b28,&uStack_ad8,0);
    alStack_518[0] = param_1[0x1e];
    FUN_141c649a0(auStack_108,0,0x20);
    uStack_e8 = 0;
    pbVar11 = (byte *)FUN_141bcf3e0(alStack_518[0] + 0x10,0xcb86ef8f);
    uVar19 = 0xffffffff;
    if (pbVar11 == (byte *)0x0) {
      uVar17 = 0xffffffff;
    }
    else {
      uVar17 = (ulonglong)*pbVar11;
    }
    FUN_141f9e0e0(alStack_518,uVar17,&uStack_b28,0xc);
    pbVar11 = (byte *)FUN_141bcf3e0(alStack_518[0] + 0x10,0xb37847ee);
    if (pbVar11 == (byte *)0x0) {
      uVar17 = 0xffffffff;
    }
    else {
      uVar17 = (ulonglong)*pbVar11;
    }
    FUN_141f9e0e0(alStack_518,uVar17,&uStack_ad8,0xc);
    auStackX_18[0] = 1;
    pbVar11 = (byte *)FUN_141bcf3e0(alStack_518[0] + 0x10,0x7a248ff0);
    if (pbVar11 != (byte *)0x0) {
      uVar19 = (ulonglong)*pbVar11;
    }
    FUN_141f9e0e0(alStack_518,uVar19,auStackX_18,1);
    FUN_1420e0880(param_1,alStack_518);
    return;
  }
  fVar25 = *(float *)((longlong)param_1 + 0x26c);
  if (*(float *)((longlong)param_1 + 0x26c) <= fVar20) {
    fVar25 = fVar20;
  }
  *(float *)((longlong)param_1 + 0x26c) = fVar25;
  (**(code **)(*param_1 + 0x168))(param_1,&fStack_b18);
  if ((*(char *)((longlong)plVar6 + 0x43d) == '\0') ||
     (*(char *)((longlong)param_1 + 0x2ca) == '\0')) {
    fStack_b40 = 0.0;
    uVar22 = 0;
    param_1[0x2f] = 0;
    *(undefined1 *)(param_1 + 0x32) = 0;
  }
  else {
    bVar15 = *(byte *)(param_1 + 0x32);
    pfVar7 = (float *)(param_1 + 0x2f);
    if (bVar15 < 2) {
      fStack_b40 = *(float *)((longlong)param_1 + 0x18c) - fStack_b10;
      *(ulonglong *)pfVar7 =
           CONCAT44(*(float *)(param_1 + 0x31) - fStack_b14,
                    *(float *)((longlong)param_1 + 0x184) - fStack_b18);
      *(float *)(param_1 + 0x30) = fStack_b40;
      fVar20 = _DAT_14382e130;
      if (bVar15 == 0) {
        fVar25 = *(float *)(param_1 + 0x30) * _DAT_14382e130;
        *pfVar7 = *pfVar7 * _DAT_14382e130;
        *(float *)(param_1 + 0x30) = fVar25;
        *(float *)((longlong)param_1 + 0x17c) = *(float *)((longlong)param_1 + 0x17c) * fVar20;
        bVar15 = *(byte *)(param_1 + 0x32);
      }
      *(byte *)(param_1 + 0x32) = bVar15 + 1;
      goto LAB_140a89395;
    }
    uVar30 = CONCAT44(uVar21,param_2);
    uStack_b28 = 0;
    fStack_b20 = 0.0;
    puVar10 = (undefined8 *)FUN_141c47af0(&fStack_b48,pfVar7,&uStack_b28,_DAT_1438388d0,uVar30);
    uVar21 = (undefined4)((ulonglong)uVar30 >> 0x20);
    *(undefined8 *)pfVar7 = *puVar10;
    uVar22 = *(undefined4 *)(puVar10 + 1);
  }
  *(undefined4 *)(param_1 + 0x30) = uVar22;
LAB_140a89395:
  pfVar7 = (float *)(param_1 + 0x2f);
  fStack_b18 = fStack_b18 + *pfVar7;
  fStack_b14 = fStack_b14 + *(float *)((longlong)param_1 + 0x17c);
  lVar12 = param_1[1];
  fStack_b10 = fStack_b10 + *(float *)(param_1 + 0x30);
  if (*(short *)(lVar12 + 0x88) == 0) {
    lVar12 = FUN_14167ab40(lVar12 + 0x58,0x147c40bf0);
  }
  else {
    lVar12 = func_0x0001416799a0(lVar12 + 0x80);
  }
  pfVar1 = (float *)((longlong)param_1 + 0x154);
  fVar20 = (float)FUN_1402c2450(pfVar1);
  if ((_DAT_143830ee8 < fVar20) && (*(char *)(lVar12 + 0x43d) != '\0')) {
    fVar20 = (float)*(undefined8 *)(lVar12 + 0x3dc);
    uStack_b28._4_4_ = (float)((ulonglong)*(undefined8 *)(lVar12 + 0x3dc) >> 0x20);
    fVar25 = *pfVar1 * fVar20 + *(float *)(param_1 + 0x2b) * uStack_b28._4_4_ +
             *(float *)((longlong)param_1 + 0x15c) * *(float *)(lVar12 + 0x3e4);
    fStack_b40 = *(float *)((longlong)param_1 + 0x15c) - fVar25 * *(float *)(lVar12 + 0x3e4);
    *(ulonglong *)pfVar1 =
         CONCAT44(*(float *)(param_1 + 0x2b) - fVar25 * uStack_b28._4_4_,*pfVar1 - fVar25 * fVar20);
    *(float *)((longlong)param_1 + 0x15c) = fStack_b40;
  }
  param_1[0x2c] = *(longlong *)pfVar1;
  *(undefined4 *)(param_1 + 0x2d) = *(undefined4 *)((longlong)param_1 + 0x15c);
  uStack_b28 = 0;
  fStack_b20 = 0.0;
  puVar10 = (undefined8 *)
            FUN_141c47730(&fStack_b48,pfVar1,&uStack_b28,*(undefined4 *)((longlong)param_1 + 0x224),
                          CONCAT44(uVar21,param_2));
  *(undefined8 *)pfVar1 = *puVar10;
  *(undefined4 *)((longlong)param_1 + 0x15c) = *(undefined4 *)(puVar10 + 1);
  fStack_b18 = fStack_b18 - *(float *)(param_1 + 0x2c);
  fStack_b14 = fStack_b14 - *(float *)((longlong)param_1 + 0x164);
  fStack_b10 = fStack_b10 - *(float *)(param_1 + 0x2d);
  lVar12 = FUN_141fc2070(plVar6);
  lVar13 = func_0x0001415a0560((longlong)plVar6 + 0x19c);
  if ((lVar12 == 0) || (lVar13 != lVar12)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((*(char *)((longlong)param_1 + 0x191) != '\0') && (cVar5 == '\0')) {
    (**(code **)(*plVar6 + 0x80))(plVar6,&uStack_b28,0);
    (**(code **)(*plVar6 + 0x80))(plVar6,&fStack_b48,1);
    *pfVar1 = (float)uStack_b28 - fStack_b48;
    *(float *)(param_1 + 0x2b) = uStack_b28._4_4_ - fStack_b44;
    *(float *)((longlong)param_1 + 0x15c) = fStack_b20 - fStack_b40;
  }
  lVar12 = param_1[1];
  *(char *)((longlong)param_1 + 0x191) = cVar5;
  if (*(short *)(lVar12 + 0x88) == 0) {
    lVar12 = FUN_14167ab40(lVar12 + 0x58,0x146dd6030);
  }
  else {
    lVar12 = func_0x0001416799a0(lVar12 + 0x80);
  }
  *(undefined8 *)(lVar12 + 0x144) = *(undefined8 *)pfVar1;
  *(undefined4 *)(lVar12 + 0x14c) = *(undefined4 *)((longlong)param_1 + 0x15c);
  (**(code **)(*param_1 + 0xb0))(param_1,param_2);
  puVar31 = auStack_ab0;
  *(int *)((longlong)param_1 + 0x1ec) = (int)param_1[0x3e];
  (**(code **)(*param_1 + 0xa0))(param_1,&uStack_ac4,&fStack_af0,&fStack_af4,puVar31,param_2);
  uStack_b38 = param_1[0x26];
  fStack_b30 = *(float *)(param_1 + 0x27);
  afStackX_20[0] = *(float *)((longlong)param_1 + 0x1dc);
  uVar19 = (ulonglong)puVar31 & 0xffffffff00000000;
  fVar20 = (float)FUN_140b7e2e0(param_1[1],0,0x4453c00,0x73420c96,uVar19);
  if ((*(uint *)(param_1[0x21] + 0x154) >> 4 & 1) == 0) {
    if (_DAT_143830118 <= fVar20) {
      fVar25 = _DAT_14382f0e0;
      if (0.0 <= *(float *)(param_1 + 0x5e)) {
        fVar25 = *(float *)(param_1 + 0x5e) + param_2;
      }
    }
    else {
      fVar25 = 0.0;
    }
  }
  else {
    fVar20 = 0.0;
    fVar25 = 0.0;
  }
  *(float *)(param_1 + 0x5e) = fVar25;
  if (*(char *)((longlong)param_1 + 0x2ca) == '\0') {
    uVar21 = FUN_1415c05d0(uVar8,0);
    FUN_1415c0080(uVar8,auStack_a58,0,uVar21);
    param_1[0x36] = CONCAT44(uStack_a50,uStack_a54);
    param_1[0x37] = CONCAT44(fStack_a48,uStack_a4c);
  }
  uVar21 = FUN_1415c05d0(uVar8,0);
  uVar22 = FUN_1415c09c0(uVar8,0);
  FUN_1415c0080(uVar8,auStack_a58,uVar22,uVar21);
  pfVar1 = (float *)(param_1 + 0x36);
  *(undefined4 *)(param_1 + 0x34) = uStack_a54;
  *(undefined4 *)(param_1 + 0x35) = uStack_a4c;
  uVar4 = _DAT_14382e890;
  *(undefined4 *)((longlong)param_1 + 0x1a4) = uStack_a50;
  *(float *)((longlong)param_1 + 0x1ac) = fStack_a48;
  fVar29 = (float)(*(uint *)(param_1 + 0x35) ^ uVar4);
  fVar27 = (float)(*(uint *)(param_1 + 0x34) ^ uVar4);
  fVar25 = *(float *)((longlong)param_1 + 0x1bc);
  fVar28 = (float)(*(uint *)((longlong)param_1 + 0x1a4) ^ uVar4);
  fVar2 = *pfVar1;
  fVar24 = *(float *)(param_1 + 0x37);
  fVar26 = *(float *)((longlong)param_1 + 0x1b4);
  fVar23 = _DAT_14382dce0 /
           (fStack_a48 * fStack_a48 + fVar29 * fVar29 + fVar28 * fVar28 + fVar27 * fVar27);
  fStack_a48 = fStack_a48 * fVar23;
  fVar28 = fVar28 * fVar23;
  fVar27 = fVar27 * fVar23;
  fVar29 = fVar29 * fVar23;
  *(float *)(param_1 + 0x38) =
       ((fVar2 * fStack_a48 + fVar25 * fVar27) - fVar24 * fVar28) + fVar26 * fVar29;
  *(float *)((longlong)param_1 + 0x1c4) =
       (fVar26 * fStack_a48 + fVar24 * fVar27 + fVar25 * fVar28) - fVar2 * fVar29;
  *(float *)(param_1 + 0x39) =
       (fVar24 * fStack_a48 - fVar26 * fVar27) + fVar2 * fVar28 + fVar25 * fVar29;
  *(float *)((longlong)param_1 + 0x1cc) =
       ((fVar25 * fStack_a48 - fVar2 * fVar27) - fVar26 * fVar28) - fVar24 * fVar29;
  if ((*(char *)((longlong)param_1 + 0x2ca) == '\0') &&
     ((1 < (int)param_1[0x58] - 0xbU || (*(int *)((longlong)param_1 + 0x2c4) == 0x35)))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  cVar5 = (**(code **)(*param_1 + 0x150))(param_1);
  if ((cVar5 != '\0') && (bVar3)) {
    uVar33 = 0;
    uVar8 = CONCAT44(uVar32,_DAT_145d9a5cc);
    uVar19 = CONCAT71((int7)(uVar19 >> 8),1);
    plVar6 = (longlong *)
             FUN_140b7e920(&fStack_b48,param_1[1],0,0,uVar19,_DAT_143834794,uVar8,0,0x4453c00,
                           0x73420c96,0,1,0);
    uVar32 = (undefined4)((ulonglong)uVar8 >> 0x20);
    lVar12 = *plVar6;
    uStack_b38._0_4_ = (float)lVar12;
    fStack_b30 = *(float *)(plVar6 + 1);
    afStackX_20[0] = fVar20;
    if (((float)uStack_b38 == 0.0) &&
       ((uStack_b38._4_4_ = (float)((ulonglong)lVar12 >> 0x20), uStack_b38._4_4_ == 0.0 &&
        (fStack_b30 == 0.0)))) {
      afStackX_20[0] = 0.0;
    }
    uStack_b38 = lVar12;
    FUN_140b8a190(param_1[1],&uStack_b38);
  }
  fVar2 = _DAT_143830118;
  uVar4 = _DAT_14382e160;
  fVar25 = _DAT_14382dce0;
  fVar23 = 0.0;
  fVar26 = (float)((uint)fStack_b10 & _DAT_14382e160);
  fVar24 = (float)((uint)fStack_b14 & _DAT_14382e160);
  if ((float)((uint)fStack_b14 & _DAT_14382e160) <= fVar26) {
    fVar24 = fVar26;
  }
  fVar27 = (float)((uint)fStack_b18 & _DAT_14382e160);
  if (fVar24 <= fVar27) {
    fVar24 = fVar27;
  }
  fVar28 = _DAT_14382dce0 / fVar24;
  if (0.0 < fVar24) {
    fVar23 = SQRT(fVar28 * fStack_b14 * fVar28 * fStack_b14 +
                  fVar28 * fStack_b18 * fVar28 * fStack_b18 +
                  fVar28 * fStack_b10 * fVar28 * fStack_b10) * fVar24;
  }
  if (afStackX_20[0] < _DAT_143830118) {
    if (fVar26 <= fVar27) {
      fVar26 = fVar27;
    }
    fVar24 = (_DAT_14382dce0 / fVar26) * fStack_b10;
    fVar27 = (_DAT_14382dce0 / fVar26) * fStack_b18;
    if ((fVar26 <= 0.0) || (SQRT(fVar24 * fVar24 + fVar27 * fVar27) * fVar26 <= _DAT_143830118)) {
      uStack_b38 = uStack_a68;
      fStack_b30 = (float)uStack_ac8;
    }
    else {
      fStack_b48 = fStack_b18;
      fStack_b40 = fStack_b10;
      fStack_b44 = 0.0;
      puVar10 = (undefined8 *)FUN_1402d0740(&uStack_b28,&fStack_b48);
      uStack_b38 = *puVar10;
      fStack_b30 = (float)*(undefined4 *)(puVar10 + 1);
    }
    plVar6 = (longlong *)FUN_141c5b320(&fStack_b48,&uStack_b38,pfVar1);
    uStack_b38 = *plVar6;
    fStack_b30 = *(float *)(plVar6 + 1);
  }
  uVar8 = FUN_141676930(param_1);
  FUN_140860840(uVar9,uVar8,&uStack_b38,afStackX_20,uVar19 & 0xffffffffffffff00);
  uVar21 = (**(code **)(*param_1 + 0x180))
                     (param_1,&uStack_b38,afStackX_20[0],uStack_ac4,fStack_af0,fStack_af4,
                      CONCAT44(uVar32,param_2));
  fStack_af8 = 0.0;
  uVar21 = (**(code **)(*param_1 + 0x188))
                     (param_1,&uStack_b38,afStackX_20[0],uVar21,&fStack_b18,param_2,&fStack_af8);
  if (fStack_af8 <= fStack_af4) {
    fStack_af8 = fStack_af4;
  }
  if (fStack_af8 <= fStack_af0) {
    fStack_af8 = fStack_af0;
  }
  if (fStack_af4 <= fStack_af8) {
    fStack_af4 = fStack_af8;
  }
  (**(code **)(*param_1 + 0x1a0))
            (param_1,&fStack_ae8,&uStack_b38,afStackX_20[0],&fStack_b18,uVar21,fStack_af4,
             CONCAT44(uVar33,param_2));
  if ((*(char *)((longlong)param_1 + 0x2ce) != '\0') &&
     (lVar12 = func_0x0001416798f0(param_1 + 0x4f), lVar12 != 0)) {
    FUN_14084ea70(lVar12,&fStack_ae8);
  }
  cVar5 = (**(code **)(*param_1 + 0x1b0))(param_1);
  if (cVar5 == '\0') {
    fStack_b40 = fVar25 / param_2;
    fStack_b48 = fStack_b40 * fStack_ae8;
    fStack_b44 = fStack_b40 * fStack_ae4;
    fStack_b40 = fStack_b40 * fStack_ae0;
    puVar10 = (undefined8 *)
              (**(code **)(*param_1 + 0x1a8))
                        (param_1,&uStack_b28,&uStack_b38,afStackX_20[0],&fStack_b48);
    uStack_b08._0_4_ = (float)*puVar10;
    fStack_b00 = *(float *)(puVar10 + 1);
  }
  else {
    fStack_b00 = *(float *)((longlong)param_1 + 300);
    uStack_b08._0_4_ = (float)*(undefined8 *)((longlong)param_1 + 0x124);
  }
  fVar24 = (float)uStack_b08;
  uStack_b08 = (ulonglong)(uint)(float)uStack_b08;
  if (fVar24 * fVar24 + fStack_b00 * fStack_b00 <= _DAT_143830ee8) {
    puVar18 = &DAT_147afdf10;
    if (*(undefined **)param_1[1] != (undefined *)0x0) {
      puVar18 = *(undefined **)param_1[1];
    }
    puVar14 = (ulonglong *)FUN_141c5b320(&fStack_b48,puVar18 + 0x20,pfVar1);
  }
  else {
    puVar14 = (ulonglong *)FUN_1402d0740(&fStack_b48,&uStack_b08);
  }
  uStack_b08 = *puVar14;
  fStack_b00 = (float)puVar14[1];
  auStackX_8[0] = 0;
  (**(code **)(*param_1 + 0x160))(param_1,&uStack_b08,auStackX_8);
  if (*(float *)(param_1 + 0x3e) <= 0.0 && *(float *)(param_1 + 0x3e) != 0.0) {
    *(float *)(param_1 + 0x3d) = (float)_DAT_147a7fbd8 + *(float *)(param_1 + 0x3d);
    fVar24 = (float)FUN_1420dc660(param_1);
    if (*(float *)((longlong)param_1 + 0x1fc) <= fVar24 &&
        fVar24 != *(float *)((longlong)param_1 + 0x1fc)) {
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)((longlong)param_1 + 0x1e4);
      cVar5 = func_0x000140860600(uVar9);
      if ((cVar5 != '\0') || ((char)param_1[0x45] != '\0')) {
        uVar21 = func_0x00014085fba0(uVar9);
        *(undefined4 *)((longlong)param_1 + 0x1e4) = uVar21;
        *(undefined4 *)(param_1 + 0x3c) = uVar21;
        *(undefined1 *)(param_1 + 0x45) = 1;
      }
    }
  }
  fStack_aec = fVar20;
  if (fStack_af0 < fVar23) {
    fStack_aec = afStackX_20[0];
  }
  uStack_ac0 = uStack_b08;
  *(float *)((longlong)param_1 + 0x2f4) = fStack_aec;
  uStack_ab8 = fStack_b00;
  cVar5 = FUN_140861020(param_1[1],&fStack_ae8,&uStack_ac0,0);
  if ((cVar5 != '\0') && (cVar5 = func_0x000140860750(uVar9), cVar5 != '\0')) {
    fStack_b00 = (float)uStack_ab8;
    uStack_b08 = uStack_ac0;
  }
  alStack_958[0] = param_1[0x1e];
  FUN_141c649a0(auStack_548,0,0x20);
  uStack_528 = 0;
  pbVar11 = (byte *)FUN_141bcf3e0(alStack_958[0] + 0x10,0xcb86ef8f);
  uVar19 = 0xffffffff;
  if (pbVar11 == (byte *)0x0) {
    uVar17 = 0xffffffff;
  }
  else {
    uVar17 = (ulonglong)*pbVar11;
  }
  FUN_141f9e0e0(alStack_958,uVar17,&fStack_ae8,0xc);
  pbVar11 = (byte *)FUN_141bcf3e0(alStack_958[0] + 0x10,0xb37847ee);
  if (pbVar11 == (byte *)0x0) {
    uVar17 = 0xffffffff;
  }
  else {
    uVar17 = (ulonglong)*pbVar11;
  }
  FUN_141f9e0e0(alStack_958,uVar17,&uStack_b08,0xc);
  pbVar11 = (byte *)FUN_141bcf3e0(alStack_958[0] + 0x10,0x71e819a6);
  if (pbVar11 == (byte *)0x0) {
    uVar17 = 0xffffffff;
  }
  else {
    uVar17 = (ulonglong)*pbVar11;
  }
  FUN_141f9e0e0(alStack_958,uVar17,&fStack_aec,4);
  pbVar11 = (byte *)FUN_141bcf3e0(alStack_958[0] + 0x10,0x5bf7469f);
  if (pbVar11 == (byte *)0x0) {
    uVar17 = 0xffffffff;
  }
  else {
    uVar17 = (ulonglong)*pbVar11;
  }
  FUN_141f9e0e0(alStack_958,uVar17,param_1 + 0x3c,4);
  pbVar11 = (byte *)FUN_141bcf3e0(alStack_958[0] + 0x10,0x7a248ff0);
  if (pbVar11 != (byte *)0x0) {
    uVar19 = (ulonglong)*pbVar11;
  }
  FUN_141f9e0e0(alStack_958,uVar19,auStackX_8,1);
  fStack_b40 = (fVar25 / param_2) * fStack_ae0;
  *(ulonglong *)((longlong)param_1 + 0x184) = (ulonglong)(uint)((fVar25 / param_2) * fStack_ae8);
  *(float *)((longlong)param_1 + 0x18c) = fStack_b40;
  if (fVar2 < *(float *)((longlong)param_1 + 0x2f4)) {
    fVar20 = uStack_b38._4_4_ * uStack_b38._4_4_ + (float)uStack_b38 * (float)uStack_b38 +
             fStack_b30 * fStack_b30;
    if ((float)((uint)fVar20 & uVar4) <= _DAT_14382e110) {
      fVar20 = 0.0;
    }
    else {
      fVar20 = (uStack_b38._4_4_ * *(float *)(param_1 + 0x31) +
                (float)uStack_b38 * *(float *)((longlong)param_1 + 0x184) +
               fStack_b30 * *(float *)((longlong)param_1 + 0x18c)) / fVar20;
    }
    fVar27 = fVar20 * fStack_b30;
    fVar20 = fVar20 * (float)uStack_b38;
    fVar26 = (float)func_0x0001403e3f30();
    fVar23 = (float)((uint)fVar20 & uVar4);
    fVar24 = (float)((uint)fVar27 & uVar4);
    if (fVar24 <= fVar23) {
      fVar24 = fVar23;
    }
    fVar23 = 0.0;
    fVar27 = (fVar25 / fVar24) * fVar27;
    fVar20 = (fVar25 / fVar24) * fVar20;
    if (0.0 < fVar24) {
      fVar23 = SQRT(fVar27 * fVar27 + fVar20 * fVar20) * fVar24;
    }
    fVar20 = 0.0;
    if (fVar2 <= fVar26) {
      fVar20 = fVar23 / fVar26;
      if (fVar20 <= 0.0) {
        fVar20 = 0.0;
      }
      if (fVar25 <= fVar20) {
        fVar20 = fVar25;
      }
    }
    *pfVar7 = fVar20 * *pfVar7;
    *(float *)((longlong)param_1 + 0x17c) = fVar20 * *(float *)((longlong)param_1 + 0x17c);
    *(float *)(param_1 + 0x30) = fVar20 * *(float *)(param_1 + 0x30);
  }
  (**(code **)(*param_1 + 0x1d8))(param_1,alStack_958);
  FUN_1420e0880(param_1,alStack_958);
  if ((int)param_1[0x58] != 0x34) {
    *(bool *)((longlong)param_1 + 0x2ca) = (char)param_1[0x59] == '\0';
  }
  return;
}


/* HeroStateSwingJumpLocal_virtual_38 @ 0x140a8a190 */

void FUN_140a8a190(longlong *param_1)

{
  char cVar1;
  longlong lVar2;
  byte *pbVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStackX_8 [8];
  undefined1 auStackX_18 [8];
  longlong alStack_448 [130];
  undefined1 auStack_38 [32];
  undefined8 uStack_18;
  
  lVar2 = param_1[1];
  if (*(short *)(lVar2 + 0x88) == 0) {
    lVar2 = FUN_14167ab40(lVar2 + 0x58,0x1473d09e0);
  }
  else {
    lVar2 = func_0x0001416799a0(lVar2 + 0x80);
  }
  cVar1 = (**(code **)(*param_1 + 0x178))(param_1,auStackX_8,auStackX_18);
  if (cVar1 != '\0') {
    alStack_448[0] = FUN_141f9e890(&UNK_1438c9b30);
    FUN_141c649a0(auStack_38,0,0x20);
    uStack_18 = 0;
    pbVar3 = (byte *)FUN_141bcf3e0(alStack_448[0] + 0x10,0x3cb31d7d);
    uVar5 = 0xffffffff;
    if (pbVar3 == (byte *)0x0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = (ulonglong)*pbVar3;
    }
    FUN_141f9e0e0(alStack_448,uVar4,auStackX_8,4);
    pbVar3 = (byte *)FUN_141bcf3e0(alStack_448[0] + 0x10,0x3ecc7218);
    if (pbVar3 != (byte *)0x0) {
      uVar5 = (ulonglong)*pbVar3;
    }
    FUN_141f9e0e0(alStack_448,uVar5,auStackX_18,4);
    FUN_1420e0880(param_1,alStack_448);
    *(uint *)(lVar2 + 0x48) = *(uint *)(lVar2 + 0x48) | 2;
    FUN_1415c2410(lVar2,1);
    *(uint *)(lVar2 + 0x48) = *(uint *)(lVar2 + 0x48) & 0xfffffffd;
  }
  return;
}


/* HeroStateSwingJumpLocal_virtual_40 @ 0x140a8a2f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140a8a2f0(longlong param_1,float param_2)

{
  ulonglong uVar1;
  float *pfVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  char cVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined8 uVar13;
  ulonglong *puVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fStackX_18;
  float fStackX_20;
  undefined8 uStack_198;
  float fStack_190;
  float fStack_188;
  float fStack_184;
  undefined8 uStack_180;
  float fStack_178;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  undefined8 uStack_160;
  undefined4 uStack_158;
  float fStack_150;
  float fStack_14c;
  float fStack_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  undefined8 uStack_130;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  undefined1 auStack_118 [48];
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  
  lVar12 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar12 + 0x88) == 0) {
    plVar9 = (longlong *)FUN_14167ab40(lVar12 + 0x58,0x146dd6030);
  }
  else {
    plVar9 = (longlong *)func_0x0001416799a0(lVar12 + 0x80);
  }
  (**(code **)(*plVar9 + 0x120))(plVar9,auStack_118,0);
  FUN_14090dd90(plVar9,&fStack_128);
  fVar16 = _DAT_14382dce0;
  fStack_e8 = fStack_e8 - fStack_128;
  fStack_e4 = fStack_e4 - fStack_124;
  fStack_e0 = fStack_e0 - fStack_120;
  uStack_dc = 0x3f800000;
  lVar10 = func_0x00014098ebf0(*(undefined8 *)(param_1 + 0x108));
  puVar11 = (undefined8 *)FUN_1402c48c0(*(undefined8 *)(param_1 + 8));
  uStack_160 = *puVar11;
  uStack_158 = *(undefined4 *)(puVar11 + 1);
  lVar12 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar12 + 0x88) == 0) {
    lVar12 = FUN_14167ab40(lVar12 + 0x58,0x146deda80);
  }
  else {
    lVar12 = func_0x0001416799a0(lVar12 + 0x80);
  }
  fStackX_20 = *(float *)(lVar12 + 0x38c);
  fStack_188 = *(float *)(lVar12 + 0x390) - *(float *)(lVar12 + 0x370);
  fStackX_18 = *(float *)(lVar12 + 900);
  fStack_144 = *(float *)(lVar10 + 0x398);
  if (fStack_188 <= 0.0) {
    fStack_188 = 0.0;
  }
  fVar18 = _DAT_143830778;
  fVar25 = _DAT_1438726d8;
  if (*(char *)(lVar10 + 0x440) != '\0') {
    fVar18 = *(float *)(lVar10 + 0x380);
    fVar25 = (*(float *)(lVar10 + 0x380) + _DAT_145d9fe6c) - *(float *)((longlong)plVar9 + 0x2d4);
  }
  if ((fStackX_18 - fVar18 < _DAT_14382f760) || (_DAT_1438530bc < uStack_160._4_4_ - fStackX_18)) {
    fStackX_20 = _DAT_14382e9ec;
    fStackX_18 = _DAT_14382e9ec;
    fStack_188 = _DAT_14382fa30;
  }
  if (*(char *)(param_1 + 0x2cf) == '\0') {
    fVar18 = *(float *)(lVar12 + 0x394);
    if (*(char *)(lVar12 + 0x39c) == '\0') {
      fVar18 = 0.0;
    }
    fVar15 = *(float *)(lVar12 + 0x374) - _DAT_14382ee90;
    fVar24 = *(float *)(lVar12 + 0x348);
    if (*(float *)(lVar12 + 0x348) < fVar15) {
      fVar18 = *(float *)(lVar12 + 0x378);
      fVar24 = fVar15;
    }
    fVar15 = 0.0;
    if (fStack_e4 < fVar24) {
      fVar23 = *(float *)(param_1 + 0x1f0);
      fVar15 = fVar23 / *(float *)(param_1 + 0x1e0);
      if (((fVar23 <= 0.0) || (fVar18 < fVar15)) ||
         (fVar21 = fVar24 - fStack_e4, fVar23 * _DAT_14382e128 * fVar15 < fVar21)) {
        fVar15 = fVar16;
        if (_DAT_14382ee88 < fVar18) {
          fVar15 = param_2 / (fVar18 - _DAT_14382ee88);
          if (fVar15 <= 0.0) {
            fVar15 = 0.0;
          }
          if (fVar16 <= fVar15) {
            fVar15 = fVar16;
          }
        }
        fVar15 = (fVar24 - fStack_e4) * fVar15;
      }
      else {
        fVar15 = fVar23 * param_2;
        if (fVar21 <= fVar23 * param_2) {
          fVar15 = fVar21;
        }
        if (fVar15 <= 0.0) {
          fVar15 = 0.0;
        }
      }
    }
    fVar18 = fStack_e4 + fVar15;
    if (fStack_e4 + fVar15 <= fVar25) {
      fVar18 = fVar25;
    }
    uStack_160 = CONCAT44(fVar18,(undefined4)uStack_160);
    FUN_1409118f0(plVar9,0,&uStack_160,0x19);
    cVar7 = '\x01';
    *(undefined8 *)(param_1 + 0x194) = uStack_160;
    *(undefined4 *)(param_1 + 0x19c) = uStack_158;
    cVar8 = '\x01';
    uVar13 = (**(code **)(*plVar9 + 0x58))(plVar9,&fStack_184);
    lVar12 = func_0x0001415a0560(uVar13);
    if (lVar12 == 0) {
LAB_140a8a7d1:
      lVar12 = FUN_1402c48c0(*(undefined8 *)(param_1 + 8));
      fVar18 = *(float *)(param_1 + 0x26c) - *(float *)(lVar12 + 4);
      if ((cVar7 == '\0') || (cVar8 == '\0')) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
    }
    else {
      if (*(short *)(lVar12 + 0x88) == 0) {
        lVar12 = FUN_14167ab40(lVar12 + 0x58,0x147462340);
      }
      else {
        lVar12 = func_0x0001416799a0(lVar12 + 0x80);
      }
      lVar12 = *(longlong *)(lVar12 + 0x50);
      if (lVar12 != 0) {
        puVar11 = *(undefined8 **)(param_1 + 8);
        uVar13 = FUN_1402c48c0(puVar11);
        cVar7 = FUN_141879fb0(lVar12,uVar13,_DAT_14382e120);
        pfVar2 = (float *)*puVar11;
        if (pfVar2 == (float *)0x0) {
          fStack_140 = _DAT_14382eaa0;
          fStack_13c = _UNK_14382eaa4;
          fStack_138 = _UNK_14382eaa8;
          fStack_134 = _UNK_14382eaac;
        }
        else {
          fVar16 = pfVar2[0x12];
          fVar18 = pfVar2[0x11];
          fVar24 = pfVar2[0x10];
          fStack_140 = fVar16 * pfVar2[8] + fVar24 * *pfVar2 + fVar18 * pfVar2[4] + pfVar2[0xc];
          fStack_13c = fVar24 * pfVar2[1] + fVar16 * pfVar2[9] + pfVar2[5] * fVar18 + pfVar2[0xd];
          fStack_138 = fVar24 * pfVar2[2] + fVar16 * pfVar2[10] + pfVar2[6] * fVar18 + pfVar2[0xe];
          fStack_134 = pfVar2[(ulonglong)((uint)pfVar2[0x17] & 3) + 0x1c] * pfVar2[0x13];
          fVar16 = _DAT_14382dce0;
        }
        cVar8 = FUN_141879fb0(lVar12,&fStack_140,_DAT_14382e120);
        goto LAB_140a8a7d1;
      }
      lVar12 = FUN_1402c48c0(*(undefined8 *)(param_1 + 8));
      bVar4 = false;
      fVar18 = *(float *)(param_1 + 0x26c) - *(float *)(lVar12 + 4);
    }
    bVar3 = _DAT_1438cb4b4 < fVar18;
    lVar12 = FUN_1402c48c0(*(undefined8 *)(param_1 + 8));
    if ((uStack_160._4_4_ - _DAT_143830118 < *(float *)(lVar12 + 4) ||
         uStack_160._4_4_ - _DAT_143830118 == *(float *)(lVar12 + 4)) ||
       (0.0 < *(float *)(param_1 + 0x1f0) || *(float *)(param_1 + 0x1f0) == 0.0)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (((bVar4) || (bVar3)) || (bVar5)) {
      *(undefined1 *)(param_1 + 0x2cf) = 1;
    }
    if (*(char *)(param_1 + 0x2cf) == '\0') goto LAB_140a8ad19;
  }
  fVar24 = fStack_e0;
  fVar18 = fStack_e8;
  fStack_14c = fStack_e8;
  fStack_184 = fStack_e0;
  fVar15 = (fStack_e4 - *(float *)(param_1 + 0x198)) + *(float *)(param_1 + 0x1d0);
  if (0.0 <= fVar15) {
    fVar15 = 0.0;
  }
  fVar23 = fStack_e4 - fVar15;
  *(float *)(param_1 + 0x1d0) = fVar15;
  fStack_148 = fVar23;
  puVar11 = (undefined8 *)FUN_1402c48c0(*(undefined8 *)(param_1 + 8));
  uVar6 = _DAT_14382e160;
  fVar18 = (float)*puVar11 - fVar18;
  uStack_198 = *(undefined8 *)(lVar10 + 700);
  fVar15 = (float)((ulonglong)uStack_198 >> 0x20);
  fStack_150 = (float)uStack_198 - *(float *)(lVar10 + 0x3ac);
  fStack_190 = *(float *)(lVar10 + 0x2c4);
  fVar24 = *(float *)(puVar11 + 1) - fVar24;
  uStack_130 = CONCAT44(fVar15,fVar15 - *(float *)(lVar10 + 0x3b0));
  fVar15 = fStack_190 - *(float *)(lVar10 + 0x3b4);
  fVar23 = (float)((ulonglong)*puVar11 >> 0x20) - fVar23;
  if (0.0 <= fVar18 * fStack_150 + fVar24 * fVar15) {
    fStack_178 = fVar24 - fVar15;
    uStack_180 = (ulonglong)(uint)(fVar18 - fStack_150);
    fVar21 = 0.0;
    fVar22 = fVar18 - fStack_150;
    if (*(char *)(param_1 + 0x2d8) == '\0') {
      uStack_198 = 0;
      fStack_190 = 0.0;
      puVar14 = (ulonglong *)
                FUN_141c472e0(&fStack_140,&uStack_198,&uStack_180,param_1 + 0x1d8,_DAT_143841700,
                              _DAT_143841320,_DAT_143830120,param_2);
      uVar1 = *puVar14;
      fStack_178 = *(float *)(puVar14 + 1);
      uStack_180._4_4_ = (float)(uVar1 >> 0x20);
      uStack_180._0_4_ = (float)uVar1;
      fVar21 = uStack_180._4_4_;
      fVar22 = (float)uStack_180;
      uStack_180 = uVar1;
    }
    fVar22 = fVar22 + fStack_150;
    fVar15 = fStack_178 + fVar15;
    fVar17 = (float)((uint)fVar24 & uVar6);
    if ((float)((uint)fVar24 & uVar6) <= (float)((uint)fVar18 & uVar6)) {
      fVar17 = (float)((uint)fVar18 & uVar6);
    }
    fVar19 = 0.0;
    fVar18 = fVar18 * (fVar16 / fVar17);
    fVar24 = fVar24 * (fVar16 / fVar17);
    if (0.0 < fVar17) {
      fVar19 = SQRT(fVar24 * fVar24 + fVar18 * fVar18) * fVar17;
    }
    fVar18 = (float)((uint)fVar15 & uVar6);
    if ((float)((uint)fVar15 & uVar6) <= (float)((uint)fVar22 & uVar6)) {
      fVar18 = (float)((uint)fVar22 & uVar6);
    }
    fVar20 = fVar22 * (fVar16 / fVar18);
    fVar24 = fVar15 * (fVar16 / fVar18);
    fVar17 = 0.0;
    if (0.0 < fVar18) {
      fVar17 = SQRT(fVar24 * fVar24 + fVar20 * fVar20) * fVar18;
    }
    if (fVar19 < fVar17) {
      fVar24 = fVar21 * fVar21 + fVar22 * fVar22 + fVar15 * fVar15;
      fVar18 = fVar19 / SQRT(fVar24);
      if (_DAT_14382e110 <= fVar24) {
        fVar22 = fVar22 * fVar18;
        fVar15 = fVar15 * fVar18;
      }
      else {
        fVar15 = 0.0;
        fVar22 = fVar19;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    fVar15 = 0.0;
    fVar22 = 0.0;
  }
  fVar18 = _DAT_14382e13c;
  if (0.0 <= fVar23) {
    fVar18 = fVar16;
  }
  fVar21 = (float)uStack_130;
  fVar24 = _DAT_14382e13c;
  if (0.0 <= fVar21) {
    fVar24 = fVar16;
  }
  if (fVar18 == fVar24) {
    fVar18 = (float)((uint)fVar21 & uVar6);
    if ((float)((uint)fVar23 & uVar6) <= (float)((uint)fVar21 & uVar6)) {
      fVar18 = (float)((uint)fVar23 & uVar6);
    }
    fVar24 = _DAT_14382e13c;
    if (0.0 <= fVar21) {
      fVar24 = fVar16;
    }
    fVar23 = fVar23 - fVar24 * fVar18;
    if (*(char *)(param_1 + 0x2d8) == '\0') {
      fVar23 = (float)FUN_141c46be0(0,fVar23,param_1 + 0x1d4,_DAT_143841700,_DAT_143841320,
                                    _DAT_143830120,param_2);
    }
    fVar23 = fVar23 + fVar24 * fVar18;
  }
  else {
    *(undefined4 *)(param_1 + 0x1d4) = 0;
    fVar23 = 0.0;
  }
  fStack_170 = fVar22 + fStack_14c;
  fStack_168 = fStack_184 + fVar15;
  fStack_16c = fVar23 + fStack_148;
  fVar18 = *(float *)(lVar10 + 0x74) - _DAT_145d9f5e8;
  if (fStack_144 - fStackX_18 < _DAT_14382ee88) {
    fVar18 = fVar18 + *(float *)(lVar10 + 0x78);
  }
  fVar24 = *(float *)(param_1 + 0x1d0);
  fStackX_20 = fStackX_20 - _DAT_145d9f5e8;
  if (fVar24 < fStackX_20) {
    fVar24 = (float)func_0x000141c477e0(fVar24,0,fVar16,param_2);
    *(float *)(param_1 + 0x1d0) = fVar24;
  }
  fVar15 = fVar24;
  if (fStackX_20 <= fVar24) {
    fVar15 = fStackX_20;
  }
  if (fVar15 <= fVar18) {
    fVar15 = fVar18;
  }
  if (fVar15 < fVar24) {
    fVar18 = fStack_188;
    if (fStack_188 <= _DAT_143836d08) {
      fVar18 = _DAT_143836d08;
    }
    if (_DAT_14382e128 <= fVar18) {
      fVar18 = _DAT_14382e128;
    }
    fVar24 = param_2 / fVar18 + fVar24 / fVar15;
    if (fVar24 <= 0.0) {
      fVar24 = 0.0;
    }
    if (fVar16 <= fVar24) {
      fVar24 = fVar16;
    }
    fVar24 = fVar24 * fVar15;
    *(float *)(param_1 + 0x1d0) = fVar24;
  }
  fVar16 = (float)(*(uint *)(lVar10 + 0x428) & uVar6 ^ _DAT_14382e890);
  if (fVar16 <= fVar24) {
    fVar16 = fVar24;
  }
  fStack_16c = fStack_16c + fVar16;
  *(float *)(param_1 + 0x1d0) = fVar16;
  if (fStack_16c < fVar25) {
    fStack_16c = fVar25;
  }
  FUN_1409118f0(plVar9,0,&fStack_170,0x19);
  *(ulonglong *)(param_1 + 0x194) = CONCAT44(fStack_16c,fStack_170);
  *(float *)(param_1 + 0x19c) = fStack_168;
LAB_140a8ad19:
  _DAT_146deecc0 = *(undefined8 *)(param_1 + 0x1d0);
  _DAT_146deecc8 = *(undefined4 *)(param_1 + 0x1d8);
  return;
}


/* HeroStateSwingJumpLocal_virtual_43 @ 0x140a143f0 */

void HeroStateSwingJumpLocal_virtual_43(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140a143f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x150))();
  return;
}


/* HeroStateSwingJumpLocal_virtual_44 @ 0x140a8ae80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140a8ae80(longlong param_1,undefined8 *param_2,undefined1 *param_3)

{
  undefined8 *puVar1;
  float afStackX_8 [2];
  float afStackX_20 [2];
  undefined1 auStack_88 [16];
  undefined1 auStack_78 [16];
  undefined1 auStack_68 [16];
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  puVar1 = (undefined8 *)&DAT_147afdf10;
  if ((undefined8 *)**(undefined8 **)(param_1 + 8) != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)**(undefined8 **)(param_1 + 8);
  }
  uStack_58 = *puVar1;
  uStack_50 = puVar1[1];
  uStack_48 = puVar1[2];
  uStack_40 = puVar1[3];
  uStack_38 = *(undefined4 *)(puVar1 + 4);
  uStack_34 = *(undefined4 *)((longlong)puVar1 + 0x24);
  uStack_30 = *(undefined4 *)(puVar1 + 5);
  uStack_2c = *(undefined4 *)((longlong)puVar1 + 0x2c);
  uStack_28 = *(undefined4 *)(puVar1 + 6);
  uStack_24 = *(undefined4 *)((longlong)puVar1 + 0x34);
  uStack_20 = *(undefined4 *)(puVar1 + 7);
  uStack_1c = *(undefined4 *)((longlong)puVar1 + 0x3c);
  FUN_141c53f40(param_1 + 0x1b0,auStack_88,afStackX_8);
  if (_DAT_14382e11c < afStackX_8[0]) {
    FUN_141c53f40(param_1 + 0x1c0,auStack_78,afStackX_20);
    afStackX_20[0] = afStackX_20[0] / afStackX_8[0];
    if (afStackX_20[0] <= 0.0) {
      afStackX_20[0] = 0.0;
    }
    if (_DAT_14382dce0 <= afStackX_20[0]) {
      afStackX_20[0] = _DAT_14382dce0;
    }
    puVar1 = (undefined8 *)FUN_141c5b3e0(auStack_68,&uStack_38,param_2,afStackX_20[0]);
    *param_2 = *puVar1;
    *(undefined4 *)(param_2 + 1) = *(undefined4 *)(puVar1 + 1);
    *param_3 = 1;
  }
  *(undefined4 *)(param_1 + 0x1b0) = *(undefined4 *)(param_1 + 0x1a0);
  *(undefined4 *)(param_1 + 0x1b4) = *(undefined4 *)(param_1 + 0x1a4);
  *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0x1a8);
  *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1ac);
  return;
}


/* HeroStateSwingJumpLocal_virtual_45 @ 0x140a8afa0 */

undefined8 FUN_140a8afa0(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    lVar1 = FUN_14167ab40(lVar1 + 0x58,0x147c40bf0);
  }
  else {
    lVar1 = func_0x0001416799a0(lVar1 + 0x80);
  }
  FUN_14098f280(lVar1 + 0x2a4,param_2,0,1);
  return param_2;
}


/* HeroStateSwingJumpLocal_virtual_46 @ 0x140a8aff0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_140a8aff0(longlong param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  longlong lVar7;
  float fVar8;
  
  lVar7 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar7 + 0x88) == 0) {
    lVar7 = FUN_14167ab40(lVar7 + 0x58,0x147c40bf0);
  }
  else {
    lVar7 = func_0x0001416799a0(lVar7 + 0x80);
  }
  fVar8 = 0.0;
  if (0.0 < *(float *)(lVar7 + 0x434)) {
    fVar8 = _DAT_14382dce0 / *(float *)(lVar7 + 0x434);
  }
  uVar5 = *(undefined8 *)(lVar7 + 700);
  fVar6 = *(float *)(lVar7 + 0x2c4);
  fVar1 = *(float *)(lVar7 + 0x3ac);
  fVar2 = *(float *)(lVar7 + 0x3b4);
  fVar3 = *(float *)(lVar7 + 0x2ec);
  fVar4 = *(float *)(lVar7 + 0x2f4);
  param_2[1] = (((float)((ulonglong)uVar5 >> 0x20) - *(float *)(lVar7 + 0x3b0)) -
               *(float *)(lVar7 + 0x2f0)) * fVar8;
  *param_2 = (((float)uVar5 - fVar1) - fVar3) * fVar8;
  param_2[2] = ((fVar6 - fVar2) - fVar4) * fVar8;
  return param_2;
}


/* HeroStateSwingJumpLocal_virtual_47 @ 0x140a8b0c0 */

undefined8 FUN_140a8b0c0(longlong param_1,undefined4 *param_2,undefined4 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined4 extraout_XMM0_Da;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    plVar2 = (longlong *)FUN_14167ab40(lVar1 + 0x58,0x146dae1c0);
  }
  else {
    plVar2 = (longlong *)func_0x0001416799a0(lVar1 + 0x80);
  }
  FUN_14088f6e0(plVar2);
  uVar3 = (**(code **)(*plVar2 + 0x58))(plVar2);
  *param_2 = uVar3;
  (**(code **)(*plVar2 + 0x50))(plVar2);
  *param_3 = extraout_XMM0_Da;
  return 1;
}


/* HeroStateSwingIntroJumpLocal_virtual_1 @ 0x140afc3b0 */

/* WARNING: Removing unreachable block (ram,0x000141676787) */
/* WARNING: Removing unreachable block (ram,0x000141676791) */
/* WARNING: Removing unreachable block (ram,0x0001416767c3) */
/* WARNING: Removing unreachable block (ram,0x0001416767d0) */
/* WARNING: Removing unreachable block (ram,0x0001416767e6) */
/* WARNING: Removing unreachable block (ram,0x0001416767f0) */
/* WARNING: Removing unreachable block (ram,0x000141676801) */
/* WARNING: Removing unreachable block (ram,0x000141676811) */
/* WARNING: Removing unreachable block (ram,0x000141676809) */
/* WARNING: Removing unreachable block (ram,0x00014167680f) */
/* WARNING: Removing unreachable block (ram,0x00014167681e) */

void HeroStateSwingIntroJumpLocal_virtual_1(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    (**(code **)(*param_1 + 0x40))();
    *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) & 0xfe;
    if (((int)param_1[7] != 0) && ((*(ushort *)(param_1[1] + 8) >> 0xd & 1) != 0)) {
      FUN_14167d120(0x147a43720,param_1,(int)param_1[7],*(undefined2 *)(param_1[1] + 0x18));
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  if ((*(ushort *)(param_1[1] + 8) >> 10 & 1) == 0) {
    lVar3 = FUN_141984370(param_1 + 3);
    if (lVar3 != 0) {
      func_0x000141984600(lVar3);
    }
    FUN_14159e150(param_1[1],param_1);
    FUN_1416793a0(0x146046060,param_1);
    lVar3 = func_0x0001416798f0((longlong)param_1 + 0x3c);
    if (lVar3 != 0) {
      *(char *)(lVar3 + 0x1c) = *(char *)(lVar3 + 0x1c) + -1;
    }
  }
  *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) | 2;
  FUN_14190fa90(0x147a42f80,(longlong)param_1 + 0x14);
  plVar2 = (longlong *)param_1[8];
  if (plVar2 != (longlong *)0x0) {
    plVar1 = plVar2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    if ((int)*plVar1 == 0) {
      (**(code **)(*plVar2 + 0x50))(plVar2[2]);
      *plVar2 = 0;
      plVar2[2] = 0;
      func_0x000141757470(plVar2);
    }
    param_1[8] = 0;
  }
  return;
}


/* HeroStateSwingIntroJumpLocal_virtual_2 @ 0x140afc3c0 */

/* WARNING: Removing unreachable block (ram,0x000141676787) */
/* WARNING: Removing unreachable block (ram,0x000141676791) */
/* WARNING: Removing unreachable block (ram,0x0001416767c3) */
/* WARNING: Removing unreachable block (ram,0x0001416767d0) */
/* WARNING: Removing unreachable block (ram,0x0001416767e6) */
/* WARNING: Removing unreachable block (ram,0x0001416767f0) */
/* WARNING: Removing unreachable block (ram,0x000141676801) */
/* WARNING: Removing unreachable block (ram,0x000141676811) */
/* WARNING: Removing unreachable block (ram,0x000141676809) */
/* WARNING: Removing unreachable block (ram,0x00014167680f) */
/* WARNING: Removing unreachable block (ram,0x00014167681e) */

void HeroStateSwingIntroJumpLocal_virtual_2(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((*(byte *)((longlong)param_1 + 0x1d) & 1) != 0) {
    (**(code **)(*param_1 + 0x40))();
    *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) & 0xfe;
    if (((int)param_1[7] != 0) && ((*(ushort *)(param_1[1] + 8) >> 0xd & 1) != 0)) {
      FUN_14167d120(0x147a43720,param_1,(int)param_1[7],*(undefined2 *)(param_1[1] + 0x18));
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  if ((*(ushort *)(param_1[1] + 8) >> 10 & 1) == 0) {
    lVar3 = FUN_141984370(param_1 + 3);
    if (lVar3 != 0) {
      func_0x000141984600(lVar3);
    }
    FUN_14159e150(param_1[1],param_1);
    FUN_1416793a0(0x146046060,param_1);
    lVar3 = func_0x0001416798f0((longlong)param_1 + 0x3c);
    if (lVar3 != 0) {
      *(char *)(lVar3 + 0x1c) = *(char *)(lVar3 + 0x1c) + -1;
    }
  }
  *(byte *)((longlong)param_1 + 0x1d) = *(byte *)((longlong)param_1 + 0x1d) | 2;
  FUN_14190fa90(0x147a42f80,(longlong)param_1 + 0x14);
  plVar2 = (longlong *)param_1[8];
  if (plVar2 != (longlong *)0x0) {
    plVar1 = plVar2 + 1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    if ((int)*plVar1 == 0) {
      (**(code **)(*plVar2 + 0x50))(plVar2[2]);
      *plVar2 = 0;
      plVar2[2] = 0;
      func_0x000141757470(plVar2);
    }
    param_1[8] = 0;
  }
  return;
}


/* HeroStateSwingIntroJumpLocal_virtual_9 @ 0x140afc3a0 */

undefined8 HeroStateSwingIntroJumpLocal_virtual_9(void)

{
  return 0x146dfa680;
}


/* HeroStateSwingIntroJumpLocal_virtual_11 @ 0x140afc3d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_140a86490(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined *puVar7;
  longlong *plVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  float fVar11;
  float fVar12;
  undefined4 auStackX_8 [2];
  undefined8 uStack_98;
  uint uStack_90;
  float afStack_88 [2];
  float fStack_80;
  undefined1 auStack_78 [48];
  undefined8 uStack_48;
  undefined4 uStack_40;
  
  FUN_1420e0800();
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    plVar4 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x147c40bf0);
  }
  else {
    plVar4 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
  }
  FUN_1408bc0a0(param_1 + 0x27c,*(undefined8 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x68),
                *(char *)(param_2 + 0x84) != '\0',0);
  *(undefined1 *)(param_1 + 0x120) = *(undefined1 *)(param_2 + 0x80);
  *(byte *)(param_1 + 0x2cb) = ~(*(byte *)(param_2 + 0x83) >> 1) & 1;
  *(byte *)(param_1 + 0x2d1) = *(byte *)(param_2 + 0x83) & 1;
  *(byte *)(param_1 + 0x2cc) = ~(*(byte *)(param_2 + 0x83) >> 2) & 1;
  *(byte *)(param_1 + 0x2d6) = *(byte *)(param_2 + 0x83) >> 6 & 1;
  *(byte *)(param_1 + 0x2d7) = *(byte *)(param_2 + 0x83) >> 7;
  cVar3 = *(char *)(param_2 + 0x87);
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0x3f800000;
  *(undefined8 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined8 *)(param_1 + 0x1ac) = 0x3f800000;
  *(undefined8 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0x3f800000;
  *(bool *)(param_1 + 0x2d8) = cVar3 != '\0';
  *(undefined1 *)(param_1 + 0x2ca) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  *(undefined4 *)(param_1 + 0x220) = 0xf149f2ca;
  *(undefined4 *)(param_1 + 0x204) = 0xbf800000;
  *(undefined8 *)(param_1 + 0x154) = *(undefined8 *)(param_2 + 0x40);
  uVar10 = *(undefined4 *)(param_2 + 0x48);
  *(undefined4 *)(param_1 + 0x15c) = uVar10;
  *(undefined8 *)(param_1 + 0x160) = *(undefined8 *)(param_1 + 0x154);
  *(undefined4 *)(param_1 + 0x168) = uVar10;
  lVar5 = FUN_1402c48c0(*(undefined8 *)(param_1 + 8));
  fVar12 = *(float *)(lVar5 + 4);
  if (*(float *)(lVar5 + 4) <= *(float *)(param_2 + 0x70)) {
    fVar12 = *(float *)(param_2 + 0x70);
  }
  *(float *)(param_1 + 0x26c) = fVar12;
  puVar6 = (undefined8 *)func_0x000140a7d9e0(param_2,&uStack_98);
  uVar2 = _DAT_14382e160;
  fVar12 = _DAT_14382e118;
  puVar1 = (uint *)(param_1 + 0x124);
  *(undefined8 *)puVar1 = *puVar6;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(puVar6 + 1);
  if (((fVar12 < (float)(*puVar1 & uVar2)) || (fVar12 < (float)(*(uint *)(param_1 + 0x128) & uVar2))
      ) || (fVar12 < (float)(*(uint *)(param_1 + 300) & uVar2))) {
    puVar6 = (undefined8 *)FUN_1402d0740(&uStack_98,puVar1);
    *(undefined8 *)puVar1 = *puVar6;
    uVar10 = *(undefined4 *)(puVar6 + 1);
  }
  else {
    puVar7 = &DAT_147afdf10;
    if ((undefined *)**(undefined8 **)(param_1 + 8) != (undefined *)0x0) {
      puVar7 = (undefined *)**(undefined8 **)(param_1 + 8);
    }
    *(undefined8 *)puVar1 = *(undefined8 *)(puVar7 + 0x20);
    uVar10 = *(undefined4 *)(puVar7 + 0x28);
  }
  *(undefined4 *)(param_1 + 300) = uVar10;
  *(undefined8 *)(param_1 + 0x130) = *(undefined8 *)puVar1;
  *(undefined4 *)(param_1 + 0x138) = uVar10;
  uVar9 = *(undefined8 *)(param_2 + 0x4c);
  uStack_90 = *(uint *)(param_2 + 0x54);
  if (((fVar12 < (float)((uint)uVar9 & uVar2)) ||
      (uStack_98._4_4_ = (uint)((ulonglong)uVar9 >> 0x20), fVar12 < (float)(uStack_98._4_4_ & uVar2)
      )) || (fVar12 < (float)(uStack_90 & uVar2))) {
    *(undefined8 *)(param_1 + 0x130) = *(undefined8 *)(param_2 + 0x4c);
    *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_2 + 0x54);
    *(undefined8 *)(param_1 + 0x16c) = *(undefined8 *)(param_2 + 0x4c);
    *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_2 + 0x54);
  }
  *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_2 + 0x74);
  *(uint *)(param_1 + 0x2c0) = (uint)*(byte *)(param_2 + 0x81);
  *(uint *)(param_1 + 0x2c4) = (uint)*(byte *)(param_2 + 0x82);
  *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(param_1 + 0x1f0) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(param_1 + 0x1e0) = *(undefined4 *)(param_2 + 0x60);
  uStack_98 = uVar9;
  uVar10 = func_0x000140a7d9c0(param_2);
  *(undefined4 *)(param_1 + 0x1e4) = uVar10;
  *(undefined4 *)(param_1 + 0x1fc) = *(undefined4 *)(param_2 + 0x7c);
  *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(param_1 + 0x274);
  *(undefined4 *)(param_1 + 0x264) = *(undefined4 *)(param_1 + 0x274);
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(undefined1 *)(param_1 + 0x2d4) = 0;
  *(byte *)(param_1 + 0x2d5) = *(byte *)(param_2 + 0x83) >> 5 & 1;
  if (((*(int *)(param_1 + 0x2c0) - 0xbU < 2) || (*(int *)(param_1 + 0x2c0) == 0x34)) &&
     (*(int *)(param_1 + 0x2c4) != 0x35)) {
    *(undefined4 *)(param_1 + 0x2fc) = _DAT_146deecd0;
    *(undefined8 *)(param_1 + 0x1d0) = _DAT_146deecc0;
    *(undefined4 *)(param_1 + 0x1d8) = _DAT_146deecc8;
  }
  else {
    _DAT_146deeccc = 0;
    _DAT_146deecc0 = 0;
    _DAT_146deecc8 = 0;
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(char *)(param_1 + 0x2cb) == '\0') {
    if (*(short *)(lVar5 + 0x88) == 0) {
      plVar8 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x146dd8370);
    }
    else {
      plVar8 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
    }
    *(uint *)((longlong)plVar8 + 0x62c) = *(uint *)((longlong)plVar8 + 0x62c) | 0x4045;
    (**(code **)(*plVar8 + 200))(plVar8);
  }
  else {
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar9 = FUN_14167ab40(lVar5 + 0x58,0x146dd84e0);
    }
    else {
      uVar9 = func_0x0001416799a0(lVar5 + 0x80);
    }
    func_0x0001409a5590(uVar9,2);
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    plVar8 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x146dd6030);
  }
  else {
    plVar8 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
  }
  uVar10 = FUN_14085fc10(*(undefined8 *)(param_1 + 8));
  *(undefined4 *)(param_1 + 500) = uVar10;
  (**(code **)(*plVar8 + 0x120))(plVar8,auStack_78,0);
  *(undefined8 *)(param_1 + 0x194) = uStack_48;
  *(undefined4 *)(param_1 + 0x19c) = uStack_40;
  *(undefined4 *)(plVar8 + 0xe) = 3;
  *(undefined4 *)((longlong)plVar8 + 0x74) = 2;
  *(undefined1 *)(param_1 + 0x2cf) = 1;
  FUN_1409118f0(plVar8,0,&uStack_48,0);
  cVar3 = FUN_140869db0(*(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x2c0),
                        *(char *)((longlong)plVar8 + 0xb9d) != '\0');
  if (cVar3 != '\0') {
    func_0x00014089f410(plVar8 + 0x55,1);
  }
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_2 + 0x78);
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_2 + 0x5c);
  (**(code **)(*plVar4 + 0x80))(plVar4,afStack_88,0);
  fVar12 = (float)((uint)afStack_88[0] & uVar2);
  if ((float)((uint)afStack_88[0] & uVar2) <= (float)((uint)fStack_80 & uVar2)) {
    fVar12 = (float)((uint)fStack_80 & uVar2);
  }
  afStack_88[0] = afStack_88[0] * (_DAT_14382dce0 / fVar12);
  fStack_80 = fStack_80 * (_DAT_14382dce0 / fVar12);
  fVar11 = 0.0;
  if (0.0 < fVar12) {
    fVar11 = SQRT(fStack_80 * fStack_80 + afStack_88[0] * afStack_88[0]) * fVar12;
  }
  fVar11 = *(float *)(param_1 + 0x2e4) - fVar11;
  if (fVar11 <= 0.0) {
    fVar11 = 0.0;
  }
  *(float *)(param_1 + 0x2ec) = fVar11 / *(float *)(param_1 + 0x2e8);
  auStackX_8[0] = *(undefined4 *)((longlong)plVar8 + 0x194);
  lVar5 = func_0x0001415a0560(auStackX_8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146d03d80);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (lVar5 != 0) {
    func_0x0001405c72b0(lVar5);
  }
  uVar9 = FUN_14159cb80(*(undefined8 *)(param_1 + 8),0x146dac610,0);
  FUN_14085ac40(uVar9);
  if ((*(int *)(param_1 + 0x2c0) - 1U < 2) || (*(int *)(param_1 + 0x2c0) == 0x30)) {
    lVar5 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar9 = FUN_14167ab40(lVar5 + 0x58,0x146dacd70);
    }
    else {
      uVar9 = func_0x0001416799a0(lVar5 + 0x80);
    }
    FUN_140861cd0(uVar9);
  }
  return;
}


/* HeroRopeManager_virtual_1 @ 0x14095f510 */

void FUN_14095f510(undefined8 *param_1,int param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined4 uStack_a8;
  longlong alStack_98 [18];
  
  lVar2 = (longlong)param_2;
  FUN_140fb76a0(alStack_98);
  (**(code **)(alStack_98[0] + 0x48))(alStack_98);
  if (0 < param_2) {
    do {
      uStack_b8 = 0;
      uStack_b0 = 0;
      uStack_a8 = 0;
      func_0x000141bdb5f0(&uStack_b8,*param_3,param_3[1],0);
      FUN_141bde070();
      uVar1 = (**(code **)(alStack_98[0] + 0x38))(alStack_98);
      FUN_141bdd190(alStack_98,&uStack_b8,uVar1);
      param_3 = param_3 + 2;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  (**(code **)*param_1)(param_1,alStack_98);
  func_0x000140fb9850(alStack_98);
  func_0x000140fb7820(alStack_98);
  return;
}


/* HeroRopeManager_virtual_2 @ 0x14095f600 */

void FUN_14095f600(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong alStack_98 [18];
  
  FUN_140fb76a0(alStack_98);
  (**(code **)(alStack_98[0] + 0x48))(alStack_98);
  uVar1 = (**(code **)(alStack_98[0] + 0x38))(alStack_98);
  FUN_141be1cb0(alStack_98,param_2,uVar1,0);
  (**(code **)*param_1)(param_1,alStack_98);
  func_0x000140fb9850(alStack_98);
  func_0x000140fb7820(alStack_98);
  return;
}


/* HeroRopeManager_virtual_3 @ 0x140676d10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140676d10(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  char cVar2;
  longlong lVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined8 unaff_RDI;
  ulonglong uVar7;
  
  piVar5 = (int *)(param_1 + 0x750);
  uVar7 = 0;
  do {
    if (*piVar5 != 0) {
      FUN_140677eb0(param_1,uVar7 * 0x7c8 + 0x50 + param_1);
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    piVar5 = piVar5 + 0x1f2;
  } while (uVar6 < 0x10);
  uVar7 = 0;
  if (*(int *)(param_1 + 0x7d38) != 0) {
    do {
      FUN_141626940(0x1460588a0,*(undefined8 *)(param_1 + 0x7cf8 + uVar7 * 8));
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < *(uint *)(param_1 + 0x7d38));
  }
  *(undefined4 *)(param_1 + 0x7d38) = 0;
  *(undefined1 *)(param_1 + 0x7d3c) = 0;
  lVar3 = func_0x0001415a0560(param_1 + 0x48);
  if (lVar3 != 0) {
    FUN_14159d500(lVar3);
  }
  puVar1 = (uint *)(param_1 + 0x7cd0);
  uVar6 = *puVar1;
  uVar4 = uVar6 >> 0x14 & 0x7ff;
  if ((uVar4 != 0) && ((int)uVar6 < 0)) {
    lVar3 = (ulonglong)(uVar6 & 0xfffff) * 0x20 + _DAT_147a4a4a0;
    if ((_DAT_147a4a4bc <= (int)(uVar6 & 0xfffff)) || (uVar4 != *(ushort *)(lVar3 + 0x1e))) {
      lVar3 = 0;
    }
    if (lVar3 != 0) {
      if (*(char *)(lVar3 + 0x1d) != '\0') {
        cVar2 = *(char *)(lVar3 + 0x1d) + -1;
        *(char *)(lVar3 + 0x1d) = cVar2;
        if (cVar2 != '\0') goto LAB_14159f8e7;
      }
      if (((*(byte *)(lVar3 + 0x1c) & 2) != 0) && (*(short *)(lVar3 + 0x18) != 0)) {
        FUN_14159fc50(lVar3);
        FUN_1415a0280(lVar3);
        if (*(short *)(lVar3 + 0x18) != 0) goto LAB_14159f8e7;
      }
      FUN_141910810(0x147a42f80,puVar1,param_3,param_4,unaff_RDI);
    }
  }
LAB_14159f8e7:
  *puVar1 = 0;
  return 1;
}


/* HeroRopeManager_virtual_7 @ 0x14095f6b0 */

void HeroStateSwingLocal_virtual_7(void)

{
  return;
}


/* HeroRopeManager_virtual_9 @ 0x14095f500 */

undefined8 HeroRopeManager_virtual_9(void)

{
  return 0x146dd77b0;
}


/* HeroRopeManager_virtual_10 @ 0x14095f6c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14095f6c0(longlong param_1,float param_2)

{
  float fVar1;
  
  *(undefined8 *)(param_1 + 0x7de0) = *(undefined8 *)(param_1 + 0x7d60);
  *(undefined4 *)(param_1 + 0x7de8) = *(undefined4 *)(param_1 + 0x7d68);
  *(undefined8 *)(param_1 + 0x7dec) = *(undefined8 *)(param_1 + 0x7d6c);
  *(undefined4 *)(param_1 + 0x7df4) = *(undefined4 *)(param_1 + 0x7d74);
  FUN_140676dd0();
  fVar1 = *(float *)(param_1 + 0x7ed8);
  if (0.0 < fVar1) {
    if ((param_2 < fVar1) || (param_2 < 0.0)) {
      *(float *)(param_1 + 0x7ed8) = fVar1 - param_2;
    }
    else {
      *(undefined4 *)(param_1 + 0x7ed8) = 0;
      FUN_14067b610(param_1,param_1 + 0x7ed0,0,0);
      FUN_14067b610(param_1,param_1 + 0x7ed4,0,0);
      *(undefined8 *)(param_1 + 0x7ed0) = 0;
      *(undefined4 *)(param_1 + 0x7ed8) = 0xbf800000;
    }
  }
  param_2 = _DAT_14382dce0 / param_2;
  *(ulonglong *)(param_1 + 0x7df8) =
       CONCAT44((*(float *)(param_1 + 0x7d64) - *(float *)(param_1 + 0x7de4)) * param_2,
                (*(float *)(param_1 + 0x7d60) - *(float *)(param_1 + 0x7de0)) * param_2);
  *(float *)(param_1 + 0x7e00) =
       (*(float *)(param_1 + 0x7d68) - *(float *)(param_1 + 0x7de8)) * param_2;
  *(ulonglong *)(param_1 + 0x7e04) =
       CONCAT44((*(float *)(param_1 + 0x7d70) - *(float *)(param_1 + 0x7df0)) * param_2,
                (*(float *)(param_1 + 0x7d6c) - *(float *)(param_1 + 0x7dec)) * param_2);
  *(float *)(param_1 + 0x7e0c) =
       (*(float *)(param_1 + 0x7d74) - *(float *)(param_1 + 0x7df4)) * param_2;
  return;
}


/* HeroRopeManager_virtual_11 @ 0x1406771c0 */

void FUN_1406771c0(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  FUN_14067b590();
  uVar4 = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x7d38) = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 0x30);
    *(int *)(param_1 + 0x7d38) = iVar1;
    if (iVar1 != 0) {
      do {
        uVar2 = func_0x0001411f3c20(param_2,uVar4);
        uVar2 = FUN_14177fe20(0x1460588a0,uVar2,0,0);
        *(undefined8 *)(param_1 + 0x7cf8 + uVar4 * 8) = uVar2;
        uVar3 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar3;
      } while (uVar3 < *(uint *)(param_1 + 0x7d38));
      *(undefined1 *)(param_1 + 0x7d3c) = 0;
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x7d3c) = 0;
  return;
}


/* HeroRopeManager_virtual_12 @ 0x140960280 */

void HeroRopeManager_virtual_12(longlong param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = (longlong)param_2;
  *(undefined4 *)(param_1 + 0x7e10 + lVar1 * 0xc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7e14 + lVar1 * 0xc) = 0;
  *(undefined4 *)(param_1 + 0x7e18 + lVar1 * 0xc) = 0;
  return;
}


/* HeroRopeManager_virtual_13 @ 0x1409602b0 */

void HeroRopeManager_virtual_13(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x7e10 + (ulonglong)*(ushort *)(param_2 + 0x708) * 0xc);
  if (iVar1 == *(int *)(param_2 + 0x704)) {
    *(uint *)(param_1 + 0x7e10 + (ulonglong)*(ushort *)(param_2 + 0x708) * 0xc) = (uint)(iVar1 == 0)
    ;
  }
  return;
}


/* HeroRopeManager_virtual_14 @ 0x14095f860 */

longlong FUN_14095f860(longlong param_1,int param_2)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  longlong *plVar4;
  
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dd6340);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  if (lVar3 == 0) {
    return *(longlong *)(param_1 + 0x7cd8);
  }
  lVar3 = func_0x000140923770(lVar3);
  if ((param_2 - 3U & 0xfffffffd) == 0) {
LAB_14095f9a6:
    return lVar3 + 0x390;
  }
  if (param_2 == 4) {
    return lVar3 + 0x508;
  }
  if (param_2 != 6) {
    if (param_2 == 7) {
      return lVar3 + 0x970;
    }
    if (param_2 == 2) {
      return lVar3 + 0x218;
    }
    lVar1 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar1 + 0x88) == 0) {
      plVar4 = (longlong *)FUN_14167ab40(lVar1 + 0x58,0x146dabca0);
    }
    else {
      plVar4 = (longlong *)func_0x0001416799a0(lVar1 + 0x80);
    }
    cVar2 = (**(code **)(*plVar4 + 0x60))(plVar4,0x400);
    if (cVar2 == '\0') {
      cVar2 = (**(code **)(*plVar4 + 0x60))(plVar4,0x800);
      if (cVar2 == '\0') {
        return lVar3 + 0x218;
      }
      goto LAB_14095f9a6;
    }
  }
  return lVar3 + 0x680;
}


/* HeroRopeManager_virtual_15 @ 0x14095f9c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14095f9c0(longlong param_1,longlong param_2,float param_3,int *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  float fVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  float *pfVar7;
  longlong lVar8;
  int iVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  uint uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fStackX_10;
  float fStack_188;
  float fStack_184;
  float fStack_180;
  undefined8 uStack_178;
  float fStack_170;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  undefined8 uStack_158;
  float fStack_150;
  float fStack_148;
  float fStack_144;
  float fStack_140;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  undefined8 uStack_f4;
  float fStack_ec;
  undefined1 auStack_d8 [176];
  
  if ((((*(byte *)(param_2 + 0x70c) & 2) == 0) && (1 < *param_4)) &&
     (*(int *)(param_2 + 0x700) == 2)) {
    uVar4 = (ulonglong)*(ushort *)(param_2 + 0x708);
    func_0x000140678b50(param_1,&fStack_130,*(undefined4 *)(param_2 + 0x704));
    func_0x000140678680(param_1,&fStack_120,*(undefined4 *)(param_2 + 0x704));
    func_0x000140678640(param_1,&fStack_110,*(undefined4 *)(param_2 + 0x704));
    fVar3 = _DAT_14382dce0;
    uVar10 = 0;
    iVar9 = 0;
    uVar2 = *(undefined8 *)(param_1 + 0x7df8 + (longlong)*(int *)(param_2 + 0x704) * 0xc);
    fStack_180 = *(float *)(param_1 + 0x7e00 + (longlong)*(int *)(param_2 + 0x704) * 0xc);
    fStack_188 = (float)uVar2;
    fStack_184 = (float)((ulonglong)uVar2 >> 0x20);
    fVar18 = param_3 * *(float *)(param_1 + 0x7e18 + uVar4 * 0xc) +
             *(float *)(param_1 + 0x7e14 + uVar4 * 0xc);
    if (_DAT_14382dce0 <= fVar18) {
      fVar18 = _DAT_14382dce0;
    }
    *(float *)(param_1 + 0x7e14 + uVar4 * 0xc) = fVar18;
    fVar11 = fVar18;
    if (fVar18 <= _DAT_143830ee8) {
      fVar11 = _DAT_143830ee8;
    }
    if (*(int *)(param_1 + 0x7e10 + uVar4 * 0xc) != -1) {
      func_0x000140678640(param_1,&uStack_178);
      func_0x000140678680(param_1,&uStack_158,*(undefined4 *)(param_1 + 0x7e10 + uVar4 * 0xc));
      iVar9 = 2;
      *(undefined8 *)(param_2 + 0x7c) = uStack_178;
      *(float *)(param_2 + 0x84) = fStack_170;
      *(undefined8 *)(param_2 + 0x88) = uStack_158;
      *(float *)(param_2 + 0x90) = fStack_150;
      fVar18 = *(float *)(param_1 + 0x7e14 + uVar4 * 0xc);
    }
    uVar4 = (ulonglong)(iVar9 + 8);
    fStack_150 = (fStack_118 - fStack_128) * fVar11 + fStack_128;
    *(float *)(param_2 + 0x1c + uVar4 * 0xc) = (fStack_110 - fStack_130) * fVar18 + fStack_130;
    *(float *)(param_2 + 0x20 + uVar4 * 0xc) = (fStack_10c - fStack_12c) * fVar18 + fStack_12c;
    *(float *)(param_2 + 0x24 + uVar4 * 0xc) = (fStack_108 - fStack_128) * fVar18 + fStack_128;
    *(ulonglong *)(param_2 + 0x1c + (ulonglong)(iVar9 + 9) * 0xc) =
         CONCAT44((fStack_11c - fStack_12c) * fVar11 + fStack_12c,
                  (fStack_120 - fStack_130) * fVar11 + fStack_130);
    *(float *)(param_2 + 0x24 + (ulonglong)(iVar9 + 9) * 0xc) = fStack_150;
    *param_4 = iVar9 + 10;
    fVar11 = (float)FUN_1402c2450(&fStack_188);
    fStack_148 = (float)*(undefined8 *)(param_2 + 0x7c);
    fStack_134 = (fVar11 - _DAT_14382ee94) * _DAT_1438ac38c;
    fStack_140 = *(float *)(param_2 + 0x84);
    fVar18 = (fVar11 - _DAT_143830120) * _DAT_1438abcb8;
    fVar11 = (fVar11 - _DAT_143834a14) * _DAT_14382e120;
    if (fStack_134 <= 0.0) {
      fStack_134 = 0.0;
    }
    fStack_138 = (*(float *)(param_2 + 0x6b4) - _DAT_14382ee88) * _DAT_1438627c8;
    if (fVar18 <= 0.0) {
      fVar18 = 0.0;
    }
    if (fVar11 <= 0.0) {
      fVar11 = 0.0;
    }
    if (fVar3 <= fStack_134) {
      fStack_134 = fVar3;
    }
    if (fStack_138 <= 0.0) {
      fStack_138 = 0.0;
    }
    if (fVar3 <= fVar18) {
      fVar18 = fVar3;
    }
    if (fVar3 <= fVar11) {
      fVar11 = fVar3;
    }
    if (fVar3 <= fStack_138) {
      fStack_138 = fVar3;
    }
    fStack_134 = fStack_134 * fStack_138;
    fStack_160 = (fVar18 * _DAT_143837a1c + _DAT_14382e124) * fStack_138;
    fStack_138 = ((fVar3 - fVar11) * _DAT_14386dc70 + _DAT_143834794) * fStack_138;
    uStack_178._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x7c) >> 0x20);
    fVar11 = uStack_178._4_4_;
    iVar9 = 7;
    lVar8 = 8;
    fVar21 = fStack_160 * _DAT_1438398cc;
    fVar18 = _DAT_1438398cc;
    fStack_168 = fStack_148;
    uVar15 = _DAT_14382e890;
    fStack_164 = uStack_178._4_4_;
    fStackX_10 = fStack_140;
    do {
      fVar12 = fVar3 - (float)iVar9 * fVar18;
      fVar18 = SQRT(fVar12) * fStack_138 * fVar12 * fVar12;
      fVar13 = (float)((uint)(fVar12 * fStack_160) ^ uVar15) - fStack_184 * fVar18;
      fVar17 = (float)((uint)(fStack_188 * fVar18) ^ uVar15);
      fVar12 = fVar17 + fStack_148;
      fStack_170 = (float)((uint)(fStack_180 * fVar18) ^ uVar15);
      uStack_178 = CONCAT44(fVar13,fVar17);
      fVar19 = fStack_140 + fStack_170;
      fVar13 = fVar11 + fVar13;
      fVar17 = fVar12 - fStack_168;
      fVar16 = fVar13 - fStack_164;
      fVar20 = fVar19 - fStackX_10;
      fVar18 = (float)((uint)fVar16 & _DAT_14382e160);
      if ((float)((uint)fVar16 & _DAT_14382e160) <= (float)((uint)fVar20 & _DAT_14382e160)) {
        fVar18 = (float)((uint)fVar20 & _DAT_14382e160);
      }
      if (fVar18 <= (float)((uint)fVar17 & _DAT_14382e160)) {
        fVar18 = (float)((uint)fVar17 & _DAT_14382e160);
      }
      fVar14 = fVar3 / fVar18;
      if (fVar18 <= 0.0) {
        fVar18 = 0.0;
      }
      else {
        fVar18 = SQRT(fVar14 * fVar17 * fVar14 * fVar17 + fVar14 * fVar16 * fVar14 * fVar16 +
                      fVar14 * fVar20 * fVar14 * fVar20) * fVar18;
      }
      if (fVar21 < fVar18) {
        fVar18 = fVar16 * fVar16 + fVar17 * fVar17 + fVar20 * fVar20;
        fVar12 = fVar21 / SQRT(fVar18);
        if (_DAT_14382e110 <= fVar18) {
          fVar19 = fVar12 * fVar20;
          fVar13 = fVar12 * fVar16;
          fVar12 = fVar12 * fVar17;
        }
        else {
          fVar19 = 0.0;
          fVar13 = 0.0;
          fVar12 = fVar21;
        }
        fVar19 = fVar19 + fStackX_10;
        fVar12 = fVar12 + fStack_168;
        fVar13 = fVar13 + fStack_164;
        fStack_170 = fVar19 - fStack_140;
        uStack_178 = CONCAT44(fVar13 - fVar11,fVar12 - fStack_148);
      }
      lVar5 = (longlong)iVar9;
      lVar1 = param_2 + lVar5 * 0xc;
      fStack_150 = fVar19;
      puVar6 = (undefined8 *)
               FUN_141c47af0(auStack_d8,lVar1 + 0x61c,&uStack_178,_DAT_143848d00,param_3);
      fVar18 = _DAT_1438398cc;
      uVar15 = _DAT_14382e890;
      iVar9 = iVar9 + -1;
      *(undefined8 *)(lVar1 + 0x61c) = *puVar6;
      *(undefined4 *)(lVar1 + 0x624) = *(undefined4 *)(puVar6 + 1);
      *(ulonglong *)(param_2 + 0x1c + lVar5 * 0xc) = CONCAT44(fVar13,fVar12);
      *(float *)(param_2 + 0x24 + lVar5 * 0xc) = fStack_150;
      lVar8 = lVar8 + -1;
      fStack_168 = fVar12;
      fStack_164 = fVar13;
      fStackX_10 = fVar19;
    } while (lVar8 != 0);
    fStack_144 = fVar11 - *(float *)(param_2 + 0x20);
    fStack_140 = fStack_140 - *(float *)(param_2 + 0x24);
    fStack_148 = fStack_148 - *(float *)(param_2 + 0x1c);
    fVar18 = (float)((uint)fStack_140 & _DAT_14382e160);
    if ((float)((uint)fStack_140 & _DAT_14382e160) <= (float)((uint)fStack_144 & _DAT_14382e160)) {
      fVar18 = (float)((uint)fStack_144 & _DAT_14382e160);
    }
    if (fVar18 <= (float)((uint)fStack_148 & _DAT_14382e160)) {
      fVar18 = (float)((uint)fStack_148 & _DAT_14382e160);
    }
    if (0.0 < fVar18) {
      fVar18 = fVar3 / fVar18;
      fStack_148 = fVar18 * fStack_148;
      fStack_144 = fVar18 * fStack_144;
      fVar18 = fVar18 * fStack_140;
      fStack_140 = fVar3 / SQRT(fStack_144 * fStack_144 + fStack_148 * fStack_148 + fVar18 * fVar18)
      ;
      fStack_148 = fStack_140 * fStack_148;
      fStack_144 = fStack_140 * fStack_144;
      fStack_140 = fStack_140 * fVar18;
    }
    fStack_188 = 0.0;
    fStack_184 = 1.0;
    fStack_180 = 0.0;
    FUN_141c511e0(&fStack_100,&fStack_148,&fStack_188);
    fVar12 = fStack_134;
    fVar21 = _DAT_1438ad00c;
    fVar11 = _DAT_143840ed0;
    fVar18 = _DAT_14382e138;
    pfVar7 = (float *)(param_2 + 0x24);
    fStack_180 = fStack_ec;
    fStack_188 = (float)uStack_f4;
    fStack_184 = (float)((ulonglong)uStack_f4 >> 0x20);
    do {
      fVar17 = fVar3 - (float)uVar10 * _DAT_1438398cc;
      fVar16 = fVar17 * fStack_160 * fVar18 + *(float *)(param_2 + 0x6b4) * fVar21 * fVar12;
      fVar13 = (float)func_0x000141c58e50(fVar16);
      fVar19 = fVar13 * _DAT_14382ee88 * fVar12;
      fVar16 = (float)func_0x000141c58e50(fVar16 + fVar11);
      fVar13 = _DAT_143834794;
      uVar10 = uVar10 + 1;
      fVar17 = fVar17 * _DAT_143834a14;
      if (fVar17 <= 0.0) {
        fVar17 = 0.0;
      }
      if (fVar3 <= fVar17) {
        fVar17 = fVar3;
      }
      fVar20 = fStack_fc * fVar16 * _DAT_143834794;
      pfVar7[-2] = (fStack_100 * fVar16 * _DAT_143834794 * fVar12 + fStack_188 * fVar19) * fVar17 +
                   pfVar7[-2];
      pfVar7[-1] = (fVar20 * fVar12 + fStack_184 * fVar19) * fVar17 + pfVar7[-1];
      *pfVar7 = (fStack_f8 * fVar16 * fVar13 * fVar12 + fStack_ec * fVar19) * fVar17 + *pfVar7;
      pfVar7 = pfVar7 + 3;
    } while (uVar10 < 8);
  }
  return;
}


