/* CZukeiHenkou -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiHenkou[1] */
/* 0067aa70  FUN_0067aa70  68 bytes, 0 callers */

undefined4 FUN_0067aa70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004fa9a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x218);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiHenkou[6] */
/* 0067ad40  FUN_0067ad40  58 bytes, 0 callers */

void FUN_0067ad40(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x214) == 0) {
    FUN_004efbb0(0x156f,0,0);
  }
  else {
    FUN_006f7cc0(param_1);
  }
  return;
}




/* vtable slots: CZukeiHenkou[0] */
/* 0067ada0  FUN_0067ada0  16 bytes, 0 callers */

undefined ** FUN_0067ada0(void)

{
  return &PTR_s_CZukeiHenkou_00978978;
}




/* vtable slots: CZukeiHenkou[46] */
/* 0067b050  FUN_0067b050  224 bytes, 0 callers */

undefined4
FUN_0067b050(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_c [2];
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_c[0] = 0xffffffff;
      iVar2 = FUN_00778a40(1,local_c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,0x2a);
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




/* vtable slots: CZukeiHenkou[47] */
/* 0067b130  FUN_0067b130  224 bytes, 0 callers */

undefined4
FUN_0067b130(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                           param_3,param_4,param_5,param_6,param_7,0x2a);
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




/* vtable slots: CZukeiHenkou[34] */
/* 0067b210  FUN_0067b210  19 bytes, 0 callers */

void FUN_0067b210(void)

{
  FUN_0067aac0();
  return;
}




/* vtable slots: CZukeiHenkou[25], CZukeiHenkou[26] */
/* 0067b230  FUN_0067b230  31 bytes, 0 callers */

void FUN_0067b230(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x214) != 0) {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiHenkou[29] */
/* 0067b250  FUN_0067b250  221 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067b250(void)

{
  int in_ECX;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a53b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x214) == 0) {
    local_63e8 = in_ECX;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_0067aac0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    FUN_006fb760(local_14);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHenkou[51] */
/* 0067b330  FUN_0067b330  479 bytes, 0 callers */

void FUN_0067b330(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0093a585;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x214) == 0) {
    if (*(int *)(in_ECX + 0x54) == 0) {
      local_8 = 0xffffffff;
      FUN_00404540();
    }
    else {
      uVar2 = (uint)*(ushort *)(*(int *)(in_ECX + 0x54) + 0x2a);
      uVar6 = *(undefined8 *)(*(int *)(in_ECX + 0x54) + 200);
      uVar5 = *(undefined8 *)(*(int *)(in_ECX + 0x54) + 0xc0);
      uVar4 = *(undefined8 *)(*(int *)(in_ECX + 0x54) + 0xb8);
      uVar3 = *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0xb4);
      local_14 = in_ECX;
      FUN_00404c80(uVar3,uVar4,uVar5,uVar6,uVar2,DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
      FUN_004fca20();
      FUN_004c9500(uVar3,uVar4,uVar5,uVar6,uVar2);
      local_1c = FUN_0046b960(local_20);
      local_8._0_1_ = 1;
      local_18 = local_1c;
      FUN_00404860(local_1c);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00404540();
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x5e4) = 0;
      if ((*(ushort *)(*(int *)(local_14 + 0x54) + 0x44) & 0x20) != 0) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x5e4) = 1;
      }
      DAT_00a0bc28 = (uint)((*(ushort *)(*(int *)(local_14 + 0x54) + 0xdc) & 1) != 0);
      DAT_00a0bc2c = (uint)((*(ushort *)(*(int *)(local_14 + 0x54) + 0xdc) & 0x10) != 0);
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007955d2();
      local_8 = 0xffffffff;
      FUN_00404540();
    }
  }
  else {
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHenkou[9] */
/* 0067b510  FUN_0067b510  442 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0067b510(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092999b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8._0_1_ = 1;
  if (*(int *)(in_ECX + 0x214) == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    iVar2 = FUN_0044a270(2,*(undefined4 *)(in_ECX + 4),&param_2,in_ECX + 0x210,0);
    if (iVar2 == 0) {
      *(undefined4 *)(in_ECX + 0x210) = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 1;
    }
  }
  else {
    uVar1 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiHenkou[11] */
/* 0067b6d0  FUN_0067b6d0  445 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0067b6d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939d2b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  if (*(int *)(local_63e8 + 0x214) == 0) {
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    local_63ec = 0;
    iVar2 = FUN_004500e0(0,*(undefined4 *)(local_63e8 + 4),&param_2,&local_63ec,0);
    if (iVar2 == 0) {
      *(undefined4 *)(local_63e8 + 0x210) = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else {
      *(undefined4 *)(local_63e8 + 0x210) = local_63ec;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 1;
    }
  }
  else {
    uVar1 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiHenkou[3] */
/* 0067b890  FUN_0067b890  2310 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067b890(void)

{
  undefined1 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 *puStack_64ac;
  undefined1 *puStack_64a8;
  int *piStack_64a4;
  int *piStack_64a0;
  undefined **ppuStack_649c;
  uint uStack_6498;
  undefined1 *local_6478;
  undefined1 local_6474 [24];
  undefined4 local_645c;
  undefined4 local_6458;
  undefined4 local_6450;
  undefined4 local_644c;
  int *local_6448;
  int local_6444;
  int local_6440;
  int local_643c;
  int local_6438;
  int local_6434;
  int local_6430;
  int local_642c;
  int local_6428;
  undefined1 local_6424 [4];
  int local_6420;
  undefined4 local_641c;
  int local_6418;
  int *local_6414;
  int *local_6410;
  int *local_640c;
  int local_6408;
  undefined4 local_10c;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a5f7;
  local_10 = ExceptionList;
  uStack_6498 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uStack_6498;
  if (*(int *)(in_ECX + 0x214) == 0) {
    ppuStack_649c = *(undefined ***)(in_ECX + 4);
    piStack_64a0 = (int *)0x67b8f9;
    local_6408 = in_ECX;
    FUN_0079dea2();
    local_8 = 0;
    ppuStack_649c = (undefined **)0x67b90e;
    local_641c = FUN_0040c0e0();
    ppuStack_649c = (undefined **)0x67b91f;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    ppuStack_649c = *(undefined ***)(local_6408 + 4);
    piStack_64a0 = (int *)local_6474;
    piStack_64a4 = (int *)0x67b93f;
    FUN_0044dd90();
    *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
    if (*(int *)(local_6408 + 0x210) == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      ppuStack_649c = (undefined **)0x67b970;
      FUN_00447100();
      local_8 = 0xffffffff;
      ppuStack_649c = (undefined **)0x67b982;
      FUN_0079dfff();
    }
    else {
      local_642c = 0;
      ppuStack_649c = (undefined **)0x67b996;
      FUN_00404c80();
      ppuStack_649c = (undefined **)0x67b99d;
      FUN_004fca20();
      ppuStack_649c = (undefined **)0x67b9a8;
      iVar2 = FUN_0067adb0();
      if (iVar2 != 0) {
        local_642c = 1;
      }
      local_6430 = 0;
      ppuStack_649c = (undefined **)0x67b9c5;
      FUN_00404c80();
      ppuStack_649c = (undefined **)0x67b9cc;
      FUN_004fca20();
      ppuStack_649c = (undefined **)0x67b9d7;
      iVar2 = FUN_0067ad80();
      if (iVar2 != 0) {
        local_6430 = 1;
      }
      ppuStack_649c = *(undefined ***)(local_6408 + 4);
      piStack_64a0 = (int *)local_6474;
      piStack_64a4 = (int *)0x67ba01;
      FUN_0044c830();
      local_6414 = (int *)0x0;
      local_6444 = 0;
      local_6428 = 0;
      if (*(int *)(*(int *)(local_6408 + 0x210) + 4) == 0) {
        ppuStack_649c = *(undefined ***)(local_6408 + 0x210);
        piStack_64a0 = (int *)0x67bba7;
        FUN_005708e0();
        local_6428 = 0;
      }
      else {
        ppuStack_649c = (undefined **)0x67ba40;
        local_6420 = FUN_00572030();
        while (local_6420 != 0) {
          ppuStack_649c = (undefined **)&local_6420;
          piStack_64a0 = (int *)0x67ba65;
          local_6414 = (int *)FUN_00572100();
          if (local_6414 == (int *)0x0) break;
          local_6434 = *(int *)(local_6408 + 4);
          if (local_6434 == 0) {
            local_6438 = 0;
          }
          else {
            local_6438 = local_6434 + 0x88;
          }
          ppuStack_649c = (undefined **)local_6438;
          piStack_64a0 = (int *)0x67bac0;
          iVar2 = FUN_0042dd10();
          if (iVar2 != 0) {
            local_643c = *(int *)(local_6408 + 4);
            if (local_643c == 0) {
              local_6440 = 0;
            }
            else {
              local_6440 = local_643c + 0x88;
            }
            ppuStack_649c = (undefined **)local_6440;
            piStack_64a0 = (int *)0x67bb0e;
            iVar2 = FUN_0042dcb0();
            if ((iVar2 == 0) && (local_6414[1] == *(int *)(*(int *)(local_6408 + 0x210) + 4))) {
              ppuStack_649c = (undefined **)local_6414;
              piStack_64a0 = (int *)0x67bb48;
              FUN_005708e0();
            }
          }
        }
        ppuStack_649c = (undefined **)0x67bb58;
        FUN_00464040();
        local_8._0_1_ = 2;
        ppuStack_649c = (undefined **)local_641c;
        piStack_64a0 = (int *)0x67bb6e;
        local_6444 = FUN_00479d80();
        local_6428 = 1;
        local_8._0_1_ = 1;
        ppuStack_649c = (undefined **)0x67bb8d;
        FUN_004640a0();
      }
      *(undefined4 *)(local_6408 + 0x210) = 0;
      local_10c = 0;
      ppuStack_649c = (undefined **)0x67bbd6;
      local_6420 = FUN_00572b10();
      while (local_6420 != 0) {
        ppuStack_649c = (undefined **)0x0;
        piStack_64a0 = &local_6420;
        piStack_64a4 = (int *)0x67bbfd;
        local_6414 = (int *)FUN_00572b30();
        if (local_6414 == (int *)0x0) break;
        ppuStack_649c = &PTR_s_CDataBlock_009fe144;
        piStack_64a0 = (int *)0x67bc21;
        iVar2 = FUN_0079d98a();
        if (iVar2 == 0) {
          ppuStack_649c = (undefined **)0x67bc3a;
          local_6410 = (int *)(**(code **)(*local_6414 + 0x14))();
          if (local_6428 != 0) {
            local_6410[1] = local_6444;
          }
          ppuStack_649c = (undefined **)0x1;
          piStack_64a0 = local_6414;
          piStack_64a4 = *(int **)(local_6408 + 4);
          puStack_64a8 = local_6474;
          puStack_64ac = (undefined1 *)0x67bc7d;
          FUN_0044b2c0();
          local_10c = 1;
          if (local_642c != 0) {
            ppuStack_649c = &PTR_s_CDataMoji_009fe108;
            piStack_64a0 = (int *)0x67bca4;
            iVar2 = FUN_0079d98a();
            if (iVar2 == 0) {
              ppuStack_649c = &PTR_s_CDataSolid_009fe094;
              piStack_64a0 = (int *)0x67bf3c;
              iVar2 = FUN_0079d98a();
              if (iVar2 == 0) {
                piStack_64a0 = (int *)DAT_00a0b418;
                piStack_64a4 = (int *)0x67bfc5;
                (**(code **)(*local_6410 + 0x20))();
                piStack_64a4 = (int *)DAT_00a0b428;
                puStack_64a8 = (undefined1 *)0x67bfde;
                (**(code **)(*local_6410 + 0x24))();
                ppuStack_649c = (undefined **)DAT_00a0b424;
                piStack_64a0 = (int *)0x67bff0;
                FUN_00457840();
                ppuStack_649c = (undefined **)DAT_00a0b424;
                piStack_64a0 = (int *)0x67c002;
                FUN_00457840();
              }
              else if (*(int *)(*(int *)(local_6408 + 4) + 0x5e18) == 0) {
                piStack_64a0 = (int *)DAT_00a0b428;
                piStack_64a4 = (int *)0x67bfa9;
                (**(code **)(*local_6410 + 0x24))();
              }
              else {
                piStack_64a0 = (int *)0xa;
                piStack_64a4 = (int *)0x67bf67;
                (**(code **)(*local_6410 + 0x24))();
                local_6448 = local_6410;
                local_6410[0x26] = *(int *)(*(int *)(local_6408 + 4) + 0x5e1c);
              }
            }
            else {
              local_640c = local_6410;
              puStack_64a8 = (undefined1 *)local_6410[2];
              piStack_64a4 = (int *)local_6410[3];
              piStack_64a0 = (int *)local_6410[4];
              ppuStack_649c = (undefined **)local_6410[5];
              puStack_64ac = local_24;
              FUN_004988c0();
              puStack_64a8 = (undefined1 *)local_640c[6];
              piStack_64a4 = (int *)local_640c[7];
              piStack_64a0 = (int *)local_640c[8];
              ppuStack_649c = (undefined **)local_640c[9];
              puStack_64ac = local_34;
              FUN_004988c0();
              *(undefined8 *)(local_6408 + 0x1f8) = *(undefined8 *)(local_640c + 0x2e);
              *(undefined8 *)(local_6408 + 0x200) = *(undefined8 *)(local_640c + 0x30);
              local_6418 = DAT_00a0b4e8;
              if ((DAT_00a0b4e8 < 0) || (10 < DAT_00a0b4e8)) {
                local_6418 = 0;
              }
              DAT_00a0b4e8 = local_6418;
              local_640c[0x2d] = local_6418;
              *(undefined8 *)(local_640c + 0x2e) = (&DAT_00a0b4f8)[local_6418];
              *(undefined8 *)(local_640c + 0x30) = (&DAT_00a0b658)[local_6418];
              *(undefined8 *)(local_640c + 0x32) = (&DAT_00a0b7b8)[local_6418];
              *(undefined2 *)((int)local_640c + 0x2a) = *(undefined2 *)(&DAT_00a0b918 + local_6418);
              ppuStack_649c = (undefined **)&DAT_00a0ba84;
              piStack_64a0 = (int *)0x67be27;
              FUN_00404860();
              *(ushort *)(local_640c + 0x11) = *(ushort *)(local_640c + 0x11) & 0xffdf;
              ppuStack_649c = (undefined **)0x67be45;
              FUN_00404c80();
              ppuStack_649c = (undefined **)0x67be4c;
              FUN_004fca20();
              ppuStack_649c = (undefined **)0x67be57;
              iVar2 = FUN_0067add0();
              if (iVar2 != 0) {
                *(ushort *)(local_640c + 0x11) = *(ushort *)(local_640c + 0x11) | 0x20;
              }
              *(undefined2 *)(local_640c + 0x37) = 0;
              if (DAT_00a0bc28 != 0) {
                *(ushort *)(local_640c + 0x37) = *(ushort *)(local_640c + 0x37) | 1;
              }
              if (DAT_00a0bc2c != 0) {
                *(ushort *)(local_640c + 0x37) = *(ushort *)(local_640c + 0x37) | 0x10;
              }
              ppuStack_649c = (undefined **)0x67bed2;
              FUN_00404c80();
              ppuStack_649c = (undefined **)0x67bed9;
              iVar2 = FUN_004fca20();
              *(undefined4 *)(local_6408 + 0x208) = *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xbc);
              ppuStack_649c = (undefined **)0x67bef6;
              FUN_00404c80();
              ppuStack_649c = (undefined **)0x67befd;
              iVar2 = FUN_004fca20();
              *(undefined4 *)(local_6408 + 0x20c) = *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xc0);
              ppuStack_649c = (undefined **)local_640c;
              piStack_64a0 = (int *)0x67bf27;
              FUN_0067adf0();
            }
          }
          ppuStack_649c = (undefined **)local_6430;
          piStack_64a0 = (int *)0x1;
          piStack_64a4 = local_6410;
          puStack_64a8 = *(undefined1 **)(local_6408 + 4);
          puStack_64ac = local_6474;
          FUN_00447670();
        }
      }
      ppuStack_649c = (undefined **)0x1;
      piStack_64a0 = *(int **)(local_6408 + 4);
      piStack_64a4 = (int *)local_6474;
      puStack_64a8 = (undefined1 *)0x67c051;
      FUN_00449d60();
      local_10c = 0;
      ppuStack_649c = (undefined **)&DAT_0095590a;
      piStack_64a0 = (int *)0x67c06b;
      CStringT<>();
      local_8._0_1_ = 3;
      uVar1 = (undefined1)local_8;
      local_8._0_1_ = 3;
      if (local_642c != 0) {
        ppuStack_649c = (undefined **)0x1570;
        piStack_64a0 = (int *)0x67c088;
        ppuStack_649c = (undefined **)FUN_005977f0();
        local_8._0_1_ = 4;
        piStack_64a0 = (int *)0x67c0b0;
        local_6450 = ppuStack_649c;
        local_644c = ppuStack_649c;
        FUN_00404950();
        local_8._0_1_ = 3;
        ppuStack_649c = (undefined **)0x67c0bf;
        FUN_00404770();
        uVar1 = (undefined1)local_8;
      }
      local_8._0_1_ = uVar1;
      if (local_6430 != 0) {
        ppuStack_649c = (undefined **)0x17e8;
        piStack_64a0 = (int *)0x67c0d8;
        ppuStack_649c = (undefined **)FUN_005977f0();
        local_8._0_1_ = 5;
        piStack_64a0 = (int *)0x67c100;
        local_645c = ppuStack_649c;
        local_6458 = ppuStack_649c;
        FUN_00404950();
        local_8._0_1_ = 3;
        ppuStack_649c = (undefined **)0x67c10f;
        FUN_00404770();
      }
      ppuStack_649c = (undefined **)0x0;
      piStack_64a0 = (int *)0x0;
      puStack_64ac = *(undefined1 **)(local_6408 + 4);
      piStack_64a4 = *(int **)(puStack_64ac + 0x8f28);
      puStack_64a8 = *(undefined1 **)(puStack_64ac + 0x8f24);
      local_6478 = (undefined1 *)&puStack_64ac;
      FUN_00403dd0(local_6424);
      FUN_00516ac0();
      local_8._0_1_ = 1;
      ppuStack_649c = (undefined **)0x67c15c;
      FUN_00404540();
      local_8 = (uint)local_8._1_3_ << 8;
      ppuStack_649c = (undefined **)0x67c16b;
      FUN_00447100();
      local_8 = 0xffffffff;
      ppuStack_649c = (undefined **)0x67c17d;
      FUN_0079dfff();
    }
  }
  else {
    ppuStack_649c = (undefined **)0x67b8df;
    FUN_006fe2f0();
  }
  ExceptionList = local_10;
  return;
}



