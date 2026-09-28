/* CMFCZoomKernel -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCZoomKernel[0] */
/* 007e7262  `scalar_deleting_destructor'  40 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCZoomKernel::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCZoomKernel::_scalar_deleting_destructor_(CMFCZoomKernel *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_007e9865();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0xc);
  }
  return this;
}



