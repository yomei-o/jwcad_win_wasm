/* CZukeiParametric -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiParametric[1] */
/* 006cb5a0  FUN_006cb5a0  68 bytes, 0 callers */

undefined4 FUN_006cb5a0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004fa9a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xfd68);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiParametric[6] */
/* 006cba00  FUN_006cba00  4179 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006cba00(double *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  float10 fVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  double local_68b8;
  double local_68b0;
  double local_68a8;
  double local_68a0;
  undefined1 local_6898 [20];
  undefined4 local_6884;
  undefined4 local_6880;
  int local_687c;
  int local_6878;
  int local_6874;
  int local_6870;
  int local_686c;
  int local_6868;
  double local_6864;
  undefined4 local_685c;
  int local_6858;
  int *local_6854;
  int local_6850;
  undefined1 local_45c [32];
  undefined1 local_43c [16];
  double local_42c;
  double local_424;
  undefined1 local_218 [516];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093dd0b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  puVar2 = (undefined4 *)FUN_004b6d60();
  uVar4 = puVar2[1];
  *(undefined4 *)(local_6850 + 0x214) = *puVar2;
  *(undefined4 *)(local_6850 + 0x218) = uVar4;
  if (*(int *)(local_6850 + 0x208) != 0) {
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(local_6850 + 0x20c) != 0) {
    *(undefined4 *)(local_6850 + 0x20c) = 0;
    ExceptionList = local_10;
    return;
  }
  local_685c = FUN_0040c0e0(uVar1);
  iVar3 = FUN_00572b10();
  if ((iVar3 == 0) && (*(int *)(local_6850 + 0x1fc) == 0)) {
    *(undefined4 *)(local_6850 + 0x1fc) = 1;
    DAT_00a0d618 = 1;
    FUN_006cb5f0();
  }
  *(undefined4 *)(local_6850 + 0xd8) = 1;
  if (*(int *)(local_6850 + 0x1fc) != 0) {
    FUN_006f7cc0(param_1);
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(local_6850 + 0x1f8) != 0) {
    FUN_0040ac80(param_1);
    ExceptionList = local_10;
    return;
  }
  puVar2 = (undefined4 *)FUN_004b75a0(local_43c);
  uVar4 = *puVar2;
  uVar6 = *(undefined8 *)(puVar2 + 1);
  uVar7 = puVar2[3];
  FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
  iVar3 = FUN_004989a0(uVar4,uVar6,uVar7);
  if (iVar3 != 0) {
    FUN_004b75a0(local_45c);
    FUN_004988c0();
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6850 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*(int *)(*(int *)(local_6850 + 4) + 0x8598) == 100) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(local_6850 + 0xfcec) = 1;
  *(double *)(local_6850 + 0xfc88) =
       (*(double *)(*(int *)(local_6850 + 4) + 0x17c0) / 180.0) * 3.141592653589793;
  *(undefined8 *)(local_6850 + 0xfc90) = 0x3ff0000000000000;
  *(undefined8 *)(local_6850 + 0xfca0) = 0x3ff0000000000000;
  *(undefined8 *)(local_6850 + 0xfcb0) = 0;
  *(undefined8 *)(local_6850 + 0xfcc0) = 0;
  *(undefined8 *)(local_6850 + 0xfcd0) = 0;
  *(undefined4 *)(local_6850 + 0xfce0) = 0;
  *(undefined4 *)(local_6850 + 0xfce4) = 0;
  *(undefined4 *)(local_6850 + 0xfce8) = 0;
  local_6868 = 0;
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) == *(int *)(*(int *)(local_6850 + 4) + 0x85f8)) {
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae430();
    *(double *)(local_6850 + 0xfc90) = (double)fVar5;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae460();
    *(double *)(local_6850 + 0xfca0) = (double)fVar5;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae590();
    *(double *)(local_6850 + 0xfcb0) = (double)fVar5;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae4a0();
    *(double *)(local_6850 + 0xfcc0) = (double)fVar5;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae510();
    *(double *)(local_6850 + 0xfcd0) = (double)fVar5;
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined4 *)(local_6850 + 0xfce0) = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xc78);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined4 *)(local_6850 + 0xfce4) = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xc7c);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined4 *)(local_6850 + 0xfce8) = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xc70);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    local_6868 = *(int *)(*(int *)(iVar3 + 0x1a0) + 0xc0);
  }
  iVar3 = FUN_00572b10();
  if (iVar3 == 0) {
    *(undefined4 *)(local_6850 + 0xfcec) = 0;
    *(undefined4 *)(local_6850 + 0x204) = 0;
  }
  FUN_0044dd90();
  local_6854 = (int *)0x0;
  if (*(int *)(local_6850 + 0xfcec) == 0) {
    *(undefined4 *)(local_6850 + 0x204) = 0;
    FUN_004efbb0(0x14c2,0,0);
  }
  if (*(int *)(local_6850 + 0xfcec) != 1) goto LAB_006cca37;
  if (*(double *)(local_6850 + 0xfcc0) <= 0.0) {
    local_68a0 = -*(double *)(local_6850 + 0xfcc0);
  }
  else {
    local_68a0 = *(double *)(local_6850 + 0xfcc0);
  }
  if (1e-07 < local_68a0) {
LAB_006cc03e:
    *(undefined4 *)(local_6850 + 0x204) = 0xffffffff;
    FUN_004efbb0(0x1522,0,0);
    FUN_0044cd50(0,local_6850 + 0xfcc0,local_6850 + 0xfcd0);
    *(double *)(local_6850 + 0xfc78) =
         *(double *)(local_6850 + 0x228) + *(double *)(local_6850 + 0xfcc0);
    *(double *)(local_6850 + 0xfc80) =
         *(double *)(local_6850 + 0x230) + *(double *)(local_6850 + 0xfcd0);
    *(undefined4 *)(local_6850 + 0xfce0) = 0;
    *(undefined4 *)(local_6850 + 0xfce4) = 0;
    *(undefined8 *)(local_6850 + 0xfc98) = *(undefined8 *)(local_6850 + 0xfc90);
    *(undefined8 *)(local_6850 + 0xfca8) = *(undefined8 *)(local_6850 + 0xfca0);
    *(undefined8 *)(local_6850 + 0xfcb8) = *(undefined8 *)(local_6850 + 0xfcb0);
    *(undefined8 *)(local_6850 + 0xfcc8) = *(undefined8 *)(local_6850 + 0xfcc0);
    *(undefined8 *)(local_6850 + 0xfcd8) = *(undefined8 *)(local_6850 + 0xfcd0);
  }
  else {
    if (*(double *)(local_6850 + 0xfcd0) <= 0.0) {
      local_68a8 = -*(double *)(local_6850 + 0xfcd0);
    }
    else {
      local_68a8 = *(double *)(local_6850 + 0xfcd0);
    }
    if (1e-07 < local_68a8) goto LAB_006cc03e;
    if (*(int *)(local_6850 + 0x204) != *(int *)(local_6850 + 0xfcec)) {
      *(undefined4 *)(local_6850 + 0x204) = *(undefined4 *)(local_6850 + 0xfcec);
      DAT_00a0b3b8 = 0;
    }
    if ((*(int *)(*(int *)(local_6850 + 4) + 0x1780) != 0) &&
       (*(int *)(*(int *)(local_6850 + 4) + 0x176c) != 0)) {
      FUN_0041df00();
    }
    FUN_004988c0();
    local_42c = *param_1;
    local_424 = param_1[1];
    FUN_005f89c0();
    FUN_005f92e0(&local_42c);
    if ((*(int *)(local_6850 + 0xfce0) == 0) || (*(int *)(local_6850 + 0xfce4) == 0)) {
      if (*(int *)(local_6850 + 0xfce0) != 0) {
        local_424 = 0.0;
      }
      if (*(int *)(local_6850 + 0xfce4) != 0) {
        local_42c = 0.0;
      }
    }
    else {
      if (local_42c <= 0.0) {
        local_68b0 = -local_42c;
      }
      else {
        local_68b0 = local_42c;
      }
      if (local_424 <= 0.0) {
        local_68b8 = -local_424;
      }
      else {
        local_68b8 = local_424;
      }
      if (local_68b0 <= local_68b8) {
        local_42c = 0.0;
      }
      else {
        local_424 = 0.0;
      }
    }
    FUN_00403d00();
    local_6864 = local_42c *
                 *(double *)
                  (*(int *)(local_6850 + 4) + 0x2578 +
                  *(int *)(*(int *)(local_6850 + 4) + 0x256c) * 8);
    if (DAT_00a0d62c != 0) {
      local_6864 = local_6864 / DAT_00a0d630;
    }
    FUN_0045a220();
    FUN_00408850();
    FUN_00408850();
    local_6864 = local_424 *
                 *(double *)
                  (*(int *)(local_6850 + 4) + 0x2578 +
                  *(int *)(*(int *)(local_6850 + 4) + 0x256c) * 8);
    if (DAT_00a0d62c != 0) {
      local_6864 = local_6864 / DAT_00a0d630;
    }
    FUN_0045a220();
    FUN_00408850();
    FUN_00408850();
    if (DAT_00a0d62c != 0) {
      FUN_00404920();
      FUN_00408850();
    }
    FUN_004efbb0(0x14bf,local_218,1);
  }
  if (DAT_00a0b3b8 == 0) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  if ((local_6868 != 0) && (0 < *(int *)(local_6850 + 0xfd60))) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  FUN_004044d0();
  local_6884 = *(undefined4 *)(*(int *)(local_6850 + 4) + 0x8f40);
  local_6880 = *(undefined4 *)(*(int *)(local_6850 + 4) + 0x8f44);
  if (*(int *)(local_6850 + 0x210) != 0) {
    if (*(int *)(local_6850 + 0x21c) == *(int *)(local_6850 + 0x214) ||
        *(int *)(local_6850 + 0x21c) - *(int *)(local_6850 + 0x214) < 0) {
      local_686c = -(*(int *)(local_6850 + 0x21c) - *(int *)(local_6850 + 0x214));
    }
    else {
      local_686c = *(int *)(local_6850 + 0x21c) - *(int *)(local_6850 + 0x214);
    }
    if (local_686c < 3) {
      if (*(int *)(local_6850 + 0x220) == *(int *)(local_6850 + 0x218) ||
          *(int *)(local_6850 + 0x220) - *(int *)(local_6850 + 0x218) < 0) {
        local_6870 = -(*(int *)(local_6850 + 0x220) - *(int *)(local_6850 + 0x218));
      }
      else {
        local_6870 = *(int *)(local_6850 + 0x220) - *(int *)(local_6850 + 0x218);
      }
      if (local_6870 < 3) {
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
    }
    *(undefined4 *)(local_6850 + 0x210) = 0;
  }
  local_6874 = FUN_00572b10();
  while( true ) {
    do {
      if ((local_6874 == 0) || (local_6854 = (int *)FUN_00572b30(), local_6854 == (int *)0x0))
      goto LAB_006cca37;
      local_6878 = *(int *)(local_6850 + 4);
      if (local_6878 == 0) {
        local_687c = 0;
      }
      else {
        local_687c = local_6878 + 0x88;
      }
      iVar3 = FUN_0042dcb0(local_687c);
    } while (iVar3 != 0);
    iVar3 = FUN_004fcab0();
    if (iVar3 != 0) break;
    uVar4 = (**(code **)(*local_6854 + 0x14))();
    *(undefined4 *)(local_6850 + 0xfd18) = uVar4;
    FUN_0040e410(0);
    FUN_0040e450(0);
    FUN_0040db70(0);
    iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
    if (iVar3 != 0) {
      iVar3 = FUN_0044f450();
      if (iVar3 != 0) {
        FUN_0040e410();
        (**(code **)(**(int **)(local_6850 + 0xfd18) + 0x20))();
      }
      iVar3 = FUN_0044f480();
      if (iVar3 != 0) {
        FUN_0040e450();
        (**(code **)(**(int **)(local_6850 + 0xfd18) + 0x20))();
      }
      iVar3 = FUN_0044f280();
      if (iVar3 != 0) {
        FUN_0040db70();
        (**(code **)(**(int **)(local_6850 + 0xfd18) + 0x20))();
      }
    }
    iVar3 = FUN_0079d98a();
    if (iVar3 != 0) {
      local_6858 = *(int *)(local_6850 + 0xfd18);
      iVar3 = FUN_0044f450();
      if (iVar3 != 0) {
        FUN_0040e410(1);
        (**(code **)(*(int *)(local_6858 + 0x68) + 0x20))(10);
      }
      iVar3 = FUN_0044f480();
      if (iVar3 != 0) {
        FUN_0040e450(1);
        (**(code **)(*(int *)(local_6858 + 0x68) + 0x20))(10);
      }
      iVar3 = FUN_0044f280();
      if (iVar3 != 0) {
        FUN_0040db70(1);
        (**(code **)(*(int *)(local_6858 + 0x68) + 0x20))(10);
      }
    }
    FUN_006ce8b0();
    FUN_00447cf0(local_6898,*(undefined4 *)(local_6850 + 4),*(undefined4 *)(local_6850 + 0xfd18),1);
  }
LAB_006cca37:
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiParametric[16] */
/* 006cca80  FUN_006cca80  1267 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006cca80(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_6424 [20];
  undefined4 local_6410;
  undefined4 local_640c;
  int local_6408;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093dd5b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6410 = FUN_0040c0e0(local_14);
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*(int *)(local_6408 + 0x1fc) == 0) {
    if (*(int *)(local_6408 + 0xfd60) < 1) {
      if (*(int *)(local_6408 + 0xfd60) < 1) {
        *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
        *(undefined4 *)(local_6408 + 0xfd60) = 0xffffffff;
        *(undefined4 *)(local_6408 + 0x1fc) = 1;
        DAT_00a0d618 = 1;
        FUN_006cb5f0();
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6408 + 4) + 0x8610)) {
          iVar1 = FUN_00572b10();
          if (iVar1 != 0) {
            uVar5 = 1;
            FUN_00404c80(1);
            FUN_004fca20();
            FUN_005c8120(uVar5);
          }
        }
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar5 = 1;
      }
      else {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar5 = 0;
      }
    }
    else {
      FUN_0044dd90(local_6424,*(undefined4 *)(local_6408 + 4));
      FUN_0044de00(local_6424,*(undefined4 *)(local_6408 + 4));
      local_640c = 0;
      FUN_0044c830(local_6424,*(undefined4 *)(local_6408 + 4));
      local_640c = 1;
      FUN_00458a80(local_6424,*(undefined4 *)(local_6408 + 4),1);
      *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
      *(int *)(local_6408 + 0xfd60) = *(int *)(local_6408 + 0xfd60) + -1;
      if (*(int *)(local_6408 + 0xfd60) < 0xfa1) {
        FUN_004988c0();
        FUN_00517640(*(undefined4 *)(local_6408 + 0x228),*(undefined4 *)(local_6408 + 0x22c),
                     *(undefined4 *)(local_6408 + 0x230),*(undefined4 *)(local_6408 + 0x234));
        uVar5 = *(undefined4 *)(local_6408 + 0x228);
        uVar2 = *(undefined4 *)(local_6408 + 0x22c);
        uVar3 = *(undefined4 *)(local_6408 + 0x230);
        uVar4 = *(undefined4 *)(local_6408 + 0x234);
        FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
        iVar1 = FUN_004989a0(uVar5,uVar2,uVar3,uVar4);
        if (iVar1 != 0) {
          FUN_004508b0(0x10,local_6424,*(undefined4 *)(local_6408 + 4),
                       *(undefined4 *)(local_6408 + 0x228),*(undefined4 *)(local_6408 + 0x22c),
                       *(undefined4 *)(local_6408 + 0x230),*(undefined4 *)(local_6408 + 0x234),0);
        }
      }
      if (0 < *(int *)(local_6408 + 0xfd30)) {
        *(int *)(local_6408 + 0xfd30) = *(int *)(local_6408 + 0xfd30) + -1;
      }
      *(undefined4 *)(local_6408 + 0x20c) = 1;
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar5 = 1;
    }
  }
  else {
    iVar1 = FUN_006f85c0();
    if (iVar1 == 0) {
      iVar1 = FUN_00572b10();
      if (iVar1 == 0) {
        FUN_00458a80(local_6424,*(undefined4 *)(local_6408 + 4),0);
        *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
        *(undefined4 *)(local_6408 + 0xfd60) = 0xffffffff;
      }
      else {
        *(undefined4 *)(local_6408 + 0x1fc) = 0;
        DAT_00a0d618 = 0;
        FUN_006cb5f0();
        FUN_00404c80();
        FUN_0056d7d0();
      }
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar5 = 1;
  }
  ExceptionList = local_10;
  return uVar5;
}




/* vtable slots: CZukeiParametric[0] */
/* 006ccf80  FUN_006ccf80  16 bytes, 0 callers */

undefined ** FUN_006ccf80(void)

{
  return &PTR_s_CZukeiParametric_00979e1c;
}




/* vtable slots: CZukeiParametric[46] */
/* 006ccf90  FUN_006ccf90  1794 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006ccf90(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int in_ECX;
  undefined1 local_6444 [20];
  undefined4 local_6430;
  undefined4 local_642c;
  undefined4 local_6428;
  undefined4 local_6424;
  undefined4 local_6420;
  undefined4 local_641c;
  undefined4 local_6418;
  int local_6414;
  int local_6410;
  int local_640c;
  int local_6408;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ddab;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0c7c0 == 0) {
    local_6408 = in_ECX;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    local_6418 = 0;
    if (*(int *)(local_6408 + 0x1fc) == 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6408 + 4) + 0x85f8)) {
        if (*(int *)(*(int *)(local_6408 + 4) + 0x9078) == 0) {
          local_640c = -1;
          iVar1 = FUN_00778a40(0x15,&local_640c,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x9070),
                               param_1,param_2,param_3,param_4,param_5,param_6,param_7,0x1d);
          if (iVar1 != 0) {
            if (param_3 == 1) {
              local_6424 = 0;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              ExceptionList = local_10;
              return local_6424;
            }
            if (param_3 != 2) {
              local_6428 = 0;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              ExceptionList = local_10;
              return local_6428;
            }
            if ((-1 < local_640c) && (local_640c < 4)) {
              iVar1 = local_640c;
              FUN_00404c80(local_640c);
              FUN_004fca20();
              FUN_004ae200(iVar1);
            }
            local_642c = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
            ExceptionList = local_10;
            return local_642c;
          }
          local_6414 = param_2;
          if (param_2 == 4) {
            if (param_3 == 1) {
              FUN_005168b0(0x141c,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f50),
                           *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              FUN_0044c830(local_6444,*(undefined4 *)(local_6408 + 4));
              FUN_006cdfb0(param_4,param_5,param_6,param_7);
            }
          }
          else if (param_2 == 5) {
            if (param_3 == 1) {
              FUN_005168b0(0x272c,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f50),
                           *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              *(undefined4 *)(local_6408 + 0x1f8) = 1;
              FUN_00653df0(1);
              FUN_00652e80(0);
              FUN_004988c0(local_24,param_4,param_5,param_6,param_7);
              FUN_0040c9d0();
              *(undefined4 *)(*(int *)(local_6408 + 8) + 4) = 1;
            }
          }
          else if (param_2 == 6) {
            if (param_3 == 1) {
              FUN_005168b0(0x272d,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f50),
                           *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              *(undefined4 *)(local_6408 + 0x1f8) = 1;
              FUN_00653df0(0);
              FUN_00652e80(1);
              FUN_004988c0(local_34,param_4,param_5,param_6,param_7);
              FUN_0040c9d0();
              *(undefined4 *)(*(int *)(local_6408 + 8) + 4) = 1;
            }
          }
          else {
            local_6418 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          }
        }
        else {
          local_6410 = param_2 + -1;
          switch(param_2) {
          case 1:
          case 2:
          case 3:
          case 0xc:
            if (param_3 == 1) {
              FUN_005168b0(0x1811,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f50),
                           *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              FUN_00404c80();
              FUN_004fca20();
              FUN_004ad710();
            }
            break;
          case 4:
            if (param_3 == 1) {
              FUN_005168b0(0x1817,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f50),
                           *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              *(undefined4 *)(*(int *)(local_6408 + 4) + 0x85a0) = 1;
              FUN_00406bc0(0x111,0x8046,0);
            }
            break;
          default:
            local_6418 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          }
        }
        local_6430 = local_6418;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        local_641c = local_6430;
      }
      else {
        local_6420 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        local_641c = local_6420;
      }
    }
    else {
      local_641c = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
  }
  else {
    local_641c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return local_641c;
}




/* vtable slots: CZukeiParametric[34] */
/* 006cd6b0  FUN_006cd6b0  112 bytes, 0 callers */

void FUN_006cd6b0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = FUN_0040c0e0();
  iVar2 = FUN_00572b10(uVar1);
  if (iVar2 == 0) {
    FUN_005168b0(0x1451,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
  }
  else {
    *(undefined4 *)(in_ECX + 0x1fc) = 0;
    DAT_00a0d618 = 0;
    FUN_006cb5f0();
  }
  return;
}




/* vtable slots: CZukeiParametric[30] */
/* 006cd720  FUN_006cd720  369 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006cd720(void)

{
  int in_ECX;
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
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(local_63e8 + 0x1f8) = 0;
    FUN_00653df0(0);
    FUN_00652e80(0);
    FUN_0040c9d0();
    *(undefined4 *)(*(int *)(local_63e8 + 8) + 4) = 0;
    *(undefined4 *)(local_63e8 + 0xc) = 0;
    *(undefined4 *)(local_63e8 + 0x1fc) = 1;
    DAT_00a0d618 = 1;
    FUN_006cb5f0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_006fbbb0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiParametric[36] */
/* 006cd8a0  FUN_006cd8a0  765 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006cd8a0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double local_6400;
  double local_63f8;
  int local_63f0;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009216e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (*(int *)(in_ECX + 4) == 0) {
    local_63f0 = 0;
  }
  else {
    local_63f0 = *(int *)(in_ECX + 4) + 0x88;
  }
  iVar1 = FUN_0044fcd0(local_63f0);
  if (iVar1 != 0) {
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    uVar5 = 0;
    uVar4 = 0x8046;
    uVar3 = 0x111;
    FUN_00404c80(0x111,0x8046,0);
    FUN_00799e17();
    FUN_00406bc0(uVar3,uVar4,uVar5);
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) != *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
    FUN_00404c80();
    FUN_0056d7d0();
    goto LAB_006cdb72;
  }
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_004ae4a0();
  *(double *)(in_ECX + 0xfcc0) = (double)fVar2;
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_004ae510();
  *(double *)(in_ECX + 0xfcd0) = (double)fVar2;
  if (*(double *)(in_ECX + 0xfcc0) <= 0.0) {
    local_63f8 = -*(double *)(in_ECX + 0xfcc0);
  }
  else {
    local_63f8 = *(double *)(in_ECX + 0xfcc0);
  }
  if (1e-07 < local_63f8) {
LAB_006cdad1:
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004ae430();
    *(double *)(in_ECX + 0xfc90) = (double)fVar2;
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004ae460();
    *(double *)(in_ECX + 0xfca0) = (double)fVar2;
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004ae590();
    *(double *)(in_ECX + 0xfcb0) = (double)fVar2;
    FUN_006cf900();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
  }
  else {
    if (*(double *)(in_ECX + 0xfcd0) <= 0.0) {
      local_6400 = -*(double *)(in_ECX + 0xfcd0);
    }
    else {
      local_6400 = *(double *)(in_ECX + 0xfcd0);
    }
    if (1e-07 < local_6400) goto LAB_006cdad1;
  }
  FUN_00404c80();
  FUN_0056d200();
LAB_006cdb72:
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiParametric[49] */
/* 006cdba0  FUN_006cdba0  26 bytes, 0 callers */

void FUN_006cdba0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xfd30) = 0;
  return;
}




/* vtable slots: CZukeiParametric[51] */
/* 006cdbc0  FUN_006cdbc0  218 bytes, 0 callers */

void FUN_006cdbc0(undefined4 param_1,undefined4 param_2,double param_3)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined8 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(in_ECX + 0xfd30) = 0;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      param_3 = param_3 / *(double *)
                           (*(int *)(in_ECX + 4) + 0x2578 +
                           *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
      uVar3 = 0;
      FUN_00404c80(param_3,0);
      FUN_004fca20();
      FUN_004ae320(param_3,uVar3);
    }
  }
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiParametric[15] */
/* 006cdca0  FUN_006cdca0  776 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006cdca0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_6428 [20];
  undefined4 local_6414;
  undefined4 local_6410;
  undefined4 local_640c;
  int local_6408;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093954b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xfd30) = 0;
  local_6408 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*(int *)(local_6408 + 0xfd60) < 0) {
    local_6414 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_6410 = local_6414;
  }
  else {
    FUN_0044dd90(local_6428,*(undefined4 *)(local_6408 + 4));
    FUN_0044de00(local_6428,*(undefined4 *)(local_6408 + 4));
    local_640c = 0;
    FUN_0044c830(local_6428,*(undefined4 *)(local_6408 + 4));
    local_640c = 1;
    FUN_00453bd0(local_6428,*(undefined4 *)(local_6408 + 4),1);
    if (*(int *)(local_6408 + 0xfd60) < 0) {
      *(undefined4 *)(local_6408 + 0xfd60) = 0;
    }
    *(int *)(local_6408 + 0xfd60) = *(int *)(local_6408 + 0xfd60) + 1;
    if (*(int *)(local_6408 + 0xfd60) < 0xfa1) {
      FUN_004988c0();
      FUN_00517640(*(undefined4 *)(local_6408 + 0x228),*(undefined4 *)(local_6408 + 0x22c),
                   *(undefined4 *)(local_6408 + 0x230),*(undefined4 *)(local_6408 + 0x234));
      uVar2 = *(undefined4 *)(local_6408 + 0x228);
      uVar3 = *(undefined4 *)(local_6408 + 0x22c);
      uVar4 = *(undefined4 *)(local_6408 + 0x230);
      uVar5 = *(undefined4 *)(local_6408 + 0x234);
      FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
      iVar1 = FUN_004989a0(uVar2,uVar3,uVar4,uVar5);
      if (iVar1 != 0) {
        FUN_004508b0(0x10,local_6428,*(undefined4 *)(local_6408 + 4),
                     *(undefined4 *)(local_6408 + 0x228),*(undefined4 *)(local_6408 + 0x22c),
                     *(undefined4 *)(local_6408 + 0x230),*(undefined4 *)(local_6408 + 0x234),0);
      }
    }
    FUN_00404c80();
    FUN_0056d7d0();
    local_6410 = 1;
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_6410;
}




/* vtable slots: CZukeiParametric[10] */
/* 006ce070  FUN_006ce070  1215 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006ce070(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined1 local_6498 [20];
  int local_6484;
  int local_6480;
  int local_647c;
  int local_6478;
  int local_6474;
  int local_6470;
  int local_646c;
  int local_6468;
  undefined1 local_94 [16];
  undefined1 local_84 [96];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093899b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = *(int *)(local_6468 + 4);
  local_24 = *(undefined4 *)(iVar1 + 0x8f68);
  local_20 = *(undefined4 *)(iVar1 + 0x8f6c);
  local_1c = *(undefined4 *)(iVar1 + 0x8f70);
  local_18 = *(undefined4 *)(iVar1 + 0x8f74);
  if (*(int *)(*(int *)(local_6468 + 4) + 0x9068) != 0) {
    local_646c = *(int *)(local_6468 + 4);
    if (local_646c == 0) {
      local_6470 = 0;
    }
    else {
      local_6470 = local_646c + 0x88;
    }
    iVar1 = FUN_0044fcd0();
    if (iVar1 == 0) {
      FUN_00517640(local_24,local_20,local_1c,local_18);
      FUN_004988c0();
    }
    else {
      FUN_006cdfb0(local_24,local_20,local_1c,local_18);
    }
  }
  if (*(int *)(*(int *)(local_6468 + 4) + 0x906c) != 0) {
    local_6474 = *(int *)(local_6468 + 4);
    if (local_6474 == 0) {
      local_6478 = 0;
    }
    else {
      local_6478 = local_6474 + 0x88;
    }
    iVar1 = FUN_0044fcd0();
    if (iVar1 == 0) {
      local_6484 = FUN_00451eb0();
      if (local_6484 != 0) {
        FUN_00517640(local_24,local_20,local_1c,local_18);
        FUN_004988c0();
      }
    }
    else {
      FUN_006cdfb0(local_24,local_20,local_1c,local_18);
    }
  }
  FUN_0044de00(local_6498,*(undefined4 *)(local_6468 + 4));
  local_647c = *(int *)(local_6468 + 4);
  if (local_647c == 0) {
    local_6480 = 0;
  }
  else {
    local_6480 = local_647c + 0x88;
  }
  iVar1 = FUN_0044fcd0();
  if (iVar1 == 0) {
    puVar3 = (undefined8 *)FUN_004b75a0();
    uVar4 = *puVar3;
    uVar5 = puVar3[1];
    FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
    iVar1 = FUN_00498960(uVar4,uVar5);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)FUN_0044f350(local_84,*(undefined4 *)(local_6468 + 4));
      FUN_00517640(*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    }
    uVar6 = 0;
    puVar2 = (undefined4 *)FUN_004b75a0(local_94);
    FUN_004508b0(0x10,local_6498,*(undefined4 *)(local_6468 + 4),*puVar2,puVar2[1],puVar2[2],
                 puVar2[3],uVar6);
    *(undefined4 *)(*(int *)(local_6468 + 4) + 0x85b0) = 0;
    *(undefined4 *)(*(int *)(local_6468 + 4) + 0x85b4) = 0;
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    puVar2 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
    FUN_00517640(*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiParametric[9] */
/* 006ce540  FUN_006ce540  459 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006ce540(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    if (*(int *)(in_ECX + 0x1f8) == 0) {
      *(undefined4 *)(in_ECX + 0xfd30) = 0;
      if (*(int *)(in_ECX + 0xfcec) == 0) {
        *(undefined4 *)(in_ECX + 0xfcec) = 1;
        FUN_004988c0(local_18,param_2,param_3,param_4,param_5);
        uVar1 = 0;
      }
      else {
        if (((*(int *)(*(int *)(in_ECX + 4) + 0x1780) != 0) &&
            (*(int *)(*(int *)(in_ECX + 4) + 0x176c) != 0)) && (param_1 != 0x231d)) {
          FUN_0041df00(*(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c),
                       *(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),&param_2);
        }
        FUN_004988c0(local_28,param_2,param_3,param_4,param_5);
        FUN_004fb9f0();
        FUN_005168b0(0x1456,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
        uVar1 = 1;
      }
    }
    else {
      iVar2 = FUN_0040dbb0(param_1,param_2,param_3,param_4,param_5);
      if (iVar2 != 0) {
        *(undefined4 *)(in_ECX + 0x1f8) = 0;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiParametric[11] */
/* 006ce710  FUN_006ce710  415 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006ce710(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    if (*(int *)(in_ECX + 0x1f8) == 0) {
      FUN_00446aa0(local_14);
      local_8 = 0;
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
      if (iVar2 == 1) {
        uVar1 = FUN_006ce540(0x231d,local_24,local_20,local_1c,local_18);
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
    else {
      iVar2 = FUN_0040deb0(param_1,param_2,param_3,param_4,param_5);
      if (iVar2 != 0) {
        *(undefined4 *)(in_ECX + 0x1f8) = 0;
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




/* vtable slots: CZukeiParametric[8] */
/* 006ce8b0  FUN_006ce8b0  3622 bytes, 2 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006ce8b0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  undefined1 local_1a4 [16];
  undefined1 local_194 [16];
  undefined1 local_184 [16];
  undefined1 local_174 [16];
  undefined1 local_164 [16];
  undefined1 local_154 [16];
  undefined1 local_144 [16];
  undefined1 local_134 [48];
  undefined1 local_104 [16];
  undefined1 local_f4 [16];
  undefined1 local_e4 [16];
  undefined1 local_d4 [16];
  undefined1 local_c4 [16];
  undefined1 local_b4 [16];
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined8 local_24;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ddfb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_00464040();
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = *(int *)(in_ECX + 0xfd18);
  local_34 = *(undefined4 *)(iVar1 + 8);
  uStack_30 = *(undefined4 *)(iVar1 + 0xc);
  local_2c = *(undefined4 *)(iVar1 + 0x10);
  uStack_28 = *(undefined4 *)(iVar1 + 0x14);
  iVar1 = *(int *)(in_ECX + 0xfd18);
  local_44 = *(undefined4 *)(iVar1 + 0x18);
  uStack_40 = *(undefined4 *)(iVar1 + 0x1c);
  local_3c = *(undefined4 *)(iVar1 + 0x20);
  uStack_38 = *(undefined4 *)(iVar1 + 0x24);
  FUN_00408a60();
  FUN_00408a60();
  FUN_00408a60();
  FUN_00408a60();
  iVar1 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078);
  if (iVar1 != 0) {
    iVar1 = *(int *)(in_ECX + 0xfd18);
    FUN_004988c0(local_94,*(undefined4 *)(iVar1 + 0x70),*(undefined4 *)(iVar1 + 0x74),
                 *(undefined4 *)(iVar1 + 0x78),*(undefined4 *)(iVar1 + 0x7c));
    FUN_004988c0(local_154,*(undefined4 *)(iVar1 + 0x80),*(undefined4 *)(iVar1 + 0x84),
                 *(undefined4 *)(iVar1 + 0x88),*(undefined4 *)(iVar1 + 0x8c));
    FUN_004988c0(local_144,*(undefined4 *)(iVar1 + 0xd8),*(undefined4 *)(iVar1 + 0xdc),
                 *(undefined4 *)(iVar1 + 0xe0),*(undefined4 *)(iVar1 + 0xe4));
    FUN_004988c0(local_134,*(undefined4 *)(iVar1 + 0xe8),*(undefined4 *)(iVar1 + 0xec),
                 *(undefined4 *)(iVar1 + 0xf0),*(undefined4 *)(iVar1 + 0xf4));
  }
  iVar1 = FUN_0079d98a(&PTR_s_CDataSolid_009fe094);
  if (iVar1 != 0) {
    FUN_004988c0();
    FUN_004988c0();
  }
  FUN_00465c40(*(undefined8 *)(in_ECX + 0xfc88),*(undefined4 *)(in_ECX + 0x228),
               *(undefined4 *)(in_ECX + 0x22c),*(undefined4 *)(in_ECX + 0x230),
               *(undefined4 *)(in_ECX + 0x234),*(undefined4 *)(in_ECX + 0xfd18),
               *(undefined8 *)(in_ECX + 0xfc90),*(undefined8 *)(in_ECX + 0xfca0));
  FUN_0046d5b0(*(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c),
               *(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
               *(undefined4 *)(in_ECX + 0xfd18),*(undefined8 *)(in_ECX + 0xfcb0));
  FUN_0046bdf0(*(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c),
               *(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
               *(undefined4 *)(in_ECX + 0xfd18),*(undefined4 *)(in_ECX + 0xfc78),
               *(undefined4 *)(in_ECX + 0xfc7c),*(undefined4 *)(in_ECX + 0xfc80),
               *(undefined4 *)(in_ECX + 0xfc84),*(undefined4 *)(in_ECX + 0xfce0),
               *(undefined4 *)(in_ECX + 0xfce4));
  iVar1 = FUN_0079d98a();
  if (iVar1 != 0) {
    iVar1 = FUN_0044f450();
    if (iVar1 != 0) {
      FUN_004988c0(local_104,local_44,uStack_40,local_3c,uStack_38);
    }
    iVar1 = FUN_0044f480();
    if (iVar1 != 0) {
      FUN_004988c0(local_f4,local_34,uStack_30,local_2c,uStack_28);
    }
    iVar1 = FUN_0044f280();
    if (iVar1 != 0) {
      FUN_004988c0(local_e4,local_34,uStack_30,local_2c,uStack_28);
      FUN_004988c0(local_d4,local_44,uStack_40,local_3c,uStack_38);
    }
  }
  iVar1 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078);
  if (iVar1 != 0) {
    FUN_00408a60();
    iVar1 = *(int *)(in_ECX + 0xfd18);
    iVar2 = FUN_0044f450();
    if (iVar2 != 0) {
      fVar3 = (float10)FUN_008f8d00((double)CONCAT44(uStack_38,local_3c) - *(double *)(iVar1 + 0x78)
                                    ,(double)CONCAT44(uStack_40,local_44) -
                                     *(double *)(iVar1 + 0x70));
      fVar4 = (float10)FUN_008f8d00((double)CONCAT44(uStack_38,local_3c) -
                                    (double)CONCAT44(uStack_28,local_2c),
                                    (double)CONCAT44(uStack_40,local_44) -
                                    (double)CONCAT44(uStack_30,local_34));
      *(double *)(iVar1 + 0x408) = *(double *)(iVar1 + 0x408) + ((double)fVar3 - (double)fVar4);
      *(double *)(iVar1 + 0x488) = *(double *)(iVar1 + 0x488) + ((double)fVar3 - (double)fVar4);
      local_24 = (double)CONCAT44(uStack_40,local_44) - *(double *)(iVar1 + 0x80);
      local_1c = (double)CONCAT44(uStack_38,local_3c) - *(double *)(iVar1 + 0x88);
      FUN_004988c0(local_c4,local_44,uStack_40,local_3c,uStack_38);
      FUN_0047e400(0,iVar1,local_64,local_60,local_5c,local_58,local_54,local_50,local_4c,local_48,
                   local_34,uStack_30,local_2c,uStack_28,local_44,uStack_40,local_3c,uStack_38);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
    }
    iVar2 = FUN_0044f480();
    if (iVar2 != 0) {
      fVar3 = (float10)FUN_008f8d00(*(double *)(iVar1 + 0x88) - (double)CONCAT44(uStack_28,local_2c)
                                    ,*(double *)(iVar1 + 0x80) -
                                     (double)CONCAT44(uStack_30,local_34));
      fVar4 = (float10)FUN_008f8d00((double)CONCAT44(uStack_38,local_3c) -
                                    (double)CONCAT44(uStack_28,local_2c),
                                    (double)CONCAT44(uStack_40,local_44) -
                                    (double)CONCAT44(uStack_30,local_34));
      *(double *)(iVar1 + 0x408) = *(double *)(iVar1 + 0x408) + ((double)fVar3 - (double)fVar4);
      *(double *)(iVar1 + 0x488) = *(double *)(iVar1 + 0x488) + ((double)fVar3 - (double)fVar4);
      local_24 = (double)CONCAT44(uStack_30,local_34) - *(double *)(iVar1 + 0x70);
      local_1c = (double)CONCAT44(uStack_28,local_2c) - *(double *)(iVar1 + 0x78);
      FUN_004988c0(local_b4,local_34,uStack_30,local_2c,uStack_28);
      FUN_0047e400(0,iVar1,local_64,local_60,local_5c,local_58,local_54,local_50,local_4c,local_48,
                   local_34,uStack_30,local_2c,uStack_28,local_44,uStack_40,local_3c,uStack_38);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
    }
    iVar2 = FUN_0044f280();
    if (iVar2 != 0) {
      local_24 = (double)CONCAT44(uStack_30,local_34) - *(double *)(iVar1 + 0x70);
      local_1c = (double)CONCAT44(uStack_28,local_2c) - *(double *)(iVar1 + 0x78);
      FUN_004988c0(local_a4,local_34,uStack_30,local_2c,uStack_28);
      FUN_004988c0(local_164,local_44,uStack_40,local_3c,uStack_38);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
      FUN_00498ac0(SUB84(local_24,0),local_24._4_4_,SUB84(local_1c,0),local_1c._4_4_);
    }
  }
  iVar1 = FUN_0079d98a();
  if (((iVar1 != 0) && (iVar1 = *(int *)(in_ECX + 0xfd18), *(byte *)(iVar1 + 0x28) < 100)) &&
     ((*(int *)(iVar1 + 0x88) != 0 ||
      (((*(int *)(iVar1 + 0x8c) != 0 || (*(int *)(iVar1 + 0x90) != 0)) ||
       (*(int *)(iVar1 + 0x94) != 0)))))) {
    if (*(int *)(iVar1 + 0x88) == 0) {
      FUN_004988c0(local_174,local_34,uStack_30,local_2c,uStack_28);
    }
    if (*(int *)(iVar1 + 0x8c) == 0) {
      FUN_004988c0(local_184,local_44,uStack_40,local_3c,uStack_38);
    }
    if (*(int *)(iVar1 + 0x90) == 0) {
      FUN_004988c0(local_194,local_74,local_70,local_6c,local_68);
    }
    if (*(int *)(iVar1 + 0x94) == 0) {
      FUN_004988c0(local_1a4,local_84,local_80,local_7c,local_78);
    }
  }
  local_8 = local_8 & 0xffffff00;
  FUN_004640a0();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiParametric[4] */
/* 006cf6e0  FUN_006cf6e0  531 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006cf6e0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937dcb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if ((*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x85f8)) &&
     (-1 < *(int *)(local_63e8 + 0xfd64))) {
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    DAT_00a0cb54 = *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x108);
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x108) = *(undefined4 *)(local_63e8 + 0xfd64);
    uVar3 = *(undefined4 *)(local_63e8 + 0xfd64);
    FUN_00404c80(uVar3);
    FUN_004fca20();
    FUN_004ae200(uVar3);
  }
  if (*(int *)(*(int *)(local_63e8 + 4) + 0x8564) != 0x8046) {
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8 = CONCAT31(local_8._1_3_,1);
    local_63f4 = FUN_0040c0e0();
    local_63f0 = FUN_00572b10();
    while ((local_63f0 != 0 && (local_63ec = FUN_00572b30(&local_63f0,0), local_63ec != 0))) {
      iVar2 = FUN_0044f450();
      if ((iVar2 != 0) ||
         ((iVar2 = FUN_0044f480(), iVar2 != 0 || (iVar2 = FUN_0044f280(), iVar2 != 0)))) {
        FUN_0040da00(0);
        *(ushort *)(local_63ec + 0x44) = *(ushort *)(local_63ec + 0x44) & 0xfffd;
      }
    }
    FUN_0044c830(local_6408,*(undefined4 *)(local_63e8 + 4));
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiParametric[3] */
/* 006cf900  FUN_006cf900  4289 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006cf900(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  undefined1 *puStack_650c;
  undefined1 *puStack_6508;
  int *piStack_6504;
  undefined **ppuStack_6500;
  undefined **ppuStack_64fc;
  uint uStack_64f8;
  undefined1 *local_64d8;
  double local_64d4;
  double local_64cc;
  double local_64c4;
  double local_64bc;
  double local_64b4;
  double local_64ac;
  undefined4 local_64a4;
  int *local_64a0;
  undefined4 local_649c;
  undefined4 local_6494;
  undefined4 local_6490;
  undefined1 local_648c [20];
  int local_6478;
  int local_6474;
  int local_6470;
  int local_646c;
  int local_6468;
  int *local_6464;
  int local_6460;
  undefined1 local_645c [4];
  int *local_6458;
  double local_6454;
  double local_644c;
  undefined4 local_6444;
  CWaitCursor local_643d;
  int local_643c;
  uint local_6438;
  undefined4 local_6434;
  int *local_6430;
  int *local_642c;
  int local_6428;
  undefined1 local_6424 [25336];
  undefined4 local_12c;
  undefined8 local_a4;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined1 local_54 [32];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093de8f;
  local_10 = ExceptionList;
  uStack_64f8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x208) = 1;
  ppuStack_64fc = (undefined **)0x0;
  ppuStack_6500 = (undefined **)0x6cf955;
  local_6428 = in_ECX;
  local_14 = uStack_64f8;
  FUN_004fb910();
  ppuStack_64fc = (undefined **)0x6cf960;
  CWaitCursor::CWaitCursor(&local_643d);
  local_8 = 0;
  ppuStack_64fc = (undefined **)0x6cf975;
  FUN_004fb9f0();
  ppuStack_64fc = (undefined **)0x0;
  ppuStack_6500 = (undefined **)0x0;
  piStack_6504 = *(int **)(*(int *)(local_6428 + 4) + 0x8f28);
  puStack_6508 = *(undefined1 **)(*(int *)(local_6428 + 4) + 0x8f24);
  puStack_650c = (undefined1 *)0x1456;
  FUN_005168b0();
  local_6430 = (int *)0x0;
  ppuStack_64fc = (undefined **)0x6cf9bb;
  local_6434 = FUN_0040c0e0();
  ppuStack_64fc = (undefined **)0x6cf9cc;
  local_6438 = FUN_0047c770();
  if (5000 < (int)local_6438) {
    ppuStack_64fc = (undefined **)0x128;
    ppuStack_6500 = (undefined **)0x6cf9ec;
    local_6460 = FUN_004121b0();
    local_8._0_1_ = 1;
    if (local_6460 == 0) {
      local_6464 = (int *)0x0;
    }
    else {
      ppuStack_64fc = (undefined **)0x0;
      ppuStack_6500 = (undefined **)0x6cfa0c;
      local_6464 = (int *)FUN_004aa560();
    }
    local_64a0 = local_6464;
    local_8 = (uint)local_8._1_3_ << 8;
    local_6430 = local_6464;
    ppuStack_64fc = (undefined **)0x6cfa3f;
    FUN_00404c80();
    ppuStack_64fc = (undefined **)0x6cfa46;
    ppuStack_64fc = (undefined **)FUN_0046ba20();
    ppuStack_6500 = (undefined **)0x15d;
    piStack_6504 = (int *)0x6cfa62;
    (**(code **)(*local_6430 + 0x164))();
    ppuStack_64fc = (undefined **)0x5;
    ppuStack_6500 = (undefined **)0x6cfa6f;
    FUN_00797f20();
    ppuStack_64fc = (undefined **)((int)local_6438 >> 8);
    ppuStack_6500 = (undefined **)0x0;
    piStack_6504 = (int *)0x6cfa8c;
    FUN_004701c0();
  }
  ppuStack_64fc = *(undefined ***)(local_6428 + 4);
  ppuStack_6500 = (undefined **)0x6cfaa1;
  FUN_0079dea2();
  local_8._0_1_ = 2;
  ppuStack_64fc = (undefined **)0x6cfab0;
  FUN_00446aa0();
  local_8._0_1_ = 3;
  ppuStack_64fc = (undefined **)0x6cfabf;
  FUN_00464040();
  local_8 = CONCAT31(local_8._1_3_,4);
  ppuStack_64fc = (undefined **)0x6cfac8;
  FUN_00404c80();
  ppuStack_64fc = (undefined **)0x6cfacf;
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6428 + 4) + 0x85f8)) {
    ppuStack_64fc = (undefined **)0x6cfaef;
    FUN_00404c80();
    ppuStack_64fc = (undefined **)0x6cfaf6;
    FUN_004fca20();
    ppuStack_64fc = (undefined **)0x6cfb01;
    fVar3 = (float10)FUN_004ae4a0();
    *(double *)(local_6428 + 0xfcc0) = (double)fVar3;
    ppuStack_64fc = (undefined **)0x6cfb12;
    FUN_00404c80();
    ppuStack_64fc = (undefined **)0x6cfb19;
    FUN_004fca20();
    ppuStack_64fc = (undefined **)0x6cfb24;
    fVar3 = (float10)FUN_004ae510();
    *(double *)(local_6428 + 0xfcd0) = (double)fVar3;
    if (*(double *)(local_6428 + 0xfcc0) <= 0.0) {
      local_64ac = -*(double *)(local_6428 + 0xfcc0);
    }
    else {
      local_64ac = *(double *)(local_6428 + 0xfcc0);
    }
    if (local_64ac <= 1e-07) {
      if (*(double *)(local_6428 + 0xfcd0) <= 0.0) {
        local_64b4 = -*(double *)(local_6428 + 0xfcd0);
      }
      else {
        local_64b4 = *(double *)(local_6428 + 0xfcd0);
      }
      if (local_64b4 <= 1e-07) goto LAB_006cfc8c;
    }
    ppuStack_64fc = (undefined **)(local_6428 + 0xfcd0);
    ppuStack_6500 = (undefined **)(local_6428 + 0xfcc0);
    piStack_6504 = (int *)0x0;
    puStack_6508 = (undefined1 *)0x6cfc18;
    FUN_0044cd50();
    *(double *)(local_6428 + 0xfc78) =
         *(double *)(local_6428 + 0x228) + *(double *)(local_6428 + 0xfcc0);
    *(double *)(local_6428 + 0xfc80) =
         *(double *)(local_6428 + 0x230) + *(double *)(local_6428 + 0xfcd0);
    *(undefined4 *)(local_6428 + 0xfce0) = 0;
    *(undefined4 *)(local_6428 + 0xfce4) = 0;
  }
LAB_006cfc8c:
  ppuStack_64fc = *(undefined ***)(local_6428 + 4);
  ppuStack_6500 = (undefined **)local_648c;
  piStack_6504 = (int *)0x6cfca8;
  FUN_0044dd90();
  ppuStack_64fc = *(undefined ***)(local_6428 + 4);
  ppuStack_6500 = (undefined **)local_648c;
  piStack_6504 = (int *)0x6cfcc4;
  FUN_0044de00();
  local_6468 = *(int *)(local_6428 + 4);
  if (local_6468 == 0) {
    local_646c = 0;
  }
  else {
    local_646c = local_6468 + 0x88;
  }
  ppuStack_64fc = (undefined **)local_646c;
  ppuStack_6500 = (undefined **)0x6cfd0b;
  FUN_00454890();
  local_642c = (int *)0x0;
  local_6438 = 0;
  ppuStack_64fc = (undefined **)local_648c;
  ppuStack_6500 = (undefined **)0x6cfd3a;
  FUN_004b5a50();
  ppuStack_64fc = (undefined **)0x6cfd45;
  local_643c = FUN_00572b10();
  while (local_643c != 0) {
    local_6438 = local_6438 + 1;
    if ((local_6430 != (int *)0x0) && ((local_6438 & 0xff) == 0)) {
      ppuStack_64fc = (undefined **)((int)local_6438 >> 8);
      ppuStack_6500 = (undefined **)0x6cfd99;
      FUN_00470190();
    }
    local_6474 = local_643c;
    ppuStack_64fc = (undefined **)0x0;
    ppuStack_6500 = (undefined **)&local_643c;
    piStack_6504 = (int *)0x6cfdb9;
    local_642c = (int *)FUN_00572b30();
    if (local_642c == (int *)0x0) break;
    local_6470 = *(int *)(local_6428 + 4);
    if (local_6470 == 0) {
      local_6478 = 0;
    }
    else {
      local_6478 = local_6470 + 0x88;
    }
    ppuStack_64fc = (undefined **)local_6478;
    ppuStack_6500 = (undefined **)0x6cfe15;
    iVar1 = FUN_0042dcb0();
    if (iVar1 == 0) {
      ppuStack_64fc = (undefined **)0x6cfe56;
      uVar2 = (**(code **)(*local_642c + 0x14))();
      *(undefined4 *)(local_6428 + 0xfd18) = uVar2;
      ppuStack_64fc = (undefined **)0x0;
      ppuStack_6500 = (undefined **)0x6cfe75;
      FUN_0040e410();
      ppuStack_64fc = (undefined **)0x0;
      ppuStack_6500 = (undefined **)0x6cfe88;
      FUN_0040e450();
      ppuStack_64fc = (undefined **)0x0;
      ppuStack_6500 = (undefined **)0x6cfe9b;
      FUN_0040db70();
      ppuStack_64fc = &PTR_s_CDataSen_009fe024;
      ppuStack_6500 = (undefined **)0x6cfeab;
      iVar1 = FUN_0079d98a();
      if (iVar1 != 0) {
        ppuStack_6500 = (undefined **)0x6cfeba;
        iVar1 = FUN_0044f450();
        if (iVar1 != 0) {
          ppuStack_6500 = (undefined **)0x1;
          piStack_6504 = (int *)0x6cfed1;
          FUN_0040e410();
        }
        ppuStack_6500 = (undefined **)0x6cfedc;
        iVar1 = FUN_0044f480();
        if (iVar1 != 0) {
          ppuStack_6500 = (undefined **)0x1;
          piStack_6504 = (int *)0x6cfef3;
          FUN_0040e450();
        }
        ppuStack_6500 = (undefined **)0x6cfefe;
        iVar1 = FUN_0044f280();
        if (iVar1 != 0) {
          ppuStack_6500 = (undefined **)0x1;
          piStack_6504 = (int *)0x6cff15;
          FUN_0040db70();
        }
      }
      ppuStack_6500 = &PTR_s_CDataSunpou_009fe078;
      piStack_6504 = (int *)0x6cff25;
      iVar1 = FUN_0079d98a();
      if (iVar1 != 0) {
        ppuStack_64fc = (undefined **)0x6cff34;
        iVar1 = FUN_0044f450();
        if (iVar1 != 0) {
          ppuStack_64fc = (undefined **)0x1;
          ppuStack_6500 = (undefined **)0x6cff4b;
          FUN_0040e410();
        }
        ppuStack_64fc = (undefined **)0x6cff56;
        iVar1 = FUN_0044f480();
        if (iVar1 != 0) {
          ppuStack_64fc = (undefined **)0x1;
          ppuStack_6500 = (undefined **)0x6cff6d;
          FUN_0040e450();
        }
        ppuStack_64fc = (undefined **)0x6cff78;
        iVar1 = FUN_0044f280();
        if (iVar1 != 0) {
          ppuStack_64fc = (undefined **)0x1;
          ppuStack_6500 = (undefined **)0x6cff8f;
          FUN_0040db70();
        }
      }
      ppuStack_64fc = (undefined **)0x6cff9a;
      FUN_006ce8b0();
      if (local_642c[1] != 0) {
        *(int *)(*(int *)(local_6428 + 0xfd18) + 4) = local_642c[1];
      }
      ppuStack_64fc = *(undefined ***)(local_6428 + 0xfd18);
      ppuStack_6500 = (undefined **)0x6cffd6;
      FUN_00570960();
    }
    else {
      ppuStack_64fc = (undefined **)0x0;
      ppuStack_6500 = (undefined **)local_642c;
      piStack_6504 = *(int **)(local_6428 + 4);
      puStack_6508 = local_648c;
      puStack_650c = (undefined1 *)0x6cfe3e;
      FUN_0044a120();
    }
  }
  ppuStack_64fc = (undefined **)0x6cffef;
  FUN_004b7110();
  local_12c = 0;
  if (local_6430 != (int *)0x0) {
    ppuStack_64fc = (undefined **)0x6d0015;
    (**(code **)(*local_6430 + 0x60))();
    local_6458 = local_6430;
    if (local_6430 == (int *)0x0) {
      local_649c = 0;
    }
    else {
      ppuStack_64fc = (undefined **)0x1;
      ppuStack_6500 = (undefined **)0x6d003f;
      local_649c = (**(code **)(*local_6430 + 4))();
    }
    local_6430 = (int *)0x0;
  }
  local_64a4 = DAT_00a0cae8;
  DAT_00a0cae8 = 0x32;
  local_12c = 0;
  local_9c = 0x487087c797fde41d;
  local_a4 = 0x487087c797fde41d;
  local_8c = 0xc87087c797fde41d;
  local_94 = 0xc87087c797fde41d;
  ppuStack_64fc = (undefined **)0x1;
  ppuStack_6500 = (undefined **)local_648c;
  piStack_6504 = (int *)local_6424;
  puStack_6508 = *(undefined1 **)(local_6428 + 4);
  puStack_650c = (undefined1 *)0x0;
  FUN_00478480();
  ppuStack_64fc = (undefined **)0x6d00ec;
  FUN_00574f10();
  if (DAT_00a0cae8 != 0) {
    ppuStack_64fc = *(undefined ***)(local_6428 + 4);
    ppuStack_6500 = (undefined **)local_648c;
    piStack_6504 = (int *)0x6d0111;
    FUN_0044f4f0();
  }
  DAT_00a0cae8 = local_64a4;
  ppuStack_64fc = (undefined **)0x6d012b;
  FUN_004fb9f0();
  ppuStack_64fc = (undefined **)0x6d0136;
  local_643c = FUN_00572c70();
  while (local_643c != 0) {
    local_6474 = local_643c;
    ppuStack_64fc = (undefined **)0x0;
    ppuStack_6500 = (undefined **)&local_643c;
    piStack_6504 = (int *)0x6d0169;
    local_642c = (int *)FUN_00572cd0();
    if (local_642c == (int *)0x0) break;
    ppuStack_64fc = (undefined **)local_6474;
    ppuStack_6500 = (undefined **)0x6d018c;
    FUN_00574fd0();
    ppuStack_64fc = (undefined **)0x0;
    ppuStack_6500 = (undefined **)0x1;
    piStack_6504 = local_642c;
    puStack_6508 = *(undefined1 **)(local_6428 + 4);
    puStack_650c = local_648c;
    FUN_00447670();
    ppuStack_64fc = (undefined **)0x1;
    ppuStack_6500 = (undefined **)0x1;
    piStack_6504 = local_642c;
    puStack_6508 = *(undefined1 **)(local_6428 + 4);
    puStack_650c = (undefined1 *)0x2;
    FUN_00447b90(local_648c);
    local_12c = 1;
  }
  local_12c = 0;
  *(double *)(local_6428 + 0xfd20) =
       *(double *)(local_6428 + 0xfc78) - *(double *)(local_6428 + 0x228);
  *(double *)(local_6428 + 0xfd28) =
       *(double *)(local_6428 + 0xfc80) - *(double *)(local_6428 + 0x230);
  if (*(int *)(local_6428 + 0xfd30) < 1) {
    *(undefined8 *)(local_6428 + 0xfd40) = *(undefined8 *)(local_6428 + 0xfd20);
    *(undefined8 *)(local_6428 + 0xfd48) = *(undefined8 *)(local_6428 + 0xfd28);
    *(undefined8 *)(local_6428 + 0xfd50) = *(undefined8 *)(local_6428 + 0xfc90);
    *(undefined8 *)(local_6428 + 0xfd58) = *(undefined8 *)(local_6428 + 0xfca0);
  }
  if (*(int *)(local_6428 + 0xfd60) < 0) {
    *(undefined4 *)(local_6428 + 0xfd60) = 0;
  }
  if (*(int *)(local_6428 + 0xfd60) < 0xfa1) {
    puStack_6508 = *(undefined1 **)(local_6428 + 0x228);
    piStack_6504 = *(int **)(local_6428 + 0x22c);
    ppuStack_6500 = *(undefined ***)(local_6428 + 0x230);
    ppuStack_64fc = *(undefined ***)(local_6428 + 0x234);
    puStack_650c = local_34;
    FUN_004988c0();
  }
  *(int *)(local_6428 + 0xfd60) = *(int *)(local_6428 + 0xfd60) + 1;
  puStack_6508 = *(undefined1 **)(local_6428 + 0xfc78);
  piStack_6504 = *(int **)(local_6428 + 0xfc7c);
  ppuStack_6500 = *(undefined ***)(local_6428 + 0xfc80);
  ppuStack_64fc = *(undefined ***)(local_6428 + 0xfc84);
  puStack_650c = local_24;
  FUN_004988c0();
  puStack_6508 = *(undefined1 **)(local_6428 + 0x228);
  piStack_6504 = *(int **)(local_6428 + 0x22c);
  ppuStack_6500 = *(undefined ***)(local_6428 + 0x230);
  ppuStack_64fc = *(undefined ***)(local_6428 + 0x234);
  puStack_650c = (undefined1 *)0x6d03d0;
  FUN_00517640();
  if (*(int *)(local_6428 + 0xfd60) < 0xfa1) {
    puStack_6508 = *(undefined1 **)(local_6428 + 0x228);
    piStack_6504 = *(int **)(local_6428 + 0x22c);
    ppuStack_6500 = *(undefined ***)(local_6428 + 0x230);
    ppuStack_64fc = *(undefined ***)(local_6428 + 0x234);
    puStack_650c = local_54;
    FUN_004988c0();
  }
  if (*(int *)(local_6428 + 0xfd30) < 1) {
    *(undefined4 *)(local_6428 + 0xfd30) = 1;
  }
  ppuStack_64fc = (undefined **)0x6d0452;
  FUN_00404c80();
  ppuStack_64fc = (undefined **)0x6d0459;
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6428 + 4) + 0x85f8)) {
    ppuStack_6500 = (undefined **)0x0;
    ppuStack_64fc = (undefined **)0x0;
    puStack_6508 = (undefined1 *)0x0;
    piStack_6504 = (int *)0x0;
    puStack_650c = (undefined1 *)0x6d048b;
    FUN_00404c80();
    puStack_650c = (undefined1 *)0x6d0492;
    FUN_004fca20();
    puStack_650c = (undefined1 *)0x6d049d;
    FUN_004ae320();
    ppuStack_64fc = (undefined **)0x6d04a2;
    FUN_00404c80();
    ppuStack_64fc = (undefined **)0x6d04a9;
    FUN_004fca20();
    ppuStack_64fc = (undefined **)0x6d04ba;
    FUN_00797df8();
  }
  ppuStack_64fc = *(undefined ***)(local_6428 + 4);
  ppuStack_6500 = (undefined **)local_648c;
  piStack_6504 = (int *)0x6d04d6;
  FUN_0044dd90();
  puStack_6508 = *(undefined1 **)(local_6428 + 0x228);
  piStack_6504 = *(int **)(local_6428 + 0x22c);
  ppuStack_6500 = *(undefined ***)(local_6428 + 0x230);
  ppuStack_64fc = *(undefined ***)(local_6428 + 0x234);
  puStack_650c = (undefined1 *)0x54b07582;
  FUN_00408a30(0x54b075823b6c498a,0x3b6c498a);
  puStack_650c = (undefined1 *)0x6d052b;
  iVar1 = FUN_004989a0();
  if (iVar1 != 0) {
    ppuStack_64fc = (undefined **)0x0;
    puStack_650c = *(undefined1 **)(local_6428 + 0x228);
    puStack_6508 = *(undefined1 **)(local_6428 + 0x22c);
    piStack_6504 = *(int **)(local_6428 + 0x230);
    ppuStack_6500 = *(undefined ***)(local_6428 + 0x234);
    FUN_004508b0(0x10,local_648c,*(undefined4 *)(local_6428 + 4));
  }
  *(undefined4 *)(local_6428 + 0x210) = 1;
  *(undefined4 *)(local_6428 + 0x21c) = *(undefined4 *)(local_6428 + 0x214);
  *(undefined4 *)(local_6428 + 0x220) = *(undefined4 *)(local_6428 + 0x218);
  *(undefined4 *)(local_6428 + 0x208) = 0;
  *(undefined4 *)(local_6428 + 0x204) = 0xffffffff;
  local_6454 = *(double *)(local_6428 + 0xfd20) *
               *(double *)
                (*(int *)(local_6428 + 4) + 0x2578 + *(int *)(*(int *)(local_6428 + 4) + 0x256c) * 8
                );
  local_644c = *(double *)(local_6428 + 0xfd28) *
               *(double *)
                (*(int *)(local_6428 + 4) + 0x2578 + *(int *)(*(int *)(local_6428 + 4) + 0x256c) * 8
                );
  if (DAT_00a0d62c != 0) {
    local_6454 = local_6454 / DAT_00a0d630;
    local_644c = local_644c / DAT_00a0d630;
  }
  ppuStack_64fc = (undefined **)&local_644c;
  ppuStack_6500 = (undefined **)&local_6454;
  piStack_6504 = (int *)0x1;
  puStack_6508 = (undefined1 *)0x6d068c;
  FUN_0044cd50();
  if ((*(int *)(local_6428 + 0xfce0) == 0) || (*(int *)(local_6428 + 0xfce4) == 0)) {
    if (*(int *)(local_6428 + 0xfce0) != 0) {
      local_644c = 0.0;
    }
    if (*(int *)(local_6428 + 0xfce4) != 0) {
      local_6454 = 0.0;
    }
  }
  else {
    if (local_6454 <= 0.0) {
      local_64bc = -local_6454;
    }
    else {
      local_64bc = local_6454;
    }
    if (local_644c <= 0.0) {
      local_64c4 = -local_644c;
    }
    else {
      local_64c4 = local_644c;
    }
    if (local_64bc <= local_64c4) {
      local_6454 = 0.0;
    }
    else {
      local_644c = 0.0;
    }
  }
  if (local_6454 <= 0.0) {
    local_64cc = -local_6454;
  }
  else {
    local_64cc = local_6454;
  }
  if (local_64cc < 1e-07) {
    local_6454 = 0.0;
  }
  if (local_644c <= 0.0) {
    local_64d4 = -local_644c;
  }
  else {
    local_64d4 = local_644c;
  }
  if (local_64d4 < 1e-07) {
    local_644c = 0.0;
  }
  ppuStack_64fc = (undefined **)&DAT_00956338;
  ppuStack_6500 = (undefined **)0x6d0848;
  CStringT<>();
  local_8._0_1_ = 5;
  ppuStack_64fc = (undefined **)&DAT_00956338;
  ppuStack_6500 = (undefined **)0x6d085c;
  CStringT<>();
  local_8._0_1_ = 6;
  if (DAT_00a0d62c != 0) {
    ppuStack_64fc = (undefined **)&DAT_00a0d644;
    ppuStack_6500 = (undefined **)0x6d0879;
    FUN_00404860();
  }
  ppuStack_64fc = (undefined **)local_6444;
  piStack_6504 = SUB84(local_644c,0);
  ppuStack_6500 = (undefined **)((ulonglong)local_644c >> 0x20);
  puStack_650c = SUB84(local_6454,0);
  puStack_6508 = (undefined1 *)((ulonglong)local_6454 >> 0x20);
  FUN_004059f0();
  ppuStack_64fc = (undefined **)0x177a;
  ppuStack_6500 = (undefined **)0x6d08c4;
  ppuStack_64fc = (undefined **)FUN_005977f0();
  local_8._0_1_ = 7;
  ppuStack_6500 = (undefined **)0x6d08ec;
  local_6494 = ppuStack_64fc;
  local_6490 = ppuStack_64fc;
  FUN_00404860();
  local_8._0_1_ = 6;
  ppuStack_64fc = (undefined **)0x6d08fb;
  FUN_00404770();
  ppuStack_64fc = (undefined **)local_645c;
  ppuStack_6500 = (undefined **)0x6d090d;
  FUN_00404950();
  ppuStack_64fc = (undefined **)0x0;
  ppuStack_6500 = (undefined **)0x0;
  piStack_6504 = *(int **)(*(int *)(local_6428 + 4) + 0x8f28);
  puStack_650c = *(undefined1 **)(*(int *)(local_6428 + 4) + 0x8f24);
  local_64d8 = (undefined1 *)&puStack_650c;
  puStack_6508 = puStack_650c;
  FUN_00403dd0(&local_6444);
  FUN_00516ac0();
  local_8._0_1_ = 5;
  ppuStack_64fc = (undefined **)0x6d095a;
  FUN_00404540();
  local_8._0_1_ = 4;
  ppuStack_64fc = (undefined **)0x6d0969;
  FUN_00404540();
  local_8._0_1_ = 3;
  ppuStack_64fc = (undefined **)0x6d0978;
  FUN_004640a0();
  local_8._0_1_ = 2;
  ppuStack_64fc = (undefined **)0x6d0987;
  FUN_00447100();
  local_8 = (uint)local_8._1_3_ << 8;
  ppuStack_64fc = (undefined **)0x6d0996;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  ppuStack_64fc = (undefined **)0x6d09a8;
  FUN_00408b00();
  ExceptionList = local_10;
  return;
}



