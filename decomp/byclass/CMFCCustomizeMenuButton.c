/* CMFCCustomizeMenuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCCustomizeMenuButton[54], CMFCShowAllButton[54], CMFCToolBarMenuButton[54], CMFCToolBarSystemMenuButton[54], CTasksPaneHistoryButton[54] */
/* 0081b5d4  CreatePopupMenu  48 bytes, 2 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual class CMFCPopupMenu * __thiscall CMFCToolBarMenuButton::CreatePopupMenu(void)
   
   Library: Visual Studio 2015 Release */

CMFCPopupMenu * __thiscall CMFCToolBarMenuButton::CreatePopupMenu(CMFCToolBarMenuButton *this)

{
  int iVar1;
  CMFCPopupMenu *pCVar2;
  
  iVar1 = FUN_0078e624(0x1178);
  pCVar2 = (CMFCPopupMenu *)0x0;
  if (iVar1 != 0) {
    pCVar2 = (CMFCPopupMenu *)FUN_0081b772();
  }
  return pCVar2;
}




/* vtable slots: CMFCCustomizeMenuButton[10], CMFCShowAllButton[10], CMFCToolBarMenuButton[10], CMFCToolBarSystemMenuButton[10] */
/* 0087713d  FUN_0087713d  194 bytes, 1 callers */

void FUN_0087713d(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  
  FUN_00881617(param_1);
  if (param_1 == 0) {
    return;
  }
  iVar2 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00);
  iVar3 = 0;
  iVar4 = 1;
  if (iVar2 == 0) {
    if ((in_ECX[8] == 0) || (iVar2 = 0, in_ECX[0x1f] != 0)) {
      iVar2 = iVar4;
    }
  }
  else {
    if (((in_ECX[8] == 0) || (in_ECX[0x1f] == 0)) && (*(int *)(param_1 + 0xd78) == 0)) {
      iVar4 = 0;
    }
    in_ECX[2] = 1;
    in_ECX[3] = 0;
    iVar2 = iVar4;
  }
  in_ECX[0x24] = iVar2;
  iVar2 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
  if (iVar2 == 0) {
    in_ECX[0x25] = 0;
    return;
  }
  in_ECX[0x25] = 1;
  in_ECX[2] = 1;
  in_ECX[3] = 0;
  if ((in_ECX[8] != 0) && (in_ECX[0x1f] == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0xf0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) goto LAB_008771ea;
  }
  iVar3 = 1;
LAB_008771ea:
  in_ECX[0x24] = iVar3;
  return;
}




/* vtable slots: CMFCCustomizeMenuButton[1] */
/* 0089e62c  FUN_0089e62c  57 bytes, 0 callers */

void FUN_0089e62c(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCCustomizeMenuButton::vftable;
  FUN_00874eb0();
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




/* vtable slots: CMFCCustomizeMenuButton[5] */
/* 0089e665  CopyFrom  106 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCCustomizeMenuButton::CopyFrom(class CMFCToolBarButton
   const &)
   
   Library: Visual Studio 2012 Release */

void __thiscall
CMFCCustomizeMenuButton::CopyFrom(CMFCCustomizeMenuButton *this,CMFCToolBarButton *param_1)

{
  FUN_00880ee9(param_1);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
  *(undefined4 *)(this + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
  *(undefined4 *)(this + 0xfc) = *(undefined4 *)(param_1 + 0xfc);
  *(undefined4 *)(this + 0x100) = *(undefined4 *)(param_1 + 0x100);
  return;
}




/* vtable slots: CMFCCustomizeMenuButton[63] */
/* 0089e6ff  FUN_0089e6ff  276 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0089e6ff(undefined4 param_1,undefined4 *param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0xec) != 0) {
    local_18 = *param_2;
    local_14 = param_2[1] + 1;
    local_10 = param_2[2] + -1;
    local_c = param_2[3] + -1;
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0xb0);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      uVar2 = *(uint *)(in_ECX + 0x24);
      *(uint *)(in_ECX + 0x24) = uVar2 | 0x10000;
      FUN_0088114d(param_1,&local_18,param_3,1);
      if (param_3 != 0) {
        iVar4 = FUN_007c2574();
        if (*(int *)(iVar4 + 100) != 0) {
          *(uint *)(in_ECX + 0x24) = *(uint *)(in_ECX + 0x24) | 0x800000;
        }
      }
      piVar3 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar3 + 0x88);
      guard_check_icall(param_1,in_ECX,local_18,local_14,local_10,local_c,1);
      (*pcVar1)();
      *(uint *)(in_ECX + 0x24) = uVar2;
    }
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0xa4);
    guard_check_icall(param_1,in_ECX,local_18,local_14,local_10,local_c,param_3,0);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCCustomizeMenuButton[0] */
/* 0089e813  FUN_0089e813  6 bytes, 0 callers */

undefined ** FUN_0089e813(void)

{
  return &PTR_s_CMFCCustomizeMenuButton_0099e5c8;
}




/* vtable slots: CMFCCustomizeMenuButton[7] */
/* 0089e819  FUN_0089e819  703 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0089e819(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  CSimpleStringT<wchar_t,0> *this;
  code *pcVar1;
  int iVar2;
  int iVar3;
  CSimpleStringT<wchar_t,0> *pCVar4;
  CObject *pCVar5;
  undefined4 uVar6;
  int *piVar7;
  int in_ECX;
  UINT in_stack_ffffff74;
  LPSTR in_stack_ffffff78;
  int in_stack_ffffff7c;
  int local_7c [3];
  int local_70;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined4 *local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  CObject *local_54;
  tagTEXTMETRICW local_50;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x89e825;
  local_64 = param_1;
  local_5c = param_2;
  local_68 = param_3;
  local_60 = param_4;
  if (*(int *)(in_ECX + 0xf0) != 0) {
    *param_1 = 0;
    param_1[1] = 4;
    goto LAB_0089ead0;
  }
  if (*(int *)(in_ECX + 0x100) != 0) {
    FUN_00876cfc(param_1,param_2,param_3,param_4);
    goto LAB_0089ead0;
  }
  this = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x2c);
  local_70 = in_ECX;
  if (*(int *)(*(int *)this + -0xc) == 0) {
    CStringT<>();
    local_8 = 0;
    iVar2 = FID_conflict_LoadStringA
                      (*(HINSTANCE *)(in_ECX + 0x20),in_stack_ffffff74,in_stack_ffffff78,
                       in_stack_ffffff7c);
    iVar3 = local_58;
    if ((iVar2 != 0) && (iVar2 = FUN_0044e690(10,0), iVar2 != -1)) {
      FUN_00450000(&local_54,iVar2 + 1,*(int *)(iVar3 + -0xc) - (iVar2 + 1));
      local_8 = CONCAT31(local_8._1_3_,1);
      ATL::CSimpleStringT<wchar_t,0>::operator=(this,(CSimpleStringT<wchar_t,0> *)&local_54);
      FUN_00406b10();
    }
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  else {
    iVar3 = FUN_0044e690(9,0);
    if (iVar3 != -1) {
      pCVar4 = (CSimpleStringT<wchar_t,0> *)Left(&local_54,iVar3);
      local_8 = 2;
      ATL::CSimpleStringT<wchar_t,0>::operator=(this,pCVar4);
      local_8 = 0xffffffff;
      FUN_00406b10();
    }
  }
  if (((DAT_00a13a44 != 0) && (*(int *)(in_ECX + 0x94) != 0)) &&
     ((*(uint *)(in_ECX + 0x20) < 0xf000 || (0xf1ef < *(uint *)(in_ECX + 0x20))))) {
    iVar3 = FUN_0044e690(9,0);
    if (-1 < iVar3) {
      pCVar4 = (CSimpleStringT<wchar_t,0> *)Left(&local_54,iVar3);
      local_8 = 3;
      ATL::CSimpleStringT<wchar_t,0>::operator=(this,pCVar4);
      FUN_00406b10();
    }
    CStringT<>();
    local_8 = 4;
    if (*(int *)(in_ECX + 0x6c) == 0) {
      pCVar5 = (CObject *)FUN_00404c80();
      local_54 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,pCVar5);
LAB_0089e9cd:
      if (local_54 != (CObject *)0x0) goto LAB_0089e9d1;
    }
    else {
      local_54 = DAT_00a13a1c;
      if (DAT_00a13a1c == (CObject *)0x0) {
        local_54 = (CObject *)FUN_00792b4c();
        goto LAB_0089e9cd;
      }
LAB_0089e9d1:
      pCVar5 = local_54;
      iVar3 = FUN_0082b064(*(undefined4 *)(in_ECX + 0x20),&local_58,local_54,1);
      if (iVar3 == 0) {
        pcVar1 = *(code **)(*(int *)pCVar5 + 0x170);
        guard_check_icall();
        uVar6 = (*pcVar1)();
        iVar3 = FUN_0082b064(*(undefined4 *)(in_ECX + 0x20),&local_58,uVar6,0);
        if (iVar3 == 0) goto LAB_0089ea23;
      }
      ATL::CSimpleStringT<wchar_t,0>::AppendChar(this,L'\t');
      FUN_00404cf0(local_58,*(undefined4 *)(local_58 + -0xc));
    }
LAB_0089ea23:
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  iVar3 = *(int *)(*(int *)this + -0xc);
  GetTextMetricsW(*(HDC *)(local_5c + 8),&local_50);
  FUN_007fe19c(local_7c);
  piVar7 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar7 + 0x2dc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  local_54 = (CObject *)(iVar2 * 3 + local_50.tmAveCharWidth * iVar3 + local_7c[0] * 2 + 0x32);
  iVar3 = FUN_00876cfc(local_6c,local_5c,local_68,local_60);
  iVar3 = *(int *)(iVar3 + 4) + 2;
  if (*(int *)(local_70 + 0x94) == 0) {
    piVar7 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar7 + 0x2dc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    iVar3 = iVar3 + iVar2;
  }
  *local_64 = local_54;
  local_64[1] = iVar3;
LAB_0089ead0:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCCustomizeMenuButton[58] */
/* 0089ead8  FUN_0089ead8  882 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0089ead8(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  __POSITION *p_Var5;
  uint uVar6;
  CObject *pCVar7;
  uint uVar8;
  HWND pHVar9;
  CWnd *pCVar10;
  CMFCCustomizeMenuButton *in_ECX;
  int iVar11;
  CObject *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0xf0) == 0) && (*(int *)(in_ECX + 0xfc) != 0)) {
    iVar3 = *(int *)(in_ECX + 0x6c);
    if (iVar3 == 0) {
LAB_0089ee45:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    iVar2 = FUN_007fc033(in_ECX);
    if ((iVar2 != -1) && (*(int *)(iVar3 + 0xbf0) != iVar2)) {
      *(int *)(iVar3 + 0xbf0) = iVar2;
      InvalidateRect(*(HWND *)(iVar3 + 0x20),(RECT *)(in_ECX + 0x54),1);
    }
    if (*(int *)(in_ECX + 0x100) == 0) {
      iVar2 = *(int *)(in_ECX + 0xe8);
      if (iVar2 != 0x4278) {
        if (*(int *)(in_ECX + 0xf4) == 0) {
          p_Var5 = CObList::FindIndex((CObList *)(DAT_00a13c80 + 0x31d),iVar2);
          if (p_Var5 == (__POSITION *)0x0) goto LAB_0089ee45;
          iVar2 = *(int *)(p_Var5 + 8);
          if (iVar2 != 0) {
            pcVar1 = *(code **)(*DAT_00a13c80 + 0x344);
            guard_check_icall(iVar2,*(undefined4 *)(in_ECX + 0xe8));
            uVar6 = (*pcVar1)();
            if (uVar6 == 0xffffffff) {
              pcVar1 = *(code **)(*DAT_00a13c80 + 0x344);
              guard_check_icall(iVar2,0xffffffff);
              uVar6 = (*pcVar1)();
            }
            else {
              iVar2 = FUN_007fdf7c();
              if (0 < iVar2) {
                iVar11 = 0;
                do {
                  pCVar7 = (CObject *)FUN_007fde79(iVar11);
                  pCVar7 = AfxDynamicDownCast((CRuntimeClass *)
                                              &PTR_s_CMFCCustomizeMenuButton_0099e5c8,pCVar7);
                  if ((((pCVar7 != (CObject *)0x0) &&
                       (uVar8 = *(uint *)(pCVar7 + 0xe8), uVar6 <= uVar8)) && (uVar8 != 0x4278)) &&
                     (*(int *)(pCVar7 + 0xf4) != 0)) {
                    *(uint *)(pCVar7 + 0xe8) = uVar8 + 1;
                  }
                  iVar11 = iVar11 + 1;
                } while (iVar11 < iVar2);
              }
            }
            *(uint *)(in_ECX + 0xe8) = uVar6;
            if ((*(int *)(in_ECX + 0xf8) != 0) &&
               ((uVar8 = FUN_007fdf7c(), uVar8 <= uVar6 ||
                (iVar2 = FUN_007fde79(uVar6 + 1), (*(byte *)(iVar2 + 0x24) & 1) == 0)))) {
              pcVar1 = *(code **)(*DAT_00a13c80 + 0x348);
              guard_check_icall(0xffffffff);
              (*pcVar1)();
            }
            pcVar1 = *(code **)(*DAT_00a13c80 + 0x20c);
            guard_check_icall();
            (*pcVar1)();
            pcVar1 = *(code **)(*DAT_00a13c80 + 0x2d4);
            guard_check_icall(1);
            (*pcVar1)();
            CMFCCustomizeMenuButton::UpdateCustomizeButton(in_ECX);
            *(undefined4 *)(in_ECX + 0xf4) = 1;
            *(undefined4 *)(in_ECX + 0xec) = 1;
            InvalidateRect(*(HWND *)(iVar3 + 0x20),(RECT *)0x0,1);
            return 1;
          }
        }
        else {
          iVar2 = FUN_007fde79(iVar2);
          uVar6 = (uint)(*(int *)(iVar2 + 0x50) == 0);
          *(uint *)(iVar2 + 0x50) = uVar6;
          iVar2 = *(int *)(in_ECX + 0xe8);
          *(uint *)(in_ECX + 0xec) = uVar6;
          iVar11 = FUN_007fdf7c();
          if ((iVar2 + 1 < iVar11) &&
             (iVar2 = FUN_007fde79(iVar2 + 1), (*(byte *)(iVar2 + 0x24) & 1) != 0)) {
            *(uint *)(iVar2 + 0x50) = uVar6;
          }
          local_1c = (CObject *)0x0;
          pHVar9 = GetParent(*(HWND *)(iVar3 + 0x20));
          pCVar10 = CWnd::FromHandle(pHVar9);
          pCVar7 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,
                                      (CObject *)pCVar10);
          if (pCVar7 != (CObject *)0x0) {
            do {
              local_1c = pCVar7;
              pCVar7 = (CObject *)FUN_0081d529();
            } while (pCVar7 != (CObject *)0x0);
            if (local_1c != (CObject *)0x0) {
              FUN_00797f20(0);
            }
          }
          pcVar1 = *(code **)(*DAT_00a13c80 + 0x20c);
          guard_check_icall();
          (*pcVar1)();
          pcVar1 = *(code **)(*DAT_00a13c80 + 0x2d4);
          guard_check_icall(1);
          (*pcVar1)();
          CMFCCustomizeMenuButton::UpdateCustomizeButton(in_ECX);
          InvalidateRect(*(HWND *)(iVar3 + 0x20),(RECT *)0x0,1);
          if (local_1c != (CObject *)0x0) {
            FUN_00797f20(4);
            local_18.left = 0;
            local_18.top = 0;
            local_18.right = 0;
            local_18.bottom = 0;
            GetWindowRect(*(HWND *)(local_1c + 0x20),&local_18);
            FUN_0082174f(&local_18);
          }
        }
        goto LAB_0089ee33;
      }
      PostMessageW((HWND)DAT_00a13c80[8],DAT_00a127e4,0,0);
    }
    else {
      iVar3 = FUN_007fe83b();
      if (iVar3 == 0) {
        FUN_00805472();
      }
      else {
        FUN_00805946();
      }
    }
    uVar4 = 0;
  }
  else {
LAB_0089ee33:
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CMFCCustomizeMenuButton[6] */
/* 0089ee4b  FUN_0089ee4b  777 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0089ee4b(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  int local_78 [2];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  undefined1 local_68 [4];
  int *local_64;
  int local_60;
  int iStack_5c;
  int local_58;
  int iStack_54;
  undefined4 local_50;
  int local_4c;
  int iStack_48;
  int iStack_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int *local_30;
  int *local_2c;
  int local_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int local_18;
  int iStack_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_50 = param_3;
  local_38 = param_1;
  local_2c = in_ECX;
  if (in_ECX[0x3c] == 0) {
    if (in_ECX[0x40] == 0) {
      local_4c = *param_2;
      iStack_48 = param_2[1];
      iStack_44 = param_2[2];
      local_40 = param_2[3] + -1;
      if (in_ECX[0x3f] == 0) {
        uVar4 = 0x40000;
        pcVar1 = *(code **)(*in_ECX + 0x8c);
        guard_check_icall(0x40000);
        (*pcVar1)();
        param_6 = 0;
        local_30 = (int *)0x1;
        local_34 = 0;
      }
      else {
        local_34 = param_6;
        if ((in_ECX[0x3b] == 0) || (param_6 == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x10000;
        }
        pcVar1 = *(code **)(*in_ECX + 0x8c);
        guard_check_icall(uVar4);
        (*pcVar1)();
        local_30 = (int *)param_8;
      }
      local_3c = in_ECX[0x3a];
      if (local_3c == 0x4278) {
        in_ECX[3] = 0;
        in_ECX[0xd] = -1;
      }
      if ((param_6 != 0) && (in_ECX[0x3f] != 0)) {
        local_60 = local_4c + 2;
        iStack_5c = iStack_48;
        iStack_54 = local_40;
        local_58 = iStack_44 + -1;
        piVar2 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar2 + 0x98);
        guard_check_icall(uVar4);
        iVar3 = (*pcVar1)();
        if ((iVar3 == 0) && (local_3c != 0x4278)) {
          piVar2 = (int *)FUN_007c2574();
          pcVar1 = *(code **)(*piVar2 + 0x2dc);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          piVar2 = (int *)FUN_007fe1cf(local_68);
          local_60 = local_60 + *piVar2 * 2 + iVar3 * 5;
        }
        local_64 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*local_64 + 0x90);
        guard_check_icall(local_38,local_2c,local_60,iStack_5c,local_58,iStack_54,local_6c);
        (*pcVar1)();
      }
      FUN_007fe1cf(local_78);
      local_18 = local_4c;
      iStack_14 = iStack_48;
      local_10 = iStack_44;
      local_c = local_40;
      piVar2 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar2 + 0x2dc);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      local_18 = iVar3 + local_18 + 1;
      piVar2 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar2 + 0x2dc);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      local_10 = iVar3 + local_78[0] + local_18 + 2;
      local_c = local_c + -1;
      pcVar1 = *(code **)(*local_2c + 0xfc);
      guard_check_icall(local_38,&local_18,local_34);
      (*pcVar1)();
      if (((local_34 != 0) && ((local_2c[9] & 0x40000U) == 0)) && (local_3c != 0x4278)) {
        pcVar1 = *(code **)(*local_2c + 0x8c);
        guard_check_icall(0);
        (*pcVar1)();
      }
      iStack_24 = iStack_48;
      iStack_20 = iStack_44;
      iStack_1c = local_40;
      local_28 = local_10;
      FUN_008755b2(local_38,&local_28,local_50,param_5,local_34,local_30,1);
    }
    else {
      FUN_00877450(param_1,param_2,0,param_4,param_5,param_6,param_7,param_8);
    }
  }
  else {
    local_4c = *param_2;
    iStack_48 = param_2[1];
    iStack_44 = param_2[2];
    local_40 = param_2[3];
    piVar2 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar2 + 0x2dc);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    piVar2 = (int *)FUN_007fe1cf(local_70);
    local_4c = iVar3 + *piVar2 * 2;
    local_3c = local_2c[0x1b];
    if (local_3c == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    local_30 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*local_30 + 0x48);
    guard_check_icall(local_38,local_3c,local_4c,iStack_48,iStack_44,local_40,0);
    (*pcVar1)();
  }
  return;
}



