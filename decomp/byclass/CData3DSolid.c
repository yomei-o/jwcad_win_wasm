/* CData3DSolid -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CData3DSolid[1] */
/* 0043d530  FUN_0043d530  68 bytes, 0 callers */

undefined4 FUN_0043d530(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0043d060();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x520);
    }
  }
  return in_ECX;
}




/* vtable slots: CData3DSolid[14] */
/* 0043dbb0  FUN_0043dbb0  369 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0043dbb0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00403cd0(local_20c,L"Solid  %d (%g,%g,%g)-(%g,%g,%g)-(%g,%g,%g)-(%g,%g,%g)  ",param_3,
               *(undefined8 *)(in_ECX + 600),*(undefined8 *)(in_ECX + 0x260),
               *(undefined8 *)(in_ECX + 0x268),*(undefined8 *)(in_ECX + 0x270),
               *(undefined8 *)(in_ECX + 0x278),*(undefined8 *)(in_ECX + 0x280),
               *(undefined8 *)(in_ECX + 0x288),*(undefined8 *)(in_ECX + 0x290),
               *(undefined8 *)(in_ECX + 0x298),*(undefined8 *)(in_ECX + 0x2a0),
               *(undefined8 *)(in_ECX + 0x2a8),*(undefined8 *)(in_ECX + 0x2b0));
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x32,local_20c,uVar1);
  return;
}




/* vtable slots: CData3DSolid[15] */
/* 00441840  FUN_00441840  121 bytes, 0 callers */

undefined4 FUN_00441840(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
        uVar1 = FUN_0043f7a0(param_1,param_2,param_3);
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




/* vtable slots: CData3DSolid[3] */
/* 00441c10  FUN_00441c10  736 bytes, 0 callers */

void FUN_00441c10(int param_1)

{
  int in_ECX;
  float10 fVar1;
  
  CStringT<>("3DFACE");
  FUN_004a7e90(0);
  FUN_0049dea0(&stack0xffffffe8,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),
               *(undefined1 *)(in_ECX + 0x28));
  FUN_004a7e90(8);
  FUN_00403dd0(param_1 + 0x1c + (uint)*(byte *)(in_ECX + 0x28) * 4);
  FUN_004a7e90(6);
  if (*(short *)(in_ECX + 0x2a) == 10) {
    FUN_0049dcf0();
    FUN_004a7e10(0x3e);
  }
  else {
    FUN_0049dcf0();
    FUN_004a7e10(0x3e);
  }
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 600));
  FUN_004a77a0(10,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x260));
  FUN_004a77a0(0x14,(double)fVar1);
  fVar1 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x268));
  FUN_004a77a0(0x1e,(double)fVar1);
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x270));
  FUN_004a77a0(0xb,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x278));
  FUN_004a77a0(0x15,(double)fVar1);
  fVar1 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x280));
  FUN_004a77a0(0x1f,(double)fVar1);
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x288));
  FUN_004a77a0(0xc,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x290));
  FUN_004a77a0(0x16,(double)fVar1);
  fVar1 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x298));
  FUN_004a77a0(0x20,(double)fVar1);
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x2a0));
  FUN_004a77a0(0xd,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x2a8));
  FUN_004a77a0(0x17,(double)fVar1);
  fVar1 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x2b0));
  FUN_004a77a0(0x21,(double)fVar1);
  FUN_004a7e10(0x46);
  return;
}




/* vtable slots: CData3DSolid[23] */
/* 004420b0  FUN_004420b0  255 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

double * FUN_004420b0(double *param_1)

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
  dVar1 = *(double *)(in_ECX + 0x278);
  dVar2 = *(double *)(in_ECX + 0x260);
  dVar3 = *(double *)(in_ECX + 0x290);
  dVar4 = *(double *)(in_ECX + 0x2a8);
  dVar5 = *(double *)(in_ECX + 0x280);
  dVar6 = *(double *)(in_ECX + 0x268);
  dVar7 = *(double *)(in_ECX + 0x298);
  dVar8 = *(double *)(in_ECX + 0x2b0);
  *param_1 = (*(double *)(in_ECX + 0x270) + *(double *)(in_ECX + 600) + *(double *)(in_ECX + 0x288)
             + *(double *)(in_ECX + 0x2a0)) / 4.0;
  param_1[1] = (dVar1 + dVar2 + dVar3 + dVar4) / 4.0;
  param_1[2] = (dVar5 + dVar6 + dVar7 + dVar8) / 4.0;
  return param_1;
}




/* vtable slots: CData3DSolid[22] */
/* 00442240  FUN_00442240  28 bytes, 0 callers */

undefined4 FUN_00442240(undefined4 param_1)

{
  FUN_00429e30(param_1);
  return param_1;
}




/* vtable slots: CData3DSolid[11] */
/* 00442340  FUN_00442340  107 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00442340(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00408a30(0,0);
  FUN_0042a260(param_1,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  return param_1;
}




/* vtable slots: CData3DSolid[0] */
/* 004423f0  FUN_004423f0  16 bytes, 0 callers */

undefined ** FUN_004423f0(void)

{
  return &PTR_s_CData3DSolid_009fe0e8;
}




/* vtable slots: CData3DSolid[17] */
/* 00442500  FUN_00442500  53 bytes, 0 callers */

void FUN_00442500(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0042c630(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CData3DSolid[5] */
/* 00442660  FUN_00442660  135 bytes, 0 callers */

undefined4 FUN_00442660(void)

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
  iVar2 = FUN_004121b0(0x520);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0043cdb0(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_0043d220(in_ECX);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CData3DSolid[2] */
/* 00442990  FUN_00442990  575 bytes, 0 callers */

void FUN_00442990(void)

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
    FUN_00420650(in_ECX + 600);
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650(in_ECX + 0x288);
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
  }
  else {
    uVar6 = *(undefined8 *)(in_ECX + 0x280);
    uVar5 = *(undefined8 *)(in_ECX + 0x278);
    uVar4 = *(undefined8 *)(in_ECX + 0x270);
    uVar3 = *(undefined8 *)(in_ECX + 0x268);
    uVar2 = *(undefined8 *)(in_ECX + 0x260);
    FUN_00420820(*(undefined8 *)(in_ECX + 600));
    FUN_00420820(uVar2);
    FUN_00420820(uVar3);
    FUN_00420820(uVar4);
    FUN_00420820(uVar5);
    FUN_00420820(uVar6);
    uVar6 = *(undefined8 *)(in_ECX + 0x2b0);
    uVar5 = *(undefined8 *)(in_ECX + 0x2a8);
    uVar4 = *(undefined8 *)(in_ECX + 0x2a0);
    uVar3 = *(undefined8 *)(in_ECX + 0x298);
    uVar2 = *(undefined8 *)(in_ECX + 0x290);
    FUN_00420820(*(undefined8 *)(in_ECX + 0x288));
    FUN_00420820(uVar2);
    FUN_00420820(uVar3);
    FUN_00420820(uVar4);
    FUN_00420820(uVar5);
    FUN_00420820(uVar6);
  }
  return;
}




/* vtable slots: CData3DSolid[6] */
/* 00442d60  FUN_00442d60  351 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00442d60(int param_1)

{
  int in_ECX;
  undefined1 local_68 [24];
  undefined1 local_50 [24];
  undefined1 local_38 [24];
  undefined1 local_20 [24];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0042f990(param_1);
  FUN_00498860(local_20,*(undefined4 *)(in_ECX + 600),*(undefined4 *)(in_ECX + 0x25c),
               *(undefined4 *)(in_ECX + 0x260),*(undefined4 *)(in_ECX + 0x264),
               *(undefined4 *)(in_ECX + 0x268),*(undefined4 *)(in_ECX + 0x26c));
  FUN_00498860(local_38,*(undefined4 *)(in_ECX + 0x270),*(undefined4 *)(in_ECX + 0x274),
               *(undefined4 *)(in_ECX + 0x278),*(undefined4 *)(in_ECX + 0x27c),
               *(undefined4 *)(in_ECX + 0x280),*(undefined4 *)(in_ECX + 0x284));
  FUN_00498860(local_50,*(undefined4 *)(in_ECX + 0x288),*(undefined4 *)(in_ECX + 0x28c),
               *(undefined4 *)(in_ECX + 0x290),*(undefined4 *)(in_ECX + 0x294),
               *(undefined4 *)(in_ECX + 0x298),*(undefined4 *)(in_ECX + 0x29c));
  FUN_00498860(local_68,*(undefined4 *)(in_ECX + 0x2a0),*(undefined4 *)(in_ECX + 0x2a4),
               *(undefined4 *)(in_ECX + 0x2a8),*(undefined4 *)(in_ECX + 0x2ac),
               *(undefined4 *)(in_ECX + 0x2b0),*(undefined4 *)(in_ECX + 0x2b4));
  *(undefined4 *)(param_1 + 0x2b8) = *(undefined4 *)(in_ECX + 0x2b8);
  FUN_004201b0(in_ECX + 0x2c0);
  return;
}




/* vtable slots: CData3DSolid[4] */
/* 00442f00  FUN_00442f00  25 bytes, 0 callers */

void FUN_00442f00(undefined4 param_1)

{
  FUN_00430e00(param_1);
  return;
}




/* vtable slots: CData3DSolid[7] */
/* 00443ca0  FUN_00443ca0  382 bytes, 0 callers */

undefined4 FUN_00443ca0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = FUN_0079d98a(&PTR_s_CData3DSolid_009fe0e8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_00438910(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_00498910(*(undefined4 *)(param_1 + 600),*(undefined4 *)(param_1 + 0x25c),
                           *(undefined4 *)(param_1 + 0x260),*(undefined4 *)(param_1 + 0x264),
                           *(undefined4 *)(param_1 + 0x268),*(undefined4 *)(param_1 + 0x26c));
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_00498910(*(undefined4 *)(param_1 + 0x270),*(undefined4 *)(param_1 + 0x274),
                             *(undefined4 *)(param_1 + 0x278),*(undefined4 *)(param_1 + 0x27c),
                             *(undefined4 *)(param_1 + 0x280),*(undefined4 *)(param_1 + 0x284));
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          iVar1 = FUN_00498910(*(undefined4 *)(param_1 + 0x288),*(undefined4 *)(param_1 + 0x28c),
                               *(undefined4 *)(param_1 + 0x290),*(undefined4 *)(param_1 + 0x294),
                               *(undefined4 *)(param_1 + 0x298),*(undefined4 *)(param_1 + 0x29c));
          if (iVar1 == 0) {
            uVar2 = 0;
          }
          else {
            iVar1 = FUN_00498910(*(undefined4 *)(param_1 + 0x2a0),*(undefined4 *)(param_1 + 0x2a4),
                                 *(undefined4 *)(param_1 + 0x2a8),*(undefined4 *)(param_1 + 0x2ac),
                                 *(undefined4 *)(param_1 + 0x2b0),*(undefined4 *)(param_1 + 0x2b4));
            if (iVar1 == 0) {
              uVar2 = 0;
            }
            else if (*(int *)(in_ECX + 0x98) == *(int *)(param_1 + 0x98)) {
              uVar2 = 1;
            }
            else {
              uVar2 = 0;
            }
          }
        }
      }
    }
  }
  return uVar2;
}



