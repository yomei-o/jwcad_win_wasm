/* CMFCTabInfo -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTabInfo[1] */
/* 00807415  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    private: virtual void * __thiscall CMFCTabInfo::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCTabInfo::_scalar_deleting_destructor_(CMFCTabInfo *this,uint param_1)

{
  ~CMFCTabInfo(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x48);
    }
  }
  return this;
}



