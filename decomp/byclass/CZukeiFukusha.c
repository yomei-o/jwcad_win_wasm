/* CZukeiFukusha -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiFukusha[1] */
/* 0064c680  FUN_0064c680  68 bytes, 0 callers */

undefined4 FUN_0064c680(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0064c660();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xfdc0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiFukusha[6] */
/* 0064d290  FUN_0064d290  5395 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0064e1f3) */

void FUN_0064d290(double *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  double local_6a9c;
  double local_6a94;
  double local_6a8c;
  double local_6a84;
  int local_6a5c;
  int local_6a58;
  int local_6a50;
  uint local_6a48;
  undefined1 local_6a44 [20];
  double local_6a30;
  undefined4 local_6a28;
  int *local_6a24;
  int local_6a20;
  undefined1 local_6a1c [25616];
  undefined1 local_60c [32];
  undefined1 local_5ec [32];
  double local_5cc;
  double local_5c4;
  undefined1 local_3b8 [208];
  undefined1 local_2e8 [208];
  undefined2 local_218 [258];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093879b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  puVar2 = (undefined4 *)FUN_004b6d60();
  uVar8 = puVar2[1];
  *(undefined4 *)(local_6a20 + 0x214) = *puVar2;
  *(undefined4 *)(local_6a20 + 0x218) = uVar8;
  *(undefined4 *)(local_6a20 + 0xfdb8) = 0;
  if (*(int *)(local_6a20 + 0x208) != 0) {
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(local_6a20 + 0x20c) != 0) {
    *(undefined4 *)(local_6a20 + 0x20c) = 0;
    ExceptionList = local_10;
    return;
  }
  local_6a28 = FUN_0040c0e0(uVar1);
  iVar3 = FUN_00572b10();
  if ((iVar3 == 0) && (*(int *)(local_6a20 + 0x1fc) == 0)) {
    *(undefined4 *)(local_6a20 + 0x1fc) = 1;
    DAT_00a0d618 = 1;
    FUN_0064c6d0();
  }
  *(undefined4 *)(local_6a20 + 0xd8) = 0;
  if (*(int *)(local_6a20 + 0x1fc) != 0) {
    FUN_006f7cc0(param_1);
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(local_6a20 + 0x1f8) != 0) {
    *(undefined4 *)(local_6a20 + 0x204) = 0;
    FUN_0040ac80(param_1);
    ExceptionList = local_10;
    return;
  }
  puVar2 = (undefined4 *)FUN_004b75a0(local_60c);
  uVar8 = *puVar2;
  uVar6 = *(undefined8 *)(puVar2 + 1);
  uVar7 = puVar2[3];
  FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
  iVar3 = FUN_004989a0(uVar8,uVar6,uVar7);
  if (iVar3 != 0) {
    FUN_004b75a0(local_5ec);
    FUN_004988c0();
    FUN_004988c0();
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6a20 + 4));
  local_8._0_1_ = 1;
  if (*(int *)(local_6a20 + 0xfd48) != 0) {
    if (*(int *)(local_6a20 + 0xfd0c) != DAT_00a0cb28) {
      *(int *)(local_6a20 + 0xfd0c) = DAT_00a0cb28;
      *(undefined4 *)(local_6a20 + 0xfdb0) = 0xffffffff;
      *(undefined4 *)(*(int *)(local_6a20 + 4) + 0x8560) = 0;
    }
    FUN_005977f0(0x161a);
    FUN_00404920();
    FUN_005cf710();
    FUN_00404770();
    FUN_004efbb0(0x14e1,local_3b8,0);
    FUN_0044dd90();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(local_6a20 + 0xfd18) != 0) {
    if (*(int *)(local_6a20 + 0xfd18) == 1) {
      FUN_004efbb0(0x1523,0,0);
      FUN_0044dd90();
      *(undefined4 *)(local_6a20 + 0x204) = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    if (*(int *)(local_6a20 + 0xfd18) == 3) {
      FUN_004efbb0(0x1524,0,0);
      FUN_0044dd90();
      *(undefined4 *)(local_6a20 + 0x204) = 0;
    }
  }
  if (*(int *)(local_6a20 + 0xfd40) != 0) {
    if (*(int *)(local_6a20 + 0xfd40) == 1) {
      FUN_004efbb0(0x15ff,0,0);
      FUN_0044dd90();
      *(undefined4 *)(local_6a20 + 0x204) = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    if (*(int *)(local_6a20 + 0xfd40) == 3) {
      FUN_005977f0(0x27ba);
      FUN_00404920();
      FUN_005cf710();
      FUN_00404770();
      FUN_004efbb0(0x2786,local_2e8,0);
      FUN_0044dd90();
      *(undefined4 *)(local_6a20 + 0x204) = 0;
    }
  }
  *(undefined4 *)(local_6a20 + 0xfd14) = 1;
  *(double *)(local_6a20 + 0xfca8) =
       (*(double *)(*(int *)(local_6a20 + 4) + 0x17c0) / 180.0) * 3.141592653589793;
  *(undefined8 *)(local_6a20 + 0xfcb0) = 0x3ff0000000000000;
  *(undefined8 *)(local_6a20 + 0xfcc0) = 0x3ff0000000000000;
  *(undefined8 *)(local_6a20 + 0xfcd0) = 0;
  *(undefined8 *)(local_6a20 + 0xfce0) = 0;
  *(undefined8 *)(local_6a20 + 0xfcf0) = 0;
  *(undefined4 *)(local_6a20 + 0xfd00) = 0;
  *(undefined4 *)(local_6a20 + 0xfd04) = 0;
  local_6a50 = 0;
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) == *(int *)(*(int *)(local_6a20 + 4) + 0x85f8)) {
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    if (*(int *)(local_6a20 + 0xfd08) != *(int *)(*(int *)(iVar3 + 0x1a0) + 0xc70)) {
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      *(undefined4 *)(local_6a20 + 0xfd08) = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xc70);
      local_6a48 = (uint)(*(int *)(local_6a20 + 0xfd08) == 0);
      *(uint *)(local_6a20 + 0xfdb4) = local_6a48;
      *(undefined4 *)(local_6a20 + 0xfdb0) = 0xffffffff;
      *(undefined4 *)(*(int *)(local_6a20 + 4) + 0x8560) = 0;
    }
    if (*(int *)(local_6a20 + 0xfd0c) != DAT_00a0cb28) {
      *(int *)(local_6a20 + 0xfd0c) = DAT_00a0cb28;
      *(undefined4 *)(local_6a20 + 0xfdb0) = 0xffffffff;
      *(undefined4 *)(*(int *)(local_6a20 + 4) + 0x8560) = 0;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae430();
    *(double *)(local_6a20 + 0xfcb0) = (double)fVar5;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae460();
    *(double *)(local_6a20 + 0xfcc0) = (double)fVar5;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae590();
    *(double *)(local_6a20 + 0xfcd0) = (double)fVar5;
    DAT_00a0cb38 = *(undefined8 *)(local_6a20 + 0xfcb0);
    DAT_00a0cb40 = *(undefined8 *)(local_6a20 + 0xfcc0);
    DAT_00a0cb48 = (*(double *)(local_6a20 + 0xfcd0) * 180.0) / 3.141592653589793;
    if (*(int *)(local_6a20 + 0xfd40) != 0) {
      *(undefined8 *)(local_6a20 + 0xfcd0) = 0;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae4a0();
    *(double *)(local_6a20 + 0xfce0) = (double)fVar5;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae510();
    *(double *)(local_6a20 + 0xfcf0) = (double)fVar5;
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined4 *)(local_6a20 + 0xfd00) = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xc78);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined4 *)(local_6a20 + 0xfd04) = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xc7c);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined4 *)(local_6a20 + 0xfd08) = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xc70);
    iVar3 = FUN_00573cb0();
    if (iVar3 != 0) {
      uVar8 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar8);
      uVar8 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar8);
    }
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    local_6a50 = *(int *)(*(int *)(iVar3 + 0x1a0) + 0xc0);
  }
  iVar3 = FUN_00572b10();
  if (iVar3 == 0) {
    *(undefined4 *)(local_6a20 + 0xfd14) = 0;
    *(undefined4 *)(local_6a20 + 0x204) = 0;
  }
  local_6a24 = (int *)0x0;
  if (*(int *)(local_6a20 + 0xfd14) == 0) {
    FUN_0044dd90();
    *(undefined4 *)(local_6a20 + 0x204) = 0;
    FUN_004efbb0(0x14c2,0,0);
  }
  if (*(int *)(local_6a20 + 0xfd14) != 1) goto LAB_0064e777;
  if (*(int *)(local_6a20 + 0xfd18) == 3) {
    *(undefined4 *)(local_6a20 + 0x204) = 0xffffffff;
    FUN_004988c0();
    FUN_0064f350();
  }
  else if (*(int *)(local_6a20 + 0xfd40) == 3) {
    *(undefined4 *)(local_6a20 + 0x204) = 0xffffffff;
    FUN_004988c0();
    FUN_0064f900();
  }
  else {
    if (*(double *)(local_6a20 + 0xfce0) <= 0.0) {
      local_6a94 = -*(double *)(local_6a20 + 0xfce0);
    }
    else {
      local_6a94 = *(double *)(local_6a20 + 0xfce0);
    }
    if (local_6a94 <= 1e-07) {
      if (*(double *)(local_6a20 + 0xfcf0) <= 0.0) {
        local_6a8c = -*(double *)(local_6a20 + 0xfcf0);
      }
      else {
        local_6a8c = *(double *)(local_6a20 + 0xfcf0);
      }
      if (local_6a8c <= 1e-07) {
        if (*(int *)(local_6a20 + 0x204) != *(int *)(local_6a20 + 0xfd14)) {
          *(undefined4 *)(local_6a20 + 0x204) = *(undefined4 *)(local_6a20 + 0xfd14);
          DAT_00a0b3b8 = 0;
        }
        if ((*(int *)(*(int *)(local_6a20 + 4) + 0x1780) != 0) &&
           (*(int *)(*(int *)(local_6a20 + 4) + 0x176c) != 0)) {
          FUN_0041df00();
        }
        FUN_004988c0();
        local_5cc = *param_1;
        local_5c4 = param_1[1];
        FUN_005f89c0();
        FUN_005f92e0(&local_5cc);
        if ((*(int *)(local_6a20 + 0xfd00) == 0) || (*(int *)(local_6a20 + 0xfd04) == 0)) {
          if (*(int *)(local_6a20 + 0xfd00) != 0) {
            local_5c4 = 0.0;
          }
          if (*(int *)(local_6a20 + 0xfd04) != 0) {
            local_5cc = 0.0;
          }
        }
        else {
          if (local_5cc <= 0.0) {
            local_6a9c = -local_5cc;
          }
          else {
            local_6a9c = local_5cc;
          }
          if (local_5c4 <= 0.0) {
            local_6a84 = -local_5c4;
          }
          else {
            local_6a84 = local_5c4;
          }
          if (local_6a9c <= local_6a84) {
            local_5cc = 0.0;
          }
          else {
            local_5c4 = 0.0;
          }
        }
        local_218[0] = 0;
        if (((*(double *)(local_6a20 + 0xfcb0) == 0.0) && (*(double *)(local_6a20 + 0xfcc0) == 0.0))
           && (*(double *)(local_6a20 + 0xfcd0) == 0.0)) {
          uVar8 = 0x62;
          FUN_005977f0();
          uVar8 = FUN_00404920(uVar8);
          FUN_0064bbe0(local_218,uVar8);
          FUN_00404770();
        }
        FUN_00408850();
        local_6a30 = local_5cc *
                     *(double *)
                      (*(int *)(local_6a20 + 4) + 0x2578 +
                      *(int *)(*(int *)(local_6a20 + 4) + 0x256c) * 8);
        if (DAT_00a0d62c != 0) {
          local_6a30 = local_6a30 / DAT_00a0d630;
        }
        FUN_0045a220();
        FUN_00408850();
        FUN_00408850();
        local_6a30 = local_5c4 *
                     *(double *)
                      (*(int *)(local_6a20 + 4) + 0x2578 +
                      *(int *)(*(int *)(local_6a20 + 4) + 0x256c) * 8);
        if (DAT_00a0d62c != 0) {
          local_6a30 = local_6a30 / DAT_00a0d630;
        }
        FUN_0045a220();
        FUN_00408850();
        FUN_00408850();
        if (DAT_00a0d62c != 0) {
          FUN_00404920();
          FUN_00408850();
        }
        if (*(int *)(local_6a20 + 0xfd08) == 0) {
          FUN_004efbb0(0x14bf,local_218,1);
        }
        else {
          FUN_004efbb0(0x14bb,local_218,1);
        }
        goto LAB_0064e44f;
      }
    }
    *(undefined4 *)(local_6a20 + 0x204) = 0xffffffff;
    FUN_004efbb0(0x1522,0,0);
    FUN_0044cd50(0,local_6a20 + 0xfce0,local_6a20 + 0xfcf0);
    *(double *)(local_6a20 + 0xfc78) =
         *(double *)(local_6a20 + 0x228) + *(double *)(local_6a20 + 0xfce0);
    *(double *)(local_6a20 + 0xfc80) =
         *(double *)(local_6a20 + 0x230) + *(double *)(local_6a20 + 0xfcf0);
    *(undefined4 *)(local_6a20 + 0xfd00) = 0;
    *(undefined4 *)(local_6a20 + 0xfd04) = 0;
    *(undefined8 *)(local_6a20 + 0xfcb8) = *(undefined8 *)(local_6a20 + 0xfcb0);
    *(undefined8 *)(local_6a20 + 0xfcc8) = *(undefined8 *)(local_6a20 + 0xfcc0);
    *(undefined8 *)(local_6a20 + 0xfcd8) = *(undefined8 *)(local_6a20 + 0xfcd0);
    *(undefined8 *)(local_6a20 + 0xfce8) = *(undefined8 *)(local_6a20 + 0xfce0);
    *(undefined8 *)(local_6a20 + 0xfcf8) = *(undefined8 *)(local_6a20 + 0xfcf0);
  }
LAB_0064e44f:
  FUN_0044dd90();
  if (DAT_00a0b3b8 == 0) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  if ((local_6a50 != 0) && (0 < *(int *)(local_6a20 + 0xfdb0))) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  FUN_004044d0();
  if (*(int *)(local_6a20 + 0x210) != 0) {
    if (*(int *)(local_6a20 + 0x21c) == *(int *)(local_6a20 + 0x214) ||
        *(int *)(local_6a20 + 0x21c) - *(int *)(local_6a20 + 0x214) < 0) {
      local_6a5c = -(*(int *)(local_6a20 + 0x21c) - *(int *)(local_6a20 + 0x214));
    }
    else {
      local_6a5c = *(int *)(local_6a20 + 0x21c) - *(int *)(local_6a20 + 0x214);
    }
    if (local_6a5c < 3) {
      if (*(int *)(local_6a20 + 0x220) == *(int *)(local_6a20 + 0x218) ||
          *(int *)(local_6a20 + 0x220) - *(int *)(local_6a20 + 0x218) < 0) {
        local_6a58 = -(*(int *)(local_6a20 + 0x220) - *(int *)(local_6a20 + 0x218));
      }
      else {
        local_6a58 = *(int *)(local_6a20 + 0x220) - *(int *)(local_6a20 + 0x218);
      }
      if (local_6a58 < 3) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
    }
    *(undefined4 *)(local_6a20 + 0x210) = 0;
  }
  iVar3 = FUN_00572b10();
  while (((iVar3 != 0 && (local_6a24 = (int *)FUN_00572b30(), local_6a24 != (int *)0x0)) &&
         (iVar4 = FUN_004fcab0(), iVar4 == 0))) {
    if (((*(int *)(*(int *)(local_6a20 + 4) + 0x9050) == 0) &&
        (*(int *)(*(int *)(local_6a20 + 4) + 0x9054) == 0)) ||
       ((iVar4 = FUN_0044f450(), iVar4 == 0 &&
        ((iVar4 = FUN_0044f480(), iVar4 == 0 && (iVar4 = FUN_0044f280(), iVar4 == 0)))))) {
      uVar8 = (**(code **)(*local_6a24 + 0x14))();
      *(undefined4 *)(local_6a20 + 0xfd44) = uVar8;
      FUN_00653e10();
      FUN_00447cf0(local_6a44,*(undefined4 *)(local_6a20 + 4),*(undefined4 *)(local_6a20 + 0xfd44),1
                  );
    }
    else if (*(int *)(local_6a20 + 0xfd08) != 0) {
      *(int **)(local_6a20 + 0xfd44) = local_6a24;
      FUN_0064cb60(local_6a1c,local_6a44,1);
    }
  }
LAB_0064e777:
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusha[16] */
/* 0064e7c0  FUN_0064e7c0  2200 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0064e7c0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 local_6470 [20];
  int local_645c;
  int local_6458;
  undefined4 local_6454;
  undefined4 local_6450;
  int local_644c;
  int local_6448;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009387eb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6450 = FUN_0040c0e0(local_14);
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2();
  local_8._0_1_ = 1;
  if (*(int *)(local_6448 + 0x1fc) == 0) {
    if (((*(int *)(local_6448 + 0xfd48) == 1) || (0 < *(int *)(local_6448 + 0xfd18))) ||
       (0 < *(int *)(local_6448 + 0xfd40))) {
      *(undefined4 *)(local_6448 + 0xfd48) = 0;
      if (*(int *)(local_6448 + 0xfd18) < 2) {
        if (*(int *)(local_6448 + 0xfd40) < 2) {
          *(undefined4 *)(local_6448 + 0xfd18) = 0;
          *(undefined4 *)(local_6448 + 0xfd40) = 0;
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6448 + 4) + 0x85f8)) {
            lVar4 = (ulonglong)*(uint *)(local_6448 + 0xfdb4) << 0x20;
            FUN_00404c80(0,*(uint *)(local_6448 + 0xfdb4));
            FUN_004fca20();
            FUN_004accf0(lVar4);
          }
        }
        else {
          *(int *)(local_6448 + 0xfd40) = *(int *)(local_6448 + 0xfd40) + -1;
        }
      }
      else {
        *(int *)(local_6448 + 0xfd18) = *(int *)(local_6448 + 0xfd18) + -1;
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 1;
    }
    else if (*(int *)(local_6448 + 0xfdb0) < 1) {
      if (*(int *)(local_6448 + 0xfdb0) < 1) {
        *(undefined4 *)(*(int *)(local_6448 + 4) + 0x8560) = 0;
        *(undefined4 *)(local_6448 + 0xfdb0) = 0xffffffff;
        *(undefined4 *)(local_6448 + 0x1fc) = 1;
        DAT_00a0d618 = 1;
        FUN_0064c6d0();
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if ((*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6448 + 4) + 0x8610)) &&
           (iVar1 = FUN_00572b10(), iVar1 != 0)) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_005c8120();
        }
        FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
        FUN_004988c0();
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 1;
      }
      else {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
    }
    else {
      FUN_0044dd90(local_6470,*(undefined4 *)(local_6448 + 4));
      FUN_0044de00(local_6470,*(undefined4 *)(local_6448 + 4));
      local_6454 = 0;
      if ((*(int *)(local_6448 + 0xfd08) == 0) || (*(int *)(local_6448 + 0xfd0c) == 1)) {
        FUN_0044c830(local_6470,*(undefined4 *)(local_6448 + 4));
        local_6454 = 1;
      }
      FUN_00458a80();
      if ((*(int *)(local_6448 + 0xfd08) == 1) && (*(int *)(local_6448 + 0xfd0c) == 1)) {
        local_645c = 0;
        local_6458 = FUN_00572030();
        while ((local_6458 != 0 && (local_644c = FUN_00572100(), local_644c != 0))) {
          iVar1 = FUN_004423b0();
          if (iVar1 != 0) {
            FUN_00447b90(local_6470,2,*(undefined4 *)(local_6448 + 4),local_644c,1,1);
            local_645c = 1;
            FUN_00615500();
            *(ushort *)(local_644c + 0x44) = *(ushort *)(local_644c + 0x44) | 2;
          }
        }
        if (local_645c == 0) {
          FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
          FUN_004988c0();
        }
      }
      *(undefined4 *)(*(int *)(local_6448 + 4) + 0x8560) = 0;
      *(int *)(local_6448 + 0xfdb0) = *(int *)(local_6448 + 0xfdb0) + -1;
      if (*(int *)(local_6448 + 0xfdb0) < 0xfa1) {
        FUN_004988c0();
        FUN_00517640(*(undefined4 *)(local_6448 + 0x228),*(undefined4 *)(local_6448 + 0x22c),
                     *(undefined4 *)(local_6448 + 0x230),*(undefined4 *)(local_6448 + 0x234));
        uVar3 = *(undefined8 *)(local_6448 + 0x228);
        uVar5 = *(undefined8 *)(local_6448 + 0x230);
        FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
        iVar1 = FUN_004989a0(uVar3,uVar5);
        if (iVar1 != 0) {
          FUN_004508b0(0x10,local_6470,*(undefined4 *)(local_6448 + 4),
                       *(undefined4 *)(local_6448 + 0x228),*(undefined4 *)(local_6448 + 0x22c),
                       *(undefined4 *)(local_6448 + 0x230),*(undefined4 *)(local_6448 + 0x234),0);
        }
      }
      if (0 < *(int *)(local_6448 + 0xfd80)) {
        *(int *)(local_6448 + 0xfd80) = *(int *)(local_6448 + 0xfd80) + -1;
      }
      if (*(int *)(local_6448 + 0xfd80) < 1) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6448 + 4) + 0x85f8)) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_007979e8();
          FUN_00404c80();
          FUN_004fca20();
          FUN_007979e8();
        }
      }
      *(undefined4 *)(local_6448 + 0x20c) = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 1;
    }
  }
  else {
    iVar1 = FUN_006f85c0();
    if (iVar1 == 0) {
      iVar1 = FUN_00572b10();
      if (iVar1 == 0) {
        *(undefined4 *)(*(int *)(local_6448 + 4) + 0x8560) = 0;
        *(undefined4 *)(local_6448 + 0xfdb0) = 0xffffffff;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      *(undefined4 *)(local_6448 + 0x1fc) = 0;
      DAT_00a0d618 = 0;
      FUN_0064c6d0();
      FUN_00404c80();
      FUN_0056d7d0();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 1;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiFukusha[0] */
/* 0064f060  FUN_0064f060  16 bytes, 0 callers */

undefined ** FUN_0064f060(void)

{
  return &PTR_s_CZukeiFukusha_009781bc;
}




/* vtable slots: CZukeiFukusha[23], CZukeiParametric[23] */
/* 0064ffe0  FUN_0064ffe0  133 bytes, 0 callers */

undefined4 FUN_0064ffe0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      if (DAT_00a0cc6c != 0) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x108) = 2;
      }
      FUN_00404c80();
      FUN_004fca20();
      FUN_004ad710();
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006f8be0();
  }
  return uVar1;
}




/* vtable slots: CZukeiFukusha[46] */
/* 00650070  FUN_00650070  3509 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00650070(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  double dVar2;
  undefined1 local_6450 [20];
  undefined4 local_643c;
  undefined4 local_6438;
  undefined4 local_6434;
  undefined4 local_6430;
  undefined4 local_642c;
  undefined4 local_6428;
  undefined4 local_6424;
  undefined4 local_6420;
  undefined4 local_641c;
  int local_6418;
  undefined4 local_6414;
  int local_6410;
  int local_640c;
  int *local_6408;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009388cb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0c7c0 == 0) {
    FUN_0079dea2();
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    local_6414 = 0;
    if (local_6408[0x7f] == 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_6408[1] + 0x85f8)) {
        if (*(int *)(local_6408[1] + 0x9078) == 0) {
          local_640c = -1;
          local_641c = 0x10;
          if (local_6408[0x3f6d] != 0) {
            local_641c = 0x11;
          }
          iVar1 = FUN_00778a40(0x15,&local_640c,*(undefined4 *)(local_6408[1] + 0x9070),param_1,
                               param_2,param_3,param_4,param_5,param_6,param_7,local_641c);
          if (iVar1 != 0) {
            if (param_3 == 1) {
              local_6428 = 0;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              ExceptionList = local_10;
              return local_6428;
            }
            if (param_3 != 2) {
              local_642c = 0;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              ExceptionList = local_10;
              return local_642c;
            }
            if ((-1 < local_640c) && (local_640c < 4)) {
              FUN_00404c80();
              FUN_004fca20();
              FUN_004ae200();
            }
            local_6430 = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
            ExceptionList = local_10;
            return local_6430;
          }
          if (((DAT_00a0b3c8 & 0x10) != 0) && (param_2 == 4)) {
            param_2 = 5;
          }
          local_6418 = param_2;
          if (param_2 == 4) {
            if (param_3 == 1) {
              FUN_005168b0(0x141c,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              FUN_0044c830(local_6450,local_6408[1]);
              FUN_00652dc0(param_4,param_5,param_6,param_7);
              local_6408[0x3f6c] = -1;
            }
          }
          else if (param_2 == 5) {
            if (param_3 == 1) {
              FUN_005168b0(0x272c,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              local_6408[0x7e] = 1;
              FUN_00653df0();
              FUN_00652e80();
              FUN_004988c0(local_24,param_4,param_5,param_6,param_7);
              FUN_0040c9d0();
              *(undefined4 *)(local_6408[2] + 4) = 1;
              local_6408[0x3f6c] = -1;
            }
          }
          else if (param_2 == 6) {
            if (param_3 == 1) {
              FUN_005168b0(0x272d,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              local_6408[0x7e] = 1;
              FUN_00653df0();
              FUN_00652e80();
              FUN_004988c0(local_34,param_4,param_5,param_6,param_7);
              FUN_0040c9d0();
              *(undefined4 *)(local_6408[2] + 4) = 1;
              local_6408[0x3f6c] = -1;
            }
          }
          else {
            local_6414 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          }
        }
        else {
          if ((0 < DAT_00a0b3c4) && (DAT_00a0b3c4 == param_2)) {
            if (param_3 == 1) {
              FUN_005168b0(0x1689,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              local_6408[0x3f57] = 1;
              local_6408[0x3f58] = 1;
              local_6408[0x3f59] = 1;
              local_6408[0x3f5a] = 0;
              FUN_0064f070();
            }
            local_6434 = local_6414;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
            ExceptionList = local_10;
            return local_6434;
          }
          local_6410 = param_2 + -1;
          switch(local_6410) {
          case 0:
            *(undefined4 *)(local_6408[1] + 0x857c) = 0;
            iVar1 = FUN_0079d98a();
            if ((iVar1 != 0) && (DAT_00a0c7bc != 0)) {
              *(undefined4 *)(local_6408[1] + 0x857c) = 1;
              local_6438 = 0;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              ExceptionList = local_10;
              return local_6438;
            }
            if (param_3 == 1) {
              if (local_6408[0x3f6d] == 0) {
                FUN_005168b0(0x1429,*(undefined4 *)(local_6408[1] + 0x8f50),
                             *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
              }
              else {
                FUN_005168b0(0x1428,*(undefined4 *)(local_6408[1] + 0x8f50),
                             *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
              }
            }
            else if (param_3 == 2) {
              if (local_6408[0x3f6d] == 0) {
                *(undefined4 *)(local_6408[1] + 0x9090) = 0x8096;
              }
              else {
                *(undefined4 *)(local_6408[1] + 0x9090) = 0x8024;
              }
              *(undefined4 *)(local_6408[1] + 0x906c) = 0;
              *(undefined4 *)(local_6408[1] + 0x9068) = 0;
            }
            break;
          case 1:
            if (param_3 == 1) {
              FUN_005168b0(0x18a1,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_6408[1] + 0x85f8)) {
                (**(code **)(*local_6408 + 0x7c))();
              }
            }
            break;
          case 2:
            if (param_3 == 1) {
              FUN_005168b0(0x1811,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_6408[1] + 0x85f8)) {
                FUN_00404c80();
                FUN_004fca20();
                FUN_004ad710();
              }
            }
            break;
          case 3:
            if (param_3 == 1) {
              FUN_005168b0(0x1817,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              *(undefined4 *)(local_6408[1] + 0x85a0) = 1;
              FUN_00406bc0(0x111,0x8046,0);
            }
            break;
          case 4:
            if (param_3 == 1) {
              FUN_005168b0(0x15fe,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              (**(code **)(*local_6408 + 0x80))();
            }
            break;
          default:
            local_6414 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
            break;
          case 6:
            if (param_3 == 1) {
              FUN_005168b0(0x17fc,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              local_6408[0x3f57] = local_6408[0x3f57] ^ 1;
              FUN_0064f070();
            }
            break;
          case 7:
            if (param_3 == 1) {
              FUN_005168b0(0x17fb,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              local_6408[0x3f58] = local_6408[0x3f58] ^ 1;
              FUN_0064f070();
            }
            break;
          case 8:
            if (param_3 == 1) {
              FUN_005168b0(0x17e3,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              local_6408[0x3f57] = 0;
              local_6408[0x3f58] = 0;
              local_6408[0x3f59] = 0;
              local_6408[0x3f5a] = 0;
              FUN_0064f070();
            }
            break;
          case 9:
            if (param_3 == 1) {
              FUN_005168b0(0x17fa,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              local_6408[0x3f59] = local_6408[0x3f59] ^ 1;
              local_6408[0x3f5a] = 0;
              FUN_0064f070();
            }
            break;
          case 10:
            if (param_3 == 1) {
              FUN_005168b0(0x17f9,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              local_6408[0x3f59] = 0;
              local_6408[0x3f5a] = local_6408[0x3f5a] ^ 1;
              FUN_0064f070();
            }
            break;
          case 0xb:
            if (param_3 == 1) {
              FUN_005168b0(0x1810,*(undefined4 *)(local_6408[1] + 0x8f50),
                           *(undefined4 *)(local_6408[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              *(ulonglong *)(local_6408 + 0x3f34) =
                   *(ulonglong *)(local_6408 + 0x3f34) ^ 0x8000000000000000;
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_6408[1] + 0x85f8)) {
                dVar2 = (*(double *)(local_6408 + 0x3f34) * 180.0) / 3.141592653589793;
                FUN_00404c80(dVar2);
                FUN_004fca20();
                FUN_004ae3f0(dVar2);
              }
            }
          }
        }
        local_643c = local_6414;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        local_6420 = local_643c;
      }
      else {
        local_6424 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        local_6420 = local_6424;
      }
    }
    else {
      local_6420 = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
  }
  else {
    local_6420 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return local_6420;
}




/* vtable slots: CZukeiFukusha[47], CZukeiParametric[47] */
/* 00650e60  FUN_00650e60  270 bytes, 0 callers */

void FUN_00650e60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int in_ECX;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(in_ECX + 0x1fc) == 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
        FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      else {
        FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      FUN_006fa580(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}




/* vtable slots: CZukeiFukusha[34] */
/* 00650f70  FUN_00650f70  134 bytes, 0 callers */

void FUN_00650f70(void)

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
    FUN_0064c6d0();
    FUN_0064f070(1);
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiFukusha[25] */
/* 00651000  FUN_00651000  1979 bytes, 0 callers */

void FUN_00651000(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  if (in_ECX[0x7f] != 0) {
    FUN_004066b0();
    return;
  }
  if (in_ECX[0x3f60] < 1) {
    return;
  }
  if ((in_ECX[0x3f43] != 0) || (in_ECX[0x3f42] != 1)) {
    *(double *)(in_ECX + 0x3f1e) = *(double *)(in_ECX + 0x8a) + *(double *)(in_ECX + 0x3f64);
    *(double *)(in_ECX + 0x3f20) = *(double *)(in_ECX + 0x8c) + *(double *)(in_ECX + 0x3f66);
    (**(code **)(*in_ECX + 0xc))(0x3ff0000000000000);
    return;
  }
  if (in_ECX[0x3f60] == 1) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x85f8)) {
      FUN_00404c80();
      FUN_004fca20();
      fVar2 = (float10)FUN_004ae590();
      *(double *)(in_ECX + 0x3f62) = (double)fVar2;
    }
  }
  in_ECX[0x3f60] = in_ECX[0x3f60] + 1;
  if (*(double *)(in_ECX + 0x3f68) <= 0.0) {
    local_10 = -*(double *)(in_ECX + 0x3f68);
  }
  else {
    local_10 = *(double *)(in_ECX + 0x3f68);
  }
  if (local_10 < 0.0001) {
LAB_00651225:
    in_ECX[0x3f2c] = 0;
    in_ECX[0x3f2d] = 0x3ff00000;
  }
  else {
    if (*(double *)(in_ECX + 0x3f68) <= 0.0) {
      local_18 = -*(double *)(in_ECX + 0x3f68);
    }
    else {
      local_18 = *(double *)(in_ECX + 0x3f68);
    }
    if (local_18 - 1.0 <= 0.0) {
      if (*(double *)(in_ECX + 0x3f68) <= 0.0) {
        local_28 = -*(double *)(in_ECX + 0x3f68);
      }
      else {
        local_28 = *(double *)(in_ECX + 0x3f68);
      }
      local_30 = -(local_28 - 1.0);
    }
    else {
      if (*(double *)(in_ECX + 0x3f68) <= 0.0) {
        local_20 = -*(double *)(in_ECX + 0x3f68);
      }
      else {
        local_20 = *(double *)(in_ECX + 0x3f68);
      }
      local_30 = local_20 - 1.0;
    }
    if (local_30 < 0.0001) goto LAB_00651225;
    if (*(double *)(in_ECX + 0x3f68) <= 0.0) {
      local_38 = -*(double *)(in_ECX + 0x3f68);
    }
    else {
      local_38 = *(double *)(in_ECX + 0x3f68);
    }
    if (local_38 <= 1.0) {
      *(double *)(in_ECX + 0x3f2c) =
           1.0 - (1.0 - *(double *)(in_ECX + 0x3f68)) * (double)in_ECX[0x3f60];
      if (*(double *)(in_ECX + 0x3f2c) <= 0.0) {
        local_48 = -*(double *)(in_ECX + 0x3f2c);
      }
      else {
        local_48 = *(double *)(in_ECX + 0x3f2c);
      }
      if (local_48 < 0.0001) {
        in_ECX[0x3f60] = in_ECX[0x3f60] + 1;
        return;
      }
    }
    else {
      *(double *)(in_ECX + 0x3f2c) =
           (*(double *)(in_ECX + 0x3f68) - 1.0) * (double)in_ECX[0x3f60] + 1.0;
      if (*(double *)(in_ECX + 0x3f2c) <= 0.0) {
        local_40 = -*(double *)(in_ECX + 0x3f2c);
      }
      else {
        local_40 = *(double *)(in_ECX + 0x3f2c);
      }
      if (10000.0 < local_40) {
        in_ECX[0x3f60] = in_ECX[0x3f60] + 1;
        return;
      }
    }
  }
  if (*(double *)(in_ECX + 0x3f6a) <= 0.0) {
    local_50 = -*(double *)(in_ECX + 0x3f6a);
  }
  else {
    local_50 = *(double *)(in_ECX + 0x3f6a);
  }
  if (0.0001 <= local_50) {
    if (*(double *)(in_ECX + 0x3f6a) <= 0.0) {
      local_58 = -*(double *)(in_ECX + 0x3f6a);
    }
    else {
      local_58 = *(double *)(in_ECX + 0x3f6a);
    }
    if (local_58 - 1.0 <= 0.0) {
      if (*(double *)(in_ECX + 0x3f6a) <= 0.0) {
        local_68 = -*(double *)(in_ECX + 0x3f6a);
      }
      else {
        local_68 = *(double *)(in_ECX + 0x3f6a);
      }
      local_70 = -(local_68 - 1.0);
    }
    else {
      if (*(double *)(in_ECX + 0x3f6a) <= 0.0) {
        local_60 = -*(double *)(in_ECX + 0x3f6a);
      }
      else {
        local_60 = *(double *)(in_ECX + 0x3f6a);
      }
      local_70 = local_60 - 1.0;
    }
    if (0.0001 <= local_70) {
      if (*(double *)(in_ECX + 0x3f6a) <= 0.0) {
        local_78 = -*(double *)(in_ECX + 0x3f6a);
      }
      else {
        local_78 = *(double *)(in_ECX + 0x3f6a);
      }
      if (local_78 <= 1.0) {
        *(double *)(in_ECX + 0x3f30) =
             1.0 - (1.0 - *(double *)(in_ECX + 0x3f6a)) * (double)in_ECX[0x3f60];
        if (*(double *)(in_ECX + 0x3f30) <= 0.0) {
          local_88 = -*(double *)(in_ECX + 0x3f30);
        }
        else {
          local_88 = *(double *)(in_ECX + 0x3f30);
        }
        if (local_88 < 0.0001) {
          in_ECX[0x3f60] = in_ECX[0x3f60] + 1;
          return;
        }
      }
      else {
        *(double *)(in_ECX + 0x3f30) =
             (*(double *)(in_ECX + 0x3f6a) - 1.0) * (double)in_ECX[0x3f60] + 1.0;
        if (*(double *)(in_ECX + 0x3f30) <= 0.0) {
          local_80 = -*(double *)(in_ECX + 0x3f30);
        }
        else {
          local_80 = *(double *)(in_ECX + 0x3f30);
        }
        if (10000.0 < local_80) {
          in_ECX[0x3f60] = in_ECX[0x3f60] + 1;
          return;
        }
      }
      goto LAB_006516e0;
    }
  }
  in_ECX[0x3f30] = 0;
  in_ECX[0x3f31] = 0x3ff00000;
LAB_006516e0:
  *(double *)(in_ECX + 0x3f34) = (double)in_ECX[0x3f60] * *(double *)(in_ECX + 0x3f62);
  *(double *)(in_ECX + 0x3f1e) =
       (double)in_ECX[0x3f60] * *(double *)(in_ECX + 0x3f64) + *(double *)(in_ECX + 0x8a);
  *(double *)(in_ECX + 0x3f20) =
       (double)in_ECX[0x3f60] * *(double *)(in_ECX + 0x3f66) + *(double *)(in_ECX + 0x8c);
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiFukusha[26], CZukeiFukusha[27] */
/* 006517c0  FUN_006517c0  31 bytes, 0 callers */

void FUN_006517c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiFukusha[28] */
/* 006517e0  FUN_006517e0  455 bytes, 0 callers */

void FUN_006517e0(void)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint local_c;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(in_ECX + 0xfd08) != *(int *)(*(int *)(iVar1 + 0x1a0) + 0xc70)) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(in_ECX + 0xfd08) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xc70);
        local_c = (uint)(*(int *)(in_ECX + 0xfd08) == 0);
        *(uint *)(in_ECX + 0xfdb4) = local_c;
        *(undefined4 *)(in_ECX + 0xfdb0) = 0xffffffff;
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
      }
    }
    *(undefined4 *)(in_ECX + 0xfd80) = 0;
    if (*(int *)(in_ECX + 0xfd48) == 0) {
      *(undefined4 *)(in_ECX + 0xfd48) = 1;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
        uVar4 = 0;
        uVar2 = 0;
        FUN_00404c80(0,0);
        FUN_004fca20();
        FUN_004ae1b0(uVar2,uVar4);
        uVar2 = CONCAT44(*(undefined4 *)(in_ECX + 0xfdb4),1);
        FUN_00404c80(1,*(undefined4 *)(in_ECX + 0xfdb4));
        FUN_004fca20();
        FUN_004accf0(uVar2);
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0xfd48) = 0;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
        lVar3 = (ulonglong)*(uint *)(in_ECX + 0xfdb4) << 0x20;
        FUN_00404c80(0,*(uint *)(in_ECX + 0xfdb4));
        FUN_004fca20();
        FUN_004accf0(lVar3);
      }
    }
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiFukusha[29] */
/* 006519b0  FUN_006519b0  31 bytes, 0 callers */

void FUN_006519b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    FUN_006fb760();
  }
  return;
}




/* vtable slots: CZukeiFukusha[30] */
/* 006519d0  FUN_006519d0  468 bytes, 0 callers */

void FUN_006519d0(void)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint local_c;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(in_ECX + 0xfd08) != *(int *)(*(int *)(iVar1 + 0x1a0) + 0xc70)) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(in_ECX + 0xfd08) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xc70);
        local_c = (uint)(*(int *)(in_ECX + 0xfd08) == 0);
        *(uint *)(in_ECX + 0xfdb4) = local_c;
        *(undefined4 *)(in_ECX + 0xfdb0) = 0xffffffff;
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
      }
    }
    *(undefined4 *)(in_ECX + 0xfd80) = 0;
    *(undefined4 *)(in_ECX + 0xfd40) = 0;
    if (*(int *)(in_ECX + 0xfd18) == 0) {
      *(undefined4 *)(in_ECX + 0xfd18) = 1;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
        uVar4 = 0;
        uVar2 = 0;
        FUN_00404c80(0,0);
        FUN_004fca20();
        FUN_004ae1b0(uVar2,uVar4);
        uVar2 = CONCAT44(*(undefined4 *)(in_ECX + 0xfdb4),2);
        FUN_00404c80(2,*(undefined4 *)(in_ECX + 0xfdb4));
        FUN_004fca20();
        FUN_004accf0(uVar2);
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0xfd18) = 0;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
        lVar3 = (ulonglong)*(uint *)(in_ECX + 0xfdb4) << 0x20;
        FUN_00404c80(0,*(uint *)(in_ECX + 0xfdb4));
        FUN_004fca20();
        FUN_004accf0(lVar3);
      }
    }
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_006fbbb0();
  }
  return;
}




/* vtable slots: CZukeiFukusha[31] */
/* 00651bb0  FUN_00651bb0  990 bytes, 0 callers */

void FUN_00651bb0(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int in_ECX;
  undefined4 uVar11;
  int local_2c8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938910;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    FUN_006fbbf0();
    ExceptionList = local_10;
    return;
  }
  FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  iVar5 = FUN_004fca20();
  if (*(int *)(iVar5 + 0x1a0) != *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
    ExceptionList = local_10;
    return;
  }
  FUN_004ae5e0(0);
  local_8 = 0;
  DAT_00a0cc8c = 1;
  FUN_00404c80();
  iVar6 = FUN_004fca20();
  iVar4 = DAT_00a0cb5c;
  iVar3 = DAT_00a0cb58;
  iVar2 = DAT_00a0cb30;
  iVar5 = DAT_00a0cb2c;
  if (*(int *)(*(int *)(iVar6 + 0x1a0) + 0xc70) != 0) {
    local_2c8 = DAT_00a0cb28;
  }
  FUN_00404c80();
  iVar6 = FUN_004fca20();
  iVar6 = *(int *)(*(int *)(iVar6 + 0x1a0) + 0xc80);
  FUN_00404c80();
  iVar7 = FUN_004fca20();
  iVar7 = *(int *)(*(int *)(iVar7 + 0x1a0) + 0xc84);
  FUN_00404c80();
  iVar8 = FUN_004fca20();
  iVar8 = *(int *)(*(int *)(iVar8 + 0x1a0) + 0xc88);
  FUN_00404c80();
  iVar9 = FUN_004fca20();
  iVar9 = *(int *)(*(int *)(iVar9 + 0x1a0) + 0xc8c);
  bVar1 = false;
  iVar10 = FUN_0079850d();
  if (iVar10 != 1) goto LAB_00651eb0;
  FUN_00404c80();
  iVar10 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar10 + 0x1a0) + 0xc80) == iVar6) {
    FUN_00404c80();
    iVar10 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar10 + 0x1a0) + 0xc84) != iVar7) goto LAB_00651dff;
    FUN_00404c80();
    iVar10 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar10 + 0x1a0) + 0xc88) != iVar8) goto LAB_00651dff;
    FUN_00404c80();
    iVar10 = FUN_004fca20();
    if ((((*(int *)(*(int *)(iVar10 + 0x1a0) + 0xc8c) != iVar9) || (DAT_00a0cb28 != local_2c8)) ||
        (DAT_00a0cb30 != iVar2)) ||
       (((DAT_00a0cb2c != iVar5 || (DAT_00a0cb58 != iVar3)) || (DAT_00a0cb5c != iVar4))))
    goto LAB_00651dff;
  }
  else {
LAB_00651dff:
    bVar1 = true;
  }
  FUN_00404c80();
  iVar10 = FUN_004fca20();
  *(int *)(*(int *)(iVar10 + 0x1a0) + 0xc80) = iVar6;
  FUN_00404c80();
  iVar6 = FUN_004fca20();
  *(int *)(*(int *)(iVar6 + 0x1a0) + 0xc84) = iVar7;
  FUN_00404c80();
  iVar6 = FUN_004fca20();
  *(int *)(*(int *)(iVar6 + 0x1a0) + 0xc88) = iVar8;
  FUN_00404c80();
  iVar6 = FUN_004fca20();
  *(int *)(*(int *)(iVar6 + 0x1a0) + 0xc8c) = iVar9;
  DAT_00a0cb28 = local_2c8;
  DAT_00a0cb2c = iVar5;
  DAT_00a0cb30 = iVar2;
  DAT_00a0cb58 = iVar3;
  DAT_00a0cb5c = iVar4;
LAB_00651eb0:
  FUN_00404c80();
  iVar5 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0xfd5c) = *(undefined4 *)(*(int *)(iVar5 + 0x1a0) + 0xc80);
  FUN_00404c80();
  iVar5 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0xfd60) = *(undefined4 *)(*(int *)(iVar5 + 0x1a0) + 0xc84);
  FUN_00404c80();
  iVar5 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0xfd64) = *(undefined4 *)(*(int *)(iVar5 + 0x1a0) + 0xc88);
  FUN_00404c80();
  iVar5 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0xfd68) = *(undefined4 *)(*(int *)(iVar5 + 0x1a0) + 0xc8c);
  FUN_0064f070(1);
  DAT_00a0cc8c = 0;
  if (bVar1) {
    uVar11 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007979e8(uVar11);
  }
  local_8 = 0xffffffff;
  FUN_004ae780();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusha[32] */
/* 00651f90  FUN_00651f90  566 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00651f90(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  uint local_30;
  undefined1 local_28 [16];
  double local_18;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(in_ECX + 0xfd08) != *(int *)(*(int *)(iVar1 + 0x1a0) + 0xc70)) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(in_ECX + 0xfd08) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xc70);
        local_30 = (uint)(*(int *)(in_ECX + 0xfd08) == 0);
        *(uint *)(in_ECX + 0xfdb4) = local_30;
        *(undefined4 *)(in_ECX + 0xfdb0) = 0xffffffff;
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
      }
    }
    *(undefined4 *)(in_ECX + 0xfd18) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      if (*(int *)(in_ECX + 0xfd40) == 0) {
        *(undefined4 *)(in_ECX + 0xfd40) = 1;
        uVar3 = *(undefined4 *)(in_ECX + 0xfdb4);
        uVar2 = 3;
        FUN_00404c80(3,uVar3);
        FUN_004fca20();
        FUN_004accf0(uVar2,uVar3);
      }
      else if (*(int *)(in_ECX + 0xfd40) == 1) {
        *(undefined4 *)(in_ECX + 0xfd40) = 2;
        local_10 = *(undefined4 *)(in_ECX + 0x230);
        local_c = *(undefined4 *)(in_ECX + 0x234);
        local_18 = *(double *)(in_ECX + 0x228) + 1.0;
        FUN_004988c0(local_28,local_18,local_10,local_c);
        uVar3 = *(undefined4 *)(in_ECX + 0xfdb4);
        uVar2 = 3;
        FUN_00404c80(3,uVar3);
        FUN_004fca20();
        FUN_004accf0(uVar2,uVar3);
      }
      else {
        *(undefined4 *)(in_ECX + 0xfd40) = 0;
        uVar3 = *(undefined4 *)(in_ECX + 0xfdb4);
        uVar2 = 0;
        FUN_00404c80(0,uVar3);
        FUN_004fca20();
        FUN_004accf0(uVar2,uVar3);
      }
    }
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_006fbc40();
  }
  return;
}




/* vtable slots: CZukeiFukusha[33] */
/* 006521d0  FUN_006521d0  323 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006521d0(void)

{
  int iVar1;
  int *in_ECX;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x85f8)) {
    (**(code **)(*in_ECX + 0x40))();
    if (in_ECX[0x3f42] == 1) {
      in_ECX[0x3f42] = 0;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xc70) = 0;
    }
    else {
      in_ECX[0x3f42] = 1;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xc70) = 1;
    }
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007955d2();
    FUN_004988c0(local_18,in_ECX[0x3f22],in_ECX[0x3f23],in_ECX[0x3f24],in_ECX[0x3f25]);
    FUN_004988c0(local_28,in_ECX[0x3f26],in_ECX[0x3f27],in_ECX[0x3f28],in_ECX[0x3f29]);
    (**(code **)(*in_ECX + 0xc))();
  }
  return;
}




/* vtable slots: CZukeiFukusha[36] */
/* 00652320  FUN_00652320  956 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00652320(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
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
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8610)) {
      FUN_005ca990(1,0);
    }
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    FUN_00404c80();
    FUN_0056d200();
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
    goto LAB_006526b1;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_004ae4a0();
  *(double *)(in_ECX + 0xfce0) = (double)fVar2;
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_004ae510();
  *(double *)(in_ECX + 0xfcf0) = (double)fVar2;
  if (*(double *)(in_ECX + 0xfce0) <= 0.0) {
    local_63f8 = -*(double *)(in_ECX + 0xfce0);
  }
  else {
    local_63f8 = *(double *)(in_ECX + 0xfce0);
  }
  if (1e-07 < local_63f8) {
LAB_006525ab:
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004ae430();
    *(double *)(in_ECX + 0xfcb0) = (double)fVar2;
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004ae460();
    *(double *)(in_ECX + 0xfcc0) = (double)fVar2;
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004ae590();
    *(double *)(in_ECX + 0xfcd0) = (double)fVar2;
    *(undefined4 *)(in_ECX + 0xfd80) = 0;
    FUN_00653fe0();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
  }
  else {
    if (*(double *)(in_ECX + 0xfcf0) <= 0.0) {
      local_6400 = -*(double *)(in_ECX + 0xfcf0);
    }
    else {
      local_6400 = *(double *)(in_ECX + 0xfcf0);
    }
    if (1e-07 < local_6400) goto LAB_006525ab;
    if (((*(double *)(in_ECX + 0xfcb0) == 0.0) && (*(double *)(in_ECX + 0xfcc0) == 0.0)) &&
       (*(double *)(in_ECX + 0xfcd0) == 0.0)) {
      FUN_00507b10();
    }
  }
  FUN_00404c80();
  FUN_0056d200();
LAB_006526b1:
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusha[49] */
/* 006526e0  FUN_006526e0  185 bytes, 0 callers */

void FUN_006526e0(undefined8 param_1)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xfd80) = 0;
  if ((*(int *)(in_ECX + 0x1fc) == 0) && (*(int *)(in_ECX + 0x1f8) == 0)) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_007979e8();
      FUN_00404c80();
      FUN_004fca20();
      FUN_007979e8();
      FUN_00404c80(param_1);
      FUN_004fca20();
      FUN_004ae3f0(param_1);
    }
  }
  return;
}




/* vtable slots: CZukeiFukusha[50], CZukeiParametric[50] */
/* 006527a0  FUN_006527a0  165 bytes, 0 callers */

void FUN_006527a0(double param_1)

{
  int iVar1;
  int in_ECX;
  double dVar2;
  
  if ((1e-07 <= param_1) && (*(int *)(in_ECX + 0x1fc) == 0)) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      param_1 = param_1 / *(double *)
                           (*(int *)(in_ECX + 4) + 0x2578 +
                           *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
      dVar2 = param_1;
      FUN_00404c80(param_1,param_1);
      FUN_004fca20();
      FUN_004ae320(param_1,dVar2);
    }
  }
  return;
}




/* vtable slots: CZukeiFukusha[51] */
/* 00652850  FUN_00652850  264 bytes, 0 callers */

void FUN_00652850(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(in_ECX + 0xfd80) = 0;
  if ((*(int *)(in_ECX + 0x1fc) == 0) && (*(int *)(in_ECX + 0x1f8) == 0)) {
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
      uVar3 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar3);
      uVar3 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar3);
    }
    *(undefined4 *)(in_ECX + 0xfd64) = 1;
    *(undefined4 *)(in_ECX + 0xfd68) = 0;
    FUN_0064f070(1);
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




/* vtable slots: CZukeiFukusha[15] */
/* 00652960  FUN_00652960  1108 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00652960(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_6438 [20];
  undefined4 local_6424;
  undefined4 local_6420;
  undefined4 local_641c;
  undefined4 local_6418;
  int local_6414;
  int local_6410;
  undefined4 local_640c;
  int local_6408;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093894b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xfd80) = 0;
  local_6408 = in_ECX;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_00404c80(local_14);
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6408 + 4) + 0x85f8)) {
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar4);
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar4);
    }
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
  local_8._0_1_ = 1;
  local_640c = FUN_0040c0e0();
  iVar1 = FUN_004146c0();
  if (iVar1 == 0) {
    if (*(int *)(local_6408 + 0xfdb0) < 0) {
      local_6424 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_641c = local_6424;
    }
    else {
      FUN_0044dd90(local_6438,*(undefined4 *)(local_6408 + 4));
      FUN_0044de00(local_6438,*(undefined4 *)(local_6408 + 4));
      local_6418 = 0;
      if ((*(int *)(local_6408 + 0xfd08) == 0) || (*(int *)(local_6408 + 0xfd0c) == 1)) {
        local_6414 = FUN_00572b10();
        while ((local_6414 != 0 && (local_6410 = FUN_00572b30(&local_6414,0), local_6410 != 0))) {
          *(ushort *)(local_6410 + 0x44) = *(ushort *)(local_6410 + 0x44) & 0xfffd;
        }
        FUN_0044c830(local_6438,*(undefined4 *)(local_6408 + 4));
        local_6418 = 1;
      }
      FUN_00453bd0(local_6438,*(undefined4 *)(local_6408 + 4),local_6418);
      if (*(int *)(local_6408 + 0xfdb0) < 0) {
        *(undefined4 *)(local_6408 + 0xfdb0) = 0;
      }
      *(int *)(local_6408 + 0xfdb0) = *(int *)(local_6408 + 0xfdb0) + 1;
      if (*(int *)(local_6408 + 0xfdb0) < 0xfa1) {
        FUN_004988c0();
        FUN_00517640(*(undefined4 *)(local_6408 + 0x228),*(undefined4 *)(local_6408 + 0x22c),
                     *(undefined4 *)(local_6408 + 0x230),*(undefined4 *)(local_6408 + 0x234));
        uVar4 = *(undefined4 *)(local_6408 + 0x228);
        uVar2 = *(undefined4 *)(local_6408 + 0x22c);
        uVar3 = *(undefined4 *)(local_6408 + 0x230);
        uVar5 = *(undefined4 *)(local_6408 + 0x234);
        FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
        iVar1 = FUN_004989a0(uVar4,uVar2,uVar3,uVar5);
        if (iVar1 != 0) {
          FUN_004508b0(0x10,local_6438,*(undefined4 *)(local_6408 + 4),
                       *(undefined4 *)(local_6408 + 0x228),*(undefined4 *)(local_6408 + 0x22c),
                       *(undefined4 *)(local_6408 + 0x230),*(undefined4 *)(local_6408 + 0x234),0);
        }
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_6420 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_641c = local_6420;
    }
  }
  else {
    local_641c = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_641c;
}




/* vtable slots: CZukeiFukusha[12] */
/* 00652ea0  FUN_00652ea0  69 bytes, 0 callers */

undefined4
FUN_00652ea0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_006fcae0(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiFukusha[10] */
/* 00652ef0  FUN_00652ef0  1215 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00652ef0(void)

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
      FUN_00652dc0(local_24,local_20,local_1c,local_18);
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
      FUN_00652dc0(local_24,local_20,local_1c,local_18);
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




/* vtable slots: CZukeiFukusha[9] */
/* 006533c0  FUN_006533c0  2004 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006533c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
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
  puStack_c = &LAB_009389e0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    if (*(int *)(in_ECX + 0x1f8) == 0) {
      *(undefined4 *)(in_ECX + 0xfd80) = 0;
      FUN_00404c80(local_14);
      iVar3 = FUN_004fca20();
      if (*(int *)(iVar3 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f8)) {
        uVar2 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_007979e8(uVar2);
        uVar2 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_007979e8(uVar2);
      }
      if (*(int *)(in_ECX + 0xfd48) == 0) {
        if (*(int *)(in_ECX + 0xfd18) == 0) {
          if (*(int *)(in_ECX + 0xfd40) == 0) {
            if (*(int *)(in_ECX + 0xfd14) == 0) {
              *(undefined4 *)(in_ECX + 0xfd14) = 1;
              FUN_004988c0(local_94,param_2,param_3,param_4,param_5);
              uVar2 = 0;
            }
            else {
              if (((*(int *)(*(int *)(in_ECX + 4) + 0x1780) != 0) &&
                  (*(int *)(*(int *)(in_ECX + 4) + 0x176c) != 0)) && (param_1 != 0x231d)) {
                FUN_0041df00(*(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c),
                             *(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
                             &param_2);
              }
              FUN_004988c0(local_a4,param_2,param_3,param_4,param_5);
              FUN_004fb9f0();
              FUN_005168b0(0x1456,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
              uVar2 = 1;
            }
          }
          else {
            if (*(int *)(in_ECX + 0xfd40) == 1) {
              FUN_004988c0(local_64,param_2,param_3,param_4,param_5);
              *(undefined4 *)(in_ECX + 0xfd40) = 2;
            }
            else if (*(int *)(in_ECX + 0xfd40) == 2) {
              FUN_004988c0(local_74,param_2,param_3,param_4,param_5);
              *(undefined4 *)(in_ECX + 0xfd40) = 3;
            }
            else if (*(int *)(in_ECX + 0xfd40) == 3) {
              FUN_004988c0(local_84,param_2,param_3,param_4,param_5);
              *(undefined4 *)(in_ECX + 0xfd40) = 4;
              ExceptionList = local_10;
              return 1;
            }
            FUN_00404c80();
            FUN_0056d7d0();
            uVar2 = 0;
          }
        }
        else {
          if (*(int *)(in_ECX + 0xfd18) == 1) {
            FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
            *(undefined4 *)(in_ECX + 0xfd18) = 2;
          }
          else if (*(int *)(in_ECX + 0xfd18) == 2) {
            FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
            *(undefined4 *)(in_ECX + 0xfd18) = 3;
          }
          else if (*(int *)(in_ECX + 0xfd18) == 3) {
            FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
            *(undefined4 *)(in_ECX + 0xfd18) = 4;
            ExceptionList = local_10;
            return 1;
          }
          FUN_00404c80();
          FUN_0056d7d0();
          uVar2 = 0;
        }
      }
      else {
        FUN_00446aa0();
        local_8 = 0;
        iVar3 = FUN_0044a270(3,*(undefined4 *)(in_ECX + 4),&param_2,in_ECX + 0xfd4c,1);
        if (iVar3 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
        else if (*(int *)(in_ECX + 0xfd4c) == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
        else {
          iVar3 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078);
          if (iVar3 != 0) {
            *(int *)(in_ECX + 0xfd4c) = *(int *)(in_ECX + 0xfd4c) + 0x68;
          }
          iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
          if (iVar3 == 0) {
            FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
          else {
            iVar3 = *(int *)(in_ECX + 0xfd4c);
            iVar1 = *(int *)(in_ECX + 0xfd4c);
            fVar4 = (float10)FUN_00655c60(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                                          *(undefined4 *)(iVar1 + 0x10),
                                          *(undefined4 *)(iVar1 + 0x14),
                                          *(undefined4 *)(iVar3 + 0x18),
                                          *(undefined4 *)(iVar3 + 0x1c),
                                          *(undefined4 *)(iVar3 + 0x20),
                                          *(undefined4 *)(iVar3 + 0x24));
            *(double *)(in_ECX + 0xfd50) = (double)fVar4;
            iVar3 = *(int *)(in_ECX + 0xfd4c);
            iVar1 = *(int *)(in_ECX + 0xfd4c);
            FUN_005f8940(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                         *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
                         *(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),
                         *(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24),0);
            FUN_004988c0(local_24,*(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c),
                         *(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234));
            FUN_005f92e0(in_ECX + 0xfc78);
            *(ulonglong *)(in_ECX + 0xfc80) = *(ulonglong *)(in_ECX + 0xfc80) ^ 0x8000000000000000;
            FUN_005f8ce0(in_ECX + 0xfc78);
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 1;
          }
        }
      }
    }
    else {
      iVar3 = FUN_0040dbb0(param_1,param_2,param_3,param_4,param_5);
      if (iVar3 != 0) {
        *(undefined4 *)(in_ECX + 0x1f8) = 0;
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiFukusha[13] */
/* 00653ba0  FUN_00653ba0  69 bytes, 0 callers */

undefined4
FUN_00653ba0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_006fda50(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiFukusha[11] */
/* 00653bf0  FUN_00653bf0  510 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00653bf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
      *(undefined4 *)(in_ECX + 0xfdb8) = 0;
      if (*(int *)(in_ECX + 0xfd48) == 0) {
        FUN_00446aa0(local_14);
        local_8 = 0;
        local_24 = param_2;
        local_20 = param_3;
        local_1c = param_4;
        local_18 = param_5;
        iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
        if (iVar2 == 1) {
          uVar1 = FUN_006533c0(0x231d,local_24,local_20,local_1c,local_18);
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
        *(undefined4 *)(in_ECX + 0xfdb8) = 1;
        uVar1 = FUN_006533c0(param_1,param_2,param_3,param_4,param_5);
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




/* vtable slots: CZukeiFukusha[8] */
/* 00653e10  FUN_00653e10  455 bytes, 3 callers */

void FUN_00653e10(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938a5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00464040(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if ((*(int *)(in_ECX + 0xfd64) == 1) || (*(int *)(in_ECX + 0xfd68) == 1)) {
    FUN_00455380();
  }
  FUN_00465c40(*(undefined8 *)(in_ECX + 0xfca8),*(undefined4 *)(in_ECX + 0x228),
               *(undefined4 *)(in_ECX + 0x22c),*(undefined4 *)(in_ECX + 0x230),
               *(undefined4 *)(in_ECX + 0x234),*(undefined4 *)(in_ECX + 0xfd44),
               *(undefined8 *)(in_ECX + 0xfcb0),*(undefined8 *)(in_ECX + 0xfcc0));
  FUN_0046d5b0(*(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c),
               *(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
               *(undefined4 *)(in_ECX + 0xfd44),*(undefined8 *)(in_ECX + 0xfcd0));
  FUN_0046bdf0(*(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c),
               *(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
               *(undefined4 *)(in_ECX + 0xfd44),*(undefined4 *)(in_ECX + 0xfc78),
               *(undefined4 *)(in_ECX + 0xfc7c),*(undefined4 *)(in_ECX + 0xfc80),
               *(undefined4 *)(in_ECX + 0xfc84),*(undefined4 *)(in_ECX + 0xfd00),
               *(undefined4 *)(in_ECX + 0xfd04));
  local_8 = 0xffffffff;
  FUN_004640a0();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusha[3] */
/* 00653fe0  FUN_00653fe0  7286 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00653fe0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  float10 fVar5;
  double dVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 uVar9;
  double dStack_19e28;
  double dStack_19e20;
  double dStack_19e10;
  double dStack_19e08;
  double dStack_19e00;
  double dStack_19df8;
  double dStack_19df0;
  int *piStack_19dd0;
  int iStack_19dbc;
  int iStack_19db4;
  undefined1 auStack_19dac [20];
  uint uStack_19d98;
  int *piStack_19d94;
  double dStack_19d90;
  int iStack_19d88;
  uint uStack_19d84;
  byte bStack_19d7e;
  CWaitCursor CStack_19d7d;
  int *piStack_19d7c;
  undefined4 uStack_19d78;
  int iStack_19d74;
  int iStack_19d70;
  int *piStack_19d6c;
  int iStack_19d68;
  undefined4 uStack_13a6c;
  undefined8 uStack_139e4;
  undefined8 uStack_139dc;
  undefined8 uStack_139d4;
  undefined8 uStack_139cc;
  int aiStack_138b4 [10004];
  int aiStack_9c64 [10004];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938abe;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x208) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9058) = *(undefined4 *)(in_ECX + 0xfd08);
  iStack_19d68 = in_ECX;
  local_14 = uVar1;
  FUN_004fb910();
  CWaitCursor::CWaitCursor(&CStack_19d7d);
  local_8 = 0;
  FUN_004fb9f0(uVar1);
  FUN_005168b0();
  piStack_19d7c = (int *)0x0;
  uStack_19d78 = FUN_0040c0e0();
  uStack_19d84 = FUN_0047c770();
  if (5000 < (int)uStack_19d84) {
    iVar2 = FUN_004121b0();
    local_8._0_1_ = 1;
    if (iVar2 == 0) {
      piStack_19dd0 = (int *)0x0;
    }
    else {
      piStack_19dd0 = (int *)FUN_004aa560();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    piStack_19d7c = piStack_19dd0;
    FUN_00404c80();
    uVar3 = FUN_0046ba20();
    (**(code **)(*piStack_19d7c + 0x164))(0x15d,uVar3);
    FUN_00797f20();
    FUN_004701c0(0,(int)uStack_19d84 >> 8);
  }
  FUN_0079dea2();
  local_8._0_1_ = 2;
  FUN_00446aa0();
  local_8._0_1_ = 3;
  FUN_00464040();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(iStack_19d68 + 4) + 0x85f8)) {
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae4a0();
    *(double *)(iStack_19d68 + 0xfce0) = (double)fVar5;
    FUN_00404c80();
    FUN_004fca20();
    fVar5 = (float10)FUN_004ae510();
    *(double *)(iStack_19d68 + 0xfcf0) = (double)fVar5;
    if (*(double *)(iStack_19d68 + 0xfce0) <= 0.0) {
      dStack_19e28 = -*(double *)(iStack_19d68 + 0xfce0);
    }
    else {
      dStack_19e28 = *(double *)(iStack_19d68 + 0xfce0);
    }
    if (dStack_19e28 <= 1e-07) {
      if (*(double *)(iStack_19d68 + 0xfcf0) <= 0.0) {
        dStack_19df0 = -*(double *)(iStack_19d68 + 0xfcf0);
      }
      else {
        dStack_19df0 = *(double *)(iStack_19d68 + 0xfcf0);
      }
      if (dStack_19df0 <= 1e-07) goto LAB_0065439f;
    }
    FUN_0044cd50();
    *(double *)(iStack_19d68 + 0xfc78) =
         *(double *)(iStack_19d68 + 0x228) + *(double *)(iStack_19d68 + 0xfce0);
    *(double *)(iStack_19d68 + 0xfc80) =
         *(double *)(iStack_19d68 + 0x230) + *(double *)(iStack_19d68 + 0xfcf0);
    *(undefined4 *)(iStack_19d68 + 0xfd00) = 0;
    *(undefined4 *)(iStack_19d68 + 0xfd04) = 0;
  }
LAB_0065439f:
  FUN_0044dd90(auStack_19dac,*(undefined4 *)(iStack_19d68 + 4));
  FUN_0044de00(auStack_19dac,*(undefined4 *)(iStack_19d68 + 4));
  FUN_00454890();
  uStack_19d98 = *(uint *)(*(int *)(iStack_19d68 + 4) + 0x256c);
  piStack_19d6c = (int *)0x0;
  if ((*(int *)(iStack_19d68 + 0xfd64) == 1) || (*(int *)(iStack_19d68 + 0xfd68) == 1)) {
    dVar6 = *(double *)(*(int *)(iStack_19d68 + 4) + 0x2578 + uStack_19d98 * 8);
    iStack_19d74 = FUN_00572b10();
    do {
      if ((iStack_19d74 == 0) ||
         (piStack_19d6c = (int *)FUN_00572b30(&iStack_19d74,0), piStack_19d6c == (int *)0x0))
      goto LAB_006545a3;
      bStack_19d7e = (**(code **)(*piStack_19d6c + 0x28))();
    } while ((bStack_19d7e == uStack_19d98) ||
            (*(double *)(*(int *)(iStack_19d68 + 4) + 0x2578 + (uint)bStack_19d7e * 8) == dVar6));
    iVar2 = FUN_004f60a0();
    if (iVar2 != 1) {
      local_8._0_1_ = 3;
      FUN_004640a0();
      local_8._0_1_ = 2;
      FUN_00447100();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00408b00();
      ExceptionList = local_10;
      return;
    }
  }
LAB_006545a3:
  uVar3 = DAT_00a0cb58;
  if (*(int *)(iStack_19d68 + 0xfd48) != 0) {
    *(undefined8 *)(iStack_19d68 + 0xfca8) = *(undefined8 *)(iStack_19d68 + 0xfd50);
    if (1.5707963267948966 < *(double *)(iStack_19d68 + 0xfca8)) {
      *(double *)(iStack_19d68 + 0xfca8) = *(double *)(iStack_19d68 + 0xfca8) - 3.141592653589793;
    }
    if (*(double *)(iStack_19d68 + 0xfca8) <= -1.5707963267948966) {
      *(double *)(iStack_19d68 + 0xfca8) = *(double *)(iStack_19d68 + 0xfca8) + 3.141592653589793;
    }
    if (*(double *)(iStack_19d68 + 0xfca8) <= 0.0) {
      dStack_19df8 = -*(double *)(iStack_19d68 + 0xfca8);
    }
    else {
      dStack_19df8 = *(double *)(iStack_19d68 + 0xfca8);
    }
    if (dStack_19df8 < 0.7853981633974483) {
      *(undefined8 *)(iStack_19d68 + 0xfcb0) = 0x3ff0000000000000;
      *(undefined8 *)(iStack_19d68 + 0xfcc0) = 0xbff0000000000000;
    }
    else {
      if (*(double *)(iStack_19d68 + 0xfca8) <= 0.0) {
        *(double *)(iStack_19d68 + 0xfca8) = *(double *)(iStack_19d68 + 0xfca8) + 1.5707963267948966
        ;
      }
      else {
        *(double *)(iStack_19d68 + 0xfca8) = *(double *)(iStack_19d68 + 0xfca8) - 1.5707963267948966
        ;
      }
      *(undefined8 *)(iStack_19d68 + 0xfcb0) = 0xbff0000000000000;
      *(undefined8 *)(iStack_19d68 + 0xfcc0) = 0x3ff0000000000000;
    }
    if (*(double *)(iStack_19d68 + 0xfca8) <= 0.0) {
      dStack_19e00 = -*(double *)(iStack_19d68 + 0xfca8);
    }
    else {
      dStack_19e00 = *(double *)(iStack_19d68 + 0xfca8);
    }
    if (dStack_19e00 < 1e-07) {
      *(undefined8 *)(iStack_19d68 + 0xfca8) = 0;
    }
    *(undefined4 *)(iStack_19d68 + 0xfd04) = 0;
    *(undefined4 *)(iStack_19d68 + 0xfd00) = 0;
  }
  if (*(int *)(iStack_19d68 + 0xfd18) != 0) {
    FUN_0064f350();
  }
  if (*(int *)(iStack_19d68 + 0xfd40) != 0) {
    FUN_0064f900();
  }
  DAT_00a0cc6c = 0;
  uStack_19d84 = 0;
  FUN_004b5a50();
  iStack_19d74 = FUN_00572b10();
  while (iStack_19d74 != 0) {
    uStack_19d84 = uStack_19d84 + 1;
    if ((piStack_19d7c != (int *)0x0) && ((uStack_19d84 & 0xff) == 0)) {
      FUN_00470190();
    }
    piStack_19d6c = (int *)FUN_00572b30(&iStack_19d74,0);
    if (piStack_19d6c == (int *)0x0) break;
    if ((*(int *)(iStack_19d68 + 0xfd08) == 0) && (iVar2 = FUN_0042dcb0(), iVar2 != 0)) {
      FUN_0044a120(auStack_19dac,*(undefined4 *)(iStack_19d68 + 4),piStack_19d6c,0);
    }
    else if (((*(int *)(*(int *)(iStack_19d68 + 4) + 0x9050) == 0) &&
             (*(int *)(*(int *)(iStack_19d68 + 4) + 0x9054) == 0)) ||
            (((iVar2 = FUN_0044f450(), iVar2 == 0 && (iVar2 = FUN_0044f480(), iVar2 == 0)) &&
             (iVar2 = FUN_0044f280(), iVar2 == 0)))) {
      uVar4 = (**(code **)(*piStack_19d6c + 0x14))();
      *(undefined4 *)(iStack_19d68 + 0xfd44) = uVar4;
      *(int *)(*(int *)(iStack_19d68 + 0xfd44) + 4) = piStack_19d6c[1];
      FUN_00653e10();
      FUN_00570960();
    }
    else if (*(int *)(iStack_19d68 + 0xfd08) != 0) {
      *(int **)(iStack_19d68 + 0xfd44) = piStack_19d6c;
      FUN_0064cb60();
    }
  }
  FUN_004b7110();
  uStack_13a6c = 0;
  uStack_139dc = 0x487087c797fde41d;
  uStack_139e4 = 0x487087c797fde41d;
  uStack_139cc = 0xc87087c797fde41d;
  uStack_139d4 = 0xc87087c797fde41d;
  DAT_00a0cb58 = uVar3;
  if (piStack_19d7c != (int *)0x0) {
    (**(code **)(*piStack_19d7c + 0x60))();
    piStack_19d94 = piStack_19d7c;
    if (piStack_19d7c != (int *)0x0) {
      (**(code **)(*piStack_19d7c + 4))();
    }
    piStack_19d7c = (int *)0x0;
  }
  uVar3 = DAT_00a0cae8;
  if (*(int *)(iStack_19d68 + 0xfd08) == 0) {
    DAT_00a0cae8 = 0x32;
    FUN_00478480();
    FUN_00574f10();
    if (DAT_00a0cae8 != 0) {
      FUN_0044f4f0(auStack_19dac,*(undefined4 *)(iStack_19d68 + 4));
    }
  }
  DAT_00a0cae8 = uVar3;
  if ((*(int *)(iStack_19d68 + 0xfd08) == 1) && (*(int *)(iStack_19d68 + 0xfd0c) == 1)) {
    iStack_19d74 = FUN_00572030();
    while ((iStack_19d74 != 0 &&
           (piStack_19d6c = (int *)FUN_00572100(), piStack_19d6c != (int *)0x0))) {
      FUN_00615500();
    }
  }
  FUN_004988c0();
  FUN_004988c0();
  if (*(int *)(iStack_19d68 + 0xfd0c) == 1) {
    iStack_19d74 = FUN_00572b10();
    while (piStack_19d6c = (int *)FUN_00572b30(&iStack_19d74,0), piStack_19d6c != (int *)0x0) {
      *(ushort *)(piStack_19d6c + 0x11) = *(ushort *)(piStack_19d6c + 0x11) & 0xfffd;
      FUN_00615500();
    }
    FUN_0044c830(auStack_19dac,*(undefined4 *)(iStack_19d68 + 4));
  }
  iStack_19d88 = 0;
  for (iStack_19d70 = 0; iStack_19d70 < 0x2711; iStack_19d70 = iStack_19d70 + 1) {
    aiStack_138b4[iStack_19d70] = 0;
    aiStack_9c64[iStack_19d70] = 0;
  }
  FUN_004b5a50();
  iStack_19d74 = FUN_00572c70();
  do {
    do {
      piStack_19d6c = (int *)FUN_00572cd0(&iStack_19d74,0);
      if (piStack_19d6c == (int *)0x0) {
        FUN_004b7110();
        FUN_004fb9f0();
        FUN_004b5a50();
        iStack_19d74 = FUN_00572c70();
        while ((iStack_19d74 != 0 &&
               (piStack_19d6c = (int *)FUN_00572cd0(&iStack_19d74,0), piStack_19d6c != (int *)0x0)))
        {
          FUN_00574fd0();
          if ((*(int *)(iStack_19d68 + 0xfd64) == 1) || (*(int *)(iStack_19d68 + 0xfd68) == 1)) {
            FUN_00455380();
          }
          if (*(int *)(iStack_19d68 + 0xfd64) == 1) {
            FUN_0040db50();
          }
          if ((*(int *)(iStack_19d68 + 0xfd5c) == 1) && (iVar2 = FUN_0079d98a(), iVar2 == 0)) {
            (**(code **)(*piStack_19d6c + 0x20))();
          }
          if (*(int *)(iStack_19d68 + 0xfd60) == 1) {
            (**(code **)(*piStack_19d6c + 0x24))();
            FUN_00457840(DAT_00a0b424);
            iVar2 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
            if (iVar2 != 0) {
              FUN_00457840();
            }
          }
          if (piStack_19d6c[1] != 0) {
            for (iStack_19d70 = 1; iStack_19d70 <= iStack_19d88; iStack_19d70 = iStack_19d70 + 1) {
              if (aiStack_138b4[iStack_19d70] == piStack_19d6c[1]) {
                if (aiStack_9c64[iStack_19d70] == 0) {
                  if (piStack_19d6c[1] < 0) {
                    iStack_19db4 = -1;
                  }
                  else {
                    iStack_19db4 = 1;
                  }
                  iVar2 = FUN_00479d80();
                  aiStack_9c64[iStack_19d70] = iVar2 * iStack_19db4;
                }
                piStack_19d6c[1] = aiStack_9c64[iStack_19d70];
              }
            }
          }
          if (*(double *)(iStack_19d68 + 0xfcd0) <= 0.0) {
            dStack_19e08 = -*(double *)(iStack_19d68 + 0xfcd0);
          }
          else {
            dStack_19e08 = *(double *)(iStack_19d68 + 0xfcd0);
          }
          if ((1e-07 < dStack_19e08) &&
             ((iVar2 = FUN_0079d98a(), iVar2 != 0 || (iVar2 = FUN_0079d98a(), iVar2 != 0)))) {
            dVar6 = *(double *)(piStack_19d6c + 6) - *(double *)(piStack_19d6c + 2);
            dStack_19e10 = dVar6;
            if (dVar6 <= 0.0) {
              dStack_19e10 = -dVar6;
            }
            if (dStack_19e10 < 1e-08) {
              *(double *)(piStack_19d6c + 2) = dVar6 / 2.0 + *(double *)(piStack_19d6c + 2);
              *(undefined8 *)(piStack_19d6c + 6) = *(undefined8 *)(piStack_19d6c + 2);
            }
            dStack_19d90 = *(double *)(piStack_19d6c + 8) - *(double *)(piStack_19d6c + 4);
            dStack_19e20 = dStack_19d90;
            if (dStack_19d90 <= 0.0) {
              dStack_19e20 = -dStack_19d90;
            }
            if (dStack_19e20 < 1e-08) {
              *(double *)(piStack_19d6c + 4) = dStack_19d90 / 2.0 + *(double *)(piStack_19d6c + 4);
              *(undefined8 *)(piStack_19d6c + 8) = *(undefined8 *)(piStack_19d6c + 4);
            }
          }
          if ((*(int *)(iStack_19d68 + 0xfd08) == 0) || (*(int *)(iStack_19d68 + 0xfd0c) == 1)) {
            FUN_0079d98a();
            FUN_00447670();
            FUN_00447b90(auStack_19dac,2,*(undefined4 *)(iStack_19d68 + 4),piStack_19d6c,1,1);
            *(ushort *)(piStack_19d6c + 0x11) = *(ushort *)(piStack_19d6c + 0x11) | 2;
          }
          else {
            FUN_00447670();
          }
          uStack_13a6c = 1;
        }
        FUN_004b7110();
        *(double *)(iStack_19d68 + 0xfd70) =
             *(double *)(iStack_19d68 + 0xfc78) - *(double *)(iStack_19d68 + 0x228);
        *(double *)(iStack_19d68 + 0xfd78) =
             *(double *)(iStack_19d68 + 0xfc80) - *(double *)(iStack_19d68 + 0x230);
        uStack_13a6c = 0;
        if (*(int *)(iStack_19d68 + 0xfd80) < 1) {
          *(undefined8 *)(iStack_19d68 + 0xfd90) = *(undefined8 *)(iStack_19d68 + 0xfd70);
          *(undefined8 *)(iStack_19d68 + 0xfd98) = *(undefined8 *)(iStack_19d68 + 0xfd78);
          *(undefined8 *)(iStack_19d68 + 0xfda0) = *(undefined8 *)(iStack_19d68 + 0xfcb0);
          *(undefined8 *)(iStack_19d68 + 0xfda8) = *(undefined8 *)(iStack_19d68 + 0xfcc0);
        }
        if (*(int *)(iStack_19d68 + 0xfdb0) < 0) {
          *(undefined4 *)(iStack_19d68 + 0xfdb0) = 0;
        }
        FUN_00408a60();
        FUN_004988c0();
        if (*(int *)(iStack_19d68 + 0xfdb0) < 0xfa1) {
          FUN_004988c0();
        }
        *(int *)(iStack_19d68 + 0xfdb0) = *(int *)(iStack_19d68 + 0xfdb0) + 1;
        if ((*(int *)(iStack_19d68 + 0xfd08) == 0) || (*(int *)(iStack_19d68 + 0xfd0c) == 1)) {
          FUN_004988c0();
          FUN_00517640(*(undefined4 *)(iStack_19d68 + 0xfc78),*(undefined4 *)(iStack_19d68 + 0xfc7c)
                       ,*(undefined4 *)(iStack_19d68 + 0xfc80),
                       *(undefined4 *)(iStack_19d68 + 0xfc84));
          FUN_004988c0();
          FUN_004988c0();
          FUN_004988c0();
          FUN_004988c0();
        }
        else {
          FUN_004b75a0();
          FUN_004988c0();
        }
        if (*(int *)(iStack_19d68 + 0xfdb0) < 0xfa1) {
          FUN_004988c0();
        }
        if (((*(int *)(iStack_19d68 + 0xfd48) == 1) || (0 < *(int *)(iStack_19d68 + 0xfd18))) ||
           (0 < *(int *)(iStack_19d68 + 0xfd40))) {
          if (*(int *)(iStack_19d68 + 0xfd48) != 0) {
            *(undefined8 *)(iStack_19d68 + 0xfcc0) = 0;
            *(undefined8 *)(iStack_19d68 + 0xfcb0) = 0;
          }
          *(undefined4 *)(iStack_19d68 + 0xfd48) = 0;
          *(undefined4 *)(iStack_19d68 + 0xfd18) = 0;
          if (*(int *)(iStack_19d68 + 0xfd40) != 0) {
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(iStack_19d68 + 4) + 0x85f8)) {
              dVar6 = (*(double *)(iStack_19d68 + 0xfcd0) * 180.0) / 3.141592653589793;
              FUN_00404c80(dVar6);
              FUN_004fca20();
              FUN_004ae3f0(dVar6);
            }
            *(undefined4 *)(iStack_19d68 + 0xfd40) = 0;
          }
          *(undefined4 *)(iStack_19d68 + 0xfd80) = 0;
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(iStack_19d68 + 4) + 0x85f8)) {
            lVar8 = (ulonglong)*(uint *)(iStack_19d68 + 0xfdb4) << 0x20;
            FUN_00404c80(0,*(uint *)(iStack_19d68 + 0xfdb4));
            FUN_004fca20();
            FUN_004accf0(lVar8);
            FUN_00404c80();
            FUN_004fca20();
            FUN_007979e8();
            FUN_00404c80();
            FUN_004fca20();
            FUN_007979e8();
          }
        }
        else {
          if (*(int *)(iStack_19d68 + 0xfd80) < 1) {
            *(undefined4 *)(iStack_19d68 + 0xfd80) = 1;
          }
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(iStack_19d68 + 4) + 0x85f8)) {
            FUN_00404c80();
            FUN_004fca20();
            FUN_007979e8();
            FUN_00404c80();
            FUN_004fca20();
            FUN_007979e8();
          }
        }
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(iStack_19d68 + 4) + 0x85f8)) {
          uVar9 = 0;
          uVar7 = 0;
          FUN_00404c80(0,0);
          FUN_004fca20();
          FUN_004ae320(uVar7,uVar9);
        }
        uVar7 = *(undefined8 *)(iStack_19d68 + 0x228);
        uVar9 = *(undefined8 *)(iStack_19d68 + 0x230);
        FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
        iVar2 = FUN_004989a0(uVar7,uVar9);
        if (iVar2 != 0) {
          FUN_004508b0(0x10,auStack_19dac,*(undefined4 *)(iStack_19d68 + 4),
                       *(undefined4 *)(iStack_19d68 + 0x228),*(undefined4 *)(iStack_19d68 + 0x22c),
                       *(undefined4 *)(iStack_19d68 + 0x230),*(undefined4 *)(iStack_19d68 + 0x234),0
                      );
        }
        if (*(int *)(iStack_19d68 + 0xfd08) == 0) {
          FUN_004e1290();
        }
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(iStack_19d68 + 4) + 0x85f8)) {
          uVar7 = *(undefined8 *)(iStack_19d68 + 0xfcc0);
          uVar9 = *(undefined8 *)(iStack_19d68 + 0xfcb0);
          FUN_00404c80(uVar9,uVar7);
          FUN_004fca20();
          FUN_004ae1b0(uVar9,uVar7);
        }
        *(undefined4 *)(iStack_19d68 + 0x210) = 1;
        *(undefined4 *)(iStack_19d68 + 0x21c) = *(undefined4 *)(iStack_19d68 + 0x214);
        *(undefined4 *)(iStack_19d68 + 0x220) = *(undefined4 *)(iStack_19d68 + 0x218);
        FUN_0064f070();
        *(undefined4 *)(iStack_19d68 + 0x208) = 0;
        *(undefined4 *)(iStack_19d68 + 0x204) = 0xffffffff;
        local_8._0_1_ = 3;
        FUN_004640a0();
        local_8._0_1_ = 2;
        FUN_00447100();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00408b00();
        ExceptionList = local_10;
        return;
      }
    } while (piStack_19d6c[1] == 0);
    iStack_19dbc = 0;
    for (iStack_19d70 = 1; iStack_19d70 <= iStack_19d88; iStack_19d70 = iStack_19d70 + 1) {
      if (piStack_19d6c[1] == aiStack_138b4[iStack_19d70]) {
        iStack_19dbc = iStack_19d70;
        break;
      }
    }
    if (iStack_19dbc == 0) {
      if (iStack_19d88 < 10000) {
        iStack_19d88 = iStack_19d88 + 1;
        aiStack_138b4[iStack_19d88] = piStack_19d6c[1];
      }
      else {
        piStack_19d6c[1] = 0;
      }
    }
  } while( true );
}



