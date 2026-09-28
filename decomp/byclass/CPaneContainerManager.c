/* CPaneContainerManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPaneContainerManager[1] */
/* 008bf4ad  FUN_008bf4ad  48 bytes, 0 callers */

void FUN_008bf4ad(byte param_1)

{
  FUN_008bf405();
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




/* vtable slots: CPaneContainerManager[7] */
/* 008bf4dd  AddPane  35 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CPaneContainerManager::AddPane(class CDockablePane *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CPaneContainerManager::AddPane(CPaneContainerManager *this,CDockablePane *param_1)

{
  CPaneContainer::SetPane(*(CPaneContainer **)(this + 0x3c),param_1,1);
  CObList::AddTail((CObList *)(this + 4),(CObject *)param_1);
  return;
}




/* vtable slots: CPaneContainerManager[5] */
/* 008bfb2f  FUN_008bfb2f  556 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008bfb2f(CPaneContainerManager *param_1,int param_2)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  CPaneContainer *this;
  undefined4 *puVar4;
  CObject *pCVar5;
  HWND pHVar6;
  CWnd *this_00;
  int *piVar7;
  undefined4 uVar8;
  CPaneContainerManager *in_ECX;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(CPaneContainer **)(in_ECX + 0x3c) != (CPaneContainer *)0x0) {
    iVar3 = CPaneContainer::IsEmpty(*(CPaneContainer **)(in_ECX + 0x3c));
    if ((iVar3 == 0) || (iVar3 = FUN_0085a847(*(undefined4 *)(in_ECX + 0x4c)), iVar3 == 0)) {
      uVar8 = 0;
    }
    else {
      RemoveAll();
      RemoveAll();
      FUN_008c01f8(in_ECX + 4,in_ECX + 0x20);
      CPaneContainerManager::RemoveAllPanesAndPaneDividers(param_1);
      pcVar1 = *(code **)(**(int **)(param_1 + 0x3c) + 0x50);
      guard_check_icall(*(undefined4 *)(in_ECX + 0x3c));
      this = (CPaneContainer *)(*pcVar1)();
      CPaneContainer::SetPaneContainer(*(CPaneContainer **)(in_ECX + 0x3c),this,1);
      CPaneContainer::SetPaneContainerManager(this,in_ECX,1);
      FUN_0085ac01(in_ECX + 4,*(undefined4 *)(in_ECX + 0x4c),1);
      FUN_0085ac01(in_ECX + 0x20,*(undefined4 *)(in_ECX + 0x4c),1);
      local_1c = *(int *)(in_ECX + 8);
      while (local_1c != 0) {
        puVar4 = (undefined4 *)FUN_0044f2d0(&local_1c);
        pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                    (CObject *)*puVar4);
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetWindowRect(*(HWND *)(pCVar5 + 0x20),&local_18);
        pHVar6 = GetParent(*(HWND *)(pCVar5 + 0x20));
        this_00 = CWnd::FromHandle(pHVar6);
        CWnd::ScreenToClient(this_00,&local_18);
      }
      local_1c = *(int *)(in_ECX + 0x24);
      while (local_1c != 0) {
        piVar7 = (int *)FUN_0044f2d0(&local_1c);
        *(CPaneContainerManager **)(*piVar7 + 0x168) = in_ECX;
      }
      local_1c = *(int *)(in_ECX + 8);
      if (local_1c != 0) {
        do {
          puVar4 = (undefined4 *)FUN_0044f2d0(&local_1c);
          pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                      (CObject *)*puVar4);
          FUN_008912c6(*(undefined4 *)(*(int *)(in_ECX + 0x44) + 0x20));
          pcVar1 = *(code **)(*(int *)pCVar5 + 0x1e0);
          pcVar2 = *(code **)(**(int **)(in_ECX + 0x44) + 0x194);
          guard_check_icall();
          uVar8 = (*pcVar2)();
          guard_check_icall(uVar8);
          (*pcVar1)();
          FUN_00845032(pCVar5,param_2 == 0,0,param_2);
          pcVar1 = *(code **)(*(int *)pCVar5 + 0x1f0);
          guard_check_icall(1);
          (*pcVar1)();
        } while (local_1c != 0);
      }
      FUN_008baee0();
      FUN_008baabc();
      uVar8 = 1;
    }
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CPaneContainerManager[4] */
/* 008bfd5c  FUN_008bfd5c  596 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008bfd5c(undefined4 param_1,uint param_2,CPaneContainerManager *param_3,int param_4)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  CObject *pCVar6;
  CPaneContainerManager *in_ECX;
  CObList local_5c [4];
  undefined4 *local_58;
  CObList local_40 [4];
  undefined4 *local_3c;
  CPaneContainer *local_38;
  CPaneContainerManager *local_20;
  undefined4 local_1c;
  __POSITION *local_18;
  CPaneContainer *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x8bfd68;
  CObList::CObList(local_40,10);
  local_8 = 0;
  CObList::CObList(local_5c,10);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_008c01f8(local_40,local_5c);
  local_1c = 0;
  pcVar2 = *(code **)(*(int *)in_ECX + 0x8c);
  puVar5 = &local_1c;
  uVar4 = param_1;
  guard_check_icall(param_1,puVar5);
  iVar3 = (*pcVar2)();
  if (iVar3 != 0) {
    local_20 = in_ECX + 4;
    local_18 = (__POSITION *)FUN_007a198a(param_1,0);
    if (local_18 != (__POSITION *)0x0) {
      local_14[0] = *(CPaneContainer **)(param_3 + 0x3c);
      if (param_4 != 0) {
        pcVar2 = *(code **)(*(int *)local_14[0] + 0x50);
        guard_check_icall(*(undefined4 *)(in_ECX + 0x3c));
        local_14[0] = (CPaneContainer *)(*pcVar2)();
        CPaneContainer::SetPaneContainerManager(local_14[0],in_ECX,1);
        CPaneContainerManager::RemoveAllPanesAndPaneDividers(param_3);
      }
      pcVar2 = *(code **)(*(int *)param_3 + 0x74);
      guard_check_icall(uVar4,puVar5);
      uVar4 = (*pcVar2)();
      FUN_0085ac01(local_40,*(undefined4 *)(in_ECX + 0x4c),1);
      FUN_0085ac01(local_5c,*(undefined4 *)(in_ECX + 0x4c),1);
      iVar3 = FUN_008bf500(param_1,local_14[0],param_2);
      if (iVar3 != 0) {
        if ((param_2 & 0x3000) == 0) {
          local_14[0] = local_38;
          while (local_14[0] != (CPaneContainer *)0x0) {
            puVar5 = (undefined4 *)FUN_0049ad10(local_14);
            CObList::InsertAfter((CObList *)(in_ECX + 4),local_18,(CObject *)*puVar5);
          }
        }
        else {
          while (local_3c != (undefined4 *)0x0) {
            puVar5 = (undefined4 *)*local_3c;
            InsertBefore(local_18,local_3c[2]);
            local_3c = puVar5;
          }
        }
        FUN_007a194b(local_5c);
        while (local_58 != (undefined4 *)0x0) {
          if (local_58 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
          piVar1 = local_58 + 2;
          local_58 = (undefined4 *)*local_58;
          *(CPaneContainerManager **)(*piVar1 + 0x168) = in_ECX;
        }
        if (param_4 == 0) {
          *(undefined4 *)(param_3 + 0x48) = 0;
          CPaneContainer::SetPaneContainerManager(*(CPaneContainer **)(param_3 + 0x3c),in_ECX,1);
        }
        local_18 = *(__POSITION **)(in_ECX + 8);
        while (local_18 != (__POSITION *)0x0) {
          puVar5 = (undefined4 *)FUN_0044f2d0(&local_18);
          pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                      (CObject *)*puVar5);
          pcVar2 = *(code **)(*(int *)pCVar6 + 0x1f0);
          guard_check_icall(1);
          (*pcVar2)();
          RedrawWindow(*(HWND *)(pCVar6 + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
        }
        uVar4 = 1;
        FUN_008baee0();
        FUN_008baabc();
        goto LAB_008bfe8d;
      }
      FUN_0085ac01(local_40,uVar4,1);
      FUN_0085ac01(local_5c,uVar4,1);
    }
  }
  uVar4 = 0;
LAB_008bfe8d:
  FUN_007a184a();
  FUN_007a184a();
  return uVar4;
}




/* vtable slots: CPaneContainerManager[6] */
/* 008bffb1  FUN_008bffb1  217 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008bffb1(CObject *param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  CObject *pCVar4;
  int *in_ECX;
  undefined4 *puVar5;
  undefined4 uVar6;
  CObList local_38 [4];
  undefined4 *local_34;
  undefined4 local_1c;
  undefined4 *local_18;
  CObject *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x8bffbd;
  CObList::CObList(local_38,10);
  uVar6 = 0;
  local_8 = 0;
  FUN_008c01f8(local_38,0);
  local_1c = 0;
  pcVar2 = *(code **)(*in_ECX + 0x8c);
  guard_check_icall(param_1,&local_1c);
  iVar3 = (*pcVar2)();
  if ((iVar3 != 0) && (iVar3 = FUN_007a198a(param_1,0), iVar3 != 0)) {
    local_14[0] = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,param_1);
    uVar6 = 1;
    puVar5 = local_34;
    while (puVar5 != (undefined4 *)0x0) {
      if (puVar5 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      puVar1 = puVar5 + 2;
      puVar5 = (undefined4 *)*puVar5;
      pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*puVar1)
      ;
      if (pCVar4 != (CObject *)0x0) {
        local_18 = (undefined4 *)(*(int *)pCVar4 + 0x34c);
        pCVar4 = local_14[0];
        if (local_14[0] == (CObject *)0x0) {
          pCVar4 = param_1;
        }
        guard_check_icall(pCVar4,1,1,local_14);
        (*(code *)*local_18)();
      }
    }
  }
  FUN_007a184a();
  return uVar6;
}




/* vtable slots: CPaneContainerManager[8] */
/* 008c0097  FUN_008c0097  353 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CObject * FUN_008c0097(CObject *param_1,undefined4 param_2)

{
  CPaneContainer *this;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  CObject *pCVar4;
  undefined4 *puVar5;
  __POSITION *p_Var6;
  int in_ECX;
  CObList local_38 [28];
  CPaneContainer *local_1c;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x8c00a3;
  local_18 = in_ECX;
  this = (CPaneContainer *)FUN_008bb422(param_2,3);
  pCVar4 = (CObject *)0x0;
  if (this != (CPaneContainer *)0x0) {
    local_1c = this;
    iVar1 = CPaneContainer::IsEmpty(this);
    iVar3 = local_18;
    if ((iVar1 == 0) && (*(int *)(this + 0xc) == 0)) {
      uVar2 = FUN_008c0691(*(undefined4 *)(this + 0x44),*(undefined4 *)(this + 0x48),
                           *(undefined4 *)(this + 0x4c),*(undefined4 *)(this + 0x50),
                           *(undefined4 *)(this + 0x40),0xffffffff);
      *(undefined4 *)(local_1c + 0xc) = uVar2;
      in_ECX = iVar3;
      this = local_1c;
    }
    iVar3 = CPaneContainer::IsEmpty(this);
    if ((iVar3 != 0) &&
       (local_14[0] = *(int *)(this + 0x18), local_14[0] != *(int *)(in_ECX + 0x3c))) {
      do {
        iVar3 = local_18;
        if (local_14[0] == 0) break;
        if ((*(int *)(local_14[0] + 0xc) == 0) && (*(int *)(local_14[0] + 0x40) != 0)) {
          uVar2 = FUN_008c0691(*(undefined4 *)(local_14[0] + 0x44),
                               *(undefined4 *)(local_14[0] + 0x48),
                               *(undefined4 *)(local_14[0] + 0x4c),
                               *(undefined4 *)(local_14[0] + 0x50),
                               *(undefined4 *)(local_14[0] + 0x40),0xffffffff);
          *(undefined4 *)(local_14[0] + 0xc) = uVar2;
          in_ECX = iVar3;
        }
        local_14[0] = *(int *)(local_14[0] + 0x18);
      } while (local_14[0] != *(int *)(in_ECX + 0x3c));
    }
    iVar3 = FUN_0079d98a(&PTR_s_CPaneFrameWnd_00a008b0);
    CObList::CObList(local_38,10);
    local_8 = 0;
    pCVar4 = (CObject *)FUN_0085f255(iVar3 == 0);
    CObList::AddTail(local_38,pCVar4);
    local_14[0] = FUN_007a198a(param_1,0);
    pCVar4 = (CObject *)FUN_008b9fcb(param_1);
    if (pCVar4 == param_1) {
      FUN_008baee0();
      do {
        if (local_14[0] == 0) {
          CObList::AddHead((CObList *)(local_18 + 4),pCVar4);
          goto LAB_008c01db;
        }
        puVar5 = (undefined4 *)FUN_0049ad10(local_14);
        p_Var6 = (__POSITION *)FUN_007a198a(*puVar5,0);
      } while (p_Var6 == (__POSITION *)0x0);
      CObList::InsertAfter((CObList *)(local_18 + 4),p_Var6,pCVar4);
    }
LAB_008c01db:
    FUN_007a184a();
  }
  return pCVar4;
}




/* vtable slots: CPaneContainerManager[31] */
/* 008c03f0  FUN_008c03f0  88 bytes, 0 callers */

undefined4 FUN_008c03f0(void)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  do {
    if (local_8 == 0) {
      return 1;
    }
    pCVar2 = (CObject *)FUN_0049acb0(&local_8);
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar2);
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x18c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
  } while (iVar3 != 0);
  return 0;
}




/* vtable slots: CPaneContainerManager[27] */
/* 008c04c8  FUN_008c04c8  296 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_008c04c8(int param_1,int param_2,int *param_3)

{
  code *pcVar1;
  POINT pt;
  int *piVar2;
  CObject *pCVar3;
  int iVar4;
  BOOL BVar5;
  int *in_ECX;
  RECT local_28;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar2 = param_3;
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMultiPaneFrameWnd_00a00968,
                              (CObject *)in_ECX[0x13]);
  *piVar2 = 0;
  if (pCVar3 != (CObject *)0x0) {
    pcVar1 = *(code **)(*in_ECX + 0x54);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 < 2) {
      local_28.left = 0;
      local_28.top = 0;
      local_28.right = 0;
      local_28.bottom = 0;
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x1c8);
      guard_check_icall(&local_28);
      (*pcVar1)();
      ScreenToClient(*(HWND *)(pCVar3 + 0x20),(LPPOINT)&param_1);
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x1bc);
      guard_check_icall(&local_18);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x170);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      param_2 = param_2 + iVar4 + local_14;
      param_1 = param_1 + local_18;
      pt.y = param_2;
      pt.x = param_1;
      BVar5 = PtInRect(&local_28,pt);
      if (BVar5 != 0) {
        pcVar1 = *(code **)(*in_ECX + 0x78);
        guard_check_icall();
        pCVar3 = (CObject *)(*pcVar1)();
        pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar3);
        *piVar2 = (int)pCVar3;
      }
      return *piVar2 != 0;
    }
  }
  return false;
}




/* vtable slots: CPaneContainerManager[3] */
/* 008c05f0  FUN_008c05f0  115 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008c05f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  CPaneContainer *this;
  int iVar1;
  CPaneContainerManager *in_ECX;
  undefined4 uVar2;
  
  uVar2 = 0;
  *(undefined4 *)(in_ECX + 0x4c) = param_1;
  *(int *)(in_ECX + 0x40) = param_3;
  if (*(int *)(in_ECX + 0x3c) == 0) {
    if (param_3 == 0) {
      iVar1 = FUN_0078e624(0x9c);
      if (iVar1 != 0) {
        uVar2 = FUN_008b9e37(in_ECX,0,0,0);
      }
      *(undefined4 *)(in_ECX + 0x3c) = uVar2;
    }
    else {
      this = (CPaneContainer *)FUN_0079d90c();
      *(CPaneContainer **)(in_ECX + 0x3c) = this;
      CPaneContainer::SetPaneContainerManager(this,in_ECX,0);
    }
    *(undefined4 *)(in_ECX + 0x44) = param_2;
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CPaneContainerManager[25] */
/* 008c078e  FUN_008c078e  87 bytes, 0 callers */

undefined4 FUN_008c078e(void)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  do {
    if (local_8 == 0) {
      return 0;
    }
    pCVar2 = (CObject *)FUN_0049acb0(&local_8);
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar2);
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x180);
    guard_check_icall();
    iVar3 = (*pcVar1)();
  } while (iVar3 == 0);
  return 1;
}




/* vtable slots: CPaneContainerManager[24] */
/* 008c07e5  FUN_008c07e5  88 bytes, 0 callers */

undefined4 FUN_008c07e5(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int iVar4;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  do {
    if (local_8 == 0) {
      return 0;
    }
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,(CObject *)*puVar2);
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x1cc);
    guard_check_icall();
    iVar4 = (*pcVar1)();
  } while (iVar4 == 0);
  return 1;
}




/* vtable slots: CPaneContainerManager[22] */
/* 008c083d  FUN_008c083d  87 bytes, 0 callers */

void FUN_008c083d(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*puVar2);
    if (pCVar3 != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x1f0);
      guard_check_icall(param_1);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CPaneContainerManager[35] */
/* 008c0894  FindPaneContainer  65 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CPaneContainer * __thiscall CPaneContainerManager::FindPaneContainer(class
   CDockablePane *,int &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

CPaneContainer * __thiscall
CPaneContainerManager::FindPaneContainer
          (CPaneContainerManager *this,CDockablePane *param_1,int *param_2)

{
  CPaneContainer *pCVar1;
  
  if (*(int *)(this + 0x3c) == 0) {
    pCVar1 = (CPaneContainer *)0x0;
  }
  else {
    *param_2 = 1;
    pCVar1 = (CPaneContainer *)FUN_008bb422(param_1,0);
    if (pCVar1 == (CPaneContainer *)0x0) {
      pCVar1 = (CPaneContainer *)FUN_008bb422(param_1,1);
      *param_2 = 0;
    }
  }
  return pCVar1;
}




/* vtable slots: CPaneContainerManager[12] */
/* 008c08eb  FUN_008c08eb  227 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c08eb(LPRECT param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int local_2c;
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
  local_2c = in_ECX[2];
  while (local_2c != 0) {
    iVar2 = FUN_0049acb0(&local_2c);
    GetWindowRect(*(HWND *)(iVar2 + 0x20),&local_28);
    UnionRect(&local_18,&local_18,&local_28);
  }
  local_2c = in_ECX[9];
  while (local_2c != 0) {
    iVar2 = FUN_0049acb0(&local_2c);
    GetWindowRect(*(HWND *)(iVar2 + 0x20),&local_28);
    UnionRect(&local_18,&local_18,&local_28);
  }
  pcVar1 = *(code **)(*in_ECX + 0x2c);
  guard_check_icall(param_1);
  (*pcVar1)();
  SubtractRect(param_1,param_1,&local_18);
  return;
}




/* vtable slots: CPaneContainerManager[29] */
/* 008c09ce  FUN_008c09ce  4 bytes, 0 callers */

undefined4 FUN_008c09ce(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4c);
}




/* vtable slots: CPaneContainerManager[28] */
/* 008c09d2  FUN_008c09d2  16 bytes, 0 callers */

undefined4 FUN_008c09d2(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    return *(undefined4 *)(*(int *)(in_ECX + 8) + 8);
  }
  return 0;
}




/* vtable slots: CPaneContainerManager[30] */
/* 008c09e2  FUN_008c09e2  75 bytes, 0 callers */

CObject * FUN_008c09e2(void)

{
  CObject *pCVar1;
  uint uVar2;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  do {
    if (local_8 == 0) {
      return (CObject *)0x0;
    }
    pCVar1 = (CObject *)FUN_0049acb0(&local_8);
    pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar1);
    uVar2 = FUN_00797b3d();
  } while ((uVar2 & 0x10000000) == 0);
  return pCVar1;
}




/* vtable slots: CPaneContainerManager[17] */
/* 008c0a2d  FUN_008c0a2d  645 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c0a2d(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  LONG LVar5;
  int *piVar6;
  int iVar7;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int *local_40;
  int *local_3c;
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *param_3 = 0;
  local_3c = param_3;
  *param_2 = 0;
  *param_4 = 0xffffffff;
  local_40 = param_2;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect((HWND)param_1[8],&local_18);
  if (param_1[0x4b] == 0) {
    piVar6 = (int *)FUN_008bb422(param_1,2);
    if (piVar6 == (int *)0x0) {
      return;
    }
    pcVar1 = *(code **)(*piVar6 + 0xc);
    guard_check_icall(&local_28,0);
    (*pcVar1)();
    local_48 = 0;
    local_44 = 0;
    local_50 = 0;
    local_4c = 0;
    pcVar1 = *(code **)(*piVar6 + 0x14);
    guard_check_icall(&local_48);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar6 + 0x18);
    guard_check_icall(&local_50);
    (*pcVar1)();
    pcVar1 = *(code **)(*param_1 + 0x164);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      iVar7 = (local_48 - local_18.left) + local_28.left;
      iVar3 = (local_28.right - local_50) - local_18.right;
    }
    else {
      iVar7 = (local_44 - local_18.top) + local_28.top + 1;
      iVar3 = (local_28.bottom - local_4c) - local_18.bottom;
    }
    *param_2 = iVar7;
    *local_3c = iVar3 + -1;
    goto LAB_008c0c8b;
  }
  pcVar1 = *(code **)(*param_1 + 0x19c);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  iVar3 = FUN_0085a847(uVar2);
  pcVar1 = *(code **)(**(int **)(local_4c + 0x3c) + 0xc);
  guard_check_icall(&local_28,0);
  (*pcVar1)();
  local_48 = 0;
  local_44 = 0;
  pcVar1 = *(code **)(**(int **)(local_4c + 0x3c) + 0x10);
  guard_check_icall(&local_48);
  (*pcVar1)();
  InflateRect(&local_28,-local_48,-local_44);
  local_38.left = *(int *)(iVar3 + 0xf8);
  local_38.top = *(int *)(iVar3 + 0xfc);
  local_38.right = *(int *)(iVar3 + 0x100);
  local_38.bottom = *(int *)(iVar3 + 0x104);
  pcVar1 = *(code **)(*param_1 + 0x19c);
  guard_check_icall();
  (*pcVar1)();
  FUN_0079e8b8(&local_38);
  InflateRect(&local_38,-DAT_00a00cc0,-DAT_00a00cc0);
  pcVar1 = *(code **)(*param_1 + 0x194);
  guard_check_icall();
  uVar4 = (*pcVar1)();
  if ((uVar4 & 0x1000) == 0) {
    if ((uVar4 & 0x2000) != 0) {
      *local_40 = (local_28.top - local_18.top) + 1;
      LVar5 = local_38.bottom;
LAB_008c0bc6:
      iVar3 = LVar5 - local_18.bottom;
      goto LAB_008c0bc9;
    }
    if ((uVar4 & 0x4000) != 0) {
      *local_40 = (local_38.left - local_18.left) + 1;
      LVar5 = local_28.right;
      goto LAB_008c0b7b;
    }
    if ((uVar4 & 0x8000) != 0) {
      *local_40 = (local_38.top - local_18.top) + 1;
      LVar5 = local_28.bottom;
      goto LAB_008c0bc6;
    }
  }
  else {
    *local_40 = (local_28.left - local_18.left) + 1;
    LVar5 = local_38.right;
LAB_008c0b7b:
    iVar3 = LVar5 - local_18.right;
LAB_008c0bc9:
    *local_3c = iVar3 + -1;
  }
  piVar6 = *(int **)(local_4c + 0x3c);
LAB_008c0c8b:
  pcVar1 = *(code **)(*piVar6 + 0x1c);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *param_4 = uVar2;
  return;
}




/* vtable slots: CPaneContainerManager[20] */
/* 008c0cb2  FUN_008c0cb2  46 bytes, 0 callers */

void FUN_008c0cb2(undefined4 *param_1)

{
  code *pcVar1;
  int in_ECX;
  
  param_1[1] = 0;
  *param_1 = 0;
  if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x3c) + 0x10);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CPaneContainerManager[0] */
/* 008c0cef  FUN_008c0cef  6 bytes, 0 callers */

undefined ** FUN_008c0cef(void)

{
  return &PTR_s_CPaneContainerManager_009a2dc8;
}




/* vtable slots: CPaneContainerManager[21] */
/* 008c0d04  FUN_008c0d04  72 bytes, 0 callers */

int FUN_008c0d04(void)

{
  CObject *pCVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  iVar3 = 0;
  while (local_8 != 0) {
    pCVar1 = (CObject *)FUN_0049acb0(&local_8);
    AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar1);
    uVar2 = FUN_00797b3d();
    if ((uVar2 & 0x10000000) != 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}




/* vtable slots: CPaneContainerManager[11] */
/* 008c0d4c  FUN_008c0d4c  36 bytes, 0 callers */

void FUN_008c0d4c(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x3c) + 0xc);
  guard_check_icall(param_1,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CPaneContainerManager[23] */
/* 008c0d70  HideAll  121 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CPaneContainerManager::HideAll(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall CPaneContainerManager::HideAll(CPaneContainerManager *this)

{
  undefined4 *puVar1;
  CObject *pCVar2;
  int local_8;
  
  local_8 = *(int *)(this + 8);
  while (local_8 != 0) {
    puVar1 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_DAT_0097c53c,(CObject *)*puVar1);
    if (pCVar2 != (CObject *)0x0) {
      FUN_00797f20(0);
    }
  }
  local_8 = *(int *)(this + 0x24);
  while (local_8 != 0) {
    puVar1 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_DAT_0097c53c,(CObject *)*puVar1);
    if (pCVar2 != (CObject *)0x0) {
      FUN_00797f20(0);
    }
  }
  return;
}




/* vtable slots: CPaneContainerManager[9] */
/* 008c0de9  FUN_008c0de9  67 bytes, 0 callers */

undefined4 FUN_008c0de9(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(in_ECX + 0x3c) != 0) {
    if (param_2 != 0) {
      iVar1 = FUN_007a198a(param_2,0);
      if (iVar1 != 0) {
        uVar2 = FUN_008bf75d(param_2,param_1,iVar1,param_3);
      }
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CPaneContainerManager[19] */
/* 008c0e36  FUN_008c0e36  14 bytes, 0 callers */

undefined4 FUN_008c0e36(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar3 = *(int *)(in_ECX + 0x3c);
  if (iVar3 == 0) {
    return 0;
  }
  if (*(int *)(iVar3 + 4) == 0) {
LAB_008bbe1f:
    if (*(int *)(iVar3 + 8) != 0) {
      uVar1 = FUN_00797b3d();
      if ((uVar1 >> 0x1c & 1) != 0) goto LAB_008bbe51;
    }
    if (*(int *)(iVar3 + 0x10) != 0) {
      iVar2 = FUN_008bbe09();
      if (iVar2 != 0) goto LAB_008bbe51;
    }
    if (*(int *)(iVar3 + 0x14) != 0) {
      iVar3 = FUN_008bbe09();
      if (iVar3 != 0) goto LAB_008bbe51;
    }
    uVar4 = 0;
  }
  else {
    uVar1 = FUN_00797b3d();
    if ((uVar1 >> 0x1c & 1) == 0) goto LAB_008bbe1f;
LAB_008bbe51:
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CPaneContainerManager[10] */
/* 008c0e64  FUN_008c0e64  458 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008c0e64(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  int local_30;
  int local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_30 = 0;
  local_2c = 0;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  pcVar1 = *(code **)(*(int *)in_ECX[0xf] + 0xc);
  guard_check_icall(&local_18,0);
  (*pcVar1)();
  piVar4 = &local_30;
  pcVar1 = *(code **)(*(int *)in_ECX[0xf] + 0x10);
  guard_check_icall(piVar4);
  (*pcVar1)();
  if (param_1 == (int *)in_ECX[0x11]) {
    pcVar1 = *(code **)(*param_1 + 0x194);
    guard_check_icall(piVar4);
    iVar2 = (*pcVar1)();
    CWnd::ScreenToClient((CWnd *)in_ECX[0x13],&local_18);
    uVar3 = FUN_00797acc();
    if (iVar2 == 0x1000) {
      if ((uVar3 & 0x400000) == 0) {
        local_18.right = local_18.right + param_3;
      }
      else {
        local_18.left = local_18.left + param_3;
      }
      if (local_18.right - local_18.left < local_30) {
        local_18.right = local_30 + local_18.left;
      }
    }
    else if (iVar2 == 0x2000) {
      local_18.bottom = local_18.bottom + param_3;
      if (local_18.bottom - local_18.top < local_2c) {
        local_18.bottom = local_18.top + local_2c;
      }
    }
    else if (iVar2 == 0x4000) {
      if ((uVar3 & 0x400000) == 0) {
        local_18.left = local_18.left + param_3;
      }
      else {
        local_18.right = local_18.right + param_3;
      }
      if (local_18.right - local_18.left < local_30) {
        local_18.left = local_18.right - local_30;
      }
    }
    else if ((iVar2 == 0x8000) &&
            (local_18.top = local_18.top + param_3, local_18.bottom - local_18.top < local_2c)) {
      local_18.top = local_18.bottom - local_2c;
    }
    iVar2 = *in_ECX;
    guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,param_4);
    (**(code **)(iVar2 + 0x38))();
  }
  else {
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    GetWindowRect((HWND)param_1[8],&local_28);
    piVar4 = (int *)FUN_008bb422(param_1,2);
    if (piVar4 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar4 + 0x38);
      guard_check_icall(param_3,param_4);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
  }
  return 0;
}




/* vtable slots: CPaneContainerManager[18] */
/* 008c102e  FUN_008c102e  38 bytes, 0 callers */

void FUN_008c102e(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX[0xf] != 0) {
    FUN_008baee0();
  }
  pcVar1 = *(code **)(*in_ECX + 0x4c);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CPaneContainerManager[26] */
/* 008c1054  FUN_008c1054  617 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CObject * FUN_008c1054(LONG param_1,LONG param_2,int param_3,int param_4,undefined4 *param_5,
                      uint *param_6)

{
  code *pcVar1;
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  undefined4 *puVar2;
  CObject *pCVar3;
  uint uVar4;
  BOOL BVar5;
  int iVar6;
  HWND pHVar7;
  CWnd *pCVar8;
  int in_ECX;
  int local_40;
  uint *local_3c;
  RECT local_38;
  tagRECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_3c = param_6;
  *param_5 = 0;
  local_40 = *(int *)(in_ECX + 8);
  do {
    do {
      do {
        if (local_40 == 0) {
          if (param_4 == 0) {
            local_3c = *(uint **)(in_ECX + 8);
            local_40 = 0;
            while (local_3c != (uint *)0x0) {
              puVar2 = (undefined4 *)FUN_0044f2d0(&local_3c);
              pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                          (CObject *)*puVar2);
              local_18.left = 0;
              local_18.top = 0;
              local_18.right = 0;
              local_18.bottom = 0;
              GetWindowRect(*(HWND *)(pCVar3 + 0x20),&local_18);
              InflateRect(&local_18,param_3,param_3);
              pt_03.y = param_2;
              pt_03.x = param_1;
              BVar5 = PtInRect(&local_18,pt_03);
              if (BVar5 != 0) {
                return pCVar3;
              }
            }
          }
          return (CObject *)0x0;
        }
        puVar2 = (undefined4 *)FUN_0044f2d0(&local_40);
        pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                                    (CObject *)*puVar2);
      } while ((pCVar3 == (CObject *)0x0) || (uVar4 = FUN_00797b3d(), (uVar4 & 0x10000000) == 0));
      local_28.left = 0;
      local_28.top = 0;
      local_28.right = 0;
      local_28.bottom = 0;
      GetWindowRect(*(HWND *)(pCVar3 + 0x20),&local_28);
      local_38.left = 0;
      local_38.top = 0;
      local_38.right = 0;
      local_38.bottom = 0;
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x32c);
      guard_check_icall(&local_38,&local_18);
      (*pcVar1)();
      pt.y = param_2;
      pt.x = param_1;
      BVar5 = PtInRect(&local_38,pt);
      if ((BVar5 != 0) ||
         (pt_00.y = param_2, pt_00.x = param_1, BVar5 = PtInRect(&local_18,pt_00), BVar5 != 0)) {
        *param_5 = 1;
        return pCVar3;
      }
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x334);
      guard_check_icall(param_1,param_2,1);
      iVar6 = (*pcVar1)();
      if (iVar6 == 2) {
        *local_3c = 1;
        return pCVar3;
      }
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x1a4);
      guard_check_icall();
      iVar6 = (*pcVar1)();
      local_28.top = local_28.top + iVar6;
      local_28.bottom = local_28.bottom + (local_18.top - local_18.bottom);
      pt_01.y = param_2;
      pt_01.x = param_1;
      BVar5 = PtInRect(&local_28,pt_01);
    } while (BVar5 == 0);
    pHVar7 = GetParent(*(HWND *)(pCVar3 + 0x20));
    pCVar8 = CWnd::FromHandle(pHVar7);
    iVar6 = FUN_0085a847(pCVar8);
    if ((((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x1b8), iVar6 != 0)) &&
        (*(int *)(iVar6 + 8) != 0)) && (*(int *)(iVar6 + 4) != 0)) {
      if (4 < *(int *)(iVar6 + 0x110) - 4U) {
        return pCVar3;
      }
      *local_3c = (uint)(*(int *)(iVar6 + 0x110) == 8);
      return pCVar3;
    }
    InflateRect(&local_28,-param_3,-param_3);
    pt_02.y = param_2;
    pt_02.x = param_1;
    BVar5 = PtInRect(&local_28,pt_02);
    if (BVar5 == 0) {
      return pCVar3;
    }
  } while (param_3 != 0);
  return pCVar3;
}




/* vtable slots: CPaneContainerManager[33] */
/* 008c1357  RemovePaneDivider  72 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CPaneContainerManager::RemovePaneDivider(class CPaneDivider *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CPaneContainerManager::RemovePaneDivider(CPaneContainerManager *this,CPaneDivider *param_1)

{
  int iVar1;
  
  iVar1 = FUN_007a198a(param_1,0);
  if (iVar1 != 0) {
    FUN_007a1ad4(iVar1);
    *(undefined4 *)(param_1 + 0x168) = 0;
  }
  if (*(int *)(this + 0x3c) != 0) {
    iVar1 = FUN_008bb422(param_1,2);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
  }
  return;
}




/* vtable slots: CPaneContainerManager[13] */
/* 008c139f  FUN_008c139f  323 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008c139f(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  CObject *pCVar5;
  uint uVar6;
  int *in_ECX;
  undefined **local_38 [7];
  int local_1c;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x8c13ab;
  if (in_ECX[0xf] != 0) {
    local_14[0] = 0;
    pcVar1 = *(code **)(*in_ECX + 0x8c);
    guard_check_icall(param_1,local_14);
    piVar2 = (int *)(*pcVar1)();
    if (piVar2 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar2 + 0x28);
      guard_check_icall(param_1,local_14[0] == 0);
      (*pcVar1)();
      FUN_008baee0();
      if (piVar2[3] != 0) {
        iVar3 = FUN_007a198a(piVar2[3],0);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        FUN_008bf222(0);
      }
      local_1c = FUN_007a198a(param_1,0);
      if (local_1c != 0) {
        CList<HWND__*,HWND__*>::CList<HWND__*,HWND__*>((CList<HWND__*,HWND__*> *)local_38,10);
        local_18 = in_ECX[2];
        local_8 = 0;
        while (local_18 != 0) {
          puVar4 = (undefined4 *)FUN_0044f2d0(&local_18);
          pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_DAT_0097c53c,(CObject *)*puVar4);
          uVar6 = 0;
          if (pCVar5 != (CObject *)0x0) {
            uVar6 = *(uint *)(pCVar5 + 0x20);
          }
          CList<unsigned_int,unsigned_int>::AddTail
                    ((CList<unsigned_int,unsigned_int> *)local_38,uVar6);
        }
        iVar3 = FUN_0079d98a(&PTR_s_CPaneFrameWnd_00a008b0);
        FUN_0085f316(local_38,iVar3 == 0);
        FUN_007a1ad4(local_1c);
        local_8 = 1;
        local_38[0] = CList<HWND__*,HWND__*>::vftable;
        RemoveAll();
      }
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CPaneContainerManager[16] */
/* 008c14e3  FUN_008c14e3  124 bytes, 0 callers */

undefined4 FUN_008c14e3(undefined4 param_1,CDockablePane *param_2)

{
  code *pcVar1;
  __POSITION *p_Var2;
  CPaneContainer *this;
  int *in_ECX;
  int local_8;
  
  p_Var2 = (__POSITION *)FUN_007a198a(param_1,0);
  if (p_Var2 == (__POSITION *)0x0) {
    CObList::AddTail((CObList *)(in_ECX + 1),(CObject *)param_2);
  }
  else {
    local_8 = 0;
    pcVar1 = *(code **)(*in_ECX + 0x8c);
    guard_check_icall(param_1,&local_8);
    this = (CPaneContainer *)(*pcVar1)();
    if (this != (CPaneContainer *)0x0) {
      CPaneContainer::SetPane(this,param_2,local_8);
      CObList::InsertAfter((CObList *)(in_ECX + 1),p_Var2,(CObject *)param_2);
      FUN_007a1ad4(p_Var2);
    }
  }
  return 1;
}




/* vtable slots: CPaneContainerManager[15] */
/* 008c155f  FUN_008c155f  80 bytes, 0 callers */

void FUN_008c155f(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
    uVar2 = 1;
    if ((param_1 != 2) && (param_1 != 1)) {
      uVar2 = 0;
    }
    iVar1 = **(int **)(in_ECX + 0x3c);
    guard_check_icall(((uint)(param_2 != 0) * 2 + -1) * param_3,uVar2,1,1,param_4);
    (**(code **)(iVar1 + 0x34))();
  }
  return;
}




/* vtable slots: CPaneContainerManager[14] */
/* 008c15af  FUN_008c15af  58 bytes, 0 callers */

void FUN_008c15af(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
    iVar1 = **(int **)(in_ECX + 0x3c);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,0);
    (**(code **)(iVar1 + 0x48))();
  }
  return;
}




/* vtable slots: CPaneContainerManager[2] */
/* 008c15e9  FUN_008c15e9  531 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CArchive * FUN_008c15e9(CArchive *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  long lVar3;
  CObject *pCVar4;
  int iVar5;
  CWnd *pCVar6;
  CArchive *pCVar7;
  CDockablePane *pCVar8;
  CArchive *in_ECX;
  CPaneContainer *pCVar9;
  CArchive *local_1c;
  CPaneContainer *local_18;
  uint local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8c15f5;
  local_18 = *(CPaneContainer **)(in_ECX + 0x3c);
  local_1c = in_ECX;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    pcVar1 = *(code **)(*(int *)local_18 + 8);
    pCVar7 = param_1;
    guard_check_icall(param_1);
    (*pcVar1)();
    if (*(int **)(in_ECX + 0x44) == (int *)0x0) {
      iVar5 = FUN_0079d98a(&PTR_s_CPaneFrameWnd_00a008b0);
      if (iVar5 == 0) goto LAB_008c17c9;
      pCVar6 = CWnd::FromHandlePermanent(*(HWND__ **)(*(int *)(in_ECX + 0x4c) + 200));
    }
    else {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x44) + 0x19c);
      guard_check_icall(pCVar7);
      pCVar6 = (CWnd *)(*pcVar1)();
    }
    local_1c = (CArchive *)FUN_0085a847(pCVar6);
    if (local_1c == (CArchive *)0x0) {
LAB_008c17c9:
      local_18 = (CPaneContainer *)FUN_004121b0(0x10);
      pCVar7 = (CArchive *)0x0;
      local_8 = 0;
      if (local_18 != (CPaneContainer *)0x0) {
        pCVar7 = (CArchive *)FUN_007a563a(0,0);
      }
      local_8 = 0xffffffff;
      local_1c = pCVar7;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_1c,&DAT_009eb3ec);
    }
    local_18 = (CPaneContainer *)0x0;
    pCVar7 = CArchive::operator>>(param_1,(long *)&local_18);
    local_14[0] = 0;
    pCVar9 = local_18;
    if (0 < (int)local_18) {
      do {
        CArchive::operator>>(param_1,(long *)local_14);
        if (local_14[0] == 0xffffffff) {
          CArchive::operator>>(param_1,(long *)local_14);
          pCVar8 = CPaneContainer::FindTabbedPane(*(CPaneContainer **)(in_ECX + 0x3c),local_14[0]);
          pCVar7 = (CArchive *)0x0;
          if (pCVar8 != (CDockablePane *)0x0) {
            pCVar7 = (CArchive *)CObList::AddTail((CObList *)(in_ECX + 4),(CObject *)pCVar8);
          }
        }
        else {
          pcVar1 = *(code **)(*(int *)local_1c + 0x24);
          guard_check_icall(local_14[0],1);
          pCVar4 = (CObject *)(*pcVar1)();
          pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar4);
          pCVar7 = (CArchive *)0x0;
          if (pCVar4 != (CObject *)0x0) {
            CObList::AddTail((CObList *)(in_ECX + 4),pCVar4);
            pCVar7 = (CArchive *)
                     CPaneContainer::SetUpByID
                               (*(CPaneContainer **)(in_ECX + 0x3c),local_14[0],
                                (CDockablePane *)pCVar4);
          }
        }
        pCVar9 = pCVar9 + -1;
      } while (pCVar9 != (CPaneContainer *)0x0);
    }
  }
  else {
    CPaneContainer::ReleaseEmptyPaneContainer(local_18);
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x3c) + 8);
    guard_check_icall(param_1);
    (*pcVar1)();
    CArchive::operator<<(param_1,*(long *)(local_1c + 0x10));
    local_14[0] = *(uint *)(local_1c + 8);
    pCVar7 = (CArchive *)0x0;
    if (local_14[0] != 0) {
      local_1c = local_1c + 4;
      do {
        puVar2 = (undefined4 *)FUN_0044f2d0(local_14);
        pCVar4 = (CObject *)*puVar2;
        lVar3 = FUN_00797a2b();
        if (lVar3 == -1) {
          pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,pCVar4);
          pcVar1 = *(code **)(*(int *)pCVar4 + 0x3cc);
          guard_check_icall(0,0);
          iVar5 = (*pcVar1)();
          if (iVar5 != 0) {
            lVar3 = FUN_00797a2b();
            CArchive::operator<<(param_1,-1);
            goto LAB_008c16a2;
          }
        }
        else {
LAB_008c16a2:
          CArchive::operator<<(param_1,lVar3);
        }
        pCVar7 = local_1c;
      } while (local_14[0] != 0);
    }
  }
  return pCVar7;
}




/* vtable slots: CPaneContainerManager[32] */
/* 008c17fd  FUN_008c17fd  50 bytes, 0 callers */

void FUN_008c17fd(undefined4 param_1)

{
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  while (local_8 != 0) {
    FUN_0044f2d0(&local_8);
    FUN_00891309(param_1);
  }
  return;
}




/* vtable slots: CPaneContainerManager[34] */
/* 008c182f  FUN_008c182f  74 bytes, 0 callers */

void FUN_008c182f(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 local_8;
  
  local_8 = 1;
  pcVar1 = *(code **)(*in_ECX + 0x8c);
  guard_check_icall(param_1,&local_8);
  piVar2 = (int *)(*pcVar1)();
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0x2c);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}



