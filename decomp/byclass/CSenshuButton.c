/* CSenshuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSenshuButton[1] */
/* 005c2800  FUN_005c2800  68 bytes, 0 callers */

undefined4 FUN_005c2800(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005c27e0();
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




/* vtable slots: CSenshuButton[90] */
/* 005c2850  FUN_005c2850  337 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005c2850(tagDRAWITEMSTRUCT *param_1)

{
  CBitmapButton *in_ECX;
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined4 local_40;
  CDC *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  CBitmapButton *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = DAT_00a0b410;
  local_2c = in_ECX;
  CBitmapButton::DrawItem(in_ECX,param_1);
  local_3c = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  local_18 = *(int *)(param_1 + 0x1c);
  local_14 = *(int *)(param_1 + 0x20);
  local_10 = *(int *)(param_1 + 0x24);
  local_c = *(int *)(param_1 + 0x28);
  local_1c = (local_14 + local_c) / 2;
  local_24 = local_18 + 0x10;
  local_28 = local_10 + -6;
  if ((*(uint *)(param_1 + 0x10) & 1) != 0) {
    local_1c = local_1c + 1;
    local_24 = local_18 + 0x11;
    local_28 = local_10 + -5;
  }
  FUN_0041c8d0(local_24,local_1c);
  FUN_0041c8d0(local_28,local_1c);
  local_38 = *(undefined4 *)(local_20 + 0x304c + *(int *)(local_2c + 0xa0) * 4);
  local_34 = 0;
  local_40 = DAT_00a0b440;
  DAT_00a0b440 = 1;
  if (local_20 == 0) {
    local_30 = 0;
  }
  else {
    local_30 = local_20 + 0x88;
  }
  FUN_004bbef0(local_30,local_3c,*(undefined4 *)(local_2c + 0xa0),&local_38,&local_34,local_50,
               local_48,0,1);
  DAT_00a0b440 = local_40;
  return;
}




/* vtable slots: CSenshuButton[10] */
/* 005c29b0  FUN_005c29b0  16 bytes, 0 callers */

void FUN_005c29b0(void)

{
  FUN_005c29c0();
  return;
}



