/* CSmartDockingGroupGuidesWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSmartDockingGroupGuidesWnd[1] */
/* 008c2bd1  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSmartDockingGroupGuidesWnd::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CSmartDockingGroupGuidesWnd::_scalar_deleting_destructor_
          (CSmartDockingGroupGuidesWnd *this,uint param_1)

{
  ~CSmartDockingGroupGuidesWnd(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x98);
    }
  }
  return this;
}




/* vtable slots: CSmartDockingGroupGuidesWnd[10] */
/* 008c39cb  FUN_008c39cb  6 bytes, 0 callers */

undefined ** FUN_008c39cb(void)

{
  return &PTR_FUN_009a3d50;
}



