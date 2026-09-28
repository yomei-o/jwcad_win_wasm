/* CColorButton2 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CColorButton2[1] */
/* 0041bba0  FUN_0041bba0  68 bytes, 0 callers */

undefined4 FUN_0041bba0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041bb80();
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




/* vtable slots: CColorButton2[90] */
/* 0041bbf0  FUN_0041bbf0  935 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0041bbf0(tagDRAWITEMSTRUCT *param_1)

{
  CDC *pCVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  CBitmapButton *in_ECX;
  undefined1 *puVar5;
  undefined4 uVar6;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  char local_240;
  char local_23c;
  char local_238;
  uint local_234;
  undefined1 local_22c [16];
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  CBitmapButton::DrawItem(in_ECX,param_1);
  pCVar1 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  iVar2 = DAT_00a0b410;
  local_234 = *(uint *)(DAT_00a0b410 + 0x52f0 + DAT_00a0b428 * 4);
  FUN_00403cd0(local_20c,L"%2d      ",DAT_00a0b428);
  if (99 < DAT_00a0b428) {
    FUN_00403cd0(local_20c,L"S%2d      ",DAT_00a0b428 + -100);
  }
  if (*(int *)(iVar2 + 0x5e18) != 0) {
    FUN_00403cd0(local_20c,&DAT_00957e04);
    local_234 = *(uint *)(iVar2 + 0x5e1c);
  }
  (**(code **)(*(int *)pCVar1 + 0x2c))(0xd6e7e7);
  local_21c = *(int *)(param_1 + 0x1c);
  local_218 = *(int *)(param_1 + 0x20);
  local_214 = *(int *)(param_1 + 0x24);
  local_210 = *(int *)(param_1 + 0x28);
  iVar2 = local_218 + local_210;
  local_250 = FUN_004f74b0(6);
  local_250 = iVar2 / 2 - local_250;
  iVar2 = local_218 + local_210;
  local_248 = FUN_004f74b0(6);
  local_248 = iVar2 / 2 + local_248;
  local_254 = FUN_004f72f0(0x1c);
  local_254 = local_254 + local_21c;
  local_24c = FUN_004f72f0(4);
  local_24c = local_214 - local_24c;
  if ((*(uint *)(param_1 + 0x10) & 4) == 0) {
    (**(code **)(*(int *)pCVar1 + 0x30))(0);
  }
  else {
    (**(code **)(*(int *)pCVar1 + 0x30))(&DAT_00a0a0a0);
    local_238 = (char)((int)((0xff - (local_234 & 0xff)) * 2) / 3) + (char)local_234;
    local_23c = (char)(((0xff - ((int)(local_234 & 0xffff) >> 8)) * 2) / 3) +
                (char)((local_234 & 0xffff) >> 8);
    local_240 = (char)((int)((0xff - (local_234 >> 0x10 & 0xff)) * 2) / 3) +
                (char)(local_234 >> 0x10);
    local_234 = (uint)CONCAT12(local_240,CONCAT11(local_23c,local_238));
  }
  if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
    uVar6 = 4;
    puVar5 = local_20c;
    uVar3 = FUN_004f74b0(6);
    uVar4 = FUN_004f72f0(4);
    (**(code **)(*(int *)pCVar1 + 0x5c))(uVar4,uVar3,puVar5,uVar6);
  }
  else {
    uVar6 = 4;
    puVar5 = local_20c;
    uVar3 = FUN_004f74b0(8);
    uVar4 = FUN_004f72f0(6);
    (**(code **)(*(int *)pCVar1 + 0x5c))(uVar4,uVar3,puVar5,uVar6);
    local_250 = local_250 + 1;
    local_248 = local_248 + 1;
    local_254 = local_254 + 1;
    local_24c = local_24c + 1;
  }
  FUN_00416040(local_254,local_250,local_24c,local_248);
  FUN_007a506d(local_22c,local_234);
  return;
}




/* vtable slots: CColorButton2[10] */
/* 0041bfa0  FUN_0041bfa0  16 bytes, 0 callers */

void FUN_0041bfa0(void)

{
  FUN_0041bfb0();
  return;
}



