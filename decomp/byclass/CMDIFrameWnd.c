/* CMDIFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMDIFrameWnd[112], CMDIFrameWndEx[112] */
/* 008a2835  FUN_008a2835  139 bytes, 0 callers */

bool FUN_008a2835(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  HWND hWnd;
  int in_ECX;
  uint uVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar3 = 0x56000001;
  if (param_2 == 0) {
    local_c = 0;
  }
  else {
    local_c = *(undefined4 *)(param_2 + 4);
  }
  local_8 = 0xff00;
  uVar1 = *(uint *)(param_1 + 0x20) & 0x300000;
  if (uVar1 != 0) {
    uVar3 = uVar1 | 0x56000001;
    FUN_00797c5d(0x300000,0,0x28);
  }
  iVar2 = FUN_0079dd6d();
  hWnd = (HWND)FUN_00797163(0x200,L"mdiclient",0,uVar3,0,0,0,0,*(undefined4 *)(in_ECX + 0x20),0xe900
                            ,*(undefined4 *)(iVar2 + 8),&local_c);
  *(HWND *)(in_ECX + 0x120) = hWnd;
  if (hWnd != (HWND)0x0) {
    BringWindowToTop(hWnd);
  }
  return hWnd != (HWND)0x0;
}




/* vtable slots: CMDIFrameWnd[71], CMDIFrameWndEx[71] */
/* 008a2939  FUN_008a2939  31 bytes, 0 callers */

void FUN_008a2939(UINT param_1,WPARAM param_2,LPARAM param_3)

{
  int in_ECX;
  
  DefFrameProcW(*(HWND *)(in_ECX + 0x20),*(HWND *)(in_ECX + 0x120),param_1,param_2,param_3);
  return;
}




/* vtable slots: CMDIFrameWnd[108], CMDIFrameWndEx[108] */
/* 008a2958  FUN_008a2958  43 bytes, 0 callers */

void FUN_008a2958(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall(param_1);
  (*pcVar1)();
  in_ECX[0x46] = in_ECX[0x46] | 1;
  return;
}




/* vtable slots: CMDIFrameWnd[92], CMDIFrameWndEx[92] */
/* 008a29f7  GetActiveFrame  18 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CFrameWnd * __thiscall CMDIFrameWnd::GetActiveFrame(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

CFrameWnd * __thiscall CMDIFrameWnd::GetActiveFrame(CMDIFrameWnd *this)

{
  CMDIChildWnd *pCVar1;
  
  pCVar1 = MDIGetActive(this,(int *)0x0);
  if (pCVar1 == (CMDIChildWnd *)0x0) {
    pCVar1 = (CMDIChildWnd *)this;
  }
  return (CFrameWnd *)pCVar1;
}




/* vtable slots: CMDIFrameWnd[10] */
/* 008a2a46  FUN_008a2a46  6 bytes, 0 callers */

undefined ** FUN_008a2a46(void)

{
  return &PTR_FUN_0099fab8;
}




/* vtable slots: CMDIFrameWnd[0] */
/* 008a2a52  FUN_008a2a52  6 bytes, 0 callers */

undefined ** FUN_008a2a52(void)

{
  return &PTR_s_CMDIFrameWnd_0099f564;
}




/* vtable slots: CMDIFrameWnd[113] */
/* 008a2a9f  FUN_008a2a9f  114 bytes, 1 callers */

HMENU FUN_008a2a9f(HMENU param_1)

{
  int nPos;
  HMENU hMenu;
  int iVar1;
  UINT UVar2;
  int local_8;
  
  if (param_1 != (HMENU)0x0) {
    nPos = GetMenuItemCount(param_1);
    while (nPos != 0) {
      nPos = nPos + -1;
      hMenu = GetSubMenu(param_1,nPos);
      if (hMenu != (HMENU)0x0) {
        iVar1 = GetMenuItemCount(hMenu);
        local_8 = 0;
        if (0 < iVar1) {
          do {
            UVar2 = GetMenuItemID(hMenu,local_8);
            if ((0xe12f < UVar2) && (UVar2 < 0xe140)) {
              return hMenu;
            }
            local_8 = local_8 + 1;
          } while (local_8 < iVar1);
        }
      }
    }
  }
  return (HMENU)0x0;
}




/* vtable slots: CMDIFrameWnd[90] */
/* 008a2be7  LoadFrame  50 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMDIFrameWnd::LoadFrame(unsigned int,unsigned long,class CWnd
   *,struct CCreateContext *)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMDIFrameWnd::LoadFrame
          (CMDIFrameWnd *this,uint param_1,ulong param_2,CWnd *param_3,CCreateContext *param_4)

{
  int iVar1;
  HMENU pHVar2;
  
  iVar1 = FUN_0079a184(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    pHVar2 = GetMenu(*(HWND *)(this + 0x20));
    *(HMENU *)(this + 0x88) = pHVar2;
  }
  return (uint)(iVar1 != 0);
}




/* vtable slots: CMDIFrameWnd[3] */
/* 008a2cfb  FUN_008a2cfb  122 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008a2cfb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  CMDIChildWnd *pCVar2;
  int iVar3;
  undefined4 uVar4;
  CMDIFrameWnd *in_ECX;
  CPushRoutingFrame local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8a2d07;
  pCVar2 = CMDIFrameWnd::MDIGetActive(in_ECX,(int *)0x0);
  if (pCVar2 != (CMDIChildWnd *)0x0) {
    CPushRoutingFrame::CPushRoutingFrame(local_1c,(CFrameWnd *)in_ECX);
    local_8 = 0;
    pcVar1 = *(code **)(*(int *)pCVar2 + 0xc);
    guard_check_icall(param_1,param_2,param_3,param_4);
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      FUN_007996a0();
      return 1;
    }
    local_8 = 0xffffffff;
    FUN_007996a0();
  }
  uVar4 = FUN_0079aebf(param_1,param_2,param_3,param_4);
  return uVar4;
}




/* vtable slots: CMDIFrameWnd[61] */
/* 008a2d75  FUN_008a2d75  121 bytes, 1 callers */

undefined4 FUN_008a2d75(undefined4 param_1,int param_2)

{
  code *pcVar1;
  CMDIChildWnd *pCVar2;
  int iVar3;
  CMDIFrameWnd *in_ECX;
  
  pCVar2 = CMDIFrameWnd::MDIGetActive(in_ECX,(int *)0x0);
  if (((pCVar2 == (CMDIChildWnd *)0x0) ||
      (iVar3 = FUN_00790b35(pCVar2,*(undefined4 *)(pCVar2 + 0x20),0x111,param_1,param_2), iVar3 == 0
      )) && (iVar3 = FUN_0079af63(param_1,param_2), iVar3 == 0)) {
    if ((param_2 != 0) || (((ushort)param_1 & 0xf000) != 0xf000)) {
      return 0;
    }
    pcVar1 = *(code **)(*(int *)in_ECX + 0x11c);
    guard_check_icall(0x111,param_1,0);
    (*pcVar1)();
  }
  return 1;
}




/* vtable slots: CMDIFrameWnd[104] */
/* 008a2ea3  FUN_008a2ea3  94 bytes, 1 callers */

void FUN_008a2ea3(undefined4 param_1)

{
  code *pcVar1;
  CMenu *pCVar2;
  int iVar3;
  int iVar4;
  HMENU pHVar5;
  int *in_ECX;
  
  pCVar2 = (CMenu *)0x0;
  if (in_ECX[0x22] == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x6c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    iVar4 = GetMenuItemCount(*(HMENU *)(iVar3 + 4));
    pHVar5 = GetSubMenu(*(HMENU *)(iVar3 + 4),iVar4 + -2);
    pCVar2 = CMenu::FromHandle(pHVar5);
  }
  pcVar1 = *(code **)(*in_ECX + 0x1c0);
  guard_check_icall(param_1,pCVar2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMDIFrameWnd[106] */
/* 008a32b3  FUN_008a32b3  87 bytes, 1 callers */

void FUN_008a32b3(WPARAM param_1)

{
  code *pcVar1;
  CMDIChildWnd *pCVar2;
  CMDIFrameWnd *in_ECX;
  
  pCVar2 = CMDIFrameWnd::MDIGetActive(in_ECX,(int *)0x0);
  if (pCVar2 == (CMDIChildWnd *)0x0) {
    if (param_1 == 0) {
      param_1 = *(WPARAM *)(in_ECX + 0x88);
    }
    SendMessageW(*(HWND *)(in_ECX + 0x120),0x230,param_1,0);
  }
  else {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x1c4);
    guard_check_icall(1,pCVar2,param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMDIFrameWnd[105], CMDIFrameWndEx[105] */
/* 008a3412  FUN_008a3412  275 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a3412(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  CSimpleStringT<wchar_t,0> *pCVar4;
  CMDIFrameWnd *in_ECX;
  CMDIChildWnd *pCVar5;
  undefined1 local_18 [4];
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8a341e;
  uVar2 = FUN_00797b3d();
  if ((uVar2 & 0x8000) == 0) {
    return;
  }
  if (*(int **)(in_ECX + 0xac) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xac) + 0x68);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return;
    }
  }
  pCVar5 = (CMDIChildWnd *)0x0;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x16c);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (((param_1 != 0) &&
      (pCVar5 = CMDIFrameWnd::MDIGetActive(in_ECX,(int *)0x0), pCVar5 != (CMDIChildWnd *)0x0)) &&
     (uVar2 = FUN_00797b3d(), (uVar2 & 0x1000000) == 0)) {
    if (iVar3 == 0) {
      pcVar1 = *(code **)(*(int *)pCVar5 + 0x16c);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) goto LAB_008a34b6;
    }
    FUN_0079cd9f(*(undefined4 *)(iVar3 + 0x20));
    return;
  }
LAB_008a34b6:
  CStringT<>();
  local_8 = 0;
  if ((pCVar5 == (CMDIChildWnd *)0x0) || (uVar2 = FUN_00797b3d(), (uVar2 & 0x1000000) != 0)) {
    iVar3 = 0;
  }
  else {
    pCVar4 = (CSimpleStringT<wchar_t,0> *)FUN_0082f3cd(local_18);
    local_8._0_1_ = 1;
    ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)local_14,pCVar4);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00406b10();
    iVar3 = 0;
    if (*(int *)(local_14[0] + -0xc) != 0) {
      iVar3 = local_14[0];
    }
  }
  FUN_0079cd9f(iVar3);
  FUN_00406b10();
  return;
}




/* vtable slots: CMDIFrameWnd[25] */
/* 008a366b  PreCreateWindow  35 bytes, 1 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual int __thiscall CMDIFrameWnd::PreCreateWindow(struct tagCREATESTRUCTA &)
    public: virtual int __thiscall CMDIFrameWnd::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 PreCreateWindow(int param_1)

{
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_00790c5e(4);
    *(wchar_t **)(param_1 + 0x28) = L"AfxMDIFrame140su";
  }
  return 1;
}




/* vtable slots: CMDIFrameWnd[67] */
/* 008a3707  FUN_008a3707  231 bytes, 1 callers */

undefined4 FUN_008a3707(LPMSG param_1)

{
  code *pcVar1;
  int iVar2;
  CMDIChildWnd *pCVar3;
  BOOL BVar4;
  undefined4 uVar5;
  CMDIFrameWnd *in_ECX;
  
  if ((param_1->message == 0x201) || (param_1->message == 0xa1)) {
    AfxCancelModes(param_1->hwnd);
  }
  iVar2 = FUN_007949fb(param_1);
  if (iVar2 == 0) {
    if (*(int **)(in_ECX + 0xac) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0xac) + 0x54);
      guard_check_icall(param_1);
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) goto LAB_008a37e4;
    }
    pCVar3 = CMDIFrameWnd::MDIGetActive(in_ECX,(int *)0x0);
    if (pCVar3 != (CMDIChildWnd *)0x0) {
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x10c);
      guard_check_icall(param_1);
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) goto LAB_008a37e4;
    }
    if (param_1->message - 0x100 < 10) {
      if (*(HACCEL *)(in_ECX + 0x8c) != (HACCEL)0x0) {
        iVar2 = TranslateAcceleratorW(*(HWND *)(in_ECX + 0x20),*(HACCEL *)(in_ECX + 0x8c),param_1);
        if (iVar2 != 0) goto LAB_008a37e4;
      }
      iVar2 = FUN_00799e17();
      if ((iVar2 == 0) && ((param_1->message == 0x100 || (param_1->message == 0x104)))) {
        BVar4 = TranslateMDISysAccel(*(HWND *)(in_ECX + 0x120),param_1);
        if (BVar4 != 0) goto LAB_008a37e4;
      }
    }
    uVar5 = 0;
  }
  else {
LAB_008a37e4:
    uVar5 = 1;
  }
  return uVar5;
}




/* vtable slots: CMDIFrameWnd[99], CMDIFrameWndEx[99] */
/* 008a3807  FUN_008a3807  24 bytes, 0 callers */

undefined4 FUN_008a3807(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x100) == 2) {
    return 0;
  }
  uVar1 = FUN_0079c986();
  return uVar1;
}




/* vtable slots: CMDIFrameWnd[97], CMDIFrameWndEx[97] */
/* 008a381f  FUN_008a381f  18 bytes, 0 callers */

void FUN_008a381f(int param_1)

{
  if (param_1 == 1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



