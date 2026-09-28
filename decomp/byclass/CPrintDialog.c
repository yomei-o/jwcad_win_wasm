/* CPrintDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPrintDialog[1] */
/* 007b5284  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CPrintDialog::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CPrintDialog::_scalar_deleting_destructor_(CPrintDialog *this,uint param_1)

{
  *(undefined ***)this = CCommonDialog::vftable;
  FUN_00797fb6();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xf0);
    }
  }
  return this;
}




/* vtable slots: CPrintDialog[99] */
/* 007b5329  AttachOnSetup  89 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual class CPrintDialog * __thiscall CPrintDialog::AttachOnSetup(void)
   
   Library: Visual Studio 2015 Release */

CPrintDialog * __thiscall CPrintDialog::AttachOnSetup(CPrintDialog *this)

{
  int iVar1;
  CPrintDialog *pCVar2;
  
  iVar1 = FUN_0078e624(0xf0);
  if (iVar1 == 0) {
    pCVar2 = (CPrintDialog *)0x0;
  }
  else {
    pCVar2 = (CPrintDialog *)FUN_007b518e(*(undefined4 *)(this + 0xa8));
  }
  *(undefined4 *)(pCVar2 + 0x20) = 0;
  *(undefined4 *)(pCVar2 + 0x94) = *(undefined4 *)(this + 0x94);
  *(undefined4 *)(pCVar2 + 0x80) = 0x7009;
  return pCVar2;
}




/* vtable slots: CPrintDialog[93] */
/* 007b53aa  DoModal  50 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CPrintDialog::DoModal(void)
   
   Library: Visual Studio 2015 Release */

int __thiscall CPrintDialog::DoModal(CPrintDialog *this)

{
  HWND__ *pHVar1;
  int iVar2;
  
  pHVar1 = CDialog::PreModal((CDialog *)this);
  *(HWND__ **)(*(int *)(this + 0xa8) + 4) = pHVar1;
  iVar2 = FUN_007b54db(*(undefined4 *)(this + 0xa8));
  CDialog::PostModal((CDialog *)this);
  if (iVar2 == 0) {
    iVar2 = 2;
  }
  return iVar2;
}




/* vtable slots: CPrintDialog[10] */
/* 007b5456  FUN_007b5456  6 bytes, 0 callers */

undefined ** FUN_007b5456(void)

{
  return &PTR_FUN_00980f1c;
}




/* vtable slots: CPrintDialog[0] */
/* 007b548d  FUN_007b548d  6 bytes, 0 callers */

undefined ** FUN_007b548d(void)

{
  return &PTR_s_CPrintDialog_00980d3c;
}



