/* CMFCCaptionButtonEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCCaptionButtonEx[1] */
/* 008aee03  `scalar_deleting_destructor'  49 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCCaptionButtonEx::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCCaptionButtonEx::_scalar_deleting_destructor_(CMFCCaptionButtonEx *this,uint param_1)

{
  *(undefined ***)this = CMFCCaptionButton::vftable;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x40);
    }
  }
  return this;
}




/* vtable slots: CMFCCaptionButtonEx[3] */
/* 008aeefc  GetRect  23 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual class CRect __thiscall CMFCCaptionButtonEx::GetRect(void)const 
    public: class CRect __thiscall CMFCPropertyGridProperty::GetRect(void)const 
   
   Library: Visual Studio 2015 Release */

void GetRect(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x30);
  param_1[1] = *(undefined4 *)(in_ECX + 0x34);
  param_1[2] = *(undefined4 *)(in_ECX + 0x38);
  param_1[3] = *(undefined4 *)(in_ECX + 0x3c);
  return;
}



