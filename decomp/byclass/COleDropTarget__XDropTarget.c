/* COleDropTarget::XDropTarget -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDropTarget::XDropTarget[1] */
/* 0088bd59  FUN_0088bd59  18 bytes, 0 callers */

void FUN_0088bd59(void)

{
  FUN_007c0c2e();
  return;
}




/* vtable slots: COleDropTarget::XDropTarget[3] */
/* 0088bd6b  FUN_0088bd6b  252 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_0088bd6b(int param_1,int *param_2,undefined4 param_3,LONG param_4,LONG param_5,ulong *param_6)

{
  code *pcVar1;
  ulong uVar2;
  undefined4 uVar3;
  LONG LVar4;
  LONG LVar5;
  int *piVar6;
  undefined1 local_40 [16];
  tagPOINT local_30;
  undefined4 local_24;
  undefined4 local_20;
  CWnd *local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x88bd77;
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x18));
  local_20 = 0;
  local_8 = 0;
  if ((param_2 != (int *)0x0) && (param_6 != (ulong *)0x0)) {
    local_24 = 0x8000ffff;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    pcVar1 = *(code **)(*param_2 + 4);
    piVar6 = param_2;
    guard_check_icall(param_2);
    (*pcVar1)();
    FUN_007c0ecc((undefined4 *)(param_1 + -0x10));
    *(undefined4 *)(param_1 + -0x10) = param_2;
    local_1c = CWnd::FromHandle(*(HWND__ **)(param_1 + -0x14));
    local_30.x = param_4;
    local_30.y = param_5;
    ScreenToClient(*(HWND *)(local_1c + 0x20),&local_30);
    pcVar1 = *(code **)(*(int *)(param_1 + -0x34) + 0x68);
    uVar3 = param_3;
    LVar4 = local_30.x;
    LVar5 = local_30.y;
    guard_check_icall(local_1c,param_3,local_30.x,local_30.y);
    uVar2 = (*pcVar1)();
    if (-1 < (int)uVar2) {
      FUN_007b98e9();
      local_8._0_1_ = 2;
      FUN_007b98fd(param_2,0);
      pcVar1 = *(code **)(*(int *)(param_1 + -0x34) + 0x54);
      guard_check_icall(local_1c,local_40,param_3,local_30.x,local_30.y);
      uVar2 = (*pcVar1)();
      local_8._0_1_ = 3;
      FUN_007b9c1f();
    }
    uVar2 = _AfxFilterDropEffect(uVar2,*param_6);
    *param_6 = uVar2;
    uVar3 = FUN_0088be7b(uVar3,LVar4,LVar5,piVar6);
    return uVar3;
  }
  guard_check_icall();
  return 0x80070057;
}




/* vtable slots: COleDropTarget::XDropTarget[5] */
/* 0088be9d  FUN_0088be9d  127 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0088be9d(int param_1)

{
  code *pcVar1;
  CWnd *pCVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x18));
  pCVar2 = CWnd::FromHandle(*(HWND__ **)(param_1 + -0x14));
  *(undefined4 *)(param_1 + -0xc) = 0xffff;
  FUN_007b98e9();
  FUN_007b98fd(*(undefined4 *)(param_1 + -0x10),0);
  pcVar1 = *(code **)(*(int *)(param_1 + -0x34) + 100);
  guard_check_icall(pCVar2);
  (*pcVar1)();
  FUN_007c0ecc((undefined4 *)(param_1 + -0x10));
  FUN_007b9c1f();
  guard_check_icall();
  return 0;
}




/* vtable slots: COleDropTarget::XDropTarget[4] */
/* 0088bf21  FUN_0088bf21  218 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_0088bf21(int param_1,undefined4 param_2,LONG param_3,LONG param_4,ulong *param_5)

{
  code *pcVar1;
  ulong uVar2;
  undefined4 uVar3;
  LONG LVar4;
  LONG LVar5;
  undefined1 local_3c [16];
  tagPOINT local_2c;
  undefined4 local_20;
  CWnd *local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x88bf2d;
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x18));
  local_8 = 0;
  if (param_5 == (ulong *)0x0) {
    FUN_0088c00c();
    return;
  }
  local_20 = 0x8000ffff;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_1c = CWnd::FromHandle(*(HWND__ **)(param_1 + -0x14));
  local_2c.x = param_3;
  local_2c.y = param_4;
  ScreenToClient(*(HWND *)(local_1c + 0x20),&local_2c);
  pcVar1 = *(code **)(*(int *)(param_1 + -0x34) + 0x68);
  uVar3 = param_2;
  LVar4 = local_2c.x;
  LVar5 = local_2c.y;
  guard_check_icall(local_1c,param_2,local_2c.x,local_2c.y);
  uVar2 = (*pcVar1)();
  if (-1 < (int)uVar2) {
    FUN_007b98e9();
    local_8._0_1_ = 2;
    FUN_007b98fd(*(undefined4 *)(param_1 + -0x10),0);
    pcVar1 = *(code **)(*(int *)(param_1 + -0x34) + 0x58);
    guard_check_icall(local_1c,local_3c,param_2,local_2c.x,local_2c.y);
    uVar2 = (*pcVar1)();
    local_8._0_1_ = 3;
    FUN_007b9c1f();
  }
  uVar2 = _AfxFilterDropEffect(uVar2,*param_5);
  *param_5 = uVar2;
  FUN_0088c00c(uVar3,LVar4,LVar5);
  return;
}




/* vtable slots: COleDropTarget::XDropTarget[6] */
/* 0088c01e  FUN_0088c01e  329 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_0088c01e(int param_1,int param_2,undefined4 param_3,LONG param_4,LONG param_5,ulong *param_6)

{
  code *pcVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  undefined4 uVar6;
  ulong *puVar7;
  undefined1 *puVar8;
  LONG LVar9;
  LONG LVar10;
  CWnd *pCVar11;
  undefined1 local_44 [16];
  tagPOINT local_34;
  undefined4 local_28;
  ulong local_24;
  ulong local_20;
  CWnd *local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x88c02a;
  puVar7 = (ulong *)(param_1 + -0x34);
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x18));
  local_8 = 0;
  if ((param_2 != 0) && (param_6 != (ulong *)0x0)) {
    local_28 = 0x8000ffff;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    *(undefined4 *)(param_1 + -0xc) = 0xffff;
    local_1c = CWnd::FromHandle(*(HWND__ **)(param_1 + -0x14));
    FUN_007b98e9();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_007b98fd(param_2,0);
    local_34.x = param_4;
    local_34.y = param_5;
    ScreenToClient(*(HWND *)(local_1c + 0x20),&local_34);
    local_20 = *param_6;
    pcVar1 = *(code **)(*puVar7 + 0x58);
    pCVar11 = local_1c;
    guard_check_icall(local_1c,local_44,param_3,local_34.x,local_34.y);
    uVar2 = (*pcVar1)();
    uVar3 = _AfxFilterDropEffect(uVar2,local_20);
    pcVar1 = *(code **)(*puVar7 + 0x60);
    uVar2 = *param_6;
    puVar8 = local_44;
    LVar9 = local_34.x;
    LVar10 = local_34.y;
    local_24 = uVar3;
    guard_check_icall(local_1c,puVar8,uVar3,uVar2,local_34.x,local_34.y);
    uVar4 = (*pcVar1)();
    if (uVar4 == 0xffffffff) {
      local_20 = *puVar7;
      uVar4 = local_24;
      if (local_24 == 0) {
        guard_check_icall(local_1c);
        (**(code **)(local_20 + 100))();
      }
      else {
        guard_check_icall(local_1c,local_44,local_24,local_34.x,local_34.y);
        iVar5 = (**(code **)(local_20 + 0x5c))();
        if (iVar5 == 0) {
          uVar4 = 0;
        }
      }
    }
    FUN_007c0ecc(param_1 + -0x10);
    *param_6 = uVar4;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_007b9c1f();
    uVar6 = FUN_0088c178(puVar8,uVar3,uVar2,LVar9,LVar10,pCVar11);
    return uVar6;
  }
  guard_check_icall();
  return 0x80070057;
}




/* vtable slots: COleDropTarget::XDropTarget[0] */
/* 0088c543  FUN_0088c543  24 bytes, 0 callers */

void FUN_0088c543(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007c0c76(param_2,param_3);
  return;
}




/* vtable slots: COleDropTarget::XDropTarget[2] */
/* 0088c5c1  FUN_0088c5c1  18 bytes, 0 callers */

void FUN_0088c5c1(void)

{
  FUN_007c0ca1();
  return;
}



