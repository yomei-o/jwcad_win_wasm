/* CMyFileDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyFileDialog[1] */
/* 0058dd00  FUN_0058dd00  68 bytes, 0 callers */

undefined4 FUN_0058dd00(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0058dae0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1118);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyFileDialog[64] */
/* 0058e000  FUN_0058e000  569 bytes, 0 callers */

void FUN_0058e000(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x7d2,in_ECX + 0x150);
  FUN_0078fb9c(param_1,0x7d3,in_ECX + 0x1d0);
  FUN_0078fb9c(param_1,0x968,in_ECX + 0x250);
  FUN_0078fb9c(param_1,0xb31,in_ECX + 0x350);
  FUN_0078fb9c(param_1,0xb32,in_ECX + 0x3d0);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x2d0);
  FUN_0078fb9c(param_1,0x827,in_ECX + 0x450);
  FUN_0078fb9c(param_1,0x826,in_ECX + 0x4d0);
  FUN_0078fb9c(param_1,0xa0f,in_ECX + 0x550);
  FUN_0078fb9c(param_1,1999,in_ECX + 0x5d0);
  FUN_0078fb9c(param_1,0x6ef,in_ECX + 0x650);
  FUN_0078fb9c(param_1,0x6c8,in_ECX + 0x6d8);
  FUN_0078fb9c(param_1,0x6c7,in_ECX + 0x758);
  FUN_0078fb9c(param_1,0x6c9,in_ECX + 0x7d8);
  FUN_0078f801(param_1,0x826,in_ECX + 0x858);
  FUN_0078f801(param_1,0x827,in_ECX + 0x85c);
  DDX_Text(param_1,0x5cf,in_ECX + 0x860);
  FUN_0078f801(param_1,0xa0f,in_ECX + 0x878);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x864);
  FUN_0078f6f8(param_1,0xb31,in_ECX + 0x868);
  FUN_0078f6f8(param_1,0xb32,in_ECX + 0x86c);
  FUN_0078f643(param_1,0x7d2,in_ECX + 0x870);
  FUN_0078f643(param_1,0x7d3,in_ECX + 0x874);
  return;
}




/* vtable slots: CMyFileDialog[93] */
/* 0058e240  FUN_0058e240  74 bytes, 6 callers */

undefined4 FUN_0058e240(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar2 = DAT_00a0ca90;
  uVar1 = DAT_00a0ca78;
  *(undefined4 *)(in_ECX + 0x10d4) = 1;
  uVar3 = FUN_0079850d();
  DAT_00a0ca90 = uVar2;
  DAT_00a0ca78 = uVar1;
  return uVar3;
}




/* vtable slots: CMyFileDialog[10] */
/* 0058e700  FUN_0058e700  16 bytes, 0 callers */

void FUN_0058e700(void)

{
  FUN_0058f310();
  return;
}




/* vtable slots: CMyFileDialog[97] */
/* 00592310  FUN_00592310  149 bytes, 0 callers */

void FUN_00592310(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  DAT_00a0cc8c = 0;
  if (*(int *)(in_ECX + 0x1108) != 0) {
    *(undefined4 *)(in_ECX + 0x1108) = 0;
    DAT_00a0d8a0 = *(undefined4 *)(in_ECX + 0x1104);
  }
  DAT_00a0b3d0 = 0;
  iVar1 = *(int *)(in_ECX + 0x10d8);
  if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) {
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = 0x1408;
    FUN_00404c80(0x1408,0,0);
    FUN_00799e17();
    FUN_00406bc0(uVar2,uVar3,uVar4);
  }
  FUN_00798826();
  return;
}




/* vtable slots: CMyFileDialog[94] */
/* 00592810  FUN_00592810  1941 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00592810(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_a8 [4];
  undefined4 local_a4;
  undefined4 local_a0;
  int local_9c;
  CGdiObject local_98 [8];
  uint local_90;
  int local_8c;
  CImageList *local_88;
  CImageList *local_84;
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
  undefined1 local_54 [32];
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
  puStack_c = &LAB_0092fa98;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  if (*(int *)(local_58 + 0x10d8) == 0xc) {
    FUN_00404860(&DAT_00a0bc84);
  }
  else if (*(int *)(local_58 + 0x10d8) == 0x32) {
    FUN_00404900(&DAT_00a09374);
  }
  else if ((0 < *(int *)(local_58 + 0x10d8)) && (*(int *)(local_58 + 0x10d8) < 5)) {
    iVar3 = *(int *)(&DAT_00a0bc54 + *(int *)(local_58 + 0x10d8) * 4) + 0x41;
    uVar1 = *(undefined4 *)(local_58 + 0x10d8);
    local_9c = iVar3;
    local_a4 = ATL::operator+(local_a8,(wchar_t *)(&DAT_00a0bc6c + *(int *)(local_58 + 0x10d8) * 4))
    ;
    local_8 = 0;
    local_a0 = local_a4;
    uVar1 = FUN_00404920(uVar1,iVar3);
    FUN_004059f0(local_58 + 0x6d4,uVar1);
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  if (*(int *)(local_58 + 0x10dc) == 0) {
    FUN_00797f20(0);
  }
  else {
    FUN_00797f20(5);
    FUN_00797f20(0);
    FUN_00797f20(0);
  }
  local_68 = *(int *)(local_58 + 0x10d8) + -10;
  switch(local_68) {
  case 0:
    FUN_004b1140(0);
    break;
  case 1:
    FUN_004b1140(1);
    break;
  case 2:
    if (*(int *)(local_58 + 0x10dc) == 0) {
      FUN_00797f20(5);
    }
    if (DAT_00a0b388 < 1) {
      FUN_004b1140(0);
    }
    else {
      FUN_004b1140(1);
    }
    FUN_00797f20(0);
    FUN_00797f20(0);
    break;
  case 3:
    FUN_004b1140(2);
    break;
  case 4:
    FUN_004b1140(3);
    break;
  default:
    FUN_00797f20(0);
  }
  if (*(int *)(local_58 + 0x10d8) != 0xc) {
    FUN_00797f20(0);
  }
  if ((*(int *)(local_58 + 0x10d8) < 1) || (4 < *(int *)(local_58 + 0x10d8))) {
    FUN_00797f20(0);
  }
  uVar5 = 0x75a;
  iVar3 = local_58;
  uVar1 = FUN_00416040(100,100,0x6e,0x6e);
  FUN_007a41cf(0x42000001,uVar1,iVar3,uVar5);
  uVar2 = GetWindowLongW(*(HWND *)(local_58 + 0xd8),-0x10);
  SetWindowLongW(*(HWND *)(local_58 + 0xd8),-0x10,uVar2 | 0x40000208);
  FUN_00413f30();
  uVar1 = std::allocator<char>::allocator<char>(local_34);
  FUN_00416570(uVar1);
  FUN_00416ff0();
  local_64 = GetSystemMetrics(10);
  local_74 = FUN_0058f2e0(L"filename.jww");
  local_60 = FUN_0058f2e0(L"1999/12/12 20:20:30");
  iVar3 = GetSystemMetrics(5);
  local_74 = iVar3 * 0xc + local_74;
  iVar3 = GetSystemMetrics(5);
  local_60 = iVar3 * 0xc + local_60;
  FUN_007a4672(1,L"Name  ",0,local_74 + local_64,1);
  FUN_007a4672(2,L"Date  ",0,local_60 + local_64,2);
  FUN_007a4672(3,L"MEMO  ",0,local_64 + local_60 * 2,3);
  if ((((*(int *)(local_58 + 0x10d8) == 10) || (*(int *)(local_58 + 0x10d8) == 0xb)) ||
      (*(int *)(local_58 + 0x10d8) == 0xd)) || (*(int *)(local_58 + 0x10d8) == 0xe)) {
    uVar1 = FUN_005977f0(0x1642);
    local_8 = 1;
    FUN_00403dd0(uVar1);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00404770();
    uVar6 = 4;
    iVar3 = local_64 + local_60 * 2;
    uVar5 = 0;
    uVar1 = FUN_00404920(0,iVar3,4);
    FUN_007a4672(4,uVar1,uVar5,iVar3,uVar6);
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  else {
    FUN_007a4672(4,&DAT_00966290,0,local_64 + local_60 * 2,4);
  }
  local_78 = 0x10;
  local_8c = 0xf;
  local_90 = FUN_004f6180(0xa3e);
  uVar2 = FUN_004f6180(0xa52);
  local_6c = local_90 - 0xa3f;
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
  local_8c = local_78 - local_5c / 100;
  local_84 = (CImageList *)FUN_004121b0(8);
  local_8 = 4;
  if (local_84 == (CImageList *)0x0) {
    local_88 = (CImageList *)0x0;
  }
  else {
    local_88 = (CImageList *)CImageList::CImageList(local_84);
  }
  local_8 = 0xffffffff;
  local_7c = local_88;
  CImageList::Create(local_88,local_78,local_8c,9,3,2);
  FUN_00415f10();
  local_8 = 5;
  for (local_70 = local_90; local_70 <= uVar2; local_70 = local_70 + 10) {
    FUN_004167a0(local_70);
    FUN_00416380(local_98,0xffffff);
    CGdiObject::DeleteObject(local_98);
  }
  FUN_00416fb0(local_7c,0);
  if ((*(int *)(local_58 + 0x10d8) != 0x15) && (*(int *)(local_58 + 0x10d8) != 0x14)) {
    FUN_00599340(*(undefined4 *)(local_58 + 0x10d8));
  }
  uVar1 = FUN_0058f270();
  *(undefined4 *)(local_58 + 0x10fc) = uVar1;
  FUN_00413f30();
  puVar4 = (undefined4 *)FUN_0058f090(local_54);
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
  FUN_00594880();
  FUN_00595270();
  DAT_00a0cc8c = 1;
  local_8 = 0xffffffff;
  FUN_00416080();
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CMyFileDialog[72] */
/* 00594560  FUN_00594560  95 bytes, 0 callers */

void FUN_00594560(void)

{
  int in_ECX;
  
  FUN_0058df70();
  guard_check_icall();
  DAT_00a0cc8c = 0;
  if (*(int *)(in_ECX + 0x1108) != 0) {
    *(undefined4 *)(in_ECX + 0x1108) = 0;
    DAT_00a0d8a0 = *(undefined4 *)(in_ECX + 0x1104);
  }
  DAT_00a0b3d0 = 0;
  return;
}




/* vtable slots: CMyFileDialog[67] */
/* 005945c0  FUN_005945c0  210 bytes, 0 callers */

int FUN_005945c0(tagMSG *param_1)

{
  int iVar1;
  CDialog *in_ECX;
  tagPOINT local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  CDialog *local_8;
  
  local_8 = in_ECX;
  if (((param_1->message == 0x20a) || (param_1->message == 0xce11)) &&
     (*(int *)(in_ECX + 0x864) == 0)) {
    FUN_004044d0();
    GetCursorPos(&local_1c);
    FUN_004eed00(&local_1c);
    if (*(int *)(local_8 + 0x10fc) < local_1c.x) {
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      if (((param_1->wParam & 0xffff0000) == 0xff880000) || ((param_1->wParam & 0xffff) == 0xff88))
      {
        local_c = 1;
      }
      FUN_005943c0(local_c,0,0);
      return 1;
    }
  }
  iVar1 = CDialog::PreTranslateMessage(local_8,param_1);
  return iVar1;
}



