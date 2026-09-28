/* COleDispatchImpl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDispatchImpl[1] */
/* 007a1d57  FUN_007a1d57  18 bytes, 0 callers */

void FUN_007a1d57(void)

{
  FUN_007c0c2e();
  return;
}




/* vtable slots: COleDispatchImpl[7] */
/* 007a2139  FUN_007a2139  8 bytes, 0 callers */

void FUN_007a2139(void)

{
  FUN_007c0c52();
  return;
}




/* vtable slots: COleDispatchImpl[5] */
/* 007a2286  FUN_007a2286  283 bytes, 0 callers */

int FUN_007a2286(int *param_1,undefined4 param_2,undefined4 *param_3,uint param_4,int param_5,
                int *param_6)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *local_8;
  
  iVar2 = FUN_008f1cfb(param_2,&DAT_009a9c0c,0x10);
  if (iVar2 != 0) {
    return -0x7ffdffff;
  }
  if (param_4 == 0) {
    return -0x7ff8ffa9;
  }
  local_8 = (int *)0x0;
  iVar2 = -0x7ffdfffa;
  if (param_5 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x10);
    guard_check_icall(param_1,0,param_5,&local_8);
    iVar2 = (*pcVar1)();
    if (-1 < iVar2) {
      pcVar1 = *(code **)(*local_8 + 0x28);
      guard_check_icall(local_8,param_3,param_4,param_6);
      iVar2 = (*pcVar1)();
      pcVar1 = *(code **)(*local_8 + 8);
      guard_check_icall(local_8);
      (*pcVar1)();
      if (iVar2 != -0x7ffd7fd5) {
        return iVar2;
      }
      return -0x7ffdfffa;
    }
  }
  pcVar1 = *(code **)(param_1[-4] + 0x30);
  guard_check_icall();
  uVar3 = (*pcVar1)();
  CStringT<>(*param_3);
  iVar4 = FUN_007a2aed(uVar3,param_1 + -4);
  *param_6 = iVar4;
  if (iVar4 == -1) {
    iVar2 = -0x7ffdfffa;
  }
  else if (param_4 == 1) {
    iVar2 = 0;
    goto LAB_007a2384;
  }
  if (1 < param_4) {
    while( true ) {
      param_6 = param_6 + 1;
      param_4 = param_4 - 1;
      if (param_4 == 0) break;
      *param_6 = -1;
    }
  }
LAB_007a2384:
  FUN_00406b10();
  return iVar2;
}




/* vtable slots: COleDispatchImpl[4] */
/* 007a24fe  FUN_007a24fe  98 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007a24fe(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_2 == 0) {
    pcVar1 = *(code **)(*(int *)(param_1 + -0x10) + 0x18);
    guard_check_icall(local_18);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      uVar3 = FUN_007c5e22(param_3,local_18,param_4);
      return uVar3;
    }
  }
  return 0x8002000b;
}




/* vtable slots: COleDispatchImpl[3] */
/* 007a2560  FUN_007a2560  40 bytes, 0 callers */

undefined4 FUN_007a2560(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = *(code **)(*(int *)(param_1 + -0x10) + 0x1c);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *param_2 = uVar2;
  return 0;
}




/* vtable slots: COleDispatchImpl[6] */
/* 007a2588  FUN_007a2588  1127 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

code * FUN_007a2588(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   ushort param_5,undefined4 *param_6,_union_2683 *param_7,undefined4 param_8,
                   int *param_9)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  VARIANTARG **ppVVar6;
  int *piVar7;
  _union_2683 *p_Var8;
  undefined4 local_84;
  ULONG UStack_80;
  int *local_7c;
  undefined4 uStack_78;
  _union_2683 local_74;
  VARIANTARG *local_64;
  int *piStack_60;
  int local_5c;
  int iStack_58;
  VARIANTARG *local_54;
  int *local_50;
  uint local_4c;
  int local_48;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  VARIANTARG *local_28;
  int *local_24;
  _union_2683 *local_20;
  code *local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x7a2594;
  piVar7 = param_1 + -4;
  local_38 = (uint)param_5;
  if (param_6 == (undefined4 *)0x0) {
    return (code *)-0x7ff8ffa9;
  }
  local_20 = param_7;
  local_24 = piVar7;
  if (param_7 != (_union_2683 *)0x0) {
    FUN_007c118b(param_7);
  }
  iVar2 = FUN_008f1cfb(param_3,&DAT_009a9c0c,0x10);
  if (iVar2 != 0) {
    return (code *)-0x7ffdffff;
  }
  pcVar5 = *(code **)(*piVar7 + 0x14);
  guard_check_icall(param_2);
  iVar2 = (*pcVar5)();
  if (iVar2 == 0) {
    return (code *)-0x7fff0001;
  }
  local_54 = (VARIANTARG *)*param_6;
  local_50 = (int *)param_6[1];
  local_4c = param_6[2];
  local_48 = param_6[3];
  if ((local_48 != 0) && ((local_48 != 1 || (*local_50 != -3)))) {
    return (code *)-0x7ffdfff9;
  }
  uVar3 = FUN_007a2168(piVar7,param_2);
  if (uVar3 == 0) {
    return (code *)-0x7ffdfffd;
  }
  local_2c = uVar3;
  if ((param_5 == 1) && ((*(int *)(uVar3 + 0x10) == 0 || (*(int *)(uVar3 + 0x14) != 0)))) {
    if (*(int *)(uVar3 + 8) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = _strlen(*(char **)(uVar3 + 8));
    }
    if (uVar4 < local_4c) {
      _param_5 = 8;
      local_48 = 1;
      local_34 = 8;
LAB_007a2793:
      local_20 = (_union_2683 *)0x0;
      if ((*(int *)(uVar3 + 0x10) != 0) && (*(int *)(uVar3 + 0x14) == 0)) {
        return (code *)-0x7ffdfffb;
      }
    }
    else {
      _param_5 = 2;
      local_34 = 0;
    }
  }
  else {
    local_34 = local_38 & 0xc;
    _param_5 = local_38 & 0xffff;
    if (local_34 != 0) goto LAB_007a2793;
  }
  local_30 = -1;
  local_84 = CONCAT22(local_84._2_2_,10);
  local_28 = (VARIANTARG *)0x0;
  FUN_007c118b(&local_74);
  uVar3 = local_2c;
  if (param_5 == 4) {
    if (((local_54->n1).n2.vt == 9) && (*(int *)((int)&local_54->n1 + 8) != 0)) {
      local_28 = local_54;
      local_84 = *(undefined4 *)&local_54->n1;
      UStack_80 = (local_54->n1).decVal.Hi32;
      local_7c = *(int **)((int)&local_54->n1 + 8);
      uStack_78 = *(undefined4 *)((int)&local_54->n1 + 0xc);
      FUN_007c118b(local_54);
      _memset(&local_64,0,0x10);
      pcVar5 = *(code **)(*local_7c + 0x18);
      guard_check_icall(local_7c,0,param_3,param_4,2,&local_64,local_54,param_8,param_9);
      pcVar5 = (code *)(*pcVar5)();
      pcVar1 = pcVar5;
      if (pcVar5 == (code *)0x0) {
        local_1c = (code *)0x0;
        goto LAB_007a27bc;
      }
    }
    else {
LAB_007a27bc:
      uVar3 = local_2c;
      if (*(short *)(local_2c + 0xc) != 9) goto LAB_007a28fd;
      _memset(&local_64,0,0x10);
      local_1c = *(code **)(*param_1 + 0x18);
      if (*(int *)(local_2c + 8) == 0) {
        guard_check_icall(param_1,param_2,param_3,param_4,3,&local_64,&local_74,param_8,param_9);
        local_1c = (code *)(*local_1c)();
        if (local_1c == (code *)0x0) {
          if ((local_74.n2.vt != 9) || ((int *)local_74._8_4_ == (int *)0x0)) goto LAB_007a28bf;
          pcVar5 = *(code **)(*(int *)local_74._8_4_ + 0x18);
          ppVVar6 = &local_54;
LAB_007a283a:
          local_1c = (code *)0x0;
          guard_check_icall(local_74._8_4_,0,param_3,param_4,4,ppVVar6,local_20,param_8,param_9);
          local_1c = (code *)(*pcVar5)();
        }
      }
      else {
        local_64 = local_54 + 1;
        local_5c = local_4c - 1;
        guard_check_icall(param_1,param_2,param_3,param_4,3,&local_64,&local_74,param_8,param_9);
        local_1c = (code *)(*local_1c)();
        if (local_1c == (code *)0x0) {
          if ((local_74.n2.vt == 9) && ((int *)local_74._8_4_ != (int *)0x0)) {
            local_5c = local_48;
            local_64 = local_54;
            piStack_60 = local_50;
            iStack_58 = local_48;
            pcVar5 = *(code **)(*(int *)local_74._8_4_ + 0x18);
            ppVVar6 = &local_64;
            goto LAB_007a283a;
          }
LAB_007a28bf:
          local_1c = (code *)0x80020005;
        }
      }
      pcVar1 = local_1c;
      VariantClear((VARIANTARG *)&local_74.n2);
      pcVar5 = local_1c;
    }
    local_1c = pcVar5;
    if (pcVar1 != (code *)0x80020003) goto LAB_007a2736;
    uVar3 = local_2c;
    if (local_28 != (VARIANTARG *)0x0) {
      local_28 = (VARIANTARG *)0x0;
      VariantClear(local_54);
      *(undefined4 *)&local_54->n1 = local_84;
      (local_54->n1).decVal.Hi32 = UStack_80;
      *(int **)((int)&local_54->n1 + 8) = local_7c;
      *(undefined4 *)((int)&local_54->n1 + 0xc) = uStack_78;
      uVar3 = local_2c;
    }
  }
LAB_007a28fd:
  local_2c = local_4c;
  local_1c = (code *)0x0;
  p_Var8 = local_20;
  if ((_param_5 & 3) == 0) {
LAB_007a295a:
    if ((1 < local_4c) && (((short)local_34 != 0 && (*(int *)(uVar3 + 0x10) == 0)))) {
      pcVar5 = (code *)0x8002000e;
      goto LAB_007a2736;
    }
  }
  else {
    if ((_param_5 & 1) == 0) {
      if (*(short *)(uVar3 + 0xc) == 0) {
        return (code *)-0x7ffdfff2;
      }
      if (local_20 == (_union_2683 *)0x0) {
        return (code *)-0x7ffdfff1;
      }
    }
    if ((*(int *)(uVar3 + 8) != 0) || (local_4c == 0)) goto LAB_007a295a;
    if (*(short *)(uVar3 + 0xc) != 9) {
      return (code *)-0x7ffdfff2;
    }
    local_4c = 0;
    if (local_20 == (_union_2683 *)0x0) {
      p_Var8 = &local_74;
    }
  }
  if (((*(int *)(uVar3 + 0x10) != 0) || (local_4c != 0)) || (p_Var8 != (_union_2683 *)0x0)) {
    local_8 = 0;
    local_3c = local_24[5];
    local_24[5] = (uint)(p_Var8 != (_union_2683 *)0x0);
    if (*(int *)(uVar3 + 0x10) == 0) {
      if (local_4c == 0) {
        FUN_007a2402(uVar3,p_Var8,&local_30);
      }
      else {
        local_1c = (code *)FUN_007a324c(uVar3,&local_54,&local_30);
      }
    }
    else {
      local_1c = (code *)FUN_007a1d69(uVar3,_param_5,p_Var8,&local_54,&local_30);
    }
    local_8 = 0xffffffff;
    iVar2 = FUN_007a2a12();
    return (code *)iVar2;
  }
  pcVar5 = (code *)0x8002000f;
LAB_007a2736:
  if (local_28 != (VARIANTARG *)0x0) {
    VariantClear(local_54);
    *(undefined4 *)&local_54->n1 = local_84;
    (local_54->n1).decVal.Hi32 = UStack_80;
    *(int **)((int)&local_54->n1 + 8) = local_7c;
    *(undefined4 *)((int)&local_54->n1 + 0xc) = uStack_78;
  }
  if (((pcVar5 != (code *)0x0) && (param_9 != (int *)0x0)) && (local_30 != -1)) {
    *param_9 = local_30;
  }
  return pcVar5;
}




/* vtable slots: COleDispatchImpl[0] */
/* 007a2fa7  FUN_007a2fa7  24 bytes, 0 callers */

void FUN_007a2fa7(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007c0c76(param_2,param_3);
  return;
}




/* vtable slots: COleDispatchImpl[2] */
/* 007a2fbf  FUN_007a2fbf  18 bytes, 0 callers */

void FUN_007a2fbf(void)

{
  FUN_007c0ca1();
  return;
}



