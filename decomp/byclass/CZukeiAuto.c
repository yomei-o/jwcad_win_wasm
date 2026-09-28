/* CZukeiAuto -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiAuto[1] */
/* 0062a700  FUN_0062a700  68 bytes, 0 callers */

undefined4 FUN_0062a700(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0062a650();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x120);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiAuto[6] */
/* 0062f0a0  FUN_0062f0a0  2261 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0062f551) */

void FUN_0062f0a0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  float10 fVar5;
  double local_66b8;
  double local_66b0;
  undefined1 local_66a8 [24];
  undefined4 local_6690;
  undefined4 local_6688;
  undefined4 local_6680;
  undefined4 local_6678;
  undefined4 local_6670;
  undefined4 local_6668;
  undefined4 local_6660;
  undefined4 local_665c;
  undefined4 local_6658;
  int *local_6654;
  int local_6650;
  int local_664c;
  int local_6648;
  undefined1 local_6644 [25552];
  undefined1 local_274 [204];
  undefined2 local_1a8 [202];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009375e6;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8ebc) = 0;
  local_6648 = in_ECX;
  local_14 = uVar1;
  if (*(int *)(in_ECX + 0xbc) == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
      FUN_00633190(uVar1);
    }
    if (*(int *)(local_6648 + 0x118) != 0) {
      FUN_00633190(uVar1);
    }
  }
  if (*(int *)(local_6648 + 0xc4) == 0) {
    if (*(int *)(local_6648 + 0xac) == 5) {
      iVar2 = *(int *)(*(int *)(local_6648 + 4) + 0x8f58);
      if (*(int *)(local_6648 + 0x110) == iVar2 || *(int *)(local_6648 + 0x110) - iVar2 < 0) {
        local_664c = -(*(int *)(local_6648 + 0x110) - *(int *)(*(int *)(local_6648 + 4) + 0x8f58));
      }
      else {
        local_664c = *(int *)(local_6648 + 0x110) - *(int *)(*(int *)(local_6648 + 4) + 0x8f58);
      }
      if (local_664c < 2) {
        iVar2 = *(int *)(*(int *)(local_6648 + 4) + 0x8f5c);
        if (*(int *)(local_6648 + 0x114) == iVar2 || *(int *)(local_6648 + 0x114) - iVar2 < 0) {
          local_6650 = -(*(int *)(local_6648 + 0x114) - *(int *)(*(int *)(local_6648 + 4) + 0x8f5c))
          ;
        }
        else {
          local_6650 = *(int *)(local_6648 + 0x114) - *(int *)(*(int *)(local_6648 + 4) + 0x8f5c);
        }
        if (local_6650 < 2) {
          FUN_004efbb0(0x153d,0,0);
          ExceptionList = local_10;
          return;
        }
      }
      *(undefined4 *)(local_6648 + 0xac) = 0;
      *(undefined4 *)(local_6648 + 0xe0) = 0;
      *(undefined4 *)(local_6648 + 200) = 0;
      local_665c = 0x8003;
      FUN_00630a10(*(undefined4 *)(local_6648 + 0x10c),0x8003);
    }
    else {
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      if (*(int *)(iVar2 + 0x1a0) == 0) {
        iVar2 = *(int *)(local_6648 + 4);
        FUN_00404c80();
        iVar3 = FUN_004fca20();
        *(undefined4 *)(iVar3 + 0x1a0) = *(undefined4 *)(iVar2 + 0x85ec);
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        local_6654 = *(int **)(iVar2 + 0x1a0);
        (**(code **)(*local_6654 + 0x18c))();
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797f20();
        *(undefined4 *)(local_6648 + 0xb0) = 1;
        *(undefined4 *)(local_6648 + 0x11c) = 0xffffd8f1;
      }
      FUN_00446aa0();
      local_8 = 0;
      FUN_00464040();
      local_8._0_1_ = 1;
      FUN_0079dea2();
      local_8._0_1_ = 2;
      FUN_0040c0e0();
      if ((*(int *)(local_6648 + 200) == 0) || (*(int *)(local_6648 + 0xac) != 10)) {
        if ((*(int *)(local_6648 + 200) == 0) || (*(int *)(local_6648 + 0xac) != 6)) {
          if (*(int *)(local_6648 + 200) == 0) {
            *(undefined4 *)(*(int *)(local_6648 + 4) + 0x8ebc) = 1;
            FUN_004efbb0(0x153a,0,0);
          }
          else {
            FUN_004efbb0(0x153b,0,0);
          }
          FUN_0044dd90(local_66a8,*(undefined4 *)(local_6648 + 4));
          local_8._0_1_ = 1;
          FUN_0079dfff();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_004640a0();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          local_6658 = 0;
          local_1a8[0] = 0;
          iVar2 = FUN_00633640(local_66a8,local_6644,*(undefined4 *)(local_6648 + 200),
                               *(undefined4 *)(local_6648 + 0xe8),*(undefined4 *)(local_6648 + 0xec)
                               ,*(undefined4 *)(local_6648 + 0xf0),
                               *(undefined4 *)(local_6648 + 0xf4));
          if (iVar2 == 0) {
            local_6678 = FUN_005977f0();
            uVar4 = FUN_00404920();
            FUN_0059f750(local_1a8,uVar4);
            FUN_00404770();
            if (DAT_00a0cc58 <= 0.0) {
              local_66b8 = -DAT_00a0cc58;
            }
            else {
              local_66b8 = DAT_00a0cc58;
            }
            if (1e-07 < local_66b8) {
              if (DAT_00a0cc60 == 0) {
                local_6688 = FUN_005977f0();
                uVar4 = FUN_00404920();
                FUN_0059f7c0(local_1a8,uVar4);
                FUN_00404770();
              }
              else {
                local_6680 = FUN_005977f0();
                uVar4 = FUN_00404920();
                FUN_0059f7c0(local_1a8,uVar4);
                FUN_00404770();
              }
              FUN_0062a340(local_274,L" %lg",DAT_00a0cc58);
              FUN_0059f7c0(local_1a8,local_274);
            }
            local_6690 = FUN_005977f0();
            uVar4 = FUN_00404920();
            FUN_0059f7c0(local_1a8,uVar4);
            FUN_00404770();
            iVar2 = FUN_0079d98a();
            if (iVar2 == 0) {
              FUN_004efbb0(0x2783,local_1a8,0);
            }
            else {
              FUN_004efbb0(0x2781,local_1a8,0);
            }
            local_8._0_1_ = 1;
            FUN_0079dfff();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_004640a0();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
          else {
            local_6660 = FUN_005977f0();
            uVar4 = FUN_00404920();
            FUN_0059f7c0(local_1a8,uVar4);
            FUN_00404770();
            local_6668 = FUN_005977f0();
            uVar4 = FUN_00404920();
            FUN_0059f7c0(local_1a8,uVar4);
            FUN_00404770();
            local_6670 = FUN_005977f0();
            uVar4 = FUN_00404920();
            FUN_0059f7c0(local_1a8,uVar4);
            FUN_00404770();
            FUN_004efbb0(0x2718,local_1a8,0);
            local_8._0_1_ = 1;
            FUN_0079dfff();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_004640a0();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
        }
      }
      else {
        FUN_004efbb0(0x158d,0,0);
        local_66b0 = 0.0;
        if (*(int *)(*(int *)(local_6648 + 4) + 0x17d8) == 0x8017) {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_6648 + 4) + 0x862c)) {
            FUN_00404c80();
            FUN_004fca20();
            fVar5 = (float10)FUN_004cad70();
            local_66b0 = (double)fVar5;
          }
        }
        FUN_00478c70(*(undefined4 *)(local_6648 + 4),local_6644,local_66a8,
                     *(undefined4 *)(local_6648 + 200),*param_1,param_1[1],param_1[2],param_1[3],0,
                     local_66b0);
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_004640a0();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
  }
  else if (*(int *)(local_6648 + 0xc0) == 0) {
    (**(code **)(**(int **)(local_6648 + 0xc4) + 0x18))();
  }
  else {
    FUN_004efbb0(0x14c2,0,0);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiAuto[16] */
/* 0062f980  FUN_0062f980  284 bytes, 0 callers */

undefined4 FUN_0062f980(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc0) == 0) {
    if ((*(int *)(in_ECX + 0xc4) == 0) || (*(int *)(in_ECX + 0xbc) == 0)) {
      *(undefined4 *)(in_ECX + 0xb8) = 0;
      if (*(int *)(in_ECX + 0xc4) == 0) {
        if (*(int *)(in_ECX + 200) == 0) {
          FUN_00633190();
          FUN_00404c80();
          FUN_0056d7d0();
          uVar1 = 0;
        }
        else {
          FUN_00633190();
          FUN_00404c80();
          FUN_0056d7d0();
          uVar1 = 1;
        }
      }
      else {
        iVar2 = FUN_0079d98a(&PTR_s_CZukeiSen_0097a430);
        if ((iVar2 == 0) && (iVar2 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0x40))(), iVar2 != 0))
        {
          return 1;
        }
        FUN_00633190();
        FUN_00404c80();
        FUN_0056d7d0();
        uVar1 = 1;
      }
    }
    else {
      uVar1 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0x40))();
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0xc0) = 0;
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CZukeiAuto[0] */
/* 0062faa0  FUN_0062faa0  16 bytes, 0 callers */

undefined ** FUN_0062faa0(void)

{
  return &PTR_s_CZukeiAuto_00977bfc;
}




/* vtable slots: CZukeiAuto[23] */
/* 0062fab0  FUN_0062fab0  52 bytes, 0 callers */

undefined4 FUN_0062fab0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0x5c))();
  }
  return uVar1;
}




/* vtable slots: CZukeiAuto[22] */
/* 0062faf0  FUN_0062faf0  285 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0062faf0(void)

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
  if (*(int *)(in_ECX + 0xc4) != 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_0044dd20(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_0044de00(local_63fc,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(local_63e8 + 0xc0) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiAuto[46] */
/* 0062fc10  FUN_0062fc10  748 bytes, 0 callers */

undefined4
FUN_0062fc10(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int in_ECX;
  undefined4 local_c;
  
  if (param_2 == 0xd) {
    if (param_3 == 1) {
      FUN_005168b0(0x271d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
    }
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0;
    local_c = 0;
  }
  else {
    local_c = 0;
    if ((*(int *)(in_ECX + 0xc4) != 0) && (DAT_00a0c7bc < 2)) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x857c) = 0;
      local_c = (**(code **)(**(int **)(in_ECX + 0xc4) + 0xb8))
                          (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      if (*(int *)(*(int *)(in_ECX + 4) + 0x857c) == 0) {
        return local_c;
      }
    }
    if (*(int *)(*(int *)(in_ECX + 4) + 0x908c) == 0) {
      if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
        if (param_2 == 5) {
          if (param_3 == 1) {
            FUN_005168b0(0x2715,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_0076e360(param_4,param_5,param_6,param_7);
          }
        }
        else if (param_2 == 6) {
          FUN_00778870();
          if (DAT_00a0c7d4 != 0) {
            *(undefined4 *)(in_ECX + 0x94) = 0;
          }
          if (param_3 == 1) {
            if (*(int *)(in_ECX + 0x9c) + 1 < *(int *)(in_ECX + 0x94)) {
              FUN_005168b0(0x148d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                           *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
            }
            else {
              FUN_005168b0(0x2716,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                           *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
            }
          }
          else if (param_3 == 2) {
            FUN_007751e0(0,param_4,param_5,param_6,param_7);
            *(undefined4 *)(in_ECX + 0x94) = 0;
          }
        }
        else {
          local_c = FUN_0062a980(1,param_1,0,0,param_2,param_3,param_4,param_5,param_6,param_7);
        }
      }
      else {
        local_c = FUN_0062a980(1,param_1,0,1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      local_c = FUN_00770b60(1,param_3,param_4,param_5,param_6,param_7);
    }
  }
  return local_c;
}




/* vtable slots: CZukeiAuto[47] */
/* 0062ff00  FUN_0062ff00  641 bytes, 0 callers */

undefined4
FUN_0062ff00(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_2 == 0xd) {
    if (param_3 == 1) {
      FUN_005168b0(0x271d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
    }
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if (((*(int *)(in_ECX + 0xc4) != 0) && (DAT_00a0c7bc < 2)) && (*(int *)(in_ECX + 0xc0) == 0)) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x857c) = 0;
      uVar1 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0xbc))
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      if (*(int *)(*(int *)(in_ECX + 4) + 0x857c) == 0) {
        return uVar1;
      }
    }
    if (*(int *)(*(int *)(in_ECX + 4) + 0x908c) == 0) {
      if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
        switch(param_2 + -3) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 6:
        case 9:
          *(undefined4 *)(in_ECX + 0xb4) = 0;
          uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          break;
        default:
          uVar1 = FUN_0062a980(1,param_1,1,2,param_2,param_3,param_4,param_5,param_6,param_7,
                               param_2 + -3,uVar1);
        }
      }
      else {
        uVar1 = FUN_0062a980(1,param_1,1,3,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      if (*(int *)(*(int *)(in_ECX + 4) + 0x908c) == -1) {
        *(undefined4 *)(in_ECX + 0xb4) = 0;
      }
      if (*(int *)(in_ECX + 0xb4) == 0x804a) {
        uVar1 = FUN_00770b60(1,param_3,param_4,param_5,param_6,param_7);
      }
      else {
        uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
  }
  return uVar1;
}




/* vtable slots: CZukeiAuto[24] */
/* 006301b0  FUN_006301b0  104 bytes, 0 callers */

void FUN_006301b0(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x60))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[34] */
/* 00630220  FUN_00630220  107 bytes, 0 callers */

void FUN_00630220(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x88))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[25] */
/* 00630290  FUN_00630290  104 bytes, 0 callers */

void FUN_00630290(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 100))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[26] */
/* 00630300  FUN_00630300  104 bytes, 0 callers */

void FUN_00630300(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x68))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[27] */
/* 00630370  FUN_00630370  104 bytes, 0 callers */

void FUN_00630370(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x6c))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[28] */
/* 006303e0  FUN_006303e0  104 bytes, 0 callers */

void FUN_006303e0(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x70))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[29] */
/* 00630450  FUN_00630450  104 bytes, 0 callers */

void FUN_00630450(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x74))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[30] */
/* 006304c0  FUN_006304c0  104 bytes, 0 callers */

void FUN_006304c0(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x78))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[31] */
/* 00630530  FUN_00630530  104 bytes, 0 callers */

void FUN_00630530(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x7c))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[32] */
/* 006305a0  FUN_006305a0  107 bytes, 0 callers */

void FUN_006305a0(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x80))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[33] */
/* 00630610  FUN_00630610  107 bytes, 0 callers */

void FUN_00630610(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x84))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiAuto[40] */
/* 00630680  FUN_00630680  51 bytes, 0 callers */

void FUN_00630680(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0xa0))();
  }
  return;
}




/* vtable slots: CZukeiAuto[36] */
/* 006306c0  FUN_006306c0  95 bytes, 0 callers */

void FUN_006306c0(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x90))();
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8578) != 0) {
    *(undefined4 *)(in_ECX + 0x118) = 1;
  }
  return;
}




/* vtable slots: CZukeiAuto[37] */
/* 00630720  FUN_00630720  51 bytes, 0 callers */

void FUN_00630720(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x94))();
  }
  return;
}




/* vtable slots: CZukeiAuto[42] */
/* 00630760  FUN_00630760  51 bytes, 0 callers */

void FUN_00630760(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0xa8))();
  }
  return;
}




/* vtable slots: CZukeiAuto[41] */
/* 006307a0  FUN_006307a0  51 bytes, 0 callers */

void FUN_006307a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0xa4))();
  }
  return;
}




/* vtable slots: CZukeiAuto[38] */
/* 006307e0  FUN_006307e0  51 bytes, 0 callers */

void FUN_006307e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x98))();
  }
  return;
}




/* vtable slots: CZukeiAuto[39] */
/* 00630820  FUN_00630820  51 bytes, 0 callers */

void FUN_00630820(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0x9c))();
  }
  return;
}




/* vtable slots: CZukeiAuto[49] */
/* 00630860  FUN_00630860  66 bytes, 0 callers */

void FUN_00630860(undefined8 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0xc4))(param_1);
  }
  return;
}




/* vtable slots: CZukeiAuto[50] */
/* 006308b0  FUN_006308b0  66 bytes, 0 callers */

void FUN_006308b0(undefined8 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 200))(param_1);
  }
  return;
}




/* vtable slots: CZukeiAuto[51] */
/* 00630900  FUN_00630900  199 bytes, 0 callers */

void FUN_00630900(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  int in_ECX;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093761d;
  local_10 = ExceptionList;
  uStack_1c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    local_18 = (undefined1 *)&uStack_20;
    local_14 = in_ECX;
    FUN_00403dd0();
    (**(code **)(**(int **)(local_14 + 0xc4) + 0xcc))(param_1,param_2,param_3,param_4,param_5);
  }
  local_8 = 0xffffffff;
  uStack_20 = 0x6309b6;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiAuto[45] */
/* 006309d0  FUN_006309d0  51 bytes, 0 callers */

void FUN_006309d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0xb4))();
  }
  return;
}




/* vtable slots: CZukeiAuto[44] */
/* 00630f40  FUN_00630f40  51 bytes, 0 callers */

void FUN_00630f40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0xb0))();
  }
  return;
}




/* vtable slots: CZukeiAuto[12] */
/* 00630f80  FUN_00630f80  425 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00630f80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x31] == 0) {
    if (in_ECX[0x32] == 0) {
      if (in_ECX[0x2b] == 5) {
        in_ECX[0x2b] = 0;
        FUN_00630a10(0,0x8005);
        uVar1 = 0;
      }
      else {
        uVar1 = (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
      }
    }
    else {
      if (in_ECX[0x2b] == 0) {
        in_ECX[0x2b] = 6;
        FUN_004988c0(local_18,param_2,param_3,param_4,param_5);
        if (in_ECX[0x2c] != 0) {
          uVar1 = 3;
          FUN_00404c80(3);
          FUN_004fca20();
          FUN_004117f0(uVar1);
        }
      }
      else if (in_ECX[0x2b] == 6) {
        FUN_004988c0(local_28,in_ECX[0x3a],in_ECX[0x3b],in_ECX[0x3c],in_ECX[0x3d]);
        return 1;
      }
      uVar1 = 0;
    }
  }
  else if (in_ECX[0x30] == 0) {
    uVar1 = (**(code **)(*(int *)in_ECX[0x31] + 0x30))(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CZukeiAuto[43] */
/* 00631130  FUN_00631130  51 bytes, 0 callers */

void FUN_00631130(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0xac))();
  }
  return;
}




/* vtable slots: CZukeiAuto[9] */
/* 00631170  FUN_00631170  2614 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00631170(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined1 local_6490 [20];
  int local_647c;
  int local_6478;
  undefined4 local_6474;
  int local_6470;
  int local_646c;
  int local_6468;
  undefined1 local_6464 [25552];
  undefined1 local_94 [16];
  undefined1 local_84 [16];
  undefined1 local_74 [32];
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
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009376ab;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6468 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_6474 = FUN_0040c0e0();
  iVar1 = FUN_004146c0();
  if (iVar1 == 0) {
    FUN_004d2660();
  }
  if (*(int *)(local_6468 + 0xc4) != 0) {
    if (*(int *)(local_6468 + 0xc0) != 0) {
      FUN_0062a750(0,param_2,param_3,param_4,param_5);
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    uVar2 = (**(code **)(**(int **)(local_6468 + 0xc4) + 0x24))
                      (param_1,param_2,param_3,param_4,param_5);
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return uVar2;
  }
  local_6470 = 0;
  local_646c = 0;
  if (param_1 != 0x231d) {
    *(undefined4 *)(*(int *)(local_6468 + 4) + 0x8f34) = 1;
    local_6470 = FUN_0044a270(3,*(undefined4 *)(local_6468 + 4),&param_2,&local_646c,0);
    if ((local_6470 == 0) && (local_646c != 0)) {
      iVar1 = FUN_0044f240();
      if (iVar1 != 0) {
        uVar4 = 0;
        uVar2 = 0;
        puVar3 = (undefined4 *)FUN_0041c8d0(9999,9999);
        FUN_005168b0(0x146f,*puVar3,puVar3[1],uVar2,uVar4);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      local_6478 = *(int *)(local_6468 + 4);
      if (local_6478 == 0) {
        local_647c = 0;
      }
      else {
        local_647c = local_6478 + 0x88;
      }
      iVar1 = FUN_0042dcb0(local_647c);
      if (iVar1 != 0) {
        FUN_00516e40(local_646c,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
    }
    if ((local_6470 != 0) && (local_646c != 0)) {
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      iVar1 = FUN_0045b6c0(0,local_646c,&local_24);
      if (iVar1 == 0) {
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      FUN_00455870(local_646c,local_24,local_20,local_1c,local_18);
    }
  }
  if ((*(int *)(local_6468 + 200) == 0) || (*(int *)(local_6468 + 0xac) != 10)) {
    if ((*(int *)(local_6468 + 200) == 0) || (*(int *)(local_6468 + 0xac) != 6)) {
      if ((*(int *)(local_6468 + 200) == 0) ||
         ((*(int *)(local_6468 + 200) != local_646c && (local_6470 != 0)))) {
        if ((*(int *)(local_6468 + 200) == 0) || ((local_6470 != 1 || (local_646c == 0)))) {
          FUN_004988c0(local_84,param_2,param_3,param_4,param_5);
          if (local_6470 == 0) {
            *(undefined4 *)(local_6468 + 0xe0) = 0;
            *(undefined4 *)(local_6468 + 200) = 0;
            if (*(int *)(local_6468 + 0xac) == 5) {
              *(undefined4 *)(local_6468 + 0xac) = 0;
              FUN_00630a10(0,0x8005);
            }
            else {
              *(undefined4 *)(local_6468 + 0xac) = 5;
              FUN_004988c0(local_94,param_2,param_3,param_4,param_5);
              *(undefined4 *)(local_6468 + 0x10c) = 0;
              uVar2 = *(undefined4 *)(*(int *)(local_6468 + 4) + 0x8f5c);
              *(undefined4 *)(local_6468 + 0x110) =
                   *(undefined4 *)(*(int *)(local_6468 + 4) + 0x8f58);
              *(undefined4 *)(local_6468 + 0x114) = uVar2;
              if (param_1 == 0x231d) {
                *(undefined4 *)(local_6468 + 0xac) = 0;
                *(undefined4 *)(local_6468 + 0xe0) = 0;
                *(undefined4 *)(local_6468 + 200) = 0;
                FUN_00630a10(0,0x8003);
              }
            }
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = local_8 & 0xffffff00;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
          else {
            *(undefined4 *)(local_6468 + 0xac) = 0;
            *(int *)(local_6468 + 200) = local_646c;
            FUN_00455870(*(undefined4 *)(local_6468 + 200),param_2,param_3,param_4,param_5);
            FUN_00447b90(local_6490,2,*(undefined4 *)(local_6468 + 4),
                         *(undefined4 *)(local_6468 + 200),1,1);
            if (*(int *)(local_6468 + 0xb0) != 0) {
              uVar2 = 2;
              FUN_00404c80(2);
              FUN_004fca20();
              FUN_004117f0(uVar2);
            }
            *(undefined4 *)(local_6468 + 0xac) = 0;
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = local_8 & 0xffffff00;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
        }
        else {
          *(int *)(local_6468 + 0xe0) = local_646c;
          FUN_00455870(*(undefined4 *)(local_6468 + 0xe0),param_2,param_3,param_4,param_5);
          *(undefined4 *)(local_6468 + 0xac) = 9;
          local_8 = local_8 & 0xffffff00;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 1;
        }
      }
      else {
        *(undefined4 *)(local_6468 + 0xac) = 6;
        FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
        FUN_00404c80();
        FUN_0056d7d0();
        puVar3 = (undefined4 *)
                 CMFCCaptionButtonEx::GetRect(*(CMFCCaptionButtonEx **)(local_6468 + 200));
        FUN_004988c0(local_74,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
        iVar1 = FUN_00633640(local_6490,local_6464,*(undefined4 *)(local_6468 + 200),
                             *(undefined4 *)(local_6468 + 0xe8),*(undefined4 *)(local_6468 + 0xec),
                             *(undefined4 *)(local_6468 + 0xf0),*(undefined4 *)(local_6468 + 0xf4));
        if (iVar1 == 0) {
          if (*(int *)(local_6468 + 0xb0) != 0) {
            uVar2 = 3;
            FUN_00404c80(3);
            FUN_004fca20();
            FUN_004117f0(uVar2);
          }
        }
        else {
          if (*(int *)(local_6468 + 0xb0) != 0) {
            uVar2 = 4;
            FUN_00404c80(4);
            FUN_004fca20();
            FUN_004117f0(uVar2);
          }
          FUN_004508b0(0xc,local_6490,*(undefined4 *)(local_6468 + 4),
                       *(undefined4 *)(local_6468 + 0xd0),*(undefined4 *)(local_6468 + 0xd4),
                       *(undefined4 *)(local_6468 + 0xd8),*(undefined4 *)(local_6468 + 0xdc),0);
        }
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
    }
    else {
      FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 1;
    }
  }
  else {
    FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 1;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiAuto[13] */
/* 00631bb0  FUN_00631bb0  308 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00631bb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x31] == 0) {
    if ((in_ECX[0x32] == 0) || (in_ECX[0x2b] != 6)) {
      if (in_ECX[0x2b] == 5) {
        in_ECX[0x2b] = 0;
        FUN_00630a10(1,0x8005);
        uVar1 = 0;
      }
      else {
        uVar1 = (**(code **)(*in_ECX + 0x2c))(param_1,param_2,param_3,param_4,param_5);
      }
    }
    else {
      FUN_004988c0(local_18,in_ECX[0x3a],in_ECX[0x3b],in_ECX[0x3c],in_ECX[0x3d]);
      uVar1 = 1;
    }
  }
  else if (in_ECX[0x30] == 0) {
    uVar1 = (**(code **)(*(int *)in_ECX[0x31] + 0x34))(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CZukeiAuto[11] */
/* 00631cf0  FUN_00631cf0  2532 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00631cf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined1 local_647c [20];
  int local_6468;
  undefined4 local_6464;
  int *local_6460;
  int *local_645c;
  int local_6458;
  undefined1 local_6454 [25380];
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined1 local_84 [16];
  undefined1 local_74 [32];
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
  puStack_c = &LAB_009376fb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6464 = FUN_0040c0e0(local_14);
  iVar1 = FUN_004146c0();
  if (iVar1 == 0) {
    FUN_004d2660();
  }
  if (*(int *)(local_6458 + 0xc4) == 0) {
    *(undefined4 *)(*(int *)(local_6458 + 4) + 0x8560) = 0;
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_6458 + 4));
    local_8._0_1_ = 1;
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    local_18 = param_5;
    *(undefined4 *)(*(int *)(local_6458 + 4) + 0x8f34) = 1;
    local_130 = 1;
    local_12c = 1;
    local_6468 = FUN_00451f30(*(undefined4 *)(local_6458 + 4),&local_24);
    local_130 = 0;
    if ((*(int *)(local_6458 + 200) == 0) || (*(int *)(local_6458 + 0xac) != 10)) {
      if (local_6468 == 1) {
        if ((*(int *)(local_6458 + 200) == 0) || (*(int *)(local_6458 + 0xac) != 6)) {
          if (*(int *)(local_6458 + 200) == 0) {
            if (*(int *)(local_6458 + 0xac) == 5) {
              *(undefined4 *)(local_6458 + 0xac) = 0;
              FUN_00630a10(1,0x8005);
            }
            else {
              *(undefined4 *)(local_6458 + 0xac) = 5;
              *(undefined4 *)(local_6458 + 0x10c) = 1;
              uVar2 = *(undefined4 *)(*(int *)(local_6458 + 4) + 0x8f5c);
              *(undefined4 *)(local_6458 + 0x110) =
                   *(undefined4 *)(*(int *)(local_6458 + 4) + 0x8f58);
              *(undefined4 *)(local_6458 + 0x114) = uVar2;
            }
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
          else {
            *(undefined4 *)(local_6458 + 0xac) = 6;
            FUN_00451b20(*(undefined4 *)(local_6458 + 4),&local_24,0);
            FUN_00454cb0(1,*(undefined4 *)(local_6458 + 4),local_24,local_20,local_1c,local_18);
            FUN_004988c0(local_54,local_24,local_20,local_1c,local_18);
            FUN_00404c80();
            FUN_0056d7d0();
            puVar3 = (undefined4 *)
                     CMFCCaptionButtonEx::GetRect(*(CMFCCaptionButtonEx **)(local_6458 + 200));
            FUN_004988c0(local_74,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
            iVar1 = FUN_00633640(local_647c,local_6454,*(undefined4 *)(local_6458 + 200),
                                 *(undefined4 *)(local_6458 + 0xe8),
                                 *(undefined4 *)(local_6458 + 0xec),
                                 *(undefined4 *)(local_6458 + 0xf0),
                                 *(undefined4 *)(local_6458 + 0xf4));
            if (iVar1 == 0) {
              if (*(int *)(local_6458 + 0xb0) != 0) {
                uVar2 = 3;
                FUN_00404c80(3);
                FUN_004fca20();
                FUN_004117f0(uVar2);
              }
            }
            else {
              if (*(int *)(local_6458 + 0xb0) != 0) {
                uVar2 = 4;
                FUN_00404c80(4);
                FUN_004fca20();
                FUN_004117f0(uVar2);
              }
              FUN_004508b0(0xc,local_647c,*(undefined4 *)(local_6458 + 4),
                           *(undefined4 *)(local_6458 + 0xd0),*(undefined4 *)(local_6458 + 0xd4),
                           *(undefined4 *)(local_6458 + 0xd8),*(undefined4 *)(local_6458 + 0xdc),0);
            }
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
        }
        else {
          FUN_00451b20(*(undefined4 *)(local_6458 + 4),&local_24,0);
          FUN_00454cb0(1,*(undefined4 *)(local_6458 + 4),local_24,local_20,local_1c,local_18);
          FUN_004988c0(local_44,local_24,local_20,local_1c,local_18);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 1;
        }
      }
      else {
        *(undefined4 *)(*(int *)(local_6458 + 4) + 0x8f34) = 1;
        local_645c = (int *)0x0;
        local_130 = 1;
        local_12c = 1;
        local_128 = 1;
        local_124 = 1;
        iVar1 = FUN_0044a270(3,*(undefined4 *)(local_6458 + 4),&local_24,&local_645c,1);
        if (iVar1 == 0) {
          if (*(int *)(local_6458 + 200) == 0) {
            FUN_00630a10(0,0x8004);
          }
          else {
            uVar4 = 0;
            uVar2 = 0;
            puVar3 = (undefined4 *)FUN_0041c8d0(9999,9999);
            FUN_005168b0(0x1451,*puVar3,puVar3[1],uVar2,uVar4);
          }
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
        else if ((*(int *)(local_6458 + 200) == 0) || (local_645c != *(int **)(local_6458 + 200))) {
          if (*(int *)(local_6458 + 0x108) != 0) {
            local_6460 = *(int **)(local_6458 + 0x108);
            if (local_6460 != (int *)0x0) {
              (**(code **)(*local_6460 + 4))(1);
            }
            *(undefined4 *)(local_6458 + 0x108) = 0;
          }
          if (local_645c != (int *)0x0) {
            uVar2 = (**(code **)(*local_645c + 0x14))();
            *(undefined4 *)(local_6458 + 0x108) = uVar2;
          }
          if ((*(int *)(local_6458 + 200) == 0) || (local_645c == (int *)0x0)) {
            FUN_00630a10(0,0x8020);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 0;
          }
          else {
            *(undefined4 *)(local_6458 + 0xe0) = *(undefined4 *)(local_6458 + 0x108);
            FUN_00455870(*(undefined4 *)(local_6458 + 0xe0),local_24,local_20,local_1c,local_18);
            *(undefined4 *)(local_6458 + 0xac) = 8;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar2 = 1;
          }
        }
        else {
          if (*(int *)(local_6458 + 0xac) == 6) {
            *(undefined4 *)(local_6458 + 0xac) = 0xb;
            FUN_004988c0(local_84,local_24,local_20,local_1c,local_18);
          }
          else {
            *(undefined4 *)(local_6458 + 0xac) = 7;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 1;
        }
      }
    }
    else if (local_6468 == 1) {
      FUN_004988c0(local_34,local_24,local_20,local_1c,local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 1;
    }
    else {
      uVar4 = 0;
      uVar2 = 0;
      puVar3 = (undefined4 *)FUN_0041c8d0(9999,9999);
      FUN_005168b0(0x14cc,*puVar3,puVar3[1],uVar2,uVar4);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 0;
    }
  }
  else if (*(int *)(local_6458 + 0xc0) == 0) {
    uVar2 = (**(code **)(**(int **)(local_6458 + 0xc4) + 0x2c))
                      (param_1,param_2,param_3,param_4,param_5);
  }
  else {
    FUN_0062a750(1,param_2,param_3,param_4,param_5);
    uVar2 = 0;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiAuto[4] */
/* 006326e0  FUN_006326e0  622 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006326e0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_6414 [20];
  undefined4 local_6400;
  undefined4 local_63fc;
  int local_63f8;
  int local_63f4;
  int *local_63f0;
  int *local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093774b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined8 *)(*(int *)(in_ECX + 4) + 0x17c0) = *(undefined8 *)(*(int *)(in_ECX + 4) + 0x17c8);
  local_63e8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044dd90(local_6414,*(undefined4 *)(local_63e8 + 4));
  if (*(int *)(local_63e8 + 0xc4) == 0) {
    FUN_0044c830(local_6414,*(undefined4 *)(local_63e8 + 4));
  }
  else {
    (**(code **)(**(int **)(local_63e8 + 0xc4) + 0x10))();
    iVar1 = FUN_0079d98a(&PTR_s_CZukeiSentaku_0097a56c);
    if (iVar1 == 0) {
      FUN_0044c830(local_6414,*(undefined4 *)(local_63e8 + 4));
    }
    local_63ec = *(int **)(local_63e8 + 0xc4);
    if (local_63ec == (int *)0x0) {
      local_63fc = 0;
    }
    else {
      local_63fc = (**(code **)(*local_63ec + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0xc4) = 0;
  }
  local_63f4 = *(int *)(local_63e8 + 4);
  if (local_63f4 == 0) {
    local_63f8 = 0;
  }
  else {
    local_63f8 = local_63f4 + 0x88;
  }
  FUN_00454890(local_63f8);
  FUN_00454830(*(undefined4 *)(local_63e8 + 4));
  if (*(int *)(local_63e8 + 0x108) != 0) {
    local_63f0 = *(int **)(local_63e8 + 0x108);
    if (local_63f0 == (int *)0x0) {
      local_6400 = 0;
    }
    else {
      local_6400 = (**(code **)(*local_63f0 + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0x108) = 0;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiAuto[3] */
/* 00632950  FUN_00632950  2103 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00632950(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined8 uVar3;
  double local_66a0;
  undefined1 local_6698 [20];
  undefined4 local_6684;
  int local_6680;
  undefined4 local_642c;
  undefined1 local_6414 [25552];
  undefined1 local_44 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009377d2;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6680 = in_ECX;
  if (*(int *)(in_ECX + 0xc4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc4) + 0xc))(local_14);
    if (*(int *)(local_6680 + 0xc4) == 0) {
      FUN_00633190();
    }
    else {
      if (*(int *)(local_6680 + 0xbc) != 0) {
        ExceptionList = local_10;
        return;
      }
      iVar1 = FUN_0079d98a();
      if (iVar1 != 0) {
        ExceptionList = local_10;
        return;
      }
      if (*(int *)(local_6680 + 0xb8) == 0x8020) {
        if (*(int *)(*(int *)(local_6680 + 4) + 0x8578) != 0) {
          *(undefined4 *)(local_6680 + 0xb8) = 0;
        }
        FUN_00633190();
      }
      else {
        FUN_00633190();
      }
    }
  }
  FUN_0079dea2();
  local_8 = 0;
  FUN_0040c0e0();
  FUN_00446aa0();
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6698,*(undefined4 *)(local_6680 + 4));
  FUN_0044c830(local_6698,*(undefined4 *)(local_6680 + 4));
  if ((*(int *)(local_6680 + 200) != 0) && (*(int *)(local_6680 + 0xac) == 10)) {
    FUN_00464040();
    local_8._0_1_ = 2;
    local_66a0 = 0.0;
    if (*(int *)(*(int *)(local_6680 + 4) + 0x17d8) == 0x8017) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6680 + 4) + 0x862c)) {
        FUN_00404c80();
        FUN_004fca20();
        fVar2 = (float10)FUN_004cad70();
        local_66a0 = (double)fVar2;
        uVar3 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_004ca970(uVar3);
      }
    }
    FUN_00478c70(*(undefined4 *)(local_6680 + 4),local_6414,local_6698,
                 *(undefined4 *)(local_6680 + 200),*(undefined4 *)(local_6680 + 0xe8),
                 *(undefined4 *)(local_6680 + 0xec),*(undefined4 *)(local_6680 + 0xf0),
                 *(undefined4 *)(local_6680 + 0xf4),1,local_66a0);
    local_8._0_1_ = 1;
    FUN_004640a0();
  }
  if (((*(int *)(local_6680 + 200) != 0) && (*(int *)(local_6680 + 0xe0) != 0)) &&
     (*(int *)(local_6680 + 0xac) == 8)) {
    iVar1 = FUN_00633a60();
    if (iVar1 != 0) goto LAB_006330f9;
    FUN_00464040();
    local_8._0_1_ = 3;
    FUN_0046e550(*(undefined4 *)(local_6680 + 4),*(undefined4 *)(local_6680 + 0xe0),
                 *(undefined4 *)(local_6680 + 200));
    local_8._0_1_ = 1;
    FUN_004640a0();
  }
  if (((*(int *)(local_6680 + 200) != 0) && (*(int *)(local_6680 + 0xe0) != 0)) &&
     (*(int *)(local_6680 + 0xac) == 9)) {
    iVar1 = FUN_00633a60();
    if ((iVar1 != 0) || (iVar1 = FUN_00633a60(), iVar1 != 0)) goto LAB_006330f9;
    FUN_00464040();
    local_8._0_1_ = 4;
    FUN_0046abe0(*(undefined4 *)(local_6680 + 4),*(undefined4 *)(local_6680 + 200),
                 *(undefined4 *)(local_6680 + 0xe0));
    local_8._0_1_ = 1;
    FUN_004640a0();
  }
  if ((*(int *)(local_6680 + 200) != 0) && (*(int *)(local_6680 + 0xac) == 7)) {
    FUN_0044b2c0(local_6698,*(undefined4 *)(local_6680 + 4),*(undefined4 *)(local_6680 + 200),1);
  }
  if ((*(int *)(local_6680 + 200) != 0) && (*(int *)(local_6680 + 0xac) == 6)) {
    iVar1 = FUN_00633640(local_6698,local_6414,*(undefined4 *)(local_6680 + 200),
                         *(undefined4 *)(local_6680 + 0xe8),*(undefined4 *)(local_6680 + 0xec),
                         *(undefined4 *)(local_6680 + 0xf0),*(undefined4 *)(local_6680 + 0xf4));
    if (iVar1 == 0) {
      FUN_00464040();
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_00470200(*(undefined4 *)(local_6680 + 4),*(undefined4 *)(local_6680 + 200),
                   *(undefined4 *)(local_6680 + 0xe8),*(undefined4 *)(local_6680 + 0xec),
                   *(undefined4 *)(local_6680 + 0xf0),*(undefined4 *)(local_6680 + 0xf4),
                   *(undefined4 *)(local_6680 + 0xf8),*(undefined4 *)(local_6680 + 0xfc),
                   *(undefined4 *)(local_6680 + 0x100),*(undefined4 *)(local_6680 + 0x104));
      iVar1 = FUN_00436970(*(undefined4 *)(local_6680 + 0xe8),*(undefined4 *)(local_6680 + 0xec),
                           *(undefined4 *)(local_6680 + 0xf0),*(undefined4 *)(local_6680 + 0xf4),
                           *(undefined4 *)(local_6680 + 0xf8),*(undefined4 *)(local_6680 + 0xfc),
                           *(undefined4 *)(local_6680 + 0x100),*(undefined4 *)(local_6680 + 0x104));
      if (iVar1 != 0) {
        FUN_005168b0(0x2737,*(undefined4 *)(*(int *)(local_6680 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6680 + 4) + 0x8f28),0,0);
      }
      local_8._0_1_ = 1;
      FUN_004640a0();
    }
    else {
      FUN_0044de00(local_6698,*(undefined4 *)(local_6680 + 4));
      local_34 = *(undefined4 *)(local_6680 + 0xd0);
      local_30 = *(undefined4 *)(local_6680 + 0xd4);
      local_2c = *(undefined4 *)(local_6680 + 0xd8);
      local_28 = *(undefined4 *)(local_6680 + 0xdc);
      local_24 = *(undefined4 *)(local_6680 + 0xf8);
      local_20 = *(undefined4 *)(local_6680 + 0xfc);
      local_1c = *(undefined4 *)(local_6680 + 0x100);
      local_18 = *(undefined4 *)(local_6680 + 0x104);
      iVar1 = FUN_0045b6c0(0,*(undefined4 *)(local_6680 + 200),&local_24);
      if (iVar1 != 0) {
        FUN_0044cfb0(local_6698,*(undefined4 *)(local_6680 + 4),1,*(undefined4 *)(local_6680 + 200),
                     local_24,local_20,local_1c,local_18,local_34,local_30,local_2c,local_28);
      }
    }
  }
  if ((*(int *)(local_6680 + 200) != 0) && (*(int *)(local_6680 + 0xac) == 0xb)) {
    local_6684 = DAT_00a0cc3c;
    DAT_00a0cc3c = 0;
    FUN_0070c300();
    local_8._0_1_ = 6;
    local_642c = *(undefined4 *)(local_6680 + 200);
    FUN_004988c0(local_44,*(undefined4 *)(local_6680 + 0xf8),*(undefined4 *)(local_6680 + 0xfc),
                 *(undefined4 *)(local_6680 + 0x100),*(undefined4 *)(local_6680 + 0x104));
    FUN_00712f00(local_6414,local_6698);
    DAT_00a0cc3c = local_6684;
    local_8._0_1_ = 1;
    FUN_0070c780();
  }
LAB_006330f9:
  *(undefined4 *)(*(int *)(local_6680 + 4) + 0x8560) = 0;
  FUN_00633190();
  *(undefined4 *)(local_6680 + 200) = 0;
  *(undefined4 *)(local_6680 + 0xe0) = 0;
  FUN_00404900();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiAuto[14] */
/* 006335f0  FUN_006335f0  74 bytes, 0 callers */

undefined4 FUN_006335f0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc4) == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(in_ECX + 0xc0) == 0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0x38))(param_1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



