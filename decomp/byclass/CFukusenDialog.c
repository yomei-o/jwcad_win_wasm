/* CFukusenDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFukusenDialog[1] */
/* 004b1cf0  FUN_004b1cf0  68 bytes, 0 callers */

undefined4 FUN_004b1cf0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004b1c40();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x810);
    }
  }
  return in_ECX;
}




/* vtable slots: CFukusenDialog[64] */
/* 004b1d40  FUN_004b1d40  333 bytes, 0 callers */

void FUN_004b1d40(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x42d,in_ECX + 200);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x148);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x1c8);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x248);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x2c8);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x348);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x3e0);
  FUN_0078fb9c(param_1,0x9d5,in_ECX + 0x528);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x5a8);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x700);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x780);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0x788);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0x808);
  return;
}




/* vtable slots: CFukusenDialog[10] */
/* 004b1e90  FUN_004b1e90  16 bytes, 0 callers */

void FUN_004b1e90(void)

{
  FUN_004b1ef0();
  return;
}




/* vtable slots: CFukusenDialog[94] */
/* 004b1f50  FUN_004b1f50  153 bytes, 0 callers */

undefined4 FUN_004b1f50(void)

{
  int in_ECX;
  undefined4 local_c;
  
  if (DAT_00a0cb24 != 0) {
    *(undefined4 *)(in_ECX + 0x780) = 0;
  }
  FUN_00798993();
  FUN_007979e8();
  for (local_c = 9; -1 < local_c; local_c = local_c + -1) {
    (**(code **)(*(int *)(in_ECX + 0x3e0) + 0x188))
              (*(undefined8 *)(*(int *)(in_ECX + 0xb8) + 0x8388 + local_c * 8));
  }
  FUN_004b21c0();
  return 1;
}




/* vtable slots: CFukusenDialog[67] */
/* 004b2120  FUN_004b2120  109 bytes, 0 callers */

int FUN_004b2120(tagMSG *param_1)

{
  undefined4 uVar1;
  int iVar2;
  CDialog *in_ECX;
  
  if (param_1->message == 0x100) {
    FUN_00404c80();
    uVar1 = FUN_00799e17();
    if (param_1->wParam == 0xd) {
      FUN_007955d2(1,uVar1);
      FUN_00406bc0(0x1500,0,0);
      FUN_00404c80();
      FUN_0056d7d0();
      return 1;
    }
  }
  iVar2 = CDialog::PreTranslateMessage(in_ECX,param_1);
  return iVar2;
}




/* vtable slots: CFukusenDialog[100] */
/* 004b2190  FUN_004b2190  37 bytes, 0 callers */

void FUN_004b2190(void)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0x3e0) + 0x184))();
  return;
}



