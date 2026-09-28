/* CPrtFileDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPrtFileDlg[1] */
/* 005b0a60  FUN_005b0a60  68 bytes, 0 callers */

undefined4 FUN_005b0a60(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005b08d0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1470);
    }
  }
  return in_ECX;
}




/* vtable slots: CPrtFileDlg[64] */
/* 005b0b40  FUN_005b0b40  167 bytes, 0 callers */

void FUN_005b0b40(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x7cb,in_ECX + 0x160);
  FUN_0078fb9c(param_1,0x7cc,in_ECX + 0x1e0);
  FUN_0078fb9c(param_1,0x8a1,in_ECX + 0x2e0);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x260);
  FUN_0078fb9c(param_1,0x6ef,in_ECX + 0x360);
  FUN_0078f643(param_1,0x8a1,in_ECX + 1000);
  return;
}




/* vtable slots: CPrtFileDlg[93] */
/* 005b0bf0  FUN_005b0bf0  32 bytes, 9 callers */

void FUN_005b0bf0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1434) = 1;
  FUN_0079850d();
  return;
}




/* vtable slots: CPrtFileDlg[10] */
/* 005b1070  FUN_005b1070  16 bytes, 0 callers */

void FUN_005b1070(void)

{
  FUN_005b1650();
  return;
}




/* vtable slots: CPrtFileDlg[97] */
/* 005b2d00  FUN_005b2d00  52 bytes, 0 callers */

void FUN_005b2d00(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xbc8) = 0;
  DAT_00a0cc8c = 0;
  DAT_00a0b3d0 = 0;
  FUN_00798826();
  return;
}




/* vtable slots: CPrtFileDlg[94] */
/* 005b2dc0  FUN_005b2dc0  1887 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005b2dc0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  CGdiObject local_98 [12];
  uint local_8c;
  int local_88;
  CImageList *local_84;
  CImageList *local_80;
  CImageList *local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  int local_58;
  undefined1 local_44 [16];
  allocator<char> local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093183c;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  local_64 = *(int *)(local_58 + 0x1438) + -0x3c;
  switch(*(int *)(local_58 + 0x1438)) {
  case 0x3c:
    FUN_00797f20(0);
    FUN_00797f20(5);
    break;
  default:
    FUN_00797f20(0);
    FUN_00797f20(0);
    break;
  case 0x46:
    FUN_00797f20(5);
    FUN_00797f20(5);
    break;
  case 0x50:
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_005977f0(0x1628);
    local_8 = 2;
    uVar1 = FUN_00404920();
    FUN_00797ece(uVar1);
    local_8 = 0xffffffff;
    FUN_00404770();
    break;
  case 0x5a:
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_005977f0(0x163b);
    local_8 = 3;
    uVar1 = FUN_00404920();
    FUN_00797ece(uVar1);
    local_8 = 0xffffffff;
    FUN_00404770();
    break;
  case 100:
    FUN_00797f20(0);
    FUN_00797f20(5);
    FUN_005977f0(0x163d);
    local_8 = 0;
    uVar1 = FUN_00404920();
    FUN_00797ece(uVar1);
    local_8 = 0xffffffff;
    FUN_00404770();
    break;
  case 0x6e:
    FUN_00797f20(0);
    FUN_00797f20(5);
    FUN_005977f0(0x163d);
    local_8 = 1;
    uVar1 = FUN_00404920();
    FUN_00797ece(uVar1);
    local_8 = 0xffffffff;
    FUN_00404770();
  }
  FUN_007955d2(0);
  if (*(int *)(local_58 + 0xb4) != 0) {
    FUN_004b1140(*(undefined4 *)(local_58 + 0xb4));
    FUN_007955d2(1);
  }
  uVar5 = 0x75a;
  iVar3 = local_58;
  uVar1 = FUN_00416040(100,100,0x6e,0x6e);
  FUN_007a41cf(0x42000001,uVar1,iVar3,uVar5);
  uVar2 = GetWindowLongW(*(HWND *)(local_58 + 0xe8),-0x10);
  SetWindowLongW(*(HWND *)(local_58 + 0xe8),-0x10,uVar2 | 0x40000008);
  FUN_00413f30();
  uVar1 = std::allocator<char>::allocator<char>(local_34);
  FUN_00416570(uVar1);
  FUN_00416ff0();
  local_68 = GetSystemMetrics(10);
  local_74 = FUN_0058f2e0(L"filename.jww");
  local_60 = FUN_0058f2e0(L"1999/12/12 20:20:30");
  iVar3 = GetSystemMetrics(5);
  local_74 = iVar3 * 0xc + local_74;
  iVar3 = GetSystemMetrics(5);
  local_60 = iVar3 * 0xc + local_60;
  FUN_007a4672(1,L"Name  ",0,local_74 + local_68,1);
  FUN_007a4672(2,L"Date  ",0,local_60 + local_68,2);
  FUN_007a4672(3,L"MEMO  ",0,local_68 + local_60 * 2,3);
  uVar1 = FUN_005977f0(0x1642);
  local_8 = 4;
  FUN_00403dd0(uVar1);
  local_8._0_1_ = 6;
  FUN_00404770();
  uVar6 = 4;
  iVar3 = local_68 + local_60 * 2;
  uVar5 = 0;
  uVar1 = FUN_00404920(0,iVar3,4);
  FUN_007a4672(4,uVar1,uVar5,iVar3,uVar6);
  local_78 = 0x10;
  local_88 = 0xf;
  local_8c = FUN_004f6180(0xa3e);
  uVar2 = FUN_004f6180(0xa52);
  local_6c = local_8c - 0xa3f;
  switch(local_6c) {
  case 0:
    local_5c = 0x7d;
    break;
  case 1:
    local_5c = 0x96;
    break;
  case 2:
    local_5c = 0xaf;
    break;
  case 3:
    local_5c = 200;
    break;
  case 4:
    local_5c = 0xe1;
    break;
  case 5:
    local_5c = 0xfa;
    break;
  case 6:
    local_5c = 300;
    break;
  case 7:
    local_5c = 400;
    break;
  case 8:
    local_5c = 500;
    break;
  default:
    local_5c = 100;
  }
  local_78 = (local_5c << 4) / 100;
  local_88 = local_78 - local_5c / 100;
  local_80 = (CImageList *)FUN_004121b0(8);
  local_8._0_1_ = 7;
  if (local_80 == (CImageList *)0x0) {
    local_84 = (CImageList *)0x0;
  }
  else {
    local_84 = (CImageList *)CImageList::CImageList(local_80);
  }
  local_8._0_1_ = 6;
  local_7c = local_84;
  CImageList::Create(local_84,local_78,local_88,9,3,2);
  FUN_00415f10();
  local_8 = CONCAT31(local_8._1_3_,8);
  for (local_70 = local_8c; local_70 <= uVar2; local_70 = local_70 + 10) {
    FUN_004167a0(local_70);
    FUN_00416380(local_98,0xffffff);
    CGdiObject::DeleteObject(local_98);
  }
  FUN_00416fb0(local_7c,0);
  if ((*(int *)(local_58 + 0x1438) != 0x15) && (*(int *)(local_58 + 0x1438) != 0x14)) {
    FUN_00599340(*(undefined4 *)(local_58 + 0x1438));
  }
  uVar1 = FUN_005b15f0();
  *(undefined4 *)(local_58 + 0x145c) = uVar1;
  FUN_00413f30();
  puVar4 = (undefined4 *)FUN_005b1410(local_44);
  local_24 = *puVar4;
  local_20 = puVar4[1];
  local_1c = puVar4[2];
  local_18 = puVar4[3];
  uVar7 = 1;
  uVar5 = FUN_00416780(1);
  uVar6 = FUN_00416ff0(uVar5);
  iVar3 = std::allocator<char>::allocator<char>((allocator<char> *)&local_24);
  uVar1 = *(undefined4 *)(iVar3 + 4);
  puVar4 = (undefined4 *)std::allocator<char>::allocator<char>((allocator<char> *)&local_24);
  FUN_00797ce1(*puVar4,uVar1,uVar6,uVar5,uVar7);
  FUN_005b3d80();
  FUN_005b5770();
  DAT_00a0cc8c = 1;
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_00416080();
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CPrtFileDlg[72] */
/* 005b3d50  FUN_005b3d50  47 bytes, 0 callers */

void FUN_005b3d50(void)

{
  FUN_005b0ab0();
  guard_check_icall();
  DAT_00a0cc8c = 0;
  DAT_00a0b3d0 = 0;
  return;
}



