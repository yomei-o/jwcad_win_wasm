/* CNamaeHenkouDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CNamaeHenkouDlg[1] */
/* 0059d370  FUN_0059d370  68 bytes, 0 callers */

undefined4 FUN_0059d370(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0059d2f0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1d0);
    }
  }
  return in_ECX;
}




/* vtable slots: CNamaeHenkouDlg[64] */
/* 0059d400  FUN_0059d400  120 bytes, 0 callers */

void FUN_0059d400(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x780,in_ECX + 0xc0);
  FUN_0078fb9c(param_1,0x8a6,in_ECX + 0x140);
  DDX_Text(param_1,0x8a6,in_ECX + 0x1c0);
  FUN_0078f500(param_1,in_ECX + 0x1c0,0xfa);
  return;
}




/* vtable slots: CNamaeHenkouDlg[10] */
/* 0059d480  FUN_0059d480  16 bytes, 0 callers */

void FUN_0059d480(void)

{
  FUN_0059d490();
  return;
}




/* vtable slots: CNamaeHenkouDlg[94] */
/* 0059d4a0  FUN_0059d4a0  366 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0059d4a0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009307fd;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar2 = FUN_00517b40(DAT_00a0c154,DAT_00a0c158,local_24,local_20,local_1c,local_18,&local_3c);
  if (iVar2 != 0) {
    FUN_00797e71(0,local_3c,local_38,0,0,5);
  }
  cVar1 = FUN_00408cb0(&DAT_0095590a,local_28 + 0xb4);
  if ((cVar1 == '\0') && (*(int *)(local_28 + 0xb0) != 1)) {
    local_30 = FUN_005977f0(0x1546);
    local_8 = 0;
    local_2c = local_30;
    uVar3 = FUN_00404920();
    FUN_00797ece(uVar3);
    local_8 = 0xffffffff;
    FUN_00404770();
  }
  else {
    uVar3 = FUN_00404920();
    FUN_00797ece(uVar3);
    uVar3 = FUN_00404920();
    FUN_00797ece(uVar3);
  }
  FUN_00797df8();
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CNamaeHenkouDlg[96] */
/* 0059d6f0  FUN_0059d6f0  123 bytes, 0 callers */

void FUN_0059d6f0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  FUN_007955d2(1);
  uVar1 = FUN_0040c0e0();
  FUN_00404860(in_ECX + 0x1c0);
  if (*(int *)(in_ECX + 0x1c8) < 0) {
    FUN_00798a09(uVar3,uVar1);
  }
  else {
    *(undefined4 *)(in_ECX + 0x1c4) = 1;
    uVar2 = 1;
    uVar1 = *(undefined4 *)(in_ECX + 0x1c8);
    uVar3 = 0x1403;
    FUN_0041b5c0(0x1403,uVar1,1);
    FUN_00406bc0(uVar3,uVar1,uVar2);
  }
  return;
}



