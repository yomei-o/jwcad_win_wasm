/* CZukeiSen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiSen[1] */
/* 006ec930  FUN_006ec930  68 bytes, 0 callers */

undefined4 FUN_006ec930(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006ec770();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x4f0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiSen[6] */
/* 006ecb90  FUN_006ecb90  2461 bytes, 2 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x006ed3e5) */

void FUN_006ecb90(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  double dVar6;
  int *piVar7;
  undefined1 local_666c [20];
  double local_6658;
  double local_6650;
  double local_6648;
  double local_6640;
  double local_6638;
  undefined4 local_6630;
  int *local_662c;
  undefined1 local_6628 [25552];
  undefined1 local_258 [16];
  undefined1 local_248 [16];
  undefined1 local_238 [16];
  undefined1 local_228 [16];
  undefined2 local_218 [258];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ed5b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(local_14);
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) != *(int *)(local_662c[1] + 0x861c)) {
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(local_662c[1] + 0x8ebc) = 0;
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(local_662c[1]);
  local_8._0_1_ = 1;
  FUN_0040c0e0();
  FUN_006eea50();
  FUN_0044dd90();
  FUN_00404c80();
  FUN_004fca20();
  iVar1 = FUN_006ed8e0();
  if (iVar1 == 0) {
    FUN_00404c80();
    FUN_004fca20();
    iVar1 = FUN_006f3450();
    if (iVar1 == 1) {
      local_662c[0x2a] = 0;
      local_662c[0x31] = 0;
      FUN_004efbb0(0x158e,0,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
  }
  local_662c[0x132] = 0;
  if (local_662c[0x2a] == 2) {
    iVar1 = local_662c[1];
    FUN_004988c0(local_228,*(undefined4 *)(iVar1 + 0x8f78),*(undefined4 *)(iVar1 + 0x8f7c),
                 *(undefined4 *)(iVar1 + 0x8f80),*(undefined4 *)(iVar1 + 0x8f84));
    if ((*(int *)(local_662c[1] + 0x1780) != 0) && (*(int *)(local_662c[1] + 0x176c) != 0)) {
      FUN_0041df00(local_662c[4],local_662c[5],local_662c[6],local_662c[7],local_662c + 8);
      iVar1 = *(int *)(local_662c[1] + 0x176c);
      FUN_004988c0(local_238,*(undefined4 *)(iVar1 + 0x40),*(undefined4 *)(iVar1 + 0x44),
                   *(undefined4 *)(iVar1 + 0x48),*(undefined4 *)(iVar1 + 0x4c));
      local_662c[0x132] = 1;
    }
    (**(code **)(*local_662c + 0x20))();
    FUN_00404c80();
    FUN_004fca20();
    iVar1 = FUN_006ed8e0();
    if (iVar1 == 0) {
      FUN_00450b70(local_666c,local_662c[1],local_662c + 0x36);
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_005beee0();
      FUN_00404c80();
      FUN_004fca20();
      fVar4 = (float10)FUN_005bee90();
      FUN_006f6140(local_6628,local_666c,(double)fVar3,(double)fVar4,0);
    }
  }
  FUN_00404c80();
  FUN_004fca20();
  iVar1 = FUN_006ed8e0();
  if (iVar1 == 0) {
    if (local_662c[0x121] == 1) {
      *(undefined2 *)(local_662c + 0xa0) = 0;
    }
    local_662c[0x121] = 0;
  }
  else {
    if (local_662c[0x121] == 0) {
      *(undefined2 *)(local_662c + 0xa0) = 0;
    }
    local_662c[0x121] = 1;
  }
  if (local_662c[0x2a] == 0) {
    *(undefined4 *)(local_662c[1] + 0x8ebc) = 1;
    FUN_00404c80();
    FUN_004fca20();
    iVar1 = FUN_006ed8e0();
    if (iVar1 == 0) {
LAB_006ed398:
      FUN_004efbb0(0x14c8,local_662c + 0xa0,0);
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_005bdbe0();
      if ((double)fVar3 <= 0.0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005bdbe0();
        local_6638 = -(double)fVar3;
      }
      else {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005bdbe0();
        local_6638 = (double)fVar3;
      }
      if (local_6638 <= 1e-07) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005bdd00();
        if ((double)fVar3 <= 0.0) {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_005bdd00();
          local_6640 = -(double)fVar3;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_005bdd00();
          local_6640 = (double)fVar3;
        }
        if (local_6640 <= 1e-07) goto LAB_006ed398;
      }
      piVar7 = local_662c + 0xa0;
      FUN_00404c80(piVar7);
      FUN_004fca20();
      fVar3 = (float10)FUN_005bdd00();
      dVar6 = (double)fVar3;
      FUN_00404c80(dVar6);
      FUN_004fca20();
      fVar3 = (float10)FUN_005bdbe0();
      FUN_006ee840((double)fVar3,dVar6,piVar7);
      FUN_004efbb0(0x153c,local_662c + 0xa0,0);
      puVar2 = (undefined4 *)FUN_004988c0(local_248,*param_1,param_1[1],param_1[2],param_1[3]);
      FUN_004988c0(local_258,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
      (**(code **)(*local_662c + 0x20))();
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_005beee0();
      FUN_00404c80();
      FUN_004fca20();
      fVar4 = (float10)FUN_005bee90();
      FUN_00404c80();
      FUN_004fca20();
      fVar5 = (float10)FUN_005bdbe0();
      if ((double)fVar5 <= 0.0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar5 = (float10)FUN_005bdbe0();
        local_6648 = -(double)fVar5;
      }
      else {
        FUN_00404c80();
        FUN_004fca20();
        fVar5 = (float10)FUN_005bdbe0();
        local_6648 = (double)fVar5;
      }
      if (1e-07 < local_6648) {
        FUN_00404c80();
        FUN_004fca20();
        fVar5 = (float10)FUN_005bdd00();
        if ((double)fVar5 <= 0.0) {
          FUN_00404c80();
          FUN_004fca20();
          fVar5 = (float10)FUN_005bdd00();
          local_6650 = -(double)fVar5;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar5 = (float10)FUN_005bdd00();
          local_6650 = (double)fVar5;
        }
        if (1e-07 < local_6650) {
          FUN_006f6140(local_6628,local_666c,(double)fVar3,(double)fVar4,0);
        }
      }
    }
  }
  if (local_662c[0x2a] == 2) {
    local_6630 = 0;
    local_218[0] = 0;
    FUN_006edd60(local_218);
    FUN_00404c80();
    FUN_004fca20();
    iVar1 = FUN_006ed8e0();
    if (iVar1 != 0) {
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_005bdbe0();
      if ((double)fVar3 <= 0.0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005bdbe0();
        local_6658 = -(double)fVar3;
      }
      else {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005bdbe0();
        local_6658 = (double)fVar3;
      }
      if (1e-07 < local_6658) {
        FUN_004efbb0(0x14e0,local_218,0);
        goto LAB_006ed4f1;
      }
    }
    FUN_004efbb0(0x14c9,local_218,1);
  }
LAB_006ed4f1:
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSen[16] */
/* 006ed530  FUN_006ed530  905 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006ed530(void)

{
  uint uVar1;
  int iVar2;
  float10 fVar3;
  undefined1 local_6420 [20];
  double local_640c;
  double local_6404;
  double local_63fc;
  double local_63f4;
  undefined4 local_63ec;
  int local_63e8;
  undefined4 local_ec;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093edab;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) != *(int *)(*(int *)(local_63e8 + 4) + 0x861c)) {
    ExceptionList = local_10;
    return 0;
  }
  *(undefined4 *)(local_63e8 + 0x488) = 0;
  *(undefined4 *)(local_63e8 + 0x48c) = 0;
  *(undefined4 *)(local_63e8 + 0x490) = 0;
  *(undefined2 *)(local_63e8 + 0x280) = 0;
  if (*(int *)(local_63e8 + 0xa8) != 0) {
    *(undefined4 *)(local_63e8 + 0xc4) = 0;
    *(int *)(*(int *)(local_63e8 + 4) + 0x8560) = *(int *)(*(int *)(local_63e8 + 4) + 0x8560) + -1;
    if (*(int *)(local_63e8 + 0xa8) == 2) {
      *(undefined4 *)(local_63e8 + 0xa8) = 0;
      *(undefined4 *)(local_63e8 + 0xac) = 0;
      *(undefined4 *)(local_63e8 + 0xb0) = 0;
    }
    FUN_00404c80(uVar1);
    FUN_0056d7d0();
    ExceptionList = local_10;
    return 1;
  }
  if (*(int *)(local_63e8 + 0xc4) == 0) {
    ExceptionList = local_10;
    return 0;
  }
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = 0;
  FUN_00446aa0();
  local_8._0_1_ = 1;
  FUN_00458a80(local_6420,*(undefined4 *)(local_63e8 + 4),0);
  FUN_00404c80();
  FUN_004fca20();
  fVar3 = (float10)FUN_005bdbe0();
  local_63f4 = (double)fVar3;
  FUN_00404c80();
  FUN_004fca20();
  fVar3 = (float10)FUN_005bdd00();
  local_63fc = (double)fVar3;
  FUN_00404c80();
  FUN_004fca20();
  iVar2 = FUN_006ed8e0();
  if (iVar2 == 1) {
    if (local_63f4 <= 0.0) {
      local_6404 = -local_63f4;
    }
    else {
      local_6404 = local_63f4;
    }
    if (1e-07 < local_6404) {
      if (local_63fc <= 0.0) {
        local_640c = -local_63fc;
      }
      else {
        local_640c = local_63fc;
      }
      if (1e-07 < local_640c) {
        *(int *)(*(int *)(local_63e8 + 4) + 0x8560) =
             *(int *)(*(int *)(local_63e8 + 4) + 0x8560) + -1;
        *(undefined4 *)(local_63e8 + 0xa8) = 0;
        goto LAB_006ed794;
      }
    }
  }
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 1;
  *(undefined4 *)(local_63e8 + 0xa8) = 2;
LAB_006ed794:
  local_ec = 0;
  *(undefined4 *)(local_63e8 + 0xc4) = 0;
  *(undefined4 *)(local_63e8 + 0xac) = *(undefined4 *)(local_63e8 + 0xb0);
  *(undefined4 *)(local_63e8 + 0xb0) = 0;
  FUN_00404c80();
  FUN_0056d7d0();
  local_63ec = 1;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiSen[0] */
/* 006ed900  FUN_006ed900  16 bytes, 0 callers */

undefined ** FUN_006ed900(void)

{
  return &PTR_s_CZukeiSen_0097a430;
}




/* vtable slots: CZukeiSen[23] */
/* 006ef0b0  FUN_006ef0b0  662 bytes, 0 callers */

undefined4 FUN_006ef0b0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  bool bVar3;
  float10 fVar4;
  undefined8 uVar5;
  double local_20;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
      FUN_00404c80();
      FUN_004fca20();
      iVar1 = FUN_006ed8e0();
      if (iVar1 == 0) {
        bVar3 = false;
        if (DAT_00a0bfb0 == 0) {
          bVar3 = DAT_00a0cc6c != 0;
        }
        else if (DAT_00a0cc6c == 0) {
          bVar3 = true;
        }
        if (bVar3) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_006ed8c0();
          FUN_00404c80();
          FUN_004fca20();
          FUN_006f06a0();
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          FUN_004fcd80();
          FUN_00404c80();
          FUN_004fca20();
          FUN_005bec00();
        }
      }
      else if (DAT_00a0cc6c == 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar4 = (float10)FUN_005bdab0();
        if ((double)fVar4 <= 0.0) {
          FUN_00404c80();
          FUN_004fca20();
          fVar4 = (float10)FUN_005bdab0();
          local_20 = -(double)fVar4;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar4 = (float10)FUN_005bdab0();
          local_20 = (double)fVar4;
        }
        if (local_20 <= 1e-07) {
          uVar5 = 0x4056800000000000;
          FUN_00404c80(0x4056800000000000);
          FUN_004fca20();
          FUN_005be990(uVar5);
        }
        else {
          uVar5 = 0;
          FUN_00404c80(0);
          FUN_004fca20();
          FUN_005be990(uVar5);
        }
      }
      else {
        FUN_00404c80();
        FUN_004fca20();
        FUN_004fcd80();
        FUN_00404c80();
        FUN_004fca20();
        FUN_005bec00();
      }
      FUN_00404c80();
      FUN_004fca20();
      FUN_007955d2();
      FUN_00404c80();
      FUN_0056d7d0();
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiSen[46] */
/* 006ef350  FUN_006ef350  3135 bytes, 0 callers */

undefined4
FUN_006ef350(undefined4 param_1,int param_2,wchar_t *param_3,wchar_t *param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  double *pdVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  wchar_t *local_b8;
  undefined8 local_b4;
  undefined8 local_ac;
  uint uStack_a4;
  undefined1 *local_a0;
  undefined1 *local_9c;
  undefined1 *local_98;
  double local_94;
  double local_8c;
  double local_84;
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  undefined1 local_40 [4];
  int local_3c;
  double local_38;
  double local_30;
  undefined1 local_28 [4];
  undefined4 local_24;
  int local_20;
  int local_1c;
  wchar_t *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ee9d;
  local_10 = ExceptionList;
  uStack_a4 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_ac = (double)CONCAT44(0x6ef380,(undefined4)local_ac);
  FUN_00404c80();
  local_ac = (double)CONCAT44(0x6ef387,(undefined4)local_ac);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) != *(int *)(*(int *)(local_14 + 4) + 0x861c)) {
    ExceptionList = local_10;
    return 0;
  }
  if (DAT_00a0c7c0 != 0) {
    local_b4 = (double)CONCAT44(param_5,param_4);
    local_ac = (double)CONCAT44(param_7,param_6);
    local_b8 = param_3;
    uVar3 = FUN_0076c9c0(param_1,param_2);
    ExceptionList = local_10;
    return uVar3;
  }
  local_24 = 0;
  local_18 = (wchar_t *)0x0;
  if (*(int *)(*(int *)(local_14 + 4) + 0x9078) == 0) {
    local_54 = 0xffffffff;
    local_44 = 2;
    local_ac = (double)CONCAT44(0x6ef414,(undefined4)local_ac);
    FUN_00404c80();
    local_ac = (double)CONCAT44(0x6ef41b,(undefined4)local_ac);
    FUN_004fca20();
    local_ac = (double)CONCAT44(0x6ef426,(undefined4)local_ac);
    iVar2 = FUN_006ed8e0();
    if (iVar2 != 0) {
      local_44 = 3;
    }
    local_b8 = param_4;
    local_b4 = (double)CONCAT44(param_6,param_5);
    local_ac = (double)CONCAT44(local_44,param_7);
    iVar2 = FUN_00778a40(1,&local_54,*(undefined4 *)(*(int *)(local_14 + 4) + 0x9070),param_1,
                         param_2,param_3);
    if (iVar2 != 0) {
      ExceptionList = local_10;
      return 0;
    }
    if ((param_2 == 0xc) && (*(int *)(local_14 + 0xa8) != 0)) {
      if (param_3 == (wchar_t *)0x1) {
        local_ac = 4.94065645841247e-324;
        local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
        local_b8 = (wchar_t *)0x2733;
        FUN_005168b0();
        ExceptionList = local_10;
        return local_24;
      }
      if (param_3 != (wchar_t *)0x2) {
        ExceptionList = local_10;
        return local_24;
      }
      local_ac = (double)CONCAT44(0x6ef4d6,(undefined4)local_ac);
      FUN_005156d0();
      ExceptionList = local_10;
      return local_24;
    }
    local_ac = (double)CONCAT44(0x6ef4e3,(undefined4)local_ac);
    FUN_00404c80();
    local_ac = (double)CONCAT44(0x6ef4ea,(undefined4)local_ac);
    FUN_004fca20();
    local_ac = (double)CONCAT44(0x6ef4f5,(undefined4)local_ac);
    iVar2 = FUN_006ed8e0();
    if ((iVar2 == 0) && (*(int *)(local_14 + 0xa8) != 0)) {
      if (param_2 == 2) {
        local_ac = (double)CONCAT44(0x6ef51c,(undefined4)local_ac);
        FUN_00404c80();
        local_ac = (double)CONCAT44(0x6ef523,(undefined4)local_ac);
        FUN_004fca20();
        local_ac = (double)CONCAT44(0x6ef52e,(undefined4)local_ac);
        iVar2 = FUN_006f3430();
        if (iVar2 == 0) {
          local_ac = (double)CONCAT44(0x6ef53b,(undefined4)local_ac);
          FUN_00404c80();
          local_ac = (double)CONCAT44(0x6ef542,(undefined4)local_ac);
          FUN_004fca20();
          local_ac = (double)CONCAT44(0x6ef54d,(undefined4)local_ac);
          iVar2 = FUN_006f3470();
          if (iVar2 == 0) {
            local_ac = (double)CONCAT44(0x6ef55a,(undefined4)local_ac);
            FUN_00404c80();
            local_ac = (double)CONCAT44(0x6ef561,(undefined4)local_ac);
            iVar2 = FUN_004fca20();
            local_1c = *(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc);
            if ((*(int *)(local_14 + 0x488) != 0) && (local_1c = local_1c + 1, 3 < local_1c)) {
              local_1c = 1;
            }
            local_18 = (wchar_t *)0x182d;
            if (local_1c == 2) {
              local_18 = (wchar_t *)0x182e;
            }
            if (local_1c == 3) {
              local_18 = (wchar_t *)0x182f;
            }
            if (param_3 == (wchar_t *)0x1) {
              local_ac = 4.94065645841247e-324;
              local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
              local_b8 = local_18;
              FUN_005168b0();
              ExceptionList = local_10;
              return local_24;
            }
            if (param_3 != (wchar_t *)0x2) {
              ExceptionList = local_10;
              return local_24;
            }
            if (*(int *)(local_14 + 0x488) != 0) {
              local_ac = (double)CONCAT44(0x6ef5fc,(undefined4)local_ac);
              FUN_00404c80();
              local_ac = (double)CONCAT44(0x6ef603,(undefined4)local_ac);
              iVar2 = FUN_004fca20();
              *(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) = local_1c;
              local_ac = (double)CONCAT44(0x6ef617,(undefined4)local_ac);
              FUN_00404c80();
              local_ac = (double)CONCAT44(0x6ef61e,(undefined4)local_ac);
              FUN_004fca20();
              local_ac = (double)CONCAT44(0x6ef629,(undefined4)local_ac);
              FUN_005bec50();
            }
            *(undefined4 *)(local_14 + 0x488) = 1;
            *(undefined4 *)(local_14 + 0x48c) = 0;
            local_ac = 0.0;
            local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f24);
            local_b8 = local_18;
            FUN_005168b0();
            ExceptionList = local_10;
            return local_24;
          }
        }
      }
      if (param_2 == 3) {
        local_ac = (double)CONCAT44(0x6ef681,(undefined4)local_ac);
        FUN_00404c80();
        local_ac = (double)CONCAT44(0x6ef688,(undefined4)local_ac);
        FUN_004fca20();
        local_ac = (double)CONCAT44(0x6ef693,(undefined4)local_ac);
        iVar2 = FUN_006f3430();
        if (iVar2 == 0) {
          local_ac = (double)CONCAT44(0x6ef6a0,(undefined4)local_ac);
          FUN_00404c80();
          local_ac = (double)CONCAT44(0x6ef6a7,(undefined4)local_ac);
          FUN_004fca20();
          local_ac = (double)CONCAT44(0x6ef6b2,(undefined4)local_ac);
          iVar2 = FUN_006f3470();
          if (iVar2 == 0) {
            local_ac = (double)CONCAT44(0x6ef6bf,(undefined4)local_ac);
            FUN_00404c80();
            local_ac = (double)CONCAT44(0x6ef6c6,(undefined4)local_ac);
            iVar2 = FUN_004fca20();
            local_20 = *(int *)(*(int *)(iVar2 + 0x1a0) + 0xc0);
            if ((*(int *)(local_14 + 0x48c) != 0) && (local_20 = local_20 + 1, 3 < local_20)) {
              local_20 = 1;
            }
            local_18 = (wchar_t *)0x1830;
            if (local_20 == 2) {
              local_18 = (wchar_t *)0x1831;
            }
            if (local_20 == 3) {
              local_18 = (wchar_t *)0x1832;
            }
            if (param_3 == (wchar_t *)0x1) {
              local_ac = 4.94065645841247e-324;
              local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
              local_b8 = local_18;
              FUN_005168b0();
              ExceptionList = local_10;
              return local_24;
            }
            if (param_3 != (wchar_t *)0x2) {
              ExceptionList = local_10;
              return local_24;
            }
            if (*(int *)(local_14 + 0x48c) != 0) {
              local_ac = (double)CONCAT44(0x6ef761,(undefined4)local_ac);
              FUN_00404c80();
              local_ac = (double)CONCAT44(0x6ef768,(undefined4)local_ac);
              iVar2 = FUN_004fca20();
              *(int *)(*(int *)(iVar2 + 0x1a0) + 0xc0) = local_20;
              local_ac = (double)CONCAT44(0x6ef77c,(undefined4)local_ac);
              FUN_00404c80();
              local_ac = (double)CONCAT44(0x6ef783,(undefined4)local_ac);
              FUN_004fca20();
              local_ac = (double)CONCAT44(0x6ef78e,(undefined4)local_ac);
              FUN_005bec50();
            }
            *(undefined4 *)(local_14 + 0x488) = 0;
            *(undefined4 *)(local_14 + 0x48c) = 1;
            local_ac = 0.0;
            local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f24);
            local_b8 = local_18;
            FUN_005168b0();
            ExceptionList = local_10;
            return local_24;
          }
        }
      }
      if (param_2 == 4) {
        local_ac = (double)CONCAT44(0x6ef7e6,(undefined4)local_ac);
        FUN_00404c80();
        local_ac = (double)CONCAT44(0x6ef7ed,(undefined4)local_ac);
        FUN_004fca20();
        local_ac = (double)CONCAT44(0x6ef7f8,(undefined4)local_ac);
        iVar2 = FUN_006f3410();
        if (iVar2 == 0) {
          local_ac = 7.61422882809419e-306;
          CStringT<>();
          local_8 = 0;
          if (*(int *)(local_14 + 0x490) == 1) {
            if (-1 < DAT_00a0bcd0) {
              local_ac = 1.33897970340843e-310;
              local_5c = FUN_005977f0();
              local_8._0_1_ = 1;
              local_ac = (double)CONCAT44(local_5c,0x6ef84f);
              local_58 = local_5c;
              FUN_00404950();
              local_8 = (uint)local_8._1_3_ << 8;
              local_ac = (double)CONCAT44(0x6ef85b,(undefined4)local_ac);
              FUN_00404770();
            }
          }
          else if (DAT_00a0bcd0 < 0) {
            local_ac = 1.33897970341144e-310;
            local_68 = FUN_005977f0();
            local_8._0_1_ = 2;
            local_ac = (double)CONCAT44(local_68,0x6ef88c);
            local_64 = local_68;
            FUN_00404950();
            local_8 = (uint)local_8._1_3_ << 8;
            local_ac = (double)CONCAT44(0x6ef898,(undefined4)local_ac);
            FUN_00404770();
          }
          local_ac = 1.18916680057176e-310;
          local_74 = FUN_005977f0();
          local_8._0_1_ = 3;
          local_ac = (double)CONCAT44(local_74,0x6ef8be);
          local_70 = local_74;
          FUN_00404950();
          local_8 = (uint)local_8._1_3_ << 8;
          local_ac = (double)CONCAT44(0x6ef8ca,(undefined4)local_ac);
          FUN_00404770();
          if (param_3 == (wchar_t *)0x1) {
            local_ac = 4.94065645841247e-324;
            local_b8 = *(wchar_t **)(*(int *)(local_14 + 4) + 0x8f54);
            local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
            local_98 = (undefined1 *)&local_b8;
            FUN_00403dd0(local_28);
            FUN_00516ac0();
          }
          else if (param_3 == (wchar_t *)0x2) {
            if (*(int *)(local_14 + 0x490) == 1) {
              *(undefined4 *)(local_14 + 0x490) = 2;
            }
            else {
              *(undefined4 *)(local_14 + 0x490) = 1;
            }
            local_ac = 0.0;
            local_b8 = *(wchar_t **)(*(int *)(local_14 + 4) + 0x8f28);
            local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f24);
            local_9c = (undefined1 *)&local_b8;
            FUN_00403dd0(local_28);
            FUN_00516ac0();
          }
          local_7c = local_24;
          local_8 = 0xffffffff;
          local_ac = (double)CONCAT44(0x6ef97f,(undefined4)local_ac);
          FUN_00404540();
          ExceptionList = local_10;
          return local_7c;
        }
      }
    }
    local_b4 = (double)CONCAT44(param_5,param_4);
    local_ac = (double)CONCAT44(param_7,param_6);
    local_b8 = param_3;
    uVar3 = FUN_0076c9c0(param_1,param_2);
    ExceptionList = local_10;
    return uVar3;
  }
  local_3c = param_2 + -1;
  switch(param_2) {
  case 1:
    if (param_3 == (wchar_t *)0x1) {
      local_ac = (double)CONCAT44(0x6efa7e,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efa85,(undefined4)local_ac);
      FUN_004fca20();
      local_ac = (double)CONCAT44(0x6efa90,(undefined4)local_ac);
      iVar2 = FUN_006ed8e0();
      if (iVar2 == 0) {
        local_18 = (wchar_t *)0x17d6;
      }
      else {
        local_18 = (wchar_t *)0x141e;
      }
      local_ac = 4.94065645841247e-324;
      local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
      local_b8 = local_18;
      FUN_005168b0();
    }
    else if (param_3 == (wchar_t *)0x2) {
      local_ac = (double)CONCAT44(0x6efad8,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efadf,(undefined4)local_ac);
      FUN_004fca20();
      local_ac = (double)CONCAT44(0x6efaea,(undefined4)local_ac);
      iVar2 = FUN_006ed8e0();
      local_48 = (uint)(iVar2 == 0);
      local_ac._4_4_ = local_48;
      local_ac._0_4_ = 0x6efb07;
      FUN_00404c80();
      local_ac._0_4_ = 0x6efb0e;
      FUN_004fca20();
      local_ac = (double)CONCAT44(local_ac._4_4_,0x6efb19);
      FUN_005176a0();
      local_ac._4_4_ = 0;
      local_ac._0_4_ = 0x6efb20;
      FUN_00404c80();
      local_ac._0_4_ = 0x6efb27;
      FUN_004fca20();
      local_ac._0_4_ = 0x6efb32;
      FUN_007955d2();
      local_ac._0_4_ = 0x6efb37;
      FUN_00404c80();
      local_ac._0_4_ = 0x6efb3e;
      FUN_004fca20();
      local_ac = (double)CONCAT44(local_ac._4_4_,0x6efb49);
      FUN_005bd4a0();
    }
    break;
  case 2:
    local_ac = (double)CONCAT44(0x6efb53,(undefined4)local_ac);
    FUN_00404c80();
    local_ac = (double)CONCAT44(0x6efb5a,(undefined4)local_ac);
    FUN_004fca20();
    local_ac = (double)CONCAT44(0x6efb65,(undefined4)local_ac);
    iVar2 = FUN_006ed8e0();
    if (iVar2 == 0) {
      if (param_3 == (wchar_t *)0x1) {
        local_ac = 4.94065645841247e-324;
        local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
        local_b8 = (wchar_t *)0x1802;
        FUN_005168b0();
        ExceptionList = local_10;
        return local_24;
      }
      if (param_3 != (wchar_t *)0x2) {
        ExceptionList = local_10;
        return local_24;
      }
      local_ac = (double)CONCAT44(0x6efe52,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efe59,(undefined4)local_ac);
      FUN_004fca20();
      local_ac = (double)CONCAT44(0x6efe64,(undefined4)local_ac);
      iVar2 = FUN_006ed8c0();
      local_4c = (uint)(iVar2 == 0);
      local_ac._4_4_ = local_4c;
      local_ac._0_4_ = 0x6efe81;
      FUN_00404c80();
      local_ac._0_4_ = 0x6efe88;
      FUN_004fca20();
      local_ac = (double)CONCAT44(local_ac._4_4_,0x6efe93);
      FUN_006f06a0();
      local_ac._4_4_ = 0;
      local_ac._0_4_ = 0x6efe9a;
      FUN_00404c80();
      local_ac._0_4_ = 0x6efea1;
      FUN_004fca20();
      local_ac = (double)CONCAT44(local_ac._4_4_,0x6efeac);
      FUN_007955d2();
      ExceptionList = local_10;
      return local_24;
    }
    local_ac = (double)CONCAT44(0x6efb72,(undefined4)local_ac);
    FUN_00404c80();
    local_ac = (double)CONCAT44(0x6efb79,(undefined4)local_ac);
    FUN_004fca20();
    local_ac = (double)CONCAT44(0x6efb84,(undefined4)local_ac);
    fVar4 = (float10)FUN_005bdbe0();
    local_30 = (double)fVar4;
    local_ac = (double)CONCAT44(0x6efb8c,(undefined4)local_ac);
    FUN_00404c80();
    local_ac = (double)CONCAT44(0x6efb93,(undefined4)local_ac);
    FUN_004fca20();
    local_ac = (double)CONCAT44(0x6efb9e,(undefined4)local_ac);
    fVar4 = (float10)FUN_005bdd00();
    local_38 = (double)fVar4;
    if (local_30 <= 0.0) {
      local_8c = -local_30;
    }
    else {
      local_8c = local_30;
    }
    if (1e-07 < local_8c) {
LAB_006efc29:
      local_38 = 0.0;
      local_30 = 0.0;
    }
    else {
      local_94 = local_38;
      if (local_38 <= 0.0) {
        local_94 = -local_38;
      }
      if (1e-07 < local_94) goto LAB_006efc29;
      local_ac = (double)CONCAT44(0x6efc45,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efc4c,(undefined4)local_ac);
      iVar2 = FUN_004fca20();
      pdVar1 = (double *)(*(int *)(iVar2 + 0x1a0) + 0x708);
      if (9e+40 < *pdVar1 || *pdVar1 == 9e+40) {
        local_38 = *(double *)
                    (*(int *)(local_14 + 4) + 0x2578 + *(int *)(*(int *)(local_14 + 4) + 0x256c) * 8
                    ) * 10.0;
        local_30 = local_38;
      }
      else {
        local_ac = (double)CONCAT44(0x6efc69,(undefined4)local_ac);
        FUN_00404c80();
        local_ac = (double)CONCAT44(0x6efc70,(undefined4)local_ac);
        iVar2 = FUN_004fca20();
        local_30 = *(double *)(*(int *)(iVar2 + 0x1a0) + 0x708);
        local_ac = (double)CONCAT44(0x6efc88,(undefined4)local_ac);
        FUN_00404c80();
        local_ac = (double)CONCAT44(0x6efc8f,(undefined4)local_ac);
        iVar2 = FUN_004fca20();
        local_38 = *(double *)(*(int *)(iVar2 + 0x1a0) + 0x710);
      }
    }
    if (param_3 == (wchar_t *)0x1) {
      if (DAT_00a0d62c != 0) {
        local_30 = local_30 / DAT_00a0d630;
        local_38 = local_38 / DAT_00a0d630;
      }
      local_ac = (double)CONCAT44(0x6efd15,(undefined4)local_ac);
      CStringT<>();
      local_8 = 4;
      local_ac = local_38;
      local_b4 = local_30;
      local_b8 = L"%lg , %lg";
      FUN_004059f0(local_40);
      local_ac = 4.94065645841247e-324;
      local_b8 = *(wchar_t **)(*(int *)(local_14 + 4) + 0x8f54);
      local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
      local_a0 = (undefined1 *)&local_b8;
      FUN_00403dd0(local_40);
      FUN_00516ac0();
      local_8 = 0xffffffff;
      local_ac = (double)CONCAT44(0x6efd8b,(undefined4)local_ac);
      FUN_00404540();
    }
    else if (param_3 == (wchar_t *)0x2) {
      local_ac = local_38;
      local_b4 = local_30;
      local_b8 = L"좋擨\xe0cc诿ꂈ\x01\xe800\xeda9￬듨텎诿\xe8c8챍￠袋Ơ";
      FUN_00404c80();
      local_b8 = L"袋Ơ";
      FUN_004fca20();
      local_b8 = L"듨텎诿\xe8c8챍￠袋Ơ";
      FUN_005beb70();
      local_ac = (double)CONCAT44(0x6efdcc,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efdd3,(undefined4)local_ac);
      FUN_004fca20();
      local_ac = (double)CONCAT44(0x6efdde,(undefined4)local_ac);
      fVar4 = (float10)FUN_005bdbe0();
      local_30 = (double)fVar4;
      local_ac = (double)CONCAT44(0x6efde6,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efded,(undefined4)local_ac);
      FUN_004fca20();
      local_ac = (double)CONCAT44(0x6efdf8,(undefined4)local_ac);
      fVar4 = (float10)FUN_005bdd00();
      local_38 = (double)fVar4;
      local_ac = (double)CONCAT44(0x6efe00,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efe07,(undefined4)local_ac);
      FUN_004fca20();
      local_ac = (double)CONCAT44(0x6efe12,(undefined4)local_ac);
      FUN_006f14f0();
    }
    break;
  case 3:
    if (param_3 == (wchar_t *)0x1) {
      local_ac = 4.94065645841247e-324;
      local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
      local_b8 = (wchar_t *)0x17d5;
      FUN_005168b0();
    }
    else if (param_3 == (wchar_t *)0x2) {
      local_ac = (double)CONCAT44(0x6efeec,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efef3,(undefined4)local_ac);
      FUN_004fca20();
      local_ac = (double)CONCAT44(0x6efefe,(undefined4)local_ac);
      iVar2 = FUN_004fcd80();
      local_50 = (uint)(iVar2 == 0);
      local_ac._4_4_ = local_50;
      local_ac._0_4_ = 0x6eff1b;
      FUN_00404c80();
      local_ac._0_4_ = 0x6eff22;
      FUN_004fca20();
      local_ac = (double)CONCAT44(local_ac._4_4_,0x6eff2d);
      FUN_005bec00();
      local_ac._4_4_ = 0;
      local_ac._0_4_ = 0x6eff34;
      FUN_00404c80();
      local_ac._0_4_ = 0x6eff3b;
      FUN_004fca20();
      local_ac = (double)CONCAT44(local_ac._4_4_,0x6eff46);
      FUN_007955d2();
    }
    break;
  default:
    local_b4 = (double)CONCAT44(param_5,param_4);
    local_ac = (double)CONCAT44(param_7,param_6);
    local_b8 = param_3;
    local_24 = FUN_0076c9c0(param_1,param_2);
    break;
  case 0xc:
    if (param_3 == (wchar_t *)0x1) {
      local_ac = 4.94065645841247e-324;
      local_b4 = *(double *)(*(int *)(local_14 + 4) + 0x8f50);
      local_b8 = (wchar_t *)0x1810;
      FUN_005168b0();
    }
    else if (param_3 == (wchar_t *)0x2) {
      local_ac = (double)CONCAT44(0x6efa24,(undefined4)local_ac);
      FUN_00404c80();
      local_ac = (double)CONCAT44(0x6efa2b,(undefined4)local_ac);
      FUN_004fca20();
      local_ac = (double)CONCAT44(0x6efa36,(undefined4)local_ac);
      fVar4 = (float10)FUN_005bdab0();
      local_ac = -(double)fVar4;
      local_b4 = (double)CONCAT44(0x6efa5c,(undefined4)local_b4);
      local_84 = local_ac;
      FUN_00404c80();
      local_b4 = (double)CONCAT44(0x6efa63,(undefined4)local_b4);
      FUN_004fca20();
      local_b4 = (double)CONCAT44(0x6efa6e,(undefined4)local_b4);
      FUN_005be990();
    }
  }
  ExceptionList = local_10;
  return local_24;
}




/* vtable slots: CZukeiSen[47] */
/* 006effb0  FUN_006effb0  731 bytes, 0 callers */

undefined4
FUN_006effb0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_8 + 4) + 0x861c)) {
    if (DAT_00a0c7c0 == 0) {
      local_10 = 0;
      if (*(int *)(*(int *)(local_8 + 4) + 0x907c) == 0) {
        local_18 = 0xffffffff;
        local_14 = 2;
        FUN_00404c80();
        FUN_004fca20();
        iVar1 = FUN_006ed8e0();
        if (iVar1 != 0) {
          local_14 = 3;
        }
        iVar1 = FUN_00778a40(2,&local_18,*(undefined4 *)(*(int *)(local_8 + 4) + 0x9074),param_1,
                             param_2,param_3,param_4,param_5,param_6,param_7,local_14);
        if (iVar1 == 0) {
          local_c = 0;
          if (param_2 == 0xc) {
            FUN_00404c80();
            FUN_004fca20();
            iVar1 = FUN_006ed8e0();
            if (iVar1 == 0) {
              if (*(int *)(local_8 + 0xa8) == 0) {
                FUN_00404c80();
                FUN_004fca20();
                iVar1 = FUN_004fcd80();
                if (iVar1 == 1) {
                  local_c = 1;
                }
                else {
                  local_c = 2;
                }
              }
              else {
                FUN_00404c80();
                FUN_004fca20();
                iVar1 = FUN_004fcd80();
                if (iVar1 == 1) {
                  if (*(int *)(local_8 + 0xac) == 0) {
                    local_c = 5;
                  }
                  else {
                    local_c = 0;
                  }
                }
                else if ((*(int *)(local_8 + 0xac) == 0) || (*(int *)(local_8 + 0xbc) == 0)) {
                  local_c = 6;
                }
                else {
                  local_c = 0xc;
                  iVar1 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
                  if (iVar1 != 0) {
                    local_c = 0xe;
                  }
                }
              }
            }
            if (local_c == 0) {
              uVar2 = FUN_0076efd0(param_1,param_3,param_4,param_5,param_6,param_7);
            }
            else {
              uVar2 = FUN_006f3490(local_c,param_1,param_3,param_4,param_5,param_6,param_7);
            }
          }
          else {
            uVar2 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      uVar2 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiSen[25] */
/* 006f0290  FUN_006f0290  61 bytes, 0 callers */

void FUN_006f0290(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x488) = 0;
  *(undefined4 *)(in_ECX + 0x48c) = 0;
  *(undefined4 *)(in_ECX + 0x490) = 0;
  FUN_004fb9f0();
  return;
}




/* vtable slots: CZukeiSen[26], CZukeiSen[27] */
/* 006f02d0  FUN_006f02d0  48 bytes, 0 callers */

void FUN_006f02d0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x488) = 0;
  *(undefined4 *)(in_ECX + 0x48c) = 0;
  FUN_004fb9f0();
  return;
}




/* vtable slots: CZukeiSen[28] */
/* 006f0300  FUN_006f0300  35 bytes, 0 callers */

void FUN_006f0300(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x490) = 0;
  FUN_004fb9f0();
  return;
}




/* vtable slots: CZukeiSen[49] */
/* 006f0330  FUN_006f0330  83 bytes, 1 callers */

void FUN_006f0330(undefined8 param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_005be990(param_1);
  }
  return;
}




/* vtable slots: CZukeiSen[50] */
/* 006f0390  FUN_006f0390  181 bytes, 1 callers */

void FUN_006f0390(double param_1)

{
  int iVar1;
  int in_ECX;
  double dVar2;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if ((*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) && (1e-07 <= param_1)) {
    FUN_00404c80();
    FUN_004fca20();
    iVar1 = FUN_006ed8e0();
    if (iVar1 == 0) {
      FUN_00404c80(param_1);
      FUN_004fca20();
      FUN_005be9e0(param_1);
    }
    else {
      dVar2 = param_1;
      FUN_00404c80(param_1,param_1);
      FUN_004fca20();
      FUN_005beb70(param_1,dVar2);
    }
  }
  return;
}




/* vtable slots: CZukeiSen[51] */
/* 006f0450  FUN_006f0450  193 bytes, 0 callers */

void FUN_006f0450(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    FUN_006f0330(param_1);
    FUN_006f0390(param_2);
    FUN_00404c80();
    FUN_004fca20();
    FUN_007955d2();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  else {
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSen[15] */
/* 006f0520  FUN_006f0520  369 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006f0520(void)

{
  int iVar1;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093365b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(local_14);
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x861c)) {
    *(undefined2 *)(local_63e8 + 0x280) = 0;
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
    FUN_0044de00(local_6400,*(undefined4 *)(local_63e8 + 4));
    FUN_00453bd0(local_6400,*(undefined4 *)(local_63e8 + 4),0);
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    *(undefined4 *)(local_63e8 + 0xc4) = 0;
    FUN_00404c80();
    FUN_0056d7d0();
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_63ec = 0;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiSen[12] */
/* 006f06c0  FUN_006f06c0  310 bytes, 0 callers */

undefined4
FUN_006f06c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  double local_10;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    if (*(int *)(in_ECX + 0xa8) == 2) {
      FUN_00404c80();
      FUN_004fca20();
      iVar1 = FUN_006ed8e0();
      if (iVar1 != 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005bdbe0();
        if ((double)fVar3 <= 0.0) {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_005bdbe0();
          local_10 = -(double)fVar3;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_005bdbe0();
          local_10 = (double)fVar3;
        }
        if (1e-07 < local_10) {
          uVar2 = FUN_006f0be0(param_1,param_2,param_3,param_4,param_5);
          return uVar2;
        }
      }
    }
    uVar2 = FUN_006f0be0(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiSen[10] */
/* 006f0800  FUN_006f0800  977 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006f0800(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int local_645c;
  undefined1 local_84 [16];
  undefined1 local_74 [16];
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093eedb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    FUN_00404c80(uVar1);
    FUN_004fca20();
    FUN_005bd4a0();
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8._0_1_ = 1;
    iVar2 = *(int *)(in_ECX + 4);
    local_24 = *(undefined4 *)(iVar2 + 0x8f68);
    local_20 = *(undefined4 *)(iVar2 + 0x8f6c);
    local_1c = *(undefined4 *)(iVar2 + 0x8f70);
    local_18 = *(undefined4 *)(iVar2 + 0x8f74);
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9068) != 0) {
      local_645c = 0;
      iVar2 = FUN_0079d98a(&PTR_s_CZukeiSen_0097a430);
      if (iVar2 != 0) {
        local_645c = *(int *)(param_1 + 0xa8);
      }
      iVar2 = FUN_0079d98a(&PTR_s_CZukeiEnko_009780a0);
      if (iVar2 != 0) {
        local_645c = *(int *)(param_1 + 0x308);
      }
      if (local_645c != 0) {
        *(undefined4 *)(in_ECX + 0xa8) = 2;
        FUN_004988c0(local_34,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                     *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
        iVar2 = *(int *)(in_ECX + 4);
        FUN_004988c0(local_44,*(undefined4 *)(iVar2 + 0x8f88),*(undefined4 *)(iVar2 + 0x8f8c),
                     *(undefined4 *)(iVar2 + 0x8f90),*(undefined4 *)(iVar2 + 0x8f94));
        FUN_006ecb90(in_ECX + 0x20);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      *(undefined4 *)(in_ECX + 0xa8) = 2;
      iVar2 = *(int *)(in_ECX + 4);
      FUN_004988c0(local_54,*(undefined4 *)(iVar2 + 0x8f68),*(undefined4 *)(iVar2 + 0x8f6c),
                   *(undefined4 *)(iVar2 + 0x8f70),*(undefined4 *)(iVar2 + 0x8f74));
      iVar2 = *(int *)(in_ECX + 4);
      FUN_004988c0(local_64,*(undefined4 *)(iVar2 + 0x8f88),*(undefined4 *)(iVar2 + 0x8f8c),
                   *(undefined4 *)(iVar2 + 0x8f90),*(undefined4 *)(iVar2 + 0x8f94));
    }
    if ((*(int *)(*(int *)(in_ECX + 4) + 0x906c) != 0) &&
       (iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1), iVar2 != 0)) {
      FUN_004988c0(local_74,local_24,local_20,local_1c,local_18);
      iVar2 = *(int *)(in_ECX + 4);
      FUN_004988c0(local_84,*(undefined4 *)(iVar2 + 0x8f88),*(undefined4 *)(iVar2 + 0x8f8c),
                   *(undefined4 *)(iVar2 + 0x8f90),*(undefined4 *)(iVar2 + 0x8f94));
      *(undefined4 *)(in_ECX + 0xa8) = 2;
    }
    FUN_006ecb90(in_ECX + 0x20);
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b0) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b4) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSen[9] */
/* 006f0be0  FUN_006f0be0  1184 bytes, 2 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006f0be0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  double local_74;
  double local_6c;
  double local_64;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ef20;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    FUN_00404c80(uVar1);
    FUN_004fca20();
    iVar2 = FUN_006ed8e0();
    if (iVar2 == 0) {
      FUN_00404c80();
      FUN_004fca20();
      iVar2 = FUN_006f3450();
      if (iVar2 == 1) {
        *(undefined4 *)(in_ECX + 0x27c) = 0;
        FUN_0040da70(param_2,param_3,param_4,param_5);
        ExceptionList = local_10;
        return 1;
      }
    }
    if ((((*(int *)(*(int *)(in_ECX + 4) + 0x1780) != 0) &&
         (*(int *)(*(int *)(in_ECX + 4) + 0x176c) != 0)) && (param_1 != 0x231d)) &&
       (*(int *)(in_ECX + 0xa8) == 2)) {
      FUN_0041df00(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),
                   *(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),&param_2);
    }
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    if (*(int *)(in_ECX + 0xa8) == 0) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 1;
      *(undefined4 *)(in_ECX + 0xa8) = 2;
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      iVar2 = *(int *)(in_ECX + 4);
      FUN_004988c0(local_34,*(undefined4 *)(iVar2 + 0x8f88),*(undefined4 *)(iVar2 + 0x8f8c),
                   *(undefined4 *)(iVar2 + 0x8f90),*(undefined4 *)(iVar2 + 0x8f94));
      FUN_006ecb90(&param_2);
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar3 = 0;
    }
    else if (*(int *)(in_ECX + 0xa8) == 2) {
      FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
      FUN_00404c80();
      FUN_004fca20();
      iVar2 = FUN_006ed8e0();
      if (iVar2 != 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar4 = (float10)FUN_005bdbe0();
        if ((double)fVar4 <= 0.0) {
          FUN_00404c80();
          FUN_004fca20();
          fVar4 = (float10)FUN_005bdbe0();
          local_64 = -(double)fVar4;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar4 = (float10)FUN_005bdbe0();
          local_64 = (double)fVar4;
        }
        if (1e-07 < local_64) {
          *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 2;
          *(undefined4 *)(in_ECX + 0xa8) = 3;
          local_8 = 0xffffffff;
          FUN_0079dfff();
          ExceptionList = local_10;
          return 1;
        }
      }
      if (*(double *)(in_ECX + 0x20) - *(double *)(in_ECX + 0x10) <= 0.0) {
        local_6c = -(*(double *)(in_ECX + 0x20) - *(double *)(in_ECX + 0x10));
      }
      else {
        local_6c = *(double *)(in_ECX + 0x20) - *(double *)(in_ECX + 0x10);
      }
      if (*(double *)(in_ECX + 0x28) - *(double *)(in_ECX + 0x18) <= 0.0) {
        local_74 = -(*(double *)(in_ECX + 0x28) - *(double *)(in_ECX + 0x18));
      }
      else {
        local_74 = *(double *)(in_ECX + 0x28) - *(double *)(in_ECX + 0x18);
      }
      if (1e-07 < local_6c + local_74) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 2;
        *(undefined4 *)(in_ECX + 0xa8) = 3;
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar3 = 1;
      }
      else {
        FUN_005168b0(0x14df,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar3 = 0;
      }
    }
    else {
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  ExceptionList = local_10;
  return uVar3;
}




/* vtable slots: CZukeiSen[13] */
/* 006f1080  FUN_006f1080  312 bytes, 0 callers */

undefined4
FUN_006f1080(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  double local_10;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    if (*(int *)(in_ECX + 0xa8) == 2) {
      FUN_00404c80();
      FUN_004fca20();
      iVar1 = FUN_006ed8e0();
      if (iVar1 != 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005bdbe0();
        if ((double)fVar3 <= 0.0) {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_005bdbe0();
          local_10 = -(double)fVar3;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_005bdbe0();
          local_10 = (double)fVar3;
        }
        if (1e-07 < local_10) {
          uVar2 = FUN_006f11c0(0x231d,param_2,param_3,param_4,param_5);
          return uVar2;
        }
      }
    }
    uVar2 = FUN_006f11c0(0x231d,param_2,param_3,param_4,param_5);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiSen[11] */
/* 006f11c0  FUN_006f11c0  812 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006f11c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  double local_641c;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ef60;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    FUN_00404c80(uVar1);
    FUN_004fca20();
    iVar2 = FUN_006ed8e0();
    if (iVar2 == 0) {
      FUN_00404c80();
      FUN_004fca20();
      iVar2 = FUN_006f3450();
      if (iVar2 == 1) {
        FUN_0040da70(param_2,param_3,param_4,param_5);
        *(undefined4 *)(in_ECX + 0x27c) = 1;
        ExceptionList = local_10;
        return 1;
      }
    }
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    local_18 = param_5;
    FUN_00446aa0();
    local_8 = 0;
    if (*(int *)(in_ECX + 0xa8) == 2) {
      FUN_00404c80();
      FUN_004fca20();
      iVar2 = FUN_006ed8e0();
      if (iVar2 != 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar4 = (float10)FUN_005bdbe0();
        if ((double)fVar4 <= 0.0) {
          FUN_00404c80();
          FUN_004fca20();
          fVar4 = (float10)FUN_005bdbe0();
          local_641c = -(double)fVar4;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar4 = (float10)FUN_005bdbe0();
          local_641c = (double)fVar4;
        }
        if (1e-07 < local_641c) {
          *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f34) = 1;
          iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
          if (iVar2 == 0) {
            FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
          }
          uVar3 = FUN_006f0be0(0x231d,local_24,local_20,local_1c,local_18);
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return uVar3;
        }
      }
    }
    iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
    if (iVar2 == 1) {
      uVar3 = FUN_006f0be0(0x231d,local_24,local_20,local_1c,local_18);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  ExceptionList = local_10;
  return uVar3;
}




/* vtable slots: CZukeiSen[8] */
/* 006f1510  FUN_006f1510  3544 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006f1510(void)

{
  undefined8 uVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_ECX;
  float10 fVar8;
  double dVar9;
  int iStack_12d04;
  double dStack_12ce8;
  double dStack_12ce0;
  double dStack_12cd8;
  double dStack_12cd0;
  double dStack_12cc8;
  double dStack_12cc0;
  double dStack_12cb8;
  double dStack_12cb0;
  double dStack_12ca8;
  double dStack_12ca0;
  double dStack_12c98;
  int iStack_12c90;
  int iStack_12c8c;
  undefined1 local_104 [16];
  undefined1 local_f4 [16];
  undefined1 local_e4 [16];
  undefined1 local_d4 [16];
  undefined1 local_c4 [16];
  undefined1 local_b4 [16];
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
  undefined1 local_84 [16];
  undefined1 local_74 [16];
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined8 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093efb6;
  local_10 = ExceptionList;
  uVar5 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar5;
  FUN_00404c80(uVar5);
  iVar6 = FUN_004fca20();
  if (*(int *)(iVar6 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x861c)) {
    FUN_00404c80(uVar5);
    FUN_004fca20();
    iVar6 = FUN_006ed8e0();
    if (iVar6 == 0) {
      if (*(int *)(in_ECX + 0xa8) != 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar8 = (float10)FUN_005bdab0();
        dVar9 = (double)fVar8;
        if ((*(int *)(in_ECX + 0xac) == 0) && (*(int *)(in_ECX + 0xb4) == 0)) {
          puVar7 = (undefined4 *)FUN_006ec980(local_104);
          FUN_004988c0(local_f4,*puVar7,puVar7[1],puVar7[2],puVar7[3]);
        }
        if ((*(int *)(in_ECX + 0xac) != 0) && (*(int *)(in_ECX + 0xbc) != 0)) {
          if ((*(int *)(in_ECX + 0xac) == 2) &&
             (iVar6 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040,uVar5,dVar9), iVar6 != 0)) {
            iVar6 = *(int *)(in_ECX + 0xbc);
            FUN_004988c0(local_e4,*(undefined4 *)(iVar6 + 8),*(undefined4 *)(iVar6 + 0xc),
                         *(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0x14));
            puVar7 = (undefined4 *)FUN_006ec980(local_d4);
            FUN_004988c0(local_c4,*puVar7,puVar7[1],puVar7[2],puVar7[3]);
          }
          FUN_00446aa0();
          local_8 = 0;
          local_34 = *(undefined4 *)(in_ECX + 0x20);
          local_30 = *(undefined4 *)(in_ECX + 0x24);
          local_2c = *(undefined4 *)(in_ECX + 0x28);
          local_28 = *(undefined4 *)(in_ECX + 0x2c);
          iVar6 = FUN_0045b6c0(0,*(undefined4 *)(in_ECX + 0xbc),&local_34);
          if (iVar6 != 0) {
            FUN_004988c0(local_b4,local_34,local_30,local_2c,local_28);
          }
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        FUN_00404c80();
        FUN_004fca20();
        fVar8 = (float10)FUN_005bdb30();
        if ((double)fVar8 != 0.0) {
          puVar7 = (undefined4 *)FUN_006eeee0(local_a4,(double)fVar8);
          FUN_004988c0(local_94,*puVar7,puVar7[1],puVar7[2],puVar7[3]);
        }
        FUN_00446aa0();
        local_8 = 1;
        FUN_004552a0(in_ECX + 0xd8);
        FUN_0040da70(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),
                     *(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c));
        FUN_0040da20(*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24),
                     *(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(in_ECX + 0x2c));
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      FUN_005f8a10();
      dStack_12c98 = *(double *)(*(int *)(in_ECX + 4) + 0x17c0);
      FUN_00404c80();
      FUN_004fca20();
      iVar6 = FUN_004fcd80();
      if (iVar6 == 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar8 = (float10)FUN_005bdab0();
        dStack_12c98 = (double)fVar8 + dStack_12c98;
      }
      FUN_004988c0(local_84,*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),
                   *(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c));
      FUN_004988c0(local_74,*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24),
                   *(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(in_ECX + 0x2c));
      FUN_005f99d0(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),
                   *(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
                   SUB84(dStack_12c98,0),(int)((ulonglong)dStack_12c98 >> 0x20),0);
      FUN_005f92e0(in_ECX + 0x498);
      FUN_005f92e0(in_ECX + 0x4a8);
      FUN_00404c80();
      FUN_004fca20();
      fVar8 = (float10)FUN_005bdbe0();
      dVar9 = (double)fVar8;
      FUN_00404c80();
      FUN_004fca20();
      fVar8 = (float10)FUN_005bdd00();
      dVar2 = (double)fVar8;
      if (*(int *)(in_ECX + 0xa8) == 0) {
        dStack_12ce8 = dVar9;
        if (dVar9 <= 0.0) {
          dStack_12ce8 = -dVar9;
        }
        if (dStack_12ce8 <= 1e-07) {
          ExceptionList = local_10;
          return;
        }
        dStack_12ce0 = dVar2;
        if (dVar2 <= 0.0) {
          dStack_12ce0 = -dVar2;
        }
        if (dStack_12ce0 <= 1e-07) {
          ExceptionList = local_10;
          return;
        }
      }
      dStack_12cd8 = dVar9;
      if (dVar9 <= 0.0) {
        dStack_12cd8 = -dVar9;
      }
      *(double *)(*(int *)(in_ECX + 4) + 0x83f8) =
           dStack_12cd8 *
           *(double *)(*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
      dStack_12cd0 = dVar2;
      if (dVar2 <= 0.0) {
        dStack_12cd0 = -dVar2;
      }
      *(double *)(*(int *)(in_ECX + 4) + 0x8400) =
           dStack_12cd0 *
           *(double *)(*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
      dStack_12cc8 = dVar9;
      if (dVar9 <= 0.0) {
        dStack_12cc8 = -dVar9;
      }
      if (1e-07 < dStack_12cc8) {
        if (*(double *)(in_ECX + 0x4a8) <= 0.0) {
          dStack_12cb8 = -*(double *)(in_ECX + 0x4a8);
        }
        else {
          dStack_12cb8 = *(double *)(in_ECX + 0x4a8);
        }
        if (dVar9 / 2.0 <= 0.0) {
          dStack_12cc0 = -(dVar9 / 2.0);
        }
        else {
          dStack_12cc0 = dVar9 / 2.0;
        }
        if (dStack_12cc0 <= dStack_12cb8) {
          if (*(double *)(in_ECX + 0x4a8) <= 0.0) {
            *(double *)(in_ECX + 0x4a8) = -dVar9;
          }
          else {
            *(double *)(in_ECX + 0x4a8) = dVar9;
          }
        }
        else {
          *(double *)(in_ECX + 0x498) = -dVar9 / 2.0;
          *(double *)(in_ECX + 0x4a8) = dVar9 / 2.0;
        }
      }
      dStack_12cb0 = dVar2;
      if (dVar2 <= 0.0) {
        dStack_12cb0 = -dVar2;
      }
      if (1e-07 < dStack_12cb0) {
        if (*(double *)(in_ECX + 0x4b0) <= 0.0) {
          dStack_12ca0 = -*(double *)(in_ECX + 0x4b0);
        }
        else {
          dStack_12ca0 = *(double *)(in_ECX + 0x4b0);
        }
        if (dVar2 / 2.0 <= 0.0) {
          dStack_12ca8 = -(dVar2 / 2.0);
        }
        else {
          dStack_12ca8 = dVar2 / 2.0;
        }
        if (dStack_12ca8 <= dStack_12ca0) {
          if (*(double *)(in_ECX + 0x4b0) <= 0.0) {
            *(double *)(in_ECX + 0x4b0) = -dVar2;
          }
          else {
            *(double *)(in_ECX + 0x4b0) = dVar2;
          }
        }
        else {
          *(double *)(in_ECX + 0x4a0) = -dVar2 / 2.0;
          *(double *)(in_ECX + 0x4b0) = dVar2 / 2.0;
        }
      }
      FUN_00446aa0();
      local_8 = 2;
      for (iStack_12c8c = 0; iStack_12c8c < 4; iStack_12c8c = iStack_12c8c + 1) {
        FUN_004552a0(in_ECX + 0xd8 + iStack_12c8c * 0x68);
      }
      FUN_00408a60();
      FUN_004988c0(local_64,*(undefined4 *)(in_ECX + 0x498),*(undefined4 *)(in_ECX + 0x49c),
                   *(undefined4 *)(in_ECX + 0x4a0),*(undefined4 *)(in_ECX + 0x4a4));
      FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
      uVar1 = *(undefined8 *)(in_ECX + 0x4a8);
      local_24._0_4_ = (undefined4)uVar1;
      local_24._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
      uVar3 = local_24._4_4_;
      uVar4 = (undefined4)local_24;
      local_24 = uVar1;
      FUN_0040da20(uVar4,uVar3,local_1c,local_18);
      FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
      FUN_004988c0(local_54,*(undefined4 *)(in_ECX + 0x4a8),*(undefined4 *)(in_ECX + 0x4ac),
                   *(undefined4 *)(in_ECX + 0x4b0),*(undefined4 *)(in_ECX + 0x4b4));
      FUN_0040da20((undefined4)local_24,local_24._4_4_,local_1c,local_18);
      FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
      uVar1 = *(undefined8 *)(in_ECX + 0x498);
      local_24._0_4_ = (undefined4)uVar1;
      local_24._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
      uVar3 = local_24._4_4_;
      uVar4 = (undefined4)local_24;
      local_24 = uVar1;
      FUN_0040da20(uVar4,uVar3,local_1c,local_18);
      FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
      FUN_004988c0(local_44,*(undefined4 *)(in_ECX + 0x498),*(undefined4 *)(in_ECX + 0x49c),
                   *(undefined4 *)(in_ECX + 0x4a0),*(undefined4 *)(in_ECX + 0x4a4));
      FUN_0040da20((undefined4)local_24,local_24._4_4_,local_1c,local_18);
      FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
      if (iStack_12d04 != 0) {
        for (iStack_12c90 = 0; iStack_12c90 < 4; iStack_12c90 = iStack_12c90 + 1) {
          FUN_005f8d70(in_ECX + 0xd8 + iStack_12c90 * 0x68);
        }
        FUN_005f8ce0(in_ECX + 0x498);
        FUN_005f8ce0(in_ECX + 0x4a8);
      }
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSen[3] */
/* 006f22f0  FUN_006f22f0  2691 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006f22f0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  int iVar16;
  _GUID *p_Var17;
  float10 fVar18;
  double dVar19;
  undefined1 local_b6a8 [20];
  undefined4 local_b694;
  int *local_b690;
  undefined1 local_b68c [46040];
  _GUID local_2b4;
  undefined1 local_2a4 [16];
  _GUID local_294;
  _GUID local_284;
  _GUID local_274;
  undefined1 local_264 [16];
  _GUID local_254;
  undefined1 local_244 [16];
  _GUID local_234;
  _GUID local_224;
  _GUID local_214;
  _GUID local_204;
  _GUID local_1f4;
  undefined1 local_1e4 [16];
  _GUID local_1d4;
  undefined1 local_1c4 [16];
  _GUID local_1b4;
  undefined1 local_1a4 [16];
  _GUID local_194;
  undefined1 local_184 [16];
  _GUID local_174;
  undefined1 local_164 [16];
  undefined1 local_154 [16];
  _GUID local_144;
  undefined1 local_134 [16];
  _GUID local_124;
  undefined1 local_114 [16];
  undefined1 local_104 [16];
  undefined1 local_f4 [16];
  _GUID local_e4;
  undefined1 local_d4 [16];
  _GUID local_c4;
  undefined1 local_b4 [16];
  double local_a4;
  double dStack_9c;
  double local_94;
  double dStack_8c;
  double local_84;
  double dStack_7c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f006;
  local_10 = ExceptionList;
  uVar15 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar15;
  FUN_00404c80(uVar15);
  iVar16 = FUN_004fca20();
  if (*(int *)(iVar16 + 0x1a0) != *(int *)(local_b690[1] + 0x861c)) {
    ExceptionList = local_10;
    return;
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(local_b690[1]);
  local_8._0_1_ = 1;
  FUN_0040c0e0();
  FUN_0044dd90();
  (**(code **)(*local_b690 + 0x20))();
  local_b690[0x31] = 0;
  local_b690[0x9e] = 0;
  FUN_00404c80();
  FUN_004fca20();
  iVar16 = FUN_006ed8e0();
  if (iVar16 != 0) {
    FUN_00404c80();
    FUN_004fca20();
    fVar18 = (float10)FUN_005beee0();
    dVar19 = (double)fVar18;
    FUN_00404c80(uVar15,dVar19);
    FUN_004fca20();
    fVar18 = (float10)FUN_005bee90();
    FUN_00404c80();
    FUN_004fca20();
    iVar16 = FUN_006f33f0();
    if (iVar16 == 0) {
      FUN_006f6140(local_b68c,local_b6a8,dVar19,(double)fVar18,1);
    }
    else {
      local_b694 = 4;
      FUN_00721630(local_b690[1],0xffffffff,0);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00404b80();
      p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x36),&local_124);
      uVar1._0_2_ = p_Var17->Data2;
      uVar1._2_2_ = p_Var17->Data3;
      FUN_004988c0(local_134,p_Var17->Data1,uVar1,*(undefined4 *)p_Var17->Data4,
                   *(undefined4 *)(p_Var17->Data4 + 4));
      p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x84),&local_144);
      uVar2._0_2_ = p_Var17->Data2;
      uVar2._2_2_ = p_Var17->Data3;
      FUN_004988c0(local_154,p_Var17->Data1,uVar2,*(undefined4 *)p_Var17->Data4,
                   *(undefined4 *)(p_Var17->Data4 + 4));
      p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x6a),&local_c4);
      uVar3._0_2_ = p_Var17->Data2;
      uVar3._2_2_ = p_Var17->Data3;
      FUN_004988c0(local_164,p_Var17->Data1,uVar3,*(undefined4 *)p_Var17->Data4,
                   *(undefined4 *)(p_Var17->Data4 + 4));
      p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x50),&local_174);
      uVar4._0_2_ = p_Var17->Data2;
      uVar4._2_2_ = p_Var17->Data3;
      FUN_004988c0(local_184,p_Var17->Data1,uVar4,*(undefined4 *)p_Var17->Data4,
                   *(undefined4 *)(p_Var17->Data4 + 4));
      if (0.0 < (local_84 - local_a4) * (dStack_8c - dStack_9c) -
                (local_94 - local_a4) * (dStack_7c - dStack_9c)) {
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x36),&local_194);
        uVar5._0_2_ = p_Var17->Data2;
        uVar5._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_1a4,p_Var17->Data1,uVar5,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x50),&local_1b4);
        uVar6._0_2_ = p_Var17->Data2;
        uVar6._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_1c4,p_Var17->Data1,uVar6,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x6a),&local_1d4);
        uVar7._0_2_ = p_Var17->Data2;
        uVar7._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_1e4,p_Var17->Data1,uVar7,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x84),&local_1f4);
        uVar8._0_2_ = p_Var17->Data2;
        uVar8._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_114,p_Var17->Data1,uVar8,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
      }
      CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x6a),&local_214);
      CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x50),&local_224);
      iVar16 = FUN_00498960();
      if (iVar16 != 0) {
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x36),&local_234);
        uVar9._0_2_ = p_Var17->Data2;
        uVar9._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_244,p_Var17->Data1,uVar9,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x50),&local_254);
        uVar10._0_2_ = p_Var17->Data2;
        uVar10._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_264,p_Var17->Data1,uVar10,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        local_b694 = 2;
      }
      CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x50),&local_274);
      CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x36),&local_284);
      iVar16 = FUN_00498960();
      if (iVar16 != 0) {
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x50),&local_294);
        uVar11._0_2_ = p_Var17->Data2;
        uVar11._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_2a4,p_Var17->Data1,uVar11,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x6a),&local_2b4);
        uVar12._0_2_ = p_Var17->Data2;
        uVar12._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_d4,p_Var17->Data1,uVar12,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        local_b694 = 2;
      }
      FUN_00404c80();
      iVar16 = FUN_004fca20();
      iVar16 = CMFCRibbonBar::IsQuickAccessToolbarOnTop(*(CMFCRibbonBar **)(iVar16 + 0x1a0));
      if (iVar16 != 0) {
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x36),&local_e4);
        uVar13._0_2_ = p_Var17->Data2;
        uVar13._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_f4,p_Var17->Data1,uVar13,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        p_Var17 = CPropertySet::GetClassID((CPropertySet *)(local_b690 + 0x6a),&local_204);
        uVar14._0_2_ = p_Var17->Data2;
        uVar14._2_2_ = p_Var17->Data3;
        FUN_004988c0(local_104,p_Var17->Data1,uVar14,*(undefined4 *)p_Var17->Data4,
                     *(undefined4 *)(p_Var17->Data4 + 4));
        local_b694 = 2;
      }
      FUN_007255f0(2,local_b68c,local_b6a8,local_b694,local_b4);
      local_8._0_1_ = 1;
      FUN_004fa980();
    }
    local_b690[0x31] = local_b690[0x31] + 1;
    FUN_00404c80();
    FUN_004fca20();
    FUN_006f14f0();
    goto LAB_006f2c8b;
  }
  FUN_00404c80();
  FUN_004fca20();
  iVar16 = FUN_006f3430();
  if (iVar16 == 1) {
LAB_006f2432:
    local_b690[0x122] = 0;
    local_b690[0x123] = 0;
  }
  else {
    FUN_00404c80();
    FUN_004fca20();
    iVar16 = FUN_006f3470();
    if (iVar16 == 1) goto LAB_006f2432;
  }
  FUN_00404c80();
  FUN_004fca20();
  iVar16 = FUN_006f3410();
  if (iVar16 == 1) {
    local_b690[0x124] = 0;
  }
  FUN_006f46a0();
  FUN_00404c80();
  FUN_004fca20();
  fVar18 = (float10)FUN_005bdb30();
  if (1e-07 < (double)fVar18) {
    FUN_00404c80();
    FUN_004fca20();
    FUN_005bea70();
  }
LAB_006f2c8b:
  FUN_006edd60(local_b690 + 0xa0);
  *(undefined4 *)(local_b690[1] + 0x8560) = 0;
  local_b690[0x2a] = 0;
  local_b690[0x2c] = local_b690[0x2b];
  local_b690[0x2b] = 0;
  local_b690[0x2d] = 0;
  local_b690[0x122] = 0;
  local_b690[0x123] = 0;
  local_b690[0x124] = 0;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



