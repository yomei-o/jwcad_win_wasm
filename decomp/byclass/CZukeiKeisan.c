/* CZukeiKeisan -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiKeisan[1] */
/* 0069ee20  FUN_0069ee20  68 bytes, 0 callers */

undefined4 FUN_0069ee20(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0069ee00();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xc4e0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiKeisan[6] */
/* 0069f410  FUN_0069f410  1334 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0069f410(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  undefined1 local_677c [28];
  undefined4 local_6760;
  undefined4 local_675c;
  undefined4 local_6758;
  undefined4 local_6750;
  undefined4 local_6748;
  undefined4 local_6740;
  undefined4 local_6738;
  undefined4 local_6734;
  int local_6730;
  undefined2 uStack_33c;
  undefined1 local_1a8 [404];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bec6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  local_6730 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6730 + 4));
  local_8._0_1_ = 1;
  FUN_00408a60();
  FUN_00408a60();
  *(undefined2 *)(local_6730 + 0xc01c) = 0;
  uStack_33c = 0;
  FUN_0044dd90(local_677c,*(undefined4 *)(local_6730 + 4));
  if (*(int *)(local_6730 + 0x214) == 0) {
    if (*(int *)(local_6730 + 0x218) == 0) {
      if (*(int *)(local_6730 + 0x1fc) == 0) {
        if (*(int *)(local_6730 + 0x1f8) == 0) {
          **(undefined4 **)(local_6730 + 8) = 8;
          *(undefined2 *)(*(int *)(local_6730 + 8) + 0x1c) = 0;
          if (*(int *)(local_6730 + 0x20c) != 0x37) {
            if (*(int *)(local_6730 + 0x204) == 1) {
              uVar1 = 0x62;
              local_6740 = FUN_005977f0(0x1537);
              uVar1 = FUN_00404920(uVar1);
              FUN_00408870(*(int *)(local_6730 + 8) + 0x1c,uVar1);
              FUN_00404770();
            }
            if (*(int *)(local_6730 + 0x204) == 2) {
              uVar1 = 0x62;
              local_6748 = FUN_005977f0(0x1538);
              uVar1 = FUN_00404920(uVar1);
              FUN_00408870(*(int *)(local_6730 + 8) + 0x1c,uVar1);
              FUN_00404770();
            }
          }
          if (*(int *)(*(int *)(local_6730 + 8) + 4) == 1) {
            local_6750 = FUN_005977f0(0x1604);
            uVar1 = FUN_00404920();
            FUN_00408850(*(int *)(local_6730 + 8) + 0x1c,uVar1);
            FUN_00404770();
          }
          FUN_0040ac80(param_1);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          if (*(int *)(local_6730 + 0x204) != *(int *)(local_6730 + 0x208)) {
            *(undefined4 *)(local_6730 + 0x208) = *(undefined4 *)(local_6730 + 0x204);
            FUN_006a0b90();
            FUN_006a0c10();
          }
          *(undefined2 *)(local_6730 + 0xc01c) = 0;
          if (*(int *)(local_6730 + 0x20c) == 0x37) {
            local_675c = FUN_005977f0(7000);
            local_8._0_1_ = 2;
            local_6758 = local_675c;
            uVar1 = FUN_00404920();
            iVar2 = local_6730 + 0xbe88;
            local_6760 = FUN_005977f0(0x1b5e);
            uVar1 = FUN_00404920(iVar2,uVar1);
            FUN_0059f750(local_6730 + 0xc01c,L"  (%d)%s %s %s",*(undefined4 *)(local_6730 + 0x21c),
                         uVar1);
            FUN_00404770();
            local_8._0_1_ = 1;
            FUN_00404770();
            FUN_004efbb0(0x1539,local_6730 + 0xc01c,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
          else {
            FUN_004efbb0(0x1539,0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
          }
        }
      }
      else {
        FUN_004efbb0(0x1603,0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      local_6734 = 0x272c;
      if (*(int *)(local_6730 + 0x218) == 2) {
        local_6734 = 0x272d;
      }
      local_6738 = FUN_005977f0(0x160a);
      uVar1 = FUN_00404920();
      FUN_0059f750(local_1a8,L"  %s",uVar1);
      FUN_00404770();
      FUN_004efbb0(local_6734,local_1a8,0);
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
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKeisan[16] */
/* 0069f950  FUN_0069f950  884 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0069f950(void)

{
  int in_ECX;
  undefined1 local_6410 [20];
  undefined4 local_63fc;
  undefined4 local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
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
  if (*(int *)(in_ECX + 0x214) == 0) {
    local_63e8 = in_ECX;
    if (*(int *)(in_ECX + 0x218) == 0) {
      if (*(int *)(in_ECX + 0x1fc) == 0) {
        if (*(int *)(in_ECX + 0xc4d8) < 1) {
          FUN_00446aa0(local_14);
          local_8 = 0;
          FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
          local_8._0_1_ = 1;
          if (*(int *)(local_63e8 + 0x1f8) == 0) {
            FUN_0044c830(local_6410,*(undefined4 *)(local_63e8 + 4));
            if (*(int *)(*(int *)(local_63e8 + 8) + 4) == 0) {
              if (*(int *)(local_63e8 + 0x204) == 2) {
                *(undefined4 *)(local_63e8 + 0x204) = 1;
                *(undefined4 *)(*(int *)(local_63e8 + 8) + 4) = 0;
                FUN_00404c80();
                FUN_0056d7d0();
                local_63f0 = 1;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                local_63ec = local_63f0;
              }
              else {
                local_63fc = 0;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0079dfff();
                local_8 = 0xffffffff;
                FUN_00447100();
                local_63ec = local_63fc;
              }
            }
            else {
              *(undefined4 *)(*(int *)(local_63e8 + 8) + 4) = 0;
              FUN_00404c80();
              FUN_0056d7d0();
              local_63ec = 1;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
            }
          }
          else {
            FUN_0044c830(local_6410,*(undefined4 *)(local_63e8 + 4));
            if (*(int *)(local_63e8 + 0x204) == 2) {
              *(undefined4 *)(local_63e8 + 0x1f8) = 0;
              *(undefined4 *)(*(int *)(local_63e8 + 8) + 4) = 0;
              FUN_00404c80();
              FUN_0056d7d0();
              local_63f4 = 1;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              local_63ec = local_63f4;
            }
            else {
              *(undefined4 *)(local_63e8 + 0x1f8) = 0;
              local_63f8 = 1;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              local_63ec = local_63f8;
            }
          }
        }
        else {
          *(int *)(in_ECX + 0xc4d8) = *(int *)(in_ECX + 0xc4d8) + -1;
          local_63ec = 0;
        }
      }
      else {
        *(undefined4 *)(in_ECX + 0x1fc) = 0;
        FUN_006a0b90();
        *(undefined4 *)(*(int *)(local_63e8 + 8) + 4) = 1;
        FUN_00404c80();
        FUN_0056d7d0();
        local_63ec = 1;
      }
    }
    else {
      FUN_004fb9f0();
      *(undefined4 *)(local_63e8 + 0x218) = 0;
      local_63ec = 1;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x214) = 0;
    FUN_0069ee70();
    FUN_0069f1f0();
    local_63ec = 1;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiKeisan[0] */
/* 0069fcd0  FUN_0069fcd0  16 bytes, 0 callers */

undefined ** FUN_0069fcd0(void)

{
  return &PTR_s_CZukeiKeisan_00979560;
}




/* vtable slots: CZukeiKeisan[23] */
/* 0069fce0  FUN_0069fce0  120 bytes, 0 callers */

undefined4 FUN_0069fce0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8614)) {
    if (in_ECX[0x85] == 0) {
      if (DAT_00a0cc6c == 0) {
        (**(code **)(*in_ECX + 0x7c))();
      }
      else {
        (**(code **)(*in_ECX + 0x80))();
      }
      FUN_00404c80();
      FUN_0056d7d0();
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiKeisan[46] */
/* 0069fd60  FUN_0069fd60  846 bytes, 0 callers */

undefined4
FUN_0069fd60(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int *in_ECX;
  bool bVar2;
  undefined4 local_14;
  
  if (DAT_00a0c7c0 == 0) {
    local_14 = 0;
    if ((in_ECX[0x85] == 0) && (*(int *)(in_ECX[1] + 0x9078) == 0)) {
      bVar2 = in_ECX[0x7f] != 0;
      if ((in_ECX[0x83] == 0x37) && (in_ECX[0x7e] == 1)) {
        bVar2 = true;
      }
      if (param_2 == 4) {
        local_14 = FUN_006a3290(0,param_3);
      }
      else {
        if (param_2 == 5) {
          if (bVar2) {
            uVar1 = FUN_006a3290(1,param_3);
            return uVar1;
          }
        }
        else if ((param_2 == 6) && (bVar2)) {
          uVar1 = FUN_006a3290(2,param_3);
          return uVar1;
        }
        local_14 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else if ((in_ECX[0x85] == 0) && (*(int *)(in_ECX[1] + 0x9078) != 0)) {
      switch(param_2) {
      case 1:
      case 0xc:
        if (param_3 == 1) {
          FUN_005168b0(0x1530,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 100))();
        }
        break;
      case 2:
        if (param_3 == 1) {
          FUN_005168b0(0x1531,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x68))();
        }
        break;
      case 3:
        if (param_3 == 1) {
          FUN_005168b0(0x1532,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x6c))();
        }
        break;
      case 4:
        if (param_3 == 1) {
          FUN_005168b0(0x1533,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x70))();
        }
        break;
      case 5:
        if (param_3 == 1) {
          FUN_005168b0(0x1534,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x74))();
        }
        break;
      default:
        local_14 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      local_14 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_14 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_14;
}




/* vtable slots: CZukeiKeisan[47], CZukeiSokutei[47] */
/* 006a00e0  FUN_006a00e0  120 bytes, 0 callers */

void FUN_006a00e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  if (DAT_00a0c7c0 == 0) {
    FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}




/* vtable slots: CZukeiKeisan[25] */
/* 006a0160  FUN_006a0160  258 bytes, 0 callers */

void FUN_006a0160(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x214) == 0) {
    *(undefined4 *)(in_ECX + 0x20c) = 0xb;
    *(undefined4 *)(in_ECX + 0x210) = 0;
    *(undefined4 *)(in_ECX + 0x214) = 0;
    FUN_0069f1f0();
    FUN_004fb9f0();
    *(undefined4 *)(in_ECX + 0x218) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xe0) = *(undefined4 *)(in_ECX + 0x20c);
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
  return;
}




/* vtable slots: CZukeiKeisan[26] */
/* 006a0270  FUN_006a0270  213 bytes, 0 callers */

void FUN_006a0270(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x214) == 0) {
    *(undefined4 *)(in_ECX + 0x20c) = 0x16;
    *(undefined4 *)(in_ECX + 0x210) = 0;
    *(undefined4 *)(in_ECX + 0x214) = 0;
    FUN_0069f1f0();
    FUN_004fb9f0();
    *(undefined4 *)(in_ECX + 0x218) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xe0) = *(undefined4 *)(in_ECX + 0x20c);
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
  return;
}




/* vtable slots: CZukeiKeisan[27] */
/* 006a0350  FUN_006a0350  213 bytes, 0 callers */

void FUN_006a0350(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x214) == 0) {
    *(undefined4 *)(in_ECX + 0x20c) = 0x21;
    *(undefined4 *)(in_ECX + 0x210) = 0;
    *(undefined4 *)(in_ECX + 0x214) = 0;
    FUN_0069f1f0();
    FUN_004fb9f0();
    *(undefined4 *)(in_ECX + 0x218) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xe0) = *(undefined4 *)(in_ECX + 0x20c);
    }
  }
  else {
    local_c = DAT_00a0be64 + 1;
    if (1 < local_c) {
      local_c = 0;
    }
    DAT_00a0be64 = local_c;
    FUN_006a1a00();
  }
  return;
}




/* vtable slots: CZukeiKeisan[28] */
/* 006a0430  FUN_006a0430  213 bytes, 0 callers */

void FUN_006a0430(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x214) == 0) {
    *(undefined4 *)(in_ECX + 0x20c) = 0x2c;
    *(undefined4 *)(in_ECX + 0x210) = 0;
    *(undefined4 *)(in_ECX + 0x214) = 0;
    FUN_0069f1f0();
    FUN_004fb9f0();
    *(undefined4 *)(in_ECX + 0x218) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xe0) = *(undefined4 *)(in_ECX + 0x20c);
    }
  }
  else {
    local_c = DAT_00a0be68 + 1;
    if (2 < local_c) {
      local_c = 0;
    }
    DAT_00a0be68 = local_c;
    FUN_006a1b50();
  }
  return;
}




/* vtable slots: CZukeiKeisan[29] */
/* 006a0510  FUN_006a0510  203 bytes, 0 callers */

void FUN_006a0510(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x214) == 0) {
    *(undefined4 *)(in_ECX + 0x20c) = 0x37;
    *(undefined4 *)(in_ECX + 0x210) = 0;
    *(undefined4 *)(in_ECX + 0x214) = 0;
    FUN_0069f1f0();
    FUN_004fb9f0();
    *(undefined4 *)(in_ECX + 0x218) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xe0) = *(undefined4 *)(in_ECX + 0x20c);
    }
  }
  else {
    DAT_00a0bfa0 = (uint)(DAT_00a0bfa0 == 0);
    FUN_006a1c80();
  }
  return;
}




/* vtable slots: CZukeiKeisan[30] */
/* 006a05e0  FUN_006a05e0  642 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006a05e0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  bool bVar3;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093365b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x214) != 0) {
    *(undefined4 *)(in_ECX + 0x214) = 0;
    FUN_0069ee70(local_14);
    if (*(int *)(in_ECX + 0x20c) != 0x37) {
      FUN_00404c80();
      FUN_0056d7d0();
      ExceptionList = local_10;
      return;
    }
    *(undefined4 *)(in_ECX + 0x1fc) = 1;
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2();
  local_8._0_1_ = 1;
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    *(undefined4 *)(in_ECX + 0x1fc) = 0;
    bVar3 = false;
    if (*(int *)(in_ECX + 0x20c) == 0x37) {
      uVar2 = FUN_006a3590();
      *(undefined4 *)(in_ECX + 0x21c) = uVar2;
      if (0 < *(int *)(in_ECX + 0x21c)) {
        *(undefined4 *)(in_ECX + 0x1f8) = 1;
        uVar2 = FUN_006a3590();
        *(undefined4 *)(in_ECX + 0x21c) = uVar2;
        FUN_006a1f20(local_63e4,*(undefined8 *)(in_ECX + 0x268));
        bVar3 = true;
      }
    }
    else if (*(int *)(in_ECX + 0x204) == 1) {
      iVar1 = FUN_006a2c20();
      bVar3 = iVar1 != 0;
      if (bVar3) {
        *(undefined4 *)(in_ECX + 0x204) = 2;
      }
    }
    else {
      iVar1 = FUN_006a2dc0();
      if (iVar1 != 0) {
        *(undefined4 *)(in_ECX + 0x1f8) = 1;
        bVar3 = true;
      }
    }
    FUN_006a0b90();
    if (!bVar3) {
      FUN_005168b0(0x1605,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
    }
  }
  FUN_004fb9f0();
  *(undefined4 *)(in_ECX + 0x218) = 0;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKeisan[31] */
/* 006a0870  FUN_006a0870  240 bytes, 0 callers */

void FUN_006a0870(void)

{
  int *in_ECX;
  int local_c;
  
  if (in_ECX[0x7f] == 0) {
    local_c = DAT_00a0be58 + 1;
    if (4 < local_c) {
      local_c = -1;
    }
    DAT_00a0be58 = local_c;
    FUN_006a0da0();
    FUN_00404c80();
    FUN_0056d7d0();
    in_ECX[0x86] = 0;
    if (in_ECX[0x83] == 0x37) {
      in_ECX[0x7f] = 1;
      (**(code **)(*in_ECX + 0x78))();
    }
  }
  else {
    FUN_004fb9f0();
    if (in_ECX[0x86] == 1) {
      in_ECX[0x86] = 0;
    }
    else {
      in_ECX[0x86] = 1;
      FUN_005168b0(0x272c,*(undefined4 *)(in_ECX[1] + 0x8f24),*(undefined4 *)(in_ECX[1] + 0x8f28),0,
                   0);
    }
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiKeisan[32] */
/* 006a0960  FUN_006a0960  190 bytes, 0 callers */

void FUN_006a0960(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    *(undefined4 *)(in_ECX + 0x1f8) = 0;
    FUN_0069f1f0();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
    FUN_00404c80();
    FUN_0056d200();
    *(undefined4 *)(in_ECX + 0x218) = 0;
  }
  else {
    FUN_004fb9f0();
    if (*(int *)(in_ECX + 0x218) == 2) {
      *(undefined4 *)(in_ECX + 0x218) = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 0x218) = 2;
      FUN_005168b0(0x272d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
    }
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiKeisan[33] */
/* 006a0a20  FUN_006a0a20  55 bytes, 0 callers */

void FUN_006a0a20(void)

{
  int in_ECX;
  
  FUN_004fb9f0();
  *(undefined4 *)(in_ECX + 0x218) = 0;
  FUN_006a1630();
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiKeisan[9] */
/* 006a0f80  FUN_006a0f80  1154 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006a0f80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_6448 [20];
  undefined4 local_6434;
  undefined4 local_6430;
  undefined4 local_642c;
  int local_6428;
  undefined4 local_6424;
  undefined4 local_6420;
  int local_641c;
  int local_6418;
  undefined1 local_6414 [25412];
  undefined4 local_d0;
  undefined1 local_44 [32];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bfab;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8._0_1_ = 1;
  if (*(int *)(local_6418 + 0x214) == 0) {
    if (*(int *)(local_6418 + 0x218) == 0) {
      if (*(int *)(local_6418 + 0x1fc) == 0) {
        if (*(int *)(local_6418 + 0x1f8) == 0) {
          **(undefined4 **)(local_6418 + 8) = 8;
          iVar1 = FUN_0040dbb0(param_1,param_2,param_3,param_4,param_5);
          if (iVar1 == 0) {
            *(undefined4 *)(local_6418 + 0xc4d8) = 0;
            if (*(int *)(local_6418 + 0x20c) != 0x37) {
              FUN_0044c830(local_6448,*(undefined4 *)(local_6418 + 4));
            }
          }
          else {
            *(undefined4 *)(local_6418 + 0x1fc) = 1;
            FUN_006a0b90();
          }
          puVar2 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
          FUN_00517640(*puVar2,puVar2[1],puVar2[2],puVar2[3]);
          FUN_00404c80();
          FUN_0056d7d0();
          local_6430 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6420 = local_6430;
        }
        else {
          *(int *)(local_6418 + 0xc4d8) = *(int *)(local_6418 + 0xc4d8) + 1;
          if (*(int *)(local_6418 + 0x20c) == 0x37) {
            FUN_006a2f00(local_6414,local_6448,local_6418 + 0xbe88,&param_2);
            *(undefined4 *)(*(int *)(local_6418 + 4) + 0x8578) = 1;
            FUN_00404c80();
            FUN_0056d200();
          }
          else {
            FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
            FUN_006a1fb0();
          }
          local_6434 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6420 = local_6434;
        }
      }
      else {
        local_d0 = 1;
        iVar1 = FUN_004500e0(1,*(undefined4 *)(local_6418 + 4),&param_2,&local_6428,0);
        if (iVar1 != 0) {
          local_641c = local_6428;
          iVar1 = FUN_00447b90(local_6448,1,*(undefined4 *)(local_6418 + 4),local_6428,1,1);
          if (iVar1 == 0) {
            *(ushort *)(local_641c + 0x44) = *(ushort *)(local_641c + 0x44) & 0xfffd;
          }
          else {
            *(ushort *)(local_641c + 0x44) = *(ushort *)(local_641c + 0x44) | 2;
          }
        }
        FUN_004efbb0();
        local_642c = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6420 = local_642c;
      }
    }
    else {
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      FUN_006a3290(*(undefined4 *)(local_6418 + 0x218),2);
      *(undefined4 *)(local_6418 + 0x218) = 0;
      local_6424 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6420 = local_6424;
    }
  }
  else {
    local_6420 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_6420;
}




/* vtable slots: CZukeiKeisan[11] */
/* 006a1410  FUN_006a1410  541 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006a1410(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938dc0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x85] == 0) {
    if (in_ECX[0x86] == 0) {
      if (in_ECX[0x7f] == 0) {
        if (in_ECX[0x7e] == 0) {
          (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
          (**(code **)(*in_ECX + 0x78))();
          uVar1 = 0;
        }
        else {
          FUN_00446aa0(local_14);
          local_8 = 0;
          local_24 = param_2;
          local_20 = param_3;
          local_1c = param_4;
          local_18 = param_5;
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
        (**(code **)(*in_ECX + 0x78))();
        uVar1 = 0;
      }
    }
    else {
      FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
      FUN_006a3290(in_ECX[0x86],2);
      in_ECX[0x86] = 0;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiKeisan[3] */
/* 006a1e60  FUN_006a1e60  182 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006a1e60(void)

{
  uint uVar1;
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
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  FUN_00446aa0(uVar1);
  local_8._0_1_ = 1;
  FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



