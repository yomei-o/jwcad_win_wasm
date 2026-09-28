/* CProgressCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CProgressCtrl[1] */
/* 004aa640  FUN_004aa640  68 bytes, 0 callers */

ExternalContextBase * FUN_004aa640(uint param_1)

{
  ExternalContextBase *in_ECX;
  
  Concurrency::details::ExternalContextBase::~ExternalContextBase(in_ECX);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x80);
    }
  }
  return in_ECX;
}




/* vtable slots: CProgressCtrl[89] */
/* 007a420c  FUN_007a420c  61 bytes, 0 callers */

void FUN_007a420c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_00790c5e(0x200);
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"msctls_progress32",0,param_1,param_2,param_3,param_4,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CProgressCtrl[0] */
/* 007a45d2  FUN_007a45d2  6 bytes, 0 callers */

undefined ** FUN_007a45d2(void)

{
  return &PTR_s_CProgressCtrl_0097eb20;
}



