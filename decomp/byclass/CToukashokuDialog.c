/* CToukashokuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CToukashokuDialog[1] */
/* 00408110  FUN_00408110  68 bytes, 0 callers */

undefined4 FUN_00408110(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004080c0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x238);
    }
  }
  return in_ECX;
}




/* vtable slots: CToukashokuDialog[64] */
/* 00408160  FUN_00408160  245 bytes, 0 callers */

void FUN_00408160(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078f5bc(param_1,*(undefined4 *)(in_ECX + 0xa8),0,0xff);
  FUN_0078f801(param_1,0xa13,in_ECX + 0xa8);
  FUN_0078f5bc(param_1,*(undefined4 *)(in_ECX + 0xac),0,0xff);
  FUN_0078f801(param_1,0xa14,in_ECX + 0xac);
  FUN_0078f5bc(param_1,*(undefined4 *)(in_ECX + 0xb0),0,0xff);
  FUN_0078f801(param_1,0xa15,in_ECX + 0xb0);
  FUN_0078fb9c(param_1,0xa13,in_ECX + 0xb8);
  FUN_0078fb9c(param_1,0xa14,in_ECX + 0x138);
  FUN_0078fb9c(param_1,0xa15,in_ECX + 0x1b8);
  return;
}




/* vtable slots: CToukashokuDialog[10] */
/* 00408260  FUN_00408260  16 bytes, 0 callers */

void FUN_00408260(void)

{
  FUN_00408280();
  return;
}




/* vtable slots: CToukashokuDialog[0] */
/* 00408270  FUN_00408270  16 bytes, 0 callers */

undefined ** FUN_00408270(void)

{
  return &PTR_s_CToukashokuDialog_00955b50;
}



