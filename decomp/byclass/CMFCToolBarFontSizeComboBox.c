/* CMFCToolBarFontSizeComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarFontSizeComboBox[1] */
/* 00828162  FUN_00828162  57 bytes, 0 callers */

void FUN_00828162(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCToolBarFontSizeComboBox::vftable;
  FUN_00825493();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CMFCToolBarFontSizeComboBox[53] */
/* 00828407  FUN_00828407  122 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00828407(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  CMFCFontComboBox *this;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  this = (CMFCFontComboBox *)FUN_0078e624(0x90);
  piVar3 = (int *)0x0;
  if (this != (CMFCFontComboBox *)0x0) {
    piVar3 = (int *)CMFCFontComboBox::CMFCFontComboBox(this);
  }
  pcVar1 = *(code **)(*piVar3 + 0x164);
  guard_check_icall(*(undefined4 *)(in_ECX + 0x8c),param_2,param_1,*(undefined4 *)(in_ECX + 0x20));
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*piVar3 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    piVar3 = (int *)0x0;
  }
  return piVar3;
}




/* vtable slots: CMFCToolBarFontSizeComboBox[0] */
/* 00828617  FUN_00828617  6 bytes, 0 callers */

undefined ** FUN_00828617(void)

{
  return &PTR_s_CMFCToolBarFontSizeComboBox_00a00850;
}



