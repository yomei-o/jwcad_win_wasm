/* COleMessageFilter::XMessageFilter -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleMessageFilter::XMessageFilter[1] */
/* 007cc32a  FUN_007cc32a  18 bytes, 0 callers */

void FUN_007cc32a(void)

{
  FUN_007c0c2e();
  return;
}




/* vtable slots: COleMessageFilter::XMessageFilter[3] */
/* 007cc352  FUN_007cc352  94 bytes, 0 callers */

undefined4 FUN_007cc352(int param_1,int param_2)

{
  BOOL BVar1;
  DWORD idThread;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  tagMSG local_20;
  
  if (*(int *)(param_1 + -0x1c) == 0) {
    if (((param_2 == 1) || (param_2 == 4)) &&
       (BVar1 = PeekMessageW(&local_20,(HWND)0x0,0x36a,0x36a,0), BVar1 == 0)) {
      lParam = 0;
      wParam = 0;
      Msg = 0x36a;
      idThread = GetCurrentThreadId();
      PostThreadMessageW(idThread,Msg,wParam,lParam);
    }
  }
  else if ((param_2 == 1) || (param_2 == 4)) {
    return *(undefined4 *)(param_1 + -8);
  }
  return 0;
}




/* vtable slots: COleMessageFilter::XMessageFilter[5] */
/* 007cc406  FUN_007cc406  227 bytes, 0 callers */

undefined4 FUN_007cc406(int param_1,undefined4 param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 uVar4;
  int *piVar5;
  tagMSG local_24;
  
  piVar5 = (int *)(param_1 + -0x40);
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x24));
  if (*(uint *)(param_1 + -4) < param_3) {
    if (*(int *)(param_1 + -0x10) == 0) {
      pcVar1 = *(code **)(*piVar5 + 0x5c);
      guard_check_icall(&local_24);
      iVar2 = (*pcVar1)();
      if ((iVar2 != 0) && (*(int *)(param_1 + -0x14) != 0)) {
        uVar4 = 1;
        *(undefined4 *)(param_1 + -0x10) = 1;
        do {
          BVar3 = PeekMessageW(&local_24,(HWND)0x0,0x200,0x209,3);
        } while (BVar3 != 0);
        do {
          BVar3 = PeekMessageW(&local_24,(HWND)0x0,0x100,0x109,3);
        } while (BVar3 != 0);
        pcVar1 = *(code **)(*piVar5 + 100);
        guard_check_icall(param_2);
        (*pcVar1)();
        *(undefined4 *)(param_1 + -0x10) = 0;
        goto LAB_007cc4d8;
      }
      goto LAB_007cc4a3;
    }
  }
  else {
LAB_007cc4a3:
    if (*(int *)(param_1 + -0x10) == 0) {
      BVar3 = PeekMessageW(&local_24,(HWND)0x0,0,0,2);
      if (BVar3 != 0) {
        pcVar1 = *(code **)(*piVar5 + 0x58);
        guard_check_icall(&local_24);
        (*pcVar1)();
      }
      uVar4 = 1;
      goto LAB_007cc4d8;
    }
  }
  uVar4 = 2;
LAB_007cc4d8:
  guard_check_icall();
  return uVar4;
}




/* vtable slots: COleMessageFilter::XMessageFilter[0] */
/* 007cc604  FUN_007cc604  24 bytes, 0 callers */

void FUN_007cc604(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007c0c76(param_2,param_3);
  return;
}




/* vtable slots: COleMessageFilter::XMessageFilter[2] */
/* 007cc639  FUN_007cc639  18 bytes, 0 callers */

void FUN_007cc639(void)

{
  FUN_007c0ca1();
  return;
}




/* vtable slots: COleMessageFilter::XMessageFilter[4] */
/* 007cc64b  FUN_007cc64b  109 bytes, 0 callers */

undefined4 FUN_007cc64b(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x24));
  if (param_4 == 1) {
    uVar2 = 0xffffffff;
  }
  else if (*(uint *)(param_1 + -0xc) < param_3) {
    if (*(int *)(param_1 + -0x18) != 0) {
      pcVar1 = *(code **)(*(int *)(param_1 + -0x40) + 0x60);
      guard_check_icall(param_2);
      iVar3 = (*pcVar1)();
      uVar2 = 0xffffffff;
      if ((iVar3 == -1) || (uVar2 = 0, iVar3 == 2)) goto LAB_007cc6a8;
    }
    uVar2 = *(undefined4 *)(param_1 + -0xc);
  }
  else {
    uVar2 = 0;
  }
LAB_007cc6a8:
  guard_check_icall();
  return uVar2;
}



