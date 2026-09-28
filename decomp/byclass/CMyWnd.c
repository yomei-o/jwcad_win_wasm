/* CMyWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyWnd[0] */
/* 0059b781  FUN_0059b781  11 bytes, 0 callers */

void FUN_0059b781(void)

{
  FUN_0059b790();
  return;
}




/* vtable slots: CMyWnd[1] */
/* 0059b790  FUN_0059b790  68 bytes, 1 callers */

undefined4 FUN_0059b790(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0059b680();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x8560);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyWnd[10] */
/* 0059c390  FUN_0059c390  16 bytes, 0 callers */

void FUN_0059c390(void)

{
  FUN_0059c3c0();
  return;
}




/* vtable slots: CMyWnd[1] */
/* 0059c3a0  FUN_0059c3a0  20 bytes, 0 callers */

undefined4 FUN_0059c3a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x84a8);
}




/* vtable slots: CMyWnd[67] */
/* 0059d000  FUN_0059d000  78 bytes, 0 callers */

void FUN_0059d000(int param_1)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 4) == 0x100) && (*(int *)(param_1 + 8) == 0xd)) {
    uVar3 = 0;
    uVar2 = *(undefined4 *)(in_ECX + 0x8554);
    uVar1 = 0x1406;
    FUN_0041b5c0(0x1406,uVar2,0);
    FUN_00406bc0(uVar1,uVar2,uVar3);
  }
  FUN_007949fb(param_1);
  return;
}




/* vtable slots: CMyWnd[3] */
/* 0059d0a0  FUN_0059d0a0  44 bytes, 0 callers */

bool FUN_0059d0a0(int param_1)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x84a8) + 0xee0 + param_1 * 4) != 0;
}




/* vtable slots: CMyWnd[2] */
/* 0059d0d0  FUN_0059d0d0  44 bytes, 0 callers */

bool FUN_0059d0d0(int param_1)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x84a8) + 0xea0 + param_1 * 4) != 0;
}




/* vtable slots: CMyWnd[5] */
/* 0059d100  FUN_0059d100  53 bytes, 0 callers */

bool FUN_0059d100(int param_1,int param_2)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x84a8) + 0x1320 + param_1 * 0x40 + param_2 * 4) != 0;
}




/* vtable slots: CMyWnd[4] */
/* 0059d140  FUN_0059d140  53 bytes, 0 callers */

bool FUN_0059d140(int param_1,int param_2)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x84a8) + 0xf20 + param_1 * 0x40 + param_2 * 4) != 0;
}



