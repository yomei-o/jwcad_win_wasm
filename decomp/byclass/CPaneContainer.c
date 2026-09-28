/* CPaneContainer -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPaneContainer[1] */
/* 008b9f4b  FUN_008b9f4b  51 bytes, 0 callers */

void FUN_008b9f4b(byte param_1)

{
  FUN_008b9edb();
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




/* vtable slots: CPaneContainer[16] */
/* 008ba885  FUN_008ba885  298 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008ba885(int param_1,int *param_2,int *param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_30 [4];
  int *local_2c;
  undefined1 local_28 [4];
  int *local_24;
  undefined1 local_20 [4];
  code *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_24 = param_2;
  local_2c = param_3;
  if (param_2 == (int *)0x0) {
    if (param_3 == (int *)0x0) {
      return param_1;
    }
    iVar2 = FUN_008bbd97();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*local_2c + 0x44);
      guard_check_icall(local_28,param_1,0,param_4);
      piVar3 = (int *)(*pcVar1)();
      goto LAB_008ba99b;
    }
    pcVar1 = *(code **)(*local_2c + 0x44);
    guard_check_icall(local_20,0,param_1,param_4);
    iVar2 = (*pcVar1)();
  }
  else {
    GetWindowRect((HWND)param_2[8],&local_18);
    iVar2 = FUN_008bbd97();
    if (iVar2 == 0) {
      if (param_4 == 0) {
        local_18.left = local_18.left + param_1;
      }
      else {
        local_18.right = local_18.right + param_1;
      }
      local_1c = *(code **)(*local_24 + 0x2d0);
      guard_check_icall(local_30,local_18.left,local_18.top,local_18.right,local_18.bottom);
      piVar3 = (int *)(*local_1c)();
      goto LAB_008ba99b;
    }
    if (param_4 == 0) {
      local_18.top = local_18.top + param_1;
    }
    else {
      local_18.bottom = local_18.bottom + param_1;
    }
    local_1c = *(code **)(*local_24 + 0x2d0);
    guard_check_icall(local_30,local_18.left,local_18.top,local_18.right,local_18.bottom);
    iVar2 = (*local_1c)();
  }
  piVar3 = (int *)(iVar2 + 4);
LAB_008ba99b:
  return *piVar3;
}




/* vtable slots: CPaneContainer[17] */
/* 008ba9af  FUN_008ba9af  269 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008ba9af(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int *in_ECX;
  int iVar2;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  pcVar1 = *(code **)(*in_ECX + 0xc);
  guard_check_icall(&local_18,0);
  (*pcVar1)();
  if (param_4 == 0) {
    local_2c = local_18 + param_2;
    local_30 = local_14 + param_3;
    local_28 = local_10;
    iVar2 = local_c;
  }
  else {
    local_28 = local_10 + param_2;
    local_30 = local_14;
    local_2c = local_18;
    iVar2 = local_c + param_3;
  }
  local_20 = 0;
  local_1c = 0;
  pcVar1 = *(code **)(*in_ECX + 0x10);
  guard_check_icall(&local_20);
  (*pcVar1)();
  *param_1 = param_2;
  param_1[1] = param_3;
  if (local_28 - local_2c < local_20) {
    local_20 = (local_10 - local_18) - local_20;
    *param_1 = local_20;
    if (local_20 < 0) {
      *param_1 = 0;
      local_20 = 0;
    }
    if (param_2 < 0) {
      *param_1 = -local_20;
    }
  }
  if (iVar2 - local_30 < local_1c) {
    local_30 = (iVar2 - local_1c) - local_30;
    param_1[1] = local_30;
    if (local_30 < 0) {
      param_1[1] = 0;
      local_30 = 0;
    }
    if (param_3 < 0) {
      param_1[1] = -local_30;
    }
  }
  return param_1;
}




/* vtable slots: CPaneContainer[20] */
/* 008bb04a  FUN_008bb04a  331 bytes, 0 callers */

int FUN_008bb04a(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0x1c) + 0x40) == 0) {
    iVar2 = FUN_0078e624(0x9c);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_008b9e37(*(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 4),
                           *(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc));
    }
  }
  else {
    iVar2 = FUN_0079d90c();
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(in_ECX + 4);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(in_ECX + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(in_ECX + 0xc);
  }
  if (*(int *)(in_ECX + 4) != 0) {
    uVar3 = FUN_00797b3d();
    if ((uVar3 & 0x10000000) == 0) {
      *(undefined4 *)(iVar2 + 4) = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 4) = 0;
    }
  }
  if (*(int *)(in_ECX + 8) != 0) {
    uVar3 = FUN_00797b3d();
    if ((uVar3 & 0x10000000) == 0) {
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 8) = 0;
    }
  }
  *(undefined4 *)(iVar2 + 0x18) = param_1;
  if (*(int **)(in_ECX + 0x10) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0x50);
    guard_check_icall(iVar2);
    iVar4 = (*pcVar1)();
    *(int *)(iVar2 + 0x10) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x18) = iVar2;
    }
  }
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x50);
    guard_check_icall(iVar2);
    iVar4 = (*pcVar1)();
    *(int *)(iVar2 + 0x14) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x18) = iVar2;
    }
  }
  if (*(int *)(in_ECX + 0xc) != 0) {
    uVar3 = FUN_00797b3d();
    if ((uVar3 & 0x10000000) == 0) {
      *(undefined4 *)(iVar2 + 0xc) = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x114);
      GetClientRect(*(HWND *)(*(int *)(in_ECX + 0xc) + 0x20),(LPRECT)(in_ECX + 0x44));
      pcVar1 = *(code **)(**(int **)(in_ECX + 0xc) + 0x164);
      guard_check_icall();
      uVar5 = (*pcVar1)();
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)(in_ECX + 0x34) = uVar5;
    }
  }
  return iVar2;
}




/* vtable slots: CPaneContainer[10] */
/* 008bb195  FUN_008bb195  653 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bb195(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  CWnd *this;
  int *in_ECX;
  CPaneContainer *pCVar3;
  code *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined1 local_3c [4];
  CPaneContainer *local_38;
  int *local_34;
  HDWP local_30;
  int *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  pcVar4 = *(code **)(*in_ECX + 0xc);
  local_18.right = 0;
  local_18.bottom = 0;
  local_2c = in_ECX;
  guard_check_icall(&local_18,0);
  (*pcVar4)();
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  GetWindowRect(*(HWND *)(param_1 + 0x20),&local_28);
  if (in_ECX[3] != 0) {
    FUN_008bbd97();
  }
  local_30 = BeginDeferWindowPos(10);
  if (param_2 == 0) {
    if (param_1 != in_ECX[1]) goto LAB_008bb3f2;
    local_34 = (int *)in_ECX[2];
    in_ECX[1] = 0;
    if (local_34 == (int *)0x0) {
      pCVar3 = (CPaneContainer *)in_ECX[5];
LAB_008bb2aa:
      if (pCVar3 != (CPaneContainer *)0x0) {
        iVar2 = CPaneContainer::IsEmpty(pCVar3);
        if (iVar2 == 0) {
          pcVar4 = *(code **)(*(int *)in_ECX[7] + 0x74);
          guard_check_icall();
          this = (CWnd *)(*pcVar4)();
          CWnd::ScreenToClient(this,&local_18);
          iVar2 = *in_ECX;
          guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,&local_30,0);
          (**(code **)(iVar2 + 0x48))();
          in_ECX = local_2c;
          goto LAB_008bb3f2;
        }
      }
      pCVar3 = (CPaneContainer *)in_ECX[6];
      if (pCVar3 != (CPaneContainer *)0x0) {
        do {
          iVar2 = CPaneContainer::IsEmpty(pCVar3);
          if (iVar2 == 0) break;
          pCVar3 = *(CPaneContainer **)(pCVar3 + 0x18);
        } while (pCVar3 != (CPaneContainer *)0x0);
        local_38 = pCVar3;
        if (pCVar3 != (CPaneContainer *)0x0) {
          local_2c = *(int **)(pCVar3 + 0xc);
          if (local_2c != (int *)0x0) {
            pcVar4 = *(code **)(*local_2c + 0x164);
            guard_check_icall();
            iVar2 = (*pcVar4)();
            piVar5 = local_2c;
            if (iVar2 == 0) {
              iVar2 = local_28.right - local_28.left;
            }
            else {
              iVar2 = local_28.bottom - local_28.top;
            }
            local_34 = (int *)(local_2c[0x46] + iVar2 * 2 + 2);
            iVar2 = CPaneContainer::IsLeftPartEmpty(pCVar3,0);
            if (iVar2 == 0) {
              iVar2 = CPaneContainer::IsRightPartEmpty(pCVar3,0);
              if (iVar2 == 0) goto LAB_008bb3f2;
              pcVar4 = *(code **)(*(int *)pCVar3 + 0x34);
              pcVar1 = *(code **)(*piVar5 + 0x164);
              guard_check_icall();
              iVar2 = (*pcVar1)();
              uVar6 = 1;
              piVar5 = local_34;
            }
            else {
              pcVar4 = *(code **)(*(int *)pCVar3 + 0x34);
              pcVar1 = *(code **)(*piVar5 + 0x164);
              guard_check_icall();
              iVar2 = (*pcVar1)();
              uVar6 = 0;
              piVar5 = (int *)-(int)local_34;
            }
            guard_check_icall(piVar5,iVar2 == 0,uVar6,1,&local_30);
            (*pcVar4)();
          }
        }
      }
      goto LAB_008bb3f2;
    }
    pcVar4 = *(code **)(*local_34 + 0x2a8);
    guard_check_icall(local_3c,local_18.left,local_18.top,local_18.right,local_18.bottom,0,&local_30
                     );
  }
  else {
    if ((param_2 != 1) || (param_1 != in_ECX[2])) goto LAB_008bb3f2;
    local_34 = (int *)in_ECX[1];
    in_ECX[2] = 0;
    if (local_34 == (int *)0x0) {
      pCVar3 = (CPaneContainer *)in_ECX[4];
      goto LAB_008bb2aa;
    }
    pcVar4 = *(code **)(*local_34 + 0x2a8);
    guard_check_icall(local_3c,local_18.left,local_18.top,local_18.right,local_18.bottom,0,&local_30
                     );
  }
  (*pcVar4)();
LAB_008bb3f2:
  EndDeferWindowPos(local_30);
  if (in_ECX[3] == 0) {
    in_ECX[2] = 0;
    in_ECX[1] = 0;
    in_ECX[5] = 0;
    in_ECX[4] = 0;
  }
  return;
}




/* vtable slots: CPaneContainer[4] */
/* 008bb629  FUN_008bb629  531 bytes, 0 callers */

void FUN_008bb629(int *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0x1c) != 0) {
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    param_1[1] = 0;
    *param_1 = 0;
    iVar2 = FUN_008bbcd5();
    local_8 = iVar2;
    if ((*(int *)(in_ECX + 4) != 0) &&
       ((uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) != 0 || (iVar2 != 0)))) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 4) + 0x270);
      guard_check_icall(&local_18);
      (*pcVar1)();
      iVar2 = local_8;
    }
    if ((*(int *)(in_ECX + 8) != 0) &&
       ((uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) != 0 || (iVar2 != 0)))) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x270);
      guard_check_icall(&local_10);
      (*pcVar1)();
    }
    local_20 = 0;
    local_1c = 0;
    if ((*(int *)(in_ECX + 0x10) != 0) && ((iVar2 = FUN_008bbe09(), iVar2 != 0 || (local_8 != 0))))
    {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0x10);
      guard_check_icall(&local_20);
      (*pcVar1)();
    }
    iVar2 = local_8;
    local_28 = 0;
    local_24 = 0;
    if ((*(int *)(in_ECX + 0x14) != 0) && ((iVar4 = FUN_008bbe09(), iVar4 != 0 || (iVar2 != 0)))) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x10);
      guard_check_icall(&local_28);
      (*pcVar1)();
    }
    if ((*(int *)(in_ECX + 0xc) == 0) ||
       ((uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) == 0 && (local_8 == 0)))) {
      iVar2 = local_18;
      if (local_18 <= local_10) {
        iVar2 = local_10;
      }
      *param_1 = iVar2;
      iVar2 = local_14;
      if (local_14 <= local_c) {
        iVar2 = local_c;
      }
      param_1[1] = iVar2;
      if ((*(int *)(in_ECX + 0x10) != 0) && (iVar2 = FUN_008bbe09(), iVar2 != 0)) {
        *param_1 = local_20;
        param_1[1] = local_1c;
      }
      if ((*(int *)(in_ECX + 0x14) != 0) && (iVar2 = FUN_008bbe09(), iVar2 != 0)) {
        *param_1 = local_28;
        param_1[1] = local_24;
      }
    }
    else {
      iVar2 = FUN_008bbd97();
      if (iVar2 == 0) {
        if (local_14 <= local_c) {
          local_14 = local_c;
        }
        if (local_1c <= local_14) {
          local_1c = local_14;
        }
        if (local_24 <= local_1c) {
          local_24 = local_1c;
        }
        param_1[1] = local_24;
        *param_1 = *(int *)(*(int *)(in_ECX + 0xc) + 0x118) + local_28 + local_20 + local_10 +
                   local_18;
      }
      else {
        if (local_18 <= local_10) {
          local_18 = local_10;
        }
        if (local_20 <= local_18) {
          local_20 = local_18;
        }
        if (local_28 <= local_20) {
          local_28 = local_20;
        }
        *param_1 = local_28;
        param_1[1] = *(int *)(*(int *)(in_ECX + 0xc) + 0x118) + local_24 + local_1c + local_c +
                     local_14;
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CPaneContainer[5] */
/* 008bb83d  FUN_008bb83d  182 bytes, 0 callers */

void FUN_008bb83d(int *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = in_ECX;
  iVar2 = FUN_008bbcd5();
  local_1c = 0;
  local_18 = 0;
  local_c = iVar2;
  if ((*(int *)(in_ECX + 4) != 0) &&
     ((uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) != 0 || (iVar2 != 0)))) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 4) + 0x270);
    guard_check_icall(&local_1c);
    (*pcVar1)();
    in_ECX = local_8;
    iVar2 = local_c;
  }
  local_14 = 0;
  local_10 = 0;
  iVar4 = 0;
  iVar5 = 0;
  if ((*(int *)(in_ECX + 0x10) != 0) &&
     ((iVar4 = FUN_008bbe09(), iVar4 != 0 || (iVar4 = local_10, iVar5 = local_14, iVar2 != 0)))) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0x10);
    guard_check_icall(&local_14);
    (*pcVar1)();
    iVar4 = local_10;
    iVar5 = local_14;
  }
  if (local_1c <= iVar5) {
    local_1c = iVar5;
  }
  *param_1 = local_1c;
  if (local_18 <= iVar4) {
    local_18 = iVar4;
  }
  param_1[1] = local_18;
  return;
}




/* vtable slots: CPaneContainer[6] */
/* 008bb8f3  FUN_008bb8f3  182 bytes, 0 callers */

void FUN_008bb8f3(int *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = in_ECX;
  iVar2 = FUN_008bbcd5();
  local_1c = 0;
  local_18 = 0;
  local_c = iVar2;
  if ((*(int *)(in_ECX + 8) != 0) &&
     ((uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) != 0 || (iVar2 != 0)))) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x270);
    guard_check_icall(&local_1c);
    (*pcVar1)();
    in_ECX = local_8;
    iVar2 = local_c;
  }
  local_14 = 0;
  local_10 = 0;
  iVar4 = 0;
  iVar5 = 0;
  if ((*(int *)(in_ECX + 0x14) != 0) &&
     ((iVar4 = FUN_008bbe09(), iVar4 != 0 || (iVar4 = local_10, iVar5 = local_14, iVar2 != 0)))) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x10);
    guard_check_icall(&local_14);
    (*pcVar1)();
    iVar4 = local_10;
    iVar5 = local_14;
  }
  if (local_1c <= iVar5) {
    local_1c = iVar5;
  }
  *param_1 = local_1c;
  if (local_18 <= iVar4) {
    local_18 = iVar4;
  }
  param_1[1] = local_18;
  return;
}




/* vtable slots: CPaneContainer[7] */
/* 008bb9d2  FUN_008bb9d2  196 bytes, 0 callers */

int FUN_008bb9d2(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = -1;
  if (*(int **)(in_ECX + 4) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 4) + 0x274);
    guard_check_icall();
    iVar3 = (*pcVar1)();
  }
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x274);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar3 <= iVar2) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x274);
      guard_check_icall();
      iVar3 = (*pcVar1)();
    }
  }
  if (*(int **)(in_ECX + 0x10) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0x1c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
  }
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x1c);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar3 <= iVar2) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x1c);
      guard_check_icall();
      iVar3 = (*pcVar1)();
    }
  }
  return iVar3;
}




/* vtable slots: CPaneContainer[0] */
/* 008bba96  FUN_008bba96  6 bytes, 0 callers */

undefined ** FUN_008bba96(void)

{
  return &PTR_s_CPaneContainer_009a2748;
}




/* vtable slots: CPaneContainer[3] */
/* 008bbac4  FUN_008bbac4  529 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bbac4(LPRECT param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  BOOL BVar4;
  int iVar5;
  int in_ECX;
  int local_44;
  int local_40;
  int local_3c;
  RECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_38.left = 0;
  local_38.top = 0;
  local_38.right = 0;
  local_38.bottom = 0;
  SetRectEmpty(param_1);
  SetRectEmpty(&local_28);
  SetRectEmpty(&local_18);
  iVar2 = FUN_008bbcd5();
  local_3c = iVar2;
  if ((*(int *)(in_ECX + 4) != 0) &&
     (((uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) != 0 || (param_2 != 0)) || (iVar2 != 0)))) {
    GetWindowRect(*(HWND *)(*(int *)(in_ECX + 4) + 0x20),&local_28);
    BVar4 = IsRectEmpty(&local_28);
    if (BVar4 != 0) {
      local_44 = 0;
      local_40 = 0;
      pcVar1 = *(code **)(**(int **)(in_ECX + 4) + 0x270);
      guard_check_icall(&local_44);
      (*pcVar1)();
      if (local_28.right == local_28.left) {
        local_28.right = local_28.right + local_44;
      }
      iVar2 = local_3c;
      if (local_28.bottom == local_28.top) {
        local_28.bottom = local_28.bottom + local_40;
      }
    }
  }
  if ((*(int *)(in_ECX + 8) != 0) &&
     (((uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) != 0 || (param_2 != 0)) || (iVar2 != 0)))) {
    GetWindowRect(*(HWND *)(*(int *)(in_ECX + 8) + 0x20),&local_18);
    BVar4 = IsRectEmpty(&local_18);
    if (BVar4 != 0) {
      local_44 = 0;
      local_40 = 0;
      pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x270);
      guard_check_icall(&local_44);
      (*pcVar1)();
      if (local_18.right == local_18.left) {
        local_18.right = local_18.right + local_44;
      }
      if (local_18.bottom == local_18.top) {
        local_18.bottom = local_18.bottom + local_40;
      }
    }
  }
  UnionRect(param_1,&local_28,&local_18);
  if ((*(int *)(in_ECX + 0x10) != 0) &&
     (((iVar2 = FUN_008bbe09(), iVar2 != 0 || (param_2 != 0)) || (local_3c != 0)))) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0xc);
    guard_check_icall(&local_38,0);
    (*pcVar1)();
    UnionRect(param_1,param_1,&local_38);
  }
  iVar2 = local_3c;
  if ((*(int *)(in_ECX + 0x14) != 0) &&
     (((iVar5 = FUN_008bbe09(), iVar5 != 0 || (param_2 != 0)) || (iVar2 != 0)))) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0xc);
    guard_check_icall(&local_38,0);
    (*pcVar1)();
    UnionRect(param_1,param_1,&local_38);
  }
  return;
}




/* vtable slots: CPaneContainer[12] */
/* 008bbf3a  FUN_008bbf3a  436 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bbf3a(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  SetRectEmpty(&local_28);
  if (*(int *)(in_ECX + 4) != 0) {
    GetWindowRect(*(HWND *)(*(int *)(in_ECX + 4) + 0x20),&local_18);
    pcVar1 = *(code **)(**(int **)(in_ECX + 4) + 0x238);
    guard_check_icall(0,param_1,param_2,0,0,0x15,0);
    (*pcVar1)();
  }
  if (*(int **)(in_ECX + 0x10) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0xc);
    guard_check_icall(&local_18,0);
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0x30);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
  }
  iVar3 = local_18.bottom - local_18.top;
  iVar4 = local_18.right - local_18.left;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xc) + 0x164);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xc) + 0x238);
    if (iVar2 == 0) {
      guard_check_icall(0,param_1 + iVar4,param_2,0,0,0x15,0);
      (*pcVar1)();
      iVar4 = iVar4 + *(int *)(*(int *)(in_ECX + 0xc) + 0x118);
      iVar3 = 0;
    }
    else {
      guard_check_icall(0,param_1,param_2 + iVar3,0,0,0x15,0);
      (*pcVar1)();
      iVar3 = iVar3 + *(int *)(*(int *)(in_ECX + 0xc) + 0x118);
      iVar4 = 0;
    }
  }
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x238);
    guard_check_icall(0,param_1 + iVar4,param_2 + iVar3,0,0,0x15,0);
    (*pcVar1)();
  }
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x30);
    guard_check_icall(param_1 + iVar4,param_2 + iVar3);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CPaneContainer[14] */
/* 008bc0ee  FUN_008bc0ee  713 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008bc0ee(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  BOOL BVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int *local_30;
  undefined4 *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = param_2;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_30 = in_ECX;
  SetRectEmpty(&local_18);
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  SetRectEmpty(&local_28);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  if (*(int *)((int)in_ECX + 4) != 0) {
    GetWindowRect(*(HWND *)(*(int *)((int)in_ECX + 4) + 0x20),&local_18);
    pcVar1 = *(code **)(**(int **)((int)in_ECX + 4) + 0x270);
    guard_check_icall(&local_40);
    (*pcVar1)();
  }
  if (*(int **)((int)in_ECX + 0x10) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)((int)in_ECX + 0x10) + 0xc);
    guard_check_icall(&local_18,0);
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)((int)in_ECX + 0x10) + 0x10);
    guard_check_icall(&local_40);
    (*pcVar1)();
  }
  if (*(int *)((int)in_ECX + 8) != 0) {
    GetWindowRect(*(HWND *)(*(int *)((int)in_ECX + 8) + 0x20),&local_28);
    pcVar1 = *(code **)(**(int **)((int)in_ECX + 8) + 0x270);
    guard_check_icall(&local_38);
    (*pcVar1)();
  }
  if (*(int **)((int)in_ECX + 0x14) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)((int)in_ECX + 0x14) + 0xc);
    guard_check_icall(&local_28,0);
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)((int)in_ECX + 0x14) + 0x10);
    guard_check_icall(&local_38);
    (*pcVar1)();
  }
  pHVar2 = GetParent(*(HWND *)(*(int *)((int)in_ECX + 0xc) + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  CWnd::ScreenToClient(pCVar3,&local_18);
  pHVar2 = GetParent(*(HWND *)(*(int *)((int)in_ECX + 0xc) + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  CWnd::ScreenToClient(pCVar3,&local_28);
  BVar4 = IsRectEmpty(&local_18);
  if (BVar4 == 0) {
    iVar5 = FUN_008bbd97();
    if (iVar5 == 0) {
      local_18.right = local_18.right + param_1;
      if (local_18.right - local_18.left < local_40) {
        local_18.right = local_18.left + local_40;
      }
    }
    else {
      local_18.bottom = local_18.bottom + param_1;
      if (local_18.bottom - local_18.top < local_3c) {
        local_18.bottom = local_18.top + local_3c;
      }
    }
  }
  BVar4 = IsRectEmpty(&local_28);
  if (BVar4 == 0) {
    iVar5 = FUN_008bbd97();
    if (iVar5 == 0) {
      local_28.left = local_28.left + param_1;
      if (local_28.right - local_28.left < local_38) {
        local_28.left = local_28.right - local_38;
      }
    }
    else {
      local_28.top = local_28.top + param_1;
      if (local_28.bottom - local_28.top < local_34) {
        local_28.top = local_28.bottom - local_34;
      }
    }
  }
  if (*(int **)((int)in_ECX + 4) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)((int)in_ECX + 4) + 0x234);
    guard_check_icall(&local_18,1,*local_2c);
    uVar6 = (*pcVar1)();
    *local_2c = uVar6;
  }
  if (*(int **)((int)in_ECX + 0x10) != (int *)0x0) {
    iVar5 = **(int **)((int)in_ECX + 0x10);
    guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,local_2c,0);
    (**(code **)(iVar5 + 0x48))();
    in_ECX = local_30;
  }
  if (*(int **)((int)in_ECX + 8) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)((int)in_ECX + 8) + 0x234);
    guard_check_icall(&local_28,1,*local_2c);
    uVar6 = (*pcVar1)();
    *local_2c = uVar6;
  }
  local_30 = *(int **)((int)in_ECX + 0x14);
  if (local_30 != (int *)0x0) {
    iVar5 = *local_30;
    guard_check_icall(local_28.left,local_28.top,local_28.right,local_28.bottom,local_2c,0);
    (**(code **)(iVar5 + 0x48))();
  }
  return param_1;
}




/* vtable slots: CPaneContainer[8] */
/* 008bc3b7  FUN_008bc3b7  287 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bc3b7(int *param_1,int param_2)

{
  code *pcVar1;
  CWnd *this;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  int *local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_2 == 0) {
    pcVar1 = *(code **)(*(int *)in_ECX[7] + 0x74);
    guard_check_icall();
    this = (CWnd *)(*pcVar1)();
    local_18.left = 0;
    local_18.top = 0;
    pcVar1 = *(code **)(*in_ECX + 0xc);
    local_18.right = 0;
    local_18.bottom = 0;
    guard_check_icall(&local_18,1);
    (*pcVar1)();
    CWnd::ScreenToClient(this,&local_18);
    piVar3 = (int *)in_ECX[1];
    if (((piVar3 == (int *)0x0) || (piVar3 == param_1)) &&
       ((piVar3 = (int *)in_ECX[2], piVar3 == (int *)0x0 || (piVar3 == param_1)))) {
      local_20 = (int *)in_ECX[4];
      if (local_20 == (int *)0x0) {
        local_1c = (int *)in_ECX[5];
        if (local_1c == (int *)0x0) {
          return;
        }
        local_20 = (int *)0x0;
        iVar2 = *local_1c;
        guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,&local_20,1);
      }
      else {
        local_1c = (int *)0x0;
        iVar2 = *local_20;
        guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,&local_1c,1);
      }
      (**(code **)(iVar2 + 0x48))();
    }
    else {
      pcVar1 = *(code **)(*piVar3 + 0x238);
      guard_check_icall(0,local_18.left,local_18.top,local_18.right - local_18.left,
                        local_18.bottom - local_18.top,0x14,0);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CPaneContainer[9] */
/* 008bc569  FUN_008bc569  71 bytes, 0 callers */

void FUN_008bc569(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  piVar2 = (int *)FUN_008bb422(param_1,0);
  if (piVar2 == (int *)0x0) {
    uVar3 = 1;
    piVar2 = (int *)FUN_008bb422(param_1,1);
    if (piVar2 == (int *)0x0) {
      return;
    }
  }
  pcVar1 = *(code **)(*piVar2 + 0x28);
  guard_check_icall(param_1,uVar3);
  (*pcVar1)();
  return;
}




/* vtable slots: CPaneContainer[18] */
/* 008bc5b0  FUN_008bc5b0  3370 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bc5b0(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
                 undefined4 param_6)

{
  code *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  BOOL BVar8;
  HWND pHVar9;
  CWnd *pCVar10;
  CPaneContainer *in_ECX;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  undefined8 local_c0;
  CPaneContainer *local_b8;
  undefined4 local_b4;
  undefined4 *local_b0;
  int local_ac;
  undefined8 local_a8;
  uint local_a0;
  int local_9c;
  tagRECT local_98;
  tagRECT local_88;
  tagRECT local_78;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  tagRECT local_58;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  tagRECT local_38;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_b0 = param_5;
  local_b4 = param_6;
  local_38.left = 0;
  local_38.top = 0;
  local_38.right = 0;
  local_38.bottom = 0;
  local_b8 = in_ECX;
  SetRectEmpty(&local_38);
  local_78.left = 0;
  local_78.top = 0;
  local_78.right = 0;
  local_78.bottom = 0;
  SetRectEmpty(&local_78);
  iVar4 = FUN_008bbcd5();
  local_9c = iVar4;
  if ((*(int *)(in_ECX + 0xc) != 0) &&
     ((uVar5 = FUN_00797b3d(), (uVar5 & 0x10000000) != 0 || (iVar4 != 0)))) {
    GetWindowRect(*(HWND *)(*(int *)(in_ECX + 0xc) + 0x20),&local_78);
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0xc);
  guard_check_icall(&local_38,0);
  (*pcVar1)();
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  SetRectEmpty(&local_28);
  local_58.left = 0;
  local_58.top = 0;
  local_58.right = 0;
  local_58.bottom = 0;
  SetRectEmpty(&local_58);
  local_c8 = 0;
  local_c4 = 0;
  local_d0 = 0;
  local_cc = 0;
  if ((*(int *)(in_ECX + 4) != 0) &&
     ((uVar5 = FUN_00797b3d(), (uVar5 & 0x10000000) != 0 || (iVar4 != 0)))) {
    GetWindowRect(*(HWND *)(*(int *)(in_ECX + 4) + 0x20),&local_28);
    pcVar1 = *(code **)(**(int **)(in_ECX + 4) + 0x270);
    guard_check_icall(&local_c8);
    (*pcVar1)();
    iVar4 = local_9c;
  }
  if ((*(int *)(in_ECX + 0x10) != 0) && ((iVar6 = FUN_008bbe09(), iVar6 != 0 || (iVar4 != 0)))) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0xc);
    guard_check_icall(&local_28,0);
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 0x10);
    guard_check_icall(&local_c8);
    (*pcVar1)();
  }
  if ((*(int *)(in_ECX + 8) != 0) &&
     ((uVar5 = FUN_00797b3d(), (uVar5 & 0x10000000) != 0 || (local_9c != 0)))) {
    GetWindowRect(*(HWND *)(*(int *)(in_ECX + 8) + 0x20),&local_58);
    pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x270);
    guard_check_icall(&local_d0);
    (*pcVar1)();
  }
  iVar4 = local_9c;
  if ((*(int *)(in_ECX + 0x14) != 0) && ((iVar6 = FUN_008bbe09(), iVar6 != 0 || (iVar4 != 0)))) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0xc);
    guard_check_icall(&local_58,0);
    (*pcVar1)();
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x10);
    guard_check_icall(&local_d0);
    (*pcVar1)();
  }
  local_a0 = (uint)(local_9c == 0);
  iVar4 = CPaneContainer::IsLeftPartEmpty(in_ECX,local_a0);
  uVar5 = local_a0;
  if ((iVar4 == 0) && (iVar4 = CPaneContainer::IsRightPartEmpty(in_ECX,local_a0), iVar4 != 0)) {
    if (*(int **)(in_ECX + 4) != (int *)0x0) {
      if ((param_3 - param_1 < local_c8) && (DAT_00a12770 != 0)) {
        param_3 = param_1 + local_c8;
      }
      if ((param_4 - param_2 < local_c4) && (DAT_00a12770 != 0)) {
        param_4 = param_2 + local_c4;
      }
      pcVar1 = *(code **)(**(int **)(in_ECX + 4) + 0x234);
      guard_check_icall(&param_1,local_b4,*local_b0);
      uVar7 = (*pcVar1)();
      *local_b0 = uVar7;
    }
    local_b8 = *(CPaneContainer **)(in_ECX + 0x10);
    if (local_b8 == (CPaneContainer *)0x0) {
      return;
    }
    iVar4 = *(int *)local_b8;
    guard_check_icall(param_1,param_2,param_3,param_4,local_b0,local_b4);
LAB_008bc98c:
    (**(code **)(iVar4 + 0x48))();
    return;
  }
  iVar4 = CPaneContainer::IsLeftPartEmpty(in_ECX,uVar5);
  if ((iVar4 != 0) && (iVar4 = CPaneContainer::IsRightPartEmpty(in_ECX,uVar5), iVar4 == 0)) {
    if (*(int **)(in_ECX + 8) != (int *)0x0) {
      if ((param_3 - param_1 < local_d0) && (DAT_00a12770 != 0)) {
        param_3 = local_d0 + param_1;
      }
      if ((param_4 - param_2 < local_cc) && (DAT_00a12770 != 0)) {
        param_4 = local_cc + param_2;
      }
      pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x234);
      guard_check_icall(&param_1,local_b4,*local_b0);
      uVar7 = (*pcVar1)();
      *local_b0 = uVar7;
    }
    local_b8 = *(CPaneContainer **)(in_ECX + 0x14);
    if (local_b8 == (CPaneContainer *)0x0) {
      return;
    }
    iVar4 = *(int *)local_b8;
    guard_check_icall(param_1,param_2,param_3,param_4,local_b0,local_b4);
    goto LAB_008bc98c;
  }
  iVar4 = CPaneContainer::IsLeftPartEmpty(in_ECX,uVar5);
  if (iVar4 != 0) {
    return;
  }
  iVar4 = CPaneContainer::IsRightPartEmpty(in_ECX,uVar5);
  if (iVar4 != 0) {
    return;
  }
  local_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  local_48 = param_1;
  local_44 = param_2;
  local_40 = param_3;
  local_3c = param_4;
  local_68 = param_1;
  local_64 = param_2;
  local_60 = param_3;
  local_5c = param_4;
  if (*(int *)(in_ECX + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar4 = FUN_008bbd97();
  local_ac = 100;
  local_9c = -1;
  if (iVar4 == 0) {
    if (((local_38.right - local_38.left <
          ((local_28.right - local_58.left) - local_28.left) + local_58.right) ||
        (BVar8 = IsRectEmpty(&local_28), BVar8 != 0)) ||
       (BVar8 = IsRectEmpty(&local_58), BVar8 != 0)) {
      iVar4 = local_38.right - local_38.left;
      if (local_28.right - local_28.left == iVar4) {
        local_9c = 0x32;
        if (*(int *)(in_ECX + 8) == 0) {
          if (*(int *)(in_ECX + 0x14) != 0) {
            local_9c = *(int *)(*(int *)(in_ECX + 0x14) + 0x20);
            goto LAB_008bce18;
          }
        }
        else {
          local_9c = *(int *)(*(int *)(in_ECX + 8) + 0x2d0);
LAB_008bce18:
          if ((local_9c == local_ac) || (local_9c == 0)) {
            local_9c = 0x32;
          }
        }
        local_28.right =
             ((local_28.left - (local_9c * iVar4) / local_ac) - local_38.left) + local_38.right;
        local_9c = local_ac - local_9c;
      }
      else {
        if (local_58.right - local_58.left != iVar4) goto LAB_008bcebd;
        local_9c = 0x32;
        if (*(int *)(in_ECX + 4) == 0) {
          if (*(int *)(in_ECX + 0x10) != 0) {
            local_9c = *(int *)(*(int *)(in_ECX + 0x10) + 0x20);
            goto LAB_008bce86;
          }
        }
        else {
          local_9c = *(int *)(*(int *)(in_ECX + 4) + 0x2d0);
LAB_008bce86:
          if ((local_9c == local_ac) || (local_9c == 0)) {
            local_9c = 0x32;
          }
        }
        local_28.right = local_28.left + (local_9c * iVar4) / local_ac;
      }
    }
LAB_008bcebd:
    iVar4 = local_28.right - local_28.left;
    local_a0 = ((local_38.left - local_38.right) - param_1) + param_3;
    local_c0 = (double)(local_38.right - local_38.left);
    local_a8 = (double)iVar4;
    if (DAT_00a13cc0 == 0) {
      if (DAT_00a13cc4 == 0) {
        if ((0 < (int)local_a0) || ((int)local_a0 < 0)) goto LAB_008bd02e;
        goto LAB_008bd051;
      }
      local_10 = local_18 + iVar4;
      pHVar9 = GetCapture();
      pCVar10 = CWnd::FromHandle(pHVar9);
      if (pCVar10 != *(CWnd **)(in_ECX + 0xc)) {
        local_98.left = local_78.left;
        local_98.top = local_78.top;
        local_98.right = local_78.right;
        local_98.bottom = local_78.bottom;
        pHVar9 = GetParent(*(HWND *)(*(CWnd **)(in_ECX + 0xc) + 0x20));
        pCVar10 = CWnd::FromHandle(pHVar9);
        CWnd::ScreenToClient(pCVar10,&local_98);
        local_10 = local_98.left;
      }
      local_a8 = (double)(local_10 - local_18);
    }
    else if (local_a0 == 0) {
LAB_008bd051:
      local_10 = local_18 + iVar4;
    }
    else {
LAB_008bd02e:
      local_a8 = (double)(int)local_a0;
      iVar4 = thunk_FUN_008d99f0();
      local_10 = ((local_28.right - iVar4) - local_28.left) + local_18;
    }
    local_60 = *(int *)(*(int *)(in_ECX + 0xc) + 0x118) + local_10;
    local_68 = local_10;
    local_48 = local_60;
    if (DAT_00a12770 == 0) goto LAB_008bd153;
    iVar6 = (local_18 - local_10) + local_c8;
    iVar4 = (local_60 - local_40) + local_d0;
    local_60 = *(int *)(*(int *)(in_ECX + 0xc) + 0x118);
    if (iVar6 < 1) {
      if (0 < iVar4) {
        local_10 = local_10 - iVar4;
        if (local_10 - local_18 < local_c8) goto LAB_008bd0f0;
LAB_008bd0f3:
        local_48 = local_60 + local_10;
        goto LAB_008bd0fc;
      }
    }
    else {
      if (0 < iVar4) {
LAB_008bd0f0:
        local_10 = local_18 + local_c8;
        goto LAB_008bd0f3;
      }
      local_10 = local_10 + iVar6;
      local_48 = local_60 + local_10;
      if (local_d0 <= local_40 - local_48) goto LAB_008bd0ff;
LAB_008bd0fc:
      local_40 = local_48 + local_d0;
    }
LAB_008bd0ff:
    local_60 = local_60 + local_10;
    local_a8 = (double)(local_10 - local_18);
    in_ECX = local_b8;
    local_68 = local_10;
    if (local_c - local_14 < local_c4) {
      local_c = local_14 + local_c4;
      local_3c = local_44 + local_c4;
    }
    goto LAB_008bd153;
  }
  if (((local_38.bottom - local_38.top <
        ((local_58.bottom - local_58.top) - local_28.top) + local_28.bottom) ||
      (BVar8 = IsRectEmpty(&local_28), BVar8 != 0)) || (BVar8 = IsRectEmpty(&local_58), BVar8 != 0))
  {
    iVar6 = local_38.bottom - local_38.top;
    iVar4 = 0x32;
    local_9c = 0x32;
    if (local_28.bottom - local_28.top == iVar6) {
      if (*(int *)(in_ECX + 8) == 0) {
        if (*(int *)(in_ECX + 0x14) != 0) {
          iVar4 = *(int *)(*(int *)(in_ECX + 0x14) + 0x20);
          goto LAB_008bca6e;
        }
      }
      else {
        iVar4 = *(int *)(*(int *)(in_ECX + 8) + 0x2d0);
LAB_008bca6e:
        if ((iVar4 == local_ac) || (iVar4 == 0)) {
          iVar4 = 0x32;
        }
      }
      local_28.bottom =
           ((local_38.bottom - (iVar6 * iVar4) / local_ac) - local_38.top) + local_28.top;
      local_9c = local_ac - iVar4;
    }
    else {
      if (local_58.bottom - local_58.top != iVar6) goto LAB_008bcaf7;
      if (*(int *)(in_ECX + 4) == 0) {
        if (*(int *)(in_ECX + 0x10) != 0) {
          local_9c = *(int *)(*(int *)(in_ECX + 0x10) + 0x20);
          goto LAB_008bcac6;
        }
      }
      else {
        local_9c = *(int *)(*(int *)(in_ECX + 4) + 0x2d0);
LAB_008bcac6:
        if ((local_9c == local_ac) || (local_9c == 0)) {
          local_9c = 0x32;
        }
      }
      local_28.bottom = (iVar6 * local_9c) / local_ac + local_28.top;
    }
  }
LAB_008bcaf7:
  local_a0 = ((local_38.top - local_38.bottom) - param_2) + param_4;
  local_c0 = (double)CONCAT44(local_28.bottom - local_28.top,(undefined4)local_c0);
  local_a8 = (double)(local_28.bottom - local_28.top);
  if (DAT_00a13cc0 == 0) {
    if (DAT_00a13cc4 == 0) {
      if ((0 < (int)local_a0) || ((int)local_a0 < 0)) goto LAB_008bcc70;
      goto LAB_008bcc93;
    }
    local_c = (local_14 - local_28.top) + local_28.bottom;
    pHVar9 = GetCapture();
    pCVar10 = CWnd::FromHandle(pHVar9);
    if (pCVar10 != *(CWnd **)(in_ECX + 0xc)) {
      local_88.left = local_78.left;
      local_88.top = local_78.top;
      local_88.right = local_78.right;
      local_88.bottom = local_78.bottom;
      pHVar9 = GetParent(*(HWND *)(*(CWnd **)(in_ECX + 0xc) + 0x20));
      pCVar10 = CWnd::FromHandle(pHVar9);
      CWnd::ScreenToClient(pCVar10,&local_88);
      local_c = local_88.top;
    }
    local_c0 = (double)CONCAT44(local_c - local_14,SUB84(local_c0,0));
    local_a8 = (double)(local_c - local_14);
  }
  else if (local_a0 == 0) {
LAB_008bcc93:
    local_c = (local_14 - local_28.top) + local_28.bottom;
  }
  else {
LAB_008bcc70:
    local_a8 = (double)(int)local_a0;
    iVar4 = thunk_FUN_008d99f0();
    local_c = ((local_14 - iVar4) - local_28.top) + local_28.bottom;
  }
  local_5c = *(int *)(*(int *)(in_ECX + 0xc) + 0x118) + local_c;
  local_64 = local_c;
  local_44 = local_5c;
  if (DAT_00a12770 == 0) goto LAB_008bd153;
  iVar6 = (local_14 - local_c) + local_c4;
  iVar4 = (local_5c - local_3c) + local_cc;
  local_5c = *(int *)(*(int *)(in_ECX + 0xc) + 0x118);
  if (iVar6 < 1) {
    if (0 < iVar4) {
      local_c = local_c - iVar4;
      if (local_c - local_14 < local_c4) goto LAB_008bcd37;
LAB_008bcd3a:
      local_44 = local_5c + local_c;
      goto LAB_008bcd43;
    }
  }
  else {
    if (0 < iVar4) {
LAB_008bcd37:
      local_c = local_14 + local_c4;
      goto LAB_008bcd3a;
    }
    local_c = local_c + iVar6;
    local_44 = local_5c + local_c;
    if (local_cc <= local_3c - local_44) goto LAB_008bcd46;
LAB_008bcd43:
    local_3c = local_44 + local_cc;
  }
LAB_008bcd46:
  local_5c = local_5c + local_c;
  local_c0 = (double)CONCAT44(local_c - local_14,(undefined4)local_c0);
  local_a8 = (double)(local_c - local_14);
  in_ECX = local_b8;
  local_64 = local_c;
  if (local_10 - local_18 < local_c8) {
    local_10 = local_18 + local_c8;
    local_40 = local_48 + local_c8;
  }
LAB_008bd153:
  piVar2 = *(int **)(in_ECX + 4);
  local_a0 = thunk_FUN_008d99f0();
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0x234);
    guard_check_icall(&local_18,local_b4,*local_b0);
    uVar7 = (*pcVar1)();
    *local_b0 = uVar7;
    *(uint *)(*(int *)(in_ECX + 4) + 0x2d0) = local_a0;
  }
  piVar2 = *(int **)(in_ECX + 0x10);
  local_a8 = (double)CONCAT44(piVar2,(undefined4)local_a8);
  if (piVar2 != (int *)0x0) {
    iVar4 = *piVar2;
    guard_check_icall(local_18,local_14,local_10,local_c,local_b0,local_b4);
    (**(code **)(iVar4 + 0x48))();
    *(uint *)(*(int *)(local_b8 + 0x10) + 0x20) = local_a0;
    in_ECX = local_b8;
  }
  local_ac = local_ac - local_a0;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 8) + 0x234);
    guard_check_icall(&local_48,local_b4,*local_b0);
    uVar7 = (*pcVar1)();
    *local_b0 = uVar7;
    *(int *)(*(int *)(in_ECX + 8) + 0x2d0) = local_ac;
  }
  piVar2 = *(int **)(in_ECX + 0x14);
  local_a8 = (double)CONCAT44(piVar2,(undefined4)local_a8);
  if (piVar2 != (int *)0x0) {
    iVar4 = *piVar2;
    guard_check_icall(local_48,local_44,local_40,local_3c,local_b0,local_b4);
    (**(code **)(iVar4 + 0x48))();
    *(int *)(*(int *)(local_b8 + 0x14) + 0x20) = local_ac;
    in_ECX = local_b8;
  }
  uVar5 = FUN_00797b3d();
  puVar3 = local_b0;
  if ((uVar5 & 0x10000000) == 0) {
    return;
  }
  pcVar1 = *(code **)(**(int **)(in_ECX + 0xc) + 0x234);
  guard_check_icall(&local_68,local_b4,*local_b0);
  uVar7 = (*pcVar1)();
  *puVar3 = uVar7;
  return;
}




/* vtable slots: CPaneContainer[15] */
/* 008bd2db  FUN_008bd2db  189 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bd2db(int param_1,int *param_2,int *param_3,int param_4,int param_5,undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  undefined1 local_20 [4];
  undefined4 local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_6;
  if (param_2 == (int *)0x0) {
    if (param_3 != (int *)0x0) {
      iVar2 = *param_3;
      guard_check_icall(param_1,param_4,param_5,1,param_6);
      (**(code **)(iVar2 + 0x34))();
    }
  }
  else {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect((HWND)param_2[8],&local_18);
    if (param_4 == 0) {
      if (param_5 == 0) {
        local_18.left = local_18.left + param_1;
      }
      else {
        local_18.right = local_18.right + param_1;
      }
    }
    else if (param_5 == 0) {
      local_18.top = local_18.top - param_1;
    }
    else {
      local_18.bottom = local_18.bottom + param_1;
    }
    pcVar1 = *(code **)(*param_2 + 0x2a8);
    guard_check_icall(local_20,local_18.left,local_18.top,local_18.right,local_18.bottom,0,local_1c)
    ;
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CPaneContainer[19] */
/* 008bd398  FUN_008bd398  608 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bd398(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  CWnd *this;
  undefined4 uVar2;
  int in_ECX;
  code *pcVar3;
  int *piVar4;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0xc) == 0) {
    return;
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  local_20 = 0;
  local_1c = 0;
  if (param_2 == 0) {
    if (*(int **)(in_ECX + 0x14) == (int *)0x0) {
      if (*(int *)(in_ECX + 8) == 0) {
        return;
      }
      GetWindowRect(*(HWND *)(*(int *)(in_ECX + 8) + 0x20),&local_18);
      pcVar3 = *(code **)(**(int **)(in_ECX + 8) + 0x270);
    }
    else {
      pcVar3 = *(code **)(**(int **)(in_ECX + 0x14) + 0xc);
      guard_check_icall(&local_18,0);
      (*pcVar3)();
      pcVar3 = *(code **)(**(int **)(in_ECX + 0x14) + 0x10);
    }
    piVar4 = &local_20;
    guard_check_icall(piVar4);
    (*pcVar3)();
    iVar1 = FUN_008bbd97();
    if (iVar1 == 0) {
LAB_008bd521:
      local_18.left = local_18.left + param_1;
      if (local_18.right - local_18.left < local_20) {
        local_18.left = local_18.right - local_20;
      }
    }
    else {
      local_18.top = local_18.top + param_1;
      if (local_18.bottom - local_18.top < local_1c) {
        local_18.top = local_18.bottom - local_1c;
      }
    }
  }
  else {
    if (*(int **)(in_ECX + 0x10) == (int *)0x0) {
      if (*(int *)(in_ECX + 4) == 0) {
        return;
      }
      GetWindowRect(*(HWND *)(*(int *)(in_ECX + 4) + 0x20),&local_18);
      pcVar3 = *(code **)(**(int **)(in_ECX + 4) + 0x270);
    }
    else {
      pcVar3 = *(code **)(**(int **)(in_ECX + 0x10) + 0xc);
      guard_check_icall(&local_18,0);
      (*pcVar3)();
      pcVar3 = *(code **)(**(int **)(in_ECX + 0x10) + 0x10);
    }
    piVar4 = &local_20;
    guard_check_icall(piVar4);
    (*pcVar3)();
    iVar1 = FUN_008bbd97();
    if (iVar1 == 0) {
      iVar1 = FUN_008bbd97();
      if (iVar1 != 0) goto LAB_008bd521;
      local_18.right = local_18.right + param_1;
      if (local_18.right - local_18.left < local_20) {
        local_18.right = local_18.left + local_20;
      }
    }
    else {
      local_18.bottom = local_18.bottom + param_1;
      if (local_18.bottom - local_18.top < local_1c) {
        local_18.bottom = local_18.top + local_1c;
      }
    }
  }
  pcVar3 = *(code **)(**(int **)(in_ECX + 0x1c) + 0x74);
  guard_check_icall(piVar4);
  this = (CWnd *)(*pcVar3)();
  CWnd::ScreenToClient(this,&local_18);
  if (param_2 == 0) {
    if (*(int **)(in_ECX + 0x14) == (int *)0x0) {
      piVar4 = *(int **)(in_ECX + 8);
      goto LAB_008bd5c2;
    }
    iVar1 = **(int **)(in_ECX + 0x14);
    guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,param_3,0);
  }
  else {
    if (*(int **)(in_ECX + 0x10) == (int *)0x0) {
      piVar4 = *(int **)(in_ECX + 4);
LAB_008bd5c2:
      if (piVar4 == (int *)0x0) {
        return;
      }
      pcVar3 = *(code **)(*piVar4 + 0x234);
      guard_check_icall(&local_18,0,*param_3);
      uVar2 = (*pcVar3)();
      *param_3 = uVar2;
      return;
    }
    iVar1 = **(int **)(in_ECX + 0x10);
    guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,param_3,0);
  }
  (**(code **)(iVar1 + 0x48))();
  return;
}




/* vtable slots: CPaneContainer[2] */
/* 008bd67b  FUN_008bd67b  695 bytes, 0 callers */

void FUN_008bd67b(CArchive *param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  CObject *pCVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  int *local_8;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x24));
    if (*(long *)(in_ECX + 0x24) == -1) {
      uVar4 = FUN_008bbe5b(param_1,in_ECX + 100);
      *(undefined4 *)(in_ECX + 4) = uVar4;
    }
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x28));
    if (*(long *)(in_ECX + 0x28) == -1) {
      uVar4 = FUN_008bbe5b(param_1,in_ECX + 0x80);
      *(undefined4 *)(in_ECX + 8) = uVar4;
    }
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x2c));
    if (*(long *)(in_ECX + 0x2c) != 0) {
      pCVar5 = (CObject *)FUN_0079d90c();
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,pCVar5);
      *(CObject **)(in_ECX + 0xc) = pCVar5;
      CPaneDivider::Init((CPaneDivider *)pCVar5,0,*(CWnd **)(*(int *)(in_ECX + 0x1c) + 0x4c));
      pcVar1 = *(code **)(**(int **)(in_ECX + 0xc) + 8);
      guard_check_icall(param_1);
      (*pcVar1)();
      *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x168) = *(undefined4 *)(in_ECX + 0x1c);
      CObList::AddTail((CObList *)(*(int *)(in_ECX + 0x1c) + 0x20),*(CObject **)(in_ECX + 0xc));
    }
    local_8 = (int *)0x0;
    CArchive::operator>>(param_1,(long *)&local_8);
    iVar2 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x40);
    if (local_8 != (int *)0x0) {
      if (iVar2 == 0) {
        local_8 = (int *)FUN_0078e624(0x9c);
        if (local_8 == (int *)0x0) {
          local_8 = (int *)0x0;
        }
        else {
          local_8 = (int *)FUN_008b9e37(*(undefined4 *)(in_ECX + 0x1c),0,0,0);
        }
        *(int **)(in_ECX + 0x10) = local_8;
      }
      else {
        iVar6 = FUN_0079d90c();
        *(int *)(in_ECX + 0x10) = iVar6;
        *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
        local_8 = *(int **)(in_ECX + 0x10);
      }
      pcVar1 = *(code **)(*local_8 + 8);
      guard_check_icall(param_1);
      (*pcVar1)();
      *(int *)(*(int *)(in_ECX + 0x10) + 0x18) = in_ECX;
    }
    piVar7 = (int *)0x0;
    local_8 = (int *)0x0;
    CArchive::operator>>(param_1,(long *)&local_8);
    if (local_8 == (int *)0x0) {
      return;
    }
    if (iVar2 == 0) {
      iVar2 = FUN_0078e624(0x9c);
      if (iVar2 != 0) {
        piVar7 = (int *)FUN_008b9e37(*(undefined4 *)(in_ECX + 0x1c),0,0,0);
      }
      *(int **)(in_ECX + 0x14) = piVar7;
    }
    else {
      iVar2 = FUN_0079d90c();
      *(int *)(in_ECX + 0x14) = iVar2;
      *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
      piVar7 = *(int **)(in_ECX + 0x14);
    }
    pcVar1 = *(code **)(*piVar7 + 8);
    guard_check_icall(param_1);
    (*pcVar1)();
    *(int *)(*(int *)(in_ECX + 0x14) + 0x18) = in_ECX;
    return;
  }
  if (*(int *)(in_ECX + 4) == 0) {
    iVar2 = 0;
LAB_008bd6ba:
    CArchive::operator<<(param_1,iVar2);
  }
  else {
    iVar2 = FUN_00797a2b();
    if (iVar2 != -1) goto LAB_008bd6ba;
    FUN_008bd5f8(param_1,*(undefined4 *)(in_ECX + 4));
  }
  if (*(int *)(in_ECX + 8) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00797a2b();
    if (iVar2 == -1) {
      FUN_008bd5f8(param_1,*(undefined4 *)(in_ECX + 8));
      goto LAB_008bd6ea;
    }
  }
  CArchive::operator<<(param_1,iVar2);
LAB_008bd6ea:
  if (*(int *)(in_ECX + 0xc) == 0) {
    CArchive::operator<<(param_1,0);
  }
  else {
    lVar3 = FUN_00797a2b();
    CArchive::operator<<(param_1,lVar3);
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xc) + 8);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  CArchive::operator<<(param_1,(uint)(*(int *)(in_ECX + 0x10) != 0));
  if (*(int **)(in_ECX + 0x10) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x10) + 8);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  CArchive::operator<<(param_1,(uint)(*(int *)(in_ECX + 0x14) != 0));
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 8);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CPaneContainer[11] */
/* 008bd9e7  FUN_008bd9e7  113 bytes, 0 callers */

void FUN_008bd9e7(CDockablePane *param_1)

{
  code *pcVar1;
  CPaneDivider *pCVar2;
  int iVar3;
  undefined4 in_ECX;
  
  pCVar2 = CDockablePane::GetDefaultPaneDivider(param_1);
  if (pCVar2 != (CPaneDivider *)0x0) {
    pcVar1 = *(code **)(*(int *)param_1 + 0x228);
    guard_check_icall(0);
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x1dc);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return;
      }
    }
  }
  pcVar1 = *(code **)(*(int *)(param_1 + 0x1e4) + 0xc);
  guard_check_icall(in_ECX,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CPaneContainer[13] */
/* 008bda58  FUN_008bda58  787 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008bda58(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  HWND pHVar7;
  CWnd *this;
  int *in_ECX;
  int iVar8;
  int local_30;
  code *local_2c;
  undefined4 *local_28;
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_3;
  local_28 = param_5;
  FUN_00404c80();
  uVar1 = FUN_00797acc();
  if (((uVar1 & 0x400000) != 0) && (param_2 != 0)) {
    param_1 = -param_1;
  }
  iVar8 = 0;
  local_20 = 0;
  iVar2 = (param_1 >> 0x1f & 0xfffffffeU) + 1;
  iVar4 = param_1;
  if (param_2 != 0) {
    iVar8 = param_1;
    iVar4 = local_20;
  }
  local_20 = iVar4;
  local_2c = *(code **)(*in_ECX + 0x44);
  if (param_2 == 0) {
    guard_check_icall(&local_18.right,iVar8,local_20,param_3);
    iVar8 = (*local_2c)();
    local_2c = *(code **)(iVar8 + 4);
  }
  else {
    guard_check_icall(local_24,iVar8,local_20,param_3);
    piVar3 = (int *)(*local_2c)();
    local_2c = (code *)*piVar3;
  }
  iVar8 = _abs((int)local_2c);
  iVar4 = _abs(param_1);
  pcVar6 = (code *)param_1;
  if (iVar8 <= iVar4) {
    pcVar6 = local_2c;
  }
  local_20 = _abs((int)pcVar6);
  local_20 = local_20 * iVar2;
  iVar4 = _abs(local_20);
  iVar8 = 0;
  if (iVar4 != 0) {
    if ((int *)in_ECX[3] != (int *)0x0) {
      pcVar6 = *(code **)(*(int *)in_ECX[3] + 0x164);
      guard_check_icall();
      iVar8 = (*pcVar6)();
      if ((iVar8 == 0) || (param_2 == 0)) {
        pcVar6 = *(code **)(*(int *)in_ECX[3] + 0x164);
        guard_check_icall();
        iVar8 = (*pcVar6)();
        if ((iVar8 != 0) || (param_2 != 0)) {
          pcVar6 = *(code **)(*in_ECX + 0x40);
          guard_check_icall(param_1,in_ECX[1],in_ECX[4],local_1c);
          iVar8 = (*pcVar6)();
          pcVar6 = *(code **)(*in_ECX + 0x40);
          guard_check_icall(param_1,in_ECX[2],in_ECX[5],local_1c);
          iVar4 = (*pcVar6)();
          iVar4 = _abs(iVar4);
          iVar5 = _abs(iVar8);
          pcVar6 = (code *)local_20;
          if (iVar5 == iVar4) {
            iVar8 = _abs(iVar8);
            pcVar6 = (code *)((iVar8 / 2 + 1) * iVar2);
          }
          local_30 = 0;
          local_2c = (code *)0x0;
          if (param_2 != 0) {
            local_30 = (int)pcVar6;
            pcVar6 = local_2c;
          }
          local_2c = pcVar6;
          if (param_4 != 0) {
            pcVar6 = *(code **)(*(int *)in_ECX[3] + 0x26c);
            guard_check_icall(&local_30,1);
            (*pcVar6)();
          }
          pcVar6 = *(code **)(*in_ECX + 0x3c);
          if (local_1c == 0) {
            iVar2 = 0;
            iVar8 = in_ECX[4];
            iVar4 = in_ECX[1];
          }
          else {
            iVar8 = in_ECX[5];
            iVar4 = in_ECX[2];
            iVar2 = local_1c;
          }
          guard_check_icall(local_20,iVar4,iVar8,param_2,iVar2,local_28);
          (*pcVar6)();
          return local_20;
        }
      }
    }
    iVar4 = local_20;
    iVar8 = *in_ECX;
    guard_check_icall(local_20,in_ECX[1],in_ECX[4],param_2,local_1c,local_28);
    (**(code **)(iVar8 + 0x3c))();
    iVar8 = *in_ECX;
    guard_check_icall(iVar4,in_ECX[2],in_ECX[5],param_2,local_1c,local_28);
    (**(code **)(iVar8 + 0x3c))();
    iVar8 = local_20;
    if ((param_4 != 0) && (in_ECX[3] != 0)) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect(*(HWND *)(in_ECX[3] + 0x20),&local_18);
      pcVar6 = *(code **)(*(int *)in_ECX[3] + 0x164);
      guard_check_icall();
      iVar8 = (*pcVar6)();
      if (iVar8 == 0) {
        if (local_1c == 0) {
          local_18.top = local_18.top + local_20;
        }
        else {
          local_18.bottom = local_18.bottom + local_20;
        }
      }
      else if (local_1c == 0) {
        local_18.left = local_18.left + local_20;
      }
      else {
        local_18.right = local_18.right + local_20;
      }
      uVar1 = FUN_00797b3d();
      iVar8 = local_20;
      if ((uVar1 & 0x10000000) != 0) {
        pHVar7 = GetParent(*(HWND *)(in_ECX[3] + 0x20));
        this = CWnd::FromHandle(pHVar7);
        CWnd::ScreenToClient(this,&local_18);
        pcVar6 = *(code **)(*(int *)in_ECX[3] + 0x234);
        guard_check_icall(&local_18,0,*local_28);
        (*pcVar6)();
        iVar8 = local_20;
      }
    }
  }
  return iVar8;
}



