/* CFullScreenImpl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFullScreenImpl[0] */
/* 008c1cd2  `scalar_deleting_destructor'  34 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CFullScreenImpl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CFullScreenImpl::_scalar_deleting_destructor_(CFullScreenImpl *this,uint param_1)

{
  ~CFullScreenImpl(this);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x40);
  }
  return this;
}



