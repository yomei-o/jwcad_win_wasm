/* CDockingManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDockingManager[1] */
/* 00844f80  FUN_00844f80  51 bytes, 0 callers */

void FUN_00844f80(byte param_1)

{
  FUN_00844c5b();
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




/* vtable slots: CDockingManager[7] */
/* 00845002  AddMiniFrame  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CDockingManager::AddMiniFrame(class CPaneFrameWnd *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CDockingManager::AddMiniFrame(CDockingManager *this,CPaneFrameWnd *param_1)

{
  int iVar1;
  
  iVar1 = FUN_007a198a(param_1,0);
  if (iVar1 == 0) {
    CObList::AddTail((CObList *)(this + 200),(CObject *)param_1);
  }
  return (uint)(iVar1 == 0);
}




/* vtable slots: CDockingManager[14] */
/* 0084519e  FUN_0084519e  1447 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0084519e(HDWP param_1)

{
  CObject *pCVar1;
  code *pcVar2;
  LONG LVar3;
  LONG LVar4;
  LONG LVar5;
  LONG LVar6;
  LONG LVar7;
  LONG LVar8;
  LONG LVar9;
  LONG LVar10;
  BOOL BVar11;
  int iVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 uVar15;
  CObject *pCVar16;
  CPaneDivider *pCVar17;
  HWND pHVar18;
  CWnd *this;
  int *piVar19;
  int iVar20;
  int in_ECX;
  int local_5c;
  int local_58;
  int local_54;
  CObject *local_50;
  int local_4c;
  uint local_48;
  int local_44;
  HDWP local_40;
  int local_3c;
  tagRECT local_38;
  RECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_40 = param_1;
  if (((DAT_00a13b30 == 0) && (*(int *)(in_ECX + 0x154) == 0)) && (*(int *)(in_ECX + 0xe4) != 0)) {
    GetClientRect(*(HWND *)(*(int *)(in_ECX + 0xe4) + 0x20),(LPRECT)(in_ECX + 0xf8));
    BVar11 = IsRectEmpty((RECT *)(in_ECX + 0x10));
    if (BVar11 == 0) {
      ((LPRECT)(in_ECX + 0xf8))->left = ((RECT *)(in_ECX + 0x10))->left;
      *(undefined4 *)(in_ECX + 0xfc) = *(undefined4 *)(in_ECX + 0x14);
      *(undefined4 *)(in_ECX + 0x100) = *(undefined4 *)(in_ECX + 0x18);
      *(undefined4 *)(in_ECX + 0x104) = *(undefined4 *)(in_ECX + 0x1c);
    }
    if (((*(int *)(in_ECX + 4) != 0) && (*(int *)(in_ECX + 0x2c) != 0)) &&
       (((iVar12 = DAT_00a13a1c, DAT_00a13a1c == 0 && (iVar12 = FUN_00792b4c(), iVar12 == 0)) ||
        (((*(int *)(iVar12 + 0x20) == 0 ||
          (BVar11 = IsWindow(*(HWND *)(iVar12 + 0x20)), BVar11 == 0)) ||
         (BVar11 = IsIconic(*(HWND *)(iVar12 + 0x20)), BVar11 == 0)))))) {
      local_54 = 0;
      local_28.left = *(LONG *)(in_ECX + 0x108);
      *(undefined4 *)(in_ECX + 0x154) = 1;
      local_28.top = *(LONG *)(in_ECX + 0x10c);
      local_28.right = *(LONG *)(in_ECX + 0x110);
      local_28.bottom = *(LONG *)(in_ECX + 0x114);
      if ((local_40 == (HDWP)0x0) && (*(int *)(in_ECX + 0x130) == 0)) {
        local_40 = BeginDeferWindowPos(*(int *)(in_ECX + 0x2c));
        local_54 = 1;
      }
      local_18.left = *(LONG *)(in_ECX + 0xe8);
      local_18.top = *(int *)(in_ECX + 0xec);
      local_18.right = *(int *)(in_ECX + 0xf0);
      local_18.bottom = *(int *)(in_ECX + 0xf4);
      GetClientRect(*(HWND *)(*(int *)(in_ECX + 0xe4) + 0x20),&local_18);
      BVar11 = IsRectEmpty((RECT *)(in_ECX + 0x10));
      if (BVar11 == 0) {
        local_18.left = ((RECT *)(in_ECX + 0x10))->left;
        local_18.top = *(int *)(in_ECX + 0x14);
        local_18.right = *(int *)(in_ECX + 0x18);
        local_18.bottom = *(int *)(in_ECX + 0x1c);
      }
      FUN_0079e8b8(&local_18);
      local_44 = *(int *)(in_ECX + 0x28);
      local_38.left = 0;
      local_38.top = 0;
      local_38.right = 0;
      local_38.bottom = 0;
      local_3c = local_44;
      if (local_44 != 0) {
        do {
          FUN_0049ad10(&local_3c);
          local_44 = local_3c;
          if (local_3c == 0) goto LAB_00845354;
          iVar12 = FUN_0079d98a(&PTR_s_CDockSite_00997564);
        } while ((iVar12 == 0) &&
                (iVar12 = FUN_0079d98a(&PTR_s_CAutoHideDockSite_009a2e90), iVar12 == 0));
        FUN_0044f2d0(&local_3c);
        local_44 = local_3c;
        if (local_3c != 0) {
          FUN_0044f2d0(&local_3c);
          local_44 = local_3c;
        }
      }
LAB_00845354:
      local_3c = *(int *)(in_ECX + 0x24);
joined_r0x0084535c:
      if (local_3c != 0) {
        puVar13 = (undefined4 *)FUN_0044f2d0(&local_3c);
        pCVar1 = (CObject *)*puVar13;
        local_50 = pCVar1;
        uVar14 = FUN_00797b3d();
        if (((uVar14 & 0x10000000) != 0) ||
           (((iVar12 = FUN_0079d98a(&PTR_s_CPane_0098ac24), iVar12 == 0 &&
             (iVar12 = FUN_0079d98a(&PTR_s_CPaneDivider_009a27cc), iVar12 == 0)) &&
            ((iVar12 = FUN_0079d98a(&PTR_s_CDockSite_00997564), iVar12 == 0 ||
             (((*(int *)(in_ECX + 0x130) == 0 && (iVar12 = FUN_0084785d(), iVar12 == 0)) &&
              (*(int *)(in_ECX + 0x1e4) == 0)))))))) {
          GetWindowRect(*(HWND *)(pCVar1 + 0x20),&local_38);
          pcVar2 = *(code **)(*(int *)pCVar1 + 0x194);
          guard_check_icall();
          local_48 = (*pcVar2)();
          pcVar2 = *(code **)(*(int *)pCVar1 + 0x164);
          guard_check_icall();
          local_4c = (*pcVar2)();
          pcVar2 = *(code **)(*(int *)pCVar1 + 0x178);
          guard_check_icall();
          uVar15 = (*pcVar2)();
          iVar12 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
          if (iVar12 != 0) {
            pCVar16 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar1);
            pCVar17 = CDockablePane::GetDefaultPaneDivider((CDockablePane *)pCVar16);
            if (pCVar17 != (CPaneDivider *)0x0) goto joined_r0x0084535c;
          }
          pcVar2 = *(code **)(*(int *)pCVar1 + 0x260);
          guard_check_icall(&local_5c,0,local_4c);
          (*pcVar2)();
          if (local_4c == 0) {
            if ((local_48 & 0x1000) == 0) {
              local_38.left = local_38.right - local_5c;
            }
            else {
              local_38.right = local_5c + local_38.left;
            }
          }
          else if ((local_48 & 0x2000) == 0) {
            local_38.top = local_38.bottom - local_58;
          }
          else {
            local_38.bottom = local_58 + local_38.top;
          }
          FUN_00845be1(&local_18,&local_38,local_48,local_4c,uVar15);
          LVar6 = local_38.bottom;
          LVar5 = local_38.right;
          LVar4 = local_38.top;
          LVar3 = local_38.left;
          pCVar1 = local_50;
          iVar12 = FUN_0079d98a(&PTR_s_CDockSite_00997564);
          pCVar16 = pCVar1;
          LVar7 = local_38.left;
          LVar8 = local_38.top;
          LVar9 = local_38.right;
          LVar10 = local_38.bottom;
          if (iVar12 != 0) {
            CWnd::ScreenToClient((CWnd *)pCVar1,&local_38);
            pcVar2 = *(code **)(*(int *)pCVar1 + 0x164);
            guard_check_icall();
            iVar12 = (*pcVar2)();
            LVar7 = LVar3;
            LVar8 = LVar4;
            LVar9 = LVar5;
            LVar10 = LVar6;
            if ((iVar12 == 0) ||
               (local_38.right == local_38.left || local_38.right - local_38.left < 0)) {
              pcVar2 = *(code **)(*(int *)pCVar1 + 0x164);
              guard_check_icall();
              iVar12 = (*pcVar2)();
              pCVar16 = local_50;
              if ((iVar12 != 0) ||
                 (local_38.bottom == local_38.top || local_38.bottom - local_38.top < 0))
              goto LAB_00845567;
            }
            pcVar2 = *(code **)(*(int *)pCVar1 + 0x298);
            guard_check_icall(&local_38);
            (*pcVar2)();
            pCVar16 = local_50;
          }
LAB_00845567:
          local_38.bottom = LVar10;
          local_38.right = LVar9;
          local_38.top = LVar8;
          local_38.left = LVar7;
          iVar12 = FUN_0079d98a(&PTR_s_CPaneDivider_009a27cc);
          if (iVar12 == 0) {
            pHVar18 = GetParent(*(HWND *)(pCVar16 + 0x20));
            this = CWnd::FromHandle(pHVar18);
            CWnd::ScreenToClient(this,&local_38);
            pcVar2 = *(code **)(*(int *)pCVar16 + 0x238);
            guard_check_icall(0,local_38.left,local_38.top,local_38.right - local_38.left,
                              local_38.bottom - local_38.top,0x14,local_40);
            local_40 = (HDWP)(*pcVar2)();
          }
          else {
            pcVar2 = *(code **)(*(int *)pCVar16 + 0x284);
            guard_check_icall(&local_38,&local_40);
            (*pcVar2)();
          }
          if ((local_48 & 0x2000) == 0) {
            if ((local_48 & 0x8000) == 0) {
              if ((local_48 & 0x1000) == 0) {
                local_18.right = local_18.right + (LVar3 - LVar5);
              }
              else {
                local_18.left = local_18.left + (LVar5 - LVar3);
              }
            }
            else {
              local_18.bottom = local_18.bottom + (LVar4 - LVar6);
            }
          }
          else {
            local_18.top = local_18.top + (LVar6 - LVar4);
          }
          if (local_44 == local_3c) {
            *(LONG *)(in_ECX + 0x108) = local_18.left;
            *(LONG *)(in_ECX + 0x10c) = local_18.top;
            *(LONG *)(in_ECX + 0x110) = local_18.right;
            *(LONG *)(in_ECX + 0x114) = local_18.bottom;
          }
        }
        goto joined_r0x0084535c;
      }
      *(LONG *)(in_ECX + 0xf8) = local_18.left;
      *(LONG *)(in_ECX + 0xfc) = local_18.top;
      *(LONG *)(in_ECX + 0x100) = local_18.right;
      *(LONG *)(in_ECX + 0x104) = local_18.bottom;
      BVar11 = IsRectEmpty((RECT *)(in_ECX + 0x108));
      if ((BVar11 != 0) || (iVar12 = FUN_0084785d(), iVar12 != 0)) {
        ((RECT *)(in_ECX + 0x108))->left = local_18.left;
        *(LONG *)(in_ECX + 0x10c) = local_18.top;
        *(LONG *)(in_ECX + 0x110) = local_18.right;
        *(LONG *)(in_ECX + 0x114) = local_18.bottom;
      }
      CWnd::ScreenToClient(*(CWnd **)(in_ECX + 0xe4),(tagRECT *)(in_ECX + 0xf8));
      CWnd::ScreenToClient(*(CWnd **)(in_ECX + 0xe4),(tagRECT *)(in_ECX + 0x108));
      BVar11 = EqualRect((tagRECT *)(in_ECX + 0x108),&local_28);
      if (BVar11 == 0) {
        FUN_0084761b(0,1);
      }
      local_3c = *(int *)(in_ECX + 0x24);
      while (local_3c != 0) {
        piVar19 = (int *)FUN_0044f2d0(&local_3c);
        iVar12 = *piVar19;
        iVar20 = FUN_0079d98a(&PTR_s_CAutoHideDockSite_009a2e90);
        if (iVar20 != 0) {
          *(undefined4 *)(iVar12 + 0x150) = 0;
          *(undefined4 *)(iVar12 + 0x154) = 0;
          FUN_008469c7(iVar12);
        }
      }
      if (local_54 != 0) {
        EndDeferWindowPos(local_40);
      }
      if ((*(int **)(in_ECX + 0xe4))[0x2b] != 0) {
        pcVar2 = *(code **)(**(int **)(in_ECX + 0xe4) + 0x178);
        guard_check_icall(1);
        (*pcVar2)();
      }
      *(undefined4 *)(in_ECX + 0x154) = 0;
    }
  }
  return;
}




/* vtable slots: CDockingManager[16] */
/* 00845745  FUN_00845745  164 bytes, 0 callers */

void FUN_00845745(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x24);
  while (local_8 != 0) {
    puVar3 = (undefined4 *)FUN_0044f2d0(&local_8);
    pcVar1 = *(code **)(*(int *)*puVar3 + 0x238);
    guard_check_icall(0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x37,0);
    (*pcVar1)();
  }
  local_8 = *(int *)(in_ECX + 0xcc);
  while (local_8 != 0) {
    puVar3 = (undefined4 *)FUN_0044f2d0(&local_8);
    piVar2 = (int *)*puVar3;
    FUN_00797e71(0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x37);
    pcVar1 = *(code **)(*piVar2 + 0x1fc);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CDockingManager[23] */
/* 008457e9  FUN_008457e9  236 bytes, 0 callers */

undefined4 FUN_008457e9(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  
  iVar4 = *(int *)(in_ECX + 0x104);
  iVar5 = *(int *)(in_ECX + 0xfc);
  iVar3 = FUN_007c2511();
  iVar1 = *(int *)(in_ECX + 0x100);
  iVar2 = *(int *)(in_ECX + 0xf8);
  iVar4 = (*(int *)(iVar3 + 0x1c0) * (iVar4 - iVar5)) / 100;
  iVar5 = FUN_007c2511();
  iVar5 = (*(int *)(iVar5 + 0x1c0) * (iVar1 - iVar2)) / 100;
  if (((param_2 & 0xa000) != 0) && (iVar4 <= param_1[3] - param_1[1])) {
    if ((param_2 & 0x2000) != 0) {
      param_1[3] = iVar4 + param_1[1];
      return 1;
    }
    if ((param_2 & 0x8000) != 0) {
      param_1[1] = param_1[3] - iVar4;
      return 1;
    }
    return 0;
  }
  if ((param_2 & 0x5000) == 0) {
    return 0;
  }
  if (param_1[2] - *param_1 < iVar5) {
    return 0;
  }
  uVar6 = FUN_00797acc();
  if ((param_2 & 0x1000) == 0) {
    if ((param_2 & 0x4000) == 0) {
      return 0;
    }
    if ((uVar6 & 0x400000) != 0) goto LAB_008458cc;
  }
  else if ((uVar6 & 0x400000) == 0) {
LAB_008458cc:
    param_1[2] = *param_1 + iVar5;
    return 1;
  }
  *param_1 = param_1[2] - iVar5;
  return 1;
}




/* vtable slots: CDockingManager[6] */
/* 00846c72  FUN_00846c72  510 bytes, 0 callers */

undefined4
FUN_00846c72(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,int *param_5,
            undefined4 param_6,int *param_7)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  CObject *pCVar5;
  uint uVar6;
  undefined4 uVar7;
  int *in_ECX;
  undefined4 local_c;
  uint local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x10);
  guard_check_icall(param_1,param_2,param_3,1,&PTR_s_CDockablePane_00a00b9c,1,param_6);
  iVar2 = (*pcVar1)();
  *param_5 = iVar2;
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x14);
    guard_check_icall(param_1,param_2,0,1);
    piVar3 = (int *)(*pcVar1)();
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*param_7 + 0x228);
      guard_check_icall(0);
      piVar4 = (int *)(*pcVar1)();
      if (piVar4 != piVar3) {
        pcVar1 = *(code **)(*piVar3 + 0x1ec);
        guard_check_icall(param_1,param_2,1);
        iVar2 = (*pcVar1)();
        if (iVar2 == 2) {
          pcVar1 = *(code **)(*piVar3 + 0x1a4);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if (iVar2 == 1) {
            pcVar1 = *(code **)(*piVar3 + 0x1ac);
            guard_check_icall();
            pCVar5 = (CObject *)(*pcVar1)();
            pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar5);
            *param_5 = (int)pCVar5;
            return 3;
          }
        }
      }
    }
  }
  if ((int *)*param_5 == (int *)0x0) goto LAB_00846e34;
  pcVar1 = *(code **)(*(int *)*param_5 + 0x228);
  guard_check_icall(0);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
LAB_00846db4:
    pcVar1 = *(code **)(*(int *)*param_5 + 0x228);
    guard_check_icall(0);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) goto LAB_00846e34;
  }
  else {
    pcVar1 = *(code **)(*param_7 + 0x1c0);
    guard_check_icall();
    uVar6 = (*pcVar1)();
    if ((uVar6 & 0x40) == 0) goto LAB_00846db4;
    pcVar1 = *(code **)(*(int *)*param_5 + 0x1c0);
    guard_check_icall();
    uVar6 = (*pcVar1)();
    if ((uVar6 & 0x40) == 0) goto LAB_00846db4;
  }
  pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)*param_5);
  if (pCVar5 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar5 + 0x170);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*(int *)pCVar5 + 0x194);
      guard_check_icall();
      uVar6 = (*pcVar1)();
      if ((param_4 & uVar6) == 0) {
        return 0;
      }
    }
    pcVar1 = *(code **)(*(int *)pCVar5 + 0x348);
    guard_check_icall(param_1,param_2,param_3);
    uVar7 = (*pcVar1)();
    return uVar7;
  }
LAB_00846e34:
  *param_5 = 0;
  local_c = 0;
  local_8 = 0;
  iVar2 = FUN_0084787c(param_1,param_2,&local_8,&local_c);
  if ((iVar2 != 0) && ((param_4 & local_8) != 0)) {
    return 2;
  }
  return 0;
}




/* vtable slots: CDockingManager[10] */
/* 00847076  FUN_00847076  143 bytes, 0 callers */

CObject * FUN_00847076(uint param_1,int param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  CObject *pCVar5;
  int in_ECX;
  int local_8;
  
  if (param_2 == 0) {
    local_8 = *(int *)(in_ECX + 0x28);
  }
  else {
    local_8 = *(int *)(in_ECX + 0x24);
  }
  do {
    do {
      if (local_8 == 0) {
        return (CObject *)0x0;
      }
      if (param_2 == 0) {
        puVar2 = (undefined4 *)FUN_0049ad10(&local_8);
      }
      else {
        puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
      }
      pCVar5 = (CObject *)*puVar2;
      iVar3 = FUN_0079d98a(&PTR_s_CDockSite_00997564);
    } while (iVar3 == 0);
    pcVar1 = *(code **)(*(int *)pCVar5 + 0x194);
    guard_check_icall();
    uVar4 = (*pcVar1)();
  } while (uVar4 != (param_1 & 0xf000));
  pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockSite_00997564,pCVar5);
  return pCVar5;
}




/* vtable slots: CDockingManager[11] */
/* 00847105  FUN_00847105  95 bytes, 0 callers */

CObject * FUN_00847105(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int iVar4;
  int in_ECX;
  int local_8;
  
  uVar1 = FUN_00797a2b();
  local_8 = *(int *)(in_ECX + 0x24);
  do {
    if (local_8 == 0) {
      return (CObject *)0x0;
    }
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockSite_00997564,(CObject *)*puVar2);
  } while ((pCVar3 == (CObject *)0x0) || (iVar4 = FUN_00861040(uVar1), iVar4 != param_1));
  return pCVar3;
}




/* vtable slots: CDockingManager[9] */
/* 00847164  FUN_00847164  436 bytes, 0 callers */

CObject * FUN_00847164(uint param_1,int param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  CObject *pCVar4;
  uint uVar5;
  CBasePane *pCVar6;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x40);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar4 = (CObject *)*puVar2;
    iVar3 = FUN_0079d98a(&PTR_s_CPaneDivider_009a27cc);
    if (iVar3 != 0) {
      AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,pCVar4);
      pCVar4 = (CObject *)FUN_008be33b();
    }
    if ((pCVar4 != (CObject *)0x0) && (uVar5 = FUN_00797a2b(), uVar5 == param_1)) {
      return pCVar4;
    }
  }
  local_8 = *(int *)(in_ECX + 0x24);
LAB_008471ce:
  do {
    if (local_8 == 0) {
      if (param_2 == 0) {
        return (CObject *)0x0;
      }
      local_8 = *(int *)(in_ECX + 0xcc);
      do {
        do {
          if (local_8 == 0) {
            pCVar6 = CPaneFrameWnd::FindFloatingPaneByID(param_1);
            return (CObject *)pCVar6;
          }
          puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
          pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,
                                      (CObject *)*puVar2);
        } while (pCVar4 == (CObject *)0x0);
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x1a8);
        guard_check_icall();
        pCVar4 = (CObject *)(*pcVar1)();
        pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar4);
      } while ((pCVar4 == (CObject *)0x0) || (uVar5 = FUN_00797a2b(), uVar5 != param_1));
      return pCVar4;
    }
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar4 = (CObject *)*puVar2;
    uVar5 = FUN_00797a2b();
    if (uVar5 == param_1) {
      return pCVar4;
    }
    iVar3 = FUN_0079d98a(&PTR_s_CBaseTabbedPane_00996820);
    if (iVar3 == 0) {
      iVar3 = FUN_0079d98a(&PTR_s_CDockSite_00997564);
      if (iVar3 != 0) {
        pCVar4 = (CObject *)FUN_00861040(param_1);
        if (pCVar4 != (CObject *)0x0) {
          pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar4);
          return pCVar4;
        }
        goto LAB_008471ce;
      }
      iVar3 = FUN_0079d98a(&PTR_s_CMFCReBar_0099792c);
      if (iVar3 == 0) goto LAB_008471ce;
      pCVar4 = (CObject *)FUN_00797a56(param_1);
    }
    else {
      pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,pCVar4);
      pcVar1 = *(code **)(*(int *)pCVar4 + 0x3c8);
      guard_check_icall(param_1);
      pCVar4 = (CObject *)(*pcVar1)();
    }
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,pCVar4);
    if (pCVar4 != (CObject *)0x0) {
      return pCVar4;
    }
  } while( true );
}




/* vtable slots: CDockingManager[12] */
/* 00847318  FUN_00847318  113 bytes, 0 callers */

void FUN_00847318(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int *in_ECX;
  int local_8;
  
  local_8 = in_ECX[9];
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockSite_00997564,(CObject *)*puVar2);
    if (pCVar3 != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x29c);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x38);
  guard_check_icall(0);
  (*pcVar1)();
  return;
}




/* vtable slots: CDockingManager[5] */
/* 00847389  FUN_00847389  178 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CObject * FUN_00847389(LONG param_1,LONG param_2,CObject *param_3,int param_4)

{
  POINT pt;
  CObject *pCVar1;
  BOOL BVar2;
  int iVar3;
  int in_ECX;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = *(int *)(in_ECX + 0xcc);
  do {
    do {
      if (local_1c == 0) {
        return (CObject *)0x0;
      }
      pCVar1 = (CObject *)FUN_0049acb0(&local_1c);
      pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,pCVar1);
      BVar2 = IsWindowVisible(*(HWND *)(pCVar1 + 0x20));
    } while (((BVar2 == 0) || (pCVar1 == param_3)) ||
            ((iVar3 = FUN_0079d98a(&PTR_s_CMultiPaneFrameWnd_00a00968), iVar3 == 0 && (param_4 != 0)
             )));
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(pCVar1 + 0x20),&local_18);
    pt.y = param_2;
    pt.x = param_1;
    BVar2 = PtInRect(&local_18,pt);
  } while (BVar2 == 0);
  return pCVar1;
}




/* vtable slots: CDockingManager[18] */
/* 0084794d  FUN_0084794d  704 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0084794d(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  CObject *pCVar5;
  undefined4 uVar6;
  int *in_ECX;
  undefined1 local_b8 [72];
  undefined1 local_70 [52];
  undefined4 local_3c;
  undefined4 local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa8;
  local_8 = 0x84795c;
  local_20 = in_ECX;
  FUN_008592c1(&local_2c,L"DockingManagers",param_1);
  local_8 = 0;
  local_3c = 0;
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004059f0(&local_28,L"%TsDockingManager-%d",local_2c,param_2);
  local_1c = (int *)in_ECX[9];
  while (local_1c != (int *)0x0) {
    piVar2 = (int *)FUN_0044f2d0(&local_1c);
    piVar2 = (int *)*piVar2;
    local_18 = piVar2;
    iVar3 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
    if ((iVar3 != 0) ||
       ((iVar3 = FUN_0079d98a(&PTR_s_CPane_0098ac24), in_ECX = local_20, iVar3 != 0 &&
        (iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBar_00a005c4), in_ECX = local_20, iVar3 == 0)))) {
      pcVar1 = *(code **)(*piVar2 + 0x22c);
      guard_check_icall(param_1,0xffffffff,0xffffffff);
      (*pcVar1)();
      in_ECX = local_20;
    }
  }
  local_1c = (int *)in_ECX[0x10];
  if (local_1c != (int *)0x0) {
    local_18 = in_ECX + 0xf;
    do {
      puVar4 = (undefined4 *)FUN_0044f2d0(&local_1c);
      pCVar5 = (CObject *)*puVar4;
      iVar3 = FUN_0079d98a(&PTR_s_CPaneDivider_009a27cc);
      if (iVar3 != 0) {
        AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,pCVar5);
        piVar2 = (int *)FUN_008be33b();
        local_18 = piVar2;
        if ((piVar2 != (int *)0x0) &&
           (iVar3 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c), iVar3 != 0)) {
          pcVar1 = *(code **)(*piVar2 + 0x22c);
          guard_check_icall(param_1,0xffffffff,0xffffffff);
          (*pcVar1)();
        }
      }
      in_ECX = local_20;
    } while (local_1c != (int *)0x0);
  }
  local_1c = (int *)in_ECX[0x33];
  while (local_1c != (int *)0x0) {
    puVar4 = (undefined4 *)FUN_0044f2d0(&local_1c);
    pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,(CObject *)*puVar4);
    pcVar1 = *(code **)(*(int *)pCVar5 + 0x1d8);
    guard_check_icall(param_1,0xffffffff);
    (*pcVar1)();
  }
  local_24 = 0;
  local_34 = (int *)0x0;
  local_30 = 0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  local_1c = (int *)FUN_00859490(0,1);
  pcVar1 = *(code **)(*local_1c + 0x10);
  guard_check_icall(local_28);
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    if (local_34 != (int *)0x0) {
      pcVar1 = *(code **)(*local_34 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    FUN_00406b10();
    FUN_00406b10();
  }
  else {
    pcVar1 = *(code **)(*local_1c + 0x44);
    guard_check_icall(L"DockingPaneAndPaneDividers",&local_24,&local_38);
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      local_8._0_1_ = 3;
      FUN_007b57de(local_24,local_38,0);
      local_8._0_1_ = 4;
      FUN_007a6256(local_70,1,0x1000,0);
      local_8 = CONCAT31(local_8._1_3_,5);
      pcVar1 = *(code **)(*local_20 + 8);
      guard_check_icall(local_b8);
      (*pcVar1)();
      local_18 = (int *)0x1;
      local_20[0x57] = 0;
      FUN_007a6389();
      FUN_007b583b();
      uVar6 = FUN_00847d31(local_28);
      return uVar6;
    }
    if (local_34 != (int *)0x0) {
      pcVar1 = *(code **)(*local_34 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    FUN_00406b10();
    FUN_00406b10();
  }
  return 0;
}




/* vtable slots: CDockingManager[22] */
/* 00847ed7  FUN_00847ed7  366 bytes, 0 callers */

void FUN_00847ed7(int param_1)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  CWnd *pCVar4;
  undefined4 *puVar5;
  CObject *pCVar6;
  int iVar7;
  HWND in_ECX;
  HWND pHVar8;
  CObject *local_14;
  HWND local_10;
  HWND local_c;
  HWND local_8;
  
  if (in_ECX[0x39].unused != 0) {
    local_10 = in_ECX;
    iVar2 = FUN_0079d98a(&PTR_s_CMDIChildWndEx_00995510);
    if (param_1 == 0) {
      local_14 = (CObject *)in_ECX[0x33].unused;
joined_r0x00847f80:
      if (local_14 != (CObject *)0x0) {
        puVar5 = (undefined4 *)FUN_0044f2d0(&local_14);
        pCVar6 = (CObject *)*puVar5;
        if (pCVar6 == (CObject *)0x0) {
          pHVar8 = (HWND)0x0;
        }
        else {
          pHVar8 = *(HWND *)(pCVar6 + 0x20);
        }
        local_c = pHVar8;
        local_8 = pHVar8;
        BVar3 = IsWindow(pHVar8);
        if ((BVar3 != 0) && (BVar3 = IsWindowVisible(pHVar8), BVar3 != 0)) {
          if (iVar2 == 0) {
            pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,pCVar6);
            pcVar1 = *(code **)(*(int *)pCVar6 + 0x1a8);
            guard_check_icall();
            pCVar6 = (CObject *)(*pcVar1)();
            pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCBaseToolBar_0098b6e0,pCVar6);
            pHVar8 = local_8;
            if (pCVar6 == (CObject *)0x0) goto joined_r0x00847f80;
          }
          ShowWindow(pHVar8,0);
          iVar7 = FUN_00847045(&local_c,0);
          if (iVar7 == 0) {
            AddTail(&local_c);
          }
        }
        goto joined_r0x00847f80;
      }
    }
    else {
      puVar5 = (undefined4 *)in_ECX[0x5a].unused;
      while (puVar5 != (undefined4 *)0x0) {
        pHVar8 = (HWND)puVar5[2];
        puVar5 = (undefined4 *)*puVar5;
        local_10 = pHVar8;
        BVar3 = IsWindow(pHVar8);
        if (BVar3 != 0) {
          pCVar4 = CWnd::FromHandle(pHVar8);
          local_14 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,
                                        (CObject *)pCVar4);
          if (local_14 != (CObject *)0x0) {
            pcVar1 = *(code **)(*(int *)local_14 + 0x1a0);
            guard_check_icall();
            iVar2 = (*pcVar1)();
            if (0 < iVar2) {
              ShowWindow(local_10,4);
            }
          }
        }
      }
      RemoveAll();
    }
  }
  return;
}




/* vtable slots: CDockingManager[15] */
/* 0084804d  FUN_0084804d  1057 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0084804d(CObject *param_1)

{
  code *pcVar1;
  bool bVar2;
  SHORT SVar3;
  CObject *pCVar4;
  uint uVar5;
  int iVar6;
  CWnd *pCVar7;
  CWnd *pCVar8;
  clock_t cVar9;
  undefined4 uVar10;
  int *in_ECX;
  int iVar11;
  CObject *local_38;
  CObject *local_34;
  CObject *local_30;
  CObject *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [12];
  LONG local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_30 = param_1;
  SVar3 = GetKeyState(0x11);
  iVar11 = 1;
  if (SVar3 < 0) {
    return 1;
  }
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,param_1);
  iVar6 = in_ECX[0x6e];
  if (((iVar6 == 0) || (*(int *)(iVar6 + 8) == 0)) || (bVar2 = true, *(int *)(iVar6 + 4) == 0)) {
    bVar2 = false;
  }
  if (pCVar4 == (CObject *)0x0) {
    return 1;
  }
  local_18._0_4_ = 0;
  local_18._4_4_ = 0;
  local_18._8_4_ = 0;
  local_c = 0;
  local_2c = pCVar4;
  GetWindowRect(*(HWND *)(local_30 + 0x20),(LPRECT)local_18);
  pcVar1 = *(code **)(*(int *)pCVar4 + 0x170);
  guard_check_icall();
  local_28 = (*pcVar1)();
  local_24 = local_28;
  local_20 = local_28;
  local_1c = local_28;
  FUN_00859dec(local_18,&local_28);
  pCVar4 = local_2c;
  FUN_00797e71(0,local_18._0_4_,local_18._4_4_,0,0,0x15);
  local_18._8_4_ = 0;
  local_c = 0;
  GetCursorPos((LPPOINT)(local_18 + 8));
  pcVar1 = *(code **)(*(int *)pCVar4 + 0x1a8);
  guard_check_icall();
  pCVar4 = (CObject *)(*pcVar1)();
  local_34 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,pCVar4);
  if (local_34 == (CObject *)0x0) {
LAB_0084818f:
    pcVar1 = *(code **)(*in_ECX + 0x14);
    guard_check_icall(local_18._8_4_,local_c,local_2c,1);
    local_30 = (CObject *)(*pcVar1)();
    if (local_30 != (CObject *)0x0) {
      pCVar7 = CWnd::FromHandlePermanent(*(HWND__ **)(local_30 + 200));
      pCVar8 = CWnd::FromHandlePermanent(*(HWND__ **)(local_2c + 200));
      if (pCVar7 == pCVar8) {
        pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMultiPaneFrameWnd_00a00968,local_30);
        if (pCVar4 == (CObject *)0x0) {
          return 1;
        }
        local_30 = pCVar4;
        if ((CObject *)in_ECX[0x49] == (CObject *)0x0) {
          cVar9 = _clock();
          in_ECX[0x4a] = cVar9;
          in_ECX[0x49] = (int)pCVar4;
        }
        else if ((CObject *)in_ECX[0x49] != pCVar4) {
          return 1;
        }
        cVar9 = _clock();
        if (cVar9 - in_ECX[0x4a] <= (int)DAT_00a00914) {
          return 1;
        }
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x248);
        guard_check_icall(local_2c,1);
        uVar10 = (*pcVar1)();
        cVar9 = _clock();
        in_ECX[0x49] = 0;
        in_ECX[0x4a] = cVar9;
        return uVar10;
      }
    }
  }
  else if (!bVar2) {
    pcVar1 = *(code **)(*(int *)local_34 + 0x1c0);
    guard_check_icall();
    uVar5 = (*pcVar1)();
    if (((uVar5 & 0x40) != 0) && (iVar6 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c), iVar6 != 0))
    goto LAB_0084818f;
  }
  in_ECX[0x49] = 0;
  if (local_34 == (CObject *)0x0) {
    return 1;
  }
  pcVar1 = *(code **)(*(int *)local_34 + 0x198);
  guard_check_icall();
  uVar5 = (*pcVar1)();
  if ((uVar5 & 0xf000) == 0) {
    return 1;
  }
  local_38 = (CObject *)0x0;
  pcVar1 = *(code **)(*(int *)local_34 + 0x2b4);
  guard_check_icall(DAT_00a0091c,&local_38);
  uVar5 = (*pcVar1)();
  uVar5 = -(uint)(local_34 != local_38) & uVar5;
  if (((local_38 != (CObject *)0x0) || (uVar5 == 2)) && (!bVar2)) {
    if (local_38 == (CObject *)0x0) {
      local_30 = (CObject *)0x0;
    }
    else {
      local_30 = (CObject *)FUN_0079d98a(&PTR_s_CDockSite_00997564);
    }
    if (local_38 != (CObject *)0x0) {
      iVar11 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
    }
    pCVar4 = DAT_00a00910;
    if ((local_30 != (CObject *)0x0) || (pCVar4 = DAT_00a00914, iVar11 != 0)) {
      local_30 = pCVar4;
      if (((CObject *)in_ECX[0x48] != local_38) || (uVar5 != in_ECX[0x4b])) {
        cVar9 = _clock();
        pCVar4 = local_30;
        in_ECX[0x4b] = uVar5;
        in_ECX[0x4a] = cVar9;
        in_ECX[0x48] = (int)local_38;
        CPaneFrameWnd::SetDockingTimer((CPaneFrameWnd *)local_2c,(uint)local_30);
      }
      cVar9 = _clock();
      if (cVar9 - in_ECX[0x4a] < (int)pCVar4) {
        return 1;
      }
    }
  }
  in_ECX[0x48] = 0;
  cVar9 = _clock();
  pCVar4 = local_2c;
  in_ECX[0x4b] = 0;
  in_ECX[0x4a] = cVar9;
  CPaneFrameWnd::KillDockingTimer((CPaneFrameWnd *)local_2c);
  if (uVar5 == 1) {
    if (local_38 != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)pCVar4 + 400);
      guard_check_icall(0,0,1);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)local_34 + 0x2a0);
      guard_check_icall(local_38);
      iVar11 = (*pcVar1)();
      pCVar4 = local_2c;
      if (iVar11 != 0) {
        return 0;
      }
    }
  }
  else if (uVar5 == 2) {
    if (!bVar2) {
      uVar10 = 1;
      goto LAB_00848444;
    }
  }
  else if ((uVar5 == 3) && (!bVar2)) {
    pcVar1 = *(code **)(*(int *)pCVar4 + 400);
    guard_check_icall(2,local_38,1);
    uVar10 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x38);
    guard_check_icall(0);
    (*pcVar1)();
    return uVar10;
  }
  uVar10 = 0;
LAB_00848444:
  pcVar1 = *(code **)(*(int *)pCVar4 + 400);
  guard_check_icall(uVar10,local_38,1);
  uVar10 = (*pcVar1)();
  return uVar10;
}




/* vtable slots: CDockingManager[3] */
/* 00848548  FUN_00848548  122 bytes, 0 callers */

int FUN_00848548(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                int param_5,undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  *param_4 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x10);
  guard_check_icall(param_1,param_2,param_3,1,0,0,param_6);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    if ((param_5 == 0) || (iVar3 = FUN_0079d98a(param_5), iVar3 != 0)) {
      iVar3 = FUN_0085a399(param_1,param_2,iVar2,param_3,in_ECX,0,param_4,0xf000,0);
      if (iVar3 == 0) {
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}




/* vtable slots: CDockingManager[4] */
/* 008485c2  FUN_008485c2  367 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008485c2(LONG param_1,LONG param_2,int param_3,char param_4,int param_5,int param_6,
                  int *param_7)

{
  code *pcVar1;
  POINT pt;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  BOOL BVar6;
  int *in_ECX;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((in_ECX[0x6e] == 0) || (3 < *(uint *)(in_ECX[0x6e] + 0x110))) {
    uVar2 = 0;
    if (param_7 != (int *)0x0) {
      pcVar1 = *(code **)(*param_7 + 0x228);
      guard_check_icall(1);
      uVar2 = (*pcVar1)();
    }
    pcVar1 = *(code **)(*in_ECX + 0x14);
    guard_check_icall(param_1,param_2,uVar2,0);
    local_1c = (int *)(*pcVar1)();
    if (local_1c != (int *)0x0) {
      pcVar1 = *(code **)(*local_1c + 0x1c4);
      guard_check_icall(param_1,param_2,param_3,param_6);
      piVar3 = (int *)(*pcVar1)();
      if ((piVar3 != (int *)0x0) && (piVar3 != param_7)) {
        if (param_5 == 0) {
          return piVar3;
        }
        iVar4 = FUN_0079d98a(param_5);
        if (iVar4 != 0) {
          return piVar3;
        }
      }
    }
    local_1c = (int *)in_ECX[9];
    do {
      do {
        if (local_1c == (int *)0x0) goto LAB_0084871e;
        piVar3 = (int *)FUN_0049acb0(&local_1c);
      } while ((((param_5 != 0) && (iVar4 = FUN_0079d98a(param_5), iVar4 == 0)) ||
               ((param_6 != 0 && (uVar5 = FUN_00797b3d(), (uVar5 & 0x10000000) == 0)))) ||
              (piVar3 == param_7));
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect((HWND)piVar3[8],&local_18);
      if (param_4 == '\0') {
        InflateRect(&local_18,param_3,param_3);
      }
      pt.y = param_2;
      pt.x = param_1;
      BVar6 = PtInRect(&local_18,pt);
    } while (BVar6 == 0);
  }
  else {
LAB_0084871e:
    piVar3 = (int *)0x0;
  }
  return piVar3;
}




/* vtable slots: CDockingManager[13] */
/* 00848871  FUN_00848871  298 bytes, 0 callers */

void FUN_00848871(void)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *in_ECX;
  int local_8;
  
  if ((((DAT_00a13b30 == 0) && (in_ECX[0x56] == 0)) && (in_ECX[3] == 0)) && (in_ECX[1] != 0)) {
    iVar1 = in_ECX[9];
    in_ECX[0x56] = 1;
    iVar4 = FUN_0084785d();
    local_8 = iVar1;
    if (iVar4 == 0) {
      while (local_8 != 0) {
        puVar5 = (undefined4 *)FUN_0044f2d0(&local_8);
        pcVar2 = *(code **)(*(int *)*puVar5 + 0x20c);
        guard_check_icall();
        (*pcVar2)();
      }
      local_8 = in_ECX[0x33];
      while (local_8 != 0) {
        puVar5 = (undefined4 *)FUN_0044f2d0(&local_8);
        pcVar2 = *(code **)(*(int *)*puVar5 + 0x1d0);
        guard_check_icall();
        (*pcVar2)();
      }
    }
    else {
      while (local_8 != 0) {
        puVar5 = (undefined4 *)FUN_0044f2d0(&local_8);
        piVar3 = (int *)*puVar5;
        uVar6 = FUN_00797b3d();
        if ((uVar6 & 0x10000000) != 0) {
          pcVar2 = *(code **)(*piVar3 + 0x20c);
          guard_check_icall();
          (*pcVar2)();
        }
      }
    }
    pcVar2 = *(code **)(*in_ECX + 0x38);
    guard_check_icall(0);
    (*pcVar2)();
    in_ECX[0x56] = 0;
  }
  return;
}




/* vtable slots: CDockingManager[8] */
/* 00848a6e  RemoveMiniFrame  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CDockingManager::RemoveMiniFrame(class CPaneFrameWnd *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CDockingManager::RemoveMiniFrame(CDockingManager *this,CPaneFrameWnd *param_1)

{
  int iVar1;
  
  iVar1 = FUN_007a198a(param_1,0);
  if (iVar1 != 0) {
    FUN_007a1ad4(iVar1);
  }
  return (uint)(iVar1 != 0);
}




/* vtable slots: CDockingManager[17] */
/* 00848be4  FUN_00848be4  676 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00848be4(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  CObject *pCVar5;
  int iVar6;
  int *in_ECX;
  undefined8 uVar7;
  undefined1 local_b0 [72];
  undefined1 local_68 [16];
  CObList local_58 [36];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [2];
  int *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa0;
  local_8 = 0x848bf3;
  _DAT_00a13b2c = 1;
  local_24 = in_ECX;
  FUN_008592c1(&local_34,L"DockingManagers",param_1);
  local_8 = 0;
  local_30 = 0;
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004059f0(local_2c,L"%TsDockingManager-%d",local_34,param_2);
  local_1c = in_ECX[9];
  while (local_1c != 0) {
    piVar2 = (int *)FUN_0044f2d0(&local_1c);
    piVar2 = (int *)*piVar2;
    local_18 = piVar2;
    iVar3 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
    if ((iVar3 != 0) ||
       ((iVar3 = FUN_0079d98a(&PTR_s_CPane_0098ac24), in_ECX = local_24, iVar3 != 0 &&
        (iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBar_00a005c4), in_ECX = local_24, iVar3 == 0)))) {
      pcVar1 = *(code **)(*piVar2 + 0x230);
      guard_check_icall(param_1,0xffffffff,0xffffffff);
      (*pcVar1)();
      in_ECX = local_24;
    }
  }
  local_1c = in_ECX[0x10];
  if (local_1c != 0) {
    local_18 = in_ECX + 8;
    do {
      puVar4 = (undefined4 *)FUN_0044f2d0(&local_1c);
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,(CObject *)*puVar4);
      if ((pCVar5 != (CObject *)0x0) && (*(int *)(pCVar5 + 300) != 0)) {
        CObList::CObList(local_58,10);
        local_8 = CONCAT31(local_8._1_3_,2);
        local_18 = (int *)FUN_008be33b();
        if (local_18 != (int *)0x0) {
          pcVar1 = *(code **)(*local_18 + 0x230);
          guard_check_icall(param_1,0xffffffff,0xffffffff);
          (*pcVar1)();
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_007a184a();
      }
      in_ECX = local_24;
    } while (local_1c != 0);
  }
  local_1c = in_ECX[0x33];
  while (local_1c != 0) {
    puVar4 = (undefined4 *)FUN_0044f2d0(&local_1c);
    pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,(CObject *)*puVar4);
    pcVar1 = *(code **)(*(int *)pCVar5 + 0x1d4);
    guard_check_icall(param_1,0xffffffff);
    (*pcVar1)();
    in_ECX = local_24;
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 3;
  FUN_007b57a7(0x400);
  local_8._0_1_ = 4;
  FUN_007a6256(local_68,0,0x1000,0);
  local_8._0_1_ = 5;
  pcVar1 = *(code **)(*in_ECX + 8);
  guard_check_icall(local_b0);
  (*pcVar1)();
  FUN_007a67a4();
  local_8._0_1_ = 4;
  FUN_007a6389();
  uVar7 = FUN_007b5a11();
  local_24 = (int *)((ulonglong)uVar7 >> 0x20);
  local_18 = (int *)uVar7;
  iVar3 = FUN_007b592a();
  if (iVar3 != 0) {
    local_20 = (int *)0x0;
    local_1c = 0;
    local_8._0_1_ = 6;
    local_24 = (int *)FUN_00859490(0,0);
    pcVar1 = *(code **)(*local_24 + 0xc);
    guard_check_icall(local_2c[0]);
    iVar6 = (*pcVar1)();
    if (iVar6 != 0) {
      pcVar1 = *(code **)(*local_24 + 0x28);
      guard_check_icall(L"DockingPaneAndPaneDividers",iVar3,local_18);
      local_30 = (*pcVar1)();
    }
    FUN_008f43b0(iVar3);
    if (local_20 != (int *)0x0) {
      pcVar1 = *(code **)(*local_20 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  FUN_007b583b();
  FUN_00848e9d();
  return;
}




/* vtable slots: CDockingManager[2] */
/* 0084919b  FUN_0084919b  2805 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0084919b(CArchive *param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&> *this;
  CArchive *pCVar3;
  __POSITION *p_Var4;
  __POSITION *p_Var5;
  undefined4 *puVar6;
  int iVar7;
  CObject *pCVar8;
  long lVar9;
  int *piVar10;
  CWnd *pCVar11;
  undefined4 uVar12;
  CDockablePane *pCVar13;
  HWND pHVar14;
  int *in_ECX;
  CObject *pCVar15;
  code *pcVar16;
  undefined **local_a4;
  __POSITION *local_a0;
  __POSITION *local_88;
  CObList *local_84;
  CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&> *local_80;
  int *local_7c;
  CArchive *local_78;
  CObject *local_74;
  CObject *local_70;
  __POSITION *local_6c;
  CObject *local_68;
  CObject *local_64;
  CObject *local_60;
  AFX_AUTOHIDE_DOCKSITE_SAVE_INFO local_5c [28];
  undefined **local_40;
  CObject *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_8 = 0x8491aa;
  local_68 = (CObject *)0x0;
  local_64 = (CObject *)0x0;
  local_74 = (CObject *)0x0;
  local_6c = (__POSITION *)0x0;
  local_78 = param_1;
  local_7c = in_ECX;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    local_84 = (CObList *)(in_ECX + 0x16);
    RemoveAll();
    RemoveAll();
    local_80 = (CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&> *)
               (in_ECX + 0x2b);
    RemoveAll();
    RemoveAll();
    local_60 = (CObject *)0xffffffff;
    FUN_00844898(10);
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    CArchive::operator>>(param_1,(long *)&local_6c);
    local_74 = (CObject *)local_6c;
    if (0 < (int)local_6c) {
      do {
        CArchive::operator>>(param_1,(long *)&local_60);
        pcVar16 = *(code **)(*in_ECX + 0x24);
        guard_check_icall(local_60,1);
        pCVar8 = (CObject *)(*pcVar16)();
        local_68 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,pCVar8);
        if (local_68 != (CObject *)0x0) {
          pcVar16 = *(code **)(*(int *)local_68 + 0x3a0);
          guard_check_icall();
          piVar10 = (int *)(*pcVar16)();
          pcVar16 = *(code **)(*piVar10 + 8);
          guard_check_icall(local_78);
          (*pcVar16)();
          CObList::AddTail((CObList *)(in_ECX + 0x1d),local_68);
          param_1 = local_78;
        }
        local_74 = local_74 + -1;
      } while (local_74 != (CObject *)0x0);
    }
    CArchive::operator>>(param_1,(long *)&local_64);
    local_74 = (CObject *)0x0;
    local_70 = (CObject *)0x0;
    if (0 < (int)local_64) {
      do {
        pCVar8 = local_70;
        CArchive::operator>>(param_1,(long *)&local_74);
        if (local_74 == (CObject *)0x0) {
          pCVar8 = (CObject *)FUN_0079d90c();
          pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,pCVar8);
          local_70 = pCVar8;
          CPaneDivider::Init((CPaneDivider *)pCVar8,1,(CWnd *)in_ECX[0x39]);
          pcVar16 = *(code **)(*(int *)pCVar8 + 8);
          guard_check_icall(param_1);
          pCVar8 = local_70;
          (*pcVar16)();
          CObList::AddHead((CObList *)(in_ECX + 0x16),pCVar8);
          p_Var4 = local_a0;
          p_Var5 = local_6c;
          while (local_6c = p_Var4, local_6c != (__POSITION *)0x0) {
            local_88 = *(__POSITION **)local_6c;
            pCVar13 = CPaneDivider::FindTabbedPane((CPaneDivider *)pCVar8,*(uint *)(local_6c + 8));
            in_ECX = local_7c;
            p_Var4 = local_88;
            p_Var5 = local_6c;
            local_68 = (CObject *)pCVar13;
            if (pCVar13 != (CDockablePane *)0x0) {
              pcVar16 = *(code **)(*(int *)pCVar13 + 0x1dc);
              guard_check_icall();
              iVar7 = (*pcVar16)();
              if (iVar7 != 0) {
                pcVar16 = *(code **)(*(int *)pCVar13 + 0x368);
                guard_check_icall(0,0xf000,0,1);
                (*pcVar16)();
              }
              *(undefined4 *)(pCVar13 + 0x354) = *(undefined4 *)(pCVar8 + 0x20);
              pcVar16 = *(code **)(*(int *)pCVar13 + 0x1e0);
              pcVar2 = *(code **)(*(int *)pCVar8 + 0x194);
              guard_check_icall();
              uVar12 = (*pcVar2)();
              guard_check_icall(uVar12);
              pCVar15 = local_68;
              (*pcVar16)();
              CObList::AddHead(local_84,pCVar15);
              CList<CFrameWnd*,CFrameWnd*>::RemoveAt
                        ((CList<CFrameWnd*,CFrameWnd*> *)&local_a4,local_6c);
              in_ECX = local_7c;
              p_Var4 = local_88;
              p_Var5 = local_6c;
            }
          }
        }
        else {
          CArchive::operator>>(param_1,(long *)&local_60);
          if (local_60 == (CObject *)0xffffffff) {
            CArchive::operator>>(param_1,(long *)&local_60);
            if (pCVar8 != (CObject *)0x0) {
              pCVar8 = (CObject *)
                       CPaneDivider::FindTabbedPane((CPaneDivider *)pCVar8,(uint)local_60);
              goto LAB_00849857;
            }
          }
          else {
            pcVar16 = *(code **)(*in_ECX + 0x24);
            guard_check_icall(local_60,1);
            pCVar8 = (CObject *)(*pcVar16)();
            pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar8);
LAB_00849857:
            local_68 = pCVar8;
            if (pCVar8 != (CObject *)0x0) {
              pcVar16 = *(code **)(*(int *)pCVar8 + 0x1dc);
              guard_check_icall();
              iVar7 = (*pcVar16)();
              if (iVar7 != 0) {
                pcVar16 = *(code **)(*(int *)pCVar8 + 0x368);
                guard_check_icall(0,0xf000,0,1);
                (*pcVar16)();
              }
              if (local_70 != (CObject *)0x0) {
                *(int *)(pCVar8 + 0x354) = *(int *)(local_70 + 0x20);
                pcVar16 = *(code **)(*(int *)pCVar8 + 0x1e0);
                pcVar2 = *(code **)(*(int *)local_70 + 0x194);
                guard_check_icall();
                uVar12 = (*pcVar2)();
                guard_check_icall(uVar12);
                (*pcVar16)();
                pCVar8 = local_68;
              }
              CObList::AddHead((CObList *)(in_ECX + 0x16),pCVar8);
              p_Var5 = local_6c;
              goto LAB_00849a06;
            }
          }
          AddTail(&local_60);
          p_Var5 = local_6c;
        }
LAB_00849a06:
        local_6c = p_Var5;
        local_64 = local_64 + -1;
        param_1 = local_78;
      } while (local_64 != (CObject *)0x0);
    }
    local_64 = (CObject *)0x0;
    CArchive::operator>>(param_1,(long *)&local_64);
    pCVar8 = local_64;
    if (0 < (int)local_64) {
      do {
        DAT_00a13b14 = in_ECX[0x39];
        local_64 = (CObject *)0x0;
        FUN_0083ea27(param_1,&local_64);
        CObList::AddTail((CObList *)(in_ECX + 0x24),local_64);
        pCVar8 = pCVar8 + -1;
      } while (pCVar8 != (CObject *)0x0);
    }
    local_64 = (CObject *)0x0;
    CArchive::operator>>(param_1,(long *)&local_64);
    this = local_80;
    pCVar8 = local_64;
    if (0 < (int)local_64) {
      do {
        FUN_00844934();
        local_8._0_1_ = 4;
        FUN_00849018(param_1);
        CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&>::AddTail
                  (this,local_5c);
        local_8._0_1_ = 5;
        local_40 = CList<unsigned_int,unsigned_int&>::vftable;
        RemoveAll();
        local_8._0_1_ = 3;
        pCVar8 = pCVar8 + -1;
        in_ECX = local_7c;
      } while (pCVar8 != (CObject *)0x0);
    }
    local_64 = (CObject *)0x0;
    CArchive::operator>>(param_1,(long *)&local_64);
    local_74 = local_64;
    if (0 < (int)local_64) {
      do {
        local_68 = (CObject *)0xffffffff;
        CArchive::operator>>(param_1,(long *)&local_68);
        if (local_68 != (CObject *)0xffffffff) {
          pcVar16 = *(code **)(*in_ECX + 0x24);
          guard_check_icall(local_68,1);
          pCVar8 = (CObject *)(*pcVar16)();
          local_60 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar8);
          if (local_60 != (CObject *)0x0) {
            pcVar16 = *(code **)(*(int *)local_60 + 0x170);
            guard_check_icall();
            iVar7 = (*pcVar16)();
            if (iVar7 == 0) {
              pcVar16 = *(code **)(*(int *)local_60 + 0x1dc);
              guard_check_icall();
              iVar7 = (*pcVar16)();
              if (iVar7 == 0) {
                pcVar16 = *(code **)(*(int *)local_60 + 0x16c);
                guard_check_icall();
                iVar7 = (*pcVar16)();
                pCVar8 = local_60;
                if (iVar7 == 0) {
                  pcVar16 = *(code **)(*(int *)local_60 + 0x240);
                  guard_check_icall(0);
                }
                else {
                  local_64 = (CObject *)FUN_007ed94f();
                  pHVar14 = (HWND)0x0;
                  if (in_ECX[0x39] != 0) {
                    pHVar14 = *(HWND *)(in_ECX[0x39] + 0x20);
                  }
                  pHVar14 = SetParent(*(HWND *)(pCVar8 + 0x20),pHVar14);
                  CWnd::FromHandle(pHVar14);
                  pcVar16 = *(code **)(*(int *)local_64 + 0x3c0);
                  guard_check_icall(local_60);
                }
                (*pcVar16)();
              }
              else {
                pcVar16 = *(code **)(*(int *)local_60 + 0x368);
                guard_check_icall(0,0xf000,0,1);
                (*pcVar16)();
              }
            }
            else {
              pcVar16 = *(code **)(*(int *)local_60 + 0x228);
              guard_check_icall(0);
              local_80 = (CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&> *)
                         (*pcVar16)();
              if (local_80 !=
                  (CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&> *)0x0) {
                pcVar16 = *(code **)(*(int *)local_80 + 0x17c);
                guard_check_icall(local_60,0,0);
                (*pcVar16)();
              }
              pHVar14 = (HWND)0x0;
              if (in_ECX[0x39] != 0) {
                pHVar14 = *(HWND *)(in_ECX[0x39] + 0x20);
              }
              pHVar14 = SetParent(*(HWND *)(local_60 + 0x20),pHVar14);
              CWnd::FromHandle(pHVar14);
            }
            FUN_00797f20(0);
            FUN_00844fde(local_60);
            *(int *)(local_60 + 0x90) = 1;
          }
        }
        local_74 = local_74 + -1;
      } while (local_74 != (CObject *)0x0);
    }
    local_8 = 6;
    local_a4 = CList<unsigned_int,unsigned_int&>::vftable;
    RemoveAll();
  }
  else {
    local_60 = (CObject *)in_ECX[9];
    while (local_6c = (__POSITION *)local_60, local_60 != (CObject *)0x0) {
      local_70 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,
                                    *(CObject **)(local_60 + 8));
      p_Var5 = local_6c;
      if (local_70 == (CObject *)0x0) {
LAB_0084925d:
        if (p_Var5 == (__POSITION *)0x0) break;
      }
      else {
        pcVar16 = *(code **)(*(int *)local_70 + 0x3a4);
        guard_check_icall();
        iVar7 = (*pcVar16)();
        p_Var5 = local_6c;
        if (iVar7 != 0) goto LAB_0084925d;
        pcVar16 = *(code **)(*(int *)local_70 + 0x1cc);
        guard_check_icall();
        iVar7 = (*pcVar16)();
        p_Var5 = local_6c;
        if (iVar7 == 0) goto LAB_0084925d;
        FUN_0049ad10(&local_60);
        pcVar16 = *(code **)(*(int *)local_70 + 0x240);
        guard_check_icall(1);
        (*pcVar16)();
        if (local_60 == (CObject *)0x0) {
          local_60 = (CObject *)in_ECX[9];
          p_Var5 = (__POSITION *)local_60;
          goto LAB_0084925d;
        }
      }
      FUN_0044f2d0(&local_60);
    }
    local_60 = (CObject *)in_ECX[0x33];
    pCVar8 = local_74;
    pCVar15 = local_68;
    while (local_74 = pCVar8, local_68 = pCVar15, local_60 != (CObject *)0x0) {
      puVar6 = (undefined4 *)FUN_0044f2d0(&local_60);
      local_64 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,
                                    (CObject *)*puVar6);
      pCVar8 = local_74;
      pCVar15 = local_68;
      if (local_64 != (CObject *)0x0) {
        pcVar16 = *(code **)(*(int *)local_64 + 0x1f0);
        guard_check_icall();
        (*pcVar16)();
        pCVar8 = local_74;
        pCVar15 = local_68;
      }
    }
    local_60 = (CObject *)in_ECX[9];
    if (local_60 != (CObject *)0x0) {
      local_64 = (CObject *)(in_ECX + 8);
      do {
        puVar6 = (undefined4 *)FUN_0044f2d0(&local_60);
        p_Var5 = (__POSITION *)*puVar6;
        local_6c = p_Var5;
        iVar7 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
        if (iVar7 == 0) {
LAB_0084931d:
          iVar7 = FUN_0079d98a(&PTR_s_CPaneDivider_009a27cc);
          if (iVar7 != 0) {
            pcVar16 = *(code **)(*(int *)p_Var5 + 0x298);
            guard_check_icall();
            iVar7 = (*pcVar16)();
            if (iVar7 != 0) goto LAB_00849346;
          }
          iVar7 = FUN_0079d98a(&PTR_s_CBaseTabbedPane_00996820);
          if (iVar7 != 0) {
            pCVar8 = pCVar8 + 1;
          }
        }
        else {
          pcVar16 = *(code **)(*(int *)p_Var5 + 0x1cc);
          guard_check_icall();
          iVar7 = (*pcVar16)();
          p_Var5 = local_6c;
          if (iVar7 == 0) goto LAB_0084931d;
LAB_00849346:
          pCVar15 = pCVar15 + 1;
        }
        in_ECX = local_7c;
        param_1 = local_78;
      } while (local_60 != (CObject *)0x0);
    }
    local_68 = pCVar15;
    local_74 = pCVar8;
    CArchive::operator<<(param_1,(long)local_74);
    pCVar3 = local_78;
    local_60 = (CObject *)in_ECX[9];
    if (local_60 != (CObject *)0x0) {
      local_64 = (CObject *)(in_ECX + 8);
      do {
        puVar6 = (undefined4 *)FUN_0044f2d0(&local_60);
        pCVar8 = (CObject *)*puVar6;
        pcVar16 = *(code **)(*(int *)pCVar8 + 0x1cc);
        guard_check_icall();
        iVar7 = (*pcVar16)();
        if (((iVar7 == 0) && (iVar7 = FUN_0079d98a(&PTR_s_CBaseTabbedPane_00996820), iVar7 != 0)) &&
           (pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,pCVar8),
           pCVar8 != (CObject *)0x0)) {
          lVar9 = FUN_00797a2b();
          CArchive::operator<<(pCVar3,lVar9);
          pcVar16 = *(code **)(*(int *)pCVar8 + 0x3a0);
          guard_check_icall();
          piVar10 = (int *)(*pcVar16)();
          pcVar16 = *(code **)(*piVar10 + 8);
          guard_check_icall(pCVar3);
          (*pcVar16)();
        }
        in_ECX = local_7c;
        param_1 = local_78;
      } while (local_60 != (CObject *)0x0);
    }
    CArchive::operator<<(param_1,(long)local_68);
    pCVar3 = local_78;
    local_60 = (CObject *)in_ECX[10];
    if (local_60 != (CObject *)0x0) {
      local_64 = (CObject *)(in_ECX + 8);
      do {
        puVar6 = (undefined4 *)FUN_0049ad10(&local_60);
        pCVar8 = (CObject *)*puVar6;
        iVar7 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c);
        if (iVar7 == 0) {
LAB_008494de:
          iVar7 = FUN_0079d98a(&PTR_s_CPaneDivider_009a27cc);
          if (iVar7 != 0) {
            pcVar16 = *(code **)(*(int *)pCVar8 + 0x298);
            guard_check_icall();
            iVar7 = (*pcVar16)();
            if (iVar7 != 0) {
              CArchive::operator<<(pCVar3,0);
              pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,pCVar8);
              pcVar16 = *(code **)(*(int *)pCVar8 + 8);
              guard_check_icall(pCVar3);
              (*pcVar16)();
            }
          }
        }
        else {
          pcVar16 = *(code **)(*(int *)pCVar8 + 0x1cc);
          guard_check_icall();
          iVar7 = (*pcVar16)();
          if (iVar7 == 0) goto LAB_008494de;
          iVar7 = FUN_00797a2b();
          if (iVar7 == -1) {
            pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,pCVar8);
            pcVar16 = *(code **)(*(int *)pCVar8 + 0x3cc);
            guard_check_icall(0,0);
            iVar7 = (*pcVar16)();
            if (iVar7 != 0) {
              iVar7 = FUN_00797a2b();
              CArchive::operator<<(pCVar3,1);
              lVar9 = -1;
              goto LAB_008494cd;
            }
          }
          else {
            lVar9 = 1;
LAB_008494cd:
            CArchive::operator<<(pCVar3,lVar9);
            CArchive::operator<<(pCVar3,iVar7);
          }
        }
        in_ECX = local_7c;
      } while (local_60 != (CObject *)0x0);
    }
    local_60 = (CObject *)in_ECX[0x33];
    pCVar15 = (CObject *)0x0;
    pCVar8 = local_68;
    if (local_60 != (CObject *)0x0) {
      local_64 = (CObject *)(in_ECX + 0x32);
      pCVar15 = (CObject *)0x0;
      do {
        puVar6 = (undefined4 *)FUN_0044f2d0(&local_60);
        pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,
                                    (CObject *)*puVar6);
        pcVar16 = *(code **)(*(int *)pCVar8 + 0x1a0);
        guard_check_icall();
        iVar7 = (*pcVar16)();
        if (0 < iVar7) {
          pCVar15 = pCVar15 + 1;
        }
        in_ECX = local_7c;
        pCVar8 = pCVar15;
      } while (local_60 != (CObject *)0x0);
    }
    local_68 = pCVar8;
    pCVar3 = local_78;
    CArchive::operator<<(local_78,(long)pCVar15);
    local_60 = (CObject *)in_ECX[0x33];
    if (local_60 != (CObject *)0x0) {
      local_64 = (CObject *)(in_ECX + 0x32);
      do {
        puVar6 = (undefined4 *)FUN_0044f2d0(&local_60);
        local_68 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,
                                      (CObject *)*puVar6);
        pcVar16 = *(code **)(*(int *)local_68 + 0x1a0);
        guard_check_icall();
        iVar7 = (*pcVar16)();
        if (0 < iVar7) {
          FUN_007a619a(local_68);
        }
        in_ECX = local_7c;
      } while (local_60 != (CObject *)0x0);
    }
    CArchive::operator<<(pCVar3,in_ECX[0x12]);
    local_60 = (CObject *)in_ECX[0x10];
    if (local_60 != (CObject *)0x0) {
      local_64 = (CObject *)(in_ECX + 0xf);
      do {
        FUN_00844934();
        local_8 = 0;
        puVar6 = (undefined4 *)FUN_0044f2d0(&local_60);
        pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneDivider_009a27cc,(CObject *)*puVar6
                                   );
        if (pCVar8 == (CObject *)0x0) {
          local_8 = 1;
        }
        else {
          pCVar8 = (CObject *)FUN_008be33b();
          local_18 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,pCVar8);
          if (local_18 != (CObject *)0x0) {
            FUN_00849018(pCVar3);
          }
          local_8 = 2;
        }
        local_40 = CList<unsigned_int,unsigned_int&>::vftable;
        RemoveAll();
        local_8 = 0xffffffff;
        in_ECX = local_7c;
      } while (local_60 != (CObject *)0x0);
    }
    CArchive::operator<<(pCVar3,in_ECX[0x6a]);
    puVar6 = (undefined4 *)in_ECX[0x68];
    while (puVar6 != (undefined4 *)0x0) {
      puVar1 = puVar6 + 2;
      puVar6 = (undefined4 *)*puVar6;
      pCVar11 = CWnd::FromHandlePermanent((HWND__ *)*puVar1);
      pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)pCVar11)
      ;
      if (pCVar8 == (CObject *)0x0) {
        lVar9 = -1;
      }
      else {
        lVar9 = FUN_00797a2b();
      }
      CArchive::operator<<(pCVar3,lVar9);
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CDockingManager[21] */
/* 0084a98b  FUN_0084a98b  139 bytes, 0 callers */

void FUN_0084a98b(int param_1)

{
  CObject *pCVar1;
  HWND hWnd;
  undefined4 *puVar2;
  int iVar3;
  CObject *pCVar4;
  BOOL BVar5;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0xcc);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pCVar1 = (CObject *)*puVar2;
    if ((((pCVar1 != (CObject *)0x0) &&
         (iVar3 = FUN_0079d98a(&PTR_s_CPaneFrameWnd_00a008b0), iVar3 != 0)) &&
        (pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,pCVar1),
        pCVar4 != (CObject *)0x0)) && (*(int *)(pCVar4 + 0xa0) != 0)) {
      hWnd = *(HWND *)(pCVar1 + 0x20);
      BVar5 = IsWindow(hWnd);
      if (BVar5 != 0) {
        ShowWindow(hWnd,-(uint)(param_1 != 0) & 4);
      }
      *(undefined4 *)(pCVar4 + 0xa0) = 0;
    }
  }
  return;
}



