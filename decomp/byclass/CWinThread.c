/* CWinThread -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CWinThread[1] */
/* 0079d152  FUN_0079d152  48 bytes, 0 callers */

void FUN_0079d152(byte param_1)

{
  FUN_0079d0f0();
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




/* vtable slots: CWinThread[26] */
/* 0079d4ce  FUN_0079d4ce  9 bytes, 0 callers */

undefined4 FUN_0079d4ce(void)

{
  _AFX_THREAD_STATE *p_Var1;
  
  p_Var1 = AfxGetThreadState();
  return *(undefined4 *)(p_Var1 + 0x38);
}




/* vtable slots: CWinThread[0] */
/* 0079d4f2  FUN_0079d4f2  6 bytes, 0 callers */

undefined ** FUN_0079d4f2(void)

{
  return &PTR_s_CWinThread_0097dde0;
}




/* vtable slots: CWinThread[24] */
/* 0079d526  FUN_0079d526  290 bytes, 1 callers */

bool FUN_0079d526(int param_1)

{
  BOOL BVar1;
  int iVar2;
  HWND hWnd;
  int iVar3;
  int in_ECX;
  
  if (param_1 < 1) {
    iVar3 = *(int *)(in_ECX + 0x20);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != 0)) &&
       (BVar1 = IsWindowVisible(*(HWND *)(iVar3 + 0x20)), BVar1 != 0)) {
      FUN_00790b35(iVar3,*(undefined4 *)(iVar3 + 0x20),0x363,1,0);
      CWnd::SendMessageToDescendants(*(HWND__ **)(iVar3 + 0x20),0x363,1,0,1,1);
    }
    FUN_0079dd6d();
    iVar2 = FUN_007c06c0(&LAB_00799ab5);
    if (iVar2 == 0) {
LAB_0079d643:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    for (iVar2 = *(int *)(iVar2 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x98)) {
      hWnd = *(HWND *)(iVar2 + 0x20);
      if ((hWnd != (HWND)0x0) && (iVar2 != iVar3)) {
        if (*(int *)(iVar2 + 0xcc) == 0) {
          FUN_00797f20(0);
          hWnd = *(HWND *)(iVar2 + 0x20);
        }
        BVar1 = IsWindowVisible(hWnd);
        if ((BVar1 != 0) || (-1 < *(int *)(iVar2 + 0xcc))) {
          FUN_00790b35(iVar2,*(undefined4 *)(iVar2 + 0x20),0x363,1,0);
          CWnd::SendMessageToDescendants(*(HWND__ **)(iVar2 + 0x20),0x363,1,0,1,1);
        }
        if (0 < *(int *)(iVar2 + 0xcc)) {
          FUN_00797f20(*(int *)(iVar2 + 0xcc));
        }
        *(undefined4 *)(iVar2 + 0xcc) = 0xffffffff;
      }
    }
  }
  else {
    FUN_0079dd6d();
    iVar3 = FUN_007c06c0(&LAB_00799ab5);
    if (iVar3 == 0) goto LAB_0079d643;
    if (*(int *)(iVar3 + 0x10) == 0) {
      FUN_007c51ce();
      FUN_007c51d7(1);
    }
  }
  return param_1 < 1;
}




/* vtable slots: CWinThread[27] */
/* 0079d786  FUN_0079d786  9 bytes, 1 callers */

void FUN_0079d786(CException *param_1,tagMSG *param_2)

{
  AfxInternalProcessWndProcException(param_1,param_2);
  return;
}




/* vtable slots: CWinThread[21] */
/* 0079d794  FUN_0079d794  194 bytes, 1 callers */

void FUN_0079d794(void)

{
  LPMSG lpMsg;
  code *pcVar1;
  bool bVar2;
  _AFX_THREAD_STATE *p_Var3;
  BOOL BVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  int local_8;
  
  p_Var3 = AfxGetThreadState();
  bVar2 = true;
  local_8 = 0;
  lpMsg = (LPMSG)(p_Var3 + 0x30);
  do {
    if (bVar2) {
      do {
        BVar4 = PeekMessageW(lpMsg,(HWND)0x0,0,0,0);
        if (BVar4 != 0) goto LAB_0079d7ed;
        iVar6 = local_8 + 1;
        pcVar1 = *(code **)(*in_ECX + 0x60);
        guard_check_icall(local_8);
        iVar5 = (*pcVar1)();
        local_8 = iVar6;
      } while (iVar5 != 0);
      bVar2 = false;
    }
LAB_0079d7ed:
    do {
      pcVar1 = *(code **)(*in_ECX + 0x5c);
      guard_check_icall();
      iVar6 = (*pcVar1)();
      iVar5 = *in_ECX;
      if (iVar6 == 0) {
        guard_check_icall();
        (**(code **)(iVar5 + 0x68))();
        return;
      }
      guard_check_icall(lpMsg);
      iVar5 = (**(code **)(iVar5 + 100))();
      if (iVar5 != 0) {
        bVar2 = true;
        local_8 = 0;
      }
      BVar4 = PeekMessageW(lpMsg,(HWND)0x0,0,0,0);
    } while (BVar4 != 0);
  } while( true );
}



