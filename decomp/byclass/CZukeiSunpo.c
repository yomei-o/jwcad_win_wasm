/* CZukeiSunpo -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiSunpo[1] */
/* 0077a660  FUN_0077a660  68 bytes, 0 callers */

undefined4 FUN_0077a660(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0077a550();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x4540);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiSunpo[6] */
/* 0077ab30  FUN_0077ab30  2546 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0077ab30(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  int local_33c;
  int local_338;
  undefined1 local_330 [208];
  undefined1 local_260 [200];
  undefined1 local_198 [400];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8ebc) = 0;
  FUN_006d7490(local_198,&DAT_0096c008);
  if (*(int *)(in_ECX + 0xac) == 0) {
    if ((*(int *)(in_ECX + 0x1a8) != DAT_00a0bcc4) || (*(int *)(in_ECX + 0x1ac) != DAT_00a0bccc)) {
      *(int *)(in_ECX + 0x1a8) = DAT_00a0bcc4;
      *(int *)(in_ECX + 0x1ac) = DAT_00a0bccc;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
        FUN_00404c80();
        FUN_004fca20();
        FUN_005da2a0();
      }
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
        FUN_00404c80();
        FUN_004fca20();
        FUN_005da370();
      }
    }
    FUN_00783610();
    if (*(double *)(in_ECX + 0x44f0) != *(double *)(in_ECX + 0x44e8)) {
      FUN_0077cc90(1);
      *(undefined8 *)(in_ECX + 0x44f0) = *(undefined8 *)(in_ECX + 0x44e8);
    }
    if (*(int *)(in_ECX + 0x1c4) == 0x15) {
      uVar2 = 0x62;
      FUN_005977f0(0x1809);
      uVar2 = FUN_00404920(uVar2);
      FUN_0060afc0(local_260,uVar2);
      FUN_00404770();
      FUN_006d7470(local_198,local_260);
      uVar2 = 0x62;
      FUN_005977f0(0x151e);
      uVar2 = FUN_00404920(uVar2);
      FUN_0060afc0(local_260,uVar2);
      FUN_00404770();
      FUN_006d7470(local_198,local_260);
      FUN_004efbb0(0x14f7,local_198,0);
    }
    else if (*(int *)(in_ECX + 0x1c4) == 0x16) {
      uVar2 = 0x62;
      FUN_005977f0(0x180a);
      uVar2 = FUN_00404920(uVar2);
      FUN_0060afc0(local_260,uVar2);
      FUN_00404770();
      FUN_006d7470(local_198,local_260);
      uVar2 = 0x62;
      FUN_005977f0(0x151e);
      uVar2 = FUN_00404920(uVar2);
      FUN_0060afc0(local_260,uVar2);
      FUN_00404770();
      FUN_006d7470(local_198,local_260);
      FUN_004efbb0(0x14f7,local_198,0);
    }
    else if ((*(int *)(in_ECX + 0x1c4) == 0x17) && (*(int *)(in_ECX + 0x1bc) == 0)) {
      uVar2 = 0x62;
      FUN_005977f0(0x180e);
      uVar2 = FUN_00404920(uVar2);
      FUN_006d74b0(local_198,uVar2);
      FUN_00404770();
      FUN_004efbb0(0x14f7,local_198,0);
    }
    else if ((*(int *)(in_ECX + 0x1c4) == 0x18) && (*(int *)(in_ECX + 0x1bc) == 0)) {
      FUN_005977f0(0x15c1);
      uVar2 = FUN_00404920();
      FUN_00480580(local_198,L"      %s",uVar2);
      FUN_00404770();
      FUN_004efbb0(0x151c,local_198,0);
    }
    else {
      *(undefined4 *)(in_ECX + 0x1b4) = 0;
      if ((*(int *)(in_ECX + 0x1c4) == 0x19) && (*(int *)(in_ECX + 0x1bc) == 3)) {
        if (*(int *)(*(int *)(in_ECX + 4) + 0x908c) != 0) {
          return;
        }
        if (*(int *)(in_ECX + 0x1d0) != 0) {
          *(undefined4 *)(in_ECX + 0x1d0) = 0;
          FUN_004fb9f0();
          return;
        }
        if (*(int *)(in_ECX + 0xb0) != 0) {
          FUN_004efbb0(0x14c6,0,0);
          *(undefined4 *)(in_ECX + 0x1b4) = 1;
          FUN_0078cd40(0,*param_1,param_1[1],param_1[2],param_1[3]);
          return;
        }
        FUN_004efbb0(0x15c8,0,0);
      }
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
        uVar2 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_005da680(uVar2);
      }
      if ((((*(int *)(in_ECX + 0x1bc) == 3) || (*(int *)(in_ECX + 0x1bc) == 6)) ||
          (*(int *)(in_ECX + 0x1bc) == 5)) || (*(int *)(in_ECX + 0x1bc) == 4)) {
        if (((*(int *)(in_ECX + 0x1c4) == 0x17) || (*(int *)(in_ECX + 0x1c4) == 0x18)) ||
           (*(int *)(in_ECX + 0x1c4) == 0x19)) {
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
            uVar2 = 1;
            FUN_00404c80(1);
            FUN_004fca20();
            FUN_005d9450(uVar2);
          }
        }
        else {
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
            uVar2 = 2;
            FUN_00404c80(2);
            FUN_004fca20();
            FUN_005d9450(uVar2);
          }
        }
      }
      else if (*(int *)(in_ECX + 0x1bc) == 2) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
          uVar2 = 1;
          FUN_00404c80(1);
          FUN_004fca20();
          FUN_005d9450(uVar2);
        }
      }
      else {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
          uVar2 = 0;
          FUN_00404c80(0);
          FUN_004fca20();
          FUN_005d9450(uVar2);
        }
      }
      if ((*(int *)(in_ECX + 0x1bc) == 0) || (*(int *)(in_ECX + 0x1bc) == 1)) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8ebc) = 1;
        if (DAT_00a0bcc0 < 1) {
          FUN_004efbb0(0x14d1,0,0);
        }
        else {
          uVar2 = 0x62;
          FUN_005977f0(0x151f);
          uVar2 = FUN_00404920(uVar2);
          FUN_00779af0(local_330,uVar2);
          FUN_00404770();
          if (DAT_00a0bcc0 == 1) {
            FUN_006d7470(local_198,L"  [ =(1) ]");
            FUN_006d7470(local_198,local_330);
            FUN_004efbb0(0x1521,local_198,0);
          }
          else if (DAT_00a0bcc0 == 2) {
            FUN_006d7470(local_198,L"  [ =(2) ]");
            FUN_006d7470(local_198,local_330);
            FUN_004efbb0(0x1521,local_198,0);
          }
          else if (DAT_00a0bcc0 == 3) {
            FUN_006d7470(local_198,L"  [ - ]");
            FUN_004efbb0(0x14d2,local_198,0);
          }
        }
      }
      if (*(int *)(in_ECX + 0x1bc) == 7) {
        FUN_004efbb0(0x1520,0,0);
        iVar1 = *(int *)(*(int *)(in_ECX + 4) + 0x8f58);
        if (*(int *)(in_ECX + 0x44e0) == iVar1 || *(int *)(in_ECX + 0x44e0) - iVar1 < 0) {
          local_338 = -(*(int *)(in_ECX + 0x44e0) - *(int *)(*(int *)(in_ECX + 4) + 0x8f58));
        }
        else {
          local_338 = *(int *)(in_ECX + 0x44e0) - *(int *)(*(int *)(in_ECX + 4) + 0x8f58);
        }
        iVar1 = *(int *)(*(int *)(in_ECX + 4) + 0x8f5c);
        if (*(int *)(in_ECX + 0x44e4) == iVar1 || *(int *)(in_ECX + 0x44e4) - iVar1 < 0) {
          local_33c = -(*(int *)(in_ECX + 0x44e4) - *(int *)(*(int *)(in_ECX + 4) + 0x8f5c));
        }
        else {
          local_33c = *(int *)(in_ECX + 0x44e4) - *(int *)(*(int *)(in_ECX + 4) + 0x8f5c);
        }
        if (2 < local_338 + local_33c) {
          *(undefined4 *)(in_ECX + 0x1bc) = 3;
          FUN_0077cc90(1);
        }
      }
    }
  }
  else {
    if (*(int *)(*(int *)(in_ECX + 0xa8) + 0x1c) == 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
        uVar2 = 3;
        FUN_00404c80(3);
        FUN_004fca20();
        FUN_005d9450(uVar2);
      }
    }
    else {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
        uVar2 = 4;
        FUN_00404c80(4);
        FUN_004fca20();
        FUN_005d9450(uVar2);
      }
    }
    FUN_00562600(param_1);
  }
  return;
}




/* vtable slots: CZukeiSunpo[16] */
/* 0077b730  FUN_0077b730  2003 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0077b730(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined1 local_63fc [20];
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009432eb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0x75] = 0;
  local_63e8 = in_ECX;
  if (in_ECX[0x2b] != 0) {
    iVar1 = FUN_00562880();
    if (iVar1 != 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_63e8[1] + 0x8630)) {
        uVar2 = 2;
        FUN_00404c80(2);
        FUN_004fca20();
        FUN_005d9450(uVar2);
      }
      local_63e8[0x2b] = 0;
    }
    FUN_00404c80();
    FUN_0056d7d0();
    ExceptionList = local_10;
    return 1;
  }
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(local_63e8[1]);
  local_8._0_1_ = 1;
  if ((local_63e8[0x71] == 0x19) && (local_63e8[0x6f] == 3)) {
    if (local_63e8[0x2c] != 0) {
      FUN_0044dd90(local_63fc,local_63e8[1]);
      local_63e8[0x2c] = 0;
      local_63e8[0x6f] = local_63e8[0x70];
      local_63e8[0x71] = local_63e8[0x72];
      FUN_0077cc90(1);
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
    if (0 < local_63e8[0x114a]) {
      local_63e8[0x114a] = local_63e8[0x114a] + -1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
  }
  if (local_63e8[0x114a] < 1) {
    if ((local_63e8[0x6f] == 10) && (local_63e8[0x71] == 0x18)) {
      local_63e8[0x6f] = 0;
      local_63e8[0x73] = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 1;
    }
    else if ((local_63e8[0x6f] == 0xb) && (local_63e8[0x71] == 0x18)) {
      local_63e8[0x6f] = 10;
      FUN_0077cc90(1);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 1;
    }
    else if ((local_63e8[0x71] == 0x14) || (0 < local_63e8[0x1147])) {
      if ((local_63e8[0x6f] == 0) || (local_63e8[0x6f] == 1)) {
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
      else if (local_63e8[0x6f] == 2) {
        local_63e8[0x6f] = 0;
        FUN_0077cc90(1);
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 1;
      }
      else if (local_63e8[0x6f] == 3) {
        if (local_63e8[0x1147] < 1) {
          if (DAT_00a0bcc0 < 1) {
            local_63e8[0x6f] = 2;
          }
          else {
            local_63e8[0x6f] = 0;
          }
        }
        else {
          FUN_0077cc90(0);
          FUN_00458a80(local_63fc,local_63e8[1],0);
          local_63e8[0x1147] = local_63e8[0x1147] + -1;
        }
        FUN_0077cc90(1);
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 1;
      }
      else if (local_63e8[0x6f] == 4) {
        local_63e8[0x6f] = 3;
        FUN_0077cc90(1);
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 1;
      }
      else if ((local_63e8[0x6f] == 5) || (local_63e8[0x6f] == 6)) {
        if (0 < local_63e8[0x1147]) {
          FUN_0077cc90(0);
          FUN_00458a80(local_63fc,local_63e8[1],0);
          local_63e8[0x1147] = local_63e8[0x1147] + -1;
        }
        local_63e8[0x6f] = 4;
        FUN_0077cc90(1);
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 1;
      }
      else {
        (**(code **)(*local_63e8 + 0x18))(local_63e8 + 0x15e);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 1;
      }
    }
    else {
      local_63e8[0x71] = 0x14;
      local_63e8[0x6f] = 0;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_63e8[1] + 0x8630)) {
        uVar2 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_005da520(uVar2);
      }
      FUN_0077cc90(1);
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
    local_63e8[0x114a] = local_63e8[0x114a] + -1;
    local_63e8[0x1147] = local_63e8[0x1147] + -1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 0;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiSunpo[0] */
/* 0077c120  FUN_0077c120  16 bytes, 0 callers */

undefined ** FUN_0077c120(void)

{
  return &PTR_s_CZukeiSunpo_0097bc08;
}




/* vtable slots: CZukeiSunpo[23] */
/* 0077d400  FUN_0077d400  139 bytes, 0 callers */

undefined4 FUN_0077d400(void)

{
  int iVar1;
  int *in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if ((*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) && (in_ECX[0x2b] == 0)) {
    if (DAT_00a0cc6c == 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
        FUN_00404c80();
        FUN_004fca20();
        FUN_0077d3e0();
      }
    }
    else {
      (**(code **)(*in_ECX + 100))();
    }
  }
  return 1;
}




/* vtable slots: CZukeiSunpo[46] */
/* 0077d640  FUN_0077d640  1778 bytes, 0 callers */

undefined4
FUN_0077d640(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  double dVar3;
  undefined8 uVar4;
  undefined4 local_18;
  int local_10;
  int local_c;
  int *local_8;
  
  if (DAT_00a0c7c0 == 0) {
    if (in_ECX[0x2b] == 0) {
      local_18 = 0;
      local_8 = in_ECX;
      if (*(int *)(in_ECX[1] + 0x9078) == 0) {
        if ((in_ECX[0x6d] != 0) && (DAT_00a0dbca == 4)) {
          local_c = -1;
          iVar1 = FUN_00778a40(0x15,&local_c,*(undefined4 *)(in_ECX[1] + 0x9070),param_1,param_2,
                               param_3,param_4,param_5,param_6,param_7,7);
          if (iVar1 != 0) {
            if (param_3 == 1) {
              return 0;
            }
            if (param_3 != 2) {
              return 0;
            }
            if ((-1 < local_c) && (local_c < 4)) {
              DAT_00a0bdb0 = local_c;
            }
            return 0;
          }
        }
        if ((0 < param_2) && (param_2 < 0xb)) {
          local_10 = -1;
          iVar1 = FUN_00778a40(0xb,&local_10,*(undefined4 *)(local_8[1] + 0x9070),param_1,param_2,
                               param_3,param_4,param_5,param_6,param_7,7);
          if (iVar1 != 0) {
            if (param_3 == 1) {
              return 0;
            }
            if (param_3 != 2) {
              return 0;
            }
            if ((0 < local_10) && (local_10 < 0xb)) {
              DAT_00a0bcd0 = local_10;
              FUN_00782350();
            }
            return 0;
          }
        }
        local_18 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      else {
        switch(param_2) {
        case 1:
          if (param_3 == 1) {
            FUN_005168b0(0x1808,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_8[1] + 0x8630)) {
              FUN_00404c80();
              FUN_004fca20();
              FUN_0077d3e0();
            }
          }
          break;
        case 2:
          if ((in_ECX[0x6f] == 0) || (in_ECX[0x6f] == 1)) {
            if (param_3 == 1) {
              FUN_005168b0(0x180b,*(undefined4 *)(in_ECX[1] + 0x8f50),
                           *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
              return 0;
            }
            if (param_3 != 2) {
              return 0;
            }
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(iVar1 + 0x1a0) != *(int *)(local_8[1] + 0x8630)) {
              return 0;
            }
            FUN_00404c80();
            FUN_004fca20();
            FUN_0077f260();
            return 0;
          }
        case 3:
          if (param_3 == 1) {
            FUN_005168b0(0x1447,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            (**(code **)(*in_ECX + 100))();
          }
          break;
        case 4:
          if (param_3 == 1) {
            FUN_005168b0(0x1809,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_8[1] + 0x8630)) {
              FUN_00404c80();
              FUN_004fca20();
              FUN_005da520();
            }
            (**(code **)(*local_8 + 0x68))();
          }
          break;
        case 5:
          if (param_3 == 1) {
            FUN_005168b0(0x180a,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_8[1] + 0x8630)) {
              FUN_00404c80();
              FUN_004fca20();
              FUN_005da520();
            }
            (**(code **)(*local_8 + 0x6c))();
          }
          break;
        default:
          local_18 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          break;
        case 0xc:
          if (((DAT_00a0bcc0 == 1) || (DAT_00a0bcc0 == 2)) &&
             ((in_ECX[0x6f] == 3 ||
              (((in_ECX[0x6f] == 6 || (in_ECX[0x6f] == 5)) || (in_ECX[0x6f] == 4)))))) {
            if (param_3 == 1) {
              FUN_005168b0(0x1805,*(undefined4 *)(in_ECX[1] + 0x8f50),
                           *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
            }
            else if (param_3 == 2) {
              in_ECX[0x1148] = in_ECX[0x1148] ^ 1;
              FUN_0077cc90();
            }
          }
          else if (param_3 == 1) {
            FUN_005168b0(0x1810,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            uVar4 = 0;
            FUN_00404c80(0);
            iVar1 = FUN_004fca20();
            if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_8[1] + 0x8630)) {
              FUN_00404c80(uVar4);
              FUN_004fca20();
              fVar2 = (float10)FUN_005da8c0();
              dVar3 = -(double)fVar2;
              FUN_00404c80(dVar3);
              FUN_004fca20();
              FUN_005da640(dVar3);
            }
          }
        }
      }
    }
    else if ((*(int *)(in_ECX[1] + 0x9078) == 0) || (param_2 != 3)) {
      if ((*(int *)(in_ECX[1] + 0x9078) == 0) &&
         ((param_2 == 0xc && (*(int *)(in_ECX[0x2a] + 0x1c) != 0)))) {
        if (param_3 == 1) {
          FUN_005168b0(0x18b1,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x88))();
        }
        local_18 = 0;
      }
      else {
        local_18 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      if (param_3 == 1) {
        FUN_005168b0(0x1447,*(undefined4 *)(in_ECX[1] + 0x8f50),*(undefined4 *)(in_ECX[1] + 0x8f54),
                     1,0);
      }
      else if (param_3 == 2) {
        (**(code **)(*in_ECX + 100))();
      }
      local_18 = 0;
    }
  }
  else {
    local_18 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_18;
}




/* vtable slots: CZukeiSunpo[47] */
/* 0077dd70  FUN_0077dd70  1240 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0077dd70(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 local_63f4;
  int local_63ec;
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009433d0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0c7c0 == 0) {
    local_63f4 = 0;
    if (*(int *)(in_ECX[1] + 0x907c) == 0) {
      local_63e8 = in_ECX;
      FUN_00446aa0(local_14);
      local_8 = 0;
      local_63ec = -1;
      iVar1 = FUN_00778a40(0xc,&local_63ec,*(undefined4 *)(local_63e8[1] + 0x9074),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,5);
      if (iVar1 == 0) {
        if (param_2 == 1) {
          if (param_3 == 1) {
            FUN_005168b0(0x15cb,*(undefined4 *)(local_63e8[1] + 0x8f50),
                         *(undefined4 *)(local_63e8[1] + 0x8f54),1,0);
          }
          else if ((param_3 == 2) &&
                  (iVar1 = FUN_0078b140(param_4,param_5,param_6,param_7,0), iVar1 != 0)) {
            FUN_0078cd40(0,param_4,param_5,param_6,param_7);
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_63e8[1] + 0x8630)) {
              uVar2 = 1;
              FUN_00404c80(1);
              FUN_004fca20();
              FUN_005da680(uVar2);
            }
          }
        }
        else if (param_2 == 2) {
          if (param_3 == 1) {
            FUN_005168b0(0x15cc,*(undefined4 *)(local_63e8[1] + 0x8f50),
                         *(undefined4 *)(local_63e8[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            local_63e8[0x75] = 1;
            FUN_0078b140(param_4,param_5,param_6,param_7,1);
          }
        }
        else if (param_2 == 0xb) {
          if (param_3 == 1) {
            FUN_005168b0(0x1808,*(undefined4 *)(local_63e8[1] + 0x8f50),
                         *(undefined4 *)(local_63e8[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_00404c80();
            iVar1 = FUN_004fca20();
            if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_63e8[1] + 0x8630)) {
              FUN_00404c80();
              FUN_004fca20();
              FUN_0077d3e0();
            }
          }
        }
        else {
          local_63f4 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        }
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (param_3 == 1) {
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63f4 = 0;
      }
      else if (param_3 == 2) {
        if ((local_63ec < 0) || (9 < local_63ec)) {
          local_8 = 0xffffffff;
          FUN_00447100();
          local_63f4 = 0;
        }
        else {
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_63e8[1] + 0x8630)) {
            if (local_63ec < 9) {
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              *(int *)(*(int *)(iVar1 + 0x1a0) + 0x270) = local_63ec;
            }
            else {
              local_63e8[0x6c] = 1;
              (**(code **)(*local_63e8 + 0x80))();
            }
          }
          local_8 = 0xffffffff;
          FUN_00447100();
          local_63f4 = 0;
        }
      }
      else {
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63f4 = 0;
      }
    }
    else {
      local_63f4 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_63f4 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return local_63f4;
}




/* vtable slots: CZukeiSunpo[34] */
/* 0077e4c0  FUN_0077e4c0  165 bytes, 0 callers */

void FUN_0077e4c0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  FUN_0077a9b0();
  if (*(int *)(in_ECX + 0xac) != 0) {
    FUN_0077c130();
  }
  *(undefined4 *)(in_ECX + 0xac) = 0;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
    uVar2 = 2;
    FUN_00404c80(2);
    FUN_004fca20();
    FUN_005d9450(uVar2);
  }
  *(undefined4 *)(in_ECX + 0x1bc) = 3;
  (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x8590) + 0xc))();
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiSunpo[25] */
/* 0077e6e0  FUN_0077e6e0  643 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0077e6e0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093711b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0077a9b0(local_14);
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_63ec = *(int *)(local_63e8 + 4);
  if (local_63ec == 0) {
    local_63f0 = 0;
  }
  else {
    local_63f0 = local_63ec + 0x88;
  }
  FUN_00454890(local_63f0);
  FUN_0044de00(local_6404,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd90(local_6404,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd20(local_6404,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c830(local_6404,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0x1bc) = 0;
  *(undefined4 *)(local_63e8 + 0x1c4) = 0x14;
  *(undefined4 *)(local_63e8 + 0x451c) = 0;
  *(undefined4 *)(local_63e8 + 0xac) = 0;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8630)) {
    uVar2 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_005d9450(uVar2);
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8630)) {
    uVar2 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_005da520(uVar2);
  }
  FUN_0077cc90(1);
  *(undefined4 *)(local_63e8 + 0x4528) = 0;
  *(undefined4 *)(local_63e8 + 0xb0) = 0;
  *(undefined4 *)(local_63e8 + 0x1d0) = 0;
  FUN_00404900(&DAT_00956338);
  *(undefined4 *)(local_63e8 + 0x1d4) = 0;
  FUN_00782350();
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSunpo[26] */
/* 0077e970  FUN_0077e970  213 bytes, 0 callers */

void FUN_0077e970(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_0077a9b0();
  if (in_ECX[0x6f] != 3) {
    (**(code **)(*in_ECX + 100))();
  }
  in_ECX[0x71] = 0x15;
  uVar1 = FUN_0040c0e0();
  iVar2 = FUN_00572560(uVar1);
  if (iVar2 == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
      uVar1 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_005d9450(uVar1);
    }
  }
  else {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
      uVar1 = 2;
      FUN_00404c80(2);
      FUN_004fca20();
      FUN_005d9450(uVar1);
    }
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiSunpo[27] */
/* 0077ea50  FUN_0077ea50  213 bytes, 0 callers */

void FUN_0077ea50(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_0077a9b0();
  if (in_ECX[0x6f] != 3) {
    (**(code **)(*in_ECX + 100))();
  }
  in_ECX[0x71] = 0x16;
  uVar1 = FUN_0040c0e0();
  iVar2 = FUN_00572560(uVar1);
  if (iVar2 == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
      uVar1 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_005d9450(uVar1);
    }
  }
  else {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
      uVar1 = 2;
      FUN_00404c80(2);
      FUN_004fca20();
      FUN_005d9450(uVar1);
    }
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiSunpo[28] */
/* 0077eb30  FUN_0077eb30  114 bytes, 0 callers */

void FUN_0077eb30(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  FUN_0077a9b0();
  (**(code **)(*in_ECX + 100))();
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
    uVar2 = 4;
    FUN_00404c80(4);
    FUN_004fca20();
    FUN_005da520(uVar2);
  }
  in_ECX[0x71] = 0x17;
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiSunpo[29] */
/* 0077ecc0  FUN_0077ecc0  114 bytes, 0 callers */

void FUN_0077ecc0(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  FUN_0077a9b0();
  (**(code **)(*in_ECX + 100))();
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
    uVar2 = 5;
    FUN_00404c80(5);
    FUN_004fca20();
    FUN_005da520(uVar2);
  }
  in_ECX[0x71] = 0x18;
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiSunpo[30] */
/* 0077ed40  FUN_0077ed40  137 bytes, 0 callers */

void FUN_0077ed40(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  FUN_0077a9b0();
  (**(code **)(*in_ECX + 100))();
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
    uVar2 = 6;
    FUN_00404c80(6);
    FUN_004fca20();
    FUN_005da520(uVar2);
  }
  in_ECX[0x71] = 0x19;
  in_ECX[0x6f] = 3;
  FUN_0077cc90(1);
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiSunpo[31] */
/* 0077edd0  FUN_0077edd0  255 bytes, 0 callers */

void FUN_0077edd0(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  FUN_0077a9b0();
  if ((in_ECX[0x71] == 0x17) || (in_ECX[0x71] == 0x18)) {
    (**(code **)(*in_ECX + 100))();
  }
  in_ECX[0x71] = 0x1a;
  if ((((in_ECX[0x6f] == 3) || (in_ECX[0x6f] == 6)) || (in_ECX[0x6f] == 5)) || (in_ECX[0x6f] == 4))
  {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
      uVar2 = 2;
      FUN_00404c80(2);
      FUN_004fca20();
      FUN_005d9450(uVar2);
    }
  }
  else {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8630)) {
      uVar2 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_005d9450(uVar2);
    }
  }
  FUN_0077cc90(1);
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiSunpo[32] */
/* 0077eed0  FUN_0077eed0  755 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0077eed0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined1 local_6408 [20];
  int local_63f4;
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00943486;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  if ((((*(int *)(in_ECX + 0x1bc) == 3) && (*(int *)(in_ECX + 0x1c4) == 0x19)) ||
      (*(int *)(in_ECX + 0x1b0) != 0)) &&
     ((*(int *)(in_ECX + 0xb0) != 0 || (*(int *)(in_ECX + 0x1b0) != 0)))) {
    local_63f4 = DAT_00a0bdb0;
    *(undefined4 *)(in_ECX + 0x1b0) = 0;
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0044dd90(local_6408,*(undefined4 *)(local_63e8 + 4));
    local_63f0 = 0;
    local_63ec = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8630)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      local_63f0 = *(int *)(*(int *)(iVar1 + 0x1a0) + 0x270) % 3;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      local_63ec = *(int *)(*(int *)(iVar1 + 0x1a0) + 0x270) / 3;
    }
    FUN_00550480(0);
    local_8 = CONCAT31(local_8._1_3_,2);
    iVar2 = local_63f0 * 3 + (2 - local_63ec);
    iVar1 = FUN_0079850d();
    if (iVar1 == 1) {
      local_63f0 = iVar2 / 3;
      local_63ec = 2 - iVar2 % 3;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8630)) {
        iVar2 = local_63ec * 3 + local_63f0;
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(int *)(*(int *)(iVar1 + 0x1a0) + 0x270) = iVar2;
        if (local_63f4 != DAT_00a0bdb0) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_005da370();
        }
      }
    }
    local_8._0_1_ = 1;
    FUN_00550710();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_0050f6f0(local_14);
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8630)) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_005da2a0();
    }
    FUN_00782350();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSunpo[33] */
/* 0077f1d0  FUN_0077f1d0  107 bytes, 0 callers */

void FUN_0077f1d0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  *(undefined4 *)(in_ECX + 0xac) = 1;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
    uVar2 = 3;
    FUN_00404c80(3);
    FUN_004fca20();
    FUN_005d9450(uVar2);
  }
  FUN_005634f0();
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiSunpo[36] */
/* 0077f240  FUN_0077f240  19 bytes, 0 callers */

void FUN_0077f240(void)

{
  FUN_00782350();
  return;
}




/* vtable slots: CZukeiSunpo[49] */
/* 0077f280  FUN_0077f280  81 bytes, 0 callers */

void FUN_0077f280(undefined8 param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_005da640(param_1);
  }
  return;
}




/* vtable slots: CZukeiSunpo[50] */
/* 0077f2e0  FUN_0077f2e0  451 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0077f2e0(double param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 local_218 [516];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009434cb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  if ((((*(int *)(in_ECX + 0x1bc) == 3) && (*(int *)(in_ECX + 0x1c4) == 0x19)) &&
      (*(int *)(in_ECX + 0x1d0) != 0)) || (*(int *)(in_ECX + 0x1d4) != 0)) {
    if (DAT_00a0bcc8 != 0) {
      param_1 = param_1 / DAT_00a0d630;
    }
    iVar1 = FUN_0045a220(local_218,param_1,DAT_00a0bcc4,DAT_00a0bd40,DAT_00a0bd3c,DAT_00a0bd44);
    if (iVar1 != 0) {
      if (DAT_00a0bd34 != 0) {
        FUN_00786cf0(local_218);
      }
      FUN_00464040();
      local_8._0_1_ = 1;
      FUN_00473110(local_218);
      FUN_00404900(local_218);
      FUN_0078b140();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004640a0();
    }
    *(undefined4 *)(in_ECX + 0x1d4) = 0;
  }
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSunpo[51] */
/* 0077f4b0  FUN_0077f4b0  210 bytes, 0 callers */

void FUN_0077f4b0(undefined8 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8630)) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_005da640(param_1);
  }
  if (((*(int *)(in_ECX + 0x54) != 0) && (0 < *(int *)(*(int *)(in_ECX + 0x54) + 0xb4))) &&
     (*(int *)(*(int *)(in_ECX + 0x54) + 0xb4) < 0xb)) {
    DAT_00a0bcd0 = *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0xb4);
    FUN_00782350();
  }
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSunpo[15] */
/* 0077f590  FUN_0077f590  354 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0077f590(void)

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
  if (*(int *)(in_ECX + 0xac) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0077cc90(0);
    FUN_00453bd0(local_6400,*(undefined4 *)(local_63e8 + 4),0);
    if (((*(int *)(local_63e8 + 0x1bc) == 5) || (*(int *)(local_63e8 + 0x1bc) == 6)) ||
       (*(int *)(local_63e8 + 0x1bc) == 4)) {
      *(undefined4 *)(local_63e8 + 0x1bc) = 3;
    }
    if (*(int *)(local_63e8 + 0x1bc) == 3) {
      *(int *)(local_63e8 + 0x451c) = *(int *)(local_63e8 + 0x451c) + 1;
    }
    FUN_0077cc90(1);
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_63ec = 1;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiSunpo[12] */
/* 0077f700  FUN_0077f700  664 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0077f700(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int local_63ec;
  int local_63e8;
  undefined4 local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009216e0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63ec = 0;
  FUN_00446aa0(local_14);
  local_8 = 0;
  if (DAT_00a0bdbc != 0) {
    local_20 = 1;
  }
  if ((*(int *)(local_63e8 + 0x1c4) == 0x18) && (*(int *)(local_63e8 + 0x1bc) == 1)) {
    iVar1 = FUN_0044a270(3,*(undefined4 *)(local_63e8 + 4),&param_2,&local_63ec,1);
    if ((iVar1 == 0) || (local_63ec == 0)) {
      *(undefined4 *)(local_63e8 + 0x1bc) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar1 == 0) {
        FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f28),0,0);
        *(undefined4 *)(local_63e8 + 0x1bc) = 0;
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
      else {
        FUN_00420110(local_63ec);
        FUN_00455ab0(local_63e8 + 0x1d8,param_2,param_3,param_4,param_5);
        *(undefined4 *)(local_63e8 + 0x1cc) = 1;
        *(undefined4 *)(local_63e8 + 0x1bc) = 10;
        FUN_0077cc90(1);
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = FUN_0077fda0(param_1,param_2,param_3,param_4,param_5);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiSunpo[9] */
/* 0077fda0  FUN_0077fda0  3006 bytes, 2 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0077fda0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_6498 [20];
  uint local_6484;
  int local_6480;
  int local_647c;
  int *local_6478;
  undefined1 local_6474 [25536];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
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
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092ceeb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0x75] = 0;
  if (in_ECX[0x2b] == 0) {
    if (in_ECX[0x71] == 0x15) {
      uVar1 = FUN_007891b0(0,0,param_2,param_3,param_4,param_5);
    }
    else if (in_ECX[0x71] == 0x16) {
      uVar1 = FUN_007891b0(1,0,param_2,param_3,param_4,param_5);
    }
    else {
      local_6478 = in_ECX;
      if ((in_ECX[0x71] == 0x17) && (in_ECX[0x6f] == 0)) {
        local_6480 = FUN_0077bf10(param_2,param_3,param_4,param_5);
        local_6478[0xde] = local_6480;
        if (local_6480 == 0) {
          uVar1 = 0;
        }
        else {
          FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
          local_6478[0xdf] = local_6478[0xde];
          local_6478[0x6f] = 1;
          FUN_0077cc90(1);
          FUN_00404c80();
          FUN_0056d7d0();
          uVar1 = 0;
        }
      }
      else if ((in_ECX[0x71] == 0x18) && (in_ECX[0x6f] == 0)) {
        FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
        local_6478[0xdf] = (int)(local_6478 + 300);
        local_6478[0x6f] = 1;
        FUN_0077cc90(1);
        FUN_00404c80();
        FUN_0056d7d0();
        uVar1 = 0;
      }
      else {
        FUN_00446aa0(local_14);
        local_8 = 0;
        FUN_0079dea2(local_6478[1]);
        local_8._0_1_ = 1;
        if (DAT_00a0bdbc != 0) {
          local_b0 = 1;
        }
        if ((local_6478[0x71] == 0x18) && (local_6478[0x6f] == 10)) {
          iVar2 = FUN_0044a270(3,local_6478[1],&param_2,&local_647c,1);
          if ((iVar2 == 0) || (local_647c == 0)) {
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
            if (iVar2 == 0) {
              FUN_005168b0(0x14de,*(undefined4 *)(local_6478[1] + 0x8f24),
                           *(undefined4 *)(local_6478[1] + 0x8f28),0,0);
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
            else {
              FUN_00408a60();
              iVar2 = FUN_0045fa30(local_6478 + 0x76,local_647c,*(undefined4 *)(local_647c + 8),
                                   *(undefined4 *)(local_647c + 0xc),
                                   *(undefined4 *)(local_647c + 0x10),
                                   *(undefined4 *)(local_647c + 0x14),local_34);
              if (iVar2 == 0) {
                FUN_005168b0(0x1455,*(undefined4 *)(local_6478[1] + 0x8f24),
                             *(undefined4 *)(local_6478[1] + 0x8f28),0,0);
              }
              else {
                FUN_00420110(local_647c);
                FUN_00455ab0(local_6478 + 0x90,param_2,param_3,param_4,param_5);
                local_6478[0x73] = 1;
                local_6478[0x6f] = 0xb;
              }
              FUN_0077cc90(1);
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
          }
        }
        else if ((local_6478[0x6f] == 0xb) && (local_6478[0x71] == 0x18)) {
          FUN_004988c0(local_64,param_2,param_3,param_4,param_5);
          local_6478[0x6f] = 0xc;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 1;
        }
        else {
          if ((local_6478[0x71] == 0x19) && (local_6478[0x6f] == 3)) {
            if (local_6478[0x2c] != 0) {
              FUN_0078cd40(1,param_2,param_3,param_4,param_5);
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 0;
            }
          }
          else {
            local_6478[0x114a] = 0;
          }
          if ((local_6478[0x6f] == 0) || (local_6478[0x6f] == 1)) {
            FUN_004988c0(local_74,param_2,param_3,param_4,param_5);
            iVar2 = *(int *)(local_6478[1] + 0x8f5c);
            local_6478[0x1138] = *(int *)(local_6478[1] + 0x8f58);
            local_6478[0x1139] = iVar2;
            local_6478[0x1148] = 0;
            local_6478[0x6f] = 2;
            if (0 < DAT_00a0bcc0) {
              FUN_00783690();
            }
            FUN_0077cc90(1);
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else if (local_6478[0x6f] == 2) {
            FUN_004988c0(local_84,param_2,param_3,param_4,param_5);
            local_6478[0x6f] = 3;
            FUN_0077cc90(1);
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else if (local_6478[0x6f] == 7) {
            local_6478[0x1148] = 1;
            local_6478[0x6f] = 3;
            FUN_0077cc90(1);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            local_24 = param_2;
            local_20 = param_3;
            local_1c = param_4;
            local_18 = param_5;
            if (param_1 != 0x231d) {
              local_b4 = 1;
              iVar2 = FUN_00451eb0(local_6478[1],&local_24,0);
              if (iVar2 == 0) {
                FUN_00404c80();
                FUN_0056d7d0();
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return 0;
              }
            }
            if ((local_6478[0x6f] == 5) || (local_6478[0x6f] == 6)) {
              if (param_1 == 0x231d) {
                uVar1 = (**(code **)(*local_6478 + 0x2c))(0x4a2d,param_2,param_3,param_4,param_5);
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return uVar1;
              }
              local_6478[0x6f] = 3;
            }
            if (local_6478[0x6f] == 3) {
              FUN_004988c0(local_94,local_24,local_20,local_1c,local_18);
              local_6478[0x1145] = 1;
              local_6478[0x1146] = 0;
              local_6478[0x6f] = 4;
              FUN_0077cc90(1);
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
            else {
              FUN_004988c0(local_a4,local_24,local_20,local_1c,local_18);
              FUN_0077cc90(0);
              local_6484 = (uint)(local_6478[0x71] == 0x19);
              iVar2 = FUN_00783730(local_6474,local_6498,local_6484,
                                   *(undefined4 *)
                                    (local_6478[1] + 0x24ec + *(int *)(local_6478[1] + 0x256c) * 4))
              ;
              if (iVar2 == 1) {
                if (local_6478[0x71] == 0x1a) {
                  local_6478[0x6f] = 4;
                }
                else {
                  local_6478[0x6f] = 5;
                }
              }
              FUN_0077cc90(1);
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 1;
            }
          }
        }
      }
    }
  }
  else {
    FUN_005637b0(param_1,param_2,param_3,param_4,param_5);
    uVar1 = 0;
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiSunpo[13] */
/* 00780960  FUN_00780960  160 bytes, 0 callers */

undefined4
FUN_00780960(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x1c4) == 0x18) && (*(int *)(in_ECX + 0x1bc) == 1)) {
    uVar1 = 0;
  }
  else if ((*(int *)(in_ECX + 0x1bc) == 3) && (*(int *)(in_ECX + 0x1c4) == 0x19)) {
    *(undefined4 *)(in_ECX + 0xb0) = 0;
    FUN_0078b140(param_2,param_3,param_4,param_5,1);
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00780a70(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiSunpo[11] */
/* 00780a70  FUN_00780a70  2700 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00780a70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined1 local_647c [20];
  int *local_6468;
  undefined1 local_6464 [25536];
  undefined4 local_a4;
  undefined4 local_a0;
  undefined1 local_94 [16];
  undefined1 local_84 [16];
  undefined1 local_74 [16];
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094356b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0x75] = 0;
  local_6468 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(local_6468[1]);
  local_8._0_1_ = 1;
  if (DAT_00a0bdbc != 0) {
    local_a0 = 1;
  }
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  if (param_1 != 0x4a2d) {
    if (local_6468[0x2b] != 0) {
      iVar1 = FUN_00564350(param_1,param_2,param_3,param_4,param_5);
      if (iVar1 != 0) {
        FUN_0077c130();
        local_6468[0x2b] = 0;
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_6468[1] + 0x8630)) {
          uVar2 = 2;
          FUN_00404c80(2);
          FUN_004fca20();
          FUN_005d9450(uVar2);
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if (local_6468[0x71] == 0x15) {
      uVar2 = FUN_007891b0(0,1,param_2,param_3,param_4,param_5);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
    if (local_6468[0x71] == 0x16) {
      uVar2 = FUN_007891b0(1,1,param_2,param_3,param_4,param_5);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
    if ((local_6468[0x71] == 0x17) && (local_6468[0x6f] == 0)) {
      iVar1 = FUN_0077bf10(param_2,param_3,param_4,param_5);
      local_6468[0xde] = iVar1;
      if (iVar1 == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
      local_6468[0xdf] = local_6468[0xde];
      local_6468[0x6f] = 1;
      FUN_0077cc90(1);
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if ((local_6468[0x71] == 0x18) && (local_6468[0x6f] == 10)) {
      uVar2 = (**(code **)(*local_6468 + 0x24))(param_1,param_2,param_3,param_4,param_5);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
    if ((local_6468[0x6f] == 0xb) && (local_6468[0x71] == 0x18)) {
      iVar1 = FUN_00451eb0(local_6468[1],&local_24,1);
      if (iVar1 == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      uVar2 = FUN_0077fda0(0x231d,local_24,local_20,local_1c,local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
    if ((local_6468[0x6f] == 3) && (local_6468[0x71] == 0x19)) {
      if (local_6468[0x2c] == 0) {
        iVar1 = FUN_0078b140(param_2,param_3,param_4,param_5,0);
        if (iVar1 != 0) {
          FUN_0078cd40(0,local_24,local_20,local_1c,local_18);
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_6468[1] + 0x8630)) {
            uVar2 = 1;
            FUN_00404c80(1);
            FUN_004fca20();
            FUN_005da680(uVar2);
          }
        }
      }
      else {
        iVar1 = FUN_00451eb0(local_6468[1],&local_24,1);
        if (iVar1 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        FUN_0078cd40(1,local_24,local_20,local_1c,local_18);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    local_6468[0x114a] = 0;
    if ((((local_6468[0x6f] == 0) || (local_6468[0x6f] == 1)) || (local_6468[0x6f] == 2)) ||
       (local_6468[0x6f] == 7)) {
      iVar1 = FUN_00451eb0(local_6468[1],&local_24,1);
      if (iVar1 == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      uVar2 = FUN_0077fda0(0x231d,local_24,local_20,local_1c,local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
    local_a4 = 1;
    iVar1 = FUN_00451eb0(local_6468[1],&local_24,0);
    if (iVar1 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if ((local_6468[0x6f] == 3) || (local_6468[0x6f] == 4)) {
      uVar2 = FUN_0077fda0(0x231d,local_24,local_20,local_1c,local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return uVar2;
    }
  }
  local_34 = local_6468[0x166];
  local_30 = local_6468[0x167];
  local_2c = local_6468[0x168];
  local_28 = local_6468[0x169];
  local_44 = local_6468[0x16a];
  local_40 = local_6468[0x16b];
  local_3c = local_6468[0x16c];
  local_38 = local_6468[0x16d];
  FUN_004988c0(local_64,local_6468[0x16a],local_6468[0x16b],local_6468[0x16c],local_6468[0x16d]);
  FUN_004988c0(local_74,local_24,local_20,local_1c,local_18);
  iVar1 = FUN_00783730(local_6464,local_647c,local_6468[0x71] == 0x19,
                       *(undefined4 *)
                        (local_6468[1] + 0x24ec + *(int *)(local_6468[1] + 0x256c) * 4));
  if (iVar1 == 1) {
    if (local_6468[0x71] != 0x1a) {
      local_6468[0x6f] = 6;
    }
  }
  else if (local_6468[0x71] != 0x1a) {
    FUN_004988c0(local_84,local_34,local_30,local_2c,local_28);
    FUN_004988c0(local_94,local_44,local_40,local_3c,local_38);
  }
  FUN_0077cc90(1);
  (**(code **)(*local_6468 + 0x18))(&local_24);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CZukeiSunpo[8] */
/* 00781520  FUN_00781520  3624 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00781520(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  double local_664c;
  double local_6644;
  double local_6618;
  undefined1 local_23c [152];
  undefined1 local_1a4 [16];
  undefined1 local_194 [16];
  undefined1 local_184 [16];
  undefined1 local_174 [16];
  undefined1 local_164 [16];
  undefined1 local_154 [16];
  undefined1 local_144 [16];
  undefined1 local_134 [16];
  undefined1 local_124 [16];
  undefined1 local_114 [16];
  undefined1 local_104 [16];
  undefined1 local_f4 [16];
  undefined1 local_e4 [16];
  undefined1 local_d4 [16];
  undefined1 local_c4 [16];
  undefined1 local_b4 [16];
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
  undefined8 local_84;
  undefined8 local_7c;
  undefined4 local_74;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_64;
  undefined4 local_60;
  undefined8 local_5c;
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
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009435c6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_00464040();
  local_8._0_1_ = 1;
  FUN_00408a60();
  local_6618 = 1.0;
  if (*(int *)(in_ECX + 0x4520) != 0) {
    local_6618 = -1.0;
  }
  if ((*(int *)(in_ECX + 0x1c4) == 0x17) || (*(int *)(in_ECX + 0x1c4) == 0x18)) {
    if ((*(int *)(in_ECX + 0x1bc) == 0) || (*(int *)(in_ECX + 0x1bc) == 1)) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004640a0();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (*(int *)(in_ECX + 0x37c) == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004640a0();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if ((DAT_00a0bcc0 == 1) || (DAT_00a0bcc0 == 2)) {
      FUN_0041f5f0();
      local_8 = CONCAT31(local_8._1_3_,2);
      local_664c = DAT_00a0bd70;
      local_6644 = DAT_00a0bd78;
      if (DAT_00a0bcc0 == 1) {
        local_664c = DAT_00a0bd60;
        local_6644 = DAT_00a0bd68;
      }
      local_6644 = local_6618 * local_6644;
      local_664c = local_6618 * local_664c;
      FUN_004988c0(local_f4,*(undefined4 *)(in_ECX + 0x558),*(undefined4 *)(in_ECX + 0x55c),
                   *(undefined4 *)(in_ECX + 0x560),*(undefined4 *)(in_ECX + 0x564));
      iVar1 = FUN_004763b0(*(undefined4 *)(in_ECX + 0x37c),local_54,local_50,local_4c,local_48,
                           local_23c);
      if (iVar1 == 0) {
        FUN_0042f5e0(0x9abcaf48,0x3e7ad7f2);
      }
      iVar1 = FUN_004751a0(local_23c,local_664c,in_ECX + 0x380);
      if (iVar1 == 0) {
        FUN_0042f5e0(0x9abcaf48,0x3e7ad7f2);
      }
      (**(code **)(*(int *)(in_ECX + 0x380) + 0x20))(9);
      iVar1 = FUN_004751a0(local_23c,local_6644,in_ECX + 0x418);
      if (iVar1 == 0) {
        FUN_0042f5e0(0x88e368f0,0x3ee4f8b5);
      }
      (**(code **)(*(int *)(in_ECX + 0x380) + 0x20))(2);
      local_8._0_1_ = 1;
      FUN_0041fd50();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004640a0();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      if (DAT_00a0bcc0 == 3) {
        FUN_004988c0(local_104,*(undefined4 *)(in_ECX + 0x558),*(undefined4 *)(in_ECX + 0x55c),
                     *(undefined4 *)(in_ECX + 0x560),*(undefined4 *)(in_ECX + 0x564));
      }
      fVar2 = (float10)FUN_0040c180();
      if (0.001 <= (double)fVar2) {
        FUN_004988c0(local_114,*(undefined4 *)(in_ECX + 0x558),*(undefined4 *)(in_ECX + 0x55c),
                     *(undefined4 *)(in_ECX + 0x560),*(undefined4 *)(in_ECX + 0x564));
        iVar1 = FUN_004763b0(*(undefined4 *)(in_ECX + 0x37c),local_54,local_50,local_4c,local_48,
                             in_ECX + 0x380);
        if (iVar1 == 0) {
          FUN_0042f5e0(0x9abcaf48,0x3e7ad7f2);
        }
        (**(code **)(*(int *)(in_ECX + 0x380) + 0x20))(9);
        if (*(int *)(in_ECX + 0x1bc) == 2) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_004640a0();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          FUN_004988c0(local_124,*(undefined4 *)(in_ECX + 0x548),*(undefined4 *)(in_ECX + 0x54c),
                       *(undefined4 *)(in_ECX + 0x550),*(undefined4 *)(in_ECX + 0x554));
          iVar1 = FUN_004763b0(*(undefined4 *)(in_ECX + 0x37c),local_54,local_50,local_4c,local_48,
                               in_ECX + 0x418);
          if (iVar1 == 0) {
            FUN_0042f5e0(0x88e368f0,0x3ee4f8b5);
          }
          (**(code **)(*(int *)(in_ECX + 0x418) + 0x20))(2);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_004640a0();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
      else {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_004640a0();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
  }
  else {
    FUN_00783610();
    *(double *)(in_ECX + 0x44f8) = (*(double *)(in_ECX + 0x44e8) * 3.141592653589793) / 180.0;
    fVar2 = (float10)FUN_008f8eb0((int)*(undefined8 *)(in_ECX + 0x44f8),
                                  (int)((ulonglong)*(undefined8 *)(in_ECX + 0x44f8) >> 0x20));
    *(double *)(in_ECX + 0x4508) = (double)fVar2;
    fVar2 = (float10)FUN_008f8f00((int)*(undefined8 *)(in_ECX + 0x44f8),
                                  (int)((ulonglong)*(undefined8 *)(in_ECX + 0x44f8) >> 0x20));
    *(double *)(in_ECX + 0x4500) = (double)fVar2;
    FUN_004988c0(local_94,*(undefined4 *)(in_ECX + 0x558),*(undefined4 *)(in_ECX + 0x55c),
                 *(undefined4 *)(in_ECX + 0x560),*(undefined4 *)(in_ECX + 0x564));
    FUN_004988c0(local_e4,*(undefined4 *)(in_ECX + 0x548),*(undefined4 *)(in_ECX + 0x54c),
                 *(undefined4 *)(in_ECX + 0x550),*(undefined4 *)(in_ECX + 0x554));
    local_44 = *(undefined4 *)(in_ECX + 0x558);
    uStack_40 = *(undefined4 *)(in_ECX + 0x55c);
    local_3c = *(undefined4 *)(in_ECX + 0x560);
    uStack_38 = *(undefined4 *)(in_ECX + 0x564);
    local_34 = *(undefined4 *)(in_ECX + 0x548);
    uStack_30 = *(undefined4 *)(in_ECX + 0x54c);
    local_2c = *(undefined4 *)(in_ECX + 0x550);
    uStack_28 = *(undefined4 *)(in_ECX + 0x554);
    FUN_00408a60();
    FUN_00408a60();
    FUN_00408a60();
    FUN_00408a60();
    if ((*(int *)(in_ECX + 0x1bc) == 0) || (*(int *)(in_ECX + 0x1bc) == 1)) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004640a0();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_005f89c0(*(undefined4 *)(in_ECX + 0x568),*(undefined4 *)(in_ECX + 0x56c),
                   *(undefined4 *)(in_ECX + 0x570),*(undefined4 *)(in_ECX + 0x574),
                   (int)*(undefined8 *)(in_ECX + 0x44e8),
                   (int)((ulonglong)*(undefined8 *)(in_ECX + 0x44e8) >> 0x20),0);
      FUN_004988c0(local_d4,*(undefined4 *)(in_ECX + 0x558),*(undefined4 *)(in_ECX + 0x55c),
                   *(undefined4 *)(in_ECX + 0x560),*(undefined4 *)(in_ECX + 0x564));
      FUN_004988c0(local_c4,*(undefined4 *)(in_ECX + 0x548),*(undefined4 *)(in_ECX + 0x54c),
                   *(undefined4 *)(in_ECX + 0x550),*(undefined4 *)(in_ECX + 0x554));
      if (DAT_00a0bcc0 == 1) {
        FUN_005f92e0(&local_64);
        local_5c = -local_6618 * DAT_00a0bd60;
        FUN_005f8ce0(&local_64);
        FUN_004988c0(local_b4,local_64,local_60,(undefined4)local_5c,local_5c._4_4_);
        FUN_004988c0(local_a4,local_44,uStack_40,local_3c,uStack_38);
        FUN_005f92e0(&local_74);
        local_6c = -local_6618 * DAT_00a0bd68;
        FUN_005f8ce0(&local_74);
        FUN_004988c0(local_134,local_74,local_70,(undefined4)local_6c,local_6c._4_4_);
        FUN_004988c0(local_144,local_34,uStack_30,local_2c,uStack_28);
      }
      else if (DAT_00a0bcc0 == 2) {
        FUN_005f92e0(&local_64);
        local_5c = -local_6618 * DAT_00a0bd70;
        FUN_005f8ce0(&local_64);
        FUN_004988c0(local_154,local_64,local_60,(undefined4)local_5c,local_5c._4_4_);
        FUN_004988c0(local_164,local_44,uStack_40,local_3c,uStack_38);
        FUN_005f92e0(&local_74);
        local_6c = -local_6618 * DAT_00a0bd78;
        FUN_005f8ce0(&local_74);
        FUN_004988c0(local_174,local_74,local_70,(undefined4)local_6c,local_6c._4_4_);
        FUN_004988c0(local_184,local_34,uStack_30,local_2c,uStack_28);
      }
      else if (DAT_00a0bcc0 == 3) {
        FUN_004988c0(local_194,*(undefined4 *)(in_ECX + 0x568),*(undefined4 *)(in_ECX + 0x56c),
                     *(undefined4 *)(in_ECX + 0x570),*(undefined4 *)(in_ECX + 0x574));
        FUN_004988c0(local_1a4,*(undefined4 *)(in_ECX + 0x568),*(undefined4 *)(in_ECX + 0x56c),
                     *(undefined4 *)(in_ECX + 0x570),*(undefined4 *)(in_ECX + 0x574));
      }
      if (DAT_00a0bcc0 != 3) {
        local_24 = (double)CONCAT44(uStack_40,local_44) -
                   *(double *)(in_ECX + 0x4508) * 20000000000.0;
        local_1c = (double)CONCAT44(uStack_38,local_3c) -
                   *(double *)(in_ECX + 0x4500) * 20000000000.0;
        local_84 = *(double *)(in_ECX + 0x4508) * 20000000000.0 +
                   (double)CONCAT44(uStack_40,local_44);
        local_7c = *(double *)(in_ECX + 0x4500) * 20000000000.0 +
                   (double)CONCAT44(uStack_38,local_3c);
        FUN_0040da70(local_24,local_1c);
        FUN_0040da20((undefined4)local_84,local_84._4_4_,(undefined4)local_7c,local_7c._4_4_);
        FUN_0040da70((undefined4)local_24,local_24._4_4_,(undefined4)local_1c,local_1c._4_4_);
        (**(code **)(*(int *)(in_ECX + 0x2a8) + 0x20))(9);
      }
      if (*(int *)(in_ECX + 0x1bc) == 2) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_004640a0();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        local_24 = (double)CONCAT44(uStack_30,local_34) -
                   *(double *)(in_ECX + 0x4508) * 20000000000.0;
        local_1c = (double)CONCAT44(uStack_28,local_2c) -
                   *(double *)(in_ECX + 0x4500) * 20000000000.0;
        local_84 = *(double *)(in_ECX + 0x4508) * 20000000000.0 +
                   (double)CONCAT44(uStack_30,local_34);
        local_7c = *(double *)(in_ECX + 0x4500) * 20000000000.0 +
                   (double)CONCAT44(uStack_28,local_2c);
        FUN_0040da70(local_24,local_1c);
        FUN_0040da20((undefined4)local_84,local_84._4_4_,(undefined4)local_7c,local_7c._4_4_);
        FUN_0040da70((undefined4)local_24,local_24._4_4_,(undefined4)local_1c,local_1c._4_4_);
        (**(code **)(*(int *)(in_ECX + 0x310) + 0x20))(2);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_004640a0();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSunpo[3] */
/* 00783270  FUN_00783270  914 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00783270(void)

{
  undefined4 *puVar1;
  int iVar2;
  float10 fVar3;
  undefined1 local_6478 [20];
  undefined4 local_6464;
  undefined4 local_6460;
  undefined4 local_645c;
  int local_6458;
  undefined1 local_6454 [25552];
  undefined1 local_84 [16];
  undefined1 local_74 [16];
  undefined1 local_64 [32];
  undefined1 local_44 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00943736;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8._0_1_ = 1;
  FUN_00464040();
  local_8._0_1_ = 2;
  if ((*(int *)(local_6458 + 0x1bc) == 0xc) && (*(int *)(local_6458 + 0x1c4) == 0x18)) {
    FUN_00408a60();
    puVar1 = (undefined4 *)CMFCCaptionButtonEx::GetRect((CMFCCaptionButtonEx *)(local_6458 + 0x1d8))
    ;
    FUN_004988c0(local_44,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    puVar1 = (undefined4 *)CMFCCaptionButtonEx::GetRect((CMFCCaptionButtonEx *)(local_6458 + 0x240))
    ;
    FUN_004988c0(local_64,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    FUN_004988c0(local_74,*(undefined4 *)(local_6458 + 0x548),*(undefined4 *)(local_6458 + 0x54c),
                 *(undefined4 *)(local_6458 + 0x550),*(undefined4 *)(local_6458 + 0x554));
    iVar2 = FUN_004619b0(local_6458 + 0x1d8,local_6458 + 0x240,*(undefined4 *)(local_6458 + 0x598),
                         *(undefined4 *)(local_6458 + 0x59c),*(undefined4 *)(local_6458 + 0x5a0),
                         *(undefined4 *)(local_6458 + 0x5a4),&local_24);
    if (iVar2 == 0) {
      FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6458 + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(local_6458 + 4) + 0x8f28),0,0);
    }
    else {
      local_645c = *(undefined4 *)
                    (*(int *)(local_6458 + 4) + 0x24ec +
                    *(int *)(*(int *)(local_6458 + 4) + 0x256c) * 4);
      local_6460 = 0;
      FUN_004988c0(local_84,local_24,local_20,local_1c,local_18);
      fVar3 = (float10)FUN_0043ad70(local_24,local_20,local_1c,local_18,
                                    *(undefined4 *)(local_6458 + 0x548),
                                    *(undefined4 *)(local_6458 + 0x54c),
                                    *(undefined4 *)(local_6458 + 0x550),
                                    *(undefined4 *)(local_6458 + 0x554));
      FUN_0042f5e0((double)fVar3);
      FUN_00420020();
      FUN_00420020();
      local_6464 = FUN_00786fb0(1,local_6454,local_6478,local_6460,local_645c);
    }
    *(undefined4 *)(local_6458 + 0x1bc) = 0;
    *(undefined4 *)(local_6458 + 0x1cc) = 0;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  local_8._0_1_ = 1;
  FUN_004640a0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



