/* CNewFileDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CNewFileDlg[1] */
/* 0059da50  FUN_0059da50  68 bytes, 0 callers */

undefined4 FUN_0059da50(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004fa810();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x7c8);
    }
  }
  return in_ECX;
}




/* vtable slots: CNewFileDlg[24] */
/* 0059daa0  FUN_0059daa0  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0059daa0(void)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_00413f30();
    FUN_004146a0(&local_18);
    FUN_00517510(&DAT_00a0c17c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CNewFileDlg[64] */
/* 0059db20  FUN_0059db20  561 bytes, 0 callers */

void FUN_0059db20(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x8aa,in_ECX + 0xb0);
  FUN_0078fb9c(param_1,0x8ab,in_ECX + 0x130);
  FUN_0078fb9c(param_1,0x8ac,in_ECX + 0x1b0);
  FUN_0078fb9c(param_1,0x8ad,in_ECX + 0x230);
  FUN_0078fb9c(param_1,0x8ae,in_ECX + 0x2b0);
  FUN_0078fb9c(param_1,0x8a9,in_ECX + 0x330);
  FUN_0078fb9c(param_1,0x5d3,in_ECX + 0x3b0);
  FUN_0078fb9c(param_1,0x69a,in_ECX + 0x4b0);
  FUN_0078fb9c(param_1,0x69b,in_ECX + 0x430);
  FUN_0078fb9c(param_1,0x69c,in_ECX + 0x530);
  FUN_0078fb9c(param_1,0x69d,in_ECX + 0x5b0);
  FUN_0078fb9c(param_1,0x69e,in_ECX + 0x630);
  FUN_0078fb9c(param_1,0x69f,in_ECX + 0x6b0);
  FUN_0078fb9c(param_1,0x5d4,in_ECX + 0x730);
  DDX_Text(param_1,0x5d3,in_ECX + 0x7b0);
  DDX_Text(param_1,0x5d4,in_ECX + 0x7b4);
  FUN_0078f75d(param_1,0x699,in_ECX + 0x7b8);
  FUN_0078f75d(param_1,0x69b,in_ECX + 0x7bc);
  FUN_0078f6f8(param_1,0x8a9,in_ECX + 0x7c0);
  FUN_0078f75d(param_1,0x8aa,in_ECX + 0x7c4);
  if (DAT_00a0cbd8 != 0) {
    FUN_00406bf0(DAT_00a0cbd8,1);
  }
  if (DAT_00a0cbf8 != 0) {
    FUN_00406bf0(DAT_00a0cbf8,1);
  }
  return;
}




/* vtable slots: CNewFileDlg[10] */
/* 0059e0d0  FUN_0059e0d0  16 bytes, 0 callers */

void FUN_0059e0d0(void)

{
  FUN_0059e110();
  return;
}




/* vtable slots: CNewFileDlg[94] */
/* 0059e310  FUN_0059e310  905 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0059e310(void)

{
  int iVar1;
  undefined4 local_6408;
  undefined4 local_6404;
  undefined4 local_6400;
  int local_63fc;
  int local_63f8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309e0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar1 = FUN_00517b40(DAT_00a0c17c,DAT_00a0c180,local_24,local_20,local_1c,local_18,&local_6408);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_6408,local_6404,0,0,5);
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_00452f40(local_63f8 + 0x7b4);
  if (DAT_00a0b3e8 < 700) {
    *(undefined4 *)(local_63f8 + 0x7c0) = 1;
    local_63fc = DAT_00a0b3e8;
    if (DAT_00a0b3e8 < 0x160) {
      if (DAT_00a0b3e8 == 0x15f) {
        *(undefined4 *)(local_63f8 + 0x7c4) = 2;
      }
      else if (DAT_00a0b3e8 == 0xe6) {
        *(undefined4 *)(local_63f8 + 0x7c4) = 4;
      }
      else if (DAT_00a0b3e8 == 300) {
        *(undefined4 *)(local_63f8 + 0x7c4) = 3;
      }
    }
    else if (DAT_00a0b3e8 == 0x1a4) {
      *(undefined4 *)(local_63f8 + 0x7c4) = 1;
    }
    else if (DAT_00a0b3e8 == 600) {
      *(undefined4 *)(local_63f8 + 0x7c4) = 0;
    }
  }
  else {
    *(undefined4 *)(local_63f8 + 0x7c0) = 0;
  }
  if (*(int *)(local_63f8 + 0xa8) != 0) {
    *(undefined4 *)(local_63f8 + 0x7c4) = 0;
  }
  FUN_007955d2(0);
  if (*(int *)(local_63f8 + 0xa8) != 0) {
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
    if (DAT_00a0b388 < 1) {
      FUN_007979e8(0);
    }
    else {
      FUN_007979e8(1);
    }
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
  }
  FUN_0059e210();
  if (*(int *)(local_63f8 + 0xac) == 0) {
    FUN_007979e8(1);
  }
  else {
    FUN_007979e8(0);
  }
  local_6400 = 1;
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return local_6400;
}




/* vtable slots: CNewFileDlg[96] */
/* 0059e7a0  FUN_0059e7a0  170 bytes, 0 callers */

void FUN_0059e7a0(void)

{
  char cVar1;
  int in_ECX;
  
  FUN_007955d2(1);
  cVar1 = FUN_00414040(&DAT_0095590a,in_ECX + 0x7b0);
  if (cVar1 == '\0') {
    DAT_00a0b3e8 = 700;
    if (*(int *)(in_ECX + 0x7c0) == 1) {
      switch(*(undefined4 *)(in_ECX + 0x7c4)) {
      case 0:
        DAT_00a0b3e8 = 600;
        break;
      case 1:
        DAT_00a0b3e8 = 0x1a4;
        break;
      case 2:
        DAT_00a0b3e8 = 0x15f;
        break;
      case 3:
        DAT_00a0b3e8 = 300;
        break;
      case 4:
        DAT_00a0b3e8 = 0xe6;
      }
    }
    FUN_00798a09();
  }
  return;
}



