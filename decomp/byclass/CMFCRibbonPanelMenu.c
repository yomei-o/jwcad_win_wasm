/* CMFCRibbonPanelMenu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonPanelMenu[1] */
/* 008b686f  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonPanelMenu::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonPanelMenu::_scalar_deleting_destructor_(CMFCRibbonPanelMenu *this,uint param_1)

{
  ~CMFCRibbonPanelMenu(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2040);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonPanelMenu[10] */
/* 008b74e8  FUN_008b74e8  6 bytes, 0 callers */

undefined ** FUN_008b74e8(void)

{
  return &PTR_FUN_009a2320;
}




/* vtable slots: CMFCRibbonPanelMenu[0] */
/* 008b7527  FUN_008b7527  6 bytes, 0 callers */

undefined ** FUN_008b7527(void)

{
  return &PTR_s_CMFCRibbonPanelMenu_009a1ee8;
}



