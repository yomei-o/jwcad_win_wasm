/* CZukeiFukusen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiFukusen[1] */
/* 00656330  FUN_00656330  68 bytes, 0 callers */

undefined4 FUN_00656330(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006562c0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x2d8);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiFukusen[6] */
/* 00656f10  FUN_00656f10  1876 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00656f10(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  undefined4 uVar4;
  double local_6420;
  int local_6418;
  int local_6410;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938c20;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8ebc) = 0;
  local_14 = uVar1;
  FUN_004988c0(local_24,*param_1,param_1[1],param_1[2],param_1[3]);
  FUN_00446aa0(uVar1);
  local_8 = 0;
  if (in_ECX[0xac] != 0) {
    FUN_006f7cc0(param_1);
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  if (in_ECX[0xa1] == 2) {
    FUN_004988c0(local_34,*param_1,param_1[1],param_1[2],param_1[3]);
    in_ECX[0x84] = -in_ECX[0x84];
  }
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  in_ECX[0x7e] = *(int *)(*(int *)(iVar2 + 0x1a0) + 0x780);
  if ((in_ECX[0x82] == in_ECX[0x81]) && (in_ECX[0x80] == in_ECX[0x7e])) {
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_004b2320();
    if (*(double *)(in_ECX + 0x8e) == (double)fVar3) goto LAB_00657392;
  }
  in_ECX[0x80] = in_ECX[0x7e];
  FUN_00404c80();
  FUN_004fca20();
  fVar3 = (float10)FUN_004b2320();
  *(double *)(in_ECX + 0x8e) = (double)fVar3;
  in_ECX[0x84] = 0;
  if (in_ECX[1] == 0) {
    local_6410 = 0;
  }
  else {
    local_6410 = in_ECX[1] + 0x88;
  }
  iVar2 = FUN_0044fcd0(local_6410);
  if ((iVar2 == 1) || (in_ECX[0x7e] == 1)) {
LAB_00657206:
    uVar4 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007979e8(uVar4);
    uVar4 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007979e8(uVar4);
    uVar4 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007979e8(uVar4);
    uVar4 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007979e8(uVar4);
  }
  else {
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_004b2320();
    if ((double)fVar3 <= 0.0) {
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_004b2320();
      local_6420 = -(double)fVar3;
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_004b2320();
      local_6420 = (double)fVar3;
    }
    if (local_6420 < 1e-07) goto LAB_00657206;
    uVar4 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_007979e8(uVar4);
    uVar4 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_007979e8(uVar4);
    uVar4 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_007979e8(uVar4);
    uVar4 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_007979e8(uVar4);
  }
  if (in_ECX[0x7e] == 0) {
    uVar4 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_00797f20(uVar4);
  }
  else {
    uVar4 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007979e8(uVar4);
    uVar4 = 5;
    FUN_00404c80(5);
    FUN_004fca20();
    FUN_00797f20(uVar4);
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    in_ECX[0x7f] = *(int *)(*(int *)(iVar2 + 0x1a0) + 0x808);
  }
LAB_00657392:
  if (in_ECX[0x82] != in_ECX[0x81]) {
    in_ECX[0x82] = in_ECX[0x81];
    uVar4 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_007979e8(uVar4);
    if (in_ECX[0x81] != 0) {
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar4);
    }
    if (in_ECX[1] == 0) {
      local_6418 = 0;
    }
    else {
      local_6418 = in_ECX[1] + 0x88;
    }
    iVar2 = FUN_0044fcd0(local_6418);
    if (((iVar2 == 1) || (in_ECX[0x87] != 1)) || (in_ECX[0x93] == 1)) {
      in_ECX[0xa0] = 0;
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar4);
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar4);
    }
    else {
      if (in_ECX[0x81] == 3) {
        if ((in_ECX[0x97] == 0) || (in_ECX[0x87] != 1)) {
          in_ECX[0xa0] = 0;
        }
        else {
          in_ECX[0xa0] = 1;
          uVar4 = 1;
          FUN_00404c80(1);
          FUN_004fca20();
          FUN_007979e8(uVar4);
        }
      }
      else {
        in_ECX[0xa0] = 0;
        uVar4 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_007979e8(uVar4);
      }
      uVar4 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_007979e8(uVar4);
    }
    if (*(int *)(in_ECX[1] + 0x17d8) == 0x8020) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_00797df8();
    }
  }
  FUN_00658890();
  if ((*(int *)(in_ECX[1] + 0x17f0) != 0) &&
     (*(undefined4 *)(in_ECX[1] + 0x17f0) = 0, *(int *)(in_ECX[1] + 0x17d8) == 0x8020)) {
    FUN_00404c80();
    FUN_004fca20();
    FUN_00797df8();
  }
  (**(code **)(*in_ECX + 0x20))();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[16] */
/* 00657670  FUN_00657670  904 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00657670(void)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  undefined1 local_640c [20];
  undefined4 local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092999b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63ec = 0;
  *(undefined4 *)(in_ECX + 0x254) = 0;
  local_63e8 = in_ECX;
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    if (*(int *)(in_ECX + 0x284) == 0) {
      *(undefined4 *)(in_ECX + 0x210) = 0;
      *(undefined8 *)(in_ECX + 0x220) = 0x44ea779600edd808;
      FUN_00446aa0(local_14);
      local_8 = 0;
      FUN_0079dea2();
      local_8._0_1_ = 1;
      if ((*(int *)(local_63e8 + 0x204) == 3) && (local_63ec == 0)) {
        FUN_0044dd90(local_640c,*(undefined4 *)(local_63e8 + 4));
        *(undefined4 *)(local_63e8 + 0x204) = 2;
        uVar2 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_004b2250(uVar2);
        FUN_00658890();
        local_63f0 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if ((*(int *)(local_63e8 + 0x204) == 3) || (*(int *)(local_63e8 + 0x204) == 2)) {
        *(undefined4 *)(local_63e8 + 0x204) = 0;
        *(undefined4 *)(local_63e8 + 0x20c) = 0;
        FUN_0044dd90(local_640c,*(undefined4 *)(local_63e8 + 4));
        FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_640c);
        FUN_00449d60(local_640c,*(undefined4 *)(local_63e8 + 4),1);
        uVar2 = *(undefined8 *)(local_63e8 + 0x2d0);
        FUN_00404c80(uVar2);
        FUN_004fca20();
        FUN_004b2250(uVar2);
        FUN_00658890();
        local_63f4 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63f0 = local_63f4;
      }
      else {
        FUN_00658890();
        local_63f8 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63f0 = local_63f8;
      }
    }
    else {
      *(int *)(in_ECX + 0x284) = *(int *)(in_ECX + 0x284) + 1;
      if (3 < *(int *)(in_ECX + 0x284)) {
        *(undefined4 *)(in_ECX + 0x284) = 0;
      }
      FUN_00658890();
      *(int *)(local_63e8 + 0x210) = -*(int *)(local_63e8 + 0x210);
      FUN_00404c80();
      FUN_0056d7d0();
      local_63f0 = 1;
    }
  }
  else {
    iVar1 = FUN_006f85c0();
    if (iVar1 == 0) {
      *(undefined4 *)(local_63e8 + 0x2b0) = 0;
      FUN_00656380();
      *(undefined4 *)(local_63e8 + 0x204) = 0;
      local_63f0 = 1;
    }
    else {
      local_63f0 = 1;
    }
  }
  ExceptionList = local_10;
  return local_63f0;
}




/* vtable slots: CZukeiFukusen[0] */
/* 00658880  FUN_00658880  16 bytes, 0 callers */

undefined ** FUN_00658880(void)

{
  return &PTR_s_CZukeiFukusen_00978300;
}




/* vtable slots: CZukeiFukusen[23] */
/* 0065aa60  FUN_0065aa60  346 bytes, 0 callers */

undefined4 FUN_0065aa60(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  double local_18;
  double local_10;
  
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x85f4)) {
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_004b2320();
      if ((double)fVar3 <= 0.0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_004b2320();
        local_18 = -(double)fVar3;
      }
      else {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_004b2320();
        local_18 = (double)fVar3;
      }
      if (1e-07 < local_18) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_004b2320();
        if (DAT_00a0cc6c == 0) {
          local_10 = (double)fVar3 / 2.0;
        }
        else {
          local_10 = (double)fVar3 * 2.0;
        }
        FUN_00404c80(local_10);
        FUN_004fca20();
        FUN_004b2250(local_10);
        FUN_00404c80();
        FUN_004fca20();
        FUN_004b1ea0();
        return 1;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_006f8be0();
  }
  return uVar1;
}




/* vtable slots: CZukeiFukusen[46] */
/* 0065abc0  FUN_0065abc0  1160 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0065abc0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  double dVar4;
  undefined4 local_3c;
  double local_38;
  undefined4 local_30;
  int *local_2c;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0xac] == 0) {
    if ((in_ECX[0x81] == 0) && (DAT_00a0c7c0 != 0)) {
      uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      if (*(int *)(in_ECX[1] + 0x9078) == 0) {
        local_3c = 0xffffffff;
        local_2c = in_ECX;
        iVar2 = FUN_00778a40(1,&local_3c,*(undefined4 *)(in_ECX[1] + 0x9070),param_1,param_2,param_3
                             ,param_4,param_5,param_6,param_7,0xb);
        if (iVar2 != 0) {
          return 0;
        }
        if (((param_2 == 3) && (local_2c[0xa0] != 0)) && (local_2c[0x97] != 0)) {
          if (param_3 == 1) {
            FUN_005168b0(0x1582,*(undefined4 *)(local_2c[1] + 0x8f50),
                         *(undefined4 *)(local_2c[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            local_2c[0xb0] = 0;
            local_2c[0x95] = 0;
            FUN_004988c0(local_18,param_4,param_5,param_6,param_7);
            local_2c[0xa1] = 2;
            FUN_00404c80();
            FUN_0056d7d0();
          }
          return 0;
        }
        if (param_2 == 4) {
          if (param_3 == 1) {
            FUN_005168b0(0x141c,*(undefined4 *)(local_2c[1] + 0x8f50),
                         *(undefined4 *)(local_2c[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            (**(code **)(*local_2c + 0x70))();
            FUN_004988c0(local_28,param_4,param_5,param_6,param_7);
            FUN_0040c9d0();
            *(undefined4 *)(local_2c[2] + 4) = 1;
          }
          return 0;
        }
        if ((param_2 == 0xc) && (local_2c[0x81] != 0)) {
          if (param_3 == 1) {
            FUN_005168b0(0x2733,*(undefined4 *)(local_2c[1] + 0x8f50),
                         *(undefined4 *)(local_2c[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_005156d0();
            local_2c[0x84] = -local_2c[0x84];
            (**(code **)(*local_2c + 0x20))();
          }
          return 0;
        }
      }
      else if ((in_ECX[0x81] == 3) && ((param_2 == 0xc || (param_2 == 6)))) {
        if (param_3 == 1) {
          local_30 = 0x2791;
          if (param_2 == 6) {
            local_30 = 0x2792;
          }
          FUN_005168b0(local_30,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_004b2320();
          if (param_2 == 0xc) {
            local_38 = (double)fVar3 * 2.0;
          }
          else {
            local_38 = (double)fVar3 / 2.0;
          }
          dVar4 = local_38;
          FUN_00404c80(local_38);
          FUN_004fca20();
          FUN_004b2250(dVar4);
          FUN_00404c80();
          FUN_004fca20();
          FUN_004b1ea0();
        }
        return 0;
      }
      uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else if ((*(int *)(in_ECX[1] + 0x9078) == 0) && (param_2 == 0xc)) {
    if (param_3 == 1) {
      FUN_005168b0(0x147c,*(undefined4 *)(in_ECX[1] + 0x8f50),*(undefined4 *)(in_ECX[1] + 0x8f54),1,
                   0);
    }
    else if (param_3 == 2) {
      (**(code **)(*in_ECX + 0x88))();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiFukusen[47] */
/* 0065b050  FUN_0065b050  775 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0065b050(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_63fc;
  int local_63f8;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938a20;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0x204) == 0) && (DAT_00a0c7c0 != 0)) {
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
    local_63fc = 0xffffffff;
    local_63f8 = in_ECX;
    iVar2 = FUN_00778a40(2,&local_63fc,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9074),param_1,
                         param_2,param_3,param_4,param_5,param_6,param_7,0xb);
    if (iVar2 == 0) {
      if (((param_2 == 3) && (*(int *)(local_63f8 + 0x280) != 0)) &&
         (*(int *)(local_63f8 + 0x25c) != 0)) {
        if (param_3 == 1) {
          FUN_005168b0(0x1582,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f50),
                       *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00446aa0();
          local_8 = 0;
          iVar2 = FUN_00451eb0(*(undefined4 *)(local_63f8 + 4),&param_4,1);
          if (iVar2 == 0) {
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
          *(undefined4 *)(local_63f8 + 0x2c0) = 0;
          *(undefined4 *)(local_63f8 + 0x254) = 0;
          FUN_004988c0(local_24,param_4,param_5,param_6,param_7);
          *(undefined4 *)(local_63f8 + 0x284) = 2;
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_2 == 1) {
    uVar1 = FUN_0076a270(param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiFukusen[34] */
/* 0065b360  FUN_0065b360  396 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065b360(void)

{
  undefined8 uVar1;
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
  FUN_0079dea2();
  local_8._0_1_ = 1;
  FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd20(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044de00(local_63fc,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0x2b0) = 0;
  FUN_00656380();
  FUN_00659200();
  if (*(int *)(local_63e8 + 0x204) == 0) {
    *(undefined4 *)(local_63e8 + 0x204) = 2;
  }
  uVar1 = *(undefined8 *)(local_63e8 + 0x2b8);
  FUN_00404c80(uVar1);
  FUN_004fca20();
  FUN_004b2250(uVar1);
  *(undefined4 *)(local_63e8 + 0x210) = 0xfffffc19;
  *(undefined4 *)(local_63e8 + 0x208) = 0xffffffff;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[25] */
/* 0065b4f0  FUN_0065b4f0  548 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065b4f0(void)

{
  int *in_ECX;
  float10 fVar1;
  undefined1 local_640c [20];
  double local_63f8;
  double local_63f0;
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092999b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0xb0] = 0;
  in_ECX[0x95] = 0;
  in_ECX[0xa1] = 0;
  if (in_ECX[0xac] == 0) {
    in_ECX[0x84] = 0;
    in_ECX[0x88] = 0xedd808;
    in_ECX[0x89] = 0x44ea7796;
    local_63e8 = in_ECX;
    FUN_00404c80(local_14);
    FUN_004fca20();
    fVar1 = (float10)FUN_004b2320();
    local_63f0 = (double)fVar1;
    local_63f8 = local_63f0;
    if (local_63f0 <= 0.0) {
      local_63f8 = -local_63f0;
    }
    if (1e-07 < local_63f8) {
      *(double *)(local_63e8 + 0x8a) =
           *(double *)(local_63e8 + 0x8a) + *(double *)(local_63e8 + 0x8c);
      if (local_63e8[0xa2] != 0) {
        local_63e8[0xa1] = 1;
      }
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2();
      local_8._0_1_ = 1;
      FUN_0044dd90(local_640c,local_63e8[1]);
      FUN_0065a340(local_63e8[0x92],*(undefined8 *)(local_63e8 + 0x8a));
      (**(code **)(*local_63e8 + 0xc))();
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




/* vtable slots: CZukeiFukusen[26] */
/* 0065b720  FUN_0065b720  84 bytes, 0 callers */

void FUN_0065b720(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c0) = 0;
  *(undefined4 *)(in_ECX + 0x254) = 0;
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    *(undefined4 *)(in_ECX + 0x284) = 3;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiFukusen[27] */
/* 0065b780  FUN_0065b780  949 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065b780(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_642c [20];
  undefined4 local_6418;
  undefined4 local_6414;
  int local_6410;
  int local_640c;
  int local_6408;
  int *local_6404;
  int local_6400;
  CMFCCaptionButtonEx *local_63fc;
  int local_63f8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938e5b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x2c0) = 0;
  *(undefined4 *)(in_ECX + 0x254) = 0;
  *(undefined4 *)(in_ECX + 0x284) = 0;
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    if (*(int *)(in_ECX + 0x204) != 0) {
      local_63f8 = in_ECX;
      FUN_00446aa0(local_14);
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
      local_8._0_1_ = 1;
      local_6408 = *(int *)(local_63f8 + 4);
      if (local_6408 == 0) {
        local_640c = 0;
      }
      else {
        local_640c = local_6408 + 0x88;
      }
      iVar1 = FUN_0044fcd0(local_640c);
      if (iVar1 == 0) {
        if (*(int *)(local_63f8 + 0x24c) == 0) {
          FUN_0044dd90(local_642c,*(undefined4 *)(local_63f8 + 4));
          local_63fc = (CMFCCaptionButtonEx *)0x0;
          local_6414 = FUN_0040c0e0();
          local_6400 = 0;
          local_6410 = FUN_00572b10();
          do {
            if ((local_6410 == 0) ||
               (local_63fc = (CMFCCaptionButtonEx *)FUN_00572b30(&local_6410,0),
               local_63fc == (CMFCCaptionButtonEx *)0x0)) {
              if (local_63fc == (CMFCCaptionButtonEx *)0x0) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return;
              }
              CMFCCaptionButtonEx::GetRect(local_63fc);
              FUN_0044c830(local_642c,*(undefined4 *)(local_63f8 + 4));
              if (*(int *)(local_63f8 + 600) != 0) {
                local_6404 = *(int **)(local_63f8 + 600);
                if (local_6404 == (int *)0x0) {
                  local_6418 = 0;
                }
                else {
                  local_6418 = (**(code **)(*local_6404 + 4))(1);
                }
                *(undefined4 *)(local_63f8 + 600) = 0;
              }
              *(undefined4 *)(local_63f8 + 0x25c) = 0;
              iVar1 = FUN_0040f830(local_24,local_20,local_1c,local_18,1);
              if (iVar1 == 0) {
                *(undefined4 *)(local_63f8 + 0x204) = 0;
              }
              else {
                FUN_00659200();
              }
              *(undefined4 *)(local_63f8 + 0x210) = 0xfffffc19;
              *(undefined4 *)(local_63f8 + 0x208) = 0xffffffff;
              FUN_00658890();
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return;
            }
            local_6400 = local_6400 + 1;
          } while (local_6400 < 2);
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
      else {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
  }
  else {
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[28] */
/* 0065bb40  FUN_0065bb40  137 bytes, 0 callers */

void FUN_0065bb40(void)

{
  int in_ECX;
  float10 fVar1;
  
  *(undefined4 *)(in_ECX + 0x2c0) = 0;
  *(undefined4 *)(in_ECX + 0x254) = 0;
  *(undefined4 *)(in_ECX + 0x284) = 0;
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    FUN_00404c80();
    FUN_004fca20();
    fVar1 = (float10)FUN_004b2320();
    *(double *)(in_ECX + 0x2b8) = (double)fVar1;
    *(undefined4 *)(in_ECX + 0x2b0) = 1;
    FUN_00656380();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiFukusen[29] */
/* 0065bbd0  FUN_0065bbd0  618 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065bbd0(void)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  undefined8 uVar3;
  undefined1 local_6404 [20];
  double local_63f0;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938eb6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    FUN_00464040();
    local_8._0_1_ = 2;
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004b2320();
    local_63f0 = (double)fVar2;
    FUN_0065e9e0(0,local_63f0,0);
    uVar1 = FUN_00476900(local_63e4,local_6404,*(undefined4 *)(local_63e8 + 4),1);
    *(undefined4 *)(local_63e8 + 0x250) = uVar1;
    *(undefined4 *)(local_63e8 + 0x210) = 0;
    *(undefined8 *)(local_63e8 + 0x220) = 0x44ea779600edd808;
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    *(undefined4 *)(local_63e8 + 0x254) = 0;
    FUN_00404c80();
    FUN_004fca20();
    FUN_007979e8();
    *(undefined4 *)(local_63e8 + 0x204) = 0;
    *(undefined4 *)(local_63e8 + 0x20c) = 0;
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004b2320();
    *(double *)(local_63e8 + 0x2d0) = (double)fVar2;
    uVar3 = *(undefined8 *)(local_63e8 + 0x2d0);
    FUN_00404c80(uVar3);
    FUN_004fca20();
    FUN_004b2250(uVar3);
    FUN_00404c80();
    FUN_004fca20();
    FUN_004b1ea0();
    *(undefined4 *)(local_63e8 + 0x284) = 0;
    FUN_00658890();
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8578) = 1;
    local_8._0_1_ = 1;
    FUN_004640a0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_006fb760();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[30] */
/* 0065be40  FUN_0065be40  603 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065be40(void)

{
  int in_ECX;
  float10 fVar1;
  float10 fVar2;
  undefined8 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938f06;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    FUN_00464040();
    local_8._0_1_ = 2;
    FUN_00404c80();
    FUN_004fca20();
    fVar1 = (float10)FUN_004b2320();
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004b2390();
    FUN_0065e9e0(1,(double)fVar1,(double)fVar2);
    *(undefined4 *)(in_ECX + 0x210) = 0;
    *(undefined8 *)(in_ECX + 0x220) = 0x44ea779600edd808;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    *(undefined4 *)(in_ECX + 0x254) = 0;
    FUN_00404c80();
    FUN_004fca20();
    FUN_007979e8();
    *(undefined4 *)(in_ECX + 0x204) = 0;
    *(undefined4 *)(in_ECX + 0x20c) = 0;
    FUN_00404c80();
    FUN_004fca20();
    fVar1 = (float10)FUN_004b2320();
    *(double *)(in_ECX + 0x2d0) = (double)fVar1;
    uVar3 = *(undefined8 *)(in_ECX + 0x2d0);
    FUN_00404c80(uVar3);
    FUN_004fca20();
    FUN_004b2250(uVar3);
    FUN_00404c80();
    FUN_004fca20();
    FUN_004b1ea0();
    *(undefined4 *)(in_ECX + 0x284) = 0;
    FUN_00658890();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
    local_8._0_1_ = 1;
    FUN_004640a0();
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




/* vtable slots: CZukeiFukusen[36] */
/* 0065c0a0  FUN_0065c0a0  564 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065c0a0(void)

{
  int *in_ECX;
  float10 fVar1;
  undefined4 uVar2;
  undefined1 local_640c [20];
  double local_63f8;
  double local_63f0;
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092999b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0xac] == 0) {
    if (DAT_00a0cb20 != 0) {
      local_63e8 = in_ECX;
      FUN_00446aa0(local_14);
      local_8 = 0;
      FUN_0079dea2(local_63e8[1]);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_00404c80();
      FUN_004fca20();
      fVar1 = (float10)FUN_004b2320();
      local_63f0 = (double)fVar1;
      if (local_63e8[0x86] == 1) {
        local_63f8 = local_63f0;
        if (local_63f0 <= 0.0) {
          local_63f8 = -local_63f0;
        }
        if (1e-07 < local_63f8) {
          local_63e8[0xb0] = 0;
          local_63e8[0xb2] = 1;
          (**(code **)(*local_63e8 + 0xc))();
          if (local_63e8[0x94] != 0) {
            if (*(int *)(local_63e8[1] + 0x17d8) == 0x8020) {
              uVar2 = 0;
              FUN_00404c80(0);
              FUN_004fca20();
              FUN_007979e8(uVar2);
              FUN_00404c80();
              FUN_004fca20();
              FUN_00797df8();
            }
            local_63e8[0x81] = 2;
            FUN_00447b90(local_640c,2,local_63e8[1],local_63e8[0x94],1,1);
            FUN_00659200();
            FUN_00658890();
          }
        }
      }
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    FUN_006fc3e0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[50] */
/* 0065c2e0  FUN_0065c2e0  125 bytes, 1 callers */

void FUN_0065c2e0(double param_1)

{
  int in_ECX;
  undefined8 uVar1;
  
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    *(undefined4 *)(in_ECX + 0x20c) = 1;
    *(double *)(in_ECX + 0x2d0) =
         param_1 / *(double *)
                    (*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
    uVar1 = *(undefined8 *)(in_ECX + 0x2d0);
    FUN_00404c80(uVar1);
    FUN_004fca20();
    FUN_004b2250(uVar1);
  }
  return;
}




/* vtable slots: CZukeiFukusen[51] */
/* 0065c360  FUN_0065c360  98 bytes, 0 callers */

void FUN_0065c360(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0065c2e0(param_3);
  local_8 = 0xffffffff;
  FUN_00404540(uVar1);
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[15] */
/* 0065c3d0  FUN_0065c3d0  67 bytes, 0 callers */

undefined4 FUN_0065c3d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    *(undefined4 *)(in_ECX + 0x210) = 0;
    *(undefined8 *)(in_ECX + 0x220) = 0x44ea779600edd808;
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0042ddf0();
  }
  return uVar1;
}




/* vtable slots: CZukeiFukusen[12] */
/* 0065c420  FUN_0065c420  112 bytes, 0 callers */

void FUN_0065c420(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *in_ECX;
  
  if (in_ECX[0xac] == 0) {
    (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    FUN_006fcae0(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}




/* vtable slots: CZukeiFukusen[10] */
/* 0065c490  FUN_0065c490  1184 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065c490(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined8 uVar4;
  undefined1 local_6428 [20];
  int *local_6414;
  int local_6410;
  int local_640c;
  int local_6408;
  int local_6404;
  int local_6400;
  int local_63fc;
  int local_63f8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938f4b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x210) = 0;
  *(undefined8 *)(in_ECX + 0x220) = 0x44ea779600edd808;
  *(undefined4 *)(in_ECX + 0x204) = 0;
  local_63f8 = in_ECX;
  local_14 = uVar1;
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar2 = FUN_0040c0e0();
  iVar3 = FUN_0079d98a(&PTR_s_CZukeiFukusen_00978300,uVar1,uVar2);
  if (iVar3 != 0) {
    local_63fc = *(int *)(local_63f8 + 4);
    if (local_63fc == 0) {
      local_6400 = 0;
    }
    else {
      local_6400 = local_63fc + 0x88;
    }
    FUN_00454890();
    FUN_0044c990(*(undefined4 *)(local_63f8 + 4),local_6428);
    FUN_00449d60(local_6428,*(undefined4 *)(local_63f8 + 4),1);
  }
  local_6404 = *(int *)(local_63f8 + 4);
  if (local_6404 == 0) {
    local_6408 = 0;
  }
  else {
    local_6408 = local_6404 + 0x88;
  }
  iVar3 = FUN_0044fcd0();
  if (iVar3 == 0) {
    iVar3 = FUN_00659200();
    if (iVar3 == 0) {
      local_640c = *(int *)(local_63f8 + 4);
      if (local_640c == 0) {
        local_6410 = 0;
      }
      else {
        local_6410 = local_640c + 0x88;
      }
      FUN_00454890();
      FUN_0044c990(*(undefined4 *)(local_63f8 + 4),local_6428);
      FUN_00449d60(local_6428,*(undefined4 *)(local_63f8 + 4),1);
      FUN_00658890();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    if (*(int *)(*(int *)(local_63f8 + 4) + 0x9068) == 0) {
      if (*(int *)(*(int *)(local_63f8 + 4) + 0x906c) == 0) {
        *(undefined4 *)(local_63f8 + 0x204) = 2;
        uVar4 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_004b2250(uVar4);
      }
      else {
        *(undefined4 *)(local_63f8 + 0x204) = 3;
        *(undefined4 *)(local_63f8 + 0x20c) = 1;
      }
    }
    else {
      *(undefined4 *)(local_63f8 + 0x204) = 2;
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_004b2250(uVar4);
    }
  }
  else if ((*(int *)(*(int *)(local_63f8 + 4) + 0x9068) == 0) &&
          (*(int *)(*(int *)(local_63f8 + 4) + 0x906c) == 0)) {
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    local_6414 = (int *)(*(int *)(iVar3 + 0x1a0) + 0x3e0);
    (**(code **)(*local_6414 + 0x184))();
  }
  else {
    iVar3 = *(int *)(local_63f8 + 4);
    local_24 = *(undefined4 *)(iVar3 + 0x8f68);
    local_20 = *(undefined4 *)(iVar3 + 0x8f6c);
    local_1c = *(undefined4 *)(iVar3 + 0x8f70);
    local_18 = *(undefined4 *)(iVar3 + 0x8f74);
    iVar3 = FUN_00657f10(local_24,local_20,local_1c,local_18);
    if (iVar3 != 0) {
      if (*(int *)(*(int *)(local_63f8 + 4) + 0x9068) == 0) {
        if (*(int *)(*(int *)(local_63f8 + 4) + 0x906c) != 0) {
          *(undefined4 *)(local_63f8 + 0x204) = 3;
          *(undefined4 *)(local_63f8 + 0x20c) = 1;
        }
      }
      else {
        *(undefined4 *)(local_63f8 + 0x204) = 2;
        uVar4 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_004b2250(uVar4);
      }
    }
  }
  FUN_00658890();
  *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x85a8) = 0;
  *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x85b4) = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[9] */
/* 0065c930  FUN_0065c930  2043 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0065c930(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  undefined8 uVar4;
  double dVar5;
  double local_6468;
  double local_6460;
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938f9b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x288) = 0;
  *(undefined4 *)(in_ECX + 0x2c0) = 0;
  *(undefined4 *)(in_ECX + 0x2c8) = 0;
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    if ((*(int *)(in_ECX + 0x284) == 3) || (*(int *)(in_ECX + 0x284) == 2)) {
      if (*(int *)(in_ECX + 0x284) == 3) {
        FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      }
      else {
        fVar3 = (float10)FUN_0043ad70(*(undefined4 *)(in_ECX + 0x290),
                                      *(undefined4 *)(in_ECX + 0x294),
                                      *(undefined4 *)(in_ECX + 0x298),
                                      *(undefined4 *)(in_ECX + 0x29c),param_2,param_3,param_4,
                                      param_5);
        if ((double)fVar3 < 1e-07) {
          FUN_005168b0(0x14df,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
      }
      *(int *)(in_ECX + 0x284) = *(int *)(in_ECX + 0x284) + -1;
      FUN_00658890();
      if (*(int *)(in_ECX + 0x284) == 1) {
        *(int *)(in_ECX + 0x210) = -*(int *)(in_ECX + 0x210);
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 0x210) = 0;
      *(undefined8 *)(in_ECX + 0x220) = 0x44ea779600edd808;
      if (*(int *)(in_ECX + 0x204) == 0) {
        *(undefined4 *)(in_ECX + 0x20c) = 0;
        iVar2 = FUN_00657f10(param_2,param_3,param_4,param_5);
        if (iVar2 != 0) {
          if (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x8020) {
            uVar4 = 0;
            FUN_00404c80(0);
            FUN_004fca20();
            FUN_004b2250(uVar4);
            FUN_00404c80();
            FUN_004fca20();
            FUN_00797df8();
          }
          *(undefined4 *)(in_ECX + 0x204) = 2;
          FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
        }
        FUN_00658890();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        if ((DAT_00a0cc6c == 1) && (*(int *)(in_ECX + 0x24c) == 0)) {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_004b2320();
          if ((double)fVar3 <= 0.0) {
            FUN_00404c80();
            FUN_004fca20();
            fVar3 = (float10)FUN_004b2320();
            local_6460 = -(double)fVar3;
          }
          else {
            FUN_00404c80();
            FUN_004fca20();
            fVar3 = (float10)FUN_004b2320();
            local_6460 = (double)fVar3;
          }
          if ((((1e-07 < local_6460) && (*(int *)(in_ECX + 0x204) == 3)) &&
              (*(int *)(in_ECX + 0x280) != 0)) && (*(int *)(in_ECX + 0x25c) != 0)) {
            DAT_00a0cc6c = 0;
            *(undefined4 *)(in_ECX + 0x2c0) = 0;
            *(undefined4 *)(in_ECX + 0x254) = 0;
            FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
            *(undefined4 *)(in_ECX + 0x284) = 2;
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
        if (*(int *)(in_ECX + 0x204) == 3) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 1;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_004b2320();
          if ((double)fVar3 <= 0.0) {
            FUN_00404c80();
            FUN_004fca20();
            fVar3 = (float10)FUN_004b2320();
            local_6468 = -(double)fVar3;
          }
          else {
            FUN_00404c80();
            FUN_004fca20();
            fVar3 = (float10)FUN_004b2320();
            local_6468 = (double)fVar3;
          }
          if (1e-07 < local_6468) {
            FUN_00658890();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            fVar3 = (float10)FUN_006608e0(param_1,param_2,param_3,param_4,param_5);
            dVar5 = (double)fVar3;
            FUN_00404c80(dVar5);
            FUN_004fca20();
            FUN_004b2250(dVar5);
            FUN_00404c80();
            FUN_004fca20();
            FUN_004b1ea0();
            *(undefined4 *)(in_ECX + 0x204) = 3;
            *(undefined4 *)(in_ECX + 0x2c4) = 0;
            *(undefined4 *)(in_ECX + 0x20c) = 0;
            FUN_004fb9f0();
            *(undefined8 *)(*(int *)(in_ECX + 4) + 0x17c0) =
                 *(undefined8 *)(*(int *)(in_ECX + 4) + 0x17c8);
            FUN_00658890();
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
    }
  }
  else {
    uVar1 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiFukusen[13] */
/* 0065d140  FUN_0065d140  226 bytes, 0 callers */

undefined4
FUN_0065d140(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  if (in_ECX[0xac] == 0) {
    if (in_ECX[0x81] == 0) {
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      (**(code **)(**(int **)(iVar2 + 0x1a0) + 400))();
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_004b2320();
      *(double *)(in_ECX + 0xb4) = (double)fVar3;
      in_ECX[0xb1] = 0;
      FUN_004fb9f0();
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)(*in_ECX + 0x2c))(param_1,param_2,param_3,param_4,param_5);
    }
  }
  else {
    uVar1 = FUN_006fda50(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiFukusen[11] */
/* 0065d230  FUN_0065d230  2160 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0065d230(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  double dVar4;
  double local_645c;
  double local_6454;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938feb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0xa2] = 0;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8._0_1_ = 1;
  in_ECX[0xb0] = 1;
  in_ECX[0xb2] = 0;
  if (in_ECX[0xac] == 0) {
    if ((in_ECX[0xa1] == 3) || (in_ECX[0xa1] == 2)) {
      iVar2 = FUN_00451eb0(in_ECX[1],&param_2,1);
      if (iVar2 == 1) {
        uVar1 = (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
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
        uVar1 = 0;
      }
    }
    else {
      in_ECX[0x84] = 0;
      in_ECX[0x88] = 0xedd808;
      in_ECX[0x89] = 0x44ea7796;
      if (in_ECX[0x81] == 0) {
        iVar2 = FUN_00657f10(param_2,param_3,param_4,param_5);
        if (iVar2 != 0) {
          in_ECX[0x81] = 2;
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_004b2320();
          if (1e-07 < (double)fVar3) {
            in_ECX[0x81] = 3;
            in_ECX[0x83] = 1;
          }
          FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
        }
        FUN_00658890();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        if ((DAT_00a0cc6c == 1) && (in_ECX[0x93] == 0)) {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_004b2320();
          if ((double)fVar3 <= 0.0) {
            FUN_00404c80();
            FUN_004fca20();
            fVar3 = (float10)FUN_004b2320();
            local_6454 = -(double)fVar3;
          }
          else {
            FUN_00404c80();
            FUN_004fca20();
            fVar3 = (float10)FUN_004b2320();
            local_6454 = (double)fVar3;
          }
          if ((((1e-07 < local_6454) && (in_ECX[0x81] == 3)) && (in_ECX[0xa0] != 0)) &&
             (in_ECX[0x97] != 0)) {
            DAT_00a0cc6c = 0;
            iVar2 = FUN_00451eb0(in_ECX[1],&param_2,1);
            if (iVar2 == 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 0;
            }
            in_ECX[0xb0] = 0;
            in_ECX[0x95] = 0;
            FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
            in_ECX[0xa1] = 2;
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
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_004b2320();
        if ((double)fVar3 <= 0.0) {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_004b2320();
          local_645c = -(double)fVar3;
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          fVar3 = (float10)FUN_004b2320();
          local_645c = (double)fVar3;
        }
        if (1e-07 < local_645c) {
          if (in_ECX[0x90] < 2) {
            FUN_00658890();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 1;
          }
          else {
            uVar1 = FUN_00658450(param_2,param_3,param_4,param_5);
            iVar2 = FUN_0079d98a();
            if (iVar2 != 0) {
              FUN_00658c90(uVar1);
              FUN_00657a80(uVar1,param_2,param_3,param_4,param_5);
            }
            iVar2 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
            if (iVar2 != 0) {
              FUN_00657a80(uVar1,param_2,param_3,param_4,param_5);
            }
            FUN_00658890();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
        }
        else {
          if (in_ECX[0xb1] != 0) {
            *(undefined4 *)(in_ECX[1] + 0x8f34) = 1;
          }
          iVar2 = FUN_00451eb0(in_ECX[1],&param_2,1);
          if (iVar2 == 1) {
            fVar3 = (float10)FUN_006608e0(0x231d,param_2,param_3,param_4,param_5);
            dVar4 = (double)fVar3;
            FUN_00404c80(dVar4);
            FUN_004fca20();
            FUN_004b2250(dVar4);
            FUN_00404c80();
            FUN_004fca20();
            FUN_004b1ea0();
            in_ECX[0x81] = 3;
          }
          else if (in_ECX[0xb1] != 0) {
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            (**(code **)(**(int **)(iVar2 + 0x1a0) + 400))();
            in_ECX[0x81] = 3;
          }
          in_ECX[0xb1] = 0;
          FUN_00658890();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
      }
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




/* vtable slots: CZukeiFukusen[8] */
/* 0065daf0  FUN_0065daf0  1245 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065daf0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined1 local_6424 [20];
  double local_6410;
  double local_6408;
  undefined4 local_6400;
  int local_63fc;
  double local_63f8;
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939046;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x204) != 0) {
    local_63e8 = in_ECX;
    FUN_00404c80(local_14);
    FUN_004fca20();
    fVar2 = (float10)FUN_004b2320();
    local_63f8 = (double)fVar2;
    local_6408 = local_63f8;
    if (local_63f8 <= 0.0) {
      local_6408 = -local_63f8;
    }
    if (1e-07 < local_6408) {
      FUN_004fb9f0();
      if (*(int *)(local_63e8 + 0x204) != 3) {
        if ((*(int *)(local_63e8 + 0x25c) == 0) || (*(int *)(local_63e8 + 0x21c) != 1)) {
          *(undefined4 *)(local_63e8 + 0x280) = 0;
        }
        else {
          *(undefined4 *)(local_63e8 + 0x280) = 1;
          FUN_00404c80();
          FUN_004fca20();
          FUN_007979e8();
        }
      }
      *(undefined4 *)(local_63e8 + 0x208) = 3;
      *(undefined4 *)(local_63e8 + 0x204) = 3;
    }
    if (*(int *)(local_63e8 + 0x204) == 3) {
      local_63ec = 0;
      local_6400 = FUN_0040c0e0();
      local_63fc = FUN_00572b10();
      if ((local_63fc != 0) && (local_63ec = FUN_00572b30(&local_63fc,0), local_63ec != 0)) {
        FUN_00446aa0();
        local_8 = 0;
        FUN_00464040();
        local_8._0_1_ = 1;
        FUN_0079dea2();
        local_8._0_1_ = 2;
        iVar1 = *(int *)(local_63e8 + 4);
        local_63ec = FUN_00658450(*(undefined4 *)(iVar1 + 0x8f78),*(undefined4 *)(iVar1 + 0x8f7c),
                                  *(undefined4 *)(iVar1 + 0x8f80),*(undefined4 *)(iVar1 + 0x8f84));
        if (local_63ec == 0) {
          local_8._0_1_ = 1;
          FUN_0079dfff();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_004640a0();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          iVar1 = *(int *)(local_63e8 + 4);
          local_63f0 = FUN_0045f5f0(*(undefined4 *)(local_63e8 + 4),local_63ec,
                                    *(undefined4 *)(iVar1 + 0x8f78),*(undefined4 *)(iVar1 + 0x8f7c),
                                    *(undefined4 *)(iVar1 + 0x8f80),*(undefined4 *)(iVar1 + 0x8f84))
          ;
          iVar1 = FUN_004423b0();
          if (iVar1 != 0) {
            local_63f0 = -local_63f0;
          }
          if (local_63f0 == *(int *)(local_63e8 + 0x210)) {
            if (local_63f8 <= 0.0) {
              local_6410 = -local_63f8;
            }
            else {
              local_6410 = local_63f8;
            }
            if ((((1e-07 < local_6410) && (*(byte *)(local_63e8 + 0x214) == DAT_00a0b418)) &&
                (*(byte *)(local_63e8 + 0x215) == DAT_00a0b428)) &&
               (*(double *)(local_63e8 + 0x220) == local_63f8)) {
              local_8._0_1_ = 1;
              FUN_0079dfff();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_004640a0();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return;
            }
          }
          *(int *)(local_63e8 + 0x210) = local_63f0;
          *(int *)(local_63e8 + 0x248) = local_63f0;
          *(undefined1 *)(local_63e8 + 0x214) = (undefined1)DAT_00a0b418;
          *(undefined1 *)(local_63e8 + 0x215) = (undefined1)DAT_00a0b428;
          *(double *)(local_63e8 + 0x220) = local_63f8;
          *(double *)(local_63e8 + 0x228) = local_63f8;
          *(undefined8 *)(local_63e8 + 0x230) = *(undefined8 *)(local_63e8 + 0x228);
          FUN_0044dd90(local_6424,*(undefined4 *)(local_63e8 + 4));
          FUN_0065a340(local_63f0,local_63f8);
          local_8._0_1_ = 1;
          FUN_0079dfff();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_004640a0();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[4] */
/* 0065dfd0  FUN_0065dfd0  600 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065dfd0(void)

{
  undefined1 local_641c [20];
  undefined4 local_6408;
  int local_6404;
  int local_6400;
  undefined4 local_63fc;
  int local_63f8;
  int local_63f4;
  int local_63f0;
  int *local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009236ab;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044de00(local_641c,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd90(local_641c,*(undefined4 *)(local_63e8 + 4));
  local_63f0 = *(int *)(local_63e8 + 4);
  if (local_63f0 == 0) {
    local_63f4 = 0;
  }
  else {
    local_63f4 = local_63f0 + 0x88;
  }
  FUN_00454890(local_63f4);
  FUN_00454830(*(undefined4 *)(local_63e8 + 4));
  local_6404 = 0;
  local_63fc = FUN_0040c0e0();
  local_63f8 = FUN_00572b10();
  do {
    if ((local_63f8 == 0) || (local_6400 = FUN_00572b30(&local_63f8,0), local_6400 == 0))
    goto LAB_0065e144;
  } while (local_6400 != *(int *)(local_63e8 + 600));
  local_6404 = 1;
LAB_0065e144:
  if (local_6404 != 0) {
    FUN_0044c830(local_641c,*(undefined4 *)(local_63e8 + 4));
  }
  if (*(int *)(local_63e8 + 600) != 0) {
    local_63ec = *(int **)(local_63e8 + 600);
    if (local_63ec == (int *)0x0) {
      local_6408 = 0;
    }
    else {
      local_6408 = (**(code **)(*local_63ec + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 600) = 0;
  }
  *(undefined4 *)(local_63e8 + 0x25c) = 0;
  DAT_00a0cc74 = 0;
  DAT_00a0cc6c = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiFukusen[3] */
/* 0065e230  FUN_0065e230  1779 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0065e230(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  undefined8 uVar4;
  undefined1 local_6428 [20];
  double local_6414;
  uint local_640c;
  undefined4 local_6408;
  int local_6404;
  int local_6400;
  int local_63fc;
  int local_63f8;
  int local_63f4;
  undefined4 local_63f0;
  int local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939096;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x2b0) == 0) {
    *(undefined8 *)(*(int *)(in_ECX + 4) + 0x17c0) = *(undefined8 *)(*(int *)(in_ECX + 4) + 0x17c8);
    *(undefined4 *)(in_ECX + 0x288) = 0;
    if (*(int *)(in_ECX + 0x284) != 0) {
      *(undefined4 *)(in_ECX + 0x288) = 1;
    }
    local_63e8 = in_ECX;
    local_63f0 = FUN_0040c0e0(local_14);
    FUN_00446aa0();
    local_8 = 0;
    FUN_00464040();
    local_8._0_1_ = 1;
    FUN_0079dea2();
    local_8 = CONCAT31(local_8._1_3_,2);
    local_63f8 = 0;
    if (*(int *)(local_63e8 + 0x1f8) != 0) {
      local_63ec = FUN_00572b10();
LAB_0065e35d:
      local_6404 = local_63ec;
      local_63f4 = FUN_00572b30(&local_63ec,0);
      if (local_63f4 != 0) {
        if (local_63f4 != *(int *)(local_63e8 + 600)) goto code_r0x0065e398;
        goto LAB_0065e3e3;
      }
      if (local_63f8 != 0) {
        FUN_005168b0(0x157a,*(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f28),0,0);
      }
      iVar1 = FUN_00573cb0();
      if (iVar1 == 0) {
        FUN_00478480(0,*(undefined4 *)(local_63e8 + 4),local_63e4,local_6428,0);
        FUN_00574f10();
      }
    }
    local_6408 = 1;
    if ((*(int *)(local_63e8 + 0x1f8) != 0) && (*(int *)(local_63e8 + 0x1fc) != 0)) {
      local_6408 = 0;
    }
    uVar2 = FUN_00476900(local_63e4,local_6428,*(undefined4 *)(local_63e8 + 4),local_6408);
    *(undefined4 *)(local_63e8 + 0x250) = uVar2;
    *(undefined4 *)(local_63e8 + 0x210) = 0;
    *(undefined8 *)(local_63e8 + 0x220) = 0x44ea779600edd808;
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    if (*(int *)(local_63e8 + 0x250) != 0) {
      FUN_00455870(*(undefined4 *)(local_63e8 + 0x250),*(undefined4 *)(local_63e8 + 0x260),
                   *(undefined4 *)(local_63e8 + 0x264),*(undefined4 *)(local_63e8 + 0x268),
                   *(undefined4 *)(local_63e8 + 0x26c));
    }
    if ((((*(int *)(local_63e8 + 0x2c0) == 1) && (*(int *)(local_63e8 + 0x254) != 0)) &&
        (*(int *)(local_63e8 + 0x250) != 0)) &&
       ((*(int *)(local_63e8 + 0x218) == 1 && (*(int *)(local_63e8 + 0x24c) == 0)))) {
      local_63ec = 0;
      iVar1 = FUN_0046abe0(*(undefined4 *)(local_63e8 + 4),*(undefined4 *)(local_63e8 + 0x254),
                           *(undefined4 *)(local_63e8 + 0x250));
      if ((iVar1 != 0) && (local_63ec = FUN_00572180(), local_63ec != 0)) {
        uVar2 = FUN_00572000();
        *(undefined4 *)(local_63e8 + 0x250) = uVar2;
      }
      if (local_63ec == 0) {
        *(undefined4 *)(local_63e8 + 0x250) = 0;
      }
      if (*(int *)(local_63e8 + 0x250) != 0) {
        FUN_00455870(*(undefined4 *)(local_63e8 + 0x250),*(undefined4 *)(local_63e8 + 0x260),
                     *(undefined4 *)(local_63e8 + 0x264),*(undefined4 *)(local_63e8 + 0x268),
                     *(undefined4 *)(local_63e8 + 0x26c));
      }
    }
    *(undefined4 *)(local_63e8 + 0x254) = *(undefined4 *)(local_63e8 + 0x250);
    *(undefined4 *)(local_63e8 + 0x204) = 0;
    *(undefined4 *)(local_63e8 + 0x20c) = 0;
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_004b2320();
    *(double *)(local_63e8 + 0x2d0) = (double)fVar3;
    if (*(int *)(local_63e8 + 0x1f8) == 0) {
      if (*(double *)(local_63e8 + 0x2d0) <= 0.0) {
        local_6414 = -*(double *)(local_63e8 + 0x2d0);
      }
      else {
        local_6414 = *(double *)(local_63e8 + 0x2d0);
      }
      local_640c = (uint)(1e-07 <= local_6414);
      FUN_00404c80();
      FUN_004fca20();
      FUN_007979e8();
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      FUN_007979e8();
      if (local_63f8 == 0) {
        FUN_005168b0(0x1779,*(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f28),0,0);
      }
    }
    uVar4 = *(undefined8 *)(local_63e8 + 0x2d0);
    FUN_00404c80(uVar4);
    FUN_004fca20();
    FUN_004b2250(uVar4);
    FUN_00404c80();
    FUN_004fca20();
    FUN_004b1ea0();
    *(undefined4 *)(local_63e8 + 0x284) = 0;
    if ((*(int *)(local_63e8 + 0x2c8) == 0) && (*(int *)(local_63e8 + 0x218) != 1)) {
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8578) = 1;
    }
    FUN_00658890();
    FUN_00404c80();
    FUN_004fca20();
    FUN_004b2220();
    local_8._0_1_ = 1;
    FUN_0079dfff();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004640a0();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_006fe2f0();
  }
  ExceptionList = local_10;
  return;
code_r0x0065e398:
  local_63fc = *(int *)(local_63e8 + 4);
  if (local_63fc == 0) {
    local_6400 = 0;
  }
  else {
    local_6400 = local_63fc + 0x88;
  }
  iVar1 = FUN_0042dcb0();
  if (iVar1 != 0) {
LAB_0065e3e3:
    FUN_00454ee0(local_6428,0,*(undefined4 *)(local_63e8 + 4),local_63f4);
    FUN_00574f40();
    local_63f8 = 1;
  }
  goto LAB_0065e35d;
}



