/* _AFX_HTMLHELP_STATE -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: _AFX_HTMLHELP_STATE[0] */
/* 00790a25  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall _AFX_HTMLHELP_STATE::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
_AFX_HTMLHELP_STATE::_scalar_deleting_destructor_(_AFX_HTMLHELP_STATE *this,uint param_1)

{
  FUN_007909aa();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      CNoTrackObject::operator_delete(this);
    }
    else {
      _Adl_verify_range<>(this,0xc);
    }
  }
  return this;
}



