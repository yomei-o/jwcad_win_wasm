/* CMDIChildWndEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMDIChildWndEx[1] */
/* 0084f879  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void * __thiscall CMDIChildWndEx::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMDIChildWndEx::_scalar_deleting_destructor_(CMDIChildWndEx *this,uint param_1)

{
  ~CMDIChildWndEx(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x4e0);
    }
  }
  return this;
}




/* vtable slots: CMDIChildWndEx[95] */
/* 0084f8e5  ActivateFrame  160 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMDIChildWndEx::ActivateFrame(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMDIChildWndEx::ActivateFrame(CMDIChildWndEx *this,int param_1)

{
  HWND pHVar1;
  CWnd *pCVar2;
  uint uVar3;
  
  pHVar1 = GetParent(*(HWND *)(this + 0x20));
  pCVar2 = CWnd::FromHandle(pHVar1);
  if (((DAT_00a0092c == 0) && (pCVar2 != (CWnd *)0x0)) && (*(int *)(pCVar2 + 0x20) != 0)) {
    SendMessageW(*(HWND *)(pCVar2 + 0x20),0xb,0,0);
    FUN_008a2580(param_1);
    SendMessageW(*(HWND *)(pCVar2 + 0x20),0xb,1,0);
    RedrawWindow(*(HWND *)(pCVar2 + 0x20),(RECT *)0x0,(HRGN)0x0,0x185);
  }
  else {
    uVar3 = FUN_00797b3d();
    if ((uVar3 & 0x80000) == 0) {
      param_1 = 3;
    }
    if ((*(int *)(this + 0x448) != 0) && (*(int *)(*(int *)(this + 0x448) + 0x2f88) != 0)) {
      param_1 = 1;
    }
    FUN_008a2580(param_1);
  }
  return;
}




/* vtable slots: CMDIChildWndEx[136] */
/* 0084f985  FUN_0084f985  142 bytes, 0 callers */

void FUN_0084f985(void)

{
  code *pcVar1;
  CObject *pCVar2;
  WPARAM wParam;
  BOOL BVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  pCVar2 = (CObject *)FUN_00792b4c();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar2);
  if (pCVar2 != (CObject *)0x0) {
    pcVar1 = *(code **)(*in_ECX + 0x17c);
    guard_check_icall(0xffffffff);
    (*pcVar1)();
    SetForegroundWindow(*(HWND *)(pCVar2 + 0x20));
    wParam = IsIconic(*(HWND *)(pCVar2 + 0x20));
    FUN_00797f20((wParam != 0) * '\x04' + '\x05');
    PostMessageW(*(HWND *)(pCVar2 + 0x20),DAT_00a13ba4,wParam,in_ECX[8]);
    BVar3 = IsIconic(*(HWND *)(pCVar2 + 0x20));
    if (BVar3 == 0) {
      uVar4 = 5;
    }
    else {
      uVar4 = 9;
    }
    FUN_00797f20(uVar4);
  }
  return;
}




/* vtable slots: CMDIChildWndEx[115] */
/* 0084fbca  FUN_0084fbca  57 bytes, 0 callers */

void FUN_0084fbca(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x3a8) == 0) {
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x254) + 0x38);
    guard_check_icall(param_1);
    (*pcVar1)();
    FUN_0084facd();
  }
  return;
}




/* vtable slots: CMDIChildWndEx[121] */
/* 0084fca1  FUN_0084fca1  72 bytes, 0 callers */

undefined4 FUN_0084fca1(void)

{
  code *pcVar1;
  uint uVar2;
  CObject *pCVar3;
  int *in_ECX;
  
  uVar2 = FUN_00797b3d();
  if ((uVar2 & 0x10000000) == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall();
    pCVar3 = (CObject *)(*pcVar1)();
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleServerDoc_009860b8,pCVar3);
    if ((pCVar3 == (CObject *)0x0) || (*(int *)(pCVar3 + 0xa0) == 0)) {
      return 0;
    }
  }
  return 1;
}




/* vtable slots: CMDIChildWndEx[134] */
/* 0085024f  FUN_0085024f  40 bytes, 0 callers */

undefined4 FUN_0085024f(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x16c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + 0x24);
  }
  return uVar3;
}




/* vtable slots: CMDIChildWndEx[120] */
/* 00850277  GetFrameIcon  35 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual struct HICON__ * __thiscall CMDIChildWndEx::GetFrameIcon(void)const 
   
   Library: Visual Studio 2015 Release */

HICON__ * __thiscall CMDIChildWndEx::GetFrameIcon(CMDIChildWndEx *this)

{
  HICON__ *pHVar1;
  
  pHVar1 = (HICON__ *)SendMessageW(*(HWND *)(this + 0x20),0x7f,0,0);
  if (pHVar1 == (HICON__ *)0x0) {
    pHVar1 = (HICON__ *)GetClassLongW(*(HWND *)(this + 0x20),-0x22);
  }
  return pHVar1;
}




/* vtable slots: CMDIChildWndEx[119] */
/* 0085029a  FUN_0085029a  58 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0085029a(undefined4 param_1)

{
  CStringT<>();
  FUN_00792c64(param_1);
  return param_1;
}




/* vtable slots: CMDIChildWndEx[10] */
/* 008502d4  FUN_008502d4  6 bytes, 0 callers */

undefined ** FUN_008502d4(void)

{
  return &PTR_FUN_009959a8;
}




/* vtable slots: CMDIChildWndEx[0] */
/* 008502e0  FUN_008502e0  6 bytes, 0 callers */

undefined ** FUN_008502e0(void)

{
  return &PTR_s_CMDIChildWndEx_00995510;
}




/* vtable slots: CMDIChildWndEx[129] */
/* 008502ec  GetTaskbarPreviewWnd  108 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CWnd * __thiscall CMDIChildWndEx::GetTaskbarPreviewWnd(void)
   
   Library: Visual Studio 2015 Release */

CWnd * __thiscall CMDIChildWndEx::GetTaskbarPreviewWnd(CMDIChildWndEx *this)

{
  CWnd *pCVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  int iVar4;
  
  pCVar1 = CWnd::GetDescendantWindow(*(HWND__ **)(this + 0x20),0xe900,0);
  if ((pCVar1 == (CWnd *)0x0) || (*(int *)(pCVar1 + 0x20) == 0)) {
    pHVar2 = GetWindow(*(HWND *)(this + 0x20),5);
    pCVar1 = CWnd::FromHandle(pHVar2);
  }
  else {
    pHVar2 = GetParent(*(HWND *)(pCVar1 + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    if (((pCVar3 != (CWnd *)this) && (pCVar3 != (CWnd *)0x0)) && (*(int *)(pCVar3 + 0x20) != 0)) {
      iVar4 = FUN_0079d98a(&PTR_s_CSplitterWnd_0098116c);
      if (iVar4 != 0) {
        pCVar1 = pCVar3;
      }
    }
  }
  return pCVar1;
}




/* vtable slots: CMDIChildWndEx[133] */
/* 00850358  GetTaskbarThumbnailClipRect  37 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CRect __thiscall CMDIChildWndEx::GetTaskbarThumbnailClipRect(void)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

LPRECT __thiscall CMDIChildWndEx::GetTaskbarThumbnailClipRect(CMDIChildWndEx *this)

{
  LPRECT in_stack_00000004;
  
  in_stack_00000004->left = 0;
  in_stack_00000004->top = 0;
  in_stack_00000004->right = 0;
  in_stack_00000004->bottom = 0;
  GetWindowRect(*(HWND *)(this + 0x20),in_stack_00000004);
  return in_stack_00000004;
}




/* vtable slots: CMDIChildWndEx[114] */
/* 008504b4  IsTabbedMDIChild  28 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMDIChildWndEx::IsTabbedMDIChild(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMDIChildWndEx::IsTabbedMDIChild(CMDIChildWndEx *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(CMDIFrameWndEx **)(this + 0x448) != (CMDIFrameWndEx *)0x0) {
    iVar1 = CMDIFrameWndEx::AreMDITabs(*(CMDIFrameWndEx **)(this + 0x448),(int *)0x0);
    if (iVar1 != 0) {
      iVar2 = 1;
    }
  }
  return iVar2;
}




/* vtable slots: CMDIChildWndEx[116] */
/* 00850c3c  FUN_00850c3c  37 bytes, 0 callers */

void FUN_00850c3c(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x254) + 0x3c);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMDIChildWndEx[130] */
/* 00850e77  FUN_00850e77  124 bytes, 0 callers */

void FUN_00850e77(void)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  pCVar2 = (CObject *)FUN_00792b4c();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar2);
  if (pCVar2 != (CObject *)0x0) {
    iVar3 = FUN_00797c32();
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x16c);
      guard_check_icall();
      piVar4 = (int *)(*pcVar1)();
      if (piVar4 != (int *)0x0) {
        pcVar1 = *(code **)(*piVar4 + 0x60);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 != 0) {
          pcVar1 = *(code **)(*in_ECX + 0x220);
          guard_check_icall();
          (*pcVar1)();
        }
      }
      PostMessageW((HWND)in_ECX[8],0x10,0,0);
    }
  }
  return;
}




/* vtable slots: CMDIChildWndEx[101] */
/* 00851094  FUN_00851094  131 bytes, 0 callers */

void FUN_00851094(int param_1,int param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  CObject *pCVar3;
  int *in_ECX;
  
  pCVar3 = (CObject *)FUN_00404c80();
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar3);
  if (pCVar3 != (CObject *)0x0) {
    *(uint *)(pCVar3 + 0x15c) = -(uint)(param_1 != 0) & (uint)in_ECX;
  }
  FUN_0084a874(param_1,param_2);
  uVar1 = *(undefined4 *)(param_2 + 8);
  FUN_0079bd2d(param_1,param_2);
  *(undefined4 *)(param_2 + 8) = uVar1;
  pcVar2 = *(code **)(*in_ECX + 0x1cc);
  guard_check_icall(0);
  (*pcVar2)();
  pcVar2 = *(code **)(*in_ECX + 0x178);
  guard_check_icall(1);
  (*pcVar2)();
  return;
}




/* vtable slots: CMDIChildWndEx[131] */
/* 0085182d  FUN_0085182d  39 bytes, 0 callers */

void FUN_0085182d(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  if (param_1 == 1) {
    pcVar1 = *(code **)(*in_ECX + 0x220);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMDIChildWndEx[132] */
/* 00851854  FUN_00851854  63 bytes, 0 callers */

undefined4 FUN_00851854(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  CObject *pCVar2;
  int *in_ECX;
  
  pCVar2 = (CObject *)FUN_00792b4c();
  AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar2);
  if (param_3 == 0x202) {
    pcVar1 = *(code **)(*in_ECX + 0x220);
    guard_check_icall();
    (*pcVar1)();
  }
  return 1;
}




/* vtable slots: CMDIChildWndEx[128] */
/* 00851893  OnTaskbarTabThumbnailStretch  187 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual int __thiscall CMDIChildWndEx::OnTaskbarTabThumbnailStretch(struct HBITMAP__
   *,class CRect const &,struct HBITMAP__ *,class CRect const &)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMDIChildWndEx::OnTaskbarTabThumbnailStretch
          (CMDIChildWndEx *this,HBITMAP__ *param_1,CRect *param_2,HBITMAP__ *param_3,CRect *param_4)

{
  HDC pHVar1;
  HGDIOBJ h;
  int iVar2;
  CImage local_68 [4];
  HBITMAP__ *local_64;
  HDC local_30;
  CDC local_20 [4];
  HDC local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x85189f;
  if ((param_3 == (HBITMAP__ *)0x0) || (param_1 == (HBITMAP__ *)0x0)) {
    iVar2 = 0;
  }
  else {
    ATL::CImage::CImage(local_68);
    local_8 = 0;
    local_64 = param_3;
    FUN_007ce01d(0);
    FUN_0079dea2(this);
    local_8._0_1_ = 1;
    CDC::CDC(local_20);
    local_8 = CONCAT31(local_8._1_3_,2);
    pHVar1 = CreateCompatibleDC(local_30);
    FUN_0079e84a(pHVar1);
    h = SelectObject(local_1c,param_1);
    iVar2 = FUN_0084fe4b(local_1c,param_2,7);
    if (h != (HGDIOBJ)0x0) {
      SelectObject(local_1c,h);
    }
    FUN_0079e053();
    FUN_0079dfff();
    ATL::CImage::~CImage(local_68);
  }
  return iVar2;
}




/* vtable slots: CMDIChildWndEx[105] */
/* 0085194e  FUN_0085194e  218 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0085194e(undefined4 param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  int in_ECX;
  undefined1 local_18 [4];
  undefined1 local_14 [12];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x85195a;
  iVar3 = FUN_0084b004();
  if (iVar3 != 0) {
    BVar4 = IsWindowVisible(*(HWND *)(in_ECX + 0x20));
    if (BVar4 != 0) {
      uVar5 = FUN_00797b3d();
      if ((uVar5 & 0x1000000) == 0) {
        bVar1 = true;
        goto LAB_0085198f;
      }
    }
  }
  bVar1 = false;
LAB_0085198f:
  CStringT<>();
  local_8 = 0;
  if (bVar1) {
    FUN_00792c64(local_18);
  }
  FUN_008a330a(param_1);
  if (bVar1) {
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00792c64(local_14);
    cVar2 = FUN_00408c80(local_18,local_14);
    if (cVar2 != '\0') {
      SendMessageW(*(HWND *)(in_ECX + 0x20),0x85,0,0);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_00406b10();
  }
  if (*(int *)(in_ECX + 0x448) != 0) {
    FUN_0089665e(0);
  }
  FUN_00406b10();
  return;
}




/* vtable slots: CMDIChildWndEx[25] */
/* 00851ab4  PreCreateWindow  33 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CMDIChildWndEx::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall CMDIChildWndEx::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void PreCreateWindow(undefined4 param_1)

{
  CFrameWnd *in_ECX;
  
  CDockingManager::Create((CDockingManager *)(in_ECX + 0x254),in_ECX);
  FUN_008a3662(param_1);
  return;
}




/* vtable slots: CMDIChildWndEx[67] */
/* 00851ad5  FUN_00851ad5  119 bytes, 0 callers */

undefined4 FUN_00851ad5(int param_1)

{
  undefined4 uVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  int in_ECX;
  
  if (((*(int *)(param_1 + 4) - 0x100U < 10) && (*(int *)(in_ECX + 0x448) != 0)) &&
     (DAT_00a139c8 != 0)) {
    uVar1 = 0;
  }
  else {
    if (((*(int *)(param_1 + 4) == 0x100) && (*(int *)(param_1 + 8) == 0x1b)) &&
       (*(int *)(in_ECX + 0x128) != 0)) {
      pHVar2 = GetCapture();
      pCVar3 = CWnd::FromHandle(pHVar2);
      if (pCVar3 == *(CWnd **)(in_ECX + 0x128)) {
        PostMessageW(*(HWND *)(*(CWnd **)(in_ECX + 0x128) + 0x20),0x1f,0,0);
      }
    }
    uVar1 = FUN_008a368e(param_1);
  }
  return uVar1;
}




/* vtable slots: CMDIChildWndEx[94] */
/* 00851b4c  FUN_00851b4c  526 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00851b4c(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  CObject *pCVar7;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0xf4) != 0) {
    return;
  }
  *(undefined4 *)(in_ECX + 0xf4) = 1;
  if (*(int *)(in_ECX + 0x134) != 0) goto LAB_00851bbe;
  iVar2 = FUN_00799e17();
  if (*(int *)(in_ECX + 900) == 0) {
    iVar3 = FUN_0084785d();
    if (iVar3 != 0) goto LAB_00851bd4;
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x254) + 0x34);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  else {
LAB_00851bd4:
    if ((iVar2 != 0) && (iVar2 = FUN_0079d98a(&PTR_s_CPreviewViewEx_009a3618), iVar2 != 0)) {
      pcVar1 = *(code **)(*(int *)(in_ECX + 0x254) + 0x34);
      guard_check_icall(param_1);
      (*pcVar1)();
      iVar2 = *(int *)(in_ECX + 0x34c);
      iVar3 = *(int *)(in_ECX + 0x350);
      local_18.right = *(int *)(in_ECX + 0x354);
      local_18.bottom = *(int *)(in_ECX + 0x358);
      iVar4 = local_18.bottom - iVar3;
      iVar5 = local_18.right - iVar2;
      local_18.left = iVar2;
      local_18.top = iVar3;
LAB_00851d50:
      FUN_00797e71(0,iVar2,iVar3,iVar5,iVar4,0x14);
      goto LAB_00851bbe;
    }
    iVar2 = FUN_00799e17();
    if (iVar2 != 0) {
      piVar6 = (int *)FUN_0079296c();
      pcVar1 = *(code **)(*piVar6 + 0x170);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if ((iVar3 == in_ECX) && (*(int *)(in_ECX + 0x148) != 0)) {
        pCVar7 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleDocument_0098683c,
                                    *(CObject **)(iVar2 + 0x80));
        if (pCVar7 != (CObject *)0x0) {
          pcVar1 = *(code **)(*(int *)pCVar7 + 0x110);
          guard_check_icall(iVar2);
          iVar2 = (*pcVar1)();
          if (((param_1 != 0) && (iVar2 != 0)) && (*(int **)(iVar2 + 0x60) != (int *)0x0)) {
            pcVar1 = *(code **)(**(int **)(iVar2 + 0x60) + 0x50);
            guard_check_icall();
            (*pcVar1)();
          }
        }
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        iVar2 = FUN_0079296c();
        if ((iVar2 == 0) || (*(int *)(iVar2 + 0x20) == 0)) goto LAB_00851bbe;
        GetClientRect(*(HWND *)(iVar2 + 0x20),&local_18);
        iVar2 = FUN_00797a56((-(uint)(*(int *)(in_ECX + 900) != 0) & 0x121) + 0xe900);
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x20) != 0)) {
          FUN_0079d98a(&PTR_s_CSplitterWnd_0098116c);
        }
        iVar4 = local_18.bottom - local_18.top;
        iVar5 = local_18.right - local_18.left;
        iVar3 = 0;
        iVar2 = 0;
        goto LAB_00851d50;
      }
    }
  }
  FUN_0084facd();
LAB_00851bbe:
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  return;
}




/* vtable slots: CMDIChildWndEx[118] */
/* 00851d5a  FUN_00851d5a  570 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00851d5a(int param_1)

{
  int iVar1;
  code *pcVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  uint uVar5;
  CMDIChildWnd *pCVar6;
  CMDIChildWndEx *in_ECX;
  undefined4 uVar7;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x851d66;
  iVar1 = FUN_008504d0();
  if ((iVar1 == 0) || ((in_ECX + 0x450 != (CMDIChildWndEx *)0x0 && (*(int *)(in_ECX + 0x470) != 0)))
     ) goto LAB_00851f8c;
  *(CMDIChildWndEx **)(in_ECX + 0x4d0) = in_ECX;
  local_24 = 0xffff8300;
  local_20 = 0xffff8300;
  local_1c = 0xffff830a;
  local_18 = 0xffff830a;
  FUN_007c2511();
  FUN_007e5eba(&local_34,L"AFX_SUPERBAR_TAB");
  local_8 = 0;
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00792c64(&local_2c);
  pcVar2 = *(code **)(*(int *)(in_ECX + 0x450) + 0x58);
  guard_check_icall(0x8000080,local_34,local_2c,0x80cf0000,&local_24,0,0,0);
  iVar1 = (*pcVar2)();
  if (iVar1 != 0) {
    FUN_007c2511();
    pcVar2 = (code *)FUN_007e5c49();
    local_28 = pcVar2;
    if (pcVar2 == (code *)0x0) {
LAB_00851f5a:
      *(undefined4 *)(in_ECX + 0x4d8) = 1;
      iVar1 = CMDIChildWndEx::IsRegisteredWithTaskbarTabs(in_ECX);
      if (iVar1 != 0) {
        FUN_0085038c();
      }
    }
    else {
      pCVar3 = (CObject *)FUN_00792b4c();
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar3);
      pcVar2 = *(code **)(*(int *)pcVar2 + 0x2c);
      uVar7 = 0;
      if (pCVar3 != (CObject *)0x0) {
        uVar7 = *(undefined4 *)(pCVar3 + 0x20);
      }
      if (in_ECX == (CMDIChildWndEx *)0xfffffbb0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(in_ECX + 0x470);
      }
      guard_check_icall(local_28,uVar4,uVar7);
      iVar1 = (*pcVar2)();
      if (-1 < iVar1) {
        if ((param_1 == 0) && (*(int *)(in_ECX + 0x448) != 0)) {
          param_1 = FUN_008935c1(in_ECX);
        }
        pcVar2 = local_28;
        uVar5 = -(uint)(param_1 != 0) & param_1 + 0x450U;
        local_28 = *(code **)(*(int *)local_28 + 0x34);
        if (uVar5 == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined4 *)(uVar5 + 0x20);
        }
        if (in_ECX == (CMDIChildWndEx *)0xfffffbb0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined4 *)(in_ECX + 0x470);
        }
        guard_check_icall(pcVar2,uVar4,uVar7);
        iVar1 = (*local_28)();
        if (-1 < iVar1) {
          if (*(CMDIFrameWnd **)(in_ECX + 0x448) != (CMDIFrameWnd *)0x0) {
            pCVar6 = CMDIFrameWnd::MDIGetActive(*(CMDIFrameWnd **)(in_ECX + 0x448),(int *)0x0);
            if (pCVar6 == (CMDIChildWnd *)in_ECX) {
              FUN_00851fa3();
            }
          }
          local_30 = 1;
          if (in_ECX == (CMDIChildWndEx *)0xfffffbb0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(undefined4 *)(in_ECX + 0x470);
          }
          FUN_007c49bf(uVar7,10,&local_30,4);
          if (in_ECX == (CMDIChildWndEx *)0xfffffbb0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(undefined4 *)(in_ECX + 0x470);
          }
          FUN_007c49bf(uVar7,7,&local_30,4);
          FUN_00852077(DAT_00a00934);
          pcVar2 = *(code **)(*(int *)in_ECX + 0x224);
          guard_check_icall(local_2c);
          (*pcVar2)();
          goto LAB_00851f5a;
        }
      }
      FUN_0085230f(1);
    }
  }
  FUN_00406b10();
  FUN_00406b10();
LAB_00851f8c:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMDIChildWndEx[137] */
/* 008520f2  FUN_008520f2  361 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008520f2(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  CObject *pCVar3;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *pCVar4;
  CSimpleStringT<wchar_t,0> *pCVar5;
  CMDIChildWndEx *in_ECX;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_24 [4];
  uint local_20;
  wchar_t local_1c [2];
  wchar_t local_18 [2];
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x8520fe;
  iVar2 = FUN_008504d0();
  if (iVar2 != 0) {
    iVar2 = CMDIChildWndEx::IsRegisteredWithTaskbarTabs(in_ECX);
    if ((iVar2 != 0) && (param_1 != 0)) {
      pCVar3 = (CObject *)FUN_00792b4c();
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar3);
      if (pCVar3 != (CObject *)0x0) {
        local_20 = FUN_00797b3d();
        if ((local_20 & 0x8000) == 0) {
          FUN_00797ece(param_1);
        }
        else {
          FUN_0082f3cd(local_1c);
          local_8 = 0;
          CStringT<>();
          local_8._0_1_ = 1;
          CStringT<>(param_1);
          local_8._0_1_ = 2;
          uVar1 = (undefined1)local_8;
          local_8._0_1_ = 2;
          if ((local_20 & 0x4000) == 0) {
            local_8._0_1_ = uVar1;
            pCVar4 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                      *)ATL::operator+((CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                        *)&local_20,local_1c);
            local_8._0_1_ = 5;
            pCVar5 = (CSimpleStringT<wchar_t,0> *)ATL::operator+(local_24,pCVar4);
            local_8 = CONCAT31(local_8._1_3_,6);
            ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)local_14,pCVar5);
            FUN_00406b10();
          }
          else {
            pCVar4 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                      *)ATL::operator+(local_24,local_18);
            local_8._0_1_ = 3;
            pCVar5 = (CSimpleStringT<wchar_t,0> *)
                     ATL::operator+((CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                     *)&local_20,pCVar4);
            local_8 = CONCAT31(local_8._1_3_,4);
            ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)local_14,pCVar5);
            FUN_00406b10();
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_00406b10();
          FUN_00797ece(local_14[0]);
          FUN_00406b10();
          FUN_00406b10();
          FUN_00406b10();
        }
      }
    }
  }
  return;
}




/* vtable slots: CMDIChildWndEx[135] */
/* 0085225b  FUN_0085225b  180 bytes, 0 callers */

undefined4 FUN_0085225b(void)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  CMDIChildWnd *pCVar4;
  int *piVar5;
  BOOL BVar6;
  CMDIChildWnd *in_ECX;
  undefined1 *puVar7;
  
  iVar2 = FUN_007c2511();
  puVar7 = (undefined1 *)0x0;
  if (*(int *)(iVar2 + 0x17c) != 0) {
    pCVar3 = (CObject *)FUN_00792b4c();
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar3);
    if ((pCVar3 != (CObject *)0x0) &&
       (pCVar4 = CMDIFrameWnd::MDIGetActive((CMDIFrameWnd *)pCVar3,(int *)0x0), pCVar4 == in_ECX)) {
      iVar2 = FUN_0079a141();
      if (iVar2 == 0) {
        CWnd::ScreenToClient((CWnd *)pCVar3,(tagRECT *)&stack0x00000004);
      }
      FUN_007c2511();
      piVar5 = (int *)FUN_007e5c49();
      if (piVar5 != (int *)0x0) {
        pcVar1 = *(code **)(*piVar5 + 0x50);
        iVar2 = FUN_0079a141();
        if ((iVar2 == 0) && (BVar6 = IsRectEmpty((RECT *)&stack0x00000004), BVar6 == 0)) {
          puVar7 = &stack0x00000004;
        }
        guard_check_icall(piVar5,*(undefined4 *)(pCVar3 + 0x20),puVar7);
        iVar2 = (*pcVar1)();
        if (-1 < iVar2) {
          return 1;
        }
      }
    }
  }
  return 0;
}




/* vtable slots: CMDIChildWndEx[124] */
/* 008523c5  UpdateTaskbarTabIcon  45 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMDIChildWndEx::UpdateTaskbarTabIcon(struct HICON__ *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMDIChildWndEx::UpdateTaskbarTabIcon(CMDIChildWndEx *this,HICON__ *param_1)

{
  if ((this != (CMDIChildWndEx *)0xfffffbb0) && (*(int *)(this + 0x470) != 0)) {
    SendMessageW(*(HWND *)(this + 0x470),0x80,0,(LPARAM)param_1);
  }
  return;
}



