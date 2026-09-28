/* CButton9Dlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CButton9Dlg[1] */
/* 0041a140  FUN_0041a140  68 bytes, 0 callers */

undefined4 FUN_0041a140(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041a030();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x630);
    }
  }
  return in_ECX;
}




/* vtable slots: CButton9Dlg[64] */
/* 0041a2b0  DoDataExchange  262 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsToolsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCToolBarsToolsPropertyPage::DoDataExchange
          (CMFCToolBarsToolsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x428,this + 0x130);
  FUN_0078fb9c(param_1,0x429,this + 0x1b0);
  FUN_0078fb9c(param_1,0x42a,this + 0x230);
  FUN_0078fb9c(param_1,0x42b,this + 0x2b0);
  FUN_0078fb9c(param_1,0x42c,this + 0x330);
  FUN_0078fb9c(param_1,0x42d,this + 0x3b0);
  FUN_0078fb9c(param_1,0x42e,this + 0x430);
  FUN_0078fb9c(param_1,0x42f,this + 0x4b0);
  FUN_0078fb9c(param_1,0x430,this + 0x530);
  FUN_0078fb9c(param_1,0x427,this + 0x5b0);
  return;
}




/* vtable slots: CButton9Dlg[10] */
/* 0041a3c0  FUN_0041a3c0  16 bytes, 0 callers */

void FUN_0041a3c0(void)

{
  FUN_0041a3d0();
  return;
}




/* vtable slots: CButton9Dlg[94] */
/* 0041a5c0  FUN_0041a5c0  32 bytes, 0 callers */

undefined4 FUN_0041a5c0(void)

{
  FUN_00798993();
  FUN_0041a3e0();
  return 1;
}



