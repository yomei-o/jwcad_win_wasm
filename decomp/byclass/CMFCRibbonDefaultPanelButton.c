/* CMFCRibbonDefaultPanelButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonDefaultPanelButton[90] */
/* 0086a829  FUN_0086a829  81 bytes, 0 callers */

void FUN_0086a829(int param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0086612f(param_1);
  iVar2 = *(int *)(param_1 + 0x1c8);
  *(int *)(in_ECX + 0x1c8) = iVar2;
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + 0x88);
  if (iVar2 != 0) {
    pwVar1 = *(wchar_t **)(iVar2 + 0xfc);
    if (pwVar1 == (wchar_t *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_008f899d(pwVar1);
    }
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x6c),pwVar1,iVar2);
  }
  return;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[72] */
/* 0086ae38  FUN_0086ae38  550 bytes, 0 callers */

void FUN_0086ae38(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  double dVar1;
  code *pcVar2;
  CObject *pCVar3;
  int *piVar4;
  int iVar5;
  CMFCRibbonBar *pCVar6;
  uint uVar7;
  HDC hdc;
  CMFCRibbonBaseElement *in_ECX;
  int local_14;
  int local_c;
  int local_8;
  
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonDefaultPanelButton_009989d8,
                              *(CObject **)(in_ECX + 0x8c));
  if (pCVar3 == (CObject *)0x0) {
    if (*(int *)(in_ECX + 0x1c4) == 0) {
      piVar4 = (int *)FUN_007c2574();
      pcVar2 = *(code **)(*piVar4 + 0x268);
      guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0,0);
      (*pcVar2)();
    }
    else {
      local_14 = 0x10;
      local_8 = 0x10;
      iVar5 = FUN_007c2511();
      if (*(int *)(iVar5 + 0x1e8) == 0) {
        dVar1 = 1.0;
      }
      else {
        dVar1 = *(double *)(iVar5 + 0x1e0);
      }
      if (dVar1 != 1.0) {
        FUN_007c2511();
        local_14 = thunk_FUN_008d99f0();
        FUN_007c2511();
        local_8 = thunk_FUN_008d99f0();
      }
      local_c = 0;
      pCVar6 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX);
      if ((pCVar6 != (CMFCRibbonBar *)0x0) && (uVar7 = FUN_00797acc(), (uVar7 & 0x400000) != 0)) {
        local_c = 1;
      }
      iVar5 = FUN_007c2511();
      if (*(int *)(iVar5 + 0x1e8) == 0) {
        dVar1 = 1.0;
      }
      else {
        dVar1 = *(double *)(iVar5 + 0x1e0);
      }
      if ((dVar1 == 1.0) && (local_c == 0)) {
        CDC::DrawState(param_1,(param_5 + param_3) / 2 - local_14 / 2,
                       (param_4 + param_6) / 2 - local_8 / 2,local_14,local_8,
                       *(undefined4 *)(in_ECX + 0x1c4),0,0);
      }
      else {
        hdc = (HDC)0x0;
        if (param_1 != (CDC *)0x0) {
          hdc = *(HDC *)(param_1 + 4);
        }
        DrawIconEx(hdc,(param_5 + param_3) / 2 - local_14 / 2,(param_4 + param_6) / 2 - local_8 / 2,
                   *(HICON *)(in_ECX + 0x1c4),local_14,local_8,0,(HBRUSH)0x0,local_c * 0x10 + 3);
      }
    }
  }
  else {
    pcVar2 = *(code **)(*(int *)pCVar3 + 0x120);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6);
    (*pcVar2)();
  }
  return;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[69] */
/* 0086b6ff  FUN_0086b6ff  157 bytes, 0 callers */

undefined4 * FUN_0086b6ff(undefined4 *param_1)

{
  double dVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_1 = 0x10;
  param_1[1] = 0x10;
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar2 + 0x1e0);
  }
  if (dVar1 != 1.0) {
    FUN_007c2511();
    uVar3 = thunk_FUN_008d99f0();
    *param_1 = uVar3;
    FUN_007c2511();
    uVar3 = thunk_FUN_008d99f0();
    param_1[1] = uVar3;
  }
  return param_1;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[76] */
/* 0086bc7c  FUN_0086bc7c  7 bytes, 0 callers */

undefined4 FUN_0086bc7c(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1c8);
}




/* vtable slots: CMFCRibbonDefaultPanelButton[0] */
/* 0086bd23  FUN_0086bd23  6 bytes, 0 callers */

undefined ** FUN_0086bd23(void)

{
  return &PTR_s_CMFCRibbonDefaultPanelButton_009989d8;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[48] */
/* 0086bd35  FUN_0086bd35  151 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_0086bd35(int *param_1)

{
  BOOL BVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  BVar1 = IsRectEmpty((RECT *)(in_ECX + 0x74));
  if (BVar1 == 0) {
    iVar3 = FUN_004054a0(*(int *)(in_ECX + 0x60) + -0x10);
    iVar3 = iVar3 + 0x10;
  }
  else {
    piVar2 = (int *)CStringT<>();
    iVar3 = *piVar2;
  }
  iVar3 = FUN_004054a0(iVar3 + -0x10);
  *param_1 = iVar3 + 0x10;
  if (BVar1 == 0) {
    FUN_00406b10();
  }
  else {
    FUN_00406b10();
  }
  return param_1;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[153] */
/* 0086c946  FUN_0086c946  29 bytes, 0 callers */

void FUN_0086c946(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x13c);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[95] */
/* 0086c99c  FUN_0086c99c  44 bytes, 0 callers */

void FUN_0086c99c(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x22c);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[94] */
/* 0086ca1c  FUN_0086ca1c  184 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0086ca1c(int *param_1,int param_2,int param_3,int param_4,LONG param_5,LONG param_6,
                 LONG param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  int in_ECX;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_24.left = param_4 + param_3;
  uVar1 = *(undefined4 *)(in_ECX + 0xd4);
  local_8 = 0;
  local_24.top = param_5;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  local_24.right = param_6;
  local_24.bottom = param_7;
  InflateRect(&local_24,-3,0);
  iVar2 = *param_1;
  guard_check_icall(param_2,*(undefined4 *)(param_2 + -0xc),&local_24,0x824);
  (**(code **)(iVar2 + 0x68))();
  *(undefined4 *)(in_ECX + 0xd4) = uVar1;
  piVar4 = (int *)FUN_007c2574();
  pcVar3 = *(code **)(*piVar4 + 0x234);
  guard_check_icall(param_1,in_ECX,param_4,param_5,param_6,param_7,param_8,param_9);
  (*pcVar3)();
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[119] */
/* 0086cf60  FUN_0086cf60  128 bytes, 0 callers */

undefined4 FUN_0086cf60(void)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    BVar3 = IsRectEmpty((RECT *)(in_ECX[0x72] + 0xcc));
    if (((BVar3 == 0) && (iVar2 = FUN_0086c441(), iVar2 == 0)) && (in_ECX[0x31] == 0)) {
      return 0;
    }
    pcVar1 = *(code **)(*in_ECX + 0x13c);
    guard_check_icall();
    (*pcVar1)();
    if (in_ECX[0x27] != 0) {
      SendMessageW(*(HWND *)(in_ECX[0x27] + 0x20),0x100,0x28,0);
    }
  }
  return 0;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[132] */
/* 0086d9ea  FUN_0086d9ea  44 bytes, 0 callers */

void FUN_0086d9ea(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_008644c5(param_1,param_2);
  pcVar1 = *(code **)(*in_ECX + 0x13c);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[79] */
/* 0086dc0d  FUN_0086dc0d  13 bytes, 0 callers */

void FUN_0086dc0d(void)

{
  undefined4 in_ECX;
  
  FUN_00870e21(in_ECX);
  return;
}




/* vtable slots: CMFCRibbonDefaultPanelButton[43] */
/* 00870ae4  FUN_00870ae4  228 bytes, 0 callers */

undefined4 FUN_00870ae4(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  wchar_t *pwVar3;
  
  iVar2 = FUN_00869cab(param_1,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  if ((in_ECX[0x1f] == in_ECX[0x1d]) && (in_ECX[0x20] == in_ECX[0x1e])) {
    *(undefined4 *)(param_2 + 0x18) = 0x16;
    iVar2 = FUN_008f899d(L"group");
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(param_2 + 4),L"group",iVar2);
    iVar2 = in_ECX[0x72];
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar2 + 0xcc);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(iVar2 + 0xd0);
    *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(iVar2 + 0xd4);
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(iVar2 + 0xd8);
    FUN_0079e8b8((undefined4 *)(param_2 + 0x24));
    *(undefined4 *)(param_2 + 0x1c) = 0;
    iVar2 = FUN_008f899d(&DAT_00956338);
    pwVar3 = L"";
  }
  else {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x40000000;
    *(undefined4 *)(param_2 + 0x18) = 0x3a;
    iVar2 = FUN_008f899d(L"Open");
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(param_2 + 0x14),L"Open",iVar2);
    pcVar1 = *(code **)(*in_ECX + 0xe4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      return 1;
    }
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 8;
    iVar2 = FUN_008f899d(L"Close");
    pwVar3 = L"Close";
  }
  ATL::CSimpleStringT<wchar_t,0>::SetString
            ((CSimpleStringT<wchar_t,0> *)(param_2 + 0x14),pwVar3,iVar2);
  return 1;
}



