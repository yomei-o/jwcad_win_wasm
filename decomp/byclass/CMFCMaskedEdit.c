/* CMFCMaskedEdit -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCMaskedEdit[1] */
/* 007d8a69  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCMaskedEdit::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCMaskedEdit::_scalar_deleting_destructor_(CMFCMaskedEdit *this,uint param_1)

{
  ~CMFCMaskedEdit(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xb0);
    }
  }
  return this;
}




/* vtable slots: CMFCMaskedEdit[10] */
/* 007d8e98  FUN_007d8e98  6 bytes, 0 callers */

undefined ** FUN_007d8e98(void)

{
  return &PTR_FUN_009889b0;
}




/* vtable slots: CMFCMaskedEdit[0] */
/* 007d8e9e  FUN_007d8e9e  6 bytes, 0 callers */

undefined ** FUN_007d8e9e(void)

{
  return &PTR_s_CMFCMaskedEdit_009886dc;
}




/* vtable slots: CMFCMaskedEdit[89] */
/* 007d8ec3  FUN_007d8ec3  162 bytes, 0 callers */

undefined4 FUN_007d8ec3(wint_t param_1,ushort param_2)

{
  int iVar1;
  undefined4 uVar2;
  _locale_t unaff_EBP;
  
  if (param_2 < 0x45) {
    if (param_2 == 0x44) {
      iVar1 = FID_conflict___iswdigit_l(param_1);
LAB_007d8f52:
      if (iVar1 == 0) goto LAB_007d8f57;
    }
    else {
      if (param_2 == 0x2a) {
        iVar1 = FID_conflict__iswprint(param_1);
        goto LAB_007d8f52;
      }
      if (param_2 != 0x2b) {
        if (param_2 == 0x41) {
          iVar1 = FID_conflict__iswalnum(param_1,unaff_EBP);
        }
        else {
          if (param_2 != 0x43) goto LAB_007d8f57;
          iVar1 = FID_conflict__iswalpha(param_1);
        }
        goto LAB_007d8f52;
      }
      if ((param_1 != 0x2b) && (param_1 != 0x2d)) goto LAB_007d8f4a;
    }
LAB_007d8f08:
    uVar2 = 1;
  }
  else {
    if (param_2 == 0x61) {
      iVar1 = FID_conflict__iswalnum(param_1,unaff_EBP);
LAB_007d8f45:
      if (iVar1 != 0) goto LAB_007d8f08;
LAB_007d8f4a:
      iVar1 = FID_conflict___iswspace_l(param_1,unaff_EBP);
      goto LAB_007d8f52;
    }
    if (param_2 == 99) {
      iVar1 = FID_conflict__iswalpha(param_1);
      goto LAB_007d8f45;
    }
    if (param_2 == 100) {
      iVar1 = FID_conflict___iswdigit_l(param_1);
      goto LAB_007d8f45;
    }
LAB_007d8f57:
    uVar2 = 0;
  }
  return uVar2;
}



