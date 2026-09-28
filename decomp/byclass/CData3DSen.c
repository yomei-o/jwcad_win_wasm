/* CData3DSen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CData3DSen[1] */
/* 0043d4e0  FUN_0043d4e0  68 bytes, 0 callers */

undefined4 FUN_0043d4e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0043d040();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x98);
    }
  }
  return in_ECX;
}




/* vtable slots: CData3DSen[14] */
/* 0043dac0  FUN_0043dac0  228 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0043dac0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00403cd0(local_20c,L"Line  %d (%g,%g,%g)-(%g,%g,%g)         ",param_3,
               *(undefined8 *)(in_ECX + 0x68),*(undefined8 *)(in_ECX + 0x70),
               *(undefined8 *)(in_ECX + 0x78),*(undefined8 *)(in_ECX + 0x80),
               *(undefined8 *)(in_ECX + 0x88),*(undefined8 *)(in_ECX + 0x90));
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x32,local_20c,uVar1);
  return;
}




/* vtable slots: CData3DSen[15] */
/* 004417c0  FUN_004417c0  121 bytes, 2 callers */

undefined4 FUN_004417c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
        uVar1 = FUN_0043ecc0(param_1,param_2,param_3);
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




/* vtable slots: CData3DSen[3] */
/* 00441a70  FUN_00441a70  415 bytes, 0 callers */

void FUN_00441a70(int param_1)

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
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x68));
  FUN_004a77a0(10,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x70));
  FUN_004a77a0(0x14,(double)fVar1);
  fVar1 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x78));
  FUN_004a77a0(0x1e,(double)fVar1);
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x80));
  FUN_004a77a0(0xb,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x88));
  FUN_004a77a0(0x15,(double)fVar1);
  fVar1 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x90));
  FUN_004a77a0(0x1f,(double)fVar1);
  return;
}




/* vtable slots: CData3DSen[23] */
/* 00441ff0  FUN_00441ff0  180 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

double * FUN_00441ff0(double *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int in_ECX;
  
  FUN_0043ca30();
  dVar1 = *(double *)(in_ECX + 0x88);
  dVar2 = *(double *)(in_ECX + 0x70);
  dVar3 = *(double *)(in_ECX + 0x90);
  dVar4 = *(double *)(in_ECX + 0x78);
  *param_1 = (*(double *)(in_ECX + 0x80) + *(double *)(in_ECX + 0x68)) / 2.0;
  param_1[1] = (dVar1 + dVar2) / 2.0;
  param_1[2] = (dVar3 + dVar4) / 2.0;
  return param_1;
}




/* vtable slots: CData3DSen[22] */
/* 00442220  FUN_00442220  28 bytes, 0 callers */

undefined4 FUN_00442220(undefined4 param_1)

{
  FUN_00429e10(param_1);
  return param_1;
}




/* vtable slots: CData3DSen[11] */
/* 004422d0  FUN_004422d0  107 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004422d0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00408a30(0,0);
  FUN_0042a1a0(param_1,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  return param_1;
}




/* vtable slots: CData3DSen[0] */
/* 004423e0  FUN_004423e0  16 bytes, 0 callers */

undefined ** FUN_004423e0(void)

{
  return &PTR_s_CData3DSen_009fe0b0;
}




/* vtable slots: CData3DSen[12], CData3DSolid[12] */
/* 00442440  FUN_00442440  56 bytes, 0 callers */

undefined4
FUN_00442440(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  FUN_0042b0f0(param_1,param_2,param_3,param_4,param_5);
  return param_1;
}




/* vtable slots: CData3DSen[17] */
/* 004424c0  FUN_004424c0  53 bytes, 0 callers */

void FUN_004424c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CData3DSen[5] */
/* 004425d0  FUN_004425d0  135 bytes, 1 callers */

undefined4 FUN_004425d0(void)

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
  iVar2 = FUN_004121b0(0x98);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0043ccc0(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_0043d170(in_ECX);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CData3DSen[2] */
/* 00442860  FUN_00442860  297 bytes, 0 callers */

void FUN_00442860(void)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  FUN_0042e690();
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    FUN_007a5922();
    FUN_00420650(in_ECX + 0x68);
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
  }
  else {
    uVar6 = *(undefined8 *)(in_ECX + 0x90);
    uVar5 = *(undefined8 *)(in_ECX + 0x88);
    uVar4 = *(undefined8 *)(in_ECX + 0x80);
    uVar3 = *(undefined8 *)(in_ECX + 0x78);
    uVar2 = *(undefined8 *)(in_ECX + 0x70);
    FUN_00420820(*(undefined8 *)(in_ECX + 0x68));
    FUN_00420820(uVar2);
    FUN_00420820(uVar3);
    FUN_00420820(uVar4);
    FUN_00420820(uVar5);
    FUN_00420820(uVar6);
  }
  return;
}




/* vtable slots: CData3DSen[6] */
/* 00442cb0  FUN_00442cb0  172 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00442cb0(undefined4 param_1)

{
  int in_ECX;
  undefined1 local_38 [24];
  undefined1 local_20 [24];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0042f720(param_1);
  FUN_00498860(local_20,*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c),
               *(undefined4 *)(in_ECX + 0x70),*(undefined4 *)(in_ECX + 0x74),
               *(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c));
  FUN_00498860(local_38,*(undefined4 *)(in_ECX + 0x80),*(undefined4 *)(in_ECX + 0x84),
               *(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x8c),
               *(undefined4 *)(in_ECX + 0x90),*(undefined4 *)(in_ECX + 0x94));
  return;
}




/* vtable slots: CData3DSen[4] */
/* 00442ee0  FUN_00442ee0  25 bytes, 0 callers */

void FUN_00442ee0(undefined4 param_1)

{
  FUN_00430c80(param_1);
  return;
}




/* vtable slots: CData3DSen[7] */
/* 00443bd0  FUN_00443bd0  206 bytes, 0 callers */

undefined4 FUN_00443bd0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0079d98a(&PTR_s_CData3DSen_009fe0b0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_00438910(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_00498910(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                           *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x74),
                           *(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x7c));
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_00498910(*(undefined4 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x84),
                             *(undefined4 *)(param_1 + 0x88),*(undefined4 *)(param_1 + 0x8c),
                             *(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x94));
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




/* vtable slots: CData3DSen[13], CData3DSolid[13] */
/* 00446850  FUN_00446850  29 bytes, 0 callers */

void FUN_00446850(undefined4 param_1,undefined4 param_2)

{
  FUN_0043ae00(param_1,param_2);
  return;
}



