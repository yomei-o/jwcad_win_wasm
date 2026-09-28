/* CMDIFrameWndEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMDIFrameWndEx[1] */
/* 0084c41c  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void * __thiscall CMDIFrameWndEx::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMDIFrameWndEx::_scalar_deleting_destructor_(CMDIFrameWndEx *this,uint param_1)

{
  ~CMDIFrameWndEx(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2ff0);
    }
  }
  return this;
}




/* vtable slots: CMDIFrameWndEx[132] */
/* 0084c546  FUN_0084c546  120 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0084c546(void)

{
  code *pcVar1;
  int in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18 = *(int *)(in_ECX + 600) + *(int *)(in_ECX + 0x9c);
  local_14 = *(int *)(in_ECX + 0x25c) + *(int *)(in_ECX + 0xa0);
  local_10 = *(int *)(in_ECX + 0x260) - *(int *)(in_ECX + 0xa4);
  local_c = *(int *)(in_ECX + 0x264) - *(int *)(in_ECX + 0xa8);
  if (((int *)(in_ECX + 0x458) != (int *)0x0) && (*(int *)(in_ECX + 0x478) != 0)) {
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x458) + 0x68);
    guard_check_icall(&local_18,0);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMDIFrameWndEx[114] */
/* 0084c5be  FUN_0084c5be  103 bytes, 0 callers */

void FUN_0084c5be(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0xad] == 0) {
    pcVar1 = *(code **)(in_ECX[0x58] + 0x38);
    guard_check_icall(param_1);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x210);
    guard_check_icall();
    (*pcVar1)();
    iVar2 = FUN_0084785d();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x178);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMDIFrameWndEx[117] */
/* 0084c62c  FUN_0084c62c  238 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_0084c62c(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  LRESULT LVar5;
  undefined4 uVar6;
  undefined4 in_ECX;
  int *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x84c638;
  iVar3 = FUN_0078e624(0x4e0);
  piVar4 = (int *)0x0;
  local_18 = (int *)0x0;
  local_8 = 0;
  if (iVar3 != 0) {
    piVar4 = (int *)FUN_0084f775();
  }
  local_8 = 0xffffffff;
  pcVar1 = *(code **)(*param_1 + 0x170);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  param_1[0xac] = iVar3;
  CStringT<>();
  local_8 = 1;
  FUN_00792c64(local_14);
  uVar2 = local_14[0];
  pcVar1 = *(code **)(*piVar4 + 0x1c0);
  LVar5 = SendMessageW((HWND)param_1[8],0x7f,0,0);
  uVar6 = AfxRegisterWndClass(8,0,0x10,LVar5);
  guard_check_icall(uVar6,uVar2,0x50cf8000,&DAT_00a00354,in_ECX,0);
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    FUN_0084df9c(local_14[0]);
    FUN_00797ece(local_14[0]);
    FUN_0084fa2f(param_1);
    local_18 = piVar4;
  }
  FUN_00406b10();
  return local_18;
}




/* vtable slots: CMDIFrameWndEx[138] */
/* 0084c71a  FUN_0084c71a  162 bytes, 0 callers */

CObject * FUN_0084c71a(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  CMDIChildWnd *pCVar3;
  CObject *pCVar4;
  int *piVar5;
  CMDIFrameWndEx *in_ECX;
  int local_8;
  
  iVar2 = CMDIFrameWndEx::AreMDITabs(in_ECX,(int *)0x0);
  if (iVar2 == 0) {
    iVar2 = FUN_0079dd6d();
    pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0xa4);
    guard_check_icall(param_1);
    piVar5 = (int *)(*pcVar1)();
    if (piVar5 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar5 + 0x68);
      guard_check_icall(param_1);
      local_8 = (*pcVar1)();
      if (local_8 != 0) {
        pcVar1 = *(code **)(*piVar5 + 0x6c);
        guard_check_icall(&local_8);
        (*pcVar1)();
        pCVar4 = (CObject *)FUN_0079296c();
        pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIChildWndEx_00995510,pCVar4);
        return pCVar4;
      }
    }
    pCVar4 = (CObject *)0x0;
  }
  else {
    CMDIFrameWndEx::OnWindowNew(in_ECX);
    pCVar3 = CMDIFrameWnd::MDIGetActive((CMDIFrameWnd *)in_ECX,(int *)0x0);
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIChildWndEx_00995510,(CObject *)pCVar3);
  }
  return pCVar4;
}




/* vtable slots: CMDIFrameWndEx[10] */
/* 0084c7fb  FUN_0084c7fb  6 bytes, 0 callers */

undefined ** FUN_0084c7fb(void)

{
  return &PTR_FUN_00994bd8;
}




/* vtable slots: CMDIFrameWndEx[0] */
/* 0084c86d  FUN_0084c86d  6 bytes, 0 callers */

undefined ** FUN_0084c86d(void)

{
  return &PTR_s_CMDIFrameWndEx_009945d0;
}




/* vtable slots: CMDIFrameWndEx[113] */
/* 0084c873  GetWindowMenuPopup  38 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual struct HMENU__ * __thiscall CMDIFrameWndEx::GetWindowMenuPopup(struct HMENU__
   *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

HMENU__ * __thiscall CMDIFrameWndEx::GetWindowMenuPopup(CMDIFrameWndEx *this,HMENU__ *param_1)

{
  HMENU__ *pHVar1;
  
  if (*(int *)(this + 0x154) == 0) {
    pHVar1 = (HMENU__ *)FUN_008a2a9f(param_1);
    *(HMENU__ **)(this + 300) = pHVar1;
  }
  else {
    pHVar1 = (HMENU__ *)0x0;
  }
  return pHVar1;
}




/* vtable slots: CMDIFrameWndEx[32] */
/* 0084c899  FUN_0084c899  33 bytes, 0 callers */

void FUN_0084c899(int param_1)

{
  int in_ECX;
  
  if ((param_1 == 0) && (*(int *)(in_ECX + 0x138) != 0)) {
    OnContextHelp();
    return;
  }
  FUN_00792e01();
  return;
}




/* vtable slots: CMDIFrameWndEx[90] */
/* 0084c8e7  LoadFrame  89 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMDIFrameWndEx::LoadFrame(unsigned int,unsigned long,class CWnd
   *,struct CCreateContext *)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMDIFrameWndEx::LoadFrame
          (CMDIFrameWndEx *this,uint param_1,ulong param_2,CWnd *param_3,CCreateContext *param_4)

{
  int iVar1;
  int iVar2;
  
  *(uint *)(this + 0x35c) = param_1;
  CFrameImpl::LoadLargeIconsState((CFrameImpl *)(this + 0x350));
  iVar1 = CMDIFrameWnd::LoadFrame((CMDIFrameWnd *)this,param_1,param_2,param_3,param_4);
  iVar2 = 0;
  if (iVar1 != 0) {
    FUN_0087c092();
    if (*(int *)(this + 0x3fc) != 0) {
      *(undefined4 *)(this + 0x88) = *(undefined4 *)(this + 0x390);
    }
    iVar2 = 1;
  }
  return iVar2;
}




/* vtable slots: CMDIFrameWndEx[135] */
/* 0084c940  FUN_0084c940  27 bytes, 0 callers */

void FUN_0084c940(undefined4 param_1)

{
  int in_ECX;
  
  FUN_008938bc(param_1,*(undefined4 *)(in_ECX + 0x158));
  return;
}




/* vtable slots: CMDIFrameWndEx[103] */
/* 0084c95b  FUN_0084c95b  120 bytes, 0 callers */

undefined4 FUN_0084c95b(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (param_1 == 1) {
    FUN_0079a2a0(1,param_2);
    pcVar3 = *(code **)(*(int *)(in_ECX + 0x160) + 0x38);
    guard_check_icall(0);
    (*pcVar3)();
    uVar4 = *(undefined4 *)(in_ECX + 0x25c);
    uVar1 = *(undefined4 *)(in_ECX + 0x260);
    uVar2 = *(undefined4 *)(in_ECX + 0x264);
    if (param_2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    *param_2 = *(undefined4 *)(in_ECX + 600);
    param_2[1] = uVar4;
    param_2[2] = uVar1;
    param_2[3] = uVar2;
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    uVar4 = FUN_0079a2a0(3,param_2);
    return uVar4;
  }
  return 1;
}




/* vtable slots: CMDIFrameWndEx[123] */
/* 0084cb6b  OnClosePopupMenu  115 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CFrameWndEx::OnClosePopupMenu(class CMFCPopupMenu *)
    public: virtual void __thiscall CMDIFrameWndEx::OnClosePopupMenu(class CMFCPopupMenu *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void OnClosePopupMenu(uint param_1)

{
  int iVar1;
  DWORD event;
  HWND hwnd;
  
  iVar1 = FUN_007c2511();
  if ((*(int *)(iVar1 + 0x19c) != 0) && (param_1 != 0)) {
    iVar1 = FUN_0081d529();
    if ((*(int *)(param_1 + 0x1164) == 0) && ((iVar1 == 0 && (*(int *)(param_1 + 0x158) != 0)))) {
      hwnd = *(HWND *)(param_1 + 0x20);
      event = 5;
    }
    else {
      hwnd = *(HWND *)(param_1 + 0x20);
      event = 7;
    }
    NotifyWinEvent(event,hwnd,0,0);
  }
  DAT_00a139c8 = DAT_00a139c8 & -(uint)(DAT_00a139c8 != param_1);
  FUN_00848045();
  return;
}




/* vtable slots: CMDIFrameWndEx[3] */
/* 0084cbde  OnCmdMsg  60 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual int __thiscall CFrameWndEx::OnCmdMsg(unsigned int,int,void *,struct
   AFX_CMDHANDLERINFO *)
    public: virtual int __thiscall CMDIFrameWndEx::OnCmdMsg(unsigned int,int,void *,struct
   AFX_CMDHANDLERINFO *)
    public: virtual int __thiscall COleDocIPFrameWndEx::OnCmdMsg(unsigned int,int,void *,struct
   AFX_CMDHANDLERINFO *)
    public: virtual int __thiscall COleIPFrameWndEx::OnCmdMsg(unsigned int,int,void *,struct
   AFX_CMDHANDLERINFO *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 OnCmdMsg(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_008a2cfb(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    uVar2 = FUN_00848731(param_1,param_2,param_3,param_4);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMDIFrameWndEx[61] */
/* 0084cc1a  FUN_0084cc1a  108 bytes, 0 callers */

undefined4 FUN_0084cc1a(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((short)(param_1 >> 0x10) == 1) {
    CMFCToolBar::AddCommandUsage(param_1 & 0xffff);
    iVar1 = FUN_0087cca9(0x1b,0);
    if ((iVar1 != 0) ||
       ((DAT_00a13bac != 0 && (iVar1 = FUN_00852536(param_1 & 0xffff), iVar1 != 0)))) {
      return 1;
    }
  }
  if (DAT_00a127ac == 0) {
    uVar2 = FUN_008a2d75(param_1,param_2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMDIFrameWndEx[104] */
/* 0084cf6d  OnCreateClient  55 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CMDIFrameWndEx::OnCreateClient(struct tagCREATESTRUCTA
   *,struct CCreateContext *)
    protected: virtual int __thiscall CMDIFrameWndEx::OnCreateClient(struct tagCREATESTRUCTW
   *,struct CCreateContext *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 OnCreateClient(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = FUN_008a2ea3(param_1,param_2);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (*(int *)(in_ECX + 0x13c) != 0) {
      FUN_007954d8(*(undefined4 *)(in_ECX + 0x120));
    }
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMDIFrameWndEx[124] */
/* 0084d08e  FUN_0084d08e  25 bytes, 0 callers */

undefined4 FUN_0084d08e(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44c) != 0) {
    uVar1 = FUN_008b2b64();
    return uVar1;
  }
  return 0;
}




/* vtable slots: CMDIFrameWndEx[115] */
/* 0084d1c9  FUN_0084d1c9  37 bytes, 0 callers */

void FUN_0084d1c9(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x160) + 0x3c);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMDIFrameWndEx[120] */
/* 0084d2e7  FUN_0084d2e7  205 bytes, 0 callers */

undefined4 FUN_0084d2e7(int param_1)

{
  code *pcVar1;
  CMFCRibbonBar *this;
  COleClientItem *this_00;
  CWnd *pCVar2;
  uint uVar3;
  CMDIChildWnd *pCVar4;
  undefined4 uVar5;
  CMDIFrameWnd *in_ECX;
  
  pcVar1 = *(code **)(*(int *)in_ECX + 0x22c);
  guard_check_icall();
  this_00 = (COleClientItem *)(*pcVar1)();
  if (this_00 == (COleClientItem *)0x0) {
LAB_0084d316:
    if (*(int *)(in_ECX + 0x44c) == 0) {
LAB_0084d363:
      if (*(int *)(in_ECX + 0x3fc) == 0) goto LAB_0084d3ab;
      pcVar1 = *(code **)(*(int *)in_ECX + 0x70);
      guard_check_icall(0);
      (*pcVar1)();
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x3fc) + 0x434);
      if (param_1 == 0) {
        param_1 = *(int *)(in_ECX + 0x390);
      }
      guard_check_icall(param_1,0,0);
      (*pcVar1)();
    }
    else {
      uVar3 = FUN_00797b3d();
      if (((uVar3 & 0x10000000) == 0) && (*(int *)(in_ECX + 0x420) == 0)) goto LAB_0084d363;
      pcVar1 = *(code **)(*(int *)in_ECX + 0x70);
      guard_check_icall(0);
      (*pcVar1)();
      this = *(CMFCRibbonBar **)(in_ECX + 0x44c);
      pCVar4 = CMDIFrameWnd::MDIGetActive(in_ECX,(int *)0x0);
      CMFCRibbonBar::SetActiveMDIChild(this,(CWnd *)pCVar4);
    }
    uVar5 = 1;
  }
  else {
    pCVar2 = COleClientItem::GetInPlaceWindow(this_00);
    if (pCVar2 == (CWnd *)0x0) goto LAB_0084d316;
LAB_0084d3ab:
    uVar5 = 0;
  }
  return uVar5;
}




/* vtable slots: CMDIFrameWndEx[101] */
/* 0084d3b4  FUN_0084d3b4  179 bytes, 0 callers */

void FUN_0084d3b4(WPARAM param_1,int param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int *in_ECX;
  
  if (in_ECX[0xbbd] != 0) {
    in_ECX[0xbbc] = (uint)(param_1 == 0);
    FUN_00797f20((-(uint)(param_1 != 0) & 0xfffffffc) + 4);
  }
  FUN_0084a874(param_1,param_2);
  uVar1 = *(undefined4 *)(param_2 + 8);
  FUN_0079bd2d(param_1,param_2);
  *(undefined4 *)(param_2 + 8) = uVar1;
  pcVar2 = *(code **)(*in_ECX + 0x1c8);
  guard_check_icall(0);
  (*pcVar2)();
  pcVar2 = *(code **)(*in_ECX + 0x178);
  guard_check_icall(1);
  (*pcVar2)();
  if ((in_ECX[0x113] != 0) && (*(int *)(in_ECX[0x113] + 0x328) != 0)) {
    PostMessageW((HWND)in_ECX[8],DAT_00a13be0,param_1,0);
  }
  return;
}




/* vtable slots: CMDIFrameWndEx[122] */
/* 0084d48b  FUN_0084d48b  27 bytes, 0 callers */

undefined4 FUN_0084d48b(undefined4 param_1,undefined4 param_2)

{
  FUN_0087aef5(param_1,param_2);
  return 1;
}




/* vtable slots: CMDIFrameWndEx[116] */
/* 0084d4a6  FUN_0084d4a6  306 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0084d4a6(undefined4 param_1,undefined4 param_2,byte param_3)

{
  code *pcVar1;
  HMENU pHVar2;
  int iVar3;
  BOOL BVar4;
  CMDIChildWnd *pCVar5;
  CObject *pCVar6;
  undefined4 uVar7;
  CMDIFrameWnd *in_ECX;
  UINT in_stack_ffffffcc;
  LPSTR in_stack_ffffffd0;
  int in_stack_ffffffd4;
  undefined **local_24;
  HMENU local_20;
  CMDIFrameWnd *local_1c;
  HWND local_18;
  LPCWSTR local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  if (((param_3 & 0x10) == 0) || (DAT_00a13a20 == (int *)0x0)) {
    uVar7 = 0;
  }
  else {
    local_24 = CMenu::vftable;
    local_20 = (HMENU)0x0;
    local_8 = 0;
    local_1c = in_ECX;
    pHVar2 = CreatePopupMenu();
    CMenu::Attach((CMenu *)&local_24,pHVar2);
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar3 = FID_conflict_LoadStringA
                      ((HINSTANCE)0x42c0,in_stack_ffffffcc,in_stack_ffffffd0,in_stack_ffffffd4);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    AppendMenuW(local_20,0,0xffffff96,local_14);
    CheckMenuItem(local_20,0xffffff96,8);
    if (in_ECX == (CMDIFrameWnd *)0x0) {
      local_18 = (HWND)0x0;
    }
    else {
      local_18 = *(HWND *)(in_ECX + 0x20);
    }
    pcVar1 = *(code **)(*DAT_00a13a20 + 0x14);
    guard_check_icall(local_20,param_1,param_2,local_1c,0);
    iVar3 = (*pcVar1)();
    BVar4 = IsWindow(local_18);
    if ((BVar4 != 0) && (iVar3 == -0x6a)) {
      pCVar5 = CMDIFrameWnd::MDIGetActive(local_1c,(int *)0x0);
      pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIChildWndEx_00995510,(CObject *)pCVar5)
      ;
      if (pCVar6 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)local_1c + 0x1d8);
        guard_check_icall(pCVar6);
        (*pcVar1)();
      }
    }
    FUN_00406b10();
    local_8 = 2;
    local_24 = CMenu::vftable;
    CMenu::DestroyMenu((CMenu *)&local_24);
    uVar7 = 1;
  }
  return uVar7;
}




/* vtable slots: CMDIFrameWndEx[131] */
/* 0084d5d9  FUN_0084d5d9  67 bytes, 0 callers */

undefined4 FUN_0084d5d9(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(in_ECX[0x58] + 0x50);
  guard_check_icall(param_1);
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1c8);
  guard_check_icall(0);
  (*pcVar1)();
  return uVar2;
}




/* vtable slots: CMDIFrameWndEx[106] */
/* 0084d815  FUN_0084d815  155 bytes, 0 callers */

void FUN_0084d815(HMENU__ *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  COleClientItem *this;
  CWnd *pCVar4;
  CMenu *pCVar5;
  int *in_ECX;
  code *pcVar6;
  
  FUN_008a32b3(param_1);
  if ((in_ECX[0xff] == 0) || (uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  bVar2 = false;
  if ((in_ECX[0x113] != 0) && (uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) != 0)) {
    bVar2 = true;
  }
  if ((!bVar1) && (!bVar2)) {
    return;
  }
  pcVar6 = *(code **)(*in_ECX + 0x22c);
  guard_check_icall();
  this = (COleClientItem *)(*pcVar6)();
  if ((this == (COleClientItem *)0x0) ||
     (pCVar4 = COleClientItem::GetInPlaceWindow(this), pCVar4 == (CWnd *)0x0)) {
    pCVar5 = (CMenu *)0x0;
    pcVar6 = *(code **)(*in_ECX + 0x70);
  }
  else {
    pcVar6 = *(code **)(*in_ECX + 0x70);
    pCVar5 = CMenu::FromHandle(param_1);
  }
  guard_check_icall(pCVar5);
  (*pcVar6)();
  return;
}




/* vtable slots: CMDIFrameWndEx[25] */
/* 0084da11  PreCreateWindow  47 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CMDIFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall CMDIFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void PreCreateWindow(undefined4 param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x404) = in_ECX + 0x160;
  FUN_0087d87d(param_1);
  PreCreateWindow(param_1);
  return;
}




/* vtable slots: CMDIFrameWndEx[67] */
/* 0084da40  FUN_0084da40  884 bytes, 0 callers */

undefined4 FUN_0084da40(undefined4 *param_1)

{
  uint uVar1;
  SHORT SVar2;
  CMFCPopupMenu *pCVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  undefined4 uVar6;
  int iVar7;
  CObject *pCVar8;
  BOOL BVar9;
  CFrameWnd *in_ECX;
  UINT Msg;
  tagPOINT local_1c;
  tagPOINT local_14;
  int local_c;
  HIMC local_8;
  
  uVar1 = param_1[1];
  if (uVar1 < 0x105) {
    if (uVar1 == 0x104) {
      if ((*(int *)(in_ECX + 0x44c) == 0) ||
         (iVar7 = FUN_008b3d1d(in_ECX,param_1[2],param_1[3]), iVar7 == 0)) {
LAB_0084db69:
        iVar7 = FUN_007c2511();
        if ((*(int *)(iVar7 + 0x1a4) == 0) && (iVar7 = FUN_007c2511(), *(int *)(iVar7 + 0x1a0) == 0)
           ) {
          iVar7 = FUN_007c2511();
          *(undefined4 *)(iVar7 + 0x1a0) = 1;
          FUN_00803a81();
        }
        pCVar8 = (CObject *)CMFCPopupMenu::GetSafeActivePopupMenu();
        if ((pCVar8 == (CObject *)0x0) || (param_1[2] != 0x12)) {
          pCVar3 = (CMFCPopupMenu *)FUN_0087cca9(param_1[2],0);
          goto LAB_0084dda7;
        }
        Msg = 0x10;
LAB_0084db3d:
        SendMessageW(*(HWND *)(pCVar8 + 0x20),Msg,0,0);
      }
    }
    else {
      if (uVar1 < 0xa6) {
        if (uVar1 != 0xa5) {
          if (uVar1 == 0x7b) goto LAB_0084db69;
          if (((uVar1 != 0xa1) && (uVar1 != 0xa2)) && (uVar1 != 0xa4)) goto LAB_0084dc58;
        }
      }
      else if ((uVar1 != 0xa7) && (uVar1 != 0xa8)) {
        if (uVar1 == 0x100) {
          iVar7 = IsHelpKey(param_1);
          if ((iVar7 == 0) && (iVar7 = FUN_0087cca9(param_1[2],0), iVar7 != 0)) goto LAB_0084db46;
          if (param_1[2] == 0x1b) {
            if (*(int *)(in_ECX + 0x420) != 0) {
              FUN_008c1d1c(in_ECX);
            }
            iVar7 = *(int *)(in_ECX + 0x318);
            if (((iVar7 != 0) && (*(int *)(iVar7 + 8) != 0)) && (*(int *)(iVar7 + 4) != 0)) {
              FUN_0086203b();
            }
            pHVar4 = GetCapture();
            pCVar5 = CWnd::FromHandle(pHVar4);
            pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,
                                        (CObject *)pCVar5);
            if (pCVar8 != (CObject *)0x0) {
              Msg = 0x1f;
              goto LAB_0084db3d;
            }
          }
        }
        goto LAB_0084dc58;
      }
      pCVar3 = (CMFCPopupMenu *)
               FUN_0087cf79(uVar1,(int)*(short *)(param_1 + 3),(int)*(short *)((int)param_1 + 0xe),
                            *param_1);
LAB_0084dda7:
      if (pCVar3 == (CMFCPopupMenu *)0x0) goto LAB_0084dc58;
    }
LAB_0084db46:
    uVar6 = 1;
  }
  else {
    if (0x205 < uVar1) {
      if ((uVar1 == 0x207) || (uVar1 == 0x208)) goto LAB_0084dbf2;
      if (uVar1 != 0x20a) goto LAB_0084dc58;
      pCVar3 = (CMFCPopupMenu *)FUN_0087d6c8(param_1[2],param_1[3]);
      goto LAB_0084dda7;
    }
    if (uVar1 != 0x205) {
      if (uVar1 == 0x105) {
        if ((*(CMFCRibbonBar **)(in_ECX + 0x44c) != (CMFCRibbonBar *)0x0) &&
           (iVar7 = CMFCRibbonBar::OnSysKeyUp
                              (*(CMFCRibbonBar **)(in_ECX + 0x44c),in_ECX,param_1[2],param_1[3]),
           iVar7 != 0)) goto LAB_0084db46;
        SVar2 = GetKeyState(0x11);
        local_14.y = (LONG)SVar2;
        SVar2 = GetKeyState(0x10);
        local_1c.y = (LONG)SVar2;
        local_8 = ImmGetContext(*(HWND *)(in_ECX + 0x20));
        if ((local_8 == (HIMC)0x0) || (BVar9 = ImmGetOpenStatus(local_8), BVar9 == 0)) {
          local_c = 0;
          if (local_8 != (HIMC)0x0) goto LAB_0084dd05;
        }
        else {
          local_c = 1;
LAB_0084dd05:
          ImmReleaseContext(*(HWND *)(in_ECX + 0x20),local_8);
        }
        if ((*(int *)(in_ECX + 0x3fc) != 0) &&
           ((param_1[2] == 0x12 ||
            ((((param_1[2] == 0x79 && ((local_14.y & 0x8000U) == 0)) &&
              ((local_1c.y & 0x8000U) == 0)) && (local_c == 0)))))) {
          pHVar4 = GetFocus();
          pCVar5 = CWnd::FromHandle(pHVar4);
          if (((*(CWnd **)(in_ECX + 0x3fc) == pCVar5) || (param_1[2] == 0x12)) ||
             ((param_1[3] & 0x20000000) == 0)) {
            FUN_00797df8();
          }
          goto LAB_0084db46;
        }
        pCVar3 = CMFCPopupMenu::GetSafeActivePopupMenu();
        goto LAB_0084dda7;
      }
      if (uVar1 == 0x200) {
        local_1c.x = (LONG)*(short *)(param_1 + 3);
        local_1c.y = (LONG)*(short *)((int)param_1 + 0xe);
        pCVar5 = CWnd::FromHandle((HWND__ *)*param_1);
        if (pCVar5 != (CWnd *)0x0) {
          ClientToScreen(*(HWND *)(pCVar5 + 0x20),&local_1c);
        }
        pCVar3 = (CMFCPopupMenu *)FUN_0087d5d0(local_1c.x,local_1c.y);
        goto LAB_0084dda7;
      }
      if ((uVar1 != 0x201) && (uVar1 != 0x204)) goto LAB_0084dc58;
    }
LAB_0084dbf2:
    local_14.x = (LONG)*(short *)(param_1 + 3);
    local_14.y = (LONG)*(short *)((int)param_1 + 0xe);
    local_1c.y = (LONG)CWnd::FromHandle((HWND__ *)*param_1);
    if (((CWnd *)local_1c.y != (CWnd *)0x0) && (BVar9 = IsWindow((HWND)*param_1), BVar9 != 0)) {
      ClientToScreen(*(HWND *)(local_1c.y + 0x20),&local_14);
    }
    iVar7 = FUN_0087cf79(param_1[1],local_14.x,local_14.y,*param_1);
    if ((iVar7 != 0) || (BVar9 = IsWindow((HWND)*param_1), BVar9 == 0)) goto LAB_0084db46;
LAB_0084dc58:
    uVar6 = FUN_008a3707(param_1);
  }
  return uVar6;
}




/* vtable slots: CMDIFrameWndEx[94] */
/* 0084ddb4  FUN_0084ddb4  446 bytes, 0 callers */

void FUN_0084ddb4(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *in_ECX;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (in_ECX[0x3d] != 0) {
    return;
  }
  iVar1 = in_ECX[0xdf];
  in_ECX[0x3d] = 1;
  in_ECX[0xdf] = 0;
  pcVar2 = *(code **)(*in_ECX + 0x22c);
  guard_check_icall();
  iVar3 = (*pcVar2)();
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x60) != 0)) && (*(int *)(iVar3 + 0x50) == 4)) {
    in_ECX[0xdf] = 1;
    uVar4 = FUN_00797b3d();
    in_ECX[0xe0] = (uint)((uVar4 & 0xc00000) != 0);
  }
  if (in_ECX[0x54] != 0) goto LAB_0084df16;
  iVar3 = FUN_00799e17();
  if (in_ECX[0xa4] == 0) {
    iVar5 = FUN_0084785d();
    if (iVar5 != 0) goto LAB_0084de77;
    pcVar2 = *(code **)(in_ECX[0x58] + 0x34);
    guard_check_icall(param_1);
    (*pcVar2)();
  }
  else {
LAB_0084de77:
    if ((iVar3 != 0) && (iVar3 = FUN_0079d98a(&PTR_s_CPreviewViewEx_009a3618), iVar3 != 0)) {
      pcVar2 = *(code **)(in_ECX[0x58] + 0x34);
      guard_check_icall(param_1);
      (*pcVar2)();
      FUN_00797e71(0,in_ECX[0x96],in_ECX[0x97],in_ECX[0x98] - in_ECX[0x96],
                   in_ECX[0x99] - in_ECX[0x97],0x14);
      goto LAB_0084df16;
    }
    if ((param_1 != 0) && (iVar3 = FUN_0084785d(), iVar3 != 0)) {
      FUN_0084c44f();
      goto LAB_0084df16;
    }
    in_ECX[0x3d] = 0;
    FUN_0079c654(param_1);
  }
  pcVar2 = *(code **)(*in_ECX + 0x210);
  guard_check_icall();
  (*pcVar2)();
LAB_0084df16:
  in_ECX[0x3d] = 0;
  if (iVar1 != in_ECX[0xdf]) {
    if (in_ECX[0xe0] == 0) {
      if (in_ECX[0xdf] == 0) {
        uVar7 = 0;
        uVar6 = 0xc00000;
      }
      else {
        uVar7 = 0xc00000;
        uVar6 = 0;
      }
      FUN_00797c5d(uVar6,uVar7,0);
    }
    FUN_0087b972();
    FUN_00797e71(0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x37);
  }
  return;
}




/* vtable slots: CMDIFrameWndEx[136] */
/* 0084df81  FUN_0084df81  27 bytes, 0 callers */

void FUN_0084df81(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00894cdd(param_1,*(undefined4 *)(in_ECX + 0x158));
  return;
}




/* vtable slots: CMDIFrameWndEx[118] */
/* 0084e257  FUN_0084e257  217 bytes, 0 callers */

undefined4 FUN_0084e257(int param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  HWND pHVar3;
  undefined4 uVar4;
  int in_ECX;
  
  uVar4 = 0;
  if (*(CObject **)(param_1 + 0x444) != (CObject *)0x0) {
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                *(CObject **)(param_1 + 0x444));
    if (pCVar2 != (CObject *)0x0) {
      if (*(int *)(pCVar2 + 0x2b0) == 0) {
        FUN_00797f20(0);
        pHVar3 = (HWND)0x0;
        if (in_ECX != 0) {
          pHVar3 = *(HWND *)(in_ECX + 0x20);
        }
        pHVar3 = SetParent(*(HWND *)(pCVar2 + 0x20),pHVar3);
        CWnd::FromHandle(pHVar3);
        *(undefined4 *)(pCVar2 + 0x90) = 0;
        pcVar1 = *(code **)(*(int *)pCVar2 + 0x364);
        guard_check_icall();
        (*pcVar1)();
      }
      else {
        pHVar3 = (HWND)0x0;
        if (in_ECX != 0) {
          pHVar3 = *(HWND *)(in_ECX + 0x20);
        }
        pHVar3 = SetParent(*(HWND *)(pCVar2 + 0x20),pHVar3);
        CWnd::FromHandle(pHVar3);
        *(undefined4 *)(pCVar2 + 0x90) = 0;
        pcVar1 = *(code **)(*(int *)pCVar2 + 0x1fc);
        guard_check_icall(*(undefined4 *)(pCVar2 + 0x1e8),*(undefined4 *)(pCVar2 + 0x1ec),
                          *(undefined4 *)(pCVar2 + 0x1f0),*(undefined4 *)(pCVar2 + 500),2,1);
        (*pcVar1)();
      }
    }
    SendMessageW(*(HWND *)(param_1 + 0x20),0x10,0,0);
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CMDIFrameWndEx[31] */
/* 0084e330  FUN_0084e330  33 bytes, 0 callers */

void FUN_0084e330(int param_1)

{
  int in_ECX;
  
  if ((param_1 == 0) && (*(int *)(in_ECX + 0x138) != 0)) {
    OnContextHelp();
    return;
  }
  FUN_00795838();
  return;
}



