/* CTourokuZuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTourokuZuDialog[1] */
/* 005f4d30  FUN_005f4d30  68 bytes, 0 callers */

undefined4 FUN_005f4d30(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005f4c90();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x8f0);
    }
  }
  return in_ECX;
}




/* vtable slots: CTourokuZuDialog[64] */
/* 005f4ea0  DoDataExchange  262 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsToolsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCToolBarsToolsPropertyPage::DoDataExchange
          (CMFCToolBarsToolsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x42c,this + 0xb8);
  FUN_0078fb9c(param_1,0x42b,this + 0x138);
  FUN_0078fb9c(param_1,0x428,this + 0x568);
  FUN_0078fb9c(param_1,0x429,this + 0x1b8);
  FUN_0078fb9c(param_1,0x597,this + 0x238);
  FUN_0078fb9c(param_1,0x584,this + 0x420);
  FUN_0078fb9c(param_1,0x585,this + 0x680);
  FUN_0078fb9c(param_1,0x6e2,this + 0x600);
  FUN_0078fb9c(param_1,0xb31,this + 0x868);
  FUN_0078f6f8(param_1,0xb31,this + 0x8e8);
  return;
}




/* vtable slots: CTourokuZuDialog[10] */
/* 005f4fb0  FUN_005f4fb0  16 bytes, 0 callers */

void FUN_005f4fb0(void)

{
  FUN_005f4fc0();
  return;
}



