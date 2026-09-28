/* CFrameWndEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFrameWndEx[1] */
/* 0084ac93  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void * __thiscall CFrameWndEx::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CFrameWndEx::_scalar_deleting_destructor_(CFrameWndEx *this,uint param_1)

{
  FUN_0084ac6c();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x430);
    }
  }
  return this;
}




/* vtable slots: CFrameWndEx[114] */
/* 0084ad83  FUN_0084ad83  219 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0084ad83(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  piVar2 = (int *)FUN_00797a56(0xe900);
  if (piVar2 == (int *)0x0) {
    return;
  }
  local_18 = *(int *)(in_ECX + 0x330) + *(int *)(in_ECX + 0x9c);
  local_14 = *(int *)(in_ECX + 0x334) + *(int *)(in_ECX + 0xa0);
  local_10 = *(int *)(in_ECX + 0x338) - *(int *)(in_ECX + 0xa4);
  local_c = *(int *)(in_ECX + 0x33c) - *(int *)(in_ECX + 0xa8);
  pcVar1 = *(code **)(*piVar2 + 0x68);
  guard_check_icall(&local_18,0);
  (*pcVar1)();
  iVar3 = FUN_0079d98a(&PTR_s_CSplitterWnd_0098116c);
  if (iVar3 == 0) {
    iVar3 = FUN_0079d98a(&PTR_s_CFormView_009849c8);
    uVar4 = 0x6000000;
    if (iVar3 == 0) goto LAB_0084ae23;
  }
  uVar4 = 0x4000000;
LAB_0084ae23:
  FUN_00797c5d(0,uVar4,0);
  FUN_00797e71(&DAT_00a11ce8,local_18,local_14,local_10 - local_18,local_c - local_14,0x10);
  return;
}




/* vtable slots: CFrameWndEx[112] */
/* 0084ae5e  FUN_0084ae5e  103 bytes, 0 callers */

void FUN_0084ae5e(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0xe3] == 0) {
    pcVar1 = *(code **)(in_ECX[0x8e] + 0x38);
    guard_check_icall(param_1);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x1c8);
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




/* vtable slots: CFrameWndEx[108] */
/* 0084aef5  FUN_0084aef5  46 bytes, 0 callers */

void FUN_0084aef5(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall(param_1);
  (*pcVar1)();
  FUN_00799bae(param_1);
  return;
}




/* vtable slots: CFrameWndEx[115], CMDIFrameWndEx[139] */
/* 0084af32  FUN_0084af32  111 bytes, 0 callers */

undefined4 FUN_0084af32(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  CObject *pCVar4;
  undefined4 uVar5;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x170);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if ((((iVar2 != 0) && (iVar2 = FUN_00799e17(), iVar2 != 0)) &&
      (iVar3 = FUN_0079d98a(&PTR_s_CPreviewViewEx_009a3618), iVar3 == 0)) &&
     (pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleDocument_0098683c,
                                  *(CObject **)(iVar2 + 0x80)), pCVar4 != (CObject *)0x0)) {
    pcVar1 = *(code **)(*(int *)pCVar4 + 0x110);
    guard_check_icall(iVar2);
    uVar5 = (*pcVar1)();
    return uVar5;
  }
  return 0;
}




/* vtable slots: CFrameWndEx[10] */
/* 0084afa1  FUN_0084afa1  6 bytes, 0 callers */

undefined ** FUN_0084afa1(void)

{
  return &PTR_FUN_009945c8;
}




/* vtable slots: CFrameWndEx[0] */
/* 0084afce  FUN_0084afce  6 bytes, 0 callers */

undefined ** FUN_0084afce(void)

{
  return &PTR_s_CFrameWndEx_00994040;
}




/* vtable slots: CFrameWndEx[32] */
/* 0084afd4  FUN_0084afd4  33 bytes, 0 callers */

void FUN_0084afd4(int param_1)

{
  int in_ECX;
  
  if ((param_1 == 0) && (*(int *)(in_ECX + 0x124) != 0)) {
    OnContextHelp();
    return;
  }
  FUN_00792e01();
  return;
}




/* vtable slots: CFrameWndEx[90] */
/* 0084b054  LoadFrame  68 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CFrameWndEx::LoadFrame(unsigned int,unsigned long,class CWnd
   *,struct CCreateContext *)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CFrameWndEx::LoadFrame
          (CFrameWndEx *this,uint param_1,ulong param_2,CWnd *param_3,CCreateContext *param_4)

{
  int iVar1;
  
  *(uint *)(this + 0x140) = param_1;
  CFrameImpl::LoadLargeIconsState((CFrameImpl *)(this + 0x134));
  iVar1 = FUN_0079a184(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    FUN_0087c092();
  }
  return (uint)(iVar1 != 0);
}




/* vtable slots: CFrameWndEx[103] */
/* 0084b098  FUN_0084b098  93 bytes, 0 callers */

undefined4 FUN_0084b098(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (param_1 == 1) {
    FUN_0079a2a0(1,param_2);
    uVar3 = *(undefined4 *)(in_ECX + 0x334);
    uVar1 = *(undefined4 *)(in_ECX + 0x338);
    uVar2 = *(undefined4 *)(in_ECX + 0x33c);
    if (param_2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    *param_2 = *(undefined4 *)(in_ECX + 0x330);
    param_2[1] = uVar3;
    param_2[2] = uVar1;
    param_2[3] = uVar2;
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    uVar3 = FUN_0079a2a0(3,param_2);
    return uVar3;
  }
  return 1;
}




/* vtable slots: CFrameWndEx[118] */
/* 0084b1e2  OnClosePopupMenu  115 bytes, 0 callers */

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




/* vtable slots: CFrameWndEx[3] */
/* 0084b255  OnCmdMsg  60 bytes, 0 callers */

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




/* vtable slots: CFrameWndEx[61] */
/* 0084b291  FUN_0084b291  108 bytes, 0 callers */

undefined4 FUN_0084b291(uint param_1,undefined4 param_2)

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




/* vtable slots: CFrameWndEx[119] */
/* 0084b479  FUN_0084b479  25 bytes, 0 callers */

undefined4 FUN_0084b479(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x230) != 0) {
    uVar1 = FUN_008b2b64();
    return uVar1;
  }
  return 0;
}




/* vtable slots: CFrameWndEx[113] */
/* 0084b5b4  FUN_0084b5b4  37 bytes, 0 callers */

void FUN_0084b5b4(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x238) + 0x3c);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CFrameWndEx[101] */
/* 0084b754  FUN_0084b754  178 bytes, 0 callers */

void FUN_0084b754(WPARAM param_1,int param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  CObject *pCVar3;
  int *in_ECX;
  
  pCVar3 = DAT_00a13a1c;
  if (DAT_00a13a1c == (CObject *)0x0) {
    pCVar3 = (CObject *)FUN_00792b4c();
  }
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWndEx_00994040,pCVar3);
  if (pCVar3 != (CObject *)0x0) {
    *(uint *)(pCVar3 + 0x428) = -(uint)(param_1 != 0) & (uint)in_ECX;
  }
  FUN_0084a874(param_1,param_2);
  uVar1 = *(undefined4 *)(param_2 + 8);
  FUN_0079bd2d(param_1,param_2);
  *(undefined4 *)(param_2 + 8) = uVar1;
  pcVar2 = *(code **)(*in_ECX + 0x1c0);
  guard_check_icall(0);
  (*pcVar2)();
  pcVar2 = *(code **)(*in_ECX + 0x178);
  guard_check_icall(1);
  (*pcVar2)();
  if ((in_ECX[0x8c] != 0) && (*(int *)(in_ECX[0x8c] + 0x328) != 0)) {
    PostMessageW((HWND)in_ECX[8],DAT_00a13be0,param_1,0);
  }
  return;
}




/* vtable slots: CFrameWndEx[117] */
/* 0084b82a  FUN_0084b82a  27 bytes, 0 callers */

undefined4 FUN_0084b82a(undefined4 param_1,undefined4 param_2)

{
  FUN_0087aef5(param_1,param_2);
  return 1;
}




/* vtable slots: CFrameWndEx[124] */
/* 0084b845  FUN_0084b845  67 bytes, 0 callers */

undefined4 FUN_0084b845(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(in_ECX[0x8e] + 0x50);
  guard_check_icall(param_1);
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1c0);
  guard_check_icall(0);
  (*pcVar1)();
  return uVar2;
}




/* vtable slots: CFrameWndEx[116], CMDIFrameWndEx[121] */
/* 0084b888  OnShowPopupMenu  45 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual int __thiscall CFrameWndEx::OnShowPopupMenu(class CMFCPopupMenu *)
    public: virtual int __thiscall CMDIFrameWndEx::OnShowPopupMenu(class CMFCPopupMenu *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 OnShowPopupMenu(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  if ((*(int *)(iVar1 + 0x19c) != 0) && (param_1 != 0)) {
    NotifyWinEvent(6,*(HWND *)(param_1 + 0x20),0,0);
  }
  return 1;
}




/* vtable slots: CFrameWndEx[106] */
/* 0084ba91  FUN_0084ba91  155 bytes, 0 callers */

void FUN_0084ba91(HMENU__ *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  COleClientItem *this;
  CWnd *pCVar4;
  CMenu *pCVar5;
  int *in_ECX;
  code *pcVar6;
  
  FUN_0079c28d(param_1);
  if ((in_ECX[0x78] == 0) || (uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  bVar2 = false;
  if ((in_ECX[0x8c] != 0) && (uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) != 0)) {
    bVar2 = true;
  }
  if ((!bVar1) && (!bVar2)) {
    return;
  }
  pcVar6 = *(code **)(*in_ECX + 0x1cc);
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




/* vtable slots: CFrameWndEx[105] */
/* 0084bb2c  FUN_0084bb2c  239 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0084bb2c(undefined4 param_1)

{
  bool bVar1;
  char cVar2;
  BOOL BVar3;
  int iVar4;
  int in_ECX;
  undefined1 local_18 [4];
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x84bb38;
  bVar1 = false;
  if ((*(int *)(in_ECX + 0x230) != 0) &&
     (((BVar3 = IsWindowVisible(*(HWND *)(*(int *)(in_ECX + 0x230) + 0x20)), BVar3 != 0 ||
       (BVar3 = IsWindowVisible(*(HWND *)(in_ECX + 0x20)), BVar3 == 0)) &&
      (*(int *)(*(int *)(in_ECX + 0x230) + 0x328) != 0)))) {
    bVar1 = true;
  }
  iVar4 = FUN_0084b004();
  if (((iVar4 != 0) && (BVar3 = IsWindowVisible(*(HWND *)(in_ECX + 0x20)), BVar3 != 0)) && (!bVar1))
  {
    CStringT<>();
    local_8 = 0;
    FUN_00792c64(local_18);
    FUN_0079c2fd(param_1);
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00792c64(local_14);
    cVar2 = FUN_00408c80(local_18,local_14);
    if (cVar2 != '\0') {
      SendMessageW(*(HWND *)(in_ECX + 0x20),0x85,0,0);
    }
    FUN_00406b10();
    FUN_00406b10();
    return;
  }
  FUN_0079c2fd(param_1);
  return;
}




/* vtable slots: CFrameWndEx[25] */
/* 0084bcb9  PreCreateWindow  57 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall CFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void PreCreateWindow(undefined4 param_1)

{
  CFrameWnd *in_ECX;
  
  CDockingManager::Create((CDockingManager *)(in_ECX + 0x238),in_ECX);
  *(CDockingManager **)(in_ECX + 0x1e8) = (CDockingManager *)(in_ECX + 0x238);
  FUN_0087d87d(param_1);
  PreCreateWindow(param_1);
  return;
}




/* vtable slots: CFrameWndEx[67] */
/* 0084bcf2  FUN_0084bcf2  938 bytes, 0 callers */

undefined4 FUN_0084bcf2(undefined4 *param_1)

{
  uint uVar1;
  SHORT SVar2;
  int iVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  undefined4 uVar7;
  BOOL BVar8;
  CFrameWnd *in_ECX;
  UINT Msg;
  tagPOINT local_20;
  tagPOINT local_18;
  int local_10;
  HIMC local_c;
  int local_8;
  
  local_8 = 1;
  uVar1 = param_1[1];
  if (uVar1 < 0x105) {
    if (uVar1 == 0x104) {
      if ((*(int *)(in_ECX + 0x230) == 0) ||
         (iVar3 = FUN_008b3d1d(in_ECX,param_1[2],param_1[3]), iVar3 == 0)) {
LAB_0084be2b:
        iVar3 = FUN_007c2511();
        if ((*(int *)(iVar3 + 0x1a4) == 0) && (iVar3 = FUN_007c2511(), *(int *)(iVar3 + 0x1a0) == 0)
           ) {
          iVar3 = FUN_007c2511();
          *(undefined4 *)(iVar3 + 0x1a0) = 1;
          FUN_00803a81();
        }
        if (((DAT_00a139c8 == (CObject *)0x0) ||
            (BVar8 = IsWindow(*(HWND *)(DAT_00a139c8 + 0x20)), BVar8 == 0)) || (param_1[2] != 0x12))
        {
          iVar3 = FUN_0087cca9(param_1[2],0);
          goto LAB_0084c08f;
        }
        Msg = 0x10;
        pCVar6 = DAT_00a139c8;
LAB_0084bdf1:
        SendMessageW(*(HWND *)(pCVar6 + 0x20),Msg,0,0);
      }
    }
    else {
      if (uVar1 < 0xa6) {
        if (uVar1 != 0xa5) {
          if (uVar1 == 0x7b) goto LAB_0084be2b;
          if (((uVar1 != 0xa1) && (uVar1 != 0xa2)) && (uVar1 != 0xa4)) goto LAB_0084bf2f;
        }
      }
      else if ((uVar1 != 0xa7) && (uVar1 != 0xa8)) {
        if (uVar1 == 0x100) {
          iVar3 = IsHelpKey(param_1);
          if ((iVar3 == 0) && (iVar3 = FUN_0087cca9(param_1[2],&local_8), iVar3 != 0))
          goto LAB_0084bdfa;
          if (param_1[2] == 0x1b) {
            if (*(int *)(in_ECX + 0x204) != 0) {
              FUN_008c1d1c(in_ECX);
            }
            iVar3 = *(int *)(in_ECX + 0x3f0);
            if (((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) && (*(int *)(iVar3 + 4) != 0)) {
              FUN_0086203b();
            }
            pHVar4 = GetCapture();
            pCVar5 = CWnd::FromHandle(pHVar4);
            pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,
                                        (CObject *)pCVar5);
            if (pCVar6 != (CObject *)0x0) {
              Msg = 0x1f;
              goto LAB_0084bdf1;
            }
          }
          if (local_8 == 0) {
            return 0;
          }
        }
        goto LAB_0084bf2f;
      }
      iVar3 = FUN_0087cf79(uVar1,(int)*(short *)(param_1 + 3),(int)*(short *)((int)param_1 + 0xe),
                           *param_1);
LAB_0084c08f:
      if (iVar3 == 0) goto LAB_0084bf2f;
    }
LAB_0084bdfa:
    uVar7 = 1;
  }
  else {
    if (0x205 < uVar1) {
      if ((uVar1 == 0x207) || (uVar1 == 0x208)) goto LAB_0084bec9;
      if (uVar1 != 0x20a) goto LAB_0084bf2f;
      iVar3 = FUN_0087d6c8(param_1[2],param_1[3]);
      goto LAB_0084c08f;
    }
    if (uVar1 != 0x205) {
      if (uVar1 == 0x105) {
        if ((*(CMFCRibbonBar **)(in_ECX + 0x230) != (CMFCRibbonBar *)0x0) &&
           (iVar3 = CMFCRibbonBar::OnSysKeyUp
                              (*(CMFCRibbonBar **)(in_ECX + 0x230),in_ECX,param_1[2],param_1[3]),
           iVar3 != 0)) goto LAB_0084bdfa;
        SVar2 = GetKeyState(0x11);
        local_18.y = (LONG)SVar2;
        SVar2 = GetKeyState(0x10);
        local_20.y = (LONG)SVar2;
        local_c = ImmGetContext(*(HWND *)(in_ECX + 0x20));
        if ((local_c == (HIMC)0x0) || (BVar8 = ImmGetOpenStatus(local_c), BVar8 == 0)) {
          local_10 = 0;
          if (local_c != (HIMC)0x0) goto LAB_0084bfdc;
        }
        else {
          local_10 = 1;
LAB_0084bfdc:
          ImmReleaseContext(*(HWND *)(in_ECX + 0x20),local_c);
        }
        if ((*(int *)(in_ECX + 0x1e0) != 0) &&
           ((param_1[2] == 0x12 ||
            ((((param_1[2] == 0x79 && ((local_18.y & 0x8000U) == 0)) &&
              ((local_20.y & 0x8000U) == 0)) && (local_10 == 0)))))) {
          pHVar4 = GetFocus();
          pCVar5 = CWnd::FromHandle(pHVar4);
          if (((*(CWnd **)(in_ECX + 0x1e0) == pCVar5) || (param_1[2] == 0x12)) ||
             ((param_1[3] & 0x20000000) == 0)) {
            FUN_00797df8();
          }
          goto LAB_0084bdfa;
        }
        if (DAT_00a139c8 == (CObject *)0x0) goto LAB_0084bf2f;
        iVar3 = IsWindow(*(HWND *)(DAT_00a139c8 + 0x20));
        goto LAB_0084c08f;
      }
      if (uVar1 == 0x200) {
        local_20.x = (LONG)*(short *)(param_1 + 3);
        local_20.y = (LONG)*(short *)((int)param_1 + 0xe);
        pCVar5 = CWnd::FromHandle((HWND__ *)*param_1);
        if (pCVar5 != (CWnd *)0x0) {
          ClientToScreen(*(HWND *)(pCVar5 + 0x20),&local_20);
        }
        iVar3 = FUN_0087d5d0(local_20.x,local_20.y);
        goto LAB_0084c08f;
      }
      if ((uVar1 != 0x201) && (uVar1 != 0x204)) goto LAB_0084bf2f;
    }
LAB_0084bec9:
    local_18.x = (LONG)*(short *)(param_1 + 3);
    local_18.y = (LONG)*(short *)((int)param_1 + 0xe);
    local_20.y = (LONG)CWnd::FromHandle((HWND__ *)*param_1);
    if (((CWnd *)local_20.y != (CWnd *)0x0) && (BVar8 = IsWindow((HWND)*param_1), BVar8 != 0)) {
      ClientToScreen(*(HWND *)(local_20.y + 0x20),&local_18);
    }
    iVar3 = FUN_0087cf79(param_1[1],local_18.x,local_18.y,*param_1);
    if ((iVar3 != 0) || (BVar8 = IsWindow((HWND)*param_1), BVar8 == 0)) goto LAB_0084bdfa;
LAB_0084bf2f:
    uVar7 = FUN_0079c475(param_1);
  }
  return uVar7;
}




/* vtable slots: CFrameWndEx[94] */
/* 0084c09c  FUN_0084c09c  448 bytes, 0 callers */

void FUN_0084c09c(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int *in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (in_ECX[0x3d] == 0) {
    iVar1 = in_ECX[0x58];
    in_ECX[0x3d] = 1;
    in_ECX[0x58] = 0;
    pcVar2 = *(code **)(*in_ECX + 0x1cc);
    guard_check_icall();
    iVar3 = (*pcVar2)();
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x60) != 0)) && (*(int *)(iVar3 + 0x50) == 4)) {
      in_ECX[0x58] = 1;
      uVar4 = FUN_00797b3d();
      in_ECX[0x59] = (uint)((uVar4 & 0xc00000) != 0);
    }
    if (in_ECX[0x4b] == 0) {
      iVar3 = FUN_00799e17();
      if ((in_ECX[0xda] == 0) && (in_ECX[0x2b] == 0)) {
        pcVar2 = *(code **)(in_ECX[0x8e] + 0x34);
        guard_check_icall(param_1);
        (*pcVar2)();
        pcVar2 = *(code **)(*in_ECX + 0x1c8);
        guard_check_icall();
        (*pcVar2)();
      }
      else if ((iVar3 == 0) || (iVar3 = FUN_0079d98a(&PTR_s_CPreviewViewEx_009a3618), iVar3 == 0)) {
        if ((param_1 == 0) || (in_ECX[0x2b] == 0)) {
          in_ECX[0x3d] = 0;
          FUN_0079c654(param_1);
          pcVar2 = *(code **)(*in_ECX + 0x1c8);
          guard_check_icall();
          (*pcVar2)();
        }
        else {
          FUN_0084acc6();
        }
      }
      else {
        pcVar2 = *(code **)(in_ECX[0x8e] + 0x34);
        guard_check_icall(param_1);
        (*pcVar2)();
        FUN_00797e71(0,in_ECX[0xcc],in_ECX[0xcd],in_ECX[0xce] - in_ECX[0xcc],
                     in_ECX[0xcf] - in_ECX[0xcd],0x14);
      }
    }
    in_ECX[0x3d] = 0;
    if (iVar1 != in_ECX[0x58]) {
      if (in_ECX[0x59] == 0) {
        if (in_ECX[0x58] == 0) {
          uVar6 = 0;
          uVar5 = 0xc00000;
        }
        else {
          uVar6 = 0xc00000;
          uVar5 = 0;
        }
        FUN_00797c5d(uVar5,uVar6,0);
      }
      FUN_0087b972();
      FUN_00797e71(0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x37);
    }
    return;
  }
  return;
}




/* vtable slots: CFrameWndEx[31] */
/* 0084c2e0  FUN_0084c2e0  33 bytes, 0 callers */

void FUN_0084c2e0(int param_1)

{
  int in_ECX;
  
  if ((param_1 == 0) && (*(int *)(in_ECX + 0x124) != 0)) {
    OnContextHelp();
    return;
  }
  FUN_00795838();
  return;
}



