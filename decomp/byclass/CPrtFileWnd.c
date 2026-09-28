/* CPrtFileWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPrtFileWnd[1] */
/* 005b6f10  FUN_005b6f10  68 bytes, 0 callers */

undefined4 FUN_005b6f10(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005b6e80();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xc0);
    }
  }
  return in_ECX;
}




/* vtable slots: CPrtFileWnd[64] */
/* 005b6fc0  DoDataExchange  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCWindowsManagerDialog::DoDataExchange(class CDataExchange
   *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCWindowsManagerDialog::DoDataExchange(CMFCWindowsManagerDialog *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  DDX_Text(param_1,0x5cf,this + 0xa8);
  return;
}




/* vtable slots: CPrtFileWnd[93] */
/* 005b7000  FUN_005b7000  27 bytes, 1 callers */

undefined4 FUN_005b7000(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0079850d();
  return uVar1;
}




/* vtable slots: CPrtFileWnd[10] */
/* 005b7020  FUN_005b7020  16 bytes, 0 callers */

void FUN_005b7020(void)

{
  FUN_005b7210();
  return;
}




/* vtable slots: CPrtFileWnd[94] */
/* 005b7330  FUN_005b7330  244 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005b7330(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
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
  puStack_c = &LAB_00931d2d;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  FUN_005977f0(0x1638);
  local_8 = 0;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404770();
  FUN_00413f30();
  puVar2 = (undefined4 *)FUN_005b7030(local_34);
  local_24 = *puVar2;
  local_20 = puVar2[1];
  local_1c = puVar2[2];
  local_18 = puVar2[3];
  uVar6 = 1;
  uVar3 = FUN_00416780(1);
  uVar4 = FUN_00416ff0(uVar3);
  iVar5 = std::allocator<char>::allocator<char>((allocator<char> *)&local_24);
  uVar1 = *(undefined4 *)(iVar5 + 4);
  puVar2 = (undefined4 *)std::allocator<char>::allocator<char>((allocator<char> *)&local_24);
  FUN_00797ce1(*puVar2,uVar1,uVar4,uVar3,uVar6);
  FUN_005b74f0();
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CPrtFileWnd[72] */
/* 005b74d0  FUN_005b74d0  27 bytes, 0 callers */

void FUN_005b74d0(void)

{
  FUN_005b6f60();
  guard_check_icall();
  return;
}



