/* CDockBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDockBar[1] */
/* 007bd00c  FUN_007bd00c  51 bytes, 0 callers */

void FUN_007bd00c(byte param_1)

{
  FUN_007bcf76();
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




/* vtable slots: CDockBar[89] */
/* 007bd072  FUN_007bd072  1371 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_007bd072(int *param_1,int param_2,int param_3)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  CDockBar *in_ECX;
  int iVar8;
  int local_7c;
  int local_78;
  int *local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  CControlBar *local_5c;
  HDWP local_58 [8];
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_74 = param_1;
  if (in_ECX == (CDockBar *)0x0) {
LAB_007bd5c8:
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  FUN_007abeef(param_1,param_2,param_3);
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0xe4));
  if (BVar2 == 0) {
    local_28.left = ((RECT *)(in_ECX + 0xe4))->left;
    local_28.top = *(LONG *)(in_ECX + 0xe8);
    local_28.right = *(LONG *)(in_ECX + 0xec);
    local_28.bottom = *(LONG *)(in_ECX + 0xf0);
    pcVar1 = *(code **)(*(int *)in_ECX + 0x170);
    guard_check_icall(&local_28,param_3);
    (*pcVar1)();
  }
  else {
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    iVar3 = FUN_0079296c();
    if (iVar3 == 0) goto LAB_007bd5c8;
    GetClientRect(*(HWND *)(iVar3 + 0x20),&local_28);
  }
  iVar3 = local_28.right - local_28.left;
  iVar4 = local_28.bottom - local_28.top;
  if (*(int *)(in_ECX + 0xe0) == 0) {
    local_58[0] = BeginDeferWindowPos(*(int *)(in_ECX + 0xd4));
  }
  else {
    local_58[0] = (HDWP)0x0;
  }
  iVar8 = -DAT_00a12218;
  local_68 = 0;
  local_6c = -DAT_00a1221c;
  local_60 = 0;
  local_64 = 0;
  local_70 = iVar8;
  if (0 < *(int *)(in_ECX + 0xd4)) {
    do {
      iVar6 = local_6c;
      local_5c = CDockBar::GetDockedControlBar(in_ECX,local_64);
      piVar5 = (int *)FUN_0049a990(local_64);
      if (local_5c == (CControlBar *)0x0) {
        if (*piVar5 == 0) {
LAB_007bd4ac:
          if (local_68 != 0) {
            if (param_3 == 0) {
              iVar8 = (iVar8 - DAT_00a12218) + local_68;
              iVar7 = *local_74;
              if (*local_74 <= iVar8) {
                iVar7 = iVar8;
              }
              *local_74 = iVar7;
              iVar7 = local_74[1];
              if (local_74[1] <= iVar6) {
                iVar7 = iVar6;
              }
              local_74[1] = iVar7;
              local_6c = -DAT_00a1221c;
            }
            else {
              local_6c = (iVar6 - DAT_00a1221c) + local_68;
              iVar6 = *local_74;
              if (*local_74 <= iVar8) {
                iVar6 = iVar8;
              }
              *local_74 = iVar6;
              iVar8 = local_74[1];
              if (local_74[1] <= local_6c) {
                iVar8 = local_6c;
              }
              local_74[1] = iVar8;
              iVar8 = -DAT_00a12218;
            }
            local_68 = 0;
            local_70 = iVar8;
          }
        }
      }
      else {
        pcVar1 = *(code **)(*(int *)local_5c + 400);
        guard_check_icall();
        iVar6 = (*pcVar1)();
        if (iVar6 == 0) {
LAB_007bd480:
          if (local_60 != 0) goto LAB_007bd519;
        }
        else {
          if (((byte)*(uint *)(local_5c + 0xb0) & 5) == 5) {
            iVar6 = 6;
          }
          else {
            iVar6 = (-(uint)((*(uint *)(local_5c + 0xb0) & 0xa000) != 0) & 0xfffffffa) + 0x10;
          }
          pcVar1 = *(code **)(*(int *)local_5c + 0x168);
          guard_check_icall(&local_7c,0xffffffff,iVar6);
          (*pcVar1)();
          iVar6 = local_6c;
          local_18.right = local_7c + iVar8;
          local_18.bottom = local_78 + local_6c;
          local_28.left = 0;
          local_28.top = 0;
          local_28.right = 0;
          local_28.bottom = 0;
          local_18.top = local_6c;
          local_18.left = iVar8;
          GetWindowRect(*(HWND *)(local_5c + 0x20),&local_28);
          CWnd::ScreenToClient((CWnd *)in_ECX,&local_28);
          if (param_3 == 0) {
            if ((local_18.top < local_28.top) && (*(int *)(in_ECX + 200) == 0)) {
              OffsetRect(&local_18,0,local_28.top - local_18.top);
            }
            if ((iVar4 < local_18.bottom) && (*(int *)(in_ECX + 200) == 0)) {
              iVar7 = DAT_00a1221c + (iVar4 - local_18.bottom) + local_18.top;
              if (iVar7 <= iVar6) {
                iVar7 = iVar6;
              }
              OffsetRect(&local_18,0,iVar7 - local_18.top);
            }
            if (local_60 == 0) {
              if (((iVar4 - DAT_00a1221c <= local_18.top) && (0 < local_64)) &&
                 (piVar5 = (int *)FUN_0049a990(local_64 + -1), *piVar5 != 0)) goto LAB_007bd350;
            }
            else {
              local_60 = 0;
              OffsetRect(&local_18,0,-(DAT_00a1221c + local_18.top));
            }
            BVar2 = EqualRect(&local_18,&local_28);
            if (BVar2 == 0) {
              if ((*(int *)(in_ECX + 0xe0) == 0) && (((byte)local_5c[0xb0] & 1) == 0)) {
                iVar8 = *(int *)(local_5c + 0xc0);
                *(LONG *)(iVar8 + 0x94) = local_18.left;
                *(LONG *)(iVar8 + 0x98) = local_18.top;
                *(LONG *)(iVar8 + 0x9c) = local_18.right;
                *(LONG *)(iVar8 + 0xa0) = local_18.bottom;
                iVar8 = local_70;
              }
              FUN_0079129f(local_58,*(int *)(local_5c + 0x20),&local_18);
            }
            local_6c = (local_18.top - DAT_00a1221c) + local_78;
            if (local_68 <= local_7c) {
              local_68 = local_7c;
              goto LAB_007bd480;
            }
          }
          else {
            if ((local_18.left < local_28.left) && (*(int *)(in_ECX + 200) == 0)) {
              OffsetRect(&local_18,local_28.left - local_18.left,0);
            }
            if ((iVar3 < local_18.right) && (*(int *)(in_ECX + 200) == 0)) {
              iVar7 = (DAT_00a12218 - local_18.right) + iVar3 + local_18.left;
              if (iVar7 <= iVar8) {
                iVar7 = iVar8;
              }
              OffsetRect(&local_18,iVar7 - local_18.left,0);
            }
            if (local_60 == 0) {
              if (((iVar3 - DAT_00a12218 <= local_18.left) && (0 < local_64)) &&
                 (piVar5 = (int *)FUN_0049a990(local_64 + -1), *piVar5 != 0)) {
LAB_007bd350:
                FUN_007affd3(local_64,0,1);
                local_60 = 1;
                goto LAB_007bd4ac;
              }
            }
            else {
              local_60 = 0;
              OffsetRect(&local_18,-(DAT_00a12218 + local_18.left),0);
            }
            BVar2 = EqualRect(&local_18,&local_28);
            if (BVar2 == 0) {
              if ((*(int *)(in_ECX + 0xe0) == 0) && (((byte)local_5c[0xb0] & 1) == 0)) {
                iVar8 = *(int *)(local_5c + 0xc0);
                *(LONG *)(iVar8 + 0x94) = local_18.left;
                *(LONG *)(iVar8 + 0x98) = local_18.top;
                *(LONG *)(iVar8 + 0x9c) = local_18.right;
                *(LONG *)(iVar8 + 0xa0) = local_18.bottom;
              }
              FUN_0079129f(local_58,*(int *)(local_5c + 0x20),&local_18);
            }
            iVar8 = (local_7c - DAT_00a12218) + local_18.left;
            local_70 = iVar8;
            if (local_68 <= local_78) {
              local_68 = local_78;
            }
          }
        }
        pcVar1 = *(code **)(*(int *)local_5c + 0x194);
        guard_check_icall(local_58);
        (*pcVar1)();
      }
LAB_007bd519:
      local_64 = local_64 + 1;
    } while (local_64 < *(int *)(in_ECX + 0xd4));
  }
  if ((*(int *)(in_ECX + 0xe0) == 0) && (local_58[0] != (HDWP)0x0)) {
    EndDeferWindowPos(local_58[0]);
  }
  local_38.left = 0;
  local_38.top = 0;
  local_38.right = 0;
  local_38.bottom = 0;
  SetRectEmpty(&local_38);
  pcVar1 = *(code **)(*(int *)in_ECX + 0x170);
  guard_check_icall(&local_38,param_3);
  (*pcVar1)();
  if ((param_2 == 0) || (param_3 == 0)) {
    if (*local_74 != 0) {
      *local_74 = (*local_74 - local_38.right) + local_38.left;
    }
    if (param_2 == 0) goto LAB_007bd5a5;
  }
  if (param_3 == 0) {
    return local_74;
  }
LAB_007bd5a5:
  if (local_74[1] != 0) {
    local_74[1] = (local_74[1] - local_38.bottom) + local_38.top;
  }
  return local_74;
}




/* vtable slots: CDockBar[105] */
/* 007bd5ce  FUN_007bd5ce  120 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007bd5ce(int param_1,uint param_2,undefined4 param_3)

{
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 != 0) {
    *(uint *)(in_ECX + 0xb0) = param_2 & 0x40ffff;
    FUN_00790c5e(2);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    SetRectEmpty(&local_18);
    FUN_00791f4f(L"AfxControlBar140su",0,param_2,&local_18,param_1,param_3,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CDockBar[106] */
/* 007bdbe3  FUN_007bdbe3  85 bytes, 0 callers */

int FUN_007bdbe3(void)

{
  code *pcVar1;
  CControlBar *pCVar2;
  int iVar3;
  CDockBar *in_ECX;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0xd4)) {
    do {
      pCVar2 = CDockBar::GetDockedControlBar(in_ECX,iVar4);
      if (pCVar2 != (CControlBar *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar2 + 400);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 != 0) {
          iVar5 = iVar5 + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0xd4));
  }
  return iVar5;
}




/* vtable slots: CDockBar[10] */
/* 007bdc38  FUN_007bdc38  6 bytes, 0 callers */

undefined ** FUN_007bdc38(void)

{
  return &PTR_LAB_00982108;
}




/* vtable slots: CDockBar[0] */
/* 007bdc44  FUN_007bdc44  6 bytes, 0 callers */

undefined ** FUN_007bdc44(void)

{
  return &PTR_s_CDockBar_00981ca8;
}



