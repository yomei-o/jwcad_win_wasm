/* CZukeiKyokuSen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiKyokuSen[1] */
/* 006b2af0  FUN_006b2af0  68 bytes, 0 callers */

undefined4 FUN_006b2af0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006b2a00();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x2130);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiKyokuSen[6] */
/* 006b2fe0  FUN_006b2fe0  2218 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x006b364b) */

void FUN_006b2fe0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double local_6560;
  double local_6558;
  undefined1 local_6548 [20];
  undefined4 local_6534;
  undefined4 local_6530;
  int local_652c;
  undefined1 local_158 [16];
  undefined1 local_148 [8];
  undefined8 local_140;
  undefined8 local_138;
  undefined2 local_e0 [102];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c916;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_652c + 4) + 0x8624)) {
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_652c + 4));
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_652c + 4) + 0x8624)) {
      FUN_00404c80();
      FUN_004fca20();
      uVar3 = FUN_00551840();
      *(undefined4 *)(local_652c + 0x128) = uVar3;
    }
    *(undefined4 *)(local_652c + 0xb0) = 0;
    if (2 < *(int *)(local_652c + 0x11c)) {
      *(undefined4 *)(local_652c + 0xb0) = 1;
    }
    local_6530 = 0;
    if (*(double *)(local_652c + 0x130 + *(int *)(local_652c + 0x11c) * 8) -
        *(double *)(local_652c + 0x138) <= 0.0) {
      local_6558 = -(*(double *)(local_652c + 0x130 + *(int *)(local_652c + 0x11c) * 8) -
                    *(double *)(local_652c + 0x138));
    }
    else {
      local_6558 = *(double *)(local_652c + 0x130 + *(int *)(local_652c + 0x11c) * 8) -
                   *(double *)(local_652c + 0x138);
    }
    if (local_6558 < 1e-07) {
      if (*(double *)(local_652c + 0x1120 + *(int *)(local_652c + 0x11c) * 8) -
          *(double *)(local_652c + 0x1128) <= 0.0) {
        local_6560 = -(*(double *)(local_652c + 0x1120 + *(int *)(local_652c + 0x11c) * 8) -
                      *(double *)(local_652c + 0x1128));
      }
      else {
        local_6560 = *(double *)(local_652c + 0x1120 + *(int *)(local_652c + 0x11c) * 8) -
                     *(double *)(local_652c + 0x1128);
      }
      if ((((local_6560 < 1e-07) && (2 < *(int *)(local_652c + 0x11c))) &&
          (*(int *)(local_652c + 0xb8) == 0)) && (*(int *)(local_652c + 0xbc) == 0)) {
        local_6530 = 1;
      }
    }
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_652c + 4) + 0x8624)) {
      uVar3 = *(undefined4 *)(local_652c + 0xb0);
      uVar4 = local_6530;
      FUN_00404c80(uVar3,local_6530);
      FUN_004fca20();
      FUN_00551760(uVar3,uVar4);
    }
    if (*(int *)(local_652c + 0xa8) == 0x15) {
      if (*(int *)(local_652c + 0xac) == 1) {
        FUN_004efbb0(0x14e1,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (*(int *)(local_652c + 0xac) == 2) {
        FUN_004efbb0(0x151c,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (*(int *)(local_652c + 0xac) == 3) {
        FUN_004efbb0(0x1529,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        if (*(int *)(local_652c + 0xac) == 4) {
          FUN_004efbb0(0x152a,0,0);
        }
        if (*(int *)(local_652c + 0xac) == 5) {
          FUN_004efbb0(0x14c8,0,0);
        }
        if (*(int *)(local_652c + 0xac) == 6) {
          FUN_004efbb0(0x14c9,0,0);
        }
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else if (*(int *)(local_652c + 0xa8) == 0x16) {
      if (*(int *)(local_652c + 0xac) == 1) {
        FUN_004efbb0(0x14e1,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (*(int *)(local_652c + 0xac) == 2) {
        FUN_004efbb0(0x151c,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (*(int *)(local_652c + 0xac) == 3) {
        FUN_004efbb0(0x1528,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        if (*(int *)(local_652c + 0xac) == 5) {
          FUN_004efbb0(0x14c8,0,0);
        }
        if (*(int *)(local_652c + 0xac) == 6) {
          FUN_004efbb0(0x14c9,0,0);
        }
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else if ((*(int *)(local_652c + 0xb4) == 0) || (*(int *)(local_652c + 0xa8) != 0x17)) {
      local_6534 = 0;
      local_e0[0] = 0;
      if (*(int *)(local_652c + 0xa8) == 0x17) {
        FUN_005977f0(0x1581);
        uVar3 = FUN_00404920();
        FUN_0062a340(local_e0,L"     %s",uVar3);
        FUN_00404770();
      }
      if ((*(int *)(local_652c + 0x11c) == 0) || (*(int *)(local_652c + 0xac) == 1)) {
        FUN_004efbb0(0x14c8,local_e0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        if (*(int *)(local_652c + 0xac) == 2) {
          FUN_004efbb0(0x1528,local_e0,0);
        }
        if (*(int *)(local_652c + 0xac) == 3) {
          FUN_004efbb0(0x14c9,local_e0,0);
        }
        FUN_0044dd90(local_6548,*(undefined4 *)(local_652c + 4));
        FUN_0041f760();
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_004552a0(local_148);
        if (0 < *(int *)(local_652c + 0x11c)) {
          local_140 = *(undefined8 *)(local_652c + 0x130 + *(int *)(local_652c + 0x11c) * 8);
          local_138 = *(undefined8 *)(local_652c + 0x1120 + *(int *)(local_652c + 0x11c) * 8);
          FUN_004988c0(local_158,*param_1,param_1[1],param_1[2],param_1[3]);
          FUN_00450b70(local_6548,*(undefined4 *)(local_652c + 4),local_148);
        }
        local_8._0_1_ = 1;
        FUN_0041fd70();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      FUN_004efbb0(0x1580,0,0);
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKyokuSen[16] */
/* 006b3890  FUN_006b3890  1581 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006b3890(void)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_6404 [20];
  int *local_63f0;
  int *local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c95b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  uVar2 = FUN_0040c0e0(uVar1);
  FUN_00446aa0(uVar1,uVar2);
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6404,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd20(local_6404,*(undefined4 *)(local_63e8 + 4));
  if ((*(int *)(local_63e8 + 0xa8) == 0x15) || (*(int *)(local_63e8 + 0xa8) == 0x16)) {
    if (*(int *)(local_63e8 + 0xac) == 1) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 0;
    }
    else if (*(int *)(local_63e8 + 0xac) == 2) {
      *(undefined4 *)(local_63e8 + 0xac) = 1;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 1;
    }
    else if (*(int *)(local_63e8 + 0xac) == 3) {
      *(undefined4 *)(local_63e8 + 0xac) = 2;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 1;
    }
    else if (*(int *)(local_63e8 + 0xac) == 4) {
      *(undefined4 *)(local_63e8 + 0xac) = 3;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 1;
    }
    else if (*(int *)(local_63e8 + 0xac) == 5) {
      if (*(int *)(local_63e8 + 0xa8) == 0x15) {
        *(undefined4 *)(local_63e8 + 0xac) = 4;
      }
      else {
        *(undefined4 *)(local_63e8 + 0xac) = 3;
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 1;
    }
    else if (*(int *)(local_63e8 + 0xac) == 6) {
      *(undefined4 *)(local_63e8 + 0xac) = 5;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 1;
    }
    else {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 0;
    }
  }
  else {
    if (*(int *)(local_63e8 + 0xbc) != 0) {
      local_63ec = *(int **)(local_63e8 + 0xbc);
      if (local_63ec != (int *)0x0) {
        (**(code **)(*local_63ec + 4))(1);
      }
      *(undefined4 *)(local_63e8 + 0xbc) = 0;
    }
    *(undefined4 *)(local_63e8 + 0xb4) = 0;
    if (*(int *)(local_63e8 + 0x120) < 1) {
      if (*(int *)(local_63e8 + 0x11c) < 2) {
        if (*(int *)(local_63e8 + 0x11c) < 1) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar2 = 0;
        }
        else {
          *(undefined4 *)(local_63e8 + 0x11c) = 0;
          *(undefined4 *)(local_63e8 + 0xac) = 1;
          if (*(int *)(local_63e8 + 0xb8) != 0) {
            local_63f0 = *(int **)(local_63e8 + 0xb8);
            if (local_63f0 != (int *)0x0) {
              (**(code **)(*local_63f0 + 4))(1);
            }
            *(undefined4 *)(local_63e8 + 0xb8) = 0;
          }
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar2 = 1;
        }
      }
      else {
        *(int *)(local_63e8 + 0x11c) = *(int *)(local_63e8 + 0x11c) + -1;
        FUN_006b3ed0();
        if (*(int *)(local_63e8 + 0x11c) == 1) {
          *(undefined4 *)(local_63e8 + 0xac) = 2;
        }
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar2 = 1;
      }
    }
    else {
      *(undefined4 *)(local_63e8 + 0x11c) = *(undefined4 *)(local_63e8 + 0x120);
      *(undefined4 *)(local_63e8 + 0x120) = 0;
      FUN_00458a80(local_6404,*(undefined4 *)(local_63e8 + 4),0);
      *(undefined4 *)(local_63e8 + 0xac) = 3;
      FUN_006b3ed0();
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 1;
    }
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiKyokuSen[0] */
/* 006b3ec0  FUN_006b3ec0  16 bytes, 0 callers */

undefined ** FUN_006b3ec0(void)

{
  return &PTR_s_CZukeiKyokuSen_00979950;
}




/* vtable slots: CZukeiKyokuSen[46] */
/* 006b4280  FUN_006b4280  347 bytes, 0 callers */

undefined4
FUN_006b4280(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined4 local_c;
  int *local_8;
  
  if (DAT_00a0c7c0 != 0) {
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return uVar1;
  }
  if (*(int *)(in_ECX[1] + 0x9078) == 0) {
    local_c = 0xffffffff;
    local_8 = in_ECX;
    iVar2 = FUN_00778a40(1,&local_c,*(undefined4 *)(in_ECX[1] + 0x9070),param_1,param_2,param_3,
                         param_4,param_5,param_6,param_7,0x18);
    if (iVar2 != 0) {
      return 0;
    }
    if ((((local_8[0x2a] == 0x17) || (local_8[0x2a] == 0x18)) && (param_2 == 0xc)) &&
       (local_8[0x2c] == 1)) {
      if (param_3 == 1) {
        FUN_005168b0(0x15e7,*(undefined4 *)(local_8[1] + 0x8f50),
                     *(undefined4 *)(local_8[1] + 0x8f54),1,0);
      }
      else if (param_3 == 2) {
        (**(code **)(*local_8 + 0x88))();
      }
      return 0;
    }
  }
  uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar1;
}




/* vtable slots: CZukeiKyokuSen[47] */
/* 006b43e0  FUN_006b43e0  224 bytes, 0 callers */

undefined4
FUN_006b43e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_c [2];
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
      local_c[0] = 0xffffffff;
      iVar2 = FUN_00778a40(2,local_c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9074),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,0x18);
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




/* vtable slots: CZukeiKyokuSen[34] */
/* 006b44c0  FUN_006b44c0  52 bytes, 0 callers */

void FUN_006b44c0(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))();
  *(undefined4 *)(in_ECX[1] + 0x8578) = 1;
  FUN_00404c80();
  FUN_0056d200();
  return;
}




/* vtable slots: CZukeiKyokuSen[25] */
/* 006b4500  FUN_006b4500  32 bytes, 0 callers */

void FUN_006b4500(void)

{
  int in_ECX;
  
  FUN_006b4090();
  *(undefined4 *)(in_ECX + 0xa8) = 0x15;
  return;
}




/* vtable slots: CZukeiKyokuSen[26] */
/* 006b4520  FUN_006b4520  32 bytes, 0 callers */

void FUN_006b4520(void)

{
  int in_ECX;
  
  FUN_006b4090();
  *(undefined4 *)(in_ECX + 0xa8) = 0x16;
  return;
}




/* vtable slots: CZukeiKyokuSen[27] */
/* 006b4540  FUN_006b4540  32 bytes, 0 callers */

void FUN_006b4540(void)

{
  int in_ECX;
  
  FUN_006b4090();
  *(undefined4 *)(in_ECX + 0xa8) = 0x17;
  return;
}




/* vtable slots: CZukeiKyokuSen[28] */
/* 006b4560  FUN_006b4560  32 bytes, 0 callers */

void FUN_006b4560(void)

{
  int in_ECX;
  
  FUN_006b4090();
  *(undefined4 *)(in_ECX + 0xa8) = 0x18;
  return;
}




/* vtable slots: CZukeiKyokuSen[29] */
/* 006b4580  FUN_006b4580  63 bytes, 0 callers */

void FUN_006b4580(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) == 0) {
    *(undefined4 *)(in_ECX + 0xb4) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xb4) = 0;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiKyokuSen[36] */
/* 006b45c0  FUN_006b45c0  67 bytes, 0 callers */

void FUN_006b45c0(void)

{
  int *in_ECX;
  
  if (((2 < in_ECX[0x47]) && (in_ECX[0x2a] != 0x15)) && (in_ECX[0x2a] != 0x16)) {
    (**(code **)(*in_ECX + 0x88))();
  }
  return;
}




/* vtable slots: CZukeiKyokuSen[12] */
/* 006b4610  FUN_006b4610  128 bytes, 0 callers */

undefined4
FUN_006b4610(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if ((in_ECX[0x2a] == 0x17) && (0 < in_ECX[0x47])) {
    in_ECX[0x47] = in_ECX[0x47] + -1;
    FUN_006b3ed0();
    in_ECX[0x2d] = 1;
    uVar1 = (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CZukeiKyokuSen[9] */
/* 006b4690  FUN_006b4690  4270 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006b4690(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  double local_658c;
  double local_6584;
  double local_657c;
  double local_6574;
  double local_656c;
  double local_6564;
  int *local_64c8;
  int *local_64c4;
  int local_64c0;
  undefined4 local_198;
  undefined4 local_194;
  undefined1 local_ec [16];
  undefined1 local_dc [16];
  undefined1 local_cc [16];
  undefined1 local_bc [16];
  undefined1 local_ac [16];
  undefined1 local_9c [16];
  undefined1 local_8c [104];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ca06;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_64c0 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  uVar2 = FUN_0040c0e0(uVar1);
  FUN_00446aa0(uVar1,uVar2);
  local_8._0_1_ = 1;
  FUN_0041f760();
  local_8._0_1_ = 2;
  FUN_004552a0(local_8c);
  *(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8560) = 0;
  if ((*(int *)(local_64c0 + 0xa8) == 0x15) || (*(int *)(local_64c0 + 0xa8) == 0x16)) {
    local_64c8 = (int *)0x0;
    if (*(int *)(local_64c0 + 0xac) == 1) {
      local_198 = 1;
      local_194 = 1;
      iVar3 = FUN_0044a270(3,*(undefined4 *)(local_64c0 + 4),&param_2,&local_64c8,1);
      if (iVar3 == 0) {
        local_8._0_1_ = 1;
        FUN_0041fd70();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar2 = 0;
      }
      else {
        if (*(int *)(local_64c0 + 0x118) != 0) {
          if (*(int **)(local_64c0 + 0x118) != (int *)0x0) {
            (**(code **)(**(int **)(local_64c0 + 0x118) + 4))(1);
          }
          *(undefined4 *)(local_64c0 + 0x118) = 0;
        }
        if (local_64c8 != (int *)0x0) {
          uVar2 = (**(code **)(*local_64c8 + 0x14))();
          *(undefined4 *)(local_64c0 + 0x118) = uVar2;
        }
        *(undefined4 *)(local_64c0 + 0xc0) = *(undefined4 *)(local_64c0 + 0x118);
        iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar3 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8f28),0,0);
          local_8._0_1_ = 1;
          FUN_0041fd70();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar2 = 0;
        }
        else {
          *(undefined4 *)(local_64c0 + 0xac) = 2;
          FUN_00404c80();
          FUN_0056d7d0();
          local_8._0_1_ = 1;
          FUN_0041fd70();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar2 = 0;
        }
      }
    }
    else if (*(int *)(local_64c0 + 0xac) == 2) {
      FUN_004988c0(local_ec,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_64c0 + 0xac) = 3;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 0;
    }
    else if (*(int *)(local_64c0 + 0xac) == 3) {
      FUN_004988c0(local_dc,param_2,param_3,param_4,param_5);
      if (*(int *)(local_64c0 + 0xa8) == 0x15) {
        *(undefined4 *)(local_64c0 + 0xac) = 4;
      }
      else {
        *(undefined4 *)(local_64c0 + 0xac) = 5;
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 0;
    }
    else if (*(int *)(local_64c0 + 0xac) == 4) {
      FUN_004988c0(local_9c,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_64c0 + 0xac) = 5;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 0;
    }
    else if (*(int *)(local_64c0 + 0xac) == 5) {
      FUN_004988c0(local_cc,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_64c0 + 0xac) = 6;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 0;
    }
    else if (*(int *)(local_64c0 + 0xac) == 6) {
      FUN_004988c0(local_bc,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_64c0 + 0xac) = 7;
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 1;
    }
    else {
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar2 = 0;
    }
  }
  else if (*(int *)(local_64c0 + 0x11c) < *(int *)(local_64c0 + 0x124)) {
    if (0 < *(int *)(local_64c0 + 0x11c)) {
      if (*(double *)(local_64c0 + 0x130 + *(int *)(local_64c0 + 0x11c) * 8) -
          (double)CONCAT44(param_3,param_2) <= 0.0) {
        local_6564 = -(*(double *)(local_64c0 + 0x130 + *(int *)(local_64c0 + 0x11c) * 8) -
                      (double)CONCAT44(param_3,param_2));
      }
      else {
        local_6564 = *(double *)(local_64c0 + 0x130 + *(int *)(local_64c0 + 0x11c) * 8) -
                     (double)CONCAT44(param_3,param_2);
      }
      if (local_6564 < 1e-06) {
        if (*(double *)(local_64c0 + 0x1120 + *(int *)(local_64c0 + 0x11c) * 8) -
            (double)CONCAT44(param_5,param_4) <= 0.0) {
          local_656c = -(*(double *)(local_64c0 + 0x1120 + *(int *)(local_64c0 + 0x11c) * 8) -
                        (double)CONCAT44(param_5,param_4));
        }
        else {
          local_656c = *(double *)(local_64c0 + 0x1120 + *(int *)(local_64c0 + 0x11c) * 8) -
                       (double)CONCAT44(param_5,param_4);
        }
        if (local_656c < 1e-06) {
          FUN_005168b0(0x14df,*(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8f28),0,0);
          local_8._0_1_ = 1;
          FUN_0041fd70();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          ExceptionList = local_10;
          return 0;
        }
      }
    }
    if ((*(int *)(local_64c0 + 0xb4) == 0) || (*(int *)(local_64c0 + 0xa8) != 0x17)) {
      if (*(int *)(local_64c0 + 0x11c) == 0) {
        if (*(int *)(local_64c0 + 0xb8) != 0) {
          if (*(int **)(local_64c0 + 0xb8) != (int *)0x0) {
            (**(code **)(**(int **)(local_64c0 + 0xb8) + 4))(1);
          }
          *(undefined4 *)(local_64c0 + 0xb8) = 0;
        }
      }
      else if (*(int *)(local_64c0 + 0xbc) != 0) {
        if (*(int **)(local_64c0 + 0xbc) != (int *)0x0) {
          (**(code **)(**(int **)(local_64c0 + 0xbc) + 4))(1);
        }
        *(undefined4 *)(local_64c0 + 0xbc) = 0;
      }
    }
    else {
      local_198 = 1;
      local_194 = 1;
      iVar3 = FUN_0044a270(3,*(undefined4 *)(local_64c0 + 4),&param_2,&local_64c4,1);
      if (iVar3 == 0) {
        *(undefined4 *)(local_64c0 + 0xb4) = 0;
        local_8._0_1_ = 1;
        FUN_0041fd70();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return 0;
      }
      iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
      if (iVar3 == 0) {
        iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar3 == 0) {
          *(undefined4 *)(local_64c0 + 0xb4) = 0;
          local_8._0_1_ = 1;
          FUN_0041fd70();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          ExceptionList = local_10;
          return 0;
        }
      }
      else {
        fVar4 = (float10)FUN_0040c100();
        local_658c = (double)fVar4;
        local_6574 = local_658c;
        if (local_658c <= 0.0) {
          local_6574 = -local_658c;
        }
        if (local_6574 - 6.283185307179586 <= 0.0) {
          local_657c = local_658c;
          if (local_658c <= 0.0) {
            local_657c = -local_658c;
          }
          local_6584 = -(local_657c - 6.283185307179586);
        }
        else {
          if (local_658c <= 0.0) {
            local_658c = -local_658c;
          }
          local_6584 = local_658c - 6.283185307179586;
        }
        if ((local_6584 <= 1e-07) || (iVar3 = FUN_0040c200(), iVar3 == 1)) {
          FUN_005168b0(0x1458,*(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8f28),0,0);
          *(undefined4 *)(local_64c0 + 0xb4) = 0;
          local_8._0_1_ = 1;
          FUN_0041fd70();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          ExceptionList = local_10;
          return 0;
        }
      }
      *(undefined4 *)(local_64c0 + 0xb4) = 0;
      (**(code **)(*local_64c4 + 0x30))(&local_24,param_2,param_3,param_4,param_5);
      FUN_004988c0(local_ac,local_24,local_20,local_1c,local_18);
      if (*(int *)(local_64c0 + 0x11c) != 0) {
        if (*(int *)(local_64c0 + 0xbc) != 0) {
          if (*(int **)(local_64c0 + 0xbc) != (int *)0x0) {
            (**(code **)(**(int **)(local_64c0 + 0xbc) + 4))(1);
          }
          *(undefined4 *)(local_64c0 + 0xbc) = 0;
        }
        uVar2 = (**(code **)(*local_64c4 + 0x14))();
        *(undefined4 *)(local_64c0 + 0xbc) = uVar2;
        *(int *)(local_64c0 + 0x11c) = *(int *)(local_64c0 + 0x11c) + 1;
        *(undefined4 *)(local_64c0 + 0x120) = 0;
        *(ulonglong *)(local_64c0 + 0x130 + *(int *)(local_64c0 + 0x11c) * 8) =
             CONCAT44(param_3,param_2);
        *(ulonglong *)(local_64c0 + 0x1120 + *(int *)(local_64c0 + 0x11c) * 8) =
             CONCAT44(param_5,param_4);
        local_8._0_1_ = 1;
        FUN_0041fd70();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return 1;
      }
      if (*(int *)(local_64c0 + 0xb8) != 0) {
        if (*(int **)(local_64c0 + 0xb8) != (int *)0x0) {
          (**(code **)(**(int **)(local_64c0 + 0xb8) + 4))(1);
        }
        *(undefined4 *)(local_64c0 + 0xb8) = 0;
      }
      uVar2 = (**(code **)(*local_64c4 + 0x14))();
      *(undefined4 *)(local_64c0 + 0xb8) = uVar2;
      if (*(int *)(local_64c0 + 0xbc) != 0) {
        if (*(int **)(local_64c0 + 0xbc) != (int *)0x0) {
          (**(code **)(**(int **)(local_64c0 + 0xbc) + 4))(1);
        }
        *(undefined4 *)(local_64c0 + 0xbc) = 0;
      }
    }
    *(undefined4 *)(local_64c0 + 0x120) = 0;
    *(int *)(local_64c0 + 0x11c) = *(int *)(local_64c0 + 0x11c) + 1;
    *(ulonglong *)(local_64c0 + 0x130 + *(int *)(local_64c0 + 0x11c) * 8) =
         CONCAT44(param_3,param_2);
    *(ulonglong *)(local_64c0 + 0x1120 + *(int *)(local_64c0 + 0x11c) * 8) =
         CONCAT44(param_5,param_4);
    FUN_006b3ed0();
    if (*(int *)(local_64c0 + 0x11c) == 1) {
      *(undefined4 *)(local_64c0 + 0xac) = 2;
    }
    if (1 < *(int *)(local_64c0 + 0x11c)) {
      *(undefined4 *)(local_64c0 + 0xac) = 3;
    }
    FUN_00404c80();
    FUN_0056d7d0();
    local_8._0_1_ = 1;
    FUN_0041fd70();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    uVar2 = 0;
  }
  else {
    FUN_005168b0(0x1461,*(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(local_64c0 + 4) + 0x8f28),0,0);
    local_8._0_1_ = 1;
    FUN_0041fd70();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    uVar2 = 0;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiKyokuSen[11] */
/* 006b5740  FUN_006b5740  382 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006b5740(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  puStack_c = &LAB_00938a20;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((*(int *)(in_ECX + 0xa8) == 0x15) || (*(int *)(in_ECX + 0xa8) == 0x16)) &&
     (*(int *)(in_ECX + 0xac) == 1)) {
    uVar1 = FUN_006b4690(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    FUN_00446aa0(local_14);
    local_8 = 0;
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    local_18 = param_5;
    iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
    if (iVar2 == 1) {
      uVar1 = FUN_006b4690(param_1,local_24,local_20,local_1c,local_18);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiKyokuSen[4] */
/* 006b58c0  FUN_006b58c0  761 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006b58c0(void)

{
  undefined4 *puVar1;
  undefined1 local_642c [20];
  undefined4 local_6418;
  undefined4 local_6414;
  undefined4 local_6410;
  int local_640c;
  int local_6408;
  int *local_6404;
  int *local_6400;
  int *local_63fc;
  int local_63f8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938e5b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_6408 = *(int *)(local_63f8 + 4);
  if (local_6408 == 0) {
    local_640c = 0;
  }
  else {
    local_640c = local_6408 + 0x88;
  }
  FUN_00454890();
  FUN_00454830();
  FUN_0044dd90(local_642c,*(undefined4 *)(local_63f8 + 4));
  FUN_0044dd20(local_642c,*(undefined4 *)(local_63f8 + 4));
  FUN_0044de00(local_642c,*(undefined4 *)(local_63f8 + 4));
  FUN_0044c990(*(undefined4 *)(local_63f8 + 4),local_642c);
  FUN_00449d60();
  puVar1 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
  FUN_00517640(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  if (*(int *)(local_63f8 + 0x118) != 0) {
    local_63fc = *(int **)(local_63f8 + 0x118);
    if (local_63fc == (int *)0x0) {
      local_6410 = 0;
    }
    else {
      local_6410 = (**(code **)(*local_63fc + 4))();
    }
    *(undefined4 *)(local_63f8 + 0x118) = 0;
  }
  if (*(int *)(local_63f8 + 0xb8) != 0) {
    local_6400 = *(int **)(local_63f8 + 0xb8);
    if (local_6400 == (int *)0x0) {
      local_6414 = 0;
    }
    else {
      local_6414 = (**(code **)(*local_6400 + 4))();
    }
    *(undefined4 *)(local_63f8 + 0xb8) = 0;
  }
  if (*(int *)(local_63f8 + 0xbc) != 0) {
    local_6404 = *(int **)(local_63f8 + 0xbc);
    if (local_6404 == (int *)0x0) {
      local_6418 = 0;
    }
    else {
      local_6418 = (**(code **)(*local_6404 + 4))();
    }
    *(undefined4 *)(local_63f8 + 0xbc) = 0;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKyokuSen[3] */
/* 006b5bc0  FUN_006b5bc0  1071 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006b5bc0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_6414 [20];
  undefined4 local_6400;
  double local_63fc;
  double local_63f4;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ca4b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  local_6400 = FUN_0040c0e0(uVar1);
  FUN_00446aa0();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044dd90(local_6414,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd20(local_6414,*(undefined4 *)(local_63e8 + 4));
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8624)) {
    FUN_00404c80();
    FUN_004fca20();
    uVar3 = FUN_00551840();
    *(undefined4 *)(local_63e8 + 0x128) = uVar3;
  }
  if (*(int *)(local_63e8 + 0xa8) == 0x15) {
    FUN_006b6ea0();
    *(undefined4 *)(local_63e8 + 0x120) = 0;
  }
  if (*(int *)(local_63e8 + 0xa8) == 0x16) {
    FUN_006b5ff0();
    *(undefined4 *)(local_63e8 + 0x120) = 0;
  }
  if (*(int *)(local_63e8 + 0xa8) == 0x17) {
    local_63ec = 0;
    if (*(double *)(local_63e8 + 0x130 + *(int *)(local_63e8 + 0x11c) * 8) -
        *(double *)(local_63e8 + 0x138) <= 0.0) {
      local_63f4 = -(*(double *)(local_63e8 + 0x130 + *(int *)(local_63e8 + 0x11c) * 8) -
                    *(double *)(local_63e8 + 0x138));
    }
    else {
      local_63f4 = *(double *)(local_63e8 + 0x130 + *(int *)(local_63e8 + 0x11c) * 8) -
                   *(double *)(local_63e8 + 0x138);
    }
    if (local_63f4 < 1e-07) {
      if (*(double *)(local_63e8 + 0x1120 + *(int *)(local_63e8 + 0x11c) * 8) -
          *(double *)(local_63e8 + 0x1128) <= 0.0) {
        local_63fc = -(*(double *)(local_63e8 + 0x1120 + *(int *)(local_63e8 + 0x11c) * 8) -
                      *(double *)(local_63e8 + 0x1128));
      }
      else {
        local_63fc = *(double *)(local_63e8 + 0x1120 + *(int *)(local_63e8 + 0x11c) * 8) -
                     *(double *)(local_63e8 + 0x1128);
      }
      if (((local_63fc < 1e-07) && (*(int *)(local_63e8 + 0xb8) == 0)) &&
         (*(int *)(local_63e8 + 0xbc) == 0)) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8624)) {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x394) != 0) {
            local_63ec = 1;
          }
        }
      }
    }
    iVar2 = FUN_006b76e0(local_63ec);
    if (iVar2 != 0) {
      *(undefined4 *)(local_63e8 + 0x120) = *(undefined4 *)(local_63e8 + 0x11c);
    }
  }
  if (*(int *)(local_63e8 + 0xa8) == 0x18) {
    iVar2 = FUN_006b2b40();
    if (iVar2 != 0) {
      *(undefined4 *)(local_63e8 + 0x120) = *(undefined4 *)(local_63e8 + 0x11c);
    }
  }
  *(undefined4 *)(local_63e8 + 0x11c) = 0;
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



