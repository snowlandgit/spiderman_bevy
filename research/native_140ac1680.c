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
  fVar27 = (float)uVar21 * _DAT_143855568 /* -57.2957763671875 */;
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
  fVar18 = _DAT_1438728c8 /* -0.01745329238474369 */;
  fVar26 = _DAT_143861350 /* 90.0 */;
  uVar8 = _DAT_14382e890 /* -0.0 */;
  uVar7 = _DAT_14382e160 /* None */;
  fVar28 = _DAT_14382e118 /* 9.999999747378752e-05 */;
  fVar6 = _DAT_14382dce0 /* 1.0 */;
  fVar17 = _DAT_14382e128 /* 0.5 */;
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
          fVar17 = _DAT_14382e128 /* 0.5 */;
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
  fVar26 = _DAT_14382f2cc /* 20.0 */;
  if (fVar17 <= fVar18) {
    if ((!bVar5) && (param_2 == '\0')) goto LAB_140ac1a20;
  }
  else if (!bVar5) goto LAB_140ac1a20;
  if (param_3 != '\0') {
LAB_140ac1a20:
    fVar27 = param_5[1];
    if (*(float *)(param_1 + 0x4bc) < fVar27) {
      param_5[1] = (*(float *)(param_1 + 0x4bc) - fVar27) * _DAT_14382e124 /* 0.25 */ + fVar27;
    }
    *param_6 = 24.0;
    uVar19 = FUN_14085fbb0(*(undefined8 *)(param_1 + 8));
    *param_7 = uVar19;
    fVar27 = _DAT_143848d00 /* 0.33000001311302185 */;
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
      fVar17 = ((float)((uint)fVar27 & uVar7) - fVar26) * _DAT_1438ac378 /* 0.02857142873108387 */;
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
  fVar17 = _DAT_14383479c /* 6.0 */;
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
  fVar23 = _DAT_14382e120 /* 0.10000000149011612 */;
  if (((DAT_146dd80b7 != '\0') && (bVar5)) && (_DAT_14382e120 /* 0.10000000149011612 */ < fVar18)) {
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
    fVar18 = (float)func_0x00014041c590(uVar20,_DAT_143836d08 /* 0.30000001192092896 */,fVar6);
    if (fVar28 < fVar18) {
      fVar28 = fVar17;
      fVar25 = _DAT_14382ee94 /* 3.0 */;
      if ((bVar4) && (fVar28 = _DAT_14382f0e4 /* 10.0 */, fVar25 = _DAT_143834a14 /* 4.0 */, !bVar3 && !bVar2)) {
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
                                               *(float *)(lVar11 + 0x14)) * _DAT_143848d00 /* 0.33000001311302185 */ +
                                               *(float *)(lVar11 + 0x14));
    fVar25 = fVar6 - fVar17 * _DAT_14382e128 /* 0.5 */;
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
  fVar17 = _DAT_14382e128 /* 0.5 */;
  if (fVar28 <= fVar27) {
    fVar26 = *(float *)(lVar10 + 0x5b8) - fVar28;
    if ((float)((uint)fVar26 & uVar7) <= _DAT_14382e118 /* 9.999999747378752e-05 */) {
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
    if ((float)((uint)(fVar28 - fVar26) & uVar7) <= _DAT_14382e118 /* 9.999999747378752e-05 */) {
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
  fVar28 = fVar27 * _DAT_1438388c0 /* 1.25 */;
  if (fVar27 * _DAT_1438388c0 /* 1.25 */ <= fVar23) {
    fVar28 = fVar23;
  }
  if (_DAT_14382f0dc /* 2.0 */ <= fVar28) {
    fVar28 = _DAT_14382f0dc /* 2.0 */;
  }
  *(float *)(param_1 + 0x528) = fVar28;
  fVar27 = _DAT_14383fd4c /* 0.3499999940395355 */;
  if (((bVar4) && (param_2 != '\0')) && (fVar27 = fVar28, fVar6 <= fVar28)) {
    fVar27 = fVar6;
  }
  *(float *)(param_1 + 0x52c) = fVar27;
  return;
}


