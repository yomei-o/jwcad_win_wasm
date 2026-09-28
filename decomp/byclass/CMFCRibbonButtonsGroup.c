/* CMFCRibbonButtonsGroup -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonButtonsGroup[1], CMFCRibbonRecentFilesList[1] */
/* 008b4eaf  FUN_008b4eaf  51 bytes, 0 callers */

void FUN_008b4eaf(byte param_1)

{
  FUN_008c4946();
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




/* vtable slots: CMFCRibbonButtonsGroup[120], CMFCRibbonQuickAccessToolBar[120], CMFCRibbonRecentFilesList[120] */
/* 008c49fd  FUN_008c49fd  87 bytes, 0 callers */

void FUN_008c49fd(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1e0);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[93], CMFCRibbonQuickAccessToolBar[93], CMFCRibbonRecentFilesList[93] */
/* 008c4a54  FUN_008c4a54  99 bytes, 0 callers */

undefined4 FUN_008c4a54(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 local_8;
  
  uVar3 = 0xffffffff;
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x174);
      guard_check_icall(param_1,param_2);
      uVar3 = (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonButtonsGroup[97], CMFCRibbonQuickAccessToolBar[97], CMFCRibbonRecentFilesList[97] */
/* 008c4ab7  FUN_008c4ab7  82 bytes, 0 callers */

void FUN_008c4ab7(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x184);
      guard_check_icall();
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[90], CMFCRibbonQuickAccessToolBar[90], CMFCRibbonRecentFilesList[90] */
/* 008c4b09  FUN_008c4b09  214 bytes, 0 callers */

void FUN_008c4b09(CMFCRibbonBaseElement *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int *piVar3;
  CMFCRibbonBaseElement *in_ECX;
  int local_8;
  
  CMFCRibbonBaseElement::CopyFrom(in_ECX,param_1);
  FUN_008c58f7();
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      puVar2 = (undefined4 *)*puVar2;
      pcVar1 = *(code **)*puVar2;
      guard_check_icall();
      (*pcVar1)();
      piVar3 = (int *)FUN_0079d90c();
      pcVar1 = *(code **)(*piVar3 + 0x168);
      guard_check_icall(puVar2);
      (*pcVar1)();
      FUN_0079c90d(*(undefined4 *)(in_ECX + 0x114),piVar3);
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(param_1 + 0x114));
  }
  FUN_007e8118(in_ECX + 0x120);
  FUN_007e8118(in_ECX + 0x238);
  FUN_007e8118(in_ECX + 0x350);
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[103], CMFCRibbonQuickAccessToolBar[103], CMFCRibbonRecentFilesList[103] */
/* 008c4c0f  FUN_008c4c0f  92 bytes, 0 callers */

int FUN_008c4c0f(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x19c);
      guard_check_icall(param_1);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[105], CMFCRibbonQuickAccessToolBar[105], CMFCRibbonRecentFilesList[105] */
/* 008c4c6b  FUN_008c4c6b  92 bytes, 0 callers */

int FUN_008c4c6b(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1a4);
      guard_check_icall(param_1);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[104], CMFCRibbonQuickAccessToolBar[104], CMFCRibbonRecentFilesList[104] */
/* 008c4cc7  FUN_008c4cc7  92 bytes, 0 callers */

int FUN_008c4cc7(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1a0);
      guard_check_icall(param_1);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[106], CMFCRibbonQuickAccessToolBar[106], CMFCRibbonRecentFilesList[106] */
/* 008c4d23  FUN_008c4d23  92 bytes, 0 callers */

int FUN_008c4d23(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1a8);
      guard_check_icall(param_1);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[113], CMFCRibbonQuickAccessToolBar[113], CMFCRibbonRecentFilesList[113] */
/* 008c4dc7  FUN_008c4dc7  87 bytes, 0 callers */

int FUN_008c4dc7(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1c4);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[122], CMFCRibbonQuickAccessToolBar[122], CMFCRibbonRecentFilesList[122] */
/* 008c4e1e  FUN_008c4e1e  90 bytes, 0 callers */

void FUN_008c4e1e(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1e8);
      guard_check_icall(param_1,param_2);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[130], CMFCRibbonQuickAccessToolBar[130], CMFCRibbonRecentFilesList[130] */
/* 008c4e78  FUN_008c4e78  87 bytes, 0 callers */

int FUN_008c4e78(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x208);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[115], CMFCRibbonQuickAccessToolBar[115], CMFCRibbonRecentFilesList[115] */
/* 008c4ecf  FUN_008c4ecf  87 bytes, 0 callers */

int FUN_008c4ecf(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1cc);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[114], CMFCRibbonQuickAccessToolBar[114], CMFCRibbonRecentFilesList[114] */
/* 008c4f26  FUN_008c4f26  87 bytes, 0 callers */

int FUN_008c4f26(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1c8);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[141], CMFCRibbonQuickAccessToolBar[141], CMFCRibbonRecentFilesList[141] */
/* 008c4fa9  FUN_008c4fa9  87 bytes, 0 callers */

void FUN_008c4fa9(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x234);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[131], CMFCRibbonQuickAccessToolBar[131], CMFCRibbonRecentFilesList[131] */
/* 008c5000  FUN_008c5000  76 bytes, 0 callers */

int FUN_008c5000(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x114);
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      return 0;
    }
    puVar3 = (undefined4 *)FUN_00799cf8(iVar1);
    pcVar2 = *(code **)(*(int *)*puVar3 + 0x20c);
    guard_check_icall();
    iVar4 = (*pcVar2)();
  } while (iVar4 == 0);
  return iVar4;
}




/* vtable slots: CMFCRibbonButtonsGroup[112], CMFCRibbonQuickAccessToolBar[112], CMFCRibbonRecentFilesList[112] */
/* 008c504c  FUN_008c504c  87 bytes, 0 callers */

int FUN_008c504c(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1c0);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[62] */
/* 008c50a3  FUN_008c50a3  216 bytes, 1 callers */

int * FUN_008c50a3(int *param_1,undefined4 param_2)

{
  int *piVar1;
  code *pcVar2;
  CObject *pCVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8 = in_ECX;
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonStatusBar_009a090c,
                              *(CObject **)(in_ECX + 0x84));
  local_10 = (uint)(pCVar3 != (CObject *)0x0);
  iVar6 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    local_c = in_ECX + 0x10c;
    iVar7 = iVar6;
    do {
      puVar4 = (undefined4 *)FUN_00799cf8(iVar7);
      piVar1 = (int *)*puVar4;
      pcVar2 = *(code **)(*piVar1 + 0x110);
      guard_check_icall(1);
      (*pcVar2)();
      pcVar2 = *(code **)(*piVar1 + 0x180);
      guard_check_icall(param_2);
      (*pcVar2)();
      pcVar2 = *(code **)(*piVar1 + 0xf4);
      guard_check_icall(&local_18,param_2);
      (*pcVar2)();
      iVar6 = *param_1 + local_18;
      *param_1 = iVar6;
      iVar5 = param_1[1];
      if (param_1[1] <= local_14) {
        iVar5 = local_14;
      }
      param_1[1] = iVar5;
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(local_8 + 0x114));
  }
  if (local_10 != 0) {
    *param_1 = iVar6 + 2;
  }
  return param_1;
}




/* vtable slots: CMFCRibbonButtonsGroup[0] */
/* 008c517b  FUN_008c517b  6 bytes, 0 callers */

undefined ** FUN_008c517b(void)

{
  return &PTR_s_CMFCRibbonButtonsGroup_009a3f90;
}




/* vtable slots: CMFCRibbonButtonsGroup[124], CMFCRibbonQuickAccessToolBar[124], CMFCRibbonRecentFilesList[124] */
/* 008c5181  FUN_008c5181  87 bytes, 0 callers */

void FUN_008c5181(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1f0);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[75], CMFCRibbonQuickAccessToolBar[75], CMFCRibbonRecentFilesList[75] */
/* 008c51d8  HitTest  82 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual class CMFCRibbonBaseElement * __thiscall
   CMFCRibbonButtonsGroup::HitTest(class CPoint)
   
   Library: Visual Studio 2015 Release */

CMFCRibbonBaseElement * __thiscall
CMFCRibbonButtonsGroup::HitTest(CMFCRibbonButtonsGroup *this,LONG param_2,LONG param_3)

{
  CMFCRibbonBaseElement *pCVar1;
  POINT pt;
  int *piVar2;
  BOOL BVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(this + 0x114)) {
    do {
      piVar2 = (int *)FUN_00799cf8(iVar4);
      pCVar1 = (CMFCRibbonBaseElement *)*piVar2;
      pt.y = param_3;
      pt.x = param_2;
      BVar3 = PtInRect((RECT *)(pCVar1 + 0x74),pt);
      if (BVar3 != 0) {
        return pCVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(this + 0x114));
  }
  return (CMFCRibbonBaseElement *)0x0;
}




/* vtable slots: CMFCRibbonButtonsGroup[73] */
/* 008c522a  FUN_008c522a  843 bytes, 1 callers */

void FUN_008c522a(undefined4 param_1)

{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  CObject *pCVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  BOOL BVar9;
  int *in_ECX;
  int *piVar10;
  int *piVar11;
  undefined4 uVar12;
  int local_3c;
  int local_38;
  int *local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  uint local_10;
  int *local_c;
  int *local_8;
  
  local_30 = 1;
  local_1c = in_ECX;
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonStatusBar_009a090c,
                              (CObject *)in_ECX[0x21]);
  local_14 = (int *)(uint)(pCVar4 != (CObject *)0x0);
  pcVar1 = *(code **)(*in_ECX + 0x250);
  guard_check_icall();
  iVar5 = (*pcVar1)();
  if ((iVar5 == 0) ||
     (iVar5 = CMFCRibbonBar::IsQuickAccessToolbarOnTop((CMFCRibbonBar *)in_ECX[0x21]), iVar5 != 0))
  {
    local_18 = 0;
  }
  else {
    local_18 = 1;
  }
  pcVar1 = *(code **)(*in_ECX + 0x250);
  guard_check_icall();
  iVar5 = (*pcVar1)();
  local_2c = (int *)(-(uint)(iVar5 != 0) & 2);
  if (local_18 == 0) {
    local_10 = (uint)local_14;
  }
  else {
    local_10 = 2;
  }
  pcVar1 = *(code **)(*in_ECX + 0x250);
  guard_check_icall();
  iVar5 = (*pcVar1)();
  piVar10 = local_1c;
  if ((iVar5 != 0) || (iVar5 = 0, local_14 != (int *)0x0)) {
    iVar5 = 1;
  }
  local_20 = ((in_ECX[0x20] - in_ECX[0x1e]) - iVar5) - local_10;
  local_14 = (int *)0xffffffff;
  iVar5 = in_ECX[0x1e];
  iVar8 = in_ECX[0x1f];
  local_18 = in_ECX[0x1d] + (int)local_2c;
  pcVar1 = *(code **)(*local_1c + 0x250);
  guard_check_icall();
  iVar6 = (*pcVar1)();
  local_24 = iVar8;
  if ((iVar6 != 0) && (0 < piVar10[0x45])) {
    local_14 = (int *)(piVar10[0x45] + -1);
    puVar7 = (undefined4 *)FUN_00799cf8(local_14);
    pcVar1 = *(code **)(*(int *)*puVar7 + 0xf4);
    guard_check_icall(&local_3c,param_1);
    (*pcVar1)();
    piVar10 = local_1c;
    local_24 = iVar8 - local_3c;
  }
  local_28 = 0;
  local_c = (int *)0x0;
  if (0 < piVar10[0x45]) {
    do {
      local_8 = (int *)FUN_00799cf8(local_c);
      local_8 = (int *)*local_8;
      local_2c = (int *)local_8[0x21];
      local_8[0x39] = 1;
      if (local_2c != (int *)0x0) {
        pcVar1 = *(code **)(*local_2c + 0x344);
        guard_check_icall(piVar10);
        iVar8 = (*pcVar1)();
        if (iVar8 == 0) {
          local_8[0x39] = 0;
        }
      }
      piVar3 = local_8;
      BVar9 = IsRectEmpty((RECT *)(piVar10 + 0x1d));
      if (BVar9 == 0) {
        local_2c = (int *)(piVar10[0x45] + -1);
        pcVar1 = *(code **)(*piVar3 + 0x164);
        guard_check_icall(piVar10[0x22]);
        piVar3 = local_8;
        (*pcVar1)();
        piVar10 = &local_3c;
        pcVar1 = *(code **)(*piVar3 + 0xf4);
        uVar12 = param_1;
        guard_check_icall(piVar10,param_1);
        (*pcVar1)();
        piVar11 = local_8;
        if (local_c == local_14) {
          local_38 = local_20 + -1;
          iVar8 = iVar5;
        }
        else {
          local_38 = local_20;
          iVar8 = iVar5 + local_10;
        }
        local_34 = piVar3 + 0x1d;
        *local_34 = local_18;
        piVar3[0x1e] = iVar8;
        piVar3[0x1f] = local_3c + local_18;
        piVar3[0x20] = iVar8 + local_38;
        if (local_28 == 0) {
LAB_008c54b6:
          bVar2 = false;
        }
        else {
          pcVar1 = *(code **)(*local_8 + 0x118);
          guard_check_icall(piVar10,uVar12);
          iVar8 = (*pcVar1)();
          if (iVar8 == 0) goto LAB_008c54b6;
          bVar2 = true;
        }
        if (((local_24 < piVar11[0x1f]) || (bVar2)) && (local_c != local_14)) {
          local_28 = 1;
          *local_34 = 0;
          local_34[1] = 0;
          local_34[2] = 0;
          local_34[3] = 0;
          piVar11 = local_8;
        }
        else {
          local_18 = local_18 + local_3c;
        }
        pcVar1 = *(code **)(*piVar11 + 0x124);
        guard_check_icall(param_1);
        (*pcVar1)();
        if (local_30 == 0) {
LAB_008c553f:
          piVar11[0x26] = (local_c != local_2c) + 3;
        }
        else if (local_c == local_2c) {
          piVar11[0x26] = 1;
        }
        else {
          if (local_30 == 0) goto LAB_008c553f;
          piVar11[0x26] = 2;
        }
        local_30 = 0;
      }
      else {
        piVar3[0x1d] = 0;
        piVar3[0x1e] = 0;
        piVar3[0x1f] = 0;
        piVar3[0x20] = 0;
        pcVar1 = *(code **)(*local_8 + 0x124);
        guard_check_icall(param_1);
        (*pcVar1)();
      }
      local_c = (int *)((int)local_c + 1);
      piVar10 = local_1c;
    } while ((int)local_c < local_1c[0x45]);
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[95], CMFCRibbonQuickAccessToolBar[95] */
/* 008c5575  FUN_008c5575  360 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008c5575(int *param_1)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  undefined1 local_2c [8];
  int local_24;
  int *local_20;
  code *local_1c;
  CSimpleStringT<wchar_t,0> *local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x8c5581;
  local_24 = in_ECX;
  BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x74));
  if (BVar3 == 0) {
    local_20 = (int *)FUN_007c2574();
    iVar2 = local_24;
    local_1c = *(code **)(*local_20 + 0x264);
    guard_check_icall(param_1,local_24,((RECT *)(in_ECX + 0x74))->left,
                      *(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c),
                      *(undefined4 *)(in_ECX + 0x80));
    iVar4 = (*local_1c)();
    local_24 = -1;
    if (iVar4 != -1) {
      pcVar1 = *(code **)(*param_1 + 0x30);
      guard_check_icall(iVar4);
      local_24 = (*pcVar1)();
    }
    local_20 = (int *)0x0;
    if (0 < *(int *)(iVar2 + 0x114)) {
      do {
        piVar5 = (int *)FUN_00799cf8(local_20);
        piVar5 = (int *)*piVar5;
        local_14 = piVar5;
        BVar3 = IsRectEmpty((RECT *)(piVar5 + 0x1d));
        if (BVar3 == 0) {
          local_18 = (CSimpleStringT<wchar_t,0> *)(piVar5 + 0x18);
          iVar4 = FUN_004054a0(*(int *)local_18 + -0x10);
          local_1c = (code *)(iVar4 + 0x10);
          local_8 = 0;
          pcVar1 = *(code **)(*piVar5 + 0x114);
          guard_check_icall(local_2c,1);
          (*pcVar1)();
          iVar4 = FUN_004208d0(0,0);
          if (iVar4 != 0) {
            Empty();
          }
          pcVar1 = *(code **)(*local_14 + 0x17c);
          guard_check_icall(param_1);
          (*pcVar1)();
          ATL::CSimpleStringT<wchar_t,0>::operator=(local_18,(CSimpleStringT<wchar_t,0> *)&local_1c)
          ;
          local_8 = 0xffffffff;
          FUN_00406b10();
        }
        local_20 = (int *)((int)local_20 + 1);
      } while ((int)local_20 < *(int *)(iVar2 + 0x114));
    }
    if (local_24 != -1) {
      pcVar1 = *(code **)(*param_1 + 0x30);
      guard_check_icall(local_24);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[147], CMFCRibbonQuickAccessToolBar[147], CMFCRibbonRecentFilesList[147] */
/* 008c56dd  FUN_008c56dd  271 bytes, 0 callers */

void FUN_008c56dd(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6,undefined4 param_7)

{
  CMFCToolBarImages *this;
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_24 [16];
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  local_10 = param_1;
  local_8 = param_6;
  pcVar1 = *(code **)(*param_6 + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if ((iVar2 == 0) || (*(int *)(in_ECX + 0x354) == 0)) {
    pcVar1 = *(code **)(*param_6 + 0xd0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((iVar2 == 0) || (iVar2 = 0x238, *(int *)(in_ECX + 0x23c) == 0)) {
      iVar2 = 0x120;
    }
  }
  else {
    iVar2 = 0x350;
  }
  this = (CMFCToolBarImages *)(in_ECX + iVar2);
  if (0 < *(int *)(this + 4)) {
    local_14 = param_2 + 1;
    local_c = param_3;
    iVar2 = FUN_007c2511();
    CMFCToolBarImages::SetTransparentColor(this,*(ulong *)(iVar2 + 0x1c));
    FUN_007eb6ca(local_24,0,0,0);
    iVar2 = FUN_007c2511();
    CMFCToolBarImages::SetTransparentColor(this,*(ulong *)(iVar2 + 0x1c));
    pcVar1 = *(code **)(*local_8 + 0xdc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((iVar2 == 0) || (*(int *)(in_ECX + 0x354) != 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    FUN_007e8cae(local_10,local_14,local_c,param_7,0,uVar3,0,0,0,0xff);
    FUN_007e98b8(local_24);
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[125], CMFCRibbonQuickAccessToolBar[125], CMFCRibbonRecentFilesList[125] */
/* 008c57ec  FUN_008c57ec  87 bytes, 0 callers */

void FUN_008c57ec(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 500);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[74], CMFCRibbonQuickAccessToolBar[74], CMFCRibbonRecentFilesList[74] */
/* 008c5843  FUN_008c5843  87 bytes, 0 callers */

void FUN_008c5843(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x128);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[138], CMFCRibbonQuickAccessToolBar[138], CMFCRibbonRecentFilesList[138] */
/* 008c589a  FUN_008c589a  93 bytes, 0 callers */

void FUN_008c589a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x228);
      guard_check_icall(param_1,param_2,param_3);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[140], CMFCRibbonQuickAccessToolBar[140], CMFCRibbonRecentFilesList[140] */
/* 008c5954  FUN_008c5954  168 bytes, 0 callers */

undefined4 FUN_008c5954(int param_1,int *param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  
  iVar5 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      piVar2 = (int *)FUN_00799cf8(iVar5);
      piVar2 = (int *)*piVar2;
      if (piVar2[0x29] == param_1) {
        pcVar1 = *(code **)(*param_2 + 0x168);
        guard_check_icall(piVar2);
        (*pcVar1)();
        puVar4 = (undefined4 *)FUN_00799cf8(iVar5);
        *puVar4 = param_2;
        pcVar1 = *(code **)(*piVar2 + 4);
        guard_check_icall(1);
        (*pcVar1)();
        return 1;
      }
      pcVar1 = *(code **)(*piVar2 + 0x230);
      guard_check_icall(param_1,param_2);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}




/* vtable slots: CMFCRibbonButtonsGroup[92], CMFCRibbonQuickAccessToolBar[92], CMFCRibbonRecentFilesList[92] */
/* 008c59fc  FUN_008c59fc  143 bytes, 0 callers */

void FUN_008c59fc(CMFCRibbonBaseElement *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  undefined4 *puVar3;
  CMFCRibbonBaseElement *in_ECX;
  int local_8;
  
  CMFCRibbonBaseElement::SetOriginal(in_ECX,param_1);
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButtonsGroup_009a3f90,
                              (CObject *)param_1);
  if (((pCVar2 != (CObject *)0x0) && (*(int *)(pCVar2 + 0x114) == *(int *)(in_ECX + 0x114))) &&
     (local_8 = 0, 0 < *(int *)(in_ECX + 0x114))) {
    do {
      puVar3 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar3 + 0x170);
      puVar3 = (undefined4 *)FUN_00799cf8(local_8);
      guard_check_icall(*puVar3);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[89], CMFCRibbonQuickAccessToolBar[89], CMFCRibbonRecentFilesList[89] */
/* 008c5a8b  FUN_008c5a8b  95 bytes, 0 callers */

void FUN_008c5a8b(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  FUN_007c2817(param_1);
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x164);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[91], CMFCRibbonQuickAccessToolBar[91], CMFCRibbonRecentFilesList[91] */
/* 008c5aea  FUN_008c5aea  95 bytes, 0 callers */

void FUN_008c5aea(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  FUN_00864c59(param_1);
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x16c);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonButtonsGroup[77], CMFCRibbonQuickAccessToolBar[77], CMFCRibbonRecentFilesList[77] */
/* 008c5b49  FUN_008c5b49  97 bytes, 0 callers */

void FUN_008c5b49(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  *(undefined4 *)(in_ECX + 0x84) = param_1;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x134);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  return;
}



