/* CTaskDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTaskDialog[1] */
/* 00813f15  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CTaskDialog::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CTaskDialog::_scalar_deleting_destructor_(CTaskDialog *this,uint param_1)

{
  ~CTaskDialog(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x90);
    }
  }
  return this;
}




/* vtable slots: CTaskDialog[16] */
/* 008141da  FUN_008141da  4 bytes, 0 callers */

undefined4 FUN_008141da(void)

{
  return 6;
}




/* vtable slots: CTaskDialog[15] */
/* 008141de  GetCommonButtonFlag  70 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CTaskDialog::GetCommonButtonFlag(int)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CTaskDialog::GetCommonButtonFlag(CTaskDialog *this,int param_1)

{
  undefined4 uStack_8;
  
  if (param_1 == 1) {
    uStack_8 = 1;
  }
  else if (param_1 == 2) {
    uStack_8 = 8;
  }
  else if (param_1 == 4) {
    uStack_8 = 0x10;
  }
  else if (param_1 == 6) {
    uStack_8 = 2;
  }
  else if (param_1 == 7) {
    uStack_8 = 4;
  }
  else if (param_1 == 8) {
    uStack_8 = 0x20;
  }
  else {
    uStack_8 = 0;
  }
  return uStack_8;
}




/* vtable slots: CTaskDialog[14] */
/* 00814224  GetCommonButtonId  69 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CTaskDialog::GetCommonButtonId(int)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CTaskDialog::GetCommonButtonId(CTaskDialog *this,int param_1)

{
  undefined4 uStack_8;
  
  if (param_1 == 1) {
    uStack_8 = 1;
  }
  else if (param_1 == 2) {
    uStack_8 = 6;
  }
  else if (param_1 == 4) {
    uStack_8 = 7;
  }
  else if (param_1 == 8) {
    uStack_8 = 2;
  }
  else if (param_1 == 0x10) {
    uStack_8 = 4;
  }
  else if (param_1 == 0x20) {
    uStack_8 = 8;
  }
  else {
    uStack_8 = 0;
  }
  return uStack_8;
}




/* vtable slots: CTaskDialog[0] */
/* 00814269  FUN_00814269  6 bytes, 0 callers */

undefined ** FUN_00814269(void)

{
  return &PTR_s_CTaskDialog_0098de0c;
}




/* vtable slots: CTaskDialog[10] */
/* 008142ee  OnHyperlinkClick  30 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual long __thiscall CTaskDialog::OnHyperlinkClick(class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > const &)
   
   Library: Visual Studio 2015 Release */

long __thiscall
CTaskDialog::OnHyperlinkClick
          (CTaskDialog *this,
          CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *param_1)

{
  ShellExecuteW(*(HWND *)(this + 4),(LPCWSTR)0x0,*(LPCWSTR *)param_1,(LPCWSTR)0x0,(LPCWSTR)0x0,5);
  return 0;
}



