/* CMFCRibbonMiniToolBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonMiniToolBar[1] */
/* 0089f29c  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonMiniToolBar::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonMiniToolBar::_scalar_deleting_destructor_(CMFCRibbonMiniToolBar *this,uint param_1)

{
  ~CMFCRibbonMiniToolBar(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2050);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonMiniToolBar[119], CMFCRibbonPanelMenu[119] */
/* 0089f2ff  FUN_0089f2ff  20 bytes, 0 callers */

undefined4 FUN_0089f2ff(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0x1f60) != 0) && (*(int *)(in_ECX + 0x1f58) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonMiniToolBar[10] */
/* 0089f313  FUN_0089f313  6 bytes, 0 callers */

undefined ** FUN_0089f313(void)

{
  return &PTR_FUN_0099e998;
}




/* vtable slots: CMFCRibbonMiniToolBar[0] */
/* 0089f319  FUN_0089f319  6 bytes, 0 callers */

undefined ** FUN_0089f319(void)

{
  return &PTR_s_CMFCRibbonMiniToolBar_0099e700;
}




/* vtable slots: CMFCRibbonMiniToolBar[123], CMFCRibbonPanelMenu[123] */
/* 008b70c6  FUN_008b70c6  50 bytes, 0 callers */

void FUN_008b70c6(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  FUN_0081c9a2(param_1);
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1178) + 0x458);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonMiniToolBar[131], CMFCRibbonPanelMenu[131] */
/* 008b746c  FUN_008b746c  52 bytes, 1 callers */

void FUN_008b746c(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1f50) != 0) {
    FUN_0081d448();
    return;
  }
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x2a8);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonMiniToolBar[118], CMFCRibbonPanelMenu[118] */
/* 008b75dc  FUN_008b75dc  33 bytes, 0 callers */

undefined4 FUN_008b75dc(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x2038) == 0) && (iVar1 = FUN_0082f53f(), iVar1 == 0)) {
    return 0;
  }
  return 1;
}




/* vtable slots: CMFCRibbonMiniToolBar[122], CMFCRibbonPanelMenu[122] */
/* 008b7616  FUN_008b7616  24 bytes, 0 callers */

undefined4 FUN_008b7616(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x201c) == 0) ||
     (uVar1 = 0, *(int *)(*(int *)(in_ECX + 0x201c) + 0x98) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonMiniToolBar[121], CMFCRibbonPanelMenu[121] */
/* 008b762e  FUN_008b762e  12 bytes, 0 callers */

bool FUN_008b762e(void)

{
  int in_ECX;
  
  return 0 < *(int *)(in_ECX + 0x1ec4);
}



