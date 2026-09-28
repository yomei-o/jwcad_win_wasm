/* COleIPFrameWndEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleIPFrameWndEx[1] */
/* 0084e3d6  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void * __thiscall COleIPFrameWndEx::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
COleIPFrameWndEx::_scalar_deleting_destructor_(COleIPFrameWndEx *this,uint param_1)

{
  FUN_0084e3af();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x4a0);
    }
  }
  return this;
}




/* vtable slots: COleIPFrameWndEx[121] */
/* 0084e425  FUN_0084e425  82 bytes, 0 callers */

void FUN_0084e425(undefined4 param_1)

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
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2ac) + 0x38);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: COleIPFrameWndEx[10] */
/* 0084e4b6  FUN_0084e4b6  6 bytes, 0 callers */

undefined ** FUN_0084e4b6(void)

{
  return &PTR_FUN_00994f90;
}




/* vtable slots: COleIPFrameWndEx[0] */
/* 0084e4e3  FUN_0084e4e3  6 bytes, 0 callers */

undefined ** FUN_0084e4e3(void)

{
  return &PTR_s_COleIPFrameWndEx_00994be0;
}




/* vtable slots: COleIPFrameWndEx[90] */
/* 0084e537  LoadFrame  50 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual int __thiscall COleDocIPFrameWndEx::LoadFrame(unsigned int,unsigned long,class
   CWnd *,struct CCreateContext *)
    public: virtual int __thiscall COleIPFrameWndEx::LoadFrame(unsigned int,unsigned long,class CWnd
   *,struct CCreateContext *)
   
   Library: Visual Studio 2015 Release */

void LoadFrame(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1b4) = param_1;
  CFrameImpl::LoadLargeIconsState((CFrameImpl *)(in_ECX + 0x1a8));
  FUN_0079a184(param_1,param_2,param_3,param_4);
  return;
}




/* vtable slots: COleIPFrameWndEx[125] */
/* 0084e621  FUN_0084e621  37 bytes, 0 callers */

void FUN_0084e621(uint param_1)

{
  DAT_00a139c8 = DAT_00a139c8 & -(uint)(DAT_00a139c8 != param_1);
  FUN_00848045();
  return;
}




/* vtable slots: COleIPFrameWndEx[3] */
/* 0084e646  OnCmdMsg  60 bytes, 0 callers */

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




/* vtable slots: COleIPFrameWndEx[61] */
/* 0084e682  FUN_0084e682  108 bytes, 0 callers */

undefined4 FUN_0084e682(uint param_1,undefined4 param_2)

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




/* vtable slots: COleIPFrameWndEx[122] */
/* 0084e93f  FUN_0084e93f  37 bytes, 0 callers */

void FUN_0084e93f(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2ac) + 0x3c);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: COleIPFrameWndEx[101] */
/* 0084e9a2  FUN_0084e9a2  72 bytes, 0 callers */

void FUN_0084e9a2(undefined4 param_1,int param_2)

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




/* vtable slots: COleIPFrameWndEx[124] */
/* 0084e9ea  FUN_0084e9ea  27 bytes, 0 callers */

undefined4 FUN_0084e9ea(undefined4 param_1,undefined4 param_2)

{
  FUN_0087aef5(param_1,param_2);
  return 1;
}




/* vtable slots: COleIPFrameWndEx[120] */
/* 0084ea05  FUN_0084ea05  67 bytes, 0 callers */

undefined4 FUN_0084ea05(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(in_ECX[0xab] + 0x50);
  guard_check_icall(param_1);
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1e4);
  guard_check_icall(0);
  (*pcVar1)();
  return uVar2;
}




/* vtable slots: COleIPFrameWndEx[25] */
/* 0084eaf5  PreCreateWindow  21 bytes, 0 callers */

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
  
  *(int *)(in_ECX + 0x25c) = in_ECX + 0x2ac;
  PreCreateWindow();
  return;
}




/* vtable slots: COleIPFrameWndEx[67] */
/* 0084eb0a  FUN_0084eb0a  385 bytes, 0 callers */

undefined4 FUN_0084eb0a(undefined4 *param_1)

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
           ((uVar1 != 0xa2 && ((uVar1 != 0xa4 && (uVar1 != 0xa5)))))) goto LAB_0084ec7e;
LAB_0084eb55:
        iVar2 = FUN_0087cf79(uVar1,(int)*(short *)(param_1 + 3),(int)*(short *)((int)param_1 + 0xe),
                             *param_1);
      }
      else {
        if (uVar1 == 0xa8) goto LAB_0084eb55;
        if (uVar1 == 0x100) {
          iVar2 = IsHelpKey(param_1);
          if (iVar2 != 0) goto LAB_0084ec7e;
          iVar2 = FUN_0087cca9(param_1[2],0);
        }
        else {
          if (uVar1 != 0x200) goto LAB_0084ec7e;
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
      goto LAB_0084ec7e;
    }
  }
  else if (((((uVar1 != 0x203) && (uVar1 != 0x204)) && (uVar1 != 0x205)) &&
           ((uVar1 != 0x206 && (uVar1 != 0x207)))) && ((uVar1 != 0x208 && (uVar1 != 0x209))))
  goto LAB_0084ec7e;
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
LAB_0084ec7e:
  uVar5 = FUN_0079c475(param_1);
  return uVar5;
}




/* vtable slots: COleIPFrameWndEx[94] */
/* 0084ec8b  FUN_0084ec8b  185 bytes, 0 callers */

void FUN_0084ec8b(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  FUN_007d0427(param_1);
  if (*(int *)(in_ECX + 0xf4) == 0) {
    *(undefined4 *)(in_ECX + 0xf4) = 1;
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x2ac) + 0x38);
    guard_check_icall(0);
    (*pcVar1)();
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x2ac) + 0x34);
    guard_check_icall(param_1);
    (*pcVar1)();
    iVar2 = FUN_00799e17();
    if (iVar2 != 0) {
      iVar2 = FUN_0079d98a(&PTR_s_CPreviewViewEx_009a3618);
      if ((iVar2 != 0) && (*(int *)(in_ECX + 0x3dc) != 0)) {
        FUN_00797e71(0,*(int *)(in_ECX + 0x3a4),*(int *)(in_ECX + 0x3a8),
                     *(int *)(in_ECX + 0x3ac) - *(int *)(in_ECX + 0x3a4),
                     *(int *)(in_ECX + 0x3b0) - *(int *)(in_ECX + 0x3a8),0x14);
      }
    }
    *(undefined4 *)(in_ECX + 0xf4) = 0;
  }
  return;
}



