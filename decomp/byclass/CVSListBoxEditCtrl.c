/* CVSListBoxEditCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CVSListBoxEditCtrl[1] */
/* 007e34d4  FID_conflict:`scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall CMFCToolBarEditCtrl::`scalar deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall CVSListBoxEditCtrl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void FID_conflict__scalar_deleting_destructor_(byte param_1)

{
  CMFCEditBrowseCtrl *in_ECX;
  
  *(undefined ***)in_ECX = CVSListBoxEditCtrl::vftable;
  CMFCEditBrowseCtrl::~CMFCEditBrowseCtrl(in_ECX);
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




/* vtable slots: CVSListBoxEditCtrl[10] */
/* 007e3c9a  FUN_007e3c9a  6 bytes, 0 callers */

undefined ** FUN_007e3c9a(void)

{
  return &PTR_FUN_0098a360;
}




/* vtable slots: CVSListBoxEditCtrl[0] */
/* 007e3d31  FUN_007e3d31  6 bytes, 0 callers */

undefined ** FUN_007e3d31(void)

{
  return &PTR_s_CVSListBoxEditCtrl_00989eb8;
}




/* vtable slots: CVSListBoxEditCtrl[89] */
/* 007e3e36  FUN_007e3e36  58 bytes, 0 callers */

void FUN_007e3e36(void)

{
  int *piVar1;
  HWND hWnd;
  code *pcVar2;
  BOOL BVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0xd4);
  if (piVar1 != (int *)0x0) {
    hWnd = (HWND)piVar1[8];
    pcVar2 = *(code **)(*piVar1 + 0x1bc);
    guard_check_icall();
    (*pcVar2)();
    BVar3 = IsWindow(hWnd);
    if (BVar3 != 0) {
      SetFocus(hWnd);
    }
  }
  return;
}



