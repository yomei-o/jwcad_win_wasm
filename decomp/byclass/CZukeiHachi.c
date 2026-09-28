/* CZukeiHachi -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiHachi[1] */
/* 00671d00  FUN_00671d00  68 bytes, 0 callers */

undefined4 FUN_00671d00(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00671c80();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x310);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiHachi[6] */
/* 00672100  FUN_00672100  879 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00672100(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  uint local_657c;
  undefined1 local_1a4 [400];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a0f1;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8ebc) = 0;
  if (*(int *)(in_ECX + 0x208) == 0) {
    if (*(int *)(in_ECX + 0x220) == 0) {
      if (*(int *)(in_ECX + 0x20c) == 0) {
        FUN_00446aa0(local_14);
        local_8 = 0;
        FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
        local_8._0_1_ = 1;
        FUN_0040c0e0();
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
        local_657c = 0;
        if (*(int *)(in_ECX + 0x234) < 1) {
          if (*(int *)(in_ECX + 0x224) < 1) {
            *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8ebc) = 1;
          }
          FUN_005977f0(7000);
          local_8._0_1_ = 2;
          uVar1 = FUN_00404920();
          uVar2 = *(undefined4 *)(in_ECX + 0x224);
          FUN_005977f0(0x1b5e);
          uVar2 = FUN_00404920(uVar2,uVar1);
          FUN_00480580(local_1a4,L"   %s %ld %s",uVar2);
          FUN_00404770();
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_00404770();
          FUN_004efbb0(0x1501,local_1a4,0);
          local_657c = (uint)(0 < *(int *)(in_ECX + 0x224));
        }
        else {
          uVar2 = *(undefined4 *)(in_ECX + 0x228);
          FUN_005977f0(7000);
          local_8._0_1_ = 3;
          uVar1 = FUN_00404920(uVar2);
          uVar2 = *(undefined4 *)(in_ECX + 0x224);
          FUN_005977f0(0x1b5e);
          uVar2 = FUN_00404920(uVar2,uVar1);
          FUN_00480580(local_1a4,L"     %s %ld %s   < %ld >",uVar2);
          FUN_00404770();
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_00404770();
          FUN_004efbb0(0x1502,local_1a4,0);
        }
        if ((0 < *(int *)(in_ECX + 0x224)) || (0 < *(int *)(in_ECX + 0x234))) {
          local_657c = local_657c + 10;
        }
        if (*(uint *)(in_ECX + 0x244) != local_657c) {
          *(uint *)(in_ECX + 0x244) = local_657c;
          FUN_00404c80(local_657c);
          FUN_004fca20();
          FUN_004c7e30(local_657c);
        }
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        FUN_004efbb0(0x14c2,0,0);
      }
    }
    else {
      FUN_0040ac80(param_1);
    }
  }
  else {
    FUN_006f7cc0(param_1);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHachi[16] */
/* 00672470  FUN_00672470  983 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00672470(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_641c [20];
  undefined4 local_6408;
  undefined4 local_6404;
  undefined4 local_6400;
  undefined4 local_63fc;
  undefined4 local_63f8;
  int local_63f4;
  int local_63f0;
  undefined4 local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009236ab;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  if (*(int *)(in_ECX + 0x208) == 0) {
    local_63ec = FUN_0040c0e0(local_14);
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    if (*(int *)(local_63e8 + 0x220) == 0) {
      if (*(int *)(local_63e8 + 0x20c) == 0) {
        if (*(int *)(local_63e8 + 0x230) < 1) {
          if ((*(int *)(local_63e8 + 0x224) < 1) && (*(int *)(local_63e8 + 0x228) < 1)) {
            local_6408 = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            local_63f8 = local_6408;
          }
          else {
            local_63f0 = FUN_00572db0();
            if (local_63f0 != 0) {
              local_63f4 = FUN_00572ae0(&local_63f0);
              if (*(int *)(local_63f4 + 0x48) == 1) {
                do {
                  FUN_00672d70(0xffffffff);
                  local_63f0 = FUN_00572db0();
                  if (local_63f0 == 0) break;
                  local_63f4 = FUN_00572ae0(&local_63f0);
                } while (*(int *)(local_63f4 + 0x48) == 0);
              }
              else {
                FUN_00672d70(0xffffffff);
              }
            }
            FUN_00672b20(0,local_63ec,local_641c,local_63e4);
            FUN_00404c80();
            FUN_0056d7d0();
            local_6404 = 1;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            local_63f8 = local_6404;
          }
        }
        else {
          FUN_00458a80(local_641c,*(undefined4 *)(local_63e8 + 4),0);
          *(int *)(local_63e8 + 0x230) = *(int *)(local_63e8 + 0x230) + -1;
          FUN_00672b20(0,local_63ec,local_641c,local_63e4);
          FUN_00404c80();
          FUN_0056d7d0();
          local_6400 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_63f8 = local_6400;
        }
      }
      else {
        *(undefined4 *)(local_63e8 + 0x20c) = 0;
        FUN_00404c80();
        FUN_0056d7d0();
        local_63fc = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63f8 = local_63fc;
      }
    }
    else {
      *(undefined4 *)(local_63e8 + 0x220) = 0;
      FUN_0044dd90(local_641c,*(undefined4 *)(local_63e8 + 4));
      FUN_00404c80();
      FUN_0056d7d0();
      local_63f8 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    iVar1 = FUN_006f85c0();
    if (iVar1 == 0) {
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8578) = 1;
      *(undefined4 *)(local_63e8 + 0x208) = 0;
      DAT_00a0d618 = 0;
      FUN_00671f80();
      local_63f8 = 1;
    }
    else {
      local_63f8 = 1;
    }
  }
  ExceptionList = local_10;
  return local_63f8;
}




/* vtable slots: CZukeiHachi[0] */
/* 00672850  FUN_00672850  16 bytes, 0 callers */

undefined ** FUN_00672850(void)

{
  return &PTR_s_CZukeiHachi_009787ec;
}




/* vtable slots: CZukeiHachi[46] */
/* 00673b00  FUN_00673b00  1099 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00673b00(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  double dVar3;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  in_ECX[0x83] = 0;
  if (DAT_00a0c7c0 == 0) {
    local_20 = 0;
    if (in_ECX[0x82] == 0) {
      if (*(int *)(in_ECX[1] + 0x9078) == 0) {
        local_24 = 0xffffffff;
        local_1c = in_ECX;
        iVar1 = FUN_00778a40(1,&local_24,*(undefined4 *)(in_ECX[1] + 0x9070),param_1,param_2,param_3
                             ,param_4,param_5,param_6,param_7,0x23);
        if (iVar1 == 0) {
          if (DAT_00a0d8ec < 0) {
            if ((DAT_00a0d8ec * DAT_00a0d8ec < *(int *)(local_1c[1] + 0x9070)) && (param_2 == 0xc))
            {
              if (param_3 == 1) {
                FUN_005168b0(0x143d,*(undefined4 *)(local_1c[1] + 0x8f50),
                             *(undefined4 *)(local_1c[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                (**(code **)(*local_1c + 0x6c))();
              }
              return 0;
            }
            if ((local_1c[0x91] % 10 != 0) && (param_2 == 0xc)) {
              if (param_3 == 1) {
                FUN_005168b0(0x15e7,*(undefined4 *)(local_1c[1] + 0x8f50),
                             *(undefined4 *)(local_1c[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                (**(code **)(*local_1c + 100))();
              }
              return 0;
            }
          }
          if (param_2 == 4) {
            if (local_1c[0x8d] < 1) {
              if (param_3 == 1) {
                FUN_005168b0(0x141c,*(undefined4 *)(local_1c[1] + 0x8f50),
                             *(undefined4 *)(local_1c[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                (**(code **)(*local_1c + 0x70))();
                FUN_004988c0(local_18,param_4,param_5,param_6,param_7);
                FUN_0040c9d0();
                *(undefined4 *)(local_1c[2] + 4) = 1;
              }
            }
            else {
              local_20 = FUN_0076c9c0(param_1,4,param_3,param_4,param_5,param_6,param_7);
            }
          }
          else {
            local_20 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          }
        }
        else {
          local_20 = 0;
        }
      }
      else if (param_2 == 0xc) {
        if (param_3 == 1) {
          FUN_005168b0(0x1810,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00404c80();
          FUN_004fca20();
          fVar2 = (float10)FUN_004c8600();
          dVar3 = -(double)fVar2;
          FUN_00404c80(dVar3);
          FUN_004fca20();
          FUN_004c8480(dVar3);
        }
      }
      else {
        local_20 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else if ((*(int *)(in_ECX[1] + 0x9078) == 0) && (param_2 == 0xc)) {
      if (param_3 == 1) {
        FUN_005168b0(0x147c,*(undefined4 *)(in_ECX[1] + 0x8f50),*(undefined4 *)(in_ECX[1] + 0x8f54),
                     1,0);
      }
      else if (param_3 == 2) {
        (**(code **)(*in_ECX + 0x88))();
      }
      local_20 = 0;
    }
    else {
      local_20 = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_20 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_20;
}




/* vtable slots: CZukeiHachi[47] */
/* 00673f50  FUN_00673f50  299 bytes, 0 callers */

int FUN_00673f50(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int in_ECX;
  undefined4 local_10 [2];
  int local_8;
  
  *(undefined4 *)(in_ECX + 0x20c) = 0;
  if (DAT_00a0c7c0 == 0) {
    local_8 = in_ECX;
    if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
      local_10[0] = 0xffffffff;
      iVar1 = FUN_00778a40(2,local_10,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9074),param_1,param_2
                           ,param_3,param_4,param_5,param_6,param_7,0x23);
      if (iVar1 != 0) {
        return 0;
      }
      if ((((param_2 == 3) || (param_2 == 6)) || (param_2 == 9)) || (param_2 == 0xc)) {
        *(undefined4 *)(local_8 + 0x20c) = 1;
      }
    }
    iVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    if (iVar1 == 0) {
      *(undefined4 *)(local_8 + 0x20c) = 0;
    }
  }
  else {
    iVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return iVar1;
}




/* vtable slots: CZukeiHachi[34] */
/* 00674080  FUN_00674080  352 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00674080(void)

{
  undefined1 local_63fc [20];
  int *local_63e8;
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
  FUN_0079dea2(local_63e8[1]);
  local_8._0_1_ = 1;
  local_63e8[0x82] = 0;
  DAT_00a0d618 = 0;
  FUN_00671f80();
  FUN_0044de00(local_63fc,local_63e8[1]);
  FUN_0044dd90(local_63fc,local_63e8[1]);
  FUN_0044dd20(local_63fc,local_63e8[1]);
  FUN_0044c990(local_63e8[1],local_63fc);
  (**(code **)(*local_63e8 + 0x28))(0);
  local_63e8[0x91] = -1;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHachi[25] */
/* 006741e0  FUN_006741e0  62 bytes, 0 callers */

void FUN_006741e0(void)

{
  int *in_ECX;
  
  if (in_ECX[0x82] == 0) {
    (**(code **)(*in_ECX + 0xc))();
    *(undefined4 *)(in_ECX[1] + 0x8578) = 1;
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiHachi[26] */
/* 00674220  FUN_00674220  130 bytes, 0 callers */

void FUN_00674220(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x208) == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x908c) == 0) {
      if (*(int *)(in_ECX + 0x20c) == 0) {
        *(undefined4 *)(in_ECX + 0x20c) = 1;
      }
      else {
        *(undefined4 *)(in_ECX + 0x20c) = 0;
      }
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x908c) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiHachi[27] */
/* 006742b0  FUN_006742b0  71 bytes, 0 callers */

void FUN_006742b0(void)

{
  int *in_ECX;
  
  if (in_ECX[0x82] == 0) {
    (**(code **)(*in_ECX + 0x10))();
    in_ECX[0x8c] = 0;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiHachi[28] */
/* 00674300  FUN_00674300  326 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00674300(void)

{
  int *in_ECX;
  undefined1 local_63fc [20];
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x82] == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(local_63e8[1]);
    local_8._0_1_ = 1;
    local_63e8[0x81] = 0;
    (**(code **)(*local_63e8 + 0x10))();
    FUN_0044c830(local_63fc,local_63e8[1]);
    local_63e8[0x82] = 1;
    DAT_00a0d618 = 1;
    local_63e8[3] = 0;
    local_63e8[0x2d] = 0;
    FUN_00671f80();
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHachi[29] */
/* 00674450  FUN_00674450  505 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00674450(void)

{
  int *in_ECX;
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093711b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x82] == 0) {
    (**(code **)(*in_ECX + 0x10))(local_14);
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    local_63e8 = in_ECX;
    FUN_006fb760();
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(local_63e8[1]);
    local_8._0_1_ = 1;
    FUN_0044de00(local_6404,local_63e8[1]);
    local_63ec = local_63e8[1];
    if (local_63ec == 0) {
      local_63f0 = 0;
    }
    else {
      local_63f0 = local_63ec + 0x88;
    }
    FUN_00454890(local_63f0);
    FUN_00454830(local_63e8[1]);
    FUN_0044dd90(local_6404,local_63e8[1]);
    FUN_0044dd20(local_6404,local_63e8[1]);
    FUN_0044c830(local_6404,local_63e8[1]);
    local_63e8[0x82] = 0;
    DAT_00a0d618 = 0;
    FUN_00671f80();
    FUN_005168b0(0x2736,*(undefined4 *)(local_63e8[1] + 0x8f24),
                 *(undefined4 *)(local_63e8[1] + 0x8f28),0,0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHachi[30] */
/* 00674650  FUN_00674650  58 bytes, 0 callers */

void FUN_00674650(void)

{
  int *in_ECX;
  
  if (in_ECX[0x82] == 0) {
    (**(code **)(*in_ECX + 0x10))();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_006fbbb0();
  }
  return;
}




/* vtable slots: CZukeiHachi[31] */
/* 00674690  FUN_00674690  58 bytes, 0 callers */

void FUN_00674690(void)

{
  int *in_ECX;
  
  if (in_ECX[0x82] == 0) {
    (**(code **)(*in_ECX + 0x10))();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_006fbbf0();
  }
  return;
}




/* vtable slots: CZukeiHachi[32] */
/* 006746d0  FUN_006746d0  213 bytes, 0 callers */

void FUN_006746d0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0x208) == 0) {
    local_8 = in_ECX;
    uVar1 = FUN_0040c0e0();
    iVar3 = 0;
    local_c = 0;
    local_10 = FUN_00573430(0,uVar1);
    do {
      if ((local_10 == 0) || (local_c = FUN_00573450(&local_10,0), local_c == 0)) goto LAB_00674769;
      iVar2 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
    } while ((iVar2 != 0) || (iVar2 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078), iVar2 != 0));
    iVar3 = 1;
LAB_00674769:
    if (iVar3 == 0) {
      FUN_005168b0(0x2734,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f28),0,0);
    }
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_006fbc40();
  }
  return;
}




/* vtable slots: CZukeiHachi[33] */
/* 006747b0  FUN_006747b0  58 bytes, 0 callers */

void FUN_006747b0(void)

{
  int *in_ECX;
  
  if (in_ECX[0x82] == 0) {
    (**(code **)(*in_ECX + 0x10))();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_006fbf90();
  }
  return;
}




/* vtable slots: CZukeiHachi[36] */
/* 006747f0  FUN_006747f0  400 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006747f0(void)

{
  int iVar1;
  int *in_ECX;
  int local_63f0;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093711b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_0079dea2(in_ECX[1]);
  local_8._0_1_ = 1;
  if (in_ECX[0x82] == 0) {
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (in_ECX[1] == 0) {
      local_63f0 = 0;
    }
    else {
      local_63f0 = in_ECX[1] + 0x88;
    }
    iVar1 = FUN_0044fcd0(local_63f0);
    if (iVar1 == 0) {
      if (DAT_00a0d618 == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        (**(code **)(*in_ECX + 0x88))();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHachi[49] */
/* 00674980  FUN_00674980  63 bytes, 0 callers */

void FUN_00674980(undefined8 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x208) == 0) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_004c8480(param_1);
  }
  return;
}




/* vtable slots: CZukeiHachi[50] */
/* 006749c0  FUN_006749c0  139 bytes, 0 callers */

void FUN_006749c0(double param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x208) == 0) {
    FUN_00404c80(param_1);
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x6ac) == 0) {
      param_1 = param_1 / *(double *)
                           (*(int *)(in_ECX + 4) + 0x2578 +
                           *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
    }
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_004c8580(param_1);
  }
  return;
}




/* vtable slots: CZukeiHachi[51] */
/* 00674a50  FUN_00674a50  257 bytes, 0 callers */

void FUN_00674a50(undefined8 param_1,double param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a22d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x208) == 0) {
    FUN_00404c80(param_1,uVar1);
    FUN_004fca20();
    FUN_004c8480(param_1);
    FUN_00404c80(uVar1,param_2);
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x6ac) == 0) {
      param_2 = param_2 / *(double *)
                           (*(int *)(in_ECX + 4) + 0x2578 +
                           *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
    }
    FUN_00404c80(param_2);
    FUN_004fca20();
    FUN_004c8580(param_2);
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




/* vtable slots: CZukeiHachi[15] */
/* 00674b60  FUN_00674b60  231 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00674b60(void)

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
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  iVar1 = FUN_00453bd0(local_6400,*(undefined4 *)(local_63e8 + 4),0);
  if (iVar1 != 0) {
    *(int *)(local_63e8 + 0x230) = *(int *)(local_63e8 + 0x230) + 1;
  }
  local_63ec = 1;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiHachi[10] */
/* 00674c50  FUN_00674c50  770 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00674c50(void)

{
  int iVar1;
  undefined1 local_6414 [20];
  int local_6400;
  int local_63fc;
  int local_63f8;
  undefined4 local_63f4;
  int local_63f0;
  int local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093774b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_63ec = 0;
  local_63f0 = 0;
  local_63f4 = FUN_0040c0e0();
  local_63f8 = *(int *)(local_63e8 + 4);
  if (local_63f8 == 0) {
    local_63fc = 0;
  }
  else {
    local_63fc = local_63f8 + 0x88;
  }
  iVar1 = FUN_0044fcd0(local_63fc);
  if (iVar1 == 0) {
    local_6400 = FUN_00572b10();
    while ((local_6400 != 0 && (local_63ec = FUN_00572b30(&local_6400,0), local_63ec != 0))) {
      if ((*(ushort *)(local_63ec + 0x44) & 0x20) == 0) {
        iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar1 != 0) {
          local_63f0 = FUN_006738f0(local_63e4,local_6414,local_63ec,0,0);
          *(int *)(local_63e8 + 0x224) = *(int *)(local_63e8 + 0x224) + 1;
          FUN_00450cc0(*(undefined4 *)(local_63e8 + 4),local_63ec);
        }
        iVar1 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
        if (iVar1 != 0) {
          local_63f0 = FUN_006738f0(local_63e4,local_6414,local_63ec,0,0);
          *(int *)(local_63e8 + 0x224) = *(int *)(local_63e8 + 0x224) + 1;
          FUN_00450cc0(*(undefined4 *)(local_63e8 + 4),local_63ec);
        }
        iVar1 = FUN_0079d98a(&PTR_s_CDataBlock_009fe144);
        if (iVar1 != 0) {
          local_63f0 = FUN_00671d50(local_63ec);
        }
      }
    }
  }
  if (local_63f0 != 0) {
    *(undefined4 *)(local_63f0 + 0x48) = 1;
  }
  FUN_00449d60(local_6414,*(undefined4 *)(local_63e8 + 4),1);
  FUN_00672b20(0,local_63f4,local_6414,local_63e4);
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x85b4) = 0;
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x85a8) = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHachi[9] */
/* 00674f60  FUN_00674f60  1722 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00674f60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  double local_6558;
  undefined1 local_652c [20];
  int local_6518;
  undefined1 *local_6514;
  undefined1 *local_6510;
  undefined1 *local_650c;
  int local_6508;
  undefined1 local_6504 [25552];
  undefined1 local_134 [152];
  undefined1 local_9c [16];
  undefined1 local_8c [16];
  undefined1 local_7c [104];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a27e;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x208) == 0) {
    local_6508 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_6508 + 4));
    local_8._0_1_ = 1;
    uVar2 = FUN_0040c0e0();
    FUN_0041f760();
    local_8._0_1_ = 2;
    FUN_0041f5f0();
    local_8._0_1_ = 3;
    uVar1 = (undefined1)local_8;
    local_8._0_1_ = 3;
    if (*(int *)(local_6508 + 0x220) == 0) {
      if (*(int *)(local_6508 + 0x20c) == 0) {
        *(undefined4 *)(local_6508 + 0x230) = 0;
        *(undefined4 *)(*(int *)(local_6508 + 4) + 0x8560) = 0;
        local_8._0_1_ = uVar1;
        FUN_004988c0(local_9c,param_2,param_3,param_4,param_5);
        iVar3 = FUN_006769e0(param_2,param_3,param_4,param_5);
        if (iVar3 == 0) {
          local_8._0_1_ = 2;
          FUN_0041fd50();
          local_8._0_1_ = 1;
          FUN_0041fd70();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
        else {
          local_6514 = *(undefined1 **)(local_6508 + 0x240);
          local_650c = local_6514;
          if (*(int *)(local_6508 + 0x24c) != 0) {
            iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
            if (iVar3 != 0) {
              FUN_00420110(local_650c);
              local_650c = local_7c;
            }
            iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
            if (iVar3 != 0) {
              FUN_00420020(local_650c);
              local_650c = local_134;
            }
          }
          if (*(int *)(local_6508 + 0x234) < 1) {
            iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
            if (iVar3 != 0) {
              local_6510 = local_650c;
              fVar4 = (float10)FUN_0040c100();
              if ((double)fVar4 <= 0.0) {
                fVar4 = (float10)FUN_0040c100();
                local_6558 = -(double)fVar4;
              }
              else {
                fVar4 = (float10)FUN_0040c100();
                local_6558 = (double)fVar4;
              }
              if (6.283185207179586 < local_6558) {
                FUN_005168b0(0x1458,*(undefined4 *)(*(int *)(local_6508 + 4) + 0x8f24),
                             *(undefined4 *)(*(int *)(local_6508 + 4) + 0x8f28),0,0);
                local_8._0_1_ = 2;
                FUN_0041fd50();
                local_8._0_1_ = 1;
                FUN_0041fd70();
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return 0;
              }
            }
            FUN_006738f0(local_6504,local_652c,local_650c,2,1);
          }
          else {
            FUN_006738f0(local_6504,local_652c,local_650c,1,0);
            local_6518 = FUN_00676f50();
            if (local_6518 == 0) {
              FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6508 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6508 + 4) + 0x8f28),0,0);
            }
            else {
              iVar3 = FUN_00610980();
              if ((iVar3 != 0) && (local_6514[0x28] == '\x14')) {
                *(undefined4 *)(local_6518 + 0x48) = 2;
              }
              FUN_00450cc0(*(undefined4 *)(local_6508 + 4),local_650c);
            }
          }
          FUN_00672b20(0,uVar2,local_652c,local_6504);
          FUN_00404c80();
          FUN_0056d7d0();
          local_8._0_1_ = 2;
          FUN_0041fd50();
          local_8._0_1_ = 1;
          FUN_0041fd70();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
      }
      else {
        *(undefined4 *)(local_6508 + 0x20c) = 0;
        FUN_0044de00(local_652c,*(undefined4 *)(local_6508 + 4));
        FUN_004988c0(local_8c,param_2,param_3,param_4,param_5);
        FUN_004508b0(0x10,local_652c,*(undefined4 *)(local_6508 + 4),param_2,param_3,param_4,param_5
                     ,0);
        FUN_00404c80();
        FUN_0056d7d0();
        local_8._0_1_ = 2;
        FUN_0041fd50();
        local_8._0_1_ = 1;
        FUN_0041fd70();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
    }
    else {
      iVar3 = FUN_0040dbb0(param_1,param_2,param_3,param_4,param_5);
      if (iVar3 != 0) {
        FUN_00672860();
        *(undefined4 *)(local_6508 + 0x220) = 0;
      }
      local_8._0_1_ = 2;
      FUN_0041fd50();
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 0;
    }
  }
  else {
    uVar2 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiHachi[11] */
/* 00675620  FUN_00675620  671 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00675620(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309e0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x208) == 0) {
    if (*(int *)(in_ECX + 0x220) == 0) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
      FUN_00446aa0(local_14);
      local_8 = 0;
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      if (*(int *)(in_ECX + 0x20c) == 0) {
        if (*(int *)(in_ECX + 0x234) < 1) {
          *(undefined4 *)(in_ECX + 0x230) = 0;
          FUN_00673080(param_2,param_3,param_4,param_5,0);
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          FUN_005168b0(0x147b,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
      }
      else {
        iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
        if (iVar2 == 1) {
          uVar1 = FUN_00674f60(param_1,local_24,local_20,local_1c,local_18);
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
      }
    }
    else {
      iVar2 = FUN_0040deb0(param_1,param_2,param_3,param_4,param_5);
      if (iVar2 != 0) {
        FUN_00672860();
        *(undefined4 *)(in_ECX + 0x220) = 0;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiHachi[4] */
/* 006758c0  FUN_006758c0  577 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006758c0(void)

{
  float10 fVar1;
  undefined1 local_6410 [20];
  undefined4 local_63fc;
  undefined4 local_63f8;
  int local_63f4;
  int local_63f0;
  int *local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939d2b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_63f8 = FUN_0040c0e0();
  if (*(int *)(local_63e8 + 0x208) == 0) {
    FUN_00404c80();
    FUN_004fca20();
    fVar1 = (float10)FUN_004c8700();
    *(double *)(local_63e8 + 0x260) = (double)fVar1;
    FUN_00404c80();
    FUN_004fca20();
    fVar1 = (float10)FUN_004c8650();
    *(double *)(local_63e8 + 0x268) = (double)fVar1;
  }
  else {
    FUN_0044c830(local_6410,*(undefined4 *)(local_63e8 + 4));
  }
  FUN_00672b20(1,local_63f8,local_6410,local_63e4);
  local_63f0 = *(int *)(local_63e8 + 4);
  if (local_63f0 == 0) {
    local_63f4 = 0;
  }
  else {
    local_63f4 = local_63f0 + 0x88;
  }
  FUN_00454890(local_63f4);
  FUN_00454830(*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0x224) = 0;
  *(undefined4 *)(local_63e8 + 0x234) = 0;
  *(undefined4 *)(local_63e8 + 0x228) = 0;
  *(undefined4 *)(local_63e8 + 0x238) = 0;
  if (*(int *)(local_63e8 + 0x248) != 0) {
    local_63ec = *(int **)(local_63e8 + 0x248);
    if (local_63ec == (int *)0x0) {
      local_63fc = 0;
    }
    else {
      local_63fc = (**(code **)(*local_63ec + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0x248) = 0;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHachi[3] */
/* 00675b10  FUN_00675b10  1781 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00675b10(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 local_6424 [20];
  int local_6410;
  undefined4 local_640c;
  int local_6408;
  int local_6404;
  int local_6400;
  CWaitCursor local_63f9;
  int local_63f8;
  undefined1 local_63f4 [25568];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a2d6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x208) == 0) {
    local_63f8 = in_ECX;
    FUN_004fb910(0);
    CWaitCursor::CWaitCursor(&local_63f9);
    local_8 = 0;
    local_6400 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
    local_8._0_1_ = 2;
    local_640c = FUN_0040c0e0();
    *(undefined4 *)(local_63f8 + 0x20c) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(local_63f8 + 0x250) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x6a8);
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_004c8600();
    *(double *)(local_63f8 + 600) = (double)fVar3 + *(double *)(*(int *)(local_63f8 + 4) + 0x17c0);
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_004c8700();
    *(double *)(local_63f8 + 0x260) = (double)fVar3;
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_004c8650();
    *(double *)(local_63f8 + 0x268) = (double)fVar3;
    if ((*(double *)(local_63f8 + 0x260) <= 0.01 && *(double *)(local_63f8 + 0x260) != 0.01) ||
       ((0 < *(int *)(local_63f8 + 0x250) &&
        (*(double *)(local_63f8 + 0x268) <= 0.01 && *(double *)(local_63f8 + 0x268) != 0.01)))) {
      FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
      local_8._0_1_ = 1;
      FUN_0079dfff();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00408b00();
    }
    else {
      local_6404 = FUN_00572c70();
      if (local_6404 == 0) {
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_00408b00();
      }
      else {
        FUN_005168b0(0x14af,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
        *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8560) = 0;
        *(undefined4 *)(local_63f8 + 0x22c) = 0;
        if (*(int *)(local_63f8 + 0x250) < 3) {
          local_6400 = FUN_00678410(local_63f4,local_6424);
        }
        if (*(int *)(local_63f8 + 0x250) == 3) {
          local_6400 = FUN_00679f40(local_63f4,local_6424,0,0);
        }
        if (*(int *)(local_63f8 + 0x250) == 4) {
          local_6410 = 0;
          local_6408 = 0;
          local_6404 = FUN_00573430();
          do {
            if ((local_6404 == 0) || (local_6408 = FUN_00573450(&local_6404,0), local_6408 == 0))
            goto LAB_00675ed3;
            iVar1 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
          } while ((iVar1 != 0) || (iVar1 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078), iVar1 != 0));
          local_6410 = 1;
LAB_00675ed3:
          if (local_6410 == 0) {
            FUN_004fb9f0();
            FUN_005168b0(0x2734,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                         *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
            local_8._0_1_ = 1;
            FUN_0079dfff();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_00408b00();
            ExceptionList = local_10;
            return;
          }
          uVar9 = 0;
          uVar7 = (undefined4)*(undefined8 *)(local_63f8 + 600);
          uVar8 = (undefined4)((ulonglong)*(undefined8 *)(local_63f8 + 600) >> 0x20);
          puVar2 = (undefined4 *)FUN_00408a30(0,0,0,0);
          FUN_005f89c0(*puVar2,puVar2[1],puVar2[2],puVar2[3],uVar7,uVar8,uVar9);
          fVar3 = (float10)FUN_005f8b60(0,(int)*(undefined8 *)(local_63f8 + 0x268),
                                        (int)((ulonglong)*(undefined8 *)(local_63f8 + 0x268) >> 0x20
                                             ),0,0);
          fVar4 = (float10)FUN_005f8c20(0,(int)*(undefined8 *)(local_63f8 + 0x268),
                                        (int)((ulonglong)*(undefined8 *)(local_63f8 + 0x268) >> 0x20
                                             ),0,0);
          fVar5 = (float10)FUN_005f8b60(0,0,0,(int)*(undefined8 *)(local_63f8 + 0x260),
                                        (int)((ulonglong)*(undefined8 *)(local_63f8 + 0x260) >> 0x20
                                             ));
          fVar6 = (float10)FUN_005f8c20(0,0,0,(int)*(undefined8 *)(local_63f8 + 0x260),
                                        (int)((ulonglong)*(undefined8 *)(local_63f8 + 0x260) >> 0x20
                                             ));
          local_6400 = FUN_00678bb0(local_63f4,local_6424,(double)fVar3,(double)fVar4,(double)fVar5,
                                    (double)fVar6);
        }
        FUN_004fb9f0();
        if (local_6400 < 0) {
          FUN_005168b0(0x1451,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
        }
        if (0 < local_6400) {
          FUN_005168b0(0x1508,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
        }
        if ((-1 < local_6400) && (0 < *(int *)(local_63f8 + 0x22c))) {
          *(int *)(local_63f8 + 0x230) = *(int *)(local_63f8 + 0x230) + 1;
        }
        FUN_00672b20(0,local_640c,local_6424,local_63f4);
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_00408b00();
      }
    }
  }
  else {
    FUN_006fe2f0(local_14);
  }
  ExceptionList = local_10;
  return;
}



