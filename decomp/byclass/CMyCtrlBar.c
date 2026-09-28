/* CMyCtrlBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyCtrlBar[1] */
/* 0058cf20  FUN_0058cf20  68 bytes, 0 callers */

COleUpdateDialog * FUN_0058cf20(uint param_1)

{
  COleUpdateDialog *in_ECX;
  
  COleUpdateDialog::~COleUpdateDialog(in_ECX);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1a8);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyCtrlBar[90] */
/* 0058cf70  FUN_0058cf70  260 bytes, 0 callers */

undefined4 * FUN_0058cf70(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  if ((param_3 & 0x40) == 0) {
    local_c = *(uint *)(in_ECX + 0x1a4);
    local_14 = local_c;
    if ((param_3 & 2) == 0) {
      local_10 = (uint)(local_c == 0);
      local_14 = local_10;
    }
    local_18 = local_14;
    if (local_14 != 0) {
      if (local_c == 0) {
        FUN_0058d270();
      }
      else {
        FUN_0058d140();
      }
    }
    FUN_007ad9a2(&local_20,param_2,param_3);
    if (local_18 != 0) {
      if (local_c == 0) {
        FUN_0058d270();
      }
      else {
        FUN_0058d140();
      }
    }
    *param_1 = local_20;
    param_1[1] = local_1c;
  }
  else {
    if ((param_3 & 0x10) == 0) {
      if (*(int *)(in_ECX + 0x1a4) != 0) {
        FUN_0058d140();
      }
    }
    else if (*(int *)(in_ECX + 0x1a4) == 0) {
      FUN_0058d270();
    }
    FUN_007ad9a2(param_1,param_2,param_3);
  }
  return param_1;
}




/* vtable slots: CMyCtrlBar[10] */
/* 0058d080  FUN_0058d080  16 bytes, 0 callers */

void FUN_0058d080(void)

{
  FUN_0058d090();
  return;
}



