/* CMDIChildWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMDIChildWnd[1], CMDIFrameWnd[1] */
/* 008a254d  FUN_008a254d  51 bytes, 0 callers */

void FUN_008a254d(byte param_1)

{
  FUN_00799509();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CMDIChildWnd[95] */
/* 008a2580  FUN_008a2580  268 bytes, 1 callers */

void FUN_008a2580(int param_1)

{
  uint uVar1;
  CMDIFrameWnd *this;
  uint uVar2;
  int iVar3;
  LRESULT LVar4;
  CFrameWnd *in_ECX;
  CFrameWnd *local_8;
  
  local_8 = in_ECX;
  uVar1 = FUN_00797b3d();
  this = (CMDIFrameWnd *)FUN_008a2a09();
  if (param_1 == -1) {
    CMDIFrameWnd::MDIGetActive(this,(int *)&local_8);
    uVar2 = FUN_00797b3d();
    if ((local_8 == (CFrameWnd *)0x0) && ((uVar2 & 0x1000000) == 0)) {
      if ((uVar2 & 0x20000000) != 0) {
        param_1 = 2;
      }
    }
    else {
      param_1 = 3;
    }
  }
  CFrameWnd::ActivateFrame(in_ECX,param_1);
  iVar3 = FUN_008a2a09();
  SendMessageW(*(HWND *)(iVar3 + 0x120),0x234,0,0);
  uVar2 = FUN_00797b3d();
  uVar2 = uVar2 >> 0x1c & 1;
  if (uVar2 != (uVar1 >> 0x1c & 1)) {
    if (uVar2 == 0) {
      LVar4 = SendMessageW(*(HWND *)(this + 0x120),0x229,0,0);
      if (LVar4 == *(int *)(in_ECX + 0x20)) {
        FUN_008a2ce5();
        LVar4 = SendMessageW(*(HWND *)(this + 0x120),0x229,0,0);
        if (LVar4 == *(int *)(in_ECX + 0x20)) {
          SendMessageW(*(HWND *)(this + 0x120),0x222,*(WPARAM *)(in_ECX + 0x20),0);
          *(undefined4 *)(in_ECX + 0x124) = 1;
        }
      }
    }
    else if (*(int *)(in_ECX + 0x124) != 0) {
      SendMessageW(*(HWND *)(this + 0x120),0x222,0,*(LPARAM *)(in_ECX + 0x20));
    }
  }
  return;
}




/* vtable slots: CMDIChildWnd[112], CMDIChildWndEx[112] */
/* 008a268c  FUN_008a268c  424 bytes, 0 callers */

undefined4
FUN_008a268c(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4,int *param_5,
            undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  HWND hWnd;
  uint uVar3;
  int *in_ECX;
  undefined4 *puVar4;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  undefined4 local_c;
  HWND local_8;
  
  if ((param_5 == (int *)0x0) &&
     ((iVar2 = FUN_0079d18b(), iVar2 == 0 ||
      (param_5 = *(int **)(iVar2 + 0x20), param_5 == (int *)0x0)))) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pcVar1 = *(code **)(*param_5 + 0x178);
  guard_check_icall(1);
  (*pcVar1)();
  local_30 = 0;
  local_34 = param_1;
  local_40 = *param_4;
  local_44 = param_4[1];
  local_38 = param_2;
  local_3c = param_3;
  local_48 = param_4[2] - local_40;
  local_4c = param_4[3] - local_44;
  local_50 = param_5[8];
  local_54 = 0;
  iVar2 = FUN_0079dd6d();
  local_58 = *(undefined4 *)(iVar2 + 8);
  local_5c = param_6;
  pcVar1 = *(code **)(*in_ECX + 100);
  puVar4 = &local_5c;
  guard_check_icall(puVar4);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x120);
    guard_check_icall(puVar4);
    (*pcVar1)();
  }
  else {
    local_2c = local_34;
    local_28 = local_38;
    local_24 = local_58;
    local_20 = local_40;
    local_1c = local_44;
    local_18 = local_48;
    local_14 = local_4c;
    local_10 = local_3c & 0xeeffffff;
    local_c = local_5c;
    FUN_00790fd2(in_ECX);
    hWnd = (HWND)SendMessageW((HWND)param_5[0x48],0x220,0,(LPARAM)&local_2c);
    local_8 = hWnd;
    iVar2 = FUN_0079134d();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x120);
      guard_check_icall();
      (*pcVar1)();
      hWnd = local_8;
    }
    if (hWnd != (HWND)0x0) {
      if ((local_3c & 0x10000000) != 0) {
        BringWindowToTop(hWnd);
        if ((local_3c & 0x20000000) == 0) {
          uVar3 = (local_3c & 0x1000000 | 0x800000) >> 0x17;
        }
        else {
          uVar3 = 2;
        }
        FUN_00797f20(uVar3);
        FUN_008a2c3e(in_ECX);
        SendMessageW((HWND)param_5[0x48],0x234,0,0);
      }
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMDIChildWnd[71], CMDIChildWndEx[71] */
/* 008a2920  FUN_008a2920  25 bytes, 0 callers */

void FUN_008a2920(UINT param_1,WPARAM param_2,LPARAM param_3)

{
  int in_ECX;
  
  DefMDIChildProcW(*(HWND *)(in_ECX + 0x20),param_1,param_2,param_3);
  return;
}




/* vtable slots: CMDIChildWnd[24], CMDIChildWndEx[24] */
/* 008a2983  FUN_008a2983  116 bytes, 0 callers */

undefined4 FUN_008a2983(void)

{
  HWND hWnd;
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  LONG dwNewLong;
  BOOL BVar5;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) == 0) {
    uVar2 = 0;
  }
  else {
    piVar3 = (int *)FUN_008a2a09();
    hWnd = (HWND)piVar3[8];
    uVar4 = GetWindowLongW(hWnd,-0x10);
    dwNewLong = SetWindowLongW(hWnd,-0x10,uVar4 & 0xffff7fff);
    FUN_008a2c5e();
    BVar5 = IsWindow(hWnd);
    if (BVar5 != 0) {
      SetWindowLongW(hWnd,-0x10,dwNewLong);
      pcVar1 = *(code **)(*piVar3 + 0x1a4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMDIChildWnd[102], CMDIChildWndEx[102] */
/* 008a2a20  FUN_008a2a20  32 bytes, 0 callers */

void FUN_008a2a20(void)

{
  code *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_008a2a09();
  pcVar1 = *(code **)(*piVar2 + 0x198);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMDIChildWnd[10] */
/* 008a2a40  FUN_008a2a40  6 bytes, 0 callers */

undefined ** FUN_008a2a40(void)

{
  return &PTR_FUN_0099fbe0;
}




/* vtable slots: CMDIChildWnd[0] */
/* 008a2a4c  FUN_008a2a4c  6 bytes, 0 callers */

undefined ** FUN_008a2a4c(void)

{
  return &PTR_s_CMDIChildWnd_0099f74c;
}




/* vtable slots: CMDIChildWnd[96], CMDIChildWndEx[96] */
/* 008a2a58  FUN_008a2a58  71 bytes, 0 callers */

undefined4 FUN_008a2a58(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar2 = FUN_0079296c();
  if (iVar2 != 0) {
    FUN_0079296c();
    iVar2 = FUN_007930a1();
    if (iVar2 != 0) {
      piVar3 = (int *)FUN_0079296c();
      pcVar1 = *(code **)(*piVar3 + 0x180);
      guard_check_icall();
      uVar4 = (*pcVar1)();
      return uVar4;
    }
  }
  return *(undefined4 *)(in_ECX + 0xd4);
}




/* vtable slots: CMDIChildWnd[90], CMDIChildWndEx[90] */
/* 008a2b11  FUN_008a2b11  214 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_008a2b11(HINSTANCE param_1,uint param_2,undefined4 param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  UINT in_stack_ffffffd4;
  LPSTR in_stack_ffffffd8;
  int in_stack_ffffffdc;
  wchar_t *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8a2b1d;
  in_ECX[0x34] = (int)param_1;
  if ((param_4 != 0) && (iVar2 = *(int *)(param_4 + 8), iVar2 != 0)) {
    in_ECX[0x48] = *(int *)(iVar2 + 0x88);
    in_ECX[0x23] = *(int *)(iVar2 + 0x8c);
  }
  CStringT<>();
  local_8 = 0;
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = FID_conflict_LoadStringA(param_1,in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc);
  if (iVar2 != 0) {
    AfxExtractSubString((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                        local_14,local_18,0,L'\n');
  }
  pcVar1 = *(code **)(*in_ECX + 0x1c0);
  uVar3 = FUN_00799ec3(param_2 | 0x40000000,param_1);
  guard_check_icall(uVar3,local_14[0],param_2 | 0x40000000,&DAT_00a00354,param_3,param_4);
  iVar2 = (*pcVar1)();
  FUN_00406b10();
  FUN_00406b10();
  return iVar2 != 0;
}




/* vtable slots: CMDIChildWnd[113], CMDIChildWndEx[113] */
/* 008a3200  FUN_008a3200  179 bytes, 0 callers */

void FUN_008a3200(int param_1,int param_2,WPARAM param_3)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  LPARAM lParam;
  int *in_ECX;
  UINT Msg;
  
  piVar2 = (int *)FUN_008a2a09();
  if (param_3 == 0) {
    if (param_1 == 0) {
LAB_008a3256:
      param_3 = in_ECX[0x48];
      if (param_3 != 0) goto LAB_008a3263;
LAB_008a3297:
      lParam = 0;
      param_3 = 0;
      Msg = 0x234;
      goto LAB_008a32a0;
    }
    pcVar1 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall();
    piVar3 = (int *)(*pcVar1)();
    if (piVar3 == (int *)0x0) goto LAB_008a3256;
    pcVar1 = *(code **)(*piVar3 + 0xec);
    guard_check_icall();
    param_3 = (*pcVar1)();
    if (param_3 == 0) goto LAB_008a3256;
LAB_008a3269:
    pcVar1 = *(code **)(*piVar2 + 0x1c4);
    guard_check_icall(param_3);
    lParam = (*pcVar1)();
  }
  else {
LAB_008a3263:
    if (param_1 != 0) goto LAB_008a3269;
    if (param_2 != 0) goto LAB_008a3297;
    lParam = 0;
    param_3 = piVar2[0x22];
  }
  Msg = 0x230;
LAB_008a32a0:
  SendMessageW((HWND)piVar2[0x48],Msg,param_3,lParam);
  return;
}




/* vtable slots: CMDIChildWnd[105] */
/* 008a330a  FUN_008a330a  264 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a330a(int param_1)

{
  code *pcVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  errno_t eVar7;
  int *in_ECX;
  wchar_t local_434 [516];
  wchar_t local_2c [18];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  piVar2 = (int *)FUN_008a2a09();
  pcVar1 = *(code **)(*piVar2 + 0x1a4);
  iVar4 = param_1;
  guard_check_icall(param_1);
  (*pcVar1)();
  uVar3 = FUN_00797b3d();
  if ((uVar3 & 0x8000) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall(iVar4);
    iVar4 = (*pcVar1)();
    if (param_1 != 0) {
      if (iVar4 == 0) {
        iVar4 = in_ECX[0x3c];
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x20);
      }
      uVar5 = FUN_008f8e5e(local_434,0x204,iVar4,0xffffffff);
      FUN_00404bd0(uVar5);
      if (0 < in_ECX[0x21]) {
        FID_conflict__swprintf(local_2c,(wchar_t *)0x11,&DAT_0097dd6c,in_ECX[0x21]);
        iVar4 = FUN_008f899d(local_2c);
        iVar6 = FUN_008f899d(local_434);
        if ((uint)(iVar4 + iVar6) < 0x204) {
          eVar7 = _wcscat_s(local_434,0x204,local_2c);
          FUN_00404bd0(eVar7);
        }
      }
      FUN_007c16be(in_ECX[8],local_434);
    }
  }
  return;
}




/* vtable slots: CMDIChildWnd[25] */
/* 008a3662  FUN_008a3662  9 bytes, 1 callers */

void FUN_008a3662(void)

{
  PreCreateWindow();
  return;
}




/* vtable slots: CMDIChildWnd[67] */
/* 008a368e  FUN_008a368e  121 bytes, 1 callers */

undefined4 FUN_008a368e(LPMSG param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  HACCEL hAccTable;
  int *in_ECX;
  
  if ((param_1->message == 0x201) || (param_1->message == 0xa1)) {
    AfxCancelModes(param_1->hwnd);
  }
  iVar2 = FUN_007949fb(param_1);
  if (iVar2 == 0) {
    if (param_1->message - 0x100 < 10) {
      pcVar1 = *(code **)(*in_ECX + 0x1ac);
      guard_check_icall();
      hAccTable = (HACCEL)(*pcVar1)();
      if (hAccTable != (HACCEL)0x0) {
        iVar2 = FUN_008a2a09();
        iVar2 = TranslateAcceleratorW(*(HWND *)(iVar2 + 0x20),hAccTable,param_1);
        if (iVar2 != 0) goto LAB_008a36bd;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_008a36bd:
    uVar3 = 1;
  }
  return uVar3;
}



