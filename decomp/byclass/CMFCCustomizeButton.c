/* CMFCCustomizeButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCCustomizeButton[27], CMFCCustomizeMenuButton[27], CMFCShowAllButton[27], CMFCToolBarMenuButton[27], CMFCToolBarSystemMenuButton[27], COutlookCustomizeButton[27], CTasksPaneHistoryButton[27], CTasksPaneMenuButton[27] */
/* 0087792d  FUN_0087792d  119 bytes, 1 callers */

int FUN_0087792d(undefined4 param_1,int *param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  FUN_008822bb(param_1,param_2,param_3);
  if ((in_ECX[8] != 0) && (in_ECX[0x1f] == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0xf0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) goto LAB_00877996;
  }
  piVar3 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar3 + 0x13c);
  guard_check_icall(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_3);
  (*pcVar1)();
LAB_00877996:
  return param_2[2] - *param_2;
}




/* vtable slots: CMFCCustomizeButton[2], CMFCCustomizeMenuButton[2], CMFCShowAllButton[2], CMFCToolBarMenuButton[2], COutlookCustomizeButton[2], CTasksPaneHistoryButton[2], CTasksPaneMenuButton[2] */
/* 00877d12  FUN_00877d12  198 bytes, 1 callers */

void FUN_00877d12(CArchive *param_1)

{
  code *pcVar1;
  int *in_ECX;
  int *local_8;
  
  local_8 = in_ECX;
  FUN_008829ae(param_1);
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,in_ECX[0x2f]);
    CArchive::operator<<(param_1,in_ECX[0x2c]);
    CArchive::operator<<(param_1,in_ECX[0x30]);
  }
  else {
    while (in_ECX[0x1f] != 0) {
      local_8 = (int *)FUN_007a1b17();
      if (local_8 != (int *)0x0) {
        pcVar1 = *(code **)(*local_8 + 4);
        guard_check_icall(1);
        (*pcVar1)();
      }
    }
    CArchive::operator>>(param_1,(long *)&local_8);
    pcVar1 = *(code **)(*in_ECX + 0xf8);
    guard_check_icall(local_8);
    (*pcVar1)();
    CArchive::operator>>(param_1,in_ECX + 0x2c);
    CArchive::operator>>(param_1,in_ECX + 0x30);
  }
  pcVar1 = *(code **)(in_ECX[0x1c] + 8);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCCustomizeButton[1], COutlookCustomizeButton[1] */
/* 008860b0  FUN_008860b0  51 bytes, 0 callers */

void FUN_008860b0(byte param_1)

{
  CMFCCustomizeButton *in_ECX;
  
  CMFCCustomizeButton::~CMFCCustomizeButton(in_ECX);
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




/* vtable slots: CMFCCustomizeButton[5], COutlookCustomizeButton[5] */
/* 0088611f  CopyFrom  88 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCCustomizeButton::CopyFrom(class CMFCToolBarButton const &)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCCustomizeButton::CopyFrom(CMFCCustomizeButton *this,CMFCToolBarButton *param_1)

{
  FUN_0087503b(param_1);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 0xf4),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0xf4));
  *(undefined4 *)(this + 0xfc) = *(undefined4 *)(param_1 + 0xfc);
  *(undefined4 *)(this + 0x104) = *(undefined4 *)(param_1 + 0x104);
  *(undefined4 *)(this + 0x10c) = *(undefined4 *)(param_1 + 0x10c);
  return;
}




/* vtable slots: CMFCCustomizeButton[54] */
/* 00886177  FUN_00886177  2287 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CMFCPopupMenu * FUN_00886177(void)

{
  code *pcVar1;
  bool bVar2;
  uint uID;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  CSimpleStringT<wchar_t,0> *pCVar9;
  CObject *pCVar10;
  CWnd *pCVar11;
  CMFCPopupMenu *this;
  CMFCToolBarMenuButton *in_ECX;
  int unaff_ESI;
  LPSTR unaff_EDI;
  HINSTANCE hInstance;
  undefined1 local_156c [4];
  int local_1568;
  CMFCToolBarMenuButton *local_1564;
  int local_1560;
  CMFCPopupMenu *local_155c;
  CMFCToolBarMenuButton *local_1558;
  int *local_1554;
  int local_1550;
  int local_154c [89];
  int local_13e8;
  undefined1 local_3d0 [180];
  undefined4 local_31c;
  undefined1 local_2e8 [232];
  undefined1 local_200 [256];
  undefined4 local_100;
  undefined1 local_fc [232];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094f05c;
  local_10 = ExceptionList;
  uID = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((DAT_00a127b0 == 0) && (DAT_00a127ac == 0)) &&
     (local_1558 = in_ECX, local_14 = uID,
     local_155c = CMFCToolBarMenuButton::CreatePopupMenu(in_ECX), local_155c != (CMFCPopupMenu *)0x0
     )) {
    iVar7 = *(int *)(in_ECX + 0xf8);
    if (*(int *)(iVar7 + 0xb78) != 0) {
      pcVar1 = *(code **)(*(int *)local_155c + 0x1c8);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      *(int *)(iVar3 + 0xd44) = iVar7;
    }
    this = local_155c;
    if ((*(int *)(in_ECX + 0x10c) == 0) || (uVar4 = FUN_00797acc(), (uVar4 & 0x400000) != 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
    *(undefined4 *)(this + 0xf44) = uVar5;
    local_1550 = 1;
    local_1568 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xb78);
    local_1554 = *(int **)(in_ECX + 0x114);
    if (local_1554 != (int *)0x0) {
      local_1564 = in_ECX + 0x110;
      bVar2 = true;
      do {
        piVar6 = (int *)FUN_0044f2d0(&local_1554);
        iVar7 = *piVar6;
        if ((*(byte *)(iVar7 + 0x24) & 1) == 0) {
LAB_008862a9:
          bVar2 = false;
          iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBarMenuButton_00a00a14);
          if (iVar3 == 0) {
            if (*(int *)(iVar7 + 0x20) == 0) {
              iVar7 = FUN_0081dee6(0xffffffff);
            }
            else {
              if (local_1568 == 0) {
                if (*(int *)(iVar7 + 4) == 0) {
                  uVar5 = *(undefined4 *)(iVar7 + 0x34);
                }
                else {
                  uVar5 = *(undefined4 *)(iVar7 + 0x38);
                }
              }
              else {
                uVar5 = 0xffffffff;
              }
              uVar5 = FUN_00874dc7(*(undefined4 *)(iVar7 + 0x20),0,uVar5,
                                   *(undefined4 *)(iVar7 + 0x2c),*(undefined4 *)(iVar7 + 4));
              local_8 = 0;
              local_1550 = FUN_0081dea9(uVar5,0xffffffff);
              local_8 = 0xffffffff;
              FUN_00874eb0();
              iVar7 = local_1550;
            }
          }
          else {
            iVar7 = FUN_0081dea9(iVar7,0xffffffff);
          }
          if ((-1 < iVar7) && (local_1550 = FUN_0081d46f(iVar7), local_1550 != 0)) {
            if (((*(int *)(*(int *)(local_1550 + 0x2c) + -0xc) == 0) ||
                (iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBarComboBoxButton_00a00810), iVar7 = local_1550
                , iVar3 != 0)) && (iVar7 = local_1550, *(int *)(local_1550 + 0x20) != 0)) {
              CStringT<>();
              local_8 = 1;
              iVar8 = FID_conflict_LoadStringA(*(HINSTANCE *)(iVar7 + 0x20),uID,unaff_EDI,unaff_ESI)
              ;
              iVar3 = local_154c[0];
              if ((iVar8 != 0) && (iVar8 = FUN_0044e690(10,0), iVar8 != -1)) {
                FUN_00450000(&local_1560,iVar8 + 1,*(int *)(iVar3 + -0xc) - (iVar8 + 1));
                local_8._0_1_ = 2;
                ATL::CSimpleStringT<wchar_t,0>::operator=
                          ((CSimpleStringT<wchar_t,0> *)(iVar7 + 0x2c),
                           (CSimpleStringT<wchar_t,0> *)&local_1560);
                local_8._0_1_ = 1;
                FUN_00406b10();
                iVar3 = FUN_0044e690(10,0);
                if (iVar3 != -1) {
                  pCVar9 = (CSimpleStringT<wchar_t,0> *)Left(local_156c,iVar3);
                  local_8 = CONCAT31(local_8._1_3_,3);
                  ATL::CSimpleStringT<wchar_t,0>::operator=
                            ((CSimpleStringT<wchar_t,0> *)(iVar7 + 0x2c),pCVar9);
                  FUN_00406b10();
                }
              }
              local_8 = 0xffffffff;
              FUN_00406b10();
              this = local_155c;
            }
            *(undefined4 *)(iVar7 + 8) = 1;
          }
        }
        else if (!bVar2) {
          in_ECX = local_1558;
          if (local_1554 != (int *)0x0) goto LAB_008862a9;
          break;
        }
        in_ECX = local_1558;
      } while (local_1554 != (int *)0x0);
    }
    if (0 < *(int *)(in_ECX + 0xe8)) {
      if (*(int *)(in_ECX + 0x11c) != 0) {
        FUN_0081dee6(0xffffffff);
      }
      if (*(int *)(*(int *)(in_ECX + 0xf8) + 0xbc8) == 0) {
        FUN_00874dc7(*(undefined4 *)(in_ECX + 0xe8),0,0xffffffff,*(undefined4 *)(in_ECX + 0xf4),0);
        local_8 = 0x14;
        FUN_0081dea9(local_fc,0xffffffff);
      }
      else {
        local_1564 = (CMFCToolBarMenuButton *)FUN_0078e624(0x1178);
        local_8 = 4;
        if (local_1564 == (CMFCToolBarMenuButton *)0x0) {
          local_1554 = (int *)0x0;
        }
        else {
          local_1554 = (int *)FUN_0081b772();
        }
        local_8 = 0xffffffff;
        iVar7 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xbc);
        if (iVar7 == 0) {
          CStringT<>();
          local_8._0_1_ = 10;
          local_8._1_3_ = 0;
          FUN_00792c64(local_154c);
          ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimLeft
                    ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                     local_154c);
          ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimRight
                    ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                     local_154c);
          if ((*(int *)(local_154c[0] + -0xc) == 0) &&
             (iVar7 = FID_conflict_LoadStringA((HINSTANCE)0x3ee8,uID,unaff_EDI,unaff_ESI),
             iVar7 == 0)) goto LAB_00886a61;
          CStringT<>();
          local_8._0_1_ = 0xb;
          uVar5 = FUN_00797a2b();
          FUN_004059f0(&local_1550,&DAT_0095b714,uVar5);
          FUN_0081b772();
          local_8._0_1_ = 0xc;
          uVar5 = FUN_00874dc7(1,0,0xffffffff,local_1550,0);
          local_8._0_1_ = 0xd;
          FUN_0081dea9(uVar5,0xffffffff);
          local_8._0_1_ = 0xc;
          FUN_00874eb0();
          pcVar1 = *(code **)(local_13e8 + 0x43c);
          guard_check_icall();
          uVar5 = (*pcVar1)();
          FUN_00874dc7(0xffffffff,uVar5,0xffffffff,local_154c[0],0);
          piVar6 = local_1554;
          local_8 = CONCAT31(local_8._1_3_,0xe);
          FUN_0081dea9(local_fc,0xffffffff);
          FUN_00874eb0();
          FUN_0081b926();
          FUN_00406b10();
          local_8 = 0xffffffff;
          FUN_00406b10();
          in_ECX = local_1558;
        }
        else {
          local_1564 = (CMFCToolBarMenuButton *)(iVar7 + 0x24);
          local_1560 = *(int *)(iVar7 + 0x28);
          piVar6 = local_1554;
          while (local_1560 != 0) {
            pCVar10 = (CObject *)FUN_0049acb0(&local_1560);
            pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,pCVar10);
            in_ECX = local_1558;
            piVar6 = local_1554;
            if (pCVar10 != (CObject *)0x0) {
              pcVar1 = *(code **)(*(int *)pCVar10 + 0x17c);
              guard_check_icall();
              iVar7 = (*pcVar1)();
              in_ECX = local_1558;
              piVar6 = local_1554;
              if ((iVar7 != 0) && (*(int *)(pCVar10 + 0xd14) != 0)) {
                CStringT<>();
                local_8._0_1_ = 5;
                local_8._1_3_ = 0;
                FUN_00792c64(local_154c);
                ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimLeft
                          ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                           local_154c);
                ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimRight
                          ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                           local_154c);
                if ((*(int *)(local_154c[0] + -0xc) == 0) &&
                   (iVar7 = FID_conflict_LoadStringA((HINSTANCE)0x3ee8,uID,unaff_EDI,unaff_ESI),
                   iVar7 == 0)) goto LAB_00886a61;
                CStringT<>();
                local_8._0_1_ = 6;
                uVar5 = FUN_00797a2b();
                FUN_004059f0(&local_1550,&DAT_0095b714,uVar5);
                FUN_0081b772();
                local_8._0_1_ = 7;
                uVar5 = FUN_00874dc7(1,0,0xffffffff,local_1550,0);
                local_8._0_1_ = 8;
                FUN_0081dea9(uVar5,0xffffffff);
                local_8._0_1_ = 7;
                FUN_00874eb0();
                iVar7 = local_154c[0];
                pcVar1 = *(code **)(local_13e8 + 0x43c);
                guard_check_icall();
                uVar5 = (*pcVar1)();
                FUN_00874dc7(0xffffffff,uVar5,0xffffffff,iVar7,0);
                piVar6 = local_1554;
                local_8 = CONCAT31(local_8._1_3_,9);
                FUN_0081dea9(local_fc,0xffffffff);
                FUN_00874eb0();
                FUN_0081b926();
                FUN_00406b10();
                local_8 = 0xffffffff;
                FUN_00406b10();
                in_ECX = local_1558;
              }
            }
          }
        }
        FUN_00874dc7(*(undefined4 *)(in_ECX + 0xe8),0,0xffffffff,*(undefined4 *)(in_ECX + 0xf4),0);
        local_8 = 0xf;
        FUN_0081dea9(local_2e8,0xffffffff);
        CStringT<>();
        local_8._0_1_ = 0x10;
        iVar7 = FID_conflict_LoadStringA((HINSTANCE)0x427a,uID,unaff_EDI,unaff_ESI);
        if (iVar7 == 0) {
LAB_00886a61:
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        pcVar1 = *(code **)(*piVar6 + 0x1c8);
        guard_check_icall();
        piVar6 = (int *)(*pcVar1)();
        pcVar1 = *(code **)(*piVar6 + 0x43c);
        guard_check_icall();
        uVar5 = (*pcVar1)();
        FUN_00874dc7(0xffffffff,uVar5,0xffffffff,local_1550,0);
        local_8._0_1_ = 0x11;
        local_31c = 1;
        pcVar1 = *(code **)(*local_1554 + 4);
        guard_check_icall(1);
        (*pcVar1)();
        if (((*(int *)(in_ECX + 0xf8) != 0) && (*(int *)(*(int *)(in_ECX + 0xf8) + 0xbcc) != 0)) &&
           (iVar7 = FUN_007fc665(), iVar7 != 0)) {
          CStringT<>();
          local_8._0_1_ = 0x12;
          iVar7 = FUN_007fe83b();
          if (iVar7 == 0) {
            hInstance = (HINSTANCE)0x4283;
          }
          else {
            hInstance = (HINSTANCE)0x4284;
          }
          iVar7 = FID_conflict_LoadStringA(hInstance,uID,unaff_EDI,unaff_ESI);
          if (iVar7 == 0) goto LAB_00886a61;
          FUN_0089e5b7(0xffffffec,0,0xffffffff,local_1558,0);
          DAT_00a13c80 = *(undefined4 *)(in_ECX + 0xf8);
          local_8._0_1_ = 0x13;
          local_100 = 1;
          FUN_0081dea9(local_200,0xffffffff);
          FUN_0089e621();
          local_8._0_1_ = 0x11;
          FUN_00406b10();
        }
        this = local_155c;
        FUN_0081dea9(local_3d0,0xffffffff);
        CMFCPopupMenu::SetQuickMode(this);
        *(undefined4 *)(this + 0x1168) = 1;
        FUN_00874eb0();
        FUN_00406b10();
      }
      local_8 = 0xffffffff;
      FUN_00874eb0();
    }
    if (*(CWnd **)(in_ECX + 0xf8) != (CWnd *)0x0) {
      pCVar11 = CWnd::GetOwner(*(CWnd **)(in_ECX + 0xf8));
      *(CWnd **)(this + 0x134) = pCVar11;
    }
  }
  else {
    this = (CMFCPopupMenu *)0x0;
  }
  ExceptionList = local_10;
  return this;
}




/* vtable slots: CMFCCustomizeButton[0] */
/* 00886a67  FUN_00886a67  6 bytes, 0 callers */

undefined ** FUN_00886a67(void)

{
  return &PTR_s_CMFCCustomizeButton_00a00ac4;
}




/* vtable slots: CMFCCustomizeButton[63], COutlookCustomizeButton[63] */
/* 00886a6d  FUN_00886a6d  235 bytes, 0 callers */

undefined4 FUN_00886a6d(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  uint wParam;
  code *pcVar2;
  int iVar3;
  __POSITION *p_Var4;
  CWnd *pCVar5;
  int in_ECX;
  int *piVar6;
  
  if ((*(int *)(in_ECX + 0xf8) != 0) && (iVar3 = FUN_007fc033(param_2), -1 < iVar3)) {
    if ((0 < *(int *)(in_ECX + 0x11c)) &&
       ((*(byte *)(*(int *)(*(int *)(in_ECX + 0x114) + 8) + 0x24) & 1) != 0)) {
      iVar3 = iVar3 + 1;
    }
    p_Var4 = CObList::FindIndex((CObList *)(in_ECX + 0x110),iVar3);
    if (p_Var4 != (__POSITION *)0x0) {
      piVar1 = *(int **)(p_Var4 + 8);
      wParam = piVar1[8];
      pcVar2 = *(code **)(**(int **)(in_ECX + 0xf8) + 1000);
      piVar6 = piVar1;
      guard_check_icall(piVar1);
      iVar3 = (*pcVar2)();
      if (((iVar3 == 0) && (wParam != 0)) && (wParam != 0xffffffff)) {
        CMFCToolBar::AddCommandUsage(wParam);
        pcVar2 = *(code **)(*piVar1 + 0x24);
        guard_check_icall(piVar6);
        iVar3 = (*pcVar2)();
        if ((iVar3 == 0) && ((DAT_00a13bac == 0 || (iVar3 = FUN_00852536(wParam), iVar3 == 0)))) {
          pCVar5 = CWnd::GetOwner(*(CWnd **)(in_ECX + 0xf8));
          PostMessageW(*(HWND *)(pCVar5 + 0x20),0x111,wParam,0);
        }
      }
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCCustomizeButton[7], COutlookCustomizeButton[7] */
/* 00886b58  FUN_00886b58  250 bytes, 0 callers */

void FUN_00886b58(int *param_1,undefined4 param_2,int *param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int unaff_EBX;
  LPSTR unaff_ESI;
  UINT unaff_EDI;
  int iVar6;
  undefined1 local_c [8];
  
  if (*(int *)(in_ECX + 0xfc) == 0) {
    if ((*(int *)(*(int *)(in_ECX + 0x2c) + -0xc) == 0) &&
       ((iVar2 = FID_conflict_LoadStringA((HINSTANCE)0x4279,unaff_EDI,unaff_ESI,unaff_EBX),
        iVar2 == 0 || (*(int *)(*(int *)(in_ECX + 0x2c) + -0xc) == 0)))) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if (*(int **)(in_ECX + 0xf8) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0xf8) + 0x168);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        *param_1 = 0;
        param_1[1] = 0;
        return;
      }
    }
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0x2e8);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((DAT_00a127b4 == 0) || (DAT_00a13bf8 != 0)) {
      iVar6 = 1;
    }
    else {
      iVar6 = 2;
    }
    if (param_4 == 0) {
      iVar4 = FUN_0081507c(local_c);
      iVar5 = *param_3;
      param_1[1] = *(int *)(iVar4 + 4) * iVar6 + iVar2 * 2;
    }
    else {
      iVar5 = param_3[1];
      piVar3 = (int *)FUN_0081507c(local_c);
      iVar4 = *piVar3;
      param_1[1] = iVar5;
      iVar5 = iVar4 * iVar6 + iVar2 * 2;
    }
    *param_1 = iVar5;
  }
  else {
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}




/* vtable slots: CMFCCustomizeButton[22], COutlookCustomizeButton[22] */
/* 00886c53  OnCancelMode  61 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCCustomizeButton::OnCancelMode(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall CMFCCustomizeButton::OnCancelMode(CMFCCustomizeButton *this)

{
  int iVar1;
  
  FUN_00877000();
  iVar1 = FUN_004208d0(0,0);
  if ((iVar1 != 0) && (*(int *)(this + 0xf8) != 0)) {
    iVar1 = FUN_007fc033(this);
    if (-1 < iVar1) {
      FUN_007fe655(iVar1);
    }
  }
  return;
}




/* vtable slots: CMFCCustomizeButton[10], COutlookCustomizeButton[10] */
/* 00886c90  OnChangeParentWnd  95 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCCustomizeButton::OnChangeParentWnd(class CWnd *)
   
   Library: Visual Studio 2012 Release */

void __thiscall CMFCCustomizeButton::OnChangeParentWnd(CMFCCustomizeButton *this,CWnd *param_1)

{
  CObject *pCVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  
  FUN_00881617(param_1);
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,(CObject *)param_1);
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xfc) = 0;
  *(CObject **)(this + 0xf8) = pCVar1;
  *(CWnd **)(this + 0x6c) = param_1;
  pHVar2 = GetParent(*(HWND *)(param_1 + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CReBar_0098511c,(CObject *)pCVar3);
  *(uint *)(this + 0x108) = (uint)(pCVar1 != (CObject *)0x0);
  return;
}




/* vtable slots: CMFCCustomizeButton[6] */
/* 00886cef  FUN_00886cef  657 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00886cef(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  code *pcVar5;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int *local_30;
  int *local_2c;
  int local_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_34 = param_1;
  local_30 = param_2;
  if (in_ECX[0x25] != 0) {
    return;
  }
  local_28 = *param_2;
  iStack_24 = param_2[1];
  iStack_20 = param_2[2];
  iStack_1c = param_2[3];
  in_ECX[0x40] = 1;
  local_2c = in_ECX;
  if (param_6 == 0) {
    pcVar5 = *(code **)(*in_ECX + 0x70);
    guard_check_icall();
    iVar1 = (*pcVar5)();
    if (iVar1 == 0) {
      uVar2 = 0;
      goto LAB_00886d57;
    }
  }
  uVar2 = 1;
LAB_00886d57:
  FUN_0088114d(local_34,&local_28,uVar2,0);
  piVar3 = (int *)FUN_007c2574();
  pcVar5 = *(code **)(*piVar3 + 0x2e8);
  guard_check_icall();
  iVar1 = (*pcVar5)();
  if (local_2c[0x40] != 0) {
    FUN_0081507c(&local_3c);
    if ((DAT_00a127b4 != 0) && (DAT_00a13bf8 == 0)) {
      local_3c = local_3c * 2;
      local_38 = local_38 * 2;
    }
    if (0 < local_2c[0x3a]) {
      local_18.left = *local_30;
      local_18.top = local_30[1];
      local_18.right = local_30[2];
      local_18.bottom = local_30[3];
      if (param_4 == 0) {
        local_18.right = local_18.left + iVar1 * 2 + local_3c;
      }
      else {
        local_18.top = (local_18.bottom + iVar1 * -2) - local_38;
      }
      if ((((local_2c[9] & 0x30000U) != 0) || (local_2c[0x23] != 0)) &&
         (iVar4 = FUN_007c2574(), *(int *)(iVar4 + 0x50) == 0)) {
        OffsetRect(&local_18,1,1);
      }
      FUN_00814d1c(local_34,(-(uint)(param_4 != 0) & 0xfffffff7) + 9,&local_18,0,&local_3c);
    }
    if (local_2c[0x47] != 0) {
      local_18.left = *local_30;
      local_18.top = local_30[1];
      local_18.right = local_30[2];
      local_18.bottom = local_30[3];
      if (param_4 == 0) {
        local_18.left = (local_18.right + iVar1 * -2) - local_3c;
      }
      else {
        local_18.bottom = local_18.top + iVar1 * 2 + local_38;
      }
      if ((((local_2c[9] & 0x30000U) != 0) || (local_2c[0x23] != 0)) &&
         (iVar1 = FUN_007c2574(), *(int *)(iVar1 + 0x50) == 0)) {
        OffsetRect(&local_18,1,1);
      }
      FUN_00814d1c(local_34,(-(param_4 != 0) & 3U) + 8,&local_18,0,&local_3c);
    }
  }
  if (param_5 == 0) {
    if (((local_2c[9] & 0x30000U) == 0) && (local_2c[0x23] == 0)) {
      if (param_6 == 0) {
        return;
      }
      if ((local_2c[9] & 0x150000U) != 0) {
        return;
      }
      local_30 = (int *)FUN_007c2574();
      pcVar5 = *(code **)(*local_30 + 0x88);
      guard_check_icall(local_34,local_2c,local_28,iStack_24,iStack_20,iStack_1c,2);
    }
    else {
      local_30 = (int *)FUN_007c2574();
      pcVar5 = *(code **)(*local_30 + 0x88);
      guard_check_icall(local_34,local_2c,local_28,iStack_24,iStack_20,iStack_1c,1);
    }
    (*pcVar5)();
  }
  return;
}



