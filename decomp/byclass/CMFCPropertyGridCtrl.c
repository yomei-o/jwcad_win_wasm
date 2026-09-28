/* CMFCPropertyGridCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCPropertyGridCtrl[1] */
/* 007db533  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCPropertyGridCtrl::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCPropertyGridCtrl::_scalar_deleting_destructor_(CMFCPropertyGridCtrl *this,uint param_1)

{
  FUN_007db3ef();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x408);
    }
  }
  return this;
}




/* vtable slots: CMFCPropertyGridCtrl[92] */
/* 007db623  FUN_007db623  703 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007db623(void)

{
  code *pcVar1;
  HGDIOBJ h;
  int iVar2;
  HGDIOBJ wParam;
  int iVar3;
  int *in_ECX;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_a4;
  int local_a0;
  undefined1 local_74 [4];
  HDC local_70;
  HDC local_6c;
  tagTEXTMETRICW local_60;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_8 = 0x7db632;
  if ((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) {
    FUN_0079dea2(in_ECX);
    local_8 = 0;
    h = (HGDIOBJ)FUN_007df99f(local_74);
    GetTextMetricsW(local_6c,&local_60);
    in_ECX[0xd4] = 0;
    in_ECX[0xd5] = local_60.tmHeight + 4;
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetClientRect((HWND)in_ECX[8],&local_24);
    iVar2 = *in_ECX;
    if (in_ECX[0xbe] == 0) {
      guard_check_icall();
      (**(code **)(iVar2 + 0x164))();
      uVar6 = 0;
    }
    else {
      in_ECX[0xd4] = in_ECX[0xd5] + 4;
      guard_check_icall();
      iVar2 = (**(code **)(iVar2 + 0x164))();
      wParam = (HGDIOBJ)in_ECX[199];
      if (wParam == (HGDIOBJ)0x0) {
        wParam = GetStockObject(0x11);
      }
      SendMessageW(*(HWND *)(iVar2 + 0x20),0x30,(WPARAM)wParam,0);
      pcVar1 = *(code **)(*in_ECX + 0x164);
      guard_check_icall();
      (*pcVar1)();
      FUN_00797e71(0,local_24.left,local_24.top,local_24.right - local_24.left,in_ECX[0xd4],0x14);
      local_a0 = in_ECX[0xd6] + 2;
      local_a4 = 1;
      pcVar1 = *(code **)(*in_ECX + 0x164);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      SendMessageW(*(HWND *)(iVar2 + 0x20),0x120c,0,(LPARAM)&local_a4);
      local_a0 = (local_24.right - local_24.left) + 10;
      pcVar1 = *(code **)(*in_ECX + 0x164);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      SendMessageW(*(HWND *)(iVar2 + 0x20),0x120c,1,(LPARAM)&local_a4);
      pcVar1 = *(code **)(*in_ECX + 0x164);
      guard_check_icall();
      (*pcVar1)();
      uVar6 = 4;
    }
    FUN_00797f20(uVar6);
    SelectObject(local_70,h);
    in_ECX[0xca] = local_24.left;
    in_ECX[0xcb] = local_24.top;
    in_ECX[0xcc] = local_24.right;
    in_ECX[0xcd] = local_24.bottom;
    in_ECX[0xcb] = in_ECX[0xcb] + in_ECX[0xd4];
    if (((in_ECX[0xbf] != 0) && (iVar2 = in_ECX[0xce], iVar2 != -1)) &&
       (local_24.bottom != local_24.top && -1 < local_24.bottom - local_24.top)) {
      iVar4 = in_ECX[0xd5];
      if (iVar2 <= iVar4) {
        iVar2 = iVar4;
      }
      iVar4 = (local_24.bottom - iVar4) - local_24.top;
      if (iVar4 <= iVar2) {
        iVar2 = iVar4;
      }
      in_ECX[0xcd] = in_ECX[0xcd] - iVar2;
      in_ECX[0xce] = iVar2;
    }
    iVar2 = GetSystemMetrics(0x15);
    FUN_007dfbfa();
    if (in_ECX[0xd8] < 1) {
      iVar5 = 0;
      iVar4 = 0;
      iVar2 = 0;
      iVar3 = 0;
    }
    else {
      in_ECX[0xcc] = in_ECX[0xcc] - iVar2;
      iVar4 = in_ECX[0xcb];
      iVar3 = in_ECX[0xcd] - iVar4;
      iVar5 = in_ECX[0xcc];
    }
    FUN_00797e71(0,iVar5,iVar4,iVar2,iVar3,0x14);
    FUN_007df357();
    if ((int *)in_ECX[0xf6] != (int *)0x0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0xf6] + 0x94);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        pcVar1 = *(code **)(*(int *)in_ECX[0xf6] + 0x78);
        guard_check_icall();
        (*pcVar1)();
      }
    }
    RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x105);
    FUN_0079dfff();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[90] */
/* 007db9c2  CloseColorPopup  61 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCPropertyGridCtrl::CloseColorPopup(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCPropertyGridCtrl::CloseColorPopup(CMFCPropertyGridCtrl *this)

{
  CObject *this_00;
  
  this_00 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPropertyGridColorProperty_00988ea8,
                               *(CObject **)(this + 0x3d8));
  if (this_00 != (CObject *)0x0) {
    *(undefined4 *)(this_00 + 0xfc) = 0;
    *(undefined4 *)(this_00 + 0x50) = 0;
    CMFCPropertyGridProperty::Redraw((CMFCPropertyGridProperty *)this_00);
    if (*(int *)(this_00 + 0xb8) != 0) {
      FUN_00797df8();
      return;
    }
  }
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[109] */
/* 007db9ff  FUN_007db9ff  47 bytes, 0 callers */

void FUN_007db9ff(int param_1,int param_2)

{
  if (*(wchar_t **)(param_2 + 0x88) != (wchar_t *)0x0) {
    _wcscmp(*(wchar_t **)(param_1 + 0x88),*(wchar_t **)(param_2 + 0x88));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00404e80(0x80004005);
}




/* vtable slots: CMFCPropertyGridCtrl[94] */
/* 007dba2f  FUN_007dba2f  90 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007dba2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7dba3b;
  FUN_007c2511();
  puVar1 = (undefined4 *)FUN_007e5eba(local_14,L"Afx:PropList");
  local_8 = 0;
  uVar2 = FUN_00791f4f(*puVar1,&DAT_00956338,param_1,param_2,param_3,param_4,0);
  FUN_00406b10();
  return uVar2;
}




/* vtable slots: CMFCPropertyGridCtrl[96] */
/* 007dbb14  FUN_007dbb14  119 bytes, 0 callers */

undefined4 FUN_007dbb14(CMFCPropertyGridProperty *param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall(1);
  iVar2 = (*pcVar1)();
  if ((iVar2 == 0) || ((*(int *)(param_1 + 0x5c) != 0 && (*(int *)(param_1 + 0x6c) == 0)))) {
    uVar4 = 0;
  }
  else {
    pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
    guard_check_icall(param_2);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      CMFCPropertyGridProperty::Redraw(param_1);
      FUN_007df74e(param_1,1);
      pHVar3 = SetCapture((HWND)in_ECX[8]);
      CWnd::FromHandle(pHVar3);
    }
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CMFCPropertyGridCtrl[98] */
/* 007dbcbe  FUN_007dbcbe  165 bytes, 0 callers */

undefined4 FUN_007dbcbe(int param_1)

{
  code *pcVar1;
  HWND pHVar2;
  int iVar3;
  int iVar4;
  HWND pHVar5;
  int *in_ECX;
  
  iVar4 = in_ECX[0xf6];
  if ((iVar4 != 0) && (*(int *)(iVar4 + 0x58) != 0)) {
    if (param_1 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x18c);
      guard_check_icall(iVar4);
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        return 0;
      }
      pcVar1 = *(code **)(*(int *)in_ECX[0xf6] + 0x28);
      guard_check_icall(iVar4);
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) {
        return 0;
      }
    }
    if ((int *)in_ECX[0xf6] != (int *)0x0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0xf6] + 0x38);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) {
        return 0;
      }
    }
    pHVar2 = (HWND)in_ECX[8];
    pHVar5 = GetCapture();
    if (pHVar5 == pHVar2) {
      ReleaseCapture();
    }
    if ((CMFCPropertyGridProperty *)in_ECX[0xf6] != (CMFCPropertyGridProperty *)0x0) {
      CMFCPropertyGridProperty::Redraw((CMFCPropertyGridProperty *)in_ECX[0xf6]);
    }
  }
  return 1;
}




/* vtable slots: CMFCPropertyGridCtrl[89] */
/* 007dbf7c  FUN_007dbf7c  7 bytes, 0 callers */

int FUN_007dbf7c(void)

{
  int in_ECX;
  
  return in_ECX + 0x120;
}




/* vtable slots: CMFCPropertyGridCtrl[10] */
/* 007dbf93  FUN_007dbf93  6 bytes, 0 callers */

undefined ** FUN_007dbf93(void)

{
  return &PTR_FUN_009894b8;
}




/* vtable slots: CMFCPropertyGridCtrl[0] */
/* 007dbf99  FUN_007dbf99  6 bytes, 0 callers */

undefined ** FUN_007dbf99(void)

{
  return &PTR_s_CMFCPropertyGridCtrl_00988ec4;
}




/* vtable slots: CMFCPropertyGridCtrl[30] */
/* 007dbf9f  GetScrollBarCtrl  31 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual class CScrollBar * __thiscall CMFCPropertyGridCtrl::GetScrollBarCtrl(int)const 
    public: virtual class CScrollBar * __thiscall CMFCTasksPane::GetScrollBarCtrl(int)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

int GetScrollBarCtrl(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (((param_1 == 0) || (iVar1 = in_ECX + 0x278, iVar1 == 0)) || (*(int *)(in_ECX + 0x298) == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}




/* vtable slots: CMFCPropertyGridCtrl[102] */
/* 007dc1ab  FUN_007dc1ab  565 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007dc1ab(void)

{
  code *pcVar1;
  int iVar2;
  HCURSOR pHVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CMFCPropertyGridCtrl *in_ECX;
  undefined4 uVar6;
  undefined4 local_4c [2];
  wchar_t *local_44;
  undefined4 local_3c;
  undefined4 local_38;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar6 = 0;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0xf0) == 0) {
    FUN_0079dd6d();
    iVar2 = FUN_0079dd6d();
    pHVar3 = LoadCursorW(*(HINSTANCE *)(iVar2 + 0xc),(LPCWSTR)0x7904);
    iVar2 = FUN_007c2511();
    *(HCURSOR *)(iVar2 + 0xf0) = pHVar3;
  }
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0xf4) == 0) {
    FUN_0079dd6d();
    iVar2 = FUN_0079dd6d();
    pHVar3 = LoadCursorW(*(HINSTANCE *)(iVar2 + 0xc),(LPCWSTR)0x7905);
    iVar2 = FUN_007c2511();
    *(HCURSOR *)(iVar2 + 0xf4) = pHVar3;
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x194);
  guard_check_icall();
  (*pcVar1)();
  local_4c[0] = 6;
  local_38 = 0;
  local_44 = L"Property";
  pcVar1 = *(code **)(*(int *)in_ECX + 0x164);
  local_3c = 100;
  guard_check_icall();
  iVar2 = (*pcVar1)();
  SendMessageW(*(HWND *)(iVar2 + 0x20),0x120a,0,(LPARAM)local_4c);
  local_44 = L"Value";
  local_3c = 100;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x164);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  SendMessageW(*(HWND *)(iVar2 + 0x20),0x120a,1,(LPARAM)local_4c);
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x278) + 0x164);
  guard_check_icall(0x50000001,&local_18);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x80) + 0x164);
  guard_check_icall();
  (*pcVar1)();
  SendMessageW(*(HWND *)(in_ECX + 0xa0),0x401,1,0);
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x1c4) != -1) {
    iVar2 = FUN_007c2511();
    SendMessageW(*(HWND *)(in_ECX + 0xa0),0x418,0,*(LPARAM *)(iVar2 + 0x1c4));
  }
  FUN_00797e71(&DAT_00a11c68,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x13);
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1d8) + 0x164);
  guard_check_icall();
  (*pcVar1)();
  pHVar4 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar5 = CWnd::FromHandle(pHVar4);
  if (pCVar5 != (CWnd *)0x0) {
    iVar2 = FUN_0079d98a(&PTR_s_CDialog_0097cf08);
    if (iVar2 != 0) goto LAB_007dc3a9;
  }
  uVar6 = 1;
LAB_007dc3a9:
  *(undefined4 *)(in_ECX + 0x394) = uVar6;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x170);
  guard_check_icall();
  (*pcVar1)();
  FUN_007dba89();
  CMFCPropertyGridCtrl::CalcEditMargin(in_ECX);
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[101] */
/* 007dc3e0  FUN_007dc3e0  98 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007dc3e0(void)

{
  code *pcVar1;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x120) + 0x164);
  guard_check_icall(0x50000000,&local_18);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[110] */
/* 007dc4cb  NotifyAccessibility  95 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCPropertyGridCtrl::NotifyAccessibility(class
   CMFCPropertyGridProperty *)
   
   Library: Visual Studio 2012 Release */

void __thiscall
CMFCPropertyGridCtrl::NotifyAccessibility
          (CMFCPropertyGridCtrl *this,CMFCPropertyGridProperty *param_1)

{
  int iVar1;
  tagPOINT local_c;
  
  local_c.x = (LONG)this;
  local_c.y = (LONG)this;
  iVar1 = FUN_007c2511();
  if ((*(int *)(iVar1 + 0x19c) != 0) && (param_1 != (CMFCPropertyGridProperty *)0x0)) {
    *(CMFCPropertyGridProperty **)(this + 0x404) = param_1;
    local_c.x = *(LONG *)(param_1 + 0x30);
    local_c.y = *(LONG *)(param_1 + 0x34);
    ClientToScreen(*(HWND *)(this + 0x20),&local_c);
    NotifyWinEvent(0x8005,*(HWND *)(this + 0x20),-4,
                   CONCAT22((undefined2)local_c.y,(undefined2)local_c.x));
  }
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[97] */
/* 007dc61b  FUN_007dc61b  237 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007dc61b(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined1 local_1c [4];
  undefined1 local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x7dc627;
  pcVar1 = *(code **)(*(int *)in_ECX[0xf6] + 0x28);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    pcVar1 = *(code **)(*(int *)in_ECX[0xf6] + 0x24);
    guard_check_icall(local_18);
    (*pcVar1)();
    local_8 = 0;
    FUN_0079dd6d();
    FUN_0078ff40();
    local_8 = CONCAT31(local_8._1_3_,1);
    pcVar1 = *(code **)(*(int *)in_ECX[0xf6] + 0x3c);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    pcVar1 = *(code **)(*(int *)in_ECX[0xf6] + 0x24);
    guard_check_icall(local_1c);
    uVar4 = (*pcVar1)();
    cVar2 = FUN_00408c80(local_18,uVar4);
    FUN_00406b10();
    if (cVar2 != '\0') {
      pcVar1 = *(code **)(*in_ECX + 0x174);
      guard_check_icall(in_ECX[0xf6]);
      (*pcVar1)();
    }
    FUN_00408b00();
    FUN_00406b10();
  }
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[104] */
/* 007dc8c2  FUN_007dc8c2  329 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007dc8c2(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  HGDIOBJ h;
  undefined4 uVar5;
  int *in_ECX;
  int *local_6c;
  int local_68;
  int local_60 [11];
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_8 = 0x7dc8ce;
  FUN_007e522a(param_1,in_ECX);
  local_8 = 0;
  piVar2 = local_60;
  if (local_68 == 0) {
    piVar2 = local_6c;
  }
  piVar3 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar3 + 0x18c);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  in_ECX[0xf7] = iVar4;
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  GetClientRect((HWND)in_ECX[8],&local_24);
  pcVar1 = *(code **)(*in_ECX + 0x19c);
  guard_check_icall(piVar2,local_24.left,local_24.top,local_24.right,local_24.bottom);
  (*pcVar1)();
  h = (HGDIOBJ)FUN_007df99f(piVar2);
  pcVar1 = *(code **)(*piVar2 + 0x30);
  uVar5 = FUN_007dbfbe();
  guard_check_icall(uVar5);
  (*pcVar1)();
  FUN_0079f0b8(1);
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall(piVar2);
  (*pcVar1)();
  if (in_ECX[0xbf] != 0) {
    local_34.top = in_ECX[0xcd];
    local_34.left = local_24.left;
    local_34.right = local_24.right;
    local_34.bottom = local_24.bottom;
    if (local_24.bottom != local_34.top && -1 < local_24.bottom - local_34.top) {
      InflateRect(&local_34,-1,-1);
      pcVar1 = *(code **)(*in_ECX + 0x1ac);
      guard_check_icall(piVar2,local_34.left,local_34.top,local_34.right,local_34.bottom);
      (*pcVar1)();
    }
  }
  SelectObject((HDC)piVar2[1],h);
  FUN_007e54da();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[107] */
/* 007dca0b  FUN_007dca0b  302 bytes, 0 callers */

void FUN_007dca0b(CDC *param_1,LONG param_2,int param_3,LONG param_4,LONG param_5)

{
  code *pcVar1;
  HBRUSH hbr;
  int iVar2;
  ulong uVar3;
  int in_ECX;
  HBRUSH local_14;
  int local_8;
  
  if (*(int *)(in_ECX + 0x3f0) == -1) {
    if (*(int *)(in_ECX + 0x394) == 0) {
      iVar2 = FUN_007c2511();
      iVar2 = iVar2 + 0x98;
    }
    else {
      iVar2 = FUN_007c2511();
      iVar2 = iVar2 + 0xd0;
    }
    if (iVar2 == 0) {
      hbr = (HBRUSH)0x0;
    }
    else {
      hbr = *(HBRUSH *)(iVar2 + 4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  }
  else {
    FUN_0079de5e(*(int *)(in_ECX + 0x3f0));
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,local_14);
    FUN_00416100();
  }
  param_3 = param_3 + 4;
  if (*(int *)(in_ECX + 0x394) == 0) {
    iVar2 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar2 + 0x20);
  }
  else {
    iVar2 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar2 + 0x58);
  }
  CDC::Draw3dRect(param_1,(tagRECT *)&param_2,uVar3,uVar3);
  if (*(int *)(in_ECX + 0x3d8) != 0) {
    InflateRect((LPRECT)&param_2,-4,-4);
    local_8 = -1;
    if (*(int *)(in_ECX + 0x3f4) != -1) {
      pcVar1 = *(code **)(*(int *)param_1 + 0x30);
      guard_check_icall(*(int *)(in_ECX + 0x3f4));
      local_8 = (*pcVar1)();
    }
    iVar2 = **(int **)(in_ECX + 0x3d8);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5);
    (**(code **)(iVar2 + 0x20))();
    if (local_8 == -1) {
      pcVar1 = *(code **)(*(int *)param_1 + 0x30);
      guard_check_icall(0xffffffff);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[106] */
/* 007dcb39  FUN_007dcb39  242 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007dcb39(CDC *param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  undefined4 *puVar5;
  undefined1 local_24 [8];
  undefined **local_1c [2];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x7dcb45;
  if (in_ECX[0xe5] == 0) {
    iVar3 = FUN_007c2511();
    iVar3 = *(int *)(iVar3 + 0x20);
  }
  else {
    iVar3 = FUN_007c2511();
    iVar3 = *(int *)(iVar3 + 0x58);
  }
  iVar4 = in_ECX[0xfe];
  if ((in_ECX[0xfe] == -1) && (iVar4 = iVar3, in_ECX[0xc2] != 0)) {
    iVar4 = in_ECX[0xf7];
  }
  FUN_0079df60(0,1,iVar4);
  local_8 = 0;
  local_14 = FUN_0079efbc(local_1c);
  iVar3 = in_ECX[0xd6];
  iVar4 = in_ECX[0xca];
  FUN_0079ec58(local_24,iVar3 + iVar4,in_ECX[0xcb] + -1);
  CDC::LineTo(param_1,iVar3 + iVar4,in_ECX[0xcd]);
  puVar5 = *(undefined4 **)((-(uint)(in_ECX[0xc1] != 0) & 0x1c) + 0x3a4 + (int)in_ECX);
  do {
    if (puVar5 == (undefined4 *)0x0) break;
    puVar1 = puVar5 + 2;
    puVar5 = (undefined4 *)*puVar5;
    pcVar2 = *(code **)(*in_ECX + 400);
    guard_check_icall(param_1,*puVar1);
    iVar3 = (*pcVar2)();
  } while (iVar3 != 0);
  FUN_0079efbc(local_14);
  local_1c[0] = CPen::vftable;
  FUN_00416100();
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[100] */
/* 007dcc2b  FUN_007dcc2b  1297 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007dcc2b(CDC *param_1,int *param_2)

{
  RECT *lprc;
  undefined4 *puVar1;
  undefined **ppuVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  CDC *pCVar6;
  BOOL BVar7;
  int iVar8;
  HRGN pHVar9;
  HDC pHVar10;
  int *in_ECX;
  HGDIOBJ h;
  int *piVar11;
  undefined4 *puVar12;
  CDC *pCVar13;
  HBRUSH pHVar14;
  HBRUSH local_90;
  undefined **local_88;
  undefined4 local_84;
  undefined **local_80;
  int iStack_7c;
  undefined **local_78;
  int local_74;
  int local_70;
  undefined **local_6c;
  undefined **local_68;
  HGDIOBJ local_64;
  int *local_60;
  int *local_5c;
  CDC *local_58;
  RECT local_54;
  RECT local_44;
  RECT local_34;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x84;
  local_8 = 0x7dcc3a;
  local_58 = param_1;
  local_60 = param_2;
  local_5c = in_ECX;
  BVar7 = IsRectEmpty((RECT *)(param_2 + 0xc));
  if (BVar7 == 0) {
    iVar8 = in_ECX[0xcd];
    if (iVar8 <= param_2[0xd]) goto LAB_007dd130;
    if (in_ECX[0xcb] <= param_2[0xf]) {
      iVar3 = in_ECX[0xca];
      local_6c = (undefined **)(in_ECX[0xd6] + iVar3);
      local_70 = -1;
      if (in_ECX[0xc2] != 0) {
        ppuVar2 = (undefined **)param_2[0xc];
        local_24.top = param_2[0xd];
        local_24.bottom = param_2[0xf];
        local_24.right = (LONG)param_2[0xe];
        if ((param_2[0x17] == 0) && (local_24.right = (LONG)local_6c, (int)ppuVar2 <= (int)local_6c)
           ) {
          local_24.right = (LONG)ppuVar2;
        }
        if (param_2[0x1b] != 0) {
          local_24.right = (local_24.bottom - local_24.top) + (int)ppuVar2;
        }
        if (iVar8 <= local_24.bottom) {
          local_24.bottom = iVar8;
        }
        param_1 = local_58;
        local_24.left = iVar3;
        if (iVar3 < local_24.right) {
          iVar8 = local_5c[0xfa];
          if (iVar8 == -1) {
            iVar8 = local_5c[0xf7];
          }
          FUN_0079de5e(iVar8);
          param_1 = local_58;
          FillRect(*(HDC *)(local_58 + 4),&local_24,local_90);
          FUN_00416100();
        }
      }
      if (param_2[0x19] == 0) {
        pcVar4 = *(code **)(*(int *)param_1 + 0x30);
        iVar8 = FUN_007c2511();
        guard_check_icall(*(undefined4 *)(iVar8 + 0x38));
        local_70 = (*pcVar4)();
      }
      local_24.left = param_2[0xc];
      local_24.top = param_2[0xd];
      local_24.right = param_2[0xe];
      local_24.bottom = param_2[0xf];
      if (((param_2[0x17] == 0) || (param_2[0x1b] != 0)) || (local_5c[0xe6] == 0)) {
        pcVar4 = *(code **)(*param_2 + 0x9c);
        guard_check_icall();
        iVar8 = (*pcVar4)();
        if (iVar8 != 0) {
          local_24.right = (LONG)local_6c;
        }
      }
      if (param_2[0x17] == 0) {
        pcVar4 = *(code **)(*param_2 + 0x9c);
        guard_check_icall();
        iVar8 = (*pcVar4)();
        piVar11 = param_2;
        if (iVar8 == 0) {
          local_34.top = local_24.top + 1;
          local_34.left = local_24.left;
          local_34.right = local_24.right;
          local_34.bottom = local_24.bottom;
          if ((local_5c == (int *)0xfffffc04) || (local_5c[0x100] == 0)) {
            iVar8 = FUN_007c2511();
            pHVar14 = (HBRUSH)0x0;
            if (iVar8 != -200) {
              pHVar14 = *(HBRUSH *)(iVar8 + 0xcc);
            }
          }
          else {
            pHVar14 = (HBRUSH)local_5c[0x100];
          }
          FillRect(*(HDC *)(local_58 + 4),&local_34,pHVar14);
        }
      }
      else {
        if (((local_5c[0xe6] != 0) && (local_5c[0xc2] == 0)) && (param_2[0x1b] == 0)) {
          local_34.top = local_24.top + 1;
          local_34.left = local_24.left;
          local_34.right = local_24.right;
          local_34.bottom = local_24.bottom;
          if ((local_5c == (int *)0xfffffc04) || (local_5c[0x100] == 0)) {
            iVar8 = FUN_007c2511();
            pHVar14 = (HBRUSH)0x0;
            if (iVar8 != -200) {
              pHVar14 = *(HBRUSH *)(iVar8 + 0xcc);
            }
          }
          else {
            pHVar14 = (HBRUSH)local_5c[0x100];
          }
          FillRect(*(HDC *)(local_58 + 4),&local_34,pHVar14);
        }
        local_78 = (undefined **)(local_24.left + local_5c[0xd5]);
        local_64 = (HGDIOBJ)0x0;
        local_80 = (undefined **)local_24.left;
        local_68 = CRgn::vftable;
        iStack_7c = local_24.top;
        local_74 = local_24.bottom;
        local_8 = 0;
        local_44.left = local_24.left;
        local_44.top = local_24.top;
        local_44.bottom = local_24.bottom;
        if (local_5c[0xcd] <= local_24.bottom) {
          local_44.bottom = local_5c[0xcd];
        }
        local_44.right = (LONG)local_78;
        local_24.left = (LONG)local_78;
        pHVar9 = CreateRectRgnIndirect(&local_44);
        Attach(pHVar9);
        FUN_0079eeb5(&local_68);
        pcVar4 = *(code **)(*param_2 + 0x18);
        guard_check_icall(local_58,local_80,iStack_7c,local_78,local_74);
        (*pcVar4)();
        local_68 = CRgn::vftable;
        FUN_00416100();
        piVar11 = local_60;
      }
      piVar5 = local_5c;
      if (local_24.left < local_24.right) {
        local_74 = 0;
        local_78 = CRgn::vftable;
        local_8 = 1;
        local_44.left = local_24.left;
        local_44.top = local_24.top;
        local_44.right = local_24.right;
        local_44.bottom = local_24.bottom;
        if (local_5c[0xcd] <= local_24.bottom) {
          local_44.bottom = local_5c[0xcd];
        }
        pHVar9 = CreateRectRgnIndirect(&local_44);
        Attach(pHVar9);
        pCVar13 = local_58;
        FUN_0079eeb5(&local_78);
        pHVar10 = (HDC)0x0;
        local_64 = (HGDIOBJ)0x0;
        if ((piVar11[0x17] != 0) && (piVar11[0x1b] == 0)) {
          h = (HGDIOBJ)0x0;
          if (piVar5 != (int *)0xfffffce0) {
            h = (HGDIOBJ)piVar5[0xc9];
          }
          if (pCVar13 != (CDC *)0x0) {
            pHVar10 = *(HDC *)(pCVar13 + 4);
          }
          local_64 = SelectObject(pHVar10,h);
        }
        pCVar13 = local_58;
        pcVar4 = *(code **)(*piVar11 + 0x10);
        guard_check_icall(local_58,local_24.left,local_24.top,local_24.right,local_24.bottom);
        (*pcVar4)();
        if (local_64 != (HGDIOBJ)0x0) {
          if (pCVar13 == (CDC *)0x0) {
            pHVar10 = (HDC)0x0;
          }
          else {
            pHVar10 = *(HDC *)(pCVar13 + 4);
          }
          SelectObject(pHVar10,local_64);
        }
        local_78 = CRgn::vftable;
        FUN_00416100();
      }
      local_84 = 0;
      local_54.left = (int)local_6c + 1;
      local_88 = CRgn::vftable;
      local_54.top = param_2[0xd];
      local_54.right = param_2[0xe];
      local_24.bottom = param_2[0xf];
      local_8 = 2;
      local_54.bottom = local_24.bottom;
      if (local_5c[0xcd] <= local_24.bottom) {
        local_54.bottom = local_5c[0xcd];
      }
      local_24.left = local_54.left;
      local_24.top = local_54.top;
      local_24.right = local_54.right;
      pHVar9 = CreateRectRgnIndirect(&local_54);
      Attach(pHVar9);
      FUN_0079eeb5(&local_88);
      pCVar13 = local_58;
      pcVar4 = *(code **)(*local_60 + 0x14);
      guard_check_icall(local_58,local_24.left,local_24.top,local_24.right,local_24.bottom);
      (*pcVar4)();
      param_2 = local_60;
      lprc = (RECT *)(local_60 + 0x10);
      BVar7 = IsRectEmpty(lprc);
      pCVar6 = local_58;
      if (BVar7 == 0) {
        pcVar4 = *(code **)(*param_2 + 0x1c);
        guard_check_icall(local_58,lprc->left,param_2[0x11],param_2[0x12],param_2[0x13]);
        (*pcVar4)();
        param_2 = local_60;
        pCVar13 = pCVar6;
      }
      FUN_0079eeb5(0);
      FUN_0079ec58(&local_78,local_5c[0xca],param_2[0xf]);
      CDC::LineTo(pCVar13,local_5c[0xcc],param_2[0xf]);
      if (local_70 != -1) {
        pcVar4 = *(code **)(*(int *)pCVar13 + 0x30);
        guard_check_icall(local_70);
        (*pcVar4)();
      }
      local_8 = 0xffffffff;
      local_88 = CRgn::vftable;
      FUN_00416100();
      in_ECX = local_5c;
    }
  }
  if ((param_2[0x18] != 0) || (in_ECX[0xc1] != 0)) {
    puVar12 = (undefined4 *)param_2[0x34];
    do {
      if (puVar12 == (undefined4 *)0x0) break;
      puVar1 = puVar12 + 2;
      puVar12 = (undefined4 *)*puVar12;
      pcVar4 = *(code **)(*in_ECX + 400);
      guard_check_icall(local_58,*puVar1);
      iVar8 = (*pcVar4)();
    } while (iVar8 != 0);
  }
LAB_007dd130:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[103] */
/* 007dd1e7  OnFillBackground  60 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCPropertyGridCtrl::OnFillBackground(class CDC *,class
   CRect)
   
   Library: Visual Studio 2012 Release */

void __thiscall CMFCPropertyGridCtrl::OnFillBackground(CMFCPropertyGridCtrl *this,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  
  if ((this == (CMFCPropertyGridCtrl *)0xfffffc04) || (*(int *)(this + 0x400) == 0)) {
    iVar1 = FUN_007c2511();
    hbr = (HBRUSH)0x0;
    if (iVar1 != -200) {
      hbr = *(HBRUSH *)(iVar1 + 0xcc);
    }
  }
  else {
    hbr = *(HBRUSH *)(this + 0x400);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[62] */
/* 007de397  FUN_007de397  77 bytes, 0 callers */

undefined4 FUN_007de397(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00793ba8(param_1,param_2,param_3);
  if (param_2 != 0) {
    if (*(int *)(param_2 + 8) == -0x209) {
      FUN_00797e71(&DAT_00a11c68,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x13);
    }
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCPropertyGridCtrl[93] */
/* 007de452  FUN_007de452  56 bytes, 0 callers */

void FUN_007de452(LPARAM param_1)

{
  CWnd *pCVar1;
  WPARAM wParam;
  CWnd *in_ECX;
  
  FUN_007dfa0c();
  pCVar1 = CWnd::GetOwner(in_ECX);
  wParam = FUN_00797a2b();
  SendMessageW(*(HWND *)(pCVar1 + 0x20),DAT_00a124e8,wParam,param_1);
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[20] */
/* 007de9bf  FUN_007de9bf  43 bytes, 0 callers */

void FUN_007de9bf(void)

{
  code *pcVar1;
  _AFX_THREAD_STATE *p_Var2;
  int *in_ECX;
  
  guard_check_icall();
  p_Var2 = AfxGetThreadState();
  if (*(int *)(p_Var2 + 0x14) == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x198);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[67] */
/* 007de9ea  FUN_007de9ea  2099 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007de9ea(int *param_1)

{
  uint uVar1;
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  LRESULT LVar6;
  BOOL BVar7;
  int iVar8;
  int *in_ECX;
  HWND pHVar9;
  code *pcVar10;
  UINT Msg;
  WPARAM wParam;
  tagPOINT local_48;
  HWND local_40;
  int *local_3c;
  char local_35;
  tagRECT local_34;
  undefined1 local_24 [12];
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x7de9f6;
  local_3c = param_1;
  local_40 = (HWND)0x0;
  uVar1 = param_1[1];
  if (uVar1 < 0x105) {
    if (((uVar1 == 0x104) || (uVar1 == 0xa1)) ||
       ((uVar1 == 0xa2 ||
        ((((uVar1 == 0xa4 || (uVar1 == 0xa5)) || (uVar1 == 0xa7)) ||
         ((uVar1 == 0xa8 || (uVar1 == 0x100)))))))) {
LAB_007dea60:
      SendMessageW((HWND)in_ECX[0x28],0x407,0,(LPARAM)param_1);
      CMFCPropertyGridToolTipCtrl::Hide((CMFCPropertyGridToolTipCtrl *)(in_ECX + 0x76));
    }
  }
  else if (uVar1 == 0x200) {
    SendMessageW((HWND)in_ECX[0x28],0x407,0,(LPARAM)param_1);
    if (local_3c[2] == 0) {
      local_24._8_4_ = 0;
      local_18[0] = (int *)0x0;
      GetCursorPos((LPPOINT)(local_24 + 8));
      ScreenToClient((HWND)in_ECX[8],(LPPOINT)(local_24 + 8));
      FUN_007dffaf(local_24._8_4_,local_18[0]);
    }
  }
  else if ((((uVar1 == 0x201) || (uVar1 == 0x202)) || (uVar1 == 0x204)) ||
          (((uVar1 == 0x205 || (uVar1 == 0x207)) || (uVar1 == 0x208)))) goto LAB_007dea60;
  if (((local_3c[1] == 0x100) && (local_3c[2] == 9)) &&
     (local_18[0] = (int *)in_ECX[0xf6], local_18[0] != (int *)0x0)) {
    pcVar10 = *(code **)(*local_18[0] + 0xa8);
    guard_check_icall();
    iVar4 = (*pcVar10)();
    if (iVar4 != 0) goto LAB_007df1e1;
  }
  if (((local_3c[1] == 0x104) &&
      (((local_3c[2] == 0x28 || (local_3c[2] == 0x27)) && (iVar4 = in_ECX[0xf6], iVar4 != 0)))) &&
     ((*(int *)(iVar4 + 100) != 0 && ((*(byte *)(iVar4 + 0x2c) & 2) != 0)))) {
    pcVar10 = *(code **)(*in_ECX + 0x180);
    guard_check_icall(iVar4,0);
    iVar4 = (*pcVar10)();
    if (iVar4 == 0) goto LAB_007dec2a;
    pcVar10 = *(code **)(*(int *)in_ECX[0xf6] + 0x24);
    guard_check_icall(local_18);
    (*pcVar10)();
    local_8 = 0;
    FUN_0079dd6d();
    FUN_0078ff40();
    local_8 = CONCAT31(local_8._1_3_,1);
    pcVar10 = *(code **)(*(int *)in_ECX[0xf6] + 0x3c);
    guard_check_icall(0xffffffff,0xffffffff);
    (*pcVar10)();
    pcVar10 = *(code **)(*(int *)in_ECX[0xf6] + 0x24);
    guard_check_icall(&local_40);
    uVar5 = (*pcVar10)();
    local_35 = FUN_00408c80(local_18,uVar5);
    FUN_00406b10();
    if (local_35 != '\0') {
      pcVar10 = *(code **)(*in_ECX + 0x174);
      guard_check_icall(in_ECX[0xf6]);
      (*pcVar10)();
    }
    FUN_00408b00();
LAB_007dec1a:
    FUN_00406b10();
    goto LAB_007df1e1;
  }
LAB_007dec2a:
  pHVar9 = (HWND)0x0;
  if (((local_3c[1] == 0x100) && (local_3c[2] == 0xd)) &&
     ((iVar4 = in_ECX[0xf6], iVar4 != 0 &&
      ((*(int *)(iVar4 + 0x5c) != 0 && (*(int *)(iVar4 + 0x58) == 0)))))) {
    FUN_007dbe9a(*(int *)(iVar4 + 0x60) == 0);
    goto LAB_007df1e1;
  }
  iVar4 = in_ECX[0xf6];
  if (((iVar4 == 0) || (*(int *)(iVar4 + 0x58) == 0)) || (*(int *)(iVar4 + 100) == 0)) {
LAB_007df1d9:
    FUN_007949fb(local_3c);
  }
  else {
    if ((*(int *)(iVar4 + 0xbc) == 0) ||
       (LVar6 = SendMessageW(*(HWND *)(*(int *)(iVar4 + 0xbc) + 0x20),0x157,0,0), LVar6 == 0)) {
      bVar2 = false;
      local_18[0] = (int *)0x0;
    }
    else {
      bVar2 = true;
      local_18[0] = (int *)0x1;
    }
    uVar1 = local_3c[1];
    if (uVar1 == 0x100) {
      if ((bVar2) && (local_3c[2] != 0xd)) goto LAB_007df1e1;
      iVar4 = local_3c[2];
      if (iVar4 == 0xd) {
        local_3c = (int *)in_ECX[0xf6];
        if (local_3c[0x15] != 0) {
          pcVar10 = *(code **)(*local_3c + 0x24);
          guard_check_icall(local_18);
          (*pcVar10)();
          local_8 = 2;
          FUN_0079dd6d();
          FUN_0078ff40();
          local_8 = CONCAT31(local_8._1_3_,3);
          pcVar10 = *(code **)(*(int *)in_ECX[0xf6] + 0x3c);
          guard_check_icall(0xffffffff,0xffffffff);
          (*pcVar10)();
          pcVar10 = *(code **)(*(int *)in_ECX[0xf6] + 0x24);
          guard_check_icall(&local_40);
          uVar5 = (*pcVar10)();
          local_35 = FUN_00408c80(local_18,uVar5);
          FUN_00406b10();
          if (local_35 != '\0') {
            pcVar10 = *(code **)(*in_ECX + 0x174);
            guard_check_icall(in_ECX[0xf6]);
            (*pcVar10)();
          }
          FUN_00408b00();
          goto LAB_007dec1a;
        }
        if (local_18[0] != (int *)0x0) {
          if (local_3c[0x2e] != 0) {
            local_40 = *(HWND *)(local_3c[0x2e] + 0x20);
          }
          pcVar10 = *(code **)(*local_3c + 0x48);
          guard_check_icall();
          (*pcVar10)();
          BVar7 = IsWindow(local_40);
          if (BVar7 != 0) {
            FUN_00797df8();
          }
        }
        pcVar10 = *(code **)(*in_ECX + 0x188);
        guard_check_icall(1);
        iVar4 = (*pcVar10)();
        if (iVar4 == 0) {
          MessageBeep(0xffffffff);
        }
      }
      else {
        if (iVar4 != 0x1b) {
          if ((iVar4 == 0x26) || (iVar4 == 0x28)) {
            local_40 = (HWND)in_ECX[0xf6];
            if (local_40[0x2a].unused < 2) {
              if (local_40[0x2e].unused != 0) {
                pHVar9 = *(HWND *)(local_40[0x2e].unused + 0x20);
              }
              BVar7 = IsWindow(pHVar9);
              if (BVar7 == 0) goto LAB_007df1e1;
              iVar4 = local_3c[3];
              wParam = local_3c[2];
              Msg = 0x100;
              iVar8 = *(int *)(in_ECX[0xf6] + 0xb8);
              goto LAB_007ded99;
            }
            pcVar10 = *(code **)(local_40->unused + 0xac);
            guard_check_icall(iVar4 != 0x26);
          }
          else {
            local_40 = (HWND)in_ECX[0xf6];
            if (local_40[0x1a].unused != 0) {
              pcVar10 = *(code **)(*in_ECX + 0x1b0);
              guard_check_icall(iVar4);
              (*pcVar10)();
              goto LAB_007df1e1;
            }
            pcVar10 = *(code **)(local_40->unused + 0x54);
            guard_check_icall(iVar4);
          }
          (*pcVar10)();
          goto LAB_007df1e1;
        }
        pcVar10 = *(code **)(*in_ECX + 0x188);
        guard_check_icall(0);
        (*pcVar10)();
      }
      FUN_00797df8();
      goto LAB_007df1e1;
    }
    if ((uVar1 < 0x200) || (0x20e < uVar1)) goto LAB_007df1e1;
    local_48.x = 0;
    local_48.y = 0;
    GetCursorPos(&local_48);
    ScreenToClient((HWND)in_ECX[8],&local_48);
    if (*(int *)(in_ECX[0xf6] + 0xc0) == 0) {
LAB_007defdd:
      local_18[0] = *(int **)(in_ECX[0xf6] + 0xb8);
      if (*(int *)(in_ECX[0xf6] + 0x68) == 0) {
        HideCaret((HWND)local_18[0][8]);
      }
      local_34.left = 0;
      local_34.top = 0;
      local_34.right = 0;
      local_34.bottom = 0;
      GetClientRect((HWND)local_18[0][8],&local_34);
      MapWindowPoints((HWND)local_18[0][8],(HWND)in_ECX[8],(LPPOINT)&local_34,2);
      pt_00.y = local_48.y;
      pt_00.x = local_48.x;
      BVar7 = PtInRect(&local_34,pt_00);
      if ((BVar7 != 0) && (local_3c[1] == 0x203)) {
        pcVar10 = *(code **)(*(int *)in_ECX[0xf6] + 0x44);
        guard_check_icall(local_48.x,local_48.y);
        iVar4 = (*pcVar10)();
        if (iVar4 != 0) goto LAB_007df1e1;
      }
      pt_01.y = local_48.y;
      pt_01.x = local_48.x;
      BVar7 = PtInRect(&local_34,pt_01);
      if (((BVar7 != 0) && (local_3c[1] == 0x204)) && (*(int *)(in_ECX[0xf6] + 0x68) == 0))
      goto LAB_007df1e1;
      pt_02.y = local_48.y;
      pt_02.x = local_48.x;
      BVar7 = PtInRect(&local_34,pt_02);
      piVar3 = local_18[0];
      if ((BVar7 == 0) &&
         (((iVar4 = local_3c[1], iVar4 == 0x201 || (iVar4 == 0xa1)) ||
          ((iVar4 == 0x204 || (iVar4 == 0x207)))))) {
        pt_03.y = local_48.y;
        pt_03.x = local_48.x;
        BVar7 = PtInRect((RECT *)(in_ECX[0xf6] + 0x40),pt_03);
        if (BVar7 != 0) {
          pcVar10 = *(code **)(*(int *)in_ECX[0xf6] + 0x24);
          guard_check_icall(&local_40);
          (*pcVar10)();
          local_8 = 4;
          FUN_0079dd6d();
          FUN_0078ff40();
          local_8 = CONCAT31(local_8._1_3_,5);
          pcVar10 = *(code **)(*in_ECX + 0x184);
          guard_check_icall(local_48.x,local_48.y);
          (*pcVar10)();
          pcVar10 = *(code **)(*(int *)in_ECX[0xf6] + 0x24);
          guard_check_icall(&local_3c);
          uVar5 = (*pcVar10)();
          local_35 = FUN_00408c80(&local_40,uVar5);
          FUN_00406b10();
          if (local_35 != '\0') {
            pcVar10 = *(code **)(*in_ECX + 0x174);
            guard_check_icall(in_ECX[0xf6]);
            (*pcVar10)();
          }
          FUN_00408b00();
          goto LAB_007dec1a;
        }
        pcVar10 = *(code **)(*in_ECX + 0x188);
        guard_check_icall(1);
        iVar4 = (*pcVar10)();
        if (iVar4 == 0) goto LAB_007df1e1;
        goto LAB_007df1d9;
      }
      MapWindowPoints((HWND)in_ECX[8],(HWND)local_18[0][8],&local_48,1);
      iVar4 = CONCAT22((undefined2)local_48.y,(undefined2)local_48.x);
      wParam = local_3c[2];
      Msg = local_3c[1];
      pHVar9 = (HWND)piVar3[8];
    }
    else {
      local_24._0_4_ = 0;
      local_24._4_4_ = 0;
      local_24._8_4_ = 0;
      local_18[0] = (int *)0x0;
      GetClientRect(*(HWND *)(*(int *)(in_ECX[0xf6] + 0xc0) + 0x20),(LPRECT)local_24);
      MapWindowPoints(*(HWND *)(*(int *)(in_ECX[0xf6] + 0xc0) + 0x20),(HWND)in_ECX[8],
                      (LPPOINT)local_24,2);
      pt.y = local_48.y;
      pt.x = local_48.x;
      BVar7 = PtInRect((RECT *)local_24,pt);
      if (BVar7 == 0) goto LAB_007defdd;
      if (*(int *)(in_ECX[0xf6] + 0xc0) != 0) {
        pHVar9 = *(HWND *)(*(int *)(in_ECX[0xf6] + 0xc0) + 0x20);
      }
      MapWindowPoints((HWND)in_ECX[8],pHVar9,&local_48,1);
      iVar4 = CONCAT22((undefined2)local_48.y,(undefined2)local_48.x);
      wParam = local_3c[2];
      Msg = local_3c[1];
      iVar8 = *(int *)(in_ECX[0xf6] + 0xc0);
LAB_007ded99:
      pHVar9 = *(HWND *)(iVar8 + 0x20);
    }
    SendMessageW(pHVar9,Msg,wParam,iVar4);
  }
LAB_007df1e1:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[108] */
/* 007df21d  ProcessClipboardAccelerators  186 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CMFCPropertyGridCtrl::ProcessClipboardAccelerators(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCPropertyGridCtrl::ProcessClipboardAccelerators(CMFCPropertyGridCtrl *this,uint param_1)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  UINT Msg;
  
  if (*(int *)(this + 0x3d8) == 0) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(this + 0x3d8) + 0xb8);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(iVar1 + 0x20) == 0) {
    return 0;
  }
  uVar2 = GetAsyncKeyState(0x11);
  uVar3 = GetAsyncKeyState(0x10);
  if ((uVar2 & 0x8000) == 0) {
LAB_007df27b:
    if (((uVar3 & 0x8000) == 0) || (param_1 != 0x2d)) {
      if ((((uVar2 & 0x8000) == 0) || (param_1 != 0x58)) &&
         (((uVar3 & 0x8000) == 0 || (param_1 != 0x2e)))) {
        return 0;
      }
      Msg = 0x300;
      goto LAB_007df298;
    }
  }
  else {
    if ((param_1 == 0x43) || (param_1 == 0x2d)) {
      Msg = 0x301;
      goto LAB_007df298;
    }
    if (param_1 != 0x56) goto LAB_007df27b;
  }
  Msg = 0x302;
LAB_007df298:
  SendMessageW(*(HWND *)(*(int *)(*(int *)(this + 0x3d8) + 0xb8) + 0x20),Msg,0,0);
  return 1;
}




/* vtable slots: CMFCPropertyGridCtrl[91] */
/* 007e02da  FUN_007e02da  143 bytes, 0 callers */

void FUN_007e02da(int param_1)

{
  int iVar1;
  code *pcVar2;
  CObject *pCVar3;
  BOOL BVar4;
  int *in_ECX;
  
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPropertyGridColorProperty_00988ea8,
                              (CObject *)in_ECX[0xf6]);
  if (pCVar3 != (CObject *)0x0) {
    iVar1 = *(int *)(pCVar3 + 0xe8);
    FUN_007df69b(param_1);
    if (param_1 != iVar1) {
      pcVar2 = *(code **)(*in_ECX + 0x174);
      guard_check_icall(pCVar3);
      (*pcVar2)();
    }
    if ((param_1 == -1) && (*(int *)(pCVar3 + 0xb8) != 0)) {
      BVar4 = IsWindow(*(HWND *)(*(int *)(pCVar3 + 0xb8) + 0x20));
      if (BVar4 != 0) {
        FUN_00797ece(&DAT_00956338);
      }
    }
    pcVar2 = *(code **)(*(int *)pCVar3 + 0x28);
    guard_check_icall();
    (*pcVar2)();
  }
  return;
}




/* vtable slots: CMFCPropertyGridCtrl[55] */
/* 007e0369  FUN_007e0369  111 bytes, 0 callers */

undefined4 FUN_007e0369(uint param_1,int param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  tagPOINT local_c;
  
  if (param_3 == (undefined2 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    local_c.x = param_1;
    local_c.y = param_2;
    ScreenToClient(*(HWND *)(in_ECX + 0x20),&local_c);
    uVar3 = 0;
    iVar2 = FUN_007dc03b(local_c.x,local_c.y,0,0);
    if (iVar2 != 0) {
      uVar3 = param_2 << 0x10 | param_1 & 0xffff;
    }
    *param_3 = 3;
    *(uint *)(param_3 + 4) = uVar3;
    *(int *)(in_ECX + 0x404) = iVar2;
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CMFCPropertyGridCtrl[53] */
/* 007e03d8  FUN_007e03d8  229 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007e03d8(int *param_1,int *param_2,int *param_3,int *param_4,short param_5,undefined4 param_6,
            int param_7)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
     (param_4 == (int *)0x0)) {
    uVar2 = 0x80070057;
  }
  else {
    if ((param_5 == 3) && (param_7 == 0)) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
      *param_1 = local_18.left;
      *param_2 = local_18.top;
      *param_3 = local_18.right - local_18.left;
      *param_4 = local_18.bottom - local_18.top;
    }
    else {
      iVar1 = *(int *)(in_ECX + 0x404);
      if (iVar1 != 0) {
        local_18.left = *(int *)(iVar1 + 0x30);
        local_18.top = *(int *)(iVar1 + 0x34);
        local_18.right = *(int *)(iVar1 + 0x38);
        local_18.bottom = *(int *)(iVar1 + 0x3c);
        FUN_0079e8b8(&local_18);
        *param_1 = local_18.left;
        *param_2 = local_18.top;
        *param_3 = local_18.right - local_18.left;
        *param_4 = local_18.bottom - local_18.top;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCPropertyGridCtrl[40] */
/* 007e04f7  get_accChild  29 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCPropertyGridCtrl::get_accChild(struct tagVARIANT,struct
   IDispatch * *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

long __thiscall
CMFCPropertyGridCtrl::get_accChild
          (CMFCPropertyGridCtrl *this,tagVARIANT param_1,IDispatch **param_2)

{
  long lVar1;
  
  if (*param_2 == (IDispatch *)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    *param_2 = *(IDispatch **)(this + 0x28);
    lVar1 = 0;
  }
  return lVar1;
}




/* vtable slots: CMFCPropertyGridCtrl[51] */
/* 007e052e  FUN_007e052e  8 bytes, 0 callers */

undefined4 FUN_007e052e(void)

{
  return 0x80020003;
}




/* vtable slots: CMFCPropertyGridCtrl[43] */
/* 007e0536  FUN_007e0536  140 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_007e0536(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  BSTR pOVar2;
  int in_ECX;
  OLECHAR *local_14;
  
  if (((param_1 == 3) || (param_3 == 0)) && (param_5 != (undefined4 *)0x0)) {
    if ((param_1 == 3) && (param_3 == 0)) {
      pOVar2 = SysAllocString(L"PropertyList");
      *param_5 = pOVar2;
    }
    else if (*(int *)(in_ECX + 0x404) != 0) {
      CStringT<>(*(undefined4 *)(*(int *)(in_ECX + 0x404) + 0x88));
      pOVar2 = SysAllocStringLen(local_14,*(UINT *)(local_14 + -6));
      if (pOVar2 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00407010();
      }
      *param_5 = pOVar2;
      FUN_00406b10();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}




/* vtable slots: CMFCPropertyGridCtrl[41] */
/* 007e05e7  FUN_007e05e7  301 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_007e05e7(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  OLECHAR *strIn;
  code *pcVar1;
  BSTR pOVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  OLECHAR *pOVar5;
  undefined1 local_1c [8];
  OLECHAR *local_14 [3];
  OLECHAR *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = (OLECHAR *)0x7e05f3;
  local_14[0] = (OLECHAR *)0x0;
  if (param_5 == (undefined4 *)0x0) {
    return 0x80070057;
  }
  if ((param_1 == 3) && (param_3 == 0)) {
    CStringT<>();
    local_8 = (OLECHAR *)0x0;
    FUN_00792c64(local_14);
    if (*(int *)(local_14[0] + -6) == 0) {
      pOVar2 = SysAllocString(L"PropertyList");
    }
    else {
      pOVar2 = SysAllocStringLen(local_14[0],*(UINT *)(local_14[0] + -6));
      if (pOVar2 == (BSTR)0x0) goto LAB_007e070f;
    }
    *param_5 = pOVar2;
  }
  else {
    piVar3 = *(int **)(in_ECX + 0x404);
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    if (piVar3[0x16] == 0) {
      piVar3 = (int *)CStringT<>(piVar3[0x22]);
      pOVar5 = (OLECHAR *)0x2;
    }
    else {
      pcVar1 = *(code **)(*piVar3 + 0x24);
      guard_check_icall(local_1c);
      piVar3 = (int *)(*pcVar1)();
      pOVar5 = (OLECHAR *)0x1;
    }
    local_14[0] = pOVar5;
    local_8 = pOVar5;
    iVar4 = FUN_004054a0(*piVar3 + -0x10);
    strIn = (OLECHAR *)(iVar4 + 0x10);
    local_8 = (OLECHAR *)0x3;
    local_14[0] = strIn;
    if (((uint)pOVar5 & 2) != 0) {
      pOVar5 = (OLECHAR *)((uint)pOVar5 & 0xfffffffd);
      FUN_00406b10();
    }
    local_8 = (OLECHAR *)CONCAT31(local_8._1_3_,5);
    if (((uint)pOVar5 & 1) != 0) {
      FUN_00406b10();
    }
    pOVar2 = SysAllocStringLen(strIn,*(UINT *)(iVar4 + 4));
    if (pOVar2 == (BSTR)0x0) {
LAB_007e070f:
                    /* WARNING: Subroutine does not return */
      FUN_00407010();
    }
    *param_5 = pOVar2;
  }
  FUN_00406b10();
  return 0;
}




/* vtable slots: CMFCPropertyGridCtrl[44] */
/* 007e0715  get_accRole  63 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCPropertyGridCtrl::get_accRole(struct tagVARIANT,struct
   tagVARIANT *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __thiscall
CMFCPropertyGridCtrl::get_accRole(CMFCPropertyGridCtrl *this,tagVARIANT param_1,tagVARIANT *param_2)

{
  if (param_2 == (tagVARIANT *)0x0) {
    return -0x7ff8ffa9;
  }
  if (param_1.n1.n2.vt == 3) {
    if (param_1.n1._8_4_ == 0) {
      *(undefined4 *)((int)&param_2->n1 + 8) = 0x21;
      goto LAB_007e0744;
    }
  }
  else if (param_1.n1._8_4_ != 0) {
    return -0x7ff8ffa9;
  }
  *(undefined4 *)((int)&param_2->n1 + 8) = 0x1c;
LAB_007e0744:
  (param_2->n1).n2.vt = 3;
  return 0;
}




/* vtable slots: CMFCPropertyGridCtrl[45] */
/* 007e0754  FUN_007e0754  138 bytes, 0 callers */

undefined4
FUN_007e0754(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined2 *param_5)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  int in_ECX;
  
  if ((param_1 == 3) && (param_3 == 0)) {
    *(undefined4 *)(param_5 + 4) = 0;
    *param_5 = 3;
  }
  else {
    *param_5 = 3;
    *(undefined4 *)(param_5 + 4) = 0x300000;
    if (*(int **)(in_ECX + 0x404) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x404) + 0xbc);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        *(uint *)(param_5 + 4) = *(uint *)(param_5 + 4) | 6;
      }
      iVar3 = *(int *)(in_ECX + 0x404);
      if ((*(int *)(iVar3 + 0x5c) == 0) || (*(int *)(iVar3 + 0x6c) != 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((*(int *)(iVar3 + 100) == 0) || (bVar2)) {
        *(uint *)(param_5 + 4) = *(uint *)(param_5 + 4) | 0x40;
      }
    }
  }
  return 0;
}




/* vtable slots: CMFCPropertyGridCtrl[42] */
/* 007e07de  FUN_007e07de  127 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_007e07de(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int *piVar1;
  code *pcVar2;
  BSTR pOVar3;
  undefined4 uVar4;
  int in_ECX;
  OLECHAR *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7e07ea;
  if ((((param_1 == 3) && (param_3 == 0)) ||
      (piVar1 = *(int **)(in_ECX + 0x404), piVar1 == (int *)0x0)) ||
     ((piVar1[0x17] != 0 && (piVar1[0x1b] == 0)))) {
    uVar4 = 1;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x24);
    guard_check_icall(local_14);
    (*pcVar2)();
    local_8 = 0;
    pOVar3 = SysAllocStringLen(local_14[0],*(UINT *)(local_14[0] + -6));
    if (pOVar3 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00407010();
    }
    *param_5 = pOVar3;
    FUN_00406b10();
    uVar4 = 0;
  }
  return uVar4;
}



