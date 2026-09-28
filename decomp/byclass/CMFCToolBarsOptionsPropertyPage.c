/* CMFCToolBarsOptionsPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsOptionsPropertyPage[1] */
/* 008cd366  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarsOptionsPropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarsOptionsPropertyPage::_scalar_deleting_destructor_
          (CMFCToolBarsOptionsPropertyPage *this,uint param_1)

{
  ~CMFCToolBarsOptionsPropertyPage(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x458);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarsOptionsPropertyPage[64] */
/* 008cd3ca  DoDataExchange  231 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsOptionsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCToolBarsOptionsPropertyPage::DoDataExchange
          (CMFCToolBarsOptionsPropertyPage *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x410d,this + 0xc0);
  FUN_0078fb9c(param_1,0x410f,this + 0x140);
  FUN_0078fb9c(param_1,0x4111,this + 0x1c0);
  FUN_0078fb9c(param_1,0x409a,this + 0x240);
  FUN_0078fb9c(param_1,0x409b,this + 0x2c0);
  FUN_0078fb9c(param_1,0x4110,this + 0x340);
  FUN_0078fb9c(param_1,0x410c,this + 0x3c0);
  FUN_0078f6f8(param_1,0x410b,this + 0x440);
  FUN_0078f6f8(param_1,0x410c,this + 0x444);
  FUN_0078f6f8(param_1,0x410f,this + 0x448);
  FUN_0078f6f8(param_1,0x4110,this + 0x44c);
  FUN_0078f6f8(param_1,0x410d,this + 0x450);
  return;
}




/* vtable slots: CMFCToolBarsOptionsPropertyPage[10] */
/* 008cd4b1  FUN_008cd4b1  6 bytes, 0 callers */

undefined ** FUN_008cd4b1(void)

{
  return &PTR_FUN_009a6a40;
}




/* vtable slots: CMFCToolBarsOptionsPropertyPage[0] */
/* 008cd4b7  FUN_008cd4b7  6 bytes, 0 callers */

undefined ** FUN_008cd4b7(void)

{
  return &PTR_s_CMFCToolBarsOptionsPropertyPage_009a67a4;
}




/* vtable slots: CMFCToolBarsOptionsPropertyPage[94] */
/* 008cd4d4  FUN_008cd4d4  261 bytes, 0 callers */

undefined4 FUN_008cd4d4(void)

{
  HWND pHVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  int in_ECX;
  
  FUN_00798993();
  FUN_007979e8(*(undefined4 *)(in_ECX + 0x440));
  FUN_007979e8(*(undefined4 *)(in_ECX + 0x448));
  if ((DAT_00a00668 == 0) || (*(int *)(in_ECX + 0x454) == 0)) {
    FUN_00797f20(0);
    FUN_007979e8(0);
    FUN_00797f20(0);
    FUN_007979e8(0);
    FUN_00797f20(0);
    FUN_007979e8(0);
    FUN_00797f20(0);
    FUN_007979e8(0);
    FUN_00797f20(0);
    FUN_007979e8(0);
  }
  pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar2 = CWnd::FromHandle(pHVar1);
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarsCustomizeDialog_0099a930,
                              (CObject *)pCVar2);
  if (pCVar3 != (CObject *)0x0) {
    if (((byte)pCVar3[0x15c] & 0x80) != 0) {
      FUN_00797f20(0);
      FUN_007979e8(0);
      *(undefined4 *)(in_ECX + 0x450) = 0;
    }
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



