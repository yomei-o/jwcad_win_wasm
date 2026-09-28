/* CZukeiBunkatsu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiBunkatsu[1] */
/* 0075b670  FUN_0075b670  68 bytes, 0 callers */

undefined4 FUN_0075b670(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0075b540();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x3ace0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiBunkatsu[6] */
/* 007614c0  FUN_007614c0  1276 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007614c0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_64a8 [20];
  int local_6494;
  int *local_6490;
  undefined1 local_bc [16];
  undefined1 local_ac [16];
  undefined1 local_9c [16];
  undefined1 local_8c [16];
  undefined1 local_7c [40];
  undefined1 local_54;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942593;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6490 = in_ECX;
  (**(code **)(*in_ECX + 0x20))(local_14);
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(local_6490[1]);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044dd90(local_64a8,local_6490[1]);
  if (local_6490[0x4e] == 0) {
    if (((local_6490[0x30] == 0) || (local_6490[0x30] == 1)) && (local_6490[0x32] != 1)) {
      local_6490[0x2b] = 0;
      FUN_004efbb0(0x14ed,0,0);
      local_6490[0x32] = 1;
    }
    if (local_6490[0x30] == 2) {
      if (local_6490[0x2b] == 0) {
        iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar2 == 0) {
          iVar2 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
          if ((iVar2 != 0) && (local_6490[0x32] != 5)) {
            FUN_004efbb0(0x14ef,0,0);
            local_6490[0x32] = 5;
          }
        }
        else if (((local_6490[0x1fad] == 0) && (local_6490[0x2a] == 0)) && (local_6490[0x1fac] == 0)
                ) {
          if (local_6490[0x32] != 4) {
            FUN_004efbb0(0x14ee,0,0);
            local_6490[0x32] = 4;
          }
        }
        else if (local_6490[0x32] != 3) {
          FUN_004efbb0(0x15ee,0,0);
          local_6490[0x32] = 3;
        }
      }
      else if (local_6490[0x32] != 2) {
        FUN_004efbb0(0x14f1,0,0);
        local_6490[0x32] = 2;
      }
    }
    if ((local_6490[0x30] == 3) && (local_6490[0x32] != 6)) {
      FUN_004efbb0(0x14f0,0,0);
      local_6490[0x32] = 6;
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (local_6490[0x4e] < 2) {
      if (local_6490[0x32] != 0xb) {
        FUN_004efbb0(0x16bb,0,0);
        local_6490[0x32] = 0xb;
      }
    }
    else if (local_6490[0x32] != 0xc) {
      FUN_004efbb0(0x16bc,0,0);
      local_6490[0x32] = 0xc;
    }
    FUN_0041f760();
    local_8._0_1_ = 2;
    for (local_6494 = 1; local_6494 < local_6490[0x4e]; local_6494 = local_6494 + 1) {
      piVar1 = local_6490 + local_6494 * 4 + 0x50;
      FUN_004988c0(local_8c,*piVar1,piVar1[1],piVar1[2],piVar1[3]);
      piVar1 = local_6490 + (local_6494 + 1) * 4 + 0x50;
      FUN_004988c0(local_9c,*piVar1,piVar1[1],piVar1[2],piVar1[3]);
      FUN_00450b70(local_64a8,local_6490[1],local_7c);
    }
    local_54 = 3;
    piVar1 = local_6490 + local_6490[0x4e] * 4 + 0x50;
    FUN_004988c0(local_ac,*piVar1,piVar1[1],piVar1[2],piVar1[3]);
    FUN_004988c0(local_bc,*param_1,param_1[1],param_1[2],param_1[3]);
    FUN_00450b70(local_64a8,local_6490[1],local_7c);
    local_8._0_1_ = 1;
    FUN_0041fd70();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiBunkatsu[16] */
/* 007619c0  FUN_007619c0  661 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007619c0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  undefined4 local_63f0;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937dcb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004fb9f0(local_14);
  *(undefined4 *)(local_63e8 + 0xa8) = 0;
  *(undefined4 *)(local_63e8 + 0x7eb0) = 0;
  *(undefined4 *)(local_63e8 + 0x7eb4) = 0;
  uVar2 = *(undefined4 *)(local_63e8 + 0x138);
  uVar1 = 0;
  FUN_00404c80(0,uVar2);
  FUN_004fca20();
  FUN_00417640(uVar1,uVar2);
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044de00(local_6408,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_6408);
  FUN_00449d60(local_6408,*(undefined4 *)(local_63e8 + 4),1);
  if (*(int *)(local_63e8 + 0x138) < 1) {
    if ((*(int *)(local_63e8 + 0xc0) == 0) || (*(int *)(local_63e8 + 0xc0) == 1)) {
      local_63f0 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63ec = local_63f0;
    }
    else {
      if (*(int *)(local_63e8 + 0xc0) == 2) {
        *(undefined4 *)(local_63e8 + 0xc0) = 0;
      }
      if (*(int *)(local_63e8 + 0xc0) == 3) {
        *(undefined4 *)(local_63e8 + 0xc0) = 2;
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_63f4 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63ec = local_63f4;
    }
  }
  else {
    *(int *)(local_63e8 + 0x138) = *(int *)(local_63e8 + 0x138) + -1;
    FUN_00404c80();
    FUN_0056d7d0();
    uVar2 = *(undefined4 *)(local_63e8 + 0x138);
    uVar1 = 0;
    FUN_00404c80(0,uVar2);
    FUN_004fca20();
    FUN_00417640(uVar1,uVar2);
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiBunkatsu[0] */
/* 007637d0  FUN_007637d0  16 bytes, 0 callers */

undefined ** FUN_007637d0(void)

{
  return &PTR_s_CZukeiBunkatsu_0097b770;
}




/* vtable slots: CZukeiBunkatsu[46] */
/* 007637e0  FUN_007637e0  814 bytes, 0 callers */

undefined4
FUN_007637e0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int in_ECX;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (DAT_00a0c7c0 == 0) {
    local_8 = in_ECX;
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_14 = 0xffffffff;
      iVar1 = FUN_00778a40(1,&local_14,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,0x1a);
      if (iVar1 != 0) {
        return 0;
      }
    }
    local_c = 0;
    local_10 = 0;
    if ((*(int *)(local_8 + 0xcc) != 0) &&
       (iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024), iVar1 != 0)) {
      local_10 = 1;
    }
    if ((*(int *)(*(int *)(local_8 + 4) + 0x9078) == 0) && (*(int *)(local_8 + 0xc0) == 2)) {
      if (param_2 == 0xc) {
        if (param_3 == 1) {
          FUN_005168b0(0x2733,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f50),
                       *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_005156d0();
        }
      }
      else if ((((param_2 == 1) && (*(int *)(local_8 + 0xac) == 0)) && (local_10 == 1)) &&
              ((*(int *)(local_8 + 0x7e84) == 0 && (*(int *)(local_8 + 0xb8) == 0)))) {
        if (param_3 == 1) {
          FUN_005168b0(0x15eb,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f50),
                       *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00763ee0();
        }
      }
      else if (((param_2 == 2) && ((*(int *)(local_8 + 0xac) == 0 && (local_10 == 1)))) &&
              ((*(int *)(local_8 + 0x7e84) == 0 && (*(int *)(local_8 + 0xb8) == 0)))) {
        if (param_3 == 1) {
          FUN_005168b0(0x15ec,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f50),
                       *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00763cd0();
        }
      }
      else if ((((param_2 == 3) && (*(int *)(local_8 + 0xac) == 0)) && (local_10 == 1)) &&
              ((*(int *)(local_8 + 0x7e84) == 0 && (*(int *)(local_8 + 0xb8) == 0)))) {
        if (param_3 == 1) {
          FUN_005168b0(0x15e9,*(undefined4 *)(*(int *)(local_8 + 4) + 0x8f50),
                       *(undefined4 *)(*(int *)(local_8 + 4) + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00763d20(0);
        }
      }
      else {
        local_c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      local_c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_c;
}




/* vtable slots: CZukeiBunkatsu[47] */
/* 00763b10  FUN_00763b10  224 bytes, 0 callers */

undefined4
FUN_00763b10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                           param_3,param_4,param_5,param_6,param_7,0x1a);
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




/* vtable slots: CZukeiBunkatsu[34] */
/* 00763bf0  FUN_00763bf0  222 bytes, 2 callers */

void FUN_00763bf0(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 local_c;
  
  FUN_004fb9f0();
  in_ECX[0x1fac] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x1fad] = 0;
  (**(code **)(*in_ECX + 0x20))();
  local_c = 0;
  if ((((in_ECX[0x2e] == 0) && (in_ECX[0x1fa1] == 0)) && (in_ECX[0x30] == 2)) &&
     ((in_ECX[0x2b] == 0 && (in_ECX[0x33] != 0)))) {
    iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
    if (iVar1 != 0) {
      local_c = 0xffffffff;
    }
  }
  iVar1 = in_ECX[0x4e];
  FUN_00404c80(local_c,iVar1);
  FUN_004fca20();
  FUN_00417640(local_c,iVar1);
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiBunkatsu[25] */
/* 00763cd0  FUN_00763cd0  74 bytes, 1 callers */

void FUN_00763cd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x7eb0) == 0) {
    *(undefined4 *)(in_ECX + 0x7eb0) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x7eb0) = 0;
  }
  *(undefined4 *)(in_ECX + 0x7eb4) = 0;
  FUN_00763f20(0);
  return;
}




/* vtable slots: CZukeiBunkatsu[26] */
/* 00763d20  FUN_00763d20  446 bytes, 1 callers */

void FUN_00763d20(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942700;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x7eb4) == 0) {
    local_14 = in_ECX;
    FUN_00498c40(0);
    local_8 = 0;
    uVar1 = FUN_005977f0(0x15ea);
    local_8._0_1_ = 1;
    FUN_00404860(uVar1);
    local_8._0_1_ = 0;
    FUN_00404770();
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    *(undefined4 *)(local_14 + 0x7eb8) = *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xb8);
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_004059f0(local_18,&DAT_0095b714,*(undefined4 *)(local_14 + 0x7eb8));
    FUN_00404860(local_18);
    iVar2 = FUN_0079850d();
    if (iVar2 == 1) {
      FUN_004994b0();
      uVar1 = thunk_FUN_008d99f0();
      *(undefined4 *)(local_14 + 0x7eb8) = uVar1;
      if (2000 < *(int *)(local_14 + 0x7eb8)) {
        *(undefined4 *)(local_14 + 0x7eb8) = 2000;
      }
      if (*(int *)(local_14 + 0x7eb8) < 2) {
        *(undefined4 *)(local_14 + 0x7eb8) = 2;
      }
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xb8) = *(undefined4 *)(local_14 + 0x7eb8);
      *(undefined4 *)(local_14 + 0x7eb4) = 1;
      *(undefined4 *)(local_14 + 0x7eb0) = 0;
    }
    local_8 = local_8 & 0xffffff00;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00498e00();
  }
  else {
    *(undefined4 *)(in_ECX + 0x7eb4) = 0;
  }
  FUN_00763f20(0);
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiBunkatsu[27] */
/* 00763ee0  FUN_00763ee0  61 bytes, 1 callers */

void FUN_00763ee0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xa8) == 0) {
    *(undefined4 *)(in_ECX + 0xa8) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xa8) = 0;
  }
  FUN_00763f20(0);
  return;
}




/* vtable slots: CZukeiBunkatsu[50] */
/* 00764140  FUN_00764140  255 bytes, 0 callers */

void FUN_00764140(double param_1)

{
  int iVar1;
  int in_ECX;
  undefined8 local_18;
  
  if (*(int *)(in_ECX + 0x7e84) == 0) {
    if (param_1 <= 0.0) {
      local_18 = -param_1;
    }
    else {
      local_18 = param_1;
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    (**(code **)(*(int *)(*(int *)(iVar1 + 0x1a0) + 0x218) + 0x188))(local_18);
  }
  else {
    if (DAT_00a0d62c != 0) {
      param_1 = param_1 / DAT_00a0d630;
    }
    if (param_1 <= 0.0) {
      param_1 = -param_1;
    }
    FUN_00404c80(param_1);
    iVar1 = FUN_004fca20();
    (**(code **)(*(int *)(*(int *)(iVar1 + 0x1a0) + 0xd0) + 0x188))(param_1);
  }
  return;
}




/* vtable slots: CZukeiBunkatsu[51] */
/* 00764240  FUN_00764240  349 bytes, 0 callers */

void FUN_00764240(undefined4 param_1,undefined4 param_2,double param_3)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  double local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094277d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80();
  FUN_004fca20();
  FUN_004183a0();
  if (*(int *)(in_ECX + 0x7e84) == 0) {
    if (param_3 <= 0.0) {
      local_24 = -param_3;
    }
    else {
      local_24 = param_3;
    }
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    (**(code **)(*(int *)(*(int *)(iVar2 + 0x1a0) + 0x218) + 0x188))(local_24);
  }
  else {
    if (DAT_00a0d62c != 0) {
      param_3 = param_3 / DAT_00a0d630;
    }
    if (param_3 <= 0.0) {
      param_3 = -param_3;
    }
    FUN_00404c80(uVar1,param_3);
    iVar2 = FUN_004fca20();
    (**(code **)(*(int *)(*(int *)(iVar2 + 0x1a0) + 0xd0) + 0x188))(param_3);
  }
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiBunkatsu[12] */
/* 007643a0  FUN_007643a0  133 bytes, 0 callers */

undefined4
FUN_007643a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x138) < 2) {
    if (*(int *)(in_ECX + 0xc0) == 2) {
      if (*(int *)(in_ECX + 0xa8) == 0) {
        *(undefined4 *)(in_ECX + 0xa8) = 1;
      }
      else {
        *(undefined4 *)(in_ECX + 0xa8) = 0;
      }
      FUN_00404c80();
      FUN_0056d7d0();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00764910(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiBunkatsu[10] */
/* 00764430  FUN_00764430  1245 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00764430(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_6434 [20];
  int *local_6420;
  int *local_641c;
  int local_6418;
  undefined4 local_f0;
  undefined4 local_ec;
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
  puStack_c = &LAB_009427bb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6418 + 4));
  local_8._0_1_ = 1;
  iVar1 = *(int *)(local_6418 + 4);
  local_24 = *(undefined4 *)(iVar1 + 0x8f68);
  local_20 = *(undefined4 *)(iVar1 + 0x8f6c);
  local_1c = *(undefined4 *)(iVar1 + 0x8f70);
  local_18 = *(undefined4 *)(iVar1 + 0x8f74);
  FUN_0044de00(local_6434,*(undefined4 *)(local_6418 + 4));
  FUN_0044c990(*(undefined4 *)(local_6418 + 4),local_6434);
  FUN_00449d60(local_6434,*(undefined4 *)(local_6418 + 4),1);
  if (*(int *)(*(int *)(local_6418 + 4) + 0x9068) == 0) {
    if (*(int *)(*(int *)(local_6418 + 4) + 0x906c) != 0) {
      if (*(int *)(local_6418 + 0xc0) != 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      iVar1 = FUN_00451eb0(*(undefined4 *)(local_6418 + 4),&local_24,1);
      if (iVar1 != 0) {
        FUN_004988c0(local_44,local_24,local_20,local_1c,local_18);
        *(undefined4 *)(local_6418 + 0xac) = 1;
        *(undefined4 *)(local_6418 + 0xc0) = 2;
        *(undefined4 *)(local_6418 + 0xbc) = *(undefined4 *)(local_6418 + 0xb8);
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
    }
  }
  else {
    if (*(int *)(local_6418 + 0xc0) != 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    local_641c = (int *)0x0;
    local_f0 = 1;
    local_ec = 1;
    iVar1 = FUN_0044a270(3,*(undefined4 *)(local_6418 + 4),&local_24,&local_641c,1);
    if (iVar1 != 0) {
      if (local_641c == (int *)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      if (*(int *)(local_6418 + 0xcc) != 0) {
        local_6420 = *(int **)(local_6418 + 0xcc);
        if (local_6420 != (int *)0x0) {
          (**(code **)(*local_6420 + 4))(1);
        }
        *(undefined4 *)(local_6418 + 0xcc) = 0;
      }
      if (local_641c != (int *)0x0) {
        uVar2 = (**(code **)(*local_641c + 0x14))();
        *(undefined4 *)(local_6418 + 0xcc) = uVar2;
      }
      FUN_004988c0(local_34,local_24,local_20,local_1c,local_18);
      *(undefined4 *)(local_6418 + 0xac) = 0;
      *(undefined4 *)(local_6418 + 0xc0) = 2;
      uVar2 = *(undefined4 *)(*(int *)(local_6418 + 4) + 0x8f5c);
      *(undefined4 *)(local_6418 + 0x130) = *(undefined4 *)(*(int *)(local_6418 + 4) + 0x8f58);
      *(undefined4 *)(local_6418 + 0x134) = uVar2;
      *(undefined4 *)(local_6418 + 0xa8) = 0;
      *(undefined4 *)(local_6418 + 0xbc) = *(undefined4 *)(local_6418 + 0xb8);
      if (*(int *)(local_6418 + 0xcc) == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar1 != 0) {
        FUN_00763bf0();
      }
      FUN_00447b90(local_6434,2,*(undefined4 *)(local_6418 + 4),*(undefined4 *)(local_6418 + 0xcc),1
                   ,1);
      *(undefined4 *)(*(int *)(local_6418 + 4) + 0x85b4) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiBunkatsu[9] */
/* 00764910  FUN_00764910  3456 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00764910(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_6460 [20];
  int *local_644c;
  int local_6448;
  undefined4 local_120;
  undefined4 local_11c;
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
  puStack_c = &LAB_0094280b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6448 + 4));
  local_8._0_1_ = 1;
  FUN_0044de00(local_6460,*(undefined4 *)(local_6448 + 4));
  FUN_0044c990(*(undefined4 *)(local_6448 + 4),local_6460);
  FUN_00449d60(local_6460,*(undefined4 *)(local_6448 + 4),1);
  iVar3 = DAT_00a0cc70;
  DAT_00a0cc74 = 0;
  DAT_00a0cc6c = 0;
  DAT_00a0cc70 = 0;
  *(undefined4 *)(local_6448 + 0xb4) = 0;
  if ((param_1 == 0x231d) || (0 < *(int *)(local_6448 + 0x138))) {
    *(undefined4 *)(local_6448 + 0x134) = 9999;
    *(undefined4 *)(local_6448 + 0x130) = 9999;
    *(undefined4 *)(local_6448 + 0xa8) = 0;
    if (((0 < *(int *)(local_6448 + 0x138)) || (iVar3 == 1)) &&
       ((*(int *)(local_6448 + 0xc0) == 0 || (*(int *)(local_6448 + 0xc0) == 1)))) {
      if (1 < *(int *)(local_6448 + 0x138)) {
        puVar1 = (undefined4 *)(local_6448 + 0x140 + *(int *)(local_6448 + 0x138) * 0x10);
        iVar2 = FUN_00436970(*puVar1,puVar1[1],puVar1[2],puVar1[3],param_2,param_3,param_4,param_5);
        if (iVar2 != 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 1;
        }
      }
      if ((0 < *(int *)(local_6448 + 0x138)) && (*(int *)(local_6448 + 0x138) < 0x7d1)) {
        *(int *)(local_6448 + 0x138) = *(int *)(local_6448 + 0x138) + 1;
      }
      if ((iVar3 == 1) && (*(int *)(local_6448 + 0x138) == 0)) {
        *(undefined4 *)(local_6448 + 0x138) = 1;
        uVar4 = *(undefined4 *)(local_6448 + 0x138);
        uVar5 = 0;
        FUN_00404c80(0,uVar4);
        FUN_004fca20();
        FUN_00417640(uVar5,uVar4);
      }
      FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
      if ((iVar3 == 1) && (1 < *(int *)(local_6448 + 0x138))) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 1;
      }
      if (0 < *(int *)(local_6448 + 0x138)) {
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
    if ((*(int *)(local_6448 + 0xc0) == 0) || (*(int *)(local_6448 + 0xc0) == 1)) {
      FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6448 + 0xac) = 1;
      *(undefined4 *)(local_6448 + 0xc0) = 2;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if (*(int *)(local_6448 + 0xc0) == 2) {
      FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6448 + 0xb0) = 1;
      if (*(int *)(local_6448 + 0xac) != 0) {
        *(undefined4 *)(local_6448 + 0xc0) = 3;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      *(undefined4 *)(local_6448 + 0xc0) = 4;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
  }
  local_644c = (int *)0x0;
  local_120 = 1;
  local_11c = 1;
  iVar3 = FUN_0044a270(3,*(undefined4 *)(local_6448 + 4),&param_2,&local_644c,1);
  if (iVar3 != 0) {
    if ((*(int *)(local_6448 + 0xc0) == 0) || (*(int *)(local_6448 + 0xc0) == 1)) {
      *(undefined4 *)(local_6448 + 0xa8) = 0;
      *(undefined4 *)(local_6448 + 0x7eb0) = 0;
      *(undefined4 *)(local_6448 + 0x7eb4) = 0;
      if (local_644c == (int *)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      if (*(int *)(local_6448 + 0xcc) != 0) {
        if (*(int **)(local_6448 + 0xcc) != (int *)0x0) {
          (**(code **)(**(int **)(local_6448 + 0xcc) + 4))(1);
        }
        *(undefined4 *)(local_6448 + 0xcc) = 0;
      }
      if (local_644c != (int *)0x0) {
        uVar4 = (**(code **)(*local_644c + 0x14))();
        *(undefined4 *)(local_6448 + 0xcc) = uVar4;
      }
      iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if ((iVar3 == 0) && (iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040), iVar3 == 0)) {
        FUN_005168b0(0x1592,*(undefined4 *)(*(int *)(local_6448 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6448 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6448 + 0xac) = 0;
      *(undefined4 *)(local_6448 + 0xc0) = 2;
      uVar4 = *(undefined4 *)(*(int *)(local_6448 + 4) + 0x8f5c);
      *(undefined4 *)(local_6448 + 0x130) = *(undefined4 *)(*(int *)(local_6448 + 4) + 0x8f58);
      *(undefined4 *)(local_6448 + 0x134) = uVar4;
      if (*(int *)(local_6448 + 0xcc) == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar3 != 0) {
        FUN_00763bf0();
      }
      FUN_00447b90(local_6460,2,*(undefined4 *)(local_6448 + 4),*(undefined4 *)(local_6448 + 0xcc),1
                   ,1);
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if (*(int *)(local_6448 + 0xc0) == 2) {
      if (local_644c == (int *)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      if (*(int *)(local_6448 + 0xd0) != 0) {
        if (*(int **)(local_6448 + 0xd0) != (int *)0x0) {
          (**(code **)(**(int **)(local_6448 + 0xd0) + 4))(1);
        }
        *(undefined4 *)(local_6448 + 0xd0) = 0;
      }
      if (local_644c != (int *)0x0) {
        uVar4 = (**(code **)(*local_644c + 0x14))();
        *(undefined4 *)(local_6448 + 0xd0) = uVar4;
      }
      if (*(int *)(local_6448 + 0xd0) == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      if ((*(int *)(local_6448 + 0xac) == 0) && (*(int *)(local_6448 + 0xcc) != 0)) {
        iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar3 == 0) {
          iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
          if ((iVar3 != 0) && (iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040), iVar3 == 0)) {
            FUN_00447b90(local_6460,2,*(undefined4 *)(local_6448 + 4),
                         *(undefined4 *)(local_6448 + 0xcc),1,1);
            FUN_005168b0(0x277e,*(undefined4 *)(*(int *)(local_6448 + 4) + 0x8f24),
                         *(undefined4 *)(*(int *)(local_6448 + 4) + 0x8f28),0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
        }
        else {
          iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
          if (iVar3 == 0) {
            FUN_00447b90(local_6460,2,*(undefined4 *)(local_6448 + 4),
                         *(undefined4 *)(local_6448 + 0xcc),1,1);
            FUN_005168b0(0x156e,*(undefined4 *)(*(int *)(local_6448 + 4) + 0x8f24),
                         *(undefined4 *)(*(int *)(local_6448 + 4) + 0x8f28),0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
        }
      }
      FUN_004988c0(local_74,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6448 + 0xb0) = 0;
      *(undefined4 *)(local_6448 + 0xc0) = 4;
      *(undefined4 *)(local_6448 + 0x134) = 9999;
      *(undefined4 *)(local_6448 + 0x130) = 9999;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
    if (*(int *)(local_6448 + 0xc0) == 3) {
      if (*(int *)(local_6448 + 0xcc) != 0) {
        if (*(int **)(local_6448 + 0xcc) != (int *)0x0) {
          (**(code **)(**(int **)(local_6448 + 0xcc) + 4))(1);
        }
        *(undefined4 *)(local_6448 + 0xcc) = 0;
      }
      if (local_644c != (int *)0x0) {
        uVar4 = (**(code **)(*local_644c + 0x14))();
        *(undefined4 *)(local_6448 + 0xcc) = uVar4;
      }
      FUN_004988c0(local_64,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6448 + 0xc0) = 4;
      *(undefined4 *)(local_6448 + 0xf8) = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukeiBunkatsu[13] */
/* 007656a0  FUN_007656a0  107 bytes, 0 callers */

void FUN_007656a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x138) < 2) {
    FUN_00765710(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    FUN_00765710(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}




/* vtable slots: CZukeiBunkatsu[11] */
/* 00765710  FUN_00765710  3393 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00765710(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_e754 [8];
  undefined1 local_e74c [20];
  undefined4 local_e738;
  undefined4 local_e734;
  undefined4 local_e730;
  undefined4 local_e72c;
  undefined4 local_e728;
  undefined4 local_e724;
  undefined4 local_e720;
  undefined4 local_e71c;
  undefined4 local_e718;
  undefined4 local_e714;
  undefined4 local_e710;
  undefined4 local_e70c;
  undefined4 local_e708;
  undefined4 local_e704;
  undefined4 local_e700;
  undefined4 local_e6fc;
  undefined4 local_e6f8;
  undefined4 local_e6f4;
  int local_e6f0;
  int local_e6ec;
  int local_e6e8;
  int local_e6e4;
  undefined4 local_e6e0;
  int local_e6dc;
  int local_e6d8;
  undefined1 local_7df4 [16];
  undefined1 local_7de4 [16];
  undefined1 local_7dd4 [16];
  undefined1 local_7dc4 [16];
  undefined1 local_7db4 [16];
  undefined1 local_7da4 [16];
  undefined1 local_7d94 [16];
  undefined1 local_7d84 [16];
  undefined1 local_7d74 [16];
  undefined4 local_7d64;
  undefined4 local_7d60;
  undefined4 local_7d5c;
  undefined4 local_7d58;
  undefined4 local_7d54 [8016];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942866;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_7d64 = param_2;
  local_7d60 = param_3;
  local_7d5c = param_4;
  local_7d58 = param_5;
  local_e6f4 = FUN_0040c0e0();
  iVar2 = DAT_00a0cc70;
  local_e6e8 = DAT_00a0cc70;
  DAT_00a0cc74 = 0;
  DAT_00a0cc6c = 0;
  DAT_00a0cc70 = 0;
  *(undefined4 *)(local_e6d8 + 0xb4) = 0;
  if (((0 < *(int *)(local_e6d8 + 0x138)) || (iVar2 == 1)) &&
     ((*(int *)(local_e6d8 + 0xc0) == 0 || (*(int *)(local_e6d8 + 0xc0) == 1)))) {
    if ((iVar2 == 1) && (*(int *)(local_e6d8 + 0x138) == 0)) {
      FUN_00408890(*(undefined4 *)(local_e6d8 + 4));
      local_8._0_1_ = 1;
      FUN_0079dea2(*(undefined4 *)(local_e6d8 + 4));
      local_8._0_1_ = 2;
      local_e6ec = FUN_00410380(local_7d64,local_7d60,local_7d5c,local_7d58,0,0);
      if (local_e6ec == 0) {
        local_e734 = 0;
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00408ab0();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_e734;
      }
      if (local_e6ec == 2) {
        FUN_0044c830(local_e74c,*(undefined4 *)(local_e6d8 + 4));
        FUN_005168b0(0x1614,*(undefined4 *)(*(int *)(local_e6d8 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_e6d8 + 4) + 0x8f28),0,0);
        local_e730 = 0;
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00408ab0();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_e730;
      }
      FUN_00404b80(local_7d54,0x10,0x7d4,FUN_00408a60);
      local_e6f0 = FUN_00572b10();
      while ((local_e6f0 != 0 && (local_e6e4 = FUN_00572b30(&local_e6f0,0), local_e6e4 != 0))) {
        if (*(int *)(local_e6d8 + 0x138) == 0) {
          *(int *)(local_e6d8 + 0x138) = *(int *)(local_e6d8 + 0x138) + 1;
          FUN_004988c0(local_7dc4,*(undefined4 *)(local_e6e4 + 8),*(undefined4 *)(local_e6e4 + 0xc),
                       *(undefined4 *)(local_e6e4 + 0x10),*(undefined4 *)(local_e6e4 + 0x14));
        }
        if (*(int *)(local_e6d8 + 0x138) < 0x7d1) {
          *(int *)(local_e6d8 + 0x138) = *(int *)(local_e6d8 + 0x138) + 1;
          FUN_004988c0(local_7db4,*(undefined4 *)(local_e6e4 + 0x18),
                       *(undefined4 *)(local_e6e4 + 0x1c),*(undefined4 *)(local_e6e4 + 0x20),
                       *(undefined4 *)(local_e6e4 + 0x24));
        }
      }
      for (local_e6dc = 1; local_e6dc <= *(int *)(local_e6d8 + 0x138); local_e6dc = local_e6dc + 1)
      {
        iVar2 = (*(int *)(local_e6d8 + 0x138) - local_e6dc) + 1;
        FUN_004988c0(local_7da4,local_7d54[iVar2 * 4],local_7d54[iVar2 * 4 + 1],
                     local_7d54[iVar2 * 4 + 2],local_7d54[iVar2 * 4 + 3]);
      }
      puVar1 = (undefined4 *)(local_e6d8 + 0x140 + *(int *)(local_e6d8 + 0x138) * 0x10);
      FUN_004fd520(local_e754,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      FUN_0044c830(local_e74c,*(undefined4 *)(local_e6d8 + 4));
      uVar4 = *(undefined4 *)(local_e6d8 + 0x138);
      uVar3 = 0;
      FUN_00404c80(0,uVar4);
      FUN_004fca20();
      FUN_00417640(uVar3,uVar4);
      FUN_00404c80();
      FUN_0056d7d0();
      local_e72c = 0;
      local_8._0_1_ = 1;
      FUN_0079dfff();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00408ab0();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_e72c;
    }
    iVar2 = FUN_00451eb0(*(undefined4 *)(local_e6d8 + 4),&local_7d64,1);
    if (iVar2 == 0) {
      local_e728 = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_e728;
    }
    if (1 < *(int *)(local_e6d8 + 0x138)) {
      puVar1 = (undefined4 *)(local_e6d8 + 0x140 + *(int *)(local_e6d8 + 0x138) * 0x10);
      iVar2 = FUN_00436970(*puVar1,puVar1[1],puVar1[2],puVar1[3],local_7d64,local_7d60,local_7d5c,
                           local_7d58);
      if (iVar2 != 0) {
        local_e724 = 1;
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_e724;
      }
    }
    if ((0 < *(int *)(local_e6d8 + 0x138)) && (*(int *)(local_e6d8 + 0x138) < 0x7d1)) {
      *(int *)(local_e6d8 + 0x138) = *(int *)(local_e6d8 + 0x138) + 1;
    }
    FUN_004988c0(local_7d94,local_7d64,local_7d60,local_7d5c,local_7d58);
    if ((local_e6e8 == 1) && (1 < *(int *)(local_e6d8 + 0x138))) {
      local_e720 = 1;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_e720;
    }
    if (0 < *(int *)(local_e6d8 + 0x138)) {
      FUN_00404c80();
      FUN_0056d7d0();
      local_e71c = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_e71c;
    }
  }
  if (*(int *)(local_e6d8 + 0xc0) == 3) {
    *(undefined4 *)(local_e6d8 + 0xf8) = 0;
    local_e718 = 1;
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else if ((((*(int *)(local_e6d8 + 0xa8) == 0) && (*(int *)(local_e6d8 + 0x7eb0) == 0)) &&
           (*(int *)(local_e6d8 + 0x7eb4) == 0)) || (*(int *)(local_e6d8 + 0xc0) != 2)) {
    *(undefined4 *)(local_e6d8 + 0x134) = 9999;
    *(undefined4 *)(local_e6d8 + 0x130) = 9999;
    *(undefined4 *)(local_e6d8 + 0xa8) = 0;
    *(undefined4 *)(local_e6d8 + 0x7eb0) = 0;
    *(undefined4 *)(local_e6d8 + 0x7eb4) = 0;
    iVar2 = FUN_00451eb0(*(undefined4 *)(local_e6d8 + 4),&local_7d64,1);
    if (iVar2 != 0) {
      if ((*(int *)(local_e6d8 + 0xc0) == 0) || (*(int *)(local_e6d8 + 0xc0) == 1)) {
        FUN_004988c0(local_7d84,local_7d64,local_7d60,local_7d5c,local_7d58);
        *(undefined4 *)(local_e6d8 + 0xac) = 1;
        *(undefined4 *)(local_e6d8 + 0xc0) = 2;
        FUN_00404c80();
        FUN_0056d7d0();
        local_e710 = 0;
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_e710;
      }
      if (*(int *)(local_e6d8 + 0xc0) == 2) {
        iVar2 = FUN_00436970(*(undefined4 *)(local_e6d8 + 0x100),*(undefined4 *)(local_e6d8 + 0x104)
                             ,*(undefined4 *)(local_e6d8 + 0x108),
                             *(undefined4 *)(local_e6d8 + 0x10c),local_7d64,local_7d60,local_7d5c,
                             local_7d58);
        if (iVar2 != 0) {
          *(undefined4 *)(local_e6d8 + 0x138) = 1;
          FUN_004988c0(local_7d74,local_7d64,local_7d60,local_7d5c,local_7d58);
          *(undefined4 *)(local_e6d8 + 0xc0) = 0;
          uVar4 = *(undefined4 *)(local_e6d8 + 0x138);
          uVar3 = 0;
          FUN_00404c80(0,uVar4);
          FUN_004fca20();
          FUN_00417640(uVar3,uVar4);
          local_e70c = 0;
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return local_e70c;
        }
        FUN_004988c0(local_7df4,local_7d64,local_7d60,local_7d5c,local_7d58);
        *(undefined4 *)(local_e6d8 + 0xb0) = 1;
        if (*(int *)(local_e6d8 + 0xac) != 0) {
          *(undefined4 *)(local_e6d8 + 0xc0) = 3;
          FUN_00404c80();
          FUN_0056d7d0();
          local_e708 = 0;
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return local_e708;
        }
        *(undefined4 *)(local_e6d8 + 0xc0) = 4;
        local_e738 = 1;
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_e738;
      }
    }
    if (*(int *)(local_e6d8 + 0xac) == 0) {
      local_e6f8 = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      local_e718 = local_e6f8;
    }
    else {
      local_e6e0 = 0;
      iVar2 = FUN_0044a270(3,*(undefined4 *)(local_e6d8 + 4),&local_7d64,&local_e6e0,1);
      if (iVar2 == 0) {
        uVar3 = 0;
        uVar4 = 0;
        puVar1 = (undefined4 *)FUN_0041c8d0(9999,9999);
        FUN_005168b0(0x14cc,*puVar1,puVar1[1],uVar4,uVar3);
        local_e704 = 0;
        local_8 = 0xffffffff;
        FUN_00447100();
        local_e718 = local_e704;
      }
      else {
        iVar2 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
        if (iVar2 == 0) {
          FUN_005168b0(0x277e,*(undefined4 *)(*(int *)(local_e6d8 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_e6d8 + 4) + 0x8f28),0,0);
          local_e6fc = 0;
          local_8 = 0xffffffff;
          FUN_00447100();
          local_e718 = local_e6fc;
        }
        else {
          FUN_004fb9f0();
          *(undefined4 *)(local_e6d8 + 0xb4) = 1;
          *(undefined4 *)(local_e6d8 + 0xd0) = local_e6e0;
          *(undefined4 *)(local_e6d8 + 0xcc) = local_e6e0;
          FUN_004988c0(local_7de4,*(undefined4 *)(local_e6d8 + 0x100),
                       *(undefined4 *)(local_e6d8 + 0x104),*(undefined4 *)(local_e6d8 + 0x108),
                       *(undefined4 *)(local_e6d8 + 0x10c));
          FUN_004988c0(local_7dd4,local_7d64,local_7d60,local_7d5c,local_7d58);
          local_e700 = 1;
          local_8 = 0xffffffff;
          FUN_00447100();
          local_e718 = local_e700;
        }
      }
    }
  }
  else {
    FUN_00763f20(1);
    local_e714 = 0;
    local_8 = 0xffffffff;
    FUN_00447100();
    local_e718 = local_e714;
  }
  ExceptionList = local_10;
  return local_e718;
}




/* vtable slots: CZukeiBunkatsu[8] */
/* 00766460  FUN_00766460  714 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00766460(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_640c [20];
  int local_63f8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a30b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(local_14);
  iVar1 = FUN_004fca20();
  *(undefined4 *)(local_63f8 + 0x7e80) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x964);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x960) == 0) {
    *(undefined4 *)(local_63f8 + 0xb8) = 0;
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x960) == 1) {
    *(undefined4 *)(local_63f8 + 0xb8) = 0x14;
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(local_63f8 + 0x7e84) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x968);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(local_63f8 + 0x7e88) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x96c);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(local_63f8 + 0x7e8c) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x970);
  if (*(int *)(local_63f8 + 0x7e8c) != 0) {
    *(undefined4 *)(local_63f8 + 0x7e88) = 0;
  }
  if (*(int *)(local_63f8 + 0xb8) != 0) {
    *(undefined4 *)(local_63f8 + 0x7e84) = 0;
    *(undefined4 *)(local_63f8 + 0x7e88) = 0;
    *(undefined4 *)(local_63f8 + 0x7e8c) = 0;
  }
  if (*(int *)(local_63f8 + 0xbc) != *(int *)(local_63f8 + 0xb8)) {
    *(undefined4 *)(local_63f8 + 0xbc) = *(undefined4 *)(local_63f8 + 0xb8);
    *(undefined4 *)(local_63f8 + 0xc0) = 0;
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    puVar2 = (undefined4 *)FUN_00408a30(0,0);
    FUN_00454cb0(0,*(undefined4 *)(local_63f8 + 4),*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    FUN_0044de00(local_640c,*(undefined4 *)(local_63f8 + 4));
    FUN_0044c990(*(undefined4 *)(local_63f8 + 4),local_640c);
    FUN_00449d60();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiBunkatsu[4] */
/* 00766730  FUN_00766730  434 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00766730(void)

{
  undefined1 local_640c [20];
  undefined4 local_63f8;
  undefined4 local_63f4;
  int *local_63f0;
  int *local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092999b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044de00(local_640c,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_640c);
  FUN_00449d60(local_640c,*(undefined4 *)(local_63e8 + 4),1);
  if (*(int *)(local_63e8 + 0xcc) != 0) {
    local_63ec = *(int **)(local_63e8 + 0xcc);
    if (local_63ec == (int *)0x0) {
      local_63f4 = 0;
    }
    else {
      local_63f4 = (**(code **)(*local_63ec + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0xcc) = 0;
  }
  if (*(int *)(local_63e8 + 0xd0) != 0) {
    local_63f0 = *(int **)(local_63e8 + 0xd0);
    if (local_63f0 == (int *)0x0) {
      local_63f8 = 0;
    }
    else {
      local_63f8 = (**(code **)(*local_63f0 + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0xd0) = 0;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiBunkatsu[3] */
/* 007668f0  FUN_007668f0  2994 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007668f0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  float10 fVar4;
  longlong lVar5;
  ulonglong local_6454;
  ulonglong local_644c;
  double local_6444;
  undefined1 local_643c [20];
  int *local_6428;
  int *local_6424;
  int *local_6420;
  int *local_641c;
  int local_6418;
  int local_6414;
  int local_6410;
  int local_640c;
  int local_6408;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009428ab;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00a0cc74 = 0;
  DAT_00a0cc6c = 0;
  DAT_00a0cc70 = 0;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044de00(local_643c,*(undefined4 *)(local_6408 + 4));
  FUN_0044c990(*(undefined4 *)(local_6408 + 4),local_643c);
  FUN_00449d60(local_643c,*(undefined4 *)(local_6408 + 4),1);
  FUN_0044dd90(local_643c,*(undefined4 *)(local_6408 + 4));
  *(undefined8 *)(local_6408 + 0x7e90) = 0x4010000000000000;
  *(undefined8 *)(local_6408 + 0x7ea8) = 0x4059000000000000;
  local_640c = 0;
  if (*(int *)(local_6408 + 0x7e84) == 0) {
    FUN_00404c80();
    FUN_004fca20();
    fVar4 = (float10)FUN_0058cc80();
    *(double *)(local_6408 + 0x7e90) = (double)fVar4;
    if (*(double *)(local_6408 + 0x7e90) < 0.0) {
      *(undefined4 *)(local_6408 + 0x7e98) = 1;
      if (-2.01 < *(double *)(local_6408 + 0x7e90)) {
        *(undefined8 *)(local_6408 + 0x7e90) = 0xc000147ae147ae14;
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        local_6420 = (int *)(*(int *)(iVar2 + 0x1a0) + 0x218);
        (**(code **)(*local_6420 + 0x188))(*(undefined8 *)(local_6408 + 0x7e90));
      }
    }
    else {
      *(undefined4 *)(local_6408 + 0x7e98) = 0;
      if (*(double *)(local_6408 + 0x7e90) <= 1.01 && *(double *)(local_6408 + 0x7e90) != 1.01) {
        *(undefined8 *)(local_6408 + 0x7e90) = 0x3ff028f5c28f5c29;
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        local_641c = (int *)(*(int *)(iVar2 + 0x1a0) + 0x218);
        (**(code **)(*local_641c + 0x188))(*(undefined8 *)(local_6408 + 0x7e90));
      }
    }
    if (*(double *)(local_6408 + 0x7e90) <= 0.0) {
      local_6444 = -*(double *)(local_6408 + 0x7e90);
    }
    else {
      local_6444 = *(double *)(local_6408 + 0x7e90);
    }
    if (10000.0 < local_6444) {
      if (*(double *)(local_6408 + 0x7e90) < 0.0) {
        *(undefined8 *)(local_6408 + 0x7e90) = 0xc0c3880000000000;
      }
      else {
        *(undefined8 *)(local_6408 + 0x7e90) = 0x40c3880000000000;
      }
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      local_6424 = (int *)(*(int *)(iVar2 + 0x1a0) + 0x218);
      (**(code **)(*local_6424 + 0x188))(*(undefined8 *)(local_6408 + 0x7e90));
      FUN_005168b0(0x15ed,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    if (*(double *)(local_6408 + 0x7e90) <= 0.0) {
      local_644c = *(ulonglong *)(local_6408 + 0x7e90) ^ 0x8000000000000000;
    }
    else {
      local_644c = *(ulonglong *)(local_6408 + 0x7e90);
    }
    *(ulonglong *)(local_6408 + 0x7e90) = local_644c;
    *(undefined8 *)(local_6408 + 0x7ea0) = 0x3ff0000000000000;
    if (0.001 <= *(double *)(local_6408 + 0x7e90) - (double)(int)*(double *)(local_6408 + 0x7e90)) {
      *(double *)(local_6408 + 0x7ea0) =
           *(double *)(local_6408 + 0x7e90) - (double)(int)*(double *)(local_6408 + 0x7e90);
    }
  }
  else {
    FUN_00404c80();
    FUN_004fca20();
    fVar4 = (float10)FUN_0058cc80();
    *(double *)(local_6408 + 0x7ea8) = (double)fVar4;
    if (*(double *)(local_6408 + 0x7ea8) <= 0.0) {
      local_6454 = *(ulonglong *)(local_6408 + 0x7ea8) ^ 0x8000000000000000;
    }
    else {
      local_6454 = *(ulonglong *)(local_6408 + 0x7ea8);
    }
    *(ulonglong *)(local_6408 + 0x7ea8) = local_6454;
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    local_6428 = (int *)(*(int *)(iVar2 + 0x1a0) + 0xd0);
    (**(code **)(*local_6428 + 0x188))(*(undefined8 *)(local_6408 + 0x7ea8));
    if (DAT_00a0d62c != 0) {
      *(double *)(local_6408 + 0x7ea8) = *(double *)(local_6408 + 0x7ea8) * DAT_00a0d630;
    }
    *(double *)(local_6408 + 0x7ea8) =
         *(double *)(local_6408 + 0x7ea8) /
         *(double *)
          (*(int *)(local_6408 + 4) + 0x2578 + *(int *)(*(int *)(local_6408 + 4) + 0x256c) * 8);
    if (*(double *)(local_6408 + 0x7ea8) <= 9.999999999999999e-06 &&
        *(double *)(local_6408 + 0x7ea8) != 9.999999999999999e-06) goto LAB_007673bf;
  }
  if (*(int *)(local_6408 + 0x138) == 0) {
    if (*(int *)(local_6408 + 0xb4) == 0) {
      if ((*(int *)(local_6408 + 0xac) == 0) || (*(int *)(local_6408 + 0xb0) == 0)) {
        local_6410 = 0;
        local_6414 = 0;
        if (*(int *)(local_6408 + 0xac) == 0) {
          iVar2 = FUN_0079d98a();
          if (iVar2 != 0) {
            local_6410 = 1;
          }
          iVar2 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
          if (iVar2 != 0) {
            local_6410 = -1;
          }
        }
        if (*(int *)(local_6408 + 0xb0) == 0) {
          iVar2 = FUN_0079d98a();
          if (iVar2 != 0) {
            local_6414 = 1;
          }
          iVar2 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
          if (iVar2 != 0) {
            local_6414 = -1;
          }
        }
        if (((-1 < local_6410) && (0 < local_6414)) || ((0 < local_6410 && (-1 < local_6414)))) {
          if (((*(int *)(local_6408 + 0xb8) == 0) || (local_6414 == 0)) || (local_6410 == 0)) {
            local_640c = FUN_0075d660();
          }
          else {
            local_640c = FUN_0075f690();
          }
        }
        if (((local_6410 < 1) && (local_6414 < 0)) || ((local_6410 < 0 && (local_6414 < 1)))) {
          local_640c = FUN_0075b6c0();
        }
      }
      else if (*(int *)(local_6408 + 0xf8) == 0) {
        local_640c = FUN_007603a0();
      }
      else {
        iVar2 = FUN_0079d98a();
        if (iVar2 == 0) {
          iVar2 = FUN_0079d98a();
          if (iVar2 != 0) {
            if (*(int *)(local_6408 + 0xb8) == 0) {
              local_640c = FUN_00762870();
            }
            else {
              local_640c = FUN_00761c60();
            }
          }
        }
        else {
          local_640c = FUN_00761370();
        }
      }
    }
    else {
      if (*(int *)(local_6408 + 0xb8) == 0) {
        local_640c = FUN_00762870();
      }
      else {
        local_640c = FUN_00761c60();
      }
      *(undefined4 *)(local_6408 + 0xd0) = 0;
      *(undefined4 *)(local_6408 + 0xcc) = 0;
      *(undefined4 *)(local_6408 + 0xb4) = 0;
      *(undefined4 *)(local_6408 + 0xac) = 0;
    }
  }
  else {
    if (*(int *)(local_6408 + 0x138) < 2) {
      *(undefined4 *)(local_6408 + 0x138) = 0;
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    *(undefined4 *)(local_6408 + 0xb0) = 1;
    *(undefined4 *)(local_6408 + 0xac) = 1;
    puVar3 = (undefined4 *)
             FUN_004988c0(local_24,*(undefined4 *)(local_6408 + 0x150),
                          *(undefined4 *)(local_6408 + 0x154),*(undefined4 *)(local_6408 + 0x158),
                          *(undefined4 *)(local_6408 + 0x15c));
    FUN_004988c0(local_34,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
    for (local_6418 = 1; local_6418 < *(int *)(local_6408 + 0x138); local_6418 = local_6418 + 1) {
      puVar3 = (undefined4 *)(local_6408 + 0x140 + (local_6418 + 1) * 0x10);
      puVar1 = (undefined4 *)(local_6408 + 0x140 + local_6418 * 0x10);
      fVar4 = (float10)FUN_0043ad70(*puVar1,puVar1[1],puVar1[2],puVar1[3],*puVar3,puVar3[1],
                                    puVar3[2],puVar3[3]);
      *(double *)(local_6408 + 0x110) = (double)fVar4 + *(double *)(local_6408 + 0x110);
    }
    local_640c = FUN_007603a0();
    *(undefined4 *)(local_6408 + 0xb0) = 0;
    *(undefined4 *)(local_6408 + 0xac) = 0;
    *(undefined4 *)(local_6408 + 0x138) = 0;
  }
LAB_007673bf:
  if (local_640c == 0) {
    FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
  }
  *(undefined4 *)(local_6408 + 0xa8) = 0;
  *(undefined4 *)(local_6408 + 0x7eb0) = 0;
  *(undefined4 *)(local_6408 + 0x7eb4) = 0;
  lVar5 = (ulonglong)*(uint *)(local_6408 + 0x138) << 0x20;
  FUN_00404c80(0,*(uint *)(local_6408 + 0x138));
  FUN_004fca20();
  FUN_00417640(lVar5);
  *(undefined4 *)(local_6408 + 0xc0) = 0;
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



