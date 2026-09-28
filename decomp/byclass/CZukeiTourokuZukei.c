/* CZukeiTourokuZukei -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiTourokuZukei[1] */
/* 00757420  FUN_00757420  68 bytes, 0 callers */

undefined4 FUN_00757420(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004fa9a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x278);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiTourokuZukei[6] */
/* 00757470  FUN_00757470  1680 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00757470(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  undefined1 local_6464 [20];
  double local_6450;
  double local_6448;
  undefined4 local_6440;
  undefined4 local_643c;
  int local_6438;
  double local_6434;
  double local_642c;
  int local_6424;
  undefined4 local_6420;
  int *local_641c;
  int local_6418;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941ffb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x17ec) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x17e8) = 0;
  local_642c = 1.0;
  local_6434 = 1.0;
  *(undefined8 *)(in_ECX + 0x250) = 0;
  *(undefined8 *)(in_ECX + 0x208) = 0;
  *(undefined8 *)(in_ECX + 0x200) = 0;
  local_6418 = in_ECX;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) != 0) {
    FUN_00404c80(uVar1);
    FUN_004fca20();
    fVar4 = (float10)FUN_005f55f0();
    local_642c = (double)fVar4;
    FUN_00404c80();
    FUN_004fca20();
    fVar4 = (float10)FUN_005f5630();
    local_6434 = (double)fVar4;
    FUN_00404c80();
    FUN_004fca20();
    fVar4 = (float10)FUN_005f5710();
    *(double *)(local_6418 + 0x250) = (double)fVar4;
    if (*(int *)(local_6418 + 0x26c) == 3) {
      FUN_00404c80();
      FUN_004fca20();
      fVar4 = (float10)FUN_005f5680();
      *(double *)(local_6418 + 0x200) = (double)fVar4;
      FUN_00404c80();
      FUN_004fca20();
      fVar4 = (float10)FUN_005f56c0();
      *(double *)(local_6418 + 0x208) = (double)fVar4;
      if (DAT_00a0d638 != 0) {
        *(double *)(local_6418 + 0x200) = *(double *)(local_6418 + 0x200) * 1000.0;
        *(double *)(local_6418 + 0x208) = *(double *)(local_6418 + 0x208) * 1000.0;
      }
    }
  }
  if (local_642c <= 0.0) {
    local_6448 = -local_642c;
  }
  else {
    local_6448 = local_642c;
  }
  if (local_6448 < 1e-07) {
    local_642c = 1.0;
  }
  if (local_6434 <= 0.0) {
    local_6450 = -local_6434;
  }
  else {
    local_6450 = local_6434;
  }
  if (local_6450 < 1e-07) {
    local_6434 = 1.0;
  }
  *(double *)(local_6418 + 0x240) = local_642c;
  *(double *)(local_6418 + 0x248) = local_6434;
  *(double *)(local_6418 + 0x250) =
       (*(double *)(*(int *)(local_6418 + 4) + 0x17c0) / 180.0) * 3.141592653589793 +
       *(double *)(local_6418 + 0x250);
  local_6420 = FUN_0040c0e0();
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6418 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6464,*(undefined4 *)(local_6418 + 4));
  iVar2 = FUN_00572c70();
  if (iVar2 == 0) {
    *(undefined4 *)(local_6418 + 0x1f8) = 1;
    FUN_004efbb0(0x14ea,0,0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (*(int *)(local_6418 + 0x1f8) != 0) {
      *(undefined4 *)(local_6418 + 0x1f8) = 0;
      DAT_00a0b3b8 = 0;
    }
    if ((*(int *)(local_6418 + 0x228) == 0) || (*(int *)(local_6418 + 0x220) != 1)) {
      FUN_004efbb0(0x14e9,0,0);
    }
    else {
      FUN_004efbb0(0x2786,0,0);
    }
    if (DAT_00a0b3b8 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      if (*(int *)(local_6418 + 0x228) == 0) {
        FUN_004988c0(local_24,*param_1,param_1[1],param_1[2],param_1[3]);
      }
      else if (*(int *)(local_6418 + 0x220) == 0) {
        FUN_004988c0(local_34,*param_1,param_1[1],param_1[2],param_1[3]);
        *(undefined8 *)(local_6418 + 0x250) = 0;
      }
      else {
        FUN_004988c0(local_44,*param_1,param_1[1],param_1[2],param_1[3]);
        FUN_00757c70();
      }
      local_6440 = *(undefined4 *)(*(int *)(local_6418 + 4) + 0x8f40);
      local_643c = *(undefined4 *)(*(int *)(local_6418 + 4) + 0x8f44);
      local_641c = (int *)0x0;
      local_6424 = 1;
      local_6438 = FUN_00572c70();
      while (((local_6438 != 0 &&
              (local_641c = (int *)FUN_00572cd0(&local_6438,0), local_641c != (int *)0x0)) &&
             (iVar2 = FUN_004fcab0(local_6440,local_643c), iVar2 == 0))) {
        if ((*(int *)(local_6418 + 0x274) == 0) || (local_6424 = 1 - local_6424, local_6424 == 0)) {
          uVar3 = (**(code **)(*local_641c + 0x14))();
          *(undefined4 *)(local_6418 + 600) = uVar3;
          *(short *)(*(int *)(local_6418 + 600) + 0x44) = (short)local_641c[0x11];
          FUN_00758fb0();
          FUN_00447cf0(local_6464,*(undefined4 *)(local_6418 + 4),*(undefined4 *)(local_6418 + 600),
                       1);
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTourokuZukei[16] */
/* 00757b00  FUN_00757b00  353 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00757b00(void)

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
  if (*(int *)(in_ECX + 0x228) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
    FUN_00458a80(local_6400,*(undefined4 *)(local_63e8 + 4),0);
    FUN_00404c80();
    FUN_0056d7d0();
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (*(int *)(in_ECX + 0x220) == 1) {
      *(undefined4 *)(in_ECX + 0x220) = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 0x228) = 0;
      *(undefined4 *)(in_ECX + 0x22c) = 1;
    }
    FUN_00757e40();
    FUN_00404c80();
    FUN_0056d7d0();
    local_63ec = 1;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiTourokuZukei[0] */
/* 00757e30  FUN_00757e30  16 bytes, 0 callers */

undefined ** FUN_00757e30(void)

{
  return &PTR_s_CZukeiTourokuZukei_0097b640;
}




/* vtable slots: CZukeiTourokuZukei[23] */
/* 00758190  FUN_00758190  109 bytes, 0 callers */

undefined4 FUN_00758190(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x864c)) {
    if (DAT_00a0cc6c == 0) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_005f5300();
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      FUN_005f51b0();
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiTourokuZukei[46] */
/* 00758200  FUN_00758200  1517 bytes, 0 callers */

undefined4
FUN_00758200(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  int *in_ECX;
  float10 fVar1;
  double dVar2;
  undefined4 local_10;
  
  if (DAT_00a0c7c0 == 0) {
    local_10 = 0;
    if (*(int *)(in_ECX[1] + 0x9078) == 0) {
      local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      switch(param_2) {
      case 1:
        if (in_ECX[0x9b] == 0) {
          if (param_3 == 1) {
            FUN_005168b0(0x14eb,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_0075a9a0();
          }
        }
        else {
          local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        }
        break;
      case 2:
        if (param_3 == 1) {
          FUN_005168b0(0x18a1,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x70))();
        }
        break;
      case 3:
        if (param_3 == 1) {
          FUN_005168b0(0x1806,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_005f50c0();
        }
        break;
      case 4:
        if (param_3 == 1) {
          FUN_005168b0(0x1807,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_005f4fd0();
        }
        break;
      case 5:
        if (param_3 == 1) {
          FUN_005168b0(0x15fe,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x74))();
        }
        break;
      default:
        local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        break;
      case 7:
        if (param_3 == 1) {
          FUN_005168b0(0x17fc,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          in_ECX[0x97] = 1;
          (&DAT_00a0c074)[in_ECX[0x9b]] = 1;
          FUN_00757e40();
        }
        break;
      case 8:
        if (param_3 == 1) {
          FUN_005168b0(0x17fb,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          in_ECX[0x98] = 1;
          (&DAT_00a0c08c)[in_ECX[0x9b]] = 1;
          FUN_00757e40();
        }
        break;
      case 9:
        if (param_3 == 1) {
          FUN_005168b0(0x17fa,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          in_ECX[0x97] = 0;
          (&DAT_00a0c074)[in_ECX[0x9b]] = 0;
          in_ECX[0x98] = 0;
          (&DAT_00a0c08c)[in_ECX[0x9b]] = 0;
          in_ECX[0x99] = 1;
          (&DAT_00a0c0a4)[in_ECX[0x9b]] = 1;
          in_ECX[0x9a] = 1;
          (&DAT_00a0c0bc)[in_ECX[0x9b]] = 1;
          FUN_00757e40();
        }
        break;
      case 10:
        if (param_3 == 1) {
          FUN_005168b0(0x17fe,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          in_ECX[0x99] = 0;
          (&DAT_00a0c0a4)[in_ECX[0x9b]] = 0;
          in_ECX[0x9a] = 1;
          (&DAT_00a0c0bc)[in_ECX[0x9b]] = 1;
          FUN_00757e40();
        }
        break;
      case 0xb:
        if (param_3 == 1) {
          FUN_005168b0(0x17fd,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          in_ECX[0x9a] = 0;
          (&DAT_00a0c0bc)[in_ECX[0x9b]] = 0;
          in_ECX[0x99] = in_ECX[0x9a];
          (&DAT_00a0c0a4)[in_ECX[0x9b]] = in_ECX[0x99];
          FUN_00757e40();
        }
        break;
      case 0xc:
        if (param_3 == 1) {
          FUN_005168b0(0x1810,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00404c80();
          FUN_004fca20();
          fVar1 = (float10)FUN_005f5710();
          dVar2 = (-(double)fVar1 * 180.0) / 3.141592653589793;
          FUN_00404c80(dVar2);
          FUN_004fca20();
          FUN_005f55b0(dVar2);
        }
      }
    }
  }
  else {
    local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_10;
}




/* vtable slots: CZukeiTourokuZukei[26] */
/* 00758820  FUN_00758820  32 bytes, 0 callers */

void FUN_00758820(void)

{
  int in_ECX;
  
  FUN_0075a9a0();
  *(undefined4 *)(in_ECX + 0x1f8) = 1;
  return;
}




/* vtable slots: CZukeiTourokuZukei[28] */
/* 00758840  FUN_00758840  761 bytes, 0 callers */

void FUN_00758840(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  uint local_24;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009420c0;
  local_10 = ExceptionList;
  uVar8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0x26c) < 0) || (4 < *(int *)(in_ECX + 0x26c))) {
    *(undefined4 *)(in_ECX + 0x26c) = 0;
  }
  *(undefined4 *)(in_ECX + 0x25c) = (&DAT_00a0c074)[*(int *)(in_ECX + 0x26c)];
  *(undefined4 *)(in_ECX + 0x260) = (&DAT_00a0c08c)[*(int *)(in_ECX + 0x26c)];
  *(undefined4 *)(in_ECX + 0x264) = (&DAT_00a0c0a4)[*(int *)(in_ECX + 0x26c)];
  *(undefined4 *)(in_ECX + 0x268) = (&DAT_00a0c0bc)[*(int *)(in_ECX + 0x26c)];
  FUN_004ae5e0(0);
  local_8 = 0;
  iVar1 = *(int *)(in_ECX + 0x268);
  iVar2 = *(int *)(in_ECX + 0x264);
  iVar3 = *(int *)(in_ECX + 0x268);
  uVar4 = *(undefined4 *)(in_ECX + 0x25c);
  uVar5 = *(undefined4 *)(in_ECX + 0x260);
  if (*(int *)(in_ECX + 0x26c) == 3) {
    *(undefined4 *)(&DAT_00a0c05c + *(int *)(in_ECX + 0x26c) * 4) = 0;
  }
  uVar7 = DAT_00a0cb5c;
  uVar6 = *(undefined4 *)(&DAT_00a0c05c + *(int *)(in_ECX + 0x26c) * 4);
  iVar9 = FUN_0079850d(uVar8);
  if (iVar9 == 1) {
    *(undefined4 *)(&DAT_00a0c05c + *(int *)(in_ECX + 0x26c) * 4) = uVar6;
    local_20 = (uint)(iVar1 != 0);
    DAT_00a0cb5c = uVar7;
    *(uint *)(in_ECX + 0x268) = local_20;
    local_24 = (uint)(iVar3 == 0 || iVar2 != 0);
    *(uint *)(in_ECX + 0x264) = local_24;
    if (*(int *)(in_ECX + 0x268) == 0) {
      *(undefined4 *)(in_ECX + 0x264) = 0;
    }
    *(undefined4 *)(in_ECX + 0x25c) = uVar4;
    *(undefined4 *)(in_ECX + 0x260) = uVar5;
    (&DAT_00a0c074)[*(int *)(in_ECX + 0x26c)] = *(undefined4 *)(in_ECX + 0x25c);
    (&DAT_00a0c08c)[*(int *)(in_ECX + 0x26c)] = *(undefined4 *)(in_ECX + 0x260);
    (&DAT_00a0c0a4)[*(int *)(in_ECX + 0x26c)] = *(undefined4 *)(in_ECX + 0x264);
    (&DAT_00a0c0bc)[*(int *)(in_ECX + 0x26c)] = *(undefined4 *)(in_ECX + 0x268);
  }
  FUN_00757e40();
  local_8 = 0xffffffff;
  FUN_004ae780();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTourokuZukei[29] */
/* 00758b40  FUN_00758b40  103 bytes, 0 callers */

void FUN_00758b40(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x228) = *(int *)(in_ECX + 0x228) + 1;
  if (2 < *(int *)(in_ECX + 0x228)) {
    *(undefined4 *)(in_ECX + 0x228) = 0;
    *(undefined4 *)(in_ECX + 0x220) = 0;
    *(undefined4 *)(in_ECX + 0x22c) = 1;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  FUN_00757e40();
  return;
}




/* vtable slots: CZukeiTourokuZukei[49] */
/* 00758bb0  FUN_00758bb0  49 bytes, 0 callers */

void FUN_00758bb0(undefined8 param_1)

{
  FUN_00404c80(param_1);
  FUN_004fca20();
  FUN_005f55b0(param_1);
  return;
}




/* vtable slots: CZukeiTourokuZukei[51] */
/* 00758bf0  FUN_00758bf0  151 bytes, 0 callers */

void FUN_00758bf0(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(in_ECX + 0x264) = 1;
  (&DAT_00a0c0a4)[*(int *)(in_ECX + 0x26c)] = 1;
  *(undefined4 *)(in_ECX + 0x268) = 1;
  (&DAT_00a0c0bc)[*(int *)(in_ECX + 0x26c)] = 1;
  FUN_00757e40(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTourokuZukei[15] */
/* 00758c90  FUN_00758c90  240 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00758c90(void)

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
  FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
  FUN_00453bd0(local_6400,*(undefined4 *)(local_63e8 + 4),0);
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




/* vtable slots: CZukeiTourokuZukei[10] */
/* 00758d80  FUN_00758d80  29 bytes, 0 callers */

void FUN_00758d80(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85a8) = 0;
  return;
}




/* vtable slots: CZukeiTourokuZukei[9] */
/* 00758da0  FUN_00758da0  242 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00758da0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x228) == 0) {
    FUN_004988c0(local_38,param_2,param_3,param_4,param_5);
    uVar1 = 1;
  }
  else if (*(int *)(in_ECX + 0x220) == 0) {
    FUN_004988c0(local_18,param_2,param_3,param_4,param_5);
    *(undefined4 *)(in_ECX + 0x220) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 0;
  }
  else {
    FUN_004988c0(local_28,param_2,param_3,param_4,param_5);
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CZukeiTourokuZukei[11] */
/* 00758ea0  FUN_00758ea0  263 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00758ea0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
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
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  iVar1 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
  if (iVar1 == 1) {
    uVar2 = FUN_00758da0(param_1,local_24,local_20,local_1c,local_18);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 0;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiTourokuZukei[8] */
/* 00758fb0  FUN_00758fb0  3178 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00758fb0(void)

{
  double dVar1;
  int iVar2;
  int iStack_6510;
  undefined8 uStack_650c;
  undefined1 auStack_6504 [8];
  undefined **ppuStack_64fc;
  undefined **ppuStack_64f8;
  uint uStack_64f4;
  double local_64f0;
  undefined1 *local_64e8;
  double local_64e4;
  double local_64dc;
  double local_64d4;
  double local_64cc;
  double local_64c4;
  double local_64bc;
  double local_64b4;
  double local_64ac;
  double local_64a4;
  double local_649c;
  double local_6494;
  undefined4 local_6480;
  int local_647c;
  int local_6470;
  undefined4 local_646c;
  double local_6468;
  double local_6460;
  undefined4 local_6458;
  double local_6454;
  undefined1 local_644c [4];
  int local_6448;
  int local_6444;
  double local_6440;
  double local_6438;
  double local_6430;
  int local_6428;
  int local_6424;
  double local_6420;
  int local_6418;
  undefined1 local_44 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942106;
  local_10 = ExceptionList;
  uStack_64f4 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ppuStack_64f8 = (undefined **)0x758ff0;
  local_14 = uStack_64f4;
  FUN_00446aa0();
  local_8 = 0;
  ppuStack_64f8 = (undefined **)0x759002;
  FUN_00464040();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_646c = DAT_00a0cb58;
  DAT_00a0cb58 = *(int *)(&DAT_00a0c05c + *(int *)(local_6418 + 0x26c) * 4);
  local_6470 = DAT_00a0cb5c;
  ppuStack_64f8 = (undefined **)0x759054;
  local_6424 = (**(code **)(**(int **)(local_6418 + 600) + 0x28))();
  if ((local_6424 < 0) || (0xf < local_6424)) {
    local_6424 = 0;
  }
  if ((*(int *)(local_6418 + 0x26c) == 0) && (*(int *)(*(int *)(local_6418 + 4) + 0x2678) == 0)) {
    DAT_00a0cb58 = 0;
  }
  if (((DAT_00a0cb58 == 1) && (-1 < *(int *)(local_6418 + 0x26c))) &&
     (*(int *)(local_6418 + 0x26c) < 3)) {
    local_6420 = *(double *)(*(int *)(local_6418 + 4) + 0x25f8 + local_6424 * 8);
    if (*(int *)(local_6418 + 0x26c) == 1) {
      local_6420 = *(double *)(*(int *)(local_6418 + 4) + 0x2578 + local_6424 * 8);
    }
    ppuStack_64f8 = &PTR_s_CDataMoji_009fe108;
    ppuStack_64fc = (undefined **)0x759139;
    iVar2 = FUN_0079d98a();
    if (iVar2 != 0) {
      if (*(int *)(local_6418 + 0x268) == 0) {
        dVar1 = *(double *)(*(int *)(local_6418 + 4) + 0x2578 + local_6424 * 8);
      }
      else {
        dVar1 = *(double *)
                 (*(int *)(local_6418 + 4) + 0x2578 +
                 *(int *)(*(int *)(local_6418 + 4) + 0x256c) * 8);
      }
      local_6420 = local_6420 / dVar1;
      if (local_6420 - 1.0 <= 0.0) {
        local_64e4 = -(local_6420 - 1.0);
      }
      else {
        local_64e4 = local_6420 - 1.0;
      }
      if (1e-07 < local_64e4) {
        if (local_6420 <= 0.0) {
          local_6494 = -local_6420;
        }
        else {
          local_6494 = local_6420;
        }
        if (1e-07 < local_6494) {
          ppuStack_64fc = (undefined **)0x75926d;
          FUN_00408a60();
          iVar2 = *(int *)(local_6418 + 600);
          uStack_650c._4_4_ = *(undefined1 **)(iVar2 + 8);
          auStack_6504._0_4_ = *(undefined4 *)(iVar2 + 0xc);
          auStack_6504._4_4_ = *(undefined4 *)(iVar2 + 0x10);
          ppuStack_64fc = *(undefined ***)(iVar2 + 0x14);
          uStack_650c._0_4_ = local_44;
          iStack_6510 = 0x7592a3;
          FUN_004988c0();
          auStack_6504._4_4_ = SUB84(local_6420,0);
          ppuStack_64fc = (undefined **)((ulonglong)local_6420 >> 0x20);
          uStack_650c._0_4_ = *(undefined1 **)(local_6418 + 600);
          iStack_6510 = local_28;
          uStack_650c._4_4_ = (undefined1 *)auStack_6504._4_4_;
          auStack_6504._0_4_ = ppuStack_64fc;
          FUN_00465c40(0,0,local_34,local_30,local_2c);
        }
      }
    }
    ppuStack_64fc = &PTR_s_CDataSunpou_009fe078;
    auStack_6504._4_4_ = 0x759318;
    iVar2 = FUN_0079d98a();
    if (iVar2 != 0) {
      local_6444 = *(int *)(local_6418 + 600);
      if (local_6420 - 1.0 <= 0.0) {
        local_649c = -(local_6420 - 1.0);
      }
      else {
        local_649c = local_6420 - 1.0;
      }
      if (1e-07 < local_649c) {
        if (local_6420 <= 0.0) {
          local_64a4 = -local_6420;
        }
        else {
          local_64a4 = local_6420;
        }
        if (1e-07 < local_64a4) {
          local_24 = *(undefined4 *)(local_6444 + 0xd8);
          local_20 = *(undefined4 *)(local_6444 + 0xdc);
          local_1c = *(undefined4 *)(local_6444 + 0xe0);
          local_18 = *(int *)(local_6444 + 0xe4);
          auStack_6504._0_4_ = *(undefined4 *)(local_6444 + 0xe8);
          auStack_6504._4_4_ = *(undefined4 *)(local_6444 + 0xec);
          ppuStack_64fc = *(undefined ***)(local_6444 + 0xf0);
          ppuStack_64f8 = *(undefined ***)(local_6444 + 0xf4);
          uStack_650c._4_4_ = (undefined1 *)0x75943e;
          FUN_00498ac0();
          ppuStack_64fc = (undefined **)0x0;
          ppuStack_64f8 = (undefined **)0x40000000;
          auStack_6504._4_4_ = 0x759456;
          FUN_00498bf0();
          ppuStack_64f8 = (undefined **)0x0;
          auStack_6504._4_4_ = SUB84(local_6420,0);
          ppuStack_64fc = (undefined **)((ulonglong)local_6420 >> 0x20);
          uStack_650c._0_4_ = (undefined1 *)(local_6444 + 0xd0);
          iStack_6510 = local_18;
          uStack_650c._4_4_ = (undefined1 *)auStack_6504._4_4_;
          auStack_6504._0_4_ = ppuStack_64fc;
          FUN_00466e30(0,0,local_24,local_20,local_1c);
        }
      }
    }
  }
  local_6454 = 1.0 / *(double *)
                      (*(int *)(local_6418 + 4) + 0x2578 +
                      *(int *)(*(int *)(local_6418 + 4) + 0x256c) * 8);
  if (*(int *)(local_6418 + 0x268) == 0) {
    local_6454 = 1.0 / *(double *)(*(int *)(local_6418 + 4) + 0x2578 + local_6424 * 8);
  }
  else {
    ppuStack_64f8 = *(undefined ***)(*(int *)(local_6418 + 4) + 0x256c);
    ppuStack_64fc = (undefined **)0x759541;
    FUN_00455380();
  }
  local_6438 = *(double *)(local_6418 + 0x240) * local_6454;
  local_6430 = *(double *)(local_6418 + 0x248) * local_6454;
  local_6480 = *(undefined4 *)(local_6418 + 0x270);
  local_64ac = local_6430;
  if (local_6430 <= 0.0) {
    local_64ac = -local_6430;
  }
  local_64b4 = local_6438;
  if (local_6438 <= 0.0) {
    local_64b4 = -local_6438;
  }
  ppuStack_64fc = SUB84(local_64ac,0);
  ppuStack_64f8 = (undefined **)((ulonglong)local_64ac >> 0x20);
  auStack_6504._0_4_ = SUB84(local_64b4,0);
  auStack_6504._4_4_ = (undefined4)((ulonglong)local_64b4 >> 0x20);
  uStack_650c._4_4_ = *(undefined1 **)(local_6418 + 600);
  iStack_6510 = *(int *)(local_6418 + 0x208);
  uStack_650c._0_4_ = *(undefined1 **)(local_6418 + 0x20c);
  FUN_00465c40(0,0,*(undefined4 *)(local_6418 + 0x200),*(undefined4 *)(local_6418 + 0x204));
  if ((local_6438 < 0.0) || (local_6430 < 0.0)) {
    if (0.0 <= local_6438) {
      local_6438 = 1.0;
    }
    else {
      local_6438 = -1.0;
    }
    if (0.0 <= local_6430) {
      local_6430 = 1.0;
    }
    else {
      local_6430 = -1.0;
    }
    ppuStack_64fc = (undefined **)0x0;
    ppuStack_64f8 = (undefined **)((ulonglong)local_6430 >> 0x20);
    auStack_6504._0_4_ = 0;
    auStack_6504._4_4_ = (undefined4)((ulonglong)local_6438 >> 0x20);
    uStack_650c._4_4_ = *(undefined1 **)(local_6418 + 600);
    iStack_6510 = *(int *)(local_6418 + 0x208);
    uStack_650c._0_4_ = *(undefined1 **)(local_6418 + 0x20c);
    FUN_00465c40(0,0,*(undefined4 *)(local_6418 + 0x200),*(undefined4 *)(local_6418 + 0x204));
  }
  ppuStack_64f8 = &PTR_s_CDataMoji_009fe108;
  ppuStack_64fc = (undefined **)0x759769;
  iVar2 = FUN_0079d98a();
  if (iVar2 != 0) {
    if ((DAT_00a0cb58 != 0) && (local_647c == 0)) {
      local_6428 = *(int *)(local_6418 + 600);
      local_6440 = *(double *)(local_6428 + 0xb8) / local_6454;
      local_64bc = local_6440;
      if (local_6440 <= 0.0) {
        local_64bc = -local_6440;
      }
      if (local_64bc < 0.01) {
        local_6440 = 0.01;
      }
      local_64d4 = *(double *)(local_6428 + 0xc0) / local_6454;
      if (local_6440 <= 0.0) {
        local_64c4 = -local_6440;
      }
      else {
        local_64c4 = local_6440;
      }
      if (local_64c4 < 0.01) {
        local_64d4 = 0.01;
      }
      if ((0.01 < *(double *)(local_6428 + 200)) ||
         (*(double *)(local_6428 + 200) <= 0.0001 && *(double *)(local_6428 + 200) != 0.0001)) {
        local_64cc = local_6454;
      }
      else {
        local_64cc = 1.0;
      }
      local_64f0 = *(double *)(local_6428 + 200) / local_64cc;
      uStack_650c._4_4_ = SUB84(local_64d4,0);
      auStack_6504._0_4_ = (undefined4)((ulonglong)local_64d4 >> 0x20);
      iStack_6510 = SUB84(local_6440,0);
      uStack_650c._0_4_ = (undefined1 *)((ulonglong)local_6440 >> 0x20);
      unique0x1000057a = local_64f0;
      FUN_00476020(1,1,local_6428);
    }
    if (*(int *)(local_6418 + 0x26c) == 3) {
      ppuStack_64fc = (undefined **)0x0;
      auStack_6504._4_4_ = *(undefined4 *)(local_6418 + 600);
      auStack_6504._0_4_ = 0x759972;
      FUN_00470100();
    }
  }
  ppuStack_64fc = &PTR_s_CDataTen_009fe05c;
  auStack_6504._4_4_ = 0x759988;
  iVar2 = FUN_0079d98a();
  if (((iVar2 != 0) && (DAT_00a0cb5c != 0)) &&
     (local_6448 = *(int *)(local_6418 + 600), *(int *)(local_6448 + 0x6c) != 0)) {
    *(double *)(local_6448 + 0x78) = *(double *)(local_6448 + 0x78) / local_6454;
  }
  DAT_00a0cb58 = local_646c;
  DAT_00a0cb5c = local_6470;
  if (*(int *)(local_6418 + 0x26c) == 3) {
    auStack_6504._4_4_ = &PTR_s_CDataMoji_009fe108;
    auStack_6504._0_4_ = 0x759a12;
    iVar2 = FUN_0079d98a();
    if (iVar2 != 0) {
      local_6458 = *(undefined4 *)(local_6418 + 600);
      local_6460 = 100.0;
      local_6468 = 100.0;
      auStack_6504._4_4_ = 0x759a57;
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,2);
      auStack_6504._4_4_ = &local_6468;
      auStack_6504._0_4_ = &local_6460;
      uStack_650c._4_4_ = local_644c;
      uStack_650c._0_4_ = (undefined1 *)0x759a7b;
      iVar2 = FUN_0048f790();
      if (iVar2 != 0) {
        local_64dc = *(double *)(*(int *)(local_6418 + 4) + 0x2578 + local_6424 * 8);
        local_6460 = local_6460 * local_64dc;
        local_6468 = local_6468 * local_64dc;
        local_64e8 = (undefined1 *)&iStack_6510;
        iStack_6510 = local_6418;
        auStack_6504 = (undefined1  [8])local_6468;
        uStack_650c = local_6460;
        FUN_00403dd0(local_644c);
        FUN_0048f7f0();
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      auStack_6504._4_4_ = 0x759b22;
      FUN_00404540();
    }
  }
  auStack_6504._0_4_ = (undefined4)*(undefined8 *)(local_6418 + 0x250);
  auStack_6504._4_4_ = (undefined4)((ulonglong)*(undefined8 *)(local_6418 + 0x250) >> 0x20);
  uStack_650c._4_4_ = *(undefined1 **)(local_6418 + 600);
  iStack_6510 = *(int *)(local_6418 + 0x208);
  uStack_650c._0_4_ = *(undefined1 **)(local_6418 + 0x20c);
  FUN_0046d5b0(*(undefined4 *)(local_6418 + 0x200),*(undefined4 *)(local_6418 + 0x204));
  auStack_6504._4_4_ = 0;
  auStack_6504._0_4_ = 0;
  iStack_6510 = *(int *)(local_6418 + 0x214);
  uStack_650c._0_4_ = *(undefined1 **)(local_6418 + 0x218);
  uStack_650c._4_4_ = *(undefined1 **)(local_6418 + 0x21c);
  FUN_0046bdf0(*(undefined4 *)(local_6418 + 0x200),*(undefined4 *)(local_6418 + 0x204),
               *(undefined4 *)(local_6418 + 0x208),*(undefined4 *)(local_6418 + 0x20c),
               *(undefined4 *)(local_6418 + 600),*(undefined4 *)(local_6418 + 0x210));
  local_8 = local_8 & 0xffffff00;
  auStack_6504._4_4_ = 0x759bef;
  FUN_004640a0();
  local_8 = 0xffffffff;
  auStack_6504._4_4_ = 0x759c01;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTourokuZukei[4] */
/* 00759c20  FUN_00759c20  310 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00759c20(void)

{
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093711b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6404,*(undefined4 *)(local_63e8 + 4));
  FUN_0044de00(local_6404,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c830(local_6404,*(undefined4 *)(local_63e8 + 4));
  local_63ec = *(int *)(local_63e8 + 4);
  if (local_63ec == 0) {
    local_63f0 = 0;
  }
  else {
    local_63f0 = local_63ec + 0x88;
  }
  FUN_00454890(local_63f0);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTourokuZukei[3] */
/* 00759d60  FUN_00759d60  3119 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00759d60(void)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  double dVar3;
  double dStack_19d58;
  undefined1 auStack_19d50 [20];
  undefined4 uStack_19d3c;
  int iStack_19d38;
  undefined4 uStack_19d34;
  int iStack_19d30;
  undefined4 uStack_19d2c;
  undefined4 uStack_19d28;
  int iStack_19d24;
  int iStack_19d20;
  int iStack_19d1c;
  uint uStack_19d18;
  double dStack_19d14;
  int iStack_19d0c;
  byte bStack_19d05;
  undefined4 uStack_19d04;
  int iStack_19d00;
  CWaitCursor CStack_19cf9;
  int iStack_19cf8;
  int *piStack_19cf4;
  int *piStack_19cf0;
  undefined4 uStack_139f4;
  int iStack_139a0;
  int aiStack_138b4 [10004];
  int aiStack_9c64 [10004];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942179;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piStack_19cf0 = in_ECX;
  local_14 = uVar1;
  FUN_005168b0(0x1456,*(undefined4 *)(in_ECX[1] + 0x8f24),*(undefined4 *)(in_ECX[1] + 0x8f28),0,0);
  piStack_19cf0[0x97] = (&DAT_00a0c074)[piStack_19cf0[0x9b]];
  piStack_19cf0[0x98] = (&DAT_00a0c08c)[piStack_19cf0[0x9b]];
  piStack_19cf0[0x99] = (&DAT_00a0c0a4)[piStack_19cf0[0x9b]];
  piStack_19cf0[0x9a] = (&DAT_00a0c0bc)[piStack_19cf0[0x9b]];
  FUN_004fb910();
  CWaitCursor::CWaitCursor(&CStack_19cf9);
  local_8 = 0;
  uStack_19d04 = FUN_0040c0e0(uVar1);
  FUN_0079dea2();
  local_8._0_1_ = 1;
  FUN_00446aa0();
  local_8._0_1_ = 2;
  FUN_00464040();
  local_8._0_1_ = 3;
  if (DAT_00a0bd90 == 1) {
    iStack_19d30 = FUN_00479d80();
    iStack_139a0 = iStack_19d30;
  }
  FUN_0044dd90(auStack_19d50,piStack_19cf0[1]);
  FUN_0044de00(auStack_19d50,piStack_19cf0[1]);
  FUN_0044c830(auStack_19d50,piStack_19cf0[1]);
  piStack_19cf4 = (int *)0x0;
  if ((piStack_19cf0[0x8a] == 0) || (iVar2 = FUN_00757c70(), iVar2 != 0)) {
    uStack_19d34 = *(undefined4 *)
                    (piStack_19cf0[1] + 0x24ec + *(int *)(piStack_19cf0[1] + 0x256c) * 4);
    uStack_19d18 = *(uint *)(piStack_19cf0[1] + 0x256c);
    if (piStack_19cf0[0x9a] == 0) {
      dVar3 = *(double *)(piStack_19cf0[1] + 0x2578 + uStack_19d18 * 8);
      iStack_19d00 = FUN_00572c70();
      do {
        if ((iStack_19d00 == 0) ||
           (piStack_19cf4 = (int *)FUN_00572cd0(&iStack_19d00,0), piStack_19cf4 == (int *)0x0))
        goto LAB_0075a137;
        bStack_19d05 = (**(code **)(*piStack_19cf4 + 0x28))();
      } while ((bStack_19d05 == uStack_19d18) ||
              (*(double *)(piStack_19cf0[1] + 0x2578 + (uint)bStack_19d05 * 8) == dVar3));
      iVar2 = FUN_004f60a0(0x157e,1,0xffffffff);
      if (iVar2 != 1) {
        local_8._0_1_ = 2;
        FUN_004640a0();
        local_8._0_1_ = 1;
        FUN_00447100();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00408b00();
        ExceptionList = local_10;
        return;
      }
    }
LAB_0075a137:
    iStack_19d00 = FUN_00572c70();
    while (iStack_19d00 != 0) {
      iStack_19d20 = iStack_19d00;
      piStack_19cf4 = (int *)FUN_00572cd0(&iStack_19d00,0);
      if (piStack_19cf4 == (int *)0x0) break;
      iVar2 = (**(code **)(*piStack_19cf4 + 0x14))();
      piStack_19cf0[0x96] = iVar2;
      *(ushort *)(piStack_19cf0[0x96] + 0x44) = *(ushort *)(piStack_19cf4 + 0x11) & 0xfffd;
      *(int *)(piStack_19cf0[0x96] + 4) = piStack_19cf4[1];
      (**(code **)(*piStack_19cf0 + 0x20))();
      FUN_00447cf0(auStack_19d50,piStack_19cf0[1],piStack_19cf0[0x96],0);
    }
    iStack_19d0c = 0;
    for (iStack_19cf8 = 0; iStack_19cf8 < 0x2711; iStack_19cf8 = iStack_19cf8 + 1) {
      aiStack_9c64[iStack_19cf8] = 0;
      aiStack_138b4[iStack_19cf8] = 0;
    }
    iStack_19d00 = FUN_005725e0();
    while (piStack_19cf4 = (int *)FUN_00572600(&iStack_19d00,0), piStack_19cf4 != (int *)0x0) {
      if (piStack_19cf4[1] != 0) {
        iStack_19d1c = 0;
        for (iStack_19cf8 = 1; iStack_19cf8 <= iStack_19d0c; iStack_19cf8 = iStack_19cf8 + 1) {
          if (piStack_19cf4[1] == aiStack_9c64[iStack_19cf8]) {
            iStack_19d1c = iStack_19cf8;
            break;
          }
        }
        if (iStack_19d1c == 0) {
          if (iStack_19d0c < 10000) {
            iStack_19d0c = iStack_19d0c + 1;
            aiStack_9c64[iStack_19d0c] = piStack_19cf4[1];
          }
          else {
            piStack_19cf4[1] = 0;
          }
        }
      }
    }
    FUN_00454830();
    uStack_139f4 = 0;
    iStack_19d00 = FUN_005725e0();
    while (iStack_19d00 != 0) {
      iStack_19d20 = iStack_19d00;
      piStack_19cf4 = (int *)FUN_00572600(&iStack_19d00,0);
      if (piStack_19cf4 == (int *)0x0) break;
      FUN_00574ec0();
      if (piStack_19cf0[0x9a] == 1) {
        FUN_00455380();
      }
      if (piStack_19cf0[0x99] == 1) {
        FUN_0040db50();
      }
      iVar2 = FUN_0079d98a();
      if ((iVar2 == 0) && (piStack_19cf0[0x97] == 1)) {
        (**(code **)(*piStack_19cf4 + 0x20))(DAT_00a0b418);
      }
      if (piStack_19cf0[0x98] == 1) {
        (**(code **)(*piStack_19cf4 + 0x24))(DAT_00a0b428);
        FUN_00457840(DAT_00a0b424);
        iVar2 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
        if (iVar2 != 0) {
          FUN_00457840(0);
        }
      }
      iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if ((iVar2 == 0) && (iVar2 = FUN_0079d98a(), iVar2 == 0)) {
        iVar2 = FUN_0079d98a();
        if ((iVar2 == 0) && (iVar2 = FUN_0079d98a(), iVar2 == 0)) {
          if (piStack_19cf0[0x9b] < 2) {
            *(ushort *)(piStack_19cf4 + 0x11) = *(ushort *)(piStack_19cf4 + 0x11) | 0x800;
          }
        }
        else if (piStack_19cf0[0x9b] < 2) {
          *(ushort *)(piStack_19cf4 + 0x11) = *(ushort *)(piStack_19cf4 + 0x11) | 0x10;
        }
      }
      else if (piStack_19cf0[0x9b] < 2) {
        *(ushort *)(piStack_19cf4 + 0x11) = *(ushort *)(piStack_19cf4 + 0x11) | 0x800;
      }
      if (piStack_19cf4[1] != 0) {
        for (iStack_19cf8 = 1; iStack_19cf8 <= iStack_19d0c; iStack_19cf8 = iStack_19cf8 + 1) {
          if (aiStack_9c64[iStack_19cf8] == piStack_19cf4[1]) {
            if (aiStack_138b4[iStack_19cf8] == 0) {
              iVar2 = FUN_00479d80();
              aiStack_138b4[iStack_19cf8] = iVar2;
            }
            piStack_19cf4[1] = aiStack_138b4[iStack_19cf8];
          }
        }
      }
      if (((piStack_19cf0[0x9d] == 0) || (iVar2 = FUN_0079d98a(), iVar2 == 0)) ||
         (iVar2 = FUN_0075ae00(), iVar2 == 0)) {
        FUN_00447670(auStack_19d50,piStack_19cf0[1],piStack_19cf4,1,0);
        iStack_19d38 = DAT_00a0bd90;
        if (DAT_00a0bd90 == 1) {
          piStack_19cf4[1] = iStack_139a0;
        }
        else {
          piStack_19cf4[1] = piStack_19cf4[1];
        }
        uStack_139f4 = 1;
        if ((piStack_19cf0[0x9d] != 0) && (iVar2 = FUN_0079d98a(), iVar2 != 0)) {
          iStack_19d24 = FUN_004121b0();
          local_8._0_1_ = 4;
          if (iStack_19d24 == 0) {
            uStack_19d28 = 0;
          }
          else {
            uStack_19d28 = FUN_0041f760();
          }
          uStack_19d3c = uStack_19d28;
          local_8._0_1_ = 3;
          uStack_19d2c = uStack_19d28;
          FUN_0041f690();
          local_8._0_1_ = 5;
          FUN_00420110();
          local_8._0_1_ = 3;
          FUN_0041fd70();
          FUN_00570940();
        }
      }
    }
    FUN_00454830();
    piStack_19cf0[0x88] = 0;
    uStack_139f4 = 0;
    if (piStack_19cf0[0x8a] != 0) {
      dStack_19d14 = (*(double *)(piStack_19cf0 + 0x94) * 180.0) / 3.141592653589793 -
                     *(double *)(piStack_19cf0[1] + 0x17c0);
      if (180.0 < dStack_19d14) {
        dStack_19d14 = dStack_19d14 - 360.0;
      }
      if (dStack_19d14 <= -180.0) {
        dStack_19d14 = dStack_19d14 + 360.0;
      }
      if (dStack_19d14 <= 0.0) {
        dStack_19d58 = -dStack_19d14;
      }
      else {
        dStack_19d58 = dStack_19d14;
      }
      if (dStack_19d58 < 1e-07) {
        dStack_19d14 = 0.0;
      }
      dVar3 = dStack_19d14;
      FUN_00404c80(dStack_19d14);
      FUN_004fca20();
      FUN_005f55b0(dVar3);
      piStack_19cf0[0x8a] = 0;
    }
    FUN_00457f70();
    FUN_0044cec0();
    FUN_00757e40();
    local_8._0_1_ = 2;
    FUN_004640a0();
    local_8._0_1_ = 1;
    FUN_00447100();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00408b00();
  }
  else {
    FUN_005168b0(0x1455,*(undefined4 *)(piStack_19cf0[1] + 0x8f24),
                 *(undefined4 *)(piStack_19cf0[1] + 0x8f28),0,0);
    local_8._0_1_ = 2;
    FUN_004640a0();
    local_8._0_1_ = 1;
    FUN_00447100();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00408b00();
  }
  ExceptionList = local_10;
  return;
}



