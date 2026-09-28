/* CDocManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDocManager[1] */
/* 007ca916  FUN_007ca916  48 bytes, 0 callers */

void FUN_007ca916(byte param_1)

{
  FUN_007ca885();
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




/* vtable slots: CDocManager[3] */
/* 007ca97f  FUN_007ca97f  150 bytes, 0 callers */

void FUN_007ca97f(CObject *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int *in_ECX;
  int local_8;
  
  if (param_1 == (CObject *)0x0) {
    if (DAT_00a12168 != (int *)0x0) {
      local_8 = DAT_00a12168[1];
      while (local_8 != 0) {
        puVar2 = (undefined4 *)FUN_00792938(&local_8);
        pcVar1 = *(code **)(*in_ECX + 0xc);
        guard_check_icall(*puVar2);
        (*pcVar1)();
      }
      if (DAT_00a12168 != (int *)0x0) {
        pcVar1 = *(code **)(*DAT_00a12168 + 4);
        guard_check_icall(1);
        (*pcVar1)();
      }
      DAT_00a12168 = (int *)0x0;
    }
    DAT_00a003b0 = 0;
  }
  else {
    pcVar1 = *(code **)(*(int *)param_1 + 0x50);
    guard_check_icall();
    (*pcVar1)();
    CObList::AddTail((CObList *)(in_ECX + 1),param_1);
  }
  return;
}




/* vtable slots: CDocManager[10] */
/* 007caa15  FUN_007caa15  66 bytes, 0 callers */

void FUN_007caa15(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_00792938(&local_8);
    pcVar1 = *(code **)(*(int *)*puVar2 + 0x7c);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CDocManager[12] */
/* 007cac7a  FUN_007cac7a  111 bytes, 0 callers */

int * FUN_007cac7a(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_c = *(int *)(in_ECX + 8);
  local_10 = 0;
  iVar2 = 0;
  piVar3 = (int *)0x0;
  while (local_c != 0) {
    puVar4 = (undefined4 *)FUN_00792938(&local_c);
    local_8 = (int *)*puVar4;
    pcVar1 = *(code **)(*local_8 + 0x68);
    guard_check_icall(param_1,&local_10);
    iVar5 = (*pcVar1)();
    if (iVar2 < iVar5) {
      iVar2 = iVar5;
      piVar3 = local_8;
    }
  }
  return piVar3;
}




/* vtable slots: CDocManager[4], CDockingPanesRow[22], CMFCAutoHideButton[5] */
/* 007cad56  FUN_007cad56  4 bytes, 0 callers */

undefined4 FUN_007cad56(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}




/* vtable slots: CDocManager[5] */
/* 007cad60  FUN_007cad60  12 bytes, 0 callers */

void FUN_007cad60(void)

{
  FUN_00797af6();
  return;
}




/* vtable slots: CDocManager[11] */
/* 007cad6c  FUN_007cad6c  112 bytes, 0 callers */

int FUN_007cad6c(void)

{
  int *piVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int local_c;
  int local_8;
  
  local_c = *(int *)(in_ECX + 8);
  iVar5 = 0;
  while (local_c != 0) {
    puVar3 = (undefined4 *)FUN_00792938(&local_c);
    piVar1 = (int *)*puVar3;
    pcVar2 = *(code **)(*piVar1 + 0x54);
    guard_check_icall();
    local_8 = (*pcVar2)();
    while (local_8 != 0) {
      pcVar2 = *(code **)(*piVar1 + 0x58);
      guard_check_icall(&local_8);
      iVar4 = (*pcVar2)();
      if (iVar4 != 0) {
        iVar5 = iVar5 + 1;
      }
    }
    local_8 = 0;
  }
  return iVar5;
}




/* vtable slots: CDocManager[0] */
/* 007caddc  FUN_007caddc  6 bytes, 0 callers */

undefined ** FUN_007caddc(void)

{
  return &PTR_s_CDocManager_0098564c;
}




/* vtable slots: CDocManager[8] */
/* 007cb673  FUN_007cb673  35 bytes, 0 callers */

void FUN_007cb673(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1c);
  guard_check_icall(param_1,1);
  (*pcVar1)();
  return;
}




/* vtable slots: CDocManager[7] */
/* 007cb696  FUN_007cb696  574 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_007cb696(short *param_1,undefined4 param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  errno_t eVar6;
  undefined4 *puVar7;
  int iVar8;
  HWND pHVar9;
  CWnd *pCVar10;
  int in_ECX;
  int *piVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  undefined4 uVar14;
  int local_630;
  int local_62c;
  int local_628;
  int *local_624;
  wchar_t local_620 [260];
  undefined1 local_418 [520];
  wchar_t local_210 [260];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 == (short *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar8 = *(int *)(in_ECX + 8);
  local_624 = (int *)0x0;
  piVar11 = (int *)0x0;
  local_62c = 0;
  if (*param_1 == 0x22) {
    param_1 = param_1 + 1;
  }
  local_630 = iVar8;
  uVar3 = FUN_008f8e5e(local_418,0x104,param_1,0xffffffff);
  FUN_00404bd0(uVar3);
  puVar4 = (undefined2 *)FUN_008f17a2(local_418,0x22);
  if (puVar4 != (undefined2 *)0x0) {
    *puVar4 = 0;
  }
  iVar5 = FUN_007a7361(local_210,local_418);
  if (iVar5 != 0) {
    uVar14 = 0x104;
    pwVar13 = local_620;
    pwVar12 = local_210;
    uVar3 = FUN_00404c80(pwVar12,pwVar13,0x104);
    iVar5 = FUN_007a75d1(uVar3,pwVar12,pwVar13,uVar14);
    if (iVar5 != 0) {
      eVar6 = _wcscpy_s(local_210,0x104,local_620);
      FUN_00404bd0(eVar6);
    }
    if (iVar8 != 0) {
      local_628 = in_ECX + 4;
      do {
        puVar7 = (undefined4 *)FUN_00792938(&local_630);
        piVar1 = (int *)*puVar7;
        pcVar2 = *(code **)(*piVar1 + 0x68);
        guard_check_icall(local_210,&local_624);
        iVar8 = (*pcVar2)();
        if (local_62c < iVar8) {
          piVar11 = piVar1;
          local_62c = iVar8;
        }
      } while ((iVar8 != 5) && (local_630 != 0));
    }
    if (local_624 != (int *)0x0) {
      pcVar2 = *(code **)(*local_624 + 0x68);
      guard_check_icall();
      local_628 = (*pcVar2)();
      if (local_628 == 0) {
        return local_624;
      }
      pcVar2 = *(code **)(*local_624 + 0x6c);
      guard_check_icall(&local_628);
      (*pcVar2)();
      piVar11 = (int *)FUN_0079296c();
      if (piVar11 == (int *)0x0) {
        return local_624;
      }
      pcVar2 = *(code **)(*piVar11 + 0x17c);
      guard_check_icall(0xffffffff);
      (*pcVar2)();
      pHVar9 = GetParent((HWND)piVar11[8]);
      pCVar10 = CWnd::FromHandle(pHVar9);
      if (pCVar10 == (CWnd *)0x0) {
        return local_624;
      }
      iVar8 = FUN_0079dd6d();
      piVar1 = *(int **)(*(int *)(iVar8 + 4) + 0x20);
      if (piVar11 == piVar1) {
        return local_624;
      }
      pcVar2 = *(code **)(*piVar1 + 0x17c);
      guard_check_icall(0xffffffff);
      (*pcVar2)();
      return local_624;
    }
    if (piVar11 != (int *)0x0) {
      pcVar2 = *(code **)(*piVar11 + 0x80);
      guard_check_icall(local_210,param_2,1);
      piVar11 = (int *)(*pcVar2)();
      return piVar11;
    }
    AfxMessageBox(0xf101,0,0xffffffff);
  }
  return (int *)0x0;
}




/* vtable slots: CDocManager[9] */
/* 007cbfa7  FUN_007cbfa7  72 bytes, 0 callers */

undefined4 FUN_007cbfa7(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  do {
    if (local_8 == 0) {
      return 1;
    }
    puVar2 = (undefined4 *)FUN_00792938(&local_8);
    pcVar1 = *(code **)(*(int *)*puVar2 + 0x78);
    guard_check_icall();
    iVar3 = (*pcVar1)();
  } while (iVar3 != 0);
  return 0;
}



