/* CDataList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataList[1] */
/* 00499e80  FUN_00499e80  68 bytes, 0 callers */

undefined4 FUN_00499e80(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00499820();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa0);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataList[18] */
/* 00499f60  FUN_00499f60  376 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00499f60(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_63f8;
  undefined4 local_63f4;
  int local_63f0;
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009249d0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63f4 = 0;
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_63f8 = FUN_0049ac10();
  while (local_63e8 = (int *)FUN_0049ac30(&local_63f8,0), uVar1 = local_63f4,
        local_63e8 != (int *)0x0) {
    local_63f4 = 1;
    iVar2 = FUN_0079d98a(&PTR_s_CDataBlock_009fe144);
    if (iVar2 == 0) {
      FUN_0042b460(param_1);
      local_63f0 = FUN_00450aa0(param_1,local_63e8,1);
      FUN_0042e540();
      if (-1 < *(int *)(param_1 + 0x16d0)) {
        *(undefined1 *)(local_63f0 + 0x2e) = *(undefined1 *)(param_1 + 0x16d0);
      }
      if (-1 < *(int *)(param_1 + 0x16d4)) {
        *(undefined1 *)(local_63f0 + 0x2f) = *(undefined1 *)(param_1 + 0x16d4);
      }
    }
    else {
      (**(code **)(*local_63e8 + 0x48))(param_1);
    }
  }
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CDataList[15] */
/* 0049a480  FUN_0049a480  446 bytes, 0 callers */

undefined4 FUN_0049a480(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  int *local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924a0d;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *(undefined4 *)(param_2 + 0x822c);
  *(undefined4 *)(param_2 + 0x822c) = 0;
  local_24 = 1;
  if (*(int *)(param_2 + 0x8220) != 0) {
    local_24 = 3;
  }
  local_18 = 1;
  local_20 = in_ECX;
LAB_0049a4ed:
  if (local_24 < local_18) {
    *(undefined4 *)(param_2 + 0x822c) = uVar1;
    ExceptionList = local_10;
    return 1;
  }
  local_28 = FUN_0049ac10(uVar2);
LAB_0049a504:
  local_1c = (int *)FUN_0049ac30(&local_28,0);
  if (local_1c == (int *)0x0) goto LAB_0049a4e4;
  if (*(int *)(param_2 + 0x8220) == 0) goto LAB_0049a5ed;
  iVar3 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
  if (iVar3 == 0) {
    iVar3 = FUN_0079d98a(&PTR_s_CDataSolid_009fe094);
    if (iVar3 != 0) {
      if (local_18 == 3 - *(int *)(param_2 + 0x8220)) goto LAB_0049a5ed;
      goto LAB_0049a504;
    }
joined_r0x0049a5ae:
    if (local_18 != 3) goto LAB_0049a504;
  }
  else {
    local_2c = local_1c;
    local_34 = Left(local_38,4);
    local_8 = 0;
    local_30 = local_34;
    local_11 = FUN_00414040(&DAT_0095b464,local_34);
    local_8 = 0xffffffff;
    FUN_00404540();
    if (local_11 == '\0') goto joined_r0x0049a5ae;
    if (local_18 != *(int *)(param_2 + 0x8220)) goto LAB_0049a504;
  }
LAB_0049a5ed:
  *(undefined1 *)((int)local_1c + 0x61) = *(undefined1 *)(local_20 + 0x61);
  (**(code **)(*local_1c + 0x3c))(param_1,param_2,param_3);
  goto LAB_0049a504;
LAB_0049a4e4:
  local_18 = local_18 + 1;
  goto LAB_0049a4ed;
}




/* vtable slots: CDataList[3] */
/* 0049a810  FUN_0049a810  376 bytes, 0 callers */

void FUN_0049a810(undefined4 param_1)

{
  uint extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_ECX_01;
  undefined8 local_48;
  uint uStack_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  undefined1 *local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined4 *local_24;
  undefined4 *local_20;
  undefined1 local_1c [4];
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924a85;
  local_10 = ExceptionList;
  uStack_40 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = (undefined1 *)((int)&local_48 + 4);
  local_48._0_4_ = L"BLOCK";
  CStringT<>();
  local_48 = (ulonglong)local_48._4_4_ << 0x20;
  FUN_004a7e90();
  local_48 = CONCAT44(0x49a85a,(wchar_t *)local_48);
  CStringT<>();
  local_8 = 0;
  local_34 = (undefined1 *)&local_48;
  local_48 = (ulonglong)extraout_ECX;
  FUN_00414640(&local_48);
  local_24 = (undefined4 *)FUN_0049d480(local_28);
  local_8._0_1_ = 1;
  local_48 = CONCAT44(*local_24,*(undefined4 *)(local_14 + 0x68));
  local_20 = local_24;
  FUN_004059f0(local_1c,L"-%03d-%s");
  local_8 = (uint)local_8._1_3_ << 8;
  local_48 = CONCAT44(0x49a8b5,(wchar_t *)local_48);
  FUN_00404540();
  local_38 = (undefined1 *)((int)&local_48 + 4);
  local_48._0_4_ = (wchar_t *)local_1c;
  local_48._4_4_ = extraout_ECX_00;
  FUN_00403dd0();
  local_48 = CONCAT44(local_48._4_4_,2);
  FUN_004a7e90();
  local_48 = 0x4000000046;
  FUN_004a7e10();
  local_48 = 0;
  FUN_004a77a0(10);
  local_48 = 0;
  FUN_004a77a0(0x14);
  local_48 = 0;
  FUN_004a77a0(0x1e);
  local_48 = CONCAT44(0x49a921,(wchar_t *)local_48);
  local_2c = FUN_0049ac10();
  while( true ) {
    local_48 = ZEXT48(&local_2c);
    local_18 = (int *)FUN_0049ac30();
    if (local_18 == (int *)0x0) break;
    local_48 = CONCAT44(param_1,0x49a94c);
    (**(code **)(*local_18 + 0xc))();
  }
  local_3c = (undefined1 *)((int)&local_48 + 4);
  local_48._0_4_ = L"ENDBLK";
  local_48._4_4_ = extraout_ECX_01;
  CStringT<>();
  local_48 = (ulonglong)local_48._4_4_ << 0x20;
  FUN_004a7e90();
  local_8 = 0xffffffff;
  local_48 = CONCAT44(0x49a977,(wchar_t *)local_48);
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataList[0] */
/* 0049ad60  FUN_0049ad60  16 bytes, 0 callers */

undefined ** FUN_0049ad60(void)

{
  return &PTR_s_CDataList_009fe128;
}




/* vtable slots: CDataList[16] */
/* 0049af70  FUN_0049af70  273 bytes, 0 callers */

undefined4
FUN_0049af70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  double local_28;
  double local_20;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_14 = 0;
  local_28 = 1e+99;
  local_18 = FUN_0049ac10();
LAB_0049af98:
  local_8 = (int *)FUN_0049ac30(&local_18,0);
  if (local_8 == (int *)0x0) {
    *(double *)(param_1 + 0x8ee0) = local_28;
    return local_14;
  }
  if ((*(byte *)(local_c + 0x28) & 0x40) != 0) goto code_r0x0049afbf;
  goto LAB_0049afec;
code_r0x0049afbf:
  if (param_1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = param_1 + 0x88;
  }
  iVar1 = FUN_0043b460(local_10);
  if (iVar1 != 1) {
LAB_0049afec:
    iVar1 = (**(code **)(*local_8 + 0x40))(param_1,param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      local_14 = 1;
      local_20 = *(double *)(param_1 + 0x8ee0);
      iVar1 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108);
      if (iVar1 != 0) {
        local_20 = 0.0;
      }
      if (local_20 < local_28) {
        local_28 = local_20;
      }
    }
  }
  goto LAB_0049af98;
}




/* vtable slots: CDataList[5] */
/* 0049b1f0  FUN_0049b1f0  199 bytes, 0 callers */

undefined4 FUN_0049b1f0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924abf;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = FUN_004121b0(0xa0);
  local_8 = 0;
  if (local_20 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_004996f0(uVar1);
  }
  local_28 = local_24;
  local_8 = 0xffffffff;
  local_1c = local_24;
  FUN_0049b750(local_24);
  local_2c = FUN_0049ac10();
  while( true ) {
    local_18 = (int *)FUN_0049ac30(&local_2c,0);
    if (local_18 == (int *)0x0) break;
    uVar2 = (**(code **)(*local_18 + 0x14))();
    FUN_00499ed0(uVar2);
  }
  ExceptionList = local_10;
  return local_1c;
}




/* vtable slots: CDataList[2] */
/* 0049b410  FUN_0049b410  623 bytes, 0 callers */

void FUN_0049b410(CArchive *param_1)

{
  uint uVar1;
  int iVar2;
  CArchive *pCVar3;
  undefined4 uVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  undefined4 uVar8;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> local_20 [4];
  undefined1 local_1c [4];
  int local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924b0d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0042e690(param_1);
  iVar2 = FUN_0042ddc0(uVar1);
  if (iVar2 == 0) {
    iVar2 = local_18 + 0x70;
    plVar5 = (long *)(local_18 + 0x6c);
    pCVar3 = CArchive::operator>>(param_1,(long *)(local_18 + 0x68));
    pCVar3 = CArchive::operator>>(pCVar3,plVar5);
    FUN_007ab76a(pCVar3,iVar2);
    if (0x3c < DAT_00a0b414) {
      CStringT<>();
      local_8 = 2;
      *(undefined4 *)(local_18 + 0x78) = 4;
      FUN_0047fc90(local_1c);
      local_24 = FUN_00429b90(L"@@SfigorgFlag@@",0);
      if (local_24 < 0) {
        FUN_00404860(local_1c);
      }
      else {
        local_38 = Left(local_3c,local_24);
        local_8._0_1_ = 3;
        local_34 = local_38;
        FUN_00404860(local_38);
        local_8._0_1_ = 2;
        FUN_00404540();
        local_44 = Mid(local_48,local_24 + 0xf);
        local_8._0_1_ = 4;
        local_40 = local_44;
        FUN_00404860(local_44);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_00404540();
        uVar4 = FUN_00404920(&DAT_0095b714,local_18 + 0x78);
        FUN_00417110(uVar4);
      }
      local_8 = 0xffffffff;
      FUN_00404540();
    }
  }
  else {
    local_2c = Left(local_30,7);
    local_8 = 0;
    local_28 = local_2c;
    local_11 = FUN_00408cb0("$EDTBLK",local_2c);
    local_8 = 0xffffffff;
    FUN_00404540();
    uVar6 = FUN_0049ad90();
    uVar4 = (undefined4)uVar6;
    lVar7 = *(long *)(local_18 + 0x6c);
    pCVar3 = CArchive::operator<<(param_1,*(long *)(local_18 + 0x68));
    pCVar3 = CArchive::operator<<(pCVar3,lVar7);
    uVar8 = (undefined4)((ulonglong)uVar6 >> 0x20);
    CArchive::operator<<(pCVar3,(long)uVar6);
    FUN_00403dd0(local_18 + 0x7c);
    local_8 = 1;
    if (*(int *)(local_18 + 0x78) != 0) {
      FUN_004059f0(local_20,L"%s@@SfigorgFlag@@%d",*(undefined4 *)(local_18 + 0x7c),
                   *(undefined4 *)(local_18 + 0x78),uVar1,uVar4,uVar8);
    }
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>(param_1,local_20)
    ;
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  (**(code **)(*(int *)(local_18 + 0x80) + 8))(param_1);
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataList[6] */
/* 0049b750  FUN_0049b750  105 bytes, 1 callers */

void FUN_0049b750(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_0042f720(param_1);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(in_ECX + 0x68);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(in_ECX + 0x6c);
  uVar1 = *(undefined4 *)(in_ECX + 0x74);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(in_ECX + 0x70);
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  FUN_00404860(in_ECX + 0x7c);
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(in_ECX + 0x78);
  return;
}




/* vtable slots: CDataList[7] */
/* 0049bdb0  FUN_0049bdb0  270 bytes, 0 callers */

undefined4 FUN_0049bdb0(int param_1)

{
  char cVar1;
  int iVar2;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  iVar2 = FUN_0079d98a(&PTR_s_CDataList_009fe128);
  if (iVar2 != 0) {
    local_c = param_1;
    cVar1 = FUN_00414010(local_8 + 0x7c,param_1 + 0x7c);
    if (((cVar1 != '\0') && (*(int *)(local_8 + 0x78) == *(int *)(local_c + 0x78))) &&
       (local_14 = FUN_0049ac10(), local_14 != 0)) {
      local_18 = FUN_0049ac10();
      for (iVar2 = local_18; iVar2 != 0; iVar2 = (**(code **)(*local_10 + 0x1c))(iVar2)) {
        if ((local_14 == 0) && (local_18 == 0)) {
          return 1;
        }
        local_10 = (int *)FUN_0049ac30(&local_14,0);
        iVar2 = FUN_0049ac30(&local_18,0);
        if ((local_10 == (int *)0x0) && (iVar2 == 0)) {
          return 1;
        }
        if (local_10 == (int *)0x0) {
          return 0;
        }
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
  }
  return 0;
}




/* vtable slots: CDataList[10] */
/* 0049bec0  FUN_0049bec0  74 bytes, 0 callers */

undefined4 FUN_0049bec0(void)

{
  undefined4 uVar1;
  int local_c;
  int *local_8;
  
  local_c = FUN_0049ac10();
  if (local_c == 0) {
    uVar1 = 0;
  }
  else {
    local_8 = (int *)FUN_0049ac30(&local_c,0);
    if (local_8 == (int *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)(*local_8 + 0x28))();
    }
  }
  return uVar1;
}



