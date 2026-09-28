/* CZukeiTakakukei -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiTakakukei[1] */
/* 00721a00  FUN_00721a00  68 bytes, 0 callers */

undefined4 FUN_00721a00(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004fa980();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x5008);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiTakakukei[6] */
/* 00721a50  FUN_00721a50  3204 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00721bcb) */

void FUN_00721a50(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  undefined1 local_6918 [20];
  undefined4 local_6904;
  undefined4 local_6900;
  int local_68fc;
  int local_68f8;
  undefined1 local_524 [16];
  undefined1 local_514 [16];
  undefined1 local_504 [16];
  undefined1 local_4f4 [16];
  undefined1 local_4e4 [16];
  undefined1 local_4d4 [16];
  undefined1 local_4c4 [16];
  undefined1 local_4b4 [16];
  undefined1 local_4a4 [16];
  undefined1 local_494 [16];
  undefined1 local_484 [16];
  undefined1 local_474 [40];
  undefined1 local_44c;
  undefined2 local_40c [404];
  undefined1 local_e4 [208];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940676;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_00446aa0(uVar2);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_68f8 + 4));
  local_8._0_1_ = 1;
  uVar3 = FUN_0040c0e0();
  *(undefined4 *)(*(int *)(local_68f8 + 4) + 0x8560) = 0;
  local_6900 = 0;
  local_68fc = 0;
  FUN_00404c80(uVar2,uVar3);
  iVar4 = FUN_004fca20();
  if (*(int *)(iVar4 + 0x1a0) == *(int *)(*(int *)(local_68f8 + 4) + 0x8620)) {
    FUN_00404c80(uVar2,uVar3);
    iVar4 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar4 + 0x1a0) + 0xbc) == 0) {
      FUN_00404c80(uVar2,uVar3);
      FUN_004fca20();
      uVar3 = FUN_005ecb60();
      *(undefined4 *)(local_68f8 + 0xbc) = uVar3;
      FUN_00404c80();
      FUN_004fca20();
      fVar5 = (float10)FUN_005ec9a0();
      *(double *)(local_68f8 + 0xc0) = (double)fVar5;
      *(double *)(local_68f8 + 0xc0) =
           *(double *)(local_68f8 + 0xc0) + *(double *)(*(int *)(local_68f8 + 4) + 0x17c0);
      while (180.0 < *(double *)(local_68f8 + 0xc0)) {
        *(double *)(local_68f8 + 0xc0) = *(double *)(local_68f8 + 0xc0) - 360.0;
      }
      while (*(double *)(local_68f8 + 0xc0) <= 180.0) {
        *(double *)(local_68f8 + 0xc0) = *(double *)(local_68f8 + 0xc0) + 360.0;
      }
      FUN_00404c80();
      iVar4 = FUN_004fca20();
      *(undefined4 *)(local_68f8 + 0xb4) = *(undefined4 *)(*(int *)(iVar4 + 0x1a0) + 0xad0);
      if (*(int *)(local_68f8 + 0xb4) != *(int *)(local_68f8 + 0xb8)) {
        FUN_0044dd90(local_6918,*(undefined4 *)(local_68f8 + 4));
        *(undefined4 *)(local_68f8 + 0xb8) = *(undefined4 *)(local_68f8 + 0xb4);
        *(undefined4 *)(local_68f8 + 0xa8) = 1;
        FUN_00404c80();
        FUN_004fca20();
        FUN_005eac20();
      }
      *(undefined4 *)(local_68f8 + 0xac) = 1;
      if (*(int *)(local_68f8 + 0xb4) == 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar5 = (float10)FUN_005eca50();
        *(double *)(local_68f8 + 0x108) = (double)fVar5;
        FUN_00404c80();
        FUN_004fca20();
        fVar5 = (float10)FUN_005ecad0();
        *(double *)(local_68f8 + 0x110) = (double)fVar5;
      }
      else {
        FUN_00404c80();
        FUN_004fca20();
        fVar5 = (float10)FUN_005ec9d0();
        *(double *)(local_68f8 + 200) = (double)fVar5;
        if (*(double *)(local_68f8 + 200) <= 1e-07 && *(double *)(local_68f8 + 200) != 1e-07) {
          *(undefined4 *)(local_68f8 + 0xac) = 0;
        }
      }
      if (*(int *)(local_68f8 + 0xac) != *(int *)(local_68f8 + 0xb0)) {
        FUN_0044dd90(local_6918,*(undefined4 *)(local_68f8 + 4));
        *(undefined4 *)(local_68f8 + 0xb0) = *(undefined4 *)(local_68f8 + 0xac);
        *(undefined4 *)(local_68f8 + 0xa8) = 1;
        FUN_00404c80();
        FUN_004fca20();
        FUN_005eac20();
      }
      FUN_00404c80();
      iVar4 = FUN_004fca20();
      *(undefined4 *)(local_68f8 + 0xd0) = *(undefined4 *)(*(int *)(iVar4 + 0x1a0) + 0xf8);
      if (*(int *)(local_68f8 + 0xa8) == 4) {
        *(undefined4 *)(local_68f8 + 0xa8) = 1;
      }
      if (*(int *)(local_68f8 + 0xa8) == 1) {
        FUN_004988c0(local_504,*param_1,param_1[1],param_1[2],param_1[3]);
        if (((*(int *)(local_68f8 + 0xb4) == 1) || (*(int *)(local_68f8 + 0xb4) == 2)) ||
           ((*(int *)(local_68f8 + 0xb4) == 3 && (*(int *)(local_68f8 + 0xac) != 0)))) {
          if ((*(int *)(local_68f8 + 0xac) == 0) || (*(int *)(local_68f8 + 0xd0) == 0)) {
            FUN_004efbb0(0x14bd,0,0);
          }
          else {
            FUN_004efbb0(0x14f4,0,0);
          }
          if (*(int *)(local_68f8 + 0xac) != 0) {
            local_6900 = FUN_00728eb0();
          }
        }
        else {
          FUN_004efbb0(0x14c8,0,0);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (*(int *)(local_68f8 + 0xa8) == 2) {
        FUN_004988c0(local_514,*param_1,param_1[1],param_1[2],param_1[3]);
        if (*(int *)(local_68f8 + 0xb4) == 0) {
          FUN_004efbb0(0x14c9,0,0);
        }
        else {
          FUN_004efbb0(0x14f4,0,0);
          local_6900 = FUN_00728eb0();
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        if (*(int *)(local_68f8 + 0xa8) == 3) {
          FUN_004988c0(local_524,*param_1,param_1[1],param_1[2],param_1[3]);
          local_6900 = FUN_007287b0();
          FUN_004efbb0(0x14be,0,0);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      FUN_00404c80(uVar2,uVar3);
      iVar4 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar4 + 0x1a0) + 0x109c) == 0) {
        *(undefined4 *)(local_68f8 + 0x118) = 0;
      }
      else {
        *(undefined4 *)(local_68f8 + 0x118) = 1;
      }
      FUN_00404c80();
      iVar4 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar4 + 0x1a0) + 0xc4) == 0) {
        FUN_0044dd90(local_6918,*(undefined4 *)(local_68f8 + 4));
        FUN_0041f760();
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_004552a0(local_474);
        for (local_68fc = 2; local_68fc <= *(int *)(local_68f8 + 0x13c); local_68fc = local_68fc + 1
            ) {
          puVar1 = (undefined4 *)(local_68f8 + 0x140 + (local_68fc + -1) * 0x10);
          FUN_004988c0(local_484,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
          puVar1 = (undefined4 *)(local_68f8 + 0x140 + local_68fc * 0x10);
          FUN_004988c0(local_494,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
          FUN_00450b70(local_6918,*(undefined4 *)(local_68f8 + 4),local_474);
        }
        if (2 < *(int *)(local_68f8 + 0x13c)) {
          local_44c = 3;
          puVar1 = (undefined4 *)(local_68f8 + 0x140 + *(int *)(local_68f8 + 0x13c) * 0x10);
          FUN_004988c0(local_4a4,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
          FUN_004988c0(local_4b4,*(undefined4 *)(local_68f8 + 0x150),
                       *(undefined4 *)(local_68f8 + 0x154),*(undefined4 *)(local_68f8 + 0x158),
                       *(undefined4 *)(local_68f8 + 0x15c));
          FUN_00450b70(local_6918,*(undefined4 *)(local_68f8 + 4),local_474);
        }
        local_44c = 9;
        if (0 < *(int *)(local_68f8 + 0x13c)) {
          puVar1 = (undefined4 *)(local_68f8 + 0x140 + *(int *)(local_68f8 + 0x13c) * 0x10);
          FUN_004988c0(local_4c4,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
          FUN_004988c0(local_4d4,*param_1,param_1[1],param_1[2],param_1[3]);
          FUN_00450b70(local_6918,*(undefined4 *)(local_68f8 + 4),local_474);
        }
        if (1 < *(int *)(local_68f8 + 0x13c)) {
          FUN_004988c0(local_4e4,*(undefined4 *)(local_68f8 + 0x150),
                       *(undefined4 *)(local_68f8 + 0x154),*(undefined4 *)(local_68f8 + 0x158),
                       *(undefined4 *)(local_68f8 + 0x15c));
          FUN_004988c0(local_4f4,*param_1,param_1[1],param_1[2],param_1[3]);
          FUN_00450b70(local_6918,*(undefined4 *)(local_68f8 + 4),local_474);
        }
        if (*(int *)(local_68f8 + 0x13c) == 0) {
          FUN_00404c80();
          iVar4 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar4 + 0x1a0) + 0x1090) == 0) {
            FUN_004efbb0(0x14c8,0,0);
          }
          else {
            FUN_005cf710(local_e4,L"     ");
            FUN_005977f0(0x15e0);
            uVar3 = FUN_00404920();
            FUN_00661050(local_e4,uVar3);
            FUN_00404770();
            FUN_004efbb0(0x14c8,local_e4,0);
          }
        }
        else if (*(int *)(local_68f8 + 0x13c) == 1) {
          FUN_004efbb0(0x1528,0,0);
        }
        else if (1 < *(int *)(local_68f8 + 0x13c)) {
          FUN_004efbb0(0x14c9,0,0);
        }
        local_8._0_1_ = 1;
        FUN_0041fd70();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        local_6904 = 0;
        local_40c[0] = 0;
        FUN_00404c80();
        iVar4 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar4 + 0x1a0) + 200) != 0) {
          FUN_005977f0(0x14b4);
          uVar3 = FUN_00404920();
          FUN_005b0570(local_40c,uVar3);
          FUN_00404770();
          FUN_005977f0(0x14b4);
          uVar3 = FUN_00404920();
          FUN_00721610(local_40c,uVar3);
          FUN_00404770();
          FUN_005977f0(0x1620);
          uVar3 = FUN_00404920();
          FUN_00721610(local_40c,uVar3);
          FUN_00404770();
        }
        FUN_004efbb0(0x1612,local_40c,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
  }
  else {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTakakukei[16] */
/* 007226e0  FUN_007226e0  883 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007226e0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined1 local_6418 [20];
  undefined4 local_6404;
  undefined4 local_6400;
  undefined4 local_63fc;
  undefined4 local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094004b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  FUN_00446aa0(uVar1);
  local_8._0_1_ = 1;
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 0) {
    FUN_0044dd90(local_6418,*(undefined4 *)(local_63e8 + 4));
    if (*(int *)(local_63e8 + 0xa8) == 2) {
      *(undefined4 *)(local_63e8 + 0xa8) = 1;
      FUN_00404c80();
      FUN_004fca20();
      FUN_005eac20();
      local_63fc = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      local_63ec = local_63fc;
    }
    else if (*(int *)(local_63e8 + 0xa8) == 3) {
      *(undefined4 *)(local_63e8 + 0xa8) = 2;
      FUN_00404c80();
      FUN_004fca20();
      FUN_005eac20();
      local_6400 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      local_63ec = local_6400;
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      FUN_005eac20();
      local_6404 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      local_63ec = local_6404;
    }
  }
  else {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xc4) == 0) {
      if (*(int *)(local_63e8 + 0x13c) < 1) {
        local_63f8 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        local_63ec = local_63f8;
      }
      else {
        *(int *)(local_63e8 + 0x13c) = *(int *)(local_63e8 + 0x13c) + -1;
        uVar3 = *(undefined4 *)(local_63e8 + 0x13c);
        FUN_00404c80(uVar3);
        FUN_004fca20();
        FUN_005ec7f0(uVar3);
        FUN_00404c80();
        FUN_0056d7d0();
        local_63f4 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        local_63ec = local_63f4;
      }
    }
    else if (*(int *)(local_63e8 + 0x11c) < 1) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_005eb250();
      FUN_00404c80();
      FUN_0056d7d0();
      local_63f0 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      local_63ec = local_63f0;
    }
    else {
      *(int *)(local_63e8 + 0x11c) = *(int *)(local_63e8 + 0x11c) + -1;
      local_63ec = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiTakakukei[0] */
/* 00722a60  FUN_00722a60  16 bytes, 0 callers */

undefined ** FUN_00722a60(void)

{
  return &PTR_s_CZukeiTakakukei_0097ae04;
}




/* vtable slots: CZukeiTakakukei[23] */
/* 00722a70  FUN_00722a70  75 bytes, 0 callers */

bool FUN_00722a70(void)

{
  int iVar1;
  int in_ECX;
  bool bVar2;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  bVar2 = *(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8620);
  if (bVar2) {
    FUN_00404c80();
    FUN_004fca20();
    FUN_00723690();
  }
  return bVar2;
}




/* vtable slots: CZukeiTakakukei[46] */
/* 00722ac0  FUN_00722ac0  1678 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00722ac0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  double dVar4;
  undefined4 local_138;
  int local_134;
  undefined4 local_130;
  undefined4 local_12c;
  int *local_128;
  CColorDialog local_124 [272];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009406b0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0c7c0 == 0) {
    local_12c = 0;
    if (*(int *)(in_ECX[1] + 0x9078) == 0) {
      local_138 = 0xffffffff;
      local_130 = 0x17;
      local_128 = in_ECX;
      FUN_00404c80(local_14);
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) == 1) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x1090) == 1) {
          local_130 = 0x2b;
        }
      }
      iVar1 = FUN_00778a40(1,&local_138,*(undefined4 *)(local_128[1] + 0x9070),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,local_130);
      if (iVar1 == 0) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if ((*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) != 0) && (0 < local_128[0x4f])) {
          if (param_2 == 0xc) {
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x1090) == 0) {
              local_134 = 3;
            }
            else {
              local_134 = 2;
            }
            if (local_134 <= local_128[0x4f]) {
              if (param_3 == 1) {
                FUN_005168b0(0x15e7,*(undefined4 *)(local_128[1] + 0x8f50),
                             *(undefined4 *)(local_128[1] + 0x8f54),1,0);
                ExceptionList = local_10;
                return local_12c;
              }
              if (param_3 != 2) {
                ExceptionList = local_10;
                return local_12c;
              }
              (**(code **)(*local_128 + 0x78))();
              ExceptionList = local_10;
              return local_12c;
            }
          }
          if (param_2 == 1) {
            if (param_3 == 1) {
              FUN_005168b0(0x15e8,*(undefined4 *)(local_128[1] + 0x8f50),
                           *(undefined4 *)(local_128[1] + 0x8f54),1,0);
              ExceptionList = local_10;
              return local_12c;
            }
            if (param_3 != 2) {
              ExceptionList = local_10;
              return local_12c;
            }
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x1090) == 0) {
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x1090) = 1;
            }
            else {
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x1090) = 0;
            }
            FUN_00404c80();
            FUN_004fca20();
            FUN_007955d2();
            FUN_00404c80();
            FUN_004fca20();
            FUN_005ec6d0();
            FUN_00404c80();
            FUN_004fca20();
            FUN_007236d0();
            ExceptionList = local_10;
            return local_12c;
          }
          if (param_2 == 2) {
            if (param_3 == 1) {
              FUN_005168b0(0x2733,*(undefined4 *)(local_128[1] + 0x8f50),
                           *(undefined4 *)(local_128[1] + 0x8f54),1,0);
              ExceptionList = local_10;
              return local_12c;
            }
            if (param_3 != 2) {
              ExceptionList = local_10;
              return local_12c;
            }
            FUN_005156d0();
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x1090) == 0) {
              ExceptionList = local_10;
              return local_12c;
            }
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x1094) = 0;
            *(undefined4 *)(local_128[1] + 0x5e18) = 0;
            FUN_00404c80();
            FUN_004fca20();
            FUN_007955d2();
            FUN_00404c80();
            FUN_004fca20();
            FUN_005ec6d0();
            ExceptionList = local_10;
            return local_12c;
          }
          if (param_2 == 3) {
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x1090) == 1) {
              if (param_3 == 1) {
                FUN_005168b0(0x15e6,*(undefined4 *)(local_128[1] + 0x8f50),
                             *(undefined4 *)(local_128[1] + 0x8f54),1,0);
                ExceptionList = local_10;
                return local_12c;
              }
              if (param_3 != 2) {
                ExceptionList = local_10;
                return local_12c;
              }
              FUN_00446f20();
              local_8 = 0;
              iVar1 = CColorDialog::DoModal(local_124);
              if (iVar1 == 1) {
                uVar2 = FUN_0041b590();
                *(undefined4 *)(local_128[1] + 0x5e1c) = uVar2;
              }
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x1094) = 1;
              *(undefined4 *)(local_128[1] + 0x5e18) = 10;
              FUN_00404c80();
              FUN_004fca20();
              FUN_007979e8();
              FUN_00404c80();
              FUN_004fca20();
              FUN_007955d2();
              FUN_00404c80();
              FUN_004fca20();
              FUN_005ec6d0();
              local_8 = 0xffffffff;
              FUN_004472f0();
              ExceptionList = local_10;
              return local_12c;
            }
          }
        }
        local_12c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      else {
        local_12c = 0;
      }
    }
    else if (param_2 == 0xc) {
      if (param_3 == 1) {
        FUN_005168b0(0x1810,*(undefined4 *)(in_ECX[1] + 0x8f50),*(undefined4 *)(in_ECX[1] + 0x8f54),
                     1,0);
      }
      else if (param_3 == 2) {
        FUN_00404c80(local_14);
        FUN_004fca20();
        fVar3 = (float10)FUN_005ec9a0();
        dVar4 = -(double)fVar3;
        FUN_00404c80(dVar4);
        FUN_004fca20();
        FUN_005ec7a0(dVar4);
      }
    }
    else {
      local_12c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_12c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return local_12c;
}




/* vtable slots: CZukeiTakakukei[47] */
/* 00723150  FUN_00723150  298 bytes, 0 callers */

undefined4
FUN_00723150(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
      local_10 = 0xffffffff;
      local_c = 0x17;
      local_8 = in_ECX;
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) == 1) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x1090) == 1) {
          local_c = 0x2b;
        }
      }
      iVar2 = FUN_00778a40(2,&local_10,*(undefined4 *)(*(int *)(local_8 + 4) + 0x9074),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,local_c);
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




/* vtable slots: CZukeiTakakukei[26] */
/* 00723280  FUN_00723280  36 bytes, 0 callers */

void FUN_00723280(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiTakakukei[30] */
/* 007232b0  FUN_007232b0  463 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007232b0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
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
  FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
  local_63ec = 0;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xc0) != 0) {
    local_63ec = 1;
  }
  if (DAT_00a0cc74 != 0) {
    local_63ec = 1;
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) != 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x1090) != 0) {
      local_63ec = 1;
    }
  }
  FUN_007255f0(local_63ec,local_63e4,local_6400,*(undefined4 *)(local_63e8 + 0x13c),
               local_63e8 + 0x140);
  *(undefined4 *)(local_63e8 + 0x13c) = 0;
  DAT_00a0cc74 = 0;
  uVar2 = *(undefined4 *)(local_63e8 + 0x13c);
  FUN_00404c80(uVar2);
  FUN_004fca20();
  FUN_005ec7f0(uVar2);
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8578) = 1;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTakakukei[31] */
/* 00723480  FUN_00723480  198 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00723480(void)

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
  FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0x13c) = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTakakukei[32] */
/* 00723550  FUN_00723550  198 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00723550(void)

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
  FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0xa8) = 1;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTakakukei[36] */
/* 00723620  FUN_00723620  110 bytes, 0 callers */

void FUN_00723620(void)

{
  int iVar1;
  int *in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) != 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x1090) == 0) {
      if (in_ECX[0x4f] < 3) {
        return;
      }
    }
    else if (in_ECX[0x4f] < 2) {
      return;
    }
    (**(code **)(*in_ECX + 0x78))();
  }
  return;
}




/* vtable slots: CZukeiTakakukei[49] */
/* 007236f0  FUN_007236f0  63 bytes, 0 callers */

void FUN_007236f0(undefined8 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_005ec7a0(param_1);
  }
  return;
}




/* vtable slots: CZukeiTakakukei[50] */
/* 00723730  FUN_00723730  177 bytes, 0 callers */

void FUN_00723730(double param_1)

{
  int iVar1;
  int in_ECX;
  double dVar2;
  
  if (1e-07 <= param_1) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 200) == 0) {
      if (*(int *)(in_ECX + 0xb4) == 0) {
        dVar2 = param_1;
        FUN_00404c80(param_1,param_1);
        FUN_004fca20();
        FUN_005ec920(param_1,dVar2);
      }
      else {
        FUN_00404c80(param_1);
        FUN_004fca20();
        FUN_005ec8b0(param_1);
      }
    }
    else {
      *(double *)(in_ECX + 0x120) = param_1;
    }
  }
  return;
}




/* vtable slots: CZukeiTakakukei[51] */
/* 007237f0  FUN_007237f0  491 bytes, 0 callers */

void FUN_007237f0(undefined8 param_1,double param_2)

{
  undefined8 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_34;
  undefined8 local_30;
  undefined8 local_28;
  uint uStack_20;
  undefined1 *local_1c;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009406f5;
  local_10 = ExceptionList;
  uStack_20 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = in_ECX;
  if (*(int *)(in_ECX + 0xb4) != 0) {
    local_28 = (double)param_1;
    local_30 = (double)CONCAT44(0x72383d,(undefined4)local_30);
    FUN_00404c80();
    local_30 = (double)CONCAT44(0x723844,(undefined4)local_30);
    FUN_004fca20();
    local_30 = (double)CONCAT44(0x72384f,(undefined4)local_30);
    FUN_005ec7a0();
  }
  if (1e-07 < param_2) {
    local_28 = (double)CONCAT44(0x723867,(undefined4)local_28);
    FUN_00404c80();
    local_28 = (double)CONCAT44(0x72386e,(undefined4)local_28);
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 200) != 0) {
      *(double *)(local_14 + 0x120) = param_2;
      if (DAT_00a0d62c != 0) {
        param_2 = param_2 / DAT_00a0d630;
      }
      local_28 = (double)CONCAT44(0x7238b4,(undefined4)local_28);
      CStringT<>();
      local_8._0_1_ = 1;
      local_28 = param_2;
      local_30 = (double)CONCAT44(L"%lg m",local_18);
      uStack_34 = 0x7238d3;
      FUN_004059f0();
      local_28 = 0.0;
      puVar1 = (undefined8 *)(*(int *)(local_14 + 4) + 0x8f24);
      uStack_34 = *(undefined4 *)puVar1;
      local_30 = (double)*puVar1;
      local_1c = (undefined1 *)&uStack_34;
      FUN_00403dd0(local_18);
      FUN_00516ac0();
      local_8 = (uint)local_8._1_3_ << 8;
      local_28 = (double)CONCAT44(0x723914,(undefined4)local_28);
      FUN_00404540();
      local_8 = 0xffffffff;
      local_28 = (double)CONCAT44(0x723923,(undefined4)local_28);
      FUN_00404540();
      ExceptionList = local_10;
      return;
    }
    if (*(int *)(local_14 + 0xb4) == 0) {
      local_28 = param_2;
      local_30 = param_2;
      uStack_34 = 0x723953;
      FUN_00404c80();
      uStack_34 = 0x72395a;
      FUN_004fca20();
      uStack_34 = 0x723965;
      FUN_005ec920();
    }
    else {
      local_28 = param_2;
      local_30 = (double)CONCAT44(0x723979,(undefined4)local_30);
      FUN_00404c80();
      local_30 = (double)CONCAT44(0x723980,(undefined4)local_30);
      FUN_004fca20();
      local_30 = (double)CONCAT44(0x72398b,(undefined4)local_30);
      FUN_005ec8b0();
    }
  }
  local_28._4_4_ = 0;
  local_28._0_4_ = 0x723992;
  FUN_00404c80();
  local_28._0_4_ = 0x723999;
  FUN_004fca20();
  local_28._0_4_ = 0x7239a4;
  FUN_007955d2();
  local_28._0_4_ = 0x7239a9;
  FUN_00404c80();
  local_28._0_4_ = 0x7239b0;
  FUN_004fca20();
  local_28._0_4_ = 0x7239bb;
  FUN_005ec6d0();
  local_8 = 0xffffffff;
  local_28 = (double)CONCAT44(local_28._4_4_,0x7239ca);
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTakakukei[15] */
/* 007239e0  FUN_007239e0  198 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007239e0(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920cbb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  FUN_00446aa0(uVar1);
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
  local_63ec = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiTakakukei[9] */
/* 00723ab0  FUN_00723ab0  2354 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_00723ab0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_6448 [20];
  undefined4 local_6434;
  int local_6430;
  int local_642c;
  int local_6428;
  undefined1 local_6424 [25384];
  undefined4 local_fc;
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094073b;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  local_6428 = in_ECX;
  local_14 = uVar2;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  FUN_00446aa0(uVar2);
  local_8._0_1_ = 1;
  local_6430 = 0;
  local_642c = 0;
  *(int *)(local_6428 + 0x5000) = DAT_00a0cc6c;
  *(int *)(local_6428 + 0x5004) = DAT_00a0cc74;
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) == 0) {
    FUN_0044dd90(local_6448,*(undefined4 *)(local_6428 + 4));
    if (*(int *)(local_6428 + 0xa8) == 1) {
      FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
      if ((*(int *)(local_6428 + 0xb4) == 0) || (*(int *)(local_6428 + 0xac) == 0)) {
        *(undefined4 *)(local_6428 + 0xa8) = 2;
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return 0;
      }
      *(undefined4 *)(local_6428 + 0xa8) = 4;
      local_6430 = FUN_00728eb0();
      *(undefined4 *)(local_6428 + 0xa8) = 1;
    }
    if (*(int *)(local_6428 + 0xa8) == 2) {
      FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
      iVar3 = FUN_00436970(*(undefined4 *)(local_6428 + 0xd8),*(undefined4 *)(local_6428 + 0xdc),
                           *(undefined4 *)(local_6428 + 0xe0),*(undefined4 *)(local_6428 + 0xe4),
                           *(undefined4 *)(local_6428 + 0xe8),*(undefined4 *)(local_6428 + 0xec),
                           *(undefined4 *)(local_6428 + 0xf0),*(undefined4 *)(local_6428 + 0xf4));
      if (iVar3 != 0) {
        FUN_005168b0(0x14df,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return 0;
      }
      if (*(int *)(local_6428 + 0xb4) == 0) {
        *(undefined4 *)(local_6428 + 0xa8) = 3;
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return 0;
      }
      *(undefined4 *)(local_6428 + 0xa8) = 4;
      local_6430 = FUN_00728eb0();
      *(undefined4 *)(local_6428 + 0xa8) = 1;
    }
    if (*(int *)(local_6428 + 0xa8) == 3) {
      FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6428 + 0xa8) = 4;
      local_6430 = FUN_007287b0();
      *(undefined4 *)(local_6428 + 0xa8) = 1;
    }
    bVar1 = 0 < local_6430;
    if (bVar1) {
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    ExceptionList = local_10;
    return (uint)bVar1;
  }
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xc4) == 0) {
    if (((DAT_00a0cc6c != 0) || (DAT_00a0cc74 != 0)) && (*(int *)(local_6428 + 0x13c) == 0)) {
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0x1090) != 0) {
        FUN_00729dd0(1,param_2,param_3,param_4,param_5);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return 0;
      }
    }
    for (local_642c = 1; local_642c <= *(int *)(local_6428 + 0x13c); local_642c = local_642c + 1) {
      iVar3 = FUN_00498960(param_2,param_3,param_4,param_5);
      if (iVar3 != 0) {
        uVar6 = 0;
        uVar5 = 0;
        puVar4 = (undefined4 *)FUN_0041c8d0(9999,9999);
        FUN_005168b0(0x14df,*puVar4,puVar4[1],uVar5,uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return 0;
      }
    }
    if (1000 < *(int *)(local_6428 + 0x13c)) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      ExceptionList = local_10;
      return 0;
    }
    if (*(int *)(local_6428 + 0x13c) < 0) {
      *(undefined4 *)(local_6428 + 0x13c) = 0;
    }
    *(int *)(local_6428 + 0x13c) = *(int *)(local_6428 + 0x13c) + 1;
    FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
    *(undefined4 *)(local_6428 + 0x4040 + *(int *)(local_6428 + 0x13c) * 4) = 0;
    uVar5 = *(undefined4 *)(local_6428 + 0x13c);
    FUN_00404c80(uVar5);
    FUN_004fca20();
    FUN_005ec7f0(uVar5);
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    ExceptionList = local_10;
    return 0;
  }
  local_fc = 1;
  iVar3 = FUN_0044a270(3,*(undefined4 *)(local_6428 + 4),&param_2,&local_6434,0);
  if (iVar3 == 0) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    ExceptionList = local_10;
    return 0;
  }
  iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
  if (iVar3 != 0) {
    *(undefined4 *)(local_6428 + 0x128) = 0;
    uVar2 = FUN_007249c0(local_6448,local_6424,local_6434,0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    ExceptionList = local_10;
    return uVar2;
  }
  iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
  if (iVar3 != 0) {
    *(undefined4 *)(local_6428 + 0x5004) = 0;
    *(undefined4 *)(local_6428 + 0x5000) = 0;
    uVar2 = FUN_007258d0(param_2,param_3,param_4,param_5,0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    ExceptionList = local_10;
    return uVar2;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukeiTakakukei[11] */
/* 007243f0  FUN_007243f0  1106 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007243f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined1 local_6438 [20];
  undefined4 local_6424;
  undefined4 local_6420;
  undefined4 local_641c;
  undefined4 local_6418;
  undefined4 local_6414;
  undefined4 local_6410;
  undefined4 local_640c;
  undefined4 local_6408;
  undefined4 local_6404;
  undefined4 local_6400;
  undefined4 local_63fc;
  int local_63f8;
  undefined1 local_63f4 [25384];
  undefined4 local_cc;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094078b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
  local_8._0_1_ = 1;
  local_6400 = FUN_0040c0e0();
  *(int *)(local_63f8 + 0x5000) = DAT_00a0cc6c;
  *(int *)(local_63f8 + 0x5004) = DAT_00a0cc74;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) != 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xc4) != 0) {
      local_cc = 1;
      iVar1 = FUN_0044a270(3,*(undefined4 *)(local_63f8 + 4),&param_2,&local_63fc,0);
      if (iVar1 == 0) {
        local_6408 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_6408;
      }
      iVar1 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
      if (iVar1 != 0) {
        *(undefined4 *)(local_63f8 + 0x128) = 0;
        FUN_00574d00();
        local_640c = FUN_007249c0(local_6438,local_63f4,local_63fc,1);
        FUN_007254e0(local_6400,DAT_00a0cac0);
        local_6410 = local_640c;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_6410;
      }
      iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar1 != 0) {
        *(undefined4 *)(local_63f8 + 0x5004) = 0;
        *(undefined4 *)(local_63f8 + 0x5000) = 0;
        local_6414 = FUN_007258d0(param_2,param_3,param_4,param_5,1);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_6414;
      }
      local_6418 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_6418;
    }
    if (((DAT_00a0cc6c != 0) || (DAT_00a0cc74 != 0)) && (*(int *)(local_63f8 + 0x13c) == 0)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x1090) != 0) {
        local_6404 = 0;
        local_6404 = FUN_00729dd0(0,param_2,param_3,param_4,param_5);
        local_641c = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_641c;
      }
    }
  }
  *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8560) = 0;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  iVar1 = FUN_00451eb0(*(undefined4 *)(local_63f8 + 4),&local_24,1);
  if (iVar1 == 1) {
    local_6420 = FUN_00723ab0(param_1,local_24,local_20,local_1c,local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_6424 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_6420 = local_6424;
  }
  ExceptionList = local_10;
  return local_6420;
}




/* vtable slots: CZukeiTakakukei[4] */
/* 00724850  FUN_00724850  125 bytes, 0 callers */

void FUN_00724850(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x134) != 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8620)) {
      if (*(int *)(in_ECX + 0x138) == 1) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x1090) = 0;
      }
      else {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x1090) = 1;
      }
    }
  }
  return;
}




/* vtable slots: CZukeiTakakukei[3] */
/* 007248d0  FUN_007248d0  225 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007248d0(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920cbb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  local_63ec = FUN_0040c0e0(uVar1);
  FUN_00446aa0();
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
  FUN_00404c80();
  FUN_004fca20();
  FUN_005eac20();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



