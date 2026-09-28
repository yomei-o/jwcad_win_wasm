/* CSmartDockingHighlighterWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSmartDockingHighlighterWnd[1] */
/* 008c443f  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSmartDockingHighlighterWnd::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CSmartDockingHighlighterWnd::_scalar_deleting_destructor_
          (CSmartDockingHighlighterWnd *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_007908c2();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xb8);
    }
  }
  return this;
}




/* vtable slots: CSmartDockingHighlighterWnd[10] */
/* 008c4524  FUN_008c4524  6 bytes, 0 callers */

undefined ** FUN_008c4524(void)

{
  return &PTR_FUN_009a3f88;
}



