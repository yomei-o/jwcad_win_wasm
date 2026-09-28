/* CMFCBaseTabCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCBaseTabCtrl[179], CMFCOutlookBarTabCtrl[179], CMFCTabCtrl[179] */
/* 007c22a4  FUN_007c22a4  7 bytes, 0 callers */

undefined4 FUN_007c22a4(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x124);
}




/* vtable slots: CMFCBaseTabCtrl[140], CMFCOutlookBarTabCtrl[140], CMFCTabCtrl[140] */
/* 007c23ac  FUN_007c23ac  20 bytes, 0 callers */

int FUN_007c23ac(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x13c);
  if (iVar1 == -1) {
    iVar1 = FUN_007c2511();
    iVar1 = *(int *)(iVar1 + 0x6c);
  }
  return iVar1;
}




/* vtable slots: CMFCBaseTabCtrl[141], CMFCOutlookBarTabCtrl[141], CMFCTabCtrl[141] */
/* 007c23c0  FUN_007c23c0  20 bytes, 0 callers */

int FUN_007c23c0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x140);
  if (iVar1 == -1) {
    iVar1 = FUN_007c2511();
    iVar1 = *(int *)(iVar1 + 0x70);
  }
  return iVar1;
}




/* vtable slots: CMFCBaseTabCtrl[143], CMFCOutlookBarTabCtrl[143], CMFCTabCtrl[143] */
/* 007c2535  GetImageList  36 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CImageList const * __thiscall CMFCBaseTabCtrl::GetImageList(void)const 
   
   Library: Visual Studio 2015 Release */

CImageList * __thiscall CMFCBaseTabCtrl::GetImageList(CMFCBaseTabCtrl *this)

{
  CImageList *pCVar1;
  
  pCVar1 = (CImageList *)(this + 200);
  if ((pCVar1 == (CImageList *)0x0) || (*(int *)(this + 0xcc) == 0)) {
    if (*(_IMAGELIST **)(this + 0xd0) != (_IMAGELIST *)0x0) {
      pCVar1 = CImageList::FromHandle(*(_IMAGELIST **)(this + 0xd0));
      return pCVar1;
    }
    pCVar1 = (CImageList *)0x0;
  }
  return pCVar1;
}




/* vtable slots: CMFCBaseTabCtrl[142], CMFCOutlookBarTabCtrl[142], CMFCTabCtrl[142] */
/* 007c2559  FUN_007c2559  27 bytes, 0 callers */

void FUN_007c2559(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xd8);
  *param_1 = *(undefined4 *)(in_ECX + 0xd4);
  param_1[1] = uVar1;
  return;
}




/* vtable slots: CMFCBaseTabCtrl[146], CMFCOutlookBarTabCtrl[146], CMFCTabCtrl[146] */
/* 007c26be  FUN_007c26be  41 bytes, 0 callers */

int FUN_007c26be(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x17c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = in_ECX[0x43];
  }
  return iVar2;
}




/* vtable slots: CMFCBaseTabCtrl[168], CMFCOutlookBarTabCtrl[168], CMFCTabCtrl[168] */
/* 007c2772  FUN_007c2772  7 bytes, 0 callers */

undefined4 FUN_007c2772(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 300);
}




/* vtable slots: CMFCBaseTabCtrl[166], CMFCOutlookBarTabCtrl[166], CMFCTabCtrl[166] */
/* 007c2799  FUN_007c2799  7 bytes, 0 callers */

undefined4 FUN_007c2799(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x154);
}




/* vtable slots: CMFCBaseTabCtrl[1] */
/* 0080738b  FUN_0080738b  51 bytes, 0 callers */

void FUN_0080738b(byte param_1)

{
  FUN_00807190();
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




/* vtable slots: CMFCBaseTabCtrl[98], CMFCOutlookBarTabCtrl[98], CMFCTabCtrl[98] */
/* 00807445  FUN_00807445  133 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00807445(undefined4 param_1,HINSTANCE param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  UINT in_stack_ffffffdc;
  LPSTR in_stack_ffffffe0;
  int in_stack_ffffffe4;
  undefined4 local_14;
  
  iVar2 = FUN_00797a2b();
  if (iVar2 != -1) {
    CStringT<>();
    iVar2 = FID_conflict_LoadStringA(param_2,in_stack_ffffffdc,in_stack_ffffffe0,in_stack_ffffffe4);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    pcVar1 = *(code **)(*in_ECX + 0x2c4);
    guard_check_icall(param_1,local_14,param_4);
    uVar3 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x18c);
    guard_check_icall(uVar3,local_14,param_3,param_4);
    (*pcVar1)();
    FUN_00406b10();
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[99], CMFCOutlookBarTabCtrl[99], CMFCTabCtrl[99] */
/* 008074cb  FUN_008074cb  99 bytes, 0 callers */

void FUN_008074cb(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) && (iVar2 = FUN_00797a2b(), iVar2 == -1))
  {
    return;
  }
  pcVar1 = *(code **)(*in_ECX + 0x2c4);
  guard_check_icall(param_1,param_2,param_4);
  uVar3 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x194);
  guard_check_icall(uVar3,param_2,0xffffffff,param_3,param_4);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCBaseTabCtrl[148], CMFCOutlookBarTabCtrl[148], CMFCTabCtrl[148] */
/* 0080757e  FUN_0080757e  974 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0080757e(int param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  int iVar7;
  HWND pHVar8;
  CWnd *pCVar9;
  CObject *pCVar10;
  int *in_ECX;
  undefined4 *puVar11;
  int *piVar12;
  CSimpleStringT<wchar_t,0> local_38 [4];
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  CWnd *local_20;
  CWnd *local_1c;
  undefined4 *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x80758a;
  uVar4 = FUN_007e5618();
  pCVar5 = (CWnd *)FUN_0085a847(uVar4);
  puVar11 = (undefined4 *)in_ECX[0x5b];
  piVar12 = (int *)0x0;
  local_1c = pCVar5;
  if (puVar11 != (undefined4 *)0x0) {
    do {
      puVar1 = (undefined4 *)*puVar11;
      local_18 = puVar1;
      FUN_00806fc4(puVar11 + 2);
      local_8 = 0;
      local_20 = (CWnd *)0x0;
      FUN_008083df(local_30,&local_20);
      puVar11 = puVar1;
      if (local_20 == (CWnd *)0x0) {
        pcVar2 = *(code **)(*(int *)pCVar5 + 0x24);
        guard_check_icall(local_30,1);
        pCVar6 = (CObject *)(*pcVar2)();
        pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar6);
        puVar11 = local_18;
        pCVar5 = local_1c;
        if (pCVar6 != (CObject *)0x0) {
          pcVar2 = *(code **)(*(int *)pCVar6 + 0x16c);
          guard_check_icall();
          iVar7 = (*pcVar2)();
          if (iVar7 != 0) {
            pHVar8 = GetParent(*(HWND *)(pCVar6 + 0x20));
            pCVar5 = CWnd::FromHandle(pHVar8);
            pHVar8 = GetParent(*(HWND *)(pCVar5 + 0x20));
            pCVar5 = CWnd::FromHandle(pHVar8);
            local_20 = pCVar5;
            pHVar8 = GetParent((HWND)in_ECX[8]);
            pCVar9 = CWnd::FromHandle(pHVar8);
            if (pCVar9 == (CWnd *)0x0) {
              pHVar8 = (HWND)0x0;
            }
            else {
              pHVar8 = *(HWND *)(pCVar9 + 0x20);
            }
            pHVar8 = SetParent(*(HWND *)(pCVar6 + 0x20),pHVar8);
            CWnd::FromHandle(pHVar8);
            pcVar2 = *(code **)(*(int *)pCVar5 + 0x3c0);
            guard_check_icall(pCVar6);
            (*pcVar2)();
            iVar7 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
            if (iVar7 != 0) {
              pcVar2 = *(code **)(*(int *)pCVar6 + 0x1f0);
              guard_check_icall(1);
              (*pcVar2)();
            }
            FUN_00797f20(5);
          }
          pcVar2 = *(code **)(*(int *)pCVar6 + 0x1dc);
          guard_check_icall();
          iVar7 = (*pcVar2)();
          if (iVar7 != 0) {
            pcVar2 = *(code **)(*(int *)pCVar6 + 0x368);
            guard_check_icall(0,0xf000,0,1);
            (*pcVar2)();
          }
          pcVar2 = *(code **)(*(int *)pCVar6 + 0x228);
          guard_check_icall(0);
          local_20 = (CWnd *)(*pcVar2)();
          if (local_20 != (CWnd *)0x0) {
            pcVar2 = *(code **)(*(int *)local_20 + 0x17c);
            guard_check_icall(pCVar6,0,0);
            (*pcVar2)();
          }
          pHVar8 = GetParent((HWND)in_ECX[8]);
          pCVar5 = CWnd::FromHandle(pHVar8);
          pHVar8 = (HWND)0x0;
          if (pCVar5 != (CWnd *)0x0) {
            pHVar8 = *(HWND *)(pCVar5 + 0x20);
          }
          pHVar8 = SetParent(*(HWND *)(pCVar6 + 0x20),pHVar8);
          CWnd::FromHandle(pHVar8);
          pHVar8 = GetParent((HWND)in_ECX[8]);
          pCVar5 = CWnd::FromHandle(pHVar8);
          pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,
                                       (CObject *)pCVar5);
          pcVar2 = *(code **)(*(int *)pCVar6 + 0x34c);
          guard_check_icall(pCVar10,3,0,0);
          (*pcVar2)();
          puVar11 = local_18;
          pCVar5 = local_1c;
        }
      }
      local_8 = 0xffffffff;
      FUN_00406b10();
    } while (puVar11 != (undefined4 *)0x0);
    piVar12 = (int *)in_ECX[0x5b];
  }
  local_1c = (CWnd *)0x0;
  iVar7 = 0;
  local_14 = 0;
  if (piVar12 != (int *)0x0) {
    do {
      piVar3 = (int *)*piVar12;
      FUN_00806fc4(piVar12 + 2);
      local_18 = (undefined4 *)0x0;
      local_8 = 1;
      local_20 = (CWnd *)FUN_008083df(local_30,&local_18);
      puVar11 = local_18;
      if (local_18 != (undefined4 *)0x0) {
        ATL::CSimpleStringT<wchar_t,0>::operator=
                  ((CSimpleStringT<wchar_t,0> *)(local_18 + 1),local_38);
        puVar11[0xb] = local_28;
        puVar11[0xc] = local_24;
        puVar11[0x11] = local_2c;
        pcVar2 = *(code **)(*in_ECX + 0x1a8);
        guard_check_icall(local_20,local_34,0,0);
        (*pcVar2)();
        if (local_34 != 0) {
          local_14 = local_14 + 1;
        }
        iVar7 = local_14;
        if ((param_1 != 0) && (local_20 != local_1c)) {
          pcVar2 = *(code **)(*in_ECX + 0x260);
          guard_check_icall(local_20,local_1c);
          (*pcVar2)();
          if ((local_18[8] != 0) && (local_1c == (CWnd *)in_ECX[0x61])) {
            FUN_00797f20(5);
          }
          iVar7 = local_14;
          if (0 < local_14) {
            pcVar2 = *(code **)(*in_ECX + 0x214);
            guard_check_icall(local_20);
            (*pcVar2)();
            iVar7 = local_14;
          }
        }
      }
      local_8 = 0xffffffff;
      FUN_00406b10();
      local_1c = local_1c + 1;
      piVar12 = piVar3;
    } while (piVar3 != (int *)0x0);
    if (0 < iVar7) {
      pcVar2 = *(code **)(*in_ECX + 0x214);
      guard_check_icall(in_ECX[0x61]);
      iVar7 = (*pcVar2)();
      if (iVar7 == 0) {
        pcVar2 = *(code **)(*in_ECX + 0x214);
        guard_check_icall(0);
        (*pcVar2)();
      }
      goto LAB_00807930;
    }
    if (iVar7 != 0) goto LAB_00807930;
  }
  pHVar8 = GetParent((HWND)in_ECX[8]);
  pCVar5 = CWnd::FromHandle(pHVar8);
  pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,(CObject *)pCVar5);
  if (pCVar6 != (CObject *)0x0) {
    pcVar2 = *(code **)(*(int *)pCVar6 + 0x224);
    guard_check_icall(0,0,0);
    (*pcVar2)();
  }
LAB_00807930:
  pcVar2 = *(code **)(*in_ECX + 0x184);
  guard_check_icall();
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCBaseTabCtrl[175], CMFCOutlookBarTabCtrl[175], CMFCTabCtrl[175] */
/* 0080794c  FUN_0080794c  255 bytes, 0 callers */

void FUN_0080794c(void)

{
  code *pcVar1;
  int *piVar2;
  BOOL BVar3;
  int iVar4;
  int in_ECX;
  int local_c;
  
  local_c = 0;
  if (0 < *(int *)(in_ECX + 0xbc)) {
    do {
      piVar2 = (int *)FUN_0049a990(local_c);
      piVar2 = (int *)*piVar2;
      if ((*(int *)(piVar2[8] + 0x20) == 0) ||
         (BVar3 = IsWindow(*(HWND *)(piVar2[8] + 0x20)), BVar3 != 0)) {
        iVar4 = FUN_0079d98a(&PTR_s_CPane_0098ac24);
        if (*(int *)(in_ECX + 0x11c) != 0) {
          pcVar1 = *(code **)(*(int *)piVar2[8] + 0x60);
          guard_check_icall();
          (*pcVar1)();
        }
        if ((iVar4 == 0) || (*(int *)(in_ECX + 0x11c) == 0)) {
          pcVar1 = *(code **)(*piVar2 + 4);
          guard_check_icall(1);
          (*pcVar1)();
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(int *)(in_ECX + 0xbc));
  }
  FUN_00819700(in_ECX + 0xf8);
  FUN_00819700(in_ECX + 0xfc);
  FUN_007b011a(0,0xffffffff);
  FUN_0042fb40(0,0xffffffff);
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = 0xffffffff;
  return;
}




/* vtable slots: CMFCBaseTabCtrl[93], CMFCOutlookBarTabCtrl[93], CMFCTabCtrl[93] */
/* 00807a4b  FUN_00807a4b  62 bytes, 0 callers */

void FUN_00807a4b(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (((CImageList *)(in_ECX + 0x32) != (CImageList *)0x0) && (in_ECX[0x33] != 0)) {
    CImageList::DeleteImageList((CImageList *)(in_ECX + 0x32));
  }
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  pcVar1 = *(code **)(*in_ECX + 0x178);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCBaseTabCtrl[177], CMFCOutlookBarTabCtrl[177], CMFCTabCtrl[177] */
/* 00807a89  FUN_00807a89  407 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00807a89(int *param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  uint local_2c;
  undefined4 local_28;
  int local_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x807a95;
  iVar2 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
  if (((iVar2 == 0) && (param_3 != 0)) && (*(int *)(in_ECX + 0x80) != 0)) {
    if (*(int *)(in_ECX + 0x188) == 0) {
      iVar2 = FUN_0078e624(0x380);
      local_8 = 0;
      if (iVar2 == 0) {
        pCVar3 = (CObject *)0x0;
      }
      else {
        pCVar3 = (CObject *)FUN_0085ebb9();
      }
      local_8 = 0xffffffff;
    }
    else {
      pCVar3 = (CObject *)FUN_0079d90c();
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePaneAdapter_00a00984,pCVar3);
    }
    local_2c = 0x56000000;
    local_28 = 0xf;
    local_24 = *(int *)(pCVar3 + 0x368);
    iStack_20 = *(int *)(pCVar3 + 0x36c);
    iStack_1c = *(int *)(pCVar3 + 0x370);
    iStack_18 = *(int *)(pCVar3 + 0x374);
    iVar2 = *(int *)(pCVar3 + 0x348);
    iVar4 = FUN_0079d98a(&PTR_s_CBasePane_0098a7f8);
    if (iVar4 != 0) {
      pcVar1 = *(code **)(*param_1 + 0x1c0);
      guard_check_icall();
      local_2c = (*pcVar1)();
      local_2c = local_2c | 0x56000000;
      pcVar1 = *(code **)(*param_1 + 0x1c4);
      guard_check_icall();
      local_28 = (*pcVar1)();
    }
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x324);
    uVar5 = FUN_00797a2b();
    guard_check_icall(param_2,in_ECX,&local_24,1,uVar5,local_2c,0x20,local_28,0);
    iVar6 = (*pcVar1)();
    iVar4 = *(int *)pCVar3;
    if (iVar6 == 0) {
      guard_check_icall(1);
      (**(code **)(iVar4 + 4))();
    }
    else {
      pcVar1 = *(code **)(iVar4 + 0x1f0);
      guard_check_icall(0);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x3a0);
      guard_check_icall(param_1);
      (*pcVar1)();
      *(int *)(pCVar3 + 0x1e8) = local_24;
      *(int *)(pCVar3 + 0x1ec) = iStack_20;
      *(int *)(pCVar3 + 0x1f0) = iStack_1c;
      *(int *)(pCVar3 + 500) = iStack_18;
      if (iVar2 != 0) {
        *(int *)(pCVar3 + 0x348) = iVar2;
      }
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCBaseTabCtrl[104], CMFCOutlookBarTabCtrl[104], CMFCTabCtrl[104] */
/* 00807c20  FUN_00807c20  1436 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00807c20(int param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int iVar4;
  CObject *pCVar5;
  int iVar6;
  HWND pHVar7;
  CWnd *pCVar8;
  int *in_ECX;
  code *pcVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  tagPOINT local_44;
  int *local_3c;
  uint local_38;
  CWnd *local_34;
  CObject *local_30;
  CObject *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar9 = *(code **)(*in_ECX + 0x2c0);
  guard_check_icall(param_2);
  iVar3 = (*pcVar9)();
  if (iVar3 < 0) {
    return 0;
  }
  pcVar9 = *(code **)(*in_ECX + 0x1f0);
  local_3c = (int *)iVar3;
  guard_check_icall(iVar3);
  iVar4 = (*pcVar9)();
  if (iVar4 == 0) {
    return 0;
  }
  pcVar9 = *(code **)(*in_ECX + 0x1b0);
  guard_check_icall(iVar3);
  pCVar5 = (CObject *)(*pcVar9)();
  local_2c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,pCVar5);
  if (local_2c == (CObject *)0x0) {
    return 0;
  }
  pcVar9 = *(code **)(*(int *)local_2c + 0x1cc);
  guard_check_icall();
  iVar3 = (*pcVar9)();
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = 0;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  SetRectEmpty(&local_28);
  pcVar9 = *(code **)(*(int *)local_2c + 0x2c0);
  guard_check_icall(&local_28,param_1);
  iVar4 = (*pcVar9)();
  if (iVar4 == 0) {
    return 0;
  }
  if (param_1 == 1) {
    local_44.x = 0;
    local_44.y = 0;
    GetCursorPos(&local_44);
    iVar4 = DAT_00a13c54;
    local_38 = in_ECX[0x58] - local_44.y;
    local_34 = (CWnd *)DAT_00a13c58;
    iVar6 = _abs(in_ECX[0x57] - local_44.x);
    if ((iVar6 < iVar4) && (iVar4 = _abs(local_38), iVar4 < (int)local_34)) {
      return 0;
    }
  }
  pcVar9 = *(code **)(*(int *)local_2c + 0x18c);
  guard_check_icall();
  iVar4 = (*pcVar9)();
  if (iVar4 == 0) {
    return 0;
  }
  pcVar9 = *(code **)(*(int *)local_2c + 0x1b8);
  guard_check_icall();
  local_38 = (*pcVar9)();
  pHVar7 = GetParent((HWND)in_ECX[8]);
  pCVar8 = CWnd::FromHandle(pHVar7);
  local_30 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,(CObject *)pCVar8);
  if (local_30 == (CObject *)0x0) {
    local_34 = (CWnd *)0x0;
    goto LAB_00807f46;
  }
  pcVar9 = *(code **)(*(int *)local_30 + 0x228);
  guard_check_icall(0);
  local_34 = (CWnd *)(*pcVar9)();
  pcVar9 = *(code **)(*(int *)local_30 + 0x1cc);
  guard_check_icall();
  iVar4 = (*pcVar9)();
  if (iVar4 == 0) {
    pcVar9 = *(code **)(*in_ECX + 0x1a4);
    guard_check_icall();
    iVar4 = (*pcVar9)();
    if (iVar4 == 1) {
      return 0;
    }
  }
  pCVar5 = local_2c;
  iVar4 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
  if (iVar4 != 0) {
    pcVar9 = *(code **)(*(int *)pCVar5 + 0x1f0);
    guard_check_icall(1);
    (*pcVar9)();
    pCVar5 = local_2c;
  }
  if (((param_3 == 0) && ((local_38 & 2) != 0)) && (param_1 == 1)) {
    param_3 = 1;
  }
  if (local_3c != (int *)in_ECX[0x30]) {
    FUN_00797f20(5);
  }
  pcVar9 = *(code **)(*(int *)local_30 + 0x3b8);
  piVar10 = local_3c;
  iVar4 = param_1;
  guard_check_icall(pCVar5,local_3c,param_1,param_3);
  (*pcVar9)();
  pcVar9 = *(code **)(*in_ECX + 0x1ac);
  guard_check_icall();
  iVar6 = (*pcVar9)();
  if (iVar6 == 0) {
    if (local_34 == (CWnd *)0x0) {
      pcVar9 = *(code **)(*(int *)local_30 + 0x3b0);
      guard_check_icall(pCVar5,piVar10,iVar4,param_3);
      iVar4 = (*pcVar9)();
      if (iVar4 == 0) {
        FUN_00797f20(0);
      }
      else {
        pcVar9 = *(code **)(*(int *)local_30 + 0x60);
        guard_check_icall();
        (*pcVar9)();
      }
    }
    else {
      pcVar9 = *(code **)(*(int *)local_34 + 0x17c);
      guard_check_icall(local_30,1,0);
LAB_00807f30:
      (*pcVar9)();
    }
  }
  else {
    pcVar9 = *(code **)(*in_ECX + 0x1a4);
    guard_check_icall(pCVar5,piVar10,iVar4,param_3);
    iVar4 = (*pcVar9)();
    if (iVar4 == 0) {
      pcVar9 = *(code **)(*(int *)local_30 + 0x224);
      guard_check_icall(0,0,0);
      goto LAB_00807f30;
    }
  }
  pcVar9 = *(code **)(*in_ECX + 0x184);
  guard_check_icall();
  (*pcVar9)();
LAB_00807f46:
  uVar12 = 0;
  pcVar9 = *(code **)(*(int *)local_2c + 0x228);
  guard_check_icall(0);
  local_3c = (int *)(*pcVar9)();
  local_44.y = local_38 & 2;
  if (((local_44.y != 0) && (param_1 == 1)) && (local_3c != (int *)0x0)) {
    ReleaseCapture();
    FUN_00797df8();
    pHVar7 = GetParent((HWND)in_ECX[8]);
    pCVar8 = CWnd::FromHandle(pHVar7);
    SendMessageW(*(HWND *)(pCVar8 + 0x20),0x363,0,0);
  }
  in_ECX[0x56] = 0;
  pcVar9 = *(code **)(*in_ECX + 0x1ac);
  guard_check_icall(uVar12);
  iVar4 = (*pcVar9)();
  if ((iVar4 == 1) && (in_ECX[0x4b] != 0)) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(local_30 + 0x20),&local_18);
    pcVar9 = *(code **)(*in_ECX + 0x1b0);
    guard_check_icall(0);
    pCVar5 = (CObject *)(*pcVar9)();
    local_2c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar5);
    pCVar5 = local_30;
    FUN_007ed9e1(local_2c,local_30,1);
    pCVar2 = local_2c;
    FUN_00890db4(local_2c,param_1,0);
    pcVar9 = *(code **)(*(int *)pCVar2 + 0x1e0);
    pcVar1 = *(code **)(*(int *)pCVar5 + 0x194);
    guard_check_icall();
    uVar12 = (*pcVar1)();
    guard_check_icall(uVar12);
    (*pcVar9)();
    uVar11 = 1;
    uVar12 = 0;
    pcVar9 = *(code **)(*in_ECX + 0x198);
    guard_check_icall(0,1);
    (*pcVar9)();
    pCVar5 = local_30;
    if (local_34 == (CWnd *)0x0) {
      pcVar9 = *(code **)(*(int *)local_30 + 0x19c);
      guard_check_icall(uVar12,uVar11);
      local_34 = (CWnd *)(*pcVar9)();
    }
    pcVar9 = *(code **)(*(int *)local_2c + 0x1f0);
    guard_check_icall(1);
    (*pcVar9)();
    pCVar8 = local_34;
    CWnd::ScreenToClient(local_34,&local_18);
    pCVar2 = local_2c;
    pHVar7 = (HWND)0x0;
    if (pCVar8 != (CWnd *)0x0) {
      pHVar7 = *(HWND *)(pCVar8 + 0x20);
    }
    pHVar7 = SetParent(*(HWND *)(local_2c + 0x20),pHVar7);
    CWnd::FromHandle(pHVar7);
    pcVar9 = *(code **)(*(int *)pCVar2 + 0x238);
    guard_check_icall(0,local_18.left,local_18.top,local_18.right - local_18.left,
                      local_18.bottom - local_18.top,0x94,0);
    (*pcVar9)();
    pcVar9 = *(code **)(*(int *)local_2c + 0x224);
    guard_check_icall(1,0,0);
    (*pcVar9)();
    FUN_00797f20(0);
    pCVar2 = local_2c;
    pHVar7 = GetParent(*(HWND *)(local_2c + 0x20));
    pCVar8 = CWnd::FromHandle(pHVar7);
    InvalidateRect(*(HWND *)(pCVar8 + 0x20),(RECT *)0x0,1);
    pHVar7 = GetParent(*(HWND *)(pCVar2 + 0x20));
    pCVar8 = CWnd::FromHandle(pHVar7);
    UpdateWindow(*(HWND *)(pCVar8 + 0x20));
    iVar3 = *(int *)(pCVar5 + 0x20);
  }
  if ((param_1 == 1) && (local_3c != (int *)0x0)) {
    if (local_44.y == 0) {
      if ((local_38 & 1) != 0) {
        FUN_00797df8();
      }
    }
    else {
      pcVar9 = *(code **)(*local_3c + 0x210);
      guard_check_icall(iVar3);
      (*pcVar9)();
      FUN_00840325();
    }
  }
  return 1;
}




/* vtable slots: CMFCBaseTabCtrl[125], CMFCOutlookBarTabCtrl[125], CMFCTabCtrl[125] */
/* 00808316  EnableTabDetach  49 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::EnableTabDetach(int,int)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::EnableTabDetach(CMFCBaseTabCtrl *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    iVar2 = 0;
  }
  else {
    piVar1 = (int *)FUN_0049a990(param_1);
    *(int *)(*piVar1 + 0x44) = param_2;
    iVar2 = 1;
  }
  return iVar2;
}




/* vtable slots: CMFCBaseTabCtrl[156], CMFCOutlookBarTabCtrl[156], CMFCTabCtrl[156] */
/* 00808434  FUN_00808434  208 bytes, 0 callers */

void FUN_00808434(WPARAM param_1)

{
  code *pcVar1;
  CWnd *pCVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int iVar5;
  undefined4 *puVar6;
  int *in_ECX;
  
  pCVar2 = DAT_00a13a1c;
  if (DAT_00a13a1c == (CWnd *)0x0) {
    pCVar2 = (CWnd *)FUN_00792b4c();
  }
  pHVar3 = GetParent((HWND)in_ECX[8]);
  pCVar4 = CWnd::FromHandle(pHVar3);
  SendMessageW(*(HWND *)(pCVar4 + 0x20),DAT_00a13150,param_1,(LPARAM)in_ECX);
  if ((pCVar4 != pCVar2) && (pCVar2 != (CWnd *)0x0)) {
    SendMessageW(*(HWND *)(pCVar2 + 0x20),DAT_00a13150,param_1,(LPARAM)in_ECX);
  }
  in_ECX[0x7b] = 1;
  iVar5 = FUN_007c2511();
  if (((*(int *)(iVar5 + 0x19c) != 0) && (-1 < (int)param_1)) && ((int)param_1 < in_ECX[0x27])) {
    puVar6 = (undefined4 *)FUN_0049a990(param_1);
    pcVar1 = *(code **)(*in_ECX + 0x2d4);
    guard_check_icall(*puVar6,in_ECX + 0x84,param_1 == in_ECX[0x30]);
    (*pcVar1)();
    NotifyWinEvent(0x8006,(HWND)in_ECX[8],-4,param_1 + 1);
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[157], CMFCOutlookBarTabCtrl[157], CMFCTabCtrl[157] */
/* 00808504  FireChangingActiveTab  104 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::FireChangingActiveTab(int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::FireChangingActiveTab(CMFCBaseTabCtrl *this,int param_1)

{
  CWnd *pCVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  LRESULT LVar4;
  int iVar5;
  
  pCVar1 = DAT_00a13a1c;
  if (DAT_00a13a1c == (CWnd *)0x0) {
    pCVar1 = (CWnd *)FUN_00792b4c();
  }
  pHVar2 = GetParent(*(HWND *)(this + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  LVar4 = SendMessageW(*(HWND *)(pCVar3 + 0x20),DAT_00a13158,param_1,(LPARAM)this);
  if (LVar4 == 0) {
    iVar5 = 0;
    if ((pCVar3 != pCVar1) && (pCVar1 != (CWnd *)0x0)) {
      iVar5 = SendMessageW(*(HWND *)(pCVar1 + 0x20),DAT_00a13158,param_1,(LPARAM)this);
    }
  }
  else {
    iVar5 = 1;
  }
  return iVar5;
}




/* vtable slots: CMFCBaseTabCtrl[132], CMFCOutlookBarTabCtrl[132], CMFCTabCtrl[132] */
/* 0080856c  FUN_0080856c  30 bytes, 0 callers */

undefined4 FUN_0080856c(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc0) == -1) {
    return 0;
  }
  iVar1 = FUN_004b0e80(*(int *)(in_ECX + 0xc0));
  return *(undefined4 *)(iVar1 + 0x20);
}




/* vtable slots: CMFCBaseTabCtrl[150], CMFCOutlookBarTabCtrl[150], CMFCTabCtrl[150] */
/* 0080858a  FUN_0080858a  38 bytes, 0 callers */

void FUN_0080858a(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x254);
  guard_check_icall(0,param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCBaseTabCtrl[149], CMFCOutlookBarTabCtrl[149], CMFCTabCtrl[149] */
/* 008085b0  FUN_008085b0  114 bytes, 0 callers */

undefined4 FUN_008085b0(int param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  int iVar5;
  
  iVar5 = param_1;
  if (param_1 < in_ECX[0x2f]) {
    do {
      piVar3 = (int *)FUN_0049a990(iVar5);
      iVar1 = *piVar3;
      if (*(int *)(iVar1 + 0x34) != 0) {
        *param_2 = iVar5;
        return *(undefined4 *)(iVar1 + 0x20);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < in_ECX[0x2f]);
  }
  if (param_1 < 1) {
    *param_2 = -1;
    uVar4 = 0;
  }
  else {
    pcVar2 = *(code **)(*in_ECX + 0x254);
    guard_check_icall(0,param_2);
    uVar4 = (*pcVar2)();
  }
  return uVar4;
}




/* vtable slots: CMFCBaseTabCtrl[151], CMFCOutlookBarTabCtrl[151], CMFCTabCtrl[151] */
/* 00808622  GetLastVisibleTab  67 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CWnd * __thiscall CMFCBaseTabCtrl::GetLastVisibleTab(int &)
   
   Library: Visual Studio 2015 Release */

CWnd * __thiscall CMFCBaseTabCtrl::GetLastVisibleTab(CMFCBaseTabCtrl *this,int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(this + 0xbc);
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      *param_1 = -1;
      return (CWnd *)0x0;
    }
    piVar3 = (int *)FUN_0049a990(iVar1);
    iVar2 = *piVar3;
  } while (*(int *)(iVar2 + 0x34) == 0);
  *param_1 = iVar1;
  return *(CWnd **)(iVar2 + 0x20);
}




/* vtable slots: CMFCBaseTabCtrl[154], CMFCOutlookBarTabCtrl[154], CMFCTabCtrl[154] */
/* 00808665  FUN_00808665  257 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_00808665(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  undefined1 local_30 [8];
  int local_28;
  int local_24;
  int local_20;
  CObject *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  local_24 = *(int *)(in_ECX + 0x9c);
  if (0 < local_24) {
    local_28 = in_ECX + 0x94;
    do {
      local_1c = (CObject *)FUN_004b0e80(local_20);
      if (*(int *)(local_1c + 0x20) != 0) {
        iVar5 = 0;
        iVar4 = 0;
        iVar2 = FUN_0079d98a(&PTR_s_CBasePane_0098a7f8);
        if (iVar2 == 0) {
          local_18.left = 0;
          local_18.top = 0;
          local_18.right = 0;
          local_18.bottom = 0;
          GetWindowRect(*(HWND *)(*(CObject **)(local_1c + 0x20) + 0x20),&local_18);
          iVar5 = local_18.right - local_18.left;
          iVar4 = local_18.bottom - local_18.top;
        }
        else {
          local_1c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,
                                        *(CObject **)(local_1c + 0x20));
          if (local_1c != (CObject *)0x0) {
            pcVar1 = *(code **)(*(int *)local_1c + 0x260);
            guard_check_icall(local_30,0,1);
            piVar3 = (int *)(*pcVar1)();
            iVar5 = *piVar3;
            iVar4 = piVar3[1];
          }
        }
        if (iVar5 <= *param_1) {
          iVar5 = *param_1;
        }
        *param_1 = iVar5;
        if (iVar4 <= param_1[1]) {
          iVar4 = param_1[1];
        }
        param_1[1] = iVar4;
      }
      local_20 = local_20 + 1;
    } while (local_20 < local_24);
  }
  return param_1;
}




/* vtable slots: CMFCBaseTabCtrl[10] */
/* 00808766  FUN_00808766  6 bytes, 0 callers */

undefined ** FUN_00808766(void)

{
  return &PTR_FUN_0098cb60;
}




/* vtable slots: CMFCBaseTabCtrl[0] */
/* 0080876c  FUN_0080876c  6 bytes, 0 callers */

undefined ** FUN_0080876c(void)

{
  return &PTR_s_CMFCBaseTabCtrl_0098c714;
}




/* vtable slots: CMFCBaseTabCtrl[119], CMFCOutlookBarTabCtrl[119], CMFCTabCtrl[119] */
/* 00808772  GetTabBkColor  92 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCBaseTabCtrl::GetTabBkColor(int)const 
   
   Library: Visual Studio 2015 Release */

ulong __thiscall CMFCBaseTabCtrl::GetTabBkColor(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  ulong *puVar2;
  ulong uVar3;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    uVar3 = *(ulong *)(iVar1 + 0x30);
    if ((uVar3 == 0xffffffff) && (*(int *)(this + 0x1dc) != 0)) {
      puVar2 = (ulong *)FUN_00799cf8(param_1 % *(int *)(this + 0x1d0));
      uVar3 = *puVar2;
      *(ulong *)(iVar1 + 0x30) = uVar3;
    }
  }
  return uVar3;
}




/* vtable slots: CMFCBaseTabCtrl[136], CMFCOutlookBarTabCtrl[136], CMFCTabCtrl[136] */
/* 008087ce  GetTabByID  61 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::GetTabByID(int)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::GetTabByID(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(this + 0xbc)) {
    do {
      iVar1 = FUN_004b0e80(iVar2);
      if (*(int *)(iVar1 + 0x28) == param_1) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(this + 0xbc));
  }
  return -1;
}




/* vtable slots: CMFCBaseTabCtrl[135], CMFCOutlookBarTabCtrl[135], CMFCTabCtrl[135] */
/* 0080880b  FUN_0080880b  126 bytes, 0 callers */

int FUN_0080880b(int param_1)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0xbc)) {
    do {
      iVar2 = FUN_004b0e80(iVar4);
      pCVar3 = *(CObject **)(iVar2 + 0x20);
      if (pCVar3 != (CObject *)0x0) {
        if (*(int *)(pCVar3 + 0x20) == param_1) {
          return iVar4;
        }
        pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePaneAdapter_00a00984,pCVar3);
        if (pCVar3 != (CObject *)0x0) {
          pcVar1 = *(code **)(*(int *)pCVar3 + 0x3a4);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if ((iVar2 != 0) && (*(int *)(iVar2 + 0x20) == param_1)) {
            return iVar4;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0xbc));
  }
  return -1;
}




/* vtable slots: CMFCBaseTabCtrl[134], CMFCOutlookBarTabCtrl[134] */
/* 00808889  GetTabFromPoint  83 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::GetTabFromPoint(class CPoint &)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::GetTabFromPoint(CMFCBaseTabCtrl *this,CPoint *param_1)

{
  int iVar1;
  BOOL BVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(this + 0xbc)) {
    do {
      iVar1 = FUN_004b0e80(iVar3);
      if ((*(int *)(iVar1 + 0x34) != 0) &&
         (BVar2 = PtInRect((RECT *)(iVar1 + 0x10),*(POINT *)param_1), BVar2 != 0)) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(this + 0xbc));
  }
  return -1;
}




/* vtable slots: CMFCBaseTabCtrl[123], CMFCOutlookBarTabCtrl[123], CMFCTabCtrl[123] */
/* 008088dc  GetTabFullWidth  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::GetTabFullWidth(int)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::GetTabFullWidth(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    iVar1 = *(int *)(iVar1 + 0x24);
  }
  return iVar1;
}




/* vtable slots: CMFCBaseTabCtrl[118], CMFCOutlookBarTabCtrl[118], CMFCTabCtrl[118] */
/* 00808905  GetTabHicon  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual struct HICON__ * __thiscall CMFCBaseTabCtrl::GetTabHicon(int)const 
   
   Library: Visual Studio 2015 Release */

HICON__ * __thiscall CMFCBaseTabCtrl::GetTabHicon(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  HICON__ *pHVar2;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    pHVar2 = (HICON__ *)0x0;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    pHVar2 = *(HICON__ **)(iVar1 + 0xc);
  }
  return pHVar2;
}




/* vtable slots: CMFCBaseTabCtrl[113], CMFCOutlookBarTabCtrl[113], CMFCTabCtrl[113] */
/* 00808958  GetTabIcon  42 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned int __thiscall CMFCBaseTabCtrl::GetTabIcon(int)const 
   
   Library: Visual Studio 2015 Release */

uint __thiscall CMFCBaseTabCtrl::GetTabIcon(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    uVar2 = *(uint *)(iVar1 + 8);
  }
  return uVar2;
}




/* vtable slots: CMFCBaseTabCtrl[111], CMFCOutlookBarTabCtrl[111], CMFCTabCtrl[111] */
/* 00808982  FUN_00808982  83 bytes, 0 callers */

undefined4 FUN_00808982(int param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  wchar_t *pwVar3;
  
  if ((param_1 < 0) || (*(int *)(in_ECX + 0xbc) <= param_1)) {
    return 0;
  }
  iVar1 = FUN_004b0e80(param_1);
  iVar2 = 0;
  if (*(int *)(iVar1 + 0x3c) == 0) {
    pwVar3 = *(wchar_t **)(iVar1 + 4);
    if (pwVar3 == (wchar_t *)0x0) goto LAB_008089bf;
  }
  else {
    pwVar3 = L"";
  }
  iVar2 = FUN_008f899d(pwVar3);
LAB_008089bf:
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_2,pwVar3,iVar2);
  return 1;
}




/* vtable slots: CMFCBaseTabCtrl[176], CMFCTabCtrl[176] */
/* 008089d5  FUN_008089d5  21 bytes, 0 callers */

int FUN_008089d5(int param_1)

{
  int in_ECX;
  
  if (param_1 == -1) {
    param_1 = *(int *)(in_ECX + 0xc0);
  }
  return param_1;
}




/* vtable slots: CMFCBaseTabCtrl[110], CMFCOutlookBarTabCtrl[110], CMFCTabCtrl[110] */
/* 008089ea  GetTabRect  70 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::GetTabRect(int,class CRect &)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::GetTabRect(CMFCBaseTabCtrl *this,int param_1,CRect *param_2)

{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < *(int *)(this + 0xbc))) {
    iVar1 = FUN_004b0e80(param_1);
    if (*(int *)(iVar1 + 0x34) != 0) {
      *(undefined4 *)param_2 = *(undefined4 *)(iVar1 + 0x10);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar1 + 0x14);
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar1 + 0x18);
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar1 + 0x1c);
      return 1;
    }
    SetRectEmpty((LPRECT)param_2);
  }
  return 0;
}




/* vtable slots: CMFCBaseTabCtrl[121], CMFCOutlookBarTabCtrl[121], CMFCTabCtrl[121] */
/* 00808a30  GetTabTextColor  42 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCBaseTabCtrl::GetTabTextColor(int)const 
   
   Library: Visual Studio 2015 Release */

ulong __thiscall CMFCBaseTabCtrl::GetTabTextColor(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  ulong uVar2;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    uVar2 = *(ulong *)(iVar1 + 0x2c);
  }
  return uVar2;
}




/* vtable slots: CMFCBaseTabCtrl[108], CMFCOutlookBarTabCtrl[108], CMFCTabCtrl[108] */
/* 00808a5a  GetTabWnd  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CWnd * __thiscall CMFCBaseTabCtrl::GetTabWnd(int)const 
   
   Library: Visual Studio 2015 Release */

CWnd * __thiscall CMFCBaseTabCtrl::GetTabWnd(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  CWnd *pCVar2;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    pCVar2 = (CWnd *)0x0;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    pCVar2 = *(CWnd **)(iVar1 + 0x20);
  }
  return pCVar2;
}




/* vtable slots: CMFCBaseTabCtrl[109], CMFCOutlookBarTabCtrl[109], CMFCTabCtrl[109] */
/* 00808a83  FUN_00808a83  90 bytes, 0 callers */

undefined4 FUN_00808a83(int param_1)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if ((param_1 < 0) || (*(int *)(in_ECX + 0xbc) <= param_1)) {
    uVar4 = 0;
  }
  else {
    iVar2 = FUN_004b0e80(param_1);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePaneAdapter_00a00984,
                                *(CObject **)(iVar2 + 0x20));
    if (pCVar3 == (CObject *)0x0) {
      uVar4 = *(undefined4 *)(iVar2 + 0x20);
    }
    else {
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x3a4);
      guard_check_icall();
      uVar4 = (*pcVar1)();
    }
  }
  return uVar4;
}




/* vtable slots: CMFCBaseTabCtrl[95], CMFCOutlookBarTabCtrl[95] */
/* 00808add  FUN_00808add  7 bytes, 0 callers */

undefined4 FUN_00808add(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x110);
}




/* vtable slots: CMFCBaseTabCtrl[105], CMFCOutlookBarTabCtrl[105], CMFCTabCtrl[105] */
/* 00808aea  GetVisibleTabsNum  59 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::GetVisibleTabsNum(void)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::GetVisibleTabsNum(CMFCBaseTabCtrl *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < *(int *)(this + 0xbc)) {
    do {
      iVar1 = FUN_004b0e80(iVar2);
      if (*(int *)(iVar1 + 0x34) != 0) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(this + 0xbc));
  }
  return iVar3;
}




/* vtable slots: CMFCBaseTabCtrl[144], CMFCOutlookBarTabCtrl[144], CMFCTabCtrl[144] */
/* 00808b25  FUN_00808b25  100 bytes, 0 callers */

undefined4 FUN_00808b25(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  if ((param_1 < 0) || (in_ECX[0x2f] <= param_1)) {
    uVar4 = 0;
  }
  else {
    iVar2 = FUN_004b0e80(param_1);
    uVar4 = 0;
    if (*(int *)(iVar2 + 0xc) == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x23c);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if ((iVar3 != 0) && (*(int *)(iVar2 + 8) != -1)) {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 1;
    }
  }
  return uVar4;
}




/* vtable slots: CMFCBaseTabCtrl[169], CMFCOutlookBarTabCtrl[169] */
/* 00808b89  FUN_00808b89  56 bytes, 0 callers */

void FUN_00808b89(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  if ((in_ECX[0x4b] != param_1) && (in_ECX[0x4b] = param_1, in_ECX[8] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x184);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[178], CMFCOutlookBarTabCtrl[178], CMFCTabCtrl[178] */
/* 00808bc1  InitAutoColors  356 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCBaseTabCtrl::InitAutoColors(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCBaseTabCtrl::InitAutoColors(CMFCBaseTabCtrl *this)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(this + 0x1e0) != 0) {
    FUN_0079ca8b(0,0xffffffff);
    iVar1 = FUN_007c2511();
    if (*(int *)(iVar1 + 0x1ac) < 9) {
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xff00);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xffff00);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xff00ff);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xc0c0c0);
      uVar2 = 0xffff;
    }
    else {
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xf2d4c5);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0x78dcff);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xa1cebe);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),&IMAGE_RESOURCE_DIRECTORY_00a1a0f0);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xe1a8bc);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xb6c19c);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0x86b8f7);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xc2add9);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xd7c2a5);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xbea6b3);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xa3d6ea);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0x7dfaf6);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0x9de9b5);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0xcfc35f);
      FUN_0079c90d(*(undefined4 *)(this + 0x1d0),0x8383c1);
      uVar2 = 0xd5caca;
    }
    FUN_0079c90d(*(undefined4 *)(this + 0x1d0),uVar2);
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[100], CMFCOutlookBarTabCtrl[100], CMFCTabCtrl[100] */
/* 00808dba  FUN_00808dba  136 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00808dba(undefined4 param_1,HINSTANCE param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  UINT in_stack_ffffffdc;
  LPSTR in_stack_ffffffe0;
  int in_stack_ffffffe4;
  undefined4 local_14;
  
  iVar2 = FUN_00797a2b();
  if (iVar2 != -1) {
    CStringT<>();
    iVar2 = FID_conflict_LoadStringA(param_2,in_stack_ffffffdc,in_stack_ffffffe0,in_stack_ffffffe4);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    pcVar1 = *(code **)(*in_ECX + 0x2c4);
    guard_check_icall(param_1,local_14,param_5);
    uVar3 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x194);
    guard_check_icall(uVar3,local_14,param_3,param_4,param_5);
    (*pcVar1)();
    FUN_00406b10();
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[101], CMFCOutlookBarTabCtrl[101], CMFCTabCtrl[101] */
/* 00808e43  FUN_00808e43  563 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00808e43(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int *in_ECX;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x808e4f;
  local_2c = param_5;
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pcVar2 = *(code **)(*in_ECX + 0x2c4);
  iVar5 = param_2;
  guard_check_icall(param_1,param_2,param_5);
  local_28 = (*pcVar2)();
  BVar4 = IsWindowVisible((HWND)in_ECX[8]);
  if (BVar4 == 0) {
    FUN_00797f20(5);
  }
  piVar1 = in_ECX + 0x2f;
  if ((param_3 < 0) || (*piVar1 < param_3)) {
    param_3 = *piVar1;
  }
  pcVar2 = *(code **)(*in_ECX + 0x210);
  guard_check_icall(param_1,iVar5,param_5);
  iVar5 = (*pcVar2)();
  iVar6 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
  uVar7 = -(uint)(iVar6 != 0) & local_2c;
  iVar6 = FUN_0078e624(0x48);
  local_8 = 0;
  if (iVar6 == 0) {
    uVar8 = 0;
  }
  else {
    iVar3 = in_ECX[0x42];
    CStringT<>(param_2);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar8 = FUN_00807015(&local_2c,param_4,local_28,iVar3,uVar7);
  }
  local_8 = 2;
  FUN_007affd3(param_3,uVar8,1);
  local_8 = 0xffffffff;
  if (iVar6 != 0) {
    FUN_00406b10();
  }
  *piVar1 = *piVar1 + 1;
  if ((in_ECX[0x3e] != 0) && (*(int *)(in_ECX[0x3e] + 0x20) != 0)) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    if (in_ECX[0x40] != 0) {
      param_2 = -1;
    }
    FUN_007af3f5(in_ECX,param_2,&local_24,in_ECX[0x42]);
  }
  in_ECX[0x42] = in_ECX[0x42] + 1;
  FUN_0042fb40(0,0xffffffff);
  pcVar2 = *(code **)(*in_ECX + 0x26c);
  guard_check_icall();
  (*pcVar2)();
  pcVar2 = *(code **)(*in_ECX + 0x184);
  guard_check_icall();
  (*pcVar2)();
  if (*piVar1 == 1) {
    pcVar2 = *(code **)(*in_ECX + 0x214);
    guard_check_icall(0);
    (*pcVar2)();
  }
  else {
    iVar6 = in_ECX[0x30];
    in_ECX[0x79] = iVar6;
    if (iVar6 == param_3) {
      in_ECX[0x79] = iVar6 + 1;
      if ((in_ECX[0x48] != 0) && (iVar5 != 0)) {
        FUN_00797f20(0);
      }
      uVar8 = 1;
    }
    else {
      if (((in_ECX[0x48] == 0) || (local_28 == 0)) || (*(int *)(local_28 + 0x20) == 0))
      goto LAB_0080904a;
      uVar8 = 0;
    }
    FUN_00797f20(uVar8);
  }
LAB_0080904a:
  if (((in_ECX[0x48] == 0) && (iVar5 != 0)) && (*(int *)(iVar5 + 0x20) != 0)) {
    BringWindowToTop(*(HWND *)(iVar5 + 0x20));
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCBaseTabCtrl[170], CMFCOutlookBarTabCtrl[170], CMFCTabCtrl[170] */
/* 008090e6  FUN_008090e6  61 bytes, 0 callers */

undefined4 FUN_008090e6(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  
  iVar3 = 0;
  if (0 < in_ECX[0x2f]) {
    do {
      pcVar1 = *(code **)(*in_ECX + 0x1dc);
      guard_check_icall(iVar3);
      iVar2 = (*pcVar1)();
      if (iVar2 != -1) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < in_ECX[0x2f]);
  }
  return 0;
}




/* vtable slots: CMFCBaseTabCtrl[124], CMFCTabCtrl[124] */
/* 00809123  IsTabDetachable  41 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::IsTabDetachable(int)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::IsTabDetachable(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    iVar1 = *(int *)(iVar1 + 0x44);
  }
  return iVar1;
}




/* vtable slots: CMFCBaseTabCtrl[115], CMFCOutlookBarTabCtrl[115], CMFCTabCtrl[115] */
/* 0080914c  IsTabIconOnly  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::IsTabIconOnly(int)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::IsTabIconOnly(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    iVar1 = *(int *)(iVar1 + 0x3c);
  }
  return iVar1;
}




/* vtable slots: CMFCBaseTabCtrl[159], CMFCOutlookBarTabCtrl[159], CMFCTabCtrl[159] */
/* 00809175  IsTabVisible  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::IsTabVisible(int)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::IsTabVisible(CMFCBaseTabCtrl *this,int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004b0e80(param_1);
    iVar1 = *(int *)(iVar1 + 0x34);
  }
  return iVar1;
}




/* vtable slots: CMFCBaseTabCtrl[153], CMFCOutlookBarTabCtrl[153] */
/* 0080919e  FUN_0080919e  449 bytes, 2 callers */

void FUN_0080919e(int param_1,int param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if ((param_1 != param_2) || (in_ECX[0x4e] != 0)) {
    puVar3 = (undefined4 *)FUN_0049a990(param_1);
    uVar1 = *puVar3;
    piVar4 = (int *)FUN_0049a990(in_ECX[0x30]);
    iVar5 = *piVar4;
    if (in_ECX[0x4e] == 0) {
      if (param_2 == -1) {
        FUN_007b00e7(in_ECX[0x27],uVar1);
        FUN_007b0085(param_1,1);
      }
      else {
        FUN_007b0085(param_1,1);
        FUN_007affd3(param_2,uVar1,1);
      }
      if (0 < in_ECX[0x27]) {
        do {
          piVar4 = (int *)FUN_0049a990(iVar7);
          if (iVar5 == *piVar4) {
            if (iVar7 != in_ECX[0x30]) {
              pcVar2 = *(code **)(*in_ECX + 0x214);
              guard_check_icall(iVar7);
              (*pcVar2)();
              pcVar2 = *(code **)(*in_ECX + 0x270);
              guard_check_icall(in_ECX[0x30]);
              (*pcVar2)();
            }
            break;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < in_ECX[0x27]);
      }
    }
    else {
      iVar5 = in_ECX[0x27];
      if (in_ECX[0x2c] != iVar5) {
        FUN_0042fb40(0,0xffffffff);
        iVar5 = in_ECX[0x27];
        if (0 < iVar5) {
          iVar6 = 0;
          do {
            FUN_0042f500(in_ECX[0x2c],iVar6);
            iVar5 = in_ECX[0x27];
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar5);
        }
      }
      if (param_2 == -1) {
        param_2 = iVar5 + -1;
      }
      if (0 < in_ECX[0x2c]) {
        do {
          piVar4 = (int *)FUN_005db5d0(iVar7);
          if (*piVar4 == param_1) {
            if (iVar7 != -1) {
              FUN_0080a5b1(iVar7,1);
              FUN_00808d25(param_2,param_1,1);
            }
            break;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < in_ECX[0x2c]);
      }
    }
    pcVar2 = *(code **)(*in_ECX + 0x184);
    guard_check_icall();
    (*pcVar2)();
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[180], CMFCOutlookBarTabCtrl[180], CMFCTabCtrl[180] */
/* 0080a243  FUN_0080a243  143 bytes, 0 callers */

undefined4 FUN_0080a243(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  BOOL BVar5;
  int *in_ECX;
  int iVar6;
  
  FUN_007ed2e1();
  iVar6 = 0;
  if (0 < in_ECX[0x2f]) {
    do {
      piVar4 = (int *)FUN_0049a990(iVar6);
      iVar1 = iVar6 + 1;
      iVar2 = *piVar4;
      if (((iVar1 == param_1) && (*(int *)(iVar2 + 0x34) != 0)) &&
         (BVar5 = IsRectEmpty((RECT *)(iVar2 + 0x10)), BVar5 == 0)) {
        pcVar3 = *(code **)(*in_ECX + 0x2d4);
        guard_check_icall(iVar2,in_ECX + 0x84,iVar6 == in_ECX[0x30]);
        (*pcVar3)();
        return 1;
      }
      iVar6 = iVar1;
    } while (iVar1 < in_ECX[0x2f]);
  }
  return 0;
}




/* vtable slots: CMFCBaseTabCtrl[67], CMFCOutlookBarTabCtrl[67] */
/* 0080a308  FUN_0080a308  374 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0080a308(int param_1)

{
  code *pcVar1;
  POINT pt;
  int iVar2;
  BOOL BVar3;
  undefined4 uVar4;
  int *in_ECX;
  tagPOINT local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x54] == 0) {
    uVar4 = FUN_007949fb(param_1);
    return uVar4;
  }
  if (*(int *)(param_1 + 4) - 0x100U < 10) {
    if (*(int *)(param_1 + 8) == 0xd) {
      pcVar1 = *(code **)(*in_ECX + 0x1fc);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        MessageBeep(0xffffffff);
        return 1;
      }
    }
    else if (*(int *)(param_1 + 8) != 0x1b) {
      return 0;
    }
  }
  else {
    if (0xe < *(int *)(param_1 + 4) - 0x200U) {
      return 0;
    }
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetClientRect(*(HWND *)(in_ECX[0x54] + 0x20),&local_18);
    MapWindowPoints(*(HWND *)(in_ECX[0x54] + 0x20),(HWND)in_ECX[8],(LPPOINT)&local_18,2);
    local_20.x = 0;
    local_20.y = 0;
    GetCursorPos(&local_20);
    ScreenToClient((HWND)in_ECX[8],&local_20);
    pt.y = local_20.y;
    pt.x = local_20.x;
    BVar3 = PtInRect(&local_18,pt);
    if (BVar3 != 0) {
      SendMessageW(*(HWND *)(in_ECX[0x54] + 0x20),*(UINT *)(param_1 + 4),*(WPARAM *)(param_1 + 8),
                   *(LPARAM *)(param_1 + 0xc));
      return 1;
    }
    if (*(int *)(param_1 + 4) == 0x200) {
      return 1;
    }
  }
  pcVar1 = *(code **)(*(int *)in_ECX[0x54] + 0x60);
  guard_check_icall();
  (*pcVar1)();
  if ((int *)in_ECX[0x54] != (int *)0x0) {
    pcVar1 = *(code **)(*(int *)in_ECX[0x54] + 4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  in_ECX[0x54] = 0;
  in_ECX[0x53] = -1;
  ReleaseCapture();
  return 1;
}




/* vtable slots: CMFCBaseTabCtrl[103], CMFCOutlookBarTabCtrl[103], CMFCTabCtrl[103] */
/* 0080a4b4  FUN_0080a4b4  253 bytes, 0 callers */

void FUN_0080a4b4(void)

{
  int iVar1;
  CToolTipCtrl *this;
  code *pcVar2;
  int *piVar3;
  CWnd *in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc0) = 0xffffffff;
  iVar1 = *(int *)(in_ECX + 0xbc);
  *(undefined4 *)(in_ECX + 0x108) = 1;
  while (0 < iVar1) {
    piVar3 = (int *)FUN_0049a990(iVar1 + -1);
    this = *(CToolTipCtrl **)(in_ECX + 0xf8);
    piVar3 = (int *)*piVar3;
    *(int *)(in_ECX + 0xbc) = *(int *)(in_ECX + 0xbc) + -1;
    if ((this != (CToolTipCtrl *)0x0) && (*(int *)(this + 0x20) != 0)) {
      CToolTipCtrl::DelTool(this,in_ECX,piVar3[10]);
    }
    if (*(int *)(in_ECX + 0x11c) != 0) {
      pcVar2 = *(code **)(*(int *)piVar3[8] + 0x60);
      guard_check_icall();
      (*pcVar2)();
    }
    if (piVar3 != (int *)0x0) {
      pcVar2 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar2)();
    }
    iVar1 = *(int *)(in_ECX + 0xbc);
  }
  FUN_007b011a(0,0xffffffff);
  FUN_0042fb40(0,0xffffffff);
  pcVar2 = *(code **)(*(int *)in_ECX + 0x26c);
  guard_check_icall();
  (*pcVar2)();
  pcVar2 = *(code **)(*(int *)in_ECX + 0x184);
  guard_check_icall();
  (*pcVar2)();
  pcVar2 = *(code **)(*(int *)in_ECX + 0x270);
  guard_check_icall(0xffffffff);
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCBaseTabCtrl[102], CMFCOutlookBarTabCtrl[102], CMFCTabCtrl[102] */
/* 0080a613  FUN_0080a613  500 bytes, 0 callers */

undefined4 FUN_0080a613(int param_1,int param_2)

{
  code *pcVar1;
  CToolTipCtrl *this;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  CWnd *in_ECX;
  int iVar5;
  int *local_c;
  int local_8;
  
  if ((param_1 < 0) || (*(int *)(in_ECX + 0xbc) <= param_1)) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(in_ECX + 0xbc) == 1) {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x19c);
      guard_check_icall();
      (*pcVar1)();
    }
    else {
      piVar4 = (int *)FUN_0049a990(param_1);
      this = *(CToolTipCtrl **)(in_ECX + 0xf8);
      piVar4 = (int *)*piVar4;
      local_c = piVar4;
      if ((this != (CToolTipCtrl *)0x0) && (*(int *)(this + 0x20) != 0)) {
        CToolTipCtrl::DelTool(this,in_ECX,piVar4[10]);
      }
      FUN_007b0085(param_1,1);
      *(int *)(in_ECX + 0xbc) = *(int *)(in_ECX + 0xbc) + -1;
      FUN_0042fb40(0,0xffffffff);
      if (*(int *)(in_ECX + 0x11c) != 0) {
        pcVar1 = *(code **)(*(int *)piVar4[8] + 0x60);
        guard_check_icall();
        (*pcVar1)();
        piVar4 = local_c;
      }
      if (piVar4 != (int *)0x0) {
        pcVar1 = *(code **)(*piVar4 + 4);
        guard_check_icall(1);
        (*pcVar1)();
      }
      local_8 = *(int *)(in_ECX + 0xc0);
      if (param_1 <= local_8) {
        if (*(int *)(in_ECX + 0x84) == 0) {
          iVar5 = *(int *)(in_ECX + 0xbc);
          while (iVar5 = iVar5 + -1, -1 < iVar5) {
            piVar4 = (int *)FUN_0049a990(iVar5);
            if (((iVar5 < param_1) && (-1 < local_8)) && (local_8 < *(int *)(in_ECX + 0xbc))) break;
            if (*(int *)(*piVar4 + 0x34) != 0) {
              local_8 = iVar5;
            }
          }
        }
        else {
          pcVar1 = *(code **)(*(int *)in_ECX + 0x25c);
          guard_check_icall(&local_8);
          (*pcVar1)();
        }
        *(undefined4 *)(in_ECX + 0xc0) = 0xffffffff;
      }
      pcVar1 = *(code **)(*(int *)in_ECX + 0x26c);
      guard_check_icall();
      (*pcVar1)();
      if (param_2 != 0) {
        pcVar1 = *(code **)(*(int *)in_ECX + 0x184);
        guard_check_icall();
        (*pcVar1)();
        if (local_8 != -1) {
          iVar5 = local_8;
          if (((*(int *)(in_ECX + 0x1e8) != 0) && (iVar2 = *(int *)(in_ECX + 0x1e4), iVar2 != -1))
             && (iVar5 = iVar2, param_1 < iVar2)) {
            iVar5 = iVar2 + -1;
          }
          local_c = (int *)0xffffffff;
          pcVar1 = *(code **)(*(int *)in_ECX + 0x254);
          guard_check_icall(iVar5,&local_c);
          (*pcVar1)();
          pcVar1 = *(code **)(*(int *)in_ECX + 0x214);
          guard_check_icall(local_c);
          (*pcVar1)();
          pcVar1 = *(code **)(*(int *)in_ECX + 0x270);
          guard_check_icall(*(undefined4 *)(in_ECX + 0xc0));
          (*pcVar1)();
        }
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CMFCBaseTabCtrl[127], CMFCOutlookBarTabCtrl[127], CMFCTabCtrl[127] */
/* 0080a807  FUN_0080a807  193 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0080a807(void)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  LRESULT LVar5;
  int *in_ECX;
  undefined4 uVar6;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x80a813;
  uVar6 = 0;
  if (in_ECX[0x54] == 0) {
    uVar6 = 0;
  }
  else {
    CStringT<>();
    local_8 = 0;
    FUN_00792c64(local_14);
    if (*(int *)(local_14[0] + -0xc) != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x200);
      guard_check_icall(in_ECX[0x53],local_14);
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        pHVar3 = GetParent((HWND)in_ECX[8]);
        pCVar4 = CWnd::FromHandle(pHVar3);
        LVar5 = SendMessageW(*(HWND *)(pCVar4 + 0x20),DAT_00a1314c,in_ECX[0x53],local_14[0]);
        if (LVar5 == 0) {
          pcVar1 = *(code **)(*in_ECX + 0x1c0);
          guard_check_icall(in_ECX[0x53],local_14);
          uVar6 = (*pcVar1)();
        }
      }
    }
    FUN_00406b10();
  }
  return uVar6;
}




/* vtable slots: CMFCBaseTabCtrl[2], CMFCOutlookBarTabCtrl[2], CMFCTabCtrl[2] */
/* 0080a99b  FUN_0080a99b  387 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0080a99b(CArchive *param_1)

{
  long lVar1;
  long lVar2;
  int in_ECX;
  int iVar3;
  undefined1 local_38 [4];
  long local_34;
  long local_30;
  long local_2c;
  long local_28;
  long local_24;
  int local_20;
  int local_1c;
  CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo> *local_18;
  long local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x80a9a7;
  iVar3 = 0;
  local_18 = (CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo> *)0x0;
  local_14[0] = 0;
  local_1c = in_ECX;
  if (((byte)param_1[0x18] & 1) == 0) {
    local_14[0] = *(long *)(in_ECX + 0x9c);
    CArchive::operator<<(param_1,local_14[0]);
    lVar1 = local_14[0];
    if (0 < local_14[0]) {
      local_20 = in_ECX + 0x94;
      do {
        iVar3 = FUN_004b0e80(iVar3);
        CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                  (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                           (iVar3 + 4));
        CArchive::operator<<(param_1,*(long *)(iVar3 + 0x34));
        lVar2 = FUN_00797a2b();
        CArchive::operator<<(param_1,lVar2);
        CArchive::operator<<(param_1,*(long *)(iVar3 + 0x44));
        CArchive::operator<<(param_1,*(long *)(iVar3 + 0x2c));
        CArchive::operator<<(param_1,*(long *)(iVar3 + 0x30));
        iVar3 = (int)local_18 + 1;
        in_ECX = local_1c;
        local_18 = (CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo> *)iVar3;
      } while (iVar3 < lVar1);
    }
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0xc0));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x90));
  }
  else {
    local_18 = (CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo> *)(in_ECX + 0x168);
    CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>::RemoveAll(local_18);
    CArchive::operator>>(param_1,local_14);
    iVar3 = local_14[0];
    if (0 < local_14[0]) {
      do {
        CStringT<>();
        local_8 = 0;
        FUN_0047fc90(local_38);
        CArchive::operator>>(param_1,&local_34);
        CArchive::operator>>(param_1,&local_30);
        CArchive::operator>>(param_1,&local_2c);
        CArchive::operator>>(param_1,&local_28);
        CArchive::operator>>(param_1,&local_24);
        FUN_00806fc4(local_38);
        CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>::AddTail(local_18);
        local_8 = 0xffffffff;
        FUN_00406b10();
        iVar3 = iVar3 + -1;
        in_ECX = local_1c;
      } while (iVar3 != 0);
    }
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x184));
    CArchive::operator>>(param_1,&local_20);
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[181], CMFCOutlookBarTabCtrl[181], CMFCTabCtrl[181] */
/* 0080ab1e  FUN_0080ab1e  114 bytes, 0 callers */

undefined4 FUN_0080ab1e(int param_1,CSimpleStringT<wchar_t,0> *param_2,int param_3)

{
  int iVar1;
  
  FUN_007ed2e1();
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,(CSimpleStringT<wchar_t,0> *)(param_1 + 4));
  iVar1 = FUN_008f899d(L"Switch");
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 0x14,L"Switch",iVar1);
  *(undefined4 *)(param_2 + 0x20) = 1;
  *(undefined4 *)(param_2 + 0x18) = 0x25;
  if (param_3 != 0) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 2;
  }
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x1c);
  FUN_0079e8b8(param_2 + 0x24);
  return 1;
}




/* vtable slots: CMFCBaseTabCtrl[138], CMFCOutlookBarTabCtrl[138], CMFCTabCtrl[138] */
/* 0080ab90  FUN_0080ab90  82 bytes, 0 callers */

void FUN_0080ab90(int param_1)

{
  code *pcVar1;
  COLORREF color;
  HBRUSH pHVar2;
  int *in_ECX;
  
  in_ECX[0x4f] = param_1;
  if (((CGdiObject *)(in_ECX + 0x51) != (CGdiObject *)0x0) && (in_ECX[0x52] != 0)) {
    CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x51));
  }
  pcVar1 = *(code **)(*in_ECX + 0x230);
  guard_check_icall();
  color = (*pcVar1)();
  pHVar2 = CreateSolidBrush(color);
  Attach(pHVar2);
  return;
}




/* vtable slots: CMFCBaseTabCtrl[139], CMFCOutlookBarTabCtrl[139], CMFCTabCtrl[139] */
/* 0080abe2  FUN_0080abe2  16 bytes, 0 callers */

void FUN_0080abe2(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x140) = param_1;
  return;
}




/* vtable slots: CMFCBaseTabCtrl[92], CMFCOutlookBarTabCtrl[92] */
/* 0080acda  FUN_0080acda  291 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0080acda(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  CImageList *this;
  undefined4 uVar4;
  undefined1 local_34 [8];
  int local_2c;
  short local_22;
  undefined **local_1c;
  HANDLE local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  uVar4 = 0;
  local_1c = CBitmap::vftable;
  local_18 = (HANDLE)0x0;
  local_8 = 0;
  local_14 = in_ECX;
  iVar2 = FUN_004167a0(param_1);
  if (iVar2 == 0) goto LAB_0080ade4;
  this = (CImageList *)(in_ECX + 0x32);
  if ((this != (CImageList *)0x0) && (in_ECX[0x33] != 0)) {
    CImageList::DeleteImageList(this);
  }
  GetObjectW(local_18,0x18,local_34);
  if (local_22 == 4) {
LAB_0080ad8d:
    uVar3 = (param_3 != -1) + 4;
  }
  else if (local_22 == 8) {
    uVar3 = (param_3 != -1) + 8;
  }
  else if (local_22 == 0x10) {
    uVar3 = (param_3 != -1) + 0x10;
  }
  else if (local_22 == 0x18) {
    uVar3 = (param_3 != -1) + 0x18;
  }
  else {
    if (local_22 != 0x20) goto LAB_0080ad8d;
    uVar3 = (param_3 != -1) + 0x20;
  }
  CImageList::Create(this,param_2,local_2c,uVar3,0,0);
  FUN_007c2827(local_14[0x33],local_18,param_3);
  local_14[0x36] = local_2c;
  local_14[0x35] = param_2;
  pcVar1 = *(code **)(*local_14 + 0x178);
  guard_check_icall();
  (*pcVar1)();
  uVar4 = 1;
LAB_0080ade4:
  local_1c = CBitmap::vftable;
  FUN_00416100();
  return uVar4;
}




/* vtable slots: CMFCBaseTabCtrl[91], CMFCOutlookBarTabCtrl[91] */
/* 0080adfd  FUN_0080adfd  164 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_0080adfd(_IMAGELIST *param_1)

{
  code *pcVar1;
  CImageList *pCVar2;
  int *in_ECX;
  undefined1 local_38 [16];
  RECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 != (_IMAGELIST *)0x0) {
    if (((CImageList *)(in_ECX + 0x32) != (CImageList *)0x0) && (in_ECX[0x33] != 0)) {
      CImageList::DeleteImageList((CImageList *)(in_ECX + 0x32));
    }
    pCVar2 = CImageList::FromHandle(param_1);
    if (pCVar2 != (CImageList *)0x0) {
      FUN_0079cfec(*(undefined4 *)(pCVar2 + 4),0,local_38);
      CopyRect(&local_18,&local_28);
      in_ECX[0x36] = local_18.bottom - local_18.top;
      in_ECX[0x34] = (int)param_1;
      in_ECX[0x35] = local_18.right - local_18.left;
      pcVar1 = *(code **)(*in_ECX + 0x178);
      guard_check_icall();
      (*pcVar1)();
    }
    return pCVar2 != (CImageList *)0x0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCBaseTabCtrl[158], CMFCOutlookBarTabCtrl[158], CMFCTabCtrl[158] */
/* 0080aea2  FUN_0080aea2  81 bytes, 0 callers */

void FUN_0080aea2(int param_1)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  int *in_ECX;
  
  in_ECX[0x24] = param_1;
  pcVar1 = *(code **)(*in_ECX + 0x184);
  guard_check_icall();
  (*pcVar1)();
  if (in_ECX[8] != 0) {
    pHVar2 = GetParent((HWND)in_ECX[8]);
    pCVar3 = CWnd::FromHandle(pHVar2);
    RedrawWindow(*(HWND *)(pCVar3 + 0x20),(RECT *)0x0,(HRGN)0x0,0x185);
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[120], CMFCOutlookBarTabCtrl[120], CMFCTabCtrl[120] */
/* 0080aef3  SetTabBkColor  49 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::SetTabBkColor(int,unsigned long)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::SetTabBkColor(CMFCBaseTabCtrl *this,int param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    iVar2 = 0;
  }
  else {
    piVar1 = (int *)FUN_0049a990(param_1);
    *(ulong *)(*piVar1 + 0x30) = param_2;
    iVar2 = 1;
  }
  return iVar2;
}




/* vtable slots: CMFCBaseTabCtrl[145], CMFCOutlookBarTabCtrl[145], CMFCTabCtrl[145] */
/* 0080af24  FUN_0080af24  92 bytes, 0 callers */

void FUN_0080af24(int param_1,int param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (param_1 == -1) {
    param_1 = 2;
  }
  if (in_ECX[0x43] != param_1) {
    in_ECX[0x43] = param_1;
    pcVar1 = *(code **)(*in_ECX + 0x184);
    guard_check_icall();
    (*pcVar1)();
    if ((param_2 != 0) && (in_ECX[8] != 0)) {
      InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
      UpdateWindow((HWND)in_ECX[8]);
    }
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[117], CMFCOutlookBarTabCtrl[117], CMFCTabCtrl[117] */
/* 0080af80  FUN_0080af80  190 bytes, 0 callers */

undefined4 FUN_0080af80(int param_1,HICON param_2)

{
  code *pcVar1;
  int *piVar2;
  HICON pHVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  
  if ((param_1 < 0) || (in_ECX[0x2f] <= param_1)) {
    uVar6 = 0;
  }
  else {
    piVar2 = (int *)FUN_0049a990(param_1);
    iVar5 = *piVar2;
    if (*(int *)(iVar5 + 0xc) != 0) {
      DestroyIcon(*(HICON *)(iVar5 + 0xc));
    }
    if (param_2 == (HICON)0x0) {
      pHVar3 = (HICON)0x0;
    }
    else {
      pHVar3 = CopyIcon(param_2);
    }
    *(HICON *)(iVar5 + 0xc) = pHVar3;
    *(undefined4 *)(iVar5 + 8) = 0xffffffff;
    iVar4 = FUN_007c2511();
    iVar5 = in_ECX[0x35];
    if (iVar5 <= *(int *)(iVar4 + 0x114)) {
      iVar5 = FUN_007c2511();
      iVar5 = *(int *)(iVar5 + 0x114);
    }
    in_ECX[0x35] = iVar5;
    iVar4 = FUN_007c2511();
    iVar5 = in_ECX[0x36];
    if (iVar5 <= *(int *)(iVar4 + 0x118)) {
      iVar5 = FUN_007c2511();
      iVar5 = *(int *)(iVar5 + 0x118);
    }
    in_ECX[0x36] = iVar5;
    pcVar1 = *(code **)(*in_ECX + 0x178);
    guard_check_icall();
    (*pcVar1)();
    uVar6 = 1;
  }
  return uVar6;
}




/* vtable slots: CMFCBaseTabCtrl[114], CMFCOutlookBarTabCtrl[114], CMFCTabCtrl[114] */
/* 0080b03e  SetTabIcon  70 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::SetTabIcon(int,unsigned int)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::SetTabIcon(CMFCBaseTabCtrl *this,int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    iVar2 = 0;
  }
  else {
    piVar1 = (int *)FUN_0049a990(param_1);
    iVar2 = *piVar1;
    if (*(int *)(iVar2 + 0xc) != 0) {
      DestroyIcon(*(HICON *)(iVar2 + 0xc));
    }
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(uint *)(iVar2 + 8) = param_2;
    iVar2 = 1;
  }
  return iVar2;
}




/* vtable slots: CMFCBaseTabCtrl[116], CMFCOutlookBarTabCtrl[116], CMFCTabCtrl[116] */
/* 0080b084  FUN_0080b084  81 bytes, 0 callers */

undefined4 FUN_0080b084(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  if ((param_1 < 0) || (in_ECX[0x2f] <= param_1)) {
    uVar4 = 0;
  }
  else {
    piVar3 = (int *)FUN_0049a990(param_1);
    iVar1 = *piVar3;
    *(undefined4 *)(iVar1 + 0x3c) = param_2;
    *(undefined4 *)(iVar1 + 0x40) = param_3;
    pcVar2 = *(code **)(*in_ECX + 0x184);
    guard_check_icall();
    (*pcVar2)();
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CMFCBaseTabCtrl[112], CMFCOutlookBarTabCtrl[112], CMFCTabCtrl[112] */
/* 0080b0d5  FUN_0080b0d5  392 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0080b0d5(int param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  CToolTipCtrl *this;
  code *pcVar1;
  int *piVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  CObject *pCVar5;
  int iVar6;
  CWnd *in_ECX;
  CToolInfo local_238 [16];
  undefined1 local_228 [544];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (((-1 < param_1) && (param_1 < *(int *)(in_ECX + 0xbc))) &&
     (*(int *)(*(int *)param_2 + -0xc) != 0)) {
    piVar2 = (int *)FUN_0049a990(param_1);
    iVar6 = *piVar2;
    ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(iVar6 + 4),param_2);
    this = *(CToolTipCtrl **)(in_ECX + 0xf8);
    if ((this != (CToolTipCtrl *)0x0) && (*(int *)(this + 0x20) != 0)) {
      if (*(int *)(in_ECX + 0x100) == 0) {
        FUN_007afd2c(*(undefined4 *)param_2,in_ECX,*(uint *)(iVar6 + 0x28));
      }
      else {
        CToolTipCtrl::GetToolInfo(this,local_238,in_ECX,*(uint *)(iVar6 + 0x28));
        CToolTipCtrl::DelTool(*(CToolTipCtrl **)(in_ECX + 0xf8),in_ECX,*(uint *)(iVar6 + 0x28));
        FUN_007af3f5(in_ECX,0xffffffff,local_228,*(undefined4 *)(iVar6 + 0x28));
      }
    }
    if ((*(int *)(iVar6 + 0x20) != 0) && (*(int *)(*(int *)(iVar6 + 0x20) + 0x20) != 0)) {
      FUN_00797ece(*(undefined4 *)param_2);
    }
    pcVar1 = *(code **)(*(int *)in_ECX + 0x184);
    guard_check_icall();
    (*pcVar1)();
    if (param_1 == *(int *)(in_ECX + 0xc0)) {
      pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
      pCVar4 = CWnd::FromHandle(pHVar3);
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,(CObject *)pCVar4
                                 );
      if (pCVar5 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar5 + 0x3e4);
        guard_check_icall();
        iVar6 = (*pcVar1)();
        if (iVar6 != 0) {
          FUN_00797ece(*(undefined4 *)param_2);
        }
        pcVar1 = *(code **)(*(int *)pCVar5 + 0x168);
        guard_check_icall();
        iVar6 = (*pcVar1)();
        if (iVar6 == 0) {
          pHVar3 = GetParent(*(HWND *)(pCVar5 + 0x20));
          pCVar5 = (CObject *)CWnd::FromHandle(pHVar3);
          if (pCVar5 == (CObject *)0x0) {
            return 1;
          }
        }
        RedrawWindow(*(HWND *)(pCVar5 + 0x20),(RECT *)0x0,(HRGN)0x0,0x401);
      }
    }
    return 1;
  }
  return 0;
}




/* vtable slots: CMFCBaseTabCtrl[122], CMFCOutlookBarTabCtrl[122], CMFCTabCtrl[122] */
/* 0080b25d  SetTabTextColor  49 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseTabCtrl::SetTabTextColor(int,unsigned long)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseTabCtrl::SetTabTextColor(CMFCBaseTabCtrl *this,int param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 < 0) || (*(int *)(this + 0xbc) <= param_1)) {
    iVar2 = 0;
  }
  else {
    piVar1 = (int *)FUN_0049a990(param_1);
    *(ulong *)(*piVar1 + 0x2c) = param_2;
    iVar2 = 1;
  }
  return iVar2;
}




/* vtable slots: CMFCBaseTabCtrl[94], CMFCOutlookBarTabCtrl[94] */
/* 0080b28e  SetTabsHeight  62 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCBaseTabCtrl::SetTabsHeight(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCBaseTabCtrl::SetTabsHeight(CMFCBaseTabCtrl *this)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(this + 0xd8) < 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(this + 0xd8) + 7;
  }
  iVar1 = FUN_007c2511();
  if (iVar2 <= *(int *)(iVar1 + 0x1cc) + 5) {
    iVar2 = FUN_007c2511();
    iVar2 = *(int *)(iVar2 + 0x1cc) + 5;
  }
  *(int *)(this + 0x110) = iVar2;
  return;
}




/* vtable slots: CMFCBaseTabCtrl[106], CMFCOutlookBarTabCtrl[106], CMFCTabCtrl[106] */
/* 0080b3a6  FUN_0080b3a6  328 bytes, 0 callers */

undefined4 FUN_0080b3a6(int param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  
  if ((param_1 < 0) || (in_ECX[0x2f] <= param_1)) {
    uVar3 = 0;
  }
  else {
    piVar2 = (int *)FUN_0049a990(param_1);
    iVar6 = *piVar2;
    if (*(int *)(iVar6 + 0x34) == param_2) {
      uVar3 = 1;
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x1a4);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      *(int *)(iVar6 + 0x34) = param_2;
      if (param_2 == 0) {
        if (in_ECX[0x48] != 0) {
          FUN_00797f20(0);
        }
        iVar6 = -1;
        if (param_1 == in_ECX[0x30]) {
          iVar5 = in_ECX[0x2f] + -1;
          if (-1 < iVar5) {
            iVar6 = -1;
            do {
              piVar2 = (int *)FUN_0049a990(iVar5);
              if ((iVar5 < param_1) && (-1 < iVar6)) break;
              if (*(int *)(*piVar2 + 0x34) != 0) {
                iVar6 = iVar5;
              }
              iVar5 = iVar5 + -1;
            } while (-1 < iVar5);
          }
          in_ECX[0x30] = -1;
        }
      }
      else {
        iVar6 = in_ECX[0x30];
        if (iVar4 == 0) {
          iVar6 = param_1;
        }
      }
      if (param_3 != 0) {
        pcVar1 = *(code **)(*in_ECX + 0x184);
        guard_check_icall();
        (*pcVar1)();
      }
      if ((((-1 < iVar6) && (param_2 == 0)) && (in_ECX[0x30] == -1)) ||
         ((param_4 != 0 || (iVar4 == 0)))) {
        pcVar1 = *(code **)(*in_ECX + 0x214);
        guard_check_icall(iVar6);
        (*pcVar1)();
        pcVar1 = *(code **)(*in_ECX + 0x270);
        guard_check_icall(in_ECX[0x30]);
        (*pcVar1)();
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}




/* vtable slots: CMFCBaseTabCtrl[126], CMFCOutlookBarTabCtrl[126], CMFCTabCtrl[126] */
/* 0080b4ee  FUN_0080b4ee  394 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0080b4ee(int param_1)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 *puVar4;
  int iVar5;
  WPARAM wParam;
  HWND pHVar6;
  int *in_ECX;
  LONG local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x80b4fa;
  if ((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) {
    if ((in_ECX[0x55] != 0) && ((-1 < param_1 && (param_1 < in_ECX[0x27])))) {
      iVar2 = FUN_004b0e80(param_1);
      BVar3 = IsRectEmpty((RECT *)(iVar2 + 0x10));
      if (BVar3 == 0) {
        if (in_ECX[0x54] != 0) goto LAB_0080b673;
        puVar4 = (undefined4 *)FUN_0078e624(0x80);
        local_8 = 0;
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          FUN_007907c8();
          *puVar4 = CEdit::vftable;
        }
        local_8 = 0xffffffff;
        in_ECX[0x54] = (int)puVar4;
        local_24 = ((RECT *)(iVar2 + 0x10))->left;
        uStack_20 = *(undefined4 *)(iVar2 + 0x14);
        uStack_1c = *(undefined4 *)(iVar2 + 0x18);
        uStack_18 = *(undefined4 *)(iVar2 + 0x1c);
        pcVar1 = *(code **)(*in_ECX + 0x208);
        guard_check_icall(&local_24);
        (*pcVar1)();
        iVar5 = FUN_00798f4d(0x50800080,&local_24,in_ECX,1);
        if (iVar5 == 0) {
          if ((int *)in_ECX[0x54] != (int *)0x0) {
            pcVar1 = *(code **)(*(int *)in_ECX[0x54] + 4);
            guard_check_icall(1);
            (*pcVar1)();
          }
          in_ECX[0x54] = 0;
        }
        else {
          FUN_00797ece(*(undefined4 *)(iVar2 + 4));
          iVar2 = in_ECX[0x54];
          iVar5 = FUN_007c2511();
          wParam = 0;
          if (iVar5 != -0x11c) {
            wParam = *(WPARAM *)(iVar5 + 0x120);
          }
          SendMessageW(*(HWND *)(iVar2 + 0x20),0x30,wParam,1);
          SendMessageW(*(HWND *)(in_ECX[0x54] + 0x20),0xb1,0,-1);
          FUN_00797df8();
          in_ECX[0x53] = param_1;
          pHVar6 = SetCapture((HWND)in_ECX[8]);
          CWnd::FromHandle(pHVar6);
        }
      }
    }
    FUN_008d9b68();
    return;
  }
LAB_0080b673:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCBaseTabCtrl[152], CMFCOutlookBarTabCtrl[152] */
/* 0080b679  SwapTabs  77 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCBaseTabCtrl::SwapTabs(int,int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCBaseTabCtrl::SwapTabs(CMFCBaseTabCtrl *this,int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_1 < *(int *)(this + 0x9c)) && (param_2 < *(int *)(this + 0x9c))) {
    uVar1 = FUN_004b0e80(param_1);
    uVar2 = FUN_004b0e80(param_2);
    FUN_007a5f21(param_1,uVar2);
    FUN_007a5f21(param_2,uVar1);
  }
  return;
}




/* vtable slots: CMFCBaseTabCtrl[56], CMFCOutlookBarTabCtrl[56], CMFCTabCtrl[56] */
/* 0080b6c6  FUN_0080b6c6  149 bytes, 0 callers */

undefined4 FUN_0080b6c6(short param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  BOOL BVar4;
  int *in_ECX;
  int iVar5;
  int iVar6;
  
  if (param_1 == 3) {
    if (param_3 != 0) {
      iVar5 = 0;
      iVar6 = 0;
      if (0 < in_ECX[0x2f]) {
        do {
          piVar3 = (int *)FUN_0049a990(iVar6);
          if ((*(int *)(*piVar3 + 0x34) != 0) &&
             (BVar4 = IsRectEmpty((RECT *)(*piVar3 + 0x10)), BVar4 == 0)) {
            if (iVar5 == param_3) {
              pcVar1 = *(code **)(*in_ECX + 0x214);
              guard_check_icall(iVar6);
              (*pcVar1)();
              pcVar1 = *(code **)(*in_ECX + 0x270);
              guard_check_icall(in_ECX[0x30]);
              (*pcVar1)();
              break;
            }
            iVar5 = iVar5 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < in_ECX[0x2f]);
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}




/* vtable slots: CMFCBaseTabCtrl[55], CMFCOutlookBarTabCtrl[55], CMFCTabCtrl[55] */
/* 0080b75b  FUN_0080b75b  193 bytes, 0 callers */

undefined4 FUN_0080b75b(LONG param_1,LONG param_2,undefined2 *param_3)

{
  code *pcVar1;
  POINT pt;
  undefined4 uVar2;
  int *piVar3;
  BOOL BVar4;
  int *in_ECX;
  int iVar5;
  tagPOINT local_14;
  int local_c;
  int local_8;
  
  if (param_3 == (undefined2 *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    *param_3 = 3;
    iVar5 = 0;
    local_14.x = param_1;
    local_14.y = param_2;
    *(undefined4 *)(param_3 + 4) = 0;
    ScreenToClient((HWND)in_ECX[8],&local_14);
    if (0 < in_ECX[0x2f]) {
      do {
        piVar3 = (int *)FUN_0049a990(iVar5);
        local_c = *piVar3;
        local_8 = iVar5 + 1;
        pt.y = local_14.y;
        pt.x = local_14.x;
        BVar4 = PtInRect((RECT *)(local_c + 0x10),pt);
        if (BVar4 != 0) {
          *(int *)(param_3 + 4) = local_8;
          pcVar1 = *(code **)(*in_ECX + 0x2d4);
          guard_check_icall(local_c,in_ECX + 0x84,iVar5 == in_ECX[0x30]);
          (*pcVar1)();
          break;
        }
        iVar5 = local_8;
      } while (local_8 < in_ECX[0x2f]);
    }
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCBaseTabCtrl[53], CMFCOutlookBarTabCtrl[53], CMFCTabCtrl[53] */
/* 0080b81c  FUN_0080b81c  244 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0080b81c(int *param_1,int *param_2,int *param_3,int *param_4,short param_5,undefined4 param_6,
            int param_7)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) && (param_3 != (int *)0x0)) &&
     (param_4 != (int *)0x0)) {
    if (param_5 == 3) {
      if (param_7 == 0) {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetWindowRect((HWND)in_ECX[8],&local_18);
        *param_1 = local_18.left;
        *param_2 = local_18.top;
        *param_3 = local_18.right - local_18.left;
        iVar2 = local_18.bottom - local_18.top;
      }
      else {
        if (param_7 < 1) {
          return 0;
        }
        pcVar1 = *(code **)(*in_ECX + 0x2d0);
        guard_check_icall(param_7);
        (*pcVar1)();
        *param_1 = in_ECX[0x8d];
        *param_2 = in_ECX[0x8e];
        *param_3 = in_ECX[0x8f] - in_ECX[0x8d];
        iVar2 = in_ECX[0x90] - in_ECX[0x8e];
      }
      *param_4 = iVar2;
    }
    return 0;
  }
  return 0x80070057;
}




/* vtable slots: CMFCBaseTabCtrl[54], CMFCOutlookBarTabCtrl[54], CMFCTabCtrl[54] */
/* 0080b910  FUN_0080b910  229 bytes, 0 callers */

undefined4
FUN_0080b910(int param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined2 *param_6)

{
  int *piVar1;
  BOOL BVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  
  *param_6 = 0;
  if (param_2 != 3) {
    return 0x80070057;
  }
  iVar3 = 0;
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0xbc)) {
    do {
      piVar1 = (int *)FUN_0049a990(iVar3);
      if ((*(int *)(*piVar1 + 0x34) != 0) &&
         (BVar2 = IsRectEmpty((RECT *)(*piVar1 + 0x10)), BVar2 == 0)) {
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(in_ECX + 0xbc));
  }
  if (param_1 != 3) {
    if ((param_1 == 4) || (param_1 == 5)) {
      if (param_4 == 0) {
        return 1;
      }
      *param_6 = 3;
      *(int *)(param_6 + 4) = param_4 + 1;
      if (param_4 + 1 <= iVar4) {
        return 0;
      }
      goto LAB_0080b9e6;
    }
    if (param_1 != 6) {
      if (param_1 == 7) {
        if (param_4 == 0) {
          *param_6 = 3;
          *(undefined4 *)(param_6 + 4) = 1;
          return 0;
        }
        return 1;
      }
      if (param_1 != 8) {
        return 1;
      }
      if (param_4 != 0) {
        return 1;
      }
      *param_6 = 3;
      *(int *)(param_6 + 4) = iVar4;
      return 0;
    }
  }
  if (param_4 == 0) {
    return 1;
  }
  *param_6 = 3;
  *(int *)(param_6 + 4) = param_4 + -1;
  if (0 < param_4 + -1) {
    return 0;
  }
LAB_0080b9e6:
  *param_6 = 0;
  return 1;
}




/* vtable slots: CMFCBaseTabCtrl[40], CMFCOutlookBarTabCtrl[40], CMFCTabCtrl[40] */
/* 0080b9f5  FUN_0080b9f5  24 bytes, 0 callers */

int FUN_0080b9f5(void)

{
  int in_stack_00000014;
  
  return (-(uint)(in_stack_00000014 != 0) & 0x7ff8ffaa) + 0x80070057;
}




/* vtable slots: CMFCBaseTabCtrl[39], CMFCOutlookBarTabCtrl[39], CMFCTabCtrl[39] */
/* 0080ba0d  get_accChildCount  100 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual long __thiscall CMFCBaseTabCtrl::get_accChildCount(long *)
   
   Library: Visual Studio 2015 Release */

long __thiscall CMFCBaseTabCtrl::get_accChildCount(CMFCBaseTabCtrl *this,long *param_1)

{
  long lVar1;
  int *piVar2;
  BOOL BVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == (long *)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    if (0 < *(int *)(this + 0xbc)) {
      do {
        piVar2 = (int *)FUN_0049a990(iVar5);
        if ((*(int *)(*piVar2 + 0x34) != 0) &&
           (BVar3 = IsRectEmpty((RECT *)(*piVar2 + 0x10)), BVar3 == 0)) {
          iVar4 = iVar4 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(this + 0xbc));
    }
    *param_1 = iVar4;
    lVar1 = 0;
  }
  return lVar1;
}




/* vtable slots: CMFCBaseTabCtrl[51], CMFCOutlookBarTabCtrl[51], CMFCTabCtrl[51] */
/* 0080ba71  FUN_0080ba71  90 bytes, 0 callers */

undefined4
FUN_0080ba71(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (param_1 == 3) {
    if (param_3 == 0) {
      return 1;
    }
  }
  else if (param_3 != 0) {
    return 0x80070057;
  }
  pcVar1 = *(code **)(*in_ECX + 0x2d0);
  guard_check_icall(param_3);
  (*pcVar1)();
  if (*(int *)(in_ECX[0x89] + -0xc) == 0) {
    return 1;
  }
  uVar2 = FUN_007913e5();
  *param_5 = uVar2;
  return 0;
}




/* vtable slots: CMFCBaseTabCtrl[41], CMFCOutlookBarTabCtrl[41], CMFCTabCtrl[41] */
/* 0080bacb  FUN_0080bacb  155 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_0080bacb(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  BSTR pOVar2;
  undefined4 uVar3;
  int *in_ECX;
  OLECHAR *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x80bad7;
  if (param_1 == 3) {
    if (param_3 == 0) {
      CStringT<>();
      local_8 = 0;
      FUN_00792c64(local_14);
      pOVar2 = SysAllocStringLen(local_14[0],*(UINT *)(local_14[0] + -6));
      if (pOVar2 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00407010();
      }
      *param_5 = pOVar2;
      FUN_00406b10();
    }
    else if (0 < param_3) {
      pcVar1 = *(code **)(*in_ECX + 0x2d0);
      guard_check_icall(param_3);
      (*pcVar1)();
      if (*(int *)(in_ECX[0x84] + -0xc) == 0) {
        return 1;
      }
      uVar3 = FUN_007913e5();
      *param_5 = uVar3;
    }
  }
  return 0;
}




/* vtable slots: CMFCBaseTabCtrl[44], CMFCOutlookBarTabCtrl[44], CMFCTabCtrl[44] */
/* 0080bb67  FUN_0080bb67  115 bytes, 0 callers */

undefined4
FUN_0080bb67(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined2 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if ((param_1 == 3) && (param_3 == 0)) {
    *param_5 = 3;
    *(undefined4 *)(param_5 + 4) = 0x3c;
    return 0;
  }
  if (param_5 == (undefined2 *)0x0) {
LAB_0080bbcf:
    uVar2 = 0x80070057;
  }
  else {
    if (param_1 == 3) {
      if (0 < param_3) {
        *param_5 = 3;
        pcVar1 = *(code **)(*in_ECX + 0x2d0);
        guard_check_icall(param_3);
        (*pcVar1)();
        *(int *)(param_5 + 4) = in_ECX[0x8a];
        return 0;
      }
    }
    else if (param_3 != 0) goto LAB_0080bbcf;
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCBaseTabCtrl[45], CMFCOutlookBarTabCtrl[45], CMFCTabCtrl[45] */
/* 0080bbda  FUN_0080bbda  106 bytes, 0 callers */

undefined4
FUN_0080bbda(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined2 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if ((param_1 == 3) && (param_3 == 0)) {
    *(undefined4 *)(param_5 + 4) = 0;
    *param_5 = 3;
    uVar2 = 0;
  }
  else if ((param_5 == (undefined2 *)0x0) || ((param_1 != 3 || (param_3 < 1)))) {
    uVar2 = 0x80070057;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x2d0);
    guard_check_icall(param_3);
    (*pcVar1)();
    *param_5 = 3;
    *(int *)(param_5 + 4) = in_ECX[0x8b];
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCBaseTabCtrl[42], CMFCOutlookBarTabCtrl[42], CMFCTabCtrl[42] */
/* 0080bc44  FUN_0080bc44  111 bytes, 0 callers */

undefined4
FUN_0080bc44(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if (param_1 == 3) {
    if (param_3 < 1) {
      if (param_3 != 0) {
        return 1;
      }
      if (in_ECX[0x30] == -1) {
        return 1;
      }
      piVar2 = (int *)FUN_0049a990(in_ECX[0x30]);
      piVar2 = (int *)(*piVar2 + 4);
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x2d0);
      guard_check_icall(param_3);
      (*pcVar1)();
      piVar2 = in_ECX + 0x85;
    }
    if (*(int *)(*piVar2 + -0xc) != 0) {
      uVar3 = FUN_007913e5();
      *param_5 = uVar3;
      return 0;
    }
  }
  return 1;
}



