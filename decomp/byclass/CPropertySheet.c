/* CPropertySheet -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPropertySheet[1] */
/* 0079fda0  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CPropertySheet::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CPropertySheet::_scalar_deleting_destructor_(CPropertySheet *this,uint param_1)

{
  ~CPropertySheet(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xe0);
    }
  }
  return this;
}




/* vtable slots: CPropertySheet[10] */
/* 007a0656  FUN_007a0656  6 bytes, 0 callers */

undefined ** FUN_007a0656(void)

{
  return &PTR_FUN_0097e828;
}




/* vtable slots: CPropertySheet[0] */
/* 007a0714  FUN_007a0714  6 bytes, 0 callers */

undefined ** FUN_007a0714(void)

{
  return &PTR_s_CPropertySheet_0097e564;
}




/* vtable slots: CPropertySheet[91] */
/* 007a0b0c  FUN_007a0b0c  544 bytes, 3 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007a0b0c(void)

{
  HWND pHVar1;
  undefined4 uVar2;
  CWnd *in_ECX;
  int iVar3;
  uint uVar4;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0xd0) == 0) &&
     (pHVar1 = GetDlgItem(*(HWND *)(in_ECX + 0x20),0x3020), pHVar1 != (HWND)0x0)) {
    CWnd::ModifyStyle(pHVar1,0x200,0,0);
  }
  if ((*(uint *)(in_ECX + 0x84) & 0x1000020) == 0) {
    pHVar1 = GetDlgItem(*(HWND *)(in_ECX + 0x20),0x3020);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(pHVar1,&local_18);
    CWnd::ScreenToClient(in_ECX,&local_18);
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0x20;
    MapDialogRect(*(HWND *)(in_ECX + 0x20),&local_28);
    if (local_28.bottom < local_18.bottom) {
      iVar3 = (local_18.bottom - local_18.top) - local_28.bottom;
      SetWindowPos(pHVar1,(HWND)0x0,0,0,local_18.right - local_18.left,local_28.bottom,0x16);
      uVar4 = 0;
      do {
        pHVar1 = GetDlgItem(*(HWND *)(in_ECX + 0x20),*(int *)((int)&DAT_00a00370 + uVar4));
        if (pHVar1 != (HWND)0x0) {
          GetWindowRect(pHVar1,&local_18);
          CWnd::ScreenToClient(in_ECX,&local_18);
          SetWindowPos(pHVar1,(HWND)0x0,local_18.left,local_18.top - iVar3,0,0,0x15);
        }
        uVar4 = uVar4 + 4;
      } while (uVar4 < 0x10);
      GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
      FUN_00797e71(0,0,0,local_18.right - local_18.left,(local_18.bottom - local_18.top) - iVar3,
                   0x16);
    }
  }
  uVar4 = 0;
  uVar2 = FUN_007922d4();
  if ((*(int *)(in_ECX + 0xd4) != 0) && ((*(uint *)(in_ECX + 0x84) & 0x1000020) == 0)) {
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_28);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    pHVar1 = GetDlgItem(*(HWND *)(in_ECX + 0x20),1);
    if (pHVar1 != (HWND)0x0) {
      GetWindowRect(pHVar1,&local_18);
      FUN_00797e71(0,0,0,local_28.right - local_28.left,local_18.top - local_28.top,0x16);
    }
    do {
      pHVar1 = GetDlgItem(*(HWND *)(in_ECX + 0x20),*(int *)((int)&DAT_00a00370 + uVar4));
      if (pHVar1 != (HWND)0x0) {
        ShowWindow(pHVar1,0);
        EnableWindow(pHVar1,0);
      }
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x10);
  }
  uVar4 = FUN_00797b3d();
  if ((uVar4 & 0x40000000) == 0) {
    FUN_00791d1f(0);
  }
  return uVar2;
}



