/* CSyncObject -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSyncObject[1] */
/* 0085241f  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSyncObject::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CSyncObject::_scalar_deleting_destructor_(CSyncObject *this,uint param_1)

{
  ~CSyncObject(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,8);
    }
  }
  return this;
}




/* vtable slots: CSyncObject[0] */
/* 00852455  FUN_00852455  6 bytes, 0 callers */

undefined ** FUN_00852455(void)

{
  return &PTR_s_CSyncObject_00995aa8;
}




/* vtable slots: CSyncObject[3] */
/* 0085245b  Lock  37 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CSyncObject::Lock(unsigned long)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

int __thiscall CSyncObject::Lock(CSyncObject *this,ulong param_1)

{
  DWORD DVar1;
  int iVar2;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(this + 4),param_1);
  if ((DVar1 == 0) || (DVar1 == 0x80)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



