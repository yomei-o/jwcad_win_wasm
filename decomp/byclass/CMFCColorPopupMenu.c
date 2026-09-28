/* CMFCColorPopupMenu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCColorPopupMenu[112], CMFCDropDownFrame[112], CMFCPopupMenu[112], CMFCRibbonMiniToolBar[112], CMFCRibbonPanelMenu[112], CMFCShadowWnd[112], CMiniDockFrameWnd[112], CMiniFrameWnd[112] */
/* 007d103c  Create  32 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual int __thiscall CMiniFrameWnd::Create(char const *,char const *,unsigned
   long,struct tagRECT const &,class CWnd *,unsigned int)
    public: virtual int __thiscall CMiniFrameWnd::Create(wchar_t const *,wchar_t const *,unsigned
   long,struct tagRECT const &,class CWnd *,unsigned int)
   
   Library: Visual Studio */

void Create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6)

{
  FUN_007d105c(0,param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CMFCColorPopupMenu[113], CMFCDropDownFrame[113], CMFCPopupMenu[113], CMFCRibbonMiniToolBar[113], CMFCRibbonPanelMenu[113], CMFCShadowWnd[113], CMiniDockFrameWnd[113], CMiniFrameWnd[113] */
/* 007d105c  FUN_007d105c  155 bytes, 5 callers */

void FUN_007d105c(undefined4 param_1,int param_2,wchar_t *param_3,undefined4 param_4,int *param_5,
                 int param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HCURSOR pHVar5;
  int in_ECX;
  undefined4 uVar6;
  int iVar7;
  
  if (param_3 == (wchar_t *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_008f899d(param_3);
  }
  ATL::CSimpleStringT<wchar_t,0>::SetString
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 300),param_3,iVar4);
  if (param_6 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(param_6 + 0x20);
  }
  iVar4 = param_5[1];
  iVar1 = param_5[3];
  iVar2 = *param_5;
  iVar3 = param_5[2];
  if (param_2 == 0) {
    iVar7 = param_2;
    pHVar5 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    param_2 = AfxRegisterWndClass(8,pHVar5,param_2,iVar7);
  }
  FUN_00792137(param_1,param_2,param_3,param_4,iVar2,iVar4,iVar3 - iVar2,iVar1 - iVar4,uVar6,param_7
               ,0);
  return;
}




/* vtable slots: CMFCColorPopupMenu[25], CMFCDropDownFrame[25], CMFCPopupMenu[25], CMFCRibbonMiniToolBar[25], CMFCRibbonPanelMenu[25], CMFCShadowWnd[25], CMiniDockFrameWnd[25], CMiniFrameWnd[25] */
/* 007d14c3  FUN_007d14c3  60 bytes, 0 callers */

undefined4 FUN_007d14c3(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if ((uVar1 & 0x600) != 0) {
    uVar1 = uVar1 | 0x40000;
    *(uint *)(param_1 + 0x20) = uVar1;
  }
  if ((uVar1 & 0xc00000) != 0) {
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x80;
  }
  PreCreateWindow(param_1);
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffdff;
  return 1;
}




/* vtable slots: CMFCColorPopupMenu[1] */
/* 007d5d42  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCColorPopupMenu::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCColorPopupMenu::_scalar_deleting_destructor_(CMFCColorPopupMenu *this,uint param_1)

{
  FUN_00824cc4();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1fe8);
    }
  }
  return this;
}




/* vtable slots: CMFCColorPopupMenu[114], CMFCRibbonMiniToolBar[114], CMFCRibbonPanelMenu[114] */
/* 007d5e8f  FUN_007d5e8f  7 bytes, 0 callers */

int FUN_007d5e8f(void)

{
  int in_ECX;
  
  return in_ECX + 0x1178;
}




/* vtable slots: CMFCColorPopupMenu[115], CMFCPopupMenu[115], CMFCRibbonMiniToolBar[115], CMFCRibbonPanelMenu[115] */
/* 007d5ea2  FUN_007d5ea2  38 bytes, 0 callers */

undefined4 FUN_007d5ea2(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1c8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    return 0;
  }
  return *(undefined4 *)(iVar2 + 0xd6c);
}




/* vtable slots: CMFCColorPopupMenu[116], CMFCPopupMenu[116], CMFCRibbonMiniToolBar[116], CMFCRibbonPanelMenu[116] */
/* 007d5ef8  FUN_007d5ef8  20 bytes, 0 callers */

undefined4 FUN_007d5ef8(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0xf74) != 0) && (*(int *)(in_ECX + 0xfa4) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCColorPopupMenu[132], CMFCPopupMenu[132], CMFCRibbonMiniToolBar[132], CMFCRibbonPanelMenu[132] */
/* 0081c1a6  FUN_0081c1a6  906 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0081c1a6(CWnd *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  bool bVar2;
  HCURSOR pHVar3;
  uint uVar4;
  ANIMATION_TYPE AVar5;
  int iVar6;
  CWnd *pCVar7;
  int iVar8;
  int *piVar9;
  BOOL BVar10;
  int *in_ECX;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_40;
  CWnd *local_38;
  tagRECT local_34;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x81c1b2;
  FUN_00886f80(2);
  if (param_1 == (CWnd *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  uVar12 = 0;
  uVar11 = 0x10;
  pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  uVar11 = AfxRegisterWndClass(0x800,pHVar3,uVar11,uVar12);
  CStringT<>(uVar11);
  local_8 = 0;
  in_ECX[0x3cd] = param_4;
  if ((param_2 == -1) && (param_3 == -1)) {
    local_34.left = 0;
    local_34.top = 0;
    local_34.right = 0;
    local_34.bottom = 0;
    GetClientRect(*(HWND *)(param_1 + 0x20),&local_34);
    FUN_0079e8b8(&local_34);
    in_ECX[0x4e] = local_34.left + 5;
    in_ECX[0x4f] = local_34.top + 5;
  }
  else {
    in_ECX[0x4e] = param_2;
    in_ECX[0x4f] = param_3;
  }
  in_ECX[0x50] = in_ECX[0x4e];
  iVar8 = in_ECX[0x55];
  in_ECX[0x51] = in_ECX[0x4f];
  if ((*(int *)(param_1 + 0x20) != 0) && (uVar4 = FUN_00797acc(), (uVar4 & 0x400000) != 0)) {
    in_ECX[0x3de] = 1;
  }
  if (in_ECX[0x3de] != 0) {
    in_ECX[0x3dd] = 1;
  }
  AVar5 = CMFCPopupMenu::GetAnimationType(0);
  if (((AVar5 == 0) || (DAT_00a127ac != 0)) || (in_ECX[0x3de] != 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  iVar6 = FUN_0081d529();
  if (iVar6 != 0) {
    in_ECX[0x3cf] = *(int *)(iVar6 + 0xf3c);
  }
  if (param_6 == 0) {
    if (iVar6 != 0) {
      in_ECX[0x4d] = *(int *)(iVar6 + 0x134);
    }
  }
  else {
    in_ECX[0x4d] = (int)param_1;
  }
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_2;
  local_18 = param_3;
  pCVar7 = CWnd::GetOwner(param_1);
  if (pCVar7 == (CWnd *)0x0) {
    local_38 = param_1;
  }
  else {
    local_38 = CWnd::GetOwner(param_1);
  }
  iVar6 = in_ECX[0x54];
  uVar4 = FUN_00797acc();
  iVar8 = FUN_007d105c(uVar4 & 0x400000,local_40,iVar6,(-(uint)(iVar8 != 0) & 0xc80000) + 0x80000000
                       ,&local_24,local_38,0);
  if (iVar8 == 0) {
    FUN_00406b10();
    goto LAB_0081c523;
  }
  if (in_ECX[0x3d1] != 0) {
    in_ECX[0x51] = in_ECX[0x4f];
    in_ECX[0x4e] = in_ECX[0x4e] + (1 - in_ECX[0x52]);
    in_ECX[0x50] = in_ECX[0x4e];
    pcVar1 = *(code **)(*in_ECX + 0x178);
    guard_check_icall(1);
    (*pcVar1)();
  }
  pcVar1 = *(code **)(*in_ECX + 0x1c8);
  guard_check_icall();
  piVar9 = (int *)(*pcVar1)();
  piVar9[0x2de] = param_5;
  piVar9[0x360] = in_ECX[0x3e0];
  if (bVar2) {
    in_ECX[0x3d9] = in_ECX[0x52] + in_ECX[0x417];
    in_ECX[0x3da] = in_ECX[0x53] + in_ECX[0x417];
    AVar5 = CMFCPopupMenu::GetAnimationType(0);
    if (AVar5 == 1) {
      pcVar1 = *(code **)(*piVar9 + 0x358);
      guard_check_icall();
      iVar8 = (*pcVar1)();
      in_ECX[0x3d9] = iVar8;
LAB_0081c454:
      pcVar1 = *(code **)(*piVar9 + 0x354);
      guard_check_icall();
      iVar8 = (*pcVar1)();
      in_ECX[0x3da] = iVar8;
    }
    else if (AVar5 == 2) goto LAB_0081c454;
    BVar10 = IsWindowVisible((HWND)piVar9[8]);
    if (BVar10 != 0) {
      FUN_00797f20(0);
    }
    SetTimer((HWND)in_ECX[8],0xec15,DAT_00a007b4,(TIMERPROC)0x0);
    _DAT_00a139e0 = _clock();
  }
  FUN_00821783(0);
  if (((in_ECX[0x417] == 0) && (AVar5 = CMFCPopupMenu::GetAnimationType(0), AVar5 == 3)) && (bVar2))
  {
    in_ECX[0x3d9] = in_ECX[0x52];
    in_ECX[0x3da] = in_ECX[0x53];
  }
  FUN_00797e71(&DAT_00a11c68,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x53);
  if (DAT_00a127ac != 0) {
    InvalidateRect((HWND)piVar9[8],(RECT *)0x0,1);
    UpdateWindow((HWND)piVar9[8]);
  }
  FUN_00406b10();
LAB_0081c523:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorPopupMenu[123], CMFCPopupMenu[123] */
/* 0081c9a2  FUN_0081c9a2  1453 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0081c9a2(CDC *param_1)

{
  int iVar1;
  CDC *pCVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  CObject *pCVar7;
  BOOL BVar8;
  undefined4 uVar9;
  int *in_ECX;
  code *pcVar10;
  HDC local_78;
  CDrawingManager local_68 [4];
  CObject *local_64;
  CDC *local_60;
  int *local_5c;
  int *local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x81c9ae;
  local_60 = param_1;
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  local_5c = in_ECX;
  GetClientRect((HWND)in_ECX[8],&local_24);
  if ((in_ECX[0x417] != 0) && (DAT_00a127ac == 0)) {
    uVar4 = FUN_00797acc();
    local_58 = (int *)(uVar4 & 0x400000);
    iVar5 = in_ECX[0x417];
    if (local_58 == (int *)0x0) {
      local_24.right = local_24.right - iVar5;
    }
    else {
      local_24.left = local_24.left + iVar5;
    }
    local_24.bottom = local_24.bottom - iVar5;
    local_44.left = 0;
    local_44.top = 0;
    local_44.right = 0;
    local_44.bottom = 0;
    SetRectEmpty(&local_44);
    if (in_ECX[0x56] != 0) {
      iVar5 = FUN_0081d529();
      if (iVar5 == 0) {
        iVar5 = in_ECX[0x56];
        iVar1 = *(int *)(iVar5 + 0x6c);
        if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
          local_44.left = *(LONG *)(iVar5 + 0x54);
          local_44.top = *(LONG *)(iVar5 + 0x58);
          local_44.right = *(int *)(iVar5 + 0x5c) + -1;
          local_44.bottom = *(int *)(iVar5 + 0x60) + -1;
          MapWindowPoints(*(HWND *)(iVar1 + 0x20),(HWND)local_5c[8],(LPPOINT)&local_44,2);
        }
      }
    }
    piVar6 = (int *)FUN_007c2574();
    pcVar10 = *(code **)(*piVar6 + 0x2f0);
    guard_check_icall();
    iVar5 = (*pcVar10)();
    if (iVar5 != 0) {
      iVar5 = FUN_0081d529();
      if (iVar5 != 0) {
        iVar1 = local_5c[0x56];
        if ((((iVar1 != 0) && (*(int *)(iVar1 + 0xb4) != 0)) && (*(int *)(iVar5 + 0x1160) != 0)) &&
           (((local_5c[0x458] == 0 && (local_5c[0x3cc] == 4)) &&
            ((iVar5 = *(int *)(iVar1 + 0x6c), iVar5 != 0 && (*(int *)(iVar5 + 0x20) != 0)))))) {
          local_44.left = *(LONG *)(iVar1 + 0x54);
          local_44.top = *(LONG *)(iVar1 + 0x58);
          local_44.right = *(int *)(iVar1 + 0x5c);
          local_44.bottom = *(int *)(iVar1 + 0x60) + 2;
          MapWindowPoints(*(HWND *)(iVar5 + 0x20),(HWND)local_5c[8],(LPPOINT)&local_44,2);
        }
      }
    }
    FUN_0079dea2(0);
    local_8 = 0;
    local_34.left = 0;
    local_34.top = 0;
    local_34.right = 0;
    local_34.bottom = 0;
    GetWindowRect((HWND)local_5c[8],&local_34);
    pCVar2 = local_60;
    BitBlt(*(HDC *)(local_60 + 4),0,0,local_34.right - local_34.left,local_34.bottom - local_34.top,
           local_78,local_34.left,local_34.top,0xcc0020);
    if (local_58 != (int *)0x0) {
      CDrawingManager::CDrawingManager(local_68,pCVar2);
      local_48 = local_34.bottom - local_34.top;
      local_4c = local_34.right - local_34.left;
      local_54 = 0;
      local_50 = 0;
      local_8._0_1_ = 1;
      FUN_008185f6(0,0,local_4c,local_48,1);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0081510b();
    }
    piVar6 = (int *)FUN_007c2574();
    pcVar10 = *(code **)(*piVar6 + 0x40);
    guard_check_icall(local_60,&local_24,&local_44,local_5c[0x417],100,0x41,local_5c + 0x41a,
                      local_5c + 0x418,local_58);
    (*pcVar10)();
    if (local_58 != (int *)0x0) {
      OffsetRect(&local_24,-local_5c[0x417],0);
    }
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  local_58 = (int *)FUN_007c2574();
  piVar6 = local_5c;
  pcVar10 = *(code **)(*local_58 + 0x3c);
  guard_check_icall(local_60,local_5c,local_24.left,local_24.top,local_24.right,local_24.bottom);
  (*pcVar10)();
  pcVar10 = *(code **)(*piVar6 + 0x20c);
  guard_check_icall();
  local_58 = (int *)(*pcVar10)();
  InflateRect(&local_24,-(int)local_58,-(int)local_58);
  piVar3 = local_5c;
  iVar5 = piVar6[0x3d6];
  if (iVar5 < 1) goto LAB_0081cd50;
  local_54 = local_24.left;
  local_50 = local_24.top;
  local_4c = local_24.right;
  local_48 = local_24.bottom;
  iVar1 = local_5c[0x3d8];
  if (iVar1 == 0) {
    local_4c = (int)local_58 + local_24.left + iVar5;
  }
  else if (iVar1 == 1) {
    local_54 = (local_24.right - iVar5) - (int)local_58;
  }
  else if (iVar1 == 2) {
    local_48 = local_24.top + iVar5 + (int)local_58;
  }
  else if (iVar1 == 3) {
    local_50 = (local_24.bottom - iVar5) - (int)local_58;
  }
  pCVar7 = DAT_00a13a1c;
  if (DAT_00a13a1c == (CObject *)0x0) {
    pCVar7 = (CObject *)FUN_00792b4c();
  }
  local_64 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar7);
  piVar6 = piVar3;
  if (local_64 == (CObject *)0x0) {
    local_64 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWndEx_00994040,pCVar7);
    if (local_64 == (CObject *)0x0) {
      local_64 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleIPFrameWndEx_00994be0,pCVar7);
      if (local_64 == (CObject *)0x0) {
        local_64 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleDocIPFrameWndEx_00994f98,pCVar7);
        if (local_64 == (CObject *)0x0) goto LAB_0081cd50;
      }
      goto LAB_0081cd33;
    }
    pcVar10 = *(code **)(*(int *)local_64 + 0x1e8);
  }
  else {
LAB_0081cd33:
    pcVar10 = *(code **)(*(int *)local_64 + 0x204);
  }
  guard_check_icall(local_60,piVar3,&local_54);
  (*pcVar10)();
LAB_0081cd50:
  BVar8 = IsRectEmpty((RECT *)(piVar6 + 0x41f));
  if (BVar8 == 0) {
    local_64 = (CObject *)FUN_007c2574();
    pcVar10 = *(code **)(*(int *)local_64 + 0x78);
    guard_check_icall(local_60,((RECT *)(piVar6 + 0x41f))->left,piVar6[0x420],piVar6[0x421],
                      piVar6[0x422],piVar6[0x41e]);
    (*pcVar10)();
    piVar6 = local_5c;
  }
  if (piVar6[0x3df] != 0) {
    pcVar10 = *(code **)(*piVar6 + 0x1e4);
    guard_check_icall();
    iVar5 = (*pcVar10)();
    if (iVar5 != 0) {
      local_64 = (CObject *)FUN_007c2574();
      pcVar10 = *(code **)(*(int *)local_64 + 0x80);
      guard_check_icall(local_60,piVar6[0x3e1],piVar6[0x3e2],piVar6[0x3e3],piVar6[0x3e4],0,
                        (uint)piVar6[0x3e9] >> 0x1f,0,0);
      (*pcVar10)();
      piVar6 = local_5c;
    }
    pcVar10 = *(code **)(*piVar6 + 0x1e8);
    guard_check_icall();
    iVar5 = (*pcVar10)();
    if (iVar5 != 0) {
      pcVar10 = *(code **)(*piVar6 + 0x1c8);
      guard_check_icall();
      iVar5 = (*pcVar10)();
      piVar3 = local_5c;
      if (iVar5 != 0) {
        local_34.left = local_24.left;
        local_34.right = local_24.right;
        local_34.bottom = local_5c[0x3e6];
        local_34.top = (local_34.bottom - (int)local_58) + -1;
        local_58 = (int *)FUN_007c2574();
        local_64 = *(CObject **)(*local_58 + 0x34);
        pcVar10 = *(code **)(*piVar3 + 0x1c8);
        guard_check_icall();
        uVar9 = (*pcVar10)();
        pCVar7 = local_64;
        guard_check_icall(local_60,uVar9,local_34.left,local_34.top,local_34.right,local_34.bottom,
                          local_34.left,local_34.top,local_34.right,local_34.bottom,0);
        (*(code *)pCVar7)();
        piVar6 = local_5c;
      }
      local_64 = (CObject *)FUN_007c2574();
      pcVar10 = *(code **)(*(int *)local_64 + 0x80);
      guard_check_icall(local_60,piVar6[0x3e5],piVar6[0x3e6],piVar6[999],piVar6[1000],1,
                        0 < piVar6[0x3e9],0,0);
      (*pcVar10)();
      piVar6 = local_5c;
    }
  }
  BVar8 = IsRectEmpty((RECT *)(piVar6 + 0x454));
  if (BVar8 == 0) {
    if (piVar6[0x44e] == 0) {
      local_58 = (int *)(uint)(0 < piVar6[0x450]);
    }
    else {
      local_58 = (int *)((0 < piVar6[0x450]) + 2);
    }
    local_64 = (CObject *)FUN_007c2574();
    pcVar10 = *(code **)(*(int *)local_64 + 0x7c);
    guard_check_icall(local_60,((RECT *)(piVar6 + 0x454))->left,piVar6[0x455],piVar6[0x456],
                      piVar6[0x457],local_58);
    (*pcVar10)();
    piVar6 = local_5c;
  }
  piVar6[0x3d2] = 1;
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorPopupMenu[124], CMFCPopupMenu[124], CMFCRibbonMiniToolBar[124], CMFCRibbonPanelMenu[124] */
/* 0081cf4f  FUN_0081cf4f  1109 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0081cf4f(int param_1)

{
  CWnd *pCVar1;
  code *pcVar2;
  HDC pHVar3;
  int iVar4;
  ANIMATION_TYPE AVar5;
  HBITMAP pHVar6;
  void *pvVar7;
  int *piVar8;
  int iVar9;
  CGdiObject *pCVar10;
  CWnd *in_ECX;
  void *pvVar11;
  CWnd *pCVar12;
  undefined1 local_90 [4];
  CGdiObject *local_8c;
  CWnd *local_88;
  DWORD local_84;
  int local_80;
  int local_7c;
  HDC__ *local_78;
  CWnd *local_6c;
  int local_68;
  int local_64;
  CGdiObject *local_60;
  undefined1 local_5c [44];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x81cf5e;
  pvVar11 = (void *)0x0;
  local_80 = param_1;
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  local_6c = in_ECX;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_24);
  local_64 = *(int *)(in_ECX + 0x148) + *(int *)(in_ECX + 0x105c);
  local_68 = *(int *)(in_ECX + 0x14c) + *(int *)(in_ECX + 0x105c);
  CDC::CDC((CDC *)&local_7c);
  local_8 = 0;
  pHVar3 = (HDC)0x0;
  if (param_1 != 0) {
    pHVar3 = *(HDC *)(param_1 + 4);
  }
  pHVar3 = CreateCompatibleDC(pHVar3);
  iVar4 = FUN_0079e84a(pHVar3);
  if (iVar4 == 0) goto LAB_0081d394;
  pCVar12 = in_ECX + 0x1040;
  if ((pCVar12 == (CWnd *)0x0) || (*(int *)(in_ECX + 0x1044) == 0)) {
    local_88 = pCVar12;
    AVar5 = CMFCPopupMenu::GetAnimationType(0);
    if ((AVar5 == 3) || (iVar4 = FUN_007c2511(), 8 < *(int *)(iVar4 + 0x1ac))) {
      local_5c._12_2_ = 1;
      local_5c._4_4_ = local_64;
      local_5c._8_4_ = local_68;
      local_84 = local_68 * local_64;
      local_5c._0_4_ = 0x28;
      local_5c._14_2_ = 0x20;
      local_5c._16_4_ = 0;
      local_5c._24_4_ = 0;
      local_5c._28_4_ = 0;
      local_5c._32_4_ = 0;
      local_5c._36_4_ = 0;
      local_5c._20_4_ = local_84;
      pHVar6 = CreateDIBSection(local_78,(BITMAPINFO *)local_5c,0,(void **)(in_ECX + 0x1050),
                                (HANDLE)0x0,0);
      if ((pHVar6 == (HBITMAP)0x0) || (*(int *)(in_ECX + 0x1050) == 0)) goto LAB_0081d394;
      Attach(pHVar6);
      pHVar6 = CreateDIBSection(local_78,(BITMAPINFO *)local_5c,0,(void **)(in_ECX + 0x1054),
                                (HANDLE)0x0,0);
      if ((pHVar6 == (HBITMAP)0x0) || (*(int *)(in_ECX + 0x1054) == 0)) goto LAB_0081d394;
      Attach(pHVar6);
      pHVar6 = CreateDIBSection(local_78,(BITMAPINFO *)local_5c,0,(void **)(in_ECX + 0x1058),
                                (HANDLE)0x0,0);
      if ((pHVar6 == (HBITMAP)0x0) || (*(int *)(in_ECX + 0x1058) == 0)) goto LAB_0081d394;
      Attach(pHVar6);
      if (in_ECX == (CWnd *)0xffffefc8) {
        pvVar7 = (void *)0x0;
      }
      else {
        pvVar7 = *(void **)(in_ECX + 0x103c);
      }
      local_60 = CDC::SelectGdiObject(local_78,pvVar7);
      if (local_80 == 0) {
        pHVar3 = (HDC)0x0;
      }
      else {
        pHVar3 = *(HDC *)(local_80 + 4);
      }
      BitBlt(local_78,0,0,local_64,local_68,pHVar3,local_24.left,local_24.top,0xcc0020);
      FUN_008f09e0(*(int *)(in_ECX + 0x1054),*(int *)(in_ECX + 0x1050),local_84 << 2);
      pvVar7 = (void *)0x0;
      if (pCVar12 != (CWnd *)0x0) {
        pvVar7 = *(void **)(in_ECX + 0x1044);
      }
      CDC::SelectGdiObject(local_78,pvVar7);
    }
    else {
      pHVar6 = CreateCompatibleBitmap(*(HDC *)(local_80 + 4),local_64,local_68);
      Attach(pHVar6);
      pvVar7 = (void *)0x0;
      if (pCVar12 != (CWnd *)0x0) {
        pvVar7 = *(void **)(in_ECX + 0x1044);
      }
      local_60 = CDC::SelectGdiObject(local_78,pvVar7);
    }
    local_5c[0x28] = '\0';
    local_5c[0x29] = '\0';
    local_5c[0x2a] = '\0';
    local_5c[0x2b] = '\0';
    local_30 = 0;
    pcVar2 = *(code **)(*(int *)in_ECX + 0x1ec);
    local_2c = 0;
    local_28 = 0;
    guard_check_icall(&local_7c);
    (*pcVar2)();
    pcVar2 = *(code **)(*(int *)in_ECX + 0x1c8);
    guard_check_icall();
    piVar8 = (int *)(*pcVar2)();
    GetWindowRect((HWND)piVar8[8],(LPRECT)(local_5c + 0x28));
    CWnd::ScreenToClient(local_6c,(tagRECT *)(local_5c + 0x28));
    pcVar2 = *(code **)(local_7c + 0x38);
    guard_check_icall(local_90,local_5c._40_4_,local_30);
    (*pcVar2)();
    pcVar2 = *(code **)(*piVar8 + 0x264);
    guard_check_icall(&local_7c);
    (*pcVar2)();
    pcVar2 = *(code **)(local_7c + 0x38);
    guard_check_icall(local_90,0,0);
    (*pcVar2)();
    if (local_60 == (CGdiObject *)0x0) {
      pvVar7 = (void *)0x0;
    }
    else {
      pvVar7 = *(void **)(local_60 + 4);
    }
    CDC::SelectGdiObject(local_78,pvVar7);
    pCVar12 = local_88;
    in_ECX = local_6c;
  }
  local_88 = *(CWnd **)(in_ECX + 0x1050);
  local_60 = *(CGdiObject **)(in_ECX + 0x1054);
  local_6c = *(CWnd **)(in_ECX + 0x1058);
  AVar5 = CMFCPopupMenu::GetAnimationType(0);
  if ((AVar5 == 1) || (AVar5 == 2)) {
    pvVar11 = (void *)0x0;
    if (pCVar12 != (CWnd *)0x0) {
      pvVar11 = *(void **)(pCVar12 + 4);
    }
    pCVar10 = CDC::SelectGdiObject(local_78,pvVar11);
    iVar4 = local_24.top;
    if (*(int *)(in_ECX + 0xf70) == 0) {
      iVar4 = local_24.bottom - *(int *)(in_ECX + 0xf68);
    }
    iVar9 = local_24.left;
    if (*(int *)(in_ECX + 0xf6c) == 0) {
      iVar9 = local_24.right - *(int *)(in_ECX + 0xf64);
    }
    BitBlt(*(HDC *)(local_80 + 4),iVar9,iVar4,*(int *)(in_ECX + 0xf64),*(int *)(in_ECX + 0xf68),
           local_78,0,0,0xcc0020);
LAB_0081d384:
    pvVar11 = (void *)0x0;
    if (pCVar10 != (CGdiObject *)0x0) {
      pvVar11 = *(void **)(pCVar10 + 4);
    }
  }
  else if (AVar5 == 3) {
    if (in_ECX == (CWnd *)0xffffefb8) {
      pvVar11 = (void *)0x0;
    }
    else {
      pvVar11 = *(void **)(in_ECX + 0x104c);
    }
    local_8c = CDC::SelectGdiObject(local_78,pvVar11);
    iVar4 = local_68 * local_64;
    if (0 < iVar4) {
      local_60 = (CGdiObject *)((int)local_60 - (int)local_88);
      pCVar12 = local_88;
      do {
        pCVar1 = pCVar12 + (int)local_60;
        iVar9 = *(int *)pCVar12;
        pCVar12 = pCVar12 + 4;
        iVar9 = FUN_00818965(iVar9,*(undefined4 *)pCVar1,100 - *(int *)(in_ECX + 0xfb0));
        *(int *)local_6c = iVar9;
        local_6c = local_6c + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    BitBlt(*(HDC *)(local_80 + 4),local_24.left,local_24.top,local_64,local_68,local_78,0,0,0xcc0020
          );
    pCVar10 = local_8c;
    goto LAB_0081d384;
  }
  CDC::SelectGdiObject(local_78,pvVar11);
LAB_0081d394:
  FUN_0079e053();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorPopupMenu[131], CMFCPopupMenu[131] */
/* 0081d448  FUN_0081d448  32 bytes, 1 callers */

void FUN_0081d448(void)

{
  code *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x2f4);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCColorPopupMenu[117], CMFCPopupMenu[117], CMFCRibbonMiniToolBar[117], CMFCRibbonPanelMenu[117] */
/* 0081d4c1  FUN_0081d4c1  104 bytes, 0 callers */

int FUN_0081d4c1(undefined4 *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(in_ECX + 0x158);
  if (iVar1 == 0) {
    if (*(int **)(in_ECX + 0x116c) != (int *)0x0) {
      pcVar2 = *(code **)(**(int **)(in_ECX + 0x116c) + 0xa4);
      guard_check_icall();
      iVar3 = (*pcVar2)();
      if (iVar3 != 0) {
        iVar1 = *(int *)(in_ECX + 0x116c);
        local_14 = *(undefined4 *)(iVar1 + 0x74);
        uStack_10 = *(undefined4 *)(iVar1 + 0x78);
        uStack_c = *(undefined4 *)(iVar1 + 0x7c);
        uStack_8 = *(undefined4 *)(iVar1 + 0x80);
        puVar4 = &local_14;
        goto LAB_0081d4e0;
      }
    }
  }
  else {
    iVar3 = *(int *)(iVar1 + 0x6c);
    if (iVar3 != 0) {
      puVar4 = (undefined4 *)(iVar1 + 0x54);
LAB_0081d4e0:
      *param_1 = *puVar4;
      param_1[1] = puVar4[1];
      param_1[2] = puVar4[2];
      param_1[3] = puVar4[3];
      return iVar3;
    }
  }
  return 0;
}




/* vtable slots: CMFCColorPopupMenu[125], CMFCPopupMenu[125], CMFCRibbonMiniToolBar[125], CMFCRibbonPanelMenu[125] */
/* 0081d610  FUN_0081d610  1636 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0081d610(void)

{
  code *pcVar1;
  char cVar2;
  int *piVar3;
  BOOL BVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int *in_ECX;
  uint uVar10;
  bool bVar11;
  int local_324;
  int *local_320;
  int local_31c;
  int local_318;
  uint local_314;
  int *local_310;
  uint local_30c;
  int local_308;
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 800;
  local_8 = 0x81d61f;
  pcVar1 = *(code **)(*in_ECX + 0x1c8);
  guard_check_icall();
  piVar3 = (int *)(*pcVar1)();
  local_320 = piVar3;
  if ((HMENU)in_ECX[0x3cd] != (HMENU)0x0) {
    BVar4 = IsMenu((HMENU)in_ECX[0x3cd]);
    if (BVar4 == 0) goto LAB_0081dc6a;
    if ((in_ECX[0x56] != 0) || (iVar5 = FUN_0082b8fd(in_ECX[0x3cd],piVar3), iVar5 == 0)) {
      iVar5 = CMFCMenuBar::IsShowAllCommands();
      pcVar1 = *(code **)(*piVar3 + 0x438);
      if (iVar5 == 0) {
        bVar11 = in_ECX[0x56] == 0;
      }
      else {
        bVar11 = true;
      }
      guard_check_icall(in_ECX[0x3cd],bVar11);
      iVar5 = (*pcVar1)();
      if (iVar5 == 0) goto LAB_0081dc64;
    }
  }
  iVar5 = FUN_0079dd6d();
  piVar9 = *(int **)(*(int *)(iVar5 + 4) + 0x8c);
  if ((piVar9 != (int *)0x0) && (DAT_00a127ac == 0)) {
    local_30c = 0;
    local_314 = 0;
    local_318 = piVar3[0x310];
    while( true ) {
      iVar5 = local_318;
      if (local_318 == 0) goto LAB_0081d954;
      piVar6 = (int *)FUN_0044f2d0(&local_318);
      piVar6 = (int *)*piVar6;
      if (piVar6 == (int *)0x0) goto LAB_0081dc6a;
      if ((piVar6[8] == 0xe110) &&
         (cVar2 = FUN_00481200(piVar6 + 0xb,L"Recent File"), cVar2 != '\0')) break;
      local_314 = piVar6[9] & 1;
      local_30c = local_30c + 1;
    }
    FUN_007a1ad4(iVar5);
    pcVar1 = *(code **)(*piVar6 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    GetCurrentDirectoryW(0x104,local_21c);
    iVar5 = FUN_008f899d(local_21c);
    local_21c[iVar5] = L'\\';
    iVar5 = iVar5 + 1;
    if (0x207 < (uint)(iVar5 * 2)) {
                    /* WARNING: Subroutine does not return */
      FUN_008d927f();
    }
    local_21c[iVar5] = L'\0';
    local_308 = 0;
    local_31c = 0;
    if (piVar9[1] < 1) goto LAB_0081d8f7;
    do {
      CStringT<>();
      local_8 = 0;
      pcVar1 = *(code **)(*piVar9 + 0xc);
      guard_check_icall(&local_310,local_308,local_21c,iVar5,1);
      iVar7 = (*pcVar1)();
      if (iVar7 != 0) {
        CStringT<>();
        local_31c = local_31c + 1;
        local_8._0_1_ = 1;
        FUN_004059f0(&local_324,L"&%d %Ts",local_31c,local_310);
        uVar10 = local_30c;
        pcVar1 = *(code **)(*piVar3 + 0x344);
        local_30c = local_30c + 1;
        uVar8 = FUN_00874dc7(local_308 + 0xe110,0,0xffffffff,local_324,0);
        local_8 = CONCAT31(local_8._1_3_,2);
        guard_check_icall(uVar8,uVar10);
        (*pcVar1)();
        FUN_00874eb0();
        FUN_00406b10();
        piVar3 = local_320;
      }
      local_8 = 0xffffffff;
      FUN_00406b10();
      local_308 = local_308 + 1;
    } while (local_308 < piVar9[1]);
    if (local_31c == 0) {
LAB_0081d8f7:
      iVar5 = local_318;
      if ((local_314 != 0) && (local_318 != 0)) {
        piVar9 = (int *)FUN_0044f2d0(&local_318);
        piVar9 = (int *)*piVar9;
        if (piVar9 == (int *)0x0) {
LAB_0081dc6a:
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        if ((*(byte *)(piVar9 + 9) & 1) != 0) {
          FUN_007a1ad4(iVar5);
          pcVar1 = *(code **)(*piVar9 + 4);
          guard_check_icall(1);
          (*pcVar1)();
        }
      }
    }
  }
LAB_0081d954:
  if ((DAT_00a13bac != 0) && (DAT_00a127ac == 0)) {
    local_318 = piVar3[0x310];
    local_314 = 0;
    uVar10 = 0;
    local_308 = 0;
    local_30c = 0;
    iVar5 = local_318;
    iVar7 = local_308;
    while (local_308 = iVar7, iVar5 != 0) {
      local_310 = (int *)FUN_0044f2d0(&local_318);
      local_310 = (int *)*local_310;
      if (local_310 == (int *)0x0) goto LAB_0081dc6a;
      local_324 = local_318;
      if (*(int *)(DAT_00a13bac + 0x20) == local_310[8]) {
        local_31c = DAT_00a13bac + 4;
        if ((DAT_00a139d0 == 0) || (*(int *)(DAT_00a13bac + 0x10) != 0)) {
          FUN_007a1ad4(iVar5);
          pcVar1 = *(code **)(*local_310 + 4);
          guard_check_icall(1);
          (*pcVar1)();
          uVar10 = local_30c;
        }
        if (local_314 == 0) {
          iVar5 = iVar7;
          if (((uVar10 == 0) && (*(int *)(local_31c + 0xc) != 0)) && (piVar3[0x312] != 0)) {
            iVar5 = iVar7 + 1;
            pcVar1 = *(code **)(*piVar3 + 0x348);
            local_308 = iVar5;
            guard_check_icall(iVar7);
            (*pcVar1)();
          }
          local_314 = *(uint *)(local_31c + 4);
          while (local_314 != 0) {
            iVar7 = FUN_0049acb0(&local_314);
            FUN_0082be6d();
            uVar10 = FUN_0082be37(*(undefined4 *)(iVar7 + 0x10),1);
            local_308 = local_308 + 1;
            pcVar1 = *(code **)(*piVar3 + 0x344);
            uVar8 = FUN_00874dc7(*(undefined4 *)(iVar7 + 0x10),0,
                                 -(uint)(uVar10 != 0xffffffff) & uVar10,*(undefined4 *)(iVar7 + 4),
                                 uVar10 != 0xffffffff);
            local_8 = 3;
            guard_check_icall(uVar8,iVar5);
            (*pcVar1)();
            local_8 = 0xffffffff;
            FUN_00874eb0();
            piVar3 = local_320;
            iVar5 = local_308;
          }
          iVar7 = iVar5;
          if (local_324 != 0) {
            iVar7 = iVar5 + 1;
            pcVar1 = *(code **)(*piVar3 + 0x348);
            guard_check_icall(iVar5);
            iVar5 = (*pcVar1)();
            local_30c = (uint)(-1 < iVar5);
          }
          local_314 = 1;
          uVar10 = local_30c;
        }
      }
      else if ((*(byte *)(local_310 + 9) & 1) == 0) {
        uVar10 = 0;
        local_30c = uVar10;
      }
      else {
        if (uVar10 != 0) {
          FUN_007a1ad4(iVar5);
          pcVar1 = *(code **)(*local_310 + 4);
          guard_check_icall(1);
          (*pcVar1)();
        }
        uVar10 = 1;
        local_30c = uVar10;
      }
      iVar7 = iVar7 + 1;
      iVar5 = local_324;
    }
  }
  pcVar1 = *(code **)(*piVar3 + 0x3c4);
  guard_check_icall();
  piVar9 = (int *)(*pcVar1)();
  if (piVar9 == (int *)0x0) {
LAB_0081dbf4:
    piVar9 = (int *)FUN_007e5618(in_ECX);
    if (piVar9 != (int *)0x0) goto LAB_0081dc15;
  }
  else {
    pcVar1 = *(code **)(*piVar9 + 0x150);
    guard_check_icall();
    iVar5 = (*pcVar1)();
    if (iVar5 == 0) goto LAB_0081dbf4;
LAB_0081dc15:
    pcVar1 = *(code **)(*piVar3 + 0x244);
    guard_check_icall(piVar9,0);
    (*pcVar1)();
  }
  iVar5 = DAT_00a13a1c;
  if (DAT_00a13a1c == 0) {
    iVar5 = FUN_00792b4c();
  }
  iVar5 = FUN_0081bab4(iVar5,in_ECX);
  if (iVar5 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x178);
    guard_check_icall(1);
    (*pcVar1)();
  }
LAB_0081dc64:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorPopupMenu[122], CMFCPopupMenu[122] */
/* 0081df20  FUN_0081df20  152 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_0081df20(void)

{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x1c8);
  guard_check_icall();
  piVar3 = (int *)(*pcVar1)();
  iVar4 = FUN_007fdf7c();
  bVar2 = false;
  if (iVar4 != 0) {
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    pcVar1 = *(code **)(*piVar3 + 0x36c);
    iVar4 = FUN_007fdf7c();
    guard_check_icall(iVar4 + -1,&local_18);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x354);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    bVar2 = iVar4 + in_ECX[0x3d4] < local_c;
  }
  return bVar2;
}




/* vtable slots: CMFCColorPopupMenu[121], CMFCPopupMenu[121] */
/* 0081dfb8  FUN_0081dfb8  40 bytes, 0 callers */

bool FUN_0081dfb8(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1c8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  return 0 < *(int *)(iVar2 + 0xd4c);
}




/* vtable slots: CMFCColorPopupMenu[3], CMFCPopupMenu[3], CMFCRibbonMiniToolBar[3], CMFCRibbonPanelMenu[3] */
/* 0081e0d7  FUN_0081e0d7  82 bytes, 0 callers */

undefined4 FUN_0081e0d7(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = FUN_0079aebf(param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    if (*(int **)(in_ECX + 0x134) == (int *)0x0) {
      uVar3 = 0;
    }
    else {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x134) + 0xc);
      guard_check_icall(param_1,param_2,param_3,param_4);
      uVar3 = (*pcVar1)();
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CMFCColorPopupMenu[62], CMFCPopupMenu[62], CMFCRibbonMiniToolBar[62], CMFCRibbonPanelMenu[62] */
/* 0081eddc  FUN_0081eddc  103 bytes, 0 callers */

void FUN_0081eddc(undefined4 param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if (*(int *)(param_2 + 8) == -0x209) {
    *(undefined4 *)(in_ECX + 0x1078) = 1;
  }
  else {
    if (*(int *)(param_2 + 8) != -0x20a) goto LAB_0081ee2a;
    *(undefined4 *)(in_ECX + 0x1078) = 0;
  }
  InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)(in_ECX + 0x107c),1);
  UpdateWindow(*(HWND *)(in_ECX + 0x20));
LAB_0081ee2a:
  FUN_00793ba8(param_1,param_2,param_3);
  return;
}




/* vtable slots: CMFCColorPopupMenu[72], CMFCPopupMenu[72], CMFCRibbonMiniToolBar[72], CMFCRibbonPanelMenu[72] */
/* 0081f6d0  FUN_0081f6d0  72 bytes, 0 callers */

void FUN_0081f6d0(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x158) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x158) + 0x58);
    guard_check_icall();
    (*pcVar1)();
  }
  if (*(int **)(in_ECX + 0x116c) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x116c) + 0x198);
    guard_check_icall();
    (*pcVar1)();
  }
  FUN_0079c41b();
  return;
}




/* vtable slots: CMFCColorPopupMenu[67], CMFCPopupMenu[67], CMFCRibbonMiniToolBar[67], CMFCRibbonPanelMenu[67] */
/* 0081f718  FUN_0081f718  199 bytes, 0 callers */

undefined4 FUN_0081f718(int param_1)

{
  POINT pt;
  POINT pt_00;
  BOOL BVar1;
  undefined4 uVar2;
  int in_ECX;
  tagPOINT local_c;
  
  local_c.x = in_ECX;
  local_c.y = in_ECX;
  if ((in_ECX != -0x1090) && (*(int *)(in_ECX + 0x10b0) != 0)) {
    SendMessageW(*(HWND *)(in_ECX + 0x10b0),0x407,0,param_1);
  }
  if (*(int *)(param_1 + 4) == 0x200) {
    BVar1 = IsRectEmpty((RECT *)(in_ECX + 0xf84));
    if (BVar1 != 0) {
      BVar1 = IsRectEmpty((RECT *)(in_ECX + 0xf94));
      if (BVar1 != 0) goto LAB_0081f7d0;
    }
    local_c.x = 0;
    local_c.y = 0;
    GetCursorPos(&local_c);
    ScreenToClient(*(HWND *)(in_ECX + 0x20),&local_c);
    pt.y = local_c.y;
    pt.x = local_c.x;
    BVar1 = PtInRect((RECT *)(in_ECX + 0xf84),pt);
    if (BVar1 == 0) {
      pt_00.y = local_c.y;
      pt_00.x = local_c.x;
      BVar1 = PtInRect((RECT *)(in_ECX + 0xf94),pt_00);
      if (BVar1 == 0) goto LAB_0081f7d0;
    }
    FUN_0081eb3f(*(undefined4 *)(param_1 + 8),local_c.x,local_c.y);
    uVar2 = 1;
  }
  else {
LAB_0081f7d0:
    uVar2 = FUN_0079c475(param_1);
  }
  return uVar2;
}




/* vtable slots: CMFCColorPopupMenu[94], CMFCPopupMenu[94], CMFCRibbonMiniToolBar[94], CMFCRibbonPanelMenu[94] */
/* 0081f7df  FUN_0081f7df  4505 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0081f7df(void)

{
  code *pcVar1;
  CWnd *this;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  BOOL BVar6;
  int iVar7;
  HMONITOR hMonitor;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  int *piVar13;
  LONG LVar14;
  ANIMATION_TYPE AVar15;
  CObject *pCVar16;
  int iVar17;
  int *in_ECX;
  tagMONITORINFO *lpmi;
  undefined4 uVar18;
  CObject *local_ac;
  uint local_98;
  uint local_94;
  tagMONITORINFO local_90;
  tagRECT local_68;
  tagRECT local_58;
  undefined1 local_48 [12];
  int local_3c;
  undefined1 local_38 [12];
  int local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x1c8);
  guard_check_icall();
  piVar5 = (int *)(*pcVar1)();
  BVar6 = IsWindow((HWND)in_ECX[8]);
  if (BVar6 == 0) {
    return;
  }
  if (piVar5 == (int *)0x0) {
    return;
  }
  BVar6 = IsWindow((HWND)piVar5[8]);
  if (BVar6 == 0) {
    return;
  }
  if (piVar5[0x2f7] != 0) {
    return;
  }
  if ((int *)in_ECX[0x56] == (int *)0x0) {
LAB_0081f892:
    bVar2 = false;
  }
  else {
    pcVar1 = *(code **)(*(int *)in_ECX[0x56] + 0xf4);
    guard_check_icall();
    iVar7 = (*pcVar1)();
    if ((iVar7 == 0) || (DAT_00a127ac != 0)) goto LAB_0081f892;
    bVar2 = true;
  }
  lpmi = &local_90;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  local_90.cbSize = 0x28;
  hMonitor = MonitorFromPoint(*(POINT *)(in_ECX + 0x4e),2);
  BVar6 = GetMonitorInfoW(hMonitor,lpmi);
  if (BVar6 == 0) {
    SystemParametersInfoW(0x30,0,&local_28,0);
  }
  else {
    CopyRect(&local_28,&local_90.rcWork);
  }
  pcVar1 = *(code **)(*in_ECX + 0x20c);
  guard_check_icall();
  iVar8 = (*pcVar1)();
  uVar9 = FUN_00797acc();
  uVar9 = uVar9 & 0x400000;
  iVar7 = in_ECX[0x4e];
  iVar12 = in_ECX[0x44c];
  if (iVar12 != 0) {
    iVar17 = in_ECX[0x452];
    if (uVar9 == 0) {
      iVar10 = (local_28.right + iVar8 * -2) - iVar7;
      if (iVar10 <= iVar17) {
        iVar17 = iVar10;
      }
    }
    else {
      iVar10 = (iVar7 + iVar8 * -2) - local_28.left;
      if (iVar10 <= iVar17) {
        iVar17 = iVar10;
      }
    }
    in_ECX[0x452] = iVar17;
    iVar10 = local_28.bottom + ((in_ECX[0x455] - in_ECX[0x4f]) - in_ECX[0x457]) + iVar8 * -2;
    iVar17 = in_ECX[0x453];
    if (iVar10 <= in_ECX[0x453]) {
      iVar17 = iVar10;
    }
    in_ECX[0x453] = iVar17;
  }
  iVar17 = iVar7;
  if (local_28.right <= iVar7) {
    iVar17 = local_28.right;
  }
  LVar14 = local_28.left;
  if ((local_28.left <= iVar17) && (LVar14 = iVar7, local_28.right <= iVar7)) {
    LVar14 = local_28.right;
  }
  in_ECX[0x4e] = LVar14;
  if (in_ECX[0x56] == 0) {
    iVar7 = in_ECX[0x4f];
    iVar17 = iVar7;
    if (local_28.bottom <= iVar7) {
      iVar17 = local_28.bottom;
    }
    LVar14 = local_28.top;
    if ((local_28.top <= iVar17) && (LVar14 = iVar7, local_28.bottom <= iVar7)) {
      LVar14 = local_28.bottom;
    }
    in_ECX[0x4f] = LVar14;
  }
  local_98 = in_ECX[0x452];
  local_94 = in_ECX[0x453];
  if ((iVar12 == 0) && (in_ECX[0x44d] == 0)) {
    pcVar1 = *(code **)(*piVar5 + 0x2a4);
    guard_check_icall(local_38 + 8,1);
    puVar11 = (uint *)(*pcVar1)();
    local_98 = *puVar11;
    local_94 = puVar11[1];
    iVar12 = in_ECX[0x44c];
  }
  bVar3 = false;
  if ((iVar12 == 0) && (in_ECX[0x44d] == 0)) {
    local_98 = local_98 + iVar8 * 2;
    local_94 = local_94 + iVar8 * 2;
    if ((in_ECX[0x3df] != 0) && (in_ECX[0x3e0] != 0)) {
      iVar7 = GetSystemMetrics(2);
      local_98 = iVar7 + local_98;
      BVar6 = IsRectEmpty((RECT *)(in_ECX + 0x454));
      if (BVar6 == 0) {
        iVar7 = GetSystemMetrics(2);
        in_ECX[0x456] = in_ECX[0x456] + iVar7;
      }
      bVar3 = true;
    }
    iVar7 = in_ECX[0x3d8];
    if ((iVar7 == 0) || (iVar7 == 1)) {
      local_98 = local_98 + in_ECX[0x3d6];
    }
    else if ((iVar7 == 2) || (iVar7 == 3)) {
      local_94 = local_94 + in_ECX[0x3d6];
    }
  }
  if (in_ECX[0x55] == 0) {
    if (bVar2) {
      local_94 = local_94 + 10;
      local_18.right = local_98 - iVar8;
      local_18.bottom = iVar8 + 10;
      in_ECX[0x41f] = iVar8;
      in_ECX[0x420] = iVar8;
      in_ECX[0x421] = local_18.right;
      in_ECX[0x422] = local_18.bottom;
      local_18.left = iVar8;
      local_18.top = iVar8;
      if ((DAT_00a127ac == 0) && ((in_ECX + 0x424 == (int *)0x0 || (in_ECX[0x42c] == 0)))) {
        pcVar1 = *(code **)(in_ECX[0x424] + 0x164);
        guard_check_icall(in_ECX,0);
        (*pcVar1)();
        SendMessageW((HWND)in_ECX[0x42c],0x401,1,0);
        iVar7 = FUN_007c2511();
        if (*(int *)(iVar7 + 0x1c4) != -1) {
          iVar7 = FUN_007c2511();
          SendMessageW((HWND)in_ECX[0x42c],0x418,0,*(LPARAM *)(iVar7 + 0x1c4));
        }
        FUN_007af37e(in_ECX,0x3e9c,in_ECX + 0x41f,1);
      }
    }
  }
  else {
    iVar7 = GetSystemMetrics(0x33);
    iVar12 = GetSystemMetrics(6);
    local_94 = iVar12 * 2 + 5 + local_94 + iVar7;
  }
  iVar7 = in_ECX[0x3eb];
  if ((iVar7 != -1) && (iVar7 < (int)local_94)) {
    if ((in_ECX[0x44c] == 0) && (in_ECX[0x44d] == 0)) {
      iVar7 = iVar7 + iVar8 * -2;
      pcVar1 = *(code **)(*piVar5 + 0x354);
      guard_check_icall();
      iVar12 = (*pcVar1)();
      local_94 = iVar7 + 2 + (iVar8 * 2 - iVar7 % iVar12);
      in_ECX[0x3d0] = 1;
    }
    in_ECX[0x3df] = 1;
  }
  if (in_ECX[0x44f] != 0) {
    iVar7 = ((in_ECX[0x450] < 1) - 1 & 3) + 9;
    local_18.top = iVar8;
    if (in_ECX[0x44e] == 0) {
      local_18.top = local_94 - iVar8;
    }
    local_18.right = local_98 - iVar8;
    local_18.bottom = iVar7 + local_18.top;
    local_94 = local_94 + iVar7;
    in_ECX[0x454] = iVar8;
    in_ECX[0x455] = local_18.top;
    in_ECX[0x456] = local_18.right;
    in_ECX[0x457] = local_18.bottom;
    local_18.left = iVar8;
  }
  if ((uVar9 == 0) && (in_ECX[0x3d1] == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (in_ECX[0x56] == 0) {
    local_ac = (CObject *)0x0;
  }
  else {
    local_ac = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCMenuBar_00a00b00,
                                  *(CObject **)(in_ECX[0x56] + 0x6c));
    if (local_ac != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)local_ac + 0x170);
      guard_check_icall();
      iVar7 = (*pcVar1)();
      if (iVar7 != 0) {
        iVar7 = FUN_008880a8(in_ECX[0x56]);
        if (iVar7 == 2) {
          iVar7 = *(int *)(in_ECX[0x56] + 0x60);
          iVar12 = *(int *)(in_ECX[0x56] + 0x58);
          in_ECX[0x3cc] = 2;
          in_ECX[0x4f] = (((in_ECX[0x51] - iVar7) + iVar12) - local_94) + 1;
        }
        else if (iVar7 == 3) {
          iVar7 = in_ECX[0x56];
          if (uVar9 == 0) {
            iVar12 = in_ECX[0x50] + (*(int *)(iVar7 + 0x5c) - *(int *)(iVar7 + 0x54));
          }
          else {
            iVar12 = (in_ECX[0x50] - *(int *)(iVar7 + 0x5c)) + *(int *)(iVar7 + 0x54);
          }
          in_ECX[0x4e] = iVar12;
          iVar12 = *(int *)(iVar7 + 0x58);
          iVar7 = *(int *)(iVar7 + 0x60);
          in_ECX[0x3cc] = 3;
          in_ECX[0x4f] = iVar12 + 1 + (in_ECX[0x51] - iVar7);
        }
        else if (iVar7 == 4) {
          iVar7 = *(int *)(in_ECX[0x56] + 0x60);
          iVar12 = *(int *)(in_ECX[0x56] + 0x58);
          in_ECX[0x3cc] = 4;
          in_ECX[0x4f] = iVar12 + (in_ECX[0x51] - iVar7) + 1;
          if (uVar9 == 0) {
            iVar7 = in_ECX[0x50] - local_98;
            in_ECX[0x4e] = iVar7;
            if (iVar7 < local_28.left) {
              in_ECX[0x4e] = local_28.left;
              goto LAB_0081febb;
            }
          }
          else {
            iVar7 = local_98 + in_ECX[0x50];
            in_ECX[0x4e] = iVar7;
            if (local_28.right < iVar7) {
              in_ECX[0x4e] = local_28.right;
LAB_0081febb:
              in_ECX[0x3cc] = 0;
            }
          }
        }
      }
    }
  }
  local_58.left = 0;
  local_58.top = 0;
  local_58.right = 0;
  local_58.bottom = 0;
  SetRectEmpty(&local_58);
  bVar4 = false;
  piVar13 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar13 + 0x2f0);
  guard_check_icall();
  iVar7 = (*pcVar1)();
  if ((((iVar7 != 0) && (iVar7 = FUN_0081d529(), iVar7 != 0)) &&
      (iVar12 = in_ECX[0x56], iVar12 != 0)) && (*(int *)(iVar12 + 0xb4) != 0)) {
    if (uVar9 == 0) {
      RedrawWindow(*(HWND *)(iVar7 + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
    }
    if ((*(int *)(iVar7 + 0x1160) != 0) && (in_ECX[0x458] == 0)) {
      local_58.left = *(int *)(iVar12 + 0x54);
      local_58.top = *(int *)(iVar12 + 0x58);
      local_58.right = *(int *)(iVar12 + 0x5c);
      local_58.bottom = *(int *)(iVar12 + 0x60);
      if ((*(int *)(iVar12 + 0x6c) != 0) && (*(int *)(*(int *)(iVar12 + 0x6c) + 0x20) != 0)) {
        FUN_0079e8b8(&local_58);
        bVar4 = true;
        in_ECX[0x4f] = local_58.top;
        if (in_ECX[0x3cc] == 4) {
          LVar14 = local_58.left;
          if (uVar9 == 0) {
            LVar14 = local_58.left - local_98;
          }
        }
        else {
          LVar14 = local_58.right;
          if (uVar9 != 0) {
            LVar14 = local_58.right + local_98;
          }
        }
        in_ECX[0x4e] = LVar14;
      }
    }
  }
  if (((uVar9 != 0) && ((int)(in_ECX[0x4e] - local_98) < local_28.left)) ||
     ((!bVar2 && (local_28.right < (int)(in_ECX[0x4e] + local_98))))) {
    iVar7 = FUN_0081d529();
    if (iVar7 == 0) {
      if (local_ac != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)local_ac + 0x164);
        guard_check_icall();
        iVar7 = (*pcVar1)();
        if (iVar7 == 0) {
          iVar7 = in_ECX[0x56];
          local_18.left = *(int *)(iVar7 + 0x54);
          local_18.top = *(int *)(iVar7 + 0x58);
          local_18.right = *(int *)(iVar7 + 0x5c);
          local_18.bottom = *(int *)(iVar7 + 0x60);
          FUN_0079e8b8(&local_18);
          if (uVar9 == 0) {
            iVar7 = local_18.left - local_98;
          }
          else {
            iVar7 = local_18.right + local_98;
          }
          in_ECX[0x4e] = iVar7;
          if (local_28.right <= (int)(iVar7 + local_98)) {
            iVar7 = (local_28.right - local_98) + -1;
            in_ECX[0x4e] = iVar7;
          }
          iVar12 = 4;
          goto LAB_00820235;
        }
      }
      if (uVar9 == 0) {
        if (in_ECX[0x3d1] == 0) {
          iVar7 = (local_28.right - local_98) + -1;
        }
        else {
          iVar7 = local_28.left + 1;
        }
      }
      else {
        iVar7 = local_28.left + 1 + local_98;
      }
      in_ECX[0x4e] = iVar7;
      iVar12 = 0;
    }
    else {
      local_38._0_4_ = 0;
      local_38._4_4_ = 0;
      local_38._8_4_ = 0;
      local_2c = 0;
      GetWindowRect(*(HWND *)(iVar7 + 0x20),(LPRECT)local_38);
      if (uVar9 == 0) {
        iVar7 = local_38._0_4_ - local_98;
      }
      else {
        iVar7 = local_38._8_4_ + local_98;
      }
      in_ECX[0x4e] = iVar7;
      if ((in_ECX[0x45b] != 0) && (iVar7 = FUN_00863d99(), iVar7 == 0)) {
        iVar7 = in_ECX[0x45b];
        local_38._0_4_ = *(int *)(iVar7 + 0x74);
        local_38._4_4_ = *(int *)(iVar7 + 0x78);
        local_38._8_4_ = *(int *)(iVar7 + 0x7c);
        local_2c = *(int *)(iVar7 + 0x80);
        FUN_0079e8b8(local_38);
        if (uVar9 == 0) {
          iVar7 = local_38._8_4_ - local_98;
        }
        else {
          iVar7 = local_38._0_4_ + local_98;
        }
        in_ECX[0x4e] = iVar7;
      }
      iVar7 = in_ECX[0x4e];
      iVar12 = 4 - (uint)(uVar9 != 0);
    }
LAB_00820235:
    in_ECX[0x3cc] = iVar12;
    if (uVar9 == 0) {
      if (iVar7 < local_28.left) {
        in_ECX[0x4e] = local_28.left;
LAB_00820260:
        in_ECX[0x3cc] = 0;
      }
    }
    else if (local_28.right < iVar7) {
      in_ECX[0x4e] = local_28.right;
      goto LAB_00820260;
    }
    if (in_ECX[0x3de] == 0) {
      AVar15 = CMFCPopupMenu::GetAnimationType(0);
      if (AVar15 == 1) {
        in_ECX[0x3db] = 0;
      }
      else {
        AVar15 = CMFCPopupMenu::GetAnimationType(0);
        if (AVar15 == 3) {
          in_ECX[0x3db] = 0;
          in_ECX[0x3dc] = 0;
        }
      }
    }
  }
  iVar7 = in_ECX[0x4f];
  if (local_28.bottom < (int)(local_94 + iVar7)) {
    iVar7 = in_ECX[0x457] - in_ECX[0x455];
    if (in_ECX[0x44f] != 0) {
      local_18.right = local_98 - iVar8;
      local_18.bottom = iVar8 + iVar7;
      in_ECX[0x454] = iVar8;
      in_ECX[0x455] = iVar8;
      in_ECX[0x456] = local_18.right;
      in_ECX[0x457] = local_18.bottom;
      in_ECX[0x44e] = 1;
      local_18.left = iVar8;
      local_18.top = iVar8;
    }
    in_ECX[0x3dc] = 0;
    local_68.left = 0;
    local_68.top = 0;
    local_68.right = 0;
    local_68.bottom = 0;
    pcVar1 = *(code **)(*in_ECX + 0x1d4);
    guard_check_icall(&local_68);
    iVar12 = (*pcVar1)();
    if (((iVar12 == 0) || (in_ECX[0x3cc] == 4)) || (in_ECX[0x3cc] == 3)) {
      if (bVar4) {
        in_ECX[0x4f] = (local_58.bottom - local_94) + -1;
      }
      else {
        in_ECX[0x4f] = in_ECX[0x4f] - local_94;
        iVar7 = FUN_0081d529();
        if (iVar7 != 0) {
          pcVar1 = *(code **)(*piVar5 + 0x354);
          guard_check_icall();
          iVar7 = (*pcVar1)();
          in_ECX[0x4f] = in_ECX[0x4f] + iVar7 + iVar8 * 2;
        }
      }
    }
    else {
      local_2c = 0;
      local_38._8_4_ = local_68.right;
      ClientToScreen(*(HWND *)(iVar12 + 0x20),(LPPOINT)(local_38 + 8));
      local_3c = local_68.top - local_94;
      local_48._8_4_ = 0;
      ClientToScreen(*(HWND *)(iVar12 + 0x20),(LPPOINT)(local_48 + 8));
      if (local_3c < 0) {
        iVar12 = local_3c + local_94;
        bVar2 = true;
        if (in_ECX[0x3df] != 0) {
          if ((in_ECX[0x56] != 0) &&
             (pCVar16 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,
                                           *(CObject **)(in_ECX[0x56] + 0x6c)),
             pCVar16 != (CObject *)0x0)) {
            pcVar1 = *(code **)(*(int *)pCVar16 + 0x164);
            guard_check_icall();
            iVar17 = (*pcVar1)();
            if ((iVar17 != 0) && (iVar17 = FUN_0081d529(), iVar17 == 0)) {
              bVar2 = true;
              goto LAB_0082041a;
            }
          }
          bVar2 = false;
        }
LAB_0082041a:
        if ((local_28.bottom - iVar12 < iVar12 - local_28.top) && (bVar2)) {
          in_ECX[0x3cc] = 0;
          local_94 = local_94 + local_3c;
          in_ECX[0x4f] = local_28.top;
        }
        else {
          local_94 = local_28.bottom - in_ECX[0x4f];
          in_ECX[0x3dc] = 1;
          if (in_ECX[0x44f] != 0) {
            in_ECX[0x44e] = 0;
            local_18.top = (local_94 - iVar7) - iVar8;
            local_18.right = local_98 - iVar8;
            local_18.bottom = iVar7 + local_18.top;
            in_ECX[0x454] = iVar8;
            in_ECX[0x455] = local_18.top;
            in_ECX[0x456] = local_18.right;
            in_ECX[0x457] = local_18.bottom;
            local_18.left = iVar8;
          }
        }
        in_ECX[0x3d0] = 1;
        in_ECX[0x3df] = 1;
      }
      else {
        in_ECX[0x4f] = local_3c;
        if (local_ac == (CObject *)0x0) {
LAB_00820509:
          iVar7 = 0;
        }
        else {
          pcVar1 = *(code **)(*(int *)local_ac + 0x164);
          guard_check_icall();
          iVar7 = (*pcVar1)();
          if (iVar7 == 0) goto LAB_00820509;
          iVar7 = 2;
        }
        in_ECX[0x3cc] = iVar7;
      }
    }
    iVar7 = in_ECX[0x4f];
    if (in_ECX[0x4f] < local_28.top) {
      in_ECX[0x3cc] = 0;
      in_ECX[0x4f] = local_28.top;
      iVar7 = local_28.top;
    }
    if (local_28.bottom < (int)(iVar7 + local_94)) {
      local_94 = local_28.bottom - in_ECX[0x4f];
      in_ECX[0x3d0] = 1;
      in_ECX[0x3df] = 1;
    }
    iVar7 = in_ECX[0x4f];
  }
  if (local_28.top <= iVar7) goto LAB_008206cb;
  if (((in_ECX[0x56] == 0) || (*(int *)(in_ECX[0x56] + 0x6c) == 0)) ||
     (iVar7 = FUN_0081d529(), iVar7 != 0)) {
    in_ECX[0x4f] = local_28.top;
  }
  else {
    local_38._8_4_ = *(int *)(in_ECX[0x56] + 0x5c);
    local_2c = 0;
    ClientToScreen(*(HWND *)(*(int *)(in_ECX[0x56] + 0x6c) + 0x20),(LPPOINT)(local_38 + 8));
    local_3c = *(int *)(in_ECX[0x56] + 0x60);
    local_48._8_4_ = 0;
    ClientToScreen(*(HWND *)(*(int *)(in_ECX[0x56] + 0x6c) + 0x20),(LPPOINT)(local_48 + 8));
    in_ECX[0x4f] = local_3c;
    if (local_ac == (CObject *)0x0) {
LAB_00820678:
      iVar7 = 0;
    }
    else {
      pcVar1 = *(code **)(*(int *)local_ac + 0x164);
      guard_check_icall();
      iVar7 = (*pcVar1)();
      if (iVar7 == 0) goto LAB_00820678;
      iVar7 = 1;
    }
    in_ECX[0x3cc] = iVar7;
  }
  if (local_28.bottom < (int)(in_ECX[0x4f] + local_94)) {
    in_ECX[0x4f] = local_28.top;
    if (local_28.bottom - local_28.top < (int)local_94) {
      in_ECX[0x3d0] = 1;
      in_ECX[0x3df] = 1;
      local_94 = local_28.bottom - local_28.top;
    }
    in_ECX[0x3cc] = 0;
  }
LAB_008206cb:
  if (((!bVar3) && (in_ECX[0x3df] != 0)) &&
     ((in_ECX[0x3e0] != 0 && ((in_ECX[0x44c] == 0 && (in_ECX[0x44d] == 0)))))) {
    iVar7 = GetSystemMetrics(2);
    local_98 = local_98 + iVar7;
    BVar6 = IsRectEmpty((RECT *)(in_ECX + 0x454));
    if (BVar6 == 0) {
      iVar7 = GetSystemMetrics(2);
      in_ECX[0x456] = in_ECX[0x456] + iVar7;
    }
  }
  in_ECX[0x52] = local_98;
  in_ECX[0x53] = local_94;
  AVar15 = CMFCPopupMenu::GetAnimationType(0);
  if (((AVar15 != 0) || (in_ECX[0x3dd] != 0)) || (DAT_00a127ac != 0)) {
    if (DAT_00a127ac == 0) {
      local_98 = local_98 + in_ECX[0x417];
      local_94 = local_94 + in_ECX[0x417];
    }
    if (in_ECX[0x55] == 0) {
      uVar18 = 0x14;
      iVar7 = in_ECX[0x4f];
      iVar12 = in_ECX[0x4e] - (-(uint)(uVar9 != 0) & local_98);
    }
    else {
      uVar18 = 0x16;
      iVar7 = -1;
      iVar12 = -1;
    }
    FUN_00797e71(0,iVar12,iVar7,local_98,local_94,uVar18);
    if (DAT_00a127ac != 0) {
      pcVar1 = *(code **)(*piVar5 + 0x3e4);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  if (((in_ECX[0x417] != 0) && (DAT_00a127ac == 0)) &&
     ((iVar7 = in_ECX[0x56], iVar7 != 0 && (*(int *)(iVar7 + 0x6c) != 0)))) {
    iVar12 = in_ECX[0x3d2];
    in_ECX[0x3d2] = 1;
    this = *(CWnd **)(iVar7 + 0x6c);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    local_38._0_4_ = 0;
    local_38._4_4_ = 0;
    local_38._8_4_ = 0;
    local_2c = 0;
    GetWindowRect((HWND)in_ECX[8],(LPRECT)local_38);
    local_68.right = in_ECX[0x417];
    local_68.bottom = local_68.right + local_2c;
    if (uVar9 == 0) {
      local_68.left = local_38._8_4_ + 1;
    }
    else {
      local_68.left = (local_38._0_4_ - local_68.right) + -1;
    }
    local_68.right = local_68.left + local_68.right;
    local_68.top = local_38._4_4_;
    CWnd::ScreenToClient(this,&local_68);
    BVar6 = IntersectRect(&local_18,&local_68,(RECT *)(in_ECX[0x56] + 0x54));
    if (BVar6 != 0) {
      InvalidateRect(*(HWND *)(this + 0x20),(RECT *)(in_ECX[0x56] + 0x54),1);
      UpdateWindow(*(HWND *)(this + 0x20));
    }
    local_48._4_4_ = local_2c + 1;
    local_48._0_4_ = local_38._0_4_;
    local_48._8_4_ = local_38._8_4_ + in_ECX[0x417];
    local_3c = local_48._4_4_ + in_ECX[0x417];
    CWnd::ScreenToClient(this,(tagRECT *)local_48);
    BVar6 = IntersectRect(&local_18,(RECT *)local_48,(RECT *)(in_ECX[0x56] + 0x54));
    if (BVar6 != 0) {
      InvalidateRect(*(HWND *)(this + 0x20),(RECT *)(in_ECX[0x56] + 0x54),1);
      UpdateWindow(*(HWND *)(this + 0x20));
    }
    in_ECX[0x3d2] = iVar12;
  }
  if (((in_ECX[0x3df] != 0) && (in_ECX[0x3e0] != 0)) &&
     ((in_ECX[0x44c] == 0 && (in_ECX[0x44d] == 0)))) {
    RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CMFCColorPopupMenu[120], CMFCPopupMenu[120], CMFCRibbonMiniToolBar[120], CMFCRibbonPanelMenu[120] */
/* 00820add  FUN_00820add  175 bytes, 0 callers */

void FUN_00820add(void)

{
  code *pcVar1;
  int *piVar2;
  HMENU hMenu;
  int *in_ECX;
  HMENU pHVar3;
  
  if (((DAT_00a127ac != 0) && (in_ECX[0x56] != 0)) && (*(int *)(in_ECX[0x56] + 0xb0) == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x1c8);
    guard_check_icall();
    piVar2 = (int *)(*pcVar1)();
    pcVar1 = *(code **)(*piVar2 + 0x43c);
    guard_check_icall();
    hMenu = (HMENU)(*pcVar1)();
    if (hMenu == (HMENU)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    pcVar1 = *(code **)(*(int *)in_ECX[0x56] + 0xd0);
    pHVar3 = hMenu;
    guard_check_icall(hMenu);
    (*pcVar1)();
    DestroyMenu(hMenu);
    piVar2 = (int *)FUN_0081d529();
    if (piVar2 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar2 + 0x1e0);
      guard_check_icall(pHVar3);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCColorPopupMenu[126], CMFCPopupMenu[126], CMFCRibbonMiniToolBar[126], CMFCRibbonPanelMenu[126] */
/* 008212dd  FUN_008212dd  994 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008212dd(int param_1,int param_2)

{
  CObject *pCVar1;
  int *piVar2;
  int iVar3;
  CObject *pCVar4;
  int *piVar5;
  int *in_ECX;
  code *pcVar6;
  tagPOINT local_4c;
  CObject *local_44;
  int local_40;
  undefined1 local_3c [4];
  CObject *local_38;
  CObject *local_34;
  int *local_30;
  int *local_2c;
  CObject *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x8212e9;
  if ((in_ECX[0x56] == 0) || (local_40 = *(int *)(in_ECX[0x56] + 0xbc), local_40 == 0))
  goto LAB_00821518;
  local_4c.x = param_1;
  local_4c.y = param_2;
  local_2c = in_ECX;
  ClientToScreen((HWND)in_ECX[8],&local_4c);
  local_28 = DAT_00a13a1c;
  pCVar1 = DAT_00a13a1c;
  if ((DAT_00a13a1c == (CObject *)0x0) &&
     (pCVar1 = (CObject *)FUN_00792b4c(), local_28 = pCVar1, pCVar1 == (CObject *)0x0))
  goto LAB_00821518;
  local_28 = pCVar1;
  local_44 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar1);
  if (local_44 == (CObject *)0x0) {
    local_38 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWndEx_00994040,pCVar1);
    if (local_38 == (CObject *)0x0) {
      local_38 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleIPFrameWndEx_00994be0,pCVar1);
      if (local_38 == (CObject *)0x0) {
        pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleDocIPFrameWndEx_00994f98,pCVar1);
        if (pCVar1 == (CObject *)0x0) goto LAB_00821518;
        piVar2 = (int *)FUN_0084ef1b(local_40);
        local_34 = pCVar1 + 0x1a4;
      }
      else {
        piVar2 = (int *)FUN_0084e4bc(local_40);
        local_34 = local_38 + 0x1a8;
      }
    }
    else {
      piVar2 = (int *)FUN_0084afa7(local_40);
      local_34 = local_38 + 0x134;
    }
  }
  else {
    piVar2 = (int *)FUN_0084c801(local_40);
    local_34 = local_44 + 0x350;
  }
  piVar5 = local_2c;
  local_30 = piVar2;
  if (local_34 == (CObject *)0x0) goto LAB_00821518;
  if (piVar2 == (int *)0x0) {
    iVar3 = FUN_004054a0(*(int *)(local_2c[0x56] + 0x2c) + -0x10);
    local_38 = (CObject *)(iVar3 + 0x10);
    local_8 = 0;
    FUN_007fa476(0x26);
    pcVar6 = *(code **)(*piVar5 + 0x1fc);
    guard_check_icall(local_28,local_40,local_38);
    piVar2 = (int *)(*pcVar6)();
    local_30 = piVar2;
    if (piVar2 == (int *)0x0) {
      FUN_00406b10();
      goto LAB_00821518;
    }
    FUN_0087b180(piVar2);
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  else {
    pcVar6 = *(code **)(*piVar2 + 0x224);
    guard_check_icall(1,0,1);
    (*pcVar6)();
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetWindowRect((HWND)piVar2[8],&local_24);
    local_24.right = local_24.right - local_24.left;
    local_24.left = local_4c.x;
    local_24.right = local_4c.x + local_24.right;
    local_24.bottom = local_24.bottom - local_24.top;
    local_24.top = local_4c.y;
    local_24.bottom = local_4c.y + local_24.bottom;
    pcVar6 = *(code **)(*piVar2 + 0x168);
    guard_check_icall();
    iVar3 = (*pcVar6)();
    if (iVar3 == 0) {
      pcVar6 = *(code **)(*piVar2 + 0x234);
      guard_check_icall(&local_24,1,0);
      (*pcVar6)();
    }
    else {
      pcVar6 = *(code **)(*piVar2 + 0x1fc);
      guard_check_icall(local_24.left,local_24.top,local_24.right,local_24.bottom,3,1);
      piVar2 = local_30;
      (*pcVar6)();
    }
  }
  pCVar1 = local_28;
  local_34 = (CObject *)0x1;
  if (local_44 == (CObject *)0x0) {
    local_38 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWndEx_00994040,local_28);
    if (local_38 != (CObject *)0x0) {
      pcVar6 = *(code **)(*(int *)local_38 + 0x1ec);
LAB_00821599:
      guard_check_icall(local_2c,piVar2);
      goto LAB_008215a8;
    }
    local_38 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleIPFrameWndEx_00994be0,pCVar1);
    if ((local_38 != (CObject *)0x0) ||
       (local_38 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleDocIPFrameWndEx_00994f98,pCVar1),
       pCVar4 = local_34, local_38 != (CObject *)0x0)) {
      pcVar6 = *(code **)(*(int *)local_38 + 0x208);
      goto LAB_00821599;
    }
  }
  else {
    pcVar6 = *(code **)(*(int *)local_44 + 0x208);
    guard_check_icall(local_2c,piVar2);
LAB_008215a8:
    pCVar4 = (CObject *)(*pcVar6)();
    pCVar1 = local_28;
  }
  if (pCVar4 == (CObject *)0x0) {
    pcVar6 = *(code **)(*piVar2 + 0x60);
    guard_check_icall();
    (*pcVar6)();
    pcVar6 = *(code **)(*piVar2 + 4);
    guard_check_icall(1);
    (*pcVar6)();
  }
  else {
    pcVar6 = *(code **)(*piVar2 + 0x244);
    guard_check_icall(pCVar1,1);
    (*pcVar6)();
    pcVar6 = *(code **)(*piVar2 + 0x2a4);
    guard_check_icall(local_3c,0);
    piVar5 = (int *)(*pcVar6)();
    local_24.left = local_4c.x;
    local_24.right = local_4c.x + *piVar5;
    local_24.top = local_4c.y;
    local_24.bottom = local_4c.y + piVar5[1];
    pcVar6 = *(code **)(*piVar2 + 0x1fc);
    guard_check_icall(local_4c.x,local_4c.y,local_24.right,local_24.bottom,3,1);
    piVar2 = local_30;
    (*pcVar6)();
    pcVar6 = *(code **)(*piVar2 + 0x210);
    guard_check_icall();
    (*pcVar6)();
    pcVar6 = *(code **)(*(int *)local_28 + 0x178);
    guard_check_icall(1);
    (*pcVar6)();
    pcVar6 = *(code **)(*piVar2 + 0x228);
    guard_check_icall(1);
    iVar3 = (*pcVar6)();
    if (iVar3 != 0) {
      FUN_00844366(local_2c);
    }
  }
LAB_00821518:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorPopupMenu[40], CMFCPopupMenu[40], CMFCRibbonMiniToolBar[40], CMFCRibbonPanelMenu[40] */
/* 00821cc0  FUN_00821cc0  112 bytes, 0 callers */

undefined4
FUN_00821cc0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int *in_ECX;
  
  if (param_5 == (undefined4 *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    if (((short)param_1 == 3) && (param_3 != 0)) {
      pcVar1 = *(code **)(*in_ECX + 0x1c8);
      guard_check_icall();
      piVar3 = (int *)(*pcVar1)();
      if (piVar3 != (int *)0x0) {
        pcVar1 = *(code **)(*piVar3 + 0xa0);
        guard_check_icall(param_1,param_2,param_3,param_4,param_5);
        uVar2 = (*pcVar1)();
        return uVar2;
      }
    }
    *param_5 = 0;
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCColorPopupMenu[39], CMFCPopupMenu[39], CMFCRibbonMiniToolBar[39], CMFCRibbonPanelMenu[39] */
/* 00821d30  FUN_00821d30  84 bytes, 0 callers */

undefined4 FUN_00821d30(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int *in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x1c8);
    guard_check_icall();
    piVar3 = (int *)(*pcVar1)();
    if (piVar3 == (int *)0x0) {
      *param_1 = 0;
      uVar2 = 1;
    }
    else {
      pcVar1 = *(code **)(*piVar3 + 0x9c);
      guard_check_icall(param_1);
      uVar2 = (*pcVar1)();
    }
  }
  return uVar2;
}




/* vtable slots: CMFCColorPopupMenu[41], CMFCPopupMenu[41], CMFCRibbonMiniToolBar[41], CMFCRibbonPanelMenu[41] */
/* 00821d84  FUN_00821d84  210 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00821d84(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  BSTR pOVar4;
  int *piVar5;
  int *in_ECX;
  
  if (param_5 == (undefined4 *)0x0) {
    uVar2 = 0x80070057;
  }
  else if ((((short)param_1 == 3) && (param_3 == 0)) && (in_ECX[0x56] != 0)) {
    iVar3 = FUN_004054a0(*(int *)(in_ECX[0x56] + 0x2c) + -0x10);
    uVar2 = 0;
    FUN_007fa476(0x26);
    if (*(int *)(iVar3 + 4) == 0) {
      uVar2 = 1;
    }
    else {
      pOVar4 = SysAllocStringLen((OLECHAR *)(iVar3 + 0x10),*(UINT *)(iVar3 + 4));
      if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00407010();
      }
      *param_5 = pOVar4;
    }
    FUN_00406b10();
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x1c8);
    guard_check_icall();
    piVar5 = (int *)(*pcVar1)();
    if (piVar5 == (int *)0x0) {
      uVar2 = 1;
    }
    else {
      pcVar1 = *(code **)(*piVar5 + 0xa4);
      guard_check_icall(param_1,param_2,param_3,param_4,param_5);
      uVar2 = (*pcVar1)();
    }
  }
  return uVar2;
}




/* vtable slots: CMFCColorPopupMenu[38], CMFCPopupMenu[38], CMFCRibbonMiniToolBar[38], CMFCRibbonPanelMenu[38] */
/* 00821e57  get_accParent  82 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual long __thiscall CMFCPopupMenu::get_accParent(struct IDispatch * *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __thiscall CMFCPopupMenu::get_accParent(CMFCPopupMenu *this,IDispatch **param_1)

{
  long lVar1;
  CObject *pCVar2;
  HRESULT HVar3;
  
  if (param_1 == (IDispatch **)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    *param_1 = (IDispatch *)0x0;
    if (((*(int *)(this + 0x158) != 0) &&
        (pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,
                                     *(CObject **)(*(int *)(this + 0x158) + 0x6c)),
        pCVar2 != (CObject *)0x0)) && (*(int *)(pCVar2 + 0x20) != 0)) {
      HVar3 = AccessibleObjectFromWindow
                        (*(HWND *)(pCVar2 + 0x20),0xfffffffc,(IID *)&DAT_009a9c2c,param_1);
      return HVar3;
    }
    lVar1 = 1;
  }
  return lVar1;
}




/* vtable slots: CMFCColorPopupMenu[44], CMFCPopupMenu[44], CMFCRibbonMiniToolBar[44], CMFCRibbonPanelMenu[44] */
/* 00821ea9  FUN_00821ea9  125 bytes, 0 callers */

undefined4
FUN_00821ea9(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined2 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int *in_ECX;
  
  if (param_5 == (undefined2 *)0x0) {
    uVar2 = 0x80070057;
  }
  else if (((short)param_1 == 3) && (param_3 == 0)) {
    *param_5 = 3;
    uVar2 = 0;
    *(undefined4 *)(param_5 + 4) = 0xb;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x1c8);
    guard_check_icall();
    piVar3 = (int *)(*pcVar1)();
    if (piVar3 == (int *)0x0) {
      uVar2 = 1;
    }
    else {
      pcVar1 = *(code **)(*piVar3 + 0xb0);
      guard_check_icall(param_1,param_2,param_3,param_4,param_5);
      uVar2 = (*pcVar1)();
    }
  }
  return uVar2;
}




/* vtable slots: CMFCColorPopupMenu[45], CMFCPopupMenu[45], CMFCRibbonMiniToolBar[45], CMFCRibbonPanelMenu[45] */
/* 00821f26  FUN_00821f26  125 bytes, 0 callers */

undefined4
FUN_00821f26(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined2 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int *in_ECX;
  
  if (param_5 == (undefined2 *)0x0) {
    uVar2 = 0x80070057;
  }
  else if (((short)param_1 == 3) && (param_3 == 0)) {
    *param_5 = 3;
    uVar2 = 0;
    *(undefined4 *)(param_5 + 4) = 0x100004;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x1c8);
    guard_check_icall();
    piVar3 = (int *)(*pcVar1)();
    if (piVar3 == (int *)0x0) {
      uVar2 = 1;
    }
    else {
      pcVar1 = *(code **)(*piVar3 + 0xb4);
      guard_check_icall(param_1,param_2,param_3,param_4,param_5);
      uVar2 = (*pcVar1)();
    }
  }
  return uVar2;
}




/* vtable slots: CMFCColorPopupMenu[127] */
/* 00824ce0  FUN_00824ce0  269 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00824ce0(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int in_ECX;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  if ((param_3 == 0) || (param_2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorMenuButton_00a00c0c,
                              *(CObject **)(in_ECX + 0x158));
  if (pCVar2 != (CObject *)0x0) {
    iVar3 = FUN_0078e624(0xe68);
    if (iVar3 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_0082200a(in_ECX + 0x1178,*(undefined4 *)(pCVar2 + 0x20));
    }
    uVar10 = 0;
    uVar9 = 0;
    pcVar1 = *(code **)(*piVar4 + 0x450);
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0x50402808;
    guard_check_icall(param_1,0x50402808,param_2,0,0,0,0);
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      FUN_00797ece(param_3);
      iVar3 = *piVar4;
      pcVar1 = *(code **)(iVar3 + 0x1c0);
      guard_check_icall(param_1,uVar6,param_2,uVar7,uVar8,uVar9,uVar10);
      uVar5 = (*pcVar1)();
      pcVar1 = *(code **)(iVar3 + 0x1e4);
      guard_check_icall(uVar5 | 0x30);
      (*pcVar1)();
      pcVar1 = *(code **)(*piVar4 + 0x1ec);
      guard_check_icall(0xf000);
      (*pcVar1)();
      return piVar4;
    }
    pcVar1 = *(code **)(*piVar4 + 4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  return (int *)0x0;
}




/* vtable slots: CMFCColorPopupMenu[10] */
/* 00824dee  FUN_00824dee  6 bytes, 0 callers */

undefined ** FUN_00824dee(void)

{
  return &PTR_FUN_0098f294;
}




/* vtable slots: CMFCColorPopupMenu[0] */
/* 00824df4  FUN_00824df4  6 bytes, 0 callers */

undefined ** FUN_00824df4(void)

{
  return &PTR_s_CMFCColorPopupMenu_0098f234;
}



