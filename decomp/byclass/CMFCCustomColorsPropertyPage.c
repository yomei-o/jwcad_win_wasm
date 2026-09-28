/* CMFCCustomColorsPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCCustomColorsPropertyPage[1] */
/* 008d15eb  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCCustomColorsPropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCCustomColorsPropertyPage::_scalar_deleting_destructor_
          (CMFCCustomColorsPropertyPage *this,uint param_1)

{
  FUN_008d1226();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x288);
    }
  }
  return this;
}




/* vtable slots: CMFCCustomColorsPropertyPage[64] */
/* 008d164e  DoDataExchange  160 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCCustomColorsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCCustomColorsPropertyPage::DoDataExchange
          (CMFCCustomColorsPropertyPage *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x424d,this + 200);
  FUN_0078fb9c(param_1,0x4116,this + 0x198);
  FUN_0078f801(param_1,0x4244,this + 0x268);
  FUN_0078f801(param_1,0x4246,this + 0x26c);
  FUN_0078f801(param_1,0x4245,this + 0x270);
  DDX_Text(param_1,0x4247,(uint *)(this + 0x274));
  DDX_Text(param_1,0x4249,(uint *)(this + 0x278));
  DDX_Text(param_1,0x4248,(uint *)(this + 0x27c));
  return;
}




/* vtable slots: CMFCCustomColorsPropertyPage[10] */
/* 008d16ee  FUN_008d16ee  6 bytes, 0 callers */

undefined ** FUN_008d16ee(void)

{
  return &PTR_FUN_009a7860;
}




/* vtable slots: CMFCCustomColorsPropertyPage[0] */
/* 008d16f4  FUN_008d16f4  6 bytes, 0 callers */

undefined ** FUN_008d16f4(void)

{
  return &PTR_s_CMFCCustomColorsPropertyPage_009a7578;
}




/* vtable slots: CMFCCustomColorsPropertyPage[94] */
/* 008d1a3a  FUN_008d1a3a  198 bytes, 0 callers */

undefined4 FUN_008d1a3a(void)

{
  CSpinButtonCtrl *this;
  int in_ECX;
  uint uVar1;
  double local_1c;
  double local_14;
  double local_c;
  
  FUN_00798993();
  CMFCColorPickerCtrl::SetPalette
            ((CMFCColorPickerCtrl *)(in_ECX + 0x198),*(CPalette **)(*(int *)(in_ECX + 0xc0) + 0xdc))
  ;
  FUN_007ad46d(2);
  CMFCColorPickerCtrl::GetHLS((CMFCColorPickerCtrl *)(in_ECX + 0x198),&local_1c,&local_14,&local_c);
  CMFCColorPickerCtrl::SetPalette
            ((CMFCColorPickerCtrl *)(in_ECX + 200),*(CPalette **)(*(int *)(in_ECX + 0xc0) + 0xdc));
  FUN_007ad46d(1);
  FUN_008d1071(local_1c,local_14,local_c,1);
  FUN_008d1119(0xe);
  uVar1 = 0x4250;
  do {
    this = (CSpinButtonCtrl *)FUN_00797a56(uVar1);
    if (this == (CSpinButtonCtrl *)0x0) break;
    CSpinButtonCtrl::SetRange(this,0,0xff);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x4256);
  *(undefined4 *)(in_ECX + 0x280) = 1;
  return 1;
}



