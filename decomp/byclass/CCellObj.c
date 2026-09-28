/* CCellObj -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CCellObj[1] */
/* 008cf413  `scalar_deleting_destructor'  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CCellObj::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CCellObj::_scalar_deleting_destructor_(CCellObj *this,uint param_1)

{
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



