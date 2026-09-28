/* CPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPropertyPage[1] */
/* 0079fd6d  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CPropertyPage::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CPropertyPage::_scalar_deleting_destructor_(CPropertyPage *this,uint param_1)

{
  FUN_0079fca4();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xc0);
    }
  }
  return this;
}




/* vtable slots: CPropertyPage[10] */
/* 007a0650  FUN_007a0650  6 bytes, 0 callers */

undefined ** FUN_007a0650(void)

{
  return &PTR_FUN_0097e730;
}



