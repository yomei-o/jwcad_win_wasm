/* CMFCImageEditorDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCImageEditorDialog[1] */
/* 008c8f10  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCImageEditorDialog::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCImageEditorDialog::_scalar_deleting_destructor_(CMFCImageEditorDialog *this,uint param_1)

{
  ~CMFCImageEditorDialog(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1f20);
    }
  }
  return this;
}




/* vtable slots: CMFCImageEditorDialog[64] */
/* 008c8fcf  DoDataExchange  91 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual void __thiscall CMFCImageEditorDialog::DoDataExchange(class CDataExchange *)
    protected: virtual void __thiscall COutlookOptionsDlg::DoDataExchange(class CDataExchange *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void DoDataExchange(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0078fb9c(param_1,0x4084,in_ECX + 0xd0);
  FUN_0078fb9c(param_1,0x4095,in_ECX + 0x150);
  FUN_0078fb9c(param_1,0x4087,in_ECX + 0x1d0);
  FUN_0078fb9c(param_1,0x4081,in_ECX + 0x250);
  return;
}




/* vtable slots: CMFCImageEditorDialog[10] */
/* 008c902a  FUN_008c902a  6 bytes, 0 callers */

undefined ** FUN_008c902a(void)

{
  return &PTR_FUN_009a58e8;
}




/* vtable slots: CMFCImageEditorDialog[94] */
/* 008c9069  FUN_008c9069  1011 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008c9069(void)

{
  CPane *this;
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  AFX_GLOBAL_DATA *this_00;
  int *piVar6;
  int iVar7;
  int in_ECX;
  LPRECT lpRect;
  undefined1 local_64 [8];
  int local_5c;
  undefined1 local_58 [4];
  code *local_54;
  undefined **local_50;
  undefined4 local_4c;
  int local_48;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x8c9075;
  local_48 = in_ECX;
  FUN_00798993();
  iVar4 = FUN_00404c80();
  if (iVar4 != 0) {
    FUN_00404c80();
    uVar5 = FUN_00797acc();
    if ((uVar5 & 0x400000) != 0) {
      FUN_00797c9f(0,0x400000,0);
    }
  }
  local_5c = in_ECX + 0x250;
  FUN_008c8c99(*(undefined4 *)(in_ECX + 0x348));
  local_34.left = 0;
  local_34.top = 0;
  local_34.right = 0;
  local_34.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0x170),&local_34);
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x170),&local_24);
  MapWindowPoints(*(HWND *)(in_ECX + 0x170),*(HWND *)(in_ECX + 0x20),(LPPOINT)&local_24,2);
  InflateRect(&local_24,-2,-2);
  piVar6 = (int *)(in_ECX + 0x11e0);
  FUN_007fd9c2(0);
  pcVar1 = *(code **)(*piVar6 + 800);
  guard_check_icall();
  (*pcVar1)();
  this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar4 = AFX_GLOBAL_DATA::Is32BitIcons(this_00);
  pcVar1 = *(code **)(*piVar6 + 0x330);
  guard_check_icall(0x3f0a,0,0,1,0,0,-(uint)(iVar4 != 0) & 0x3f0b);
  (*pcVar1)();
  pcVar1 = *(code **)(*piVar6 + 0x1c0);
  pcVar2 = *(code **)(*piVar6 + 0x1e4);
  guard_check_icall();
  uVar5 = (*pcVar1)();
  guard_check_icall(uVar5 | 0x30);
  (*pcVar2)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x11e0) + 0x1e4);
  pcVar2 = *(code **)(*(int *)(in_ECX + 0x11e0) + 0x1c0);
  guard_check_icall();
  uVar5 = (*pcVar2)();
  guard_check_icall(uVar5 & 0xffbff0ff);
  (*pcVar1)();
  this = (CPane *)(in_ECX + 0x11e0);
  CPane::SetBorders(this,10,5,10,5);
  piVar6 = (int *)FUN_007c23d4(local_64);
  FUN_00806771(*piVar6 * 3,0x7fff,0,0xffffffff,0xffffffff);
  pcVar1 = *(code **)(*(int *)this + 0x2a4);
  guard_check_icall(local_58,0);
  (*pcVar1)();
  local_24.bottom = local_24.top + (int)local_54 + 10;
  pcVar1 = *(code **)(*(int *)this + 0x234);
  guard_check_icall(&local_24,1,0);
  (*pcVar1)();
  if (local_34.bottom - local_34.top < local_24.bottom - local_24.top) {
    FUN_00797e71(0,0xffffffff,0xffffffff,local_34.right - local_34.left,
                 (local_24.bottom - local_24.top) + 7,0x16);
  }
  pcVar1 = *(code **)(*(int *)this + 0x238);
  guard_check_icall(&DAT_00a11c68,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x13,0);
  (*pcVar1)();
  *(undefined4 *)(in_ECX + 0x123c) = *(undefined4 *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x1d94) = 0;
  local_44.left = 0;
  local_44.top = 0;
  local_44.right = 0;
  local_44.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0xf0),&local_44);
  MapWindowPoints(*(HWND *)(in_ECX + 0xf0),*(HWND *)(in_ECX + 0x20),(LPPOINT)&local_44,2);
  InflateRect(&local_44,-2,-2);
  local_4c = 0;
  local_50 = CPalette::vftable;
  *(undefined4 *)(in_ECX + 0x1178) = 1;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x354) < 9) {
    FUN_008c8f43(&local_50);
  }
  else {
    FUN_00823040(L"Other",1,1);
    FUN_00824c6d(1);
    FUN_00824c36(1);
  }
  local_54 = *(code **)(*(int *)(in_ECX + 0x378) + 0x454);
  guard_check_icall();
  (*local_54)();
  FUN_00824a91(0);
  local_8 = 0xffffffff;
  local_50 = CPalette::vftable;
  FUN_00416100();
  iVar3 = local_48;
  lpRect = (LPRECT)(in_ECX + 0x368);
  GetClientRect(*(HWND *)(local_48 + 0x1f0),lpRect);
  MapWindowPoints(*(HWND *)(iVar3 + 0x1f0),*(HWND *)(iVar3 + 0x20),(LPPOINT)lpRect,2);
  iVar4 = *(int *)(iVar3 + 0x34c);
  iVar7 = ((*(int *)(iVar3 + 0x370) - iVar4) + lpRect->left) / 2;
  lpRect->left = iVar7;
  *(int *)(iVar3 + 0x370) = iVar7 + iVar4;
  iVar4 = ((*(int *)(iVar3 + 0x374) - *(int *)(iVar3 + 0x350)) + *(int *)(iVar3 + 0x36c)) / 2;
  *(int *)(iVar3 + 0x36c) = iVar4;
  *(int *)(iVar3 + 0x374) = iVar4 + *(int *)(iVar3 + 0x350);
  ((LPRECT)(iVar3 + 0x358))->left = lpRect->left;
  *(undefined4 *)(iVar3 + 0x35c) = *(undefined4 *)(in_ECX + 0x36c);
  *(undefined4 *)(iVar3 + 0x360) = *(undefined4 *)(in_ECX + 0x370);
  *(undefined4 *)(iVar3 + 0x364) = *(undefined4 *)(in_ECX + 0x374);
  InflateRect((LPRECT)(iVar3 + 0x358),4,4);
  *(LONG *)(local_48 + 0x2d0) = lpRect->left;
  *(undefined4 *)(local_48 + 0x2d4) = *(undefined4 *)(in_ECX + 0x36c);
  *(undefined4 *)(local_48 + 0x2d8) = *(undefined4 *)(in_ECX + 0x370);
  *(undefined4 *)(local_48 + 0x2dc) = *(undefined4 *)(in_ECX + 0x374);
  FUN_00797c5d(0x10000,0,0);
  FUN_008d9b68();
  return;
}



