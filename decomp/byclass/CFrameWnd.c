/* CFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFrameWnd[96], CFrameWndEx[96], CMDIFrameWnd[96], CMDIFrameWndEx[96], CMFCColorPopupMenu[96], CMFCDropDownFrame[96], CMFCPopupMenu[96], CMFCRibbonMiniToolBar[96], CMFCRibbonPanelMenu[96], CMFCShadowWnd[96], CMainFrame[96], CMiniDockFrameWnd[96], CMiniFrameWnd[96], COleCntrFrameWnd[96], COleCntrFrameWndEx[96], COleDocIPFrameWnd[96], COleDocIPFrameWndEx[96], COleIPFrameWnd[96], COleIPFrameWndEx[96] */
/* 005668a0  FUN_005668a0  20 bytes, 0 callers */

undefined4 FUN_005668a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xd4);
}




/* vtable slots: CFrameWnd[1] */
/* 00799785  FUN_00799785  51 bytes, 0 callers */

void FUN_00799785(byte param_1)

{
  FUN_00799509();
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




/* vtable slots: CFrameWnd[95], CFrameWndEx[95], CMDIFrameWnd[95], CMDIFrameWndEx[95], CMFCColorPopupMenu[95], CMFCDropDownFrame[95], CMFCPopupMenu[95], CMFCRibbonMiniToolBar[95], CMFCRibbonPanelMenu[95], CMFCShadowWnd[95], CMainFrame[95], CMiniDockFrameWnd[95], CMiniFrameWnd[95], COleCntrFrameWnd[95], COleCntrFrameWndEx[95], COleDocIPFrameWnd[95], COleDocIPFrameWndEx[95], COleIPFrameWnd[95], COleIPFrameWndEx[95] */
/* 007997b8  ActivateFrame  84 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CFrameWnd::ActivateFrame(int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CFrameWnd::ActivateFrame(CFrameWnd *this,int param_1)

{
  BOOL BVar1;
  
  if (param_1 == -1) {
    BVar1 = IsWindowVisible(*(HWND *)(this + 0x20));
    if (BVar1 == 0) {
      param_1 = 1;
    }
    else {
      BVar1 = IsIconic(*(HWND *)(this + 0x20));
      if (BVar1 != 0) {
        param_1 = 9;
      }
    }
  }
  BringToTop(this,param_1);
  if (param_1 != -1) {
    FUN_00797f20(param_1);
    BringToTop(this,param_1);
  }
  return;
}




/* vtable slots: CFrameWnd[65], CFrameWndEx[65], CMDIChildWnd[65], CMDIChildWndEx[65], CMDIFrameWnd[65], CMDIFrameWndEx[65], CMFCColorPopupMenu[65], CMFCDropDownFrame[65], CMFCPopupMenu[65], CMFCRibbonMiniToolBar[65], CMFCRibbonPanelMenu[65], CMFCShadowWnd[65], CMainFrame[65], CMiniDockFrameWnd[65], CMiniFrameWnd[65], COleCntrFrameWnd[65], COleCntrFrameWndEx[65], COleDocIPFrameWnd[65], COleDocIPFrameWndEx[65], COleIPFrameWnd[65], COleIPFrameWndEx[65] */
/* 00799880  FUN_00799880  299 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x0079995d) */
/* WARNING: Removing unreachable block (ram,0x00799950) */
/* WARNING: Removing unreachable block (ram,0x0079995b) */
/* WARNING: Removing unreachable block (ram,0x00799989) */

undefined1 * FUN_00799880(void)

{
  undefined1 *puVar1;
  CWnd *pCVar2;
  HWND pHVar3;
  BOOL BVar4;
  CWnd *pCVar5;
  int iVar6;
  LRESULT LVar7;
  CWnd *in_ECX;
  UINT uCmd;
  
  puVar1 = &LAB_009441f8;
  *(int *)(in_ECX + 0xe4) = *(int *)(in_ECX + 0xe4) + 1;
  if (*(uint *)(in_ECX + 0xe4) < 2) {
    pCVar2 = CWnd::GetTopLevelParent(in_ECX);
    if (pCVar2 == (CWnd *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    uCmd = 5;
    pHVar3 = GetDesktopWindow();
    pHVar3 = GetWindow(pHVar3,uCmd);
    puVar1 = (undefined1 *)0x0;
    if (pHVar3 != (HWND)0x0) {
      do {
        BVar4 = IsWindowEnabled(pHVar3);
        if ((((BVar4 != 0) && (pCVar5 = CWnd::FromHandlePermanent(pHVar3), pCVar5 != (CWnd *)0x0))
            && (iVar6 = AfxIsDescendant(*(HWND__ **)(pCVar2 + 0x20),pHVar3), iVar6 != 0)) &&
           (LVar7 = SendMessageW(pHVar3,0x36c,0,0), LVar7 == 0)) {
          EnableWindow(pHVar3,0);
          FUN_0079c90d(0,pHVar3);
        }
        pHVar3 = GetWindow(pHVar3,2);
      } while (pHVar3 != (HWND)0x0);
      puVar1 = (undefined1 *)0x0;
    }
  }
  return puVar1;
}




/* vtable slots: CFrameWnd[89], CFrameWndEx[89], CMDIChildWnd[89], CMDIChildWndEx[89], CMDIFrameWnd[89], CMDIFrameWndEx[89], CMFCColorPopupMenu[89], CMFCDropDownFrame[89], CMFCPopupMenu[89], CMFCRibbonMiniToolBar[89], CMFCRibbonPanelMenu[89], CMFCShadowWnd[89], CMainFrame[89], CMiniDockFrameWnd[89], CMiniFrameWnd[89], COleCntrFrameWnd[89], COleCntrFrameWndEx[89], COleDocIPFrameWnd[89], COleDocIPFrameWndEx[89], COleIPFrameWnd[89], COleIPFrameWndEx[89] */
/* 007999de  FUN_007999de  215 bytes, 0 callers */

undefined4
FUN_007999de(undefined4 param_1,wchar_t *param_2,undefined4 param_3,int *param_4,int param_5,
            LPCWSTR param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  HMENU hMenu;
  undefined4 local_8;
  
  hMenu = (HMENU)0x0;
  local_8 = 0;
  if (param_6 != (LPCWSTR)0x0) {
    iVar2 = FUN_0079dd6d();
    hMenu = LoadMenuW(*(HINSTANCE *)(iVar2 + 0xc),param_6);
    if (hMenu == (HMENU)0x0) {
      pcVar1 = *(code **)(*in_ECX + 0x120);
      guard_check_icall();
      (*pcVar1)();
      return 0;
    }
  }
  iVar2 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar2 = FUN_008f899d(param_2);
  }
  ATL::CSimpleStringT<wchar_t,0>::SetString
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x3c),param_2,iVar2);
  pcVar1 = *(code **)(*in_ECX + 0x5c);
  if (param_5 != 0) {
    local_8 = *(undefined4 *)(param_5 + 0x20);
  }
  guard_check_icall(param_7,param_1,param_2,param_3,*param_4,param_4[1],param_4[2] - *param_4,
                    param_4[3] - param_4[1],local_8,hMenu,param_8);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if (hMenu != (HMENU)0x0) {
      DestroyMenu(hMenu);
    }
    return 0;
  }
  return 1;
}




/* vtable slots: CFrameWnd[108], CMDIChildWnd[108], CMDIChildWndEx[108], CMFCColorPopupMenu[108], CMFCDropDownFrame[108], CMFCPopupMenu[108], CMFCRibbonMiniToolBar[108], CMFCRibbonPanelMenu[108], CMFCShadowWnd[108], CMainFrame[108], CMiniDockFrameWnd[108], CMiniFrameWnd[108], COleCntrFrameWnd[108], COleCntrFrameWndEx[108], COleDocIPFrameWnd[108], COleDocIPFrameWndEx[108], COleIPFrameWnd[108], COleIPFrameWndEx[108] */
/* 00799bae  FUN_00799bae  23 bytes, 1 callers */

void FUN_00799bae(undefined4 param_1)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 0x118) = *(uint *)(in_ECX + 0x118) | 1;
  *(undefined4 *)(in_ECX + 0xec) = param_1;
  return;
}




/* vtable slots: CFrameWnd[66], CFrameWndEx[66], CMDIChildWnd[66], CMDIChildWndEx[66], CMDIFrameWnd[66], CMDIFrameWndEx[66], CMFCColorPopupMenu[66], CMFCDropDownFrame[66], CMFCPopupMenu[66], CMFCRibbonMiniToolBar[66], CMFCRibbonPanelMenu[66], CMFCShadowWnd[66], CMainFrame[66], CMiniDockFrameWnd[66], CMiniFrameWnd[66], COleCntrFrameWnd[66], COleCntrFrameWndEx[66], COleDocIPFrameWnd[66], COleDocIPFrameWndEx[66], COleIPFrameWnd[66], COleIPFrameWndEx[66] */
/* 00799d17  FUN_00799d17  110 bytes, 0 callers */

void FUN_00799d17(void)

{
  int iVar1;
  int *piVar2;
  BOOL BVar3;
  int in_ECX;
  int iVar4;
  
  if (((*(int *)(in_ECX + 0xe4) != 0) &&
      (iVar1 = *(int *)(in_ECX + 0xe4) + -1, *(int *)(in_ECX + 0xe4) = iVar1, iVar1 == 0)) &&
     (piVar2 = *(int **)(in_ECX + 0xe8), piVar2 != (int *)0x0)) {
    iVar1 = 0;
    if (*piVar2 != 0) {
      iVar4 = 0;
      do {
        BVar3 = IsWindow(*(HWND *)(iVar4 + (int)piVar2));
        if (BVar3 != 0) {
          EnableWindow(*(HWND *)(*(int *)(in_ECX + 0xe8) + iVar4),1);
        }
        piVar2 = *(int **)(in_ECX + 0xe8);
        iVar1 = iVar1 + 1;
        iVar4 = iVar1 * 4;
      } while (piVar2[iVar1] != 0);
    }
    thunk_FUN_008f43b0(piVar2);
    *(undefined4 *)(in_ECX + 0xe8) = 0;
  }
  return;
}




/* vtable slots: CFrameWnd[109], CFrameWndEx[109], CMDIChildWnd[109], CMDIChildWndEx[109], CMDIFrameWnd[109], CMDIFrameWndEx[109], CMFCColorPopupMenu[109], CMFCDropDownFrame[109], CMFCPopupMenu[109], CMFCRibbonMiniToolBar[109], CMFCRibbonPanelMenu[109], CMFCShadowWnd[109], CMainFrame[109], CMiniDockFrameWnd[109], CMiniFrameWnd[109], COleCntrFrameWnd[109], COleCntrFrameWndEx[109], COleDocIPFrameWnd[109], COleDocIPFrameWndEx[109], COleIPFrameWnd[109], COleIPFrameWndEx[109] */
/* 00799d85  FUN_00799d85  125 bytes, 0 callers */

void FUN_00799d85(void)

{
  BOOL BVar1;
  HWND pHVar2;
  int iVar3;
  int in_ECX;
  tagMSG local_20;
  
  if (*(int *)(in_ECX + 0x94) != 0) {
    BVar1 = PeekMessageW(&local_20,*(HWND *)(in_ECX + 0x20),0x367,0x367,3);
    if (BVar1 == 0) {
      PostMessageW(*(HWND *)(in_ECX + 0x20),0x367,0,0);
    }
    pHVar2 = GetCapture();
    if (pHVar2 == *(HWND *)(in_ECX + 0x20)) {
      ReleaseCapture();
    }
    iVar3 = FUN_00792b4c();
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    *(undefined4 *)(in_ECX + 0x94) = 0;
    *(undefined4 *)(iVar3 + 0x94) = 0;
    PostMessageW(*(HWND *)(in_ECX + 0x20),0x36a,0,0);
  }
  return;
}




/* vtable slots: CFrameWnd[91], CFrameWndEx[91], CMDIChildWnd[91], CMDIChildWndEx[91], CMDIFrameWnd[91], CMDIFrameWndEx[91], CMFCColorPopupMenu[91], CMFCDropDownFrame[91], CMFCPopupMenu[91], CMFCRibbonMiniToolBar[91], CMFCRibbonPanelMenu[91], CMFCShadowWnd[91], CMainFrame[91], CMiniDockFrameWnd[91], CMiniFrameWnd[91], COleCntrFrameWnd[91], COleCntrFrameWndEx[91], COleDocIPFrameWnd[91], COleDocIPFrameWndEx[91], COleIPFrameWnd[91], COleIPFrameWndEx[91] */
/* 00799e03  FUN_00799e03  20 bytes, 0 callers */

undefined4 FUN_00799e03(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xdc) != 0) {
    return *(undefined4 *)(*(int *)(in_ECX + 0xdc) + 0x80);
  }
  return 0;
}




/* vtable slots: CFrameWnd[107], CFrameWndEx[107], CMDIChildWnd[107], CMDIChildWndEx[107], CMDIFrameWnd[107], CMDIFrameWndEx[107], CMFCColorPopupMenu[107], CMFCDropDownFrame[107], CMFCPopupMenu[107], CMFCRibbonMiniToolBar[107], CMFCRibbonPanelMenu[107], CMFCShadowWnd[107], CMainFrame[107], CMiniDockFrameWnd[107], CMiniFrameWnd[107], COleCntrFrameWnd[107], COleCntrFrameWndEx[107], COleDocIPFrameWnd[107], COleDocIPFrameWndEx[107], COleIPFrameWnd[107], COleIPFrameWndEx[107] */
/* 00799e6a  FUN_00799e6a  69 bytes, 0 callers */

int FUN_00799e6a(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  
  iVar4 = in_ECX[0x23];
  pcVar1 = *(code **)(*in_ECX + 0x16c);
  guard_check_icall();
  piVar2 = (int *)(*pcVar1)();
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0xf0);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      iVar4 = iVar3;
    }
  }
  return iVar4;
}




/* vtable slots: CFrameWnd[27], CFrameWndEx[27], CMDIChildWnd[27], CMDIChildWndEx[27], CMDIFrameWnd[27], CMDIFrameWndEx[27], CMFCColorPopupMenu[27], CMFCDropDownFrame[27], CMFCPopupMenu[27], CMFCRibbonMiniToolBar[27], CMFCRibbonPanelMenu[27], CMFCShadowWnd[27], CMainFrame[27], CMiniDockFrameWnd[27], CMiniFrameWnd[27], COleCntrFrameWnd[27], COleCntrFrameWndEx[27], COleDocIPFrameWnd[27], COleDocIPFrameWndEx[27], COleIPFrameWnd[27], COleIPFrameWndEx[27] */
/* 00799f6b  GetMenu  44 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CMenu * __thiscall CFrameWnd::GetMenu(void)const 
   
   Library: Visual Studio 2015 Release */

CMenu * __thiscall CFrameWnd::GetMenu(CFrameWnd *this)

{
  HMENU__ *pHVar1;
  CMenu *pCVar2;
  undefined **ppuStack_8;
  
  if (*(int *)(this + 0x100) == 1) {
    ppuStack_8 = (undefined **)0x799f7f;
    pHVar1 = ::GetMenu(*(HWND *)(this + 0x20));
  }
  else {
    if (*(int *)(this + 0x100) != 2) {
      ppuStack_8 = &PTR_vftable_00a001c0;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&ppuStack_8,&DAT_009ea07c);
    }
    pHVar1 = *(HMENU__ **)(this + 0x104);
  }
  ppuStack_8 = (undefined **)0x799f96;
  pCVar2 = CMenu::FromHandle(pHVar1);
  return pCVar2;
}




/* vtable slots: CFrameWnd[100], CFrameWndEx[100], CMDIChildWnd[100], CMDIChildWndEx[100], CMDIFrameWnd[100], CMDIFrameWndEx[100], CMFCColorPopupMenu[100], CMFCDropDownFrame[100], CMFCPopupMenu[100], CMFCRibbonMiniToolBar[100], CMFCRibbonPanelMenu[100], CMFCShadowWnd[100], CMainFrame[100], CMiniDockFrameWnd[100], CMiniFrameWnd[100], COleCntrFrameWnd[100], COleCntrFrameWndEx[100], COleDocIPFrameWnd[100], COleDocIPFrameWndEx[100], COleIPFrameWnd[100], COleIPFrameWndEx[100] */
/* 00799f97  FUN_00799f97  7 bytes, 0 callers */

undefined4 FUN_00799f97(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x100);
}




/* vtable slots: CFrameWnd[98], CFrameWndEx[98], CMDIChildWnd[98], CMDIChildWndEx[98], CMDIFrameWnd[98], CMDIFrameWndEx[98], CMFCColorPopupMenu[98], CMFCDropDownFrame[98], CMFCPopupMenu[98], CMFCRibbonMiniToolBar[98], CMFCRibbonPanelMenu[98], CMFCShadowWnd[98], CMainFrame[98], CMiniDockFrameWnd[98], CMiniFrameWnd[98], COleCntrFrameWnd[98], COleCntrFrameWndEx[98], COleDocIPFrameWnd[98], COleDocIPFrameWndEx[98], COleIPFrameWnd[98], COleIPFrameWndEx[98] */
/* 00799f9e  FUN_00799f9e  7 bytes, 0 callers */

undefined4 FUN_00799f9e(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xfc);
}




/* vtable slots: CFrameWnd[102], CFrameWndEx[102], CMDIFrameWnd[102], CMDIFrameWndEx[102], CMFCColorPopupMenu[102], CMFCDropDownFrame[102], CMFCPopupMenu[102], CMFCRibbonMiniToolBar[102], CMFCRibbonPanelMenu[102], CMFCShadowWnd[102], CMainFrame[102], CMiniDockFrameWnd[102], CMiniFrameWnd[102], COleCntrFrameWnd[102], COleCntrFrameWndEx[102], COleDocIPFrameWnd[102], COleDocIPFrameWndEx[102], COleIPFrameWnd[102], COleIPFrameWndEx[102] */
/* 00799fa5  GetMessageBar  16 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CWnd * __thiscall CFrameWnd::GetMessageBar(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

CWnd * __thiscall CFrameWnd::GetMessageBar(CFrameWnd *this)

{
  CWnd *pCVar1;
  
  pCVar1 = CWnd::GetDescendantWindow(*(HWND__ **)(this + 0x20),0xe801,1);
  return pCVar1;
}




/* vtable slots: CFrameWnd[10], COleCntrFrameWnd[10] */
/* 00799fb5  FUN_00799fb5  6 bytes, 0 callers */

undefined ** FUN_00799fb5(void)

{
  return &PTR_FUN_0097dcc0;
}




/* vtable slots: CFrameWnd[93], CFrameWndEx[93], CMDIChildWnd[93], CMDIChildWndEx[93], CMDIFrameWnd[93], CMDIFrameWndEx[93], CMFCColorPopupMenu[93], CMFCDropDownFrame[93], CMFCPopupMenu[93], CMFCRibbonMiniToolBar[93], CMFCRibbonPanelMenu[93], CMFCShadowWnd[93], CMainFrame[93], CMiniDockFrameWnd[93], CMiniFrameWnd[93], COleCntrFrameWnd[93], COleCntrFrameWndEx[93], COleDocIPFrameWnd[93], COleDocIPFrameWndEx[93], COleIPFrameWnd[93], COleIPFrameWndEx[93] */
/* 00799fbb  GetMessageString  71 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CFrameWnd::GetMessageString(unsigned int,class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > &)const 
    public: virtual void __thiscall COleControl::GetMessageString(unsigned int,class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > &)const 
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

void GetMessageString(undefined4 param_1,CSimpleStringT<char,0> *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined2 *puVar3;
  
  pcVar1 = ATL::CSimpleStringT<char,0>::PrepareWrite(param_2,0xff);
  iVar2 = FUN_0078f2e1(param_1,pcVar1,0x100);
  if (iVar2 != 0) {
    puVar3 = (undefined2 *)FUN_008f16db(pcVar1,10);
    if (puVar3 != (undefined2 *)0x0) {
      *puVar3 = 0;
    }
  }
  ReleaseBuffer(0xffffffff);
  return;
}




/* vtable slots: CFrameWnd[0], COleCntrFrameWnd[0] */
/* 0079a002  FUN_0079a002  6 bytes, 0 callers */

undefined ** FUN_0079a002(void)

{
  return &PTR_s_CFrameWnd_0097d624;
}




/* vtable slots: CFrameWnd[90], CMFCColorPopupMenu[90], CMFCDropDownFrame[90], CMFCPopupMenu[90], CMFCRibbonMiniToolBar[90], CMFCRibbonPanelMenu[90], CMFCShadowWnd[90], CMainFrame[90], CMiniDockFrameWnd[90], CMiniFrameWnd[90], COleCntrFrameWnd[90], COleCntrFrameWndEx[90] */
/* 0079a184  FUN_0079a184  284 bytes, 4 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0079a184(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  HMENU pHVar4;
  int *in_ECX;
  UINT in_stack_ffffffc8;
  LPSTR in_stack_ffffffcc;
  int in_stack_ffffffd0;
  undefined4 local_1c;
  wchar_t *local_14;
  
  in_ECX[0x34] = (int)param_1;
  CStringT<>();
  local_1c = 0;
  iVar2 = FID_conflict_LoadStringA(param_1,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
  if (iVar2 != 0) {
    AfxExtractSubString((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                        (in_ECX + 0x3c),local_14,0,L'\n');
  }
  FUN_00790c5e(8);
  uVar3 = FUN_00799ec3(param_2,param_1);
  iVar2 = FUN_004054a0(in_ECX[0x3c] + -0x10);
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall(uVar3,iVar2 + 0x10,param_2,&DAT_00a00354,param_3,(uint)param_1 & 0xffff,0,
                    param_4);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    if (in_ECX[0x40] == 1) {
      pHVar4 = GetMenu((HWND)in_ECX[8]);
    }
    else {
      pHVar4 = (HMENU)in_ECX[0x41];
    }
    in_ECX[0x22] = (int)pHVar4;
    LoadAccelTable((uint)param_1 & 0xffff);
    if (param_4 == 0) {
      CWnd::SendMessageToDescendants((HWND__ *)in_ECX[8],0x364,0,0,1,1);
    }
    local_1c = 1;
  }
  FUN_00406b10();
  FUN_00406b10();
  return local_1c;
}




/* vtable slots: CFrameWnd[103], CMDIChildWnd[103], CMDIChildWndEx[103], CMDIFrameWnd[103], CMFCColorPopupMenu[103], CMFCDropDownFrame[103], CMFCPopupMenu[103], CMFCRibbonMiniToolBar[103], CMFCRibbonPanelMenu[103], CMFCShadowWnd[103], CMainFrame[103], CMiniDockFrameWnd[103], CMiniFrameWnd[103], COleCntrFrameWnd[103], COleCntrFrameWndEx[103], COleDocIPFrameWnd[103], COleDocIPFrameWndEx[103], COleIPFrameWnd[103], COleIPFrameWndEx[103] */
/* 0079a2a0  FUN_0079a2a0  117 bytes, 2 callers */

undefined4 FUN_0079a2a0(int param_1,RECT *param_2)

{
  LPRECT lprc1;
  int iVar1;
  BOOL BVar2;
  int in_ECX;
  
  if (param_1 == 1) {
    FUN_00794e3f(0,0xffff,0xe900,1,param_2,0,1);
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    lprc1 = (LPRECT)(in_ECX + 0x9c);
    if (param_2 == (RECT *)0x0) {
      iVar1 = FUN_0079a141();
      if (iVar1 != 0) {
        return 0;
      }
      SetRectEmpty(lprc1);
    }
    else {
      BVar2 = EqualRect(lprc1,param_2);
      if (BVar2 != 0) {
        return 0;
      }
      CopyRect(lprc1,param_2);
    }
  }
  return 1;
}




/* vtable slots: CFrameWnd[3], CMDIChildWnd[3], CMDIChildWndEx[3], CMFCDropDownFrame[3], CMFCShadowWnd[3], CMainFrame[3], CMiniDockFrameWnd[3], CMiniFrameWnd[3], COleDocIPFrameWnd[3], COleIPFrameWnd[3] */
/* 0079aebf  FUN_0079aebf  164 bytes, 5 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0079aebf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  CFrameWnd *in_ECX;
  undefined4 uVar3;
  CPushRoutingFrame local_20 [12];
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x79aecb;
  CPushRoutingFrame::CPushRoutingFrame(local_20,in_ECX);
  local_14 = *(int **)(in_ECX + 0xdc);
  uVar3 = 0;
  local_8 = 0;
  if (local_14 == (int *)0x0) {
LAB_0079af0a:
    iVar2 = FUN_007900e9(param_1,param_2,param_3,param_4);
    if (iVar2 == 0) {
      iVar2 = FUN_0079dd6d();
      if (*(int **)(iVar2 + 4) == (int *)0x0) goto LAB_0079af51;
      pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0xc);
      guard_check_icall(param_1,param_2,param_3,param_4);
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) goto LAB_0079af51;
    }
  }
  else {
    pcVar1 = *(code **)(*local_14 + 0xc);
    guard_check_icall(param_1,param_2,param_3,param_4);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) goto LAB_0079af0a;
  }
  uVar3 = 1;
LAB_0079af51:
  FUN_007996a0();
  return uVar3;
}




/* vtable slots: CFrameWnd[61], CMDIChildWnd[61], CMDIChildWndEx[61], CMFCColorPopupMenu[61], CMFCDropDownFrame[61], CMFCPopupMenu[61], CMFCRibbonMiniToolBar[61], CMFCRibbonPanelMenu[61], CMFCShadowWnd[61], CMainFrame[61], CMiniDockFrameWnd[61], CMiniFrameWnd[61], COleCntrFrameWnd[61], COleCntrFrameWndEx[61], COleDocIPFrameWnd[61], COleIPFrameWnd[61] */
/* 0079af63  FUN_0079af63  137 bytes, 4 callers */

undefined4 FUN_0079af63(uint param_1,int param_2)

{
  int iVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  
  uVar4 = param_1 & 0xffff;
  iVar1 = FUN_00792b4c();
  if (iVar1 != 0) {
    if ((((*(int *)(iVar1 + 0x94) == 0) || (param_2 != 0)) || (uVar4 == 0xe146)) ||
       ((uVar4 == 0xe147 || (uVar4 == 0xe145)))) {
      uVar3 = FUN_00793275(param_1,param_2);
    }
    else {
      LVar2 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x365,0,uVar4 + 0x10000);
      if (LVar2 == 0) {
        SendMessageW(*(HWND *)(in_ECX + 0x20),0x111,0xe147,0);
      }
      uVar3 = 1;
    }
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CFrameWnd[104], CFrameWndEx[104], CMDIChildWnd[104], CMDIChildWndEx[104], CMFCColorPopupMenu[104], CMFCDropDownFrame[104], CMFCPopupMenu[104], CMFCRibbonMiniToolBar[104], CMFCRibbonPanelMenu[104], CMFCShadowWnd[104], CMainFrame[104], CMiniDockFrameWnd[104], CMiniFrameWnd[104], COleCntrFrameWnd[104], COleCntrFrameWndEx[104], COleDocIPFrameWnd[104], COleDocIPFrameWndEx[104], COleIPFrameWnd[104], COleIPFrameWndEx[104] */
/* 0079b07c  OnCreateClient  37 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CFrameWnd::OnCreateClient(struct tagCREATESTRUCTA *,struct
   CCreateContext *)
    protected: virtual int __thiscall CFrameWnd::OnCreateClient(struct tagCREATESTRUCTW *,struct
   CCreateContext *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

undefined4 OnCreateClient(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (((param_2 != (int *)0x0) && (*param_2 != 0)) &&
     (iVar1 = FUN_00799b11(param_2,0xe900), iVar1 == 0)) {
    return 0;
  }
  return 1;
}




/* vtable slots: CFrameWnd[101], CMDIChildWnd[101], CMDIFrameWnd[101], CMFCColorPopupMenu[101], CMFCDropDownFrame[101], CMFCPopupMenu[101], CMFCRibbonMiniToolBar[101], CMFCRibbonPanelMenu[101], CMFCShadowWnd[101], CMainFrame[101], CMiniDockFrameWnd[101], CMiniFrameWnd[101], COleCntrFrameWnd[101], COleCntrFrameWndEx[101], COleDocIPFrameWnd[101], COleIPFrameWnd[101] */
/* 0079bd2d  FUN_0079bd2d  742 bytes, 5 callers */

void FUN_0079bd2d(int param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  HWND pHVar6;
  HMENU pHVar7;
  int *in_ECX;
  HWND local_14;
  uint local_10;
  uint local_c;
  int *local_8;
  
  if (param_2 != (int *)0x0) {
    pcVar1 = *(code **)(*in_ECX + 0x170);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      if ((param_1 != 0) && (local_14 = *(HWND *)(iVar2 + 0xac), local_14 != (HWND)0x0)) {
        pcVar1 = *(code **)(local_14->unused + 0x5c);
        guard_check_icall(0);
        (*pcVar1)();
      }
      local_14 = (HWND)in_ECX[0x2d];
      local_c = 0;
      while( true ) {
        if (local_14 == (HWND)0x0) {
          param_2[2] = local_c;
          if (param_1 == 0) {
            in_ECX[0x38] = 0;
            local_14 = GetDlgItem((HWND)in_ECX[8],0xea21);
            if (local_14 != (HWND)0x0) {
              pHVar6 = GetDlgItem((HWND)in_ECX[8],0xe900);
              if (pHVar6 != (HWND)0x0) {
                SetWindowLongW(pHVar6,-0xc,0xea21);
              }
              SetWindowLongW(local_14,-0xc,0xe900);
            }
            if (param_2[1] != 0) {
              InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
              if (in_ECX[0x40] == 1) {
                SetMenu((HWND)in_ECX[8],(HMENU)param_2[1]);
              }
              else if (in_ECX[0x40] == 2) {
                in_ECX[0x41] = param_2[1];
              }
            }
            if (*(int **)(iVar2 + 0xac) != (int *)0x0) {
              pcVar1 = *(code **)(**(int **)(iVar2 + 0xac) + 0x5c);
              guard_check_icall(1);
              (*pcVar1)();
            }
            pcVar1 = *(code **)(*in_ECX + 0x178);
            guard_check_icall(1);
            (*pcVar1)();
            pHVar6 = local_14;
            if (*param_2 != 0xe900) {
              pHVar6 = GetDlgItem((HWND)in_ECX[8],*param_2);
            }
            ShowWindow(pHVar6,5);
            in_ECX[0x23] = param_2[5];
            FUN_0079cd05(1);
          }
          else {
            in_ECX[0x38] = param_2[4];
            FUN_0079cd05(0);
            pHVar6 = GetDlgItem((HWND)in_ECX[8],*param_2);
            ShowWindow(pHVar6,0);
            if (in_ECX[0x40] == 1) {
              pHVar7 = GetMenu((HWND)in_ECX[8]);
            }
            else {
              pHVar7 = (HMENU)in_ECX[0x41];
            }
            param_2[1] = (int)pHVar7;
            if (pHVar7 != (HMENU)0x0) {
              InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
              pcVar1 = *(code **)(*in_ECX + 0x70);
              guard_check_icall(0);
              (*pcVar1)();
              in_ECX[0x46] = in_ECX[0x46] & 0xfffffffe;
            }
            param_2[5] = in_ECX[0x23];
            in_ECX[0x23] = 0;
            LoadAccelTable(0x7915);
            if (*param_2 != 0xe900) {
              pHVar6 = GetDlgItem((HWND)in_ECX[8],0xe900);
            }
            if (pHVar6 != (HWND)0x0) {
              SetWindowLongW(pHVar6,-0xc,0xea21);
            }
          }
          return;
        }
        piVar3 = (int *)FUN_00792938(&local_14);
        piVar3 = (int *)*piVar3;
        local_8 = piVar3;
        if (piVar3 == (int *)0x0) break;
        iVar4 = GetDlgCtrlID((HWND)piVar3[8]);
        if (iVar4 - 0xe800U < 0x20) {
          local_10 = 1 << ((byte)iVar4 & 0x1f);
          pcVar1 = *(code **)(*piVar3 + 400);
          guard_check_icall();
          iVar5 = (*pcVar1)();
          if (iVar5 != 0) {
            local_c = local_c | local_10;
          }
          pcVar1 = *(code **)(*local_8 + 0x198);
          guard_check_icall();
          iVar5 = (*pcVar1)();
          if ((iVar5 == 0) || (iVar4 != 0xe81f)) {
            FUN_0079cbbd(local_8,param_2[2] & local_10,1);
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CFrameWnd[106], CMDIChildWnd[106], CMDIChildWndEx[106], CMFCColorPopupMenu[106], CMFCDropDownFrame[106], CMFCPopupMenu[106], CMFCRibbonMiniToolBar[106], CMFCRibbonPanelMenu[106], CMFCShadowWnd[106], CMainFrame[106], CMiniDockFrameWnd[106], CMiniFrameWnd[106], COleCntrFrameWnd[106], COleCntrFrameWndEx[106], COleDocIPFrameWnd[106], COleDocIPFrameWndEx[106], COleIPFrameWnd[106], COleIPFrameWndEx[106] */
/* 0079c28d  FUN_0079c28d  112 bytes, 1 callers */

void FUN_0079c28d(HMENU param_1)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  
  if (param_1 == (HMENU)0x0) {
    pcVar1 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall();
    piVar2 = (int *)(*pcVar1)();
    if (piVar2 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar2 + 0xec);
      guard_check_icall();
      param_1 = (HMENU)(*pcVar1)();
      if (param_1 != (HMENU)0x0) goto LAB_0079c2d6;
    }
    param_1 = (HMENU)in_ECX[0x22];
  }
LAB_0079c2d6:
  if (in_ECX[0x40] == 1) {
    SetMenu((HWND)in_ECX[8],param_1);
  }
  else if (in_ECX[0x40] == 2) {
    in_ECX[0x41] = (int)param_1;
  }
  return;
}




/* vtable slots: CFrameWnd[105], CMFCColorPopupMenu[105], CMFCDropDownFrame[105], CMFCPopupMenu[105], CMFCRibbonMiniToolBar[105], CMFCRibbonPanelMenu[105], CMFCShadowWnd[105], CMainFrame[105], CMiniDockFrameWnd[105], CMiniFrameWnd[105], COleCntrFrameWnd[105], COleCntrFrameWndEx[105], COleDocIPFrameWnd[105], COleDocIPFrameWndEx[105], COleIPFrameWnd[105], COleIPFrameWndEx[105] */
/* 0079c2fd  FUN_0079c2fd  102 bytes, 1 callers */

void FUN_0079c2fd(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  uVar2 = FUN_00797b3d();
  if ((uVar2 & 0x8000) != 0) {
    if ((int *)in_ECX[0x2b] != (int *)0x0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x2b] + 0x68);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return;
      }
    }
    pcVar1 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if ((param_1 == 0) || (iVar3 == 0)) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar3 + 0x20);
    }
    FUN_0079cd9f(uVar4);
  }
  return;
}




/* vtable slots: CFrameWnd[72], CFrameWndEx[72], CJw_winView[72], CMDIChildWnd[72], CMDIChildWndEx[72], CMDIFrameWnd[72], CMDIFrameWndEx[72], CMFCShadowWnd[72], CMainFrame[72], CMiniDockFrameWnd[72], CMiniFrameWnd[72], COleDocIPFrameWnd[72], COleDocIPFrameWndEx[72], COleIPFrameWnd[72], COleIPFrameWndEx[72], CPreviewView[72], CPreviewViewEx[72], CScrollView[72] */
/* 0079c41b  FUN_0079c41b  30 bytes, 2 callers */

void FUN_0079c41b(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX != (int *)0x0) {
    pcVar1 = *(code **)(*in_ECX + 4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CFrameWnd[25], COleCntrFrameWnd[25], COleDocIPFrameWnd[25], COleIPFrameWnd[25] */
/* 0079c439  PreCreateWindow  60 bytes, 7 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CFrameWnd::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall CFrameWnd::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 PreCreateWindow(int param_1)

{
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_00790c5e(8);
    *(wchar_t **)(param_1 + 0x28) = L"AfxFrameOrView140su";
  }
  if ((*(uint *)(param_1 + 0x20) & 0x8000) != 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x4000;
  }
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x200;
  return 1;
}




/* vtable slots: CFrameWnd[67], CMFCDropDownFrame[67], CMFCShadowWnd[67], CMainFrame[67], CMiniDockFrameWnd[67], CMiniFrameWnd[67], COleCntrFrameWnd[67], COleCntrFrameWndEx[67] */
/* 0079c475  FUN_0079c475  478 bytes, 5 callers */

undefined4 FUN_0079c475(LPMSG param_1)

{
  code *pcVar1;
  UINT UVar2;
  int iVar3;
  HACCEL hAccTable;
  undefined4 uVar4;
  int *in_ECX;
  uint uVar5;
  
  if (param_1 == (LPMSG)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((param_1->message == 0x201) || (param_1->message == 0xa1)) {
    AfxCancelModes(param_1->hwnd);
  }
  uVar5 = in_ECX[0x3f];
  if ((((uVar5 & 4) != 0) && (param_1->message == 0x105)) && (param_1->wParam == 0x79)) {
    pcVar1 = *(code **)(*in_ECX + 0x18c);
    guard_check_icall(1);
    (*pcVar1)();
    uVar5 = in_ECX[0x3f];
  }
  if ((uVar5 & 2) != 0) {
    if (param_1->message == 0x105) {
      if (param_1->wParam == 0x12) {
        pcVar1 = *(code **)(*in_ECX + 0x18c);
        guard_check_icall((in_ECX[0x40] == 1) + '\x01');
        (*pcVar1)();
      }
    }
    else if ((param_1->message == 0x106) && (in_ECX[0x40] == 2)) {
      pcVar1 = *(code **)(*in_ECX + 0x18c);
      guard_check_icall(1);
      (*pcVar1)();
      in_ECX[0x42] = 1;
    }
  }
  if (((*(byte *)(in_ECX + 0x3f) & 1) == 0) &&
     ((((UVar2 = param_1->message, UVar2 == 0x100 && (param_1->wParam == 0x1b)) ||
       ((UVar2 == 0x201 || (UVar2 == 0x204)))) ||
      (((UVar2 == 0xa1 || (UVar2 == 0xa4)) && (param_1->wParam != 5)))))) {
    pcVar1 = *(code **)(*in_ECX + 0x18c);
    guard_check_icall(2);
    (*pcVar1)();
  }
  UVar2 = param_1->message;
  if ((UVar2 == 0xa1) || (UVar2 == 0xa4)) {
    in_ECX[0x43] = (uint)(param_1->wParam == 5);
  }
  else if (((UVar2 == 0xa2) || (UVar2 == 0xa5)) || ((UVar2 == 0x202 || (UVar2 == 0x205)))) {
    in_ECX[0x43] = 0;
  }
  iVar3 = FUN_007949fb(param_1);
  if (iVar3 == 0) {
    if ((int *)in_ECX[0x2b] != (int *)0x0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x2b] + 0x54);
      guard_check_icall(param_1);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) goto LAB_0079c644;
    }
    if (param_1->message - 0x100 < 10) {
      pcVar1 = *(code **)(*in_ECX + 0x1ac);
      guard_check_icall();
      hAccTable = (HACCEL)(*pcVar1)();
      if (hAccTable != (HACCEL)0x0) {
        iVar3 = TranslateAcceleratorW((HWND)in_ECX[8],hAccTable,param_1);
        if (iVar3 != 0) goto LAB_0079c644;
      }
    }
    uVar4 = 0;
  }
  else {
LAB_0079c644:
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CFrameWnd[94], CMDIChildWnd[94], CMDIFrameWnd[94], CMFCShadowWnd[94], CMainFrame[94], CMiniFrameWnd[94] */
/* 0079c654  FUN_0079c654  284 bytes, 3 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0079c654(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int *in_ECX;
  int iVar3;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x3d] == 0) {
    in_ECX[0x3d] = 1;
    iVar3 = 1;
    if ((in_ECX[0x46] & 4U) == 0) {
      iVar3 = param_1;
    }
    in_ECX[0x46] = in_ECX[0x46] & 0xfffffff3;
    if ((iVar3 != 0) && ((int *)in_ECX[0x2b] != (int *)0x0)) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x2b] + 0x50);
      guard_check_icall();
      (*pcVar1)();
    }
    uVar2 = FUN_00797b3d();
    if ((uVar2 & 0x2000) == 0) {
      FUN_00794e3f(0,0xffff,0xe900,2,in_ECX + 0x27,0,1);
    }
    else {
      local_18 = 0;
      local_10 = 0x7fff;
      local_c = 0x7fff;
      local_14 = 0;
      FUN_00794e3f(0,0xffff,0xe900,1,&local_18,&local_18,0);
      FUN_00794e3f(0,0xffff,0xe900,2,in_ECX + 0x27,&local_18,1);
      pcVar1 = *(code **)(*in_ECX + 0x68);
      guard_check_icall(&local_18,0);
      (*pcVar1)();
      FUN_00797e71(0,0,0,local_10 - local_18,local_c - local_14,0x16);
    }
    in_ECX[0x3d] = 0;
  }
  return;
}




/* vtable slots: CFrameWnd[28], CFrameWndEx[28], CMDIChildWnd[28], CMDIChildWndEx[28], CMDIFrameWnd[28], CMDIFrameWndEx[28], CMFCColorPopupMenu[28], CMFCDropDownFrame[28], CMFCPopupMenu[28], CMFCRibbonMiniToolBar[28], CMFCRibbonPanelMenu[28], CMFCShadowWnd[28], CMainFrame[28], CMiniDockFrameWnd[28], CMiniFrameWnd[28], COleCntrFrameWnd[28], COleCntrFrameWndEx[28], COleDocIPFrameWnd[28], COleDocIPFrameWndEx[28], COleIPFrameWnd[28], COleIPFrameWndEx[28] */
/* 0079c940  FUN_0079c940  69 bytes, 0 callers */

BOOL FUN_0079c940(int param_1)

{
  HMENU hMenu;
  BOOL BVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x100) == 1) {
    hMenu = (HMENU)0x0;
    if (param_1 != 0) {
      hMenu = *(HMENU *)(param_1 + 4);
    }
    BVar1 = SetMenu(*(HWND *)(in_ECX + 0x20),hMenu);
  }
  else {
    if (*(int *)(in_ECX + 0x100) != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    uVar2 = 0;
    if (param_1 != 0) {
      uVar2 = *(undefined4 *)(param_1 + 4);
    }
    *(undefined4 *)(in_ECX + 0x104) = uVar2;
    BVar1 = 1;
  }
  return BVar1;
}




/* vtable slots: CFrameWnd[99], CFrameWndEx[99], CMDIChildWnd[99], CMDIChildWndEx[99], CMFCColorPopupMenu[99], CMFCDropDownFrame[99], CMFCPopupMenu[99], CMFCRibbonMiniToolBar[99], CMFCRibbonPanelMenu[99], CMFCShadowWnd[99], CMainFrame[99], CMiniDockFrameWnd[99], CMiniFrameWnd[99], COleCntrFrameWnd[99], COleCntrFrameWndEx[99], COleDocIPFrameWnd[99], COleDocIPFrameWndEx[99], COleIPFrameWnd[99], COleIPFrameWndEx[99] */
/* 0079c986  FUN_0079c986  133 bytes, 1 callers */

undefined4 FUN_0079c986(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  HMENU pHVar3;
  int *in_ECX;
  
  if ((param_1 != 1) && (param_1 != 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if (in_ECX[0x40] == param_1) {
    uVar2 = 0;
  }
  else {
    if (param_1 == 1) {
      pcVar1 = *(code **)(*in_ECX + 0x1b8);
      guard_check_icall();
      (*pcVar1)();
      pHVar3 = (HMENU)in_ECX[0x41];
    }
    else {
      pHVar3 = GetMenu((HWND)in_ECX[8]);
      in_ECX[0x41] = (int)pHVar3;
      pcVar1 = *(code **)(*in_ECX + 0x1bc);
      guard_check_icall();
      (*pcVar1)();
      pHVar3 = (HMENU)0x0;
    }
    SetMenu((HWND)in_ECX[8],pHVar3);
    in_ECX[0x40] = param_1;
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CFrameWnd[97], CFrameWndEx[97], CMDIChildWnd[97], CMDIChildWndEx[97], CMFCColorPopupMenu[97], CMFCDropDownFrame[97], CMFCPopupMenu[97], CMFCRibbonMiniToolBar[97], CMFCRibbonPanelMenu[97], CMFCShadowWnd[97], CMainFrame[97], CMiniDockFrameWnd[97], CMiniFrameWnd[97], COleCntrFrameWnd[97], COleCntrFrameWndEx[97], COleDocIPFrameWnd[97], COleDocIPFrameWndEx[97], COleIPFrameWnd[97], COleIPFrameWndEx[97] */
/* 0079ca0c  FUN_0079ca0c  100 bytes, 0 callers */

void FUN_0079ca0c(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  if (((param_1 != 1) && (param_1 != 2)) && (param_1 != 6)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if (in_ECX[0x3f] != param_1) {
    if (param_1 == 1) {
      in_ECX[0x3f] = 1;
      uVar2 = 1;
    }
    else {
      if ((param_1 != 2) && (param_1 != 6)) {
        return;
      }
      in_ECX[0x3f] = param_1;
      uVar2 = 2;
    }
    pcVar1 = *(code **)(*in_ECX + 0x18c);
    guard_check_icall(uVar2);
    (*pcVar1)();
  }
  return;
}



