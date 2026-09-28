/* CZukeiSentaku -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiSentaku[1] */
/* 006f7c70  FUN_006f7c70  68 bytes, 0 callers */

undefined4 FUN_006f7c70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006f7c30();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1f8);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiSentaku[6] */
/* 006f7cc0  FUN_006f7cc0  2295 bytes, 14 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x006f8468) */

void FUN_006f7cc0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  double local_68dc;
  double local_68d4;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f24b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8610)) {
    if ((*(uint *)(*(int *)(in_ECX + 4) + 0x2ac4) & 2) == 0) {
      *(undefined4 *)(in_ECX + 0xc0) = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 0xc0) = 1;
    }
    if (*(int *)(in_ECX + 0xa8) == 0) {
      *(undefined4 *)(in_ECX + 0xa8) = 1;
      FUN_00404c80(uVar1);
      iVar2 = FUN_004fca20();
      if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8610)) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x1e8) = 0;
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x1ec) = 0;
        FUN_00404c80();
        FUN_004fca20();
        FUN_007955d2();
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797df8();
      }
    }
    if (*(int *)(in_ECX + 0xac) == 0) {
      if (*(int *)(in_ECX + 0xb0) == 0) {
        *(undefined4 *)(*(int *)(in_ECX + 8) + 0x18) = *(undefined4 *)(in_ECX + 0xc0);
        *(undefined4 *)(*(int *)(in_ECX + 8) + 8) = *(undefined4 *)(in_ECX + 0xd8);
        *(undefined4 *)(*(int *)(in_ECX + 8) + 0xc) = *(undefined4 *)(in_ECX + 0xe4);
        if ((*(int *)(in_ECX + 0xdc) == 0) && (*(int *)(in_ECX + 0xe0) == 0)) {
          FUN_00404c80(uVar1);
          iVar2 = FUN_004fca20();
          if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8610)) {
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x1e8) == 0) {
              *(undefined4 *)(*(int *)(in_ECX + 8) + 0x10) = 0;
            }
            else {
              *(undefined4 *)(*(int *)(in_ECX + 8) + 0x10) = 1;
            }
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x1ec) == 0) {
              *(undefined4 *)(*(int *)(in_ECX + 8) + 0x14) = 0;
            }
            else {
              *(undefined4 *)(*(int *)(in_ECX + 8) + 0x14) = 1;
            }
          }
        }
        else {
          *(undefined4 *)(*(int *)(in_ECX + 8) + 8) = 0;
          *(undefined4 *)(*(int *)(in_ECX + 8) + 0x14) = 0;
          **(undefined4 **)(in_ECX + 8) = 0xf;
          if (*(int *)(in_ECX + 0xdc) != 0) {
            *(undefined4 *)(*(int *)(in_ECX + 8) + 0x10) = 1;
          }
          if (*(int *)(in_ECX + 0xe0) != 0) {
            **(undefined4 **)(in_ECX + 8) = 8;
          }
        }
        FUN_00446aa0();
        local_8 = 0;
        FUN_0079dea2();
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_0040c0e0();
        iVar2 = FUN_00572b10();
        if (iVar2 == 0) {
          *(undefined4 *)(in_ECX + 0xb4) = 0;
        }
        else {
          *(undefined4 *)(in_ECX + 0xb4) = 1;
        }
        if (*(int *)(in_ECX + 0xb4) != *(int *)(in_ECX + 0xb8)) {
          *(undefined4 *)(in_ECX + 0xb8) = *(undefined4 *)(in_ECX + 0xb4);
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8610)) {
            FUN_00404c80();
            FUN_004fca20();
            FUN_005c8120();
          }
          if (*(int *)(in_ECX + 0xb4) == 0) {
            FUN_00653df0();
            FUN_00652e80();
          }
        }
        if (*(int *)(in_ECX + 0xbc) == 0) {
          if (*(int *)(in_ECX + 0xc) == 0) {
            FUN_0040ac80();
            local_8 = local_8 & 0xffffff00;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
          else {
            if (*(int *)(in_ECX + 0xe0) == 0) {
              FUN_00404c80();
              iVar2 = FUN_004fca20();
              if ((*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8610)) &&
                 (DAT_00a0d618 != 0)) {
                FUN_00404c80();
                FUN_004fca20();
                iVar2 = FUN_005c9b10();
                if (iVar2 != 0) {
                  FUN_005977f0(0x16c4);
                  FUN_00404920();
                  FUN_006f77c0();
                  FUN_00404770();
                }
                FUN_00404c80();
                FUN_004fca20();
                iVar2 = FUN_005c9b40();
                if (iVar2 != 0) {
                  FUN_005977f0(0x16c5);
                  FUN_00404920();
                  FUN_006f77c0();
                  FUN_00404770();
                }
              }
              FUN_004efbb0();
            }
            else {
              FUN_004efbb0();
            }
            local_8 = local_8 & 0xffffff00;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
        }
        else {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8610)) {
            FUN_00404c80();
            iVar2 = FUN_004fca20();
            if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xe0) == 0) {
              FUN_004efbb0();
            }
            else {
              FUN_005977f0();
              FUN_00404920();
              FUN_0059f750();
              FUN_00404770();
              FUN_004efbb0();
              FUN_00404c80();
              FUN_004fca20();
              fVar3 = (float10)FUN_005cb3d0();
              if ((double)fVar3 <= 0.0) {
                FUN_00404c80();
                FUN_004fca20();
                fVar3 = (float10)FUN_005cb3d0();
                local_68d4 = -(double)fVar3;
              }
              else {
                FUN_00404c80();
                FUN_004fca20();
                fVar3 = (float10)FUN_005cb3d0();
                local_68d4 = (double)fVar3;
              }
              if (local_68d4 <= 1e-07) {
                FUN_00404c80();
                FUN_004fca20();
                FUN_00797df8();
                FUN_00404c80();
                FUN_004fca20();
                FUN_004b1140();
                FUN_00404c80();
                FUN_004fca20();
                fVar3 = (float10)FUN_005cb3d0();
                if ((double)fVar3 <= 0.0) {
                  FUN_00404c80();
                  FUN_004fca20();
                  fVar3 = (float10)FUN_005cb3d0();
                  local_68dc = -(double)fVar3;
                }
                else {
                  FUN_00404c80();
                  FUN_004fca20();
                  fVar3 = (float10)FUN_005cb3d0();
                  local_68dc = (double)fVar3;
                }
                if (local_68dc <= 1e-07) {
                  uVar5 = 0;
                  uVar4 = 0x4014000000000000;
                  FUN_00404c80(0x4014000000000000,0);
                  FUN_004fca20();
                  FUN_0058ae50(uVar4,uVar5);
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
      else {
        FUN_005977f0();
        FUN_00404920();
        FUN_0059f750();
        FUN_00404770();
        FUN_004efbb0();
      }
    }
    else {
      FUN_004efbb0();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSentaku[16] */
/* 006f85c0  FUN_006f85c0  936 bytes, 13 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006f85c0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined1 local_6414 [20];
  undefined4 local_6400;
  undefined4 local_63fc;
  undefined4 local_63f8;
  undefined4 local_63f4;
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093774b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  if (*(int *)(in_ECX + 0xbc) != 0) {
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8610)) {
      uVar3 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_005c9c30(uVar3);
    }
  }
  if (*(int *)(local_63e8 + 0xac) == 0) {
    if (*(int *)(local_63e8 + 0xb0) == 0) {
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
      local_8._0_1_ = 1;
      FUN_0044de00(local_6414,*(undefined4 *)(local_63e8 + 4));
      FUN_0044dd90(local_6414,*(undefined4 *)(local_63e8 + 4));
      FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_6414);
      FUN_00449d60(local_6414,*(undefined4 *)(local_63e8 + 4),1);
      if ((*(int *)(local_63e8 + 0xc) == 0) && (*(int *)(*(int *)(local_63e8 + 8) + 4) == 1)) {
        *(undefined4 *)(*(int *)(local_63e8 + 8) + 4) = 0;
        local_63f4 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (*(int *)(local_63e8 + 0xc) == 0) {
        local_63ec = *(int *)(local_63e8 + 4);
        if (local_63ec == 0) {
          local_63f0 = 0;
        }
        else {
          local_63f0 = local_63ec + 0x88;
        }
        iVar2 = FUN_0044fcd0(local_63f0);
        if (iVar2 == 0) {
          local_6400 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_63f4 = local_6400;
        }
        else {
          if ((*(int *)(*(int *)(local_63e8 + 4) + 0x177c) == 0) &&
             (1 < *(int *)(*(int *)(local_63e8 + 4) + 6000))) {
            FUN_00517430(0);
          }
          local_63fc = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_63f4 = local_63fc;
        }
      }
      else {
        *(undefined4 *)(*(int *)(local_63e8 + 8) + 4) = 1;
        *(undefined4 *)(local_63e8 + 0xc) = 0;
        FUN_0040ac80(*(int *)(local_63e8 + 4) + 0x8f78);
        local_63f8 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63f4 = local_63f8;
      }
    }
    else {
      *(undefined4 *)(local_63e8 + 0xb0) = 0;
      FUN_004fb9f0();
      if ((*(int *)(*(int *)(local_63e8 + 4) + 0x177c) == 0) &&
         (*(int *)(*(int *)(local_63e8 + 4) + 6000) == 3)) {
        FUN_00517430(0);
      }
      local_63f4 = 1;
    }
  }
  else {
    *(undefined4 *)(local_63e8 + 0xac) = 0;
    FUN_00404c80(uVar1);
    FUN_0056d7d0();
    local_63f4 = 1;
  }
  ExceptionList = local_10;
  return local_63f4;
}




/* vtable slots: CZukeiSentaku[0] */
/* 006f8970  FUN_006f8970  16 bytes, 0 callers */

undefined ** FUN_006f8970(void)

{
  return &PTR_s_CZukeiSentaku_0097a56c;
}




/* vtable slots: CZukeiSentaku[9] */
/* 006fd240  FUN_006fd240  2057 bytes, 15 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006fd240(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_64c0 [20];
  undefined4 local_64ac;
  CMFCCaptionButtonEx *local_64a8;
  undefined4 local_64a4;
  undefined4 local_64a0;
  CMFCCaptionButtonEx *local_649c;
  int local_6498;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_15c;
  undefined4 local_154;
  undefined4 local_150;
  undefined1 local_b4 [128];
  undefined1 local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f53b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6498 + 4));
  local_8._0_1_ = 1;
  uVar2 = FUN_0040c0e0();
  *(undefined4 *)(local_6498 + 500) = 0;
  FUN_00510dc0(uVar1,uVar2);
  if (*(int *)(local_6498 + 0xac) == 0) {
    if (*(int *)(local_6498 + 0xbc) == 0) {
      if (*(int *)(local_6498 + 0xc) == 0) {
        if (0 < *(int *)(*(int *)(local_6498 + 8) + 4)) {
          *(undefined4 *)(local_6498 + 500) = 1;
        }
        iVar4 = FUN_0040dbb0();
        if (iVar4 != 0) {
          *(undefined4 *)(local_6498 + 0xc) = 1;
        }
      }
      else if (*(int *)(local_6498 + 0xb0) == 0) {
        if (*(int *)(local_6498 + 0xe0) == 0) {
          local_178 = 1;
          local_174 = 1;
          local_16c = 1;
          local_168 = 1;
          local_15c = 1;
          local_154 = 1;
          if (*(int *)(local_6498 + 0xc0) == 0) {
            local_150 = 1;
          }
          iVar4 = FUN_0044a270();
          if ((iVar4 == 1) && (iVar4 = FUN_006feb30(local_649c), iVar4 != 0)) {
            if ((*(int *)(local_649c + 4) == 0) ||
               (iVar4 = FUN_0079d98a(&PTR_s_CDataBlock_009fe144), iVar4 != 0)) {
              iVar4 = FUN_00447b90(local_64c0,1,*(undefined4 *)(local_6498 + 4),local_649c,1,1);
              if (iVar4 == 0) {
                *(ushort *)(local_649c + 0x44) = *(ushort *)(local_649c + 0x44) & 0xfffd;
                *(int *)(*(int *)(local_6498 + 4) + 0x8560) =
                     *(int *)(*(int *)(local_6498 + 4) + 0x8560) + -1;
                if (*(int *)(*(int *)(local_6498 + 4) + 0x8560) < 0) {
                  *(undefined4 *)(*(int *)(local_6498 + 4) + 0x8560) = 0;
                }
              }
              else {
                *(ushort *)(local_649c + 0x44) = *(ushort *)(local_649c + 0x44) | 2;
                FUN_00455870();
                CMFCCaptionButtonEx::GetRect(local_649c);
                FUN_004988c0();
                FUN_004988c0();
                *(int *)(*(int *)(local_6498 + 4) + 0x8560) =
                     *(int *)(*(int *)(local_6498 + 4) + 0x8560) + 1;
              }
            }
            else {
              FUN_0040f580(local_649c);
            }
          }
        }
        else {
          iVar4 = FUN_004500e0();
          if (iVar4 != 0) {
            local_649c = local_64a8;
            iVar4 = FUN_006feb30(local_64a8);
            if (iVar4 != 0) {
              iVar4 = FUN_00447b90(local_64c0,1,*(undefined4 *)(local_6498 + 4),local_649c,1,1);
              if (iVar4 == 0) {
                *(int *)(*(int *)(local_6498 + 4) + 0x8560) =
                     *(int *)(*(int *)(local_6498 + 4) + 0x8560) + -1;
                *(ushort *)(local_649c + 0x44) = *(ushort *)(local_649c + 0x44) & 0xfffd;
                if (*(int *)(*(int *)(local_6498 + 4) + 0x8560) < 0) {
                  *(undefined4 *)(*(int *)(local_6498 + 4) + 0x8560) = 0;
                }
              }
              else {
                *(ushort *)(local_649c + 0x44) = *(ushort *)(local_649c + 0x44) | 2;
                FUN_00455870();
                CMFCCaptionButtonEx::GetRect(local_649c);
                FUN_004988c0();
                FUN_004988c0();
                *(int *)(*(int *)(local_6498 + 4) + 0x8560) =
                     *(int *)(*(int *)(local_6498 + 4) + 0x8560) + 1;
              }
            }
          }
        }
      }
      else {
        FUN_004988c0();
        FUN_006fc970(*(undefined4 *)(local_6498 + 0xb0));
        *(undefined4 *)(local_6498 + 0xb0) = 0;
      }
      puVar3 = (undefined4 *)FUN_004b75a0(local_b4);
      uVar2 = *puVar3;
      uVar5 = puVar3[1];
      uVar6 = puVar3[2];
      uVar7 = puVar3[3];
      FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
      iVar4 = FUN_00498960(uVar2,uVar5,uVar6,uVar7);
      if (iVar4 != 0) {
        FUN_006f8980();
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_64ac = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_64a0 = local_64ac;
    }
    else {
      FUN_006feba0();
      *(undefined4 *)(*(int *)(local_6498 + 4) + 0x8578) = 1;
      *(undefined4 *)(local_6498 + 0xc) = 0;
      local_64a4 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_64a0 = local_64a4;
    }
  }
  else {
    FUN_00517640(param_2,param_3,param_4,param_5);
    FUN_004988c0();
    *(undefined4 *)(local_6498 + 0xac) = 0;
    FUN_0044de00(local_64c0,*(undefined4 *)(local_6498 + 4));
    uVar2 = 0;
    puVar3 = (undefined4 *)FUN_004b75a0(local_34);
    FUN_004508b0(0x10,local_64c0,*(undefined4 *)(local_6498 + 4),*puVar3,puVar3[1],puVar3[2],
                 puVar3[3],uVar2);
    FUN_00404c80();
    FUN_0056d7d0();
    local_64a0 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_64a0;
}




/* vtable slots: CZukeiSentaku[11] */
/* 006fda70  FUN_006fda70  2158 bytes, 14 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006fda70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_64ac [20];
  undefined4 local_6498;
  CMFCCaptionButtonEx *local_6494;
  undefined4 local_6490;
  undefined4 local_648c;
  undefined4 local_6488;
  undefined4 local_6484;
  undefined4 local_6480;
  CMFCCaptionButtonEx *local_647c;
  int local_6478;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_14c;
  undefined4 local_130;
  undefined1 local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f58b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6478 + 4));
  local_8._0_1_ = 1;
  *(undefined4 *)(local_6478 + 500) = 0;
  FUN_00510dc0();
  if (*(int *)(local_6478 + 0xac) == 0) {
    if (*(int *)(local_6478 + 0xbc) == 0) {
      if (*(int *)(local_6478 + 0xc) == 0) {
        if (0 < *(int *)(*(int *)(local_6478 + 8) + 4)) {
          *(undefined4 *)(local_6478 + 500) = 1;
        }
        iVar1 = FUN_0040deb0();
        if (iVar1 != 0) {
          *(undefined4 *)(local_6478 + 0xc) = 1;
        }
      }
      else if (*(int *)(local_6478 + 0xb0) == 0) {
        if ((*(int *)(local_6478 + 0xe0) == 1) || (DAT_00a0cc6c == 0)) {
          if (*(int *)(local_6478 + 0xc0) == 0) {
            local_130 = 1;
          }
          iVar1 = FUN_004500e0();
          if (iVar1 != 0) {
            local_647c = local_6494;
            iVar1 = FUN_006feb30(local_6494);
            if (iVar1 != 0) {
              iVar1 = FUN_00447b90(local_64ac,1,*(undefined4 *)(local_6478 + 4),local_647c,1,1);
              if (iVar1 == 0) {
                *(int *)(*(int *)(local_6478 + 4) + 0x8560) =
                     *(int *)(*(int *)(local_6478 + 4) + 0x8560) + -1;
                *(ushort *)(local_647c + 0x44) = *(ushort *)(local_647c + 0x44) & 0xfffd;
                if (*(int *)(*(int *)(local_6478 + 4) + 0x8560) < 0) {
                  *(undefined4 *)(*(int *)(local_6478 + 4) + 0x8560) = 0;
                }
              }
              else {
                *(ushort *)(local_647c + 0x44) = *(ushort *)(local_647c + 0x44) | 2;
                FUN_00455870();
                CMFCCaptionButtonEx::GetRect(local_647c);
                FUN_004988c0();
                FUN_004988c0();
                *(int *)(*(int *)(local_6478 + 4) + 0x8560) =
                     *(int *)(*(int *)(local_6478 + 4) + 0x8560) + 1;
              }
            }
          }
        }
        else {
          local_158 = 1;
          local_154 = 1;
          local_14c = 1;
          if (*(int *)(local_6478 + 0xc0) == 0) {
            local_130 = 1;
          }
          DAT_00a0cc6c = 0;
          iVar1 = FUN_0044a270();
          if ((iVar1 == 1) && (iVar1 = FUN_006feb30(local_647c), iVar1 != 0)) {
            iVar1 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
            if ((iVar1 == 0) && (iVar1 = FUN_0079d98a(&PTR_s_CDataBlock_009fe144), iVar1 == 0)) {
              if ((*(int *)(local_647c + 4) == 0) ||
                 (iVar1 = FUN_0079d98a(&PTR_s_CDataBlock_009fe144), iVar1 != 0)) {
                FUN_0040f830();
              }
              else {
                FUN_0040f580(local_647c);
              }
            }
            else {
              iVar1 = FUN_00447b90(local_64ac,1,*(undefined4 *)(local_6478 + 4),local_647c,1,1);
              if (iVar1 == 0) {
                *(int *)(*(int *)(local_6478 + 4) + 0x8560) =
                     *(int *)(*(int *)(local_6478 + 4) + 0x8560) + -1;
                *(ushort *)(local_647c + 0x44) = *(ushort *)(local_647c + 0x44) & 0xfffd;
                if (*(int *)(*(int *)(local_6478 + 4) + 0x8560) < 0) {
                  *(undefined4 *)(*(int *)(local_6478 + 4) + 0x8560) = 0;
                }
              }
              else {
                *(ushort *)(local_647c + 0x44) = *(ushort *)(local_647c + 0x44) | 2;
                FUN_00455870();
                CMFCCaptionButtonEx::GetRect(local_647c);
                FUN_004988c0();
                FUN_004988c0();
                *(int *)(*(int *)(local_6478 + 4) + 0x8560) =
                     *(int *)(*(int *)(local_6478 + 4) + 0x8560) + 1;
              }
            }
          }
        }
      }
      else {
        FUN_004988c0();
        FUN_006fc970(*(undefined4 *)(local_6478 + 0xb0));
        *(undefined4 *)(local_6478 + 0xb0) = 0;
      }
      puVar2 = (undefined4 *)FUN_004b75a0(local_94);
      uVar3 = *puVar2;
      uVar4 = puVar2[1];
      uVar5 = puVar2[2];
      uVar6 = puVar2[3];
      FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
      iVar1 = FUN_00498960(uVar3,uVar4,uVar5,uVar6);
      if (iVar1 != 0) {
        FUN_006f8980();
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_6498 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6484 = local_6498;
    }
    else {
      iVar1 = FUN_00451eb0(*(undefined4 *)(local_6478 + 4),&param_2,1);
      if (iVar1 == 0) {
        local_648c = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6484 = local_648c;
      }
      else {
        FUN_006feba0();
        *(undefined4 *)(*(int *)(local_6478 + 4) + 0x8578) = 1;
        *(undefined4 *)(local_6478 + 0xc) = 0;
        local_6490 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6484 = local_6490;
      }
    }
  }
  else {
    local_6480 = DAT_00a0cbd0;
    DAT_00a0cbd0 = 0;
    iVar1 = FUN_00451eb0(*(undefined4 *)(local_6478 + 4),&param_2,1);
    if (iVar1 == 0) {
      DAT_00a0cbd0 = local_6480;
      local_6484 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      DAT_00a0cbd0 = local_6480;
      local_6488 = FUN_006fd240();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6484 = local_6488;
    }
  }
  ExceptionList = local_10;
  return local_6484;
}




/* vtable slots: CZukeiSentaku[3] */
/* 006fe2f0  FUN_006fe2f0  229 bytes, 7 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006fe2f0(void)

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
  FUN_0044de00(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



