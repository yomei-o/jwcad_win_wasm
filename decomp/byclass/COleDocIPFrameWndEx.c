/* COleDocIPFrameWndEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDocIPFrameWndEx[32], COleIPFrameWndEx[32] */
/* 0084e4e9  FUN_0084e4e9  33 bytes, 0 callers */

void FUN_0084e4e9(int param_1)

{
  int in_ECX;
  
  if ((param_1 == 0) && (*(int *)(in_ECX + 0x19c) != 0)) {
    OnContextHelp();
    return;
  }
  FUN_00792e01();
  return;
}




/* vtable slots: COleDocIPFrameWndEx[112], COleIPFrameWndEx[112] */
/* 0084e734  FUN_0084e734  156 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0084e734(CObject *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  COleCntrFrameWndEx *this;
  HWND__ *pHVar3;
  COleIPFrameWnd *in_ECX;
  CWnd *this_00;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleCntrFrameWndEx_00996120,param_1);
  if (pCVar2 == (CObject *)0x0) {
    this = (COleCntrFrameWndEx *)FUN_0078e624(0x318);
    this_00 = (CWnd *)0x0;
    if (this != (COleCntrFrameWndEx *)0x0) {
      this_00 = (CWnd *)COleCntrFrameWndEx::COleCntrFrameWndEx(this,in_ECX);
    }
    pHVar3 = CWnd::Detach(*(CWnd **)(in_ECX + 0x140));
    if (*(int **)(in_ECX + 0x140) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x140) + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    *(CWnd **)(in_ECX + 0x140) = this_00;
    CWnd::Attach(this_00,pHVar3);
    CDockingManager::Create((CDockingManager *)(this_00 + 0x128),(CFrameWnd *)this_00);
  }
  return 1;
}




/* vtable slots: COleDocIPFrameWndEx[31], COleIPFrameWndEx[31] */
/* 0084ed9d  FUN_0084ed9d  33 bytes, 0 callers */

void FUN_0084ed9d(int param_1)

{
  int in_ECX;
  
  if ((param_1 == 0) && (*(int *)(in_ECX + 0x19c) != 0)) {
    OnContextHelp();
    return;
  }
  FUN_00795838();
  return;
}




/* vtable slots: COleDocIPFrameWndEx[1] */
/* 0084ee35  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void * __thiscall COleDocIPFrameWndEx::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
COleDocIPFrameWndEx::_scalar_deleting_destructor_(COleDocIPFrameWndEx *this,uint param_1)

{
  FUN_0084ee0e();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x498);
    }
  }
  return this;
}




/* vtable slots: COleDocIPFrameWndEx[121] */
/* 0084ee84  FUN_0084ee84  82 bytes, 0 callers */

void FUN_0084ee84(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int in_ECX;
  UINT uCmd;
  
  uCmd = 5;
  while( true ) {
    pHVar3 = GetWindow(*(HWND *)(in_ECX + 0x20),uCmd);
    pCVar4 = CWnd::FromHandle(pHVar3);
    if (pCVar4 == (CWnd *)0x0) break;
    iVar2 = FUN_0079d98a(&PTR_s_CBasePane_0098a7f8);
    if (iVar2 == 0) break;
    uCmd = 2;
  }
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2a8) + 0x38);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: COleDocIPFrameWndEx[10] */
/* 0084ef15  FUN_0084ef15  6 bytes, 0 callers */

undefined ** FUN_0084ef15(void)

{
  return &PTR_FUN_00995348;
}




/* vtable slots: COleDocIPFrameWndEx[0] */
/* 0084ef42  FUN_0084ef42  6 bytes, 0 callers */

undefined ** FUN_0084ef42(void)

{
  return &PTR_s_COleDocIPFrameWndEx_00994f98;
}




/* vtable slots: COleDocIPFrameWndEx[90] */
/* 0084ef75  LoadFrame  50 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual int __thiscall COleDocIPFrameWndEx::LoadFrame(unsigned int,unsigned long,class
   CWnd *,struct CCreateContext *)
    public: virtual int __thiscall COleIPFrameWndEx::LoadFrame(unsigned int,unsigned long,class CWnd
   *,struct CCreateContext *)
   
   Library: Visual Studio 2015 Release */

void LoadFrame(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1b0) = param_1;
  CFrameImpl::LoadLargeIconsState((CFrameImpl *)(in_ECX + 0x1a4));
  FUN_0079a184(param_1,param_2,param_3,param_4);
  return;
}




/* vtable slots: COleDocIPFrameWndEx[125] */
/* 0084f057  FUN_0084f057  37 bytes, 0 callers */

void FUN_0084f057(uint param_1)

{
  DAT_00a139c8 = DAT_00a139c8 & -(uint)(DAT_00a139c8 != param_1);
  FUN_00848045();
  return;
}




/* vtable slots: COleDocIPFrameWndEx[3] */
/* 0084f07c  OnCmdMsg  60 bytes, 0 callers */

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
  
  iVar1 = FUN_0079aebf(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    uVar2 = FUN_00848731(param_1,param_2,param_3,param_4);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: COleDocIPFrameWndEx[61] */
/* 0084f0b8  FUN_0084f0b8  108 bytes, 0 callers */

undefined4 FUN_0084f0b8(uint param_1,undefined4 param_2)

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
    uVar2 = FUN_0079af63(param_1,param_2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: COleDocIPFrameWndEx[122] */
/* 0084f293  FUN_0084f293  37 bytes, 0 callers */

void FUN_0084f293(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2a8) + 0x3c);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: COleDocIPFrameWndEx[101] */
/* 0084f2f6  FUN_0084f2f6  72 bytes, 0 callers */

void FUN_0084f2f6(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int *in_ECX;
  
  FUN_0084a874(param_1,param_2);
  uVar1 = *(undefined4 *)(param_2 + 8);
  FUN_0079bd2d(param_1,param_2);
  *(undefined4 *)(param_2 + 8) = uVar1;
  pcVar2 = *(code **)(*in_ECX + 0x178);
  guard_check_icall(1);
  (*pcVar2)();
  return;
}




/* vtable slots: COleDocIPFrameWndEx[124] */
/* 0084f33e  FUN_0084f33e  27 bytes, 0 callers */

undefined4 FUN_0084f33e(undefined4 param_1,undefined4 param_2)

{
  FUN_0087aef5(param_1,param_2);
  return 1;
}




/* vtable slots: COleDocIPFrameWndEx[120] */
/* 0084f359  FUN_0084f359  67 bytes, 0 callers */

undefined4 FUN_0084f359(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(in_ECX[0xaa] + 0x50);
  guard_check_icall(param_1);
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1e4);
  guard_check_icall(0);
  (*pcVar1)();
  return uVar2;
}




/* vtable slots: COleDocIPFrameWndEx[25] */
/* 0084f449  PreCreateWindow  21 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall COleDocIPFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA
   &)
    protected: virtual int __thiscall COleDocIPFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTW
   &)
    protected: virtual int __thiscall COleIPFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall COleIPFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void PreCreateWindow(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 600) = in_ECX + 0x2a8;
  PreCreateWindow();
  return;
}




/* vtable slots: COleDocIPFrameWndEx[67] */
/* 0084f45e  FUN_0084f45e  385 bytes, 0 callers */

undefined4 FUN_0084f45e(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  CWnd *pCVar3;
  BOOL BVar4;
  undefined4 uVar5;
  tagPOINT local_14;
  tagPOINT local_c;
  
  uVar1 = param_1[1];
  if (uVar1 < 0x202) {
    if (uVar1 != 0x201) {
      if (uVar1 < 0xa8) {
        if (((uVar1 != 0xa7) && (uVar1 != 0xa1)) &&
           ((uVar1 != 0xa2 && ((uVar1 != 0xa4 && (uVar1 != 0xa5)))))) goto LAB_0084f5d2;
LAB_0084f4a9:
        iVar2 = FUN_0087cf79(uVar1,(int)*(short *)(param_1 + 3),(int)*(short *)((int)param_1 + 0xe),
                             *param_1);
      }
      else {
        if (uVar1 == 0xa8) goto LAB_0084f4a9;
        if (uVar1 == 0x100) {
          iVar2 = IsHelpKey(param_1);
          if (iVar2 != 0) goto LAB_0084f5d2;
          iVar2 = FUN_0087cca9(param_1[2],0);
        }
        else {
          if (uVar1 != 0x200) goto LAB_0084f5d2;
          local_c.x = (LONG)*(short *)(param_1 + 3);
          local_c.y = (LONG)*(short *)((int)param_1 + 0xe);
          pCVar3 = CWnd::FromHandle((HWND__ *)*param_1);
          if (pCVar3 != (CWnd *)0x0) {
            ClientToScreen(*(HWND *)(pCVar3 + 0x20),&local_c);
          }
          iVar2 = FUN_0087d5d0(local_c.x,local_c.y);
        }
      }
      if (iVar2 != 0) {
        return 1;
      }
      goto LAB_0084f5d2;
    }
  }
  else if (((((uVar1 != 0x203) && (uVar1 != 0x204)) && (uVar1 != 0x205)) &&
           ((uVar1 != 0x206 && (uVar1 != 0x207)))) && ((uVar1 != 0x208 && (uVar1 != 0x209))))
  goto LAB_0084f5d2;
  local_14.x = (LONG)*(short *)(param_1 + 3);
  local_14.y = (LONG)*(short *)((int)param_1 + 0xe);
  local_c.y = (LONG)CWnd::FromHandle((HWND__ *)*param_1);
  if (((CWnd *)local_c.y != (CWnd *)0x0) && (BVar4 = IsWindow((HWND)*param_1), BVar4 != 0)) {
    ClientToScreen(*(HWND *)(local_c.y + 0x20),&local_14);
  }
  iVar2 = FUN_0087cf79(param_1[1],local_14.x,local_14.y,*param_1);
  if ((iVar2 != 0) || (BVar4 = IsWindow((HWND)*param_1), BVar4 == 0)) {
    return 1;
  }
LAB_0084f5d2:
  uVar5 = FUN_0079c475(param_1);
  return uVar5;
}




/* vtable slots: COleDocIPFrameWndEx[94] */
/* 0084f5df  FUN_0084f5df  166 bytes, 0 callers */

void FUN_0084f5df(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0089a29f(param_1);
  if (*(int *)(in_ECX + 0xf4) == 0) {
    *(undefined4 *)(in_ECX + 0xf4) = 1;
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x2a8) + 0x34);
    guard_check_icall(param_1);
    (*pcVar1)();
    iVar2 = FUN_00799e17();
    if (iVar2 != 0) {
      iVar2 = FUN_0079d98a(&PTR_s_CPreviewViewEx_009a3618);
      if ((iVar2 != 0) && (*(int *)(in_ECX + 0x3d8) != 0)) {
        FUN_00797e71(0,*(int *)(in_ECX + 0x3a0),*(int *)(in_ECX + 0x3a4),
                     *(int *)(in_ECX + 0x3a8) - *(int *)(in_ECX + 0x3a0),
                     *(int *)(in_ECX + 0x3ac) - *(int *)(in_ECX + 0x3a4),0x14);
      }
    }
    *(undefined4 *)(in_ECX + 0xf4) = 0;
  }
  return;
}



