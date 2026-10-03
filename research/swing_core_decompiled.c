/* Decompiled from the locally installed Spider-Man.exe.
 * Class names come from RTTI. Vtable slot names are labels, not recovered source names.
 * Types and unnamed callees are incomplete. This is research, not recompilable source. */

/* SwingRegion_140ab209a @ 0x140ab209a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab209a(undefined8 param_1,undefined8 param_2,float param_3,float param_4)

{
  float fVar1;
  longlong lVar2;
  longlong *plVar3;
  byte *pbVar4;
  ulonglong uVar5;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int *unaff_RDI;
  ulonglong uVar6;
  undefined8 unaff_R15;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  float in_XMM4_Da;
  float in_XMM5_Da;
  float unaff_XMM6_Da;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  float unaff_XMM12_Da;
  float unaff_XMM13_Da;
  
  fVar8 = (param_3 * unaff_XMM13_Da + in_XMM4_Da * in_XMM5_Da + param_4 * unaff_XMM11_Da) /
          unaff_XMM12_Da;
  if (unaff_XMM13_Da * fVar8 * unaff_XMM13_Da + in_XMM5_Da * in_XMM5_Da * fVar8 +
      unaff_XMM11_Da * unaff_XMM11_Da * fVar8 < unaff_XMM9_Da) {
    *(float *)(unaff_RBP + -0x80) = in_XMM4_Da - in_XMM5_Da * fVar8;
    *(float *)(unaff_RBP + -0x78) = param_4 - unaff_XMM11_Da * fVar8;
  }
  if (((*(char *)(unaff_RBX + 0x150) == (char)unaff_R15) || (unaff_RDI == (int *)0x0)) ||
     (*unaff_RDI != *(int *)(unaff_RBX + 0x120))) {
    if (unaff_XMM7_Da < unaff_XMM9_Da) {
      unaff_XMM10_Da = _DAT_14382e13c;
    }
    fVar8 = (float)((uint)unaff_XMM7_Da & _DAT_14382e160);
    if (unaff_XMM8_Da * _DAT_14383f848 <= (float)((uint)unaff_XMM7_Da & _DAT_14382e160)) {
      fVar8 = unaff_XMM8_Da * _DAT_14383f848;
    }
    *(float *)(unaff_RBP + -0x7c) = fVar8 * unaff_XMM10_Da;
    goto LAB_140ab226c;
  }
  fVar8 = (float)unaff_RDI[0xc0];
  lVar2 = unaff_RBP + -0x60;
  fVar1 = *(float *)(unaff_RBX + 0x128);
  fVar9 = fVar8 * (float)unaff_RDI[0xbd];
  if (fVar1 <= fVar9) {
    fVar1 = *(float *)(unaff_RBX + 300);
    if (fVar1 <= fVar9) {
      if (unaff_XMM9_Da < fVar1) {
        func_0x0001415c00e0(fVar1,fVar8,lVar2,fVar1,fVar9);
        fVar8 = (((float)(_DAT_145d9fe68 ^ _DAT_14382e890) - *(float *)(unaff_RBX + 0x14c)) /
                *(float *)(unaff_RBX + 0x140)) * *(float *)(unaff_RBP + -0x48) +
                *(float *)(unaff_RBX + 0x14c) + *(float *)(unaff_RBX + 0x154);
        goto LAB_140ab2227;
      }
      func_0x0001415c00e0(fVar1,fVar8,lVar2,fVar9,fVar8);
    }
    else {
      func_0x0001415c00e0(fVar1,fVar8,lVar2,fVar9,fVar1);
      unaff_XMM6_Da = *(float *)(unaff_RBX + 0x14c) + *(float *)(unaff_RBX + 0x154);
    }
    fVar8 = unaff_XMM6_Da - *(float *)(unaff_RBP + -0x48);
  }
  else {
    func_0x0001415c00e0(fVar1,fVar8,lVar2,fVar9,fVar1);
    FUN_1402c48c0(*(undefined8 *)(unaff_RBX + 8));
    fVar8 = *(float *)(unaff_RBX + 0x154) -
            *(float *)(unaff_RBP + -0x48) * *(float *)(unaff_RBX + 0x148);
  }
LAB_140ab2227:
  lVar2 = FUN_1402c48c0(*(undefined8 *)(unaff_RBX + 8));
  *(float *)(unaff_RBP + -0x7c) = fVar8 - *(float *)(lVar2 + 4);
LAB_140ab226c:
  fVar8 = *(float *)(unaff_RBX + 0x170);
  if (unaff_XMM9_Da < fVar8) {
    if ((unaff_XMM8_Da < fVar8) || (unaff_XMM8_Da < unaff_XMM9_Da)) {
      *(float *)(unaff_RBX + 0x170) = fVar8 - unaff_XMM8_Da;
    }
    else {
      *(int *)(unaff_RBX + 0x170) = (int)unaff_R15;
      lVar2 = *(longlong *)(unaff_RBX + 8);
      if ((ushort)unaff_R15 < *(ushort *)(lVar2 + 0x88)) {
        plVar3 = (longlong *)func_0x0001416799a0(lVar2 + 0x80);
      }
      else {
        plVar3 = (longlong *)FUN_14167ab40(lVar2 + 0x58,0x146dabca0);
      }
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x58))(plVar3,0x4000000);
      }
    }
  }
  *(undefined8 *)(unaff_RBP + 0x20) = *(undefined8 *)(unaff_RBX + 0xf0);
  FUN_141c649a0(unaff_RBP + 0x430,0,0x20);
  *(undefined8 *)(unaff_RBP + 0x450) = unaff_R15;
  pbVar4 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xcb86ef8f);
  uVar6 = 0xffffffff;
  if (pbVar4 == (byte *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = (ulonglong)*pbVar4;
  }
  FUN_141f9e0e0(unaff_RBP + 0x20,uVar5,unaff_RBP + -0x80,0xc);
  pbVar4 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xb37847ee);
  if (pbVar4 != (byte *)0x0) {
    uVar6 = (ulonglong)*pbVar4;
  }
  uVar7 = FUN_141f9e0e0(unaff_RBP + 0x20,uVar6,&stack0x00000070,0xc);
  FUN_1420e0880(uVar7,unaff_RBP + 0x20);
  return;
}


/* SwingRegion_140ab2107 @ 0x140ab2107 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab2107(undefined8 param_1,float param_2,undefined8 param_3,float param_4)

{
  float fVar1;
  longlong lVar2;
  longlong *plVar3;
  byte *pbVar4;
  ulonglong uVar5;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int *unaff_RDI;
  ulonglong uVar6;
  undefined8 unaff_R15;
  undefined4 uVar7;
  float fVar8;
  float in_XMM4_Da;
  float unaff_XMM6_Da;
  float fVar9;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM10_Da;
  float unaff_XMM12_Da;
  
  *(float *)(unaff_RBP + -0x80) = in_XMM4_Da - param_2;
  *(float *)(unaff_RBP + -0x78) = param_4 - unaff_XMM12_Da;
  if (((*(char *)(unaff_RBX + 0x150) == (char)unaff_R15) || (unaff_RDI == (int *)0x0)) ||
     (*unaff_RDI != *(int *)(unaff_RBX + 0x120))) {
    if (unaff_XMM7_Da < unaff_XMM9_Da) {
      unaff_XMM10_Da = _DAT_14382e13c;
    }
    fVar9 = (float)((uint)unaff_XMM7_Da & _DAT_14382e160);
    if (unaff_XMM8_Da * _DAT_14383f848 <= (float)((uint)unaff_XMM7_Da & _DAT_14382e160)) {
      fVar9 = unaff_XMM8_Da * _DAT_14383f848;
    }
    *(float *)(unaff_RBP + -0x7c) = fVar9 * unaff_XMM10_Da;
    goto LAB_140ab226c;
  }
  fVar9 = (float)unaff_RDI[0xc0];
  lVar2 = unaff_RBP + -0x60;
  fVar1 = *(float *)(unaff_RBX + 0x128);
  fVar8 = fVar9 * (float)unaff_RDI[0xbd];
  if (fVar1 <= fVar8) {
    fVar1 = *(float *)(unaff_RBX + 300);
    if (fVar1 <= fVar8) {
      if (unaff_XMM9_Da < fVar1) {
        func_0x0001415c00e0(fVar1,fVar9,lVar2,fVar1,fVar8);
        fVar9 = (((float)(_DAT_145d9fe68 ^ _DAT_14382e890) - *(float *)(unaff_RBX + 0x14c)) /
                *(float *)(unaff_RBX + 0x140)) * *(float *)(unaff_RBP + -0x48) +
                *(float *)(unaff_RBX + 0x14c) + *(float *)(unaff_RBX + 0x154);
        goto LAB_140ab2227;
      }
      func_0x0001415c00e0(fVar1,fVar9,lVar2,fVar8,fVar9);
    }
    else {
      func_0x0001415c00e0(fVar1,fVar9,lVar2,fVar8,fVar1);
      unaff_XMM6_Da = *(float *)(unaff_RBX + 0x14c) + *(float *)(unaff_RBX + 0x154);
    }
    fVar9 = unaff_XMM6_Da - *(float *)(unaff_RBP + -0x48);
  }
  else {
    func_0x0001415c00e0(fVar1,fVar9,lVar2,fVar8,fVar1);
    FUN_1402c48c0(*(undefined8 *)(unaff_RBX + 8));
    fVar9 = *(float *)(unaff_RBX + 0x154) -
            *(float *)(unaff_RBP + -0x48) * *(float *)(unaff_RBX + 0x148);
  }
LAB_140ab2227:
  lVar2 = FUN_1402c48c0(*(undefined8 *)(unaff_RBX + 8));
  *(float *)(unaff_RBP + -0x7c) = fVar9 - *(float *)(lVar2 + 4);
LAB_140ab226c:
  fVar9 = *(float *)(unaff_RBX + 0x170);
  if (unaff_XMM9_Da < fVar9) {
    if ((unaff_XMM8_Da < fVar9) || (unaff_XMM8_Da < unaff_XMM9_Da)) {
      *(float *)(unaff_RBX + 0x170) = fVar9 - unaff_XMM8_Da;
    }
    else {
      *(int *)(unaff_RBX + 0x170) = (int)unaff_R15;
      lVar2 = *(longlong *)(unaff_RBX + 8);
      if ((ushort)unaff_R15 < *(ushort *)(lVar2 + 0x88)) {
        plVar3 = (longlong *)func_0x0001416799a0(lVar2 + 0x80);
      }
      else {
        plVar3 = (longlong *)FUN_14167ab40(lVar2 + 0x58,0x146dabca0);
      }
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x58))(plVar3,0x4000000);
      }
    }
  }
  *(undefined8 *)(unaff_RBP + 0x20) = *(undefined8 *)(unaff_RBX + 0xf0);
  FUN_141c649a0(unaff_RBP + 0x430,0,0x20);
  *(undefined8 *)(unaff_RBP + 0x450) = unaff_R15;
  pbVar4 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xcb86ef8f);
  uVar6 = 0xffffffff;
  if (pbVar4 == (byte *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = (ulonglong)*pbVar4;
  }
  FUN_141f9e0e0(unaff_RBP + 0x20,uVar5,unaff_RBP + -0x80,0xc);
  pbVar4 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xb37847ee);
  if (pbVar4 != (byte *)0x0) {
    uVar6 = (ulonglong)*pbVar4;
  }
  uVar7 = FUN_141f9e0e0(unaff_RBP + 0x20,uVar6,&stack0x00000070,0xc);
  FUN_1420e0880(uVar7,unaff_RBP + 0x20);
  return;
}


/* SwingRegion_140ab2130 @ 0x140ab2130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab2130(void)

{
  float fVar1;
  longlong lVar2;
  longlong *plVar3;
  byte *pbVar4;
  ulonglong uVar5;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int *unaff_RDI;
  ulonglong uVar6;
  undefined8 unaff_R15;
  undefined4 uVar7;
  float fVar8;
  float unaff_XMM6_Da;
  float fVar9;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM10_Da;
  
  if ((unaff_RDI == (int *)0x0) || (*unaff_RDI != *(int *)(unaff_RBX + 0x120))) {
    if (unaff_XMM7_Da < unaff_XMM9_Da) {
      unaff_XMM10_Da = _DAT_14382e13c;
    }
    fVar9 = (float)((uint)unaff_XMM7_Da & _DAT_14382e160);
    if (unaff_XMM8_Da * _DAT_14383f848 <= (float)((uint)unaff_XMM7_Da & _DAT_14382e160)) {
      fVar9 = unaff_XMM8_Da * _DAT_14383f848;
    }
    *(float *)(unaff_RBP + -0x7c) = fVar9 * unaff_XMM10_Da;
    goto LAB_140ab226c;
  }
  fVar9 = (float)unaff_RDI[0xc0];
  lVar2 = unaff_RBP + -0x60;
  fVar1 = *(float *)(unaff_RBX + 0x128);
  fVar8 = fVar9 * (float)unaff_RDI[0xbd];
  if (fVar1 <= fVar8) {
    fVar1 = *(float *)(unaff_RBX + 300);
    if (fVar1 <= fVar8) {
      if (unaff_XMM9_Da < fVar1) {
        func_0x0001415c00e0(fVar1,fVar9,lVar2,fVar1,fVar8);
        fVar9 = (((float)(_DAT_145d9fe68 ^ _DAT_14382e890) - *(float *)(unaff_RBX + 0x14c)) /
                *(float *)(unaff_RBX + 0x140)) * *(float *)(unaff_RBP + -0x48) +
                *(float *)(unaff_RBX + 0x14c) + *(float *)(unaff_RBX + 0x154);
        goto LAB_140ab2227;
      }
      func_0x0001415c00e0(fVar1,fVar9,lVar2,fVar8,fVar9);
    }
    else {
      func_0x0001415c00e0(fVar1,fVar9,lVar2,fVar8,fVar1);
      unaff_XMM6_Da = *(float *)(unaff_RBX + 0x14c) + *(float *)(unaff_RBX + 0x154);
    }
    fVar9 = unaff_XMM6_Da - *(float *)(unaff_RBP + -0x48);
  }
  else {
    func_0x0001415c00e0(fVar1,fVar9,lVar2,fVar8,fVar1);
    FUN_1402c48c0(*(undefined8 *)(unaff_RBX + 8));
    fVar9 = *(float *)(unaff_RBX + 0x154) -
            *(float *)(unaff_RBP + -0x48) * *(float *)(unaff_RBX + 0x148);
  }
LAB_140ab2227:
  lVar2 = FUN_1402c48c0(*(undefined8 *)(unaff_RBX + 8));
  *(float *)(unaff_RBP + -0x7c) = fVar9 - *(float *)(lVar2 + 4);
LAB_140ab226c:
  fVar9 = *(float *)(unaff_RBX + 0x170);
  if (unaff_XMM9_Da < fVar9) {
    if ((unaff_XMM8_Da < fVar9) || (unaff_XMM8_Da < unaff_XMM9_Da)) {
      *(float *)(unaff_RBX + 0x170) = fVar9 - unaff_XMM8_Da;
    }
    else {
      *(int *)(unaff_RBX + 0x170) = (int)unaff_R15;
      lVar2 = *(longlong *)(unaff_RBX + 8);
      if ((ushort)unaff_R15 < *(ushort *)(lVar2 + 0x88)) {
        plVar3 = (longlong *)func_0x0001416799a0(lVar2 + 0x80);
      }
      else {
        plVar3 = (longlong *)FUN_14167ab40(lVar2 + 0x58,0x146dabca0);
      }
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x58))(plVar3,0x4000000);
      }
    }
  }
  *(undefined8 *)(unaff_RBP + 0x20) = *(undefined8 *)(unaff_RBX + 0xf0);
  FUN_141c649a0(unaff_RBP + 0x430,0,0x20);
  *(undefined8 *)(unaff_RBP + 0x450) = unaff_R15;
  pbVar4 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xcb86ef8f);
  uVar6 = 0xffffffff;
  if (pbVar4 == (byte *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = (ulonglong)*pbVar4;
  }
  FUN_141f9e0e0(unaff_RBP + 0x20,uVar5,unaff_RBP + -0x80,0xc);
  pbVar4 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xb37847ee);
  if (pbVar4 != (byte *)0x0) {
    uVar6 = (ulonglong)*pbVar4;
  }
  uVar7 = FUN_141f9e0e0(unaff_RBP + 0x20,uVar6,&stack0x00000070,0xc);
  FUN_1420e0880(uVar7,unaff_RBP + 0x20);
  return;
}


/* SwingRegion_140ab229b @ 0x140ab229b */

void SwingRegion_140ab229b(float param_1)

{
  longlong lVar1;
  longlong *plVar2;
  byte *pbVar3;
  ulonglong uVar4;
  longlong unaff_RBX;
  longlong unaff_RBP;
  ulonglong uVar5;
  undefined8 unaff_R15;
  undefined4 uVar6;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  
  if ((unaff_XMM8_Da < param_1) || (unaff_XMM8_Da < unaff_XMM9_Da)) {
    *(float *)(unaff_RBX + 0x170) = param_1 - unaff_XMM8_Da;
  }
  else {
    *(int *)(unaff_RBX + 0x170) = (int)unaff_R15;
    lVar1 = *(longlong *)(unaff_RBX + 8);
    if ((ushort)unaff_R15 < *(ushort *)(lVar1 + 0x88)) {
      plVar2 = (longlong *)func_0x0001416799a0(lVar1 + 0x80);
    }
    else {
      plVar2 = (longlong *)FUN_14167ab40(lVar1 + 0x58,0x146dabca0);
    }
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x58))(plVar2,0x4000000);
    }
  }
  *(undefined8 *)(unaff_RBP + 0x20) = *(undefined8 *)(unaff_RBX + 0xf0);
  FUN_141c649a0(unaff_RBP + 0x430,0,0x20);
  *(undefined8 *)(unaff_RBP + 0x450) = unaff_R15;
  pbVar3 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xcb86ef8f);
  uVar5 = 0xffffffff;
  if (pbVar3 == (byte *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = (ulonglong)*pbVar3;
  }
  FUN_141f9e0e0(unaff_RBP + 0x20,uVar4,unaff_RBP + -0x80,0xc);
  pbVar3 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xb37847ee);
  if (pbVar3 != (byte *)0x0) {
    uVar5 = (ulonglong)*pbVar3;
  }
  uVar6 = FUN_141f9e0e0(unaff_RBP + 0x20,uVar5,&stack0x00000070,0xc);
  FUN_1420e0880(uVar6,unaff_RBP + 0x20);
  return;
}


/* SwingRegion_140ab2353 @ 0x140ab2353 */

void SwingRegion_140ab2353(void)

{
  undefined1 *in_RAX;
  byte *pbVar1;
  longlong unaff_RBP;
  uint unaff_EDI;
  
  FUN_141f9e0e0(unaff_RBP + 0x20,*in_RAX,unaff_RBP + -0x80,0xc);
  pbVar1 = (byte *)FUN_141bcf3e0(*(longlong *)(unaff_RBP + 0x20) + 0x10,0xb37847ee);
  if (pbVar1 != (byte *)0x0) {
    unaff_EDI = (uint)*pbVar1;
  }
  FUN_141f9e0e0(unaff_RBP + 0x20,unaff_EDI,&stack0x00000070,0xc);
  FUN_1420e0880();
  return;
}


/* SwingRegion_140ab23c0 @ 0x140ab23c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab23c0(longlong param_1,undefined4 param_2)

{
  longlong *plVar1;
  byte *pbVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  float fVar6;
  undefined4 auStackX_8 [2];
  undefined4 auStackX_18 [2];
  longlong alStack_898 [130];
  undefined1 auStack_488 [32];
  undefined8 uStack_468;
  longlong alStack_458 [130];
  undefined1 auStack_48 [32];
  undefined8 uStack_28;
  
  FUN_1416761c0(param_1,0x146df2410,3,param_2);
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    plVar1 = (longlong *)FUN_14167ab40(lVar3 + 0x58,0x146dae1c0);
  }
  else {
    plVar1 = (longlong *)func_0x0001416799a0(lVar3 + 0x80);
  }
  FUN_14088f6e0(plVar1);
  auStackX_8[0] = (**(code **)(*plVar1 + 0x58))(plVar1);
  auStackX_18[0] = (**(code **)(*plVar1 + 0x50))(plVar1);
  alStack_458[0] = *(longlong *)(param_1 + 0xf0);
  FUN_141c649a0(auStack_48,0,0x20);
  uStack_28 = 0;
  pbVar2 = (byte *)FUN_141bcf3e0(alStack_458[0] + 0x10,0x3cb31d7d);
  uVar5 = 0xffffffff;
  if (pbVar2 == (byte *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = (ulonglong)*pbVar2;
  }
  FUN_141f9e0e0(alStack_458,uVar4,auStackX_8,4);
  pbVar2 = (byte *)FUN_141bcf3e0(alStack_458[0] + 0x10,0x3ecc7218);
  if (pbVar2 == (byte *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = (ulonglong)*pbVar2;
  }
  FUN_141f9e0e0(alStack_458,uVar4,auStackX_18,4);
  FUN_1420e0880(param_1,alStack_458);
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x1473d09e0);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  *(uint *)(lVar3 + 0x48) = *(uint *)(lVar3 + 0x48) | 2;
  FUN_1415c2410(lVar3,1);
  *(uint *)(lVar3 + 0x48) = *(uint *)(lVar3 + 0x48) & 0xfffffffd;
  fVar6 = (float)func_0x0001420e0a50(param_1);
  if (_DAT_145d9fe48 < fVar6) {
    alStack_898[0] = *(longlong *)(param_1 + 0xe8);
    FUN_141c649a0(auStack_488,0,0x20);
    uStack_468 = 0;
    FUN_141fe0f20(alStack_898,*(undefined8 *)(param_1 + 8),0);
    FUN_1420e09d0(param_1,alStack_898,_DAT_14382ee88);
    pbVar2 = (byte *)FUN_141bcf3e0(alStack_898[0] + 0x10,0x3cb31d7d);
    if (pbVar2 == (byte *)0x0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = (ulonglong)*pbVar2;
    }
    FUN_141f9e0e0(alStack_898,uVar4,auStackX_8,4);
    pbVar2 = (byte *)FUN_141bcf3e0(alStack_898[0] + 0x10,0x3ecc7218);
    if (pbVar2 != (byte *)0x0) {
      uVar5 = (uint)*pbVar2;
    }
    FUN_141f9e0e0(alStack_898,uVar5,auStackX_18,4);
    FUN_1420e0a80(param_1,alStack_898);
  }
  return;
}


/* SwingRegion_140ab2660 @ 0x140ab2660 */

void FUN_140ab2660(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  FUN_1409ca710();
  FUN_1420e1290(param_1,param_1 + 0x168,param_2);
  uVar1 = FUN_141f9e890(&UNK_14386db28);
  *(undefined8 *)(param_1 + 0xe8) = uVar1;
  uVar1 = FUN_141f9e890(&UNK_14386db40);
  *(undefined8 *)(param_1 + 0xf0) = uVar1;
  return;
}


/* SwingRegion_140ab26c0 @ 0x140ab26c0 */

void FUN_140ab26c0(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  byte *pbVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 auStackX_8 [2];
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    plVar2 = (longlong *)FUN_14167ab40(lVar1 + 0x58,0x146dae0b0);
  }
  else {
    plVar2 = (longlong *)func_0x0001416799a0(lVar1 + 0x80);
  }
  if (plVar2 != (longlong *)0x0) {
    auStackX_8[0] = (**(code **)(*plVar2 + 0x58))(plVar2);
    pbVar3 = (byte *)FUN_141bcf3e0(*param_2 + 0x10,0x3cb31d7d);
    uVar5 = 0xffffffff;
    if (pbVar3 == (byte *)0x0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = (ulonglong)*pbVar3;
    }
    FUN_141f9e0e0(param_2,uVar4,auStackX_8,4);
    auStackX_8[0] = (**(code **)(*plVar2 + 0x50))(plVar2);
    pbVar3 = (byte *)FUN_141bcf3e0(*param_2 + 0x10,0x3ecc7218);
    if (pbVar3 != (byte *)0x0) {
      uVar5 = (ulonglong)*pbVar3;
    }
    FUN_141f9e0e0(param_2,uVar5,auStackX_8,4);
  }
  return;
}


/* SwingRegion_140ab2708 @ 0x140ab2708 */

void SwingRegion_140ab2708(void)

{
  longlong in_RAX;
  byte *pbVar1;
  ulonglong uVar2;
  longlong *unaff_RBX;
  longlong *unaff_RSI;
  ulonglong uVar3;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 in_stack_00000030;
  
  in_stack_00000030 = (**(code **)(in_RAX + 0x58))();
  pbVar1 = (byte *)FUN_141bcf3e0(*unaff_RSI + 0x10,0x3cb31d7d);
  uVar3 = 0xffffffff;
  if (pbVar1 == (byte *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (ulonglong)*pbVar1;
  }
  FUN_141f9e0e0(extraout_XMM0_Da,uVar2,&stack0x00000030,4);
  in_stack_00000030 = (**(code **)(*unaff_RBX + 0x50))();
  pbVar1 = (byte *)FUN_141bcf3e0(*unaff_RSI + 0x10,0x3ecc7218);
  if (pbVar1 != (byte *)0x0) {
    uVar3 = (ulonglong)*pbVar1;
  }
  FUN_141f9e0e0(extraout_XMM0_Da_00,uVar3,&stack0x00000030,4);
  return;
}


/* SwingRegion_140ab278d @ 0x140ab278d */

void SwingRegion_140ab278d(void)

{
  return;
}


/* SwingRegion_140ab27a0 @ 0x140ab27a0 */

void FUN_140ab27a0(longlong param_1,longlong *param_2)

{
  char cVar1;
  undefined1 *puVar2;
  longlong lVar3;
  undefined4 auStackX_10 [2];
  undefined4 auStackX_18 [4];
  
  puVar2 = (undefined1 *)FUN_141bcf3e0(*param_2 + 0x10,0x3cb31d7d);
  if (puVar2 != (undefined1 *)0x0) {
    cVar1 = FUN_141f9db60(param_2,*puVar2,auStackX_10,4);
    if (cVar1 != '\0') {
      puVar2 = (undefined1 *)FUN_141bcf3e0(*param_2 + 0x10,0x3ecc7218);
      if (puVar2 != (undefined1 *)0x0) {
        cVar1 = FUN_141f9db60(param_2,*puVar2,auStackX_18,4);
        if (cVar1 != '\0') {
          lVar3 = *(longlong *)(param_1 + 8);
          if (*(short *)(lVar3 + 0x88) == 0) {
            lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dae2b0);
          }
          else {
            lVar3 = func_0x0001416799a0(lVar3 + 0x80);
          }
          if (lVar3 != 0) {
            func_0x0001408907a0(lVar3,auStackX_10[0],0);
            func_0x000140890770(lVar3,auStackX_18[0],0);
          }
        }
      }
    }
  }
  return;
}


/* SwingRegion_140ab2880 @ 0x140ab2880 */

undefined8 * FUN_140ab2880(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &UNK_1438baf50;
  func_0x000141676000();
  if ((param_2 & 1) != 0) {
    func_0x000143636c9c(param_1,0x1d0);
  }
  return param_1;
}


/* SwingRegion_140ab28c0 @ 0x140ab28c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab28c0(longlong *param_1,uint param_2,float param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  
  uVar3 = _DAT_14382f0dc;
  uVar2 = _DAT_14382dce0;
  if (0 < (int)param_2) {
    uVar4 = (ulonglong)param_2;
    do {
      lVar1 = *param_1;
      param_1 = param_1 + 1;
      if (((*(byte *)(lVar1 + 0x1d) & 2) == 0) && ((*(byte *)(lVar1 + 0x1d) & 1) != 0)) {
        FUN_1416761c0(lVar1,0x146df2510,0,param_3 * *(float *)(lVar1 + 0x10));
        FUN_1420e1e70(lVar1,lVar1 + 0x168,uVar2,uVar3);
      }
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}


/* SwingRegion_140ab28d6 @ 0x140ab28d6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab28d6(undefined8 param_1,uint param_2,float param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong *unaff_RSI;
  ulonglong uVar4;
  
  uVar3 = _DAT_14382f0dc;
  uVar2 = _DAT_14382dce0;
  uVar4 = (ulonglong)param_2;
  do {
    lVar1 = *unaff_RSI;
    unaff_RSI = unaff_RSI + 1;
    if (((*(byte *)(lVar1 + 0x1d) & 2) == 0) && ((*(byte *)(lVar1 + 0x1d) & 1) != 0)) {
      FUN_1416761c0(lVar1,0x146df2510,0,param_3 * *(float *)(lVar1 + 0x10));
      FUN_1420e1e70(lVar1,lVar1 + 0x168,uVar2,uVar3);
    }
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  return;
}


/* SwingRegion_140ab2980 @ 0x140ab2980 */

void SwingRegion_140ab2980(void)

{
  return;
}


/* SwingRegion_140ab2990 @ 0x140ab2990 */

void FUN_140ab2990(longlong *param_1,uint param_2)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  if (0 < (int)param_2) {
    uVar4 = (ulonglong)param_2;
    do {
      lVar2 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = 0;
      do {
        uVar3 = uVar3 + 0x40;
      } while (uVar3 < 0x100);
      bVar1 = *(byte *)(lVar2 + 0x1d);
      if (((bVar1 & 2) == 0) && ((bVar1 & 1) != 0)) {
        FUN_1409caa20(lVar2,*param_1);
      }
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}


/* SwingRegion_140ab29a1 @ 0x140ab29a1 */

void SwingRegion_140ab29a1(undefined8 param_1,uint param_2)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong *unaff_RBX;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)param_2;
  do {
    lVar2 = *unaff_RBX;
    unaff_RBX = unaff_RBX + 1;
    uVar3 = 0;
    do {
      uVar3 = uVar3 + 0x40;
    } while (uVar3 < 0x100);
    bVar1 = *(byte *)(lVar2 + 0x1d);
    if (((bVar1 & 2) == 0) && ((bVar1 & 1) != 0)) {
      FUN_1409caa20(lVar2,*unaff_RBX);
    }
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  return;
}


/* SwingRegion_140ab29fe @ 0x140ab29fe */

void SwingRegion_140ab29fe(void)

{
  return;
}


/* SwingRegion_140ab2a00 @ 0x140ab2a00 */

void FUN_140ab2a00(undefined8 *param_1)

{
  *param_1 = &UNK_14382ddf0;
  *(undefined4 *)((longlong)param_1 + 0x14) = 0;
  func_0x000141984310(param_1 + 3);
  *(undefined4 *)((longlong)param_1 + 0x3c) = 0;
  *param_1 = &UNK_1438bb2c8;
  func_0x000141f7b570(param_1 + 0x20);
  func_0x000141f7b570(param_1 + 0x24);
  *param_1 = &UNK_1438ce5e8;
  func_0x000141f7b570(param_1 + 0x2d);
  func_0x000141f7b570(param_1 + 0x31);
  return;
}


/* SwingRegion_140ab2a80 @ 0x140ab2a80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab2a80(longlong *param_1,undefined4 param_2)

{
  short sVar1;
  float fVar2;
  undefined4 uVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  short *apsStackX_8 [2];
  longlong alStack_478 [130];
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  undefined8 uStack_30;
  
  uStack_30 = 0x140ab2a9b;
  FUN_1416761c0(param_1,0x146df2510,0,param_2);
  uVar3 = _DAT_14382f0dc;
  fVar2 = _DAT_14382dce0;
  fVar6 = *(float *)((longlong)param_1 + 0x1c4) - *(float *)(param_1 + 0x38);
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  fVar5 = (float)func_0x0001416769f0();
  fVar5 = fVar5 * fVar2;
  *(float *)(param_1 + 0x39) = fVar5;
  if (fVar6 < fVar5) {
    alStack_478[0] = param_1[0x1d];
    FUN_141c649a0(auStack_68,0,0x20);
    uStack_48 = 0;
    FUN_141c649a0(auStack_68,0,0x20);
    uStack_48 = 0;
    apsStackX_8[0] = (short *)0x0;
    cVar4 = func_0x0001420dfa50(param_1[9],0,apsStackX_8);
    if (cVar4 != '\0') {
      sVar1 = apsStackX_8[0][1];
      cVar4 = func_0x0001420e0870(param_1);
      if (((char)sVar1 == cVar4) && (*apsStackX_8[0] == *(short *)(alStack_478[0] + 8))) {
        FUN_141f9e300(alStack_478,(longlong)apsStackX_8[0] + 3,0x7d);
        cVar4 = func_0x0001420df840(param_1[9]);
        if (cVar4 != '\0') {
          FUN_1420e1520(param_1,alStack_478,param_1 + 0x2d);
          (**(code **)(*param_1 + 0x78))(param_1,alStack_478);
          fVar5 = *(float *)(param_1 + 0x39) - fVar6;
          *(float *)(param_1 + 0x39) = fVar5;
          goto LAB_1420e1fc4;
        }
      }
    }
    fVar5 = *(float *)(param_1 + 0x39);
  }
LAB_1420e1fc4:
  fVar5 = fVar5 + *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x38) = fVar5;
  if (_DAT_14656b238 <= fVar5) {
    fVar5 = _DAT_14656b238;
  }
  *(float *)(param_1 + 0x38) = fVar5;
  alStack_478[0] = param_1[0x1e];
  FUN_141c649a0(auStack_68,0,0x20);
  uStack_48 = 0;
  FUN_1420e0c20(param_1,alStack_478,param_1 + 0x2d,uVar3);
  (**(code **)(*param_1 + 0x80))(param_1,alStack_478);
  FUN_1420e0880(param_1,alStack_478);
  return;
}


/* SwingRegion_140ab2af0 @ 0x140ab2af0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab2af0(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
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
  undefined8 *puVar12;
  longlong lVar13;
  undefined8 uVar14;
  byte bVar15;
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
  bVar15 = *(byte *)(param_2 + 0x6c) >> 4 & 1;
  *(byte *)(param_1 + 0x284) = bVar15;
  *(byte *)(param_1 + 0x28a) = *(byte *)(param_2 + 0x6c) >> 6 & 1;
  *(byte *)(param_1 + 0x1fd) = *(byte *)(param_2 + 0x6c) >> 7;
  uVar17 = _DAT_14383fd4c;
  if (bVar15 != 0) {
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
  puVar1 = *(undefined8 **)(param_1 + 8);
  puVar11 = (undefined8 *)&DAT_147afdf10;
  if ((undefined8 *)*puVar1 != (undefined8 *)0x0) {
    puVar11 = (undefined8 *)*puVar1;
  }
  uVar14 = puVar11[1];
  *(undefined8 *)(param_1 + 0x104) = *puVar11;
  *(undefined8 *)(param_1 + 0x10c) = uVar14;
  uVar14 = puVar11[3];
  *(undefined8 *)(param_1 + 0x114) = puVar11[2];
  *(undefined8 *)(param_1 + 0x11c) = uVar14;
  uVar17 = *(undefined4 *)((longlong)puVar11 + 0x24);
  uVar2 = *(undefined4 *)(puVar11 + 5);
  uVar3 = *(undefined4 *)((longlong)puVar11 + 0x2c);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(puVar11 + 4);
  *(undefined4 *)(param_1 + 0x128) = uVar17;
  *(undefined4 *)(param_1 + 300) = uVar2;
  *(undefined4 *)(param_1 + 0x130) = uVar3;
  uVar17 = *(undefined4 *)((longlong)puVar11 + 0x34);
  uVar2 = *(undefined4 *)(puVar11 + 7);
  uVar3 = *(undefined4 *)((longlong)puVar11 + 0x3c);
  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(puVar11 + 6);
  *(undefined4 *)(param_1 + 0x138) = uVar17;
  *(undefined4 *)(param_1 + 0x13c) = uVar2;
  *(undefined4 *)(param_1 + 0x140) = uVar3;
  if (*(short *)(puVar1 + 0x11) == 0) {
    plVar10 = (longlong *)FUN_14167ab40(puVar1 + 0xb,0x147c40bf0);
  }
  else {
    plVar10 = (longlong *)func_0x0001416799a0(puVar1 + 0x10,0x147c40bf0);
  }
  puVar11 = (undefined8 *)(**(code **)(*plVar10 + 0x80))(plVar10,&pcStack_c8,0);
  puVar1 = (undefined8 *)(param_1 + 0x214);
  *puVar1 = *puVar11;
  *(undefined4 *)(param_1 + 0x21c) = *(undefined4 *)(puVar11 + 1);
  if ((*(byte *)(param_2 + 0x6c) & 2) != 0) {
    *puVar1 = *(undefined8 *)(param_2 + 0x5c);
    *(undefined4 *)(param_1 + 0x21c) = *(undefined4 *)(param_2 + 100);
  }
  *(undefined8 *)(param_1 + 0x144) = *puVar1;
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x21c);
  *(bool *)(param_1 + 0x280) = 0.0 < *(float *)(param_1 + 0x218);
  puVar12 = (undefined8 *)FUN_140ab40c0(param_1,&pcStack_c8,puVar1,1);
  puVar11 = *(undefined8 **)(param_1 + 8);
  *(undefined8 *)(param_1 + 0x220) = *puVar12;
  *(undefined4 *)(param_1 + 0x228) = *(undefined4 *)(puVar12 + 1);
  pfVar16 = (float *)&DAT_147afdf10;
  if ((float *)*puVar11 != (float *)0x0) {
    pfVar16 = (float *)*puVar11;
  }
  fStack_78 = *pfVar16;
  fStack_74 = pfVar16[1];
  fStack_70 = pfVar16[2];
  fStack_6c = pfVar16[3];
  fStack_48 = pfVar16[0xc];
  fStack_44 = pfVar16[0xd];
  fStack_40 = pfVar16[0xe];
  fStack_3c = pfVar16[0xf];
  if (*(short *)(puVar11 + 0x11) == 0) {
    lVar13 = FUN_14167ab40(puVar11 + 0xb,0x146dacd70);
  }
  else {
    lVar13 = func_0x0001416799a0(puVar11 + 0x10);
  }
  pcStack_c8 = *(code **)(param_1 + 0x168);
  pcStack_a8 = *(code **)(param_1 + 0x134);
  uStack_c0 = CONCAT44(uStack_c0._4_4_,*(undefined4 *)(param_1 + 0x170));
  uStack_a0 = *(undefined4 *)(param_1 + 0x13c);
  uStack_88 = *puVar1;
  uStack_80 = *(undefined4 *)(param_1 + 0x21c);
  uVar17 = FUN_140ab38e0(lVar13 + 0x410,&pcStack_c8,&pcStack_a8,&uStack_88);
  *(undefined4 *)(param_1 + 0x22c) = uVar17;
  bVar4 = 0.0 < (*(float *)(param_1 + 0x170) - fStack_40) * fStack_70 +
                (*(float *)(param_1 + 0x168) - fStack_48) * fStack_78;
  *(bool *)(param_1 + 0x281) = bVar4;
  if (DAT_146df2615 != '\0') {
    bVar4 = !bVar4;
  }
  lVar13 = *(longlong *)(param_1 + 8);
  *(bool *)(param_1 + 0x281) = bVar4;
  *(undefined4 *)(param_1 + 0x100) = 0x3eb33333;
  if (*(short *)(lVar13 + 0x88) == 0) {
    uVar14 = FUN_14167ab40(lVar13 + 0x58,0x1473d09e0);
  }
  else {
    uVar14 = func_0x0001416799a0(lVar13 + 0x80);
  }
  FUN_1415bf500(uVar14,0);
  FUN_1415bf500(uVar14,1);
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
  FUN_140ab5e60(param_1,0,uVar14);
  FUN_140ab4cc0(param_1);
  uVar3 = _DAT_1438ce984;
  uVar2 = _DAT_1438ce97c;
  uVar17 = _DAT_1438ce968;
  _DAT_146df263c = _DAT_146df263c + 1;
  *(uint *)(plVar10 + 0xea) = *(uint *)(plVar10 + 0xea) | 0xa0;
  *(uint *)((longlong)plVar10 + 0x144) = *(uint *)((longlong)plVar10 + 0x144) | 0x10;
  func_0x000141fc3540(plVar10,uVar2,uVar3,uVar17);
  FUN_141fcc7b0(*(undefined8 *)(param_1 + 8),1);
  uVar14 = func_0x000141fc2460(plVar10);
  FUN_141fde3f0(uVar14);
  uVar14 = func_0x000141fc2460(plVar10);
  func_0x000141fde440(uVar14);
  lVar13 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar13 + 0x88) == 0) {
    plVar10 = (longlong *)FUN_14167ab40(lVar13 + 0x58,0x146dabca0);
  }
  else {
    plVar10 = (longlong *)func_0x0001416799a0(lVar13 + 0x80);
  }
  (**(code **)(*plVar10 + 0x50))(plVar10,0x2000);
  lVar13 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar13 + 0x88) == 0) {
    lVar13 = FUN_14167ab40(lVar13 + 0x58,0x146d11880);
  }
  else {
    lVar13 = func_0x0001416799a0(lVar13 + 0x80);
  }
  if (lVar13 != 0) {
    FUN_14030d190(lVar13,100);
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


/* SwingRegion_140ab3280 @ 0x140ab3280 */

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


/* SwingRegion_140ab3390 @ 0x140ab3390 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab3390(longlong param_1,longlong param_2,longlong param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  byte bVar8;
  float fVar9;
  undefined4 auStackX_8 [2];
  
  func_0x0001420dd3d0();
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x147c40bf0);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  *(uint *)(lVar5 + 0x750) = *(uint *)(lVar5 + 0x750) & 0xffffff5f;
  *(uint *)(lVar5 + 0x144) = *(uint *)(lVar5 + 0x144) & 0xffffffef;
  FUN_141fcbe90(*(undefined8 *)(param_1 + 8),1);
  fVar9 = _DAT_14382e13c;
  if (param_2 == 0) {
LAB_140ab34c7:
    bVar3 = false;
    bVar8 = 0;
    if (param_2 == 0) goto LAB_140ab34e7;
  }
  else {
    cVar4 = func_0x0001416766e0(param_2,0x146deda80);
    if (cVar4 == '\0') goto LAB_140ab34c7;
    lVar5 = *(longlong *)(param_1 + 8);
    uVar2 = *(undefined4 *)(param_3 + 0x2c);
    bVar8 = *(byte *)(param_3 + 0x83) >> 4 & 1;
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar6 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
    }
    else {
      uVar6 = func_0x0001416799a0(lVar5 + 0x80);
    }
    FUN_1415c2240(uVar6,auStackX_8,uVar2,0);
    lVar5 = func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
    if (lVar5 != 0) {
      fVar9 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar5,0x430d2232);
    }
    func_0x0001415c0440(uVar6,auStackX_8[0]);
  }
  bVar3 = false;
  if (param_2 == 0x146dfc880) {
    bVar3 = true;
    fVar9 = 0.0;
  }
LAB_140ab34e7:
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146dd77b0);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (lVar5 != 0) {
    if (((bVar8 == 0) || (*(char *)(param_1 + 0x282) == '\0')) || (fVar9 <= 0.0)) {
      puVar1 = (undefined4 *)(param_1 + 0xfc);
      FUN_1409606f0(lVar5,*puVar1);
      if (fVar9 <= 0.0) {
        if (bVar3) {
          FUN_1409605a0(lVar5,*puVar1,0,_DAT_14382e128);
        }
        else {
          FUN_14067b610(lVar5,puVar1,0,0);
        }
      }
      else {
        func_0x00014067b730(lVar5,puVar1,fVar9);
      }
    }
    else {
      func_0x00014067d760(lVar5,*(undefined4 *)(param_1 + 0xfc),0);
      FUN_1409606f0(lVar5,*(undefined4 *)(param_1 + 0xfc));
      func_0x00014067b730(lVar5,(undefined4 *)(param_1 + 0xfc),fVar9);
    }
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar6 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar6 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (*(int *)(param_1 + 0x264) != 0) {
    FUN_1415bf200(uVar6);
    *(undefined4 *)(param_1 + 0x264) = 0;
  }
  if (*(int *)(param_1 + 0x254) != 0) {
    FUN_1415bf200(uVar6);
    *(undefined4 *)(param_1 + 0x254) = 0;
  }
  if (*(int *)(param_1 + 0x270) != 0) {
    FUN_1415bf200(uVar6);
    *(undefined4 *)(param_1 + 0x270) = 0;
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    plVar7 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x146dabca0);
  }
  else {
    plVar7 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
  }
  if (plVar7 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140ab367f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar7 + 0x58))(plVar7,0x2000);
    return;
  }
  return;
}


/* SwingRegion_140ab3394 @ 0x140ab3394 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab3394(longlong param_1,longlong param_2,longlong param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  byte bVar8;
  float fVar9;
  undefined4 in_stack_00000060;
  
  func_0x0001420dd3d0();
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x147c40bf0);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  *(uint *)(lVar5 + 0x750) = *(uint *)(lVar5 + 0x750) & 0xffffff5f;
  *(uint *)(lVar5 + 0x144) = *(uint *)(lVar5 + 0x144) & 0xffffffef;
  FUN_141fcbe90(*(undefined8 *)(param_1 + 8),1);
  fVar9 = _DAT_14382e13c;
  if (param_2 == 0) {
LAB_140ab34c7:
    bVar3 = false;
    bVar8 = 0;
    if (param_2 == 0) goto LAB_140ab34e7;
  }
  else {
    cVar4 = func_0x0001416766e0(param_2,0x146deda80);
    if (cVar4 == '\0') goto LAB_140ab34c7;
    lVar5 = *(longlong *)(param_1 + 8);
    uVar2 = *(undefined4 *)(param_3 + 0x2c);
    bVar8 = *(byte *)(param_3 + 0x83) >> 4 & 1;
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar6 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
    }
    else {
      uVar6 = func_0x0001416799a0(lVar5 + 0x80);
    }
    FUN_1415c2240(uVar6,&stack0x00000060,uVar2,0);
    lVar5 = func_0x0001415ad2a0(0x1473d0730,in_stack_00000060);
    if (lVar5 != 0) {
      fVar9 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar5,0x430d2232);
    }
    func_0x0001415c0440(uVar6,in_stack_00000060);
  }
  bVar3 = false;
  if (param_2 == 0x146dfc880) {
    bVar3 = true;
    fVar9 = 0.0;
  }
LAB_140ab34e7:
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146dd77b0);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (lVar5 != 0) {
    if (((bVar8 == 0) || (*(char *)(param_1 + 0x282) == '\0')) || (fVar9 <= 0.0)) {
      puVar1 = (undefined4 *)(param_1 + 0xfc);
      FUN_1409606f0(lVar5,*puVar1);
      if (fVar9 <= 0.0) {
        if (bVar3) {
          FUN_1409605a0(lVar5,*puVar1,0,_DAT_14382e128);
        }
        else {
          FUN_14067b610(lVar5,puVar1,0,0);
        }
      }
      else {
        func_0x00014067b730(lVar5,puVar1,fVar9);
      }
    }
    else {
      func_0x00014067d760(lVar5,*(undefined4 *)(param_1 + 0xfc),0);
      FUN_1409606f0(lVar5,*(undefined4 *)(param_1 + 0xfc));
      func_0x00014067b730(lVar5,(undefined4 *)(param_1 + 0xfc),fVar9);
    }
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar6 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar6 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (*(int *)(param_1 + 0x264) != 0) {
    FUN_1415bf200(uVar6);
    *(undefined4 *)(param_1 + 0x264) = 0;
  }
  if (*(int *)(param_1 + 0x254) != 0) {
    FUN_1415bf200(uVar6);
    *(undefined4 *)(param_1 + 0x254) = 0;
  }
  if (*(int *)(param_1 + 0x270) != 0) {
    FUN_1415bf200(uVar6);
    *(undefined4 *)(param_1 + 0x270) = 0;
  }
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    plVar7 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x146dabca0);
  }
  else {
    plVar7 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
  }
  if (plVar7 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140ab367f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar7 + 0x58))(plVar7,0x2000);
    return;
  }
  return;
}


/* SwingRegion_140ab33ac @ 0x140ab33ac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab33ac(void)

{
  undefined4 *puVar1;
  bool bVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong unaff_RBX;
  byte bVar7;
  longlong unaff_RSI;
  longlong unaff_RDI;
  undefined4 uVar8;
  float fVar9;
  undefined4 in_stack_00000060;
  
  func_0x0001420dd3d0();
  lVar4 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    lVar4 = FUN_14167ab40(lVar4 + 0x58,0x147c40bf0);
  }
  else {
    lVar4 = func_0x0001416799a0(lVar4 + 0x80);
  }
  *(uint *)(lVar4 + 0x750) = *(uint *)(lVar4 + 0x750) & 0xffffff5f;
  *(uint *)(lVar4 + 0x144) = *(uint *)(lVar4 + 0x144) & 0xffffffef;
  uVar8 = FUN_141fcbe90(*(undefined8 *)(unaff_RBX + 8),1);
  fVar9 = _DAT_14382e13c;
  if (unaff_RDI == 0) {
LAB_140ab34c7:
    bVar2 = false;
    bVar7 = 0;
    if (unaff_RDI == 0) goto LAB_140ab34e7;
  }
  else {
    cVar3 = func_0x0001416766e0(uVar8,0x146deda80);
    if (cVar3 == '\0') goto LAB_140ab34c7;
    lVar4 = *(longlong *)(unaff_RBX + 8);
    uVar8 = *(undefined4 *)(unaff_RSI + 0x2c);
    bVar7 = *(byte *)(unaff_RSI + 0x83) >> 4 & 1;
    if (*(short *)(lVar4 + 0x88) == 0) {
      uVar5 = FUN_14167ab40(lVar4 + 0x58,0x1473d09e0);
    }
    else {
      uVar5 = func_0x0001416799a0(lVar4 + 0x80);
    }
    FUN_1415c2240(uVar5,&stack0x00000060,uVar8,0);
    lVar4 = func_0x0001415ad2a0(0x1473d0730,in_stack_00000060);
    if (lVar4 != 0) {
      fVar9 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8),lVar4,0x430d2232);
    }
    func_0x0001415c0440(uVar5,in_stack_00000060);
  }
  bVar2 = false;
  if (unaff_RDI == 0x146dfc880) {
    bVar2 = true;
    fVar9 = 0.0;
  }
LAB_140ab34e7:
  lVar4 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    lVar4 = FUN_14167ab40(lVar4 + 0x58,0x146dd77b0);
  }
  else {
    lVar4 = func_0x0001416799a0(lVar4 + 0x80);
  }
  if (lVar4 != 0) {
    if (((bVar7 == 0) || (*(char *)(unaff_RBX + 0x282) == '\0')) || (fVar9 <= 0.0)) {
      puVar1 = (undefined4 *)(unaff_RBX + 0xfc);
      FUN_1409606f0(lVar4,*puVar1);
      if (fVar9 <= 0.0) {
        if (bVar2) {
          FUN_1409605a0(lVar4,*puVar1,0,_DAT_14382e128);
        }
        else {
          FUN_14067b610(lVar4,puVar1,0,0);
        }
      }
      else {
        func_0x00014067b730(lVar4,puVar1,fVar9);
      }
    }
    else {
      func_0x00014067d760(lVar4,*(undefined4 *)(unaff_RBX + 0xfc),0);
      FUN_1409606f0(lVar4,*(undefined4 *)(unaff_RBX + 0xfc));
      func_0x00014067b730(lVar4,(undefined4 *)(unaff_RBX + 0xfc),fVar9);
    }
  }
  lVar4 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    uVar5 = FUN_14167ab40(lVar4 + 0x58,0x1473d09e0);
  }
  else {
    uVar5 = func_0x0001416799a0(lVar4 + 0x80);
  }
  if (*(int *)(unaff_RBX + 0x264) != 0) {
    FUN_1415bf200(uVar5);
    *(undefined4 *)(unaff_RBX + 0x264) = 0;
  }
  if (*(int *)(unaff_RBX + 0x254) != 0) {
    FUN_1415bf200(uVar5);
    *(undefined4 *)(unaff_RBX + 0x254) = 0;
  }
  if (*(int *)(unaff_RBX + 0x270) != 0) {
    FUN_1415bf200(uVar5);
    *(undefined4 *)(unaff_RBX + 0x270) = 0;
  }
  lVar4 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    plVar6 = (longlong *)FUN_14167ab40(lVar4 + 0x58,0x146dabca0);
  }
  else {
    plVar6 = (longlong *)func_0x0001416799a0(lVar4 + 0x80);
  }
  if (plVar6 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140ab367f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar6 + 0x58))(plVar6,0x2000);
    return;
  }
  return;
}


/* SwingRegion_140ab343e @ 0x140ab343e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab343e(longlong param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong unaff_RBX;
  longlong unaff_RSI;
  longlong unaff_RDI;
  float unaff_XMM6_Da;
  float unaff_XMM7_Da;
  undefined4 in_stack_00000060;
  
  uVar3 = *(undefined4 *)(unaff_RSI + 0x2c);
  bVar2 = *(byte *)(unaff_RSI + 0x83);
  if (*(short *)(param_1 + 0x88) == 0) {
    uVar4 = FUN_14167ab40(param_1 + 0x58);
  }
  else {
    uVar4 = func_0x0001416799a0(param_1 + 0x80);
  }
  FUN_1415c2240(uVar4,&stack0x00000060,uVar3,0);
  lVar5 = func_0x0001415ad2a0(0x1473d0730,in_stack_00000060);
  if (lVar5 != 0) {
    unaff_XMM6_Da = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8),lVar5,0x430d2232);
  }
  func_0x0001415c0440(uVar4,in_stack_00000060);
  if (unaff_RDI == 0x146dfc880) {
    unaff_XMM6_Da = 0.0;
  }
  lVar5 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146dd77b0);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (lVar5 != 0) {
    if ((((bVar2 >> 4 & 1) == 0) || (*(char *)(unaff_RBX + 0x282) == '\0')) ||
       (unaff_XMM6_Da <= unaff_XMM7_Da)) {
      puVar1 = (undefined4 *)(unaff_RBX + 0xfc);
      FUN_1409606f0(lVar5,*puVar1);
      if (unaff_XMM6_Da <= unaff_XMM7_Da) {
        if (unaff_RDI != 0x146dfc880) {
          FUN_14067b610(lVar5,puVar1,0,0);
        }
        else {
          FUN_1409605a0(lVar5,*puVar1,0,_DAT_14382e128);
        }
      }
      else {
        func_0x00014067b730(lVar5,puVar1,unaff_XMM6_Da);
      }
    }
    else {
      func_0x00014067d760(lVar5,*(undefined4 *)(unaff_RBX + 0xfc),0);
      FUN_1409606f0(lVar5,*(undefined4 *)(unaff_RBX + 0xfc));
      func_0x00014067b730(lVar5,(undefined4 *)(unaff_RBX + 0xfc),unaff_XMM6_Da);
    }
  }
  lVar5 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar4 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (*(int *)(unaff_RBX + 0x264) != 0) {
    FUN_1415bf200(uVar4);
    *(undefined4 *)(unaff_RBX + 0x264) = 0;
  }
  if (*(int *)(unaff_RBX + 0x254) != 0) {
    FUN_1415bf200(uVar4);
    *(undefined4 *)(unaff_RBX + 0x254) = 0;
  }
  if (*(int *)(unaff_RBX + 0x270) != 0) {
    FUN_1415bf200(uVar4);
    *(undefined4 *)(unaff_RBX + 0x270) = 0;
  }
  lVar5 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    plVar6 = (longlong *)FUN_14167ab40(lVar5 + 0x58,0x146dabca0);
  }
  else {
    plVar6 = (longlong *)func_0x0001416799a0(lVar5 + 0x80);
  }
  if (plVar6 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140ab367f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar6 + 0x58))(plVar6,0x2000);
    return;
  }
  return;
}


/* SwingRegion_140ab34a4 @ 0x140ab34a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab34a4(void)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong unaff_RBX;
  char unaff_SIL;
  longlong unaff_RDI;
  float fVar5;
  float unaff_XMM7_Da;
  undefined4 in_stack_00000060;
  
  fVar5 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8));
  func_0x0001415c0440(fVar5,in_stack_00000060);
  if (unaff_RDI == 0x146dfc880) {
    fVar5 = 0.0;
  }
  lVar2 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    lVar2 = FUN_14167ab40(lVar2 + 0x58,0x146dd77b0);
  }
  else {
    lVar2 = func_0x0001416799a0(lVar2 + 0x80);
  }
  if (lVar2 != 0) {
    if (((unaff_SIL == '\0') || (*(char *)(unaff_RBX + 0x282) == '\0')) || (fVar5 <= unaff_XMM7_Da))
    {
      puVar1 = (undefined4 *)(unaff_RBX + 0xfc);
      FUN_1409606f0(lVar2,*puVar1);
      if (fVar5 <= unaff_XMM7_Da) {
        if (unaff_RDI != 0x146dfc880) {
          FUN_14067b610(lVar2,puVar1,0,0);
        }
        else {
          FUN_1409605a0(lVar2,*puVar1,0,_DAT_14382e128);
        }
      }
      else {
        func_0x00014067b730(lVar2,puVar1,fVar5);
      }
    }
    else {
      func_0x00014067d760(lVar2,*(undefined4 *)(unaff_RBX + 0xfc),0);
      FUN_1409606f0(lVar2,*(undefined4 *)(unaff_RBX + 0xfc));
      func_0x00014067b730(lVar2,(undefined4 *)(unaff_RBX + 0xfc),fVar5);
    }
  }
  lVar2 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    uVar3 = FUN_14167ab40(lVar2 + 0x58,0x1473d09e0);
  }
  else {
    uVar3 = func_0x0001416799a0(lVar2 + 0x80);
  }
  if (*(int *)(unaff_RBX + 0x264) != 0) {
    FUN_1415bf200(uVar3);
    *(undefined4 *)(unaff_RBX + 0x264) = 0;
  }
  if (*(int *)(unaff_RBX + 0x254) != 0) {
    FUN_1415bf200(uVar3);
    *(undefined4 *)(unaff_RBX + 0x254) = 0;
  }
  if (*(int *)(unaff_RBX + 0x270) != 0) {
    FUN_1415bf200(uVar3);
    *(undefined4 *)(unaff_RBX + 0x270) = 0;
  }
  lVar2 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    plVar4 = (longlong *)FUN_14167ab40(lVar2 + 0x58,0x146dabca0);
  }
  else {
    plVar4 = (longlong *)func_0x0001416799a0(lVar2 + 0x80);
  }
  if (plVar4 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140ab367f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar4 + 0x58))(plVar4,0x2000);
    return;
  }
  return;
}


/* SwingRegion_140ab35d2 @ 0x140ab35d2 */

void SwingRegion_140ab35d2(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong unaff_RBX;
  
  uVar2 = func_0x0001416799a0(param_1 + 0x80);
  if (*(int *)(unaff_RBX + 0x264) != 0) {
    FUN_1415bf200(uVar2);
    *(undefined4 *)(unaff_RBX + 0x264) = 0;
  }
  if (*(int *)(unaff_RBX + 0x254) != 0) {
    FUN_1415bf200(uVar2);
    *(undefined4 *)(unaff_RBX + 0x254) = 0;
  }
  if (*(int *)(unaff_RBX + 0x270) != 0) {
    FUN_1415bf200(uVar2);
    *(undefined4 *)(unaff_RBX + 0x270) = 0;
  }
  lVar1 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    plVar3 = (longlong *)FUN_14167ab40(lVar1 + 0x58,0x146dabca0);
  }
  else {
    plVar3 = (longlong *)func_0x0001416799a0(lVar1 + 0x80);
  }
  if (plVar3 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140ab367f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar3 + 0x58))(plVar3,0x2000);
    return;
  }
  return;
}


/* SwingRegion_140ab3657 @ 0x140ab3657 */

void SwingRegion_140ab3657(longlong param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)func_0x0001416799a0(param_1 + 0x80);
  if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140ab367f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x58))(plVar1,0x2000);
    return;
  }
  return;
}


/* SwingRegion_140ab3690 @ 0x140ab3690 */

undefined8 * FUN_140ab3690(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &UNK_1438baf50;
  func_0x000141676000();
  if ((param_2 & 1) != 0) {
    func_0x000143636c9c(param_1,0x290);
  }
  return param_1;
}


/* SwingRegion_140ab36d0 @ 0x140ab36d0 */

undefined8 FUN_140ab36d0(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined4 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  longlong lVar15;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  uVar9 = func_0x000141affb20();
  lVar10 = (**(code **)(*param_1 + 0x38))(param_1);
  FUN_141bdb050(param_2);
  iVar5 = FUN_141bdb050(param_2);
  iVar6 = FUN_141bdb050(param_2);
  lVar15 = (longlong)iVar6;
  iVar7 = FUN_141bdb050(param_2);
  lVar1 = *param_2;
  if (iVar5 != 0x3150044) {
    return 2;
  }
  puVar11 = (undefined4 *)func_0x000141bda580(param_2,iVar6 * 8);
  func_0x000141bda580(param_2,iVar6 * 4);
  uStack_60 = 0;
  uStack_50 = 0;
  uStack_58 = 0;
  uStack_48 = 0;
  if (*(code **)(lVar10 + 0xf8) == (code *)0x0) {
    puVar12 = &uStack_60;
  }
  else {
    puVar12 = (undefined8 *)(**(code **)(lVar10 + 0xf8))(param_1);
  }
  if (*(code **)(lVar10 + 0x100) == (code *)0x0) {
    puVar13 = &uStack_50;
  }
  else {
    puVar13 = (undefined8 *)(**(code **)(lVar10 + 0x100))(param_1);
  }
  func_0x000141bda2c0(param_2,4);
  if (0 < iVar6) {
    do {
      uVar8 = func_0x000141bef6a0(lVar10,*puVar11);
      if (uVar8 == 0xffffffff) {
        FUN_141bdb620(param_2,puVar11);
      }
      else {
        cVar3 = func_0x000141bef240(lVar10,uVar8);
        uVar14 = func_0x000141bef220(lVar10,uVar8,param_1);
        if (cVar3 == '\0') {
          FUN_141bdce60(uVar14,puVar11,param_2,lVar10,uVar8,uVar9);
        }
        else if (cVar3 == '\x01') {
          FUN_141bdc9a0(uVar14,puVar11,param_2,lVar10,uVar8,uVar9);
        }
        else if (cVar3 == '\x02') {
          FUN_141bdc3d0(uVar14,puVar11,param_2,lVar10,uVar8,uVar9);
        }
        else if (cVar3 == '\x03') {
          uVar4 = func_0x000141bef430(lVar10,uVar8);
          switch(uVar4) {
          case 0:
          case 1:
          case 2:
          case 4:
          case 5:
          case 6:
          case 10:
            FUN_141bdb7c0(uVar14,puVar11,param_2,lVar10,uVar8,uVar9);
            break;
          case 3:
          case 7:
          case 0x10:
          case 0x11:
            FUN_141bdbf30(uVar14,puVar11,param_2,lVar10,uVar8,uVar9);
            break;
          case 0x14:
            FUN_141bdbc60(uVar14,puVar11,param_2,lVar10,uVar8,uVar9);
          }
        }
        uVar2 = uVar8 >> 6;
        puVar12[uVar2] = puVar12[uVar2] | 1L << (uVar8 & 0x3f);
        puVar13[uVar2] = puVar13[uVar2] | 1L << (uVar8 & 0x3f);
      }
      puVar11 = puVar11 + 2;
      lVar15 = lVar15 + -1;
    } while (lVar15 != 0);
  }
  *param_2 = iVar7 + lVar1;
  func_0x000141bda2c0(param_2,4);
  return 0;
}


/* SwingRegion_140ab3720 @ 0x140ab3720 */

void FUN_140ab3720(longlong *param_1,uint param_2,float param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (0 < (int)param_2) {
    uVar2 = (ulonglong)param_2;
    do {
      lVar1 = *param_1;
      param_1 = param_1 + 1;
      if (((*(byte *)(lVar1 + 0x1d) & 2) == 0) && ((*(byte *)(lVar1 + 0x1d) & 1) != 0)) {
        FUN_140ab8410(lVar1,param_3 * *(float *)(lVar1 + 0x10));
      }
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}


/* SwingRegion_140ab3731 @ 0x140ab3731 */

void SwingRegion_140ab3731(undefined8 param_1,uint param_2,float param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong *unaff_RDI;
  
  uVar2 = (ulonglong)param_2;
  do {
    lVar1 = *unaff_RDI;
    unaff_RDI = unaff_RDI + 1;
    if (((*(byte *)(lVar1 + 0x1d) & 2) == 0) && ((*(byte *)(lVar1 + 0x1d) & 1) != 0)) {
      FUN_140ab8410(lVar1,param_3 * *(float *)(lVar1 + 0x10));
    }
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}


/* SwingRegion_140ab378d @ 0x140ab378d */

void SwingRegion_140ab378d(void)

{
  return;
}


/* SwingRegion_140ab3790 @ 0x140ab3790 */

undefined8 FUN_140ab3790(longlong *param_1,longlong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined4 uStack_18;
  
  (**(code **)(*param_1 + 0x48))();
  if (param_2 != 0) {
    uStack_18 = 0;
    uStack_28 = 0;
    uStack_20 = 0;
    func_0x000141bdb5f0(&uStack_28,param_2,param_3,0);
    uVar1 = func_0x000141affb20(param_1);
    uVar2 = (**(code **)(*param_1 + 0x38))(param_1);
    uVar1 = FUN_141bdd190(param_1,&uStack_28,uVar2,uVar1);
    return uVar1;
  }
  return 0;
}


/* SwingRegion_140ab3820 @ 0x140ab3820 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_140ab3820(undefined4 *param_1)

{
  FUN_1409c7870();
  *(undefined8 *)(param_1 + 0x15) = 0x3e4ccccd;
  *(undefined8 *)(param_1 + 9) = 0;
  *(undefined8 *)(param_1 + 0xb) = 0;
  *(undefined8 *)(param_1 + 0xd) = 0;
  *(undefined8 *)(param_1 + 0xf) = 0;
  *(undefined8 *)(param_1 + 0x11) = 0;
  *(undefined8 *)(param_1 + 0x13) = 0;
  *(undefined8 *)(param_1 + 0x17) = 0;
  *(undefined8 *)(param_1 + 0x19) = 0;
  *(undefined2 *)(param_1 + 0x1b) = 0;
  *param_1 = _DAT_146df270c;
  *(undefined1 *)(param_1 + 1) = 0x70;
  return param_1;
}


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
  
  uVar1 = _DAT_14382e160;
  fVar4 = _DAT_14382dce0;
  fVar3 = *param_2 - *param_3;
  fVar7 = 0.0;
  fVar8 = 0.0;
  fVar9 = param_2[2] - param_3[2];
  fVar10 = (float)((uint)fVar3 & _DAT_14382e160);
  fVar11 = param_2[1] - param_3[1];
  fVar5 = (float)((uint)fVar9 & _DAT_14382e160);
  fVar2 = (float)((uint)fVar11 & _DAT_14382e160);
  if ((float)((uint)fVar11 & _DAT_14382e160) <= fVar5) {
    fVar2 = fVar5;
  }
  if (fVar2 <= fVar10) {
    fVar2 = fVar10;
  }
  fVar6 = _DAT_14382dce0 / fVar2;
  if (0.0 < fVar2) {
    fVar8 = SQRT(fVar6 * fVar11 * fVar6 * fVar11 + fVar6 * fVar3 * fVar6 * fVar3 +
                 fVar6 * fVar9 * fVar6 * fVar9) * fVar2;
  }
  if (fVar5 <= fVar10) {
    fVar5 = fVar10;
  }
  fVar3 = fVar3 * (_DAT_14382dce0 / fVar5);
  fVar9 = (_DAT_14382dce0 / fVar5) * fVar9;
  if (fVar5 <= 0.0) {
    fVar5 = 0.0;
  }
  else {
    fVar5 = SQRT(fVar3 * fVar3 + fVar9 * fVar9) * fVar5;
  }
  fVar2 = (float)FUN_141c58560(fVar11,fVar5);
  fVar5 = param_4[1];
  fVar9 = fVar2 * _DAT_1438ac3cc - _DAT_1438ac3a4;
  fVar2 = *(float *)(param_1 + 0xc);
  if (0.0 <= fVar5) {
    fVar5 = 0.0;
  }
  fVar3 = (fVar8 - _DAT_143879c24) * _DAT_1438abcb8;
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
  fVar9 = ((fVar4 - fVar9) + fVar3) * _DAT_14382f760;
  if (fVar2 <= fVar5) {
    fVar3 = fVar5;
    if (fVar9 < fVar4) goto LAB_140ab3a94;
  }
  else if (fVar9 < fVar4) {
    fVar3 = fVar5 + (fVar2 - fVar5) * fVar9;
    goto LAB_140ab3a94;
  }
  fVar3 = (((*(float *)(param_1 + 0x10) - fVar2) * _DAT_14382e128 + fVar2) - fVar2) *
          (fVar9 - fVar4) + fVar2;
  if (fVar3 <= fVar5) {
    fVar3 = fVar5;
  }
LAB_140ab3a94:
  if (fVar2 <= fVar3) {
    fVar5 = *(float *)(param_1 + 0x10) - fVar2;
    if ((float)((uint)fVar5 & uVar1) <= _DAT_14382e118) {
      fVar5 = _DAT_14382e128;
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
    if ((float)((uint)(fVar2 - fVar5) & uVar1) <= _DAT_14382e118) {
      if (fVar5 <= fVar3) {
        fVar2 = _DAT_14382e128;
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


/* SwingRegion_140ab3bc0 @ 0x140ab3bc0 */

void FUN_140ab3bc0(undefined8 *param_1)

{
  *param_1 = &UNK_14382ddf0;
  *(undefined4 *)((longlong)param_1 + 0x14) = 0;
  func_0x000141984310(param_1 + 3);
  *(undefined4 *)((longlong)param_1 + 0x3c) = 0;
  *param_1 = &UNK_1438ce690;
  *(undefined8 *)((longlong)param_1 + 0xf4) = 0;
  *(undefined2 *)((longlong)param_1 + 0xf1) = 0xff;
  *(undefined1 *)(param_1 + 0x1e) = 0xff;
  FUN_1420df1c0(param_1 + 0x1e,0xff);
  return;
}


/* SwingRegion_140ab3c20 @ 0x140ab3c20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_140ab3c20(longlong param_1,int param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 auStackX_10 [2];
  
  bVar3 = false;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  if (param_2 != 0) {
    lVar2 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar2 + 0x88) == 0) {
      uVar1 = FUN_14167ab40(lVar2 + 0x58,0x1473d09e0);
    }
    else {
      uVar1 = func_0x0001416799a0(lVar2 + 0x80);
    }
    FUN_1415c2240(uVar1,auStackX_10,param_2,0);
    lVar2 = func_0x0001415ad2a0(0x1473d0730,auStackX_10[0]);
    bVar3 = lVar2 != 0;
    if (lVar2 != 0) {
      fVar4 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar2,0x54638a5f);
      *(float *)(param_1 + 0x1d0) = fVar4;
      if (fVar4 < 0.0) {
        fVar4 = *(float *)(lVar2 + 0x300) * _DAT_143848d00;
      }
      *(float *)(param_1 + 0x1d0) = fVar4;
      fVar4 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar2,0x3bff28c9);
      *(float *)(param_1 + 0x1d4) = fVar4;
      if ((fVar4 < 0.0) && (fVar4 = *(float *)(lVar2 + 0x300) - _DAT_14382e120, fVar4 <= 0.0)) {
        fVar4 = 0.0;
      }
      *(float *)(param_1 + 0x1d4) = fVar4;
      fVar5 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar2,0xa959982c);
      fVar4 = *(float *)(param_1 + 0x1d4);
      fVar6 = fVar4;
      if ((0.0 <= fVar5) && (fVar6 = fVar5, fVar4 <= fVar5)) {
        fVar6 = fVar4;
      }
      *(float *)(param_1 + 0x1d8) = fVar6;
    }
    func_0x0001415c0440(uVar1,auStackX_10[0]);
  }
  return bVar3;
}


/* SwingRegion_140ab3c4b @ 0x140ab3c4b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool SwingRegion_140ab3c4b(longlong param_1)

{
  ushort in_AX;
  undefined8 uVar1;
  longlong lVar2;
  longlong unaff_RBX;
  undefined4 unaff_EDI;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 in_stack_00000048;
  
  if (in_AX < *(ushort *)(param_1 + 0x88)) {
    uVar1 = func_0x0001416799a0(param_1 + 0x80);
  }
  else {
    uVar1 = FUN_14167ab40(param_1 + 0x58);
  }
  FUN_1415c2240(uVar1,&stack0x00000048,unaff_EDI,0);
  lVar2 = func_0x0001415ad2a0(0x1473d0730,in_stack_00000048);
  if (lVar2 != 0) {
    fVar3 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8),lVar2,0x54638a5f);
    *(float *)(unaff_RBX + 0x1d0) = fVar3;
    if (fVar3 < 0.0) {
      fVar3 = *(float *)(lVar2 + 0x300) * _DAT_143848d00;
    }
    *(float *)(unaff_RBX + 0x1d0) = fVar3;
    fVar3 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8),lVar2,0x3bff28c9);
    *(float *)(unaff_RBX + 0x1d4) = fVar3;
    if ((fVar3 < 0.0) && (fVar3 = *(float *)(lVar2 + 0x300) - _DAT_14382e120, fVar3 <= 0.0)) {
      fVar3 = 0.0;
    }
    *(float *)(unaff_RBX + 0x1d4) = fVar3;
    fVar4 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8),lVar2,0xa959982c);
    fVar3 = *(float *)(unaff_RBX + 0x1d4);
    fVar5 = fVar3;
    if ((0.0 <= fVar4) && (fVar5 = fVar4, fVar3 <= fVar4)) {
      fVar5 = fVar3;
    }
    *(float *)(unaff_RBX + 0x1d8) = fVar5;
  }
  func_0x0001415c0440(uVar1,in_stack_00000048);
  return lVar2 != 0;
}


/* SwingRegion_140ab3cb8 @ 0x140ab3cb8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 SwingRegion_140ab3cb8(void)

{
  longlong unaff_RBX;
  undefined1 unaff_BPL;
  longlong unaff_RDI;
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 in_stack_00000048;
  
  fVar1 = (float)FUN_141d50d30();
  *(float *)(unaff_RBX + 0x1d0) = fVar1;
  if (fVar1 < 0.0) {
    fVar1 = *(float *)(unaff_RDI + 0x300) * _DAT_143848d00;
  }
  *(float *)(unaff_RBX + 0x1d0) = fVar1;
  fVar1 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8));
  *(float *)(unaff_RBX + 0x1d4) = fVar1;
  if ((fVar1 < 0.0) && (fVar1 = *(float *)(unaff_RDI + 0x300) - _DAT_14382e120, fVar1 <= 0.0)) {
    fVar1 = 0.0;
  }
  *(float *)(unaff_RBX + 0x1d4) = fVar1;
  fVar2 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8));
  fVar1 = *(float *)(unaff_RBX + 0x1d4);
  fVar3 = fVar1;
  if ((0.0 <= fVar2) && (fVar3 = fVar2, fVar1 <= fVar2)) {
    fVar2 = fVar1;
    fVar3 = fVar1;
  }
  *(float *)(unaff_RBX + 0x1d8) = fVar3;
  func_0x0001415c0440(fVar2,in_stack_00000048);
  return unaff_BPL;
}


/* SwingRegion_140ab3d49 @ 0x140ab3d49 */

undefined1 SwingRegion_140ab3d49(float param_1,float param_2)

{
  longlong unaff_RBX;
  undefined1 unaff_BPL;
  undefined4 in_stack_00000048;
  
  if (param_2 <= param_1) {
    param_1 = param_2;
  }
  *(float *)(unaff_RBX + 0x1d8) = param_1;
  func_0x0001415c0440(param_1,in_stack_00000048);
  return unaff_BPL;
}


/* SwingRegion_140ab3d72 @ 0x140ab3d72 */

void SwingRegion_140ab3d72(void)

{
  return;
}


/* SwingRegion_140ab3d80 @ 0x140ab3d80 */

bool FUN_140ab3d80(longlong param_1,undefined4 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  float fVar3;
  undefined4 auStackX_8 [2];
  
  *(undefined4 *)(param_1 + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(param_1 + 0x1cc) = 0x3e99999a;
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    uVar1 = FUN_14167ab40(lVar2 + 0x58,0x1473d09e0);
  }
  else {
    uVar1 = func_0x0001416799a0(lVar2 + 0x80);
  }
  FUN_1415c2240(uVar1,auStackX_8,param_2,0);
  lVar2 = func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
  if (lVar2 != 0) {
    fVar3 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar2,0x3bff28c9);
    if (0.0 <= fVar3) {
      *(float *)(param_1 + 0x1c8) = fVar3;
    }
    else {
      fVar3 = *(float *)(param_1 + 0x1cc);
      *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
    }
    *(float *)(param_1 + 0x1cc) = fVar3;
    fVar3 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar2,0xa959982c);
    if (fVar3 < 0.0) {
      fVar3 = *(float *)(param_1 + 0x1c8);
    }
    *(float *)(param_1 + 0x1c8) = fVar3;
    fVar3 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar2,0xbe47e933);
    if (fVar3 < 0.0) {
      fVar3 = *(float *)(param_1 + 0x1cc);
      if (*(float *)(param_1 + 0x1c8) <= *(float *)(param_1 + 0x1cc)) {
        fVar3 = *(float *)(param_1 + 0x1c8);
      }
    }
    *(float *)(param_1 + 0x1cc) = fVar3;
  }
  func_0x0001415c0440(uVar1,auStackX_8[0]);
  return lVar2 != 0;
}


/* SwingRegion_140ab3e1c @ 0x140ab3e1c */

undefined1 SwingRegion_140ab3e1c(void)

{
  longlong unaff_RBX;
  undefined1 unaff_BPL;
  float fVar1;
  undefined4 in_stack_00000040;
  
  fVar1 = (float)FUN_141d50d30();
  if (0.0 <= fVar1) {
    *(float *)(unaff_RBX + 0x1c8) = fVar1;
  }
  else {
    fVar1 = *(float *)(unaff_RBX + 0x1cc);
    *(undefined4 *)(unaff_RBX + 0x1c8) = *(undefined4 *)(unaff_RBX + 0x1c8);
  }
  *(float *)(unaff_RBX + 0x1cc) = fVar1;
  fVar1 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8));
  if (fVar1 < 0.0) {
    fVar1 = *(float *)(unaff_RBX + 0x1c8);
  }
  *(float *)(unaff_RBX + 0x1c8) = fVar1;
  fVar1 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8));
  if (fVar1 < 0.0) {
    fVar1 = *(float *)(unaff_RBX + 0x1cc);
    if (*(float *)(unaff_RBX + 0x1c8) <= *(float *)(unaff_RBX + 0x1cc)) {
      fVar1 = *(float *)(unaff_RBX + 0x1c8);
    }
  }
  *(float *)(unaff_RBX + 0x1cc) = fVar1;
  func_0x0001415c0440(fVar1,in_stack_00000040);
  return unaff_BPL;
}


/* SwingRegion_140ab3e97 @ 0x140ab3e97 */

undefined1 SwingRegion_140ab3e97(void)

{
  longlong unaff_RBX;
  undefined1 unaff_BPL;
  float fVar1;
  undefined4 in_stack_00000040;
  
  fVar1 = *(float *)(unaff_RBX + 0x1cc);
  if (*(float *)(unaff_RBX + 0x1c8) <= *(float *)(unaff_RBX + 0x1cc)) {
    fVar1 = *(float *)(unaff_RBX + 0x1c8);
  }
  *(float *)(unaff_RBX + 0x1cc) = fVar1;
  func_0x0001415c0440(fVar1,in_stack_00000040);
  return unaff_BPL;
}


/* SwingRegion_140ab3ee0 @ 0x140ab3ee0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140ab3ee0(longlong param_1,int param_2)

{
  float fVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined4 auStackX_10 [2];
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined4 uStack_168;
  longlong alStack_158 [39];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  *(undefined8 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x1e8) = 0xbf800000;
  if (param_2 == 0) {
    uVar2 = in_RAX & 0xffffffffffffff00;
  }
  else {
    lVar4 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar4 + 0x88) == 0) {
      uVar3 = FUN_14167ab40(lVar4 + 0x58,0x1473d09e0);
    }
    else {
      uVar3 = func_0x0001416799a0(lVar4 + 0x80);
    }
    FUN_1415c2240(uVar3,auStackX_10,param_2,0);
    lVar4 = func_0x0001415ad2a0(0x1473d0730,auStackX_10[0]);
    if (lVar4 != 0) {
      fVar1 = *(float *)(lVar4 + 0x300);
      *(float *)(param_1 + 0x1dc) = fVar1;
      *(float *)(param_1 + 0x1e0) = fVar1 * _DAT_14382e128;
      puVar5 = (ulonglong *)FUN_141d50b40(*(undefined8 *)(param_1 + 8),lVar4,0x875e46a8);
      if (puVar5 != (ulonglong *)0x0) {
        FUN_14146ecf0(alStack_158);
        uVar2 = *puVar5;
        if ((uVar2 & 1) == 0) {
          (**(code **)(alStack_158[0] + 0x48))(alStack_158);
        }
        else {
          (**(code **)(alStack_158[0] + 0x48))();
          lVar8 = (uVar2 & 0xfffffffffffffffe) + 8;
          if (lVar8 != 0) {
            uStack_178 = 0;
            uStack_170 = 0;
            uStack_168 = 0;
            func_0x000141bdb5f0(&uStack_178,lVar8,0,0);
            uVar6 = func_0x000141affb20(alStack_158);
            uVar7 = (**(code **)(alStack_158[0] + 0x38))(alStack_158);
            FUN_141bdd190(alStack_158,&uStack_178,uVar7,uVar6);
          }
        }
        *(undefined4 *)(param_1 + 0x1e4) = uStack_20;
        *(undefined4 *)(param_1 + 0x1e8) = uStack_1c;
        *(int *)(param_1 + 0x1e0) = (int)puVar5[1];
        func_0x000141479ff0(alStack_158);
        func_0x00014146f540(alStack_158);
      }
    }
    func_0x0001415c0440(uVar3,auStackX_10[0]);
    uVar2 = (ulonglong)(lVar4 != 0);
  }
  return uVar2;
}


/* SwingRegion_140ab40c0 @ 0x140ab40c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_140ab40c0(longlong param_1,float *param_2,float *param_3,char param_4)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar5 = *(float *)(param_1 + 0x150) - *(float *)(param_1 + 0x134);
  fVar6 = *(float *)(param_1 + 0x158) - *(float *)(param_1 + 0x13c);
  fVar7 = *(float *)(param_1 + 0x154) - *(float *)(param_1 + 0x138);
  fVar3 = (float)((uint)fVar6 & _DAT_14382e160);
  if ((float)((uint)fVar6 & _DAT_14382e160) <= (float)((uint)fVar7 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fVar7 & _DAT_14382e160);
  }
  if (fVar3 <= (float)((uint)fVar5 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fVar5 & _DAT_14382e160);
  }
  fVar2 = fVar7;
  if (0.0 < fVar3) {
    fVar3 = _DAT_14382dce0 / fVar3;
    fVar5 = fVar3 * fVar5;
    fVar2 = fVar3 * fVar7;
    fVar3 = fVar3 * fVar6;
    fVar4 = _DAT_14382dce0 / SQRT(fVar2 * fVar2 + fVar5 * fVar5 + fVar3 * fVar3);
    fVar5 = fVar4 * fVar5;
    fVar6 = fVar4 * fVar3;
    fVar2 = fVar4 * fVar2;
  }
  fVar3 = fVar2 * fVar2 + fVar5 * fVar5 + fVar6 * fVar6;
  if ((float)((uint)fVar3 & _DAT_14382e160) <= _DAT_14382e110) {
    fVar3 = 0.0;
  }
  else {
    fVar3 = (param_3[1] * fVar2 + *param_3 * fVar5 + param_3[2] * fVar6) / fVar3;
  }
  fVar4 = *param_3 - fVar5 * fVar3;
  fVar5 = param_3[1] - fVar2 * fVar3;
  fVar3 = param_3[2] - fVar6 * fVar3;
  *param_2 = fVar4;
  param_2[1] = fVar5;
  param_2[2] = fVar3;
  uVar1 = _DAT_14382e890;
  if (param_4 != '\0') {
    if (0.0 <= fVar7) {
      if (0.0 < fVar5) {
        *param_2 = (float)((uint)fVar4 ^ _DAT_14382e890);
        param_2[2] = (float)((uint)fVar3 ^ uVar1);
        param_2[1] = (float)((uint)fVar5 ^ uVar1);
      }
    }
    else {
      uVar1 = FUN_1402c2450(param_3);
      *(ulonglong *)param_2 = (ulonglong)(uVar1 ^ _DAT_14382e890) << 0x20;
      param_2[2] = 0.0;
    }
  }
  return param_2;
}


/* SwingRegion_140ab42f0 @ 0x140ab42f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_140ab42f0(longlong param_1)

{
  undefined8 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = (float)FUN_140876340(param_1 + 0x220);
  uVar1 = FUN_141676930(param_1);
  fVar3 = (float)FUN_140311350(uVar1,param_1 + 0x150);
  fVar4 = (float)FUN_1402c2450(param_1 + 0x214);
  return (fVar3 * fVar2) / ((*(float *)(param_1 + 0x22c) - fVar4) * _DAT_14382f760 + fVar4);
}


/* SwingRegion_140ab4380 @ 0x140ab4380 */

void FUN_140ab4380(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined1 param_6)

{
  undefined1 auStack_18 [24];
  
  FUN_140ab4450(param_3,param_1 + 0x134,param_2,auStack_18,param_4,param_5,param_6);
  return;
}


/* SwingRegion_140ab43d0 @ 0x140ab43d0 */

void FUN_140ab43d0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5)

{
  undefined1 auStack_18 [24];
  
  FUN_140ab4450(param_1 + 0x168,param_1 + 0x134,param_2,auStack_18,param_3,param_4,param_5);
  return;
}


/* SwingRegion_140ab4410 @ 0x140ab4410 */

void FUN_140ab4410(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStack_18 [24];
  
  FUN_140ab4450(param_1 + 0x168,param_1 + 0x134,param_1 + 0x214,auStack_18,param_2,param_3,0);
  return;
}


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
  
  uVar1 = _DAT_14382e160;
  fVar5 = _DAT_14382dce0;
  fVar6 = param_1[2] - param_2[2];
  fVar8 = *param_1 - *param_2;
  fVar9 = param_1[1] - param_2[1];
  fVar3 = (float)((uint)fVar6 & _DAT_14382e160);
  if ((float)((uint)fVar6 & _DAT_14382e160) <= (float)((uint)fVar9 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fVar9 & _DAT_14382e160);
  }
  if (fVar3 <= (float)((uint)fVar8 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fVar8 & _DAT_14382e160);
  }
  if (0.0 < fVar3) {
    fVar3 = _DAT_14382dce0 / fVar3;
    fVar6 = fVar3 * fVar6;
    fVar8 = fVar3 * fVar8;
    fVar3 = fVar3 * fVar9;
    fVar7 = _DAT_14382dce0 / SQRT(fVar3 * fVar3 + fVar8 * fVar8 + fVar6 * fVar6);
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
  fVar3 = (float)((uint)fStack_110 & _DAT_14382e160);
  if ((float)((uint)fStack_110 & _DAT_14382e160) <= (float)((uint)fStack_114 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fStack_114 & _DAT_14382e160);
  }
  if (fVar3 <= (float)((uint)fStack_118 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fStack_118 & _DAT_14382e160);
  }
  if (0.0 < fVar3) {
    fVar3 = _DAT_14382dce0 / fVar3;
    fStack_110 = fStack_110 * fVar3;
    fStack_114 = fStack_114 * fVar3;
    fStack_118 = fStack_118 * fVar3;
    fVar3 = _DAT_14382dce0 /
            SQRT(fStack_114 * fStack_114 + fStack_118 * fStack_118 + fStack_110 * fStack_110);
    fStack_118 = fVar3 * fStack_118;
    fStack_114 = fVar3 * fStack_114;
    fStack_110 = fVar3 * fStack_110;
  }
  *(ulonglong *)param_4 = CONCAT44(fStack_114,fStack_118);
  param_4[2] = fStack_110;
  fVar3 = (float)FUN_140876340(param_4);
  uVar2 = _DAT_14382e890;
  fVar3 = fVar3 * _DAT_143830124;
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
  fVar5 = fVar5 * _DAT_143830124;
  *param_6 = fVar5;
  if (0.0 < fStack_f4) {
    if (fStack_f0 <= 0.0) {
      *param_6 = _DAT_14386dd08 - fVar5;
    }
    else {
      *param_6 = (float)((uint)fVar5 ^ uVar2);
    }
  }
  return;
}


/* SwingRegion_140ab4a70 @ 0x140ab4a70 */

void FUN_140ab4a70(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dd77b0);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  if (lVar3 != 0) {
    uVar1 = *(uint *)(param_1 + 0xfc);
    lVar2 = func_0x00014067b7b0();
    if (lVar2 != 0) {
      *(uint *)(lVar3 + 0x7e10 + ((ulonglong)uVar1 & 0xffff) * 0xc) =
           (uint)(*(int *)(lVar2 + 0x704) == 0);
    }
    return;
  }
  return;
}


/* SwingRegion_140ab4ac0 @ 0x140ab4ac0 */

void FUN_140ab4ac0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    lVar1 = FUN_14167ab40(lVar1 + 0x58,0x146dd77b0);
  }
  else {
    lVar1 = func_0x0001416799a0(lVar1 + 0x80);
  }
  if ((lVar1 != 0) && (*(int *)(param_1 + 0xfc) != 0)) {
    bVar3 = *(int *)(param_2 + 0x138) != 1;
    if (*(int *)(param_2 + 0x138) == 2) {
      lVar2 = func_0x00014067b7b0(lVar1);
      if (lVar2 != 0) {
        bVar3 = *(int *)(lVar2 + 0x704) == 0;
      }
    }
    func_0x00014067d760(lVar1,*(undefined4 *)(param_1 + 0xfc),bVar3);
  }
  return;
}


/* SwingRegion_140ab4ba0 @ 0x140ab4ba0 */

char FUN_140ab4ba0(longlong param_1)

{
  char cVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  FUN_141f9de20(param_1,0xcb86ef8f,0xc);
  FUN_141f9de20(param_1,0xb37847ee,0xc);
  FUN_141f9de20(param_1,0x44d96bd9,0xc);
  FUN_141f9de20(param_1,0x25f068d0,0xc);
  FUN_141f9de20(param_1,0x5becae87,4);
  puVar2 = (undefined1 *)FUN_141bcec10(param_1 + 0x10,0x7a248ff0);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = *(undefined1 *)(param_1 + 0x1c0);
  }
  *(undefined1 *)((ulonglong)*(byte *)(param_1 + 0x1c0) + 0x180 + param_1) = 1;
  *(undefined1 *)((ulonglong)*(byte *)(param_1 + 0x1c0) + 0x1a0 + param_1) = 1;
  *(undefined8 *)(param_1 + 0x1c8 + (ulonglong)*(byte *)(param_1 + 0x1c0) * 8) = 0;
  *(undefined8 *)(param_1 + 0x2c8 + (ulonglong)*(byte *)(param_1 + 0x1c0) * 8) = 0;
  cVar1 = *(char *)(param_1 + 0x1c0);
  bVar3 = cVar1 + 1;
  *(byte *)(param_1 + 0x1c0) = bVar3;
  *(byte *)(param_1 + 0x1c1) = ((bVar3 & 7) != 0) + (bVar3 >> 3);
  return cVar1;
}


/* SwingRegion_140ab4c20 @ 0x140ab4c20 */

char FUN_140ab4c20(longlong param_1)

{
  char cVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  FUN_141f9dec0(param_1,0xb37847ee,0xc,1,FUN_141f9e930,FUN_141f9ef40);
  FUN_141f9de20(param_1,0xbc2d5985,0xc);
  FUN_141f9de20(param_1,0x72f78b5f,8);
  FUN_141f9de20(param_1,0xe3c752bb,4);
  FUN_141f9de20(param_1,0x44d96bd9,0xc);
  puVar2 = (undefined1 *)FUN_141bcec10(param_1 + 0x10,0x5becae87);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = *(undefined1 *)(param_1 + 0x1c0);
  }
  *(undefined1 *)((ulonglong)*(byte *)(param_1 + 0x1c0) + 0x180 + param_1) = 4;
  *(undefined1 *)((ulonglong)*(byte *)(param_1 + 0x1c0) + 0x1a0 + param_1) = 4;
  *(undefined8 *)(param_1 + 0x1c8 + (ulonglong)*(byte *)(param_1 + 0x1c0) * 8) = 0;
  *(undefined8 *)(param_1 + 0x2c8 + (ulonglong)*(byte *)(param_1 + 0x1c0) * 8) = 0;
  cVar1 = *(char *)(param_1 + 0x1c0);
  bVar3 = cVar1 + 1;
  *(byte *)(param_1 + 0x1c0) = bVar3;
  *(byte *)(param_1 + 0x1c1) = ((bVar3 & 7) != 0) + (bVar3 >> 3);
  return cVar1;
}


/* SwingRegion_140ab4cc0 @ 0x140ab4cc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab4cc0(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  undefined1 uVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  float *pfVar12;
  undefined4 uVar13;
  int iVar14;
  char cVar15;
  undefined *puVar16;
  undefined *puVar17;
  undefined *puVar18;
  bool bVar19;
  int *piVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  uint uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float afStackX_8 [2];
  char cStackX_10;
  char cStackX_18;
  char cStackX_20;
  float afStack_120 [3];
  float fStack_114;
  int iStack_110;
  int *piStack_108;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  
  FUN_140ab4450(param_1 + 0x168,param_1 + 0x134,param_1 + 0x220,&fStack_100,afStackX_8,&fStack_114,0
               );
  piStack_108 = (int *)(param_1 + 0x17c);
  cVar6 = *(char *)(param_1 + 0x281);
  iVar14 = *(int *)(param_1 + 0x178);
  if ((((iVar14 == 0) && (*piStack_108 == 0)) || (*(int *)(param_1 + 0x180) != 0)) ||
     (*(int *)(param_1 + 0x184) != 0)) {
    bVar21 = false;
  }
  else {
    bVar21 = true;
  }
  if (((iVar14 == 0) && (*(int *)(param_1 + 0x180) == 0)) ||
     ((*piStack_108 != 0 || (*(int *)(param_1 + 0x184) != 0)))) {
    iVar7 = *piStack_108;
    if (((iVar7 == 0) && (bVar23 = false, *(int *)(param_1 + 0x184) == 0)) ||
       ((bVar23 = false, iVar14 != 0 || (*(int *)(param_1 + 0x180) != 0)))) goto LAB_140ab4dd9;
    bVar22 = true;
LAB_140ab4de1:
    if (*(int *)(param_1 + 0x184) != 0) goto LAB_140ab4dea;
LAB_140ab4e25:
    bVar19 = false;
  }
  else {
    bVar23 = true;
    iVar7 = 0;
LAB_140ab4dd9:
    bVar22 = false;
    if (*(int *)(param_1 + 0x180) == 0) goto LAB_140ab4de1;
LAB_140ab4dea:
    if ((iVar14 != 0) || (iVar7 != 0)) goto LAB_140ab4e25;
    bVar19 = true;
  }
  if ((bVar23) || ((afStackX_8[0] < _DAT_14384002c && (!bVar22)))) {
    cVar15 = '\x01';
  }
  else {
    cVar15 = '\0';
  }
  if (((cVar6 == '\0') && (!bVar21)) || (bVar19)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  lVar11 = *(longlong *)(param_1 + 8);
  *(undefined1 *)(param_1 + 0x281) = uVar5;
  cStackX_10 = cVar15;
  if (*(short *)(lVar11 + 0x88) == 0) {
    uVar10 = FUN_14167ab40(lVar11 + 0x58,0x146dacd70);
  }
  else {
    uVar10 = func_0x0001416799a0(lVar11 + 0x80);
  }
  iStack_110 = func_0x00014085fb90(uVar10);
  bVar21 = iStack_110 == 2;
  bVar22 = iStack_110 != 1;
  if ((bVar23) || (cVar15 != '\0')) {
    bVar19 = true;
  }
  else {
    bVar19 = false;
  }
  lVar11 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar11 + 0x88) == 0) {
    lVar11 = FUN_14167ab40(lVar11 + 0x58,0x146da9d90);
  }
  else {
    lVar11 = func_0x0001416799a0(lVar11 + 0x80);
  }
  fVar29 = _DAT_143848d00;
  if (((lVar11 != 0) && (cVar15 != '\0')) && (!bVar23)) {
    uVar24 = FUN_141f2dd10(*(undefined8 *)(lVar11 + 0x50),0x4453c00,_DAT_143830118);
    bVar19 = fVar29 < (float)(uVar24 & _DAT_14382e160);
  }
  uVar10 = FUN_141676930(param_1);
  fVar25 = (float)FUN_140311350(uVar10,param_1 + 0x150);
  uVar24 = func_0x000141bbb790();
  fVar26 = (float)FUN_140ab42f0();
  fVar4 = _DAT_1438ad724;
  fVar28 = _DAT_143840c8c;
  bVar23 = false;
  afStackX_8[0] = (float)((uint)afStackX_8[0] & 0xffffff00);
  if (((_DAT_14383d254 <= fVar26) || (fVar26 <= _DAT_143834a04)) ||
     (_DAT_1438ce980 < *(float *)(param_1 + 0x218) || _DAT_1438ce980 == *(float *)(param_1 + 0x218))
     ) {
    cStackX_20 = '\0';
  }
  else {
    cStackX_20 = '\x01';
  }
  if (((bVar21) || (_DAT_1438ad724 <= fVar26)) ||
     ((fVar26 <= _DAT_143840c8c ||
      (_DAT_14387e6ac < *(float *)(param_1 + 0x218) || _DAT_14387e6ac == *(float *)(param_1 + 0x218)
      )))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((cStackX_20 == '\0') || ((_DAT_146df2630 != 0 && (_DAT_146df2634 != 0)))) {
    cStackX_18 = '\0';
  }
  else {
    cStackX_18 = '\x01';
  }
  if ((bVar2) && (_DAT_146df2638 == 0)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((_DAT_145d9fe8c < *(float *)(param_1 + 0x148) || _DAT_145d9fe8c == *(float *)(param_1 + 0x148)
      ) || (DAT_145d9fe7f == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  lVar11 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar11 + 0x88) == 0) {
    lVar11 = FUN_14167ab40(lVar11 + 0x58,0x147c40bf0);
  }
  else {
    lVar11 = func_0x0001416799a0(lVar11 + 0x80);
  }
  if ((!bVar1) || (*(float *)(lVar11 + 0x6b8) <= _DAT_143830120)) {
    bVar1 = false;
    if ((DAT_145d9fe7f != '\0') &&
       (fVar27 = (float)func_0x0001403e3f30(param_1 + 0x214), _DAT_14382f0e4 < fVar27)) {
      afStack_120[0] = *(float *)(param_1 + 0x214);
      afStack_120[2] = *(float *)(param_1 + 0x21c);
      afStack_120[1] = 0.0;
      FUN_1402d0740(&fStack_f0,afStack_120);
      pfVar12 = (float *)FUN_141676930(param_1);
      afStack_120[1] = 0.0;
      afStack_120[0] = *(float *)(param_1 + 0x168) - *pfVar12;
      afStack_120[2] = *(float *)(param_1 + 0x170) - pfVar12[2];
      FUN_1402d0740(&fStack_100,afStack_120);
      bVar1 = false;
      if (fStack_f0 * fStack_100 + fStack_ec * fStack_fc + fStack_e8 * fStack_f8 < _DAT_143837a24) {
        bVar1 = true;
      }
    }
  }
  else {
    bVar1 = true;
  }
  fVar27 = _DAT_14382dce0;
  if ((*(int *)(param_1 + 0x188) != 0) || (*(int *)(param_1 + 0x18c) != 0)) {
    bVar1 = false;
  }
  fVar30 = (*(float *)(param_1 + 0x218) - _DAT_1438acf84) * _DAT_1438ce95c;
  if (fVar30 <= 0.0) {
    fVar30 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar30) {
    fVar30 = _DAT_14382dce0;
  }
  fVar31 = _DAT_1438ac760;
  if ((!bVar21) && (bVar22)) {
    fVar31 = _DAT_14382dce0;
  }
  fVar31 = (fVar30 + fVar28) * fVar31;
  fVar28 = ((float)_DAT_146df263c - _DAT_14382f0e0) * _DAT_14386dc74;
  if (fVar28 <= 0.0) {
    fVar28 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar28) {
    fVar28 = _DAT_14382dce0;
  }
  fVar28 = (float)FUN_143666da0(fVar28,fVar4);
  fVar28 = fVar28 * _DAT_1438cb4b0 + _DAT_143836d0c;
  if (cStackX_18 == '\0') {
    fVar31 = 0.0;
  }
  if (!bVar3) {
    fVar28 = 0.0;
  }
  fVar28 = (fVar31 + fVar27 + fVar28) * (float)(uVar24 >> 8) * _DAT_14382e114;
  if (DAT_146df2614 != '\0') {
    func_0x000141bbb4e0(&UNK_1438ce760);
    func_0x000141bbb4e0(&UNK_1438ce778,(double)fStack_114);
    func_0x000141bbb4e0(&UNK_1438ce790,(double)fVar25);
    func_0x000141bbb4e0(&UNK_1438ce7a8,(double)*(float *)(param_1 + 0x218));
    func_0x000141bbb4e0(&UNK_1438ce7c0,(double)fVar26);
    func_0x000141bbb4e0(&UNK_1438ce7d8,
                        *(undefined8 *)
                         (*(longlong *)(_DAT_145e11438 + 0x20) + (longlong)iStack_110 * 8));
    puVar16 = &UNK_1438ce7ec;
    func_0x000141bbb4e0(&UNK_1438ce7f8,&UNK_1438ce7f0,&UNK_1438ce7ec,_DAT_143830a28);
    puVar17 = &UNK_1438ce7ec;
    if (_DAT_146df261c != 0) {
      puVar17 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce830,&UNK_1438ce7ec,puVar17,0);
    puVar17 = &UNK_1438ce7ec;
    if (cStackX_20 != '\0') {
      puVar17 = &UNK_1438ce7f0;
    }
    puVar18 = &UNK_1438ce7ec;
    if (_DAT_146df2630 != 0) {
      puVar18 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce868,puVar17,puVar18,(double)fVar31);
    puVar18 = &UNK_1438ce7ec;
    if (_DAT_146df2634 != 0) {
      puVar18 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8a0,puVar17,puVar18,(double)fVar31);
    puVar17 = &UNK_1438ce7ec;
    if (_DAT_146df2638 != 0) {
      puVar17 = &UNK_1438ce7f0;
    }
    if (bVar2) {
      puVar16 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8d8,puVar16,puVar17);
    func_0x000141bbb4e0(&UNK_1438ce910,(double)fVar28);
  }
  cVar15 = cStackX_10;
  if (_DAT_1438aa3f4 <= fVar28) {
    if ((cStackX_18 == '\0') || (fVar31 + fVar27 <= fVar28)) {
      if (bVar3) {
        afStackX_8[0] = (float)CONCAT31(afStackX_8[0]._1_3_,1);
        bVar19 = true;
      }
    }
    else {
      bVar23 = true;
      bVar19 = true;
    }
  }
  if ((*(char *)(param_1 + 0x1fd) != '\0') && (cVar6 != *(char *)(param_1 + 0x281))) {
    bVar23 = false;
    bVar1 = true;
    afStackX_8[0] = (float)((uint)afStackX_8[0] & 0xffffff00);
  }
  if (_DAT_146df2618 == 1) {
    afStackX_8[0] = (float)((uint)afStackX_8[0]._1_3_ << 8);
LAB_140ab54ac:
    bVar22 = false;
    bVar23 = false;
  }
  else if (_DAT_146df2618 == 2) {
    bVar23 = false;
    bVar22 = true;
    afStackX_8[0] = (float)((uint)afStackX_8[0]._1_3_ << 8);
    bVar19 = false;
  }
  else {
    bVar22 = false;
    if (_DAT_146df2618 == 3) {
      bVar23 = true;
      afStackX_8[0] = (float)((uint)afStackX_8[0]._1_3_ << 8);
      bVar19 = true;
    }
    else if (_DAT_146df2618 == 4) {
      afStackX_8[0] = (float)CONCAT31(afStackX_8[0]._1_3_,1);
      bVar19 = true;
      goto LAB_140ab54ac;
    }
  }
  if (((!bVar21) || (bVar23)) ||
     ((*(char *)(param_1 + 0x28a) == '\0' && (_DAT_14383d148 <= fVar26)))) {
    bVar21 = false;
  }
  else {
    if (bVar19 == false) {
      if (cStackX_10 != '\0') {
        uVar24 = func_0x000141bbb790();
        bVar19 = (bool)(~(byte)(uVar24 >> 0xf) & 1);
        if (bVar19 != false) goto LAB_140ab54fd;
      }
    }
    else {
LAB_140ab54fd:
      if (DAT_146df2614 != '\0') {
        func_0x000141bbb4e0(&UNK_1438ce920);
      }
    }
    bVar21 = true;
  }
  if (DAT_146df2616 != '\0') {
    bVar21 = true;
    bVar19 = true;
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(param_1 + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar15 != '\0') && (bVar19 != false)) goto LAB_140ab5619;
    cVar6 = *(char *)(param_1 + 0x281);
    bVar23 = cVar6 == '\0';
    *(undefined4 *)(param_1 + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(param_1 + 0x1ac) = 0x836c214c;
    *(undefined4 *)(param_1 + 0x1b0) = 0xa1ff8610;
    iVar14 = 0x42991cb0;
    if (!bVar23) {
      iVar14 = -0x6927dc91;
    }
    *(undefined2 *)(param_1 + 0x282) = 1;
    uVar8 = 0x9a5e57b2;
    if (!bVar23) {
      uVar8 = 0x4e1f686d;
    }
    *(undefined4 *)(param_1 + 0x1a8) = uVar8;
    uVar8 = 0x734348c3;
    if (!bVar23) {
      uVar8 = 0xa702771c;
    }
    *(undefined4 *)(param_1 + 0x1b4) = uVar8;
    if (bVar23) {
      iVar7 = *(int *)(param_1 + 0x184);
    }
    else {
      iVar7 = *piStack_108;
    }
    if (iVar7 != 0) {
      if (cVar6 == '\0') {
        iVar14 = *(int *)(param_1 + 0x184);
      }
      else {
        iVar14 = *piStack_108;
      }
    }
    *(int *)(param_1 + 0x198) = iVar14;
    uVar24 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar14 = *(int *)(param_1 + 0x188);
    iVar9 = *(int *)(param_1 + 0x18c);
    if (iVar14 == 0) {
      if (iVar9 == 0) {
        if ((!bVar21) || (iVar7 != 0)) {
          *(undefined4 *)(param_1 + 0x1a0) = 0xea6ee521;
          if (bVar22) {
            *(undefined4 *)(param_1 + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar24 = _DAT_146df2634;
          }
          else {
            if (bVar1) {
              uVar8 = 0x4db30291;
              if (cVar6 != '\0') {
                uVar8 = 0x99f23d4e;
              }
            }
            else {
              uVar8 = 0;
            }
            *(undefined4 *)(param_1 + 0x19c) = uVar8;
            *(undefined4 *)(param_1 + 0x1a4) = 0x6498e62f;
            uVar24 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x1a0) = 0xf60be115;
          *(undefined4 *)(param_1 + 0x1a4) = 0x568987b1;
          *(undefined1 *)(param_1 + 0x211) = 1;
          uVar8 = 0x736ce232;
          if (cVar6 != '\0') {
            uVar8 = 0xc3aac29e;
          }
          *(undefined4 *)(param_1 + 0x198) = uVar8;
          uVar24 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(param_1 + 0x1a0) = iVar14;
      if (iVar9 == 0) {
        iVar9 = *(int *)(param_1 + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(param_1 + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        bVar19 = true;
        cVar15 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        bVar19 = false;
        cVar15 = '\0';
      }
    }
    if (*(char *)(param_1 + 0x281) == '\0') {
      if (bVar19 == false) {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        bVar19 = false;
      }
      goto LAB_140ab56c6;
    }
    if (bVar19 != false) {
      if (DAT_145d9fe7a == '\0') {
        bVar19 = false;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar6 = *(char *)(param_1 + 0x281);
    bVar19 = cVar6 == '\0';
    *(undefined4 *)(param_1 + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(param_1 + 0x282) = 0x100;
    iVar14 = -0x4ce4b144;
    if (!bVar19) {
      iVar14 = 0x675a7163;
    }
    uVar8 = 0x7bf72b79;
    if (!bVar19) {
      uVar8 = 0xafb614a6;
    }
    *(undefined4 *)(param_1 + 0x1a0) = uVar8;
    uVar8 = 0x2671d34e;
    if (!bVar19) {
      uVar8 = 0xf230ec91;
    }
    *(undefined4 *)(param_1 + 0x1ac) = uVar8;
    uVar8 = 0x7c1d212;
    if (!bVar19) {
      uVar8 = 0xd380edcd;
    }
    *(undefined4 *)(param_1 + 0x1b4) = uVar8;
    uVar8 = 0x797b9614;
    if (!bVar19) {
      uVar8 = 0xad3aa9cb;
    }
    *(undefined4 *)(param_1 + 0x1a8) = uVar8;
    if (bVar19) {
      iVar7 = *(int *)(param_1 + 0x180);
    }
    else {
      iVar7 = *(int *)(param_1 + 0x178);
    }
    if (iVar7 != 0) {
      piVar20 = (int *)(param_1 + 0x180);
      if (cVar6 != '\0') {
        piVar20 = (int *)(param_1 + 0x178);
      }
      iVar14 = *piVar20;
    }
    *(int *)(param_1 + 0x198) = iVar14;
    uVar24 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar8 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(param_1 + 0x1a0) = uVar8;
      *(undefined4 *)(param_1 + 0x1a4) = 0x26558708;
      uVar24 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar14 = *(int *)(param_1 + 0x188);
    iVar9 = *(int *)(param_1 + 0x18c);
    if (iVar14 != 0) goto LAB_140ab5a94;
    if (iVar9 == 0) {
      if ((!bVar21) || (iVar7 != 0)) {
        if (bVar23) {
          bVar21 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar24 = func_0x000141bbb790();
            bVar21 = (bool)(~(byte)(uVar24 >> 0xf) & 1);
          }
          *(undefined2 *)(param_1 + 0x211) = 0x101;
          uVar8 = 0x9b0f4f04;
          if (bVar21 != false) {
            uVar8 = 0xe6e5760f;
          }
          uVar13 = 0xff0dd6e7;
          if (bVar21 != false) {
            uVar13 = 0xd104919c;
          }
          bVar23 = *(char *)(param_1 + 0x281) != '\0';
          if (bVar23) {
            uVar13 = uVar8;
          }
          uVar8 = 0x6eb97095;
          if (bVar23) {
            uVar8 = 0xde7f5039;
          }
          *(undefined4 *)(param_1 + 0x1a4) = uVar13;
          *(undefined4 *)(param_1 + 0x1a0) = uVar8;
          _DAT_146df261c = 2;
          if (bVar21 == false) {
            uVar24 = 2;
            if (2 < _DAT_146df2630) {
              uVar24 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar24;
            uVar24 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar24 = 2;
            if (2 < _DAT_146df2634) {
              uVar24 = _DAT_146df2634;
            }
          }
        }
        else if (afStackX_8[0]._0_1_ == '\0') {
          if (bVar22) {
            uVar8 = 0x6eb97095;
            if (cVar6 != '\0') {
              uVar8 = 0xde7f5039;
            }
            uVar13 = 0xbf5cd6b2;
            if (cVar6 != '\0') {
              uVar13 = 0xf9af61e;
            }
            *(undefined4 *)(param_1 + 0x1a0) = uVar8;
            *(undefined4 *)(param_1 + 0x1a4) = uVar13;
            _DAT_146df261c = 2;
            uVar24 = _DAT_146df2634;
          }
          else {
            uVar8 = 0x6eb97095;
            if (cVar6 != '\0') {
              uVar8 = 0xde7f5039;
            }
            *(undefined4 *)(param_1 + 0x1a0) = uVar8;
            if (bVar1) {
              uVar8 = 0x99fc5bf5;
              if (cVar6 != '\0') {
                uVar8 = 0x4dbd642a;
              }
            }
            else {
              uVar8 = 0;
            }
            *(undefined4 *)(param_1 + 0x19c) = uVar8;
            uVar8 = 0x26558708;
            if (cVar6 != '\0') {
              uVar8 = 0x9693a7a4;
            }
            *(undefined4 *)(param_1 + 0x1a4) = uVar8;
            uVar24 = _DAT_146df2634;
          }
        }
        else {
          uVar8 = 0x6eb97095;
          if (cVar6 != '\0') {
            uVar8 = 0xde7f5039;
          }
          uVar13 = 0xea32cd03;
          if (cVar6 != '\0') {
            uVar13 = 0x8e3054e0;
          }
          *(undefined4 *)(param_1 + 0x1a0) = uVar8;
          *(undefined4 *)(param_1 + 0x1a4) = uVar13;
          _DAT_146df261c = 2;
          _DAT_146df2638 = 4;
          _DAT_146df263c = 0;
          uVar24 = _DAT_146df2634;
        }
      }
      else {
        bVar21 = cVar6 != '\0';
        *(undefined2 *)(param_1 + 0x211) = 0x101;
        uVar8 = 0x65efd996;
        if (bVar21) {
          uVar8 = 0xd529f93a;
        }
        *(undefined4 *)(param_1 + 0x198) = uVar8;
        uVar8 = 0x2a58dc40;
        if (bVar21) {
          uVar8 = 0xfe19e39f;
        }
        *(undefined4 *)(param_1 + 0x1a0) = uVar8;
        uVar8 = 0xa2dc00a0;
        if (bVar21) {
          uVar8 = 0x769d3f7f;
        }
        *(undefined4 *)(param_1 + 0x1a4) = uVar8;
        uVar24 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(param_1 + 0x1a4) = iVar9;
  *(undefined1 *)(param_1 + 0x211) = *(undefined1 *)(param_1 + 400);
  uVar24 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar24;
  if ((DAT_146df2611 != '\0') || (uVar10 = 1, *(char *)(param_1 + 0x284) != '\0')) {
    uVar10 = 3;
  }
  FUN_1420df1c0(param_1 + 0xf0,uVar10);
  cVar6 = FUN_140ab3ee0(param_1,*(undefined4 *)(param_1 + 0x1a4));
  if (cVar6 == '\0') {
    *(undefined4 *)(param_1 + 0x1a4) = 0;
  }
  lVar11 = *(longlong *)(param_1 + 8);
  uVar8 = *(undefined4 *)(param_1 + 0x198);
  *(undefined4 *)(param_1 + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(param_1 + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar11 + 0x88) == 0) {
    uVar10 = FUN_14167ab40(lVar11 + 0x58,0x1473d09e0);
  }
  else {
    uVar10 = func_0x0001416799a0(lVar11 + 0x80);
  }
  FUN_1415c2240(uVar10,afStackX_8,uVar8,0);
  lVar11 = func_0x0001415ad2a0(0x1473d0730,afStackX_8[0]);
  if (lVar11 != 0) {
    fVar28 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar11,0x3bff28c9);
    if (0.0 <= fVar28) {
      *(float *)(param_1 + 0x1c8) = fVar28;
    }
    else {
      fVar28 = *(float *)(param_1 + 0x1cc);
      *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
    }
    *(float *)(param_1 + 0x1cc) = fVar28;
    fVar28 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar11,0xa959982c);
    if (fVar28 < 0.0) {
      fVar28 = *(float *)(param_1 + 0x1c8);
    }
    *(float *)(param_1 + 0x1c8) = fVar28;
    fVar28 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar11,0xbe47e933);
    if (fVar28 < 0.0) {
      fVar28 = *(float *)(param_1 + 0x1c8);
      if (*(float *)(param_1 + 0x1cc) <= *(float *)(param_1 + 0x1c8)) {
        fVar28 = *(float *)(param_1 + 0x1cc);
      }
    }
    *(float *)(param_1 + 0x1cc) = fVar28;
  }
  func_0x0001415c0440(uVar10,afStackX_8[0]);
  iVar14 = *(int *)(param_1 + 0x19c);
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  if (iVar14 != 0) {
    lVar11 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar11 + 0x88) == 0) {
      uVar10 = FUN_14167ab40(lVar11 + 0x58,0x1473d09e0);
    }
    else {
      uVar10 = func_0x0001416799a0(lVar11 + 0x80);
    }
    FUN_1415c2240(uVar10,afStackX_8,iVar14,0);
    lVar11 = func_0x0001415ad2a0(0x1473d0730,afStackX_8[0]);
    if (lVar11 != 0) {
      fVar28 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar11,0x54638a5f);
      *(float *)(param_1 + 0x1d0) = fVar28;
      if (fVar28 < 0.0) {
        fVar28 = *(float *)(lVar11 + 0x300) * fVar29;
      }
      *(float *)(param_1 + 0x1d0) = fVar28;
      fVar29 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar11,0x3bff28c9);
      *(float *)(param_1 + 0x1d4) = fVar29;
      if ((fVar29 < 0.0) && (fVar29 = *(float *)(lVar11 + 0x300) - _DAT_14382e120, fVar29 <= 0.0)) {
        fVar29 = 0.0;
      }
      *(float *)(param_1 + 0x1d4) = fVar29;
      fVar28 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar11,0xa959982c);
      fVar29 = *(float *)(param_1 + 0x1d4);
      if ((0.0 <= fVar28) && (fVar28 <= fVar29)) {
        fVar29 = fVar28;
      }
      *(float *)(param_1 + 0x1d8) = fVar29;
    }
    func_0x0001415c0440(uVar10,afStackX_8[0]);
  }
  return;
}


/* SwingRegion_140ab4ced @ 0x140ab4ced */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab4ced(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  bool bVar2;
  float fVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  longlong in_RAX;
  undefined8 uVar9;
  longlong lVar10;
  float *pfVar11;
  undefined4 uVar12;
  int iVar13;
  longlong unaff_RBP;
  char cVar14;
  undefined *puVar15;
  undefined *puVar16;
  undefined *puVar17;
  undefined8 unaff_R12;
  undefined8 unaff_R13;
  bool bVar18;
  int *piVar19;
  bool bVar20;
  bool bVar21;
  uint uVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined4 unaff_XMM6_Da;
  float fVar28;
  float fVar29;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  undefined4 unaff_XMM11_Da;
  undefined4 unaff_XMM11_Db;
  undefined4 unaff_XMM11_Dc;
  undefined4 unaff_XMM11_Dd;
  undefined4 unaff_XMM12_Da;
  undefined4 unaff_XMM12_Db;
  undefined4 unaff_XMM12_Dc;
  undefined4 unaff_XMM12_Dd;
  undefined4 unaff_XMM13_Da;
  undefined4 unaff_XMM13_Db;
  undefined4 unaff_XMM13_Dc;
  undefined4 unaff_XMM13_Dd;
  longlong lStack0000000000000028;
  undefined1 uStack0000000000000030;
  char cStack0000000000000041;
  char cStack0000000000000042;
  char cStack0000000000000043;
  char cStack0000000000000044;
  float fStack0000000000000048;
  undefined4 uStack000000000000004c;
  float fStack0000000000000050;
  float fStack0000000000000054;
  int in_stack_00000058;
  int *in_stack_00000060;
  float fStack0000000000000068;
  float fStack000000000000006c;
  float in_stack_00000070;
  float fStack0000000000000078;
  float fStack000000000000007c;
  
  *(undefined8 *)(in_RAX + -0x28) = unaff_R12;
  *(undefined8 *)(in_RAX + -0x30) = unaff_R13;
  *(undefined4 *)(in_RAX + -0x58) = unaff_XMM6_Da;
  *(undefined4 *)(in_RAX + -0x54) = unaff_XMM6_Db;
  *(undefined4 *)(in_RAX + -0x50) = unaff_XMM6_Dc;
  *(undefined4 *)(in_RAX + -0x4c) = unaff_XMM6_Dd;
  lStack0000000000000028 = (longlong)&stack0x00000050 + 4;
  *(undefined4 *)(in_RAX + -0x68) = unaff_XMM7_Da;
  *(undefined4 *)(in_RAX + -100) = unaff_XMM7_Db;
  *(undefined4 *)(in_RAX + -0x60) = unaff_XMM7_Dc;
  *(undefined4 *)(in_RAX + -0x5c) = unaff_XMM7_Dd;
  *(undefined4 *)(in_RAX + -0x88) = unaff_XMM9_Da;
  *(undefined4 *)(in_RAX + -0x84) = unaff_XMM9_Db;
  *(undefined4 *)(in_RAX + -0x80) = unaff_XMM9_Dc;
  *(undefined4 *)(in_RAX + -0x7c) = unaff_XMM9_Dd;
  *(undefined4 *)(in_RAX + -0x98) = unaff_XMM10_Da;
  *(undefined4 *)(in_RAX + -0x94) = unaff_XMM10_Db;
  *(undefined4 *)(in_RAX + -0x90) = unaff_XMM10_Dc;
  *(undefined4 *)(in_RAX + -0x8c) = unaff_XMM10_Dd;
  *(undefined4 *)(in_RAX + -0xa8) = unaff_XMM11_Da;
  *(undefined4 *)(in_RAX + -0xa4) = unaff_XMM11_Db;
  *(undefined4 *)(in_RAX + -0xa0) = unaff_XMM11_Dc;
  *(undefined4 *)(in_RAX + -0x9c) = unaff_XMM11_Dd;
  uStack0000000000000030 = 0;
  *(undefined4 *)(in_RAX + -0xb8) = unaff_XMM12_Da;
  *(undefined4 *)(in_RAX + -0xb4) = unaff_XMM12_Db;
  *(undefined4 *)(in_RAX + -0xb0) = unaff_XMM12_Dc;
  *(undefined4 *)(in_RAX + -0xac) = unaff_XMM12_Dd;
  *(undefined4 *)(in_RAX + -200) = unaff_XMM13_Da;
  *(undefined4 *)(in_RAX + -0xc4) = unaff_XMM13_Db;
  *(undefined4 *)(in_RAX + -0xc0) = unaff_XMM13_Dc;
  *(undefined4 *)(in_RAX + -0xbc) = unaff_XMM13_Dd;
  FUN_140ab4450(param_1 + 0x168,param_2,param_3,&stack0x00000068,unaff_RBP + 0x70);
  in_stack_00000060 = (int *)(param_1 + 0x17c);
  cStack0000000000000044 = *(char *)(param_1 + 0x281);
  iVar13 = *(int *)(param_1 + 0x178);
  if ((((iVar13 == 0) && (*in_stack_00000060 == 0)) || (*(int *)(param_1 + 0x180) != 0)) ||
     (*(int *)(param_1 + 0x184) != 0)) {
    bVar20 = false;
  }
  else {
    bVar20 = true;
  }
  if (((iVar13 == 0) && (*(int *)(param_1 + 0x180) == 0)) ||
     ((*in_stack_00000060 != 0 || (*(int *)(param_1 + 0x184) != 0)))) {
    iVar6 = *in_stack_00000060;
    if (((iVar6 == 0) && (bVar21 = false, *(int *)(param_1 + 0x184) == 0)) ||
       ((bVar21 = false, iVar13 != 0 || (*(int *)(param_1 + 0x180) != 0)))) goto LAB_140ab4dd9;
    bVar18 = true;
LAB_140ab4de1:
    if (*(int *)(param_1 + 0x184) != 0) goto LAB_140ab4dea;
LAB_140ab4e25:
    bVar1 = false;
  }
  else {
    bVar21 = true;
    iVar6 = 0;
LAB_140ab4dd9:
    bVar18 = false;
    if (*(int *)(param_1 + 0x180) == 0) goto LAB_140ab4de1;
LAB_140ab4dea:
    if ((iVar13 != 0) || (iVar6 != 0)) goto LAB_140ab4e25;
    bVar1 = true;
  }
  if ((bVar21) || ((*(float *)(unaff_RBP + 0x70) < _DAT_14384002c && (!bVar18)))) {
    cVar14 = '\x01';
  }
  else {
    cVar14 = '\0';
  }
  *(char *)(unaff_RBP + 0x78) = cVar14;
  if (((cStack0000000000000044 == '\0') && (!bVar20)) || (bVar1)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  lVar10 = *(longlong *)(param_1 + 8);
  *(undefined1 *)(param_1 + 0x281) = uVar4;
  if (*(short *)(lVar10 + 0x88) == 0) {
    uVar9 = FUN_14167ab40(lVar10 + 0x58,0x146dacd70);
  }
  else {
    uVar9 = func_0x0001416799a0(lVar10 + 0x80);
  }
  in_stack_00000058 = func_0x00014085fb90(uVar9);
  bVar20 = in_stack_00000058 == 2;
  cStack0000000000000043 = in_stack_00000058 == 1;
  if ((bVar21) || (cVar14 != '\0')) {
    bVar18 = true;
  }
  else {
    bVar18 = false;
  }
  lVar10 = *(longlong *)(param_1 + 8);
  cStack0000000000000042 = bVar20;
  if (*(short *)(lVar10 + 0x88) == 0) {
    lVar10 = FUN_14167ab40(lVar10 + 0x58,0x146da9d90);
  }
  else {
    lVar10 = func_0x0001416799a0(lVar10 + 0x80);
  }
  fVar27 = _DAT_143848d00;
  if (((lVar10 != 0) && (cVar14 != '\0')) && (!bVar21)) {
    uVar22 = FUN_141f2dd10(*(undefined8 *)(lVar10 + 0x50),0x4453c00,_DAT_143830118);
    bVar18 = fVar27 < (float)(uVar22 & _DAT_14382e160);
  }
  uVar9 = FUN_141676930(param_1);
  fVar23 = (float)FUN_140311350(uVar9,param_1 + 0x150);
  uVar22 = func_0x000141bbb790();
  fVar24 = (float)FUN_140ab42f0();
  bVar21 = false;
  *(undefined1 *)(unaff_RBP + 0x70) = 0;
  fVar3 = _DAT_1438ad724;
  fVar26 = _DAT_143840c8c;
  if (((_DAT_14383d254 <= fVar24) || (fVar24 <= _DAT_143834a04)) ||
     (_DAT_1438ce980 < *(float *)(param_1 + 0x218) || _DAT_1438ce980 == *(float *)(param_1 + 0x218))
     ) {
    cVar14 = '\0';
  }
  else {
    cVar14 = '\x01';
  }
  *(char *)(unaff_RBP + 0x88) = cVar14;
  if (((bVar20) || (fVar3 <= fVar24)) ||
     ((fVar24 <= fVar26 ||
      (_DAT_14387e6ac < *(float *)(param_1 + 0x218) || _DAT_14387e6ac == *(float *)(param_1 + 0x218)
      )))) {
    bVar20 = false;
  }
  else {
    bVar20 = true;
  }
  if ((cVar14 == '\0') || ((_DAT_146df2630 != 0 && (_DAT_146df2634 != 0)))) {
    *(undefined1 *)(unaff_RBP + 0x80) = 0;
  }
  else {
    *(undefined1 *)(unaff_RBP + 0x80) = 1;
  }
  if ((bVar20) && (_DAT_146df2638 == 0)) {
    cVar14 = '\x01';
  }
  else {
    cVar14 = '\0';
  }
  if ((_DAT_145d9fe8c < *(float *)(param_1 + 0x148) || _DAT_145d9fe8c == *(float *)(param_1 + 0x148)
      ) || (DAT_145d9fe7f == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  lVar10 = *(longlong *)(param_1 + 8);
  cStack0000000000000041 = cVar14;
  if (*(short *)(lVar10 + 0x88) == 0) {
    lVar10 = FUN_14167ab40(lVar10 + 0x58,0x147c40bf0);
  }
  else {
    lVar10 = func_0x0001416799a0(lVar10 + 0x80);
  }
  if ((!bVar1) || (*(float *)(lVar10 + 0x6b8) <= _DAT_143830120)) {
    bVar1 = false;
    if ((DAT_145d9fe7f != '\0') &&
       (fVar25 = (float)func_0x0001403e3f30(param_1 + 0x214), _DAT_14382f0e4 < fVar25)) {
      fStack0000000000000048 = *(float *)(param_1 + 0x214);
      fStack0000000000000050 = *(float *)(param_1 + 0x21c);
      uStack000000000000004c = 0;
      FUN_1402d0740(&stack0x00000078,&stack0x00000048);
      pfVar11 = (float *)FUN_141676930(param_1);
      uStack000000000000004c = 0;
      fStack0000000000000048 = *(float *)(param_1 + 0x168) - *pfVar11;
      fStack0000000000000050 = *(float *)(param_1 + 0x170) - pfVar11[2];
      FUN_1402d0740(&stack0x00000068,&stack0x00000048);
      bVar1 = false;
      if (fStack0000000000000078 * fStack0000000000000068 +
          fStack000000000000007c * fStack000000000000006c +
          *(float *)(unaff_RBP + -0x80) * in_stack_00000070 < _DAT_143837a24) {
        bVar1 = true;
      }
    }
  }
  else {
    bVar1 = true;
  }
  fVar25 = _DAT_14382dce0;
  if ((*(int *)(param_1 + 0x188) != 0) || (*(int *)(param_1 + 0x18c) != 0)) {
    bVar1 = false;
  }
  fVar28 = (*(float *)(param_1 + 0x218) - _DAT_1438acf84) * _DAT_1438ce95c;
  if (fVar28 <= 0.0) {
    fVar28 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar28) {
    fVar28 = _DAT_14382dce0;
  }
  fVar29 = _DAT_1438ac760;
  if ((cStack0000000000000042 == '\0') && (cStack0000000000000043 == '\0')) {
    fVar29 = _DAT_14382dce0;
  }
  fVar29 = (fVar28 + fVar26) * fVar29;
  fVar26 = ((float)_DAT_146df263c - _DAT_14382f0e0) * _DAT_14386dc74;
  if (fVar26 <= 0.0) {
    fVar26 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar26) {
    fVar26 = _DAT_14382dce0;
  }
  fVar26 = (float)FUN_143666da0(fVar26,fVar3);
  cVar5 = *(char *)(unaff_RBP + 0x80);
  fVar26 = fVar26 * _DAT_1438cb4b0 + _DAT_143836d0c;
  if (cVar5 == '\0') {
    fVar29 = 0.0;
  }
  if (cVar14 == '\0') {
    fVar26 = 0.0;
  }
  fVar26 = (fVar29 + fVar25 + fVar26) * (float)(uVar22 >> 8) * _DAT_14382e114;
  if (DAT_146df2614 != '\0') {
    func_0x000141bbb4e0(&UNK_1438ce760);
    func_0x000141bbb4e0(&UNK_1438ce778,(double)fStack0000000000000054);
    func_0x000141bbb4e0(&UNK_1438ce790,(double)fVar23);
    func_0x000141bbb4e0(&UNK_1438ce7a8,(double)*(float *)(param_1 + 0x218));
    func_0x000141bbb4e0(&UNK_1438ce7c0,(double)fVar24);
    func_0x000141bbb4e0(&UNK_1438ce7d8,
                        *(undefined8 *)
                         (*(longlong *)(_DAT_145e11438 + 0x20) + (longlong)in_stack_00000058 * 8));
    puVar15 = &UNK_1438ce7ec;
    func_0x000141bbb4e0(&UNK_1438ce7f8,&UNK_1438ce7f0,&UNK_1438ce7ec,_DAT_143830a28);
    puVar16 = &UNK_1438ce7ec;
    if (_DAT_146df261c != 0) {
      puVar16 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce830,&UNK_1438ce7ec,puVar16,0);
    puVar16 = &UNK_1438ce7ec;
    if (*(char *)(unaff_RBP + 0x88) != '\0') {
      puVar16 = &UNK_1438ce7f0;
    }
    puVar17 = &UNK_1438ce7ec;
    if (_DAT_146df2630 != 0) {
      puVar17 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce868,puVar16,puVar17,(double)fVar29);
    puVar17 = &UNK_1438ce7ec;
    if (_DAT_146df2634 != 0) {
      puVar17 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8a0,puVar16,puVar17,(double)fVar29);
    puVar16 = &UNK_1438ce7ec;
    if (_DAT_146df2638 != 0) {
      puVar16 = &UNK_1438ce7f0;
    }
    if (bVar20) {
      puVar15 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8d8,puVar15,puVar16);
    func_0x000141bbb4e0(&UNK_1438ce910,(double)fVar26);
    cVar5 = *(char *)(unaff_RBP + 0x80);
    cVar14 = cStack0000000000000041;
  }
  if (_DAT_1438aa3f4 <= fVar26) {
    if ((cVar5 == '\0') || (fVar29 + fVar25 <= fVar26)) {
      if (cVar14 != '\0') {
        *(undefined1 *)(unaff_RBP + 0x70) = 1;
        bVar18 = true;
      }
    }
    else {
      bVar21 = true;
      bVar18 = true;
    }
  }
  if ((*(char *)(param_1 + 0x1fd) != '\0') && (cStack0000000000000044 != *(char *)(param_1 + 0x281))
     ) {
    bVar21 = false;
    bVar1 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
  }
  if (_DAT_146df2618 == 1) {
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
LAB_140ab54ac:
    bVar20 = false;
    bVar21 = false;
  }
  else if (_DAT_146df2618 == 2) {
    bVar21 = false;
    bVar20 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
    bVar18 = false;
  }
  else {
    bVar20 = false;
    if (_DAT_146df2618 == 3) {
      bVar21 = true;
      *(undefined1 *)(unaff_RBP + 0x70) = 0;
      bVar18 = true;
    }
    else if (_DAT_146df2618 == 4) {
      *(undefined1 *)(unaff_RBP + 0x70) = 1;
      bVar18 = true;
      goto LAB_140ab54ac;
    }
  }
  if (((cStack0000000000000042 == '\0') || (bVar21)) ||
     ((*(char *)(param_1 + 0x28a) == '\0' && (_DAT_14383d148 <= fVar24)))) {
    cVar14 = *(char *)(unaff_RBP + 0x78);
    bVar2 = false;
  }
  else {
    cVar14 = *(char *)(unaff_RBP + 0x78);
    if (bVar18 == false) {
      if (cVar14 != '\0') {
        uVar22 = func_0x000141bbb790();
        bVar18 = (bool)(~(byte)(uVar22 >> 0xf) & 1);
        if (bVar18 != false) goto LAB_140ab54fd;
      }
    }
    else {
LAB_140ab54fd:
      if (DAT_146df2614 != '\0') {
        func_0x000141bbb4e0(&UNK_1438ce920);
      }
    }
    bVar2 = true;
  }
  if (DAT_146df2616 != '\0') {
    bVar2 = true;
    bVar18 = true;
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(param_1 + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar14 != '\0') && (bVar18 != false)) goto LAB_140ab5619;
    cVar14 = *(char *)(param_1 + 0x281);
    bVar21 = cVar14 == '\0';
    *(undefined4 *)(param_1 + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(param_1 + 0x1ac) = 0x836c214c;
    *(undefined4 *)(param_1 + 0x1b0) = 0xa1ff8610;
    iVar13 = 0x42991cb0;
    if (!bVar21) {
      iVar13 = -0x6927dc91;
    }
    *(undefined2 *)(param_1 + 0x282) = 1;
    uVar7 = 0x9a5e57b2;
    if (!bVar21) {
      uVar7 = 0x4e1f686d;
    }
    *(undefined4 *)(param_1 + 0x1a8) = uVar7;
    uVar7 = 0x734348c3;
    if (!bVar21) {
      uVar7 = 0xa702771c;
    }
    *(undefined4 *)(param_1 + 0x1b4) = uVar7;
    if (bVar21) {
      iVar6 = *(int *)(param_1 + 0x184);
    }
    else {
      iVar6 = *in_stack_00000060;
    }
    if (iVar6 != 0) {
      if (cVar14 == '\0') {
        iVar13 = *(int *)(param_1 + 0x184);
      }
      else {
        iVar13 = *in_stack_00000060;
      }
    }
    *(int *)(param_1 + 0x198) = iVar13;
    uVar22 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar13 = *(int *)(param_1 + 0x188);
    iVar8 = *(int *)(param_1 + 0x18c);
    if (iVar13 == 0) {
      if (iVar8 == 0) {
        if ((!bVar2) || (iVar6 != 0)) {
          *(undefined4 *)(param_1 + 0x1a0) = 0xea6ee521;
          if (bVar20) {
            *(undefined4 *)(param_1 + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar22 = _DAT_146df2634;
          }
          else {
            if (bVar1) {
              uVar7 = 0x4db30291;
              if (cVar14 != '\0') {
                uVar7 = 0x99f23d4e;
              }
            }
            else {
              uVar7 = 0;
            }
            *(undefined4 *)(param_1 + 0x19c) = uVar7;
            *(undefined4 *)(param_1 + 0x1a4) = 0x6498e62f;
            uVar22 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x1a0) = 0xf60be115;
          *(undefined4 *)(param_1 + 0x1a4) = 0x568987b1;
          *(undefined1 *)(param_1 + 0x211) = 1;
          uVar7 = 0x736ce232;
          if (cVar14 != '\0') {
            uVar7 = 0xc3aac29e;
          }
          *(undefined4 *)(param_1 + 0x198) = uVar7;
          uVar22 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(param_1 + 0x1a0) = iVar13;
      if (iVar8 == 0) {
        iVar8 = *(int *)(param_1 + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(param_1 + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        bVar18 = true;
        cVar14 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        bVar18 = false;
        cVar14 = '\0';
      }
    }
    if (*(char *)(param_1 + 0x281) == '\0') {
      if (bVar18 == false) {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        bVar18 = false;
      }
      goto LAB_140ab56c6;
    }
    if (bVar18 != false) {
      if (DAT_145d9fe7a == '\0') {
        bVar18 = false;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar14 = *(char *)(param_1 + 0x281);
    bVar18 = cVar14 == '\0';
    *(undefined4 *)(param_1 + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(param_1 + 0x282) = 0x100;
    iVar13 = -0x4ce4b144;
    if (!bVar18) {
      iVar13 = 0x675a7163;
    }
    uVar7 = 0x7bf72b79;
    if (!bVar18) {
      uVar7 = 0xafb614a6;
    }
    *(undefined4 *)(param_1 + 0x1a0) = uVar7;
    uVar7 = 0x2671d34e;
    if (!bVar18) {
      uVar7 = 0xf230ec91;
    }
    *(undefined4 *)(param_1 + 0x1ac) = uVar7;
    uVar7 = 0x7c1d212;
    if (!bVar18) {
      uVar7 = 0xd380edcd;
    }
    *(undefined4 *)(param_1 + 0x1b4) = uVar7;
    uVar7 = 0x797b9614;
    if (!bVar18) {
      uVar7 = 0xad3aa9cb;
    }
    *(undefined4 *)(param_1 + 0x1a8) = uVar7;
    if (bVar18) {
      iVar6 = *(int *)(param_1 + 0x180);
    }
    else {
      iVar6 = *(int *)(param_1 + 0x178);
    }
    if (iVar6 != 0) {
      piVar19 = (int *)(param_1 + 0x180);
      if (cVar14 != '\0') {
        piVar19 = (int *)(param_1 + 0x178);
      }
      iVar13 = *piVar19;
    }
    *(int *)(param_1 + 0x198) = iVar13;
    uVar22 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar7 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(param_1 + 0x1a0) = uVar7;
      *(undefined4 *)(param_1 + 0x1a4) = 0x26558708;
      uVar22 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar13 = *(int *)(param_1 + 0x188);
    iVar8 = *(int *)(param_1 + 0x18c);
    if (iVar13 != 0) goto LAB_140ab5a94;
    if (iVar8 == 0) {
      if ((!bVar2) || (iVar6 != 0)) {
        if (bVar21) {
          bVar20 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar22 = func_0x000141bbb790();
            bVar20 = (bool)(~(byte)(uVar22 >> 0xf) & 1);
          }
          *(undefined2 *)(param_1 + 0x211) = 0x101;
          uVar7 = 0x9b0f4f04;
          if (bVar20 != false) {
            uVar7 = 0xe6e5760f;
          }
          uVar12 = 0xff0dd6e7;
          if (bVar20 != false) {
            uVar12 = 0xd104919c;
          }
          bVar21 = *(char *)(param_1 + 0x281) != '\0';
          if (bVar21) {
            uVar12 = uVar7;
          }
          uVar7 = 0x6eb97095;
          if (bVar21) {
            uVar7 = 0xde7f5039;
          }
          *(undefined4 *)(param_1 + 0x1a4) = uVar12;
          *(undefined4 *)(param_1 + 0x1a0) = uVar7;
          _DAT_146df261c = 2;
          if (bVar20 == false) {
            uVar22 = 2;
            if (2 < _DAT_146df2630) {
              uVar22 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar22;
            uVar22 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar22 = 2;
            if (2 < _DAT_146df2634) {
              uVar22 = _DAT_146df2634;
            }
          }
        }
        else if (*(char *)(unaff_RBP + 0x70) == '\0') {
          if (bVar20) {
            uVar7 = 0x6eb97095;
            if (cVar14 != '\0') {
              uVar7 = 0xde7f5039;
            }
            uVar12 = 0xbf5cd6b2;
            if (cVar14 != '\0') {
              uVar12 = 0xf9af61e;
            }
            *(undefined4 *)(param_1 + 0x1a0) = uVar7;
            *(undefined4 *)(param_1 + 0x1a4) = uVar12;
            _DAT_146df261c = 2;
            uVar22 = _DAT_146df2634;
          }
          else {
            uVar7 = 0x6eb97095;
            if (cVar14 != '\0') {
              uVar7 = 0xde7f5039;
            }
            *(undefined4 *)(param_1 + 0x1a0) = uVar7;
            if (bVar1) {
              uVar7 = 0x99fc5bf5;
              if (cVar14 != '\0') {
                uVar7 = 0x4dbd642a;
              }
            }
            else {
              uVar7 = 0;
            }
            *(undefined4 *)(param_1 + 0x19c) = uVar7;
            uVar7 = 0x26558708;
            if (cVar14 != '\0') {
              uVar7 = 0x9693a7a4;
            }
            *(undefined4 *)(param_1 + 0x1a4) = uVar7;
            uVar22 = _DAT_146df2634;
          }
        }
        else {
          uVar7 = 0x6eb97095;
          if (cVar14 != '\0') {
            uVar7 = 0xde7f5039;
          }
          uVar12 = 0xea32cd03;
          if (cVar14 != '\0') {
            uVar12 = 0x8e3054e0;
          }
          *(undefined4 *)(param_1 + 0x1a0) = uVar7;
          *(undefined4 *)(param_1 + 0x1a4) = uVar12;
          _DAT_146df261c = 2;
          _DAT_146df2638 = 4;
          _DAT_146df263c = 0;
          uVar22 = _DAT_146df2634;
        }
      }
      else {
        bVar20 = cVar14 != '\0';
        *(undefined2 *)(param_1 + 0x211) = 0x101;
        uVar7 = 0x65efd996;
        if (bVar20) {
          uVar7 = 0xd529f93a;
        }
        *(undefined4 *)(param_1 + 0x198) = uVar7;
        uVar7 = 0x2a58dc40;
        if (bVar20) {
          uVar7 = 0xfe19e39f;
        }
        *(undefined4 *)(param_1 + 0x1a0) = uVar7;
        uVar7 = 0xa2dc00a0;
        if (bVar20) {
          uVar7 = 0x769d3f7f;
        }
        *(undefined4 *)(param_1 + 0x1a4) = uVar7;
        uVar22 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(param_1 + 0x1a4) = iVar8;
  *(undefined1 *)(param_1 + 0x211) = *(undefined1 *)(param_1 + 400);
  uVar22 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar22;
  if ((DAT_146df2611 != '\0') || (uVar9 = 1, *(char *)(param_1 + 0x284) != '\0')) {
    uVar9 = 3;
  }
  FUN_1420df1c0(param_1 + 0xf0,uVar9);
  cVar14 = FUN_140ab3ee0(param_1,*(undefined4 *)(param_1 + 0x1a4));
  if (cVar14 == '\0') {
    *(undefined4 *)(param_1 + 0x1a4) = 0;
  }
  lVar10 = *(longlong *)(param_1 + 8);
  uVar7 = *(undefined4 *)(param_1 + 0x198);
  *(undefined4 *)(param_1 + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(param_1 + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar10 + 0x88) == 0) {
    uVar9 = FUN_14167ab40(lVar10 + 0x58,0x1473d09e0);
  }
  else {
    uVar9 = func_0x0001416799a0(lVar10 + 0x80);
  }
  FUN_1415c2240(uVar9,unaff_RBP + 0x70,uVar7,0);
  lVar10 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar10 != 0) {
    fVar26 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar10,0x3bff28c9);
    if (0.0 <= fVar26) {
      *(float *)(param_1 + 0x1c8) = fVar26;
    }
    else {
      fVar26 = *(float *)(param_1 + 0x1cc);
      *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
    }
    *(float *)(param_1 + 0x1cc) = fVar26;
    fVar26 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar10,0xa959982c);
    if (fVar26 < 0.0) {
      fVar26 = *(float *)(param_1 + 0x1c8);
    }
    *(float *)(param_1 + 0x1c8) = fVar26;
    fVar26 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar10,0xbe47e933);
    if (fVar26 < 0.0) {
      fVar26 = *(float *)(param_1 + 0x1c8);
      if (*(float *)(param_1 + 0x1cc) <= *(float *)(param_1 + 0x1c8)) {
        fVar26 = *(float *)(param_1 + 0x1cc);
      }
    }
    *(float *)(param_1 + 0x1cc) = fVar26;
  }
  func_0x0001415c0440(uVar9,*(undefined4 *)(unaff_RBP + 0x70));
  iVar13 = *(int *)(param_1 + 0x19c);
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  if (iVar13 != 0) {
    lVar10 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar10 + 0x88) == 0) {
      uVar9 = FUN_14167ab40(lVar10 + 0x58,0x1473d09e0);
    }
    else {
      uVar9 = func_0x0001416799a0(lVar10 + 0x80);
    }
    FUN_1415c2240(uVar9,unaff_RBP + 0x70,iVar13,0);
    lVar10 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar10 != 0) {
      fVar26 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar10,0x54638a5f);
      *(float *)(param_1 + 0x1d0) = fVar26;
      if (fVar26 < 0.0) {
        fVar26 = *(float *)(lVar10 + 0x300) * fVar27;
      }
      *(float *)(param_1 + 0x1d0) = fVar26;
      fVar27 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar10,0x3bff28c9);
      *(float *)(param_1 + 0x1d4) = fVar27;
      if ((fVar27 < 0.0) && (fVar27 = *(float *)(lVar10 + 0x300) - _DAT_14382e120, fVar27 <= 0.0)) {
        fVar27 = 0.0;
      }
      *(float *)(param_1 + 0x1d4) = fVar27;
      fVar26 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),lVar10,0xa959982c);
      fVar27 = *(float *)(param_1 + 0x1d4);
      if ((0.0 <= fVar26) && (fVar26 <= fVar27)) {
        fVar27 = fVar26;
      }
      *(float *)(param_1 + 0x1d8) = fVar27;
    }
    func_0x0001415c0440(uVar9,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab4cfd @ 0x140ab4cfd */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab4cfd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  bool bVar2;
  float fVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  longlong in_RAX;
  undefined8 uVar8;
  longlong lVar9;
  float *pfVar10;
  undefined4 uVar11;
  int iVar12;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char cVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined *puVar16;
  bool bVar17;
  int *piVar18;
  bool bVar19;
  bool bVar20;
  uint uVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined4 uVar26;
  float fVar27;
  undefined4 unaff_XMM6_Da;
  float fVar28;
  float fVar29;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  undefined4 unaff_XMM11_Da;
  undefined4 unaff_XMM11_Db;
  undefined4 unaff_XMM11_Dc;
  undefined4 unaff_XMM11_Dd;
  undefined4 unaff_XMM12_Da;
  undefined4 unaff_XMM12_Db;
  undefined4 unaff_XMM12_Dc;
  undefined4 unaff_XMM12_Dd;
  undefined4 unaff_XMM13_Da;
  undefined4 unaff_XMM13_Db;
  undefined4 unaff_XMM13_Dc;
  undefined4 unaff_XMM13_Dd;
  longlong lStack0000000000000028;
  undefined1 uStack0000000000000030;
  char cStack0000000000000041;
  char cStack0000000000000042;
  char cStack0000000000000043;
  char cStack0000000000000044;
  float fStack0000000000000048;
  undefined4 uStack000000000000004c;
  float fStack0000000000000050;
  float fStack0000000000000054;
  int in_stack_00000058;
  int *in_stack_00000060;
  float fStack0000000000000068;
  float fStack000000000000006c;
  float in_stack_00000070;
  float fStack0000000000000078;
  float fStack000000000000007c;
  
  *(undefined4 *)(in_RAX + -0x58) = unaff_XMM6_Da;
  *(undefined4 *)(in_RAX + -0x54) = unaff_XMM6_Db;
  *(undefined4 *)(in_RAX + -0x50) = unaff_XMM6_Dc;
  *(undefined4 *)(in_RAX + -0x4c) = unaff_XMM6_Dd;
  lStack0000000000000028 = (longlong)&stack0x00000050 + 4;
  *(undefined4 *)(in_RAX + -0x68) = unaff_XMM7_Da;
  *(undefined4 *)(in_RAX + -100) = unaff_XMM7_Db;
  *(undefined4 *)(in_RAX + -0x60) = unaff_XMM7_Dc;
  *(undefined4 *)(in_RAX + -0x5c) = unaff_XMM7_Dd;
  *(undefined4 *)(in_RAX + -0x88) = unaff_XMM9_Da;
  *(undefined4 *)(in_RAX + -0x84) = unaff_XMM9_Db;
  *(undefined4 *)(in_RAX + -0x80) = unaff_XMM9_Dc;
  *(undefined4 *)(in_RAX + -0x7c) = unaff_XMM9_Dd;
  *(undefined4 *)(in_RAX + -0x98) = unaff_XMM10_Da;
  *(undefined4 *)(in_RAX + -0x94) = unaff_XMM10_Db;
  *(undefined4 *)(in_RAX + -0x90) = unaff_XMM10_Dc;
  *(undefined4 *)(in_RAX + -0x8c) = unaff_XMM10_Dd;
  *(undefined4 *)(in_RAX + -0xa8) = unaff_XMM11_Da;
  *(undefined4 *)(in_RAX + -0xa4) = unaff_XMM11_Db;
  *(undefined4 *)(in_RAX + -0xa0) = unaff_XMM11_Dc;
  *(undefined4 *)(in_RAX + -0x9c) = unaff_XMM11_Dd;
  uStack0000000000000030 = 0;
  *(undefined4 *)(in_RAX + -0xb8) = unaff_XMM12_Da;
  *(undefined4 *)(in_RAX + -0xb4) = unaff_XMM12_Db;
  *(undefined4 *)(in_RAX + -0xb0) = unaff_XMM12_Dc;
  *(undefined4 *)(in_RAX + -0xac) = unaff_XMM12_Dd;
  *(undefined4 *)(in_RAX + -200) = unaff_XMM13_Da;
  *(undefined4 *)(in_RAX + -0xc4) = unaff_XMM13_Db;
  *(undefined4 *)(in_RAX + -0xc0) = unaff_XMM13_Dc;
  *(undefined4 *)(in_RAX + -0xbc) = unaff_XMM13_Dd;
  FUN_140ab4450(unaff_RSI + 0x168,param_2,param_3,param_4,unaff_RBP + 0x70);
  in_stack_00000060 = (int *)(unaff_RSI + 0x17c);
  cStack0000000000000044 = *(char *)(unaff_RSI + 0x281);
  iVar12 = *(int *)(unaff_RSI + 0x178);
  if ((((iVar12 == 0) && (*in_stack_00000060 == 0)) || (*(int *)(unaff_RSI + 0x180) != 0)) ||
     (*(int *)(unaff_RSI + 0x184) != 0)) {
    bVar19 = false;
  }
  else {
    bVar19 = true;
  }
  if (((iVar12 == 0) && (*(int *)(unaff_RSI + 0x180) == 0)) ||
     ((*in_stack_00000060 != 0 || (*(int *)(unaff_RSI + 0x184) != 0)))) {
    iVar6 = *in_stack_00000060;
    if (((iVar6 == 0) && (bVar20 = false, *(int *)(unaff_RSI + 0x184) == 0)) ||
       ((bVar20 = false, iVar12 != 0 || (*(int *)(unaff_RSI + 0x180) != 0)))) goto LAB_140ab4dd9;
    bVar17 = true;
LAB_140ab4de1:
    if (*(int *)(unaff_RSI + 0x184) != 0) goto LAB_140ab4dea;
LAB_140ab4e25:
    bVar1 = false;
  }
  else {
    bVar20 = true;
    iVar6 = 0;
LAB_140ab4dd9:
    bVar17 = false;
    if (*(int *)(unaff_RSI + 0x180) == 0) goto LAB_140ab4de1;
LAB_140ab4dea:
    if ((iVar12 != 0) || (iVar6 != 0)) goto LAB_140ab4e25;
    bVar1 = true;
  }
  if ((bVar20) || ((*(float *)(unaff_RBP + 0x70) < _DAT_14384002c && (!bVar17)))) {
    cVar13 = '\x01';
  }
  else {
    cVar13 = '\0';
  }
  *(char *)(unaff_RBP + 0x78) = cVar13;
  if (((cStack0000000000000044 == '\0') && (!bVar19)) || (bVar1)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  lVar9 = *(longlong *)(unaff_RSI + 8);
  *(undefined1 *)(unaff_RSI + 0x281) = uVar4;
  if (*(short *)(lVar9 + 0x88) == 0) {
    uVar8 = FUN_14167ab40(lVar9 + 0x58,0x146dacd70);
  }
  else {
    uVar8 = func_0x0001416799a0(lVar9 + 0x80);
  }
  in_stack_00000058 = func_0x00014085fb90(uVar8);
  bVar19 = in_stack_00000058 == 2;
  cStack0000000000000043 = in_stack_00000058 == 1;
  if ((bVar20) || (cVar13 != '\0')) {
    bVar17 = true;
  }
  else {
    bVar17 = false;
  }
  lVar9 = *(longlong *)(unaff_RSI + 8);
  cStack0000000000000042 = bVar19;
  if (*(short *)(lVar9 + 0x88) == 0) {
    lVar9 = FUN_14167ab40(lVar9 + 0x58,0x146da9d90);
  }
  else {
    lVar9 = func_0x0001416799a0(lVar9 + 0x80);
  }
  fVar27 = _DAT_143848d00;
  if (((lVar9 != 0) && (cVar13 != '\0')) && (!bVar20)) {
    uVar21 = FUN_141f2dd10(*(undefined8 *)(lVar9 + 0x50),0x4453c00,_DAT_143830118);
    bVar17 = fVar27 < (float)(uVar21 & _DAT_14382e160);
  }
  uVar8 = FUN_141676930();
  fVar22 = (float)FUN_140311350(uVar8,unaff_RSI + 0x150);
  uVar21 = func_0x000141bbb790();
  fVar23 = (float)FUN_140ab42f0();
  bVar20 = false;
  *(undefined1 *)(unaff_RBP + 0x70) = 0;
  fVar3 = _DAT_1438ad724;
  fVar25 = _DAT_143840c8c;
  if (((_DAT_14383d254 <= fVar23) || (fVar23 <= _DAT_143834a04)) ||
     (_DAT_1438ce980 < *(float *)(unaff_RSI + 0x218) ||
      _DAT_1438ce980 == *(float *)(unaff_RSI + 0x218))) {
    cVar13 = '\0';
  }
  else {
    cVar13 = '\x01';
  }
  *(char *)(unaff_RBP + 0x88) = cVar13;
  if (((bVar19) || (fVar3 <= fVar23)) ||
     ((fVar23 <= fVar25 ||
      (_DAT_14387e6ac < *(float *)(unaff_RSI + 0x218) ||
       _DAT_14387e6ac == *(float *)(unaff_RSI + 0x218))))) {
    bVar19 = false;
  }
  else {
    bVar19 = true;
  }
  if ((cVar13 == '\0') || ((_DAT_146df2630 != 0 && (_DAT_146df2634 != 0)))) {
    *(undefined1 *)(unaff_RBP + 0x80) = 0;
  }
  else {
    *(undefined1 *)(unaff_RBP + 0x80) = 1;
  }
  if ((bVar19) && (_DAT_146df2638 == 0)) {
    cVar13 = '\x01';
  }
  else {
    cVar13 = '\0';
  }
  if ((_DAT_145d9fe8c < *(float *)(unaff_RSI + 0x148) ||
       _DAT_145d9fe8c == *(float *)(unaff_RSI + 0x148)) || (DAT_145d9fe7f == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  lVar9 = *(longlong *)(unaff_RSI + 8);
  cStack0000000000000041 = cVar13;
  if (*(short *)(lVar9 + 0x88) == 0) {
    lVar9 = FUN_14167ab40(lVar9 + 0x58,0x147c40bf0);
  }
  else {
    lVar9 = func_0x0001416799a0(lVar9 + 0x80);
  }
  if ((!bVar1) || (*(float *)(lVar9 + 0x6b8) <= _DAT_143830120)) {
    bVar1 = false;
    if ((DAT_145d9fe7f != '\0') &&
       (fVar24 = (float)func_0x0001403e3f30(unaff_RSI + 0x214), _DAT_14382f0e4 < fVar24)) {
      fStack0000000000000048 = *(float *)(unaff_RSI + 0x214);
      fStack0000000000000050 = *(float *)(unaff_RSI + 0x21c);
      uStack000000000000004c = 0;
      FUN_1402d0740(&stack0x00000078,&stack0x00000048);
      pfVar10 = (float *)FUN_141676930();
      uStack000000000000004c = 0;
      fStack0000000000000048 = *(float *)(unaff_RSI + 0x168) - *pfVar10;
      fStack0000000000000050 = *(float *)(unaff_RSI + 0x170) - pfVar10[2];
      FUN_1402d0740(&stack0x00000068,&stack0x00000048);
      bVar1 = false;
      if (fStack0000000000000078 * fStack0000000000000068 +
          fStack000000000000007c * fStack000000000000006c +
          *(float *)(unaff_RBP + -0x80) * in_stack_00000070 < _DAT_143837a24) {
        bVar1 = true;
      }
    }
  }
  else {
    bVar1 = true;
  }
  fVar24 = _DAT_14382dce0;
  if ((*(int *)(unaff_RSI + 0x188) != 0) || (*(int *)(unaff_RSI + 0x18c) != 0)) {
    bVar1 = false;
  }
  fVar28 = (*(float *)(unaff_RSI + 0x218) - _DAT_1438acf84) * _DAT_1438ce95c;
  if (fVar28 <= 0.0) {
    fVar28 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar28) {
    fVar28 = _DAT_14382dce0;
  }
  fVar29 = _DAT_1438ac760;
  if ((cStack0000000000000042 == '\0') && (cStack0000000000000043 == '\0')) {
    fVar29 = _DAT_14382dce0;
  }
  fVar29 = (fVar28 + fVar25) * fVar29;
  fVar25 = ((float)_DAT_146df263c - _DAT_14382f0e0) * _DAT_14386dc74;
  if (fVar25 <= 0.0) {
    fVar25 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar25) {
    fVar25 = _DAT_14382dce0;
  }
  fVar25 = (float)FUN_143666da0(fVar25,fVar3);
  cVar5 = *(char *)(unaff_RBP + 0x80);
  fVar25 = fVar25 * _DAT_1438cb4b0 + _DAT_143836d0c;
  if (cVar5 == '\0') {
    fVar29 = 0.0;
  }
  if (cVar13 == '\0') {
    fVar25 = 0.0;
  }
  fVar25 = (fVar29 + fVar24 + fVar25) * (float)(uVar21 >> 8) * _DAT_14382e114;
  if (DAT_146df2614 != '\0') {
    func_0x000141bbb4e0(&UNK_1438ce760);
    func_0x000141bbb4e0(&UNK_1438ce778,(double)fStack0000000000000054);
    func_0x000141bbb4e0(&UNK_1438ce790,(double)fVar22);
    func_0x000141bbb4e0(&UNK_1438ce7a8,(double)*(float *)(unaff_RSI + 0x218));
    func_0x000141bbb4e0(&UNK_1438ce7c0,(double)fVar23);
    func_0x000141bbb4e0(&UNK_1438ce7d8,
                        *(undefined8 *)
                         (*(longlong *)(_DAT_145e11438 + 0x20) + (longlong)in_stack_00000058 * 8));
    puVar14 = &UNK_1438ce7ec;
    func_0x000141bbb4e0(&UNK_1438ce7f8,&UNK_1438ce7f0,&UNK_1438ce7ec,_DAT_143830a28);
    puVar15 = &UNK_1438ce7ec;
    if (_DAT_146df261c != 0) {
      puVar15 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce830,&UNK_1438ce7ec,puVar15,0);
    puVar15 = &UNK_1438ce7ec;
    if (*(char *)(unaff_RBP + 0x88) != '\0') {
      puVar15 = &UNK_1438ce7f0;
    }
    puVar16 = &UNK_1438ce7ec;
    if (_DAT_146df2630 != 0) {
      puVar16 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce868,puVar15,puVar16,(double)fVar29);
    puVar16 = &UNK_1438ce7ec;
    if (_DAT_146df2634 != 0) {
      puVar16 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8a0,puVar15,puVar16,(double)fVar29);
    puVar15 = &UNK_1438ce7ec;
    if (_DAT_146df2638 != 0) {
      puVar15 = &UNK_1438ce7f0;
    }
    if (bVar19) {
      puVar14 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8d8,puVar14,puVar15);
    func_0x000141bbb4e0(&UNK_1438ce910,(double)fVar25);
    cVar5 = *(char *)(unaff_RBP + 0x80);
    cVar13 = cStack0000000000000041;
  }
  if (_DAT_1438aa3f4 <= fVar25) {
    if ((cVar5 == '\0') || (fVar29 + fVar24 <= fVar25)) {
      if (cVar13 != '\0') {
        *(undefined1 *)(unaff_RBP + 0x70) = 1;
        bVar17 = true;
      }
    }
    else {
      bVar20 = true;
      bVar17 = true;
    }
  }
  if ((*(char *)(unaff_RSI + 0x1fd) != '\0') &&
     (cStack0000000000000044 != *(char *)(unaff_RSI + 0x281))) {
    bVar20 = false;
    bVar1 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
  }
  if (_DAT_146df2618 == 1) {
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
LAB_140ab54ac:
    bVar19 = false;
    bVar20 = false;
  }
  else if (_DAT_146df2618 == 2) {
    bVar20 = false;
    bVar19 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
    bVar17 = false;
  }
  else {
    bVar19 = false;
    if (_DAT_146df2618 == 3) {
      bVar20 = true;
      *(undefined1 *)(unaff_RBP + 0x70) = 0;
      bVar17 = true;
    }
    else if (_DAT_146df2618 == 4) {
      *(undefined1 *)(unaff_RBP + 0x70) = 1;
      bVar17 = true;
      goto LAB_140ab54ac;
    }
  }
  if (((cStack0000000000000042 == '\0') || (bVar20)) ||
     ((*(char *)(unaff_RSI + 0x28a) == '\0' && (_DAT_14383d148 <= fVar23)))) {
    cVar13 = *(char *)(unaff_RBP + 0x78);
    bVar2 = false;
  }
  else {
    cVar13 = *(char *)(unaff_RBP + 0x78);
    if (bVar17 == false) {
      if (cVar13 != '\0') {
        uVar21 = func_0x000141bbb790();
        bVar17 = (bool)(~(byte)(uVar21 >> 0xf) & 1);
        if (bVar17 != false) goto LAB_140ab54fd;
      }
    }
    else {
LAB_140ab54fd:
      if (DAT_146df2614 != '\0') {
        func_0x000141bbb4e0(&UNK_1438ce920);
      }
    }
    bVar2 = true;
  }
  if (DAT_146df2616 != '\0') {
    bVar2 = true;
    bVar17 = true;
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(unaff_RSI + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar13 != '\0') && (bVar17 != false)) goto LAB_140ab5619;
    cVar13 = *(char *)(unaff_RSI + 0x281);
    bVar20 = cVar13 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar12 = 0x42991cb0;
    if (!bVar20) {
      iVar12 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar26 = 0x9a5e57b2;
    if (!bVar20) {
      uVar26 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar26;
    uVar26 = 0x734348c3;
    if (!bVar20) {
      uVar26 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar26;
    if (bVar20) {
      iVar6 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar6 = *in_stack_00000060;
    }
    if (iVar6 != 0) {
      if (cVar13 == '\0') {
        iVar12 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar12 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar12;
    uVar21 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar12 = *(int *)(unaff_RSI + 0x188);
    iVar7 = *(int *)(unaff_RSI + 0x18c);
    if (iVar12 == 0) {
      if (iVar7 == 0) {
        if ((!bVar2) || (iVar6 != 0)) {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
          if (bVar19) {
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar21 = _DAT_146df2634;
          }
          else {
            if (bVar1) {
              uVar26 = 0x4db30291;
              if (cVar13 != '\0') {
                uVar26 = 0x99f23d4e;
              }
            }
            else {
              uVar26 = 0;
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar26;
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
            uVar21 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
          *(undefined1 *)(unaff_RSI + 0x211) = 1;
          uVar26 = 0x736ce232;
          if (cVar13 != '\0') {
            uVar26 = 0xc3aac29e;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar26;
          uVar21 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar12;
      if (iVar7 == 0) {
        iVar7 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(unaff_RSI + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        bVar17 = true;
        cVar13 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        bVar17 = false;
        cVar13 = '\0';
      }
    }
    if (*(char *)(unaff_RSI + 0x281) == '\0') {
      if (bVar17 == false) {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        bVar17 = false;
      }
      goto LAB_140ab56c6;
    }
    if (bVar17 != false) {
      if (DAT_145d9fe7a == '\0') {
        bVar17 = false;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar13 = *(char *)(unaff_RSI + 0x281);
    bVar17 = cVar13 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar12 = -0x4ce4b144;
    if (!bVar17) {
      iVar12 = 0x675a7163;
    }
    uVar26 = 0x7bf72b79;
    if (!bVar17) {
      uVar26 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
    uVar26 = 0x2671d34e;
    if (!bVar17) {
      uVar26 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar26;
    uVar26 = 0x7c1d212;
    if (!bVar17) {
      uVar26 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar26;
    uVar26 = 0x797b9614;
    if (!bVar17) {
      uVar26 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar26;
    if (bVar17) {
      iVar6 = *(int *)(unaff_RSI + 0x180);
    }
    else {
      iVar6 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar6 != 0) {
      piVar18 = (int *)(unaff_RSI + 0x180);
      if (cVar13 != '\0') {
        piVar18 = (int *)(unaff_RSI + 0x178);
      }
      iVar12 = *piVar18;
    }
    *(int *)(unaff_RSI + 0x198) = iVar12;
    uVar21 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar26 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar21 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar12 = *(int *)(unaff_RSI + 0x188);
    iVar7 = *(int *)(unaff_RSI + 0x18c);
    if (iVar12 != 0) goto LAB_140ab5a94;
    if (iVar7 == 0) {
      if ((!bVar2) || (iVar6 != 0)) {
        if (bVar20) {
          bVar19 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar21 = func_0x000141bbb790();
            bVar19 = (bool)(~(byte)(uVar21 >> 0xf) & 1);
          }
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar26 = 0x9b0f4f04;
          if (bVar19 != false) {
            uVar26 = 0xe6e5760f;
          }
          uVar11 = 0xff0dd6e7;
          if (bVar19 != false) {
            uVar11 = 0xd104919c;
          }
          bVar20 = *(char *)(unaff_RSI + 0x281) != '\0';
          if (bVar20) {
            uVar11 = uVar26;
          }
          uVar26 = 0x6eb97095;
          if (bVar20) {
            uVar26 = 0xde7f5039;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
          _DAT_146df261c = 2;
          if (bVar19 == false) {
            uVar21 = 2;
            if (2 < _DAT_146df2630) {
              uVar21 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar21;
            uVar21 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar21 = 2;
            if (2 < _DAT_146df2634) {
              uVar21 = _DAT_146df2634;
            }
          }
        }
        else if (*(char *)(unaff_RBP + 0x70) == '\0') {
          if (bVar19) {
            uVar26 = 0x6eb97095;
            if (cVar13 != '\0') {
              uVar26 = 0xde7f5039;
            }
            uVar11 = 0xbf5cd6b2;
            if (cVar13 != '\0') {
              uVar11 = 0xf9af61e;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
            _DAT_146df261c = 2;
            uVar21 = _DAT_146df2634;
          }
          else {
            uVar26 = 0x6eb97095;
            if (cVar13 != '\0') {
              uVar26 = 0xde7f5039;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
            if (bVar1) {
              uVar26 = 0x99fc5bf5;
              if (cVar13 != '\0') {
                uVar26 = 0x4dbd642a;
              }
            }
            else {
              uVar26 = 0;
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar26;
            uVar26 = 0x26558708;
            if (cVar13 != '\0') {
              uVar26 = 0x9693a7a4;
            }
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar26;
            uVar21 = _DAT_146df2634;
          }
        }
        else {
          uVar26 = 0x6eb97095;
          if (cVar13 != '\0') {
            uVar26 = 0xde7f5039;
          }
          uVar11 = 0xea32cd03;
          if (cVar13 != '\0') {
            uVar11 = 0x8e3054e0;
          }
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
          _DAT_146df261c = 2;
          _DAT_146df2638 = 4;
          _DAT_146df263c = 0;
          uVar21 = _DAT_146df2634;
        }
      }
      else {
        bVar19 = cVar13 != '\0';
        *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
        uVar26 = 0x65efd996;
        if (bVar19) {
          uVar26 = 0xd529f93a;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar26;
        uVar26 = 0x2a58dc40;
        if (bVar19) {
          uVar26 = 0xfe19e39f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
        uVar26 = 0xa2dc00a0;
        if (bVar19) {
          uVar26 = 0x769d3f7f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a4) = uVar26;
        uVar21 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar7;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar21 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar21;
  if ((DAT_146df2611 != '\0') || (uVar8 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar8 = 3;
  }
  uVar26 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar8);
  cVar13 = FUN_140ab3ee0(uVar26,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar13 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar9 = *(longlong *)(unaff_RSI + 8);
  uVar26 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar9 + 0x88) == 0) {
    uVar8 = FUN_14167ab40(lVar9 + 0x58,0x1473d09e0);
  }
  else {
    uVar8 = func_0x0001416799a0(lVar9 + 0x80);
  }
  FUN_1415c2240(uVar8,unaff_RBP + 0x70,uVar26,0);
  lVar9 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar9 != 0) {
    fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0x3bff28c9);
    if (0.0 <= fVar25) {
      *(float *)(unaff_RSI + 0x1c8) = fVar25;
    }
    else {
      fVar25 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar25;
    fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0xa959982c);
    if (fVar25 < 0.0) {
      fVar25 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar25;
    fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0xbe47e933);
    if (fVar25 < 0.0) {
      fVar25 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar25 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar25;
  }
  func_0x0001415c0440(uVar8,*(undefined4 *)(unaff_RBP + 0x70));
  iVar12 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar12 != 0) {
    lVar9 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar9 + 0x88) == 0) {
      uVar8 = FUN_14167ab40(lVar9 + 0x58,0x1473d09e0);
    }
    else {
      uVar8 = func_0x0001416799a0(lVar9 + 0x80);
    }
    FUN_1415c2240(uVar8,unaff_RBP + 0x70,iVar12,0);
    lVar9 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar9 != 0) {
      fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar25;
      if (fVar25 < 0.0) {
        fVar25 = *(float *)(lVar9 + 0x300) * fVar27;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar25;
      fVar27 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar27;
      if ((fVar27 < 0.0) && (fVar27 = *(float *)(lVar9 + 0x300) - _DAT_14382e120, fVar27 <= 0.0)) {
        fVar27 = 0.0;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar27;
      fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0xa959982c);
      fVar27 = *(float *)(unaff_RSI + 0x1d4);
      if ((0.0 <= fVar25) && (fVar25 <= fVar27)) {
        fVar27 = fVar25;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar27;
    }
    func_0x0001415c0440(uVar8,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab4d3c @ 0x140ab4d3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab4d3c(void)

{
  bool bVar1;
  bool bVar2;
  float fVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  longlong in_RAX;
  undefined8 uVar8;
  longlong lVar9;
  float *pfVar10;
  undefined4 uVar11;
  int iVar12;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char cVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined *puVar16;
  bool bVar17;
  int *piVar18;
  bool bVar19;
  bool bVar20;
  uint uVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined4 uVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  undefined4 unaff_XMM12_Da;
  undefined4 unaff_XMM12_Db;
  undefined4 unaff_XMM12_Dc;
  undefined4 unaff_XMM12_Dd;
  undefined4 unaff_XMM13_Da;
  undefined4 unaff_XMM13_Db;
  undefined4 unaff_XMM13_Dc;
  undefined4 unaff_XMM13_Dd;
  char cStack0000000000000041;
  char cStack0000000000000042;
  char cStack0000000000000043;
  char cStack0000000000000044;
  float fStack0000000000000048;
  undefined4 uStack000000000000004c;
  float fStack0000000000000050;
  float fStack0000000000000054;
  int in_stack_00000058;
  int *in_stack_00000060;
  float fStack0000000000000068;
  float fStack000000000000006c;
  float in_stack_00000070;
  float fStack0000000000000078;
  float fStack000000000000007c;
  
  *(undefined4 *)(in_RAX + -0xb8) = unaff_XMM12_Da;
  *(undefined4 *)(in_RAX + -0xb4) = unaff_XMM12_Db;
  *(undefined4 *)(in_RAX + -0xb0) = unaff_XMM12_Dc;
  *(undefined4 *)(in_RAX + -0xac) = unaff_XMM12_Dd;
  *(undefined4 *)(in_RAX + -200) = unaff_XMM13_Da;
  *(undefined4 *)(in_RAX + -0xc4) = unaff_XMM13_Db;
  *(undefined4 *)(in_RAX + -0xc0) = unaff_XMM13_Dc;
  *(undefined4 *)(in_RAX + -0xbc) = unaff_XMM13_Dd;
  FUN_140ab4450();
  in_stack_00000060 = (int *)(unaff_RSI + 0x17c);
  cStack0000000000000044 = *(char *)(unaff_RSI + 0x281);
  iVar12 = *(int *)(unaff_RSI + 0x178);
  if ((((iVar12 == 0) && (*in_stack_00000060 == 0)) || (*(int *)(unaff_RSI + 0x180) != 0)) ||
     (*(int *)(unaff_RSI + 0x184) != 0)) {
    bVar19 = false;
  }
  else {
    bVar19 = true;
  }
  if (((iVar12 == 0) && (*(int *)(unaff_RSI + 0x180) == 0)) ||
     ((*in_stack_00000060 != 0 || (*(int *)(unaff_RSI + 0x184) != 0)))) {
    iVar6 = *in_stack_00000060;
    if (((iVar6 == 0) && (bVar20 = false, *(int *)(unaff_RSI + 0x184) == 0)) ||
       ((bVar20 = false, iVar12 != 0 || (*(int *)(unaff_RSI + 0x180) != 0)))) goto LAB_140ab4dd9;
    bVar17 = true;
LAB_140ab4de1:
    if (*(int *)(unaff_RSI + 0x184) != 0) goto LAB_140ab4dea;
LAB_140ab4e25:
    bVar1 = false;
  }
  else {
    bVar20 = true;
    iVar6 = 0;
LAB_140ab4dd9:
    bVar17 = false;
    if (*(int *)(unaff_RSI + 0x180) == 0) goto LAB_140ab4de1;
LAB_140ab4dea:
    if ((iVar12 != 0) || (iVar6 != 0)) goto LAB_140ab4e25;
    bVar1 = true;
  }
  if ((bVar20) || ((*(float *)(unaff_RBP + 0x70) < _DAT_14384002c && (!bVar17)))) {
    cVar13 = '\x01';
  }
  else {
    cVar13 = '\0';
  }
  *(char *)(unaff_RBP + 0x78) = cVar13;
  if (((cStack0000000000000044 == '\0') && (!bVar19)) || (bVar1)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  lVar9 = *(longlong *)(unaff_RSI + 8);
  *(undefined1 *)(unaff_RSI + 0x281) = uVar4;
  if (*(short *)(lVar9 + 0x88) == 0) {
    uVar8 = FUN_14167ab40(lVar9 + 0x58,0x146dacd70);
  }
  else {
    uVar8 = func_0x0001416799a0(lVar9 + 0x80);
  }
  in_stack_00000058 = func_0x00014085fb90(uVar8);
  bVar19 = in_stack_00000058 == 2;
  cStack0000000000000043 = in_stack_00000058 == 1;
  if ((bVar20) || (cVar13 != '\0')) {
    bVar17 = true;
  }
  else {
    bVar17 = false;
  }
  lVar9 = *(longlong *)(unaff_RSI + 8);
  cStack0000000000000042 = bVar19;
  if (*(short *)(lVar9 + 0x88) == 0) {
    lVar9 = FUN_14167ab40(lVar9 + 0x58,0x146da9d90);
  }
  else {
    lVar9 = func_0x0001416799a0(lVar9 + 0x80);
  }
  fVar27 = _DAT_143848d00;
  if (((lVar9 != 0) && (cVar13 != '\0')) && (!bVar20)) {
    uVar21 = FUN_141f2dd10(*(undefined8 *)(lVar9 + 0x50),0x4453c00,_DAT_143830118);
    bVar17 = fVar27 < (float)(uVar21 & _DAT_14382e160);
  }
  uVar8 = FUN_141676930();
  fVar22 = (float)FUN_140311350(uVar8,unaff_RSI + 0x150);
  uVar21 = func_0x000141bbb790();
  fVar23 = (float)FUN_140ab42f0();
  bVar20 = false;
  *(undefined1 *)(unaff_RBP + 0x70) = 0;
  fVar3 = _DAT_1438ad724;
  fVar25 = _DAT_143840c8c;
  if (((_DAT_14383d254 <= fVar23) || (fVar23 <= _DAT_143834a04)) ||
     (_DAT_1438ce980 < *(float *)(unaff_RSI + 0x218) ||
      _DAT_1438ce980 == *(float *)(unaff_RSI + 0x218))) {
    cVar13 = '\0';
  }
  else {
    cVar13 = '\x01';
  }
  *(char *)(unaff_RBP + 0x88) = cVar13;
  if (((bVar19) || (fVar3 <= fVar23)) ||
     ((fVar23 <= fVar25 ||
      (_DAT_14387e6ac < *(float *)(unaff_RSI + 0x218) ||
       _DAT_14387e6ac == *(float *)(unaff_RSI + 0x218))))) {
    bVar19 = false;
  }
  else {
    bVar19 = true;
  }
  if ((cVar13 == '\0') || ((_DAT_146df2630 != 0 && (_DAT_146df2634 != 0)))) {
    *(undefined1 *)(unaff_RBP + 0x80) = 0;
  }
  else {
    *(undefined1 *)(unaff_RBP + 0x80) = 1;
  }
  if ((bVar19) && (_DAT_146df2638 == 0)) {
    cVar13 = '\x01';
  }
  else {
    cVar13 = '\0';
  }
  if ((_DAT_145d9fe8c < *(float *)(unaff_RSI + 0x148) ||
       _DAT_145d9fe8c == *(float *)(unaff_RSI + 0x148)) || (DAT_145d9fe7f == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  lVar9 = *(longlong *)(unaff_RSI + 8);
  cStack0000000000000041 = cVar13;
  if (*(short *)(lVar9 + 0x88) == 0) {
    lVar9 = FUN_14167ab40(lVar9 + 0x58,0x147c40bf0);
  }
  else {
    lVar9 = func_0x0001416799a0(lVar9 + 0x80);
  }
  if ((!bVar1) || (*(float *)(lVar9 + 0x6b8) <= _DAT_143830120)) {
    bVar1 = false;
    if ((DAT_145d9fe7f != '\0') &&
       (fVar24 = (float)func_0x0001403e3f30(unaff_RSI + 0x214), _DAT_14382f0e4 < fVar24)) {
      fStack0000000000000048 = *(float *)(unaff_RSI + 0x214);
      fStack0000000000000050 = *(float *)(unaff_RSI + 0x21c);
      uStack000000000000004c = 0;
      FUN_1402d0740(&stack0x00000078,&stack0x00000048);
      pfVar10 = (float *)FUN_141676930();
      uStack000000000000004c = 0;
      fStack0000000000000048 = *(float *)(unaff_RSI + 0x168) - *pfVar10;
      fStack0000000000000050 = *(float *)(unaff_RSI + 0x170) - pfVar10[2];
      FUN_1402d0740(&stack0x00000068,&stack0x00000048);
      bVar1 = false;
      if (fStack0000000000000078 * fStack0000000000000068 +
          fStack000000000000007c * fStack000000000000006c +
          *(float *)(unaff_RBP + -0x80) * in_stack_00000070 < _DAT_143837a24) {
        bVar1 = true;
      }
    }
  }
  else {
    bVar1 = true;
  }
  fVar24 = _DAT_14382dce0;
  if ((*(int *)(unaff_RSI + 0x188) != 0) || (*(int *)(unaff_RSI + 0x18c) != 0)) {
    bVar1 = false;
  }
  fVar28 = (*(float *)(unaff_RSI + 0x218) - _DAT_1438acf84) * _DAT_1438ce95c;
  if (fVar28 <= 0.0) {
    fVar28 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar28) {
    fVar28 = _DAT_14382dce0;
  }
  fVar29 = _DAT_1438ac760;
  if ((cStack0000000000000042 == '\0') && (cStack0000000000000043 == '\0')) {
    fVar29 = _DAT_14382dce0;
  }
  fVar29 = (fVar28 + fVar25) * fVar29;
  fVar25 = ((float)_DAT_146df263c - _DAT_14382f0e0) * _DAT_14386dc74;
  if (fVar25 <= 0.0) {
    fVar25 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar25) {
    fVar25 = _DAT_14382dce0;
  }
  fVar25 = (float)FUN_143666da0(fVar25,fVar3);
  cVar5 = *(char *)(unaff_RBP + 0x80);
  fVar25 = fVar25 * _DAT_1438cb4b0 + _DAT_143836d0c;
  if (cVar5 == '\0') {
    fVar29 = 0.0;
  }
  if (cVar13 == '\0') {
    fVar25 = 0.0;
  }
  fVar25 = (fVar29 + fVar24 + fVar25) * (float)(uVar21 >> 8) * _DAT_14382e114;
  if (DAT_146df2614 != '\0') {
    func_0x000141bbb4e0(&UNK_1438ce760);
    func_0x000141bbb4e0(&UNK_1438ce778,(double)fStack0000000000000054);
    func_0x000141bbb4e0(&UNK_1438ce790,(double)fVar22);
    func_0x000141bbb4e0(&UNK_1438ce7a8,(double)*(float *)(unaff_RSI + 0x218));
    func_0x000141bbb4e0(&UNK_1438ce7c0,(double)fVar23);
    func_0x000141bbb4e0(&UNK_1438ce7d8,
                        *(undefined8 *)
                         (*(longlong *)(_DAT_145e11438 + 0x20) + (longlong)in_stack_00000058 * 8));
    puVar14 = &UNK_1438ce7ec;
    func_0x000141bbb4e0(&UNK_1438ce7f8,&UNK_1438ce7f0,&UNK_1438ce7ec,_DAT_143830a28);
    puVar15 = &UNK_1438ce7ec;
    if (_DAT_146df261c != 0) {
      puVar15 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce830,&UNK_1438ce7ec,puVar15,0);
    puVar15 = &UNK_1438ce7ec;
    if (*(char *)(unaff_RBP + 0x88) != '\0') {
      puVar15 = &UNK_1438ce7f0;
    }
    puVar16 = &UNK_1438ce7ec;
    if (_DAT_146df2630 != 0) {
      puVar16 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce868,puVar15,puVar16,(double)fVar29);
    puVar16 = &UNK_1438ce7ec;
    if (_DAT_146df2634 != 0) {
      puVar16 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8a0,puVar15,puVar16,(double)fVar29);
    puVar15 = &UNK_1438ce7ec;
    if (_DAT_146df2638 != 0) {
      puVar15 = &UNK_1438ce7f0;
    }
    if (bVar19) {
      puVar14 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8d8,puVar14,puVar15);
    func_0x000141bbb4e0(&UNK_1438ce910,(double)fVar25);
    cVar5 = *(char *)(unaff_RBP + 0x80);
    cVar13 = cStack0000000000000041;
  }
  if (_DAT_1438aa3f4 <= fVar25) {
    if ((cVar5 == '\0') || (fVar29 + fVar24 <= fVar25)) {
      if (cVar13 != '\0') {
        *(undefined1 *)(unaff_RBP + 0x70) = 1;
        bVar17 = true;
      }
    }
    else {
      bVar20 = true;
      bVar17 = true;
    }
  }
  if ((*(char *)(unaff_RSI + 0x1fd) != '\0') &&
     (cStack0000000000000044 != *(char *)(unaff_RSI + 0x281))) {
    bVar20 = false;
    bVar1 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
  }
  if (_DAT_146df2618 == 1) {
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
LAB_140ab54ac:
    bVar19 = false;
    bVar20 = false;
  }
  else if (_DAT_146df2618 == 2) {
    bVar20 = false;
    bVar19 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
    bVar17 = false;
  }
  else {
    bVar19 = false;
    if (_DAT_146df2618 == 3) {
      bVar20 = true;
      *(undefined1 *)(unaff_RBP + 0x70) = 0;
      bVar17 = true;
    }
    else if (_DAT_146df2618 == 4) {
      *(undefined1 *)(unaff_RBP + 0x70) = 1;
      bVar17 = true;
      goto LAB_140ab54ac;
    }
  }
  if (((cStack0000000000000042 == '\0') || (bVar20)) ||
     ((*(char *)(unaff_RSI + 0x28a) == '\0' && (_DAT_14383d148 <= fVar23)))) {
    cVar13 = *(char *)(unaff_RBP + 0x78);
    bVar2 = false;
  }
  else {
    cVar13 = *(char *)(unaff_RBP + 0x78);
    if (bVar17 == false) {
      if (cVar13 != '\0') {
        uVar21 = func_0x000141bbb790();
        bVar17 = (bool)(~(byte)(uVar21 >> 0xf) & 1);
        if (bVar17 != false) goto LAB_140ab54fd;
      }
    }
    else {
LAB_140ab54fd:
      if (DAT_146df2614 != '\0') {
        func_0x000141bbb4e0(&UNK_1438ce920);
      }
    }
    bVar2 = true;
  }
  if (DAT_146df2616 != '\0') {
    bVar2 = true;
    bVar17 = true;
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(unaff_RSI + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar13 != '\0') && (bVar17 != false)) goto LAB_140ab5619;
    cVar13 = *(char *)(unaff_RSI + 0x281);
    bVar20 = cVar13 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar12 = 0x42991cb0;
    if (!bVar20) {
      iVar12 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar26 = 0x9a5e57b2;
    if (!bVar20) {
      uVar26 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar26;
    uVar26 = 0x734348c3;
    if (!bVar20) {
      uVar26 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar26;
    if (bVar20) {
      iVar6 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar6 = *in_stack_00000060;
    }
    if (iVar6 != 0) {
      if (cVar13 == '\0') {
        iVar12 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar12 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar12;
    uVar21 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar12 = *(int *)(unaff_RSI + 0x188);
    iVar7 = *(int *)(unaff_RSI + 0x18c);
    if (iVar12 == 0) {
      if (iVar7 == 0) {
        if ((!bVar2) || (iVar6 != 0)) {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
          if (bVar19) {
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar21 = _DAT_146df2634;
          }
          else {
            if (bVar1) {
              uVar26 = 0x4db30291;
              if (cVar13 != '\0') {
                uVar26 = 0x99f23d4e;
              }
            }
            else {
              uVar26 = 0;
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar26;
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
            uVar21 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
          *(undefined1 *)(unaff_RSI + 0x211) = 1;
          uVar26 = 0x736ce232;
          if (cVar13 != '\0') {
            uVar26 = 0xc3aac29e;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar26;
          uVar21 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar12;
      if (iVar7 == 0) {
        iVar7 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(unaff_RSI + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        bVar17 = true;
        cVar13 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        bVar17 = false;
        cVar13 = '\0';
      }
    }
    if (*(char *)(unaff_RSI + 0x281) == '\0') {
      if (bVar17 == false) {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        bVar17 = false;
      }
      goto LAB_140ab56c6;
    }
    if (bVar17 != false) {
      if (DAT_145d9fe7a == '\0') {
        bVar17 = false;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar13 = *(char *)(unaff_RSI + 0x281);
    bVar17 = cVar13 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar12 = -0x4ce4b144;
    if (!bVar17) {
      iVar12 = 0x675a7163;
    }
    uVar26 = 0x7bf72b79;
    if (!bVar17) {
      uVar26 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
    uVar26 = 0x2671d34e;
    if (!bVar17) {
      uVar26 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar26;
    uVar26 = 0x7c1d212;
    if (!bVar17) {
      uVar26 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar26;
    uVar26 = 0x797b9614;
    if (!bVar17) {
      uVar26 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar26;
    if (bVar17) {
      iVar6 = *(int *)(unaff_RSI + 0x180);
    }
    else {
      iVar6 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar6 != 0) {
      piVar18 = (int *)(unaff_RSI + 0x180);
      if (cVar13 != '\0') {
        piVar18 = (int *)(unaff_RSI + 0x178);
      }
      iVar12 = *piVar18;
    }
    *(int *)(unaff_RSI + 0x198) = iVar12;
    uVar21 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar26 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar21 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar12 = *(int *)(unaff_RSI + 0x188);
    iVar7 = *(int *)(unaff_RSI + 0x18c);
    if (iVar12 != 0) goto LAB_140ab5a94;
    if (iVar7 == 0) {
      if ((!bVar2) || (iVar6 != 0)) {
        if (bVar20) {
          bVar19 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar21 = func_0x000141bbb790();
            bVar19 = (bool)(~(byte)(uVar21 >> 0xf) & 1);
          }
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar26 = 0x9b0f4f04;
          if (bVar19 != false) {
            uVar26 = 0xe6e5760f;
          }
          uVar11 = 0xff0dd6e7;
          if (bVar19 != false) {
            uVar11 = 0xd104919c;
          }
          bVar20 = *(char *)(unaff_RSI + 0x281) != '\0';
          if (bVar20) {
            uVar11 = uVar26;
          }
          uVar26 = 0x6eb97095;
          if (bVar20) {
            uVar26 = 0xde7f5039;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
          _DAT_146df261c = 2;
          if (bVar19 == false) {
            uVar21 = 2;
            if (2 < _DAT_146df2630) {
              uVar21 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar21;
            uVar21 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar21 = 2;
            if (2 < _DAT_146df2634) {
              uVar21 = _DAT_146df2634;
            }
          }
        }
        else if (*(char *)(unaff_RBP + 0x70) == '\0') {
          if (bVar19) {
            uVar26 = 0x6eb97095;
            if (cVar13 != '\0') {
              uVar26 = 0xde7f5039;
            }
            uVar11 = 0xbf5cd6b2;
            if (cVar13 != '\0') {
              uVar11 = 0xf9af61e;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
            _DAT_146df261c = 2;
            uVar21 = _DAT_146df2634;
          }
          else {
            uVar26 = 0x6eb97095;
            if (cVar13 != '\0') {
              uVar26 = 0xde7f5039;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
            if (bVar1) {
              uVar26 = 0x99fc5bf5;
              if (cVar13 != '\0') {
                uVar26 = 0x4dbd642a;
              }
            }
            else {
              uVar26 = 0;
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar26;
            uVar26 = 0x26558708;
            if (cVar13 != '\0') {
              uVar26 = 0x9693a7a4;
            }
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar26;
            uVar21 = _DAT_146df2634;
          }
        }
        else {
          uVar26 = 0x6eb97095;
          if (cVar13 != '\0') {
            uVar26 = 0xde7f5039;
          }
          uVar11 = 0xea32cd03;
          if (cVar13 != '\0') {
            uVar11 = 0x8e3054e0;
          }
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
          _DAT_146df261c = 2;
          _DAT_146df2638 = 4;
          _DAT_146df263c = 0;
          uVar21 = _DAT_146df2634;
        }
      }
      else {
        bVar19 = cVar13 != '\0';
        *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
        uVar26 = 0x65efd996;
        if (bVar19) {
          uVar26 = 0xd529f93a;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar26;
        uVar26 = 0x2a58dc40;
        if (bVar19) {
          uVar26 = 0xfe19e39f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a0) = uVar26;
        uVar26 = 0xa2dc00a0;
        if (bVar19) {
          uVar26 = 0x769d3f7f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a4) = uVar26;
        uVar21 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar7;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar21 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar21;
  if ((DAT_146df2611 != '\0') || (uVar8 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar8 = 3;
  }
  uVar26 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar8);
  cVar13 = FUN_140ab3ee0(uVar26,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar13 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar9 = *(longlong *)(unaff_RSI + 8);
  uVar26 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar9 + 0x88) == 0) {
    uVar8 = FUN_14167ab40(lVar9 + 0x58,0x1473d09e0);
  }
  else {
    uVar8 = func_0x0001416799a0(lVar9 + 0x80);
  }
  FUN_1415c2240(uVar8,unaff_RBP + 0x70,uVar26,0);
  lVar9 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar9 != 0) {
    fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0x3bff28c9);
    if (0.0 <= fVar25) {
      *(float *)(unaff_RSI + 0x1c8) = fVar25;
    }
    else {
      fVar25 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar25;
    fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0xa959982c);
    if (fVar25 < 0.0) {
      fVar25 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar25;
    fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0xbe47e933);
    if (fVar25 < 0.0) {
      fVar25 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar25 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar25;
  }
  func_0x0001415c0440(uVar8,*(undefined4 *)(unaff_RBP + 0x70));
  iVar12 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar12 != 0) {
    lVar9 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar9 + 0x88) == 0) {
      uVar8 = FUN_14167ab40(lVar9 + 0x58,0x1473d09e0);
    }
    else {
      uVar8 = func_0x0001416799a0(lVar9 + 0x80);
    }
    FUN_1415c2240(uVar8,unaff_RBP + 0x70,iVar12,0);
    lVar9 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar9 != 0) {
      fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar25;
      if (fVar25 < 0.0) {
        fVar25 = *(float *)(lVar9 + 0x300) * fVar27;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar25;
      fVar27 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar27;
      if ((fVar27 < 0.0) && (fVar27 = *(float *)(lVar9 + 0x300) - _DAT_14382e120, fVar27 <= 0.0)) {
        fVar27 = 0.0;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar27;
      fVar25 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar9,0xa959982c);
      fVar27 = *(float *)(unaff_RSI + 0x1d4);
      if ((0.0 <= fVar25) && (fVar25 <= fVar27)) {
        fVar27 = fVar25;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar27;
    }
    func_0x0001415c0440(uVar8,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab4e86 @ 0x140ab4e86 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab4e86(void)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  float fVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  float *pfVar10;
  undefined4 uVar11;
  int iVar12;
  char unaff_BL;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char unaff_DIL;
  char cVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined *puVar16;
  bool bVar17;
  int *unaff_R15;
  bool bVar18;
  bool bVar19;
  uint uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined4 uVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  undefined8 in_stack_00000040;
  float fStack0000000000000048;
  undefined4 uStack000000000000004c;
  float fStack0000000000000050;
  float fStack0000000000000054;
  int in_stack_00000058;
  int *in_stack_00000060;
  float fStack0000000000000068;
  float fStack000000000000006c;
  float in_stack_00000070;
  float fStack0000000000000078;
  float fStack000000000000007c;
  
  in_stack_00000058 = func_0x00014085fb90();
  bVar18 = in_stack_00000058 == 2;
  bVar19 = in_stack_00000058 != 1;
  if ((unaff_BL == '\0') && (unaff_DIL == '\0')) {
    bVar17 = false;
  }
  else {
    bVar17 = true;
  }
  lVar8 = *(longlong *)(unaff_RSI + 8);
  if (*(short *)(lVar8 + 0x88) == 0) {
    lVar8 = FUN_14167ab40(lVar8 + 0x58,0x146da9d90);
  }
  else {
    lVar8 = func_0x0001416799a0(lVar8 + 0x80);
  }
  fVar26 = _DAT_143848d00;
  if (((lVar8 != 0) && (unaff_DIL != '\0')) && (unaff_BL == '\0')) {
    uVar20 = FUN_141f2dd10(*(undefined8 *)(lVar8 + 0x50),0x4453c00,_DAT_143830118);
    bVar17 = fVar26 < (float)(uVar20 & _DAT_14382e160);
  }
  uVar9 = FUN_141676930();
  fVar21 = (float)FUN_140311350(uVar9,unaff_RSI + 0x150);
  uVar20 = func_0x000141bbb790();
  fVar22 = (float)FUN_140ab42f0();
  bVar3 = false;
  *(undefined1 *)(unaff_RBP + 0x70) = 0;
  fVar6 = _DAT_1438ad724;
  fVar24 = _DAT_143840c8c;
  if (((_DAT_14383d254 <= fVar22) || (fVar22 <= _DAT_143834a04)) ||
     (_DAT_1438ce980 < *(float *)(unaff_RSI + 0x218) ||
      _DAT_1438ce980 == *(float *)(unaff_RSI + 0x218))) {
    cVar13 = '\0';
  }
  else {
    cVar13 = '\x01';
  }
  *(char *)(unaff_RBP + 0x88) = cVar13;
  if (((bVar18) || (fVar6 <= fVar22)) ||
     ((fVar22 <= fVar24 ||
      (_DAT_14387e6ac < *(float *)(unaff_RSI + 0x218) ||
       _DAT_14387e6ac == *(float *)(unaff_RSI + 0x218))))) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if ((cVar13 == '\0') || ((_DAT_146df2630 != 0 && (_DAT_146df2634 != 0)))) {
    *(undefined1 *)(unaff_RBP + 0x80) = 0;
  }
  else {
    *(undefined1 *)(unaff_RBP + 0x80) = 1;
  }
  if ((bVar4) && (_DAT_146df2638 == 0)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  if ((_DAT_145d9fe8c < *(float *)(unaff_RSI + 0x148) ||
       _DAT_145d9fe8c == *(float *)(unaff_RSI + 0x148)) || (DAT_145d9fe7f == '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  lVar8 = *(longlong *)(unaff_RSI + 8);
  if (*(short *)(lVar8 + 0x88) == 0) {
    lVar8 = FUN_14167ab40(lVar8 + 0x58,0x147c40bf0);
  }
  else {
    lVar8 = func_0x0001416799a0(lVar8 + 0x80);
  }
  if ((!bVar2) || (*(float *)(lVar8 + 0x6b8) <= _DAT_143830120)) {
    bVar2 = false;
    if ((DAT_145d9fe7f != '\0') &&
       (fVar23 = (float)func_0x0001403e3f30(unaff_RSI + 0x214), _DAT_14382f0e4 < fVar23)) {
      fStack0000000000000048 = *(float *)(unaff_RSI + 0x214);
      fStack0000000000000050 = *(float *)(unaff_RSI + 0x21c);
      uStack000000000000004c = 0;
      FUN_1402d0740(&stack0x00000078,&stack0x00000048);
      pfVar10 = (float *)FUN_141676930();
      uStack000000000000004c = 0;
      fStack0000000000000048 = *(float *)(unaff_RSI + 0x168) - *pfVar10;
      fStack0000000000000050 = *(float *)(unaff_RSI + 0x170) - pfVar10[2];
      FUN_1402d0740(&stack0x00000068,&stack0x00000048);
      bVar2 = false;
      if (fStack0000000000000078 * fStack0000000000000068 +
          fStack000000000000007c * fStack000000000000006c +
          *(float *)(unaff_RBP + -0x80) * in_stack_00000070 < _DAT_143837a24) {
        bVar2 = true;
      }
    }
  }
  else {
    bVar2 = true;
  }
  fVar23 = _DAT_14382dce0;
  if ((*(int *)(unaff_RSI + 0x188) != 0) || (*(int *)(unaff_RSI + 0x18c) != 0)) {
    bVar2 = false;
  }
  fVar27 = (*(float *)(unaff_RSI + 0x218) - _DAT_1438acf84) * _DAT_1438ce95c;
  if (fVar27 <= 0.0) {
    fVar27 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar27) {
    fVar27 = _DAT_14382dce0;
  }
  fVar28 = _DAT_1438ac760;
  if ((!bVar18) && (bVar19)) {
    fVar28 = _DAT_14382dce0;
  }
  fVar28 = (fVar27 + fVar24) * fVar28;
  fVar24 = ((float)_DAT_146df263c - _DAT_14382f0e0) * _DAT_14386dc74;
  if (fVar24 <= 0.0) {
    fVar24 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar24) {
    fVar24 = _DAT_14382dce0;
  }
  fVar24 = (float)FUN_143666da0(fVar24,fVar6);
  cVar13 = *(char *)(unaff_RBP + 0x80);
  fVar24 = fVar24 * _DAT_1438cb4b0 + _DAT_143836d0c;
  if (cVar13 == '\0') {
    fVar28 = 0.0;
  }
  if (!bVar5) {
    fVar24 = 0.0;
  }
  fVar24 = (fVar28 + fVar23 + fVar24) * (float)(uVar20 >> 8) * _DAT_14382e114;
  if (DAT_146df2614 != '\0') {
    func_0x000141bbb4e0(&UNK_1438ce760);
    func_0x000141bbb4e0(&UNK_1438ce778,(double)fStack0000000000000054);
    func_0x000141bbb4e0(&UNK_1438ce790,(double)fVar21);
    func_0x000141bbb4e0(&UNK_1438ce7a8,(double)*(float *)(unaff_RSI + 0x218));
    func_0x000141bbb4e0(&UNK_1438ce7c0,(double)fVar22);
    func_0x000141bbb4e0(&UNK_1438ce7d8,
                        *(undefined8 *)
                         (*(longlong *)(_DAT_145e11438 + 0x20) + (longlong)in_stack_00000058 * 8));
    puVar14 = &UNK_1438ce7ec;
    func_0x000141bbb4e0(&UNK_1438ce7f8,&UNK_1438ce7f0,&UNK_1438ce7ec,_DAT_143830a28);
    puVar15 = &UNK_1438ce7ec;
    if (_DAT_146df261c != 0) {
      puVar15 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce830,&UNK_1438ce7ec,puVar15,0);
    puVar15 = &UNK_1438ce7ec;
    if (*(char *)(unaff_RBP + 0x88) != '\0') {
      puVar15 = &UNK_1438ce7f0;
    }
    puVar16 = &UNK_1438ce7ec;
    if (_DAT_146df2630 != 0) {
      puVar16 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce868,puVar15,puVar16,(double)fVar28);
    puVar16 = &UNK_1438ce7ec;
    if (_DAT_146df2634 != 0) {
      puVar16 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8a0,puVar15,puVar16,(double)fVar28);
    puVar15 = &UNK_1438ce7ec;
    if (_DAT_146df2638 != 0) {
      puVar15 = &UNK_1438ce7f0;
    }
    if (bVar4) {
      puVar14 = &UNK_1438ce7f0;
    }
    func_0x000141bbb4e0(&UNK_1438ce8d8,puVar14,puVar15);
    func_0x000141bbb4e0(&UNK_1438ce910,(double)fVar24);
    cVar13 = *(char *)(unaff_RBP + 0x80);
  }
  if (_DAT_1438aa3f4 <= fVar24) {
    if ((cVar13 == '\0') || (fVar28 + fVar23 <= fVar24)) {
      if (bVar5) {
        *(undefined1 *)(unaff_RBP + 0x70) = 1;
        bVar17 = true;
      }
    }
    else {
      bVar3 = true;
      bVar17 = true;
    }
  }
  if ((*(char *)(unaff_RSI + 0x1fd) != '\0') &&
     (in_stack_00000040._4_1_ != *(char *)(unaff_RSI + 0x281))) {
    bVar3 = false;
    bVar2 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
  }
  if (_DAT_146df2618 == 1) {
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
LAB_140ab54ac:
    bVar19 = false;
    bVar3 = false;
  }
  else if (_DAT_146df2618 == 2) {
    bVar3 = false;
    bVar19 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
    bVar17 = false;
  }
  else {
    bVar19 = false;
    if (_DAT_146df2618 == 3) {
      bVar3 = true;
      *(undefined1 *)(unaff_RBP + 0x70) = 0;
      bVar17 = true;
    }
    else if (_DAT_146df2618 == 4) {
      *(undefined1 *)(unaff_RBP + 0x70) = 1;
      bVar17 = true;
      goto LAB_140ab54ac;
    }
  }
  if (((!bVar18) || (bVar3)) ||
     ((*(char *)(unaff_RSI + 0x28a) == '\0' && (_DAT_14383d148 <= fVar22)))) {
    cVar13 = *(char *)(unaff_RBP + 0x78);
    bVar18 = false;
  }
  else {
    cVar13 = *(char *)(unaff_RBP + 0x78);
    if (bVar17 == false) {
      if (cVar13 != '\0') {
        uVar20 = func_0x000141bbb790();
        bVar17 = (bool)(~(byte)(uVar20 >> 0xf) & 1);
        if (bVar17 != false) goto LAB_140ab54fd;
      }
    }
    else {
LAB_140ab54fd:
      if (DAT_146df2614 != '\0') {
        func_0x000141bbb4e0(&UNK_1438ce920);
      }
    }
    bVar18 = true;
  }
  if (DAT_146df2616 != '\0') {
    bVar18 = true;
    bVar17 = true;
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(unaff_RSI + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar13 != '\0') && (bVar17 != false)) goto LAB_140ab5619;
    cVar13 = *(char *)(unaff_RSI + 0x281);
    bVar17 = cVar13 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar12 = 0x42991cb0;
    if (!bVar17) {
      iVar12 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar25 = 0x9a5e57b2;
    if (!bVar17) {
      uVar25 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar25;
    uVar25 = 0x734348c3;
    if (!bVar17) {
      uVar25 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar25;
    if (bVar17) {
      iVar1 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar1 = *in_stack_00000060;
    }
    if (iVar1 != 0) {
      if (cVar13 == '\0') {
        iVar12 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar12 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar12;
    uVar20 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar12 = *(int *)(unaff_RSI + 0x188);
    iVar7 = *(int *)(unaff_RSI + 0x18c);
    if (iVar12 == 0) {
      if (iVar7 == 0) {
        if ((!bVar18) || (iVar1 != 0)) {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
          if (bVar19) {
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar20 = _DAT_146df2634;
          }
          else {
            if (bVar2) {
              uVar25 = 0x4db30291;
              if (cVar13 != '\0') {
                uVar25 = 0x99f23d4e;
              }
            }
            else {
              uVar25 = 0;
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar25;
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
            uVar20 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
          *(undefined1 *)(unaff_RSI + 0x211) = 1;
          uVar25 = 0x736ce232;
          if (cVar13 != '\0') {
            uVar25 = 0xc3aac29e;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar25;
          uVar20 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar12;
      if (iVar7 == 0) {
        iVar7 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(unaff_RSI + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        bVar17 = true;
        cVar13 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        bVar17 = false;
        cVar13 = '\0';
      }
    }
    if (*(char *)(unaff_RSI + 0x281) == '\0') {
      if (bVar17 == false) {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        bVar17 = false;
      }
      goto LAB_140ab56c6;
    }
    if (bVar17 != false) {
      if (DAT_145d9fe7a == '\0') {
        bVar17 = false;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar13 = *(char *)(unaff_RSI + 0x281);
    bVar17 = cVar13 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar12 = -0x4ce4b144;
    if (!bVar17) {
      iVar12 = 0x675a7163;
    }
    uVar25 = 0x7bf72b79;
    if (!bVar17) {
      uVar25 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar25;
    uVar25 = 0x2671d34e;
    if (!bVar17) {
      uVar25 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar25;
    uVar25 = 0x7c1d212;
    if (!bVar17) {
      uVar25 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar25;
    uVar25 = 0x797b9614;
    if (!bVar17) {
      uVar25 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar25;
    if (bVar17) {
      iVar1 = *unaff_R15;
    }
    else {
      iVar1 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar1 != 0) {
      if (cVar13 != '\0') {
        unaff_R15 = (int *)(unaff_RSI + 0x178);
      }
      iVar12 = *unaff_R15;
    }
    *(int *)(unaff_RSI + 0x198) = iVar12;
    uVar20 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar25 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar25;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar20 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar12 = *(int *)(unaff_RSI + 0x188);
    iVar7 = *(int *)(unaff_RSI + 0x18c);
    if (iVar12 != 0) goto LAB_140ab5a94;
    if (iVar7 == 0) {
      if ((!bVar18) || (iVar1 != 0)) {
        if (bVar3) {
          bVar18 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar20 = func_0x000141bbb790();
            bVar18 = (bool)(~(byte)(uVar20 >> 0xf) & 1);
          }
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar25 = 0x9b0f4f04;
          if (bVar18 != false) {
            uVar25 = 0xe6e5760f;
          }
          uVar11 = 0xff0dd6e7;
          if (bVar18 != false) {
            uVar11 = 0xd104919c;
          }
          bVar19 = *(char *)(unaff_RSI + 0x281) != '\0';
          if (bVar19) {
            uVar11 = uVar25;
          }
          uVar25 = 0x6eb97095;
          if (bVar19) {
            uVar25 = 0xde7f5039;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar25;
          _DAT_146df261c = 2;
          if (bVar18 == false) {
            uVar20 = 2;
            if (2 < _DAT_146df2630) {
              uVar20 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar20;
            uVar20 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar20 = 2;
            if (2 < _DAT_146df2634) {
              uVar20 = _DAT_146df2634;
            }
          }
        }
        else if (*(char *)(unaff_RBP + 0x70) == '\0') {
          if (bVar19) {
            uVar25 = 0x6eb97095;
            if (cVar13 != '\0') {
              uVar25 = 0xde7f5039;
            }
            uVar11 = 0xbf5cd6b2;
            if (cVar13 != '\0') {
              uVar11 = 0xf9af61e;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar25;
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
            _DAT_146df261c = 2;
            uVar20 = _DAT_146df2634;
          }
          else {
            uVar25 = 0x6eb97095;
            if (cVar13 != '\0') {
              uVar25 = 0xde7f5039;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar25;
            if (bVar2) {
              uVar25 = 0x99fc5bf5;
              if (cVar13 != '\0') {
                uVar25 = 0x4dbd642a;
              }
            }
            else {
              uVar25 = 0;
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar25;
            uVar25 = 0x26558708;
            if (cVar13 != '\0') {
              uVar25 = 0x9693a7a4;
            }
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar25;
            uVar20 = _DAT_146df2634;
          }
        }
        else {
          uVar25 = 0x6eb97095;
          if (cVar13 != '\0') {
            uVar25 = 0xde7f5039;
          }
          uVar11 = 0xea32cd03;
          if (cVar13 != '\0') {
            uVar11 = 0x8e3054e0;
          }
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar25;
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
          _DAT_146df261c = 2;
          _DAT_146df2638 = 4;
          _DAT_146df263c = 0;
          uVar20 = _DAT_146df2634;
        }
      }
      else {
        bVar18 = cVar13 != '\0';
        *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
        uVar25 = 0x65efd996;
        if (bVar18) {
          uVar25 = 0xd529f93a;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar25;
        uVar25 = 0x2a58dc40;
        if (bVar18) {
          uVar25 = 0xfe19e39f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a0) = uVar25;
        uVar25 = 0xa2dc00a0;
        if (bVar18) {
          uVar25 = 0x769d3f7f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a4) = uVar25;
        uVar20 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar7;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar20 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar20;
  if ((DAT_146df2611 != '\0') || (uVar9 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar9 = 3;
  }
  uVar25 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar9);
  cVar13 = FUN_140ab3ee0(uVar25,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar13 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar8 = *(longlong *)(unaff_RSI + 8);
  uVar25 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar8 + 0x88) == 0) {
    uVar9 = FUN_14167ab40(lVar8 + 0x58,0x1473d09e0);
  }
  else {
    uVar9 = func_0x0001416799a0(lVar8 + 0x80);
  }
  FUN_1415c2240(uVar9,unaff_RBP + 0x70,uVar25,0);
  lVar8 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar8 != 0) {
    fVar24 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar8,0x3bff28c9);
    if (0.0 <= fVar24) {
      *(float *)(unaff_RSI + 0x1c8) = fVar24;
    }
    else {
      fVar24 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar24;
    fVar24 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar8,0xa959982c);
    if (fVar24 < 0.0) {
      fVar24 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar24;
    fVar24 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar8,0xbe47e933);
    if (fVar24 < 0.0) {
      fVar24 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar24 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar24;
  }
  func_0x0001415c0440(uVar9,*(undefined4 *)(unaff_RBP + 0x70));
  iVar12 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar12 != 0) {
    lVar8 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar8 + 0x88) == 0) {
      uVar9 = FUN_14167ab40(lVar8 + 0x58,0x1473d09e0);
    }
    else {
      uVar9 = func_0x0001416799a0(lVar8 + 0x80);
    }
    FUN_1415c2240(uVar9,unaff_RBP + 0x70,iVar12,0);
    lVar8 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar8 != 0) {
      fVar24 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar8,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar24;
      if (fVar24 < 0.0) {
        fVar24 = *(float *)(lVar8 + 0x300) * fVar26;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar24;
      fVar26 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar8,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar26;
      if ((fVar26 < 0.0) && (fVar26 = *(float *)(lVar8 + 0x300) - _DAT_14382e120, fVar26 <= 0.0)) {
        fVar26 = 0.0;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar26;
      fVar24 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar8,0xa959982c);
      fVar26 = *(float *)(unaff_RSI + 0x1d4);
      if ((0.0 <= fVar24) && (fVar24 <= fVar26)) {
        fVar26 = fVar24;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar26;
    }
    func_0x0001415c0440(uVar9,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab524c @ 0x140ab524c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab524c(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 uVar6;
  int iVar7;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char cVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  char unaff_R12B;
  char unaff_R13B;
  byte unaff_R14B;
  int *unaff_R15;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  undefined4 uVar15;
  float fVar16;
  float fVar17;
  float unaff_XMM6_Da;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  float unaff_XMM13_Da;
  float unaff_XMM14_Da;
  char cStack0000000000000040;
  char cStack0000000000000041;
  char cStack0000000000000042;
  char cStack0000000000000044;
  undefined8 in_stack_00000050;
  int in_stack_00000058;
  int *in_stack_00000060;
  
  func_0x000141bbb4e0(&UNK_1438ce760);
  func_0x000141bbb4e0(&UNK_1438ce778,(double)in_stack_00000050._4_4_);
  func_0x000141bbb4e0(&UNK_1438ce790,(double)unaff_XMM13_Da);
  func_0x000141bbb4e0(&UNK_1438ce7a8,(double)*(float *)(unaff_RSI + 0x218));
  func_0x000141bbb4e0(&UNK_1438ce7c0,(double)unaff_XMM11_Da);
  func_0x000141bbb4e0(&UNK_1438ce7d8,
                      *(undefined8 *)
                       (*(longlong *)(_DAT_145e11438 + 0x20) + (longlong)in_stack_00000058 * 8));
  puVar9 = &UNK_1438ce7ec;
  func_0x000141bbb4e0(&UNK_1438ce7f8,&UNK_1438ce7f0,&UNK_1438ce7ec,_DAT_143830a28);
  puVar10 = &UNK_1438ce7ec;
  if (_DAT_146df261c != 0) {
    puVar10 = &UNK_1438ce7f0;
  }
  func_0x000141bbb4e0(&UNK_1438ce830,&UNK_1438ce7ec,puVar10,0);
  puVar10 = &UNK_1438ce7ec;
  if (*(char *)(unaff_RBP + 0x88) != unaff_R13B) {
    puVar10 = &UNK_1438ce7f0;
  }
  puVar11 = &UNK_1438ce7ec;
  if (_DAT_146df2630 != 0) {
    puVar11 = &UNK_1438ce7f0;
  }
  func_0x000141bbb4e0(&UNK_1438ce868,puVar10,puVar11,(double)unaff_XMM6_Da);
  puVar11 = &UNK_1438ce7ec;
  if (_DAT_146df2634 != 0) {
    puVar11 = &UNK_1438ce7f0;
  }
  func_0x000141bbb4e0(&UNK_1438ce8a0,puVar10,puVar11,(double)unaff_XMM6_Da);
  puVar10 = &UNK_1438ce7ec;
  if (_DAT_146df2638 != 0) {
    puVar10 = &UNK_1438ce7f0;
  }
  if (cStack0000000000000040 != unaff_R13B) {
    puVar9 = &UNK_1438ce7f0;
  }
  func_0x000141bbb4e0(&UNK_1438ce8d8,puVar9,puVar10);
  func_0x000141bbb4e0(&UNK_1438ce910,(double)unaff_XMM7_Da);
  if (_DAT_1438aa3f4 <= unaff_XMM7_Da) {
    if ((*(char *)(unaff_RBP + 0x80) == '\0') || (unaff_XMM10_Da <= unaff_XMM7_Da)) {
      if (cStack0000000000000041 != '\0') {
        *(undefined1 *)(unaff_RBP + 0x70) = 1;
        unaff_R14B = 1;
      }
    }
    else {
      unaff_R13B = '\x01';
      unaff_R14B = 1;
    }
  }
  if ((*(char *)(unaff_RSI + 0x1fd) != '\0') &&
     (cStack0000000000000044 != *(char *)(unaff_RSI + 0x281))) {
    unaff_R13B = '\0';
    unaff_R12B = '\x01';
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
  }
  if (_DAT_146df2618 == 1) {
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
LAB_140ab54ac:
    bVar13 = false;
    unaff_R13B = '\0';
  }
  else if (_DAT_146df2618 == 2) {
    unaff_R13B = '\0';
    bVar13 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
    unaff_R14B = 0;
  }
  else {
    bVar13 = false;
    if (_DAT_146df2618 == 3) {
      unaff_R13B = '\x01';
      *(undefined1 *)(unaff_RBP + 0x70) = 0;
      unaff_R14B = 1;
    }
    else if (_DAT_146df2618 == 4) {
      *(undefined1 *)(unaff_RBP + 0x70) = 1;
      unaff_R14B = 1;
      goto LAB_140ab54ac;
    }
  }
  if (((cStack0000000000000042 == '\0') || (unaff_R13B != '\0')) ||
     ((*(char *)(unaff_RSI + 0x28a) == '\0' && (_DAT_14383d148 <= unaff_XMM11_Da)))) {
    cVar8 = *(char *)(unaff_RBP + 0x78);
    bVar14 = false;
  }
  else {
    cVar8 = *(char *)(unaff_RBP + 0x78);
    if (unaff_R14B == 0) {
      if (cVar8 != '\0') {
        uVar2 = func_0x000141bbb790();
        unaff_R14B = ~(byte)(uVar2 >> 0xf) & 1;
        if (unaff_R14B != 0) goto LAB_140ab54fd;
      }
    }
    else {
LAB_140ab54fd:
      if (DAT_146df2614 != '\0') {
        func_0x000141bbb4e0(&UNK_1438ce920);
      }
    }
    bVar14 = true;
  }
  if (DAT_146df2616 != '\0') {
    bVar14 = true;
    unaff_R14B = 1;
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(unaff_RSI + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar8 != '\0') && (unaff_R14B != 0)) goto LAB_140ab5619;
    cVar8 = *(char *)(unaff_RSI + 0x281);
    bVar12 = cVar8 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar7 = 0x42991cb0;
    if (!bVar12) {
      iVar7 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar15 = 0x9a5e57b2;
    if (!bVar12) {
      uVar15 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar15;
    uVar15 = 0x734348c3;
    if (!bVar12) {
      uVar15 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar15;
    if (bVar12) {
      iVar1 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar1 = *in_stack_00000060;
    }
    if (iVar1 != 0) {
      if (cVar8 == '\0') {
        iVar7 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar7 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar7;
    uVar2 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar7 = *(int *)(unaff_RSI + 0x188);
    iVar3 = *(int *)(unaff_RSI + 0x18c);
    if (iVar7 == 0) {
      if (iVar3 == 0) {
        if ((!bVar14) || (iVar1 != 0)) {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
          if (bVar13) {
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar2 = _DAT_146df2634;
          }
          else {
            if (unaff_R12B == '\0') {
              uVar15 = 0;
            }
            else {
              uVar15 = 0x4db30291;
              if (cVar8 != '\0') {
                uVar15 = 0x99f23d4e;
              }
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar15;
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
            uVar2 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
          *(undefined1 *)(unaff_RSI + 0x211) = 1;
          uVar15 = 0x736ce232;
          if (cVar8 != '\0') {
            uVar15 = 0xc3aac29e;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar15;
          uVar2 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar7;
      if (iVar3 == 0) {
        iVar3 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(unaff_RSI + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        unaff_R14B = 1;
        cVar8 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        unaff_R14B = 0;
        cVar8 = '\0';
      }
    }
    if (*(char *)(unaff_RSI + 0x281) == '\0') {
      if (unaff_R14B == 0) {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        unaff_R14B = 0;
      }
      goto LAB_140ab56c6;
    }
    if (unaff_R14B != 0) {
      if (DAT_145d9fe7a == '\0') {
        unaff_R14B = 0;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar8 = *(char *)(unaff_RSI + 0x281);
    bVar12 = cVar8 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar7 = -0x4ce4b144;
    if (!bVar12) {
      iVar7 = 0x675a7163;
    }
    uVar15 = 0x7bf72b79;
    if (!bVar12) {
      uVar15 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar15;
    uVar15 = 0x2671d34e;
    if (!bVar12) {
      uVar15 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar15;
    uVar15 = 0x7c1d212;
    if (!bVar12) {
      uVar15 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar15;
    uVar15 = 0x797b9614;
    if (!bVar12) {
      uVar15 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar15;
    if (bVar12) {
      iVar1 = *unaff_R15;
    }
    else {
      iVar1 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar1 != 0) {
      if (cVar8 != '\0') {
        unaff_R15 = (int *)(unaff_RSI + 0x178);
      }
      iVar7 = *unaff_R15;
    }
    *(int *)(unaff_RSI + 0x198) = iVar7;
    uVar2 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar15 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar15;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar2 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar7 = *(int *)(unaff_RSI + 0x188);
    iVar3 = *(int *)(unaff_RSI + 0x18c);
    if (iVar7 != 0) goto LAB_140ab5a94;
    if (iVar3 == 0) {
      if ((!bVar14) || (iVar1 != 0)) {
        if (unaff_R13B == '\0') {
          if (*(char *)(unaff_RBP + 0x70) == '\0') {
            if (bVar13) {
              uVar15 = 0x6eb97095;
              if (cVar8 != '\0') {
                uVar15 = 0xde7f5039;
              }
              uVar6 = 0xbf5cd6b2;
              if (cVar8 != '\0') {
                uVar6 = 0xf9af61e;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar15;
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
              _DAT_146df261c = 2;
              uVar2 = _DAT_146df2634;
            }
            else {
              uVar15 = 0x6eb97095;
              if (cVar8 != '\0') {
                uVar15 = 0xde7f5039;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar15;
              if (unaff_R12B == '\0') {
                uVar15 = 0;
              }
              else {
                uVar15 = 0x99fc5bf5;
                if (cVar8 != '\0') {
                  uVar15 = 0x4dbd642a;
                }
              }
              *(undefined4 *)(unaff_RSI + 0x19c) = uVar15;
              uVar15 = 0x26558708;
              if (cVar8 != '\0') {
                uVar15 = 0x9693a7a4;
              }
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar15;
              uVar2 = _DAT_146df2634;
            }
          }
          else {
            uVar15 = 0x6eb97095;
            if (cVar8 != '\0') {
              uVar15 = 0xde7f5039;
            }
            uVar6 = 0xea32cd03;
            if (cVar8 != '\0') {
              uVar6 = 0x8e3054e0;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar15;
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
            _DAT_146df261c = 2;
            _DAT_146df2638 = 4;
            _DAT_146df263c = 0;
            uVar2 = _DAT_146df2634;
          }
        }
        else {
          bVar13 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar2 = func_0x000141bbb790();
            bVar13 = (bool)(~(byte)(uVar2 >> 0xf) & 1);
          }
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar15 = 0x9b0f4f04;
          if (bVar13 != false) {
            uVar15 = 0xe6e5760f;
          }
          uVar6 = 0xff0dd6e7;
          if (bVar13 != false) {
            uVar6 = 0xd104919c;
          }
          bVar14 = *(char *)(unaff_RSI + 0x281) != '\0';
          if (bVar14) {
            uVar6 = uVar15;
          }
          uVar15 = 0x6eb97095;
          if (bVar14) {
            uVar15 = 0xde7f5039;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar15;
          _DAT_146df261c = 2;
          if (bVar13 == false) {
            uVar2 = 2;
            if (2 < _DAT_146df2630) {
              uVar2 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar2;
            uVar2 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar2 = 2;
            if (2 < _DAT_146df2634) {
              uVar2 = _DAT_146df2634;
            }
          }
        }
      }
      else {
        bVar13 = cVar8 != '\0';
        *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
        uVar15 = 0x65efd996;
        if (bVar13) {
          uVar15 = 0xd529f93a;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar15;
        uVar15 = 0x2a58dc40;
        if (bVar13) {
          uVar15 = 0xfe19e39f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a0) = uVar15;
        uVar15 = 0xa2dc00a0;
        if (bVar13) {
          uVar15 = 0x769d3f7f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a4) = uVar15;
        uVar2 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar3;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar2 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar2;
  if ((DAT_146df2611 != '\0') || (uVar4 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar4 = 3;
  }
  uVar15 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar4);
  cVar8 = FUN_140ab3ee0(uVar15,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar8 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar5 = *(longlong *)(unaff_RSI + 8);
  uVar15 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar4 = func_0x0001416799a0(lVar5 + 0x80);
  }
  FUN_1415c2240(uVar4,unaff_RBP + 0x70,uVar15,0);
  lVar5 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar5 != 0) {
    fVar16 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x3bff28c9);
    if (unaff_XMM8_Da <= fVar16) {
      *(float *)(unaff_RSI + 0x1c8) = fVar16;
    }
    else {
      fVar16 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar16;
    fVar16 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xa959982c);
    if (fVar16 < unaff_XMM8_Da) {
      fVar16 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar16;
    fVar16 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xbe47e933);
    if (fVar16 < unaff_XMM8_Da) {
      fVar16 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar16 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar16;
  }
  func_0x0001415c0440(uVar4,*(undefined4 *)(unaff_RBP + 0x70));
  iVar7 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar7 != 0) {
    lVar5 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
    }
    else {
      uVar4 = func_0x0001416799a0(lVar5 + 0x80);
    }
    FUN_1415c2240(uVar4,unaff_RBP + 0x70,iVar7,0);
    lVar5 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar5 != 0) {
      fVar16 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar16;
      if (fVar16 < unaff_XMM8_Da) {
        fVar16 = *(float *)(lVar5 + 0x300) * unaff_XMM14_Da;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar16;
      fVar16 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar16;
      if ((fVar16 < unaff_XMM8_Da) &&
         (fVar16 = *(float *)(lVar5 + 0x300) - _DAT_14382e120, fVar16 <= unaff_XMM8_Da)) {
        fVar16 = unaff_XMM8_Da;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar16;
      fVar17 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xa959982c);
      fVar16 = *(float *)(unaff_RSI + 0x1d4);
      if ((unaff_XMM8_Da <= fVar17) && (fVar17 <= fVar16)) {
        fVar16 = fVar17;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar16;
    }
    func_0x0001415c0440(uVar4,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab5418 @ 0x140ab5418 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab5418(void)

{
  int iVar1;
  char in_AL;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 uVar6;
  int iVar7;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char unaff_DIL;
  char cVar8;
  char unaff_R12B;
  char unaff_R13B;
  byte unaff_R14B;
  int *unaff_R15;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  undefined4 uVar12;
  float fVar13;
  float fVar14;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  float unaff_XMM14_Da;
  undefined8 in_stack_00000040;
  int *in_stack_00000060;
  
  if ((in_AL == '\0') || (unaff_XMM10_Da <= unaff_XMM7_Da)) {
    if (unaff_DIL != '\0') {
      *(undefined1 *)(unaff_RBP + 0x70) = 1;
      unaff_R14B = 1;
    }
  }
  else {
    unaff_R13B = '\x01';
    unaff_R14B = 1;
  }
  if ((*(char *)(unaff_RSI + 0x1fd) != '\0') &&
     (in_stack_00000040._4_1_ != *(char *)(unaff_RSI + 0x281))) {
    unaff_R13B = '\0';
    unaff_R12B = '\x01';
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
  }
  if (_DAT_146df2618 == 1) {
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
LAB_140ab54ac:
    bVar10 = false;
    unaff_R13B = '\0';
  }
  else if (_DAT_146df2618 == 2) {
    unaff_R13B = '\0';
    bVar10 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
    unaff_R14B = 0;
  }
  else {
    bVar10 = false;
    if (_DAT_146df2618 == 3) {
      unaff_R13B = '\x01';
      *(undefined1 *)(unaff_RBP + 0x70) = 0;
      unaff_R14B = 1;
    }
    else if (_DAT_146df2618 == 4) {
      *(undefined1 *)(unaff_RBP + 0x70) = 1;
      unaff_R14B = 1;
      goto LAB_140ab54ac;
    }
  }
  if (((in_stack_00000040._2_1_ == '\0') || (unaff_R13B != '\0')) ||
     ((*(char *)(unaff_RSI + 0x28a) == '\0' && (_DAT_14383d148 <= unaff_XMM11_Da)))) {
    cVar8 = *(char *)(unaff_RBP + 0x78);
    bVar11 = false;
  }
  else {
    cVar8 = *(char *)(unaff_RBP + 0x78);
    if (unaff_R14B == 0) {
      if (cVar8 != '\0') {
        uVar2 = func_0x000141bbb790();
        unaff_R14B = ~(byte)(uVar2 >> 0xf) & 1;
        if (unaff_R14B != 0) goto LAB_140ab54fd;
      }
    }
    else {
LAB_140ab54fd:
      if (DAT_146df2614 != '\0') {
        func_0x000141bbb4e0(&UNK_1438ce920);
      }
    }
    bVar11 = true;
  }
  if (DAT_146df2616 != '\0') {
    bVar11 = true;
    unaff_R14B = 1;
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(unaff_RSI + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar8 != '\0') && (unaff_R14B != 0)) goto LAB_140ab5619;
    cVar8 = *(char *)(unaff_RSI + 0x281);
    bVar9 = cVar8 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar7 = 0x42991cb0;
    if (!bVar9) {
      iVar7 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar12 = 0x9a5e57b2;
    if (!bVar9) {
      uVar12 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar12;
    uVar12 = 0x734348c3;
    if (!bVar9) {
      uVar12 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar12;
    if (bVar9) {
      iVar1 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar1 = *in_stack_00000060;
    }
    if (iVar1 != 0) {
      if (cVar8 == '\0') {
        iVar7 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar7 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar7;
    uVar2 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar7 = *(int *)(unaff_RSI + 0x188);
    iVar3 = *(int *)(unaff_RSI + 0x18c);
    if (iVar7 == 0) {
      if (iVar3 == 0) {
        if ((!bVar11) || (iVar1 != 0)) {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
          if (bVar10) {
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar2 = _DAT_146df2634;
          }
          else {
            if (unaff_R12B == '\0') {
              uVar12 = 0;
            }
            else {
              uVar12 = 0x4db30291;
              if (cVar8 != '\0') {
                uVar12 = 0x99f23d4e;
              }
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar12;
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
            uVar2 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
          *(undefined1 *)(unaff_RSI + 0x211) = 1;
          uVar12 = 0x736ce232;
          if (cVar8 != '\0') {
            uVar12 = 0xc3aac29e;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar12;
          uVar2 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar7;
      if (iVar3 == 0) {
        iVar3 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(unaff_RSI + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        unaff_R14B = 1;
        cVar8 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        unaff_R14B = 0;
        cVar8 = '\0';
      }
    }
    if (*(char *)(unaff_RSI + 0x281) == '\0') {
      if (unaff_R14B == 0) {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        unaff_R14B = 0;
      }
      goto LAB_140ab56c6;
    }
    if (unaff_R14B != 0) {
      if (DAT_145d9fe7a == '\0') {
        unaff_R14B = 0;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar8 = *(char *)(unaff_RSI + 0x281);
    bVar9 = cVar8 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar7 = -0x4ce4b144;
    if (!bVar9) {
      iVar7 = 0x675a7163;
    }
    uVar12 = 0x7bf72b79;
    if (!bVar9) {
      uVar12 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
    uVar12 = 0x2671d34e;
    if (!bVar9) {
      uVar12 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar12;
    uVar12 = 0x7c1d212;
    if (!bVar9) {
      uVar12 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar12;
    uVar12 = 0x797b9614;
    if (!bVar9) {
      uVar12 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar12;
    if (bVar9) {
      iVar1 = *unaff_R15;
    }
    else {
      iVar1 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar1 != 0) {
      if (cVar8 != '\0') {
        unaff_R15 = (int *)(unaff_RSI + 0x178);
      }
      iVar7 = *unaff_R15;
    }
    *(int *)(unaff_RSI + 0x198) = iVar7;
    uVar2 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar12 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar2 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar7 = *(int *)(unaff_RSI + 0x188);
    iVar3 = *(int *)(unaff_RSI + 0x18c);
    if (iVar7 != 0) goto LAB_140ab5a94;
    if (iVar3 == 0) {
      if ((!bVar11) || (iVar1 != 0)) {
        if (unaff_R13B == '\0') {
          if (*(char *)(unaff_RBP + 0x70) == '\0') {
            if (bVar10) {
              uVar12 = 0x6eb97095;
              if (cVar8 != '\0') {
                uVar12 = 0xde7f5039;
              }
              uVar6 = 0xbf5cd6b2;
              if (cVar8 != '\0') {
                uVar6 = 0xf9af61e;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
              _DAT_146df261c = 2;
              uVar2 = _DAT_146df2634;
            }
            else {
              uVar12 = 0x6eb97095;
              if (cVar8 != '\0') {
                uVar12 = 0xde7f5039;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
              if (unaff_R12B == '\0') {
                uVar12 = 0;
              }
              else {
                uVar12 = 0x99fc5bf5;
                if (cVar8 != '\0') {
                  uVar12 = 0x4dbd642a;
                }
              }
              *(undefined4 *)(unaff_RSI + 0x19c) = uVar12;
              uVar12 = 0x26558708;
              if (cVar8 != '\0') {
                uVar12 = 0x9693a7a4;
              }
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar12;
              uVar2 = _DAT_146df2634;
            }
          }
          else {
            uVar12 = 0x6eb97095;
            if (cVar8 != '\0') {
              uVar12 = 0xde7f5039;
            }
            uVar6 = 0xea32cd03;
            if (cVar8 != '\0') {
              uVar6 = 0x8e3054e0;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
            _DAT_146df261c = 2;
            _DAT_146df2638 = 4;
            _DAT_146df263c = 0;
            uVar2 = _DAT_146df2634;
          }
        }
        else {
          bVar10 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar2 = func_0x000141bbb790();
            bVar10 = (bool)(~(byte)(uVar2 >> 0xf) & 1);
          }
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar12 = 0x9b0f4f04;
          if (bVar10 != false) {
            uVar12 = 0xe6e5760f;
          }
          uVar6 = 0xff0dd6e7;
          if (bVar10 != false) {
            uVar6 = 0xd104919c;
          }
          bVar11 = *(char *)(unaff_RSI + 0x281) != '\0';
          if (bVar11) {
            uVar6 = uVar12;
          }
          uVar12 = 0x6eb97095;
          if (bVar11) {
            uVar12 = 0xde7f5039;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
          _DAT_146df261c = 2;
          if (bVar10 == false) {
            uVar2 = 2;
            if (2 < _DAT_146df2630) {
              uVar2 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar2;
            uVar2 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar2 = 2;
            if (2 < _DAT_146df2634) {
              uVar2 = _DAT_146df2634;
            }
          }
        }
      }
      else {
        bVar10 = cVar8 != '\0';
        *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
        uVar12 = 0x65efd996;
        if (bVar10) {
          uVar12 = 0xd529f93a;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar12;
        uVar12 = 0x2a58dc40;
        if (bVar10) {
          uVar12 = 0xfe19e39f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
        uVar12 = 0xa2dc00a0;
        if (bVar10) {
          uVar12 = 0x769d3f7f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a4) = uVar12;
        uVar2 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar3;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar2 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar2;
  if ((DAT_146df2611 != '\0') || (uVar4 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar4 = 3;
  }
  uVar12 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar4);
  cVar8 = FUN_140ab3ee0(uVar12,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar8 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar5 = *(longlong *)(unaff_RSI + 8);
  uVar12 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar4 = func_0x0001416799a0(lVar5 + 0x80);
  }
  FUN_1415c2240(uVar4,unaff_RBP + 0x70,uVar12,0);
  lVar5 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar5 != 0) {
    fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x3bff28c9);
    if (unaff_XMM8_Da <= fVar13) {
      *(float *)(unaff_RSI + 0x1c8) = fVar13;
    }
    else {
      fVar13 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar13;
    fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xa959982c);
    if (fVar13 < unaff_XMM8_Da) {
      fVar13 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar13;
    fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xbe47e933);
    if (fVar13 < unaff_XMM8_Da) {
      fVar13 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar13 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar13;
  }
  func_0x0001415c0440(uVar4,*(undefined4 *)(unaff_RBP + 0x70));
  iVar7 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar7 != 0) {
    lVar5 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
    }
    else {
      uVar4 = func_0x0001416799a0(lVar5 + 0x80);
    }
    FUN_1415c2240(uVar4,unaff_RBP + 0x70,iVar7,0);
    lVar5 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar5 != 0) {
      fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar13;
      if (fVar13 < unaff_XMM8_Da) {
        fVar13 = *(float *)(lVar5 + 0x300) * unaff_XMM14_Da;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar13;
      fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar13;
      if ((fVar13 < unaff_XMM8_Da) &&
         (fVar13 = *(float *)(lVar5 + 0x300) - _DAT_14382e120, fVar13 <= unaff_XMM8_Da)) {
        fVar13 = unaff_XMM8_Da;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar13;
      fVar14 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xa959982c);
      fVar13 = *(float *)(unaff_RSI + 0x1d4);
      if ((unaff_XMM8_Da <= fVar14) && (fVar14 <= fVar13)) {
        fVar13 = fVar14;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar13;
    }
    func_0x0001415c0440(uVar4,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab5451 @ 0x140ab5451 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab5451(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 uVar6;
  int iVar7;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char cVar8;
  char unaff_R12B;
  char unaff_R13B;
  byte unaff_R14B;
  int *unaff_R15;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  undefined4 uVar12;
  float fVar13;
  float fVar14;
  float unaff_XMM8_Da;
  float unaff_XMM11_Da;
  float unaff_XMM14_Da;
  undefined8 in_stack_00000040;
  int *in_stack_00000060;
  
  if (in_stack_00000040._4_1_ != *(char *)(unaff_RSI + 0x281)) {
    unaff_R13B = '\0';
    unaff_R12B = '\x01';
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
  }
  if (_DAT_146df2618 == 1) {
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
LAB_140ab54ac:
    bVar10 = false;
    unaff_R13B = '\0';
  }
  else if (_DAT_146df2618 == 2) {
    unaff_R13B = '\0';
    bVar10 = true;
    *(undefined1 *)(unaff_RBP + 0x70) = 0;
    unaff_R14B = 0;
  }
  else {
    bVar10 = false;
    if (_DAT_146df2618 == 3) {
      unaff_R13B = '\x01';
      *(undefined1 *)(unaff_RBP + 0x70) = 0;
      unaff_R14B = 1;
    }
    else if (_DAT_146df2618 == 4) {
      *(undefined1 *)(unaff_RBP + 0x70) = 1;
      unaff_R14B = 1;
      goto LAB_140ab54ac;
    }
  }
  if (((in_stack_00000040._2_1_ == '\0') || (unaff_R13B != '\0')) ||
     ((*(char *)(unaff_RSI + 0x28a) == '\0' && (_DAT_14383d148 <= unaff_XMM11_Da)))) {
    cVar8 = *(char *)(unaff_RBP + 0x78);
    bVar11 = false;
  }
  else {
    cVar8 = *(char *)(unaff_RBP + 0x78);
    if (unaff_R14B == 0) {
      if (cVar8 != '\0') {
        uVar2 = func_0x000141bbb790();
        unaff_R14B = ~(byte)(uVar2 >> 0xf) & 1;
        if (unaff_R14B != 0) goto LAB_140ab54fd;
      }
    }
    else {
LAB_140ab54fd:
      if (DAT_146df2614 != '\0') {
        func_0x000141bbb4e0(&UNK_1438ce920);
      }
    }
    bVar11 = true;
  }
  if (DAT_146df2616 != '\0') {
    bVar11 = true;
    unaff_R14B = 1;
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(unaff_RSI + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar8 != '\0') && (unaff_R14B != 0)) goto LAB_140ab5619;
    cVar8 = *(char *)(unaff_RSI + 0x281);
    bVar9 = cVar8 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar7 = 0x42991cb0;
    if (!bVar9) {
      iVar7 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar12 = 0x9a5e57b2;
    if (!bVar9) {
      uVar12 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar12;
    uVar12 = 0x734348c3;
    if (!bVar9) {
      uVar12 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar12;
    if (bVar9) {
      iVar1 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar1 = *in_stack_00000060;
    }
    if (iVar1 != 0) {
      if (cVar8 == '\0') {
        iVar7 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar7 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar7;
    uVar2 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar7 = *(int *)(unaff_RSI + 0x188);
    iVar3 = *(int *)(unaff_RSI + 0x18c);
    if (iVar7 == 0) {
      if (iVar3 == 0) {
        if ((!bVar11) || (iVar1 != 0)) {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
          if (bVar10) {
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar2 = _DAT_146df2634;
          }
          else {
            if (unaff_R12B == '\0') {
              uVar12 = 0;
            }
            else {
              uVar12 = 0x4db30291;
              if (cVar8 != '\0') {
                uVar12 = 0x99f23d4e;
              }
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar12;
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
            uVar2 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
          *(undefined1 *)(unaff_RSI + 0x211) = 1;
          uVar12 = 0x736ce232;
          if (cVar8 != '\0') {
            uVar12 = 0xc3aac29e;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar12;
          uVar2 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar7;
      if (iVar3 == 0) {
        iVar3 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(unaff_RSI + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        unaff_R14B = 1;
        cVar8 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        unaff_R14B = 0;
        cVar8 = '\0';
      }
    }
    if (*(char *)(unaff_RSI + 0x281) == '\0') {
      if (unaff_R14B == 0) {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        unaff_R14B = 0;
      }
      goto LAB_140ab56c6;
    }
    if (unaff_R14B != 0) {
      if (DAT_145d9fe7a == '\0') {
        unaff_R14B = 0;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar8 = *(char *)(unaff_RSI + 0x281);
    bVar9 = cVar8 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar7 = -0x4ce4b144;
    if (!bVar9) {
      iVar7 = 0x675a7163;
    }
    uVar12 = 0x7bf72b79;
    if (!bVar9) {
      uVar12 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
    uVar12 = 0x2671d34e;
    if (!bVar9) {
      uVar12 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar12;
    uVar12 = 0x7c1d212;
    if (!bVar9) {
      uVar12 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar12;
    uVar12 = 0x797b9614;
    if (!bVar9) {
      uVar12 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar12;
    if (bVar9) {
      iVar1 = *unaff_R15;
    }
    else {
      iVar1 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar1 != 0) {
      if (cVar8 != '\0') {
        unaff_R15 = (int *)(unaff_RSI + 0x178);
      }
      iVar7 = *unaff_R15;
    }
    *(int *)(unaff_RSI + 0x198) = iVar7;
    uVar2 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar12 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar2 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar7 = *(int *)(unaff_RSI + 0x188);
    iVar3 = *(int *)(unaff_RSI + 0x18c);
    if (iVar7 != 0) goto LAB_140ab5a94;
    if (iVar3 == 0) {
      if ((!bVar11) || (iVar1 != 0)) {
        if (unaff_R13B == '\0') {
          if (*(char *)(unaff_RBP + 0x70) == '\0') {
            if (bVar10) {
              uVar12 = 0x6eb97095;
              if (cVar8 != '\0') {
                uVar12 = 0xde7f5039;
              }
              uVar6 = 0xbf5cd6b2;
              if (cVar8 != '\0') {
                uVar6 = 0xf9af61e;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
              _DAT_146df261c = 2;
              uVar2 = _DAT_146df2634;
            }
            else {
              uVar12 = 0x6eb97095;
              if (cVar8 != '\0') {
                uVar12 = 0xde7f5039;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
              if (unaff_R12B == '\0') {
                uVar12 = 0;
              }
              else {
                uVar12 = 0x99fc5bf5;
                if (cVar8 != '\0') {
                  uVar12 = 0x4dbd642a;
                }
              }
              *(undefined4 *)(unaff_RSI + 0x19c) = uVar12;
              uVar12 = 0x26558708;
              if (cVar8 != '\0') {
                uVar12 = 0x9693a7a4;
              }
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar12;
              uVar2 = _DAT_146df2634;
            }
          }
          else {
            uVar12 = 0x6eb97095;
            if (cVar8 != '\0') {
              uVar12 = 0xde7f5039;
            }
            uVar6 = 0xea32cd03;
            if (cVar8 != '\0') {
              uVar6 = 0x8e3054e0;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
            _DAT_146df261c = 2;
            _DAT_146df2638 = 4;
            _DAT_146df263c = 0;
            uVar2 = _DAT_146df2634;
          }
        }
        else {
          bVar10 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar2 = func_0x000141bbb790();
            bVar10 = (bool)(~(byte)(uVar2 >> 0xf) & 1);
          }
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar12 = 0x9b0f4f04;
          if (bVar10 != false) {
            uVar12 = 0xe6e5760f;
          }
          uVar6 = 0xff0dd6e7;
          if (bVar10 != false) {
            uVar6 = 0xd104919c;
          }
          bVar11 = *(char *)(unaff_RSI + 0x281) != '\0';
          if (bVar11) {
            uVar6 = uVar12;
          }
          uVar12 = 0x6eb97095;
          if (bVar11) {
            uVar12 = 0xde7f5039;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
          _DAT_146df261c = 2;
          if (bVar10 == false) {
            uVar2 = 2;
            if (2 < _DAT_146df2630) {
              uVar2 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar2;
            uVar2 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar2 = 2;
            if (2 < _DAT_146df2634) {
              uVar2 = _DAT_146df2634;
            }
          }
        }
      }
      else {
        bVar10 = cVar8 != '\0';
        *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
        uVar12 = 0x65efd996;
        if (bVar10) {
          uVar12 = 0xd529f93a;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar12;
        uVar12 = 0x2a58dc40;
        if (bVar10) {
          uVar12 = 0xfe19e39f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a0) = uVar12;
        uVar12 = 0xa2dc00a0;
        if (bVar10) {
          uVar12 = 0x769d3f7f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a4) = uVar12;
        uVar2 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar3;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar2 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar2;
  if ((DAT_146df2611 != '\0') || (uVar4 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar4 = 3;
  }
  uVar12 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar4);
  cVar8 = FUN_140ab3ee0(uVar12,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar8 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar5 = *(longlong *)(unaff_RSI + 8);
  uVar12 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar4 = func_0x0001416799a0(lVar5 + 0x80);
  }
  FUN_1415c2240(uVar4,unaff_RBP + 0x70,uVar12,0);
  lVar5 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar5 != 0) {
    fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x3bff28c9);
    if (unaff_XMM8_Da <= fVar13) {
      *(float *)(unaff_RSI + 0x1c8) = fVar13;
    }
    else {
      fVar13 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar13;
    fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xa959982c);
    if (fVar13 < unaff_XMM8_Da) {
      fVar13 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar13;
    fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xbe47e933);
    if (fVar13 < unaff_XMM8_Da) {
      fVar13 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar13 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar13;
  }
  func_0x0001415c0440(uVar4,*(undefined4 *)(unaff_RBP + 0x70));
  iVar7 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar7 != 0) {
    lVar5 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
    }
    else {
      uVar4 = func_0x0001416799a0(lVar5 + 0x80);
    }
    FUN_1415c2240(uVar4,unaff_RBP + 0x70,iVar7,0);
    lVar5 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar5 != 0) {
      fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar13;
      if (fVar13 < unaff_XMM8_Da) {
        fVar13 = *(float *)(lVar5 + 0x300) * unaff_XMM14_Da;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar13;
      fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar13;
      if ((fVar13 < unaff_XMM8_Da) &&
         (fVar13 = *(float *)(lVar5 + 0x300) - _DAT_14382e120, fVar13 <= unaff_XMM8_Da)) {
        fVar13 = unaff_XMM8_Da;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar13;
      fVar14 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xa959982c);
      fVar13 = *(float *)(unaff_RSI + 0x1d4);
      if ((unaff_XMM8_Da <= fVar14) && (fVar14 <= fVar13)) {
        fVar13 = fVar14;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar13;
    }
    func_0x0001415c0440(uVar4,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab5527 @ 0x140ab5527 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab5527(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  int iVar8;
  char unaff_BL;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char unaff_DIL;
  char unaff_R12B;
  char unaff_R13B;
  int *unaff_R15;
  bool bVar9;
  bool bVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float unaff_XMM8_Da;
  float unaff_XMM14_Da;
  int *in_stack_00000060;
  
  bVar9 = true;
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(unaff_RSI + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((unaff_DIL != '\0') && (bVar9)) goto LAB_140ab5619;
    cVar2 = *(char *)(unaff_RSI + 0x281);
    bVar9 = cVar2 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar8 = 0x42991cb0;
    if (!bVar9) {
      iVar8 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar11 = 0x9a5e57b2;
    if (!bVar9) {
      uVar11 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar11;
    uVar11 = 0x734348c3;
    if (!bVar9) {
      uVar11 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar11;
    if (bVar9) {
      iVar1 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar1 = *in_stack_00000060;
    }
    if (iVar1 != 0) {
      if (cVar2 == '\0') {
        iVar8 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar8 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar8;
    uVar3 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar8 = *(int *)(unaff_RSI + 0x188);
    iVar4 = *(int *)(unaff_RSI + 0x18c);
    if (iVar8 == 0) {
      if (iVar4 == 0) {
        if (iVar1 != 0) {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
          if (unaff_BL == '\0') {
            if (unaff_R12B == '\0') {
              uVar11 = 0;
            }
            else {
              uVar11 = 0x4db30291;
              if (cVar2 != '\0') {
                uVar11 = 0x99f23d4e;
              }
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar11;
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
            uVar3 = _DAT_146df2634;
          }
          else {
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar3 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
          *(undefined1 *)(unaff_RSI + 0x211) = 1;
          uVar11 = 0x736ce232;
          if (cVar2 != '\0') {
            uVar11 = 0xc3aac29e;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar11;
          uVar3 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar8;
      if (iVar4 == 0) {
        iVar4 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(unaff_RSI + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        bVar9 = true;
        unaff_DIL = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        bVar9 = false;
        unaff_DIL = '\0';
      }
    }
    if (*(char *)(unaff_RSI + 0x281) == '\0') {
      if (bVar9) {
        if (DAT_145d9fe78 == '\0') {
          bVar9 = false;
        }
      }
      else if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      goto LAB_140ab56c6;
    }
    if (bVar9) {
      if (DAT_145d9fe7a == '\0') {
        bVar9 = false;
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar2 = *(char *)(unaff_RSI + 0x281);
    bVar9 = cVar2 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar8 = -0x4ce4b144;
    if (!bVar9) {
      iVar8 = 0x675a7163;
    }
    uVar11 = 0x7bf72b79;
    if (!bVar9) {
      uVar11 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
    uVar11 = 0x2671d34e;
    if (!bVar9) {
      uVar11 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar11;
    uVar11 = 0x7c1d212;
    if (!bVar9) {
      uVar11 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar11;
    uVar11 = 0x797b9614;
    if (!bVar9) {
      uVar11 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar11;
    if (bVar9) {
      iVar1 = *unaff_R15;
    }
    else {
      iVar1 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar1 != 0) {
      if (cVar2 != '\0') {
        unaff_R15 = (int *)(unaff_RSI + 0x178);
      }
      iVar8 = *unaff_R15;
    }
    *(int *)(unaff_RSI + 0x198) = iVar8;
    uVar3 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar11 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar3 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar8 = *(int *)(unaff_RSI + 0x188);
    iVar4 = *(int *)(unaff_RSI + 0x18c);
    if (iVar8 != 0) goto LAB_140ab5a94;
    if (iVar4 == 0) {
      if (iVar1 != 0) {
        if (unaff_R13B == '\0') {
          if (*(char *)(unaff_RBP + 0x70) == '\0') {
            if (unaff_BL == '\0') {
              uVar11 = 0x6eb97095;
              if (cVar2 != '\0') {
                uVar11 = 0xde7f5039;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
              if (unaff_R12B == '\0') {
                uVar11 = 0;
              }
              else {
                uVar11 = 0x99fc5bf5;
                if (cVar2 != '\0') {
                  uVar11 = 0x4dbd642a;
                }
              }
              *(undefined4 *)(unaff_RSI + 0x19c) = uVar11;
              uVar11 = 0x26558708;
              if (cVar2 != '\0') {
                uVar11 = 0x9693a7a4;
              }
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
              uVar3 = _DAT_146df2634;
            }
            else {
              uVar11 = 0x6eb97095;
              if (cVar2 != '\0') {
                uVar11 = 0xde7f5039;
              }
              uVar7 = 0xbf5cd6b2;
              if (cVar2 != '\0') {
                uVar7 = 0xf9af61e;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar7;
              _DAT_146df261c = 2;
              uVar3 = _DAT_146df2634;
            }
          }
          else {
            uVar11 = 0x6eb97095;
            if (cVar2 != '\0') {
              uVar11 = 0xde7f5039;
            }
            uVar7 = 0xea32cd03;
            if (cVar2 != '\0') {
              uVar7 = 0x8e3054e0;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar7;
            _DAT_146df261c = 2;
            _DAT_146df2638 = 4;
            _DAT_146df263c = 0;
            uVar3 = _DAT_146df2634;
          }
        }
        else {
          bVar9 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar3 = func_0x000141bbb790();
            bVar9 = (bool)(~(byte)(uVar3 >> 0xf) & 1);
          }
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar11 = 0x9b0f4f04;
          if (bVar9 != false) {
            uVar11 = 0xe6e5760f;
          }
          uVar7 = 0xff0dd6e7;
          if (bVar9 != false) {
            uVar7 = 0xd104919c;
          }
          bVar10 = *(char *)(unaff_RSI + 0x281) != '\0';
          if (bVar10) {
            uVar7 = uVar11;
          }
          uVar11 = 0x6eb97095;
          if (bVar10) {
            uVar11 = 0xde7f5039;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar7;
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
          _DAT_146df261c = 2;
          if (bVar9 == false) {
            uVar3 = 2;
            if (2 < _DAT_146df2630) {
              uVar3 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar3;
            uVar3 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar3 = 2;
            if (2 < _DAT_146df2634) {
              uVar3 = _DAT_146df2634;
            }
          }
        }
      }
      else {
        bVar9 = cVar2 != '\0';
        *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
        uVar11 = 0x65efd996;
        if (bVar9) {
          uVar11 = 0xd529f93a;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar11;
        uVar11 = 0x2a58dc40;
        if (bVar9) {
          uVar11 = 0xfe19e39f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
        uVar11 = 0xa2dc00a0;
        if (bVar9) {
          uVar11 = 0x769d3f7f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
        uVar3 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar4;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar3 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar3;
  if ((DAT_146df2611 != '\0') || (uVar5 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar5 = 3;
  }
  uVar11 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar5);
  cVar2 = FUN_140ab3ee0(uVar11,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar2 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar6 = *(longlong *)(unaff_RSI + 8);
  uVar11 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar6 + 0x88) == 0) {
    uVar5 = FUN_14167ab40(lVar6 + 0x58,0x1473d09e0);
  }
  else {
    uVar5 = func_0x0001416799a0(lVar6 + 0x80);
  }
  FUN_1415c2240(uVar5,unaff_RBP + 0x70,uVar11,0);
  lVar6 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar6 != 0) {
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0x3bff28c9);
    if (unaff_XMM8_Da <= fVar12) {
      *(float *)(unaff_RSI + 0x1c8) = fVar12;
    }
    else {
      fVar12 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar12;
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0xa959982c);
    if (fVar12 < unaff_XMM8_Da) {
      fVar12 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar12;
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0xbe47e933);
    if (fVar12 < unaff_XMM8_Da) {
      fVar12 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar12 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar12;
  }
  func_0x0001415c0440(uVar5,*(undefined4 *)(unaff_RBP + 0x70));
  iVar8 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar8 != 0) {
    lVar6 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar6 + 0x88) == 0) {
      uVar5 = FUN_14167ab40(lVar6 + 0x58,0x1473d09e0);
    }
    else {
      uVar5 = func_0x0001416799a0(lVar6 + 0x80);
    }
    FUN_1415c2240(uVar5,unaff_RBP + 0x70,iVar8,0);
    lVar6 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar6 != 0) {
      fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar12;
      if (fVar12 < unaff_XMM8_Da) {
        fVar12 = *(float *)(lVar6 + 0x300) * unaff_XMM14_Da;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar12;
      fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar12;
      if ((fVar12 < unaff_XMM8_Da) &&
         (fVar12 = *(float *)(lVar6 + 0x300) - _DAT_14382e120, fVar12 <= unaff_XMM8_Da)) {
        fVar12 = unaff_XMM8_Da;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar12;
      fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0xa959982c);
      fVar12 = *(float *)(unaff_RSI + 0x1d4);
      if ((unaff_XMM8_Da <= fVar13) && (fVar13 <= fVar12)) {
        fVar12 = fVar13;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar12;
    }
    func_0x0001415c0440(uVar5,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab555a @ 0x140ab555a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab555a(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 uVar6;
  int iVar7;
  char unaff_BL;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char cVar8;
  char unaff_R12B;
  char unaff_R13B;
  char unaff_R14B;
  int *unaff_R15;
  bool bVar9;
  bool bVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float unaff_XMM8_Da;
  float unaff_XMM14_Da;
  int *in_stack_00000060;
  
  cVar8 = *(char *)(unaff_RBP + 0x78);
  bVar9 = DAT_146df2616 != '\0';
  if (bVar9) {
    unaff_R14B = '\x01';
  }
  if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe7b == '\0')) {
    if ((DAT_145d9fe78 != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab559a:
      *(undefined1 *)(unaff_RSI + 0x281) = 0;
      if (DAT_145d9fe7a == '\0') goto LAB_140ab55ba;
      goto LAB_140ab55cc;
    }
LAB_140ab56c6:
    if ((cVar8 != '\0') && (unaff_R14B != '\0')) goto LAB_140ab5619;
    cVar8 = *(char *)(unaff_RSI + 0x281);
    bVar10 = cVar8 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar7 = 0x42991cb0;
    if (!bVar10) {
      iVar7 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar11 = 0x9a5e57b2;
    if (!bVar10) {
      uVar11 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar11;
    uVar11 = 0x734348c3;
    if (!bVar10) {
      uVar11 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar11;
    if (bVar10) {
      iVar1 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar1 = *in_stack_00000060;
    }
    if (iVar1 != 0) {
      if (cVar8 == '\0') {
        iVar7 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar7 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar7;
    uVar2 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar7 = *(int *)(unaff_RSI + 0x188);
    iVar3 = *(int *)(unaff_RSI + 0x18c);
    if (iVar7 == 0) {
      if (iVar3 == 0) {
        if ((!bVar9) || (iVar1 != 0)) {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
          if (unaff_BL == '\0') {
            if (unaff_R12B == '\0') {
              uVar11 = 0;
            }
            else {
              uVar11 = 0x4db30291;
              if (cVar8 != '\0') {
                uVar11 = 0x99f23d4e;
              }
            }
            *(undefined4 *)(unaff_RSI + 0x19c) = uVar11;
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
            uVar2 = _DAT_146df2634;
          }
          else {
            *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
            _DAT_146df261c = 2;
            uVar2 = _DAT_146df2634;
          }
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
          *(undefined1 *)(unaff_RSI + 0x211) = 1;
          uVar11 = 0x736ce232;
          if (cVar8 != '\0') {
            uVar11 = 0xc3aac29e;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar11;
          uVar2 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar7;
      if (iVar3 == 0) {
        iVar3 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  else {
    if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
      *(undefined1 *)(unaff_RSI + 0x281) = 1;
    }
    if (DAT_145d9fe7a == '\0') {
      if (DAT_145d9fe7b == '\0') goto LAB_140ab559a;
LAB_140ab55ba:
      if (DAT_145d9fe78 != '\0') goto LAB_140ab55cc;
      if ((DAT_145d9fe7b != '\0') || (DAT_145d9fe79 != '\0')) goto LAB_140ab55e9;
    }
    else {
LAB_140ab55cc:
      if ((DAT_145d9fe7b == '\0') && (DAT_145d9fe79 == '\0')) {
        unaff_R14B = '\x01';
        cVar8 = '\x01';
      }
      else if ((DAT_145d9fe7a == '\0') && (DAT_145d9fe78 == '\0')) {
LAB_140ab55e9:
        unaff_R14B = '\0';
        cVar8 = '\0';
      }
    }
    if (*(char *)(unaff_RSI + 0x281) == '\0') {
      if (unaff_R14B == '\0') {
        if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
      }
      else if (DAT_145d9fe78 == '\0') {
        unaff_R14B = '\0';
      }
      goto LAB_140ab56c6;
    }
    if (unaff_R14B != '\0') {
      if (DAT_145d9fe7a == '\0') {
        unaff_R14B = '\0';
      }
      goto LAB_140ab56c6;
    }
    if (DAT_145d9fe7b != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar8 = *(char *)(unaff_RSI + 0x281);
    bVar10 = cVar8 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar7 = -0x4ce4b144;
    if (!bVar10) {
      iVar7 = 0x675a7163;
    }
    uVar11 = 0x7bf72b79;
    if (!bVar10) {
      uVar11 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
    uVar11 = 0x2671d34e;
    if (!bVar10) {
      uVar11 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar11;
    uVar11 = 0x7c1d212;
    if (!bVar10) {
      uVar11 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar11;
    uVar11 = 0x797b9614;
    if (!bVar10) {
      uVar11 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar11;
    if (bVar10) {
      iVar1 = *unaff_R15;
    }
    else {
      iVar1 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar1 != 0) {
      if (cVar8 != '\0') {
        unaff_R15 = (int *)(unaff_RSI + 0x178);
      }
      iVar7 = *unaff_R15;
    }
    *(int *)(unaff_RSI + 0x198) = iVar7;
    uVar2 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar11 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar2 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar7 = *(int *)(unaff_RSI + 0x188);
    iVar3 = *(int *)(unaff_RSI + 0x18c);
    if (iVar7 != 0) goto LAB_140ab5a94;
    if (iVar3 == 0) {
      if ((!bVar9) || (iVar1 != 0)) {
        if (unaff_R13B == '\0') {
          if (*(char *)(unaff_RBP + 0x70) == '\0') {
            if (unaff_BL == '\0') {
              uVar11 = 0x6eb97095;
              if (cVar8 != '\0') {
                uVar11 = 0xde7f5039;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
              if (unaff_R12B == '\0') {
                uVar11 = 0;
              }
              else {
                uVar11 = 0x99fc5bf5;
                if (cVar8 != '\0') {
                  uVar11 = 0x4dbd642a;
                }
              }
              *(undefined4 *)(unaff_RSI + 0x19c) = uVar11;
              uVar11 = 0x26558708;
              if (cVar8 != '\0') {
                uVar11 = 0x9693a7a4;
              }
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
              uVar2 = _DAT_146df2634;
            }
            else {
              uVar11 = 0x6eb97095;
              if (cVar8 != '\0') {
                uVar11 = 0xde7f5039;
              }
              uVar6 = 0xbf5cd6b2;
              if (cVar8 != '\0') {
                uVar6 = 0xf9af61e;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
              _DAT_146df261c = 2;
              uVar2 = _DAT_146df2634;
            }
          }
          else {
            uVar11 = 0x6eb97095;
            if (cVar8 != '\0') {
              uVar11 = 0xde7f5039;
            }
            uVar6 = 0xea32cd03;
            if (cVar8 != '\0') {
              uVar6 = 0x8e3054e0;
            }
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
            _DAT_146df261c = 2;
            _DAT_146df2638 = 4;
            _DAT_146df263c = 0;
            uVar2 = _DAT_146df2634;
          }
        }
        else {
          bVar9 = _DAT_146df2630 == 0;
          if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
            uVar2 = func_0x000141bbb790();
            bVar9 = (bool)(~(byte)(uVar2 >> 0xf) & 1);
          }
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar11 = 0x9b0f4f04;
          if (bVar9 != false) {
            uVar11 = 0xe6e5760f;
          }
          uVar6 = 0xff0dd6e7;
          if (bVar9 != false) {
            uVar6 = 0xd104919c;
          }
          bVar10 = *(char *)(unaff_RSI + 0x281) != '\0';
          if (bVar10) {
            uVar6 = uVar11;
          }
          uVar11 = 0x6eb97095;
          if (bVar10) {
            uVar11 = 0xde7f5039;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar6;
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
          _DAT_146df261c = 2;
          if (bVar9 == false) {
            uVar2 = 2;
            if (2 < _DAT_146df2630) {
              uVar2 = _DAT_146df2630;
            }
            _DAT_146df2634 = 6;
            _DAT_146df2630 = uVar2;
            uVar2 = _DAT_146df2634;
          }
          else {
            _DAT_146df2630 = 3;
            uVar2 = 2;
            if (2 < _DAT_146df2634) {
              uVar2 = _DAT_146df2634;
            }
          }
        }
      }
      else {
        bVar9 = cVar8 != '\0';
        *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
        uVar11 = 0x65efd996;
        if (bVar9) {
          uVar11 = 0xd529f93a;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar11;
        uVar11 = 0x2a58dc40;
        if (bVar9) {
          uVar11 = 0xfe19e39f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
        uVar11 = 0xa2dc00a0;
        if (bVar9) {
          uVar11 = 0x769d3f7f;
        }
        *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
        uVar2 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar3;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar2 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar2;
  if ((DAT_146df2611 != '\0') || (uVar4 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar4 = 3;
  }
  uVar11 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar4);
  cVar8 = FUN_140ab3ee0(uVar11,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar8 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar5 = *(longlong *)(unaff_RSI + 8);
  uVar11 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar4 = func_0x0001416799a0(lVar5 + 0x80);
  }
  FUN_1415c2240(uVar4,unaff_RBP + 0x70,uVar11,0);
  lVar5 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar5 != 0) {
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x3bff28c9);
    if (unaff_XMM8_Da <= fVar12) {
      *(float *)(unaff_RSI + 0x1c8) = fVar12;
    }
    else {
      fVar12 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar12;
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xa959982c);
    if (fVar12 < unaff_XMM8_Da) {
      fVar12 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar12;
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xbe47e933);
    if (fVar12 < unaff_XMM8_Da) {
      fVar12 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar12 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar12;
  }
  func_0x0001415c0440(uVar4,*(undefined4 *)(unaff_RBP + 0x70));
  iVar7 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar7 != 0) {
    lVar5 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      uVar4 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
    }
    else {
      uVar4 = func_0x0001416799a0(lVar5 + 0x80);
    }
    FUN_1415c2240(uVar4,unaff_RBP + 0x70,iVar7,0);
    lVar5 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar5 != 0) {
      fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar12;
      if (fVar12 < unaff_XMM8_Da) {
        fVar12 = *(float *)(lVar5 + 0x300) * unaff_XMM14_Da;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar12;
      fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar12;
      if ((fVar12 < unaff_XMM8_Da) &&
         (fVar12 = *(float *)(lVar5 + 0x300) - _DAT_14382e120, fVar12 <= unaff_XMM8_Da)) {
        fVar12 = unaff_XMM8_Da;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar12;
      fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar5,0xa959982c);
      fVar12 = *(float *)(unaff_RSI + 0x1d4);
      if ((unaff_XMM8_Da <= fVar13) && (fVar13 <= fVar12)) {
        fVar12 = fVar13;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar12;
    }
    func_0x0001415c0440(uVar4,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab5563 @ 0x140ab5563 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab5563(undefined8 param_1,char param_2,undefined8 param_3,char param_4)

{
  int iVar1;
  char in_AL;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  int iVar8;
  char unaff_BL;
  longlong unaff_RBP;
  longlong unaff_RSI;
  char unaff_DIL;
  char unaff_R12B;
  char unaff_R13B;
  char unaff_R14B;
  int *unaff_R15;
  bool bVar9;
  bool bVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float unaff_XMM8_Da;
  float unaff_XMM14_Da;
  int *in_stack_00000060;
  
  if ((DAT_145d9fe78 == '\0') && (DAT_145d9fe79 == '\0')) {
    *(undefined1 *)(unaff_RSI + 0x281) = 1;
    param_2 = DAT_145d9fe7a;
    in_AL = DAT_145d9fe7b;
  }
  if ((param_2 == '\0') &&
     (((in_AL != '\0' ||
       (*(undefined1 *)(unaff_RSI + 0x281) = 0, param_2 = DAT_145d9fe7a, in_AL = DAT_145d9fe7b,
       DAT_145d9fe7a == '\0')) && (DAT_145d9fe78 == '\0')))) {
    if ((in_AL != '\0') || (DAT_145d9fe79 != '\0')) {
LAB_140ab55e9:
      unaff_R14B = '\0';
      unaff_DIL = '\0';
    }
  }
  else if ((in_AL == '\0') && (DAT_145d9fe79 == '\0')) {
    unaff_R14B = '\x01';
    unaff_DIL = '\x01';
  }
  else if ((param_2 == '\0') && (DAT_145d9fe78 == '\0')) goto LAB_140ab55e9;
  if (*(char *)(unaff_RSI + 0x281) == '\0') {
    if (unaff_R14B == '\0') {
      if (DAT_145d9fe79 == '\0') goto LAB_140ab5619;
    }
    else if (DAT_145d9fe78 == '\0') {
      unaff_R14B = '\0';
    }
LAB_140ab56c6:
    if ((unaff_DIL != '\0') && (unaff_R14B != '\0')) goto LAB_140ab5619;
    cVar2 = *(char *)(unaff_RSI + 0x281);
    bVar9 = cVar2 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1a0) = 0x6f3903cc;
    *(undefined4 *)(unaff_RSI + 0x1ac) = 0x836c214c;
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    iVar8 = 0x42991cb0;
    if (!bVar9) {
      iVar8 = -0x6927dc91;
    }
    *(undefined2 *)(unaff_RSI + 0x282) = 1;
    uVar11 = 0x9a5e57b2;
    if (!bVar9) {
      uVar11 = 0x4e1f686d;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar11;
    uVar11 = 0x734348c3;
    if (!bVar9) {
      uVar11 = 0xa702771c;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar11;
    if (bVar9) {
      iVar1 = *(int *)(unaff_RSI + 0x184);
    }
    else {
      iVar1 = *in_stack_00000060;
    }
    if (iVar1 != 0) {
      if (cVar2 == '\0') {
        iVar8 = *(int *)(unaff_RSI + 0x184);
      }
      else {
        iVar8 = *in_stack_00000060;
      }
    }
    *(int *)(unaff_RSI + 0x198) = iVar8;
    uVar3 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    iVar8 = *(int *)(unaff_RSI + 0x188);
    iVar4 = *(int *)(unaff_RSI + 0x18c);
    if (iVar8 != 0) goto LAB_140ab5a94;
    if (iVar4 == 0) {
      if ((param_4 == '\0') || (iVar1 != 0)) {
        *(undefined4 *)(unaff_RSI + 0x1a0) = 0xea6ee521;
        if (unaff_BL == '\0') {
          if (unaff_R12B == '\0') {
            uVar11 = 0;
          }
          else {
            uVar11 = 0x4db30291;
            if (cVar2 != '\0') {
              uVar11 = 0x99f23d4e;
            }
          }
          *(undefined4 *)(unaff_RSI + 0x19c) = uVar11;
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0x6498e62f;
          uVar3 = _DAT_146df2634;
        }
        else {
          *(undefined4 *)(unaff_RSI + 0x1a4) = 0xfd91b795;
          _DAT_146df261c = 2;
          uVar3 = _DAT_146df2634;
        }
      }
      else {
        *(undefined4 *)(unaff_RSI + 0x1a0) = 0xf60be115;
        *(undefined4 *)(unaff_RSI + 0x1a4) = 0x568987b1;
        *(undefined1 *)(unaff_RSI + 0x211) = 1;
        uVar11 = 0x736ce232;
        if (cVar2 != '\0') {
          uVar11 = 0xc3aac29e;
        }
        *(undefined4 *)(unaff_RSI + 0x198) = uVar11;
        uVar3 = _DAT_146df2634;
      }
      goto LAB_140ab5ab7;
    }
  }
  else {
    if (unaff_R14B != '\0') {
      if (param_2 == '\0') {
        unaff_R14B = '\0';
      }
      goto LAB_140ab56c6;
    }
    if (in_AL != '\0') goto LAB_140ab56c6;
LAB_140ab5619:
    cVar2 = *(char *)(unaff_RSI + 0x281);
    bVar9 = cVar2 == '\0';
    *(undefined4 *)(unaff_RSI + 0x1b0) = 0xa1ff8610;
    *(undefined2 *)(unaff_RSI + 0x282) = 0x100;
    iVar8 = -0x4ce4b144;
    if (!bVar9) {
      iVar8 = 0x675a7163;
    }
    uVar11 = 0x7bf72b79;
    if (!bVar9) {
      uVar11 = 0xafb614a6;
    }
    *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
    uVar11 = 0x2671d34e;
    if (!bVar9) {
      uVar11 = 0xf230ec91;
    }
    *(undefined4 *)(unaff_RSI + 0x1ac) = uVar11;
    uVar11 = 0x7c1d212;
    if (!bVar9) {
      uVar11 = 0xd380edcd;
    }
    *(undefined4 *)(unaff_RSI + 0x1b4) = uVar11;
    uVar11 = 0x797b9614;
    if (!bVar9) {
      uVar11 = 0xad3aa9cb;
    }
    *(undefined4 *)(unaff_RSI + 0x1a8) = uVar11;
    if (bVar9) {
      iVar1 = *unaff_R15;
    }
    else {
      iVar1 = *(int *)(unaff_RSI + 0x178);
    }
    if (iVar1 != 0) {
      if (cVar2 != '\0') {
        unaff_R15 = (int *)(unaff_RSI + 0x178);
      }
      iVar8 = *unaff_R15;
    }
    *(int *)(unaff_RSI + 0x198) = iVar8;
    uVar3 = _DAT_146df2634;
    if (DAT_145d9fe7e == '\0') goto LAB_140ab5ab7;
    if (DAT_146df2617 != '\0') {
      uVar11 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
      *(undefined4 *)(unaff_RSI + 0x1a4) = 0x26558708;
      uVar3 = _DAT_146df2634;
      goto LAB_140ab5ab7;
    }
    iVar8 = *(int *)(unaff_RSI + 0x188);
    iVar4 = *(int *)(unaff_RSI + 0x18c);
    if (iVar8 == 0) {
      if (iVar4 == 0) {
        if ((param_4 == '\0') || (iVar1 != 0)) {
          if (unaff_R13B == '\0') {
            if (*(char *)(unaff_RBP + 0x70) == '\0') {
              if (unaff_BL == '\0') {
                uVar11 = 0x6eb97095;
                if (cVar2 != '\0') {
                  uVar11 = 0xde7f5039;
                }
                *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
                if (unaff_R12B == '\0') {
                  uVar11 = 0;
                }
                else {
                  uVar11 = 0x99fc5bf5;
                  if (cVar2 != '\0') {
                    uVar11 = 0x4dbd642a;
                  }
                }
                *(undefined4 *)(unaff_RSI + 0x19c) = uVar11;
                uVar11 = 0x26558708;
                if (cVar2 != '\0') {
                  uVar11 = 0x9693a7a4;
                }
                *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
                uVar3 = _DAT_146df2634;
              }
              else {
                uVar11 = 0x6eb97095;
                if (cVar2 != '\0') {
                  uVar11 = 0xde7f5039;
                }
                uVar7 = 0xbf5cd6b2;
                if (cVar2 != '\0') {
                  uVar7 = 0xf9af61e;
                }
                *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
                *(undefined4 *)(unaff_RSI + 0x1a4) = uVar7;
                _DAT_146df261c = 2;
                uVar3 = _DAT_146df2634;
              }
            }
            else {
              uVar11 = 0x6eb97095;
              if (cVar2 != '\0') {
                uVar11 = 0xde7f5039;
              }
              uVar7 = 0xea32cd03;
              if (cVar2 != '\0') {
                uVar7 = 0x8e3054e0;
              }
              *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
              *(undefined4 *)(unaff_RSI + 0x1a4) = uVar7;
              _DAT_146df261c = 2;
              _DAT_146df2638 = 4;
              _DAT_146df263c = 0;
              uVar3 = _DAT_146df2634;
            }
          }
          else {
            bVar9 = _DAT_146df2630 == 0;
            if ((_DAT_146df2630 == 0) && (_DAT_146df2634 == 0)) {
              uVar3 = func_0x000141bbb790();
              bVar9 = (bool)(~(byte)(uVar3 >> 0xf) & 1);
            }
            *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
            uVar11 = 0x9b0f4f04;
            if (bVar9 != false) {
              uVar11 = 0xe6e5760f;
            }
            uVar7 = 0xff0dd6e7;
            if (bVar9 != false) {
              uVar7 = 0xd104919c;
            }
            bVar10 = *(char *)(unaff_RSI + 0x281) != '\0';
            if (bVar10) {
              uVar7 = uVar11;
            }
            uVar11 = 0x6eb97095;
            if (bVar10) {
              uVar11 = 0xde7f5039;
            }
            *(undefined4 *)(unaff_RSI + 0x1a4) = uVar7;
            *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
            _DAT_146df261c = 2;
            if (bVar9 == false) {
              uVar3 = 2;
              if (2 < _DAT_146df2630) {
                uVar3 = _DAT_146df2630;
              }
              _DAT_146df2634 = 6;
              _DAT_146df2630 = uVar3;
              uVar3 = _DAT_146df2634;
            }
            else {
              _DAT_146df2630 = 3;
              uVar3 = 2;
              if (2 < _DAT_146df2634) {
                uVar3 = _DAT_146df2634;
              }
            }
          }
        }
        else {
          bVar9 = cVar2 != '\0';
          *(undefined2 *)(unaff_RSI + 0x211) = 0x101;
          uVar11 = 0x65efd996;
          if (bVar9) {
            uVar11 = 0xd529f93a;
          }
          *(undefined4 *)(unaff_RSI + 0x198) = uVar11;
          uVar11 = 0x2a58dc40;
          if (bVar9) {
            uVar11 = 0xfe19e39f;
          }
          *(undefined4 *)(unaff_RSI + 0x1a0) = uVar11;
          uVar11 = 0xa2dc00a0;
          if (bVar9) {
            uVar11 = 0x769d3f7f;
          }
          *(undefined4 *)(unaff_RSI + 0x1a4) = uVar11;
          uVar3 = _DAT_146df2634;
        }
        goto LAB_140ab5ab7;
      }
    }
    else {
LAB_140ab5a94:
      *(int *)(unaff_RSI + 0x1a0) = iVar8;
      if (iVar4 == 0) {
        iVar4 = *(int *)(unaff_RSI + 0x1a4);
      }
    }
  }
  *(int *)(unaff_RSI + 0x1a4) = iVar4;
  *(undefined1 *)(unaff_RSI + 0x211) = *(undefined1 *)(unaff_RSI + 400);
  uVar3 = _DAT_146df2634;
LAB_140ab5ab7:
  _DAT_146df2634 = uVar3;
  if ((DAT_146df2611 != '\0') || (uVar5 = 1, *(char *)(unaff_RSI + 0x284) != '\0')) {
    uVar5 = 3;
  }
  uVar11 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar5);
  cVar2 = FUN_140ab3ee0(uVar11,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar2 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar6 = *(longlong *)(unaff_RSI + 8);
  uVar11 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar6 + 0x88) == 0) {
    uVar5 = FUN_14167ab40(lVar6 + 0x58,0x1473d09e0);
  }
  else {
    uVar5 = func_0x0001416799a0(lVar6 + 0x80);
  }
  FUN_1415c2240(uVar5,unaff_RBP + 0x70,uVar11,0);
  lVar6 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar6 != 0) {
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0x3bff28c9);
    if (unaff_XMM8_Da <= fVar12) {
      *(float *)(unaff_RSI + 0x1c8) = fVar12;
    }
    else {
      fVar12 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar12;
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0xa959982c);
    if (fVar12 < unaff_XMM8_Da) {
      fVar12 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar12;
    fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0xbe47e933);
    if (fVar12 < unaff_XMM8_Da) {
      fVar12 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar12 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar12;
  }
  func_0x0001415c0440(uVar5,*(undefined4 *)(unaff_RBP + 0x70));
  iVar8 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar8 != 0) {
    lVar6 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar6 + 0x88) == 0) {
      uVar5 = FUN_14167ab40(lVar6 + 0x58,0x1473d09e0);
    }
    else {
      uVar5 = func_0x0001416799a0(lVar6 + 0x80);
    }
    FUN_1415c2240(uVar5,unaff_RBP + 0x70,iVar8,0);
    lVar6 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar6 != 0) {
      fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar12;
      if (fVar12 < unaff_XMM8_Da) {
        fVar12 = *(float *)(lVar6 + 0x300) * unaff_XMM14_Da;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar12;
      fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar12;
      if ((fVar12 < unaff_XMM8_Da) &&
         (fVar12 = *(float *)(lVar6 + 0x300) - _DAT_14382e120, fVar12 <= unaff_XMM8_Da)) {
        fVar12 = unaff_XMM8_Da;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar12;
      fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar6,0xa959982c);
      fVar12 = *(float *)(unaff_RSI + 0x1d4);
      if ((unaff_XMM8_Da <= fVar13) && (fVar13 <= fVar12)) {
        fVar12 = fVar13;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar12;
    }
    func_0x0001415c0440(uVar5,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab5ae0 @ 0x140ab5ae0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab5ae0(void)

{
  int iVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong unaff_RBP;
  longlong unaff_RSI;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float unaff_XMM8_Da;
  float unaff_XMM14_Da;
  
  uVar3 = 1;
  if (*(char *)(unaff_RSI + 0x284) != '\0') {
    uVar3 = 3;
  }
  uVar5 = FUN_1420df1c0(unaff_RSI + 0xf0,uVar3);
  cVar2 = FUN_140ab3ee0(uVar5,*(undefined4 *)(unaff_RSI + 0x1a4));
  if (cVar2 == '\0') {
    *(undefined4 *)(unaff_RSI + 0x1a4) = 0;
  }
  lVar4 = *(longlong *)(unaff_RSI + 8);
  uVar5 = *(undefined4 *)(unaff_RSI + 0x198);
  *(undefined4 *)(unaff_RSI + 0x1c8) = 0x3f19999a;
  *(undefined4 *)(unaff_RSI + 0x1cc) = 0x3e99999a;
  if (*(short *)(lVar4 + 0x88) == 0) {
    uVar3 = FUN_14167ab40(lVar4 + 0x58,0x1473d09e0);
  }
  else {
    uVar3 = func_0x0001416799a0(lVar4 + 0x80);
  }
  FUN_1415c2240(uVar3,unaff_RBP + 0x70,uVar5,0);
  lVar4 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
  if (lVar4 != 0) {
    fVar6 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar4,0x3bff28c9);
    if (unaff_XMM8_Da <= fVar6) {
      *(float *)(unaff_RSI + 0x1c8) = fVar6;
    }
    else {
      fVar6 = *(float *)(unaff_RSI + 0x1cc);
      *(undefined4 *)(unaff_RSI + 0x1c8) = *(undefined4 *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar6;
    fVar6 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar4,0xa959982c);
    if (fVar6 < unaff_XMM8_Da) {
      fVar6 = *(float *)(unaff_RSI + 0x1c8);
    }
    *(float *)(unaff_RSI + 0x1c8) = fVar6;
    fVar6 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar4,0xbe47e933);
    if (fVar6 < unaff_XMM8_Da) {
      fVar6 = *(float *)(unaff_RSI + 0x1c8);
      if (*(float *)(unaff_RSI + 0x1cc) <= *(float *)(unaff_RSI + 0x1c8)) {
        fVar6 = *(float *)(unaff_RSI + 0x1cc);
      }
    }
    *(float *)(unaff_RSI + 0x1cc) = fVar6;
  }
  func_0x0001415c0440(uVar3,*(undefined4 *)(unaff_RBP + 0x70));
  iVar1 = *(int *)(unaff_RSI + 0x19c);
  *(undefined8 *)(unaff_RSI + 0x1d0) = 0;
  if (iVar1 != 0) {
    lVar4 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar4 + 0x88) == 0) {
      uVar3 = FUN_14167ab40(lVar4 + 0x58,0x1473d09e0);
    }
    else {
      uVar3 = func_0x0001416799a0(lVar4 + 0x80);
    }
    FUN_1415c2240(uVar3,unaff_RBP + 0x70,iVar1,0);
    lVar4 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0x70));
    if (lVar4 != 0) {
      fVar6 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar4,0x54638a5f);
      *(float *)(unaff_RSI + 0x1d0) = fVar6;
      if (fVar6 < unaff_XMM8_Da) {
        fVar6 = *(float *)(lVar4 + 0x300) * unaff_XMM14_Da;
      }
      *(float *)(unaff_RSI + 0x1d0) = fVar6;
      fVar6 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar4,0x3bff28c9);
      *(float *)(unaff_RSI + 0x1d4) = fVar6;
      if ((fVar6 < unaff_XMM8_Da) &&
         (fVar6 = *(float *)(lVar4 + 0x300) - _DAT_14382e120, fVar6 <= unaff_XMM8_Da)) {
        fVar6 = unaff_XMM8_Da;
      }
      *(float *)(unaff_RSI + 0x1d4) = fVar6;
      fVar7 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RSI + 8),lVar4,0xa959982c);
      fVar6 = *(float *)(unaff_RSI + 0x1d4);
      if ((unaff_XMM8_Da <= fVar7) && (fVar7 <= fVar6)) {
        fVar6 = fVar7;
      }
      *(float *)(unaff_RSI + 0x1d8) = fVar6;
    }
    func_0x0001415c0440(uVar3,*(undefined4 *)(unaff_RBP + 0x70));
  }
  return;
}


/* SwingRegion_140ab5e60 @ 0x140ab5e60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab5e60(longlong param_1,undefined8 param_2,longlong param_3)

{
  float fVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined4 auStackX_8 [2];
  undefined4 uStack_138;
  float fStack_134;
  float fStack_130;
  undefined8 uStack_128;
  float fStack_120;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  float fStack_e4;
  float fStack_e0;
  float fStack_d8;
  float fStack_d4;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_bc;
  float fStack_a4;
  float fStack_a0;
  
  uVar12 = (undefined4)((ulonglong)param_2 >> 0x20);
  fVar10 = (float)param_2;
  FUN_1402d0740(&uStack_138,param_1 + 0x220);
  puVar4 = (undefined4 *)&DAT_147afdf10;
  if ((undefined4 *)**(undefined8 **)(param_1 + 8) != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)**(undefined8 **)(param_1 + 8);
  }
  uStack_118 = *puVar4;
  uStack_114 = puVar4[1];
  uStack_110 = puVar4[2];
  uStack_10c = puVar4[4];
  uStack_108 = puVar4[5];
  uStack_104 = puVar4[6];
  uStack_100 = puVar4[8];
  uStack_fc = puVar4[9];
  uStack_f8 = puVar4[10];
  fVar15 = (float)puVar4[0xc];
  fVar11 = (float)puVar4[0xd];
  fVar13 = (float)puVar4[0xe];
  FUN_1402e7060(&fStack_d8,&uStack_118);
  uVar2 = _DAT_14382e160;
  fVar1 = _DAT_14382dce0;
  fVar15 = *(float *)(param_1 + 0x168) - fVar15;
  fVar13 = *(float *)(param_1 + 0x170) - fVar13;
  fVar11 = *(float *)(param_1 + 0x16c) - (fVar11 + _DAT_1438388c0);
  fVar16 = fStack_cc * fVar11 + fStack_d8 * fVar15 + fStack_c0 * fVar13;
  fVar11 = fStack_c8 * fVar11 + fStack_d4 * fVar15 + fStack_bc * fVar13;
  fVar15 = (float)((uint)fVar11 & _DAT_14382e160);
  if (fVar15 <= 0.0) {
    fVar15 = 0.0;
  }
  if (fVar15 <= (float)((uint)fVar16 & _DAT_14382e160)) {
    fVar15 = (float)((uint)fVar16 & _DAT_14382e160);
  }
  fVar13 = fVar16;
  if (0.0 < fVar15) {
    fVar11 = (_DAT_14382dce0 / fVar15) * fVar11;
    fVar15 = (_DAT_14382dce0 / fVar15) * fVar16;
    fVar13 = _DAT_14382dce0 / SQRT(fVar11 * fVar11 + fVar15 * fVar15);
    fVar11 = fVar13 * fVar11;
    fVar13 = fVar13 * fVar15;
  }
  fVar15 = (float)((uint)fVar13 & _DAT_14382e160);
  if (fVar15 <= 0.0) {
    fVar15 = 0.0;
  }
  if (fVar15 <= 0.0) {
    fVar15 = 0.0;
  }
  else {
    fVar15 = SQRT((fVar13 / fVar15) * (fVar13 / fVar15)) * fVar15;
  }
  uVar7 = FUN_141c58560(fVar11,fVar15);
  fVar15 = _DAT_14382e128;
  fVar11 = (float)(uVar7 ^ _DAT_14382e890);
  if (*(int *)(param_1 + 0x19c) != 0) {
    fVar8 = (float)FUN_1415c09c0(param_3,0);
    fVar14 = *(float *)(param_1 + 0x1cc) + *(float *)(param_1 + 0x1d0);
    if (*(char *)(param_1 + 0xf0) == '\x01') {
      fVar14 = fVar14 - _DAT_145d9fe88;
      if ((float)((uint)fVar14 & uVar2) <= _DAT_14382e118) {
        if (_DAT_145d9fe88 <= fVar8) {
          if (fVar8 <= _DAT_145d9fe88) {
            *(float *)(param_1 + 0x244) = fVar15;
            fVar14 = *(float *)(param_1 + 0x244);
            uVar12 = 0;
          }
          else {
            *(float *)(param_1 + 0x244) = fVar1;
            fVar14 = *(float *)(param_1 + 0x244);
            uVar12 = 0;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x244) = 0;
          fVar14 = *(float *)(param_1 + 0x244);
          uVar12 = 0;
        }
      }
      else {
        fVar14 = (fVar8 - _DAT_145d9fe88) / fVar14;
        if (fVar14 <= 0.0) {
          fVar14 = 0.0;
        }
        if (fVar1 <= fVar14) {
          fVar14 = fVar1;
        }
        *(float *)(param_1 + 0x244) = fVar14;
        fVar14 = *(float *)(param_1 + 0x244);
        uVar12 = 0;
      }
      goto LAB_140ab6217;
    }
    if (*(char *)(param_1 + 0xf0) == '\x02') {
      fVar14 = fVar14 - _DAT_145d9fe88;
      fVar9 = *(float *)(param_1 + 0x1cc) + fVar8;
      if ((float)((uint)fVar14 & uVar2) <= _DAT_14382e118) {
        if (_DAT_145d9fe88 <= fVar9) {
          fVar14 = fVar15;
          if (_DAT_145d9fe88 < fVar9) {
            fVar14 = fVar1;
          }
        }
        else {
          fVar14 = 0.0;
        }
      }
      else {
        fVar14 = (fVar9 - _DAT_145d9fe88) / fVar14;
        if (fVar14 <= 0.0) {
          fVar14 = 0.0;
        }
        if (fVar1 <= fVar14) {
          fVar14 = fVar1;
        }
      }
      *(float *)(param_1 + 0x244) = fVar14;
      if ((*(char *)(param_1 + 0x289) != '\0') && (*(float *)(param_1 + 0x1d0) < fVar8)) {
        func_0x0001415c6440(param_3 + 0x68,auStackX_8,0);
        lVar5 = func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
        if (lVar5 != 0) {
          *(undefined1 *)(param_1 + 0x289) = 0;
        }
      }
      fVar14 = *(float *)(param_1 + 0x244);
      uVar12 = 0;
      goto LAB_140ab6217;
    }
  }
  fVar14 = fVar10 * _DAT_143834a14 + *(float *)(param_1 + 0x244);
  if (fVar1 <= fVar14) {
    fVar14 = fVar1;
  }
  *(float *)(param_1 + 0x244) = fVar14;
LAB_140ab6217:
  fVar8 = _DAT_14382e140;
  fVar11 = fVar11 - _DAT_14382e140;
  fVar9 = ((float)((uint)fStack_134 & uVar2) - _DAT_143836d08) * _DAT_1438ac3b8;
  if (fVar9 <= 0.0) {
    fVar9 = 0.0;
  }
  if (fVar1 <= fVar9) {
    fVar9 = fVar1;
  }
  fVar9 = (float)((uint)((fVar1 - fVar9) * fVar11 - _DAT_14382e134) & uVar2) * _DAT_143872ed0;
  if (fVar9 <= 0.0) {
    fVar9 = 0.0;
  }
  if (fVar1 <= fVar9) {
    fVar9 = fVar1;
  }
  fVar14 = (float)FUN_143666da0(CONCAT44(uVar12,fVar14),_DAT_145d9fe84);
  fVar9 = (fVar1 - fVar9) * fVar15;
  if (fVar16 <= 0.0) {
    fVar16 = fVar9 + fVar15;
    fVar14 = fVar9 * fVar14 + fVar15;
  }
  else {
    fVar16 = fVar15 - fVar9;
    fVar14 = fVar15 - fVar9 * fVar14;
  }
  *(float *)(param_1 + 0x23c) = fVar16;
  fVar16 = (float)FUN_141c46be0(*(undefined4 *)(param_1 + 0x238),fVar14,param_1 + 0x240,
                                _DAT_1438347a4,_DAT_14383ee38,_DAT_1438ad724,fVar10);
  if (((DAT_145d9fe7f != '\0') && (*(int *)(param_1 + 0x19c) != 0)) &&
     ((byte)(*(char *)(param_1 + 0xf0) - 1U) < 2)) {
    if (_DAT_143830ee8 <= fVar10) {
      fVar16 = (fVar14 - *(float *)(param_1 + 0x238)) / fVar10;
    }
    else {
      fVar16 = 0.0;
    }
    *(float *)(param_1 + 0x240) = fVar16;
    fVar16 = fVar14;
  }
  *(float *)(param_1 + 0x238) = fVar16;
  FUN_1415c2c00(param_3,0xf8d44865,fVar16);
  FUN_1415c2c00(param_3,0x46434591,fVar1 - *(float *)(param_1 + 0x238));
  fVar16 = (*(float *)(param_1 + 0x1b8) - _DAT_143861350) * _DAT_1438ad510;
  if (fVar16 <= 0.0) {
    fVar16 = 0.0;
  }
  if (fVar1 <= fVar16) {
    fVar16 = fVar1;
  }
  fVar16 = fVar1 - fVar16;
  fVar14 = fVar16;
  if ((*(float *)(param_1 + 0x27c) != _DAT_14382e9ec) &&
     (fVar14 = fVar10 * _DAT_14382ee88 + *(float *)(param_1 + 0x27c), fVar14 <= fVar16)) {
    fVar14 = fVar16;
  }
  *(float *)(param_1 + 0x27c) = fVar14;
  FUN_1415c2c00(param_3,0x14049a0b);
  cVar3 = *(char *)(param_1 + 0xf0);
  if (cVar3 == '\x01') {
    fVar13 = (float)FUN_141c58560(fVar13,0);
    fVar11 = fVar11 * _DAT_14383e6a4;
    if (fVar11 <= 0.0) {
      fVar11 = 0.0;
    }
    fVar13 = (fVar13 - fVar8) * _DAT_14383e6a4;
    if (fVar1 <= fVar11) {
      fVar11 = fVar1;
    }
    if (fVar13 <= 0.0) {
      fVar13 = 0.0;
    }
    if (fVar1 <= fVar13) {
      fVar13 = fVar1;
    }
    FUN_1415c2c00(param_3,0x9d1aea3d,fVar11);
    FUN_1415c2c00(param_3,0x14c28d6c,fVar13);
    cVar3 = *(char *)(param_1 + 0xf0);
  }
  fVar11 = _DAT_1438ad548;
  fVar13 = *(float *)(param_1 + 0x1b8) * _DAT_1438ad548;
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  if (fVar1 <= fVar13) {
    fVar13 = fVar1;
  }
  fVar13 = fVar1 - fVar13;
  if (cVar3 == '\x03') {
    if (fVar13 <= 0.0) {
      fVar13 = 0.0;
    }
    if (_DAT_1438b4f38 <= fVar13) {
      fVar13 = _DAT_1438b4f38;
    }
  }
  else if (cVar3 == '\x05') {
    if (fVar13 <= _DAT_1438b4f3c) {
      fVar13 = _DAT_1438b4f3c;
    }
    if (fVar1 <= fVar13) {
      fVar13 = fVar1;
    }
  }
  FUN_1415c2c00(param_3,0x5f118c92,fVar13);
  FUN_1415c2c00(param_3,0xe47da57f,fVar13);
  FUN_1415c2c00(param_3,0xb26c1350,fVar15);
  uVar6 = 0xa8a6e397;
  if (*(char *)(param_1 + 0x281) != '\0') {
    uVar6 = 0xbb15a07f;
  }
  lVar5 = **(longlong **)(param_1 + 8);
  if ((lVar5 == 0) || (*(char *)(lVar5 + 0x5f) != '\0')) {
    lVar5 = 0;
  }
  FUN_141775cc0(lVar5,&uStack_118,uVar6);
  lVar5 = **(longlong **)(param_1 + 8);
  if ((lVar5 == 0) || (*(char *)(lVar5 + 0x5f) != '\0')) {
    lVar5 = 0;
  }
  FUN_141775cc0(lVar5,&fStack_d8,0xe3a5e47f);
  fStack_134 = fStack_a4 - fStack_e4;
  fStack_130 = fStack_a0 - fStack_e0;
  fVar13 = (float)((uint)fStack_130 & uVar2);
  if ((float)((uint)fStack_130 & uVar2) <= (float)((uint)fStack_134 & uVar2)) {
    fVar13 = (float)((uint)fStack_134 & uVar2);
  }
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  if (0.0 < fVar13) {
    fStack_130 = (fVar1 / fVar13) * fStack_130;
    fStack_134 = (fVar1 / fVar13) * fStack_134;
    fVar13 = fVar1 / SQRT(fStack_130 * fStack_130 + fStack_134 * fStack_134);
    fStack_130 = fVar13 * fStack_130;
    fStack_134 = fVar13 * fStack_134;
  }
  uStack_128 = (ulonglong)(uint)fStack_134 << 0x20;
  fStack_120 = fStack_130;
  uStack_138 = 0;
  fStack_134 = 1.0;
  fStack_130 = 0.0;
  fVar16 = (float)func_0x000141c59090(&uStack_138,&uStack_128);
  fVar13 = _DAT_143855568;
  if (0.0 <= fStack_120) {
    fVar13 = _DAT_143830124;
  }
  fVar13 = fVar16 * fVar13 + _DAT_143861350;
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  if (_DAT_143840c90 <= fVar13) {
    fVar13 = _DAT_143840c90;
  }
  fVar11 = ((*(float *)(param_1 + 0x1b8) - fVar13) - _DAT_14386dd14) * fVar11;
  if (fVar11 <= 0.0) {
    fVar11 = 0.0;
  }
  if (fVar1 <= fVar11) {
    fVar11 = fVar1;
  }
  fVar13 = (float)((uint)uStack_128._4_4_ & uVar2);
  if ((float)((uint)uStack_128._4_4_ & uVar2) <= (float)((uint)fStack_120 & uVar2)) {
    fVar13 = (float)((uint)fStack_120 & uVar2);
  }
  if (fVar13 <= (float)((uint)(float)uStack_128 & uVar2)) {
    fVar13 = (float)((uint)(float)uStack_128 & uVar2);
  }
  fVar16 = fVar1 / fVar13;
  if (((fVar13 <= 0.0) ||
      (SQRT(uStack_128._4_4_ * fVar16 * uStack_128._4_4_ * fVar16 +
            (float)uStack_128 * fVar16 * (float)uStack_128 * fVar16 +
            fVar16 * fStack_120 * fVar16 * fStack_120) * fVar13 < _DAT_14382e120)) ||
     (fVar11 = fVar1 - fVar11, *(char *)(param_1 + 0xf0) == '\x01')) {
    fVar11 = fVar15;
  }
  uVar12 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x250),fVar11,_DAT_14382f0e4,fVar10);
  *(undefined4 *)(param_1 + 0x250) = uVar12;
  FUN_1415c2c00(param_3,0x14330330,uVar12);
  return;
}


/* SwingRegion_140ab6750 @ 0x140ab6750 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab6750(longlong param_1,float param_2)

{
  float *pfVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  float *pfVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int iVar10;
  float fVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  undefined4 uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float afStackX_18 [2];
  float afStackX_20 [2];
  float *pfVar25;
  undefined8 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  uint in_stack_fffffffffffffea8;
  uint uVar29;
  undefined8 uStack_148;
  float fStack_140;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  float fStack_114;
  float afStack_110 [2];
  float fStack_108;
  float fStack_104;
  float fStack_fc;
  float fStack_f8;
  float fStack_f0;
  undefined1 auStack_e8 [56];
  undefined1 *puStack_b0;
  undefined4 uStack_88;
  undefined4 uStack_80;
  float fStack_78;
  
  if (DAT_145d9fe7e != '\0') {
    lVar5 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      puStack_b0 = &LAB_140ab782c;
      uVar8 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
    }
    else {
      puStack_b0 = (undefined1 *)0x140ab7821;
      uVar8 = func_0x0001416799a0(lVar5 + 0x80);
    }
    if (*(int *)(param_1 + 0x194) == 0) {
      puStack_b0 = (undefined1 *)0x140ab7842;
      FUN_1415bf500(uVar8,0);
      puStack_b0 = (undefined1 *)0x140ab784f;
      FUN_1415bf500(uVar8,1);
      lVar5 = *(longlong *)(param_1 + 8);
      if (*(short *)(lVar5 + 0x88) == 0) {
        puStack_b0 = &LAB_140ab7878;
        uVar9 = FUN_14167ab40(lVar5 + 0x58,0x146dacd70);
      }
      else {
        puStack_b0 = (undefined1 *)0x140ab786d;
        uVar9 = func_0x0001416799a0(lVar5 + 0x80);
      }
      puStack_b0 = &LAB_140ab7880;
      FUN_1408614a0(uVar9);
    }
    puStack_b0 = (undefined1 *)0x140ab788f;
    FUN_140ab7b30(param_1,param_2,uVar8);
    puStack_b0 = (undefined1 *)0x140ab789e;
    FUN_140ab8d00(param_1,param_2,uVar8);
    puStack_b0 = (undefined1 *)0x140ab78ad;
    FUN_140ab5e60(param_1,param_2,uVar8);
    puStack_b0 = (undefined1 *)0x140ab78bc;
    FUN_140ab8af0(param_1,param_2,uVar8);
    puStack_b0 = (undefined1 *)0x140ab78c4;
    fVar13 = (float)FUN_1420dc660(param_1);
    fVar22 = _DAT_14382dce0;
    fVar14 = (fVar13 - _DAT_14382e120) * _DAT_1438627c8;
    fVar13 = ((float)((uint)*(float *)(param_1 + 0x230) & _DAT_14382e160) - _DAT_14382f0e0) *
             _DAT_1438929bc;
    if (fVar14 <= 0.0) {
      fVar14 = 0.0;
    }
    if (fVar13 <= 0.0) {
      fVar13 = 0.0;
    }
    if (_DAT_14382dce0 <= fVar14) {
      fVar14 = _DAT_14382dce0;
    }
    if (_DAT_14382dce0 <= fVar13) {
      fVar13 = _DAT_14382dce0;
    }
    if (0.0 <= *(float *)(param_1 + 0x230)) {
      fVar13 = _DAT_14382dce0 - fVar13 * fVar14;
    }
    else {
      fVar13 = fVar13 * fVar14 + _DAT_14382dce0;
    }
    uStack_80 = _DAT_14382ee90;
    uStack_88 = _DAT_143841320;
    puStack_b0 = (undefined1 *)0x140ab7974;
    fStack_78 = param_2;
    uVar15 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x248),fVar13 * _DAT_14382e128,param_1 + 0x24c,
                           _DAT_1438ac770);
    *(undefined4 *)(param_1 + 0x248) = uVar15;
    puStack_b0 = (undefined1 *)0x140ab798c;
    FUN_1415c2c00(uVar8,0x31b78a49,uVar15);
    puStack_b0 = (undefined1 *)0x140ab799b;
    FUN_140ab7ee0(param_1,param_2,uVar8);
    puStack_b0 = (undefined1 *)0x140ab79aa;
    FUN_140ab81e0(param_1,param_2,uVar8);
    if (*(int *)(param_1 + 0x194) == *(int *)(param_1 + 0x1a4)) {
      if ((0.0 < *(float *)(param_1 + 0x1e4) || *(float *)(param_1 + 0x1e4) == 0.0) &&
         (0.0 < *(float *)(param_1 + 0x1e8) || *(float *)(param_1 + 0x1e8) == 0.0)) {
        puStack_b0 = (undefined1 *)0x140ab7a27;
        fVar14 = (float)FUN_1415c09c0(uVar8,0);
        puStack_b0 = (undefined1 *)0x140ab7a35;
        fVar16 = (float)FUN_1415c05d0(uVar8,0);
        puStack_b0 = (undefined1 *)0x140ab7a43;
        fVar17 = (float)FUN_1415c0a10(uVar8,0);
        fVar13 = (fVar22 / fVar16) * *(float *)(param_1 + 0x1e8);
        if (fVar22 <= fVar13) {
          fVar13 = fVar22;
        }
        if (fVar13 < *(float *)(param_1 + 0x204) || fVar13 == *(float *)(param_1 + 0x204)) {
          fVar13 = *(float *)(param_1 + 0x208);
          puStack_b0 = (undefined1 *)0x140ab7ab2;
          fVar14 = (float)func_0x00014041c590(*(undefined4 *)(param_1 + 0x1bc),
                                              *(undefined4 *)(param_1 + 0x20c),
                                              *(undefined4 *)(param_1 + 0x1e4));
          fVar13 = fVar14 * (fVar22 - fVar13) + fVar13;
        }
        else {
          *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(param_1 + 0x1bc);
          fVar13 = (fVar14 + param_2) * (fVar22 / fVar16);
          if (fVar22 <= fVar13) {
            fVar13 = fVar22;
          }
          *(float *)(param_1 + 0x208) = fVar13;
        }
        *(float *)(param_1 + 0x204) = fVar13;
        if ((_DAT_14382e118 <= param_2) &&
           (fVar22 = ((fVar13 - fVar17) * fVar16) / param_2, fVar22 <= _DAT_143830118)) {
          fVar22 = _DAT_143830118;
        }
        puStack_b0 = (undefined1 *)0x140ab7b03;
        FUN_1415c2670(uVar8,fVar22,0);
        *(undefined1 *)(param_1 + 0x210) = 1;
        return;
      }
    }
    else {
      puStack_b0 = &LAB_140ab79c8;
      FUN_1415c2c00(uVar8,0x2ae17432,0);
    }
    *(undefined1 *)(param_1 + 0x210) = 0;
    *(undefined4 *)(param_1 + 0x204) = 0;
    return;
  }
  pfVar6 = afStackX_18;
  pfVar1 = (float *)(param_1 + 0x168);
  uVar29 = in_stack_fffffffffffffea8 & 0xffffff00;
  pfVar25 = afStackX_20;
  FUN_140ab4450(pfVar1,param_1 + 0x134,param_1 + 0x220,&uStack_148,pfVar25,pfVar6,uVar29);
  uVar15 = _DAT_14384a1cc;
  fVar13 = _DAT_14382e9ec;
  uVar28 = (undefined4)((ulonglong)pfVar6 >> 0x20);
  uVar27 = (undefined4)((ulonglong)pfVar25 >> 0x20);
  fVar22 = *(float *)(param_1 + 0x1b8);
  if (*(float *)(param_1 + 0x1b8) == _DAT_14382e9ec) {
    fVar22 = afStackX_18[0];
  }
  *(float *)(param_1 + 0x1b8) = fVar22;
  uVar8 = func_0x000141c477e0(fVar22,afStackX_18[0],uVar15,param_2);
  fVar14 = _DAT_143840c90;
  fVar16 = (float)uVar8;
  *(float *)(param_1 + 0x1b8) = fVar16;
  *(float *)(param_1 + 0x1bc) = fVar14 - fVar16;
  *(float *)(param_1 + 0x1c0) = afStackX_20[0];
  fVar17 = (float)FUN_1420dc660(param_1);
  fVar22 = _DAT_14382e128;
  if ((fVar17 < _DAT_14382e128) && (fVar16 < _DAT_14382f0e0)) {
    lVar5 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146df2790);
    }
    else {
      lVar5 = func_0x0001416799a0(lVar5 + 0x80);
    }
    if (lVar5 != 0) {
      uStack_148 = *(undefined8 *)(lVar5 + 0x438);
      fStack_140 = *(float *)(lVar5 + 0x440);
      FUN_141676930(param_1);
      pfVar6 = afStackX_18;
      pfVar25 = afStackX_20;
      FUN_140ab4450(&uStack_148,param_1 + 0x134,param_1 + 0x220,auStack_e8,pfVar25,pfVar6,
                    uVar29 & 0xffffff00);
      uVar28 = (undefined4)((ulonglong)pfVar6 >> 0x20);
      uVar27 = (undefined4)((ulonglong)pfVar25 >> 0x20);
    }
  }
  lVar5 = *(longlong *)(param_1 + 8);
  afStackX_18[0] = (float)CONCAT31(afStackX_18[0]._1_3_,1);
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar9 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar9 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if ((*(char *)(param_1 + 0xf0) == '\x01') &&
     (*(int *)(param_1 + 0x194) == *(int *)(param_1 + 0x198))) {
    fVar17 = (float)FUN_1415c09c0(uVar9,0);
    if ((*(int *)(param_1 + 0x1a8) != 0) && (*(float *)(param_1 + 0x1c4) <= fVar17)) {
      uVar28 = 0;
      uVar26 = CONCAT44(uVar27,_DAT_14382e13c);
      FUN_1415bae90(uVar9,afStackX_20,*(int *)(param_1 + 0x1a8),0,uVar26,0);
      uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);
      *(undefined4 *)(param_1 + 0x1c4) = 0x7149f2ca;
    }
    cVar3 = FUN_1415bfc60(uVar9,_DAT_14382ee88,0);
    if ((cVar3 != '\0') || (fVar16 < _DAT_143872d8c)) {
      FUN_1420df1c0(param_1 + 0xf0,3);
    }
  }
  fVar23 = _DAT_14382e134;
  fVar17 = _DAT_14382dce0;
  fVar11 = 0.0;
  if (*(char *)(param_1 + 0xf0) == '\x01') {
    iVar10 = *(int *)(param_1 + 0x198);
    afStackX_18[0] = (float)((uint)afStackX_18[0]._1_3_ << 8);
  }
  else if (*(char *)(param_1 + 0xf0) == '\a') {
    iVar10 = *(int *)(param_1 + 0x200);
    afStackX_18[0] = (float)((uint)afStackX_18[0]._1_3_ << 8);
  }
  else {
    if (fVar16 <= _DAT_143861350) {
      uVar8 = func_0x00014041c590(uVar8,0,_DAT_143861350);
      fVar14 = (float)FUN_143666da0(uVar8,_DAT_143834a08);
      fVar11 = ((fVar17 - fVar14) * _DAT_1438ce970) / ((fVar14 + fVar17) * _DAT_1438388cc) + fVar23;
    }
    else {
      fVar14 = (float)func_0x00014041c590(uVar8,_DAT_143861350,fVar14);
      fVar11 = (float)FUN_143666da0(fVar17 - fVar14,_DAT_143834a08);
      fVar11 = fVar11 * fVar23;
    }
    fVar11 = fVar11 * _DAT_1438ce960;
    iVar10 = *(int *)(param_1 + 0x1a0);
    if (fVar11 <= 0.0) {
      fVar11 = 0.0;
    }
    if (fVar17 <= fVar11) {
      fVar11 = fVar17;
    }
  }
  iVar4 = *(int *)(param_1 + 0x194);
  uVar15 = _DAT_14382e13c;
  if (iVar10 != iVar4) {
    if (iVar4 == 0) {
      FUN_1415bf500(uVar9,0);
      FUN_1415bf500(uVar9,1);
      lVar5 = *(longlong *)(param_1 + 8);
      if (*(short *)(lVar5 + 0x88) == 0) {
        uVar8 = FUN_14167ab40(lVar5 + 0x58,0x146dacd70);
      }
      else {
        uVar8 = func_0x0001416799a0(lVar5 + 0x80);
      }
      FUN_1408614a0(uVar8);
    }
    uVar15 = _DAT_14382e13c;
    uVar28 = 0;
    uVar8 = CONCAT44(uVar27,_DAT_14382e13c);
    FUN_1415bae90(uVar9,afStackX_20,iVar10,0,uVar8,0);
    uVar27 = (undefined4)((ulonglong)uVar8 >> 0x20);
    uVar8 = func_0x0001415ad2a0(0x1473d0730,afStackX_20[0]);
    *(int *)(param_1 + 0x194) = iVar10;
    iVar4 = iVar10;
    if (((iVar10 == *(int *)(param_1 + 0x198)) && (DAT_145d9fe7c != '\0')) &&
       (DAT_145d9fe7e == '\0')) {
      fVar14 = (float)FUN_141d50d30(*(undefined8 *)(param_1 + 8),uVar8,0x3c146f44);
      if (fVar14 < 0.0) {
        fVar14 = fVar13;
      }
      iVar4 = *(int *)(param_1 + 0x194);
      *(float *)(param_1 + 0x1c4) = fVar14;
    }
  }
  if (iVar4 == *(int *)(param_1 + 0x198)) {
    cVar3 = FUN_1415bfc60(uVar9,_DAT_14382ee8c,0);
    bVar2 = false;
    if (cVar3 != '\0') goto LAB_140ab6c34;
  }
  else {
LAB_140ab6c34:
    bVar2 = true;
  }
  if ((*(int *)(param_1 + 0x270) == 0) && ((bVar2 || (*(char *)(param_1 + 0x274) != '\0')))) {
    uVar28 = 0;
    uVar8 = CONCAT44(uVar27,uVar15);
    FUN_1415bae90(uVar9,afStackX_20,*(undefined4 *)(param_1 + 0x1b4),0,uVar8,0);
    uVar27 = (undefined4)((ulonglong)uVar8 >> 0x20);
    *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(param_1 + 0x1b4);
    *(undefined1 *)(param_1 + 0x274) = 0;
  }
  FUN_1402d0740(&uStack_148,param_1 + 0x220);
  pfVar6 = (float *)FUN_141676930(param_1);
  uVar29 = _DAT_14382e160;
  fVar13 = (float)uStack_148;
  fVar24 = *(float *)(param_1 + 0x16c) - pfVar6[1];
  fVar20 = *(float *)(param_1 + 0x170) - pfVar6[2];
  fVar14 = fVar24 * uStack_148._4_4_ + (float)uStack_148 * (*pfVar1 - *pfVar6) + fStack_140 * fVar20
  ;
  fVar23 = (*pfVar1 - *pfVar6) - (float)uStack_148 * fVar14;
  fVar24 = fVar24 - fVar14 * uStack_148._4_4_;
  fVar20 = fVar20 - fStack_140 * fVar14;
  fVar14 = (float)((uint)fVar20 & _DAT_14382e160);
  if ((float)((uint)fVar20 & _DAT_14382e160) <= (float)((uint)fVar24 & _DAT_14382e160)) {
    fVar14 = (float)((uint)fVar24 & _DAT_14382e160);
  }
  if (fVar14 <= (float)((uint)fVar23 & _DAT_14382e160)) {
    fVar14 = (float)((uint)fVar23 & _DAT_14382e160);
  }
  if (0.0 < fVar14) {
    fVar14 = fVar17 / fVar14;
    fVar20 = fVar14 * fVar20;
    fVar23 = fVar14 * fVar23;
    fVar14 = fVar14 * fVar24;
    fVar21 = fVar17 / SQRT(fVar14 * fVar14 + fVar23 * fVar23 + fVar20 * fVar20);
    fVar23 = fVar21 * fVar23;
    fVar24 = fVar21 * fVar14;
    fVar20 = fVar21 * fVar20;
  }
  fVar14 = (float)((uint)fVar20 & _DAT_14382e160);
  if ((float)((uint)fVar20 & _DAT_14382e160) <= (float)((uint)fVar23 & _DAT_14382e160)) {
    fVar14 = (float)((uint)fVar23 & _DAT_14382e160);
  }
  fVar19 = fVar23 * (fVar17 / fVar14);
  fVar21 = fVar20 * (fVar17 / fVar14);
  fVar18 = 0.0;
  if (0.0 < fVar14) {
    fVar18 = SQRT(fVar21 * fVar21 + fVar19 * fVar19) * fVar14;
  }
  uVar12 = FUN_141c58560(fVar24,fVar18);
  afStackX_20[0] = (float)(uVar12 ^ _DAT_14382e890) - _DAT_14382e140;
  fVar14 = (float)((uint)((fVar17 - (float)((uint)uStack_148._4_4_ & uVar29)) * afStackX_20[0] -
                         _DAT_14382e134) & uVar29) * _DAT_143872ed0;
  if (fVar14 <= 0.0) {
    fVar14 = 0.0;
  }
  if (fVar17 <= fVar14) {
    fVar14 = fVar17;
  }
  fVar14 = (fVar17 - fVar14) * fVar22;
  if ((float)((uint)fVar13 ^ _DAT_14382e890) * fVar20 + fVar23 * fStack_140 <= 0.0) {
    fVar14 = fVar14 + fVar22;
  }
  else {
    fVar14 = fVar22 - fVar14;
  }
  uVar26 = CONCAT44(uVar28,_DAT_1438ad724);
  uVar8 = CONCAT44(uVar27,_DAT_14383ee38);
  uVar15 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x238),fVar14,param_1 + 0x240,_DAT_1438347a4,
                         uVar8,uVar26,param_2);
  uVar27 = (undefined4)((ulonglong)uVar8 >> 0x20);
  uVar28 = (undefined4)((ulonglong)uVar26 >> 0x20);
  *(undefined4 *)(param_1 + 0x238) = uVar15;
  FUN_1415c2c00(uVar9,0xf8d44865,uVar15);
  FUN_1415c2c00(uVar9,0x46434591,fVar17 - *(float *)(param_1 + 0x238));
  fVar13 = _DAT_14382e9ec;
  fVar14 = (fVar16 - _DAT_143861350) * _DAT_1438ad510;
  if (fVar14 <= 0.0) {
    fVar14 = 0.0;
  }
  if (fVar17 <= fVar14) {
    fVar14 = fVar17;
  }
  fVar14 = fVar17 - fVar14;
  fVar16 = fVar14;
  if ((*(float *)(param_1 + 0x27c) != _DAT_14382e9ec) &&
     (fVar16 = param_2 * _DAT_14382ee88 + *(float *)(param_1 + 0x27c), fVar16 <= fVar14)) {
    fVar16 = fVar14;
  }
  *(float *)(param_1 + 0x27c) = fVar16;
  FUN_1415c2c00(uVar9,0x14049a0b);
  FUN_1415c2c00(uVar9,0x5f118c92,fVar11);
  FUN_1415c2c00(uVar9,0xe47da57f,fVar11);
  FUN_1415c2c00(uVar9,0xb26c1350,fVar22);
  if (fVar13 == *(float *)(param_1 + 0x278)) {
    fVar13 = (*(float *)(param_1 + 0x218) - _DAT_14383ee38) * _DAT_1438ac384;
    if (fVar13 <= 0.0) {
      fVar13 = 0.0;
    }
    if (fVar17 <= fVar13) {
      fVar13 = fVar17;
    }
    *(float *)(param_1 + 0x278) = (fVar17 - fVar13) * _DAT_143836d08 + _DAT_14382e130;
    FUN_1415c2c00(uVar9,0x4668b2d4);
  }
  if (*(char *)(param_1 + 0xf0) == '\x01') {
    puVar7 = (undefined4 *)&DAT_147afdf10;
    if ((undefined4 *)**(undefined8 **)(param_1 + 8) != (undefined4 *)0x0) {
      puVar7 = (undefined4 *)**(undefined8 **)(param_1 + 8);
    }
    uStack_138 = *puVar7;
    uStack_134 = puVar7[1];
    uStack_130 = puVar7[2];
    uStack_128 = puVar7[5];
    uStack_12c = puVar7[4];
    uStack_120 = puVar7[8];
    uStack_124 = puVar7[6];
    uStack_118 = puVar7[10];
    uStack_11c = puVar7[9];
    FUN_1402e7060(afStack_110,&uStack_138);
    fVar14 = (float)FUN_141c58560(fVar23 * afStack_110[0] + fVar24 * fStack_104 + fVar20 * fStack_f8
                                  ,fVar23 * fStack_108 + fVar24 * fStack_fc + fVar20 * fStack_f0);
    fVar13 = afStackX_20[0] * _DAT_14383e6a4;
    if (fVar13 <= 0.0) {
      fVar13 = 0.0;
    }
    fVar14 = (fVar14 - _DAT_14382e140) * _DAT_14383e6a4;
    if (fVar17 <= fVar13) {
      fVar13 = fVar17;
    }
    if (fVar14 <= 0.0) {
      fVar14 = 0.0;
    }
    if (fVar17 <= fVar14) {
      fVar14 = fVar17;
    }
    FUN_1415c2c00(uVar9,0x9d1aea3d,fVar13);
    FUN_1415c2c00(uVar9,0x14c28d6c,fVar14);
  }
  fVar16 = (float)FUN_1420dc660(param_1);
  fVar14 = _DAT_1438627c8;
  fVar13 = _DAT_14382e120;
  fVar23 = (fVar16 - _DAT_14382e120) * _DAT_1438627c8;
  fVar16 = ((float)((uint)*(float *)(param_1 + 0x230) & uVar29) - _DAT_14382f0e0) * _DAT_1438929bc;
  if (fVar23 <= 0.0) {
    fVar23 = 0.0;
  }
  if (fVar16 <= 0.0) {
    fVar16 = 0.0;
  }
  if (fVar17 <= fVar23) {
    fVar23 = fVar17;
  }
  if (fVar17 <= fVar16) {
    fVar16 = fVar17;
  }
  if (0.0 <= *(float *)(param_1 + 0x230)) {
    fVar16 = fVar17 - fVar16 * fVar23;
  }
  else {
    fVar16 = fVar16 * fVar23 + fVar17;
  }
  uVar26 = CONCAT44(uVar28,_DAT_14382ee90);
  uVar8 = CONCAT44(uVar27,_DAT_143841320);
  uVar15 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x248),fVar16 * fVar22,param_1 + 0x24c,
                         _DAT_1438ac770,uVar8,uVar26,param_2);
  uVar27 = (undefined4)((ulonglong)uVar8 >> 0x20);
  uVar28 = (undefined4)((ulonglong)uVar26 >> 0x20);
  *(undefined4 *)(param_1 + 0x248) = uVar15;
  FUN_1415c2c00(uVar9,0x31b78a49,uVar15);
  fVar23 = (float)FUN_1420dc660(param_1);
  fVar16 = _DAT_14383fd4c;
  if ((fVar23 <= _DAT_14383fd4c) || (DAT_145d9fe7d == '\0')) {
    bVar2 = false;
LAB_140ab7267:
    if ((*(int *)(param_1 + 0x254) != 0) && (!bVar2)) {
      FUN_1415bf200(uVar9);
      *(int *)(param_1 + 0x254) = 0;
    }
  }
  else {
    bVar2 = true;
    if (*(int *)(param_1 + 0x254) != 0) goto LAB_140ab7267;
    uVar28 = 0;
    uVar8 = CONCAT44(uVar27,_DAT_14382e13c);
    FUN_1415bae90(uVar9,afStackX_20,*(undefined4 *)(param_1 + 0x1b0),1,uVar8,0);
    uVar27 = (undefined4)((ulonglong)uVar8 >> 0x20);
    *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x1b0);
  }
  fVar13 = (((float)(*(uint *)(param_1 + 0x230) & uVar29) -
            (float)(*(uint *)(param_1 + 0x234) & uVar29)) - _DAT_14382f0e0) * fVar13;
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  if (fVar17 <= fVar13) {
    fVar13 = fVar17;
  }
  fVar23 = (float)FUN_1420dc660(param_1);
  fVar14 = (fVar23 - fVar16) * fVar14;
  if (fVar14 <= 0.0) {
    fVar14 = 0.0;
  }
  if (fVar17 <= fVar14) {
    fVar14 = fVar17;
  }
  if (0.0 < *(float *)(param_1 + 0x230) || *(float *)(param_1 + 0x230) == 0.0) {
    fVar13 = fVar14 * fVar13 + fVar17;
  }
  else {
    fVar13 = fVar17 - fVar14 * fVar13;
  }
  fVar13 = fVar13 * fVar22;
  if ((float)((uint)(fVar13 - fVar22) & uVar29) <=
      (float)((uint)(*(float *)(param_1 + 600) - fVar22) & uVar29)) {
    fVar13 = (float)func_0x000141c477e0(*(float *)(param_1 + 600),fVar13,_DAT_14382f760,param_2);
  }
  uVar15 = _DAT_1438374ac;
  uVar26 = CONCAT44(uVar28,_DAT_1438388c4);
  uVar8 = CONCAT44(uVar27,_DAT_143841320);
  *(float *)(param_1 + 600) = fVar13;
  fVar14 = param_2;
  uVar15 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x260),fVar13,param_1 + 0x25c,uVar15,uVar8,uVar26
                         ,param_2);
  *(undefined4 *)(param_1 + 0x260) = uVar15;
  FUN_1415c2c00(uVar9,0x5dd56ddb,uVar15);
  pfVar25 = &fStack_114;
  pfVar6 = afStackX_20;
  FUN_140ab4450(pfVar1,param_1 + 0x134,param_1 + 0x220,auStack_e8,pfVar6,pfVar25,
                (uint)fVar14 & 0xffffff00);
  fVar14 = afStackX_20[0];
  fVar13 = _DAT_14384bc0c;
  uVar27 = (undefined4)((ulonglong)pfVar25 >> 0x20);
  uVar15 = (undefined4)((ulonglong)pfVar6 >> 0x20);
  if ((_DAT_143861350 <= fStack_114) || (_DAT_14384bc0c <= afStackX_20[0])) {
    bVar2 = false;
    if (*(int *)(param_1 + 0x264) == 0) goto LAB_140ab7491;
  }
  else {
    bVar2 = true;
    if (*(int *)(param_1 + 0x264) == 0) {
      lVar5 = *(longlong *)(param_1 + 8);
      if (*(short *)(lVar5 + 0x88) == 0) {
        lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146df2690);
      }
      else {
        lVar5 = func_0x0001416799a0(lVar5 + 0x80);
      }
      uVar28 = *(undefined4 *)(lVar5 + 0x1ac);
      uVar27 = 0;
      uVar8 = CONCAT44(uVar15,_DAT_14382e13c);
      *(undefined4 *)(param_1 + 0x264) = uVar28;
      FUN_1415bae90(uVar9,afStackX_20,uVar28,1,uVar8,0);
      uVar15 = (undefined4)((ulonglong)uVar8 >> 0x20);
      goto LAB_140ab7491;
    }
  }
  if (!bVar2) {
    FUN_1415bf200(uVar9);
    *(undefined4 *)(param_1 + 0x264) = 0;
  }
LAB_140ab7491:
  fVar16 = (fStack_114 - fVar13) * _DAT_14386dc70;
  fVar13 = ((float)((uint)fVar14 & uVar29) - _DAT_14382f2cc) * _DAT_14382ee88;
  if (fVar16 <= 0.0) {
    fVar16 = 0.0;
  }
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  if (fVar17 <= fVar16) {
    fVar16 = fVar17;
  }
  if (fVar17 <= fVar13) {
    fVar13 = fVar17;
  }
  fVar23 = *pfVar1 - (*(float *)(param_1 + 0x134) - *(float *)(param_1 + 0x124));
  fVar20 = *(float *)(param_1 + 0x170) - (*(float *)(param_1 + 0x13c) - *(float *)(param_1 + 300));
  fVar14 = (float)((uint)fVar20 & uVar29);
  if (fVar14 <= 0.0) {
    fVar14 = 0.0;
  }
  if (fVar14 <= (float)((uint)fVar23 & uVar29)) {
    fVar14 = (float)((uint)fVar23 & uVar29);
  }
  if (0.0 < fVar14) {
    fVar20 = (fVar17 / fVar14) * fVar20;
    fVar23 = (fVar17 / fVar14) * fVar23;
    fVar14 = fVar17 / SQRT(fVar20 * fVar20 + fVar23 * fVar23);
    fVar20 = fVar14 * fVar20;
    fVar23 = fVar14 * fVar23;
  }
  uStack_138 = *(undefined4 *)(param_1 + 0x104);
  uStack_134 = *(undefined4 *)(param_1 + 0x108);
  uStack_130 = *(undefined4 *)(param_1 + 0x10c);
  uStack_128 = *(undefined4 *)(param_1 + 0x118);
  uStack_12c = *(undefined4 *)(param_1 + 0x114);
  uStack_120 = *(undefined4 *)(param_1 + 0x124);
  uStack_124 = *(undefined4 *)(param_1 + 0x11c);
  uStack_118 = *(undefined4 *)(param_1 + 300);
  uStack_11c = *(undefined4 *)(param_1 + 0x128);
  FUN_1402e7060(afStack_110,&uStack_138);
  fVar23 = (float)FUN_141c58560(fVar23 * afStack_110[0] + fVar20 * fStack_f8,
                                fVar23 * fStack_108 + fVar20 * fStack_f0);
  fVar23 = fVar23 * _DAT_143830124;
  fVar14 = (_DAT_143840c90 - (float)((uint)fVar23 & uVar29)) * _DAT_1438ad510;
  if (fVar14 <= 0.0) {
    fVar14 = 0.0;
  }
  if (fVar17 <= fVar14) {
    fVar14 = fVar17;
  }
  fVar14 = (float)FUN_143666da0(fVar14,_DAT_1438a6094);
  if (fVar23 < 0.0) {
    fVar14 = (float)((uint)fVar14 ^ _DAT_14382e890);
  }
  fVar14 = (fVar17 - fVar16) * (fVar17 - fVar13) * fVar14;
  if (0.0 <= fVar14) {
    fVar22 = fVar22 - fVar14 * fVar22;
    if (fVar22 <= 0.0) {
      fVar22 = 0.0;
    }
  }
  else {
    fVar22 = ((float)((uint)fVar14 & uVar29) + fVar17) * fVar22;
  }
  uVar15 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x268),fVar22,param_1 + 0x26c,_DAT_1438ce978,
                         CONCAT44(uVar15,_DAT_143841320),CONCAT44(uVar27,_DAT_1438aa2a0),param_2);
  *(undefined4 *)(param_1 + 0x268) = uVar15;
  FUN_1415c2c00(uVar9,0x7f46ca87,uVar15);
  if (afStackX_18[0]._0_1_ != '\0') {
    FUN_1415c2670(uVar9,0,0);
    FUN_1415c28a0(uVar9,fVar11,0);
    if (*(int *)(param_1 + 0x254) != 0) {
      FUN_1415c2670(uVar9,0,2);
      FUN_1415c28a0(uVar9,fVar11,2);
    }
  }
  return;
}


/* SwingRegion_140ab67af @ 0x140ab67af */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab67af(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  float *pfVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  longlong in_RAX;
  longlong lVar6;
  undefined8 uVar7;
  float *pfVar8;
  undefined4 *puVar9;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined8 uVar26;
  undefined4 uVar27;
  longlong lStack0000000000000028;
  float fStack0000000000000040;
  float fStack0000000000000044;
  float in_stack_00000048;
  undefined4 uStack0000000000000050;
  undefined4 uStack0000000000000054;
  undefined4 uStack0000000000000058;
  undefined4 uStack000000000000005c;
  undefined4 uStack0000000000000060;
  undefined4 uStack0000000000000064;
  undefined4 uStack0000000000000068;
  undefined4 uStack000000000000006c;
  undefined4 uStack0000000000000070;
  float fStack0000000000000074;
  float in_stack_00000078;
  
  pfVar1 = (float *)(param_1 + 0x168);
  lVar6 = unaff_RBP + 0xa8;
  lStack0000000000000028 = in_RAX;
  FUN_140ab4450(pfVar1,param_1 + 0x134,param_3,&stack0x00000040,lVar6);
  uVar15 = _DAT_14384a1cc;
  fVar18 = _DAT_14382e9ec;
  uVar27 = (undefined4)((ulonglong)lVar6 >> 0x20);
  fVar23 = *(float *)(unaff_RBP + 0xa0);
  fVar13 = *(float *)(unaff_RBX + 0x1b8);
  if (*(float *)(unaff_RBX + 0x1b8) == _DAT_14382e9ec) {
    fVar13 = fVar23;
  }
  *(float *)(unaff_RBX + 0x1b8) = fVar13;
  uVar16 = func_0x000141c477e0(fVar13,fVar23,uVar15);
  fVar13 = _DAT_143840c90;
  fVar20 = (float)uVar16;
  *(float *)(unaff_RBX + 0x1b8) = fVar20;
  *(float *)(unaff_RBX + 0x1bc) = fVar13 - fVar20;
  *(undefined4 *)(unaff_RBX + 0x1c0) = *(undefined4 *)(unaff_RBP + 0xa8);
  fVar11 = (float)FUN_1420dc660();
  fVar23 = _DAT_14382e128;
  if ((fVar11 < _DAT_14382e128) && (fVar20 < _DAT_14382f0e0)) {
    lVar6 = *(longlong *)(unaff_RBX + 8);
    if (*(short *)(lVar6 + 0x88) == 0) {
      lVar6 = FUN_14167ab40(lVar6 + 0x58,0x146df2790);
    }
    else {
      lVar6 = func_0x0001416799a0(lVar6 + 0x80);
    }
    if (lVar6 != 0) {
      _fStack0000000000000040 = *(undefined8 *)(lVar6 + 0x438);
      in_stack_00000048 = *(float *)(lVar6 + 0x440);
      FUN_141676930();
      lStack0000000000000028 = unaff_RBP + 0xa0;
      lVar6 = unaff_RBP + 0xa8;
      FUN_140ab4450(&stack0x00000040,unaff_RBX + 0x134,unaff_RBX + 0x220,unaff_RBP + -0x60,lVar6);
      uVar27 = (undefined4)((ulonglong)lVar6 >> 0x20);
    }
  }
  lVar6 = *(longlong *)(unaff_RBX + 8);
  *(undefined1 *)(unaff_RBP + 0xa0) = 1;
  if (*(short *)(lVar6 + 0x88) == 0) {
    uVar7 = FUN_14167ab40(lVar6 + 0x58,0x1473d09e0);
  }
  else {
    uVar7 = func_0x0001416799a0(lVar6 + 0x80);
  }
  if ((*(char *)(unaff_RBX + 0xf0) == '\x01') &&
     (*(int *)(unaff_RBX + 0x194) == *(int *)(unaff_RBX + 0x198))) {
    fVar11 = (float)FUN_1415c09c0(uVar7,0);
    if ((*(int *)(unaff_RBX + 0x1a8) != 0) && (*(float *)(unaff_RBX + 0x1c4) <= fVar11)) {
      lStack0000000000000028 = 0;
      uVar26 = CONCAT44(uVar27,_DAT_14382e13c);
      FUN_1415bae90(uVar7,unaff_RBP + 0xa8,*(int *)(unaff_RBX + 0x1a8),0,uVar26);
      uVar27 = (undefined4)((ulonglong)uVar26 >> 0x20);
      *(undefined4 *)(unaff_RBX + 0x1c4) = 0x7149f2ca;
    }
    cVar4 = FUN_1415bfc60(uVar7,_DAT_14382ee88,0);
    if ((cVar4 != '\0') || (fVar20 < _DAT_143872d8c)) {
      FUN_1420df1c0(unaff_RBX + 0xf0,3);
    }
  }
  fVar24 = _DAT_14382e134;
  fVar11 = _DAT_14382dce0;
  fVar12 = 0.0;
  if (*(char *)(unaff_RBX + 0xf0) == '\x01') {
    iVar10 = *(int *)(unaff_RBX + 0x198);
    *(undefined1 *)(unaff_RBP + 0xa0) = 0;
  }
  else if (*(char *)(unaff_RBX + 0xf0) == '\a') {
    iVar10 = *(int *)(unaff_RBX + 0x200);
    *(undefined1 *)(unaff_RBP + 0xa0) = 0;
  }
  else {
    if (fVar20 <= _DAT_143861350) {
      uVar16 = func_0x00014041c590(uVar16,0,_DAT_143861350);
      fVar13 = (float)FUN_143666da0(uVar16,_DAT_143834a08);
      fVar12 = ((fVar11 - fVar13) * _DAT_1438ce970) / ((fVar13 + fVar11) * _DAT_1438388cc) + fVar24;
    }
    else {
      fVar13 = (float)func_0x00014041c590(uVar16,_DAT_143861350,fVar13);
      fVar12 = (float)FUN_143666da0(fVar11 - fVar13,_DAT_143834a08);
      fVar12 = fVar12 * fVar24;
    }
    fVar12 = fVar12 * _DAT_1438ce960;
    iVar10 = *(int *)(unaff_RBX + 0x1a0);
    if (fVar12 <= 0.0) {
      fVar12 = 0.0;
    }
    if (fVar11 <= fVar12) {
      fVar12 = fVar11;
    }
  }
  iVar5 = *(int *)(unaff_RBX + 0x194);
  uVar15 = _DAT_14382e13c;
  if (iVar10 != iVar5) {
    if (iVar5 == 0) {
      FUN_1415bf500(uVar7,0);
      FUN_1415bf500(uVar7,1);
      lVar6 = *(longlong *)(unaff_RBX + 8);
      if (*(short *)(lVar6 + 0x88) == 0) {
        uVar16 = FUN_14167ab40(lVar6 + 0x58,0x146dacd70);
      }
      else {
        uVar16 = func_0x0001416799a0(lVar6 + 0x80);
      }
      FUN_1408614a0(uVar16);
    }
    uVar15 = _DAT_14382e13c;
    lStack0000000000000028 = 0;
    uVar16 = CONCAT44(uVar27,_DAT_14382e13c);
    FUN_1415bae90(uVar7,unaff_RBP + 0xa8,iVar10,0,uVar16);
    uVar27 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar16 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0xa8));
    *(int *)(unaff_RBX + 0x194) = iVar10;
    iVar5 = iVar10;
    if (((iVar10 == *(int *)(unaff_RBX + 0x198)) && (DAT_145d9fe7c != '\0')) &&
       (DAT_145d9fe7e == '\0')) {
      fVar13 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8),uVar16,0x3c146f44);
      if (fVar13 < 0.0) {
        fVar13 = fVar18;
      }
      iVar5 = *(int *)(unaff_RBX + 0x194);
      *(float *)(unaff_RBX + 0x1c4) = fVar13;
    }
  }
  if (iVar5 == *(int *)(unaff_RBX + 0x198)) {
    cVar4 = FUN_1415bfc60(uVar7,_DAT_14382ee8c,0);
    bVar2 = false;
    if (cVar4 != '\0') goto LAB_140ab6c34;
  }
  else {
LAB_140ab6c34:
    bVar2 = true;
  }
  if ((*(int *)(unaff_RBX + 0x270) == 0) && ((bVar2 || (*(char *)(unaff_RBX + 0x274) != '\0')))) {
    lStack0000000000000028 = 0;
    uVar16 = CONCAT44(uVar27,uVar15);
    FUN_1415bae90(uVar7,unaff_RBP + 0xa8,*(undefined4 *)(unaff_RBX + 0x1b4),0,uVar16);
    uVar27 = (undefined4)((ulonglong)uVar16 >> 0x20);
    *(undefined4 *)(unaff_RBX + 0x270) = *(undefined4 *)(unaff_RBX + 0x1b4);
    *(undefined1 *)(unaff_RBX + 0x274) = 0;
  }
  FUN_1402d0740(&stack0x00000040,unaff_RBX + 0x220);
  pfVar8 = (float *)FUN_141676930();
  uVar3 = _DAT_14382e160;
  fVar13 = fStack0000000000000040;
  fVar25 = *(float *)(param_1 + 0x16c) - pfVar8[1];
  fVar21 = *(float *)(param_1 + 0x170) - pfVar8[2];
  fVar18 = fVar25 * fStack0000000000000044 + fStack0000000000000040 * (*pfVar1 - *pfVar8) +
           in_stack_00000048 * fVar21;
  fVar24 = (*pfVar1 - *pfVar8) - fStack0000000000000040 * fVar18;
  fVar25 = fVar25 - fVar18 * fStack0000000000000044;
  fVar21 = fVar21 - in_stack_00000048 * fVar18;
  fVar18 = (float)((uint)fVar21 & _DAT_14382e160);
  if ((float)((uint)fVar21 & _DAT_14382e160) <= (float)((uint)fVar25 & _DAT_14382e160)) {
    fVar18 = (float)((uint)fVar25 & _DAT_14382e160);
  }
  if (fVar18 <= (float)((uint)fVar24 & _DAT_14382e160)) {
    fVar18 = (float)((uint)fVar24 & _DAT_14382e160);
  }
  if (0.0 < fVar18) {
    fVar18 = fVar11 / fVar18;
    fVar21 = fVar18 * fVar21;
    fVar24 = fVar18 * fVar24;
    fVar18 = fVar18 * fVar25;
    fVar22 = fVar11 / SQRT(fVar18 * fVar18 + fVar24 * fVar24 + fVar21 * fVar21);
    fVar24 = fVar22 * fVar24;
    fVar25 = fVar22 * fVar18;
    fVar21 = fVar22 * fVar21;
  }
  fVar18 = (float)((uint)fVar21 & _DAT_14382e160);
  if ((float)((uint)fVar21 & _DAT_14382e160) <= (float)((uint)fVar24 & _DAT_14382e160)) {
    fVar18 = (float)((uint)fVar24 & _DAT_14382e160);
  }
  fVar19 = fVar24 * (fVar11 / fVar18);
  fVar22 = fVar21 * (fVar11 / fVar18);
  fVar17 = 0.0;
  if (0.0 < fVar18) {
    fVar17 = SQRT(fVar22 * fVar22 + fVar19 * fVar19) * fVar18;
  }
  uVar14 = FUN_141c58560(fVar25,fVar17);
  fVar13 = (float)((uint)fVar13 ^ _DAT_14382e890);
  fVar18 = (float)(uVar14 ^ _DAT_14382e890) - _DAT_14382e140;
  *(float *)(unaff_RBP + 0xa8) = fVar18;
  fVar18 = (float)((uint)((fVar11 - (float)((uint)fStack0000000000000044 & uVar3)) * fVar18 -
                         _DAT_14382e134) & uVar3) * _DAT_143872ed0;
  if (fVar18 <= 0.0) {
    fVar18 = 0.0;
  }
  if (fVar11 <= fVar18) {
    fVar18 = fVar11;
  }
  fVar18 = (fVar11 - fVar18) * fVar23;
  if (fVar13 * fVar21 + fVar24 * in_stack_00000048 <= 0.0) {
    fVar18 = fVar18 + fVar23;
  }
  else {
    fVar18 = fVar23 - fVar18;
  }
  fVar13 = *(float *)(unaff_RBP + 0x98);
  lStack0000000000000028 = CONCAT44(lStack0000000000000028._4_4_,_DAT_1438ad724);
  uVar16 = CONCAT44(uVar27,_DAT_14383ee38);
  uVar15 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x238),fVar18,unaff_RBX + 0x240,_DAT_1438347a4,
                         uVar16);
  uVar27 = (undefined4)((ulonglong)uVar16 >> 0x20);
  *(undefined4 *)(unaff_RBX + 0x238) = uVar15;
  FUN_1415c2c00(uVar7,0xf8d44865,uVar15);
  FUN_1415c2c00(uVar7,0x46434591,fVar11 - *(float *)(unaff_RBX + 0x238));
  fVar18 = _DAT_14382e9ec;
  fVar20 = (fVar20 - _DAT_143861350) * _DAT_1438ad510;
  if (fVar20 <= 0.0) {
    fVar20 = 0.0;
  }
  if (fVar11 <= fVar20) {
    fVar20 = fVar11;
  }
  fVar20 = fVar11 - fVar20;
  fVar22 = fVar20;
  if ((*(float *)(unaff_RBX + 0x27c) != _DAT_14382e9ec) &&
     (fVar22 = fVar13 * _DAT_14382ee88 + *(float *)(unaff_RBX + 0x27c), fVar22 <= fVar20)) {
    fVar22 = fVar20;
  }
  *(float *)(unaff_RBX + 0x27c) = fVar22;
  FUN_1415c2c00(uVar7,0x14049a0b);
  FUN_1415c2c00(uVar7,0x5f118c92,fVar12);
  FUN_1415c2c00(uVar7,0xe47da57f,fVar12);
  FUN_1415c2c00(uVar7,0xb26c1350,fVar23);
  if (fVar18 == *(float *)(unaff_RBX + 0x278)) {
    fVar18 = (*(float *)(unaff_RBX + 0x218) - _DAT_14383ee38) * _DAT_1438ac384;
    if (fVar18 <= 0.0) {
      fVar18 = 0.0;
    }
    if (fVar11 <= fVar18) {
      fVar18 = fVar11;
    }
    *(float *)(unaff_RBX + 0x278) = (fVar11 - fVar18) * _DAT_143836d08 + _DAT_14382e130;
    FUN_1415c2c00(uVar7,0x4668b2d4);
  }
  if (*(char *)(unaff_RBX + 0xf0) == '\x01') {
    puVar9 = (undefined4 *)&DAT_147afdf10;
    if ((undefined4 *)**(undefined8 **)(unaff_RBX + 8) != (undefined4 *)0x0) {
      puVar9 = (undefined4 *)**(undefined8 **)(unaff_RBX + 8);
    }
    uStack0000000000000050 = *puVar9;
    uStack0000000000000054 = puVar9[1];
    uStack0000000000000058 = puVar9[2];
    uStack0000000000000060 = puVar9[5];
    uStack000000000000005c = puVar9[4];
    uStack0000000000000068 = puVar9[8];
    uStack0000000000000064 = puVar9[6];
    uStack0000000000000070 = puVar9[10];
    uStack000000000000006c = puVar9[9];
    FUN_1402e7060(&stack0x00000078,&stack0x00000050);
    fVar20 = (float)FUN_141c58560(fVar24 * in_stack_00000078 +
                                  fVar25 * *(float *)(unaff_RBP + -0x7c) +
                                  fVar21 * *(float *)(unaff_RBP + -0x70),
                                  fVar24 * *(float *)(unaff_RBP + -0x80) +
                                  fVar25 * *(float *)(unaff_RBP + -0x74) +
                                  fVar21 * *(float *)(unaff_RBP + -0x68));
    fVar18 = *(float *)(unaff_RBP + 0xa8) * _DAT_14383e6a4;
    if (fVar18 <= 0.0) {
      fVar18 = 0.0;
    }
    fVar20 = (fVar20 - _DAT_14382e140) * _DAT_14383e6a4;
    if (fVar11 <= fVar18) {
      fVar18 = fVar11;
    }
    if (fVar20 <= 0.0) {
      fVar20 = 0.0;
    }
    if (fVar11 <= fVar20) {
      fVar20 = fVar11;
    }
    FUN_1415c2c00(uVar7,0x9d1aea3d,fVar18);
    FUN_1415c2c00(uVar7,0x14c28d6c,fVar20);
  }
  fVar24 = (float)FUN_1420dc660();
  fVar20 = _DAT_1438627c8;
  fVar18 = _DAT_14382e120;
  fVar21 = (fVar24 - _DAT_14382e120) * _DAT_1438627c8;
  fVar24 = ((float)((uint)*(float *)(unaff_RBX + 0x230) & uVar3) - _DAT_14382f0e0) * _DAT_1438929bc;
  if (fVar21 <= 0.0) {
    fVar21 = 0.0;
  }
  if (fVar24 <= 0.0) {
    fVar24 = 0.0;
  }
  if (fVar11 <= fVar21) {
    fVar21 = fVar11;
  }
  if (fVar11 <= fVar24) {
    fVar24 = fVar11;
  }
  if (0.0 <= *(float *)(unaff_RBX + 0x230)) {
    fVar24 = fVar11 - fVar24 * fVar21;
  }
  else {
    fVar24 = fVar24 * fVar21 + fVar11;
  }
  lStack0000000000000028 = CONCAT44(lStack0000000000000028._4_4_,_DAT_14382ee90);
  uVar16 = CONCAT44(uVar27,_DAT_143841320);
  uVar15 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x248),fVar24 * fVar23,unaff_RBX + 0x24c,
                         _DAT_1438ac770,uVar16);
  uVar27 = (undefined4)((ulonglong)uVar16 >> 0x20);
  *(undefined4 *)(unaff_RBX + 0x248) = uVar15;
  FUN_1415c2c00(uVar7,0x31b78a49,uVar15);
  fVar21 = (float)FUN_1420dc660();
  fVar24 = _DAT_14383fd4c;
  if ((fVar21 <= _DAT_14383fd4c) || (DAT_145d9fe7d == '\0')) {
    bVar2 = false;
LAB_140ab7267:
    if ((*(int *)(unaff_RBX + 0x254) != 0) && (!bVar2)) {
      FUN_1415bf200(uVar7);
      *(int *)(unaff_RBX + 0x254) = 0;
    }
  }
  else {
    bVar2 = true;
    if (*(int *)(unaff_RBX + 0x254) != 0) goto LAB_140ab7267;
    lStack0000000000000028 = 0;
    uVar16 = CONCAT44(uVar27,_DAT_14382e13c);
    FUN_1415bae90(uVar7,unaff_RBP + 0xa8,*(undefined4 *)(unaff_RBX + 0x1b0),1,uVar16);
    uVar27 = (undefined4)((ulonglong)uVar16 >> 0x20);
    *(int *)(unaff_RBX + 0x254) = *(int *)(unaff_RBX + 0x1b0);
  }
  fVar18 = (((float)(*(uint *)(unaff_RBX + 0x230) & uVar3) -
            (float)(*(uint *)(unaff_RBX + 0x234) & uVar3)) - _DAT_14382f0e0) * fVar18;
  if (fVar18 <= 0.0) {
    fVar18 = 0.0;
  }
  if (fVar11 <= fVar18) {
    fVar18 = fVar11;
  }
  fVar21 = (float)FUN_1420dc660();
  fVar20 = (fVar21 - fVar24) * fVar20;
  if (fVar20 <= 0.0) {
    fVar20 = 0.0;
  }
  if (fVar11 <= fVar20) {
    fVar20 = fVar11;
  }
  if (0.0 < *(float *)(unaff_RBX + 0x230) || *(float *)(unaff_RBX + 0x230) == 0.0) {
    fVar18 = fVar20 * fVar18 + fVar11;
  }
  else {
    fVar18 = fVar11 - fVar20 * fVar18;
  }
  fVar18 = fVar18 * fVar23;
  if ((float)((uint)(fVar18 - fVar23) & uVar3) <=
      (float)((uint)(*(float *)(unaff_RBX + 600) - fVar23) & uVar3)) {
    fVar18 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 600),fVar18,_DAT_14382f760,fVar13);
  }
  uVar15 = _DAT_1438374ac;
  lStack0000000000000028 = CONCAT44(lStack0000000000000028._4_4_,_DAT_1438388c4);
  uVar16 = CONCAT44(uVar27,_DAT_143841320);
  *(float *)(unaff_RBX + 600) = fVar18;
  uVar15 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x260),fVar18,unaff_RBX + 0x25c,uVar15,uVar16);
  *(undefined4 *)(unaff_RBX + 0x260) = uVar15;
  FUN_1415c2c00(uVar7,0x5dd56ddb,uVar15);
  lStack0000000000000028 = (longlong)&stack0x00000070 + 4;
  lVar6 = unaff_RBP + 0xa8;
  FUN_140ab4450(pfVar1,unaff_RBX + 0x134,unaff_RBX + 0x220,unaff_RBP + -0x60,lVar6);
  fVar18 = _DAT_14384bc0c;
  uVar15 = (undefined4)((ulonglong)lVar6 >> 0x20);
  fVar13 = *(float *)(unaff_RBP + 0xa8);
  if ((_DAT_143861350 <= fStack0000000000000074) || (_DAT_14384bc0c <= fVar13)) {
    bVar2 = false;
    if (*(int *)(unaff_RBX + 0x264) == 0) goto LAB_140ab7491;
  }
  else {
    bVar2 = true;
    if (*(int *)(unaff_RBX + 0x264) == 0) {
      lVar6 = *(longlong *)(unaff_RBX + 8);
      if (*(short *)(lVar6 + 0x88) == 0) {
        lVar6 = FUN_14167ab40(lVar6 + 0x58,0x146df2690);
      }
      else {
        lVar6 = func_0x0001416799a0(lVar6 + 0x80);
      }
      uVar27 = *(undefined4 *)(lVar6 + 0x1ac);
      lStack0000000000000028 = 0;
      uVar16 = CONCAT44(uVar15,_DAT_14382e13c);
      *(undefined4 *)(unaff_RBX + 0x264) = uVar27;
      FUN_1415bae90(uVar7,unaff_RBP + 0xa8,uVar27,1,uVar16);
      uVar15 = (undefined4)((ulonglong)uVar16 >> 0x20);
      goto LAB_140ab7491;
    }
  }
  if (!bVar2) {
    FUN_1415bf200(uVar7);
    *(undefined4 *)(unaff_RBX + 0x264) = 0;
  }
LAB_140ab7491:
  fVar18 = (fStack0000000000000074 - fVar18) * _DAT_14386dc70;
  fVar13 = ((float)((uint)fVar13 & uVar3) - _DAT_14382f2cc) * _DAT_14382ee88;
  if (fVar18 <= 0.0) {
    fVar18 = 0.0;
  }
  if (fVar13 <= 0.0) {
    fVar13 = 0.0;
  }
  if (fVar11 <= fVar18) {
    fVar18 = fVar11;
  }
  if (fVar11 <= fVar13) {
    fVar13 = fVar11;
  }
  fVar24 = *pfVar1 - (*(float *)(unaff_RBX + 0x134) - *(float *)(unaff_RBX + 0x124));
  fVar21 = *(float *)(param_1 + 0x170) -
           (*(float *)(unaff_RBX + 0x13c) - *(float *)(unaff_RBX + 300));
  fVar20 = (float)((uint)fVar21 & uVar3);
  if (fVar20 <= 0.0) {
    fVar20 = 0.0;
  }
  if (fVar20 <= (float)((uint)fVar24 & uVar3)) {
    fVar20 = (float)((uint)fVar24 & uVar3);
  }
  if (0.0 < fVar20) {
    fVar21 = (fVar11 / fVar20) * fVar21;
    fVar24 = (fVar11 / fVar20) * fVar24;
    fVar20 = fVar11 / SQRT(fVar21 * fVar21 + fVar24 * fVar24);
    fVar21 = fVar20 * fVar21;
    fVar24 = fVar20 * fVar24;
  }
  uStack0000000000000050 = *(undefined4 *)(unaff_RBX + 0x104);
  uStack0000000000000054 = *(undefined4 *)(unaff_RBX + 0x108);
  uStack0000000000000058 = *(undefined4 *)(unaff_RBX + 0x10c);
  uStack0000000000000060 = *(undefined4 *)(unaff_RBX + 0x118);
  uStack000000000000005c = *(undefined4 *)(unaff_RBX + 0x114);
  uStack0000000000000068 = *(undefined4 *)(unaff_RBX + 0x124);
  uStack0000000000000064 = *(undefined4 *)(unaff_RBX + 0x11c);
  uStack0000000000000070 = *(undefined4 *)(unaff_RBX + 300);
  uStack000000000000006c = *(undefined4 *)(unaff_RBX + 0x128);
  FUN_1402e7060(&stack0x00000078,&stack0x00000050);
  fVar24 = (float)FUN_141c58560(fVar24 * in_stack_00000078 + fVar21 * *(float *)(unaff_RBP + -0x70),
                                fVar24 * *(float *)(unaff_RBP + -0x80) +
                                fVar21 * *(float *)(unaff_RBP + -0x68));
  fVar24 = fVar24 * _DAT_143830124;
  fVar20 = (_DAT_143840c90 - (float)((uint)fVar24 & uVar3)) * _DAT_1438ad510;
  if (fVar20 <= 0.0) {
    fVar20 = 0.0;
  }
  if (fVar11 <= fVar20) {
    fVar20 = fVar11;
  }
  fVar20 = (float)FUN_143666da0(fVar20,_DAT_1438a6094);
  if (fVar24 < 0.0) {
    fVar20 = (float)((uint)fVar20 ^ _DAT_14382e890);
  }
  fVar20 = (fVar11 - fVar18) * (fVar11 - fVar13) * fVar20;
  if (0.0 <= fVar20) {
    fVar23 = fVar23 - fVar20 * fVar23;
    if (fVar23 <= 0.0) {
      fVar23 = 0.0;
    }
  }
  else {
    fVar23 = ((float)((uint)fVar20 & uVar3) + fVar11) * fVar23;
  }
  lStack0000000000000028 = CONCAT44(lStack0000000000000028._4_4_,_DAT_1438aa2a0);
  uVar15 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x268),fVar23,unaff_RBX + 0x26c,_DAT_1438ce978,
                         CONCAT44(uVar15,_DAT_143841320));
  *(undefined4 *)(unaff_RBX + 0x268) = uVar15;
  FUN_1415c2c00(uVar7,0x7f46ca87,uVar15);
  if (*(char *)(unaff_RBP + 0xa0) != '\0') {
    FUN_1415c2670(uVar7,0,0);
    FUN_1415c28a0(uVar7,fVar12,0);
    if (*(int *)(unaff_RBX + 0x254) != 0) {
      FUN_1415c2670(uVar7,0,2);
      FUN_1415c28a0(uVar7,fVar12,2);
    }
  }
  return;
}


/* SwingRegion_140ab67cd @ 0x140ab67cd */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab67cd(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  longlong in_RAX;
  longlong lVar5;
  undefined8 uVar6;
  float *pfVar7;
  undefined4 *puVar8;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int iVar9;
  float *unaff_R12;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined8 uVar25;
  undefined4 uVar26;
  longlong lStack0000000000000028;
  float fStack0000000000000040;
  float fStack0000000000000044;
  float in_stack_00000048;
  undefined4 uStack0000000000000050;
  undefined4 uStack0000000000000054;
  undefined4 uStack0000000000000058;
  undefined4 uStack000000000000005c;
  undefined4 uStack0000000000000060;
  undefined4 uStack0000000000000064;
  undefined4 uStack0000000000000068;
  undefined4 uStack000000000000006c;
  undefined4 uStack0000000000000070;
  float fStack0000000000000074;
  float in_stack_00000078;
  
  lVar5 = unaff_RBP + 0xa8;
  lStack0000000000000028 = in_RAX;
  FUN_140ab4450(param_1,param_2,param_3,&stack0x00000040,lVar5);
  uVar14 = _DAT_14384a1cc;
  fVar17 = _DAT_14382e9ec;
  uVar26 = (undefined4)((ulonglong)lVar5 >> 0x20);
  fVar22 = *(float *)(unaff_RBP + 0xa0);
  fVar12 = *(float *)(unaff_RBX + 0x1b8);
  if (*(float *)(unaff_RBX + 0x1b8) == _DAT_14382e9ec) {
    fVar12 = fVar22;
  }
  *(float *)(unaff_RBX + 0x1b8) = fVar12;
  uVar15 = func_0x000141c477e0(fVar12,fVar22,uVar14);
  fVar12 = _DAT_143840c90;
  fVar19 = (float)uVar15;
  *(float *)(unaff_RBX + 0x1b8) = fVar19;
  *(float *)(unaff_RBX + 0x1bc) = fVar12 - fVar19;
  *(undefined4 *)(unaff_RBX + 0x1c0) = *(undefined4 *)(unaff_RBP + 0xa8);
  fVar10 = (float)FUN_1420dc660();
  fVar22 = _DAT_14382e128;
  if ((fVar10 < _DAT_14382e128) && (fVar19 < _DAT_14382f0e0)) {
    lVar5 = *(longlong *)(unaff_RBX + 8);
    if (*(short *)(lVar5 + 0x88) == 0) {
      lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146df2790);
    }
    else {
      lVar5 = func_0x0001416799a0(lVar5 + 0x80);
    }
    if (lVar5 != 0) {
      _fStack0000000000000040 = *(undefined8 *)(lVar5 + 0x438);
      in_stack_00000048 = *(float *)(lVar5 + 0x440);
      FUN_141676930();
      lStack0000000000000028 = unaff_RBP + 0xa0;
      lVar5 = unaff_RBP + 0xa8;
      FUN_140ab4450(&stack0x00000040,unaff_RBX + 0x134,unaff_RBX + 0x220,unaff_RBP + -0x60,lVar5);
      uVar26 = (undefined4)((ulonglong)lVar5 >> 0x20);
    }
  }
  lVar5 = *(longlong *)(unaff_RBX + 8);
  *(undefined1 *)(unaff_RBP + 0xa0) = 1;
  if (*(short *)(lVar5 + 0x88) == 0) {
    uVar6 = FUN_14167ab40(lVar5 + 0x58,0x1473d09e0);
  }
  else {
    uVar6 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if ((*(char *)(unaff_RBX + 0xf0) == '\x01') &&
     (*(int *)(unaff_RBX + 0x194) == *(int *)(unaff_RBX + 0x198))) {
    fVar10 = (float)FUN_1415c09c0(uVar6,0);
    if ((*(int *)(unaff_RBX + 0x1a8) != 0) && (*(float *)(unaff_RBX + 0x1c4) <= fVar10)) {
      lStack0000000000000028 = 0;
      uVar25 = CONCAT44(uVar26,_DAT_14382e13c);
      FUN_1415bae90(uVar6,unaff_RBP + 0xa8,*(int *)(unaff_RBX + 0x1a8),0,uVar25);
      uVar26 = (undefined4)((ulonglong)uVar25 >> 0x20);
      *(undefined4 *)(unaff_RBX + 0x1c4) = 0x7149f2ca;
    }
    cVar3 = FUN_1415bfc60(uVar6,_DAT_14382ee88,0);
    if ((cVar3 != '\0') || (fVar19 < _DAT_143872d8c)) {
      FUN_1420df1c0(unaff_RBX + 0xf0,3);
    }
  }
  fVar23 = _DAT_14382e134;
  fVar10 = _DAT_14382dce0;
  fVar11 = 0.0;
  if (*(char *)(unaff_RBX + 0xf0) == '\x01') {
    iVar9 = *(int *)(unaff_RBX + 0x198);
    *(undefined1 *)(unaff_RBP + 0xa0) = 0;
  }
  else if (*(char *)(unaff_RBX + 0xf0) == '\a') {
    iVar9 = *(int *)(unaff_RBX + 0x200);
    *(undefined1 *)(unaff_RBP + 0xa0) = 0;
  }
  else {
    if (fVar19 <= _DAT_143861350) {
      uVar15 = func_0x00014041c590(uVar15,0,_DAT_143861350);
      fVar12 = (float)FUN_143666da0(uVar15,_DAT_143834a08);
      fVar11 = ((fVar10 - fVar12) * _DAT_1438ce970) / ((fVar12 + fVar10) * _DAT_1438388cc) + fVar23;
    }
    else {
      fVar12 = (float)func_0x00014041c590(uVar15,_DAT_143861350,fVar12);
      fVar11 = (float)FUN_143666da0(fVar10 - fVar12,_DAT_143834a08);
      fVar11 = fVar11 * fVar23;
    }
    fVar11 = fVar11 * _DAT_1438ce960;
    iVar9 = *(int *)(unaff_RBX + 0x1a0);
    if (fVar11 <= 0.0) {
      fVar11 = 0.0;
    }
    if (fVar10 <= fVar11) {
      fVar11 = fVar10;
    }
  }
  iVar4 = *(int *)(unaff_RBX + 0x194);
  uVar14 = _DAT_14382e13c;
  if (iVar9 != iVar4) {
    if (iVar4 == 0) {
      FUN_1415bf500(uVar6,0);
      FUN_1415bf500(uVar6,1);
      lVar5 = *(longlong *)(unaff_RBX + 8);
      if (*(short *)(lVar5 + 0x88) == 0) {
        uVar15 = FUN_14167ab40(lVar5 + 0x58,0x146dacd70);
      }
      else {
        uVar15 = func_0x0001416799a0(lVar5 + 0x80);
      }
      FUN_1408614a0(uVar15);
    }
    uVar14 = _DAT_14382e13c;
    lStack0000000000000028 = 0;
    uVar15 = CONCAT44(uVar26,_DAT_14382e13c);
    FUN_1415bae90(uVar6,unaff_RBP + 0xa8,iVar9,0,uVar15);
    uVar26 = (undefined4)((ulonglong)uVar15 >> 0x20);
    uVar15 = func_0x0001415ad2a0(0x1473d0730,*(undefined4 *)(unaff_RBP + 0xa8));
    *(int *)(unaff_RBX + 0x194) = iVar9;
    iVar4 = iVar9;
    if (((iVar9 == *(int *)(unaff_RBX + 0x198)) && (DAT_145d9fe7c != '\0')) &&
       (DAT_145d9fe7e == '\0')) {
      fVar12 = (float)FUN_141d50d30(*(undefined8 *)(unaff_RBX + 8),uVar15,0x3c146f44);
      if (fVar12 < 0.0) {
        fVar12 = fVar17;
      }
      iVar4 = *(int *)(unaff_RBX + 0x194);
      *(float *)(unaff_RBX + 0x1c4) = fVar12;
    }
  }
  if (iVar4 == *(int *)(unaff_RBX + 0x198)) {
    cVar3 = FUN_1415bfc60(uVar6,_DAT_14382ee8c,0);
    bVar1 = false;
    if (cVar3 != '\0') goto LAB_140ab6c34;
  }
  else {
LAB_140ab6c34:
    bVar1 = true;
  }
  if ((*(int *)(unaff_RBX + 0x270) == 0) && ((bVar1 || (*(char *)(unaff_RBX + 0x274) != '\0')))) {
    lStack0000000000000028 = 0;
    uVar15 = CONCAT44(uVar26,uVar14);
    FUN_1415bae90(uVar6,unaff_RBP + 0xa8,*(undefined4 *)(unaff_RBX + 0x1b4),0,uVar15);
    uVar26 = (undefined4)((ulonglong)uVar15 >> 0x20);
    *(undefined4 *)(unaff_RBX + 0x270) = *(undefined4 *)(unaff_RBX + 0x1b4);
    *(undefined1 *)(unaff_RBX + 0x274) = 0;
  }
  FUN_1402d0740(&stack0x00000040,unaff_RBX + 0x220);
  pfVar7 = (float *)FUN_141676930();
  uVar2 = _DAT_14382e160;
  fVar12 = fStack0000000000000040;
  fVar17 = (unaff_R12[1] - pfVar7[1]) * fStack0000000000000044 +
           fStack0000000000000040 * (*unaff_R12 - *pfVar7) +
           in_stack_00000048 * (unaff_R12[2] - pfVar7[2]);
  fVar23 = (*unaff_R12 - *pfVar7) - fStack0000000000000040 * fVar17;
  fVar24 = (unaff_R12[1] - pfVar7[1]) - fVar17 * fStack0000000000000044;
  fVar20 = (unaff_R12[2] - pfVar7[2]) - in_stack_00000048 * fVar17;
  fVar17 = (float)((uint)fVar20 & _DAT_14382e160);
  if ((float)((uint)fVar20 & _DAT_14382e160) <= (float)((uint)fVar24 & _DAT_14382e160)) {
    fVar17 = (float)((uint)fVar24 & _DAT_14382e160);
  }
  if (fVar17 <= (float)((uint)fVar23 & _DAT_14382e160)) {
    fVar17 = (float)((uint)fVar23 & _DAT_14382e160);
  }
  if (0.0 < fVar17) {
    fVar17 = fVar10 / fVar17;
    fVar20 = fVar17 * fVar20;
    fVar23 = fVar17 * fVar23;
    fVar17 = fVar17 * fVar24;
    fVar21 = fVar10 / SQRT(fVar17 * fVar17 + fVar23 * fVar23 + fVar20 * fVar20);
    fVar23 = fVar21 * fVar23;
    fVar24 = fVar21 * fVar17;
    fVar20 = fVar21 * fVar20;
  }
  fVar17 = (float)((uint)fVar20 & _DAT_14382e160);
  if ((float)((uint)fVar20 & _DAT_14382e160) <= (float)((uint)fVar23 & _DAT_14382e160)) {
    fVar17 = (float)((uint)fVar23 & _DAT_14382e160);
  }
  fVar18 = fVar23 * (fVar10 / fVar17);
  fVar21 = fVar20 * (fVar10 / fVar17);
  fVar16 = 0.0;
  if (0.0 < fVar17) {
    fVar16 = SQRT(fVar21 * fVar21 + fVar18 * fVar18) * fVar17;
  }
  uVar13 = FUN_141c58560(fVar24,fVar16);
  fVar12 = (float)((uint)fVar12 ^ _DAT_14382e890);
  fVar17 = (float)(uVar13 ^ _DAT_14382e890) - _DAT_14382e140;
  *(float *)(unaff_RBP + 0xa8) = fVar17;
  fVar17 = (float)((uint)((fVar10 - (float)((uint)fStack0000000000000044 & uVar2)) * fVar17 -
                         _DAT_14382e134) & uVar2) * _DAT_143872ed0;
  if (fVar17 <= 0.0) {
    fVar17 = 0.0;
  }
  if (fVar10 <= fVar17) {
    fVar17 = fVar10;
  }
  fVar17 = (fVar10 - fVar17) * fVar22;
  if (fVar12 * fVar20 + fVar23 * in_stack_00000048 <= 0.0) {
    fVar17 = fVar17 + fVar22;
  }
  else {
    fVar17 = fVar22 - fVar17;
  }
  fVar12 = *(float *)(unaff_RBP + 0x98);
  lStack0000000000000028 = CONCAT44(lStack0000000000000028._4_4_,_DAT_1438ad724);
  uVar15 = CONCAT44(uVar26,_DAT_14383ee38);
  uVar14 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x238),fVar17,unaff_RBX + 0x240,_DAT_1438347a4,
                         uVar15);
  uVar26 = (undefined4)((ulonglong)uVar15 >> 0x20);
  *(undefined4 *)(unaff_RBX + 0x238) = uVar14;
  FUN_1415c2c00(uVar6,0xf8d44865,uVar14);
  FUN_1415c2c00(uVar6,0x46434591,fVar10 - *(float *)(unaff_RBX + 0x238));
  fVar17 = _DAT_14382e9ec;
  fVar19 = (fVar19 - _DAT_143861350) * _DAT_1438ad510;
  if (fVar19 <= 0.0) {
    fVar19 = 0.0;
  }
  if (fVar10 <= fVar19) {
    fVar19 = fVar10;
  }
  fVar19 = fVar10 - fVar19;
  fVar21 = fVar19;
  if ((*(float *)(unaff_RBX + 0x27c) != _DAT_14382e9ec) &&
     (fVar21 = fVar12 * _DAT_14382ee88 + *(float *)(unaff_RBX + 0x27c), fVar21 <= fVar19)) {
    fVar21 = fVar19;
  }
  *(float *)(unaff_RBX + 0x27c) = fVar21;
  FUN_1415c2c00(uVar6,0x14049a0b);
  FUN_1415c2c00(uVar6,0x5f118c92,fVar11);
  FUN_1415c2c00(uVar6,0xe47da57f,fVar11);
  FUN_1415c2c00(uVar6,0xb26c1350,fVar22);
  if (fVar17 == *(float *)(unaff_RBX + 0x278)) {
    fVar17 = (*(float *)(unaff_RBX + 0x218) - _DAT_14383ee38) * _DAT_1438ac384;
    if (fVar17 <= 0.0) {
      fVar17 = 0.0;
    }
    if (fVar10 <= fVar17) {
      fVar17 = fVar10;
    }
    *(float *)(unaff_RBX + 0x278) = (fVar10 - fVar17) * _DAT_143836d08 + _DAT_14382e130;
    FUN_1415c2c00(uVar6,0x4668b2d4);
  }
  if (*(char *)(unaff_RBX + 0xf0) == '\x01') {
    puVar8 = (undefined4 *)&DAT_147afdf10;
    if ((undefined4 *)**(undefined8 **)(unaff_RBX + 8) != (undefined4 *)0x0) {
      puVar8 = (undefined4 *)**(undefined8 **)(unaff_RBX + 8);
    }
    uStack0000000000000050 = *puVar8;
    uStack0000000000000054 = puVar8[1];
    uStack0000000000000058 = puVar8[2];
    uStack0000000000000060 = puVar8[5];
    uStack000000000000005c = puVar8[4];
    uStack0000000000000068 = puVar8[8];
    uStack0000000000000064 = puVar8[6];
    uStack0000000000000070 = puVar8[10];
    uStack000000000000006c = puVar8[9];
    FUN_1402e7060(&stack0x00000078,&stack0x00000050);
    fVar19 = (float)FUN_141c58560(fVar23 * in_stack_00000078 +
                                  fVar24 * *(float *)(unaff_RBP + -0x7c) +
                                  fVar20 * *(float *)(unaff_RBP + -0x70),
                                  fVar23 * *(float *)(unaff_RBP + -0x80) +
                                  fVar24 * *(float *)(unaff_RBP + -0x74) +
                                  fVar20 * *(float *)(unaff_RBP + -0x68));
    fVar17 = *(float *)(unaff_RBP + 0xa8) * _DAT_14383e6a4;
    if (fVar17 <= 0.0) {
      fVar17 = 0.0;
    }
    fVar19 = (fVar19 - _DAT_14382e140) * _DAT_14383e6a4;
    if (fVar10 <= fVar17) {
      fVar17 = fVar10;
    }
    if (fVar19 <= 0.0) {
      fVar19 = 0.0;
    }
    if (fVar10 <= fVar19) {
      fVar19 = fVar10;
    }
    FUN_1415c2c00(uVar6,0x9d1aea3d,fVar17);
    FUN_1415c2c00(uVar6,0x14c28d6c,fVar19);
  }
  fVar23 = (float)FUN_1420dc660();
  fVar19 = _DAT_1438627c8;
  fVar17 = _DAT_14382e120;
  fVar20 = (fVar23 - _DAT_14382e120) * _DAT_1438627c8;
  fVar23 = ((float)((uint)*(float *)(unaff_RBX + 0x230) & uVar2) - _DAT_14382f0e0) * _DAT_1438929bc;
  if (fVar20 <= 0.0) {
    fVar20 = 0.0;
  }
  if (fVar23 <= 0.0) {
    fVar23 = 0.0;
  }
  if (fVar10 <= fVar20) {
    fVar20 = fVar10;
  }
  if (fVar10 <= fVar23) {
    fVar23 = fVar10;
  }
  if (0.0 <= *(float *)(unaff_RBX + 0x230)) {
    fVar23 = fVar10 - fVar23 * fVar20;
  }
  else {
    fVar23 = fVar23 * fVar20 + fVar10;
  }
  lStack0000000000000028 = CONCAT44(lStack0000000000000028._4_4_,_DAT_14382ee90);
  uVar15 = CONCAT44(uVar26,_DAT_143841320);
  uVar14 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x248),fVar23 * fVar22,unaff_RBX + 0x24c,
                         _DAT_1438ac770,uVar15);
  uVar26 = (undefined4)((ulonglong)uVar15 >> 0x20);
  *(undefined4 *)(unaff_RBX + 0x248) = uVar14;
  FUN_1415c2c00(uVar6,0x31b78a49,uVar14);
  fVar20 = (float)FUN_1420dc660();
  fVar23 = _DAT_14383fd4c;
  if ((fVar20 <= _DAT_14383fd4c) || (DAT_145d9fe7d == '\0')) {
    bVar1 = false;
LAB_140ab7267:
    if ((*(int *)(unaff_RBX + 0x254) != 0) && (!bVar1)) {
      FUN_1415bf200(uVar6);
      *(int *)(unaff_RBX + 0x254) = 0;
    }
  }
  else {
    bVar1 = true;
    if (*(int *)(unaff_RBX + 0x254) != 0) goto LAB_140ab7267;
    lStack0000000000000028 = 0;
    uVar15 = CONCAT44(uVar26,_DAT_14382e13c);
    FUN_1415bae90(uVar6,unaff_RBP + 0xa8,*(undefined4 *)(unaff_RBX + 0x1b0),1,uVar15);
    uVar26 = (undefined4)((ulonglong)uVar15 >> 0x20);
    *(int *)(unaff_RBX + 0x254) = *(int *)(unaff_RBX + 0x1b0);
  }
  fVar17 = (((float)(*(uint *)(unaff_RBX + 0x230) & uVar2) -
            (float)(*(uint *)(unaff_RBX + 0x234) & uVar2)) - _DAT_14382f0e0) * fVar17;
  if (fVar17 <= 0.0) {
    fVar17 = 0.0;
  }
  if (fVar10 <= fVar17) {
    fVar17 = fVar10;
  }
  fVar20 = (float)FUN_1420dc660();
  fVar19 = (fVar20 - fVar23) * fVar19;
  if (fVar19 <= 0.0) {
    fVar19 = 0.0;
  }
  if (fVar10 <= fVar19) {
    fVar19 = fVar10;
  }
  if (0.0 < *(float *)(unaff_RBX + 0x230) || *(float *)(unaff_RBX + 0x230) == 0.0) {
    fVar17 = fVar19 * fVar17 + fVar10;
  }
  else {
    fVar17 = fVar10 - fVar19 * fVar17;
  }
  fVar17 = fVar17 * fVar22;
  if ((float)((uint)(fVar17 - fVar22) & uVar2) <=
      (float)((uint)(*(float *)(unaff_RBX + 600) - fVar22) & uVar2)) {
    fVar17 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 600),fVar17,_DAT_14382f760,fVar12);
  }
  uVar14 = _DAT_1438374ac;
  lStack0000000000000028 = CONCAT44(lStack0000000000000028._4_4_,_DAT_1438388c4);
  uVar15 = CONCAT44(uVar26,_DAT_143841320);
  *(float *)(unaff_RBX + 600) = fVar17;
  uVar14 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x260),fVar17,unaff_RBX + 0x25c,uVar14,uVar15);
  *(undefined4 *)(unaff_RBX + 0x260) = uVar14;
  uVar15 = FUN_1415c2c00(uVar6,0x5dd56ddb,uVar14);
  lStack0000000000000028 = (longlong)&stack0x00000070 + 4;
  lVar5 = unaff_RBP + 0xa8;
  FUN_140ab4450(uVar15,unaff_RBX + 0x134,unaff_RBX + 0x220,unaff_RBP + -0x60,lVar5);
  fVar17 = _DAT_14384bc0c;
  uVar14 = (undefined4)((ulonglong)lVar5 >> 0x20);
  fVar12 = *(float *)(unaff_RBP + 0xa8);
  if ((_DAT_143861350 <= fStack0000000000000074) || (_DAT_14384bc0c <= fVar12)) {
    bVar1 = false;
    if (*(int *)(unaff_RBX + 0x264) == 0) goto LAB_140ab7491;
  }
  else {
    bVar1 = true;
    if (*(int *)(unaff_RBX + 0x264) == 0) {
      lVar5 = *(longlong *)(unaff_RBX + 8);
      if (*(short *)(lVar5 + 0x88) == 0) {
        lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146df2690);
      }
      else {
        lVar5 = func_0x0001416799a0(lVar5 + 0x80);
      }
      uVar26 = *(undefined4 *)(lVar5 + 0x1ac);
      lStack0000000000000028 = 0;
      uVar15 = CONCAT44(uVar14,_DAT_14382e13c);
      *(undefined4 *)(unaff_RBX + 0x264) = uVar26;
      FUN_1415bae90(uVar6,unaff_RBP + 0xa8,uVar26,1,uVar15);
      uVar14 = (undefined4)((ulonglong)uVar15 >> 0x20);
      goto LAB_140ab7491;
    }
  }
  if (!bVar1) {
    FUN_1415bf200(uVar6);
    *(undefined4 *)(unaff_RBX + 0x264) = 0;
  }
LAB_140ab7491:
  fVar17 = (fStack0000000000000074 - fVar17) * _DAT_14386dc70;
  fVar12 = ((float)((uint)fVar12 & uVar2) - _DAT_14382f2cc) * _DAT_14382ee88;
  if (fVar17 <= 0.0) {
    fVar17 = 0.0;
  }
  if (fVar12 <= 0.0) {
    fVar12 = 0.0;
  }
  if (fVar10 <= fVar17) {
    fVar17 = fVar10;
  }
  if (fVar10 <= fVar12) {
    fVar12 = fVar10;
  }
  fVar23 = *unaff_R12 - (*(float *)(unaff_RBX + 0x134) - *(float *)(unaff_RBX + 0x124));
  fVar20 = unaff_R12[2] - (*(float *)(unaff_RBX + 0x13c) - *(float *)(unaff_RBX + 300));
  fVar19 = (float)((uint)fVar20 & uVar2);
  if (fVar19 <= 0.0) {
    fVar19 = 0.0;
  }
  if (fVar19 <= (float)((uint)fVar23 & uVar2)) {
    fVar19 = (float)((uint)fVar23 & uVar2);
  }
  if (0.0 < fVar19) {
    fVar20 = (fVar10 / fVar19) * fVar20;
    fVar23 = (fVar10 / fVar19) * fVar23;
    fVar19 = fVar10 / SQRT(fVar20 * fVar20 + fVar23 * fVar23);
    fVar20 = fVar19 * fVar20;
    fVar23 = fVar19 * fVar23;
  }
  uStack0000000000000050 = *(undefined4 *)(unaff_RBX + 0x104);
  uStack0000000000000054 = *(undefined4 *)(unaff_RBX + 0x108);
  uStack0000000000000058 = *(undefined4 *)(unaff_RBX + 0x10c);
  uStack0000000000000060 = *(undefined4 *)(unaff_RBX + 0x118);
  uStack000000000000005c = *(undefined4 *)(unaff_RBX + 0x114);
  uStack0000000000000068 = *(undefined4 *)(unaff_RBX + 0x124);
  uStack0000000000000064 = *(undefined4 *)(unaff_RBX + 0x11c);
  uStack0000000000000070 = *(undefined4 *)(unaff_RBX + 300);
  uStack000000000000006c = *(undefined4 *)(unaff_RBX + 0x128);
  FUN_1402e7060(&stack0x00000078,&stack0x00000050);
  fVar23 = (float)FUN_141c58560(fVar23 * in_stack_00000078 + fVar20 * *(float *)(unaff_RBP + -0x70),
                                fVar23 * *(float *)(unaff_RBP + -0x80) +
                                fVar20 * *(float *)(unaff_RBP + -0x68));
  fVar23 = fVar23 * _DAT_143830124;
  fVar19 = (_DAT_143840c90 - (float)((uint)fVar23 & uVar2)) * _DAT_1438ad510;
  if (fVar19 <= 0.0) {
    fVar19 = 0.0;
  }
  if (fVar10 <= fVar19) {
    fVar19 = fVar10;
  }
  fVar19 = (float)FUN_143666da0(fVar19,_DAT_1438a6094);
  if (fVar23 < 0.0) {
    fVar19 = (float)((uint)fVar19 ^ _DAT_14382e890);
  }
  fVar19 = (fVar10 - fVar17) * (fVar10 - fVar12) * fVar19;
  if (0.0 <= fVar19) {
    fVar22 = fVar22 - fVar19 * fVar22;
    if (fVar22 <= 0.0) {
      fVar22 = 0.0;
    }
  }
  else {
    fVar22 = ((float)((uint)fVar19 & uVar2) + fVar10) * fVar22;
  }
  lStack0000000000000028 = CONCAT44(lStack0000000000000028._4_4_,_DAT_1438aa2a0);
  uVar14 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x268),fVar22,unaff_RBX + 0x26c,_DAT_1438ce978,
                         CONCAT44(uVar14,_DAT_143841320));
  *(undefined4 *)(unaff_RBX + 0x268) = uVar14;
  FUN_1415c2c00(uVar6,0x7f46ca87,uVar14);
  if (*(char *)(unaff_RBP + 0xa0) != '\0') {
    FUN_1415c2670(uVar6,0,0);
    FUN_1415c28a0(uVar6,fVar11,0);
    if (*(int *)(unaff_RBX + 0x254) != 0) {
      FUN_1415c2670(uVar6,0,2);
      FUN_1415c28a0(uVar6,fVar11,2);
    }
  }
  return;
}


/* SwingRegion_140ab72e3 @ 0x140ab72e3 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab72e3(float param_1)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int *unaff_RSI;
  float *unaff_R12;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM11_Da;
  float fVar9;
  float fVar10;
  uint unaff_XMM13_Da;
  undefined8 in_stack_00000020;
  undefined8 uVar11;
  undefined4 in_stack_00000050;
  undefined4 uStack0000000000000054;
  undefined4 in_stack_00000058;
  undefined4 uStack000000000000005c;
  undefined4 in_stack_00000060;
  undefined4 uStack0000000000000064;
  undefined4 in_stack_00000068;
  undefined4 uStack000000000000006c;
  undefined4 uStack0000000000000070;
  float fStack0000000000000074;
  float in_stack_00000078;
  
  uVar5 = (undefined4)((ulonglong)in_stack_00000020 >> 0x20);
  fVar6 = (unaff_XMM8_Da - param_1) * unaff_XMM11_Da;
  if ((float)((uint)(fVar6 - unaff_XMM11_Da) & unaff_XMM13_Da) <=
      (float)((uint)(*(float *)(unaff_RBX + 600) - unaff_XMM11_Da) & unaff_XMM13_Da)) {
    fVar6 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 600),fVar6,_DAT_14382f760);
  }
  uVar1 = _DAT_1438374ac;
  uVar11 = CONCAT44(uVar5,_DAT_143841320);
  *(float *)(unaff_RBX + 600) = fVar6;
  uVar5 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x260),fVar6,unaff_RBX + 0x25c,uVar1,uVar11);
  *(undefined4 *)(unaff_RBX + 0x260) = uVar5;
  uVar5 = FUN_1415c2c00(uVar5,0x5dd56ddb,uVar5);
  lVar4 = unaff_RBP + 0xa8;
  FUN_140ab4450(uVar5,unaff_RBX + 0x134,unaff_RBX + 0x220,unaff_RBP + -0x60,lVar4);
  fVar9 = _DAT_14384bc0c;
  uVar5 = (undefined4)((ulonglong)lVar4 >> 0x20);
  fVar6 = *(float *)(unaff_RBP + 0xa8);
  if ((_DAT_143861350 <= fStack0000000000000074) || (_DAT_14384bc0c <= fVar6)) {
    bVar2 = false;
    if (*(int *)(unaff_RBX + 0x264) == 0) goto LAB_140ab7491;
  }
  else {
    bVar2 = true;
    if (*(int *)(unaff_RBX + 0x264) == 0) {
      lVar4 = *(longlong *)(unaff_RBX + 8);
      if (*(short *)(lVar4 + 0x88) == 0) {
        lVar4 = FUN_14167ab40(lVar4 + 0x58,0x146df2690);
      }
      else {
        lVar4 = func_0x0001416799a0(lVar4 + 0x80);
      }
      uVar3 = _DAT_14382e13c;
      uVar1 = *(undefined4 *)(lVar4 + 0x1ac);
      uVar11 = CONCAT44(uVar5,_DAT_14382e13c);
      *(undefined4 *)(unaff_RBX + 0x264) = uVar1;
      FUN_1415bae90(uVar3,unaff_RBP + 0xa8,uVar1,1,uVar11);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      goto LAB_140ab7491;
    }
  }
  if (!bVar2) {
    FUN_1415bf200();
    *(undefined4 *)(unaff_RBX + 0x264) = 0;
  }
LAB_140ab7491:
  fVar9 = (fStack0000000000000074 - fVar9) * _DAT_14386dc70;
  fVar6 = ((float)((uint)fVar6 & unaff_XMM13_Da) - _DAT_14382f2cc) * _DAT_14382ee88;
  if (fVar9 <= unaff_XMM9_Da) {
    fVar9 = unaff_XMM9_Da;
  }
  if (fVar6 <= unaff_XMM9_Da) {
    fVar6 = unaff_XMM9_Da;
  }
  if (unaff_XMM8_Da <= fVar9) {
    fVar9 = unaff_XMM8_Da;
  }
  if (unaff_XMM8_Da <= fVar6) {
    fVar6 = unaff_XMM8_Da;
  }
  fVar10 = *unaff_R12 - (*(float *)(unaff_RBX + 0x134) - *(float *)(unaff_RBX + 0x124));
  fVar7 = unaff_R12[2] - (*(float *)(unaff_RBX + 0x13c) - *(float *)(unaff_RBX + 300));
  fVar8 = (float)((uint)fVar7 & unaff_XMM13_Da);
  if ((float)((uint)fVar7 & unaff_XMM13_Da) <= unaff_XMM9_Da) {
    fVar8 = unaff_XMM9_Da;
  }
  if (fVar8 <= (float)((uint)fVar10 & unaff_XMM13_Da)) {
    fVar8 = (float)((uint)fVar10 & unaff_XMM13_Da);
  }
  if (unaff_XMM9_Da < fVar8) {
    fVar7 = (unaff_XMM8_Da / fVar8) * fVar7;
    fVar10 = (unaff_XMM8_Da / fVar8) * fVar10;
    fVar8 = unaff_XMM8_Da / SQRT(fVar7 * fVar7 + fVar10 * fVar10);
    fVar7 = fVar8 * fVar7;
    fVar10 = fVar8 * fVar10;
  }
  in_stack_00000050 = *(undefined4 *)(unaff_RBX + 0x104);
  uStack0000000000000054 = *(undefined4 *)(unaff_RBX + 0x108);
  in_stack_00000058 = *(undefined4 *)(unaff_RBX + 0x10c);
  in_stack_00000060 = *(undefined4 *)(unaff_RBX + 0x118);
  uStack000000000000005c = *(undefined4 *)(unaff_RBX + 0x114);
  in_stack_00000068 = *(undefined4 *)(unaff_RBX + 0x124);
  uStack0000000000000064 = *(undefined4 *)(unaff_RBX + 0x11c);
  uStack0000000000000070 = *(undefined4 *)(unaff_RBX + 300);
  uStack000000000000006c = *(undefined4 *)(unaff_RBX + 0x128);
  FUN_1402e7060(&stack0x00000078,&stack0x00000050);
  fVar8 = (float)FUN_141c58560(fVar10 * in_stack_00000078 + fVar7 * *(float *)(unaff_RBP + -0x70),
                               fVar10 * *(float *)(unaff_RBP + -0x80) +
                               fVar7 * *(float *)(unaff_RBP + -0x68));
  fVar8 = fVar8 * _DAT_143830124;
  fVar10 = (float)FUN_143666da0();
  if (fVar8 < unaff_XMM9_Da) {
    fVar10 = (float)((uint)fVar10 ^ _DAT_14382e890);
  }
  fVar10 = (unaff_XMM8_Da - fVar9) * (unaff_XMM8_Da - fVar6) * fVar10;
  if (unaff_XMM9_Da <= fVar10) {
    fVar6 = unaff_XMM11_Da - fVar10 * unaff_XMM11_Da;
    if (fVar6 <= unaff_XMM9_Da) {
      fVar6 = unaff_XMM9_Da;
    }
  }
  else {
    fVar6 = ((float)((uint)fVar10 & unaff_XMM13_Da) + unaff_XMM8_Da) * unaff_XMM11_Da;
  }
  uVar5 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x268),fVar6,unaff_RBX + 0x26c,_DAT_1438ce978,
                        CONCAT44(uVar5,_DAT_143841320));
  *(undefined4 *)(unaff_RBX + 0x268) = uVar5;
  uVar5 = FUN_1415c2c00(uVar5,0x7f46ca87,uVar5);
  if (*(char *)(unaff_RBP + 0xa0) != '\0') {
    FUN_1415c2670(uVar5,0,0);
    uVar5 = FUN_1415c28a0();
    if (*unaff_RSI != 0) {
      FUN_1415c2670(uVar5,0,2);
      FUN_1415c28a0();
    }
  }
  return;
}


/* SwingRegion_140ab73f9 @ 0x140ab73f9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab73f9(void)

{
  bool bVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int *unaff_RSI;
  float *unaff_R12;
  undefined4 uVar4;
  float unaff_XMM6_Da;
  float fVar5;
  float fVar6;
  float fVar7;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM11_Da;
  float unaff_XMM12_Da;
  float fVar8;
  float fVar9;
  uint unaff_XMM13_Da;
  undefined4 in_stack_00000050;
  undefined4 uStack0000000000000054;
  undefined4 in_stack_00000058;
  undefined4 uStack000000000000005c;
  undefined4 in_stack_00000060;
  undefined4 uStack0000000000000064;
  undefined4 in_stack_00000068;
  undefined4 uStack000000000000006c;
  undefined4 in_stack_00000070;
  float in_stack_00000078;
  
  if (unaff_XMM7_Da <= unaff_XMM6_Da) {
    bVar1 = false;
    if (*(int *)(unaff_RBX + 0x264) == 0) goto LAB_140ab7491;
  }
  else {
    bVar1 = true;
    if (*(int *)(unaff_RBX + 0x264) == 0) {
      lVar3 = *(longlong *)(unaff_RBX + 8);
      if (*(short *)(lVar3 + 0x88) == 0) {
        lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146df2690);
      }
      else {
        lVar3 = func_0x0001416799a0(lVar3 + 0x80);
      }
      uVar2 = _DAT_14382e13c;
      uVar4 = *(undefined4 *)(lVar3 + 0x1ac);
      *(undefined4 *)(unaff_RBX + 0x264) = uVar4;
      FUN_1415bae90(uVar2,unaff_RBP + 0xa8,uVar4,1,uVar2);
      goto LAB_140ab7491;
    }
  }
  if (!bVar1) {
    FUN_1415bf200();
    *(undefined4 *)(unaff_RBX + 0x264) = 0;
  }
LAB_140ab7491:
  fVar8 = (unaff_XMM12_Da - unaff_XMM7_Da) * _DAT_14386dc70;
  fVar5 = ((float)((uint)unaff_XMM6_Da & unaff_XMM13_Da) - _DAT_14382f2cc) * _DAT_14382ee88;
  if (fVar8 <= unaff_XMM9_Da) {
    fVar8 = unaff_XMM9_Da;
  }
  if (fVar5 <= unaff_XMM9_Da) {
    fVar5 = unaff_XMM9_Da;
  }
  if (unaff_XMM8_Da <= fVar8) {
    fVar8 = unaff_XMM8_Da;
  }
  if (unaff_XMM8_Da <= fVar5) {
    fVar5 = unaff_XMM8_Da;
  }
  fVar9 = *unaff_R12 - (*(float *)(unaff_RBX + 0x134) - *(float *)(unaff_RBX + 0x124));
  fVar6 = unaff_R12[2] - (*(float *)(unaff_RBX + 0x13c) - *(float *)(unaff_RBX + 300));
  fVar7 = (float)((uint)fVar6 & unaff_XMM13_Da);
  if ((float)((uint)fVar6 & unaff_XMM13_Da) <= unaff_XMM9_Da) {
    fVar7 = unaff_XMM9_Da;
  }
  if (fVar7 <= (float)((uint)fVar9 & unaff_XMM13_Da)) {
    fVar7 = (float)((uint)fVar9 & unaff_XMM13_Da);
  }
  if (unaff_XMM9_Da < fVar7) {
    fVar6 = (unaff_XMM8_Da / fVar7) * fVar6;
    fVar9 = (unaff_XMM8_Da / fVar7) * fVar9;
    fVar7 = unaff_XMM8_Da / SQRT(fVar6 * fVar6 + fVar9 * fVar9);
    fVar6 = fVar7 * fVar6;
    fVar9 = fVar7 * fVar9;
  }
  in_stack_00000050 = *(undefined4 *)(unaff_RBX + 0x104);
  uStack0000000000000054 = *(undefined4 *)(unaff_RBX + 0x108);
  in_stack_00000058 = *(undefined4 *)(unaff_RBX + 0x10c);
  in_stack_00000060 = *(undefined4 *)(unaff_RBX + 0x118);
  uStack000000000000005c = *(undefined4 *)(unaff_RBX + 0x114);
  in_stack_00000068 = *(undefined4 *)(unaff_RBX + 0x124);
  uStack0000000000000064 = *(undefined4 *)(unaff_RBX + 0x11c);
  in_stack_00000070 = *(undefined4 *)(unaff_RBX + 300);
  uStack000000000000006c = *(undefined4 *)(unaff_RBX + 0x128);
  FUN_1402e7060(&stack0x00000078,&stack0x00000050);
  fVar7 = (float)FUN_141c58560(fVar9 * in_stack_00000078 + fVar6 * *(float *)(unaff_RBP + -0x70),
                               fVar9 * *(float *)(unaff_RBP + -0x80) +
                               fVar6 * *(float *)(unaff_RBP + -0x68));
  fVar7 = fVar7 * _DAT_143830124;
  fVar9 = (float)FUN_143666da0();
  if (fVar7 < unaff_XMM9_Da) {
    fVar9 = (float)((uint)fVar9 ^ _DAT_14382e890);
  }
  fVar9 = (unaff_XMM8_Da - fVar8) * (unaff_XMM8_Da - fVar5) * fVar9;
  if (unaff_XMM9_Da <= fVar9) {
    fVar5 = unaff_XMM11_Da - fVar9 * unaff_XMM11_Da;
    if (fVar5 <= unaff_XMM9_Da) {
      fVar5 = unaff_XMM9_Da;
    }
  }
  else {
    fVar5 = ((float)((uint)fVar9 & unaff_XMM13_Da) + unaff_XMM8_Da) * unaff_XMM11_Da;
  }
  uVar4 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x268),fVar5,unaff_RBX + 0x26c,_DAT_1438ce978,
                        _DAT_143841320);
  *(undefined4 *)(unaff_RBX + 0x268) = uVar4;
  uVar4 = FUN_1415c2c00(uVar4,0x7f46ca87,uVar4);
  if (*(char *)(unaff_RBP + 0xa0) != '\0') {
    FUN_1415c2670(uVar4,0,0);
    uVar4 = FUN_1415c28a0();
    if (*unaff_RSI != 0) {
      FUN_1415c2670(uVar4,0,2);
      FUN_1415c28a0();
    }
  }
  return;
}


/* SwingRegion_140ab753d @ 0x140ab753d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab753d(undefined8 param_1,undefined8 param_2,float param_3)

{
  longlong unaff_RBX;
  longlong unaff_RBP;
  int *unaff_RSI;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float unaff_XMM6_Da;
  float fVar4;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM11_Da;
  float unaff_XMM12_Da;
  uint unaff_XMM13_Da;
  float unaff_XMM14_Da;
  undefined4 uStack0000000000000050;
  undefined4 uStack0000000000000054;
  undefined4 uStack0000000000000058;
  undefined4 uStack000000000000005c;
  undefined4 uStack0000000000000060;
  undefined4 uStack0000000000000064;
  undefined4 uStack0000000000000068;
  undefined4 uStack000000000000006c;
  undefined4 uStack0000000000000070;
  float in_stack_00000078;
  
  fVar3 = (unaff_XMM8_Da / param_3) * unaff_XMM6_Da;
  fVar2 = (unaff_XMM8_Da / param_3) * unaff_XMM12_Da;
  fVar4 = unaff_XMM8_Da / SQRT(fVar3 * fVar3 + fVar2 * fVar2);
  fVar3 = fVar4 * fVar3;
  fVar4 = fVar4 * fVar2;
  uStack0000000000000050 = *(undefined4 *)(unaff_RBX + 0x104);
  uStack0000000000000054 = *(undefined4 *)(unaff_RBX + 0x108);
  uStack0000000000000058 = *(undefined4 *)(unaff_RBX + 0x10c);
  uStack0000000000000060 = *(undefined4 *)(unaff_RBX + 0x118);
  uStack000000000000005c = *(undefined4 *)(unaff_RBX + 0x114);
  uStack0000000000000068 = *(undefined4 *)(unaff_RBX + 0x124);
  uStack0000000000000064 = *(undefined4 *)(unaff_RBX + 0x11c);
  uStack0000000000000070 = *(undefined4 *)(unaff_RBX + 300);
  uStack000000000000006c = *(undefined4 *)(unaff_RBX + 0x128);
  FUN_1402e7060(&stack0x00000078,&stack0x00000050);
  fVar2 = (float)FUN_141c58560(fVar4 * in_stack_00000078 + fVar3 * *(float *)(unaff_RBP + -0x70),
                               fVar4 * *(float *)(unaff_RBP + -0x80) +
                               fVar3 * *(float *)(unaff_RBP + -0x68));
  fVar2 = fVar2 * _DAT_143830124;
  fVar3 = (float)FUN_143666da0();
  if (fVar2 < unaff_XMM9_Da) {
    fVar3 = (float)((uint)fVar3 ^ _DAT_14382e890);
  }
  fVar3 = unaff_XMM7_Da * unaff_XMM14_Da * fVar3;
  if (unaff_XMM9_Da <= fVar3) {
    fVar2 = unaff_XMM11_Da - fVar3 * unaff_XMM11_Da;
    if (fVar2 <= unaff_XMM9_Da) {
      fVar2 = unaff_XMM9_Da;
    }
  }
  else {
    fVar2 = ((float)((uint)fVar3 & unaff_XMM13_Da) + unaff_XMM8_Da) * unaff_XMM11_Da;
  }
  uVar1 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x268),fVar2,unaff_RBX + 0x26c,_DAT_1438ce978,
                        _DAT_143841320);
  *(undefined4 *)(unaff_RBX + 0x268) = uVar1;
  uVar1 = FUN_1415c2c00(uVar1,0x7f46ca87,uVar1);
  if (*(char *)(unaff_RBP + 0xa0) != '\0') {
    FUN_1415c2670(uVar1,0,0);
    uVar1 = FUN_1415c28a0();
    if (*unaff_RSI != 0) {
      FUN_1415c2670(uVar1,0,2);
      FUN_1415c28a0();
    }
  }
  return;
}


/* SwingRegion_140ab7687 @ 0x140ab7687 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab7687(uint param_1)

{
  longlong unaff_RBX;
  longlong unaff_RBP;
  int *unaff_RSI;
  undefined4 uVar1;
  float unaff_XMM7_Da;
  float fVar2;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM11_Da;
  uint unaff_XMM13_Da;
  float unaff_XMM14_Da;
  undefined4 uStack0000000000000028;
  
  fVar2 = unaff_XMM7_Da * unaff_XMM14_Da * (float)(param_1 ^ _DAT_14382e890);
  if (unaff_XMM9_Da <= fVar2) {
    fVar2 = unaff_XMM11_Da - fVar2 * unaff_XMM11_Da;
    if (fVar2 <= unaff_XMM9_Da) {
      fVar2 = unaff_XMM9_Da;
    }
  }
  else {
    fVar2 = ((float)((uint)fVar2 & unaff_XMM13_Da) + unaff_XMM8_Da) * unaff_XMM11_Da;
  }
  uStack0000000000000028 = _DAT_1438aa2a0;
  uVar1 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x268),fVar2,unaff_RBX + 0x26c,_DAT_1438ce978,
                        _DAT_143841320);
  *(undefined4 *)(unaff_RBX + 0x268) = uVar1;
  uVar1 = FUN_1415c2c00(uVar1,0x7f46ca87,uVar1);
  if (*(char *)(unaff_RBP + 0xa0) != '\0') {
    FUN_1415c2670(uVar1,0,0);
    uVar1 = FUN_1415c28a0();
    if (*unaff_RSI != 0) {
      FUN_1415c2670(uVar1,0,2);
      FUN_1415c28a0();
    }
  }
  return;
}


/* SwingRegion_140ab76a6 @ 0x140ab76a6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab76a6(void)

{
  longlong unaff_RBX;
  longlong unaff_RBP;
  int *unaff_RSI;
  undefined4 uVar1;
  uint unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM11_Da;
  uint unaff_XMM13_Da;
  undefined4 uStack0000000000000028;
  
  uStack0000000000000028 = _DAT_1438aa2a0;
  uVar1 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x268),
                        ((float)(unaff_XMM7_Da & unaff_XMM13_Da) + unaff_XMM8_Da) * unaff_XMM11_Da,
                        unaff_RBX + 0x26c,_DAT_1438ce978,_DAT_143841320);
  *(undefined4 *)(unaff_RBX + 0x268) = uVar1;
  uVar1 = FUN_1415c2c00(uVar1,0x7f46ca87,uVar1);
  if (*(char *)(unaff_RBP + 0xa0) != '\0') {
    FUN_1415c2670(uVar1,0,0);
    uVar1 = FUN_1415c28a0();
    if (*unaff_RSI != 0) {
      FUN_1415c2670(uVar1,0,2);
      FUN_1415c28a0();
    }
  }
  return;
}


/* SwingRegion_140ab775a @ 0x140ab775a */

void SwingRegion_140ab775a(void)

{
  int *unaff_RSI;
  
  FUN_1415c2670();
  FUN_1415c28a0();
  if (*unaff_RSI != 0) {
    FUN_1415c2670();
    FUN_1415c28a0();
  }
  return;
}


/* SwingRegion_140ab77e0 @ 0x140ab77e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab77e0(longlong param_1,float param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    uVar2 = FUN_14167ab40(lVar1 + 0x58,0x1473d09e0);
  }
  else {
    uVar2 = func_0x0001416799a0(lVar1 + 0x80);
  }
  if (*(int *)(param_1 + 0x194) == 0) {
    FUN_1415bf500(uVar2,0);
    FUN_1415bf500(uVar2,1);
    lVar1 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar1 + 0x88) == 0) {
      uVar3 = FUN_14167ab40(lVar1 + 0x58,0x146dacd70);
    }
    else {
      uVar3 = func_0x0001416799a0(lVar1 + 0x80);
    }
    FUN_1408614a0(uVar3);
  }
  FUN_140ab7b30(param_1,param_2,uVar2);
  FUN_140ab8d00(param_1,param_2,uVar2);
  FUN_140ab5e60(param_1,param_2,uVar2);
  FUN_140ab8af0(param_1,param_2,uVar2);
  fVar4 = (float)FUN_1420dc660(param_1);
  fVar9 = _DAT_14382dce0;
  fVar4 = (fVar4 - _DAT_14382e120) * _DAT_1438627c8;
  fVar8 = ((float)((uint)*(float *)(param_1 + 0x230) & _DAT_14382e160) - _DAT_14382f0e0) *
          _DAT_1438929bc;
  if (fVar4 <= 0.0) {
    fVar4 = 0.0;
  }
  if (fVar8 <= 0.0) {
    fVar8 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar4) {
    fVar4 = _DAT_14382dce0;
  }
  if (_DAT_14382dce0 <= fVar8) {
    fVar8 = _DAT_14382dce0;
  }
  if (0.0 <= *(float *)(param_1 + 0x230)) {
    fVar4 = _DAT_14382dce0 - fVar8 * fVar4;
  }
  else {
    fVar4 = fVar8 * fVar4 + _DAT_14382dce0;
  }
  uVar5 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x248),fVar4 * _DAT_14382e128,param_1 + 0x24c,
                        _DAT_1438ac770,_DAT_143841320,_DAT_14382ee90,param_2);
  *(undefined4 *)(param_1 + 0x248) = uVar5;
  FUN_1415c2c00(uVar2,0x31b78a49,uVar5);
  FUN_140ab7ee0(param_1,param_2,uVar2);
  FUN_140ab81e0(param_1,param_2,uVar2);
  if (*(int *)(param_1 + 0x194) == *(int *)(param_1 + 0x1a4)) {
    if ((0.0 < *(float *)(param_1 + 0x1e4) || *(float *)(param_1 + 0x1e4) == 0.0) &&
       (0.0 < *(float *)(param_1 + 0x1e8) || *(float *)(param_1 + 0x1e8) == 0.0)) {
      fVar8 = (float)FUN_1415c09c0(uVar2,0);
      fVar6 = (float)FUN_1415c05d0(uVar2,0);
      fVar7 = (float)FUN_1415c0a10(uVar2,0);
      fVar4 = (fVar9 / fVar6) * *(float *)(param_1 + 0x1e8);
      if (fVar9 <= fVar4) {
        fVar4 = fVar9;
      }
      if (fVar4 < *(float *)(param_1 + 0x204) || fVar4 == *(float *)(param_1 + 0x204)) {
        fVar4 = *(float *)(param_1 + 0x208);
        fVar8 = (float)func_0x00014041c590(*(undefined4 *)(param_1 + 0x1bc),
                                           *(undefined4 *)(param_1 + 0x20c),
                                           *(undefined4 *)(param_1 + 0x1e4));
        fVar4 = fVar8 * (fVar9 - fVar4) + fVar4;
      }
      else {
        *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(param_1 + 0x1bc);
        fVar4 = (fVar8 + param_2) * (fVar9 / fVar6);
        if (fVar9 <= fVar4) {
          fVar4 = fVar9;
        }
        *(float *)(param_1 + 0x208) = fVar4;
      }
      *(float *)(param_1 + 0x204) = fVar4;
      if ((_DAT_14382e118 <= param_2) &&
         (fVar9 = ((fVar4 - fVar7) * fVar6) / param_2, fVar9 <= _DAT_143830118)) {
        fVar9 = _DAT_143830118;
      }
      FUN_1415c2670(uVar2,fVar9,0);
      *(undefined1 *)(param_1 + 0x210) = 1;
      return;
    }
  }
  else {
    FUN_1415c2c00(uVar2,0x2ae17432,0);
  }
  *(undefined1 *)(param_1 + 0x210) = 0;
  *(undefined4 *)(param_1 + 0x204) = 0;
  return;
}


/* SwingRegion_140ab7a0b @ 0x140ab7a0b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab7a0b(undefined4 param_1)

{
  longlong unaff_RBX;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float unaff_XMM7_Da;
  float unaff_XMM9_Da;
  
  fVar1 = (float)FUN_1415c09c0(param_1,0);
  fVar2 = (float)FUN_1415c05d0(fVar1,0);
  fVar3 = (float)FUN_1415c0a10(fVar2,0);
  fVar5 = (unaff_XMM7_Da / fVar2) * *(float *)(unaff_RBX + 0x1e8);
  if (unaff_XMM7_Da <= fVar5) {
    fVar5 = unaff_XMM7_Da;
  }
  if (fVar5 < *(float *)(unaff_RBX + 0x204) || fVar5 == *(float *)(unaff_RBX + 0x204)) {
    fVar5 = *(float *)(unaff_RBX + 0x208);
    fVar4 = (float)func_0x00014041c590(*(undefined4 *)(unaff_RBX + 0x1bc),
                                       *(undefined4 *)(unaff_RBX + 0x20c),
                                       *(undefined4 *)(unaff_RBX + 0x1e4));
    fVar1 = unaff_XMM7_Da - fVar5;
    fVar5 = fVar4 * fVar1 + fVar5;
  }
  else {
    *(undefined4 *)(unaff_RBX + 0x20c) = *(undefined4 *)(unaff_RBX + 0x1bc);
    fVar5 = (fVar1 + unaff_XMM9_Da) * (unaff_XMM7_Da / fVar2);
    if (unaff_XMM7_Da <= fVar5) {
      fVar5 = unaff_XMM7_Da;
    }
    *(float *)(unaff_RBX + 0x208) = fVar5;
    fVar1 = fVar3;
  }
  *(float *)(unaff_RBX + 0x204) = fVar5;
  if (_DAT_14382e118 <= unaff_XMM9_Da) {
    unaff_XMM7_Da = ((fVar5 - fVar3) * fVar2) / unaff_XMM9_Da;
    if (unaff_XMM7_Da <= _DAT_143830118) {
      unaff_XMM7_Da = _DAT_143830118;
    }
  }
  FUN_1415c2670(fVar1,unaff_XMM7_Da,0);
  *(undefined1 *)(unaff_RBX + 0x210) = 1;
  return;
}


/* SwingRegion_140ab7b30 @ 0x140ab7b30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab7b30(longlong param_1,float param_2,longlong param_3)

{
  undefined1 *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  undefined7 uVar10;
  undefined8 uVar9;
  float fVar11;
  float fVar12;
  float afStackX_8 [2];
  undefined4 auStackX_18 [2];
  undefined1 auStack_38 [48];
  
  FUN_140ab4450(param_1 + 0x150,param_1 + 0x134,param_1 + 0x220,auStack_38,auStackX_18,afStackX_8,0)
  ;
  if (*(float *)(param_1 + 0x1b8) != _DAT_14382e9ec) {
    afStackX_8[0] =
         (float)func_0x000141c477e0(*(float *)(param_1 + 0x1b8),afStackX_8[0],_DAT_14384a1cc,param_2
                                   );
  }
  fVar12 = _DAT_143840c90 - afStackX_8[0];
  *(float *)(param_1 + 0x1b8) = afStackX_8[0];
  *(undefined4 *)(param_1 + 0x1c0) = auStackX_18[0];
  *(float *)(param_1 + 0x1bc) = fVar12;
  fVar12 = (float)FUN_140ab42f0(param_1);
  uVar9 = 0;
  fVar11 = (float)FUN_1415c09c0(param_3,0);
  uVar10 = (undefined7)((ulonglong)uVar9 >> 8);
  bVar8 = 1;
  if ((*(byte *)(param_3 + 0x98) & 1) != 0) {
    bVar8 = *(byte *)(param_3 + 0xa0) & 1;
    uVar10 = 0;
  }
  puVar1 = (undefined1 *)(param_1 + 0xf0);
  switch(*puVar1) {
  case 1:
    if (*(int *)(param_1 + 0x194) == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x1a4) != 0) {
      if ((fVar11 < *(float *)(param_1 + 0x1c8)) ||
         ((*(char *)(param_1 + 0x211) == '\0' && (*(float *)(param_1 + 0x1e0) <= fVar12)))) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if ((*(float *)(param_1 + 0x1b8) <= _DAT_143830128 &&
           _DAT_143830128 != *(float *)(param_1 + 0x1b8)) ||
         (fVar12 <= param_2 * *(float *)(param_1 + 0x1e0) * _DAT_143854044)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if ((*(char *)(param_1 + 0x212) == '\0') || (fVar11 < *(float *)(param_1 + 0x1cc))) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (((bVar4) || (bVar2)) || (bVar3)) {
code_r0x000140ab7d68:
        uVar9 = CONCAT71(uVar10,4);
        break;
      }
    }
    if ((fVar11 < *(float *)(param_1 + 0x1cc)) ||
       (fVar12 <= *(float *)(param_1 + 0x1e0) + _DAT_14382e124)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (((*(int *)(param_1 + 0x19c) == 0) || (*(char *)(param_1 + 0x211) != '\0')) || (!bVar4)) {
      cVar5 = FUN_1415bfc60(param_3,_DAT_14382ee88,0);
      if (cVar5 == '\0') {
        return;
      }
      uVar9 = CONCAT71(uVar10,(*(char *)(param_1 + 0x211) != '\0') + '\x03');
    }
    else {
      uVar9 = CONCAT71(uVar10,2);
    }
    break;
  case 2:
    if (*(int *)(param_1 + 0x200) != 0) goto code_r0x000140ab7e6b;
    if (((*(int *)(param_1 + 0x1a4) != 0) && (*(float *)(param_1 + 0x1d8) <= fVar11)) &&
       (fVar12 < *(float *)(param_1 + 0x1e0))) goto code_r0x000140ab7d68;
    if (fVar11 < *(float *)(param_1 + 0x1d4) || fVar11 == *(float *)(param_1 + 0x1d4)) {
      return;
    }
    uVar9 = CONCAT71(uVar10,3);
    break;
  case 3:
    if (*(int *)(param_1 + 0x200) == 0) {
      if (*(int *)(param_1 + 0x1a4) == 0) {
        return;
      }
      if ((_UNK_1438ce974 < *(float *)(param_1 + 0x1b8) ||
           _UNK_1438ce974 == *(float *)(param_1 + 0x1b8)) &&
         (param_2 + *(float *)(param_1 + 0x1e0) < fVar12)) {
        return;
      }
      FUN_1420df1c0(puVar1,CONCAT71(uVar10,4));
      iVar6 = func_0x000141bb88d0(&UNK_1438ce938,0xedb88320);
      iVar7 = *(int *)(param_1 + 0x1a0);
      if (iVar7 == iVar6) {
        iVar7 = 0x6eb97095;
      }
      *(int *)(param_1 + 0x1a0) = iVar7;
      return;
    }
    goto code_r0x000140ab7e6b;
  case 4:
    *(undefined4 *)(param_1 + 0x19c) = 0;
    if (*(int *)(param_1 + 0x200) != 0) goto code_r0x000140ab7e6b;
    if ((*(int *)(param_1 + 0x1a4) == 0) && (*(char *)(param_1 + 0x1ec) != '\0')) {
      uVar9 = CONCAT71(uVar10,6);
    }
    else {
      if (bVar8 == 0) {
        return;
      }
      uVar9 = CONCAT71(uVar10,5);
    }
    break;
  case 5:
    if (*(int *)(param_1 + 0x200) == 0) {
      if (*(char *)(param_1 + 0x1ed) == '\0') {
        return;
      }
      if (0.0 < *(float *)(param_1 + 0x218) || *(float *)(param_1 + 0x218) == 0.0) {
        return;
      }
      FUN_1420df1c0(puVar1,CONCAT71(uVar10,3));
      *(undefined1 *)(param_1 + 0x1ed) = 0;
      return;
    }
    goto code_r0x000140ab7e6b;
  case 6:
    if (*(int *)(param_1 + 0x200) == 0) {
      return;
    }
code_r0x000140ab7e6b:
    uVar9 = CONCAT71(uVar10,7);
    break;
  case 7:
    if (*(int *)(param_1 + 0x200) != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x285) = 1;
    uVar9 = 3;
    if (*(char *)(param_1 + 0x1ec) != '\0') {
      uVar9 = 6;
    }
    break;
  default:
    goto LAB_140ab7e9b;
  }
  FUN_1420df1c0(puVar1,uVar9);
LAB_140ab7e9b:
  return;
}


/* SwingRegion_140ab7ee0 @ 0x140ab7ee0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140ab7ee0(longlong param_1,undefined4 param_2,longlong param_3)

{
  float fVar1;
  byte bVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  float afStack_b0 [2];
  float fStack_a8;
  float fStack_98;
  float fStack_90;
  undefined1 *puStack_50;
  
  uVar4 = _DAT_14382e160;
  fVar1 = _DAT_14382dce0;
  fVar11 = *(float *)(param_1 + 0x170) - *(float *)(param_1 + 0x13c);
  fVar12 = *(float *)(param_1 + 0x168) - *(float *)(param_1 + 0x134);
  fVar10 = (float)((uint)fVar11 & _DAT_14382e160);
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  fVar7 = ((float)(*(uint *)(param_1 + 0x1c0) & _DAT_14382e160) - _DAT_14382f2cc) * _DAT_14382ee88;
  if (fVar7 <= 0.0) {
    fVar7 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar7) {
    fVar7 = _DAT_14382dce0;
  }
  fVar7 = _DAT_14382dce0 - fVar7;
  fVar8 = (*(float *)(param_1 + 0x1b8) - _DAT_1438794d0) * _DAT_1438ac374;
  if (fVar8 <= 0.0) {
    fVar8 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar8) {
    fVar8 = _DAT_14382dce0;
  }
  fVar8 = _DAT_14382dce0 - fVar8;
  if (fVar10 <= (float)((uint)fVar12 & _DAT_14382e160)) {
    fVar10 = (float)((uint)fVar12 & _DAT_14382e160);
  }
  if (0.0 < fVar10) {
    fVar11 = (_DAT_14382dce0 / fVar10) * fVar11;
    fVar12 = (_DAT_14382dce0 / fVar10) * fVar12;
    fVar10 = _DAT_14382dce0 / SQRT(fVar11 * fVar11 + fVar12 * fVar12);
    fVar11 = fVar10 * fVar11;
    fVar12 = fVar10 * fVar12;
  }
  uStack_d8 = *(undefined4 *)(param_1 + 0x104);
  uStack_d4 = *(undefined4 *)(param_1 + 0x108);
  uStack_d0 = *(undefined4 *)(param_1 + 0x10c);
  uStack_c8 = *(undefined4 *)(param_1 + 0x118);
  uStack_cc = *(undefined4 *)(param_1 + 0x114);
  uStack_c0 = *(undefined4 *)(param_1 + 0x124);
  uStack_c4 = *(undefined4 *)(param_1 + 0x11c);
  uStack_b8 = *(undefined4 *)(param_1 + 300);
  uStack_bc = *(undefined4 *)(param_1 + 0x128);
  FUN_1402e7060(afStack_b0,&uStack_d8);
  fVar12 = (float)FUN_141c58560(fStack_98 * fVar11 + afStack_b0[0] * fVar12,
                                fStack_90 * fVar11 + fStack_a8 * fVar12);
  fVar10 = (float)((uint)(_DAT_143861350 - (float)((uint)(fVar12 * _DAT_143830124) & uVar4)) & uVar4
                  ) * _DAT_1438ad510;
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  if (fVar1 <= fVar10) {
    fVar10 = fVar1;
  }
  fVar10 = fVar1 - fVar10;
  if (fVar12 * _DAT_143830124 < 0.0) {
    fVar10 = (float)((uint)fVar10 ^ _DAT_14382e890);
  }
  fVar10 = (fVar8 * fVar7 * fVar10 - _DAT_14382e13c) * _DAT_14382e128;
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  if (fVar1 <= fVar10) {
    fVar10 = fVar1;
  }
  uVar9 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x268),fVar10,param_1 + 0x26c,_DAT_1438ce978,
                        _DAT_143841320,_DAT_1438aa2a0,param_2);
  *(undefined4 *)(param_1 + 0x268) = uVar9;
  if ((*(ushort *)(*(ulonglong *)(param_3 + 8) + 8) >> 10 & 1) != 0) {
    return *(ulonglong *)(param_3 + 8) & 0xffffffffffffff00;
  }
  puStack_50 = (undefined1 *)0x1415c2c67;
  bVar2 = FUN_1415c83b0(param_3 + 0x68,&stack0x00000008,0x7f46ca87,1);
  if (bVar2 != 0) {
    *(undefined4 *)(param_3 + 0x878) = 0xffffffff;
  }
  uVar4 = *(uint *)(param_3 + 0xea8);
  uVar5 = 0;
  uVar6 = 1;
  while (uVar4 != 0) {
    if ((uVar4 & uVar6) != 0) {
      puStack_50 = (undefined1 *)0x1415c2ca4;
      plVar3 = (longlong *)func_0x0001416798f0(param_3 + 0xeac + uVar5 * 4);
      if (plVar3 != (longlong *)0x0) {
        puStack_50 = &LAB_1415c2cb9;
        (**(code **)(*plVar3 + 0x70))(plVar3,0x7f46ca87,uVar9);
      }
      uVar4 = uVar4 ^ uVar6;
    }
    uVar6 = uVar6 * 2;
    uVar5 = (ulonglong)((int)uVar5 + 1);
  }
  return (ulonglong)bVar2;
}


/* SwingRegion_140ab81e0 @ 0x140ab81e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab81e0(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  undefined1 auStackX_20 [8];
  undefined8 in_stack_ffffffffffffff90;
  undefined8 uVar9;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  if (DAT_145d9fe7e != '\0') {
    return;
  }
  fVar5 = (float)FUN_1420dc660();
  if ((fVar5 <= _DAT_14383fd4c) || (DAT_145d9fe7d == '\0')) {
    bVar1 = false;
    if (*(int *)(param_1 + 0x254) == 0) goto LAB_140ab82a2;
  }
  else {
    bVar1 = true;
    if (*(int *)(param_1 + 0x254) == 0) {
      uVar7 = 0;
      FUN_1415bae90(param_3,auStackX_20,*(undefined4 *)(param_1 + 0x1b0),1,_DAT_14382e13c,0);
      *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(param_1 + 0x1b0);
      goto LAB_140ab82a2;
    }
  }
  if (!bVar1) {
    FUN_1415bf200(param_3);
    *(undefined4 *)(param_1 + 0x254) = 0;
  }
LAB_140ab82a2:
  uVar2 = _DAT_14382e160;
  fVar5 = _DAT_14382dce0;
  fVar8 = (((float)(*(uint *)(param_1 + 0x230) & _DAT_14382e160) -
           (float)(*(uint *)(param_1 + 0x234) & _DAT_14382e160)) - _DAT_14382f0e0) * _DAT_14382e120;
  if (fVar8 <= 0.0) {
    fVar8 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar8) {
    fVar8 = _DAT_14382dce0;
  }
  fVar6 = (float)FUN_1420dc660(param_1);
  fVar6 = (fVar6 - _DAT_14383fd4c) * _DAT_1438627c8;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  if (fVar5 <= fVar6) {
    fVar6 = fVar5;
  }
  if (0.0 < *(float *)(param_1 + 0x230) || *(float *)(param_1 + 0x230) == 0.0) {
    fVar5 = fVar6 * fVar8 + fVar5;
  }
  else {
    fVar5 = fVar5 - fVar6 * fVar8;
  }
  fVar5 = fVar5 * _DAT_14382e128;
  if ((float)((uint)(fVar5 - _DAT_14382e128) & uVar2) <=
      (float)((uint)(*(float *)(param_1 + 600) - _DAT_14382e128) & uVar2)) {
    fVar5 = (float)func_0x000141c477e0(*(float *)(param_1 + 600),fVar5,_DAT_14382f760,param_2);
  }
  uVar4 = _DAT_143841320;
  uVar3 = _DAT_1438374ac;
  uVar9 = CONCAT44(uVar7,_DAT_1438388c4);
  *(float *)(param_1 + 600) = fVar5;
  uVar7 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x260),fVar5,param_1 + 0x25c,uVar3,uVar4,uVar9,
                        param_2);
  *(undefined4 *)(param_1 + 0x260) = uVar7;
  FUN_1415c2c00(param_3,0x5dd56ddb,uVar7);
  return;
}


/* SwingRegion_140ab820b @ 0x140ab820b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab820b(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong in_RAX;
  longlong unaff_RBX;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  float fVar7;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  
  *(undefined4 *)(in_RAX + -0x18) = unaff_XMM6_Da;
  *(undefined4 *)(in_RAX + -0x14) = unaff_XMM6_Db;
  *(undefined4 *)(in_RAX + -0x10) = unaff_XMM6_Dc;
  *(undefined4 *)(in_RAX + -0xc) = unaff_XMM6_Dd;
  *(undefined4 *)(in_RAX + -0x28) = unaff_XMM7_Da;
  *(undefined4 *)(in_RAX + -0x24) = unaff_XMM7_Db;
  *(undefined4 *)(in_RAX + -0x20) = unaff_XMM7_Dc;
  *(undefined4 *)(in_RAX + -0x1c) = unaff_XMM7_Dd;
  *(undefined4 *)(in_RAX + -0x38) = unaff_XMM8_Da;
  *(undefined4 *)(in_RAX + -0x34) = unaff_XMM8_Db;
  *(undefined4 *)(in_RAX + -0x30) = unaff_XMM8_Dc;
  *(undefined4 *)(in_RAX + -0x2c) = unaff_XMM8_Dd;
  *(undefined4 *)(in_RAX + -0x48) = unaff_XMM9_Da;
  *(undefined4 *)(in_RAX + -0x44) = unaff_XMM9_Db;
  *(undefined4 *)(in_RAX + -0x40) = unaff_XMM9_Dc;
  *(undefined4 *)(in_RAX + -0x3c) = unaff_XMM9_Dd;
  fVar4 = (float)FUN_1420dc660();
  if ((fVar4 <= _DAT_14383fd4c) || (DAT_145d9fe7d == '\0')) {
    bVar1 = false;
    if (*(int *)(unaff_RBX + 0x254) == 0) goto LAB_140ab82a2;
  }
  else {
    bVar1 = true;
    if (*(int *)(unaff_RBX + 0x254) == 0) {
      FUN_1415bae90(_DAT_14382e13c,&stack0x000000b8,*(undefined4 *)(unaff_RBX + 0x1b0),1,
                    _DAT_14382e13c);
      *(undefined4 *)(unaff_RBX + 0x254) = *(undefined4 *)(unaff_RBX + 0x1b0);
      goto LAB_140ab82a2;
    }
  }
  if (!bVar1) {
    FUN_1415bf200();
    *(undefined4 *)(unaff_RBX + 0x254) = 0;
  }
LAB_140ab82a2:
  uVar2 = _DAT_14382e160;
  fVar4 = _DAT_14382dce0;
  fVar7 = (((float)(*(uint *)(unaff_RBX + 0x230) & _DAT_14382e160) -
           (float)(*(uint *)(unaff_RBX + 0x234) & _DAT_14382e160)) - _DAT_14382f0e0) *
          _DAT_14382e120;
  if (fVar7 <= 0.0) {
    fVar7 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar7) {
    fVar7 = _DAT_14382dce0;
  }
  fVar5 = (float)FUN_1420dc660();
  fVar5 = (fVar5 - _DAT_14383fd4c) * _DAT_1438627c8;
  if (fVar5 <= 0.0) {
    fVar5 = 0.0;
  }
  if (fVar4 <= fVar5) {
    fVar5 = fVar4;
  }
  if (0.0 < *(float *)(unaff_RBX + 0x230) || *(float *)(unaff_RBX + 0x230) == 0.0) {
    fVar4 = fVar5 * fVar7 + fVar4;
  }
  else {
    fVar4 = fVar4 - fVar5 * fVar7;
  }
  fVar4 = fVar4 * _DAT_14382e128;
  if ((float)((uint)(fVar4 - _DAT_14382e128) & uVar2) <=
      (float)((uint)(*(float *)(unaff_RBX + 600) - _DAT_14382e128) & uVar2)) {
    fVar4 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 600),fVar4,_DAT_14382f760);
  }
  uVar3 = _DAT_143841320;
  uVar6 = _DAT_1438374ac;
  *(float *)(unaff_RBX + 600) = fVar4;
  uVar6 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x260),fVar4,unaff_RBX + 0x25c,uVar6,uVar3);
  *(undefined4 *)(unaff_RBX + 0x260) = uVar6;
  FUN_1415c2c00(uVar6,0x5dd56ddb,uVar6);
  return;
}


/* SwingRegion_140ab832f @ 0x140ab832f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab832f(float param_1,undefined8 param_2,float param_3)

{
  undefined4 uVar1;
  longlong unaff_RBX;
  undefined4 uVar2;
  float unaff_XMM8_Da;
  float fVar3;
  uint unaff_XMM9_Da;
  
  fVar3 = (unaff_XMM8_Da - param_1) * param_3;
  if ((float)((uint)(fVar3 - param_3) & unaff_XMM9_Da) <=
      (float)((uint)(*(float *)(unaff_RBX + 600) - param_3) & unaff_XMM9_Da)) {
    fVar3 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 600),fVar3,_DAT_14382f760);
  }
  uVar1 = _DAT_143841320;
  uVar2 = _DAT_1438374ac;
  *(float *)(unaff_RBX + 600) = fVar3;
  uVar2 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x260),fVar3,unaff_RBX + 0x25c,uVar2,uVar1);
  *(undefined4 *)(unaff_RBX + 0x260) = uVar2;
  FUN_1415c2c00(uVar2,0x5dd56ddb,uVar2);
  return;
}


/* SwingRegion_140ab836e @ 0x140ab836e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab836e(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  longlong unaff_RBX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = func_0x000141c477e0(param_1,param_2,_DAT_14382f760);
  uVar1 = _DAT_143841320;
  uVar3 = _DAT_1438374ac;
  *(undefined4 *)(unaff_RBX + 600) = uVar2;
  uVar3 = FUN_141c46be0(*(undefined4 *)(unaff_RBX + 0x260),uVar2,unaff_RBX + 0x25c,uVar3,uVar1);
  *(undefined4 *)(unaff_RBX + 0x260) = uVar3;
  FUN_1415c2c00(uVar3,0x5dd56ddb,uVar3);
  return;
}


/* SwingRegion_140ab83f4 @ 0x140ab83f4 */

void SwingRegion_140ab83f4(void)

{
  return;
}


/* SwingRegion_140ab8410 @ 0x140ab8410 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab8410(longlong param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  bool bVar4;
  bool bVar5;
  float fVar6;
  char cVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined4 *puVar10;
  uint uVar11;
  longlong unaff_GS_OFFSET;
  float fVar13;
  undefined4 uVar14;
  float fVar15;
  float fVar16;
  undefined1 auStackX_8 [8];
  undefined *puVar17;
  uint in_stack_fffffffffffffee0;
  ulonglong in_stack_fffffffffffffee8;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  undefined1 auStack_b8 [160];
  ulonglong uVar12;
  
  fVar6 = _DAT_14382e118;
  if ((*(char *)(param_1 + 0x280) != '\0') || (*(float *)(param_1 + 0x218) <= _DAT_14382e118)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  puVar8 = (undefined8 *)&DAT_147afdf10;
  if ((undefined8 *)**(undefined8 **)(param_1 + 8) != (undefined8 *)0x0) {
    puVar8 = (undefined8 *)**(undefined8 **)(param_1 + 8);
  }
  uVar3 = puVar8[1];
  *(undefined8 *)(param_1 + 0x104) = *puVar8;
  *(undefined8 *)(param_1 + 0x10c) = uVar3;
  uVar3 = puVar8[3];
  *(undefined8 *)(param_1 + 0x114) = puVar8[2];
  *(undefined8 *)(param_1 + 0x11c) = uVar3;
  uVar14 = *(undefined4 *)((longlong)puVar8 + 0x24);
  uVar1 = *(undefined4 *)(puVar8 + 5);
  uVar2 = *(undefined4 *)((longlong)puVar8 + 0x2c);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(puVar8 + 4);
  *(undefined4 *)(param_1 + 0x128) = uVar14;
  *(undefined4 *)(param_1 + 300) = uVar1;
  *(undefined4 *)(param_1 + 0x130) = uVar2;
  uVar3 = puVar8[7];
  *(undefined8 *)(param_1 + 0x134) = puVar8[6];
  *(undefined8 *)(param_1 + 0x13c) = uVar3;
  fStack_c0 = *(float *)(param_1 + 0x164);
  fStack_d0 = fStack_c0 - *(float *)(param_1 + 0x170);
  fStack_d4 = *(float *)(param_1 + 0x16c);
  fStack_c8 = *(float *)(param_1 + 0x15c);
  fStack_d8 = fStack_c8 - *(float *)(param_1 + 0x168);
  fVar16 = *(float *)(param_1 + 0x160) - fStack_d4;
  fVar15 = (float)((uint)fStack_d0 & _DAT_14382e160);
  if (fVar15 <= 0.0) {
    fVar15 = 0.0;
  }
  fVar13 = (float)((uint)fStack_d8 & _DAT_14382e160);
  if ((float)((uint)fStack_d8 & _DAT_14382e160) <= fVar15) {
    fVar13 = fVar15;
  }
  if (0.0 < fVar13) {
    fStack_d0 = (_DAT_14382dce0 / fVar13) * fStack_d0;
    fStack_d8 = (_DAT_14382dce0 / fVar13) * fStack_d8;
    fVar15 = _DAT_14382dce0 / SQRT(fStack_d8 * fStack_d8 + fStack_d0 * fStack_d0);
    fStack_d0 = fVar15 * fStack_d0;
    fStack_d8 = fVar15 * fStack_d8;
  }
  fStack_d0 = *(float *)(param_1 + 0x170) + fStack_d0;
  fStack_d8 = *(float *)(param_1 + 0x168) + fStack_d8;
  uVar12 = 0;
  puVar17 = (undefined *)0x0;
  fStack_c4 = fStack_d4;
  fVar13 = (float)FUN_141c03d00(auStack_b8,&fStack_c8,&fStack_d8,param_1 + 0x134,0);
  fVar15 = (float)FUN_1420dc660(param_1);
  fVar15 = (fVar15 - _DAT_14382f0dc) * _DAT_14386db58;
  if (fVar15 <= 0.0) {
    fVar15 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar15) {
    fVar15 = _DAT_14382dce0;
  }
  if (fVar15 <= fVar13) {
    fVar15 = fVar13;
  }
  if (fVar15 <= *(float *)(param_1 + 0x174)) {
    fVar15 = *(float *)(param_1 + 0x174);
  }
  *(float *)(param_1 + 0x174) = fVar15;
  fStack_c0 = (fStack_d0 - fStack_c0) * fVar15 + fStack_c0;
  *(ulonglong *)(param_1 + 0x150) =
       CONCAT44((fStack_d4 - fStack_c4) * fVar15 + fStack_c4 + fVar16,
                (fStack_d8 - fStack_c8) * fVar15 + fStack_c8);
  *(float *)(param_1 + 0x158) = fStack_c0;
  FUN_140ab6750(param_1,param_2);
  FUN_140ab9410(param_1,param_2);
  if (*(char *)(param_1 + 0x28b) != '\0') {
    if (*(short *)(*(longlong *)(param_1 + 8) + 0x88) == 0) {
      lVar9 = FUN_14167ab40(*(longlong *)(param_1 + 8) + 0x58,0x147a51f80);
    }
    else {
      lVar9 = func_0x0001416799a0();
    }
    if (lVar9 != 0) {
      if ((*(int *)(*(longlong *)
                     (*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)__tls_index * 8) + 0xa0a0)
           < _DAT_146df2788) && (FUN_143636f50(&DAT_146df2788), _DAT_146df2788 == -1)) {
        _DAT_146df2784 = FUN_141bb8a10(&UNK_1438ce948);
        FUN_143636ef0(&DAT_146df2788);
      }
      uVar14 = FUN_140ab42f0();
      if (*(int *)(lVar9 + 0x154) != 0) {
        do {
          in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffffffff00000000;
          in_stack_fffffffffffffee0 = 0;
          puVar17 = &UNK_1438a8214;
          FUN_14196af10(*(undefined4 *)(lVar9 + (uVar12 + 6) * 0xc),_DAT_146df2784,uVar14,
                        &UNK_1438ce948,&UNK_1438a8214,0,in_stack_fffffffffffffee8);
          uVar11 = (int)uVar12 + 1;
          uVar12 = (ulonglong)uVar11;
        } while (uVar11 < *(uint *)(lVar9 + 0x154));
      }
    }
  }
  cVar7 = *(char *)(param_1 + 0x280);
  if ((cVar7 != '\0') || (*(float *)(param_1 + 0x218) <= fVar6)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  if ((!bVar4) && (bVar5)) {
    lVar9 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar9 + 0x88) == 0) {
      lVar9 = FUN_14167ab40(lVar9 + 0x58,0x146dd77b0);
    }
    else {
      lVar9 = func_0x0001416799a0(lVar9 + 0x80);
    }
    if (lVar9 != 0) {
      func_0x00014067b580(lVar9,*(undefined4 *)(param_1 + 0xfc));
    }
    puVar10 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
    FUN_1416d5e80(0x147475690,0xf315cbc8,*puVar10,0,(ulonglong)puVar17 & 0xffffffff00000000,
                  in_stack_fffffffffffffee0 & 0xffffff00,0,0,1,0,0,0,0);
    cVar7 = *(char *)(param_1 + 0x280);
  }
  if ((cVar7 != '\0') && (*(float *)(param_1 + 0x218) <= 0.0 && *(float *)(param_1 + 0x218) != 0.0))
  {
    *(undefined1 *)(param_1 + 0x280) = 0;
  }
  *(undefined1 *)(param_1 + 0x28b) = 0;
  *(undefined4 *)(param_1 + 0x234) = *(undefined4 *)(param_1 + 0x230);
  return;
}


/* SwingRegion_140ab8900 @ 0x140ab8900 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab8900(longlong param_1,float param_2,longlong param_3)

{
  longlong lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 auStackX_8 [2];
  
  if (*(int *)(param_1 + 0x19c) != 0) {
    fVar2 = (float)FUN_1415c09c0(param_3,0);
    fVar4 = *(float *)(param_1 + 0x1cc) + *(float *)(param_1 + 0x1d0);
    if (*(char *)(param_1 + 0xf0) == '\x01') {
      fVar4 = fVar4 - _DAT_145d9fe88;
      if (_DAT_14382e118 < (float)((uint)fVar4 & _DAT_14382e160)) {
        fVar4 = (fVar2 - _DAT_145d9fe88) / fVar4;
        if (fVar4 <= 0.0) {
          fVar4 = 0.0;
        }
        if (_DAT_14382dce0 <= fVar4) {
          fVar4 = _DAT_14382dce0;
        }
        *(float *)(param_1 + 0x244) = fVar4;
        return;
      }
      if (fVar2 < _DAT_145d9fe88) {
        *(undefined4 *)(param_1 + 0x244) = 0;
        return;
      }
      if (_DAT_145d9fe88 < fVar2) {
        *(float *)(param_1 + 0x244) = _DAT_14382dce0;
        return;
      }
      *(float *)(param_1 + 0x244) = _DAT_14382e128;
      return;
    }
    if (*(char *)(param_1 + 0xf0) == '\x02') {
      fVar4 = fVar4 - _DAT_145d9fe88;
      fVar3 = *(float *)(param_1 + 0x1cc) + fVar2;
      if ((float)((uint)fVar4 & _DAT_14382e160) <= _DAT_14382e118) {
        if (_DAT_145d9fe88 <= fVar3) {
          fVar4 = _DAT_14382e128;
          if (_DAT_145d9fe88 < fVar3) {
            fVar4 = _DAT_14382dce0;
          }
        }
        else {
          fVar4 = 0.0;
        }
      }
      else {
        fVar4 = (fVar3 - _DAT_145d9fe88) / fVar4;
        if (fVar4 <= 0.0) {
          fVar4 = 0.0;
        }
        if (_DAT_14382dce0 <= fVar4) {
          fVar4 = _DAT_14382dce0;
        }
      }
      *(float *)(param_1 + 0x244) = fVar4;
      if (*(char *)(param_1 + 0x289) == '\0') {
        return;
      }
      if (fVar2 <= *(float *)(param_1 + 0x1d0)) {
        return;
      }
      func_0x0001415c6440(param_3 + 0x68,auStackX_8,0);
      lVar1 = func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
      if (lVar1 == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 0x289) = 0;
      return;
    }
  }
  fVar4 = param_2 * _DAT_143834a14 + *(float *)(param_1 + 0x244);
  if (_DAT_14382dce0 <= fVar4) {
    fVar4 = _DAT_14382dce0;
  }
  *(float *)(param_1 + 0x244) = fVar4;
  return;
}


/* SwingRegion_140ab8af0 @ 0x140ab8af0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab8af0(longlong param_1,float param_2,undefined8 param_3)

{
  bool bVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  
  if (*(int *)(param_1 + 0x19c) == 0) {
    return;
  }
  if (*(char *)(param_1 + 0xf0) == '\x01') {
    fVar3 = (*(float *)(param_1 + 0x148) - _DAT_14387e6ac) * _DAT_14386dc74;
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    if (_DAT_14382dce0 <= fVar3) {
      fVar3 = _DAT_14382dce0;
    }
    fVar6 = ((float)((uint)(_DAT_14382e128 - *(float *)(param_1 + 0x23c)) & _DAT_14382e160) -
            _DAT_14384421c) * _DAT_1438ce96c;
    if (fVar6 <= 0.0) {
      fVar6 = 0.0;
    }
    if (_DAT_14382dce0 <= fVar6) {
      fVar6 = _DAT_14382dce0;
    }
    fVar3 = fVar6 * (_DAT_14382dce0 - fVar3) * _DAT_14382f5ac * _DAT_14382e128 + _DAT_1438ce964;
    if (_DAT_14382e128 <= *(float *)(param_1 + 0x23c)) {
      fVar3 = fVar3 + _DAT_14382e128;
    }
    else {
      fVar3 = _DAT_14382e128 - fVar3;
    }
    bVar1 = fVar3 < _DAT_14382e128;
    *(undefined4 *)(param_1 + 0x1f8) = 0;
    *(float *)(param_1 + 500) = fVar3;
    *(float *)(param_1 + 0x1f0) = fVar3;
    *(bool *)(param_1 + 0x1fc) = bVar1;
    goto LAB_140ab8cd4;
  }
  fVar3 = *(float *)(param_1 + 0x230);
  cVar2 = *(char *)(param_1 + 0x1fc);
  fVar6 = ((float)((uint)fVar3 & _DAT_14382e160) - _DAT_14382f0e4) * _DAT_1438ac378;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar6) {
    fVar6 = _DAT_14382dce0;
  }
  if (0.0 < fVar3 != (bool)cVar2) {
    if ((DAT_145d9fe80 != '\0') ||
       (fVar4 = fVar6 * _DAT_14382f0e0 * param_2 + *(float *)(param_1 + 0x1f8),
       bVar1 = fVar4 < _DAT_14382dce0, *(float *)(param_1 + 0x1f8) = fVar4, bVar1))
    goto LAB_140ab8cd4;
    cVar2 = cVar2 == '\0';
    *(char *)(param_1 + 0x1fc) = cVar2;
    if (0.0 < fVar3 != (bool)cVar2) goto LAB_140ab8cd4;
  }
  uVar5 = _DAT_143837a24;
  fVar3 = *(float *)(param_1 + 0x1f0);
  fVar4 = fVar6 * _DAT_14382f5ac * _DAT_14382e128 + _DAT_1438ce964;
  fVar6 = fVar3;
  if (cVar2 == '\0') {
    fVar4 = fVar4 + _DAT_14382e128;
    if (fVar3 <= fVar4) {
      fVar6 = fVar4;
    }
  }
  else {
    fVar4 = _DAT_14382e128 - fVar4;
    if (fVar4 <= fVar3) {
      fVar6 = fVar4;
    }
  }
  *(float *)(param_1 + 500) = fVar6;
  uVar5 = func_0x000141c477e0(fVar3,fVar6,uVar5);
  *(undefined4 *)(param_1 + 0x1f0) = uVar5;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
LAB_140ab8cd4:
  FUN_1415c2c00(param_3,0xfc348363,*(undefined4 *)(param_1 + 0x1f0));
  return;
}


/* SwingRegion_140ab8b43 @ 0x140ab8b43 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab8b43(float param_1,float param_2,float param_3,float param_4)

{
  bool bVar1;
  longlong in_RCX;
  longlong unaff_RBX;
  float in_XMM4_Da;
  float fVar2;
  float fVar3;
  
  fVar3 = param_1 * _DAT_14386dc74;
  if (param_1 * _DAT_14386dc74 <= param_4) {
    fVar3 = param_4;
  }
  if (param_2 <= fVar3) {
    fVar3 = param_2;
  }
  fVar2 = ((float)((uint)(_DAT_14382e128 - in_XMM4_Da) & _DAT_14382e160) - _DAT_14384421c) *
          _DAT_1438ce96c;
  if (fVar2 <= param_4) {
    fVar2 = param_4;
  }
  if (param_2 <= fVar2) {
    fVar2 = param_2;
  }
  fVar3 = fVar2 * (param_3 - fVar3) * _DAT_14382f5ac * _DAT_14382e128 + _DAT_1438ce964;
  if (_DAT_14382e128 <= in_XMM4_Da) {
    fVar3 = fVar3 + _DAT_14382e128;
  }
  else {
    fVar3 = _DAT_14382e128 - fVar3;
  }
  bVar1 = fVar3 < _DAT_14382e128;
  *(undefined4 *)(in_RCX + 0x1f8) = 0;
  *(float *)(in_RCX + 500) = fVar3;
  *(float *)(in_RCX + 0x1f0) = fVar3;
  *(bool *)(in_RCX + 0x1fc) = bVar1;
  FUN_1415c2c00(fVar3,0xfc348363,*(undefined4 *)(unaff_RBX + 0x1f0));
  return;
}


/* SwingRegion_140ab8be7 @ 0x140ab8be7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab8be7(longlong param_1,undefined8 param_2,undefined8 param_3,float param_4)

{
  float fVar1;
  bool bVar2;
  undefined4 uVar3;
  longlong unaff_RBX;
  char cVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = *(float *)(param_1 + 0x230);
  fVar5 = 0.0;
  cVar4 = *(char *)(unaff_RBX + 0x1fc);
  fVar6 = ((float)((uint)fVar1 & _DAT_14382e160) - _DAT_14382f0e4) * _DAT_1438ac378;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar6) {
    fVar6 = _DAT_14382dce0;
  }
  if (0.0 < fVar1 != (bool)cVar4) {
    if (DAT_145d9fe80 != '\0') goto LAB_140ab8cd4;
    fVar5 = fVar6 * _DAT_14382f0e0 * param_4 + *(float *)(unaff_RBX + 0x1f8);
    bVar2 = fVar5 < _DAT_14382dce0;
    *(float *)(unaff_RBX + 0x1f8) = fVar5;
    if (bVar2) goto LAB_140ab8cd4;
    cVar4 = cVar4 == '\0';
    *(char *)(unaff_RBX + 0x1fc) = cVar4;
    if (0.0 < fVar1 != (bool)cVar4) goto LAB_140ab8cd4;
  }
  uVar3 = _DAT_143837a24;
  fVar1 = *(float *)(unaff_RBX + 0x1f0);
  fVar5 = fVar6 * _DAT_14382f5ac * _DAT_14382e128 + _DAT_1438ce964;
  fVar6 = fVar1;
  if (cVar4 == '\0') {
    fVar5 = fVar5 + _DAT_14382e128;
    if (fVar1 <= fVar5) {
      fVar6 = fVar5;
    }
  }
  else {
    fVar5 = _DAT_14382e128 - fVar5;
    if (fVar5 <= fVar1) {
      fVar6 = fVar5;
    }
  }
  *(float *)(unaff_RBX + 500) = fVar6;
  fVar5 = (float)func_0x000141c477e0(fVar1,fVar6,uVar3);
  *(float *)(unaff_RBX + 0x1f0) = fVar5;
  *(undefined4 *)(unaff_RBX + 0x1f8) = 0;
LAB_140ab8cd4:
  FUN_1415c2c00(fVar5,0xfc348363,*(undefined4 *)(unaff_RBX + 0x1f0));
  return;
}


/* SwingRegion_140ab8d00 @ 0x140ab8d00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab8d00(longlong param_1,undefined8 param_2,longlong param_3)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  undefined4 auStackX_8 [2];
  undefined4 auStackX_20 [2];
  
  uVar2 = _DAT_14382e13c;
  iVar6 = *(int *)(param_1 + 0x1a0);
  switch(*(undefined1 *)(param_1 + 0xf0)) {
  case 1:
    iVar6 = *(int *)(param_1 + 0x198);
    break;
  case 2:
    iVar6 = *(int *)(param_1 + 0x19c);
    break;
  case 4:
    iVar6 = *(int *)(param_1 + 0x1a4);
    break;
  case 7:
    iVar6 = *(int *)(param_1 + 0x200);
  }
  iVar4 = *(int *)(param_1 + 0x194);
  if (iVar6 != *(int *)(param_1 + 0x194)) {
    func_0x0001415c6440(param_3 + 0x68,auStackX_8,0);
    lVar5 = func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
    if (lVar5 != 0) {
      if (*(char *)(param_1 + 0x285) == '\0') {
        if (*(char *)(param_1 + 0x287) != '\0') {
          FUN_1415ceb00(lVar5,0xf8d44865,1);
        }
      }
      else {
        FUN_1415bf500(param_3,0);
      }
    }
    FUN_1415bae90(param_3,auStackX_20,iVar6,0,uVar2,0);
    lVar5 = func_0x0001415ad2a0(0x1473d0730,auStackX_20[0]);
    if ((lVar5 != 0) && (FUN_1415ceb00(lVar5,0x46434591,1), *(char *)(param_1 + 0x286) != '\0')) {
      FUN_1415ceb00(lVar5,0x5f118c92,1);
    }
    *(int *)(param_1 + 0x194) = iVar6;
    iVar4 = iVar6;
  }
  if (iVar4 == *(int *)(param_1 + 0x198)) {
    cVar3 = FUN_1415bfc60(param_3,_DAT_14382ee8c,0);
    bVar1 = false;
    if (cVar3 == '\0') goto LAB_140ab8e63;
  }
  bVar1 = true;
LAB_140ab8e63:
  if ((*(int *)(param_1 + 0x270) == 0) && ((bVar1 || (*(char *)(param_1 + 0x274) != '\0')))) {
    FUN_1415bae90(param_3,auStackX_8,*(undefined4 *)(param_1 + 0x1b4),0,uVar2,0);
    *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(param_1 + 0x1b4);
    *(undefined1 *)(param_1 + 0x274) = 0;
  }
  *(undefined2 *)(param_1 + 0x285) = 0;
  *(undefined1 *)(param_1 + 0x287) = 0;
  return;
}


/* SwingRegion_140ab8d18 @ 0x140ab8d18 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab8d18(longlong param_1,undefined8 param_2,longlong param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 in_EAX;
  int iVar3;
  longlong lVar4;
  int iVar5;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000078;
  
  iVar5 = *(int *)(param_1 + 0x1a0);
  switch(in_EAX) {
  case 0:
    iVar5 = *(int *)(param_1 + 0x198);
    break;
  case 1:
    iVar5 = *(int *)(param_1 + 0x19c);
    break;
  case 3:
    iVar5 = *(int *)(param_1 + 0x1a4);
    break;
  case 6:
    iVar5 = *(int *)(param_1 + 0x200);
  }
  iVar3 = *(int *)(param_1 + 0x194);
  if (iVar5 != *(int *)(param_1 + 0x194)) {
    func_0x0001415c6440(param_3 + 0x68,&stack0x00000060,0);
    lVar4 = func_0x0001415ad2a0(0x1473d0730,in_stack_00000060);
    if (lVar4 != 0) {
      if (*(char *)(param_1 + 0x285) == '\0') {
        if (*(char *)(param_1 + 0x287) != '\0') {
          FUN_1415ceb00(lVar4,0xf8d44865,1);
        }
      }
      else {
        FUN_1415bf500();
      }
    }
    FUN_1415bae90();
    lVar4 = func_0x0001415ad2a0(0x1473d0730,in_stack_00000078);
    if ((lVar4 != 0) && (FUN_1415ceb00(lVar4,0x46434591,1), *(char *)(param_1 + 0x286) != '\0')) {
      FUN_1415ceb00(lVar4,0x5f118c92,1);
    }
    *(int *)(param_1 + 0x194) = iVar5;
    iVar3 = iVar5;
  }
  if (iVar3 == *(int *)(param_1 + 0x198)) {
    cVar2 = FUN_1415bfc60();
    bVar1 = false;
    if (cVar2 == '\0') goto LAB_140ab8e63;
  }
  bVar1 = true;
LAB_140ab8e63:
  if ((*(int *)(param_1 + 0x270) == 0) && ((bVar1 || (*(char *)(param_1 + 0x274) != '\0')))) {
    FUN_1415bae90();
    *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(param_1 + 0x1b4);
    *(undefined1 *)(param_1 + 0x274) = 0;
  }
  *(undefined2 *)(param_1 + 0x285) = 0;
  *(undefined1 *)(param_1 + 0x287) = 0;
  return;
}


/* SwingRegion_140ab8d78 @ 0x140ab8d78 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab8d78(undefined8 param_1)

{
  bool bVar1;
  char cVar2;
  longlong lVar3;
  longlong unaff_RBX;
  int unaff_EDI;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000078;
  
  func_0x0001415c6440(param_1,&stack0x00000060,0);
  lVar3 = func_0x0001415ad2a0(0x1473d0730,in_stack_00000060);
  if (lVar3 != 0) {
    if (*(char *)(unaff_RBX + 0x285) == '\0') {
      if (*(char *)(unaff_RBX + 0x287) != '\0') {
        FUN_1415ceb00(lVar3,0xf8d44865,1);
      }
    }
    else {
      FUN_1415bf500();
    }
  }
  FUN_1415bae90();
  lVar3 = func_0x0001415ad2a0(0x1473d0730,in_stack_00000078);
  if (lVar3 != 0) {
    FUN_1415ceb00(lVar3,0x46434591,1);
    if (*(char *)(unaff_RBX + 0x286) != '\0') {
      FUN_1415ceb00(lVar3,0x5f118c92,1);
    }
  }
  *(int *)(unaff_RBX + 0x194) = unaff_EDI;
  if (unaff_EDI == *(int *)(unaff_RBX + 0x198)) {
    cVar2 = FUN_1415bfc60();
    bVar1 = false;
    if (cVar2 == '\0') goto LAB_140ab8e63;
  }
  bVar1 = true;
LAB_140ab8e63:
  if ((*(int *)(unaff_RBX + 0x270) == 0) && ((bVar1 || (*(char *)(unaff_RBX + 0x274) != '\0')))) {
    FUN_1415bae90();
    *(undefined4 *)(unaff_RBX + 0x270) = *(undefined4 *)(unaff_RBX + 0x1b4);
    *(undefined1 *)(unaff_RBX + 0x274) = 0;
  }
  *(undefined2 *)(unaff_RBX + 0x285) = 0;
  *(undefined1 *)(unaff_RBX + 0x287) = 0;
  return;
}


/* SwingRegion_140ab8e3d @ 0x140ab8e3d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab8e3d(void)

{
  bool bVar1;
  char cVar2;
  int in_EAX;
  longlong unaff_RBX;
  
  if (in_EAX == *(int *)(unaff_RBX + 0x198)) {
    cVar2 = FUN_1415bfc60();
    bVar1 = false;
    if (cVar2 == '\0') goto LAB_140ab8e63;
  }
  bVar1 = true;
LAB_140ab8e63:
  if ((*(int *)(unaff_RBX + 0x270) == 0) && ((bVar1 || (*(char *)(unaff_RBX + 0x274) != '\0')))) {
    FUN_1415bae90();
    *(undefined4 *)(unaff_RBX + 0x270) = *(undefined4 *)(unaff_RBX + 0x1b4);
    *(undefined1 *)(unaff_RBX + 0x274) = 0;
  }
  *(undefined2 *)(unaff_RBX + 0x285) = 0;
  *(undefined1 *)(unaff_RBX + 0x287) = 0;
  return;
}


/* SwingRegion_140ab8e4a @ 0x140ab8e4a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab8e4a(void)

{
  char cVar1;
  longlong unaff_RBX;
  
  cVar1 = FUN_1415bfc60();
  if ((*(int *)(unaff_RBX + 0x270) == 0) &&
     ((cVar1 != '\0' || (*(char *)(unaff_RBX + 0x274) != '\0')))) {
    FUN_1415bae90();
    *(undefined4 *)(unaff_RBX + 0x270) = *(undefined4 *)(unaff_RBX + 0x1b4);
    *(undefined1 *)(unaff_RBX + 0x274) = 0;
  }
  *(undefined2 *)(unaff_RBX + 0x285) = 0;
  *(undefined1 *)(unaff_RBX + 0x287) = 0;
  return;
}


/* SwingRegion_140ab8ef0 @ 0x140ab8ef0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab8ef0(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong unaff_GS_OFFSET;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x28b) != '\0') {
    lVar1 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar1 + 0x88) == 0) {
      lVar1 = FUN_14167ab40(lVar1 + 0x58,0x147a51f80);
    }
    else {
      lVar1 = func_0x0001416799a0(lVar1 + 0x80);
    }
    if (lVar1 != 0) {
      if ((*(int *)(*(longlong *)
                     (*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)__tls_index * 8) + 0xa0a0)
           < _DAT_146df2788) && (FUN_143636f50(&DAT_146df2788), _DAT_146df2788 == -1)) {
        _DAT_146df2784 = FUN_141bb8a10(&UNK_1438ce948);
        FUN_143636ef0(&DAT_146df2788);
      }
      uVar3 = FUN_140ab42f0(param_1);
      uVar2 = 0;
      if (*(int *)(lVar1 + 0x154) != 0) {
        do {
          FUN_14196af10(*(undefined4 *)(lVar1 + ((ulonglong)uVar2 + 6) * 0xc),_DAT_146df2784,uVar3,
                        &UNK_1438ce948,&UNK_1438a8214,0,0);
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint *)(lVar1 + 0x154));
      }
    }
  }
  return;
}


/* SwingRegion_140ab9040 @ 0x140ab9040 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab9040(longlong param_1,float param_2,undefined8 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (*(int *)(param_1 + 0x194) == *(int *)(param_1 + 0x1a4)) {
    if ((*(float *)(param_1 + 0x1e4) <= 0.0 && *(float *)(param_1 + 0x1e4) != 0.0) ||
       (*(float *)(param_1 + 0x1e8) <= 0.0 && *(float *)(param_1 + 0x1e8) != 0.0)) {
      *(undefined4 *)(param_1 + 0x204) = 0;
      *(undefined1 *)(param_1 + 0x210) = 0;
    }
    else {
      fVar1 = (float)FUN_1415c09c0(param_3,0);
      fVar2 = (float)FUN_1415c05d0(param_3,0);
      fVar3 = (float)FUN_1415c0a10(param_3,0);
      fVar6 = _DAT_14382dce0;
      fVar5 = _DAT_14382dce0 / fVar2;
      fVar4 = fVar5 * *(float *)(param_1 + 0x1e8);
      if (_DAT_14382dce0 <= fVar4) {
        fVar4 = _DAT_14382dce0;
      }
      if (fVar4 < *(float *)(param_1 + 0x204) || fVar4 == *(float *)(param_1 + 0x204)) {
        fVar4 = (float)func_0x00014041c590(*(undefined4 *)(param_1 + 0x1bc),
                                           *(undefined4 *)(param_1 + 0x20c),
                                           *(undefined4 *)(param_1 + 0x1e4));
        fVar5 = fVar4 * (fVar6 - *(float *)(param_1 + 0x208)) + *(float *)(param_1 + 0x208);
      }
      else {
        *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(param_1 + 0x1bc);
        fVar5 = (fVar1 + param_2) * fVar5;
        if (fVar6 <= fVar5) {
          fVar5 = fVar6;
        }
        *(float *)(param_1 + 0x208) = fVar5;
      }
      *(float *)(param_1 + 0x204) = fVar5;
      if (_DAT_14382e118 <= param_2) {
        fVar6 = ((fVar5 - fVar3) * fVar2) / param_2;
        if (fVar6 <= _DAT_143830118) {
          fVar6 = _DAT_143830118;
        }
      }
      FUN_1415c2670(param_3,fVar6,0);
      *(undefined1 *)(param_1 + 0x210) = 1;
    }
  }
  else {
    FUN_1415c2c00(param_3,0x2ae17432,0);
    *(undefined4 *)(param_1 + 0x204) = 0;
    *(undefined1 *)(param_1 + 0x210) = 0;
  }
  return;
}


/* SwingRegion_140ab90ab @ 0x140ab90ab */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab90ab(undefined4 param_1)

{
  longlong unaff_RBX;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float unaff_XMM9_Da;
  
  fVar1 = (float)FUN_1415c09c0(param_1,0);
  fVar2 = (float)FUN_1415c05d0(fVar1,0);
  fVar3 = (float)FUN_1415c0a10(fVar2,0);
  fVar7 = _DAT_14382dce0;
  fVar4 = *(float *)(unaff_RBX + 0x1bc);
  fVar6 = _DAT_14382dce0 / fVar2;
  fVar5 = fVar6 * *(float *)(unaff_RBX + 0x1e8);
  if (_DAT_14382dce0 <= fVar5) {
    fVar5 = _DAT_14382dce0;
  }
  if (fVar5 < *(float *)(unaff_RBX + 0x204) || fVar5 == *(float *)(unaff_RBX + 0x204)) {
    fVar5 = (float)func_0x00014041c590(fVar4,*(undefined4 *)(unaff_RBX + 0x20c),
                                       *(undefined4 *)(unaff_RBX + 0x1e4));
    fVar4 = fVar7 - *(float *)(unaff_RBX + 0x208);
    fVar6 = fVar5 * fVar4 + *(float *)(unaff_RBX + 0x208);
  }
  else {
    *(float *)(unaff_RBX + 0x20c) = fVar4;
    fVar6 = (fVar1 + unaff_XMM9_Da) * fVar6;
    if (fVar7 <= fVar6) {
      fVar6 = fVar7;
    }
    *(float *)(unaff_RBX + 0x208) = fVar6;
  }
  *(float *)(unaff_RBX + 0x204) = fVar6;
  if (_DAT_14382e118 <= unaff_XMM9_Da) {
    fVar7 = ((fVar6 - fVar3) * fVar2) / unaff_XMM9_Da;
    if (fVar7 <= _DAT_143830118) {
      fVar7 = _DAT_143830118;
    }
  }
  FUN_1415c2670(fVar4,fVar7,0);
  *(undefined1 *)(unaff_RBX + 0x210) = 1;
  return;
}


/* SwingRegion_140ab91cc @ 0x140ab91cc */

void SwingRegion_140ab91cc(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined1 *)(param_1 + 0x210) = 0;
  return;
}


/* SwingRegion_140ab9200 @ 0x140ab9200 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab9200(longlong param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  undefined1 auStack_78 [112];
  
  fStack_94 = *(float *)(param_1 + 0x16c);
  fVar3 = *(float *)(param_1 + 0x160) - fStack_94;
  fStack_88 = *(float *)(param_1 + 0x15c);
  fStack_80 = *(float *)(param_1 + 0x164);
  fStack_98 = fStack_88 - *(float *)(param_1 + 0x168);
  fStack_90 = fStack_80 - *(float *)(param_1 + 0x170);
  fVar2 = (float)((uint)fStack_90 & _DAT_14382e160);
  if (fVar2 <= 0.0) {
    fVar2 = 0.0;
  }
  if (fVar2 <= (float)((uint)fStack_98 & _DAT_14382e160)) {
    fVar2 = (float)((uint)fStack_98 & _DAT_14382e160);
  }
  if (0.0 < fVar2) {
    fStack_90 = fStack_90 * (_DAT_14382dce0 / fVar2);
    fStack_98 = fStack_98 * (_DAT_14382dce0 / fVar2);
    fVar2 = _DAT_14382dce0 / SQRT(fStack_90 * fStack_90 + fStack_98 * fStack_98);
    fStack_90 = fVar2 * fStack_90;
    fStack_98 = fVar2 * fStack_98;
  }
  fStack_98 = *(float *)(param_1 + 0x168) + fStack_98;
  fStack_90 = *(float *)(param_1 + 0x170) + fStack_90;
  fStack_84 = fStack_94;
  fVar1 = (float)FUN_141c03d00(auStack_78,&fStack_88,&fStack_98,param_1 + 0x134,0);
  fVar2 = (float)FUN_1420dc660(param_1);
  fVar2 = (fVar2 - _DAT_14382f0dc) * _DAT_14386db58;
  if (fVar2 <= 0.0) {
    fVar2 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar2) {
    fVar2 = _DAT_14382dce0;
  }
  if (fVar2 <= fVar1) {
    fVar2 = fVar1;
  }
  if (fVar2 <= *(float *)(param_1 + 0x174)) {
    fVar2 = *(float *)(param_1 + 0x174);
  }
  *(float *)(param_1 + 0x174) = fVar2;
  *(ulonglong *)(param_1 + 0x150) =
       CONCAT44((fStack_94 - fStack_84) * fVar2 + fStack_84 + fVar3,
                (fStack_98 - fStack_88) * fVar2 + fStack_88);
  *(float *)(param_1 + 0x158) = (fStack_90 - fStack_80) * fVar2 + fStack_80;
  return;
}


/* SwingRegion_140ab9410 @ 0x140ab9410 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ab9410(longlong param_1,float param_2)

{
  float fVar1;
  char cVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 auStackX_8 [2];
  ulonglong in_stack_ffffffffffffff98;
  undefined4 uVar5;
  uint in_stack_ffffffffffffffa0;
  ulonglong in_stack_ffffffffffffffa8;
  
  fVar1 = *(float *)(param_1 + 0x100);
  if (0.0 <= fVar1) {
    if ((fVar1 <= param_2) && (0.0 <= param_2)) {
      *(undefined4 *)(param_1 + 0x100) = 0;
      lVar3 = *(longlong *)(param_1 + 8);
      if (*(short *)(lVar3 + 0x88) == 0) {
        lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dd77b0);
      }
      else {
        lVar3 = func_0x0001416799a0(lVar3 + 0x80);
      }
      if (lVar3 != 0) {
        in_stack_ffffffffffffffa0 = 0;
        in_stack_ffffffffffffff98 = 0;
        cVar2 = FUN_140677d20(lVar3,param_1 + 0xfc,2,*(char *)(param_1 + 0x281) == '\0',0,0,
                              in_stack_ffffffffffffffa8 & 0xffffffff00000000);
        if (cVar2 != '\0') {
          func_0x00014067d7c0(lVar3,*(undefined4 *)(param_1 + 0xfc),param_1 + 0x168);
        }
      }
      puVar4 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
      in_stack_ffffffffffffffa0 = in_stack_ffffffffffffffa0 & 0xffffff00;
      in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffff00000000;
      FUN_1416d5e80(0x147475690,0x21bbe6e8,*puVar4,0,in_stack_ffffffffffffff98,
                    in_stack_ffffffffffffffa0,0,0,1,0,0,0,0);
      uVar5 = (undefined4)(in_stack_ffffffffffffff98 >> 0x20);
      func_0x000141676900(param_1,auStackX_8);
      lVar3 = FUN_1416d5e80(0x147475690,0x7507304a,auStackX_8[0],auStackX_8,CONCAT44(uVar5,1),
                            in_stack_ffffffffffffffa0 & 0xffffff00,0,0,0,0,0,0,0);
      *(undefined4 *)(lVar3 + 0x13c) = 0x1d974ef7;
      *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x200;
      *(ulonglong *)(lVar3 + 0x18) = *(ulonglong *)(lVar3 + 0x18) | 0x200;
      *(undefined4 *)(param_1 + 0x100) = 0xbf800000;
      return;
    }
    *(float *)(param_1 + 0x100) = fVar1 - param_2;
  }
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dd77b0);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  if (lVar3 != 0) {
    if ((((*(char *)(param_1 + 0x281) != '\0') && (*(char *)(param_1 + 0xf0) != '\x01')) &&
        (*(int *)(param_1 + 0xfc) != 0)) && (*(char *)(param_1 + 0x283) == '\0')) {
      func_0x00014067d7c0(lVar3,*(int *)(param_1 + 0xfc),param_1 + 0x168);
      func_0x00014067d760(lVar3,*(undefined4 *)(param_1 + 0xfc),1);
      *(undefined1 *)(param_1 + 0x281) = 0;
    }
    if (*(int *)(param_1 + 0x270) != 0) {
      FUN_140960540(lVar3,*(undefined4 *)(param_1 + 0xfc),_DAT_14382ee8c);
    }
    if ((*(int *)(param_1 + 0x194) != *(int *)(param_1 + 0x198)) &&
       (*(char *)(param_1 + 0x282) != '\0')) {
      FUN_1409604f0(lVar3,*(undefined4 *)(param_1 + 0xfc));
    }
  }
  return;
}


/* SwingRegion_140ab944b @ 0x140ab944b */

void SwingRegion_140ab944b(longlong param_1)

{
  undefined4 *puVar1;
  char cVar2;
  longlong lVar3;
  longlong unaff_RBX;
  ulonglong in_stack_00000020;
  undefined4 uVar4;
  undefined4 in_stack_00000090;
  
  *(undefined4 *)(param_1 + 0x100) = 0;
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dd77b0);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  if (lVar3 != 0) {
    in_stack_00000020 = 0;
    cVar2 = FUN_140677d20(lVar3,unaff_RBX + 0xfc,2,*(char *)(unaff_RBX + 0x281) == '\0',0);
    if (cVar2 != '\0') {
      func_0x00014067d7c0(lVar3,*(undefined4 *)(unaff_RBX + 0xfc),unaff_RBX + 0x168);
    }
  }
  puVar1 = (undefined4 *)func_0x000141676900();
  in_stack_00000020 = in_stack_00000020 & 0xffffffff00000000;
  FUN_1416d5e80(0x147475690,0x21bbe6e8,*puVar1,0,in_stack_00000020);
  uVar4 = (undefined4)(in_stack_00000020 >> 0x20);
  func_0x000141676900();
  lVar3 = FUN_1416d5e80(0x147475690,0x7507304a,in_stack_00000090,&stack0x00000090,CONCAT44(uVar4,1))
  ;
  *(undefined4 *)(lVar3 + 0x13c) = 0x1d974ef7;
  *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x200;
  *(ulonglong *)(lVar3 + 0x18) = *(ulonglong *)(lVar3 + 0x18) | 0x200;
  *(undefined4 *)(unaff_RBX + 0x100) = 0xbf800000;
  return;
}


/* SwingRegion_140ab94b6 @ 0x140ab94b6 */

void SwingRegion_140ab94b6(void)

{
  undefined4 *puVar1;
  char cVar2;
  longlong lVar3;
  longlong unaff_RBX;
  undefined4 in_stack_00000090;
  
  cVar2 = FUN_140677d20();
  if (cVar2 != '\0') {
    func_0x00014067d7c0();
  }
  puVar1 = (undefined4 *)func_0x000141676900();
  FUN_1416d5e80(0x147475690,0x21bbe6e8,*puVar1,0);
  func_0x000141676900();
  lVar3 = FUN_1416d5e80(0x147475690,0x7507304a,in_stack_00000090,&stack0x00000090,1);
  *(undefined4 *)(lVar3 + 0x13c) = 0x1d974ef7;
  *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x200;
  *(ulonglong *)(lVar3 + 0x18) = *(ulonglong *)(lVar3 + 0x18) | 0x200;
  *(undefined4 *)(unaff_RBX + 0x100) = 0xbf800000;
  return;
}


/* SwingRegion_140ab94e4 @ 0x140ab94e4 */

void SwingRegion_140ab94e4(void)

{
  undefined4 *puVar1;
  longlong lVar2;
  longlong unaff_RBX;
  undefined4 in_stack_00000090;
  
  puVar1 = (undefined4 *)func_0x000141676900();
  FUN_1416d5e80(0x147475690,0x21bbe6e8,*puVar1,0);
  func_0x000141676900();
  lVar2 = FUN_1416d5e80(0x147475690,0x7507304a,in_stack_00000090,&stack0x00000090,1);
  *(undefined4 *)(lVar2 + 0x13c) = 0x1d974ef7;
  *(ulonglong *)(lVar2 + 8) = *(ulonglong *)(lVar2 + 8) | 0x200;
  *(ulonglong *)(lVar2 + 0x18) = *(ulonglong *)(lVar2 + 0x18) | 0x200;
  *(undefined4 *)(unaff_RBX + 0x100) = 0xbf800000;
  return;
}


/* SwingRegion_140ab95cb @ 0x140ab95cb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ab95cb(float param_1,float param_2)

{
  longlong lVar1;
  longlong in_RCX;
  longlong unaff_RBX;
  
  *(float *)(in_RCX + 0x100) = param_1 - param_2;
  lVar1 = *(longlong *)(in_RCX + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    lVar1 = FUN_14167ab40(lVar1 + 0x58,0x146dd77b0);
  }
  else {
    lVar1 = func_0x0001416799a0(lVar1 + 0x80);
  }
  if (lVar1 != 0) {
    if ((((*(char *)(unaff_RBX + 0x281) != '\0') && (*(char *)(unaff_RBX + 0xf0) != '\x01')) &&
        (*(int *)(unaff_RBX + 0xfc) != 0)) && (*(char *)(unaff_RBX + 0x283) == '\0')) {
      func_0x00014067d7c0(lVar1,*(int *)(unaff_RBX + 0xfc),unaff_RBX + 0x168);
      func_0x00014067d760(lVar1,*(undefined4 *)(unaff_RBX + 0xfc),1);
      *(undefined1 *)(unaff_RBX + 0x281) = 0;
    }
    if (*(int *)(unaff_RBX + 0x270) != 0) {
      FUN_140960540(lVar1,*(undefined4 *)(unaff_RBX + 0xfc),_DAT_14382ee8c);
    }
    if ((*(int *)(unaff_RBX + 0x194) != *(int *)(unaff_RBX + 0x198)) &&
       (*(char *)(unaff_RBX + 0x282) != '\0')) {
      FUN_1409604f0(lVar1,*(undefined4 *)(unaff_RBX + 0xfc));
    }
  }
  return;
}


/* SwingRegion_140ab96c0 @ 0x140ab96c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140ab96c0(longlong param_1,undefined4 param_2,longlong param_3)

{
  byte bVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  fVar6 = (float)FUN_1420dc660();
  fVar6 = (fVar6 - _DAT_14382e120) * _DAT_1438627c8;
  fVar8 = ((float)((uint)*(float *)(param_1 + 0x230) & _DAT_14382e160) - _DAT_14382f0e0) *
          _DAT_1438929bc;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  if (fVar8 <= 0.0) {
    fVar8 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar6) {
    fVar6 = _DAT_14382dce0;
  }
  if (_DAT_14382dce0 <= fVar8) {
    fVar8 = _DAT_14382dce0;
  }
  if (0.0 <= *(float *)(param_1 + 0x230)) {
    fVar6 = _DAT_14382dce0 - fVar8 * fVar6;
  }
  else {
    fVar6 = fVar8 * fVar6 + _DAT_14382dce0;
  }
  uVar7 = FUN_141c46be0(*(undefined4 *)(param_1 + 0x248),fVar6 * _DAT_14382e128,param_1 + 0x24c,
                        _DAT_1438ac770,_DAT_143841320,_DAT_14382ee90,CONCAT44(uVar7,param_2));
  *(undefined4 *)(param_1 + 0x248) = uVar7;
  if ((*(ushort *)(*(ulonglong *)(param_3 + 8) + 8) >> 10 & 1) != 0) {
    return *(ulonglong *)(param_3 + 8) & 0xffffffffffffff00;
  }
  bVar1 = FUN_1415c83b0(param_3 + 0x68,&stack0x00000008,0x31b78a49,1,
                        CONCAT44(unaff_XMM6_Db,unaff_XMM6_Da),CONCAT44(unaff_XMM6_Dd,unaff_XMM6_Dc))
  ;
  if (bVar1 != 0) {
    *(undefined4 *)(param_3 + 0x878) = 0xffffffff;
  }
  uVar3 = *(uint *)(param_3 + 0xea8);
  uVar4 = 0;
  uVar5 = 1;
  while (uVar3 != 0) {
    if ((uVar3 & uVar5) != 0) {
      plVar2 = (longlong *)func_0x0001416798f0(param_3 + 0xeac + uVar4 * 4);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x70))(plVar2,0x31b78a49,uVar7);
      }
      uVar3 = uVar3 ^ uVar5;
    }
    uVar5 = uVar5 * 2;
    uVar4 = (ulonglong)((int)uVar4 + 1);
  }
  return (ulonglong)bVar1;
}


/* SwingRegion_140ab97e0 @ 0x140ab97e0 */

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
  puVar8 = (undefined8 *)&DAT_147afdf10;
  if ((undefined8 *)**(undefined8 **)(param_1 + 8) != (undefined8 *)0x0) {
    puVar8 = (undefined8 *)**(undefined8 **)(param_1 + 8);
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


/* SwingRegion_140aba1f0 @ 0x140aba1f0 */

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


/* SwingRegion_140aba2e8 @ 0x140aba2e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 SwingRegion_140aba2e8(void)

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
  char unaff_BL;
  char cVar14;
  char unaff_SIL;
  longlong unaff_RDI;
  undefined8 uVar15;
  bool bVar16;
  float fVar17;
  float fVar18;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  float extraout_XMM0_Da_01;
  float fVar19;
  float fVar20;
  undefined8 *puVar21;
  undefined4 uVar23;
  ulonglong uVar22;
  undefined4 in_stack_00000080;
  undefined4 uStack0000000000000098;
  undefined4 uStack000000000000009c;
  undefined4 in_stack_000000d0;
  undefined4 in_stack_000000d8;
  undefined4 in_stack_000000e0;
  undefined4 in_stack_000000e8;
  undefined4 in_stack_00000138;
  
  cVar8 = FUN_140b91970();
  if ((cVar8 == '\0') || (unaff_SIL != '\0')) {
    iVar10 = FUN_140ac2200();
    cVar8 = '\0';
    if (unaff_SIL == '\0') goto LAB_140aba31b;
  }
  else {
    cVar8 = '\x01';
    iVar10 = FUN_140ac2200();
LAB_140aba31b:
    if (iVar10 != 1) {
      cVar14 = '\0';
      goto LAB_140aba328;
    }
  }
  cVar14 = '\x01';
LAB_140aba328:
  if ((unaff_BL == '\0') && (iVar10 != 2)) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  bVar16 = iVar10 == 2;
  bVar7 = true;
  if ((((iVar10 == 0) && (bVar6)) && (cVar14 == '\0')) &&
     ((cVar8 == '\0' &&
      (cVar9 = *(char *)(unaff_RDI + 0x5fb), *(char *)(unaff_RDI + 0x5fb) = cVar9 + -1, '\0' < cVar9
      )))) {
    bVar7 = false;
  }
  plVar5 = *(longlong **)(unaff_RDI + 0x108);
  if ((*(byte *)((longlong)plVar5 + 0x157) & 1) != 0) {
    bVar6 = true;
    bVar7 = true;
  }
  if ((((*(char *)(unaff_RDI + 0x580) == '\x03') ||
       ((fVar17 = (float)FUN_1402c2450(unaff_RDI + 0x4b8), fVar17 <= _DAT_143830120 &&
        (*(float *)(unaff_RDI + 0x424) <= _DAT_14382ee88)))) ||
      (cVar9 = (**(code **)(*plVar5 + 0x3e0))(plVar5,0x100,0,0), cVar9 == '\0')) &&
     (cVar9 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x308))
                        (*(longlong **)(unaff_RDI + 0x108),1,1,0), cVar9 == '\0')) {
    fVar17 = (float)FUN_140876340(unaff_RDI + 0x4d0);
    fVar18 = (float)FUN_1420dc660();
    uVar12 = _DAT_14382e160;
    if ((fVar18 < _DAT_143839a5c) ||
       ((*(int *)(unaff_RDI + 0x574) == 0 &&
        (_DAT_1438388cc < (float)((uint)(fVar17 * _DAT_143830124) & _DAT_14382e160))))) {
      uVar15 = 1;
    }
    else {
      uVar15 = 0;
    }
    cVar9 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x2c8))
                      (*(longlong **)(unaff_RDI + 0x108),uVar15);
    if (cVar9 == '\0') {
      fVar20 = 0.0;
      fVar17 = (float)((uint)*(float *)(unaff_RDI + 0x4b8) & uVar12);
      fVar18 = (float)((uint)*(float *)(unaff_RDI + 0x4c0) & uVar12);
      if (fVar17 <= fVar18) {
        fVar17 = fVar18;
      }
      fVar19 = *(float *)(unaff_RDI + 0x4b8) * (_DAT_14382dce0 / fVar17);
      fVar18 = *(float *)(unaff_RDI + 0x4c0) * (_DAT_14382dce0 / fVar17);
      if (0.0 < fVar17) {
        fVar20 = SQRT(fVar18 * fVar18 + fVar19 * fVar19) * fVar17;
      }
      cVar9 = func_0x000140b8fcf0(unaff_RDI + 0x120,&stack0x00000068);
      if ((((cVar9 == '\0') || (fVar20 <= _DAT_14382f0e0)) ||
          (cVar9 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x488))
                             (*(longlong **)(unaff_RDI + 0x108),unaff_RDI + 0x4b8,&stack0x00000068),
          cVar9 == '\0')) &&
         (((cVar9 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x2f0))
                              (*(longlong **)(unaff_RDI + 0x108),0), cVar9 == '\0' &&
           (cVar9 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x2e0))
                              (*(longlong **)(unaff_RDI + 0x108),0), cVar9 == '\0')) &&
          ((fVar17 = (float)FUN_1420dc660(), _DAT_14382ee8c <= fVar17 ||
           (cVar9 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x2a0))
                              (*(longlong **)(unaff_RDI + 0x108),0,0), cVar9 == '\0')))))) {
        fVar17 = (float)FUN_1420dc660();
        if ((*(float *)(unaff_RDI + 0x450) <= fVar17 && fVar17 != *(float *)(unaff_RDI + 0x450)) &&
           ((((bVar6 || (cVar14 != '\0')) || (cVar8 != '\0')) && (bVar7)))) {
          lVar13 = *(longlong *)(unaff_RDI + 8);
          if (*(short *)(lVar13 + 0x88) == 0) {
            lVar13 = FUN_14167ab40(lVar13 + 0x58,0x146df2690);
            uVar11 = extraout_XMM0_Da_00;
          }
          else {
            lVar13 = func_0x0001416799a0(lVar13 + 0x80);
            uVar11 = extraout_XMM0_Da;
          }
          cVar9 = *(char *)(lVar13 + 0x282);
          puVar1 = (undefined4 *)(unaff_RDI + 0x53c);
          uVar4 = *(undefined1 *)(lVar13 + 0x281);
          puVar2 = (undefined8 *)(unaff_RDI + 0x540);
          puVar21 = puVar2;
          FUN_140ac1680(uVar11,cVar14,cVar8,bVar16,puVar2);
          uVar15 = CONCAT44((int)((ulonglong)puVar21 >> 0x20),*puVar1);
          uVar11 = FUN_140ac0ff0(*puVar1,cVar14,cVar8,puVar2,uVar15);
          uVar23 = (undefined4)((ulonglong)uVar15 >> 0x20);
          *(char *)(unaff_RDI + 0x538) = cVar14;
          uVar12 = func_0x000141bbb790();
          *(byte *)(unaff_RDI + 0x53a) = ~(byte)(uVar12 >> 0xf) & 1;
          if (cVar9 == '\0') {
            *(undefined1 *)(unaff_RDI + 0x53a) = uVar4;
          }
          if ((byte)(*(char *)(unaff_RDI + 0x580) - 2U) < 2) {
            uVar11 = 0xaa782917;
            *puVar2 = CONCAT44(_DAT_14384e300,_DAT_143854908);
            *(undefined4 *)(unaff_RDI + 0x548) = 0x80000000;
            in_stack_00000138 = FUN_14085fbb0(*(undefined8 *)(unaff_RDI + 8));
            *puVar1 = in_stack_00000138;
          }
          func_0x0001408687b0(&stack0x00000080);
          uStack0000000000000098 = *puVar1;
          in_stack_00000080 = uVar11;
          uStack000000000000009c = in_stack_00000138;
          cVar9 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x290))
                            (*(longlong **)(unaff_RDI + 0x108),puVar2,&stack0x00000080,0xff,
                             CONCAT44(uVar23,-(uint)(*(char *)(unaff_RDI + 0x53a) != '\0')) &
                             0xffffffff00000400);
          fVar17 = extraout_XMM0_Da_01;
          if (cVar9 != '\0') {
            return 1;
          }
        }
        uVar3 = unaff_RDI + 0x540;
        uVar22 = uVar3;
        FUN_140ac1680(fVar17,cVar14,cVar8,bVar16,uVar3);
        cVar8 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x158))
                          (*(longlong **)(unaff_RDI + 0x108),uVar3,bVar16);
        if (((cVar8 == '\0') &&
            (cVar8 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x160))
                               (*(longlong **)(unaff_RDI + 0x108),0,1), cVar8 == '\0')) &&
           (cVar8 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x2f8))(), cVar8 == '\0')) {
          lVar13 = func_0x0001409c87f0();
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
          cVar8 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x2c0))
                            (*(longlong **)(unaff_RDI + 0x108),0,uVar15);
          if (((cVar8 == '\0') &&
              (cVar8 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 0x2e8))
                                 (*(longlong **)(unaff_RDI + 0x108),0,0), cVar8 == '\0')) &&
             (cVar8 = (**(code **)(**(longlong **)(unaff_RDI + 0x108) + 200))
                                (*(longlong **)(unaff_RDI + 0x108),_DAT_143837a20,0,0,
                                 uVar22 & 0xffffffff00000000), cVar8 == '\0')) {
            return 0;
          }
        }
      }
    }
  }
  return 1;
}


/* SwingRegion_140aba8a0 @ 0x140aba8a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140aba8a0(longlong param_1,longlong param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 auStackX_8 [2];
  undefined4 auStackX_10 [2];
  undefined4 auStackX_20 [2];
  undefined4 *puVar13;
  undefined8 uStack_78;
  undefined4 uStack_70;
  undefined8 uStack_6c;
  undefined4 uStack_64;
  
  FUN_1409c86b0();
  uVar9 = _DAT_14382e13c;
  uVar2 = _DAT_14382e13c;
  uVar11 = _DAT_14383fd4c;
  uVar3 = _DAT_14383fd4c;
  if (*(char *)(param_1 + 0x539) != '\0') {
    uVar9 = _DAT_14382dce0;
    uVar2 = _DAT_143839a5c;
    uVar11 = _DAT_14382dce0;
    uVar3 = _DAT_143839a5c;
  }
  uVar12 = _DAT_143836d08;
  if (*(char *)(param_1 + 0x538) == '\0') {
    uVar9 = uVar2;
    uVar11 = uVar3;
    uVar12 = 0;
  }
  lVar6 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar6 + 0x88) == 0) {
    lVar6 = FUN_14167ab40(lVar6 + 0x58,0x146dacd70);
  }
  else {
    lVar6 = func_0x0001416799a0(lVar6 + 0x80);
  }
  if (lVar6 != 0) {
    FUN_140861a90(lVar6,*(undefined4 *)(param_1 + 0x52c),*(undefined4 *)(param_1 + 0x528));
    FUN_140861bd0(lVar6,uVar9,uVar11);
    FUN_140861c50(lVar6,*(undefined4 *)(param_1 + 0x52c));
    FUN_1408615f0(lVar6,*(undefined4 *)(param_1 + 0x52c));
    uVar9 = FUN_1420dc660(param_1);
    func_0x000140861290(lVar6,*(undefined4 *)(param_1 + 0x534),uVar9);
    func_0x00014085e310(lVar6);
  }
  lVar7 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar7 + 0x88) == 0) {
    lVar7 = FUN_14167ab40(lVar7 + 0x58,0x146dd8220);
  }
  else {
    lVar7 = func_0x0001416799a0(lVar7 + 0x80);
  }
  if (lVar7 != 0) {
    *(undefined4 *)(lVar7 + 0x274) = *(undefined4 *)(param_1 + 0x52c);
  }
  lVar7 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar7 + 0x88) == 0) {
    lVar7 = FUN_14167ab40(lVar7 + 0x58,0x146dd6e90);
  }
  else {
    lVar7 = func_0x0001416799a0(lVar7 + 0x80);
  }
  if (lVar7 != 0) {
    func_0x0001409488c0(lVar7,uVar12);
  }
  uStack_78 = *(undefined8 *)(param_1 + 0x444);
  uStack_70 = *(undefined4 *)(param_1 + 0x44c);
  uStack_6c = *(undefined8 *)(param_1 + 0x4b8);
  uStack_64 = *(undefined4 *)(param_1 + 0x4c0);
  func_0x000140861950(lVar6,&uStack_78);
  puVar13 = auStackX_8;
  cVar5 = FUN_140ac1430(param_1,*(undefined1 *)(param_1 + 0x538),auStackX_20,auStackX_10,puVar13);
  if ((cVar5 != '\0') && (*(char *)(param_1 + 0x5f7) == '\0')) {
    FUN_140861de0(lVar6,auStackX_20[0],auStackX_10[0],auStackX_8[0]);
  }
  lVar6 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar6 + 0x88) == 0) {
    lVar6 = FUN_14167ab40(lVar6 + 0x58,0x146dd6030);
  }
  else {
    lVar6 = func_0x0001416799a0(lVar6 + 0x80);
  }
  FUN_140911560(lVar6,0,0);
  *(undefined8 *)(lVar6 + 0x134) = 0;
  *(undefined4 *)(lVar6 + 0x13c) = 0;
  *(undefined1 *)(lVar6 + 0x140) = 0;
  if (param_2 != 0) {
    cVar5 = func_0x0001416766e0(param_2,0x146deece0);
    uVar4 = _DAT_14382e124;
    if ((cVar5 != '\0') && (fVar1 = *(float *)(param_1 + 0x544), _DAT_14382e118 < fVar1)) {
      uVar10 = _DAT_14382e124;
      if (_DAT_14382e118 < (float)((uint)*(float *)(param_1 + 0x53c) & _DAT_14382e160)) {
        uVar10 = (uint)(fVar1 / *(float *)(param_1 + 0x53c)) & _DAT_14382e160;
      }
      FUN_140897a50(lVar6 + 0x6c0,fVar1,uVar10);
    }
    func_0x000140990550(*(undefined8 *)(param_1 + 0x108));
    func_0x0001409908a0(*(undefined8 *)(param_1 + 0x108),uVar4);
  }
  puVar8 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
  FUN_1416d5e80(0x147475690,0xcdd16db5,*puVar8,0,(ulonglong)puVar13 & 0xffffffff00000000,0,0,0,1,0,0
                ,0,0);
  return;
}


/* SwingRegion_140aba8bf @ 0x140aba8bf */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140aba8bf(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  longlong in_RAX;
  longlong lVar6;
  longlong lVar7;
  undefined4 *puVar8;
  longlong unaff_RBX;
  longlong unaff_RBP;
  undefined4 uVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined4 unaff_XMM8_Da;
  undefined4 uVar12;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 uVar13;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 *puVar14;
  undefined8 in_stack_00000070;
  undefined4 in_stack_00000078;
  undefined8 uStack000000000000007c;
  undefined4 uStack0000000000000084;
  undefined4 in_stack_000000f0;
  undefined4 in_stack_000000f8;
  undefined4 in_stack_00000108;
  
  *(undefined4 *)(in_RAX + -0x48) = unaff_XMM8_Da;
  *(undefined4 *)(in_RAX + -0x44) = unaff_XMM8_Db;
  *(undefined4 *)(in_RAX + -0x40) = unaff_XMM8_Dc;
  *(undefined4 *)(in_RAX + -0x3c) = unaff_XMM8_Dd;
  *(undefined4 *)(in_RAX + -0x58) = unaff_XMM9_Da;
  *(undefined4 *)(in_RAX + -0x54) = unaff_XMM9_Db;
  *(undefined4 *)(in_RAX + -0x50) = unaff_XMM9_Dc;
  *(undefined4 *)(in_RAX + -0x4c) = unaff_XMM9_Dd;
  FUN_1409c86b0();
  uVar9 = _DAT_14382e13c;
  uVar2 = _DAT_14382e13c;
  uVar12 = _DAT_14383fd4c;
  uVar3 = _DAT_14383fd4c;
  if (*(char *)(unaff_RBX + 0x539) != '\0') {
    uVar9 = _DAT_14382dce0;
    uVar2 = _DAT_143839a5c;
    uVar12 = _DAT_14382dce0;
    uVar3 = _DAT_143839a5c;
  }
  uVar13 = _DAT_143836d08;
  if (*(char *)(unaff_RBX + 0x538) == '\0') {
    uVar9 = uVar2;
    uVar12 = uVar3;
    uVar13 = 0;
  }
  lVar6 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar6 + 0x88) == 0) {
    lVar6 = FUN_14167ab40(lVar6 + 0x58,0x146dacd70);
  }
  else {
    lVar6 = func_0x0001416799a0(lVar6 + 0x80);
  }
  if (lVar6 != 0) {
    FUN_140861a90(lVar6,*(undefined4 *)(unaff_RBX + 0x52c),*(undefined4 *)(unaff_RBX + 0x528));
    FUN_140861bd0(lVar6,uVar9,uVar12);
    FUN_140861c50(lVar6,*(undefined4 *)(unaff_RBX + 0x52c));
    FUN_1408615f0(lVar6,*(undefined4 *)(unaff_RBX + 0x52c));
    uVar9 = FUN_1420dc660();
    func_0x000140861290(lVar6,*(undefined4 *)(unaff_RBX + 0x534),uVar9);
    func_0x00014085e310(lVar6);
  }
  lVar7 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar7 + 0x88) == 0) {
    lVar7 = FUN_14167ab40(lVar7 + 0x58,0x146dd8220);
  }
  else {
    lVar7 = func_0x0001416799a0(lVar7 + 0x80);
  }
  if (lVar7 != 0) {
    *(undefined4 *)(lVar7 + 0x274) = *(undefined4 *)(unaff_RBX + 0x52c);
  }
  lVar7 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar7 + 0x88) == 0) {
    lVar7 = FUN_14167ab40(lVar7 + 0x58,0x146dd6e90);
  }
  else {
    lVar7 = func_0x0001416799a0(lVar7 + 0x80);
  }
  if (lVar7 != 0) {
    func_0x0001409488c0(lVar7,uVar13);
  }
  in_stack_00000070 = *(undefined8 *)(unaff_RBX + 0x444);
  in_stack_00000078 = *(undefined4 *)(unaff_RBX + 0x44c);
  uStack000000000000007c = *(undefined8 *)(unaff_RBX + 0x4b8);
  uStack0000000000000084 = *(undefined4 *)(unaff_RBX + 0x4c0);
  uVar10 = func_0x000140861950(lVar6,&stack0x00000070);
  puVar14 = &stack0x000000f0;
  cVar5 = FUN_140ac1430(uVar10,*(undefined1 *)(unaff_RBX + 0x538),&stack0x00000108,&stack0x000000f8,
                        puVar14);
  if ((cVar5 != '\0') && (*(char *)(unaff_RBX + 0x5f7) == '\0')) {
    FUN_140861de0(lVar6,in_stack_00000108,in_stack_000000f8,in_stack_000000f0);
  }
  lVar6 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar6 + 0x88) == 0) {
    lVar6 = FUN_14167ab40(lVar6 + 0x58,0x146dd6030);
  }
  else {
    lVar6 = func_0x0001416799a0(lVar6 + 0x80);
  }
  uVar10 = FUN_140911560(lVar6,0,0);
  *(undefined8 *)(lVar6 + 0x134) = 0;
  *(undefined4 *)(lVar6 + 0x13c) = 0;
  *(undefined1 *)(lVar6 + 0x140) = 0;
  if (unaff_RBP != 0) {
    cVar5 = func_0x0001416766e0(uVar10,0x146deece0);
    uVar4 = _DAT_14382e124;
    if ((cVar5 != '\0') && (fVar1 = *(float *)(unaff_RBX + 0x544), _DAT_14382e118 < fVar1)) {
      uVar11 = _DAT_14382e124;
      if (_DAT_14382e118 < (float)((uint)*(float *)(unaff_RBX + 0x53c) & _DAT_14382e160)) {
        uVar11 = (uint)(fVar1 / *(float *)(unaff_RBX + 0x53c)) & _DAT_14382e160;
      }
      FUN_140897a50(lVar6 + 0x6c0,fVar1,uVar11);
    }
    func_0x000140990550(*(undefined8 *)(unaff_RBX + 0x108));
    uVar10 = func_0x0001409908a0(*(undefined8 *)(unaff_RBX + 0x108),uVar4);
  }
  puVar8 = (undefined4 *)func_0x000141676900(uVar10,&stack0x000000f0);
  FUN_1416d5e80(0x147475690,0xcdd16db5,*puVar8,0,(ulonglong)puVar14 & 0xffffffff00000000);
  return;
}


/* SwingRegion_140aba9ef @ 0x140aba9ef */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140aba9ef(longlong param_1)

{
  float fVar1;
  uint uVar2;
  char cVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong unaff_RBX;
  longlong unaff_RBP;
  undefined1 *unaff_RSI;
  undefined8 uVar6;
  undefined8 extraout_XMM0_Qa;
  uint uVar7;
  undefined4 *puVar8;
  undefined8 in_stack_00000070;
  undefined4 in_stack_00000078;
  undefined8 uStack000000000000007c;
  undefined4 uStack0000000000000084;
  undefined4 in_stack_000000f0;
  undefined4 in_stack_000000f8;
  undefined4 in_stack_00000108;
  
  lVar4 = func_0x0001416799a0(param_1 + 0x80);
  if (lVar4 != 0) {
    *(undefined4 *)(lVar4 + 0x274) = *(undefined4 *)(unaff_RBX + 0x52c);
  }
  lVar4 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    lVar4 = FUN_14167ab40(lVar4 + 0x58,0x146dd6e90);
  }
  else {
    lVar4 = func_0x0001416799a0(lVar4 + 0x80);
  }
  if (lVar4 != 0) {
    func_0x0001409488c0(lVar4);
  }
  in_stack_00000070 = *(undefined8 *)(unaff_RBX + 0x444);
  in_stack_00000078 = *(undefined4 *)(unaff_RBX + 0x44c);
  uStack000000000000007c = *(undefined8 *)(unaff_RBX + 0x4b8);
  uStack0000000000000084 = *(undefined4 *)(unaff_RBX + 0x4c0);
  uVar6 = func_0x000140861950(uStack000000000000007c,&stack0x00000070);
  puVar8 = &stack0x000000f0;
  cVar3 = FUN_140ac1430(uVar6,*unaff_RSI,&stack0x00000108,&stack0x000000f8,puVar8);
  if ((cVar3 != '\0') && (*(char *)(unaff_RBX + 0x5f7) == '\0')) {
    FUN_140861de0(extraout_XMM0_Qa,in_stack_00000108,in_stack_000000f8,in_stack_000000f0);
  }
  lVar4 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    lVar4 = FUN_14167ab40(lVar4 + 0x58,0x146dd6030);
  }
  else {
    lVar4 = func_0x0001416799a0(lVar4 + 0x80);
  }
  uVar6 = FUN_140911560(lVar4,0,0);
  *(undefined8 *)(lVar4 + 0x134) = 0;
  *(undefined4 *)(lVar4 + 0x13c) = 0;
  *(undefined1 *)(lVar4 + 0x140) = 0;
  if (unaff_RBP != 0) {
    cVar3 = func_0x0001416766e0(uVar6,0x146deece0);
    uVar2 = _DAT_14382e124;
    if ((cVar3 != '\0') && (fVar1 = *(float *)(unaff_RBX + 0x544), _DAT_14382e118 < fVar1)) {
      uVar7 = _DAT_14382e124;
      if (_DAT_14382e118 < (float)((uint)*(float *)(unaff_RBX + 0x53c) & _DAT_14382e160)) {
        uVar7 = (uint)(fVar1 / *(float *)(unaff_RBX + 0x53c)) & _DAT_14382e160;
      }
      FUN_140897a50(lVar4 + 0x6c0,fVar1,uVar7);
    }
    func_0x000140990550(*(undefined8 *)(unaff_RBX + 0x108));
    uVar6 = func_0x0001409908a0(*(undefined8 *)(unaff_RBX + 0x108),uVar2);
  }
  puVar5 = (undefined4 *)func_0x000141676900(uVar6,&stack0x000000f0);
  FUN_1416d5e80(0x147475690,0xcdd16db5,*puVar5,0,(ulonglong)puVar8 & 0xffffffff00000000);
  return;
}


/* SwingRegion_140abaac6 @ 0x140abaac6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abaac6(undefined4 param_1)

{
  float fVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  longlong lVar5;
  longlong unaff_RBX;
  longlong unaff_RBP;
  undefined4 uVar6;
  uint uVar7;
  undefined4 in_stack_000000f0;
  undefined4 in_stack_000000f8;
  undefined4 in_stack_00000108;
  
  if (*(char *)(unaff_RBX + 0x5f7) == '\0') {
    FUN_140861de0(param_1,in_stack_00000108,in_stack_000000f8,in_stack_000000f0);
  }
  lVar5 = *(longlong *)(unaff_RBX + 8);
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x146dd6030);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  uVar6 = FUN_140911560(lVar5,0,0);
  *(undefined8 *)(lVar5 + 0x134) = 0;
  *(undefined4 *)(lVar5 + 0x13c) = 0;
  *(undefined1 *)(lVar5 + 0x140) = 0;
  if (unaff_RBP != 0) {
    cVar4 = func_0x0001416766e0(uVar6,0x146deece0);
    uVar3 = _DAT_14382e124;
    if ((cVar4 != '\0') && (fVar1 = *(float *)(unaff_RBX + 0x544), _DAT_14382e118 < fVar1)) {
      uVar7 = _DAT_14382e124;
      if (_DAT_14382e118 < (float)((uint)*(float *)(unaff_RBX + 0x53c) & _DAT_14382e160)) {
        uVar7 = (uint)(fVar1 / *(float *)(unaff_RBX + 0x53c)) & _DAT_14382e160;
      }
      FUN_140897a50(lVar5 + 0x6c0,fVar1,uVar7);
    }
    func_0x000140990550(*(undefined8 *)(unaff_RBX + 0x108));
    uVar6 = func_0x0001409908a0(*(undefined8 *)(unaff_RBX + 0x108),uVar3);
  }
  puVar2 = (undefined4 *)func_0x000141676900(uVar6,&stack0x000000f0);
  FUN_1416d5e80(0x147475690,0xcdd16db5,*puVar2,0,0);
  return;
}


/* SwingRegion_140abac40 @ 0x140abac40 */

undefined8 * FUN_140abac40(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &UNK_1438baf50;
  func_0x000141676000();
  if ((param_2 & 1) != 0) {
    func_0x000143636c9c(param_1,0x600);
  }
  return param_1;
}


/* SwingRegion_140abac80 @ 0x140abac80 */

void FUN_140abac80(longlong *param_1,uint param_2,float param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (0 < (int)param_2) {
    uVar2 = (ulonglong)param_2;
    do {
      lVar1 = *param_1;
      param_1 = param_1 + 1;
      if (((*(byte *)(lVar1 + 0x1d) & 2) == 0) && ((*(byte *)(lVar1 + 0x1d) & 1) != 0)) {
        FUN_140ac30e0(lVar1,param_3 * *(float *)(lVar1 + 0x10));
      }
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}


/* SwingRegion_140abac91 @ 0x140abac91 */

void SwingRegion_140abac91(undefined8 param_1,uint param_2,float param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong *unaff_RDI;
  
  uVar2 = (ulonglong)param_2;
  do {
    lVar1 = *unaff_RDI;
    unaff_RDI = unaff_RDI + 1;
    if (((*(byte *)(lVar1 + 0x1d) & 2) == 0) && ((*(byte *)(lVar1 + 0x1d) & 1) != 0)) {
      FUN_140ac30e0(lVar1,param_3 * *(float *)(lVar1 + 0x10));
    }
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}


/* SwingRegion_140abaced @ 0x140abaced */

void SwingRegion_140abaced(void)

{
  return;
}


/* SwingRegion_140abacf0 @ 0x140abacf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140abacf0(longlong *param_1,uint param_2,float param_3)

{
  longlong lVar1;
  float fVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  float fVar7;
  longlong alStack_498 [130];
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  
  uVar3 = _DAT_14382ee88;
  fVar2 = _DAT_14382e120;
  if (0 < (int)param_2) {
    uVar6 = (ulonglong)param_2;
    do {
      lVar1 = *param_1;
      param_1 = param_1 + 1;
      uVar4 = 0;
      do {
        uVar4 = uVar4 + 0x40;
      } while (uVar4 < 0x100);
      if (((*(byte *)(lVar1 + 0x1d) & 2) == 0) && ((*(byte *)(lVar1 + 0x1d) & 1) != 0)) {
        fVar7 = param_3 * *(float *)(lVar1 + 0x10);
        FUN_140ac3a20(lVar1,fVar7);
        FUN_140b91bb0(lVar1 + 0x120,fVar7);
        fVar7 = (float)func_0x0001420e0a50(lVar1);
        if ((fVar2 < fVar7) || (fVar7 = (float)FUN_1420dc660(lVar1), fVar7 == 0.0)) {
          alStack_498[0] = *(longlong *)(lVar1 + 0xe8);
          FUN_141c649a0(auStack_88,0,0x20);
          uStack_68 = 0;
          FUN_141fe0f20(alStack_498,*(undefined8 *)(lVar1 + 8),0);
          FUN_1420e09d0(lVar1,alStack_498,uVar3);
          pbVar5 = (byte *)FUN_141bcf3e0(alStack_498[0] + 0x10,0x44d96bd9);
          if (pbVar5 == (byte *)0x0) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = (ulonglong)*pbVar5;
          }
          FUN_141f9e0e0(alStack_498,uVar4,lVar1 + 0x4b8,0xc);
          pbVar5 = (byte *)FUN_141bcf3e0(alStack_498[0] + 0x10,0x5becae87);
          if (pbVar5 == (byte *)0x0) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = (ulonglong)*pbVar5;
          }
          FUN_141f9e0e0(alStack_498,uVar4,lVar1 + 0x54c,4);
          FUN_1420e0a80(lVar1);
        }
        *(undefined1 *)(lVar1 + 0x5f2) = 0;
      }
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return;
}


/* SwingRegion_140abad0b @ 0x140abad0b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abad0b(undefined8 param_1,ulonglong param_2,float param_3)

{
  longlong lVar1;
  float fVar2;
  undefined4 uVar3;
  longlong in_RAX;
  ulonglong uVar4;
  byte *pbVar5;
  undefined8 unaff_RBX;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  longlong *unaff_RDI;
  undefined4 unaff_XMM6_Da;
  float fVar6;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  longlong lStackX_20;
  
  *(undefined8 *)(in_RAX + 8) = unaff_RBX;
  *(undefined8 *)(in_RAX + 0x10) = unaff_RBP;
  *(undefined8 *)(in_RAX + 0x18) = unaff_RSI;
  *(undefined4 *)(in_RAX + -0x28) = unaff_XMM7_Da;
  *(undefined4 *)(in_RAX + -0x24) = unaff_XMM7_Db;
  *(undefined4 *)(in_RAX + -0x20) = unaff_XMM7_Dc;
  *(undefined4 *)(in_RAX + -0x1c) = unaff_XMM7_Dd;
  *(undefined4 *)(in_RAX + -0x48) = unaff_XMM9_Da;
  *(undefined4 *)(in_RAX + -0x44) = unaff_XMM9_Db;
  *(undefined4 *)(in_RAX + -0x40) = unaff_XMM9_Dc;
  *(undefined4 *)(in_RAX + -0x3c) = unaff_XMM9_Dd;
  fVar2 = _DAT_14382e120;
  *(undefined4 *)(in_RAX + -0x58) = unaff_XMM10_Da;
  *(undefined4 *)(in_RAX + -0x54) = unaff_XMM10_Db;
  *(undefined4 *)(in_RAX + -0x50) = unaff_XMM10_Dc;
  *(undefined4 *)(in_RAX + -0x4c) = unaff_XMM10_Dd;
  uVar3 = _DAT_14382ee88;
  *(undefined4 *)(in_RAX + -0x18) = unaff_XMM6_Da;
  *(undefined4 *)(in_RAX + -0x14) = unaff_XMM6_Db;
  *(undefined4 *)(in_RAX + -0x10) = unaff_XMM6_Dc;
  *(undefined4 *)(in_RAX + -0xc) = unaff_XMM6_Dd;
  param_2 = param_2 & 0xffffffff;
  do {
    lVar1 = *unaff_RDI;
    unaff_RDI = unaff_RDI + 1;
    uVar4 = 0;
    do {
      uVar4 = uVar4 + 0x40;
    } while (uVar4 < 0x100);
    if (((*(byte *)(lVar1 + 0x1d) & 2) == 0) && ((*(byte *)(lVar1 + 0x1d) & 1) != 0)) {
      fVar6 = param_3 * *(float *)(lVar1 + 0x10);
      FUN_140ac3a20(lVar1,fVar6);
      FUN_140b91bb0(lVar1 + 0x120,fVar6);
      fVar6 = (float)func_0x0001420e0a50(lVar1);
      if (fVar2 < fVar6) {
LAB_140abadc6:
        lStackX_20 = *(longlong *)(lVar1 + 0xe8);
        FUN_141c649a0(&stack0x00000430,0,0x20);
        FUN_141fe0f20(&lStackX_20,*(undefined8 *)(lVar1 + 8),0);
        FUN_1420e09d0(lVar1,&lStackX_20,uVar3);
        pbVar5 = (byte *)FUN_141bcf3e0(lStackX_20 + 0x10,0x44d96bd9);
        if (pbVar5 == (byte *)0x0) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (ulonglong)*pbVar5;
        }
        FUN_141f9e0e0(&lStackX_20,uVar4,lVar1 + 0x4b8,0xc);
        pbVar5 = (byte *)FUN_141bcf3e0(lStackX_20 + 0x10,0x5becae87);
        if (pbVar5 == (byte *)0x0) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (ulonglong)*pbVar5;
        }
        FUN_141f9e0e0(&lStackX_20,uVar4,lVar1 + 0x54c,4);
        FUN_1420e0a80(lVar1);
      }
      else {
        fVar6 = (float)FUN_1420dc660(lVar1);
        if (fVar6 == 0.0) goto LAB_140abadc6;
      }
      *(undefined1 *)(lVar1 + 0x5f2) = 0;
    }
    param_2 = param_2 - 1;
    if (param_2 == 0) {
      return;
    }
  } while( true );
}


/* SwingRegion_140abaeea @ 0x140abaeea */

void SwingRegion_140abaeea(void)

{
  return;
}


/* SwingRegion_140abaef0 @ 0x140abaef0 */

void FUN_140abaef0(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined1 auStackX_20 [8];
  
  puVar1 = (undefined4 *)func_0x000141676900(param_1,auStackX_20);
  FUN_1416d5e80(0x147475690,0xdad04fc5,*puVar1,0,0,0,0,0,1,param_2,param_3,0,0);
  return;
}


/* SwingRegion_140abb030 @ 0x140abb030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140abb030(longlong param_1,float *param_2,float param_3)

{
  uint *puVar1;
  float *pfVar2;
  bool bVar3;
  undefined8 *puVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined4 uVar13;
  ulonglong uStack_d8;
  float fStack_d0;
  float afStack_c8 [4];
  float afStack_b8 [2];
  float fStack_b0;
  float afStack_a8 [2];
  float fStack_a0;
  
  fVar6 = (float)func_0x000140b8fda0(param_1 + 0x120,0);
  fVar7 = (float)func_0x000140b8fda0(param_1 + 0x120,0xffffffff);
  fVar8 = (float)func_0x000140b8fda0(param_1 + 0x120,0xfffffffe);
  fVar9 = (float)func_0x000140b8fda0(param_1 + 0x120,1);
  if (fVar8 <= fVar7) {
    fVar8 = fVar7;
  }
  fVar7 = (float)func_0x000140b8fda0(param_1 + 0x120,2);
  if (fVar7 <= fVar9) {
    fVar7 = fVar9;
  }
  fVar10 = (float)FUN_1420dc660(param_1);
  fVar9 = _DAT_14382dce0;
  puVar1 = (uint *)(param_1 + 0x4b8);
  fVar10 = (fVar10 - _DAT_14382e124) * _DAT_1438ad55c;
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar10) {
    fVar10 = _DAT_14382dce0;
  }
  fVar11 = (float)FUN_1402c2450(puVar1);
  fVar12 = _DAT_14382f2cc;
  fVar11 = (fVar11 - _DAT_143834a14) * _DAT_14382e124;
  if (fVar11 <= 0.0) {
    fVar11 = 0.0;
  }
  if (fVar9 <= fVar11) {
    fVar11 = fVar9;
  }
  fVar10 = (fVar11 - fVar9) * fVar10 + fVar9;
  if (fVar6 <= _DAT_14382f2cc) {
    fVar11 = fVar6 + _DAT_14383d264;
    bVar3 = fVar11 < fVar8;
    if (bVar3) {
LAB_140abb1be:
      if (fVar7 > fVar11) {
        fStack_d0 = *(float *)(param_1 + 0x44c) - param_2[2];
        uStack_d8 = (ulonglong)(uint)(*(float *)(param_1 + 0x444) - *param_2);
        FUN_1402d0740(afStack_a8,&uStack_d8);
        fStack_d0 = *(float *)(param_1 + 0x4c0);
        uStack_d8 = (ulonglong)*puVar1;
        FUN_1402d0740(afStack_b8,&uStack_d8);
        bVar3 = 0.0 < afStack_a8[0] * fStack_b0 - afStack_b8[0] * fStack_a0;
      }
    }
    else {
      if (fVar7 <= fVar11) goto LAB_140abb174;
      if (fVar11 < fVar8) goto LAB_140abb1be;
    }
    fVar8 = (float)FUN_1402c2450(puVar1);
    afStack_c8[0] = *(float *)(param_1 + 0x4c0);
    afStack_c8[2] = (float)(*puVar1 ^ _DAT_14382e890);
    fVar6 = (fVar6 - _DAT_143830120) * _DAT_1438564c4;
    fVar7 = (fVar8 - fVar12) * _DAT_14382e120;
    fVar8 = (float)((uint)afStack_c8[2] & _DAT_14382e160);
    if (fVar6 <= 0.0) {
      fVar6 = 0.0;
    }
    if (fVar8 <= 0.0) {
      fVar8 = 0.0;
    }
    if (fVar7 <= 0.0) {
      fVar7 = 0.0;
    }
    if (fVar9 <= fVar6) {
      fVar6 = fVar9;
    }
    if (fVar9 <= fVar7) {
      fVar7 = fVar9;
    }
    fVar12 = fVar7 * _DAT_1438b3184 + _DAT_143837a24;
    if (fVar8 <= (float)((uint)afStack_c8[0] & _DAT_14382e160)) {
      fVar8 = (float)((uint)afStack_c8[0] & _DAT_14382e160);
    }
    fVar12 = (fVar9 - fVar6) * ((fVar7 * _DAT_14382f760 + fVar9) - fVar12) + fVar12;
    if (0.0 < fVar8) {
      afStack_c8[2] = afStack_c8[2] * (fVar9 / fVar8);
      afStack_c8[0] = (fVar9 / fVar8) * afStack_c8[0];
      fVar9 = fVar9 / SQRT(afStack_c8[2] * afStack_c8[2] + afStack_c8[0] * afStack_c8[0]);
      afStack_c8[2] = fVar9 * afStack_c8[2];
      afStack_c8[0] = fVar9 * afStack_c8[0];
    }
    if (!bVar3) {
      fVar12 = (float)((uint)fVar12 ^ _DAT_14382e890);
    }
    afStack_c8[0] = afStack_c8[0] * fVar12;
    pfVar5 = afStack_c8;
    afStack_c8[1] = 0.0;
    afStack_c8[2] = afStack_c8[2] * fVar12;
    uVar13 = _DAT_1438388d0;
  }
  else {
LAB_140abb174:
    pfVar5 = (float *)&uStack_d8;
    uStack_d8 = 0;
    fStack_d0 = 0.0;
    uVar13 = _DAT_14383ffa0;
  }
  pfVar2 = (float *)(param_1 + 0x470);
  puVar4 = (undefined8 *)FUN_141c47af0(afStack_a8,pfVar2,pfVar5,uVar13,param_3);
  *(undefined8 *)pfVar2 = *puVar4;
  *(undefined4 *)(param_1 + 0x478) = *(undefined4 *)(puVar4 + 1);
  fVar8 = *pfVar2;
  fVar6 = *(float *)(param_1 + 0x478);
  param_2[1] = *(float *)(param_1 + 0x474) * param_3 * fVar10 + param_2[1];
  param_2[2] = fVar6 * param_3 * fVar10 + param_2[2];
  *param_2 = param_3 * fVar8 * fVar10 + *param_2;
  return;
}


/* SwingRegion_140abb420 @ 0x140abb420 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_140abb420(longlong param_1,undefined8 *param_2,undefined8 *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  longlong lVar5;
  float *pfVar6;
  undefined4 *puVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float afStackX_8 [2];
  float fStackX_10;
  float fStackX_18;
  float fStackX_20;
  undefined1 auStack_c8 [8];
  float fStack_c0;
  
  lVar5 = *(longlong *)(param_1 + 8);
  uVar4 = *(undefined4 *)(param_3 + 1);
  *param_2 = *param_3;
  *(undefined4 *)(param_2 + 1) = uVar4;
  fStackX_20 = param_4;
  if (*(short *)(lVar5 + 0x88) == 0) {
    lVar5 = FUN_14167ab40(lVar5 + 0x58,0x147c40bf0);
  }
  else {
    lVar5 = func_0x0001416799a0(lVar5 + 0x80);
  }
  if (*(char *)(lVar5 + 0x194) != '\0') {
    fVar1 = *(float *)(lVar5 + 0x160);
    fVar2 = *(float *)(lVar5 + 0x15c);
    fVar3 = *(float *)(lVar5 + 0x164);
    fVar10 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
    if ((float)((uint)fVar10 & _DAT_14382e160) <= _DAT_14382e110) {
      fVar13 = *(float *)(param_1 + 0x4bc);
      fVar10 = 0.0;
      fVar14 = *(float *)(param_1 + 0x4c0);
    }
    else {
      fVar13 = *(float *)(param_1 + 0x4bc);
      fVar14 = *(float *)(param_1 + 0x4c0);
      fVar10 = (fVar2 * *(float *)(param_1 + 0x4b8) + fVar1 * fVar13 + fVar3 * fVar14) / fVar10;
    }
    afStackX_8[0] = fVar1 * fVar10;
    fStackX_10 = fVar3 * fVar10;
    fVar10 = fVar2 * fVar10;
    fVar13 = fVar13 - afStackX_8[0];
    fVar16 = *(float *)(param_1 + 0x4b8) - fVar10;
    fStackX_18 = (float)((uint)fStackX_10 & _DAT_14382e160);
    if ((float)((uint)fStackX_10 & _DAT_14382e160) <= (float)((uint)afStackX_8[0] & _DAT_14382e160))
    {
      fStackX_18 = (float)((uint)afStackX_8[0] & _DAT_14382e160);
    }
    fVar14 = fVar14 - fStackX_10;
    if (fStackX_18 <= (float)((uint)fVar10 & _DAT_14382e160)) {
      fStackX_18 = (float)((uint)fVar10 & _DAT_14382e160);
    }
    fVar8 = _DAT_14382dce0 / fStackX_18;
    fVar15 = 0.0;
    if (0.0 < fStackX_18) {
      fVar15 = SQRT(afStackX_8[0] * fVar8 * afStackX_8[0] * fVar8 + fVar10 * fVar8 * fVar10 * fVar8
                    + fStackX_10 * fVar8 * fStackX_10 * fVar8) * fStackX_18;
    }
    fVar11 = 0.0;
    fVar12 = fVar15 - fVar15 * _DAT_143830120 * fStackX_20;
    fVar8 = (float)((uint)fVar14 & _DAT_14382e160);
    if ((float)((uint)fVar14 & _DAT_14382e160) <= (float)((uint)fVar13 & _DAT_14382e160)) {
      fVar8 = (float)((uint)fVar13 & _DAT_14382e160);
    }
    if (fVar12 <= 0.0) {
      fVar12 = 0.0;
    }
    if (fVar8 <= (float)((uint)fVar16 & _DAT_14382e160)) {
      fVar8 = (float)((uint)fVar16 & _DAT_14382e160);
    }
    fVar9 = _DAT_14382dce0 / fVar8;
    if (0.0 < fVar8) {
      fVar11 = SQRT(fVar9 * fVar16 * fVar9 * fVar16 + fVar9 * fVar13 * fVar9 * fVar13 +
                    fVar9 * fVar14 * fVar9 * fVar14) * fVar8;
    }
    fVar11 = fVar11 - fVar15 * _DAT_14384d780 * fStackX_20;
    if (fVar11 <= 0.0) {
      fVar11 = 0.0;
    }
    fVar8 = fVar10 * fVar10 + afStackX_8[0] * afStackX_8[0] + fStackX_10 * fStackX_10;
    fStack_c0 = fVar12 / SQRT(fVar8);
    if (_DAT_14382e110 <= fVar8) {
      fVar8 = fStack_c0 * afStackX_8[0];
      fVar12 = fVar10 * fStack_c0;
      fStack_c0 = fStack_c0 * fStackX_10;
    }
    else {
      fStack_c0 = 0.0;
      fVar8 = 0.0;
    }
    fVar9 = fVar13 * fVar13 + fVar16 * fVar16 + fVar14 * fVar14;
    fVar10 = fVar11 / SQRT(fVar9);
    if (_DAT_14382e110 <= fVar9) {
      fVar11 = fVar10 * fVar16;
      fVar13 = fVar10 * fVar13;
      fVar10 = fVar10 * fVar14;
    }
    else {
      fVar10 = 0.0;
      fVar13 = 0.0;
    }
    fStack_c0 = fStack_c0 + fVar10;
    *param_2 = CONCAT44(fVar8 + fVar13,fVar12 + fVar11);
    *(float *)(param_2 + 1) = fStack_c0;
    pfVar6 = (float *)FUN_1402d0740(auStack_c8);
    if ((fVar1 * pfVar6[1] + fVar2 * *pfVar6 + fVar3 * pfVar6[2] < _DAT_1438a60b8) &&
       (*(char *)(param_1 + 0x5f4) == '\0')) {
      puVar7 = (undefined4 *)func_0x000141676900(param_1,afStackX_8);
      lVar5 = FUN_1416d5e80(0x147475690,0xb63ed3a3,*puVar7,0,0,0,0,0,1,0,0,0,0);
      *(float *)(lVar5 + 0x138) = fVar15;
      *(ulonglong *)(lVar5 + 8) = *(ulonglong *)(lVar5 + 8) | 0x100;
      *(ulonglong *)(lVar5 + 0x18) = *(ulonglong *)(lVar5 + 0x18) | 0x100;
      *(undefined1 *)(param_1 + 0x5f4) = 1;
    }
    return param_2;
  }
  return param_2;
}


/* SwingRegion_140abb47b @ 0x140abb47b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abb47b(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longlong in_RAX;
  float *pfVar4;
  undefined4 *puVar5;
  longlong lVar6;
  undefined8 *unaff_RBX;
  longlong unaff_RDI;
  float fVar7;
  undefined4 extraout_XMM0_Da;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStack0000000000000078;
  float fStack0000000000000140;
  float fStack0000000000000148;
  float fStack0000000000000150;
  float in_stack_00000158;
  
  fVar1 = *(float *)(in_RAX + 0x160);
  fVar2 = *(float *)(in_RAX + 0x15c);
  fVar3 = *(float *)(in_RAX + 0x164);
  fVar9 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
  if ((float)((uint)fVar9 & _DAT_14382e160) <= _DAT_14382e110) {
    fVar12 = *(float *)(unaff_RDI + 0x4bc);
    fVar9 = 0.0;
    fVar13 = *(float *)(unaff_RDI + 0x4c0);
  }
  else {
    fVar12 = *(float *)(unaff_RDI + 0x4bc);
    fVar13 = *(float *)(unaff_RDI + 0x4c0);
    fVar9 = (fVar2 * *(float *)(unaff_RDI + 0x4b8) + fVar1 * fVar12 + fVar3 * fVar13) / fVar9;
  }
  fStack0000000000000140 = fVar1 * fVar9;
  fStack0000000000000148 = fVar3 * fVar9;
  fVar9 = fVar2 * fVar9;
  fVar12 = fVar12 - fStack0000000000000140;
  fVar15 = *(float *)(unaff_RDI + 0x4b8) - fVar9;
  fStack0000000000000150 = (float)((uint)fStack0000000000000148 & _DAT_14382e160);
  if ((float)((uint)fStack0000000000000148 & _DAT_14382e160) <=
      (float)((uint)fStack0000000000000140 & _DAT_14382e160)) {
    fStack0000000000000150 = (float)((uint)fStack0000000000000140 & _DAT_14382e160);
  }
  fVar13 = fVar13 - fStack0000000000000148;
  if (fStack0000000000000150 <= (float)((uint)fVar9 & _DAT_14382e160)) {
    fStack0000000000000150 = (float)((uint)fVar9 & _DAT_14382e160);
  }
  fVar7 = _DAT_14382dce0 / fStack0000000000000150;
  fVar14 = 0.0;
  if (0.0 < fStack0000000000000150) {
    fVar14 = SQRT(fStack0000000000000140 * fVar7 * fStack0000000000000140 * fVar7 +
                  fVar9 * fVar7 * fVar9 * fVar7 +
                  fStack0000000000000148 * fVar7 * fStack0000000000000148 * fVar7) *
             fStack0000000000000150;
  }
  fVar10 = 0.0;
  fVar11 = fVar14 - fVar14 * _DAT_143830120 * in_stack_00000158;
  fVar7 = (float)((uint)fVar13 & _DAT_14382e160);
  if ((float)((uint)fVar13 & _DAT_14382e160) <= (float)((uint)fVar12 & _DAT_14382e160)) {
    fVar7 = (float)((uint)fVar12 & _DAT_14382e160);
  }
  if (fVar11 <= 0.0) {
    fVar11 = 0.0;
  }
  if (fVar7 <= (float)((uint)fVar15 & _DAT_14382e160)) {
    fVar7 = (float)((uint)fVar15 & _DAT_14382e160);
  }
  fVar8 = _DAT_14382dce0 / fVar7;
  if (0.0 < fVar7) {
    fVar10 = SQRT(fVar8 * fVar15 * fVar8 * fVar15 + fVar8 * fVar12 * fVar8 * fVar12 +
                  fVar8 * fVar13 * fVar8 * fVar13) * fVar7;
  }
  fVar10 = fVar10 - fVar14 * _DAT_14384d780 * in_stack_00000158;
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  fVar7 = fVar9 * fVar9 + fStack0000000000000140 * fStack0000000000000140 +
          fStack0000000000000148 * fStack0000000000000148;
  fStack0000000000000078 = fVar11 / SQRT(fVar7);
  if (_DAT_14382e110 <= fVar7) {
    fVar7 = fStack0000000000000078 * fStack0000000000000140;
    fVar11 = fVar9 * fStack0000000000000078;
    fStack0000000000000078 = fStack0000000000000078 * fStack0000000000000148;
  }
  else {
    fStack0000000000000078 = 0.0;
    fVar7 = 0.0;
  }
  fVar8 = fVar12 * fVar12 + fVar15 * fVar15 + fVar13 * fVar13;
  fVar9 = fVar10 / SQRT(fVar8);
  if (_DAT_14382e110 <= fVar8) {
    fVar10 = fVar9 * fVar15;
    fVar12 = fVar9 * fVar12;
    fVar9 = fVar9 * fVar13;
  }
  else {
    fVar9 = 0.0;
    fVar12 = 0.0;
  }
  fStack0000000000000078 = fStack0000000000000078 + fVar9;
  *unaff_RBX = CONCAT44(fVar7 + fVar12,fVar11 + fVar10);
  *(float *)(unaff_RBX + 1) = fStack0000000000000078;
  pfVar4 = (float *)FUN_1402d0740(&stack0x00000070);
  if ((fVar1 * pfVar4[1] + fVar2 * *pfVar4 + fVar3 * pfVar4[2] < _DAT_1438a60b8) &&
     (*(char *)(unaff_RDI + 0x5f4) == '\0')) {
    puVar5 = (undefined4 *)func_0x000141676900(extraout_XMM0_Da,&stack0x00000140);
    lVar6 = FUN_1416d5e80(0x147475690,0xb63ed3a3,*puVar5,0,0);
    *(float *)(lVar6 + 0x138) = fVar14;
    *(ulonglong *)(lVar6 + 8) = *(ulonglong *)(lVar6 + 8) | 0x100;
    *(ulonglong *)(lVar6 + 0x18) = *(ulonglong *)(lVar6 + 0x18) | 0x100;
    *(undefined1 *)(unaff_RDI + 0x5f4) = 1;
  }
  return;
}


/* SwingRegion_140abb48a @ 0x140abb48a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abb48a(undefined8 param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longlong in_RAX;
  float *pfVar4;
  undefined4 *puVar5;
  longlong lVar6;
  undefined8 *unaff_RBX;
  longlong unaff_RDI;
  float fVar7;
  undefined4 extraout_XMM0_Da;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStack0000000000000078;
  float fStack0000000000000140;
  float fStack0000000000000148;
  float fStack0000000000000150;
  float in_stack_00000158;
  
  fVar1 = *(float *)(in_RAX + 0x160);
  fVar2 = *(float *)(in_RAX + 0x15c);
  fVar3 = *(float *)(in_RAX + 0x164);
  fVar9 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
  if ((float)((uint)fVar9 & _DAT_14382e160) <= _DAT_14382e110) {
    fVar12 = *(float *)(unaff_RDI + 0x4bc);
    fVar9 = 0.0;
    fVar13 = *(float *)(unaff_RDI + 0x4c0);
  }
  else {
    fVar12 = param_2[1];
    fVar13 = param_2[2];
    fVar9 = (fVar2 * *param_2 + fVar1 * fVar12 + fVar3 * fVar13) / fVar9;
  }
  fStack0000000000000140 = fVar1 * fVar9;
  fStack0000000000000148 = fVar3 * fVar9;
  fVar9 = fVar2 * fVar9;
  fVar12 = fVar12 - fStack0000000000000140;
  fVar15 = *param_2 - fVar9;
  fStack0000000000000150 = (float)((uint)fStack0000000000000148 & _DAT_14382e160);
  if ((float)((uint)fStack0000000000000148 & _DAT_14382e160) <=
      (float)((uint)fStack0000000000000140 & _DAT_14382e160)) {
    fStack0000000000000150 = (float)((uint)fStack0000000000000140 & _DAT_14382e160);
  }
  fVar13 = fVar13 - fStack0000000000000148;
  if (fStack0000000000000150 <= (float)((uint)fVar9 & _DAT_14382e160)) {
    fStack0000000000000150 = (float)((uint)fVar9 & _DAT_14382e160);
  }
  fVar7 = _DAT_14382dce0 / fStack0000000000000150;
  fVar14 = 0.0;
  if (0.0 < fStack0000000000000150) {
    fVar14 = SQRT(fStack0000000000000140 * fVar7 * fStack0000000000000140 * fVar7 +
                  fVar9 * fVar7 * fVar9 * fVar7 +
                  fStack0000000000000148 * fVar7 * fStack0000000000000148 * fVar7) *
             fStack0000000000000150;
  }
  fVar10 = 0.0;
  fVar11 = fVar14 - fVar14 * _DAT_143830120 * in_stack_00000158;
  fVar7 = (float)((uint)fVar13 & _DAT_14382e160);
  if ((float)((uint)fVar13 & _DAT_14382e160) <= (float)((uint)fVar12 & _DAT_14382e160)) {
    fVar7 = (float)((uint)fVar12 & _DAT_14382e160);
  }
  if (fVar11 <= 0.0) {
    fVar11 = 0.0;
  }
  if (fVar7 <= (float)((uint)fVar15 & _DAT_14382e160)) {
    fVar7 = (float)((uint)fVar15 & _DAT_14382e160);
  }
  fVar8 = _DAT_14382dce0 / fVar7;
  if (0.0 < fVar7) {
    fVar10 = SQRT(fVar8 * fVar15 * fVar8 * fVar15 + fVar8 * fVar12 * fVar8 * fVar12 +
                  fVar8 * fVar13 * fVar8 * fVar13) * fVar7;
  }
  fVar10 = fVar10 - fVar14 * _DAT_14384d780 * in_stack_00000158;
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  fVar7 = fVar9 * fVar9 + fStack0000000000000140 * fStack0000000000000140 +
          fStack0000000000000148 * fStack0000000000000148;
  fStack0000000000000078 = fVar11 / SQRT(fVar7);
  if (_DAT_14382e110 <= fVar7) {
    fVar7 = fStack0000000000000078 * fStack0000000000000140;
    fVar11 = fVar9 * fStack0000000000000078;
    fStack0000000000000078 = fStack0000000000000078 * fStack0000000000000148;
  }
  else {
    fStack0000000000000078 = 0.0;
    fVar7 = 0.0;
  }
  fVar8 = fVar12 * fVar12 + fVar15 * fVar15 + fVar13 * fVar13;
  fVar9 = fVar10 / SQRT(fVar8);
  if (_DAT_14382e110 <= fVar8) {
    fVar10 = fVar9 * fVar15;
    fVar12 = fVar9 * fVar12;
    fVar9 = fVar9 * fVar13;
  }
  else {
    fVar9 = 0.0;
    fVar12 = 0.0;
  }
  fStack0000000000000078 = fStack0000000000000078 + fVar9;
  *unaff_RBX = CONCAT44(fVar7 + fVar12,fVar11 + fVar10);
  *(float *)(unaff_RBX + 1) = fStack0000000000000078;
  pfVar4 = (float *)FUN_1402d0740(&stack0x00000070);
  if ((fVar1 * pfVar4[1] + fVar2 * *pfVar4 + fVar3 * pfVar4[2] < _DAT_1438a60b8) &&
     (*(char *)(unaff_RDI + 0x5f4) == '\0')) {
    puVar5 = (undefined4 *)func_0x000141676900(extraout_XMM0_Da,&stack0x00000140);
    lVar6 = FUN_1416d5e80(0x147475690,0xb63ed3a3,*puVar5,0,0);
    *(float *)(lVar6 + 0x138) = fVar14;
    *(ulonglong *)(lVar6 + 8) = *(ulonglong *)(lVar6 + 8) | 0x100;
    *(ulonglong *)(lVar6 + 0x18) = *(ulonglong *)(lVar6 + 0x18) | 0x100;
    *(undefined1 *)(unaff_RDI + 0x5f4) = 1;
  }
  return;
}


/* SwingRegion_140abb514 @ 0x140abb514 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abb514(undefined8 param_1,float *param_2,undefined8 param_3,float param_4)

{
  float *pfVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined8 *unaff_RBX;
  longlong unaff_RDI;
  float fVar4;
  undefined4 extraout_XMM0_Da;
  float in_XMM1_Da;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float unaff_XMM6_Da;
  float unaff_XMM7_Da;
  uint unaff_XMM8_Da;
  float fVar9;
  float fVar10;
  float unaff_XMM11_Da;
  float unaff_XMM12_Da;
  float fVar11;
  float fVar12;
  float fStack0000000000000078;
  float fStack0000000000000140;
  float fStack0000000000000148;
  float fStack0000000000000150;
  float in_stack_00000158;
  
  if ((float)((uint)(param_4 + in_XMM1_Da) & unaff_XMM8_Da) <= _DAT_14382e110) {
    fVar9 = *(float *)(unaff_RDI + 0x4bc);
    fVar5 = 0.0;
    fVar10 = *(float *)(unaff_RDI + 0x4c0);
  }
  else {
    fVar9 = param_2[1];
    fVar10 = param_2[2];
    fVar5 = (unaff_XMM11_Da * *param_2 + unaff_XMM7_Da * fVar9 + unaff_XMM12_Da * fVar10) /
            (param_4 + in_XMM1_Da);
  }
  fStack0000000000000140 = unaff_XMM7_Da * fVar5;
  fStack0000000000000148 = unaff_XMM12_Da * fVar5;
  fVar5 = unaff_XMM11_Da * fVar5;
  fVar9 = fVar9 - fStack0000000000000140;
  fVar12 = *param_2 - fVar5;
  fStack0000000000000150 = (float)((uint)fStack0000000000000148 & unaff_XMM8_Da);
  if ((float)((uint)fStack0000000000000148 & unaff_XMM8_Da) <=
      (float)((uint)fStack0000000000000140 & unaff_XMM8_Da)) {
    fStack0000000000000150 = (float)((uint)fStack0000000000000140 & unaff_XMM8_Da);
  }
  fVar10 = fVar10 - fStack0000000000000148;
  if (fStack0000000000000150 <= (float)((uint)fVar5 & unaff_XMM8_Da)) {
    fStack0000000000000150 = (float)((uint)fVar5 & unaff_XMM8_Da);
  }
  fVar4 = _DAT_14382dce0 / fStack0000000000000150;
  fVar11 = 0.0;
  if (unaff_XMM6_Da < fStack0000000000000150) {
    fVar11 = SQRT(fStack0000000000000140 * fVar4 * fStack0000000000000140 * fVar4 +
                  fVar5 * fVar4 * fVar5 * fVar4 +
                  fStack0000000000000148 * fVar4 * fStack0000000000000148 * fVar4) *
             fStack0000000000000150;
  }
  fVar4 = 0.0;
  fVar8 = fVar11 - fVar11 * _DAT_143830120 * in_stack_00000158;
  fVar7 = (float)((uint)fVar10 & unaff_XMM8_Da);
  if ((float)((uint)fVar10 & unaff_XMM8_Da) <= (float)((uint)fVar9 & unaff_XMM8_Da)) {
    fVar7 = (float)((uint)fVar9 & unaff_XMM8_Da);
  }
  if (fVar8 <= unaff_XMM6_Da) {
    fVar8 = unaff_XMM6_Da;
  }
  if (fVar7 <= (float)((uint)fVar12 & unaff_XMM8_Da)) {
    fVar7 = (float)((uint)fVar12 & unaff_XMM8_Da);
  }
  fVar6 = _DAT_14382dce0 / fVar7;
  if (unaff_XMM6_Da < fVar7) {
    fVar4 = SQRT(fVar6 * fVar12 * fVar6 * fVar12 + fVar6 * fVar9 * fVar6 * fVar9 +
                 fVar6 * fVar10 * fVar6 * fVar10) * fVar7;
  }
  fVar4 = fVar4 - fVar11 * _DAT_14384d780 * in_stack_00000158;
  if (fVar4 <= unaff_XMM6_Da) {
    fVar4 = unaff_XMM6_Da;
  }
  fVar7 = fVar5 * fVar5 + fStack0000000000000140 * fStack0000000000000140 +
          fStack0000000000000148 * fStack0000000000000148;
  fStack0000000000000078 = fVar8 / SQRT(fVar7);
  if (_DAT_14382e110 <= fVar7) {
    fVar7 = fStack0000000000000078 * fStack0000000000000140;
    fVar8 = fVar5 * fStack0000000000000078;
    fStack0000000000000078 = fStack0000000000000078 * fStack0000000000000148;
  }
  else {
    fStack0000000000000078 = 0.0;
    fVar7 = 0.0;
  }
  fVar6 = fVar9 * fVar9 + fVar12 * fVar12 + fVar10 * fVar10;
  fVar5 = fVar4 / SQRT(fVar6);
  if (_DAT_14382e110 <= fVar6) {
    fVar4 = fVar5 * fVar12;
    fVar9 = fVar5 * fVar9;
    fVar5 = fVar5 * fVar10;
  }
  else {
    fVar5 = 0.0;
    fVar9 = 0.0;
  }
  fStack0000000000000078 = fStack0000000000000078 + fVar5;
  *unaff_RBX = CONCAT44(fVar7 + fVar9,fVar8 + fVar4);
  *(float *)(unaff_RBX + 1) = fStack0000000000000078;
  pfVar1 = (float *)FUN_1402d0740(&stack0x00000070);
  if ((unaff_XMM7_Da * pfVar1[1] + unaff_XMM11_Da * *pfVar1 + unaff_XMM12_Da * pfVar1[2] <
       _DAT_1438a60b8) && (*(char *)(unaff_RDI + 0x5f4) == '\0')) {
    puVar2 = (undefined4 *)func_0x000141676900(extraout_XMM0_Da,&stack0x00000140);
    lVar3 = FUN_1416d5e80(0x147475690,0xb63ed3a3,*puVar2,0,0);
    *(float *)(lVar3 + 0x138) = fVar11;
    *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x100;
    *(ulonglong *)(lVar3 + 0x18) = *(ulonglong *)(lVar3 + 0x18) | 0x100;
    *(undefined1 *)(unaff_RDI + 0x5f4) = 1;
  }
  return;
}


/* SwingRegion_140abb783 @ 0x140abb783 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abb783(void)

{
  float *pfVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined8 *unaff_RBX;
  longlong unaff_RDI;
  undefined4 extraout_XMM0_Da;
  float in_XMM3_Da;
  float in_XMM4_Da;
  float in_XMM5_Da;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM11_Da;
  float unaff_XMM12_Da;
  undefined4 unaff_XMM13_Da;
  float fStack0000000000000078;
  
  fStack0000000000000078 = in_XMM4_Da + 0.0;
  *unaff_RBX = CONCAT44(unaff_XMM8_Da + 0.0,in_XMM5_Da + in_XMM3_Da);
  *(float *)(unaff_RBX + 1) = fStack0000000000000078;
  pfVar1 = (float *)FUN_1402d0740(&stack0x00000070);
  if ((unaff_XMM7_Da * pfVar1[1] + unaff_XMM11_Da * *pfVar1 + unaff_XMM12_Da * pfVar1[2] <
       _DAT_1438a60b8) && (*(char *)(unaff_RDI + 0x5f4) == '\0')) {
    puVar2 = (undefined4 *)func_0x000141676900(extraout_XMM0_Da,&stack0x00000140);
    lVar3 = FUN_1416d5e80(0x147475690,0xb63ed3a3,*puVar2,0,0);
    *(undefined4 *)(lVar3 + 0x138) = unaff_XMM13_Da;
    *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x100;
    *(ulonglong *)(lVar3 + 0x18) = *(ulonglong *)(lVar3 + 0x18) | 0x100;
    *(undefined1 *)(unaff_RDI + 0x5f4) = 1;
  }
  return;
}


/* SwingRegion_140abb830 @ 0x140abb830 */

void SwingRegion_140abb830(void)

{
  undefined4 *puVar1;
  longlong lVar2;
  longlong unaff_RDI;
  undefined4 unaff_XMM13_Da;
  
  if (*(char *)(unaff_RDI + 0x5f4) == '\0') {
    puVar1 = (undefined4 *)func_0x000141676900();
    lVar2 = FUN_1416d5e80(0x147475690,0xb63ed3a3,*puVar1,0,0);
    *(undefined4 *)(lVar2 + 0x138) = unaff_XMM13_Da;
    *(ulonglong *)(lVar2 + 8) = *(ulonglong *)(lVar2 + 8) | 0x100;
    *(ulonglong *)(lVar2 + 0x18) = *(ulonglong *)(lVar2 + 0x18) | 0x100;
    *(undefined1 *)(unaff_RDI + 0x5f4) = 1;
  }
  return;
}


/* SwingRegion_140abb8cc @ 0x140abb8cc */

void SwingRegion_140abb8cc(void)

{
  return;
}


/* SwingRegion_140abb8e0 @ 0x140abb8e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140abb8e0(longlong param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 *puVar9;
  int iVar10;
  ulonglong uVar11;
  int iVar12;
  ulonglong uVar13;
  float fVar14;
  uint uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined8 extraout_XMM0_Qb;
  undefined1 auVar20 [16];
  float fVar21;
  float fVar22;
  undefined1 auVar23 [16];
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float afStackX_10 [2];
  float fStackX_18;
  float afStackX_20 [2];
  uint in_stack_fffffffffffffea8;
  float afStack_148 [4];
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float afStack_128 [2];
  float fStack_120;
  undefined4 uStack_118;
  undefined8 uStack_114;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined1 auStack_f8 [184];
  
  fVar24 = _DAT_14382e128;
  fVar19 = _DAT_14382dce0;
  fVar26 = *(float *)(param_1 + 0x428) - *(float *)(param_1 + 0x560);
  auVar23._0_4_ = fVar26 * _DAT_143830660 + _DAT_14382e128;
  iVar10 = (int)auVar23._0_4_;
  if ((iVar10 != -0x80000000) && ((float)iVar10 != auVar23._0_4_)) {
    auVar23._4_4_ = auVar23._0_4_;
    auVar23._8_8_ = 0;
    uVar6 = movmskps((int)&stack0x00000000,auVar23);
    auVar23._0_4_ = (float)(int)(iVar10 - (uVar6 & 1));
  }
  uVar11 = 0;
  auVar23._0_4_ = (fVar26 - auVar23._0_4_ * _DAT_14383011c) * _DAT_143830124;
  if ((_DAT_143864ed8 < auVar23._0_4_) || (*(float *)(param_1 + 0x564) < _DAT_14384002c)) {
    *(undefined4 *)(param_1 + 0x570) = 0;
    *(undefined4 *)(param_1 + 0x568) = 0x3f800000;
    fVar26 = fVar19;
  }
  else {
    fVar26 = *(float *)(param_1 + 0x568);
    if (fVar26 < _DAT_14382dce0) {
      auVar23._0_4_ = (auVar23._0_4_ - _DAT_14382f0e0) * _DAT_14386dc70;
      fVar14 = (*(float *)(param_1 + 0x564) - _DAT_14384002c) * _DAT_1438ac37c;
      if (auVar23._0_4_ <= 0.0) {
        auVar23._0_4_ = 0.0;
      }
      if (fVar14 <= 0.0) {
        fVar14 = 0.0;
      }
      if (_DAT_14382dce0 <= auVar23._0_4_) {
        auVar23._0_4_ = _DAT_14382dce0;
      }
      if (_DAT_14382dce0 <= fVar14) {
        fVar14 = _DAT_14382dce0;
      }
      fVar29 = *(float *)(param_1 + 0x56c);
      if (*(float *)(param_1 + 0x56c) <= auVar23._0_4_) {
        fVar29 = auVar23._0_4_;
      }
      fVar14 = _DAT_14382dce0 - fVar14;
      bVar5 = _DAT_14382ee88 <= fVar29;
      *(float *)(param_1 + 0x56c) = fVar29;
      if (bVar5) {
        *(undefined4 *)(param_1 + 0x570) = 0;
      }
      else {
        auVar23._0_4_ =
             *(float *)(param_1 + 0x570) -
             ((fVar29 + fVar14) * _DAT_143834a14 + fVar29 * fVar14 * _DAT_1438388d0 + fVar19) *
             param_3;
        bVar5 = _DAT_14382e118 <= auVar23._0_4_;
        *(float *)(param_1 + 0x570) = auVar23._0_4_;
        if (bVar5) goto LAB_140abbaf5;
      }
      fVar26 = (fVar29 * _DAT_1438cea5c + fVar29 * fVar14 * _DAT_1438cea64 +
               fVar14 * _DAT_14383479c + _DAT_143834a0c) * param_3 + fVar26;
      if (fVar19 <= fVar26) {
        fVar26 = fVar19;
      }
      *(float *)(param_1 + 0x568) = fVar26;
    }
  }
LAB_140abbaf5:
  fStackX_18 = param_3;
  FUN_141c5b3e0(afStack_128,param_1 + 0x554,param_1 + 0x418,fVar26);
  uVar6 = _DAT_14382e160;
  afStack_148[2] = param_2[2];
  afStack_148[0] = *param_2;
  auVar23._0_4_ = (float)((uint)afStack_148[2] & _DAT_14382e160);
  if (auVar23._0_4_ <= 0.0) {
    auVar23._0_4_ = 0.0;
  }
  if (auVar23._0_4_ <= (float)((uint)afStack_148[0] & _DAT_14382e160)) {
    auVar23._0_4_ = (float)((uint)afStack_148[0] & _DAT_14382e160);
  }
  if (0.0 < auVar23._0_4_) {
    afStack_148[2] = (fVar19 / auVar23._0_4_) * afStack_148[2];
    afStack_148[0] = (fVar19 / auVar23._0_4_) * afStack_148[0];
    auVar23._0_4_ = fVar19 / SQRT(afStack_148[2] * afStack_148[2] + afStack_148[0] * afStack_148[0])
    ;
    afStack_148[2] = auVar23._0_4_ * afStack_148[2];
    afStack_148[0] = auVar23._0_4_ * afStack_148[0];
  }
  afStack_148[1] = 0.0;
  bVar5 = 0.0 < afStack_128[0] * afStack_148[2] - fStack_120 * afStack_148[0];
  if ((((*(float *)(param_1 + 0x568) <= _DAT_14387a8c8) ||
       (_DAT_143840108 <=
        *(float *)(param_1 + 0x41c) * 0.0 + afStack_148[0] * *(float *)(param_1 + 0x418) +
        afStack_148[2] * *(float *)(param_1 + 0x420))) &&
      ((*(int *)(param_1 + 0x574) != 2 ||
       (_DAT_143834794 < *(float *)(param_1 + 0x424) ||
        _DAT_143834794 == *(float *)(param_1 + 0x424))))) &&
     (auVar23._0_4_ = (float)func_0x000141c59090(afStack_148,afStack_128),
     _DAT_1438cea30 <= auVar23._0_4_)) {
    fVar26 = auVar23._0_4_ * _DAT_1438b55a0;
    if (fVar26 <= 0.0) {
      fVar26 = 0.0;
    }
    if (fVar19 <= fVar26) {
      fVar26 = fVar19;
    }
    fStack_134 = (fVar26 - _DAT_143848d00) * _DAT_1438cea50;
    if (fStack_134 <= 0.0) {
      fStack_134 = 0.0;
    }
    if (fVar19 <= fStack_134) {
      fStack_134 = fVar19;
    }
    if (*(char *)(param_1 + 0x5f3) == '\0') {
      fVar14 = *(float *)(param_1 + 0x500);
    }
    else {
      fVar14 = fStack_134 * fVar26 * _DAT_143839a5c;
    }
    lVar8 = *(longlong *)(param_1 + 0x378);
    lVar4 = *(longlong *)(param_1 + 8);
    *(float *)(param_1 + 0x500) = fVar14;
    fVar14 = fVar26 * param_3 * *(float *)(lVar8 + 0x28) + fVar14;
    if (fVar26 <= fVar14) {
      fVar14 = fVar26;
    }
    *(float *)(param_1 + 0x500) = fVar14;
    fVar26 = *(float *)(lVar8 + 0xc);
    fVar29 = *(float *)(lVar8 + 8);
    fVar25 = *(float *)(lVar8 + 0x14);
    fVar1 = *(float *)(lVar8 + 0x10);
    fVar31 = *(float *)(lVar8 + 0x24);
    fVar2 = *(float *)(lVar8 + 0x20);
    fVar27 = *(float *)(lVar8 + 8);
    fVar3 = *(float *)(lVar8 + 0x10);
    fVar30 = *(float *)(lVar8 + 0x20);
    if (*(short *)(lVar4 + 0x88) == 0) {
      plVar7 = (longlong *)FUN_14167ab40(lVar4 + 0x58,0x146dd6030);
    }
    else {
      plVar7 = (longlong *)func_0x0001416799a0(lVar4 + 0x80);
    }
    uVar15 = (**(code **)(*plVar7 + 0xa0))(plVar7);
    fVar28 = ((float)(uVar15 & uVar6) - _DAT_14382e120) * _DAT_143880d88;
    if (fVar28 <= 0.0) {
      fVar28 = 0.0;
    }
    if (fVar19 <= fVar28) {
      fVar28 = fVar19;
    }
    fVar16 = fVar28;
    if (fVar28 <= *(float *)(param_1 + 0x550)) {
      fVar16 = (float)func_0x000141c477e0();
    }
    lVar8 = *(longlong *)(param_1 + 8);
    fVar21 = fVar28 * _DAT_14382e124;
    *(float *)(param_1 + 0x550) = fVar16;
    fVar21 = fVar21 + fVar19;
    fVar16 = *(float *)(param_1 + 0x568) * _DAT_1438cea4c;
    if (fVar16 <= 0.0) {
      fVar16 = 0.0;
    }
    if (fVar19 <= fVar16) {
      fVar16 = fVar19;
    }
    fVar16 = (fVar19 - fVar16) * _DAT_1438cea34 + fVar19;
    fVar31 = ((fVar19 - fVar28 * fVar24) * ((fVar31 - fVar2) * fVar14 + fVar30)) / fVar16;
    if (*(short *)(lVar8 + 0x88) == 0) {
      lVar8 = FUN_14167ab40(lVar8 + 0x58,0x146dacd70);
    }
    else {
      lVar8 = func_0x0001416799a0(lVar8 + 0x80);
    }
    fVar2 = *(float *)(lVar8 + 0x34c);
    fVar29 = ((fVar26 - fVar29) * fVar14 + fVar27) * fVar21 * fVar16 * fVar2;
    fStack_130 = fVar31 + (fVar31 / fVar2 - fVar31) * _DAT_143848d00;
    FUN_140ab4450(param_1 + 0x444,param_1 + 0x3c8,param_1 + 0x4d0,&uStack_108,afStackX_20,
                  afStackX_10,in_stack_fffffffffffffea8 & 0xffffff00);
    fVar26 = _DAT_14382e118;
    lVar8 = *(longlong *)(param_1 + 0x378);
    afStackX_10[0] = _DAT_143861350 - afStackX_10[0];
    if (afStackX_10[0] <= 0.0) {
      afStackX_10[0] = 0.0;
    }
    fVar31 = *(float *)(lVar8 + 0x2c);
    fVar27 = *(float *)(lVar8 + 0x30) - fVar31;
    if ((float)((uint)fVar27 & uVar6) <= _DAT_14382e118) {
      if (fVar31 <= afStackX_20[0]) {
        fVar27 = fVar24;
        if (fVar31 < afStackX_20[0]) {
          fVar27 = fVar19;
        }
      }
      else {
        fVar27 = 0.0;
      }
    }
    else {
      fVar27 = (afStackX_20[0] - fVar31) / fVar27;
      if (fVar27 <= 0.0) {
        fVar27 = 0.0;
      }
      if (fVar19 <= fVar27) {
        fVar27 = fVar19;
      }
    }
    fVar31 = *(float *)(lVar8 + 0x34);
    fVar30 = *(float *)(lVar8 + 0x38);
    fVar22 = *(float *)(lVar8 + 0x3c) - fVar30;
    fVar28 = *(float *)(lVar8 + 0x34);
    if ((float)((uint)fVar22 & uVar6) <= _DAT_14382e118) {
      if (fVar30 <= afStackX_10[0]) {
        if (fVar30 < afStackX_10[0]) {
          fVar24 = fVar19;
        }
      }
      else {
        fVar24 = 0.0;
      }
    }
    else {
      fVar24 = (afStackX_10[0] - fVar30) / fVar22;
      if (fVar24 <= 0.0) {
        fVar24 = 0.0;
      }
      if (fVar19 <= fVar24) {
        fVar24 = fVar19;
      }
    }
    fVar22 = 0.0;
    iVar10 = -2;
    fVar30 = 0.0;
    do {
      auVar20._0_8_ = func_0x000140b8fda0(param_1 + 0x120,iVar10);
      auVar20._8_8_ = extraout_XMM0_Qb;
      if ((float)auVar20._0_8_ <= fVar30) {
        auVar20._0_4_ = fVar30;
      }
      iVar10 = iVar10 + 1;
      fVar30 = auVar20._0_4_;
    } while (iVar10 < 3);
    iVar10 = -1;
    iVar12 = 1;
    do {
      func_0x000140b8fda0(param_1 + 0x120,iVar10);
      fVar17 = (float)func_0x000140b8fda0(param_1 + 0x120,iVar12);
      iVar12 = iVar12 + 1;
      fVar17 = fVar30 - fVar17;
      iVar10 = iVar10 + -1;
      if (fVar17 <= 0.0) {
        fVar17 = 0.0;
      }
      fVar22 = fVar22 + fVar17;
    } while (-4 < iVar10);
    uStack_108 = _DAT_1438cea80;
    uStack_100 = _UNK_1438cea88;
    fStack_138 = fVar22;
    iVar10 = func_0x000140b8fdb0(param_1 + 0x120);
    uVar13 = uVar11;
    if (0 < iVar10) {
      do {
        func_0x000140b8fdf0(param_1 + 0x120,uVar13,bVar5);
        uVar11 = uVar11 + 1;
        uVar13 = (ulonglong)((int)uVar13 + 1);
        fVar26 = _DAT_14382e118;
      } while ((longlong)uVar11 < (longlong)iVar10);
    }
    fVar17 = fStackX_18;
    fVar18 = (float)func_0x000141c477e0();
    fVar22 = _DAT_143830118;
    fVar30 = *(float *)(param_1 + 0x424);
    *(float *)(param_1 + 0x47c) = fVar18;
    fVar18 = ((((fVar25 - fVar1) * fVar14 + fVar3) * fVar21 * fVar16 * fVar2 - fVar29) *
              (fVar19 - fVar24) + fVar29) * ((fVar19 - fVar31) * (fVar19 - fVar27) + fVar28) *
             fVar18;
    if (fVar22 < fVar30) {
      if (_DAT_14382e130 <= fVar30) {
        fVar24 = (fVar30 - _DAT_14382e130) * _DAT_1438cea54;
        if (fVar24 <= 0.0) {
          fVar24 = 0.0;
        }
        if (fVar19 <= fVar24) {
          fVar24 = fVar19;
        }
        fVar24 = fVar24 * _DAT_1438cea38 + _DAT_143854044;
      }
      else {
        fVar30 = fVar30 * _DAT_1438ac3b8;
        if (fVar30 <= 0.0) {
          fVar30 = 0.0;
        }
        if (fVar19 <= fVar30) {
          fVar30 = fVar19;
        }
        fVar24 = (fVar30 + fVar19) * _DAT_143848d00;
      }
      fVar14 = ((float)((uint)(*(float *)(param_1 + 0x428) * _DAT_143830124) & _DAT_14382e160) -
               _DAT_14382f0e8) * _DAT_14386dc70;
      if (fVar14 <= 0.0) {
        fVar14 = 0.0;
      }
      if (fVar19 <= fVar14) {
        fVar14 = fVar19;
      }
      fVar18 = fVar18 * ((fVar24 - fVar19) * fVar14 + fVar19);
    }
    if (!bVar5) {
      auVar23._0_4_ = (float)((uint)auVar23._0_4_ ^ _DAT_14382e890);
    }
    if (*(char *)(param_1 + 0x5f3) != '\0') {
      fVar29 = (auVar23._0_4_ / fVar17) * _DAT_143830124;
      fVar25 = fVar18 * _DAT_14382e128;
      fVar14 = (float)((uint)fVar29 & _DAT_14382e160);
      fVar24 = fVar18 * _DAT_1438388c0 - fVar25;
      if ((float)((uint)fVar24 & _DAT_14382e160) <= fVar26) {
        if (fVar25 <= fVar14) {
          fVar24 = _DAT_14382e128;
          if (fVar25 < fVar14) {
            fVar24 = fVar19;
          }
        }
        else {
          fVar24 = 0.0;
        }
      }
      else {
        fVar24 = (fVar14 - fVar25) / fVar24;
        if (fVar24 <= 0.0) {
          fVar24 = 0.0;
        }
        if (fVar19 <= fVar24) {
          fVar24 = fVar19;
        }
      }
      fVar19 = (float)((uint)((fVar19 - fStack_134) * (fVar19 - fVar24) * fVar29 * _DAT_14382e11c) &
                      _DAT_14382e160);
      if (fVar18 * _DAT_14382e11c <= fVar19) {
        fVar19 = fVar18 * _DAT_14382e11c;
      }
      if (auVar23._0_4_ < 0.0) {
        fVar19 = (float)((uint)fVar19 ^ _DAT_14382e890);
      }
      *(float *)(param_1 + 0x4fc) = fVar19;
    }
    fVar19 = (float)FUN_141c46be0();
    uStack_118 = 0;
    uStack_114 = 0x3f800000;
    FUN_141c54e30(auStack_f8,&uStack_118,auVar23._0_4_ - fVar19);
    puVar9 = (undefined8 *)FUN_141c5b320(&uStack_108,param_2,auStack_f8);
    *(undefined8 *)param_2 = *puVar9;
    param_2[2] = *(float *)(puVar9 + 1);
  }
  return;
}


/* SwingRegion_140abbc12 @ 0x140abbc12 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abbc12(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int iVar10;
  char unaff_R12B;
  undefined8 *unaff_R13;
  int iVar11;
  ulonglong unaff_R15;
  ulonglong uVar12;
  float fVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined4 uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float fVar29;
  uint unaff_XMM12_Da;
  float unaff_XMM13_Da;
  float fVar30;
  float unaff_XMM15_Da;
  float fVar31;
  float in_stack_00000050;
  float fStack0000000000000054;
  float in_stack_00000058;
  undefined4 in_stack_00000070;
  undefined8 uStack0000000000000074;
  undefined4 in_stack_000000e0;
  undefined4 in_stack_000000e8;
  undefined4 in_stack_000000f0;
  undefined4 in_stack_000000f8;
  
  fVar13 = (float)func_0x000141c59090(&stack0x00000040);
  if (_DAT_1438cea30 <= fVar13) {
    fVar19 = fVar13 * _DAT_1438b55a0;
    if (fVar13 * _DAT_1438b55a0 <= unaff_XMM8_Da) {
      fVar19 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fVar19) {
      fVar19 = unaff_XMM7_Da;
    }
    fStack0000000000000054 = (fVar19 - _DAT_143848d00) * _DAT_1438cea50;
    if (fStack0000000000000054 <= unaff_XMM8_Da) {
      fStack0000000000000054 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fStack0000000000000054) {
      fStack0000000000000054 = unaff_XMM7_Da;
    }
    if (*(char *)(unaff_RBX + 0x5f3) == (char)unaff_R15) {
      fVar20 = *(float *)(unaff_RBX + 0x500);
    }
    else {
      fVar20 = fStack0000000000000054 * fVar19 * _DAT_143839a5c;
    }
    lVar8 = *(longlong *)(unaff_RBX + 0x378);
    lVar4 = *(longlong *)(unaff_RBX + 8);
    *(float *)(unaff_RBX + 0x500) = fVar20;
    fVar20 = fVar19 * unaff_XMM15_Da * *(float *)(lVar8 + 0x28) + fVar20;
    if (fVar19 <= fVar20) {
      fVar20 = fVar19;
    }
    *(float *)(unaff_RBX + 0x500) = fVar20;
    fVar19 = *(float *)(lVar8 + 0xc);
    fVar23 = *(float *)(lVar8 + 8);
    fVar25 = *(float *)(lVar8 + 0x14);
    fVar26 = *(float *)(lVar8 + 0x10);
    fVar31 = *(float *)(lVar8 + 0x24);
    fVar1 = *(float *)(lVar8 + 0x20);
    fVar29 = *(float *)(lVar8 + 8);
    fVar2 = *(float *)(lVar8 + 0x10);
    *(float *)(unaff_RBP + 0x90) =
         (*(float *)(lVar8 + 0x1c) - *(float *)(lVar8 + 0x18)) * fVar20 + *(float *)(lVar8 + 0x18);
    fVar27 = *(float *)(lVar8 + 0x20);
    if ((ushort)unaff_R15 < *(ushort *)(lVar4 + 0x88)) {
      plVar7 = (longlong *)func_0x0001416799a0(lVar4 + 0x80);
    }
    else {
      plVar7 = (longlong *)FUN_14167ab40(lVar4 + 0x58,0x146dd6030);
    }
    uVar14 = (**(code **)(*plVar7 + 0xa0))(plVar7);
    fVar28 = ((float)(uVar14 & unaff_XMM12_Da) - _DAT_14382e120) * _DAT_143880d88;
    if (fVar28 <= unaff_XMM8_Da) {
      fVar28 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fVar28) {
      fVar28 = unaff_XMM7_Da;
    }
    fVar15 = fVar28;
    if (fVar28 <= *(float *)(unaff_RBX + 0x550)) {
      fVar15 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x550),fVar28,_DAT_14382f0dc);
    }
    fVar3 = *(float *)(unaff_RBP + 0x90);
    lVar8 = *(longlong *)(unaff_RBX + 8);
    fVar21 = fVar28 * _DAT_14382e124;
    *(float *)(unaff_RBX + 0x550) = fVar15;
    fVar21 = fVar21 + unaff_XMM7_Da;
    fVar15 = *(float *)(unaff_RBX + 0x568) * _DAT_1438cea4c;
    if (fVar15 <= unaff_XMM8_Da) {
      fVar15 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fVar15) {
      fVar15 = unaff_XMM7_Da;
    }
    fVar15 = (unaff_XMM7_Da - fVar15) * _DAT_1438cea34 + unaff_XMM7_Da;
    fVar31 = ((unaff_XMM7_Da - fVar28 * unaff_XMM13_Da) * ((fVar31 - fVar1) * fVar20 + fVar27)) /
             fVar15;
    *(float *)(unaff_RBP + 0x90) = fVar3 * (fVar28 + unaff_XMM7_Da) * fVar15;
    if ((ushort)unaff_R15 < *(ushort *)(lVar8 + 0x88)) {
      lVar8 = func_0x0001416799a0(lVar8 + 0x80);
    }
    else {
      lVar8 = FUN_14167ab40(lVar8 + 0x58,0x146dacd70);
    }
    fVar1 = *(float *)(lVar8 + 0x34c);
    fVar27 = *(float *)(unaff_RBP + 0x90);
    fVar29 = ((fVar19 - fVar23) * fVar20 + fVar29) * fVar21 * fVar15 * fVar1;
    *(float *)(unaff_RBP + 0x90) = fVar27 + (fVar1 * fVar27 - fVar27) * _DAT_143848d00;
    in_stack_00000058 = fVar31 + (fVar31 / fVar1 - fVar31) * _DAT_143848d00;
    FUN_140ab4450(unaff_RBX + 0x444,unaff_RBX + 0x3c8,unaff_RBX + 0x4d0,unaff_RBP + -0x80,
                  unaff_RBP + 0xa8);
    fVar19 = _DAT_14382e118;
    lVar8 = *(longlong *)(unaff_RBX + 0x378);
    fVar23 = _DAT_143861350 - *(float *)(unaff_RBP + 0x98);
    if (fVar23 <= unaff_XMM8_Da) {
      fVar23 = unaff_XMM8_Da;
    }
    *(float *)(unaff_RBP + 0x98) = fVar23;
    fVar31 = *(float *)(lVar8 + 0x2c);
    fVar27 = *(float *)(lVar8 + 0x30) - fVar31;
    if ((float)((uint)fVar27 & unaff_XMM12_Da) <= fVar19) {
      if (fVar31 <= *(float *)(unaff_RBP + 0xa8)) {
        fVar27 = unaff_XMM13_Da;
        if (fVar31 < *(float *)(unaff_RBP + 0xa8)) {
          fVar27 = unaff_XMM7_Da;
        }
      }
      else {
        fVar27 = 0.0;
      }
    }
    else {
      fVar27 = (*(float *)(unaff_RBP + 0xa8) - fVar31) / fVar27;
      if (fVar27 <= unaff_XMM8_Da) {
        fVar27 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar27) {
        fVar27 = unaff_XMM7_Da;
      }
    }
    fVar31 = *(float *)(lVar8 + 0x34);
    fVar28 = *(float *)(lVar8 + 0x38);
    fVar22 = *(float *)(lVar8 + 0x3c) - fVar28;
    fVar3 = *(float *)(lVar8 + 0x34);
    if ((float)((uint)fVar22 & unaff_XMM12_Da) <= fVar19) {
      if (fVar28 <= fVar23) {
        if (fVar28 < fVar23) {
          unaff_XMM13_Da = unaff_XMM7_Da;
        }
      }
      else {
        unaff_XMM13_Da = 0.0;
      }
    }
    else {
      unaff_XMM13_Da = (fVar23 - fVar28) / fVar22;
      if (unaff_XMM13_Da <= unaff_XMM8_Da) {
        unaff_XMM13_Da = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= unaff_XMM13_Da) {
        unaff_XMM13_Da = unaff_XMM7_Da;
      }
    }
    fVar28 = 0.0;
    fVar22 = 0.0;
    iVar10 = -2;
    fVar23 = 0.0;
    do {
      fVar16 = (float)func_0x000140b8fda0(unaff_RBX + 0x120,iVar10);
      if (fVar16 <= fVar23) {
        fVar16 = fVar23;
      }
      iVar10 = iVar10 + 1;
      fVar23 = fVar16;
    } while (iVar10 < 3);
    iVar10 = -1;
    iVar11 = 1;
    do {
      fVar17 = (float)func_0x000140b8fda0(unaff_RBX + 0x120,iVar10);
      fVar23 = fVar16 - fVar17;
      if (fVar16 - fVar17 <= unaff_XMM8_Da) {
        fVar23 = unaff_XMM8_Da;
      }
      fVar28 = fVar28 + fVar23;
      fVar17 = (float)func_0x000140b8fda0(unaff_RBX + 0x120,iVar11);
      uVar6 = _UNK_1438cea8c;
      uVar5 = _UNK_1438cea88;
      uVar24 = _UNK_1438cea84;
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + -1;
      fVar23 = fVar16 - fVar17;
      if (fVar16 - fVar17 <= unaff_XMM8_Da) {
        fVar23 = unaff_XMM8_Da;
      }
      fVar22 = fVar22 + fVar23;
    } while (-4 < iVar10);
    *(undefined4 *)(unaff_RBP + -0x80) = _DAT_1438cea80;
    *(undefined4 *)(unaff_RBP + -0x7c) = uVar24;
    *(undefined4 *)(unaff_RBP + -0x78) = uVar5;
    *(undefined4 *)(unaff_RBP + -0x74) = uVar6;
    in_stack_00000050 = fVar22;
    iVar10 = func_0x000140b8fdb0(unaff_RBX + 0x120);
    fVar23 = _DAT_1438398cc;
    uVar12 = unaff_R15;
    fVar22 = unaff_XMM8_Da;
    fVar17 = unaff_XMM8_Da;
    fVar30 = unaff_XMM8_Da;
    if (0 < iVar10) {
      do {
        fVar19 = *(float *)(unaff_RBP + -0x80 + unaff_R15 * 4);
        fVar30 = fVar30 + fVar19;
        fVar18 = (float)func_0x000140b8fdf0(unaff_RBX + 0x120,uVar12 & 0xffffffff,unaff_R12B);
        unaff_R15 = unaff_R15 + 1;
        fVar18 = (fVar18 - _DAT_143834a14) * fVar23;
        if (fVar18 <= unaff_XMM8_Da) {
          fVar18 = unaff_XMM8_Da;
        }
        if (unaff_XMM7_Da <= fVar18) {
          fVar18 = unaff_XMM7_Da;
        }
        fVar17 = fVar17 + fVar19 * fVar18;
        uVar12 = (ulonglong)((int)uVar12 + 1);
      } while ((longlong)unaff_R15 < (longlong)iVar10);
      fVar19 = _DAT_14382e118;
      if (_DAT_14382e118 <= fVar30) {
        fVar22 = fVar17 / fVar30;
      }
    }
    fVar23 = (fVar16 - _DAT_14383479c) * _DAT_14382e120;
    if (fVar23 <= unaff_XMM8_Da) {
      fVar23 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fVar23) {
      fVar23 = unaff_XMM7_Da;
    }
    if (unaff_R12B == '\0') {
      fVar28 = in_stack_00000050;
    }
    fVar28 = fVar28 * _DAT_1438ac37c - _DAT_143837a24;
    if (fVar28 <= unaff_XMM8_Da) {
      fVar28 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fVar28) {
      fVar28 = unaff_XMM7_Da;
    }
    fVar23 = fVar28 * fVar23 * _DAT_143836d0c;
    fVar23 = (unaff_XMM7_Da - fVar23) + fVar23 * fVar22;
    uVar24 = _DAT_14383f84c;
    if (*(float *)(unaff_RBX + 0x47c) < fVar23) {
      uVar24 = _DAT_143830120;
    }
    fVar28 = *(float *)(unaff_RBP + 0xa0);
    fVar16 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x47c),fVar23,uVar24,fVar28);
    fVar22 = _DAT_143830118;
    fVar23 = *(float *)(unaff_RBX + 0x424);
    *(float *)(unaff_RBX + 0x47c) = fVar16;
    fVar16 = ((((fVar25 - fVar26) * fVar20 + fVar2) * fVar21 * fVar15 * fVar1 - fVar29) *
              (unaff_XMM7_Da - unaff_XMM13_Da) + fVar29) *
             ((unaff_XMM7_Da - fVar31) * (unaff_XMM7_Da - fVar27) + fVar3) * fVar16;
    if (fVar22 < fVar23) {
      if (_DAT_14382e130 <= fVar23) {
        fVar20 = (fVar23 - _DAT_14382e130) * _DAT_1438cea54;
        if (fVar20 <= unaff_XMM8_Da) {
          fVar20 = unaff_XMM8_Da;
        }
        if (unaff_XMM7_Da <= fVar20) {
          fVar20 = unaff_XMM7_Da;
        }
        fVar20 = fVar20 * _DAT_1438cea38 + _DAT_143854044;
      }
      else {
        fVar20 = fVar23 * _DAT_1438ac3b8;
        if (fVar23 * _DAT_1438ac3b8 <= unaff_XMM8_Da) {
          fVar20 = unaff_XMM8_Da;
        }
        if (unaff_XMM7_Da <= fVar20) {
          fVar20 = unaff_XMM7_Da;
        }
        fVar20 = (fVar20 + unaff_XMM7_Da) * _DAT_143848d00;
      }
      fVar23 = ((float)((uint)(*(float *)(unaff_RBX + 0x428) * _DAT_143830124) & _DAT_14382e160) -
               _DAT_14382f0e8) * _DAT_14386dc70;
      if (fVar23 <= unaff_XMM8_Da) {
        fVar23 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar23) {
        fVar23 = unaff_XMM7_Da;
      }
      fVar16 = fVar16 * ((fVar20 - unaff_XMM7_Da) * fVar23 + unaff_XMM7_Da);
    }
    if (unaff_R12B == '\0') {
      fVar13 = (float)((uint)fVar13 ^ _DAT_14382e890);
    }
    if (*(char *)(unaff_RBX + 0x5f3) != '\0') {
      fVar25 = (fVar13 / fVar28) * _DAT_143830124;
      fVar26 = fVar16 * _DAT_14382e128;
      fVar23 = (float)((uint)fVar25 & _DAT_14382e160);
      fVar20 = fVar16 * _DAT_1438388c0 - fVar26;
      if ((float)((uint)fVar20 & _DAT_14382e160) <= fVar19) {
        fVar20 = unaff_XMM8_Da;
        if ((fVar26 <= fVar23) && (fVar20 = _DAT_14382e128, fVar26 < fVar23)) {
          fVar20 = unaff_XMM7_Da;
        }
      }
      else {
        fVar20 = (fVar23 - fVar26) / fVar20;
        if (fVar20 <= unaff_XMM8_Da) {
          fVar20 = unaff_XMM8_Da;
        }
        if (unaff_XMM7_Da <= fVar20) {
          fVar20 = unaff_XMM7_Da;
        }
      }
      fVar19 = (float)((uint)((unaff_XMM7_Da - fStack0000000000000054) * (unaff_XMM7_Da - fVar20) *
                             fVar25 * _DAT_14382e11c) & _DAT_14382e160);
      if (fVar16 * _DAT_14382e11c <= fVar19) {
        fVar19 = fVar16 * _DAT_14382e11c;
      }
      if (fVar13 < unaff_XMM8_Da) {
        fVar19 = (float)((uint)fVar19 ^ _DAT_14382e890);
      }
      *(float *)(unaff_RBX + 0x4fc) = fVar19;
    }
    fVar19 = (float)FUN_141c46be0(fVar13);
    in_stack_00000070 = 0;
    uStack0000000000000074 = 0x3f800000;
    FUN_141c54e30(unaff_RBP + -0x70,&stack0x00000070,fVar13 - fVar19);
    puVar9 = (undefined8 *)FUN_141c5b320(unaff_RBP + -0x80);
    *unaff_R13 = *puVar9;
    *(undefined4 *)(unaff_R13 + 1) = *(undefined4 *)(puVar9 + 1);
  }
  return;
}


/* SwingRegion_140abbc3f @ 0x140abbc3f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abbc3f(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong unaff_RBX;
  longlong unaff_RBP;
  int iVar10;
  char unaff_R12B;
  undefined8 *unaff_R13;
  int iVar11;
  ulonglong unaff_R15;
  ulonglong uVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined4 uVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float fVar27;
  float fVar28;
  uint unaff_XMM12_Da;
  float fVar29;
  float unaff_XMM13_Da;
  float fVar30;
  float unaff_XMM14_Da;
  float unaff_XMM15_Da;
  float fVar31;
  float fStack0000000000000054;
  undefined4 in_stack_00000070;
  undefined8 uStack0000000000000074;
  
  if (param_1 <= unaff_XMM8_Da) {
    param_1 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= param_1) {
    param_1 = unaff_XMM7_Da;
  }
  fStack0000000000000054 = (param_1 - _DAT_143848d00) * _DAT_1438cea50;
  if (fStack0000000000000054 <= unaff_XMM8_Da) {
    fStack0000000000000054 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= fStack0000000000000054) {
    fStack0000000000000054 = unaff_XMM7_Da;
  }
  if (*(char *)(unaff_RBX + 0x5f3) == (char)unaff_R15) {
    fVar18 = *(float *)(unaff_RBX + 0x500);
  }
  else {
    fVar18 = fStack0000000000000054 * param_1 * _DAT_143839a5c;
  }
  lVar8 = *(longlong *)(unaff_RBX + 0x378);
  lVar4 = *(longlong *)(unaff_RBX + 8);
  *(float *)(unaff_RBX + 0x500) = fVar18;
  fVar18 = param_1 * unaff_XMM15_Da * *(float *)(lVar8 + 0x28) + fVar18;
  if (param_1 <= fVar18) {
    fVar18 = param_1;
  }
  *(float *)(unaff_RBX + 0x500) = fVar18;
  fVar31 = *(float *)(lVar8 + 0xc);
  fVar21 = *(float *)(lVar8 + 8);
  fVar23 = *(float *)(lVar8 + 0x14);
  fVar24 = *(float *)(lVar8 + 0x10);
  fVar27 = *(float *)(lVar8 + 8);
  fVar1 = *(float *)(lVar8 + 0x10);
  *(float *)(unaff_RBP + 0x90) =
       (*(float *)(lVar8 + 0x1c) - *(float *)(lVar8 + 0x18)) * fVar18 + *(float *)(lVar8 + 0x18);
  if ((ushort)unaff_R15 < *(ushort *)(lVar4 + 0x88)) {
    plVar7 = (longlong *)func_0x0001416799a0(lVar4 + 0x80);
  }
  else {
    plVar7 = (longlong *)FUN_14167ab40(lVar4 + 0x58,0x146dd6030);
  }
  uVar13 = (**(code **)(*plVar7 + 0xa0))(plVar7);
  fVar26 = ((float)(uVar13 & unaff_XMM12_Da) - _DAT_14382e120) * _DAT_143880d88;
  if (fVar26 <= unaff_XMM8_Da) {
    fVar26 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= fVar26) {
    fVar26 = unaff_XMM7_Da;
  }
  fVar14 = fVar26;
  if (fVar26 <= *(float *)(unaff_RBX + 0x550)) {
    fVar14 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x550),fVar26,_DAT_14382f0dc);
  }
  fVar2 = *(float *)(unaff_RBP + 0x90);
  lVar8 = *(longlong *)(unaff_RBX + 8);
  fVar19 = fVar26 * _DAT_14382e124;
  *(float *)(unaff_RBX + 0x550) = fVar14;
  fVar19 = fVar19 + unaff_XMM7_Da;
  fVar14 = *(float *)(unaff_RBX + 0x568) * _DAT_1438cea4c;
  if (fVar14 <= unaff_XMM8_Da) {
    fVar14 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= fVar14) {
    fVar14 = unaff_XMM7_Da;
  }
  fVar14 = (unaff_XMM7_Da - fVar14) * _DAT_1438cea34 + unaff_XMM7_Da;
  *(float *)(unaff_RBP + 0x90) = fVar2 * (fVar26 + unaff_XMM7_Da) * fVar14;
  if ((ushort)unaff_R15 < *(ushort *)(lVar8 + 0x88)) {
    lVar8 = func_0x0001416799a0(lVar8 + 0x80);
  }
  else {
    lVar8 = FUN_14167ab40(lVar8 + 0x58,0x146dacd70);
  }
  fVar26 = *(float *)(lVar8 + 0x34c);
  fVar2 = *(float *)(unaff_RBP + 0x90);
  fVar27 = ((fVar31 - fVar21) * fVar18 + fVar27) * fVar19 * fVar14 * fVar26;
  *(float *)(unaff_RBP + 0x90) = fVar2 + (fVar26 * fVar2 - fVar2) * _DAT_143848d00;
  FUN_140ab4450(unaff_RBX + 0x444,unaff_RBX + 0x3c8,unaff_RBX + 0x4d0,unaff_RBP + -0x80,
                unaff_RBP + 0xa8);
  fVar31 = _DAT_14382e118;
  lVar8 = *(longlong *)(unaff_RBX + 0x378);
  fVar21 = _DAT_143861350 - *(float *)(unaff_RBP + 0x98);
  if (fVar21 <= unaff_XMM8_Da) {
    fVar21 = unaff_XMM8_Da;
  }
  *(float *)(unaff_RBP + 0x98) = fVar21;
  fVar2 = *(float *)(lVar8 + 0x2c);
  fVar25 = *(float *)(lVar8 + 0x30) - fVar2;
  if ((float)((uint)fVar25 & unaff_XMM12_Da) <= fVar31) {
    if (fVar2 <= *(float *)(unaff_RBP + 0xa8)) {
      fVar25 = unaff_XMM13_Da;
      if (fVar2 < *(float *)(unaff_RBP + 0xa8)) {
        fVar25 = unaff_XMM7_Da;
      }
    }
    else {
      fVar25 = 0.0;
    }
  }
  else {
    fVar25 = (*(float *)(unaff_RBP + 0xa8) - fVar2) / fVar25;
    if (fVar25 <= unaff_XMM8_Da) {
      fVar25 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fVar25) {
      fVar25 = unaff_XMM7_Da;
    }
  }
  fVar2 = *(float *)(lVar8 + 0x34);
  fVar28 = *(float *)(lVar8 + 0x38);
  fVar20 = *(float *)(lVar8 + 0x3c) - fVar28;
  fVar3 = *(float *)(lVar8 + 0x34);
  if ((float)((uint)fVar20 & unaff_XMM12_Da) <= fVar31) {
    if (fVar28 <= fVar21) {
      if (fVar28 < fVar21) {
        unaff_XMM13_Da = unaff_XMM7_Da;
      }
    }
    else {
      unaff_XMM13_Da = 0.0;
    }
  }
  else {
    unaff_XMM13_Da = (fVar21 - fVar28) / fVar20;
    if (unaff_XMM13_Da <= unaff_XMM8_Da) {
      unaff_XMM13_Da = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= unaff_XMM13_Da) {
      unaff_XMM13_Da = unaff_XMM7_Da;
    }
  }
  fVar28 = 0.0;
  fVar20 = 0.0;
  iVar10 = -2;
  fVar21 = 0.0;
  do {
    fVar15 = (float)func_0x000140b8fda0(unaff_RBX + 0x120,iVar10);
    if (fVar15 <= fVar21) {
      fVar15 = fVar21;
    }
    iVar10 = iVar10 + 1;
    fVar21 = fVar15;
  } while (iVar10 < 3);
  iVar10 = -1;
  iVar11 = 1;
  do {
    fVar16 = (float)func_0x000140b8fda0(unaff_RBX + 0x120,iVar10);
    fVar21 = fVar15 - fVar16;
    if (fVar15 - fVar16 <= unaff_XMM8_Da) {
      fVar21 = unaff_XMM8_Da;
    }
    fVar28 = fVar28 + fVar21;
    fVar16 = (float)func_0x000140b8fda0(unaff_RBX + 0x120,iVar11);
    uVar6 = _UNK_1438cea8c;
    uVar5 = _UNK_1438cea88;
    uVar22 = _UNK_1438cea84;
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + -1;
    fVar21 = fVar15 - fVar16;
    if (fVar15 - fVar16 <= unaff_XMM8_Da) {
      fVar21 = unaff_XMM8_Da;
    }
    fVar20 = fVar20 + fVar21;
  } while (-4 < iVar10);
  *(undefined4 *)(unaff_RBP + -0x80) = _DAT_1438cea80;
  *(undefined4 *)(unaff_RBP + -0x7c) = uVar22;
  *(undefined4 *)(unaff_RBP + -0x78) = uVar5;
  *(undefined4 *)(unaff_RBP + -0x74) = uVar6;
  iVar10 = func_0x000140b8fdb0(unaff_RBX + 0x120);
  fVar21 = _DAT_1438398cc;
  uVar12 = unaff_R15;
  fVar16 = unaff_XMM8_Da;
  fVar29 = unaff_XMM8_Da;
  fVar30 = unaff_XMM8_Da;
  if (0 < iVar10) {
    do {
      fVar31 = *(float *)(unaff_RBP + -0x80 + unaff_R15 * 4);
      fVar30 = fVar30 + fVar31;
      fVar17 = (float)func_0x000140b8fdf0(unaff_RBX + 0x120,uVar12 & 0xffffffff,unaff_R12B);
      unaff_R15 = unaff_R15 + 1;
      fVar17 = (fVar17 - _DAT_143834a14) * fVar21;
      if (fVar17 <= unaff_XMM8_Da) {
        fVar17 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar17) {
        fVar17 = unaff_XMM7_Da;
      }
      fVar29 = fVar29 + fVar31 * fVar17;
      uVar12 = (ulonglong)((int)uVar12 + 1);
    } while ((longlong)unaff_R15 < (longlong)iVar10);
    fVar31 = _DAT_14382e118;
    if (_DAT_14382e118 <= fVar30) {
      fVar16 = fVar29 / fVar30;
    }
  }
  fVar21 = (fVar15 - _DAT_14383479c) * _DAT_14382e120;
  if (fVar21 <= unaff_XMM8_Da) {
    fVar21 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= fVar21) {
    fVar21 = unaff_XMM7_Da;
  }
  if (unaff_R12B == '\0') {
    fVar28 = fVar20;
  }
  fVar28 = fVar28 * _DAT_1438ac37c - _DAT_143837a24;
  if (fVar28 <= unaff_XMM8_Da) {
    fVar28 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= fVar28) {
    fVar28 = unaff_XMM7_Da;
  }
  fVar21 = fVar28 * fVar21 * _DAT_143836d0c;
  fVar21 = (unaff_XMM7_Da - fVar21) + fVar21 * fVar16;
  uVar22 = _DAT_14383f84c;
  if (*(float *)(unaff_RBX + 0x47c) < fVar21) {
    uVar22 = _DAT_143830120;
  }
  fVar28 = *(float *)(unaff_RBP + 0xa0);
  fVar15 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x47c),fVar21,uVar22,fVar28);
  fVar20 = _DAT_143830118;
  fVar21 = *(float *)(unaff_RBX + 0x424);
  *(float *)(unaff_RBX + 0x47c) = fVar15;
  fVar15 = ((((fVar23 - fVar24) * fVar18 + fVar1) * fVar19 * fVar14 * fVar26 - fVar27) *
            (unaff_XMM7_Da - unaff_XMM13_Da) + fVar27) *
           ((unaff_XMM7_Da - fVar2) * (unaff_XMM7_Da - fVar25) + fVar3) * fVar15;
  if (fVar20 < fVar21) {
    if (_DAT_14382e130 <= fVar21) {
      fVar18 = (fVar21 - _DAT_14382e130) * _DAT_1438cea54;
      if (fVar18 <= unaff_XMM8_Da) {
        fVar18 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar18) {
        fVar18 = unaff_XMM7_Da;
      }
      fVar18 = fVar18 * _DAT_1438cea38 + _DAT_143854044;
    }
    else {
      fVar18 = fVar21 * _DAT_1438ac3b8;
      if (fVar21 * _DAT_1438ac3b8 <= unaff_XMM8_Da) {
        fVar18 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar18) {
        fVar18 = unaff_XMM7_Da;
      }
      fVar18 = (fVar18 + unaff_XMM7_Da) * _DAT_143848d00;
    }
    fVar21 = ((float)((uint)(*(float *)(unaff_RBX + 0x428) * _DAT_143830124) & _DAT_14382e160) -
             _DAT_14382f0e8) * _DAT_14386dc70;
    if (fVar21 <= unaff_XMM8_Da) {
      fVar21 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fVar21) {
      fVar21 = unaff_XMM7_Da;
    }
    fVar15 = fVar15 * ((fVar18 - unaff_XMM7_Da) * fVar21 + unaff_XMM7_Da);
  }
  if (unaff_R12B == '\0') {
    unaff_XMM14_Da = (float)((uint)unaff_XMM14_Da ^ _DAT_14382e890);
  }
  if (*(char *)(unaff_RBX + 0x5f3) != '\0') {
    fVar23 = (unaff_XMM14_Da / fVar28) * _DAT_143830124;
    fVar24 = fVar15 * _DAT_14382e128;
    fVar21 = (float)((uint)fVar23 & _DAT_14382e160);
    fVar18 = fVar15 * _DAT_1438388c0 - fVar24;
    if ((float)((uint)fVar18 & _DAT_14382e160) <= fVar31) {
      fVar18 = unaff_XMM8_Da;
      if ((fVar24 <= fVar21) && (fVar18 = _DAT_14382e128, fVar24 < fVar21)) {
        fVar18 = unaff_XMM7_Da;
      }
    }
    else {
      fVar18 = (fVar21 - fVar24) / fVar18;
      if (fVar18 <= unaff_XMM8_Da) {
        fVar18 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar18) {
        fVar18 = unaff_XMM7_Da;
      }
    }
    fVar18 = (float)((uint)((unaff_XMM7_Da - fStack0000000000000054) * (unaff_XMM7_Da - fVar18) *
                           fVar23 * _DAT_14382e11c) & _DAT_14382e160);
    if (fVar15 * _DAT_14382e11c <= fVar18) {
      fVar18 = fVar15 * _DAT_14382e11c;
    }
    if (unaff_XMM14_Da < unaff_XMM8_Da) {
      fVar18 = (float)((uint)fVar18 ^ _DAT_14382e890);
    }
    *(float *)(unaff_RBX + 0x4fc) = fVar18;
  }
  fVar18 = (float)FUN_141c46be0(unaff_XMM14_Da);
  in_stack_00000070 = 0;
  uStack0000000000000074 = 0x3f800000;
  FUN_141c54e30(unaff_RBP + -0x70,&stack0x00000070,unaff_XMM14_Da - fVar18);
  puVar9 = (undefined8 *)FUN_141c5b320(unaff_RBP + -0x80);
  *unaff_R13 = *puVar9;
  *(undefined4 *)(unaff_R13 + 1) = *(undefined4 *)(puVar9 + 1);
  return;
}


/* SwingRegion_140abc155 @ 0x140abc155 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abc155(void)

{
  undefined8 *puVar1;
  longlong unaff_RBX;
  longlong unaff_RBP;
  char unaff_R12B;
  undefined8 *unaff_R13;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float fVar7;
  float unaff_XMM11_Da;
  float unaff_XMM12_Da;
  float unaff_XMM14_Da;
  undefined4 unaff_XMM14_Db;
  float unaff_XMM15_Da;
  float fStack0000000000000050;
  float fStack0000000000000054;
  undefined4 in_stack_00000070;
  undefined8 uStack0000000000000074;
  
  fVar7 = fStack0000000000000050 * _DAT_1438ac37c - _DAT_143837a24;
  if (fVar7 <= unaff_XMM8_Da) {
    fVar7 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= fVar7) {
    fVar7 = unaff_XMM7_Da;
  }
  fVar7 = fVar7 * unaff_XMM9_Da * _DAT_143836d0c;
  fVar7 = (unaff_XMM7_Da - fVar7) + fVar7 * unaff_XMM12_Da;
  uVar5 = _DAT_14383f84c;
  if (*(float *)(unaff_RBX + 0x47c) < fVar7) {
    uVar5 = _DAT_143830120;
  }
  fVar4 = *(float *)(unaff_RBP + 0xa0);
  fVar2 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x47c),fVar7,uVar5,fVar4);
  fVar3 = _DAT_143830118;
  fVar7 = *(float *)(unaff_RBX + 0x424);
  *(float *)(unaff_RBX + 0x47c) = fVar2;
  fVar2 = unaff_XMM11_Da * fVar2;
  if (fVar3 < fVar7) {
    if (_DAT_14382e130 <= fVar7) {
      fVar7 = (fVar7 - _DAT_14382e130) * _DAT_1438cea54;
      if (fVar7 <= unaff_XMM8_Da) {
        fVar7 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar7) {
        fVar7 = unaff_XMM7_Da;
      }
      fVar7 = fVar7 * _DAT_1438cea38 + _DAT_143854044;
    }
    else {
      fVar3 = fVar7 * _DAT_1438ac3b8;
      if (fVar7 * _DAT_1438ac3b8 <= unaff_XMM8_Da) {
        fVar3 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar3) {
        fVar3 = unaff_XMM7_Da;
      }
      fVar7 = (fVar3 + unaff_XMM7_Da) * _DAT_143848d00;
    }
    fVar3 = ((float)((uint)(*(float *)(unaff_RBX + 0x428) * _DAT_143830124) & _DAT_14382e160) -
            _DAT_14382f0e8) * _DAT_14386dc70;
    if (fVar3 <= unaff_XMM8_Da) {
      fVar3 = unaff_XMM8_Da;
    }
    if (unaff_XMM7_Da <= fVar3) {
      fVar3 = unaff_XMM7_Da;
    }
    fVar2 = fVar2 * ((fVar7 - unaff_XMM7_Da) * fVar3 + unaff_XMM7_Da);
  }
  if (unaff_R12B == '\0') {
    unaff_XMM14_Da = (float)((uint)unaff_XMM14_Da ^ _DAT_14382e890);
  }
  if (*(char *)(unaff_RBX + 0x5f3) != '\0') {
    fVar3 = (unaff_XMM14_Da / fVar4) * _DAT_143830124;
    fVar6 = fVar2 * _DAT_14382e128;
    fVar4 = (float)((uint)fVar3 & _DAT_14382e160);
    fVar7 = fVar2 * _DAT_1438388c0 - fVar6;
    if ((float)((uint)fVar7 & _DAT_14382e160) <= unaff_XMM15_Da) {
      fVar7 = unaff_XMM8_Da;
      if ((fVar6 <= fVar4) && (fVar7 = _DAT_14382e128, fVar6 < fVar4)) {
        fVar7 = unaff_XMM7_Da;
      }
    }
    else {
      fVar7 = (fVar4 - fVar6) / fVar7;
      if (fVar7 <= unaff_XMM8_Da) {
        fVar7 = unaff_XMM8_Da;
      }
      if (unaff_XMM7_Da <= fVar7) {
        fVar7 = unaff_XMM7_Da;
      }
    }
    fVar7 = (float)((uint)((unaff_XMM7_Da - fStack0000000000000054) * (unaff_XMM7_Da - fVar7) *
                          fVar3 * _DAT_14382e11c) & _DAT_14382e160);
    if (fVar2 * _DAT_14382e11c <= fVar7) {
      fVar7 = fVar2 * _DAT_14382e11c;
    }
    if (unaff_XMM14_Da < unaff_XMM8_Da) {
      fVar7 = (float)((uint)fVar7 ^ _DAT_14382e890);
    }
    *(float *)(unaff_RBX + 0x4fc) = fVar7;
  }
  fVar7 = (float)FUN_141c46be0(CONCAT44(unaff_XMM14_Db,unaff_XMM14_Da));
  in_stack_00000070 = 0;
  uStack0000000000000074 = 0x3f800000;
  FUN_141c54e30(unaff_RBP + -0x70,&stack0x00000070,unaff_XMM14_Da - fVar7);
  puVar1 = (undefined8 *)FUN_141c5b320(unaff_RBP + -0x80);
  *unaff_R13 = *puVar1;
  *(undefined4 *)(unaff_R13 + 1) = *(undefined4 *)(puVar1 + 1);
  return;
}


/* SwingRegion_140abc3fc @ 0x140abc3fc */

void SwingRegion_140abc3fc(void)

{
  return;
}


/* SwingRegion_140abc405 @ 0x140abc405 */

void SwingRegion_140abc405(void)

{
  return;
}


/* SwingRegion_140abc460 @ 0x140abc460 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_140abc460(longlong param_1,float *param_2,float *param_3,undefined8 param_4,
                     float param_5)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  undefined1 auStack_48 [64];
  
  if (*(char *)(param_1 + 0x464) == '\0') {
    fVar5 = param_3[2];
    *(undefined8 *)param_2 = *(undefined8 *)param_3;
    param_2[2] = fVar5;
  }
  else {
    if (*(int *)(param_1 + 0x574) == 0) {
      fVar4 = (float)FUN_1402c2450(param_3);
      fVar5 = param_3[1];
      if (0.0 < fVar5) {
        fVar4 = (float)func_0x0001403e3f30(param_3);
      }
      if (((fVar4 < *(float *)(param_1 + 0x454) || fVar4 == *(float *)(param_1 + 0x454)) ||
          (0.0 <= fVar5)) && (*(float *)(param_1 + 0x57c) <= _DAT_143837a20)) {
        fVar5 = (float)func_0x000141c477e0(*(undefined4 *)(param_1 + 0x45c),
                                           *(undefined4 *)(param_1 + 0x458),
                                           *(undefined4 *)(param_1 + 0x460),param_5);
        fVar4 = *(float *)(param_1 + 0x454) - fVar4;
        *(float *)(param_1 + 0x45c) = fVar5;
        if (fVar4 <= 0.0) {
          fVar4 = 0.0;
        }
        if (fVar5 * param_5 <= fVar4) {
          fVar4 = fVar5 * param_5;
        }
        pfVar3 = (float *)FUN_140a2f110(auStack_48,param_4,fVar4);
        fVar5 = pfVar3[1];
        fVar4 = pfVar3[2];
        fVar1 = param_3[1];
        fVar2 = param_3[2];
        *param_2 = *pfVar3 + *param_3;
        param_2[1] = fVar5 + fVar1;
        param_2[2] = fVar4 + fVar2;
        return param_2;
      }
    }
    *(undefined1 *)(param_1 + 0x464) = 0;
    fVar5 = param_3[2];
    *(undefined8 *)param_2 = *(undefined8 *)param_3;
    param_2[2] = fVar5;
  }
  return param_2;
}


/* SwingRegion_140abc4a5 @ 0x140abc4a5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abc4a5(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *unaff_RBX;
  longlong unaff_RSI;
  float *unaff_RDI;
  bool in_ZF;
  float fVar5;
  undefined4 uVar6;
  undefined1 auStackX_20 [8];
  undefined4 in_stack_00000090;
  
  if (in_ZF) {
    fVar5 = (float)FUN_1402c2450();
    fVar1 = unaff_RBX[1];
    if (0.0 < fVar1) {
      fVar5 = (float)func_0x0001403e3f30();
    }
    if (((fVar5 < *(float *)(unaff_RSI + 0x454) || fVar5 == *(float *)(unaff_RSI + 0x454)) ||
        (0.0 <= fVar1)) && (*(float *)(unaff_RSI + 0x57c) <= _DAT_143837a20)) {
      uVar6 = func_0x000141c477e0(*(undefined4 *)(unaff_RSI + 0x45c),
                                  *(undefined4 *)(unaff_RSI + 0x458),
                                  *(undefined4 *)(unaff_RSI + 0x460),in_stack_00000090);
      *(undefined4 *)(unaff_RSI + 0x45c) = uVar6;
      pfVar4 = (float *)FUN_140a2f110(auStackX_20);
      fVar1 = pfVar4[1];
      fVar5 = pfVar4[2];
      fVar2 = unaff_RBX[1];
      fVar3 = unaff_RBX[2];
      *unaff_RDI = *pfVar4 + *unaff_RBX;
      unaff_RDI[1] = fVar1 + fVar2;
      unaff_RDI[2] = fVar5 + fVar3;
      return;
    }
  }
  *(undefined1 *)(unaff_RSI + 0x464) = 0;
  fVar1 = unaff_RBX[2];
  *(undefined8 *)unaff_RDI = *(undefined8 *)unaff_RBX;
  unaff_RDI[2] = fVar1;
  return;
}


/* SwingRegion_140abc5b0 @ 0x140abc5b0 */

void SwingRegion_140abc5b0(void)

{
  return;
}


/* SwingRegion_140abc5d0 @ 0x140abc5d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140abc5d0(longlong param_1,undefined8 *param_2,float *param_3,undefined8 param_4,float param_5)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float afStackX_8 [2];
  undefined1 auStackX_10 [8];
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  
  FUN_140ab4450(param_1 + 0x444,param_1 + 0x3c8,param_4,&fStack_58,auStackX_10,afStackX_8,0);
  if (*(int *)(param_1 + 0x574) == 0) {
    if (afStackX_8[0] < _DAT_143861350) {
      *(undefined4 *)(param_1 + 0x574) = 1;
    }
  }
  else if (((*(int *)(param_1 + 0x574) == 1) && (param_3[1] <= 0.0 && param_3[1] != 0.0)) &&
          (_DAT_143864ed8 < afStackX_8[0])) {
    *(undefined4 *)(param_1 + 0x574) = 2;
  }
  fVar3 = *(float *)(param_1 + 0x424);
  fVar4 = 0.0;
  if ((_DAT_143830118 < fVar3) && (_DAT_14387a8c8 < *(float *)(param_1 + 0x568))) {
    fStack_68 = *(float *)(param_1 + 0x4b8);
    fStack_60 = *(float *)(param_1 + 0x4c0);
    fStack_64 = 0.0;
    FUN_1402d0740(&fStack_58,&fStack_68);
    if (fStack_54 * *(float *)(param_1 + 0x41c) + fStack_58 * *(float *)(param_1 + 0x418) +
        fStack_50 * *(float *)(param_1 + 0x420) < _DAT_143840108) {
      fVar4 = (afStackX_8[0] - _DAT_143861350) * _DAT_1438ac374;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
      if (_DAT_14382dce0 <= fVar4) {
        fVar4 = _DAT_14382dce0;
      }
      fVar4 = (_DAT_14382dce0 - fVar4) * fVar3;
    }
  }
  uVar1 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x57c),fVar4,_DAT_14382f0dc,param_5);
  *(undefined4 *)(param_1 + 0x57c) = uVar1;
  *param_2 = *(undefined8 *)param_3;
  *(float *)(param_2 + 1) = param_3[2];
  if (*(int *)(param_1 + 0x574) == 2) {
    fVar3 = param_5 + *(float *)(param_1 + 0x578);
    *(float *)(param_1 + 0x578) = fVar3;
    fVar3 = fVar3 * _DAT_14382e120;
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    if (_DAT_14382dce0 <= fVar3) {
      fVar3 = _DAT_14382dce0;
    }
    fStack_68 = (float)FUN_1402c2450(param_2);
    fStack_64 = param_3[1];
    fVar4 = *param_3;
    fStack_60 = param_3[2];
    fStack_68 = fStack_68 -
                (SQRT(fVar3) * fVar3 * _DAT_1438c0448 + _DAT_143830118) * fStack_68 * param_5;
    fVar3 = fVar4 * fVar4 + fStack_64 * fStack_64 + fStack_60 * fStack_60;
    if (fStack_68 <= 0.0) {
      fStack_68 = 0.0;
    }
    fVar2 = fStack_68 / SQRT(fVar3);
    if (_DAT_14382e110 <= fVar3) {
      fStack_68 = fVar4 * fVar2;
      fStack_64 = fStack_64 * fVar2;
      fStack_60 = fStack_60 * fVar2;
    }
    else {
      fStack_64 = 0.0;
      fStack_60 = 0.0;
    }
    *param_2 = CONCAT44(fStack_64,fStack_68);
    *(float *)(param_2 + 1) = fStack_60;
  }
  return param_2;
}


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
  fVar8 = _DAT_1438ac390;
  uVar2 = _DAT_14382e160;
  fVar12 = _DAT_14382dce0;
  fVar3 = (fVar3 - _DAT_143834a14) * _DAT_14382e124;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0;
  }
  if (_DAT_14382dce0 <= fVar3) {
    fVar3 = _DAT_14382dce0;
  }
  if (_DAT_14382e118 <= fVar3) {
    fVar11 = 0.0;
    fVar4 = (float)((uint)param_3[2] & _DAT_14382e160);
    fVar9 = (float)((uint)*param_3 & _DAT_14382e160);
    if (fVar9 <= fVar4) {
      fVar9 = fVar4;
    }
    fVar7 = (_DAT_14382dce0 / fVar9) * param_3[2];
    fVar4 = (_DAT_14382dce0 / fVar9) * *param_3;
    if (0.0 < fVar9) {
      fVar11 = SQRT(fVar7 * fVar7 + fVar4 * fVar4) * fVar9;
    }
    fVar9 = (fVar11 - _DAT_14382f0e8) * _DAT_1438ac390;
    if (fVar9 <= 0.0) {
      fVar9 = 0.0;
    }
    if (_DAT_14382dce0 <= fVar9) {
      fVar9 = _DAT_14382dce0;
    }
    *(float *)(param_1 + 0x4f8) = (fVar9 + _DAT_14382dce0) * param_7 + *(float *)(param_1 + 0x4f8);
    fVar4 = (float)FUN_140311350(param_5,param_1 + 0x3c8);
    fVar4 = (fVar4 - _DAT_1438957e0) * _DAT_1438564c4;
    if (fVar4 <= 0.0) {
      fVar4 = 0.0;
    }
    if (fVar12 <= fVar4) {
      fVar4 = fVar12;
    }
    fVar4 = (fVar12 - fVar9) * fVar4;
    fVar11 = fVar4 * _DAT_14382e130;
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
    fVar9 = ((float)((uint)(fVar9 * _DAT_143855568) & uVar2) - _DAT_1438794d0) * _DAT_14386dc70;
    if (fVar9 <= 0.0) {
      fVar9 = 0.0;
    }
    fVar8 = (param_3[1] - _DAT_14383f72c) * fVar8;
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
             ((fVar12 - fVar9) * _DAT_143837a1c - fVar4 * (fVar12 - fVar9) * _DAT_1438b4f28);
    fVar8 = fVar12 - fVar8;
    bVar1 = 0.0 < (param_5[1] - *(float *)(param_1 + 0x3cc)) * param_3[1] +
                  (*param_5 - *(float *)(param_1 + 0x3c8)) * *param_3 +
                  (param_5[2] - *(float *)(param_1 + 0x3d0)) * param_3[2];
    fVar4 = _DAT_1438726d4 - (fVar8 + fVar8);
    fVar9 = _DAT_1438347a4;
    if (bVar1) {
      fVar9 = (_DAT_1438cea68 - fVar8 * _DAT_14382e128) * fVar11;
    }
    fVar8 = (*(float *)(param_1 + 0x4f8) - _DAT_143836d08) * _DAT_14384ebec;
    if (fVar8 <= 0.0) {
      fVar8 = 0.0;
    }
    if (fVar12 <= fVar8) {
      fVar8 = fVar12;
    }
    FUN_1402d0740(auStack_c8,param_3);
    FUN_141c46f80(&fStack_d8,auStack_c8,&fStack_e8,param_1 + 0x4f4,
                  ((fVar4 - fVar9) * fVar8 + fVar9) * fVar3,_DAT_1438414f4,
                  ((fVar12 - fVar11) * fVar8 + fVar11) * _DAT_1438cea58,param_7);
    fVar3 = (float)func_0x000141c59090(&fStack_e8,auStack_c8);
    fVar8 = _DAT_14382e110;
    fVar9 = fVar3 * _DAT_1438b146c - _DAT_1438398cc;
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
    if (_DAT_14382e110 <= fVar3) {
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


/* SwingRegion_140abc958 @ 0x140abc958 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abc958(uint param_1,float param_2,float param_3,float param_4)

{
  float *pfVar1;
  bool bVar2;
  uint uVar3;
  float *unaff_RBX;
  longlong unaff_RBP;
  longlong unaff_RSI;
  undefined8 *unaff_RDI;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float fVar12;
  float fStack0000000000000040;
  float fStack0000000000000044;
  float in_stack_00000048;
  float fStack0000000000000050;
  float fStack0000000000000054;
  float in_stack_00000058;
  
  fVar8 = _DAT_1438ac390;
  uVar3 = _DAT_14382e160;
  fVar10 = 0.0;
  fVar11 = (float)((uint)param_2 & _DAT_14382e160);
  if ((float)((uint)param_2 & _DAT_14382e160) <= (float)(param_1 & _DAT_14382e160)) {
    fVar11 = (float)(param_1 & _DAT_14382e160);
  }
  param_3 = (param_4 / fVar11) * param_3;
  param_2 = (param_4 / fVar11) * param_2;
  if (unaff_XMM7_Da < fVar11) {
    fVar10 = SQRT(param_3 * param_3 + param_2 * param_2) * fVar11;
  }
  pfVar1 = *(float **)(unaff_RBP + 0x50);
  fVar11 = (fVar10 - _DAT_14382f0e8) * _DAT_1438ac390;
  if (fVar11 <= unaff_XMM7_Da) {
    fVar11 = unaff_XMM7_Da;
  }
  if (unaff_XMM9_Da <= fVar11) {
    fVar11 = unaff_XMM9_Da;
  }
  *(float *)(unaff_RSI + 0x4f8) =
       (fVar11 + unaff_XMM9_Da) * *(float *)(unaff_RBP + 0x60) + *(float *)(unaff_RSI + 0x4f8);
  fVar10 = (float)FUN_140311350(pfVar1,unaff_RSI + 0x3c8);
  fVar10 = (fVar10 - _DAT_1438957e0) * _DAT_1438564c4;
  if (fVar10 <= unaff_XMM7_Da) {
    fVar10 = unaff_XMM7_Da;
  }
  if (unaff_XMM9_Da <= fVar10) {
    fVar10 = unaff_XMM9_Da;
  }
  fVar10 = (unaff_XMM9_Da - fVar11) * fVar10;
  fVar4 = fVar10 * _DAT_14382e130;
  FUN_1402d0740(&stack0x00000040);
  fVar5 = (float)FUN_1402c2450();
  fVar6 = (float)((uint)unaff_RBX[2] & uVar3);
  fVar11 = (float)((uint)*unaff_RBX & uVar3);
  if (fVar11 <= fVar6) {
    fVar11 = fVar6;
  }
  fVar12 = 0.0;
  fVar9 = (unaff_XMM9_Da / fVar11) * unaff_RBX[2];
  fVar6 = (unaff_XMM9_Da / fVar11) * *unaff_RBX;
  if (unaff_XMM7_Da < fVar11) {
    fVar12 = SQRT(fVar9 * fVar9 + fVar6 * fVar6) * fVar11;
  }
  fVar11 = (float)((uint)in_stack_00000048 & uVar3);
  if ((float)((uint)in_stack_00000048 & uVar3) <= (float)((uint)fStack0000000000000040 & uVar3)) {
    fVar11 = (float)((uint)fStack0000000000000040 & uVar3);
  }
  fVar7 = fStack0000000000000040 * (unaff_XMM9_Da / fVar11);
  fVar9 = in_stack_00000048 * (unaff_XMM9_Da / fVar11);
  fVar6 = 0.0;
  if (unaff_XMM7_Da < fVar11) {
    fVar6 = SQRT(fVar9 * fVar9 + fVar7 * fVar7) * fVar11;
  }
  fVar11 = (float)FUN_141c58560(fStack0000000000000044,fVar6);
  fVar11 = ((float)((uint)(fVar11 * _DAT_143855568) & uVar3) - _DAT_1438794d0) * _DAT_14386dc70;
  if (fVar11 <= unaff_XMM7_Da) {
    fVar11 = unaff_XMM7_Da;
  }
  fVar8 = (unaff_RBX[1] - _DAT_14383f72c) * fVar8;
  if (fVar8 <= unaff_XMM7_Da) {
    fVar8 = unaff_XMM7_Da;
  }
  if (unaff_XMM9_Da <= fVar11) {
    fVar11 = unaff_XMM9_Da;
  }
  if (unaff_XMM9_Da <= fVar8) {
    fVar8 = unaff_XMM9_Da;
  }
  fVar8 = unaff_XMM9_Da - fVar8;
  bVar2 = unaff_XMM7_Da <
          (pfVar1[1] - *(float *)(unaff_RSI + 0x3cc)) * unaff_RBX[1] +
          (*pfVar1 - *(float *)(unaff_RSI + 0x3c8)) * *unaff_RBX +
          (pfVar1[2] - *(float *)(unaff_RSI + 0x3d0)) * unaff_RBX[2];
  fVar9 = _DAT_1438726d4 - (fVar8 + fVar8);
  fVar6 = _DAT_1438347a4;
  if (bVar2) {
    fVar6 = (_DAT_1438cea68 - fVar8 * _DAT_14382e128) *
            ((unaff_XMM9_Da - fVar4) -
            ((unaff_XMM9_Da - fVar11) * _DAT_143837a1c -
            fVar10 * (unaff_XMM9_Da - fVar11) * _DAT_1438b4f28));
  }
  fVar8 = (*(float *)(unaff_RSI + 0x4f8) - _DAT_143836d08) * _DAT_14384ebec;
  if (fVar8 <= unaff_XMM7_Da) {
    fVar8 = unaff_XMM7_Da;
  }
  if (unaff_XMM9_Da <= fVar8) {
    fVar8 = unaff_XMM9_Da;
  }
  FUN_1402d0740(&stack0x00000060);
  FUN_141c46f80(&stack0x00000050,&stack0x00000060,&stack0x00000040,unaff_RSI + 0x4f4,
                ((fVar9 - fVar6) * fVar8 + fVar6) * unaff_XMM8_Da);
  fVar11 = (float)func_0x000141c59090(&stack0x00000040,&stack0x00000060);
  fVar8 = _DAT_14382e110;
  fVar10 = fVar11 * _DAT_1438b146c - _DAT_1438398cc;
  fVar11 = (float)((uint)in_stack_00000058 & uVar3);
  if ((float)((uint)in_stack_00000058 & uVar3) <= (float)((uint)fStack0000000000000054 & uVar3)) {
    fVar11 = (float)((uint)fStack0000000000000054 & uVar3);
  }
  if (fVar10 <= unaff_XMM7_Da) {
    fVar10 = unaff_XMM7_Da;
  }
  if (fVar11 <= (float)((uint)fStack0000000000000050 & uVar3)) {
    fVar11 = (float)((uint)fStack0000000000000050 & uVar3);
  }
  if (unaff_XMM9_Da <= fVar10) {
    fVar10 = unaff_XMM9_Da;
  }
  fVar4 = fStack0000000000000050;
  fVar6 = in_stack_00000058;
  fVar9 = fStack0000000000000054;
  if (unaff_XMM7_Da < fVar11) {
    fVar11 = unaff_XMM9_Da / fVar11;
    fVar6 = in_stack_00000058 * fVar11;
    fVar9 = fStack0000000000000054 * fVar11;
    fVar11 = fStack0000000000000050 * fVar11;
    fVar7 = unaff_XMM9_Da / SQRT(fVar9 * fVar9 + fVar11 * fVar11 + fVar6 * fVar6);
    fVar4 = fVar7 * fVar11;
    fVar6 = fVar7 * fVar6;
    fVar9 = fVar7 * fVar9;
  }
  fVar7 = fStack0000000000000054 * fStack0000000000000054 +
          fStack0000000000000050 * fStack0000000000000050 + in_stack_00000058 * in_stack_00000058;
  fVar5 = ((fVar4 * *unaff_RBX + fVar9 * unaff_RBX[1] + fVar6 * unaff_RBX[2]) - fVar5) * fVar10 +
          fVar5;
  fVar11 = fVar5 / SQRT(fVar7);
  if (_DAT_14382e110 <= fVar7) {
    fVar10 = fStack0000000000000054 * fVar11;
    fVar5 = fStack0000000000000050 * fVar11;
    fVar11 = in_stack_00000058 * fVar11;
  }
  else {
    fVar10 = 0.0;
    fVar11 = 0.0;
  }
  fStack0000000000000040 = fVar5;
  in_stack_00000048 = fVar11;
  if (((*(int *)(unaff_RSI + 0x574) == 0) && (unaff_XMM7_Da < fVar10)) && (bVar2)) {
    fStack0000000000000054 = 0.0;
    fStack0000000000000044 = fVar10;
    fStack0000000000000050 = fVar5;
    in_stack_00000058 = fVar11;
    fStack0000000000000040 = (float)FUN_1402c2450(&stack0x00000050);
    if (fVar12 <= fStack0000000000000040) {
      fStack0000000000000040 = fVar12;
    }
    fVar4 = fVar11 * fVar11 + fVar5 * fVar5;
    in_stack_00000048 = unaff_XMM7_Da;
    if (fVar8 <= fVar4) {
      fStack0000000000000040 = fStack0000000000000040 / SQRT(fVar4);
      in_stack_00000048 = fStack0000000000000040 * fVar11;
      fStack0000000000000040 = fStack0000000000000040 * fVar5;
    }
  }
  *unaff_RDI = CONCAT44(fVar10,fStack0000000000000040);
  *(float *)(unaff_RDI + 1) = in_stack_00000048;
  return;
}


/* SwingRegion_140abcc11 @ 0x140abcc11 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abcc11(undefined8 param_1,float param_2)

{
  float *unaff_RBX;
  longlong unaff_RSI;
  undefined8 *unaff_RDI;
  char unaff_R14B;
  float fVar1;
  float fVar2;
  float fVar3;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float fVar4;
  float fVar5;
  float fVar6;
  uint unaff_XMM11_Da;
  float unaff_XMM12_Da;
  float unaff_XMM13_Da;
  float unaff_XMM14_Da;
  float fVar7;
  float unaff_XMM15_Da;
  float in_stack_00000040;
  float fStack0000000000000044;
  float in_stack_00000048;
  float fStack0000000000000050;
  float fStack0000000000000054;
  float in_stack_00000058;
  
  fVar5 = (_DAT_1438cea68 - param_2 * _DAT_14382e128) * unaff_XMM14_Da;
  fVar3 = (*(float *)(unaff_RSI + 0x4f8) - _DAT_143836d08) * _DAT_14384ebec;
  if (fVar3 <= unaff_XMM7_Da) {
    fVar3 = unaff_XMM7_Da;
  }
  if (unaff_XMM9_Da <= fVar3) {
    fVar3 = unaff_XMM9_Da;
  }
  FUN_1402d0740(&stack0x00000060);
  FUN_141c46f80(&stack0x00000050,&stack0x00000060,&stack0x00000040,unaff_RSI + 0x4f4,
                ((unaff_XMM12_Da - fVar5) * fVar3 + fVar5) * unaff_XMM8_Da);
  fVar5 = (float)func_0x000141c59090(&stack0x00000040,&stack0x00000060);
  fVar3 = _DAT_14382e110;
  fVar7 = fVar5 * _DAT_1438b146c - _DAT_1438398cc;
  fVar5 = (float)((uint)in_stack_00000058 & unaff_XMM11_Da);
  if ((float)((uint)in_stack_00000058 & unaff_XMM11_Da) <=
      (float)((uint)fStack0000000000000054 & unaff_XMM11_Da)) {
    fVar5 = (float)((uint)fStack0000000000000054 & unaff_XMM11_Da);
  }
  if (fVar7 <= unaff_XMM7_Da) {
    fVar7 = unaff_XMM7_Da;
  }
  if (fVar5 <= (float)((uint)fStack0000000000000050 & unaff_XMM11_Da)) {
    fVar5 = (float)((uint)fStack0000000000000050 & unaff_XMM11_Da);
  }
  if (unaff_XMM9_Da <= fVar7) {
    fVar7 = unaff_XMM9_Da;
  }
  fVar6 = fStack0000000000000050;
  fVar2 = in_stack_00000058;
  fVar1 = fStack0000000000000054;
  if (unaff_XMM7_Da < fVar5) {
    fVar5 = unaff_XMM9_Da / fVar5;
    fVar2 = in_stack_00000058 * fVar5;
    fVar1 = fStack0000000000000054 * fVar5;
    fVar5 = fStack0000000000000050 * fVar5;
    fVar4 = unaff_XMM9_Da / SQRT(fVar1 * fVar1 + fVar5 * fVar5 + fVar2 * fVar2);
    fVar6 = fVar4 * fVar5;
    fVar2 = fVar4 * fVar2;
    fVar1 = fVar4 * fVar1;
  }
  fVar4 = fStack0000000000000054 * fStack0000000000000054 +
          fStack0000000000000050 * fStack0000000000000050 + in_stack_00000058 * in_stack_00000058;
  fVar7 = ((fVar6 * *unaff_RBX + fVar1 * unaff_RBX[1] + fVar2 * unaff_RBX[2]) - unaff_XMM15_Da) *
          fVar7 + unaff_XMM15_Da;
  fVar5 = fVar7 / SQRT(fVar4);
  if (_DAT_14382e110 <= fVar4) {
    fVar6 = fStack0000000000000054 * fVar5;
    fVar7 = fStack0000000000000050 * fVar5;
    fVar5 = in_stack_00000058 * fVar5;
  }
  else {
    fVar6 = 0.0;
    fVar5 = 0.0;
  }
  in_stack_00000040 = fVar7;
  in_stack_00000048 = fVar5;
  if (((*(int *)(unaff_RSI + 0x574) == 0) && (unaff_XMM7_Da < fVar6)) && (unaff_R14B != '\0')) {
    fStack0000000000000054 = 0.0;
    fStack0000000000000044 = fVar6;
    fStack0000000000000050 = fVar7;
    in_stack_00000058 = fVar5;
    in_stack_00000040 = (float)FUN_1402c2450(&stack0x00000050);
    if (unaff_XMM13_Da <= in_stack_00000040) {
      in_stack_00000040 = unaff_XMM13_Da;
    }
    fVar2 = fVar5 * fVar5 + fVar7 * fVar7;
    in_stack_00000048 = unaff_XMM7_Da;
    if (fVar3 <= fVar2) {
      in_stack_00000040 = in_stack_00000040 / SQRT(fVar2);
      in_stack_00000048 = in_stack_00000040 * fVar5;
      in_stack_00000040 = in_stack_00000040 * fVar7;
    }
  }
  *unaff_RDI = CONCAT44(fVar6,in_stack_00000040);
  *(float *)(unaff_RDI + 1) = in_stack_00000048;
  return;
}


/* SwingRegion_140abcd46 @ 0x140abcd46 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abcd46(undefined8 param_1,undefined8 param_2,float param_3)

{
  float fVar1;
  float *unaff_RBX;
  longlong unaff_RSI;
  undefined8 *unaff_RDI;
  char unaff_R14B;
  float fVar2;
  float fVar3;
  float fVar4;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float fVar5;
  float unaff_XMM10_Da;
  float unaff_XMM12_Da;
  float unaff_XMM13_Da;
  float unaff_XMM14_Da;
  float unaff_XMM15_Da;
  float fStack0000000000000040;
  float fStack0000000000000044;
  float fStack0000000000000048;
  float fStack0000000000000050;
  undefined4 uStack0000000000000054;
  float fStack0000000000000058;
  
  fVar1 = _DAT_14382e110;
  param_3 = unaff_XMM9_Da / param_3;
  fVar4 = unaff_XMM8_Da * param_3;
  fVar3 = unaff_XMM10_Da * param_3;
  param_3 = unaff_XMM12_Da * param_3;
  fVar5 = unaff_XMM9_Da / SQRT(fVar3 * fVar3 + param_3 * param_3 + fVar4 * fVar4);
  fVar2 = unaff_XMM10_Da * unaff_XMM10_Da + unaff_XMM12_Da * unaff_XMM12_Da +
          unaff_XMM8_Da * unaff_XMM8_Da;
  fVar4 = ((fVar5 * param_3 * *unaff_RBX + fVar5 * fVar3 * unaff_RBX[1] +
           fVar5 * fVar4 * unaff_RBX[2]) - unaff_XMM15_Da) * unaff_XMM14_Da + unaff_XMM15_Da;
  fVar3 = fVar4 / SQRT(fVar2);
  if (_DAT_14382e110 <= fVar2) {
    fVar2 = unaff_XMM10_Da * fVar3;
    fVar4 = unaff_XMM12_Da * fVar3;
    fVar3 = unaff_XMM8_Da * fVar3;
  }
  else {
    fVar2 = 0.0;
    fVar3 = 0.0;
  }
  fStack0000000000000040 = fVar4;
  fStack0000000000000048 = fVar3;
  if (((*(int *)(unaff_RSI + 0x574) == 0) && (unaff_XMM7_Da < fVar2)) && (unaff_R14B != '\0')) {
    uStack0000000000000054 = 0;
    fStack0000000000000044 = fVar2;
    fStack0000000000000050 = fVar4;
    fStack0000000000000058 = fVar3;
    fStack0000000000000040 = (float)FUN_1402c2450(&stack0x00000050);
    if (unaff_XMM13_Da <= fStack0000000000000040) {
      fStack0000000000000040 = unaff_XMM13_Da;
    }
    fVar5 = fVar3 * fVar3 + fVar4 * fVar4;
    fStack0000000000000048 = unaff_XMM7_Da;
    if (fVar1 <= fVar5) {
      fStack0000000000000040 = fStack0000000000000040 / SQRT(fVar5);
      fStack0000000000000048 = fStack0000000000000040 * fVar3;
      fStack0000000000000040 = fStack0000000000000040 * fVar4;
    }
  }
  *unaff_RDI = CONCAT44(fVar2,fStack0000000000000040);
  *(float *)(unaff_RDI + 1) = fStack0000000000000048;
  return;
}


/* SwingRegion_140abce28 @ 0x140abce28 */

void SwingRegion_140abce28(void)

{
  longlong unaff_RSI;
  ulonglong *unaff_RDI;
  char unaff_R14B;
  float fVar1;
  float unaff_XMM6_Da;
  float unaff_XMM7_Da;
  float unaff_XMM9_Da;
  float unaff_XMM13_Da;
  float fStack0000000000000040;
  undefined4 uStack0000000000000044;
  float fStack0000000000000048;
  undefined4 uStack0000000000000054;
  undefined4 uStack0000000000000058;
  
  fStack0000000000000048 = 0.0;
  uStack0000000000000044 = 0;
  fStack0000000000000040 = unaff_XMM6_Da;
  if (((*(int *)(unaff_RSI + 0x574) == 0) && (unaff_XMM7_Da < 0.0)) && (unaff_R14B != '\0')) {
    uStack0000000000000058 = 0;
    uStack0000000000000054 = 0;
    fStack0000000000000040 = (float)FUN_1402c2450(&stack0x00000050);
    if (unaff_XMM13_Da <= fStack0000000000000040) {
      fStack0000000000000040 = unaff_XMM13_Da;
    }
    fVar1 = unaff_XMM6_Da * unaff_XMM6_Da + 0.0;
    fStack0000000000000048 = unaff_XMM7_Da;
    if (unaff_XMM9_Da <= fVar1) {
      fStack0000000000000040 = fStack0000000000000040 / SQRT(fVar1);
      fStack0000000000000048 = fStack0000000000000040 * 0.0;
      fStack0000000000000040 = fStack0000000000000040 * unaff_XMM6_Da;
    }
  }
  *unaff_RDI = (ulonglong)(uint)fStack0000000000000040;
  *(float *)(unaff_RDI + 1) = fStack0000000000000048;
  return;
}


/* SwingRegion_140abce6a @ 0x140abce6a */

void SwingRegion_140abce6a(void)

{
  undefined8 *unaff_RDI;
  char unaff_R14B;
  float fVar1;
  float unaff_XMM6_Da;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM10_Da;
  float unaff_XMM13_Da;
  float fStack0000000000000040;
  float fStack0000000000000044;
  float in_stack_00000048;
  undefined4 uStack0000000000000054;
  
  if ((unaff_XMM7_Da < unaff_XMM10_Da) && (unaff_R14B != '\0')) {
    uStack0000000000000054 = 0;
    fStack0000000000000040 = (float)FUN_1402c2450(&stack0x00000050);
    if (unaff_XMM13_Da <= fStack0000000000000040) {
      fStack0000000000000040 = unaff_XMM13_Da;
    }
    fVar1 = unaff_XMM8_Da * unaff_XMM8_Da + unaff_XMM6_Da * unaff_XMM6_Da;
    fStack0000000000000044 = unaff_XMM10_Da;
    in_stack_00000048 = unaff_XMM7_Da;
    if (unaff_XMM9_Da <= fVar1) {
      fStack0000000000000040 = fStack0000000000000040 / SQRT(fVar1);
      in_stack_00000048 = fStack0000000000000040 * unaff_XMM8_Da;
      fStack0000000000000040 = fStack0000000000000040 * unaff_XMM6_Da;
    }
  }
  *unaff_RDI = CONCAT44(fStack0000000000000044,fStack0000000000000040);
  *(float *)(unaff_RDI + 1) = in_stack_00000048;
  return;
}


/* SwingRegion_140abcf04 @ 0x140abcf04 */

void SwingRegion_140abcf04(undefined8 param_1)

{
  undefined4 in_EAX;
  undefined8 *unaff_RDI;
  
  *unaff_RDI = param_1;
  *(undefined4 *)(unaff_RDI + 1) = in_EAX;
  return;
}


/* SwingRegion_140abcf40 @ 0x140abcf40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140abcf40(longlong param_1,float param_2)

{
  undefined8 *puVar1;
  float *pfVar2;
  bool bVar3;
  undefined8 uVar4;
  uint uVar5;
  char cVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined4 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  float afStack_e0 [2];
  float fStack_d8;
  float fStack_d4;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  undefined1 auStack_b8 [16];
  undefined1 auStack_a8 [144];
  
  lVar11 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar11 + 0x88) == 0) {
    uVar7 = FUN_14167ab40(lVar11 + 0x58,0x146dd6340);
  }
  else {
    uVar7 = func_0x0001416799a0(lVar11 + 0x80);
  }
  lVar8 = func_0x000140923770(uVar7);
  lVar11 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar11 + 0x88) == 0) {
    plVar9 = (longlong *)FUN_14167ab40(lVar11 + 0x58,0x146dd6030);
  }
  else {
    plVar9 = (longlong *)func_0x0001416799a0(lVar11 + 0x80);
  }
  puVar10 = (undefined8 *)(**(code **)(*plVar9 + 0x80))(plVar9,auStack_a8);
  puVar1 = (undefined8 *)(param_1 + 0x3d8);
  uVar7 = puVar10[1];
  *puVar1 = *puVar10;
  *(undefined8 *)(param_1 + 0x3e0) = uVar7;
  uVar7 = puVar10[3];
  *(undefined8 *)(param_1 + 1000) = puVar10[2];
  *(undefined8 *)(param_1 + 0x3f0) = uVar7;
  uVar7 = puVar10[5];
  *(undefined8 *)(param_1 + 0x3f8) = puVar10[4];
  *(undefined8 *)(param_1 + 0x400) = uVar7;
  uVar7 = puVar10[7];
  *(undefined8 *)(param_1 + 0x408) = puVar10[6];
  *(undefined8 *)(param_1 + 0x410) = uVar7;
  puVar10 = (undefined8 *)**(undefined8 **)(param_1 + 8);
  puVar12 = (undefined8 *)&DAT_147afdf10;
  if (puVar10 != (undefined8 *)0x0) {
    puVar12 = puVar10;
  }
  uVar7 = puVar12[1];
  *(undefined8 *)(param_1 + 0x398) = *puVar12;
  *(undefined8 *)(param_1 + 0x3a0) = uVar7;
  uVar7 = puVar12[3];
  *(undefined8 *)(param_1 + 0x3a8) = puVar12[2];
  *(undefined8 *)(param_1 + 0x3b0) = uVar7;
  uVar7 = puVar12[5];
  *(undefined8 *)(param_1 + 0x3b8) = puVar12[4];
  *(undefined8 *)(param_1 + 0x3c0) = uVar7;
  uVar7 = puVar12[6];
  uVar4 = puVar12[7];
  *(undefined4 *)(param_1 + 0x424) = 0;
  *(undefined8 *)(param_1 + 0x3c8) = uVar7;
  *(undefined8 *)(param_1 + 0x3d0) = uVar4;
  puVar10 = (undefined8 *)
            FUN_140b7e920(&fStack_118,*(undefined8 **)(param_1 + 8),param_1 + 0x424,param_1 + 0x428,
                          1,_DAT_14384e2fc,_DAT_145d9a5d0,0,0x4453c00,0x73420c96,0,1,0);
  fVar15 = _DAT_14382ee88;
  uVar5 = _DAT_14382e160;
  fVar18 = _DAT_14382dce0;
  pfVar2 = (float *)(param_1 + 0x418);
  *(undefined8 *)pfVar2 = *puVar10;
  *(undefined4 *)(param_1 + 0x420) = *(undefined4 *)(puVar10 + 1);
  if (*(char *)(param_1 + 0x5fa) != '\0') {
    fStack_110 = *(float *)(param_1 + 0x400);
    fStack_118 = *(float *)(param_1 + 0x3f8);
    fVar14 = (float)((uint)fStack_110 & uVar5);
    fStack_114 = 0.0;
    if (fVar14 <= 0.0) {
      fVar14 = 0.0;
    }
    if (fVar14 <= (float)((uint)fStack_118 & uVar5)) {
      fVar14 = (float)((uint)fStack_118 & uVar5);
    }
    if (0.0 < fVar14) {
      fStack_110 = (fVar18 / fVar14) * fStack_110;
      fStack_118 = (fVar18 / fVar14) * fStack_118;
      fVar14 = fVar18 / SQRT(fStack_110 * fStack_110 + fStack_118 * fStack_118);
      fStack_110 = fVar14 * fStack_110;
      fStack_118 = fVar14 * fStack_118;
    }
    FUN_141c511e0(auStack_a8,&fStack_118,param_1 + 1000);
    if ((*(float *)(param_1 + 0x424) <= fVar15 && fVar15 != *(float *)(param_1 + 0x424)) ||
       (_DAT_14382e128 <
        fStack_114 * *(float *)(param_1 + 0x41c) + fStack_118 * *pfVar2 +
        fStack_110 * *(float *)(param_1 + 0x420))) {
      *(undefined1 *)(param_1 + 0x5fa) = 0;
    }
    else {
      puVar10 = (undefined8 *)FUN_140b85760(auStack_b8,pfVar2,puVar1,_DAT_143840ed0);
      *(undefined8 *)pfVar2 = *puVar10;
      *(undefined4 *)(param_1 + 0x420) = *(undefined4 *)(puVar10 + 1);
      uStack_108 = *(undefined4 *)puVar1;
      uStack_104 = *(undefined4 *)(param_1 + 0x3dc);
      uStack_100 = *(undefined4 *)(param_1 + 0x3e0);
      uStack_f8 = *(undefined4 *)(param_1 + 0x3ec);
      uStack_fc = *(undefined4 *)(param_1 + 1000);
      uStack_f0 = *(undefined4 *)(param_1 + 0x3f8);
      uStack_f4 = *(undefined4 *)(param_1 + 0x3f0);
      uStack_e8 = *(undefined4 *)(param_1 + 0x400);
      uStack_ec = *(undefined4 *)(param_1 + 0x3fc);
      FUN_1402e7060(afStack_e0,&uStack_108);
      uVar13 = FUN_141c58560(afStack_e0[0] * *pfVar2 + fStack_d4 * *(float *)(param_1 + 0x41c) +
                             fStack_c8 * *(float *)(param_1 + 0x420),
                             fStack_d8 * *pfVar2 + fStack_cc * *(float *)(param_1 + 0x41c) +
                             fStack_c0 * *(float *)(param_1 + 0x420));
      *(undefined4 *)(param_1 + 0x428) = uVar13;
      *(undefined4 *)(param_1 + 0x560) = uVar13;
    }
  }
  if (*(float *)(param_1 + 0x424) <= fVar15 && fVar15 != *(float *)(param_1 + 0x424)) {
    fStack_110 = *(float *)(param_1 + 0x400);
    fStack_118 = *(float *)(param_1 + 0x3f8);
    fVar15 = (float)((uint)fStack_110 & uVar5);
    fStack_114 = 0.0;
    if (fVar15 <= 0.0) {
      fVar15 = 0.0;
    }
    if (fVar15 <= (float)((uint)fStack_118 & uVar5)) {
      fVar15 = (float)((uint)fStack_118 & uVar5);
    }
    if (0.0 < fVar15) {
      fStack_110 = (fVar18 / fVar15) * fStack_110;
      fStack_118 = (fVar18 / fVar15) * fStack_118;
      fVar15 = fVar18 / SQRT(fStack_110 * fStack_110 + fStack_118 * fStack_118);
      fStack_110 = fVar15 * fStack_110;
      fStack_118 = fVar15 * fStack_118;
    }
    *(ulonglong *)pfVar2 = (ulonglong)(uint)fStack_118;
    *(float *)(param_1 + 0x420) = fStack_110;
  }
  cVar6 = FUN_140b8a190(*(undefined8 *)(param_1 + 8),pfVar2);
  if (cVar6 != '\0') {
    FUN_140b8a910(*(undefined8 *)(param_1 + 8),pfVar2,_DAT_1438a96e4,1);
  }
  fVar15 = *(float *)(param_1 + 0x4c0);
  fVar14 = *(float *)(param_1 + 0x4b8);
  fVar16 = (float)((uint)fVar15 & uVar5);
  if (fVar16 <= 0.0) {
    fVar16 = 0.0;
  }
  if (fVar16 <= (float)((uint)fVar14 & uVar5)) {
    fVar16 = (float)((uint)fVar14 & uVar5);
  }
  if (0.0 < fVar16) {
    fVar15 = (fVar18 / fVar16) * fVar15;
    fVar14 = (fVar18 / fVar16) * fVar14;
    fVar16 = fVar18 / SQRT(fVar15 * fVar15 + fVar14 * fVar14);
    fVar15 = fVar16 * fVar15;
    fVar14 = fVar16 * fVar14;
  }
  fVar16 = *(float *)(param_1 + 0x424);
  fVar15 = fVar15 * *(float *)(param_1 + 0x420) + fVar14 * *pfVar2;
  if (_DAT_143840108 <= fVar15) {
    fVar14 = *(float *)(lVar8 + 0x1fc);
    if (fVar16 <= fVar14) {
      fVar17 = *(float *)(lVar8 + 0x1f8);
      if ((float)((uint)(fVar14 - fVar17) & uVar5) <= _DAT_14382e118) {
        if (fVar17 <= fVar16) {
          fVar14 = fVar18;
          if (fVar16 <= fVar17) {
            fVar14 = _DAT_14382e128;
          }
        }
        else {
          fVar14 = 0.0;
        }
      }
      else {
        fVar14 = (fVar16 - fVar17) / (fVar14 - fVar17);
        if (fVar14 <= 0.0) {
          fVar14 = 0.0;
        }
        if (fVar18 <= fVar14) {
          fVar14 = fVar18;
        }
      }
      fVar14 = fVar14 * *(float *)(lVar8 + 0x204);
    }
    else {
      fVar19 = *(float *)(lVar8 + 0x200) - fVar14;
      fVar17 = fVar18;
      if (_DAT_14382e118 < (float)((uint)fVar19 & uVar5)) {
        fVar17 = (fVar16 - fVar14) / fVar19;
        if (fVar17 <= 0.0) {
          fVar17 = 0.0;
        }
        if (fVar18 <= fVar17) {
          fVar17 = fVar18;
        }
      }
      fVar14 = (fVar18 - *(float *)(lVar8 + 0x204)) * fVar17 + *(float *)(lVar8 + 0x204);
    }
    fVar16 = *(float *)(param_1 + 0x42c);
    if (fVar14 < fVar16) {
      fVar18 = *(float *)(param_1 + 0x434) - param_2;
      if (fVar18 <= 0.0) {
        fVar18 = 0.0;
      }
      bVar3 = fVar18 < _DAT_14382e118;
      *(float *)(param_1 + 0x434) = fVar18;
      if (bVar3) {
        fVar16 = (float)func_0x000141c477e0(fVar16,fVar14,_DAT_14382f0dc,param_2);
        *(float *)(param_1 + 0x42c) = fVar16;
      }
    }
    else {
      *(float *)(param_1 + 0x42c) = fVar14;
      *(undefined4 *)(param_1 + 0x434) = 0x3e4ccccd;
      fVar16 = fVar14;
    }
    if (fVar15 <= 0.0) {
      fVar15 = 0.0;
    }
    fVar16 = (fVar15 * _DAT_14382e124 + _DAT_14382f760) * fVar16;
  }
  else {
    fVar16 = (float)((uint)fVar16 ^ _DAT_14382e890);
    *(float *)(param_1 + 0x42c) = fVar16;
  }
  *(float *)(param_1 + 0x430) = fVar16;
  lVar11 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar11 + 0x88) == 0) {
    lVar11 = FUN_14167ab40(lVar11 + 0x58,0x146dacd70);
  }
  else {
    lVar11 = func_0x0001416799a0(lVar11 + 0x80);
  }
  *(longlong *)(param_1 + 0x378) = lVar11 + 0x478;
  *(longlong *)(param_1 + 0x380) = lVar11 + 0x410;
  *(longlong *)(param_1 + 0x388) = lVar11 + 0x4b8;
  *(longlong *)(param_1 + 0x390) = lVar11 + 0x5c0;
  return;
}


/* SwingRegion_140abd610 @ 0x140abd610 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140abd610(longlong param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float afStack_68 [24];
  
  fVar1 = _DAT_14382dce0;
  fVar5 = *(float *)(param_1 + 0x440) - *(float *)(param_1 + 0x3d0);
  fVar4 = *(float *)(param_1 + 0x438) - *(float *)(param_1 + 0x3c8);
  fVar6 = (float)((uint)fVar5 & _DAT_14382e160);
  fVar2 = (float)((uint)fVar4 & _DAT_14382e160);
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  fVar7 = 0.0;
  if (fVar6 <= fVar2) {
    fVar6 = fVar2;
  }
  fVar5 = (_DAT_14382dce0 / fVar6) * fVar5;
  fVar4 = (_DAT_14382dce0 / fVar6) * fVar4;
  if (0.0 < fVar6) {
    fVar7 = SQRT(fVar5 * fVar5 + fVar4 * fVar4) * fVar6;
  }
  afStack_68[2] = *(float *)(param_1 + 0x4c0);
  afStack_68[0] = *(float *)(param_1 + 0x4b8);
  fVar6 = (float)((uint)afStack_68[2] & _DAT_14382e160);
  afStack_68[1] = 0.0;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  if (fVar6 <= (float)((uint)afStack_68[0] & _DAT_14382e160)) {
    fVar6 = (float)((uint)afStack_68[0] & _DAT_14382e160);
  }
  if (0.0 < fVar6) {
    afStack_68[2] = (_DAT_14382dce0 / fVar6) * afStack_68[2];
    afStack_68[0] = (_DAT_14382dce0 / fVar6) * afStack_68[0];
    fVar6 = _DAT_14382dce0 / SQRT(afStack_68[2] * afStack_68[2] + afStack_68[0] * afStack_68[0]);
    afStack_68[2] = fVar6 * afStack_68[2];
    afStack_68[0] = fVar6 * afStack_68[0];
  }
  fVar6 = (float)func_0x000141c59090(param_1 + 0x418,afStack_68);
  fVar2 = (fVar7 - _DAT_143830120) * _DAT_1438398cc;
  fVar6 = fVar6 * _DAT_1438ac3cc - _DAT_1438cea40;
  if (fVar2 <= 0.0) {
    fVar2 = 0.0;
  }
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  if (fVar1 <= fVar2) {
    fVar2 = fVar1;
  }
  if (fVar1 <= fVar6) {
    fVar6 = fVar1;
  }
  uVar3 = FUN_140876340(param_1 + 0x4d0);
  fVar5 = (float)(uVar3 ^ _DAT_14382e890) * _DAT_1438bfc14;
  *(undefined4 *)(param_1 + 0x514) = 0x3e4ccccd;
  fVar5 = fVar5 - _DAT_1438374ac;
  if (fVar5 <= 0.0) {
    fVar5 = 0.0;
  }
  if (fVar1 <= fVar5) {
    fVar5 = fVar1;
  }
  *(float *)(param_1 + 0x510) =
       fVar1 - fVar5 * fVar6 * ((fVar1 - fVar2) * _DAT_14383df0c + _DAT_14383fd4c);
  return;
}


/* SwingRegion_140abd820 @ 0x140abd820 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140abd820(longlong param_1,undefined8 *param_2,float param_3,undefined4 *param_4,
             undefined1 *param_5)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  float fVar6;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined8 uStack_d8;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined2 uStack_c0;
  undefined1 uStack_be;
  undefined1 uStack_b8;
  undefined8 uStack_b4;
  undefined8 uStack_ac;
  undefined8 uStack_a4;
  undefined4 uStack_9c;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined4 uStack_88;
  undefined8 uStack_84;
  undefined4 uStack_7c;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined4 uStack_60;
  undefined8 uStack_5c;
  undefined8 uStack_54;
  undefined8 uStack_4c;
  undefined4 uStack_44;
  undefined1 auStack_38 [32];
  
  lVar4 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    lVar4 = FUN_14167ab40(lVar4 + 0x58,0x1473d09e0);
  }
  else {
    lVar4 = func_0x0001416799a0(lVar4 + 0x80);
  }
  uStack_e8 = *param_4;
  uStack_e0 = param_4[2];
  uStack_e4 = 0;
  FUN_1402d0740(param_2,&uStack_e8);
  *param_5 = 0;
  cVar1 = *(char *)(param_1 + 0x580);
  if (cVar1 == '\0') {
    fVar6 = (float)func_0x0001403e3f30(param_4);
    if (fVar6 < param_3) {
      uStack_e8 = *(undefined4 *)(param_1 + 0x3b8);
      uStack_e0 = *(undefined4 *)(param_1 + 0x3c0);
      uStack_e4 = 0;
      puVar5 = (undefined8 *)FUN_1402d0740(auStack_38,&uStack_e8);
      *param_2 = *puVar5;
      *(undefined4 *)(param_2 + 1) = *(undefined4 *)(puVar5 + 1);
    }
    fVar6 = (float)FUN_141c46be0(*(undefined4 *)(param_1 + 0x508),
                                 *(float *)(param_1 + 0x54c) * _DAT_14382ee8c,param_1 + 0x504,
                                 _DAT_14382e13c,_DAT_1438ad58c,_DAT_14383d264,param_3);
    uStack_e4 = _DAT_14382dce0;
    uStack_e8 = 0;
    *(float *)(param_1 + 0x508) = fVar6;
    uStack_e0 = 0;
    FUN_141c54e30(&uStack_d8,&uStack_e8,fVar6 * _DAT_14382e11c);
    puVar5 = (undefined8 *)FUN_141c5b320(auStack_38,param_2,&uStack_d8);
    *param_2 = *puVar5;
    uVar3 = *(undefined4 *)(puVar5 + 1);
  }
  else {
    if (cVar1 == '\x01') {
      uStack_d0 = *(undefined4 *)(param_2 + 1);
      uStack_cc = _DAT_14386d520;
      uStack_d8 = *param_2;
      uStack_c4 = _DAT_14382e9ec;
      uStack_c8 = 0;
      uStack_c0 = 0x100;
      uStack_be = 1;
      uVar2 = FUN_1415bd1d0(lVar4,param_2,&uStack_d8);
      *param_5 = uVar2;
      return param_2;
    }
    if (cVar1 == '\x02') {
      uStack_b4 = *(undefined8 *)(lVar4 + 0x714);
      uStack_ac = *(undefined8 *)(lVar4 + 0x71c);
      uStack_b8 = *(undefined1 *)(lVar4 + 0x710);
      uStack_84 = *(undefined8 *)(lVar4 + 0x744);
      uStack_a4 = *(undefined8 *)(lVar4 + 0x724);
      uStack_9c = *(undefined4 *)(lVar4 + 0x72c);
      uStack_98 = *(undefined8 *)(lVar4 + 0x730);
      uStack_90 = *(undefined8 *)(lVar4 + 0x738);
      uStack_7c = *(undefined4 *)(lVar4 + 0x74c);
      uStack_88 = *(undefined4 *)(lVar4 + 0x740);
      uStack_78 = *(undefined8 *)(lVar4 + 0x750);
      uStack_70 = *(undefined8 *)(lVar4 + 0x758);
      uStack_60 = *(undefined4 *)(lVar4 + 0x768);
      uStack_68 = *(undefined8 *)(lVar4 + 0x760);
      uStack_5c = *(undefined8 *)(lVar4 + 0x76c);
      uStack_54 = *(undefined8 *)(lVar4 + 0x774);
      uStack_44 = *(undefined4 *)(lVar4 + 0x784);
      uStack_4c = *(undefined8 *)(lVar4 + 0x77c);
      puVar5 = (undefined8 *)FUN_141c5b320(&uStack_e8,param_1 + 0x3b8,&uStack_b4);
      *param_2 = *puVar5;
      *(undefined4 *)(param_2 + 1) = *(undefined4 *)(puVar5 + 1);
      *param_5 = 1;
      return param_2;
    }
    if (cVar1 != '\x03') {
      return param_2;
    }
    *param_2 = *(undefined8 *)(param_1 + 0x3b8);
    uVar3 = *(undefined4 *)(param_1 + 0x3c0);
  }
  *(undefined4 *)(param_2 + 1) = uVar3;
  return param_2;
}


/* SwingRegion_140abdb30 @ 0x140abdb30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_140abdb30(longlong param_1,float *param_2,float param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  undefined1 auVar4 [16];
  char cVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  float *pfVar10;
  uint *puVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar18;
  uint uVar19;
  undefined4 uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  uint uVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  undefined8 in_stack_fffffffffffffd88;
  undefined8 uVar33;
  float *pfVar34;
  undefined8 uVar35;
  undefined4 uVar36;
  uint in_stack_fffffffffffffd98;
  undefined8 uStack_258;
  float fStack_250;
  undefined8 uStack_248;
  float fStack_240;
  undefined8 uStack_238;
  float fStack_230;
  float fStack_228;
  float fStack_224;
  float fStack_220;
  undefined8 uStack_218;
  float fStack_210;
  float fStack_208;
  float fStack_204;
  undefined8 uStack_200;
  float fStack_1f8;
  float fStack_1f0;
  float fStack_1ec;
  float fStack_1e8;
  uint uStack_1e0;
  float fStack_1dc;
  float fStack_1d8;
  float fStack_1d4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b4;
  undefined8 uStack_1b0;
  float fStack_1a8;
  float afStack_1a0 [4];
  float fStack_190;
  float fStack_18c;
  undefined8 uStack_188;
  float fStack_180;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_168;
  uint uStack_164;
  uint uStack_160;
  uint uStack_15c;
  uint uStack_158;
  uint uStack_154;
  undefined8 uStack_150;
  undefined4 uStack_148;
  undefined8 uStack_140;
  float fStack_138;
  undefined1 auStack_134 [12];
  undefined1 auStack_128 [16];
  undefined1 auStack_118 [12];
  undefined1 auStack_10c [12];
  undefined1 auStack_100 [12];
  undefined1 auStack_f4 [180];
  
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffd88 >> 0x20);
  pfVar10 = (float *)(param_1 + 0x4b8);
  *(undefined8 *)(param_1 + 0x4c4) = *(undefined8 *)pfVar10;
  *(undefined4 *)(param_1 + 0x4cc) = *(undefined4 *)(param_1 + 0x4c0);
  puVar7 = (undefined8 *)FUN_140abb420((int)*(undefined8 *)pfVar10,&uStack_188,pfVar10,param_3);
  puVar8 = (undefined8 *)(param_1 + 0x4e8);
  *(undefined8 *)pfVar10 = *puVar7;
  *(undefined4 *)(param_1 + 0x4c0) = *(undefined4 *)(puVar7 + 1);
  puVar7 = (undefined8 *)FUN_140abc5d0(param_1,&uStack_188,pfVar10,puVar8,CONCAT44(uVar20,param_3));
  pfVar1 = (float *)(param_1 + 0x3c8);
  *(undefined8 *)pfVar10 = *puVar7;
  *(undefined4 *)(param_1 + 0x4c0) = *(undefined4 *)(puVar7 + 1);
  *puVar8 = *(undefined8 *)(param_1 + 0x4d0);
  *(undefined4 *)(param_1 + 0x4f0) = *(undefined4 *)(param_1 + 0x4d8);
  FUN_140ac04f0(param_1,&fStack_178,pfVar10,pfVar1,*(int *)(param_1 + 0x574) == 0,puVar8);
  uVar19 = _DAT_14382e160;
  fVar26 = _DAT_14382e110;
  fVar3 = _DAT_14382dce0;
  fVar13 = (float)((uint)fStack_170 & _DAT_14382e160);
  if ((float)((uint)fStack_170 & _DAT_14382e160) <= (float)((uint)fStack_174 & _DAT_14382e160)) {
    fVar13 = (float)((uint)fStack_174 & _DAT_14382e160);
  }
  if (fVar13 <= (float)((uint)fStack_178 & _DAT_14382e160)) {
    fVar13 = (float)((uint)fStack_178 & _DAT_14382e160);
  }
  if (fVar13 <= 0.0) {
    uStack_238 = CONCAT44(fStack_174,fStack_178);
    fStack_230 = fStack_170;
  }
  else {
    fVar13 = _DAT_14382dce0 / fVar13;
    fStack_170 = fStack_170 * fVar13;
    fStack_174 = fStack_174 * fVar13;
    fStack_178 = fStack_178 * fVar13;
    fVar13 = _DAT_14382dce0 /
             SQRT(fStack_174 * fStack_174 + fStack_178 * fStack_178 + fStack_170 * fStack_170);
    fStack_230 = fVar13 * fStack_170;
    uStack_238 = CONCAT44(fVar13 * fStack_174,fVar13 * fStack_178);
  }
  *(undefined8 *)(param_1 + 0x4d0) = uStack_238;
  *(float *)(param_1 + 0x4d8) = fStack_230;
  uVar29 = _DAT_14382e890;
  fVar13 = *(float *)(param_1 + 0x4d4);
  fVar14 = *(float *)(param_1 + 0x4d0);
  fVar15 = *(float *)(param_1 + 0x4d8);
  fVar24 = fVar14 * fVar14 + fVar13 * fVar13 + fVar15 * fVar15;
  if ((float)((uint)fVar24 & uVar19) <= fVar26) {
    fVar24 = 0.0;
  }
  else {
    fVar24 = (fVar13 * *(float *)(param_1 + 0x4bc) + fVar14 * *pfVar10 +
             fVar15 * *(float *)(param_1 + 0x4c0)) / fVar24;
  }
  fVar27 = fVar14 * fVar24;
  fVar32 = fVar15 * fVar24;
  fVar24 = fVar13 * fVar24;
  fStack_1f0 = fVar27;
  fStack_1ec = fVar24;
  fStack_1e8 = fVar32;
  if (fVar24 * fVar13 + fVar27 * fVar14 + fVar32 * fVar15 < 0.0) {
    fStack_1f0 = (float)((uint)fVar27 ^ _DAT_14382e890);
    fStack_1ec = (float)((uint)fVar24 ^ _DAT_14382e890);
    fStack_1e8 = (float)((uint)fVar32 ^ _DAT_14382e890);
  }
  pfVar2 = (float *)(param_1 + 0x438);
  *(ulonglong *)(param_1 + 0x4dc) = CONCAT44(fStack_1ec,fStack_1f0);
  *(float *)(param_1 + 0x4e4) = fStack_1e8;
  fStack_1dc = fVar24;
  fStack_1d8 = fVar27;
  fStack_1d0 = fVar27;
  fStack_1cc = fVar24;
  fStack_1c8 = fVar32;
  fStack_18c = fVar32;
  cVar5 = FUN_1408478f0(pfVar2,&uStack_150,1,*(undefined8 *)(param_1 + 8));
  if (cVar5 != '\0') {
    *(undefined8 *)(param_1 + 0x480) = uStack_150;
    *(undefined4 *)(param_1 + 0x488) = uStack_148;
    *(undefined1 *)(param_1 + 0x48c) = 1;
  }
  fVar14 = (float)FUN_140b8a4f0(pfVar2);
  fVar13 = fStack_1c8;
  if (fVar14 != _DAT_143830778) {
    if ((*(char *)(param_1 + 0x5f8) != '\0') ||
       (*(float *)(param_1 + 0x3cc) + _DAT_143830120 < fVar14)) {
      *(undefined1 *)(param_1 + 0x5f8) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x5f8) = 0;
      if ((*(char *)(param_1 + 0x48c) == '\0') ||
         (*(float *)(param_1 + 0x484) <= fVar14 && fVar14 != *(float *)(param_1 + 0x484))) {
        *(undefined8 *)(param_1 + 0x480) = *(undefined8 *)pfVar1;
        fVar15 = *(float *)(param_1 + 0x448) - _DAT_14383d264;
        *(undefined4 *)(param_1 + 0x488) = *(undefined4 *)(param_1 + 0x3d0);
        *(undefined1 *)(param_1 + 0x48c) = 1;
        if (fVar14 <= fVar15) {
          fVar15 = fVar14;
        }
        *(float *)(param_1 + 0x484) = fVar15;
      }
    }
  }
  uStack_248 = *(undefined8 *)pfVar1;
  uVar12 = 0;
  fStack_240 = *(float *)(param_1 + 0x3d0);
  fVar15 = param_3 * _DAT_14382e124;
  fStack_250 = *(float *)(param_1 + 0x4c0);
  uStack_258 = *(undefined8 *)pfVar10;
  fStack_210 = *(float *)(param_1 + 0x4e4);
  afStack_1a0[1] = 0.0;
  fVar14 = _DAT_1438cea3c;
  uStack_218 = *(undefined8 *)(param_1 + 0x4dc);
  do {
    fVar16 = (float)FUN_1420dc660(param_1);
    pfVar10 = &fStack_1c0;
    fVar16 = ((fVar16 + (float)uVar12 * fVar15) - _DAT_143848d00) * _DAT_1438cea48;
    if (fVar16 <= 0.0) {
      fVar16 = 0.0;
    }
    if (fVar3 <= fVar16) {
      fVar16 = fVar3;
    }
    fStack_190 = fVar14 - fVar16 * fVar14;
    FUN_140ab4450(param_1 + 0x444,pfVar1,&uStack_218,auStack_128,&uStack_1e0,pfVar10,
                  in_stack_fffffffffffffd98 & 0xffffff00);
    uVar20 = (undefined4)((ulonglong)pfVar10 >> 0x20);
    if (*(char *)(param_1 + 0x464) != '\0') {
      if (*(int *)(param_1 + 0x574) == 0) {
        fVar24 = (float)((uint)fStack_250 & uVar19);
        fVar14 = (float)((uint)uStack_258._4_4_ & uVar19);
        if ((float)((uint)uStack_258._4_4_ & uVar19) <= fVar24) {
          fVar14 = fVar24;
        }
        fVar27 = (float)((uint)(float)uStack_258 & uVar19);
        if (fVar14 <= fVar27) {
          fVar14 = fVar27;
        }
        fVar16 = fVar3 / fVar14;
        if (fVar14 <= 0.0) {
          fVar14 = 0.0;
        }
        else {
          fVar14 = SQRT(uStack_258._4_4_ * fVar16 * uStack_258._4_4_ * fVar16 +
                        (float)uStack_258 * fVar16 * (float)uStack_258 * fVar16 +
                        fStack_250 * fVar16 * fStack_250 * fVar16) * fVar14;
        }
        if (0.0 < uStack_258._4_4_) {
          if (fVar24 <= fVar27) {
            fVar24 = fVar27;
          }
          fVar27 = (float)uStack_258 * (fVar3 / fVar24);
          fVar14 = fStack_250 * (fVar3 / fVar24);
          if (fVar24 <= 0.0) {
            fVar14 = 0.0;
          }
          else {
            fVar14 = SQRT(fVar14 * fVar14 + fVar27 * fVar27) * fVar24;
          }
        }
        if (((*(float *)(param_1 + 0x454) <= fVar14 && fVar14 != *(float *)(param_1 + 0x454)) &&
            (uStack_258._4_4_ < 0.0)) || (_DAT_143837a20 < *(float *)(param_1 + 0x57c))) {
          *(undefined1 *)(param_1 + 0x464) = 0;
          fVar27 = fStack_1d8;
          uVar29 = _DAT_14382e890;
          fVar24 = fStack_1dc;
        }
        else {
          fVar24 = (float)func_0x000141c477e0(*(undefined4 *)(param_1 + 0x45c),
                                              *(undefined4 *)(param_1 + 0x458),
                                              *(undefined4 *)(param_1 + 0x460),fVar15);
          fVar14 = *(float *)(param_1 + 0x454) - fVar14;
          *(float *)(param_1 + 0x45c) = fVar24;
          if (fVar14 <= 0.0) {
            fVar14 = 0.0;
          }
          if (fVar24 * fVar15 <= fVar14) {
            fVar14 = fVar24 * fVar15;
          }
          fVar27 = (float)uStack_218 * (float)uStack_218 + uStack_218._4_4_ * uStack_218._4_4_ +
                   fStack_210 * fStack_210;
          fVar24 = fVar14 / SQRT(fVar27);
          if (fVar26 <= fVar27) {
            fVar26 = fStack_210 * fVar24;
            fVar14 = (float)uStack_218 * fVar24;
            fVar24 = uStack_218._4_4_ * fVar24;
          }
          else {
            fVar26 = 0.0;
            fVar24 = 0.0;
          }
          fStack_250 = fStack_250 + fVar26;
          uStack_258._4_4_ = uStack_258._4_4_ + fVar24;
          uStack_258._0_4_ = (float)uStack_258 + fVar14;
          fVar27 = fStack_1d8;
          uVar29 = _DAT_14382e890;
          fVar24 = fStack_1dc;
          fStack_1a8 = fStack_250;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x464) = 0;
      }
    }
    uStack_1b0 = CONCAT44(uStack_258._4_4_,(float)uStack_258);
    puVar8 = (undefined8 *)
             FUN_140abc8c0(param_1,auStack_118,&uStack_258,&uStack_218,pfVar2,
                           CONCAT44(uVar20,uStack_1e0),fVar15);
    uStack_258 = *puVar8;
    fStack_250 = *(float *)(puVar8 + 1);
    FUN_140abb8e0(param_1,&uStack_258,fVar15);
    FUN_140ac04f0(param_1,&uStack_200,&uStack_258,&uStack_248,*(int *)(param_1 + 0x574) == 0,
                  &uStack_218);
    fVar14 = (float)FUN_1420dc660(param_1);
    fVar26 = (float)uStack_200;
    if (fVar14 < _DAT_14382e120) {
      fVar14 = (float)((uint)(float)uStack_200 & uVar19);
      if ((float)((uint)(float)uStack_200 & uVar19) <= (float)((uint)fStack_1f8 & uVar19)) {
        fVar14 = (float)((uint)fStack_1f8 & uVar19);
      }
      fVar25 = (float)uStack_200 * (fVar3 / fVar14);
      fVar16 = fStack_1f8 * (fVar3 / fVar14);
      if ((0.0 < fVar14) && (_DAT_14382f2cc < SQRT(fVar16 * fVar16 + fVar25 * fVar25) * fVar14)) {
        puVar8 = (undefined8 *)
                 FUN_140ac04f0(param_1,auStack_10c,&uStack_258,&uStack_248,
                               *(int *)(param_1 + 0x574) == 0,&uStack_218);
        uStack_200 = *puVar8;
        fStack_1f8 = *(float *)(puVar8 + 1);
        fVar26 = (float)uStack_200;
      }
    }
    fVar14 = (float)((uint)uStack_200._4_4_ & uVar19);
    if ((float)((uint)uStack_200._4_4_ & uVar19) <= (float)((uint)fStack_1f8 & uVar19)) {
      fVar14 = (float)((uint)fStack_1f8 & uVar19);
    }
    if (fVar14 <= (float)((uint)fVar26 & uVar19)) {
      fVar14 = (float)((uint)fVar26 & uVar19);
    }
    fVar16 = uStack_200._4_4_;
    fVar25 = fStack_1f8;
    if (0.0 < fVar14) {
      fVar14 = fVar3 / fVar14;
      fVar16 = uStack_200._4_4_ * fVar14;
      fVar25 = fStack_1f8 * fVar14;
      fVar26 = fVar26 * fVar14;
      fVar14 = fVar3 / SQRT(fVar16 * fVar16 + fVar26 * fVar26 + fVar25 * fVar25);
      fVar26 = fVar26 * fVar14;
      fVar16 = fVar16 * fVar14;
      fVar25 = fVar25 * fVar14;
    }
    if (0.0 <= fVar16 * fVar24 + fVar26 * fVar27 + fVar25 * fVar32) {
      pfVar10 = (float *)&uStack_140;
      uStack_140 = CONCAT44(fStack_1cc,fStack_1d0);
      fStack_138 = fVar13;
    }
    else {
      pfVar10 = &fStack_168;
      fStack_168 = (float)((uint)fVar27 ^ uVar29);
      uStack_164 = (uint)fVar24 ^ uVar29;
      uStack_160 = (uint)fVar32 ^ uVar29;
    }
    uVar33 = *(undefined8 *)pfVar10;
    fStack_1bc = (float)uStack_258 - (float)uVar33;
    fStack_230 = pfVar10[2];
    uStack_238._4_4_ = (float)((ulonglong)uVar33 >> 0x20);
    fStack_1b8 = uStack_258._4_4_ - uStack_238._4_4_;
    fStack_1b4 = fStack_250 - fStack_230;
    fVar26 = (float)((uint)fStack_250 & uVar19);
    if ((float)((uint)fStack_250 & uVar19) <= (float)((uint)uStack_258._4_4_ & uVar19)) {
      fVar26 = (float)((uint)uStack_258._4_4_ & uVar19);
    }
    if (fVar26 <= (float)((uint)(float)uStack_258 & uVar19)) {
      fVar26 = (float)((uint)(float)uStack_258 & uVar19);
    }
    afStack_1a0[0] = fStack_250;
    afStack_1a0[2] = (float)uStack_258;
    if (0.0 < fVar26) {
      fVar26 = fVar3 / fVar26;
      fVar24 = fVar26 * (float)uStack_258;
      fVar14 = fVar26 * fStack_250;
      fVar26 = fVar3 / SQRT(fVar26 * uStack_258._4_4_ * fVar26 * uStack_258._4_4_ + fVar24 * fVar24
                            + fVar14 * fVar14);
      afStack_1a0[0] = fVar14 * fVar26;
      afStack_1a0[2] = fVar24 * fVar26;
    }
    afStack_1a0[2] = (float)((uint)afStack_1a0[2] ^ uVar29);
    fVar26 = (float)((uint)afStack_1a0[2] & uVar19);
    if (fVar26 <= 0.0) {
      fVar26 = 0.0;
    }
    if (fVar26 <= (float)((uint)afStack_1a0[0] & uVar19)) {
      fVar26 = (float)((uint)afStack_1a0[0] & uVar19);
    }
    if (0.0 < fVar26) {
      afStack_1a0[2] = (fVar3 / fVar26) * afStack_1a0[2];
      afStack_1a0[0] = (fVar3 / fVar26) * afStack_1a0[0];
      fVar26 = fVar3 / SQRT(afStack_1a0[2] * afStack_1a0[2] + afStack_1a0[0] * afStack_1a0[0]);
      afStack_1a0[2] = fVar26 * afStack_1a0[2];
      afStack_1a0[0] = fVar26 * afStack_1a0[0];
    }
    pfVar34 = afStack_1a0;
    puVar8 = &uStack_238;
    uStack_238 = uVar33;
    FUN_140abf160(param_1,&fStack_1f0,pfVar2,&uStack_248,puVar8,pfVar34,fVar15);
    fVar24 = fStack_1e8;
    fVar14 = fStack_1ec;
    fVar26 = fStack_1f0;
    fVar32 = fStack_1e8 - fStack_240;
    fVar16 = fStack_1f0 - (float)uStack_248;
    fVar25 = fStack_1ec - uStack_248._4_4_;
    fVar27 = (float)((uint)fVar32 & uVar19);
    if ((float)((uint)fVar32 & uVar19) <= (float)((uint)fVar25 & uVar19)) {
      fVar27 = (float)((uint)fVar25 & uVar19);
    }
    if (fVar27 <= (float)((uint)fVar16 & uVar19)) {
      fVar27 = (float)((uint)fVar16 & uVar19);
    }
    fVar28 = fVar3 / fVar27;
    fVar31 = fVar28 * fVar16;
    fVar30 = fVar28 * fVar25;
    fVar28 = fVar28 * fVar32;
    if (fVar27 <= 0.0) {
      fVar27 = 0.0;
    }
    else {
      fVar27 = SQRT(fVar31 * fVar31 + fVar30 * fVar30 + fVar28 * fVar28) * fVar27;
      fVar32 = fVar3 / SQRT(fVar31 * fVar31 + fVar30 * fVar30 + fVar28 * fVar28);
      fVar16 = fVar31 * fVar32;
      fVar25 = fVar30 * fVar32;
      fVar32 = fVar28 * fVar32;
    }
    uVar35 = CONCAT44((int)((ulonglong)pfVar34 >> 0x20),fVar15);
    uVar33 = CONCAT44((int)((ulonglong)puVar8 >> 0x20),fVar27);
    fVar31 = (float)FUN_140ac0b60(param_1,&uStack_238,fStack_1c0,uStack_1e0,uVar33,uVar35);
    fVar28 = fStack_1c0;
    uVar20 = (undefined4)((ulonglong)uVar33 >> 0x20);
    uVar36 = (undefined4)((ulonglong)uVar35 >> 0x20);
    fVar30 = (float)((uint)uStack_238._4_4_ & uVar19);
    if ((float)((uint)uStack_238._4_4_ & uVar19) <= (float)((uint)fStack_230 & uVar19)) {
      fVar30 = (float)((uint)fStack_230 & uVar19);
    }
    fVar21 = (float)((uint)(float)*(undefined8 *)pfVar10 & uVar19);
    if (fVar30 <= fVar21) {
      fVar30 = fVar21;
    }
    fVar21 = fVar3 / fVar30;
    fVar22 = fVar21 * (float)*(undefined8 *)pfVar10;
    if (fVar30 <= 0.0) {
      fVar30 = 0.0;
    }
    else {
      fVar30 = SQRT(fVar21 * uStack_238._4_4_ * fVar21 * uStack_238._4_4_ + fVar22 * fVar22 +
                    fVar21 * fStack_230 * fVar21 * fStack_230) * fVar30;
    }
    fVar21 = *(float *)(param_1 + 0x510);
    fVar23 = (fVar30 * fVar30) / fVar27;
    fVar22 = fVar23 * fVar25;
    fVar17 = *(float *)(param_1 + 0x514) - fVar15;
    *(float *)(param_1 + 0x514) = fVar17;
    if (fVar17 <= 0.0) {
      fVar21 = fVar15 * _DAT_1438388c0 + fVar21;
      if (fVar3 <= fVar21) {
        fVar21 = fVar3;
      }
      *(float *)(param_1 + 0x510) = fVar21;
    }
    fVar17 = fVar25 * fVar31;
    fStack_204 = (float)((uint)(fVar17 * fVar16 * fVar21) ^ _DAT_14382e890) * fVar15 +
                 fVar23 * fVar16 * fVar15 + *pfVar10;
    fStack_208 = (float)((uint)(fVar17 * fVar32 * fVar21) ^ _DAT_14382e890) * fVar15 +
                 fVar23 * fVar32 * fVar15 + fStack_230;
    fVar32 = fVar22 * fVar21;
    if (fVar22 <= fVar22 * fVar21) {
      fVar32 = fVar22;
    }
    fStack_1d4 = (((fVar31 - fVar17 * fVar25) - fVar31) * fVar21 + fVar31) * fVar15 +
                 fVar32 * fVar15 + uStack_238._4_4_;
    fVar32 = (float)((uint)fStack_1d4 & uVar19);
    if ((float)((uint)fStack_1d4 & uVar19) <= (float)((uint)fStack_208 & uVar19)) {
      fVar32 = (float)((uint)fStack_208 & uVar19);
    }
    if (fVar32 <= (float)((uint)fStack_204 & uVar19)) {
      fVar32 = (float)((uint)fStack_204 & uVar19);
    }
    fVar16 = fVar3 / fVar32;
    if (fVar32 <= 0.0) {
      fVar32 = 0.0;
    }
    else {
      fVar32 = SQRT(fVar16 * fStack_1d4 * fVar16 * fStack_1d4 +
                    fVar16 * fStack_204 * fVar16 * fStack_204 +
                    fVar16 * fStack_208 * fVar16 * fStack_208) * fVar32;
    }
    fVar25 = fStack_1d4 * fVar15 + uStack_248._4_4_;
    fVar16 = fStack_204 * fVar15 + (float)uStack_248;
    fVar31 = fVar14 - fVar25;
    *(float *)(param_1 + 0x46c) = fVar32 - fVar30;
    fVar32 = fStack_208 * fVar15 + fStack_240;
    fVar30 = fVar26 - fVar16;
    fVar21 = fVar24 - fVar32;
    if (0.0 <= fVar31) {
      fVar32 = fVar31 * fVar31 + fVar30 * fVar30 + fVar21 * fVar21;
      fVar16 = fVar27 / SQRT(fVar32);
      if (_DAT_14382e110 <= fVar32) {
        fVar32 = fVar16 * fVar21;
        fVar25 = fVar16 * fVar31;
        fVar16 = fVar16 * fVar30;
      }
      else {
        fVar32 = 0.0;
        fVar25 = 0.0;
        fVar16 = fVar27;
      }
      fVar25 = fVar14 - fVar25;
      fVar16 = fVar26 - fVar16;
      fVar32 = fVar24 - fVar32;
    }
    else {
      fVar27 = (float)((uint)fVar21 & uVar19);
      if ((float)((uint)fVar21 & uVar19) <= (float)((uint)fVar31 & uVar19)) {
        fVar27 = (float)((uint)fVar31 & uVar19);
      }
      if (fVar27 <= (float)((uint)fVar30 & uVar19)) {
        fVar27 = (float)((uint)fVar30 & uVar19);
      }
      fVar22 = fVar3 / fVar27;
      if (fVar27 <= 0.0) {
        fVar27 = 0.0;
      }
      else {
        fVar27 = SQRT(fVar22 * fVar31 * fVar22 * fVar31 + fVar22 * fVar30 * fVar22 * fVar30 +
                      fVar22 * fVar21 * fVar22 * fVar21) * fVar27;
      }
    }
    fVar30 = fVar14 - (fStack_1b8 * fVar15 + fVar25);
    fVar16 = fVar26 - (fStack_1bc * fVar15 + fVar16);
    fVar25 = fVar24 - (fStack_1b4 * fVar15 + fVar32);
    fVar32 = (float)((uint)fVar25 & uVar19);
    if ((float)((uint)fVar25 & uVar19) <= (float)((uint)fVar30 & uVar19)) {
      fVar32 = (float)((uint)fVar30 & uVar19);
    }
    if (fVar32 <= (float)((uint)fVar16 & uVar19)) {
      fVar32 = (float)((uint)fVar16 & uVar19);
    }
    fVar31 = fVar3 / fVar32;
    if (fVar32 <= 0.0) {
      fVar32 = 0.0;
    }
    else {
      fVar32 = SQRT(fVar31 * fVar30 * fVar31 * fVar30 + fVar31 * fVar16 * fVar31 * fVar16 +
                    fVar31 * fVar25 * fVar31 * fVar25) * fVar32;
    }
    fVar27 = (fVar32 - fVar27) * fStack_190 + fVar27;
    if (fVar32 <= fVar27) {
      fVar27 = fVar32;
    }
    fVar31 = fVar30 * fVar30 + fVar16 * fVar16 + fVar25 * fVar25;
    fVar32 = fVar27 / SQRT(fVar31);
    if (_DAT_14382e110 <= fVar31) {
      fVar25 = fVar25 * fVar32;
      fVar31 = fVar30 * fVar32;
      fVar16 = fVar16 * fVar32;
    }
    else {
      fVar25 = 0.0;
      fVar31 = 0.0;
      fVar16 = fVar27;
    }
    fVar14 = fVar14 - fVar31;
    fVar26 = fVar26 - fVar16;
    fVar24 = fVar24 - fVar25;
    fStack_224 = fVar14;
    if (0.0 < fVar30) {
      if (*(int *)(param_1 + 0x574) != 2) {
        fStack_228 = fVar26;
        fStack_220 = fVar24;
        fVar32 = (float)FUN_14366a0e0(fStack_1c0 * _DAT_14382e11c);
        fVar32 = fVar32 + fVar3;
        fVar16 = (fVar28 - _DAT_1438ac404) * _DAT_143837a20;
        if (fVar32 <= 0.0) {
          fVar32 = 0.0;
        }
        if (fVar16 <= 0.0) {
          fVar16 = 0.0;
        }
        if (fVar3 <= fVar32) {
          fVar32 = fVar3;
        }
        if (fVar3 <= fVar16) {
          fVar16 = fVar3;
        }
        fVar25 = (float)FUN_1420dc660(param_1);
        fVar31 = fVar14 - *(float *)(param_1 + 0x43c);
        fVar21 = fVar24 - *(float *)(param_1 + 0x440);
        fVar25 = (fVar25 - _DAT_14382e120) * _DAT_1438388c4;
        fVar28 = (float)((uint)fVar31 & uVar19);
        fVar30 = (float)((uint)fVar21 & uVar19);
        if (fVar28 <= fVar30) {
          fVar28 = fVar30;
        }
        fVar30 = (float)((uint)(fVar26 - *pfVar2) & uVar19);
        if (fVar25 <= 0.0) {
          fVar25 = 0.0;
        }
        if (fVar28 <= fVar30) {
          fVar28 = fVar30;
        }
        if (fVar3 <= fVar25) {
          fVar25 = fVar3;
        }
        fVar30 = fVar3 / fVar28;
        fVar22 = (fVar26 - *pfVar2) * fVar30;
        fVar31 = fVar31 * fVar30;
        fVar21 = fVar21 * fVar30;
        if (fVar28 <= 0.0) {
          fVar28 = 0.0;
        }
        else {
          fVar28 = SQRT(fVar31 * fVar31 + fVar22 * fVar22 + fVar21 * fVar21) * fVar28;
        }
        fVar30 = *(float *)(param_1 + 0x4a4);
        if (_DAT_14382f2cc <= *(float *)(param_1 + 0x4a4)) {
          fVar30 = _DAT_14382f2cc;
        }
        fVar28 = ((fVar30 - fVar28) - fVar3) * _DAT_14386dc74;
        if (fVar28 <= 0.0) {
          fVar28 = 0.0;
        }
        if (fVar3 <= fVar28) {
          fVar28 = fVar3;
        }
        uVar18 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x4a8),
                                     fVar28 * fVar32 * fVar25 * _DAT_143834a14 * fVar16,
                                     _DAT_14383d264,fVar15);
        *(undefined4 *)(param_1 + 0x4a8) = uVar18;
      }
      fStack_224 = fVar14 - fVar15 * *(float *)(param_1 + 0x4a8);
    }
    fVar14 = fStack_1bc;
    fStack_228 = fVar26;
    fStack_220 = fVar24;
    FUN_140abb030(param_1,&fStack_228,fVar15);
    fStack_250 = fStack_208 + fStack_1b4;
    uStack_258 = CONCAT44(fStack_1d4 + fStack_1b8,fStack_204 + fVar14);
    puVar8 = (undefined8 *)
             FUN_140abf580(param_1,auStack_100,&uStack_258,&uStack_218,CONCAT44(uVar20,fVar27),
                           CONCAT44(uVar36,fVar15));
    uStack_258 = *puVar8;
    fStack_250 = *(float *)(puVar8 + 1);
    in_stack_fffffffffffffd98 = uStack_1e0;
    puVar8 = (undefined8 *)
             FUN_140abf850(param_1,auStack_f4,&uStack_258,&uStack_248,&fStack_228,&fStack_1f0,
                           uStack_1e0,fVar15);
    uStack_248 = *puVar8;
    fStack_240 = *(float *)(puVar8 + 1);
    puVar8 = (undefined8 *)
             FUN_140ac04f0(param_1,auStack_134,&uStack_258,&uStack_248,
                           *(int *)(param_1 + 0x574) == 0,&uStack_218);
    fVar14 = _DAT_1438cea3c;
    uVar29 = _DAT_14382e890;
    fVar26 = _DAT_14382e110;
    uVar33 = *puVar8;
    fStack_1f8 = *(float *)(puVar8 + 1);
    uStack_200._4_4_ = (float)((ulonglong)uVar33 >> 0x20);
    uStack_200._0_4_ = (float)uVar33;
    fVar24 = (float)((uint)uStack_200._4_4_ & uVar19);
    if ((float)((uint)uStack_200._4_4_ & uVar19) <= (float)((uint)fStack_1f8 & uVar19)) {
      fVar24 = (float)((uint)fStack_1f8 & uVar19);
    }
    if (fVar24 <= (float)((uint)(float)uStack_200 & uVar19)) {
      fVar24 = (float)((uint)(float)uStack_200 & uVar19);
    }
    fVar27 = fStack_1f8;
    if (0.0 < fVar24) {
      fVar24 = fVar3 / fVar24;
      fVar27 = fStack_1f8 * fVar24;
      uStack_200._4_4_ = uStack_200._4_4_ * fVar24;
      uStack_200._0_4_ = (float)uStack_200 * fVar24;
      fVar24 = fVar3 / SQRT(uStack_200._4_4_ * uStack_200._4_4_ +
                            (float)uStack_200 * (float)uStack_200 + fVar27 * fVar27);
      uStack_200._0_4_ = fVar24 * (float)uStack_200;
      uStack_200._4_4_ = fVar24 * uStack_200._4_4_;
      fVar27 = fVar24 * fVar27;
    }
    if (0.0 <= uStack_200._4_4_ * fStack_1dc + (float)uStack_200 * fStack_1d8 + fVar27 * fStack_18c)
    {
      puVar11 = (uint *)&uStack_188;
      uStack_188 = CONCAT44(fStack_1cc,fStack_1d0);
      fStack_180 = fVar13;
    }
    else {
      puVar11 = &uStack_15c;
      uStack_15c = (uint)fStack_1d8 ^ _DAT_14382e890;
      uStack_158 = (uint)fStack_1dc ^ _DAT_14382e890;
      uStack_154 = (uint)fStack_18c ^ _DAT_14382e890;
    }
    uVar35 = *(undefined8 *)puVar11;
    uVar12 = uVar12 + 1;
    fStack_210 = (float)puVar11[2];
    *(undefined1 *)(param_1 + 0x5f3) = 0;
    fVar27 = fStack_1d8;
    fVar24 = fStack_1dc;
    fVar32 = fStack_18c;
    uStack_218 = uVar35;
    uStack_200 = uVar33;
  } while (uVar12 < 4);
  uStack_218._4_4_ = (float)((ulonglong)uVar35 >> 0x20);
  uStack_218._0_4_ = (float)uVar35;
  *(undefined8 *)(param_1 + 0x4b8) = uStack_258;
  *(undefined8 *)(param_1 + 0x4dc) = *(undefined8 *)puVar11;
  *(float *)(param_1 + 0x4c0) = fStack_250;
  fStack_228 = (float)((uint)uStack_218._4_4_ & uVar19);
  if ((float)((uint)uStack_218._4_4_ & uVar19) <= (float)((uint)fStack_210 & uVar19)) {
    fStack_228 = (float)((uint)fStack_210 & uVar19);
  }
  *(uint *)(param_1 + 0x4e4) = puVar11[2];
  if (fStack_228 <= (float)((uint)(float)uStack_218 & uVar19)) {
    fStack_228 = (float)((uint)(float)uStack_218 & uVar19);
  }
  if (fStack_228 <= 0.0) {
    fStack_228 = (float)uStack_218;
    fStack_224 = uStack_218._4_4_;
    fStack_220 = fStack_210;
  }
  else {
    fStack_228 = fVar3 / fStack_228;
    fVar13 = fStack_210 * fStack_228;
    fStack_224 = uStack_218._4_4_ * fStack_228;
    fStack_228 = (float)uStack_218 * fStack_228;
    fVar26 = fVar3 / SQRT(fStack_224 * fStack_224 + fStack_228 * fStack_228 + fVar13 * fVar13);
    fStack_228 = fVar26 * fStack_228;
    fStack_224 = fVar26 * fStack_224;
    fStack_220 = fVar26 * fVar13;
  }
  *(ulonglong *)(param_1 + 0x4d0) = CONCAT44(fStack_224,fStack_228);
  *(float *)(param_1 + 0x4d8) = fStack_220;
  fVar26 = *(float *)(param_1 + 0x3d0);
  fVar13 = *(float *)(param_1 + 0x3cc);
  *param_2 = (float)uStack_248 - *pfVar1;
  param_2[2] = fStack_240 - fVar26;
  param_2[1] = uStack_248._4_4_ - fVar13;
  fVar26 = (float)FUN_1420dc660(param_1);
  if (_DAT_143837a20 < fVar26) {
    lVar9 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar9 + 0x88) == 0) {
      lVar9 = FUN_14167ab40(lVar9 + 0x58,0x146dd6030);
    }
    else {
      lVar9 = func_0x0001416799a0(lVar9 + 0x80);
    }
    uVar19 = FUN_140876340(param_2);
    uVar20 = FUN_141c58560(*(undefined4 *)(param_1 + 0x4b8),*(undefined4 *)(param_1 + 0x4c0));
    fVar26 = (float)FUN_1402c2450(param_2);
    fVar26 = fVar26 / param_3;
    pfVar10 = (float *)FUN_141c5a7a0(auStack_134,fVar3,uVar20,uVar19 ^ uVar29);
    fVar3 = pfVar10[2];
    auVar4._4_4_ = -(uint)(_UNK_14382e154 == 0.0);
    auVar4._0_4_ = -(uint)((float)((uint)(fVar26 * fVar3) & (uint)_DAT_14382e150) == _DAT_14382e150)
    ;
    auVar4._8_4_ = -(uint)((float)((uint)(fVar26 * *pfVar10) & (uint)_UNK_14382e158) ==
                          _UNK_14382e158);
    auVar4._12_4_ =
         -(uint)((float)((uint)(fVar26 * pfVar10[1]) & (uint)_UNK_14382e15c) == _UNK_14382e15c);
    iVar6 = movmskps((int)pfVar10,auVar4);
    if (iVar6 == 0) {
      *(ulonglong *)(lVar9 + 0x134) = CONCAT44(fVar26 * pfVar10[1],fVar26 * *pfVar10);
      *(float *)(lVar9 + 0x13c) = fVar26 * fVar3;
      *(undefined1 *)(lVar9 + 0x140) = 1;
    }
  }
  return param_2;
}


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
  fVar1 = _DAT_14382dce0;
  fVar14 = *(float *)(lVar3 + 0x340);
  fVar13 = *(float *)(lVar3 + 0x344);
  fVar12 = *(float *)(lVar3 + 0x348);
  fVar10 = *(float *)(param_1 + 0x430);
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  fVar6 = (_DAT_14382dce0 - fVar14) * *(float *)(lVar5 + 0x208) + fVar14;
  fVar6 = (fVar14 - fVar6) * fVar10 + fVar6;
  fVar7 = (_DAT_14382dce0 - fVar13) * *(float *)(lVar5 + 0x20c) + fVar13;
  fVar7 = (fVar13 - fVar7) * fVar10 + fVar7;
  fVar8 = (_DAT_14382dce0 - fVar12) * *(float *)(lVar5 + 0x210) + fVar12;
  fVar9 = (float)FUN_140876340(param_5);
  fVar13 = _DAT_1438ac374;
  fVar14 = _DAT_143830124;
  uVar2 = _DAT_14382e160;
  fVar11 = (float)((uint)(fVar9 * _DAT_143830124) & _DAT_14382e160);
  if (fVar9 * _DAT_143830124 <= 0.0) {
    fVar6 = (fVar11 - _DAT_14382f2cc) * _DAT_14384421c;
    if (fVar6 <= 0.0) {
      fVar6 = 0.0;
    }
    if (fVar1 <= fVar6) {
      fVar6 = fVar1;
    }
    fVar6 = (((fVar12 - fVar8) * fVar10 + fVar8) - fVar7) * fVar6 + fVar7;
  }
  else {
    fVar12 = (fVar11 - _DAT_14382f0e0) * _DAT_1438ac374;
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
  fVar12 = (fVar6 - fVar1) * _DAT_145d9fe90 + fVar1;
  if (*(float *)(param_1 + 0x518) <= fVar12) {
    fVar12 = *(float *)(param_1 + 0x518);
  }
  *(float *)(param_1 + 0x518) = fVar12;
  fVar12 = *(float *)(param_1 + 0x4fc);
  fVar10 = (float)FUN_1420dc660(param_1);
  fVar10 = (fVar10 - _DAT_143839a5c) * _DAT_1438ad110;
  fVar13 = ((float)((uint)(fVar12 * fVar14) & uVar2) - _DAT_14384bc0c) * fVar13;
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
  fVar14 = *(float *)(param_1 + 0x518) - fVar10 * param_7 * fVar13 * _DAT_143837a24;
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


/* SwingRegion_140abf4f0 @ 0x140abf4f0 */

void FUN_140abf4f0(undefined8 *param_1)

{
  *param_1 = &UNK_14382ddf0;
  *(undefined4 *)((longlong)param_1 + 0x14) = 0;
  func_0x000141984310(param_1 + 3);
  *(undefined4 *)((longlong)param_1 + 0x3c) = 0;
  *param_1 = &UNK_1438ce990;
  func_0x000140abaf70(param_1 + 0x24);
  *(undefined8 *)((longlong)param_1 + 0x584) = 0;
  *(undefined2 *)((longlong)param_1 + 0x581) = 0xff;
  *(undefined1 *)(param_1 + 0xb0) = 0xff;
  FUN_1420df1c0(param_1 + 0xb0,0xff);
  param_1[0xb2] = 0;
  *(undefined2 *)((longlong)param_1 + 0x58d) = 0xff;
  *(undefined1 *)((longlong)param_1 + 0x58c) = 0xff;
  FUN_1420df1c0((undefined1 *)((longlong)param_1 + 0x58c),0xff);
  return;
}


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
  uVar2 = _DAT_14382e160;
  fVar8 = _DAT_14382dce0;
  fVar9 = 0.0;
  fVar4 = (float)((uint)param_3[2] & _DAT_14382e160);
  fVar7 = (float)((uint)*param_3 & _DAT_14382e160);
  if (fVar7 <= fVar4) {
    fVar7 = fVar4;
  }
  fVar6 = *param_3 * (_DAT_14382dce0 / fVar7);
  fVar4 = param_3[2] * (_DAT_14382dce0 / fVar7);
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
    fVar6 = fVar6 - (float)((uint)fVar4 & _DAT_14382e160) * *(float *)(lVar1 + 0x34) * param_6;
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
    if (fVar6 <= _DAT_1438cea44) {
      fVar5 = (float)FUN_14366a0e0();
      if (fVar5 <= _DAT_143830ee8) {
        fVar5 = _DAT_143830ee8;
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
  param_5 = param_5 * _DAT_1438627c4;
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
  fVar13 = _DAT_143834a14;
  fVar3 = _DAT_143830ee8;
  fVar5 = _DAT_14382f0dc;
  fVar4 = _DAT_14382e128;
  fVar15 = (*(float *)(param_1 + 0x43c) - *(float *)(param_1 + 0x4a4)) - _DAT_14382f0dc;
  fVar12 = *(float *)(param_1 + 0x494);
  if (*(float *)(param_1 + 0x494) == _DAT_143830778) {
    fVar12 = fVar15;
  }
  *(float *)(param_1 + 0x494) = fVar12;
  if (*(char *)(param_1 + 0x48c) != '\0') {
    fVar2 = (float)FUN_140311350(param_1 + 0x480,param_6);
    fVar11 = fVar2 - _DAT_143834a0c;
    if (fVar1 <= fVar2 - _DAT_143834a0c) {
      fVar11 = fVar1;
    }
    if ((fVar11 < fVar1 - fVar3) &&
       (*(float *)(param_1 + 0x484) < *(float *)(param_1 + 0x448) - fVar13)) {
      fVar15 = *(float *)(param_1 + 0x484) + fVar5;
      fVar3 = (float)func_0x0001403e3f30(param_3);
      fVar4 = (float)func_0x0001404c4e20(param_1 + 0x480,param_4);
      fVar4 = fVar4 / ((*(float *)(param_1 + 0x51c) - fVar3) * _DAT_14382f760 + fVar3);
    }
  }
  fVar11 = _DAT_14384002c;
  fVar3 = _DAT_14382dce0;
  if (fVar15 <= fVar12) {
    if (fVar15 < fVar12 - fVar5) {
      fVar12 = ((fVar12 - fVar15) - fVar13) * _DAT_1438564c4;
      if (fVar12 <= 0.0) {
        fVar12 = 0.0;
      }
      if (_DAT_14382dce0 <= fVar12) {
        fVar12 = _DAT_14382dce0;
      }
      uVar8 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x498),fVar12 * _DAT_143830120 + fVar5,
                                  fVar12 * _DAT_14384002c + _DAT_14382f0e4,param_8);
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
  fVar16 = _DAT_14382e118;
  fVar9 = fVar15;
  if (fVar15 <= fVar5) {
    fVar9 = fVar5;
  }
  param_2[2] = fVar2;
  uVar14 = _DAT_14382e160;
  fVar10 = _DAT_14382e120;
  if (fVar9 < fVar12) {
    fVar1 = (fVar4 - _DAT_143837a20) * _DAT_14382f0e0;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    if (fVar3 <= fVar1) {
      fVar1 = fVar3;
    }
    if (fVar4 <= _DAT_143830118) {
      fVar4 = 0.0;
    }
    else {
      fVar4 = (fVar12 - fVar5) / fVar4;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
    }
    fVar12 = ((fVar12 - fVar5) - fVar3) * _DAT_143836d0c;
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
    if (_DAT_14382f0e0 <= fVar13) {
      fVar13 = _DAT_14382f0e0;
    }
    fVar4 = (float)func_0x000141c477e0(*(undefined4 *)(param_1 + 0x4a0),fVar13,_DAT_1438ac3f4,
                                       param_8);
    uVar14 = _DAT_14382e160;
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
      fVar10 = (*(float *)(param_1 + 0x49c) - _DAT_14382f0e0) * fVar10;
      if (fVar10 <= 0.0) {
        fVar10 = 0.0;
      }
      if (fVar3 <= fVar10) {
        fVar10 = fVar3;
      }
      fVar4 = (float)FUN_140876340(param_3);
      fVar4 = fVar4 * _DAT_1438cea6c - _DAT_1438b4f48;
      fVar5 = fVar10 * _DAT_1438cea60 + _DAT_14383f374;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
      if (fVar3 <= fVar4) {
        fVar4 = fVar3;
      }
      uVar6 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x49c),0,
                                  (_DAT_14384002c - fVar5) * fVar4 + fVar5,param_8);
      *(uint *)(param_1 + 0x49c) = uVar6;
      param_2[1] = (float)(uVar6 & uVar14) * param_8 + param_2[1];
    }
  }
  else {
    fVar13 = (float)func_0x000141c58730(param_7 * _DAT_14382e11c);
    fVar12 = (float)((uint)(fVar5 - fVar15) & uVar14);
    fVar4 = *(float *)(param_1 + 0x494);
    fVar5 = ((fVar4 - fVar17) / param_3[1] - fVar10) * _DAT_1438388c4;
    if (fVar5 <= 0.0) {
      fVar5 = 0.0;
    }
    if (fVar3 <= fVar5) {
      fVar5 = fVar3;
    }
    fVar16 = _DAT_14382e118;
    if (fVar4 <= *(float *)(param_1 + 0x448) - fVar13 * fVar1) goto LAB_140abfd63;
    fVar13 = (float)FUN_143667c70(((fVar3 - fVar5) * _DAT_14382ee94 - _DAT_143830120) * param_8);
    fVar4 = (fVar3 - fVar13) * (param_4[1] - fVar4);
    fVar5 = (float)FUN_143667c70((_DAT_14386d9b0 - (fVar3 - fVar5) * _DAT_1438794d0) * param_8);
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
      fVar13 = (float)((uint)fVar4 & uVar14) * _DAT_143848d00;
      fVar5 = fVar5 * _DAT_143854044 * param_8;
      if (fVar5 <= fVar13) {
        fVar13 = fVar5;
      }
      param_3[1] = fVar13 + fVar4;
    }
  }
  uVar7 = func_0x000141c477e0(*(undefined4 *)(param_1 + 0x4a0),0,_DAT_1438ac3f4,param_8);
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
  if (fVar12 < fVar1 - _DAT_14382e118) {
    if (fVar13 <= 0.0) {
      fVar13 = 0.0;
    }
    fVar15 = 0.0;
    if (fVar13 <= fVar16) {
      fVar13 = fVar16;
    }
    fVar16 = (fVar1 - fVar12) * _DAT_14382e130;
    fVar12 = (fVar3 / fVar13) * fVar11;
    fVar1 = (fVar3 / fVar13) * fVar2;
    if (0.0 < fVar13) {
      fVar15 = SQRT(fVar12 * fVar12 + fVar1 * fVar1) * fVar13;
    }
    fVar15 = fVar15 + fVar16;
    fVar13 = fVar11 * fVar11 + fVar2 * fVar2;
    fVar12 = fVar15 / SQRT(fVar13);
    if (_DAT_14382e110 <= fVar13) {
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
       (fVar4 = SQRT(fVar12 * fVar12 + fVar1 * fVar1) * fVar4, _DAT_143830ee8 <= fVar4)) {
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


/* SwingRegion_140abf898 @ 0x140abf898 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abf898(void)

{
  longlong in_RAX;
  longlong unaff_RBX;
  undefined8 unaff_RBP;
  float *unaff_RSI;
  float *unaff_RDI;
  float *in_R9;
  undefined8 unaff_R12;
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
  undefined4 unaff_XMM10_Da;
  float fVar15;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  undefined4 unaff_XMM11_Da;
  undefined4 unaff_XMM11_Db;
  undefined4 unaff_XMM11_Dc;
  undefined4 unaff_XMM11_Dd;
  float fVar16;
  float fVar17;
  float fStackX_20;
  undefined8 *in_stack_00000110;
  undefined8 in_stack_00000118;
  float in_stack_00000120;
  float in_stack_00000128;
  
  *(undefined8 *)(in_RAX + 8) = unaff_RBP;
  *(undefined8 *)(in_RAX + 0x10) = unaff_R12;
  *(undefined4 *)(in_RAX + -0x68) = unaff_XMM10_Da;
  *(undefined4 *)(in_RAX + -100) = unaff_XMM10_Db;
  *(undefined4 *)(in_RAX + -0x60) = unaff_XMM10_Dc;
  *(undefined4 *)(in_RAX + -0x5c) = unaff_XMM10_Dd;
  *(undefined4 *)(in_RAX + -0x78) = unaff_XMM11_Da;
  *(undefined4 *)(in_RAX + -0x74) = unaff_XMM11_Db;
  *(undefined4 *)(in_RAX + -0x70) = unaff_XMM11_Dc;
  *(undefined4 *)(in_RAX + -0x6c) = unaff_XMM11_Dd;
  fVar1 = (float)FUN_140311350(in_stack_00000110);
  fVar13 = _DAT_143834a14;
  fVar3 = _DAT_143830ee8;
  fVar5 = _DAT_14382f0dc;
  fVar4 = _DAT_14382e128;
  fVar15 = (*(float *)(unaff_RBX + 0x43c) - *(float *)(unaff_RBX + 0x4a4)) - _DAT_14382f0dc;
  fVar12 = *(float *)(unaff_RBX + 0x494);
  if (*(float *)(unaff_RBX + 0x494) == _DAT_143830778) {
    fVar12 = fVar15;
  }
  *(float *)(unaff_RBX + 0x494) = fVar12;
  if (*(char *)(unaff_RBX + 0x48c) != '\0') {
    fVar2 = (float)FUN_140311350(unaff_RBX + 0x480,in_stack_00000118);
    fVar11 = fVar2 - _DAT_143834a0c;
    if (fVar1 <= fVar2 - _DAT_143834a0c) {
      fVar11 = fVar1;
    }
    if ((fVar11 < fVar1 - fVar3) &&
       (*(float *)(unaff_RBX + 0x484) < *(float *)(unaff_RBX + 0x448) - fVar13)) {
      fVar15 = *(float *)(unaff_RBX + 0x484) + fVar5;
      fVar3 = (float)func_0x0001403e3f30();
      fVar4 = (float)func_0x0001404c4e20(unaff_RBX + 0x480,in_R9);
      fVar4 = fVar4 / ((*(float *)(unaff_RBX + 0x51c) - fVar3) * _DAT_14382f760 + fVar3);
    }
  }
  fVar11 = _DAT_14384002c;
  fVar3 = _DAT_14382dce0;
  if (fVar15 <= fVar12) {
    if (fVar15 < fVar12 - fVar5) {
      fVar12 = ((fVar12 - fVar15) - fVar13) * _DAT_1438564c4;
      if (fVar12 <= 0.0) {
        fVar12 = 0.0;
      }
      if (_DAT_14382dce0 <= fVar12) {
        fVar12 = _DAT_14382dce0;
      }
      uVar8 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x498),fVar12 * _DAT_143830120 + fVar5
                                  ,fVar12 * _DAT_14384002c + _DAT_14382f0e4,in_stack_00000128);
      *(int *)(unaff_RBX + 0x498) = (int)uVar8;
      fVar12 = (float)func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x494),fVar15,uVar8,
                                          in_stack_00000128);
      *(float *)(unaff_RBX + 0x494) = fVar12;
    }
  }
  else {
    *(float *)(unaff_RBX + 0x494) = fVar15;
    *(undefined4 *)(unaff_RBX + 0x498) = 0;
    fVar12 = fVar15;
  }
  uVar8 = *in_stack_00000110;
  fVar2 = *(float *)(in_stack_00000110 + 1);
  fVar17 = (float)((ulonglong)uVar8 >> 0x20);
  fVar5 = *(float *)((longlong)in_stack_00000110 + 4);
  fVar15 = in_R9[1];
  *(undefined8 *)unaff_RDI = uVar8;
  fVar16 = _DAT_14382e118;
  fVar9 = fVar15;
  if (fVar15 <= fVar5) {
    fVar9 = fVar5;
  }
  unaff_RDI[2] = fVar2;
  uVar14 = _DAT_14382e160;
  fVar10 = _DAT_14382e120;
  if (fVar9 < fVar12) {
    fVar1 = (fVar4 - _DAT_143837a20) * _DAT_14382f0e0;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    if (fVar3 <= fVar1) {
      fVar1 = fVar3;
    }
    if (fVar4 <= _DAT_143830118) {
      fVar4 = 0.0;
    }
    else {
      fVar4 = (fVar12 - fVar5) / fVar4;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
    }
    fVar12 = ((fVar12 - fVar5) - fVar3) * _DAT_143836d0c;
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
    if (_DAT_14382f0e0 <= fVar13) {
      fVar13 = _DAT_14382f0e0;
    }
    fVar4 = (float)func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x4a0),fVar13,_DAT_1438ac3f4,
                                       in_stack_00000128);
    uVar14 = _DAT_14382e160;
    fVar13 = *(float *)(unaff_RBX + 0x494) - fVar5;
    *(float *)(unaff_RBX + 0x4a0) = fVar4;
    fVar4 = fVar4 * in_stack_00000128 + fVar5;
    if ((fVar4 - unaff_RDI[1] < fVar13) && (in_stack_00000128 * unaff_RSI[1] < 0.0)) {
      fVar13 = fVar13 - (fVar4 - unaff_RDI[1]);
      fVar12 = (float)((uint)(in_stack_00000128 * unaff_RSI[1]) & uVar14);
      if (fVar13 <= fVar12) {
        fVar12 = fVar13;
      }
      fVar4 = fVar4 + fVar12;
    }
    fVar4 = (fVar4 - fVar5) / in_stack_00000128;
    if (fVar4 <= *(float *)(unaff_RBX + 0x49c)) {
      fVar4 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x49c),fVar4,fVar11,
                                         in_stack_00000128);
    }
    *(float *)(unaff_RBX + 0x49c) = fVar4;
    unaff_RDI[1] = fVar4 * in_stack_00000128 + unaff_RDI[1];
    goto LAB_140abfe2c;
  }
  if (0.0 <= fVar5 - fVar15) {
LAB_140abfd63:
    if (fVar16 < (float)((uint)*(float *)(unaff_RBX + 0x49c) & uVar14)) {
      fVar10 = (*(float *)(unaff_RBX + 0x49c) - _DAT_14382f0e0) * fVar10;
      if (fVar10 <= 0.0) {
        fVar10 = 0.0;
      }
      if (fVar3 <= fVar10) {
        fVar10 = fVar3;
      }
      fVar4 = (float)FUN_140876340();
      fVar4 = fVar4 * _DAT_1438cea6c - _DAT_1438b4f48;
      fVar5 = fVar10 * _DAT_1438cea60 + _DAT_14383f374;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
      if (fVar3 <= fVar4) {
        fVar4 = fVar3;
      }
      uVar6 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x49c),0,
                                  (_DAT_14384002c - fVar5) * fVar4 + fVar5,in_stack_00000128);
      *(uint *)(unaff_RBX + 0x49c) = uVar6;
      unaff_RDI[1] = (float)(uVar6 & uVar14) * in_stack_00000128 + unaff_RDI[1];
    }
  }
  else {
    fVar13 = (float)func_0x000141c58730(in_stack_00000120 * _DAT_14382e11c);
    fVar12 = (float)((uint)(fVar5 - fVar15) & uVar14);
    fVar4 = *(float *)(unaff_RBX + 0x494);
    fVar5 = ((fVar4 - fVar17) / unaff_RSI[1] - fVar10) * _DAT_1438388c4;
    if (fVar5 <= 0.0) {
      fVar5 = 0.0;
    }
    if (fVar3 <= fVar5) {
      fVar5 = fVar3;
    }
    fVar16 = _DAT_14382e118;
    if (fVar4 <= *(float *)(unaff_RBX + 0x448) - fVar13 * fVar1) goto LAB_140abfd63;
    fVar13 = (float)FUN_143667c70(((fVar3 - fVar5) * _DAT_14382ee94 - _DAT_143830120) *
                                  in_stack_00000128);
    fVar4 = (fVar3 - fVar13) * (in_R9[1] - fVar4);
    fVar5 = (float)FUN_143667c70((_DAT_14386d9b0 - (fVar3 - fVar5) * _DAT_1438794d0) *
                                 in_stack_00000128);
    fVar5 = fVar5 * fVar12;
    if (fVar5 <= fVar4) {
      fVar4 = fVar5;
    }
    fVar12 = fVar12 - fVar4;
    fVar5 = fVar12 / in_stack_00000128;
    unaff_RDI[1] = fVar12 + unaff_RDI[1];
    *(float *)(unaff_RBX + 0x49c) = fVar5;
    fVar4 = unaff_RSI[1];
    if (fVar4 < 0.0) {
      fVar13 = (float)((uint)fVar4 & uVar14) * _DAT_143848d00;
      fVar5 = fVar5 * _DAT_143854044 * in_stack_00000128;
      if (fVar5 <= fVar13) {
        fVar13 = fVar5;
      }
      unaff_RSI[1] = fVar13 + fVar4;
    }
  }
  uVar7 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x4a0),0,_DAT_1438ac3f4,in_stack_00000128)
  ;
  *(undefined4 *)(unaff_RBX + 0x4a0) = uVar7;
LAB_140abfe2c:
  fStackX_20 = (float)uVar8;
  fVar4 = in_R9[2];
  fVar17 = fVar17 - in_R9[1];
  fVar5 = *in_R9;
  fVar2 = fVar2 - fVar4;
  fVar12 = (float)((uint)fVar17 & uVar14);
  fVar13 = (float)((uint)fVar2 & uVar14);
  if (fVar13 <= fVar12) {
    fVar13 = fVar12;
  }
  fVar12 = (float)((uint)(fStackX_20 - fVar5) & uVar14);
  if (fVar13 <= fVar12) {
    fVar13 = fVar12;
  }
  fVar15 = fVar3 / fVar13;
  fVar12 = fVar15 * (fStackX_20 - fVar5);
  fVar1 = 0.0;
  fVar17 = fVar15 * fVar17;
  fVar15 = fVar15 * fVar2;
  if (0.0 < fVar13) {
    fVar1 = SQRT(fVar17 * fVar17 + fVar12 * fVar12 + fVar15 * fVar15) * fVar13;
  }
  fVar2 = *unaff_RDI - fVar5;
  fVar15 = unaff_RDI[1] - in_R9[1];
  fVar11 = unaff_RDI[2] - fVar4;
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
  if (fVar12 < fVar1 - _DAT_14382e118) {
    if (fVar13 <= 0.0) {
      fVar13 = 0.0;
    }
    fVar15 = 0.0;
    if (fVar13 <= fVar16) {
      fVar13 = fVar16;
    }
    fVar16 = (fVar1 - fVar12) * _DAT_14382e130;
    fVar12 = (fVar3 / fVar13) * fVar11;
    fVar1 = (fVar3 / fVar13) * fVar2;
    if (0.0 < fVar13) {
      fVar15 = SQRT(fVar12 * fVar12 + fVar1 * fVar1) * fVar13;
    }
    fVar15 = fVar15 + fVar16;
    fVar13 = fVar11 * fVar11 + fVar2 * fVar2;
    fVar12 = fVar15 / SQRT(fVar13);
    if (_DAT_14382e110 <= fVar13) {
      fVar11 = fVar12 * fVar11;
      fVar15 = fVar12 * fVar2;
    }
    else {
      fVar11 = 0.0;
    }
    fVar13 = unaff_RSI[2];
    *(ulonglong *)unaff_RDI = CONCAT44(unaff_RDI[1] + 0.0,fVar15 + fVar5);
    fVar5 = *unaff_RSI;
    unaff_RDI[2] = fVar11 + fVar4;
    fVar4 = (float)((uint)fVar5 & uVar14);
    if ((float)((uint)fVar5 & uVar14) <= (float)((uint)fVar13 & uVar14)) {
      fVar4 = (float)((uint)fVar13 & uVar14);
    }
    fVar1 = fVar5 * (fVar3 / fVar4);
    fVar12 = fVar13 * (fVar3 / fVar4);
    if ((0.0 < fVar4) &&
       (fVar4 = SQRT(fVar12 * fVar12 + fVar1 * fVar1) * fVar4, _DAT_143830ee8 <= fVar4)) {
      fVar3 = *(float *)(unaff_RBX + 0x51c) - fVar4;
      if (fVar3 <= 0.0) {
        fVar3 = 0.0;
      }
      if (fVar16 <= fVar3) {
        fVar3 = fVar16;
      }
      fVar3 = (fVar3 + fVar4) / fVar4;
    }
    *unaff_RSI = fVar5 * fVar3;
    unaff_RSI[2] = fVar13 * fVar3;
  }
  return;
}


/* SwingRegion_140abf937 @ 0x140abf937 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abf937(void)

{
  longlong unaff_RBX;
  undefined8 *unaff_RBP;
  float *unaff_RSI;
  float *unaff_RDI;
  float *unaff_R12;
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
  float unaff_XMM6_Da;
  float unaff_XMM9_Da;
  float fVar12;
  uint uVar13;
  undefined4 unaff_XMM9_Db;
  float unaff_XMM10_Da;
  float unaff_XMM12_Da;
  float fVar14;
  float unaff_XMM13_Da;
  float fVar15;
  float unaff_XMM14_Da;
  float unaff_XMM15_Da;
  float fStackX_20;
  float in_stack_00000120;
  float in_stack_00000128;
  
  fVar1 = (float)FUN_140311350();
  fVar2 = fVar1 - _DAT_143834a0c;
  if (unaff_XMM14_Da <= fVar1 - _DAT_143834a0c) {
    fVar2 = unaff_XMM14_Da;
  }
  if ((fVar2 < unaff_XMM14_Da - unaff_XMM6_Da) &&
     (*(float *)(unaff_RBX + 0x484) < *(float *)(unaff_RBX + 0x448) - unaff_XMM15_Da)) {
    unaff_XMM10_Da = *(float *)(unaff_RBX + 0x484) + unaff_XMM13_Da;
    fVar2 = (float)func_0x0001403e3f30();
    fVar1 = (float)func_0x0001404c4e20(unaff_RBX + 0x480);
    unaff_XMM12_Da = fVar1 / ((*(float *)(unaff_RBX + 0x51c) - fVar2) * _DAT_14382f760 + fVar2);
  }
  fVar1 = _DAT_14384002c;
  fVar2 = _DAT_14382dce0;
  if (unaff_XMM10_Da <= unaff_XMM9_Da) {
    if (unaff_XMM10_Da < unaff_XMM9_Da - unaff_XMM13_Da) {
      fVar5 = ((unaff_XMM9_Da - unaff_XMM10_Da) - unaff_XMM15_Da) * _DAT_1438564c4;
      if (fVar5 <= 0.0) {
        fVar5 = 0.0;
      }
      if (_DAT_14382dce0 <= fVar5) {
        fVar5 = _DAT_14382dce0;
      }
      uVar8 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x498),
                                  fVar5 * _DAT_143830120 + unaff_XMM13_Da,
                                  CONCAT44(unaff_XMM9_Db,fVar5 * _DAT_14384002c + _DAT_14382f0e4),
                                  in_stack_00000128);
      *(int *)(unaff_RBX + 0x498) = (int)uVar8;
      unaff_XMM9_Da =
           (float)func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x494),unaff_XMM10_Da,uVar8,
                                      in_stack_00000128);
      *(float *)(unaff_RBX + 0x494) = unaff_XMM9_Da;
    }
  }
  else {
    *(float *)(unaff_RBX + 0x494) = unaff_XMM10_Da;
    *(undefined4 *)(unaff_RBX + 0x498) = 0;
    unaff_XMM9_Da = unaff_XMM10_Da;
  }
  uVar8 = *unaff_RBP;
  fVar9 = *(float *)(unaff_RBP + 1);
  fVar15 = (float)((ulonglong)uVar8 >> 0x20);
  fVar5 = *(float *)((longlong)unaff_RBP + 4);
  fVar3 = unaff_R12[1];
  *(undefined8 *)unaff_RDI = uVar8;
  fVar4 = _DAT_14382e118;
  fVar12 = fVar3;
  if (fVar3 <= fVar5) {
    fVar12 = fVar5;
  }
  unaff_RDI[2] = fVar9;
  uVar13 = _DAT_14382e160;
  fVar11 = _DAT_14382e120;
  if (fVar12 < unaff_XMM9_Da) {
    fVar3 = (unaff_XMM12_Da - _DAT_143837a20) * _DAT_14382f0e0;
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    if (fVar2 <= fVar3) {
      fVar3 = fVar2;
    }
    if (unaff_XMM12_Da <= _DAT_143830118) {
      fVar4 = 0.0;
    }
    else {
      fVar4 = (unaff_XMM9_Da - fVar5) / unaff_XMM12_Da;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
    }
    fVar12 = ((unaff_XMM9_Da - fVar5) - fVar2) * _DAT_143836d0c;
    if (fVar12 <= 0.0) {
      fVar12 = 0.0;
    }
    if (fVar2 <= fVar12) {
      fVar12 = fVar2;
    }
    fVar3 = fVar12 * (fVar2 - fVar3) * unaff_XMM15_Da + fVar2;
    if (fVar3 <= fVar4) {
      fVar3 = fVar4;
    }
    if (_DAT_14382f0e0 <= fVar3) {
      fVar3 = _DAT_14382f0e0;
    }
    fVar3 = (float)func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x4a0),fVar3,_DAT_1438ac3f4,
                                       in_stack_00000128);
    uVar13 = _DAT_14382e160;
    fVar4 = *(float *)(unaff_RBX + 0x494) - fVar5;
    *(float *)(unaff_RBX + 0x4a0) = fVar3;
    fVar3 = fVar3 * in_stack_00000128 + fVar5;
    if ((fVar3 - unaff_RDI[1] < fVar4) && (in_stack_00000128 * unaff_RSI[1] < 0.0)) {
      fVar4 = fVar4 - (fVar3 - unaff_RDI[1]);
      fVar12 = (float)((uint)(in_stack_00000128 * unaff_RSI[1]) & uVar13);
      if (fVar4 <= fVar12) {
        fVar12 = fVar4;
      }
      fVar3 = fVar3 + fVar12;
    }
    fVar5 = (fVar3 - fVar5) / in_stack_00000128;
    if (fVar5 <= *(float *)(unaff_RBX + 0x49c)) {
      fVar5 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x49c),fVar5,fVar1,in_stack_00000128
                                        );
    }
    *(float *)(unaff_RBX + 0x49c) = fVar5;
    unaff_RDI[1] = fVar5 * in_stack_00000128 + unaff_RDI[1];
    goto LAB_140abfe2c;
  }
  if (0.0 <= fVar5 - fVar3) {
LAB_140abfd63:
    if (fVar4 < (float)((uint)*(float *)(unaff_RBX + 0x49c) & uVar13)) {
      fVar11 = (*(float *)(unaff_RBX + 0x49c) - _DAT_14382f0e0) * fVar11;
      if (fVar11 <= 0.0) {
        fVar11 = 0.0;
      }
      if (fVar2 <= fVar11) {
        fVar11 = fVar2;
      }
      fVar1 = (float)FUN_140876340();
      fVar1 = fVar1 * _DAT_1438cea6c - _DAT_1438b4f48;
      fVar5 = fVar11 * _DAT_1438cea60 + _DAT_14383f374;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0;
      }
      if (fVar2 <= fVar1) {
        fVar1 = fVar2;
      }
      uVar6 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x49c),0,
                                  (_DAT_14384002c - fVar5) * fVar1 + fVar5,in_stack_00000128);
      *(uint *)(unaff_RBX + 0x49c) = uVar6;
      unaff_RDI[1] = (float)(uVar6 & uVar13) * in_stack_00000128 + unaff_RDI[1];
    }
  }
  else {
    fVar12 = (float)func_0x000141c58730(in_stack_00000120 * _DAT_14382e11c);
    fVar3 = (float)((uint)(fVar5 - fVar3) & uVar13);
    fVar1 = *(float *)(unaff_RBX + 0x494);
    fVar5 = ((fVar1 - fVar15) / unaff_RSI[1] - fVar11) * _DAT_1438388c4;
    if (fVar5 <= 0.0) {
      fVar5 = 0.0;
    }
    if (fVar2 <= fVar5) {
      fVar5 = fVar2;
    }
    fVar4 = _DAT_14382e118;
    if (fVar1 <= *(float *)(unaff_RBX + 0x448) - fVar12 * unaff_XMM14_Da) goto LAB_140abfd63;
    fVar4 = (float)FUN_143667c70(((fVar2 - fVar5) * _DAT_14382ee94 - _DAT_143830120) *
                                 in_stack_00000128);
    fVar1 = (fVar2 - fVar4) * (unaff_R12[1] - fVar1);
    fVar5 = (float)FUN_143667c70((_DAT_14386d9b0 - (fVar2 - fVar5) * _DAT_1438794d0) *
                                 in_stack_00000128);
    fVar5 = fVar5 * fVar3;
    if (fVar5 <= fVar1) {
      fVar1 = fVar5;
    }
    fVar3 = fVar3 - fVar1;
    fVar5 = fVar3 / in_stack_00000128;
    unaff_RDI[1] = fVar3 + unaff_RDI[1];
    *(float *)(unaff_RBX + 0x49c) = fVar5;
    fVar1 = unaff_RSI[1];
    if (fVar1 < 0.0) {
      fVar3 = (float)((uint)fVar1 & uVar13) * _DAT_143848d00;
      fVar5 = fVar5 * _DAT_143854044 * in_stack_00000128;
      if (fVar5 <= fVar3) {
        fVar3 = fVar5;
      }
      unaff_RSI[1] = fVar3 + fVar1;
    }
  }
  uVar7 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x4a0),0,_DAT_1438ac3f4,in_stack_00000128)
  ;
  *(undefined4 *)(unaff_RBX + 0x4a0) = uVar7;
LAB_140abfe2c:
  fStackX_20 = (float)uVar8;
  fVar1 = unaff_R12[2];
  fVar15 = fVar15 - unaff_R12[1];
  fVar5 = *unaff_R12;
  fVar9 = fVar9 - fVar1;
  fVar4 = (float)((uint)fVar15 & uVar13);
  fVar3 = (float)((uint)fVar9 & uVar13);
  if (fVar3 <= fVar4) {
    fVar3 = fVar4;
  }
  fVar4 = (float)((uint)(fStackX_20 - fVar5) & uVar13);
  if (fVar3 <= fVar4) {
    fVar3 = fVar4;
  }
  fVar11 = fVar2 / fVar3;
  fVar4 = fVar11 * (fStackX_20 - fVar5);
  fVar12 = 0.0;
  fVar15 = fVar11 * fVar15;
  fVar11 = fVar11 * fVar9;
  if (0.0 < fVar3) {
    fVar12 = SQRT(fVar15 * fVar15 + fVar4 * fVar4 + fVar11 * fVar11) * fVar3;
  }
  fVar11 = *unaff_RDI - fVar5;
  fVar4 = unaff_RDI[1] - unaff_R12[1];
  fVar15 = unaff_RDI[2] - fVar1;
  fVar14 = (float)((uint)fVar11 & uVar13);
  fVar9 = (float)((uint)fVar4 & uVar13);
  fVar3 = (float)((uint)fVar15 & uVar13);
  if (fVar9 <= fVar3) {
    fVar9 = fVar3;
  }
  if (fVar9 <= fVar14) {
    fVar9 = fVar14;
  }
  fVar10 = fVar2 / fVar9;
  fVar4 = fVar10 * fVar4;
  if (fVar9 <= 0.0) {
    fVar9 = 0.0;
  }
  else {
    fVar9 = SQRT(fVar4 * fVar4 + fVar10 * fVar11 * fVar10 * fVar11 +
                 fVar10 * fVar15 * fVar10 * fVar15) * fVar9;
  }
  if (fVar9 < fVar12 - _DAT_14382e118) {
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    fVar4 = 0.0;
    if (fVar3 <= fVar14) {
      fVar3 = fVar14;
    }
    fVar14 = (fVar12 - fVar9) * _DAT_14382e130;
    fVar9 = (fVar2 / fVar3) * fVar15;
    fVar12 = (fVar2 / fVar3) * fVar11;
    if (0.0 < fVar3) {
      fVar4 = SQRT(fVar9 * fVar9 + fVar12 * fVar12) * fVar3;
    }
    fVar4 = fVar4 + fVar14;
    fVar3 = fVar15 * fVar15 + fVar11 * fVar11;
    fVar9 = fVar4 / SQRT(fVar3);
    if (_DAT_14382e110 <= fVar3) {
      fVar15 = fVar9 * fVar15;
      fVar4 = fVar9 * fVar11;
    }
    else {
      fVar15 = 0.0;
    }
    fVar3 = unaff_RSI[2];
    *(ulonglong *)unaff_RDI = CONCAT44(unaff_RDI[1] + 0.0,fVar4 + fVar5);
    fVar5 = *unaff_RSI;
    unaff_RDI[2] = fVar15 + fVar1;
    fVar1 = (float)((uint)fVar5 & uVar13);
    if ((float)((uint)fVar5 & uVar13) <= (float)((uint)fVar3 & uVar13)) {
      fVar1 = (float)((uint)fVar3 & uVar13);
    }
    fVar4 = fVar5 * (fVar2 / fVar1);
    fVar9 = fVar3 * (fVar2 / fVar1);
    if ((0.0 < fVar1) &&
       (fVar1 = SQRT(fVar9 * fVar9 + fVar4 * fVar4) * fVar1, _DAT_143830ee8 <= fVar1)) {
      fVar2 = *(float *)(unaff_RBX + 0x51c) - fVar1;
      if (fVar2 <= 0.0) {
        fVar2 = 0.0;
      }
      if (fVar14 <= fVar2) {
        fVar2 = fVar14;
      }
      fVar2 = (fVar2 + fVar1) / fVar1;
    }
    *unaff_RSI = fVar5 * fVar2;
    unaff_RSI[2] = fVar3 * fVar2;
  }
  return;
}


/* SwingRegion_140abf9c4 @ 0x140abf9c4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abf9c4(void)

{
  undefined8 uVar1;
  longlong unaff_RBX;
  undefined8 *unaff_RBP;
  float *unaff_RSI;
  float *unaff_RDI;
  float *unaff_R12;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float unaff_XMM9_Da;
  float fVar12;
  uint uVar13;
  undefined4 unaff_XMM9_Db;
  float unaff_XMM10_Da;
  float unaff_XMM12_Da;
  float fVar14;
  float unaff_XMM13_Da;
  float fVar15;
  float unaff_XMM14_Da;
  float unaff_XMM15_Da;
  float fStackX_20;
  float in_stack_00000120;
  float in_stack_00000128;
  
  fVar7 = _DAT_14384002c;
  fVar11 = _DAT_14382dce0;
  if (unaff_XMM10_Da <= unaff_XMM9_Da) {
    if (unaff_XMM10_Da < unaff_XMM9_Da - unaff_XMM13_Da) {
      fVar4 = ((unaff_XMM9_Da - unaff_XMM10_Da) - unaff_XMM15_Da) * _DAT_1438564c4;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0;
      }
      if (_DAT_14382dce0 <= fVar4) {
        fVar4 = _DAT_14382dce0;
      }
      uVar6 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x498),
                                  fVar4 * _DAT_143830120 + unaff_XMM13_Da,
                                  CONCAT44(unaff_XMM9_Db,fVar4 * _DAT_14384002c + _DAT_14382f0e4),
                                  in_stack_00000128);
      *(undefined4 *)(unaff_RBX + 0x498) = uVar6;
      unaff_XMM9_Da = (float)func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x494));
      *(float *)(unaff_RBX + 0x494) = unaff_XMM9_Da;
    }
  }
  else {
    *(float *)(unaff_RBX + 0x494) = unaff_XMM10_Da;
    *(undefined4 *)(unaff_RBX + 0x498) = 0;
    unaff_XMM9_Da = unaff_XMM10_Da;
  }
  uVar1 = *unaff_RBP;
  fVar8 = *(float *)(unaff_RBP + 1);
  fVar15 = (float)((ulonglong)uVar1 >> 0x20);
  fVar4 = *(float *)((longlong)unaff_RBP + 4);
  fVar2 = unaff_R12[1];
  *(undefined8 *)unaff_RDI = uVar1;
  fVar3 = _DAT_14382e118;
  fVar12 = fVar2;
  if (fVar2 <= fVar4) {
    fVar12 = fVar4;
  }
  unaff_RDI[2] = fVar8;
  uVar13 = _DAT_14382e160;
  fVar10 = _DAT_14382e120;
  if (fVar12 < unaff_XMM9_Da) {
    fVar2 = (unaff_XMM12_Da - _DAT_143837a20) * _DAT_14382f0e0;
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    if (fVar11 <= fVar2) {
      fVar2 = fVar11;
    }
    if (unaff_XMM12_Da <= _DAT_143830118) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = (unaff_XMM9_Da - fVar4) / unaff_XMM12_Da;
      if (fVar3 <= 0.0) {
        fVar3 = 0.0;
      }
    }
    fVar12 = ((unaff_XMM9_Da - fVar4) - fVar11) * _DAT_143836d0c;
    if (fVar12 <= 0.0) {
      fVar12 = 0.0;
    }
    if (fVar11 <= fVar12) {
      fVar12 = fVar11;
    }
    fVar2 = fVar12 * (fVar11 - fVar2) * unaff_XMM15_Da + fVar11;
    if (fVar2 <= fVar3) {
      fVar2 = fVar3;
    }
    if (_DAT_14382f0e0 <= fVar2) {
      fVar2 = _DAT_14382f0e0;
    }
    fVar2 = (float)func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x4a0),fVar2,_DAT_1438ac3f4,
                                       in_stack_00000128);
    uVar13 = _DAT_14382e160;
    fVar3 = *(float *)(unaff_RBX + 0x494) - fVar4;
    *(float *)(unaff_RBX + 0x4a0) = fVar2;
    fVar2 = fVar2 * in_stack_00000128 + fVar4;
    if ((fVar2 - unaff_RDI[1] < fVar3) && (in_stack_00000128 * unaff_RSI[1] < 0.0)) {
      fVar3 = fVar3 - (fVar2 - unaff_RDI[1]);
      fVar12 = (float)((uint)(in_stack_00000128 * unaff_RSI[1]) & uVar13);
      if (fVar3 <= fVar12) {
        fVar12 = fVar3;
      }
      fVar2 = fVar2 + fVar12;
    }
    fVar4 = (fVar2 - fVar4) / in_stack_00000128;
    if (fVar4 <= *(float *)(unaff_RBX + 0x49c)) {
      fVar4 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x49c),fVar4,fVar7,in_stack_00000128
                                        );
    }
    *(float *)(unaff_RBX + 0x49c) = fVar4;
    unaff_RDI[1] = fVar4 * in_stack_00000128 + unaff_RDI[1];
    goto LAB_140abfe2c;
  }
  if (0.0 <= fVar4 - fVar2) {
LAB_140abfd63:
    if (fVar3 < (float)((uint)*(float *)(unaff_RBX + 0x49c) & uVar13)) {
      fVar10 = (*(float *)(unaff_RBX + 0x49c) - _DAT_14382f0e0) * fVar10;
      if (fVar10 <= 0.0) {
        fVar10 = 0.0;
      }
      if (fVar11 <= fVar10) {
        fVar10 = fVar11;
      }
      fVar7 = (float)FUN_140876340();
      fVar7 = fVar7 * _DAT_1438cea6c - _DAT_1438b4f48;
      fVar4 = fVar10 * _DAT_1438cea60 + _DAT_14383f374;
      if (fVar7 <= 0.0) {
        fVar7 = 0.0;
      }
      if (fVar11 <= fVar7) {
        fVar7 = fVar11;
      }
      uVar5 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x49c),0,
                                  (_DAT_14384002c - fVar4) * fVar7 + fVar4,in_stack_00000128);
      *(uint *)(unaff_RBX + 0x49c) = uVar5;
      unaff_RDI[1] = (float)(uVar5 & uVar13) * in_stack_00000128 + unaff_RDI[1];
    }
  }
  else {
    fVar12 = (float)func_0x000141c58730(in_stack_00000120 * _DAT_14382e11c);
    fVar2 = (float)((uint)(fVar4 - fVar2) & uVar13);
    fVar7 = *(float *)(unaff_RBX + 0x494);
    fVar4 = ((fVar7 - fVar15) / unaff_RSI[1] - fVar10) * _DAT_1438388c4;
    if (fVar4 <= 0.0) {
      fVar4 = 0.0;
    }
    if (fVar11 <= fVar4) {
      fVar4 = fVar11;
    }
    fVar3 = _DAT_14382e118;
    if (fVar7 <= *(float *)(unaff_RBX + 0x448) - fVar12 * unaff_XMM14_Da) goto LAB_140abfd63;
    fVar3 = (float)FUN_143667c70(((fVar11 - fVar4) * _DAT_14382ee94 - _DAT_143830120) *
                                 in_stack_00000128);
    fVar7 = (fVar11 - fVar3) * (unaff_R12[1] - fVar7);
    fVar4 = (float)FUN_143667c70((_DAT_14386d9b0 - (fVar11 - fVar4) * _DAT_1438794d0) *
                                 in_stack_00000128);
    fVar4 = fVar4 * fVar2;
    if (fVar4 <= fVar7) {
      fVar7 = fVar4;
    }
    fVar2 = fVar2 - fVar7;
    fVar4 = fVar2 / in_stack_00000128;
    unaff_RDI[1] = fVar2 + unaff_RDI[1];
    *(float *)(unaff_RBX + 0x49c) = fVar4;
    fVar7 = unaff_RSI[1];
    if (fVar7 < 0.0) {
      fVar2 = (float)((uint)fVar7 & uVar13) * _DAT_143848d00;
      fVar4 = fVar4 * _DAT_143854044 * in_stack_00000128;
      if (fVar4 <= fVar2) {
        fVar2 = fVar4;
      }
      unaff_RSI[1] = fVar2 + fVar7;
    }
  }
  uVar6 = func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x4a0),0,_DAT_1438ac3f4,in_stack_00000128)
  ;
  *(undefined4 *)(unaff_RBX + 0x4a0) = uVar6;
LAB_140abfe2c:
  fStackX_20 = (float)uVar1;
  fVar7 = unaff_R12[2];
  fVar15 = fVar15 - unaff_R12[1];
  fVar4 = *unaff_R12;
  fVar8 = fVar8 - fVar7;
  fVar3 = (float)((uint)fVar15 & uVar13);
  fVar2 = (float)((uint)fVar8 & uVar13);
  if (fVar2 <= fVar3) {
    fVar2 = fVar3;
  }
  fVar3 = (float)((uint)(fStackX_20 - fVar4) & uVar13);
  if (fVar2 <= fVar3) {
    fVar2 = fVar3;
  }
  fVar10 = fVar11 / fVar2;
  fVar3 = fVar10 * (fStackX_20 - fVar4);
  fVar12 = 0.0;
  fVar15 = fVar10 * fVar15;
  fVar10 = fVar10 * fVar8;
  if (0.0 < fVar2) {
    fVar12 = SQRT(fVar15 * fVar15 + fVar3 * fVar3 + fVar10 * fVar10) * fVar2;
  }
  fVar10 = *unaff_RDI - fVar4;
  fVar3 = unaff_RDI[1] - unaff_R12[1];
  fVar15 = unaff_RDI[2] - fVar7;
  fVar14 = (float)((uint)fVar10 & uVar13);
  fVar8 = (float)((uint)fVar3 & uVar13);
  fVar2 = (float)((uint)fVar15 & uVar13);
  if (fVar8 <= fVar2) {
    fVar8 = fVar2;
  }
  if (fVar8 <= fVar14) {
    fVar8 = fVar14;
  }
  fVar9 = fVar11 / fVar8;
  fVar3 = fVar9 * fVar3;
  if (fVar8 <= 0.0) {
    fVar8 = 0.0;
  }
  else {
    fVar8 = SQRT(fVar3 * fVar3 + fVar9 * fVar10 * fVar9 * fVar10 + fVar9 * fVar15 * fVar9 * fVar15)
            * fVar8;
  }
  if (fVar8 < fVar12 - _DAT_14382e118) {
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    fVar3 = 0.0;
    if (fVar2 <= fVar14) {
      fVar2 = fVar14;
    }
    fVar14 = (fVar12 - fVar8) * _DAT_14382e130;
    fVar8 = (fVar11 / fVar2) * fVar15;
    fVar12 = (fVar11 / fVar2) * fVar10;
    if (0.0 < fVar2) {
      fVar3 = SQRT(fVar8 * fVar8 + fVar12 * fVar12) * fVar2;
    }
    fVar3 = fVar3 + fVar14;
    fVar2 = fVar15 * fVar15 + fVar10 * fVar10;
    fVar8 = fVar3 / SQRT(fVar2);
    if (_DAT_14382e110 <= fVar2) {
      fVar15 = fVar8 * fVar15;
      fVar3 = fVar8 * fVar10;
    }
    else {
      fVar15 = 0.0;
    }
    fVar2 = unaff_RSI[2];
    *(ulonglong *)unaff_RDI = CONCAT44(unaff_RDI[1] + 0.0,fVar3 + fVar4);
    fVar4 = *unaff_RSI;
    unaff_RDI[2] = fVar15 + fVar7;
    fVar7 = (float)((uint)fVar4 & uVar13);
    if ((float)((uint)fVar4 & uVar13) <= (float)((uint)fVar2 & uVar13)) {
      fVar7 = (float)((uint)fVar2 & uVar13);
    }
    fVar3 = fVar4 * (fVar11 / fVar7);
    fVar8 = fVar2 * (fVar11 / fVar7);
    if ((0.0 < fVar7) &&
       (fVar7 = SQRT(fVar8 * fVar8 + fVar3 * fVar3) * fVar7, _DAT_143830ee8 <= fVar7)) {
      fVar11 = *(float *)(unaff_RBX + 0x51c) - fVar7;
      if (fVar11 <= 0.0) {
        fVar11 = 0.0;
      }
      if (fVar14 <= fVar11) {
        fVar11 = fVar14;
      }
      fVar11 = (fVar11 + fVar7) / fVar7;
    }
    *unaff_RSI = fVar4 * fVar11;
    unaff_RSI[2] = fVar2 * fVar11;
  }
  return;
}


/* SwingRegion_140abfae0 @ 0x140abfae0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abfae0(void)

{
  uint uVar1;
  longlong unaff_RBX;
  float *unaff_RSI;
  float *unaff_RDI;
  float *unaff_R12;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float fVar9;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  float unaff_XMM12_Da;
  float fVar10;
  float unaff_XMM13_Da;
  float fVar11;
  float unaff_XMM15_Da;
  float fStackX_20;
  float in_stack_00000028;
  
  fVar2 = (unaff_XMM12_Da - _DAT_143837a20) * _DAT_14382f0e0;
  if (fVar2 <= unaff_XMM8_Da) {
    fVar2 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= fVar2) {
    fVar2 = unaff_XMM7_Da;
  }
  if (unaff_XMM12_Da <= _DAT_143830118) {
    fVar3 = 0.0;
  }
  else {
    fVar3 = (unaff_XMM9_Da - unaff_XMM10_Da) / unaff_XMM12_Da;
    if (fVar3 <= unaff_XMM8_Da) {
      fVar3 = unaff_XMM8_Da;
    }
  }
  fVar9 = ((unaff_XMM9_Da - unaff_XMM10_Da) - unaff_XMM7_Da) * _DAT_143836d0c;
  if (fVar9 <= unaff_XMM8_Da) {
    fVar9 = unaff_XMM8_Da;
  }
  if (unaff_XMM7_Da <= fVar9) {
    fVar9 = unaff_XMM7_Da;
  }
  fVar2 = fVar9 * (unaff_XMM7_Da - fVar2) * unaff_XMM15_Da + unaff_XMM7_Da;
  if (fVar2 <= fVar3) {
    fVar2 = fVar3;
  }
  if (_DAT_14382f0e0 <= fVar2) {
    fVar2 = _DAT_14382f0e0;
  }
  fVar2 = (float)func_0x000141c477e0(*(undefined4 *)(unaff_RBX + 0x4a0),fVar2,_DAT_1438ac3f4);
  uVar1 = _DAT_14382e160;
  fVar3 = *(float *)(unaff_RBX + 0x494) - unaff_XMM10_Da;
  *(float *)(unaff_RBX + 0x4a0) = fVar2;
  fVar2 = fVar2 * unaff_XMM11_Da + unaff_XMM10_Da;
  if ((fVar2 - unaff_RDI[1] < fVar3) && (unaff_XMM11_Da * unaff_RSI[1] < unaff_XMM8_Da)) {
    fVar3 = fVar3 - (fVar2 - unaff_RDI[1]);
    fVar9 = (float)((uint)(unaff_XMM11_Da * unaff_RSI[1]) & uVar1);
    if (fVar3 <= fVar9) {
      fVar9 = fVar3;
    }
    fVar2 = fVar2 + fVar9;
  }
  fVar2 = (fVar2 - unaff_XMM10_Da) / unaff_XMM11_Da;
  if (fVar2 <= *(float *)(unaff_RBX + 0x49c)) {
    fVar2 = (float)func_0x000141c477e0(*(float *)(unaff_RBX + 0x49c),fVar2);
  }
  *(float *)(unaff_RBX + 0x49c) = fVar2;
  unaff_RDI[1] = fVar2 * unaff_XMM11_Da + unaff_RDI[1];
  fVar2 = unaff_R12[2];
  fVar11 = unaff_XMM13_Da - unaff_R12[1];
  fVar3 = *unaff_R12;
  fVar4 = (float)((uint)fVar11 & uVar1);
  fVar9 = (float)((uint)(in_stack_00000028 - fVar2) & uVar1);
  if (fVar9 <= fVar4) {
    fVar9 = fVar4;
  }
  fVar4 = (float)((uint)(fStackX_20 - fVar3) & uVar1);
  if (fVar9 <= fVar4) {
    fVar9 = fVar4;
  }
  fVar7 = unaff_XMM7_Da / fVar9;
  fVar4 = fVar7 * (fStackX_20 - fVar3);
  fVar6 = 0.0;
  fVar11 = fVar7 * fVar11;
  fVar7 = fVar7 * (in_stack_00000028 - fVar2);
  if (unaff_XMM8_Da < fVar9) {
    fVar6 = SQRT(fVar11 * fVar11 + fVar4 * fVar4 + fVar7 * fVar7) * fVar9;
  }
  fVar8 = *unaff_RDI - fVar3;
  fVar11 = unaff_RDI[1] - unaff_R12[1];
  fVar7 = unaff_RDI[2] - fVar2;
  fVar10 = (float)((uint)fVar8 & uVar1);
  fVar4 = (float)((uint)fVar11 & uVar1);
  fVar9 = (float)((uint)fVar7 & uVar1);
  if (fVar4 <= fVar9) {
    fVar4 = fVar9;
  }
  if (fVar4 <= fVar10) {
    fVar4 = fVar10;
  }
  fVar5 = unaff_XMM7_Da / fVar4;
  fVar11 = fVar5 * fVar11;
  if (fVar4 <= unaff_XMM8_Da) {
    fVar4 = 0.0;
  }
  else {
    fVar4 = SQRT(fVar11 * fVar11 + fVar5 * fVar8 * fVar5 * fVar8 + fVar5 * fVar7 * fVar5 * fVar7) *
            fVar4;
  }
  if (fVar4 < fVar6 - _DAT_14382e118) {
    if (fVar9 <= unaff_XMM8_Da) {
      fVar9 = unaff_XMM8_Da;
    }
    fVar11 = 0.0;
    if (fVar9 <= fVar10) {
      fVar9 = fVar10;
    }
    fVar10 = (fVar6 - fVar4) * _DAT_14382e130;
    fVar4 = (unaff_XMM7_Da / fVar9) * fVar7;
    fVar6 = (unaff_XMM7_Da / fVar9) * fVar8;
    if (unaff_XMM8_Da < fVar9) {
      fVar11 = SQRT(fVar4 * fVar4 + fVar6 * fVar6) * fVar9;
    }
    fVar11 = fVar11 + fVar10;
    fVar9 = fVar7 * fVar7 + fVar8 * fVar8;
    fVar4 = fVar11 / SQRT(fVar9);
    if (_DAT_14382e110 <= fVar9) {
      fVar7 = fVar4 * fVar7;
      fVar11 = fVar4 * fVar8;
    }
    else {
      fVar7 = 0.0;
    }
    fVar9 = unaff_RSI[2];
    *(ulonglong *)unaff_RDI = CONCAT44(unaff_RDI[1] + 0.0,fVar11 + fVar3);
    fVar3 = *unaff_RSI;
    unaff_RDI[2] = fVar7 + fVar2;
    fVar2 = (float)((uint)fVar3 & uVar1);
    if ((float)((uint)fVar3 & uVar1) <= (float)((uint)fVar9 & uVar1)) {
      fVar2 = (float)((uint)fVar9 & uVar1);
    }
    fVar11 = fVar3 * (unaff_XMM7_Da / fVar2);
    fVar4 = fVar9 * (unaff_XMM7_Da / fVar2);
    if ((unaff_XMM8_Da < fVar2) &&
       (fVar2 = SQRT(fVar4 * fVar4 + fVar11 * fVar11) * fVar2, _DAT_143830ee8 <= fVar2)) {
      fVar4 = *(float *)(unaff_RBX + 0x51c) - fVar2;
      if (fVar4 <= unaff_XMM8_Da) {
        fVar4 = unaff_XMM8_Da;
      }
      if (fVar10 <= fVar4) {
        fVar4 = fVar10;
      }
      unaff_XMM7_Da = (fVar4 + fVar2) / fVar2;
    }
    *unaff_RSI = fVar3 * unaff_XMM7_Da;
    unaff_RSI[2] = fVar9 * unaff_XMM7_Da;
  }
  return;
}


/* SwingRegion_140abfea4 @ 0x140abfea4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abfea4(float param_1,float param_2)

{
  longlong unaff_RBX;
  float *unaff_RSI;
  float *unaff_RDI;
  float fVar1;
  float fVar2;
  float fVar3;
  float in_XMM4_Da;
  float fVar4;
  float in_XMM5_Da;
  float fVar5;
  float unaff_XMM6_Da;
  float fVar6;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  uint unaff_XMM9_Da;
  float fVar7;
  float fVar8;
  float unaff_XMM14_Da;
  float unaff_XMM15_Da;
  
  fVar3 = SQRT(param_1 * param_1 + param_2 * param_2 + in_XMM4_Da * in_XMM4_Da) * in_XMM5_Da;
  fVar5 = *unaff_RDI - unaff_XMM14_Da;
  fVar1 = unaff_RDI[1] - unaff_XMM6_Da;
  fVar6 = unaff_RDI[2] - unaff_XMM15_Da;
  fVar8 = (float)((uint)fVar5 & unaff_XMM9_Da);
  fVar7 = (float)((uint)fVar1 & unaff_XMM9_Da);
  fVar4 = (float)((uint)fVar6 & unaff_XMM9_Da);
  if (fVar7 <= fVar4) {
    fVar7 = fVar4;
  }
  if (fVar7 <= fVar8) {
    fVar7 = fVar8;
  }
  fVar2 = unaff_XMM7_Da / fVar7;
  fVar1 = fVar2 * fVar1;
  if (fVar7 <= unaff_XMM8_Da) {
    fVar7 = 0.0;
  }
  else {
    fVar7 = SQRT(fVar1 * fVar1 + fVar2 * fVar5 * fVar2 * fVar5 + fVar2 * fVar6 * fVar2 * fVar6) *
            fVar7;
  }
  if (fVar7 < fVar3 - _DAT_14382e118) {
    if (fVar4 <= unaff_XMM8_Da) {
      fVar4 = unaff_XMM8_Da;
    }
    fVar1 = 0.0;
    if (fVar4 <= fVar8) {
      fVar4 = fVar8;
    }
    fVar8 = (fVar3 - fVar7) * _DAT_14382e130;
    fVar7 = (unaff_XMM7_Da / fVar4) * fVar6;
    fVar3 = (unaff_XMM7_Da / fVar4) * fVar5;
    if (unaff_XMM8_Da < fVar4) {
      fVar1 = SQRT(fVar7 * fVar7 + fVar3 * fVar3) * fVar4;
    }
    fVar1 = fVar1 + fVar8;
    fVar4 = fVar6 * fVar6 + fVar5 * fVar5;
    fVar7 = fVar1 / SQRT(fVar4);
    if (_DAT_14382e110 <= fVar4) {
      fVar6 = fVar7 * fVar6;
      fVar1 = fVar7 * fVar5;
    }
    else {
      fVar6 = 0.0;
    }
    fVar4 = unaff_RSI[2];
    *(ulonglong *)unaff_RDI = CONCAT44(unaff_RDI[1] + 0.0,fVar1 + unaff_XMM14_Da);
    fVar7 = *unaff_RSI;
    unaff_RDI[2] = fVar6 + unaff_XMM15_Da;
    fVar1 = (float)((uint)fVar7 & unaff_XMM9_Da);
    if ((float)((uint)fVar7 & unaff_XMM9_Da) <= (float)((uint)fVar4 & unaff_XMM9_Da)) {
      fVar1 = (float)((uint)fVar4 & unaff_XMM9_Da);
    }
    fVar6 = fVar7 * (unaff_XMM7_Da / fVar1);
    fVar3 = fVar4 * (unaff_XMM7_Da / fVar1);
    if ((unaff_XMM8_Da < fVar1) &&
       (fVar1 = SQRT(fVar3 * fVar3 + fVar6 * fVar6) * fVar1, _DAT_143830ee8 <= fVar1)) {
      fVar3 = *(float *)(unaff_RBX + 0x51c) - fVar1;
      if (fVar3 <= unaff_XMM8_Da) {
        fVar3 = unaff_XMM8_Da;
      }
      if (fVar8 <= fVar3) {
        fVar3 = fVar8;
      }
      unaff_XMM7_Da = (fVar3 + fVar1) / fVar1;
    }
    *unaff_RSI = fVar7 * unaff_XMM7_Da;
    unaff_RSI[2] = fVar4 * unaff_XMM7_Da;
  }
  return;
}


/* SwingRegion_140abff6e @ 0x140abff6e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140abff6e(undefined8 param_1,undefined8 param_2,float param_3,float param_4)

{
  longlong unaff_RBX;
  float *unaff_RSI;
  undefined8 *unaff_RDI;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float in_XMM4_Da;
  float in_XMM5_Da;
  float unaff_XMM6_Da;
  float unaff_XMM7_Da;
  float unaff_XMM8_Da;
  uint unaff_XMM9_Da;
  float unaff_XMM12_Da;
  float unaff_XMM13_Da;
  float unaff_XMM14_Da;
  float unaff_XMM15_Da;
  
  if (in_XMM4_Da <= unaff_XMM8_Da) {
    in_XMM4_Da = unaff_XMM8_Da;
  }
  fVar4 = 0.0;
  if (in_XMM4_Da <= unaff_XMM12_Da) {
    in_XMM4_Da = unaff_XMM12_Da;
  }
  fVar6 = (param_4 - param_3) * _DAT_14382e130;
  fVar1 = (unaff_XMM7_Da / in_XMM4_Da) * unaff_XMM6_Da;
  fVar3 = (unaff_XMM7_Da / in_XMM4_Da) * in_XMM5_Da;
  if (unaff_XMM8_Da < in_XMM4_Da) {
    fVar4 = SQRT(fVar1 * fVar1 + fVar3 * fVar3) * in_XMM4_Da;
  }
  fVar4 = fVar4 + fVar6;
  fVar1 = unaff_XMM6_Da * unaff_XMM6_Da + in_XMM5_Da * in_XMM5_Da;
  fVar3 = fVar4 / SQRT(fVar1);
  if (_DAT_14382e110 <= fVar1) {
    fVar1 = fVar3 * unaff_XMM6_Da;
    fVar4 = fVar3 * in_XMM5_Da;
  }
  else {
    fVar1 = 0.0;
  }
  fVar3 = unaff_RSI[2];
  *unaff_RDI = CONCAT44(unaff_XMM13_Da + 0.0,fVar4 + unaff_XMM14_Da);
  fVar4 = *unaff_RSI;
  *(float *)(unaff_RDI + 1) = fVar1 + unaff_XMM15_Da;
  fVar1 = (float)((uint)fVar4 & unaff_XMM9_Da);
  if ((float)((uint)fVar4 & unaff_XMM9_Da) <= (float)((uint)fVar3 & unaff_XMM9_Da)) {
    fVar1 = (float)((uint)fVar3 & unaff_XMM9_Da);
  }
  fVar5 = fVar4 * (unaff_XMM7_Da / fVar1);
  fVar2 = fVar3 * (unaff_XMM7_Da / fVar1);
  if ((unaff_XMM8_Da < fVar1) &&
     (fVar1 = SQRT(fVar2 * fVar2 + fVar5 * fVar5) * fVar1, _DAT_143830ee8 <= fVar1)) {
    fVar2 = *(float *)(unaff_RBX + 0x51c) - fVar1;
    if (fVar2 <= unaff_XMM8_Da) {
      fVar2 = unaff_XMM8_Da;
    }
    if (fVar6 <= fVar2) {
      fVar2 = fVar6;
    }
    unaff_XMM7_Da = (fVar2 + fVar1) / fVar1;
  }
  *unaff_RSI = fVar4 * unaff_XMM7_Da;
  unaff_RSI[2] = fVar3 * unaff_XMM7_Da;
  return;
}


/* SwingRegion_140ac00e0 @ 0x140ac00e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ac00e0(longlong param_1)

{
  bool bVar1;
  float fVar2;
  longlong *plVar3;
  longlong lVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float afStack_e8 [4];
  undefined8 uStack_d8;
  float fStack_d0;
  ulonglong uStack_c8;
  float fStack_c0;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  undefined1 auStack_98 [144];
  
  lVar4 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    plVar3 = (longlong *)FUN_14167ab40(lVar4 + 0x58,0x147c40bf0);
  }
  else {
    plVar3 = (longlong *)func_0x0001416799a0(lVar4 + 0x80);
  }
  (**(code **)(*plVar3 + 0x80))(plVar3,&fStack_b8,0);
  lVar4 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar4 + 0x88) == 0) {
    lVar4 = FUN_14167ab40(lVar4 + 0x58,0x146dad7c0);
  }
  else {
    lVar4 = func_0x0001416799a0(lVar4 + 0x80);
  }
  func_0x0001408732f0(lVar4,&fStack_b8);
  fVar2 = _DAT_14382dce0;
  fVar10 = (float)((uint)fStack_b8 & _DAT_14382e160);
  fVar8 = (float)((uint)fStack_b0 & _DAT_14382e160);
  fVar6 = fVar10;
  if (fVar10 <= fVar8) {
    fVar6 = fVar8;
  }
  fVar9 = 0.0;
  fVar7 = fStack_b8 * (_DAT_14382dce0 / fVar6);
  fVar5 = fStack_b0 * (_DAT_14382dce0 / fVar6);
  if (0.0 < fVar6) {
    fVar9 = SQRT(fVar5 * fVar5 + fVar7 * fVar7) * fVar6;
  }
  afStack_e8[2] = *(float *)(param_1 + 0x400);
  afStack_e8[0] = *(float *)(param_1 + 0x3f8);
  fVar6 = (float)((uint)afStack_e8[2] & _DAT_14382e160);
  afStack_e8[1] = 0.0;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  if (fVar6 <= (float)((uint)afStack_e8[0] & _DAT_14382e160)) {
    fVar6 = (float)((uint)afStack_e8[0] & _DAT_14382e160);
  }
  if (0.0 < fVar6) {
    afStack_e8[2] = (_DAT_14382dce0 / fVar6) * afStack_e8[2];
    afStack_e8[0] = (_DAT_14382dce0 / fVar6) * afStack_e8[0];
    fVar6 = _DAT_14382dce0 / SQRT(afStack_e8[2] * afStack_e8[2] + afStack_e8[0] * afStack_e8[0]);
    afStack_e8[2] = fVar6 * afStack_e8[2];
    afStack_e8[0] = fVar6 * afStack_e8[0];
  }
  if (_DAT_143830ee8 <= fVar9) {
    fStack_d0 = 0.0;
    if (0.0 <= fVar8) {
      fStack_d0 = fVar8;
    }
    if (fStack_d0 <= fVar10) {
      fStack_d0 = fVar10;
    }
    if (fStack_d0 <= 0.0) {
      uStack_d8 = (ulonglong)(uint)fStack_b8;
      fStack_d0 = fStack_b0;
    }
    else {
      fStack_d0 = _DAT_14382dce0 / fStack_d0;
      fStack_b8 = fStack_d0 * fStack_b8;
      fVar8 = fStack_d0 * 0.0;
      fStack_d0 = fStack_d0 * fStack_b0;
      fVar6 = _DAT_14382dce0 / SQRT(fVar8 * fVar8 + fStack_b8 * fStack_b8 + fStack_d0 * fStack_d0);
      fStack_d0 = fVar6 * fStack_d0;
      uStack_d8 = CONCAT44(fVar6 * fVar8,fVar6 * fStack_b8);
    }
  }
  else {
    uStack_d8 = (ulonglong)(uint)afStack_e8[0];
    fStack_d0 = afStack_e8[2];
  }
  uStack_c8 = uStack_d8;
  fStack_c0 = fStack_d0;
  FUN_14086c2a0(auStack_98,afStack_e8,&uStack_c8,param_1 + 0x418,(char *)(param_1 + 0x5f7));
  fVar6 = (float)func_0x000141c59090(&uStack_c8,auStack_98);
  fVar8 = fVar6 * _DAT_1438ac3c4 - _DAT_14386db58;
  fVar6 = (fVar9 - _DAT_14382f0e4) * _DAT_14386dc70;
  fVar10 = (*(float *)(param_1 + 0x424) - _DAT_14382e120) * _DAT_14384ebec;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  if (fVar8 <= 0.0) {
    fVar8 = 0.0;
  }
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  if (fVar2 <= fVar6) {
    fVar6 = fVar2;
  }
  if (fVar2 <= fVar8) {
    fVar8 = fVar2;
  }
  if (fVar2 <= fVar10) {
    fVar10 = fVar2;
  }
  if (*(char *)(param_1 + 0x5f7) == '\0') {
    fVar10 = fVar8 * (fVar2 - fVar6) * fVar10;
    fVar6 = fVar10 + (fVar2 - fVar10) * *(float *)(lVar4 + 0xe97c);
  }
  else {
    fVar6 = fVar2;
    if (_DAT_14383479c <= fVar9) {
      fVar9 = _DAT_14383479c;
    }
  }
  FUN_141c5b3e0(&fStack_a8,&uStack_c8,auStack_98,fVar6);
  bVar1 = _DAT_14382e118 <= fVar6;
  *(ulonglong *)(param_1 + 0x4b8) = CONCAT44(fStack_a4 * fVar9 + fStack_b4,fStack_a8 * fVar9);
  *(float *)(param_1 + 0x4c0) = fStack_a0 * fVar9;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x50c) = 0;
  }
  else {
    *(float *)(param_1 + 0x50c) = fVar2;
  }
  return;
}


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
  
  uVar1 = _DAT_14382e160;
  fVar14 = _DAT_14382dce0;
  fVar15 = *(float *)(param_1 + 0x440) - param_4[2];
  fVar18 = *(float *)(param_1 + 0x438) - *param_4;
  fVar20 = *(float *)(param_1 + 0x43c) - param_4[1];
  fVar13 = (float)((uint)fVar15 & _DAT_14382e160);
  if ((float)((uint)fVar15 & _DAT_14382e160) <= (float)((uint)fVar20 & _DAT_14382e160)) {
    fVar13 = (float)((uint)fVar20 & _DAT_14382e160);
  }
  if (fVar13 <= (float)((uint)fVar18 & _DAT_14382e160)) {
    fVar13 = (float)((uint)fVar18 & _DAT_14382e160);
  }
  fVar16 = fVar20;
  if (0.0 < fVar13) {
    fVar13 = _DAT_14382dce0 / fVar13;
    fVar15 = fVar13 * fVar15;
    fVar18 = fVar13 * fVar18;
    fVar13 = fVar13 * fVar20;
    fVar16 = _DAT_14382dce0 / SQRT(fVar13 * fVar13 + fVar18 * fVar18 + fVar15 * fVar15);
    fVar18 = fVar16 * fVar18;
    fVar15 = fVar16 * fVar15;
    fVar16 = fVar16 * fVar13;
  }
  FUN_1402d0740(&fStack_e8,param_3);
  uVar2 = _DAT_14382e890;
  fVar11 = (float)((uint)fVar18 ^ _DAT_14382e890);
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
  if (_DAT_14382e110 <= fVar5) {
    fVar17 = fVar17 * fVar4;
    fVar19 = fVar12 * fVar4;
    fVar4 = fVar4 * fStack_d4;
  }
  else {
    fVar4 = 0.0;
    fVar17 = 0.0;
  }
  if (_DAT_143830ee8 <= fVar6 * fVar6 + fVar13 * fVar13) {
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
  if (fVar13 < _DAT_14384e300) {
    fVar13 = (float)((uint)fVar13 & uVar1);
    if (_DAT_143836d08 <= fVar13) {
      fVar13 = (fVar13 - _DAT_143836d08) * _DAT_143880d88;
      if (fVar13 <= 0.0) {
        fVar13 = 0.0;
      }
      if (fVar14 <= fVar13) {
        fVar13 = fVar14;
      }
      fVar14 = fVar13 * _DAT_1438ac3a4 + _DAT_143837a24;
    }
    else {
      fVar13 = (fVar13 - _DAT_14382e120) * _DAT_1438ac768;
      if (fVar13 <= 0.0) {
        fVar13 = 0.0;
      }
      if (fVar14 <= fVar13) {
        fVar13 = fVar14;
      }
      fVar14 = fVar14 - fVar13 * _DAT_1438ac3a4;
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
  uVar4 = _DAT_14382e160;
  fVar11 = _DAT_14382e128;
  fVar3 = _DAT_14382dce0;
  lVar2 = *(longlong *)(param_1 + 0x388);
  fVar6 = fVar6 * _DAT_143855568;
  fVar10 = *(float *)(lVar2 + 0x1c);
  fVar7 = *(float *)(lVar2 + 0x20) - fVar10;
  if ((float)((uint)fVar7 & _DAT_14382e160) <= _DAT_14382e118) {
    if (fVar10 <= fVar6) {
      fVar7 = _DAT_14382e128;
      if (fVar10 < fVar6) {
        fVar7 = _DAT_14382dce0;
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
    if (_DAT_14382dce0 <= fVar7) {
      fVar7 = _DAT_14382dce0;
    }
  }
  fVar10 = *(float *)(lVar2 + 0x24);
  fVar6 = *(float *)(lVar2 + 0x28) - fVar10;
  if ((float)((uint)fVar6 & _DAT_14382e160) <= _DAT_14382e118) {
    if (fVar10 <= param_4) {
      fVar6 = _DAT_14382e128;
      if (fVar10 < param_4) {
        fVar6 = _DAT_14382dce0;
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
    if (_DAT_14382dce0 <= fVar6) {
      fVar6 = _DAT_14382dce0;
    }
  }
  fVar10 = *(float *)(lVar2 + 0x2c);
  fVar8 = *(float *)(lVar2 + 0x30) - fVar10;
  if ((float)((uint)fVar8 & _DAT_14382e160) <= _DAT_14382e118) {
    if (fVar10 <= fVar5) {
      fVar8 = _DAT_14382e128;
      if (fVar10 < fVar5) {
        fVar8 = _DAT_14382dce0;
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
    if (_DAT_14382dce0 <= fVar8) {
      fVar8 = _DAT_14382dce0;
    }
  }
  fVar10 = *(float *)(lVar2 + 0x34);
  fVar9 = *(float *)(lVar2 + 0x38) - fVar10;
  if ((float)((uint)fVar9 & _DAT_14382e160) <= _DAT_14382e118) {
    if (fVar10 <= fVar5) {
      fVar9 = _DAT_14382e128;
      if (fVar10 < fVar5) {
        fVar9 = _DAT_14382dce0;
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
    if (_DAT_14382dce0 <= fVar9) {
      fVar9 = _DAT_14382dce0;
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
    if (_DAT_1438388d0 <= param_5) {
      fVar10 = *(float *)(lVar2 + 0x68);
      fVar6 = *(float *)(lVar2 + 0x6c) - fVar10;
      if ((float)((uint)fVar6 & _DAT_14382e160) <= _DAT_14382e118) {
        if (fVar10 <= param_5) {
          fVar6 = _DAT_14382e128;
          if (fVar10 < param_5) {
            fVar6 = _DAT_14382dce0;
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
        if (_DAT_14382dce0 <= fVar6) {
          fVar6 = _DAT_14382dce0;
        }
      }
      fVar5 = fVar5 * ((*(float *)(lVar2 + 100) - _DAT_14382dce0) * fVar6 + _DAT_14382dce0);
    }
    else {
      fVar10 = (param_5 - _DAT_143830120) * _DAT_1438398cc;
      if (fVar10 <= 0.0) {
        fVar10 = 0.0;
      }
      if (_DAT_14382dce0 <= fVar10) {
        fVar10 = _DAT_14382dce0;
      }
      fVar5 = fVar5 - (fVar5 + _DAT_1438794d0) * fVar10;
    }
  }
  else if (*(int *)(param_1 + 0x574) == 2) {
    fVar5 = *(float *)(param_1 + 0x4b4);
  }
  else {
    fVar10 = (param_3 - _DAT_1438ad6d4) * _DAT_1438ac378;
    if (fVar10 <= 0.0) {
      fVar10 = 0.0;
    }
    if (_DAT_14382dce0 <= fVar10) {
      fVar10 = _DAT_14382dce0;
    }
    fVar5 = (float)FUN_1420dc660(param_1);
    fVar5 = (fVar5 - _DAT_14382e124) * _DAT_143834a14;
    if (fVar5 <= 0.0) {
      fVar5 = 0.0;
    }
    if (fVar3 <= fVar5) {
      fVar5 = fVar3;
    }
    fVar5 = (*(float *)(param_1 + 0x4b0) - *(float *)(param_1 + 0x4ac)) * fVar5 +
            *(float *)(param_1 + 0x4ac);
    fVar5 = fVar5 - (fVar5 + _DAT_1438312b0) * fVar10;
  }
  iVar1 = *(int *)(param_1 + 0x574);
  fVar10 = fVar5;
  if (_DAT_14383f72c <= fVar5) {
    fVar10 = _DAT_14383f72c;
  }
  fVar10 = (fVar5 - fVar10) * *(float *)(param_1 + 0x510) + fVar10;
  if (iVar1 != 0) {
    fVar5 = fVar10;
    if (((0.0 < *(float *)(param_2 + 4)) && (*(float *)(param_1 + 0x430) < 0.0)) &&
       (fVar8 = (float)((uint)*(float *)(param_1 + 0x430) & uVar4), fVar5 = fVar8 * _DAT_1438388cc,
       fVar6 = _DAT_14386d9b0 - fVar5,
       fVar5 = ((((_DAT_1438acf84 - fVar5) - fVar6) * fVar7 + fVar6) - fVar10) * fVar8 + fVar10,
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
    else if ((iVar1 == 2) && (fVar10 = _DAT_1438862e0, 0.0 < *(float *)(param_2 + 4))) {
      fVar10 = _DAT_1438cea70;
    }
  }
  return fVar10;
}


/* SwingRegion_140ac0ff0 @ 0x140ac0ff0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_140ac0ff0(longlong param_1,char param_2,undefined8 param_3,longlong param_4,float param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  undefined4 auStackX_8 [2];
  
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    uVar1 = FUN_14167ab40(lVar2 + 0x58,0x146dd6340);
  }
  else {
    uVar1 = func_0x0001416799a0(lVar2 + 0x80);
  }
  lVar2 = func_0x000140923770(uVar1);
  if (*(float *)(param_4 + 4) <= _DAT_143830ee8) {
    param_5 = 0.0;
  }
  else {
    param_5 = *(float *)(param_4 + 4) / param_5;
  }
  fVar8 = (float)FUN_140876340(param_1 + 0x4d0);
  lVar3 = *(longlong *)(param_1 + 8);
  fVar8 = fVar8 * _DAT_143855568;
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x147c40bf0);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  if (*(float *)(lVar2 + 0x1c0) <= fVar8) {
    if (*(float *)(lVar2 + 0x1c4) <= fVar8) {
      if (fVar8 < *(float *)(lVar2 + 0x1c8) || fVar8 == *(float *)(lVar2 + 0x1c8)) {
        if ((param_5 <= _DAT_14382dce0) || (DAT_145d9fe7e == '\0')) {
          iVar7 = 0x6466fa89;
          iVar6 = 0x6b092d6d;
        }
        else {
          iVar7 = 0x4dc416b4;
          iVar6 = -0x5591c871;
        }
        if (param_2 != '\0') {
          puVar4 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
          lVar2 = FUN_1416d5e80(0x147475690,0xe5b5a000,*puVar4,0,0,0,0,0,1,0,0,0,0);
          *(undefined1 *)(lVar2 + 0x138) = 1;
          *(undefined4 *)(lVar2 + 0x13c) = 1;
          goto LAB_140ac1379;
        }
        puVar4 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
        lVar2 = FUN_1416d5e80(0x147475690,0xa8c72762,*puVar4,0,0,0,0,0,1,0,0,0,0);
        *(undefined4 *)(lVar2 + 0x13c) = 1;
        iVar6 = iVar7;
      }
      else {
        if (param_2 != '\0') {
          iVar6 = 0x70128191;
          puVar4 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
          lVar2 = FUN_1416d5e80(0x147475690,0xbfd0639a,*puVar4,0,0,0,0,0,1,0,0,0,0);
          *(undefined1 *)(lVar2 + 0x138) = 1;
          *(undefined4 *)(lVar2 + 0x13c) = 2;
          goto LAB_140ac1379;
        }
        puVar4 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
        lVar2 = FUN_1416d5e80(0x147475690,0xe386aee5,*puVar4,0,0,0,0,0,1,0,0,0,0);
        *(undefined4 *)(lVar2 + 0x13c) = 2;
        iVar6 = -0x2d290e84;
      }
      *(undefined1 *)(lVar2 + 0x138) = 0;
      goto LAB_140ac1379;
    }
    iVar6 = -0x686f6190;
    if (param_2 != '\0') {
      iVar6 = 0x34910153;
      puVar4 = (undefined4 *)func_0x000141676900(param_1,auStackX_8);
      lVar2 = FUN_1416d5e80(0x147475690,0x3f77347e,*puVar4,0,0,0,0,0,1,0,0,0,0);
      *(undefined1 *)(lVar2 + 0x138) = 1;
      *(undefined4 *)(lVar2 + 0x13c) = 0;
      goto LAB_140ac1379;
    }
  }
  else if (param_2 == '\0') {
    iVar6 = -0x686f6190;
    if ((float)(*(uint *)(lVar3 + 0x428) & _DAT_14382e160) < _DAT_143830120) {
      iVar6 = -0x30491d91;
    }
  }
  else {
    iVar6 = 0x34910153;
  }
  lVar2 = FUN_140abaef0(param_1,0,0);
  *(undefined1 *)(lVar2 + 0x138) = 0;
  *(undefined4 *)(lVar2 + 0x13c) = 0;
LAB_140ac1379:
  *(ulonglong *)(lVar2 + 8) = *(ulonglong *)(lVar2 + 8) | 0x300;
  *(ulonglong *)(lVar2 + 0x18) = *(ulonglong *)(lVar2 + 0x18) | 0x300;
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar2 + 0x88) == 0) {
    lVar2 = FUN_14167ab40(lVar2 + 0x58,0x1473d09e0);
  }
  else {
    lVar2 = func_0x0001416799a0(lVar2 + 0x80);
  }
  func_0x0001415c6440(lVar2 + 0x68,auStackX_8,0);
  piVar5 = (int *)func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
  if ((piVar5 != (int *)0x0) && (*piVar5 == *(int *)(param_1 + 0x5e4))) {
    if (param_2 == '\0') {
      if (*(int *)(param_1 + 0x5dc) != 0) {
        iVar6 = *(int *)(param_1 + 0x5dc);
      }
    }
    else if (*(int *)(param_1 + 0x5e0) != 0) {
      return *(int *)(param_1 + 0x5e0);
    }
  }
  return iVar6;
}


/* SwingRegion_140ac1430 @ 0x140ac1430 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_140ac1430(longlong param_1,char param_2,float *param_3,undefined4 *param_4,undefined4 *param_5)

{
  float fVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float afStackX_8 [2];
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [56];
  
  if (*(int *)(param_1 + 0x574) != 2) {
    FUN_140ab4450(param_1 + 0x444,param_1 + 0x3c8,param_1 + 0x4d0,auStack_60,auStack_68,afStackX_8,0
                 );
    lVar3 = *(longlong *)(param_1 + 8);
    if (afStackX_8[0] <= 0.0) {
      afStackX_8[0] = 0.0;
    }
    if (_DAT_143840c90 <= afStackX_8[0]) {
      afStackX_8[0] = _DAT_143840c90;
    }
    afStackX_8[0] = _DAT_143840c90 - afStackX_8[0];
    if (*(short *)(lVar3 + 0x88) == 0) {
      uVar4 = FUN_14167ab40(lVar3 + 0x58,0x146dd6340);
    }
    else {
      uVar4 = func_0x0001416799a0(lVar3 + 0x80);
    }
    lVar5 = func_0x000140923770(uVar4);
    lVar3 = lVar5 + 0xbe8;
    if (*(int *)(lVar5 + 0xbf8) != 0) {
      lVar6 = func_0x0001411f3c90(lVar3,0);
      lVar7 = func_0x0001411f3c90(lVar3,0);
      fVar11 = _DAT_14382dce0;
      uVar2 = *(uint *)(lVar5 + 0xbf8);
      uVar9 = 1;
      lVar8 = lVar7;
      fVar10 = 0.0;
      if (1 < uVar2) {
        do {
          lVar7 = func_0x0001411f3c90(lVar3,uVar9);
          fVar10 = fVar11;
          if (afStackX_8[0] < *(float *)(lVar7 + 8)) {
            fVar1 = *(float *)(lVar8 + 8);
            fVar12 = *(float *)(lVar7 + 8) - fVar1;
            lVar6 = lVar8;
            if ((float)((uint)fVar12 & _DAT_14382e160) <= _DAT_14382e118) {
              if (fVar1 <= afStackX_8[0]) {
                if (afStackX_8[0] <= fVar1) {
                  fVar10 = _DAT_14382e128;
                }
              }
              else {
                fVar10 = 0.0;
              }
            }
            else {
              fVar10 = (afStackX_8[0] - fVar1) / fVar12;
              if (fVar10 <= 0.0) {
                fVar10 = 0.0;
              }
              if (fVar11 <= fVar10) {
                fVar10 = fVar11;
              }
            }
            break;
          }
          uVar9 = uVar9 + 1;
          lVar8 = lVar7;
          lVar6 = lVar7;
        } while (uVar9 < uVar2);
      }
      fVar11 = (*(float *)(lVar7 + 0xc) - *(float *)(lVar6 + 0xc)) * fVar10 +
               *(float *)(lVar6 + 0xc);
      if (param_2 != '\0') {
        *param_3 = fVar11 * *(float *)(lVar5 + 0xc20);
        *param_4 = *(undefined4 *)(lVar5 + 0xc24);
        *param_5 = *(undefined4 *)(lVar5 + 0xc28);
        return 1;
      }
      *param_3 = fVar11 * *(float *)(lVar5 + 0xc08);
      *param_4 = *(undefined4 *)(lVar5 + 0xc0c);
      *param_5 = *(undefined4 *)(lVar5 + 0xc10);
      return 1;
    }
  }
  return 0;
}


/* SwingRegion_140ac14ff @ 0x140ac14ff */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SwingRegion_140ac14ff(undefined4 param_1)

{
  float fVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong unaff_RBX;
  longlong lVar5;
  uint uVar6;
  float *unaff_R12;
  char unaff_R13B;
  undefined4 *unaff_R15;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 uVar7;
  undefined4 extraout_XMM0_Da_01;
  float fVar8;
  float fVar9;
  float unaff_XMM7_Da;
  float in_stack_000000b0;
  undefined4 *in_stack_000000d0;
  
  lVar3 = func_0x0001411f3c90(param_1,0);
  lVar4 = func_0x0001411f3c90(extraout_XMM0_Da,0);
  fVar8 = _DAT_14382dce0;
  uVar2 = *(uint *)(unaff_RBX + 0x10);
  uVar6 = 1;
  lVar5 = lVar4;
  uVar7 = extraout_XMM0_Da_00;
  fVar9 = 0.0;
  if (1 < uVar2) {
    do {
      lVar4 = func_0x0001411f3c90(uVar7,uVar6);
      if (in_stack_000000b0 < *(float *)(lVar4 + 8)) {
        fVar1 = *(float *)(lVar5 + 8);
        fVar9 = *(float *)(lVar4 + 8) - fVar1;
        lVar3 = lVar5;
        if ((float)((uint)fVar9 & _DAT_14382e160) <= _DAT_14382e118) {
          fVar9 = unaff_XMM7_Da;
          if ((fVar1 <= in_stack_000000b0) && (fVar9 = fVar8, in_stack_000000b0 <= fVar1)) {
            fVar9 = _DAT_14382e128;
          }
        }
        else {
          fVar9 = (in_stack_000000b0 - fVar1) / fVar9;
          if (fVar9 <= unaff_XMM7_Da) {
            fVar9 = unaff_XMM7_Da;
          }
          if (fVar8 <= fVar9) {
            fVar9 = fVar8;
          }
        }
        break;
      }
      uVar6 = uVar6 + 1;
      lVar5 = lVar4;
      lVar3 = lVar4;
      uVar7 = extraout_XMM0_Da_01;
      fVar9 = fVar8;
    } while (uVar6 < uVar2);
  }
  fVar8 = (*(float *)(lVar4 + 0xc) - *(float *)(lVar3 + 0xc)) * fVar9 + *(float *)(lVar3 + 0xc);
  if (unaff_R13B == '\0') {
    *unaff_R12 = fVar8 * *(float *)(unaff_RBX + 0x20);
    *unaff_R15 = *(undefined4 *)(unaff_RBX + 0x24);
    *in_stack_000000d0 = *(undefined4 *)(unaff_RBX + 0x28);
  }
  else {
    *unaff_R12 = fVar8 * *(float *)(unaff_RBX + 0x38);
    *unaff_R15 = *(undefined4 *)(unaff_RBX + 0x3c);
    *in_stack_000000d0 = *(undefined4 *)(unaff_RBX + 0x40);
  }
  return 1;
}


/* SwingRegion_140ac1614 @ 0x140ac1614 */

undefined8 SwingRegion_140ac1614(undefined8 param_1,float param_2)

{
  longlong unaff_RBX;
  float *unaff_R12;
  undefined4 *unaff_R15;
  undefined4 *in_stack_000000d0;
  
  *unaff_R12 = param_2 * *(float *)(unaff_RBX + 0x38);
  *unaff_R15 = *(undefined4 *)(unaff_RBX + 0x3c);
  *in_stack_000000d0 = *(undefined4 *)(unaff_RBX + 0x40);
  return 1;
}


/* SwingRegion_140ac1680 @ 0x140ac1680 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ac1680(longlong param_1,char param_2,char param_3,char param_4,float *param_5,
                  float *param_6,undefined4 *param_7)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  float fVar6;
  uint uVar7;
  uint uVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 *puVar13;
  longlong lVar14;
  float *pfVar15;
  uint uVar16;
  float fVar17;
  float fVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float afStack_120 [4];
  undefined1 auStack_110 [16];
  undefined1 auStack_100 [192];
  
  lVar10 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar10 + 0x88) == 0) {
    plVar9 = (longlong *)FUN_14167ab40(lVar10 + 0x58,0x147c40bf0);
  }
  else {
    plVar9 = (longlong *)func_0x0001416799a0(lVar10 + 0x80);
  }
  (**(code **)(*plVar9 + 0x80))(plVar9,&fStack_130,0);
  uVar21 = FUN_140876340(param_1 + 0x4d0);
  uVar19 = (undefined4)((ulonglong)uVar21 >> 0x20);
  fVar27 = (float)uVar21 * _DAT_143855568;
  *(ulonglong *)param_5 = CONCAT44(fStack_12c,fStack_130);
  param_5[2] = fStack_128;
  lVar10 = *(longlong *)(param_1 + 8);
  *(float *)(param_1 + 0x534) = fVar27;
  if (*(short *)(lVar10 + 0x88) == 0) {
    lVar10 = FUN_14167ab40(lVar10 + 0x58,0x146dacd70);
  }
  else {
    lVar10 = func_0x0001416799a0(lVar10 + 0x80);
  }
  lVar11 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar11 + 0x88) == 0) {
    uVar21 = FUN_14167ab40(lVar11 + 0x58,0x146dd6340);
  }
  else {
    uVar21 = func_0x0001416799a0(lVar11 + 0x80);
  }
  lVar11 = func_0x000140923770(uVar21);
  fVar18 = _DAT_1438728c8;
  fVar26 = _DAT_143861350;
  uVar8 = _DAT_14382e890;
  uVar7 = _DAT_14382e160;
  fVar28 = _DAT_14382e118;
  fVar6 = _DAT_14382dce0;
  fVar17 = _DAT_14382e128;
  if ((param_2 != '\0') && (DAT_145d9fe94 != '\0')) {
    uVar1 = *(uint *)(lVar11 + 0x1f0);
    uVar16 = 0;
    if (uVar1 != 0) {
      do {
        lVar12 = func_0x0001411f3c10(lVar11,uVar16);
        fVar25 = fVar27 + fVar26;
        fVar23 = *(float *)(lVar12 + 8);
        if ((fVar23 <= fVar25) && (fVar25 <= *(float *)(lVar12 + 0xc))) {
          fVar27 = *(float *)(lVar12 + 0xc) - fVar23;
          if ((float)((uint)fVar27 & uVar7) <= fVar28) {
            if (fVar25 <= fVar23) {
              uVar22 = (ulonglong)(uint)fVar17;
            }
            else {
              uVar22 = (ulonglong)(uint)fVar6;
            }
          }
          else {
            fVar27 = (fVar25 - fVar23) / fVar27;
            if (fVar27 <= 0.0) {
              fVar27 = 0.0;
            }
            if (fVar6 <= fVar27) {
              fVar27 = fVar6;
            }
            uVar22 = CONCAT44(uVar19,fVar27);
          }
          uVar21 = FUN_143666da0(uVar22,*(undefined4 *)(lVar12 + 0x18));
          uVar19 = (undefined4)((ulonglong)uVar21 >> 0x20);
          fVar17 = (float)((uint)fStack_128 & uVar7);
          if ((float)((uint)fStack_128 & uVar7) <= (float)((uint)fStack_12c & uVar7)) {
            fVar17 = (float)((uint)fStack_12c & uVar7);
          }
          fVar27 = (float)uVar21 * (*(float *)(lVar12 + 0x14) - *(float *)(lVar12 + 0x10)) +
                   *(float *)(lVar12 + 0x10);
          if (fVar17 <= (float)((uint)fStack_130 & uVar7)) {
            fVar17 = (float)((uint)fStack_130 & uVar7);
          }
          afStack_120[2] = fStack_130;
          afStack_120[0] = fStack_128;
          if (0.0 < fVar17) {
            fVar17 = fVar6 / fVar17;
            fVar23 = fStack_128 * fVar17;
            fVar24 = fStack_130 * fVar17;
            fVar17 = fVar6 / SQRT(fStack_12c * fVar17 * fStack_12c * fVar17 + fVar24 * fVar24 +
                                  fVar23 * fVar23);
            afStack_120[2] = fVar17 * fVar24;
            afStack_120[0] = fVar17 * fVar23;
          }
          afStack_120[2] = (float)((uint)afStack_120[2] ^ uVar8);
          afStack_120[1] = 0.0;
          FUN_141c54e30(auStack_100,afStack_120,(fVar27 - fVar25) * fVar18);
          puVar13 = (undefined8 *)FUN_141c5b320(auStack_110,param_5,auStack_100);
          fVar17 = _DAT_14382e128;
          fVar27 = fVar27 - fVar26;
          *(undefined8 *)param_5 = *puVar13;
          param_5[2] = *(float *)(puVar13 + 1);
          *(float *)(param_1 + 0x534) = fVar27;
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 < uVar1);
    }
  }
  FUN_140b82710(*(undefined8 *)(param_1 + 8));
  bVar2 = fVar27 == *(float *)(lVar11 + 0x1c8);
  bVar3 = fVar27 < *(float *)(lVar11 + 0x1c8);
  bVar4 = *(float *)(lVar11 + 0x1c4) <= fVar27;
  bVar5 = *(float *)(lVar11 + 0x1c0) <= fVar27;
  fVar18 = (float)FUN_1420dc660(param_1);
  fVar26 = _DAT_14382f2cc;
  if (fVar17 <= fVar18) {
    if ((!bVar5) && (param_2 == '\0')) goto LAB_140ac1a20;
  }
  else if (!bVar5) goto LAB_140ac1a20;
  if (param_3 != '\0') {
LAB_140ac1a20:
    fVar27 = param_5[1];
    if (*(float *)(param_1 + 0x4bc) < fVar27) {
      param_5[1] = (*(float *)(param_1 + 0x4bc) - fVar27) * _DAT_14382e124 + fVar27;
    }
    *param_6 = 24.0;
    uVar19 = FUN_14085fbb0(*(undefined8 *)(param_1 + 8));
    *param_7 = uVar19;
    fVar27 = _DAT_143848d00;
    *(undefined4 *)(param_1 + 0x528) = 0x3f000000;
    *(float *)(param_1 + 0x52c) = fVar27;
    return;
  }
  lVar12 = lVar10 + 0x560;
  if (bVar5) {
    if (bVar4) {
      if (!bVar3 && !bVar2) {
        *(undefined1 *)(param_1 + 0x539) = 1;
        lVar12 = lVar10 + 0x578;
      }
    }
    else {
      lVar12 = lVar10 + 0x548;
    }
  }
  else {
    lVar12 = lVar10 + 0x530;
    fVar18 = (float)func_0x0001403e3f30(param_5);
    fVar17 = *(float *)(lVar11 + 0x1d4);
    if (fVar17 < fVar18) {
      fVar23 = fVar18 * *(float *)(lVar11 + 0x1d0);
      if (fVar23 <= fVar17) {
        fVar23 = fVar17;
      }
      fVar17 = ((float)((uint)fVar27 & uVar7) - fVar26) * _DAT_1438ac378;
      if (fVar17 <= 0.0) {
        fVar17 = 0.0;
      }
      if (fVar6 <= fVar17) {
        fVar17 = fVar6;
      }
      fVar17 = (fVar23 / fVar18 - fVar6) * fVar17 + fVar6;
      param_5[2] = fVar17 * param_5[2];
      *param_5 = fVar17 * *param_5;
    }
  }
  fVar17 = _DAT_14383479c;
  if (param_2 == '\0') {
    fVar18 = param_5[1];
  }
  else {
    fVar18 = *(float *)(lVar12 + 8) + param_5[1];
    param_5[1] = fVar18;
    if ((bVar3 || bVar2) || (*(char *)(param_1 + 0x5f9) == '\0')) {
      fVar18 = fVar18 + 0.0;
      param_5[1] = fVar18;
    }
    else {
      fVar18 = fVar17 + fVar18;
      param_5[1] = fVar18;
    }
  }
  fVar23 = _DAT_14382e120;
  if (((DAT_146dd80b7 != '\0') && (bVar5)) && (_DAT_14382e120 < fVar18)) {
    lVar11 = *(longlong *)(param_1 + 8);
    if (*(short *)(lVar11 + 0x88) == 0) {
      lVar11 = FUN_14167ab40(lVar11 + 0x58,0x146dacd70);
    }
    else {
      lVar11 = func_0x0001416799a0(lVar11 + 0x80);
    }
    if (lVar11 == 0) {
      uVar20 = 0;
    }
    else {
      uVar20 = *(undefined4 *)(lVar11 + 0x1d4);
    }
    fVar18 = (float)func_0x00014041c590(uVar20,_DAT_143836d08,fVar6);
    if (fVar28 < fVar18) {
      fVar28 = fVar17;
      fVar25 = _DAT_14382ee94;
      if ((bVar4) && (fVar28 = _DAT_14382f0e4, fVar25 = _DAT_143834a14, !bVar3 && !bVar2)) {
        fVar28 = fVar26;
        fVar25 = fVar17;
      }
      param_5[1] = (fVar28 - fVar25) * fVar18 + fVar25 + param_5[1];
    }
  }
  fVar28 = param_5[1];
  if ((fVar28 <= 0.0) || (param_4 != '\0')) {
    if (param_2 != '\0') {
      fVar17 = *(float *)(lVar12 + 0x10);
      goto LAB_140ac1e43;
    }
  }
  else {
    uVar21 = func_0x0001403e3f30(param_5);
    lVar11 = *(longlong *)(param_1 + 0x380);
    fVar17 = (float)func_0x00014041c590(uVar21,(*(float *)(lVar11 + 0x1c) -
                                               *(float *)(lVar11 + 0x14)) * _DAT_143848d00 +
                                               *(float *)(lVar11 + 0x14));
    fVar25 = fVar6 - fVar17 * _DAT_14382e128;
    lVar14 = FUN_1402d0740(auStack_110,param_5);
    afStack_120[1] = 0.0;
    fVar18 = (*(float *)(param_1 + 0x51c) + fVar6) - (float)uVar21;
    fVar26 = *(float *)(lVar14 + 4) * *(float *)(lVar11 + 0x48) * fVar25;
    fVar17 = param_5[2];
    if (fVar18 <= 0.0) {
      fVar18 = 0.0;
    }
    if (fVar18 <= fVar26) {
      fVar26 = fVar18;
    }
    fVar24 = *(float *)(lVar11 + 0x4c) - (float)uVar21;
    fVar18 = *param_5;
    if (fVar26 <= fVar24) {
      fVar26 = fVar24;
    }
    afStack_120[0] = fVar18;
    afStack_120[2] = fVar17;
    pfVar15 = (float *)FUN_1402d0740(auStack_110,afStack_120);
    fVar18 = fVar26 * *pfVar15 + fVar18;
    fVar28 = pfVar15[1] * fVar26 + fVar28;
    fVar17 = pfVar15[2] * fVar26 + fVar17;
    *param_5 = fVar18;
    param_5[1] = fVar28;
    param_5[2] = fVar17;
    if (param_2 != '\0') {
      lVar11 = *(longlong *)(param_1 + 0x380);
      if (*(float *)(lVar11 + 0x58) <= fVar27) {
        fVar26 = fVar6;
        if (*(float *)(lVar11 + 0x5c) < fVar27) {
          fVar26 = (float)func_0x00014041c590(CONCAT44(uVar19,fVar27),*(float *)(lVar11 + 0x5c),
                                              *(undefined4 *)(lVar11 + 0x60));
          fVar26 = fVar6 - fVar26;
        }
      }
      else {
        fVar26 = (float)func_0x00014041c590(CONCAT44(uVar19,fVar27),*(undefined4 *)(lVar11 + 0x54));
      }
      afStack_120[1] = 0.0;
      fVar25 = fVar26 * *(float *)(lVar11 + 0x50) * fVar25;
      afStack_120[0] = fVar18;
      afStack_120[2] = fVar17;
      pfVar15 = (float *)FUN_1402d0740(auStack_110,afStack_120);
      fVar26 = pfVar15[2];
      fVar28 = pfVar15[1] * fVar25 + fVar28;
      *param_5 = fVar25 * *pfVar15 + fVar18;
      param_5[1] = fVar28;
      param_5[2] = fVar26 * fVar25 + fVar17;
      fVar17 = *(float *)(lVar12 + 0x10);
      goto LAB_140ac1e43;
    }
  }
  fVar17 = *(float *)(lVar12 + 0xc);
LAB_140ac1e43:
  if (fVar28 <= fVar17) {
    fVar28 = fVar17;
  }
  param_5[1] = fVar28;
  *param_6 = *(float *)(lVar10 + 0x598);
  uVar19 = FUN_14085fbb0(*(undefined8 *)(param_1 + 8));
  *param_7 = uVar19;
  fVar28 = *(float *)(lVar10 + 0x5b4);
  fVar17 = _DAT_14382e128;
  if (fVar28 <= fVar27) {
    fVar26 = *(float *)(lVar10 + 0x5b8) - fVar28;
    if ((float)((uint)fVar26 & uVar7) <= _DAT_14382e118) {
      if (fVar28 < fVar27) {
        fVar17 = fVar6;
      }
    }
    else {
      fVar17 = (fVar27 - fVar28) / fVar26;
      if (fVar17 <= 0.0) {
        fVar17 = 0.0;
      }
      if (fVar6 <= fVar17) {
        fVar17 = fVar6;
      }
    }
    if (param_2 == '\0') {
      fVar27 = *(float *)(lVar10 + 0x59c);
      fVar28 = *(float *)(lVar10 + 0x5a0);
    }
    else {
      fVar27 = *(float *)(lVar10 + 0x5a8);
      fVar28 = *(float *)(lVar10 + 0x5ac);
    }
  }
  else {
    fVar26 = *(float *)(lVar10 + 0x5b0);
    if ((float)((uint)(fVar28 - fVar26) & uVar7) <= _DAT_14382e118) {
      if (fVar26 <= fVar27) {
        if (fVar26 < fVar27) {
          fVar17 = fVar6;
        }
      }
      else {
        fVar17 = 0.0;
      }
    }
    else {
      fVar17 = (fVar27 - fVar26) / (fVar28 - fVar26);
      if (fVar17 <= 0.0) {
        fVar17 = 0.0;
      }
      if (fVar6 <= fVar17) {
        fVar17 = fVar6;
      }
    }
    if (param_2 == '\0') {
      fVar27 = *(float *)(lVar10 + 0x598);
      fVar28 = *(float *)(lVar10 + 0x59c);
    }
    else {
      fVar27 = *(float *)(lVar10 + 0x5a4);
      fVar28 = *(float *)(lVar10 + 0x5a8);
    }
  }
  fVar27 = (fVar28 - fVar27) * fVar17 + fVar27;
  *param_6 = fVar27;
  fVar27 = param_5[1] / fVar27;
  if (fVar27 <= fVar23) {
    fVar27 = fVar23;
  }
  fVar28 = fVar27 * _DAT_1438388c0;
  if (fVar27 * _DAT_1438388c0 <= fVar23) {
    fVar28 = fVar23;
  }
  if (_DAT_14382f0dc <= fVar28) {
    fVar28 = _DAT_14382f0dc;
  }
  *(float *)(param_1 + 0x528) = fVar28;
  fVar27 = _DAT_14383fd4c;
  if (((bVar4) && (param_2 != '\0')) && (fVar27 = fVar28, fVar6 <= fVar28)) {
    fVar27 = fVar6;
  }
  *(float *)(param_1 + 0x52c) = fVar27;
  return;
}


/* SwingRegion_140ac17aa @ 0x140ac17aa */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ac17aa(void)

{
  float fVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  longlong lVar11;
  undefined8 *puVar12;
  longlong lVar13;
  float *pfVar14;
  longlong unaff_RBP;
  longlong unaff_RSI;
  float *unaff_RDI;
  longlong unaff_R14;
  char unaff_R15B;
  uint uVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float unaff_XMM9_Da;
  float fVar25;
  undefined4 unaff_XMM9_Db;
  float fVar26;
  float fStack0000000000000028;
  float fStack000000000000002c;
  float in_stack_00000030;
  float fStack0000000000000038;
  undefined4 uStack000000000000003c;
  float in_stack_00000040;
  
  lVar10 = func_0x000140923770();
  fVar17 = _DAT_1438728c8;
  fVar24 = _DAT_143861350;
  uVar9 = _DAT_14382e890;
  uVar8 = _DAT_14382e160;
  fVar26 = _DAT_14382e118;
  fVar1 = _DAT_14382dce0;
  fVar16 = _DAT_14382e128;
  if ((unaff_R15B != '\0') && (DAT_145d9fe94 != '\0')) {
    uVar4 = *(uint *)(lVar10 + 0x1f0);
    uVar15 = 0;
    if (uVar4 != 0) {
      do {
        lVar11 = func_0x0001411f3c10(lVar10,uVar15);
        fVar23 = unaff_XMM9_Da + fVar24;
        fVar25 = *(float *)(lVar11 + 8);
        if ((fVar25 <= fVar23) && (fVar23 <= *(float *)(lVar11 + 0xc))) {
          fVar21 = *(float *)(lVar11 + 0xc) - fVar25;
          if ((float)((uint)fVar21 & uVar8) <= fVar26) {
            if (fVar23 <= fVar25) {
              uVar19 = (ulonglong)(uint)fVar16;
            }
            else {
              uVar19 = (ulonglong)(uint)fVar1;
            }
          }
          else {
            fVar21 = (fVar23 - fVar25) / fVar21;
            if (fVar21 <= 0.0) {
              fVar21 = 0.0;
            }
            if (fVar1 <= fVar21) {
              fVar21 = fVar1;
            }
            uVar19 = CONCAT44(unaff_XMM9_Db,fVar21);
          }
          uVar20 = FUN_143666da0(uVar19,*(undefined4 *)(lVar11 + 0x18));
          unaff_XMM9_Db = (undefined4)((ulonglong)uVar20 >> 0x20);
          fVar16 = (float)((uint)in_stack_00000030 & uVar8);
          if ((float)((uint)in_stack_00000030 & uVar8) <=
              (float)((uint)fStack000000000000002c & uVar8)) {
            fVar16 = (float)((uint)fStack000000000000002c & uVar8);
          }
          fVar25 = (float)uVar20 * (*(float *)(lVar11 + 0x14) - *(float *)(lVar11 + 0x10)) +
                   *(float *)(lVar11 + 0x10);
          if (fVar16 <= (float)((uint)fStack0000000000000028 & uVar8)) {
            fVar16 = (float)((uint)fStack0000000000000028 & uVar8);
          }
          in_stack_00000040 = fStack0000000000000028;
          fStack0000000000000038 = in_stack_00000030;
          if (0.0 < fVar16) {
            fVar16 = fVar1 / fVar16;
            fVar21 = in_stack_00000030 * fVar16;
            fVar22 = fStack0000000000000028 * fVar16;
            fVar16 = fVar1 / SQRT(fStack000000000000002c * fVar16 * fStack000000000000002c * fVar16
                                  + fVar22 * fVar22 + fVar21 * fVar21);
            in_stack_00000040 = fVar16 * fVar22;
            fStack0000000000000038 = fVar16 * fVar21;
          }
          in_stack_00000040 = (float)((uint)in_stack_00000040 ^ uVar9);
          uStack000000000000003c = 0;
          FUN_141c54e30(&stack0x00000058,&stack0x00000038,(fVar25 - fVar23) * fVar17);
          puVar12 = (undefined8 *)FUN_141c5b320(&stack0x00000048);
          fVar16 = _DAT_14382e128;
          unaff_XMM9_Da = fVar25 - fVar24;
          *(undefined8 *)unaff_RDI = *puVar12;
          unaff_RDI[2] = *(float *)(puVar12 + 1);
          *(float *)(unaff_RSI + 0x534) = unaff_XMM9_Da;
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < uVar4);
    }
    unaff_R15B = *(char *)(unaff_RBP + 0x68);
  }
  FUN_140b82710(*(undefined8 *)(unaff_RSI + 8));
  bVar5 = unaff_XMM9_Da == *(float *)(lVar10 + 0x1c8);
  bVar6 = unaff_XMM9_Da < *(float *)(lVar10 + 0x1c8);
  *(bool *)(unaff_RBP + 0x80) = unaff_XMM9_Da < *(float *)(lVar10 + 0x1c4);
  bVar7 = *(float *)(lVar10 + 0x1c0) <= unaff_XMM9_Da;
  fVar17 = (float)FUN_1420dc660();
  fVar24 = _DAT_14382f2cc;
  if (fVar16 <= fVar17) {
    if ((!bVar7) && (unaff_R15B == '\0')) goto LAB_140ac1a20;
  }
  else if (!bVar7) goto LAB_140ac1a20;
  if (*(char *)(unaff_RBP + 0x70) != '\0') {
LAB_140ac1a20:
    fVar1 = unaff_RDI[1];
    if (*(float *)(unaff_RSI + 0x4bc) < fVar1) {
      unaff_RDI[1] = (*(float *)(unaff_RSI + 0x4bc) - fVar1) * _DAT_14382e124 + fVar1;
    }
    **(undefined4 **)(unaff_RBP + 0x88) = 0x41c00000;
    uVar18 = FUN_14085fbb0(*(undefined8 *)(unaff_RSI + 8));
    **(undefined4 **)(unaff_RBP + 0x90) = uVar18;
    fVar1 = _DAT_143848d00;
    *(undefined4 *)(unaff_RSI + 0x528) = 0x3f000000;
    *(float *)(unaff_RSI + 0x52c) = fVar1;
    return;
  }
  lVar11 = unaff_R14 + 0x560;
  if (bVar7) {
    if (*(char *)(unaff_RBP + 0x80) == '\0') {
      if (!bVar6 && !bVar5) {
        *(undefined1 *)(unaff_RSI + 0x539) = 1;
        lVar11 = unaff_R14 + 0x578;
      }
    }
    else {
      lVar11 = unaff_R14 + 0x548;
    }
  }
  else {
    lVar11 = unaff_R14 + 0x530;
    fVar17 = (float)func_0x0001403e3f30();
    fVar16 = *(float *)(lVar10 + 0x1d4);
    if (fVar16 < fVar17) {
      fVar25 = fVar17 * *(float *)(lVar10 + 0x1d0);
      if (fVar25 <= fVar16) {
        fVar25 = fVar16;
      }
      fVar16 = ((float)((uint)unaff_XMM9_Da & uVar8) - fVar24) * _DAT_1438ac378;
      if (fVar16 <= 0.0) {
        fVar16 = 0.0;
      }
      if (fVar1 <= fVar16) {
        fVar16 = fVar1;
      }
      fVar16 = (fVar25 / fVar17 - fVar1) * fVar16 + fVar1;
      unaff_RDI[2] = fVar16 * unaff_RDI[2];
      *unaff_RDI = fVar16 * *unaff_RDI;
    }
  }
  fVar16 = _DAT_14383479c;
  cVar2 = *(char *)(unaff_RBP + 0x68);
  if (cVar2 == '\0') {
    fVar17 = unaff_RDI[1];
  }
  else {
    fVar17 = *(float *)(lVar11 + 8) + unaff_RDI[1];
    unaff_RDI[1] = fVar17;
    if ((bVar6 || bVar5) || (*(char *)(unaff_RSI + 0x5f9) == '\0')) {
      fVar17 = fVar17 + 0.0;
      unaff_RDI[1] = fVar17;
    }
    else {
      fVar17 = fVar16 + fVar17;
      unaff_RDI[1] = fVar17;
    }
  }
  fVar25 = _DAT_14382e120;
  if (((DAT_146dd80b7 != '\0') && (bVar7)) && (_DAT_14382e120 < fVar17)) {
    lVar10 = *(longlong *)(unaff_RSI + 8);
    if (*(short *)(lVar10 + 0x88) == 0) {
      lVar10 = FUN_14167ab40(lVar10 + 0x58,0x146dacd70);
    }
    else {
      lVar10 = func_0x0001416799a0(lVar10 + 0x80);
    }
    if (lVar10 == 0) {
      uVar18 = 0;
    }
    else {
      uVar18 = *(undefined4 *)(lVar10 + 0x1d4);
    }
    fVar17 = (float)func_0x00014041c590(uVar18,_DAT_143836d08,fVar1);
    if (fVar26 < fVar17) {
      fVar26 = fVar16;
      fVar23 = _DAT_14382ee94;
      if ((*(char *)(unaff_RBP + 0x80) == '\0') &&
         (fVar26 = _DAT_14382f0e4, fVar23 = _DAT_143834a14, !bVar6 && !bVar5)) {
        fVar26 = fVar24;
        fVar23 = fVar16;
      }
      unaff_RDI[1] = (fVar26 - fVar23) * fVar17 + fVar23 + unaff_RDI[1];
    }
  }
  fVar26 = unaff_RDI[1];
  if ((fVar26 <= 0.0) || (*(char *)(unaff_RBP + 0x78) != '\0')) {
    if (cVar2 != '\0') {
      fVar16 = *(float *)(lVar11 + 0x10);
      goto LAB_140ac1e43;
    }
  }
  else {
    uVar20 = func_0x0001403e3f30();
    lVar10 = *(longlong *)(unaff_RSI + 0x380);
    fVar16 = (float)func_0x00014041c590(uVar20,(*(float *)(lVar10 + 0x1c) -
                                               *(float *)(lVar10 + 0x14)) * _DAT_143848d00 +
                                               *(float *)(lVar10 + 0x14));
    fVar24 = fVar1 - fVar16 * _DAT_14382e128;
    *(float *)(unaff_RBP + 0x68) = fVar24;
    lVar13 = FUN_1402d0740(&stack0x00000048);
    uStack000000000000003c = 0;
    fVar17 = (*(float *)(unaff_RSI + 0x51c) + fVar1) - (float)uVar20;
    fVar24 = *(float *)(lVar13 + 4) * *(float *)(lVar10 + 0x48) * fVar24;
    fVar16 = unaff_RDI[2];
    if (fVar17 <= 0.0) {
      fVar17 = 0.0;
    }
    if (fVar17 <= fVar24) {
      fVar24 = fVar17;
    }
    fVar23 = *(float *)(lVar10 + 0x4c) - (float)uVar20;
    fVar17 = *unaff_RDI;
    if (fVar24 <= fVar23) {
      fVar24 = fVar23;
    }
    fStack0000000000000038 = fVar17;
    in_stack_00000040 = fVar16;
    pfVar14 = (float *)FUN_1402d0740(&stack0x00000048,&stack0x00000038);
    fVar17 = fVar24 * *pfVar14 + fVar17;
    fVar26 = pfVar14[1] * fVar24 + fVar26;
    fVar16 = pfVar14[2] * fVar24 + fVar16;
    *(float *)(unaff_RBP + 0x60) = fVar17;
    *unaff_RDI = fVar17;
    unaff_RDI[1] = fVar26;
    unaff_RDI[2] = fVar16;
    if (cVar2 != '\0') {
      lVar10 = *(longlong *)(unaff_RSI + 0x380);
      if (*(float *)(lVar10 + 0x58) <= unaff_XMM9_Da) {
        fVar24 = fVar1;
        if (*(float *)(lVar10 + 0x5c) < unaff_XMM9_Da) {
          fVar24 = (float)func_0x00014041c590(CONCAT44(unaff_XMM9_Db,unaff_XMM9_Da),
                                              *(float *)(lVar10 + 0x5c),
                                              *(undefined4 *)(lVar10 + 0x60));
          fVar24 = fVar1 - fVar24;
        }
      }
      else {
        fVar24 = (float)func_0x00014041c590(CONCAT44(unaff_XMM9_Db,unaff_XMM9_Da),
                                            *(undefined4 *)(lVar10 + 0x54));
      }
      uStack000000000000003c = 0;
      fVar17 = *(float *)(unaff_RBP + 0x60);
      fVar23 = fVar24 * *(float *)(lVar10 + 0x50) * *(float *)(unaff_RBP + 0x68);
      fStack0000000000000038 = fVar17;
      in_stack_00000040 = fVar16;
      pfVar14 = (float *)FUN_1402d0740(&stack0x00000048,&stack0x00000038);
      fVar24 = pfVar14[2];
      fVar26 = pfVar14[1] * fVar23 + fVar26;
      *unaff_RDI = fVar23 * *pfVar14 + fVar17;
      unaff_RDI[1] = fVar26;
      unaff_RDI[2] = fVar24 * fVar23 + fVar16;
      fVar16 = *(float *)(lVar11 + 0x10);
      goto LAB_140ac1e43;
    }
  }
  fVar16 = *(float *)(lVar11 + 0xc);
LAB_140ac1e43:
  pfVar14 = *(float **)(unaff_RBP + 0x88);
  if (fVar26 <= fVar16) {
    fVar26 = fVar16;
  }
  unaff_RDI[1] = fVar26;
  *pfVar14 = *(float *)(unaff_R14 + 0x598);
  uVar18 = FUN_14085fbb0(*(undefined8 *)(unaff_RSI + 8));
  **(undefined4 **)(unaff_RBP + 0x90) = uVar18;
  fVar26 = *(float *)(unaff_R14 + 0x5b4);
  fVar16 = _DAT_14382e128;
  if (fVar26 <= unaff_XMM9_Da) {
    fVar24 = *(float *)(unaff_R14 + 0x5b8) - fVar26;
    if ((float)((uint)fVar24 & uVar8) <= _DAT_14382e118) {
      if (fVar26 < unaff_XMM9_Da) {
        fVar16 = fVar1;
      }
    }
    else {
      fVar16 = (unaff_XMM9_Da - fVar26) / fVar24;
      if (fVar16 <= 0.0) {
        fVar16 = 0.0;
      }
      if (fVar1 <= fVar16) {
        fVar16 = fVar1;
      }
    }
    if (cVar2 == '\0') {
      fVar26 = *(float *)(unaff_R14 + 0x59c);
      fVar24 = *(float *)(unaff_R14 + 0x5a0);
    }
    else {
      fVar26 = *(float *)(unaff_R14 + 0x5a8);
      fVar24 = *(float *)(unaff_R14 + 0x5ac);
    }
  }
  else {
    fVar24 = *(float *)(unaff_R14 + 0x5b0);
    if ((float)((uint)(fVar26 - fVar24) & uVar8) <= _DAT_14382e118) {
      if (fVar24 <= unaff_XMM9_Da) {
        if (fVar24 < unaff_XMM9_Da) {
          fVar16 = fVar1;
        }
      }
      else {
        fVar16 = 0.0;
      }
    }
    else {
      fVar16 = (unaff_XMM9_Da - fVar24) / (fVar26 - fVar24);
      if (fVar16 <= 0.0) {
        fVar16 = 0.0;
      }
      if (fVar1 <= fVar16) {
        fVar16 = fVar1;
      }
    }
    if (cVar2 == '\0') {
      fVar26 = *(float *)(unaff_R14 + 0x598);
      fVar24 = *(float *)(unaff_R14 + 0x59c);
    }
    else {
      fVar26 = *(float *)(unaff_R14 + 0x5a4);
      fVar24 = *(float *)(unaff_R14 + 0x5a8);
    }
  }
  cVar3 = *(char *)(unaff_RBP + 0x80);
  fVar26 = (fVar24 - fVar26) * fVar16 + fVar26;
  *pfVar14 = fVar26;
  fVar26 = unaff_RDI[1] / fVar26;
  if (fVar26 <= fVar25) {
    fVar26 = fVar25;
  }
  fVar16 = fVar26 * _DAT_1438388c0;
  if (fVar26 * _DAT_1438388c0 <= fVar25) {
    fVar16 = fVar25;
  }
  if (_DAT_14382f0dc <= fVar16) {
    fVar16 = _DAT_14382f0dc;
  }
  *(float *)(unaff_RSI + 0x528) = fVar16;
  fVar26 = _DAT_14383fd4c;
  if (((cVar3 == '\0') && (cVar2 != '\0')) && (fVar26 = fVar16, fVar1 <= fVar16)) {
    fVar26 = fVar1;
  }
  *(float *)(unaff_RSI + 0x52c) = fVar26;
  return;
}


/* SwingRegion_140ac2040 @ 0x140ac2040 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140ac2040(void)

{
  float fVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = func_0x0001409c87f0();
  fVar1 = *(float *)(lVar2 + 0x1b8);
  if ((fVar1 <= _DAT_143830128) && (0.0 <= fVar1)) {
    uVar3 = 0x6b0e4660;
    if (fVar1 < _DAT_1438794d0) {
      uVar3 = 0xd865fadc;
    }
    return uVar3;
  }
  return 0;
}


/* SwingRegion_140ac2090 @ 0x140ac2090 */

void FUN_140ac2090(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5)

{
  undefined1 auStack_18 [24];
  
  FUN_140ab4450(param_1 + 0x444,param_1 + 0x3c8,param_2,auStack_18,param_3,param_4,param_5);
  return;
}


/* SwingRegion_140ac20d0 @ 0x140ac20d0 */

void FUN_140ac20d0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  undefined1 auStack_18 [24];
  
  FUN_140ab4450(param_1 + 0x444,param_1 + 0x3c8,param_1 + 0x4d0,auStack_18,param_2,param_3,param_4);
  return;
}


/* SwingRegion_140ac2110 @ 0x140ac2110 */

void FUN_140ac2110(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 auStackX_8 [2];
  
  *(undefined4 *)(param_1 + 0x5dc) = *(undefined4 *)(param_2 + 0x144);
  *(undefined4 *)(param_1 + 0x5e0) = *(undefined4 *)(param_2 + 0x154);
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x1473d09e0);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  func_0x0001415c6440(lVar3 + 0x68,auStackX_8,0);
  puVar4 = (undefined4 *)func_0x0001415ad2a0(0x1473d0730,auStackX_8[0]);
  uVar2 = 0;
  if (puVar4 != (undefined4 *)0x0) {
    uVar2 = *puVar4;
  }
  *(undefined4 *)(param_1 + 0x5e4) = uVar2;
  if (*(int *)(param_1 + 0x5e0) != 0) {
    cVar1 = FUN_1415c19a0(lVar3);
    if (cVar1 == '\0') {
      *(undefined4 *)(param_1 + 0x5e0) = 0;
    }
  }
  if (*(int *)(param_1 + 0x5dc) != 0) {
    cVar1 = FUN_1415c19a0(lVar3);
    if (cVar1 == '\0') {
      *(undefined4 *)(param_1 + 0x5dc) = 0;
    }
  }
  return;
}


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
  fVar1 = _DAT_14382dce0;
  fVar7 = *(float *)(param_1 + 0x3cc) - *(float *)(param_1 + 0x448);
  fVar4 = *(float *)(param_1 + 0x3d0) - *(float *)(param_1 + 0x44c);
  fVar6 = *(float *)(param_1 + 0x3c8) - *(float *)(param_1 + 0x444);
  fVar3 = (float)((uint)fVar4 & _DAT_14382e160);
  if ((float)((uint)fVar4 & _DAT_14382e160) <= (float)((uint)fVar7 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fVar7 & _DAT_14382e160);
  }
  if (fVar3 <= (float)((uint)fVar6 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fVar6 & _DAT_14382e160);
  }
  if (0.0 < fVar3) {
    fVar3 = _DAT_14382dce0 / fVar3;
    fVar4 = fVar3 * fVar4;
    fVar6 = fVar3 * fVar6;
    fVar3 = fVar3 * fVar7;
    fVar5 = _DAT_14382dce0 / SQRT(fVar3 * fVar3 + fVar6 * fVar6 + fVar4 * fVar4);
    fVar6 = fVar5 * fVar6;
    fVar7 = fVar5 * fVar3;
    fVar4 = fVar5 * fVar4;
  }
  fVar3 = (float)((uint)fVar6 & _DAT_14382e160);
  if ((float)((uint)fVar6 & _DAT_14382e160) <= (float)((uint)fVar4 & _DAT_14382e160)) {
    fVar3 = (float)((uint)fVar4 & _DAT_14382e160);
  }
  fVar4 = (_DAT_14382dce0 / fVar3) * fVar4;
  fVar6 = (_DAT_14382dce0 / fVar3) * fVar6;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0;
  }
  else {
    fVar3 = SQRT(fVar4 * fVar4 + fVar6 * fVar6) * fVar3;
  }
  fVar6 = (float)FUN_141c58560(fVar7,fVar3);
  fVar6 = fVar6 * _DAT_143855568;
  fVar3 = (float)FUN_140311350(param_1 + 0x3c8,param_1 + 0x444);
  fVar3 = (fVar3 - _DAT_14383d264) * _DAT_1438398cc;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0;
  }
  if (fVar1 <= fVar3) {
    fVar3 = fVar1;
  }
  fVar4 = (float)FUN_1402c2450(param_1 + 0x4b8);
  fVar3 = _DAT_1438312b0 - fVar3 * _DAT_14384bc0c;
  cVar2 = FUN_14098fc80(*(undefined8 *)(param_1 + 0x108));
  if (cVar2 != '\0') {
    fVar3 = *(float *)(param_1 + 0x42c);
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    if (fVar1 <= fVar3) {
      fVar3 = fVar1;
    }
    fVar3 = fVar3 * _DAT_14382f0e4 + _DAT_14384bc0c;
  }
  if ((((fVar6 < fVar3) && (0.0 < *(float *)(param_1 + 0x4bc))) && (*(int *)(param_1 + 0x574) != 0))
     || ((afStackX_8[0] <= _DAT_1438416fc && (afStackX_10[0] <= fVar3)))) {
    cVar2 = (fVar4 <= _DAT_14382f2cc) + '\x01';
  }
  else {
    cVar2 = '\0';
  }
  return cVar2;
}


/* SwingRegion_140ac2490 @ 0x140ac2490 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ac2490(longlong param_1,longlong param_2)

{
  float fVar1;
  char cVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar3 + 0x88) == 0) {
    lVar3 = FUN_14167ab40(lVar3 + 0x58,0x146dd6030);
  }
  else {
    lVar3 = func_0x0001416799a0(lVar3 + 0x80);
  }
  FUN_140911560(lVar3,0,0);
  *(undefined8 *)(lVar3 + 0x134) = 0;
  *(undefined4 *)(lVar3 + 0x13c) = 0;
  *(undefined1 *)(lVar3 + 0x140) = 0;
  if (((param_2 != 0) && (cVar2 = func_0x0001416766e0(param_2,0x146deece0), cVar2 != '\0')) &&
     (fVar1 = *(float *)(param_1 + 0x544), _DAT_14382e118 < fVar1)) {
    uVar4 = _DAT_14382e124;
    if (_DAT_14382e118 < (float)((uint)*(float *)(param_1 + 0x53c) & _DAT_14382e160)) {
      uVar4 = (uint)(fVar1 / *(float *)(param_1 + 0x53c)) & _DAT_14382e160;
    }
    FUN_140897a50(lVar3 + 0x6c0,fVar1,uVar4);
  }
  return;
}


/* SwingRegion_140ac2570 @ 0x140ac2570 */

/* WARNING: Removing unreachable block (ram,0x000140ac28ca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ac2570(longlong param_1)

{
  float *pfVar1;
  float *pfVar2;
  char *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  longlong lVar7;
  longlong lVar8;
  char cVar9;
  float fVar10;
  float fVar11;
  float afStackX_18 [2];
  undefined1 auStackX_20 [8];
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float afStack_68 [2];
  undefined4 uStack_60;
  
  pfVar1 = (float *)(param_1 + 0x3c8);
  pfVar2 = (float *)(param_1 + 0x444);
  FUN_140ab4450(pfVar2,pfVar1,param_1 + 0x4d0,afStack_68,auStackX_20,afStackX_18,0);
  lVar7 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar7 + 0x88) == 0) {
    lVar7 = FUN_14167ab40(lVar7 + 0x58,0x1473d09e0);
  }
  else {
    lVar7 = func_0x0001416799a0(lVar7 + 0x80);
  }
  lVar8 = func_0x0001409c87f0(param_1);
  uVar5 = _DAT_14382e160;
  pcVar3 = (char *)(param_1 + 0x580);
  cVar9 = *pcVar3;
  if (cVar9 != '\0') {
    if (cVar9 == '\x01') {
      if (((*(byte *)(lVar7 + 0x98) & 1) != 0) && ((*(byte *)(lVar7 + 0xa0) & 1) == 0)) {
        return;
      }
      FUN_1420df1c0(pcVar3,0);
      *(undefined4 *)(param_1 + 0x598) = 0;
      *(undefined8 *)(param_1 + 0x59c) = *(undefined8 *)(param_1 + 0x398);
      *(undefined8 *)(param_1 + 0x5a4) = *(undefined8 *)(param_1 + 0x3a0);
      *(undefined8 *)(param_1 + 0x5ac) = *(undefined8 *)(param_1 + 0x3a8);
      *(undefined8 *)(param_1 + 0x5b4) = *(undefined8 *)(param_1 + 0x3b0);
      *(undefined4 *)(param_1 + 0x5bc) = *(undefined4 *)(param_1 + 0x3b8);
      *(undefined4 *)(param_1 + 0x5c0) = *(undefined4 *)(param_1 + 0x3bc);
      *(undefined4 *)(param_1 + 0x5c4) = *(undefined4 *)(param_1 + 0x3c0);
      *(undefined4 *)(param_1 + 0x5c8) = *(undefined4 *)(param_1 + 0x3c4);
      *(undefined4 *)(param_1 + 0x5cc) = *(undefined4 *)(param_1 + 0x3c8);
      *(undefined4 *)(param_1 + 0x5d0) = *(undefined4 *)(param_1 + 0x3cc);
      *(undefined4 *)(param_1 + 0x5d4) = *(undefined4 *)(param_1 + 0x3d0);
      *(undefined4 *)(param_1 + 0x5d8) = *(undefined4 *)(param_1 + 0x3d4);
      func_0x000140ab5d70(lVar8,0,0);
      return;
    }
    if (cVar9 != '\x02') {
      return;
    }
    if (((*(byte *)(lVar7 + 0x98) & 1) != 0) && ((*(byte *)(lVar7 + 0xa0) & 1) == 0)) {
      return;
    }
    FUN_1420df1c0(pcVar3,3);
    *(undefined4 *)(param_1 + 0x598) = 0x72d1384e;
    *(undefined8 *)(param_1 + 0x59c) = *(undefined8 *)(param_1 + 0x398);
    *(undefined8 *)(param_1 + 0x5a4) = *(undefined8 *)(param_1 + 0x3a0);
    *(undefined8 *)(param_1 + 0x5ac) = *(undefined8 *)(param_1 + 0x3a8);
    *(undefined8 *)(param_1 + 0x5b4) = *(undefined8 *)(param_1 + 0x3b0);
    *(undefined4 *)(param_1 + 0x5bc) = *(undefined4 *)(param_1 + 0x3b8);
    *(undefined4 *)(param_1 + 0x5c0) = *(undefined4 *)(param_1 + 0x3bc);
    *(undefined4 *)(param_1 + 0x5c4) = *(undefined4 *)(param_1 + 0x3c0);
    *(undefined4 *)(param_1 + 0x5c8) = *(undefined4 *)(param_1 + 0x3c4);
    *(undefined4 *)(param_1 + 0x5cc) = *(undefined4 *)(param_1 + 0x3c8);
    *(undefined4 *)(param_1 + 0x5d0) = *(undefined4 *)(param_1 + 0x3cc);
    *(undefined4 *)(param_1 + 0x5d4) = *(undefined4 *)(param_1 + 0x3d0);
    *(undefined4 *)(param_1 + 0x5d8) = *(undefined4 *)(param_1 + 0x3d4);
    func_0x000140ab5d70(lVar8,0x72d1384e,1);
    return;
  }
  if ((*(int *)(param_1 + 0x574) == 0) || (cVar9 = *(char *)(param_1 + 0x58c), cVar9 == '\x02'))
  goto LAB_140ac2b12;
  if ((0.0 < *(float *)(param_1 + 0x4bc) || *(float *)(param_1 + 0x4bc) == 0.0) ||
     (*(float *)(param_1 + 0x4c8) <= 0.0 && *(float *)(param_1 + 0x4c8) != 0.0)) {
    if (cVar9 != '\0') goto LAB_140ac2b12;
    fStack_78 = *pfVar1 - *(float *)(param_1 + 0x438);
    fStack_74 = *(float *)(param_1 + 0x3cc) - *(float *)(param_1 + 0x43c);
    fStack_70 = *(float *)(param_1 + 0x3d0) - *(float *)(param_1 + 0x440);
    FUN_1402d0740(afStack_68,&fStack_78);
    fStack_78 = afStack_68[0];
    fStack_70 = (float)uStack_60;
    fStack_74 = 0.0;
    FUN_1402d0740(&fStack_88,&fStack_78);
    fVar11 = fStack_80 * *(float *)(param_1 + 0x4c0) + fStack_88 * *(float *)(param_1 + 0x4b8);
    fStack_78 = *(float *)(param_1 + 0x4b8) - fStack_88 * fVar11;
    fStack_70 = *(float *)(param_1 + 0x4c0) - fStack_80 * fVar11;
    fStack_74 = (float)((uint)(fStack_84 * fVar11) ^ _DAT_14382e890);
    fVar11 = (float)FUN_140876340(afStack_68);
    fVar10 = (float)FUN_140876340(param_1 + 0x4d0);
    if (((_DAT_1438312b0 <= fVar11 * _DAT_143830124) ||
        (_DAT_14382f2cc <= (float)((uint)(fVar10 * _DAT_143830124) & uVar5))) ||
       (fVar11 = (float)FUN_1402c2450(&fStack_78), fVar11 <= _DAT_143834a14)) goto LAB_140ac2b12;
    func_0x000140ab5e30(lVar8);
    cVar9 = '\x01';
  }
  else {
    fStack_88 = *(float *)(param_1 + 0x4b8);
    fStack_80 = *(float *)(param_1 + 0x4c0);
    fStack_84 = 0.0;
    FUN_1402d0740(&fStack_78,&fStack_88);
    if (fStack_74 * *(float *)(param_1 + 0x3bc) + fStack_78 * *(float *)(param_1 + 0x3b8) +
        fStack_70 * *(float *)(param_1 + 0x3c0) < _DAT_143836d08) {
      if (cVar9 == '\0') {
        func_0x000140ab5e30(lVar8);
        puVar4 = (undefined4 *)(param_1 + 0x598);
        *puVar4 = 0xf70f28b4;
        if (*(char *)(lVar8 + 0x282) == '\0') {
          cVar9 = '\x01';
          uVar6 = 0x19190e18;
          if (*(char *)(lVar8 + 0x281) != '\0') {
            uVar6 = 0xfc3030fa;
          }
          *puVar4 = uVar6;
        }
        else {
          *puVar4 = 0xbd08b51b;
          cVar9 = '\x01';
        }
      }
      else {
        if (cVar9 == '\x01') {
          fStack_78 = *pfVar1 - *pfVar2;
          fStack_74 = *(float *)(param_1 + 0x3cc) - *(float *)(param_1 + 0x448);
          fStack_70 = *(float *)(param_1 + 0x3d0) - *(float *)(param_1 + 0x44c);
          FUN_1402d0740(afStack_68,&fStack_78);
          fVar11 = (float)FUN_140876340(afStack_68);
          if (_DAT_143864ed8 < fVar11 * _DAT_143830124) {
            func_0x000140ab5e00(lVar8);
            *(undefined4 *)(param_1 + 0x598) = 0xf70f28b4;
            cVar9 = '\x02';
            *(undefined4 *)(param_1 + 0x598) = 0xa5f21c32;
            goto LAB_140ac28d5;
          }
        }
        *(undefined4 *)(param_1 + 0x598) = 0xf70f28b4;
        if (cVar9 == '\x01') {
          *(undefined4 *)(param_1 + 0x598) = 0xf70f28b4;
        }
      }
LAB_140ac28d5:
      FUN_1420df1c0(param_1 + 0x580,1);
      FUN_1420df1c0(param_1 + 0x58c,cVar9);
      *(undefined8 *)(param_1 + 0x59c) = *(undefined8 *)(param_1 + 0x398);
      *(undefined8 *)(param_1 + 0x5a4) = *(undefined8 *)(param_1 + 0x3a0);
      *(undefined8 *)(param_1 + 0x5ac) = *(undefined8 *)(param_1 + 0x3a8);
      *(undefined8 *)(param_1 + 0x5b4) = *(undefined8 *)(param_1 + 0x3b0);
      *(undefined4 *)(param_1 + 0x5bc) = *(undefined4 *)(param_1 + 0x3b8);
      *(undefined4 *)(param_1 + 0x5c0) = *(undefined4 *)(param_1 + 0x3bc);
      *(undefined4 *)(param_1 + 0x5c4) = *(undefined4 *)(param_1 + 0x3c0);
      *(undefined4 *)(param_1 + 0x5c8) = *(undefined4 *)(param_1 + 0x3c4);
      *(undefined4 *)(param_1 + 0x5cc) = *(undefined4 *)(param_1 + 0x3c8);
      *(undefined4 *)(param_1 + 0x5d0) = *(undefined4 *)(param_1 + 0x3cc);
      *(undefined4 *)(param_1 + 0x5d4) = *(undefined4 *)(param_1 + 0x3d0);
      *(undefined4 *)(param_1 + 0x5d8) = *(undefined4 *)(param_1 + 0x3d4);
      func_0x000140ab5d70(lVar8,*(undefined4 *)(param_1 + 0x598),7);
      goto LAB_140ac2b12;
    }
    if (cVar9 == '\0') {
      func_0x000140ab5e30(lVar8);
      cVar9 = '\x01';
    }
    else if (cVar9 == '\x01') {
      fStack_78 = *pfVar1 - *pfVar2;
      fStack_74 = *(float *)(param_1 + 0x3cc) - *(float *)(param_1 + 0x448);
      fStack_70 = *(float *)(param_1 + 0x3d0) - *(float *)(param_1 + 0x44c);
      FUN_1402d0740(afStack_68,&fStack_78);
      fVar11 = (float)FUN_140876340(afStack_68);
      if (_DAT_143864ed8 < fVar11 * _DAT_143830124) {
        func_0x000140ab5e00(lVar8);
        cVar9 = '\x02';
      }
    }
  }
  FUN_1420df1c0(param_1 + 0x58c,cVar9);
LAB_140ac2b12:
  if ((((float)((uint)(_DAT_143861350 - afStackX_18[0]) & uVar5) < _DAT_14382f0e0) &&
      (fVar10 = (float)FUN_1402c2450(param_1 + 0x4b8), fVar11 = _DAT_14382ee94,
      fVar10 < _DAT_14382ee94)) &&
     ((fVar10 = (float)func_0x0001404c4e20(pfVar1,param_1 + 0x438), fVar10 < fVar11 &&
      (fVar11 = (float)FUN_1420df110(param_1 + 0x580), _DAT_14382e128 < fVar11)))) {
    FUN_1420df1c0(param_1 + 0x580,2);
    *(undefined4 *)(param_1 + 0x598) = 0x1289f384;
    *(undefined8 *)(param_1 + 0x59c) = *(undefined8 *)(param_1 + 0x398);
    *(undefined8 *)(param_1 + 0x5a4) = *(undefined8 *)(param_1 + 0x3a0);
    *(undefined8 *)(param_1 + 0x5ac) = *(undefined8 *)(param_1 + 0x3a8);
    *(undefined8 *)(param_1 + 0x5b4) = *(undefined8 *)(param_1 + 0x3b0);
    *(undefined4 *)(param_1 + 0x5bc) = *(undefined4 *)(param_1 + 0x3b8);
    *(undefined4 *)(param_1 + 0x5c0) = *(undefined4 *)(param_1 + 0x3bc);
    *(undefined4 *)(param_1 + 0x5c4) = *(undefined4 *)(param_1 + 0x3c0);
    *(undefined4 *)(param_1 + 0x5c8) = *(undefined4 *)(param_1 + 0x3c4);
    *(undefined4 *)(param_1 + 0x5cc) = *(undefined4 *)(param_1 + 0x3c8);
    *(undefined4 *)(param_1 + 0x5d0) = *(undefined4 *)(param_1 + 0x3cc);
    *(undefined4 *)(param_1 + 0x5d4) = *(undefined4 *)(param_1 + 0x3d0);
    *(undefined4 *)(param_1 + 0x5d8) = *(undefined4 *)(param_1 + 0x3d4);
    func_0x000140ab5d70(lVar8,0x1289f384,1);
  }
  return;
}


/* SwingRegion_140ac271d @ 0x140ac271d */

/* WARNING: Removing unreachable block (ram,0x000140ac28ca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ac271d(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  undefined4 uVar5;
  longlong unaff_RBX;
  longlong unaff_RBP;
  longlong unaff_RSI;
  float *unaff_R12;
  float *unaff_R13;
  longlong unaff_R14;
  char cVar6;
  bool in_ZF;
  uint uVar7;
  float fVar8;
  float fVar9;
  
  uVar4 = _DAT_14382e160;
  if (in_ZF) goto LAB_140ac2b12;
  cVar6 = *(char *)(unaff_RBX + 0x58c);
  if (cVar6 != '\x02') {
    if ((0.0 < *(float *)(unaff_RBX + 0x4bc) || *(float *)(unaff_RBX + 0x4bc) == 0.0) ||
       (*(float *)(unaff_RBX + 0x4c8) <= 0.0 && *(float *)(unaff_RBX + 0x4c8) != 0.0)) {
      if (cVar6 == '\0') {
        fVar9 = unaff_R12[1];
        fVar8 = *(float *)(unaff_RBX + 0x43c);
        *(float *)(unaff_RBP + -0x19) = *unaff_R12 - *(float *)(unaff_RBX + 0x438);
        fVar2 = unaff_R12[2];
        fVar3 = *(float *)(unaff_RBX + 0x440);
        *(float *)(unaff_RBP + -0x15) = fVar9 - fVar8;
        *(float *)(unaff_RBP + -0x11) = fVar2 - fVar3;
        FUN_1402d0740(unaff_RBP + -9,unaff_RBP + -0x19);
        *(undefined4 *)(unaff_RBP + -0x19) = *(undefined4 *)(unaff_RBP + -9);
        *(undefined4 *)(unaff_RBP + -0x11) = *(undefined4 *)(unaff_RBP + -1);
        *(undefined4 *)(unaff_RBP + -0x15) = 0;
        FUN_1402d0740(unaff_RBP + -0x29,unaff_RBP + -0x19);
        fVar9 = *(float *)(unaff_RBX + 0x4c0);
        fVar8 = *(float *)(unaff_RBP + -0x21) * fVar9 +
                *(float *)(unaff_RBP + -0x29) * *(float *)(unaff_RBX + 0x4b8);
        uVar7 = (uint)(*(float *)(unaff_RBP + -0x25) * fVar8) ^ _DAT_14382e890;
        *(float *)(unaff_RBP + -0x19) =
             *(float *)(unaff_RBX + 0x4b8) - *(float *)(unaff_RBP + -0x29) * fVar8;
        *(uint *)(unaff_RBP + -0x15) = uVar7;
        *(float *)(unaff_RBP + -0x11) = fVar9 - *(float *)(unaff_RBP + -0x21) * fVar8;
        fVar9 = (float)FUN_140876340(unaff_RBP + -9);
        fVar8 = (float)FUN_140876340(unaff_RBX + 0x4d0);
        if (((fVar9 * _DAT_143830124 < _DAT_1438312b0) &&
            ((float)((uint)(fVar8 * _DAT_143830124) & uVar4) < _DAT_14382f2cc)) &&
           (fVar9 = (float)FUN_1402c2450(unaff_RBP + -0x19), _DAT_143834a14 < fVar9)) {
          func_0x000140ab5e30();
          cVar6 = '\x01';
          goto LAB_140ac2aff;
        }
      }
    }
    else {
      uVar5 = *(undefined4 *)(unaff_RBX + 0x4c0);
      *(undefined4 *)(unaff_RBP + -0x29) = *(undefined4 *)(unaff_RBX + 0x4b8);
      *(undefined4 *)(unaff_RBP + -0x21) = uVar5;
      *(undefined4 *)(unaff_RBP + -0x25) = 0;
      FUN_1402d0740(unaff_RBP + -0x19,unaff_RBP + -0x29);
      if (*(float *)(unaff_RBP + -0x15) * *(float *)(unaff_RBX + 0x3bc) +
          *(float *)(unaff_RBP + -0x19) * *(float *)(unaff_RBX + 0x3b8) +
          *(float *)(unaff_RBP + -0x11) * *(float *)(unaff_RBX + 0x3c0) < _DAT_143836d08) {
        if (cVar6 == '\0') {
          func_0x000140ab5e30();
          puVar1 = (undefined4 *)(unaff_RBX + 0x598);
          *puVar1 = 0xf70f28b4;
          if (*(char *)(unaff_R14 + 0x282) == '\0') {
            cVar6 = '\x01';
            uVar5 = 0x19190e18;
            if (*(char *)(unaff_R14 + 0x281) != '\0') {
              uVar5 = 0xfc3030fa;
            }
            *puVar1 = uVar5;
          }
          else {
            *puVar1 = 0xbd08b51b;
            cVar6 = '\x01';
          }
        }
        else {
          if (cVar6 == '\x01') {
            fVar9 = unaff_R12[1];
            fVar8 = unaff_R13[1];
            *(float *)(unaff_RBP + -0x19) = *unaff_R12 - *unaff_R13;
            fVar2 = unaff_R12[2];
            fVar3 = unaff_R13[2];
            *(float *)(unaff_RBP + -0x15) = fVar9 - fVar8;
            *(float *)(unaff_RBP + -0x11) = fVar2 - fVar3;
            FUN_1402d0740(unaff_RBP + -9,unaff_RBP + -0x19);
            fVar9 = (float)FUN_140876340(unaff_RBP + -9);
            if (_DAT_143864ed8 < fVar9 * _DAT_143830124) {
              func_0x000140ab5e00();
              *(undefined4 *)(unaff_RBX + 0x598) = 0xf70f28b4;
              cVar6 = '\x02';
              *(undefined4 *)(unaff_RBX + 0x598) = 0xa5f21c32;
              goto LAB_140ac28d5;
            }
          }
          *(undefined4 *)(unaff_RBX + 0x598) = 0xf70f28b4;
          if (cVar6 == '\x01') {
            *(undefined4 *)(unaff_RBX + 0x598) = 0xf70f28b4;
          }
        }
LAB_140ac28d5:
        unaff_RSI = unaff_RBX + 0x580;
        FUN_1420df1c0(unaff_RSI,1);
        FUN_1420df1c0(unaff_RBX + 0x58c,cVar6);
        *(undefined8 *)(unaff_RBX + 0x59c) = *(undefined8 *)(unaff_RBX + 0x398);
        *(undefined8 *)(unaff_RBX + 0x5a4) = *(undefined8 *)(unaff_RBX + 0x3a0);
        *(undefined8 *)(unaff_RBX + 0x5ac) = *(undefined8 *)(unaff_RBX + 0x3a8);
        *(undefined8 *)(unaff_RBX + 0x5b4) = *(undefined8 *)(unaff_RBX + 0x3b0);
        *(undefined4 *)(unaff_RBX + 0x5bc) = *(undefined4 *)(unaff_RBX + 0x3b8);
        *(undefined4 *)(unaff_RBX + 0x5c0) = *(undefined4 *)(unaff_RBX + 0x3bc);
        *(undefined4 *)(unaff_RBX + 0x5c4) = *(undefined4 *)(unaff_RBX + 0x3c0);
        *(undefined4 *)(unaff_RBX + 0x5c8) = *(undefined4 *)(unaff_RBX + 0x3c4);
        *(undefined4 *)(unaff_RBX + 0x5cc) = *(undefined4 *)(unaff_RBX + 0x3c8);
        *(undefined4 *)(unaff_RBX + 0x5d0) = *(undefined4 *)(unaff_RBX + 0x3cc);
        *(undefined4 *)(unaff_RBX + 0x5d4) = *(undefined4 *)(unaff_RBX + 0x3d0);
        *(undefined4 *)(unaff_RBX + 0x5d8) = *(undefined4 *)(unaff_RBX + 0x3d4);
        func_0x000140ab5d70(*(undefined4 *)(unaff_RBX + 0x3b8),*(undefined4 *)(unaff_RBX + 0x598),7)
        ;
        goto LAB_140ac2b12;
      }
      if (cVar6 == '\0') {
        func_0x000140ab5e30();
        cVar6 = '\x01';
      }
      else if (cVar6 == '\x01') {
        fVar9 = unaff_R12[1];
        fVar8 = unaff_R13[1];
        *(float *)(unaff_RBP + -0x19) = *unaff_R12 - *unaff_R13;
        fVar2 = unaff_R12[2];
        fVar3 = unaff_R13[2];
        *(float *)(unaff_RBP + -0x15) = fVar9 - fVar8;
        *(float *)(unaff_RBP + -0x11) = fVar2 - fVar3;
        FUN_1402d0740(unaff_RBP + -9,unaff_RBP + -0x19);
        fVar9 = (float)FUN_140876340(unaff_RBP + -9);
        if (_DAT_143864ed8 < fVar9 * _DAT_143830124) {
          func_0x000140ab5e00();
          cVar6 = '\x02';
        }
      }
LAB_140ac2aff:
      FUN_1420df1c0(unaff_RBX + 0x58c,cVar6);
    }
  }
  unaff_RSI = unaff_RBX + 0x580;
LAB_140ac2b12:
  if ((((float)((uint)(_DAT_143861350 - *(float *)(unaff_RBP + 0x77)) & uVar4) < _DAT_14382f0e0) &&
      (fVar8 = (float)FUN_1402c2450(unaff_RBX + 0x4b8), fVar9 = _DAT_14382ee94,
      fVar8 < _DAT_14382ee94)) &&
     ((fVar8 = (float)func_0x0001404c4e20(fVar8,unaff_RBX + 0x438), fVar8 < fVar9 &&
      (fVar9 = (float)FUN_1420df110(unaff_RSI), _DAT_14382e128 < fVar9)))) {
    FUN_1420df1c0(unaff_RSI,2);
    *(undefined4 *)(unaff_RBX + 0x598) = 0x1289f384;
    *(undefined8 *)(unaff_RBX + 0x59c) = *(undefined8 *)(unaff_RBX + 0x398);
    *(undefined8 *)(unaff_RBX + 0x5a4) = *(undefined8 *)(unaff_RBX + 0x3a0);
    *(undefined8 *)(unaff_RBX + 0x5ac) = *(undefined8 *)(unaff_RBX + 0x3a8);
    *(undefined8 *)(unaff_RBX + 0x5b4) = *(undefined8 *)(unaff_RBX + 0x3b0);
    *(undefined4 *)(unaff_RBX + 0x5bc) = *(undefined4 *)(unaff_RBX + 0x3b8);
    *(undefined4 *)(unaff_RBX + 0x5c0) = *(undefined4 *)(unaff_RBX + 0x3bc);
    *(undefined4 *)(unaff_RBX + 0x5c4) = *(undefined4 *)(unaff_RBX + 0x3c0);
    *(undefined4 *)(unaff_RBX + 0x5c8) = *(undefined4 *)(unaff_RBX + 0x3c4);
    *(undefined4 *)(unaff_RBX + 0x5cc) = *(undefined4 *)(unaff_RBX + 0x3c8);
    *(undefined4 *)(unaff_RBX + 0x5d0) = *(undefined4 *)(unaff_RBX + 0x3cc);
    *(undefined4 *)(unaff_RBX + 0x5d4) = *(undefined4 *)(unaff_RBX + 0x3d0);
    *(undefined4 *)(unaff_RBX + 0x5d8) = *(undefined4 *)(unaff_RBX + 0x3d4);
    func_0x000140ab5d70(*(undefined4 *)(unaff_RBX + 0x3b8),0x1289f384,1);
  }
  return;
}


/* SwingRegion_140ac2725 @ 0x140ac2725 */

/* WARNING: Removing unreachable block (ram,0x000140ac28ca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ac2725(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  undefined4 uVar5;
  longlong unaff_RBX;
  longlong unaff_RBP;
  longlong unaff_RSI;
  float *unaff_R12;
  float *unaff_R13;
  longlong unaff_R14;
  char cVar6;
  bool in_ZF;
  uint uVar7;
  float fVar8;
  float fVar9;
  
  uVar4 = _DAT_14382e160;
  if (in_ZF) goto LAB_140ac2b12;
  cVar6 = *(char *)(unaff_RBX + 0x58c);
  if (cVar6 != '\x02') {
    if ((0.0 < *(float *)(unaff_RBX + 0x4bc) || *(float *)(unaff_RBX + 0x4bc) == 0.0) ||
       (*(float *)(unaff_RBX + 0x4c8) <= 0.0 && *(float *)(unaff_RBX + 0x4c8) != 0.0)) {
      if (cVar6 == '\0') {
        fVar9 = unaff_R12[1];
        fVar8 = *(float *)(unaff_RBX + 0x43c);
        *(float *)(unaff_RBP + -0x19) = *unaff_R12 - *(float *)(unaff_RBX + 0x438);
        fVar2 = unaff_R12[2];
        fVar3 = *(float *)(unaff_RBX + 0x440);
        *(float *)(unaff_RBP + -0x15) = fVar9 - fVar8;
        *(float *)(unaff_RBP + -0x11) = fVar2 - fVar3;
        FUN_1402d0740(unaff_RBP + -9,unaff_RBP + -0x19);
        *(undefined4 *)(unaff_RBP + -0x19) = *(undefined4 *)(unaff_RBP + -9);
        *(undefined4 *)(unaff_RBP + -0x11) = *(undefined4 *)(unaff_RBP + -1);
        *(undefined4 *)(unaff_RBP + -0x15) = 0;
        FUN_1402d0740(unaff_RBP + -0x29,unaff_RBP + -0x19);
        fVar9 = *(float *)(unaff_RBX + 0x4c0);
        fVar8 = *(float *)(unaff_RBP + -0x21) * fVar9 +
                *(float *)(unaff_RBP + -0x29) * *(float *)(unaff_RBX + 0x4b8);
        uVar7 = (uint)(*(float *)(unaff_RBP + -0x25) * fVar8) ^ _DAT_14382e890;
        *(float *)(unaff_RBP + -0x19) =
             *(float *)(unaff_RBX + 0x4b8) - *(float *)(unaff_RBP + -0x29) * fVar8;
        *(uint *)(unaff_RBP + -0x15) = uVar7;
        *(float *)(unaff_RBP + -0x11) = fVar9 - *(float *)(unaff_RBP + -0x21) * fVar8;
        fVar9 = (float)FUN_140876340(unaff_RBP + -9);
        fVar8 = (float)FUN_140876340(unaff_RBX + 0x4d0);
        if (((fVar9 * _DAT_143830124 < _DAT_1438312b0) &&
            ((float)((uint)(fVar8 * _DAT_143830124) & uVar4) < _DAT_14382f2cc)) &&
           (fVar9 = (float)FUN_1402c2450(unaff_RBP + -0x19), _DAT_143834a14 < fVar9)) {
          func_0x000140ab5e30();
          cVar6 = '\x01';
          goto LAB_140ac2aff;
        }
      }
    }
    else {
      uVar5 = *(undefined4 *)(unaff_RBX + 0x4c0);
      *(undefined4 *)(unaff_RBP + -0x29) = *(undefined4 *)(unaff_RBX + 0x4b8);
      *(undefined4 *)(unaff_RBP + -0x21) = uVar5;
      *(undefined4 *)(unaff_RBP + -0x25) = 0;
      FUN_1402d0740(unaff_RBP + -0x19,unaff_RBP + -0x29);
      if (*(float *)(unaff_RBP + -0x15) * *(float *)(unaff_RBX + 0x3bc) +
          *(float *)(unaff_RBP + -0x19) * *(float *)(unaff_RBX + 0x3b8) +
          *(float *)(unaff_RBP + -0x11) * *(float *)(unaff_RBX + 0x3c0) < _DAT_143836d08) {
        if (cVar6 == '\0') {
          func_0x000140ab5e30();
          puVar1 = (undefined4 *)(unaff_RBX + 0x598);
          *puVar1 = 0xf70f28b4;
          if (*(char *)(unaff_R14 + 0x282) == '\0') {
            cVar6 = '\x01';
            uVar5 = 0x19190e18;
            if (*(char *)(unaff_R14 + 0x281) != '\0') {
              uVar5 = 0xfc3030fa;
            }
            *puVar1 = uVar5;
          }
          else {
            *puVar1 = 0xbd08b51b;
            cVar6 = '\x01';
          }
        }
        else {
          if (cVar6 == '\x01') {
            fVar9 = unaff_R12[1];
            fVar8 = unaff_R13[1];
            *(float *)(unaff_RBP + -0x19) = *unaff_R12 - *unaff_R13;
            fVar2 = unaff_R12[2];
            fVar3 = unaff_R13[2];
            *(float *)(unaff_RBP + -0x15) = fVar9 - fVar8;
            *(float *)(unaff_RBP + -0x11) = fVar2 - fVar3;
            FUN_1402d0740(unaff_RBP + -9,unaff_RBP + -0x19);
            fVar9 = (float)FUN_140876340(unaff_RBP + -9);
            if (_DAT_143864ed8 < fVar9 * _DAT_143830124) {
              func_0x000140ab5e00();
              *(undefined4 *)(unaff_RBX + 0x598) = 0xf70f28b4;
              cVar6 = '\x02';
              *(undefined4 *)(unaff_RBX + 0x598) = 0xa5f21c32;
              goto LAB_140ac28d5;
            }
          }
          *(undefined4 *)(unaff_RBX + 0x598) = 0xf70f28b4;
          if (cVar6 == '\x01') {
            *(undefined4 *)(unaff_RBX + 0x598) = 0xf70f28b4;
          }
        }
LAB_140ac28d5:
        unaff_RSI = unaff_RBX + 0x580;
        FUN_1420df1c0(unaff_RSI,1);
        FUN_1420df1c0(unaff_RBX + 0x58c,cVar6);
        *(undefined8 *)(unaff_RBX + 0x59c) = *(undefined8 *)(unaff_RBX + 0x398);
        *(undefined8 *)(unaff_RBX + 0x5a4) = *(undefined8 *)(unaff_RBX + 0x3a0);
        *(undefined8 *)(unaff_RBX + 0x5ac) = *(undefined8 *)(unaff_RBX + 0x3a8);
        *(undefined8 *)(unaff_RBX + 0x5b4) = *(undefined8 *)(unaff_RBX + 0x3b0);
        *(undefined4 *)(unaff_RBX + 0x5bc) = *(undefined4 *)(unaff_RBX + 0x3b8);
        *(undefined4 *)(unaff_RBX + 0x5c0) = *(undefined4 *)(unaff_RBX + 0x3bc);
        *(undefined4 *)(unaff_RBX + 0x5c4) = *(undefined4 *)(unaff_RBX + 0x3c0);
        *(undefined4 *)(unaff_RBX + 0x5c8) = *(undefined4 *)(unaff_RBX + 0x3c4);
        *(undefined4 *)(unaff_RBX + 0x5cc) = *(undefined4 *)(unaff_RBX + 0x3c8);
        *(undefined4 *)(unaff_RBX + 0x5d0) = *(undefined4 *)(unaff_RBX + 0x3cc);
        *(undefined4 *)(unaff_RBX + 0x5d4) = *(undefined4 *)(unaff_RBX + 0x3d0);
        *(undefined4 *)(unaff_RBX + 0x5d8) = *(undefined4 *)(unaff_RBX + 0x3d4);
        func_0x000140ab5d70(*(undefined4 *)(unaff_RBX + 0x3b8),*(undefined4 *)(unaff_RBX + 0x598),7)
        ;
        goto LAB_140ac2b12;
      }
      if (cVar6 == '\0') {
        func_0x000140ab5e30();
        cVar6 = '\x01';
      }
      else if (cVar6 == '\x01') {
        fVar9 = unaff_R12[1];
        fVar8 = unaff_R13[1];
        *(float *)(unaff_RBP + -0x19) = *unaff_R12 - *unaff_R13;
        fVar2 = unaff_R12[2];
        fVar3 = unaff_R13[2];
        *(float *)(unaff_RBP + -0x15) = fVar9 - fVar8;
        *(float *)(unaff_RBP + -0x11) = fVar2 - fVar3;
        FUN_1402d0740(unaff_RBP + -9,unaff_RBP + -0x19);
        fVar9 = (float)FUN_140876340(unaff_RBP + -9);
        if (_DAT_143864ed8 < fVar9 * _DAT_143830124) {
          func_0x000140ab5e00();
          cVar6 = '\x02';
        }
      }
LAB_140ac2aff:
      FUN_1420df1c0(unaff_RBX + 0x58c,cVar6);
    }
  }
  unaff_RSI = unaff_RBX + 0x580;
LAB_140ac2b12:
  if ((((float)((uint)(_DAT_143861350 - *(float *)(unaff_RBP + 0x77)) & uVar4) < _DAT_14382f0e0) &&
      (fVar8 = (float)FUN_1402c2450(unaff_RBX + 0x4b8), fVar9 = _DAT_14382ee94,
      fVar8 < _DAT_14382ee94)) &&
     ((fVar8 = (float)func_0x0001404c4e20(fVar8,unaff_RBX + 0x438), fVar8 < fVar9 &&
      (fVar9 = (float)FUN_1420df110(unaff_RSI), _DAT_14382e128 < fVar9)))) {
    FUN_1420df1c0(unaff_RSI,2);
    *(undefined4 *)(unaff_RBX + 0x598) = 0x1289f384;
    *(undefined8 *)(unaff_RBX + 0x59c) = *(undefined8 *)(unaff_RBX + 0x398);
    *(undefined8 *)(unaff_RBX + 0x5a4) = *(undefined8 *)(unaff_RBX + 0x3a0);
    *(undefined8 *)(unaff_RBX + 0x5ac) = *(undefined8 *)(unaff_RBX + 0x3a8);
    *(undefined8 *)(unaff_RBX + 0x5b4) = *(undefined8 *)(unaff_RBX + 0x3b0);
    *(undefined4 *)(unaff_RBX + 0x5bc) = *(undefined4 *)(unaff_RBX + 0x3b8);
    *(undefined4 *)(unaff_RBX + 0x5c0) = *(undefined4 *)(unaff_RBX + 0x3bc);
    *(undefined4 *)(unaff_RBX + 0x5c4) = *(undefined4 *)(unaff_RBX + 0x3c0);
    *(undefined4 *)(unaff_RBX + 0x5c8) = *(undefined4 *)(unaff_RBX + 0x3c4);
    *(undefined4 *)(unaff_RBX + 0x5cc) = *(undefined4 *)(unaff_RBX + 0x3c8);
    *(undefined4 *)(unaff_RBX + 0x5d0) = *(undefined4 *)(unaff_RBX + 0x3cc);
    *(undefined4 *)(unaff_RBX + 0x5d4) = *(undefined4 *)(unaff_RBX + 0x3d0);
    *(undefined4 *)(unaff_RBX + 0x5d8) = *(undefined4 *)(unaff_RBX + 0x3d4);
    func_0x000140ab5d70(*(undefined4 *)(unaff_RBX + 0x3b8),0x1289f384,1);
  }
  return;
}


/* SwingRegion_140ac2b34 @ 0x140ac2b34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ac2b34(void)

{
  longlong unaff_RBX;
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_1402c2450(unaff_RBX + 0x4b8);
  fVar2 = _DAT_14382ee94;
  if (fVar1 < _DAT_14382ee94) {
    fVar1 = (float)func_0x0001404c4e20(fVar1,unaff_RBX + 0x438);
    if (fVar1 < fVar2) {
      fVar2 = (float)FUN_1420df110();
      if (_DAT_14382e128 < fVar2) {
        FUN_1420df1c0(fVar2,2);
        *(undefined4 *)(unaff_RBX + 0x598) = 0x1289f384;
        *(undefined8 *)(unaff_RBX + 0x59c) = *(undefined8 *)(unaff_RBX + 0x398);
        *(undefined8 *)(unaff_RBX + 0x5a4) = *(undefined8 *)(unaff_RBX + 0x3a0);
        *(undefined8 *)(unaff_RBX + 0x5ac) = *(undefined8 *)(unaff_RBX + 0x3a8);
        *(undefined8 *)(unaff_RBX + 0x5b4) = *(undefined8 *)(unaff_RBX + 0x3b0);
        *(undefined4 *)(unaff_RBX + 0x5bc) = *(undefined4 *)(unaff_RBX + 0x3b8);
        *(undefined4 *)(unaff_RBX + 0x5c0) = *(undefined4 *)(unaff_RBX + 0x3bc);
        *(undefined4 *)(unaff_RBX + 0x5c4) = *(undefined4 *)(unaff_RBX + 0x3c0);
        *(undefined4 *)(unaff_RBX + 0x5c8) = *(undefined4 *)(unaff_RBX + 0x3c4);
        *(undefined4 *)(unaff_RBX + 0x5cc) = *(undefined4 *)(unaff_RBX + 0x3c8);
        *(undefined4 *)(unaff_RBX + 0x5d0) = *(undefined4 *)(unaff_RBX + 0x3cc);
        *(undefined4 *)(unaff_RBX + 0x5d4) = *(undefined4 *)(unaff_RBX + 0x3d0);
        *(undefined4 *)(unaff_RBX + 0x5d8) = *(undefined4 *)(unaff_RBX + 0x3d4);
        func_0x000140ab5d70(*(undefined4 *)(unaff_RBX + 0x3b8),0x1289f384,1);
      }
    }
  }
  return;
}


/* SwingRegion_140ac2bdd @ 0x140ac2bdd */

void SwingRegion_140ac2bdd(void)

{
  return;
}


/* SwingRegion_140ac2c00 @ 0x140ac2c00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ac2c00(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  undefined4 auStackX_8 [2];
  float afStackX_18 [2];
  float afStackX_20 [2];
  undefined4 uStack_58;
  undefined4 auStack_54 [19];
  
  fVar5 = _DAT_14382dce0;
  if (*(float *)(param_1 + 0x490) <= 0.0 && *(float *)(param_1 + 0x490) != 0.0) {
    fVar2 = (*(float *)(param_1 + 0x4bc) - _DAT_14382f0ec) * _DAT_143858754;
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    if (_DAT_14382dce0 <= fVar2) {
      fVar2 = _DAT_14382dce0;
    }
    *(float *)(param_1 + 0x490) = fVar2;
  }
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    lVar1 = FUN_14167ab40(lVar1 + 0x58,0x146dd6030);
  }
  else {
    lVar1 = func_0x0001416799a0(lVar1 + 0x80);
  }
  auStackX_8[0] = *(undefined4 *)(lVar1 + 400);
  lVar1 = func_0x0001415a0560(auStackX_8);
  if (lVar1 != 0) {
    if (*(short *)(lVar1 + 0x88) == 0) {
      lVar1 = FUN_14167ab40(lVar1 + 0x58,0x147c0b3c0);
    }
    else {
      lVar1 = func_0x0001416799a0(lVar1 + 0x80);
    }
    if (lVar1 != 0) {
      func_0x000141e0c290(lVar1,afStackX_18,afStackX_20);
      func_0x000141e0c280(lVar1,&uStack_58,auStack_54);
      fVar2 = (float)FUN_1420dc660(param_1);
      uVar4 = _DAT_143830128;
      if (_DAT_143848d00 <= fVar2) {
        fVar5 = 0.0;
      }
      fVar5 = fVar5 * *(float *)(param_1 + 0x490);
      fVar2 = afStackX_20[0] + _DAT_1438312b0;
      uVar3 = func_0x000141c477e0(uStack_58,
                                  afStackX_18[0] - (afStackX_18[0] + _DAT_1438312b0) * fVar5,
                                  _DAT_143830128,param_2);
      uVar4 = func_0x000141c477e0(auStack_54[0],afStackX_20[0] - fVar2 * fVar5,uVar4,param_2);
      func_0x000141e0c650(lVar1,uVar3,uVar4,1);
    }
  }
  return;
}


/* SwingRegion_140ac2cb4 @ 0x140ac2cb4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ac2cb4(void)

{
  longlong in_RAX;
  longlong lVar1;
  longlong unaff_RBX;
  bool in_CF;
  bool in_ZF;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float unaff_XMM7_Da;
  float fVar5;
  undefined4 uStackX_20;
  undefined4 uStackX_24;
  float in_stack_00000090;
  float in_stack_00000098;
  
  if (in_CF || in_ZF) {
    lVar1 = FUN_14167ab40(in_RAX + 0x58);
  }
  else {
    lVar1 = func_0x0001416799a0(in_RAX + 0x80);
  }
  if (lVar1 != 0) {
    func_0x000141e0c290(lVar1,&stack0x00000090,&stack0x00000098);
    func_0x000141e0c280(lVar1,&uStackX_20,&uStackX_24);
    fVar2 = (float)FUN_1420dc660();
    uVar4 = _DAT_143830128;
    if (_DAT_143848d00 <= fVar2) {
      unaff_XMM7_Da = 0.0;
    }
    fVar2 = unaff_XMM7_Da * *(float *)(unaff_RBX + 0x490);
    fVar5 = in_stack_00000098 - (in_stack_00000098 + _DAT_1438312b0) * fVar2;
    uVar3 = func_0x000141c477e0(uStackX_20,
                                in_stack_00000090 - (in_stack_00000090 + _DAT_1438312b0) * fVar2,
                                _DAT_143830128);
    uVar4 = func_0x000141c477e0(uStackX_24,fVar5,uVar4);
    func_0x000141e0c650(lVar1,uVar3,uVar4,1);
  }
  return;
}


/* SwingRegion_140ac2ce9 @ 0x140ac2ce9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SwingRegion_140ac2ce9(undefined4 param_1)

{
  longlong unaff_RBX;
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  float unaff_XMM7_Da;
  float fVar4;
  undefined4 uStackX_20;
  undefined4 uStackX_24;
  float in_stack_00000090;
  float in_stack_00000098;
  
  uVar1 = func_0x000141e0c290(param_1,&stack0x00000090);
  func_0x000141e0c280(uVar1,&uStackX_20,&uStackX_24);
  fVar2 = (float)FUN_1420dc660();
  uVar1 = _DAT_143830128;
  if (_DAT_143848d00 <= fVar2) {
    unaff_XMM7_Da = 0.0;
  }
  fVar2 = unaff_XMM7_Da * *(float *)(unaff_RBX + 0x490);
  fVar4 = in_stack_00000098 - (in_stack_00000098 + _DAT_1438312b0) * fVar2;
  uVar3 = func_0x000141c477e0(uStackX_20,
                              in_stack_00000090 - (in_stack_00000090 + _DAT_1438312b0) * fVar2,
                              _DAT_143830128);
  uVar1 = func_0x000141c477e0(uStackX_24,fVar4,uVar1);
  func_0x000141e0c650(uVar1,uVar3,uVar1,1);
  return;
}


/* SwingRegion_140ac2db2 @ 0x140ac2db2 */

void SwingRegion_140ac2db2(void)

{
  return;
}


/* SwingRegion_140ac2dba @ 0x140ac2dba */

void SwingRegion_140ac2dba(void)

{
  return;
}


/* SwingRegion_140ac2dd0 @ 0x140ac2dd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ac2dd0(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  float fVar7;
  float extraout_XMM0_Da;
  float fVar8;
  undefined4 extraout_XMM0_Db;
  undefined4 extraout_XMM0_Dc;
  undefined4 extraout_XMM0_Dd;
  float fVar9;
  float fVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  float fVar15;
  float afStack_68 [24];
  undefined1 auVar14 [16];
  
  fVar7 = (float)FUN_141c58560(*(undefined4 *)(param_1 + 0x4c4));
  uVar3 = FUN_141c58560(*(undefined4 *)(param_1 + 0x4b8));
  uVar2 = _DAT_14382e160;
  fVar9 = _DAT_14382dce0;
  fVar7 = extraout_XMM0_Da - fVar7;
  auVar11._4_4_ = extraout_XMM0_Db;
  auVar11._0_4_ = fVar7;
  auVar11._8_4_ = extraout_XMM0_Dc;
  auVar11._12_4_ = extraout_XMM0_Dd;
  auVar12._4_12_ = auVar11._4_12_;
  auVar12._0_4_ = fVar7 * _DAT_143830660 + _DAT_14382e128;
  iVar6 = (int)auVar12._0_4_;
  if ((iVar6 != -0x80000000) && ((float)iVar6 != auVar12._0_4_)) {
    auVar14._0_8_ = auVar12._0_8_;
    auVar14._8_4_ = extraout_XMM0_Db;
    auVar14._12_4_ = extraout_XMM0_Db;
    auVar13._8_8_ = auVar14._8_8_;
    auVar13._4_4_ = auVar12._0_4_;
    auVar13._0_4_ = auVar12._0_4_;
    uVar4 = movmskps(uVar3,auVar13);
    auVar12 = ZEXT416((uint)(float)(int)(iVar6 - (uVar4 & 1)));
  }
  fVar15 = ((fVar7 - auVar12._0_4_ * _DAT_14383011c) * _DAT_143830124) / *(float *)(param_1 + 0x530)
  ;
  *(float *)(param_1 + 0x54c) = fVar15;
  fVar8 = (float)((uint)*(float *)(param_1 + 0x4cc) & uVar2);
  fVar7 = (float)((uint)*(float *)(param_1 + 0x4c4) & uVar2);
  if (fVar7 <= fVar8) {
    fVar7 = fVar8;
  }
  fVar10 = *(float *)(param_1 + 0x4c4) * (fVar9 / fVar7);
  fVar8 = *(float *)(param_1 + 0x4cc) * (fVar9 / fVar7);
  if ((fVar7 <= 0.0) || (SQRT(fVar8 * fVar8 + fVar10 * fVar10) * fVar7 < _DAT_143830118)) {
    *(undefined4 *)(param_1 + 0x54c) = 0;
    fVar15 = 0.0;
  }
  afStack_68[2] = *(float *)(param_1 + 0x4c0);
  afStack_68[0] = *(float *)(param_1 + 0x4b8);
  fVar7 = (float)((uint)afStack_68[2] & uVar2);
  if (fVar7 <= 0.0) {
    fVar7 = 0.0;
  }
  afStack_68[1] = 0.0;
  if (fVar7 <= (float)((uint)afStack_68[0] & uVar2)) {
    fVar7 = (float)((uint)afStack_68[0] & uVar2);
  }
  if (0.0 < fVar7) {
    afStack_68[2] = (fVar9 / fVar7) * afStack_68[2];
    afStack_68[0] = (fVar9 / fVar7) * afStack_68[0];
    fVar9 = fVar9 / SQRT(afStack_68[2] * afStack_68[2] + afStack_68[0] * afStack_68[0]);
    afStack_68[2] = fVar9 * afStack_68[2];
    afStack_68[0] = fVar9 * afStack_68[0];
  }
  if ((_DAT_14382e120 < *(float *)(param_1 + 0x424)) &&
     (0.0 < afStack_68[2] * *(float *)(param_1 + 0x418) -
            afStack_68[0] * *(float *)(param_1 + 0x420) == 0.0 < fVar15)) {
    func_0x000141c59090(param_1 + 0x418,afStack_68);
  }
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(short *)(lVar1 + 0x88) == 0) {
    uVar5 = FUN_14167ab40(lVar1 + 0x58,0x146dd6030);
  }
  else {
    uVar5 = func_0x0001416799a0(lVar1 + 0x80);
  }
  FUN_140911560(uVar5);
  return;
}


