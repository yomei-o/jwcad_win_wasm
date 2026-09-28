/* CZukeiTategu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiTategu[1] */
/* 0072b0e0  FUN_0072b0e0  68 bytes, 0 callers */

undefined4 FUN_0072b0e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0072aff0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x348);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiTategu[6] */
/* 0072b250  FUN_0072b250  1790 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0072b250(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  double dVar4;
  undefined8 uVar5;
  undefined1 local_6448 [20];
  double local_6434;
  double local_642c;
  double local_6424;
  double local_641c;
  double local_6414;
  undefined4 *local_6408;
  undefined4 *local_6404;
  double local_6400;
  double local_63f8;
  int *local_63f0;
  undefined1 local_63ec [4];
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940b61;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0xb8) != 0x65) && (*(int *)(in_ECX + 0xb8) != 0x66)) {
    local_63e8 = in_ECX;
    local_14 = uVar1;
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8634)) {
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_0040c0e0();
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_005f6790();
      local_6424 = (double)fVar3;
      *(undefined4 *)(local_63e8 + 0x168) = 0;
      *(undefined8 *)(local_63e8 + 0x180) = 0;
      if (local_6424 <= 1.0) {
        *(undefined4 *)(local_63e8 + 0x168) = 1;
      }
      else {
        *(double *)(local_63e8 + 0x180) = local_6424;
        *(undefined4 *)(local_63e8 + 0x168) = 0;
        if (*(int *)(local_63e8 + 0xb8) == 2) {
          *(undefined4 *)(local_63e8 + 0xb8) = 3;
        }
      }
      if (((*(int *)(local_63e8 + 0x168) != 0) && (*(int *)(local_63e8 + 0xb8) == 3)) &&
         (9e+20 < *(double *)(local_63e8 + 0xf0))) {
        FUN_0044dd90(local_6448,*(undefined4 *)(local_63e8 + 4));
        FUN_0044de00(local_6448,*(undefined4 *)(local_63e8 + 4));
        *(undefined4 *)(local_63e8 + 0xb8) = 2;
      }
      if (*(int *)(local_63e8 + 0x1d8) != 0) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005f6760();
        local_63f8 = (double)fVar3;
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005f6720();
        local_6400 = (double)fVar3;
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005f66f0();
        *(double *)(local_63e8 + 0x1b0) = (double)fVar3;
        if ((*(double *)(local_63e8 + 0x1b8) != local_63f8) ||
           (*(double *)(local_63e8 + 0x1c0) != local_6400)) {
          *(double *)(local_63e8 + 0x1b8) = local_63f8;
          *(double *)(local_63e8 + 0x1c0) = local_6400;
          if (*(int *)(local_63e8 + 0x16c) != 0) {
            dVar4 = (local_63f8 - local_6400) / 2.0;
            FUN_00404c80(uVar1,dVar4);
            iVar2 = FUN_004fca20();
            local_63f0 = (int *)(*(int *)(iVar2 + 0x1a0) + 0xcf0);
            (**(code **)(*local_63f0 + 0x188))(dVar4);
          }
          CStringT<>();
          local_8._0_1_ = 2;
          dVar4 = local_63f8 + local_6400;
          local_6408 = (undefined4 *)FUN_005977f0(0x15df);
          local_8._0_1_ = 3;
          local_6404 = local_6408;
          FUN_004059f0(local_63ec,L"%s = %lg ",*local_6408,dVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_00404770();
          if (*(int *)(local_63e8 + 0x16c) != 0) {
            FUN_00464110();
          }
          FUN_00404920();
          FUN_00404c80();
          FUN_004fca20();
          FUN_00797ece();
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_00404540();
        }
      }
      *(undefined8 *)(local_63e8 + 0x198) = *(undefined8 *)(*(int *)(local_63e8 + 0xac) + 0xb58);
      if (0.001 <= *(double *)(local_63e8 + 0x198)) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005f66c0();
        local_6414 = (double)fVar3;
        if (local_6414 - *(double *)(local_63e8 + 0x198) <= 0.0) {
          local_642c = -(local_6414 - *(double *)(local_63e8 + 0x198));
        }
        else {
          local_642c = local_6414 - *(double *)(local_63e8 + 0x198);
        }
        if (1e-07 < local_642c) {
          uVar5 = *(undefined8 *)(local_63e8 + 0x198);
          FUN_00404c80(uVar5);
          FUN_004fca20();
          FUN_0072c9c0(uVar5);
          *(undefined8 *)(local_63e8 + 0x188) = *(undefined8 *)(local_63e8 + 0x198);
        }
      }
      *(undefined8 *)(local_63e8 + 0x1a0) = *(undefined8 *)(*(int *)(local_63e8 + 0xac) + 0xb60);
      if (0.001 <= *(double *)(local_63e8 + 0x1a0)) {
        FUN_00404c80();
        FUN_004fca20();
        fVar3 = (float10)FUN_005f6820();
        local_641c = (double)fVar3;
        if (local_641c - *(double *)(local_63e8 + 0x1a0) <= 0.0) {
          local_6434 = -(local_641c - *(double *)(local_63e8 + 0x1a0));
        }
        else {
          local_6434 = local_641c - *(double *)(local_63e8 + 0x1a0);
        }
        if (1e-07 < local_6434) {
          uVar5 = *(undefined8 *)(local_63e8 + 0x1a0);
          FUN_00404c80(uVar5);
          FUN_004fca20();
          FUN_0072d580(uVar5);
          *(undefined8 *)(local_63e8 + 400) = *(undefined8 *)(local_63e8 + 0x1a0);
        }
      }
      if (*(int *)(local_63e8 + 0xb8) == 3) {
        FUN_0044dd90(local_6448,*(undefined4 *)(local_63e8 + 4));
        FUN_0044de00(local_6448,*(undefined4 *)(local_63e8 + 4));
        FUN_0072efc0(local_63e4,local_6448,*param_1,param_1[1],param_1[2],param_1[3]);
      }
      FUN_0072bbe0();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTategu[16] */
/* 0072b950  FUN_0072b950  476 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0072b950(void)

{
  int in_ECX;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093365b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0xb8) == 0x65) || (*(int *)(in_ECX + 0xb8) == 0x66)) {
    local_63ec = 1;
  }
  else if (*(int *)(in_ECX + 0xb8) == 1) {
    local_63ec = 0;
  }
  else if (*(int *)(in_ECX + 0xb8) == 7) {
    *(undefined4 *)(in_ECX + 0xb8) = 1;
    FUN_0072bbe0();
    local_63ec = 1;
  }
  else if (*(int *)(in_ECX + 0xb8) == 2) {
    *(undefined4 *)(in_ECX + 0xb8) = 1;
    FUN_0072bbe0();
    local_63ec = 1;
  }
  else if (*(int *)(in_ECX + 0xb8) == 3) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
    FUN_0044de00(local_6400,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(local_63e8 + 0xb8) = 1;
    if (*(int *)(local_63e8 + 0x168) != 0) {
      *(undefined4 *)(local_63e8 + 0xb8) = 2;
    }
    FUN_0072bbe0();
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_63ec = 1;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiTategu[0] */
/* 0072bb90  FUN_0072bb90  16 bytes, 0 callers */

undefined ** FUN_0072bb90(void)

{
  return &PTR_s_CZukeiTategu_0097af1c;
}




/* vtable slots: CZukeiTategu[23] */
/* 0072bce0  FUN_0072bce0  290 bytes, 0 callers */

undefined4 FUN_0072bce0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  if (*(int *)(in_ECX + 0xb8) == 3) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8634)) {
      if (DAT_00a0cc6c == 0) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        piVar3 = (int *)(*(int *)(iVar2 + 0x1a0) + 0xee4);
        *piVar3 = *piVar3 + 1;
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (2 < *(int *)(*(int *)(iVar2 + 0x1a0) + 0xee4)) {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xee4) = 0xfffffffe;
        }
      }
      else {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        piVar3 = (int *)(*(int *)(iVar2 + 0x1a0) + 0xee0);
        *piVar3 = *piVar3 + 1;
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        if (2 < *(int *)(*(int *)(iVar2 + 0x1a0) + 0xee0)) {
          FUN_00404c80();
          iVar2 = FUN_004fca20();
          *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0xee0) = 0;
        }
      }
      FUN_00404c80();
      FUN_0056d7d0();
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CZukeiTategu[46] */
/* 0072be10  FUN_0072be10  252 bytes, 0 callers */

undefined4
FUN_0072be10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_10 = 0xffffffff;
      local_c = 0x14;
      if (*(int *)(in_ECX + 0xb0) == 2) {
        local_c = 0x15;
      }
      iVar2 = FUN_00778a40(1,&local_10,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,local_c);
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




/* vtable slots: CZukeiTategu[47] */
/* 0072bf10  FUN_0072bf10  252 bytes, 0 callers */

undefined4
FUN_0072bf10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
      local_10 = 0xffffffff;
      local_c = 0x14;
      if (*(int *)(in_ECX + 0xb0) == 2) {
        local_c = 0x15;
      }
      iVar2 = FUN_00778a40(2,&local_10,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9074),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,local_c);
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




/* vtable slots: CZukeiTategu[34] */
/* 0072c010  FUN_0072c010  1903 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0072c010(void)

{
  char cVar1;
  uint uID;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  LPSTR in_stack_fffff6e4;
  int in_stack_fffff6e8;
  undefined1 local_910 [4];
  undefined4 local_90c;
  undefined1 local_908 [4];
  undefined4 local_904;
  undefined4 local_900;
  undefined1 local_8fc [4];
  undefined4 local_8f8;
  double local_8f4;
  int *local_8ec;
  int local_8e8;
  int local_8e4;
  undefined4 local_8e0;
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
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940bb6;
  local_10 = ExceptionList;
  uID = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar4 = 0x66;
  local_14 = uID;
  FUN_00404c80(0x66);
  FUN_004fca20();
  FUN_005f60b0(uVar4);
  if (*(int *)(local_8d0[1] + 0x8ce8) != 0) {
    if (local_8d0[0x2c] == 1) {
      cVar1 = FUN_00447350(&DAT_00956338);
      if ((cVar1 != '\0') || (*(int *)(local_8d0[1] + 0x8cf4) == 0)) {
        *(undefined4 *)(local_8d0[1] + 0x8ce8) = 0;
      }
    }
    else if (local_8d0[0x2c] == 2) {
      cVar1 = FUN_00447350(&DAT_00956338);
      if ((cVar1 != '\0') || (*(int *)(local_8d0[1] + 0x8cfc) == 0)) {
        *(undefined4 *)(local_8d0[1] + 0x8ce8) = 0;
      }
    }
    else {
      *(undefined4 *)(local_8d0[1] + 0x8ce8) = 0;
    }
  }
  if (*(int *)(local_8d0[1] + 0x8ce8) == 0) {
    FUN_00403dd0();
    local_8 = 0;
    local_8e4 = ReverseFind();
    local_8f8 = Left(local_8fc,local_8e4);
    FUN_00404920();
    FUN_00403d00(local_8d0[0x2b] + 0x10);
    FUN_00404540();
    local_904 = Mid(local_908,local_8e4 + 1);
    local_8._0_1_ = 1;
    local_900 = local_904;
    FUN_00404860();
    local_8._0_1_ = 0;
    FUN_00404540();
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,2);
    FID_conflict_LoadStringA
              ((HINSTANCE)(local_8d0[0x2c] + 7000),uID,in_stack_fffff6e4,in_stack_fffff6e8);
    local_8e8 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_8dc);
    local_90c = Left(local_910,local_8e8);
    local_8d5 = FUN_00414010(local_90c);
    FUN_00404540();
    if (local_8d5 != '\0') {
      iVar3 = FUN_00404920();
      *(uint *)(local_8d0[0x2b] + 8) = *(ushort *)(iVar3 + local_8e8 * 2) - 0x41;
      local_8e0 = FUN_00596540();
      FUN_005aac30(local_8e0,0);
      if (local_8d0[0x2c] == 1) {
        FUN_00404900();
        *(undefined4 *)(local_8d0[1] + 0x8cf4) = local_8e0;
      }
      if (local_8d0[0x2c] == 2) {
        FUN_00404900();
        *(undefined4 *)(local_8d0[1] + 0x8cfc) = local_8e0;
      }
      if ((DAT_00a0cc6c != 0) && (DAT_00a0cc74 != 0)) {
        DAT_00a0cc74 = 0;
        DAT_00a0cc6c = 0;
        iVar3 = FUN_004f1700();
        if (iVar3 != 0) {
          uVar2 = FUN_00404920();
          FUN_004f7a90(local_8bc,L"\"%s\"",uVar2);
          local_8cc = local_8bc;
          iStack_8c8 = local_8d0[0x2b] + 0x212;
          uStack_8c4 = 0;
          uVar2 = FUN_00404920();
          FUN_00904dec(0,uVar2);
          FUN_004e96f0(0x111,*(undefined4 *)(DAT_00a0b410 + 0x8564),0);
          local_8 = local_8 & 0xffffff00;
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
    local_8 = local_8 & 0xffffff00;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  else {
    if (local_8d0[0x2c] == 1) {
      uVar2 = FUN_00404920();
      FUN_00403d00(local_8d0[0x2b] + 0x212,uVar2);
      FUN_005aac30(*(undefined4 *)(local_8d0[1] + 0x8cf4),1);
    }
    if (local_8d0[0x2c] == 2) {
      uVar2 = FUN_00404920();
      FUN_00403d00(local_8d0[0x2b] + 0x212,uVar2);
      FUN_005aac30(*(undefined4 *)(local_8d0[1] + 0x8cfc),1);
    }
  }
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) == *(int *)(local_8d0[1] + 0x8634)) {
    if (*(int *)(local_8d0[0x2b] + 0x2318c) != 0) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_0072d550();
    }
    local_8f4 = *(double *)(local_8d0[0x2b] + 0xc40);
    if (-1e-07 < local_8f4) {
      if (1e-07 < local_8f4) {
        if (DAT_00a0d62c != 0) {
          local_8f4 = local_8f4 / DAT_00a0d630;
        }
        FUN_00404c80();
        iVar3 = FUN_004fca20();
        local_8ec = (int *)(*(int *)(iVar3 + 0x1a0) + 0x8f8);
        (**(code **)(*local_8ec + 0x188))(local_8f4);
      }
      else {
        FUN_005977f0();
        uVar2 = FUN_00404920();
        FUN_005cf710(local_e4,uVar2);
        FUN_00404770();
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797ece();
      }
    }
  }
  local_8d0[0x2e] = 1;
  (**(code **)(*local_8d0 + 0x20))();
  local_8d0[0x2f] = -1;
  FUN_0072c940();
  FUN_00404c80();
  FUN_0056d7d0();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTategu[25] */
/* 0072c780  FUN_0072c780  19 bytes, 0 callers */

void FUN_0072c780(void)

{
  FUN_0072e660();
  return;
}




/* vtable slots: CZukeiTategu[32] */
/* 0072c7a0  FUN_0072c7a0  38 bytes, 0 callers */

void FUN_0072c7a0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = 0x66;
  FUN_00404c80(0x66,0);
  FUN_004fca20();
  FUN_005f60b0(uVar1,uVar2);
  return;
}




/* vtable slots: CZukeiTategu[50] */
/* 0072c7d0  FUN_0072c7d0  142 bytes, 0 callers */

void FUN_0072c7d0(double param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8634)) {
    if (DAT_00a0d62c != 0) {
      param_1 = param_1 / DAT_00a0d630;
    }
    FUN_00404c80(param_1);
    iVar1 = FUN_004fca20();
    (**(code **)(*(int *)(*(int *)(iVar1 + 0x1a0) + 0x8f8) + 0x188))(param_1);
  }
  return;
}




/* vtable slots: CZukeiTategu[51] */
/* 0072c860  FUN_0072c860  221 bytes, 0 callers */

void FUN_0072c860(undefined4 param_1,undefined4 param_2,double param_3)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093cd2d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8634)) {
    if (DAT_00a0d62c != 0) {
      param_3 = param_3 / DAT_00a0d630;
    }
    FUN_00404c80(uVar1,param_3);
    iVar2 = FUN_004fca20();
    (**(code **)(*(int *)(*(int *)(iVar2 + 0x1a0) + 0x8f8) + 0x188))(param_3);
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  else {
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTategu[9] */
/* 0072ca00  FUN_0072ca00  1990 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0072ca00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined1 local_6484 [8];
  undefined4 local_647c;
  undefined4 local_6478;
  undefined4 local_6474;
  undefined4 local_6470;
  undefined4 local_646c;
  undefined4 local_6468;
  undefined4 local_6464;
  undefined4 local_6460;
  undefined4 local_645c;
  undefined4 local_6458;
  undefined4 local_6454;
  undefined4 local_6450;
  undefined4 local_644c;
  undefined4 local_6448;
  undefined4 local_6444;
  undefined4 local_6440;
  undefined4 local_643c;
  int local_6438;
  int local_6434;
  int local_641c;
  int *local_6418;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940bfb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(local_6418[1]);
  local_8._0_1_ = 1;
  local_647c = 0;
  FUN_004b6d60(local_6484,param_2,param_3,param_4,param_5);
  if (local_6418[0x2e] == 0x65) {
    local_6434 = FUN_005a1910(param_1,param_2,param_3,param_4,param_5);
    if (local_6434 == 0) {
      local_643c = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (local_6434 == -1) {
      local_6440 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_643c = local_6440;
    }
    else {
      local_6418[0x2e] = 1;
      FUN_0072bbe0();
      local_6444 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_643c = local_6444;
    }
  }
  else if (local_6418[0x2e] == 0x66) {
    local_6438 = FUN_005a1720(param_1,param_2,param_3,param_4,param_5);
    if (local_6438 == 0) {
      local_6448 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_643c = local_6448;
    }
    else if (local_6438 == -1) {
      local_6418[0x2e] = 0x65;
      FUN_0072bbe0();
      local_644c = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_643c = local_644c;
    }
    else {
      FUN_0072bbe0();
      local_6418[0x2e] = 1;
      (**(code **)(*local_6418 + 0x20))();
      local_6450 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_643c = local_6450;
    }
  }
  else if (local_6418[0x2e] == 1) {
    if (param_1 == 0x231d) {
      local_6418[0x2e] = 7;
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      FUN_0072bbe0();
      local_6454 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_643c = local_6454;
    }
    else {
      (**(code **)(*local_6418 + 0x20))();
      local_f0 = 1;
      local_ec = 1;
      iVar1 = FUN_0044a270(3,local_6418[1],&param_2,&local_641c,1);
      if (iVar1 == 0) {
        local_6458 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_643c = local_6458;
      }
      else {
        iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar1 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(local_6418[1] + 0x8f24),
                       *(undefined4 *)(local_6418[1] + 0x8f28),0,0);
          local_645c = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_643c = local_645c;
        }
        else {
          iVar1 = FUN_0072eb20(*(undefined4 *)(local_641c + 8),*(undefined4 *)(local_641c + 0xc),
                               *(undefined4 *)(local_641c + 0x10),*(undefined4 *)(local_641c + 0x14)
                               ,*(undefined4 *)(local_641c + 0x18),
                               *(undefined4 *)(local_641c + 0x1c),*(undefined4 *)(local_641c + 0x20)
                               ,*(undefined4 *)(local_641c + 0x24));
          if (iVar1 == 0) {
            local_6460 = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            local_643c = local_6460;
          }
          else {
            local_6464 = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            local_643c = local_6464;
          }
        }
      }
    }
  }
  else if (local_6418[0x2e] == 7) {
    (**(code **)(*local_6418 + 0x20))();
    iVar1 = FUN_0072eb20(local_6418[0x48],local_6418[0x49],local_6418[0x4a],local_6418[0x4b],param_2
                         ,param_3,param_4,param_5);
    if (iVar1 == 0) {
      local_6468 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_643c = local_6468;
    }
    else {
      local_646c = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_643c = local_646c;
    }
  }
  else if (local_6418[0x2e] == 2) {
    (**(code **)(*local_6418 + 0x20))();
    FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
    local_6418[0x2e] = 3;
    FUN_0072bbe0();
    FUN_00404c80();
    FUN_0056d7d0();
    local_6470 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_643c = local_6470;
  }
  else if (local_6418[0x2e] == 3) {
    FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
    local_6474 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_643c = local_6474;
  }
  else {
    FUN_00404c80();
    FUN_0056d7d0();
    local_6478 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_643c = local_6478;
  }
  ExceptionList = local_10;
  return local_643c;
}




/* vtable slots: CZukeiTategu[11] */
/* 0072d1d0  FUN_0072d1d0  838 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0072d1d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009404f0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  if ((in_ECX[0x2e] == 0x65) || (in_ECX[0x2e] == 0x66)) {
    uVar1 = FUN_0072ca00(param_1,param_2,param_3,param_4,param_5);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else if (in_ECX[0x2e] == 1) {
    iVar2 = FUN_00451eb0(in_ECX[1],&param_2,1);
    if (iVar2 == 0) {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else {
      (**(code **)(*in_ECX + 0x20))();
      in_ECX[0x2e] = 7;
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      FUN_0072bbe0();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
  }
  else if (in_ECX[0x2e] == 7) {
    iVar2 = FUN_00451eb0(in_ECX[1],&param_2,1);
    if (iVar2 == 0) {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else {
      (**(code **)(*in_ECX + 0x20))();
      iVar2 = FUN_0072eb20(in_ECX[0x48],in_ECX[0x49],in_ECX[0x4a],in_ECX[0x4b],param_2,param_3,
                           param_4,param_5);
      if (iVar2 == 0) {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
  }
  else {
    iVar2 = FUN_00451eb0(in_ECX[1],&param_2,1);
    if (iVar2 == 1) {
      uVar1 = FUN_0072ca00(param_1,param_2,param_3,param_4,param_5);
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




/* vtable slots: CZukeiTategu[8] */
/* 0072d5c0  FUN_0072d5c0  1521 bytes, 1 callers */

void FUN_0072d5c0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  
  *(undefined8 *)(in_ECX + 0x198) = *(undefined8 *)(*(int *)(in_ECX + 0xac) + 0xb58);
  *(undefined8 *)(in_ECX + 0x1a0) = *(undefined8 *)(*(int *)(in_ECX + 0xac) + 0xb60);
  *(undefined8 *)(in_ECX + 0x1f0) = *(undefined8 *)(*(int *)(in_ECX + 0xac) + 0xb70);
  *(undefined8 *)(in_ECX + 0x1f8) = *(undefined8 *)(*(int *)(in_ECX + 0xac) + 0xb78);
  *(undefined8 *)(in_ECX + 0x200) = *(undefined8 *)(*(int *)(in_ECX + 0xac) + 0xb80);
  *(undefined8 *)(in_ECX + 0x1d0) = *(undefined8 *)(*(int *)(in_ECX + 0xac) + 0xb88);
  *(undefined4 *)(in_ECX + 0x210) = *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0xc58);
  *(undefined4 *)(in_ECX + 0x208) = *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0xc50);
  *(undefined4 *)(in_ECX + 0x20c) = *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0xc54);
  *(undefined4 *)(in_ECX + 0x16c) = *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0x2318c);
  *(undefined4 *)(in_ECX + 0x1d8) = *(undefined4 *)(*(int *)(in_ECX + 0xac) + 0x23190);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8634)) {
    FUN_00404c80(0);
    FUN_004fca20();
    fVar3 = (float10)FUN_005f66c0();
    if ((double)fVar3 <= 30.0) {
      *(undefined8 *)(in_ECX + 0x188) = 0x4051800000000000;
    }
    else {
      *(double *)(in_ECX + 0x188) = (double)fVar3;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_005f6820();
    if ((double)fVar3 <= 10.0) {
      *(undefined8 *)(in_ECX + 400) = 0x4041800000000000;
    }
    else {
      *(double *)(in_ECX + 400) = (double)fVar3;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_005f6790();
    *(undefined4 *)(in_ECX + 0x168) = 0;
    *(undefined8 *)(in_ECX + 0x180) = 0;
    if ((double)fVar3 <= 1.0) {
      *(undefined4 *)(in_ECX + 0x168) = 1;
    }
    else {
      *(double *)(in_ECX + 0x180) = (double)fVar3;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_005f66f0();
    if ((double)fVar3 < 0.0) {
      *(undefined8 *)(in_ECX + 0x1a8) = 0xbff0000000000000;
      *(undefined4 *)(in_ECX + 0x174) = 1;
    }
    else {
      *(double *)(in_ECX + 0x1a8) = (double)fVar3;
      *(undefined4 *)(in_ECX + 0x174) = 0;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_005f6760();
    if ((double)fVar3 <= 1.0) {
      *(undefined8 *)(in_ECX + 0x1e0) = 0x4052c00000000000;
    }
    else {
      *(double *)(in_ECX + 0x1e0) = (double)fVar3;
    }
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_005f6720();
    if ((double)fVar3 <= 1.0) {
      *(undefined8 *)(in_ECX + 0x1e8) = 0x4052c00000000000;
    }
    else {
      *(double *)(in_ECX + 0x1e8) = (double)fVar3;
    }
    FUN_00404c80();
    FUN_004fca20();
    iVar1 = FUN_0072bb30();
    *(int *)(in_ECX + 0x170) = 2 - iVar1;
    FUN_00404c80();
    FUN_004fca20();
    uVar2 = FUN_0072bb50();
    *(undefined4 *)(in_ECX + 0x178) = uVar2;
    FUN_00404c80();
    FUN_004fca20();
    uVar2 = FUN_0072bba0();
    *(undefined4 *)(in_ECX + 0x1c8) = uVar2;
    iVar1 = *(int *)(in_ECX + 0x164);
    FUN_00404c80();
    FUN_004fca20();
    uVar2 = FUN_0072bbc0();
    *(undefined4 *)(in_ECX + 0x164) = uVar2;
    FUN_00404c80();
    FUN_004fca20();
    uVar2 = FUN_0072bb70();
    *(undefined4 *)(in_ECX + 0x160) = uVar2;
    if (*(int *)(in_ECX + 0x16c) != 0) {
      *(undefined4 *)(in_ECX + 0x170) = 1;
      *(undefined4 *)(in_ECX + 0x174) = 0;
      FUN_00404c80();
      FUN_004fca20();
      fVar3 = (float10)FUN_005f66f0();
      *(double *)(in_ECX + 0x1a8) = (double)fVar3;
      if (*(int *)(in_ECX + 0x164) != 0) {
        *(ulonglong *)(in_ECX + 0x1a8) = *(ulonglong *)(in_ECX + 0x1a8) ^ 0x8000000000000000;
      }
      if (((*(int *)(in_ECX + 0x16c) == 2) && (*(int *)(in_ECX + 0xb0) == 1)) &&
         (*(int *)(in_ECX + 0x164) != iVar1)) {
        if (*(int *)(in_ECX + 0x164) == 0) {
          *(undefined4 *)(in_ECX + 0x160) = 0;
          FUN_00404c80();
          FUN_004fca20();
          FUN_0072d520();
        }
        else {
          *(undefined4 *)(in_ECX + 0x160) = 1;
          FUN_00404c80();
          FUN_004fca20();
          FUN_0072d520();
        }
        FUN_00404c80();
        FUN_004fca20();
        FUN_0072d550();
      }
    }
    FUN_0072ee60(*(undefined8 *)(in_ECX + 0xd0),*(undefined8 *)(in_ECX + 0xd8),
                 *(undefined8 *)(in_ECX + 0xe0),*(undefined8 *)(in_ECX + 0xe8));
    if ((*(int *)(in_ECX + 0x160) != 0) && (*(int *)(in_ECX + 0xb0) == 2)) {
      *(undefined4 *)(in_ECX + 0x160) = 0;
      FUN_0072ee60(*(undefined8 *)(in_ECX + 0xe0),*(undefined8 *)(in_ECX + 0xe8),
                   *(undefined8 *)(in_ECX + 0xd0),*(undefined8 *)(in_ECX + 0xd8));
    }
  }
  return;
}




/* vtable slots: CZukeiTategu[3] */
/* 0072dbc0  FUN_0072dbc0  499 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0072dbc0(void)

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
  (**(code **)(*local_63e8 + 0x20))();
  FUN_00464040();
  local_8._0_1_ = 3;
  if (DAT_00a0bd94 != 0) {
    local_63f4 = FUN_00479d80(local_63f0);
    local_9c = local_63f4;
  }
  FUN_0044dd90(local_6408,local_63e8[1]);
  FUN_0044de00(local_6408,local_63e8[1]);
  local_63e8[0x2e] = 4;
  FUN_0072efc0(local_63e4,local_6408,local_63e8[0x30],local_63e8[0x31],local_63e8[0x32],
               local_63e8[0x33]);
  local_63e8[0x2e] = 1;
  local_63e8[0x3c] = 0x4560aa5c;
  local_63e8[0x3d] = 0x444ad581;
  FUN_0072bbe0();
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




/* vtable slots: CZukeiTategu[5] */
/* 0072eac0  FUN_0072eac0  81 bytes, 0 callers */

void FUN_0072eac0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xb0);
  if (*(int *)(in_ECX + 0xb8) == 0x65) {
    FUN_005a11c0();
  }
  if (*(int *)(in_ECX + 0xb8) == 0x66) {
    FUN_005a2c30(uVar1);
  }
  return;
}



