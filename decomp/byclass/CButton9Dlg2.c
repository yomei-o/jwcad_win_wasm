/* CButton9Dlg2 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CButton9Dlg2[1] */
/* 00418970  FUN_00418970  68 bytes, 0 callers */

undefined4 FUN_00418970(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00418860();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x750);
    }
  }
  return in_ECX;
}




/* vtable slots: CButton9Dlg2[64] */
/* 004189c0  DoDataExchange  262 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsToolsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCToolBarsToolsPropertyPage::DoDataExchange
          (CMFCToolBarsToolsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x428,this + 0x160);
  FUN_0078fb9c(param_1,0x429,this + 0x1f8);
  FUN_0078fb9c(param_1,0x42a,this + 0x290);
  FUN_0078fb9c(param_1,0x42b,this + 0x328);
  FUN_0078fb9c(param_1,0x42c,this + 0x3c0);
  FUN_0078fb9c(param_1,0x42d,this + 0x458);
  FUN_0078fb9c(param_1,0x42e,this + 0x4f0);
  FUN_0078fb9c(param_1,0x42f,this + 0x588);
  FUN_0078fb9c(param_1,0x430,this + 0x620);
  FUN_0078fb9c(param_1,0x427,this + 0x6b8);
  return;
}




/* vtable slots: CButton9Dlg2[10] */
/* 00418ad0  FUN_00418ad0  16 bytes, 0 callers */

void FUN_00418ad0(void)

{
  FUN_00418ae0();
  return;
}




/* vtable slots: CButton9Dlg2[94] */
/* 00418d20  FUN_00418d20  162 bytes, 0 callers */

undefined4 FUN_00418d20(void)

{
  int in_ECX;
  
  FUN_00798993();
  FUN_00418af0();
  *(undefined4 *)(in_ECX + 0x744) = 0;
  *(undefined4 *)(in_ECX + 0x6ac) = 0;
  *(undefined4 *)(in_ECX + 0x614) = 0;
  *(undefined4 *)(in_ECX + 0x57c) = 0;
  *(undefined4 *)(in_ECX + 0x4e4) = 0;
  *(undefined4 *)(in_ECX + 0x44c) = 0;
  *(undefined4 *)(in_ECX + 0x3b4) = 0;
  *(undefined4 *)(in_ECX + 0x31c) = 0;
  *(undefined4 *)(in_ECX + 0x284) = 0;
  *(undefined4 *)(in_ECX + 0x1ec) = 0;
  return 1;
}



