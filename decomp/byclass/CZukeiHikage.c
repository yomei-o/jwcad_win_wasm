/* CZukeiHikage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiHikage[1] */
/* 0068d2c0  FUN_0068d2c0  68 bytes, 0 callers */

undefined4 FUN_0068d2c0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0068d1e0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1ea0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiHikage[6] */
/* 0068d310  FUN_0068d310  879 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0068d487) */

void FUN_0068d310(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined8 uVar3;
  undefined2 local_1a8 [202];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093af66;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8._0_1_ = 1;
    FUN_0040c0e0();
    FUN_0044dd90();
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 0) {
      FUN_004efbb0(0x1594,0,0);
      if (*(int *)(*(int *)(in_ECX + 4) + 0x17f0) != 0) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x17f0) = 0;
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797df8();
      }
    }
    else {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 4) {
        local_1a8[0] = 0;
        FUN_005977f0(0x1833);
        local_8._0_1_ = 2;
        uVar2 = FUN_00404920();
        uVar3 = *(undefined8 *)(*(int *)(in_ECX + 4) + 0x8320);
        FUN_005977f0(0x1833);
        uVar2 = FUN_00404920(uVar3,uVar2);
        FUN_0059f750(local_1a8,L"         %.3lf(%s)  %.3lf(%s)",
                     *(undefined8 *)(*(int *)(in_ECX + 4) + 0x8318),uVar2);
        FUN_00404770();
        local_8._0_1_ = 1;
        FUN_00404770();
        FUN_004efc30(0x151b,local_1a8,0);
      }
      else {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 5) {
          FUN_004efbb0(0x1595,0,0);
        }
        else {
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 6) {
            FUN_004efbb0(0x159f,0,0);
          }
          else {
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 7) {
              FUN_004efbb0(0x159b,0,0);
            }
            else {
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 9) {
                FUN_004efbb0(0x15ce,0,0);
              }
              else {
                FUN_004efbb0(0x151b,0,0);
              }
            }
          }
        }
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x18))(param_1);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[16] */
/* 0068d680  FUN_0068d680  217 bytes, 0 callers */

undefined4 FUN_0068d680(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0x2c] == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) != 5) {
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) != 6) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) != 9) {
          if (*(char *)(in_ECX[1] + 0x859c) != '\0') {
            (**(code **)(*in_ECX + 0x7c))();
            return 1;
          }
          return 0;
        }
      }
    }
    uVar1 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_0054b780(uVar1);
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 1;
  }
  else {
    uVar1 = (**(code **)(*(int *)in_ECX[0x2c] + 0x40))();
  }
  return uVar1;
}




/* vtable slots: CZukeiHikage[0] */
/* 0068d760  FUN_0068d760  16 bytes, 0 callers */

undefined ** FUN_0068d760(void)

{
  return &PTR_s_CZukeiHikage_00978fcc;
}




/* vtable slots: CZukeiHikage[25] */
/* 0068e190  FUN_0068e190  661 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0068e190(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 local_63f4;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b098;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8._0_1_ = 1;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    iVar1 = FUN_00691d50();
    if (iVar1 < -9) {
      uVar2 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_0054b780(uVar2);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (((*(int *)(in_ECX + 0x1478) == 0) || (*(int *)(*(int *)(in_ECX + 0xa8) + 0x4a4f8) != 0)
             ) || (iVar1 = FUN_004f60a0(0x15e2,1,0xffffffff), iVar1 == 1)) {
      iVar1 = FUN_004121b0(400);
      local_8._0_1_ = 2;
      if (iVar1 == 0) {
        local_63f4 = 0;
      }
      else {
        local_63f4 = FUN_006936a0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0xa8),
                                  *(undefined4 *)(in_ECX + 0xb4));
      }
      *(undefined4 *)(in_ECX + 0xb0) = local_63f4;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      uVar2 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_0054b780(uVar2);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    FUN_0068d770();
    if (*(int *)(in_ECX + 0xb0) != 0) {
      if (*(int **)(in_ECX + 0xb0) != (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 0xb0) + 4))(1);
      }
      *(undefined4 *)(in_ECX + 0xb0) = 0;
    }
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[26] */
/* 0068e430  FUN_0068e430  234 bytes, 1 callers */

void FUN_0068e430(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093279f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    iVar1 = FUN_00691d50(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    if (iVar1 < 1) {
      uVar2 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_0054b780(uVar2);
    }
    else {
      iVar1 = FUN_004121b0(0x15a0);
      local_8 = 0;
      if (iVar1 == 0) {
        local_1c = 0;
      }
      else {
        local_1c = FUN_006989e0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0xa8),
                                *(undefined4 *)(in_ECX + 0xb4));
      }
      *(undefined4 *)(in_ECX + 0xb0) = local_1c;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x68))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[27] */
/* 0068e520  FUN_0068e520  234 bytes, 1 callers */

void FUN_0068e520(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093279f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    iVar1 = FUN_00691d50(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    if (iVar1 < 1) {
      uVar2 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_0054b780(uVar2);
    }
    else {
      iVar1 = FUN_004121b0(0x9e0);
      local_8 = 0;
      if (iVar1 == 0) {
        local_1c = 0;
      }
      else {
        local_1c = FUN_0069c7c0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0xa8),
                                *(undefined4 *)(in_ECX + 0xb4));
      }
      *(undefined4 *)(in_ECX + 0xb0) = local_1c;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x6c))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[28] */
/* 0068e610  FUN_0068e610  282 bytes, 0 callers */

void FUN_0068e610(void)

{
  int in_ECX;
  undefined1 *puVar1;
  undefined1 local_2c [20];
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a02d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    puVar1 = local_18;
    local_14 = in_ECX;
    FUN_00404c80(puVar1,DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    FUN_004fca20();
    FUN_0054d140(puVar1);
    FUN_00404540();
    FUN_00404c80();
    FUN_004fca20();
    FUN_0054d070();
    FUN_00404c80();
    FUN_004fca20();
    FUN_0054cfa0();
    *(undefined4 *)(*(int *)(local_14 + 4) + 0x82ec) = 4;
    FUN_00691600();
    *(undefined1 *)(*(int *)(local_14 + 4) + 0x859c) = 1;
    FUN_0079dea2(*(undefined4 *)(local_14 + 4));
    local_8 = 0;
    (**(code **)(**(int **)(local_14 + 4) + 0x19c))(local_2c);
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x70))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[29] */
/* 0068e730  FUN_0068e730  48 bytes, 0 callers */

void FUN_0068e730(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb0) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x74))();
  }
  return;
}




/* vtable slots: CZukeiHikage[30] */
/* 0068e760  FUN_0068e760  340 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0068e760(void)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
    if (*(int *)(local_63e8 + 0xb4) != 0) {
      uVar2 = *(undefined8 *)(*(int *)(local_63e8 + 4) + 0x83b0);
      FUN_00404c80(uVar2);
      FUN_004fca20();
      FUN_0054cc50(uVar2);
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xbc) = 0;
    }
    *(undefined4 *)(local_63e8 + 0xb4) = 0;
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x78))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[31] */
/* 0068e8c0  FUN_0068e8c0  513 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0068e8c0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b0f6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    if (*(char *)(*(int *)(local_63e8 + 4) + 0x859c) != '\0') {
      local_63ec = *(int *)(local_63e8 + 4);
      if (local_63ec == 0) {
        local_63f0 = 0;
      }
      else {
        local_63f0 = local_63ec + 0x88;
      }
      FUN_0060b020(local_63f0,*(undefined4 *)(local_63e8 + 4),0);
      local_8._0_1_ = 2;
      FUN_004578a0(0);
      *(undefined1 *)(*(int *)(local_63e8 + 4) + 0x859c) = 0;
      local_8._0_1_ = 1;
      FUN_0060b110();
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 7) {
      FUN_0044c830(local_6404,*(undefined4 *)(local_63e8 + 4));
      *(undefined4 *)(local_63e8 + 0xb4) = 0;
    }
    uVar2 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_0054b780(uVar2);
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 0) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_00797df8();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x7c))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[32] */
/* 0068ead0  FUN_0068ead0  61 bytes, 0 callers */

void FUN_0068ead0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb0) == 0) {
    FUN_006908d0();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x80))();
  }
  return;
}




/* vtable slots: CZukeiHikage[33] */
/* 0068eb10  FUN_0068eb10  51 bytes, 0 callers */

void FUN_0068eb10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb0) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0x84))();
  }
  return;
}




/* vtable slots: CZukeiHikage[12] */
/* 0068f840  FUN_0068f840  312 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0068f840(void)

{
  int iVar1;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  undefined4 local_ec;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093365b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 0) {
    if (*(int *)(local_63e8 + 0xac) != 0) {
      local_ec = 1;
      FUN_0044b2c0(local_6400,*(undefined4 *)(local_63e8 + 4),*(undefined4 *)(local_63e8 + 0xac),1);
      *(undefined4 *)(local_63e8 + 0xac) = 0;
    }
    FUN_00404c80();
    FUN_004fca20();
    FUN_00797df8();
  }
  local_63ec = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiHikage[9] */
/* 0068f980  FUN_0068f980  1849 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0068f980(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 local_6420 [4];
  undefined4 local_641c;
  undefined4 local_6418;
  undefined1 local_6414 [20];
  int local_6400;
  undefined4 local_63fc;
  int local_63f8;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b1cb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) != 0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xb0) + 0x24))(param_1,param_2,param_3,param_4,param_5)
    ;
    ExceptionList = local_10;
    return uVar1;
  }
  local_63f8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8560) = 0;
  FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
  *(undefined4 *)(local_63f8 + 0xac) = 0;
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 0) {
LAB_0068fad9:
    local_63fc = 0;
    iVar2 = FUN_0044a270(3,*(undefined4 *)(local_63f8 + 4),&param_2,&local_63fc,0);
    if (iVar2 == 0) {
      local_6418 = 0;
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_6418;
    }
    iVar2 = FUN_0079d98a();
    if (iVar2 == 0) {
      FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
      local_641c = 0;
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_641c;
    }
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) != 0) {
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) != 5) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 6) {
          FUN_0044c830(local_6414,*(undefined4 *)(local_63f8 + 4));
          *(undefined4 *)(local_63f8 + 0xb4) = 0;
          FUN_00420110();
          *(int *)(local_63f8 + 0xb4) = local_63f8 + 0xb8;
          local_6400 = FUN_00541130();
          if (local_6400 < 0) {
            FUN_00404c80();
            FUN_004fca20();
            FUN_0054b780();
            *(undefined4 *)(local_63f8 + 0xb4) = 0;
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = local_8 & 0xffffff00;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
          FUN_00447b90(local_6414,2,*(undefined4 *)(local_63f8 + 4),local_63fc,1,1);
          if (0 < local_6400) {
            FUN_00404c80();
            FUN_004fca20();
            FUN_0054b780();
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = local_8 & 0xffffff00;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
          FUN_00404c80();
          FUN_004fca20();
          FUN_0054b780();
          uVar5 = *(undefined8 *)(*(int *)(local_63f8 + 4) + 0x83b8);
          FUN_00404c80(uVar5);
          FUN_004fca20();
          FUN_0054cc50(uVar5);
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = local_8 & 0xffffff00;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        goto LAB_0068feef;
      }
    }
    uVar5 = CONCAT44(param_5,param_4);
    uVar1 = local_63fc;
    uVar3 = param_2;
    uVar4 = param_3;
    FUN_00404c80(local_63fc,param_2,param_3,param_4,param_5);
    iVar2 = FUN_004fca20();
    FUN_00692820(local_6420,*(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xbc),uVar1,uVar3,uVar4,uVar5)
    ;
    FUN_00404540();
    FUN_00404c80();
    FUN_004fca20();
    FUN_0054b780();
    FUN_00404c80();
    FUN_004fca20();
    FUN_00797df8();
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 5) goto LAB_0068fad9;
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 6) goto LAB_0068fad9;
LAB_0068feef:
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 7) {
      FUN_0053eca0(*(undefined4 *)(local_63f8 + 0xb4),param_2,param_3,param_4,param_5);
      uVar5 = *(undefined8 *)(*(int *)(local_63f8 + 4) + 0x83b8);
      FUN_00404c80(uVar5);
      FUN_004fca20();
      FUN_0054cc50(uVar5);
      FUN_00404c80();
      FUN_004fca20();
      FUN_0054b780();
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 9) {
        FUN_0068d8c0(param_2,param_3,param_4,param_5);
        FUN_00404c80();
        FUN_004fca20();
        FUN_0054b780();
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukeiHikage[11] */
/* 006900c0  FUN_006900c0  1319 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006900c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 *puVar4;
  undefined1 local_6410 [4];
  undefined4 local_640c;
  undefined4 local_6408;
  undefined4 local_6404;
  undefined1 local_6400 [4];
  undefined4 local_63fc;
  int local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
  undefined4 local_63ec;
  undefined4 local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b226;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    local_63f8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
    local_8._0_1_ = 1;
    local_63f4 = param_2;
    local_63f0 = param_3;
    local_63ec = param_4;
    local_63e8 = param_5;
    local_63fc = 0;
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) == 0) {
      iVar3 = FUN_0044a270(3,*(undefined4 *)(local_63f8 + 4),&local_63f4,&local_63fc,0);
      if (iVar3 == 0) {
        local_6404 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = local_6404;
      }
      else {
        FUN_00692820(local_6400,1,local_63fc,local_63f4,local_63f0,local_63ec,local_63e8);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_00404c80();
        iVar3 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) == 0) {
          cVar1 = FUN_004640c0(&DAT_00956338,local_6400);
          if (cVar1 != '\0') {
            puVar4 = local_6400;
            FUN_00404c80(puVar4);
            FUN_004fca20();
            FUN_00404860(puVar4);
            FUN_00404c80(0);
            FUN_004fca20();
            FUN_007955d2();
          }
        }
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797df8();
        local_6408 = 0;
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = local_6408;
      }
    }
    else {
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) == 5) {
        iVar3 = FUN_0044a270(3,*(undefined4 *)(local_63f8 + 4),&local_63f4,&local_63fc,0);
        if (iVar3 == 0) {
          local_640c = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = local_640c;
        }
        else {
          FUN_00692820(local_6410,4,local_63fc,local_63f4,local_63f0,local_63ec,local_63e8);
          FUN_00404540();
          uVar2 = 0;
          FUN_00404c80(0);
          FUN_004fca20();
          FUN_0054b780(uVar2);
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
      }
      else {
        FUN_00404c80();
        iVar3 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) == 9) {
          iVar3 = FUN_00451eb0(*(undefined4 *)(local_63f8 + 4),&local_63f4,1);
          if (iVar3 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
          else {
            FUN_0068d8c0(local_63f4,local_63f0,local_63ec,local_63e8);
            uVar2 = 0;
            FUN_00404c80(0);
            FUN_004fca20();
            FUN_0054b780(uVar2);
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
        }
        else {
          uVar2 = FUN_0068f980(param_1,local_63f4,local_63f0,local_63ec,local_63e8);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
    }
  }
  else {
    uVar2 = (**(code **)(**(int **)(in_ECX + 0xb0) + 0x2c))(param_1,param_2,param_3,param_4,param_5)
    ;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiHikage[4] */
/* 006905f0  FUN_006905f0  466 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006905f0(void)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    if (*(int *)(in_ECX + 0xb4) == 0) {
      FUN_00404c80(local_14);
      FUN_004fca20();
      fVar2 = (float10)FUN_0054d070();
      *(double *)(*(int *)(local_63e8 + 4) + 0x83b0) = (double)fVar2;
    }
    else {
      FUN_00404c80(local_14);
      FUN_004fca20();
      fVar2 = (float10)FUN_0054d070();
      *(double *)(*(int *)(local_63e8 + 4) + 0x83b8) = (double)fVar2;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_0054cfa0();
    *(double *)(*(int *)(local_63e8 + 4) + 0x83c0) = (double)fVar2;
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_0054d0f0();
    *(double *)(*(int *)(local_63e8 + 4) + 0x83c8) = (double)fVar2;
    FUN_00404c80();
    FUN_004fca20();
    uVar1 = FUN_0054d110();
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x83d0) = uVar1;
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044de00(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_63fc);
  FUN_00449d60(local_63fc,*(undefined4 *)(local_63e8 + 4),1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[3] */
/* 006907d0  FUN_006907d0  249 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006907d0(void)

{
  int in_ECX;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a53b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb0) == 0) {
    local_63e8 = in_ECX;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb0) + 0xc))(local_14);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikage[5] */
/* 006908d0  FUN_006908d0  3373 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006908d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined1 local_6768 [8];
  undefined1 local_6760 [8];
  undefined1 local_6758 [8];
  double local_6750;
  double local_6748;
  double local_6740;
  double local_6738;
  double local_6730;
  double local_6728;
  double local_6720;
  double local_6718;
  double local_6710;
  int local_6708;
  int local_6704;
  int local_6700;
  int local_66fc;
  undefined4 local_66f8;
  undefined4 local_66f4;
  int local_66f0;
  int local_66ec;
  undefined4 local_66e8;
  int local_66e4;
  undefined4 local_66e0;
  undefined4 local_66dc;
  int local_66d8;
  undefined4 local_66d4;
  undefined1 local_66d0 [8];
  int local_66c8;
  int local_66c4;
  int local_66c0;
  int local_66bc;
  undefined4 local_66b8;
  undefined4 local_66b4;
  int local_66b0;
  int local_66ac;
  int local_66a8;
  int local_66a4;
  undefined4 local_66a0;
  double local_669c;
  int local_6694;
  int local_6690;
  int local_668c;
  int local_6688;
  int local_6684;
  int local_6680;
  int local_667c;
  int local_6678;
  double local_6674;
  double local_666c;
  undefined1 local_6664 [20];
  int local_6650;
  double local_664c;
  int local_6644;
  int local_6640;
  uint local_663c;
  uint local_6638;
  int local_6634;
  double local_6630;
  int local_6628;
  int *local_6624;
  int local_6620;
  undefined1 local_65f4;
  undefined2 local_65f2;
  undefined1 local_65ee;
  undefined1 local_65ed;
  undefined4 local_65b4;
  undefined4 local_65b0;
  undefined4 local_65ac;
  undefined4 local_65a8;
  undefined8 local_65a4;
  undefined4 local_659c;
  undefined4 local_6598;
  undefined4 local_6594;
  undefined4 local_6590;
  undefined8 local_658c;
  undefined1 local_6584 [25696];
  undefined8 local_124;
  undefined8 local_8c;
  undefined1 local_84 [24];
  undefined1 local_6c [24];
  undefined1 local_54 [24];
  undefined1 local_3c [24];
  CRect local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b297;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_66a0 = FUN_0040c0e0(local_14);
  FUN_0079dea2();
  local_8 = 0;
  FUN_00446aa0();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004fb9f0();
  FUN_004bb680(local_6664,0);
  local_6650 = 0;
  for (local_6628 = 0; local_6628 < 0x10; local_6628 = local_6628 + 1) {
    if (*(int *)(local_6620 + 0x3e0 + local_6628 * 4) !=
        *(int *)(*(int *)(local_6620 + 4) + 0x242c + local_6628 * 4)) {
      local_6650 = 1;
    }
    for (local_6634 = 0; local_6634 < 0x10; local_6634 = local_6634 + 1) {
      if (*(int *)(local_6620 + 0x460 + local_6628 * 0x80 + local_6634 * 4) !=
          *(int *)(*(int *)(local_6620 + 4) + 0x182c + local_6628 * 0x40 + local_6634 * 4)) {
        local_6650 = 1;
      }
    }
  }
  if (local_6650 != 0) {
    FUN_00691600();
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined8 *)(*(int *)(local_6620 + 4) + 0x8318) =
       *(undefined8 *)(*(int *)(iVar1 + 0x1a0) + 0xc0);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined8 *)(*(int *)(local_6620 + 4) + 0x8320) =
       *(undefined8 *)(*(int *)(iVar1 + 0x1a0) + 200);
  local_66e8 = FUN_00572c70();
  while (local_6624 = (int *)FUN_00572cd0(&local_66e8,0), local_6624 != (int *)0x0) {
    local_66a4 = *(int *)(local_6620 + 4);
    if (local_66a4 == 0) {
      local_66a8 = 0;
    }
    else {
      local_66a8 = local_66a4 + 0x88;
    }
    (**(code **)(*local_6624 + 0x3c))(local_6664);
    iVar1 = FUN_0079d98a(&PTR_s_CData3DSen_009fe0b0);
    if ((iVar1 != 0) && ((short)local_6624[0x11] != 0)) {
      FUN_0060d840();
      local_8._0_1_ = 2;
      local_65f4 = 2;
      local_65f2 = 5;
      local_65ee = *(undefined1 *)
                    (*(int *)(local_6620 + 4) + 0x24ec +
                    *(int *)(*(int *)(local_6620 + 4) + 0x256c) * 4);
      local_65ed = *(undefined1 *)(*(int *)(local_6620 + 4) + 0x256c);
      local_65a4 = *(double *)(local_6620 + 0x1460);
      local_658c = *(double *)(local_6620 + 0x1460);
      local_66ac = *(int *)(local_6620 + 4);
      if (local_66ac == 0) {
        local_66b0 = 0;
      }
      else {
        local_66b0 = local_66ac + 0x88;
      }
      FUN_004417c0(local_6664,local_66b0,local_6584);
      if (*(double *)(local_6620 + 0x1460) <= -1e-07 && *(double *)(local_6620 + 0x1460) != -1e-07)
      {
        FUN_0060d840();
        local_8._0_1_ = 3;
        FUN_0060d840();
        local_8._0_1_ = 4;
        puVar2 = (undefined4 *)
                 FUN_00498860(local_54,local_65b4,local_65b0,local_65ac,local_65a8,
                              SUB84(local_65a4,0),local_65a4._4_4_);
        FUN_00498860(local_3c,*puVar2,puVar2[1],puVar2[2],puVar2[3],puVar2[4],puVar2[5]);
        local_124 = 0;
        local_6680 = *(int *)(local_6620 + 4);
        if (local_6680 == 0) {
          local_6684 = 0;
        }
        else {
          local_6684 = local_6680 + 0x88;
        }
        FUN_004417c0(local_6664,local_6684,local_6584);
        puVar2 = (undefined4 *)
                 FUN_00498860(local_6c,local_659c,local_6598,local_6594,local_6590,
                              SUB84(local_658c,0),local_658c._4_4_);
        FUN_00498860(local_84,*puVar2,puVar2[1],puVar2[2],puVar2[3],puVar2[4],puVar2[5]);
        local_8c = 0;
        local_6688 = *(int *)(local_6620 + 4);
        if (local_6688 == 0) {
          local_668c = 0;
        }
        else {
          local_668c = local_6688 + 0x88;
        }
        FUN_004417c0(local_6664,local_668c,local_6584);
        local_8._0_1_ = 3;
        FUN_0043d040();
        local_8._0_1_ = 2;
        FUN_0043d040();
      }
      local_6638 = (uint)*(byte *)((int)local_6624 + 0x2f);
      local_663c = (uint)*(byte *)((int)local_6624 + 0x2e);
      if (*(double *)(local_6620 + 0x1480 + local_6638 * 0x90 + local_663c * 8) <= 0.0) {
        local_6710 = -*(double *)(local_6620 + 0x1480 + local_6638 * 0x90 + local_663c * 8);
      }
      else {
        local_6710 = *(double *)(local_6620 + 0x1480 + local_6638 * 0x90 + local_663c * 8);
      }
      if (1e-07 < local_6710) {
        local_65f4 = 3;
        local_65f2 = 6;
        local_65a4 = (*(double *)(local_6620 + 0x1480 + local_6638 * 0x90 + local_663c * 8) * 1000.0
                     ) / *(double *)
                          (*(int *)(local_6620 + 4) + 0x2578 +
                          *(int *)(*(int *)(local_6620 + 4) + 0x256c) * 8);
        local_658c = (*(double *)(local_6620 + 0x1480 + local_6638 * 0x90 + local_663c * 8) * 1000.0
                     ) / *(double *)
                          (*(int *)(local_6620 + 4) + 0x2578 +
                          *(int *)(*(int *)(local_6620 + 4) + 0x256c) * 8);
        local_6690 = *(int *)(local_6620 + 4);
        if (local_6690 == 0) {
          local_6694 = 0;
        }
        else {
          local_6694 = local_6690 + 0x88;
        }
        FUN_004417c0(local_6664,local_6694,local_6584);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_0043d040();
    }
  }
  FUN_00447080();
  local_8._0_1_ = 5;
  FUN_004db560(local_66d0,1,0xff);
  local_66d4 = FUN_0079efbc();
  local_666c = 30.0;
  local_6674 = 30.0;
  local_6630 = 20.0;
  local_664c = (((*(double *)(local_6620 + 0x1470) + 90.0) -
                *(double *)(*(int *)(local_6620 + 4) + 0x8318)) * 3.141592653589793) / 180.0;
  fVar3 = (float10)FUN_008f8eb0(local_664c);
  local_6718 = (double)fVar3;
  local_66d8 = (int)(local_6718 * local_6630 + local_666c);
  fVar3 = (float10)FUN_008f8f00(local_664c);
  local_6720 = (double)fVar3;
  local_66e4 = (int)(local_6674 - local_6720 * local_6630);
  FUN_0041c8d0(local_66d8,local_66e4);
  FUN_004044d0();
  FUN_004044d0();
  FUN_00416040((int)(local_666c - local_6630),(int)(local_6674 - local_6630),
               (int)(local_666c + local_6630),(int)(local_6674 + local_6630));
  CRect::NormalizeRect(local_24);
  std::allocator<char>::allocator<char>((allocator<char> *)local_24);
  FUN_004b6f10();
  local_669c = (local_664c + 3.141592653589793) - 0.52;
  fVar3 = (float10)FUN_008f8eb0(local_669c);
  local_6728 = (double)fVar3;
  local_6644 = (int)(local_6728 * local_6630 + local_666c);
  fVar3 = (float10)FUN_008f8f00(local_669c);
  local_6730 = (double)fVar3;
  local_6640 = (int)(local_6674 - local_6730 * local_6630);
  local_66e0 = local_66b8;
  local_66dc = local_66b4;
  CStringT<>(local_6758,local_66b8,local_66b4);
  local_66f0 = local_6644;
  local_66ec = local_6640;
  FUN_004b7a50(local_6644,local_6640);
  local_669c = local_664c + 3.141592653589793 + 0.52;
  fVar3 = (float10)FUN_008f8eb0(local_669c);
  local_6738 = (double)fVar3;
  local_667c = (int)(local_6738 * local_6630 + local_666c);
  fVar3 = (float10)FUN_008f8f00(local_669c);
  local_6740 = (double)fVar3;
  local_6678 = (int)(local_6674 - local_6740 * local_6630);
  local_66f8 = local_66b8;
  local_66f4 = local_66b4;
  CStringT<>(local_6760,local_66b8,local_66b4);
  local_6700 = local_667c;
  local_66fc = local_6678;
  FUN_004b7a50(local_667c,local_6678);
  local_6708 = local_6644;
  local_6704 = local_6640;
  CStringT<>(local_6768,local_6644,local_6640);
  local_6630 = local_6630 * 0.5;
  fVar3 = (float10)FUN_008f8eb0(local_664c);
  local_6750 = (double)fVar3;
  local_6644 = (int)(local_666c - local_6750 * local_6630);
  fVar3 = (float10)FUN_008f8f00(local_664c);
  local_6748 = (double)fVar3;
  local_66bc = (int)(local_6748 * local_6630 + local_6674);
  local_66c0 = local_6644;
  local_6640 = local_66bc;
  FUN_004b7a50(local_6644,local_66bc);
  local_66c8 = local_667c;
  local_66c4 = local_6678;
  FUN_004b7a50(local_667c,local_6678);
  FUN_0079efbc();
  local_8._0_1_ = 1;
  FUN_0041c990();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



