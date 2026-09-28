/* CMFCStandardColorsPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCStandardColorsPropertyPage[1] */
/* 008d1247  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCStandardColorsPropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCStandardColorsPropertyPage::_scalar_deleting_destructor_
          (CMFCStandardColorsPropertyPage *this,uint param_1)

{
  FUN_008d1226();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x270);
    }
  }
  return this;
}




/* vtable slots: CMFCStandardColorsPropertyPage[64] */
/* 008d1331  DoDataExchange  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCStandardColorsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCStandardColorsPropertyPage::DoDataExchange
          (CMFCStandardColorsPropertyPage *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x424e,this + 200);
  FUN_0078fb9c(param_1,0x424c,this + 0x198);
  return;
}




/* vtable slots: CMFCStandardColorsPropertyPage[10] */
/* 008d1364  FUN_008d1364  6 bytes, 0 callers */

undefined ** FUN_008d1364(void)

{
  return &PTR_FUN_009a7570;
}




/* vtable slots: CMFCStandardColorsPropertyPage[0] */
/* 008d136a  FUN_008d136a  6 bytes, 0 callers */

undefined ** FUN_008d136a(void)

{
  return &PTR_s_CMFCStandardColorsPropertyPage_009a72e8;
}




/* vtable slots: CMFCStandardColorsPropertyPage[94] */
/* 008d1498  FUN_008d1498  160 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008d1498(void)

{
  CWnd *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00798993();
  CMFCColorPickerCtrl::SetPalette
            ((CMFCColorPickerCtrl *)(in_ECX + 200),*(CPalette **)(*(int *)(in_ECX + 0xc0) + 0xdc));
  FUN_007ad46d(3);
  CMFCColorPickerCtrl::SetPalette
            ((CMFCColorPickerCtrl *)(in_ECX + 0x198),*(CPalette **)(*(int *)(in_ECX + 0xc0) + 0xdc))
  ;
  FUN_007ad46d(4);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0xe8),&local_18);
  CWnd::ScreenToClient(in_ECX,&local_18);
  *(LONG *)(in_ECX + 0x268) = local_18.left;
  return 1;
}



