/* CPaneFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPaneFrameWnd[1] */
/* 0083eaac  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CPaneFrameWnd::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CPaneFrameWnd::_scalar_deleting_destructor_(CPaneFrameWnd *this,uint param_1)

{
  FUN_0083e9c7();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,400);
    }
  }
  return this;
}




/* vtable slots: CPaneFrameWnd[10] */
/* 0083fa63  FUN_0083fa63  6 bytes, 0 callers */

undefined ** FUN_0083fa63(void)

{
  return &PTR_FUN_00993eb8;
}




/* vtable slots: CPaneFrameWnd[0] */
/* 0083fb4c  FUN_0083fb4c  6 bytes, 0 callers */

undefined ** FUN_0083fb4c(void)

{
  return &PTR_s_CPaneFrameWnd_00a008b0;
}



