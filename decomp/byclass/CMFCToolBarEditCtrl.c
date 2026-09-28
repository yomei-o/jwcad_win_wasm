/* CMFCToolBarEditCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarEditCtrl[1] */
/* 008d2260  FID_conflict:`scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall CMFCToolBarEditCtrl::`scalar deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall CVSListBoxEditCtrl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void FID_conflict__scalar_deleting_destructor_(byte param_1)

{
  CMFCEditBrowseCtrl *in_ECX;
  
  *(undefined ***)in_ECX = CMFCToolBarEditCtrl::vftable;
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




/* vtable slots: CMFCToolBarEditCtrl[10] */
/* 008d241b  FUN_008d241b  6 bytes, 0 callers */

undefined ** FUN_008d241b(void)

{
  return &PTR_FUN_009a7d60;
}




/* vtable slots: CMFCToolBarEditCtrl[67] */
/* 008d2dc6  FUN_008d2dc6  259 bytes, 0 callers */

undefined4 FUN_008d2dc6(int param_1)

{
  SHORT SVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  undefined4 uVar5;
  CWnd *in_ECX;
  UINT Msg;
  
  if (*(int *)(param_1 + 4) == 0x100) {
    if (*(int *)(param_1 + 8) == 9) {
      pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
      pCVar4 = CWnd::FromHandle(pHVar3);
      if (pCVar4 != (CWnd *)0x0) {
        pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
        pCVar4 = CWnd::FromHandle(pHVar3);
        pHVar3 = GetNextDlgTabItem(*(HWND *)(pCVar4 + 0x20),*(HWND *)(in_ECX + 0x20),0);
        CWnd::FromHandle(pHVar3);
        goto LAB_008d2e31;
      }
    }
    else if ((*(int *)(param_1 + 8) == 0x1b) && (iVar2 = FUN_00792b4c(), iVar2 != 0)) {
      FUN_00792b4c();
LAB_008d2e31:
      FUN_00797df8();
      return 1;
    }
    pHVar3 = GetFocus();
    pCVar4 = CWnd::FromHandle(pHVar3);
    if ((pCVar4 == in_ECX) && (SVar1 = GetKeyState(0x11), SVar1 < 0)) {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0x2e) {
        Msg = 0x303;
      }
      else if (iVar2 == 0x43) {
        Msg = 0x301;
      }
      else if (iVar2 == 0x56) {
        Msg = 0x302;
      }
      else if (iVar2 == 0x58) {
        Msg = 0x300;
      }
      else {
        if (iVar2 != 0x5a) goto LAB_008d2ebb;
        Msg = 199;
      }
      SendMessageW(*(HWND *)(in_ECX + 0x20),Msg,0,0);
      return 1;
    }
  }
LAB_008d2ebb:
  uVar5 = FUN_007d779e(param_1);
  return uVar5;
}



