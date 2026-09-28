/* CTasksPaneMenuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTasksPaneMenuButton[1] */
/* 008d38f2  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarMenuButton::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarMenuButton::_scalar_deleting_destructor_(CMFCToolBarMenuButton *this,uint param_1)

{
  FUN_00874eb0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xec);
    }
  }
  return this;
}




/* vtable slots: CTasksPaneMenuButton[53] */
/* 008d4158  CreateMenu  18 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual struct HMENU__ * __thiscall CTasksPaneMenuButton::CreateMenu(void)const 
   
   Library: Visual Studio 2015 Release */

HMENU__ * __thiscall CTasksPaneMenuButton::CreateMenu(CTasksPaneMenuButton *this)

{
  HMENU__ *pHVar1;
  
  if (*(CMFCTasksPane **)(this + 0xe8) == (CMFCTasksPane *)0x0) {
    return (HMENU__ *)0x0;
  }
  pHVar1 = CMFCTasksPane::CreateMenu(*(CMFCTasksPane **)(this + 0xe8));
  return pHVar1;
}




/* vtable slots: CTasksPaneMenuButton[54] */
/* 008d47a4  CreatePopupMenu  21 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CMFCPopupMenu * __thiscall CTasksPaneMenuButton::CreatePopupMenu(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

CMFCPopupMenu * __thiscall CTasksPaneMenuButton::CreatePopupMenu(CTasksPaneMenuButton *this)

{
  CMFCPopupMenu *pCVar1;
  
  pCVar1 = CMFCToolBarMenuButton::CreatePopupMenu((CMFCToolBarMenuButton *)this);
  if (pCVar1 == (CMFCPopupMenu *)0x0) {
    return (CMFCPopupMenu *)0x0;
  }
  *(undefined4 *)(pCVar1 + 0xf44) = 1;
  return pCVar1;
}




/* vtable slots: CTasksPaneMenuButton[0] */
/* 008d4c14  FUN_008d4c14  6 bytes, 0 callers */

undefined ** FUN_008d4c14(void)

{
  return &PTR_s_CTasksPaneMenuButton_00a00dc0;
}



