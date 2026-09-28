/* CScrollBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CScrollBar[1] */
/* 00798eab  FUN_00798eab  51 bytes, 0 callers */

void FUN_00798eab(byte param_1)

{
  ExternalContextBase *in_ECX;
  
  Concurrency::details::ExternalContextBase::~ExternalContextBase(in_ECX);
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




/* vtable slots: CScrollBar[89] */
/* 00798fb3  FUN_00798fb3  51 bytes, 0 callers */

void FUN_00798fb3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"SCROLLBAR",0,param_1,param_2,param_3,param_4,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CScrollBar[0] */
/* 00799075  FUN_00799075  6 bytes, 0 callers */

undefined ** FUN_00799075(void)

{
  return &PTR_s_CScrollBar_0097d3d4;
}



