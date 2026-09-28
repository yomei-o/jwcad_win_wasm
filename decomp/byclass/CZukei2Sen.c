/* CZukei2Sen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukei2Sen[1] */
/* 00623660  FUN_00623660  68 bytes, 0 callers */

undefined4 FUN_00623660(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00623590();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xe6f00);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukei2Sen[6] */
/* 006236b0  FUN_006236b0  2699 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006236b0(undefined4 *param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  double local_6428;
  double local_6420;
  double local_6418;
  undefined1 local_6410 [20];
  uint local_63fc;
  int *local_63f8;
  undefined1 local_63f4 [25552];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936f0b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8ebc) = 0;
  local_63f8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0040c0e0();
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_005baf70();
  *(double *)(local_63f8 + 0x39b88) = -(double)fVar2;
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_005bb010();
  *(double *)(local_63f8 + 0x39b8a) = (double)fVar2;
  if (*(double *)(local_63f8 + 0x39b88) <= 0.0) {
    local_6418 = -*(double *)(local_63f8 + 0x39b88);
  }
  else {
    local_6418 = *(double *)(local_63f8 + 0x39b88);
  }
  if (local_6418 < 1e-07) {
    if (*(double *)(local_63f8 + 0x39b8a) <= 0.0) {
      local_6420 = -*(double *)(local_63f8 + 0x39b8a);
    }
    else {
      local_6420 = *(double *)(local_63f8 + 0x39b8a);
    }
    if (local_6420 < 1e-07) {
      uVar4 = 0x4049000000000000;
      uVar3 = 0x4049000000000000;
      FUN_00404c80(0x4049000000000000,0x4049000000000000);
      FUN_004fca20();
      FUN_005bb2c0(uVar3,uVar4);
      local_63f8[0x39b88] = 0;
      local_63f8[0x39b89] = -0x3fb70000;
      local_63f8[0x39b8a] = 0;
      local_63f8[0x39b8b] = 0x40490000;
    }
  }
  if (local_63f8[0x39b02] != 0) {
    FUN_00473760(local_63f8 + 0x39b88,local_63f8 + 0x39b8a);
    *(ulonglong *)(local_63f8 + 0x39b88) = *(ulonglong *)(local_63f8 + 0x39b88) ^ 0x8000000000000000
    ;
    *(ulonglong *)(local_63f8 + 0x39b8a) = *(ulonglong *)(local_63f8 + 0x39b8a) ^ 0x8000000000000000
    ;
  }
  if (*(double *)(local_63f8 + 0x39b88) + *(double *)(local_63f8 + 0x39b8a) <= 0.0) {
    local_6428 = -(*(double *)(local_63f8 + 0x39b88) + *(double *)(local_63f8 + 0x39b8a));
  }
  else {
    local_6428 = *(double *)(local_63f8 + 0x39b88) + *(double *)(local_63f8 + 0x39b8a);
  }
  local_63fc = (uint)(local_6428 < 1e-07);
  if (local_63fc != local_63f8[0x39b03]) {
    local_63f8[0x39b03] = local_63fc;
    FUN_00404c80();
    FUN_004fca20();
    FUN_005badc0();
  }
  if (local_63f8[0x2b] == 4) {
    iVar1 = FUN_00629330(local_63f8[0x39b9c],local_63f8[0x39b9d],local_63f8[0x39b9e],
                         local_63f8[0x39b9f],*param_1,param_1[1],param_1[2],param_1[3]);
    if (iVar1 != 0) {
      FUN_004efbb0();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    local_63f8[0x2b] = 3;
  }
  if (local_63f8[0x2b] == 5) {
    iVar1 = FUN_00629330(local_63f8[0x39b90],local_63f8[0x39b91],local_63f8[0x39b92],
                         local_63f8[0x39b93],*param_1,param_1[1],param_1[2],param_1[3]);
    if (iVar1 != 0) {
      FUN_004efbb0();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    (**(code **)(*local_63f8 + 0xc))();
    if (0 < local_63f8[0x39afc]) {
      iVar1 = FUN_006292e0();
      if (iVar1 != 0) {
        local_63f8[0x2b] = 2;
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      local_63f8[0x39afc] = local_63f8[0x39afc] + 1;
      local_63f8[local_63f8[0x39afc] + 0x2c] = local_63f8[local_63f8[0x39afc] + 0x2b];
      local_63f8[local_63f8[0x39afc] + 0x37bb4] = 0;
      local_63f8[local_63f8[0x39afc] + 0x38b58] = 0;
    }
    local_63f8[0x2b] = 2;
  }
  if (local_63f8[0x2b] == 6) {
    iVar1 = FUN_00629330(local_63f8[0x39b9c],local_63f8[0x39b9d],local_63f8[0x39b9e],
                         local_63f8[0x39b9f],*param_1,param_1[1],param_1[2],param_1[3]);
    if (iVar1 != 0) {
      FUN_004efbb0();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_00451eb0();
    if (iVar1 == 0) {
      local_63f8[0x2b] = 2;
      if (0 < local_63f8[0x39afc]) {
        local_63f8[local_63f8[0x39afc] + 0x37bb3] = 0;
        local_63f8[local_63f8[0x39afc] + 0x38b57] = 0;
      }
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    local_63f8[0x2b] = 3;
  }
  if (local_63f8[0x2b] == 7) {
    iVar1 = FUN_00629330(local_63f8[0x39b90],local_63f8[0x39b91],local_63f8[0x39b92],
                         local_63f8[0x39b93],*param_1,param_1[1],param_1[2],param_1[3]);
    if (iVar1 != 0) {
      FUN_004efbb0();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_00451eb0();
    if (iVar1 == 0) {
      local_63f8[0x2b] = 3;
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    (**(code **)(*local_63f8 + 0xc))();
    if (0 < local_63f8[0x39afc]) {
      iVar1 = FUN_006292e0();
      if (iVar1 != 0) {
        local_63f8[0x2b] = 2;
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      local_63f8[0x39afc] = local_63f8[0x39afc] + 1;
      local_63f8[local_63f8[0x39afc] + 0x2c] = local_63f8[local_63f8[0x39afc] + 0x2b];
      local_63f8[local_63f8[0x39afc] + 0x37bb4] = 0;
      local_63f8[local_63f8[0x39afc] + 0x38b58] = 0;
    }
    local_63f8[0x2b] = 2;
  }
  if (local_63f8[0x2b] == 1) {
    *(undefined4 *)(local_63f8[1] + 0x8ebc) = 1;
    FUN_0044dd90(local_6410,local_63f8[1]);
    FUN_004efbb0();
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else if (local_63f8[0x2b] == 2) {
    FUN_004efbb0();
    FUN_0044dd90(local_6410,local_63f8[1]);
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (local_63f8[0x2b] == 3) {
      FUN_004efbb0();
    }
    FUN_004988c0(local_24,*param_1,param_1[1],param_1[2],param_1[3]);
    FUN_00627c30(local_6410,local_63f4);
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukei2Sen[16] */
/* 00624150  FUN_00624150  1823 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00624150(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_6434 [20];
  undefined4 local_6420;
  int local_641c;
  int local_6418;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936f5b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6418 + 4));
  local_8._0_1_ = 1;
  local_6420 = FUN_0040c0e0();
  *(undefined4 *)(local_6418 + 0x3f4c) = 0;
  *(undefined4 *)(local_6418 + 0x3f48) = 0;
  FUN_0044dd90(local_6434,*(undefined4 *)(local_6418 + 4));
  if (*(int *)(local_6418 + 0xac) == 1) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return 0;
  }
  if (*(int *)(local_6418 + 0xac) == 2) {
    if (*(int *)(local_6418 + 0xe6bf0) < 2) {
      *(undefined4 *)(local_6418 + 0xac) = 1;
      *(undefined4 *)(local_6418 + 0xe6bf0) = 0;
      FUN_00624880();
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
    *(undefined4 *)(local_6418 + 0xac) = 3;
    *(int *)(local_6418 + 0xe6bf0) = *(int *)(local_6418 + 0xe6bf0) + -1;
    local_641c = *(int *)(local_6418 + 0xdeed0 + *(int *)(local_6418 + 0xe6bf0) * 4);
    if (local_641c == -2) {
      *(int *)(local_6418 + 0xe6bf0) = *(int *)(local_6418 + 0xe6bf0) + -1;
    }
    FUN_00624880();
    if (*(int *)(local_6418 + 0xdeed0 + *(int *)(local_6418 + 0xe6bf0) * 4) == 0) {
      puVar1 = (undefined4 *)(local_6418 + 0x3f50 + *(int *)(local_6418 + 0xe6bf0) * 0x10);
      FUN_004988c0(local_24,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    }
    if ((local_641c != -2) &&
       (10 < *(int *)(local_6418 + 0xe2d5c + *(int *)(local_6418 + 0xe6bf0) * 4))) {
      *(undefined4 *)(local_6418 + 0xe2d60 + *(int *)(local_6418 + 0xe6bf0) * 4) = 0;
    }
  }
  else if (*(int *)(local_6418 + 0xac) == 3) {
    if (*(int *)(local_6418 + 0xe6bf0) < 2) {
      *(undefined4 *)(local_6418 + 0xac) = 2;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
    if (*(int *)(local_6418 + 0xdeed0 + *(int *)(local_6418 + 0xe6bf0) * 4) == 0) {
      puVar1 = (undefined4 *)(local_6418 + 0x3f50 + *(int *)(local_6418 + 0xe6bf0) * 0x10);
      FUN_004988c0(local_34,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      if (*(int *)(local_6418 + 0xdeecc + *(int *)(local_6418 + 0xe6bf0) * 4) != -1) {
        *(undefined4 *)(local_6418 + 0xac) = 2;
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 1;
      }
      FUN_004b5a50(local_6434);
      FUN_0044a120(local_6434,*(undefined4 *)(local_6418 + 4),
                   *(undefined4 *)(local_6418 + 0xac + *(int *)(local_6418 + 0xe6bf0) * 4),0);
      FUN_004b7110();
      *(undefined4 *)(local_6418 + 0xac + *(int *)(local_6418 + 0xe6bf0) * 4) =
           *(undefined4 *)(local_6418 + 0xb0 + *(int *)(local_6418 + 0xe6bf0) * 4);
      *(int *)(local_6418 + 0xe6bf0) = *(int *)(local_6418 + 0xe6bf0) + -1;
      *(undefined4 *)(local_6418 + 0xdeed0 + *(int *)(local_6418 + 0xe6bf0) * 4) = 0;
      *(undefined4 *)(local_6418 + 0xe2d60 + *(int *)(local_6418 + 0xe6bf0) * 4) = 0;
      *(undefined4 *)(local_6418 + 0xac) = 2;
      FUN_00624880();
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
    *(undefined4 *)(local_6418 + 0xac) = 3;
    *(int *)(local_6418 + 0xe6bf0) = *(int *)(local_6418 + 0xe6bf0) + -1;
    if (*(int *)(local_6418 + 0xdeed0 + *(int *)(local_6418 + 0xe6bf0) * 4) == -2) {
      *(int *)(local_6418 + 0xe6bf0) = *(int *)(local_6418 + 0xe6bf0) + -1;
    }
    FUN_00624880();
    if (*(int *)(local_6418 + 0xdeed0 + *(int *)(local_6418 + 0xe6bf0) * 4) == 0) {
      puVar1 = (undefined4 *)(local_6418 + 0x3f50 + *(int *)(local_6418 + 0xe6bf0) * 0x10);
      FUN_004988c0(local_44,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      if ((*(int *)(local_6418 + 0xdeecc + *(int *)(local_6418 + 0xe6bf0) * 4) != -1) &&
         (*(int *)(local_6418 + 0xe2d5c + *(int *)(local_6418 + 0xe6bf0) * 4) < 10)) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 1;
      }
    }
  }
  FUN_00458a80(local_6434,*(undefined4 *)(local_6418 + 4),0);
  iVar2 = FUN_004146c0();
  if (iVar2 == 0) {
    FUN_004d2660();
  }
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CZukei2Sen[0] */
/* 00624920  FUN_00624920  16 bytes, 0 callers */

undefined ** FUN_00624920(void)

{
  return &PTR_s_CZukei2Sen_00977b00;
}




/* vtable slots: CZukei2Sen[23] */
/* 00624930  FUN_00624930  89 bytes, 0 callers */

undefined4 FUN_00624930(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8628)) {
    if (DAT_00a0cc6c == 0) {
      (**(code **)(*in_ECX + 0x68))();
    }
    else {
      (**(code **)(*in_ECX + 0x6c))();
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukei2Sen[46] */
/* 00624990  FUN_00624990  502 bytes, 0 callers */

undefined4
FUN_00624990(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  if (DAT_00a0c7c0 == 0) {
    local_10 = 0;
    if (*(int *)(in_ECX[1] + 0x9078) == 0) {
      local_18 = 0xffffffff;
      iVar1 = FUN_00778a40(1,&local_18,*(undefined4 *)(in_ECX[1] + 0x9070),param_1,param_2,param_3,
                           param_4,param_5,param_6,param_7,8);
      if (iVar1 == 0) {
        local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      else {
        local_10 = 0;
      }
    }
    else {
      local_c = param_2;
      if (param_2 == 1) {
        if (param_3 == 1) {
          FUN_005168b0(0x1805,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00624c80();
        }
      }
      else if ((param_2 == 6) || (param_2 == 0xc)) {
        if (param_3 == 1) {
          local_14 = 0x2791;
          if (param_2 == 6) {
            local_14 = 0x2792;
          }
          FUN_005168b0(local_14,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          if (param_2 == 0xc) {
            (**(code **)(*in_ECX + 0x6c))();
          }
          else {
            (**(code **)(*in_ECX + 0x68))();
          }
        }
      }
      else {
        local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
  }
  else {
    local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_10;
}




/* vtable slots: CZukei2Sen[47] */
/* 00624b90  FUN_00624b90  231 bytes, 0 callers */

undefined4
FUN_00624b90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                           param_3,param_4,param_5,param_6,param_7,8);
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




/* vtable slots: CZukei2Sen[25] */
/* 00624c80  FUN_00624c80  63 bytes, 1 callers */

void FUN_00624c80(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xe6c08) == 0) {
    *(undefined4 *)(in_ECX + 0xe6c08) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xe6c08) = 0;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukei2Sen[26] */
/* 00624cc0  FUN_00624cc0  236 bytes, 0 callers */

void FUN_00624cc0(void)

{
  int in_ECX;
  float10 fVar1;
  float10 fVar2;
  double dVar3;
  double dVar4;
  
  FUN_00404c80();
  FUN_004fca20();
  fVar1 = (float10)FUN_005baf70();
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_005bb010();
  dVar3 = ((double)fVar1 / 2.0) *
          *(double *)(*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
  dVar4 = ((double)fVar2 / 2.0) *
          *(double *)(*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
  FUN_00404c80(dVar3,dVar4);
  FUN_004fca20();
  FUN_005bb2c0(dVar3,dVar4);
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukei2Sen[27] */
/* 00624db0  FUN_00624db0  236 bytes, 0 callers */

void FUN_00624db0(void)

{
  int in_ECX;
  float10 fVar1;
  float10 fVar2;
  double dVar3;
  double dVar4;
  
  FUN_00404c80();
  FUN_004fca20();
  fVar1 = (float10)FUN_005baf70();
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_005bb010();
  dVar3 = (double)fVar1 * 2.0 *
          *(double *)(*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
  dVar4 = (double)fVar2 * 2.0 *
          *(double *)(*(int *)(in_ECX + 4) + 0x2578 + *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
  FUN_00404c80(dVar3,dVar4);
  FUN_004fca20();
  FUN_005bb2c0(dVar3,dVar4);
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukei2Sen[50] */
/* 00624ea0  FUN_00624ea0  96 bytes, 0 callers */

void FUN_00624ea0(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = param_1;
  FUN_00404c80(param_1,param_1);
  FUN_004fca20();
  FUN_005bb2c0(param_1,uVar1);
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukei2Sen[51] */
/* 00624f00  FUN_00624f00  160 bytes, 0 callers */

void FUN_00624f00(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00936f9d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  uVar1 = param_3;
  FUN_00404c80(param_3,param_3,DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  FUN_004fca20();
  FUN_005bb2c0(param_3,uVar1);
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukei2Sen[12] */
/* 00624fa0  FUN_00624fa0  1760 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00624fa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_6424 [20];
  int local_6410;
  int local_640c;
  int local_6408;
  undefined1 local_6404 [25380];
  undefined4 local_e0;
  undefined4 local_dc;
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
  puStack_c = &LAB_00936fdb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  local_6408 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  FUN_00446aa0(uVar1);
  local_8._0_1_ = 1;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  if (*(int *)(local_6408 + 0xac) == 4) {
    *(undefined4 *)(local_6408 + 0xac) = 2;
    local_e0 = 1;
    local_dc = 1;
    iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6408 + 4),&local_24,&local_640c,1);
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar2 == 0) {
        FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else {
        local_6410 = FUN_00450d00(*(undefined4 *)(local_6408 + 4),local_640c);
        if (*(int *)(local_6408 + 0xb0 + *(int *)(local_6408 + 0xe6bf0) * 4) == local_6410) {
          FUN_005168b0(0x14e7,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
        else {
          *(int *)(local_6408 + 0xb0 + *(int *)(local_6408 + 0xe6bf0) * 4) = local_6410;
          *(undefined4 *)(local_6408 + 0xdeed0 + *(int *)(local_6408 + 0xe6bf0) * 4) = 0;
          *(undefined4 *)(local_6408 + 0xe2d60 + *(int *)(local_6408 + 0xe6bf0) * 4) = 0;
          FUN_005168b0(0x2793,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
      }
    }
  }
  else if (*(int *)(local_6408 + 0xac) == 5) {
    *(undefined4 *)(local_6408 + 0xac) = 3;
    local_e0 = 1;
    local_dc = 1;
    iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6408 + 4),&local_24,&local_640c,1);
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar2 == 0) {
        FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else if (*(int *)(local_6408 + 0xb0 + *(int *)(local_6408 + 0xe6bf0) * 4) == local_640c) {
        FUN_005168b0(0x14e7,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else {
        iVar2 = FUN_00629400(*(undefined4 *)(local_6408 + 0xb0 + *(int *)(local_6408 + 0xe6bf0) * 4)
                             ,local_640c);
        if (iVar2 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
        else {
          uVar3 = FUN_00450d00(*(undefined4 *)(local_6408 + 4),local_640c);
          *(undefined4 *)(local_6408 + 0xac) = 9;
          FUN_004988c0(local_34,local_24,local_20,local_1c,local_18);
          FUN_00627c30(local_6424,local_6404);
          *(undefined4 *)(local_6408 + 0xac) = 3;
          iVar2 = FUN_006292e0();
          if (iVar2 == 0) {
            *(int *)(local_6408 + 0xe6bf0) = *(int *)(local_6408 + 0xe6bf0) + 1;
            *(undefined4 *)(local_6408 + 0xb0 + *(int *)(local_6408 + 0xe6bf0) * 4) = uVar3;
            *(undefined4 *)(local_6408 + 0xdeed0 + *(int *)(local_6408 + 0xe6bf0) * 4) = 1;
            *(undefined4 *)(local_6408 + 0xe2d60 + *(int *)(local_6408 + 0xe6bf0) * 4) = 0;
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
          }
          else {
            *(undefined4 *)(local_6408 + 0xac) = 2;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
          }
        }
      }
    }
  }
  else {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukei2Sen[9] */
/* 00625680  FUN_00625680  2901 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00625680(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  undefined1 local_6444 [20];
  int local_6430;
  int local_642c;
  int local_6428;
  undefined1 local_6424 [25380];
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093702b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6428 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  uVar2 = FUN_0040c0e0(uVar1);
  FUN_00446aa0(uVar1,uVar2);
  local_8._0_1_ = 1;
  *(undefined4 *)(local_6428 + 0x3f4c) = 0;
  *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
  FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
  if (*(int *)(local_6428 + 0xac) == 1) {
    local_100 = 1;
    local_fc = 1;
    iVar3 = FUN_0044a270(3,*(undefined4 *)(local_6428 + 4),&param_2,&local_642c,1);
    if (iVar3 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar3 == 0) {
        FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else {
        iVar3 = FUN_006292e0();
        if (iVar3 == 0) {
          *(int *)(local_6428 + 0xe6bf0) = *(int *)(local_6428 + 0xe6bf0) + 1;
          uVar2 = FUN_00450d00(*(undefined4 *)(local_6428 + 4),local_642c);
          *(undefined4 *)(local_6428 + 0xb0 + *(int *)(local_6428 + 0xe6bf0) * 4) = uVar2;
          *(undefined4 *)(local_6428 + 0xdeed0 + *(int *)(local_6428 + 0xe6bf0) * 4) = 0;
          *(undefined4 *)(local_6428 + 0xe2d60 + *(int *)(local_6428 + 0xe6bf0) * 4) = 0;
          *(undefined4 *)(local_6428 + 0xac) = 2;
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
        else {
          *(undefined4 *)(local_6428 + 0xac) = 2;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
      }
    }
  }
  else if (*(int *)(local_6428 + 0xac) == 2) {
    FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
    *(undefined4 *)(local_6428 + 0xac) = 3;
    if (0 < *(int *)(local_6428 + 0xe6bf0)) {
      *(undefined4 *)(local_6428 + 0xe2d5c + *(int *)(local_6428 + 0xe6bf0) * 4) = 0;
      local_6430 = FUN_00629c90();
      if (0 < local_6430) {
        *(int *)(local_6428 + 0xe2d5c + *(int *)(local_6428 + 0xe6bf0) * 4) = local_6430 + 10;
        fVar4 = (float10)FUN_006295e0(local_6430);
        *(double *)(local_6428 + 0xe6bf8) = (double)fVar4;
      }
      *(undefined4 *)(local_6428 + 0xac) = 4;
    }
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else if (*(int *)(local_6428 + 0xac) == 3) {
    if (0 < *(int *)(local_6428 + 0xe6bf0)) {
      iVar3 = FUN_00629c90();
      if (0 < iVar3) {
        *(int *)(local_6428 + 0x3f4c) = iVar3;
      }
    }
    *(undefined4 *)(local_6428 + 0xac) = 5;
    FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else if (*(int *)(local_6428 + 0xac) == 4) {
    *(undefined4 *)(local_6428 + 0xac) = 2;
    local_100 = 1;
    local_fc = 1;
    iVar3 = FUN_0044a270(3,*(undefined4 *)(local_6428 + 4),&param_2,&local_642c,1);
    if (iVar3 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar3 == 0) {
        FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else {
        iVar3 = FUN_00450d00(*(undefined4 *)(local_6428 + 4),local_642c);
        if (*(int *)(local_6428 + 0xb0 + *(int *)(local_6428 + 0xe6bf0) * 4) == iVar3) {
          FUN_005168b0(0x14e7,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
        else {
          *(int *)(local_6428 + 0xb0 + *(int *)(local_6428 + 0xe6bf0) * 4) = iVar3;
          *(undefined4 *)(local_6428 + 0xdeed0 + *(int *)(local_6428 + 0xe6bf0) * 4) = 0;
          *(undefined4 *)(local_6428 + 0xe2d60 + *(int *)(local_6428 + 0xe6bf0) * 4) = 0;
          FUN_005168b0(0x2793,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
      }
    }
  }
  else if (*(int *)(local_6428 + 0xac) == 5) {
    *(undefined4 *)(local_6428 + 0xac) = 3;
    local_100 = 1;
    local_fc = 1;
    iVar3 = FUN_0044a270(3,*(undefined4 *)(local_6428 + 4),&param_2,&local_642c,1);
    if (iVar3 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar3 == 0) {
        FUN_005168b0(0x14de,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else if (*(int *)(local_6428 + 0xb0 + *(int *)(local_6428 + 0xe6bf0) * 4) == local_642c) {
        FUN_005168b0(0x14e7,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else {
        iVar3 = FUN_00629400(*(undefined4 *)(local_6428 + 0xb0 + *(int *)(local_6428 + 0xe6bf0) * 4)
                             ,local_642c);
        if (iVar3 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
        else {
          uVar2 = FUN_00450d00(*(undefined4 *)(local_6428 + 4),local_642c);
          *(undefined4 *)(local_6428 + 0xac) = 9;
          FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
          FUN_00627c30(local_6444,local_6424);
          *(undefined4 *)(local_6428 + 0xac) = 3;
          iVar3 = FUN_006292e0();
          if (iVar3 == 0) {
            *(int *)(local_6428 + 0xe6bf0) = *(int *)(local_6428 + 0xe6bf0) + 1;
            *(undefined4 *)(local_6428 + 0xb0 + *(int *)(local_6428 + 0xe6bf0) * 4) = uVar2;
            *(undefined4 *)(local_6428 + 0xdeed0 + *(int *)(local_6428 + 0xe6bf0) * 4) = 1;
            *(undefined4 *)(local_6428 + 0xe2d60 + *(int *)(local_6428 + 0xe6bf0) * 4) = 0;
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
          }
          else {
            *(undefined4 *)(local_6428 + 0xac) = 2;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
          }
        }
      }
    }
  }
  else {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukei2Sen[13] */
/* 006261e0  FUN_006261e0  2360 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006261e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  int local_640c;
  int local_6404;
  int local_63fc;
  int *local_63f8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093707b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8560) = 0;
  local_63f8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(in_ECX[1]);
  local_8 = 0;
  FUN_00446aa0(uVar1);
  local_8._0_1_ = 1;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  if (local_63f8[0x2b] == 6) {
    local_63f8[0x2b] = 2;
    iVar2 = FUN_0044a270(3,local_63f8[1],&local_24,&local_63fc,1);
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      if (local_63f8[1] == 0) {
        local_6404 = 0;
      }
      else {
        local_6404 = local_63f8[1] + 0x88;
      }
      iVar2 = FUN_0042b720(local_6404);
      if (iVar2 == 1) {
        FUN_005168b0(0x149f,*(undefined4 *)(local_63f8[1] + 0x8f24),
                     *(undefined4 *)(local_63f8[1] + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else {
        iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar2 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(local_63f8[1] + 0x8f24),
                       *(undefined4 *)(local_63f8[1] + 0x8f28),0,0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
        else {
          iVar2 = FUN_00629400(local_63f8[local_63f8[0x39afc] + 0x2c],local_63fc);
          if (iVar2 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
          }
          else {
            iVar2 = FUN_006292e0();
            if (iVar2 == 0) {
              local_63f8[0x39afc] = local_63f8[0x39afc] + 1;
              local_63f8[local_63f8[0x39afc] + 0x2c] = local_63fc;
              iVar2 = local_63f8[local_63f8[0x39afc] + 0x2c];
              local_63f8[local_63f8[0x39afc] + 0x2c] = local_63f8[local_63f8[0x39afc] + 0x2b];
              local_63f8[local_63f8[0x39afc] + 0x2b] = iVar2;
              local_63f8[local_63f8[0x39afc] + 0x37bb3] = -1;
              local_63f8[local_63f8[0x39afc] + 0x38b58] = 0;
              FUN_0040db00(local_24,local_20,local_1c,local_18);
              local_63f8[local_63f8[0x39afc] + 0x37bb4] = 0;
              local_63f8[local_63f8[0x39afc] + 0x38b58] = 0;
              local_63f8[0x2b] = 3;
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
            }
            else {
              local_63f8[0x2b] = 2;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
            }
          }
        }
      }
    }
  }
  else if (local_63f8[0x2b] == 7) {
    local_63f8[0x2b] = 3;
    iVar2 = FUN_0044a270(3,local_63f8[1],&local_24,&local_63fc,1);
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      if (local_63f8[1] == 0) {
        local_640c = 0;
      }
      else {
        local_640c = local_63f8[1] + 0x88;
      }
      iVar2 = FUN_0042b720(local_640c);
      if (iVar2 == 1) {
        FUN_005168b0(0x149f,*(undefined4 *)(local_63f8[1] + 0x8f24),
                     *(undefined4 *)(local_63f8[1] + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else {
        iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar2 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(local_63f8[1] + 0x8f24),
                       *(undefined4 *)(local_63f8[1] + 0x8f28),0,0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
        else {
          iVar2 = FUN_00629400(local_63f8[local_63f8[0x39afc] + 0x2c],local_63fc);
          if (iVar2 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
          }
          else {
            iVar2 = FUN_006292e0();
            if (iVar2 == 0) {
              local_63f8[0x39afc] = local_63f8[0x39afc] + 1;
              local_63f8[local_63f8[0x39afc] + 0x2c] = local_63fc;
              local_63f8[local_63f8[0x39afc] + 0x37bb4] = -2;
              local_63f8[local_63f8[0x39afc] + 0x38b58] = 0;
              FUN_0040db00(local_24,local_20,local_1c,local_18);
              (**(code **)(*local_63f8 + 0xc))();
              iVar2 = FUN_006292e0();
              if (iVar2 == 0) {
                local_63f8[0x39afc] = local_63f8[0x39afc] + 1;
                local_63f8[local_63f8[0x39afc] + 0x2c] = local_63f8[local_63f8[0x39afc] + 0x2a];
                local_63f8[local_63f8[0x39afc] + 0x37bb4] = 0;
                local_63f8[local_63f8[0x39afc] + 0x38b58] = 0;
                local_63f8[0x2b] = 2;
                FUN_00404c80();
                FUN_0056d7d0();
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_00447100();
                local_8 = 0xffffffff;
                FUN_0079dfff();
              }
              else {
                local_63f8[0x2b] = 2;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_00447100();
                local_8 = 0xffffffff;
                FUN_0079dfff();
              }
            }
            else {
              local_63f8[0x2b] = 2;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
            }
          }
        }
      }
    }
  }
  else {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukei2Sen[11] */
/* 00626b20  FUN_00626b20  3006 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00626b20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  int local_6448;
  int local_6440;
  int local_641c;
  int *local_6418;
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
  puStack_c = &LAB_009370cb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8560) = 0;
  local_6418 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(in_ECX[1]);
  local_8 = 0;
  FUN_00446aa0(uVar1);
  local_8._0_1_ = 1;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  local_6418[0xfd3] = 0;
  if (local_6418[0x2b] == 2) {
    local_6418[0x2b] = 6;
    FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
    if (0 < local_6418[0x39afc]) {
      local_6418[local_6418[0x39afc] + 0x38b57] = 0;
      iVar2 = FUN_00629c90();
      if (0 < iVar2) {
        local_6418[local_6418[0x39afc] + 0x38b57] = iVar2 + 10;
        fVar4 = (float10)FUN_006295e0(iVar2);
        *(double *)(local_6418 + 0x39afe) = (double)fVar4;
      }
    }
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    uVar3 = 0;
  }
  else if (local_6418[0x2b] == 3) {
    if (0 < local_6418[0x39afc]) {
      iVar2 = FUN_00629c90();
      if (0 < iVar2) {
        local_6418[0xfd3] = iVar2;
      }
    }
    local_6418[0x2b] = 7;
    FUN_004988c0(local_44,local_24,local_20,local_1c,local_18);
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    uVar3 = 0;
  }
  else if (local_6418[0x2b] == 6) {
    local_6418[0x2b] = 2;
    iVar2 = FUN_0044a270(3,local_6418[1],&local_24,&local_641c,1);
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar3 = 0;
    }
    else {
      if (local_6418[1] == 0) {
        local_6440 = 0;
      }
      else {
        local_6440 = local_6418[1] + 0x88;
      }
      iVar2 = FUN_0042b720(local_6440);
      if (iVar2 == 1) {
        FUN_005168b0(0x149f,*(undefined4 *)(local_6418[1] + 0x8f24),
                     *(undefined4 *)(local_6418[1] + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar3 = 0;
      }
      else {
        iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar2 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(local_6418[1] + 0x8f24),
                       *(undefined4 *)(local_6418[1] + 0x8f28),0,0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar3 = 0;
        }
        else {
          iVar2 = FUN_00629400(local_6418[local_6418[0x39afc] + 0x2c],local_641c);
          if (iVar2 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
            uVar3 = 0;
          }
          else {
            iVar2 = FUN_006292e0();
            if (iVar2 == 0) {
              local_6418[0x39afc] = local_6418[0x39afc] + 1;
              local_6418[local_6418[0x39afc] + 0x2c] = local_641c;
              iVar2 = local_6418[local_6418[0x39afc] + 0x2c];
              local_6418[local_6418[0x39afc] + 0x2c] = local_6418[local_6418[0x39afc] + 0x2b];
              local_6418[local_6418[0x39afc] + 0x2b] = iVar2;
              local_6418[local_6418[0x39afc] + 0x37bb3] = -1;
              local_6418[local_6418[0x39afc] + 0x38b58] = 0;
              FUN_0040db00(local_24,local_20,local_1c,local_18);
              local_6418[local_6418[0x39afc] + 0x37bb4] = 0;
              local_6418[local_6418[0x39afc] + 0x38b58] = 0;
              local_6418[0x2b] = 3;
              FUN_00404c80();
              FUN_0056d7d0();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              uVar3 = 0;
            }
            else {
              local_6418[0x2b] = 2;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              uVar3 = 0;
            }
          }
        }
      }
    }
  }
  else if (local_6418[0x2b] == 7) {
    local_6418[0x2b] = 3;
    iVar2 = FUN_0044a270(3,local_6418[1],&local_24,&local_641c,1);
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar3 = 0;
    }
    else {
      if (local_6418[1] == 0) {
        local_6448 = 0;
      }
      else {
        local_6448 = local_6418[1] + 0x88;
      }
      iVar2 = FUN_0042b720(local_6448);
      if (iVar2 == 1) {
        FUN_005168b0(0x149f,*(undefined4 *)(local_6418[1] + 0x8f24),
                     *(undefined4 *)(local_6418[1] + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar3 = 0;
      }
      else {
        iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar2 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(local_6418[1] + 0x8f24),
                       *(undefined4 *)(local_6418[1] + 0x8f28),0,0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar3 = 0;
        }
        else {
          iVar2 = FUN_00629400(local_6418[local_6418[0x39afc] + 0x2c],local_641c);
          if (iVar2 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_0079dfff();
            uVar3 = 0;
          }
          else {
            iVar2 = FUN_006292e0();
            if (iVar2 == 0) {
              local_6418[0x39afc] = local_6418[0x39afc] + 1;
              local_6418[local_6418[0x39afc] + 0x2c] = local_641c;
              local_6418[local_6418[0x39afc] + 0x37bb4] = -2;
              local_6418[local_6418[0x39afc] + 0x38b58] = 0;
              FUN_0040db00(local_24,local_20,local_1c,local_18);
              (**(code **)(*local_6418 + 0xc))();
              iVar2 = FUN_006292e0();
              if (iVar2 == 0) {
                local_6418[0x39afc] = local_6418[0x39afc] + 1;
                local_6418[local_6418[0x39afc] + 0x2c] = local_6418[local_6418[0x39afc] + 0x2a];
                local_6418[local_6418[0x39afc] + 0x37bb4] = 0;
                local_6418[local_6418[0x39afc] + 0x38b58] = 0;
                local_6418[0x2b] = 2;
                FUN_00404c80();
                FUN_0056d7d0();
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_00447100();
                local_8 = 0xffffffff;
                FUN_0079dfff();
                uVar3 = 0;
              }
              else {
                local_6418[0x2b] = 2;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_00447100();
                local_8 = 0xffffffff;
                FUN_0079dfff();
                uVar3 = 0;
              }
            }
            else {
              local_6418[0x2b] = 2;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              uVar3 = 0;
            }
          }
        }
      }
    }
  }
  else {
    iVar2 = FUN_00451eb0(local_6418[1],&local_24,1);
    if (iVar2 == 1) {
      uVar3 = FUN_00625680(param_1,local_24,local_20,local_1c,local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      uVar3 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar3;
}




/* vtable slots: CZukei2Sen[4] */
/* 006276e0  FUN_006276e0  412 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006276e0(void)

{
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
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044dd90(local_6404,*(undefined4 *)(local_63e8 + 4));
  local_63ec = *(int *)(local_63e8 + 4);
  if (local_63ec == 0) {
    local_63f0 = 0;
  }
  else {
    local_63f0 = local_63ec + 0x88;
  }
  FUN_00454890(local_63f0);
  FUN_00454830(*(undefined4 *)(local_63e8 + 4));
  if (*(int *)(local_63e8 + 0x3f40) != 0) {
    FUN_004b5a50(local_6404);
    FUN_0044a120(local_6404,*(undefined4 *)(local_63e8 + 4),*(undefined4 *)(local_63e8 + 0x3f40),0);
    FUN_004b7110();
  }
  *(undefined4 *)(local_63e8 + 0x3f40) = 0;
  *(undefined4 *)(local_63e8 + 0x3f44) = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukei2Sen[3] */
/* 00627880  FUN_00627880  944 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00627880(void)

{
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25336];
  undefined4 local_ec;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093711b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_63ec = *(int *)(local_63e8 + 0xdeed0 + *(int *)(local_63e8 + 0xe6bf0) * 4);
  if (local_63ec == -2) {
    *(int *)(local_63e8 + 0xe6bf0) = *(int *)(local_63e8 + 0xe6bf0) + -1;
  }
  *(undefined4 *)(local_63e8 + 0xac) = 9;
  FUN_00627c30(local_6404,local_63e4);
  *(undefined4 *)(local_63e8 + 0xac) = 3;
  FUN_0044dd90(local_6404,*(undefined4 *)(local_63e8 + 4));
  if (local_63ec == -2) {
    *(int *)(local_63e8 + 0xe6bf0) = *(int *)(local_63e8 + 0xe6bf0) + 1;
    local_63f0 = FUN_00629650(local_6404,local_63e4);
    FUN_00450860(local_6404,*(undefined4 *)(local_63e8 + 4),
                 local_63e8 + 0x13990 + (*(int *)(local_63e8 + 0xe6bf0) + -1) * 0x68,1,1);
    local_ec = 1;
    FUN_00450860(local_6404,*(undefined4 *)(local_63e8 + 4),
                 local_63e8 + 0x79430 + (*(int *)(local_63e8 + 0xe6bf0) + -1) * 0x68,1,1);
    if (0 < local_63f0) {
      FUN_0044b2c0(local_6404,*(undefined4 *)(local_63e8 + 4),
                   *(undefined4 *)(local_63e8 + 0xb0 + *(int *)(local_63e8 + 0xe6bf0) * 4),1);
      local_ec = 1;
      FUN_00450860(local_6404,*(undefined4 *)(local_63e8 + 4),
                   local_63e8 + 0x13990 + *(int *)(local_63e8 + 0xe6bf0) * 0x68,1,0);
    }
    if (1 < local_63f0) {
      FUN_00450860(local_6404,*(undefined4 *)(local_63e8 + 4),
                   local_63e8 + 0x79430 + *(int *)(local_63e8 + 0xe6bf0) * 0x68,1,0);
    }
  }
  else {
    FUN_00450860(local_6404,*(undefined4 *)(local_63e8 + 4),
                 local_63e8 + 0x13990 + *(int *)(local_63e8 + 0xe6bf0) * 0x68,1,1);
    local_ec = 1;
    FUN_00450860(local_6404,*(undefined4 *)(local_63e8 + 4),
                 local_63e8 + 0x79430 + *(int *)(local_63e8 + 0xe6bf0) * 0x68,1,1);
    if ((*(int *)(local_63e8 + 0x3f4c) != 0) && (*(int *)(local_63e8 + 0x3f48) != 0)) {
      FUN_00450860(local_6404,*(undefined4 *)(local_63e8 + 4),*(undefined4 *)(local_63e8 + 0x3f48),1
                   ,1);
    }
  }
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8578) = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



