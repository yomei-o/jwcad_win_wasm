/* CMFCToolBarDropSource -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarDropSource[14], COleDropSource[14] */
/* 007d0ba3  FUN_007d0ba3  6 bytes, 0 callers */

undefined ** FUN_007d0ba3(void)

{
  return &PTR_DAT_00986734;
}




/* vtable slots: CMFCToolBarDropSource[1] */
/* 00880c20  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarDropSource::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarDropSource::_scalar_deleting_destructor_(CMFCToolBarDropSource *this,uint param_1)

{
  ~CMFCToolBarDropSource(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x58);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarDropSource[10] */
/* 00880c50  FUN_00880c50  6 bytes, 0 callers */

undefined ** FUN_00880c50(void)

{
  return &PTR_FUN_0099a58c;
}




/* vtable slots: CMFCToolBarDropSource[21] */
/* 00880c56  GiveFeedback  52 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCToolBarDropSource::GiveFeedback(unsigned long)
   
   Library: Visual Studio 2015 Release */

long __thiscall CMFCToolBarDropSource::GiveFeedback(CMFCToolBarDropSource *this,ulong param_1)

{
  HCURSOR hCursor;
  long lVar1;
  
  if (param_1 == 1) {
    hCursor = *(HCURSOR *)(this + 0x54);
  }
  else if (param_1 == 2) {
    hCursor = *(HCURSOR *)(this + 0x50);
  }
  else {
    hCursor = *(HCURSOR *)(this + 0x4c);
  }
  if (hCursor == (HCURSOR)0x0) {
    lVar1 = COleDropSource::GiveFeedback((COleDropSource *)this,param_1);
    return lVar1;
  }
  SetCursor(hCursor);
  return 0;
}




/* vtable slots: CMFCToolBarDropSource[22] */
/* 00880c8a  OnBeginDrag  118 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBarDropSource::OnBeginDrag(class CWnd *)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCToolBarDropSource::OnBeginDrag(CMFCToolBarDropSource *this,CWnd *param_1)

{
  int iVar1;
  HCURSOR pHVar2;
  
  if (*(int *)(this + 0x4c) == 0) {
    FUN_0079dd6d();
    iVar1 = FUN_0079dd6d();
    pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3f05);
    *(HCURSOR *)(this + 0x4c) = pHVar2;
    FUN_0079dd6d();
    iVar1 = FUN_0079dd6d();
    pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3f12);
    *(HCURSOR *)(this + 0x50) = pHVar2;
    FUN_0079dd6d();
    iVar1 = FUN_0079dd6d();
    pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3e84);
    *(HCURSOR *)(this + 0x54) = pHVar2;
  }
  *(undefined4 *)(this + 0x48) = 1;
  iVar1 = FUN_007d0bf4(param_1);
  return iVar1;
}




/* vtable slots: CMFCToolBarDropSource[20] */
/* 00880d00  QueryContinueDrag  49 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCToolBarDropSource::QueryContinueDrag(int,unsigned long)
   
   Library: Visual Studio 2015 Release */

long __thiscall
CMFCToolBarDropSource::QueryContinueDrag(CMFCToolBarDropSource *this,int param_1,ulong param_2)

{
  long lVar1;
  
  if ((*(int *)(this + 0x40) != 0) && (*(int *)(this + 0x4c) != 0)) {
    SetCursor(*(HCURSOR *)(this + 0x4c));
  }
  *(int *)(this + 0x44) = param_1;
  lVar1 = COleDropSource::QueryContinueDrag((COleDropSource *)this,param_1,param_2);
  return lVar1;
}



