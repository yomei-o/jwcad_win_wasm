/* CDialogBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDialogBar[90], CDockBar[90], CMyStatusBar[90], CStatusBar[90] */
/* 007abebb  FUN_007abebb  52 bytes, 0 callers */

undefined4 FUN_007abebb(undefined4 param_1,undefined4 param_2,uint param_3)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall(param_1,param_3 & 1,param_3 & 2);
  (*pcVar1)();
  return param_1;
}




/* vtable slots: CDialogBar[92], CDockBar[92], CLayerControlBar[92], CMyCtrlBar[92], CMyToolBar[92], CSenCollControlBar[92], CSenCollControlBar2[92], CToolBar[92] */
/* 007abf22  FUN_007abf22  215 bytes, 3 callers */

void FUN_007abf22(int *param_1,int param_2)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  
  uVar1 = *(uint *)(in_ECX + 0xb0);
  if ((uVar1 & 0x100) != 0) {
    *param_1 = *param_1 + DAT_00a12218;
  }
  if ((uVar1 & 0x200) != 0) {
    param_1[1] = param_1[1] + DAT_00a1221c;
  }
  if ((uVar1 & 0x400) != 0) {
    param_1[2] = param_1[2] - DAT_00a12218;
  }
  if ((uVar1 & 0x800) != 0) {
    param_1[3] = param_1[3] - DAT_00a1221c;
  }
  if (param_2 == 0) {
    *param_1 = *param_1 + *(int *)(in_ECX + 0x90);
    iVar2 = *(int *)(in_ECX + 0x88) + param_1[1];
    param_1[1] = iVar2;
    param_1[2] = param_1[2] - *(int *)(in_ECX + 0x94);
    param_1[3] = param_1[3] - *(int *)(in_ECX + 0x8c);
    if ((*(uint *)(in_ECX + 0xb0) & 0x400001) == 0x400000) {
      param_1[1] = iVar2 + 7;
    }
  }
  else {
    iVar2 = *(int *)(in_ECX + 0x88) + *param_1;
    *param_1 = iVar2;
    param_1[1] = param_1[1] + *(int *)(in_ECX + 0x90);
    param_1[2] = param_1[2] - *(int *)(in_ECX + 0x8c);
    param_1[3] = param_1[3] - *(int *)(in_ECX + 0x94);
    if ((*(uint *)(in_ECX + 0xb0) & 0x400001) == 0x400000) {
      *param_1 = iVar2 + 7;
    }
  }
  return;
}




/* vtable slots: CDialogBar[99], CDockBar[99], CLayerControlBar[99], CMyCtrlBar[99], CMyStatusBar[99], CMyToolBar[99], CSenCollControlBar[99], CSenCollControlBar2[99], CStatusBar[99], CToolBar[99] */
/* 007abff9  DelayShow  59 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CControlBar::DelayShow(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CControlBar::DelayShow(CControlBar *this,int param_1)

{
  uint uVar1;
  
  *(uint *)(this + 0xac) = *(uint *)(this + 0xac) & 0xfffffffc;
  uVar1 = FUN_00797b3d();
  if (param_1 == 0) {
    if ((uVar1 & 0x10000000) != 0) {
      *(uint *)(this + 0xac) = *(uint *)(this + 0xac) | 1;
    }
  }
  else if ((uVar1 & 0x10000000) == 0) {
    *(uint *)(this + 0xac) = *(uint *)(this + 0xac) | 2;
  }
  return;
}




/* vtable slots: CDialogBar[24], CDockBar[24], CLayerControlBar[24], CMyCtrlBar[24], CMyStatusBar[24], CMyToolBar[24], CSenCollControlBar[24], CSenCollControlBar2[24], CStatusBar[24], CToolBar[24] */
/* 007ac034  FUN_007ac034  56 bytes, 2 callers */

void FUN_007ac034(void)

{
  code *pcVar1;
  int iVar2;
  CFrameWnd *pCVar3;
  CControlBar *in_ECX;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    iVar2 = FUN_0079a105();
    if (iVar2 != 0) {
      pCVar3 = CControlBar::GetDockingFrame(in_ECX);
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x60);
      guard_check_icall();
      (*pcVar1)();
      return;
    }
  }
  FUN_00792313();
  return;
}




/* vtable slots: CDialogBar[93], CLayerControlBar[93], CMyCtrlBar[93], CMyStatusBar[93], CMyToolBar[93], CSenCollControlBar[93], CSenCollControlBar2[93], CStatusBar[93], CToolBar[93] */
/* 007ac06c  FUN_007ac06c  118 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007ac06c(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect((HWND)in_ECX[8],&local_18);
  pcVar1 = *(code **)(*in_ECX + 0x178);
  guard_check_icall(param_1,&local_18);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x17c);
  guard_check_icall(param_1,&local_18);
  (*pcVar1)();
  return;
}




/* vtable slots: CDialogBar[94], CDockBar[94], CLayerControlBar[94], CMyCtrlBar[94], CMyStatusBar[94], CMyToolBar[94], CSenCollControlBar[94], CSenCollControlBar2[94], CStatusBar[94], CToolBar[94] */
/* 007ac0e2  FUN_007ac0e2  642 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007ac0e2(int param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  BOOL BVar5;
  HRESULT HVar6;
  COLORREF CVar7;
  uint uVar8;
  int in_ECX;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int local_3c;
  int local_24;
  RECT local_18;
  uint local_8;
  
  uVar3 = DAT_00a12234;
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar2 = *(uint *)(in_ECX + 0xb0);
  if ((uVar2 & 0xf00) == 0) {
    return;
  }
  local_18.left = *param_2;
  local_18.top = param_2[1];
  local_18.right = param_2[2];
  local_18.bottom = param_2[3];
  iVar12 = param_2[1];
  local_24 = param_2[3];
  iVar9 = local_18.right;
  local_3c = local_18.bottom;
  if ((uVar2 & 0x80) != 0) {
    iVar9 = local_18.right + -1;
    local_3c = local_18.bottom + -1;
  }
  uVar10 = uVar2 & 0x200;
  if (uVar10 != 0) {
    iVar12 = iVar12 + DAT_00a1221c;
  }
  uVar11 = uVar2 & 0x800;
  if (uVar11 != 0) {
    local_24 = local_24 - DAT_00a1221c;
  }
  iVar4 = FUN_0079d98a(&PTR_s_CToolBar_0097fbd4);
  if ((iVar4 != 0) && (uVar11 != 0)) {
    local_18.right = param_2[2];
    local_18.left = 0;
    local_18.top = param_2[1];
    local_18.bottom = param_2[3];
    if (*(HTHEME *)(in_ECX + 0xa8) != (HTHEME)0x0) {
      BVar5 = IsThemeBackgroundPartiallyTransparent(*(HTHEME *)(in_ECX + 0xa8),6,0);
      if (BVar5 != 0) {
        DrawThemeParentBackground(*(HWND *)(in_ECX + 0x20),*(HDC *)(param_1 + 4),&local_18);
      }
      HVar6 = DrawThemeBackground(*(HTHEME *)(in_ECX + 0xa8),*(HDC *)(param_1 + 4),6,0,&local_18,
                                  (LPCRECT)0x0);
      if (-1 < HVar6) goto LAB_007ac22f;
    }
    CVar7 = GetBkColor(*(HDC *)(param_1 + 8));
    FUN_007a506d(&local_18,CVar7);
  }
LAB_007ac22f:
  uVar8 = uVar2 & 0x100;
  if (uVar8 != 0) {
    FUN_007a500d(0,iVar12,1,local_24 - iVar12,uVar3);
  }
  if (uVar10 != 0) {
    FUN_007a500d(0,0,param_2[2],1,uVar3);
  }
  uVar1 = uVar2 & 0x400;
  if (uVar1 != 0) {
    FUN_007a500d(iVar9,iVar12,0xffffffff,local_24 - iVar12,uVar3);
  }
  if (uVar11 != 0) {
    FUN_007a500d(0,local_3c,param_2[2],0xffffffff,uVar3);
  }
  uVar3 = DAT_00a12238;
  if ((uVar2 & 0x80) != 0) {
    if (uVar8 != 0) {
      FUN_007a500d(1,iVar12,1,local_24 - iVar12,DAT_00a12238);
    }
    if (uVar10 != 0) {
      FUN_007a500d(0,1,param_2[2],1,uVar3);
    }
    if (uVar1 != 0) {
      FUN_007a500d(param_2[2],iVar12,0xffffffff,local_24 - iVar12,uVar3);
    }
    if (uVar11 != 0) {
      FUN_007a500d(0,param_2[3],param_2[2],0xffffffff,uVar3);
    }
  }
  if (uVar8 != 0) {
    *param_2 = *param_2 + DAT_00a12218;
  }
  if (uVar10 != 0) {
    param_2[1] = param_2[1] + DAT_00a1221c;
  }
  if (uVar1 != 0) {
    param_2[2] = param_2[2] - DAT_00a12218;
  }
  if (uVar11 != 0) {
    param_2[3] = param_2[3] - DAT_00a1221c;
  }
  return;
}




/* vtable slots: CDialogBar[95], CDockBar[95], CLayerControlBar[95], CMyCtrlBar[95], CMyStatusBar[95], CMyToolBar[95], CSenCollControlBar[95], CSenCollControlBar2[95], CStatusBar[95], CToolBar[95] */
/* 007ac364  FUN_007ac364  100 bytes, 0 callers */

void FUN_007ac364(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((in_ECX[0x2c] & 0x400001U) == 0x400000) {
    pcVar1 = *(code **)(*in_ECX + 0x184);
    guard_check_icall(param_1,param_2,0);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x188);
      guard_check_icall(param_1,param_2);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CDialogBar[96], CDockBar[96], CLayerControlBar[96], CMyCtrlBar[96], CMyStatusBar[96], CMyToolBar[96], CSenCollControlBar[96], CSenCollControlBar2[96], CStatusBar[96], CToolBar[96] */
/* 007ac3c9  FUN_007ac3c9  100 bytes, 0 callers */

void FUN_007ac3c9(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((in_ECX[0x2c] & 0x400001U) == 0x400000) {
    pcVar1 = *(code **)(*in_ECX + 0x184);
    guard_check_icall(param_1,param_2,1);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x188);
      guard_check_icall(param_1,param_2);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CDialogBar[98], CDockBar[98], CLayerControlBar[98], CMyCtrlBar[98], CMyStatusBar[98], CMyToolBar[98], CSenCollControlBar[98], CSenCollControlBar2[98], CStatusBar[98], CToolBar[98] */
/* 007ac42e  FUN_007ac42e  160 bytes, 0 callers */

undefined4 FUN_007ac42e(int param_1,int *param_2)

{
  int in_ECX;
  
  if (param_1 != 0) {
    if ((*(uint *)(in_ECX + 0xb0) & 0xa000) == 0) {
      FUN_007a4cbf(*(int *)(in_ECX + 0x90) + *param_2,param_2[1] + 2,
                   ((param_2[2] - *(int *)(in_ECX + 0x94)) - *(int *)(in_ECX + 0x90)) - *param_2,3,
                   DAT_00a12238,DAT_00a12234);
    }
    else {
      FUN_007a4cbf(*param_2 + 2,param_2[1] + *(int *)(in_ECX + 0x90),3,
                   ((param_2[3] - *(int *)(in_ECX + 0x94)) - param_2[1]) - *(int *)(in_ECX + 0x90),
                   DAT_00a12238,DAT_00a12234);
    }
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CDialogBar[97], CDockBar[97], CLayerControlBar[97], CMyCtrlBar[97], CMyStatusBar[97], CMyToolBar[97], CSenCollControlBar[97], CSenCollControlBar2[97], CStatusBar[97], CToolBar[97] */
/* 007ac4cf  FUN_007ac4cf  470 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007ac4cf(int param_1,int *param_2,int param_3)

{
  HTHEME hTheme;
  HRESULT HVar1;
  int iVar2;
  CWnd *in_ECX;
  int local_50;
  RECT local_48;
  tagRECT local_38;
  RECT local_28;
  undefined1 local_18 [12];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  hTheme = *(HTHEME *)(in_ECX + 0xa8);
  if (hTheme != (HTHEME)0x0) {
    local_38.left = 0;
    local_38.top = 0;
    local_38.right = 0;
    local_38.bottom = 0;
    if (param_3 != 0) {
      GetClientRect(*(HWND *)(in_ECX + 0x20),&local_38);
      local_18._0_4_ = 0;
      local_18._4_4_ = 0;
      local_18._8_4_ = 0;
      local_c = 0;
      GetWindowRect(*(HWND *)(in_ECX + 0x20),(LPRECT)local_18);
      CWnd::ScreenToClient(in_ECX,(tagRECT *)local_18);
      OffsetRect(&local_38,-local_18._0_4_,-local_18._4_4_);
      hTheme = *(HTHEME *)(in_ECX + 0xa8);
    }
    if ((*(uint *)(in_ECX + 0xb0) & 0xa000) == 0) {
      local_50 = 1;
      HVar1 = GetThemePartSize(hTheme,*(HDC *)(param_1 + 4),1,0,(LPCRECT)0x0,TS_TRUE,
                               (SIZE *)(local_18 + 8));
      if (HVar1 < 0) {
        return 0;
      }
      local_48.top = param_2[1];
      local_28.top = local_48.top;
      if (param_3 != 0) {
        iVar2 = local_38.top - local_48.top;
        if (iVar2 < local_c) {
          iVar2 = iVar2 + -1;
        }
        local_28.top = (iVar2 - local_c) / 2 + local_48.top;
      }
      local_48.left = *(int *)(in_ECX + 0x90) + *param_2;
      local_48.right = param_2[2] - *(int *)(in_ECX + 0x94);
      local_28.bottom = local_28.top + local_c;
      local_48.bottom = local_38.top;
      local_28.left = local_48.left;
      local_28.right = local_48.right;
    }
    else {
      local_50 = 2;
      HVar1 = GetThemePartSize(hTheme,*(HDC *)(param_1 + 4),2,0,(LPCRECT)0x0,TS_TRUE,
                               (SIZE *)(local_18 + 8));
      if (HVar1 < 0) {
        return 0;
      }
      local_48.left = *param_2;
      local_28.left = local_48.left;
      if (param_3 != 0) {
        iVar2 = local_38.left - local_48.left;
        if (iVar2 < (int)local_18._8_4_) {
          iVar2 = iVar2 + -1;
        }
        local_28.left = (iVar2 - local_18._8_4_) / 2 + local_48.left;
      }
      local_28.right = local_28.left + local_18._8_4_;
      local_48.top = *(int *)(in_ECX + 0x90) + param_2[1];
      local_28.bottom = param_2[3] - *(int *)(in_ECX + 0x94);
      local_48.right = local_38.left;
      local_48.bottom = local_28.bottom;
      local_28.top = local_48.top;
    }
    HVar1 = DrawThemeBackground(*(HTHEME *)(in_ECX + 0xa8),*(HDC *)(param_1 + 4),local_50,0,
                                &local_28,&local_48);
    if (-1 < HVar1) {
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CDialogBar[100], CDockBar[100], CLayerControlBar[100], CMyCtrlBar[100], CMyStatusBar[100], CMyToolBar[100], CSenCollControlBar[100], CSenCollControlBar2[100], CStatusBar[100], CToolBar[100] */
/* 007ac79e  IsVisible  33 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CControlBar::IsVisible(void)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CControlBar::IsVisible(CControlBar *this)

{
  uint uVar1;
  
  if ((*(uint *)(this + 0xac) & 1) != 0) {
    return 0;
  }
  if (((*(uint *)(this + 0xac) & 2) == 0) && (uVar1 = FUN_00797b3d(), (uVar1 & 0x10000000) == 0)) {
    return 0;
  }
  return 1;
}




/* vtable slots: CDialogBar[72], CDockBar[72], CLayerControlBar[72], CMyCtrlBar[72], CMyStatusBar[72], CMyToolBar[72], CSenCollControlBar[72], CSenCollControlBar2[72], CStatusBar[72], CToolBar[72] */
/* 007ad051  FUN_007ad051  35 bytes, 0 callers */

void FUN_007ad051(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX[0x21] != 0) {
    pcVar1 = *(code **)(*in_ECX + 4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CDialogBar[25], CDockBar[25], CLayerControlBar[25], CMyCtrlBar[25], CMyToolBar[25], CSenCollControlBar[25], CSenCollControlBar2[25], CToolBar[25] */
/* 007ad074  FUN_007ad074  114 bytes, 1 callers */

undefined4 FUN_007ad074(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  iVar2 = PreCreateWindow(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x4000000;
  uVar1 = *(uint *)(in_ECX + 0xb0);
  if ((char)uVar1 < '\0') {
    return 1;
  }
  uVar3 = uVar1 & 0xff00;
  if (uVar3 != 0x1400) {
    if (uVar3 == 0x2800) {
      uVar3 = 0x280;
      goto LAB_007ad0cf;
    }
    if (uVar3 != 0x4100) {
      if (uVar3 != 0x8200) {
        return 1;
      }
      uVar3 = 0x880;
      goto LAB_007ad0cf;
    }
  }
  uVar3 = 0xa80;
LAB_007ad0cf:
  *(uint *)(in_ECX + 0xb0) = uVar1 & 0xfffff0ff | uVar3;
  return 1;
}




/* vtable slots: CDialogBar[67], CDockBar[67], CMyCtrlBar[67], CMyStatusBar[67], CMyToolBar[67], CSenCollControlBar[67], CSenCollControlBar2[67], CStatusBar[67], CToolBar[67] */
/* 007ad0e6  FUN_007ad0e6  584 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007ad0e6(int param_1)

{
  uint uVar1;
  code *pcVar2;
  SHORT SVar3;
  int iVar4;
  CWnd *pCVar5;
  BOOL BVar6;
  undefined4 uVar7;
  CWnd *in_ECX;
  AFX_MODULE_THREAD_STATE *pAVar8;
  tagPOINT local_50;
  int local_48;
  int local_44;
  int local_40;
  AFX_MODULE_THREAD_STATE *local_3c;
  undefined4 local_38;
  uint local_34;
  int local_14;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_48 = param_1;
  iVar4 = FUN_007949fb(param_1);
  if (iVar4 != 0) {
    return 1;
  }
  uVar1 = *(uint *)(param_1 + 4);
  pCVar5 = CWnd::GetOwner(in_ECX);
  if (((byte)in_ECX[0xb0] & 0x20) == 0) {
    if (uVar1 != 0x201) {
      if (uVar1 != 0x202) goto LAB_007ad2bc;
      goto LAB_007ad139;
    }
  }
  else {
LAB_007ad139:
    if (((uVar1 < 0x200) || (0x209 < uVar1)) && (9 < uVar1 - 0xa0)) goto LAB_007ad2bc;
  }
  local_3c = AfxGetModuleThreadState();
  local_50.y = *(LONG *)(param_1 + 0x18);
  local_50.x = *(LONG *)(param_1 + 0x14);
  ScreenToClient(*(HWND *)(in_ECX + 0x20),&local_50);
  _memset(&local_38,0,0x2c);
  local_38 = 0x30;
  pcVar2 = *(code **)(*(int *)in_ECX + 0x74);
  guard_check_icall(local_50.x,local_50.y,&local_38);
  iVar4 = (*pcVar2)();
  local_44 = iVar4;
  if (local_14 != -1) {
    FUN_008f43b0(local_14);
  }
  if ((uVar1 == 0x201) && ((local_34 & 0x80000000) != 0)) {
    local_40 = 1;
  }
  else {
    local_40 = 0;
    if ((uVar1 != 0x201) && (SVar3 = GetKeyState(1), SVar3 < 0)) {
      iVar4 = *(int *)(local_3c + 0x4c);
      local_44 = iVar4;
    }
  }
  if ((iVar4 < 0) || (local_40 != 0)) {
    SVar3 = GetKeyState(1);
    if ((-1 < SVar3) || (pAVar8 = local_3c, local_40 != 0)) {
      pcVar2 = *(code **)(*(int *)in_ECX + 0x1a0);
      guard_check_icall(0xffffffff);
      (*pcVar2)();
      KillTimer(*(HWND *)(in_ECX + 0x20),0xec0a);
      pAVar8 = local_3c;
      iVar4 = local_44;
    }
  }
  else if (uVar1 == 0x202) {
    pcVar2 = *(code **)(*(int *)in_ECX + 0x1a0);
    guard_check_icall(0xffffffff);
    (*pcVar2)();
    CControlBar::ResetTimer((CControlBar *)in_ECX,0xec0a,200);
    pAVar8 = local_3c;
    iVar4 = local_44;
  }
  else if ((((byte)in_ECX[0xac] & 8) == 0) &&
          (SVar3 = GetKeyState(1), pAVar8 = local_3c, -1 < SVar3)) {
    if (iVar4 != *(int *)(local_3c + 0x4c)) {
      CControlBar::ResetTimer((CControlBar *)in_ECX,0xec09,300);
    }
  }
  else {
    pcVar2 = *(code **)(*(int *)in_ECX + 0x1a0);
    guard_check_icall(iVar4);
    (*pcVar2)();
    pAVar8 = local_3c;
    iVar4 = local_44;
  }
  *(int *)(pAVar8 + 0x4c) = iVar4;
LAB_007ad2bc:
  iVar4 = FUN_00792b4c();
  if ((iVar4 == 0) || (*(int *)(iVar4 + 0x94) == 0)) {
    while (pCVar5 != (CWnd *)0x0) {
      pcVar2 = *(code **)(*(int *)pCVar5 + 0x10c);
      guard_check_icall(local_48);
      iVar4 = (*pcVar2)();
      if (iVar4 != 0) {
        return 1;
      }
      pCVar5 = (CWnd *)FUN_0079296c();
    }
    BVar6 = IsWindow(*(HWND *)(in_ECX + 0x20));
    if (BVar6 != 0) {
      uVar7 = FUN_007949cc(local_48);
      return uVar7;
    }
  }
  return 0;
}




/* vtable slots: CDialogBar[101], CDockBar[101], CLayerControlBar[101], CMyCtrlBar[101], CMyStatusBar[101], CMyToolBar[101], CSenCollControlBar[101], CSenCollControlBar2[101], CStatusBar[101], CToolBar[101] */
/* 007ad32e  FUN_007ad32e  154 bytes, 0 callers */

uint FUN_007ad32e(int *param_1)

{
  uint uVar1;
  uint uVar2;
  HDWP pvVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  uVar2 = FUN_00797b3d();
  uVar2 = uVar2 & 0x10000000;
  uVar5 = *(uint *)(in_ECX + 0xb0) & 0xff00 | uVar2;
  uVar1 = *(uint *)(in_ECX + 0xac);
  if ((uVar1 & 3) == 0) {
    return uVar5;
  }
  if ((uVar1 & 1) == 0) {
    if (uVar2 == 0) {
      uVar4 = 0x40;
      goto LAB_007ad396;
    }
  }
  else {
    uVar4 = -(uint)(uVar2 != 0) & 0x80;
    if (uVar2 != 0) {
LAB_007ad396:
      if (*param_1 == 0) {
        return uVar5 ^ 0x10000000;
      }
      *(uint *)(in_ECX + 0xac) = uVar1 & 0xfffffffc;
      pvVar3 = DeferWindowPos((HDWP)*param_1,*(HWND *)(in_ECX + 0x20),(HWND)0x0,0,0,0,0,uVar4 | 0x17
                             );
      *param_1 = (int)pvVar3;
      return uVar5 ^ 0x10000000;
    }
  }
  *(uint *)(in_ECX + 0xac) = uVar1 & 0xfffffffc;
  return uVar5;
}




/* vtable slots: CDialogBar[104], CDockBar[104], CLayerControlBar[104], CMyCtrlBar[104], CMyStatusBar[104], CMyToolBar[104], CSenCollControlBar[104], CSenCollControlBar2[104], CStatusBar[104], CToolBar[104] */
/* 007ad47d  SetStatusText  157 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CControlBar::SetStatusText(int)
   
   Library: Visual Studio 2015 Release */

int __thiscall CControlBar::SetStatusText(CControlBar *this,int param_1)

{
  CWnd *pCVar1;
  AFX_MODULE_THREAD_STATE *pAVar2;
  
  pCVar1 = CWnd::GetOwner((CWnd *)this);
  pAVar2 = AfxGetModuleThreadState();
  if (param_1 == -1) {
    *(undefined4 *)(pAVar2 + 0x50) = 0;
    if (((byte)this[0xac] & 8) == 0) {
      KillTimer(*(HWND *)(this + 0x20),0xec09);
      return 0;
    }
    SendMessageW(*(HWND *)(pCVar1 + 0x20),0x375,0xe001,0);
    *(uint *)(this + 0xac) = *(uint *)(this + 0xac) & 0xfffffff7;
  }
  else {
    if ((((byte)this[0xac] & 8) != 0) && (*(int *)(pAVar2 + 0x4c) == param_1)) {
      return 0;
    }
    *(CControlBar **)(pAVar2 + 0x50) = this;
    SendMessageW(*(HWND *)(pCVar1 + 0x20),0x362,param_1,0);
    *(uint *)(this + 0xac) = *(uint *)(this + 0xac) | 8;
    ResetTimer(this,0xec0a,200);
  }
  return 1;
}




/* vtable slots: CDialogBar[69], CDockBar[69], CLayerControlBar[69], CMyCtrlBar[69], CMyStatusBar[69], CMyToolBar[69], CSenCollControlBar[69], CSenCollControlBar2[69], CStatusBar[69], CToolBar[69] */
/* 007ad51a  FUN_007ad51a  269 bytes, 0 callers */

CWnd * FUN_007ad51a(uint param_1,WPARAM param_2,int param_3)

{
  code *pcVar1;
  CWnd *pCVar2;
  int iVar3;
  CWnd *in_ECX;
  bool bVar4;
  CWnd *local_c;
  CWnd *local_8;
  
  if (param_1 < 0x30) {
    if ((((param_1 != 0x2f) && (param_1 != 0x2b)) && (param_1 != 0x2c)) && (param_1 != 0x2d)) {
      bVar4 = param_1 == 0x2e;
LAB_007ad553:
      if (!bVar4) {
        pCVar2 = (CWnd *)FUN_007958aa(param_1,param_2,param_3);
        return pCVar2;
      }
    }
  }
  else if ((param_1 != 0x39) && (param_1 != 0x4e)) {
    bVar4 = param_1 == 0x111;
    goto LAB_007ad553;
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x118);
  local_c = in_ECX;
  local_8 = in_ECX;
  guard_check_icall(param_1,param_2,param_3,&local_c);
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    return local_c;
  }
  if ((*(int *)(local_8 + 0x80) != 0) && (param_1 == 0x111)) {
    pCVar2 = (CWnd *)SendMessageW(*(HWND *)(*(int *)(local_8 + 0x80) + 0x20),0x111,param_2,param_3);
    return pCVar2;
  }
  pCVar2 = CWnd::GetOwner(local_8);
  local_c = (CWnd *)SendMessageW(*(HWND *)(pCVar2 + 0x20),param_1,param_2,param_3);
  if (param_1 != 0x4e) {
    return local_c;
  }
  if (*(int *)(param_3 + 8) == -0x208) {
    if (*(int *)(param_3 + 0x60) != 0) {
      return local_c;
    }
    if (*(char **)(param_3 + 0xc) == (char *)0x0) goto LAB_007ad5fc;
    bVar4 = **(char **)(param_3 + 0xc) == '\0';
  }
  else {
    if (*(int *)(param_3 + 8) != -0x212) {
      return local_c;
    }
    if (*(int *)(param_3 + 0xb0) != 0) {
      return local_c;
    }
    if (*(short **)(param_3 + 0xc) == (short *)0x0) goto LAB_007ad5fc;
    bVar4 = **(short **)(param_3 + 0xc) == 0;
  }
  if (!bVar4) {
    return local_c;
  }
LAB_007ad5fc:
  pCVar2 = (CWnd *)FUN_007958aa(0x4e,param_2,param_3);
  return pCVar2;
}




/* vtable slots: CDialogBar[1] */
/* 007ce23d  FUN_007ce23d  51 bytes, 0 callers */

void FUN_007ce23d(byte param_1)

{
  ExternalContextBase *in_ECX;
  
  Concurrency::details::ExternalContextBase::~ExternalContextBase(in_ECX);
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




/* vtable slots: CDialogBar[89] */
/* 007ce270  FUN_007ce270  75 bytes, 0 callers */

void FUN_007ce270(undefined4 *param_1,int param_2,int param_3)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar1 = *(undefined4 *)(in_ECX + 200);
    param_1[1] = *(undefined4 *)(in_ECX + 0xcc);
  }
  else {
    if (param_3 == 0) {
      uVar1 = *(undefined4 *)(in_ECX + 200);
      uVar2 = 0x7fff;
    }
    else {
      uVar2 = *(undefined4 *)(in_ECX + 0xcc);
      uVar1 = 0x7fff;
    }
    param_1[1] = uVar2;
  }
  *param_1 = uVar1;
  return;
}




/* vtable slots: CDialogBar[105] */
/* 007ce2bb  FUN_007ce2bb  47 bytes, 0 callers */

void FUN_007ce2bb(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall(param_1,param_2,param_3,param_4);
  (*pcVar1)();
  return;
}




/* vtable slots: CDialogBar[106] */
/* 007ce2ea  FUN_007ce2ea  315 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007ce2ea(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  undefined1 local_50 [4];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = param_2;
  local_1c = param_4;
  in_ECX[0x2c] = param_3 & 0x40ffff;
  _memset(local_50,0,0x30);
  local_30 = param_3 | 0x40000000;
  local_28 = L"AfxControlBar140su";
  local_48 = local_1c;
  iVar2 = FUN_0079dd6d();
  local_4c = *(undefined4 *)(iVar2 + 8);
  if (param_1 == 0) {
    local_44 = 0;
  }
  else {
    local_44 = *(undefined4 *)(param_1 + 0x20);
  }
  pcVar1 = *(code **)(*in_ECX + 100);
  guard_check_icall(local_50);
  iVar3 = (*pcVar1)();
  iVar2 = local_20;
  if (iVar3 != 0) {
    in_ECX[0x35] = local_20;
    FUN_00790c5e(0x10);
    FUN_00790c5e(0xfc000);
    iVar3 = FUN_007981f2(iVar2,param_1);
    in_ECX[0x35] = 0;
    if (iVar3 != 0) {
      FUN_00797d82(local_1c);
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect((HWND)in_ECX[8],&local_18);
      in_ECX[0x32] = local_18.right - local_18.left;
      in_ECX[0x33] = local_18.bottom - local_18.top;
      FUN_00797c5d(0,0x4000000,0);
      iVar2 = FUN_00792670(iVar2);
      if (iVar2 != 0) {
        FUN_00797e71(0,0,0,0,0,0x54);
        return 1;
      }
    }
  }
  return 0;
}




/* vtable slots: CDialogBar[10] */
/* 007ce425  FUN_007ce425  6 bytes, 0 callers */

undefined ** FUN_007ce425(void)

{
  return &PTR_LAB_00986000;
}




/* vtable slots: CDialogBar[0] */
/* 007ce42b  FUN_007ce42b  6 bytes, 0 callers */

undefined ** FUN_007ce42b(void)

{
  return &PTR_s_CDialogBar_00985e04;
}




/* vtable slots: CDialogBar[91] */
/* 007ce483  FUN_007ce483  9 bytes, 0 callers */

void FUN_007ce483(CCmdTarget *param_1,int param_2)

{
  CWnd *in_ECX;
  
  CWnd::UpdateDialogControls(in_ECX,param_1,param_2);
  return;
}




/* vtable slots: CDialogBar[87] */
/* 007ce48c  FUN_007ce48c  19 bytes, 0 callers */

undefined4 FUN_007ce48c(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xd0) = param_1;
  return 1;
}



