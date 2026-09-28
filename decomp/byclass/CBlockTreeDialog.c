/* CBlockTreeDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBlockTreeDialog[1] */
/* 004162e0  FUN_004162e0  68 bytes, 0 callers */

undefined4 FUN_004162e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004160a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x388);
    }
  }
  return in_ECX;
}




/* vtable slots: CBlockTreeDialog[64] */
/* 004164c0  FUN_004164c0  167 bytes, 0 callers */

void FUN_004164c0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x9fb,in_ECX + 0xa8);
  FUN_0078fb9c(param_1,0x9f4,in_ECX + 0x128);
  FUN_0078fb9c(param_1,0x9f2,in_ECX + 0x1a8);
  FUN_0078fb9c(param_1,0x9f1,in_ECX + 0x228);
  FUN_0078fb9c(param_1,0x6ef,in_ECX + 0x2a8);
  FUN_0078f6f8(param_1,0x9f3,in_ECX + 0x380);
  return;
}




/* vtable slots: CBlockTreeDialog[10] */
/* 00416590  FUN_00416590  16 bytes, 0 callers */

void FUN_00416590(void)

{
  FUN_00416770();
  return;
}




/* vtable slots: CBlockTreeDialog[94] */
/* 00416ad0  FUN_00416ad0  634 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00416ad0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  CGdiObject local_64 [8];
  uint local_5c;
  int local_58;
  CImageList *local_54;
  CImageList *local_50;
  CImageList *local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  int local_3c;
  uint local_38;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920d07;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  *(undefined4 *)(local_3c + 0x328) = 0;
  FUN_00416f00();
  local_48 = 0x10;
  local_58 = 0xf;
  local_5c = FUN_004f6180(0xa3e);
  uVar1 = FUN_004f6180(0xa52);
  local_40 = local_5c - 0xa3f;
  switch(local_40) {
  case 0:
    local_38 = 0x7d;
    break;
  case 1:
    local_38 = 0x96;
    break;
  case 2:
    local_38 = 0xaf;
    break;
  case 3:
    local_38 = 200;
    break;
  case 4:
    local_38 = 0xe1;
    break;
  case 5:
    local_38 = 0xfa;
    break;
  case 6:
    local_38 = 300;
    break;
  case 7:
    local_38 = 400;
    break;
  case 8:
    local_38 = 500;
    break;
  default:
    local_38 = 100;
  }
  local_48 = (local_38 << 4) / 100;
  local_58 = local_48 - local_38 / 100;
  local_50 = (CImageList *)FUN_004121b0(8);
  local_8 = 0;
  if (local_50 == (CImageList *)0x0) {
    local_54 = (CImageList *)0x0;
  }
  else {
    local_54 = (CImageList *)CImageList::CImageList(local_50);
  }
  local_8 = 0xffffffff;
  local_4c = local_54;
  CImageList::Create(local_54,local_48,local_58,9,3,2);
  FUN_00415f10();
  local_8 = 1;
  for (local_44 = local_5c; local_44 <= uVar1; local_44 = local_44 + 10) {
    FUN_004167a0(local_44);
    FUN_00416380(local_64,0xffffff);
    CGdiObject::DeleteObject(local_64);
  }
  FUN_00416fb0(local_4c,0);
  FUN_0059b390(10);
  FUN_00413f30();
  puVar2 = (undefined4 *)FUN_004165a0(local_34);
  local_24 = *puVar2;
  local_20 = puVar2[1];
  local_1c = puVar2[2];
  local_18 = puVar2[3];
  uVar7 = 1;
  uVar3 = FUN_00416780(1);
  uVar4 = FUN_00416ff0(uVar3);
  iVar5 = std::allocator<char>::allocator<char>((allocator<char> *)&local_24);
  uVar6 = *(undefined4 *)(iVar5 + 4);
  puVar2 = (undefined4 *)std::allocator<char>::allocator<char>((allocator<char> *)&local_24);
  FUN_00797ce1(*puVar2,uVar6,uVar4,uVar3,uVar7);
  FUN_00416dc0();
  local_8 = 0xffffffff;
  FUN_00416080();
  ExceptionList = local_10;
  return 1;
}



