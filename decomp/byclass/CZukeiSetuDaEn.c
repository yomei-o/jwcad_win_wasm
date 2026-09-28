/* CZukeiSetuDaEn -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiSetuDaEn[1] */
/* 00641780  FUN_00641780  68 bytes, 0 callers */

undefined4 FUN_00641780(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00641720();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x338);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiSetuDaEn[6] */
/* 00641a10  FUN_00641a10  906 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00641a10(undefined4 *param_1)

{
  int iVar1;
  undefined1 local_65b0 [20];
  undefined4 local_659c;
  undefined4 local_6594;
  uint local_6590;
  int local_658c;
  undefined1 local_6588 [25552];
  undefined1 local_1b8 [16];
  undefined1 local_1a8 [404];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938076;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_658c + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_659c = FUN_0040c0e0();
  FUN_0044dd90();
  if ((((*(int *)(local_658c + 0xb0) != 10) && (*(int *)(local_658c + 0xb0) != 0x14)) &&
      (*(int *)(local_658c + 0xb0) != 0x1e)) && (*(int *)(local_658c + 0xb0) != 0x32)) {
    FUN_004efbb0(0x151b,0,0);
    *(undefined4 *)(local_658c + 0xac) = 0;
  }
  if ((*(int *)(local_658c + 0xb0) == 10) || (*(int *)(local_658c + 0xb0) == 0x32)) {
    if (*(int *)(local_658c + 0xac) == 1) {
      FUN_004efbb0(0x1541,0,0);
    }
    if (*(int *)(local_658c + 0xac) == 2) {
      FUN_004efbb0(0x1542,0,0);
    }
    if (*(int *)(local_658c + 0xac) == 3) {
      FUN_004efbb0(0x1543,0,0);
      local_6590 = (uint)(*(int *)(local_658c + 0xb0) == 0x32);
      FUN_004988c0(local_1b8,*param_1,param_1[1],param_1[2],param_1[3]);
      iVar1 = FUN_00643340(local_6590);
      if (iVar1 != 0) {
        FUN_00464040();
        local_8._0_1_ = 2;
        FUN_0047f220(*(undefined4 *)(local_658c + 4),local_6588,local_65b0,local_658c + 600,
                     *(undefined8 *)(local_658c + 0x330),0);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_004640a0();
      }
    }
  }
  if ((*(int *)(local_658c + 0xb0) == 0x14) || (*(int *)(local_658c + 0xb0) == 0x1e)) {
    if (*(int *)(local_658c + 0xac) == 1) {
      FUN_0059f7e0();
    }
    if (*(int *)(local_658c + 0xac) == 2) {
      FUN_0059f7e0();
    }
    if (*(int *)(local_658c + 0xac) == 3) {
      FUN_0059f7e0();
    }
    if (*(int *)(local_658c + 0xac) == 4) {
      FUN_0059f7e0();
    }
    local_6594 = FUN_005977f0(0x1544);
    FUN_00404920();
    FUN_0059f7c0();
    FUN_00404770();
    FUN_004efbb0(0,local_1a8,0);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuDaEn[16] */
/* 00641da0  FUN_00641da0  974 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00641da0(void)

{
  undefined4 uVar1;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009380bb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
  if (*(int *)(local_63e8 + 0xac) == 1) {
    if ((*(int *)(local_63e8 + 0xa8) == 0) || (0 < *(int *)(local_63e8 + 0xb4))) {
      *(int *)(local_63e8 + 0xb4) = *(int *)(local_63e8 + 0xb4) + -1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else {
      *(undefined4 *)(local_63e8 + 0xb4) = 0xffffffff;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 1;
    }
  }
  else if (*(int *)(local_63e8 + 0xac) == 2) {
    *(undefined4 *)(local_63e8 + 0xac) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar1 = 1;
  }
  else if (*(int *)(local_63e8 + 0xac) == 3) {
    *(undefined4 *)(local_63e8 + 0xac) = 2;
    if ((*(int *)(local_63e8 + 0xb0) == 0x14) || (*(int *)(local_63e8 + 0xb0) == 0x1e)) {
      FUN_00447b90(local_63fc,2,*(undefined4 *)(local_63e8 + 4),local_63e8 + 0xb8,1,1);
    }
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar1 = 1;
  }
  else if (*(int *)(local_63e8 + 0xac) == 4) {
    if (*(int *)(local_63e8 + 0xb0) == 0x1e) {
      FUN_00447b90(local_63fc,2,*(undefined4 *)(local_63e8 + 4),local_63e8 + 0xb8,1,1);
      FUN_00447b90(local_63fc,2,*(undefined4 *)(local_63e8 + 4),local_63e8 + 0x120,1,1);
    }
    *(undefined4 *)(local_63e8 + 0xac) = 3;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar1 = 1;
  }
  else if (*(int *)(local_63e8 + 0xb4) < 1) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar1 = 1;
  }
  else {
    *(int *)(local_63e8 + 0xb4) = *(int *)(local_63e8 + 0xb4) + -1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar1 = 0;
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiSetuDaEn[0] */
/* 00642170  FUN_00642170  16 bytes, 0 callers */

undefined ** FUN_00642170(void)

{
  return &PTR_s_CZukeiSetuDaEn_00977f54;
}




/* vtable slots: CZukeiSetuDaEn[46] */
/* 00642180  FUN_00642180  233 bytes, 0 callers */

undefined4
FUN_00642180(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_10 = 0xffffffff;
      local_c = 0x26;
      iVar2 = FUN_00778a40(1,&local_10,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,0x26);
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




/* vtable slots: CZukeiSetuDaEn[47] */
/* 00642270  FUN_00642270  233 bytes, 0 callers */

undefined4
FUN_00642270(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
      local_10 = 0xffffffff;
      local_c = 0x26;
      iVar2 = FUN_00778a40(2,&local_10,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9074),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,0x26);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiSetuDaEn[27] */
/* 00642360  FUN_00642360  237 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00642360(void)

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
  FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0xb0) = 10;
  FUN_00642720();
  *(undefined4 *)(local_63e8 + 0xac) = 1;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuDaEn[28] */
/* 00642450  FUN_00642450  237 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00642450(void)

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
  FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0xb0) = 0x14;
  FUN_00642720();
  *(undefined4 *)(local_63e8 + 0xac) = 1;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuDaEn[29] */
/* 00642540  FUN_00642540  237 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00642540(void)

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
  FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0xb0) = 0x1e;
  FUN_00642720();
  *(undefined4 *)(local_63e8 + 0xac) = 1;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuDaEn[30] */
/* 00642630  FUN_00642630  237 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00642630(void)

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
  FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0xb0) = 0x32;
  FUN_00642720();
  *(undefined4 *)(local_63e8 + 0xac) = 1;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuDaEn[9] */
/* 00642810  FUN_00642810  1634 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00642810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_6474 [20];
  undefined4 local_6460;
  undefined4 local_645c;
  int local_6458;
  undefined4 local_130;
  undefined4 local_12c;
  undefined1 local_84 [16];
  undefined1 local_74 [16];
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093810b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0xb0) == 10) || (*(int *)(in_ECX + 0xb0) == 0x32)) {
    if (*(int *)(in_ECX + 0xac) == 1) {
      *(undefined4 *)(in_ECX + 0xac) = 2;
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      FUN_00404c80();
      FUN_0056d7d0();
      uVar1 = 0;
    }
    else if (*(int *)(in_ECX + 0xac) == 2) {
      *(undefined4 *)(in_ECX + 0xac) = 3;
      FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
      FUN_00404c80();
      FUN_0056d7d0();
      uVar1 = 0;
    }
    else if (*(int *)(in_ECX + 0xac) == 3) {
      FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    local_6458 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_6458 + 4));
    local_8._0_1_ = 1;
    local_130 = 1;
    local_12c = 1;
    iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6458 + 4),&param_2,&local_6460,0);
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar2 == 0) {
        FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_6458 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6458 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        local_645c = local_6460;
        if ((*(int *)(local_6458 + 0xb0) == 0x14) || (*(int *)(local_6458 + 0xb0) == 0x1e)) {
          if (*(int *)(local_6458 + 0xac) == 1) {
            *(undefined4 *)(local_6458 + 0xac) = 2;
            FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
            FUN_00420110(local_645c);
            FUN_00447b90(local_6474,2,*(undefined4 *)(local_6458 + 4),local_6458 + 0xb8,1,1);
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
          if (*(int *)(local_6458 + 0xac) == 2) {
            *(undefined4 *)(local_6458 + 0xac) = 3;
            FUN_004988c0(local_64,param_2,param_3,param_4,param_5);
            FUN_00420110(local_645c);
            FUN_00447b90(local_6474,2,*(undefined4 *)(local_6458 + 4),local_6458 + 0x120,1,1);
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
          if (*(int *)(local_6458 + 0xac) == 3) {
            FUN_00420110(local_6460);
            FUN_004988c0(local_74,param_2,param_3,param_4,param_5);
            if (*(int *)(local_6458 + 0xb0) == 0x14) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 1;
            }
            *(undefined4 *)(local_6458 + 0xac) = 4;
            FUN_00447b90(local_6474,2,*(undefined4 *)(local_6458 + 4),local_6458 + 0x188,1,1);
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
          if (*(int *)(local_6458 + 0xac) == 4) {
            FUN_004988c0(local_84,param_2,param_3,param_4,param_5);
            FUN_00420110(local_645c);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 1;
          }
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiSetuDaEn[11] */
/* 00642e80  FUN_00642e80  409 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00642e80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938150;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8560) = 0;
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  if ((in_ECX[0x2c] == 10) || (in_ECX[0x2c] == 0x32)) {
    iVar1 = FUN_00451eb0(in_ECX[1],&local_24,1);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*in_ECX + 0x24))(param_1,local_24,local_20,local_1c,local_18);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    uVar2 = (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiSetuDaEn[4] */
/* 00643020  FUN_00643020  202 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00643020(void)

{
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
  local_63ec = FUN_0040c0e0();
  FUN_0044c830(local_6400,*(undefined4 *)(local_63e8 + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuDaEn[3] */
/* 006430f0  FUN_006430f0  590 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006430f0(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_6404 [20];
  undefined4 local_63f0;
  int local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009381a6;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  local_63f0 = FUN_0040c0e0(uVar1);
  FUN_00446aa0();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_63ec = 0;
  FUN_0044dd90();
  FUN_0044c830();
  if (*(int *)(local_63e8 + 0xb0) == 10) {
    local_63ec = FUN_00643340(0);
  }
  if (*(int *)(local_63e8 + 0xb0) == 0x14) {
    local_63ec = FUN_006450c0();
  }
  if (*(int *)(local_63e8 + 0xb0) == 0x1e) {
    local_63ec = FUN_00643c30();
  }
  if (*(int *)(local_63e8 + 0xb0) == 0x32) {
    local_63ec = FUN_00643340(1);
  }
  if (local_63ec == 0) {
    FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f28),0,0);
  }
  else {
    FUN_00464040();
    local_8._0_1_ = 2;
    FUN_0047f220(*(undefined4 *)(local_63e8 + 4),local_63e4,local_6404,local_63e8 + 600,
                 *(undefined8 *)(local_63e8 + 0x330),1);
    *(int *)(local_63e8 + 0xb4) = *(int *)(local_63e8 + 0xb4) + 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_004640a0();
  }
  *(undefined4 *)(local_63e8 + 0xac) = 1;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = local_8 & 0xffffff00;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



