/* std::locale::_Locimp -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::locale::_Locimp[0] */
/* 008da7f8  `scalar_deleting_destructor'  34 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void * __thiscall std::locale::_Locimp::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2019 Release */

void * __thiscall std::locale::_Locimp::_scalar_deleting_destructor_(_Locimp *this,uint param_1)

{
  ~_Locimp(this);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x20);
  }
  return this;
}



