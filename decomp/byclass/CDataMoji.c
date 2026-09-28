/* CDataMoji -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataMoji[23], CDataSen[23], CDataSolid[23], CDataSunpou[23] */
/* 00429d20  FUN_00429d20  28 bytes, 0 callers */

undefined4 FUN_00429d20(undefined4 param_1)

{
  FUN_00429c10(param_1);
  return param_1;
}




/* vtable slots: CDataMoji[1] */
/* 00481310  FUN_00481310  68 bytes, 0 callers */

undefined4 FUN_00481310(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00480ef0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xf0);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataMoji[14] */
/* 004816b0  FUN_004816b0  199 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004816b0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_198 [400];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar1 = FUN_00404920();
  FUN_00480580(local_198,L"String  %d (%g,%g)-(%g,%g)  [%s]                           ",param_3,
               *(undefined8 *)(in_ECX + 8),*(undefined8 *)(in_ECX + 0x10),
               *(undefined8 *)(in_ECX + 0x18),*(undefined8 *)(in_ECX + 0x20),uVar1);
  FUN_008f899d(local_198);
  (**(code **)(*param_1 + 0x5c))();
  return;
}




/* vtable slots: CDataMoji[15] */
/* 00486f60  FUN_00486f60  811 bytes, 1 callers */

undefined4 FUN_00486f60(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_2c [4];
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  uint local_10;
  int local_c;
  char local_5;
  
  local_10 = 0;
  local_14 = 0;
  local_c = in_ECX;
  if ((*(int *)(in_ECX + 0xb4) == 0) &&
     ((((cVar1 = FUN_00480510(*(undefined8 *)(in_ECX + 0xb8)), cVar1 == '\0' ||
        (cVar1 = FUN_00480510(*(undefined8 *)(local_c + 0xc0)), cVar1 == '\0')) ||
       (cVar1 = FUN_00480510(*(undefined8 *)(local_c + 200)), cVar1 == '\0')) ||
      (cVar1 = FUN_00480510(*(undefined8 *)(local_c + 0xd0)), cVar1 == '\0')))) {
    return 0;
  }
  iVar2 = FUN_00424ed0(param_1,param_2,param_3);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_0042b460();
  if (iVar2 != 0) {
    FUN_0042e540();
    local_14 = 0;
    goto LAB_00487275;
  }
  *(undefined4 *)(local_c + 0xa4) = 0;
  if (*(int *)(param_2 + 0x8240) != 0) {
    if ((((*(ushort *)(local_c + 0x44) & 0x40) == 0) && ((*(ushort *)(local_c + 0x44) & 0x80) == 0))
       && ((*(ushort *)(local_c + 0x44) & 0x8000) == 0)) {
      local_28 = Left(local_2c,4);
      local_10 = local_10 | 1;
      cVar1 = FUN_00447350(L"^@BM",local_28);
      if (cVar1 != '\0') goto LAB_004870e0;
      local_20 = 0;
    }
    else {
LAB_004870e0:
      local_20 = 1;
    }
    local_5 = (char)local_20;
    if ((local_10 & 1) != 0) {
      local_10 = local_10 & 0xfffffffe;
      FUN_00404540();
    }
    if (local_5 != '\0') {
      *(undefined4 *)(local_c + 0xa4) = 1;
    }
  }
  if (*(int *)(param_2 + 0x8240) == 1) {
    local_1c = 6;
    if (*(int *)(local_c + 0xa4) == 1) {
      local_1c = 0;
    }
    local_24 = FUN_004b8250(*(double *)(local_c + 0xc0) * DAT_00a0c7a8);
    local_18 = -local_24;
    if (0 < local_18) {
      local_24 = local_18;
    }
    if ((double)local_24 < (double)DAT_00a0b454 * 1.5) {
      local_1c = 0;
    }
    *(undefined4 *)(local_c + 0xa0) = local_1c;
    while (-1 < *(int *)(local_c + 0xa0)) {
      if (param_3 != 0) {
        if (*(int *)(local_c + 0xa0) == 6) {
          iVar2 = param_2;
          iVar3 = FUN_0042b020();
          FUN_00456e10(param_1,-iVar3,iVar2);
        }
        if (*(int *)(local_c + 0xa0) == 0) {
          iVar2 = param_2;
          uVar4 = FUN_0042b020();
          FUN_00456e10(param_1,uVar4,iVar2);
        }
      }
      local_14 = FUN_00481d50(param_1,param_2);
      *(int *)(local_c + 0xa0) = *(int *)(local_c + 0xa0) + -1;
    }
  }
  else {
    *(undefined4 *)(local_c + 0xa0) = 0;
    local_14 = FUN_00481d50(param_1,param_2,param_3);
  }
  FUN_0042e540();
LAB_00487275:
  *(undefined4 *)(local_c + 0xa0) = 0;
  return local_14;
}




/* vtable slots: CDataMoji[3] */
/* 00489960  FUN_00489960  940 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00489960(void)

{
  undefined8 uVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  double local_10;
  
  FUN_0040c0e0();
  iVar2 = FUN_00572700(in_ECX,L"Printer",L"Orientation");
  if ((((iVar2 == 0) && (iVar2 = FUN_00572700(in_ECX,L"Printer",L"PaperSize"), iVar2 == 0)) &&
      (iVar2 = FUN_00572700(in_ECX,L"Printer",L"D2dBMP"), iVar2 == 0)) &&
     (((iVar2 = FUN_00572700(in_ECX,L"Printer",L"BmpZENTAI"), iVar2 == 0 &&
       (iVar2 = FUN_00572700(in_ECX,L"View",L"Direct2d"), iVar2 == 0)) &&
      ((iVar2 = FUN_00572700(in_ECX,L"Draw",L"BMPTOUKA"), iVar2 == 0 &&
       (iVar2 = FUN_00572700(in_ECX,L"Draw",L"BmpTOUKA"), iVar2 == 0)))))) {
    bVar3 = (*(ushort *)(in_ECX + 0x44) & 0x20) != 0;
    FUN_008f8d00(*(double *)(in_ECX + 0x20) - *(double *)(in_ECX + 0x10),
                 *(double *)(in_ECX + 0x18) - *(double *)(in_ECX + 8));
    uVar1 = *(undefined8 *)(in_ECX + 8);
    local_10 = *(double *)(in_ECX + 0x10);
    if (bVar3) {
      FUN_005f8840(in_ECX);
      FUN_005f92e0();
      local_10 = *(double *)(in_ECX + 0xb8) / 2.0 + local_10;
      FUN_005f8ce0();
    }
    CStringT<>(L"TEXT");
    FUN_004a7e90(0);
    FUN_0049dea0(&stack0xffffff7c,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),1);
    FUN_004a7e90(8);
    FUN_0049dcf0();
    FUN_004a7e10(0x3e);
    FUN_004a93e0(uVar1);
    FUN_004a77a0();
    FUN_004a9450(local_10);
    FUN_004a77a0();
    FUN_004a93a0(*(undefined8 *)(in_ECX + 0xc0));
    FUN_004a77a0();
    FUN_004a77a0();
    FUN_004a77a0();
    FUN_0048ea70();
    FUN_00403dd0(in_ECX + 0xb0);
    FUN_004a7e90(1);
    if (bVar3) {
      CStringT<>("TATEGAKI");
      FUN_004a7e90(7);
    }
  }
  return;
}




/* vtable slots: CDataMoji[0] */
/* 0048a090  FUN_0048a090  16 bytes, 0 callers */

undefined ** FUN_0048a090(void)

{
  return &PTR_s_CDataMoji_009fe108;
}




/* vtable slots: CDataMoji[17] */
/* 0048a1e0  FUN_0048a1e0  2882 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0048a1e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  double dVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;
  double local_6738;
  int local_6730;
  undefined8 local_66e8;
  undefined8 local_66e0;
  undefined8 local_66d8;
  double local_66d0;
  double local_66c8;
  undefined8 local_66c0;
  undefined4 local_66b8;
  undefined4 local_66b4;
  undefined4 local_66b0;
  undefined4 local_66ac;
  undefined4 local_66a8;
  undefined4 local_66a4;
  undefined4 local_66a0;
  undefined4 local_669c;
  undefined4 local_6698;
  undefined4 local_6694;
  undefined4 local_6690;
  double local_668c;
  double local_6684;
  double local_667c;
  undefined4 local_6674;
  undefined4 local_6670;
  undefined4 local_666c;
  undefined4 local_6668;
  undefined4 local_6664;
  undefined4 local_6660;
  undefined4 local_665c;
  undefined4 local_6658;
  undefined4 local_6654;
  double local_6650;
  double local_6648;
  double local_6640;
  double local_6638;
  double local_6630;
  int local_6628;
  double local_6624;
  int local_661c;
  undefined1 local_6618 [25556];
  undefined1 local_244 [8];
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined1 local_154 [16];
  undefined1 local_144 [16];
  undefined1 local_134 [16];
  undefined1 local_124 [32];
  undefined1 local_104 [16];
  undefined1 local_f4 [104];
  undefined1 local_8c [24];
  undefined8 local_74;
  undefined8 local_6c;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923ffc;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_667c = 100.0;
  local_6684 = 100.0;
  local_14 = uVar2;
  CStringT<>(&DAT_00956338);
  local_8 = 0;
  local_66e8 = 0;
  local_66e0 = 0;
  local_66d8 = 0x3ff0000000000000;
  local_66c0 = 0;
  local_6690 = 0xff;
  local_6674 = 0xff;
  local_6670 = 0xff;
  iVar3 = FUN_0048efe0(local_6618,&local_667c,&local_6684,&local_66e8,&local_66e0,&local_66d8,
                       &local_66c0,&local_6690,&local_6674,&local_6670);
  if (iVar3 == 1) {
    FUN_005f89c0(*(undefined4 *)(local_661c + 8),*(undefined4 *)(local_661c + 0xc),
                 *(undefined4 *)(local_661c + 0x10),*(undefined4 *)(local_661c + 0x14),
                 (int)local_66c0,(int)((ulonglong)local_66c0 >> 0x20),0);
    FUN_0041f760(uVar2);
    local_8._0_1_ = 1;
    FUN_0041f760();
    local_8._0_1_ = 2;
    puVar4 = (undefined4 *)FUN_00408a30(0,0,0,0);
    FUN_004988c0(local_124,*puVar4,puVar4[1],puVar4[2],puVar4[3]);
    FUN_004988c0(local_134,(undefined4)local_74,local_74._4_4_,(undefined4)local_6c,local_6c._4_4_);
    local_74 = local_74 + local_667c;
    FUN_00420110(local_8c);
    FUN_005f8d70(local_f4);
    iVar3 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
    if (iVar3 != 0) {
      local_666c = 1;
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0041fd70();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return local_666c;
    }
    FUN_004988c0(local_144,(undefined4)local_74,local_74._4_4_,(undefined4)local_6c,local_6c._4_4_);
    local_6c = local_6c + local_6684;
    FUN_00420110(local_8c);
    FUN_005f8d70(local_f4);
    iVar3 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
    if (iVar3 != 0) {
      local_6694 = 1;
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0041fd70();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return local_6694;
    }
    FUN_004988c0(local_154,(undefined4)local_74,local_74._4_4_,(undefined4)local_6c,local_6c._4_4_);
    local_74 = local_74 - local_667c;
    FUN_00420110(local_8c);
    FUN_005f8d70(local_f4);
    iVar3 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
    if (iVar3 != 0) {
      local_6698 = 1;
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0041fd70();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return local_6698;
    }
    FUN_004988c0(local_104,(undefined4)local_74,local_74._4_4_,(undefined4)local_6c,local_6c._4_4_);
    local_6c = local_6c - local_6684;
    FUN_00420110(local_8c);
    FUN_005f8d70(local_f4);
    iVar3 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
    if (iVar3 != 0) {
      local_669c = 1;
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0041fd70();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return local_669c;
    }
    if (DAT_00a0c790 == 0) {
      local_66a0 = 0;
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0041fd70();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return local_66a0;
    }
    local_8._0_1_ = 1;
    FUN_0041fd70();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0041fd70();
  }
  local_6630 = 4.0 / *(double *)(param_1 + 0x17b0);
  if (*(double *)(local_661c + 0xc0) <= 0.0) {
    local_66c8 = -*(double *)(local_661c + 0xc0);
  }
  else {
    local_66c8 = *(double *)(local_661c + 0xc0);
  }
  local_6624 = local_66c8 + local_6630;
  dVar1 = *(double *)(local_661c + 0x10);
  local_6638 = *(double *)(local_661c + 0x20);
  local_6640 = dVar1;
  if (dVar1 < local_6638) {
    local_6640 = local_6638;
    local_6638 = dVar1;
  }
  if ((double)CONCAT44(param_5,param_4) <= local_6640 + local_6624) {
    if (local_6638 - local_6624 < (double)CONCAT44(param_5,param_4) ||
        local_6638 - local_6624 == (double)CONCAT44(param_5,param_4)) {
      local_6648 = *(double *)(local_661c + 8);
      dVar1 = *(double *)(local_661c + 0x18);
      local_6650 = dVar1;
      if (local_6648 < dVar1) {
        local_6650 = local_6648;
        local_6648 = dVar1;
      }
      if ((double)CONCAT44(param_3,param_2) <= local_6648 + local_6624) {
        if (local_6650 - local_6624 < (double)CONCAT44(param_3,param_2) ||
            local_6650 - local_6624 == (double)CONCAT44(param_3,param_2)) {
          FUN_005f8840(local_661c,param_1);
          if (local_6730 == 0) {
            local_66b8 = 0;
            local_8 = 0xffffffff;
            FUN_00404540();
            local_66a4 = local_66b8;
          }
          else {
            local_24 = param_2;
            uStack_20 = param_3;
            local_1c = param_4;
            uStack_18 = param_5;
            FUN_005f92e0(&local_24);
            if (-local_6630 < (double)CONCAT44(uStack_20,local_24) ||
                -local_6630 == (double)CONCAT44(uStack_20,local_24)) {
              if ((double)CONCAT44(uStack_20,local_24) <= local_6738 + local_6630) {
                local_6628 = FUN_004939e0();
                if ((local_6628 == 1) || (local_6628 == 3)) {
                  if (local_6624 < (double)CONCAT44(uStack_18,local_1c)) {
                    local_665c = 0;
                    local_8 = 0xffffffff;
                    FUN_00404540();
                    ExceptionList = local_10;
                    return local_665c;
                  }
                  if ((double)CONCAT44(uStack_18,local_1c) <= -local_6630 &&
                      -local_6630 != (double)CONCAT44(uStack_18,local_1c)) {
                    local_6660 = 0;
                    local_8 = 0xffffffff;
                    FUN_00404540();
                    ExceptionList = local_10;
                    return local_6660;
                  }
                }
                else {
                  if (local_6630 < (double)CONCAT44(uStack_18,local_1c)) {
                    local_66a8 = 0;
                    local_8 = 0xffffffff;
                    FUN_00404540();
                    ExceptionList = local_10;
                    return local_66a8;
                  }
                  if ((double)CONCAT44(uStack_18,local_1c) <= -local_6624 &&
                      -local_6624 != (double)CONCAT44(uStack_18,local_1c)) {
                    local_6664 = 0;
                    local_8 = 0xffffffff;
                    FUN_00404540();
                    ExceptionList = local_10;
                    return local_6664;
                  }
                }
                FUN_00480a30();
                local_8._0_1_ = 3;
                FUN_00481070(local_661c);
                FUN_005f9380(local_244);
                FUN_00446aa0();
                local_8._0_1_ = 4;
                fVar5 = (float10)FUN_0043acd0(local_24,uStack_20,local_1c,uStack_18,local_23c,
                                              local_238,local_234,local_230);
                local_668c = (double)fVar5;
                fVar5 = (float10)FUN_0043acd0(local_24,uStack_20,local_1c,uStack_18,local_22c,
                                              local_228,local_224,local_220);
                local_66d0 = (double)fVar5;
                if (local_66d0 < local_668c) {
                  local_668c = local_66d0;
                }
                *(double *)(param_1 + 0x8ee0) = local_668c;
                local_6668 = 1;
                local_8._0_1_ = 3;
                FUN_00447100();
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_00480ef0();
                local_8 = 0xffffffff;
                FUN_00404540();
                local_66a4 = local_6668;
              }
              else {
                local_6658 = 0;
                local_8 = 0xffffffff;
                FUN_00404540();
                local_66a4 = local_6658;
              }
            }
            else {
              local_6654 = 0;
              local_8 = 0xffffffff;
              FUN_00404540();
              local_66a4 = local_6654;
            }
          }
        }
        else {
          local_66b4 = 0;
          local_8 = 0xffffffff;
          FUN_00404540();
          local_66a4 = local_66b4;
        }
      }
      else {
        local_66b0 = 0;
        local_8 = 0xffffffff;
        FUN_00404540();
        local_66a4 = local_66b0;
      }
    }
    else {
      local_66ac = 0;
      local_8 = 0xffffffff;
      FUN_00404540();
      local_66a4 = local_66ac;
    }
  }
  else {
    local_66a4 = 0;
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return local_66a4;
}




/* vtable slots: CDataMoji[5] */
/* 0048c5f0  FUN_0048c5f0  135 bytes, 11 callers */

undefined4 FUN_0048c5f0(void)

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
  iVar2 = FUN_004121b0(0xf0);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_00480a30(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_0048d4b0(local_18);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CDataMoji[2] */
/* 0048cff0  FUN_0048cff0  1115 bytes, 0 callers */

void FUN_0048cff0(CArchive *param_1)

{
  int iVar1;
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *pCVar2;
  CArchive *pCVar3;
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *pCVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined1 local_24 [4];
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *local_20;
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092411d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_0042ddc0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  if (iVar1 == 0) {
    FUN_0042e690(param_1);
    *(undefined2 *)(local_14 + 0xde) = *(undefined2 *)(local_14 + 0x2c);
    *(undefined2 *)(local_14 + 0x2c) = 1;
    *(byte *)(local_14 + 0x28) = *(byte *)(local_14 + 0x28) % 100;
    local_18 = DAT_00a0b414;
    iVar5 = local_14 + 0x20;
    iVar1 = local_14 + 0x18;
    FUN_00420650(local_14 + 8);
    FUN_00420650();
    FUN_00420650(iVar1);
    FUN_00420650(iVar5);
    if (0x13 < local_18) {
      CArchive::operator>>(param_1,(long *)(local_14 + 0xb4));
    }
    iVar1 = local_14 + 0xc0;
    FUN_00420650(local_14 + 0xb8);
    FUN_00420650(iVar1);
    if (0x13 < local_18) {
      FUN_00420650(local_14 + 200);
    }
    FUN_00420650(local_14 + 0xd0);
    if (0x27 < local_18) {
      FUN_0047fc90(local_14 + 0xd8);
    }
    FUN_0047fc90(local_14 + 0xb0);
    if (local_18 < 0x14) {
      FUN_005f8940();
      FUN_005f92e0(local_14 + 8);
      FUN_005f92e0(local_14 + 0x18);
      *(double *)(local_14 + 0x10) = *(double *)(local_14 + 0x10) - *(double *)(local_14 + 0xc0);
      *(double *)(local_14 + 0x20) = *(double *)(local_14 + 0x20) - *(double *)(local_14 + 0xc0);
      FUN_005f8ce0(local_14 + 8);
      FUN_005f8ce0(local_14 + 0x18);
    }
    *(undefined2 *)(local_14 + 0xdc) = 0;
    if (19999 < *(int *)(local_14 + 0xb4)) {
      *(ushort *)(local_14 + 0xdc) = *(ushort *)(local_14 + 0xdc) | 0x10;
    }
    *(int *)(local_14 + 0xb4) = *(int *)(local_14 + 0xb4) % 20000;
    if (9999 < *(int *)(local_14 + 0xb4)) {
      *(ushort *)(local_14 + 0xdc) = *(ushort *)(local_14 + 0xdc) | 1;
    }
    *(int *)(local_14 + 0xb4) = *(int *)(local_14 + 0xb4) % 10000;
  }
  else {
    *(undefined2 *)(local_14 + 0x2c) = *(undefined2 *)(local_14 + 0xde);
    FUN_0042e690(param_1);
    *(undefined2 *)(local_14 + 0x2c) = 1;
    if ((*(ushort *)(local_14 + 0xdc) & 1) != 0) {
      *(int *)(local_14 + 0xb4) = *(int *)(local_14 + 0xb4) + 10000;
    }
    if ((*(ushort *)(local_14 + 0xdc) & 0x10) != 0) {
      *(int *)(local_14 + 0xb4) = *(int *)(local_14 + 0xb4) + 20000;
    }
    pCVar4 = (CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)(local_14 + 0xb0)
    ;
    pCVar2 = (CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
             FUN_0046b960(local_24);
    local_8 = 0;
    uVar13 = *(undefined8 *)(local_14 + 0xd0);
    uVar12 = *(undefined8 *)(local_14 + 200);
    uVar11 = *(undefined8 *)(local_14 + 0xc0);
    uVar10 = *(undefined8 *)(local_14 + 0xb8);
    lVar9 = *(long *)(local_14 + 0xb4);
    uVar8 = *(undefined8 *)(local_14 + 0x20);
    uVar7 = *(undefined8 *)(local_14 + 0x18);
    uVar6 = *(undefined8 *)(local_14 + 0x10);
    local_20 = pCVar2;
    local_1c = pCVar2;
    FUN_00420820(*(undefined8 *)(local_14 + 8));
    FUN_00420820(uVar6);
    FUN_00420820(uVar7);
    pCVar3 = (CArchive *)FUN_00420820(uVar8);
    CArchive::operator<<(pCVar3,lVar9);
    FUN_00420820(uVar10);
    FUN_00420820(uVar11);
    FUN_00420820(uVar12);
    pCVar3 = (CArchive *)FUN_00420820(uVar13);
    pCVar3 = CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                       (pCVar3,pCVar2);
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>(pCVar3,pCVar4);
    local_8 = 0xffffffff;
    FUN_00404540();
    *(int *)(local_14 + 0xb4) = *(int *)(local_14 + 0xb4) % 10000;
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataMoji[6] */
/* 0048d4b0  FUN_0048d4b0  470 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0048d4b0(int param_1)

{
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092414d;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0042f720(param_1);
  local_3c = param_1;
  FUN_004988c0(local_24,*(undefined4 *)(local_38 + 8),*(undefined4 *)(local_38 + 0xc),
               *(undefined4 *)(local_38 + 0x10),*(undefined4 *)(local_38 + 0x14));
  FUN_004988c0(local_34,*(undefined4 *)(local_38 + 0x18),*(undefined4 *)(local_38 + 0x1c),
               *(undefined4 *)(local_38 + 0x20),*(undefined4 *)(local_38 + 0x24));
  FUN_00404860(local_38 + 0xb0);
  *(undefined4 *)(local_3c + 0xb4) = *(undefined4 *)(local_38 + 0xb4);
  *(undefined8 *)(local_3c + 0xb8) = *(undefined8 *)(local_38 + 0xb8);
  *(undefined8 *)(local_3c + 0xc0) = *(undefined8 *)(local_38 + 0xc0);
  *(undefined8 *)(local_3c + 200) = *(undefined8 *)(local_38 + 200);
  *(undefined8 *)(local_3c + 0xd0) = *(undefined8 *)(local_38 + 0xd0);
  local_44 = FUN_0046b960(local_48);
  local_8 = 0;
  local_40 = local_44;
  FUN_00404860(local_44);
  local_8 = 0xffffffff;
  FUN_00404540();
  *(undefined2 *)(local_3c + 0xdc) = *(undefined2 *)(local_38 + 0xdc);
  *(undefined2 *)(local_3c + 0xde) = *(undefined2 *)(local_38 + 0xde);
  *(undefined8 *)(local_3c + 0xe0) = *(undefined8 *)(local_38 + 0xe0);
  *(undefined8 *)(local_3c + 0xe8) = *(undefined8 *)(local_38 + 0xe8);
  *(undefined2 *)(local_3c + 0x2c) = 1;
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataMoji[4] */
/* 0048e460  FUN_0048e460  1549 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0048e88a) */
/* WARNING: Removing unreachable block (ram,0x0048e986) */

void FUN_0048e460(int param_1)

{
  int iVar1;
  wchar_t *extraout_ECX;
  wchar_t *pwStack_424;
  CSimpleStringT<wchar_t,0> *pCStack_420;
  uint uStack_41c;
  undefined1 *local_418;
  undefined1 *local_414;
  undefined4 local_410;
  undefined4 local_40c [3];
  int local_400;
  undefined1 *local_3fc;
  int local_3f8;
  undefined1 *local_3f4;
  CSimpleStringT<wchar_t,0> local_3f0 [4];
  int local_3ec;
  undefined1 local_3e8 [4];
  undefined4 local_3e4;
  int local_3e0;
  undefined4 local_3dc;
  undefined1 local_3d8 [260];
  undefined8 local_2d4;
  undefined8 local_2cc;
  undefined8 local_2c4;
  undefined8 local_2bc;
  undefined8 local_2b4;
  undefined4 local_2ac;
  undefined1 local_2a8 [260];
  undefined8 local_1a4;
  undefined8 local_19c;
  undefined8 local_194;
  undefined8 local_18c;
  undefined8 local_184;
  undefined8 local_17c;
  undefined8 local_174;
  undefined4 local_16c;
  undefined4 local_168;
  int local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined1 local_158 [260];
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924240;
  local_10 = ExceptionList;
  uStack_41c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pCStack_420 = (CSimpleStringT<wchar_t,0> *)0x48e49c;
  local_14 = uStack_41c;
  local_3e4 = FUN_0040c0e0();
  pCStack_420 = (CSimpleStringT<wchar_t,0> *)local_3e8;
  pwStack_424 = L"Orientation";
  iVar1 = FUN_00572700(local_3e0,L"Printer");
  if (iVar1 == 0) {
    pCStack_420 = (CSimpleStringT<wchar_t,0> *)local_3e8;
    pwStack_424 = L"PaperSize";
    iVar1 = FUN_00572700(local_3e0,L"Printer");
    if (iVar1 == 0) {
      pCStack_420 = (CSimpleStringT<wchar_t,0> *)local_3e8;
      pwStack_424 = L"D2dBMP";
      iVar1 = FUN_00572700(local_3e0,L"Printer");
      if (iVar1 == 0) {
        pCStack_420 = (CSimpleStringT<wchar_t,0> *)local_3e8;
        pwStack_424 = L"BmpZENTAI";
        iVar1 = FUN_00572700(local_3e0,L"Printer");
        if (iVar1 == 0) {
          pCStack_420 = (CSimpleStringT<wchar_t,0> *)local_3e8;
          pwStack_424 = L"Direct2d";
          iVar1 = FUN_00572700(local_3e0,L"View");
          if (iVar1 == 0) {
            pCStack_420 = (CSimpleStringT<wchar_t,0> *)local_3e8;
            pwStack_424 = L"BMPTOUKA";
            iVar1 = FUN_00572700(local_3e0,L"Draw");
            if (iVar1 == 0) {
              pCStack_420 = (CSimpleStringT<wchar_t,0> *)local_3e8;
              pwStack_424 = L"BmpTOUKA";
              iVar1 = FUN_00572700(local_3e0,L"Draw");
              if (iVar1 == 0) {
                local_3ec = 0;
                pCStack_420 = local_3f0;
                pwStack_424 = L"䗇ü";
                FUN_00494640();
                local_8 = 0;
                pCStack_420 = (CSimpleStringT<wchar_t,0> *)0x48e604;
                iVar1 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_3f0);
                if (iVar1 < 1) {
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)(uint)*(ushort *)(local_3e0 + 0x2a);
                  pwStack_424 = (wchar_t *)0x1;
                  local_164 = FUN_0042afb0(*(undefined1 *)(local_3e0 + 0x2f),
                                           *(undefined1 *)(local_3e0 + 0x2e));
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)(uint)*(ushort *)(local_3e0 + 0x2a);
                  pwStack_424 = 
                  L"薉ﺤ\xffff䖋倈趍ﵘ\xffff譑⒍￼\xe8ff\xeefa\xffff藇ﰄ\xffffā";
                  local_160 = FUN_005db650();
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)param_1;
                  pwStack_424 = (wchar_t *)&local_2ac;
                  FUN_0048d690();
                  local_400 = 0x101;
                  local_3fc = local_158;
                  local_410 = 0xff;
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)&local_410;
                  pwStack_424 = (wchar_t *)0x101;
                  FUN_00480450(local_3fc);
                  local_3fc[local_400 + -1] = 0;
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)0x0;
                  local_418 = (undefined1 *)&pwStack_424;
                  pwStack_424 = extraout_ECX;
                  CStringT<>(local_2a8);
                  FUN_004f0780(local_158);
                  local_15c = local_2ac;
                  local_54 = local_1a4;
                  local_4c = local_19c;
                  local_44 = local_194;
                  local_3c = local_18c;
                  local_34 = local_184;
                  local_2c = local_17c;
                  local_24 = local_174;
                  local_18 = local_168;
                  local_1c = local_16c;
                  if (local_164 != -999) {
                    pCStack_420 = (CSimpleStringT<wchar_t,0> *)&local_164;
                    pwStack_424 = L"䕔员";
                    local_3ec = (**(code **)(param_1 + 0x4c158))();
                  }
                  if (local_3ec < 0) {
                    pCStack_420 = (CSimpleStringT<wchar_t,0> *)0x48e97e;
                    FUN_005e6520();
                  }
                  local_8 = 0xffffffff;
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)0x48ea52;
                  FUN_00404540();
                }
                else {
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)(uint)*(ushort *)(local_3e0 + 0x2a);
                  pwStack_424 = (wchar_t *)0x1;
                  local_3dc = FUN_0042afb0(*(undefined1 *)(local_3e0 + 0x2f),
                                           *(undefined1 *)(local_3e0 + 0x2e));
                  local_2d4 = 0;
                  local_2cc = 0;
                  local_2c4 = 0;
                  local_2bc = 0x3ff0000000000000;
                  local_2b4 = 0x3ff0000000000000;
                  local_3f8 = 0x101;
                  local_3f4 = local_3d8;
                  local_40c[0] = 0xff;
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)local_40c;
                  pwStack_424 = (wchar_t *)0x101;
                  FUN_00480450(local_3f4);
                  pwStack_424 = (wchar_t *)(local_3f4 + local_3f8);
                  *(undefined1 *)((int)pwStack_424 + -1) = 0;
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)0x0;
                  local_414 = (undefined1 *)&pwStack_424;
                  FUN_00403dd0(local_3f0);
                  FUN_004f0780(local_3d8);
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)&local_3dc;
                  pwStack_424 = L"SFIG_LOCATE";
                  local_3ec = (**(code **)(param_1 + 0x4c158))();
                  if (local_3ec < 0) {
                    pCStack_420 = (CSimpleStringT<wchar_t,0> *)0x48e71f;
                    FUN_005e6520();
                  }
                  local_8 = 0xffffffff;
                  pCStack_420 = (CSimpleStringT<wchar_t,0> *)0x48e731;
                  FUN_00404540();
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataMoji[7] */
/* 00492fd0  FUN_00492fd0  613 bytes, 0 callers */

undefined4 FUN_00492fd0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092455d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_0079d98a(&PTR_s_CDataMoji_009fe108,DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_00438910(param_1);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      local_1c = param_1;
      iVar2 = FUN_00498960(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                           *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        iVar2 = FUN_00498960(*(undefined4 *)(local_1c + 0x18),*(undefined4 *)(local_1c + 0x1c),
                             *(undefined4 *)(local_1c + 0x20),*(undefined4 *)(local_1c + 0x24));
        if (iVar2 == 0) {
          uVar3 = 0;
        }
        else {
          cVar1 = FUN_00414010(local_18 + 0xb0,local_1c + 0xb0);
          if (cVar1 == '\0') {
            uVar3 = 0;
          }
          else if (*(int *)(local_18 + 0xb4) == *(int *)(local_1c + 0xb4)) {
            if (*(double *)(local_18 + 0xb8) == *(double *)(local_1c + 0xb8)) {
              if (*(double *)(local_18 + 0xc0) == *(double *)(local_1c + 0xc0)) {
                if (*(double *)(local_18 + 200) == *(double *)(local_1c + 200)) {
                  if (*(double *)(local_18 + 0xd0) == *(double *)(local_1c + 0xd0)) {
                    uVar3 = FUN_0046b960(local_34);
                    local_8 = 0;
                    local_28 = uVar3;
                    local_24 = uVar3;
                    local_2c = FUN_0046b960(local_30);
                    cVar1 = FUN_00414010(local_2c,uVar3);
                    local_11 = cVar1 == '\0';
                    local_20 = (uint)(byte)local_11;
                    FUN_00404540();
                    local_8 = 0xffffffff;
                    FUN_00404540();
                    if (local_11 == '\0') {
                      if (*(short *)(local_18 + 0xdc) == *(short *)(local_1c + 0xdc)) {
                        if (*(short *)(local_18 + 0xde) == *(short *)(local_1c + 0xde)) {
                          uVar3 = 1;
                        }
                        else {
                          uVar3 = 0;
                        }
                      }
                      else {
                        uVar3 = 0;
                      }
                    }
                    else {
                      uVar3 = 0;
                    }
                  }
                  else {
                    uVar3 = 0;
                  }
                }
                else {
                  uVar3 = 0;
                }
              }
              else {
                uVar3 = 0;
              }
            }
            else {
              uVar3 = 0;
            }
          }
          else {
            uVar3 = 0;
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return uVar3;
}



