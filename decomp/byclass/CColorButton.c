/* CColorButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CColorButton[1] */
/* 0041b440  FUN_0041b440  68 bytes, 0 callers */

undefined4 FUN_0041b440(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041b3d0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa8);
    }
  }
  return in_ECX;
}




/* vtable slots: CColorButton[90] */
/* 0041b490  FUN_0041b490  254 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0041b490(tagDRAWITEMSTRUCT *param_1)

{
  int iVar1;
  int iVar2;
  CBitmapButton *in_ECX;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined1 local_28 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  CBitmapButton::DrawItem(in_ECX,param_1);
  CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  local_18 = *(int *)(param_1 + 0x1c);
  local_14 = *(int *)(param_1 + 0x20);
  local_10 = *(int *)(param_1 + 0x24);
  local_c = *(int *)(param_1 + 0x28);
  iVar1 = (local_14 + local_c) / 2;
  local_34 = iVar1 + -2;
  iVar2 = (local_14 + local_c) / 2;
  local_2c = iVar2 + 2;
  local_38 = local_18 + 0x10;
  local_30 = local_10 + -6;
  if ((*(uint *)(param_1 + 0x10) & 1) != 0) {
    local_34 = iVar1 + -1;
    local_2c = iVar2 + 3;
    local_38 = local_18 + 0x11;
    local_30 = local_10 + -5;
  }
  FUN_00416040(local_38,local_34,local_30,local_2c);
  FUN_007a506d(local_28,*(undefined4 *)(DAT_00a0b410 + 0x52f0 + *(int *)(in_ECX + 0xa4) * 4));
  return;
}




/* vtable slots: CColorButton[10] */
/* 0041b5b0  FUN_0041b5b0  16 bytes, 0 callers */

void FUN_0041b5b0(void)

{
  FUN_0041b5e0();
  return;
}



