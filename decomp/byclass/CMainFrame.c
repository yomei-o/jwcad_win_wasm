/* CMainFrame -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMainFrame[1] */
/* 00565f90  FUN_00565f90  68 bytes, 0 callers */

undefined4 FUN_00565f90(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00565d50();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x14b8);
    }
  }
  return in_ECX;
}




/* vtable slots: CMainFrame[10] */
/* 00566610  FUN_00566610  16 bytes, 0 callers */

void FUN_00566610(void)

{
  FUN_00566890();
  return;
}




/* vtable slots: CMainFrame[0] */
/* 00566620  FUN_00566620  16 bytes, 0 callers */

undefined ** FUN_00566620(void)

{
  return &PTR_s_CMainFrame_0096a270;
}




/* vtable slots: CMainFrame[25] */
/* 0056d260  FUN_0056d260  25 bytes, 0 callers */

void FUN_0056d260(undefined4 param_1)

{
  PreCreateWindow(param_1);
  return;
}




/* vtable slots: CMainFrame[31] */
/* 0056ed10  FUN_0056ed10  1644 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0056ed10(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  CFileStatus *pCVar5;
  wchar_t *pwVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 local_31c [4];
  int local_318;
  BSTR local_314;
  undefined1 local_310 [4];
  CWinApp *local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_2fc;
  undefined4 local_2f8;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_2f4 [4];
  undefined4 local_2f0;
  undefined1 local_2ec [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_2e8 [4];
  undefined4 local_2e4;
  undefined4 local_2e0;
  wchar_t *local_2dc;
  wchar_t *local_2d8;
  int local_2d4;
  uint local_2d0;
  HWND local_2cc;
  CWnd *local_2c8;
  CWnd *local_2c4;
  HWND local_2c0;
  int local_2bc;
  HWND local_2b8;
  int *local_2b4;
  int local_2b0;
  char local_2a9;
  int local_2a8;
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> local_2a4 [7];
  CWaitCursor local_29d;
  CWnd *local_29c;
  tagRECT local_298;
  CFileStatus local_288 [576];
  undefined4 local_48 [2];
  int local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092d6a7;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  local_30c = AfxGetApp();
  CWaitCursor::CWaitCursor(&local_29d);
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)local_29c + 0x150))(uVar1);
  if (iVar2 != 0) {
    local_2c4 = local_29c;
    (**(code **)(*(int *)local_29c + 0x1b4))();
  }
  FUN_00406bc0(0x1f,0,0);
  FUN_0056d7a0(0x1f,0,0,1,1);
  local_2c8 = CWnd::GetTopLevelParent(local_29c);
  FUN_00406bc0(0x1f,0,0);
  FUN_0056d7a0(0x1f,0,0,1,1);
  local_2cc = GetCapture();
  if (local_2cc != (HWND)0x0) {
    SendMessageW(local_2cc,0x1f,0,0);
  }
  CStringT<>(*(undefined4 *)(local_30c + 0x68));
  local_8._0_1_ = 1;
  pwVar6 = L".hlp";
  local_308 = ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::Right
                        (local_2a4,(int)local_310);
  local_8._0_1_ = 2;
  local_304 = local_308;
  iVar2 = FUN_0046a2e0(pwVar6);
  local_2a9 = iVar2 == 0;
  local_2d0 = (uint)(byte)local_2a9;
  local_8._0_1_ = 1;
  FUN_00404540();
  if (local_2a9 != '\0') {
    iVar2 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength((CSimpleStringT<wchar_t,0> *)local_2a4);
    local_2dc = (wchar_t *)Left(local_2ec,iVar2 + -4);
    local_8._0_1_ = 3;
    local_2d8 = local_2dc;
    local_2e4 = ATL::operator+(local_2e8,local_2dc);
    local_8._0_1_ = 4;
    local_2e0 = local_2e4;
    FUN_00404860(local_2e4);
    local_8._0_1_ = 3;
    FUN_00404540();
    local_8._0_1_ = 1;
    FUN_00404540();
  }
  CFileStatus::CFileStatus(local_288);
  uVar7 = 0;
  pCVar5 = local_288;
  uVar3 = FUN_00404920(pCVar5,0);
  iVar2 = FUN_007abbe2(uVar3,pCVar5,uVar7);
  if (iVar2 == 0) {
    AfxMessageBox(0xf107,0,0xffffffff);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00408b00();
    ExceptionList = local_10;
    return;
  }
  local_2b8 = GetDesktopWindow();
  local_2b0 = 0;
  local_2bc = param_2;
  if (param_2 != 1) {
    if ((param_2 == 3) || (param_2 == 0xb)) {
      uVar8 = 0;
      uVar7 = 0;
      uVar3 = FUN_00404920(0,0);
      local_2b0 = _HtmlHelpW_16(local_2b8,uVar3,uVar7,uVar8);
    }
    goto LAB_0056f238;
  }
  local_2b4 = &DAT_00a10228;
  if ((DAT_00a10228 != 0) && (DAT_00a1022c == 1)) {
    local_2c0 = DAT_00a10234;
    local_2a8 = GetDlgCtrlID(DAT_00a10234);
    iVar2 = local_2a8 + 0x10000;
    uVar7 = 0xf;
    local_2d4 = iVar2;
    uVar3 = FUN_00404920(0xf,iVar2);
    local_2b0 = _HtmlHelpW_16(local_2b8,uVar3,uVar7,iVar2);
    if (local_2b0 != 0) goto LAB_0056f238;
    if (((((local_2b4[4] != 0) && (local_2a8 != 1)) && (local_2a8 != 2)) &&
        ((local_2a8 != 0xe146 && (local_2a8 != 6)))) &&
       ((local_2a8 != 7 && ((local_2a8 != 3 && (local_2a8 != 5)))))) {
      FUN_00413f30();
      GetWindowRect(local_2c0,&local_298);
      _memset(local_48,0,0x34);
      local_48[0] = 0x34;
      local_40 = local_2d4;
      puVar4 = (undefined4 *)FUN_0041c8d0(local_298.left,local_298.bottom);
      local_38 = *puVar4;
      local_34 = puVar4[1];
      local_2c = 0xffffffff;
      local_30 = 0xffffffff;
      puVar4 = (undefined4 *)FUN_00416040(0xffffffff,0xffffffff,0xffffffff,0xffffffff);
      local_28 = *puVar4;
      local_24 = puVar4[1];
      local_20 = puVar4[2];
      local_1c = puVar4[3];
      puVar4 = local_48;
      uVar7 = 0xe;
      local_2f0 = ATL::operator+(local_2f4,(wchar_t *)local_2a4);
      uVar3 = FUN_00404920(uVar7,puVar4);
      local_2b0 = _HtmlHelpW_16(local_2c0,uVar3,uVar7,puVar4);
      FUN_00404540();
      goto LAB_0056f238;
    }
  }
  local_2b0 = 0;
  uVar7 = 0xf;
  uVar3 = FUN_00404920(0xf,param_1);
  local_2b0 = _HtmlHelpW_16(local_2b8,uVar3,uVar7,param_1);
LAB_0056f238:
  if (local_2b0 == 0) {
    *(int *)(local_29c + 0x13bc) = *(int *)(local_29c + 0x13bc) + 1;
    if (*(int *)(local_29c + 0x13bc) < 5) {
      uVar8 = 0;
      uVar7 = 0x80e4;
      uVar3 = 0x111;
      FUN_00799e17(0x111,0x80e4,0);
      FUN_00406bc0(uVar3,uVar7,uVar8);
    }
    else {
      _HtmlHelpW_16(local_2b8,0,0x14,local_31c);
      if ((local_318 < 0) && (local_314 != (BSTR)0x0)) {
        uVar8 = 0;
        uVar7 = 0;
        local_2fc = CStringT<>(local_314);
        local_8._0_1_ = 5;
        local_2f8 = local_2fc;
        uVar3 = FUN_00404920(uVar7,uVar8);
        FUN_0079f557(uVar3,uVar7,uVar8);
        local_8._0_1_ = 1;
        FUN_00404540();
        SysFreeString(local_314);
      }
      *(undefined4 *)(local_29c + 0x13bc) = 0;
    }
  }
  else {
    *(undefined4 *)(local_29c + 0x13bc) = 0;
  }
  DAT_00a10228 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404540();
  local_8 = 0xffffffff;
  FUN_00408b00();
  ExceptionList = local_10;
  return;
}



