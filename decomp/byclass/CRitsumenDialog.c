/* CRitsumenDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRitsumenDialog[1] */
/* 005b89e0  FUN_005b89e0  68 bytes, 0 callers */

undefined4 FUN_005b89e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005b8950();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x710);
    }
  }
  return in_ECX;
}




/* vtable slots: CRitsumenDialog[64] */
/* 005b9120  DoDataExchange  309 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsOptionsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCToolBarsOptionsPropertyPage::DoDataExchange
          (CMFCToolBarsOptionsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x592,this + 0xb8);
  FUN_0078fb9c(param_1,0x596,this + 0x2a0);
  FUN_0078fb9c(param_1,0x429,this + 1000);
  FUN_0078fb9c(param_1,0x42a,this + 0x468);
  FUN_0078fb9c(param_1,0x52d,this + 0x4e8);
  FUN_0078fb9c(param_1,0x52c,this + 0x568);
  FUN_0078fb9c(param_1,0x52b,this + 0x5e8);
  FUN_0078f6f8(param_1,0x52b,this + 0x668);
  FUN_0078f6f8(param_1,0x52c,this + 0x66c);
  FUN_0078f6f8(param_1,0x52d,this + 0x670);
  FUN_0078fb9c(param_1,0xb31,this + 0x678);
  FUN_0078f6f8(param_1,0xb31,this + 0x6f8);
  return;
}




/* vtable slots: CRitsumenDialog[10] */
/* 005b9260  FUN_005b9260  16 bytes, 0 callers */

void FUN_005b9260(void)

{
  FUN_005b9270();
  return;
}




/* vtable slots: CRitsumenDialog[94] */
/* 005b92b0  FUN_005b92b0  110 bytes, 0 callers */

undefined4 FUN_005b92b0(void)

{
  int in_ECX;
  
  FUN_00798993();
  FUN_0058b040();
  FUN_0058ae50(DAT_00a0bca0,DAT_00a0bca8);
  (**(code **)(*(int *)(in_ECX + 0x2a0) + 0x17c))();
  return 1;
}



