/* CToolTipCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CToolTipCtrl[1] */
/* 007af34b  FUN_007af34b  51 bytes, 0 callers */

void FUN_007af34b(byte param_1)

{
  call<unsigned_int,std::function<void___cdecl(unsigned_int_const&)>_> *in_ECX;
  
  Concurrency::call<unsigned_int,std::function<void___cdecl(unsigned_int_const&)>_>::
  ~call<unsigned_int,std::function<void___cdecl(unsigned_int_const&)>_>(in_ECX);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CToolTipCtrl[10] */
/* 007afa49  FUN_007afa49  6 bytes, 0 callers */

undefined ** FUN_007afa49(void)

{
  return &PTR_FUN_00980168;
}




/* vtable slots: CToolTipCtrl[0] */
/* 007afa4f  FUN_007afa4f  6 bytes, 0 callers */

undefined ** FUN_007afa4f(void)

{
  return &PTR_s_CToolTipCtrl_0097ff60;
}



