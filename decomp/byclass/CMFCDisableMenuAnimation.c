/* CMFCDisableMenuAnimation -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCDisableMenuAnimation[0] */
/* 008b2a5b  `scalar_deleting_destructor'  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCDisableMenuAnimation::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCDisableMenuAnimation::_scalar_deleting_destructor_(CMFCDisableMenuAnimation *this,uint param_1)

{
  DAT_00a139d8 = *(undefined4 *)(this + 4);
  *(undefined ***)this = vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,8);
  }
  return this;
}



