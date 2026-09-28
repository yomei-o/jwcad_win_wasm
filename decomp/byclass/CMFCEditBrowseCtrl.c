/* CMFCEditBrowseCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCEditBrowseCtrl[1] */
/* 007d69b6  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCEditBrowseCtrl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCEditBrowseCtrl::_scalar_deleting_destructor_(CMFCEditBrowseCtrl *this,uint param_1)

{
  ~CMFCEditBrowseCtrl(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xd0);
    }
  }
  return this;
}




/* vtable slots: CMFCEditBrowseCtrl[10] */
/* 007d6b47  FUN_007d6b47  6 bytes, 0 callers */

undefined ** FUN_007d6b47(void)

{
  return &PTR_FUN_009880f0;
}




/* vtable slots: CMFCEditBrowseCtrl[0], CMFCToolBarEditCtrl[0] */
/* 007d6b4d  FUN_007d6b4d  6 bytes, 0 callers */

undefined ** FUN_007d6b4d(void)

{
  return &PTR_s_CMFCEditBrowseCtrl_00987e08;
}




/* vtable slots: CMFCEditBrowseCtrl[92], CMFCToolBarEditCtrl[92], CVSListBoxEditCtrl[92] */
/* 007d6b78  FUN_007d6b78  109 bytes, 0 callers */

void FUN_007d6b78(void)

{
  CWnd *pCVar1;
  WPARAM WVar2;
  CWnd *in_ECX;
  LPARAM lParam;
  LPARAM lParam_00;
  
  pCVar1 = CWnd::GetOwner(in_ECX);
  if (pCVar1 != (CWnd *)0x0) {
    pCVar1 = CWnd::GetOwner(in_ECX);
    lParam_00 = 0;
    lParam = 0;
    if (in_ECX != (CWnd *)0x0) {
      lParam = *(LPARAM *)(in_ECX + 0x20);
    }
    WVar2 = FUN_00797a2b();
    PostMessageW(*(HWND *)(pCVar1 + 0x20),0x300,WVar2,lParam);
    pCVar1 = CWnd::GetOwner(in_ECX);
    if (in_ECX != (CWnd *)0x0) {
      lParam_00 = *(LPARAM *)(in_ECX + 0x20);
    }
    WVar2 = FUN_00797a2b();
    PostMessageW(*(HWND *)(pCVar1 + 0x20),0x400,WVar2,lParam_00);
  }
  return;
}




/* vtable slots: CMFCEditBrowseCtrl[89], CMFCToolBarEditCtrl[89] */
/* 007d6be5  FUN_007d6be5  932 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d6be5(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  HWND pHVar7;
  CWnd *pCVar8;
  int *in_ECX;
  bool bVar9;
  wchar_t *local_70c;
  int local_708;
  char local_701;
  wchar_t *local_700 [315];
  wchar_t local_214 [262];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x700;
  local_8 = 0x7d6bf4;
  bVar9 = false;
  local_70c = (wchar_t *)0x0;
  if ((in_ECX == (int *)0x0) || (in_ECX[8] == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if (in_ECX[0x30] == 2) {
    CStringT<>();
    local_8 = 2;
    FUN_00792c64(local_700);
    if (*(int *)(local_700[0] + -6) != 0) {
      __wsplitpath_s(local_700[0],(wchar_t *)0x0,0,(wchar_t *)0x0,0,local_214,0x100,(wchar_t *)0x0,0
                    );
      CStringT<>(local_214);
      local_8 = CONCAT31(local_8._1_3_,3);
      ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimLeft
                ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)&local_708);
      ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimRight
                ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)&local_708);
      if (*(int *)(local_708 + -0xc) == 0) {
        Empty();
      }
      CStringT<>(L"*?<>|");
      local_8 = CONCAT31(local_8._1_3_,4);
      pwVar4 = _wcspbrk(local_700[0],local_70c);
      if ((pwVar4 != (wchar_t *)0x0) && (-1 < (int)pwVar4 - (int)local_700[0] >> 1)) {
        pcVar1 = *(code **)(*in_ECX + 0x174);
        guard_check_icall(local_700);
        iVar3 = (*pcVar1)();
        if (iVar3 == 0) {
          FUN_00797df8();
          FUN_00406b10();
          FUN_00406b10();
          FUN_00406b10();
          goto LAB_007d6e05;
        }
      }
      FUN_00406b10();
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00406b10();
    }
    FUN_007b3573(1,-(uint)(*(int *)(in_ECX[0x2b] - 0xc) != 0) & in_ECX[0x2b],local_700[0],
                 in_ECX[0x2d],-(uint)(*(int *)(in_ECX[0x2c] - 0xc) != 0) & in_ECX[0x2c],0,0,1);
    local_8 = CONCAT31(local_8._1_3_,5);
    iVar3 = FUN_007b3f8f();
    if (iVar3 == 1) {
      uVar5 = FUN_007b4284(&local_70c);
      bVar9 = true;
      cVar2 = FUN_00408c80(local_700,uVar5);
      local_701 = '\x01';
      if (cVar2 == '\0') goto LAB_007d6ead;
    }
    else {
LAB_007d6ead:
      local_701 = '\0';
    }
    if (bVar9) {
      FUN_00406b10();
    }
    if (local_701 != '\0') {
      puVar6 = (undefined4 *)FUN_007b4284(&local_70c);
      local_8._0_1_ = 6;
      FUN_00797ece(*puVar6);
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_00406b10();
      SendMessageW((HWND)in_ECX[8],0xb9,1,0);
      pcVar1 = *(code **)(*in_ECX + 0x170);
      guard_check_icall();
      (*pcVar1)();
    }
    pHVar7 = GetParent((HWND)in_ECX[8]);
    pCVar8 = CWnd::FromHandle(pHVar7);
    if (pCVar8 != (CWnd *)0x0) {
      pHVar7 = GetParent((HWND)in_ECX[8]);
      pCVar8 = CWnd::FromHandle(pHVar7);
      RedrawWindow(*(HWND *)(pCVar8 + 0x20),(RECT *)0x0,(HRGN)0x0,0x481);
    }
    FUN_007b384d();
LAB_007d6f66:
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  else if ((in_ECX[0x30] == 3) && (DAT_00a139e8 != 0)) {
    CStringT<>();
    local_8 = 0;
    FUN_00792c64(local_700);
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar3 = FUN_00824f3a(&local_708,in_ECX,local_700[0],
                         -(uint)(*(int *)(in_ECX[0x2e] - 0xc) != 0) & in_ECX[0x2e],in_ECX[0x2f],0);
    if (iVar3 != 0) {
      cVar2 = FUN_00408c80(&local_708,local_700);
      if (cVar2 != '\0') {
        FUN_00797ece(local_708);
        SendMessageW((HWND)in_ECX[8],0xb9,1,0);
        pcVar1 = *(code **)(*in_ECX + 0x170);
        guard_check_icall();
        (*pcVar1)();
      }
    }
    FUN_00406b10();
    goto LAB_007d6f66;
  }
  FUN_00797df8();
LAB_007d6e05:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCEditBrowseCtrl[91], CMFCToolBarEditCtrl[91], CVSListBoxEditCtrl[91] */
/* 007d6fc9  FUN_007d6fc9  118 bytes, 0 callers */

void FUN_007d6fc9(void)

{
  tagRECT *lprc;
  int iVar1;
  CWnd *in_ECX;
  
  if ((in_ECX != (CWnd *)0x0) && (*(int *)(in_ECX + 0x20) != 0)) {
    iVar1 = 0x14;
    if (0x13 < *(int *)(in_ECX + 0xa4) + 8) {
      iVar1 = *(int *)(in_ECX + 0xa4) + 8;
    }
    *(int *)(in_ECX + 0x80) = iVar1;
    FUN_00797e71(0,0,0,0,0,0x27);
    lprc = (tagRECT *)(in_ECX + 0x94);
    if (*(int *)(in_ECX + 0xc0) == 0) {
      SetRectEmpty(lprc);
    }
    else {
      GetWindowRect(*(HWND *)(in_ECX + 0x20),lprc);
      lprc->left = *(int *)(in_ECX + 0x9c) - *(int *)(in_ECX + 0x80);
      CWnd::ScreenToClient(in_ECX,lprc);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCEditBrowseCtrl[90], CMFCToolBarEditCtrl[90], CVSListBoxEditCtrl[90] */
/* 007d7040  FUN_007d7040  557 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d7040(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_34;
  int local_30;
  int *local_2c;
  code *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x7d704c;
  iVar2 = FUN_007c2511();
  uVar1 = *(undefined4 *)(iVar2 + 0x28);
  local_2c = (int *)FUN_007c2574();
  local_28 = *(code **)(*local_2c + 0x1bc);
  piVar6 = param_1;
  iVar2 = param_2;
  iVar7 = param_3;
  iVar8 = param_4;
  iVar9 = param_5;
  guard_check_icall(param_1,param_2,param_3,param_4,param_5);
  iVar3 = (*local_28)();
  if (iVar3 != 0) {
    local_2c = (int *)0x0;
    if ((local_30 == -0xc4) || (*(int *)(local_30 + 200) == 0)) {
      pcVar5 = *(code **)(*param_1 + 0x30);
      guard_check_icall(uVar1);
      local_2c = (int *)(*pcVar5)();
      local_28 = (code *)FUN_0079f0b8(1);
      pcVar5 = *(code **)(*param_1 + 0x24);
      guard_check_icall(0x11);
      local_30 = (*pcVar5)();
      local_24.left = param_2;
      local_24.top = param_3;
      local_24.right = param_4;
      local_24.bottom = param_5;
      InflateRect(&local_24,-1,-2);
      OffsetRect(&local_24,0,-2);
      if (param_6 != 0) {
        OffsetRect(&local_24,1,1);
      }
      CStringT<>(&DAT_009880f8);
      local_8 = 0;
      FUN_007c2378(&local_34,&local_24,0x25);
      local_8 = 0xffffffff;
      FUN_00406b10();
      pcVar5 = *(code **)(*param_1 + 0x30);
      guard_check_icall(local_2c);
      (*pcVar5)();
      FUN_0079f0b8(local_28);
      pcVar5 = *(code **)(*param_1 + 0x28);
      guard_check_icall(local_30);
      (*pcVar5)();
    }
    else {
      if (*(int *)(local_30 + 0x90) != 0) {
        if (*(int *)(local_30 + 0xc0) == 2) {
          local_2c = (int *)0x1;
        }
        else if (*(int *)(local_30 + 0xc0) == 3) {
          local_2c = (int *)0x0;
        }
      }
      pcVar5 = (code *)((param_2 + param_4) / 2 - *(int *)(local_30 + 0xa4) / 2);
      iVar3 = (param_3 + param_5) / 2 - *(int *)(local_30 + 0xa8) / 2;
      local_34 = iVar3;
      local_28 = pcVar5;
      if (param_6 != 0) {
        piVar4 = (int *)FUN_007c2574();
        pcVar5 = *(code **)(*piVar4 + 0x2ec);
        guard_check_icall(piVar6,iVar2,iVar7,iVar8,iVar9);
        iVar2 = (*pcVar5)();
        pcVar5 = local_28;
        iVar3 = local_34;
        if (iVar2 != 0) {
          pcVar5 = local_28 + 1;
          iVar3 = local_34 + 1;
        }
      }
      if (param_1 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = param_1[1];
      }
      FUN_0079cf15(*(undefined4 *)(local_30 + 200),local_2c,iVar2,pcVar5,iVar3,0);
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCEditBrowseCtrl[93], CMFCToolBarEditCtrl[93], CVSListBoxEditCtrl[93] */
/* 007d726d  FUN_007d726d  118 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007d726d(undefined4 *param_1)

{
  UINT in_stack_ffffffd8;
  LPSTR in_stack_ffffffdc;
  int in_stack_ffffffe0;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7d7279;
  CStringT<>();
  local_8 = 0;
  FID_conflict_LoadStringA((HINSTANCE)0xf100,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0);
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004059f0(&local_18,L"%Ts\r\n%Ts",*param_1,local_14);
  FUN_00793169(local_18,0,0x30);
  FUN_00406b10();
  FUN_00406b10();
  return 0;
}




/* vtable slots: CMFCEditBrowseCtrl[67], CVSListBoxEditCtrl[67] */
/* 007d779e  FUN_007d779e  77 bytes, 1 callers */

undefined4 FUN_007d779e(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (((*(int *)(param_1 + 4) == 0x104) && (in_ECX[0x30] != 0)) &&
     ((*(int *)(param_1 + 8) == 0x28 || (*(int *)(param_1 + 8) == 0x27)))) {
    pcVar1 = *(code **)(*in_ECX + 0x164);
    guard_check_icall();
    (*pcVar1)();
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_007949fb(param_1);
  }
  return uVar2;
}



