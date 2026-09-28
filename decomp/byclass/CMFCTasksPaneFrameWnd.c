/* CMFCTasksPaneFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTasksPaneFrameWnd[94], CPaneFrameWnd[94] */
/* 0083eb81  FUN_0083eb81  333 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0083eb81(int *param_1)

{
  code *pcVar1;
  int iVar2;
  LRESULT LVar3;
  int *in_ECX;
  undefined4 uVar4;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x83eb8d;
  iVar2 = FUN_0079d98a(&PTR_s_CMFCToolBar_00a005c4);
  in_ECX[0x27] = iVar2;
  iVar2 = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = param_1[8];
  }
  if (in_ECX[0x35] != iVar2) {
    iVar2 = 0;
    if (param_1 != (int *)0x0) {
      iVar2 = param_1[8];
    }
    in_ECX[0x35] = iVar2;
    CStringT<>();
    local_8 = 0;
    FUN_00792c64(local_14);
    FUN_00797ece(local_14[0]);
    LVar3 = SendMessageW((HWND)param_1[8],0x7f,0,0);
    SendMessageW((HWND)in_ECX[8],0x80,0,LVar3);
    LVar3 = SendMessageW((HWND)param_1[8],0x7f,1,0);
    SendMessageW((HWND)in_ECX[8],0x80,1,LVar3);
    FUN_0083ecce(param_1,1);
    pcVar1 = *(code **)(*param_1 + 0x1c8);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      if (((in_ECX[0x27] == 0) || (param_1[0x345] == 0)) || (param_1[0x2f2] == 0)) {
        uVar4 = 2;
      }
      else {
        uVar4 = 0x12;
      }
      pcVar1 = *(code **)(*in_ECX + 0x18c);
      guard_check_icall(uVar4);
      (*pcVar1)();
    }
    iVar2 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00);
    if ((iVar2 != 0) && (param_1[0x345] != 0)) {
      pcVar1 = *(code **)(*in_ECX + 0x18c);
      guard_check_icall(0x10);
      (*pcVar1)();
    }
    pcVar1 = *(code **)(*in_ECX + 500);
    guard_check_icall();
    (*pcVar1)();
    FUN_00406b10();
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[116], CPaneFrameWnd[116] */
/* 0083edb0  FUN_0083edb0  79 bytes, 0 callers */

void FUN_0083edb0(void)

{
  code *pcVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  int *in_ECX;
  
  pCVar2 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x35]);
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,(CObject *)pCVar2);
  if (pCVar3 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x210);
    guard_check_icall();
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x1b4);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[112], CPaneFrameWnd[112] */
/* 0083efa1  FUN_0083efa1  22 bytes, 0 callers */

void FUN_0083efa1(void)

{
  LPRECT in_stack_00000010;
  undefined4 *in_stack_00000014;
  
  *in_stack_00000014 = 0;
  SetRectEmpty(in_stack_00000010);
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[143], CMultiPaneFrameWnd[143], CPaneFrameWnd[143] */
/* 0083efb7  FUN_0083efb7  170 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0083efb7(int *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  pcVar1 = *(code **)(*in_ECX + 0x1bc);
  guard_check_icall(&local_18);
  (*pcVar1)();
  iVar3 = *param_1;
  iVar2 = FUN_0083f811();
  if (iVar3 <= iVar2) {
    iVar3 = FUN_0083f811();
  }
  local_18 = local_18 + local_10 + iVar3;
  *(int *)(param_2 + 0x18) = local_18;
  if (local_18 <= in_ECX[0x3a]) {
    local_18 = in_ECX[0x3a];
  }
  *(int *)(param_2 + 0x18) = local_18;
  local_14 = local_14 + in_ECX[0x2b] + param_1[1] + local_c;
  *(int *)(param_2 + 0x1c) = local_14;
  if (local_14 <= in_ECX[0x3b]) {
    local_14 = in_ECX[0x3b];
  }
  *(int *)(param_2 + 0x1c) = local_14;
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[93], CPaneFrameWnd[93] */
/* 0083f061  FUN_0083f061  70 bytes, 0 callers */

undefined4 FUN_0083f061(void)

{
  code *pcVar1;
  CObject *pCVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar1)();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,pCVar2);
  if (pCVar2 == (CObject *)0x0) {
    uVar3 = 0;
  }
  else {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x18c);
    guard_check_icall();
    uVar3 = (*pcVar1)();
  }
  return uVar3;
}




/* vtable slots: CMFCTasksPaneFrameWnd[89], CPaneFrameWnd[89] */
/* 0083f0a7  FUN_0083f0a7  59 bytes, 0 callers */

void FUN_0083f0a7(int *param_1)

{
  code *pcVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  int in_ECX;
  
  pCVar2 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)pCVar2);
  pcVar1 = *(code **)(*param_1 + 0x184);
  guard_check_icall(pCVar3);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[137], CPaneFrameWnd[137] */
/* 0083f0e2  FUN_0083f0e2  69 bytes, 0 callers */

void FUN_0083f0e2(void)

{
  code *pcVar1;
  int iVar2;
  CWnd *pCVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x220);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_00797f20(0);
    if ((HWND__ *)in_ECX[0x35] != (HWND__ *)0x0) {
      pCVar3 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x35]);
      if (pCVar3 != (CWnd *)0x0) {
        FUN_00797f20(0);
      }
    }
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[128], CPaneFrameWnd[128] */
/* 0083f127  FUN_0083f127  89 bytes, 0 callers */

void FUN_0083f127(void)

{
  code *pcVar1;
  CObject *pCVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1ac);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar1)();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar2);
  if (pCVar2 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x2e0);
    guard_check_icall(0);
    (*pcVar1)();
    PostMessageW((HWND)in_ECX[8],DAT_00a13b18,0,0);
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[129], CMultiPaneFrameWnd[129], CPaneFrameWnd[129] */
/* 0083f180  FUN_0083f180  29 bytes, 0 callers */

void FUN_0083f180(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0083f19d(0,param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[130], CMultiPaneFrameWnd[130], CPaneFrameWnd[130] */
/* 0083f19d  FUN_0083f19d  237 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_0083f19d(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4,CObject *param_5,
            undefined4 param_6)

{
  code *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  CObject *pCVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x83f1a9;
  local_14 = in_ECX;
  if (param_5 == (CObject *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar2 = FUN_00797acc();
    if ((uVar2 & 0x400000) != 0) {
      param_1 = param_1 | 0x400000;
    }
    uVar7 = *(undefined4 *)(param_5 + 0x20);
  }
  *(undefined4 *)(in_ECX + 200) = uVar7;
  FUN_007c2511();
  puVar3 = (undefined4 *)FUN_007e5eba(local_18,L"Afx:MiniFrame");
  local_8 = 0;
  iVar4 = FUN_007920d9(param_1,*puVar3,param_2,param_3 | 0x80000000,param_4,param_5,0,param_6);
  local_8 = 0xffffffff;
  FUN_00406b10();
  if (iVar4 == 0) {
LAB_0083f280:
    uVar7 = 0;
  }
  else {
    if (param_5 != (CObject *)0x0) {
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,param_5);
      if (pCVar5 == (CObject *)0x0) goto LAB_0083f280;
      piVar6 = *(int **)(in_ECX + 0x184);
      if (piVar6 == (int *)0x0) {
        piVar6 = (int *)FUN_0085a847(param_5);
        if (piVar6 == (int *)0x0) goto LAB_0083f280;
      }
      pcVar1 = *(code **)(*piVar6 + 0x1c);
      guard_check_icall(local_14);
      (*pcVar1)();
      in_ECX = local_14;
    }
    FUN_0085faab(in_ECX);
    uVar7 = 1;
  }
  return uVar7;
}




/* vtable slots: CMFCTasksPaneFrameWnd[97], CMultiPaneFrameWnd[97], CPaneFrameWnd[97] */
/* 0083f28a  FUN_0083f28a  722 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CObject * FUN_0083f28a(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  byte bVar3;
  CObject *pCVar4;
  int *piVar5;
  int iVar6;
  CObject *pCVar7;
  CWnd *pCVar8;
  int *piVar9;
  BOOL BVar10;
  int *in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  pCVar4 = (CObject *)(*pcVar1)();
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar4);
  *param_1 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x1b0);
  guard_check_icall();
  bVar3 = (*pcVar1)();
  piVar5 = (int *)in_ECX[0x61];
  if ((piVar5 != (int *)0x0) || (piVar5 = (int *)FUN_0085a847(in_ECX), piVar5 != (int *)0x0)) {
    iVar6 = piVar5[0x6e];
    if (((bVar3 & 1) != 0) &&
       ((((-1 < (char)bVar3 || (iVar6 == 0)) || (*(int *)(iVar6 + 8) == 0)) ||
        (*(int *)(iVar6 + 4) == 0)))) {
      if (in_ECX[0x62] == 1) {
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x2a0);
        guard_check_icall(in_ECX[0x4a]);
        iVar6 = (*pcVar1)();
        *param_1 = iVar6;
      }
      else if (((in_ECX[0x62] == 2) && ((CObject *)in_ECX[0x4a] != (CObject *)0x0)) &&
              ((pCVar7 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                            (CObject *)in_ECX[0x4a]), pCVar4 != (CObject *)0x0 &&
               (pCVar7 != (CObject *)0x0)))) {
        *param_1 = 1;
        iVar6 = in_ECX[0x61];
        if (iVar6 == 0) {
          pCVar8 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x32]);
          iVar6 = FUN_0085a847(pCVar8);
          if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
        }
        if (*(int *)(iVar6 + 0x1b8) != 0) {
          FUN_0086283a();
        }
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x34c);
        guard_check_icall(pCVar7,1,1,0);
        pCVar4 = (CObject *)(*pcVar1)();
        return pCVar4;
      }
      if (piVar5[0x6e] != 0) {
        FUN_0086283a();
      }
      in_ECX[0x62] = 0;
      return pCVar4;
    }
    if ((bVar3 & 0x82) != 0) {
      local_18.left = in_ECX[0x4e];
      local_18.top = in_ECX[0x4f];
      local_18.right = in_ECX[0x50];
      local_18.bottom = in_ECX[0x51];
      if (pCVar4 != (CObject *)0x0) {
        FUN_0085f9ad(1);
      }
      piVar9 = (int *)FUN_007e5618();
      uVar2 = DAT_00a13b30;
      DAT_00a13b30 = 1;
      pcVar1 = *(code **)(*in_ECX + 0x22c);
      guard_check_icall(param_1);
      pCVar4 = (CObject *)(*pcVar1)();
      DAT_00a13b30 = uVar2;
      if (piVar5[0x6e] != 0) {
        FUN_0086283a();
      }
      if (piVar9 != (int *)0x0) {
        pcVar1 = *(code **)(*piVar9 + 0x178);
        guard_check_icall(1);
        (*pcVar1)();
      }
      pcVar1 = *(code **)(*piVar5 + 0x38);
      guard_check_icall(0);
      (*pcVar1)();
      BVar10 = IsRectEmpty(&local_18);
      if (BVar10 != 0) {
        return pCVar4;
      }
      if (pCVar4 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x228);
        guard_check_icall(0);
        piVar5 = (int *)(*pcVar1)();
        if (piVar5 != in_ECX) {
          return pCVar4;
        }
      }
      if (*param_1 != 0) {
        return pCVar4;
      }
      FUN_00797e71(0,local_18.left,local_18.top,local_18.right - local_18.left,
                   local_18.bottom - local_18.top,0x104);
      BVar10 = IsWindowVisible((HWND)in_ECX[8]);
      if (BVar10 != 0) {
        return pCVar4;
      }
      pcVar1 = *(code **)(*in_ECX + 0x1a4);
      guard_check_icall();
      iVar6 = (*pcVar1)();
      if (iVar6 < 1) {
        return pCVar4;
      }
      FUN_00797f20(5);
      return pCVar4;
    }
  }
  return (CObject *)0x0;
}




/* vtable slots: CMFCTasksPaneFrameWnd[139], CPaneFrameWnd[139] */
/* 0083f55d  FUN_0083f55d  164 bytes, 0 callers */

CObject * FUN_0083f55d(undefined4 param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar1)();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar2);
  if (pCVar2 != (CObject *)0x0) {
    pcVar1 = *(code **)(*in_ECX + 0x19c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      BVar4 = IsWindowVisible(*(HWND *)(pCVar2 + 0x20));
      if (BVar4 == 0) {
        pcVar1 = *(code **)(*(int *)pCVar2 + 0x1b8);
        guard_check_icall();
        uVar5 = (*pcVar1)();
        if ((uVar5 & 2) != 0) {
          FUN_00797f20(5);
        }
      }
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x2b0);
      guard_check_icall(param_1);
      pCVar2 = (CObject *)(*pcVar1)();
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar2);
      return pCVar2;
    }
  }
  return (CObject *)0x0;
}




/* vtable slots: CMFCTasksPaneFrameWnd[132], CMultiPaneFrameWnd[132], CPaneFrameWnd[132] */
/* 0083f601  FUN_0083f601  215 bytes, 0 callers */

void FUN_0083f601(int param_1)

{
  code *pcVar1;
  char cVar2;
  HWND pHVar3;
  uint uVar4;
  HCURSOR hCursor;
  int *in_ECX;
  
  if (*(char *)((int)in_ECX + 0xa5) == '\0') {
    pHVar3 = SetCapture((HWND)in_ECX[8]);
    CWnd::FromHandle(pHVar3);
    if (in_ECX[0x33] == 0) {
      in_ECX[0x33] = param_1;
    }
    *(undefined1 *)((int)in_ECX + 0xa5) = 1;
    pcVar1 = *(code **)(*in_ECX + 0x20c);
    guard_check_icall(1);
    (*pcVar1)();
    GetCursorPos((LPPOINT)(in_ECX + 0x4c));
    pcVar1 = *(code **)(*in_ECX + 0x1b0);
    guard_check_icall();
    uVar4 = (*pcVar1)();
    if ((uVar4 & 1) != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x1b0);
      guard_check_icall();
      cVar2 = (*pcVar1)();
      if (-1 < cVar2) {
        FUN_0079dd6d();
        hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f86);
        SetCursor(hCursor);
      }
    }
    GetCursorPos((LPPOINT)(in_ECX + 0x40));
    if (in_ECX[0x61] == 0) {
      FUN_0085a847(in_ECX);
    }
    FUN_00848b24();
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[92], CMultiPaneFrameWnd[92], CPaneFrameWnd[92] */
/* 0083f880  FUN_0083f880  7 bytes, 0 callers */

undefined4 FUN_0083f880(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xac);
}




/* vtable slots: CMFCTasksPaneFrameWnd[114], CMultiPaneFrameWnd[114], CPaneFrameWnd[114] */
/* 0083f887  FUN_0083f887  195 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0083f887(int *param_1)

{
  code *pcVar1;
  int iVar2;
  CWnd *in_ECX;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  pcVar1 = *(code **)(*(int *)in_ECX + 0x1bc);
  guard_check_icall(&local_18);
  (*pcVar1)();
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_28);
  CWnd::ScreenToClient(in_ECX,&local_28);
  OffsetRect(&local_28,local_18.left,*(int *)(in_ECX + 0xac) + local_18.top);
  iVar2 = *(int *)(in_ECX + 0xac);
  *param_1 = local_28.left + local_18.left;
  param_1[1] = local_28.top + local_18.top;
  param_1[2] = local_28.right - local_18.right;
  param_1[3] = local_28.top + local_18.top + iVar2;
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[110], CPaneFrameWnd[110] */
/* 0083f94a  FUN_0083f94a  121 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_0083f94a(int *param_1)

{
  CWnd *pCVar1;
  int iVar2;
  int in_ECX;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x83f956;
  if (*(int *)(in_ECX + 0xd4) == 0) {
    CStringT<>(&DAT_00956338);
  }
  else {
    CStringT<>();
    local_8 = 0;
    pCVar1 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
    if (pCVar1 != (CWnd *)0x0) {
      FUN_00792c64(local_14);
    }
    iVar2 = FUN_004054a0(local_14[0] + -0x10);
    *param_1 = iVar2 + 0x10;
    FUN_00406b10();
  }
  return param_1;
}




/* vtable slots: CMFCTasksPaneFrameWnd[108], CMultiPaneFrameWnd[108], CPaneFrameWnd[108] */
/* 0083f9e2  FUN_0083f9e2  73 bytes, 0 callers */

undefined4 FUN_0083f9e2(void)

{
  code *pcVar1;
  CObject *pCVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar1)();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar2);
  uVar3 = DAT_00a00928;
  if (pCVar2 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x1b8);
    guard_check_icall();
    uVar3 = (*pcVar1)();
  }
  return uVar3;
}




/* vtable slots: CMFCTasksPaneFrameWnd[107], CPaneFrameWnd[107] */
/* 0083fa2b  FUN_0083fa2b  56 bytes, 0 callers */

undefined4 FUN_0083fa2b(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 1) {
    pcVar1 = *(code **)(*in_ECX + 0x1a8);
    guard_check_icall();
    uVar3 = (*pcVar1)();
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CMFCTasksPaneFrameWnd[106], CPaneFrameWnd[106] */
/* 0083fa69  FUN_0083fa69  12 bytes, 1 callers */

void FUN_0083fa69(void)

{
  int in_ECX;
  
  CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[104], CPaneFrameWnd[104] */
/* 0083fa75  GetPaneCount  18 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CPaneFrameWnd::GetPaneCount(void)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CPaneFrameWnd::GetPaneCount(CPaneFrameWnd *this)

{
  CWnd *pCVar1;
  
  pCVar1 = CWnd::FromHandlePermanent(*(HWND__ **)(this + 0xd4));
  return (uint)(pCVar1 != (CWnd *)0x0);
}




/* vtable slots: CMFCTasksPaneFrameWnd[105], CPaneFrameWnd[105] */
/* 0083fc5a  GetVisiblePaneCount  49 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CPaneFrameWnd::GetVisiblePaneCount(void)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CPaneFrameWnd::GetVisiblePaneCount(CPaneFrameWnd *this)

{
  BOOL BVar1;
  uint uVar2;
  
  BVar1 = IsWindow(*(HWND *)(this + 0xd4));
  if (BVar1 != 0) {
    uVar2 = GetWindowLongW(*(HWND *)(this + 0xd4),-0x10);
    if ((uVar2 & 0x10000000) != 0) {
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCTasksPaneFrameWnd[123], CMultiPaneFrameWnd[123], CPaneFrameWnd[123] */
/* 0083fc8b  FUN_0083fc8b  1229 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0083fc8b(LONG param_1,LONG param_2,int param_3)

{
  code *pcVar1;
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  POINT pt_06;
  POINT pt_07;
  POINT pt_08;
  POINT pt_09;
  POINT pt_10;
  POINT pt_11;
  POINT pt_12;
  POINT pt_13;
  POINT pt_14;
  bool bVar2;
  bool bVar3;
  int iVar4;
  BOOL BVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  CObject *pCVar10;
  CPaneFrameWnd *in_ECX;
  CWnd *local_6c;
  tagRECT local_68;
  RECT local_58;
  tagRECT local_48;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar4 = CPaneFrameWnd::IsCustModeAndNotFloatingToolbar(in_ECX);
  if (iVar4 == 0) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
    pt.y = param_2;
    pt.x = param_1;
    BVar5 = PtInRect(&local_18,pt);
    if (BVar5 != 0) {
      local_48.left = 0;
      local_48.top = 0;
      local_48.right = 0;
      local_48.bottom = 0;
      GetClientRect(*(HWND *)(in_ECX + 0x20),&local_48);
      FUN_0079e8b8(&local_48);
      pt_00.y = param_2;
      pt_00.x = param_1;
      BVar5 = PtInRect(&local_48,pt_00);
      if (BVar5 == 0) {
        local_38 = 0;
        local_34 = 0;
        pcVar1 = *(code **)(*(int *)in_ECX + 0x1bc);
        local_30 = 0;
        local_2c = 0;
        guard_check_icall(&local_38);
        (*pcVar1)();
        iVar4 = GetSystemMetrics(0xd);
        iVar4 = iVar4 / 2;
        iVar6 = GetSystemMetrics(0xe);
        local_58.left = local_38 + local_18.left;
        local_58.top = local_34 + local_18.top;
        local_58.right = local_18.right - local_30;
        iVar6 = iVar6 / 2;
        local_58.bottom = *(int *)(in_ECX + 0xac) + local_34 + local_18.top;
        pt_01.y = param_2;
        pt_01.x = param_1;
        BVar5 = PtInRect(&local_58,pt_01);
        if (BVar5 == 0) {
          bVar3 = true;
          local_6c = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
          bVar2 = true;
          if (local_6c != (CWnd *)0x0) {
            iVar9 = FUN_0079d98a(&PTR_s_CMFCToolBar_00a005c4);
            bVar3 = (bool)(~(iVar9 != 0) & 1);
            iVar9 = FUN_0079d98a(&PTR_s_CMFCColorBar_00a007bc);
            bVar2 = true;
            if ((iVar9 != 0) &&
               (pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorBar_00a007bc,
                                             (CObject *)local_6c), pCVar10 != (CObject *)0x0)) {
              bVar2 = (bool)(~(*(int *)(pCVar10 + 0xdf8) != 0) & 1);
            }
          }
          local_28.left = 0;
          local_28.top = 0;
          local_28.right = 0;
          local_28.bottom = 0;
          if (!bVar3) {
            SetRect(&local_28,local_18.left,local_18.top,local_18.right,local_34 + local_18.top);
            pt_11.y = param_2;
            pt_11.x = param_1;
            BVar5 = PtInRect(&local_28,pt_11);
            if (BVar5 == 0) {
              SetRect(&local_28,local_18.left,local_18.top,local_38 + local_18.left,local_18.bottom)
              ;
              pt_12.y = param_2;
              pt_12.x = param_1;
              BVar5 = PtInRect(&local_28,pt_12);
              if (BVar5 == 0) {
                SetRect(&local_28,local_18.left,local_18.bottom - local_2c,local_18.right,
                        local_18.bottom);
                pt_13.y = param_2;
                pt_13.x = param_1;
                BVar5 = PtInRect(&local_28,pt_13);
                if (BVar5 == 0) {
                  SetRect(&local_28,local_18.right - local_30,local_18.top,local_18.right,
                          local_18.bottom);
                  pt_14.y = param_2;
                  pt_14.x = param_1;
                  BVar5 = PtInRect(&local_28,pt_14);
                  if (BVar5 == 0) goto LAB_0084004a;
                  if (bVar2) {
                    return 0xb;
                  }
                }
                else if (bVar2) {
                  return 0xf;
                }
              }
              else if (bVar2) {
                return 10;
              }
            }
            else if (bVar2) {
              return 0xc;
            }
            return 0x12;
          }
          SetRect(&local_28,local_18.left,local_18.top,local_18.left + iVar4,local_18.top + iVar6);
          pt_03.y = param_2;
          pt_03.x = param_1;
          BVar5 = PtInRect(&local_28,pt_03);
          if (BVar5 != 0) {
            return 0xd;
          }
          SetRect(&local_28,local_18.left + iVar4,local_18.top,local_18.right - iVar4,
                  local_34 + local_18.top);
          pt_04.y = param_2;
          pt_04.x = param_1;
          BVar5 = PtInRect(&local_28,pt_04);
          if (BVar5 != 0) {
            return 0xc;
          }
          SetRect(&local_28,local_18.right - iVar4,local_18.top,local_18.right,local_18.top + iVar6)
          ;
          pt_05.y = param_2;
          pt_05.x = param_1;
          BVar5 = PtInRect(&local_28,pt_05);
          if (BVar5 != 0) {
            return 0xe;
          }
          SetRect(&local_28,local_18.right - local_30,local_18.top + iVar6,local_18.right,
                  local_18.bottom - iVar6);
          pt_06.y = param_2;
          pt_06.x = param_1;
          BVar5 = PtInRect(&local_28,pt_06);
          if (BVar5 != 0) {
            return 0xb;
          }
          SetRect(&local_28,local_18.right - iVar4,local_18.bottom - iVar6,local_18.right,
                  local_18.bottom);
          pt_07.y = param_2;
          pt_07.x = param_1;
          BVar5 = PtInRect(&local_28,pt_07);
          if (BVar5 != 0) {
            return 0x11;
          }
          SetRect(&local_28,local_18.left + iVar4,local_18.bottom - local_2c,local_18.right - iVar4,
                  local_18.bottom);
          pt_08.y = param_2;
          pt_08.x = param_1;
          BVar5 = PtInRect(&local_28,pt_08);
          if (BVar5 != 0) {
            return 0xf;
          }
          SetRect(&local_28,local_18.left,local_18.bottom - iVar6,local_18.left + iVar4,
                  local_18.bottom);
          pt_09.y = param_2;
          pt_09.x = param_1;
          BVar5 = PtInRect(&local_28,pt_09);
          if (BVar5 != 0) {
            return 0x10;
          }
          SetRect(&local_28,local_18.left,local_18.top + iVar6,local_38 + local_18.left,
                  local_18.bottom - iVar6);
          pt_10.y = param_2;
          pt_10.x = param_1;
          BVar5 = PtInRect(&local_28,pt_10);
          if (BVar5 != 0) {
            return 10;
          }
LAB_0084004a:
          uVar8 = FUN_007922d4();
          return uVar8;
        }
        if (param_3 != 0) {
          return 2;
        }
        local_6c = *(CWnd **)(in_ECX + 0x10c);
        while (local_6c != (CWnd *)0x0) {
          puVar7 = (undefined4 *)FUN_0044f2d0(&local_6c);
          pcVar1 = *(code **)(*(int *)*puVar7 + 0xc);
          guard_check_icall(&local_68);
          (*pcVar1)();
          OffsetRect(&local_68,local_58.left,local_58.top);
          pt_02.y = param_2;
          pt_02.x = param_1;
          BVar5 = PtInRect(&local_68,pt_02);
          if (BVar5 != 0) {
            uVar8 = FUN_008aee34();
            return uVar8;
          }
        }
      }
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCTasksPaneFrameWnd[90], CMultiPaneFrameWnd[90], CPaneFrameWnd[90] */
/* 00840185  FUN_00840185  138 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00840185(void)

{
  POINT Point;
  POINT pt;
  HWND pHVar1;
  CWnd *pCVar2;
  BOOL BVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  tagPOINT local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar5 = 0;
  local_20.x = 0;
  local_20.y = 0;
  GetCursorPos(&local_20);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
  Point.y = local_20.y;
  Point.x = local_20.x;
  pHVar1 = WindowFromPoint(Point);
  pCVar2 = CWnd::FromHandle(pHVar1);
  pt.y = local_20.y;
  pt.x = local_20.x;
  BVar3 = PtInRect(&local_18,pt);
  if (BVar3 != 0) {
    iVar4 = 0;
    if (pCVar2 != (CWnd *)0x0) {
      iVar4 = *(int *)(pCVar2 + 0x20);
    }
    if (iVar4 == *(int *)(in_ECX + 0x20)) {
      uVar5 = 1;
    }
  }
  return uVar5;
}




/* vtable slots: CMFCTasksPaneFrameWnd[91], CMultiPaneFrameWnd[91], CPaneFrameWnd[91] */
/* 0084020f  FUN_0084020f  108 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0084020f(void)

{
  POINT pt;
  BOOL BVar1;
  int in_ECX;
  undefined4 uVar2;
  tagPOINT local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar2 = 0;
  local_20.x = 0;
  local_20.y = 0;
  GetCursorPos(&local_20);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
  pt.y = local_20.y;
  pt.x = local_20.x;
  BVar1 = PtInRect(&local_18,pt);
  if ((BVar1 == 0) && (*(int *)(in_ECX + 0x94) == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCTasksPaneFrameWnd[118], CPaneFrameWnd[118] */
/* 008402db  FUN_008402db  74 bytes, 0 callers */

undefined4 FUN_008402db(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  int in_ECX;
  
  pCVar2 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,(CObject *)pCVar2);
  if (pCVar3 == (CObject *)0x0) {
    uVar4 = 1;
  }
  else {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x22c);
    guard_check_icall(param_1,param_2,0xffffffff);
    uVar4 = (*pcVar1)();
  }
  return uVar4;
}




/* vtable slots: CMFCTasksPaneFrameWnd[103], CMultiPaneFrameWnd[103], CPaneFrameWnd[103] */
/* 008403f5  FUN_008403f5  190 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008403f5(void)

{
  SHORT SVar1;
  CWnd *pCVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 local_28;
  tagPOINT local_24;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  SVar1 = GetKeyState(0x11);
  if (SVar1 < 0) {
LAB_008404a3:
    uVar5 = 0;
  }
  else {
    if (*(int *)(in_ECX + 0x184) == 0) {
      pCVar2 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 200));
      iVar3 = FUN_0085a847(pCVar2);
      if (iVar3 != 0) goto LAB_00840440;
    }
    else {
LAB_00840440:
      local_24.x = 0;
      local_24.y = 0;
      GetCursorPos(&local_24);
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      SetRectEmpty(&local_18);
      local_1c = 0;
      local_28 = 0;
      FUN_00846691(in_ECX,local_24.x,local_24.y,&local_18,&local_1c,&local_28);
      BVar4 = IsRectEmpty(&local_18);
      if ((BVar4 != 0) && (local_1c == 0)) goto LAB_008404a3;
    }
    uVar5 = 1;
  }
  return uVar5;
}




/* vtable slots: CMFCTasksPaneFrameWnd[131], CMultiPaneFrameWnd[131], CPaneFrameWnd[131] */
/* 0084064d  FUN_0084064d  160 bytes, 0 callers */

void FUN_0084064d(int param_1)

{
  code *pcVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  BOOL BVar4;
  int in_ECX;
  
  pCVar2 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)pCVar2);
  if (pCVar3 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x30c);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  BVar4 = IsWindow(*(HWND *)(in_ECX + 0xcc));
  if ((BVar4 != 0) && (param_1 == 0)) {
    DestroyWindow(*(HWND *)(in_ECX + 0xcc));
    *(undefined4 *)(in_ECX + 0xcc) = 0;
  }
  if ((pCVar3 != (CObject *)0x0) && (param_1 == 0)) {
    if (*(HWND *)(pCVar3 + 0x184) != *(HWND *)(in_ECX + 0x20)) {
      BVar4 = IsWindow(*(HWND *)(pCVar3 + 0x184));
      if (BVar4 != 0) {
        DestroyWindow(*(HWND *)(pCVar3 + 0x184));
      }
    }
    *(undefined4 *)(pCVar3 + 0x184) = 0;
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[144], CMultiPaneFrameWnd[144], CPaneFrameWnd[144] */
/* 008407f4  FUN_008407f4  299 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008407f4(void)

{
  code *pcVar1;
  CWnd *pCVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar3 = in_ECX[0x61];
  if (iVar3 == 0) {
    pCVar2 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x32]);
    iVar3 = FUN_0085a847(pCVar2);
  }
  if (*(int *)(iVar3 + 8) == 0) {
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect((HWND)in_ECX[8],&local_18);
    GetClientRect((HWND)in_ECX[8],&local_28);
    pcVar1 = *(code **)(*in_ECX + 0x168);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (in_ECX[0x24] != 0) {
      if (iVar3 == 0) {
        return;
      }
      local_18.bottom = in_ECX[0x2a] + local_18.top;
      FUN_00797e71(0,local_18.left,local_18.top,local_18.right - local_18.left,
                   local_18.bottom - local_18.top,0x14);
      in_ECX[0x24] = 0;
    }
    if (iVar4 != 0) {
      in_ECX[0x2a] = local_18.bottom - local_18.top;
      local_18.bottom = local_18.bottom + (local_28.top - local_28.bottom);
      FUN_00797e71(0,local_18.left,local_18.top,local_18.right - local_18.left,
                   local_18.bottom - local_18.top,0x14);
      in_ECX[0x24] = 1;
    }
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[136], CMultiPaneFrameWnd[136], CPaneFrameWnd[136] */
/* 0084093a  FUN_0084093a  164 bytes, 0 callers */

undefined4 FUN_0084093a(void)

{
  CObject *pCVar1;
  CObject *pCVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  pCVar1 = DAT_00a13a1c;
  if ((DAT_00a13a1c == (CObject *)0x0) &&
     (pCVar1 = (CObject *)FUN_00792b4c(), pCVar1 == (CObject *)0x0)) {
    return 1;
  }
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar1);
  if (pCVar2 == (CObject *)0x0) {
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWndEx_00994040,pCVar1);
    if (pCVar2 == (CObject *)0x0) {
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleIPFrameWndEx_00994be0,pCVar1);
      if ((pCVar2 == (CObject *)0x0) &&
         (pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleDocIPFrameWndEx_00994f98,pCVar1),
         pCVar2 == (CObject *)0x0)) {
        return 1;
      }
      pcVar4 = *(code **)(*(int *)pCVar2 + 0x20c);
    }
    else {
      pcVar4 = *(code **)(*(int *)pCVar2 + 500);
    }
  }
  else {
    pcVar4 = *(code **)(*(int *)pCVar2 + 0x214);
  }
  guard_check_icall();
  uVar3 = (*pcVar4)();
  return uVar3;
}




/* vtable slots: CMFCTasksPaneFrameWnd[102], CPaneFrameWnd[102] */
/* 00840c2d  FUN_00840c2d  163 bytes, 0 callers */

void FUN_00840c2d(void)

{
  code *pcVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  uint uVar4;
  int iVar5;
  int *in_ECX;
  int local_8;
  
  local_8 = in_ECX[0x61];
  if (local_8 == 0) {
    local_8 = FUN_0085a847(in_ECX);
  }
  pCVar2 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x35]);
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)pCVar2);
  if (pCVar3 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x198);
    guard_check_icall();
    uVar4 = (*pcVar1)();
    if ((uVar4 & 0xf000) != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x21c);
      guard_check_icall();
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x1f8);
      guard_check_icall(pCVar3,0,2);
      iVar5 = (*pcVar1)();
      if (iVar5 != 0) {
        FUN_0085a743(local_8,0,0);
      }
    }
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[126], CPaneFrameWnd[126] */
/* 00841028  FUN_00841028  82 bytes, 0 callers */

void FUN_00841028(void)

{
  code *pcVar1;
  CObject *pCVar2;
  uint uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar1)();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar2);
  if (pCVar2 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x1c4);
    guard_check_icall();
    uVar3 = (*pcVar1)();
    if ((uVar3 & 0x10) != 0) {
      return;
    }
  }
  FUN_0084029b();
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[101], CMultiPaneFrameWnd[101], CPaneFrameWnd[101] */
/* 00841f42  FUN_00841f42  90 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00841f42(undefined4 param_1,int param_2,int param_3)

{
  CWnd *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
  OffsetRect(&local_18,param_2,param_3);
  CWnd::MoveWindow(in_ECX,&local_18,1);
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[115], CPaneFrameWnd[115] */
/* 00842828  FUN_00842828  299 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00842828(void)

{
  code *pcVar1;
  CObject *pCVar2;
  CWnd *pCVar3;
  int *in_ECX;
  int local_28;
  int local_24;
  CObject *local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect((HWND)in_ECX[8],&local_18);
  pCVar3 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x35]);
  local_20 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)pCVar3);
  local_1c = 0;
  if (local_20 != (CObject *)0x0) {
    if (DAT_00a12770 != 0) {
      local_28 = 0;
      local_24 = 0;
      pcVar1 = *(code **)(*(int *)local_20 + 0x270);
      guard_check_icall(&local_28);
      (*pcVar1)();
      if (local_18.right - local_18.left < local_28) {
        local_18.right = local_18.left + local_28;
        local_1c = 1;
      }
      if (local_18.bottom - local_18.top < local_24) {
        local_18.bottom = local_18.top + local_24;
        local_1c = 1;
      }
    }
    pcVar1 = *(code **)(*(int *)local_20 + 0x238);
    guard_check_icall(0,local_18.left,local_18.top,local_18.right - local_18.left,
                      local_18.bottom - local_18.top,0x34,0);
    pCVar2 = local_20;
    (*pcVar1)();
    RedrawWindow(*(HWND *)(pCVar2 + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
    if (local_1c != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x1b4);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[125], CPaneFrameWnd[125] */
/* 00842ebd  FUN_00842ebd  82 bytes, 0 callers */

void FUN_00842ebd(void)

{
  code *pcVar1;
  CObject *pCVar2;
  uint uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar1)();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar2);
  if (pCVar2 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x1c4);
    guard_check_icall();
    uVar3 = (*pcVar1)();
    if ((uVar3 & 0x10) != 0) {
      FUN_00844224();
      return;
    }
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[113], CPaneFrameWnd[113] */
/* 008434d7  PaneFromPoint  133 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    public: virtual class CBasePane * __thiscall CPaneFrameWnd::PaneFromPoint(class CPoint,int,int)
   
   Library: Visual Studio 2012 Release */

CBasePane * __thiscall
CPaneFrameWnd::PaneFromPoint
          (CPaneFrameWnd *this,LONG param_2,LONG param_3,undefined4 param_4,int param_5)

{
  POINT pt;
  CWnd *pCVar1;
  CObject *pCVar2;
  BOOL BVar3;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pCVar1 = CWnd::FromHandlePermanent(*(HWND__ **)(this + 0xd4));
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)pCVar1);
  if (pCVar2 != (CObject *)0x0) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(pCVar2 + 0x20),&local_18);
    pt.y = param_3;
    pt.x = param_2;
    BVar3 = PtInRect(&local_18,pt);
    if (BVar3 != 0) {
      BVar3 = IsWindowVisible(*(HWND *)(pCVar2 + 0x20));
      if (BVar3 != 0) {
        return (CBasePane *)pCVar2;
      }
      if (param_5 == 0) {
        return (CBasePane *)pCVar2;
      }
    }
  }
  return (CBasePane *)0x0;
}




/* vtable slots: CMFCTasksPaneFrameWnd[25], CMultiPaneFrameWnd[25], CPaneFrameWnd[25] */
/* 0084355c  PreCreateWindow  23 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CPaneFrameWnd::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall CPaneFrameWnd::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Library: Visual Studio 2015 Release */

void PreCreateWindow(int param_1)

{
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x100;
  PreCreateWindow(param_1);
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[67], CMultiPaneFrameWnd[67], CPaneFrameWnd[67] */
/* 00843573  FUN_00843573  151 bytes, 0 callers */

void FUN_00843573(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 < 0x105) {
    if (((uVar1 != 0x104) && (uVar1 != 0xa1)) &&
       ((uVar1 != 0xa2 &&
        ((((uVar1 != 0xa4 && (uVar1 != 0xa5)) && (uVar1 != 0xa7)) &&
         ((uVar1 != 0xa8 && (uVar1 != 0x100)))))))) goto LAB_008435fc;
  }
  else if ((((uVar1 != 0x200) && (uVar1 != 0x201)) && (uVar1 != 0x202)) &&
          (((uVar1 != 0x204 && (uVar1 != 0x205)) && ((uVar1 != 0x207 && (uVar1 != 0x208))))))
  goto LAB_008435fc;
  iVar2 = *(int *)(in_ECX + 0x124);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x20) != 0)) {
    SendMessageW(*(HWND *)(iVar2 + 0x20),0x407,0,param_1);
  }
LAB_008435fc:
  FUN_007949fb(param_1);
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[145], CMultiPaneFrameWnd[145], CPaneFrameWnd[145] */
/* 0084360a  FUN_0084360a  80 bytes, 1 callers */

void FUN_0084360a(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined1 local_c [8];
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x144);
  guard_check_icall(local_c);
  iVar3 = (*pcVar1)();
  iVar4 = GetSystemMetrics(0x33);
  iVar4 = iVar4 + *(int *)(iVar3 + 4);
  *(int *)(in_ECX + 0xac) = iVar4;
  iVar4 = iVar4 + 0xf;
  *(int *)(in_ECX + 0xec) = iVar4;
  *(int *)(in_ECX + 0xe8) = iVar4;
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[124], CPaneFrameWnd[124] */
/* 00843752  FUN_00843752  143 bytes, 0 callers */

void FUN_00843752(void)

{
  code *pcVar1;
  CObject *pCVar2;
  BOOL BVar3;
  int iVar4;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  pCVar2 = (CObject *)(*pcVar1)();
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_DAT_0097c53c,pCVar2);
  if ((pCVar2 != (CObject *)0x0) && (BVar3 = IsWindow(*(HWND *)(pCVar2 + 0x20)), BVar3 != 0)) {
    iVar4 = FUN_00797a2b();
    if (iVar4 != -1) {
      return;
    }
    pcVar1 = *(code **)(*in_ECX + 0x1a8);
    guard_check_icall();
    pCVar2 = (CObject *)(*pcVar1)();
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,pCVar2);
    if (pCVar2 != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x3a4);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 != 0) {
        return;
      }
    }
  }
  in_ECX[0x35] = 0;
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[95], CPaneFrameWnd[95] */
/* 008437e1  FUN_008437e1  161 bytes, 1 callers */

void FUN_008437e1(int *param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  in_ECX[0x26] = param_3;
  FUN_0083ecce(param_1,0);
  pcVar1 = *(code **)(*param_1 + 0x218);
  guard_check_icall();
  (*pcVar1)();
  if (in_ECX[0x35] == param_1[8]) {
    in_ECX[0x35] = 0;
  }
  pcVar1 = *(code **)(*in_ECX + 0x1f8);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1a0);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if (param_2 == 0) {
      PostMessageW((HWND)in_ECX[8],DAT_00a13b18,0,0);
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x60);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[96], CPaneFrameWnd[96] */
/* 00843882  FUN_00843882  94 bytes, 1 callers */

void FUN_00843882(int param_1,int param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (((param_1 != 0) && (param_2 != 0)) && (param_1 != param_2)) {
    FUN_0083ecce(param_1,0);
    if (*(int *)(param_1 + 0x20) == in_ECX[0x35]) {
      in_ECX[0x35] = *(int *)(param_2 + 0x20);
    }
    FUN_0083ecce(param_2,1);
    pcVar1 = *(code **)(*in_ECX + 500);
    guard_check_icall();
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCTasksPaneFrameWnd[135], CPaneFrameWnd[135] */
/* 008438e1  FUN_008438e1  131 bytes, 0 callers */

void FUN_008438e1(void)

{
  LONG LVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  int in_ECX;
  tagPOINT local_c;
  
  local_c.y = in_ECX + 0xd8;
  GetWindowRect(*(HWND *)(in_ECX + 0x20),(LPRECT)local_c.y);
  if (*(HWND__ **)(in_ECX + 0xd4) != (HWND__ *)0x0) {
    pCVar2 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)pCVar2);
    LVar1 = local_c.y;
    if (pCVar3 != (CObject *)0x0) {
      local_c.x = 0;
      local_c.y = 0;
      *(LONG *)(pCVar3 + 0x1e8) = *(LONG *)LVar1;
      *(LONG *)(pCVar3 + 0x1ec) = *(LONG *)(LVar1 + 4);
      *(LONG *)(pCVar3 + 0x1f0) = *(LONG *)(LVar1 + 8);
      *(LONG *)(pCVar3 + 500) = *(LONG *)(LVar1 + 0xc);
      GetCursorPos(&local_c);
      ScreenToClient(*(HWND *)(pCVar3 + 0x20),&local_c);
      *(LONG *)(pCVar3 + 0x168) = local_c.x;
      *(LONG *)(pCVar3 + 0x16c) = local_c.y;
    }
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[117], CPaneFrameWnd[117] */
/* 00843964  FUN_00843964  74 bytes, 0 callers */

undefined4 FUN_00843964(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  int in_ECX;
  
  pCVar2 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,(CObject *)pCVar2);
  if (pCVar3 == (CObject *)0x0) {
    uVar4 = 1;
  }
  else {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x230);
    guard_check_icall(param_1,param_2,0xffffffff);
    uVar4 = (*pcVar1)();
  }
  return uVar4;
}




/* vtable slots: CMFCTasksPaneFrameWnd[2], CPaneFrameWnd[2] */
/* 008439ae  FUN_008439ae  418 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008439ae(CArchive *param_1)

{
  code *pcVar1;
  CArchive *this;
  int iVar2;
  BOOL BVar3;
  long lVar4;
  CWnd *pCVar5;
  int *in_ECX;
  CArchive *pCVar6;
  int local_3c;
  CArchive *local_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x8439ba;
  pCVar6 = (CArchive *)0x0;
  local_38 = param_1;
  if (((byte)param_1[0x18] & 1) == 0) {
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetWindowRect((HWND)in_ECX[8],&local_24);
    if (in_ECX[0x24] != 0) {
      local_24.bottom = in_ECX[0x2a] + local_24.top;
    }
    BVar3 = IsWindowVisible((HWND)in_ECX[8]);
    lVar4 = FUN_00797b3d();
    CArchive::operator<<(local_38,lVar4);
    FUN_007a6b47(&local_24,0x10);
    this = local_38;
    CArchive::operator<<(local_38,BVar3);
    pCVar5 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x35]);
    if (pCVar5 != (CWnd *)0x0) {
      pCVar6 = (CArchive *)FUN_00797a2b();
    }
    CArchive::operator<<(this,(long)pCVar6);
    CArchive::operator<<(this,in_ECX[0x31]);
    CArchive::operator<<(this,in_ECX[0x25]);
  }
  else {
    local_38 = (CArchive *)0x0;
    local_34.left = 0;
    local_34.top = 0;
    local_34.right = 0;
    local_34.bottom = 0;
    SetRectEmpty(&local_34);
    CArchive::operator>>(param_1,(long *)&local_38);
    CArchive::EnsureRead(param_1,&local_34,0x10);
    CArchive::operator>>(param_1,&local_3c);
    CArchive::operator>>(param_1,in_ECX + 0x30);
    CArchive::operator>>(param_1,in_ECX + 0x31);
    CArchive::operator>>(param_1,in_ECX + 0x25);
    pcVar1 = *(code **)(*in_ECX + 0x204);
    guard_check_icall(&DAT_00956338,(uint)local_38 & 0xefffffff,&local_34,DAT_00a13b14,0);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      local_3c = FUN_004121b0(0x10);
      local_8 = 0;
      if (local_3c != 0) {
        pCVar6 = (CArchive *)FUN_007a563a(0,0);
      }
      local_8 = 0xffffffff;
      local_38 = pCVar6;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_38,&DAT_009eb3ec);
    }
    in_ECX[0x32] = *(int *)(DAT_00a13b14 + 0x20);
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[119], CPaneFrameWnd[119] */
/* 00843d2a  FUN_00843d2a  891 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00843d2a(int *param_1)

{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  BOOL BVar5;
  HWND pHVar6;
  CWnd *pCVar7;
  CWnd *pCVar8;
  int iVar9;
  CObject *pCVar10;
  int *in_ECX;
  undefined4 uVar11;
  undefined1 local_30 [4];
  int *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = in_ECX;
  if (in_ECX[0x30] != 0) {
    pcVar1 = *(code **)(*param_1 + 0x24);
    guard_check_icall(in_ECX[0x30],1);
    piVar3 = (int *)(*pcVar1)();
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 0x1cc);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if ((iVar4 != 0) && (BVar5 = IsWindow((HWND)piVar3[8]), BVar5 != 0)) {
        pcVar1 = *(code **)(*piVar3 + 0x16c);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 != 0) {
          pHVar6 = GetParent((HWND)piVar3[8]);
          pCVar7 = CWnd::FromHandle(pHVar6);
          pHVar6 = GetParent(*(HWND *)(pCVar7 + 0x20));
          pCVar7 = CWnd::FromHandle(pHVar6);
          pCVar8 = CWnd::FromHandlePermanent((HWND__ *)in_ECX[0x32]);
          if (pCVar8 == (CWnd *)0x0) {
            pHVar6 = (HWND)0x0;
          }
          else {
            pHVar6 = *(HWND *)(pCVar8 + 0x20);
          }
          pHVar6 = SetParent((HWND)piVar3[8],pHVar6);
          CWnd::FromHandle(pHVar6);
          pcVar1 = *(code **)(*(int *)pCVar7 + 0x3c0);
          guard_check_icall(piVar3);
          (*pcVar1)();
          iVar4 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
          if (iVar4 != 0) {
            pcVar1 = *(code **)(*piVar3 + 0x1f0);
            guard_check_icall(1);
            (*pcVar1)();
          }
          FUN_00797f20(5);
        }
        iVar4 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
        if (iVar4 != 0) {
          pcVar1 = *(code **)(*piVar3 + 0x1dc);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          if (iVar4 != 0) {
            pcVar1 = *(code **)(*piVar3 + 0x368);
            guard_check_icall(0,0xf000,0,1);
            (*pcVar1)();
          }
        }
        local_28.left = 0;
        local_28.top = 0;
        local_28.right = 0;
        local_28.bottom = 0;
        GetWindowRect((HWND)piVar3[8],&local_28);
        pcVar1 = *(code **)(*piVar3 + 0x228);
        guard_check_icall(0);
        iVar4 = (*pcVar1)();
        if (iVar4 == 0) {
          pcVar1 = *(code **)(*piVar3 + 0x1fc);
          guard_check_icall(local_28.left,local_28.top,local_28.right,local_28.bottom,3,0);
          (*pcVar1)();
          in_ECX = local_2c;
        }
        pcVar1 = *(code **)(*piVar3 + 0x228);
        guard_check_icall(0);
        local_2c = (int *)(*pcVar1)();
        if (local_2c != (int *)0x0) {
          pcVar1 = *(code **)(*local_2c + 0x17c);
          guard_check_icall(piVar3,0,0);
          (*pcVar1)();
          pHVar6 = SetParent((HWND)piVar3[8],(HWND)in_ECX[8]);
          CWnd::FromHandle(pHVar6);
          pcVar1 = *(code **)(*piVar3 + 0x268);
          guard_check_icall(0);
          (*pcVar1)();
          local_18.left = 0;
          local_18.top = 0;
          local_18.right = 0;
          local_18.bottom = 0;
          GetClientRect((HWND)in_ECX[8],&local_18);
          pcVar1 = *(code **)(*in_ECX + 0x178);
          guard_check_icall(piVar3);
          (*pcVar1)();
          pcVar1 = *(code **)(*piVar3 + 0x238);
          guard_check_icall(&DAT_00a11c68,0,0,0,0,0x11,0);
          (*pcVar1)();
          pcVar1 = *(code **)(*piVar3 + 0x208);
          guard_check_icall(local_30,local_18.bottom - local_18.top,1);
          (*pcVar1)();
          pcVar1 = *(code **)(*piVar3 + 0x210);
          guard_check_icall();
          (*pcVar1)();
          pcVar1 = *(code **)(*in_ECX + 0x1b4);
          guard_check_icall();
          (*pcVar1)();
          FUN_00797e71(0,0,0,0,0,0x37);
          pcVar1 = *(code **)(*piVar3 + 0x1ac);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          iVar9 = FUN_0079dd6d();
          pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CWinAppEx_0098fd18,
                                       *(CObject **)(iVar9 + 4));
          if ((pCVar10 == (CObject *)0x0) || (*(int *)(pCVar10 + 0xd0) == 0)) {
            bVar2 = false;
            uVar11 = 1;
          }
          else {
            bVar2 = true;
            uVar11 = 0;
          }
          if ((iVar4 != 0) && (!bVar2)) {
            in_ECX[0x28] = 1;
          }
          pcVar1 = *(code **)(*piVar3 + 0x224);
          guard_check_icall(iVar4,uVar11,0);
          (*pcVar1)();
          pcVar1 = *(code **)(*in_ECX + 0x18c);
          guard_check_icall(in_ECX[0x31]);
          (*pcVar1)();
          return;
        }
      }
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x60);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[100], CPaneFrameWnd[100] */
/* 008440d7  FUN_008440d7  333 bytes, 0 callers */

undefined4 FUN_008440d7(int param_1,CObject *param_2)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  tagPOINT local_1c;
  tagPOINT local_14;
  undefined4 local_c;
  char local_5;
  
  if (param_1 == 0) {
LAB_0084421a:
    uVar5 = 1;
  }
  else {
    if (param_1 == 2) {
      if (param_2 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)param_2 + 0x18c);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) goto LAB_0084421a;
        goto LAB_00844115;
      }
    }
    else {
LAB_00844115:
      if (param_2 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)param_2 + 0x228);
        guard_check_icall(0);
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) goto LAB_0084421a;
      }
    }
    local_5 = *(char *)((int)in_ECX + 0xa5);
    if (local_5 != '\0') {
      ReleaseCapture();
      *(undefined1 *)((int)in_ECX + 0xa5) = 0;
      pcVar1 = *(code **)(*in_ECX + 0x20c);
      guard_check_icall(0);
      (*pcVar1)();
    }
    local_14.x = 0;
    local_14.y = 0;
    GetCursorPos(&local_14);
    local_1c.x = local_14.x;
    local_1c.y = local_14.y;
    pcVar1 = *(code **)(*in_ECX + 0x1a8);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    ScreenToClient(*(HWND *)(iVar2 + 0x20),&local_1c);
    in_ECX[0x62] = param_1;
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,param_2);
    local_c = 0;
    in_ECX[0x4a] = (int)pCVar3;
    pcVar1 = *(code **)(*in_ECX + 0x184);
    guard_check_icall(&local_c);
    piVar4 = (int *)(*pcVar1)();
    if (piVar4 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar4 + 0x268);
      guard_check_icall(0);
      (*pcVar1)();
      if (local_5 != '\0') {
        pcVar1 = *(code **)(*piVar4 + 0x314);
        guard_check_icall(0);
        (*pcVar1)();
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}




/* vtable slots: CMFCTasksPaneFrameWnd[109], CMultiPaneFrameWnd[109], CPaneFrameWnd[109] */
/* 0084426e  FUN_0084426e  190 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0084426e(void)

{
  code *pcVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  int in_ECX;
  int local_30;
  int local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pCVar2 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0xd4));
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)pCVar2);
  if (pCVar3 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x260);
    guard_check_icall(&local_30,0,1);
    (*pcVar1)();
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    GetClientRect(*(HWND *)(in_ECX + 0x20),&local_28);
    FUN_00797e71(0,0,0,((local_18.right - local_28.right) - local_18.left) + local_28.left +
                       local_30,
                 ((local_28.top - local_28.bottom) - local_18.top) + local_18.bottom + local_2c,0x16
                );
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[1] */
/* 008b1254  FUN_008b1254  57 bytes, 0 callers */

void FUN_008b1254(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCTasksPaneFrameWnd::vftable;
  FUN_0083e9c7();
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




/* vtable slots: CMFCTasksPaneFrameWnd[140] */
/* 008b128d  AddButton  205 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual void __thiscall CMFCTasksPaneFrameWnd::AddButton(unsigned int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCTasksPaneFrameWnd::AddButton(CMFCTasksPaneFrameWnd *this,uint param_1)

{
  int iVar1;
  CObject *pCVar2;
  
  iVar1 = FUN_0083f6d8(param_1);
  if (iVar1 == 0) {
    if (param_1 == 0x17) {
      iVar1 = FUN_0078e624(0x30);
      pCVar2 = (CObject *)0x0;
      if (iVar1 != 0) {
        pCVar2 = (CObject *)FUN_008aed24(0x17,1);
      }
    }
    else if (param_1 == 0x18) {
      iVar1 = FUN_0078e624(0x30);
      if (iVar1 == 0) {
        pCVar2 = (CObject *)0x0;
      }
      else {
        pCVar2 = (CObject *)FUN_008aed24(0x18,1);
      }
    }
    else {
      if (param_1 != 0x19) {
        CPaneFrameWnd::AddButton((CPaneFrameWnd *)this,param_1);
        return;
      }
      iVar1 = FUN_0078e624(0x3c);
      if (iVar1 == 0) {
        pCVar2 = (CObject *)0x0;
      }
      else {
        pCVar2 = (CObject *)FUN_008b911f();
      }
      *(undefined4 *)(pCVar2 + 0x34) = 0;
      *(undefined4 *)(pCVar2 + 0x1c) = 0x19;
    }
    CObList::AddHead((CObList *)(this + 0x108),pCVar2);
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[111] */
/* 008b135a  FUN_008b135a  25 bytes, 0 callers */

void FUN_008b135a(LPRECT param_1)

{
  SetRect(param_1,3,3,3,3);
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[10] */
/* 008b1373  FUN_008b1373  6 bytes, 0 callers */

undefined ** FUN_008b1373(void)

{
  return &PTR_FUN_009a0be8;
}




/* vtable slots: CMFCTasksPaneFrameWnd[0] */
/* 008b1379  FUN_008b1379  6 bytes, 0 callers */

undefined ** FUN_008b1379(void)

{
  return &PTR_s_CMFCTasksPaneFrameWnd_00a00c90;
}




/* vtable slots: CMFCTasksPaneFrameWnd[133] */
/* 008b137f  FUN_008b137f  9 bytes, 0 callers */

void FUN_008b137f(void)

{
  FUN_00840cd0();
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[134] */
/* 008b1388  FUN_008b1388  120 bytes, 0 callers */

int FUN_008b1388(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  byte bVar4;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x10c);
  iVar3 = 0;
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    bVar4 = 1;
    piVar1 = (int *)*puVar2;
    iVar3 = FUN_008aee34();
    if (iVar3 == 9) {
      bVar4 = ~-(*(int *)(in_ECX + 0x94) != 0) & 1;
    }
    iVar3 = *piVar1;
    guard_check_icall(param_1,0,1,bVar4,0);
    (**(code **)(iVar3 + 0x10))();
    iVar3 = in_ECX + 0x108;
  }
  return iVar3;
}




/* vtable slots: CMFCTasksPaneFrameWnd[138] */
/* 008b15d2  FUN_008b15d2  166 bytes, 0 callers */

void FUN_008b15d2(int param_1)

{
  CObject *pCVar1;
  int iVar2;
  int *in_ECX;
  code *pcVar3;
  
  pcVar3 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  pCVar1 = (CObject *)(*pcVar3)();
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTasksPane_00a00d6c,pCVar1);
  if (pCVar1 != (CObject *)0x0) {
    if (param_1 == 0x17) {
      pcVar3 = *(code **)(*(int *)pCVar1 + 0x3a0);
    }
    else {
      if (param_1 != 0x18) {
        if (param_1 == 0x19) {
          iVar2 = FUN_0083f6d8(0x19);
          if (iVar2 != 0) {
            in_ECX[100] = 1;
            pcVar3 = *(code **)(*(int *)pCVar1 + 0x3ac);
            guard_check_icall(iVar2);
            (*pcVar3)();
            in_ECX[100] = 0;
          }
        }
        goto LAB_008b1667;
      }
      pcVar3 = *(code **)(*(int *)pCVar1 + 0x3a4);
    }
    guard_check_icall();
    (*pcVar3)();
  }
LAB_008b1667:
  FUN_00842953(param_1);
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[141] */
/* 008b1678  FUN_008b1678  27 bytes, 0 callers */

void FUN_008b1678(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 400) == 0) {
    FUN_008432d0(param_1,param_2);
  }
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[99] */
/* 008b1693  FUN_008b1693  277 bytes, 0 callers */

void FUN_008b1693(uint param_1)

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
  pcVar1 = *(code **)(*in_ECX + 0x230);
  guard_check_icall(0x17);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x230);
  guard_check_icall(0x18);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x230);
  guard_check_icall(0x19);
  (*pcVar1)();
  in_ECX[0x31] = param_1 | 0x70;
  FUN_00843c3c();
  FUN_0083ee42();
  SendMessageW((HWND)in_ECX[8],0x85,0,0);
  return;
}




/* vtable slots: CMFCTasksPaneFrameWnd[142] */
/* 008b17a8  FUN_008b17a8  14 bytes, 0 callers */

void FUN_008b17a8(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 400) != 0) {
    return;
  }
  if (*(int *)(in_ECX + 0xb0) != 0) {
    iVar1 = FUN_0083f6d8(*(int *)(in_ECX + 0xb0));
    *(undefined4 *)(in_ECX + 0xb0) = 0;
    ReleaseCapture();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 4) = 0;
      FUN_0084368c(iVar1);
    }
  }
  if (*(int *)(in_ECX + 0xb4) != 0) {
    iVar1 = FUN_0083f6d8(*(int *)(in_ECX + 0xb4));
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    ReleaseCapture();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 8) = 0;
      FUN_0084368c(iVar1);
    }
  }
  return;
}



