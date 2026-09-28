/* CMyBWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyBWnd[1] */
/* 0058baf0  FUN_0058baf0  68 bytes, 0 callers */

undefined4 FUN_0058baf0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0058bad0();
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




/* vtable slots: CMyBWnd[21] */
/* 0058bb40  FUN_0058bb40  93 bytes, 0 callers */

void FUN_0058bb40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  uVar1 = FUN_0058bbc0(0x3fa);
  uVar1 = AfxRegisterWndClass(0x400b,uVar1,uVar2,uVar3);
  FUN_00791f4f(uVar1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CMyBWnd[10] */
/* 0058bba0  FUN_0058bba0  16 bytes, 0 callers */

void FUN_0058bba0(void)

{
  FUN_0058bbb0();
  return;
}



