/* CPane -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPane[1] */
/* 007ef157  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CPane::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CPane::_scalar_deleting_destructor_(CPane *this,uint param_1)

{
  ~CPane(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2b8);
    }
  }
  return this;
}




/* vtable slots: CPane[10] */
/* 007f0250  FUN_007f0250  6 bytes, 0 callers */

undefined ** FUN_007f0250(void)

{
  return &PTR_FUN_0098b078;
}




/* vtable slots: CPane[0] */
/* 007f0288  FUN_007f0288  6 bytes, 0 callers */

undefined ** FUN_007f0288(void)

{
  return &PTR_s_CPane_0098ac24;
}



