/* CFontComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFontComboBox[1] */
/* 004b01c0  FUN_004b01c0  68 bytes, 0 callers */

undefined4 FUN_004b01c0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004b0100();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa0);
    }
  }
  return in_ECX;
}




/* vtable slots: CFontComboBox[92] */
/* 004b0480  FUN_004b0480  276 bytes, 0 callers */

undefined4 FUN_004b0480(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925df5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(ushort *)(param_1 + 0xc);
  uVar2 = *(ushort *)(param_1 + 0x14);
  CStringT<>(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  CStringT<>();
  local_8._0_1_ = 1;
  if (uVar1 == 0xffffffff) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00404540();
    uVar3 = 0xffffffff;
  }
  else if (uVar2 == 0xffffffff) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00404540();
    uVar3 = 1;
  }
  else {
    GetLBText((uint)uVar1,local_18);
    GetLBText((uint)uVar2,local_14);
    uVar3 = FUN_00404920();
    uVar3 = FUN_004b0450(uVar3);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return uVar3;
}




/* vtable slots: CFontComboBox[90] */
/* 004b05e0  FUN_004b05e0  568 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004b05e0(int param_1)

{
  uint uVar1;
  ulong uVar2;
  DWORD DVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  CDC local_5c [16];
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  int local_40;
  undefined1 local_3c [8];
  int local_34;
  uint local_30;
  CSimpleStringT<wchar_t,0> local_2c [4];
  CDC *local_28;
  int local_24;
  undefined4 local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925e3d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_48 = (uint)*(ushort *)(param_1 + 8);
  local_14 = uVar1;
  local_28 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  CRect(param_1 + 0x1c);
  if ((*(uint *)(param_1 + 0x10) & 0x10) != 0) {
    uVar2 = std::allocator<char>::allocator<char>((allocator<char> *)&local_24);
    CMenu::SetMenuContextHelpId((CMenu *)local_28,uVar2);
  }
  local_4c = (**(code **)(*(int *)local_28 + 0x1c))(uVar1);
  FUN_00480800();
  local_8 = 0;
  if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
    uVar4 = FUN_00489e40();
    FUN_004b05a0(uVar4);
  }
  else {
    DVar3 = GetSysColor(0xd);
    FUN_004b05a0(DVar3);
    DVar3 = GetSysColor(0xe);
    (**(code **)(*(int *)local_28 + 0x30))(DVar3);
  }
  FUN_0079f0b8(1);
  puVar6 = local_3c;
  uVar4 = std::allocator<char>::allocator<char>((allocator<char> *)&local_24);
  FUN_004b0df0(uVar4,puVar6);
  local_40 = *(int *)(param_1 + 0x2c);
  local_30 = *(uint *)(local_40 + 0xc);
  if ((local_30 & 0x600) != 0) {
    CDC::CDC(local_5c);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00481570(local_28);
    local_44 = FUN_0048cb30(local_34 + 0x98);
    if ((local_30 & 0x200) == 0) {
      FUN_004b0410(local_24,local_20,0x10,0xf,local_5c,0,0,0x8800c6);
    }
    else {
      FUN_004b0410(local_24,local_20,0x10,0xf,local_5c,0x10,0,0x8800c6);
    }
    FUN_0048cb30(local_44);
    local_8 = local_8 & 0xffffff00;
    FUN_0079e053();
  }
  local_24 = local_24 + 0x16;
  CStringT<>();
  local_8._0_1_ = 2;
  GetLBText(local_48,local_2c);
  iVar5 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_2c);
  uVar4 = FUN_00404920(iVar5);
  (**(code **)(*(int *)local_28 + 0x5c))(local_24,local_20,uVar4);
  (**(code **)(*(int *)local_28 + 0x20))(local_4c);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404540();
  local_8 = 0xffffffff;
  FUN_0041fd10();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CFontComboBox[10] */
/* 004b0f40  FUN_004b0f40  16 bytes, 0 callers */

void FUN_004b0f40(void)

{
  FUN_004b0fa0();
  return;
}




/* vtable slots: CFontComboBox[91] */
/* 004b0fc0  FUN_004b0fc0  105 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004b0fc0(int param_1)

{
  undefined4 uVar1;
  int local_1c;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00413f30();
  FUN_004146a0(local_18);
  uVar1 = FUN_00416ff0();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  if (DAT_00a07fdc < 0xf) {
    local_1c = 0xf;
  }
  else {
    local_1c = DAT_00a07fdc;
  }
  *(int *)(param_1 + 0x10) = local_1c;
  return;
}




/* vtable slots: CFontComboBox[67], CLocalComboBox[67] */
/* 004b10b0  FUN_004b10b0  25 bytes, 0 callers */

void FUN_004b10b0(undefined4 param_1)

{
  FUN_007949fb(param_1);
  return;
}



