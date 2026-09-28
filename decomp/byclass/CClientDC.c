/* CClientDC -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CClientDC[23], CDC[23], CPaintDC[23], CWindowDC[23] */
/* 0059d070  CheckMenuRadioItem  42 bytes, 4 callers */

/* Library Function - Single Match
    public: int __thiscall CMenu::CheckMenuRadioItem(unsigned int,unsigned int,unsigned int,unsigned
   int)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

int __thiscall
CMenu::CheckMenuRadioItem(CMenu *this,uint param_1,uint param_2,uint param_3,uint param_4)

{
  BOOL BVar1;
  
  BVar1 = TextOutW(*(HDC *)(this + 4),param_1,param_2,(LPCWSTR)param_3,param_4);
  return BVar1;
}




/* vtable slots: CClientDC[1] */
/* 0079e14c  FUN_0079e14c  48 bytes, 0 callers */

void FUN_0079e14c(byte param_1)

{
  FUN_0079dfff();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CClientDC[27], CDC[27], CPaintDC[27], CWindowDC[27] */
/* 0079ea10  FUN_0079ea10  31 bytes, 0 callers */

void FUN_0079ea10(LPWSTR param_1,int param_2,LPRECT param_3,UINT param_4,LPDRAWTEXTPARAMS param_5)

{
  int in_ECX;
  
  DrawTextExW(*(HDC *)(in_ECX + 4),param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CClientDC[26], CDC[26], CPaintDC[26], CWindowDC[26] */
/* 0079ea2f  FUN_0079ea2f  28 bytes, 0 callers */

void FUN_0079ea2f(LPCWSTR param_1,int param_2,LPRECT param_3,UINT param_4)

{
  int in_ECX;
  
  DrawTextW(*(HDC *)(in_ECX + 4),param_1,param_2,param_3,param_4);
  return;
}




/* vtable slots: CClientDC[29], CDC[29], CPaintDC[29], CWindowDC[29] */
/* 0079ea4b  FUN_0079ea4b  28 bytes, 0 callers */

void FUN_0079ea4b(int param_1,int param_2,LPCSTR param_3,LPVOID param_4)

{
  int in_ECX;
  
  Escape(*(HDC *)(in_ECX + 4),param_1,param_2,param_3,param_4);
  return;
}




/* vtable slots: CClientDC[24], CDC[24], CPaintDC[24], CWindowDC[24] */
/* 0079eab4  FUN_0079eab4  37 bytes, 0 callers */

void FUN_0079eab4(int param_1,int param_2,UINT param_3,RECT *param_4,LPCWSTR param_5,UINT param_6,
                 INT *param_7)

{
  int in_ECX;
  
  ExtTextOutW(*(HDC *)(in_ECX + 4),param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CClientDC[20], CDC[20], CPaintDC[20], CPreviewDC[20], CWindowDC[20] */
/* 0079eafd  FUN_0079eafd  19 bytes, 1 callers */

void FUN_0079eafd(LPRECT param_1)

{
  int in_ECX;
  
  GetClipBox(*(HDC *)(in_ECX + 4),param_1);
  return;
}




/* vtable slots: CClientDC[0] */
/* 0079eb26  FUN_0079eb26  6 bytes, 0 callers */

undefined ** FUN_0079eb26(void)

{
  return &PTR_s_CClientDC_0097e130;
}




/* vtable slots: CClientDC[28], CDC[28], CPaintDC[28], CWindowDC[28] */
/* 0079eb68  FUN_0079eb68  48 bytes, 0 callers */

void FUN_0079eb68(int param_1,GRAYSTRINGPROC param_2,LPARAM param_3,int param_4,int param_5,
                 int param_6,int param_7,int param_8)

{
  HBRUSH hBrush;
  int in_ECX;
  
  hBrush = (HBRUSH)0x0;
  if (param_1 != 0) {
    hBrush = *(HBRUSH *)(param_1 + 4);
  }
  GrayStringW(*(HDC *)(in_ECX + 4),hBrush,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}




/* vtable slots: CClientDC[15], CDC[15], CPaintDC[15], CWindowDC[15] */
/* 0079ec9e  FUN_0079ec9e  70 bytes, 0 callers */

LPPOINT FUN_0079ec9e(LPPOINT param_1,int param_2,int param_3)

{
  HDC hdc;
  int in_ECX;
  
  param_1->x = 0;
  param_1->y = 0;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    OffsetViewportOrgEx(*(HDC *)(in_ECX + 4),param_2,param_3,param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    OffsetViewportOrgEx(hdc,param_2,param_3,param_1);
  }
  return param_1;
}




/* vtable slots: CClientDC[21], CDC[21], CPaintDC[21], CPreviewDC[21], CWindowDC[21] */
/* 0079ed2a  FUN_0079ed2a  22 bytes, 0 callers */

void FUN_0079ed2a(int param_1,int param_2)

{
  int in_ECX;
  
  PtVisible(*(HDC *)(in_ECX + 4),param_1,param_2);
  return;
}




/* vtable slots: CClientDC[22], CDC[22], CPaintDC[22], CPreviewDC[22], CWindowDC[22] */
/* 0079ed40  FUN_0079ed40  19 bytes, 0 callers */

void FUN_0079ed40(RECT *param_1)

{
  int in_ECX;
  
  RectVisible(*(HDC *)(in_ECX + 4),param_1);
  return;
}




/* vtable slots: CClientDC[5], CDC[5], CPaintDC[5], CPreviewDC[5], CWindowDC[5] */
/* 0079ed53  FUN_0079ed53  5 bytes, 0 callers */

void FUN_0079ed53(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}




/* vtable slots: CClientDC[6], CDC[6], CPaintDC[6], CWindowDC[6] */
/* 0079ed58  FUN_0079ed58  5 bytes, 1 callers */

void FUN_0079ed58(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}




/* vtable slots: CClientDC[8], CDC[8], CPaintDC[8], CWindowDC[8] */
/* 0079ed5d  FUN_0079ed5d  66 bytes, 0 callers */

int FUN_0079ed5d(int param_1)

{
  int iVar1;
  BOOL BVar2;
  int in_ECX;
  HDC hdc;
  
  iVar1 = 1;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    iVar1 = RestoreDC(*(HDC *)(in_ECX + 4),param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    if ((iVar1 != 0) && (BVar2 = RestoreDC(hdc,param_1), BVar2 != 0)) {
      return 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}




/* vtable slots: CClientDC[7], CDC[7], CPaintDC[7], CWindowDC[7] */
/* 0079ed9f  FUN_0079ed9f  51 bytes, 0 callers */

int FUN_0079ed9f(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  if (*(HDC *)(in_ECX + 8) != (HDC)0x0) {
    iVar2 = SaveDC(*(HDC *)(in_ECX + 8));
    iVar1 = *(int *)(in_ECX + 8);
  }
  if (*(int *)(in_ECX + 4) != iVar1) {
    iVar1 = SaveDC(*(HDC *)(in_ECX + 4));
    if (iVar1 != 0) {
      iVar2 = -1;
    }
  }
  return iVar2;
}




/* vtable slots: CClientDC[17], CDC[17], CPaintDC[17], CWindowDC[17] */
/* 0079edd2  FUN_0079edd2  82 bytes, 0 callers */

LPSIZE FUN_0079edd2(LPSIZE param_1,int param_2,int param_3,int param_4,int param_5)

{
  HDC hdc;
  int in_ECX;
  
  param_1->cx = 0;
  param_1->cy = 0;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    ScaleViewportExtEx(*(HDC *)(in_ECX + 4),param_2,param_3,param_4,param_5,param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    ScaleViewportExtEx(hdc,param_2,param_3,param_4,param_5,param_1);
  }
  return param_1;
}




/* vtable slots: CClientDC[19], CDC[19], CPaintDC[19], CWindowDC[19] */
/* 0079ee24  FUN_0079ee24  82 bytes, 0 callers */

LPSIZE FUN_0079ee24(LPSIZE param_1,int param_2,int param_3,int param_4,int param_5)

{
  HDC hdc;
  int in_ECX;
  
  param_1->cx = 0;
  param_1->cy = 0;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    ScaleWindowExtEx(*(HDC *)(in_ECX + 4),param_2,param_3,param_4,param_5,param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    ScaleWindowExtEx(hdc,param_2,param_3,param_4,param_5,param_1);
  }
  return param_1;
}




/* vtable slots: CClientDC[10], CDC[10], CPaintDC[10], CWindowDC[10] */
/* 0079efbc  FUN_0079efbc  81 bytes, 122 callers */

void FUN_0079efbc(int param_1)

{
  HDC hdc;
  int in_ECX;
  HGDIOBJ pvVar1;
  HGDIOBJ h;
  
  hdc = *(HDC *)(in_ECX + 8);
  h = (HGDIOBJ)0x0;
  pvVar1 = (HGDIOBJ)0x0;
  if (*(HDC *)(in_ECX + 4) != hdc) {
    pvVar1 = (HGDIOBJ)0x0;
    if (param_1 != 0) {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    pvVar1 = SelectObject(*(HDC *)(in_ECX + 4),pvVar1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    if (param_1 != 0) {
      h = *(HGDIOBJ *)(param_1 + 4);
    }
    pvVar1 = SelectObject(hdc,h);
  }
  CGdiObject::FromHandle(pvVar1);
  return;
}




/* vtable slots: CClientDC[9], CDC[9], CPaintDC[9], CWindowDC[9] */
/* 0079f031  FUN_0079f031  65 bytes, 10 callers */

void FUN_0079f031(int param_1)

{
  HGDIOBJ h;
  void *pvVar1;
  int in_ECX;
  HDC hdc;
  
  h = GetStockObject(param_1);
  hdc = *(HDC *)(in_ECX + 8);
  pvVar1 = (HGDIOBJ)0x0;
  if (*(HDC *)(in_ECX + 4) != hdc) {
    pvVar1 = SelectObject(*(HDC *)(in_ECX + 4),h);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    pvVar1 = SelectObject(hdc,h);
  }
  CGdiObject::FromHandle(pvVar1);
  return;
}




/* vtable slots: CClientDC[3], CDC[3], CMFCAutoHideButton[4], CPaintDC[3], CWindowDC[3] */
/* 0079f072  SetAttribDC  13 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CDC::SetAttribDC(struct HDC__ *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

void __thiscall CDC::SetAttribDC(CDC *this,HDC__ *param_1)

{
  *(HDC__ **)(this + 8) = param_1;
  return;
}




/* vtable slots: CClientDC[11], CDC[11], CPaintDC[11], CWindowDC[11] */
/* 0079f07f  FUN_0079f07f  57 bytes, 5 callers */

COLORREF FUN_0079f07f(COLORREF param_1)

{
  HDC hdc;
  int in_ECX;
  COLORREF CVar1;
  
  CVar1 = 0xffffffff;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    CVar1 = SetBkColor(*(HDC *)(in_ECX + 4),param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    CVar1 = SetBkColor(hdc,param_1);
  }
  return CVar1;
}




/* vtable slots: CClientDC[13], CDC[13], CPaintDC[13], CWindowDC[13] */
/* 0079f13b  FUN_0079f13b  56 bytes, 2 callers */

int FUN_0079f13b(int param_1)

{
  HDC hdc;
  int in_ECX;
  int iVar1;
  
  iVar1 = 0;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    iVar1 = SetMapMode(*(HDC *)(in_ECX + 4),param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    iVar1 = SetMapMode(hdc,param_1);
  }
  return iVar1;
}




/* vtable slots: CClientDC[4], CDC[4], CPaintDC[4], CWindowDC[4] */
/* 0079f173  SetOutputDC  13 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CDC::SetOutputDC(struct HDC__ *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CDC::SetOutputDC(CDC *this,HDC__ *param_1)

{
  *(HDC__ **)(this + 4) = param_1;
  return;
}




/* vtable slots: CClientDC[12], CDC[12], CPaintDC[12], CWindowDC[12] */
/* 0079f261  FUN_0079f261  57 bytes, 4 callers */

COLORREF FUN_0079f261(COLORREF param_1)

{
  HDC hdc;
  int in_ECX;
  COLORREF CVar1;
  
  CVar1 = 0xffffffff;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    CVar1 = SetTextColor(*(HDC *)(in_ECX + 4),param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    CVar1 = SetTextColor(hdc,param_1);
  }
  return CVar1;
}




/* vtable slots: CClientDC[16], CDC[16], CPaintDC[16], CWindowDC[16] */
/* 0079f29a  FUN_0079f29a  70 bytes, 0 callers */

LPSIZE FUN_0079f29a(LPSIZE param_1,int param_2,int param_3)

{
  HDC hdc;
  int in_ECX;
  
  param_1->cx = 0;
  param_1->cy = 0;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    SetViewportExtEx(*(HDC *)(in_ECX + 4),param_2,param_3,param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    SetViewportExtEx(hdc,param_2,param_3,param_1);
  }
  return param_1;
}




/* vtable slots: CClientDC[14], CDC[14], CPaintDC[14], CWindowDC[14] */
/* 0079f2e0  FUN_0079f2e0  70 bytes, 0 callers */

LPPOINT FUN_0079f2e0(LPPOINT param_1,int param_2,int param_3)

{
  HDC hdc;
  int in_ECX;
  
  param_1->x = 0;
  param_1->y = 0;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    SetViewportOrgEx(*(HDC *)(in_ECX + 4),param_2,param_3,param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    SetViewportOrgEx(hdc,param_2,param_3,param_1);
  }
  return param_1;
}




/* vtable slots: CClientDC[18], CDC[18], CPaintDC[18], CWindowDC[18] */
/* 0079f326  FUN_0079f326  70 bytes, 0 callers */

LPSIZE FUN_0079f326(LPSIZE param_1,int param_2,int param_3)

{
  HDC hdc;
  int in_ECX;
  
  param_1->cx = 0;
  param_1->cy = 0;
  hdc = *(HDC *)(in_ECX + 8);
  if (*(HDC *)(in_ECX + 4) != hdc) {
    SetWindowExtEx(*(HDC *)(in_ECX + 4),param_2,param_3,param_1);
    hdc = *(HDC *)(in_ECX + 8);
  }
  if (hdc != (HDC)0x0) {
    SetWindowExtEx(hdc,param_2,param_3,param_1);
  }
  return param_1;
}




/* vtable slots: CClientDC[25], CDC[25], CPaintDC[25], CWindowDC[25] */
/* 0079f3ea  FUN_0079f3ea  56 bytes, 0 callers */

int * FUN_0079f3ea(int *param_1,int param_2,int param_3,LPCWSTR param_4,int param_5,int param_6,
                  INT *param_7,int param_8)

{
  LONG LVar1;
  int in_ECX;
  
  LVar1 = TabbedTextOutW(*(HDC *)(in_ECX + 4),param_2,param_3,param_4,param_5,param_6,param_7,
                         param_8);
  *param_1 = (int)(short)LVar1;
  param_1[1] = (int)(short)((uint)LVar1 >> 0x10);
  return param_1;
}



