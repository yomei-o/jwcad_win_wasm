/* CLType -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CLType[0] */
/* 0049d1c0  `scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::VirtualProcessorRoot::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::VirtualProcessorRoot::_scalar_deleting_destructor_
          (VirtualProcessorRoot *this,uint param_1)

{
  ~VirtualProcessorRoot(this);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x30);
  }
  return this;
}



