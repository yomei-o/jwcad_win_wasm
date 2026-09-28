/* CMFCShadowWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCShadowWnd[0], CMiniFrameWnd[0] */
/* 007d112d  FUN_007d112d  6 bytes, 0 callers */

undefined ** FUN_007d112d(void)

{
  return &PTR_s_CMiniFrameWnd_009868cc;
}




/* vtable slots: CMFCShadowWnd[1] */
/* 0081ba81  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    private: virtual void * __thiscall CMFCShadowWnd::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCShadowWnd::_scalar_deleting_destructor_(CMFCShadowWnd *this,uint param_1)

{
  FUN_0081ba32();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2b8);
    }
  }
  return this;
}




/* vtable slots: CMFCShadowWnd[114] */
/* 0081c531  FUN_0081c531  230 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0081c531(void)

{
  code *pcVar1;
  int iVar2;
  HCURSOR pHVar3;
  uint uVar4;
  HWND pHVar5;
  CWnd *pCVar6;
  int in_ECX;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x81c53d;
  iVar2 = FUN_007c2511();
  if (8 < *(int *)(iVar2 + 0x1ac)) {
    uVar8 = 0;
    uVar7 = 0x10;
    pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    uVar7 = AfxRegisterWndClass(0x800,pHVar3,uVar7,uVar8);
    CStringT<>(uVar7);
    local_8 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    uVar4 = FUN_00797acc();
    if ((uVar4 & 0x400000) != 0) {
      *(undefined4 *)(in_ECX + 0x2b0) = 1;
    }
    pHVar5 = GetParent(*(HWND *)(*(int *)(in_ECX + 0x130) + 0x20));
    pCVar6 = CWnd::FromHandle(pHVar5);
    iVar2 = FUN_007d105c(0x80080,local_28,&DAT_00956338,0x80000000,&local_24,pCVar6,0);
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*(int *)(in_ECX + 0x138) + 0x2c);
      guard_check_icall(*(undefined4 *)(in_ECX + 0x134),0x5a5a5a,0,0x32);
      (*pcVar1)();
    }
    FUN_00406b10();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCShadowWnd[10] */
/* 0081d4bb  FUN_0081d4bb  6 bytes, 0 callers */

undefined ** FUN_0081d4bb(void)

{
  return &PTR_FUN_0098e948;
}



