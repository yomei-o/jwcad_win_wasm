/* CZukeiKigouHenkei -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiKigouHenkei[1] */
/* 006a4430  FUN_006a4430  68 bytes, 0 callers */

undefined4 FUN_006a4430(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006a4280();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x6898);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiKigouHenkei[6] */
/* 006a4a00  FUN_006a4a00  1786 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006a4a00(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  undefined1 local_6428 [24];
  undefined4 local_6410;
  undefined4 local_640c;
  undefined4 local_6404;
  undefined1 local_6400 [4];
  int local_63fc;
  int *local_63f8;
  undefined1 local_63f4 [25568];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c30c;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x1929] == 0) {
    if (in_ECX[0x1928] == 0) {
      local_63f8 = in_ECX;
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2();
      local_8._0_1_ = 1;
      if ((local_63f8[0x1926] == 0x2c) && (local_63f8[0x192a] == 20000)) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_63f8[1] + 0x8600)) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_00580970();
          FUN_00404c80();
          FUN_004fca20();
          FUN_0057fb10();
          FUN_00404c80();
          FUN_004fca20();
          FUN_0057f8b0();
          FUN_0044dd90();
          FUN_0044de00();
          local_63f8[0x1926] = 0x2b;
          local_63fc = local_63f8[0x198a] % 1000;
          FUN_00403dd0();
          local_8._0_1_ = 2;
          FUN_00404c80();
          FUN_004fca20();
          FUN_005835f0();
          FUN_00404c80();
          FUN_004fca20();
          local_6410 = FUN_00581420();
          local_8._0_1_ = 3;
          local_640c = local_6410;
          FUN_00404860();
          local_8._0_1_ = 2;
          FUN_00404540();
          local_63f8[0x1990] = 1;
          FUN_006b0230(local_63f4,local_6428,local_63f8[0x198a],local_63f8[0x198b],
                       local_63f8[0x198c],local_63f8[0x198d],*(undefined8 *)(local_63f8 + 0x1982),
                       *(undefined8 *)(local_63f8 + 0x1984));
          local_63f8[0x1990] = 0;
          FUN_00404860();
          local_63f8[0x1926] = 0x2c;
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
      else {
        if (local_63f8[0x19c4] != 0) {
          local_63f8[0x192a] = 0;
          FUN_006a4480();
        }
        if (local_63f8[0x19c5] != 0) {
          local_63f8[0x19c5] = 0;
          CStringT<>();
          local_8._0_1_ = 4;
          FUN_004059f0();
          FUN_00403dd0(local_6400);
          FUN_00516ac0();
          local_8._0_1_ = 1;
          FUN_00404540();
        }
        if ((local_63f8[0x1926] == 0x65) || (local_63f8[0x1926] == 0x66)) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          FUN_00404c80();
          iVar1 = FUN_004fca20();
          if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_63f8[1] + 0x863c)) {
            local_6404 = 0;
            if (local_63f8[0x1967] == 0) {
              local_6404 = 1;
              if ((*(int *)local_63f8[0x1947] != 0) || (*(int *)(local_63f8[0x1947] + 4) != 0)) {
                local_6404 = 0xffffffff;
              }
              FUN_00404c80();
              FUN_004fca20();
              fVar2 = (float10)FUN_005cc790();
              *(double *)(local_63f8 + 0x1a18) = (double)fVar2;
              FUN_00404c80();
              iVar1 = FUN_004fca20();
              *(undefined8 *)(*(int *)(iVar1 + 0x1a0) + 0xb8) = *(undefined8 *)(local_63f8 + 0x1a18)
              ;
            }
            else {
              local_63f8[0x1a18] = 0;
              local_63f8[0x1a19] = 0;
            }
            FUN_00404c80();
            FUN_004fca20();
            FUN_005cbd50();
          }
          FUN_0040c0e0();
          if ((local_63f8[0x1966] == local_63f8[0x1967]) && (*(int *)(local_63f8[0x1947] + 4) == 0))
          {
            FUN_0044dd90();
            FUN_0044de00();
            FUN_004988c0();
            (**(code **)(*local_63f8 + 0x20))();
            FUN_006a5c90();
          }
          FUN_006ac610();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
    }
    else {
      (**(code **)(*(int *)in_ECX[0x1928] + 0x18))();
    }
  }
  else {
    in_ECX[0x1929] = 0;
    FUN_006a4480();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKigouHenkei[16] */
/* 006a5100  FUN_006a5100  1071 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006a5100(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092ce3b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x64a0) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_0044de00(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_63fc);
    FUN_00449d60(local_63fc,*(undefined4 *)(local_63e8 + 4),1);
    if (*(int *)(local_63e8 + 0x6498) == 0x29) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else if (*(int *)(local_63e8 + 0x6498) == 0x2a) {
      *(undefined4 *)(local_63e8 + 0x65a0) = 0;
      *(undefined4 *)(local_63e8 + 0x6598) = 0;
      *(undefined4 *)(local_63e8 + 0x6498) = 0x29;
      FUN_006ac610();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 1;
    }
    else if (((*(int *)(local_63e8 + 0x659c) == 0) && (**(int **)(local_63e8 + 0x651c) != 0)) &&
            (*(int *)(*(int *)(local_63e8 + 0x651c) + 4) == 0)) {
      *(undefined4 *)(*(int *)(local_63e8 + 0x651c) + 4) = **(undefined4 **)(local_63e8 + 0x651c);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 1;
    }
    else if (*(int *)(local_63e8 + 0x6498) == 0x2b) {
      if (*(int *)(local_63e8 + 0x6598) < 1) {
        if (*(int *)(local_63e8 + 0x6490) == 0) {
          FUN_006ac610();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          *(undefined4 *)(local_63e8 + 0x6490) = 0;
          *(undefined4 *)(local_63e8 + 0x6494) = 1;
          FUN_006a5900();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 1;
        }
      }
      else {
        *(undefined4 *)(local_63e8 + 0x65a0) = 0;
        *(undefined4 *)(local_63e8 + 0x6598) = 0;
        *(undefined4 *)(local_63e8 + 0x6498) = 0x29;
        FUN_006ac610();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 1;
      }
    }
    else {
      if (*(int *)(local_63e8 + 0x6498) == 0x1af) {
        *(undefined4 *)(local_63e8 + 0x6498) = 0x2b;
        FUN_006a5900();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 1;
    }
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x40))();
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiKigouHenkei[0] */
/* 006a5590  FUN_006a5590  16 bytes, 0 callers */

undefined ** FUN_006a5590(void)

{
  return &PTR_s_CZukeiKigouHenkei_00979730;
}




/* vtable slots: CZukeiKigouHenkei[23] */
/* 006acb50  FUN_006acb50  109 bytes, 0 callers */

undefined4 FUN_006acb50(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x863c)) {
    if (DAT_00a0cc6c == 0) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_005cc310();
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      FUN_005cc1c0();
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiKigouHenkei[46] */
/* 006acbc0  FUN_006acbc0  326 bytes, 0 callers */

undefined4
FUN_006acbc0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int in_ECX;
  undefined4 local_c;
  
  if (DAT_00a0c7c0 == 0) {
    local_c = 0;
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      if ((param_2 == 0xc) && (*(int *)(in_ECX + 0x64a8) == 20000)) {
        if (param_3 == 1) {
          FUN_005168b0(0x2732,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                       *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          local_c = FUN_006ac410(param_4,param_5,param_6,param_7);
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




/* vtable slots: CZukeiKigouHenkei[34] */
/* 006acd10  FUN_006acd10  1611 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006acd10(void)

{
  char cVar1;
  uint uID;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  LPSTR unaff_ESI;
  CSimpleStringT<wchar_t,0> *pCVar4;
  int in_stack_fffff7c8;
  undefined1 local_834 [4];
  undefined4 local_830;
  undefined1 local_82c [4];
  undefined4 local_828;
  undefined4 local_824;
  undefined1 local_820 [4];
  undefined4 local_81c;
  undefined4 local_818;
  int local_814;
  int local_810;
  CSimpleStringT<wchar_t,0> local_80c [7];
  char local_805;
  int *local_800;
  undefined1 *local_7fc;
  int iStack_7f8;
  undefined4 uStack_7f4;
  undefined1 local_7ec [2008];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c586;
  local_10 = ExceptionList;
  uID = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0x1924] = 0;
  in_ECX[0x19c3] = 0;
  local_14 = uID;
  if (in_ECX[0x1928] == 0) {
    in_ECX[0x19c2] = 0;
    local_800 = in_ECX;
    if ((*(int *)(in_ECX[1] + 0x8ce8) != 0) &&
       ((cVar1 = FUN_00447350(&DAT_00956338,in_ECX[1] + 0x8d08), cVar1 != '\0' ||
        (*(int *)(local_800[1] + 0x8d0c) == 0)))) {
      *(undefined4 *)(local_800[1] + 0x8ce8) = 0;
    }
    if (*(int *)(local_800[1] + 0x8ce8) == 0) {
      FUN_00403dd0(local_800[0x2a] + 0x6d4);
      local_8 = 0;
      local_810 = ReverseFind(0x5c);
      local_81c = Left(local_820,local_810);
      uVar2 = FUN_00404920();
      FUN_00403d00(local_800[0x1920] + 0x10,uVar2);
      FUN_00404540();
      local_828 = Mid(local_82c,local_810 + 1);
      local_8._0_1_ = 1;
      local_824 = local_828;
      FUN_00404860(local_828);
      local_8._0_1_ = 0;
      FUN_00404540();
      CStringT<>();
      local_8._0_1_ = 2;
      FID_conflict_LoadStringA
                ((HINSTANCE)(local_800[0x1921] + 7000),uID,unaff_ESI,in_stack_fffff7c8);
      local_814 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_80c);
      pCVar4 = local_80c;
      local_830 = Left(local_834,local_814);
      local_805 = FUN_00414010(local_830,pCVar4);
      FUN_00404540();
      if (local_805 != '\0') {
        iVar3 = FUN_00404920();
        *(uint *)(local_800[0x1920] + 8) = *(ushort *)(iVar3 + local_814 * 2) - 0x41;
        local_818 = FUN_00596540();
        FUN_00404860(local_800 + 0x1949);
        DAT_00a0bc28 = local_800[0x194a];
        FUN_005aac30(local_818,0);
        FUN_00404900(local_800[0x1920] + 0x212);
        *(undefined4 *)(local_800[1] + 0x8d0c) = local_818;
        if ((DAT_00a0cc6c != 0) && (DAT_00a0cc74 != 0)) {
          DAT_00a0cc74 = 0;
          DAT_00a0cc6c = 0;
          iVar3 = FUN_004f1700(1);
          if (iVar3 != 0) {
            uVar2 = FUN_00404920();
            FUN_004f7a90(local_7ec,L"\"%s\"",uVar2);
            local_7fc = local_7ec;
            iStack_7f8 = local_800[0x1920] + 0x212;
            uStack_7f4 = 0;
            uVar2 = FUN_00404920(&local_7fc);
            FUN_00904dec(0,uVar2);
            FUN_004e96f0(0x111,*(undefined4 *)(DAT_00a0b410 + 0x8564),0);
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
      FUN_00403d00(local_800[0x1920] + 0x212,uVar2);
      FUN_005aac30(*(undefined4 *)(local_800[1] + 0x8d0c),1);
    }
    (**(code **)(*local_800 + 0x20))();
    local_800[0x192b] = *(int *)(local_800[0x1920] + 0xb50);
    local_800[0x192d] = 0;
    local_800[0x192c] = 0;
    FUN_006af630();
    local_800[0x1968] = 0;
    local_800[0x1966] = 0;
    if (local_800[0x194c] == 10) {
      local_800[0x195a] = 0;
      local_800[0x195b] = 0;
      local_800[0x1958] = 0;
      local_800[0x1959] = 0;
      local_800[0x1956] = 0;
      local_800[0x1957] = 0;
      local_800[0x1954] = 0;
      local_800[0x1955] = 0;
      local_800[0x1926] = 0x2c;
      FUN_006a55a0();
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      *(undefined4 *)(local_800[0x1947] + 4) = *(undefined4 *)local_800[0x1947];
      if (local_800[0x1967] == 0) {
        local_800[0x1926] = 0x2b;
      }
      else {
        local_800[0x1926] = 0x29;
      }
      FUN_00404c80();
      FUN_0056d7d0();
    }
  }
  else {
    (**(code **)(*(int *)in_ECX[0x1928] + 0x88))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKigouHenkei[25] */
/* 006ad360  FUN_006ad360  378 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006ad360(void)

{
  int in_ECX;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x64a0) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_0044de00(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_63fc);
    FUN_00449d60(local_63fc,*(undefined4 *)(local_63e8 + 4),1);
    *(undefined4 *)(local_63e8 + 0x65a0) = 0;
    *(undefined4 *)(local_63e8 + 0x6598) = 0;
    *(undefined4 *)(local_63e8 + 0x6498) = 0x29;
    FUN_006aff00();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x64a0) + 100))();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKigouHenkei[26] */
/* 006ad4e0  FUN_006ad4e0  633 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006ad4e0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  int local_63f0;
  int local_63ec;
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
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      local_63e8 = in_ECX;
      FUN_00446aa0(local_14);
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
      local_8._0_1_ = 1;
      local_63ec = *(int *)(local_63e8 + 4);
      if (local_63ec == 0) {
        local_63f0 = 0;
      }
      else {
        local_63f0 = local_63ec + 0x88;
      }
      FUN_00454890(local_63f0);
      FUN_0044dd90(local_6408,*(undefined4 *)(local_63e8 + 4));
      FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_6408);
      FUN_00449d60(local_6408,*(undefined4 *)(local_63e8 + 4),1);
      if (*(int *)(local_63e8 + 0x64b0) < 1) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        if (*(int *)(*(int *)(local_63e8 + 0x6480) + 0xb50) != *(int *)(local_63e8 + 0x64b0)) {
          iVar1 = FUN_006ae270(*(undefined4 *)(local_63e8 + 0x64b0));
          if (iVar1 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return;
          }
          local_63f4 = *(undefined4 *)(local_63e8 + 0x64b0);
          *(undefined4 *)(local_63e8 + 0x64b0) =
               *(undefined4 *)(*(int *)(local_63e8 + 0x6480) + 0xb50);
          *(undefined4 *)(*(int *)(local_63e8 + 0x6480) + 0xb50) = local_63f4;
          FUN_006ae310();
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x68))();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKigouHenkei[27] */
/* 006ad760  FUN_006ad760  130 bytes, 0 callers */

void FUN_006ad760(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      if (*(int *)(in_ECX + 0x648c) == 0) {
        FUN_00404c80();
        FUN_0056d7d0();
      }
      else {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
        FUN_00404c80();
        FUN_0056d200();
      }
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x6c))();
    }
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[28] */
/* 006ad7f0  FUN_006ad7f0  88 bytes, 0 callers */

void FUN_006ad7f0(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x70))();
    }
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[29] */
/* 006ad850  FUN_006ad850  198 bytes, 0 callers */

void FUN_006ad850(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      if ((*(int *)(in_ECX + 0x6498) == 0x2b) || (*(int *)(in_ECX + 0x6498) == 0x1af)) {
        *(int *)(in_ECX + 0x6490) = *(int *)(in_ECX + 0x6490) + 1;
        if (2 < *(int *)(in_ECX + 0x6490)) {
          *(undefined4 *)(in_ECX + 0x6490) = 0;
          *(undefined4 *)(in_ECX + 0x6498) = 0x2b;
          *(undefined4 *)(in_ECX + 0x6494) = 1;
        }
        FUN_006a5900();
      }
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x74))();
    }
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[30] */
/* 006ad920  FUN_006ad920  88 bytes, 0 callers */

void FUN_006ad920(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x78))();
    }
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[31] */
/* 006ad980  FUN_006ad980  88 bytes, 0 callers */

void FUN_006ad980(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x7c))();
    }
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[32] */
/* 006ad9e0  FUN_006ad9e0  91 bytes, 0 callers */

void FUN_006ad9e0(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x80))();
    }
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[33] */
/* 006ada40  FUN_006ada40  91 bytes, 0 callers */

void FUN_006ada40(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      FUN_00404c80();
      FUN_0056d7d0();
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x84))();
    }
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[36] */
/* 006adaa0  FUN_006adaa0  1563 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006adaa0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined1 *puStack_6454;
  uint uStack_6450;
  undefined1 local_642c [20];
  undefined4 local_6418;
  undefined1 *local_6414;
  undefined1 local_640c [4];
  undefined1 *local_6408;
  undefined1 *local_6404;
  undefined1 local_6400 [4];
  undefined1 *local_63fc;
  undefined1 *local_63f8;
  int local_63f4;
  undefined1 local_63f0 [4];
  int local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c5f7;
  local_10 = ExceptionList;
  uStack_6450 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0x6498) != 0x65) && (*(int *)(in_ECX + 0x6498) != 0x66)) {
    local_14 = uStack_6450;
    if (*(int *)(in_ECX + 0x64a0) == 0) {
      if (*(int *)(in_ECX + 0x64a8) == 20000) {
        puStack_6454 = (undefined1 *)0x6adb50;
        local_63e8 = in_ECX;
        FUN_006a5b30();
        local_63ec = *(int *)(local_63e8 + 0x6628) % 1000;
        puStack_6454 = (undefined1 *)0x6adb6f;
        FUN_00404c80();
        puStack_6454 = (undefined1 *)0x6adb76;
        iVar2 = FUN_004fca20();
        if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8600)) {
          puStack_6454 = (undefined1 *)(*(int *)(local_63e8 + 0x6504) + local_63ec * 4);
          FUN_00403dd0();
          local_8 = 0;
          puStack_6454 = (undefined1 *)0x1;
          FUN_00404c80();
          FUN_004fca20();
          FUN_005835f0();
          puStack_6454 = local_6400;
          FUN_00404c80();
          FUN_004fca20();
          puStack_6454 = (undefined1 *)FUN_00581420();
          local_8._0_1_ = 1;
          local_63fc = puStack_6454;
          local_63f8 = puStack_6454;
          FUN_00404860();
          local_8 = (uint)local_8._1_3_ << 8;
          puStack_6454 = (undefined1 *)0x6adc37;
          FUN_00404540();
          puStack_6454 = (undefined1 *)(*(int *)(local_63e8 + 0x6504) + local_63ec * 4);
          cVar1 = FUN_00447350(&DAT_00956338);
          if (cVar1 != '\0') {
            puStack_6454 = (undefined1 *)(local_63e8 + 0x65e8);
            FUN_00404860();
          }
          puStack_6454 = local_640c;
          FUN_00404c80();
          FUN_004fca20();
          puStack_6454 = (undefined1 *)FUN_00581270();
          local_8._0_1_ = 2;
          local_6408 = puStack_6454;
          local_6404 = puStack_6454;
          FUN_00404860();
          local_8 = (uint)local_8._1_3_ << 8;
          puStack_6454 = (undefined1 *)0x6adceb;
          FUN_00404540();
          if ((*(int *)(local_63e8 + 0x6868) != 0) && (*(int *)(local_63e8 + 0x6498) == 0x2c)) {
            puStack_6454 = (undefined1 *)(*(int *)(local_63e8 + 0x6504) + local_63ec * 4);
            cVar1 = FUN_00447350(&DAT_00956338);
            if (cVar1 != '\0') {
              puStack_6454 = *(undefined1 **)(local_63e8 + 0x64ac);
              iVar2 = FUN_006ae270();
              if (iVar2 == 0) {
                local_8 = 0xffffffff;
                puStack_6454 = (undefined1 *)0x6add6d;
                FUN_00404540();
                ExceptionList = local_10;
                return;
              }
              *(undefined4 *)(local_63e8 + 0x64b0) =
                   *(undefined4 *)(*(int *)(local_63e8 + 0x6480) + 0xb50);
              *(undefined4 *)(*(int *)(local_63e8 + 0x6480) + 0xb50) =
                   *(undefined4 *)(local_63e8 + 0x64ac);
              *(undefined4 *)(local_63e8 + 0x64a8) = 0;
              puStack_6454 = (undefined1 *)0x6addc9;
              FUN_006ae310();
              *(undefined4 *)(*(int *)(local_63e8 + 0x651c) + 4) =
                   **(undefined4 **)(local_63e8 + 0x651c);
              local_8 = 0xffffffff;
              puStack_6454 = (undefined1 *)0x6ade09;
              FUN_00404540();
              ExceptionList = local_10;
              return;
            }
          }
          if (-1 < *(int *)(local_63e8 + 0x65f0)) {
            puStack_6454 = (undefined1 *)(*(int *)(local_63e8 + 0x6504) + local_63ec * 4);
            FUN_00404860();
            puStack_6454 = (undefined1 *)0x6ade4d;
            FUN_00464040();
            local_8._0_1_ = 3;
            local_6414 = (undefined1 *)&puStack_6454;
            FUN_00403dd0(local_63e8 + 0x6600);
            local_6418 = FUN_0047f500();
            puStack_6454 = (undefined1 *)0x6adeac;
            FUN_00404540();
            local_8 = (uint)local_8._1_3_ << 8;
            puStack_6454 = (undefined1 *)0x6adebb;
            FUN_004640a0();
          }
          puStack_6454 = (undefined1 *)0x6adec6;
          FUN_00446aa0();
          local_8._0_1_ = 4;
          puStack_6454 = *(undefined1 **)(local_63e8 + 4);
          FUN_0079dea2();
          local_8._0_1_ = 5;
          puStack_6454 = (undefined1 *)((ulonglong)*(undefined8 *)(local_63e8 + 0x6620) >> 0x20);
          FUN_006b0230(local_63e4,local_642c,*(undefined4 *)(local_63e8 + 0x6628),
                       *(undefined4 *)(local_63e8 + 0x662c),*(undefined4 *)(local_63e8 + 0x6630),
                       *(undefined4 *)(local_63e8 + 0x6634),*(undefined8 *)(local_63e8 + 0x6608),
                       *(undefined8 *)(local_63e8 + 0x6610),
                       (int)*(undefined8 *)(local_63e8 + 0x6618),
                       (int)((ulonglong)*(undefined8 *)(local_63e8 + 0x6618) >> 0x20),
                       (int)*(undefined8 *)(local_63e8 + 0x6620));
          puStack_6454 = local_63f0;
          FUN_00404860();
          puStack_6454 = local_642c;
          local_63f4 = FUN_006a74a0(local_63e4);
          if (local_63f4 == 10000) {
            local_8._0_1_ = 4;
            puStack_6454 = (undefined1 *)0x6adfe3;
            FUN_0079dfff();
            local_8 = (uint)local_8._1_3_ << 8;
            puStack_6454 = (undefined1 *)0x6adff2;
            FUN_00447100();
            local_8 = 0xffffffff;
            puStack_6454 = (undefined1 *)0x6ae004;
            FUN_00404540();
          }
          else {
            if (local_63f4 < 10000) {
              *(undefined4 *)(local_63e8 + 0x65a0) = 0;
              *(undefined4 *)(local_63e8 + 0x6598) = 0;
              if (*(int *)(local_63e8 + 0x659c) == 0) {
                *(undefined4 *)(local_63e8 + 0x6498) = 0x2b;
              }
              else {
                *(undefined4 *)(local_63e8 + 0x6498) = 0x29;
              }
              puStack_6454 = (undefined1 *)0x6ae071;
              FUN_006ac610();
            }
            local_8._0_1_ = 4;
            puStack_6454 = (undefined1 *)0x6ae080;
            FUN_0079dfff();
            local_8 = (uint)local_8._1_3_ << 8;
            puStack_6454 = (undefined1 *)0x6ae08f;
            FUN_00447100();
            local_8 = 0xffffffff;
            puStack_6454 = (undefined1 *)0x6ae0a1;
            FUN_00404540();
          }
        }
      }
    }
    else {
      puStack_6454 = (undefined1 *)0x6adb2a;
      (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x90))();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKigouHenkei[49] */
/* 006ae0c0  FUN_006ae0c0  134 bytes, 0 callers */

void FUN_006ae0c0(undefined8 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x64a0) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x64a0) + 0xc4))(param_1);
  }
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x863c)) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_005cc4e0(param_1);
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[50] */
/* 006ae150  FUN_006ae150  66 bytes, 0 callers */

void FUN_006ae150(undefined8 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x64a0) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x64a0) + 200))(param_1);
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[51] */
/* 006ae1a0  FUN_006ae1a0  199 bytes, 0 callers */

void FUN_006ae1a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  int in_ECX;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093761d;
  local_10 = ExceptionList;
  uStack_1c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x64a0) != 0) {
    local_18 = (undefined1 *)&uStack_20;
    local_14 = in_ECX;
    FUN_00403dd0();
    (**(code **)(**(int **)(local_14 + 0x64a0) + 0xcc))(param_1,param_2,param_3,param_4,param_5);
  }
  local_8 = 0xffffffff;
  uStack_20 = 0x6ae256;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKigouHenkei[15] */
/* 006ae3c0  FUN_006ae3c0  83 bytes, 0 callers */

undefined4 FUN_006ae3c0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x6498) == 0x65) || (*(int *)(in_ECX + 0x6498) == 0x66)) {
    uVar1 = 1;
  }
  else if (*(int *)(in_ECX + 0x64a0) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x3c))();
  }
  return uVar1;
}




/* vtable slots: CZukeiKigouHenkei[12] */
/* 006ae420  FUN_006ae420  86 bytes, 0 callers */

undefined4
FUN_006ae420(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x64a0) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x30))
                      (param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiKigouHenkei[9] */
/* 006ae480  FUN_006ae480  3496 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006ae480(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  float10 fVar3;
  undefined1 local_6508 [8];
  double local_6500;
  double local_64f8;
  double local_64f0;
  undefined4 local_64e8;
  undefined4 local_64e4;
  undefined4 local_64e0;
  undefined4 local_64dc;
  undefined4 local_64d8;
  undefined4 local_64d4;
  undefined4 local_64d0;
  undefined4 local_64cc;
  undefined4 local_64c8;
  undefined4 local_64c4;
  undefined4 local_64c0;
  undefined4 local_64bc;
  undefined4 local_64b8;
  undefined4 local_64b4;
  undefined4 local_64b0;
  undefined4 local_64ac;
  undefined4 local_64a8;
  undefined4 local_64a4;
  undefined4 local_64a0;
  undefined4 local_649c;
  undefined4 local_6498;
  int local_6494;
  int local_6490;
  undefined1 local_648c [20];
  int *local_6478;
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
  undefined1 local_84 [16];
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
  puStack_c = &LAB_0093c64b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x1928] == 0) {
    local_6478 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(local_6478[1]);
    local_8._0_1_ = 1;
    local_64e8 = 0;
    FUN_004b6d60(local_6508,param_2,param_3,param_4,param_5);
    if (local_6478[0x1926] == 0x65) {
      local_6490 = FUN_005a1910(param_1,param_2,param_3,param_4,param_5);
      if (local_6490 == 0) {
        local_6498 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else if (local_6490 == -1) {
        local_649c = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6498 = local_649c;
      }
      else {
        local_6478[0x1926] = 0x66;
        FUN_006ac610();
        local_64a0 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6498 = local_64a0;
      }
    }
    else if (local_6478[0x192a] == 20000) {
      (**(code **)(*local_6478 + 0x90))();
      FUN_00404c80();
      FUN_0056d7d0();
      local_64a4 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6498 = local_64a4;
    }
    else if (local_6478[0x1926] == 0x66) {
      local_6494 = FUN_005a1720(param_1,param_2,param_3,param_4,param_5);
      if (local_6494 == 0) {
        local_64a8 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6498 = local_64a8;
      }
      else if (local_6494 == -1) {
        local_6478[0x1926] = 0x65;
        FUN_006ac610();
        local_64ac = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6498 = local_64ac;
      }
      else {
        (**(code **)(*local_6478 + 0x20))();
        local_6478[0x192b] = *(int *)(local_6478[0x1920] + 0xb50);
        local_6478[0x192d] = 0;
        local_6478[0x192c] = 0;
        FUN_006af630();
        local_6478[0x1968] = 0;
        local_6478[0x1966] = 0;
        if (local_6478[0x194c] == 10) {
          local_6478[0x195a] = 0;
          local_6478[0x195b] = 0;
          local_6478[0x1958] = 0;
          local_6478[0x1959] = 0;
          local_6478[0x1956] = 0;
          local_6478[0x1957] = 0;
          local_6478[0x1954] = 0;
          local_6478[0x1955] = 0;
          local_6478[0x1926] = 0x2c;
          FUN_006a55a0();
          FUN_00404c80();
          FUN_0056d7d0();
          local_64b0 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6498 = local_64b0;
        }
        else {
          *(undefined4 *)(local_6478[0x1947] + 4) = *(undefined4 *)local_6478[0x1947];
          if (local_6478[0x1967] == 0) {
            local_6478[0x1926] = 0x2b;
          }
          else {
            local_6478[0x1926] = 0x29;
          }
          FUN_006ac610();
          local_64e0 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6498 = local_64e0;
        }
      }
    }
    else if (local_6478[0x1926] == 0x29) {
      iVar1 = FUN_0044a270(3,local_6478[1],&param_2,local_6478 + 0x1951,0);
      if (iVar1 == 0) {
        local_64dc = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6498 = local_64dc;
      }
      else {
        iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar1 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(local_6478[1] + 0x8f24),
                       *(undefined4 *)(local_6478[1] + 0x8f28),0,0);
          local_64d8 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6498 = local_64d8;
        }
        else {
          FUN_00447b90(local_648c,2,local_6478[1],local_6478[0x1951],2,1);
          FUN_004988c0(local_a4,param_2,param_3,param_4,param_5);
          local_6478[0x1966] = 0;
          if (local_6478[0x1967] != 0) {
            local_6478[0x1966] = 1;
          }
          if (local_6478[0x1969] == 0) {
            local_6478[0x1926] = 0x2b;
          }
          else {
            local_6478[0x1926] = 0x2a;
          }
          if (local_6478[0x1965] == 0) {
            iVar1 = local_6478[0x1951];
            fVar3 = (float10)FUN_0043ad70(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                                          *(undefined4 *)(iVar1 + 0x10),
                                          *(undefined4 *)(iVar1 + 0x14),param_2,param_3,param_4,
                                          param_5);
            local_6500 = (double)fVar3;
            iVar1 = local_6478[0x1951];
            local_64f0 = local_6500;
            fVar3 = (float10)FUN_0043ad70(*(undefined4 *)(iVar1 + 0x18),
                                          *(undefined4 *)(iVar1 + 0x1c),
                                          *(undefined4 *)(iVar1 + 0x20),
                                          *(undefined4 *)(iVar1 + 0x24),param_2,param_3,param_4,
                                          param_5);
            local_64f8 = (double)fVar3;
            if (local_64f8 <= local_6500) {
              iVar1 = local_6478[0x1951];
              FUN_004988c0(local_84,*(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x1c),
                           *(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x24));
            }
            else {
              iVar1 = local_6478[0x1951];
              FUN_004988c0(local_94,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                           *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
            }
            local_6478[0x1926] = 0x2c;
            FUN_006a55a0();
            local_64d4 = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            local_6498 = local_64d4;
          }
          else {
            FUN_006ac610();
            FUN_00404c80();
            FUN_0056d7d0();
            local_64d0 = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            local_6498 = local_64d0;
          }
        }
      }
    }
    else if (local_6478[0x1926] == 0x2a) {
      iVar1 = FUN_0044a270(3,local_6478[1],&param_2,local_6478 + 0x1952,0);
      if (iVar1 == 0) {
        local_64cc = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6498 = local_64cc;
      }
      else {
        iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
        if (iVar1 == 0) {
          FUN_005168b0(0x14de,*(undefined4 *)(local_6478[1] + 0x8f24),
                       *(undefined4 *)(local_6478[1] + 0x8f28),0,0);
          local_64c8 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6498 = local_64c8;
        }
        else {
          FUN_004988c0(local_74,param_2,param_3,param_4,param_5);
          local_6478[0x1968] = 0;
          if (local_6478[0x1969] != 0) {
            local_6478[0x1968] = 1;
          }
          local_6478[0x1926] = 0x2c;
          FUN_006a55a0();
          local_64c4 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_6498 = local_64c4;
        }
      }
    }
    else if ((local_6478[0x1926] == 0x2b) && (*(int *)(local_6478[0x1947] + 4) != 0)) {
      FUN_004988c0(local_64,param_2,param_3,param_4,param_5);
      *(undefined4 *)(local_6478[0x1947] + 4) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      local_64c0 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6498 = local_64c0;
    }
    else if (local_6478[0x1926] == 0x2b) {
      if (local_6478[0x1924] == 0) {
        FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
        local_6478[0x1926] = 0x2c;
        FUN_006a55a0();
        local_64b4 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6498 = local_64b4;
      }
      else {
        puVar2 = (undefined4 *)FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
        FUN_004988c0(local_44,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
        local_6478[0x1926] = 0x1af;
        FUN_00404c80();
        FUN_0056d7d0();
        local_64e4 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6498 = local_64e4;
      }
    }
    else if (local_6478[0x1926] == 0x1af) {
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      local_6478[0x1926] = 0x2c;
      FUN_006a55a0();
      local_6478[0x1924] = 0;
      local_64b8 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6498 = local_64b8;
    }
    else {
      FUN_00404c80();
      FUN_0056d7d0();
      local_64bc = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6498 = local_64bc;
    }
  }
  else {
    local_6498 = (**(code **)(*(int *)in_ECX[0x1928] + 0x24))
                           (param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return local_6498;
}




/* vtable slots: CZukeiKigouHenkei[13] */
/* 006af230  FUN_006af230  86 bytes, 0 callers */

undefined4
FUN_006af230(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x64a0) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x34))
                      (param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiKigouHenkei[11] */
/* 006af290  FUN_006af290  464 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006af290(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  if (*(int *)(in_ECX + 0x64a0) == 0) {
    if ((*(int *)(in_ECX + 0x6498) == 0x65) || (*(int *)(in_ECX + 0x6498) == 0x66)) {
      uVar1 = FUN_006ae480(param_1,param_2,param_3,param_4,param_5);
    }
    else if (*(int *)(in_ECX + 0x64a8) == 20000) {
      FUN_006ac410(param_2,param_3,param_4,param_5);
      uVar1 = 0;
    }
    else {
      FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
      local_8 = 0;
      iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&param_2,1);
      if (iVar2 == 1) {
        uVar1 = FUN_006ae480(param_1,param_2,param_3,param_4,param_5);
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x2c))
                      (param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiKigouHenkei[8] */
/* 006af460  FUN_006af460  454 bytes, 0 callers */

void FUN_006af460(void)

{
  int in_ECX;
  float10 fVar1;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(int *)(in_ECX + 0x64a0) == 0) {
    if (*(int *)(in_ECX + 0x6710) != 0) {
      *(undefined4 *)(in_ECX + 0x64a8) = 0;
      FUN_006a4480();
    }
    *(undefined4 *)(in_ECX + 0x6538) = *(undefined4 *)(*(int *)(in_ECX + 0x6480) + 0xc58);
    *(undefined4 *)(in_ECX + 0x652c) = *(undefined4 *)(*(int *)(in_ECX + 0x6480) + 0xc50);
    *(undefined4 *)(in_ECX + 0x6530) = *(undefined4 *)(*(int *)(in_ECX + 0x6480) + 0xc54);
    *(undefined8 *)(in_ECX + 0x65d8) = 0x3ff0000000000000;
    *(undefined8 *)(in_ECX + 0x65e0) = 0x3ff0000000000000;
    FUN_00404c80();
    FUN_004fca20();
    fVar1 = (float10)FUN_005cc660();
    *(double *)(in_ECX + 0x65d8) = (double)fVar1;
    FUN_00404c80();
    FUN_004fca20();
    fVar1 = (float10)FUN_005cc6f0();
    *(double *)(in_ECX + 0x65e0) = (double)fVar1;
    if (*(double *)(in_ECX + 0x65d8) <= 0.0) {
      local_10 = -*(double *)(in_ECX + 0x65d8);
    }
    else {
      local_10 = *(double *)(in_ECX + 0x65d8);
    }
    if (local_10 < 0.001) {
      *(undefined8 *)(in_ECX + 0x65d8) = 0x3ff0000000000000;
    }
    if (*(double *)(in_ECX + 0x65e0) <= 0.0) {
      local_18 = -*(double *)(in_ECX + 0x65e0);
    }
    else {
      local_18 = *(double *)(in_ECX + 0x65e0);
    }
    if (local_18 < 0.001) {
      *(undefined8 *)(in_ECX + 0x65e0) = 0x3ff0000000000000;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x64a0) + 0x20))();
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[4] */
/* 006afc10  FUN_006afc10  142 bytes, 0 callers */

void FUN_006afc10(void)

{
  int in_ECX;
  
  FUN_00404860(in_ECX + 0x6524);
  DAT_00a0bc28 = *(undefined4 *)(in_ECX + 0x6528);
  if (*(int *)(in_ECX + 0xa8) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xa8) + 0x60))();
    if (*(int **)(in_ECX + 0xa8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0xa8) + 4))(1);
    }
    *(undefined4 *)(in_ECX + 0xa8) = 0;
  }
  return;
}




/* vtable slots: CZukeiKigouHenkei[3] */
/* 006afca0  FUN_006afca0  598 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006afca0(void)

{
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  int local_63f0;
  int *local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c69b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_006a5b30();
  if (*(int *)(local_63e8 + 0x64a0) != 0) {
    (**(code **)(**(int **)(local_63e8 + 0x64a0) + 0xc))();
    local_63ec = *(int **)(local_63e8 + 0x64a0);
    if (local_63ec == (int *)0x0) {
      local_63f4 = 0;
    }
    else {
      local_63f4 = (**(code **)(*local_63ec + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0x64a0) = 0;
  }
  FUN_006a5b30();
  *(undefined4 *)(local_63e8 + 0x64a8) = 0;
  FUN_006a4480();
  local_63f0 = FUN_006a74a0(local_63e4,local_6408);
  if (local_63f0 == 10000) {
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (local_63f0 < 10000) {
      *(undefined4 *)(local_63e8 + 0x65a0) = 0;
      *(undefined4 *)(local_63e8 + 0x6598) = 0;
      if (*(int *)(local_63e8 + 0x659c) == 0) {
        *(undefined4 *)(local_63e8 + 0x6498) = 0x2b;
      }
      else {
        *(undefined4 *)(local_63e8 + 0x6498) = 0x29;
      }
      FUN_006ac610();
      if (*(int *)(local_63e8 + 0x648c) != 0) {
        *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8578) = 1;
      }
    }
    *(undefined4 *)(*(int *)(local_63e8 + 0x651c) + 4) = **(undefined4 **)(local_63e8 + 0x651c);
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}



