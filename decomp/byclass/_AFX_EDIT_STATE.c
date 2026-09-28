/* _AFX_EDIT_STATE -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: _AFX_EDIT_STATE[0] */
/* 008d85a7  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall _AFX_EDIT_STATE::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall _AFX_EDIT_STATE::_scalar_deleting_destructor_(_AFX_EDIT_STATE *this,uint param_1)

{
  ~_AFX_EDIT_STATE(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      CNoTrackObject::operator_delete(this);
    }
    else {
      _Adl_verify_range<>(this,0x20);
    }
  }
  return this;
}



