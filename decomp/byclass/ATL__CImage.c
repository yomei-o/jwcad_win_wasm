/* ATL::CImage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: ATL::CImage[0] */
/* 007cc892  `scalar_deleting_destructor'  34 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall ATL::CImage::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall ATL::CImage::_scalar_deleting_destructor_(CImage *this,uint param_1)

{
  ~CImage(this);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x34);
  }
  return this;
}



