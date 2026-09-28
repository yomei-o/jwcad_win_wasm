/* CZukeiGaibuHenkei -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiGaibuHenkei[1] */
/* 006619d0  FUN_006619d0  68 bytes, 0 callers */

undefined4 FUN_006619d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006618a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x3280);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiGaibuHenkei[6] */
/* 006625b0  FUN_006625b0  2354 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00662a70) */

void FUN_006625b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  float10 fVar2;
  double local_671c;
  double local_6714;
  double local_670c;
  double local_6704;
  double local_66fc;
  undefined1 local_66f4 [24];
  undefined4 local_66dc;
  undefined4 local_66d8;
  undefined4 local_66d4;
  int local_66d0;
  undefined4 local_66cc;
  double local_66c8;
  int local_66c0;
  undefined1 local_2ec [8];
  undefined4 local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined2 local_284 [104];
  undefined2 local_1b4 [104];
  undefined2 local_e4 [104];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009393d6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_66c0 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_66cc = FUN_0040c0e0();
  if (*(int *)(local_66c0 + 0x1fc) != *(int *)(local_66c0 + 0x200)) {
    *(undefined4 *)(local_66c0 + 0x200) = *(undefined4 *)(local_66c0 + 0x1fc);
    FUN_00661b20();
  }
  if (*(int *)(local_66c0 + 0x1fc) == 1) {
    FUN_006f7cc0(param_1);
    FUN_00574d00();
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (*(int *)(*(int *)(local_66c0 + 4) + 0x17f0) != 0) {
      *(undefined4 *)(*(int *)(local_66c0 + 4) + 0x17f0) = 0;
      local_66d8 = FUN_00572b90();
      while (local_66d0 = FUN_00572bb0(), local_66d0 != 0) {
        FUN_0044a120(local_66f4,*(undefined4 *)(local_66c0 + 4),local_66d0,1);
      }
    }
    if ((*(int *)(local_66c0 + 0x1fc) == 0x14) || (*(int *)(local_66c0 + 0x1fc) == 0x28)) {
      FUN_004efbb0(0x151b,0,0);
    }
    else if ((((*(int *)(local_66c0 + 0x1fc) == 3) || (*(int *)(local_66c0 + 0x1fc) == 4)) ||
             (*(int *)(local_66c0 + 0x1fc) == 7)) || (*(int *)(local_66c0 + 0x1fc) == 8)) {
      FUN_004efbb0(0x154c,0,0);
    }
    else if (*(int *)(local_66c0 + 0x1fc) == 2) {
      FUN_004efbb0(0x14fa,0,0);
    }
    else {
      FUN_004efbb0(0x154d,0,0);
    }
    *(undefined4 *)(*(int *)(local_66c0 + 4) + 0x8560) = 0;
    FUN_0044dd90();
    if (((*(int *)(local_66c0 + 0x63c + *(int *)(local_66c0 + 0x618) * 4) == 2) ||
        (*(int *)(local_66c0 + 0x63c + *(int *)(local_66c0 + 0x618) * 4) == 9)) ||
       ((*(int *)(local_66c0 + 0x63c + *(int *)(local_66c0 + 0x618) * 4) == 10 ||
        (*(int *)(local_66c0 + 0x63c + *(int *)(local_66c0 + 0x618) * 4) == 0xb)))) {
      if (*(int *)(local_66c0 + 0x618) < 2) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (*(int *)(local_66c0 + 0x1fc) == 0x28) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        if (0 < *(int *)(local_66c0 + 0x22b0 + *(int *)(local_66c0 + 0x618) * 4)) {
          FUN_0041f760();
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_004552a0(local_2ec);
          puVar1 = (undefined4 *)(local_66c0 + 0x25e0 + (*(int *)(local_66c0 + 0x618) + -1) * 0x10);
          FUN_0040da70(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
          if (*(int *)(local_66c0 + 0x22b0 + *(int *)(local_66c0 + 0x618) * 4) == 2) {
            FUN_00665740();
          }
          FUN_0040da20(*param_1,param_1[1],param_1[2],param_1[3]);
          FUN_00450b70(local_66f4,*(undefined4 *)(local_66c0 + 4),local_2ec);
          local_66d4 = 0;
          local_1b4[0] = 0;
          local_284[0] = 0;
          local_e4[0] = 0;
          fVar2 = (float10)FUN_0043ad70(local_2e4,local_2e0,local_2dc,local_2d8,local_2d4,local_2d0,
                                        local_2cc,local_2c8);
          local_66c8 = (double)fVar2 *
                       *(double *)
                        (*(int *)(local_66c0 + 4) + 0x2578 +
                        *(int *)(*(int *)(local_66c0 + 4) + 0x256c) * 8);
          if (DAT_00a0d62c != 0) {
            local_66c8 = local_66c8 / DAT_00a0d630;
          }
          FUN_0045a220(local_1b4,local_66c8,3,1,1,1);
          fVar2 = (float10)FUN_00667f60(local_2e4,local_2e0,local_2dc,local_2d8,local_2d4,local_2d0,
                                        local_2cc,local_2c8);
          local_66c8 = (double)fVar2 - *(double *)(*(int *)(local_66c0 + 4) + 0x17c0);
          if (180.0 < local_66c8) {
            local_66c8 = local_66c8 - 360.0;
          }
          if (local_66c8 <= -180.0) {
            local_66c8 = local_66c8 + 360.0;
          }
          if (local_66c8 <= 0.0) {
            local_66fc = -local_66c8;
          }
          else {
            local_66fc = local_66c8;
          }
          if (local_66fc - 180.0 <= 0.0) {
            if (local_66c8 <= 0.0) {
              local_670c = -local_66c8;
            }
            else {
              local_670c = local_66c8;
            }
            local_6714 = -(local_670c - 180.0);
          }
          else {
            if (local_66c8 <= 0.0) {
              local_6704 = -local_66c8;
            }
            else {
              local_6704 = local_66c8;
            }
            local_6714 = local_6704 - 180.0;
          }
          if (local_6714 < 1e-07) {
            local_66c8 = 180.0;
          }
          if (local_66c8 <= 0.0) {
            local_671c = -local_66c8;
          }
          else {
            local_671c = local_66c8;
          }
          if (local_671c < 1e-07) {
            local_66c8 = 0.0;
          }
          local_66dc = FUN_005977f0(0x1834);
          FUN_00404920();
          FUN_0058d540();
          FUN_00404770();
          FUN_0058d540(local_284,L"   %s",local_1b4);
          FUN_00661050();
          if (DAT_00a0d62c != 0) {
            FUN_00404920();
            FUN_00661050();
          }
          FUN_004efbb0(0x14fa,local_e4,0);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_0041fd70();
        }
        local_8 = local_8 & 0xffffff00;
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
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiGaibuHenkei[16] */
/* 00662ef0  FUN_00662ef0  2254 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00662ef0(void)

{
  double *pdVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_6490;
  undefined4 local_648c;
  undefined4 local_6488;
  int local_6484;
  undefined1 local_6480 [20];
  int local_646c;
  undefined4 local_6468;
  int local_6464;
  int local_6460;
  undefined1 local_8c [104];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939426;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6460 + 4));
  local_8._0_1_ = 1;
  if ((*(int *)(local_6460 + 0x1fc) == 1) && (iVar3 = FUN_006f85c0(), iVar3 != 0)) {
    local_6488 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    DAT_00a0d618 = 0;
    if ((*(int *)(local_6460 + 0x1fc) == 0x28) || (*(int *)(local_6460 + 0x1fc) == 0)) {
      local_648c = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6488 = local_648c;
    }
    else {
      uVar4 = 0;
      FUN_00404c80(0);
      iVar3 = FUN_004fca20();
      FUN_0044fbe0(*(int *)(iVar3 + 0x1a0) + 0x138,uVar4);
      do {
        if (*(int *)(local_6460 + 0x618) < 2) {
          if ((*(int *)(local_6460 + 0x618) == 1) && (*(int *)(local_6460 + 0x63c) == 0x14)) {
            FUN_0044de00(local_6480,*(undefined4 *)(local_6460 + 4));
            FUN_0044dd90(local_6480,*(undefined4 *)(local_6460 + 4));
            FUN_0044dd20(local_6480,*(undefined4 *)(local_6460 + 4));
            *(undefined4 *)(local_6460 + 0x618) = 0;
            *(undefined4 *)(local_6460 + 0x200) = 0xffffffff;
            FUN_00661a20();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 1;
          }
          if (*(int *)(local_6460 + 0x618) < 2) {
            FUN_0044de00(local_6480,*(undefined4 *)(local_6460 + 4));
            FUN_0044dd90(local_6480,*(undefined4 *)(local_6460 + 4));
            FUN_0044dd20(local_6480,*(undefined4 *)(local_6460 + 4));
            *(undefined4 *)(local_6460 + 0x618) = 0;
            *(undefined4 *)(local_6460 + 0x1fc) = 0x28;
            *(undefined4 *)(local_6460 + 0x200) = 0xffffffff;
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 1;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        FUN_004b5a50(local_6480);
        *(int *)(local_6460 + 0x618) = *(int *)(local_6460 + 0x618) + -1;
        FUN_0044de00(local_6480,*(undefined4 *)(local_6460 + 4));
        FUN_0044dd90(local_6480,*(undefined4 *)(local_6460 + 4));
        FUN_0044dd20(local_6480,*(undefined4 *)(local_6460 + 4));
        local_6468 = FUN_0040c0e0();
        local_6490 = FUN_00572b90();
        while (local_6484 = FUN_00572bb0(&local_6490,0), local_6484 != 0) {
          FUN_0044a120(local_6480,*(undefined4 *)(local_6460 + 4),local_6484,0);
        }
        FUN_0044c880(*(undefined4 *)(local_6460 + 4),local_6480);
        if (((((*(int *)(local_6460 + 0x63c + *(int *)(local_6460 + 0x618) * 4) == 2) ||
              (*(int *)(local_6460 + 0x63c + *(int *)(local_6460 + 0x618) * 4) == 9)) ||
             (*(int *)(local_6460 + 0x63c + *(int *)(local_6460 + 0x618) * 4) == 10)) ||
            (*(int *)(local_6460 + 0x63c + *(int *)(local_6460 + 0x618) * 4) == 0xb)) &&
           (0 < *(int *)(local_6460 + 0x1f84))) {
          *(undefined4 *)(local_6460 + 0x618) = *(undefined4 *)(local_6460 + 0x1f84);
          *(undefined4 *)(local_6460 + 0x1f84) = 0;
        }
        FUN_00574d00();
        for (local_6464 = 1; local_6464 < *(int *)(local_6460 + 0x618); local_6464 = local_6464 + 1)
        {
          if (((*(int *)(local_6460 + 0x63c + local_6464 * 4) == 2) ||
              (*(int *)(local_6460 + 0x63c + local_6464 * 4) == 9)) ||
             ((*(int *)(local_6460 + 0x63c + local_6464 * 4) == 10 ||
              (*(int *)(local_6460 + 0x63c + local_6464 * 4) == 0xb)))) {
            pdVar1 = (double *)(local_6460 + 0x25e0 + local_6464 * 0x10);
            local_24 = *(undefined4 *)pdVar1;
            uStack_20 = *(undefined4 *)((int)pdVar1 + 4);
            local_1c = *(undefined4 *)(pdVar1 + 1);
            local_18 = *(undefined4 *)((int)pdVar1 + 0xc);
            if (9e+30 <= *pdVar1) break;
            if ((1 < local_6464) && (0 < *(int *)(local_6460 + 0x22b0 + local_6464 * 4))) {
              FUN_0041f760();
              local_8._0_1_ = 2;
              FUN_004552a0(local_8c);
              puVar2 = (undefined4 *)(local_6460 + 0x25e0 + (local_6464 + -1) * 0x10);
              FUN_0040da70(*puVar2,puVar2[1],puVar2[2],puVar2[3]);
              FUN_0040da20(local_24,uStack_20,local_1c,local_18);
              FUN_00450af0(local_6480,*(undefined4 *)(local_6460 + 4),local_8c);
              local_8._0_1_ = 1;
              FUN_0041fd70();
            }
            if (*(int *)(local_6460 + 0x1f88 + local_6464 * 4) == 0) {
              FUN_004508b0(0xc,local_6480,*(undefined4 *)(local_6460 + 4),local_24,uStack_20,
                           local_1c,local_18,0);
            }
            else {
              FUN_004508b0(0x10,local_6480,*(undefined4 *)(local_6460 + 4),local_24,uStack_20,
                           local_1c,local_18,0);
              if ((*(int *)(local_6460 + 0x63c + local_6464 * 4) != 2) &&
                 (local_646c = *(int *)(local_6460 + 0xfb4 + local_6464 * 4), local_646c != 0)) {
                FUN_00570920(local_646c);
                *(undefined4 *)(local_646c + 0x48) =
                     *(undefined4 *)(local_6460 + 0x1f88 + local_6464 * 4);
                FUN_0044a120(local_6480,*(undefined4 *)(local_6460 + 4),local_646c,1);
              }
            }
          }
        }
        *(undefined4 *)(local_6460 + 0x1fc) =
             *(undefined4 *)(local_6460 + 0x63c + *(int *)(local_6460 + 0x618) * 4);
        *(undefined4 *)(local_6460 + 0x200) = 0xffffffff;
        if (*(int *)(local_6460 + 0x1fc) == 1) {
          FUN_006637c0();
        }
      } while (((*(int *)(local_6460 + 0x1fc) == 5) || (*(int *)(local_6460 + 0x1fc) == 6)) &&
              (iVar3 = FUN_00667bf0(*(undefined4 *)(local_6460 + 0x618)), iVar3 == 0));
      FUN_00404c80();
      FUN_0056d7d0();
      FUN_004b7110();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6488 = 1;
    }
  }
  ExceptionList = local_10;
  return local_6488;
}




/* vtable slots: CZukeiGaibuHenkei[0] */
/* 006641b0  FUN_006641b0  16 bytes, 0 callers */

undefined ** FUN_006641b0(void)

{
  return &PTR_s_CZukeiGaibuHenkei_00978450;
}




/* vtable slots: CZukeiGaibuHenkei[46] */
/* 006642d0  FUN_006642d0  624 bytes, 0 callers */

undefined4
FUN_006642d0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (DAT_00a0c7c0 == 0) {
    if (in_ECX[0x7f] == 1) {
      uVar2 = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      if ((((in_ECX[0x7f] == 2) || (in_ECX[0x7f] == 9)) || (in_ECX[0x7f] == 10)) ||
         (in_ECX[0x7f] == 0xb)) {
        if (((param_2 == 0xc) && (*(int *)(in_ECX[1] + 0x9078) == 0)) &&
           ((in_ECX[0x7e0] != 0 && (in_ECX[in_ECX[0x186] + 0x7e2] != 0)))) {
          if (param_3 == 1) {
            FUN_005168b0(0x1550,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
            return 0;
          }
          if (param_3 != 2) {
            return 0;
          }
          (**(code **)(*in_ECX + 0x6c))();
          return 0;
        }
        if (((param_2 == 1) && (*(int *)(in_ECX[1] + 0x9078) == 0)) &&
           (iVar1 = in_ECX[0x186], in_ECX[iVar1 + 0x8ac] != 0)) {
          if (param_3 == 1) {
            FUN_005168b0(0x1802,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            if (in_ECX[iVar1 + 0x8ac] == 2) {
              in_ECX[iVar1 + 0x8ac] = 1;
            }
            else {
              in_ECX[iVar1 + 0x8ac] = 2;
            }
          }
          return 0;
        }
      }
      if (*(int *)(in_ECX[1] + 0x9078) == 0) {
        uVar2 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      else {
        uVar2 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
  }
  else {
    uVar2 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar2;
}




/* vtable slots: CZukeiGaibuHenkei[47] */
/* 00664540  FUN_00664540  182 bytes, 0 callers */

void FUN_00664540(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int in_ECX;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(in_ECX + 0x1fc) == 1) {
      FUN_006fa580(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}




/* vtable slots: CZukeiGaibuHenkei[34] */
/* 00664600  FUN_00664600  653 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00664600(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *in_ECX;
  double dVar6;
  double dVar7;
  undefined4 uVar8;
  undefined1 local_6428 [20];
  undefined4 local_6414;
  int local_6410;
  undefined4 local_640c;
  int *local_6408;
  undefined1 local_34 [16];
  undefined8 local_24;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093954b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00a0d618 = 0;
  in_ECX[0x7f] = 0;
  local_6408 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(local_6408[1]);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = local_6408[1];
  FUN_00454cb0(0,local_6408[1],*(undefined4 *)(iVar1 + 0x8f10),*(undefined4 *)(iVar1 + 0x8f14),
               *(undefined4 *)(iVar1 + 0x8f18),*(undefined4 *)(iVar1 + 0x8f1c));
  FUN_0044de00(local_6428,local_6408[1]);
  if ((local_6408[0x150] != 0) && (local_6408[0x8ac] == 0)) {
    FUN_00408a60();
    dVar6 = -(*(double *)(&DAT_009ffbb8 + *(int *)(local_6408[1] + 0x3020) * 8) / 2.0);
    dVar7 = -(*(double *)(&DAT_009ffc58 + *(int *)(local_6408[1] + 0x3020) * 8) / 2.0);
    local_24._0_4_ =
         SUB84(*(double *)(&DAT_009ffbb8 + *(int *)(local_6408[1] + 0x3020) * 8) / 2.0,0);
    uVar8 = (undefined4)local_24;
    local_24._4_4_ = (undefined4)((ulonglong)dVar6 >> 0x20);
    uVar2 = local_24._4_4_;
    local_1c._0_4_ =
         SUB84(*(double *)(&DAT_009ffc58 + *(int *)(local_6408[1] + 0x3020) * 8) / 2.0,0);
    uVar3 = (undefined4)local_1c;
    local_1c._4_4_ = (undefined4)((ulonglong)dVar7 >> 0x20);
    uVar4 = local_1c._4_4_;
    local_24 = dVar6;
    local_1c = dVar7;
    FUN_00517640(uVar8,uVar2,uVar3,uVar4);
  }
  uVar8 = 0;
  puVar5 = (undefined4 *)FUN_004b75a0(local_34);
  FUN_004508b0(0xc,local_6428,local_6408[1],*puVar5,puVar5[1],puVar5[2],puVar5[3],uVar8);
  local_640c = FUN_0040c0e0();
  local_6414 = FUN_00572b10();
  while( true ) {
    local_6410 = FUN_00572b30(&local_6414,0);
    if (local_6410 == 0) break;
    *(undefined4 *)(local_6410 + 0x48) = 0;
  }
  (**(code **)(*local_6408 + 0x90))();
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiGaibuHenkei[25] */
/* 00664890  FUN_00664890  80 bytes, 0 callers */

void FUN_00664890(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00667af0(1);
  if ((iVar1 == 0) && (*(int *)(in_ECX + 0x1fc) == 0x28)) {
    *(undefined4 *)(in_ECX + 0x204) = 0;
    iVar1 = FUN_00666990(0);
    if (iVar1 != 0) {
      FUN_00404c80();
      FUN_0056d7d0();
    }
  }
  return;
}




/* vtable slots: CZukeiGaibuHenkei[26] */
/* 006648e0  FUN_006648e0  47 bytes, 0 callers */

void FUN_006648e0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00667af0(2);
  if ((iVar1 == 0) && (*(int *)(in_ECX + 0x1fc) == 0x28)) {
    FUN_00661a20();
  }
  return;
}




/* vtable slots: CZukeiGaibuHenkei[27] */
/* 00664910  FUN_00664910  276 bytes, 0 callers */

void FUN_00664910(void)

{
  int iVar1;
  int *in_ECX;
  int local_c;
  
  if (((((in_ECX[0x7f] == 2) || (in_ECX[0x7f] == 9)) || (in_ECX[0x7f] == 10)) ||
      (in_ECX[0x7f] == 0xb)) && ((in_ECX[0x7e0] != 0 && (in_ECX[in_ECX[0x186] + 0x7e2] != 0)))) {
    in_ECX[0x7e1] = in_ECX[0x186];
    for (local_c = in_ECX[in_ECX[0x186] + 0x7e2]; local_c <= in_ECX[0x7e0]; local_c = local_c + 1) {
      iVar1 = in_ECX[0x186];
      (in_ECX + iVar1 * 4 + 0x978)[0] = 0x41d14c8;
      (in_ECX + iVar1 * 4 + 0x978)[1] = 0x465f3d28;
      in_ECX[0x186] = in_ECX[0x186] + 1;
    }
    in_ECX[0x186] = in_ECX[0x186] + -1;
    (**(code **)(*in_ECX + 0x90))();
  }
  else {
    FUN_00667af0(3);
  }
  return;
}




/* vtable slots: CZukeiGaibuHenkei[28] */
/* 00664a30  FUN_00664a30  21 bytes, 0 callers */

void FUN_00664a30(void)

{
  FUN_00667af0(4);
  return;
}




/* vtable slots: CZukeiGaibuHenkei[29] */
/* 00664a50  FUN_00664a50  21 bytes, 0 callers */

void FUN_00664a50(void)

{
  FUN_00667af0(5);
  return;
}




/* vtable slots: CZukeiGaibuHenkei[30] */
/* 00664a70  FUN_00664a70  43 bytes, 0 callers */

void FUN_00664a70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 1) {
    FUN_006fbbb0();
  }
  else {
    FUN_00667af0(6);
  }
  return;
}




/* vtable slots: CZukeiGaibuHenkei[31] */
/* 00664aa0  FUN_00664aa0  21 bytes, 0 callers */

void FUN_00664aa0(void)

{
  FUN_00667af0(7);
  return;
}




/* vtable slots: CZukeiGaibuHenkei[32] */
/* 00664ac0  FUN_00664ac0  21 bytes, 0 callers */

void FUN_00664ac0(void)

{
  FUN_00667af0(8);
  return;
}




/* vtable slots: CZukeiGaibuHenkei[33] */
/* 00664ae0  FUN_00664ae0  21 bytes, 0 callers */

void FUN_00664ae0(void)

{
  FUN_00667af0(9);
  return;
}




/* vtable slots: CZukeiGaibuHenkei[36] */
/* 00664b00  FUN_00664b00  3134 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00664b00(void)

{
  double *pdVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_64a0;
  undefined4 local_649c;
  int local_6498;
  int local_6494;
  undefined1 local_6490 [20];
  undefined4 local_647c;
  int local_6478;
  int local_6474;
  int local_6470;
  int local_646c;
  undefined4 local_6468;
  int local_6464;
  int *local_6460;
  undefined1 local_8c [104];
  int local_24;
  int iStack_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009395a6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(local_6460[1]);
  local_8._0_1_ = 1;
  if (local_6460[0x7f] == 1) {
    local_6494 = local_6460[1];
    if (local_6494 == 0) {
      local_6498 = 0;
    }
    else {
      local_6498 = local_6494 + 0x88;
    }
    iVar4 = FUN_0044fcd0(local_6498);
    if (iVar4 == 0) {
      if (DAT_00a0d618 == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        (**(code **)(*local_6460 + 0x88))();
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
  else if (local_6460[0x7f] == 0x14) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if ((local_6460[0x7f] == 7) || (local_6460[0x7f] == 8)) {
      if (*(int *)(local_6460[1] + 0x17d8) == 0x8091) {
        FUN_00404c80(1);
        FUN_004fca20();
        FUN_007955d2();
        FUN_00404c80();
        iVar4 = FUN_004fca20();
        FUN_00404860(*(int *)(iVar4 + 0x1a0) + 0x1b8);
      }
      uVar5 = 0;
      FUN_00404c80(0);
      iVar4 = FUN_004fca20();
      FUN_0044fbe0(*(int *)(iVar4 + 0x1a0) + 0x138,uVar5);
    }
    if ((((local_6460[0x7f] == 3) || (local_6460[0x7f] == 4)) || (local_6460[0x7f] == 5)) ||
       (local_6460[0x7f] == 6)) {
      FUN_00404900(&DAT_00956338);
      if ((local_6460[0x7f] == 3) || (local_6460[0x7f] == 4)) {
        if (*(int *)(local_6460[1] + 0x17d8) == 0x8091) {
          FUN_00404c80(1);
          FUN_004fca20();
          FUN_007955d2();
          FUN_00404c80();
          iVar4 = FUN_004fca20();
          cVar3 = FUN_004640c0(&DAT_00956338,*(int *)(iVar4 + 0x1a0) + 0x1b8);
          if (cVar3 != '\0') {
            FUN_00404c80();
            iVar4 = FUN_004fca20();
            FUN_00404860(*(int *)(iVar4 + 0x1a0) + 0x1b8);
            if (local_6460[local_6460[0x186] + 0x259] != 0) {
              FUN_00464110(&DAT_0095b4d4);
            }
          }
        }
      }
      else if (-1 < local_6460[0x16c]) {
        FUN_004059f0(local_6460 + local_6460[0x186] + 0x715,&DAT_0095b714,local_6460[0x16c]);
      }
      uVar5 = 0;
      FUN_00404c80(0);
      iVar4 = FUN_004fca20();
      FUN_0044fbe0(*(int *)(iVar4 + 0x1a0) + 0x138,uVar5);
      FUN_00404900(&DAT_00956338);
      for (local_646c = 1; local_646c <= local_6460[0x186]; local_646c = local_646c + 1) {
        if ((((local_6460[local_646c + 399] == 3) || (local_6460[local_646c + 399] == 4)) ||
            ((local_6460[local_646c + 399] == 5 || (local_6460[local_646c + 399] == 6)))) &&
           (cVar3 = FUN_00447350(&DAT_00956338,local_6460 + local_646c + 0x715), cVar3 == '\0')) {
          FUN_00404950(local_6460 + local_646c + 0x64b);
          FUN_00404950(local_6460 + local_646c + 0x715);
          FUN_00464110(&DAT_0095b620);
        }
      }
    }
    local_6468 = FUN_0040c0e0();
    local_647c = FUN_00572b10();
    if ((((local_6460[0x7f] == 2) || (local_6460[0x7f] == 9)) || (local_6460[0x7f] == 10)) ||
       (local_6460[0x7f] == 0xb)) {
      iVar4 = local_6460[1];
      FUN_00454cb0(0,local_6460[1],*(undefined4 *)(iVar4 + 0x8f10),*(undefined4 *)(iVar4 + 0x8f14),
                   *(undefined4 *)(iVar4 + 0x8f18),*(undefined4 *)(iVar4 + 0x8f1c));
      FUN_0044de00(local_6490,local_6460[1]);
      FUN_0044dd90(local_6490,local_6460[1]);
      FUN_0044dd20(local_6490,local_6460[1]);
      while (local_6474 = FUN_00572b30(&local_647c,0), local_6474 != 0) {
        *(undefined4 *)(local_6474 + 0x48) = 0;
      }
      FUN_00574d00();
      FUN_004b5a50(local_6490);
      for (local_6464 = 1; local_6464 <= local_6460[0x186]; local_6464 = local_6464 + 1) {
        if (((local_6460[local_6464 + 399] == 2) || (local_6460[local_6464 + 399] == 9)) ||
           ((local_6460[local_6464 + 399] == 10 || (local_6460[local_6464 + 399] == 0xb)))) {
          pdVar1 = (double *)(local_6460 + local_6464 * 4 + 0x978);
          local_24 = *(int *)pdVar1;
          iStack_20 = *(int *)((int)pdVar1 + 4);
          local_1c = *(int *)(pdVar1 + 1);
          local_18 = *(int *)((int)pdVar1 + 0xc);
          if (9e+30 <= *pdVar1) break;
          if ((1 < local_6464) && (0 < local_6460[local_6464 + 0x8ac])) {
            FUN_0041f760();
            local_8._0_1_ = 2;
            FUN_004552a0(local_8c);
            piVar2 = local_6460 + (local_6464 + -1) * 4 + 0x978;
            FUN_0040da70(*piVar2,piVar2[1],piVar2[2],piVar2[3]);
            FUN_0040da20(local_24,iStack_20,local_1c,local_18);
            FUN_00450af0(local_6490,local_6460[1],local_8c);
            local_8._0_1_ = 1;
            FUN_0041fd70();
          }
          if (local_6460[local_6464 + 0x7e2] == 0) {
            FUN_004508b0(0xc,local_6490,local_6460[1],local_24,iStack_20,local_1c,local_18,0);
          }
          else {
            FUN_004508b0(0x10,local_6490,local_6460[1],local_24,iStack_20,local_1c,local_18,0);
            if ((local_6460[local_6464 + 399] != 2) &&
               (local_6478 = local_6460[local_6464 + 0x3ed], local_6478 != 0)) {
              FUN_00570920(local_6478);
              *(int *)(local_6478 + 0x48) = local_6460[local_6464 + 0x7e2];
              FUN_0044a120(local_6490,local_6460[1],local_6478,1);
            }
          }
        }
      }
      FUN_004b7110();
    }
    if ((local_6460[0x186] < local_6460[0x185]) && (local_6460[local_6460[0x186] + 400] == 0x13)) {
      local_6460[0x186] = local_6460[0x186] + 1;
    }
    if (local_6460[0x186] == local_6460[0x185]) {
      local_647c = FUN_00572b10();
LAB_006654d5:
      local_6474 = FUN_00572b30(&local_647c,0);
      if (local_6474 != 0) {
        local_649c = FUN_00572b90();
        do {
          local_6470 = FUN_00572bb0(&local_649c,0);
          if (local_6470 == 0) goto LAB_006654d5;
        } while (local_6470 != local_6474);
        *(int *)(local_6470 + 0x48) = -*(int *)(local_6470 + 0x48);
        goto LAB_006654d5;
      }
      local_64a0 = FUN_00572b90();
      while (local_6470 = FUN_00572bb0(&local_64a0,0), local_6470 != 0) {
        if (0 < *(int *)(local_6470 + 0x48)) {
          FUN_005708e0(local_6470);
        }
      }
      FUN_00574d00();
      local_6460[0x7f] = 0x28;
      iVar4 = FUN_00669670();
      if (iVar4 == 0) {
        local_6460[0x7f] = 0x28;
        (**(code **)(*local_6460 + 100))();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      do {
        local_6460[0x186] = local_6460[0x186] + 1;
        local_6460[0x80] = -1;
        local_6460[0x7f] = local_6460[local_6460[0x186] + 399];
        if (local_6460[0x7f] == 1) {
          FUN_006637c0();
        }
      } while (((local_6460[0x7f] == 5) || (local_6460[0x7f] == 6)) &&
              (iVar4 = FUN_00667bf0(local_6460[0x186]), iVar4 == 0));
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiGaibuHenkei[9] */
/* 00665a20  FUN_00665a20  1950 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00665a20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  int local_6430;
  int local_642c;
  int *local_6428;
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009395e0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x7f] == 1) {
    uVar2 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  else if ((in_ECX[0x7f] == 0x14) || (in_ECX[0x7f] == 6)) {
    FUN_00667af0(1);
    uVar2 = 0;
  }
  else if (in_ECX[0x7f] == 5) {
    FUN_00667af0(0xffffffff);
    uVar2 = 0;
  }
  else if (in_ECX[0x7f] == 0x28) {
    (**(code **)(*in_ECX + 100))();
    uVar2 = 0;
  }
  else if ((((in_ECX[0x7f] == 7) || (in_ECX[0x7f] == 8)) || (in_ECX[0x7f] == 3)) ||
          (in_ECX[0x7f] == 4)) {
    (**(code **)(*in_ECX + 0x90))();
    uVar2 = 0;
  }
  else {
    local_6428 = in_ECX;
    if (in_ECX[0x7f] == 2) {
      if ((1 < in_ECX[0x186]) && (in_ECX[in_ECX[0x186] + 0x8ac] == 2)) {
        piVar1 = in_ECX + (in_ECX[0x186] + -1) * 4 + 0x978;
        FUN_00665740(*piVar1,piVar1[1],piVar1[2],piVar1[3],&param_2);
      }
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      if (local_6428[local_6428[0x186] + 0x7e2] == 0) {
        FUN_00517640(param_2,param_3,param_4,param_5);
      }
      (**(code **)(*local_6428 + 0x90))();
      uVar2 = 0;
    }
    else {
      FUN_00446aa0(local_14);
      local_8 = 0;
      if (local_6428[0x7f] == 9) {
        iVar3 = FUN_0044a270(3,local_6428[1],&param_2,&local_642c,0);
        if (iVar3 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
        else {
          iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
          if (iVar3 == 0) {
            FUN_005168b0(0x14de,*(undefined4 *)(local_6428[1] + 0x8f24),
                         *(undefined4 *)(local_6428[1] + 0x8f28),0,0);
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
          else {
            local_6428[local_6428[0x186] + 0x3ed] = local_642c;
            FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
            if (local_6428[local_6428[0x186] + 0x7e2] == 0) {
              FUN_00517640(param_2,param_3,param_4,param_5);
            }
            (**(code **)(*local_6428 + 0x90))();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
        }
      }
      else if (local_6428[0x7f] == 10) {
        iVar3 = FUN_0044a270(3,local_6428[1],&param_2,&local_642c,0);
        if (iVar3 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
        else {
          iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
          if (iVar3 == 0) {
            FUN_005168b0(0x277e,*(undefined4 *)(local_6428[1] + 0x8f24),
                         *(undefined4 *)(local_6428[1] + 0x8f28),0,0);
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
          else {
            local_6428[local_6428[0x186] + 0x3ed] = local_642c;
            FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
            if (local_6428[local_6428[0x186] + 0x7e2] == 0) {
              FUN_00517640(param_2,param_3,param_4,param_5);
            }
            (**(code **)(*local_6428 + 0x90))();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
        }
      }
      else if (local_6428[0x7f] == 0xb) {
        iVar3 = FUN_004500e0(1,local_6428[1],&param_2,&local_6430,0);
        if (iVar3 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
        else {
          iVar3 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
          if (iVar3 == 0) {
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
          else {
            local_6428[local_6428[0x186] + 0x3ed] = local_6430;
            FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
            if (local_6428[local_6428[0x186] + 0x7e2] == 0) {
              FUN_00517640(param_2,param_3,param_4,param_5);
            }
            (**(code **)(*local_6428 + 0x90))();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
        }
      }
      else {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
    }
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiGaibuHenkei[11] */
/* 006661c0  FUN_006661c0  614 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006661c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939620;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x7f] == 1) {
    uVar1 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
  }
  else if ((in_ECX[0x7f] == 0x14) || (in_ECX[0x7f] == 6)) {
    FUN_00667af0(2);
    uVar1 = 0;
  }
  else if (in_ECX[0x7f] == 5) {
    FUN_00667af0(0xffffffff);
    uVar1 = 0;
  }
  else if (in_ECX[0x7f] == 0x28) {
    if (0 < in_ECX[0x186]) {
      (**(code **)(*in_ECX + 0x68))();
    }
    uVar1 = 0;
  }
  else if ((((in_ECX[0x7f] == 7) || (in_ECX[0x7f] == 8)) || (in_ECX[0x7f] == 3)) ||
          (in_ECX[0x7f] == 4)) {
    (**(code **)(*in_ECX + 0x90))();
    uVar1 = 0;
  }
  else {
    if (((in_ECX[0x7f] == 2) || (in_ECX[0x7f] == 9)) ||
       ((in_ECX[0x7f] == 10 || (in_ECX[0x7f] == 0xb)))) {
      FUN_00446aa0(local_14);
      local_8 = 0;
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      iVar2 = FUN_00451eb0(in_ECX[1],&local_24,1);
      if (iVar2 == 1) {
        uVar1 = (**(code **)(*in_ECX + 0x24))(param_1,local_24,local_20,local_1c,local_18);
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return uVar1;
      }
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    uVar1 = 0;
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiGaibuHenkei[4] */
/* 00666430  FUN_00666430  22 bytes, 0 callers */

void FUN_00666430(void)

{
  SetCurrentDirectoryW((LPCWSTR)&DAT_00a08f74);
  return;
}




/* vtable slots: CZukeiGaibuHenkei[3] */
/* 00666450  FUN_00666450  623 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00666450(void)

{
  undefined4 *puVar1;
  undefined1 local_6a20 [20];
  int local_6a0c;
  int local_6a08;
  int local_518;
  short local_514;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939676;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8._0_1_ = 1;
  FUN_005f9c30();
  local_8 = CONCAT31(local_8._1_3_,2);
  local_6a0c = -1;
  if (*(short *)(local_6a08 + 0x218) != 0) {
    local_6a0c = FUN_00601b90();
    if (local_518 == 0) {
      if (local_514 != 0) {
        *(undefined4 *)(local_6a08 + 0x59c) = 0;
        FUN_00404900();
        FUN_006666c0();
      }
    }
    else {
      *(undefined4 *)(local_6a08 + 0x59c) = 1;
      FUN_00404900();
    }
  }
  if (local_6a0c < 10) {
    FUN_0044c990(*(undefined4 *)(local_6a08 + 4),local_6a20);
    FUN_00449d60();
  }
  puVar1 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
  FUN_00517640(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  if (local_6a0c < 0) {
    local_8._0_1_ = 1;
    FUN_005f9fb0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_00663b30();
    FUN_00404c80();
    FUN_0056d7d0();
    local_8._0_1_ = 1;
    FUN_005f9fb0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiGaibuHenkei[14] */
/* 00667eb0  FUN_00667eb0  162 bytes, 0 callers */

uint FUN_00667eb0(int param_1)

{
  int iVar1;
  int *in_ECX;
  uint local_c;
  
  local_c = 0;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8614)) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    local_c = FUN_0041b190(param_1);
  }
  else if (in_ECX[0x7f] == 0x28) {
    if (param_1 == 1) {
      (**(code **)(*in_ECX + 100))();
    }
    local_c = (uint)(param_1 == 1);
    if ((param_1 == 2) && (0 < in_ECX[0x186])) {
      (**(code **)(*in_ECX + 0x68))();
      local_c = 1;
    }
  }
  return local_c;
}



