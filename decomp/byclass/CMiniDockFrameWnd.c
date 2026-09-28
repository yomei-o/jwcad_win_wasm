/* CMiniDockFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMiniDockFrameWnd[1] */
/* 007bd03f  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMiniDockFrameWnd::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMiniDockFrameWnd::_scalar_deleting_destructor_(CMiniDockFrameWnd *this,uint param_1)

{
  FUN_007bcff6();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x228);
    }
  }
  return this;
}




/* vtable slots: CMiniDockFrameWnd[114] */
/* 007bd647  FUN_007bd647  380 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007bd647(undefined4 param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  HMENU pHVar3;
  CMenu *pCVar4;
  HWND pHVar5;
  undefined4 uVar6;
  int in_ECX;
  UINT in_stack_ffffffd4;
  LPSTR in_stack_ffffffd8;
  int in_stack_ffffffdc;
  LPCWSTR local_14;
  
  *(undefined4 *)(in_ECX + 0xf4) = 1;
  iVar2 = FUN_007d105c(0,0,&DAT_00956338,~(param_2 << 9) & 0x800 | 0x80c83300,&DAT_00a00354,param_1,
                       0);
  if (iVar2 != 0) {
    pHVar3 = GetSystemMenu(*(HWND *)(in_ECX + 0x20),0);
    pCVar4 = CMenu::FromHandle(pHVar3);
    if (pCVar4 != (CMenu *)0x0) {
      DeleteMenu(*(HMENU *)(pCVar4 + 4),0xf000,0);
      DeleteMenu(*(HMENU *)(pCVar4 + 4),0xf020,0);
      DeleteMenu(*(HMENU *)(pCVar4 + 4),0xf030,0);
      DeleteMenu(*(HMENU *)(pCVar4 + 4),0xf120,0);
      CStringT<>();
      iVar2 = FID_conflict_LoadStringA
                        ((HINSTANCE)0xf011,in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc);
      if (iVar2 != 0) {
        DeleteMenu(*(HMENU *)(pCVar4 + 4),0xf060,0);
        AppendMenuW(*(HMENU *)(pCVar4 + 4),0,0xf060,local_14);
      }
      FUN_00406b10();
    }
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x130) + 0x1a4);
    guard_check_icall(param_1,(-(uint)((param_2 & 0x5000) != 0) & 0xfffff000) + 0x2000 |
                              param_2 & 0x40 | 0x50000000,0xe81f);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      pHVar5 = SetParent(*(HWND *)(in_ECX + 0x150),*(HWND *)(in_ECX + 0x20));
      CWnd::FromHandle(pHVar5);
      uVar6 = 1;
      goto LAB_007bd7b4;
    }
  }
  uVar6 = 0;
LAB_007bd7b4:
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  return uVar6;
}




/* vtable slots: CMiniDockFrameWnd[10] */
/* 007bdc3e  FUN_007bdc3e  6 bytes, 0 callers */

undefined ** FUN_007bdc3e(void)

{
  return &PTR_FUN_00982188;
}




/* vtable slots: CMiniDockFrameWnd[0] */
/* 007bdc4a  FUN_007bdc4a  6 bytes, 0 callers */

undefined ** FUN_007bdc4a(void)

{
  return &PTR_s_CMiniDockFrameWnd_00981e74;
}




/* vtable slots: CMiniDockFrameWnd[94] */
/* 007be469  RecalcLayout  92 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    public: virtual void __thiscall CMiniDockFrameWnd::RecalcLayout(int)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release,
   Visual Studio 2012 Release */

void __thiscall CMiniDockFrameWnd::RecalcLayout(CMiniDockFrameWnd *this,int param_1)

{
  undefined1 local_210 [520];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(this + 0xf4) == 0) {
    FUN_0079c654(param_1);
    FUN_00797b67(local_210,0x104);
    FUN_007c16be(*(undefined4 *)(this + 0x20),local_210);
  }
  return;
}



