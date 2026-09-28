/* CBitmap -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBitmap[1] */
/* 00416290  FUN_00416290  65 bytes, 0 callers */

undefined4 FUN_00416290(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00416080();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,8);
    }
  }
  return in_ECX;
}




/* vtable slots: CBitmap[0], CPngImage[0] */
/* 0079eb1a  FUN_0079eb1a  6 bytes, 0 callers */

undefined ** FUN_0079eb1a(void)

{
  return &PTR_s_CBitmap_0097dfac;
}



