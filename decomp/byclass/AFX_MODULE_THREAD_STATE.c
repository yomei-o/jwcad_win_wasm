/* AFX_MODULE_THREAD_STATE -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: AFX_MODULE_THREAD_STATE[0] */
/* 0079dd0a  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall AFX_MODULE_THREAD_STATE::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
AFX_MODULE_THREAD_STATE::_scalar_deleting_destructor_(AFX_MODULE_THREAD_STATE *this,uint param_1)

{
  FUN_0079db47();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      CNoTrackObject::operator_delete(this);
    }
    else {
      _Adl_verify_range<>(this,0x54);
    }
  }
  return this;
}



