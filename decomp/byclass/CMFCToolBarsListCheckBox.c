/* CMFCToolBarsListCheckBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsListCheckBox[1] */
/* 008cefa0  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarsListCheckBox::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarsListCheckBox::_scalar_deleting_destructor_(CMFCToolBarsListCheckBox *this,uint param_1)

{
  ~CMFCToolBarsListCheckBox(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xa0);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarsListCheckBox[10] */
/* 008cefe2  FUN_008cefe2  6 bytes, 0 callers */

undefined ** FUN_008cefe2(void)

{
  return &PTR_FUN_009a6fc0;
}



