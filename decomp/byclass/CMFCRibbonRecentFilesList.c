/* CMFCRibbonRecentFilesList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonRecentFilesList[62] */
/* 008b56f6  FUN_008b56f6  223 bytes, 0 callers */

void FUN_008b56f6(undefined4 *param_1,undefined4 param_2)

{
  double dVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  undefined4 uVar7;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 4;
  local_c = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar5 = (undefined4 *)FUN_00799cf8(local_c);
      piVar2 = (int *)*puVar5;
      pcVar3 = *(code **)(*piVar2 + 0x180);
      guard_check_icall(param_2);
      (*pcVar3)();
      pcVar3 = *(code **)(*piVar2 + 0xf4);
      guard_check_icall(local_14,param_2);
      (*pcVar3)();
      local_8 = local_8 + local_10 + 8;
      local_c = local_c + 1;
    } while (local_c < *(int *)(in_ECX + 0x114));
  }
  iVar4 = local_8;
  iVar6 = FUN_007c2511();
  if (*(int *)(iVar6 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar6 + 0x1e0);
  }
  if (dVar1 == 1.0) {
    uVar7 = 300;
  }
  else {
    FUN_007c2511();
    uVar7 = thunk_FUN_008d99f0();
  }
  param_1[1] = iVar4;
  *param_1 = uVar7;
  return;
}




/* vtable slots: CMFCRibbonRecentFilesList[0] */
/* 008b57db  FUN_008b57db  6 bytes, 0 callers */

undefined ** FUN_008b57db(void)

{
  return &PTR_s_CMFCRibbonRecentFilesList_009a17b8;
}




/* vtable slots: CMFCRibbonRecentFilesList[73] */
/* 008b588c  FUN_008b588c  284 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b588c(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined1 local_44 [4];
  int local_40;
  int local_3c;
  undefined4 local_38;
  int *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = *(int *)(in_ECX + 0x78) + 2;
  local_38 = param_1;
  local_30 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    local_34 = (int *)(in_ECX + 0x74);
    local_3c = in_ECX;
    do {
      iVar2 = local_3c;
      piVar3 = (int *)FUN_00799cf8(local_30);
      piVar3 = (int *)*piVar3;
      pcVar1 = *(code **)(*piVar3 + 0x16c);
      guard_check_icall(*(undefined4 *)(iVar2 + 0x94));
      (*pcVar1)();
      pcVar1 = *(code **)(*piVar3 + 0x180);
      guard_check_icall(param_1);
      (*pcVar1)();
      pcVar1 = *(code **)(*piVar3 + 0xf4);
      guard_check_icall(local_44,param_1);
      (*pcVar1)();
      local_18.left = *local_34;
      local_18.top = local_34[1];
      local_18.right = local_34[2];
      local_18.bottom = local_34[3];
      InflateRect(&local_18,-1,0);
      param_1 = local_38;
      local_18.top = local_2c;
      iStack_1c = local_40 + local_2c + 8;
      local_28 = local_18.left;
      iStack_24 = local_2c;
      iStack_20 = local_18.right;
      piVar3[0x1d] = local_18.left;
      piVar3[0x1e] = local_2c;
      piVar3[0x1f] = local_18.right;
      piVar3[0x20] = iStack_1c;
      pcVar1 = *(code **)(*piVar3 + 0x124);
      local_18.bottom = iStack_1c;
      guard_check_icall(local_38);
      (*pcVar1)();
      local_2c = local_18.bottom;
      local_30 = local_30 + 1;
    } while (local_30 < *(int *)(local_3c + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonRecentFilesList[95] */
/* 008b59a8  FUN_008b59a8  99 bytes, 0 callers */

void FUN_008b59a8(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x74));
  if ((BVar2 == 0) && (0 < *(int *)(in_ECX + 0x114))) {
    iVar4 = 0;
    do {
      puVar3 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar3 + 0x17c);
      guard_check_icall(param_1);
      (*pcVar1)();
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x114));
  }
  return;
}




/* vtable slots: CMFCRibbonRecentFilesList[121] */
/* 008b5a33  FUN_008b5a33  266 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008b5a33(uint param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  WCHAR local_18 [2];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x8b5a3f;
  iVar5 = 0;
  if (0 < *(int *)(in_ECX + 0x114)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar5);
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButton_00998478,
                                  (CObject *)*puVar2);
      if (pCVar3 != (CObject *)0x0) {
        CStringT<>(*(undefined4 *)(pCVar3 + 0x60));
        local_8 = 0;
        iVar4 = FUN_0044e690(0x26,0);
        if ((-1 < iVar4) && (iVar4 < *(int *)(local_14 + -0xc) + -1)) {
          local_18[0] = FUN_004473c0(iVar4 + 1);
          local_18[1] = 0;
          CharUpperW(local_18);
          if ((ushort)local_18[0] == param_1) {
            pcVar1 = *(code **)(*(int *)pCVar3 + 0xdc);
            guard_check_icall();
            iVar4 = (*pcVar1)();
            if (iVar4 == 0) {
              pcVar1 = *(code **)(*(int *)pCVar3 + 0x264);
              guard_check_icall(*(undefined4 *)(pCVar3 + 0x74),*(undefined4 *)(pCVar3 + 0x78));
              (*pcVar1)();
              FUN_00406b10();
              return 1;
            }
          }
        }
        local_8 = 0xffffffff;
        FUN_00406b10();
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(in_ECX + 0x114));
  }
  return 0;
}



