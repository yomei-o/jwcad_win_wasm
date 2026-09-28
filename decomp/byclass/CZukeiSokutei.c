/* CZukeiSokutei -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiSokutei[1] */
/* 0071af20  FUN_0071af20  68 bytes, 0 callers */

undefined4 FUN_0071af20(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0071aee0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xed0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiSokutei[6] */
/* 0071b670  FUN_0071b670  4878 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0071c6c1) */

void FUN_0071b670(undefined4 *param_1)

{
  undefined8 uVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  double local_679c;
  double local_6794;
  double local_678c;
  double local_6784;
  double local_6758;
  undefined1 local_6750 [20];
  double local_673c;
  int local_6734;
  undefined1 local_250 [16];
  undefined1 local_240 [16];
  undefined1 local_230 [104];
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined2 local_1a8 [202];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009402f6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x210) == 0) {
    local_6734 = in_ECX;
    if (*(double *)(in_ECX + 0x220) != DAT_00a0d630) {
      *(double *)(in_ECX + 0x220) = DAT_00a0d630;
      FUN_0071af70(local_14);
    }
    *(undefined4 *)(*(int *)(local_6734 + 4) + 0x8560) = 0;
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_6734 + 4));
    local_8._0_1_ = 1;
    FUN_00408a60();
    FUN_00408a60();
    *(undefined2 *)(local_6734 + 0x554) = 0;
    local_1a8[0] = 0;
    FUN_0044dd90(local_6750,*(undefined4 *)(local_6734 + 4));
    if (*(int *)(local_6734 + 0x208) == 0) {
      if (*(int *)(local_6734 + 0x1f8) != *(int *)(local_6734 + 0x1fc)) {
        *(undefined4 *)(local_6734 + 0x1fc) = *(undefined4 *)(local_6734 + 0x1f8);
        FUN_0071e460();
      }
      local_673c = *(double *)
                    (*(int *)(local_6734 + 4) + 0x2578 +
                    *(int *)(*(int *)(local_6734 + 4) + 0x256c) * 8);
      if (local_673c < 1.0) {
        FUN_0059f750(local_1a8,L"      S = %lg / 1  ",1.0 / local_673c);
      }
      else {
        FUN_0059f750(local_1a8,L"      S = 1 / %lg  ",SUB84(local_673c,0),
                     (int)((ulonglong)local_673c >> 0x20));
      }
      if (DAT_00a0be50 != 0) {
        local_673c = local_673c / DAT_00a0d630;
      }
      dVar2 = local_673c;
      if (*(int *)(local_6734 + 0x200) == 0x16) {
        local_673c = local_673c * local_673c;
      }
      if (*(int *)(local_6734 + 0x200) == 0x2c) {
        local_673c = 1.0;
      }
      if (*(double *)(local_6734 + 0x378) <= 0.0) {
        local_678c = -*(double *)(local_6734 + 0x378);
      }
      else {
        local_678c = *(double *)(local_6734 + 0x378);
      }
      local_6784 = (local_678c + *(double *)(local_6734 + 0x390)) * local_673c;
      if (*(double *)(local_6734 + 0x3a8) <= 0.0) {
        local_6794 = -*(double *)(local_6734 + 0x3a8);
      }
      else {
        local_6794 = *(double *)(local_6734 + 0x3a8);
      }
      local_679c = *(double *)(local_6734 + 0x370) * local_673c;
      local_6758 = local_679c;
      if (*(int *)(local_6734 + 0x1f8) != 1) {
        if (local_679c <= 0.0) {
          local_679c = -local_679c;
        }
        local_6758 = local_679c;
      }
      if (*(int *)(local_6734 + 0x200) == 0x21) {
        if (*(int *)(local_6734 + 0x1f8) == 1) {
          *(undefined4 *)(local_6734 + 0x228) = 0;
          *(undefined8 *)(local_6734 + 0x358) = 0;
          *(undefined8 *)(local_6734 + 0x350) = 0;
        }
        if ((*(int *)(local_6734 + 0x1f8) == 2) && (*(int *)(local_6734 + 0x228) == 0)) {
          FUN_007208c0(*param_1,param_1[1],param_1[2],param_1[3]);
        }
        local_6784 = *(double *)(local_6734 + 0x350) * local_673c;
        local_6758 = *(double *)(local_6734 + 0x358) * local_673c;
      }
      if (*(int *)(local_6734 + 0x200) == 0x2c) {
        if (*(int *)(local_6734 + 0x1f8) == 3) {
          FUN_00720420(*param_1,param_1[1],param_1[2],param_1[3]);
        }
        local_6784 = *(double *)(local_6734 + 0x380);
        local_6758 = 0.0;
        FUN_0059f750(local_1a8,L"       ");
      }
      FUN_0071fe20(SUB84(local_6784,0),(int)((ulonglong)local_6784 >> 0x20),SUB84(local_6758,0),
                   (int)((ulonglong)local_6758 >> 0x20));
      FUN_0059f7c0(local_1a8,local_6734 + 0x554);
      *(undefined2 *)(local_6734 + 0xa10) = 0;
      if ((*(int *)(local_6734 + 0x200) == 0x16) && (*(int *)(local_6734 + 0x39c) != 0)) {
        FUN_0045a220(local_6734 + 0xa10,local_6794 * dVar2,DAT_00a0be58,DAT_00a0be60,DAT_00a0be64,
                     DAT_00a0be68);
        if (DAT_00a0be6c != 0) {
          if (DAT_00a0be50 == 0) {
            FUN_0059f7c0(local_6734 + 0xa10,&DAT_0095b618);
          }
          else {
            uVar3 = FUN_00404920();
            FUN_0059f7c0(local_6734 + 0xa10,uVar3);
          }
        }
        FUN_005977f0(0x14b4);
        uVar3 = FUN_00404920();
        FUN_0059f7c0(local_1a8,uVar3);
        FUN_00404770();
        FUN_005977f0(0x1674);
        uVar3 = FUN_00404920();
        FUN_0059f7c0(local_1a8,uVar3);
        FUN_00404770();
        FUN_005977f0(0x1b5e);
        uVar3 = FUN_00404920();
        FUN_0059f7c0(local_1a8,uVar3);
        FUN_00404770();
        FUN_0059f7c0(local_1a8,local_6734 + 0xa10);
        FUN_005977f0(7000);
        uVar3 = FUN_00404920();
        FUN_0059f7c0(local_1a8,uVar3);
        FUN_00404770();
      }
      if (*(int *)(local_6734 + 0x204) == 0) {
        if (*(int *)(local_6734 + 0x1f8) == 1) {
          if ((*(int *)(local_6734 + 0x200) == 0x2c) || (*(int *)(local_6734 + 0x200) == 0x21)) {
            FUN_004efbb0(0x151c,local_1a8,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
          else {
            FUN_004efbb0(0x14c8,local_1a8,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
        }
        else {
          FUN_0041f760();
          local_8._0_1_ = 2;
          FUN_004552a0(local_230);
          if (*(int *)(local_6734 + 0x1f8) == 2) {
            if (*(int *)(local_6734 + 0x200) == 0x2c) {
              FUN_0042f6b0(1);
              FUN_004988c0();
              FUN_004988c0();
              FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
              FUN_004efbb0(0x2785,0,0);
              local_8._0_1_ = 1;
              FUN_0041fd70();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
            }
            else if (*(int *)(local_6734 + 0x200) == 0x21) {
              FUN_0042f6b0(3);
              FUN_004988c0();
              FUN_004988c0();
              FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
              FUN_00408a60();
              FUN_00408a60();
              FUN_0042f6b0(1);
              uVar1 = *(undefined8 *)(*(int *)(local_6734 + 4) + 0x17c0);
              FUN_005f89c0(*(undefined4 *)(local_6734 + 0x340),*(undefined4 *)(local_6734 + 0x344),
                           *(undefined4 *)(local_6734 + 0x348),*(undefined4 *)(local_6734 + 0x34c),
                           (int)uVar1,(int)((ulonglong)uVar1 >> 0x20),
                           *(undefined4 *)(local_6734 + 4));
              local_1b8 = 0x4234f46b04000000;
              local_1c8 = 0xc234f46b04000000;
              local_1c0 = 0;
              local_1b0 = 0;
              FUN_005f8ce0(&local_1b8);
              FUN_005f8ce0(&local_1c8);
              FUN_004988c0();
              FUN_004988c0();
              FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
              local_1c8 = 0;
              local_1b8 = 0;
              local_1b0 = 0x4234f46b04000000;
              local_1c0 = 0xc234f46b04000000;
              FUN_005f8ce0(&local_1b8);
              FUN_005f8ce0(&local_1c8);
              FUN_004988c0();
              FUN_004988c0();
              FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
              FUN_004efbb0(0x151d,local_1a8,0);
              local_8._0_1_ = 1;
              FUN_0041fd70();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
            }
            else {
              FUN_004efbb0(0x14cb,local_1a8,0);
              if (*(int *)(local_6734 + 0x200) == 0x16) {
                FUN_0042f6b0(9);
                FUN_004988c0();
                FUN_004988c0();
                FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
                FUN_004988c0();
                FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
              }
              FUN_0042f6b0(3);
              FUN_004988c0();
              FUN_004988c0();
              FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
              local_8._0_1_ = 1;
              FUN_0041fd70();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
            }
          }
          else if (*(int *)(local_6734 + 0x1f8) == 3) {
            FUN_004988c0();
            *(undefined8 *)(local_6734 + 0x78) = *(undefined8 *)(local_6734 + 0x388);
            FUN_0076bee0();
            FUN_004efbb0(0x2786,local_1a8,0);
            local_8._0_1_ = 1;
            FUN_0041fd70();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
          else {
            if (*(int *)(local_6734 + 0x1f8) == 0x32) {
              FUN_004efbb0(0x14f7,local_1a8,0);
            }
            if (*(int *)(local_6734 + 0x1f8) == 0x34) {
              if (*(int *)(local_6734 + 0x200) == 0x16) {
                FUN_0059f750(local_1a8,L"     (L)+   (R)-");
              }
              else {
                local_1a8[0] = 0;
              }
              FUN_004efbb0(0x14f7,local_1a8,0);
            }
            if (*(int *)(local_6734 + 0x1f8) == 0x33) {
              FUN_004efbb0(0x14fb,local_1a8,0);
              iVar4 = FUN_00720230(*param_1,param_1[1],param_1[2],param_1[3]);
              if (iVar4 == 0) {
                local_8._0_1_ = 1;
                FUN_0041fd70();
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                ExceptionList = local_10;
                return;
              }
              (**(code **)(*(int *)(local_6734 + 0x298) + 0x20))(1);
              FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_6734 + 0x298);
              if (*(int *)(local_6734 + 0x200) == 0x16) {
                FUN_0042f6b0(9);
                FUN_004988c0();
                FUN_004988c0();
                FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
                iVar4 = FUN_0045ab70(local_6734 + 0x298,local_250,local_240);
                if (iVar4 == 0) {
                  local_8._0_1_ = 1;
                  FUN_0041fd70();
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                  ExceptionList = local_10;
                  return;
                }
                FUN_004988c0();
                FUN_00450b70(local_6750,*(undefined4 *)(local_6734 + 4),local_230);
              }
            }
            local_8._0_1_ = 1;
            FUN_0041fd70();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
        }
      }
      else {
        FUN_004efbb0(0x14c6,local_1a8,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      FUN_004efbb0(0x1465,0,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    FUN_006f7cc0(param_1);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSokutei[16] */
/* 0071c980  FUN_0071c980  1580 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0071c980(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_6444 [20];
  int local_6430;
  int local_642c;
  int local_6428;
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
  puStack_c = &LAB_0094033b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6428 = in_ECX;
  if (*(int *)(in_ECX + 0x210) == 0) {
    if (*(int *)(in_ECX + 0x214) == 0) {
      if (*(int *)(in_ECX + 0x208) == 0) {
        FUN_00446aa0(local_14);
        local_8 = 0;
        FUN_0079dea2(*(undefined4 *)(local_6428 + 4));
        local_8._0_1_ = 1;
        if ((*(int *)(local_6428 + 0x1f8) == 0x34) || (*(int *)(local_6428 + 0x1f8) == 0x32)) {
          FUN_0071dc40();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 1;
        }
        else if (*(int *)(local_6428 + 0x21c) < 1) {
          if (*(int *)(local_6428 + 0x204) == 0) {
            if (*(int *)(local_6428 + 0x1f8) == 0x33) {
              *(undefined4 *)(local_6428 + 0x1f8) = 2;
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar2 = 1;
            }
            else {
              iVar1 = FUN_0045af10(*(undefined4 *)(local_6428 + 4));
              if (iVar1 == 0) {
                if (*(int *)(local_6428 + 0x1f8) == 2) {
                  *(undefined4 *)(local_6428 + 0x1f8) = 1;
                  FUN_00404c80();
                  FUN_0056d7d0();
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                  uVar2 = 1;
                }
                else if (*(int *)(local_6428 + 0x1f8) == 3) {
                  *(undefined4 *)(local_6428 + 0x1f8) = 2;
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
                FUN_00454580(local_6444,*(undefined4 *)(local_6428 + 4));
                local_642c = FUN_0044fd00(local_6444,*(undefined4 *)(local_6428 + 4));
                FUN_00720ff0();
                if (local_642c == 0) {
                  *(undefined4 *)(local_6428 + 0x1f8) = 1;
                  FUN_00404c80();
                  FUN_0056d7d0();
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                  uVar2 = 1;
                }
                else {
                  iVar1 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
                  if (iVar1 == 0) {
                    FUN_004988c0(local_54,*(undefined4 *)(local_642c + 0x18),
                                 *(undefined4 *)(local_642c + 0x1c),
                                 *(undefined4 *)(local_642c + 0x20),
                                 *(undefined4 *)(local_642c + 0x24));
                  }
                  else {
                    local_6430 = local_642c;
                    iVar1 = FUN_0040c200();
                    if (iVar1 != 0) {
                      *(undefined4 *)(local_6428 + 0x1f8) = 1;
                      FUN_00404c80();
                      FUN_0056d7d0();
                      local_8 = (uint)local_8._1_3_ << 8;
                      FUN_0079dfff();
                      local_8 = 0xffffffff;
                      FUN_00447100();
                      ExceptionList = local_10;
                      return 1;
                    }
                    FUN_00408a60();
                    FUN_00408a60();
                    iVar1 = FUN_0045ab70(local_6430,local_34,&local_24);
                    if (iVar1 == 0) {
                      local_8 = (uint)local_8._1_3_ << 8;
                      FUN_0079dfff();
                      local_8 = 0xffffffff;
                      FUN_00447100();
                      ExceptionList = local_10;
                      return 1;
                    }
                    FUN_004988c0(local_44,local_24,local_20,local_1c,local_18);
                  }
                  FUN_00404c80();
                  FUN_0056d7d0();
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                  uVar2 = 1;
                }
              }
            }
          }
          else {
            *(undefined4 *)(local_6428 + 0x204) = 0;
            FUN_0071e460();
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
          FUN_00458a80(local_6444,*(undefined4 *)(local_6428 + 4),0);
          *(int *)(local_6428 + 0x21c) = *(int *)(local_6428 + 0x21c) + -1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 1;
        }
      }
      else {
        *(undefined4 *)(in_ECX + 0x208) = 0;
        FUN_0071af70();
        FUN_0071b440();
        uVar2 = 1;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x214) = 0;
      FUN_0071b440();
      uVar2 = 1;
    }
  }
  else {
    iVar1 = FUN_006f85c0();
    if (iVar1 == 0) {
      *(undefined4 *)(local_6428 + 0x210) = 0;
      FUN_0071af70();
      FUN_0071b440();
    }
    uVar2 = 1;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiSokutei[0] */
/* 0071cfb0  FUN_0071cfb0  16 bytes, 0 callers */

undefined ** FUN_0071cfb0(void)

{
  return &PTR_s_CZukeiSokutei_0097abb8;
}




/* vtable slots: CZukeiSokutei[23] */
/* 0071d0f0  FUN_0071d0f0  95 bytes, 0 callers */

undefined4 FUN_0071d0f0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x210) == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
      if (DAT_00a0cc6c == 0) {
        FUN_0071dcb0();
      }
      else {
        FUN_0071dd60();
      }
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CZukeiSokutei[46] */
/* 0071d150  FUN_0071d150  1003 bytes, 0 callers */

undefined4
FUN_0071d150(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int *in_ECX;
  undefined4 local_10;
  
  if (DAT_00a0c7c0 == 0) {
    if (in_ECX[0x84] == 0) {
      local_10 = 0;
      if ((in_ECX[0x82] == 0) && (*(int *)(in_ECX[1] + 0x9078) != 0)) {
        switch(param_2) {
        case 1:
          if (param_3 == 1) {
            FUN_005168b0(0x1439,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            (**(code **)(*in_ECX + 100))();
          }
          break;
        case 2:
          if (param_3 == 1) {
            FUN_005168b0(0x143a,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            (**(code **)(*in_ECX + 0x68))();
          }
          break;
        case 3:
          if (param_3 == 1) {
            FUN_005168b0(0x143b,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            (**(code **)(*in_ECX + 0x6c))();
          }
          break;
        case 4:
          if (param_3 == 1) {
            FUN_005168b0(0x143c,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            (**(code **)(*in_ECX + 0x70))();
          }
          break;
        case 5:
          if ((in_ECX[0x80] == 0x2c) || (in_ECX[0x80] == 0x21)) {
            local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          }
          else if (param_3 == 1) {
            if ((in_ECX[0x7e] == 1) || (in_ECX[0x7e] == 0x34)) {
              FUN_005168b0(0x1462,*(undefined4 *)(in_ECX[1] + 0x8f50),
                           *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
            }
            else {
              FUN_005168b0(0x1463,*(undefined4 *)(in_ECX[1] + 0x8f50),
                           *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
            }
          }
          else if (param_3 == 2) {
            (**(code **)(*in_ECX + 0x74))();
          }
          break;
        default:
          local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          break;
        case 0xc:
          if (param_3 == 1) {
            FUN_005168b0(0x143e,*(undefined4 *)(in_ECX[1] + 0x8f50),
                         *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            (**(code **)(*in_ECX + 0x80))();
          }
        }
      }
      else {
        local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
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
      local_10 = 0;
    }
    else {
      local_10 = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_10;
}




/* vtable slots: CZukeiSokutei[34] */
/* 0071d570  FUN_0071d570  345 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0071d570(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_63f0;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (in_ECX[1] == 0) {
    local_63f0 = 0;
  }
  else {
    local_63f0 = in_ECX[1] + 0x88;
  }
  iVar1 = FUN_0044fcd0(local_63f0);
  if (iVar1 == 0) {
    DAT_00a0d618 = 0;
    in_ECX[0x84] = 0;
    in_ECX[0x85] = 1;
    in_ECX[0x86] = 1;
    FUN_0071af70();
    FUN_00720cf0();
    (**(code **)(*in_ECX + 0x80))();
    uVar3 = 0x143d;
    uVar2 = 99;
    FUN_00404c80(99,0x143d);
    FUN_004fca20();
    FUN_0041af40(uVar2,uVar3);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSokutei[25] */
/* 0071d6d0  FUN_0071d6d0  389 bytes, 0 callers */

void FUN_0071d6d0(void)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x218) == 0) {
    if (*(int *)(in_ECX + 0x210) == 0) {
      bVar1 = false;
      if ((DAT_00a0cc6c != 0) && (DAT_00a0cc74 != 0)) {
        bVar1 = true;
      }
      DAT_00a0cc6c = 0;
      DAT_00a0cc74 = 0;
      if (*(int *)(in_ECX + 0x208) == 0) {
        *(undefined4 *)(in_ECX + 0x200) = 0xb;
        *(undefined4 *)(in_ECX + 0x204) = 0;
        *(undefined4 *)(in_ECX + 0x208) = 0;
        FUN_0071b440();
        *(undefined4 *)(in_ECX + 0x39c) = 0;
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xdc) = *(undefined4 *)(in_ECX + 0x200);
        }
        if (bVar1) {
          FUN_0071b440();
          *(undefined4 *)(in_ECX + 0x210) = 1;
          FUN_0071af70();
        }
      }
      else {
        if (DAT_00a0be5c < 1) {
          local_10 = -DAT_00a0be5c;
        }
        else {
          local_10 = DAT_00a0be5c;
        }
        local_c = local_10 + 1;
        if (10 < local_c) {
          local_c = 1;
        }
        if (DAT_00a0be5c < 0) {
          local_c = -local_c;
        }
        DAT_00a0be5c = local_c;
        FUN_006a17a0();
      }
    }
    else {
      FUN_004066b0();
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x218) = 0;
  }
  return;
}




/* vtable slots: CZukeiSokutei[26] */
/* 0071d860  FUN_0071d860  281 bytes, 0 callers */

void FUN_0071d860(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x210) == 0) {
    if (*(int *)(in_ECX + 0x208) == 0) {
      *(undefined4 *)(in_ECX + 0x200) = 0x16;
      *(undefined4 *)(in_ECX + 0x204) = 0;
      *(undefined4 *)(in_ECX + 0x208) = 0;
      *(undefined4 *)(in_ECX + 0x39c) = DAT_00a0be4c;
      if (DAT_00a0cc6c != 0) {
        *(uint *)(in_ECX + 0x39c) = *(uint *)(in_ECX + 0x39c) ^ 1;
      }
      DAT_00a0cc74 = 0;
      DAT_00a0cc6c = 0;
      FUN_0071b440();
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xdc) = *(undefined4 *)(in_ECX + 0x200);
      }
    }
    else {
      local_c = DAT_00a0be60 + 1;
      if (1 < local_c) {
        local_c = 0;
      }
      DAT_00a0be60 = local_c;
      FUN_006a18b0();
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiSokutei[27] */
/* 0071d980  FUN_0071d980  225 bytes, 0 callers */

void FUN_0071d980(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x210) == 0) {
    if (*(int *)(in_ECX + 0x208) == 0) {
      *(undefined4 *)(in_ECX + 0x200) = 0x21;
      *(undefined4 *)(in_ECX + 0x204) = 0;
      *(undefined4 *)(in_ECX + 0x208) = 0;
      FUN_0071b440();
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xdc) = *(undefined4 *)(in_ECX + 0x200);
      }
      *(undefined4 *)(in_ECX + 0x39c) = 0;
    }
    else {
      local_c = DAT_00a0be64 + 1;
      if (1 < local_c) {
        local_c = 0;
      }
      DAT_00a0be64 = local_c;
      FUN_006a1a00();
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiSokutei[28] */
/* 0071da70  FUN_0071da70  225 bytes, 0 callers */

void FUN_0071da70(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x210) == 0) {
    if (*(int *)(in_ECX + 0x208) == 0) {
      *(undefined4 *)(in_ECX + 0x200) = 0x2c;
      *(undefined4 *)(in_ECX + 0x204) = 0;
      *(undefined4 *)(in_ECX + 0x208) = 0;
      FUN_0071b440();
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xdc) = *(undefined4 *)(in_ECX + 0x200);
      }
      *(undefined4 *)(in_ECX + 0x39c) = 0;
    }
    else {
      local_c = DAT_00a0be68 + 1;
      if (2 < local_c) {
        local_c = 0;
      }
      DAT_00a0be68 = local_c;
      FUN_006a1b50();
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiSokutei[29] */
/* 0071db60  FUN_0071db60  211 bytes, 0 callers */

void FUN_0071db60(void)

{
  int in_ECX;
  int local_c;
  
  if (*(int *)(in_ECX + 0x210) == 0) {
    if (*(int *)(in_ECX + 0x208) == 0) {
      if ((*(int *)(in_ECX + 0x200) != 0x2c) && (*(int *)(in_ECX + 0x200) != 0x21)) {
        if ((*(int *)(in_ECX + 0x1f8) == 1) || (*(int *)(in_ECX + 0x1f8) == 0x34)) {
          *(undefined4 *)(in_ECX + 0x1f8) = 0x34;
        }
        else {
          *(undefined4 *)(in_ECX + 0x1f8) = 0x32;
        }
        *(undefined4 *)(in_ECX + 0x204) = 0;
        FUN_0071e460();
        FUN_00404c80();
        FUN_0056d7d0();
      }
    }
    else {
      local_c = DAT_00a0be6c + 1;
      if (1 < local_c) {
        local_c = 0;
      }
      DAT_00a0be6c = local_c;
      FUN_0071fc00();
    }
  }
  else {
    FUN_006fb760();
  }
  return;
}




/* vtable slots: CZukeiSokutei[30] */
/* 0071dcb0  FUN_0071dcb0  175 bytes, 1 callers */

void FUN_0071dcb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x210) == 0) {
    if (*(int *)(in_ECX + 0x208) == 0) {
      if (*(int *)(in_ECX + 0x200) == 0x2c) {
        DAT_00a0be54 = (uint)(DAT_00a0be54 == 0);
      }
      else if (DAT_00a0be50 == 0) {
        DAT_00a0be50 = 1;
      }
      else {
        DAT_00a0be50 = 0;
      }
      FUN_0071e080();
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      *(undefined4 *)(in_ECX + 0x208) = 0;
      FUN_0071af70();
      FUN_0071b440();
    }
  }
  else {
    FUN_006fbbb0();
  }
  return;
}




/* vtable slots: CZukeiSokutei[31] */
/* 0071dd60  FUN_0071dd60  94 bytes, 1 callers */

void FUN_0071dd60(void)

{
  int in_ECX;
  undefined4 local_8;
  
  if (*(int *)(in_ECX + 0x210) == 0) {
    local_8 = DAT_00a0be58 + 1;
    if (4 < local_8) {
      local_8 = -1;
    }
    DAT_00a0be58 = local_8;
    FUN_0071e780();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else {
    FUN_006fbbf0();
  }
  return;
}




/* vtable slots: CZukeiSokutei[32] */
/* 0071ddc0  FUN_0071ddc0  54 bytes, 0 callers */

void FUN_0071ddc0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x210) == 0) {
    *(undefined4 *)(in_ECX + 0x204) = 1;
    FUN_0071dc40();
  }
  else {
    FUN_006fbc40();
  }
  return;
}




/* vtable slots: CZukeiSokutei[33] */
/* 0071de00  FUN_0071de00  426 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0071de00(void)

{
  int *in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX[0x84] == 0) {
    FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    FUN_0079dea2(in_ECX[1]);
    local_8._0_1_ = 1;
    if (in_ECX[0x85] == 0) {
      if (in_ECX[0x7e] == 1) {
        FUN_0071fa90();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        *(undefined4 *)(in_ECX[1] + 0x8578) = 1;
        FUN_0071b440();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      in_ECX[0x85] = 0;
      in_ECX[0x7e] = 1;
      if (in_ECX[0x80] == 0xb) {
        (**(code **)(*in_ECX + 100))();
      }
      uVar2 = 0x1465;
      uVar1 = 99;
      FUN_00404c80(99,0x1465);
      FUN_004fca20();
      FUN_0041af40(uVar1,uVar2);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    FUN_006fbf90();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSokutei[36] */
/* 0071dfb0  FUN_0071dfb0  39 bytes, 0 callers */

void FUN_0071dfb0(void)

{
  int *in_ECX;
  
  if (in_ECX[0x84] != 0) {
    (**(code **)(*in_ECX + 0x88))();
  }
  return;
}




/* vtable slots: CZukeiSokutei[50] */
/* 0071dfe0  FUN_0071dfe0  155 bytes, 0 callers */

void FUN_0071dfe0(double param_1)

{
  int in_ECX;
  
  if (((1e-07 <= param_1) && (*(int *)(in_ECX + 0x200) == 0xb)) &&
     (1e-07 < *(double *)
               (*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8))) {
    *(double *)(in_ECX + 0x370) =
         param_1 / *(double *)
                    (*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
    *(double *)(in_ECX + 0x378) = *(double *)(in_ECX + 0x378) + *(double *)(in_ECX + 0x370);
  }
  return;
}




/* vtable slots: CZukeiSokutei[9] */
/* 0071e8d0  FUN_0071e8d0  3952 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0071e8d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *in_ECX;
  double local_6488;
  undefined1 local_6480 [4];
  undefined1 local_647c [20];
  int *local_6468;
  undefined1 local_6464 [25336];
  undefined4 local_16c;
  undefined4 local_140;
  undefined4 local_13c;
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
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094044b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x84] == 0) {
    if (in_ECX[0x82] == 0) {
      in_ECX[0xe6] = 0;
      local_6468 = in_ECX;
      FUN_00446aa0(local_14);
      local_8 = 0;
      FUN_0079dea2();
      local_8._0_1_ = 1;
      FUN_0044dd90(local_647c,local_6468[1]);
      if (local_6468[0x81] == 0) {
        local_6468[0x87] = 0;
        if (local_6468[0x7e] == 1) {
          puVar2 = (undefined4 *)FUN_004988c0(local_84,param_2,param_3,param_4,param_5);
          FUN_004988c0(local_74,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
          local_6468[0x7e] = 2;
          FUN_0071e3a0();
          local_6468[0x8a] = 0;
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else if (local_6468[0x7e] == 2) {
          iVar3 = FUN_00436970(param_2,param_3,param_4,param_5,local_6468[0xd0],local_6468[0xd1],
                               local_6468[0xd2],local_6468[0xd3]);
          if (iVar3 == 0) {
            if ((local_6468[0x80] == 0xb) || (local_6468[0x80] == 0x16)) {
              local_6468[0x8a] = local_6468[0x8a] + 1;
              FUN_004552a0();
              (**(code **)(local_6468[0x8c] + 0x20))();
              FUN_004988c0(local_64,local_6468[0xd0],local_6468[0xd1],local_6468[0xd2],
                           local_6468[0xd3]);
              FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
              FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
              FUN_00450af0();
              FUN_00720ff0();
            }
            else if (local_6468[0x80] == 0x21) {
              local_6468[0x8a] = 1;
              FUN_007208c0(param_2,param_3,param_4,param_5);
            }
            else if (local_6468[0x80] == 0x2c) {
              FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
              local_6468[0x7e] = 3;
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
            FUN_005168b0(0x14df,*(undefined4 *)(local_6468[1] + 0x8f24),
                         *(undefined4 *)(local_6468[1] + 0x8f28),0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
        }
        else if (local_6468[0x7e] == 3) {
          iVar3 = FUN_00436970(param_2,param_3,param_4,param_5,local_6468[0xd8],local_6468[0xd9],
                               local_6468[0xda],local_6468[0xdb]);
          if (iVar3 == 0) {
            FUN_00720420(param_2,param_3,param_4,param_5);
            local_6468[0x7e] = 1;
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            FUN_005168b0(0x14df,*(undefined4 *)(local_6468[1] + 0x8f24),
                         *(undefined4 *)(local_6468[1] + 0x8f28),0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
        }
        else if (local_6468[0x7e] == 0x32) {
          local_140 = 1;
          local_13c = 1;
          iVar3 = FUN_0044a270(3,local_6468[1],&param_2,local_6480,1);
          if (iVar3 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            iVar3 = FUN_0079d98a();
            if (iVar3 == 0) {
              FUN_005168b0(0x277e,*(undefined4 *)(local_6468[1] + 0x8f24),
                           *(undefined4 *)(local_6468[1] + 0x8f28),0,0);
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
            else {
              FUN_00420020();
              FUN_004988c0(local_24,local_6468[0xd0],local_6468[0xd1],local_6468[0xd2],
                           local_6468[0xd3]);
              iVar3 = FUN_0045b790();
              if (iVar3 == 0) {
                FUN_005168b0(0x1455,*(undefined4 *)(local_6468[1] + 0x8f24),
                             *(undefined4 *)(local_6468[1] + 0x8f28),0,0);
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                uVar1 = 0;
              }
              else {
                iVar3 = FUN_00436970(local_6468[0xec],local_6468[0xed],local_6468[0xee],
                                     local_6468[0xef],local_6468[0xd0],local_6468[0xd1],
                                     local_6468[0xd2],local_6468[0xd3]);
                if (iVar3 == 0) {
                  FUN_005168b0(0x1464,*(undefined4 *)(local_6468[1] + 0x8f24),
                               *(undefined4 *)(local_6468[1] + 0x8f28),0,0);
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0079dfff();
                  local_8 = 0xffffffff;
                  FUN_00447100();
                  uVar1 = 0;
                }
                else {
                  local_6468[0x7e] = 0x33;
                  FUN_0071dc40();
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
        else if (local_6468[0x7e] == 0x33) {
          iVar3 = FUN_00720230(param_2,param_3,param_4,param_5);
          if (iVar3 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            local_6468[0x8a] = local_6468[0x8a] + 1;
            iVar3 = FUN_0045b790();
            if (iVar3 == 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
            else {
              local_6468[0x7e] = 2;
              FUN_0071dc40();
              FUN_004988c0(local_94,param_2,param_3,param_4,param_5);
              (**(code **)(local_6468[0xa6] + 0x20))();
              FUN_00450af0();
              if ((local_6468[0x80] == 0xb) || (local_6468[0x80] == 0x16)) {
                FUN_00720ff0();
              }
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
        else if (local_6468[0x7e] == 0x34) {
          iVar3 = FUN_00720970(param_2,param_3,param_4,param_5);
          if (iVar3 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else {
            local_6468[0x8a] = local_6468[0x8a] + 1;
            FUN_00720ff0();
            local_6468[0x7e] = 1;
            FUN_0071dc40();
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
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
        if (local_6468[0x80] == 0x2c) {
          (**(code **)(*local_6468 + 0x18))();
        }
        if (local_6468[0x80] == 0x21) {
          local_6488 = *(double *)(local_6468[1] + 0x2578 + *(int *)(local_6468[1] + 0x256c) * 8);
          if (DAT_00a0be50 != 0) {
            local_6488 = local_6488 / DAT_00a0d630;
          }
          FUN_0071fe20(*(double *)(local_6468 + 0xd4) * local_6488,
                       *(double *)(local_6468 + 0xd6) * local_6488);
        }
        if (local_6468[0x80] == 0x16) {
          FUN_0059f7e0(local_6468 + 0x1ba,local_6468 + 0xf0);
          if (DAT_00a0be6c != 0) {
            if (DAT_00a0be50 == 0) {
              FUN_0059f7c0(local_6468 + 0x1ba,L"mm^u2");
            }
            else {
              uVar1 = FUN_00404920();
              FUN_0059f7c0(local_6468 + 0x1ba,uVar1);
              FUN_0059f7c0(local_6468 + 0x1ba,&DAT_0097adc0);
            }
          }
        }
        FUN_0044de70(local_647c,local_6468[1]);
        FUN_007205a0(local_6464,local_647c,local_6468 + 0x1ba,&param_2);
        if (local_6468[0x80] == 0x21) {
          local_16c = 1;
          FUN_007205a0(local_6464,local_647c,local_6468 + 0x21f,&param_2);
        }
        if ((local_6468[0x80] == 0x16) && (local_6468[0xe7] != 0)) {
          local_16c = 1;
          FUN_007205a0(local_6464,local_647c,local_6468 + 0x284,&param_2);
        }
        local_6468[0x87] = local_6468[0x87] + 1;
        FUN_0044de70(local_647c,local_6468[1]);
        local_6468[0x81] = 0;
        FUN_0071e460();
        *(undefined4 *)(local_6468[1] + 0x8578) = 1;
        FUN_00404c80();
        FUN_0056d200();
        if (local_6468[0x85] != 0) {
          local_6468[0x85] = 0;
          FUN_0071b440();
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiSokutei[11] */
/* 0071f840  FUN_0071f840  588 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0071f840(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  puStack_c = &LAB_009309e0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x84] == 0) {
    if (in_ECX[0x82] == 0) {
      FUN_00446aa0(local_14);
      local_8 = 0;
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      if (in_ECX[0x7e] == 0x34) {
        in_ECX[0xe6] = 1;
        iVar2 = FUN_00720970(param_2,param_3,param_4,param_5);
        if (iVar2 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          in_ECX[0x8a] = in_ECX[0x8a] + 1;
          FUN_00720ff0();
          in_ECX[0x7e] = 1;
          FUN_0071dc40();
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
      }
      else {
        iVar2 = FUN_00451eb0(in_ECX[1],&local_24,1);
        if (iVar2 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          uVar1 = (**(code **)(*in_ECX + 0x24))(param_1,local_24,local_20,local_1c,local_18);
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiSokutei[3] */
/* 0071fd40  FUN_0071fd40  210 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0071fd40(void)

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
  if (*(int *)(in_ECX + 0x210) == 0) {
    local_63e8 = in_ECX;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    FUN_006fe2f0(local_14);
  }
  ExceptionList = local_10;
  return;
}



