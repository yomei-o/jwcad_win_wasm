/* CMFCMenuBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCMenuBar[1] */
/* 008872cf  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCMenuBar::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCMenuBar::_scalar_deleting_destructor_(CMFCMenuBar *this,uint param_1)

{
  FUN_00887224();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xd90);
    }
  }
  return this;
}




/* vtable slots: CMFCMenuBar[249] */
/* 00887302  FUN_00887302  460 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00887302(void)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint dx;
  int *in_ECX;
  uint dy;
  int local_44;
  int local_40;
  int local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar4 = FUN_00888170();
  if (iVar4 != 0) {
    FUN_00805aeb(0);
  }
  FUN_007fb67f();
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  GetClientRect((HWND)in_ECX[8],&local_28);
  local_44 = local_28.right;
  pcVar1 = *(code **)(*in_ECX + 0x194);
  guard_check_icall();
  uVar5 = (*pcVar1)();
  uVar5 = uVar5 & 0xa000;
  if (in_ECX[0x35c] != 0) {
    uVar2 = in_ECX[0x35f];
    uVar3 = in_ECX[0x360];
    local_18.left = local_28.left;
    local_2c = in_ECX[0x311];
    local_18.top = local_28.top;
    local_18.right = local_28.right;
    local_18.bottom = local_28.bottom;
    SetRectEmpty(&local_28);
    FUN_007ef36a(&local_28,uVar5 != 0);
    if (uVar5 == 0) {
      local_18.bottom = local_18.bottom + (local_28.bottom - local_28.top);
    }
    local_18.left = local_18.right - uVar2;
    local_18.top = local_18.bottom - uVar3;
    if (in_ECX[0x345] != 0) {
      FUN_0049ad10(&local_2c);
    }
    local_40 = 0;
    if (0 < in_ECX[0x359]) {
      do {
        if (local_2c == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        FUN_0049ad10(&local_2c);
        FUN_0080554f(local_18.left,local_18.top,local_18.right,local_18.bottom);
        local_44 = local_18.left;
        if (uVar5 == 0) {
          dy = ~uVar3;
          dx = 0;
        }
        else {
          dy = 0;
          dx = ~uVar2;
        }
        OffsetRect(&local_18,dx,dy);
        local_40 = local_40 + 1;
      } while (local_40 < in_ECX[0x359]);
    }
  }
  if (iVar4 != 0) {
    FUN_00805aeb(1);
    local_18.left = *(int *)(iVar4 + 0x54);
    local_18.top = *(LONG *)(iVar4 + 0x58);
    local_18.right = *(int *)(iVar4 + 0x5c);
    local_18.bottom = *(LONG *)(iVar4 + 0x60);
    if (uVar5 == 0) {
      SetRectEmpty(&local_18);
    }
    else {
      local_18.right = local_44;
      local_18.left = local_44 - in_ECX[0x35b];
    }
    FUN_0080554f(local_18.left,local_18.top,local_18.right,local_18.bottom);
  }
  return;
}




/* vtable slots: CMFCMenuBar[270] */
/* 008874f0  FUN_008874f0  460 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008874f0(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  CObject *pCVar5;
  UINT UVar6;
  HMENU pHVar7;
  int in_ECX;
  undefined **local_30;
  HMENU local_2c;
  int local_28;
  int local_24;
  int local_20;
  CMenu *local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x8874fc;
  iVar4 = *(int *)(in_ECX + 0xc64);
  while (iVar4 != 0) {
    piVar3 = (int *)FUN_007a1b17();
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    iVar4 = *(int *)(in_ECX + 0xc64);
  }
  iVar4 = FUN_0079dd6d();
  pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CWinAppEx_0098fd18,*(CObject **)(iVar4 + 4));
  if ((pCVar5 != (CObject *)0x0) && (*(int *)(pCVar5 + 0x10c) != 0)) {
    local_2c = (HMENU)0x0;
    local_30 = CMenu::vftable;
    local_8._0_1_ = 0;
    local_8._1_3_ = 0;
    iVar4 = FUN_004fd4f0(param_1);
    if (iVar4 != 0) {
      local_20 = GetMenuItemCount(local_2c);
      local_14 = 0;
      if (0 < local_20) {
        do {
          UVar6 = GetMenuItemID(local_2c,local_14);
          CStringT<>();
          uVar2 = local_18;
          local_8._0_1_ = 2;
          if (UVar6 == 0) {
            local_28 = FUN_0078e624(0x70);
            local_8._0_1_ = 3;
            if (local_28 == 0) {
              pCVar5 = (CObject *)0x0;
            }
            else {
              pCVar5 = (CObject *)FUN_00880e44();
            }
            local_8._0_1_ = 2;
            if (pCVar5 == (CObject *)0x0) {
LAB_008876b7:
                    /* WARNING: Subroutine does not return */
              FUN_0078e714();
            }
            *(undefined4 *)(pCVar5 + 0x24) = 1;
          }
          else if (UVar6 == 0xffffffff) {
            pHVar7 = GetSubMenu(local_2c,local_14);
            local_1c = CMenu::FromHandle(pHVar7);
            if (local_1c == (CMenu *)0x0) goto LAB_008876b7;
            pCVar5 = (CObject *)FUN_0079d90c();
            FUN_00876bb3(0,*(undefined4 *)(local_1c + 4),0xffffffff,uVar2,0);
          }
          else {
            local_24 = FUN_0078e624(0x70);
            local_8._0_1_ = 4;
            if (local_24 == 0) {
              pCVar5 = (CObject *)0x0;
            }
            else {
              pCVar5 = (CObject *)FUN_00880d51(UVar6,0xffffffff,uVar2,0,0);
            }
            local_8._0_1_ = 2;
          }
          CObList::AddTail((CObList *)(in_ECX + 0xc58),pCVar5);
          FUN_00406b10();
          local_14 = local_14 + 1;
        } while (local_14 < local_20);
      }
      local_8 = 5;
      local_30 = CMenu::vftable;
      CMenu::DestroyMenu((CMenu *)&local_30);
      return 1;
    }
    local_8 = 1;
    local_30 = CMenu::vftable;
    CMenu::DestroyMenu((CMenu *)&local_30);
  }
  return 0;
}




/* vtable slots: CMFCMenuBar[152] */
/* 008876bd  FUN_008876bd  81 bytes, 0 callers */

undefined4 FUN_008876bd(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX[0x312] == 0) {
    FUN_007c23d4(param_1);
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x3b8);
    guard_check_icall(param_1,param_2 != 0 | -(param_3 != 0) & 2U,0xffffffff);
    (*pcVar1)();
  }
  return param_1;
}




/* vtable slots: CMFCMenuBar[238] */
/* 0088770e  FUN_0088770e  520 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_0088770e(int *param_1,uint param_2,undefined4 param_3)

{
  code *pcVar1;
  CMFCToolBarButton *this;
  undefined4 *puVar2;
  int iVar3;
  BOOL BVar4;
  CWnd *pCVar5;
  int iVar6;
  int *piVar7;
  CWnd *in_ECX;
  undefined4 uVar8;
  undefined1 local_30 [4];
  uint local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar8 = 0xffffffff;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x3b0);
  guard_check_icall(0xffffffff);
  (*pcVar1)();
  local_2c = *(uint *)(in_ECX + 0xc40);
  *(undefined4 *)(in_ECX + 0xd74) = 0;
  do {
    if (local_2c == 0) goto LAB_008877a6;
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_2c);
    this = (CMFCToolBarButton *)*puVar2;
    iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBarMenuButtonsButton_0099bc48);
  } while ((((iVar3 != 0) ||
            (iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBarSystemMenuButton_00a00b28), iVar3 != 0)) ||
           (*(int *)(this + 0xc) == 0)) ||
          (iVar3 = CMFCToolBarButton::IsDrawImage(this), iVar3 == 0));
  *(undefined4 *)(in_ECX + 0xd74) = 1;
LAB_008877a6:
  local_2c = param_2 & 0x12;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x170);
  guard_check_icall(uVar8);
  iVar3 = (*pcVar1)();
  if ((iVar3 == 0) && (*(int *)(in_ECX + 0x178) != 0)) {
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    SetRectEmpty(&local_28);
    if (*(CDockingPanesRow **)(in_ECX + 0xbc) != (CDockingPanesRow *)0x0) {
      CDockingPanesRow::GetClientRect(*(CDockingPanesRow **)(in_ECX + 0xbc),(CRect *)&local_28);
    }
    BVar4 = IsRectEmpty(&local_28);
    if (BVar4 != 0) {
      pCVar5 = CWnd::GetOwner(in_ECX);
      GetClientRect(*(HWND *)(pCVar5 + 0x20),&local_28);
    }
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    SetRectEmpty(&local_18);
    FUN_007ef36a(&local_18,param_2 & 2);
    if (local_2c == 2) {
      FUN_00806771(local_28.right + -1 + ((local_18.right - local_18.left) - local_28.left),0x7fff,0
                   ,0xffffffff,0xffffffff);
      pcVar1 = *(code **)(*(int *)in_ECX + 0x2a4);
      guard_check_icall(local_30,0);
      iVar6 = (*pcVar1)();
      iVar3 = (local_28.right - (local_18.right - local_18.left) / 2) - local_28.left;
      iVar6 = *(int *)(iVar6 + 4) + (local_18.top - local_18.bottom);
    }
    else {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x2a4);
      guard_check_icall(local_30,1);
      piVar7 = (int *)(*pcVar1)();
      iVar6 = (local_28.bottom - (local_18.bottom - local_18.top) / 2) - local_28.top;
      iVar3 = *piVar7 + (local_18.left - local_18.right);
    }
    FUN_00803951();
    *param_1 = iVar3;
    param_1[1] = iVar6;
  }
  else {
    FUN_007fc0ba(param_1,param_2,param_3);
  }
  return param_1;
}




/* vtable slots: CMFCMenuBar[263] */
/* 00887916  FUN_00887916  137 bytes, 0 callers */

void FUN_00887916(void)

{
  CMFCToolBarButton *this;
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int *in_ECX;
  int local_8;
  
  local_8 = in_ECX[0x310];
  in_ECX[0x35d] = 0;
  do {
    if (local_8 == 0) goto LAB_00887987;
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    this = (CMFCToolBarButton *)*puVar2;
    iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBarMenuButtonsButton_0099bc48);
  } while ((((iVar3 != 0) ||
            (iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBarSystemMenuButton_00a00b28), iVar3 != 0)) ||
           (*(int *)(this + 0xc) == 0)) ||
          (iVar3 = CMFCToolBarButton::IsDrawImage(this), iVar3 == 0));
  in_ECX[0x35d] = 1;
LAB_00887987:
  pcVar1 = *(code **)(*in_ECX + 0x354);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCMenuBar[200] */
/* 00887ab6  FUN_00887ab6  28 bytes, 0 callers */

void FUN_00887ab6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xd48) = param_1;
  FUN_007fc712(param_1,param_2,param_3);
  return;
}




/* vtable slots: CMFCMenuBar[201] */
/* 00887ad2  CreateEx  47 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCMenuBar::CreateEx(class CWnd *,unsigned long,unsigned
   long,class CRect,unsigned int)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCMenuBar::CreateEx
          (CMFCMenuBar *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9)

{
  int iVar1;
  
  *(undefined4 *)(this + 0xd48) = param_1;
  iVar1 = FUN_007fc878(param_1,param_2,param_3,param_5,param_6,param_7,param_8,param_9);
  return iVar1;
}




/* vtable slots: CMFCMenuBar[269] */
/* 00887b01  FUN_00887b01  1038 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00887b01(HMENU__ *param_1,int param_2,int param_3)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  int iVar4;
  undefined4 uVar5;
  CMenu *pCVar6;
  UINT UVar7;
  HMENU pHVar8;
  CMenu *pCVar9;
  int *piVar10;
  CObject *this;
  CMDIChildWnd *pCVar11;
  CWnd *in_ECX;
  HMENU__ *pHVar12;
  int iVar13;
  int in_stack_fffffe5c;
  UINT in_stack_fffffe60;
  HMENU local_18c;
  undefined4 local_184;
  undefined4 local_180;
  undefined1 local_17c [248];
  CMFCToolBarButton local_84 [8];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x184;
  local_8 = 0x887b10;
  iVar13 = 0;
  if (*(int *)(in_ECX + 0xd8c) == 0) {
LAB_00887f0a:
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pHVar2 = GetFocus();
  pCVar3 = CWnd::FromHandle(pHVar2);
  if (pCVar3 == in_ECX) {
    FUN_0079296c();
    FUN_00797df8();
  }
  pHVar12 = *(HMENU__ **)(in_ECX + 0xd4c);
  if (((pHVar12 == param_1) && (DAT_00a127ac == 0)) && (param_3 == 0)) {
    if (*(int *)(in_ECX + 0xd70) != 0) {
      FUN_008896a2(0,0,0);
      FUN_008896a2(1,0,0);
      FUN_007fe655(0);
      if (0 < *(int *)(in_ECX + 0xd64)) {
        do {
          iVar4 = FUN_007fdf7c();
          FUN_007fe655((iVar4 - iVar13) + -1);
          iVar13 = iVar13 + 1;
        } while (iVar13 < *(int *)(in_ECX + 0xd64));
      }
    }
  }
  else {
    if ((DAT_00a13c78 != 0) && (pHVar12 != (HMENU__ *)0x0)) {
      FUN_0089df10(pHVar12);
      pHVar12 = *(HMENU__ **)(in_ECX + 0xd4c);
    }
    FUN_0082ba9e(pHVar12);
    iVar13 = *(int *)(in_ECX + 0xd70);
    *(int *)(in_ECX + 0xd70) = 0;
    *(HMENU__ **)(in_ECX + 0xd4c) = param_1;
    if (param_2 != 0) {
      *(HMENU__ **)(in_ECX + 0xd50) = param_1;
    }
    pcVar1 = *(code **)(*(int *)in_ECX + 0x194);
    guard_check_icall();
    uVar5 = (*pcVar1)();
    iVar4 = FUN_0082b8fd(param_1,in_ECX);
    if ((iVar4 == 0) || (param_3 != 0)) {
      pCVar6 = CMenu::FromHandle(param_1);
      if (pCVar6 == (CMenu *)0x0) goto LAB_00887f02;
      if (DAT_00a13c78 != 0) {
        FUN_0089e04b(param_1);
      }
      pcVar1 = *(code **)(*(int *)in_ECX + 0x350);
      guard_check_icall();
      (*pcVar1)();
      iVar4 = GetMenuItemCount(*(HMENU *)(pCVar6 + 4));
      local_18c = (HMENU)0x0;
      if (0 < iVar4) {
        do {
          UVar7 = GetMenuItemID(*(HMENU *)(pCVar6 + 4),(int)local_18c);
          CStringT<>();
          local_8 = 0;
          FID_conflict_GetMenuStringA
                    (local_18c,(UINT)&local_180,(LPSTR)0x400,in_stack_fffffe5c,in_stack_fffffe60);
          if (UVar7 == 0) {
            pcVar1 = *(code **)(*(int *)in_ECX + 0x348);
            guard_check_icall(0xffffffff);
            (*pcVar1)();
          }
          else if (UVar7 == 0xffffffff) {
            pHVar8 = GetSubMenu(*(HMENU *)(pCVar6 + 4),(int)local_18c);
            pCVar9 = CMenu::FromHandle(pHVar8);
            if (pCVar9 == (CMenu *)0x0) goto LAB_00887f0a;
            local_184 = 0;
            if (DAT_00a13c78 != 0) {
              local_184 = FUN_0089de66(&local_180);
            }
            piVar10 = (int *)FUN_0079d90c();
            FUN_00876bb3(0,*(undefined4 *)(pCVar9 + 4),0xffffffff,local_180,0);
            piVar10[3] = 0;
            piVar10[2] = 1;
            pcVar1 = *(code **)(*piVar10 + 0xf8);
            guard_check_icall(local_184);
            (*pcVar1)();
            pcVar1 = *(code **)(*(int *)in_ECX + 0x344);
            guard_check_icall(piVar10,0xffffffff);
            (*pcVar1)();
            pcVar1 = *(code **)(*piVar10 + 4);
            guard_check_icall(1);
            (*pcVar1)();
          }
          else {
            FUN_00880d51(UVar7,0xffffffff,local_180,0,0);
            local_78 = 0;
            local_8 = CONCAT31(local_8._1_3_,1);
            pcVar1 = *(code **)(*(int *)in_ECX + 0x344);
            local_7c = 1;
            guard_check_icall(local_84,0xffffffff);
            (*pcVar1)();
            CMFCToolBarButton::~CMFCToolBarButton(local_84);
          }
          local_8 = 0xffffffff;
          FUN_00406b10();
          local_18c = (HMENU)((int)&local_18c->unused + 1);
        } while ((int)local_18c < iVar4);
      }
      if ((*(int *)(in_ECX + 0xd60) != 0) &&
         (iVar4 = FUN_007fc6bf(*(int *)(in_ECX + 0xd60),0), iVar4 < 0)) {
        FUN_008870fc(*(int *)(in_ECX + 0xd60),*(int *)(in_ECX + 0xd6c),*(int *)(in_ECX + 0xd84));
        local_8 = 2;
        pcVar1 = *(code **)(*(int *)in_ECX + 0x344);
        guard_check_icall(local_17c,0xffffffff);
        (*pcVar1)();
        local_8 = 0xffffffff;
        FUN_0088720b();
      }
    }
    else {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x1e0);
      guard_check_icall(uVar5);
      (*pcVar1)();
    }
    if ((iVar13 != 0) &&
       (this = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWnd_0099f564,
                                  *(CObject **)(in_ECX + 0xd48)), this != (CObject *)0x0)) {
      uVar5 = 1;
      pCVar11 = CMDIFrameWnd::MDIGetActive((CMDIFrameWnd *)this,(int *)0x0);
      FUN_008896a2(1,pCVar11,uVar5);
    }
    if (*(int *)(in_ECX + 0x20) != 0) {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x20c);
      guard_check_icall();
      (*pcVar1)();
    }
    FUN_00803951();
  }
  if (*(int *)(in_ECX + 0x178) == 0) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x2d4);
    guard_check_icall(1);
    (*pcVar1)();
  }
LAB_00887f02:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCMenuBar[248] */
/* 00887f10  FUN_00887f10  188 bytes, 0 callers */

int FUN_00887f10(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_007fda05(param_1,param_2,param_3);
  if ((*(int *)(in_ECX + 0xd70) != 0) && (-1 < iVar1)) {
    if ((iVar1 == 0) && (*(int *)(in_ECX + 0xd54) != 0)) {
      return -1;
    }
    iVar2 = FUN_007fdf7c();
    if (iVar2 - *(int *)(in_ECX + 0xd64) < iVar1) {
      iVar2 = *(int *)(in_ECX + 0xd64);
      iVar1 = FUN_007fdf7c();
      iVar1 = iVar1 - iVar2;
      if (0 < iVar2) {
        iVar2 = FUN_007fde79(iVar1 + -1);
        FUN_007fda05(*(undefined4 *)(iVar2 + 0x5c),
                     (*(int *)(iVar2 + 0x60) - *(int *)(iVar2 + 0x58)) / 2 + *(int *)(iVar2 + 0x58),
                     param_3);
      }
    }
  }
  if (((*(int *)(in_ECX + 0xd60) != 0) &&
      (iVar2 = FUN_007fc6bf(*(int *)(in_ECX + 0xd60),0), -1 < iVar2)) && (iVar2 < iVar1)) {
    iVar1 = iVar2;
  }
  return iVar1;
}




/* vtable slots: CMFCMenuBar[158] */
/* 00888066  FUN_00888066  20 bytes, 0 callers */

undefined4 FUN_00888066(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x178) != 0) {
    return 0xffff;
  }
  uVar1 = FUN_007f00ee();
  return uVar1;
}




/* vtable slots: CMFCMenuBar[214] */
/* 0088807a  GetColumnWidth  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCMenuBar::GetColumnWidth(void)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

int __thiscall CMFCMenuBar::GetColumnWidth(CMFCMenuBar *this)

{
  int *piVar1;
  int iVar2;
  CMFCMenuBar *local_c;
  CMFCMenuBar *pCStack_8;
  
  if (*(int *)(this + 0xd74) != 0) {
    local_c = this;
    pCStack_8 = this;
    piVar1 = (int *)FUN_007c23d4(&local_c);
    return *piVar1;
  }
  iVar2 = DAT_00a00620;
  if (DAT_00a00620 < 1) {
    iVar2 = DAT_00a00610;
  }
  return iVar2 + -2;
}




/* vtable slots: CMFCMenuBar[10] */
/* 008881c2  FUN_008881c2  6 bytes, 0 callers */

undefined ** FUN_008881c2(void)

{
  return &PTR_FUN_0099b2e0;
}




/* vtable slots: CMFCMenuBar[213] */
/* 008881c8  FUN_008881c8  206 bytes, 0 callers */

int FUN_008881c8(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *in_ECX;
  undefined1 local_18 [8];
  undefined1 local_10 [8];
  int local_8;
  
  if (in_ECX[0x35d] == 0) {
    iVar2 = DAT_00a00624;
    if (DAT_00a00624 < 1) {
      iVar2 = DAT_00a00614;
    }
    iVar2 = iVar2 + -2;
  }
  else {
    iVar2 = FUN_007c23d4(local_10);
    iVar2 = *(int *)(iVar2 + 4);
  }
  local_8 = FUN_007c2511();
  pcVar1 = *(code **)(*in_ECX + 0x194);
  guard_check_icall();
  uVar3 = (*pcVar1)();
  if ((uVar3 & 0xa000) == 0) {
    iVar4 = *(int *)(local_8 + 0x1d0);
  }
  else {
    iVar4 = *(int *)(local_8 + 0x1cc);
  }
  if (iVar2 < iVar4) {
    iVar2 = FUN_007c2511();
    pcVar1 = *(code **)(*in_ECX + 0x194);
    guard_check_icall();
    uVar3 = (*pcVar1)();
    if ((uVar3 & 0xa000) == 0) {
      iVar2 = *(int *)(iVar2 + 0x1d0);
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x1cc);
    }
  }
  else if (in_ECX[0x35d] == 0) {
    iVar2 = DAT_00a00624;
    if (DAT_00a00624 < 1) {
      iVar2 = DAT_00a00614;
    }
    iVar2 = iVar2 + -2;
  }
  else {
    iVar2 = FUN_007c23d4(local_18);
    iVar2 = *(int *)(iVar2 + 4);
  }
  return iVar2;
}




/* vtable slots: CMFCMenuBar[0] */
/* 0088829c  FUN_0088829c  6 bytes, 0 callers */

undefined ** FUN_0088829c(void)

{
  return &PTR_s_CMFCMenuBar_00a00b00;
}




/* vtable slots: CMFCMenuBar[259] */
/* 008882cd  IsPureMenuButton  41 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CMFCMenuBar::IsPureMenuButton(class CMFCToolBarButton *)const 
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCMenuBar::IsPureMenuButton(CMFCMenuBar *this,CMFCToolBarButton *param_1)

{
  int iVar1;
  
  if ((*(int *)(this + 0xbac) == 0) &&
     (iVar1 = FUN_0079d98a(&PTR_s_CMFCToolBarMenuButton_00a00a14), iVar1 == 0)) {
    return 0;
  }
  return 1;
}




/* vtable slots: CMFCMenuBar[139] */
/* 008882f6  FUN_008882f6  767 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008882f6(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  CWnd *pCVar5;
  WPARAM wParam;
  int *piVar6;
  CWnd *in_ECX;
  uint uVar7;
  int local_1c;
  WPARAM local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x888302;
  if (*(int *)(in_ECX + 0xd50) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  FUN_008592c1(local_14,L"MenuBar",param_1);
  iVar1 = *(int *)(in_ECX + 0xd70);
  local_8 = 0;
  FUN_008896a2(0,0,0);
  iVar3 = FUN_0079dd6d();
  piVar6 = *(int **)(*(int *)(iVar3 + 4) + 0x5c);
  if ((*(int *)(in_ECX + 0xd40) != 0) && (piVar6 != (int *)0x0)) {
    pcVar2 = *(code **)(*piVar6 + 0x10);
    guard_check_icall();
    local_1c = (*pcVar2)();
    while (local_1c != 0) {
      pcVar2 = *(code **)(*piVar6 + 0x14);
      guard_check_icall(&local_1c);
      iVar3 = (*pcVar2)();
      iVar4 = FUN_0079d98a(&PTR_s_CMultiDocTemplate_0099f534);
      if ((iVar4 != 0) && (*(int *)(iVar3 + 0x88) != 0)) {
        local_18 = *(WPARAM *)(iVar3 + 0x54);
        pcVar2 = *(code **)(*(int *)in_ECX + 0x438);
        guard_check_icall(local_18);
        (*pcVar2)();
        iVar4 = FUN_007fedee(local_14[0],param_2,local_18);
        if ((iVar4 == 0) || (*(int *)(in_ECX + 0xb90) != 0)) {
          pCVar5 = CWnd::GetOwner(in_ECX);
          if ((pCVar5 != (CWnd *)0x0) && (*(int *)(pCVar5 + 0x20) != 0)) {
            *(undefined4 *)(in_ECX + 0xd4c) = 0;
            pcVar2 = *(code **)(*(int *)in_ECX + 0x434);
            guard_check_icall(*(undefined4 *)(iVar3 + 0x88),0,0);
            (*pcVar2)();
            pCVar5 = CWnd::GetOwner(in_ECX);
            SendMessageW(*(HWND *)(pCVar5 + 0x20),DAT_00a127d4,local_18,0);
            FUN_0082ba9e(*(undefined4 *)(iVar3 + 0x88));
            *(undefined4 *)(in_ECX + 0xd4c) = *(undefined4 *)(iVar3 + 0x88);
          }
        }
        else {
          FUN_0082ba9e(*(undefined4 *)(iVar3 + 0x88));
        }
      }
    }
  }
  pcVar2 = *(code **)(*(int *)in_ECX + 0x438);
  guard_check_icall(*(undefined4 *)(in_ECX + 0xd5c));
  (*pcVar2)();
  iVar3 = FUN_007fedee(local_14[0],param_2,0);
  if ((iVar3 == 0) || (*(int *)(in_ECX + 0xb90) != 0)) {
    pCVar5 = CWnd::GetOwner(in_ECX);
    if ((pCVar5 != (CWnd *)0x0) && (*(int *)(pCVar5 + 0x20) != 0)) {
      pcVar2 = *(code **)(*(int *)in_ECX + 0x434);
      *(undefined4 *)(in_ECX + 0xd4c) = 0;
      guard_check_icall(*(undefined4 *)(in_ECX + 0xd50),1,0);
      (*pcVar2)();
      wParam = *(WPARAM *)(in_ECX + 0xd5c);
      if (wParam == 0) {
        pCVar5 = CWnd::GetOwner(in_ECX);
        wParam = SendMessageW(*(HWND *)(pCVar5 + 0x20),0x366,0,0);
      }
      pCVar5 = CWnd::GetOwner(in_ECX);
      SendMessageW(*(HWND *)(pCVar5 + 0x20),DAT_00a127d4,wParam,0);
      FUN_0082ba9e(*(undefined4 *)(in_ECX + 0xd50));
      *(undefined4 *)(in_ECX + 0xd4c) = *(undefined4 *)(in_ECX + 0xd50);
    }
  }
  else {
    FUN_0082ba9e(*(undefined4 *)(in_ECX + 0xd50));
  }
  if ((*(int *)(in_ECX + 0xd4c) == 0) ||
     (iVar3 = FUN_0082b8fd(*(int *)(in_ECX + 0xd4c),in_ECX), iVar3 == 0)) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  if (iVar1 != 0) {
    FUN_00888e54(uVar7 ^ 1);
  }
  if (uVar7 != 0) {
    piVar6 = (int *)FUN_0079296c();
    pcVar2 = *(code **)(*piVar6 + 0x178);
    guard_check_icall(1);
    (*pcVar2)();
    InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,1);
    UpdateWindow(*(HWND *)(in_ECX + 0x20));
  }
  pcVar2 = *(code **)(*(int *)in_ECX + 0x20c);
  guard_check_icall();
  (*pcVar2)();
  FUN_00803951();
  FUN_00406b10();
  return 1;
}




/* vtable slots: CMFCMenuBar[236] */
/* 008885f6  FUN_008885f6  115 bytes, 0 callers */

void FUN_008885f6(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_007ff92c(param_1);
  KillTimer((HWND)in_ECX[8],0xec12);
  iVar2 = FUN_007fdf83(0);
  if (iVar2 == 0) {
    DAT_00a13c24 = 0;
  }
  else {
    SetTimer((HWND)in_ECX[8],0xec12,5000,(TIMERPROC)0x0);
  }
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x19c) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x25c);
    guard_check_icall(in_ECX[0x2fc]);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCMenuBar[250] */
/* 008888d7  OnSendCommand  124 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCMenuBar::OnSendCommand(class CMFCToolBarButton const *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCMenuBar::OnSendCommand(CMFCMenuBar *this,CMFCToolBarButton *param_1)

{
  CObject *pCVar1;
  CObject *this_00;
  CMDIChildWnd *pCVar2;
  int iVar3;
  
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButtonsButton_0099bc48,
                              (CObject *)param_1);
  iVar3 = 0;
  if (pCVar1 != (CObject *)0x0) {
    if (((*(int *)(pCVar1 + 0x70) == 0xf060) || (*(int *)(pCVar1 + 0x70) == 0xf020)) ||
       (*(int *)(pCVar1 + 0x70) == 0xf120)) {
      this_00 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWnd_0099f564,
                                   *(CObject **)(this + 0xd48));
      if (this_00 == (CObject *)0x0) {
        MessageBeep(0xffffffff);
      }
      else {
        pCVar2 = CMDIFrameWnd::MDIGetActive((CMDIFrameWnd *)this_00,(int *)0x0);
        SendMessageW(*(HWND *)(pCVar2 + 0x20),0x112,*(WPARAM *)(pCVar1 + 0x70),0);
      }
    }
    iVar3 = 1;
  }
  return iVar3;
}




/* vtable slots: CMFCMenuBar[232] */
/* 00888953  FUN_00888953  99 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00888953(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  CSimpleStringT<wchar_t,0> local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x88895f;
  CStringT<>();
  local_8 = 0;
  iVar1 = FUN_00887fcc(*(undefined4 *)(in_ECX + 0xd4c),*(undefined4 *)(param_1 + 0x20),local_14);
  if (iVar1 == 0) {
    uVar2 = FUN_008027e8(param_1);
  }
  else {
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(param_1 + 0x2c),local_14);
    uVar2 = 1;
  }
  FUN_00406b10();
  return uVar2;
}




/* vtable slots: CMFCMenuBar[29] */
/* 00888ae6  FUN_00888ae6  93 bytes, 0 callers */

undefined4 FUN_00888ae6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x390);
  guard_check_icall(param_1,param_2);
  iVar2 = (*pcVar1)();
  if (iVar2 == -1) {
LAB_00888b2d:
    uVar3 = FUN_00802ae4(param_1,param_2,param_3);
  }
  else {
    iVar2 = FUN_007fde79(iVar2);
    if (iVar2 != 0) {
      iVar2 = FUN_0079d98a(&PTR_s_CMFCToolBarMenuButton_00a00a14);
      if (iVar2 == 0) goto LAB_00888b2d;
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}




/* vtable slots: CMFCMenuBar[67] */
/* 00888b43  FUN_00888b43  477 bytes, 0 callers */

undefined4 FUN_00888b43(int param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  SHORT SVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *in_ECX;
  uint uVar8;
  
  if (*(int *)(param_1 + 4) != 0x100) goto LAB_00888c27;
  iVar5 = FUN_007fdf83(0);
  if (iVar5 != 0) {
    uVar6 = FUN_007ee372(param_1);
    return uVar6;
  }
  iVar5 = FUN_007fdf7c();
  if (in_ECX[0x35c] != 0) {
    iVar5 = iVar5 - in_ECX[0x359];
  }
  iVar2 = in_ECX[0x2fc];
  if ((iVar2 < 0) || (iVar5 <= iVar2)) goto LAB_00888c27;
  uVar8 = *(uint *)(param_1 + 8);
  if (uVar8 == 9) {
    SVar4 = GetKeyState(0x10);
    uVar8 = ((byte)SVar4 ^ 0x80) >> 6 | 0x25;
  }
  uVar7 = FUN_00797acc();
  if ((uVar7 & 0x400000) == 0) {
LAB_00888be0:
    if (uVar8 == 0xd) {
      uVar6 = FUN_007fde79(in_ECX[0x2fc]);
      iVar5 = FUN_007fd66a(uVar6);
      if (iVar5 == 0) {
        uVar6 = FUN_007fde79(in_ECX[0x2fc]);
        FUN_008038ff(uVar6);
      }
      return 1;
    }
    if (uVar8 == 0x1b) {
      pcVar3 = *(code **)(*in_ECX + 0x360);
      guard_check_icall();
      (*pcVar3)();
      pcVar3 = *(code **)(*in_ECX + 0x364);
      guard_check_icall();
      (*pcVar3)();
      DAT_00a13c24 = 0;
      goto LAB_00888c27;
    }
    if (uVar8 == 0x25) goto LAB_00888ca1;
    if (uVar8 != 0x27) {
      if (uVar8 == 0x28) {
        uVar6 = FUN_007fde79(in_ECX[0x2fc]);
        FUN_007fd66a(uVar6);
        return 1;
      }
      pcVar3 = *(code **)(*in_ECX + 0x394);
      guard_check_icall(*(undefined4 *)(param_1 + 8));
      iVar5 = (*pcVar3)();
      if (iVar5 != 0) {
        return 1;
      }
      goto LAB_00888c27;
    }
LAB_00888c50:
    in_ECX[0x2fc] = in_ECX[0x2fc] + 1;
    if (iVar5 <= in_ECX[0x2fc]) {
      in_ECX[0x2fc] = 0;
    }
  }
  else {
    if (uVar8 == 0x25) goto LAB_00888c50;
    if (uVar8 != 0x27) goto LAB_00888be0;
LAB_00888ca1:
    piVar1 = in_ECX + 0x2fc;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      in_ECX[0x2fc] = iVar5 + -1;
    }
  }
  FUN_007fe655(iVar2);
  FUN_007fe655(in_ECX[0x2fc]);
  UpdateWindow((HWND)in_ECX[8]);
  pcVar3 = *(code **)(*in_ECX + 0x25c);
  guard_check_icall(in_ECX[0x2fc]);
  (*pcVar3)();
LAB_00888c27:
  uVar6 = FUN_008036ce(param_1);
  return uVar6;
}




/* vtable slots: CMFCMenuBar[202] */
/* 00888d20  FUN_00888d20  307 bytes, 0 callers */

void FUN_00888d20(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int local_8;
  
  if (*(int *)(in_ECX + 0xd50) != 0) {
    local_8 = in_ECX;
    FUN_0082ba9e(*(undefined4 *)(in_ECX + 0xd4c));
    iVar2 = FUN_0079dd6d();
    piVar4 = *(int **)(*(int *)(iVar2 + 4) + 0x5c);
    if (piVar4 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar4 + 0x10);
      guard_check_icall();
      local_8 = (*pcVar1)();
      while (local_8 != 0) {
        pcVar1 = *(code **)(*piVar4 + 0x14);
        guard_check_icall(&local_8);
        iVar2 = (*pcVar1)();
        iVar3 = FUN_0079d98a(&PTR_s_CMultiDocTemplate_0099f534);
        if (((iVar3 != 0) && (*(int *)(iVar2 + 0x88) != 0)) &&
           (iVar3 = FUN_0082b8fd(*(int *)(iVar2 + 0x88),in_ECX), iVar3 != 0)) {
          FUN_00803ecd();
          FUN_0082ba9e(*(undefined4 *)(iVar2 + 0x88));
        }
      }
    }
    iVar2 = FUN_0082b8fd(*(undefined4 *)(in_ECX + 0xd50),in_ECX);
    if (iVar2 != 0) {
      FUN_00803ecd();
      FUN_0082ba9e(*(undefined4 *)(in_ECX + 0xd50));
    }
    if ((*(int *)(in_ECX + 0xd4c) != 0) &&
       (iVar2 = FUN_0082b8fd(*(int *)(in_ECX + 0xd4c),in_ECX), iVar2 != 0)) {
      piVar4 = (int *)FUN_0079296c();
      pcVar1 = *(code **)(*piVar4 + 0x178);
      guard_check_icall(1);
      (*pcVar1)();
      InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,1);
      UpdateWindow(*(HWND *)(in_ECX + 0x20));
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCMenuBar[226] */
/* 00889077  FUN_00889077  1012 bytes, 0 callers */

undefined4 FUN_00889077(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  HMENU pHVar4;
  bool bVar5;
  CObject *pCVar6;
  int iVar7;
  CObject *pCVar8;
  CMDIChildWnd *pCVar9;
  CDocTemplate *pCVar10;
  HMENU pHVar11;
  BOOL BVar12;
  int iVar13;
  int *piVar14;
  int *in_ECX;
  CObject *local_24;
  int local_14;
  CDocTemplate *local_10;
  int local_c;
  int *local_8;
  
  local_c = in_ECX[0x353];
  if (local_c != 0) {
    FUN_0082ba9e(local_c);
  }
  local_24 = (CObject *)0x0;
  if ((undefined4 *)in_ECX[0x345] != (undefined4 *)0x0) {
    pcVar1 = (code *)**(undefined4 **)in_ECX[0x345];
    guard_check_icall();
    (*pcVar1)();
    pCVar6 = (CObject *)FUN_0079d90c();
    local_24 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,pCVar6);
    pcVar1 = *(code **)(*(int *)local_24 + 0x14);
    guard_check_icall(in_ECX[0x345]);
    (*pcVar1)();
  }
  pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,
                              (CObject *)in_ECX[0x352]);
  if (DAT_00a13c78 != 0) {
    FUN_0089df10(0);
  }
  iVar2 = in_ECX[0x35c];
  bVar5 = false;
  local_10 = (CDocTemplate *)0x0;
  FUN_008896a2(0,0,1);
  iVar7 = FUN_0079dd6d();
  piVar14 = *(int **)(*(int *)(iVar7 + 4) + 0x5c);
  local_8 = piVar14;
  if (piVar14 != (int *)0x0) {
    pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWnd_0099f564,
                                (CObject *)in_ECX[0x352]);
    if ((pCVar8 != (CObject *)0x0) &&
       (pCVar9 = CMDIFrameWnd::MDIGetActive((CMDIFrameWnd *)pCVar8,(int *)0x0),
       pCVar9 != (CMDIChildWnd *)0x0)) {
      pCVar9 = CMDIFrameWnd::MDIGetActive((CMDIFrameWnd *)pCVar8,(int *)0x0);
      pcVar1 = *(code **)(*(int *)pCVar9 + 0x16c);
      guard_check_icall();
      iVar7 = (*pcVar1)();
      piVar14 = local_8;
      if (iVar7 != 0) {
        local_10 = *(CDocTemplate **)(iVar7 + 0x28);
      }
    }
    pcVar1 = *(code **)(*piVar14 + 0x10);
    guard_check_icall();
    local_14 = (*pcVar1)();
    while (local_14 != 0) {
      pcVar1 = *(code **)(*piVar14 + 0x14);
      guard_check_icall(&local_14);
      pCVar10 = (CDocTemplate *)(*pcVar1)();
      iVar7 = FUN_0079d98a(&PTR_s_CMultiDocTemplate_0099f534);
      piVar14 = local_8;
      if ((iVar7 != 0) && (*(int *)(pCVar10 + 0x88) != 0)) {
        uVar3 = *(uint *)(pCVar10 + 0x54);
        if (uVar3 == 0) goto LAB_00889466;
        iVar7 = FUN_0079dd6d();
        pHVar4 = *(HMENU *)(pCVar10 + 0x88);
        pHVar11 = LoadMenuW(*(HINSTANCE *)(iVar7 + 0xc),(LPCWSTR)(uVar3 & 0xffff));
        *(HMENU *)(pCVar10 + 0x88) = pHVar11;
        pcVar1 = *(code **)(*in_ECX + 0x434);
        guard_check_icall(pHVar11,0,0);
        (*pcVar1)();
        FUN_0082ba9e(*(undefined4 *)(pCVar10 + 0x88));
        if (local_10 == pCVar10) {
          local_c = *(int *)(pCVar10 + 0x88);
          bVar5 = true;
        }
        FUN_00889a48(pCVar10);
        piVar14 = local_8;
        if (pHVar4 != (HMENU)0x0) {
          BVar12 = IsMenu(pHVar4);
          if (BVar12 == 0) goto LAB_00889466;
          FUN_0082ba5f(pHVar4);
          DestroyMenu(pHVar4);
          piVar14 = local_8;
        }
      }
    }
  }
  if (in_ECX[0x357] != 0) {
    iVar7 = FUN_0079dd6d();
    pHVar4 = (HMENU)in_ECX[0x354];
    pHVar11 = LoadMenuW(*(HINSTANCE *)(iVar7 + 0xc),(LPCWSTR)(uint)*(ushort *)(in_ECX + 0x357));
    in_ECX[0x354] = (int)pHVar11;
    pcVar1 = *(code **)(*in_ECX + 0x43c);
    guard_check_icall(pHVar11);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x434);
    guard_check_icall(in_ECX[0x354],1,0);
    (*pcVar1)();
    FUN_0082ba9e(in_ECX[0x354]);
    if (!bVar5) {
      local_c = in_ECX[0x354];
    }
    if (pCVar6 != (CObject *)0x0) {
      *(int *)(pCVar6 + 0x88) = in_ECX[0x354];
      *(int *)(pCVar6 + 0x390) = in_ECX[0x354];
    }
    pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,(CObject *)in_ECX[0x352])
    ;
    if (pCVar8 != (CObject *)0x0) {
      *(int *)(pCVar8 + 0x88) = in_ECX[0x354];
    }
    if (pHVar4 != (HMENU)0x0) {
      BVar12 = IsMenu(pHVar4);
      if (BVar12 == 0) {
LAB_00889466:
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      FUN_0082ba5f(pHVar4);
      DestroyMenu(pHVar4);
    }
  }
  iVar7 = local_c;
  iVar13 = FUN_0082b8fd(local_c,in_ECX);
  if ((iVar13 != 0) && (in_ECX[0x353] = iVar7, iVar2 == 0)) {
    piVar14 = (int *)FUN_0079296c();
    pcVar1 = *(code **)(*piVar14 + 0x178);
    guard_check_icall(1);
    (*pcVar1)();
    InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
    UpdateWindow((HWND)in_ECX[8]);
  }
  if (pCVar6 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar6 + 0x1a8);
    guard_check_icall(in_ECX[0x353]);
    (*pcVar1)();
  }
  if (iVar2 != 0) {
    FUN_00888e54(1);
  }
  if ((CMFCToolBarsMenuPropertyPage *)in_ECX[0x362] != (CMFCToolBarsMenuPropertyPage *)0x0) {
    CMFCToolBarsMenuPropertyPage::SelectMenu
              ((CMFCToolBarsMenuPropertyPage *)in_ECX[0x362],local_10,0);
  }
  if (local_24 != (CObject *)0x0) {
    pcVar1 = *(code **)(*in_ECX + 0x340);
    guard_check_icall(local_24,0xffffffff);
    (*pcVar1)();
    in_ECX[0x345] = (int)local_24;
    pcVar1 = *(code **)(*in_ECX + 0x20c);
    guard_check_icall();
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x2d4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  return 1;
}




/* vtable slots: CMFCMenuBar[140] */
/* 0088946c  FUN_0088946c  500 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0088946c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  uint uVar6;
  undefined4 uVar7;
  int local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x889478;
  if (in_ECX[0x354] == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  FUN_008592c1(local_14,L"MenuBar",param_1);
  local_8 = 0;
  FUN_0082ba9e(in_ECX[0x353]);
  iVar1 = in_ECX[0x35c];
  FUN_008896a2(0,0,0);
  iVar3 = FUN_0079dd6d();
  piVar5 = *(int **)(*(int *)(iVar3 + 4) + 0x5c);
  if ((in_ECX[0x350] != 0) && (piVar5 != (int *)0x0)) {
    pcVar2 = *(code **)(*piVar5 + 0x10);
    guard_check_icall();
    local_18 = (*pcVar2)();
    while (local_18 != 0) {
      pcVar2 = *(code **)(*piVar5 + 0x14);
      guard_check_icall(&local_18);
      iVar3 = (*pcVar2)();
      iVar4 = FUN_0079d98a(&PTR_s_CMultiDocTemplate_0099f534);
      if ((iVar4 != 0) && (*(int *)(iVar3 + 0x88) != 0)) {
        uVar7 = *(undefined4 *)(iVar3 + 0x54);
        iVar3 = FUN_0082b8fd(*(int *)(iVar3 + 0x88),in_ECX);
        if (iVar3 != 0) {
          pcVar2 = *(code **)(*in_ECX + 0x438);
          guard_check_icall(uVar7);
          (*pcVar2)();
          FUN_008041af(local_14[0],param_2,uVar7);
        }
      }
    }
  }
  iVar3 = FUN_0082b8fd(in_ECX[0x354],in_ECX);
  if (iVar3 != 0) {
    pcVar2 = *(code **)(*in_ECX + 0x438);
    guard_check_icall(in_ECX[0x357]);
    (*pcVar2)();
    FUN_008041af(local_14[0],param_2,0);
  }
  if ((in_ECX[0x353] == 0) || (iVar3 = FUN_0082b8fd(in_ECX[0x353],in_ECX), iVar3 == 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
  }
  if (iVar1 != 0) {
    FUN_00888e54(uVar6 ^ 1);
  }
  uVar7 = 1;
  pcVar2 = *(code **)(*in_ECX + 0x2d4);
  guard_check_icall(1);
  (*pcVar2)();
  if (uVar6 != 0) {
    piVar5 = (int *)FUN_0079296c();
    pcVar2 = *(code **)(*piVar5 + 0x178);
    guard_check_icall(1);
    (*pcVar2)();
    InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
    UpdateWindow((HWND)in_ECX[8]);
  }
  pcVar2 = *(code **)(*in_ECX + 0x20c);
  guard_check_icall(uVar7);
  (*pcVar2)();
  FUN_00406b10();
  return 1;
}



