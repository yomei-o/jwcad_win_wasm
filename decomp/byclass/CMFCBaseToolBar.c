/* CMFCBaseToolBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCBaseToolBar[156], CMFCColorBar[156], CMFCDropDownToolBar[156], CMFCImageEditorPaletteBar[156], CMFCMenuBar[156], CMFCOutlookBarPane[156], CMFCOutlookBarToolBar[156], CMFCPopupMenuBar[156], CMFCPrintPreviewToolBar[156], CMFCRibbonPanelMenuBar[156], CMFCTasksPaneToolBar[156], CMFCToolBar[156] */
/* 007c25ee  FUN_007c25ee  60 bytes, 0 callers */

void FUN_007c25ee(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_14;
  
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    uVar3 = 0x28;
    uStack_14 = 0x10;
  }
  else {
    uVar3 = 0x10;
    uStack_14 = 0x28;
  }
  *param_1 = uStack_14;
  param_1[1] = uVar3;
  return;
}




/* vtable slots: CMFCBaseToolBar[1] */
/* 007faa01  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCBaseToolBar::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCBaseToolBar::_scalar_deleting_destructor_(CMFCBaseToolBar *this,uint param_1)

{
  *(undefined ***)this = vftable;
  CPane::~CPane((CPane *)this);
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




/* vtable slots: CMFCBaseToolBar[10] */
/* 007faa6a  FUN_007faa6a  6 bytes, 0 callers */

undefined ** FUN_007faa6a(void)

{
  return &PTR_FUN_0098ba48;
}




/* vtable slots: CMFCBaseToolBar[0] */
/* 007faa70  FUN_007faa70  6 bytes, 0 callers */

undefined ** FUN_007faa70(void)

{
  return &PTR_s_CMFCBaseToolBar_0098b6e0;
}




/* vtable slots: CMFCBaseToolBar[193], CMFCColorBar[193], CMFCDropDownToolBar[193], CMFCImageEditorPaletteBar[193], CMFCMenuBar[193], CMFCOutlookBarPane[193], CMFCOutlookBarToolBar[193], CMFCPopupMenuBar[193], CMFCPrintPreviewToolBar[193], CMFCRibbonPanelMenuBar[193], CMFCTasksPaneToolBar[193], CMFCToolBar[193] */
/* 007faa76  FUN_007faa76  106 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007faa76(void)

{
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  if (local_18.right - local_18.left != *(int *)(in_ECX + 0x148) - *(int *)(in_ECX + 0x140)) {
    InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,1);
    UpdateWindow(*(HWND *)(in_ECX + 0x20));
  }
  return;
}



