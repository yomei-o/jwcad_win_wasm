/* CDataSunpou -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataSunpou[1] */
/* 00420b70  FUN_00420b70  68 bytes, 0 callers */

undefined4 FUN_00420b70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041fde0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x498);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataSunpou[14] */
/* 00421370  FUN_00421370  143 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00421370(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00403cd0(local_20c,L"Measure  %d (%g,%g)                                        ",param_3,
               *(undefined8 *)(in_ECX + 8),*(undefined8 *)(in_ECX + 0x10));
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x32,local_20c,uVar1);
  return;
}




/* vtable slots: CDataSunpou[15] */
/* 004252e0  FUN_004252e0  258 bytes, 0 callers */

undefined4 FUN_004252e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1c0) != 0) {
    (**(code **)(*(int *)(in_ECX + 0x1c8) + 0x3c))(param_1,param_2,param_3);
    (**(code **)(*(int *)(in_ECX + 0x2b0) + 0x3c))(param_1,param_2,param_3);
    (**(code **)(*(int *)(in_ECX + 0x398) + 0x3c))(param_1,param_2,param_3);
    (**(code **)(*(int *)(in_ECX + 0x418) + 0x3c))(param_1,param_2,param_3);
  }
  iVar1 = FUN_00424ed0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_0042b460(param_2);
    if (iVar1 == 0) {
      FUN_004240d0(param_1,param_2,param_3);
      FUN_0042e540();
      uVar2 = 1;
    }
    else {
      FUN_0042e540();
      uVar2 = 0;
    }
  }
  return uVar2;
}




/* vtable slots: CDataSunpou[3] */
/* 00429950  FUN_00429950  181 bytes, 0 callers */

void FUN_00429950(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0x68) + 0xc))(param_1);
  (**(code **)(*(int *)(in_ECX + 0xd0) + 0xc))(param_1);
  if (*(int *)(in_ECX + 0x1c0) != 0) {
    (**(code **)(*(int *)(in_ECX + 0x1c8) + 0xc))(param_1);
    (**(code **)(*(int *)(in_ECX + 0x2b0) + 0xc))(param_1);
    (**(code **)(*(int *)(in_ECX + 0x398) + 0xc))(param_1);
    (**(code **)(*(int *)(in_ECX + 0x418) + 0xc))(param_1);
  }
  return;
}




/* vtable slots: CDataSunpou[22] */
/* 0042a0d0  FUN_0042a0d0  203 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_0042a0d0(undefined4 *param_1)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_00408a30(0,0);
  FUN_00498ac0(*(undefined4 *)(in_ECX + 0x70),*(undefined4 *)(in_ECX + 0x74),
               *(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c));
  FUN_00498ac0(*(undefined4 *)(in_ECX + 0x80),*(undefined4 *)(in_ECX + 0x84),
               *(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x8c));
  FUN_00498bf0(0x4000000000000000);
  *param_1 = local_18;
  param_1[1] = local_14;
  param_1[2] = local_10;
  param_1[3] = local_c;
  return param_1;
}




/* vtable slots: CDataSunpou[11] */
/* 0042af20  FUN_0042af20  136 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

double * FUN_0042af20(double *param_1)

{
  double dVar1;
  double dVar2;
  int in_ECX;
  
  FUN_00408a60();
  dVar1 = *(double *)(in_ECX + 0x78);
  dVar2 = *(double *)(in_ECX + 0x88);
  *param_1 = (*(double *)(in_ECX + 0x70) + *(double *)(in_ECX + 0x80)) / 2.0;
  param_1[1] = (dVar1 + dVar2) / 2.0;
  return param_1;
}




/* vtable slots: CDataSunpou[0] */
/* 0042b0d0  FUN_0042b0d0  16 bytes, 0 callers */

undefined ** FUN_0042b0d0(void)

{
  return &PTR_s_CDataSunpou_009fe078;
}




/* vtable slots: CDataSunpou[17] */
/* 0042d7f0  FUN_0042d7f0  403 bytes, 0 callers */

undefined4
FUN_0042d7f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  undefined8 local_20;
  undefined8 local_18;
  
  iVar1 = (**(code **)(*(int *)(in_ECX + 0x68) + 0x44))(param_1,param_2,param_3,param_4,param_5);
  local_18 = *(double *)(param_1 + 0x8ee0);
  if (iVar1 == 0) {
    local_18 = 9e+30;
  }
  iVar2 = (**(code **)(*(int *)(in_ECX + 0xd0) + 0x44))(param_1,param_2,param_3,param_4,param_5);
  if (iVar2 != 0) {
    FUN_005f8940(*(undefined4 *)(in_ECX + 0xd8),*(undefined4 *)(in_ECX + 0xdc),
                 *(undefined4 *)(in_ECX + 0xe0),*(undefined4 *)(in_ECX + 0xe4),
                 *(undefined4 *)(in_ECX + 0xe8),*(undefined4 *)(in_ECX + 0xec),
                 *(undefined4 *)(in_ECX + 0xf0),*(undefined4 *)(in_ECX + 0xf4),param_1);
    fVar4 = (float10)FUN_005f8ca0(1,param_2,param_3,param_4,param_5);
    *(double *)(param_1 + 0x8ee0) = (double)fVar4;
  }
  local_20 = *(double *)(param_1 + 0x8ee0);
  if (iVar2 == 0) {
    local_20 = 9e+30;
  }
  if ((iVar1 == 0) && (iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    if (local_20 <= local_18) {
      *(double *)(param_1 + 0x8ee0) = local_20;
    }
    else {
      *(double *)(param_1 + 0x8ee0) = local_18;
    }
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CDataSunpou[5] */
/* 0042dfb0  FUN_0042dfb0  135 bytes, 2 callers */

undefined4 FUN_0042dfb0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092182f;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_004121b0(0x498);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0041f8d0(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_0042f9b0(local_18);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CDataSunpou[2] */
/* 0042f110  FUN_0042f110  548 bytes, 0 callers */

void FUN_0042f110(CArchive *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0042e690(param_1);
  iVar2 = FUN_0042ddc0();
  iVar1 = DAT_00a0b414;
  if (iVar2 == 0) {
    if (0x15 < DAT_00a0b414) {
      (**(code **)(*(int *)(in_ECX + 0x68) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0xd0) + 8))(param_1);
    }
    if (0x1a3 < iVar1) {
      CArchive::operator>>(param_1,(ushort *)(in_ECX + 0x1c0));
      (**(code **)(*(int *)(in_ECX + 0x1c8) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x2b0) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x398) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x418) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x230) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x318) + 8))(param_1);
    }
  }
  else {
    (**(code **)(*(int *)(in_ECX + 0x68) + 8))(param_1);
    (**(code **)(*(int *)(in_ECX + 0xd0) + 8))(param_1);
    if (0x1a3 < DAT_00a0b3e8) {
      CArchive::operator<<(param_1,*(ushort *)(in_ECX + 0x1c0));
      (**(code **)(*(int *)(in_ECX + 0x1c8) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x2b0) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x398) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x418) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x230) + 8))(param_1);
      (**(code **)(*(int *)(in_ECX + 0x318) + 8))(param_1);
    }
  }
  return;
}




/* vtable slots: CDataSunpou[9] */
/* 0042f680  FUN_0042f680  39 bytes, 0 callers */

void FUN_0042f680(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0042f660(param_1);
  *(undefined2 *)(in_ECX + 0x92) = (undefined2)param_1;
  return;
}




/* vtable slots: CDataSunpou[8] */
/* 0042f6f0  FUN_0042f6f0  37 bytes, 0 callers */

void FUN_0042f6f0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0042f6b0(param_1);
  *(undefined1 *)(in_ECX + 0x90) = (undefined1)param_1;
  return;
}




/* vtable slots: CDataSunpou[6] */
/* 0042f9b0  FUN_0042f9b0  227 bytes, 1 callers */

void FUN_0042f9b0(int param_1)

{
  int in_ECX;
  
  FUN_0042f720(param_1);
  FUN_00420110(in_ECX + 0x68);
  FUN_00481070(in_ECX + 0xd0);
  *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(in_ECX + 0x1c0);
  FUN_00420110(in_ECX + 0x1c8);
  FUN_00420110(in_ECX + 0x2b0);
  FUN_00420430(in_ECX + 0x398);
  FUN_00420430(in_ECX + 0x418);
  FUN_00420430(in_ECX + 0x230);
  FUN_00420430(in_ECX + 0x318);
  return;
}




/* vtable slots: CDataSunpou[4] */
/* 00431020  FUN_00431020  2740 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00431020(int param_1)

{
  int *in_ECX;
  float10 fVar1;
  undefined1 auStack_43c [84];
  undefined4 uStack_3e8;
  uint uStack_3e4;
  undefined8 uStack_3e0;
  undefined4 *puStack_3d8;
  double local_3d4;
  double local_3cc;
  undefined1 *local_3c4;
  undefined1 *local_3c0;
  double local_3bc;
  double local_3b4;
  undefined4 local_3ac;
  undefined4 local_3a8;
  int local_3a4;
  uint local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  double local_38c;
  int *local_384;
  undefined4 local_380;
  undefined1 local_37c [260];
  undefined8 local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 local_248;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  double local_228;
  double local_220;
  double local_218;
  double local_210;
  undefined4 local_208;
  double local_200;
  double local_1f8;
  double local_1f0;
  double local_1e8;
  double local_1e0;
  double local_1d8;
  undefined4 local_1d0;
  double local_1c8;
  double local_1c0;
  double local_1b8;
  double local_1b0;
  double local_1a8;
  double local_1a0;
  int local_198;
  undefined4 local_194;
  double local_190;
  double local_188;
  undefined8 local_180;
  int local_178;
  undefined4 local_174;
  double local_170;
  double local_168;
  undefined8 local_160;
  uint local_158;
  undefined4 local_154;
  undefined1 local_150 [264];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_384 = in_ECX;
  if (in_ECX[0x70] == 0) {
    puStack_3d8 = (undefined4 *)param_1;
    uStack_3e0 = CONCAT44(0x431063,(undefined4)uStack_3e0);
    (**(code **)(in_ECX[0x1a] + 0x10))();
    uStack_3e0 = CONCAT44(param_1,0x431084);
    (**(code **)(local_384[0x34] + 0x10))();
  }
  else {
    local_3a4 = 0;
    puStack_3d8 = (undefined4 *)(uint)*(ushort *)((int)in_ECX + 0x2a);
    uStack_3e0 = (ulonglong)CONCAT14((char)in_ECX[10],(uint)*(byte *)((int)in_ECX + 0x2e));
    uStack_3e4 = (uint)*(byte *)((int)in_ECX + 0x2f);
    uStack_3e8 = 0x4310c7;
    local_238 = FUN_0042afb0();
    puStack_3d8 = (undefined4 *)(uint)*(ushort *)((int)local_384 + 0x2a);
    uStack_3e0 = CONCAT44(0x4310e0,(undefined4)uStack_3e0);
    local_234 = FUN_005db650();
    local_3c0 = auStack_43c;
    FUN_0041f0e0(local_384);
    local_3a8 = FUN_005dbd80();
    local_3c4 = auStack_43c;
    local_230 = local_3a8;
    FUN_0041f0e0(local_384);
    local_3ac = FUN_005dbfa0();
    puStack_3d8 = (undefined4 *)0x43115b;
    local_22c = local_3ac;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x1c);
    uStack_3e4 = 0x431177;
    fVar1 = (float10)FUN_005ea230();
    local_228 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x431190;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x1e);
    uStack_3e4 = 0x4311ac;
    fVar1 = (float10)FUN_005ea290();
    local_220 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x4311c5;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x20);
    uStack_3e4 = 0x4311e4;
    fVar1 = (float10)FUN_005ea230();
    local_218 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x4311fd;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x22);
    uStack_3e4 = 0x43121c;
    fVar1 = (float10)FUN_005ea290();
    local_210 = (double)fVar1;
    if ((((*(double *)(local_384 + 0x74) == 0.0) && (*(double *)(local_384 + 0x76) == 0.0)) &&
        (*(double *)(local_384 + 0x78) == 0.0)) && (*(double *)(local_384 + 0x7a) == 0.0)) {
      local_208 = 0;
    }
    else {
      local_208 = 1;
    }
    puStack_3d8 = (undefined4 *)0x431313;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x8e);
    uStack_3e4 = 0x431332;
    fVar1 = (float10)FUN_005ea230();
    local_200 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x43134b;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x90);
    uStack_3e4 = 0x43136a;
    fVar1 = (float10)FUN_005ea290();
    local_1f8 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x431383;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x74);
    uStack_3e4 = 0x4313a2;
    fVar1 = (float10)FUN_005ea230();
    local_1f0 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x4313bb;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x76);
    uStack_3e4 = 0x4313da;
    fVar1 = (float10)FUN_005ea290();
    local_1e8 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x4313f3;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x78);
    uStack_3e4 = 0x431412;
    fVar1 = (float10)FUN_005ea230();
    local_1e0 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x43142b;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x7a);
    uStack_3e4 = 0x43144a;
    fVar1 = (float10)FUN_005ea290();
    local_1d8 = (double)fVar1;
    if (((*(double *)(local_384 + 0xae) == 0.0) && (*(double *)(local_384 + 0xb0) == 0.0)) &&
       ((*(double *)(local_384 + 0xb2) == 0.0 && (*(double *)(local_384 + 0xb4) == 0.0)))) {
      local_1d0 = 0;
    }
    else {
      local_1d0 = 1;
    }
    puStack_3d8 = (undefined4 *)0x4314d5;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 200);
    uStack_3e4 = 0x4314f4;
    fVar1 = (float10)FUN_005ea230();
    local_1c8 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x43150d;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0xca);
    uStack_3e4 = 0x43152c;
    fVar1 = (float10)FUN_005ea290();
    local_1c0 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x431545;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0xae);
    uStack_3e4 = 0x431564;
    fVar1 = (float10)FUN_005ea230();
    local_1b8 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x43157d;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0xb0);
    uStack_3e4 = 0x43159c;
    fVar1 = (float10)FUN_005ea290();
    local_1b0 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x4315b5;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0xb2);
    uStack_3e4 = 0x4315d4;
    fVar1 = (float10)FUN_005ea230();
    local_1a8 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x4315ed;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0xb4);
    uStack_3e4 = 0x43160c;
    fVar1 = (float10)FUN_005ea290();
    local_1a0 = (double)fVar1;
    local_198 = local_384[0x101];
    puStack_3d8 = (undefined4 *)0x431632;
    fVar1 = (float10)FUN_0042b040();
    local_3cc = (double)fVar1;
    for (local_38c = ((*(double *)(local_384 + 0x102) - local_3cc) / 3.141592653589793) * 180.0;
        180.0 <= local_38c; local_38c = local_38c - 360.0) {
    }
    for (; local_38c < -180.0; local_38c = local_38c + 360.0) {
    }
    if (*(double *)(local_384 + 0x104) == 0.0) {
      local_394 = 0;
    }
    else {
      if (local_38c <= 0.0) {
        local_3b4 = -local_38c;
      }
      else {
        local_3b4 = local_38c;
      }
      if (90.0 <= local_3b4) {
        local_390 = 1;
      }
      else {
        local_390 = 2;
      }
      local_394 = local_390;
    }
    local_194 = local_394;
    puStack_3d8 = (undefined4 *)0x43176f;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0xe8);
    uStack_3e4 = 0x43178e;
    fVar1 = (float10)FUN_005ea230();
    local_190 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x4317a7;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0xea);
    uStack_3e4 = 0x4317c6;
    fVar1 = (float10)FUN_005ea290();
    local_188 = (double)fVar1;
    local_180 = *(undefined8 *)(local_384 + 0x104);
    local_178 = local_384[0x121];
    puStack_3d8 = (undefined4 *)0x431802;
    fVar1 = (float10)FUN_0042b040();
    local_3d4 = (double)fVar1;
    for (local_38c = ((*(double *)(local_384 + 0x122) - local_3d4) / 3.141592653589793) * 180.0;
        180.0 <= local_38c; local_38c = local_38c - 360.0) {
    }
    for (; local_38c < -180.0; local_38c = local_38c + 360.0) {
    }
    if (*(double *)(local_384 + 0x124) == 0.0) {
      local_39c = 0;
    }
    else {
      if (local_38c <= 0.0) {
        local_3bc = -local_38c;
      }
      else {
        local_3bc = local_38c;
      }
      if (90.0 <= local_3bc) {
        local_398 = 2;
      }
      else {
        local_398 = 1;
      }
      local_39c = local_398;
    }
    local_174 = local_39c;
    puStack_3d8 = (undefined4 *)0x43193f;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x108);
    uStack_3e4 = 0x43195e;
    fVar1 = (float10)FUN_005ea230();
    local_170 = (double)fVar1;
    puStack_3d8 = (undefined4 *)0x431977;
    puStack_3d8 = (undefined4 *)(**(code **)(*local_384 + 0x28))();
    uStack_3e0 = *(ulonglong *)(local_384 + 0x10a);
    uStack_3e4 = 0x431996;
    fVar1 = (float10)FUN_005ea290();
    local_168 = (double)fVar1;
    local_160 = *(undefined8 *)(local_384 + 0x124);
    local_3a0 = (uint)(*(double *)(local_384 + 100) != 0.0);
    local_158 = local_3a0;
    puStack_3d8 = (undefined4 *)param_1;
    uStack_3e0 = CONCAT44(&local_380,0x431a07);
    FUN_0048d690();
    puStack_3d8 = (undefined4 *)local_37c;
    uStack_3e0 = CONCAT44(local_150,0x431a1a);
    FUN_0041efc0();
    local_154 = local_380;
    local_48 = local_278;
    local_40 = local_270;
    local_38 = local_268;
    local_30 = local_260;
    local_28 = local_258;
    local_20 = local_250;
    local_18 = local_248;
    local_c = local_23c;
    local_10 = local_240;
    puStack_3d8 = &local_238;
    uStack_3e0._4_4_ = "LINEAR_DIMENSION";
    uStack_3e0._0_4_ = 0x431aad;
    local_3a4 = (**(code **)(param_1 + 0x4c158))();
    if (local_3a4 < 0) {
      uStack_3e0 = CONCAT44(uStack_3e0._4_4_,0x431ac4);
      FUN_005e6520();
    }
  }
  return;
}




/* vtable slots: CDataSunpou[7] */
/* 00438cb0  FUN_00438cb0  448 bytes, 0 callers */

undefined4 FUN_00438cb0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_00438910(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = (**(code **)(*(int *)(in_ECX + 0x68) + 0x1c))(param_1 + 0x68);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        iVar1 = (**(code **)(*(int *)(in_ECX + 0xd0) + 0x1c))(param_1 + 0xd0);
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else if (*(int *)(in_ECX + 0x1c0) == *(int *)(param_1 + 0x1c0)) {
          if (*(int *)(in_ECX + 0x1c0) == 0) {
            uVar2 = 1;
          }
          else {
            iVar1 = (**(code **)(*(int *)(in_ECX + 0x1c8) + 0x1c))(param_1 + 0x1c8);
            if (iVar1 == 0) {
              uVar2 = 0;
            }
            else {
              iVar1 = (**(code **)(*(int *)(in_ECX + 0x2b0) + 0x1c))(param_1 + 0x2b0);
              if (iVar1 == 0) {
                uVar2 = 0;
              }
              else {
                iVar1 = (**(code **)(*(int *)(in_ECX + 0x398) + 0x1c))(param_1 + 0x398);
                if (iVar1 == 0) {
                  uVar2 = 0;
                }
                else {
                  iVar1 = (**(code **)(*(int *)(in_ECX + 0x418) + 0x1c))(param_1 + 0x418);
                  if (iVar1 == 0) {
                    uVar2 = 0;
                  }
                  else {
                    iVar1 = (**(code **)(*(int *)(in_ECX + 0x230) + 0x1c))(param_1 + 0x230);
                    if (iVar1 == 0) {
                      uVar2 = 0;
                    }
                    else {
                      iVar1 = (**(code **)(*(int *)(in_ECX + 0x318) + 0x1c))(param_1 + 0x318);
                      if (iVar1 == 0) {
                        uVar2 = 0;
                      }
                      else {
                        uVar2 = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}




/* vtable slots: CDataSunpou[13] */
/* 0043b330  FUN_0043b330  133 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0043b330(void)

{
  int in_ECX;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 0x70),*(undefined4 *)(in_ECX + 0x74),
               *(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c));
  FUN_004988c0(local_28,*(undefined4 *)(in_ECX + 0x80),*(undefined4 *)(in_ECX + 0x84),
               *(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x8c));
  return 2;
}



