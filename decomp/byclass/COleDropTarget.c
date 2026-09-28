/* COleDropTarget -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDropTarget[1] */
/* 0088bd29  FUN_0088bd29  48 bytes, 0 callers */

void FUN_0088bd29(byte param_1)

{
  FUN_0088bbef();
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




/* vtable slots: COleDropTarget[21] */
/* 0088c19f  FUN_0088c19f  62 bytes, 0 callers */

void FUN_0088c19f(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = FUN_0079d98a(&PTR_s_CView_0097d804);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x170);
    guard_check_icall(param_2,param_3,param_4,param_5);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: COleDropTarget[25] */
/* 0088c1dd  FUN_0088c1dd  50 bytes, 0 callers */

void FUN_0088c1dd(int *param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = FUN_0079d98a(&PTR_s_CView_0097d804);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x178);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: COleDropTarget[22] */
/* 0088c20f  FUN_0088c20f  62 bytes, 0 callers */

void FUN_0088c20f(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = FUN_0079d98a(&PTR_s_CView_0097d804);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x174);
    guard_check_icall(param_2,param_3,param_4,param_5);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: COleDropTarget[24] */
/* 0088c4fd  FUN_0088c4fd  70 bytes, 0 callers */

undefined4
FUN_0088c4fd(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0079d98a(&PTR_s_CView_0097d804);
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    pcVar1 = *(code **)(*param_1 + 0x180);
    guard_check_icall(param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar1)();
  }
  return uVar3;
}



