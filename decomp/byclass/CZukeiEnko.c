/* CZukeiEnko -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiEnko[1] */
/* 00646910  FUN_00646910  68 bytes, 0 callers */

undefined4 FUN_00646910(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00646820();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x450);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiEnko[6] */
/* 00646960  FUN_00646960  2135 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00646960(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  float10 fVar3;
  double local_686c;
  double local_6864;
  undefined1 local_685c [20];
  double local_6848;
  int *local_6840;
  undefined1 local_683c [25552];
  undefined1 local_46c [16];
  undefined1 local_45c [16];
  undefined1 local_44c [16];
  undefined1 local_43c [16];
  undefined1 local_42c [16];
  undefined1 local_41c [516];
  undefined1 local_218 [516];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938376;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(local_6840[1] + 0x85f0)) {
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    local_6840[0x3b] = *(int *)(*(int *)(iVar2 + 0x1a0) + 600);
    *(undefined4 *)(local_6840[1] + 0x8ebc) = 0;
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(local_6840[1]);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0040c0e0();
    FUN_004988c0(local_42c,*param_1,param_1[1],param_1[2],param_1[3]);
    FUN_0044dd90(local_685c,local_6840[1]);
    FUN_0044de00(local_685c,local_6840[1]);
    if (local_6840[0xc2] == 0) {
      iVar2 = local_6840[1];
      FUN_004988c0(local_43c,*(undefined4 *)(iVar2 + 0x8f78),*(undefined4 *)(iVar2 + 0x8f7c),
                   *(undefined4 *)(iVar2 + 0x8f80),*(undefined4 *)(iVar2 + 0x8f84));
    }
    else {
      iVar2 = local_6840[1];
      FUN_004988c0(local_44c,*(undefined4 *)(iVar2 + 0x8f78),*(undefined4 *)(iVar2 + 0x8f7c),
                   *(undefined4 *)(iVar2 + 0x8f80),*(undefined4 *)(iVar2 + 0x8f84));
    }
    if ((((local_6840[0xc2] == 2) && (local_6840[0xc3] == 0)) &&
        (*(int *)(local_6840[1] + 0x1780) != 0)) && (*(int *)(local_6840[1] + 0x176c) != 0)) {
      FUN_0041df00(local_6840[4],local_6840[5],local_6840[6],local_6840[7],local_6840 + 8);
    }
    (**(code **)(*local_6840 + 0x20))();
    if (1e-07 < *(double *)(local_6840 + 0x2a)) {
      if (*(double *)(local_6840 + 0x34) <= 0.0) {
        local_6864 = -*(double *)(local_6840 + 0x34);
      }
      else {
        local_6864 = *(double *)(local_6840 + 0x34);
      }
      if (1e-07 < local_6864) {
        FUN_00464040();
        local_8._0_1_ = 2;
        FUN_0047f220(local_6840[1],local_683c,local_685c,local_6840 + 0xc6,
                     (int)*(undefined8 *)(local_6840 + 0x3c),
                     (int)((ulonglong)*(undefined8 *)(local_6840 + 0x3c) >> 0x20),0);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_004640a0();
      }
    }
    if (local_6840[0xc2] == 0) {
      *(undefined4 *)(local_6840[1] + 0x8ebc) = 1;
      if (local_6840[0xc3] == 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_004ab530();
        local_6848 = (double)fVar3;
        local_686c = local_6848;
        if (local_6848 <= 0.0) {
          local_686c = -local_6848;
        }
        if (1e-07 <= local_686c) {
          FUN_00647b40(local_41c);
          FUN_004efbb0(0x14b5,local_41c,0);
        }
        else {
          FUN_004efbb0(0x14bd,local_6840 + 0x5e,0);
        }
      }
      else {
        FUN_004efbb0(0x1503,0,0);
      }
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_00647b40(local_218);
      if (local_6840[0xc2] == 2) {
        if (local_6840[0xc3] == 0) {
          if (local_6840[0x3a] == 0) {
            FUN_004efbb0(0x14b8,local_218,1);
          }
          else {
            FUN_004efbb0(0x14b5,local_218,1);
          }
        }
        else {
          FUN_004efbb0(0x1504,0,0);
        }
      }
      if (local_6840[0xc2] == 5) {
        if (local_6840[0xc3] == 0) {
          FUN_004efbb0(0x14c9,local_218,0);
        }
        else {
          if (local_6840[0xc3] == 2) {
            FUN_004efbb0(0x1506,local_218,0);
          }
          if (local_6840[0xc3] == 3) {
            FUN_00404c80();
            FUN_004fca20();
            fVar3 = (float10)FUN_004ab530();
            if (1e-07 <= (double)fVar3) {
              if (local_6840[0x3a] == 0) {
                FUN_004efbb0(0x1574,local_218,0);
                FUN_00420020(local_6840 + 0xc6);
                FUN_0042f5a0((int)*(undefined8 *)(local_6840 + 0x36),
                             (uint)((ulonglong)*(undefined8 *)(local_6840 + 0x36) >> 0x20) ^
                             0x80000000);
                *(undefined1 *)(local_6840 + 0xf6) = 9;
                FUN_00450b70(local_685c,local_6840[1],local_6840 + 0xec);
                FUN_004988c0(local_46c,local_6840[0x4c],local_6840[0x4d],local_6840[0x4e],
                             local_6840[0x4f]);
                FUN_0042f620((int)*(undefined8 *)(local_6840 + 0x32),
                             (int)((ulonglong)*(undefined8 *)(local_6840 + 0x32) >> 0x20));
                FUN_0042f5a0((int)*(undefined8 *)(local_6840 + 0x36),
                             (int)((ulonglong)*(undefined8 *)(local_6840 + 0x36) >> 0x20));
                FUN_00450b70(local_685c,local_6840[1],local_6840 + 0xec);
                fVar3 = (float10)FUN_0040c100();
                FUN_0042f5a0(SUB84((double)fVar3,0),
                             (uint)((ulonglong)(double)fVar3 >> 0x20) ^ 0x80000000);
                FUN_00450b70(local_685c,local_6840[1],local_6840 + 0xec);
              }
              else {
                FUN_00420020(local_6840 + 0xc6);
                FUN_004988c0(local_45c,local_6840[0x4c],local_6840[0x4d],local_6840[0x4e],
                             local_6840[0x4f]);
                *(undefined1 *)(local_6840 + 0xf6) = 9;
                FUN_00450b70(local_685c,local_6840[1],local_6840 + 0xec);
              }
            }
            else {
              FUN_004efbb0(0x1505,local_218,0);
            }
          }
        }
      }
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiEnko[16] */
/* 006471c0  FUN_006471c0  944 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006471c0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  float10 fVar4;
  undefined1 local_6450 [20];
  double local_643c;
  double local_6434;
  undefined4 local_642c;
  int local_6428;
  undefined4 local_12c;
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009383bb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined2 *)(in_ECX + 0x178) = 0;
  local_14 = uVar1;
  if (*(int *)(in_ECX + 0x308) == 0) {
    if (*(int *)(in_ECX + 0x30c) != 0) {
      *(undefined4 *)(in_ECX + 0xe8) = 0;
    }
    if (*(int *)(in_ECX + 0xf8) == 0) {
      local_642c = 0;
    }
    else {
      local_6428 = in_ECX;
      FUN_00404c80(uVar1);
      iVar2 = FUN_004fca20();
      if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_6428 + 4) + 0x85f0)) {
        FUN_00404c80(uVar1);
        FUN_004fca20();
        fVar4 = (float10)FUN_004ab530();
        local_6434 = (double)fVar4;
        local_643c = local_6434;
        if (local_6434 <= 0.0) {
          local_643c = -local_6434;
        }
        if ((1e-07 < local_643c) && (*(int *)(local_6428 + 0xe8) == 1)) {
          ExceptionList = local_10;
          return 0;
        }
      }
      FUN_0079dea2(*(undefined4 *)(local_6428 + 4));
      local_8 = 0;
      FUN_00446aa0();
      local_8._0_1_ = 1;
      FUN_00458a80(local_6450,*(undefined4 *)(local_6428 + 4),0);
      puVar3 = (undefined4 *)
               FUN_004988c0(local_24,*(undefined4 *)(local_6428 + 0x100),
                            *(undefined4 *)(local_6428 + 0x104),*(undefined4 *)(local_6428 + 0x108),
                            *(undefined4 *)(local_6428 + 0x10c));
      FUN_004988c0(local_34,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
      puVar3 = (undefined4 *)
               FUN_004988c0(local_44,*(undefined4 *)(local_6428 + 0x110),
                            *(undefined4 *)(local_6428 + 0x114),*(undefined4 *)(local_6428 + 0x118),
                            *(undefined4 *)(local_6428 + 0x11c));
      FUN_004988c0(local_54,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
      *(undefined8 *)(local_6428 + 0xd0) = *(undefined8 *)(local_6428 + 0x170);
      if (*(int *)(local_6428 + 0xe8) == 0) {
        *(undefined4 *)(local_6428 + 0x308) = 5;
      }
      else {
        *(undefined4 *)(local_6428 + 0x308) = 2;
      }
      local_12c = 0;
      *(undefined4 *)(local_6428 + 0xf8) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      local_642c = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
  }
  else {
    *(int *)(*(int *)(in_ECX + 4) + 0x8560) = *(int *)(*(int *)(in_ECX + 4) + 0x8560) + -1;
    if (*(int *)(in_ECX + 0xe8) == 0) {
      if (*(int *)(in_ECX + 0x308) == 5) {
        *(undefined4 *)(in_ECX + 0x308) = 2;
      }
      else {
        *(undefined4 *)(in_ECX + 0x308) = 0;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x308) = 0;
    }
    *(undefined4 *)(in_ECX + 0xf8) = 0;
    FUN_00404c80(uVar1);
    FUN_0056d7d0();
    local_642c = 1;
  }
  ExceptionList = local_10;
  return local_642c;
}




/* vtable slots: CZukeiEnko[52] */
/* 00647580  FUN_00647580  1323 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00647580(void)

{
  undefined4 uVar1;
  float10 fVar2;
  float10 fVar3;
  double dVar4;
  double dVar5;
  double local_645c;
  double local_6454;
  double local_644c;
  double local_6444;
  double local_6408;
  double local_6400;
  double local_63f8;
  double local_63f0;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938400;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  dVar4 = *(double *)(local_63e8 + 0x20) - *(double *)(local_63e8 + 0x10);
  dVar5 = *(double *)(local_63e8 + 0x28) - *(double *)(local_63e8 + 0x18);
  fVar2 = (float10)FUN_008f8eb0((int)*(undefined8 *)(local_63e8 + 0xb8),
                                (int)((ulonglong)*(undefined8 *)(local_63e8 + 0xb8) >> 0x20));
  fVar3 = (float10)FUN_008f8f00((int)*(undefined8 *)(local_63e8 + 0xb8),
                                (int)((ulonglong)*(undefined8 *)(local_63e8 + 0xb8) >> 0x20));
  local_63f8 = (double)fVar2 * dVar4 + (double)fVar3 * dVar5;
  local_63f0 = ((double)fVar2 * dVar5 - (double)fVar3 * dVar4) / *(double *)(local_63e8 + 0xe0);
  local_6444 = local_63f8;
  if (local_63f8 <= 0.0) {
    local_6444 = -local_63f8;
  }
  local_644c = local_63f0;
  if (local_63f0 <= 0.0) {
    local_644c = -local_63f0;
  }
  if (1e-07 <= local_6444 + local_644c) {
    fVar2 = (float10)FUN_008f8d00(SUB84(local_63f0,0),(int)((ulonglong)local_63f0 >> 0x20),
                                  SUB84(local_63f8,0),(int)((ulonglong)local_63f8 >> 0x20));
    local_6400 = (double)fVar2 - *(double *)(local_63e8 + 0xc0);
    local_6454 = local_6400;
    if (local_6400 <= 0.0) {
      local_6454 = -local_6400;
    }
    if (1e-07 <= local_6454) {
      if (*(double *)(local_63e8 + 0xd0) <= 0.0) {
        local_645c = -*(double *)(local_63e8 + 0xd0);
      }
      else {
        local_645c = *(double *)(local_63e8 + 0xd0);
      }
      if (0.7853981633974483 <= local_645c) {
        local_6408 = *(double *)(local_63e8 + 0xd0);
      }
      else {
        fVar2 = (float10)FUN_008f8eb0((int)*(undefined8 *)(local_63e8 + 0xc0),
                                      (int)((ulonglong)*(undefined8 *)(local_63e8 + 0xc0) >> 0x20));
        dVar4 = *(double *)(local_63e8 + 0xa8);
        fVar3 = (float10)FUN_008f8f00((int)*(undefined8 *)(local_63e8 + 0xc0),
                                      (int)((ulonglong)*(undefined8 *)(local_63e8 + 0xc0) >> 0x20));
        local_6408 = ((double)fVar2 * dVar4 - 0.0) * (local_63f0 - 0.0) -
                     (local_63f8 - 0.0) * ((double)fVar3 * *(double *)(local_63e8 + 0xa8) - 0.0);
        if (local_6408 == 0.0) {
          *(undefined8 *)(local_63e8 + 0xd0) = 0;
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
      }
      if (local_6408 == 0.0) {
        *(undefined8 *)(local_63e8 + 0xd0) = 0;
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        FUN_0040b250(SUB84(local_6408,0),(int)((ulonglong)local_6408 >> 0x20),&local_6400);
        *(double *)(local_63e8 + 0xd0) = local_6400;
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 1;
      }
    }
    else {
      *(undefined8 *)(local_63e8 + 0xd0) = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
  }
  else {
    *(undefined8 *)(local_63e8 + 0xd0) = 0;
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar1 = 0;
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiEnko[0] */
/* 00647ad0  FUN_00647ad0  16 bytes, 0 callers */

undefined ** FUN_00647ad0(void)

{
  return &PTR_s_CZukeiEnko_009780a0;
}




/* vtable slots: CZukeiEnko[23] */
/* 00647d40  FUN_00647d40  412 bytes, 0 callers */

undefined4 FUN_00647d40(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  uint local_c;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) != *(int *)(in_ECX[1] + 0x85f0)) {
    return 0;
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) != *(int *)(in_ECX[1] + 0x85f0)) {
    return 0;
  }
  if (DAT_00a0cc6c != 0) {
    (**(code **)(*in_ECX + 100))();
    goto LAB_00647ec3;
  }
  FUN_00404c80();
  FUN_004fca20();
  iVar1 = FUN_00647b00();
  if (iVar1 == 1) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x270) == 0) goto LAB_00647e36;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x270) = 0;
    uVar2 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_00648810(uVar2);
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007955d2();
  }
  else {
LAB_00647e36:
    FUN_00404c80();
    FUN_004fca20();
    iVar1 = FUN_00647ab0();
    local_c = (uint)(iVar1 == 0);
    FUN_00404c80(local_c);
    FUN_004fca20();
    FUN_00648810(local_c);
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007955d2();
    FUN_00404c80();
    FUN_004fca20();
    FUN_004abbe0();
  }
  FUN_00404c80();
  FUN_004fca20();
  FUN_004ac460();
LAB_00647ec3:
  FUN_00404c80();
  FUN_0056d7d0();
  return 1;
}




/* vtable slots: CZukeiEnko[46] */
/* 00647ee0  FUN_00647ee0  997 bytes, 0 callers */

undefined4
FUN_00647ee0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  float10 fVar2;
  undefined8 uVar3;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (DAT_00a0c7c0 == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_8 + 4) + 0x85f0)) {
      local_10 = 0;
      if (*(int *)(*(int *)(local_8 + 4) + 0x9078) == 0) {
        local_1c = 0xffffffff;
        iVar1 = FUN_00778a40(1,&local_1c,*(undefined4 *)(*(int *)(local_8 + 4) + 0x9070),param_1,
                             param_2,param_3,param_4,param_5,param_6,param_7,4);
        if (iVar1 == 0) {
          if ((param_2 == 0xc) && (*(int *)(local_8 + 0x308) != 0)) {
            if (param_3 == 1) {
              FUN_005168b0(0x2733,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f50),
                           *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              FUN_005156d0();
            }
          }
          else {
            local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          }
        }
        else {
          local_10 = 0;
        }
      }
      else {
        local_c = param_2;
        if (param_2 == 1) {
          if (param_3 == 1) {
            FUN_005168b0(0x17da,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_00404c80();
            FUN_004fca20();
            iVar1 = FUN_00647ab0();
            local_14 = (uint)(iVar1 == 0);
            FUN_00404c80();
            FUN_004fca20();
            FUN_00648810();
            FUN_00404c80();
            FUN_004fca20();
            FUN_007955d2();
            FUN_00404c80();
            FUN_004fca20();
            FUN_004abbe0();
          }
        }
        else if (param_2 == 2) {
          if (param_3 == 1) {
            FUN_005168b0(0x17db,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_00404c80();
            FUN_004fca20();
            iVar1 = FUN_00647b20();
            local_18 = (uint)(iVar1 == 0);
            FUN_00404c80();
            FUN_004fca20();
            FUN_00649500();
            FUN_00404c80();
            FUN_004fca20();
            FUN_007955d2();
          }
        }
        else if (param_2 == 0xc) {
          if (param_3 == 1) {
            FUN_005168b0(0x1810,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_00404c80();
            FUN_004fca20();
            fVar2 = (float10)FUN_004abb30();
            *(double *)(local_8 + 0xb8) = (double)fVar2;
            *(ulonglong *)(local_8 + 0xb8) = *(ulonglong *)(local_8 + 0xb8) ^ 0x8000000000000000;
            uVar3 = *(undefined8 *)(local_8 + 0xb8);
            FUN_00404c80(uVar3);
            FUN_004fca20();
            FUN_004ac7f0(uVar3);
          }
        }
        else {
          local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        }
      }
    }
    else {
      local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_10;
}




/* vtable slots: CZukeiEnko[47] */
/* 006482d0  FUN_006482d0  231 bytes, 0 callers */

undefined4
FUN_006482d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                           param_3,param_4,param_5,param_6,param_7,4);
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




/* vtable slots: CZukeiEnko[25] */
/* 006483c0  FUN_006483c0  274 bytes, 0 callers */

void FUN_006483c0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined8 local_18;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f0)) {
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004ab530();
    local_18 = (double)fVar2;
    if (local_18 <= 0.0) {
      local_18 = -local_18;
    }
    if (local_18 <= 1e-07) {
      *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 2;
      if (2 < *(int *)(in_ECX + 0xec)) {
        *(undefined4 *)(in_ECX + 0xec) = 0;
      }
    }
    else {
      *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 1;
      if (8 < *(int *)(in_ECX + 0xec)) {
        *(undefined4 *)(in_ECX + 0xec) = 0;
      }
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 600) = *(undefined4 *)(in_ECX + 0xec);
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiEnko[49] */
/* 006484e0  FUN_006484e0  83 bytes, 1 callers */

void FUN_006484e0(undefined8 param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f0)) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_004ac7f0(param_1);
  }
  return;
}




/* vtable slots: CZukeiEnko[50] */
/* 00648540  FUN_00648540  100 bytes, 1 callers */

void FUN_00648540(double param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if ((*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f0)) && (1e-07 <= param_1)) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_004ac6e0(param_1);
  }
  return;
}




/* vtable slots: CZukeiEnko[51] */
/* 006485b0  FUN_006485b0  234 bytes, 0 callers */

void FUN_006485b0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int in_ECX;
  double in_stack_00000024;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f0)) {
    FUN_006484e0(param_1);
    FUN_00648540(param_2);
    if ((in_stack_00000024 < 1000.0) && (5.0 < in_stack_00000024)) {
      FUN_00404c80(in_stack_00000024);
      FUN_004fca20();
      FUN_004ac7a0(in_stack_00000024);
    }
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




/* vtable slots: CZukeiEnko[15] */
/* 006486a0  FUN_006486a0  327 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006486a0(void)

{
  int in_ECX;
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
  *(undefined2 *)(in_ECX + 0x178) = 0;
  local_63e8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
  FUN_0044de00(local_6400,*(undefined4 *)(local_63e8 + 4));
  FUN_00453bd0(local_6400,*(undefined4 *)(local_63e8 + 4),0);
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
  *(undefined4 *)(local_63e8 + 0xf8) = 0;
  FUN_00404c80();
  FUN_0056d7d0();
  local_63ec = 1;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiEnko[10] */
/* 00648830  FUN_00648830  1205 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00648830(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
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
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009384bb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(local_14);
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f0)) {
    uVar2 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_004aafb0(uVar2);
    if (*(int *)(in_ECX + 0x448) != 0) {
      uVar2 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_006487f0(uVar2);
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007955d2();
      FUN_00404c80();
      FUN_004fca20();
      FUN_004abbe0();
    }
    if (*(int *)(*(int *)(in_ECX + 4) + 0x8588) != 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x260) != 0) {
        FUN_00404c80();
        FUN_004fca20();
        FUN_004ab190();
      }
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x264) != 0) {
        FUN_00404c80();
        FUN_004fca20();
        FUN_004ab240();
      }
    }
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar1 = *(int *)(in_ECX + 4);
    local_24 = *(undefined4 *)(iVar1 + 0x8f68);
    local_20 = *(undefined4 *)(iVar1 + 0x8f6c);
    local_1c = *(undefined4 *)(iVar1 + 0x8f70);
    local_18 = *(undefined4 *)(iVar1 + 0x8f74);
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9068) != 0) {
      local_645c = 0;
      iVar1 = FUN_0079d98a(&PTR_s_CZukeiSen_0097a430);
      if (iVar1 != 0) {
        local_645c = *(int *)(param_1 + 0xa8);
      }
      iVar1 = FUN_0079d98a(&PTR_s_CZukeiEnko_009780a0);
      if (iVar1 != 0) {
        local_645c = *(int *)(param_1 + 0x308);
      }
      if (local_645c == 0) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f34) = 1;
        FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
        *(undefined4 *)(in_ECX + 0x308) = 2;
        iVar1 = *(int *)(in_ECX + 4);
        FUN_004988c0(local_54,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
                     *(undefined4 *)(iVar1 + 0x8f70),*(undefined4 *)(iVar1 + 0x8f74));
        iVar1 = *(int *)(in_ECX + 4);
        FUN_004988c0(local_64,*(undefined4 *)(iVar1 + 0x8f88),*(undefined4 *)(iVar1 + 0x8f8c),
                     *(undefined4 *)(iVar1 + 0x8f90),*(undefined4 *)(iVar1 + 0x8f94));
      }
      else {
        *(undefined4 *)(in_ECX + 0x308) = 2;
        FUN_004988c0(local_34,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                     *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
        iVar1 = *(int *)(in_ECX + 4);
        FUN_004988c0(local_44,*(undefined4 *)(iVar1 + 0x8f88),*(undefined4 *)(iVar1 + 0x8f8c),
                     *(undefined4 *)(iVar1 + 0x8f90),*(undefined4 *)(iVar1 + 0x8f94));
        FUN_00646960(in_ECX + 0x20);
      }
    }
    if ((*(int *)(*(int *)(in_ECX + 4) + 0x906c) != 0) &&
       (iVar1 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1), iVar1 != 0)) {
      FUN_004988c0(local_74,local_24,local_20,local_1c,local_18);
      iVar1 = *(int *)(in_ECX + 4);
      FUN_004988c0(local_84,*(undefined4 *)(iVar1 + 0x8f88),*(undefined4 *)(iVar1 + 0x8f8c),
                   *(undefined4 *)(iVar1 + 0x8f90),*(undefined4 *)(iVar1 + 0x8f94));
      *(undefined4 *)(in_ECX + 0x308) = 2;
    }
    FUN_00646960(in_ECX + 0x20);
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b0) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b4) = 0;
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiEnko[9] */
/* 00648cf0  FUN_00648cf0  1537 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00648cf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *in_ECX;
  double local_c0;
  double local_b8;
  int local_ac;
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
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
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938500;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_0079dea2(in_ECX[1]);
  local_8 = 0;
  local_ac = 0;
  if (in_ECX[0xc2] == 0) {
    in_ECX[0xc2] = 2;
    puVar2 = (undefined4 *)FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
    puVar2 = (undefined4 *)FUN_004988c0(local_34,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    puVar2 = (undefined4 *)FUN_004988c0(local_44,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    FUN_004988c0(local_54,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    (**(code **)(*in_ECX + 0x20))();
    *(undefined4 *)(in_ECX[1] + 0x8560) = 1;
    if ((*(double *)(in_ECX + 0x2a) <= 1e-07) || (in_ECX[0x3a] == 0)) {
      local_ac = 0;
    }
    else {
      local_ac = 1;
    }
  }
  else if (in_ECX[0xc2] == 2) {
    if ((((*(int *)(in_ECX[1] + 0x1780) != 0) && (*(int *)(in_ECX[1] + 0x176c) != 0)) &&
        (param_1 != 0x231d)) && (in_ECX[0xc3] == 0)) {
      FUN_0041df00(in_ECX[4],in_ECX[5],in_ECX[6],in_ECX[7],&param_2);
    }
    puVar2 = (undefined4 *)FUN_004988c0(local_64,param_2,param_3,param_4,param_5);
    FUN_004988c0(local_74,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    if (*(double *)(in_ECX + 0x54) - *(double *)(in_ECX + 0x50) <= 0.0) {
      local_b8 = -(*(double *)(in_ECX + 0x54) - *(double *)(in_ECX + 0x50));
    }
    else {
      local_b8 = *(double *)(in_ECX + 0x54) - *(double *)(in_ECX + 0x50);
    }
    if (local_b8 < 1e-07) {
      if (*(double *)(in_ECX + 0x56) - *(double *)(in_ECX + 0x52) <= 0.0) {
        local_c0 = -(*(double *)(in_ECX + 0x56) - *(double *)(in_ECX + 0x52));
      }
      else {
        local_c0 = *(double *)(in_ECX + 0x56) - *(double *)(in_ECX + 0x52);
      }
      if (local_c0 < 1e-07) {
        FUN_005168b0(0x14df,*(undefined4 *)(in_ECX[1] + 0x8f24),*(undefined4 *)(in_ECX[1] + 0x8f28),
                     0,0);
        goto LAB_006492ab;
      }
    }
    (**(code **)(*in_ECX + 0x20))();
    if ((1e-07 < *(double *)(in_ECX + 0x2a) || *(double *)(in_ECX + 0x2a) == 1e-07) ||
       (in_ECX[0xc3] != 0)) {
      FUN_004988c0(local_84,in_ECX[8],in_ECX[9],in_ECX[10],in_ECX[0xb]);
      if (in_ECX[0x3a] == 0) {
        in_ECX[0xc2] = 5;
        in_ECX[0x34] = 0;
        in_ECX[0x35] = 0;
        *(undefined4 *)(in_ECX[1] + 0x8560) = 2;
        local_ac = 0;
      }
      else {
        in_ECX[0x34] = 0x54442d18;
        in_ECX[0x35] = 0x401921fb;
        local_ac = 1;
      }
    }
    else {
      in_ECX[0x30] = 0;
      in_ECX[0x31] = 0;
      local_ac = 0;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_004988c0(local_94,param_2,param_3,param_4,param_5);
    FUN_004988c0(local_a4,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    (**(code **)(*in_ECX + 0x20))(uVar1);
    if (in_ECX[0x3a] == 0) {
      iVar3 = (**(code **)(*in_ECX + 0xd0))();
      if (iVar3 == 0) {
        local_ac = 0;
        goto LAB_006492ab;
      }
    }
    *(undefined4 *)(in_ECX[1] + 0x8560) = 3;
    local_ac = 1;
  }
LAB_006492ab:
  if (local_ac == 0) {
    FUN_00404c80();
    FUN_0056d7d0();
  }
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return local_ac;
}




/* vtable slots: CZukeiEnko[11] */
/* 00649300  FUN_00649300  498 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00649300(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
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
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f0)) {
    if (*(int *)(in_ECX + 0x308) == 5) {
      if (*(int *)(in_ECX + 0x30c) == 2) {
        uVar3 = FUN_00648cf0(param_1,param_2,param_3,param_4,param_5);
        ExceptionList = local_10;
        return uVar3;
      }
      if (*(int *)(in_ECX + 0x30c) == 3) {
        FUN_00404c80(uVar1);
        FUN_004fca20();
        fVar4 = (float10)FUN_004ab530();
        if (1e-07 <= (double)fVar4) {
          uVar3 = FUN_00648cf0(param_1,param_2,param_3,param_4,param_5);
          ExceptionList = local_10;
          return uVar3;
        }
      }
    }
    FUN_00446aa0();
    local_8 = 0;
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    local_18 = param_5;
    iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
    if (iVar2 == 1) {
      uVar3 = FUN_00648cf0(0x231d,local_24,local_20,local_1c,local_18);
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




/* vtable slots: CZukeiEnko[8] */
/* 00649520  FUN_00649520  3790 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00649520(void)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double local_64ac;
  double local_64a4;
  double local_649c;
  double local_6494;
  int local_646c;
  uint local_6464;
  double local_6460;
  double local_6458;
  double local_6440;
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined8 local_24;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938540;
  local_10 = ExceptionList;
  uVar3 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6440 = 0.0;
  local_646c = 0;
  local_14 = uVar3;
  FUN_00404c80(uVar3);
  iVar4 = FUN_004fca20();
  if (*(int *)(iVar4 + 0x1a0) == *(int *)(in_ECX[1] + 0x85f0)) {
    FUN_00404c80(uVar3);
    FUN_004fca20();
    iVar4 = FUN_00647ab0();
    local_6464 = (uint)(iVar4 == 0);
    in_ECX[0x3a] = local_6464;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ab530();
    local_6494 = (double)fVar5;
    if (local_6494 <= 0.0) {
      local_6494 = -local_6494;
    }
    local_6440 = local_6494;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ab8a0();
    *(double *)(in_ECX + 0x38) = (double)fVar5;
    if ((-1e-07 < *(double *)(in_ECX + 0x38) || *(double *)(in_ECX + 0x38) == -1e-07) ||
       (local_6494 <= 1e-07)) {
      if ((*(double *)(in_ECX + 0x38) <= 0.01 && *(double *)(in_ECX + 0x38) != 0.01) ||
         (10.0 < *(double *)(in_ECX + 0x38))) {
        in_ECX[0x38] = 0;
        in_ECX[0x39] = 0x3ff00000;
      }
    }
    else {
      if (*(double *)(in_ECX + 0x38) <= 0.0) {
        local_649c = -*(double *)(in_ECX + 0x38);
      }
      else {
        local_649c = *(double *)(in_ECX + 0x38);
      }
      *(double *)(in_ECX + 0x38) = local_649c / local_6494;
      if ((*(double *)(in_ECX + 0x38) <= 0.01 && *(double *)(in_ECX + 0x38) != 0.01) ||
         (10.0 < *(double *)(in_ECX + 0x38))) {
        in_ECX[0x38] = 0;
        in_ECX[0x39] = 0x3ff00000;
      }
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004abb30();
    *(double *)(in_ECX + 0x2e) =
         (((double)fVar5 + *(double *)(in_ECX[1] + 0x17c0)) / 180.0) * 3.141592653589793;
    FUN_00404c80();
    FUN_004fca20();
    local_646c = FUN_00647b20();
    in_ECX[0xc3] = 0;
    FUN_00404c80();
    FUN_004fca20();
    iVar4 = FUN_00647ae0();
    if (iVar4 != 0) {
      in_ECX[0xc3] = 2;
    }
    FUN_00404c80();
    FUN_004fca20();
    iVar4 = FUN_00647b00();
    if (iVar4 != 0) {
      in_ECX[0xc3] = 3;
    }
    if (in_ECX[0xc3] != in_ECX[0xc4]) {
      in_ECX[0xc4] = in_ECX[0xc3];
      in_ECX[0x3a] = 0;
      in_ECX[0xc2] = 0;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ac890();
    *(double *)(in_ECX + 0x3c) = (double)fVar5;
  }
  local_24 = *(double *)(in_ECX + 4);
  local_1c = *(double *)(in_ECX + 6);
  dVar6 = *(double *)(in_ECX + 8) - *(double *)(in_ECX + 4);
  dVar7 = *(double *)(in_ECX + 10) - *(double *)(in_ECX + 6);
  fVar5 = (float10)FUN_008f8eb0(*(undefined8 *)(in_ECX + 0x2e));
  dVar1 = (double)fVar5;
  fVar5 = (float10)FUN_008f8f00(*(undefined8 *)(in_ECX + 0x2e));
  dVar2 = (double)fVar5;
  dVar8 = dVar1 * dVar6 + dVar2 * dVar7;
  dVar9 = (dVar1 * dVar7 - dVar2 * dVar6) / *(double *)(in_ECX + 0x38);
  if (in_ECX[0xc2] == 0) {
    if (in_ECX[0xc3] == 0) {
      *(double *)(in_ECX + 0x2a) = local_6440;
      if (local_6440 <= 1e-07) {
        in_ECX[0x34] = 0;
        in_ECX[0x35] = 0;
      }
      else {
        in_ECX[0x34] = 0x54442d18;
        in_ECX[0x35] = 0x401921fb;
      }
    }
    else {
      in_ECX[0x34] = 0;
      in_ECX[0x35] = 0;
      in_ECX[0x30] = 0;
      in_ECX[0x31] = 0;
      in_ECX[0x2a] = 0;
      in_ECX[0x2b] = 0;
      in_ECX[0x3a] = 0;
      FUN_004988c0(local_34,in_ECX[4],in_ECX[5],in_ECX[6],in_ECX[7]);
    }
  }
  else if (in_ECX[0xc2] == 2) {
    if (in_ECX[0xc3] == 0) {
      local_64a4 = dVar8;
      if (dVar8 <= 0.0) {
        local_64a4 = -dVar8;
      }
      local_64ac = dVar9;
      if (dVar9 <= 0.0) {
        local_64ac = -dVar9;
      }
      if (1e-07 <= local_64a4 + local_64ac) {
        fVar5 = (float10)FUN_008f8d00(dVar9,dVar8);
        *(double *)(in_ECX + 0x30) = (double)fVar5;
      }
      else {
        in_ECX[0x30] = 0;
        in_ECX[0x31] = 0;
      }
      while (3.141592653589793 < *(double *)(in_ECX + 0x30)) {
        *(double *)(in_ECX + 0x30) = *(double *)(in_ECX + 0x30) - 3.141592653589793;
      }
      while (*(double *)(in_ECX + 0x30) <= -3.141592653589793) {
        *(double *)(in_ECX + 0x30) = *(double *)(in_ECX + 0x30) + 3.141592653589793;
      }
      if (1e-07 < local_6440) {
        *(double *)(in_ECX + 0x2a) = local_6440;
      }
      else {
        fVar5 = (float10)FUN_008f8d10(dVar8 * dVar8 + dVar9 * dVar9);
        *(double *)(in_ECX + 0x2a) = (double)fVar5;
      }
      *(undefined8 *)(in_ECX + 0x2c) = *(undefined8 *)(in_ECX + 0x2a);
      in_ECX[0x34] = 0x54442d18;
      in_ECX[0x35] = 0x401921fb;
    }
    else {
      in_ECX[0x34] = 0;
      in_ECX[0x35] = 0;
      in_ECX[0x30] = 0;
      in_ECX[0x31] = 0;
      in_ECX[0x2a] = 0;
      in_ECX[0x2b] = 0;
      in_ECX[0x3a] = 0;
      FUN_004988c0(local_44,in_ECX[4],in_ECX[5],in_ECX[6],in_ECX[7]);
      FUN_004988c0(local_54,in_ECX[8],in_ECX[9],in_ECX[10],in_ECX[0xb]);
    }
  }
  else if (in_ECX[0xc3] == 0) {
    (**(code **)(*in_ECX + 0xd0))();
    if (local_646c == 0) {
      *(undefined8 *)(in_ECX + 0x2a) = *(undefined8 *)(in_ECX + 0x2c);
    }
    else if (local_6440 == 0.0) {
      fVar5 = (float10)FUN_008f8d10(dVar8 * dVar8 + dVar9 * dVar9);
      *(double *)(in_ECX + 0x2a) = (double)fVar5;
    }
    else {
      *(double *)(in_ECX + 0x2a) = local_6440;
    }
  }
  else {
    if (in_ECX[0xc3] == 2) {
      in_ECX[0x3a] = 0;
      iVar4 = FUN_0064a780();
      if (iVar4 == 0) {
        in_ECX[0x34] = 0;
        in_ECX[0x35] = 0;
        in_ECX[0x30] = 0;
        in_ECX[0x31] = 0;
        in_ECX[0x2a] = 0;
        in_ECX[0x2b] = 0;
        goto LAB_0064a01b;
      }
    }
    if (in_ECX[0xc3] == 3) {
      in_ECX[0x3a] = 0;
      FUN_00404c80();
      iVar4 = FUN_004fca20();
      if (*(int *)(iVar4 + 0x1a0) == *(int *)(in_ECX[1] + 0x85f0)) {
        FUN_00404c80();
        FUN_004fca20();
        iVar4 = FUN_00647ab0();
        if (iVar4 == 0) {
          in_ECX[0x3a] = 1;
        }
        FUN_00404c80();
        iVar4 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar4 + 0x1a0) + 0x270) != 0) {
          in_ECX[0x3a] = 0;
        }
      }
      iVar4 = FUN_0064ae30();
      if (iVar4 == 0) {
        in_ECX[0x34] = 0;
        in_ECX[0x35] = 0;
        in_ECX[0x30] = 0;
        in_ECX[0x31] = 0;
        in_ECX[0x2a] = 0;
        in_ECX[0x2b] = 0;
        goto LAB_0064a01b;
      }
    }
    FUN_004988c0(local_64,in_ECX[0x48],in_ECX[0x49],in_ECX[0x4a],in_ECX[0x4b]);
  }
LAB_0064a01b:
  if ((0 < in_ECX[0x3b]) && (in_ECX[0xc3] == 0)) {
    if (local_6440 <= 1e-07) {
      in_ECX[0x3b] = 2;
      if (in_ECX[0x3b] == 2) {
        fVar5 = (float10)FUN_008f8d10(dVar8 * dVar8 + dVar9 * dVar9);
        *(double *)(in_ECX + 0x2a) = (double)fVar5 / 2.0;
        local_24 = dVar6 / 2.0 + local_24;
        local_1c = dVar7 / 2.0 + local_1c;
      }
    }
    else {
      local_6460 = *(double *)(in_ECX + 0x2a);
      local_6458 = local_6440 * *(double *)(in_ECX + 0x38);
      if ((in_ECX[0x3b] == 4) || (in_ECX[0x3b] == 8)) {
        local_6460 = 0.0;
      }
      if (((in_ECX[0x3b] == 5) || (in_ECX[0x3b] == 6)) || (in_ECX[0x3b] == 7)) {
        local_6460 = -local_6460;
      }
      if (((in_ECX[0x3b] == 1) || (in_ECX[0x3b] == 7)) || (in_ECX[0x3b] == 8)) {
        local_6458 = -local_6458;
      }
      if ((in_ECX[0x3b] == 2) || (in_ECX[0x3b] == 6)) {
        local_6458 = 0.0;
      }
      local_24 = (dVar1 * local_6460 + local_24) - dVar2 * local_6458;
      local_1c = dVar1 * local_6458 + local_1c + dVar2 * local_6460;
    }
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_004552a0();
  FUN_0040da70(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
  FUN_0042f5e0(*(undefined8 *)(in_ECX + 0x2a));
  FUN_0042f640(*(undefined8 *)(in_ECX + 0x2e));
  FUN_0042f620(*(undefined8 *)(in_ECX + 0x30));
  FUN_0042f5a0(*(undefined8 *)(in_ECX + 0x34));
  FUN_0042f600(*(undefined8 *)(in_ECX + 0x38));
  FUN_00430200();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiEnko[3] */
/* 0064a3f0  FUN_0064a3f0  908 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0064a3f0(void)

{
  int iVar1;
  float10 fVar2;
  undefined4 uVar3;
  double dVar4;
  undefined4 uVar5;
  undefined1 local_6410 [20];
  undefined4 local_63fc;
  double local_63f8;
  double local_63f0;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938596;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  local_63fc = FUN_0040c0e0();
  FUN_0044dd90(local_6410,*(undefined4 *)(local_63e8 + 4));
  FUN_0044de00(local_6410,*(undefined4 *)(local_63e8 + 4));
  if (1e-07 < *(double *)(local_63e8 + 0xa8)) {
    if (*(double *)(local_63e8 + 0xd0) <= 0.0) {
      local_63f8 = -*(double *)(local_63e8 + 0xd0);
    }
    else {
      local_63f8 = *(double *)(local_63e8 + 0xd0);
    }
    if (1e-07 < local_63f8) {
      FUN_004552a0(local_63e8 + 0x318);
      FUN_00464040();
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_0047f220(*(undefined4 *)(local_63e8 + 4),local_63e4,local_6410,local_63e8 + 0x318,
                   (int)*(undefined8 *)(local_63e8 + 0xf0),
                   (int)((ulonglong)*(undefined8 *)(local_63e8 + 0xf0) >> 0x20),1);
      *(undefined4 *)(local_63e8 + 0xf8) = 1;
      *(undefined8 *)(local_63e8 + 0x170) = *(undefined8 *)(local_63e8 + 0xd0);
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
      FUN_00647b40(local_63e8 + 0x178);
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x85f0)) {
        FUN_00404c80();
        FUN_004fca20();
        fVar2 = (float10)FUN_004ab530();
        local_63f0 = (double)fVar2;
        if (local_63f0 <= 1e-07) {
          uVar3 = 0;
          uVar5 = 0;
          FUN_00404c80(0,0);
          FUN_004fca20();
          FUN_004ac6e0(uVar3,uVar5);
        }
        else {
          local_63f0 = local_63f0 *
                       *(double *)
                        (*(int *)(local_63e8 + 4) + 0x2578 +
                        *(int *)(*(int *)(local_63e8 + 4) + 0x256c) * 8);
          dVar4 = local_63f0;
          FUN_00404c80(local_63f0);
          FUN_004fca20();
          FUN_004ac6e0(dVar4);
        }
      }
      local_8._0_1_ = 1;
      FUN_004640a0();
      goto LAB_0064a709;
    }
  }
  FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f24),
               *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f28),0,0);
  *(undefined2 *)(local_63e8 + 0x178) = 0;
LAB_0064a709:
  FUN_004efbb0(0x14bd,local_63e8 + 0x178,0);
  *(undefined4 *)(local_63e8 + 0x308) = 0;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



