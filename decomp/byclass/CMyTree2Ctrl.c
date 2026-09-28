/* CMyTree2Ctrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyTree2Ctrl[1] */
/* 00599ac0  FUN_00599ac0  68 bytes, 0 callers */

undefined4 FUN_00599ac0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00599a50();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xd8);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyTree2Ctrl[10] */
/* 0059a890  FUN_0059a890  16 bytes, 0 callers */

void FUN_0059a890(void)

{
  FUN_0059a8a0();
  return;
}




/* vtable slots: CMyTree2Ctrl[0], CMyTreeCtrl[0], CTreeCtrl[0] */
/* 007a45ea  FUN_007a45ea  6 bytes, 0 callers */

undefined ** FUN_007a45ea(void)

{
  return &PTR_s_CTreeCtrl_0097eae8;
}



