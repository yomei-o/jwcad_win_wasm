/* CZukeiChuushinSen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiChuushinSen[12], CZukeiCorner[12], CZukeiRenzokuSen[12] */
/* 00636720  FUN_00636720  58 bytes, 0 callers */

void FUN_00636720(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CZukeiChuushinSen[1] */
/* 0063cc00  FUN_0063cc00  68 bytes, 0 callers */

undefined4 FUN_0063cc00(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0063cb20();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1e0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiChuushinSen[6] */
/* 0063d050  FUN_0063d050  1436 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0063d050(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  int local_65a8;
  int local_65a4;
  int local_65a0;
  int local_659c;
  undefined1 local_1c4 [16];
  undefined1 local_1b4 [208];
  undefined1 local_e4 [208];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937d7b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8ebc) = 0;
  local_14 = uVar1;
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2(in_ECX[1]);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar2 = FUN_0040c0e0();
  if (in_ECX[0x32] == 1) {
    *(undefined4 *)(in_ECX[1] + 0x8ebc) = 1;
    FUN_004efbb0(0x14fc,0,0);
  }
  if (in_ECX[0x32] == 2) {
    FUN_004efbb0(0x14fd,0,0);
  }
  if (in_ECX[0x32] == 3) {
    if (in_ECX[0x2a] == 0) {
      FUN_005977f0(0x150a);
      uVar3 = FUN_00404920();
      FUN_005cf710(local_e4,uVar3);
      FUN_00404770();
      FUN_004efbb0(0x14c8,local_e4,0);
    }
    else {
      if (in_ECX[0x2e] == *(int *)(in_ECX[1] + 0x8f58) ||
          in_ECX[0x2e] - *(int *)(in_ECX[1] + 0x8f58) < 0) {
        local_659c = -(in_ECX[0x2e] - *(int *)(in_ECX[1] + 0x8f58));
      }
      else {
        local_659c = in_ECX[0x2e] - *(int *)(in_ECX[1] + 0x8f58);
      }
      if (in_ECX[0x2f] == *(int *)(in_ECX[1] + 0x8f5c) ||
          in_ECX[0x2f] - *(int *)(in_ECX[1] + 0x8f5c) < 0) {
        local_65a0 = -(in_ECX[0x2f] - *(int *)(in_ECX[1] + 0x8f5c));
      }
      else {
        local_65a0 = in_ECX[0x2f] - *(int *)(in_ECX[1] + 0x8f5c);
      }
      if (local_659c + local_65a0 < 3) {
        FUN_004efbb0(0x150b,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      in_ECX[0x32] = 4;
    }
    in_ECX[0x2c] = 0;
    in_ECX[0x2a] = 0;
  }
  if (in_ECX[0x32] == 4) {
    if (in_ECX[0x2b] == 0) {
      FUN_004988c0(local_1c4,*param_1,param_1[1],param_1[2],param_1[3]);
      FUN_005977f0(0x150a);
      uVar2 = FUN_00404920();
      FUN_005cf710(local_1b4,uVar2);
      FUN_00404770();
      FUN_004efbb0(0x14c9,local_1b4,0);
      iVar4 = FUN_0063f520();
      if (iVar4 == 0) {
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      in_ECX[0x2d] = 0;
      in_ECX[0x2b] = 0;
      FUN_0063cc50();
    }
    else {
      if (in_ECX[0x30] == *(int *)(in_ECX[1] + 0x8f58) ||
          in_ECX[0x30] - *(int *)(in_ECX[1] + 0x8f58) < 0) {
        local_65a4 = -(in_ECX[0x30] - *(int *)(in_ECX[1] + 0x8f58));
      }
      else {
        local_65a4 = in_ECX[0x30] - *(int *)(in_ECX[1] + 0x8f58);
      }
      if (in_ECX[0x31] == *(int *)(in_ECX[1] + 0x8f5c) ||
          in_ECX[0x31] - *(int *)(in_ECX[1] + 0x8f5c) < 0) {
        local_65a8 = -(in_ECX[0x31] - *(int *)(in_ECX[1] + 0x8f5c));
      }
      else {
        local_65a8 = in_ECX[0x31] - *(int *)(in_ECX[1] + 0x8f5c);
      }
      if (local_65a4 + local_65a8 < 3) {
        FUN_0063cc50();
        FUN_004efbb0(0x150b,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      in_ECX[0x2d] = 0;
      in_ECX[0x2b] = 0;
      in_ECX[0x32] = 5;
      (**(code **)(*in_ECX + 0xc))(uVar1,uVar2);
      if (*(int *)(in_ECX[1] + 0x8588) == 0x8069) {
        *(undefined4 *)(in_ECX[1] + 0x8588) = 0xffffd9bb;
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
    }
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiChuushinSen[16] */
/* 0063d5f0  FUN_0063d5f0  529 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0063d5f0(void)

{
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  undefined4 local_63f0;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937dcb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6408,*(undefined4 *)(local_63e8 + 4));
  if (*(int *)(local_63e8 + 200) == 1) {
    if (*(int *)(local_63e8 + 0xcc) != 0) {
      *(undefined4 *)(local_63e8 + 0xcc) = 0;
      *(undefined4 *)(local_63e8 + 200) = 4;
    }
    local_63ec = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (*(int *)(local_63e8 + 200) == 2) {
      *(undefined4 *)(local_63e8 + 200) = 1;
    }
    if (*(int *)(local_63e8 + 200) == 3) {
      *(undefined4 *)(local_63e8 + 200) = 2;
    }
    if ((*(int *)(local_63e8 + 200) == 4) &&
       (*(undefined4 *)(local_63e8 + 200) = 3, *(int *)(local_63e8 + 0xb0) != 0)) {
      *(undefined4 *)(local_63e8 + 0xb0) = 0;
      *(undefined4 *)(local_63e8 + 0xa8) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      local_63f0 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63ec = local_63f0;
    }
    else {
      FUN_00404c80();
      FUN_0056d7d0();
      local_63f4 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63ec = local_63f4;
    }
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiChuushinSen[0] */
/* 0063d810  FUN_0063d810  16 bytes, 0 callers */

undefined ** FUN_0063d810(void)

{
  return &PTR_s_CZukeiChuushinSen_00977e50;
}




/* vtable slots: CZukeiChuushinSen[46] */
/* 0063d820  FUN_0063d820  231 bytes, 0 callers */

undefined4
FUN_0063d820(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_c [2];
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_c[0] = 0xffffffff;
      iVar2 = FUN_00778a40(1,local_c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,9);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiChuushinSen[47] */
/* 0063d910  FUN_0063d910  1316 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0063d910(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  undefined4 uVar5;
  undefined4 local_647c;
  undefined4 local_6478;
  undefined4 local_6474;
  int local_6470;
  undefined1 local_9c [16];
  undefined1 local_8c [8];
  double local_84;
  double local_7c;
  double local_74;
  double local_6c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937e1b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00446aa0(uVar1);
  local_8 = 0;
  if (DAT_00a0c7c0 != 0) {
    local_6478 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return local_6478;
  }
  uVar5 = 0;
  if (*(int *)(*(int *)(local_6470 + 4) + 0x907c) == 0) {
    local_647c = 0xffffffff;
    iVar2 = FUN_00778a40(2,&local_647c,*(undefined4 *)(*(int *)(local_6470 + 4) + 0x9074),param_1,
                         param_2,param_3,param_4,param_5,param_6,param_7,9);
    if (iVar2 != 0) {
      local_8 = 0xffffffff;
      FUN_00447100(uVar1,uVar5);
      ExceptionList = local_10;
      return 0;
    }
    if (((*(int *)(local_6470 + 200) == 3) || (*(int *)(local_6470 + 200) == 4)) && (param_2 == 0xc)
       ) {
      if (param_3 == 1) {
        FUN_005168b0(0x278e,*(undefined4 *)(*(int *)(local_6470 + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(local_6470 + 4) + 0x8f54),1,0);
        local_8 = 0xffffffff;
        FUN_00447100(uVar1,uVar5);
        ExceptionList = local_10;
        return 0;
      }
      if (param_3 == 2) {
        *(undefined4 *)(local_6470 + 0xac) = 0;
        *(undefined4 *)(local_6470 + 0xb4) = 0;
        local_6474 = 0;
        iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6470 + 4),&param_4,&local_6474,0);
        if (iVar2 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100(uVar1,uVar5);
          ExceptionList = local_10;
          return 0;
        }
        iVar2 = FUN_0079d98a();
        if ((iVar2 == 0) && (iVar2 = FUN_0079d98a(), iVar2 == 0)) {
          FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6470 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6470 + 4) + 0x8f28),0,0);
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        FUN_0041f760();
        local_8._0_1_ = 1;
        FUN_00408a60();
        fVar4 = (float10)FUN_005f8b60(0,0,0);
        local_84 = (double)fVar4;
        fVar4 = (float10)FUN_005f8c20(0,0,0);
        local_7c = (double)fVar4;
        fVar4 = (float10)FUN_005f8b60(0,0x4059000000000000,0);
        local_74 = (double)fVar4;
        fVar4 = (float10)FUN_005f8c20(0,0x4059000000000000,0);
        local_6c = (double)fVar4;
        iVar2 = FUN_0045fa30(local_8c,local_6474,param_4,param_5,param_6,param_7,&local_24);
        if (iVar2 == 0) {
          FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6470 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6470 + 4) + 0x8f28),0,0);
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0041fd70();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        FUN_004988c0(local_9c,local_24,local_20,local_1c,local_18);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0041fd70();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 1;
      }
    }
  }
  uVar3 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00447100(uVar1,uVar5);
  ExceptionList = local_10;
  return uVar3;
}




/* vtable slots: CZukeiChuushinSen[10] */
/* 0063de40  FUN_0063de40  432 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0063de40(void)

{
  int iVar1;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a30b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_0079dea2(in_ECX[1]);
  local_8._0_1_ = 1;
  iVar1 = in_ECX[1];
  if (*(int *)(in_ECX[1] + 0x9068) == 0) {
    if (*(int *)(in_ECX[1] + 0x906c) != 0) {
      if (in_ECX[0x32] != 1) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      (**(code **)(*in_ECX + 0x2c))
                (0,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
                 *(undefined4 *)(iVar1 + 0x8f70),*(undefined4 *)(iVar1 + 0x8f74));
    }
  }
  else {
    if (in_ECX[0x32] != 1) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    (**(code **)(*in_ECX + 0x24))
              (0,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
               *(undefined4 *)(iVar1 + 0x8f70),*(undefined4 *)(iVar1 + 0x8f74));
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiChuushinSen[9] */
/* 0063dff0  FUN_0063dff0  3948 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0063dff0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  float10 fVar4;
  undefined1 local_6568 [20];
  int *local_6554;
  int *local_6550;
  int *local_654c;
  int local_6548;
  undefined4 local_24c;
  undefined4 local_220;
  undefined4 local_21c;
  undefined1 local_174 [16];
  undefined1 local_164 [16];
  undefined1 local_154 [16];
  undefined1 local_144 [16];
  undefined1 local_134 [16];
  undefined1 local_124 [16];
  undefined1 local_114 [16];
  undefined1 local_104 [8];
  double local_fc;
  double local_f4;
  double local_ec;
  double local_e4;
  undefined1 local_9c [8];
  double local_94;
  double local_8c;
  double local_84;
  double local_7c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937e81;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  local_6548 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6568,*(undefined4 *)(local_6548 + 4));
  if (param_1 == 0x231d) {
    uVar1 = FUN_0063f0e0(param_2,param_3,param_4,param_5);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if ((*(int *)(local_6548 + 200) == 1) || (*(int *)(local_6548 + 200) == 2)) {
      local_220 = 1;
      local_21c = 1;
      iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6548 + 4),&param_2,&local_654c,1);
      if (iVar2 == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
    }
    if (*(int *)(local_6548 + 200) == 1) {
      if (*(int *)(local_6548 + 0x150) != 0) {
        local_6550 = *(int **)(local_6548 + 0x150);
        if (local_6550 != (int *)0x0) {
          (**(code **)(*local_6550 + 4))();
        }
        *(undefined4 *)(local_6548 + 0x150) = 0;
      }
      if (local_654c != (int *)0x0) {
        uVar1 = (**(code **)(*local_654c + 0x14))();
        *(undefined4 *)(local_6548 + 0x150) = uVar1;
      }
      *(undefined4 *)(local_6548 + 0xe8) = *(undefined4 *)(local_6548 + 0x150);
      FUN_004988c0(local_154,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6548 + 200) = 2;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else if (*(int *)(local_6548 + 200) == 2) {
      if (local_654c == *(int **)(local_6548 + 0xe8)) {
        FUN_005168b0(0x14e7,*(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        if (*(int *)(local_6548 + 0x154) != 0) {
          local_6554 = *(int **)(local_6548 + 0x154);
          if (local_6554 != (int *)0x0) {
            (**(code **)(*local_6554 + 4))();
          }
          *(undefined4 *)(local_6548 + 0x154) = 0;
        }
        if (local_654c != (int *)0x0) {
          uVar1 = (**(code **)(*local_654c + 0x14))();
          *(undefined4 *)(local_6548 + 0x154) = uVar1;
        }
        *(undefined4 *)(local_6548 + 0xec) = *(undefined4 *)(local_6548 + 0x154);
        FUN_004988c0(local_144,param_2,param_3,param_4,param_5);
        iVar2 = FUN_0063f520();
        if (iVar2 == 0) {
          FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f28),0,0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          *(undefined4 *)(local_6548 + 200) = 3;
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
      }
    }
    else if (*(int *)(local_6548 + 200) == 3) {
      FUN_004988c0(local_134,param_2,param_3,param_4,param_5);
      uVar1 = *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f5c);
      *(undefined4 *)(local_6548 + 0xb8) = *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f58);
      *(undefined4 *)(local_6548 + 0xbc) = uVar1;
      if (*(int *)(local_6548 + 0xa8) == 0) {
        *(undefined4 *)(local_6548 + 0xa8) = 1;
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        *(undefined4 *)(local_6548 + 0xa8) = 0;
        iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6548 + 4),local_6548 + 0x120,local_6548 + 0xb0,
                             0);
        if (iVar2 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          iVar2 = FUN_0079d98a();
          if ((iVar2 == 0) && (iVar2 = FUN_0079d98a(), iVar2 == 0)) {
            FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f24),
                         *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f28),0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            FUN_0041f760();
            local_8._0_1_ = 2;
            FUN_00408a60();
            fVar4 = (float10)FUN_005f8b60(0,0,0);
            local_fc = (double)fVar4;
            fVar4 = (float10)FUN_005f8c20(0,0,0);
            local_f4 = (double)fVar4;
            fVar4 = (float10)FUN_005f8b60(0,0x4059000000000000,0);
            local_ec = (double)fVar4;
            fVar4 = (float10)FUN_005f8c20(0,0x4059000000000000,0);
            local_e4 = (double)fVar4;
            iVar2 = FUN_0045fa30(local_104,*(undefined4 *)(local_6548 + 0xb0),
                                 *(undefined4 *)(local_6548 + 0x120),
                                 *(undefined4 *)(local_6548 + 0x124),
                                 *(undefined4 *)(local_6548 + 0x128),
                                 *(undefined4 *)(local_6548 + 300),&local_24);
            if (iVar2 == 0) {
              FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f28),0,0);
              FUN_00404c80();
              FUN_0056d7d0();
              local_8._0_1_ = 1;
              FUN_0041fd70();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
            else {
              FUN_0044cfb0(local_6568,*(undefined4 *)(local_6548 + 4),0,
                           *(undefined4 *)(local_6548 + 0xb0),local_24,local_20,local_1c,local_18,
                           *(undefined4 *)(local_6548 + 0x120),*(undefined4 *)(local_6548 + 0x124),
                           *(undefined4 *)(local_6548 + 0x128),*(undefined4 *)(local_6548 + 300));
              local_24c = 0;
              FUN_004988c0(local_124,local_24,local_20,local_1c,local_18);
              *(undefined4 *)(local_6548 + 200) = 4;
              iVar2 = FUN_0079d98a();
              if ((iVar2 != 0) && (iVar2 = FUN_0040c200(), iVar2 != 0)) {
                FUN_005168b0(0x1458,*(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f24),
                             *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f28),0,0);
                *(undefined4 *)(local_6548 + 0xb0) = 0;
              }
              FUN_00404c80();
              FUN_0056d7d0();
              local_8._0_1_ = 1;
              FUN_0041fd70();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
          }
        }
      }
    }
    else if (*(int *)(local_6548 + 200) == 4) {
      puVar3 = (undefined4 *)FUN_004988c0(local_114,param_2,param_3,param_4,param_5);
      FUN_004988c0(local_174,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
      uVar1 = *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f5c);
      *(undefined4 *)(local_6548 + 0xc0) = *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f58);
      *(undefined4 *)(local_6548 + 0xc4) = uVar1;
      if (*(int *)(local_6548 + 0xac) == 0) {
        *(undefined4 *)(local_6548 + 0xac) = 1;
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6548 + 4),local_6548 + 0x130,local_6548 + 0xb4,
                             0);
        if (iVar2 == 0) {
          *(undefined4 *)(local_6548 + 0xac) = 0;
          *(undefined4 *)(local_6548 + 0xb4) = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          iVar2 = FUN_0079d98a();
          if ((iVar2 == 0) && (iVar2 = FUN_0079d98a(), iVar2 == 0)) {
            *(undefined4 *)(local_6548 + 0xac) = 0;
            *(undefined4 *)(local_6548 + 0xb4) = 0;
            FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f24),
                         *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f28),0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            FUN_0041f760();
            local_8._0_1_ = 3;
            FUN_00408a60();
            fVar4 = (float10)FUN_005f8b60(0,0,0);
            local_94 = (double)fVar4;
            fVar4 = (float10)FUN_005f8c20(0,0,0);
            local_8c = (double)fVar4;
            fVar4 = (float10)FUN_005f8b60(0,0x4059000000000000,0);
            local_84 = (double)fVar4;
            fVar4 = (float10)FUN_005f8c20(0,0x4059000000000000,0);
            local_7c = (double)fVar4;
            iVar2 = FUN_0045fa30(local_9c,*(undefined4 *)(local_6548 + 0xb4),
                                 *(undefined4 *)(local_6548 + 0x130),
                                 *(undefined4 *)(local_6548 + 0x134),
                                 *(undefined4 *)(local_6548 + 0x138),
                                 *(undefined4 *)(local_6548 + 0x13c),&local_34);
            if (iVar2 == 0) {
              *(undefined4 *)(local_6548 + 0xac) = 0;
              *(undefined4 *)(local_6548 + 0xb4) = 0;
              FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f28),0,0);
              FUN_00404c80();
              FUN_0056d7d0();
              local_8._0_1_ = 1;
              FUN_0041fd70();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
            else {
              FUN_004988c0(local_164,local_34,local_30,local_2c,local_28);
              *(undefined4 *)(local_6548 + 200) = 5;
              iVar2 = FUN_0079d98a();
              if ((iVar2 != 0) && (iVar2 = FUN_0040c200(), iVar2 != 0)) {
                FUN_005168b0(0x1458,*(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f24),
                             *(undefined4 *)(*(int *)(local_6548 + 4) + 0x8f28),0,0);
                *(undefined4 *)(local_6548 + 0xb4) = 0;
              }
              local_8._0_1_ = 1;
              FUN_0041fd70();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 1;
            }
          }
        }
      }
    }
    else {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiChuushinSen[11] */
/* 0063ef60  FUN_0063ef60  376 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0063ef60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  undefined1 local_6414 [20];
  undefined4 local_6400;
  undefined4 local_63fc;
  int local_63f8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937ecb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  local_63f8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6414,*(undefined4 *)(local_63f8 + 4));
  *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8560) = 0;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  iVar1 = FUN_00451eb0(*(undefined4 *)(local_63f8 + 4),&local_24,1);
  if (iVar1 == 0) {
    local_63fc = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_6400 = FUN_0063f0e0(local_24,local_20,local_1c,local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_63fc = local_6400;
  }
  ExceptionList = local_10;
  return local_63fc;
}




/* vtable slots: CZukeiChuushinSen[3] */
/* 0063f3b0  FUN_0063f3b0  362 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0063f3b0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920cbb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  FUN_0040c0e0(uVar1);
  FUN_00446aa0();
  local_8._0_1_ = 1;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  iVar2 = FUN_0063f520();
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 0xac) = 0;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    FUN_0063cc50();
    *(undefined4 *)(in_ECX + 200) = 1;
    *(undefined4 *)(in_ECX + 0xac) = 0;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
    FUN_00404c80();
    FUN_0056d200();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  ExceptionList = local_10;
  return;
}



