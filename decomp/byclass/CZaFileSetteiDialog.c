/* CZaFileSetteiDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZaFileSetteiDialog[1] */
/* 00607850  FUN_00607850  68 bytes, 0 callers */

undefined4 FUN_00607850(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004aa7a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,200);
    }
  }
  return in_ECX;
}




/* vtable slots: CZaFileSetteiDialog[64] */
/* 006078a0  DoDataExchange  214 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCCustomColorsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCCustomColorsPropertyPage::DoDataExchange
          (CMFCCustomColorsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  DDX_Text(param_1,0x938,this + 0xa8);
  FUN_0078f75d(param_1,0x91a,this + 0xac);
  FUN_0078f75d(param_1,0x92f,this + 0xb0);
  FUN_0078f6f8(param_1,0x52b,this + 0xb4);
  FUN_0078f6f8(param_1,0x52c,this + 0xb8);
  FUN_0078f6f8(param_1,0x52d,this + 0xbc);
  FUN_0078f6f8(param_1,0x52e,this + 0xc0);
  FUN_0078f6f8(param_1,0x52f,this + 0xc4);
  return;
}




/* vtable slots: CZaFileSetteiDialog[10] */
/* 00607980  FUN_00607980  16 bytes, 0 callers */

void FUN_00607980(void)

{
  FUN_00607990();
  return;
}



