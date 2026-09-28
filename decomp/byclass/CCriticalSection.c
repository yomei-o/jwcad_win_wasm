/* CCriticalSection -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CCriticalSection[1] */
/* 007e71ff  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CCriticalSection::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CCriticalSection::_scalar_deleting_destructor_(CCriticalSection *this,uint param_1)

{
  ~CCriticalSection(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x20);
    }
  }
  return this;
}




/* vtable slots: CCriticalSection[3] */
/* 007eaa01  FUN_007eaa01  16 bytes, 0 callers */

undefined4 FUN_007eaa01(void)

{
  int in_ECX;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 8));
  return 1;
}




/* vtable slots: CCriticalSection[5] */
/* 007ec34e  FUN_007ec34e  14 bytes, 0 callers */

undefined4 FUN_007ec34e(void)

{
  int in_ECX;
  
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 8));
  return 1;
}




/* vtable slots: CCriticalSection[0] */
/* 0085244f  FUN_0085244f  6 bytes, 0 callers */

undefined ** FUN_0085244f(void)

{
  return &PTR_s_CCriticalSection_00995ae0;
}



