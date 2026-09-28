/* AFX_MODULE_STATE -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: AFX_MODULE_STATE[0], _AFX_BASE_MODULE_STATE[0] */
/* 0079dcd7  FID_conflict:`scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall AFX_MODULE_STATE::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall _AFX_BASE_MODULE_STATE::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void FID_conflict__scalar_deleting_destructor_(byte param_1)

{
  void *in_ECX;
  
  FUN_0079daa3();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      CNoTrackObject::operator_delete(in_ECX);
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}



