/* CMFCOutlookBarTabCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCOutlookBarTabCtrl[172], CMFCTabCtrl[172] */
/* 008104ae  FUN_008104ae  45 bytes, 0 callers */

void FUN_008104ae(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x2b8);
  guard_check_icall(param_1,param_2,param_3,param_4);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCOutlookBarTabCtrl[1] */
/* 00896f4d  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCOutlookBarTabCtrl::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCOutlookBarTabCtrl::_scalar_deleting_destructor_(CMFCOutlookBarTabCtrl *this,uint param_1)

{
  FUN_00896e80();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1f60);
    }
  }
  return this;
}




/* vtable slots: CMFCOutlookBarTabCtrl[130] */
/* 0089721f  FUN_0089721f  20 bytes, 0 callers */

void FUN_0089721f(LPRECT param_1)

{
  InflateRect(param_1,-1,-1);
  return;
}




/* vtable slots: CMFCOutlookBarTabCtrl[187] */
/* 00897251  FUN_00897251  74 bytes, 0 callers */

void FUN_00897251(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = FUN_00791f4f(0,&DAT_00956338,0x56000000,param_1,param_2,param_3,0);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x178);
    guard_check_icall();
    (*pcVar1)();
    in_ECX[0x22] = 1;
  }
  return;
}




/* vtable slots: CMFCOutlookBarTabCtrl[129] */
/* 0089787a  FUN_0089787a  16 bytes, 0 callers */

void FUN_0089787a(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x154) = param_1;
  return;
}




/* vtable slots: CMFCOutlookBarTabCtrl[147] */
/* 00897976  FindTargetWnd  97 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CWnd * __thiscall CMFCOutlookBarTabCtrl::FindTargetWnd(class CPoint const
   &)
   
   Library: Visual Studio 2015 Release */

CWnd * __thiscall CMFCOutlookBarTabCtrl::FindTargetWnd(CMFCOutlookBarTabCtrl *this,CPoint *param_1)

{
  int *piVar1;
  BOOL BVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < *(int *)(this + 0xbc)) {
    do {
      piVar1 = (int *)FUN_0049a990(iVar5);
      if ((*(int *)(*piVar1 + 0x34) != 0) &&
         (BVar2 = PtInRect((RECT *)(*piVar1 + 0x10),*(POINT *)param_1), BVar2 != 0)) {
        return (CWnd *)0x0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(this + 0xbc));
  }
  pHVar3 = GetParent(*(HWND *)(this + 0x20));
  pCVar4 = CWnd::FromHandle(pHVar3);
  return pCVar4;
}




/* vtable slots: CMFCOutlookBarTabCtrl[10] */
/* 008979f0  FUN_008979f0  6 bytes, 0 callers */

undefined ** FUN_008979f0(void)

{
  return &PTR_FUN_0099d4e8;
}




/* vtable slots: CMFCOutlookBarTabCtrl[0] */
/* 00897a02  FUN_00897a02  6 bytes, 0 callers */

undefined ** FUN_00897a02(void)

{
  return &PTR_s_CMFCOutlookBarTabCtrl_0099cee0;
}




/* vtable slots: CMFCOutlookBarTabCtrl[90] */
/* 00897a14  FUN_00897a14  179 bytes, 0 callers */

void FUN_00897a14(LPRECT param_1,LPRECT param_2)

{
  int iVar1;
  BOOL BVar2;
  int in_ECX;
  int iVar3;
  LPRECT ptVar4;
  
  SetRectEmpty(param_1);
  SetRectEmpty(param_2);
  iVar3 = 0;
  if (0 < *(int *)(in_ECX + 0xbc)) {
    do {
      iVar1 = FUN_004b0e80(iVar3);
      ptVar4 = param_1;
      if (iVar3 == 0) {
LAB_00897a61:
        ptVar4->left = *(LONG *)(iVar1 + 0x10);
        ptVar4->top = *(LONG *)(iVar1 + 0x14);
        ptVar4->right = *(LONG *)(iVar1 + 0x18);
        ptVar4->bottom = *(LONG *)(iVar1 + 0x1c);
      }
      else if (param_1->bottom == *(int *)(iVar1 + 0x14)) {
        param_1->bottom = param_1->bottom + (*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x14));
      }
      else {
        BVar2 = IsRectEmpty(param_2);
        ptVar4 = param_2;
        if (BVar2 != 0) goto LAB_00897a61;
        param_2->bottom = param_2->bottom + (*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x14));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(in_ECX + 0xbc));
  }
  FUN_0079e8b8(param_1);
  FUN_0079e8b8(param_2);
  return;
}




/* vtable slots: CMFCOutlookBarTabCtrl[176] */
/* 00897ac7  FUN_00897ac7  21 bytes, 0 callers */

int FUN_00897ac7(int param_1)

{
  int in_ECX;
  
  if (param_1 == -1) {
    param_1 = *(int *)(in_ECX + 0x118);
  }
  return param_1;
}




/* vtable slots: CMFCOutlookBarTabCtrl[89] */
/* 00897b0a  FUN_00897b0a  179 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00897b0a(LONG param_1,LONG param_2)

{
  code *pcVar1;
  POINT pt;
  POINT pt_00;
  BOOL BVar2;
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
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  SetRectEmpty(&local_28);
  pcVar1 = *(code **)(*(int *)in_ECX + 0x168);
  guard_check_icall(&local_18,&local_28);
  (*pcVar1)();
  CWnd::ScreenToClient(in_ECX,&local_18);
  CWnd::ScreenToClient(in_ECX,&local_28);
  pt.y = param_2;
  pt.x = param_1;
  BVar2 = PtInRect(&local_18,pt);
  if ((BVar2 == 0) &&
     (pt_00.y = param_2, pt_00.x = param_1, BVar2 = PtInRect(&local_28,pt_00), BVar2 == 0)) {
    return 0;
  }
  return 1;
}




/* vtable slots: CMFCOutlookBarTabCtrl[124] */
/* 00897bbd  IsTabDetachable  34 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCOutlookBarTabCtrl::IsTabDetachable(int)const 
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCOutlookBarTabCtrl::IsTabDetachable(CMFCOutlookBarTabCtrl *this,int param_1)

{
  int iVar1;
  
  iVar1 = IsMode2003(this);
  if (iVar1 == 0) {
    iVar1 = CMFCBaseTabCtrl::IsTabDetachable((CMFCBaseTabCtrl *)this,param_1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}




/* vtable slots: CMFCOutlookBarTabCtrl[61] */
/* 00897cff  FUN_00897cff  155 bytes, 0 callers */

undefined4 FUN_00897cff(undefined4 param_1,int param_2)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  undefined4 uVar7;
  
  pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCOutlookBar_00a00680,(CObject *)pCVar3);
  if (pCVar4 == (CObject *)0x0) {
LAB_00897d86:
    uVar7 = FUN_00793275(param_1,param_2);
  }
  else {
    iVar6 = 0;
    iVar5 = 0;
    if (in_ECX != -0x1010) {
      iVar5 = *(int *)(in_ECX + 0x1030);
    }
    if (iVar5 == param_2) {
      uVar7 = 0;
    }
    else {
      if (in_ECX != -0x17b8) {
        iVar6 = *(int *)(in_ECX + 0x17d8);
      }
      if (iVar6 != param_2) goto LAB_00897d86;
      uVar7 = 1;
    }
    pcVar1 = *(code **)(*(int *)pCVar4 + 0x3f0);
    guard_check_icall(uVar7);
    (*pcVar1)();
    iVar5 = FUN_00797c32();
    if (iVar5 == 0) {
      FUN_00797df8();
    }
    uVar7 = 1;
  }
  return uVar7;
}




/* vtable slots: CMFCOutlookBarTabCtrl[174] */
/* 00897f78  FUN_00897f78  138 bytes, 0 callers */

char FUN_00897f78(undefined4 param_1,byte param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  piVar2 = (int *)FUN_00880f70(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPaneButton_00a009f8);
    iVar4 = *piVar2;
    if (iVar3 == 0) {
      guard_check_icall(1);
      (**(code **)(iVar4 + 4))();
    }
    else {
      guard_check_icall(1);
      (**(code **)(iVar4 + 4))();
      pcVar1 = *(code **)(*in_ECX + 0x218);
      guard_check_icall(&stack0x0000000c);
      iVar4 = (*pcVar1)();
      if (-1 < iVar4) {
        pcVar1 = *(code **)(*in_ECX + 0x214);
        guard_check_icall(iVar4);
        (*pcVar1)();
        return ((param_2 & 8) == 0) + '\x01';
      }
    }
  }
  return '\0';
}




/* vtable slots: CMFCOutlookBarTabCtrl[183] */
/* 00898e6a  FUN_00898e6a  50 bytes, 0 callers */

void FUN_00898e6a(void)

{
  code *pcVar1;
  int *in_ECX;
  
  in_ECX[0x95] = in_ECX[0x95] + -1;
  in_ECX[0x98] = 1;
  pcVar1 = *(code **)(*in_ECX + 0x184);
  guard_check_icall();
  (*pcVar1)();
  in_ECX[0x98] = 0;
  return;
}




/* vtable slots: CMFCOutlookBarTabCtrl[182] */
/* 00898e9c  FUN_00898e9c  50 bytes, 0 callers */

void FUN_00898e9c(void)

{
  code *pcVar1;
  int *in_ECX;
  
  in_ECX[0x95] = in_ECX[0x95] + 1;
  in_ECX[0x98] = 1;
  pcVar1 = *(code **)(*in_ECX + 0x184);
  guard_check_icall();
  (*pcVar1)();
  in_ECX[0x98] = 0;
  return;
}




/* vtable slots: CMFCOutlookBarTabCtrl[97] */
/* 00899436  FUN_00899436  1514 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00899436(void)

{
  double dVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  HWND pHVar8;
  CWnd *pCVar9;
  CMFCOutlookBarTabCtrl *in_ECX;
  CObject *pCVar10;
  undefined1 local_34 [4];
  LPRECT local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX == (CMFCOutlookBarTabCtrl *)0x0) {
    return;
  }
  if (*(int *)(in_ECX + 0x20) == 0) {
    return;
  }
  if (*(int *)(in_ECX + 0x110) == 0) {
    return;
  }
  local_20 = CMFCOutlookBarTabCtrl::IsMode2003(in_ECX);
  local_28 = 0;
  if (local_20 != 0) {
    if ((in_ECX == (CMFCOutlookBarTabCtrl *)0xfffffd5c) || (*(int *)(in_ECX + 0x2a8) == 0)) {
      pcVar2 = *(code **)(*(int *)in_ECX + 0x238);
      guard_check_icall(local_34);
      iVar5 = (*pcVar2)();
      iVar5 = *(int *)(iVar5 + 4);
    }
    else {
      iVar5 = *(int *)(in_ECX + 0x2a0);
    }
    if (iVar5 == 0) {
      iVar5 = 0x10;
    }
    iVar4 = FUN_007c2511();
    if (*(int *)(iVar4 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar4 + 0x1e0);
    }
    iVar4 = 0xc;
    if (dVar1 != 1.0) {
      iVar4 = thunk_FUN_008d99f0();
    }
    local_28 = iVar4 + iVar5;
  }
  SendMessageW(*(HWND *)(in_ECX + 0x1030),0x1f,0,0);
  SendMessageW(*(HWND *)(in_ECX + 0x17d8),0x1f,0,0);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  InflateRect(&local_18,~*(uint *)(in_ECX + 0x250),~*(uint *)(in_ECX + 0x250));
  *(LONG *)(in_ECX + 0x26c) = local_18.left;
  *(LONG *)(in_ECX + 0x270) = local_18.top;
  *(LONG *)(in_ECX + 0x274) = local_18.right;
  *(LONG *)(in_ECX + 0x278) = local_18.bottom;
  pcVar2 = *(code **)(*(int *)in_ECX + 0x1a4);
  guard_check_icall();
  iVar5 = (*pcVar2)();
  if (local_20 == 0) {
    SetRectEmpty((LPRECT)(in_ECX + 0x27c));
    SetRectEmpty((LPRECT)(in_ECX + 0x28c));
    if (iVar5 < 2) {
      pcVar2 = *(code **)(*(int *)in_ECX + 0x2a0);
      guard_check_icall();
      iVar4 = (*pcVar2)();
      local_24 = local_18.top;
      if (iVar4 != 0) goto LAB_00899682;
    }
    InflateRect((LPRECT)(in_ECX + 0x26c),0,-1);
    local_24 = local_18.top;
  }
  else {
    iVar4 = *(int *)(in_ECX + 0x254);
    if ((iVar4 == -1) || (iVar5 < iVar4)) {
      *(int *)(in_ECX + 0x254) = iVar5;
      iVar4 = iVar5;
    }
    local_1c = (((local_18.bottom - *(int *)(in_ECX + 0x110)) - local_18.top) - local_28) /
               (*(int *)(in_ECX + 0x110) * 2);
    if (iVar5 < local_1c) {
      local_1c = iVar5;
    }
    *(int *)(in_ECX + 600) = local_1c;
    if (iVar4 <= local_1c) {
      local_1c = iVar4;
    }
    *(LONG *)(in_ECX + 0x27c) = local_18.left;
    *(LONG *)(in_ECX + 0x280) = local_18.top;
    *(LONG *)(in_ECX + 0x284) = local_18.right;
    *(LONG *)(in_ECX + 0x288) = local_18.bottom;
    iVar6 = FUN_007c2511();
    iVar3 = DAT_00a00678;
    iVar4 = *(int *)(in_ECX + 0x280);
    iVar6 = *(int *)(iVar6 + 0x1cc);
    *(LONG *)(in_ECX + 0x28c) = local_18.left;
    *(LONG *)(in_ECX + 0x290) = local_18.top;
    *(int *)(in_ECX + 0x280) = iVar4 + 3;
    iVar4 = iVar6 + iVar3 * 2 + iVar4;
    *(LONG *)(in_ECX + 0x294) = local_18.right;
    *(int *)(in_ECX + 0x288) = iVar4;
    *(int *)(in_ECX + 0x270) = iVar4;
    *(LONG *)(in_ECX + 0x298) = local_18.bottom;
    *(int *)(in_ECX + 0x298) =
         *(int *)(in_ECX + 0x298) - (*(int *)(in_ECX + 0x110) * local_1c + local_28);
    *(int *)(in_ECX + 0x290) = *(int *)(in_ECX + 0x298) + -8;
    *(int *)(in_ECX + 0x278) = *(int *)(in_ECX + 0x298) + -8;
    local_24 = *(int *)(in_ECX + 0x298);
  }
LAB_00899682:
  if (iVar5 < 2) {
    pcVar2 = *(code **)(*(int *)in_ECX + 0x2a0);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) goto LAB_00899811;
  }
  local_1c = 0;
  if (0 < *(int *)(in_ECX + 0xbc)) {
    do {
      piVar7 = (int *)FUN_0049a990(local_1c);
      iVar4 = local_24;
      local_2c = *piVar7;
      local_30 = (LPRECT)(local_2c + 0x10);
      local_30->left = local_18.left;
      *(LONG *)(local_2c + 0x14) = local_18.top;
      *(LONG *)(local_2c + 0x18) = local_18.right;
      *(LONG *)(local_2c + 0x1c) = local_18.bottom;
      *(int *)(local_2c + 0x18) = *(int *)(local_2c + 0x18) + 1;
      *(int *)(local_2c + 0x14) = local_24;
      *(int *)(local_2c + 0x1c) = *(int *)(in_ECX + 0x110) + local_24;
      if ((local_18.bottom - local_28 <= local_24) && (local_20 != 0)) {
        SetRectEmpty(local_30);
      }
      if (*(int *)(local_2c + 0x34) == 0) {
        SetRectEmpty(local_30);
      }
      else {
        if (((*(int *)(in_ECX + 0x264) != 0) && (local_20 == 0)) &&
           ((local_1c == *(int *)(in_ECX + 0xc0) || (local_1c == *(int *)(in_ECX + 0xc0) + 1)))) {
          iVar6 = *(int *)(local_2c + 0x18) - *(int *)(in_ECX + 0x110);
          iVar4 = *(int *)(local_2c + 0x18);
          *(int *)(local_2c + 0x18) = iVar6;
          FUN_00797e71(0,iVar6,*(int *)(local_2c + 0x14),iVar4 - iVar6,
                       *(int *)(local_2c + 0x1c) - *(int *)(local_2c + 0x14),0x14);
          iVar4 = local_24;
        }
        if ((local_1c == *(int *)(in_ECX + 0xc0)) && (local_20 == 0)) {
          iVar6 = 0;
          *(int *)(in_ECX + 0x270) = *(int *)(in_ECX + 0x110) + iVar4;
          iVar4 = local_1c;
          while (iVar4 = iVar4 + 1, iVar4 < *(int *)(in_ECX + 0xbc)) {
            piVar7 = (int *)FUN_0049a990(iVar4);
            if (*piVar7 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_0078e714();
            }
            if (*(int *)(*piVar7 + 0x34) != 0) {
              iVar6 = iVar6 + 1;
            }
          }
          local_24 = local_18.bottom - *(int *)(in_ECX + 0x110) * iVar6;
          *(int *)(in_ECX + 0x278) = local_24;
          local_24 = local_24 + 1;
        }
        else {
          local_24 = iVar4 + *(int *)(in_ECX + 0x110);
        }
      }
      local_1c = local_1c + 1;
    } while (local_1c < *(int *)(in_ECX + 0xbc));
  }
LAB_00899811:
  if (((*(int *)(in_ECX + 0x264) != 0) && (local_20 == 0)) &&
     (*(int *)(in_ECX + 0xc0) == iVar5 + -1)) {
    iVar4 = *(int *)(in_ECX + 0x110);
    *(int *)(in_ECX + 0x278) = *(int *)(in_ECX + 0x278) - iVar4;
    FUN_00797e71(0,(local_18.right - iVar4) + 1,(local_18.bottom - iVar4) + 1,iVar4,iVar4,0x15);
  }
  local_30 = (LPRECT)0x0;
  if (0 < *(int *)(in_ECX + 0xbc)) {
    iVar4 = 0;
    do {
      piVar7 = (int *)FUN_0049a990(iVar4);
      pCVar10 = (CObject *)0x0;
      local_2c = *piVar7;
      if (*(int *)(local_2c + 0x34) != 0) {
        local_30 = (LPRECT)AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePaneAdapter_00a00984,
                                              *(CObject **)(local_2c + 0x20));
        if (local_30 != (LPRECT)0x0) {
          pcVar2 = *(code **)(*(int *)local_30 + 0x3a4);
          guard_check_icall();
          pCVar10 = (CObject *)(*pcVar2)();
          pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCOutlookBarPane_00a006a0,pCVar10);
          if (pCVar10 != (CObject *)0x0) {
            *(int *)(pCVar10 + 0x1dbc) = *(int *)(in_ECX + 0x274) - *(int *)(in_ECX + 0x26c);
            *(int *)(pCVar10 + 0xc08) = *(int *)(in_ECX + 0x278) - *(int *)(in_ECX + 0x270);
            if (*(int *)(in_ECX + 0x260) != 0) {
              *(undefined4 *)(pCVar10 + 0x1dd8) = 1;
            }
          }
        }
        FUN_00797e71(0,*(int *)(in_ECX + 0x26c),*(int *)(in_ECX + 0x270),
                     *(int *)(in_ECX + 0x274) - *(int *)(in_ECX + 0x26c),
                     *(int *)(in_ECX + 0x278) - *(int *)(in_ECX + 0x270),0x14);
        if (pCVar10 != (CObject *)0x0) {
          *(undefined4 *)(pCVar10 + 0x1dd8) = 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0xbc));
  }
  if ((iVar5 == 0) && (local_20 == 0)) {
    FUN_00797f20(0);
  }
  else {
    RedrawWindow(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,(HRGN)0x0,0x585);
    if (local_20 != 0) {
      FUN_00797f20(4);
      pcVar2 = *(code **)(*(int *)(in_ECX + 0x2b0) + 0x238);
      guard_check_icall(0,local_18.left,local_18.bottom - local_28,local_18.right - local_18.left,
                        local_28,0x14,0);
      (*pcVar2)();
      FUN_008990aa();
      return;
    }
  }
  FUN_00797f20(0);
  RedrawWindow(*(HWND *)(in_ECX + 0x1030),(RECT *)0x0,(HRGN)0x0,0x105);
  RedrawWindow(*(HWND *)(in_ECX + 0x17d8),(RECT *)0x0,(HRGN)0x0,0x105);
  pHVar8 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar9 = CWnd::FromHandle(pHVar8);
  RedrawWindow(*(HWND *)(pCVar9 + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
  return;
}



