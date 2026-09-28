/* CMFCTabCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTabCtrl[130] */
/* 007c22ab  CalcRectEdit  32 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCTabCtrl::CalcRectEdit(class CRect &)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCTabCtrl::CalcRectEdit(CMFCTabCtrl *this,CRect *param_1)

{
  InflateRect((LPRECT)param_1,-(*(int *)(this + 0x110) / 2),-1);
  return;
}




/* vtable slots: CMFCTabCtrl[167] */
/* 007c24e8  FUN_007c24e8  41 bytes, 0 callers */

undefined4 FUN_007c24e8(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb0);
  if ((iVar1 == *(int *)(in_ECX + 0x9c)) && (iVar1 != 0)) {
    if (0 < iVar1) {
      return **(undefined4 **)(in_ECX + 0xac);
    }
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  return *(undefined4 *)(in_ECX + 0x2b0);
}




/* vtable slots: CMFCTabCtrl[90] */
/* 007c2686  FUN_007c2686  56 bytes, 0 callers */

void FUN_007c2686(LPRECT param_1,LPRECT param_2)

{
  int in_ECX;
  
  SetRectEmpty(param_1);
  SetRectEmpty(param_2);
  if (*(int *)(in_ECX + 0x90) != 1) {
    param_1 = param_2;
  }
  param_1->left = *(LONG *)(in_ECX + 0x2dc);
  param_1->top = *(LONG *)(in_ECX + 0x2e0);
  param_1->right = *(LONG *)(in_ECX + 0x2e4);
  param_1->bottom = *(LONG *)(in_ECX + 0x2e8);
  return;
}




/* vtable slots: CMFCTabCtrl[95] */
/* 007c26e7  FUN_007c26e7  73 bytes, 0 callers */

int FUN_007c26e7(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0x98] == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1a4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (((in_ECX[0x4b] != 0) && (iVar2 < 2)) || ((in_ECX[0xa1] != 0 && (iVar2 == 0)))) {
      return 0;
    }
  }
  return in_ECX[0x44];
}




/* vtable slots: CMFCTabCtrl[96] */
/* 007c2737  FUN_007c2737  24 bytes, 0 callers */

void FUN_007c2737(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x2dc);
  param_1[1] = *(undefined4 *)(in_ECX + 0x2e0);
  param_1[2] = *(undefined4 *)(in_ECX + 0x2e4);
  param_1[3] = *(undefined4 *)(in_ECX + 0x2e8);
  return;
}




/* vtable slots: CMFCTabCtrl[161] */
/* 007c274f  FUN_007c274f  7 bytes, 0 callers */

undefined4 FUN_007c274f(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28c);
}




/* vtable slots: CMFCTabCtrl[165] */
/* 007c275d  FUN_007c275d  7 bytes, 0 callers */

undefined4 FUN_007c275d(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x270);
}




/* vtable slots: CMFCTabCtrl[160] */
/* 007c2764  FUN_007c2764  7 bytes, 0 callers */

undefined4 FUN_007c2764(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x250);
}




/* vtable slots: CMFCTabCtrl[164] */
/* 007c27a0  FUN_007c27a0  7 bytes, 0 callers */

undefined4 FUN_007c27a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x25c);
}




/* vtable slots: CMFCTabCtrl[162] */
/* 007c27a7  FUN_007c27a7  7 bytes, 0 callers */

undefined4 FUN_007c27a7(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x254);
}




/* vtable slots: CMFCTabCtrl[163] */
/* 007c27c5  FUN_007c27c5  7 bytes, 0 callers */

undefined4 FUN_007c27c5(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 600);
}




/* vtable slots: CMFCTabCtrl[1] */
/* 0080e568  FUN_0080e568  51 bytes, 0 callers */

void FUN_0080e568(byte param_1)

{
  FUN_0080e463();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CMFCTabCtrl[183] */
/* 0080e629  FUN_0080e629  2711 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0080e629(void)

{
  LPRECT ptVar1;
  LPRECT lprc;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  LRESULT LVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  LONG *pLVar12;
  int iVar13;
  int iVar14;
  BOOL BVar15;
  int *in_ECX;
  int local_94;
  int local_90;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  LONG local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  RECT local_54;
  LONG local_44 [4];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xb0;
  local_8 = 0x80e638;
  lprc = (LPRECT)(in_ECX + 0x80);
  in_ECX[0xa5] = 0;
  SetRectEmpty(lprc);
  pcVar2 = *(code **)(*in_ECX + 0x1a4);
  guard_check_icall();
  iVar5 = (*pcVar2)();
  if (iVar5 != 0) {
    pcVar2 = *(code **)(*in_ECX + 0x17c);
    guard_check_icall();
    iVar6 = (*pcVar2)();
    if (iVar6 != 0) {
      iVar6 = 0;
      if ((in_ECX[0x4b] == 0) || (1 < iVar5)) {
        iVar6 = in_ECX[0x3f];
        if ((iVar6 != 0) &&
           ((*(int *)(iVar6 + 0x20) != 0 &&
            (LVar8 = SendMessageW(*(HWND *)(iVar6 + 0x20),0x40d,0,0), LVar8 == 0)))) {
          local_64 = 0;
          local_60 = 0;
          local_5c = 0;
          local_58 = 0;
          FUN_007af3f5(in_ECX,0xffffffff,&local_64,1);
        }
        local_54.left = 0;
        local_54.top = 0;
        local_54.right = 0;
        local_54.bottom = 0;
        FUN_0079dea2(in_ECX);
        local_8 = 0;
        iVar6 = FUN_007c2511();
        iVar6 = FUN_0079efbc(iVar6 + 300);
        if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        local_88 = in_ECX[0xb7] - in_ECX[0xa9];
        local_84 = in_ECX[0x2f];
        in_ECX[0xab] = 0;
        local_7c = 0;
        if (0 < local_84) {
          do {
            iVar11 = 0;
            iVar9 = local_7c;
            if (in_ECX[0x2c] == local_84) {
              piVar7 = (int *)FUN_005db5d0(local_7c);
              iVar9 = *piVar7;
            }
            piVar7 = (int *)FUN_0049a990(iVar9);
            local_80 = 0;
            iVar13 = *piVar7;
            if ((*(int *)(iVar13 + 0xc) != 0) || (*(int *)(iVar13 + 8) != -1)) {
              local_80 = in_ECX[0x35];
            }
            if ((in_ECX[0xa2] != 0) &&
               (((in_ECX[0x95] != 0 || (in_ECX[0x96] != 0)) || (iVar9 == in_ECX[0x30])))) {
              iVar10 = FUN_007c2511();
              FUN_0079efbc(iVar10 + 300);
            }
            local_78 = 0;
            if (*(int *)(iVar13 + 0x34) == 0) {
              *(undefined4 *)(iVar13 + 0x24) = 0;
              local_80 = 0;
            }
            else {
              if (*(int *)(iVar13 + 0x3c) == 0) {
                piVar7 = (int *)FUN_00566800(&local_5c,iVar13 + 4);
                iVar11 = *piVar7;
              }
              local_80 = local_80 + iVar11 + DAT_00a00678 * 2 + DAT_00a0067c;
              *(int *)(iVar13 + 0x24) = local_80;
              if (in_ECX[0x97] == 0) {
                if (in_ECX[0x95] == 0) {
                  if (in_ECX[0x96] == 0) goto LAB_0080e90b;
                  iVar11 = -in_ECX[0xb8];
                }
                else {
                  iVar11 = DAT_00a0067c * 2 - in_ECX[0xb8];
                }
                local_80 = iVar11 + local_80 + in_ECX[0xba];
                *(int *)(iVar13 + 0x24) = local_80;
                local_78 = ((in_ECX[0xba] - in_ECX[0xb8]) - DAT_00a0067c) + -1;
              }
              else {
                iVar11 = in_ECX[0xba] - in_ECX[0xb8];
                if (iVar11 < 0) {
                  iVar11 = iVar11 + 1;
                }
                local_80 = local_80 + (iVar11 >> 1);
                *(int *)(iVar13 + 0x24) = local_80;
                local_78 = (in_ECX[0xba] - in_ECX[0xb8]) / 2;
              }
LAB_0080e90b:
              if ((in_ECX[0xa3] != 0) && (iVar9 == in_ECX[0x30])) {
                local_80 = in_ECX[0xba] + -2 + (local_80 - in_ECX[0xb8]);
                *(int *)(iVar13 + 0x24) = local_80;
              }
            }
            if ((in_ECX[0xa2] != 0) && (iVar9 == in_ECX[0x30])) {
              iVar11 = FUN_007c2511();
              FUN_0079efbc(iVar11 + 0x11c);
              local_80 = *(int *)(iVar13 + 0x24);
            }
            if (((in_ECX[0x99] != 0) && (iVar11 = in_ECX[0xae], 0 < iVar11)) && (iVar11 <= local_80)
               ) {
              local_80 = iVar11;
            }
            local_1c = local_80 + local_88;
            local_20 = in_ECX[0xb8];
            local_18 = in_ECX[0xba] + -2;
            local_24 = local_88;
            ptVar1 = (LPRECT)(iVar13 + 0x10);
            ptVar1->left = local_88;
            *(int *)(iVar13 + 0x14) = local_20;
            *(int *)(iVar13 + 0x18) = local_1c;
            *(int *)(iVar13 + 0x1c) = local_18;
            if (*(int *)(iVar13 + 0x34) == 0) {
              if ((in_ECX[0x3e] != 0) && (*(int *)(in_ECX[0x3e] + 0x20) != 0)) {
                local_34 = 0;
                local_30 = 0;
                local_2c = 0;
                local_28 = 0;
                FUN_007afca9(in_ECX,*(undefined4 *)(iVar13 + 0x28),&local_34);
              }
            }
            else {
              if (in_ECX[0x24] == 1) {
                OffsetRect(ptVar1,0,2);
              }
              if ((in_ECX[0xa4] != 0) && (in_ECX[0xb9] < *(int *)(iVar13 + 0x18))) {
                if ((iVar9 != in_ECX[0x30]) ||
                   ((local_7c != 0 ||
                    (in_ECX[0xb9] - *(int *)(iVar13 + 0x10) < local_78 + DAT_00a00678 * 2)))) {
                  *(undefined4 *)(iVar13 + 0x24) = 0;
                  SetRectEmpty((LPRECT)(iVar13 + 0x10));
                  in_ECX[0xa5] = 1;
                  goto LAB_0080ebc9;
                }
                *(int *)(iVar13 + 0x18) = in_ECX[0xb9];
              }
              if ((in_ECX[0x3e] != 0) && (*(int *)(in_ECX[0x3e] + 0x20) != 0)) {
                if ((*(int *)(iVar13 + 0x40) == 0) && (in_ECX[0x40] == 0)) {
                  bVar3 = false;
                  bVar4 = false;
                }
                else {
                  bVar3 = true;
                  bVar4 = true;
                }
                if ((*(int *)(iVar13 + 0x10) < in_ECX[0xb7]) ||
                   (in_ECX[0xb9] < *(int *)(iVar13 + 0x18))) {
                  bVar3 = true;
                  bVar4 = true;
                }
                if (((in_ECX[0x99] == 0) || (in_ECX[0xae] < 1)) ||
                   (*(int *)(iVar13 + 0x24) <= *(int *)(iVar13 + 0x18) - *(int *)(iVar13 + 0x10))) {
                  if (bVar3) goto LAB_0080eb14;
                  local_44[0] = 0;
                  pLVar12 = local_44;
                  local_44[1] = 0;
                  local_44[2] = 0;
                  local_44[3] = 0;
                }
                else {
                  bVar4 = true;
LAB_0080eb14:
                  local_74 = *(LONG *)(iVar13 + 0x10);
                  pLVar12 = &local_74;
                  uStack_70 = *(undefined4 *)(iVar13 + 0x14);
                  uStack_6c = *(undefined4 *)(iVar13 + 0x18);
                  uStack_68 = *(undefined4 *)(iVar13 + 0x1c);
                }
                FUN_007afca9(in_ECX,*(undefined4 *)(iVar13 + 0x28),pLVar12);
                if ((bVar4) && (iVar9 == in_ECX[0x30])) {
                  local_54.left = ptVar1->left;
                  local_54.top = *(LONG *)(iVar13 + 0x14);
                  local_54.right = *(int *)(iVar13 + 0x18);
                  local_54.bottom = *(LONG *)(iVar13 + 0x1c);
                }
              }
              local_88 = local_88 + 1 + ((*(int *)(iVar13 + 0x18) - ptVar1->left) - local_78);
              in_ECX[0xab] = in_ECX[0xab] + (*(int *)(iVar13 + 0x18) - ptVar1->left) + 1;
              iVar11 = FUN_007f38ad(iVar9);
              if (iVar11 == 0) {
                in_ECX[0xab] = in_ECX[0xab] - local_78;
              }
              if (in_ECX[0x94] != 0) {
                *(int *)(iVar13 + 0x18) = *(int *)(iVar13 + 0x18) + in_ECX[0x44] / 2;
              }
            }
LAB_0080ebc9:
            local_84 = in_ECX[0x2f];
            local_7c = local_7c + 1;
          } while (local_7c < local_84);
        }
        if ((in_ECX[0x99] == 0) && (in_ECX[0xb9] <= local_88)) {
          local_88 = (in_ECX[0xb9] - in_ECX[0xb7]) / iVar5 + -1;
          if (in_ECX[0x97] != 0) {
            iVar11 = ((in_ECX[0xb9] - in_ECX[0xb7]) - (in_ECX[0xba] - in_ECX[0xb8]) / 3) / iVar5;
            local_88 = (in_ECX[0xba] - in_ECX[0xb8]) / 2 + in_ECX[0x35];
            if (local_88 <= iVar11) {
              local_88 = iVar11;
            }
          }
          local_94 = 0;
          local_7c = 0;
          local_78 = iVar5;
          if (0 < local_84) {
            do {
              iVar11 = local_7c;
              if (in_ECX[0x2c] == local_84) {
                piVar7 = (int *)FUN_005db5d0(local_7c);
                iVar11 = *piVar7;
              }
              piVar7 = (int *)FUN_0049a990(iVar11);
              iVar11 = *piVar7;
              if ((*(int *)(iVar11 + 0x34) != 0) && (*(int *)(iVar11 + 0x24) < local_88)) {
                local_94 = local_94 + (local_88 - *(int *)(iVar11 + 0x24));
                local_78 = local_78 + -1;
              }
              local_84 = in_ECX[0x2f];
              local_7c = local_7c + 1;
            } while (local_7c < local_84);
          }
          if (0 < local_78) {
            local_88 = local_94 / local_78 + local_88;
            local_78 = in_ECX[0xb7];
            local_90 = 0;
            if (0 < local_84) {
              do {
                iVar11 = local_90;
                if (in_ECX[0x2c] == local_84) {
                  piVar7 = (int *)FUN_005db5d0(local_90);
                  iVar11 = *piVar7;
                }
                piVar7 = (int *)FUN_0049a990(iVar11);
                iVar9 = *piVar7;
                if (*(int *)(iVar9 + 0x34) == 0) {
                  if ((in_ECX[0x3e] != 0) && (*(int *)(in_ECX[0x3e] + 0x20) != 0)) {
                    local_44[0] = 0;
                    local_44[1] = 0;
                    local_44[2] = 0;
                    local_44[3] = 0;
                    FUN_007afca9(in_ECX,*(undefined4 *)(iVar9 + 0x28),local_44);
                  }
                }
                else {
                  local_7c = 0;
                  if ((*(int *)(iVar9 + 0xc) != 0) || (*(int *)(iVar9 + 8) != -1)) {
                    local_7c = in_ECX[0x35];
                  }
                  iVar10 = *(int *)(iVar9 + 0x24);
                  iVar13 = local_88;
                  if (iVar10 <= local_88) {
                    iVar13 = iVar10;
                  }
                  if (local_88 < DAT_00a0067c + local_7c) {
                    iVar13 = ((in_ECX[0xb9] + in_ECX[0x43] * 2) - in_ECX[0xb7]) / iVar5;
                  }
                  else if ((*(int *)(*(int *)(iVar9 + 4) + -0xc) == 0) ||
                          (*(int *)(iVar9 + 0x3c) != 0)) {
                    iVar13 = local_7c + DAT_00a00678 * 2;
                  }
                  if (in_ECX[0x97] != 0) {
                    iVar14 = in_ECX[0xba] - in_ECX[0xb8];
                    if (iVar14 < 0) {
                      iVar14 = iVar14 + 1;
                    }
                    iVar13 = iVar13 + (iVar14 >> 1) + -1;
                  }
                  local_30 = in_ECX[0xb8];
                  local_34 = local_78;
                  iVar13 = local_78 + iVar13;
                  ptVar1 = (LPRECT)(iVar9 + 0x10);
                  local_28 = in_ECX[0xba] + -2;
                  ptVar1->left = local_78;
                  *(int *)(iVar9 + 0x14) = local_30;
                  *(int *)(iVar9 + 0x18) = iVar13;
                  *(int *)(iVar9 + 0x1c) = local_28;
                  local_2c = iVar13;
                  if (in_ECX[0x94] == 0) {
                    if (in_ECX[0x24] == 1) {
                      OffsetRect(ptVar1,0,2);
                    }
                    if ((in_ECX[0x3e] != 0) && (*(int *)(in_ECX[0x3e] + 0x20) != 0)) {
                      if ((local_88 < iVar10) ||
                         ((*(int *)(iVar9 + 0x40) != 0 || (in_ECX[0x40] != 0)))) {
                        bVar3 = true;
                        piVar7 = &local_74;
                        local_74 = ptVar1->left;
                        uStack_70 = *(undefined4 *)(iVar9 + 0x14);
                        uStack_6c = *(undefined4 *)(iVar9 + 0x18);
                        uStack_68 = *(undefined4 *)(iVar9 + 0x1c);
                      }
                      else {
                        bVar3 = false;
                        piVar7 = &local_24;
                        local_24 = 0;
                        local_20 = 0;
                        local_1c = 0;
                        local_18 = 0;
                      }
                      FUN_007afca9(in_ECX,*(undefined4 *)(iVar9 + 0x28),piVar7);
                      if ((bVar3) && (iVar11 == in_ECX[0x30])) {
                        local_54.left = ptVar1->left;
                        local_54.top = *(LONG *)(iVar9 + 0x14);
                        local_54.right = *(int *)(iVar9 + 0x18);
                        local_54.bottom = *(LONG *)(iVar9 + 0x1c);
                      }
                    }
                  }
                  local_78 = iVar13;
                  if (in_ECX[0x97] != 0) {
                    local_78 = iVar13 - (in_ECX[0xba] - in_ECX[0xb8]) / 2;
                  }
                  if (0 < local_94) {
                    local_78 = local_78 + 1;
                  }
                }
                local_84 = in_ECX[0x2f];
                local_90 = local_90 + 1;
              } while (local_90 < local_84);
            }
          }
        }
        else {
          in_ECX[0xab] = in_ECX[0xab] + in_ECX[0x44] / 2;
        }
        FUN_0079efbc(iVar6);
        if ((in_ECX[0xa3] != 0) && (-1 < in_ECX[0x30])) {
          pcVar2 = *(code **)(*in_ECX + 0x1b8);
          guard_check_icall(in_ECX[0x30],in_ECX + 0x80);
          (*pcVar2)();
          ((LPRECT)(in_ECX + 0x80))->left = (in_ECX[0x82] - in_ECX[0x83]) + in_ECX[0x81];
          InflateRect((LPRECT)(in_ECX + 0x80),-2,-2);
          iVar5 = in_ECX[0x24];
          piVar7 = (int *)FUN_007c2574();
          pcVar2 = *(code **)(*piVar7 + 0x120);
          guard_check_icall(in_ECX);
          iVar6 = (*pcVar2)();
          OffsetRect(lprc,-iVar6,(uint)(iVar5 == 1) * 2 + -1);
          if ((in_ECX[0x3f] != 0) && (*(int *)(in_ECX[0x3f] + 0x20) != 0)) {
            FUN_007afca9(in_ECX,1,lprc);
            piVar7 = (int *)FUN_0049a990(in_ECX[0x30]);
            iVar5 = *piVar7;
            if ((((in_ECX[0x3e] != 0) && (*(int *)(in_ECX[0x3e] + 0x20) != 0)) && (iVar5 != 0)) &&
               (BVar15 = IsRectEmpty(&local_54), BVar15 == 0)) {
              local_54.right = in_ECX[0x80] + -1;
              FUN_007afca9(in_ECX,*(undefined4 *)(iVar5 + 0x28),&local_54);
            }
          }
        }
        FUN_0079dfff();
      }
      else if (0 < in_ECX[0x2f]) {
        do {
          piVar7 = (int *)FUN_0049a990(iVar6);
          SetRectEmpty((LPRECT)(*piVar7 + 0x10));
          iVar6 = iVar6 + 1;
        } while (iVar6 < in_ECX[0x2f]);
      }
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCTabCtrl[184] */
/* 0080f0c1  FUN_0080f0c1  187 bytes, 0 callers */

void FUN_0080f0c1(void)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  int *in_ECX;
  uint uVar4;
  
  if (in_ECX[0x99] == 0) {
LAB_0080f0ce:
    in_ECX[0xa9] = 0;
    in_ECX[0xac] = 0;
    return;
  }
  if (in_ECX[0x2f] == 0) {
    in_ECX[0xaa] = 0;
    goto LAB_0080f0ce;
  }
  uVar3 = ((RECT *)(in_ECX + 0xb7))->left + (in_ECX[0xab] - in_ECX[0xb9]);
  uVar1 = in_ECX[0xa9];
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  in_ECX[0xaa] = uVar3;
  if (((in_ECX[0x95] == 0) && (in_ECX[0x96] == 0)) && (in_ECX[0x97] == 0)) {
    uVar4 = 0;
    if (-1 < (int)uVar1) {
      uVar4 = uVar1;
    }
    if (uVar3 <= uVar4) goto LAB_0080f13f;
  }
  uVar3 = 0;
  if (-1 < (int)uVar1) {
    uVar3 = uVar1;
  }
LAB_0080f13f:
  in_ECX[0xa9] = uVar3;
  if (uVar1 != uVar3) {
    pcVar2 = *(code **)(*in_ECX + 0x2dc);
    guard_check_icall();
    (*pcVar2)();
    InvalidateRect((HWND)in_ECX[8],(RECT *)(in_ECX + 0xb7),1);
    UpdateWindow((HWND)in_ECX[8]);
  }
  FUN_00813636();
  return;
}




/* vtable slots: CMFCTabCtrl[185] */
/* 0080f17c  FUN_0080f17c  264 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0080f17c(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x98] == 0) {
    return;
  }
  local_18.left = in_ECX[0xb7];
  local_18.top = in_ECX[0xb8];
  local_18.right = in_ECX[0xb9];
  local_18.bottom = in_ECX[0xba];
  pcVar1 = *(code **)(*in_ECX + 0x1a4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (((in_ECX[0x4b] == 0) || (1 < iVar2)) && ((in_ECX[0xa1] == 0 || (iVar2 != 0)))) {
    iVar2 = GetSystemMetrics(0x15);
    if (iVar2 * 2 <= in_ECX[0xad]) {
      local_18.right = in_ECX[0xa8];
      local_18.top = local_18.top + 1;
      local_18.bottom = local_18.bottom + -2;
      local_18.left = local_18.right - in_ECX[0xad];
      in_ECX[0xaf] = local_18.left;
      in_ECX[0xb9] = local_18.left + -5;
      in_ECX[0xb0] = local_18.top;
      in_ECX[0xb1] = local_18.right;
      in_ECX[0xb2] = local_18.bottom;
      in_ECX[0xb0] = in_ECX[0xb0] + 1;
      in_ECX[0xb1] = local_18.left;
      in_ECX[0xaf] = local_18.left + -5;
      goto LAB_0080f255;
    }
    SetRectEmpty(&local_18);
  }
  else {
    local_18.bottom = local_18.bottom + -2;
  }
  SetRectEmpty((LPRECT)(in_ECX + 0xaf));
LAB_0080f255:
  FUN_00797e71(0,local_18.left,local_18.top,local_18.right - local_18.left,
               local_18.bottom - local_18.top,0x114);
  return;
}




/* vtable slots: CMFCTabCtrl[189] */
/* 0080f3b4  FUN_0080f3b4  198 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0080f3b4(undefined4 param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  BOOL BVar2;
  int *piVar3;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (((((*(int *)(in_ECX + 0x254) == 0) && (*(int *)(in_ECX + 600) == 0)) &&
       (*(int *)(in_ECX + 0x25c) == 0)) || (*(int *)(in_ECX + 0x2dc) <= *(int *)(param_2 + 0x10)))
     && (*(int *)(param_2 + 0x34) != 0)) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x2cc));
    if ((BVar2 != 0) ||
       (BVar2 = IntersectRect(&local_18,(RECT *)(param_2 + 0x10),(RECT *)(in_ECX + 0x2cc)),
       BVar2 != 0)) {
      piVar3 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar3 + 0xf4);
      guard_check_icall(param_1,((RECT *)(param_2 + 0x10))->left,*(undefined4 *)(param_2 + 0x14),
                        *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                        *(undefined4 *)(in_ECX + 0x104),param_3);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCTabCtrl[190] */
/* 0080f47a  FUN_0080f47a  77 bytes, 0 callers */

void FUN_0080f47a(undefined4 param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(int *)(param_2 + 0x34) != 0) {
    piVar2 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar2 + 0xf4);
    guard_check_icall(param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                      *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                      *(undefined4 *)(in_ECX + 0x104),param_3);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCTabCtrl[191] */
/* 0080f4c7  DrawResizeDragRect  120 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual void __thiscall CMFCTabCtrl::DrawResizeDragRect(class CRect &,class CRect &)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCTabCtrl::DrawResizeDragRect(CMFCTabCtrl *this,CRect *param_1,CRect *param_2)

{
  HWND pHVar1;
  CWnd *pCVar2;
  int iVar3;
  
  pHVar1 = GetDesktopWindow();
  pCVar2 = CWnd::FromHandle(pHVar1);
  FUN_0079dfaa(pCVar2);
  if (*(int *)(this + 0x29f8) == 1) {
    iVar3 = *(int *)(this + 0x314) - *(int *)(this + 0x30c);
  }
  else {
    iVar3 = *(int *)(this + 0x318) - *(int *)(this + 0x310);
  }
  iVar3 = iVar3 / 2 + 1;
  FUN_007a4d4e(param_1,iVar3,iVar3,param_2,iVar3,iVar3,0,0);
  FUN_0079e0f8();
  return;
}




/* vtable slots: CMFCTabCtrl[129] */
/* 0080f588  FUN_0080f588  25 bytes, 0 callers */

void FUN_0080f588(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x250) != 0) {
    *(undefined4 *)(in_ECX + 0x154) = param_1;
  }
  return;
}




/* vtable slots: CMFCTabCtrl[137] */
/* 0080f66f  FUN_0080f66f  527 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0080f66f(int param_1)

{
  code *pcVar1;
  int *piVar2;
  BOOL BVar3;
  int *in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((param_1 < 0) || (in_ECX[0x2f] <= param_1)) {
    return 0;
  }
  if ((in_ECX[0x99] != 0) && (in_ECX[0xb9] != in_ECX[0xb7] && -1 < in_ECX[0xb9] - in_ECX[0xb7])) {
    piVar2 = (int *)FUN_0049a990(param_1);
    iVar5 = *piVar2;
    local_18.left = *(int *)(iVar5 + 0x10);
    local_18.top = *(LONG *)(iVar5 + 0x14);
    local_18.right = *(int *)(iVar5 + 0x18);
    local_18.bottom = *(LONG *)(iVar5 + 0x1c);
    if (in_ECX[0xa4] == 0) {
      if (((in_ECX[0x95] == 0) && (in_ECX[0x96] == 0)) && (in_ECX[0x97] == 0)) {
        iVar5 = in_ECX[0xb7];
        if (local_18.left < iVar5) {
          in_ECX[0xa9] = in_ECX[0xa9] + (local_18.left - iVar5);
        }
        else {
          iVar6 = in_ECX[0xb9];
          if (local_18.right <= iVar6) {
            return 1;
          }
          if (iVar6 - iVar5 < local_18.right - local_18.left) {
            return 1;
          }
          in_ECX[0xa9] = in_ECX[0xa9] + (local_18.right - iVar6);
        }
      }
      else {
        if ((in_ECX[0xb7] <= local_18.left) && (local_18.right <= in_ECX[0xb9])) {
          return 1;
        }
        iVar5 = 0;
        local_1c = 0;
        iVar6 = ((in_ECX[0xba] - in_ECX[0xb8]) - DAT_00a0067c) + -1;
        do {
          piVar2 = (int *)FUN_0049a990(iVar5);
          local_1c = local_1c + ((*(int *)(*piVar2 + 0x18) - *(int *)(*piVar2 + 0x10)) - iVar6);
          iVar5 = iVar5 + 1;
        } while (iVar5 <= param_1);
        in_ECX[0xa9] = 0;
        in_ECX[0xac] = 0;
        if (0 < param_1) {
          iVar5 = 0;
          do {
            if (local_1c <= in_ECX[0xb9] - in_ECX[0xb7]) break;
            if ((iVar5 < 0) || (in_ECX[0x27] <= iVar5)) {
                    /* WARNING: Subroutine does not return */
              FUN_0078e714();
            }
            iVar4 = *(int *)(in_ECX[0x26] + iVar5 * 4);
            iVar4 = (*(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 0x10)) - iVar6;
            in_ECX[0xa9] = in_ECX[0xa9] + iVar4;
            local_1c = local_1c - iVar4;
            iVar5 = iVar5 + 1;
            in_ECX[0xac] = iVar5;
          } while (iVar5 < param_1);
        }
      }
      pcVar1 = *(code **)(*in_ECX + 0x2dc);
      guard_check_icall();
      (*pcVar1)();
      pcVar1 = *(code **)(*in_ECX + 0x2e0);
      guard_check_icall();
      (*pcVar1)();
      RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x105);
    }
    else if ((in_ECX[0xb9] < *(int *)(iVar5 + 0x24) + local_18.left) ||
            (BVar3 = IsRectEmpty(&local_18), BVar3 != 0)) {
      FUN_0080919e(param_1,0);
    }
  }
  return 1;
}




/* vtable slots: CMFCTabCtrl[147] */
/* 0080f87f  FUN_0080f87f  114 bytes, 0 callers */

CWnd * FUN_0080f87f(POINT *param_1)

{
  int *piVar1;
  BOOL BVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int in_ECX;
  int iVar5;
  
  if (param_1->y < *(int *)(in_ECX + 0x110)) {
LAB_0080f8e8:
    pCVar4 = (CWnd *)0x0;
  }
  else {
    iVar5 = 0;
    if (0 < *(int *)(in_ECX + 0xbc)) {
      do {
        piVar1 = (int *)FUN_0049a990(iVar5);
        if ((*(int *)(*piVar1 + 0x34) != 0) &&
           (BVar2 = PtInRect((RECT *)(*piVar1 + 0x10),*param_1), BVar2 != 0)) goto LAB_0080f8e8;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(in_ECX + 0xbc));
    }
    pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar4 = CWnd::FromHandle(pHVar3);
  }
  return pCVar4;
}




/* vtable slots: CMFCTabCtrl[10] */
/* 0080f911  FUN_0080f911  6 bytes, 0 callers */

undefined ** FUN_0080f911(void)

{
  return &PTR_FUN_0098ddc0;
}




/* vtable slots: CMFCTabCtrl[0] */
/* 0080f917  FUN_0080f917  6 bytes, 0 callers */

undefined ** FUN_0080f917(void)

{
  return &PTR_s_CMFCTabCtrl_0098d8b8;
}




/* vtable slots: CMFCTabCtrl[134] */
/* 0080f91d  FUN_0080f91d  373 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0080f91d(POINT *param_1)

{
  BOOL BVar1;
  int iVar2;
  int *piVar3;
  CMFCBaseTabCtrl *in_ECX;
  int iVar4;
  int iVar5;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  BVar1 = PtInRect((RECT *)(in_ECX + 0x2dc),*param_1);
  if (BVar1 != 0) {
    if (((*(int *)(in_ECX + 0x254) == 0) && (*(int *)(in_ECX + 600) == 0)) &&
       (*(int *)(in_ECX + 0x25c) == 0)) {
      iVar2 = CMFCBaseTabCtrl::GetTabFromPoint(in_ECX,(CPoint *)param_1);
      return iVar2;
    }
    if (-1 < *(int *)(in_ECX + 0xc0)) {
      iVar2 = FUN_004b0e80(*(int *)(in_ECX + 0xc0));
      local_18.left = *(int *)(iVar2 + 0x10);
      local_18.top = *(int *)(iVar2 + 0x14);
      local_18.right = *(LONG *)(iVar2 + 0x18);
      local_18.bottom = *(int *)(iVar2 + 0x1c);
      BVar1 = PtInRect(&local_18,*param_1);
      if (BVar1 != 0) {
        iVar2 = FUN_007f38ad(*(undefined4 *)(in_ECX + 0xc0));
        if (iVar2 == 0) {
          iVar2 = local_18.bottom - local_18.top;
          if ((param_1->x < iVar2 + local_18.left) &&
             (iVar5 = param_1->x - local_18.left, iVar4 = param_1->y - local_18.top,
             iVar4 * iVar4 + iVar5 * iVar5 < (iVar2 * iVar2) / 2)) {
            iVar2 = *(int *)(in_ECX + 0xc0);
            while (iVar2 = iVar2 + -1, -1 < iVar2) {
              iVar4 = FUN_004b0e80(iVar2);
              if (*(int *)(iVar4 + 0x34) != 0) {
                return iVar2;
              }
            }
          }
        }
        return *(int *)(in_ECX + 0xc0);
      }
    }
    iVar2 = *(int *)(in_ECX + 0xbc);
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        iVar5 = iVar4;
        if (*(int *)(in_ECX + 0xb0) == iVar2) {
          piVar3 = (int *)FUN_00799cf8(iVar4);
          iVar5 = *piVar3;
        }
        iVar2 = FUN_004b0e80(iVar5);
        if ((*(int *)(iVar2 + 0x34) != 0) &&
           (BVar1 = PtInRect((RECT *)(iVar2 + 0x10),*param_1), BVar1 != 0)) {
          return iVar5;
        }
        iVar2 = *(int *)(in_ECX + 0xbc);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
  }
  return -1;
}




/* vtable slots: CMFCTabCtrl[169] */
/* 0080fb1a  FUN_0080fb1a  65 bytes, 0 callers */

void FUN_0080fb1a(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  if ((in_ECX[0x4b] != param_1) && (in_ECX[0x4b] = param_1, in_ECX[8] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x184);
    guard_check_icall();
    (*pcVar1)();
    FUN_00813563(0);
  }
  return;
}




/* vtable slots: CMFCTabCtrl[188] */
/* 0080fb5b  FUN_0080fb5b  35 bytes, 0 callers */

undefined4 FUN_0080fb5b(void)

{
  HWND pHVar1;
  CWnd *pCVar2;
  undefined4 uVar3;
  int in_ECX;
  
  pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar2 = CWnd::FromHandle(pHVar1);
  if (pCVar2 != (CWnd *)0x0) {
    uVar3 = FUN_0079d98a(&PTR_s_CMDIClientAreaWnd_0099c578);
    return uVar3;
  }
  return 0;
}




/* vtable slots: CMFCTabCtrl[89] */
/* 0080fb7e  FUN_0080fb7e  26 bytes, 0 callers */

void FUN_0080fb7e(LONG param_1,LONG param_2)

{
  POINT pt;
  int in_ECX;
  
  pt.y = param_2;
  pt.x = param_1;
  PtInRect((RECT *)(in_ECX + 0x2dc),pt);
  return;
}




/* vtable slots: CMFCTabCtrl[153] */
/* 0080fc0d  FUN_0080fc0d  88 bytes, 0 callers */

void FUN_0080fc0d(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_0080919e(param_1,param_2);
  if (((in_ECX[0x95] != 0) || (in_ECX[0x96] != 0)) || (in_ECX[0x97] != 0)) {
    in_ECX[0xa9] = 0;
    in_ECX[0xac] = 0;
    pcVar1 = *(code **)(*in_ECX + 0x224);
    guard_check_icall(in_ECX[0x30]);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCTabCtrl[61] */
/* 0080fcec  FUN_0080fcec  745 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0080fcec(undefined4 param_1,int param_2)

{
  CMFCTabButton *this;
  HWND hWnd;
  code *pcVar1;
  LONG LVar2;
  LONG LVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  BOOL BVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *in_ECX;
  int iVar11;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_2 == 0) {
    uVar4 = FUN_00793275(param_1,0);
    return uVar4;
  }
  iVar10 = in_ECX[0xa9];
  if ((in_ECX == (int *)0xfffffc50) || (param_2 != in_ECX[0xf4])) {
    this = (CMFCTabButton *)(in_ECX + 0x2d6);
    if ((this == (CMFCTabButton *)0x0) || (param_2 != in_ECX[0x2de])) {
      if ((in_ECX == (int *)0xffffed00) || (param_2 != in_ECX[0x4c8])) {
        if ((in_ECX == (int *)0xffffe558) || (param_2 != in_ECX[0x6b2])) {
          if ((in_ECX != (int *)0xffffddb0) && (param_2 == in_ECX[0x89c])) {
            pcVar1 = *(code **)(*in_ECX + 0x210);
            guard_check_icall();
            iVar10 = (*pcVar1)();
            if (iVar10 == 0) {
              return 1;
            }
            SendMessageW(*(HWND *)(iVar10 + 0x20),0x10,0,0);
            return 1;
          }
          goto LAB_0080fe5b;
        }
        iVar8 = in_ECX[0xaa];
        goto LAB_0080ff0c;
      }
      in_ECX[0xa9] = 0;
    }
    else {
      if (in_ECX[0xa4] != 0) {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetWindowRect((HWND)in_ECX[0x2de],&local_18);
        CMFCTabButton::SetPressed(this,1);
        LVar3 = local_18.bottom;
        LVar2 = local_18.left;
        local_1c = local_18.left;
        uVar6 = FUN_00797acc();
        if ((uVar6 & 0x400000) != 0) {
          local_1c = LVar2 + (local_18.right - local_18.left);
        }
        SendMessageW((HWND)in_ECX[0x2de],0x1f,0,0);
        hWnd = (HWND)in_ECX[8];
        CMFCTabButton::SetPressed(this,1);
        pcVar1 = *(code **)(*in_ECX + 0x2ec);
        guard_check_icall(local_1c,LVar3);
        (*pcVar1)();
        BVar7 = IsWindow(hWnd);
        if (BVar7 == 0) {
          return 1;
        }
        CMFCTabButton::SetPressed((CMFCTabButton *)(in_ECX + 0x2d6),0);
LAB_0080fe5b:
        uVar4 = FUN_00793275(param_1,param_2);
        return uVar4;
      }
      if (((in_ECX[0x95] == 0) && (in_ECX[0x96] == 0)) && (in_ECX[0x97] == 0)) {
        iVar8 = iVar10 + 0x14;
        goto LAB_0080ff0c;
      }
      if (in_ECX[0xac] < in_ECX[0x2f]) {
        piVar5 = (int *)FUN_0049a990(in_ECX[0xac]);
        in_ECX[0xa9] = in_ECX[0xa9] +
                       DAT_00a0067c + 1 +
                       (((in_ECX[0xb8] - in_ECX[0xba]) + *(int *)(*piVar5 + 0x18)) -
                       *(int *)(*piVar5 + 0x10));
        in_ECX[0xac] = in_ECX[0xac] + 1;
      }
    }
  }
  else if (((in_ECX[0x95] == 0) && (in_ECX[0x96] == 0)) && (in_ECX[0x97] == 0)) {
    iVar8 = iVar10 + -0x14;
LAB_0080ff0c:
    in_ECX[0xa9] = iVar8;
  }
  else if (0 < in_ECX[0xac]) {
    piVar5 = (int *)FUN_0049a990(in_ECX[0xac] + -1);
    in_ECX[0xa9] = in_ECX[0xa9] +
                   *(int *)(*piVar5 + 0x10) + -2 +
                   (((in_ECX[0xba] - in_ECX[0xb8]) - *(int *)(*piVar5 + 0x18)) - DAT_00a0067c);
    in_ECX[0xac] = in_ECX[0xac] + -1;
  }
  if (((in_ECX[0x95] == 0) && (in_ECX[0x96] == 0)) && (in_ECX[0x97] == 0)) {
    iVar8 = in_ECX[0xa9];
    iVar11 = 0;
    if (-1 < iVar8) {
      iVar11 = iVar8;
    }
    iVar9 = in_ECX[0xaa];
    if (iVar9 <= iVar11) goto LAB_0080ff52;
  }
  else {
    iVar8 = in_ECX[0xa9];
  }
  iVar9 = iVar8;
  if (iVar9 < 0) {
    iVar9 = 0;
  }
LAB_0080ff52:
  in_ECX[0xa9] = iVar9;
  if (iVar10 != iVar9) {
    pcVar1 = *(code **)(*in_ECX + 0x2dc);
    guard_check_icall();
    (*pcVar1)();
    FUN_00813636();
    InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
    UpdateWindow((HWND)in_ECX[8]);
  }
  return 1;
}




/* vtable slots: CMFCTabCtrl[182] */
/* 008104db  FUN_008104db  3149 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008104db(CDC *param_1)

{
  code *pcVar1;
  LONG LVar2;
  int *piVar3;
  tagRECT *ptVar4;
  int iVar5;
  HRGN pHVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  BOOL BVar9;
  HBRUSH pHVar10;
  int *piVar11;
  code *pcVar12;
  CDC *pCVar13;
  ulong uVar14;
  undefined **local_c0 [2];
  int local_b8;
  ulong local_b4;
  undefined4 local_b0;
  undefined **local_ac;
  code *local_a8;
  undefined **local_a4;
  code *local_a0;
  int local_9c;
  int local_98;
  undefined **local_94 [2];
  undefined **local_8c [2];
  ulong local_84;
  ulong local_80;
  ulong local_7c;
  int local_78;
  ulong local_74;
  undefined **local_70;
  int *local_6c;
  undefined1 local_68 [4];
  code *local_64;
  int *local_60;
  int local_5c;
  CDC *local_58;
  tagRECT local_54;
  tagRECT local_44;
  tagRECT local_34;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xb0;
  local_8 = 0x8104ea;
  local_78 = 0;
  local_98 = 0;
  local_58 = param_1;
  piVar3 = (int *)FUN_007c2574();
  pcVar12 = *(code **)(*piVar3 + 0x10c);
  guard_check_icall(local_60,&local_74,&local_b0,&local_80,&local_7c,&local_84,&local_b4,&local_78,
                    &local_98);
  (*pcVar12)();
  piVar3 = local_60;
  local_44.left = 0;
  local_44.top = 0;
  local_44.right = 0;
  local_44.bottom = 0;
  GetClientRect((HWND)local_60[8],&local_44);
  local_b8 = FUN_0079efbc(local_78);
  if (local_b8 == 0) goto LAB_00811123;
  FUN_0079df60(0,1,local_74);
  local_8 = 0;
  FUN_0079df60(0,1,local_b0);
  local_8._0_1_ = 1;
  FUN_0079df60(0,1,local_80);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_9c = FUN_0079efbc(local_94);
  if (local_9c == 0) goto LAB_00811123;
  pcVar12 = *(code **)(*piVar3 + 0x248);
  guard_check_icall();
  local_5c = (*pcVar12)();
  piVar3 = local_60;
  local_ac = (undefined **)local_44.left;
  local_a8 = (code *)local_44.top;
  local_a4 = (undefined **)local_44.right;
  local_a0 = (code *)local_44.bottom;
  if (local_60[0x24] == 0) {
    local_a8 = (code *)local_60[0xb8];
  }
  else {
    local_a0 = (code *)local_60[0xba];
  }
  FUN_0079ea67(local_60 + 0xbb);
  local_6c = (int *)FUN_007c2574();
  pCVar13 = local_58;
  local_64 = *(code **)(*local_6c + 0x110);
  guard_check_icall(local_58,local_44.left,local_44.top,local_44.right,local_44.bottom,piVar3);
  local_6c = (int *)(*local_64)();
  piVar3 = local_60;
  if ((local_60[0xa0] == 0) && (local_6c == (int *)0x0)) {
    pHVar10 = (HBRUSH)0x0;
    if (local_78 != 0) {
      pHVar10 = *(HBRUSH *)(local_78 + 4);
    }
    FillRect(*(HDC *)(pCVar13 + 4),&local_44,pHVar10);
  }
  local_64 = (code *)FUN_007c2574();
  local_34.bottom = *(undefined4 *)(*(int *)local_64 + 0xf0);
  guard_check_icall(local_58,local_ac,local_a8,local_a4,local_a0,piVar3);
  (*(code *)local_34.bottom)();
  pCVar13 = local_58;
  piVar3 = local_60;
  local_24.left = local_44.left;
  local_24.top = local_44.top;
  local_24.right = local_44.right;
  local_24.bottom = local_44.bottom;
  iVar5 = local_60[0x24];
  if (local_5c == 0) {
    if (iVar5 == 0) {
      local_24.bottom = local_60[0xb8] + 1;
    }
    else {
      local_24.top = local_60[0xba] + -1;
    }
    iVar5 = local_98;
    if (local_60[0x94] == 0) {
      iVar5 = local_78;
    }
    pHVar10 = (HBRUSH)0x0;
    if (iVar5 != 0) {
      pHVar10 = *(HBRUSH *)(iVar5 + 4);
    }
    FrameRect(*(HDC *)(local_58 + 4),&local_24,pHVar10);
  }
  else {
    if (iVar5 == 0) {
      local_64 = (code *)local_60[0xb8];
    }
    else {
      local_64 = (code *)local_60[0xba];
    }
    if (local_60[0x94] == 0) {
      if (iVar5 == 0) {
        local_24.bottom = local_60[0xb8];
      }
      else {
        local_24.top = local_60[0xba];
      }
    }
    if (local_60[0x9c] == 0) {
      if (local_60[0xa0] != 0) {
        CDC::Draw3dRect(local_58,&local_24,local_80,local_84);
        InflateRect(&local_24,-1,-1);
        CDC::Draw3dRect(pCVar13,&local_24,local_b4,local_74);
        InflateRect(&local_24,-1,-1);
        if (((local_6c == (int *)0x0) &&
            (local_24.right != local_24.left && -1 < local_24.right - local_24.left)) &&
           (0 < local_24.bottom - local_24.top)) {
          PatBlt(*(HDC *)(pCVar13 + 4),local_24.left,local_24.top,local_5c,
                 local_24.bottom - local_24.top,0xf00021);
          PatBlt(*(HDC *)(pCVar13 + 4),local_24.left,local_24.top,local_24.right - local_24.left,
                 local_5c,0xf00021);
          PatBlt(*(HDC *)(pCVar13 + 4),local_24.right - local_5c,local_24.top,local_5c,
                 local_24.bottom - local_24.top,0xf00021);
          PatBlt(*(HDC *)(pCVar13 + 4),local_24.left,local_24.bottom - local_5c,
                 local_24.right - local_24.left,local_5c,0xf00021);
          if (piVar3[0x24] == 0) {
            iVar5 = local_24.bottom - piVar3[0xbe];
            pcVar12 = (code *)piVar3[0xbe];
          }
          else {
            iVar5 = piVar3[0xbc] - local_24.top;
            pcVar12 = (code *)local_24.top;
          }
          PatBlt(*(HDC *)(pCVar13 + 4),local_24.left,(int)pcVar12,local_24.right - local_24.left,
                 iVar5,0xf00021);
          if (piVar3[0x94] != 0) {
            FUN_0079efbc(local_8c);
            FUN_0079ec58(&local_a4,local_24.left + local_5c,local_64);
            CDC::LineTo(pCVar13,local_24.right - local_5c,(int)local_64);
          }
          if (2 < local_5c) {
            InflateRect(&local_24,2 - local_5c,2 - local_5c);
          }
          if ((local_24.right != local_24.left && -1 < local_24.right - local_24.left) &&
             (local_24.bottom != local_24.top && -1 < local_24.bottom - local_24.top)) {
            ptVar4 = &local_24;
            local_7c = local_84;
            uVar14 = local_80;
            goto LAB_00810b63;
          }
        }
        else {
          InflateRect(&local_24,-2,-2);
        }
      }
    }
    else {
      local_34.left = local_44.left;
      local_34.top = local_24.top;
      local_34.right = local_44.right;
      local_34.bottom = local_24.bottom;
      if (local_60[0x94] != 0) {
        if (iVar5 == 0) {
          local_34.bottom = local_60[0xb8] + 1;
        }
        else {
          local_34.top = local_60[0xba] + -1;
        }
      }
      InflateRect(&local_24,-1,-1);
      pCVar13 = local_58;
      if (((piVar3[0xa0] != 0) && (local_6c == (int *)0x0)) &&
         ((local_24.right != local_24.left && -1 < local_24.right - local_24.left &&
          (0 < local_24.bottom - local_24.top)))) {
        PatBlt(*(HDC *)(local_58 + 4),local_24.left,local_24.top,local_5c,
               local_24.bottom - local_24.top,0xf00021);
        PatBlt(*(HDC *)(pCVar13 + 4),local_24.left,local_24.top,local_24.right - local_24.left,
               local_5c,0xf00021);
        PatBlt(*(HDC *)(pCVar13 + 4),local_24.right + (-1 - local_5c),local_24.top,local_5c + 1,
               local_24.bottom - local_24.top,0xf00021);
        PatBlt(*(HDC *)(pCVar13 + 4),local_24.left,local_24.bottom - local_5c,
               local_24.right - local_24.left,local_5c,0xf00021);
        if (piVar3[0x24] == 0) {
          iVar5 = local_24.bottom - piVar3[0xbe];
          pcVar12 = (code *)piVar3[0xbe];
        }
        else {
          iVar5 = piVar3[0xbc] - local_24.top;
          pcVar12 = (code *)local_24.top;
        }
        PatBlt(*(HDC *)(pCVar13 + 4),local_24.left,(int)pcVar12,local_24.right - local_24.left,iVar5
               ,0xf00021);
      }
      if (piVar3[0x94] != 0) {
        FUN_0079efbc(local_8c);
        FUN_0079ec58(&local_a4,local_24.left + local_5c,local_64);
        CDC::LineTo(pCVar13,local_24.right - local_5c,(int)local_64);
      }
      CDC::Draw3dRect(pCVar13,&local_34,local_7c,local_7c);
      pcVar12 = *(code **)(*piVar3 + 0x17c);
      guard_check_icall();
      iVar5 = (*pcVar12)();
      pCVar13 = local_58;
      if (iVar5 == 0) {
        ptVar4 = &local_34;
        uVar14 = local_7c;
LAB_00810b63:
        CDC::Draw3dRect(pCVar13,ptVar4,local_7c,uVar14);
      }
      else {
        if (piVar3[0xa0] != 0) {
          CDC::Draw3dRect(local_58,&local_34,local_74,local_74);
        }
        if (piVar3[0x95] == 0) {
          local_64 = (code *)(local_34.right + -1);
          if (piVar3[0xa0] == 0) {
            local_64 = (code *)((int)local_64 - local_5c);
          }
          if (piVar3[0x24] == 0) {
            FUN_0079efbc(local_8c);
            FUN_0079ec58(&local_a4,local_34.left,(code *)(local_34.bottom + -1));
            pcVar12 = (code *)(local_34.bottom + -1);
          }
          else {
            FUN_0079efbc(local_c0);
            FUN_0079ec58(&local_a4,local_34.left,local_34.top);
            pcVar12 = (code *)local_34.top;
          }
          CDC::LineTo(pCVar13,(int)local_64,(int)pcVar12);
        }
      }
    }
  }
  if ((piVar3[0x9f] != 0) && (piVar3[0x24] == 1)) {
    FUN_0079efbc(local_94);
    FUN_0079ec58(&local_a4,local_44.left,piVar3[0xba]);
    CDC::LineTo(pCVar13,local_44.left,local_44.top);
    CDC::LineTo(pCVar13,local_44.right + -1,local_44.top);
    CDC::LineTo(pCVar13,local_44.right + -1,piVar3[0xba]);
  }
  pcVar12 = *(code **)(*(int *)pCVar13 + 0x28);
  iVar5 = FUN_007c2511();
  guard_check_icall(iVar5 + 0x11c);
  local_a0 = (code *)(*pcVar12)();
  pCVar13 = local_58;
  if (local_a0 != (code *)0x0) {
    FUN_0079f0b8(1);
    pcVar12 = *(code **)(*(int *)pCVar13 + 0x30);
    iVar5 = FUN_007c2511();
    guard_check_icall(*(undefined4 *)(iVar5 + 0x28));
    (*pcVar12)();
    pCVar13 = local_58;
    if ((5 < piVar3[0xb9] - piVar3[0xb7]) && (5 < piVar3[0xba] - piVar3[0xb8])) {
      local_54.left = piVar3[0xb7];
      local_54.top = piVar3[0xb8];
      local_54.right = piVar3[0xb9];
      local_54.bottom = piVar3[0xba];
      InflateRect(&local_54,1,local_5c);
      local_34.bottom = 0;
      local_34.right = (LONG)CRgn::vftable;
      local_8 = CONCAT31(local_8._1_3_,3);
      pHVar6 = CreateRectRgnIndirect(&local_54);
      Attach(pHVar6);
      piVar3 = local_60;
      local_64 = (code *)local_60[0x2f];
      while (piVar11 = (int *)((int)local_64 + -1), local_64 = (code *)piVar11, -1 < (int)piVar11) {
        if (piVar3[0x2c] == piVar3[0x2f]) {
          puVar7 = (undefined4 *)FUN_005db5d0(piVar11);
          piVar11 = (int *)*puVar7;
        }
        local_6c = (int *)FUN_0049a990(piVar11);
        local_6c = (int *)*local_6c;
        if ((*(int *)((int)local_6c + 0x34) != 0) &&
           (piVar3[0x41] = (int)piVar11, piVar11 != (int *)piVar3[0x30])) {
          FUN_0079eeb5(&local_34.right);
          if (piVar3[0x94] == 0) {
            pcVar12 = *(code **)(*piVar3 + 0x2f4);
          }
          else {
            FUN_0079efbc(local_8c);
            pcVar12 = *(code **)(*piVar3 + 0x2f8);
          }
          guard_check_icall(local_58,local_6c,0);
          (*pcVar12)();
        }
      }
      pCVar13 = local_58;
      if (-1 < piVar3[0x30]) {
        pcVar12 = *(code **)(*(int *)local_58 + 0x30);
        iVar5 = FUN_007c2511();
        uVar8 = *(undefined4 *)(iVar5 + 0x70);
        guard_check_icall(uVar8);
        (*pcVar12)();
        piVar11 = (int *)FUN_0049a990(piVar3[0x30]);
        local_5c = *piVar11;
        piVar3[0x41] = piVar3[0x30];
        FUN_0079eeb5(&local_34.right);
        pCVar13 = local_58;
        if (piVar3[0x94] == 0) {
          if (piVar3[0xa2] != 0) {
            pcVar12 = *(code **)(*piVar3 + 0x2f0);
            guard_check_icall(uVar8);
            iVar5 = (*pcVar12)();
            if ((iVar5 == 0) || (piVar3[0xa6] != 0)) {
              pcVar12 = *(code **)(*(int *)local_58 + 0x28);
              iVar5 = FUN_007c2511();
              guard_check_icall(iVar5 + 300);
              (*pcVar12)();
            }
          }
          pcVar12 = *(code **)(*piVar3 + 0x2f4);
          guard_check_icall(local_58,local_5c,1);
          (*pcVar12)();
          pCVar13 = local_58;
        }
        else {
          FUN_0079efbc(piVar3 + 0x51);
          pcVar12 = *(code **)(*(int *)pCVar13 + 0x28);
          iVar5 = FUN_007c2511();
          guard_check_icall(iVar5 + 300);
          (*pcVar12)();
          pcVar12 = *(code **)(*(int *)pCVar13 + 0x30);
          pcVar1 = *(code **)(*local_60 + 0x234);
          guard_check_icall();
          uVar8 = (*pcVar1)();
          guard_check_icall(uVar8);
          (*pcVar12)();
          FUN_0079efbc(local_8c);
          piVar3 = local_60;
          pcVar12 = *(code **)(*local_60 + 0x2f8);
          guard_check_icall(local_58,local_5c,1);
          (*pcVar12)();
          piVar11 = (int *)(piVar3[0xb7] + 1);
          local_64 = (code *)(*(int *)(local_5c + 0x10) + 1);
          if ((int)local_64 < (int)piVar11) {
            local_64 = (code *)piVar11;
          }
          pCVar13 = local_58;
          if ((int)piVar11 < *(int *)(local_5c + 0x18)) {
            pcVar12 = *(code **)(*piVar3 + 0x230);
            guard_check_icall();
            uVar8 = (*pcVar12)();
            FUN_0079df60(0,1,uVar8);
            pCVar13 = local_58;
            local_8 = CONCAT31(local_8._1_3_,4);
            FUN_0079efbc(&local_70);
            if (piVar3[0x24] == 0) {
              FUN_0079ec58(local_68,local_64,*(undefined4 *)(local_5c + 0x14));
              iVar5 = *(int *)(local_5c + 0x14);
            }
            else {
              FUN_0079ec58(local_68,local_64,*(undefined4 *)(local_5c + 0x1c));
              iVar5 = *(int *)(local_5c + 0x1c);
            }
            CDC::LineTo(pCVar13,*(int *)(local_5c + 0x18),iVar5);
            FUN_0079efbc(local_9c);
            local_8 = CONCAT31(local_8._1_3_,3);
            local_70 = CPen::vftable;
            FUN_00416100();
          }
        }
      }
      FUN_0079eeb5(0);
      local_8 = CONCAT31(local_8._1_3_,2);
      local_34.right = (LONG)CRgn::vftable;
      FUN_00416100();
    }
    local_34.bottom = (LONG)(piVar3 + 0xaf);
    BVar9 = IsRectEmpty((RECT *)local_34.bottom);
    LVar2 = local_34.bottom;
    if (BVar9 == 0) {
      pHVar10 = (HBRUSH)0x0;
      if (local_78 != 0) {
        pHVar10 = *(HBRUSH *)(local_78 + 4);
      }
      FillRect(*(HDC *)(pCVar13 + 4),(RECT *)local_34.bottom,pHVar10);
      pCVar13 = local_58;
      local_34.left = *(LONG *)LVar2;
      local_34.top = *(LONG *)(LVar2 + 4);
      local_34.right = *(LONG *)(LVar2 + 8);
      local_34.bottom = *(LONG *)(LVar2 + 0xc);
      CDC::Draw3dRect(local_58,&local_34,local_84,local_74);
      InflateRect(&local_34,-1,-1);
      CDC::Draw3dRect(pCVar13,&local_34,local_80,local_74);
      piVar3 = local_60;
    }
    if ((piVar3[0x94] != 0) && (0 < piVar3[0xa9])) {
      FUN_0079efbc(local_94);
      local_6c = (int *)(piVar3[0xb7] + -1);
      if (piVar3[0x24] == 0) {
        FUN_0079ec58(&local_34.right,local_6c,piVar3[0xb8] + 1);
        iVar5 = piVar3[0xba] + -2;
      }
      else {
        FUN_0079ec58(&local_34.right,local_6c,piVar3[0xba]);
        iVar5 = piVar3[0xb8] + 2;
      }
      CDC::LineTo(pCVar13,(int)local_6c,iVar5);
    }
    BVar9 = IsRectEmpty((RECT *)(piVar3 + 0xbf));
    if (BVar9 == 0) {
      local_34.bottom = FUN_007c2574();
      pcVar12 = *(code **)(((RECT *)local_34.bottom)->left + 0x124);
      guard_check_icall(local_58,local_60,local_60[0xa7e] == 1,((RECT *)(piVar3 + 0xbf))->left,
                        piVar3[0xc0],piVar3[0xc1],piVar3[0xc2],local_78,local_94);
      (*pcVar12)();
      pCVar13 = local_58;
    }
    pcVar12 = *(code **)(*(int *)pCVar13 + 0x28);
    guard_check_icall(local_a0);
    (*pcVar12)();
    FUN_0079efbc(local_b8);
    FUN_0079efbc(local_9c);
    local_c0[0] = CPen::vftable;
    FUN_00416100();
    local_8c[0] = CPen::vftable;
    FUN_00416100();
    local_94[0] = CPen::vftable;
    FUN_00416100();
    FUN_008d9b68();
    return;
  }
LAB_00811123:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCTabCtrl[62] */
/* 00811af4  FUN_00811af4  145 bytes, 0 callers */

undefined4 FUN_00811af4(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar2 = FUN_00793ba8(param_1,param_2,param_3);
  if (param_2 != (int *)0x0) {
    if (param_2[2] == -0x209) {
      if ((*(int *)(in_ECX + 0xf8) != 0) && (*(int *)(*(int *)(in_ECX + 0xf8) + 0x20) != 0)) {
        FUN_00797e71(&DAT_00a11c68,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x13);
      }
      if (((*(int *)(in_ECX + 0xfc) != 0) &&
          (iVar1 = *(int *)(*(int *)(in_ECX + 0xfc) + 0x20), iVar1 != 0)) && (*param_2 == iVar1)) {
        FUN_00797e71(&DAT_00a11c68,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x13);
      }
    }
    if (param_2[2] == -0x141) {
      FUN_00813563(0);
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCTabCtrl[187] */
/* 00811d7f  FUN_00811d7f  616 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_00811d7f(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  wchar_t *_Str1;
  undefined1 *puVar2;
  HMENU pHVar3;
  int *piVar4;
  int iVar5;
  HWND pHVar6;
  DWORD *pDVar7;
  BOOL BVar8;
  int *in_ECX;
  int iVar9;
  int in_stack_ffffffc0;
  UINT in_stack_ffffffc4;
  undefined **local_30;
  HMENU local_2c;
  int *local_28;
  int local_24;
  UINT_PTR local_20;
  wchar_t *local_1c;
  wchar_t *local_18;
  HMENU local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  puVar2 = &LAB_0094992b;
  if (DAT_00a13a20 != (int *)0x0) {
    local_2c = (HMENU)0x0;
    local_30 = CMenu::vftable;
    local_8 = 0;
    local_28 = in_ECX;
    pHVar3 = CreatePopupMenu();
    CMenu::Attach((CMenu *)&local_30,pHVar3);
    iVar9 = 0;
    if (0 < in_ECX[0x2f]) {
      do {
        piVar4 = (int *)FUN_0049a990(iVar9);
        local_24 = *piVar4;
        if (*(int *)(local_24 + 0x34) != 0) {
          local_20 = -iVar9 - 100;
          iVar5 = FUN_004054a0(*(int *)(local_24 + 4) + -0x10);
          local_1c = (wchar_t *)(iVar5 + 0x10);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
          FUN_005946a0(&DAT_0095bc0c,&DAT_0098dde8);
          FUN_005946a0(&DAT_0098dde0,&DAT_0098dde8);
          local_14 = (HMENU)0x0;
          iVar5 = GetMenuItemCount(local_2c);
          _Str1 = local_1c;
          if (0 < iVar5) {
            do {
              CStringT<>();
              local_8._0_1_ = 2;
              FID_conflict_GetMenuStringA
                        (local_14,(UINT)&local_18,(LPSTR)0x400,in_stack_ffffffc0,in_stack_ffffffc4);
              if (local_18 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
                FUN_00404e80(0x80004005);
              }
              iVar5 = __wcsicmp(_Str1,local_18);
              if (iVar5 < 0) {
                InsertMenuW(local_2c,(UINT)local_14,0x400,local_20,_Str1);
                local_8 = CONCAT31(local_8._1_3_,1);
                FUN_00406b10();
                goto LAB_00811eb1;
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              FUN_00406b10();
              local_14 = (HMENU)((int)&local_14->unused + 1);
              iVar5 = GetMenuItemCount(local_2c);
            } while ((int)local_14 < iVar5);
          }
          AppendMenuW(local_2c,0,local_20,_Str1);
LAB_00811eb1:
          iVar5 = *(int *)(local_24 + 0x20);
          if ((iVar5 != 0) && (*(int *)(iVar5 + 0x20) != 0)) {
            local_14 = (HMENU)SendMessageW(*(HWND *)(iVar5 + 0x20),0x7f,0,0);
            if (local_14 == (HMENU)0x0) {
              if (*(int *)(local_24 + 0x20) == 0) {
                pHVar6 = (HWND)0x0;
              }
              else {
                pHVar6 = *(HWND *)(*(int *)(local_24 + 0x20) + 0x20);
              }
              local_14 = (HMENU)GetClassLongW(pHVar6,-0x22);
            }
            pDVar7 = (DWORD *)FUN_007e3332(local_20);
            *pDVar7 = (DWORD)local_14;
          }
          local_8 = local_8 & 0xffffff00;
          FUN_00406b10();
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < in_ECX[0x2f]);
    }
    pHVar6 = (HWND)in_ECX[8];
    pcVar1 = *(code **)(*DAT_00a13a20 + 0x14);
    guard_check_icall(local_2c,param_1,param_2,local_28,0);
    iVar9 = (*pcVar1)();
    BVar8 = IsWindow(pHVar6);
    if (BVar8 != 0) {
      iVar9 = -100 - iVar9;
      if ((-1 < iVar9) && (iVar9 < local_28[0x2f])) {
        local_28[0x93] = 1;
        pcVar1 = *(code **)(*local_28 + 0x214);
        guard_check_icall(iVar9);
        (*pcVar1)();
        local_28[0x93] = 0;
      }
      RemoveAll();
    }
    local_8 = 4;
    local_30 = CMenu::vftable;
    puVar2 = (undefined1 *)CMenu::DestroyMenu((CMenu *)&local_30);
  }
  return puVar2;
}




/* vtable slots: CMFCTabCtrl[67] */
/* 008122bf  FUN_008122bf  540 bytes, 0 callers */

undefined4 FUN_008122bf(int *param_1)

{
  uint uVar1;
  code *pcVar2;
  SHORT SVar3;
  undefined4 uVar4;
  int *in_ECX;
  int iVar5;
  int iVar6;
  int local_8;
  
  iVar5 = 0;
  uVar1 = param_1[1];
  if (uVar1 < 0x105) {
    if ((((uVar1 == 0x104) || (uVar1 == 0xa1)) || (uVar1 == 0xa2)) ||
       ((((uVar1 == 0xa4 || (uVar1 == 0xa5)) || (uVar1 == 0xa7)) || (uVar1 == 0xa8)))) {
LAB_0081246f:
      iVar6 = in_ECX[0x3f];
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x20) != 0)) {
        SendMessageW(*(HWND *)(iVar6 + 0x20),0x407,0,(LPARAM)param_1);
      }
      iVar6 = in_ECX[0x3e];
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x20) != 0)) {
        SendMessageW(*(HWND *)(iVar6 + 0x20),0x407,0,(LPARAM)param_1);
      }
      goto LAB_008124ad;
    }
    if (uVar1 != 0x100) goto LAB_008124ad;
    if ((in_ECX[0x30] == -1) || (SVar3 = GetAsyncKeyState(0x11), -1 < SVar3)) goto LAB_0081246f;
    if (param_1[2] == 0x21) {
      iVar5 = in_ECX[0x30] + -1 + in_ECX[0x2f];
      if (in_ECX[0x30] < iVar5) {
        do {
          local_8 = iVar5 % in_ECX[0x2f];
          pcVar2 = *(code **)(*in_ECX + 0x27c);
          guard_check_icall(local_8);
          iVar6 = (*pcVar2)();
          if (iVar6 != 0) goto LAB_008123e9;
          iVar5 = iVar5 + -1;
        } while (in_ECX[0x30] < iVar5);
      }
    }
    else {
      if (param_1[2] != 0x22) goto LAB_0081246f;
      iVar5 = in_ECX[0x30];
      iVar6 = iVar5;
      while( true ) {
        iVar6 = iVar6 + 1;
        if (iVar5 + in_ECX[0x2f] <= iVar6) break;
        local_8 = iVar6 % in_ECX[0x2f];
        pcVar2 = *(code **)(*in_ECX + 0x27c);
        guard_check_icall(local_8);
        iVar5 = (*pcVar2)();
        if (iVar5 != 0) goto LAB_008123e9;
        iVar5 = in_ECX[0x30];
      }
    }
LAB_008124c7:
    uVar4 = 1;
  }
  else {
    if (((((uVar1 == 0x200) || (uVar1 == 0x201)) || (uVar1 == 0x202)) ||
        ((uVar1 == 0x204 || (uVar1 == 0x205)))) || ((uVar1 == 0x207 || (uVar1 == 0x208))))
    goto LAB_0081246f;
LAB_008124ad:
    if (param_1[1] == 0x203) {
      if (in_ECX != (int *)0xffffddb0) {
        iVar5 = in_ECX[0x89c];
      }
      if (*param_1 == iVar5) goto LAB_008124c7;
    }
    uVar4 = FUN_0080a308(param_1);
  }
  return uVar4;
LAB_008123e9:
  in_ECX[0x93] = 1;
  pcVar2 = *(code **)(*in_ECX + 0x214);
  guard_check_icall(local_8);
  (*pcVar2)();
  pcVar2 = *(code **)(*in_ECX + 0x210);
  guard_check_icall();
  (*pcVar2)();
  FUN_00797df8();
  pcVar2 = *(code **)(*in_ECX + 0x270);
  guard_check_icall(in_ECX[0x30]);
  (*pcVar2)();
  in_ECX[0x93] = 0;
  goto LAB_008124c7;
}




/* vtable slots: CMFCTabCtrl[97] */
/* 008124db  FUN_008124db  1671 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008124db(void)

{
  LPRECT lprc;
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  HWND pHVar6;
  CWnd *pCVar7;
  RECT *lpRect;
  int *in_ECX;
  int iVar8;
  undefined1 local_6c [4];
  uint local_68;
  undefined1 local_64 [4];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int *local_4c;
  tagRECT local_48;
  tagRECT local_38;
  tagRECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX == (int *)0x0) {
    return;
  }
  if (in_ECX[8] == 0) {
    return;
  }
  pcVar1 = *(code **)(*in_ECX + 0x17c);
  local_4c = in_ECX;
  guard_check_icall();
  local_54 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x248);
  guard_check_icall();
  local_58 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1a4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (((in_ECX[0x4b] == 0) || (1 < iVar2)) && ((in_ECX[0xa1] == 0 || (iVar2 != 0)))) {
    local_5c = 0;
  }
  else {
    local_5c = 1;
  }
  local_48.left = 0;
  local_48.top = 0;
  local_48.right = 0;
  local_48.bottom = 0;
  GetClientRect((HWND)in_ECX[8],&local_48);
  lprc = (LPRECT)(in_ECX + 0xbf);
  if (in_ECX[0xa7e] == 1) {
    lprc->left = local_48.left;
    in_ECX[0xc0] = local_48.top;
    in_ECX[0xc1] = local_48.right;
    in_ECX[0xc2] = local_48.bottom;
    local_4c[0xbf] = local_48.right + -5;
    in_ECX = local_4c;
    local_48.right = local_48.right + -6;
  }
  else if (in_ECX[0xa7e] == 2) {
    lprc->left = local_48.left;
    in_ECX[0xc0] = local_48.top;
    in_ECX[0xc1] = local_48.right;
    in_ECX[0xc2] = local_48.bottom;
    local_4c[0xc0] = local_48.bottom + -5;
    in_ECX = local_4c;
    local_48.bottom = local_48.bottom + -6;
  }
  else {
    SetRectEmpty(lprc);
  }
  ((LPRECT)(in_ECX + 0xb7))->left = local_48.left;
  in_ECX[0xb8] = local_48.top;
  in_ECX[0xb9] = local_48.right;
  in_ECX[0xba] = local_48.bottom;
  InflateRect((LPRECT)(in_ECX + 0xb7),-2,0);
  local_60 = 0;
  local_50 = 0;
  local_68 = 0;
  if (local_4c[0x99] != 0) {
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0x140);
    guard_check_icall(local_6c);
    piVar3 = (int *)(*pcVar1)();
    piVar4 = (int *)FUN_0081507c(local_64);
    local_50 = *piVar4 + 4 + *piVar3;
    if (local_4c[0x94] == 0) {
      iVar2 = local_50 + 2;
      local_50 = local_54 + -4;
      if (iVar2 <= local_54 + -4) {
        local_50 = iVar2;
      }
    }
    iVar2 = local_4c[0xa82];
    if ((local_4c[0x9a] == 0) || (local_4c[0xa3] != 0)) {
      iVar2 = iVar2 + -1;
    }
    if (local_4c[0xa4] != 0) {
      iVar2 = iVar2 + -1;
    }
    local_60 = 3;
    local_68 = ~-(uint)(local_5c != 0) & (local_50 + 3) * iVar2;
  }
  piVar3 = local_4c;
  if (local_4c[0x94] == 0) {
    if (local_4c[0x24] == 0) {
      local_4c[0xb8] = local_4c[0xba] - local_54;
    }
    else {
      local_4c[0xba] = local_4c[0xb8] + local_54;
    }
    if (local_4c[0x99] != 0) {
      iVar2 = local_4c[0xb9] - local_68;
      local_4c[0xb9] = iVar2;
      if ((((local_4c[0x95] != 0) || (local_4c[0x96] != 0)) || (local_4c[0x97] != 0)) &&
         (local_4c[0xa4] == 0)) {
        OffsetRect((LPRECT)(local_4c + 0xb7),local_50,0);
        iVar2 = piVar3[0xb9];
      }
      iVar2 = iVar2 + 1;
      iVar8 = (piVar3[0xba] + piVar3[0xb8]) / 2 - local_50 / 2;
      iVar5 = local_50;
      goto LAB_00812835;
    }
  }
  else {
    if (local_4c[0x24] == 0) {
      iVar2 = local_4c[0xba];
      if (1 < local_58) {
        iVar2 = (iVar2 - local_58) + 1;
        local_4c[0xba] = iVar2;
      }
      iVar8 = iVar2 - local_54;
      local_4c[0xb8] = iVar8;
    }
    else {
      iVar8 = local_4c[0xb8];
      if (1 < local_58) {
        iVar8 = iVar8 + -1 + local_58;
        local_4c[0xb8] = iVar8;
      }
      iVar2 = local_54 + iVar8;
      local_4c[0xba] = iVar2;
    }
    local_4c[0xb7] = local_4c[0xb7] + local_68 + 1;
    local_4c[0xb9] = local_4c[0xb9] + -1;
    if (local_4c[0xb9] < local_4c[0xb7]) {
      if (local_58 < 1) {
        local_4c[0xb7] = local_48.left;
        iVar5 = local_48.right;
      }
      else {
        local_4c[0xb7] = local_48.left + 1 + local_58;
        iVar5 = (local_48.right - local_58) + -1;
      }
      local_4c[0xb9] = iVar5;
    }
    iVar2 = iVar2 - iVar8;
    if (local_48.bottom - local_48.top < local_58 + iVar2) {
      local_4c[0xb7] = 0;
      local_4c[0xb9] = 0;
LAB_00812761:
      iVar5 = 0;
    }
    else {
      if (iVar2 == 0) goto LAB_00812761;
      iVar2 = (iVar2 - local_50) / 2;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      iVar8 = iVar8 + iVar2;
      iVar5 = local_50;
    }
    iVar2 = local_58 + local_48.left + 1;
LAB_00812835:
    FUN_00812b62(iVar2,iVar8,local_50,iVar5,local_5c,local_60);
  }
  piVar3[0xbb] = local_48.left;
  piVar3[0xbc] = local_48.top;
  piVar3[0xbd] = local_48.right;
  piVar3[0xbe] = local_48.bottom;
  iVar8 = GetSystemMetrics(2);
  piVar3 = local_4c;
  iVar2 = local_58;
  local_4c[0xa8] = local_4c[0xb9] - iVar8;
  if (0 < local_58) {
    InflateRect((LPRECT)(local_4c + 0xbb),-1 - local_58,-1 - local_58);
    if (piVar3[0xa7e] == 1) {
      piVar3[0xbd] = piVar3[0xbd] + iVar2 + 2;
    }
    else if (piVar3[0xa7e] == 2) {
      piVar3[0xbe] = piVar3[0xbe] + iVar2 + 2;
    }
  }
  if (piVar3[0x94] == 0) {
    if (piVar3[0x24] == 0) {
      piVar3[0xbe] = piVar3[0xb8] - iVar2;
    }
    else {
      piVar3[0xbc] = piVar3[0xba] + iVar2;
    }
  }
  else if (piVar3[0x24] == 0) {
    piVar3[0xbe] = piVar3[0xb8];
    if (iVar2 == 0) {
      piVar3[0xbc] = piVar3[0xbc] + 1;
LAB_008128f1:
      piVar3[0xbb] = piVar3[0xbb] + 1;
    }
  }
  else {
    piVar3[0xbc] = piVar3[0xba] + iVar2;
    if (iVar2 == 0) {
      piVar3[0xbe] = piVar3[0xbe] + -1;
      goto LAB_008128f1;
    }
  }
  if ((piVar3[0x9d] != 0) && (local_68 = 0, 0 < piVar3[0x2f])) {
    do {
      piVar4 = (int *)FUN_0049a990(local_68);
      local_60 = *piVar4;
      if ((*(int *)(local_60 + 0x34) != 0) &&
         ((iVar2 = *(int *)(local_60 + 0x20), iVar2 != 0 && (*(int *)(iVar2 + 0x20) != 0)))) {
        local_18.left = piVar3[0xbb];
        local_18.top = piVar3[0xbc];
        local_18.right = piVar3[0xbd];
        local_18.bottom = piVar3[0xbe];
        pHVar6 = GetParent(*(HWND *)(iVar2 + 0x20));
        pCVar7 = CWnd::FromHandle(pHVar6);
        piVar3 = local_4c;
        if ((pCVar7 != (CWnd *)0x0) &&
           ((pHVar6 = *(HWND *)(pCVar7 + 0x20), pHVar6 != (HWND)0x0 && (pHVar6 != (HWND)local_4c[8])
            ))) {
          MapWindowPoints((HWND)local_4c[8],pHVar6,(LPPOINT)&local_18,2);
        }
        FUN_00797e71(0,local_18.left,local_18.top,local_18.right - local_18.left,
                     local_18.bottom - local_18.top,0x14);
      }
      local_68 = local_68 + 1;
    } while ((int)local_68 < piVar3[0x2f]);
  }
  pcVar1 = *(code **)(*piVar3 + 0x2e4);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*piVar3 + 0x2dc);
  guard_check_icall();
  (*pcVar1)();
  if ((piVar3[0xa5] == 0) && (piVar3[0x2c] == piVar3[0x27])) {
    FUN_0042fb40(0,0xffffffff);
    pcVar1 = *(code **)(*piVar3 + 0x2dc);
    guard_check_icall();
    (*pcVar1)();
  }
  pcVar1 = *(code **)(*piVar3 + 0x2e0);
  guard_check_icall();
  (*pcVar1)();
  local_28.left = local_48.left;
  local_28.top = local_48.top;
  local_28.right = local_48.right;
  local_28.bottom = local_48.bottom;
  if (local_58 == 0) {
    if (local_4c[0x24] == 0) {
      local_28.bottom = local_4c[0xb8] + 1;
    }
    else {
      local_28.top = local_4c[0xba] + -1;
    }
  }
  else {
    if (local_4c[0x94] == 0) {
      if (local_4c[0x24] == 0) {
        local_28.bottom = local_4c[0xb8];
      }
      else {
        local_28.top = local_4c[0xba];
      }
    }
    if (local_4c[0x9c] != 0) {
      local_18.left = local_48.left;
      local_18.top = local_28.top;
      local_18.right = local_48.right;
      local_18.bottom = local_28.bottom;
      if (local_4c[0x94] != 0) {
        if (local_4c[0x24] == 0) {
          local_18.bottom = local_4c[0xb8] + 1;
        }
        else {
          local_18.top = local_4c[0xba] + -1;
        }
      }
      lpRect = &local_18;
      goto LAB_00812af8;
    }
    InflateRect(&local_28,-1,-1);
  }
  lpRect = &local_28;
LAB_00812af8:
  InvalidateRect((HWND)local_4c[8],lpRect,1);
  local_38.left = 0;
  local_38.top = 0;
  local_38.right = 0;
  local_38.bottom = 0;
  GetClientRect((HWND)local_4c[8],&local_38);
  if (local_4c[0x24] == 0) {
    local_38.top = local_4c[0xbc];
  }
  else {
    local_38.bottom = local_4c[0xbe];
  }
  InvalidateRect((HWND)local_4c[8],&local_38,1);
  UpdateWindow((HWND)local_4c[8]);
  return;
}




/* vtable slots: CMFCTabCtrl[133] */
/* 00812d1e  FUN_00812d1e  1320 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00812d1e(CObject *param_1)

{
  int iVar1;
  CObject *pCVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  CObject *pCVar5;
  HMENU pHVar6;
  CMenu *pCVar7;
  BOOL BVar8;
  undefined4 uVar9;
  RECT *lprcUpdate;
  CWnd *this;
  int *piVar10;
  uint uVar11;
  int *in_ECX;
  code *pcVar12;
  tagMENUITEMINFOW local_68;
  CObject *local_38;
  CObject *local_34;
  int local_30;
  CWnd *local_2c;
  undefined4 local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x812d2a;
  if ((((int)param_1 < 0) || (in_ECX[0x2f] <= (int)param_1)) || (in_ECX[0x27] <= (int)param_1))
  goto LAB_00812e7f;
  local_34 = (CObject *)in_ECX[0x30];
  if (local_34 == param_1) {
    pcVar12 = *(code **)(*in_ECX + 0x2f0);
    guard_check_icall();
    iVar1 = (*pcVar12)();
    if (iVar1 != 0) {
      FUN_0080e59b(in_ECX[0x30]);
    }
    goto LAB_00812e7f;
  }
  pcVar12 = *(code **)(*in_ECX + 0x274);
  guard_check_icall(param_1);
  iVar1 = (*pcVar12)();
  if (iVar1 != 0) goto LAB_00812e7f;
  pCVar2 = (CObject *)FUN_0079296c();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar2);
  local_30 = 0;
  if ((pCVar2 != (CObject *)0x0) && (in_ECX[0x4e] != 0)) {
    if ((*(int *)(pCVar2 + 0x154) == 0) && (DAT_00a0092c == 0)) {
      local_30 = 1;
    }
    else {
      local_30 = 0;
    }
  }
  iVar1 = local_30;
  pHVar3 = GetParent((HWND)in_ECX[8]);
  local_2c = CWnd::FromHandle(pHVar3);
  if ((1 < in_ECX[0x2f]) && (iVar1 != 0)) {
    SendMessageW(*(HWND *)(local_2c + 0x20),0xb,0,0);
  }
  if ((in_ECX[0x30] != -1) && (in_ECX[0x48] != 0)) {
    pcVar12 = *(code **)(*in_ECX + 0x210);
    guard_check_icall();
    iVar1 = (*pcVar12)();
    if (iVar1 != 0) {
      FUN_00797f20(0);
    }
  }
  in_ECX[0x30] = (int)param_1;
  FUN_0080fa92();
  pcVar12 = *(code **)(*in_ECX + 0x210);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar12)();
  local_38 = pCVar2;
  if (pCVar2 == (CObject *)0x0) {
    SendMessageW(*(HWND *)(local_2c + 0x20),0xb,1,0);
    goto LAB_00812e7f;
  }
  FUN_00797f20(5);
  if (in_ECX[0x48] == 0) {
    BringWindowToTop(*(HWND *)(pCVar2 + 0x20));
  }
  if (in_ECX[0x9d] != 0) {
    FUN_00797e71(0,0xffffffff,0xffffffff,(in_ECX[0xbd] - in_ECX[0xbb]) + 1,
                 in_ECX[0xbe] - in_ECX[0xbc],0x16);
    FUN_00797e71(0,0xffffffff,0xffffffff,in_ECX[0xbd] - in_ECX[0xbb],in_ECX[0xbe] - in_ECX[0xbc],
                 0x16);
  }
  pcVar12 = *(code **)(*in_ECX + 0x224);
  guard_check_icall(in_ECX[0x30]);
  (*pcVar12)();
  if (in_ECX[0x94] != 0) {
    FUN_00813563(0);
  }
  pHVar3 = GetParent((HWND)in_ECX[8]);
  pCVar4 = CWnd::FromHandle(pHVar3);
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CTabbedPane_00a009a4,(CObject *)pCVar4);
  if (pCVar2 != (CObject *)0x0) {
    pcVar12 = *(code **)(*(int *)pCVar2 + 0x3e4);
    guard_check_icall();
    iVar1 = (*pcVar12)();
    if (iVar1 != 0) {
      CStringT<>();
      local_8 = 0;
      pcVar12 = *(code **)(*in_ECX + 0x1bc);
      guard_check_icall(in_ECX[0x30],&local_28);
      (*pcVar12)();
      FUN_00797ece(local_28);
      pcVar12 = *(code **)(*(int *)pCVar2 + 0x168);
      guard_check_icall();
      iVar1 = (*pcVar12)();
      pCVar5 = pCVar2;
      if (iVar1 == 0) {
        pHVar3 = GetParent(*(HWND *)(pCVar2 + 0x20));
        pCVar5 = (CObject *)CWnd::FromHandle(pHVar3);
        if (pCVar5 != (CObject *)0x0) goto LAB_00812fcd;
      }
      else {
LAB_00812fcd:
        RedrawWindow(*(HWND *)(pCVar5 + 0x20),(RECT *)0x0,(HRGN)0x0,0x401);
      }
      local_8 = 0xffffffff;
      FUN_00406b10();
    }
  }
  if ((in_ECX[0xa2] != 0) || (in_ECX[0xa3] != 0)) {
    pcVar12 = *(code **)(*in_ECX + 0x184);
    guard_check_icall();
    (*pcVar12)();
  }
  InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
  UpdateWindow((HWND)in_ECX[8]);
  pCVar5 = local_38;
  if (local_34 != (CObject *)0xffffffff) {
    local_34 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CView_0097d804,local_38);
    if (local_34 == (CObject *)0x0) {
      if (DAT_00a006bc != 0) {
        FUN_00797df8();
      }
    }
    else {
      FUN_007e5618(local_34);
      FUN_0079c896(local_34,1);
    }
  }
  if ((in_ECX != (int *)0xffffddb0) && (in_ECX[0x89c] != 0)) {
    local_28 = 1;
    pHVar6 = GetSystemMenu(*(HWND *)(pCVar5 + 0x20),0);
    pCVar7 = CMenu::FromHandle(pHVar6);
    uVar9 = local_28;
    if ((pCVar7 != (CMenu *)0x0) && (pHVar6 = *(HMENU *)(pCVar7 + 4), pHVar6 != (HMENU)0x0)) {
      _memset(&local_68,0,0x30);
      local_68.cbSize = 0x30;
      local_68.fMask = 1;
      BVar8 = GetMenuItemInfoW(pHVar6,0xf060,0,&local_68);
      if ((BVar8 == 0) || (uVar9 = local_28, ((byte)local_68.fState & 3) != 0)) {
        uVar9 = 0;
      }
    }
    FUN_007979e8(uVar9);
  }
  pcVar12 = *(code **)(*in_ECX + 0x270);
  guard_check_icall(in_ECX[0x30]);
  (*pcVar12)();
  pCVar4 = local_2c;
  if ((1 < in_ECX[0x2f]) && (local_30 != 0)) {
    SendMessageW(*(HWND *)(local_2c + 0x20),0xb,1,0);
    lprcUpdate = (RECT *)0x0;
    if (in_ECX[0x7c] != 0) {
      local_24.left = 0;
      local_24.top = 0;
      local_24.right = 0;
      local_24.bottom = 0;
      GetWindowRect((HWND)in_ECX[8],&local_24);
      pHVar3 = GetParent((HWND)in_ECX[8]);
      this = CWnd::FromHandle(pHVar3);
      CWnd::ScreenToClient(this,&local_24);
      lprcUpdate = &local_24;
    }
    RedrawWindow(*(HWND *)(pCVar4 + 0x20),lprcUpdate,(HRGN)0x0,0x185);
  }
  if ((in_ECX[0x30] != -1) && (pCVar2 != (CObject *)0x0)) {
    pcVar12 = *(code **)(*in_ECX + 0x1b0);
    guard_check_icall(in_ECX[0x30]);
    pCVar5 = (CObject *)(*pcVar12)();
    local_2c = (CWnd *)AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar5);
    if (local_2c != (CWnd *)0x0) {
      pcVar12 = *(code **)(*(int *)local_2c + 0x228);
      guard_check_icall(0);
      piVar10 = (int *)(*pcVar12)();
      pcVar12 = *(code **)(*(int *)local_2c + 0x1c4);
      guard_check_icall();
      uVar11 = (*pcVar12)();
      if ((uVar11 & 0x10) == 0) {
        *(uint *)(pCVar2 + 0xa0) = *(uint *)(pCVar2 + 0xa0) & 0xffffffef;
        if (piVar10 == (int *)0x0) goto LAB_00812e7f;
        pcVar12 = *(code **)(*piVar10 + 0x1f8);
      }
      else {
        *(uint *)(pCVar2 + 0xa0) = *(uint *)(pCVar2 + 0xa0) | 0x10;
        if (piVar10 == (int *)0x0) goto LAB_00812e7f;
        pcVar12 = *(code **)(*piVar10 + 500);
      }
      guard_check_icall();
      (*pcVar12)();
    }
  }
LAB_00812e7f:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCTabCtrl[92] */
/* 0081328f  FUN_0081328f  9 bytes, 0 callers */

void FUN_0081328f(void)

{
  FUN_0080acda();
  return;
}




/* vtable slots: CMFCTabCtrl[91] */
/* 00813298  FUN_00813298  9 bytes, 0 callers */

void FUN_00813298(void)

{
  FUN_0080adfd();
  return;
}




/* vtable slots: CMFCTabCtrl[94] */
/* 008133de  SetTabsHeight  75 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCTabCtrl::SetTabsHeight(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCTabCtrl::SetTabsHeight(CMFCTabCtrl *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(this + 600) != 0) {
    if (0 < *(int *)(this + 0xd8)) {
      iVar2 = *(int *)(this + 0xd8) + 7;
    }
    iVar1 = FUN_007c2511();
    if (iVar2 <= *(int *)(iVar1 + 0x1cc) + 4) {
      iVar2 = FUN_007c2511();
      iVar2 = *(int *)(iVar2 + 0x1cc) + 4;
    }
    *(int *)(this + 0x110) = iVar2;
    return;
  }
  CMFCBaseTabCtrl::SetTabsHeight((CMFCBaseTabCtrl *)this);
  return;
}




/* vtable slots: CMFCTabCtrl[152] */
/* 00813527  SwapTabs  60 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCTabCtrl::SwapTabs(int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCTabCtrl::SwapTabs(CMFCTabCtrl *this,int param_1,int param_2)

{
  CMFCBaseTabCtrl::SwapTabs((CMFCBaseTabCtrl *)this,param_1,param_2);
  if (((*(int *)(this + 0x254) != 0) || (*(int *)(this + 600) != 0)) ||
     (*(int *)(this + 0x25c) != 0)) {
    *(undefined4 *)(this + 0x2a4) = 0;
    *(undefined4 *)(this + 0x2b0) = 0;
  }
  return;
}



