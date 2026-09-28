/* CData3DEnko -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CData3DEnko[16], CData3DSen[16], CData3DSolid[16], CDataEnko[16], CDataMoji[16], CDataSen[16], CDataSolid[16], CDataSunpou[16], CDataTen[16] */
/* 0042daf0  FUN_0042daf0  331 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0042daf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  int local_63f0;
  int local_63ec;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920b30;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    local_63ec = 0;
  }
  else {
    local_63ec = param_1 + 0x88;
  }
  iVar2 = FUN_0042b460(local_63ec);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*in_ECX + 0x44))(param_1,param_2,param_3,param_4,param_5,uVar1);
    if (iVar2 != 0) {
      FUN_00446aa0();
      local_8 = 0;
      if (param_1 == 0) {
        local_63f0 = 0;
      }
      else {
        local_63f0 = param_1 + 0x88;
      }
      FUN_00450aa0(local_63f0,in_ECX,1);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    FUN_0042e540();
  }
  else {
    FUN_0042e540();
    iVar2 = 0;
  }
  ExceptionList = local_10;
  return iVar2;
}




/* vtable slots: CData3DEnko[21], CDataEnko[21] */
/* 00433da0  FUN_00433da0  55 bytes, 0 callers */

void FUN_00433da0(double param_1)

{
  int in_ECX;
  
  *(double *)(in_ECX + 0x68) = *(double *)(in_ECX + 0x68) * param_1;
  FUN_00433d30(param_1);
  return;
}




/* vtable slots: CData3DEnko[1] */
/* 0043d490  FUN_0043d490  68 bytes, 0 callers */

undefined4 FUN_0043d490(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0043cf70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x9a0);
    }
  }
  return in_ECX;
}




/* vtable slots: CData3DEnko[14] */
/* 0043d9d0  FUN_0043d9d0  237 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0043d9d0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00403cd0(local_20c,L"Ci  %d (%g,%g,%g)-(%g,%g,%g)         ",param_3,
               *(undefined8 *)(in_ECX + 0x498),*(undefined8 *)(in_ECX + 0x4a0),
               *(undefined8 *)(in_ECX + 0x4a8),*(undefined8 *)(in_ECX + 0x4b0),
               *(undefined8 *)(in_ECX + 0x4b8),*(undefined8 *)(in_ECX + 0x4c0));
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x32,local_20c,uVar1);
  return;
}




/* vtable slots: CData3DEnko[15] */
/* 00441740  FUN_00441740  121 bytes, 0 callers */

undefined4 FUN_00441740(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_00a088e8 == 1) {
    uVar1 = 1;
  }
  else {
    iVar2 = FUN_00424ed0(param_1,param_2,param_3);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_0042b460(param_2);
      if (iVar2 == 0) {
        uVar1 = FUN_0043dd30(param_1,param_2,param_3);
        FUN_0042e540();
      }
      else {
        FUN_0042e540();
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}




/* vtable slots: CData3DEnko[3] */
/* 004418c0  FUN_004418c0  424 bytes, 0 callers */

void FUN_004418c0(int param_1)

{
  int in_ECX;
  float10 fVar1;
  
  CStringT<>(&DAT_0095a9bc);
  FUN_004a7e90(0);
  FUN_0049dea0(&stack0xffffffe8,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),
               *(undefined1 *)(in_ECX + 0x28));
  FUN_004a7e90(8);
  FUN_00403dd0(param_1 + 0x1c + (uint)*(byte *)(in_ECX + 0x28) * 4);
  FUN_004a7e90(6);
  FUN_0049dcf0();
  FUN_004a7e10(0x3e);
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x498));
  FUN_004a77a0(10,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x4a0));
  FUN_004a77a0(0x14,(double)fVar1);
  fVar1 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x4a8));
  FUN_004a77a0(0x1e,(double)fVar1);
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x4b0));
  FUN_004a77a0(0xb,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x4b8));
  FUN_004a77a0(0x15,(double)fVar1);
  fVar1 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x4c0));
  FUN_004a77a0(0x1f,(double)fVar1);
  return;
}




/* vtable slots: CData3DEnko[23] */
/* 00441ef0  FUN_00441ef0  255 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

double * FUN_00441ef0(double *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int in_ECX;
  
  FUN_0043ca30();
  dVar1 = *(double *)(in_ECX + 0x120);
  dVar2 = *(double *)(in_ECX + 0x108);
  dVar3 = *(double *)(in_ECX + 0x1b8);
  dVar4 = *(double *)(in_ECX + 0x1a0);
  dVar5 = *(double *)(in_ECX + 0x128);
  dVar6 = *(double *)(in_ECX + 0x110);
  dVar7 = *(double *)(in_ECX + 0x1c0);
  dVar8 = *(double *)(in_ECX + 0x1a8);
  *param_1 = (*(double *)(in_ECX + 0x118) + *(double *)(in_ECX + 0x100) +
              *(double *)(in_ECX + 0x1b0) + *(double *)(in_ECX + 0x198)) / 4.0;
  param_1[1] = (dVar1 + dVar2 + dVar3 + dVar4) / 4.0;
  param_1[2] = (dVar5 + dVar6 + dVar7 + dVar8) / 4.0;
  return param_1;
}




/* vtable slots: CData3DEnko[22] */
/* 004421b0  FUN_004421b0  104 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_004421b0(undefined4 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int in_ECX;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  FUN_00408a60();
  uVar1 = *(undefined8 *)(in_ECX + 0x2c8);
  uVar2 = *(undefined8 *)(in_ECX + 0x2d0);
  local_18 = (undefined4)uVar1;
  *param_1 = local_18;
  uStack_14 = (undefined4)((ulonglong)uVar1 >> 0x20);
  param_1[1] = uStack_14;
  local_10 = (undefined4)uVar2;
  param_1[2] = local_10;
  uStack_c = (undefined4)((ulonglong)uVar2 >> 0x20);
  param_1[3] = uStack_c;
  return param_1;
}




/* vtable slots: CData3DEnko[11] */
/* 00442260  FUN_00442260  107 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00442260(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00408a30(0,0);
  FUN_0042a230(param_1,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  return param_1;
}




/* vtable slots: CData3DEnko[0] */
/* 004423d0  FUN_004423d0  16 bytes, 0 callers */

undefined ** FUN_004423d0(void)

{
  return &PTR_s_CData3DEnko_009fe0cc;
}




/* vtable slots: CData3DEnko[12] */
/* 00442400  FUN_00442400  56 bytes, 0 callers */

undefined4
FUN_00442400(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  FUN_0042b2a0(param_1,param_2,param_3,param_4,param_5);
  return param_1;
}




/* vtable slots: CData3DEnko[17] */
/* 00442480  FUN_00442480  53 bytes, 0 callers */

void FUN_00442480(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0042b7d0(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CData3DEnko[5] */
/* 00442540  FUN_00442540  135 bytes, 0 callers */

undefined4 FUN_00442540(void)

{
  uint uVar1;
  int iVar2;
  undefined4 in_ECX;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092182f;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_004121b0(0x9a0);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0043ca60(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_0043d090(in_ECX);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CData3DEnko[2] */
/* 004426f0  FUN_004426f0  360 bytes, 0 callers */

void FUN_004426f0(void)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  FUN_0042e690();
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    FUN_007a5922();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
  }
  else {
    uVar7 = *(undefined8 *)(in_ECX + 0x738);
    uVar6 = *(undefined8 *)(in_ECX + 0x4c0);
    uVar5 = *(undefined8 *)(in_ECX + 0x4b8);
    uVar4 = *(undefined8 *)(in_ECX + 0x4b0);
    uVar3 = *(undefined8 *)(in_ECX + 0x4a8);
    uVar2 = *(undefined8 *)(in_ECX + 0x4a0);
    FUN_00420820(*(undefined8 *)(in_ECX + 0x498));
    FUN_00420820(uVar2);
    FUN_00420820(uVar3);
    FUN_00420820(uVar4);
    FUN_00420820(uVar5);
    FUN_00420820(uVar6);
    FUN_00420820(uVar7);
  }
  return;
}




/* vtable slots: CData3DEnko[6] */
/* 00442bf0  FUN_00442bf0  178 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00442bf0(undefined4 param_1)

{
  int in_ECX;
  undefined1 local_38 [24];
  undefined1 local_20 [24];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0042f720(param_1);
  FUN_00498860(local_20,*(undefined4 *)(in_ECX + 0x498),*(undefined4 *)(in_ECX + 0x49c),
               *(undefined4 *)(in_ECX + 0x4a0),*(undefined4 *)(in_ECX + 0x4a4),
               *(undefined4 *)(in_ECX + 0x4a8),*(undefined4 *)(in_ECX + 0x4ac));
  FUN_00498860(local_38,*(undefined4 *)(in_ECX + 0x4b0),*(undefined4 *)(in_ECX + 0x4b4),
               *(undefined4 *)(in_ECX + 0x4b8),*(undefined4 *)(in_ECX + 0x4bc),
               *(undefined4 *)(in_ECX + 0x4c0),*(undefined4 *)(in_ECX + 0x4c4));
  return;
}




/* vtable slots: CData3DEnko[4] */
/* 00442ec0  FUN_00442ec0  25 bytes, 0 callers */

void FUN_00442ec0(undefined4 param_1)

{
  FUN_00430260(param_1);
  return;
}




/* vtable slots: CData3DEnko[7] */
/* 00443af0  FUN_00443af0  212 bytes, 0 callers */

undefined4 FUN_00443af0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0079d98a(&PTR_s_CData3DEnko_009fe0cc);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_00438910(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_00498910(*(undefined4 *)(param_1 + 0x498),*(undefined4 *)(param_1 + 0x49c),
                           *(undefined4 *)(param_1 + 0x4a0),*(undefined4 *)(param_1 + 0x4a4),
                           *(undefined4 *)(param_1 + 0x4a8),*(undefined4 *)(param_1 + 0x4ac));
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_00498910(*(undefined4 *)(param_1 + 0x4b0),*(undefined4 *)(param_1 + 0x4b4),
                             *(undefined4 *)(param_1 + 0x4b8),*(undefined4 *)(param_1 + 0x4bc),
                             *(undefined4 *)(param_1 + 0x4c0),*(undefined4 *)(param_1 + 0x4c4));
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}




/* vtable slots: CData3DEnko[13] */
/* 00446830  FUN_00446830  29 bytes, 0 callers */

void FUN_00446830(undefined4 param_1,undefined4 param_2)

{
  FUN_0043af40(param_1,param_2);
  return;
}



