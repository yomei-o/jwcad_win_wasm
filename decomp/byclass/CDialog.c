/* CDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDialog[1] */
/* 00798024  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CDialog::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CDialog::_scalar_deleting_destructor_(CDialog *this,uint param_1)

{
  FUN_00797fb6();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xa8);
    }
  }
  return this;
}




/* vtable slots: CDialog[10], CPrintingDialog[10] */
/* 0079871e  FUN_0079871e  6 bytes, 0 callers */

undefined ** FUN_0079871e(void)

{
  return &PTR_FUN_0097d1a8;
}



