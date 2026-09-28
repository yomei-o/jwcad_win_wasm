/* COleBusyDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleBusyDialog[1] */
/* 00814a4a  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall COleBusyDialog::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall COleBusyDialog::_scalar_deleting_destructor_(COleBusyDialog *this,uint param_1)

{
  *(undefined ***)this = CCommonDialog::vftable;
  FUN_00797fb6();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xe0);
    }
  }
  return this;
}




/* vtable slots: COleBusyDialog[93] */
/* 00814ace  FUN_00814ace  139 bytes, 2 callers */

int FUN_00814ace(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  CWnd *in_ECX;
  CWnd *local_8;
  
  uVar1 = 0;
  if (*(int *)(in_ECX + 0x94) != 0) {
    uVar1 = *(undefined4 *)(*(int *)(in_ECX + 0x94) + 0x20);
  }
  local_8 = in_ECX;
  uVar1 = FUN_0079f613(uVar1,&local_8);
  *(undefined4 *)(in_ECX + 0xb8) = uVar1;
  FUN_00790fd2(in_ECX);
  uVar2 = OleUIBusyW(in_ECX + 0xb0);
  FUN_0079134d();
  CWnd::Detach(in_ECX);
  if (local_8 != (CWnd *)0x0) {
    EnableWindow((HWND)local_8,1);
  }
  iVar3 = 2;
  if (uVar2 != 2) {
    if (uVar2 == 0x75) {
      iVar3 = 1;
    }
    else if (uVar2 != 0x76) {
      if (uVar2 == 0x77) {
        iVar3 = 3;
      }
      else {
        iVar3 = COleDialog::MapResult((COleDialog *)in_ECX,uVar2);
      }
    }
    *(int *)(in_ECX + 0xdc) = iVar3;
    iVar3 = 1;
  }
  return iVar3;
}




/* vtable slots: COleBusyDialog[0] */
/* 00814b59  FUN_00814b59  6 bytes, 0 callers */

undefined ** FUN_00814b59(void)

{
  return &PTR_s_COleBusyDialog_0098dea8;
}



