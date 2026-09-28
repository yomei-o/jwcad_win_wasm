/* CMFCPopupMenu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCPopupMenu[1] */
/* 0081ba4e  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCPopupMenu::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCPopupMenu::_scalar_deleting_destructor_(CMFCPopupMenu *this,uint param_1)

{
  FUN_0081b926();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1178);
    }
  }
  return this;
}




/* vtable slots: CMFCPopupMenu[127], CMFCRibbonMiniToolBar[127], CMFCRibbonPanelMenu[127] */
/* 0081c617  FUN_0081c617  906 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0081c617(uint param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  CMenu *pCVar3;
  int *piVar4;
  int iVar5;
  UINT UVar6;
  CSimpleStringT<wchar_t,0> *pCVar7;
  HMENU pHVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  int in_ECX;
  HMENU hMenu;
  UINT flags;
  undefined1 local_188 [4];
  int local_184;
  int local_180;
  CMenu *local_17c;
  uint local_178;
  int local_174;
  undefined4 local_170;
  CMFCToolBarMenuButton local_16c [4];
  int local_168;
  undefined4 local_164;
  undefined4 local_160;
  int local_138;
  int local_134;
  CMFCToolBarButton local_84 [4];
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_50;
  int local_4c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x178;
  local_8 = 0x81c626;
  local_174 = param_3;
  local_178 = param_1;
  if (param_3 != 0) {
    if ((*(HMENU__ **)(in_ECX + 0xf34) != (HMENU__ *)0x0) &&
       (local_184 = in_ECX, pCVar3 = CMenu::FromHandle(*(HMENU__ **)(in_ECX + 0xf34)),
       local_17c = pCVar3, pCVar3 != (CMenu *)0x0)) {
      local_180 = FUN_0078e624(0xd40);
      local_8 = 0;
      if (local_180 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_007fab6a();
      }
      local_8 = 0xffffffff;
      flags = 0x50402808;
      pcVar1 = *(code **)(*piVar4 + 800);
      uVar10 = local_178;
      guard_check_icall(local_178,0x50402808,param_2);
      iVar5 = (*pcVar1)();
      if (iVar5 == 0) {
        pcVar1 = *(code **)(*piVar4 + 4);
        guard_check_icall(1);
        (*pcVar1)();
      }
      else {
        FUN_00797ece(local_174);
        local_174 = GetMenuItemCount(*(HMENU *)(pCVar3 + 4));
        hMenu = (HMENU)0x0;
        if (0 < local_174) {
          do {
            UVar6 = GetMenuItemID(*(HMENU *)(local_17c + 4),(int)hMenu);
            CStringT<>();
            local_8 = 1;
            FID_conflict_GetMenuStringA(hMenu,(UINT)&local_170,(LPSTR)0x400,uVar10,flags);
            if (UVar6 == 0) {
              if (hMenu != (HMENU)(local_174 + -1)) {
                pcVar1 = *(code **)(*piVar4 + 0x348);
                guard_check_icall(0xffffffff);
                (*pcVar1)();
              }
            }
            else if (UVar6 == 0xffffffff) {
              local_178 = 0;
              if (DAT_00a13c78 != 0) {
                local_178 = FUN_0089de66(&local_170);
              }
              iVar5 = FUN_0044e690(9,0);
              if (-1 < iVar5) {
                pCVar7 = (CSimpleStringT<wchar_t,0> *)Left(&local_180,iVar5);
                local_8._0_1_ = 2;
                ATL::CSimpleStringT<wchar_t,0>::operator=
                          ((CSimpleStringT<wchar_t,0> *)&local_170,pCVar7);
                local_8 = CONCAT31(local_8._1_3_,1);
                FUN_00406b10();
              }
              uVar2 = local_170;
              pHVar8 = GetSubMenu(*(HMENU *)(local_17c + 4),(int)hMenu);
              pCVar3 = CMenu::FromHandle(pHVar8);
              uVar9 = 0;
              if (pCVar3 != (CMenu *)0x0) {
                uVar9 = *(undefined4 *)(pCVar3 + 4);
              }
              FUN_00874dc7(0xffffffff,uVar9,0xffffffff,uVar2,0);
              local_8 = CONCAT31(local_8._1_3_,3);
              iVar5 = local_134;
              if (local_168 == 0) {
                iVar5 = local_138;
              }
              if (iVar5 == -1) {
                local_160 = 0;
                local_164 = 1;
              }
              CMFCToolBarMenuButton::SetTearOff(local_16c,local_178);
              pcVar1 = *(code **)(*piVar4 + 0x344);
              guard_check_icall(local_16c,0xffffffff);
              (*pcVar1)();
              FUN_00874eb0();
            }
            else {
              iVar5 = IsStandardCommand(UVar6);
              if (iVar5 == 0) {
                FUN_00880d51(UVar6,0xffffffff,local_170,0,0);
                local_8 = CONCAT31(local_8._1_3_,4);
                iVar5 = local_4c;
                if (local_80 == 0) {
                  iVar5 = local_50;
                }
                if (iVar5 == -1) {
                  local_78 = 0;
                  local_7c = 1;
                }
                pcVar1 = *(code **)(*piVar4 + 0x344);
                guard_check_icall(local_84,0xffffffff);
                (*pcVar1)();
                CMFCToolBarButton::~CMFCToolBarButton(local_84);
              }
            }
            local_8 = 0xffffffff;
            FUN_00406b10();
            hMenu = (HMENU)((int)&hMenu->unused + 1);
          } while ((int)hMenu < local_174);
        }
        iVar5 = *piVar4;
        pcVar1 = *(code **)(iVar5 + 0x1c0);
        guard_check_icall();
        uVar10 = (*pcVar1)();
        pcVar1 = *(code **)(iVar5 + 0x1e4);
        guard_check_icall(uVar10 | 0x34);
        (*pcVar1)();
        pcVar1 = *(code **)(*piVar4 + 0x1ec);
        guard_check_icall(0xf000);
        (*pcVar1)();
        iVar5 = *(int *)(local_184 + 0x158);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xb0) != 0)) {
          iVar5 = local_174 / *(int *)(iVar5 + 0xc0);
          pcVar1 = *(code **)(*piVar4 + 0x358);
          guard_check_icall();
          iVar11 = (*pcVar1)();
          pcVar1 = *(code **)(*piVar4 + 0x208);
          guard_check_icall(local_188,iVar11 * (iVar5 + 1),0);
          (*pcVar1)();
        }
      }
    }
    FUN_008d9b68();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCPopupMenu[114] */
/* 0081d468  FUN_0081d468  7 bytes, 0 callers */

int FUN_0081d468(void)

{
  int in_ECX;
  
  return in_ECX + 0x160;
}




/* vtable slots: CMFCPopupMenu[10] */
/* 0081d4b5  FUN_0081d4b5  6 bytes, 0 callers */

undefined ** FUN_0081d4b5(void)

{
  return &PTR_FUN_0098eb30;
}




/* vtable slots: CMFCPopupMenu[0] */
/* 0081d59f  FUN_0081d59f  6 bytes, 0 callers */

undefined ** FUN_0081d59f(void)

{
  return &PTR_s_CMFCPopupMenu_00a00790;
}



