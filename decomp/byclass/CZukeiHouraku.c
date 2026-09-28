/* CZukeiHouraku -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiHouraku[1] */
/* 0067eca0  FUN_0067eca0  68 bytes, 0 callers */

undefined4 FUN_0067eca0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0067ec50();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x470);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiHouraku[6] */
/* 0067ecf0  FUN_0067ecf0  546 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067ecf0(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_641c [20];
  int *local_6408;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a95b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00683e00(1);
  if (local_6408[0x7e] != 0) {
    FUN_00446aa0(uVar1);
    local_8 = 0;
    FUN_0079dea2(local_6408[1]);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar2 = FUN_0040c0e0();
    FUN_0044dd90(local_641c,local_6408[1]);
    FUN_004988c0(local_24,local_6408[4],local_6408[5],local_6408[6],local_6408[7]);
    if (local_6408[0x7e] == 2) {
      FUN_004988c0(local_34,*param_1,param_1[1],param_1[2],param_1[3]);
      (**(code **)(*local_6408 + 0x20))(uVar1,uVar2);
      FUN_00450b70(local_641c,local_6408[1],local_6408 + 0xa0);
      FUN_00450b70(local_641c,local_6408[1],local_6408 + 0xba);
      FUN_00450b70(local_641c,local_6408[1],local_6408 + 0xd4);
      FUN_00450b70(local_641c,local_6408[1],local_6408 + 0xee);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHouraku[16] */
/* 0067ef20  FUN_0067ef20  317 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0067ef20(void)

{
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
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  if (*(int *)(local_63e8 + 0x1f8) == 2) {
    local_63f4 = FUN_0040c0e0();
    FUN_0044dd90(local_6408,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(local_63e8 + 0x1f8) = 0;
    FUN_00683e00(1);
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_63f0 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_63ec = local_63f0;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiHouraku[0] */
/* 0067f0a0  FUN_0067f0a0  16 bytes, 0 callers */

undefined ** FUN_0067f0a0(void)

{
  return &PTR_s_CZukeiHouraku_00978c20;
}




/* vtable slots: CZukeiHouraku[46] */
/* 00683f10  FUN_00683f10  545 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00683f10(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 local_40;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  in_ECX[0x108] = 0;
  in_ECX[0x109] = 0;
  iVar1 = in_ECX[1];
  FUN_004988c0(local_18,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
               *(undefined4 *)(iVar1 + 0x8f70),*(undefined4 *)(iVar1 + 0x8f74));
  local_40 = 0;
  if (in_ECX[0x7e] == 0) {
    local_40 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else if (*(int *)(in_ECX[1] + 0x9078) == 0) {
    if (param_2 == 9) {
      if (param_3 == 1) {
        FUN_005168b0(0x2784,*(undefined4 *)(in_ECX[1] + 0x8f50),*(undefined4 *)(in_ECX[1] + 0x8f54),
                     1,0);
      }
      else if (param_3 == 2) {
        in_ECX[0x7e] = 3;
        iVar1 = in_ECX[1];
        puVar2 = (undefined4 *)
                 FUN_004988c0(local_28,*(undefined4 *)(iVar1 + 0x8f68),
                              *(undefined4 *)(iVar1 + 0x8f6c),*(undefined4 *)(iVar1 + 0x8f70),
                              *(undefined4 *)(iVar1 + 0x8f74));
        FUN_004988c0(local_38,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
        in_ECX[0x109] = 1;
        (**(code **)(*in_ECX + 0xc))();
      }
    }
    else {
      local_40 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_40 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_40;
}




/* vtable slots: CZukeiHouraku[10] */
/* 00684140  FUN_00684140  252 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00684140(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(*(int *)(in_ECX + 4) + 0x9068) != 0) ||
     (*(int *)(*(int *)(in_ECX + 4) + 0x906c) != 0)) {
    *(undefined4 *)(in_ECX + 0x1f8) = 2;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x90c8) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x90cc) = 0;
    iVar1 = *(int *)(in_ECX + 4);
    puVar2 = (undefined4 *)
             FUN_004988c0(local_18,*(undefined4 *)(iVar1 + 0x8f98),*(undefined4 *)(iVar1 + 0x8f9c),
                          *(undefined4 *)(iVar1 + 0x8fa0),*(undefined4 *)(iVar1 + 0x8fa4));
    FUN_004988c0(local_28,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    *(undefined4 *)(in_ECX + 0x428) = 1;
  }
  FUN_00683e00(1);
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  return;
}




/* vtable slots: CZukeiHouraku[9] */
/* 00684240  FUN_00684240  351 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00684240(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 0x420) = 0;
  *(undefined4 *)(in_ECX + 0x424) = 0;
  if (*(int *)(in_ECX + 0x1f8) == 0) {
    *(undefined4 *)(in_ECX + 0x1f8) = 2;
    *(undefined4 *)(in_ECX + 0x428) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x90c8) = 0;
    puVar1 = (undefined4 *)FUN_004988c0(local_18,param_2,param_3,param_4,param_5);
    FUN_004988c0(local_28,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    FUN_00404c80();
    FUN_0056d7d0();
    DAT_00a0cc6c = 0;
    uVar2 = 0;
  }
  else if (*(int *)(in_ECX + 0x1f8) == 2) {
    if (DAT_00a0cc6c != 0) {
      *(undefined4 *)(in_ECX + 0x424) = 1;
    }
    DAT_00a0cc6c = 0;
    *(undefined4 *)(in_ECX + 0x1f8) = 3;
    FUN_004988c0(local_38,param_2,param_3,param_4,param_5);
    FUN_00404c80();
    FUN_0056d7d0();
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiHouraku[11] */
/* 006843a0  FUN_006843a0  332 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006843a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  DAT_00a0cc6c = 0;
  *(undefined4 *)(in_ECX + 0x420) = 0;
  *(undefined4 *)(in_ECX + 0x424) = 0;
  if (*(int *)(in_ECX + 0x1f8) == 0) {
    *(undefined4 *)(in_ECX + 0x1f8) = 2;
    *(undefined4 *)(in_ECX + 0x428) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x90cc) = 0;
    puVar1 = (undefined4 *)FUN_004988c0(local_18,param_2,param_3,param_4,param_5);
    FUN_004988c0(local_28,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    FUN_00404c80();
    FUN_0056d7d0();
    uVar2 = 0;
  }
  else if (*(int *)(in_ECX + 0x1f8) == 2) {
    *(undefined4 *)(in_ECX + 0x1f8) = 3;
    FUN_004988c0(local_38,param_2,param_3,param_4,param_5);
    *(undefined4 *)(in_ECX + 0x420) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiHouraku[8] */
/* 006844f0  FUN_006844f0  1899 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006844f0(void)

{
  ulonglong uVar1;
  int in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_c;
  
  *(double *)(in_ECX + 0x430) =
       (*(double *)(*(int *)(in_ECX + 4) + 0x17c0) * 3.141592653589793) / 180.0;
  fVar2 = (float10)FUN_008f8eb0(*(undefined8 *)(in_ECX + 0x430));
  *(double *)(in_ECX + 0x438) = (double)fVar2;
  fVar2 = (float10)FUN_008f8f00(*(undefined8 *)(in_ECX + 0x430));
  *(double *)(in_ECX + 0x440) = (double)fVar2;
  if (*(int *)(in_ECX + 0x1f8) == 2) {
    dVar6 = *(double *)(in_ECX + 0x220) - *(double *)(in_ECX + 0x200);
    dVar7 = *(double *)(in_ECX + 0x228) - *(double *)(in_ECX + 0x208);
    dVar8 = *(double *)(in_ECX + 0x438) * dVar6 + *(double *)(in_ECX + 0x440) * dVar7;
    dVar6 = *(double *)(in_ECX + 0x438) * dVar7 - *(double *)(in_ECX + 0x440) * dVar6;
    if (((0.0 < dVar8) && (0.0 < dVar6)) || ((dVar8 < 0.0 && (dVar6 < 0.0)))) {
      *(undefined8 *)(in_ECX + 0x240) = 0;
      *(undefined8 *)(in_ECX + 0x248) = 0;
      *(double *)(in_ECX + 0x250) = dVar8;
      *(undefined8 *)(in_ECX + 600) = 0;
      *(double *)(in_ECX + 0x260) = dVar8;
      *(double *)(in_ECX + 0x268) = dVar6;
      *(undefined8 *)(in_ECX + 0x270) = 0;
      *(double *)(in_ECX + 0x278) = dVar6;
    }
    else {
      *(undefined8 *)(in_ECX + 0x240) = 0;
      *(undefined8 *)(in_ECX + 0x248) = 0;
      *(undefined8 *)(in_ECX + 0x250) = 0;
      *(double *)(in_ECX + 600) = dVar6;
      *(double *)(in_ECX + 0x260) = dVar8;
      *(double *)(in_ECX + 0x268) = dVar6;
      *(double *)(in_ECX + 0x270) = dVar8;
      *(undefined8 *)(in_ECX + 0x278) = 0;
    }
    *(double *)(in_ECX + 0x220) =
         (*(double *)(in_ECX + 0x438) * *(double *)(in_ECX + 0x260) -
         *(double *)(in_ECX + 0x440) * *(double *)(in_ECX + 0x268)) + *(double *)(in_ECX + 0x200);
    *(double *)(in_ECX + 0x228) =
         *(double *)(in_ECX + 0x438) * *(double *)(in_ECX + 0x268) +
         *(double *)(in_ECX + 0x440) * *(double *)(in_ECX + 0x260) + *(double *)(in_ECX + 0x208);
    *(double *)(in_ECX + 0x210) =
         (*(double *)(in_ECX + 0x438) * *(double *)(in_ECX + 0x250) -
         *(double *)(in_ECX + 0x440) * *(double *)(in_ECX + 600)) + *(double *)(in_ECX + 0x200);
    *(double *)(in_ECX + 0x218) =
         *(double *)(in_ECX + 0x438) * *(double *)(in_ECX + 600) +
         *(double *)(in_ECX + 0x440) * *(double *)(in_ECX + 0x250) + *(double *)(in_ECX + 0x208);
    *(double *)(in_ECX + 0x230) =
         (*(double *)(in_ECX + 0x438) * *(double *)(in_ECX + 0x270) -
         *(double *)(in_ECX + 0x440) * *(double *)(in_ECX + 0x278)) + *(double *)(in_ECX + 0x200);
    *(double *)(in_ECX + 0x238) =
         *(double *)(in_ECX + 0x438) * *(double *)(in_ECX + 0x278) +
         *(double *)(in_ECX + 0x440) * *(double *)(in_ECX + 0x270) + *(double *)(in_ECX + 0x208);
    uVar1 = *(ulonglong *)(*(int *)(in_ECX + 4) + 0x17b8);
    FUN_00408a60();
    FUN_00408a60();
    FUN_00684c60(*(undefined4 *)(in_ECX + 0x200),*(undefined4 *)(in_ECX + 0x204),
                 *(undefined4 *)(in_ECX + 0x208),*(undefined4 *)(in_ECX + 0x20c),
                 *(undefined4 *)(in_ECX + 0x210),*(undefined4 *)(in_ECX + 0x214),
                 *(undefined4 *)(in_ECX + 0x218),*(undefined4 *)(in_ECX + 0x21c));
    fVar2 = (float10)FUN_0067f0f0(0,uVar1 ^ 0x8000000000000000,0);
    fVar3 = (float10)FUN_0067f180(0,uVar1 ^ 0x8000000000000000,0);
    fVar4 = (float10)FUN_0067f0f0(0,uVar1,0);
    fVar5 = (float10)FUN_0067f180(0,uVar1,0);
    uStack_14 = (undefined4)((ulonglong)(double)fVar2 >> 0x20);
    uStack_c = (undefined4)((ulonglong)(double)fVar3 >> 0x20);
    FUN_0040da70(SUB84((double)fVar2,0),uStack_14,SUB84((double)fVar3,0),uStack_c);
    uStack_24 = (undefined4)((ulonglong)(double)fVar4 >> 0x20);
    uStack_1c = (undefined4)((ulonglong)(double)fVar5 >> 0x20);
    FUN_0040da20(SUB84((double)fVar4,0),uStack_24,SUB84((double)fVar5,0),uStack_1c);
    FUN_0040da70(*(undefined4 *)(in_ECX + 0x210),*(undefined4 *)(in_ECX + 0x214),
                 *(undefined4 *)(in_ECX + 0x218),*(undefined4 *)(in_ECX + 0x21c));
    FUN_0040da20(*(undefined4 *)(in_ECX + 0x220),*(undefined4 *)(in_ECX + 0x224),
                 *(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c));
    FUN_0040da70(*(undefined4 *)(in_ECX + 0x220),*(undefined4 *)(in_ECX + 0x224),
                 *(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c));
    FUN_0040da20(*(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
                 *(undefined4 *)(in_ECX + 0x238),*(undefined4 *)(in_ECX + 0x23c));
    FUN_00684c60(*(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
                 *(undefined4 *)(in_ECX + 0x238),*(undefined4 *)(in_ECX + 0x23c),
                 *(undefined4 *)(in_ECX + 0x200),*(undefined4 *)(in_ECX + 0x204),
                 *(undefined4 *)(in_ECX + 0x208),*(undefined4 *)(in_ECX + 0x20c));
    fVar2 = (float10)FUN_0067f0f0(0,uVar1 ^ 0x8000000000000000,0);
    fVar3 = (float10)FUN_0067f180(0,uVar1 ^ 0x8000000000000000,0);
    fVar4 = (float10)FUN_0067f0f0(0,uVar1,0);
    fVar5 = (float10)FUN_0067f180(0,uVar1,0);
    uStack_14 = (undefined4)((ulonglong)(double)fVar2 >> 0x20);
    uStack_c = (undefined4)((ulonglong)(double)fVar3 >> 0x20);
    FUN_0040da70(SUB84((double)fVar2,0),uStack_14,SUB84((double)fVar3,0),uStack_c);
    uStack_24 = (undefined4)((ulonglong)(double)fVar4 >> 0x20);
    uStack_1c = (undefined4)((ulonglong)(double)fVar5 >> 0x20);
    FUN_0040da20(SUB84((double)fVar4,0),uStack_24,SUB84((double)fVar5,0),uStack_1c);
  }
  return;
}




/* vtable slots: CZukeiHouraku[3] */
/* 00684dc0  FUN_00684dc0  449 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00684dc0(void)

{
  int in_ECX;
  undefined1 local_641c [20];
  int local_6408;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937a1b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x1f8) = 0;
  local_6408 = in_ECX;
  FUN_00408a60(local_14);
  FUN_00408a60();
  local_34 = *(undefined8 *)(local_6408 + 0x10);
  local_2c = *(undefined8 *)(local_6408 + 0x18);
  local_24 = *(undefined8 *)(local_6408 + 0x20);
  local_1c = *(undefined8 *)(local_6408 + 0x28);
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_641c,*(undefined4 *)(local_6408 + 4));
  FUN_0067f210((undefined4)local_34,local_34._4_4_,(undefined4)local_2c,local_2c._4_4_,
               (undefined4)local_24,local_24._4_4_,(undefined4)local_1c,local_1c._4_4_);
  *(undefined4 *)(local_6408 + 0xc) = 0;
  *(undefined4 *)(local_6408 + 0x428) = 0;
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x90c8) = 0;
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8578) = 1;
  if (*(int *)(*(int *)(local_6408 + 4) + 0x8588) != 0) {
    *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8588) = 0xffffd9bb;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



