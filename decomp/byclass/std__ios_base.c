/* std::ios_base -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::ios_base[0] */
/* 00555330  `scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall std::ios_base::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall std::ios_base::_scalar_deleting_destructor_(ios_base *this,uint param_1)

{
  ~ios_base(this);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x38);
  }
  return this;
}



