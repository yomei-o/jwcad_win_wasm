/* CDockingPanesRow -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDockingPanesRow[1] */
/* 00855ffb  FUN_00855ffb  48 bytes, 0 callers */

void FUN_00855ffb(byte param_1)

{
  FUN_00855fed();
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




/* vtable slots: CDockingPanesRow[7] */
/* 0085602b  FUN_0085602b  408 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0085602b(int *param_1,undefined4 param_2,RECT *param_3,int param_4)

{
  code *pcVar1;
  int *piVar2;
  BOOL BVar3;
  int iVar4;
  CDockingPanesRow *in_ECX;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_48;
  undefined4 local_44;
  int *local_40;
  int local_3c;
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_40 = param_1;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  if ((param_3 == (RECT *)0x0) || (BVar3 = IsRectEmpty(param_3), BVar3 != 0)) {
    iVar7 = 0;
    if ((param_4 != 0) && (iVar7 = CDockingPanesRow::CalcLastPaneOffset(in_ECX), 0 < iVar7)) {
      iVar4 = FUN_007c2511();
      iVar7 = iVar7 + *(int *)(iVar4 + 0x1b8);
    }
    CDockingPanesRow::GetClientRect(in_ECX,(CRect *)&local_18);
    uVar5 = *(uint *)(in_ECX + 0x40);
    iVar4 = *(int *)(in_ECX + 0x18);
    if ((uVar5 & 0xa000) == 0) {
      iVar6 = local_18.top + iVar7;
      local_3c = iVar4;
      if (*(int *)(in_ECX + 0x20) == 1) {
        local_3c = *(int *)(in_ECX + 0x1c) + iVar4;
      }
    }
    else {
      iVar6 = iVar4;
      local_3c = local_18.left + iVar7;
      if (*(int *)(in_ECX + 0x20) == 1) {
        iVar6 = *(int *)(in_ECX + 0x1c) + iVar4;
      }
    }
  }
  else {
    CopyRect(&local_38,param_3);
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    GetClientRect(*(HWND *)(*(int *)(in_ECX + 0x44) + 0x20),&local_28);
    CDockingPanesRow::GetWindowRect(in_ECX,(CRect *)&local_18);
    CWnd::ScreenToClient(*(CWnd **)(in_ECX + 0x44),&local_38);
    CWnd::ScreenToClient(*(CWnd **)(in_ECX + 0x44),&local_18);
    uVar5 = *(uint *)(in_ECX + 0x40);
    if ((uVar5 & 0xa000) == 0) {
      local_3c = local_28.left + *(int *)(in_ECX + 0x18);
      iVar6 = local_38.top - local_18.top;
    }
    else {
      iVar6 = local_28.top + *(int *)(in_ECX + 0x18);
      local_3c = local_38.left - local_18.left;
    }
  }
  pcVar1 = *(code **)(*local_40 + 0x260);
  guard_check_icall(&local_48,0,(uVar5 & 0xa000) != 0);
  (*pcVar1)();
  pcVar1 = *(code **)(*local_40 + 0x238);
  guard_check_icall(0,local_3c,iVar6,local_48,local_44,0x34,0);
  piVar2 = local_40;
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)in_ECX + 100);
  guard_check_icall(piVar2);
  (*pcVar1)();
  FUN_007f2322();
  return;
}




/* vtable slots: CDockingPanesRow[8] */
/* 008561c3  FUN_008561c3  383 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008561c3(int *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int xRight;
  int *in_ECX;
  int iVar3;
  LONG yTop;
  tagPOINT local_44;
  uint local_3c;
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect((HWND)param_1[8],&local_18);
  if (param_2 == 1) {
    local_44.x = 0;
    local_44.y = 0;
    GetCursorPos(&local_44);
    ScreenToClient(*(HWND *)(in_ECX[0x11] + 0x20),&local_44);
    iVar3 = param_1[0x5a];
    iVar2 = param_1[0x5b];
    local_38.left = 0;
    local_38.top = 0;
    local_38.right = 0;
    local_38.bottom = 0;
    GetClientRect((HWND)param_1[8],&local_38);
    FUN_0079e8b8(&local_38);
    local_3c = in_ECX[0x10];
    if ((local_3c & 0xa000) == 0) {
      iVar3 = local_44.y - iVar2;
    }
    else {
      iVar3 = local_44.x - iVar3;
    }
    yTop = iVar3 - (local_38.left - local_18.left);
  }
  else {
    CWnd::ScreenToClient((CWnd *)in_ECX[0x11],&local_18);
    local_3c = in_ECX[0x10];
    yTop = local_18.left;
    if ((local_3c & 0xa000) == 0) {
      yTop = local_18.top;
    }
  }
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  if ((local_3c & 0xa000) == 0) {
    iVar2 = (local_18.bottom - local_18.top) + yTop;
    xRight = (in_ECX[6] - local_18.left) + local_18.right;
    iVar3 = in_ECX[6];
  }
  else {
    iVar2 = (in_ECX[6] - local_18.top) + local_18.bottom;
    xRight = (local_18.right - local_18.left) + yTop;
    iVar3 = yTop;
    yTop = in_ECX[6];
  }
  SetRect(&local_28,iVar3,yTop,xRight,iVar2);
  pcVar1 = *(code **)(*param_1 + 0x238);
  guard_check_icall(0,local_28.left,local_28.top,local_28.right,local_28.bottom,0x15,0);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 100);
  guard_check_icall(param_1);
  (*pcVar1)();
  FUN_007f2322();
  return;
}




/* vtable slots: CDockingPanesRow[11] */
/* 008563f7  FUN_008563f7  557 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CDockingPanesRow * FUN_008563f7(int param_1,int param_2)

{
  code *pcVar1;
  CDockingPanesRow *pCVar2;
  int *piVar3;
  int iVar4;
  CDockingPanesRow *in_ECX;
  int iVar5;
  undefined1 local_50 [8];
  CDockingPanesRow *local_48;
  int local_44;
  int local_40;
  int local_3c;
  CDockingPanesRow *local_38;
  int local_34;
  int *local_30;
  char local_29;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_28 = 0;
  iVar5 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_34 = 0;
  local_38 = in_ECX;
  CDockingPanesRow::GetWindowRect(in_ECX,(CRect *)&local_28);
  local_29 = '\x01';
  piVar3 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar3 + 0x1ac);
  guard_check_icall();
  local_3c = (*pcVar1)();
  local_44 = *(int *)(local_38 + 0x28);
  local_48 = local_38;
  if (local_44 != 0) {
    local_48 = local_38 + 0x24;
    do {
      piVar3 = (int *)FUN_0044f2d0(&local_44);
      piVar3 = (int *)*piVar3;
      pcVar1 = *(code **)(*piVar3 + 0x17c);
      local_30 = piVar3;
      guard_check_icall();
      iVar4 = (*pcVar1)();
      pCVar2 = local_38;
      if ((iVar4 != 0) || (*(int *)(local_38 + 4) != 0)) {
        GetWindowRect((HWND)piVar3[8],&local_18);
        if (local_29 != '\0') {
          if ((*(uint *)(pCVar2 + 0x40) & 0xa000) == 0) {
            local_34 = local_24 + param_1;
          }
          else {
            iVar5 = local_28 + param_1;
          }
        }
        if ((local_30[0x45] == 0) && (local_29 == '\0')) {
          if ((*(uint *)(pCVar2 + 0x40) & 0xa000) == 0) {
            local_34 = local_34 - (DAT_00a00a30 + param_2);
            if (local_3c != 0) {
              local_34 = local_34 - (local_18.right - local_18.left) / 2;
            }
          }
          else {
            iVar5 = iVar5 - (DAT_00a00a30 + param_2);
            if (local_3c != 0) {
              iVar5 = iVar5 - (local_18.bottom - local_18.top) / 2;
            }
          }
        }
        iVar4 = local_34;
        local_29 = '\0';
        if ((*(uint *)(pCVar2 + 0x40) & 0xa000) == 0) {
          local_40 = local_18.bottom - local_18.top;
          local_18.bottom = local_40 + local_34;
          local_18.top = local_34;
        }
        else {
          local_40 = local_18.right - local_18.left;
          local_18.right = iVar5 + local_40;
          local_18.left = iVar5;
        }
        CWnd::ScreenToClient(*(CWnd **)(pCVar2 + 0x44),&local_18);
        pcVar1 = *(code **)(*local_30 + 0x238);
        guard_check_icall(0,local_18.left,local_18.top,local_18.right - local_18.left,
                          local_18.bottom - local_18.top,0x14,0);
        (*pcVar1)();
        pcVar1 = *(code **)(*local_30 + 0x208);
        guard_check_icall(local_50,local_40,(*(uint *)(local_38 + 0x40) & 0xa000) == 0);
        (*pcVar1)();
        GetWindowRect((HWND)local_30[8],&local_18);
        if ((*(uint *)(local_38 + 0x40) & 0xa000) == 0) {
          local_34 = iVar4 + (local_18.bottom - local_18.top) + param_2;
        }
        else {
          iVar5 = iVar5 + (local_18.right - local_18.left) + param_2;
        }
      }
    } while (local_44 != 0);
  }
  return local_48;
}




/* vtable slots: CDockingPanesRow[10] */
/* 00856624  FUN_00856624  620 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CDockingPanesRow * FUN_00856624(int *param_1)

{
  code *pcVar1;
  CDockingPanesRow *pCVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  CDockingPanesRow *in_ECX;
  int iVar6;
  CDockingPanesRow *_X;
  CDockingPanesRow *local_34;
  undefined4 local_30;
  int *local_2c;
  RECT local_28;
  tagRECT local_18;
  CDockingPanesRow *local_8;
  
  pCVar2 = (CDockingPanesRow *)(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  if (*(int *)(in_ECX + 0x30) != 0) {
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    local_8 = pCVar2;
    CDockingPanesRow::GetClientRect(in_ECX,(CRect *)&local_28);
    pCVar2 = (CDockingPanesRow *)IsRectEmpty(&local_28);
    if (pCVar2 == (CDockingPanesRow *)0x0) {
      local_30 = 0;
      pcVar1 = *(code **)(*(int *)in_ECX + 0x5c);
      guard_check_icall(0);
      local_34 = (CDockingPanesRow *)(*pcVar1)();
      if (*(int *)(in_ECX + 0x30) == 1) {
        if (param_1 == (int *)0x0) {
          param_1 = *(int **)(*(int *)(in_ECX + 0x28) + 8);
        }
        if ((int)local_34 < 0) {
          pcVar1 = *(code **)(*param_1 + 0x2ac);
          guard_check_icall(local_34,&local_30);
          (*pcVar1)();
          local_18.left = 0;
          local_18.top = 0;
          local_18.right = 0;
          local_18.bottom = 0;
          GetWindowRect((HWND)param_1[8],&local_18);
          CWnd::ScreenToClient(*(CWnd **)(in_ECX + 0x44),&local_18);
          if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
            iVar6 = -local_18.top;
            iVar3 = *(int *)(in_ECX + 0x18) - local_18.left;
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x18) - local_18.top;
            iVar3 = -local_18.left;
          }
          OffsetRect(&local_18,iVar3,iVar6);
          pcVar1 = *(code **)(*param_1 + 0x238);
          guard_check_icall(0,local_18.left,local_18.top,local_18.right - local_18.left,
                            local_18.bottom - local_18.top,0x14,0);
          pCVar2 = (CDockingPanesRow *)(*pcVar1)();
          return pCVar2;
        }
      }
      if (param_1 == (int *)0x0) {
        param_1 = *(int **)(*(int *)(in_ECX + 0x28) + 8);
      }
      else {
        FUN_0085895d(param_1,0,&local_30);
      }
      FUN_0085895d(param_1,1,&local_30);
      uVar4 = FUN_0085725d(1);
      iVar3 = FUN_008577c9(uVar4,1);
      if (0 < iVar3) {
        FUN_00858ce6(uVar4,iVar3,1);
      }
      local_2c = (int *)FUN_0085725d(0);
      pCVar2 = (CDockingPanesRow *)FUN_008577c9(local_2c,0);
      _X = local_34;
      if (0 < (int)pCVar2) {
        uVar4 = 0;
        if ((int)local_34 < 1) {
          iVar3 = _abs((int)local_34);
          pCVar2 = (CDockingPanesRow *)FUN_00858ce6(local_2c,iVar3 - (int)pCVar2,uVar4);
          if ((int)_X < 0) {
            local_34 = *(CDockingPanesRow **)(in_ECX + 0x2c);
            pCVar2 = (CDockingPanesRow *)0x0;
            while (local_34 != (CDockingPanesRow *)0x0) {
              puVar5 = (undefined4 *)FUN_0049ad10(&local_34);
              local_2c = (int *)*puVar5;
              pcVar1 = *(code **)(*local_2c + 0x17c);
              guard_check_icall();
              iVar3 = (*pcVar1)();
              if ((iVar3 != 0) || (*(int *)(in_ECX + 4) != 0)) {
                pcVar1 = *(code **)(*local_2c + 0x2ac);
                guard_check_icall(_X,&local_30);
                pCVar2 = (CDockingPanesRow *)(*pcVar1)();
                puVar5 = &local_30;
                uVar4 = 0;
                iVar3 = _abs((int)pCVar2);
                iVar6 = _abs((int)_X);
                FUN_00857c8a(local_2c,iVar6 - iVar3,uVar4,puVar5);
                if (pCVar2 == _X) {
                  return pCVar2;
                }
                _X = _X + -(int)pCVar2;
              }
              pCVar2 = in_ECX + 0x24;
            }
          }
        }
        else {
          pCVar2 = (CDockingPanesRow *)FUN_00858ce6(local_2c,-(int)pCVar2,0);
        }
      }
    }
  }
  return pCVar2;
}




/* vtable slots: CDockingPanesRow[6] */
/* 00856a9f  FUN_00856a9f  276 bytes, 0 callers */

void FUN_00856a9f(int *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  CObject *local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 8) == 0) {
    if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
      *param_1 = 0;
      param_1[1] = 0x7fff;
    }
    else {
      *param_1 = 0x7fff;
      param_1[1] = 0;
    }
  }
  else {
    local_14 = *(int *)(in_ECX + 0x28);
    local_10 = *(uint *)(in_ECX + 0x40) & 0xa000;
    iVar4 = 0;
    iVar5 = 0;
    local_8 = in_ECX;
    while (local_14 != 0) {
      puVar2 = (undefined4 *)FUN_0044f2d0(&local_14);
      local_c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)*puVar2);
      pcVar1 = *(code **)(*(int *)local_c + 0x17c);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if ((iVar3 != 0) || (*(int *)(local_8 + 4) != 0)) {
        pcVar1 = *(code **)(*(int *)local_c + 0x260);
        guard_check_icall(&local_1c,param_2,param_3);
        (*pcVar1)();
        if (local_10 == 0) {
          if (iVar4 <= local_1c) {
            iVar4 = local_1c;
          }
          iVar5 = iVar5 + local_18;
        }
        else {
          iVar4 = iVar4 + local_1c;
          if (iVar5 <= local_18) {
            iVar5 = local_18;
          }
        }
      }
    }
    if (local_10 == 0) {
      if (0 < iVar4) {
        iVar4 = iVar4 + *(int *)(local_8 + 0x1c);
      }
    }
    else if (0 < iVar5) {
      iVar5 = iVar5 + *(int *)(local_8 + 0x1c);
    }
    param_1[1] = iVar5;
    *param_1 = iVar4;
  }
  return;
}




/* vtable slots: CDockingPanesRow[23] */
/* 008573ce  FUN_008573ce  229 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008573ce(int param_1)

{
  code *pcVar1;
  int iVar2;
  CDockingPanesRow *in_ECX;
  int iVar3;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar3 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  CDockingPanesRow::GetClientRect(in_ECX,(CRect *)&local_28);
  local_30 = *(int *)(in_ECX + 0x28);
  while (local_30 != 0) {
    local_2c = (int *)FUN_0049acb0(&local_30);
    pcVar1 = *(code **)(*local_2c + 0x17c);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((iVar2 != 0) || (*(int *)(in_ECX + 4) != 0)) {
      local_18.left = 0;
      local_18.top = local_18.left;
      local_18.right = local_18.left;
      local_18.bottom = local_18.left;
      if (param_1 == 0) {
        GetWindowRect((HWND)local_2c[8],&local_18);
      }
      else {
        FUN_007f028e(&local_18);
      }
      if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
        iVar2 = local_18.bottom - local_18.top;
      }
      else {
        iVar2 = local_18.right - local_18.left;
      }
      iVar3 = iVar3 + iVar2;
    }
  }
  if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
    local_20 = local_1c - local_24;
  }
  else {
    local_20 = local_20 - local_28;
  }
  return local_20 - iVar3;
}




/* vtable slots: CDockingPanesRow[4] */
/* 0085757d  FUN_0085757d  179 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CDockingPanesRow * FUN_0085757d(LPRECT param_1)

{
  CDockingPanesRow *pCVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  CDockingPanesRow *in_ECX;
  int dy;
  int local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  CDockingPanesRow::GetWindowRect(in_ECX,(CRect *)param_1);
  local_20 = *(int *)(in_ECX + 0x28);
  pCVar1 = (CDockingPanesRow *)0x0;
  while (local_20 != 0) {
    puVar3 = (undefined4 *)FUN_0044f2d0(&local_20);
    local_1c = (int *)*puVar3;
    pcVar2 = *(code **)(*local_1c + 0x17c);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if ((iVar4 != 0) || (*(int *)(in_ECX + 4) != 0)) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect((HWND)local_1c[8],&local_18);
      if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
        dy = local_18.top - local_18.bottom;
        iVar4 = 0;
      }
      else {
        iVar4 = local_18.left - local_18.right;
        dy = 0;
      }
      InflateRect(param_1,iVar4,dy);
    }
    pCVar1 = in_ECX + 0x24;
  }
  return pCVar1;
}




/* vtable slots: CDockingPanesRow[0] */
/* 008578fd  FUN_008578fd  6 bytes, 0 callers */

undefined ** FUN_008578fd(void)

{
  return &PTR_s_CDockingPanesRow_00996388;
}




/* vtable slots: CDockingPanesRow[5] */
/* 00857903  FUN_00857903  89 bytes, 0 callers */

int FUN_00857903(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int local_8;
  
  iVar4 = 0;
  local_8 = *(int *)(in_ECX + 0x28);
joined_r0x00857916:
  if (local_8 == 0) {
    return iVar4;
  }
  puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
  if (*(int *)(in_ECX + 4) == 0) goto code_r0x00857932;
  goto LAB_0085794b;
code_r0x00857932:
  pcVar1 = *(code **)(*(int *)*puVar2 + 0x17c);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
LAB_0085794b:
    iVar4 = iVar4 + 1;
  }
  goto joined_r0x00857916;
}




/* vtable slots: CDockingPanesRow[16] */
/* 008579a8  FUN_008579a8  9 bytes, 0 callers */

bool FUN_008579a8(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x30) == 0;
}




/* vtable slots: CDockingPanesRow[24] */
/* 00857b28  FUN_00857b28  75 bytes, 0 callers */

undefined4 FUN_00857b28(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x28);
  do {
    if (local_8 == 0) {
      return 0;
    }
    piVar2 = (int *)FUN_0049acb0(&local_8);
    pcVar1 = *(code **)(*piVar2 + 0x280);
    guard_check_icall();
    iVar3 = (*pcVar1)();
  } while (iVar3 != 0);
  return 1;
}




/* vtable slots: CDockingPanesRow[14] */
/* 00857b73  FUN_00857b73  79 bytes, 0 callers */

void FUN_00857b73(int param_1)

{
  undefined4 *puVar1;
  CObject *pCVar2;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x28);
  while (local_8 != 0) {
    puVar1 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)*puVar1);
    if (pCVar2 != (CObject *)0x0) {
      FUN_007f0887(*(undefined4 *)(in_ECX + 0x40),param_1);
    }
  }
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + param_1;
  return;
}




/* vtable slots: CDockingPanesRow[25] */
/* 008581a1  FUN_008581a1  267 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008581a1(CObject *param_1)

{
  code *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  int *in_ECX;
  int iVar4;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(*(HWND *)(param_1 + 0x20),&local_18);
  local_1c = in_ECX[10];
  do {
    iVar4 = local_1c;
    local_1c = iVar4;
    if (iVar4 == 0) {
      CObList::AddTail((CObList *)(in_ECX + 9),param_1);
      goto LAB_00858232;
    }
    puVar3 = (undefined4 *)FUN_0044f2d0(&local_1c);
    AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)*puVar3);
    cVar2 = FUN_007f0584(local_18.left,local_18.top,local_18.right,local_18.bottom,1);
  } while (cVar2 == '\0');
  InsertBefore(iVar4,param_1);
LAB_00858232:
  pcVar1 = *(code **)(*in_ECX + 0x44);
  guard_check_icall(1);
  (*pcVar1)();
  if ((in_ECX[0x10] & 0xa000U) == 0) {
    iVar4 = local_18.right - local_18.left;
  }
  else {
    iVar4 = local_18.bottom - local_18.top;
  }
  if (in_ECX[3] < iVar4) {
    FUN_00861bb1(in_ECX,in_ECX[7] + iVar4,1);
  }
  *(int **)(param_1 + 0xbc) = in_ECX;
  pcVar1 = *(code **)(*in_ECX + 0x28);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CDockingPanesRow[9] */
/* 008582e6  FUN_008582e6  176 bytes, 0 callers */

void FUN_008582e6(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 local_8;
  
  iVar2 = FUN_007a198a(param_1,0);
  if (iVar2 != 0) {
    local_8 = 0;
    pcVar1 = *(code **)(*param_1 + 0x2ac);
    guard_check_icall(0xffff,&local_8);
    (*pcVar1)();
    FUN_007a1ad4(iVar2);
    param_1[0x2f] = 0;
    if (in_ECX[0xc] == 0) {
      FUN_00861920(in_ECX);
    }
    else {
      FUN_008572d1(1,param_1);
      FUN_00857128();
      pcVar1 = *(code **)(*in_ECX + 0x44);
      guard_check_icall(0);
      (*pcVar1)();
      iVar2 = FUN_008576fa(0);
      if (iVar2 < in_ECX[3]) {
        FUN_00861bb1(in_ECX,iVar2,1);
        in_ECX[3] = iVar2;
      }
    }
  }
  return;
}




/* vtable slots: CDockingPanesRow[19] */
/* 00858396  ReplacePane  58 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CDockingPanesRow::ReplacePane(class CPane *,class CPane *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CDockingPanesRow::ReplacePane(CDockingPanesRow *this,CPane *param_1,CPane *param_2)

{
  __POSITION *p_Var1;
  
  p_Var1 = (__POSITION *)FUN_007a198a(param_1,0);
  if (p_Var1 != (__POSITION *)0x0) {
    CObList::InsertAfter((CObList *)(this + 0x24),p_Var1,(CObject *)param_2);
    FUN_007a1ad4(p_Var1);
  }
  return (uint)(p_Var1 != (__POSITION *)0x0);
}




/* vtable slots: CDockingPanesRow[15] */
/* 008583d0  FUN_008583d0  1326 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CDockingPanesRow * FUN_008583d0(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  CDockingPanesRow *pCVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  CDockingPanesRow *pCVar7;
  CDockingPanesRow *pCVar8;
  undefined4 *puVar9;
  BOOL BVar10;
  CDockingPanesRow *in_ECX;
  int *local_64;
  int *local_60;
  CDockingPanesRow *local_5c;
  undefined4 local_58;
  CDockingPanesRow *local_54;
  CDockingPanesRow *local_50;
  int *local_4c;
  RECT local_48;
  tagRECT local_38;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  RECT local_18;
  CDockingPanesRow *local_8;
  
  local_8 = (CDockingPanesRow *)(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  if (*(int *)(in_ECX + 0x30) == 0) {
    return local_8;
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x14);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    return (CDockingPanesRow *)0x0;
  }
  local_28 = *param_1;
  local_24 = param_1[1];
  local_20 = param_1[2];
  local_1c = param_1[3];
  FUN_0079e8b8(&local_28);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  CDockingPanesRow::GetWindowRect(in_ECX,(CRect *)&local_18);
  pCVar3 = (CDockingPanesRow *)IsRectEmpty(&local_18);
  if (pCVar3 != (CDockingPanesRow *)0x0) {
    return pCVar3;
  }
  if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
    pCVar3 = (CDockingPanesRow *)(((local_1c - local_18.bottom) - local_24) + local_18.top);
  }
  else {
    pCVar3 = (CDockingPanesRow *)(((local_20 - local_18.right) - local_28) + local_18.left);
  }
  local_58 = 0;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x60);
  local_50 = pCVar3;
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    piVar6 = *(int **)(*(int *)(in_ECX + 0x28) + 8);
    iVar2 = *piVar6;
    if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
      iVar4 = local_1c - local_24;
      iVar5 = local_18.right - local_18.left;
    }
    else {
      iVar4 = local_18.bottom - local_18.top;
      iVar5 = local_20 - local_28;
    }
    guard_check_icall(0,local_18.left,local_18.top,iVar5,iVar4,0x16,0);
    (**(code **)(iVar2 + 0x238))();
    pCVar3 = (CDockingPanesRow *)RedrawWindow((HWND)piVar6[8],(RECT *)0x0,(HRGN)0x0,0x105);
    return pCVar3;
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x5c);
  guard_check_icall(1);
  piVar6 = (int *)(*pcVar1)();
  local_4c = piVar6;
  if ((int)piVar6 < 0) {
    if (param_3 == 0) goto LAB_00858530;
    local_4c = *(int **)(in_ECX + 0x28);
    local_5c = pCVar3;
    do {
      do {
        if (local_4c == (int *)0x0) goto LAB_00858707;
        puVar9 = (undefined4 *)FUN_0044f2d0(&local_4c);
        pCVar8 = (CDockingPanesRow *)*puVar9;
        pcVar1 = *(code **)(*(int *)pCVar8 + 0x17c);
        local_54 = pCVar8;
        guard_check_icall();
        iVar2 = (*pcVar1)();
        pCVar7 = local_5c;
      } while ((iVar2 == 0) && (pCVar3 = local_50, *(int *)(in_ECX + 4) == 0));
      pcVar1 = *(code **)(*(int *)pCVar8 + 0x2ac);
      guard_check_icall(local_5c,&local_58);
      pCVar3 = (CDockingPanesRow *)(*pcVar1)();
      local_54 = pCVar3;
      if ((pCVar3 != (CDockingPanesRow *)0x0) && (local_4c != (int *)0x0)) {
        local_64 = local_4c;
        do {
          puVar9 = (undefined4 *)FUN_0044f2d0(&local_64);
          local_60 = (int *)*puVar9;
          pcVar1 = *(code **)(*local_60 + 0x17c);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if ((iVar2 != 0) || (*(int *)(in_ECX + 4) != 0)) {
            FUN_00857c8a(local_60,pCVar3,1,&local_58);
          }
          pCVar7 = local_5c;
        } while (local_64 != (int *)0x0);
      }
      local_5c = pCVar7 + -(int)local_54;
      pCVar3 = local_50;
    } while (0 < (int)local_5c);
  }
  else if ((param_3 == 0) && (iVar2 = _abs((int)pCVar3), (int)piVar6 < iVar2)) {
LAB_00858530:
    pCVar8 = (CDockingPanesRow *)0x1;
    if ((param_2 != 3) && (param_2 != 1)) {
      pCVar8 = (CDockingPanesRow *)0x0;
    }
    local_5c = (CDockingPanesRow *)CONCAT31(local_5c._1_3_,(char)pCVar8);
    if (-1 < (int)piVar6) {
      iVar4 = ((int)pCVar3 >> 0x1f & 0xfffffffeU) + 1;
      iVar2 = FUN_008577c9(0,pCVar8);
      iVar2 = _abs(iVar2);
      FUN_00858ce6(0,((int)local_4c - iVar2) * iVar4,pCVar8);
      iVar2 = _abs((int)local_50);
      pCVar8 = (CDockingPanesRow *)((iVar2 - (int)local_4c) * iVar4);
      local_50 = pCVar8;
    }
    local_60 = *(int **)(in_ECX + 0x2c);
    do {
      if (local_60 == (int *)0x0) {
        return pCVar8;
      }
      puVar9 = (undefined4 *)FUN_0049ad10(&local_60);
      piVar6 = (int *)*puVar9;
      pcVar1 = *(code **)(*piVar6 + 0x17c);
      local_4c = piVar6;
      guard_check_icall();
      iVar2 = (*pcVar1)();
      pCVar3 = local_50;
      if ((iVar2 != 0) || (*(int *)(in_ECX + 4) != 0)) {
        pcVar1 = *(code **)(*piVar6 + 0x2ac);
        guard_check_icall(local_50,&local_58);
        local_54 = (CDockingPanesRow *)(*pcVar1)();
        puVar9 = &local_58;
        pCVar8 = local_5c;
        iVar2 = _abs((int)local_54);
        iVar4 = _abs((int)pCVar3);
        FUN_00857c8a(local_4c,iVar4 - iVar2,pCVar8,puVar9);
        if (local_54 == pCVar3) {
          return local_54;
        }
        local_50 = pCVar3 + -(int)local_54;
      }
      pCVar8 = in_ECX + 0x24;
    } while( true );
  }
LAB_00858707:
  if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
    local_18.top = local_24;
    local_18.bottom = local_1c;
  }
  else {
    local_18.left = local_28;
    local_18.right = local_20;
  }
  pCVar7 = (CDockingPanesRow *)FUN_0085725d(1);
  FUN_00856342(pCVar7,&local_18,&local_58);
  pCVar8 = (CDockingPanesRow *)FUN_0085725d(0);
  if (pCVar7 != pCVar8) {
    pCVar8 = (CDockingPanesRow *)FUN_00856342(pCVar8,&local_18,&local_58);
  }
  if ((param_2 != -1) && (param_3 != 0)) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x5c);
    guard_check_icall(1);
    iVar2 = (*pcVar1)();
    pCVar8 = pCVar3 + iVar2;
    if (0 < (int)pCVar8) {
      local_38.left = 0;
      local_38.top = 0;
      local_38.right = 0;
      local_38.bottom = 0;
      local_48.left = 0;
      local_48.top = 0;
      local_48.right = 0;
      local_48.bottom = 0;
      local_54 = *(CDockingPanesRow **)(in_ECX + 0x28);
      pCVar8 = (CDockingPanesRow *)0x0;
      while (local_54 != (CDockingPanesRow *)0x0) {
        puVar9 = (undefined4 *)FUN_0044f2d0(&local_54);
        local_50 = (CDockingPanesRow *)*puVar9;
        pcVar1 = *(code **)(*(int *)local_50 + 0x17c);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if ((iVar2 != 0) || (*(int *)(in_ECX + 4) != 0)) {
          GetWindowRect(*(HWND *)(local_50 + 0x20),&local_38);
          FUN_007f028e(&local_48);
          BVar10 = EqualRect(&local_38,&local_48);
          if (BVar10 == 0) {
            if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
              if (local_48.top < local_38.top) goto LAB_00858876;
LAB_0085883a:
              local_4c = (int *)CONCAT31(local_4c._1_3_,1);
            }
            else {
              if (local_38.left <= local_48.left) goto LAB_0085883a;
LAB_00858876:
              local_4c = (int *)((uint)local_4c._1_3_ << 8);
            }
            piVar6 = (int *)0x0;
            if ((*(uint *)(in_ECX + 0x40) & 0xa000) == 0) {
              if ((param_2 == 3) || (param_2 == 6)) {
                iVar2 = _abs(local_48.top - local_38.top);
                iVar4 = _abs(param_4);
                if (iVar2 <= iVar4) {
                  iVar2 = local_48.top - local_38.top;
                  goto LAB_008588ad;
                }
LAB_00858867:
                piVar6 = (int *)_abs(param_4);
              }
            }
            else if ((param_2 == 1) || (param_2 == 2)) {
              iVar2 = _abs(local_48.left - local_38.left);
              iVar4 = _abs(param_4);
              if (iVar4 < iVar2) goto LAB_00858867;
              iVar2 = local_48.left - local_38.left;
LAB_008588ad:
              piVar6 = (int *)_abs(iVar2);
            }
            local_64 = piVar6;
            iVar2 = FUN_008579b1(local_50,local_4c,&local_64);
            if (iVar2 != 0) {
              FUN_00857c8a(local_50,piVar6,local_4c,&local_58);
            }
          }
        }
        pCVar8 = in_ECX + 0x24;
      }
    }
  }
  return pCVar8;
}




/* vtable slots: CDockingPanesRow[13] */
/* 008588fe  FUN_008588fe  95 bytes, 0 callers */

int FUN_008588fe(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x28);
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)*puVar2);
    if (pCVar3 != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x210);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return param_1;
}




/* vtable slots: CDockingPanesRow[18] */
/* 0085902f  ShowDockSiteRow  32 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CDockingPanesRow::ShowDockSiteRow(int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CDockingPanesRow::ShowDockSiteRow(CDockingPanesRow *this,int param_1,int param_2)

{
  *(int *)(this + 8) = param_1;
  FUN_00861e1d(this,param_1,param_2 == 0);
  return;
}




/* vtable slots: CDockingPanesRow[20] */
/* 0085904f  FUN_0085904f  244 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0085904f(int *param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  CDockingPanesRow *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_007a198a(param_1,0);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00797f20(-(param_2 != 0) & 5);
  pcVar1 = *(code **)(*(int *)in_ECX + 0x44);
  guard_check_icall(param_3);
  (*pcVar1)();
  if (param_2 == 0) {
    FUN_00857128();
    if (param_3 != 0) {
      return 1;
    }
  }
  else {
    if (param_3 != 0) {
      return 1;
    }
    pcVar1 = *(code **)(*param_1 + 0x20c);
    guard_check_icall();
    (*pcVar1)();
    pcVar1 = *(code **)(*(int *)in_ECX + 0x28);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  CDockingPanesRow::GetClientRect(in_ECX,(CRect *)&local_18);
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x44) + 0x298);
  guard_check_icall(&local_18);
  (*pcVar1)();
  iVar2 = *(int *)in_ECX;
  guard_check_icall(&local_18,0xffffffff,0,0);
  (**(code **)(iVar2 + 0x3c))();
  return 1;
}




/* vtable slots: CDockingPanesRow[17] */
/* 008591ec  FUN_008591ec  213 bytes, 0 callers */

int * FUN_008591ec(undefined4 param_1)

{
  int *piVar1;
  code *pcVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  BOOL BVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int *in_ECX;
  int *piVar9;
  int local_c;
  int *local_8;
  
  pHVar3 = GetParent(*(HWND *)(in_ECX[0x11] + 0x20));
  pCVar4 = CWnd::FromHandle(pHVar3);
  BVar5 = IsWindowVisible(*(HWND *)(pCVar4 + 0x20));
  piVar1 = (int *)in_ECX[2];
  piVar6 = (int *)-BVar5;
  local_c = in_ECX[10];
  piVar9 = (int *)0x0;
  do {
    if (local_c == 0) {
LAB_0085929d:
      if (piVar1 != piVar9) {
        pcVar2 = *(code **)(*in_ECX + 0x48);
        guard_check_icall(piVar9,param_1);
        piVar6 = (int *)(*pcVar2)();
      }
      in_ECX[2] = (int)piVar9;
      return piVar6;
    }
    puVar7 = (undefined4 *)FUN_0044f2d0(&local_c);
    local_8 = (int *)*puVar7;
    if (BVar5 == 0) {
      pcVar2 = *(code **)(*local_8 + 0x1b0);
      guard_check_icall();
      iVar8 = (*pcVar2)();
      if (iVar8 == 0) goto LAB_0085927e;
      pcVar2 = *(code **)(*local_8 + 0x1ac);
      guard_check_icall();
      piVar6 = (int *)(*pcVar2)();
      piVar9 = piVar6;
      if (piVar6 != (int *)0x0) goto LAB_0085929d;
    }
    else {
LAB_0085927e:
      piVar6 = (int *)FUN_00797b3d();
      if (((uint)piVar6 & 0x10000000) != 0) {
        piVar9 = (int *)0x1;
        goto LAB_0085929d;
      }
    }
    piVar6 = in_ECX + 9;
  } while( true );
}



