/* CPaneDivider -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPaneDivider[1] */
/* 008bde08  FUN_008bde08  57 bytes, 0 callers */

void FUN_008bde08(byte param_1)

{
  CBasePane *in_ECX;
  
  *(undefined ***)in_ECX = CPaneDivider::vftable;
  CBasePane::~CBasePane(in_ECX);
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




/* vtable slots: CPaneDivider[156] */
/* 008bde41  FUN_008bde41  61 bytes, 0 callers */

void FUN_008bde41(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x1c);
  guard_check_icall(param_1);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x290);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CPaneDivider[163] */
/* 008bde7e  FUN_008bde7e  77 bytes, 0 callers */

undefined4 FUN_008bde7e(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  uVar2 = 0;
  if ((int *)in_ECX[0x5a] != (int *)0x0) {
    pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x14);
    guard_check_icall(param_1,param_2);
    uVar2 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x290);
    guard_check_icall();
    (*pcVar1)();
  }
  return uVar2;
}




/* vtable slots: CPaneDivider[162] */
/* 008bdecb  FUN_008bdecb  82 bytes, 0 callers */

undefined4 FUN_008bdecb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  uVar2 = 0;
  if ((int *)in_ECX[0x5a] != (int *)0x0) {
    pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x10);
    guard_check_icall(param_1,param_3,param_2,1);
    uVar2 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x290);
    guard_check_icall();
    (*pcVar1)();
  }
  return uVar2;
}




/* vtable slots: CPaneDivider[157] */
/* 008bdf1d  FUN_008bdf1d  153 bytes, 0 callers */

undefined4 FUN_008bdf1d(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  code *pcVar4;
  
  iVar1 = FUN_0085f26e(1);
  iVar2 = FUN_0085f286(1);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      return 0;
    }
    pcVar4 = *(code **)(*(int *)in_ECX[0x5a] + 0x20);
    guard_check_icall(param_1,iVar2);
    uVar3 = (*pcVar4)();
    pcVar4 = *(code **)(*in_ECX + 0x290);
  }
  else {
    pcVar4 = *(code **)(*(int *)in_ECX[0x5a] + 0x20);
    guard_check_icall(param_1,iVar1);
    uVar3 = (*pcVar4)();
    pcVar4 = *(code **)(*in_ECX + 0x290);
    iVar2 = iVar1;
  }
  guard_check_icall(param_1,iVar2);
  (*pcVar4)();
  return uVar3;
}




/* vtable slots: CPaneDivider[167] */
/* 008bdfb6  CalcExpectedDockedRect  79 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CPaneDivider::CalcExpectedDockedRect(class CWnd *,class
   CPoint,class CRect &,int &,class CDockablePane * *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CPaneDivider::CalcExpectedDockedRect
          (CPaneDivider *this,undefined4 param_1,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  CGlobalUtils local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8bdfc2;
  CGlobalUtils::CGlobalUtils(local_1c);
  local_8 = 0;
  if (*(int *)(this + 0x168) != 0) {
    FUN_00859f19(*(int *)(this + 0x168),param_1,param_3,param_4,param_5,param_6,param_7);
  }
  FUN_00859dc2();
  return;
}




/* vtable slots: CPaneDivider[152] */
/* 008be005  FUN_008be005  147 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008be005(int *param_1)

{
  code *pcVar1;
  int in_ECX;
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
  GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
  *param_1 = local_18.right - local_18.left;
  param_1[1] = local_18.bottom - local_18.top;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (*(int **)(in_ECX + 0x168) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x168) + 0x2c);
    guard_check_icall(&local_28);
    (*pcVar1)();
    *param_1 = *param_1 + (local_20 - local_28);
    param_1[1] = param_1[1] + (local_1c - local_24);
  }
  return param_1;
}




/* vtable slots: CPaneDivider[164] */
/* 008be098  FUN_008be098  94 bytes, 0 callers */

int FUN_008be098(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0x4b] != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1dc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((iVar2 == 0) && ((int *)in_ECX[0x5a] != (int *)0x0)) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x4c);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      FUN_00797f20(-(iVar2 != 0) & 5);
      return iVar2;
    }
  }
  return 0;
}




/* vtable slots: CPaneDivider[169] */
/* 008be0f6  FUN_008be0f6  29 bytes, 0 callers */

void FUN_008be0f6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_008be199(0,param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CPaneDivider[170] */
/* 008be199  FUN_008be199  276 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_008be199(undefined4 param_1,uint param_2,int *param_3,CObject *param_4,undefined4 param_5,
            undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  CObject *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8be1a5;
  *(undefined4 *)(in_ECX + 0x110) = param_5;
  *(uint *)(in_ECX + 0x114) = param_2;
  if ((param_2 & 2) == 0) {
    if ((param_2 & 1) != 0) {
      iVar2 = param_3[3] - param_3[1];
      goto LAB_008be1d6;
    }
  }
  else {
    iVar2 = param_3[2] - *param_3;
LAB_008be1d6:
    *(int *)(in_ECX + 0x118) = iVar2;
  }
  if (*(int *)(in_ECX + 300) != 0) {
    if (PTR_PTR_00a00cb8 != (undefined *)0x0) {
      pCVar3 = (CObject *)FUN_0079d90c();
      local_14[0] = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneContainerManager_009a2dc8,pCVar3
                                      );
      *(CObject **)(in_ECX + 0x168) = local_14[0];
      if (local_14[0] != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)local_14[0] + 0xc);
        guard_check_icall(param_4);
        (*pcVar1)();
        goto LAB_008be237;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
LAB_008be237:
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,param_4);
  *(CObject **)(in_ECX + 0xa4) = pCVar3;
  if (pCVar3 == (CObject *)0x0) {
    uVar4 = FUN_007e5618(param_4);
    *(undefined4 *)(in_ECX + 0xa4) = uVar4;
  }
  FUN_007c2511();
  puVar5 = (undefined4 *)FUN_007e5eba(local_14,L"Afx:Slider");
  local_8 = 0;
  uVar4 = FUN_007920d9(param_1,*puVar5,0,param_2 | 0x46000000,param_3,param_4,param_5,param_6);
  FUN_00406b10();
  return uVar4;
}




/* vtable slots: CPaneDivider[96] */
/* 008be2ae  FUN_008be2ae  37 bytes, 0 callers */

undefined4 FUN_008be2ae(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x168) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x168) + 100);
    guard_check_icall();
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  return 1;
}




/* vtable slots: CPaneDivider[166] */
/* 008be2d3  FUN_008be2d3  36 bytes, 0 callers */

undefined4 FUN_008be2d3(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x168) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x168) + 0x60);
    guard_check_icall();
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  return 0;
}




/* vtable slots: CPaneDivider[10] */
/* 008be35f  FUN_008be35f  6 bytes, 0 callers */

undefined ** FUN_008be35f(void)

{
  return &PTR_FUN_009a2da8;
}




/* vtable slots: CPaneDivider[0] */
/* 008be3ca  FUN_008be3ca  6 bytes, 0 callers */

undefined ** FUN_008be3ca(void)

{
  return &PTR_s_CPaneDivider_009a27cc;
}




/* vtable slots: CPaneDivider[158] */
/* 008be449  FUN_008be449  86 bytes, 0 callers */

undefined4 FUN_008be449(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((int *)in_ECX[0x5a] != (int *)0x0) {
    pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x24);
    guard_check_icall(param_1,param_2,param_3,param_4,0);
    uVar2 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x290);
    guard_check_icall();
    (*pcVar1)();
  }
  return uVar2;
}




/* vtable slots: CPaneDivider[119] */
/* 008be49f  FUN_008be49f  7 bytes, 0 callers */

undefined4 FUN_008be49f(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x130);
}




/* vtable slots: CPaneDivider[89] */
/* 008be4a6  FUN_008be4a6  10 bytes, 0 callers */

uint FUN_008be4a6(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0x114) & 1;
}




/* vtable slots: CPaneDivider[155] */
/* 008be4b0  FUN_008be4b0  300 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008be4b0(int *param_1)

{
  code *pcVar1;
  HWND pHVar2;
  uint uVar3;
  CWnd *this;
  HDWP hWinPosInfo;
  int *in_ECX;
  int iVar4;
  int dy;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pHVar2 = GetParent((HWND)in_ECX[8]);
  CWnd::FromHandle(pHVar2);
  uVar3 = FUN_00797acc();
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect((HWND)in_ECX[8],&local_18);
  pHVar2 = GetParent((HWND)in_ECX[8]);
  this = CWnd::FromHandle(pHVar2);
  CWnd::ScreenToClient(this,&local_18);
  if ((in_ECX[0x45] & 2U) == 0) {
    if ((in_ECX[0x45] & 1U) == 0) {
      return;
    }
    dy = param_1[1];
    iVar4 = 0;
  }
  else {
    iVar4 = *param_1;
    if ((uVar3 & 0x400000) != 0) {
      iVar4 = -iVar4;
    }
    dy = 0;
  }
  OffsetRect(&local_18,iVar4,dy);
  hWinPosInfo = BeginDeferWindowPos(0x32);
  if ((int *)in_ECX[0x5a] != (int *)0x0) {
    iVar4 = *(int *)in_ECX[0x5a];
    guard_check_icall();
    (**(code **)(iVar4 + 0x28))();
  }
  EndDeferWindowPos(hWinPosInfo);
  pcVar1 = *(code **)(*in_ECX + 0x268);
  guard_check_icall(0);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x238);
  guard_check_icall(0,local_18.left,local_18.top,local_18.right - local_18.left,
                    local_18.bottom - local_18.top,0x14,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CPaneDivider[168] */
/* 008be5dc  NotifyAboutRelease  53 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CPaneDivider::NotifyAboutRelease(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CPaneDivider::NotifyAboutRelease(CPaneDivider *this)

{
  int iVar1;
  
  iVar1 = CPaneContainerManager::IsEmpty(*(CPaneContainerManager **)(this + 0x168));
  if (iVar1 != 0) {
    iVar1 = CPaneContainerManager::GetTotalRefCount(*(CPaneContainerManager **)(this + 0x168));
    if (iVar1 == 0) {
      FUN_007ee3fe(this,1,0,*(undefined4 *)(this + 0x130),0);
    }
  }
  return;
}




/* vtable slots: CPaneDivider[165] */
/* 008beb72  FUN_008beb72  177 bytes, 0 callers */

void FUN_008beb72(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 local_8;
  
  if (in_ECX[0x5a] != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1dc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x48);
      guard_check_icall(param_1,param_2);
      iVar2 = (*pcVar1)();
      if (param_2 == 0) {
        FUN_00797f20(-(iVar2 != 0) & 5);
        local_8 = 0;
        pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x8c);
        guard_check_icall(param_1,&local_8);
        piVar3 = (int *)(*pcVar1)();
        if (piVar3 != (int *)0x0) {
          pcVar1 = *(code **)(*piVar3 + 0x20);
          guard_check_icall(param_1,0);
          (*pcVar1)();
        }
      }
      else {
        FUN_00797f20(5);
      }
    }
  }
  return;
}




/* vtable slots: CPaneDivider[160] */
/* 008bec23  FUN_008bec23  168 bytes, 0 callers */

void FUN_008bec23(int param_1)

{
  code *pcVar1;
  int iVar2;
  CPaneDivider *pCVar3;
  CPaneDivider *in_ECX;
  
  if (*(int **)(in_ECX + 0x168) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x168) + 0x34);
    guard_check_icall(param_1);
    (*pcVar1)();
    FUN_007ee3fe(param_1,0,0,*(int *)(in_ECX + 0x130),0);
    iVar2 = CPaneContainerManager::IsEmpty(*(CPaneContainerManager **)(in_ECX + 0x168));
    if (((iVar2 == 0) ||
        (iVar2 = CPaneContainerManager::GetTotalRefCount
                           (*(CPaneContainerManager **)(in_ECX + 0x168)), iVar2 != 0)) ||
       (pCVar3 = CRecentDockSiteInfo::GetRecentDefaultPaneDivider
                           ((CRecentDockSiteInfo *)(param_1 + 0x1e4)), pCVar3 == in_ECX)) {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x290);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        FUN_00797f20(0);
      }
    }
    else {
      FUN_007ee3fe(in_ECX,1,0,*(int *)(in_ECX + 0x130),0);
    }
  }
  return;
}




/* vtable slots: CPaneDivider[159] */
/* 008beccb  FUN_008beccb  92 bytes, 0 callers */

undefined4 FUN_008beccb(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[0x5a] == 0) {
    uVar2 = 0;
  }
  else {
    FUN_008912c6(in_ECX[8]);
    pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x40);
    guard_check_icall(param_1,param_2);
    uVar2 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x290);
    guard_check_icall();
    (*pcVar1)();
  }
  return uVar2;
}




/* vtable slots: CPaneDivider[161] */
/* 008bed27  FUN_008bed27  802 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008bed27(tagRECT *param_1,undefined4 *param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int *piVar3;
  tagRECT *ptVar4;
  int iVar5;
  HWND pHVar6;
  CWnd *this;
  undefined4 uVar7;
  CObject *pCVar8;
  HRGN pHVar9;
  int *in_ECX;
  CObList local_98 [4];
  undefined4 *local_94;
  CObList local_7c [4];
  undefined4 *local_78;
  int *local_60;
  int local_5c;
  int local_58;
  undefined **local_54;
  HRGN local_50;
  int *local_4c;
  tagRECT *local_48;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x88;
  local_8 = 0x8bed36;
  local_48 = param_1;
  local_4c = param_2;
  local_24.left = param_1->left;
  local_24.top = param_1->top;
  local_24.right = param_1->right;
  local_24.bottom = param_1->bottom;
  local_44.left = param_1->left;
  local_44.top = param_1->top;
  local_44.right = param_1->right;
  local_44.bottom = param_1->bottom;
  pcVar1 = *(code **)(*in_ECX + 0x194);
  local_60 = in_ECX;
  guard_check_icall();
  iVar5 = (*pcVar1)();
  ptVar4 = local_48;
  if (iVar5 == 0x1000) {
    local_44.left = local_48->right - in_ECX[0x46];
    local_24.right = local_44.left;
LAB_008bedd9:
    local_24.top = local_44.top;
    local_24.bottom = local_44.bottom;
  }
  else {
    if (iVar5 == 0x2000) {
      local_44.top = local_48->bottom - in_ECX[0x46];
      local_24.bottom = local_44.top;
    }
    else {
      if (iVar5 == 0x4000) {
        local_44.right = in_ECX[0x46] + local_48->left;
        local_24.left = local_44.right;
        goto LAB_008bedd9;
      }
      if (iVar5 != 0x8000) goto LAB_008bede5;
      local_44.bottom = in_ECX[0x46] + local_48->top;
      local_24.top = local_44.bottom;
    }
    local_24.left = local_44.left;
    local_24.right = local_44.right;
  }
LAB_008bede5:
  pHVar6 = GetParent((HWND)in_ECX[8]);
  this = CWnd::FromHandle(pHVar6);
  local_48 = (tagRECT *)this;
  CWnd::ScreenToClient(this,ptVar4);
  CWnd::ScreenToClient(this,&local_44);
  CWnd::ScreenToClient(this,&local_24);
  piVar3 = local_4c;
  pcVar1 = *(code **)(*in_ECX + 0x234);
  guard_check_icall(&local_44,1,*local_4c);
  uVar7 = (*pcVar1)();
  *piVar3 = uVar7;
  local_4c = (int *)in_ECX[0x5a];
  if (local_4c != (int *)0x0) {
    pcVar1 = *(code **)(*local_4c + 0x38);
    guard_check_icall(local_24.left,local_24.top,local_24.right,local_24.bottom,piVar3);
    (*pcVar1)();
    local_5c = 0;
    local_58 = 0;
    pcVar1 = *(code **)(*(int *)local_60[0x5a] + 0x50);
    guard_check_icall(&local_5c);
    (*pcVar1)();
    if (DAT_00a12770 != 0) {
      CObList::CObList(local_7c,10);
      local_8 = 0;
      CObList::CObList(local_98,10);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_008c01f8(local_7c,local_98);
      ptVar4 = local_48;
      if ((local_24.right - local_24.left < local_5c) || (local_24.bottom - local_24.top < local_58)
         ) {
        while (local_78 != (undefined4 *)0x0) {
          if (local_78 == (undefined4 *)0x0) goto LAB_008bf044;
          puVar2 = (undefined4 *)*local_78;
          pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                      (CObject *)local_78[2]);
          local_34.left = 0;
          local_34.top = 0;
          local_34.right = 0;
          local_34.bottom = 0;
          GetWindowRect(*(HWND *)(pCVar8 + 0x20),&local_34);
          CWnd::ScreenToClient((CWnd *)ptVar4,&local_34);
          if (local_24.right < local_34.right) {
            local_34.right = local_24.right;
          }
          if (local_24.bottom < local_34.bottom) {
            local_34.bottom = local_24.bottom;
          }
          OffsetRect(&local_34,-local_34.left,-local_34.top);
          local_50 = (HRGN)0x0;
          local_54 = CRgn::vftable;
          local_8._0_1_ = 2;
          pHVar9 = CreateRectRgn(local_34.left,local_34.top,local_34.right,local_34.bottom);
          Attach(pHVar9);
          SetWindowRgn(*(HWND *)(pCVar8 + 0x20),local_50,1);
          local_8 = CONCAT31(local_8._1_3_,1);
          local_54 = CRgn::vftable;
          FUN_00416100();
          local_78 = puVar2;
        }
        while (local_94 != (undefined4 *)0x0) {
          if (local_94 == (undefined4 *)0x0) goto LAB_008bf044;
          puVar2 = local_94 + 2;
          local_94 = (undefined4 *)*local_94;
          pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,
                                      (CObject *)*puVar2);
          pcVar1 = *(code **)(*(int *)pCVar8 + 0x238);
          guard_check_icall(&DAT_00a11ce8,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x13,0);
          (*pcVar1)();
        }
      }
      else {
        while (local_78 != (undefined4 *)0x0) {
          if (local_78 == (undefined4 *)0x0) {
LAB_008bf044:
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
          puVar2 = (undefined4 *)*local_78;
          SetWindowRgn(*(HWND *)(local_78[2] + 0x20),(HRGN)0x0,1);
          local_78 = puVar2;
        }
      }
      FUN_007a184a();
      FUN_007a184a();
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CPaneDivider[2] */
/* 008bf04a  FUN_008bf04a  472 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bf04a(CArchive *param_1)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *this;
  BOOL BVar3;
  uint uVar4;
  int *in_ECX;
  long local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_007ee62d(param_1);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    local_1c = 0;
    CArchive::operator>>(param_1,in_ECX + 0x44);
    CArchive::operator>>(param_1,in_ECX + 0x49);
    CArchive::EnsureRead(param_1,&local_18,0x10);
    CArchive::operator>>(param_1,&local_1c);
    CArchive::operator>>(param_1,in_ECX + 0x45);
    CArchive::operator>>(param_1,in_ECX + 0x46);
    CArchive::operator>>(param_1,in_ECX + 0x4b);
    CArchive::operator>>(param_1,in_ECX + 0x47);
    CArchive::operator>>(param_1,in_ECX + 0x48);
    if (local_1c == 0) {
      uVar4 = in_ECX[0x45] & 0xefffffff;
    }
    else {
      uVar4 = in_ECX[0x45] | 0x10000000;
    }
    in_ECX[0x45] = uVar4;
    pcVar1 = *(code **)(*in_ECX + 0x2a8);
    guard_check_icall(0,uVar4,&local_18,in_ECX[0x59],in_ECX[0x44],0);
    (*pcVar1)();
  }
  else {
    GetWindowRect((HWND)in_ECX[8],&local_18);
    pHVar2 = GetParent((HWND)in_ECX[8]);
    this = CWnd::FromHandle(pHVar2);
    CWnd::ScreenToClient(this,&local_18);
    CArchive::operator<<(param_1,in_ECX[0x44]);
    CArchive::operator<<(param_1,in_ECX[0x49]);
    FUN_007a6b47(&local_18,0x10);
    BVar3 = IsWindowVisible((HWND)in_ECX[8]);
    CArchive::operator<<(param_1,BVar3);
    CArchive::operator<<(param_1,in_ECX[0x45]);
    CArchive::operator<<(param_1,in_ECX[0x46]);
    CArchive::operator<<(param_1,in_ECX[0x4b]);
    CArchive::operator<<(param_1,in_ECX[0x47]);
    CArchive::operator<<(param_1,in_ECX[0x48]);
  }
  if (((int *)in_ECX[0x5a] != (int *)0x0) && (in_ECX[0x4b] != 0)) {
    pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 8);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CPaneDivider[171] */
/* 008bf22b  FUN_008bf22b  266 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008bf22b(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  int local_24;
  int local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((char)in_ECX[0x4a] != '\0') {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect((HWND)in_ECX[8],&local_18);
    local_20 = in_ECX[0x4e] - local_18.top;
    local_24 = in_ECX[0x4d] - local_18.left;
    local_1c = (int *)in_ECX[0x5b];
    if ((local_1c != (int *)0x0) && (local_1c[8] != 0)) {
      pcVar1 = *(code **)(*local_1c + 0x60);
      guard_check_icall();
      (*pcVar1)();
      local_1c = (int *)in_ECX[0x5b];
      if (local_1c != (int *)0x0) {
        pcVar1 = *(code **)(*local_1c + 4);
        guard_check_icall(1);
        (*pcVar1)();
      }
      in_ECX[0x5b] = 0;
    }
    if (param_1 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x26c);
      guard_check_icall(&local_24,1);
      (*pcVar1)();
    }
    SetRectEmpty((LPRECT)(in_ECX + 0x4d));
    ReleaseCapture();
    *(undefined1 *)(in_ECX + 0x4a) = 0;
    if ((int *)in_ECX[0x5a] != (int *)0x0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x5a] + 0x80);
      guard_check_icall(0);
      (*pcVar1)();
    }
  }
  return;
}



