/* CMFCTasksPaneToolBarCmdUI -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTasksPaneToolBarCmdUI[0] */
/* 008d4981  FUN_008d4981  146 bytes, 0 callers */

CMFCTasksPaneTaskGroup * FUN_008d4981(int param_1)

{
  CMFCTasksPane *this;
  int iVar1;
  CMFCTasksPaneTaskGroup *pCVar2;
  int *piVar3;
  int in_ECX;
  int local_8;
  
  this = *(CMFCTasksPane **)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = 1;
  if (this == (CMFCTasksPane *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pCVar2 = CMFCTasksPane::GetTaskGroup(this,*(int *)(in_ECX + 8));
  if ((pCVar2 != (CMFCTasksPaneTaskGroup *)0x0) && (local_8 = *(int *)(pCVar2 + 0x10), local_8 != 0)
     ) {
    pCVar2 = pCVar2 + 0xc;
    do {
      piVar3 = (int *)FUN_0044f2d0(&local_8);
      iVar1 = *piVar3;
      if ((*(int *)(iVar1 + 0x24) == *(int *)(in_ECX + 4)) && (*(int *)(iVar1 + 0x38) != param_1)) {
        *(int *)(iVar1 + 0x38) = param_1;
        InvalidateRect(*(HWND *)(this + 0x20),(RECT *)(iVar1 + 0xc),1);
        if (*(int *)(iVar1 + 0x2c) != 0) {
          CWnd::FromHandle(*(HWND__ **)(iVar1 + 0x2c));
          FUN_007979e8(param_1);
        }
      }
    } while (local_8 != 0);
  }
  return pCVar2;
}




/* vtable slots: CMFCTasksPaneToolBarCmdUI[3] */
/* 008d8114  FUN_008d8114  241 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008d8114(int param_1)

{
  CMFCTasksPane *this;
  char cVar1;
  int iVar2;
  CSimpleStringT<wchar_t,0> *pCVar3;
  CMFCTasksPaneTaskGroup *pCVar4;
  int *piVar5;
  int in_ECX;
  int local_18;
  CSimpleStringT<wchar_t,0> local_14 [12];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8d8120;
  if ((param_1 != 0) && (this = *(CMFCTasksPane **)(in_ECX + 0x14), this != (CMFCTasksPane *)0x0)) {
    CStringT<>(param_1);
    local_8 = 0;
    iVar2 = FUN_0044e690(9,0);
    if (iVar2 != -1) {
      pCVar3 = (CSimpleStringT<wchar_t,0> *)Left(&local_18,iVar2);
      local_8._0_1_ = 1;
      ATL::CSimpleStringT<wchar_t,0>::operator=(local_14,pCVar3);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00406b10();
    }
    pCVar4 = CMFCTasksPane::GetTaskGroup(this,*(int *)(in_ECX + 8));
    if (pCVar4 != (CMFCTasksPaneTaskGroup *)0x0) {
      local_18 = *(int *)(pCVar4 + 0x10);
      while (local_18 != 0) {
        piVar5 = (int *)FUN_0044f2d0(&local_18);
        iVar2 = *piVar5;
        if ((*(int *)(iVar2 + 0x24) == *(int *)(in_ECX + 4)) &&
           (cVar1 = FUN_00408c80(iVar2 + 8,local_14), cVar1 != '\0')) {
          ATL::CSimpleStringT<wchar_t,0>::operator=
                    ((CSimpleStringT<wchar_t,0> *)(iVar2 + 8),local_14);
          InvalidateRect(*(HWND *)(this + 0x20),(RECT *)(iVar2 + 0xc),1);
        }
      }
    }
    FUN_00406b10();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



