/* CMFCToolBarsCommandsPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsCommandsPropertyPage[1] */
/* 008c9e30  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarsCommandsPropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarsCommandsPropertyPage::_scalar_deleting_destructor_
          (CMFCToolBarsCommandsPropertyPage *this,uint param_1)

{
  ~CMFCToolBarsCommandsPropertyPage(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1d8);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarsCommandsPropertyPage[64] */
/* 008c9ef7  DoDataExchange  71 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsCommandsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCToolBarsCommandsPropertyPage::DoDataExchange
          (CMFCToolBarsCommandsPropertyPage *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x40d9,this + 0xc0);
  FUN_0078fb9c(param_1,0x40da,this + 0x140);
  DDX_Text(param_1,0x40db,this + 0x1c8);
  return;
}




/* vtable slots: CMFCToolBarsCommandsPropertyPage[10] */
/* 008c9fcb  FUN_008c9fcb  6 bytes, 0 callers */

undefined ** FUN_008c9fcb(void)

{
  return &PTR_FUN_009a5d28;
}




/* vtable slots: CMFCToolBarsCommandsPropertyPage[0] */
/* 008c9fd7  FUN_008c9fd7  6 bytes, 0 callers */

undefined ** FUN_008c9fd7(void)

{
  return &PTR_s_CMFCToolBarsCommandsPropertyPage_009a58f0;
}




/* vtable slots: CMFCToolBarsCommandsPropertyPage[94] */
/* 008ca2c8  FUN_008ca2c8  94 bytes, 0 callers */

undefined4 FUN_008ca2c8(void)

{
  HWND pHVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  int in_ECX;
  
  FUN_00798993();
  pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar2 = CWnd::FromHandle(pHVar1);
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarsCustomizeDialog_0099a930,
                              (CObject *)pCVar2);
  if (pCVar3 != (CObject *)0x0) {
    FUN_008855bc(in_ECX + 0xc0,1);
    SendMessageW(*(HWND *)(in_ECX + 0xe0),0x186,0,0);
    FUN_008ca979();
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



