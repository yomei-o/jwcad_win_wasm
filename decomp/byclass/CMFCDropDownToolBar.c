/* CMFCDropDownToolBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCDropDownToolBar[241], CMFCImageEditorPaletteBar[241], CMFCMenuBar[241], CMFCOutlookBarPane[241], CMFCOutlookBarToolBar[241], CMFCPrintPreviewToolBar[241], CMFCTasksPaneToolBar[241], CMFCToolBar[241] */
/* 007c248e  FUN_007c248e  64 bytes, 1 callers */

CWnd * FUN_007c248e(void)

{
  code *pcVar1;
  CWnd *pCVar2;
  int iVar3;
  CWnd *in_ECX;
  
  pCVar2 = CWnd::GetOwner(in_ECX);
  if (pCVar2 != (CWnd *)0x0) {
    if (*(int *)(in_ECX + 0xbb4) == 0) {
      return pCVar2;
    }
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x150);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return pCVar2;
    }
  }
  pCVar2 = (CWnd *)FUN_007e5618();
  return pCVar2;
}




/* vtable slots: CMFCDropDownToolBar[131], CMFCImageEditorPaletteBar[131], CMFCMenuBar[131], CMFCOutlookBarPane[131], CMFCOutlookBarToolBar[131], CMFCPrintPreviewToolBar[131], CMFCToolBar[131] */
/* 007fb471  FUN_007fb471  526 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007fb471(void)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  int iVar7;
  int iVar8;
  int *in_ECX;
  undefined4 uVar9;
  uint wParam;
  int local_84;
  uint local_80;
  undefined4 local_7c;
  uint local_78;
  int local_5c;
  undefined4 local_58;
  uint local_54;
  int local_38;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x194);
    guard_check_icall();
    uVar2 = (*pcVar1)();
    local_80 = in_ECX[0x310];
    while (local_80 != 0) {
      piVar3 = (int *)FUN_0044f2d0(&local_80);
      iVar7 = *piVar3;
      if (iVar7 == 0) break;
      if ((((*(byte *)(iVar7 + 0x24) & 1) == 0) && (in_ECX[0x2e2] != 0)) && ((uVar2 & 0xa000) != 0))
      {
        uVar9 = 1;
      }
      else {
        uVar9 = 0;
      }
      *(undefined4 *)(iVar7 + 0x18) = uVar9;
    }
    pHVar4 = GetParent((HWND)in_ECX[8]);
    pCVar5 = CWnd::FromHandle(pHVar4);
    pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCReBar_0099792c,(CObject *)pCVar5);
    if (pCVar6 == (CObject *)0x0) {
      FUN_007fbc2d();
    }
    else {
      iVar7 = FUN_0078f4b5();
      local_80 = SendMessageW(*(HWND *)(iVar7 + 0x20),0x40c,0,0);
      local_7c = *(undefined4 *)(pCVar6 + 0x2c0);
      wParam = 0;
      local_78 = 0x230;
      uVar2 = 0x230;
      if (local_80 != 0) {
        do {
          SendMessageW(*(HWND *)(iVar7 + 0x20),0x41c,wParam,(LPARAM)&local_7c);
          uVar2 = local_78;
          if (local_5c == in_ECX[8]) break;
          wParam = wParam + 1;
        } while (wParam < local_80);
      }
      local_78 = uVar2 ^ 0x10;
      if (wParam < local_80) {
        pcVar1 = *(code **)(*in_ECX + 0x41c);
        guard_check_icall();
        iVar8 = (*pcVar1)();
        in_ECX[0x2fa] = iVar8;
        pcVar1 = *(code **)(*in_ECX + 0x2a4);
        guard_check_icall(&local_84,0);
        (*pcVar1)();
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        SetRectEmpty(&local_18);
        FUN_007ef36a(&local_18,1);
        local_84 = local_84 + (local_18.left - local_18.right);
        local_80 = (local_18.top - local_18.bottom) + local_80;
        if (local_84 < 1) {
          local_84 = 0;
        }
        if ((int)local_80 < 1) {
          local_80 = 0;
        }
        local_58 = DAT_00a00610;
        local_54 = local_80;
        local_38 = local_84;
        SendMessageW(*(HWND *)(iVar7 + 0x20),0x40b,wParam,(LPARAM)&local_7c);
      }
    }
    pcVar1 = *(code **)(*in_ECX + 0x3e4);
    guard_check_icall();
    (*pcVar1)();
    RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x505);
  }
  return;
}




/* vtable slots: CMFCDropDownToolBar[249], CMFCImageEditorPaletteBar[249], CMFCPrintPreviewToolBar[249], CMFCToolBar[249] */
/* 007fb67f  FUN_007fb67f  1453 bytes, 3 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007fb67f(void)

{
  code *pcVar1;
  CObject *pCVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  int *in_ECX;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined1 local_bc [8];
  undefined1 local_b4 [20];
  undefined1 local_a0 [4];
  int local_9c;
  int local_98;
  uint local_94;
  int local_90;
  uint local_8c;
  int local_88;
  uint local_84;
  int local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  code *local_6c;
  int local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  CObject *local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int *local_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_8 = 0x7fb68e;
  if ((in_ECX[0x312] == 0) || (in_ECX[8] == 0)) goto LAB_007fbc21;
  pcVar1 = *(code **)(*in_ECX + 0x194);
  local_38 = in_ECX;
  guard_check_icall();
  uVar3 = (*pcVar1)();
  uVar3 = uVar3 & 0xa000;
  local_94 = (uint)(uVar3 != 0);
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  local_50 = uVar3;
  GetClientRect((HWND)in_ECX[8],&local_24);
  local_78 = local_24.right;
  FUN_0079dea2(in_ECX);
  local_8 = 0;
  if (uVar3 == 0) {
    iVar4 = FUN_007c2511();
    local_98 = FUN_0079efbc(iVar4 + 0x14c);
  }
  else {
    local_98 = FUN_0080441a(local_b4);
  }
  if (local_98 == 0) {
LAB_007fbc27:
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_74 = local_24.top;
  local_64 = local_24.top;
  if (uVar3 != 0) {
    local_64 = local_24.left;
  }
  local_64 = local_64 + 1;
  pcVar1 = *(code **)(*in_ECX + 0x354);
  local_3c = local_64;
  guard_check_icall();
  uVar3 = (*pcVar1)();
  pcVar1 = *(code **)(*local_38 + 0x358);
  guard_check_icall();
  local_90 = (*pcVar1)();
  piVar9 = local_38;
  local_7c = 0;
  local_80 = 0;
  local_8c = uVar3;
  if (local_38[0x345] != 0) {
    pcVar1 = *(code **)(*local_38 + 0x170);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if ((iVar4 == 0) && (DAT_00a127ac == 0)) {
      RemoveAll();
      local_68 = *(int *)(piVar9[0x345] + 0xfc);
      *(undefined4 *)(piVar9[0x345] + 0xfc) = 0;
      local_6c = *(code **)(*(int *)piVar9[0x345] + 0x1c);
      if (local_50 == 0) {
        local_88 = local_24.right - local_24.left;
        local_84 = local_8c;
      }
      else {
        local_88 = local_90;
        local_84 = local_24.bottom - local_24.top;
      }
      guard_check_icall(local_a0,local_b4,&local_88,local_94);
      piVar5 = (int *)(*local_6c)();
      local_7c = *piVar5;
      local_80 = piVar5[1];
      *(int *)(piVar9[0x345] + 0xfc) = local_68;
    }
  }
  local_9c = piVar9[0x310];
  local_70 = 0;
  local_48 = 0;
  if (local_9c != 0) {
    local_6c = (code *)(piVar9 + 0x30f);
    iVar4 = local_9c;
    do {
      do {
        local_68 = iVar4;
        piVar5 = (int *)FUN_0044f2d0(&local_9c);
        local_4c = (CObject *)*piVar5;
        if (local_4c == (CObject *)0x0) goto LAB_007fbb33;
        local_44 = 1;
        pcVar1 = *(code **)(*(int *)local_4c + 0x1c);
        guard_check_icall(local_bc,local_b4,&local_90,local_94);
        piVar5 = (int *)(*pcVar1)();
        local_40 = *piVar5;
        local_54 = piVar5[1];
        if ((*(int *)(local_4c + 0x18) != 0) && (local_50 != 0)) {
          local_54 = local_8c;
        }
        if (((byte)local_4c[0x24] & 1) != 0) {
          if ((local_3c == local_64) || (local_70 != 0)) {
            local_40 = 0;
            local_54 = 0;
            local_44 = 0;
          }
          else {
            local_70 = 1;
          }
        }
        local_84 = local_3c;
        if (local_50 == 0) {
          local_60 = local_24.left;
          local_58 = local_24.left + local_40;
          local_5c = local_3c;
          local_54 = local_3c + local_54;
          piVar9 = local_38;
          local_3c = local_54;
        }
        else {
          local_60 = local_3c;
          local_58 = local_3c + local_40;
          local_54 = local_54 + local_74;
          local_48 = local_48 + local_40;
          local_5c = local_74;
          local_3c = local_58;
        }
        local_40 = local_9c;
        if (((CObject *)piVar9[0x345] != (CObject *)0x0) && (local_4c != (CObject *)piVar9[0x345]))
        {
          pcVar1 = *(code **)(*piVar9 + 0x170);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          if ((iVar4 == 0) && (DAT_00a127ac == 0)) {
            iVar4 = piVar9[0x345];
            iVar7 = local_7c;
            iVar8 = local_80;
            if ((((*(int *)(iVar4 + 0xe8) < 1) && (local_40 != 0)) &&
                (*(int *)(local_40 + 8) == iVar4)) && (*(int *)(iVar4 + 0x11c) == 0)) {
              iVar7 = 0;
              iVar8 = 0;
            }
            if (local_50 == 0) {
              if (local_24.bottom - iVar8 < (int)local_54) goto LAB_007fb9ef;
            }
            else if ((int)(local_78 - iVar7) < (int)local_58) {
LAB_007fb9ef:
              local_44 = 0;
              local_3c = local_84;
              CObList::AddTail((CObList *)(iVar4 + 0x110),local_4c);
            }
          }
        }
        FUN_00805aeb(local_44);
        pCVar2 = local_4c;
        FUN_0080554f(local_60,local_5c,local_58,local_54);
        piVar9 = local_38;
        if (local_44 != 0) {
          local_70 = *(uint *)(pCVar2 + 0x24) & 1;
        }
      } while ((*(int *)(pCVar2 + 0x10) == 0) && (iVar4 = local_40, local_40 != 0));
      if (local_50 != 0) {
        local_48 = (int)((local_78 - local_48) - local_64) / 2;
        pcVar1 = *(code **)(*local_38 + 0x170);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (((iVar4 != 0) && (0 < local_48)) && (iVar4 = local_68, piVar9[0x2e2] != 0)) {
          while (local_44 = iVar4, local_44 != 0) {
            local_84 = (uint)(local_44 == local_68);
            puVar6 = (uint *)FUN_0049ad10(&local_44);
            local_3c = *puVar6;
            if (local_3c == 0) goto LAB_007fbc27;
            if ((*(int *)(local_3c + 0x10) != 0) && (local_84 == 0)) break;
            local_34.left = *(LONG *)(local_3c + 0x54);
            local_34.top = *(LONG *)(local_3c + 0x58);
            local_34.right = *(LONG *)(local_3c + 0x5c);
            local_34.bottom = *(LONG *)(local_3c + 0x60);
            OffsetRect(&local_34,local_48,0);
            FUN_0080554f(local_34.left,local_34.top,local_34.right,local_34.bottom);
            iVar4 = local_44;
          }
        }
        local_48 = 0;
        local_3c = local_64;
        local_74 = local_74 + local_8c + 5;
      }
      iVar4 = local_40;
      piVar9 = local_38;
    } while (local_40 != 0);
  }
LAB_007fbb33:
  iVar4 = piVar9[0x345];
  if (iVar4 != 0) {
    local_60 = local_24.left;
    local_5c = local_24.top;
    local_58 = local_24.right;
    local_54 = local_24.bottom;
    if ((*(int *)(iVar4 + 0xe8) < 1) && (*(int *)(iVar4 + 0x11c) == 0)) {
LAB_007fbbc0:
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      FUN_0080554f(0,0,0,0);
      uVar10 = 0;
    }
    else {
      pcVar1 = *(code **)(*local_38 + 0x170);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if ((iVar4 != 0) || (DAT_00a127ac != 0)) goto LAB_007fbbc0;
      if (local_50 == 0) {
        local_54 = local_54 - 1;
        local_5c = local_54 - local_80;
      }
      else {
        local_58 = local_78 - 1;
        local_60 = (local_58 - local_7c) + 1;
      }
      FUN_0080554f(local_60,local_5c,local_58,local_54);
      uVar10 = 1;
    }
    FUN_00805aeb(uVar10);
  }
  FUN_0079efbc(local_98);
  FUN_008065ff();
  FUN_008039f7();
  FUN_0079dfff();
LAB_007fbc21:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCDropDownToolBar[169], CMFCImageEditorPaletteBar[169], CMFCMenuBar[169], CMFCOutlookBarPane[169], CMFCOutlookBarToolBar[169], CMFCPrintPreviewToolBar[169], CMFCTasksPaneToolBar[169], CMFCToolBar[169] */
/* 007fc420  FUN_007fc420  568 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007fc420(uint *param_1,int param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *in_ECX;
  int iVar6;
  undefined1 local_7c [8];
  undefined1 local_74 [8];
  undefined1 local_6c [20];
  uint local_58;
  uint local_54;
  uint *local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int *local_30;
  uint local_2c;
  uint local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x7fc42c;
  local_50 = param_1;
  local_40 = param_2;
  if (in_ECX[0x312] == 0) {
    FUN_007c23d4(param_1);
  }
  else {
    FUN_0079dea2(in_ECX);
    local_8 = 0;
    if (param_2 == 0) {
      local_48 = FUN_0080441a(local_6c);
    }
    else {
      iVar3 = FUN_007c2511();
      local_48 = FUN_0079efbc(iVar3 + 0x14c);
    }
    if (local_48 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    pcVar1 = *(code **)(*in_ECX + 0x354);
    guard_check_icall();
    uVar2 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x358);
    local_44 = uVar2;
    guard_check_icall();
    local_4c = (*pcVar1)();
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    local_2c = uVar2;
    local_28 = local_4c;
    SetRectEmpty(&local_24);
    iVar3 = local_40;
    uVar2 = (uint)(local_40 == 0);
    local_38 = uVar2;
    FUN_007ef36a(&local_24,uVar2);
    local_34 = (uint)(iVar3 != 0);
    local_3c = in_ECX[0x310];
    while (local_3c != 0) {
      local_30 = (int *)FUN_0044f2d0(&local_3c);
      local_30 = (int *)*local_30;
      if (local_30 == (int *)0x0) break;
      if ((local_3c == 0) && (in_ECX[0x345] != 0)) {
        pcVar1 = *(code **)(*in_ECX + 0x170);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 != 0) break;
      }
      piVar5 = local_30;
      uVar4 = local_44;
      if (in_ECX[0x2e3] != 0) {
        iVar3 = FUN_007c23d4(local_74);
        uVar4 = *(uint *)(iVar3 + 4);
      }
      local_58 = local_4c;
      pcVar1 = *(code **)(*piVar5 + 0x1c);
      local_54 = uVar4;
      guard_check_icall(local_7c,local_6c,&local_58,local_38);
      piVar5 = (int *)(*pcVar1)();
      iVar3 = *piVar5;
      iVar6 = piVar5[1];
      if (in_ECX[0x2e3] != 0) {
        iVar6 = in_ECX[0x2fa];
      }
      if (local_40 == 0) {
        if (((uVar2 == local_38) || (local_30[4] != 0)) && ((*(byte *)(local_30 + 9) & 1) != 0)) {
          iVar3 = 0;
          iVar6 = 0;
        }
        uVar2 = uVar2 + iVar3;
        if ((int)local_28 < (int)uVar2) {
          local_28 = uVar2;
        }
        if ((int)local_2c < (int)(iVar6 + local_34)) {
          local_2c = iVar6 + local_34;
        }
        if (local_30[4] != 0) {
          local_34 = local_34 + 5 + local_44;
          uVar2 = local_38;
        }
      }
      else {
        if ((int)local_28 < (int)(uVar2 + iVar3)) {
          local_28 = uVar2 + iVar3;
        }
        local_34 = local_34 + iVar6;
        uVar2 = local_38;
        if ((int)local_2c < (int)local_34) {
          local_2c = local_34;
        }
      }
    }
    FUN_0079efbc(local_48);
    *local_50 = local_28;
    local_50[1] = local_2c;
    FUN_0079dfff();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCDropDownToolBar[255], CMFCImageEditorPaletteBar[255], CMFCMenuBar[255], CMFCOutlookBarToolBar[255], CMFCPrintPreviewToolBar[255], CMFCTasksPaneToolBar[255], CMFCToolBar[255] */
/* 007fc74e  FUN_007fc74e  297 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007fc74e(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  CSimpleStringT<wchar_t,0> *pCVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined1 local_560 [1368];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x550;
  local_8 = 0x7fc75d;
  piVar2 = (int *)FUN_00880f70(param_1);
  if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar3 = FUN_0044e690(9,0);
  if (-1 < iVar3) {
    pCVar4 = (CSimpleStringT<wchar_t,0> *)Left(local_560,iVar3);
    local_8 = 0;
    ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(piVar2 + 0xb),pCVar4);
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  if (piVar2[7] != 0) {
    piVar2[2] = 0;
    piVar2[3] = 1;
    if (piVar2[1] == 0) {
      iVar3 = piVar2[0xd];
    }
    else {
      iVar3 = piVar2[0xe];
    }
    if ((iVar3 == -1) && (*(int *)(piVar2[0xb] + -0xc) == 0)) {
      pcVar1 = *(code **)(*in_ECX + 0x40c);
      guard_check_icall(piVar2);
      uVar5 = (*pcVar1)();
      FUN_00882f72(piVar2,DAT_00a127a0,in_ECX,0,uVar5);
      local_8 = 1;
      iVar3 = FUN_0079850d();
      if (iVar3 != 1) {
        pcVar1 = *(code **)(*piVar2 + 4);
        guard_check_icall(1);
        (*pcVar1)();
        FUN_00883215();
        goto LAB_007fc86a;
      }
      FUN_00883215();
    }
  }
  if (piVar2[1] == 0) {
    iVar3 = piVar2[0xd];
  }
  else {
    iVar3 = piVar2[0xe];
  }
  if (iVar3 < 0) {
    piVar2[2] = 1;
    piVar2[3] = 0;
  }
LAB_007fc86a:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCDropDownToolBar[153], CMFCImageEditorPaletteBar[153], CMFCMenuBar[153], CMFCOutlookBarToolBar[153], CMFCPopupMenuBar[153], CMFCPrintPreviewToolBar[153], CMFCTasksPaneToolBar[153], CMFCToolBar[153] */
/* 007fc9c4  FUN_007fc9c4  2500 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007fc9c4(int *param_1)

{
  code *pcVar1;
  ulong uVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  CMFCToolBarImages *pCVar7;
  int iVar8;
  double *pdVar9;
  undefined4 uVar10;
  BOOL BVar11;
  CDC *pCVar12;
  int *piVar13;
  undefined1 local_11c [12];
  uint local_110;
  int local_108;
  CMFCToolBarImages *local_104;
  CMFCToolBarImages *local_100;
  CMFCToolBarImages *local_fc;
  CMFCToolBarImages *local_f8;
  undefined4 local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  CMFCToolBarImages *local_e4;
  uint local_e0;
  int local_dc;
  undefined8 local_d8;
  CMFCToolBarImages *local_d0;
  CMFCToolBarImages *local_cc;
  int *local_c8;
  undefined8 local_c4;
  int *local_bc;
  uint local_b8;
  CDC *local_b4;
  CDC *local_ac;
  int local_a8;
  CDC local_a0 [44];
  tagRECT local_74;
  tagRECT local_64;
  RECT local_54;
  tagRECT local_44;
  tagRECT local_34;
  undefined1 local_24 [28];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10c;
  local_8 = 0x7fc9d3;
  local_54.left = 0;
  local_54.top = 0;
  local_54.right = 0;
  local_54.bottom = 0;
  pcVar1 = *(code **)(*param_1 + 0x50);
  guard_check_icall(&local_54);
  (*pcVar1)();
  pcVar1 = *(code **)(*local_bc + 0x194);
  guard_check_icall();
  local_e0 = (*pcVar1)();
  piVar13 = local_bc;
  local_e0 = local_e0 & 0xa000;
  local_110 = (uint)(local_e0 != 0);
  local_64.left = 0;
  local_64.top = 0;
  local_64.right = 0;
  local_64.bottom = 0;
  GetClientRect((HWND)local_bc[8],&local_64);
  FUN_007e522a(param_1,piVar13);
  piVar13 = local_bc;
  local_8 = 0;
  pCVar12 = local_a0;
  if (local_a8 == 0) {
    pCVar12 = local_ac;
  }
  local_b4 = pCVar12;
  uVar4 = FUN_00797b3d();
  if ((uVar4 & 0x8000) == 0) {
    piVar5 = (int *)FUN_007c2574();
    piVar13 = local_bc;
    local_c4 = (double)CONCAT44(piVar5,(int)local_c4);
    pcVar1 = *(code **)(*piVar5 + 0x34);
    guard_check_icall(local_b4,local_bc,local_64.left,local_64.top,local_64.right,local_64.bottom,
                      local_54.left,local_54.top,local_54.right,local_54.bottom,0);
    (*pcVar1)();
    pCVar12 = local_b4;
  }
  else {
    FUN_00828c84(pCVar12);
  }
  pcVar1 = *(code **)(*piVar13 + 0x3a4);
  guard_check_icall(pCVar12);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)local_b4 + 0x30);
  iVar6 = FUN_007c2511();
  uVar10 = *(undefined4 *)(iVar6 + 0x28);
  guard_check_icall(uVar10);
  (*pcVar1)();
  FUN_0079f0b8();
  local_34.left = 0;
  local_34.top = 0;
  local_34.right = 0;
  local_34.bottom = 0;
  GetClientRect((HWND)piVar13[8],&local_34);
  if (local_e0 == 0) {
    pcVar1 = *(code **)(*piVar13 + 0x358);
    guard_check_icall(uVar10);
    local_34.right = (*pcVar1)();
    local_34.right = local_34.right + local_34.left;
  }
  else {
    pcVar1 = *(code **)(*piVar13 + 0x354);
    guard_check_icall(uVar10);
    local_34.bottom = (*pcVar1)();
    local_34.bottom = local_34.bottom + local_34.top;
  }
  iVar6 = DAT_00a12790;
  if (piVar13[0x2de] != 0) {
    iVar6 = piVar13[0x30c];
  }
  local_24._8_8_ = 1.0;
  if (iVar6 == 0) {
    iVar6 = FUN_007c2511();
    if (*(int *)(iVar6 + 0x1e8) == 0) {
      local_24._8_8_ = 1.0;
    }
    else {
      local_24._8_8_ = *(double *)(iVar6 + 0x1e0);
    }
  }
  pCVar7 = (CMFCToolBarImages *)
           FUN_007fe05a(&DAT_00a12880,piVar13 + 0xae,&DAT_00a12df8,piVar13 + 0x180);
  local_104 = pCVar7;
  local_cc = pCVar7;
  local_e4 = (CMFCToolBarImages *)
             FUN_007fe05a(&DAT_00a12998,piVar13 + 0xf4,&DAT_00a12f10,piVar13 + 0x1c6);
  local_100 = (CMFCToolBarImages *)
              FUN_007fe05a(&DAT_00a12bc8,piVar13 + 0x13a,&DAT_00a13028,piVar13 + 0x20c);
  if (piVar13[0x2de] == 0) {
    local_fc = (CMFCToolBarImages *)&DAT_00a12ab0;
    local_f8 = (CMFCToolBarImages *)&DAT_00a12ce0;
  }
  else {
    local_fc = (CMFCToolBarImages *)(piVar13 + 0x252);
    local_f8 = (CMFCToolBarImages *)(piVar13 + 0x298);
  }
  local_dc = *(int *)(pCVar7 + 0x8c);
  iVar6 = FUN_007c2511();
  CMFCToolBarImages::SetTransparentColor(pCVar7,*(ulong *)(iVar6 + 0x1c));
  iVar8 = FUN_007c2574();
  iVar6 = piVar13[0x2eb];
  local_f4 = *(undefined4 *)(iVar8 + 0x5c);
  if (iVar6 == 0) {
    pdVar9 = (double *)FUN_007fe0a1();
  }
  else {
    pdVar9 = (double *)&local_d8;
    local_d8 = (double)CONCAT44(DAT_00a0062c,DAT_00a00628);
  }
  local_ec = *(int *)pdVar9;
  local_e8 = *(int *)((int)pdVar9 + 4);
  local_c4 = *pdVar9;
  if ((double)local_24._8_8_ != 1.0) {
    if (((iVar6 != 0) && (local_ec == -1)) && (local_e8 == -1)) {
      pdVar9 = (double *)FUN_007fe0a1();
      local_c4 = *pdVar9;
      if ((1.0 < (double)local_24._8_8_) && (piVar13[0x2df] != 0)) {
        local_c4 = (double)CONCAT44(DAT_00a0061c,DAT_00a00618);
      }
    }
    local_d8 = (double)(int)local_c4;
    local_ec = thunk_FUN_008d99f0();
    local_c4 = (double)local_c4._4_4_;
    local_e8 = thunk_FUN_008d99f0();
  }
  if (local_dc != 0) {
    if (((double)local_24._8_8_ != 1.0) && (*(double *)(local_cc + 0xb8) == 1.0)) {
      FUN_007eba06(local_24._8_8_);
    }
    iVar6 = FUN_007eb6ca(local_11c,local_ec,local_e8,local_f4);
    if (iVar6 == 0) goto LAB_007fd370;
  }
  if (local_e0 == 0) {
    pcVar1 = *(code **)(*(int *)local_b4 + 0x28);
    FUN_007c2511();
    guard_check_icall();
    uVar10 = (*pcVar1)();
  }
  else {
    uVar10 = FUN_0080441a();
  }
  local_c4 = (double)CONCAT44(uVar10,(int)local_c4);
  if (0 < *(int *)(local_e4 + 4)) {
    iVar6 = FUN_007c2574();
    *(undefined4 *)(iVar6 + 0x5c) = 0;
  }
  local_f0 = 0;
  local_d8 = (double)CONCAT44(piVar13[0x310],(undefined4)local_d8);
  iVar6 = piVar13[0x310];
  while (iVar6 != 0) {
    local_c8 = (int *)FUN_0044f2d0();
    local_c8 = (int *)*local_c8;
    if (local_c8 == (int *)0x0) break;
    local_34.left = local_c8[0x15];
    local_34.top = local_c8[0x16];
    local_34.right = local_c8[0x17];
    local_34.bottom = local_c8[0x18];
    local_74.left = 0;
    local_74.top = 0;
    local_74.right = 0;
    local_74.bottom = 0;
    if ((*(byte *)(local_c8 + 9) & 1) == 0) {
      BVar11 = IntersectRect(&local_74,&local_34,&local_54);
      piVar13 = local_bc;
      if (BVar11 != 0) {
        local_108 = FUN_007fe765();
        if (((local_c8[9] & 0x40000U) == 0) || (DAT_00a127ac != 0)) {
          local_d0 = (CMFCToolBarImages *)0x0;
        }
        else {
          local_d0 = (CMFCToolBarImages *)0x1;
        }
        pcVar1 = *(code **)(*(int *)local_b4 + 0x58);
        guard_check_icall();
        iVar6 = (*pcVar1)();
        if (iVar6 != 0) {
          local_b8 = 0;
          if (local_dc != 0) {
            if (local_c8[1] == 0) {
              if (piVar13[0x2eb] == 0) {
                if ((local_d0 == (CMFCToolBarImages *)0x0) || (*(int *)(local_100 + 4) < 1)) {
                  bVar3 = false;
                  local_b8 = 0;
                  pCVar7 = local_104;
                }
                else {
                  bVar3 = true;
                  local_b8 = 1;
                  pCVar7 = local_100;
                }
                local_d0 = pCVar7;
                if ((((local_108 == 0) && (!bVar3)) && ((local_c8[9] & 0x20000U) == 0)) &&
                   (0 < *(int *)(local_e4 + 4))) {
                  pcVar1 = *(code **)(*local_c8 + 0x70);
                  guard_check_icall();
                  iVar6 = (*pcVar1)();
                  pCVar7 = local_e4;
                  if (iVar6 != 0) {
                    pCVar7 = local_d0;
                  }
                }
              }
              else if ((local_d0 == (CMFCToolBarImages *)0x0) || (*(int *)(local_f8 + 4) < 1)) {
                pCVar7 = local_fc;
                if (*(int *)(local_fc + 4) < 1) {
                  if ((local_d0 == (CMFCToolBarImages *)0x0) || (*(int *)(local_100 + 4) < 1)) {
                    local_b8 = 0;
                    pCVar7 = local_104;
                  }
                  else {
                    local_b8 = 1;
                    pCVar7 = local_100;
                  }
                }
              }
              else {
                local_b8 = 1;
                pCVar7 = local_f8;
              }
            }
            else {
              pCVar7 = (CMFCToolBarImages *)0x0;
              if (-1 < local_c8[0xe]) {
                pCVar7 = DAT_00a127a0;
              }
            }
            if ((pCVar7 != local_cc) && (pCVar7 != (CMFCToolBarImages *)0x0)) {
              FUN_007e98b8();
              iVar6 = FUN_007c2511();
              CMFCToolBarImages::SetTransparentColor(pCVar7,*(ulong *)(iVar6 + 0x1c));
              if (((double)local_24._8_8_ != 1.0) && (*(double *)(pCVar7 + 0xb8) == 1.0)) {
                FUN_007eba06(local_24._8_8_);
              }
              FUN_007eb6ca(local_11c,local_ec,local_e8,local_f4);
              local_cc = pCVar7;
            }
          }
          pcVar1 = *(code **)(*piVar13 + 0x3bc);
          guard_check_icall(local_b4,local_c8,-(uint)(local_dc != 0) & (uint)local_cc,local_108);
          (*pcVar1)();
        }
      }
    }
    else {
      local_b8 = local_110;
      local_44.left = 0;
      local_44.top = 0;
      local_44.right = 0;
      local_44.bottom = 0;
      SetRectEmpty(&local_44);
      piVar13 = local_bc;
      pcVar1 = *(code **)(*local_bc + 0x410);
      guard_check_icall(local_c8,&local_44);
      (*pcVar1)();
      piVar5 = local_c8;
      if (local_c8[4] != 0) {
        local_b8 = local_b8 & ~-(uint)(local_e0 != 0);
      }
      BVar11 = IntersectRect(&local_74,&local_44,&local_54);
      if ((BVar11 != 0) && (piVar5[0x10] == 0)) {
        pcVar1 = *(code **)(*piVar13 + 0x3f8);
        guard_check_icall(local_b4,&local_44);
        (*pcVar1)();
      }
    }
    local_f0 = local_f0 + 1;
    iVar6 = local_d8._4_4_;
  }
  iVar6 = piVar13[0x2fd];
  if (piVar13[0x312] <= iVar6) {
    piVar13[0x2fd] = -1;
    iVar6 = -1;
  }
  if ((DAT_00a127ac != 0) || (DAT_00a127b0 != 0)) {
    if ((-1 < iVar6) && ((piVar13[0x2de] == 0 && (DAT_00a12794 == piVar13)))) {
      piVar5 = (int *)FUN_007fde79();
      local_d8 = (double)CONCAT44(piVar5,(undefined4)local_d8);
      if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      pcVar1 = *(code **)(*piVar5 + 0x50);
      guard_check_icall();
      iVar6 = (*pcVar1)();
      if (iVar6 != 0) {
        local_24._0_4_ = *(LONG *)(local_d8._4_4_ + 0x54);
        local_24._4_4_ = *(LONG *)(local_d8._4_4_ + 0x58);
        local_24._8_8_ = *(double *)(local_d8._4_4_ + 0x5c);
        iVar6 = FUN_007c2511();
        uVar2 = *(ulong *)(iVar6 + 0x28);
        iVar6 = FUN_007c2511();
        CDC::Draw3dRect(local_b4,(tagRECT *)local_24,*(ulong *)(iVar6 + 0x28),uVar2);
        InflateRect((LPRECT)local_24,-1,-1);
        iVar6 = FUN_007c2511();
        uVar2 = *(ulong *)(iVar6 + 0x28);
        iVar6 = FUN_007c2511();
        CDC::Draw3dRect(local_b4,(tagRECT *)local_24,*(ulong *)(iVar6 + 0x28),uVar2);
        piVar13 = local_bc;
      }
    }
    if (((DAT_00a127ac != 0) && (-1 < piVar13[0x300])) && (piVar13[0x2de] == 0)) {
      pcVar1 = *(code **)(*piVar13 + 0x3c0);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  pcVar1 = *(code **)(*(int *)local_b4 + 0x28);
  guard_check_icall();
  (*pcVar1)();
  if (local_dc != 0) {
    FUN_007e98b8();
  }
  iVar6 = FUN_007c2574();
  *(undefined4 *)(iVar6 + 0x5c) = local_f4;
LAB_007fd370:
  FUN_007e54da();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCDropDownToolBar[240], CMFCImageEditorPaletteBar[240], CMFCMenuBar[240], CMFCOutlookBarPane[240], CMFCOutlookBarToolBar[240], CMFCPrintPreviewToolBar[240], CMFCTasksPaneToolBar[240], CMFCToolBar[240] */
/* 007fd44d  FUN_007fd44d  478 bytes, 0 callers */

void FUN_007fd44d(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  undefined1 local_3c [8];
  undefined1 local_34 [8];
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  undefined1 local_1c [8];
  undefined1 local_14 [8];
  undefined4 local_c;
  uint local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x194);
  guard_check_icall();
  local_8 = (*pcVar1)();
  local_8 = local_8 & 0xa000;
  local_c = FUN_0079efbc(in_ECX + 0x33b);
  iVar4 = 0;
  do {
    if (local_8 == 0) {
      FUN_0079ec58(local_2c,in_ECX[0x333],
                   (in_ECX[0x336] - in_ECX[0x334]) / 2 + -1 + in_ECX[0x334] + iVar4);
      CDC::LineTo(param_1,in_ECX[0x335],
                  (in_ECX[0x336] - in_ECX[0x334]) / 2 + -1 + in_ECX[0x334] + iVar4);
      FUN_0079ec58(local_34,in_ECX[0x333] + iVar4,in_ECX[0x334] + iVar4);
      CDC::LineTo(param_1,in_ECX[0x333] + iVar4,in_ECX[0x336] - iVar4);
      FUN_0079ec58(local_3c,(in_ECX[0x335] - iVar4) + -1,in_ECX[0x334] + iVar4);
      iVar2 = (in_ECX[0x335] - iVar4) + -1;
      iVar3 = in_ECX[0x336] - iVar4;
    }
    else {
      FUN_0079ec58(local_14,(in_ECX[0x335] - in_ECX[0x333]) / 2 + in_ECX[0x333] + -1 + iVar4,
                   in_ECX[0x334]);
      CDC::LineTo(param_1,(in_ECX[0x335] - in_ECX[0x333]) / 2 + in_ECX[0x333] + -1 + iVar4,
                  in_ECX[0x336]);
      FUN_0079ec58(local_1c,in_ECX[0x333] + iVar4,in_ECX[0x334] + iVar4);
      CDC::LineTo(param_1,in_ECX[0x335] - iVar4,in_ECX[0x334] + iVar4);
      FUN_0079ec58(local_24,in_ECX[0x333] + iVar4,(in_ECX[0x336] - iVar4) + -1);
      iVar2 = in_ECX[0x335] - iVar4;
      iVar3 = (in_ECX[0x336] - iVar4) + -1;
    }
    CDC::LineTo(param_1,iVar2,iVar3);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_0079efbc(local_c);
  return;
}




/* vtable slots: CMFCDropDownToolBar[254], CMFCImageEditorPaletteBar[254], CMFCMenuBar[254], CMFCOutlookBarPane[254], CMFCOutlookBarToolBar[254], CMFCPrintPreviewToolBar[254], CMFCTasksPaneToolBar[254], CMFCToolBar[254] */
/* 007fd62b  FUN_007fd62b  63 bytes, 0 callers */

void FUN_007fd62b(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  undefined4 in_ECX;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x48);
  guard_check_icall(param_1,in_ECX,*param_2,param_2[1],param_2[2],param_2[3],param_3);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCDropDownToolBar[258], CMFCImageEditorPaletteBar[258], CMFCMenuBar[258], CMFCOutlookBarToolBar[258], CMFCPrintPreviewToolBar[258], CMFCTasksPaneToolBar[258], CMFCToolBar[258] */
/* 007fd73b  FUN_007fd73b  395 bytes, 2 callers */

undefined4 FUN_007fd73b(int *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  int *piVar4;
  UINT uIDCheckItem;
  uint local_c;
  int *local_8;
  
  local_c = in_ECX[0x27] & 0xa000;
  pcVar1 = *(code **)(*param_1 + 0x68);
  local_8 = in_ECX;
  guard_check_icall(param_2);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) goto LAB_007fd859;
  if (param_1[3] == 0) {
LAB_007fd78e:
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x420f,1);
  }
  else {
    if (param_1[1] == 0) {
      iVar2 = param_1[0xd];
    }
    else {
      iVar2 = param_1[0xe];
    }
    if (iVar2 < 0) goto LAB_007fd78e;
  }
  if ((param_1[8] == -1) || (param_1[8] == 0)) {
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x420e,1);
  }
  if ((param_1[2] == 0) && ((param_1[6] == 0 || (local_c == 0)))) {
    uIDCheckItem = 0x4212;
  }
  else if (param_1[3] == 0) {
    uIDCheckItem = 0x4213;
  }
  else {
    uIDCheckItem = 0x4214;
  }
  CheckMenuItem(*(HMENU *)(param_2 + 4),uIDCheckItem,8);
  if ((param_1[6] != 0) && (local_c != 0)) {
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4212,1);
  }
  pcVar1 = *(code **)(*local_8 + 0x40c);
  guard_check_icall(param_1);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4212,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4213,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4214,1);
    param_1[2] = 1;
  }
LAB_007fd859:
  local_c = local_8[0x310];
  if (local_c != 0) {
    local_8 = local_8 + 0x30f;
    piVar4 = (int *)0x0;
    do {
      puVar3 = (undefined4 *)FUN_0044f2d0(&local_c);
      if ((int *)*puVar3 == param_1) {
        if (piVar4 == (int *)0x0) {
          EnableMenuItem(*(HMENU *)(param_2 + 4),0x4215,1);
          return 1;
        }
        if ((*(byte *)(piVar4 + 9) & 1) == 0) {
          return 1;
        }
        CheckMenuItem(*(HMENU *)(param_2 + 4),0x4215,8);
        return 1;
      }
      piVar4 = (int *)*puVar3;
    } while (local_c != 0);
  }
  return 1;
}




/* vtable slots: CMFCDropDownToolBar[248], CMFCImageEditorPaletteBar[248], CMFCOutlookBarPane[248], CMFCOutlookBarToolBar[248], CMFCPrintPreviewToolBar[248], CMFCTasksPaneToolBar[248], CMFCToolBar[248] */
/* 007fda05  FUN_007fda05  990 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007fda05(int param_1,int param_2,LPRECT param_3)

{
  int iVar1;
  code *pcVar2;
  LONG LVar3;
  LONG LVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  LONG LVar8;
  int *in_ECX;
  int iVar9;
  int *piVar10;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_28 = -1;
  local_1c = in_ECX;
  SetRectEmpty(param_3);
  pcVar2 = *(code **)(*in_ECX + 0x194);
  guard_check_icall();
  uVar5 = (*pcVar2)();
  local_34 = param_1;
  local_24 = param_2;
  if (param_2 < 0) {
    local_24 = 0;
  }
  if ((local_1c[0x312] == 0) || ((local_1c[0x312] == 1 && (local_1c[0x345] != 0)))) {
    GetClientRect((HWND)local_1c[8],param_3);
    iVar7 = 0;
    piVar10 = local_1c;
  }
  else {
    iVar7 = -1;
    if ((uVar5 & 0xa000) == 0) {
      local_20 = 0;
      local_34 = local_1c[0x310];
      while (local_34 != 0) {
        iVar7 = FUN_0049acb0(&local_34);
        if (iVar7 == 0) goto LAB_007fddde;
        iVar9 = *(int *)(iVar7 + 0x58);
        LVar8 = *(LONG *)(iVar7 + 0x5c);
        iVar6 = *(int *)(iVar7 + 0x60);
        if (local_24 < iVar9) {
          local_28 = local_20;
          param_3->left = *(LONG *)(iVar7 + 0x54);
          param_3->top = iVar9;
          param_3->right = LVar8;
          param_3->bottom = iVar6;
LAB_007fdd25:
          param_3->bottom = param_3->top;
          iVar7 = local_20;
          goto LAB_007fdd2b;
        }
        if (local_24 <= iVar6) {
          param_3->left = *(LONG *)(iVar7 + 0x54);
          param_3->top = iVar9;
          param_3->right = LVar8;
          param_3->bottom = iVar6;
          if (local_24 - iVar9 <= iVar6 - local_24) goto LAB_007fdd25;
          iVar7 = local_20 + 1;
          param_3->top = param_3->bottom;
          goto LAB_007fdd2b;
        }
        local_20 = local_20 + 1;
        iVar7 = local_28;
      }
      goto LAB_007fdcc6;
    }
    pcVar2 = *(code **)(*local_1c + 0x354);
    guard_check_icall();
    local_30 = (*pcVar2)();
    iVar9 = 0;
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    local_2c = 0;
    SetRectEmpty(&local_18);
    local_20 = local_1c[0x310];
    while (local_20 != 0) {
      iVar6 = FUN_0049acb0(&local_20);
      if (iVar6 == 0) goto LAB_007fddde;
      LVar8 = local_18.left;
      iVar1 = local_18.top;
      LVar3 = local_18.right;
      LVar4 = local_18.bottom;
      iVar7 = local_28;
      if ((*(int *)(iVar6 + 0x40) == 0) && (*(int *)(iVar6 + 0x50) != 0)) {
        iVar1 = *(int *)(iVar6 + 0x58);
        iVar9 = local_2c;
        LVar8 = *(int *)(iVar6 + 0x54);
        LVar3 = *(int *)(iVar6 + 0x5c);
        LVar4 = *(LONG *)(iVar6 + 0x60);
        if ((0 < local_2c) && (local_18.bottom < iVar1)) {
          local_30 = iVar1 - local_18.bottom;
          break;
        }
      }
      local_18.bottom = LVar4;
      local_18.right = LVar3;
      local_18.top = iVar1;
      local_18.left = LVar8;
      iVar9 = iVar9 + 1;
      local_2c = iVar9;
    }
    pcVar2 = *(code **)(*local_1c + 0x354);
    guard_check_icall();
    iVar9 = (*pcVar2)();
    local_30 = local_24 / (iVar9 + local_30);
    local_20 = local_1c[0x310];
    local_24 = 0;
    local_2c = 0;
    while (local_20 != 0) {
      iVar7 = FUN_0049acb0(&local_20);
      if (iVar7 == 0) {
LAB_007fddde:
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      iVar9 = local_18.left;
      iVar6 = local_18.top;
      iVar1 = local_18.right;
      LVar8 = local_18.bottom;
      if ((*(int *)(iVar7 + 0x40) == 0) && (*(int *)(iVar7 + 0x50) != 0)) {
        iVar9 = *(int *)(iVar7 + 0x54);
        iVar6 = *(int *)(iVar7 + 0x58);
        iVar1 = *(int *)(iVar7 + 0x5c);
        LVar8 = *(LONG *)(iVar7 + 0x60);
        if ((0 < local_2c) && (local_18.bottom <= iVar6)) {
          local_24 = local_24 + 1;
        }
        if (local_30 < local_24) {
          param_3->left = local_18.left;
          param_3->top = local_18.top;
          param_3->right = local_18.right;
          param_3->bottom = local_18.bottom;
          iVar7 = local_2c + -1;
LAB_007fdc3a:
          param_3->left = param_3->right;
        }
        else {
          if (local_24 != local_30) goto LAB_007fdbe9;
          iVar7 = local_2c;
          if (local_34 < iVar9) {
            local_28 = local_2c;
            param_3->left = iVar9;
            param_3->top = iVar6;
            param_3->right = iVar1;
            param_3->bottom = LVar8;
            param_3->right = param_3->left;
          }
          else {
            if (iVar1 < local_34) goto LAB_007fdbe9;
            param_3->left = iVar9;
            param_3->top = iVar6;
            param_3->right = iVar1;
            param_3->bottom = LVar8;
            if (iVar1 - local_34 < local_34 - iVar9) {
              iVar7 = local_2c + 1;
              goto LAB_007fdc3a;
            }
            param_3->right = param_3->left;
          }
        }
        if (iVar7 != -1) goto LAB_007fdd2b;
        break;
      }
LAB_007fdbe9:
      local_18.bottom = LVar8;
      local_18.right = iVar1;
      local_18.top = iVar6;
      local_18.left = iVar9;
      local_2c = local_2c + 1;
      iVar7 = local_28;
    }
    if (local_24 != local_30) goto LAB_007fdcc6;
    param_3->left = local_18.left;
    param_3->top = local_18.top;
    param_3->right = local_18.right;
    param_3->bottom = local_18.bottom;
    param_3->left = param_3->right;
    iVar7 = local_2c;
LAB_007fdd2b:
    piVar10 = local_1c;
    if (iVar7 < 0) goto LAB_007fdcc6;
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect((HWND)piVar10[8],&local_18);
  if (((piVar10[0x345] != 0) && (iVar7 == piVar10[0x312])) &&
     (iVar7 = piVar10[0x312] + -1, iVar7 < 0)) {
    iVar7 = 0;
  }
  local_1c = piVar10;
  if ((uVar5 & 0xa000) == 0) {
    iVar9 = param_3->top + -3;
    LVar8 = local_18.top;
    if (local_18.top <= iVar9) {
      LVar8 = iVar9;
    }
    param_3->top = LVar8;
    param_3->bottom = LVar8 + 6;
    if (local_18.bottom < LVar8 + 6) {
      param_3->bottom = local_18.bottom;
      param_3->top = local_18.bottom + -6;
    }
  }
  else {
    iVar9 = param_3->left + -3;
    LVar8 = local_18.left;
    if (local_18.left <= iVar9) {
      LVar8 = iVar9;
    }
    param_3->left = LVar8;
    param_3->right = LVar8 + 6;
    if (local_18.right < LVar8 + 6) {
      param_3->right = local_18.right;
      param_3->left = local_18.right + -6;
    }
  }
LAB_007fdcc6:
  if ((local_1c[0x345] != 0) && (iVar7 == local_1c[0x312])) {
    iVar7 = -1;
    SetRectEmpty(param_3);
  }
  return iVar7;
}




/* vtable slots: CMFCDropDownToolBar[265], CMFCImageEditorPaletteBar[265], CMFCMenuBar[265], CMFCOutlookBarPane[265], CMFCOutlookBarToolBar[265], CMFCPrintPreviewToolBar[265], CMFCTasksPaneToolBar[265], CMFCToolBar[265] */
/* 007ff5fb  FUN_007ff5fb  73 bytes, 0 callers */

void FUN_007ff5fb(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x170);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x2d4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x20c);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCDropDownToolBar[260], CMFCImageEditorPaletteBar[260], CMFCMenuBar[260], CMFCOutlookBarPane[260], CMFCOutlookBarToolBar[260], CMFCPrintPreviewToolBar[260], CMFCTasksPaneToolBar[260], CMFCToolBar[260] */
/* 007ff766  OnCalcSeparatorRect  113 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBar::OnCalcSeparatorRect(class CMFCToolBarButton
   *,class CRect &,int)
   
   Library: Visual Studio 2012 Release */

void __thiscall
CMFCToolBar::OnCalcSeparatorRect
          (CMFCToolBar *this,CMFCToolBarButton *param_1,CRect *param_2,int param_3)

{
  int iVar1;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(this + 0x20),&local_18);
  *(undefined4 *)param_2 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x60);
  if ((*(int *)(param_1 + 0x10) != 0) && (param_3 != 0)) {
    *(LONG *)param_2 = local_18.left;
    *(LONG *)(param_2 + 8) = local_18.right;
    iVar1 = *(int *)(param_1 + 0x60);
    *(int *)(param_2 + 4) = iVar1;
    *(int *)(param_2 + 0xc) = iVar1 + 5;
  }
  return;
}




/* vtable slots: CMFCDropDownToolBar[236], CMFCImageEditorPaletteBar[236], CMFCOutlookBarPane[236], CMFCOutlookBarToolBar[236], CMFCPrintPreviewToolBar[236], CMFCTasksPaneToolBar[236], CMFCToolBar[236] */
/* 007ff92c  FUN_007ff92c  1716 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007ff92c(int param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  CObject *in_ECX;
  undefined1 local_30 [4];
  CObject *local_2c;
  int local_28;
  CObject *local_24;
  CObject *local_20;
  CObject *local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = (CObject *)param_1;
  if ((*(int *)(in_ECX + 0xbf8) == param_1) && (-1 < *(int *)(in_ECX + 0xbf8))) {
    local_20 = (CObject *)0xffffffff;
  }
  *(CObject **)(in_ECX + 0xbf8) = local_20;
  local_1c = (CObject *)FUN_007fdf83(0);
  if (local_1c == (CObject *)0x0) {
    if (DAT_00a127ac == 0) {
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCMenuBar_00a00b00,in_ECX);
      if (pCVar2 == (CObject *)0x0) {
        return;
      }
      iVar3 = FUN_007c2511();
      if (*(int *)(iVar3 + 0x19c) == 0) {
        return;
      }
      pHVar4 = GetFocus();
      pCVar5 = CWnd::FromHandle(pHVar4);
      if (pCVar5 != (CWnd *)in_ECX) {
        return;
      }
      iVar3 = FUN_007fb277(*(undefined4 *)(in_ECX + 0xbf8));
      if (iVar3 < 1) {
        return;
      }
      NotifyWinEvent(0x8005,*(HWND *)(in_ECX + 0x20),-4,iVar3);
      return;
    }
  }
  else {
    pcVar1 = *(code **)(*(int *)local_1c + 0xec);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return;
    }
  }
  pCVar2 = local_1c;
  if (((int)local_20 < 0) || (*(int *)(in_ECX + 0xc48) <= (int)local_20)) {
    *(undefined4 *)(in_ECX + 0xbf8) = 0xffffffff;
    if (local_1c == (CObject *)0x0) {
      return;
    }
    if (DAT_00a127ac == 0) {
      return;
    }
    if (DAT_00a127b0 != 0) {
      return;
    }
    pcVar1 = *(code **)(*(int *)local_1c + 0x58);
    guard_check_icall();
    (*pcVar1)();
    return;
  }
  pCVar6 = (CObject *)FUN_007fde79(local_20);
  local_20 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar6);
  if (local_20 == pCVar2) {
    if (DAT_00a127ac == 0) goto LAB_007ffd08;
    if (pCVar2 != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x70);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        pcVar1 = *(code **)(*(int *)local_1c + 0x58);
        guard_check_icall();
        (*pcVar1)();
      }
    }
  }
  else {
    local_28 = 0;
    local_24 = (CObject *)CMFCPopupMenu::GetAnimationType(0);
    iVar3 = local_28;
    if (pCVar2 != (CObject *)0x0) {
      local_28 = *(int *)(in_ECX + 0xbf0);
      if (DAT_00a127ac == 0) {
        *(undefined4 *)(in_ECX + 0xbf0) = 0xffffffff;
      }
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x58);
      guard_check_icall();
      (*pcVar1)();
      *(int *)(in_ECX + 0xbf0) = local_28;
      iVar3 = 1;
    }
    if ((local_20 != (CObject *)0x0) &&
       ((DAT_00a127ac == 0 ||
        (iVar7 = FUN_0079d98a(&PTR_s_CMFCToolBarSystemMenuButton_00a00b28), iVar7 == 0)))) {
      DAT_00a139d8 = (CObject *)((uint)DAT_00a139d8 & ~-(uint)(iVar3 != 0));
      pcVar1 = *(code **)(*(int *)local_20 + 0x20);
      guard_check_icall();
      (*pcVar1)();
      DAT_00a139d8 = local_24;
    }
  }
  if ((DAT_00a127ac != 0) && (*(int *)(in_ECX + 0xc00) < 0)) {
    local_24 = *(CObject **)(in_ECX + 0xbf0);
    *(undefined4 *)(in_ECX + 0xbf4) = *(undefined4 *)(in_ECX + 0xbf8);
    if ((local_24 != (CObject *)0xffffffff) &&
       ((-1 < (int)local_24 && ((int)local_24 < *(int *)(in_ECX + 0xc48))))) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      pcVar1 = *(code **)(*(int *)in_ECX + 0x370);
      guard_check_icall(local_24,&local_18);
      (*pcVar1)();
      iVar3 = FUN_007fde79(local_24);
      if ((iVar3 != 0) && (iVar3 == *(int *)(in_ECX + 0xd14))) {
        local_18.right = local_18.right + 10;
        local_18.bottom = local_18.bottom + 10;
      }
      InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_18,1);
      if ((iVar3 != 0) && (iVar3 == *(int *)(in_ECX + 0xd14))) {
        FUN_007fe00a(local_30);
        iVar3 = FUN_004208d0(0,0);
        if (iVar3 != 0) {
          piVar8 = (int *)FUN_007fe00a(local_30);
          InflateRect(&local_18,*piVar8,piVar8[1]);
          RedrawWindow(*(HWND *)(in_ECX + 0x20),&local_18,(HRGN)0x0,0x401);
        }
      }
    }
    iVar3 = FUN_007fde79(*(undefined4 *)(in_ECX + 0xbf4));
    if (iVar3 == 0) {
      return;
    }
    if ((*(byte *)(iVar3 + 0x24) & 1) == 0) {
      local_24 = *(CObject **)(in_ECX + 0xbf4);
      if ((-1 < (int)local_24) && ((int)local_24 < *(int *)(in_ECX + 0xc48))) {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        pcVar1 = *(code **)(*(int *)in_ECX + 0x370);
        guard_check_icall(local_24,&local_18);
        (*pcVar1)();
        iVar3 = FUN_007fde79(local_24);
        if ((iVar3 != 0) && (iVar3 == *(int *)(in_ECX + 0xd14))) {
          local_18.right = local_18.right + 10;
          local_18.bottom = local_18.bottom + 10;
        }
        InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_18,1);
        if ((iVar3 != 0) && (iVar3 == *(int *)(in_ECX + 0xd14))) {
          FUN_007fe00a(local_30);
          iVar3 = FUN_004208d0(0,0);
          if (iVar3 != 0) {
            piVar8 = (int *)FUN_007fe00a(local_30);
            InflateRect(&local_18,*piVar8,piVar8[1]);
            RedrawWindow(*(HWND *)(in_ECX + 0x20),&local_18,(HRGN)0x0,0x401);
          }
        }
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0xbf4) = 0xffffffff;
    }
  }
LAB_007ffd08:
  if ((-1 < *(int *)(in_ECX + 0xbf8)) && (*(int *)(in_ECX + 0xbf8) != *(int *)(in_ECX + 0xbf0))) {
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCMenuBar_00a00b00,in_ECX);
    if ((pCVar2 != (CObject *)0x0) &&
       ((((iVar3 = FUN_007c2511(), *(int *)(iVar3 + 0x19c) != 0 && (*(int *)(in_ECX + 0xbf0) == -1))
         && (local_24 = *(CObject **)(in_ECX + 0xbf8), -1 < (int)local_24)) &&
        ((int)local_24 < *(int *)(in_ECX + 0xc48))))) {
      local_28 = *(int *)(in_ECX + 0xc40);
      local_20 = (CObject *)0x0;
      local_1c = (CObject *)0x1;
      if (local_28 != 0) {
        local_2c = in_ECX + 0xc3c;
        do {
          puVar9 = (undefined4 *)FUN_0044f2d0(&local_28);
          pcVar1 = *(code **)(*(int *)*puVar9 + 0xbc);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          if (0 < iVar3) {
            if (local_20 == local_24) {
              if (0 < (int)local_1c) {
                NotifyWinEvent(0x8005,*(HWND *)(in_ECX + 0x20),-4,(LONG)local_1c);
              }
              break;
            }
            local_1c = local_1c + 1;
          }
          local_20 = local_20 + 1;
        } while (local_28 != 0);
      }
    }
    local_2c = *(CObject **)(in_ECX + 0xbf0);
    if ((-1 < (int)local_2c) && ((int)local_2c < *(int *)(in_ECX + 0xc48))) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      pcVar1 = *(code **)(*(int *)in_ECX + 0x370);
      local_18.bottom = 0;
      guard_check_icall(local_2c,&local_18);
      (*pcVar1)();
      iVar3 = FUN_007fde79(local_2c);
      if ((iVar3 != 0) && (iVar3 == *(int *)(in_ECX + 0xd14))) {
        local_18.right = local_18.right + 10;
        local_18.bottom = local_18.bottom + 10;
      }
      InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_18,1);
      if ((iVar3 != 0) && (iVar3 == *(int *)(in_ECX + 0xd14))) {
        FUN_007fe00a(local_30);
        iVar3 = FUN_004208d0(0,0);
        if (iVar3 != 0) {
          piVar8 = (int *)FUN_007fe00a(local_30);
          InflateRect(&local_18,*piVar8,piVar8[1]);
          RedrawWindow(*(HWND *)(in_ECX + 0x20),&local_18,(HRGN)0x0,0x401);
        }
      }
    }
    local_2c = *(CObject **)(in_ECX + 0xbf8);
    *(CObject **)(in_ECX + 0xbf0) = local_2c;
    if ((-1 < (int)local_2c) && ((int)local_2c < *(int *)(in_ECX + 0xc48))) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      pcVar1 = *(code **)(*(int *)in_ECX + 0x370);
      local_18.bottom = 0;
      guard_check_icall(local_2c,&local_18);
      (*pcVar1)();
      iVar3 = FUN_007fde79(local_2c);
      if ((iVar3 != 0) && (iVar3 == *(int *)(in_ECX + 0xd14))) {
        local_18.right = local_18.right + 10;
        local_18.bottom = local_18.bottom + 10;
      }
      InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_18,1);
      if ((iVar3 != 0) && (iVar3 == *(int *)(in_ECX + 0xd14))) {
        FUN_007fe00a(local_30);
        iVar3 = FUN_004208d0(0,0);
        if (iVar3 != 0) {
          piVar8 = (int *)FUN_007fe00a(local_30);
          InflateRect(&local_18,*piVar8,piVar8[1]);
          RedrawWindow(*(HWND *)(in_ECX + 0x20),&local_18,(HRGN)0x0,0x401);
        }
      }
    }
    UpdateWindow(*(HWND *)(in_ECX + 0x20));
  }
  return;
}




/* vtable slots: CMFCDropDownToolBar[246], CMFCImageEditorPaletteBar[246], CMFCMenuBar[246], CMFCOutlookBarToolBar[246], CMFCPrintPreviewToolBar[246], CMFCTasksPaneToolBar[246], CMFCToolBar[246] */
/* 008008a0  FUN_008008a0  431 bytes, 2 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char FUN_008008a0(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  BOOL BVar5;
  int iVar6;
  int *in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (((in_ECX[0x2de] == 0) && (in_ECX[0x2ee] == 0)) &&
     (piVar3 = (int *)FUN_00880f70(param_1), piVar3 != (int *)0x0)) {
    pcVar1 = *(code **)(*piVar3 + 0x10);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    if (iVar4 != 0) {
      in_ECX[0x2e8] = param_2 & 8;
      if (in_ECX[0x343] == 0) {
        iVar4 = in_ECX[0x2fd];
        in_ECX[0x2fd] = -1;
        if (iVar4 != -1) {
          FUN_007fe655(iVar4);
          UpdateWindow((HWND)in_ECX[8]);
        }
      }
      local_18.left = in_ECX[0x333];
      local_18.top = in_ECX[0x334];
      local_18.right = in_ECX[0x335];
      local_18.bottom = in_ECX[0x336];
      pcVar1 = *(code **)(*in_ECX + 0x3e0);
      guard_check_icall(param_3,param_4,in_ECX + 0x333);
      iVar4 = (*pcVar1)();
      BVar5 = EqualRect(&local_18,(RECT *)(in_ECX + 0x333));
      if (BVar5 == 0) {
        in_ECX[0x300] = iVar4;
        InflateRect(&local_18,2,2);
        InvalidateRect((HWND)in_ECX[8],&local_18,1);
        local_18.left = ((RECT *)(in_ECX + 0x333))->left;
        local_18.top = in_ECX[0x334];
        local_18.right = in_ECX[0x335];
        local_18.bottom = in_ECX[0x336];
        InflateRect(&local_18,2,2);
        InvalidateRect((HWND)in_ECX[8],(RECT *)(in_ECX + 0x333),1);
        UpdateWindow((HWND)in_ECX[8]);
      }
      iVar2 = in_ECX[0x2fc];
      pcVar1 = *(code **)(*in_ECX + 0x390);
      guard_check_icall(param_3,param_4);
      iVar6 = (*pcVar1)();
      in_ECX[0x2fc] = iVar6;
      if (iVar2 != iVar6) {
        pcVar1 = *(code **)(*in_ECX + 0x3b0);
        guard_check_icall(iVar6);
        (*pcVar1)();
      }
      if (iVar4 != -1) {
        return ((param_2 & 8) == 0) + '\x01';
      }
    }
  }
  return '\0';
}




/* vtable slots: CMFCDropDownToolBar[232], CMFCImageEditorPaletteBar[232], CMFCOutlookBarPane[232], CMFCOutlookBarToolBar[232], CMFCPrintPreviewToolBar[232], CMFCTasksPaneToolBar[232], CMFCToolBar[232] */
/* 008027e8  FUN_008027e8  145 bytes, 2 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008027e8(int param_1)

{
  int iVar1;
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> local_218 [4];
  wchar_t local_214 [262];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x208;
  local_8 = 0x8027f7;
  if ((*(int *)(param_1 + 0x20) != 0) && (*(int *)(param_1 + 0x20) != -1)) {
    CStringT<>();
    local_8 = 0;
    iVar1 = FUN_0078f2e1(*(undefined4 *)(param_1 + 0x20),local_214,0x100);
    if ((iVar1 != 0) && (iVar1 = AfxExtractSubString(local_218,local_214,1,L'\n'), iVar1 != 0)) {
      ATL::CSimpleStringT<wchar_t,0>::operator=
                ((CSimpleStringT<wchar_t,0> *)(param_1 + 0x2c),
                 (CSimpleStringT<wchar_t,0> *)local_218);
    }
    FUN_00406b10();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCDropDownToolBar[29], CMFCImageEditorPaletteBar[29], CMFCOutlookBarPane[29], CMFCOutlookBarToolBar[29], CMFCTasksPaneToolBar[29], CMFCToolBar[29] */
/* 00802ae4  FUN_00802ae4  870 bytes, 3 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00802ae4(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  undefined1 local_224 [4];
  int *local_220;
  int *local_21c;
  int local_218;
  wchar_t local_214 [262];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x220;
  local_8 = 0x802af3;
  if ((DAT_00a005ec == 0) || (local_21c = in_ECX, iVar3 = FUN_00793db2(param_1), iVar3 != -1))
  goto LAB_00802c48;
  pcVar1 = *(code **)(*in_ECX + 0x390);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if ((iVar3 == -1) || ((iVar3 = FUN_007fde79(), iVar3 == 0 || (param_3 == 0)))) goto LAB_00802c48;
  CStringT<>();
  local_8 = 0;
  pcVar1 = *(code **)(*local_21c + 0x3ac);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if (iVar4 == 0) {
    uVar2 = *(uint *)(iVar3 + 0x20);
    if ((((uVar2 == 0) || (uVar2 == 0xffffffff)) || (*(int *)(iVar3 + 4) != 0)) &&
       (*(int *)(*(int *)(iVar3 + 0x2c) + -0xc) != 0)) {
      ATL::CSimpleStringT<wchar_t,0>::operator=
                ((CSimpleStringT<wchar_t,0> *)&local_218,(CSimpleStringT<wchar_t,0> *)(iVar3 + 0x2c)
                );
      FUN_007fa476();
    }
    else if (((DAT_00a13bac == 0) || (uVar2 < *(uint *)(DAT_00a13bac + 0x24))) ||
            (*(uint *)(DAT_00a13bac + 0x28) < uVar2)) {
      FUN_0078f2e1(uVar2);
      AfxExtractSubString((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                          &local_218,local_214,1,L'\n');
    }
    else {
      ATL::CSimpleStringT<wchar_t,0>::operator=
                ((CSimpleStringT<wchar_t,0> *)&local_218,(CSimpleStringT<wchar_t,0> *)(iVar3 + 0x2c)
                );
    }
  }
  if (*(int *)(local_218 + -0xc) == 0) {
    FUN_00406b10();
    goto LAB_00802c48;
  }
  if (((*(int *)(iVar3 + 0x20) != 0) && (*(int *)(iVar3 + 0x20) != -1)) && (DAT_00a005f0 != 0)) {
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar4 = FUN_007e5618();
    if (iVar4 != 0) {
      FUN_007e5618();
      local_220 = DAT_00a13a1c;
      piVar5 = DAT_00a13a1c;
      if ((DAT_00a13a1c != (int *)0x0) ||
         (piVar5 = (int *)FUN_00792b4c(), local_220 = piVar5, piVar5 != (int *)0x0)) {
        local_220 = piVar5;
        iVar4 = FUN_0082b064(*(undefined4 *)(iVar3 + 0x20),local_224);
        if (iVar4 == 0) {
          pcVar1 = *(code **)(*piVar5 + 0x170);
          guard_check_icall();
          (*pcVar1)();
          iVar4 = FUN_0082b064(*(undefined4 *)(iVar3 + 0x20),local_224);
          if (iVar4 == 0) goto LAB_00802d3e;
        }
        FUN_008f899d();
        FUN_00404cf0();
        FUN_00404cf0();
        ATL::CSimpleStringT<wchar_t,0>::AppendChar((CSimpleStringT<wchar_t,0> *)&local_218,L')');
      }
    }
LAB_00802d3e:
    FUN_00406b10();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,2);
  local_220 = (int *)FUN_0079296c();
  if ((local_220 != (int *)0x0) && (local_220[8] != 0)) {
    pcVar1 = *(code **)(*local_220 + 0x174);
    guard_check_icall();
    (*pcVar1)();
  }
  local_220 = (int *)&stack0xfffffdb8;
  iVar4 = local_21c[0x342];
  FUN_004054a0(local_218 + -0x10);
  FUN_008197cb(param_3,iVar4,2);
  pcVar1 = *(code **)(*local_21c + 0x36c);
  guard_check_icall();
  (*pcVar1)();
  *(uint *)(param_3 + 0xc) = -(uint)(*(int *)(iVar3 + 0x20) != -1) & *(uint *)(iVar3 + 0x20);
  *(int *)(param_3 + 8) = local_21c[8];
  FUN_00406b10();
  FUN_00406b10();
LAB_00802c48:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCDropDownToolBar[235], CMFCImageEditorPaletteBar[235], CMFCMenuBar[235], CMFCOutlookBarPane[235], CMFCPrintPreviewToolBar[235], CMFCToolBar[235] */
/* 00803542  FUN_00803542  199 bytes, 1 callers */

undefined4 FUN_00803542(undefined4 param_1,undefined4 param_2)

{
  CObject *pCVar1;
  CObject *pCVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  pCVar1 = (CObject *)FUN_007e5618();
  if (pCVar1 == (CObject *)0x0) {
LAB_00803601:
    uVar3 = 0;
  }
  else {
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCDropDownFrame_00a00b60,pCVar1);
    if (pCVar2 != (CObject *)0x0) {
      pCVar1 = (CObject *)FUN_007e5618(pCVar2);
      if (pCVar1 == (CObject *)0x0) goto LAB_00803601;
    }
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar1);
    if (pCVar2 == (CObject *)0x0) {
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWndEx_00994040,pCVar1);
      if (pCVar2 == (CObject *)0x0) {
        pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIChildWndEx_00995510,pCVar1);
        if (pCVar1 == (CObject *)0x0) {
          pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleIPFrameWndEx_00994be0,
                                      (CObject *)0x0);
          if (pCVar1 == (CObject *)0x0) goto LAB_00803601;
          pcVar4 = *(code **)(*(int *)pCVar1 + 0x200);
        }
        else {
          pcVar4 = *(code **)(*(int *)pCVar1 + 0x1d4);
        }
      }
      else {
        pcVar4 = *(code **)(*(int *)pCVar2 + 0x1e4);
      }
    }
    else {
      pcVar4 = *(code **)(*(int *)pCVar2 + 0x1f8);
    }
    guard_check_icall(param_1,param_2);
    uVar3 = (*pcVar4)();
  }
  return uVar3;
}




/* vtable slots: CMFCDropDownToolBar[67], CMFCImageEditorPaletteBar[67], CMFCOutlookBarToolBar[67], CMFCPopupMenuBar[67], CMFCPrintPreviewToolBar[67], CMFCTasksPaneToolBar[67], CMFCToolBar[67] */
/* 008036ce  FUN_008036ce  262 bytes, 4 callers */

undefined4 FUN_008036ce(int param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((uVar1 == 0x100) && (*(int *)(param_1 + 8) == 0x1b)) {
    if (in_ECX[0x2e9] == 0) {
      iVar3 = FUN_007fdf83(0);
      if (iVar3 != 0) goto LAB_008037c6;
      pcVar2 = *(code **)(*in_ECX + 0x360);
      guard_check_icall();
      (*pcVar2)();
      pcVar2 = *(code **)(*in_ECX + 0x364);
      guard_check_icall();
      (*pcVar2)();
    }
    else {
      FUN_007ff7d7();
    }
    return 1;
  }
  if (uVar1 == DAT_00a127e4) {
    FUN_0080255b(0,0);
    return 1;
  }
  if (uVar1 < 0x105) {
    if (((uVar1 != 0x104) && (uVar1 != 0xa1)) &&
       ((uVar1 != 0xa2 &&
        ((((uVar1 != 0xa4 && (uVar1 != 0xa5)) && (uVar1 != 0xa7)) &&
         ((uVar1 != 0xa8 && (uVar1 != 0x100)))))))) goto LAB_008037c6;
  }
  else if ((((uVar1 != 0x200) && (uVar1 != 0x201)) && (uVar1 != 0x202)) &&
          (((uVar1 != 0x204 && (uVar1 != 0x205)) && ((uVar1 != 0x207 && (uVar1 != 0x208))))))
  goto LAB_008037c6;
  iVar3 = in_ECX[0x342];
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != 0)) {
    SendMessageW(*(HWND *)(iVar3 + 0x20),0x407,0,param_1);
  }
LAB_008037c6:
  uVar4 = FUN_007ee372(param_1);
  return uVar4;
}




/* vtable slots: CMFCDropDownToolBar[2], CMFCImageEditorPaletteBar[2], CMFCMenuBar[2], CMFCOutlookBarPane[2], CMFCOutlookBarToolBar[2], CMFCPopupMenuBar[2], CMFCPrintPreviewToolBar[2], CMFCRibbonPanelMenuBar[2], CMFCTasksPaneToolBar[2], CMFCToolBar[2] */
/* 0080450a  FUN_0080450a  756 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0080450a(CArchive *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 *puVar5;
  int *in_ECX;
  CArchive *pCVar6;
  CObList local_44 [32];
  int *local_24;
  CObject *local_20;
  undefined4 *local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x804516;
  FUN_007ee62d(param_1);
  if (in_ECX[0x2de] == 0) {
    CStringT<>();
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    if (((byte)param_1[0x18] & 1) == 0) {
      CObList::CObList(local_44,10);
      local_1c = (undefined4 *)in_ECX[0x310];
      local_8._0_1_ = 2;
      while (local_1c != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)FUN_0044f2d0(&local_1c);
        local_20 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,
                                      (CObject *)*puVar5);
        if (local_20 != (CObject *)0x0) {
          pcVar1 = *(code **)(*(int *)local_20 + 0x50);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          if (iVar3 != 0) {
            CObList::AddTail(local_44,local_20);
          }
        }
      }
      CObList::Serialize(local_44,param_1);
      CArchive::operator<<(param_1,in_ECX[0x2e2]);
      BVar4 = IsWindow((HWND)in_ECX[8]);
      if (BVar4 != 0) {
        FUN_00792c64(local_18);
      }
      CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                         local_18);
      CArchive::operator<<(param_1,in_ECX[0x4f]);
      FUN_007a184a();
    }
    else {
      local_1c = (undefined4 *)in_ECX[0x345];
      local_20 = (CObject *)0x0;
      if (local_1c != (undefined4 *)0x0) {
        pcVar1 = *(code **)*local_1c;
        guard_check_icall();
        (*pcVar1)();
        pCVar2 = (CObject *)FUN_0079d90c();
        local_20 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,pCVar2);
        pcVar1 = *(code **)(*(int *)local_20 + 0x14);
        guard_check_icall(in_ECX[0x345]);
        (*pcVar1)();
      }
      pcVar1 = *(code **)(*in_ECX + 0x350);
      guard_check_icall();
      (*pcVar1)();
      pcVar1 = *(code **)(in_ECX[0x30f] + 8);
      pCVar6 = param_1;
      guard_check_icall(param_1);
      (*pcVar1)();
      local_1c = (undefined4 *)in_ECX[0x310];
      while (local_1c != (undefined4 *)0x0) {
        local_24 = (int *)FUN_0044f2d0(&local_1c);
        local_24 = (int *)*local_24;
        if (local_24 == (int *)0x0) {
          RemoveAll();
          pcVar1 = *(code **)(*in_ECX + 900);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          if (iVar3 != 0) {
            pcVar1 = *(code **)(*in_ECX + 0x388);
            guard_check_icall();
            (*pcVar1)();
          }
          pcVar1 = *(code **)(*in_ECX + 0x3e4);
          guard_check_icall();
          (*pcVar1)();
          goto LAB_00804638;
        }
        local_24[9] = local_24[9] & 0xfffcffff;
        pcVar1 = *(code **)(*local_24 + 0x28);
        guard_check_icall();
        (*pcVar1)();
      }
      CArchive::operator>>(param_1,(long *)&local_24);
      pcVar1 = *(code **)(*in_ECX + 0x378);
      guard_check_icall(pCVar6);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        in_ECX[0x2e2] = (int)local_24;
      }
      if (local_20 != (CObject *)0x0) {
        pcVar1 = *(code **)(*in_ECX + 0x340);
        guard_check_icall(local_20,0xffffffff);
        (*pcVar1)();
        in_ECX[0x345] = (int)local_20;
      }
      pcVar1 = *(code **)(*in_ECX + 0x3e4);
      guard_check_icall();
      (*pcVar1)();
      FUN_0047fc90(local_18);
      BVar4 = IsWindow((HWND)in_ECX[8]);
      pCVar2 = DAT_00a00644;
      if (BVar4 != 0) {
        FUN_00797ece(local_18[0]);
        pCVar2 = DAT_00a00644;
      }
      while (pCVar2 != (CObject *)0x0) {
        local_20 = *(CObject **)pCVar2;
        iVar3 = FUN_007fc6bf(*(int *)(pCVar2 + 8),0);
        pCVar2 = local_20;
        if (-1 < iVar3) {
          pcVar1 = *(code **)(*in_ECX + 0x34c);
          guard_check_icall(iVar3);
          (*pcVar1)();
          pCVar2 = local_20;
        }
      }
      CArchive::operator>>(param_1,in_ECX + 0x4f);
    }
LAB_00804638:
    FUN_00406b10();
  }
  return;
}




/* vtable slots: CMFCDropDownToolBar[221], CMFCImageEditorPaletteBar[221], CMFCMenuBar[221], CMFCOutlookBarPane[221], CMFCOutlookBarToolBar[221], CMFCPrintPreviewToolBar[221], CMFCTasksPaneToolBar[221], CMFCToolBar[221] */
/* 00804812  FUN_00804812  105 bytes, 0 callers */

void FUN_00804812(undefined4 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  int *piVar3;
  
  piVar3 = (int *)FUN_007fde79(param_1);
  if ((piVar3 != (int *)0x0) && (uVar1 = piVar3[9], uVar1 != param_2)) {
    if ((param_2 & 0x40000) != 0) {
      param_2 = param_2 & 0xfffdffff;
    }
    pcVar2 = *(code **)(*piVar3 + 0x8c);
    guard_check_icall(param_2);
    (*pcVar2)();
    if ((uVar1 & param_2 & 0x20000) == 0) {
      FUN_007fe655(param_1);
    }
  }
  return;
}




/* vtable slots: CMFCDropDownToolBar[262], CMFCImageEditorPaletteBar[262], CMFCMenuBar[262], CMFCOutlookBarPane[262], CMFCOutlookBarToolBar[262], CMFCPrintPreviewToolBar[262], CMFCTasksPaneToolBar[262], CMFCToolBar[262] */
/* 00805b1f  FUN_00805b1f  106 bytes, 1 callers */

void FUN_00805b1f(uint param_1)

{
  CWnd *pCVar1;
  CWnd *in_ECX;
  
  if (DAT_00a127a4 == 0) {
    if ((param_1 == 0xffffffff) || (param_1 == 0xffffffec)) {
      pCVar1 = CWnd::GetOwner(in_ECX);
      param_1 = 0xe001;
    }
    else {
      if (param_1 - 0xf000 < 0x1f0) {
        param_1 = (param_1 - 0xf000 >> 4) + 0xef00;
      }
      else if (0xfeff < param_1) {
        param_1 = 0xef1f;
      }
      pCVar1 = CWnd::GetOwner(in_ECX);
    }
    SendMessageW(*(HWND *)(pCVar1 + 0x20),0x362,param_1,0);
  }
  return;
}




/* vtable slots: CMFCDropDownToolBar[229], CMFCImageEditorPaletteBar[229], CMFCMenuBar[229], CMFCOutlookBarPane[229], CMFCOutlookBarToolBar[229], CMFCPrintPreviewToolBar[229], CMFCTasksPaneToolBar[229], CMFCToolBar[229] */
/* 008063a0  FUN_008063a0  234 bytes, 0 callers */

undefined4 FUN_008063a0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  ANIMATION_TYPE AVar3;
  CObject *pCVar4;
  undefined4 uVar5;
  undefined4 local_10;
  undefined4 local_c;
  CObject *local_8;
  
  iVar2 = FUN_0082b24e(param_1);
  if (iVar2 != 0) {
    local_10 = FUN_0082b498(param_1);
    local_8 = (CObject *)0x0;
    iVar2 = Lookup(&local_10,&local_8);
    if (iVar2 != 0) {
      AVar3 = CMFCPopupMenu::GetAnimationType(0);
      DAT_00a139d8 = 0;
      if ((local_8 != (CObject *)0x0) &&
         (pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,local_8
                                     ), pCVar4 != (CObject *)0x0)) {
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x20);
        guard_check_icall(local_c,1);
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) {
          pcVar1 = *(code **)(*(int *)pCVar4 + 0x70);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if (iVar2 != 0) {
            SendMessageW(*(HWND *)(*(int *)(pCVar4 + 0x8c) + 0x20),0x100,0x24,0);
          }
          FUN_00804f82(pCVar4);
          DAT_00a139d8 = AVar3;
          return 1;
        }
      }
      DAT_00a139d8 = AVar3;
      uVar5 = FUN_008038ff(local_8);
      return uVar5;
    }
  }
  return 0;
}




/* vtable slots: CMFCDropDownToolBar[1] */
/* 0088a1bc  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCDropDownToolBar::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCDropDownToolBar::_scalar_deleting_destructor_(CMFCDropDownToolBar *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_007faf4a();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xd40);
    }
  }
  return this;
}




/* vtable slots: CMFCDropDownToolBar[10] */
/* 0088a662  FUN_0088a662  6 bytes, 0 callers */

undefined ** FUN_0088a662(void)

{
  return &PTR_FUN_0099bb78;
}




/* vtable slots: CMFCDropDownToolBar[0] */
/* 0088a66e  FUN_0088a66e  6 bytes, 0 callers */

undefined ** FUN_0088a66e(void)

{
  return &PTR_s_CMFCDropDownToolBar_00a00b44;
}




/* vtable slots: CMFCDropDownToolBar[203] */
/* 0088a68b  FUN_0088a68b  29 bytes, 0 callers */

void FUN_0088a68b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007feb6d(param_1,param_2,param_3,1,param_5,param_6);
  return;
}




/* vtable slots: CMFCDropDownToolBar[204] */
/* 0088a6a8  LoadToolBar  32 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCDropDownToolBar::LoadToolBar(unsigned int,unsigned
   int,unsigned int,int,unsigned int,unsigned int,unsigned int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
CMFCDropDownToolBar::LoadToolBar
          (CMFCDropDownToolBar *this,uint param_1,uint param_2,uint param_3,int param_4,uint param_5
          ,uint param_6,uint param_7)

{
  int iVar1;
  
  iVar1 = FUN_007ff127(param_1,param_2,param_3,1,param_5,param_6,param_7);
  return iVar1;
}




/* vtable slots: CMFCDropDownToolBar[250] */
/* 0088b592  FUN_0088b592  127 bytes, 0 callers */

undefined4 FUN_0088b592(int param_1)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  int *piVar4;
  undefined4 uVar5;
  CWnd *in_ECX;
  
  if ((((*(uint *)(param_1 + 0x24) & 0x40000) == 0) && (*(int *)(param_1 + 0x20) != 0)) &&
     (*(int *)(param_1 + 0x20) != -1)) {
    pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    CMFCDropDownToolbarButton::SetDefaultCommand
              (*(CMFCDropDownToolbarButton **)(pCVar3 + 0x134),*(uint *)(param_1 + 0x20));
    piVar4 = (int *)FUN_0079296c();
    pCVar3 = CWnd::GetOwner(in_ECX);
    PostMessageW(*(HWND *)(pCVar3 + 0x20),0x111,*(WPARAM *)(param_1 + 0x20),0);
    pcVar1 = *(code **)(*piVar4 + 0x60);
    guard_check_icall();
    (*pcVar1)();
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}




/* vtable slots: CMFCDropDownToolBar[145] */
/* 0088b668  FUN_0088b668  44 bytes, 0 callers */

void FUN_0088b668(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x3c4);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  FUN_0080345e(uVar2,param_2);
  return;
}



