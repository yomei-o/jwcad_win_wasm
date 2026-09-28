/* CMFCOutlookBarToolBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCOutlookBarToolBar[1] */
/* 00896f80  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCOutlookBarToolBar::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCOutlookBarToolBar::_scalar_deleting_destructor_(CMFCOutlookBarToolBar *this,uint param_1)

{
  FUN_00896ebd();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xd60);
    }
  }
  return this;
}




/* vtable slots: CMFCOutlookBarToolBar[249] */
/* 00896fe6  FUN_00896fe6  569 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00896fe6(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  CObject *pCVar4;
  int in_ECX;
  int iVar5;
  undefined1 local_4c [4];
  int local_48;
  int local_44;
  undefined8 local_40;
  int local_38;
  CObject *local_34;
  undefined8 local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar1 = FUN_007c2511();
  local_40 = 1.0;
  if (*(int *)(iVar1 + 0x1e8) != 0) {
    local_40 = *(double *)(iVar1 + 0x1e0);
  }
  FUN_007fe0a1(&local_28);
  if ((local_28 == 0) && (local_24 == 0)) {
    local_28 = 0x10;
    local_24 = 0x10;
  }
  local_44 = local_24 + 0xe;
  local_20 = local_28 + 10;
  local_30 = (double)CONCAT44(local_20,(undefined4)local_30);
  local_48 = local_44;
  if (local_40 != 1.0) {
    local_30 = (double)local_20;
    local_20 = thunk_FUN_008d99f0();
    local_30 = (double)local_48;
    local_44 = thunk_FUN_008d99f0();
  }
  iVar5 = local_20;
  local_38 = 0;
  local_24 = 0;
  iVar1 = 0;
  if ((*(int *)(in_ECX + 0xd14) != 0) &&
     (local_38 = local_44, local_24 = local_20, piVar2 = (int *)FUN_0081507c(local_4c),
     iVar1 = iVar5, local_20 <= *piVar2 + 10)) {
    piVar2 = (int *)FUN_0081507c(&local_40);
    iVar1 = *piVar2 + 10;
    local_24 = iVar1;
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  if ((iVar1 == 0) && (local_38 == 0)) {
    local_1c = *(int *)(in_ECX + 0xc48);
  }
  else {
    local_1c = *(int *)(in_ECX + 0xc48) + -1;
  }
  local_1c = local_1c - (((local_18.right - local_18.left) - iVar1) + 2) / (local_20 + -2);
  local_30 = (double)CONCAT44(*(int *)(in_ECX + 0xc44),(undefined4)local_30);
  local_40._4_4_ = (local_18.right - iVar1) + 2;
  iVar5 = *(int *)(in_ECX + 0xc44);
  while (iVar5 != 0) {
    puVar3 = (undefined4 *)FUN_0049ad10((int)&local_30 + 4);
    local_34 = (CObject *)*puVar3;
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,local_34);
    if ((local_1c < 1) || (pCVar4 != (CObject *)0x0)) {
      local_48 = local_44;
      iVar5 = local_20;
      if (local_34 == *(CObject **)(in_ECX + 0xd14)) {
        local_48 = local_38;
        iVar5 = iVar1;
      }
      FUN_0080554f(local_40._4_4_,0xffffffff,local_40._4_4_ + iVar5,local_48);
      local_40._4_4_ = local_40._4_4_ + (2 - local_20);
    }
    else {
      if (*(int *)(in_ECX + 0xd14) != 0) {
        CObList::AddHead((CObList *)(*(int *)(in_ECX + 0xd14) + 0x110),local_34);
      }
      FUN_0080554f(0,0,0,0);
      local_1c = local_1c + -1;
    }
    iVar1 = local_24;
    iVar5 = local_30._4_4_;
  }
  FUN_008065ff();
  return;
}




/* vtable slots: CMFCOutlookBarToolBar[10] */
/* 008979f6  FUN_008979f6  6 bytes, 0 callers */

undefined ** FUN_008979f6(void)

{
  return &PTR_FUN_0099d3a8;
}




/* vtable slots: CMFCOutlookBarToolBar[0] */
/* 00897a08  FUN_00897a08  6 bytes, 0 callers */

undefined ** FUN_00897a08(void)

{
  return &PTR_s_CMFCOutlookBarToolBar_0099ca8c;
}




/* vtable slots: CMFCOutlookBarToolBar[257] */
/* 00897f15  OnCustomizeMode  35 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCOutlookBarToolBar::OnCustomizeMode(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCOutlookBarToolBar::OnCustomizeMode(CMFCOutlookBarToolBar *this,int param_1)

{
  FUN_008006cc(param_1);
  FUN_007979e8(param_1 == 0);
  return;
}




/* vtable slots: CMFCOutlookBarToolBar[250] */
/* 00898cb2  FUN_00898cb2  177 bytes, 0 callers */

undefined4 FUN_00898cb2(undefined4 param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  WPARAM WVar4;
  int in_ECX;
  WPARAM local_8;
  
  uVar2 = FUN_007fc033(param_1);
  if (-1 < (int)uVar2) {
    local_8 = 0xffffffff;
    iVar3 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                      ((CMap<unsigned_int,unsigned_int,int,int> *)(in_ECX + 0xd40),uVar2,
                       (int *)&local_8);
    if (iVar3 != 0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0xd5c) + 0x20c);
      guard_check_icall();
      WVar4 = (*pcVar1)();
      if (WVar4 != local_8) {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0xd5c) + 0x214);
        guard_check_icall(local_8);
        iVar3 = (*pcVar1)();
        if ((iVar3 != 0) && (iVar3 = FUN_0079296c(), iVar3 != 0)) {
          iVar3 = FUN_0079296c();
          SendMessageW(*(HWND *)(iVar3 + 0x20),DAT_00a13150,local_8,*(LPARAM *)(in_ECX + 0xd5c));
        }
        return 1;
      }
    }
  }
  return 0;
}




/* vtable slots: CMFCOutlookBarToolBar[145] */
/* 00898f9e  FUN_00898f9e  156 bytes, 0 callers */

void FUN_00898f9e(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  CMFCToolBar *in_ECX;
  uint uVar4;
  int local_8;
  
  uVar4 = 0;
  if (0 < *(int *)(in_ECX + 0xc48)) {
    do {
      uVar2 = CMFCToolBar::GetButtonStyle(in_ECX,uVar4);
      local_8 = -1;
      uVar2 = uVar2 & 0xffeeffff;
      iVar3 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                        ((CMap<unsigned_int,unsigned_int,int,int> *)(in_ECX + 0xd40),uVar4,&local_8)
      ;
      if (iVar3 != 0) {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0xd5c) + 0x20c);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 == local_8) {
          uVar2 = uVar2 | 0x10000;
        }
        pcVar1 = *(code **)(*(int *)in_ECX + 0x374);
        guard_check_icall(uVar4,uVar2 | 2);
        (*pcVar1)();
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < *(int *)(in_ECX + 0xc48));
  }
  return;
}




/* vtable slots: CMFCOutlookBarToolBar[235] */
/* 00899091  FUN_00899091  25 bytes, 0 callers */

undefined4 FUN_00899091(int param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,(CSimpleStringT<wchar_t,0> *)(param_1 + 0x2c));
  return 1;
}



