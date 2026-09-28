/* CMFCTasksPanePropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTasksPanePropertyPage[1] */
/* 008d385c  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCTasksPanePropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCTasksPanePropertyPage::_scalar_deleting_destructor_
          (CMFCTasksPanePropertyPage *this,uint param_1)

{
  ~CMFCTasksPanePropertyPage(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xc);
    }
  }
  return this;
}




/* vtable slots: CMFCTasksPanePropertyPage[3] */
/* 008d7de9  SetACCData  54 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCTasksPanePropertyPage::SetACCData(class CWnd *,class
   CAccessibilityData &)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCTasksPanePropertyPage::SetACCData
          (CMFCTasksPanePropertyPage *this,CWnd *param_1,CAccessibilityData *param_2)

{
  FUN_007ed2e1();
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)param_2,(CSimpleStringT<wchar_t,0> *)(this + 4));
  *(undefined4 *)(param_2 + 0x18) = 0x25;
  *(undefined4 *)(param_2 + 0x1c) = 0x100;
  *(undefined4 *)(param_2 + 0x20) = 1;
  return 1;
}



