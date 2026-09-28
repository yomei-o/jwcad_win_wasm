/* CMFCRibbonGallery -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonGallery[43], CMFCRibbonUndoButton[43] */
/* 008a1222  SetACCData  31 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCRibbonGallery::SetACCData(class CWnd *,class
   CAccessibilityData &)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCRibbonGallery::SetACCData(CMFCRibbonGallery *this,CWnd *param_1,CAccessibilityData *param_2)

{
  FUN_00869cab(param_1,param_2);
  *(undefined4 *)(param_2 + 0x18) = 0x3a;
  return 1;
}




/* vtable slots: CMFCRibbonGallery[1] */
/* 008af0ad  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonGallery::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonGallery::_scalar_deleting_destructor_(CMFCRibbonGallery *this,uint param_1)

{
  FUN_008af02c();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x378);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonGallery[90] */
/* 008af26e  FUN_008af26e  422 bytes, 2 callers */

void FUN_008af26e(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  
  FUN_0086612f(param_1);
  iVar1 = FUN_0079d98a(&PTR_s_CMFCRibbonGallery_009a0360);
  if (iVar1 != 0) {
    FUN_008b0e77();
    FUN_007e8118(in_ECX + 0x200);
    iVar1 = 0;
    *(undefined4 *)(in_ECX + 0x358) = *(undefined4 *)(param_1 + 0x358);
    *(undefined4 *)(in_ECX + 0x344) = *(undefined4 *)(param_1 + 0x344);
    *(undefined4 *)(in_ECX + 0x35c) = *(undefined4 *)(param_1 + 0x35c);
    *(undefined4 *)(in_ECX + 0x360) = *(undefined4 *)(param_1 + 0x360);
    *(undefined4 *)(in_ECX + 0x32c) = *(undefined4 *)(param_1 + 0x32c);
    *(undefined4 *)(in_ECX + 0x350) = *(undefined4 *)(param_1 + 0x350);
    *(undefined4 *)(in_ECX + 0x348) = *(undefined4 *)(param_1 + 0x348);
    *(undefined4 *)(in_ECX + 0x334) = *(undefined4 *)(param_1 + 0x334);
    *(undefined4 *)(in_ECX + 0x364) = *(undefined4 *)(param_1 + 0x364);
    *(undefined4 *)(in_ECX + 0x368) = *(undefined4 *)(param_1 + 0x368);
    *(undefined4 *)(in_ECX + 0x34c) = *(undefined4 *)(param_1 + 0x34c);
    *(undefined4 *)(in_ECX + 0x36c) = *(undefined4 *)(param_1 + 0x36c);
    FUN_007bf7c0(0,0xffffffff);
    FUN_0042fb40(0,0xffffffff);
    if (0 < *(int *)(param_1 + 0x1e0)) {
      iVar4 = 0;
      do {
        uVar2 = FUN_0049a990(iVar4);
        FUN_007bf724(*(undefined4 *)(in_ECX + 0x1e0),uVar2);
        puVar3 = (undefined4 *)FUN_005db5d0(iVar4);
        FUN_0042f500(*(undefined4 *)(in_ECX + 500),*puVar3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x1e0));
    }
    FUN_007bf7c0(0,0xffffffff);
    if (0 < *(int *)(param_1 + 800)) {
      do {
        uVar2 = FUN_0049a990(iVar1);
        FUN_007bf724(*(undefined4 *)(in_ECX + 800),uVar2);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 800));
    }
    FUN_008af44e();
  }
  return;
}




/* vtable slots: CMFCRibbonGallery[164], CMFCRibbonUndoButton[164] */
/* 008af815  FUN_008af815  263 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_008af815(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  UINT in_stack_ffffffdc;
  LPSTR in_stack_ffffffe0;
  int in_stack_ffffffe4;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8af821;
  iVar3 = *(int *)(param_2 + 0x1c8);
  CStringT<>();
  local_8 = 0;
  if (iVar3 == -3) {
    iVar3 = FID_conflict_LoadStringA
                      ((HINSTANCE)0x42d3,in_stack_ffffffdc,in_stack_ffffffe0,in_stack_ffffffe4);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
  }
  else {
    if ((iVar3 != -2) && (iVar3 != -1)) {
      if ((iVar3 < 0) || (*(int *)(in_ECX + 800) <= iVar3)) {
        CStringT<>(&DAT_00956338);
        FUN_00406b10();
        return param_1;
      }
      piVar2 = (int *)FUN_00799cf8(iVar3);
      iVar3 = FUN_004054a0(*piVar2 + -0x10);
      goto LAB_008af8d1;
    }
    iVar3 = *(int *)(in_ECX + 0x338);
    iVar1 = *(int *)(in_ECX + 0x33c);
    if (iVar3 == 1) {
      FUN_00571e40(local_14,0x42d4,iVar1 + 1,*(int *)(in_ECX + 0x340) + 1);
    }
    else {
      FUN_00571e40(local_14,0x42d5,iVar1 + 1,iVar3 + iVar1,*(int *)(in_ECX + 0x340) + iVar3);
    }
  }
  iVar3 = FUN_004054a0(local_14[0] + -0x10);
LAB_008af8d1:
  *param_1 = iVar3 + 0x10;
  FUN_00406b10();
  return param_1;
}




/* vtable slots: CMFCRibbonGallery[0] */
/* 008afd71  FUN_008afd71  6 bytes, 0 callers */

undefined ** FUN_008afd71(void)

{
  return &PTR_s_CMFCRibbonGallery_009a0360;
}




/* vtable slots: CMFCRibbonGallery[78] */
/* 008afda9  FUN_008afda9  12 bytes, 0 callers */

bool FUN_008afda9(void)

{
  int in_ECX;
  
  return 0 < *(int *)(in_ECX + 0x34c);
}




/* vtable slots: CMFCRibbonGallery[162], CMFCRibbonUndoButton[162] */
/* 008b025c  FUN_008b025c  342 bytes, 1 callers */

void FUN_008b025c(CObject *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  CObject *pCVar4;
  BOOL BVar5;
  int iVar6;
  int *in_ECX;
  int iVar7;
  int iVar8;
  int local_8;
  
  iVar8 = *(int *)(param_1 + 0x1c8);
  if (iVar8 != -3) {
    if (iVar8 == -2) {
      iVar8 = in_ECX[0xd0];
      if (in_ECX[0xcf] + 1 <= in_ECX[0xd0]) {
        iVar8 = in_ECX[0xcf] + 1;
      }
    }
    else {
      if (iVar8 != -1) {
        local_8 = 0;
        iVar8 = 0;
        if (0 < in_ECX[0x73]) {
          do {
            puVar3 = (undefined4 *)FUN_00799cf8(iVar8);
            pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                        (CObject *)*puVar3);
            if (pCVar4 != (CObject *)0x0) {
              if (*(int *)(pCVar4 + 0xd8) != 0) {
                *(undefined4 *)(pCVar4 + 0xd8) = 0;
              }
              if (pCVar4 == param_1) {
                in_ECX[0xd1] = local_8;
                *(undefined4 *)(param_1 + 0xd8) = 1;
                BVar5 = IsRectEmpty((RECT *)(param_1 + 0x74));
                if ((BVar5 != 0) && (0 < in_ECX[0xcc])) {
                  iVar6 = local_8 / in_ECX[0xcc];
                  iVar7 = in_ECX[0xd0];
                  if (iVar6 <= in_ECX[0xd0]) {
                    iVar7 = iVar6;
                  }
                  in_ECX[0xcf] = iVar7;
                  FUN_008b0b9a();
                }
              }
              local_8 = local_8 + 1;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < in_ECX[0x73]);
        }
        pcVar1 = *(code **)(*in_ECX + 0x1b8);
        guard_check_icall();
        (*pcVar1)();
        iVar8 = in_ECX[0xcb];
        uVar2 = *(undefined4 *)(param_1 + 0x1c8);
        if (iVar8 == 0) {
          iVar8 = in_ECX[0x29];
        }
        puVar3 = (undefined4 *)FUN_007e3332(iVar8);
        *puVar3 = uVar2;
        return;
      }
      iVar8 = in_ECX[0xcf] + -1;
      if (in_ECX[0xcf] + -1 < 0) {
        iVar8 = 0;
      }
    }
    in_ECX[0xcf] = iVar8;
    FUN_008b0b9a();
    pcVar1 = *(code **)(*in_ECX + 0x1b8);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonGallery[169] */
/* 008b06bb  FUN_008b06bb  102 bytes, 0 callers */

void FUN_008b06bb(undefined4 param_1,LONG param_2,LONG param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (in_ECX[0xd9] == 0) {
    if (in_ECX[0xd6] == 0) {
      InflateRect((LPRECT)&param_2,-4,-4);
    }
    uVar6 = 0xff;
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = 0;
    pcVar1 = *(code **)(*in_ECX + 0xdc);
    guard_check_icall(0,0,0,0xff);
    uVar2 = (*pcVar1)();
    FUN_007e8cae(param_1,param_2,param_3,param_6,0,uVar2,uVar3,uVar4,uVar5,uVar6);
  }
  return;
}




/* vtable slots: CMFCRibbonGallery[79] */
/* 008b0950  FUN_008b0950  586 bytes, 2 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008b0950(void)

{
  code *pcVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  CMFCRibbonBar *pCVar5;
  int iVar6;
  undefined4 *puVar7;
  CMFCRibbonBaseElement *in_ECX;
  CMFCRibbonBaseElement *pCVar8;
  int local_44 [2];
  undefined4 local_3c;
  CMFCRibbonBaseElement *local_38;
  int local_34;
  int *local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x8b095c;
  pcVar1 = *(code **)(*(int *)in_ECX + 0xa4);
  guard_check_icall();
  local_34 = (*pcVar1)();
  if ((((local_34 != 0) && (*(int *)(local_34 + 0x20) != 0)) &&
      (pCVar5 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX), pCVar5 != (CMFCRibbonBar *)0x0)
      ) && (*(int *)(pCVar5 + 0x20) != 0)) {
    CMFCRibbonBaseElement::OnShowPopupMenu(in_ECX);
    local_2c = FUN_00797acc();
    local_2c = local_2c & 0x400000;
    if (*(int *)(in_ECX + 0x1cc) == 0) {
      FUN_008af44e();
    }
    iVar6 = *(int *)(in_ECX + 0x32c);
    if (iVar6 == 0) {
      iVar6 = *(int *)(in_ECX + 0xa4);
    }
    iVar6 = FID_conflict_GetLastSelectedItem(iVar6);
    if (-1 < iVar6) {
      FUN_008b0ed4(iVar6);
    }
    iVar6 = CMFCRibbonGallery::IsButtonLook((CMFCRibbonGallery *)in_ECX);
    pCVar8 = in_ECX;
    if (iVar6 == 0) {
      puVar7 = (undefined4 *)FUN_00799cf8(*(int *)(in_ECX + 0x1cc) + -1);
      pCVar8 = (CMFCRibbonBaseElement *)*puVar7;
    }
    local_38 = pCVar8;
    local_3c = FUN_00792a04(0,0);
    local_30 = (int *)FUN_0078e624(0x2040);
    local_8 = 0;
    if (local_30 == (int *)0x0) {
      local_30 = (int *)0x0;
    }
    else {
      local_30 = (int *)FUN_008b61f5(in_ECX);
    }
    piVar2 = local_30;
    local_8 = 0xffffffff;
    FUN_00820bbf(pCVar8);
    piVar2[0x7d4] = 1;
    local_24 = *(undefined4 *)(in_ECX + 0x74);
    local_20 = *(int *)(in_ECX + 0x78);
    local_1c = *(undefined4 *)(in_ECX + 0x7c);
    local_18 = *(int *)(in_ECX + 0x80);
    FUN_0079e8b8(&local_24);
    iVar6 = *(int *)(in_ECX + 0x358);
    pcVar1 = *(code **)(*(int *)in_ECX + 0x28c);
    guard_check_icall(local_44);
    (*pcVar1)();
    uVar3 = local_2c;
    local_34 = local_44[0] + (-(uint)(iVar6 != 0) & 0xfffffff8) + 8;
    if (local_2c == 0) {
      local_28 = local_24;
    }
    else {
      local_28 = local_1c;
    }
    local_2c = local_18;
    iVar6 = FUN_00863d99();
    uVar4 = local_1c;
    if (iVar6 != 0) {
      if (uVar3 == 0) {
        local_28 = local_1c;
      }
      else {
        local_28 = local_24;
      }
      local_2c = local_20;
    }
    iVar6 = CMFCRibbonGallery::IsButtonLook((CMFCRibbonGallery *)in_ECX);
    piVar2 = local_30;
    if (iVar6 == 0) {
      if (uVar3 == 0) {
        local_28 = local_24;
      }
      else {
        local_28 = uVar4;
      }
      local_2c = local_20 + 3;
    }
    iVar6 = *(int *)(in_ECX + 0x348);
    if (iVar6 < 1) {
      if (local_38 == in_ECX) {
        iVar6 = 4;
      }
      else {
        iVar6 = *(int *)(in_ECX + 0x334);
      }
      if (*(int *)(in_ECX + 0x358) == 0) {
        if (iVar6 < 5) {
          iVar6 = 4;
        }
      }
      else {
        iVar6 = 10;
      }
    }
    FUN_008b9099(iVar6 * local_34,0);
    pcVar1 = *(code **)(*piVar2 + 0x210);
    guard_check_icall(local_3c,local_28,local_2c,0,0,0);
    (*pcVar1)();
    FUN_00864a83(piVar2);
    *(undefined4 *)(in_ECX + 0xfc) = 0;
    if (piVar2[0x3d0] != 0) {
      FUN_008216bf();
    }
  }
  FUN_008d9b68();
  return;
}



