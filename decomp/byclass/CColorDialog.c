/* CColorDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CColorDialog[1] */
/* 007a51f6  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CColorDialog::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CColorDialog::_scalar_deleting_destructor_(CColorDialog *this,uint param_1)

{
  *(undefined ***)this = CCommonDialog::vftable;
  FUN_00797fb6();
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




/* vtable slots: CColorDialog[93], CMyColorDialog[93] */
/* 007a5279  DoModal  48 bytes, 10 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CColorDialog::DoModal(void)
   
   Library: Visual Studio 2015 Release */

int __thiscall CColorDialog::DoModal(CColorDialog *this)

{
  HWND__ *pHVar1;
  int iVar2;
  
  pHVar1 = CDialog::PreModal((CDialog *)this);
  *(HWND__ **)(this + 0xac) = pHVar1;
  iVar2 = FUN_007a5370(this + 0xa8);
  CDialog::PostModal((CDialog *)this);
  if (iVar2 == 0) {
    iVar2 = 2;
  }
  return iVar2;
}




/* vtable slots: CColorDialog[0], CMyColorDialog[0] */
/* 007a52a9  FUN_007a52a9  6 bytes, 0 callers */

undefined ** FUN_007a52a9(void)

{
  return &PTR_s_CColorDialog_0097f130;
}




/* vtable slots: CColorDialog[10], CCommonDialog[10], CFileDialog[10], CMyColorDialog[10], COleBusyDialog[10] */
/* 007ab555  FUN_007ab555  6 bytes, 0 callers */

undefined ** FUN_007ab555(void)

{
  return &PTR_FUN_0097f8c0;
}




/* vtable slots: CColorDialog[96], CCommonDialog[96], CFileDialog[96], CMyColorDialog[96], COleBusyDialog[96], CPrintDialog[96] */
/* 007ab574  FUN_007ab574  24 bytes, 0 callers */

void FUN_007ab574(void)

{
  int iVar1;
  
  iVar1 = FUN_007955d2(1);
  if (iVar1 != 0) {
    FUN_007922d4();
    return;
  }
  return;
}



