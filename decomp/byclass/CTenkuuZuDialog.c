/* CTenkuuZuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTenkuuZuDialog[1] */
/* 005ed5d0  FUN_005ed5d0  68 bytes, 0 callers */

undefined4 FUN_005ed5d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005ed300();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1448);
    }
  }
  return in_ECX;
}




/* vtable slots: CTenkuuZuDialog[24] */
/* 005ee700  FUN_005ee700  233 bytes, 0 callers */

void FUN_005ee700(void)

{
  int in_ECX;
  
  FUN_00404860(in_ECX + 0x5f8);
  DAT_00a0beac = (uint)(*(int *)(in_ECX + 0xa18) != 0);
  if (*(int *)(in_ECX + 0xc38) != 0) {
    DAT_00a0beac = DAT_00a0beac + 2;
  }
  if (*(int *)(in_ECX + 0xcc0) != 0) {
    DAT_00a0beac = DAT_00a0beac + 4;
  }
  if (*(int *)(in_ECX + 0xd48) != 0) {
    DAT_00a0beac = DAT_00a0beac + 8;
  }
  if (*(int *)(in_ECX + 0xaa0) != 0) {
    DAT_00a0beac = DAT_00a0beac + 0x10;
  }
  if (*(int *)(in_ECX + 0xb28) != 0) {
    DAT_00a0beac = DAT_00a0beac + 0x20;
  }
  if (*(int *)(in_ECX + 0xbb0) != 0) {
    DAT_00a0beac = DAT_00a0beac + 0x40;
  }
  FUN_00792313();
  return;
}




/* vtable slots: CTenkuuZuDialog[64] */
/* 005ee7f0  FUN_005ee7f0  1327 bytes, 0 callers */

void FUN_005ee7f0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0xf0);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x170);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x1f0);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x270);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x2f0);
  FUN_0078fb9c(param_1,0x791,in_ECX + 0x370);
  FUN_0078fb9c(param_1,0x5d3,in_ECX + 0x3f0);
  DDX_Text(param_1,0x5d3,in_ECX + 0x470);
  FUN_0078fb9c(param_1,0x796,in_ECX + 0x478);
  FUN_0078fb9c(param_1,0x8a7,in_ECX + 0x4f8);
  DDX_Text(param_1,0x8a7,in_ECX + 0x5f8);
  FUN_0078fb9c(param_1,0x8a8,in_ECX + 0x578);
  DDX_Text(param_1,0x8a8,in_ECX + 0x5fc);
  FUN_0078fb9c(param_1,0x795,in_ECX + 0x600);
  FUN_0078fb9c(param_1,0x5d4,in_ECX + 0x680);
  DDX_Text(param_1,0x5d4,in_ECX + 0x700);
  FUN_0078fb9c(param_1,0x792,in_ECX + 0x708);
  FUN_0078fb9c(param_1,0x5d5,in_ECX + 0x788);
  DDX_Text(param_1,0x5d5,in_ECX + 0x808);
  FUN_0078fb9c(param_1,0x793,in_ECX + 0x890);
  FUN_0078fb9c(param_1,0x8a1,in_ECX + 0x910);
  FUN_0078f643(param_1,0x8a1,in_ECX + 0x990);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x998);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0xa18);
  FUN_0078fb9c(param_1,0x52f,in_ECX + 0xa20);
  FUN_0078f6f8(param_1,0x52f,in_ECX + 0xaa0);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0xaa8);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0xb28);
  FUN_0078fb9c(param_1,0x530,in_ECX + 3000);
  FUN_0078f6f8(param_1,0x530,in_ECX + 0xbb0);
  FUN_0078fb9c(param_1,0x52d,in_ECX + 0xb30);
  FUN_0078f6f8(param_1,0x52d,in_ECX + 0xc38);
  FUN_0078fb9c(param_1,0x52e,in_ECX + 0xc40);
  FUN_0078f6f8(param_1,0x52e,in_ECX + 0xcc0);
  FUN_0078fb9c(param_1,0x841,in_ECX + 0xcc8);
  FUN_0078f6f8(param_1,0x841,in_ECX + 0xd48);
  FUN_0078fb9c(param_1,0x843,in_ECX + 0xd50);
  FUN_0078f6f8(param_1,0x843,in_ECX + 0xdd0);
  FUN_0078fb9c(param_1,0x842,in_ECX + 0xdd8);
  FUN_0078f6f8(param_1,0x842,in_ECX + 0xe58);
  FUN_0078f75d(param_1,0x699,in_ECX + 0xfe4);
  FUN_0078fb9c(param_1,0x699,in_ECX + 0xfe8);
  FUN_0078fb9c(param_1,0x69a,in_ECX + 0x1068);
  FUN_0078fb9c(param_1,0x531,in_ECX + 0xe60);
  FUN_0078f6f8(param_1,0x531,in_ECX + 0xe5c);
  FUN_0078fb9c(param_1,0x794,in_ECX + 0xee0);
  FUN_0078fb9c(param_1,0x8a2,in_ECX + 0xf60);
  FUN_0078f643(param_1,0x8a2,in_ECX + 0xfe0);
  FUN_0078fb9c(param_1,0x461,in_ECX + 0x810);
  FUN_0078fb9c(param_1,0x463,in_ECX + 0x10e8);
  FUN_0078fb9c(param_1,0x464,in_ECX + 0x1180);
  FUN_0078fb9c(param_1,0x465,in_ECX + 0x1218);
  FUN_0078fb9c(param_1,0x466,in_ECX + 0x12b0);
  FUN_0078fb9c(param_1,0x469,in_ECX + 0x1348);
  FUN_0078fb9c(param_1,0x43c,in_ECX + 0x13c8);
  return;
}




/* vtable slots: CTenkuuZuDialog[10] */
/* 005eed20  FUN_005eed20  16 bytes, 0 callers */

void FUN_005eed20(void)

{
  FUN_005eed30();
  return;
}




/* vtable slots: CTenkuuZuDialog[67] */
/* 005ef650  FUN_005ef650  250 bytes, 0 callers */

undefined4 FUN_005ef650(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928f9d;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  FUN_00403dd0(in_ECX + 0x5fc);
  local_8 = 0;
  uVar3 = FUN_0058d4f0(param_1);
  FUN_007955d2(1,uVar2);
  if (*(int *)(local_14 + 0xbc) == 1) {
    cVar1 = FUN_00408c80(local_14 + 0x5fc,local_1c);
    if (cVar1 != '\0') {
      local_18 = 0;
      cVar1 = FUN_004640c0(&DAT_00956338,local_14 + 0x5fc);
      if (cVar1 != '\0') {
        local_18 = 1;
      }
      FUN_007979e8(local_18);
      FUN_007979e8(local_18);
    }
  }
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return uVar3;
}



