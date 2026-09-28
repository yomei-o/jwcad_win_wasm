/* CUserTBDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CUserTBDialog[1] */
/* 005f8580  FUN_005f8580  68 bytes, 0 callers */

undefined4 FUN_005f8580(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005f0b80();
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




/* vtable slots: CUserTBDialog[64] */
/* 005f85d0  DoDataExchange  262 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsToolsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCToolBarsToolsPropertyPage::DoDataExchange
          (CMFCToolBarsToolsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  DDX_Text(param_1,0x9f5,this + 0xa8);
  DDX_Text(param_1,0x9f6,this + 0xac);
  DDX_Text(param_1,0x9f7,this + 0xb0);
  DDX_Text(param_1,0x9f8,this + 0xb4);
  DDX_Text(param_1,0x9f9,this + 0xb8);
  DDX_Text(param_1,0x9fa,this + 0xbc);
  FUN_0078f6f8(param_1,0xa0e,this + 0xc0);
  FUN_0078f6f8(param_1,0xa0f,this + 0xc4);
  FUN_0078f6f8(param_1,0xa10,this + 200);
  FUN_0078f6f8(param_1,0xa11,this + 0xcc);
  return;
}




/* vtable slots: CUserTBDialog[10] */
/* 005f86e0  FUN_005f86e0  16 bytes, 0 callers */

void FUN_005f86e0(void)

{
  FUN_005f86f0();
  return;
}



