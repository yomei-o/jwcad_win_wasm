/* CLayerControlButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CLayerControlButton[1] */
/* 0055cd70  FUN_0055cd70  68 bytes, 0 callers */

undefined4 FUN_0055cd70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0055ccf0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xd0);
    }
  }
  return in_ECX;
}




/* vtable slots: CLayerControlButton[90] */
/* 0055e970  FUN_0055e970  91 bytes, 0 callers */

void FUN_0055e970(tagDRAWITEMSTRUCT *param_1)

{
  CDC *pCVar1;
  CBitmapButton *in_ECX;
  undefined4 local_8;
  
  CBitmapButton::DrawItem(in_ECX,param_1);
  local_8 = 0;
  if ((*(uint *)(param_1 + 0x10) & 1) != 0) {
    local_8 = FUN_004f72f0(1);
  }
  pCVar1 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  FUN_0055cdc0(pCVar1,local_8);
  return;
}




/* vtable slots: CLayerControlButton[10] */
/* 0055e9d0  FUN_0055e9d0  16 bytes, 0 callers */

void FUN_0055e9d0(void)

{
  FUN_0055e9e0();
  return;
}



