/* CZukeiRitsumen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiRitsumen[1] */
/* 006dfe60  FUN_006dfe60  68 bytes, 0 callers */

undefined4 FUN_006dfe60(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006dfd70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x398);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiRitsumen[6] */
/* 006dffd0  FUN_006dffd0  634 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006dffd0(undefined4 *param_1)

{
  uint uVar1;
  float10 fVar2;
  double dVar3;
  undefined1 local_63fc [20];
  int *local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e7db;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0040c0e0();
  if (local_63e8[0x2e] == 2) {
    FUN_0044dd90(local_63fc,local_63e8[1]);
    FUN_0044de00(local_63fc,local_63e8[1]);
    (**(code **)(*local_63e8 + 0x20))();
  }
  else if (local_63e8[0x2e] == 3) {
    FUN_0044dd90(local_63fc,local_63e8[1]);
    FUN_0044de00(local_63fc,local_63e8[1]);
    (**(code **)(*local_63e8 + 0x20))();
    fVar2 = (float10)FUN_008f8eb0(((*(double *)(local_63e8 + 0x8a) +
                                   *(double *)(local_63e8[1] + 0x17c0)) * 3.141592653589793) / 180.0
                                 );
    dVar3 = (double)fVar2;
    fVar2 = (float10)FUN_008f8f00(((*(double *)(local_63e8 + 0x8a) +
                                   *(double *)(local_63e8[1] + 0x17c0)) * 3.141592653589793) / 180.0
                                  ,uVar1,dVar3);
    FUN_006e27c0(0,0,dVar3,(double)fVar2);
    FUN_006e2920(local_63e4,local_63fc,*param_1,param_1[1],param_1[2],param_1[3]);
  }
  FUN_006e0490();
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiRitsumen[16] */
/* 006e0250  FUN_006e0250  554 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006e0250(void)

{
  int in_ECX;
  undefined1 local_640c [20];
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
  puStack_c = &LAB_0092999b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0xb8) == 0x65) || (*(int *)(in_ECX + 0xb8) == 0x66)) {
    local_63ec = 1;
  }
  else {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    if (*(int *)(local_63e8 + 0xb8) == 2) {
      FUN_0044dd90(local_640c,*(undefined4 *)(local_63e8 + 4));
      FUN_0044de00(local_640c,*(undefined4 *)(local_63e8 + 4));
      local_63ec = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (*(int *)(local_63e8 + 0xb8) == 3) {
      FUN_0044dd90(local_640c,*(undefined4 *)(local_63e8 + 4));
      FUN_0044de00(local_640c,*(undefined4 *)(local_63e8 + 4));
      if (*(int *)(local_63e8 + 0x200) == 0) {
        local_63f4 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63ec = local_63f4;
      }
      else {
        *(undefined4 *)(local_63e8 + 0xb8) = 2;
        FUN_006e0490();
        local_63f0 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63ec = local_63f0;
      }
    }
    else {
      local_63f8 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63ec = local_63f8;
    }
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiRitsumen[0] */
/* 006e0480  FUN_006e0480  16 bytes, 0 callers */

undefined ** FUN_006e0480(void)

{
  return &PTR_s_CZukeiRitsumen_0097a1d4;
}




/* vtable slots: CZukeiRitsumen[23] */
/* 006e0570  FUN_006e0570  89 bytes, 0 callers */

undefined4 FUN_006e0570(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8638)) {
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




/* vtable slots: CZukeiRitsumen[46] */
/* 006e05d0  FUN_006e05d0  238 bytes, 0 callers */

undefined4
FUN_006e05d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_c [2];
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_c[0] = 0xffffffff;
      iVar2 = FUN_00778a40(1,local_c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,0x16);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiRitsumen[47] */
/* 006e06c0  FUN_006e06c0  231 bytes, 0 callers */

undefined4
FUN_006e06c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                           param_3,param_4,param_5,param_6,param_7,0x16);
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




/* vtable slots: CZukeiRitsumen[34] */
/* 006e07b0  FUN_006e07b0  1598 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006e07b0(void)

{
  char cVar1;
  uint uID;
  undefined4 uVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  LPSTR in_stack_fffff6e0;
  int in_stack_fffff6e4;
  undefined1 local_90c [4];
  undefined4 local_908;
  undefined4 local_904;
  undefined1 local_900 [4];
  undefined4 local_8fc;
  double local_8f8;
  undefined4 local_8f0;
  int local_8ec;
  int local_8e8;
  double local_8e4;
  CSimpleStringT<wchar_t,0> local_8dc [7];
  char local_8d5;
  int *local_8d0;
  undefined1 *local_8cc;
  int iStack_8c8;
  undefined4 uStack_8c4;
  undefined1 local_8bc [2008];
  undefined1 local_e4 [208];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e836;
  local_10 = ExceptionList;
  uID = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uID;
  FUN_00404c80();
  FUN_004fca20();
  FUN_005b8a30();
  if ((*(int *)(local_8d0[1] + 0x8ce8) != 0) &&
     ((cVar1 = FUN_00414040(&DAT_0095590a), cVar1 != '\0' || (*(int *)(local_8d0[1] + 0x8d04) == 0))
     )) {
    *(undefined4 *)(local_8d0[1] + 0x8ce8) = 0;
  }
  if (*(int *)(local_8d0[1] + 0x8ce8) == 0) {
    FUN_00403dd0();
    local_8 = 0;
    local_8e8 = ReverseFind();
    local_8fc = Left(local_900,local_8e8);
    FUN_00404920();
    FUN_00403d00(local_8d0[0x2b] + 0x10);
    FUN_00404540();
    local_908 = Mid(local_90c,local_8e8 + 1);
    local_8._0_1_ = 1;
    local_904 = local_908;
    FUN_00404860();
    local_8._0_1_ = 0;
    FUN_00404540();
    CStringT<>();
    local_8._0_1_ = 2;
    FID_conflict_LoadStringA
              ((HINSTANCE)(local_8d0[0x2c] + 7000),uID,in_stack_fffff6e0,in_stack_fffff6e4);
    local_8ec = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_8dc);
    uVar2 = Left();
    local_8d5 = FUN_00414010(uVar2);
    FUN_00404540();
    if (local_8d5 != '\0') {
      iVar3 = FUN_00404920();
      *(uint *)(local_8d0[0x2b] + 8) = *(ushort *)(iVar3 + local_8ec * 2) - 0x41;
      local_8f0 = FUN_00596540();
      FUN_005aac30(local_8f0,0);
      FUN_00404900();
      *(undefined4 *)(local_8d0[1] + 0x8d04) = local_8f0;
      if ((DAT_00a0cc6c != 0) && (DAT_00a0cc74 != 0)) {
        DAT_00a0cc74 = 0;
        DAT_00a0cc6c = 0;
        iVar3 = FUN_004f1700();
        if (iVar3 != 0) {
          FUN_00404920();
          FUN_004f7a90();
          local_8cc = local_8bc;
          iStack_8c8 = local_8d0[0x2b] + 0x212;
          uStack_8c4 = 0;
          FUN_00404920();
          FUN_00904dec();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00404540();
          ExceptionList = local_10;
          return;
        }
      }
      DAT_00a0cc74 = 0;
      DAT_00a0cc6c = 0;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  else {
    uVar2 = FUN_00404920();
    FUN_00403d00(local_8d0[0x2b] + 0x212,uVar2);
    FUN_005aac30(*(undefined4 *)(local_8d0[1] + 0x8d04),1);
  }
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) == *(int *)(local_8d0[1] + 0x8638)) {
    local_8e4 = *(double *)(local_8d0[0x2b] + 0xc40);
    local_8f8 = *(double *)(local_8d0[0x2b] + 0xc48);
    if ((-1e-07 < local_8e4) && (-1e-07 < local_8e4)) {
      if ((local_8e4 <= 1e-07) || (local_8f8 <= 1e-07)) {
        FUN_005977f0();
        uVar2 = FUN_00404920();
        FUN_005cf710(local_e4,uVar2);
        FUN_00404770();
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797ece();
      }
      else {
        if (DAT_00a0d62c != 0) {
          local_8e4 = local_8e4 / DAT_00a0d630;
          local_8f8 = local_8f8 / DAT_00a0d630;
        }
        dVar4 = local_8e4;
        dVar5 = local_8f8;
        FUN_00404c80(local_8e4,local_8f8);
        FUN_004fca20();
        FUN_0058ae50(dVar4,dVar5);
      }
    }
  }
  local_8d0[0x81] = 0;
  (**(code **)(*local_8d0 + 0x20))();
  if (local_8d0[0x80] == 0) {
    local_8d0[0x2e] = 3;
  }
  else {
    local_8d0[0x2e] = 2;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiRitsumen[25] */
/* 006e0df0  FUN_006e0df0  19 bytes, 0 callers */

void FUN_006e0df0(void)

{
  FUN_006e2500();
  return;
}




/* vtable slots: CZukeiRitsumen[26] */
/* 006e0e10  FUN_006e0e10  281 bytes, 0 callers */

void FUN_006e0e10(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    local_c = *(int *)(*(int *)(iVar1 + 0x1a0) + 0x6fc) + 1;
    if (3 < local_c) {
      local_c = -1;
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(int *)(*(int *)(iVar1 + 0x1a0) + 0x6fc) = local_c;
    uVar2 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_005b8a30(uVar2);
  }
  else {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(in_ECX + 0x210) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x700);
    *(int *)(in_ECX + 0x210) = *(int *)(in_ECX + 0x210) + 1;
    if (0 < *(int *)(in_ECX + 0x210)) {
      *(undefined4 *)(in_ECX + 0x210) = 0xffffffff;
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x700) = *(undefined4 *)(in_ECX + 0x210);
    uVar2 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_005b8a30(uVar2);
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiRitsumen[27] */
/* 006e0f30  FUN_006e0f30  281 bytes, 0 callers */

void FUN_006e0f30(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    local_c = *(int *)(*(int *)(iVar1 + 0x1a0) + 0x704) + 1;
    if (3 < local_c) {
      local_c = -1;
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(int *)(*(int *)(iVar1 + 0x1a0) + 0x704) = local_c;
    uVar2 = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_005b8a30(uVar2);
  }
  else {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(in_ECX + 0x218) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x708);
    *(int *)(in_ECX + 0x218) = *(int *)(in_ECX + 0x218) + 1;
    if (0 < *(int *)(in_ECX + 0x218)) {
      *(undefined4 *)(in_ECX + 0x218) = 0xffffffff;
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x708) = *(undefined4 *)(in_ECX + 0x218);
    uVar2 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_005b8a30(uVar2);
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiRitsumen[49] */
/* 006e1050  FUN_006e1050  70 bytes, 0 callers */

void FUN_006e1050(undefined8 param_1)

{
  int iVar1;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  (**(code **)(*(int *)(*(int *)(iVar1 + 0x1a0) + 0x2a0) + 0x188))(param_1);
  return;
}




/* vtable slots: CZukeiRitsumen[50] */
/* 006e10a0  FUN_006e10a0  107 bytes, 0 callers */

void FUN_006e10a0(double param_1)

{
  double dVar1;
  undefined8 local_10;
  
  local_10 = param_1;
  if (DAT_00a0d62c != 0) {
    local_10 = param_1 / DAT_00a0d630;
  }
  dVar1 = local_10;
  FUN_00404c80(local_10,local_10);
  FUN_004fca20();
  FUN_0058ae50(local_10,dVar1);
  return;
}




/* vtable slots: CZukeiRitsumen[51] */
/* 006e1110  FUN_006e1110  226 bytes, 0 callers */

void FUN_006e1110(undefined8 param_1,double param_2)

{
  int iVar1;
  double dVar2;
  double local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093cd2d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  iVar1 = FUN_004fca20();
  (**(code **)(*(int *)(*(int *)(iVar1 + 0x1a0) + 0x2a0) + 0x188))(param_1);
  local_20 = param_2;
  if (DAT_00a0d62c != 0) {
    local_20 = param_2 / DAT_00a0d630;
  }
  dVar2 = local_20;
  FUN_00404c80(local_20,local_20);
  FUN_004fca20();
  FUN_0058ae50(local_20,dVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiRitsumen[15], CZukeiTategu[15] */
/* 006e1200  FUN_006e1200  44 bytes, 0 callers */

undefined4 FUN_006e1200(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xb8) == 0x65) || (*(int *)(in_ECX + 0xb8) == 0x66)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CZukeiRitsumen[9] */
/* 006e1230  FUN_006e1230  1130 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006e1230(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 local_6454 [8];
  undefined4 local_644c;
  undefined4 local_6434;
  undefined4 local_6430;
  undefined4 local_642c;
  undefined4 local_6428;
  undefined4 local_6424;
  undefined4 local_6420;
  undefined4 local_641c;
  undefined4 local_6418;
  undefined4 local_6414;
  int local_6410;
  int local_640c;
  int local_6408;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e87b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
  local_8._0_1_ = 1;
  local_644c = 0;
  FUN_004b6d60(local_6454,param_2,param_3,param_4,param_5);
  if (*(int *)(local_6408 + 0xb8) == 0x65) {
    local_640c = FUN_005a1910(param_1,param_2,param_3,param_4,param_5);
    if (local_640c == 0) {
      local_6414 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (local_640c == -1) {
      local_6418 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6414 = local_6418;
    }
    else {
      *(undefined4 *)(local_6408 + 0xb8) = 0x66;
      FUN_006e0490();
      local_641c = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6414 = local_641c;
    }
  }
  else if (*(int *)(local_6408 + 0xb8) == 0x66) {
    local_6410 = FUN_005a1720(param_1,param_2,param_3,param_4,param_5);
    if (local_6410 == 0) {
      local_6420 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6414 = local_6420;
    }
    else if (local_6410 == -1) {
      *(undefined4 *)(local_6408 + 0xb8) = 0x65;
      FUN_006e0490();
      local_6424 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6414 = local_6424;
    }
    else {
      FUN_006e0490();
      *(undefined4 *)(local_6408 + 0xb8) = 3;
      *(undefined4 *)(local_6408 + 0x204) = 0;
      local_6428 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6414 = local_6428;
    }
  }
  else if (*(int *)(local_6408 + 0xb8) == 2) {
    FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
    *(undefined4 *)(local_6408 + 0xb8) = 3;
    FUN_006e0490();
    FUN_00404c80();
    FUN_0056d7d0();
    local_642c = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_6414 = local_642c;
  }
  else if (*(int *)(local_6408 + 0xb8) == 3) {
    FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
    local_6430 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_6414 = local_6430;
  }
  else {
    FUN_00404c80();
    FUN_0056d7d0();
    local_6434 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_6414 = local_6434;
  }
  ExceptionList = local_10;
  return local_6414;
}




/* vtable slots: CZukeiRitsumen[11] */
/* 006e16a0  FUN_006e16a0  332 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006e16a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (((*(int *)(in_ECX + 0xb8) == 0x65) || (*(int *)(in_ECX + 0xb8) == 0x66)) ||
     (*(int *)(in_ECX + 0xb8) == 1)) {
    uVar1 = FUN_006e1230(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&param_2,1);
    if (iVar2 == 1) {
      uVar1 = FUN_006e1230(param_1,param_2,param_3,param_4,param_5);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiRitsumen[8] */
/* 006e17f0  FUN_006e17f0  964 bytes, 0 callers */

void FUN_006e17f0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 uVar3;
  undefined8 local_1c;
  undefined8 local_14;
  
  *(undefined8 *)(in_ECX + 0x318) = *(undefined8 *)(*(int *)(in_ECX + 0xac) + 0xb78);
  *(undefined8 *)(in_ECX + 800) = *(undefined8 *)(*(int *)(in_ECX + 0xac) + 0xb80);
  *(undefined4 *)(in_ECX + 0x388) = *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0xc58);
  *(undefined4 *)(in_ECX + 0x380) = *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0xc50);
  *(undefined4 *)(in_ECX + 900) = *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0xc54);
  *(undefined8 *)(in_ECX + 0x1f0) = 0;
  *(undefined8 *)(in_ECX + 0x1f8) = 0;
  *(undefined4 *)(in_ECX + 0x20c) = 0;
  *(undefined4 *)(in_ECX + 0x214) = 0;
  *(undefined4 *)(in_ECX + 0x21c) = 0;
  *(undefined4 *)(in_ECX + 0x220) = 0;
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_0058cc80();
  *(double *)(in_ECX + 0x228) = (double)fVar2;
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_0058b290();
  *(double *)(in_ECX + 0x1f0) = (double)fVar2;
  DAT_00a0bca0 = *(undefined8 *)(in_ECX + 0x1f0);
  if (DAT_00a0d62c != 0) {
    *(double *)(in_ECX + 0x1f0) = *(double *)(in_ECX + 0x1f0) * DAT_00a0d630;
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  fVar2 = (float10)(**(code **)(*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) + 0x178))();
  *(double *)(in_ECX + 0x1f8) = (double)fVar2;
  DAT_00a0bca8 = *(undefined8 *)(in_ECX + 0x1f8);
  if (DAT_00a0d62c != 0) {
    *(double *)(in_ECX + 0x1f8) = *(double *)(in_ECX + 0x1f8) * DAT_00a0d630;
  }
  *(undefined4 *)(in_ECX + 0x200) = 0;
  *(undefined4 *)(in_ECX + 0x208) = 0;
  if (*(double *)(in_ECX + 0x1f0) <= 0.0) {
    local_14 = -*(double *)(in_ECX + 0x1f0);
  }
  else {
    local_14 = *(double *)(in_ECX + 0x1f0);
  }
  if (1e-07 <= local_14) {
    if (*(double *)(in_ECX + 0x1f8) <= 0.0) {
      local_1c = -*(double *)(in_ECX + 0x1f8);
    }
    else {
      local_1c = *(double *)(in_ECX + 0x1f8);
    }
    if (1e-07 <= local_1c) {
      if (*(int *)(in_ECX + 0x204) == 1) {
        *(undefined4 *)(in_ECX + 0xb8) = 3;
        uVar3 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_005b8a30(uVar3);
      }
      *(undefined4 *)(in_ECX + 0x204) = 0;
      *(undefined4 *)(in_ECX + 0x200) = 0;
      goto LAB_006e1b0b;
    }
  }
  if (*(int *)(in_ECX + 0x204) == 0) {
    *(undefined4 *)(in_ECX + 0xb8) = 2;
    uVar3 = 1;
    FUN_00404c80(1);
    FUN_004fca20();
    FUN_005b8a30(uVar3);
  }
  *(undefined4 *)(in_ECX + 0x204) = 1;
  *(undefined4 *)(in_ECX + 0x200) = 1;
LAB_006e1b0b:
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0x208) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x670);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0x20c) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x6fc);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0x214) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x704);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0x21c) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x668);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(in_ECX + 0x220) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x66c);
  return;
}




/* vtable slots: CZukeiRitsumen[4], CZukeiTategu[4] */
/* 006e1bc0  FUN_006e1bc0  108 bytes, 0 callers */

void FUN_006e1bc0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xa8) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xa8) + 0x60))();
    if (*(int **)(in_ECX + 0xa8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0xa8) + 4))(1);
    }
    *(undefined4 *)(in_ECX + 0xa8) = 0;
  }
  return;
}




/* vtable slots: CZukeiRitsumen[3] */
/* 006e1c30  FUN_006e1c30  510 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006e1c30(void)

{
  uint uVar1;
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  undefined4 local_63f0;
  CWaitCursor local_63e9;
  int *local_63e8;
  undefined1 local_63e4 [25416];
  undefined4 local_9c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e8e1;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_004fb910(0);
  CWaitCursor::CWaitCursor(&local_63e9);
  local_8 = 0;
  FUN_00446aa0(uVar1);
  local_8._0_1_ = 1;
  FUN_0079dea2(local_63e8[1]);
  local_8._0_1_ = 2;
  local_63f0 = FUN_0040c0e0();
  FUN_0044dd90(local_6408,local_63e8[1]);
  FUN_0044de00(local_6408,local_63e8[1]);
  (**(code **)(*local_63e8 + 0x20))();
  FUN_00464040();
  local_8._0_1_ = 3;
  if (DAT_00a0bd94 != 0) {
    local_63f4 = FUN_00479d80(local_63f0);
    local_9c = local_63f4;
  }
  local_63e8[0x2e] = 4;
  FUN_006e2920(local_63e4,local_6408,local_63e8[0x30],local_63e8[0x31],local_63e8[0x32],
               local_63e8[0x33]);
  if (local_63e8[0x80] == 0) {
    local_63e8[0x2e] = 3;
  }
  else {
    local_63e8[0x2e] = 2;
  }
  FUN_006e0490();
  local_8._0_1_ = 2;
  FUN_004640a0();
  local_8._0_1_ = 1;
  FUN_0079dfff();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_00408b00();
  ExceptionList = local_10;
  return;
}



