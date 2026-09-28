/* CMFCOutlookBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCOutlookBar[1] */
/* 0080bdc0  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCOutlookBar::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCOutlookBar::_scalar_deleting_destructor_(CMFCOutlookBar *this,uint param_1)

{
  FUN_0080bd31();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x3b0);
    }
  }
  return this;
}




/* vtable slots: CMFCOutlookBar[97] */
/* 0080be50  FUN_0080be50  129 bytes, 0 callers */

undefined4 FUN_0080be50(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (uVar3 = 0, in_ECX[0xe9] != 0)) {
    uVar3 = 0;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x1cc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      iVar2 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPaneAdapter_00a00bcc);
      if (((iVar2 != 0) || (iVar2 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPane_00a006a0), iVar2 != 0))
         || (iVar2 = FUN_0079d98a(&PTR_s_CMFCOutlookBar_00a00680), iVar2 != 0)) {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = FUN_0080bdf3(param_1);
    }
  }
  return uVar3;
}




/* vtable slots: CMFCOutlookBar[249] */
/* 0080bed8  FUN_0080bed8  20 bytes, 0 callers */

undefined4 FUN_0080bed8(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x3a4) != 0) {
    return 1;
  }
  return *(undefined4 *)(in_ECX + 0x36c);
}




/* vtable slots: CMFCOutlookBar[253] */
/* 0080beec  FUN_0080beec  154 bytes, 0 callers */

undefined4
FUN_0080beec(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,uint param_6,undefined4 param_7)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  CBasePane *in_ECX;
  
  iVar2 = Create(param_1,param_2,param_3,0,param_4,param_5,0x40,param_6 & 0xfffffffe,param_7);
  uVar3 = 0;
  if (iVar2 != 0) {
    if ((param_6 & 4) == 0) {
      iVar2 = FUN_0085a847(param_2);
      if (iVar2 != 0) {
        FUN_00845032(in_ECX,1,0,0);
      }
    }
    else {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x1ec);
      guard_check_icall(0xf000);
      (*pcVar1)();
      CBasePane::DockPaneUsingRTTI(in_ECX,0);
    }
    if (param_1 != (wchar_t *)0x0) {
      iVar2 = FUN_008f899d(param_1);
      ATL::CSimpleStringT<wchar_t,0>::SetString
                ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x3ac),param_1,iVar2);
    }
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CMFCOutlookBar[238] */
/* 0080bfb7  FUN_0080bfb7  98 bytes, 0 callers */

undefined4 FUN_0080bfb7(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x3a0);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar1)();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCOutlookBarTabCtrl_0099cee0,pCVar2);
  pcVar1 = *(code **)(*(int *)pCVar2 + 0x1ac);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 < 2) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0085dcb5(param_1,param_2,param_3,param_4);
  }
  return uVar4;
}




/* vtable slots: CMFCOutlookBar[210] */
/* 0080c020  FUN_0080c020  336 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0080c020(LONG param_1,LONG param_2,int param_3)

{
  code *pcVar1;
  POINT pt;
  POINT pt_00;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  int *in_ECX;
  RECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((int *)in_ECX[0xdc] == (int *)0x0) {
LAB_0080c15d:
    iVar2 = 0;
  }
  else {
    pcVar1 = *(code **)(*(int *)in_ECX[0xdc] + 0x1ac);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0xdc] + 0x1a4);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        pcVar1 = *(code **)(*in_ECX + 0x334);
        guard_check_icall(param_1,param_2,1);
        iVar2 = (*pcVar1)();
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        local_28.left = 0;
        local_28.top = 0;
        local_28.right = 0;
        local_28.bottom = 0;
        pcVar1 = *(code **)(*in_ECX + 0x32c);
        guard_check_icall(&local_18,&local_28);
        (*pcVar1)();
        BVar3 = IsRectEmpty(&local_18);
        if (BVar3 == 0) {
          local_18.bottom = local_18.bottom + param_3;
        }
        BVar3 = IsRectEmpty(&local_28);
        if (BVar3 == 0) {
          local_28.top = local_28.top - param_3;
        }
        if (((iVar2 != 2) &&
            (pt.y = param_2, pt.x = param_1, BVar3 = PtInRect(&local_18,pt), BVar3 == 0)) &&
           (pt_00.y = param_2, pt_00.x = param_1, BVar3 = PtInRect(&local_28,pt_00), BVar3 == 0)) {
          iVar2 = FUN_0088e78a(param_1,param_2,param_3);
          pcVar1 = *(code **)(*in_ECX + 0x1cc);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          if (iVar4 != 0) {
            return iVar2;
          }
          if (iVar2 != 2) {
            return iVar2;
          }
          goto LAB_0080c15d;
        }
      }
    }
    iVar2 = 3;
  }
  return iVar2;
}




/* vtable slots: CMFCOutlookBar[10] */
/* 0080c170  FUN_0080c170  6 bytes, 0 callers */

undefined ** FUN_0080c170(void)

{
  return &PTR_FUN_0098cfd8;
}




/* vtable slots: CMFCOutlookBar[163] */
/* 0080c176  FUN_0080c176  22 bytes, 0 callers */

void FUN_0080c176(CSimpleStringT<wchar_t,0> *param_1)

{
  int in_ECX;
  
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_1,(CSimpleStringT<wchar_t,0> *)(in_ECX + 0x3ac));
  return;
}




/* vtable slots: CMFCOutlookBar[0] */
/* 0080c18c  FUN_0080c18c  6 bytes, 0 callers */

undefined ** FUN_0080c18c(void)

{
  return &PTR_s_CMFCOutlookBar_00a00680;
}




/* vtable slots: CMFCOutlookBar[203] */
/* 0080c192  FUN_0080c192  115 bytes, 0 callers */

void FUN_0080c192(LPRECT param_1,LPRECT param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  SetRectEmpty(param_1);
  SetRectEmpty(param_2);
  pcVar1 = *(code **)(*in_ECX + 0x1cc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    GetClientRect((HWND)in_ECX[8],param_1);
    FUN_0079e8b8(param_1);
  }
  else if ((int *)in_ECX[0xdc] != (int *)0x0) {
    pcVar1 = *(code **)(*(int *)in_ECX[0xdc] + 0x168);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCOutlookBar[139] */
/* 0080c295  FUN_0080c295  754 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0080c295(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  CWnd *pCVar4;
  undefined4 uVar5;
  undefined1 local_c4 [44];
  CArchive local_98 [80];
  undefined4 local_48;
  undefined4 local_44;
  long local_40;
  int *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  long local_24;
  long local_20;
  CWnd *local_1c;
  CObject *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xb4;
  local_8 = 0x80c2a4;
  FUN_0085e08f(param_1,param_2,param_3);
  FUN_008592c1(&local_2c,L"MFCOutlookBars",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(&local_28,L"%TsMFCOutlookBar-%d",local_2c,param_2);
  }
  else {
    FUN_004059f0(&local_28,L"%TsMFCOutlookBar-%d%x",local_2c,param_2,param_3);
  }
  local_34 = 0;
  local_3c = (int *)0x0;
  local_38 = 0;
  local_8._0_1_ = 2;
  local_18 = (CObject *)FUN_00859490(0,1);
  pcVar1 = *(code **)(*(int *)local_18 + 0x10);
  guard_check_icall(local_28);
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    if (local_3c != (int *)0x0) {
      pcVar1 = *(code **)(*local_3c + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    FUN_00406b10();
    FUN_00406b10();
  }
  else {
    pcVar1 = *(code **)(*(int *)local_18 + 0x44);
    guard_check_icall(L"MFCOutlookCustomPages",&local_34,&local_48);
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*(int *)local_1c + 0x3a0);
      guard_check_icall(local_28);
      local_30 = (int *)(*pcVar1)();
      local_8._0_1_ = 3;
      FUN_007b57de(local_34,local_48,0);
      local_8._0_1_ = 4;
      FUN_007a6256(local_c4,1,0x1000,0);
      local_8 = CONCAT31(local_8._1_3_,5);
      local_40 = 0;
      CArchive::operator>>(local_98,&local_40);
      local_24 = 0;
      while( true ) {
        if (local_40 <= local_24) break;
        local_20 = 0;
        CStringT<>();
        local_8._0_1_ = 6;
        CArchive::operator>>(local_98,&local_20);
        FUN_0047fc90(&local_44);
        local_18 = (CObject *)FUN_0078e624(0x1de0);
        local_8._0_1_ = 7;
        if (local_18 == (CObject *)0x0) {
          local_18 = (CObject *)0x0;
        }
        else {
          local_18 = (CObject *)
                     CMFCOutlookBarPane::CMFCOutlookBarPane((CMFCOutlookBarPane *)local_18);
        }
        local_8._0_1_ = 6;
        pcVar1 = *(code **)(*(int *)local_18 + 0x438);
        guard_check_icall(local_1c,0x50402808,local_20,0);
        (*pcVar1)();
        pCVar4 = CWnd::GetOwner(local_1c);
        pCVar2 = local_18;
        if (pCVar4 == (CWnd *)0x0) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(undefined4 *)(pCVar4 + 0x20);
        }
        *(undefined4 *)(local_18 + 0x5c) = uVar5;
        pcVar1 = *(code **)(*(int *)local_18 + 0x22c);
        guard_check_icall(param_1,local_20,local_20);
        (*pcVar1)();
        CObList::AddTail((CObList *)(local_1c + 0x388),pCVar2);
        pcVar1 = *(code **)(*local_30 + 0x18c);
        guard_check_icall(local_18,local_44,0xffffffff,1);
        (*pcVar1)();
        local_8 = CONCAT31(local_8._1_3_,5);
        (&DAT_00a13178)[local_20 - _DAT_00a0069c] = 1;
        FUN_00406b10();
        local_24 = local_24 + 1;
      }
      local_24 = 0;
      CArchive::operator>>(local_98,&local_24);
      local_30[0x95] = local_24;
      FUN_007a6389();
      FUN_007b583b();
      uVar5 = FUN_0080c5a6();
      return uVar5;
    }
    if (local_3c != (int *)0x0) {
      pcVar1 = *(code **)(*local_3c + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    FUN_00406b10();
    FUN_00406b10();
  }
  return 0;
}




/* vtable slots: CMFCOutlookBar[140] */
/* 0080c7d2  FUN_0080c7d2  686 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0080c7d2(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  long lVar5;
  int iVar6;
  HWND pHVar7;
  int iVar8;
  int *in_ECX;
  undefined8 uVar9;
  CArchive local_a4 [72];
  undefined1 local_5c [52];
  undefined4 local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_8 = 0x80c7e1;
  local_20 = in_ECX;
  FUN_0085e52f(param_1,param_2,param_3);
  local_18[0] = in_ECX[0xe3];
  while (local_18[0] != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(local_18);
    piVar4 = (int *)*puVar2;
    uVar3 = FUN_00797a2b();
    pcVar1 = *(code **)(*piVar4 + 0x230);
    guard_check_icall(param_1,uVar3,uVar3);
    (*pcVar1)();
    in_ECX = local_20;
  }
  FUN_008592c1(&local_28,L"MFCOutlookBars",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_18,L"%TsMFCOutlookBar-%d",local_28,param_2);
  }
  else {
    FUN_004059f0(local_18,L"%TsMFCOutlookBar-%d%x",local_28,param_2,param_3);
  }
  local_8._0_1_ = 2;
  FUN_007b57a7(0x400);
  local_8._0_1_ = 3;
  FUN_007a6256(local_5c,0,0x1000,0);
  local_8 = CONCAT31(local_8._1_3_,4);
  CArchive::operator<<(local_a4,in_ECX[0xe5]);
  local_1c = in_ECX[0xe3];
  while (local_1c != 0) {
    piVar4 = (int *)FUN_0044f2d0(&local_1c);
    piVar4 = (int *)*piVar4;
    lVar5 = FUN_00797a2b();
    CArchive::operator<<(local_a4,lVar5);
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,5);
    pcVar1 = *(code **)(*piVar4 + 0x16c);
    guard_check_icall();
    iVar6 = (*pcVar1)();
    if (iVar6 == 0) {
      pHVar7 = GetParent((HWND)piVar4[8]);
      CWnd::FromHandle(pHVar7);
    }
    FUN_00792c64(&local_20);
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (local_a4,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                        &local_20);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_00406b10();
  }
  pcVar1 = *(code **)(*in_ECX + 0x3a0);
  guard_check_icall();
  iVar6 = (*pcVar1)();
  if (iVar6 == 0) {
    lVar5 = -1;
  }
  else {
    lVar5 = *(long *)(iVar6 + 0x254);
  }
  CArchive::operator<<(local_a4,lVar5);
  FUN_007a67a4();
  local_8._0_1_ = 3;
  FUN_007a6389();
  uVar9 = FUN_007b5a11();
  local_20 = (int *)((ulonglong)uVar9 >> 0x20);
  local_1c = (int)uVar9;
  iVar6 = FUN_007b592a();
  if (iVar6 != 0) {
    local_24 = (int *)0x0;
    local_20 = (int *)0x0;
    local_8._0_1_ = 6;
    piVar4 = (int *)FUN_00859490(0,0);
    pcVar1 = *(code **)(*piVar4 + 0xc);
    guard_check_icall(local_18[0]);
    iVar8 = (*pcVar1)();
    if (iVar8 != 0) {
      pcVar1 = *(code **)(*piVar4 + 0x28);
      guard_check_icall(L"MFCOutlookCustomPages",iVar6,local_1c);
      (*pcVar1)();
    }
    FUN_008f43b0(iVar6);
    if (local_24 != (int *)0x0) {
      pcVar1 = *(code **)(*local_24 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  FUN_007b583b();
  FUN_00406b10();
  FUN_00406b10();
  return 1;
}



