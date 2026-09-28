/* CZukeiMoji -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiMoji[1] */
/* 006bb8e0  FUN_006bb8e0  68 bytes, 0 callers */

undefined4 FUN_006bb8e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006bb820();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x9e0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiMoji[6] */
/* 006bc120  FUN_006bc120  4426 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bc120(undefined **param_1)

{
  void *pvVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  double dVar6;
  undefined8 uStack_654c;
  undefined1 *puStack_6544;
  undefined **ppuStack_6540;
  undefined **ppuStack_653c;
  uint uStack_6538;
  int local_650c;
  undefined1 *local_64c4;
  undefined1 *local_64c0;
  undefined1 *local_64bc;
  double local_64b8;
  double local_64b0;
  double local_64a8;
  undefined1 local_64a0 [20];
  undefined **local_648c;
  undefined *local_6488;
  int local_6484;
  undefined **local_6480;
  int local_647c;
  int local_6478;
  int local_6474;
  int local_6470;
  double local_646c;
  double local_6464;
  int local_645c;
  undefined **local_6458;
  undefined1 *local_6454;
  undefined *local_6450;
  undefined4 local_644c;
  int *local_6448;
  undefined1 local_6444 [25552];
  undefined1 local_74 [16];
  undefined1 local_64 [32];
  undefined1 local_44 [16];
  double local_34;
  double local_2c;
  undefined8 local_24;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  pvVar1 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093cf57;
  local_10 = ExceptionList;
  uStack_6538 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6470 = DAT_00a0ba70;
  DAT_00a0ba70 = 0;
  local_647c = in_ECX[0xae];
  in_ECX[0xae] = 0;
  if ((in_ECX[0xa8] != *(int *)(in_ECX[1] + 0x256c)) ||
     (in_ECX[0xa9] != *(int *)(in_ECX[1] + 0x24ec + *(int *)(in_ECX[1] + 0x256c) * 4))) {
    local_6470 = 1;
    in_ECX[0xa8] = *(int *)(in_ECX[1] + 0x256c);
    in_ECX[0xa9] = *(int *)(in_ECX[1] + 0x24ec + *(int *)(in_ECX[1] + 0x256c) * 4);
  }
  *(undefined4 *)(in_ECX[1] + 0x8ebc) = 0;
  local_14 = uStack_6538;
  if (in_ECX[0x8c] != 0) {
    *(undefined4 *)in_ECX[2] = 8;
    ppuStack_653c = param_1;
    ppuStack_6540 = (undefined **)0x6bc266;
    FUN_006f7cc0();
    ExceptionList = local_10;
    return;
  }
  if (in_ECX[0x8a] != 0) {
    ExceptionList = pvVar1;
    return;
  }
  if (in_ECX[0x8d] != 0) {
    ppuStack_653c = param_1;
    ppuStack_6540 = (undefined **)0x6bc29d;
    FUN_006bdcb0();
    ExceptionList = local_10;
    return;
  }
  local_6448 = in_ECX;
  if (in_ECX[0xab] != 0) {
    in_ECX[0xab] = 0;
    ppuStack_653c = (undefined **)0x0;
    ppuStack_6540 = (undefined **)0x0;
    puStack_6544 = (undefined1 *)0x270f;
    uStack_654c = 2.1217839403069e-310;
    puVar3 = (undefined4 *)FUN_0041c8d0();
    puStack_6544 = (undefined1 *)puVar3[1];
    uStack_654c = (double)CONCAT44(*puVar3,0x14cc);
    FUN_005168b0();
  }
  if (local_6448[0x172] != local_6448[0x171]) {
    local_6448[0x172] = local_6448[0x171];
    ppuStack_653c = (undefined **)local_6448[0x171];
    ppuStack_6540 = (undefined **)0x6bc338;
    FUN_00404c80();
    ppuStack_6540 = (undefined **)0x6bc33f;
    FUN_004fca20();
    ppuStack_6540 = (undefined **)0x6bc34a;
    FUN_005818d0();
  }
  if ((local_6470 != 0) || (local_647c != 0)) {
    ppuStack_653c = (undefined **)0x6bc361;
    FUN_00404c80();
    ppuStack_653c = (undefined **)0x6bc368;
    iVar4 = FUN_004fca20();
    if (*(int *)(iVar4 + 0x1a0) == *(int *)(local_6448[1] + 0x8600)) {
      ppuStack_653c = (undefined **)0x6bc395;
      (**(code **)(*local_6448 + 0x80))();
    }
  }
  if (((((local_6448[0x98] != DAT_00a0b4e8) || (*(double *)(local_6448 + 0x9a) != DAT_00a0b4a8)) ||
       (*(double *)(local_6448 + 0x9c) != DAT_00a0b4b8)) ||
      ((*(double *)(local_6448 + 0x9e) != DAT_00a0b4c8 ||
       ((undefined **)local_6448[0xa0] != _DAT_00a0b4e0)))) &&
     (*(int *)(local_6448[1] + 0x17d8) == 0x8026)) {
    ppuStack_653c = _DAT_00a0b4e0;
    puStack_6544 = SUB84(DAT_00a0b4c8,0);
    ppuStack_6540 = (undefined **)((ulonglong)DAT_00a0b4c8 >> 0x20);
    uStack_654c = DAT_00a0b4b8;
    iVar4 = DAT_00a0b4e8;
    dVar6 = DAT_00a0b4a8;
    FUN_00404c80(DAT_00a0b4e8,DAT_00a0b4a8);
    FUN_004fca20();
    FUN_00583240(iVar4,dVar6);
    local_6448[0x98] = DAT_00a0b4e8;
    *(double *)(local_6448 + 0x9a) = DAT_00a0b4a8;
    *(double *)(local_6448 + 0x9c) = DAT_00a0b4b8;
    *(double *)(local_6448 + 0x9e) = DAT_00a0b4c8;
    local_6448[0xa0] = (int)_DAT_00a0b4e0;
  }
  ppuStack_653c = (undefined **)0x6bc4f3;
  FUN_00446aa0();
  local_8 = 0;
  ppuStack_653c = (undefined **)local_6448[1];
  ppuStack_6540 = (undefined **)0x6bc50f;
  FUN_0079dea2();
  local_8 = CONCAT31(local_8._1_3_,1);
  ppuStack_653c = (undefined **)0x6bc521;
  local_644c = FUN_0040c0e0();
  local_646c = 0.0;
  local_6464 = 0.0;
  local_6458 = (undefined **)0x0;
  ppuStack_653c = (undefined **)local_6448[1];
  ppuStack_6540 = (undefined **)local_64a0;
  puStack_6544 = (undefined1 *)0x6bc563;
  FUN_0044dd90();
  ppuStack_653c = (undefined **)(local_6448[1] + 0x8d10);
  ppuStack_6540 = (undefined **)&DAT_00956338;
  puStack_6544 = (undefined1 *)0x6bc57d;
  cVar2 = FUN_004640c0();
  if (cVar2 != '\0') {
    ppuStack_653c = (undefined **)local_6448[1];
    ppuStack_6540 = (undefined **)local_64a0;
    puStack_6544 = (undefined1 *)0x6bc5a3;
    FUN_0044c830();
    ppuStack_653c = (undefined **)0x6bc5b6;
    (**(code **)(*local_6448 + 0x78))();
    ppuStack_653c = (undefined **)&DAT_00956338;
    ppuStack_6540 = (undefined **)0x6bc5cf;
    FUN_00404900();
  }
  if (local_6448[0x178] != 0) {
    ppuStack_653c = (undefined **)0x0;
    ppuStack_6540 = (undefined **)0x0;
    puStack_6544 = (undefined1 *)0x1513;
    uStack_654c = (double)CONCAT44(0x6bc5f5,(undefined4)uStack_654c);
    FUN_004efbb0();
    if (0 < *(int *)(local_6448[1] + 0x8eb4)) {
      ppuStack_653c = (undefined **)0x0;
      ppuStack_6540 = (undefined **)0x0;
      puStack_6544 = (undefined1 *)local_6448[0x7f];
      local_64c4 = (undefined1 *)&uStack_654c;
      uStack_654c = (double)CONCAT44(local_6448[0x7e],local_6448[0x7e]);
      FUN_00403dd0();
      FUN_00516ac0();
    }
    local_8 = local_8 & 0xffffff00;
    ppuStack_653c = (undefined **)0x6bc657;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    ppuStack_653c = (undefined **)0x6bc669;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  if (local_6448[0x171] != 0) {
    ppuStack_653c = param_1;
    ppuStack_6540 = (undefined **)(local_6448 + 0xf6);
    puStack_6544 = (undefined1 *)0x6bc698;
    FUN_006c6890();
  }
  local_6448[0x88] = 0;
  ppuStack_653c = (undefined **)0x6bc6b3;
  iVar4 = FUN_00573cb0();
  if (iVar4 == 0) {
    ppuStack_653c = (undefined **)(local_6448 + 0xf6);
    ppuStack_6540 = (undefined **)0x6bc6d9;
    FUN_00481070();
    ppuStack_653c = (undefined **)0x6bc6e4;
    FUN_006bbe60();
    ppuStack_653c = (undefined **)0x6bc6ec;
    FUN_00408a60();
    local_34 = *(double *)(local_6448 + 0x80) - *(double *)(local_6448 + 0x84);
    local_2c = *(double *)(local_6448 + 0x82) - *(double *)(local_6448 + 0x86);
    local_646c = local_34 - *(double *)param_1;
    local_6464 = local_2c - *(double *)(param_1 + 2);
  }
  else {
    ppuStack_653c = (undefined **)0x6bc76d;
    iVar4 = FUN_004146c0();
    if (iVar4 == 0) {
      ppuStack_653c = (undefined **)0x6bc786;
      puVar3 = (undefined4 *)FUN_006bda10();
      local_6458 = (undefined **)*puVar3;
      ppuStack_653c = &PTR_s_CDataMoji_009fe108;
      ppuStack_6540 = (undefined **)0x6bc79e;
      iVar4 = FUN_0079d98a();
      if (iVar4 != 0) {
        ppuStack_653c = (undefined **)0x6bc7ab;
        FUN_00404c80();
        ppuStack_653c = (undefined **)0x6bc7b2;
        FUN_004fca20();
        ppuStack_653c = (undefined **)0x6bc7bd;
        fVar5 = (float10)FUN_005836e0();
        local_64a8 = (double)fVar5;
        if (local_64a8 == 0.0) {
          ppuStack_653c = (undefined **)0x6bc7d9;
          FUN_00404c80();
          ppuStack_653c = (undefined **)0x6bc7e0;
          FUN_004fca20();
          ppuStack_653c = (undefined **)0x6bc7eb;
          fVar5 = (float10)FUN_00583710();
          local_64b0 = (double)fVar5;
          if (local_64b0 == 0.0) goto LAB_006bca36;
        }
        if (0 < local_6448[0xb8]) {
          local_6448[0x88] = 1;
          ppuStack_653c = local_6458;
          ppuStack_6540 = (undefined **)0x6bc841;
          FUN_00481070();
          ppuStack_653c = (undefined **)0x6bc849;
          FUN_00408a60();
          ppuStack_653c = (undefined **)0x0;
          puStack_6544 = (undefined1 *)*(undefined8 *)(local_6448 + 0x12a);
          ppuStack_6540 = (undefined **)((ulonglong)*(undefined8 *)(local_6448 + 0x12a) >> 0x20);
          uStack_654c = 0.0;
          puVar3 = (undefined4 *)FUN_00408a30(0);
          uStack_654c = *(double *)(puVar3 + 2);
          FUN_005f89c0(*puVar3,puVar3[1]);
          if (local_650c != 0) {
            ppuStack_653c = (undefined **)0x6bc8b7;
            FUN_00404c80();
            ppuStack_653c = (undefined **)0x6bc8be;
            FUN_004fca20();
            ppuStack_653c = (undefined **)0x6bc8c9;
            fVar5 = (float10)FUN_005836e0();
            local_24 = (double)fVar5;
            ppuStack_653c = (undefined **)0x6bc8d1;
            FUN_00404c80();
            ppuStack_653c = (undefined **)0x6bc8d8;
            FUN_004fca20();
            ppuStack_653c = (undefined **)0x6bc8e3;
            fVar5 = (float10)FUN_00583710();
            local_64b8 = (double)fVar5;
            local_1c = -local_64b8;
            ppuStack_653c = (undefined **)&local_24;
            ppuStack_6540 = (undefined **)0x6bc90c;
            FUN_005f8ce0();
            puStack_6544 = (undefined1 *)local_24._4_4_;
            ppuStack_6540 = (undefined **)(undefined4)local_1c;
            ppuStack_653c = local_1c._4_4_;
            uStack_654c = (double)CONCAT44(SUB84(local_24,0),0x6bc939);
            FUN_00498ac0();
            puStack_6544 = (undefined1 *)local_24._4_4_;
            ppuStack_6540 = (undefined **)(undefined4)local_1c;
            ppuStack_653c = local_1c._4_4_;
            uStack_654c = (double)CONCAT44(SUB84(local_24,0),0x6bc966);
            FUN_00498ac0();
          }
          puStack_6544 = (undefined1 *)local_6448[0xf9];
          ppuStack_6540 = (undefined **)local_6448[0xfa];
          ppuStack_653c = (undefined **)local_6448[0xfb];
          uStack_654c = (double)CONCAT44(local_6448[0xf8],local_44);
          FUN_004988c0();
          ppuStack_653c = (undefined **)(local_6448 + 0xf6);
          ppuStack_6540 = (undefined **)0x6bc9c0;
          FUN_00481070();
          ppuStack_653c = (undefined **)0x6bc9cb;
          FUN_006bbe60();
          local_24 = *(double *)(local_6448 + 0x80) - *(double *)(local_6448 + 0x84);
          local_1c = *(double *)(local_6448 + 0x82) - *(double *)(local_6448 + 0x86);
          local_646c = local_24 - *(double *)param_1;
          local_6464 = local_1c - *(double *)(param_1 + 2);
        }
      }
    }
  }
LAB_006bca36:
  ppuStack_653c = (undefined **)&DAT_00956338;
  ppuStack_6540 = (undefined **)0x6bca46;
  CStringT<>();
  local_8._0_1_ = 2;
  ppuStack_653c = (undefined **)0x1;
  ppuStack_6540 = (undefined **)0x6bca51;
  FUN_00404c80();
  ppuStack_6540 = (undefined **)0x6bca58;
  FUN_004fca20();
  ppuStack_6540 = (undefined **)0x6bca63;
  FUN_005835f0();
  ppuStack_653c = &local_6488;
  ppuStack_6540 = (undefined **)0x6bca6f;
  FUN_00404c80();
  ppuStack_6540 = (undefined **)0x6bca76;
  FUN_004fca20();
  ppuStack_6540 = (undefined **)0x6bca81;
  ppuStack_653c = (undefined **)FUN_00581420();
  local_8._0_1_ = 3;
  ppuStack_6540 = (undefined **)0x6bcaa9;
  local_648c = ppuStack_653c;
  local_6480 = ppuStack_653c;
  FUN_00404860();
  local_8 = CONCAT31(local_8._1_3_,2);
  ppuStack_653c = (undefined **)0x6bcab8;
  FUN_00404540();
  if (DAT_00a0cc64 == 0) {
LAB_006bcb32:
    puStack_6544 = param_1[1];
    ppuStack_6540 = (undefined **)param_1[2];
    ppuStack_653c = (undefined **)param_1[3];
    uStack_654c = (double)CONCAT44(*param_1,local_64);
    FUN_004988c0();
  }
  else {
    ppuStack_653c = (undefined **)0x6bcacc;
    iVar4 = FUN_00573cb0();
    if (((iVar4 == 0) ||
        (9e+20 < *(double *)(local_6448 + 0xb4) || *(double *)(local_6448 + 0xb4) == 9e+20)) ||
       (local_6448[0x88] != 0)) goto LAB_006bcb32;
    puStack_6544 = (undefined1 *)local_6448[0xb5];
    ppuStack_6540 = (undefined **)local_6448[0xb6];
    ppuStack_653c = (undefined **)local_6448[0xb7];
    uStack_654c = (double)CONCAT44(local_6448[0xb4],local_74);
    FUN_004988c0();
  }
  ppuStack_653c = (undefined **)0x6bcb6d;
  FUN_006bd820();
  ppuStack_6540 = &local_6450;
  puStack_6544 = (undefined1 *)0x6bcb82;
  local_64c0 = (undefined1 *)&ppuStack_653c;
  FUN_00403dd0();
  ppuStack_6540 = (undefined **)0x6bcb8d;
  FUN_006c6680();
  ppuStack_653c = (undefined **)0x6bcb92;
  FUN_00404c80();
  ppuStack_653c = (undefined **)0x6bcb99;
  FUN_004fca20();
  ppuStack_653c = (undefined **)0x6bcbaa;
  fVar5 = (float10)FUN_0057fb10();
  *(double *)(local_6448 + 0xf2) = (double)fVar5;
  ppuStack_653c = (undefined **)0x6bcbbb;
  FUN_00404c80();
  ppuStack_653c = (undefined **)0x6bcbc2;
  FUN_004fca20();
  ppuStack_653c = (undefined **)0x6bcbd3;
  fVar5 = (float10)FUN_0057f8b0();
  *(double *)(local_6448 + 0xf4) = (double)fVar5;
  local_64bc = (undefined1 *)&ppuStack_653c;
  ppuStack_6540 = &local_6450;
  puStack_6544 = (undefined1 *)0x6bcbf4;
  FUN_00403dd0();
  ppuStack_6540 = (undefined **)0x6bcbf9;
  local_6484 = FUN_004de160();
  local_6474 = local_6484;
  if ((((*(double *)(local_6448 + 0xf2) != *(double *)(local_6448 + 0xa2)) ||
       (*(double *)(local_6448 + 0xf4) != *(double *)(local_6448 + 0xa4))) ||
      (local_6484 != local_6448[0xa6])) || (local_6448[0x171] != local_6448[0x173])) {
    *(undefined8 *)(local_6448 + 0xa2) = *(undefined8 *)(local_6448 + 0xf2);
    *(undefined8 *)(local_6448 + 0xa4) = *(undefined8 *)(local_6448 + 0xf4);
    local_6448[0xa6] = local_6484;
    local_6448[0x173] = local_6448[0x171];
    ppuStack_653c = (undefined **)local_6448[0x171];
    ppuStack_6540 = (undefined **)0x6bccf8;
    FUN_00404c80();
    ppuStack_6540 = (undefined **)0x6bccff;
    FUN_004fca20();
    ppuStack_6540 = (undefined **)0x6bcd0a;
    FUN_00581900();
    DAT_00a0cc74 = 0;
  }
  ppuStack_653c = (undefined **)0x6bcd19;
  FUN_00404c80();
  ppuStack_653c = (undefined **)0x6bcd20;
  iVar4 = FUN_004fca20();
  local_6454 = *(undefined1 **)(*(int *)(iVar4 + 0x1a0) + 0xcc);
  if ((local_6454 != (undefined1 *)0x0) && (local_6448[0x171] != 1)) {
    ppuStack_653c = (undefined **)0x6bcd55;
    FUN_00464040();
    local_8._0_1_ = 4;
    ppuStack_653c = (undefined **)0x0;
    ppuStack_6540 = (undefined **)0x1;
    puStack_6544 = local_6454;
    uStack_654c = (double)CONCAT44(local_6448 + 0xba,local_6444);
    FUN_004737a0(local_6448[1],local_64a0);
    local_8 = CONCAT31(local_8._1_3_,2);
    ppuStack_653c = (undefined **)0x6bcda3;
    FUN_004640a0();
  }
  ppuStack_653c = (undefined **)(local_6448 + 0xba);
  ppuStack_6540 = (undefined **)local_6448[1];
  puStack_6544 = local_64a0;
  uStack_654c = (double)CONCAT44(0x6bcdcb,(undefined4)uStack_654c);
  FUN_00450b70();
  ppuStack_6540 = (undefined **)*(undefined8 *)(local_6448 + 0x126);
  ppuStack_653c = (undefined **)((ulonglong)*(undefined8 *)(local_6448 + 0x126) >> 0x20);
  puStack_6544 = (undefined1 *)0x6bcdf5;
  local_645c = FUN_004b8250();
  ppuStack_653c = (undefined **)0x6bce06;
  iVar4 = FUN_00573cb0();
  if ((iVar4 == 0) && (local_6448[0x171] != 0)) {
    if (local_645c < 1) {
      local_6478 = -local_645c;
    }
    else {
      local_6478 = local_645c;
    }
    if (local_6478 < DAT_00a0b454) goto LAB_006bce4b;
LAB_006bce5e:
    if (local_6448[0x171] != 2) {
      *(double *)(local_6448 + 0xbc) = *(double *)(local_6448 + 0xbc) + local_646c;
      *(double *)(local_6448 + 0xbe) = *(double *)(local_6448 + 0xbe) + local_6464;
      *(double *)(local_6448 + 0xc0) = *(double *)(local_6448 + 0xc0) + local_646c;
      *(double *)(local_6448 + 0xc2) = *(double *)(local_6448 + 0xc2) + local_6464;
      ppuStack_653c = (undefined **)(local_6448 + 0xba);
      ppuStack_6540 = (undefined **)local_6448[1];
      puStack_6544 = local_64a0;
      uStack_654c = (double)CONCAT44(0x6bcf2a,(undefined4)uStack_654c);
      FUN_00450b70();
      if ((local_6454 != (undefined1 *)0x0) && (local_6448[0x88] == 1)) {
        ppuStack_653c = (undefined **)0x6bcf4d;
        FUN_00464040();
        local_8._0_1_ = 5;
        ppuStack_653c = (undefined **)0x0;
        ppuStack_6540 = (undefined **)0x1;
        puStack_6544 = local_6454;
        uStack_654c = (double)CONCAT44(local_6448 + 0xba,local_6444);
        FUN_004737a0(local_6448[1],local_64a0);
        local_8 = CONCAT31(local_8._1_3_,2);
        ppuStack_653c = (undefined **)0x6bcf9b;
        FUN_004640a0();
      }
      *(double *)(local_6448 + 0xbc) = *(double *)(local_6448 + 0xbc) - local_646c;
      *(double *)(local_6448 + 0xbe) = *(double *)(local_6448 + 0xbe) - local_6464;
      *(double *)(local_6448 + 0xc0) = *(double *)(local_6448 + 0xc0) - local_646c;
      *(double *)(local_6448 + 0xc2) = *(double *)(local_6448 + 0xc2) - local_6464;
    }
  }
  else {
LAB_006bce4b:
    if (local_6448[0x88] != 0) goto LAB_006bce5e;
  }
  *(undefined4 *)(local_6448[1] + 0x8ebc) = 1;
  if ((DAT_00a0cc64 == 0) || (local_6448[0x171] != 0)) {
    ppuStack_653c = &local_6450;
    ppuStack_6540 = (undefined **)&DAT_00956338;
    puStack_6544 = (undefined1 *)0x6bd1a5;
    cVar2 = FUN_00447350();
    if (cVar2 == '\0') {
      ppuStack_653c = (undefined **)0x6bd1cf;
      iVar4 = FUN_00573cb0();
      if (iVar4 == 0) {
        ppuStack_653c = (undefined **)0x0;
        ppuStack_6540 = (undefined **)0x0;
        puStack_6544 = (undefined1 *)0x14c5;
        uStack_654c = (double)CONCAT44(0x6bd1e6,(undefined4)uStack_654c);
        FUN_004efbb0();
      }
      else if (local_6448[0x88] == 0) {
        ppuStack_653c = (undefined **)0x0;
        ppuStack_6540 = (undefined **)0x0;
        puStack_6544 = (undefined1 *)0x14c6;
        uStack_654c = (double)CONCAT44(0x6bd21f,(undefined4)uStack_654c);
        FUN_004efbb0();
      }
      else {
        ppuStack_653c = (undefined **)0x0;
        ppuStack_6540 = (undefined **)0x0;
        puStack_6544 = (undefined1 *)0x14c7;
        uStack_654c = (double)CONCAT44(0x6bd20a,(undefined4)uStack_654c);
        FUN_004efbb0();
      }
    }
    else {
      ppuStack_653c = (undefined **)0x0;
      ppuStack_6540 = (undefined **)0x0;
      puStack_6544 = (undefined1 *)0x14c4;
      uStack_654c = (double)CONCAT44(0x6bd1c2,(undefined4)uStack_654c);
      FUN_004efbb0();
    }
    local_8._0_1_ = 1;
    ppuStack_653c = (undefined **)0x6bd22e;
    FUN_00404540();
    local_8 = (uint)local_8._1_3_ << 8;
    ppuStack_653c = (undefined **)0x6bd23d;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    ppuStack_653c = (undefined **)0x6bd24f;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  if ((local_6448[0x88] == 1) ||
     (*(double *)(local_6448 + 0xb4) <= 9e+20 && *(double *)(local_6448 + 0xb4) != 9e+20)) {
    *(undefined4 *)(local_6448[1] + 0x17f4) = 0;
  }
  else {
    *(undefined4 *)(local_6448[1] + 0x17f4) = 1;
  }
  if ((*(double *)(local_6448 + 0xb4) <= 9e+20) || (local_6448[0x88] != 0)) {
    ppuStack_653c = (undefined **)0x6bd0f4;
    iVar4 = FUN_00573cb0();
    if (iVar4 == 0) {
      ppuStack_653c = (undefined **)0x0;
      ppuStack_6540 = (undefined **)0x0;
      puStack_6544 = (undefined1 *)0x14c5;
      uStack_654c = (double)CONCAT44(0x6bd10b,(undefined4)uStack_654c);
      FUN_004efbb0();
    }
    else {
      if (local_6448[0x88] == 1) {
        ppuStack_653c = &local_6450;
        ppuStack_6540 = (undefined **)&DAT_00956338;
        puStack_6544 = (undefined1 *)0x6bd12d;
        cVar2 = FUN_004640c0();
        if (cVar2 != '\0') {
          ppuStack_653c = (undefined **)0x0;
          ppuStack_6540 = (undefined **)0x0;
          puStack_6544 = (undefined1 *)0x14c7;
          uStack_654c = (double)CONCAT44(0x6bd14a,(undefined4)uStack_654c);
          FUN_004efbb0();
          goto LAB_006bd15f;
        }
      }
      ppuStack_653c = (undefined **)0x0;
      ppuStack_6540 = (undefined **)0x0;
      puStack_6544 = (undefined1 *)0x155b;
      uStack_654c = (double)CONCAT44(0x6bd15f,(undefined4)uStack_654c);
      FUN_004efbb0();
    }
  }
  else {
    ppuStack_653c = (undefined **)0x0;
    ppuStack_6540 = (undefined **)0x0;
    puStack_6544 = (undefined1 *)0x155c;
    uStack_654c = (double)CONCAT44(0x6bd0e7,(undefined4)uStack_654c);
    FUN_004efbb0();
  }
LAB_006bd15f:
  local_8._0_1_ = 1;
  ppuStack_653c = (undefined **)0x6bd16e;
  FUN_00404540();
  local_8 = (uint)local_8._1_3_ << 8;
  ppuStack_653c = (undefined **)0x6bd17d;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  ppuStack_653c = (undefined **)0x6bd18f;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[16] */
/* 006bd270  FUN_006bd270  1445 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006bd270(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
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
  FUN_004fb9f0(local_14);
  if (*(int *)(*(int *)(local_63e8 + 4) + 0x8eb4) < 1) {
    if (*(int *)(local_63e8 + 0x230) == 0) {
      *(undefined4 *)(local_63e8 + 0x224) = 0;
      if (*(int *)(local_63e8 + 0x234) == 0) {
        if (*(int *)(*(int *)(local_63e8 + 4) + 0x17d8) == 0x8026) {
          *(undefined4 *)(local_63e8 + 0x5c4) = 0;
          FUN_00446aa0();
          local_8 = 0;
          FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
          local_8._0_1_ = 1;
          FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
          FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_63fc);
          FUN_00449d60(local_63fc,*(undefined4 *)(local_63e8 + 4),1);
          *(undefined4 *)(local_63e8 + 0x5dc) = 0;
          if (*(int *)(local_63e8 + 0x5e0) == 0) {
            if (*(int *)(local_63e8 + 0x5d4) == 0) {
              if (*(int *)(local_63e8 + 0x5d0) == 0) {
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                cVar1 = FUN_004640c0(&DAT_00956338,*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) + 0x490)
                ;
                if (cVar1 == '\0') {
                  FUN_0040c0e0();
                  if ((((DAT_00a0cc64 != 0) && (iVar3 = FUN_00573cb0(), iVar3 != 0)) &&
                      (*(int *)(local_63e8 + 0x220) == 0)) &&
                     (*(double *)(local_63e8 + 0x2d0) <= 9e+20 &&
                      *(double *)(local_63e8 + 0x2d0) != 9e+20)) {
                    *(undefined8 *)(local_63e8 + 0x2d0) = 0x447e7e4171bf4d3a;
                    local_8 = (uint)local_8._1_3_ << 8;
                    FUN_0079dfff();
                    local_8 = 0xffffffff;
                    FUN_00447100();
                    ExceptionList = local_10;
                    return 1;
                  }
                  *(int *)(local_63e8 + 0x2e0) = *(int *)(local_63e8 + 0x2e0) + -1;
                  *(undefined4 *)(local_63e8 + 0x2b8) = 1;
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                  uVar2 = 0;
                }
                else {
                  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
                  puVar4 = &DAT_00956338;
                  FUN_00404c80(&DAT_00956338);
                  FUN_004fca20();
                  FUN_00404900(puVar4);
                  uVar2 = 0;
                  FUN_00404c80(0);
                  FUN_004fca20();
                  FUN_005835f0(uVar2);
                  *(undefined8 *)(local_63e8 + 0x2d0) = 0x447e7e4171bf4d3a;
                  FUN_00404c80();
                  FUN_004fca20();
                  FUN_00797df8();
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                  uVar2 = 1;
                }
              }
              else {
                *(undefined4 *)(local_63e8 + 0x5d0) = 0;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                uVar2 = 1;
              }
            }
            else {
              FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
              *(undefined4 *)(local_63e8 + 0x5d4) = 0;
              *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
              *(undefined4 *)(local_63e8 + 0x5c4) = 0;
              *(undefined4 *)(local_63e8 + 0x5c8) = 0xffffffff;
              *(undefined4 *)(local_63e8 + 0x5cc) = 0xffffffff;
              *(undefined8 *)(local_63e8 + 0x2d0) = 0x447e7e4171bf4d3a;
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar2 = 1;
            }
          }
          else {
            FUN_00454830(*(undefined4 *)(local_63e8 + 4));
            *(undefined4 *)(local_63e8 + 0x5e0) = 0;
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 1;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = FUN_006bde10();
      }
    }
    else {
      iVar3 = FUN_006f85c0();
      if (iVar3 == 0) {
        if (*(int *)(local_63e8 + 0x228) == 0) {
          *(undefined4 *)(local_63e8 + 0x230) = 0;
          *(undefined4 *)(local_63e8 + 0x224) = 0;
          DAT_00a0d618 = 0;
          FUN_006bb930();
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 1;
      }
    }
  }
  else {
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8eb4) = 0;
    *(undefined4 *)(local_63e8 + 0x224) = 0;
    *(undefined4 *)(local_63e8 + 0x5e0) = 0;
    uVar2 = 1;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiMoji[0] */
/* 006bda00  FUN_006bda00  16 bytes, 0 callers */

undefined ** FUN_006bda00(void)

{
  return &PTR_s_CZukeiMoji_00979b6c;
}




/* vtable slots: CZukeiMoji[23] */
/* 006c0640  FUN_006c0640  496 bytes, 0 callers */

undefined4 FUN_006c0640(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x230) == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if ((*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8600)) &&
       (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026)) {
      if (DAT_00a0cc6c == 0) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x9f8) == 0) {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x9fc) == 0) {
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9f8) = 1;
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9fc) = 0;
          }
          else {
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9f8) = 0;
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9fc) = 0;
          }
        }
        else {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9f8) = 0;
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9fc) = 1;
        }
      }
      else {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x9f8) == 0) {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9f8) = 1;
        }
        else {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9f8) = 0;
        }
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x9fc) = 0;
      }
      uVar1 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_005835f0(uVar1);
      FUN_00404c80();
      FUN_0056d7d0();
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




/* vtable slots: CZukeiMoji[46] */
/* 006c0830  FUN_006c0830  2998 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006c0830(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  int *in_ECX;
  float10 fVar5;
  double dVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_6404;
  undefined4 local_6400;
  int local_63fc;
  int *local_63f8;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d22b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (DAT_00a0c7c0 == 0) {
    if (in_ECX[0x8c] == 0) {
      if (in_ECX[0x8d] == 0) {
        local_63f8 = in_ECX;
        FUN_00446aa0(uVar1);
        local_8 = 0;
        FUN_0079dea2(local_63f8[1]);
        local_8._0_1_ = 1;
        FUN_0040c0e0();
        FUN_00404c80();
        iVar3 = FUN_004fca20();
        if (*(int *)(iVar3 + 0x1a0) == *(int *)(local_63f8[1] + 0x8600)) {
          if (((*(int *)(local_63f8[1] + 0x9078) == 0) && (DAT_00a0dbc6 == 4)) &&
             (local_63f8[0x171] != 0)) {
            local_6404 = -1;
            iVar3 = FUN_00778a40(0x15,&local_6404,*(undefined4 *)(local_63f8[1] + 0x9070),param_1,
                                 param_2,param_3,param_4,param_5,param_6,param_7,5);
            if (iVar3 != 0) {
              if (param_3 == 1) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return 0;
              }
              if (param_3 != 2) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return 0;
              }
              if ((-1 < local_6404) && (local_6404 < 4)) {
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                *(int *)(*(int *)(iVar3 + 0x1a0) + 0x270) = local_6404;
                FUN_00404c80();
                FUN_004fca20();
                FUN_00581470();
              }
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 0;
            }
          }
          if ((*(int *)(local_63f8[1] + 0x9078) == 0) && (param_2 < 0xd)) {
            local_63fc = -1;
            iVar3 = FUN_00778a40(0xb,&local_63fc,*(undefined4 *)(local_63f8[1] + 0x9070),param_1,
                                 param_2,param_3,param_4,param_5,param_6,param_7,5);
            if (iVar3 != 0) {
              if (param_3 == 1) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return 0;
              }
              if (param_3 != 2) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return 0;
              }
              if ((-1 < local_63fc) && (local_63fc < 0xb)) {
                DAT_00a0b4e8 = local_63fc;
                uVar2 = (&DAT_00a0b918)[local_63fc];
                uVar9 = (undefined4)(&DAT_00a0b7b8)[local_63fc];
                uVar10 = (undefined4)((ulonglong)(&DAT_00a0b7b8)[local_63fc] >> 0x20);
                uVar8 = (&DAT_00a0b658)[local_63fc];
                uVar7 = (&DAT_00a0b4f8)[local_63fc];
                iVar3 = local_63fc;
                FUN_00404c80(local_63fc,uVar7,uVar8,uVar9,uVar10,uVar2);
                FUN_004fca20();
                FUN_00583240(iVar3,uVar7,uVar8,uVar9,uVar10,uVar2);
                (**(code **)(*local_63f8 + 0x80))();
              }
              if (local_63fc == 0xb) {
                FUN_00404c80();
                FUN_004fca20();
                FUN_006cb000();
              }
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 0;
            }
          }
        }
        if (*(int *)(local_63f8[1] + 0x8588) == 0) {
          local_6400 = 0;
          if (*(int *)(local_63f8[1] + 0x9078) == 0) {
            if (param_2 == 4) {
              if (param_3 == 1) {
                FUN_005168b0(0x141c,*(undefined4 *)(local_63f8[1] + 0x8f50),
                             *(undefined4 *)(local_63f8[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                (**(code **)(*local_63f8 + 0x6c))();
                FUN_004988c0(local_24,param_4,param_5,param_6,param_7);
                FUN_0040c9d0();
                *(undefined4 *)(local_63f8[2] + 4) = 1;
              }
            }
            else if (param_2 == 5) {
              if (param_3 == 1) {
                FUN_005168b0(0x272b,*(undefined4 *)(local_63f8[1] + 0x8f50),
                             *(undefined4 *)(local_63f8[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                local_6400 = FUN_006c01e0();
              }
            }
            else if (param_2 == 0xc) {
              local_6400 = FUN_006bfd50(param_4,param_5,param_6,param_7,param_3);
            }
            else {
              local_6400 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
            }
          }
          else {
            switch(param_2) {
            case 1:
              if (param_3 == 1) {
                FUN_005168b0(0x17d7,*(undefined4 *)(local_63f8[1] + 0x8f50),
                             *(undefined4 *)(local_63f8[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                puVar4 = (uint *)(*(int *)(iVar3 + 0x1a0) + 0x9f8);
                *puVar4 = *puVar4 ^ 1;
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0x9fc) = 0;
                FUN_00404c80();
                FUN_004fca20();
                FUN_00581890();
              }
              break;
            case 2:
              if (param_3 == 1) {
                FUN_005168b0(0x17d8,*(undefined4 *)(local_63f8[1] + 0x8f50),
                             *(undefined4 *)(local_63f8[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0x9f8) = 0;
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                puVar4 = (uint *)(*(int *)(iVar3 + 0x1a0) + 0x9fc);
                *puVar4 = *puVar4 ^ 1;
                FUN_00404c80();
                FUN_004fca20();
                FUN_00581890();
              }
              break;
            case 3:
              if (param_3 == 1) {
                FUN_005168b0(0x17e0,*(undefined4 *)(local_63f8[1] + 0x8f50),
                             *(undefined4 *)(local_63f8[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0x9f8) = 0;
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0x9fc) = 0;
                FUN_00404c80();
                FUN_004fca20();
                FUN_00581890();
              }
              break;
            default:
              local_6400 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
              break;
            case 5:
              if (param_3 == 1) {
                FUN_005168b0(0x17f6,*(undefined4 *)(local_63f8[1] + 0x8f50),
                             *(undefined4 *)(local_63f8[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                local_6400 = FUN_006bf710();
              }
              break;
            case 0xc:
              if (param_3 == 1) {
                FUN_005168b0(0x1810,*(undefined4 *)(local_63f8[1] + 0x8f50),
                             *(undefined4 *)(local_63f8[1] + 0x8f54),1,0);
              }
              else if (param_3 == 2) {
                FUN_00404c80();
                FUN_004fca20();
                fVar5 = (float10)FUN_0058cc80();
                dVar6 = -(double)fVar5;
                FUN_00404c80(uVar1,dVar6);
                iVar3 = FUN_004fca20();
                *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0x9f8) = 0;
                FUN_00404c80();
                iVar3 = FUN_004fca20();
                *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0x9fc) = 0;
                FUN_00404c80();
                FUN_004fca20();
                FUN_00581890();
                uVar2 = SUB84(dVar6,0);
                uVar9 = (undefined4)((ulonglong)dVar6 >> 0x20);
                FUN_00404c80(uVar2,uVar9);
                FUN_004fca20();
                FUN_00583200(uVar2,uVar9);
              }
            }
          }
          uVar2 = local_6400;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          uVar2 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
      else {
        uVar2 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
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
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    uVar2 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiMoji[47] */
/* 006c1410  FUN_006c1410  1742 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006c1410(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  undefined1 *puVar5;
  undefined1 local_c800 [20];
  undefined4 local_c7ec;
  undefined4 local_c7e8;
  undefined1 local_c7e4 [4];
  undefined4 local_c7e0;
  undefined4 local_c7dc;
  undefined4 local_c7d8;
  undefined4 local_c7d4;
  undefined4 local_c7d0;
  undefined4 local_c7cc;
  undefined4 local_c7c8;
  uint local_c7c4;
  char local_c7bd;
  int local_c7bc;
  int *local_c7b8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d286;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_c7c4 = 0;
  if (DAT_00a0c7c0 != 0) {
    uVar2 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    ExceptionList = local_10;
    return uVar2;
  }
  if (in_ECX[0x8c] != 0) {
    if ((*(int *)(in_ECX[1] + 0x907c) == 0) && (param_2 == 0xc)) {
      if (param_3 == 1) {
        FUN_005168b0(0x147c,*(undefined4 *)(in_ECX[1] + 0x8f50),*(undefined4 *)(in_ECX[1] + 0x8f54),
                     1,0);
      }
      else if (param_3 == 2) {
        (**(code **)(*in_ECX + 0x88))();
      }
      ExceptionList = local_10;
      return 0;
    }
    uVar2 = FUN_006fa580(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    ExceptionList = local_10;
    return uVar2;
  }
  local_c7b8 = in_ECX;
  if (*(int *)(in_ECX[1] + 0x907c) != 0) goto LAB_006c1a4b;
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_c7bc = -1;
  iVar3 = FUN_00778a40(0xc,&local_c7bc,*(undefined4 *)(local_c7b8[1] + 0x9074),param_1,param_2,
                       param_3,param_4,param_5,param_6,param_7,5);
  if (iVar3 != 0) {
    if (param_3 == 1) {
      local_c7cc = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_c7cc;
    }
    if (param_3 != 2) {
      local_c7d0 = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_c7d0;
    }
    if ((local_c7bc < 0) || (9 < local_c7bc)) {
      local_c7d4 = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_c7d4;
    }
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    if (*(int *)(iVar3 + 0x1a0) == *(int *)(local_c7b8[1] + 0x8614)) {
      if (local_c7bc < 9) {
        iVar4 = local_c7bc % 3;
        FUN_00404c80();
        iVar3 = FUN_004fca20();
        *(int *)(*(int *)(iVar3 + 0x1a0) + 0xd4) = iVar4;
        iVar3 = local_c7bc / 3;
        FUN_00404c80();
        iVar4 = FUN_004fca20();
        *(int *)(*(int *)(iVar4 + 0x1a0) + 0xd8) = iVar3;
        local_c7b8[0xac] = local_c7bc % 3;
        local_c7b8[0xad] = local_c7bc / 3;
        FUN_006bda50();
      }
      else {
        (**(code **)(*local_c7b8 + 0x74))();
      }
      local_c7d8 = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_c7d8;
    }
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    if (*(int *)(iVar3 + 0x1a0) == *(int *)(local_c7b8[1] + 0x8600)) {
      if (local_c7bc < 9) {
        iVar4 = local_c7bc % 3;
        FUN_00404c80();
        iVar3 = FUN_004fca20();
        *(int *)(*(int *)(iVar3 + 0x1a0) + 0x274) = iVar4;
        iVar3 = local_c7bc / 3;
        FUN_00404c80();
        iVar4 = FUN_004fca20();
        *(int *)(*(int *)(iVar4 + 0x1a0) + 0x278) = iVar3;
        FUN_00404c80();
        FUN_004fca20();
        FUN_00581550();
      }
      else {
        FUN_00404c80();
        FUN_004fca20();
        FUN_006cb020();
      }
      (**(code **)(*local_c7b8 + 0x80))();
      local_c7dc = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_c7dc;
    }
  }
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) == *(int *)(local_c7b8[1] + 0x8600)) {
    if ((DAT_00a0cc64 == 0) && (param_2 == 0xc)) {
      puVar5 = local_c7e4;
      FUN_00404c80(puVar5);
      FUN_004fca20();
      local_c7e0 = FUN_00581420(puVar5);
      local_c7c4 = local_c7c4 | 1;
      cVar1 = FUN_00447350(&DAT_00956338,local_c7e0);
      if (cVar1 == '\0') goto LAB_006c18e4;
      local_c7c8 = 1;
    }
    else {
LAB_006c18e4:
      local_c7c8 = 0;
    }
    local_c7bd = (char)local_c7c8;
    if ((local_c7c4 & 1) != 0) {
      local_c7c4 = local_c7c4 & 0xfffffffe;
      FUN_00404540();
    }
    if (local_c7bd != '\0') {
      if (param_3 == 1) {
        FUN_005168b0(0x1686,*(undefined4 *)(local_c7b8[1] + 0x8f50),
                     *(undefined4 *)(local_c7b8[1] + 0x8f54),1,0);
      }
      else if (param_3 == 2) {
        FUN_00446aa0();
        local_8._0_1_ = 1;
        FUN_0079dea2(local_c7b8[1]);
        local_8 = CONCAT31(local_8._1_3_,2);
        iVar3 = FUN_004500e0(1,local_c7b8[1],&param_4,&local_c7e8,0);
        if (iVar3 != 0) {
          FUN_0044b2c0(local_c800,local_c7b8[1],local_c7e8,1);
        }
        (**(code **)(*local_c7b8 + 0x80))();
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
      }
      local_c7ec = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_c7ec;
    }
  }
  local_8 = 0xffffffff;
  FUN_00447100();
LAB_006c1a4b:
  if (local_c7b8[0x8d] == 0) {
    uVar2 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar2 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiMoji[34] */
/* 006c1e50  FUN_006c1e50  797 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c1e50(void)

{
  int iVar1;
  int *in_ECX;
  undefined1 local_6414 [20];
  int local_6400;
  int local_63fc;
  int local_63f8;
  undefined4 local_63f4;
  int local_63f0;
  int *local_63ec;
  int *local_63e8;
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
  if (in_ECX[0x8d] == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(local_63e8[1]);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0044dd90(local_6414,local_63e8[1]);
    FUN_0044dd20(local_6414,local_63e8[1]);
    FUN_0044de00(local_6414,local_63e8[1]);
    local_63e8[0x8c] = 0;
    DAT_00a0d618 = 0;
    if (local_63e8[0x8a] == 0) {
      FUN_006bb930();
    }
    local_63f4 = FUN_0040c0e0();
    local_63f0 = FUN_00572b10();
    while (local_63f0 != 0) {
      local_6400 = local_63f0;
      local_63ec = (int *)FUN_00572b30(&local_63f0,0);
      if (local_63ec == (int *)0x0) break;
      iVar1 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
      if (iVar1 == 0) {
        FUN_00574f40(local_6400);
        local_63f8 = local_63e8[1];
        if (local_63f8 == 0) {
          local_63fc = 0;
        }
        else {
          local_63fc = local_63f8 + 0x88;
        }
        (**(code **)(*local_63ec + 0x3c))(local_6414,local_63fc,local_63e4);
        *(undefined1 *)((int)local_63ec + 0x5a) = 0;
        *(ushort *)(local_63ec + 0x11) = *(ushort *)(local_63ec + 0x11) & 0xfffd;
      }
      else {
        local_63e8[0x175] = 1;
      }
    }
    if (local_63e8[0x175] == 0) {
      local_63e8[0x176] = 1;
    }
    else {
      local_63e8[0x176] = 0;
    }
    *(undefined4 *)(local_63e8[1] + 0x8560) = 0;
    local_63e8[0x171] = 0;
    local_63e8[0x172] = -1;
    local_63e8[0x173] = -1;
    FUN_00404c80();
    FUN_0056d7d0();
    if ((local_63e8[0x89] != 0) || (local_63e8[0x8a] == 1)) {
      (**(code **)(*local_63e8 + 0x70))();
      local_63e8[0x89] = 0;
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[35] */
/* 006c2170  FUN_006c2170  666 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c2170(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 *puVar5;
  undefined4 uVar6;
  int local_6408;
  undefined1 local_6400 [4];
  int local_63fc;
  int local_63f8;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d32b;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_00446aa0(uVar2);
  local_8 = 0;
  local_63f8 = DAT_00a0b410;
  FUN_0040c0e0();
  puVar5 = local_6400;
  FUN_00404c80(puVar5);
  FUN_004fca20();
  FUN_00581420(puVar5);
  local_8 = CONCAT31(local_8._1_3_,1);
  if ((*(int *)(*(int *)((int)ThreadLocalStoragePointer + _tls_index * 4) + 4) < DAT_00a10400) &&
     (FUN_008d9469(&DAT_00a10400), DAT_00a10400 == -1)) {
    CStringT<>();
    _atexit(FUN_00953950);
    FUN_008d941f(&DAT_00a10400);
  }
  cVar1 = FUN_00408c80(&DAT_00a103fc,local_6400);
  if (cVar1 != '\0') {
    DAT_00a103f8 = 0;
  }
  FUN_00404860(local_6400);
  if (DAT_00a103f8 == 0) {
    DAT_00a103f8 = FUN_00572030();
  }
  do {
    do {
      local_63fc = FUN_00572100(&DAT_00a103f8);
      if (local_63fc == 0) {
        FUN_005168b0(0x279e,*(undefined4 *)(in_ECX + 0x1f8),*(undefined4 *)(in_ECX + 0x1fc),0,0);
        DAT_00a103f8 = 0;
        goto LAB_006c23d0;
      }
      if (local_63f8 == 0) {
        local_6408 = 0;
      }
      else {
        local_6408 = local_63f8 + 0x88;
      }
      iVar3 = FUN_0042dc40(local_6408);
    } while ((iVar3 != 0) || (iVar3 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108), iVar3 == 0));
    uVar6 = 0;
    uVar4 = FUN_00404920(0,uVar2,local_63fc);
    iVar3 = FUN_00429b90(uVar4,uVar6);
  } while (iVar3 < 0);
  FUN_004988c0(local_24,*(undefined4 *)(local_63fc + 8),*(undefined4 *)(local_63fc + 0xc),
               *(undefined4 *)(local_63fc + 0x10),*(undefined4 *)(local_63fc + 0x14));
  FUN_0044fc20(1);
LAB_006c23d0:
  local_8 = local_8 & 0xffffff00;
  FUN_00404540();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[25] */
/* 006c2410  FUN_006c2410  689 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c2410(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_c7fc [20];
  undefined1 local_c7e8 [20];
  int local_c7d4;
  int local_c7d0;
  int local_c7cc;
  int local_c7c8;
  undefined4 local_c7c4;
  int local_c7c0;
  int local_c7bc;
  int local_c7b8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d391;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x230) == 0) {
    local_c7b8 = in_ECX;
    if (*(int *)(in_ECX + 0x234) == 0) {
      if ((*(int *)(in_ECX + 0x5c4) == 0) && (DAT_00a0bbb0 != 0)) {
        FUN_00404c80(local_14);
        FUN_004fca20();
        local_c7d0 = FUN_006cafc0();
        FUN_00404c80();
        FUN_004fca20();
        local_c7cc = FUN_006cafe0();
        local_c7d4 = local_c7d0 + 1 + local_c7cc * 3;
        local_c7c8 = 0;
        local_c7c4 = FUN_0040c0e0();
        local_c7c0 = FUN_00572b10();
        while ((local_c7c0 != 0 && (local_c7bc = FUN_00572b30(&local_c7c0,0), local_c7bc != 0))) {
          iVar1 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
          if (iVar1 != 0) {
            *(undefined1 *)(local_c7bc + 0x28) = (undefined1)local_c7d4;
            local_c7c8 = 1;
          }
        }
        FUN_00446aa0();
        local_8 = 2;
        FUN_0079dea2(*(undefined4 *)(local_c7b8 + 4));
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0044c830(local_c7fc,*(undefined4 *)(local_c7b8 + 4));
        if (local_c7c8 != 0) {
          FUN_005168b0(0x1817,*(undefined4 *)(local_c7b8 + 0x1f8),
                       *(undefined4 *)(local_c7b8 + 0x1fc),0,0);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(local_c7b8 + 4));
      local_8._0_1_ = 1;
      FUN_0044dd90(local_c7e8,*(undefined4 *)(local_c7b8 + 4));
      *(undefined4 *)(local_c7b8 + 0x234) = 0;
      FUN_006bb930();
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[26] */
/* 006c26d0  FUN_006c26d0  398 bytes, 0 callers */

void FUN_006c26d0(void)

{
  int iVar1;
  int in_ECX;
  double dVar2;
  undefined8 uVar3;
  double local_18;
  
  if (*(int *)(in_ECX + 0x230) == 0) {
    if (*(int *)(in_ECX + 0x234) == 0) {
      if (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026) {
        *(undefined4 *)(in_ECX + 0x5e0) = 1;
        FUN_006c4400();
        if (DAT_00a0b488 <= 0.0) {
          local_18 = -DAT_00a0b488;
        }
        else {
          local_18 = DAT_00a0b488;
        }
        if (0.01 <= local_18) {
          dVar2 = DAT_00a0b488;
          uVar3 = DAT_00a0b490;
          FUN_00404c80(DAT_00a0b488,DAT_00a0b490);
          FUN_004fca20();
          FUN_0058ae50(dVar2,uVar3);
        }
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8600)) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_007979e8();
        }
        FUN_00404c80();
        FUN_0056d7d0();
      }
    }
    else if (*(int *)(in_ECX + 0x234) == 2) {
      *(undefined4 *)(in_ECX + 0x234) = 3;
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else if (*(int *)(in_ECX + 0x234) == 3) {
      *(undefined4 *)(in_ECX + 0x234) = 2;
      FUN_00404c80();
      FUN_0056d7d0();
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiMoji[27] */
/* 006c2860  FUN_006c2860  90 bytes, 0 callers */

void FUN_006c2860(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x230) == 0) {
    if (*(int *)(in_ECX + 0x234) == 0) {
      *(undefined4 *)(in_ECX + 0x230) = 1;
      DAT_00a0d618 = 1;
      FUN_006bb930();
      FUN_00404c80();
      FUN_0056d7d0();
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiMoji[28] */
/* 006c28c0  FUN_006c28c0  1797 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x006c2ab5) */

void FUN_006c28c0(void)

{
  void **ppvVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  float10 fVar5;
  double local_1800;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_17f4 [4];
  undefined4 local_17f0;
  undefined4 local_17ec;
  double local_17e8;
  int local_17e0;
  int local_17dc;
  int local_17d8;
  undefined4 local_17d4;
  int local_17d0;
  int local_17cc;
  undefined1 local_17c8 [8];
  undefined4 local_17c0;
  FILE *local_17bc;
  int *local_17b8;
  undefined1 local_17b4 [2016];
  undefined1 *local_fd4;
  wchar_t *pwStack_fd0;
  undefined4 uStack_fcc;
  undefined1 local_fc4 [2008];
  wchar_t local_7ec [9];
  undefined1 local_7da [1990];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d3ff;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (DAT_00a0b458 == 0) {
    local_17c0 = 8;
  }
  else {
    local_17c0 = 1;
  }
  local_14 = uVar2;
  if (in_ECX[0x8c] == 0) {
    if (in_ECX[0x8d] == 0) {
      ppvVar1 = &local_10;
      local_17b8 = in_ECX;
      if (in_ECX[0x8a] == 0) {
        if (*(int *)(in_ECX[1] + 0x17d8) != 0x8026) {
          return;
        }
        ExceptionList = &local_10;
        FUN_00404c80(uVar2);
        iVar3 = FUN_004fca20();
        ppvVar1 = ExceptionList;
        if (*(int *)(iVar3 + 0x1a0) == *(int *)(local_17b8[1] + 0x8600)) {
          FUN_00404c80();
          FUN_004fca20();
          fVar5 = (float10)FUN_00583710();
          local_17e8 = (double)fVar5;
          local_1800 = local_17e8;
          if (local_17e8 <= 0.0) {
            local_1800 = -local_17e8;
          }
          ppvVar1 = ExceptionList;
          if (0.1 <= local_1800) {
            DAT_00a0b488 = local_17e8;
          }
        }
      }
      ExceptionList = ppvVar1;
      local_17d4 = FUN_0040c0e0();
      iVar3 = FUN_00572b10();
      if (iVar3 == 0) {
        local_17b8[0x89] = 1;
        (**(code **)(*local_17b8 + 0x6c))();
      }
      else {
        CStringT<>(L"TEMP.TXT");
        local_8 = 0;
        uVar4 = FUN_00404920(&DAT_00966110,&local_17c0);
        local_17bc = (FILE *)FUN_004f4290(uVar4);
        if (local_17bc == (FILE *)0x0) {
          local_17bc = (FILE *)0x0;
          FUN_005168b0(0x1515,local_17b8[0x7e],local_17b8[0x7f],0,0);
          local_8 = 0xffffffff;
          FUN_00404540();
        }
        else {
          _eh_vector_constructor_iterator_(local_17b4,4,0x1f8,CStringT<>,FUN_00404540);
          local_8 = CONCAT31(local_8._1_3_,1);
          local_17cc = 0;
          FUN_0057a7d0();
          local_17d8 = FUN_00572b10();
          while ((local_17d8 != 0 &&
                 (iVar3 = local_17d8, local_17dc = FUN_00572b30(&local_17d8,0), local_17dc != 0))) {
            iVar3 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108,uVar2,iVar3);
            if (iVar3 != 0) {
              CStringT<>();
              local_8._0_1_ = 2;
              local_17f0 = ATL::operator+(local_17f4,(wchar_t *)(local_17dc + 0xb0));
              local_8._0_1_ = 3;
              local_17ec = local_17f0;
              FUN_00404860(local_17f0);
              local_8 = CONCAT31(local_8._1_3_,2);
              FUN_00404540();
              uVar4 = GetBuffer();
              FUN_004f0830(local_17bc,uVar4,local_17c0);
              ReleaseBuffer(0xffffffff);
              if (local_17b8[0x8b] != 0) {
                FUN_00404860(local_17c8);
                local_17cc = local_17cc + 1;
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              FUN_00404540();
            }
          }
          _fclose(local_17bc);
          if (local_17b8[0x8b] == 0) {
            iVar3 = FUN_004f1700(1);
            if (iVar3 == 0) {
              local_8 = local_8 & 0xffffff00;
              _eh_vector_destructor_iterator_(local_17b4,4,0x1f8,FUN_00404540);
              local_8 = 0xffffffff;
              FUN_00404540();
            }
            else {
              builtin_wcsncpy(local_7ec,L"TEMP.TXT",9);
              _memset(local_7da,0,0x7c6);
              uVar4 = FUN_00404920();
              FUN_004f7a90(local_fc4,L"\"%s\"",uVar4);
              local_fd4 = local_fc4;
              pwStack_fd0 = local_7ec;
              uStack_fcc = 0;
              uVar4 = FUN_00404920(&local_fd4);
              FUN_00904dec(0,uVar4);
              uVar4 = FUN_00404920(&DAT_0095be08,&local_17c0);
              local_17bc = (FILE *)FUN_004f4290(uVar4);
              FUN_006c4bc0(0,local_17bc,local_17c0);
              if (local_17bc != (FILE *)0x0) {
                __fcloseall();
                local_17bc = (FILE *)0x0;
              }
              FUN_00404c80();
              iVar3 = FUN_004fca20();
              if (*(int *)(iVar3 + 0x1a0) == *(int *)(local_17b8[1] + 0x8600)) {
                uVar4 = 0;
                FUN_00404c80(0);
                FUN_004fca20();
                FUN_005835f0(uVar4);
              }
              if (local_17b8[0x8a] != 0) {
                (**(code **)(*local_17b8 + 0x6c))();
              }
              if (*(int *)(local_17b8[1] + 0x8560) < 1) {
                FUN_006bb930();
              }
              *(undefined4 *)(local_17b8[1] + 0x8578) = 1;
              local_8 = local_8 & 0xffffff00;
              _eh_vector_destructor_iterator_(local_17b4,4,0x1f8,FUN_00404540);
              local_8 = 0xffffffff;
              FUN_00404540();
            }
          }
          else {
            FUN_004fdba0(0x8053);
            local_17e0 = *(int *)(DAT_00a0b410 + 0x8644);
            **(int **)(local_17e0 + 0xc0) = local_17cc;
            for (local_17d0 = 0; local_17d0 < local_17cc; local_17d0 = local_17d0 + 1) {
              FUN_00404860(local_17b4 + local_17d0 * 4);
            }
            *(undefined4 *)(local_17e0 + 0xd4) = 1;
            local_8 = local_8 & 0xffffff00;
            _eh_vector_destructor_iterator_(local_17b4,4,0x1f8,FUN_00404540);
            local_8 = 0xffffffff;
            FUN_00404540();
          }
        }
      }
    }
  }
  else {
    ExceptionList = &local_10;
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[29] */
/* 006c2fd0  FUN_006c2fd0  846 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c2fd0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined2 *puVar4;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d456;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x230) == 0) {
    local_63e8 = in_ECX;
    if (*(int *)(in_ECX + 0x234) == 0) {
      FUN_00446aa0(local_14);
      local_8 = 1;
      FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
      FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
      *(undefined4 *)(local_63e8 + 0x5d4) = 0;
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
      *(undefined4 *)(local_63e8 + 0x5c4) = 0;
      *(undefined4 *)(local_63e8 + 0x5c8) = 0xffffffff;
      *(undefined4 *)(local_63e8 + 0x5cc) = 0xffffffff;
      *(undefined8 *)(local_63e8 + 0x2d0) = 0x447e7e4171bf4d3a;
      *(undefined4 *)(local_63e8 + 0x5d0) = 0;
      if (*(int *)(*(int *)(local_63e8 + 4) + 0x17d8) == 0x8026) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        cVar1 = FUN_004640c0(&DAT_00956338,*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) + 0x490);
        if (cVar1 != '\0') {
          puVar4 = &DAT_00956338;
          FUN_00404c80(&DAT_00956338);
          FUN_004fca20();
          FUN_00404900(puVar4);
        }
      }
      *(undefined4 *)(local_63e8 + 0x234) = 1;
      *(undefined4 *)(local_63e8 + 0x23c) = 0;
      FUN_006bb930();
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_00550480(0);
      local_8 = 0;
      iVar2 = *(int *)(local_63e8 + 0x2b0) * 3 + (2 - *(int *)(local_63e8 + 0x2b4));
      iVar3 = FUN_0079850d();
      if (iVar3 == 1) {
        *(int *)(local_63e8 + 0x2b0) = iVar2 / 3;
        *(int *)(local_63e8 + 0x2b4) = 2 - iVar2 % 3;
        FUN_006bda50();
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8614)) {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xd4) = *(undefined4 *)(local_63e8 + 0x2b0);
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xd8) = *(undefined4 *)(local_63e8 + 0x2b4);
        }
      }
      local_8 = 0xffffffff;
      FUN_00550710();
    }
  }
  else {
    FUN_006fb760();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[30] */
/* 006c3320  FUN_006c3320  2271 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x006c38eb) */

void FUN_006c3320(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  double dVar6;
  undefined8 uVar7;
  undefined1 local_ca78 [20];
  undefined1 *local_ca64;
  undefined1 *local_ca60;
  undefined4 local_ca5c;
  undefined1 *local_ca58;
  undefined8 local_ca54;
  undefined4 local_ca4c;
  double local_ca48;
  double local_ca40;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_ca38;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_ca34 [4];
  wchar_t local_ca30 [2];
  double local_ca2c;
  undefined4 local_ca24;
  undefined4 local_ca20;
  undefined4 local_ca1c;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_ca14;
  wchar_t *local_ca10;
  wchar_t *local_ca0c;
  undefined1 local_ca08 [4];
  undefined4 local_ca04;
  undefined4 local_ca00;
  undefined1 local_c9fc [4];
  undefined4 local_c9f8;
  double local_c9f4;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_c9ec [4];
  undefined1 local_c9e8 [4];
  int local_c9e4;
  int local_c9e0;
  undefined1 local_c9dc [4];
  undefined1 local_c9d8 [4];
  undefined1 local_c9d4 [4];
  FILE *local_c9d0;
  int local_c9cc;
  allocator<char> local_228 [16];
  undefined1 local_218 [516];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d509;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x230) == 0) {
    if ((*(int *)(in_ECX + 0x234) == 0) && (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026)) {
      local_c9cc = in_ECX;
      FUN_00446aa0();
      local_8 = 0;
      local_c9d0 = (FILE *)0x0;
      FUN_00660fa0(local_c9cc + 0x5e4);
      cVar1 = FUN_004640c0(&DAT_00956338);
      if (cVar1 == '\0') {
        if (0 < DAT_00a0d620) {
          FUN_004044d0();
          FUN_00413f30();
          FUN_004146a0();
          puVar2 = (undefined4 *)FUN_0045d370();
          local_ca24 = *puVar2;
          local_ca20 = puVar2[1];
          std::allocator<char>::allocator<char>(local_228);
          piVar3 = (int *)FID_conflict_operator_();
          local_c9e4 = *piVar3 / 2;
          local_c9e0 = piVar3[1] / 2;
          FUN_004dbab0(local_c9e4);
        }
        iVar5 = FUN_006ca1d0();
        if (iVar5 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return;
        }
      }
      else {
        FUN_00404920();
        FUN_0058d570(local_c9cc + 0x5e4);
        FUN_00404900();
        local_ca58 = &stack0xffff3578;
        CStringT<>(local_c9cc + 0x5e4);
        local_ca1c = FUN_0044eff0(local_c9fc);
        local_8._0_1_ = 1;
        local_c9f8 = local_ca1c;
        FUN_00404860();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
      }
      CStringT<>();
      local_8._0_1_ = 2;
      local_ca64 = &stack0xffff3578;
      FUN_00403dd0(local_c9d4);
      local_ca5c = FUN_0044ef10(local_c9dc);
      local_8._0_1_ = 3;
      Mid(local_c9d8);
      local_8._0_1_ = 4;
      if (DAT_00a088f4 != 0) {
        FUN_00404900();
      }
      FUN_0044ff70();
      uVar4 = FUN_00404920();
      iVar5 = FUN_00429b90(uVar4);
      if (iVar5 < 1) {
        local_c9d0 = (FILE *)FUN_004f4290();
        if (local_c9d0 == (FILE *)0x0) {
          local_c9d0 = (FILE *)0x0;
          FUN_005168b0(0x1515,*(undefined4 *)(local_c9cc + 0x1f8),
                       *(undefined4 *)(local_c9cc + 0x1fc),0);
          *(undefined4 *)(local_c9cc + 0x5e0) = 0;
          FUN_00404c80();
          FUN_0056d7d0();
          local_8._0_1_ = 3;
          FUN_00404540();
          local_8._0_1_ = 2;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          FUN_00446aa0();
          local_8._0_1_ = 0xc;
          FUN_0079dea2();
          local_8 = CONCAT31(local_8._1_3_,0xd);
          FUN_0044c830(local_ca78);
          *(undefined4 *)(local_c9cc + 0x5d4) = 0;
          local_ca4c = 0;
          FUN_00454830();
          while (iVar5 = FUN_004f0900(local_218,0x101,local_c9d0), iVar5 != 0) {
            FUN_006c5950();
          }
          if (local_c9d0 != (FILE *)0x0) {
            _fclose(local_c9d0);
            local_c9d0 = (FILE *)0x0;
          }
          *(undefined4 *)(local_c9cc + 0x5e0) = 1;
          local_c9f4 = DAT_00a0b488;
          local_ca54 = DAT_00a0b490;
          if (DAT_00a0b488 <= 0.0) {
            local_ca48 = -DAT_00a0b488;
          }
          else {
            local_ca48 = DAT_00a0b488;
          }
          if (0.01 <= local_ca48) {
            FUN_00404c80();
            iVar5 = FUN_004fca20();
            if (*(int *)(iVar5 + 0x1a0) == *(int *)(*(int *)(local_c9cc + 4) + 0x8600)) {
              dVar6 = local_c9f4;
              uVar7 = local_ca54;
              FUN_00404c80(local_c9f4,local_ca54);
              FUN_004fca20();
              FUN_0058ae50(dVar6,uVar7);
            }
          }
          FUN_00404c80();
          iVar5 = FUN_004fca20();
          if (*(int *)(iVar5 + 0x1a0) == *(int *)(*(int *)(local_c9cc + 4) + 0x8600)) {
            FUN_00404c80();
            FUN_004fca20();
            FUN_007979e8();
          }
          FUN_00404c80();
          FUN_0056d7d0();
          local_8._0_1_ = 0xc;
          FUN_0079dfff();
          local_8._0_1_ = 4;
          FUN_00447100();
          local_8._0_1_ = 3;
          FUN_00404540();
          local_8._0_1_ = 2;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
      else {
        CStringT<>();
        local_8._0_1_ = 5;
        if (DAT_00a0ba78 <= 0.0) {
          local_ca40 = -DAT_00a0ba78;
        }
        else {
          local_ca40 = DAT_00a0ba78;
        }
        local_ca2c = local_ca40;
        if ((10.0 <= local_ca40) && (local_ca40 <= 1000.0)) {
          FUN_004059f0(local_c9e8,&DAT_0095590c,local_ca40);
        }
        local_ca60 = &stack0xffff3578;
        FUN_00403dd0(local_c9d4);
        local_ca04 = FUN_00463de0(local_ca08);
        local_8._0_1_ = 6;
        local_ca00 = local_ca04;
        FUN_00404860();
        local_8._0_1_ = 5;
        FUN_00404540();
        local_ca10 = (wchar_t *)
                     ATL::operator+(local_ca30,
                                    (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                     *)L"^@BM");
        local_8._0_1_ = 7;
        local_ca0c = local_ca10;
        local_ca38 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                      *)ATL::operator+(local_ca34,local_ca10);
        local_8._0_1_ = 8;
        local_ca14 = local_ca38;
        ATL::operator+(local_c9ec,local_ca38);
        local_8._0_1_ = 10;
        FUN_00404540();
        local_8 = CONCAT31(local_8._1_3_,0xb);
        FUN_00404540();
        FUN_00405bc0();
        FUN_006c5950();
        if ((DAT_00a08adc & 4) != 0) {
          FUN_00405bc0();
          FUN_006c5950();
        }
        *(undefined4 *)(local_c9cc + 0x5e0) = 1;
        FUN_00404c80();
        FUN_0056d7d0();
        local_8._0_1_ = 5;
        FUN_00404540();
        local_8._0_1_ = 4;
        FUN_00404540();
        local_8._0_1_ = 3;
        FUN_00404540();
        local_8._0_1_ = 2;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
  }
  else {
    FUN_006fbbb0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[31] */
/* 006c3c00  FUN_006c3c00  77 bytes, 0 callers */

void FUN_006c3c00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x230) == 0) {
    if ((*(int *)(in_ECX + 0x234) == 0) && (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026)) {
      FUN_006c99b0(1);
    }
  }
  else {
    FUN_006fbbf0();
  }
  return;
}




/* vtable slots: CZukeiMoji[32] */
/* 006c3c50  FUN_006c3c50  191 bytes, 0 callers */

void FUN_006c3c50(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x230) == 0) && (*(int *)(in_ECX + 0x234) == 0)) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8600)) {
      DAT_00a0ba70 = 0;
      if ((DAT_00a0cc64 == 0) ||
         (*(double *)(in_ECX + 0x2d0) <= 9e+21 && *(double *)(in_ECX + 0x2d0) != 9e+21)) {
        if (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_005835d0();
        }
      }
      else {
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797df8();
      }
    }
  }
  return;
}




/* vtable slots: CZukeiMoji[33] */
/* 006c3d10  FUN_006c3d10  87 bytes, 0 callers */

void FUN_006c3d10(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x230) == 0) && (*(int *)(in_ECX + 0x234) == 0)) {
    *(undefined8 *)(in_ECX + 0x2d0) = 0x447e7e4171bf4d3a;
    FUN_00404c80();
    FUN_004fca20();
    FUN_00797df8();
  }
  return;
}




/* vtable slots: CZukeiMoji[36] */
/* 006c3d70  FUN_006c3d70  1667 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c3d70(void)

{
  int iVar1;
  undefined1 local_6510 [20];
  uint local_64fc;
  undefined4 local_64f8;
  uint local_64f4;
  int local_64f0;
  int local_64ec;
  int *local_64e8;
  undefined1 local_114 [240];
  undefined8 local_24;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d566;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(local_64e8[1]);
  local_8._0_1_ = 1;
  if (local_64e8[0x8c] == 0) {
    if (local_64e8[0x8d] == 0) {
      iVar1 = local_64e8[1];
      FUN_00454cb0(0,local_64e8[1],*(undefined4 *)(iVar1 + 0x8f10),*(undefined4 *)(iVar1 + 0x8f14),
                   *(undefined4 *)(iVar1 + 0x8f18),*(undefined4 *)(iVar1 + 0x8f1c));
      *(undefined4 *)(local_64e8[1] + 0x8578) = 0;
      FUN_00408a60();
      local_1c = 0.0;
      local_24 = 0.0;
      local_64e8[0x177] = 1;
      if (local_64e8[0x178] == 0) {
        if (local_64e8[0x175] == 0) {
          if (*(int *)(local_64e8[1] + 0x17d8) == 0x8026) {
            if (local_64e8[0x171] == 2) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
            }
            else {
              local_64f8 = FUN_0040c0e0();
              if ((((DAT_00a0cc64 == 0) ||
                   (9e+20 < *(double *)(local_64e8 + 0xb4) ||
                    *(double *)(local_64e8 + 0xb4) == 9e+20)) ||
                  (iVar1 = FUN_00573cb0(), iVar1 == 0)) || (local_64e8[0x88] != 0)) {
                iVar1 = FUN_00573cb0();
                if ((iVar1 == 0) || (local_64e8[0x88] != 0)) {
                  FUN_00480a30();
                  local_8._0_1_ = 2;
                  FUN_00481070(local_64e8 + 0xba);
                  FUN_00481070(local_64e8 + 0xf6);
                  FUN_006bbe60();
                  local_24 = *(double *)(local_64e8 + 0x80) - *(double *)(local_64e8 + 0x84);
                  local_1c = *(double *)(local_64e8 + 0x82) - *(double *)(local_64e8 + 0x86);
                  FUN_00481070(local_114);
                  FUN_006bbe60();
                  (**(code **)(*local_64e8 + 0x24))
                            (0,(undefined4)local_24,local_24._4_4_,(undefined4)local_1c,
                             local_1c._4_4_);
                  local_64e8[0x8e] = 1;
                  (**(code **)(*local_64e8 + 0xc))();
                  local_64fc = (uint)(DAT_00a0bba8 == 0);
                  local_64e8[0x8e] = local_64fc;
                  *(undefined4 *)(local_64e8[1] + 0x8578) = 1;
                  if (*(int *)(local_64e8[1] + 0x8588) == 0) {
                    local_8._0_1_ = 1;
                    FUN_00480ef0();
                    local_8 = (uint)local_8._1_3_ << 8;
                    FUN_0079dfff();
                    local_8 = 0xffffffff;
                    FUN_00447100();
                  }
                  else {
                    *(undefined4 *)(local_64e8[1] + 0x8588) = 0xffffd9bb;
                    *(undefined4 *)(local_64e8[1] + 0x906c) = 0;
                    FUN_00404c80();
                    FUN_0056d200();
                    local_8._0_1_ = 1;
                    FUN_00480ef0();
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
              else {
                local_64e8[0x8e] = 1;
                (**(code **)(*local_64e8 + 0xc))();
                local_64f4 = (uint)(DAT_00a0bba8 == 0);
                local_64e8[0x8e] = local_64f4;
                *(undefined4 *)(local_64e8[1] + 0x8578) = 1;
                if (*(int *)(local_64e8[1] + 0x8588) == 0) {
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                }
                else {
                  *(undefined4 *)(local_64e8[1] + 0x8588) = 0xffffd9bb;
                  *(undefined4 *)(local_64e8[1] + 0x906c) = 0;
                  FUN_00404c80();
                  FUN_0056d200();
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                }
              }
            }
          }
          else {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
        }
        else {
          FUN_0044c830(local_6510,local_64e8[1]);
          local_64e8[0x175] = 0;
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
    else {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    local_64ec = local_64e8[1];
    if (local_64ec == 0) {
      local_64f0 = 0;
    }
    else {
      local_64f0 = local_64ec + 0x88;
    }
    iVar1 = FUN_0044fcd0(local_64f0);
    if (iVar1 == 0) {
      (**(code **)(*local_64e8 + 0x88))();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
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




/* vtable slots: CZukeiMoji[49] */
/* 006c4640  FUN_006c4640  151 bytes, 0 callers */

void FUN_006c4640(undefined8 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x234) == 0) && (*(int *)(in_ECX + 0x230) == 0)) &&
     (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026)) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x9f8) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x9fc) = 0;
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_00583200(param_1);
  }
  return;
}




/* vtable slots: CZukeiMoji[50] */
/* 006c46e0  FUN_006c46e0  350 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c46e0(double param_1)

{
  int in_ECX;
  undefined8 uVar1;
  undefined1 local_198 [400];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0x234) == 0) && (*(int *)(in_ECX + 0x230) == 0)) {
    param_1 = param_1 / *(double *)
                         (*(int *)(in_ECX + 4) + 0x2578 +
                         *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
    FUN_00480580(local_198,L"%.3lf",param_1);
    FUN_00417110();
    if (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026) {
      uVar1 = 0;
      FUN_00404c80(param_1,0);
      FUN_004fca20();
      FUN_0058ae50(param_1,uVar1);
      FUN_00404c80();
      FUN_004fca20();
      FUN_005836e0();
      FUN_00404c80();
      FUN_004fca20();
      FUN_00583710();
      FUN_00404c80();
      FUN_004fca20();
      FUN_00797df8();
    }
  }
  return;
}




/* vtable slots: CZukeiMoji[51] */
/* 006c4840  FUN_006c4840  888 bytes, 0 callers */

void FUN_006c4840(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 *puStack_34;
  uint uStack_30;
  undefined4 local_2c;
  undefined1 *local_28;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_24 [4];
  undefined1 *local_20;
  undefined1 *local_1c;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0093d605;
  local_10 = ExceptionList;
  uStack_30 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x234) == 0) {
    if (*(int *)(in_ECX + 0x230) == 0) {
      if (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026) {
        uVar3 = (undefined4)param_1;
        puStack_34 = (undefined1 *)((ulonglong)param_1 >> 0x20);
        local_14 = in_ECX;
        FUN_00404c80(uVar3);
        FUN_004fca20();
        FUN_00583200(uVar3);
        if (*(int *)(local_14 + 0x54) == 0) {
          local_8 = 0xffffffff;
          puStack_34 = (undefined1 *)0x6c4911;
          FUN_00404540();
        }
        else {
          puStack_34 = (undefined1 *)(uint)*(ushort *)(*(int *)(local_14 + 0x54) + 0x2a);
          uVar5 = *(undefined8 *)(*(int *)(local_14 + 0x54) + 200);
          uVar6 = (undefined4)uVar5;
          uVar7 = (undefined4)((ulonglong)uVar5 >> 0x20);
          uVar5 = *(undefined8 *)(*(int *)(local_14 + 0x54) + 0xc0);
          uVar4 = *(undefined8 *)(*(int *)(local_14 + 0x54) + 0xb8);
          uVar3 = *(undefined4 *)(*(int *)(local_14 + 0x54) + 0xb4);
          FUN_00404c80(uVar3,uVar4,uVar5,uVar6,uVar7);
          FUN_004fca20();
          FUN_00583240(uVar3,uVar4,uVar5,uVar6,uVar7);
          local_28 = (undefined1 *)&puStack_34;
          local_2c = FUN_0046b960(&puStack_34);
          local_8._0_1_ = 1;
          FUN_00404c80();
          FUN_004fca20();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00583190();
          puStack_34 = (undefined1 *)0x6c49c0;
          FUN_00404c80();
          puStack_34 = (undefined1 *)0x6c49c7;
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xa00) = 0;
          if ((*(ushort *)(*(int *)(local_14 + 0x54) + 0x44) & 0x20) != 0) {
            puStack_34 = (undefined1 *)0x6c49eb;
            FUN_00404c80();
            puStack_34 = (undefined1 *)0x6c49f2;
            iVar2 = FUN_004fca20();
            *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xa00) = 1;
          }
          DAT_00a0bc28 = (uint)((*(ushort *)(*(int *)(local_14 + 0x54) + 0xdc) & 1) != 0);
          DAT_00a0bc2c = (uint)((*(ushort *)(*(int *)(local_14 + 0x54) + 0xdc) & 0x10) != 0);
          puStack_34 = (undefined1 *)0x0;
          FUN_00404c80();
          FUN_004fca20();
          FUN_005835f0();
          puStack_34 = &stack0x0000002c;
          cVar1 = FUN_004640c0(&DAT_00956338);
          if (cVar1 != '\0') {
            puStack_34 = (undefined1 *)0x6c4a88;
            FUN_00404c80();
            puStack_34 = (undefined1 *)0x6c4a8f;
            iVar2 = FUN_004fca20();
            puStack_34 = (undefined1 *)(*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) + 0x490);
            FUN_00403dd0();
            local_8._0_1_ = 2;
            puStack_34 = &stack0x0000002c;
            puStack_34 = (undefined1 *)ATL::operator+(local_24,local_18);
            local_8._0_1_ = 3;
            local_20 = puStack_34;
            local_1c = puStack_34;
            FUN_00404c80();
            FUN_004fca20();
            FUN_00404860();
            local_8._0_1_ = 2;
            puStack_34 = (undefined1 *)0x6c4b01;
            FUN_00404540();
            puStack_34 = (undefined1 *)0x0;
            FUN_00404c80();
            FUN_004fca20();
            FUN_005835f0();
            local_8 = (uint)local_8._1_3_ << 8;
            puStack_34 = (undefined1 *)0x6c4b26;
            FUN_00404540();
          }
          if ((DAT_00a0cc64 == 0) ||
             (*(double *)(local_14 + 0x2d0) <= 9e+21 && *(double *)(local_14 + 0x2d0) != 9e+21)) {
            if (*(int *)(*(int *)(local_14 + 4) + 0x17d8) == 0x8026) {
              puStack_34 = (undefined1 *)0x6c4b5b;
              FUN_00404c80();
              puStack_34 = (undefined1 *)0x6c4b62;
              FUN_004fca20();
              puStack_34 = (undefined1 *)0x6c4b79;
              FUN_00797df8();
            }
          }
          else {
            puStack_34 = (undefined1 *)0x6c4b80;
            FUN_00404c80();
            puStack_34 = (undefined1 *)0x6c4b87;
            FUN_004fca20();
            puStack_34 = (undefined1 *)0x6c4b98;
            FUN_00797df8();
          }
          local_8 = 0xffffffff;
          puStack_34 = (undefined1 *)0x6c4ba7;
          FUN_00404540();
        }
      }
      else {
        local_8 = 0xffffffff;
        puStack_34 = (undefined1 *)0x6c48d0;
        FUN_00404540();
      }
    }
    else {
      local_8 = 0xffffffff;
      puStack_34 = (undefined1 *)0x6c48aa;
      FUN_00404540();
    }
  }
  else {
    local_8 = 0xffffffff;
    puStack_34 = (undefined1 *)0x6c488a;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[15] */
/* 006c5c40  FUN_006c5c40  243 bytes, 0 callers */

undefined4 FUN_006c5c40(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8026) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if ((((*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8600)) &&
         (*(int *)(in_ECX + 0x230) == 0)) && (*(int *)(in_ECX + 0x234) == 0)) &&
       (((*(int *)(in_ECX + 0x5e0) == 0 && (*(int *)(in_ECX + 0x5d4) == 0)) &&
        ((*(int *)(in_ECX + 0x5d0) == 0 && (DAT_00a0cc64 == 0)))))) {
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      cVar1 = FUN_004640c0(&DAT_00956338,*(int *)(*(int *)(iVar2 + 0x1a0) + 0xbc) + 0x490);
      if (cVar1 == '\0') {
        *(undefined4 *)(in_ECX + 0x2b8) = 1;
      }
    }
  }
  return 0;
}




/* vtable slots: CZukeiMoji[12] */
/* 006c6c90  FUN_006c6c90  303 bytes, 0 callers */

undefined4
FUN_006c6c90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  if (in_ECX[0x8c] == 0) {
    if (in_ECX[0x8d] == 0) {
      if (in_ECX[0x178] == 0) {
        if (*(int *)(in_ECX[1] + 0x8560) == 0) {
          FUN_00404c80();
          iVar3 = FUN_004fca20();
          cVar1 = FUN_00447350(&DAT_00956338,*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) + 0x490);
          if (cVar1 != '\0') {
            in_ECX[0xaa] = 1;
            in_ECX[0xb4] = 0;
            in_ECX[0xb5] = 0;
            (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
            in_ECX[0xaa] = 0;
          }
        }
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = FUN_006bdfc0(param_1,param_2,param_3,param_4,param_5);
    }
  }
  else {
    uVar2 = FUN_006fcae0(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar2;
}




/* vtable slots: CZukeiMoji[10] */
/* 006c6dc0  FUN_006c6dc0  1057 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c6dc0(void)

{
  int iVar1;
  int *in_ECX;
  int iStack_643c;
  uint uStack_6438;
  undefined4 local_6420;
  undefined1 *local_641c;
  int local_6418;
  int local_6414;
  undefined4 local_6410;
  int local_640c;
  int *local_6408;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d8e6;
  local_10 = ExceptionList;
  uStack_6438 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x8d] == 0) {
    iStack_643c = 0x6c6e14;
    local_6408 = in_ECX;
    local_14 = uStack_6438;
    FUN_00446aa0();
    local_8 = 0;
    iStack_643c = local_6408[1];
    FUN_0079dea2();
    local_8._0_1_ = 1;
    iStack_643c = 0x6c6e42;
    local_6410 = FUN_0040c0e0();
    if (local_6408[0x8a] == 0) {
      iStack_643c = 0x6c6fbf;
      local_6418 = FUN_00572b10();
      if ((local_6418 == 0) && (*(int *)(local_6408[1] + 0x9068) != 0)) {
        iVar1 = local_6408[1];
        local_24 = *(undefined4 *)(iVar1 + 0x8f68);
        local_20 = *(undefined4 *)(iVar1 + 0x8f6c);
        local_1c = *(undefined4 *)(iVar1 + 0x8f70);
        local_18 = *(undefined4 *)(iVar1 + 0x8f74);
        *(undefined4 *)(local_6408[1] + 0x8f34) = 1;
        iStack_643c = 0;
        iVar1 = FUN_004500e0(1,local_6408[1],&local_24,&local_640c);
        if (iVar1 == 1) {
          if (*(int *)(local_6408[1] + 0x17d8) == 0x8026) {
            iStack_643c = 0x6c706b;
            FUN_00404c80();
            iStack_643c = 0x6c7072;
            FUN_004fca20();
            iStack_643c = 0x6c707d;
            FUN_00583170();
            iStack_643c = 0x6c7082;
            FUN_00404c80();
            iStack_643c = 0x6c7089;
            FUN_004fca20();
            iStack_643c = 0x6c7094;
            iVar1 = FUN_00581530();
            if (iVar1 != 0) {
              local_641c = (undefined1 *)&iStack_643c;
              local_6420 = FUN_0046b960(&iStack_643c);
              local_8._0_1_ = 2;
              FUN_00404c80();
              FUN_004fca20();
              local_8._0_1_ = 1;
              FUN_00583190();
              DAT_00a0bc28 = (uint)((*(ushort *)(local_640c + 0xdc) & 1) != 0);
              if ((*(ushort *)(local_640c + 0xdc) & 0x10) == 0) {
                DAT_00a0bc2c = 0;
              }
              else {
                DAT_00a0bc2c = 1;
              }
            }
            iStack_643c = local_640c;
            FUN_006c6160();
            local_6408[0x171] = 1;
            local_6408[0x172] = 0;
            iStack_643c = 0x6c715d;
            FUN_00404c80();
            iStack_643c = 0x6c7164;
            FUN_004fca20();
            iStack_643c = 0x6c716f;
            FUN_00580c10();
          }
          local_8 = (uint)local_8._1_3_ << 8;
          iStack_643c = 0x6c717e;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          iStack_643c = 0x6c7190;
          FUN_00447100();
          ExceptionList = local_10;
          return;
        }
      }
      *(undefined4 *)(local_6408[1] + 0x8560) = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      iStack_643c = 0x6c71b4;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      iStack_643c = 0x6c71c6;
      FUN_00447100();
    }
    else {
      local_6414 = *(int *)(local_6408[1] + 0x9068) + *(int *)(local_6408[1] + 0x906c);
      *(undefined4 *)(local_6408[1] + 0x906c) = 0;
      *(undefined4 *)(local_6408[1] + 0x9068) = 0;
      iStack_643c = 0x6c6eb8;
      (**(code **)(*local_6408 + 0x70))();
      if ((local_6414 != 0) &&
         (*(double *)(local_6408[1] + 0x8f68) <= 9e+20 &&
          *(double *)(local_6408[1] + 0x8f68) != 9e+20)) {
        iStack_643c = 0x6c6eef;
        iVar1 = FUN_00572b10();
        if (iVar1 == 0) {
          iStack_643c = 0;
          FUN_00653df0();
          iStack_643c = 0;
          FUN_00652e80();
          iVar1 = local_6408[1];
          iStack_643c = *(int *)(iVar1 + 0x8f74);
          FUN_004988c0(local_34,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
                       *(undefined4 *)(iVar1 + 0x8f70));
          iStack_643c = 0x6c6f67;
          FUN_0040c9d0();
          *(undefined4 *)(local_6408[2] + 4) = 1;
          local_6408[3] = 0;
          DAT_00a0d618 = 1;
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      iStack_643c = 0x6c6f9d;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      iStack_643c = 0x6c6faf;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[9] */
/* 006c71f0  FUN_006c71f0  1734 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006c71f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  undefined4 *local_6480;
  uint uStack_647c;
  undefined4 local_6478;
  undefined1 *local_6474;
  undefined4 local_6470;
  undefined1 local_646c [20];
  double local_6458;
  double local_6450;
  undefined4 local_6448;
  undefined4 local_6444;
  undefined4 local_6440;
  undefined4 local_643c;
  undefined4 *local_6438;
  undefined4 local_6434;
  undefined4 local_6430;
  undefined4 local_642c;
  uint local_6428;
  undefined4 *local_6424;
  uint local_6420;
  char local_6419;
  int local_6418;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d936;
  local_10 = ExceptionList;
  uStack_647c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6420 = 0;
  local_6428 = (uint)(DAT_00a0bba8 == 0);
  *(uint *)(in_ECX + 0x238) = local_6428;
  local_14 = uStack_647c;
  if (*(int *)(in_ECX + 0x230) != 0) {
    local_6480 = param_5;
    uVar2 = FUN_006fd240(param_1,param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar2;
  }
  if (*(int *)(in_ECX + 0x234) != 0) {
    local_6480 = param_5;
    uVar2 = FUN_006be0b0(param_1,param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar2;
  }
  local_6480 = (undefined4 *)0x6c72e9;
  local_6418 = in_ECX;
  FUN_00446aa0();
  local_8 = 0;
  local_6480 = *(undefined4 **)(local_6418 + 4);
  FUN_0079dea2();
  local_8._0_1_ = 1;
  *(undefined4 *)(local_6418 + 0x5dc) = 0;
  if (*(int *)(local_6418 + 0x5e0) != 0) {
    local_6480 = param_5;
    FUN_004988c0(local_24,param_2,param_3,param_4);
    local_6430 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    local_6480 = (undefined4 *)0x6c7372;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    local_6480 = (undefined4 *)0x6c7384;
    FUN_00447100();
    ExceptionList = local_10;
    return local_6430;
  }
  if (*(int *)(local_6418 + 0x5d4) != 0) {
    local_6480 = *(undefined4 **)(local_6418 + 4);
    FUN_0044c830(local_646c);
    *(undefined4 *)(local_6418 + 0x5d4) = 0;
    local_6434 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    local_6480 = (undefined4 *)0x6c73e3;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    local_6480 = (undefined4 *)0x6c73f5;
    FUN_00447100();
    ExceptionList = local_10;
    return local_6434;
  }
  if (*(int *)(local_6418 + 0x5d0) != 0) {
    local_6480 = (undefined4 *)0x6c741a;
    FUN_006bfc10();
  }
  if ((((DAT_00a0cc64 == 0) || (*(double *)(local_6418 + 0x2d0) <= 9e+20)) || (DAT_00a0cc6c != 0))
     || (*(int *)(local_6418 + 0x2a8) != 0)) {
LAB_006c74b1:
    local_642c = 0;
  }
  else {
    local_6480 = &local_643c;
    FUN_00404c80();
    FUN_004fca20();
    local_6480 = (undefined4 *)FUN_00581420();
    local_6420 = local_6420 | 1;
    local_6438 = local_6480;
    cVar1 = FUN_00447350(&DAT_00956338);
    if (cVar1 == '\0') goto LAB_006c74b1;
    local_642c = 1;
  }
  local_6419 = (char)local_642c;
  if ((local_6420 & 1) != 0) {
    local_6420 = local_6420 & 0xfffffffe;
    local_6480 = (undefined4 *)0x6c74e4;
    FUN_00404540();
  }
  if (local_6419 != '\0') {
    local_6480 = param_5;
    puVar3 = (undefined4 *)FUN_004988c0(local_34,param_2,param_3,param_4);
    local_6480 = (undefined4 *)puVar3[3];
    FUN_004988c0(local_44,*puVar3,puVar3[1],puVar3[2]);
    local_6480 = (undefined4 *)0x6c7559;
    FUN_00404c80();
    local_6480 = (undefined4 *)0x6c7560;
    FUN_004fca20();
    local_6480 = (undefined4 *)0x6c756b;
    FUN_00583170();
    local_6440 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    local_6480 = (undefined4 *)0x6c7584;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    local_6480 = (undefined4 *)0x6c7596;
    FUN_00447100();
    ExceptionList = local_10;
    return local_6440;
  }
  local_6480 = (undefined4 *)0x6c75af;
  local_6470 = FUN_0040c0e0();
  if (*(int *)(*(int *)(local_6418 + 4) + 0x8560) == 0) {
    local_6480 = (undefined4 *)0x6c75d0;
    FUN_00404c80();
    local_6480 = (undefined4 *)0x6c75d7;
    iVar4 = FUN_004fca20();
    local_6480 = (undefined4 *)(*(int *)(*(int *)(iVar4 + 0x1a0) + 0xbc) + 0x490);
    cVar1 = FUN_00447350(&DAT_00956338);
    if (cVar1 != '\0') {
      local_6480 = (undefined4 *)0x0;
      iVar4 = FUN_004500e0(1,*(undefined4 *)(local_6418 + 4),&param_2,&local_6424);
      if (iVar4 == 1) {
        if (*(int *)(*(int *)(local_6418 + 4) + 0x17d8) == 0x8026) {
          local_6480 = (undefined4 *)0x6c764c;
          FUN_00404c80();
          local_6480 = (undefined4 *)0x6c7653;
          FUN_004fca20();
          local_6480 = (undefined4 *)0x6c765e;
          FUN_00583170();
          local_6480 = (undefined4 *)0x6c7663;
          FUN_00404c80();
          local_6480 = (undefined4 *)0x6c766a;
          FUN_004fca20();
          local_6480 = (undefined4 *)0x6c7675;
          iVar4 = FUN_00581530();
          if (iVar4 != 0) {
            local_6474 = (undefined1 *)&local_6480;
            local_6478 = FUN_0046b960(&local_6480);
            local_8._0_1_ = 2;
            FUN_00404c80();
            FUN_004fca20();
            local_8._0_1_ = 1;
            FUN_00583190();
            DAT_00a0bc28 = (uint)((*(ushort *)(local_6424 + 0x37) & 1) != 0);
            if ((*(ushort *)(local_6424 + 0x37) & 0x10) == 0) {
              DAT_00a0bc2c = 0;
            }
            else {
              DAT_00a0bc2c = 1;
            }
          }
          local_6480 = local_6424;
          FUN_006c6160();
          *(undefined4 *)(local_6418 + 0x5c4) = 1;
          local_6480 = (undefined4 *)0x6c772e;
          FUN_00404c80();
          local_6480 = (undefined4 *)0x6c7735;
          FUN_004fca20();
          local_6480 = (undefined4 *)0x6c7740;
          FUN_00580c10();
        }
        local_6444 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        local_6480 = (undefined4 *)0x6c7759;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        local_6480 = (undefined4 *)0x6c776b;
        FUN_00447100();
        ExceptionList = local_10;
        return local_6444;
      }
      goto LAB_006c786a;
    }
  }
  if (*(int *)(local_6418 + 0x5c4) != 0) {
    local_6480 = &param_2;
    FUN_006c6890(local_6418 + 0x3d8);
  }
  local_6450 = ((double)CONCAT44(param_3,param_2) - *(double *)(local_6418 + 0x10)) +
               *(double *)(local_6418 + 0x210);
  local_6458 = ((double)CONCAT44(param_5,param_4) - *(double *)(local_6418 + 0x18)) +
               *(double *)(local_6418 + 0x218);
  *(double *)(local_6418 + 0x10) = *(double *)(local_6418 + 0x10) + local_6450;
  *(double *)(local_6418 + 0x18) = *(double *)(local_6418 + 0x18) + local_6458;
  *(double *)(local_6418 + 0x20) = *(double *)(local_6418 + 0x20) + local_6450;
  *(double *)(local_6418 + 0x28) = *(double *)(local_6418 + 0x28) + local_6458;
LAB_006c786a:
  local_6448 = 1;
  local_8 = (uint)local_8._1_3_ << 8;
  local_6480 = (undefined4 *)0x6c7883;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  local_6480 = (undefined4 *)0x6c7895;
  FUN_00447100();
  ExceptionList = local_10;
  return local_6448;
}




/* vtable slots: CZukeiMoji[13] */
/* 006c78c0  FUN_006c78c0  542 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006c78c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920af0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX[0x8c] == 0) {
    if (in_ECX[0x8d] == 0) {
      if (in_ECX[0x178] == 0) {
        if (*(int *)(in_ECX[1] + 0x8560) == 0) {
          FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
          iVar3 = FUN_004fca20();
          cVar1 = FUN_00447350(&DAT_00956338,*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) + 0x490);
          if (cVar1 != '\0') {
            FUN_00446aa0();
            local_8 = 0;
            FUN_004fb9f0();
            iVar3 = in_ECX[1];
            FUN_00454cb0(0,in_ECX[1],*(undefined4 *)(iVar3 + 0x8f10),*(undefined4 *)(iVar3 + 0x8f14)
                         ,*(undefined4 *)(iVar3 + 0x8f18),*(undefined4 *)(iVar3 + 0x8f1c));
            in_ECX[0xaa] = 1;
            in_ECX[0xb4] = 0x71bf4d3a;
            in_ECX[0xb5] = 0x447e7e41;
            (**(code **)(*in_ECX + 0x2c))(param_1,param_2,param_3,param_4,param_5);
            in_ECX[0xaa] = 0;
            in_ECX[0xab] = 0;
            local_8 = 0xffffffff;
            FUN_00447100();
          }
        }
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = FUN_006be4b0(param_1,param_2,param_3,param_4,param_5);
    }
  }
  else {
    uVar2 = FUN_006fda50(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiMoji[11] */
/* 006c7ae0  FUN_006c7ae0  1938 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006c7ae0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 *local_c848;
  uint uStack_c844;
  undefined4 local_c840;
  undefined1 *local_c83c;
  undefined4 local_c838;
  undefined4 local_c834;
  undefined4 local_c830;
  undefined4 local_c82c;
  undefined4 local_c828;
  undefined1 local_c824 [4];
  undefined1 *local_c820;
  undefined4 local_c81c;
  undefined4 local_c818;
  undefined4 local_c814;
  undefined1 local_c810 [20];
  undefined4 local_c7fc;
  uint local_c7f8;
  undefined1 *local_c7f4;
  uint local_c7f0;
  char local_c7e9;
  int local_c7e8;
  undefined4 local_64c0;
  undefined4 local_64b8;
  undefined4 local_64a0;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093d991;
  local_10 = ExceptionList;
  uStack_c844 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_c7f0 = 0;
  local_c7f8 = (uint)(DAT_00a0bba8 == 0);
  *(uint *)(in_ECX + 0x238) = local_c7f8;
  local_14 = uStack_c844;
  if (*(int *)(in_ECX + 0x230) != 0) {
    local_c848 = param_5;
    uVar2 = FUN_006fda70(param_1,param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar2;
  }
  if (*(int *)(in_ECX + 0x234) != 0) {
    local_c848 = param_5;
    uVar2 = FUN_006be560(param_1,param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar2;
  }
  local_c848 = (undefined1 *)0x6c7bd9;
  local_c7e8 = in_ECX;
  FUN_00446aa0();
  local_8 = 0;
  local_c848 = *(undefined1 **)(local_c7e8 + 4);
  FUN_0079dea2();
  local_8._0_1_ = 1;
  *(undefined4 *)(local_c7e8 + 0x5dc) = 0;
  if (*(int *)(local_c7e8 + 0x5e0) != 0) {
    local_c848 = (undefined1 *)0x1;
    iVar3 = FUN_00451eb0(*(undefined4 *)(local_c7e8 + 4),&param_2);
    if (iVar3 == 0) {
      local_c814 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      local_c848 = (undefined1 *)0x6c7c54;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      local_c848 = (undefined1 *)0x6c7c66;
      FUN_00447100();
      ExceptionList = local_10;
      return local_c814;
    }
    local_c848 = param_5;
    FUN_004988c0(local_24,param_2,param_3,param_4);
    local_c818 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    local_c848 = (undefined1 *)0x6c7cbb;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    local_c848 = (undefined1 *)0x6c7ccd;
    FUN_00447100();
    ExceptionList = local_10;
    return local_c818;
  }
  if (*(int *)(local_c7e8 + 0x5d4) != 0) {
    local_c848 = *(undefined1 **)(local_c7e8 + 4);
    FUN_0044c830(local_c810);
    *(undefined4 *)(local_c7e8 + 0x5d4) = 0;
    local_c81c = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    local_c848 = (undefined1 *)0x6c7d2c;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    local_c848 = (undefined1 *)0x6c7d3e;
    FUN_00447100();
    ExceptionList = local_10;
    return local_c81c;
  }
  if ((((DAT_00a0cc64 != 0) && (9e+20 < *(double *)(local_c7e8 + 0x2d0))) && (DAT_00a0cc6c == 0)) &&
     (*(int *)(local_c7e8 + 0x2a8) == 0)) {
    local_c848 = local_c824;
    FUN_00404c80();
    FUN_004fca20();
    local_c848 = (undefined1 *)FUN_00581420();
    local_c7f0 = local_c7f0 | 1;
    local_c820 = local_c848;
    cVar1 = FUN_00447350(&DAT_00956338);
    if (cVar1 != '\0') {
      local_c7fc = 1;
      goto LAB_006c7dea;
    }
  }
  local_c7fc = 0;
LAB_006c7dea:
  local_c7e9 = (char)local_c7fc;
  if ((local_c7f0 & 1) != 0) {
    local_c7f0 = local_c7f0 & 0xfffffffe;
    local_c848 = (undefined1 *)0x6c7e13;
    FUN_00404540();
  }
  if (local_c7e9 == '\0') {
    if (*(int *)(local_c7e8 + 0x5d0) != 0) {
      local_c848 = (undefined1 *)0x6c7f7e;
      FUN_006bfc10();
    }
    if (*(int *)(*(int *)(local_c7e8 + 4) + 0x8560) == 0) {
      local_c848 = (undefined1 *)0x6c7f99;
      FUN_00404c80();
      local_c848 = (undefined1 *)0x6c7fa0;
      iVar3 = FUN_004fca20();
      local_c848 = (undefined1 *)(*(int *)(*(int *)(iVar3 + 0x1a0) + 0xbc) + 0x490);
      cVar1 = FUN_00447350(&DAT_00956338);
      if (cVar1 != '\0') {
        local_c848 = (undefined1 *)0x6c7fd5;
        FUN_00446aa0();
        local_8._0_1_ = 2;
        local_64c0 = 1;
        local_64b8 = 1;
        local_64a0 = 1;
        local_c848 = (undefined1 *)0x0;
        iVar3 = FUN_004500e0(1,*(undefined4 *)(local_c7e8 + 4),&param_2,&local_c7f4);
        if (iVar3 == 1) {
          local_c848 = (undefined1 *)0x6c8029;
          FUN_00404c80();
          local_c848 = (undefined1 *)0x6c8030;
          FUN_004fca20();
          local_c848 = (undefined1 *)0x6c803b;
          FUN_00580c10();
          *(undefined4 *)(local_c7e8 + 0x5c4) = 2;
          local_c848 = local_c7f4;
          FUN_00481070();
          local_c848 = (undefined1 *)(local_c7e8 + 0x4c8);
          FUN_006c6160();
          local_c848 = *(undefined1 **)(local_c7e8 + 4);
          FUN_0044c830(local_c810);
          *(undefined4 *)(local_c7e8 + 0x5c0) = *(undefined4 *)(local_c7f4 + 0xb4);
          local_c848 = (undefined1 *)0x6c80b4;
          FUN_00404c80();
          local_c848 = (undefined1 *)0x6c80bb;
          FUN_004fca20();
          local_c848 = (undefined1 *)0x6c80c6;
          iVar3 = FUN_00581530();
          if (iVar3 != 0) {
            local_c83c = (undefined1 *)&local_c848;
            local_c840 = FUN_0046b960(&local_c848);
            local_8._0_1_ = 3;
            FUN_00404c80();
            FUN_004fca20();
            local_8._0_1_ = 2;
            FUN_00583190();
            DAT_00a0bc28 = (uint)((*(ushort *)(local_c7f4 + 0xdc) & 1) != 0);
            if ((*(ushort *)(local_c7f4 + 0xdc) & 0x10) == 0) {
              DAT_00a0bc2c = 0;
            }
            else {
              DAT_00a0bc2c = 1;
            }
          }
          local_c830 = 0;
          local_8._0_1_ = 1;
          local_c848 = (undefined1 *)0x6c8171;
          FUN_00447100();
          local_8 = (uint)local_8._1_3_ << 8;
          local_c848 = (undefined1 *)0x6c8180;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          local_c848 = (undefined1 *)0x6c8192;
          FUN_00447100();
          ExceptionList = local_10;
          return local_c830;
        }
        local_8._0_1_ = 1;
        local_c848 = (undefined1 *)0x6c81ac;
        FUN_00447100();
      }
    }
    local_c848 = (undefined1 *)0x1;
    iVar3 = FUN_00451eb0(*(undefined4 *)(local_c7e8 + 4),&param_2);
    if (iVar3 == 1) {
      local_c848 = param_5;
      local_c834 = FUN_006c71f0(param_1,param_2,param_3,param_4);
      local_8 = (uint)local_8._1_3_ << 8;
      local_c848 = (undefined1 *)0x6c820c;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      local_c848 = (undefined1 *)0x6c821e;
      FUN_00447100();
      local_c828 = local_c834;
    }
    else {
      local_c838 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      local_c848 = (undefined1 *)0x6c823f;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      local_c848 = (undefined1 *)0x6c8251;
      FUN_00447100();
      local_c828 = local_c838;
    }
  }
  else {
    *(undefined4 *)(local_c7e8 + 0x2ac) = 0;
    *(undefined4 *)(*(int *)(local_c7e8 + 4) + 0x8f34) = 1;
    local_c848 = (undefined1 *)0x1;
    iVar3 = FUN_00451eb0(*(undefined4 *)(local_c7e8 + 4),&param_2);
    if (iVar3 == 0) {
      *(undefined4 *)(local_c7e8 + 0x2ac) = 1;
      local_c848 = (undefined1 *)0x6c7e79;
      FUN_00404c80();
      local_c848 = (undefined1 *)0x6c7e80;
      FUN_0056d7d0();
      local_c828 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      local_c848 = (undefined1 *)0x6c7e99;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      local_c848 = (undefined1 *)0x6c7eab;
      FUN_00447100();
    }
    else {
      local_c848 = param_5;
      puVar4 = (undefined4 *)FUN_004988c0(local_34,param_2,param_3,param_4);
      local_c848 = (undefined1 *)puVar4[3];
      FUN_004988c0(local_44,*puVar4,puVar4[1],puVar4[2]);
      local_c848 = (undefined1 *)0x6c7f1c;
      FUN_00404c80();
      local_c848 = (undefined1 *)0x6c7f23;
      FUN_004fca20();
      local_c848 = (undefined1 *)0x6c7f2e;
      FUN_00583170();
      local_c82c = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      local_c848 = (undefined1 *)0x6c7f47;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      local_c848 = (undefined1 *)0x6c7f59;
      FUN_00447100();
      local_c828 = local_c82c;
    }
  }
  ExceptionList = local_10;
  return local_c828;
}




/* vtable slots: CZukeiMoji[8] */
/* 006c8280  FUN_006c8280  279 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c8280(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920af0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x234) == 0) {
    FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (*(int *)(in_ECX + 0x5c4) == 0) {
      FUN_004552a0(in_ECX + 0x2e8);
    }
    FUN_0040da70(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),
                 *(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c));
    FUN_0040da20(*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24),
                 *(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(in_ECX + 0x2c));
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiMoji[3] */
/* 006c83a0  FUN_006c83a0  2676 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006c83a0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 *extraout_ECX;
  undefined1 *local_64c4;
  undefined1 local_6498 [24];
  undefined1 *local_6480;
  undefined4 local_647c;
  undefined1 *local_6478;
  undefined4 local_6474;
  undefined1 local_6470 [28];
  undefined4 local_6454;
  undefined4 local_644c;
  undefined4 local_6448;
  undefined4 local_6444;
  undefined4 local_643c;
  undefined4 local_6438;
  undefined4 local_6430;
  undefined4 local_642c;
  undefined4 local_6428;
  undefined4 local_6424;
  undefined4 local_641c;
  undefined4 local_6414;
  undefined4 local_6410;
  undefined4 local_640c;
  undefined4 local_6408;
  uint local_6404;
  undefined1 *local_6400;
  int local_63f8;
  CWaitCursor local_63f4;
  CWaitCursor local_63f3;
  char local_63f2;
  char local_63f1;
  int local_63f0;
  undefined1 local_63ec [4];
  int local_63e8;
  undefined1 local_63e4 [25336];
  undefined4 local_ec;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093da5f;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x230) == 0) {
    if (*(int *)(in_ECX + 0x234) == 0) {
      local_63e8 = in_ECX;
      if (*(int *)(in_ECX + 0x5e0) == 0) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(*(int *)(*(int *)(iVar1 + 0x1a0) + 0xbc) + 0xc4) != 0) {
          CStringT<>();
          local_8 = 2;
          CStringT<>();
          local_8._0_1_ = 3;
          FUN_00404860();
          local_64c4 = (undefined1 *)0x6c864c;
          local_641c = Left();
          local_64c4 = (undefined1 *)0x6c8663;
          local_63f1 = FUN_00447350();
          FUN_00404540();
          if (local_63f1 != '\0') {
            local_64c4 = (undefined1 *)0x6c8692;
            __wsetlocale(0,L"japan");
            local_64c4 = (undefined1 *)0x6c86a9;
            local_6428 = Mid();
            local_8._0_1_ = 4;
            local_6424 = local_6428;
            FUN_00404860();
            local_8._0_1_ = 3;
            FUN_00404540();
            local_64c4 = (undefined1 *)0x6c86f2;
            local_6408 = FUN_00429b90();
            local_64c4 = (undefined1 *)0x6c8714;
            local_6430 = Mid();
            local_8._0_1_ = 5;
            local_642c = local_6430;
            FUN_00404860();
            local_8._0_1_ = 3;
            FUN_00404540();
            local_64c4 = (undefined1 *)0x6c8764;
            local_643c = Left();
            local_8._0_1_ = 6;
            local_6438 = local_643c;
            FUN_00404860();
            local_8._0_1_ = 3;
            FUN_00404540();
            FUN_00404920();
            local_64c4 = (undefined1 *)0x6c87b7;
            CStdioFile();
            local_8._0_1_ = 7;
            *(undefined1 **)(local_63e8 + 0x9d8) = local_6498;
            (**(code **)(**(int **)(local_63e8 + 0x9d8) + 0x58))();
            *(undefined4 *)(local_63e8 + 0x9dc) = 0;
            local_6480 = &stack0xffff9b40;
            local_64c4 = local_63ec;
            local_6474 = FUN_00403dd0();
            local_8._0_1_ = 8;
            local_6478 = (undefined1 *)&local_64c4;
            local_64c4 = extraout_ECX;
            CStringT<>(&DAT_00979d54);
            local_8._0_1_ = 7;
            FUN_006c5d40();
            FUN_007bfb80();
            local_8._0_1_ = 3;
            FUN_007bf9cf();
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00404540();
        }
        FUN_004fb910();
        CWaitCursor::CWaitCursor(&local_63f3);
        local_8 = 9;
        FUN_00446aa0();
        local_8._0_1_ = 10;
        FUN_0079dea2();
        local_8 = CONCAT31(local_8._1_3_,0xb);
        local_640c = FUN_0040c0e0();
        local_64c4 = (undefined1 *)0x6c88f7;
        FUN_0044dd90();
        if (*(int *)(local_63e8 + 0x5c4) == 0) {
          FUN_004552a0();
        }
        local_63f0 = DAT_00a0b4e8;
        if ((DAT_00a0b4e8 < 0) || (10 < DAT_00a0b4e8)) {
          local_63f0 = 0;
        }
        DAT_00a0b4e8 = local_63f0;
        *(int *)(local_63e8 + 0x39c) = local_63f0;
        *(undefined8 *)(local_63e8 + 0x3a0) = (&DAT_00a0b4f8)[local_63f0];
        *(undefined8 *)(local_63e8 + 0x3a8) = (&DAT_00a0b658)[local_63f0];
        *(undefined8 *)(local_63e8 + 0x3b0) = (&DAT_00a0b7b8)[local_63f0];
        *(undefined2 *)(local_63e8 + 0x312) = *(undefined2 *)(&DAT_00a0b918 + local_63f0);
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        local_6400 = *(undefined1 **)(*(int *)(iVar1 + 0x1a0) + 0xcc);
        iVar1 = FUN_00573cb0();
        if (iVar1 == 0) {
          local_6444 = FUN_00574f80();
          local_64c4 = *(undefined1 **)(local_63e8 + 4);
          FUN_0044b2c0(local_6470);
          local_ec = 1;
          local_6400 = (undefined1 *)0x0;
        }
        local_64c4 = *(undefined1 **)(local_63e8 + 0x14);
        FUN_0040da70(*(undefined4 *)(local_63e8 + 0x10));
        local_64c4 = *(undefined1 **)(local_63e8 + 0x24);
        FUN_0040da20(*(undefined4 *)(local_63e8 + 0x20));
        FUN_00404c80();
        FUN_004fca20();
        local_644c = FUN_00581270();
        local_8._0_1_ = 0xc;
        local_6448 = local_644c;
        FUN_00404860();
        local_8._0_1_ = 0xb;
        FUN_00404540();
        local_63f8 = *(int *)(local_63e8 + 0x5b8) + 1 + *(int *)(local_63e8 + 0x5bc) * 3;
        if ((local_63f8 < 1) || (9 < local_63f8)) {
          local_63f8 = 1;
        }
        *(undefined1 *)(local_63e8 + 0x310) = (undefined1)local_63f8;
        FUN_00404c80();
        FUN_004fca20();
        local_6454 = FUN_00581420();
        local_64c4 = (undefined1 *)0x6c8b97;
        local_63f2 = FUN_004640c0();
        FUN_00404540();
        if (local_63f2 != '\0') {
          *(undefined8 *)(local_63e8 + 0x3d0) = 0;
          *(undefined8 *)(local_63e8 + 0x3c8) = 0;
          FUN_006c8e20();
          local_6404 = (uint)(*(int *)(local_63e8 + 0x5c4) == 0);
          if (local_6400 != (undefined1 *)0x0) {
            FUN_00464040();
            local_8._0_1_ = 0xd;
            local_64c4 = local_6400;
            FUN_004737a0(*(undefined4 *)(local_63e8 + 4),local_6470,local_63e4,local_63e8 + 0x2e8);
            local_ec = 1;
            local_8._0_1_ = 0xb;
            FUN_004640a0();
          }
          local_64c4 = (undefined1 *)(local_63e8 + 0x2e8);
          local_647c = FUN_00450860(local_6470,*(undefined4 *)(local_63e8 + 4));
        }
        *(int *)(local_63e8 + 0x2e0) = *(int *)(local_63e8 + 0x2e0) + 1;
        FUN_00404c80();
        FUN_0056d7d0();
        if ((DAT_00a0cc64 == 0) || (*(int *)(local_63e8 + 0x220) != 0)) {
          if (*(int *)(*(int *)(local_63e8 + 4) + 0x17d8) == 0x8026) {
            FUN_00404c80();
            FUN_004fca20();
            FUN_00583740();
            FUN_00404c80();
            FUN_004fca20();
            FUN_00797df8();
          }
        }
        else {
          *(undefined8 *)(local_63e8 + 0x2d0) = 0x447e7e4171bf4d3a;
          if (*(int *)(*(int *)(local_63e8 + 4) + 0x17d8) == 0x8026) {
            FUN_00404c80();
            FUN_004fca20();
            FUN_00583740();
            FUN_00404c80();
            FUN_004fca20();
            FUN_00797df8();
          }
        }
        *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
        *(undefined4 *)(local_63e8 + 0x5c4) = 0;
        local_8._0_1_ = 10;
        FUN_0079dfff();
        local_8 = CONCAT31(local_8._1_3_,9);
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_00408b00();
      }
      else {
        CWaitCursor::CWaitCursor(&local_63f4);
        local_8 = 0;
        local_64c4 = (undefined1 *)0x1456;
        FUN_004efc30();
        FUN_00404c80();
        FUN_004fca20();
        local_6414 = FUN_00581270();
        local_8._0_1_ = 1;
        local_6410 = local_6414;
        FUN_00404860();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
        local_64c4 = *(undefined1 **)(local_63e8 + 0x2c4);
        FUN_006cabb0(*(undefined4 *)(local_63e8 + 0x2c0));
        *(undefined4 *)(local_63e8 + 0x5e0) = 0;
        if (*(int *)(*(int *)(local_63e8 + 4) + 0x8eb4) < 2) {
          *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8eb4) = 0;
          FUN_00404900();
        }
        else {
          *(int *)(*(int *)(local_63e8 + 4) + 0x8eb4) =
               *(int *)(*(int *)(local_63e8 + 4) + 0x8eb4) + -1;
          FUN_00404860();
          *(undefined4 *)(local_63e8 + 0x5e0) = 1;
        }
        if (*(int *)(*(int *)(local_63e8 + 4) + 0x17d8) == 0x8026) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_00797df8();
        }
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = 0xffffffff;
        FUN_00408b00();
      }
    }
    else {
      FUN_006be8a0();
    }
  }
  else {
    FUN_006fe2f0();
  }
  ExceptionList = local_10;
  return;
}



