/* CDialogEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDialogEx[61], CMFCColorDialog[61], CMFCImageEditorDialog[61], CMFCPropertyPage[61] */
/* 007c2ad3  OnCommand  50 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CDialogEx::OnCommand(unsigned int,long)
    protected: virtual int __thiscall CMFCPropertyPage::OnCommand(unsigned int,long)
   
   Library: Visual Studio 2015 Release */

undefined4 OnCommand(uint param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = CDialogImpl::OnCommand((CDialogImpl *)(in_ECX + 0xc0),param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = FUN_00793275(param_1,param_2);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CDialogEx[1] */
/* 0089e1c7  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CDialogEx::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CDialogEx::_scalar_deleting_destructor_(CDialogEx *this,uint param_1)

{
  ~CDialogEx(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xd0);
    }
  }
  return this;
}




/* vtable slots: CDialogEx[10] */
/* 0089e249  FUN_0089e249  6 bytes, 0 callers */

undefined ** FUN_0089e249(void)

{
  return &PTR_FUN_0099e5c0;
}




/* vtable slots: CDialogEx[0], CMFCColorDialog[0], CMFCImageEditorDialog[0] */
/* 0089e24f  FUN_0089e24f  6 bytes, 0 callers */

undefined ** FUN_0089e24f(void)

{
  return &PTR_s_CDialogEx_0099e348;
}




/* vtable slots: CDialogEx[67], CMFCImageEditorDialog[67] */
/* 0089e58b  PreTranslateMessage  44 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CDialogEx::PreTranslateMessage(struct tagMSG *)
   
   Library: Visual Studio 2015 Release */

int __thiscall CDialogEx::PreTranslateMessage(CDialogEx *this,tagMSG *param_1)

{
  int iVar1;
  
  iVar1 = FUN_007ec9f3(param_1);
  if (iVar1 == 0) {
    iVar1 = CDialog::PreTranslateMessage((CDialog *)this,param_1);
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}



