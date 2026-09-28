/* CZukeiKyori -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiKyori[1] */
/* 006b90b0  FUN_006b90b0  68 bytes, 0 callers */

undefined4 FUN_006b90b0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006b9040();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x2060);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiKyori[6] */
/* 006b9100  FUN_006b9100  197 bytes, 0 callers */

void FUN_006b9100(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0xf0) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x964);
  if (*(int *)(*(int *)(in_ECX + 4) + 0x17f0) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x17f0) = 0;
    FUN_006baa70();
  }
  if ((*(int *)(in_ECX + 0xa8) == 0) || (*(int *)(in_ECX + 0xa8) == 1)) {
    FUN_004efbb0(0x14c8,0,0);
  }
  if (*(int *)(in_ECX + 0xa8) == 2) {
    FUN_004efbb0(0x1556,0,0);
  }
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_0058cc80();
  *(double *)(in_ECX + 0xf8) = (double)fVar2;
  return;
}




/* vtable slots: CZukeiKyori[16] */
/* 006b91d0  FUN_006b91d0  147 bytes, 0 callers */

undefined4 FUN_006b91d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xa8) == 0) || (*(int *)(in_ECX + 0xa8) == 1)) {
    if (0 < *(int *)(in_ECX + 0xb0)) {
      *(int *)(in_ECX + 0xb0) = *(int *)(in_ECX + 0xb0) + -1;
    }
    FUN_006baa70();
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 0;
  }
  else {
    if (*(int *)(in_ECX + 0xa8) == 2) {
      *(undefined4 *)(in_ECX + 0xac) = 0;
      *(undefined4 *)(in_ECX + 0xa8) = 0;
    }
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CZukeiKyori[0] */
/* 006b9930  FUN_006b9930  16 bytes, 0 callers */

undefined ** FUN_006b9930(void)

{
  return &PTR_s_CZukeiKyori_00979a70;
}




/* vtable slots: CZukeiKyori[46] */
/* 006b9ee0  FUN_006b9ee0  456 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006b9ee0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (DAT_00a0c7c0 == 0) {
    if (in_ECX[0x36] != 0) {
      if ((int *)in_ECX[0x36] != (int *)0x0) {
        (**(code **)(*(int *)in_ECX[0x36] + 4))(1);
      }
      in_ECX[0x36] = 0;
    }
    if (*(int *)(in_ECX[1] + 0x9078) == 0) {
      if ((param_2 == 0xc) && (in_ECX[0x2a] == 2)) {
        if (param_3 == 1) {
          FUN_005168b0(0x1488,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_004988c0(local_18,param_4,param_5,param_6,param_7);
          in_ECX[0x2a] = 4;
          (**(code **)(*in_ECX + 0xc))();
        }
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiKyori[27] */
/* 006ba0b0  FUN_006ba0b0  64 bytes, 0 callers */

void FUN_006ba0b0(void)

{
  int *in_ECX;
  
  if (in_ECX[0x2c] != 0) {
    in_ECX[0x2b] = 0;
    in_ECX[0x2a] = 4;
    (**(code **)(*in_ECX + 0xc))();
  }
  return;
}




/* vtable slots: CZukeiKyori[50] */
/* 006ba0f0  FUN_006ba0f0  141 bytes, 0 callers */

void FUN_006ba0f0(double param_1)

{
  int iVar1;
  
  if (DAT_00a0d62c != 0) {
    param_1 = param_1 / DAT_00a0d630;
  }
  if (param_1 <= 0.0) {
    param_1 = -param_1;
  }
  FUN_00404c80(param_1);
  iVar1 = FUN_004fca20();
  (**(code **)(*(int *)(*(int *)(iVar1 + 0x1a0) + 0xd0) + 0x188))(param_1);
  return;
}




/* vtable slots: CZukeiKyori[51] */
/* 006ba180  FUN_006ba180  235 bytes, 0 callers */

void FUN_006ba180(undefined4 param_1,undefined4 param_2,double param_3)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093cd2d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80();
  FUN_004fca20();
  FUN_004183a0();
  if (DAT_00a0d62c != 0) {
    param_3 = param_3 / DAT_00a0d630;
  }
  if (param_3 <= 0.0) {
    param_3 = -param_3;
  }
  FUN_00404c80(uVar1,param_3);
  iVar2 = FUN_004fca20();
  (**(code **)(*(int *)(*(int *)(iVar2 + 0x1a0) + 0xd0) + 0x188))(param_3);
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKyori[15] */
/* 006ba270  FUN_006ba270  72 bytes, 0 callers */

undefined4 FUN_006ba270(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  FUN_006baa70();
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  FUN_00404c80();
  FUN_0056d7d0();
  return 0;
}




/* vtable slots: CZukeiKyori[9] */
/* 006ba2c0  FUN_006ba2c0  1325 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006ba2c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *local_643c;
  int local_6438;
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093cd6b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6438 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined4 *)(local_6438 + 0xb0) = 0;
  FUN_006baa70();
  FUN_00404c80();
  FUN_004fca20();
  FUN_00797df8();
  if (*(int *)(local_6438 + 0xd8) != 0) {
    if (*(int **)(local_6438 + 0xd8) != (int *)0x0) {
      (**(code **)(**(int **)(local_6438 + 0xd8) + 4))(1);
    }
    *(undefined4 *)(local_6438 + 0xd8) = 0;
  }
  if (param_1 == 0x231d) {
    if ((*(int *)(local_6438 + 0xa8) == 0) || (*(int *)(local_6438 + 0xa8) == 1)) {
      *(undefined4 *)(local_6438 + 0xac) = 0x231d;
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6438 + 0xa8) = 2;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if (*(int *)(local_6438 + 0xa8) == 2) {
      FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6438 + 0xa8) = 4;
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
  }
  if ((*(int *)(local_6438 + 0xa8) == 0) || (*(int *)(local_6438 + 0xa8) == 1)) {
    if (*(int *)(local_6438 + 0xd8) != 0) {
      if (*(int **)(local_6438 + 0xd8) != (int *)0x0) {
        (**(code **)(**(int **)(local_6438 + 0xd8) + 4))(1);
      }
      *(undefined4 *)(local_6438 + 0xd8) = 0;
    }
    FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
    *(undefined4 *)(local_6438 + 0xac) = 1;
    *(undefined4 *)(local_6438 + 0xa8) = 2;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 0;
  }
  else {
    local_643c = (int *)0x0;
    local_110 = 1;
    local_10c = 1;
    iVar1 = FUN_0044a270(3,*(undefined4 *)(local_6438 + 4),&param_2,&local_643c,1);
    if ((iVar1 == 0) || (*(int *)(local_6438 + 0xa8) != 2)) {
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 0;
    }
    else {
      if (*(int *)(local_6438 + 0xd8) != 0) {
        if (*(int **)(local_6438 + 0xd8) != (int *)0x0) {
          (**(code **)(**(int **)(local_6438 + 0xd8) + 4))(1);
        }
        *(undefined4 *)(local_6438 + 0xd8) = 0;
      }
      if (local_643c != (int *)0x0) {
        uVar2 = (**(code **)(*local_643c + 0x14))();
        *(undefined4 *)(local_6438 + 0xd8) = uVar2;
      }
      puVar3 = (undefined4 *)FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
      FUN_004988c0(local_64,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
      *(undefined4 *)(local_6438 + 0xa8) = 4;
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 1;
    }
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiKyori[11] */
/* 006ba7f0  FUN_006ba7f0  626 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006ba7f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  undefined1 local_44 [16];
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
  puStack_c = &LAB_0093cdb0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  FUN_006baa70();
  FUN_00404c80();
  FUN_004fca20();
  FUN_00797df8();
  if (*(int *)(in_ECX + 0xd8) != 0) {
    if (*(int **)(in_ECX + 0xd8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0xd8) + 4))(1);
    }
    *(undefined4 *)(in_ECX + 0xd8) = 0;
  }
  iVar1 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 0xa8) == 0) || (*(int *)(in_ECX + 0xa8) == 1)) {
      FUN_004988c0(local_34,local_24,local_20,local_1c,local_18);
      *(undefined4 *)(in_ECX + 0xac) = 0;
      *(undefined4 *)(in_ECX + 0xa8) = 2;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if (*(int *)(in_ECX + 0xa8) == 2) {
      FUN_004988c0(local_44,local_24,local_20,local_1c,local_18);
      *(undefined4 *)(in_ECX + 0xa8) = 4;
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 1;
    }
  }
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukeiKyori[3] */
/* 006baad0  FUN_006baad0  807 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006baad0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  int *local_63f0;
  int local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937dcb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63f4 = 4;
  *(undefined8 *)(in_ECX + 0xf8) = 0x4059000000000000;
  local_63e8 = in_ECX;
  FUN_00404c80(local_14);
  FUN_004fca20();
  fVar2 = (float10)FUN_0058cc80();
  *(double *)(local_63e8 + 0xf8) = (double)fVar2;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  local_63f0 = (int *)(*(int *)(iVar1 + 0x1a0) + 0xd0);
  (**(code **)(*local_63f0 + 0x188))(*(undefined8 *)(local_63e8 + 0xf8));
  FUN_00404c80();
  FUN_004fca20();
  FUN_00797df8();
  *(double *)(local_63e8 + 0xf8) =
       *(double *)(local_63e8 + 0xf8) /
       *(double *)
        (*(int *)(local_63e8 + 4) + 0x2578 + *(int *)(*(int *)(local_63e8 + 4) + 0x256c) * 8);
  if (DAT_00a0d62c != 0) {
    *(double *)(local_63e8 + 0xf8) = *(double *)(local_63e8 + 0xf8) * DAT_00a0d630;
  }
  local_63ec = 0;
  *(int *)(local_63e8 + 0xb0) = *(int *)(local_63e8 + 0xb0) + 1;
  if (*(int *)(local_63e8 + 0xb0) < 1) {
    *(undefined4 *)(local_63e8 + 0xb0) = 1;
  }
  if (*(int *)(local_63e8 + 0xb0) < 1000) {
    if (*(int *)(local_63e8 + 0xd8) == 0) {
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
      local_8._0_1_ = 1;
      local_63ec = FUN_006b9940(local_63e4,local_6408);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar1 == 0) {
        iVar1 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
        if (iVar1 != 0) {
          local_63ec = FUN_006b9270();
        }
      }
      else {
        local_63ec = FUN_006b9c40();
      }
    }
  }
  if (local_63ec == 0) {
    FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f28),0,0);
    *(undefined4 *)(local_63e8 + 0xb0) = 0;
  }
  *(undefined4 *)(local_63e8 + 0xac) = 0;
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8578) = 1;
  FUN_006baa70();
  *(undefined4 *)(local_63e8 + 0xa8) = 0;
  FUN_00404c80();
  FUN_0056d200();
  ExceptionList = local_10;
  return;
}



