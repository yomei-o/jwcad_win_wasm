/* CFrameImpl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFrameImpl[0] */
/* 0087aed0  `scalar_deleting_destructor'  37 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CFrameImpl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CFrameImpl::_scalar_deleting_destructor_(CFrameImpl *this,uint param_1)

{
  FUN_0087ad60();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x104);
  }
  return this;
}



