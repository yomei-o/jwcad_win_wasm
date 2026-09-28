/* CZukeiTenkuu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiTenkuu[1] */
/* 00733df0  FUN_00733df0  68 bytes, 0 callers */

undefined4 FUN_00733df0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00733d80();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x2600);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiTenkuu[6] */
/* 00734240  FUN_00734240  1188 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x007343df) */
/* WARNING: Removing unreachable block (ram,0x00734336) */

void FUN_00734240(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  undefined8 uVar4;
  undefined2 local_278 [202];
  undefined2 local_e4 [104];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940ff0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x15c) == 0) {
    if (*(double *)(in_ECX + 0x178) != (double)DAT_00a0bed0) {
      *(double *)(in_ECX + 0x178) = (double)DAT_00a0bed0;
      FUN_00404c80(local_14);
      iVar1 = FUN_004fca20();
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xbc);
      FUN_00404c80(uVar2);
      FUN_004fca20();
      FUN_005ed620(uVar2);
    }
    local_278[0] = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 0) {
      FUN_004efbb0(0x1594,0,0);
    }
    else {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 1) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005efa00();
        *(double *)(*(int *)(in_ECX + 4) + 0x83e8) = (double)fVar3;
        local_e4[0] = 0;
        FUN_005977f0(0x14b4);
        FUN_00404920();
        FUN_005cf710();
        FUN_00404770();
        FUN_005977f0(0x1650);
        FUN_00404920();
        FUN_00661050();
        FUN_00404770();
        if (*(int *)(in_ECX + 0x1a4) == 0) {
          FUN_004efbb0(0x164e,local_e4,0);
        }
        else {
          FUN_004efbb0(0x164f,local_e4,0);
        }
      }
      else {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 2) {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_005efa00();
          if ((0.4 <= (double)fVar3) || (*(int *)(in_ECX + 0x1a0) != 0)) {
            FUN_004efbb0(0x1651,local_278,0);
          }
          else {
            FUN_004efbb0(0x15b8,0,0);
          }
        }
        else {
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 4) {
            FUN_005977f0(0x1833);
            local_8 = 0;
            uVar2 = FUN_00404920();
            uVar4 = *(undefined8 *)(*(int *)(in_ECX + 4) + 0x8320);
            FUN_005977f0(0x1833);
            uVar2 = FUN_00404920(uVar4,uVar2);
            FUN_0059f750(local_278,L"         %.3lf(%s)  %.3lf(%s)",
                         *(undefined8 *)(*(int *)(in_ECX + 4) + 0x8318),uVar2);
            FUN_00404770();
            local_8 = 0xffffffff;
            FUN_00404770();
            FUN_004efc30(0x151b,local_278,0);
          }
          else {
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 5) {
              if (*(int *)(in_ECX + 0x1b0) == 0) {
                FUN_004efbb0(0x16a1,0,0);
              }
              if (*(int *)(in_ECX + 0x1b0) == 1) {
                FUN_004efbb0(0x16a2,0,0);
              }
              if (*(int *)(in_ECX + 0x1b0) == 2) {
                FUN_004efbb0(0x16a3,0,0);
              }
            }
            else {
              FUN_004efbb0(0x151b,0,0);
            }
          }
        }
      }
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x18))(param_1);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTenkuu[16] */
/* 007346f0  FUN_007346f0  518 bytes, 0 callers */

undefined4 FUN_007346f0(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0x57] == 0) {
    if (*(char *)(in_ECX[1] + 0x859c) == '\0') {
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 0) {
        uVar1 = 0;
      }
      else {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 1) {
          FUN_00738ac0(0);
          if (in_ECX[0x6a] < 1) {
            uVar1 = 0;
            FUN_00404c80(0);
            FUN_004fca20();
            FUN_005ed620(uVar1);
            uVar1 = 1;
          }
          else {
            in_ECX[0x6a] = in_ECX[0x6a] + -1;
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            iVar2 = *(int *)(*(int *)(iVar2 + 0x1a0) + 200);
            if (1 < iVar2) {
              iVar2 = iVar2 + -1;
              FUN_00404c80(iVar2);
              FUN_004fca20();
              FUN_005ef750(iVar2);
            }
            uVar1 = 0;
          }
        }
        else {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 2) {
            FUN_00738ac0(0);
            uVar1 = 1;
            FUN_00404c80(1);
            FUN_004fca20();
            FUN_005ed620(uVar1);
            uVar1 = 1;
          }
          else {
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 5) {
              if (in_ECX[0x6c] < 1) {
                if (in_ECX[0x6b] < 1) {
                  uVar1 = 0;
                  FUN_00404c80(0);
                  FUN_004fca20();
                  FUN_005ed620(uVar1);
                  uVar1 = 1;
                }
                else {
                  in_ECX[0x6b] = in_ECX[0x6b] + -1;
                  uVar1 = 0;
                }
              }
              else {
                in_ECX[0x6c] = in_ECX[0x6c] + -1;
                uVar1 = 1;
              }
            }
            else {
              uVar1 = 0;
            }
          }
        }
      }
    }
    else {
      (**(code **)(*in_ECX + 0x7c))();
      uVar1 = 1;
    }
  }
  else {
    uVar1 = (**(code **)(*(int *)in_ECX[0x57] + 0x40))();
  }
  return uVar1;
}




/* vtable slots: CZukeiTenkuu[0] */
/* 00734910  FUN_00734910  16 bytes, 0 callers */

undefined ** FUN_00734910(void)

{
  return &PTR_s_CZukeiTenkuu_0097b13c;
}




/* vtable slots: CZukeiTenkuu[25] */
/* 00739310  FUN_00739310  101 bytes, 1 callers */

void FUN_00739310(void)

{
  int in_ECX;
  undefined4 uVar1;
  
  if (*(int *)(in_ECX + 0x15c) == 0) {
    *(undefined4 *)(in_ECX + 0x1a0) = 0;
    *(undefined4 *)(in_ECX + 0x1a4) = 0;
    uVar1 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_005ed620(uVar1);
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 100))();
  }
  return;
}




/* vtable slots: CZukeiTenkuu[26] */
/* 00739380  FUN_00739380  101 bytes, 1 callers */

void FUN_00739380(void)

{
  int in_ECX;
  undefined4 uVar1;
  
  if (*(int *)(in_ECX + 0x15c) == 0) {
    *(undefined4 *)(in_ECX + 0x1a0) = 0;
    *(undefined4 *)(in_ECX + 0x1a4) = 1;
    uVar1 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_005ed620(uVar1);
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x68))();
  }
  return;
}




/* vtable slots: CZukeiTenkuu[27] */
/* 007393f0  FUN_007393f0  127 bytes, 0 callers */

void FUN_007393f0(void)

{
  int in_ECX;
  undefined4 uVar1;
  
  if (*(int *)(in_ECX + 0x15c) == 0) {
    *(undefined4 *)(in_ECX + 0x1a0) = 0;
    *(undefined4 *)(in_ECX + 0x1a4) = 0;
    *(undefined4 *)(in_ECX + 0x1ac) = 0;
    *(undefined4 *)(in_ECX + 0x1b0) = 0;
    uVar1 = 5;
    FUN_00404c80(5);
    FUN_004fca20();
    FUN_005ed620(uVar1);
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x6c))();
  }
  return;
}




/* vtable slots: CZukeiTenkuu[28] */
/* 00739470  FUN_00739470  260 bytes, 0 callers */

void FUN_00739470(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 uVar3;
  undefined1 local_28 [20];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093069d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x15c) == 0) {
    local_14 = in_ECX;
    FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    FUN_004fca20();
    fVar2 = (float10)FUN_005efd00();
    *(double *)(local_14 + 0x1b70) = (double)fVar2;
    *(undefined4 *)(*(int *)(local_14 + 4) + 0x82ec) = 4;
    iVar1 = FUN_0073b870();
    if (iVar1 == 0) {
      uVar3 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_005ed620(uVar3);
    }
    else {
      *(undefined1 *)(*(int *)(local_14 + 4) + 0x859c) = 1;
      FUN_0079dea2(*(undefined4 *)(local_14 + 4));
      local_8 = 0;
      (**(code **)(**(int **)(local_14 + 4) + 0x19c))(local_28);
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x70))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTenkuu[29] */
/* 00739580  FUN_00739580  121 bytes, 1 callers */

void FUN_00739580(void)

{
  int in_ECX;
  undefined4 uVar1;
  
  if (*(int *)(in_ECX + 0x15c) == 0) {
    *(undefined4 *)(in_ECX + 0x1a0) = 1;
    *(undefined4 *)(in_ECX + 0x1a4) = 0;
    uVar1 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_005ed620(uVar1);
    DAT_00a0cc6c = 0;
    DAT_00a0cc74 = 0;
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x74))();
  }
  return;
}




/* vtable slots: CZukeiTenkuu[30] */
/* 00739600  FUN_00739600  48 bytes, 0 callers */

void FUN_00739600(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x15c) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x78))();
  }
  return;
}




/* vtable slots: CZukeiTenkuu[31] */
/* 00739630  FUN_00739630  616 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00739630(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  int local_63f4;
  int local_63ec;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941216;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x15c) == 0) {
    FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8._0_1_ = 1;
    if (*(char *)(*(int *)(in_ECX + 4) + 0x859c) == '\0') {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      local_63ec = *(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc);
      if (local_63ec == 5) {
        local_63ec = 0;
      }
      local_63ec = local_63ec + -1;
      if (local_63ec < 0) {
        local_63ec = 0;
      }
      iVar1 = local_63ec;
      FUN_00404c80(local_63ec);
      FUN_004fca20();
      FUN_005ed620(iVar1);
      if (local_63ec == 0) {
        FUN_00738ac0(0);
        *(undefined4 *)(in_ECX + 0x1a8) = 0;
      }
      else if (local_63ec == 1) {
        FUN_00738ac0(0);
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      if (*(int *)(in_ECX + 4) == 0) {
        local_63f4 = 0;
      }
      else {
        local_63f4 = *(int *)(in_ECX + 4) + 0x88;
      }
      FUN_0060b020(local_63f4,*(undefined4 *)(in_ECX + 4),0);
      local_8._0_1_ = 2;
      FUN_004578a0(0);
      *(undefined1 *)(*(int *)(in_ECX + 4) + 0x859c) = 0;
      uVar2 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_005ed620(uVar2);
      FUN_00404c80();
      FUN_0056d7d0();
      local_8._0_1_ = 1;
      FUN_0060b110();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x7c))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTenkuu[32] */
/* 007398a0  FUN_007398a0  61 bytes, 0 callers */

void FUN_007398a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x15c) == 0) {
    FUN_0073aae0();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x80))();
  }
  return;
}




/* vtable slots: CZukeiTenkuu[33] */
/* 007398e0  FUN_007398e0  113 bytes, 0 callers */

void FUN_007398e0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x15c) == 0) {
    if (*(int *)(in_ECX + 0x1a0) != 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xe58) == 1) {
        FUN_00739960();
        return;
      }
    }
    FUN_004fb9f0();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0x84))();
  }
  return;
}




/* vtable slots: CZukeiTenkuu[12] */
/* 00739a90  FUN_00739a90  312 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00739a90(void)

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
    if (*(int *)(local_63e8 + 0x158) != 0) {
      local_ec = 1;
      FUN_0044b2c0(local_6400,*(undefined4 *)(local_63e8 + 4),*(undefined4 *)(local_63e8 + 0x158),1)
      ;
      *(undefined4 *)(local_63e8 + 0x158) = 0;
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




/* vtable slots: CZukeiTenkuu[9] */
/* 00739bd0  FUN_00739bd0  1710 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00739bd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_644c [4];
  undefined4 local_6448;
  undefined4 local_6444;
  undefined4 local_642c;
  int local_6428;
  undefined1 local_6424 [25552];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094125b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x15c) == 0) {
    local_6428 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_6428 + 4));
    local_8._0_1_ = 1;
    *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
    FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
    *(undefined4 *)(local_6428 + 0x158) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 0) {
      local_642c = 0;
      iVar1 = FUN_0044a270(3,*(undefined4 *)(local_6428 + 4),&param_2,&local_642c,0);
      if (iVar1 == 0) {
        local_6444 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar1 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
          local_6448 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6444 = local_6448;
        }
        else {
          uVar6 = local_642c;
          uVar2 = param_2;
          uVar3 = param_3;
          uVar4 = param_4;
          uVar5 = param_5;
          FUN_00404c80(local_642c,param_2,param_3,param_4,param_5);
          iVar1 = FUN_004fca20();
          FUN_0074e800(local_644c,*(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xbc),uVar6,uVar2,uVar3,
                       uVar4,uVar5);
          FUN_00404540();
          uVar6 = 0;
          FUN_00404c80(0);
          FUN_004fca20();
          FUN_005ed620(uVar6);
          FUN_00404c80();
          FUN_004fca20();
          FUN_00797df8();
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6444 = 0;
        }
      }
    }
    else {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 1) {
        uVar6 = 2;
        FUN_00404c80(2);
        FUN_004fca20();
        FUN_005ed620(uVar6);
        FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
        FUN_00738ac0(1);
        if (*(int *)(local_6428 + 0x1a0) != 0) {
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xe58) == 1) {
            FUN_00739960();
          }
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6444 = 0;
      }
      else {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 2) {
          FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6444 = 1;
        }
        else {
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 5) {
            if (*(int *)(local_6428 + 0x1b0) == 0) {
              *(undefined4 *)(local_6428 + 0x82c) = 0;
              iVar1 = FUN_0074e1c0(local_6424,param_2,param_3,param_4,param_5);
              if (iVar1 == 0) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return 0;
              }
              *(undefined4 *)(local_6428 + 0x1b0) = 1;
            }
            else if (*(int *)(local_6428 + 0x1b0) == 1) {
              iVar1 = FUN_0074e1c0(local_6424,param_2,param_3,param_4,param_5);
              if (iVar1 == 0) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return 0;
              }
              *(undefined4 *)(local_6428 + 0x1b0) = 2;
            }
            else if (*(int *)(local_6428 + 0x1b0) == 2) {
              *(undefined4 *)(local_6428 + 0x1b0) = 0;
              FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 1;
            }
            FUN_00404c80();
            FUN_0056d7d0();
          }
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            local_6444 = 0;
          }
          else {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            local_6444 = 0;
          }
        }
      }
    }
  }
  else {
    local_6444 = (**(code **)(**(int **)(in_ECX + 0x15c) + 0x24))
                           (param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return local_6444;
}




/* vtable slots: CZukeiTenkuu[11] */
/* 0073a280  FUN_0073a280  1338 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0073a280(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 *puVar4;
  undefined4 local_6400;
  undefined1 local_63fc [4];
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
  puStack_c = &LAB_009412b6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x15c) != 0) {
    uVar2 = (**(code **)(**(int **)(in_ECX + 0x15c) + 0x2c))
                      (param_1,param_2,param_3,param_4,param_5);
    ExceptionList = local_10;
    return uVar2;
  }
  local_63f8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
  local_8._0_1_ = 1;
  local_63f4 = param_2;
  local_63f0 = param_3;
  local_63ec = param_4;
  local_63e8 = param_5;
  local_6400 = 0;
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) == 0) {
    iVar3 = FUN_0044a270(3,*(undefined4 *)(local_63f8 + 4),&local_63f4,&local_6400,0);
    if (iVar3 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    FUN_0074e800(local_63fc,1,local_6400,local_63f4,local_63f0,local_63ec,local_63e8);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    if ((*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) == 0) &&
       (cVar1 = FUN_004640c0(&DAT_00956338,local_63fc), cVar1 != '\0')) {
      puVar4 = local_63fc;
      FUN_00404c80(puVar4);
      FUN_004fca20();
      FUN_00404860(puVar4);
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007955d2();
    }
    FUN_00404c80();
    FUN_004fca20();
    FUN_00797df8();
    local_8._0_1_ = 1;
    FUN_00404540();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return 0;
  }
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) != 1) {
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) != 2) goto LAB_0073a5c3;
  }
  iVar3 = FUN_00451eb0(*(undefined4 *)(local_63f8 + 4),&local_63f4,1);
  if (iVar3 == 1) {
    uVar2 = FUN_00739bd0(param_1,local_63f4,local_63f0,local_63ec,local_63e8);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return uVar2;
  }
LAB_0073a5c3:
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) == 5) {
    if (*(int *)(local_63f8 + 0x1b0) == 0) {
      uVar2 = FUN_00739bd0(param_1,local_63f4,local_63f0,local_63ec,local_63e8);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
    if (*(int *)(local_63f8 + 0x1b0) == 1) {
      uVar2 = FUN_00739bd0(param_1,local_63f4,local_63f0,local_63ec,local_63e8);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
    if ((*(int *)(local_63f8 + 0x1b0) == 2) &&
       (iVar3 = FUN_00451eb0(*(undefined4 *)(local_63f8 + 4),&local_63f4,1), iVar3 == 1)) {
      uVar2 = FUN_00739bd0(param_1,local_63f4,local_63f0,local_63ec,local_63e8);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukeiTenkuu[4] */
/* 0073a7c0  FUN_0073a7c0  268 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0073a7c0(void)

{
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
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044de00(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd20(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_63fc);
  FUN_00449d60(local_63fc,*(undefined4 *)(local_63e8 + 4),1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTenkuu[3] */
/* 0073a8d0  FUN_0073a8d0  524 bytes, 0 callers */

void FUN_0073a8d0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093950d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x15c) == 0) {
    local_14 = in_ECX;
    FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 5) {
      FUN_00737bf0();
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      FUN_00738ac0(0);
      *(undefined4 *)(local_14 + 0xe4) = 0;
      *(undefined4 *)(local_14 + 0xe8) = 0;
      if (DAT_00a0cc6c == 0) {
        if (DAT_00a0becc != 0) {
          *(undefined4 *)(local_14 + 0xe4) = 1;
        }
      }
      else if (DAT_00a0becc == 0) {
        *(undefined4 *)(local_14 + 0xe4) = 1;
      }
      if (DAT_00a0cc74 != 0) {
        *(undefined4 *)(local_14 + 0xe8) = 1;
      }
      DAT_00a0cc74 = 0;
      DAT_00a0cc6c = 0;
      puVar2 = local_28;
      FUN_00404c80(puVar2);
      FUN_004fca20();
      local_24 = FUN_005efea0(puVar2);
      local_8 = 0;
      local_20 = local_24;
      FUN_00404860(local_24);
      local_8 = 0xffffffff;
      FUN_00404540();
      local_18 = 0;
      if (*(int *)(local_14 + 0x1a0) == 0) {
        local_18 = FUN_00748da0();
      }
      else {
        local_18 = FUN_00740440();
      }
      if (0 < local_18) {
        *(int *)(local_14 + 0x1a8) = *(int *)(local_14 + 0x1a8) + 1;
      }
      uVar3 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_005ed620(uVar3);
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      local_1c = *(int *)(*(int *)(iVar1 + 0x1a0) + 200);
      if ((0 < local_1c) && (0 < local_18)) {
        iVar1 = local_1c + 1;
        FUN_00404c80(iVar1);
        FUN_004fca20();
        FUN_005ef750(iVar1);
      }
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0xc))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTenkuu[5] */
/* 0073aae0  FUN_0073aae0  3468 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0073aae0(void)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined1 local_6770 [8];
  undefined1 local_6768 [8];
  undefined1 local_6760 [8];
  double local_6758;
  double local_6750;
  double local_6748;
  double local_6740;
  double local_6738;
  double local_6730;
  double local_6728;
  double local_6720;
  double local_6710;
  double local_6708;
  int local_6700;
  int local_66fc;
  int local_66f8;
  int local_66f4;
  undefined4 local_66f0;
  undefined4 local_66ec;
  int local_66e8;
  int local_66e4;
  undefined4 local_66e0;
  int local_66dc;
  undefined4 local_66d8;
  undefined4 local_66d4;
  int local_66d0;
  undefined4 local_66cc;
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
  int *local_6620;
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
  puStack_c = &LAB_00941327;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_66a0 = FUN_0040c0e0(local_14);
  FUN_0079dea2();
  local_8 = 0;
  FUN_00446aa0();
  local_8._0_1_ = 1;
  FUN_004fb9f0();
  FUN_004bb680(local_6664,0);
  local_6650 = 0;
  for (local_6628 = 0; local_6628 < 0x10; local_6628 = local_6628 + 1) {
    if (local_6620[local_6628 + 700] != *(int *)(local_6620[1] + 0x242c + local_6628 * 4)) {
      local_6650 = 1;
    }
    for (local_6634 = 0; local_6634 < 0x10; local_6634 = local_6634 + 1) {
      if (local_6620[local_6628 * 0x20 + local_6634 + 0x2dc] !=
          *(int *)(local_6620[1] + 0x182c + local_6628 * 0x40 + local_6634 * 4)) {
        local_6650 = 1;
      }
    }
  }
  if ((local_6650 == 0) || (iVar1 = FUN_0073b870(), iVar1 != 0)) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined8 *)(local_6620[1] + 0x8318) = *(undefined8 *)(*(int *)(iVar1 + 0x1a0) + 0xd0);
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined8 *)(local_6620[1] + 0x8320) = *(undefined8 *)(*(int *)(iVar1 + 0x1a0) + 0xd8);
    local_66e0 = FUN_00572c70();
    while (local_6624 = (int *)FUN_00572cd0(&local_66e0,0), local_6624 != (int *)0x0) {
      local_66a4 = local_6620[1];
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
        local_65ee = *(undefined1 *)(local_6620[1] + 0x24ec + *(int *)(local_6620[1] + 0x256c) * 4);
        local_65ed = *(undefined1 *)(local_6620[1] + 0x256c);
        local_6708 = (*(double *)(local_6620 + 0x6dc) * 1000.0) /
                     *(double *)(local_6620[1] + 0x2578 + *(int *)(local_6620[1] + 0x256c) * 8);
        local_66ac = local_6620[1];
        if (local_66ac == 0) {
          local_66b0 = 0;
        }
        else {
          local_66b0 = local_66ac + 0x88;
        }
        local_65a4 = local_6708;
        local_658c = local_6708;
        FUN_004417c0(local_6664,local_66b0,local_6584);
        if (*(double *)(local_6620 + 0x6dc) <= -1e-07 && *(double *)(local_6620 + 0x6dc) != -1e-07)
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
          local_6680 = local_6620[1];
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
          local_6688 = local_6620[1];
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
        if (*(double *)(local_6620 + local_6638 * 0x24 + local_663c * 2 + 0x6f6) <= 0.0) {
          local_6710 = -*(double *)(local_6620 + local_6638 * 0x24 + local_663c * 2 + 0x6f6);
        }
        else {
          local_6710 = *(double *)(local_6620 + local_6638 * 0x24 + local_663c * 2 + 0x6f6);
        }
        if (1e-07 < local_6710) {
          local_65f4 = 3;
          local_65f2 = 6;
          local_65a4 = (*(double *)(local_6620 + local_6638 * 0x24 + local_663c * 2 + 0x6f6) *
                       1000.0) / *(double *)
                                  (local_6620[1] + 0x2578 + *(int *)(local_6620[1] + 0x256c) * 8);
          local_658c = (*(double *)(local_6620 + local_6638 * 0x24 + local_663c * 2 + 0x6f6) *
                       1000.0) / *(double *)
                                  (local_6620[1] + 0x2578 + *(int *)(local_6620[1] + 0x256c) * 8);
          local_6690 = local_6620[1];
          if (local_6690 == 0) {
            local_6694 = 0;
          }
          else {
            local_6694 = local_6690 + 0x88;
          }
          FUN_004417c0(local_6664,local_6694,local_6584);
        }
        local_8._0_1_ = 1;
        FUN_0043d040();
      }
    }
    FUN_0079df60(0,1,0xff);
    local_8._0_1_ = 5;
    local_66cc = FUN_0079efbc();
    local_666c = 30.0;
    local_6674 = 30.0;
    local_6630 = 20.0;
    local_664c = (((*(double *)(local_6620 + 0x6e0) + 90.0) - *(double *)(local_6620[1] + 0x8318)) *
                 3.141592653589793) / 180.0;
    fVar3 = (float10)FUN_008f8eb0(local_664c);
    local_6720 = (double)fVar3;
    local_66d0 = (int)(local_6720 * local_6630 + local_666c);
    fVar3 = (float10)FUN_008f8f00(local_664c);
    local_6728 = (double)fVar3;
    local_66dc = (int)(local_6674 - local_6728 * local_6630);
    FUN_0041c8d0(local_66d0,local_66dc);
    FUN_004044d0();
    FUN_004044d0();
    FUN_00416040((int)(local_666c - local_6630),(int)(local_6674 - local_6630),
                 (int)(local_666c + local_6630),(int)(local_6674 + local_6630));
    CRect::NormalizeRect(local_24);
    std::allocator<char>::allocator<char>((allocator<char> *)local_24);
    FUN_004b6f10();
    local_669c = (local_664c + 3.141592653589793) - 0.52;
    fVar3 = (float10)FUN_008f8eb0(local_669c);
    local_6730 = (double)fVar3;
    local_6644 = (int)(local_6730 * local_6630 + local_666c);
    fVar3 = (float10)FUN_008f8f00(local_669c);
    local_6738 = (double)fVar3;
    local_6640 = (int)(local_6674 - local_6738 * local_6630);
    local_66d8 = local_66b8;
    local_66d4 = local_66b4;
    CStringT<>(local_6760,local_66b8,local_66b4);
    local_66e8 = local_6644;
    local_66e4 = local_6640;
    FUN_004b7a50(local_6644,local_6640);
    local_669c = local_664c + 3.141592653589793 + 0.52;
    fVar3 = (float10)FUN_008f8eb0(local_669c);
    local_6740 = (double)fVar3;
    local_667c = (int)(local_6740 * local_6630 + local_666c);
    fVar3 = (float10)FUN_008f8f00(local_669c);
    local_6748 = (double)fVar3;
    local_6678 = (int)(local_6674 - local_6748 * local_6630);
    local_66f0 = local_66b8;
    local_66ec = local_66b4;
    CStringT<>(local_6768,local_66b8,local_66b4);
    local_66f8 = local_667c;
    local_66f4 = local_6678;
    FUN_004b7a50(local_667c,local_6678);
    local_6700 = local_6644;
    local_66fc = local_6640;
    CStringT<>(local_6770,local_6644,local_6640);
    local_6630 = local_6630 * 0.5;
    fVar3 = (float10)FUN_008f8eb0(local_664c);
    local_6758 = (double)fVar3;
    local_6644 = (int)(local_666c - local_6758 * local_6630);
    fVar3 = (float10)FUN_008f8f00(local_664c);
    local_6750 = (double)fVar3;
    local_66bc = (int)(local_6750 * local_6630 + local_6674);
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
  }
  else {
    (**(code **)(*local_6620 + 0x7c))();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  ExceptionList = local_10;
  return;
}



