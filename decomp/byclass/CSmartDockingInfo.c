/* CSmartDockingInfo -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSmartDockingInfo[1] */
/* 00844fb3  `scalar_deleting_destructor'  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSmartDockingInfo::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CSmartDockingInfo::_scalar_deleting_destructor_(CSmartDockingInfo *this,uint param_1)

{
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x58);
    }
  }
  return this;
}



