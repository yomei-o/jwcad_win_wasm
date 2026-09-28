/* CDockSite -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDockSite[1] */
/* 008604d2  FUN_008604d2  51 bytes, 0 callers */

void FUN_008604d2(byte param_1)

{
  FUN_00860448();
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




/* vtable slots: CDockSite[97] */
/* 008607ff  FUN_008607ff  48 bytes, 0 callers */

bool FUN_008607ff(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  bool bVar3;
  
  if (param_1 == 0) {
    bVar3 = false;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x178);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}




/* vtable slots: CDockSite[157] */
/* 00860a56  FUN_00860a56  953 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00860a56(CObject *param_1,int param_2,RECT *param_3)

{
  code *pcVar1;
  int iVar2;
  RECT *pRVar3;
  __POSITION *p_Var4;
  BOOL BVar5;
  int *in_ECX;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  CObject *pCStack_80;
  LONG LStack_7c;
  int local_58;
  int local_54;
  uint local_50;
  tagPOINT local_4c;
  int local_44;
  int local_40;
  uint local_3c;
  CObject *local_38;
  char local_31;
  RECT *local_30;
  char local_29;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_38 = param_1;
  local_30 = param_3;
  SetRectEmpty(&local_18);
  if (param_3 != (RECT *)0x0) {
    CopyRect(&local_28,param_3);
    local_18.left = local_28.left;
    local_18.top = local_28.top;
    local_18.right = local_28.right;
    local_18.bottom = local_28.bottom;
    param_1 = local_38;
  }
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  local_3c = (uint)(iVar2 == 0);
  local_50 = (uint)(iVar2 != 0);
  pcVar1 = *(code **)(*(int *)param_1 + 0x260);
  guard_check_icall();
  (*pcVar1)();
  LStack_7c = 0x860afc;
  iVar2 = FUN_007a198a();
  if (iVar2 != 0) {
    return;
  }
  local_29 = '\0';
  local_31 = '\0';
  if (param_2 == 1) {
    local_4c.x = 0;
    local_4c.y = 0;
    GetCursorPos(&local_4c);
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    LStack_7c = 0x860b3f;
    GetWindowRect((HWND)in_ECX[8],&local_28);
    LStack_7c = local_4c.x;
    pCStack_80 = (CObject *)0x860b50;
    pRVar3 = (RECT *)FUN_00861cd8();
    local_29 = local_31;
LAB_00860ccc:
    if (pRVar3 != (RECT *)0x0) {
      pcVar1 = *(code **)(pRVar3->left + 0x60);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        pcVar1 = *(code **)(*(int *)local_38 + 0x280);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) goto LAB_00860d6e;
        pcVar1 = *(code **)(pRVar3->left + 0x40);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) goto LAB_00860d6e;
      }
      LStack_7c = 0x860d24;
      pRVar3 = (RECT *)FUN_007a198a();
      if (pRVar3 == (RECT *)0x0) {
LAB_00860e0a:
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      local_30 = pRVar3;
      if (local_29 == '\0') {
        FUN_0044f2d0();
      }
    }
  }
  else {
    if (param_2 == 2) {
      LStack_7c = 0x860bf5;
      iVar2 = FUN_007a198a();
      if (iVar2 == 0) goto LAB_00860b6d;
      local_30 = *(RECT **)(param_1 + 0x208);
LAB_00860ca0:
      LStack_7c = 0x860cb1;
      CopyRect(&local_28,(RECT *)(param_1 + 0x218));
      local_18.left = local_28.left;
      local_18.top = local_28.top;
      local_18.right = local_28.right;
      local_18.bottom = local_28.bottom;
      FUN_0079e8b8();
      pRVar3 = local_30;
      goto LAB_00860ccc;
    }
    if (param_2 == 4) {
LAB_00860b6d:
      iVar2 = in_ECX[0x4e];
      iVar6 = *(int *)(param_1 + 0x200);
      if (DAT_00a13b28 == 0) {
        if (param_2 == 2) {
          if (iVar6 < iVar2) {
            p_Var4 = CObList::FindIndex((CObList *)(in_ECX + 0x4b),iVar6);
            if (p_Var4 == (__POSITION *)0x0) goto LAB_00860e0a;
            local_30 = *(RECT **)(p_Var4 + 8);
            local_29 = '\x01';
          }
          else {
            BVar5 = IsRectEmpty((RECT *)(param_1 + 0x218));
            if (BVar5 != 0) goto LAB_00860c7e;
            pCStack_80 = (CObject *)((RECT *)(param_1 + 0x218))->left;
            LStack_7c = *(LONG *)(param_1 + 0x21c);
            local_30 = (RECT *)FUN_008610b0();
            param_1 = local_38;
          }
          goto LAB_00860c77;
        }
        if ((param_2 == 4) && (local_30 != (RECT *)0x0)) {
          CopyRect((LPRECT)&pCStack_80,local_30);
          local_30 = (RECT *)FUN_008610b0();
          goto LAB_00860c77;
        }
      }
      else {
        if ((iVar2 + -1 < iVar6) &&
           (local_30 = (RECT *)0x0, iVar6 - iVar2 != -1 && -1 < (iVar6 - iVar2) + 1)) {
          do {
            LStack_7c = 0x860bb0;
            FUN_00860505();
            iVar6 = *(int *)(param_1 + 0x200);
            local_30 = (RECT *)((int)&local_30->left + 1);
          } while ((int)local_30 < (iVar6 - iVar2) + 1);
        }
        p_Var4 = CObList::FindIndex((CObList *)(in_ECX + 0x4b),iVar6);
        if (p_Var4 == (__POSITION *)0x0) goto LAB_00860e0a;
        local_30 = *(RECT **)(p_Var4 + 8);
LAB_00860c77:
        if (local_30 != (RECT *)0x0) goto LAB_00860ca0;
      }
LAB_00860c7e:
      LStack_7c = 0x860c94;
      FUN_00860505();
      local_30 = *(RECT **)(in_ECX[0x4d] + 8);
      goto LAB_00860ca0;
    }
  }
  LStack_7c = 0x860d6c;
  pRVar3 = (RECT *)FUN_00860505();
LAB_00860d6e:
  iVar2 = pRVar3->left;
  LStack_7c = param_2;
  pCStack_80 = local_38;
  guard_check_icall();
  (**(code **)(iVar2 + 0x1c))();
  uVar8 = 0;
  piVar7 = &local_58;
  pcVar1 = *(code **)(*(int *)local_38 + 0x260);
  uVar9 = local_50;
  guard_check_icall(piVar7,0,local_50);
  (*pcVar1)();
  if ((local_58 != local_44) || (local_54 != local_40)) {
    if (local_3c == 0) {
      local_58 = local_54;
    }
    FUN_00861bb1(pRVar3,local_58,1);
  }
  CObList::AddTail((CObList *)(in_ECX + 0x44),local_38);
  pcVar1 = *(code **)(*in_ECX + 0x2a8);
  guard_check_icall(piVar7,uVar8,uVar9);
  (*pcVar1)();
  FUN_00797f20();
  return;
}




/* vtable slots: CDockSite[10] */
/* 00861165  FUN_00861165  6 bytes, 0 callers */

undefined ** FUN_00861165(void)

{
  return &PTR_FUN_009978f8;
}




/* vtable slots: CDockSite[0] */
/* 0086116b  FUN_0086116b  6 bytes, 0 callers */

undefined ** FUN_0086116b(void)

{
  return &PTR_s_CDockSite_00997564;
}




/* vtable slots: CDockSite[166] */
/* 008619ad  FUN_008619ad  295 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008619ad(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int _X;
  int _X_00;
  int local_24;
  int *local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_20 = param_1;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  if ((param_1[2] - *param_1 == local_18.right - local_18.left) &&
     (param_1[3] - local_20[1] == local_18.bottom - local_18.top)) {
    local_1c = *(int **)(in_ECX + 0x130);
    iVar2 = 0;
    while (local_1c != (int *)0x0) {
      FUN_0044f2d0(&local_1c);
      iVar2 = FUN_008571d5();
    }
  }
  else {
    _X_00 = (param_1[3] - local_20[1]) - (local_18.bottom - local_18.top);
    _X = (param_1[2] - *param_1) - (local_18.right - local_18.left);
    local_24 = *(int *)(in_ECX + 0x130);
    iVar2 = 0;
    if (local_24 != 0) {
      iVar2 = in_ECX + 300;
      do {
        puVar3 = (undefined4 *)FUN_0044f2d0(&local_24);
        local_1c = (int *)*puVar3;
        if (_X != 0) {
          pcVar1 = *(code **)(*local_1c + 0x3c);
          iVar4 = _abs(_X);
          guard_check_icall(local_20,2,0 < _X,iVar4);
          (*pcVar1)();
        }
        if (_X_00 != 0) {
          pcVar1 = *(code **)(*local_1c + 0x3c);
          iVar4 = _abs(_X_00);
          guard_check_icall(local_20,6,0 < _X_00,iVar4);
          (*pcVar1)();
        }
      } while (local_24 != 0);
    }
  }
  return iVar2;
}



