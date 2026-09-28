/* CMyTabCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyTabCtrl[1] */
/* 005978e0  FUN_005978e0  68 bytes, 0 callers */

undefined4 FUN_005978e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005978c0();
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




/* vtable slots: CMyTabCtrl[10] */
/* 00597980  FUN_00597980  16 bytes, 0 callers */

void FUN_00597980(void)

{
  FUN_00597990();
  return;
}




/* vtable slots: CMyTabCtrl[67] */
/* 005979a0  FUN_005979a0  47 bytes, 0 callers */

void FUN_005979a0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0x204) {
    *(undefined4 *)(param_1 + 4) = 0x201;
  }
  FUN_007949fb(param_1);
  return;
}




/* vtable slots: CMyTabCtrl[89], CTabCtrl[89] */
/* 007a4283  FUN_007a4283  61 bytes, 0 callers */

void FUN_007a4283(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_00790c5e(0x100);
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"SysTabControl32",0,param_1,param_2,param_3,param_4,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CMyTabCtrl[0], CTabCtrl[0] */
/* 007a45e4  FUN_007a45e4  6 bytes, 0 callers */

undefined ** FUN_007a45e4(void)

{
  return &PTR_s_CTabCtrl_0097eccc;
}



