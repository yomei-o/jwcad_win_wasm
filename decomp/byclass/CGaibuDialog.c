/* CGaibuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CGaibuDialog[1] */
/* 004b2560  FUN_004b2560  68 bytes, 0 callers */

undefined4 FUN_004b2560(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004b24f0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x340);
    }
  }
  return in_ECX;
}




/* vtable slots: CGaibuDialog[64] */
/* 004b25b0  FUN_004b25b0  167 bytes, 0 callers */

void FUN_004b25b0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x782,in_ECX + 0xb8);
  FUN_0078fb9c(param_1,0x781,in_ECX + 0x138);
  DDX_Text(param_1,0x781,in_ECX + 0x1b8);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x1c0);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x240);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x2c0);
  return;
}




/* vtable slots: CGaibuDialog[10] */
/* 004b2660  FUN_004b2660  16 bytes, 0 callers */

void FUN_004b2660(void)

{
  FUN_004b2670();
  return;
}




/* vtable slots: CGaibuDialog[67] */
/* 004b2680  FUN_004b2680  82 bytes, 0 callers */

int FUN_004b2680(tagMSG *param_1)

{
  int iVar1;
  CDialog *in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = CDialog::PreTranslateMessage(in_ECX,param_1);
  if ((param_1->message == 0x100) && (param_1->wParam == 0xd)) {
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = 0x1500;
    FUN_00404c80(0x1500,0,0);
    FUN_00799e17();
    FUN_00406bc0(uVar2,uVar3,uVar4);
  }
  return iVar1;
}



