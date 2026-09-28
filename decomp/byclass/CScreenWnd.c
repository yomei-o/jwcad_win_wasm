/* CScreenWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CScreenWnd[1] */
/* 0089f706  FUN_0089f706  57 bytes, 0 callers */

void FUN_0089f706(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CScreenWnd::vftable;
  FUN_007908c2();
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




/* vtable slots: CScreenWnd[89] */
/* 0089f73f  Create  178 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    public: virtual int __thiscall CScreenWnd::Create(class CMFCColorDialog *)
   
   Library: Visual Studio 2015 Release */

int __thiscall CScreenWnd::Create(CScreenWnd *this,CMFCColorDialog *param_1)

{
  HWND pHVar1;
  CWnd *pCVar2;
  int iVar3;
  HCURSOR pHVar4;
  undefined4 uVar5;
  undefined4 local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x89f74b;
  pHVar1 = GetDesktopWindow();
  pCVar2 = CWnd::FromHandle(pHVar1);
  if (pCVar2 != (CWnd *)0x0) {
    *(CMFCColorDialog **)(this + 0x80) = param_1;
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetWindowRect(*(HWND *)(pCVar2 + 0x20),&local_24);
    FUN_0079dd6d();
    iVar3 = FUN_0079dd6d();
    pHVar4 = LoadCursorW(*(HINSTANCE *)(iVar3 + 0xc),(LPCWSTR)0x3f11);
    uVar5 = AfxRegisterWndClass(0x800,pHVar4,0x10,0);
    CStringT<>(uVar5);
    local_8 = 0;
    FUN_007920d9(0xa0,local_28,&DAT_00956338,0x90000000,&local_24,0,0,0);
    FUN_00406b10();
  }
  iVar3 = FUN_008d9b68();
  return iVar3;
}




/* vtable slots: CScreenWnd[10] */
/* 0089f83e  FUN_0089f83e  6 bytes, 0 callers */

undefined ** FUN_0089f83e(void)

{
  return &PTR_FUN_0099edc8;
}



