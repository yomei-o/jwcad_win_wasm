/* CAutoDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CAutoDialog[1] */
/* 004116b0  FUN_004116b0  68 bytes, 0 callers */

undefined4 FUN_004116b0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00411670();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x240);
    }
  }
  return in_ECX;
}




/* vtable slots: CAutoDialog[64] */
/* 00411980  FUN_00411980  136 bytes, 0 callers */

void FUN_00411980(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0xc0);
  FUN_0078fb9c(param_1,0x731,in_ECX + 0x140);
  FUN_0078fb9c(param_1,0x732,in_ECX + 0x1c0);
  FUN_00797f20(0);
  FUN_00797f20(0);
  FUN_00411700();
  return;
}




/* vtable slots: CAutoDialog[10] */
/* 00411a10  FUN_00411a10  16 bytes, 0 callers */

void FUN_00411a10(void)

{
  FUN_00411a20();
  return;
}




/* vtable slots: CAutoDialog[67], CBunkatsuDialog[67], CButton9Dlg[67], CButton9Dlg2[67], CDummyDialog[67], CGazouDialog[67], CHachiDialog[67], CHourakuDialog[67], CIkktuDialog[67], CKyokusenDialog[67], CMentoriDialog[67], CMyDialog[67], CPrtHnDialog[67], CRenzokuSenDailog[67], CRitsumenDialog[67], CSen2Dialog[67], CSenDialog[67], CSenKigouDialog[67], CSesenDialog[67], CSunpoDialog[67], CTakakukeiDialog[67], CTateguDialog[67], CTourokuZuDialog[67] */
/* 0058d4f0  FUN_0058d4f0  75 bytes, 6 callers */

int FUN_0058d4f0(tagMSG *param_1)

{
  int iVar1;
  CDialog *in_ECX;
  
  if ((param_1->message == 0x100) && (param_1->wParam == 0xd)) {
    FUN_007955d2(1);
    FUN_00404c80();
    FUN_0056d7d0();
    iVar1 = 1;
  }
  else {
    iVar1 = CDialog::PreTranslateMessage(in_ECX,param_1);
  }
  return iVar1;
}



