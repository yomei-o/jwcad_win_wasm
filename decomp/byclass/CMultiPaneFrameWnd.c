/* CMultiPaneFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMultiPaneFrameWnd[140], CPaneFrameWnd[140] */
/* 0083eadf  AddButton  162 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual void __thiscall CPaneFrameWnd::AddButton(unsigned int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CPaneFrameWnd::AddButton(CPaneFrameWnd *this,uint param_1)

{
  int iVar1;
  CObject *pCVar2;
  
  iVar1 = FUN_0083f6d8(param_1);
  if (iVar1 == 0) {
    if (param_1 == 0x19) {
      iVar1 = FUN_0078e624(0x3c);
      if (iVar1 == 0) {
        pCVar2 = (CObject *)0x0;
      }
      else {
        pCVar2 = (CObject *)FUN_008b911f();
      }
      *(undefined4 *)(pCVar2 + 0x34) = 0;
      *(undefined4 *)(pCVar2 + 0x1c) = 0x19;
      CObList::AddHead((CObList *)(this + 0x108),pCVar2);
    }
    else {
      iVar1 = FUN_0078e624(0x30);
      if (iVar1 == 0) {
        pCVar2 = (CObject *)0x0;
      }
      else {
        pCVar2 = (CObject *)FUN_008aed61();
      }
      CObList::AddHead((CObList *)(this + 0x108),pCVar2);
      *(uint *)(pCVar2 + 0x1c) = param_1;
    }
    *(undefined4 *)(pCVar2 + 0x2c) = 1;
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[111], CPaneFrameWnd[111] */
/* 0083ef3b  FUN_0083ef3b  102 bytes, 0 callers */

void FUN_0083ef3b(LPRECT param_1)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if ((iVar2 != 0) || (in_ECX[0x27] == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x1a8);
    guard_check_icall();
    pCVar3 = (CObject *)(*pcVar1)();
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,pCVar3);
    if (pCVar3 == (CObject *)0x0) {
      iVar2 = 4;
      goto LAB_0083ef8d;
    }
  }
  iVar2 = 3;
LAB_0083ef8d:
  SetRect(param_1,iVar2,iVar2,iVar2,iVar2);
  return;
}




/* vtable slots: CMultiPaneFrameWnd[133], CPaneFrameWnd[133] */
/* 00840cd0  FUN_00840cd0  394 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00840cd0(int param_1)

{
  CWnd *pCVar1;
  int iVar2;
  CObject *pCVar3;
  HBRUSH hbr;
  int *piVar4;
  CWnd *in_ECX;
  code *pcVar5;
  RECT local_38;
  tagRECT local_28;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = *(int *)(in_ECX + 0x184);
  if (iVar2 == 0) {
    pCVar1 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 200));
    iVar2 = FUN_0085a847(pCVar1);
    if (iVar2 == 0) {
      return;
    }
  }
  if (*(int *)(iVar2 + 8) == 0) {
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_28);
    CWnd::ScreenToClient(in_ECX,&local_28);
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    pcVar5 = *(code **)(*(int *)in_ECX + 0x1bc);
    guard_check_icall(&local_18);
    (*pcVar5)();
    OffsetRect(&local_28,local_18,*(int *)(in_ECX + 0xac) + local_14);
    local_38.left = local_28.left;
    local_38.top = local_28.top;
    local_38.right = local_28.right;
    local_38.bottom = local_28.bottom;
    pcVar5 = *(code **)(*(int *)in_ECX + 0x1a8);
    guard_check_icall();
    pCVar3 = (CObject *)(*pcVar5)();
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,pCVar3);
    if (pCVar3 == (CObject *)0x0) {
      piVar4 = (int *)FUN_007c2574();
      pcVar5 = *(code **)(*piVar4 + 0x14c);
      guard_check_icall(param_1,in_ECX,local_38.left,local_38.top,local_38.right,local_38.bottom,
                        local_18,local_14,local_10,local_c);
    }
    else {
      iVar2 = FUN_007c2511();
      hbr = (HBRUSH)0x0;
      if (iVar2 != -0x98) {
        hbr = *(HBRUSH *)(iVar2 + 0x9c);
      }
      FillRect(*(HDC *)(param_1 + 4),&local_38,hbr);
      piVar4 = (int *)FUN_007c2574();
      pcVar5 = *(code **)(*piVar4 + 0x150);
      guard_check_icall(param_1,pCVar3,local_38.left,local_38.top,local_38.right,local_38.bottom,
                        local_18,local_14,local_10,local_c);
    }
    (*pcVar5)();
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[134], CPaneFrameWnd[134] */
/* 00840e5a  FUN_00840e5a  181 bytes, 0 callers */

int FUN_00840e5a(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint in_ECX;
  int local_c;
  uint local_8;
  
  local_c = *(int *)(in_ECX + 0x10c);
  iVar2 = 0;
  local_8 = in_ECX;
  while (local_c != 0) {
    piVar1 = (int *)FUN_0044f2d0(&local_c);
    local_8 = 1;
    piVar1 = (int *)*piVar1;
    iVar2 = FUN_008aee34();
    if (iVar2 == 9) {
      local_8 = ~-(uint)(*(int *)(in_ECX + 0x94) != 0) & 1;
    }
    if (((DAT_00a127ac == 0) || (iVar2 = FUN_008aee34(), iVar2 == 0x14)) ||
       (iVar2 = FUN_008aee34(), iVar2 == 0x13)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    iVar2 = *piVar1;
    piVar1[4] = uVar3;
    guard_check_icall(param_1,1,1,local_8,uVar3 ^ 1);
    (**(code **)(iVar2 + 0x10))();
    piVar1[8] = -1;
    iVar2 = in_ECX + 0x108;
  }
  return iVar2;
}




/* vtable slots: CMultiPaneFrameWnd[138], CPaneFrameWnd[138] */
/* 00842953  FUN_00842953  1053 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00842953(int param_1)

{
  code *pcVar1;
  CMFCPopupMenu *pCVar2;
  int *piVar3;
  CObject *pCVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *in_ECX;
  UINT in_stack_fffffc04;
  LPSTR in_stack_fffffc08;
  int in_stack_fffffc0c;
  undefined1 local_3ec [4];
  int *local_3e8;
  int *local_3e4;
  tagPOINT local_3e0;
  int local_3d8;
  int *local_3d4;
  int local_3d0;
  CMFCPopupMenu *local_3cc;
  int local_3c8 [59];
  undefined1 local_2dc [232];
  undefined1 local_1f4 [232];
  undefined1 local_10c [180];
  undefined4 local_58;
  int local_24;
  int local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3dc;
  local_8 = 0x842962;
  if ((DAT_00a127ac == 0) && (param_1 == 0x19)) {
    local_3e8 = in_ECX;
    piVar3 = (int *)FUN_0083f6d8(0x19);
    local_3e4 = piVar3;
    if (piVar3 == (int *)0x0) goto LAB_00842d63;
    pcVar1 = *(code **)(*in_ECX + 0x1a8);
    guard_check_icall();
    pCVar4 = (CObject *)(*pcVar1)();
    if ((pCVar4 == (CObject *)0x0) || (*(int *)(pCVar4 + 0x20) == 0)) goto LAB_00842d63;
    iVar5 = FUN_0079d98a(&PTR_s_CMFCToolBar_00a005c4);
    if (iVar5 == 0) goto LAB_00842d63;
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,pCVar4);
    local_3d0 = *(int *)(pCVar4 + 0xd14);
    if ((local_3d0 == 0) || (*(int *)(pCVar4 + 0xbc8) == 0)) goto LAB_00842d63;
    piVar3[1] = 1;
    CStringT<>();
    local_8._0_1_ = 0;
    local_8._1_3_ = 0;
    FUN_00792c64(local_3c8);
    ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimLeft
              ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)local_3c8);
    ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimRight
              ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)local_3c8);
    if (*(int *)(local_3c8[0] + -0xc) == 0) {
      iVar5 = FID_conflict_LoadStringA
                        ((HINSTANCE)0x3ee8,in_stack_fffffc04,in_stack_fffffc08,in_stack_fffffc0c);
      if (iVar5 == 0) goto LAB_00842d6b;
    }
    local_3d8 = FUN_0078e624(0x1178);
    local_8._0_1_ = 1;
    if (local_3d8 == 0) {
      local_3cc = (CMFCPopupMenu *)0x0;
    }
    else {
      local_3cc = (CMFCPopupMenu *)FUN_0081b772();
    }
    local_8._0_1_ = 0;
    local_3d8 = FUN_0078e624(0x1178);
    local_8._0_1_ = 2;
    if (local_3d8 == 0) {
      local_3d4 = (int *)0x0;
    }
    else {
      local_3d4 = (int *)FUN_0081b772();
    }
    piVar3 = local_3d4;
    local_8._0_1_ = 0;
    uVar6 = FUN_00874dc7(1,0,0xffffffff,L"DUMMY",0);
    local_8._0_1_ = 3;
    FUN_0081dea9(uVar6,0xffffffff);
    local_8._0_1_ = 0;
    FUN_00874eb0();
    pcVar1 = *(code **)(*piVar3 + 0x1c8);
    guard_check_icall();
    piVar3 = (int *)(*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x43c);
    guard_check_icall();
    uVar6 = (*pcVar1)();
    FUN_00874dc7(0xffffffff,uVar6,0xffffffff,local_3c8[0],0);
    iVar5 = local_3d0;
    local_8._0_1_ = 4;
    puVar7 = (undefined4 *)FUN_0083f9c3(&local_3d8);
    local_8._0_1_ = 5;
    FUN_00874dc7(*(undefined4 *)(iVar5 + 0xe8),0,0xffffffff,*puVar7,0);
    local_8._0_1_ = 7;
    FUN_00406b10();
    local_3d0 = FUN_0078e624(0x1178);
    local_8._0_1_ = 8;
    if (local_3d0 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_0081b772();
    }
    local_8._0_1_ = 7;
    FUN_0081dea9(local_2dc,0xffffffff);
    FUN_0081dea9(local_1f4,0xffffffff);
    CStringT<>();
    local_8._0_1_ = 9;
    iVar5 = FID_conflict_LoadStringA
                      ((HINSTANCE)0x427a,in_stack_fffffc04,in_stack_fffffc08,in_stack_fffffc0c);
    if (iVar5 == 0) {
LAB_00842d6b:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    pcVar1 = *(code **)(*piVar3 + 0x1c8);
    guard_check_icall();
    piVar8 = (int *)(*pcVar1)();
    pcVar1 = *(code **)(*piVar8 + 0x43c);
    guard_check_icall();
    uVar6 = (*pcVar1)();
    FUN_00874dc7(0xffffffff,uVar6,0xffffffff,local_3d0,0);
    local_8 = CONCAT31(local_8._1_3_,10);
    local_58 = 1;
    pcVar1 = *(code **)(*local_3d4 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    FUN_0081dea9(local_10c,0xffffffff);
    pcVar1 = *(code **)(*local_3e4 + 0xc);
    guard_check_icall(&local_24);
    (*pcVar1)();
    local_3e0.x = local_24;
    local_3e0.y = local_20;
    ClientToScreen((HWND)local_3e8[8],&local_3e0);
    FUN_0083fb52(local_3ec);
    pcVar1 = *(code **)(*(int *)local_3cc + 0x210);
    guard_check_icall(local_3e8,local_3e0.x + -2,local_3e0.y + -9,0,0,0);
    (*pcVar1)();
    pCVar2 = local_3cc;
    *(undefined4 *)(local_3cc + 0xf38) = 1;
    *(int *)(local_3cc + 0x5c) = local_3e8[8];
    CMFCPopupMenu::SetQuickMode(local_3cc);
    *(undefined4 *)(pCVar2 + 0x1168) = 1;
    FUN_00874eb0();
    FUN_00406b10();
    FUN_00874eb0();
    FUN_00874eb0();
    FUN_00406b10();
  }
LAB_00842d63:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[141], CPaneFrameWnd[141] */
/* 008432d0  FUN_008432d0  253 bytes, 1 callers */

void FUN_008432d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  HWND pHVar6;
  int in_ECX;
  bool bVar7;
  
  if (DAT_00a139c8 != 0) {
    return;
  }
  iVar1 = *(int *)(in_ECX + 0xb4);
  bVar7 = false;
  iVar2 = FUN_0083f71c(param_1,param_2);
  if (iVar2 != 0) {
    iVar5 = *(int *)(iVar2 + 0x10);
    if (((DAT_00a127ac == 0) || (iVar3 = FUN_008aee34(), iVar3 == 0x14)) ||
       (iVar3 = FUN_008aee34(), iVar3 == 0x13)) {
      iVar3 = 1;
    }
    else {
      iVar3 = 0;
    }
    *(int *)(iVar2 + 0x10) = iVar3;
    bVar7 = iVar3 != iVar5;
    if (iVar3 != 0) {
      uVar4 = FUN_008aee34();
      *(undefined4 *)(in_ECX + 0xb4) = uVar4;
      *(undefined4 *)(iVar2 + 8) = 1;
      iVar5 = *(int *)(in_ECX + 0xb4);
      goto LAB_00843364;
    }
  }
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  iVar5 = 0;
LAB_00843364:
  if ((iVar5 != iVar1) || (bVar7)) {
    FUN_0084368c(iVar2);
    iVar2 = FUN_0083f6d8(iVar1);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 8) = 0;
      FUN_0084368c(iVar2);
    }
  }
  if (*(int *)(in_ECX + 0xb0) == 0) {
    if (iVar1 == 0) {
      if (*(int *)(in_ECX + 0xb4) != 0) {
        pHVar6 = SetCapture(*(HWND *)(in_ECX + 0x20));
        CWnd::FromHandle(pHVar6);
      }
    }
    else if (*(int *)(in_ECX + 0xb4) == 0) {
      ReleaseCapture();
    }
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[99], CPaneFrameWnd[99] */
/* 00843b51  FUN_00843b51  235 bytes, 0 callers */

void FUN_00843b51(uint param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int *in_ECX;
  
  FUN_00843704();
  if ((param_1 & 2) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1a8);
    guard_check_icall();
    pCVar2 = (CObject *)(*pcVar1)();
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar2);
    if (pCVar2 != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x1c8);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        pcVar1 = *(code **)(*in_ECX + 0x230);
        guard_check_icall(0x14);
        (*pcVar1)();
      }
    }
  }
  if ((param_1 & 1) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x230);
    guard_check_icall(9);
    (*pcVar1)();
  }
  if ((param_1 & 4) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x230);
    guard_check_icall(8);
    (*pcVar1)();
  }
  if ((param_1 & 0x10) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x230);
    guard_check_icall(0x19);
    (*pcVar1)();
  }
  in_ECX[0x31] = param_1;
  FUN_00843c3c();
  FUN_0083ee42();
  SendMessageW((HWND)in_ECX[8],0x85,0,0);
  return;
}




/* vtable slots: CMultiPaneFrameWnd[142], CPaneFrameWnd[142] */
/* 0084467b  StopCaptionButtonsTracking  103 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CPaneFrameWnd::StopCaptionButtonsTracking(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CPaneFrameWnd::StopCaptionButtonsTracking(CPaneFrameWnd *this)

{
  int iVar1;
  
  if (*(int *)(this + 0xb0) != 0) {
    iVar1 = FUN_0083f6d8(*(int *)(this + 0xb0));
    *(undefined4 *)(this + 0xb0) = 0;
    ReleaseCapture();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 4) = 0;
      FUN_0084368c(iVar1);
    }
  }
  if (*(int *)(this + 0xb4) != 0) {
    iVar1 = FUN_0083f6d8(*(int *)(this + 0xb4));
    *(undefined4 *)(this + 0xb4) = 0;
    ReleaseCapture();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 8) = 0;
      FUN_0084368c(iVar1);
    }
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[1] */
/* 0085ada2  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMultiPaneFrameWnd::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMultiPaneFrameWnd::_scalar_deleting_destructor_(CMultiPaneFrameWnd *this,uint param_1)

{
  FUN_0085ad86();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1e8);
    }
  }
  return this;
}




/* vtable slots: CMultiPaneFrameWnd[94] */
/* 0085add5  FUN_0085add5  97 bytes, 0 callers */

void FUN_0085add5(CObject *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int *in_ECX;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,param_1);
  iVar3 = CPaneContainerManager::IsEmpty((CPaneContainerManager *)(in_ECX + 100));
  if (iVar3 != 0) {
    pcVar1 = *(code **)(in_ECX[100] + 0x1c);
    guard_check_icall(pCVar2);
    (*pcVar1)();
    FUN_0083eb81(param_1);
  }
  pcVar1 = *(code **)(*in_ECX + 500);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[148] */
/* 0085ae36  FUN_0085ae36  480 bytes, 0 callers */

undefined4 FUN_0085ae36(int *param_1)

{
  int *piVar1;
  CWnd *pCVar2;
  int iVar3;
  int *piVar4;
  CWnd *in_ECX;
  HWND pHVar5;
  code *pcVar6;
  int *piVar7;
  int *local_10;
  int local_c;
  int *local_8;
  
  pHVar5 = (HWND)0x0;
  local_10 = param_1 + 0x79;
  local_8 = (int *)FUN_0085f26e(0);
  local_c = FUN_0085f286(0);
  if (local_8 == (int *)0x0) {
    if (local_c == 0) {
      return 0;
    }
    pHVar5 = (HWND)0x0;
    if (in_ECX != (CWnd *)0x0) {
      pHVar5 = *(HWND *)(in_ECX + 0x20);
    }
    pHVar5 = SetParent((HWND)param_1[8],pHVar5);
    CWnd::FromHandle(pHVar5);
    FUN_0083ecce(param_1,1);
    iVar3 = FUN_0085f2fe(0);
    if (iVar3 == 0) {
      local_8 = *(int **)(local_c + 8);
    }
    else {
      local_8 = *(int **)(local_c + 4);
    }
    if (local_8 != (int *)0x0) {
      local_10 = (int *)0x0;
      pcVar6 = *(code **)(*param_1 + 0x34c);
      guard_check_icall(local_8,2,1,&local_10);
      (*pcVar6)();
      pcVar6 = *(code **)(*local_8 + 0x224);
      guard_check_icall(1,0,1);
      (*pcVar6)();
      pcVar6 = *(code **)(*(int *)in_ECX + 0x1cc);
      guard_check_icall();
      (*pcVar6)();
      goto LAB_0085aff5;
    }
    pcVar6 = *(code **)(*(int *)(in_ECX + 400) + 0x20);
    guard_check_icall(param_1,local_c);
    piVar4 = (int *)(*pcVar6)();
    pcVar6 = *(code **)(*(int *)in_ECX + 0x1e8);
  }
  else {
    if (in_ECX != (CWnd *)0x0) {
      pHVar5 = *(HWND *)(in_ECX + 0x20);
    }
    pHVar5 = SetParent((HWND)param_1[8],pHVar5);
    CWnd::FromHandle(pHVar5);
    FUN_0083ecce(param_1,1);
    pcVar6 = *(code **)(*(int *)(in_ECX + 400) + 0x20);
    piVar4 = param_1;
    piVar7 = local_8;
    guard_check_icall(param_1,local_8);
    piVar1 = (int *)(*pcVar6)();
    local_8 = piVar1;
    pCVar2 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
    if ((piVar1 != (int *)0x0) && (pCVar2 == (CWnd *)0x0)) {
      *(int *)(in_ECX + 0xd4) = piVar1[8];
    }
    pcVar6 = *(code **)(*(int *)(in_ECX + 400) + 0x54);
    guard_check_icall(piVar4,piVar7);
    iVar3 = (*pcVar6)();
    piVar4 = local_8;
    if ((iVar3 == 1) && (param_1 == local_8)) {
      CWnd::MoveWindow(in_ECX,(tagRECT *)(in_ECX + 0xd8),1);
    }
    if (piVar4 == (int *)0x0) goto LAB_0085aff5;
    pcVar6 = *(code **)(*(int *)in_ECX + 0x1e8);
  }
  guard_check_icall(piVar4,1);
  (*pcVar6)();
LAB_0085aff5:
  pcVar6 = *(code **)(*(int *)in_ECX + 500);
  guard_check_icall();
  (*pcVar6)();
  return 1;
}




/* vtable slots: CMultiPaneFrameWnd[127] */
/* 0085b016  FUN_0085b016  94 bytes, 0 callers */

void FUN_0085b016(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x198);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*puVar2);
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x238);
    guard_check_icall(0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x37,0);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[112] */
/* 0085b074  CalcExpectedDockedRect  100 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMultiPaneFrameWnd::CalcExpectedDockedRect(class CWnd *,class
   CPoint,class CRect &,int &,class CDockablePane * *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMultiPaneFrameWnd::CalcExpectedDockedRect
          (CMultiPaneFrameWnd *this,undefined4 param_1,undefined4 param_3,undefined4 param_4,
          LPRECT param_5,undefined4 *param_6,undefined4 param_7)

{
  CGlobalUtils local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x85b080;
  CGlobalUtils::CGlobalUtils(local_1c);
  local_8 = 0;
  if (*(int *)(this + 0x90) == 0) {
    FUN_00859f19(this + 400,param_1,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    *param_6 = 0;
    SetRectEmpty(param_5);
  }
  FUN_00859dc2();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[93] */
/* 0085b0d8  FUN_0085b0d8  28 bytes, 0 callers */

void FUN_0085b0d8(void)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x7c);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[89] */
/* 0085b0f4  FUN_0085b0f4  134 bytes, 0 callers */

undefined4 FUN_0085b0f4(int *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x198);
  do {
    do {
      if (local_8 == 0) {
        return 0;
      }
      pCVar2 = (CObject *)FUN_0049acb0(&local_8);
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar2);
      pcVar1 = *(code **)(*param_1 + 0x184);
      guard_check_icall(pCVar2);
      iVar3 = (*pcVar1)();
    } while (iVar3 == 0);
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x184);
    guard_check_icall(param_1);
    iVar3 = (*pcVar1)();
  } while (iVar3 == 0);
  return 1;
}




/* vtable slots: CMultiPaneFrameWnd[98] */
/* 0085b17a  FUN_0085b17a  123 bytes, 0 callers */

void FUN_0085b17a(void)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  CObject *pCVar5;
  int in_ECX;
  
  BVar3 = IsWindowVisible(*(HWND *)(in_ECX + 0x20));
  if (BVar3 != 0) {
    pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x54);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    iVar2 = *(int *)(in_ECX + 400);
    if (iVar4 == 1) {
      guard_check_icall();
      pCVar5 = (CObject *)(**(code **)(iVar2 + 0x78))();
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar5);
      if (pCVar5 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar5 + 0x1f0);
        guard_check_icall(0);
        (*pcVar1)();
      }
    }
    else {
      guard_check_icall(1);
      (**(code **)(iVar2 + 0x58))();
    }
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[137] */
/* 0085b1f5  FUN_0085b1f5  65 bytes, 0 callers */

void FUN_0085b1f5(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x220);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_00797f20(0);
    pcVar1 = *(code **)(in_ECX[100] + 0x5c);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[149] */
/* 0085b87b  FUN_0085b87b  47 bytes, 0 callers */

void FUN_0085b87b(int *param_1)

{
  code *pcVar1;
  
  FUN_0083ecce(param_1,0);
  pcVar1 = *(code **)(*param_1 + 0x1f8);
  guard_check_icall(param_1,0,2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[110] */
/* 0085b8aa  FUN_0085b8aa  130 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0085b8aa(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int in_ECX;
  
  CStringT<>();
  pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x54);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 1) {
    pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x78);
    guard_check_icall();
    pCVar3 = (CObject *)(*pcVar1)();
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_DAT_0097c53c,pCVar3);
    if (pCVar3 != (CObject *)0x0) {
      FUN_00792c64(param_1);
    }
  }
  return param_1;
}




/* vtable slots: CMultiPaneFrameWnd[107] */
/* 0085b92c  FUN_0085b92c  28 bytes, 0 callers */

void FUN_0085b92c(void)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x78);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[10] */
/* 0085b948  FUN_0085b948  6 bytes, 0 callers */

undefined ** FUN_0085b948(void)

{
  return &PTR_FUN_00996818;
}




/* vtable slots: CMultiPaneFrameWnd[106] */
/* 0085b94e  FUN_0085b94e  65 bytes, 0 callers */

void FUN_0085b94e(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = FUN_0083fa69();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1ac);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(in_ECX[100] + 0x70);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[104] */
/* 0085b98f  FUN_0085b98f  7 bytes, 0 callers */

undefined4 FUN_0085b98f(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1a0);
}




/* vtable slots: CMultiPaneFrameWnd[0] */
/* 0085b996  FUN_0085b996  6 bytes, 0 callers */

undefined ** FUN_0085b996(void)

{
  return &PTR_s_CMultiPaneFrameWnd_00a00968;
}




/* vtable slots: CMultiPaneFrameWnd[105] */
/* 0085b99c  FUN_0085b99c  28 bytes, 0 callers */

void FUN_0085b99c(void)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x54);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[150] */
/* 0085b9b8  FUN_0085b9b8  20 bytes, 0 callers */

undefined4 FUN_0085b9b8(undefined4 param_1)

{
  FUN_0083ecce(param_1,1);
  return 1;
}




/* vtable slots: CMultiPaneFrameWnd[118] */
/* 0085b9cc  FUN_0085b9cc  94 bytes, 0 callers */

undefined4 FUN_0085b9cc(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x198);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*puVar2);
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x22c);
    guard_check_icall(param_1,param_2,0xffffffff);
    (*pcVar1)();
  }
  return 1;
}




/* vtable slots: CMultiPaneFrameWnd[102] */
/* 0085baf6  FUN_0085baf6  258 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0085baf6(void)

{
  int *piVar1;
  code *pcVar2;
  CObject *pCVar3;
  int in_ECX;
  int *piVar4;
  CObList local_34 [4];
  int *local_30;
  int local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x85bb02;
  local_14 = *(int *)(in_ECX + 0x184);
  local_18 = in_ECX;
  if (local_14 == 0) {
    local_14 = FUN_0085a847(in_ECX);
  }
  CObList::CObList(local_34,10);
  local_8 = 0;
  FUN_008c01f8(local_34,0);
  piVar4 = local_30;
  if (local_30 != (int *)0x0) {
    do {
      if (piVar4 == (int *)0x0) goto LAB_0085bbf3;
      piVar1 = piVar4 + 2;
      piVar4 = (int *)*piVar4;
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*piVar1)
      ;
      pcVar2 = *(code **)(*(int *)pCVar3 + 0x31c);
      guard_check_icall();
      (*pcVar2)();
    } while (piVar4 != (int *)0x0);
    while (local_30 != (int *)0x0) {
      if (local_30 == (int *)0x0) {
LAB_0085bbf3:
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      piVar4 = (int *)*local_30;
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                  (CObject *)local_30[2]);
      FUN_0083ecce(pCVar3,0);
      pcVar2 = *(code **)(*(int *)pCVar3 + 0x1f8);
      guard_check_icall(pCVar3,0,2);
      (*pcVar2)();
      local_30 = piVar4;
    }
  }
  FUN_0085a743(local_14,0,0);
  SendMessageW(*(HWND *)(local_18 + 0x20),DAT_00a13b18,0,0);
  FUN_007a184a();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[115] */
/* 0085bd0d  FUN_0085bd0d  280 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0085bd0d(void)

{
  code *pcVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  HDWP local_3c;
  tagRECT local_38;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  local_3c = BeginDeferWindowPos(0x14);
  iVar2 = *(int *)(in_ECX + 400);
  guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,&local_3c);
  (**(code **)(iVar2 + 0x38))();
  EndDeferWindowPos(local_3c);
  if (DAT_00a12770 != 0) {
    local_28 = 0;
    pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x2c);
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    guard_check_icall(&local_28);
    (*pcVar1)();
    local_38.left = 0;
    local_38.top = 0;
    local_38.right = 0;
    local_38.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_38);
    iVar2 = ((local_1c - local_24) - local_18.bottom) + local_18.top;
    iVar3 = ((local_20 - local_18.right) - local_28) + local_18.left;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    if ((iVar3 != 0) || (iVar2 != 0)) {
      FUN_00797e71(0,0xffffffff,0xffffffff,(local_38.right - local_38.left) + iVar3,
                   (local_38.bottom - local_38.top) + iVar2,0x16);
    }
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[122] */
/* 0085bfb2  FUN_0085bfb2  183 bytes, 0 callers */

void FUN_0085bfb2(undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  code *pcVar2;
  int iVar3;
  
  pcVar2 = *(code **)(in_ECX[100] + 0x48);
  iVar3 = param_2;
  guard_check_icall(param_1,param_2);
  (*pcVar2)();
  if (param_2 == 0) {
    pcVar2 = *(code **)(in_ECX[100] + 0x4c);
    guard_check_icall(param_1,iVar3);
    iVar1 = (*pcVar2)();
    if (iVar1 != 0) goto LAB_0085c02a;
    FUN_00797f20(0);
    pcVar2 = *(code **)(*in_ECX + 0x1f8);
  }
  else {
    if (in_ECX[0x28] == 0) {
      FUN_00797f20(4);
    }
    pcVar2 = *(code **)(*in_ECX + 500);
  }
  guard_check_icall(param_1,iVar3);
  (*pcVar2)();
LAB_0085c02a:
  pcVar2 = *(code **)(*in_ECX + 0x188);
  guard_check_icall();
  (*pcVar2)();
  pcVar2 = *(code **)(*in_ECX + 0x1cc);
  guard_check_icall();
  (*pcVar2)();
  FUN_00797e71(0,0,0,0,0,0x37);
  return;
}




/* vtable slots: CMultiPaneFrameWnd[113] */
/* 0085c0a4  FUN_0085c0a4  86 bytes, 0 callers */

void FUN_0085c0a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  code *pcVar1;
  BOOL BVar2;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_4 != 0) && (BVar2 = IsWindowVisible(*(HWND *)(in_ECX + 0x20)), BVar2 == 0)) {
    return;
  }
  local_c = 0;
  local_8 = 0;
  pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x68);
  guard_check_icall(param_1,param_2,param_3,1,&local_c,&local_8);
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[95] */
/* 0085c105  FUN_0085c105  289 bytes, 0 callers */

void FUN_0085c105(undefined4 param_1,int param_2)

{
  CPaneContainerManager *this;
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  CWnd *pCVar4;
  int iVar5;
  int *in_ECX;
  
  iVar2 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
  if (iVar2 != 0) {
    this = (CPaneContainerManager *)(in_ECX + 100);
    pcVar1 = *(code **)(*(int *)this + 0x34);
    guard_check_icall(param_1);
    (*pcVar1)();
    iVar2 = CPaneContainerManager::IsEmpty(this);
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*(int *)this + 0x70);
      guard_check_icall();
      uVar3 = (*pcVar1)();
      FUN_00843882(param_1,uVar3);
    }
    else {
      FUN_008437e1(param_1,0,0);
      pCVar4 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x35]);
      if (pCVar4 == (CWnd *)0x0) {
        pcVar1 = *(code **)(*(int *)this + 0x70);
        guard_check_icall();
        iVar5 = (*pcVar1)();
        iVar2 = 0;
        if (iVar5 != 0) {
          iVar2 = *(int *)(iVar5 + 0x20);
        }
        in_ECX[0x35] = iVar2;
      }
    }
  }
  if (param_2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1a0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      PostMessageW((HWND)in_ECX[8],DAT_00a13b18,0,0);
      goto LAB_0085c20c;
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1cc);
  guard_check_icall();
  (*pcVar1)();
  SendMessageW((HWND)in_ECX[8],0x85,0,0);
LAB_0085c20c:
  pcVar1 = *(code **)(*in_ECX + 0x1f8);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[96] */
/* 0085c226  FUN_0085c226  64 bytes, 0 callers */

void FUN_0085c226(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(in_ECX[100] + 0x40);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 500);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[117] */
/* 0085c2e7  FUN_0085c2e7  94 bytes, 0 callers */

undefined4 FUN_0085c2e7(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x198);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*puVar2);
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x230);
    guard_check_icall(param_1,param_2,0xffffffff);
    (*pcVar1)();
  }
  return 1;
}




/* vtable slots: CMultiPaneFrameWnd[2] */
/* 0085c345  FUN_0085c345  47 bytes, 0 callers */

void FUN_0085c345(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  FUN_008439ae(param_1);
  pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 8);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[119] */
/* 0085c374  FUN_0085c374  1757 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0085c374(int *param_1)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  CObject *pCVar5;
  CPaneContainer *this;
  CList<unsigned_int,unsigned_int> *pCVar6;
  CObject *pCVar7;
  HWND pHVar8;
  CWnd *pCVar9;
  CWnd *pCVar10;
  LRESULT LVar11;
  code *in_ECX;
  undefined4 uVar12;
  code *pcVar13;
  CObList local_88 [4];
  CWnd *local_84;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  code *local_48;
  int *local_44;
  CPaneContainerManager *local_40;
  code *local_3c;
  int local_38;
  CObject *local_34;
  CWnd *local_30;
  CObject *local_2c;
  code *local_28;
  tagRECT local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0x85c380;
  local_44 = param_1;
  local_28 = in_ECX;
  CObList::CObList(local_88,10);
  local_8 = 0;
  local_40 = (CPaneContainerManager *)(in_ECX + 400);
  iVar3 = CPaneContainerManager::IsEmpty(local_40);
  if (iVar3 == 0) {
    local_48 = in_ECX + 0x194;
    local_38 = *(int *)(in_ECX + 0x198);
    while (pcVar1 = local_48, local_38 != 0) {
      puVar4 = (undefined4 *)FUN_0044f2d0(&local_38);
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*puVar4)
      ;
      local_34 = pCVar5;
      iVar3 = FUN_0079d98a(&PTR_s_CBaseTabbedPane_00996820);
      if (iVar3 == 0) {
        pcVar1 = *(code **)(*(int *)pCVar5 + 0x16c);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 != 0) {
          pHVar8 = GetParent(*(HWND *)(pCVar5 + 0x20));
          pCVar10 = CWnd::FromHandle(pHVar8);
          pHVar8 = GetParent(*(HWND *)(pCVar10 + 0x20));
          pCVar10 = CWnd::FromHandle(pHVar8);
          local_30 = pCVar10;
          pCVar9 = CWnd::FromHandlePermanent(*(HWND__ **)(local_28 + 200));
          if (pCVar9 == (CWnd *)0x0) {
            pHVar8 = (HWND)0x0;
          }
          else {
            pHVar8 = *(HWND *)(pCVar9 + 0x20);
          }
          pHVar8 = SetParent(*(HWND *)(pCVar5 + 0x20),pHVar8);
          CWnd::FromHandle(pHVar8);
          pcVar1 = *(code **)(*(int *)pCVar10 + 0x3c0);
          guard_check_icall(pCVar5);
          (*pcVar1)();
          iVar3 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
          if (iVar3 != 0) {
            pcVar1 = *(code **)(*(int *)pCVar5 + 0x1f0);
            guard_check_icall(1);
            (*pcVar1)();
          }
          FUN_00797f20(5);
        }
        pcVar1 = *(code **)(*(int *)pCVar5 + 0x1dc);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 != 0) {
          pcVar1 = *(code **)(*(int *)pCVar5 + 0x368);
          guard_check_icall(0,0xf000,0,1);
          (*pcVar1)();
        }
        local_24.left = 0;
        local_24.top = 0;
        local_24.right = 0;
        local_24.bottom = 0;
        GetWindowRect(*(HWND *)(pCVar5 + 0x20),&local_24);
        local_30 = *(CWnd **)(*(int *)pCVar5 + 0x1fc);
        guard_check_icall(local_24.left,local_24.top,local_24.right,local_24.bottom,3,0);
        pCVar5 = local_34;
        (*(code *)local_30)();
        pcVar1 = *(code **)(*(int *)pCVar5 + 0x228);
        guard_check_icall(0);
        pCVar10 = (CWnd *)(*pcVar1)();
        in_ECX = local_28;
        local_30 = pCVar10;
        if (pCVar10 != (CWnd *)0x0) {
          if (local_28 == (code *)0x0) {
            pHVar8 = (HWND)0x0;
          }
          else {
            pHVar8 = *(HWND *)(local_28 + 0x20);
          }
          pHVar8 = SetParent(*(HWND *)(pCVar5 + 0x20),pHVar8);
          CWnd::FromHandle(pHVar8);
          pcVar1 = *(code **)(*(int *)pCVar10 + 0x17c);
          guard_check_icall(pCVar5,0,0);
          (*pcVar1)();
          local_5c = *(int *)(pCVar5 + 0x298);
          local_58 = *(int *)(pCVar5 + 0x29c);
          local_54 = *(int *)(pCVar5 + 0x2a0);
          local_50 = *(int *)(pCVar5 + 0x2a4);
          pcVar1 = *(code **)(*(int *)local_34 + 0x238);
          guard_check_icall(0,local_5c,local_58,local_54 - local_5c,local_50 - local_58,0x34,0);
          (*pcVar1)();
          in_ECX = local_28;
        }
      }
      else {
        local_4c = 0;
        pcVar1 = *(code **)(*(int *)local_40 + 0x8c);
        guard_check_icall(pCVar5,&local_4c);
        this = (CPaneContainer *)(*pcVar1)();
        if (this == (CPaneContainer *)0x0) goto LAB_0085ca4c;
        pCVar6 = CPaneContainer::GetAssociatedSiblingPaneIDs(this,(CDockablePane *)pCVar5);
        if (pCVar6 != (CList<unsigned_int,unsigned_int> *)0x0) {
          pCVar10 = *(CWnd **)(pCVar6 + 4);
          while (pCVar10 != (CWnd *)0x0) {
            local_30 = *(CWnd **)pCVar10;
            pcVar1 = *(code **)(*local_44 + 0x24);
            guard_check_icall(*(int *)(pCVar10 + 8),1);
            pCVar7 = (CObject *)(*pcVar1)();
            pCVar10 = local_30;
            local_2c = pCVar7;
            if (pCVar7 != (CObject *)0x0) {
              iVar3 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
              if (iVar3 != 0) {
                pcVar1 = *(code **)(*(int *)pCVar7 + 0x1dc);
                guard_check_icall();
                iVar3 = (*pcVar1)();
                if (iVar3 != 0) {
                  pcVar1 = *(code **)(*(int *)pCVar7 + 0x368);
                  guard_check_icall(0,0xf000,0,1);
                  (*pcVar1)();
                }
              }
              pcVar1 = *(code **)(*(int *)pCVar7 + 0x16c);
              guard_check_icall();
              iVar3 = (*pcVar1)();
              if (iVar3 == 0) {
                local_64 = 10;
                local_3c = *(code **)(*(int *)pCVar7 + 0x1fc);
                local_6c = 0;
                local_68 = 0;
                local_60 = 10;
                guard_check_icall(0,0,10,10,3,0);
                pCVar7 = local_2c;
                (*local_3c)();
              }
              else {
                pHVar8 = GetParent(*(HWND *)(pCVar7 + 0x20));
                pCVar10 = CWnd::FromHandle(pHVar8);
                pHVar8 = GetParent(*(HWND *)(pCVar10 + 0x20));
                pCVar10 = CWnd::FromHandle(pHVar8);
                pHVar8 = SetParent(*(HWND *)(local_2c + 0x20),*(HWND *)(local_28 + 0x20));
                CWnd::FromHandle(pHVar8);
                pcVar1 = *(code **)(*(int *)pCVar10 + 0x3c0);
                guard_check_icall(local_2c);
                (*pcVar1)();
                pCVar7 = local_2c;
              }
              pcVar1 = *(code **)(*(int *)pCVar7 + 0x228);
              guard_check_icall(0);
              local_3c = (code *)(*pcVar1)();
              if ((local_3c != (code *)0x0) && (local_3c != local_28)) {
                pcVar1 = *(code **)(*(int *)local_3c + 0x17c);
                guard_check_icall(pCVar7,0,0);
                (*pcVar1)();
              }
              pCVar5 = local_34;
              pcVar1 = *(code **)(*(int *)pCVar7 + 0x34c);
              guard_check_icall(local_34,0,0,0);
              (*pcVar1)();
              pCVar10 = local_30;
              if (local_3c != (code *)0x0) {
                PostMessageW(*(HWND *)(local_3c + 0x20),DAT_00a13b18,0,0);
                pCVar10 = local_30;
              }
            }
          }
        }
        pcVar1 = *(code **)(*(int *)pCVar5 + 0x3a4);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 == 0) {
          CObList::AddTail(local_88,pCVar5);
          in_ECX = local_28;
        }
        else {
          pcVar1 = *(code **)(*(int *)pCVar5 + 0x3d4);
          guard_check_icall(0);
          (*pcVar1)();
          pcVar1 = *(code **)(*(int *)pCVar5 + 0x210);
          guard_check_icall();
          (*pcVar1)();
          in_ECX = local_28;
        }
      }
    }
    while (local_48 = pcVar1, local_84 != (CWnd *)0x0) {
      if (local_84 == (CWnd *)0x0) {
LAB_0085ca4c:
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      local_30 = *(CWnd **)local_84;
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                  *(CObject **)(local_84 + 8));
      pcVar1 = *(code **)(*(int *)in_ECX + 0x17c);
      guard_check_icall(pCVar5,0,1);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar5 + 0x60);
      guard_check_icall();
      (*pcVar1)();
      in_ECX = local_28;
      pcVar1 = local_48;
      local_84 = local_30;
    }
    if (*(int *)(pcVar1 + 0xc) == 0) {
      SendMessageW(*(HWND *)(local_28 + 0x20),DAT_00a13b18,0,0);
    }
    else {
      local_38 = *(int *)(pcVar1 + 4);
      iVar3 = 0;
      if (local_38 != 0) {
        do {
          puVar4 = (undefined4 *)FUN_0044f2d0(&local_38);
          local_2c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                        (CObject *)*puVar4);
          pcVar13 = *(code **)(*(int *)local_2c + 0x1ac);
          guard_check_icall();
          pCVar10 = (CWnd *)(*pcVar13)();
          local_30 = pCVar10;
          iVar3 = FUN_0079dd6d();
          pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CWinAppEx_0098fd18,
                                      *(CObject **)(iVar3 + 4));
          if ((pCVar5 == (CObject *)0x0) || (*(int *)(pCVar5 + 0xd0) == 0)) {
            bVar2 = false;
            uVar12 = 1;
          }
          else {
            bVar2 = true;
            uVar12 = 0;
          }
          if ((pCVar10 != (CWnd *)0x0) && (!bVar2)) {
            *(int *)(local_28 + 0xa0) = 1;
          }
          pcVar13 = *(code **)(*(int *)local_2c + 0x224);
          guard_check_icall(local_30,uVar12,0);
          (*pcVar13)();
          FUN_0083ecce(local_2c,1);
        } while (local_38 != 0);
        iVar3 = *(int *)(pcVar1 + 4);
      }
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,
                                  *(CObject **)(iVar3 + 8));
      pcVar13 = local_28;
      if (pCVar5 != (CObject *)0x0) {
        if (*(int *)(pcVar1 + 0xc) < 2) {
          CStringT<>();
          local_8._0_1_ = 1;
          FUN_00792c64(&local_34);
          FUN_00797ece(local_34);
          LVar11 = SendMessageW(*(HWND *)(pCVar5 + 0x20),0x7f,0,0);
          SendMessageW(*(HWND *)(local_28 + 0x20),0x80,0,LVar11);
          LVar11 = SendMessageW(*(HWND *)(pCVar5 + 0x20),0x7f,1,0);
          SendMessageW(*(HWND *)(local_28 + 0x20),0x80,1,LVar11);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00406b10();
          pcVar13 = local_28;
        }
        else {
          *(int *)(local_28 + 0xd4) = *(int *)(pCVar5 + 0x20);
        }
      }
      pcVar1 = *(code **)(*(int *)pcVar13 + 500);
      guard_check_icall();
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pcVar13 + 0x18c);
      guard_check_icall(*(int *)(pcVar13 + 0xc4));
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pcVar13 + 0x1cc);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  else {
    PostMessageW(*(HWND *)(in_ECX + 0x20),DAT_00a13b18,0,0);
  }
  FUN_007a184a();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[100] */
/* 0085ca52  FUN_0085ca52  1361 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0085ca52(int param_1,CObject *param_2,int param_3)

{
  int *piVar1;
  code *pcVar2;
  int *piVar3;
  HWND pHVar4;
  int iVar5;
  CWnd *pCVar6;
  CObject *pCVar7;
  uint uVar8;
  BOOL BVar9;
  CWnd *in_ECX;
  undefined4 *puVar10;
  CObList local_88 [4];
  int *local_84;
  undefined **local_6c;
  undefined4 *local_68;
  CObject *local_50;
  tagPOINT local_4c;
  CWnd *local_44;
  CObject *local_40;
  CObject *local_3c;
  int *local_38;
  CWnd *local_34;
  undefined4 local_30;
  CObject *local_2c;
  int *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0x85ca5e;
  if (param_1 == 0) goto LAB_0085cf9b;
  local_44 = in_ECX;
  if ((param_1 == 2) && (param_2 != (CObject *)0x0)) {
    pcVar2 = *(code **)(*(int *)param_2 + 0x18c);
    guard_check_icall();
    iVar5 = (*pcVar2)();
    if (iVar5 == 0) goto LAB_0085cf9b;
  }
  local_2c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,param_2);
  local_28 = *(int **)(in_ECX + 0x184);
  if (local_28 == (int *)0x0) {
    pCVar6 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 200));
    local_28 = (int *)FUN_0085a847(pCVar6);
    if (local_28 == (int *)0x0) goto LAB_0085cf9b;
  }
  local_34 = in_ECX + 400;
  pcVar2 = *(code **)(*(int *)local_34 + 0x78);
  guard_check_icall();
  local_50 = (CObject *)(*pcVar2)();
  local_4c.x = 0;
  local_4c.y = 0;
  GetCursorPos(&local_4c);
  local_30 = 0;
  CObList::CObList(local_88,10);
  local_8 = 0;
  FUN_008c01f8(local_88,0);
  CList<HWND__*,HWND__*>::CList<HWND__*,HWND__*>((CList<HWND__*,HWND__*> *)&local_6c,10);
  local_8 = CONCAT31(local_8._1_3_,1);
  pCVar6 = in_ECX + 400;
  piVar3 = local_84;
  while (piVar3 != (int *)0x0) {
    piVar1 = piVar3 + 2;
    piVar3 = (int *)*piVar3;
    pCVar7 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*piVar1);
    pcVar2 = *(code **)(*(int *)pCVar7 + 0x31c);
    guard_check_icall();
    (*pcVar2)();
    CList<unsigned_int,unsigned_int>::AddTail
              ((CList<unsigned_int,unsigned_int> *)&local_6c,*(uint *)(pCVar7 + 0x20));
    pCVar6 = local_34;
    in_ECX = local_44;
  }
  pCVar7 = (CObject *)0x0;
  if (local_2c == (CObject *)0x0) {
    local_40 = pCVar7;
    iVar5 = FUN_0084787c(local_4c.x,local_4c.y,&local_30,&local_40);
    if (iVar5 != 0) {
      pCVar6 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 200));
      local_38 = (int *)FUN_0088d62f(local_30,pCVar6,0);
      if (local_38 != (int *)0x0) {
        pcVar2 = *(code **)(*local_38 + 0x1e0);
        guard_check_icall(local_30);
        (*pcVar2)();
        pCVar6 = local_34;
        pcVar2 = *(code **)(*(int *)local_34 + 0x2c);
        local_24.left = (LONG)pCVar7;
        local_24.top = (LONG)pCVar7;
        local_24.right = (LONG)pCVar7;
        local_24.bottom = (LONG)pCVar7;
        guard_check_icall(&local_24);
        (*pcVar2)();
        pcVar2 = *(code **)(*local_28 + 0x5c);
        guard_check_icall(&local_24,local_30);
        (*pcVar2)();
        pcVar2 = *(code **)(*(int *)pCVar6 + 0x38);
        local_3c = pCVar7;
        guard_check_icall(local_24.left,local_24.top,local_24.right,local_24.bottom,&local_3c);
        (*pcVar2)();
        piVar3 = local_38;
        if (local_40 == (CObject *)0x0) {
          pcVar2 = *(code **)(*local_38 + 0x28c);
          guard_check_icall(local_34,0);
          (*pcVar2)();
          FUN_00845032(piVar3,1,0,0);
        }
        else {
          FUN_00845032(local_38,0,0,local_40);
          pcVar2 = *(code **)(*piVar3 + 0x28c);
          guard_check_icall(local_34,local_40);
          (*pcVar2)();
        }
LAB_0085ce55:
        pHVar4 = *(HWND *)(local_44 + 0x20);
        SendMessageW(pHVar4,DAT_00a13b18,0,0);
        BVar9 = IsWindow(pHVar4);
        if (BVar9 != 0) {
          CWnd::MoveWindow(local_44,(tagRECT *)(local_44 + 0xd8),1);
          pCVar7 = local_50;
          if ((local_50 != (CObject *)0x0) && (param_3 == 1)) {
            ScreenToClient(*(HWND *)(local_50 + 0x20),&local_4c);
            iVar5 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
            if (iVar5 == 0) {
              SendMessageW(*(HWND *)(pCVar7 + 0x20),0x201,0,
                           CONCAT22((undefined2)local_4c.y,(undefined2)local_4c.x));
            }
            else {
              pcVar2 = *(code **)(*(int *)pCVar7 + 0x314);
              guard_check_icall(0);
              (*pcVar2)();
              pCVar7 = local_50;
            }
          }
          if (local_2c == (CObject *)0x0) {
            if ((pCVar7 != (CObject *)0x0) &&
               (local_3c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar7)
               , local_3c != (CObject *)0x0)) {
              pcVar2 = *(code **)(*(int *)local_3c + 0x268);
              guard_check_icall(0);
              (*pcVar2)();
            }
          }
          else {
            pcVar2 = *(code **)(*(int *)local_2c + 0x210);
            guard_check_icall();
            (*pcVar2)();
          }
          pcVar2 = *(code **)(*(int *)local_44 + 500);
          guard_check_icall();
          (*pcVar2)();
          puVar10 = local_68;
          while (puVar10 != (undefined4 *)0x0) {
            pHVar4 = (HWND)puVar10[2];
            puVar10 = (undefined4 *)*puVar10;
            BVar9 = IsWindow(pHVar4);
            if (BVar9 != 0) {
              pCVar6 = CWnd::FromHandle(pHVar4);
              local_3c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                            (CObject *)pCVar6);
              if (local_3c != (CObject *)0x0) {
                pcVar2 = *(code **)(*(int *)local_3c + 0x35c);
                guard_check_icall();
                (*pcVar2)();
              }
            }
          }
        }
      }
    }
  }
  else {
    pcVar2 = *(code **)(*(int *)pCVar6 + 0x70);
    guard_check_icall();
    local_28 = (int *)(*pcVar2)();
    if (local_28 != (int *)0x0) {
      pcVar2 = *(code **)(*(int *)local_2c + 0x184);
      guard_check_icall(local_28);
      iVar5 = (*pcVar2)();
      if (iVar5 != 0) {
        pcVar2 = *(code **)(*local_28 + 0x184);
        guard_check_icall(local_2c);
        iVar5 = (*pcVar2)();
        if (iVar5 != 0) {
          uVar8 = FUN_00797b3d();
          if (((uVar8 & 0x10000000) == 0) && (*(int *)(in_ECX + 0x1a0) == 1)) {
            pcVar2 = *(code **)(*local_28 + 0x1b8);
            guard_check_icall();
            uVar8 = (*pcVar2)();
            if ((uVar8 & 2) != 0) {
              FUN_00797c5d(0,0x10000000,0);
            }
          }
          pCVar7 = local_2c;
          if (param_1 == 1) {
            iVar5 = FUN_0085a399(local_4c.x,local_4c.y,local_2c,DAT_00a0091c,0,0,&local_30,0xf000,0)
            ;
            if (iVar5 != 0) {
              pcVar2 = *(code **)(*(int *)pCVar7 + 0x358);
              guard_check_icall(local_34,local_30,param_3);
              iVar5 = (*pcVar2)();
              if (iVar5 != 0) goto LAB_0085ce55;
            }
          }
          else if (param_1 == 2) {
            while (pCVar6 = local_44, local_84 != (int *)0x0) {
              local_38 = (int *)*local_84;
              pCVar7 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                          (CObject *)local_84[2]);
              FUN_0083ecce(pCVar7,0);
              pcVar2 = *(code **)(*(int *)pCVar7 + 0x34c);
              guard_check_icall(local_2c,param_3,1,0);
              (*pcVar2)();
              local_84 = local_38;
            }
            FUN_00797f20(0);
            local_24.left = *(LONG *)(pCVar6 + 0xd8);
            local_24.top = *(LONG *)(pCVar6 + 0xdc);
            local_24.right = *(LONG *)(pCVar6 + 0xe0);
            local_24.bottom = *(LONG *)(pCVar6 + 0xe4);
            CWnd::MoveWindow(local_44,&local_24,1);
            FUN_008404b3();
            SendMessageW(*(HWND *)(local_44 + 0x20),DAT_00a13b18,0,0);
          }
        }
      }
    }
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  local_6c = CList<HWND__*,HWND__*>::vftable;
  RemoveAll();
  FUN_007a184a();
LAB_0085cf9b:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMultiPaneFrameWnd[120] */
/* 0085cfa3  FUN_0085cfa3  103 bytes, 0 callers */

void FUN_0085cfa3(CObject *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_8;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,param_1);
  if (pCVar2 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x8c);
    local_8 = 1;
    guard_check_icall(pCVar2,&local_8);
    uVar3 = (*pcVar1)();
    pcVar1 = *(code **)(*(int *)(pCVar2 + 0x1e4) + 0xc);
    guard_check_icall(uVar3,0);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMultiPaneFrameWnd[121] */
/* 0085d00a  FUN_0085d00a  84 bytes, 0 callers */

void FUN_0085d00a(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 1;
  pcVar1 = *(code **)(*(int *)(in_ECX + 400) + 0x8c);
  guard_check_icall(param_2,&local_8);
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(param_1 + 0x1e4) + 0xc);
  guard_check_icall(uVar2,param_2);
  (*pcVar1)();
  return;
}



