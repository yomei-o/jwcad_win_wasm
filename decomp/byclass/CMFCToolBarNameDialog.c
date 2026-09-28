/* CMFCToolBarNameDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarNameDialog[1] */
/* 008d8970  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarNameDialog::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarNameDialog::_scalar_deleting_destructor_(CMFCToolBarNameDialog *this,uint param_1)

{
  ~CMFCToolBarNameDialog(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x130);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarNameDialog[64] */
/* 008d89a3  DoDataExchange  48 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarNameDialog::DoDataExchange(class CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCToolBarNameDialog::DoDataExchange(CMFCToolBarNameDialog *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,1,this + 0xa8);
  DDX_Text(param_1,0x4084,this + 0x128);
  return;
}




/* vtable slots: CMFCToolBarNameDialog[10] */
/* 008d89d3  FUN_008d89d3  6 bytes, 0 callers */

undefined ** FUN_008d89d3(void)

{
  return &PTR_FUN_009a9848;
}




/* vtable slots: CMFCToolBarNameDialog[94] */
/* 008d89d9  OnInitDialog  81 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CMFCToolBarNameDialog::OnInitDialog(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCToolBarNameDialog::OnInitDialog(CMFCToolBarNameDialog *this)

{
  int iVar1;
  uint uVar2;
  
  FUN_00798993();
  iVar1 = FUN_00404c80();
  if (iVar1 != 0) {
    FUN_00404c80();
    uVar2 = FUN_00797acc();
    if ((uVar2 & 0x400000) != 0) {
      FUN_00797c9f(0,0x400000,0);
    }
  }
  FUN_007979e8(*(int *)(*(int *)(this + 0x128) + -0xc) != 0);
  return 1;
}



