/* CMyToolBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyToolBar[1] */
/* 00597a10  FUN_00597a10  68 bytes, 0 callers */

undefined4 FUN_00597a10(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005979f0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xf0);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyToolBar[10] */
/* 00597a60  FUN_00597a60  16 bytes, 0 callers */

void FUN_00597a60(void)

{
  FUN_00597a70();
  return;
}




/* vtable slots: CMyToolBar[90], CToolBar[90] */
/* 007ad9a2  FUN_007ad9a2  82 bytes, 1 callers */

undefined4 FUN_007ad9a2(undefined4 param_1,int param_2,uint param_3)

{
  code *pcVar1;
  int *in_ECX;
  
  if (((param_2 == -1) && ((param_3 & 0x44) == 0)) && ((param_3 & 0x18) != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x164);
    guard_check_icall(param_1,param_3 & 1,param_3 & 8);
    (*pcVar1)();
  }
  else {
    FUN_007ada1d(param_1,param_3,param_2);
  }
  return param_1;
}



