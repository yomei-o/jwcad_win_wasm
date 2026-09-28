/* CProtectLayPassWordDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CProtectLayPassWordDialog[1] */
/* 005acfd0  FUN_005acfd0  68 bytes, 0 callers */

undefined4 FUN_005acfd0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00525ee0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x7f8);
    }
  }
  return in_ECX;
}




/* vtable slots: CProtectLayPassWordDialog[64] */
/* 005ad020  FUN_005ad020  1353 bytes, 0 callers */

void FUN_005ad020(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  undefined4 uVar3;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x7c8,in_ECX + 0xb8);
  FUN_0078fb9c(param_1,0x7c9,in_ECX + 0x138);
  DDX_Text(param_1,0x7c9,in_ECX + 0x1b8);
  FUN_0078fb9c(param_1,0x7ca,in_ECX + 0x1c0);
  DDX_Text(param_1,0x7ca,in_ECX + 0x240);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x248);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x2c8);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0x2d0);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0x3d0);
  FUN_0078fb9c(param_1,0x52d,in_ECX + 0x3d8);
  FUN_0078f6f8(param_1,0x52d,in_ECX + 0x4d8);
  FUN_0078fb9c(param_1,0x52e,in_ECX + 0x4e0);
  FUN_0078f6f8(param_1,0x52e,in_ECX + 0x5e0);
  FUN_0078fb9c(param_1,0x52f,in_ECX + 0x5e8);
  FUN_0078fb9c(param_1,0x9d8,in_ECX + 0x350);
  FUN_0078fb9c(param_1,0x9d9,in_ECX + 0x458);
  FUN_0078fb9c(param_1,0x89d,in_ECX + 0x560);
  FUN_0078fb9c(param_1,0x9da,in_ECX + 0x668);
  FUN_0078fb9c(param_1,0x89e,in_ECX + 0x770);
  FUN_0078f6f8(param_1,0x52f,in_ECX + 0x6e8);
  FUN_0078fb9c(param_1,0x530,in_ECX + 0x6f0);
  FUN_0078f6f8(param_1,0x530,in_ECX + 0x7f0);
  if (*(int *)(in_ECX + 0xb0) < 10) {
    FUN_00797f20(0);
  }
  else {
    FUN_00797f20(5);
  }
  iVar2 = 0;
  if ((DAT_00a08ae0 == 0x4e3) || (DAT_00a08ae0 == 0x2fefd8)) {
    iVar2 = 1;
  }
  cVar1 = FUN_00414010(in_ECX + 0x1b8,in_ECX + 0x240);
  if ((cVar1 == '\0') && (cVar1 = FUN_00447350(&DAT_00956338,in_ECX + 0x240), cVar1 == '\0')) {
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(0);
    FUN_007979e8(*(undefined4 *)(in_ECX + 0x3d0));
    FUN_007979e8(*(undefined4 *)(in_ECX + 0x4d8));
    FUN_007979e8(*(undefined4 *)(in_ECX + 0x5e0));
    if (iVar2 == 0) {
      FUN_00797f20(0);
      FUN_00797f20(0);
      FUN_00797f20(0);
      FUN_00797f20(0);
    }
    else {
      FUN_007979e8(0);
      FUN_007979e8(0);
      FUN_007979e8(*(undefined4 *)(in_ECX + 0x6e8));
      FUN_007979e8(*(undefined4 *)(in_ECX + 0x7f0));
    }
    FUN_00797df8();
    return;
  }
  uVar3 = 1;
  cVar1 = FUN_00447350(&DAT_00956338,in_ECX + 0x1b8,iVar2,1);
  if (cVar1 != '\0') {
    uVar3 = 0;
  }
  FUN_007979e8(uVar3);
  if (*(int *)(in_ECX + 0x2c8) == 0) {
    uVar3 = 0;
  }
  FUN_007979e8(uVar3);
  FUN_007979e8(uVar3);
  FUN_007979e8(uVar3);
  FUN_007979e8(uVar3);
  FUN_007979e8(uVar3);
  FUN_007979e8(uVar3);
  if (iVar2 == 0) {
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
  }
  else {
    FUN_007979e8(uVar3);
    FUN_007979e8(uVar3);
    FUN_007979e8(uVar3);
    FUN_007979e8(uVar3);
  }
  *(undefined4 *)(in_ECX + 0xa8) = 1;
  return;
}




/* vtable slots: CProtectLayPassWordDialog[10] */
/* 005ad570  FUN_005ad570  16 bytes, 0 callers */

void FUN_005ad570(void)

{
  FUN_005ad580();
  return;
}




/* vtable slots: CProtectLayPassWordDialog[94] */
/* 005ad680  FUN_005ad680  178 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005ad680(void)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931100;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00798993(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  FUN_00446aa0();
  local_8 = 0;
  FUN_0044fbe0(in_ECX,0);
  FUN_00797df8();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CProtectLayPassWordDialog[96] */
/* 005ad740  FUN_005ad740  366 bytes, 0 callers */

void FUN_005ad740(void)

{
  char cVar1;
  int in_ECX;
  uint local_c;
  
  FUN_007955d2(1);
  FUN_005ad8b0(in_ECX + 0x1b8);
  FUN_005ad8b0(in_ECX + 0x240);
  FUN_00404860(in_ECX + 0x1b8);
  cVar1 = FUN_00447350(&DAT_00956338,in_ECX + 0x1b8);
  if (cVar1 != '\0') {
    *(undefined4 *)(in_ECX + 0x2c8) = 0;
    *(undefined4 *)(in_ECX + 0x6e8) = 0;
    *(undefined4 *)(in_ECX + 0x7f0) = 0;
  }
  if (*(int *)(in_ECX + 0xa8) != 0) {
    local_c = (uint)(*(int *)(in_ECX + 0x3d0) != 0);
    if (*(int *)(in_ECX + 0x4d8) != 0) {
      local_c = local_c + 2;
    }
    if (*(int *)(in_ECX + 0x5e0) != 0) {
      local_c = local_c + 4;
    }
    if (*(int *)(in_ECX + 0x2c8) == 0) {
      FUN_00404900(&DAT_00956338);
    }
    else {
      if (*(int *)(in_ECX + 0x6e8) != 0) {
        local_c = local_c + 8;
      }
      if (*(int *)(in_ECX + 0x7f0) != 0) {
        local_c = local_c + 0x10;
      }
      FUN_00404860(in_ECX + 0x1b8);
    }
    *(uint *)(DAT_00a0b410 + 0x2ac4) = local_c;
  }
  FUN_00798a09();
  return;
}




/* vtable slots: CProtectLayPassWordDialog[67] */
/* 005ada20  FUN_005ada20  374 bytes, 0 callers */

int FUN_005ada20(tagMSG *param_1)

{
  char cVar1;
  int iVar2;
  CDialog *in_ECX;
  
  if (param_1->message == 0x100) {
    if (param_1->wParam == 0x11) {
      *(undefined4 *)(in_ECX + 0xac) = 1;
      return 1;
    }
    if (param_1->wParam == 0xd) {
      if ((*(int *)(in_ECX + 0xac) != 0) &&
         (*(undefined4 *)(in_ECX + 0xac) = 0, DAT_00a08ae0 == 0x2fefd8)) {
        *(int *)(in_ECX + 0xb0) = *(int *)(in_ECX + 0xb0) + 1;
        if (9 < *(int *)(in_ECX + 0xb0)) {
          FUN_00797f20(5);
        }
        return 1;
      }
      FUN_007955d2(1);
      FUN_005ad8b0(in_ECX + 0x1b8);
      if (*(int *)(in_ECX + 0xa8) != 0) {
        FUN_00404860(in_ECX + 0x1b8);
        cVar1 = FUN_00447350(&DAT_00956338,in_ECX + 0x1b8);
        if (cVar1 != '\0') {
          *(undefined4 *)(in_ECX + 0x2c8) = 0;
          *(undefined4 *)(in_ECX + 0x3d0) = 0;
          *(undefined4 *)(in_ECX + 0x4d8) = 0;
          *(undefined4 *)(in_ECX + 0x5e0) = 0;
          *(undefined4 *)(in_ECX + 0x6e8) = 0;
          *(undefined4 *)(in_ECX + 0x7f0) = 0;
        }
      }
      FUN_007955d2(0);
      return 1;
    }
  }
  iVar2 = CDialog::PreTranslateMessage(in_ECX,param_1);
  return iVar2;
}



