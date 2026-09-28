/* CPreviewDC -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPreviewDC[1] */
/* 007ce53d  FUN_007ce53d  48 bytes, 0 callers */

void FUN_007ce53d(byte param_1)

{
  FUN_007ce4ef();
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




/* vtable slots: CPreviewDC[27] */
/* 007cea19  FUN_007cea19  81 bytes, 0 callers */

int FUN_007cea19(LPWSTR param_1,int param_2,LPRECT param_3,UINT param_4,LPDRAWTEXTPARAMS param_5)

{
  int iVar1;
  int in_ECX;
  tagPOINT local_c;
  
  iVar1 = DrawTextExW(*(HDC *)(in_ECX + 4),param_1,param_2,param_3,param_4,param_5);
  local_c.x = 0;
  local_c.y = 0;
  GetCurrentPositionEx(*(HDC *)(in_ECX + 4),&local_c);
  MoveToEx(*(HDC *)(in_ECX + 8),local_c.x,local_c.y,(LPPOINT)0x0);
  return iVar1;
}




/* vtable slots: CPreviewDC[26] */
/* 007cea6a  FUN_007cea6a  78 bytes, 0 callers */

int FUN_007cea6a(LPCWSTR param_1,int param_2,LPRECT param_3,UINT param_4)

{
  int iVar1;
  int in_ECX;
  tagPOINT local_c;
  
  iVar1 = DrawTextW(*(HDC *)(in_ECX + 4),param_1,param_2,param_3,param_4);
  local_c.x = 0;
  local_c.y = 0;
  GetCurrentPositionEx(*(HDC *)(in_ECX + 4),&local_c);
  MoveToEx(*(HDC *)(in_ECX + 8),local_c.x,local_c.y,(LPPOINT)0x0);
  return iVar1;
}




/* vtable slots: CPreviewDC[29] */
/* 007ceab8  FUN_007ceab8  135 bytes, 0 callers */

int FUN_007ceab8(int param_1,int param_2,LPCSTR param_3,LPVOID param_4)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 < 0x101) {
    if (param_1 != 0x100) {
      switch(param_1) {
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x1a:
      case 0x1b:
      case 0x1c:
      case 0x1d:
      case 0x1e:
      case 0x1f:
      case 0x20:
      case 0x22:
      case 0x23:
        break;
      default:
        goto LAB_007ceb3b;
      }
    }
  }
  else {
    if (param_1 < 0x303) {
      if (((param_1 == 0x302) || (param_1 == 0x101)) || ((param_1 == 0x102 || (param_1 == 0x103))))
      goto switchD_007cead8_caseD_3;
      iVar1 = param_1 + -0x300;
    }
    else {
      if (((param_1 == 0x303) || (param_1 == 0x304)) || (param_1 == 0x1007))
      goto switchD_007cead8_caseD_3;
      iVar1 = param_1 + -0x1009;
    }
    if ((iVar1 != 0) && (iVar1 != 1)) {
LAB_007ceb3b:
      return 0;
    }
  }
switchD_007cead8_caseD_3:
  iVar1 = Escape(*(HDC *)(in_ECX + 8),param_1,param_2,param_3,param_4);
  return iVar1;
}




/* vtable slots: CPreviewDC[24] */
/* 007ceb69  FID_conflict:ExtTextOutA  269 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    public: virtual int __thiscall CPreviewDC::ExtTextOutA(int,int,unsigned int,struct tagRECT const
   *,char const *,unsigned int,int *)
    public: virtual int __thiscall CPreviewDC::ExtTextOutW(int,int,unsigned int,struct tagRECT const
   *,wchar_t const *,unsigned int,int *)
   
   Library: Visual Studio 2015 Release */

BOOL FID_conflict_ExtTextOutA
               (HDC hdc,int x,int y,UINT options,RECT *lprect,LPCSTR lpString,UINT c,INT *lpDx)

{
  char cVar1;
  UINT UVar2;
  int in_ECX;
  INT *lpDx_00;
  RECT *lpString_00;
  BOOL BVar3;
  RECT *pRVar4;
  INT *pIVar5;
  tagPOINT local_2c;
  undefined1 local_24 [4];
  int local_20;
  INT *local_1c;
  RECT *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  pIVar5 = (INT *)0x0;
  local_1c = (INT *)0x0;
  pRVar4 = (RECT *)0x0;
  local_18 = (RECT *)0x0;
  local_20 = 0;
  BVar3 = 1;
  local_8 = 1;
  lpDx_00 = (INT *)c;
  lpString_00 = lprect;
  local_14 = in_ECX;
  if (c == 0) {
    if (lpString == (LPCSTR)0x0) goto LAB_007cec5e;
    cVar1 = FUN_007ce56d(lpString);
    if ((cVar1 == '\0') ||
       (cVar1 = FUN_007ce5ec(lpString), pRVar4 = local_18, pIVar5 = local_1c, cVar1 == '\0')) {
      BVar3 = 0;
      pIVar5 = local_1c;
      goto LAB_007cec5e;
    }
    FUN_007ce6ed(&local_2c,&hdc,lprect,&lpString,0,0,0,0,local_18,local_1c,&local_20);
    lpDx_00 = pIVar5;
    lpString_00 = pRVar4;
  }
  BVar3 = ExtTextOutW(*(HDC *)(local_14 + 4),(int)hdc,x,y,(RECT *)options,(LPCWSTR)lpString_00,
                      (UINT)lpString,lpDx_00);
  if (((local_20 != 0) && (BVar3 != 0)) &&
     (UVar2 = GetTextAlign(*(HDC *)(local_14 + 8)), (UVar2 & 1) != 0)) {
    local_2c.x = 0;
    local_2c.y = 0;
    GetCurrentPositionEx(*(HDC *)(local_14 + 4),&local_2c);
    FUN_0079ec58(local_24,local_2c.x - local_20,local_2c.y);
  }
LAB_007cec5e:
  thunk_FUN_008f43b0(pRVar4);
  thunk_FUN_008f43b0(pIVar5);
  return BVar3;
}




/* vtable slots: CPreviewDC[0] */
/* 007cec76  FUN_007cec76  6 bytes, 0 callers */

undefined ** FUN_007cec76(void)

{
  return &PTR_s_CPreviewDC_00986014;
}




/* vtable slots: CPreviewDC[28] */
/* 007cec7c  unshift  42 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: int __thiscall std::codecvt<char,char,int>::unshift(int &,char *,char *,char * &)const 
    public: int __thiscall std::codecvt<char,char,struct _Mbstatet>::unshift(struct _Mbstatet &,char
   *,char *,char * &)const 
    public: int __thiscall std::codecvt<unsigned short,char,int>::unshift(int &,char *,char *,char *
   &)const 
    public: int __thiscall std::codecvt<unsigned short,char,struct _Mbstatet>::unshift(struct
   _Mbstatet &,char *,char *,char * &)const 
     6 names - too many to list
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void unshift(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x5c);
  guard_check_icall(param_5,param_6,param_3,param_4);
  (*pcVar1)();
  return;
}




/* vtable slots: CPreviewDC[15] */
/* 007cf131  FUN_007cf131  48 bytes, 0 callers */

LPPOINT FUN_007cf131(LPPOINT param_1,int param_2,int param_3)

{
  int in_ECX;
  
  param_1->x = 0;
  param_1->y = 0;
  OffsetViewportOrgEx(*(HDC *)(in_ECX + 8),param_2,param_3,param_1);
  FUN_007cf0b7();
  return param_1;
}




/* vtable slots: CPreviewDC[6] */
/* 007cf1c8  FUN_007cf1c8  23 bytes, 0 callers */

void FUN_007cf1c8(void)

{
  int in_ECX;
  
  RestoreDC(*(HDC *)(in_ECX + 4),*(int *)(in_ECX + 0x18));
  FUN_0079ed58();
  return;
}




/* vtable slots: CPreviewDC[8] */
/* 007cf1df  RestoreDC  72 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CPreviewDC::RestoreDC(int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CPreviewDC::RestoreDC(CPreviewDC *this,int param_1)

{
  BOOL BVar1;
  
  BVar1 = ::RestoreDC(*(HDC *)(this + 8),param_1);
  if ((BVar1 != 0) && (*(int *)(this + 0x1c) != 0x7fff)) {
    if (param_1 != -1) {
      param_1 = param_1 + *(int *)(this + 0x1c);
    }
    BVar1 = ::RestoreDC(*(HDC *)(this + 4),param_1);
    FUN_007ceda6();
  }
  return BVar1;
}




/* vtable slots: CPreviewDC[7] */
/* 007cf227  SaveDC  79 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CPreviewDC::SaveDC(void)
   
   Library: Visual Studio 2015 Release */

int __thiscall CPreviewDC::SaveDC(CPreviewDC *this)

{
  int iVar1;
  HGDIOBJ h;
  int iVar2;
  
  iVar1 = ::SaveDC(*(HDC *)(this + 8));
  if (*(int *)(this + 4) == 0) {
    *(undefined4 *)(this + 0x1c) = 0x7fff;
  }
  else {
    h = GetStockObject(0xd);
    ::SelectObject(*(HDC *)(this + 4),h);
    iVar2 = ::SaveDC(*(HDC *)(this + 4));
    *(int *)(this + 0x1c) = iVar2 - iVar1;
    ::SelectObject(*(HDC *)(this + 4),*(HGDIOBJ *)(this + 0x28));
  }
  return iVar1;
}




/* vtable slots: CPreviewDC[17] */
/* 007cf276  FUN_007cf276  56 bytes, 0 callers */

LPSIZE FUN_007cf276(LPSIZE param_1,int param_2,int param_3,int param_4,int param_5)

{
  int in_ECX;
  
  param_1->cx = 0;
  param_1->cy = 0;
  ScaleViewportExtEx(*(HDC *)(in_ECX + 8),param_2,param_3,param_4,param_5,param_1);
  FUN_007cefa0(1);
  return param_1;
}




/* vtable slots: CPreviewDC[19] */
/* 007cf2ae  FUN_007cf2ae  56 bytes, 0 callers */

LPSIZE FUN_007cf2ae(LPSIZE param_1,int param_2,int param_3,int param_4,int param_5)

{
  int in_ECX;
  
  param_1->cx = 0;
  param_1->cy = 0;
  ScaleWindowExtEx(*(HDC *)(in_ECX + 8),param_2,param_3,param_4,param_5,param_1);
  FUN_007cefa0(1);
  return param_1;
}




/* vtable slots: CPreviewDC[10] */
/* 007cf2e6  SelectObject  66 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CFont * __thiscall CPreviewDC::SelectObject(class CFont *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

CFont * __thiscall CPreviewDC::SelectObject(CPreviewDC *this,CFont *param_1)

{
  CFont *pCVar1;
  HGDIOBJ pvVar2;
  
  if (param_1 == (CFont *)0x0) {
    pCVar1 = (CFont *)0x0;
  }
  else {
    pvVar2 = ::SelectObject(*(HDC *)(this + 8),*(HGDIOBJ *)(param_1 + 4));
    pCVar1 = (CFont *)CGdiObject::FromHandle(pvVar2);
    if (*(int *)(this + 0x2c) != *(int *)(param_1 + 4)) {
      *(int *)(this + 0x2c) = *(int *)(param_1 + 4);
      FUN_007ceda6();
    }
  }
  return pCVar1;
}




/* vtable slots: CPreviewDC[9] */
/* 007cf328  FUN_007cf328  132 bytes, 0 callers */

CGdiObject * FUN_007cf328(int param_1)

{
  HGDIOBJ pvVar1;
  CGdiObject *pCVar2;
  HGDIOBJ pvVar3;
  int in_ECX;
  
  pvVar1 = GetStockObject(param_1);
  if ((((param_1 == 10) || (param_1 == 0xb)) || (param_1 == 0xc)) ||
     (((param_1 == 0xd || (param_1 == 0xe)) || ((param_1 == 0x10 || (param_1 == 0x11)))))) {
    pvVar3 = SelectObject(*(HDC *)(in_ECX + 8),pvVar1);
    pCVar2 = CGdiObject::FromHandle(pvVar3);
    if (*(HGDIOBJ *)(in_ECX + 0x2c) != pvVar1) {
      *(HGDIOBJ *)(in_ECX + 0x2c) = pvVar1;
      FUN_007ceda6();
    }
  }
  else {
    if (*(int *)(in_ECX + 4) != 0) {
      SelectObject(*(HDC *)(in_ECX + 4),pvVar1);
    }
    pvVar1 = SelectObject(*(HDC *)(in_ECX + 8),pvVar1);
    pCVar2 = CGdiObject::FromHandle(pvVar1);
  }
  return pCVar2;
}




/* vtable slots: CPreviewDC[3] */
/* 007cf3ac  SetAttribDC  42 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CPreviewDC::SetAttribDC(struct HDC__ *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

void __thiscall CPreviewDC::SetAttribDC(CPreviewDC *this,HDC__ *param_1)

{
  CDC::SetAttribDC((CDC *)this,param_1);
  FUN_007cefa0(1);
  FUN_007ceda6();
  FUN_007ceca6();
  return;
}




/* vtable slots: CPreviewDC[11] */
/* 007cf3d6  FUN_007cf3d6  51 bytes, 0 callers */

void FUN_007cf3d6(COLORREF param_1)

{
  COLORREF color;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    color = GetNearestColor(*(HDC *)(in_ECX + 8),param_1);
    SetBkColor(*(HDC *)(in_ECX + 4),color);
  }
  SetBkColor(*(HDC *)(in_ECX + 8),param_1);
  return;
}




/* vtable slots: CPreviewDC[13] */
/* 007cf409  SetMapMode  38 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CPreviewDC::SetMapMode(int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CPreviewDC::SetMapMode(CPreviewDC *this,int param_1)

{
  int iVar1;
  
  iVar1 = ::SetMapMode(*(HDC *)(this + 8),param_1);
  FUN_007cefa0(1);
  return iVar1;
}




/* vtable slots: CPreviewDC[4] */
/* 007cf42f  SetOutputDC  82 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CPreviewDC::SetOutputDC(struct HDC__ *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CPreviewDC::SetOutputDC(CPreviewDC *this,HDC__ *param_1)

{
  int iVar1;
  
  iVar1 = ::SaveDC(param_1);
  *(int *)(this + 0x18) = iVar1;
  CDC::SetOutputDC((CDC *)this,param_1);
  if (*(int *)(this + 8) != 0) {
    FUN_007cefa0(0);
    if (*(int *)(this + 0x28) == 0) {
      FUN_007ceda6();
    }
    else {
      ::SelectObject(*(HDC *)(this + 4),*(HGDIOBJ *)(this + 0x28));
    }
    FUN_007ceca6();
  }
  return;
}




/* vtable slots: CPreviewDC[12] */
/* 007cf4ac  FUN_007cf4ac  51 bytes, 0 callers */

void FUN_007cf4ac(COLORREF param_1)

{
  COLORREF color;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    color = GetNearestColor(*(HDC *)(in_ECX + 8),param_1);
    SetTextColor(*(HDC *)(in_ECX + 4),color);
  }
  SetTextColor(*(HDC *)(in_ECX + 8),param_1);
  return;
}




/* vtable slots: CPreviewDC[16] */
/* 007cf4f7  FUN_007cf4f7  50 bytes, 0 callers */

LPSIZE FUN_007cf4f7(LPSIZE param_1,int param_2,int param_3)

{
  int in_ECX;
  
  param_1->cx = 0;
  param_1->cy = 0;
  SetViewportExtEx(*(HDC *)(in_ECX + 8),param_2,param_3,param_1);
  FUN_007cefa0(1);
  return param_1;
}




/* vtable slots: CPreviewDC[14] */
/* 007cf529  FUN_007cf529  48 bytes, 0 callers */

LPPOINT FUN_007cf529(LPPOINT param_1,int param_2,int param_3)

{
  int in_ECX;
  
  param_1->x = 0;
  param_1->y = 0;
  SetViewportOrgEx(*(HDC *)(in_ECX + 8),param_2,param_3,param_1);
  FUN_007cf0b7();
  return param_1;
}




/* vtable slots: CPreviewDC[18] */
/* 007cf559  FUN_007cf559  50 bytes, 0 callers */

LPSIZE FUN_007cf559(LPSIZE param_1,int param_2,int param_3)

{
  int in_ECX;
  
  param_1->cx = 0;
  param_1->cy = 0;
  SetWindowExtEx(*(HDC *)(in_ECX + 8),param_2,param_3,param_1);
  FUN_007cefa0(1);
  return param_1;
}




/* vtable slots: CPreviewDC[25] */
/* 007cf58b  FUN_007cf58b  296 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 *
FUN_007cf58b(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            int param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  UINT UVar4;
  int *in_ECX;
  undefined4 uVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  int local_24;
  tagPOINT local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  if (param_5 < 1) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    local_18 = 0;
    local_14 = 0;
    local_8 = 1;
    cVar2 = FUN_007ce56d(param_5);
    local_20.y = param_5;
    uVar5 = 0;
    if ((cVar2 == '\0') || (cVar2 = FUN_007ce5ec(param_5), uVar5 = local_14, cVar2 == '\0')) {
      *param_1 = 0;
      param_1[1] = 0;
      thunk_FUN_008f43b0(uVar5);
      thunk_FUN_008f43b0(local_18);
    }
    else {
      FUN_007ce6ed(&local_30,&param_2,param_4,&local_20.y,1,param_6,param_7,param_8,local_14,
                   local_18,&local_24);
      pcVar1 = *(code **)(*in_ECX + 0x60);
      guard_check_icall(param_2,param_3,0,0,local_14,local_20.y,local_18);
      iVar3 = (*pcVar1)();
      if ((iVar3 != 0) && (UVar4 = GetTextAlign((HDC)in_ECX[2]), (UVar4 & 1) != 0)) {
        local_20.x = 0;
        local_20.y = 0;
        GetCurrentPositionEx((HDC)in_ECX[1],&local_20);
        FUN_0079ec58(local_28,local_20.x - local_24,local_20.y);
      }
      *param_1 = local_30;
      param_1[1] = local_2c;
      thunk_FUN_008f43b0(local_14);
      thunk_FUN_008f43b0(local_18);
    }
  }
  return param_1;
}




/* vtable slots: CPreviewDC[23] */
/* 007cf6b3  FUN_007cf6b3  47 bytes, 0 callers */

void FUN_007cf6b3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x60);
  guard_check_icall(param_1,param_2,0,0,param_3,param_4,0);
  (*pcVar1)();
  return;
}



