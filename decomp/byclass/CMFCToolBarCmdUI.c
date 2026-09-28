/* CMFCToolBarCmdUI -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarCmdUI[0] */
/* 007fd6e8  FUN_007fd6e8  82 bytes, 0 callers */

void FUN_007fd6e8(int param_1)

{
  CMFCToolBar *this;
  code *pcVar1;
  uint uVar2;
  int in_ECX;
  
  this = *(CMFCToolBar **)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = 1;
  if (this != (CMFCToolBar *)0x0) {
    uVar2 = CMFCToolBar::GetButtonStyle(this,*(int *)(in_ECX + 8));
    uVar2 = uVar2 & 0xfffbffff;
    if (param_1 == 0) {
      uVar2 = uVar2 | 0x40000;
    }
    pcVar1 = *(code **)(*(int *)this + 0x374);
    guard_check_icall(*(undefined4 *)(in_ECX + 8),uVar2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCToolBarCmdUI[1] */
/* 00804cf6  FUN_00804cf6  107 bytes, 0 callers */

void FUN_00804cf6(int param_1)

{
  CMFCToolBar *this;
  code *pcVar1;
  uint uVar2;
  int in_ECX;
  
  if (2 < param_1) {
    param_1 = 1;
  }
  this = *(CMFCToolBar **)(in_ECX + 0x14);
  if (this != (CMFCToolBar *)0x0) {
    uVar2 = CMFCToolBar::GetButtonStyle(this,*(int *)(in_ECX + 8));
    uVar2 = uVar2 & 0xffeeffff;
    if (param_1 == 1) {
      uVar2 = uVar2 | 0x10000;
    }
    else if (param_1 == 2) {
      uVar2 = uVar2 | 0x100000;
    }
    pcVar1 = *(code **)(*(int *)this + 0x374);
    guard_check_icall(*(undefined4 *)(in_ECX + 8),uVar2 | 2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCToolBarCmdUI[2] */
/* 008054fd  FUN_008054fd  81 bytes, 0 callers */

void FUN_008054fd(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int *in_ECX;
  
  uVar2 = (uint)(param_1 != 0);
  pcVar1 = *(code **)(*in_ECX + 4);
  guard_check_icall(uVar2);
  (*pcVar1)();
  if (in_ECX[5] != 0) {
    piVar3 = (int *)FUN_007fde79(in_ECX[2]);
    pcVar1 = *(code **)(*piVar3 + 0xc4);
    guard_check_icall(uVar2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCToolBarCmdUI[3] */
/* 008057f6  FUN_008057f6  246 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_008057f6(int param_1)

{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  CSimpleStringT<wchar_t,0> *pCVar7;
  int in_ECX;
  undefined1 local_18 [4];
  CSimpleStringT<wchar_t,0> local_14 [12];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  puVar4 = &LAB_009461a9;
  local_8 = 0x805802;
  if ((param_1 != 0) && (piVar1 = *(int **)(in_ECX + 0x14), piVar1 != (int *)0x0)) {
    if (piVar1[0x2f1] == 0) {
      iVar5 = FUN_007fde79(*(undefined4 *)(in_ECX + 8));
      puVar4 = (undefined1 *)0x0;
      if (iVar5 != 0) {
        CStringT<>(param_1);
        local_8 = 0;
        iVar6 = FUN_0044e690(9,0);
        if (iVar6 != -1) {
          pCVar7 = (CSimpleStringT<wchar_t,0> *)Left(local_18,iVar6);
          local_8._0_1_ = 1;
          ATL::CSimpleStringT<wchar_t,0>::operator=(local_14,pCVar7);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00406b10();
        }
        FUN_007dfd36(local_18,&DAT_00966468);
        local_8 = CONCAT31(local_8._1_3_,2);
        cVar3 = FUN_00414010(local_18,local_14);
        if (cVar3 == '\0') {
          ATL::CSimpleStringT<wchar_t,0>::operator=
                    ((CSimpleStringT<wchar_t,0> *)(iVar5 + 0x2c),local_14);
          pcVar2 = *(code **)(*piVar1 + 0x20c);
          guard_check_icall();
          (*pcVar2)();
        }
        FUN_00406b10();
        puVar4 = (undefined1 *)FUN_00406b10();
      }
    }
    return puVar4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



