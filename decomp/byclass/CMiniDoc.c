/* CMiniDoc -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMiniDoc[1] */
/* 00570700  FUN_00570700  68 bytes, 0 callers */

undefined4 FUN_00570700(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00570440();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1d20);
    }
  }
  return in_ECX;
}




/* vtable slots: CMiniDoc[29] */
/* 00571b50  FUN_00571b50  743 bytes, 5 callers */

void FUN_00571b50(void)

{
  int iVar1;
  int *piVar2;
  
  FUN_00574d00();
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  FUN_00574f10();
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  RemoveAll();
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  return;
}




/* vtable slots: CMiniDoc[10] */
/* 005726f0  FUN_005726f0  16 bytes, 0 callers */

void FUN_005726f0(void)

{
  FUN_00573490();
  return;
}




/* vtable slots: CMiniDoc[0] */
/* 00572a10  FUN_00572a10  16 bytes, 0 callers */

undefined ** FUN_00572a10(void)

{
  return &PTR_s_CMiniDoc_0096afe0;
}




/* vtable slots: CMiniDoc[30] */
/* 00573cd0  FUN_00573cd0  68 bytes, 0 callers */

bool FUN_00573cd0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_007a9f42();
  if (iVar1 != 0) {
    FUN_004948d0(in_ECX + 0x398);
    *(undefined4 *)(in_ECX + 0x3a0) = 0;
    *(undefined4 *)(in_ECX + 0x3a4) = 0;
  }
  return iVar1 != 0;
}




/* vtable slots: CMiniDoc[2] */
/* 00575010  FUN_00575010  22125 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00576f89) */
/* WARNING: Removing unreachable block (ram,0x00577559) */
/* WARNING: Removing unreachable block (ram,0x00576a31) */

void FUN_00575010(CArchive *param_1)

{
  double *pdVar1;
  char cVar2;
  int iVar3;
  CArchive *pCVar4;
  int *piVar5;
  long lVar6;
  long lVar7;
  uint *puVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  uint *puVar12;
  long lVar13;
  long *plVar14;
  uint *puVar15;
  uint uStack_bce20;
  undefined1 auStack_bce08 [8];
  undefined1 auStack_bce00 [8];
  undefined1 auStack_bcdf8 [24];
  undefined1 auStack_bcde0 [8];
  undefined1 auStack_bcdd8 [8];
  undefined1 auStack_bcdd0 [16];
  undefined1 auStack_bcdc0 [24];
  undefined8 uStack_bcda8;
  undefined8 uStack_bcda0;
  undefined8 uStack_bcd98;
  undefined8 uStack_bcd90;
  undefined8 uStack_bcd78;
  undefined1 auStack_bcd70 [24];
  undefined8 uStack_bcd58;
  undefined8 uStack_bcd50;
  CObList aCStack_bcd48 [28];
  undefined1 *puStack_bcd2c;
  undefined1 *puStack_bcd28;
  undefined4 uStack_bcd24;
  undefined1 *puStack_bcd20;
  undefined1 *puStack_bcd1c;
  undefined4 uStack_bcd18;
  undefined1 *puStack_bcd14;
  undefined1 *puStack_bcd10;
  undefined1 *puStack_bcd0c;
  long lStack_bcd08;
  long lStack_bcd04;
  long lStack_bcd00;
  undefined1 *puStack_bccfc;
  undefined4 uStack_bccf8;
  undefined1 *puStack_bccf4;
  undefined4 uStack_bccec;
  undefined8 uStack_bcce8;
  undefined8 uStack_bcce0;
  undefined8 uStack_bccd8;
  undefined8 uStack_bccd0;
  undefined8 uStack_bccc8;
  double dStack_bccc0;
  double dStack_bccb8;
  undefined8 uStack_bcca0;
  undefined8 uStack_bcc98;
  undefined8 uStack_bcc90;
  undefined8 uStack_bcc88;
  undefined8 uStack_bcc80;
  undefined8 uStack_bcc78;
  long lStack_bcc70;
  undefined1 *puStack_bcc6c;
  long lStack_bcc68;
  long lStack_bcc64;
  long lStack_bcc60;
  long alStack_bcc5c [6];
  undefined8 uStack_bcc44;
  undefined8 uStack_bcc3c;
  undefined8 uStack_bcc34;
  double dStack_bcc2c;
  double dStack_bcc24;
  double dStack_bcc1c;
  double dStack_bcc14;
  undefined8 uStack_bcc0c;
  undefined8 uStack_bcc04;
  undefined8 uStack_bcbf4;
  double dStack_bcbec;
  undefined4 uStack_bcbd0;
  undefined4 uStack_bcbcc;
  undefined4 uStack_bcbc8;
  undefined4 uStack_bcbc0;
  undefined4 uStack_bcbbc;
  undefined4 uStack_bcbb4;
  undefined4 uStack_bcbb0;
  undefined4 uStack_bcbac;
  undefined4 uStack_bcba8;
  undefined4 uStack_bcba4;
  int iStack_bcba0;
  undefined4 uStack_bcb98;
  long lStack_bcb94;
  undefined4 uStack_bcb90;
  int iStack_bcb8c;
  undefined4 uStack_bcb88;
  undefined4 uStack_bcb80;
  undefined4 uStack_bcb7c;
  long lStack_bcb78;
  undefined4 uStack_bcb74;
  undefined4 uStack_bcb70;
  undefined1 *puStack_bcb6c;
  undefined1 *puStack_bcb68;
  undefined4 uStack_bcb64;
  int iStack_bcb60;
  int iStack_bcb58;
  undefined4 uStack_bcb54;
  undefined4 uStack_bcb50;
  undefined4 uStack_bcb48;
  undefined4 uStack_bcb44;
  undefined1 auStack_bcb40 [4];
  undefined4 uStack_bcb3c;
  int iStack_bcb38;
  int iStack_bcb34;
  int iStack_bcb2c;
  undefined4 uStack_bcb28;
  undefined4 uStack_bcb24;
  int iStack_bcb20;
  undefined4 uStack_bcb1c;
  undefined4 uStack_bcb14;
  undefined4 uStack_bcb10;
  undefined4 uStack_bcb08;
  undefined4 uStack_bcb04;
  undefined4 uStack_bcafc;
  undefined4 uStack_bcaf8;
  undefined8 uStack_bcaf4;
  double dStack_bcaec;
  double dStack_bcae4;
  int iStack_bcadc;
  long lStack_bcad8;
  long lStack_bcad4;
  long lStack_bcad0;
  int iStack_bcacc;
  uint uStack_bcac8;
  int iStack_bcac4;
  undefined4 uStack_bcac0;
  int iStack_bcabc;
  undefined4 uStack_bcab8;
  undefined4 uStack_bcab4;
  undefined4 uStack_bcab0;
  long lStack_bcaac;
  long lStack_bcaa8;
  int iStack_bcaa4;
  int iStack_bcaa0;
  int iStack_bca9c;
  int iStack_bca98;
  undefined4 uStack_bca94;
  int *piStack_bca90;
  uint uStack_bca8c;
  int iStack_bca88;
  int iStack_bca84;
  uint uStack_bca80;
  int iStack_bca7c;
  long lStack_bca78;
  int iStack_bca74;
  undefined4 uStack_bca70;
  int iStack_bca6c;
  int iStack_bca68;
  undefined4 uStack_bca64;
  undefined4 uStack_bca60;
  uint uStack_bca5c;
  int iStack_bca58;
  double dStack_bca54;
  long lStack_bca4c;
  double dStack_bca48;
  int iStack_bca40;
  long lStack_bca3c;
  undefined1 auStack_bca38 [4];
  long lStack_bca34;
  int iStack_bca30;
  int iStack_bca2c;
  undefined8 uStack_bca28;
  int iStack_bca20;
  long lStack_bca1c;
  int iStack_bca18;
  int iStack_bca14;
  int iStack_bca10;
  uint uStack_bca08;
  uint uStack_bca04;
  int iStack_bca00;
  uint uStack_bc9fc;
  int iStack_bc9f8;
  int iStack_bc9f4;
  long alStack_bc9ec [2];
  int iStack_bc9e4;
  int iStack_bc9e0;
  uint uStack_bc9dc;
  long lStack_bc9d8;
  int iStack_bc9d4;
  long lStack_bc9d0;
  int iStack_bc9cc;
  int iStack_bc9c8;
  char cStack_bc9c4;
  char cStack_bc9c3;
  char cStack_bc9c2;
  char cStack_bc9c1;
  long lStack_bc9c0;
  int iStack_bc9bc;
  int iStack_bc9b8;
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> aCStack_bc9b0 [4];
  undefined1 auStack_bc9ac [4];
  undefined1 auStack_bc9a8 [4];
  long alStack_bc9a4 [2];
  long lStack_bc99c;
  int *piStack_bc998;
  long lStack_bc994;
  int iStack_bc990;
  int iStack_bc988;
  int iStack_bc984;
  uint uStack_bc980;
  int iStack_bc97c;
  uint uStack_bc978;
  uint uStack_bc974;
  int iStack_bc970;
  uint uStack_bc96c;
  int iStack_bc968;
  int iStack_bc964;
  int iStack_bc960;
  int *piStack_bc95c;
  int iStack_bc958;
  int iStack_bc954;
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> local_ae78 [4004];
  undefined8 auStack_9ed4 [16];
  long local_9e54 [10026];
  char local_1ac [404];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092de99;
  local_10 = ExceptionList;
  uStack_bce20 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_bce20;
  ExceptionList = &local_10;
  uStack_bc9fc = 0;
  local_18 = uStack_bce20;
  iVar3 = FUN_0042ddc0();
  if (iVar3 != 0) {
    FUN_0057b060();
  }
  uStack_bcb70 = (**(code **)(*piStack_bc95c + 0x68))();
  iStack_bc988 = 0;
  iStack_bc9e0 = 0;
  iStack_bc964 = 0;
  FUN_004948d0();
  piStack_bc95c[0xd4] = 0;
  DAT_00a08ae4 = 0;
  for (iStack_bc9e0 = 0; iStack_bc9e0 < 0xd; iStack_bc9e0 = iStack_bc9e0 + 1) {
    *(undefined8 *)(&DAT_00a08ae8 + iStack_bc9e0 * 8) = 0;
  }
  iStack_bc954 = 0;
  if (piStack_bc95c[0x38] == 0) {
    iStack_bc988 = (**(code **)(*piStack_bc95c + 0x6c))();
    if (iStack_bc988 == 0) {
      iStack_bca88 = 0;
    }
    else {
      iStack_bca88 = iStack_bc988 + 0x88;
    }
    iStack_bc954 = iStack_bca88;
  }
  else {
    iStack_bc954 = piStack_bc95c[0x38];
  }
  for (uStack_bc974 = 0; (int)uStack_bc974 < 0x16; uStack_bc974 = uStack_bc974 + 1) {
    local_9e54[uStack_bc974] = 0;
  }
  for (uStack_bc974 = 0; (int)uStack_bc974 < 0xcc; uStack_bc974 = uStack_bc974 + 1) {
    uStack_bca8c = uStack_bc974;
    if (0x193 < uStack_bc974) {
                    /* WARNING: Subroutine does not return */
      FUN_008d927f();
    }
    local_1ac[uStack_bc974] = '\0';
  }
  piStack_bc998 = (int *)FUN_004d1e10();
  iVar3 = FUN_0042ddc0();
  if (iVar3 == 0) {
    lStack_bc9d8 = 0;
    uStack_bc96c = 0;
    uStack_bc980 = 0;
    uStack_bc978 = 0;
    lStack_bca34 = 0;
    CStringT<>();
    local_8 = 6;
    uStack_bcaf4 = 0;
    uStack_bcd50 = 0;
    uStack_bcd58 = 0;
    piStack_bc95c[0xd3] = 0;
    piStack_bc95c[0xd2] = 0;
    piStack_bc95c[0xd1] = 0;
    piStack_bc95c[0xd0] = 0;
    piStack_bc95c[0xcf] = 0;
    DAT_00a0b414 = -1;
    (**(code **)(*piStack_bc998 + 0x38))();
    uStack_bcab0 = 0x10;
    local_1ac[0x10] = 0;
    FUN_0048cb10();
    DAT_00a08ae4 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 7;
    CStringT<>();
    local_8._0_1_ = 8;
    puStack_bcc6c = &stack0xfff431d4;
    (**(code **)(*piStack_bc998 + 0x10))();
    uStack_bcb80 = FUN_0044ef10();
    local_8._0_1_ = 9;
    uStack_bcb7c = uStack_bcb80;
    FUN_00404860();
    local_8._0_1_ = 8;
    FUN_00404540();
    cVar2 = FUN_00447350();
    if ((((cVar2 != '\0') && (local_1ac[2] != '\0')) && (local_1ac[3] != '\0')) &&
       ((local_1ac[4] != '\0' && (local_1ac[5] != '\0')))) {
      FUN_0049c2c0();
      local_8._0_1_ = 10;
      FUN_0049f4d0();
      *(undefined4 *)(iStack_bc954 + 0x2a3c) = 0;
      FUN_00404900();
      DAT_00a0b414 = 0;
      *(undefined4 *)(iStack_bc954 + 0x8440) = 1;
      local_8._0_1_ = 8;
      FUN_0049cc10();
      local_8._0_1_ = 7;
      FUN_00404540();
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return;
    }
    cVar2 = FUN_00447350();
    if (((cVar2 != '\0') && (DAT_00a08ab4 != 0)) ||
       ((cVar2 = FUN_00447350(), cVar2 != '\0' && (DAT_00a08ab8 != 0)))) {
      cVar2 = FUN_00447350();
      if (cVar2 == '\0') {
        uStack_bcab4 = 2;
      }
      else {
        uStack_bcab4 = 1;
      }
      uStack_bcb88 = uStack_bcab4;
      if ((((local_1ac[2] != '\0') && (local_1ac[3] != '\0')) && (local_1ac[4] != '\0')) &&
         (local_1ac[5] != '\0')) {
        FUN_005daa80();
        local_8._0_1_ = 0xb;
        FUN_005dc020();
        *(undefined4 *)(iStack_bc954 + 0x2a3c) = 0;
        ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::operator=
                  ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                   (iStack_bc954 + 0x2a38),"");
        DAT_00a0b414 = 0;
        *(undefined4 *)(iStack_bc954 + 0x8440) = 1;
        local_8._0_1_ = 8;
        FUN_005db1b0();
        local_8._0_1_ = 7;
        FUN_00404540();
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_00404540();
        ExceptionList = local_10;
        return;
      }
    }
    iVar3 = _strcmp(local_1ac,"jw_cad(c)data...");
    if (iVar3 == 0) {
      FUN_00518ac0();
      local_8 = CONCAT31(local_8._1_3_,0xc);
      if (DAT_00a101a8 == 0) {
        iVar3 = FUN_00518c80();
        if (iVar3 == 0) {
          (**(code **)(*piStack_bc95c + 0x78))();
        }
        *(undefined4 *)(iStack_bc954 + 0x2a3c) = 0;
        FUN_00404900();
      }
      else {
        FUN_00518c80();
      }
      DAT_00a0b414 = 0;
      local_8._0_1_ = 8;
      FUN_004066b0();
      local_8._0_1_ = 7;
      FUN_00404540();
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return;
    }
    iVar3 = _strcmp(local_1ac,"jw_cad(c)sym....");
    if (iVar3 == 0) {
      FUN_00518ac0();
      local_8 = CONCAT31(local_8._1_3_,0xd);
      iVar3 = FUN_0079d98a();
      if (iVar3 == 0) {
        FUN_0051cc20();
      }
      else {
        iVar3 = FUN_0051cc20();
        if (iVar3 == 0) {
          (**(code **)(*piStack_bc95c + 0x78))();
        }
      }
      local_8._0_1_ = 8;
      FUN_004066b0();
      local_8._0_1_ = 7;
      FUN_00404540();
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return;
    }
    uStack_bcab8 = 8;
    local_1ac[8] = 0;
    iVar3 = _strcmp(local_1ac,"JwsData.");
    if (iVar3 == 0) {
      iVar3 = FUN_0079d98a();
      if (iVar3 != 0) {
        FUN_007a6927();
        CArchive::operator>>(param_1,&iStack_bcb8c);
        DAT_00a0b414 = iStack_bcb8c;
        FUN_00420650();
        FUN_00420650();
        for (iStack_bca20 = 0; iStack_bca20 < 0x10; iStack_bca20 = iStack_bca20 + 1) {
          FUN_00420650();
          auStack_9ed4[iStack_bca20] = uStack_bcca0;
        }
        plVar14 = alStack_bcc5c;
        plVar11 = &lStack_bcc60;
        pCVar4 = CArchive::operator>>(param_1,&lStack_bcc64);
        pCVar4 = CArchive::operator>>(pCVar4,plVar11);
        CArchive::operator>>(pCVar4,plVar14);
        plVar14 = &lStack_bcc68;
        plVar11 = &lStack_bcc70;
        pCVar4 = CArchive::operator>>(param_1,&lStack_bcd00);
        pCVar4 = CArchive::operator>>(pCVar4,plVar11);
        CArchive::operator>>(pCVar4,plVar14);
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_0057a780();
        (**(code **)(piStack_bc95c[0x39] + 8))();
        (**(code **)(piStack_bc95c[0x40] + 8))();
        FUN_005709a0();
        FUN_0041fb60();
        local_8._0_1_ = 0xe;
        FUN_00408a30();
        FUN_0040da70();
        FUN_0042f660();
        FUN_00455c40();
        uStack_bcb90 = FUN_0042e040();
        FUN_00570750();
        uStack_bca28 = 0x3f50624dd2f1a9fc;
        dStack_bca54 = (double)*(int *)(piStack_bc95c[0x38] + 0x1720) * 2.0 - 16.0;
        if (dStack_bca54 < 0.001) {
          dStack_bca54 = 0.001;
        }
        dStack_bca48 = ((double)*(int *)(piStack_bc95c[0x38] + 0x1724) * 2.0 - 16.0) - 8.0;
        if (dStack_bca48 < 0.001) {
          dStack_bca48 = 0.001;
        }
        dStack_bccb8 = dStack_bca54 * *(double *)(iStack_bc954 + 6000);
        dStack_bccc0 = dStack_bca48 * *(double *)(iStack_bc954 + 6000);
        dStack_bca54 = dStack_bcc24 - dStack_bcc1c;
        if (dStack_bca54 < 0.001) {
          dStack_bca54 = 0.001;
        }
        dStack_bca48 = dStack_bcc2c - dStack_bcbec;
        if (dStack_bca48 < 0.001) {
          dStack_bca48 = 0.001;
        }
        dStack_bcc14 = dStack_bccb8 / dStack_bca54;
        if (dStack_bccc0 / dStack_bca48 <= dStack_bcc14) {
          *(double *)(piStack_bc95c[0x38] + 0x1728) = dStack_bccc0 / dStack_bca48;
        }
        else {
          *(double *)(piStack_bc95c[0x38] + 0x1728) = dStack_bcc14;
        }
        *(double *)(piStack_bc95c[0x38] + 0x7a18) = (dStack_bcc1c + dStack_bcc24) / 2.0;
        *(double *)(piStack_bc95c[0x38] + 0x7a20) = (dStack_bcbec + dStack_bcc2c) / 2.0;
        dStack_bcae4 = (*(double *)(iStack_bc954 + 6000) * 8.0) /
                       *(double *)(piStack_bc95c[0x38] + 0x1728);
        *(double *)(piStack_bc95c[0x38] + 0x7a20) =
             *(double *)(piStack_bc95c[0x38] + 0x7a20) + dStack_bcae4;
        local_8._0_1_ = 8;
        FUN_0041fe70();
      }
      local_8._0_1_ = 7;
      FUN_00404540();
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return;
    }
    *(undefined4 *)(iStack_bc954 + 0x1754) = 1;
    uStack_bcac0 = 8;
    local_1ac[8] = 0;
    iVar3 = _strcmp(local_1ac,"JwwData.");
    if (iVar3 == 0) {
      FUN_007a6927();
      CArchive::operator>>(param_1,&DAT_00a0b414);
    }
    else if (((local_1ac[0] == '\v') && (local_1ac[1] == '\0')) &&
            ((local_1ac[2] == '\0' && (local_1ac[3] == '\0')))) {
      CArchive::operator>>(param_1,&lStack_bcd04);
      DAT_00a0b414 = 3;
    }
    else if ((((local_1ac[0] == 'd') && (local_1ac[1] == '\0')) && (local_1ac[2] == '\0')) &&
            (local_1ac[3] == '\0')) {
      CArchive::operator>>(param_1,&lStack_bcd08);
      DAT_00a0b414 = 10;
    }
    iStack_bc970 = DAT_00a0b414;
    if (((0 < DAT_00a0b414) && (DAT_00a0b414 < 700)) && (iStack_bc988 != 0)) {
      FUN_005168b0();
    }
    if (iStack_bc970 == -1) {
      if (iStack_bc988 != 0) {
        FUN_004f60a0();
      }
      piStack_bc95c[0xd4] = 1;
      local_8._0_1_ = 7;
      FUN_00404540();
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return;
    }
    if (700 < iStack_bc970) {
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,0xf);
      FUN_00571e40();
      if (iStack_bc988 != 0) {
        puStack_bcd0c = &stack0xfff431c8;
        FUN_00403dd0(auStack_bca38);
        FUN_00516ac0();
      }
      piStack_bc95c[0xd4] = 1;
      local_8._0_1_ = 8;
      FUN_00404540();
      local_8._0_1_ = 7;
      FUN_00404540();
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return;
    }
    if (0x40 < iStack_bc970) {
      FUN_0047fc90();
    }
    for (iStack_bc968 = 0; iStack_bc968 < 0x10; iStack_bc968 = iStack_bc968 + 1) {
      *(undefined4 *)(iStack_bc954 + 0x29f4 + iStack_bc968 * 4) = 0;
      for (iStack_bc97c = 0; iStack_bc97c < 0x10; iStack_bc97c = iStack_bc97c + 1) {
        *(undefined4 *)(iStack_bc954 + 0x25f4 + iStack_bc968 * 0x40 + iStack_bc97c * 4) = 0;
      }
    }
    if (9 < iStack_bc970) {
      CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x2f98));
      CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x24e4));
      for (iStack_bc968 = 0; iStack_bc968 < 0x10; iStack_bc968 = iStack_bc968 + 1) {
        *(undefined4 *)(iStack_bc954 + 0x29f4 + iStack_bc968 * 4) = 0;
        CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x23a4 + iStack_bc968 * 4));
        CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x2464 + iStack_bc968 * 4));
        FUN_00420650();
        pdVar1 = (double *)(iStack_bc954 + 0x24f0 + iStack_bc968 * 8);
        if (*pdVar1 <= 1e-07 && *pdVar1 != 1e-07) {
          *(undefined8 *)(iStack_bc954 + 0x24f0 + iStack_bc968 * 8) = 0x3ff0000000000000;
        }
        if (0xd3 < iStack_bc970) {
          CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x29f4 + iStack_bc968 * 4));
        }
        for (iStack_bc97c = 0; iStack_bc97c < 0x10; iStack_bc97c = iStack_bc97c + 1) {
          *(undefined4 *)(iStack_bc954 + 0x25f4 + iStack_bc968 * 0x40 + iStack_bc97c * 4) = 0;
          CArchive::operator>>
                    (param_1,(long *)(iStack_bc954 + 0x17a4 + iStack_bc968 * 0x40 + iStack_bc97c * 4
                                     ));
          if (0xd3 < iStack_bc970) {
            CArchive::operator>>
                      (param_1,(long *)(iStack_bc954 + 0x25f4 + iStack_bc968 * 0x40 +
                                       iStack_bc97c * 4));
          }
        }
      }
    }
    piStack_bc95c[0xce] = 0;
    *(undefined4 *)(iStack_bc954 + 0x2a3c) = 0;
    FUN_00404900();
    piStack_bc95c[0xd3] = 0;
    piStack_bc95c[0xd2] = 0;
    piStack_bc95c[0xd1] = 0;
    piStack_bc95c[0xd0] = 0;
    piStack_bc95c[0xcf] = 0;
    if (0xd3 < iStack_bc970) {
      CArchive::operator>>(param_1,piStack_bc95c + 0xce);
      for (uStack_bc974 = 0; (int)uStack_bc974 < 0xd; uStack_bc974 = uStack_bc974 + 1) {
        CArchive::operator>>(param_1,local_9e54 + uStack_bc974);
      }
      CArchive::operator>>(param_1,piStack_bc95c + 0xcf);
      CArchive::operator>>(param_1,piStack_bc95c + 0xd0);
      CArchive::operator>>(param_1,piStack_bc95c + 0xd1);
      CArchive::operator>>(param_1,piStack_bc95c + 0xd2);
      CArchive::operator>>(param_1,piStack_bc95c + 0xd3);
      CArchive::operator>>(param_1,local_9e54 + 0x12);
      lStack_bc99c = 0;
      CArchive::operator>>(param_1,&lStack_bc99c);
      if (DAT_00a0cab4 != 0) {
        if (lStack_bc99c < 1) {
          iStack_bcac4 = -lStack_bc99c;
        }
        else {
          iStack_bcac4 = lStack_bc99c;
        }
        iStack_bc9d4 = iStack_bcac4;
        DAT_00a0ca7c = 100;
        if ((200 < iStack_bcac4) && (iStack_bcac4 < 0x12d)) {
          DAT_00a0ca7c = iStack_bcac4 + -200;
        }
        if ((400 < iStack_bcac4) && (iStack_bcac4 < 0x1f5)) {
          DAT_00a0ca7c = -(iStack_bcac4 + -400);
        }
        uStack_bcac8 = (uint)(lStack_bc99c < -100);
        DAT_00a0ca90 = uStack_bcac8;
        if (lStack_bc99c < -100) {
          lStack_bc99c = -100;
        }
        if (100 < lStack_bc99c) {
          lStack_bc99c = 100;
        }
        if (lStack_bc99c == 0) {
          DAT_00a0ca78 = 100;
        }
        else {
          DAT_00a0ca78 = lStack_bc99c;
        }
      }
    }
    if (0x3b < iStack_bc970) {
      FUN_00420650();
      FUN_00420650();
    }
    if (DAT_00a0cab4 != 0) {
      *(undefined8 *)(iStack_bc954 + 0x2fa0) = 0x3ff0000000000000;
      *(undefined4 *)(iStack_bc954 + 0x2fa8) = 0;
    }
    if (0xc9 < iStack_bc970) {
      uStack_bcc34 = 0x3ff0000000000000;
      alStack_bc9ec[0] = 0;
      FUN_00420650();
      CArchive::operator>>(param_1,alStack_bc9ec);
      if (DAT_00a0cab4 != 0) {
        *(undefined8 *)(iStack_bc954 + 0x2fa0) = uStack_bcc34;
        *(int *)(iStack_bc954 + 0x2fa8) = alStack_bc9ec[0] % 10;
        if (299 < iStack_bc970) {
          alStack_bc9ec[0] = alStack_bc9ec[0] / 10;
          *(int *)(iStack_bc954 + 0x2fc0) = alStack_bc9ec[0] % 10;
        }
      }
    }
    if (0x3d < iStack_bc970) {
      alStack_bc9a4[0] = 0;
      CArchive::operator>>(param_1,alStack_bc9a4);
      if (alStack_bc9a4[0] < 0) {
        *(undefined4 *)(iStack_bc954 + 0x7988) = 1;
        if (alStack_bc9a4[0] < 1) {
          iStack_bcacc = -alStack_bc9a4[0];
        }
        else {
          iStack_bcacc = alStack_bc9a4[0];
        }
        alStack_bc9a4[0] = iStack_bcacc + -1;
      }
      else {
        *(undefined4 *)(iStack_bc954 + 0x7988) = 0;
      }
      if (alStack_bc9a4[0] < 10) {
        *(undefined4 *)(iStack_bc954 + 0x798c) = 0;
      }
      else {
        *(undefined4 *)(iStack_bc954 + 0x798c) = 1;
        alStack_bc9a4[0] = alStack_bc9a4[0] + -10;
      }
      *(long *)(iStack_bc954 + 0x7984) = alStack_bc9a4[0];
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
    }
    for (iStack_bc958 = 0; iStack_bc958 < 0x10; iStack_bc958 = iStack_bc958 + 1) {
      for (iStack_bc9b8 = 0; iStack_bc9b8 < 0x10; iStack_bc9b8 = iStack_bc9b8 + 1) {
        FUN_00404900();
      }
    }
    for (iStack_bc958 = 0; iStack_bc958 < 0x10; iStack_bc958 = iStack_bc958 + 1) {
      FUN_00404900();
    }
    if (0x3f < iStack_bc970) {
      for (iStack_bc958 = 0; iStack_bc958 < 0x10; iStack_bc958 = iStack_bc958 + 1) {
        for (iStack_bc9b8 = 0; iStack_bc9b8 < 0x10; iStack_bc9b8 = iStack_bc9b8 + 1) {
          FUN_0047fc90();
        }
      }
      for (iStack_bc958 = 0; iStack_bc958 < 0x10; iStack_bc958 = iStack_bc958 + 1) {
        FUN_0047fc90();
      }
    }
    if (99 < iStack_bc970) {
      FUN_00420650();
      FUN_00420650();
      CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x8348));
    }
    if (100 < iStack_bc970) {
      FUN_00420650();
      *(undefined8 *)(iStack_bc954 + 0x8358) = 0;
      *(undefined8 *)(iStack_bc954 + 0x8360) = 0x4039000000000000;
      if (299 < iStack_bc970) {
        FUN_00420650();
        FUN_00420650();
        *(double *)(iStack_bc954 + 0x8360) = *(double *)(iStack_bc954 + 0x8360) / 2.0;
      }
      CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x8268));
    }
    if (199 < iStack_bc970) {
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      if (iStack_bc970 < 300) {
        for (iStack_bc958 = 1; iStack_bc958 < 5; iStack_bc958 = iStack_bc958 + 1) {
          FUN_00420650();
          FUN_00420650();
          FUN_00420650();
          *(undefined4 *)(iStack_bc954 + 0x7b60 + iStack_bc958 * 4) = 0xffffffff;
        }
      }
      else {
        for (iStack_bc958 = 1; iStack_bc958 < 9; iStack_bc958 = iStack_bc958 + 1) {
          FUN_00420650();
          FUN_00420650();
          FUN_00420650();
          CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x7b60 + iStack_bc958 * 4));
          pdVar1 = (double *)(iStack_bc954 + 0x7a70 + iStack_bc958 * 8);
          if (*pdVar1 <= 1e-07 && *pdVar1 != 1e-07) {
            *(undefined8 *)(iStack_bc954 + 0x7a70 + iStack_bc958 * 8) = 0x3ff0000000000000;
          }
          if ((*(int *)(iStack_bc954 + 0x7b60 + iStack_bc958 * 4) < -1) ||
             (0xf < *(int *)(iStack_bc954 + 0x7b60 + iStack_bc958 * 4))) {
            *(undefined4 *)(iStack_bc954 + 0x7b60 + iStack_bc958 * 4) = 0xffffffff;
          }
        }
        uStack_bccc8 = 0;
        uStack_bccd0 = 0;
        uStack_bccd8 = 0;
        uStack_bcce0 = 0;
        uStack_bcce8 = 0;
        dStack_bcaec = 0.0;
        lStack_bcb94 = 0;
        lStack_bc994 = 0;
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        CArchive::operator>>(param_1,&lStack_bcb94);
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        CArchive::operator>>(param_1,&lStack_bc994);
        if (DAT_00a0cab4 != 0) {
          if ((dStack_bcaec < -1.0) || (10.0 < dStack_bcaec)) {
            *(undefined8 *)(iStack_bc954 + 0x8248) = 0;
          }
          else {
            *(double *)(iStack_bc954 + 0x8248) = dStack_bcaec;
          }
          if (0 < lStack_bc994) {
            lStack_bc994 = (lStack_bc994 + -1) % 100;
            if (lStack_bc994 < 10) {
              *(undefined4 *)(iStack_bc954 + 0x8258) = 0;
            }
            else {
              *(undefined4 *)(iStack_bc954 + 0x8258) = 1;
            }
            lStack_bc994 = lStack_bc994 % 10;
            if ((-1 < lStack_bc994) && (lStack_bc994 < 3)) {
              *(long *)(iStack_bc954 + 0x8240) = lStack_bc994;
            }
          }
        }
      }
      for (iStack_bc958 = 0; iStack_bc958 < 10; iStack_bc958 = iStack_bc958 + 1) {
        FUN_00420650();
      }
      FUN_00420650();
    }
    if (200 < iStack_bc970) {
      for (iStack_bc958 = 0; iStack_bc958 < 10; iStack_bc958 = iStack_bc958 + 1) {
        puVar15 = &uStack_bc96c;
        pCVar4 = CArchive::operator>>(param_1,&lStack_bca4c);
        CArchive::operator>>(pCVar4,(long *)puVar15);
        if (DAT_00a0cab0 != 0) {
          iStack_bc964 = iStack_bc958;
          if (iStack_bc958 == 9) {
            iStack_bc964 = 0xd;
          }
          *(long *)(iStack_bc954 + 0x5268 + iStack_bc964 * 4) = lStack_bca4c;
          *(uint *)(iStack_bc954 + 0x5d98 + iStack_bc964 * 4) = uStack_bc96c;
        }
      }
      for (iStack_bc958 = 0; iStack_bc958 < 10; iStack_bc958 = iStack_bc958 + 1) {
        puVar15 = &uStack_bc96c;
        pCVar4 = CArchive::operator>>(param_1,&lStack_bca4c);
        CArchive::operator>>(pCVar4,(long *)puVar15);
        FUN_00420650();
        if (DAT_00a0cab0 != 0) {
          iStack_bc964 = iStack_bc958;
          if (iStack_bc958 == 9) {
            iStack_bc964 = 0xd;
          }
          *(long *)(iStack_bc954 + 0x57fc + iStack_bc964 * 4) = lStack_bca4c;
          *(uint *)(iStack_bc954 + 0x632c + iStack_bc964 * 4) = uStack_bc96c;
          *(undefined8 *)(iStack_bc954 + 0x68c0 + iStack_bc964 * 8) = uStack_bcaf4;
        }
      }
      for (iStack_bc958 = 2; iStack_bc958 < 10; iStack_bc958 = iStack_bc958 + 1) {
        puVar15 = &uStack_bc978;
        puVar12 = &uStack_bc980;
        puVar8 = &uStack_bc96c;
        pCVar4 = CArchive::operator>>(param_1,&lStack_bc9d8);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar8);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar12);
        CArchive::operator>>(pCVar4,(long *)puVar15);
        if (DAT_00a0cab0 != 0) {
          *(long *)(iStack_bc954 + 0x2fc4 + iStack_bc958 * 4) = lStack_bc9d8;
          *(uint *)(iStack_bc954 + 0x4d40 + iStack_bc958 * 4) = uStack_bc96c;
          *(uint *)(iStack_bc954 + 0x5058 + iStack_bc958 * 4) = uStack_bc980;
          *(uint *)(iStack_bc954 + 0x5160 + iStack_bc958 * 4) = uStack_bc978;
        }
      }
      for (iStack_bc958 = 0xb; iStack_bc958 < 0x10; iStack_bc958 = iStack_bc958 + 1) {
        plVar14 = &lStack_bca34;
        puVar15 = &uStack_bc978;
        puVar12 = &uStack_bc980;
        puVar8 = &uStack_bc96c;
        pCVar4 = CArchive::operator>>(param_1,&lStack_bc9d8);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar8);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar12);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar15);
        CArchive::operator>>(pCVar4,plVar14);
        if (DAT_00a0cab0 != 0) {
          *(long *)(iStack_bc954 + 0x2fc4 + iStack_bc958 * 4) = lStack_bc9d8;
          *(uint *)(iStack_bc954 + 0x4e48 + iStack_bc958 * 4) = uStack_bc96c;
          *(uint *)(iStack_bc954 + 0x5058 + iStack_bc958 * 4) = uStack_bc980;
          *(uint *)(iStack_bc954 + 0x4f50 + iStack_bc958 * 4) = uStack_bc978;
          *(long *)(iStack_bc954 + 0x5160 + iStack_bc958 * 4) = lStack_bca34;
        }
      }
      for (iStack_bc958 = 0x10; iStack_bc958 < 0x14; iStack_bc958 = iStack_bc958 + 1) {
        puVar15 = &uStack_bc978;
        puVar12 = &uStack_bc980;
        puVar8 = &uStack_bc96c;
        pCVar4 = CArchive::operator>>(param_1,&lStack_bc9d8);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar8);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar12);
        CArchive::operator>>(pCVar4,(long *)puVar15);
        if (DAT_00a0cab0 != 0) {
          *(long *)(iStack_bc954 + 0x2fc4 + iStack_bc958 * 4) = lStack_bc9d8;
          *(uint *)(iStack_bc954 + 0x4d40 + iStack_bc958 * 4) = uStack_bc96c;
          *(uint *)(iStack_bc954 + 0x5058 + iStack_bc958 * 4) = uStack_bc980;
          *(uint *)(iStack_bc954 + 0x5160 + iStack_bc958 * 4) = uStack_bc978;
        }
      }
      puVar15 = &uStack_bc980;
      pCVar4 = CArchive::operator>>(param_1,(long *)&uStack_bc96c);
      CArchive::operator>>(pCVar4,(long *)puVar15);
      if (DAT_00a0cab0 != 0) {
        *(uint *)(iStack_bc954 + 0x797c) = uStack_bc96c % 10;
        *(uint *)(iStack_bc954 + 0x7980) = uStack_bc980 % 10;
      }
      if (DAT_00a0cab4 != 0) {
        *(undefined4 *)(iStack_bc954 + 0x8220) = 0;
        *(undefined4 *)(iStack_bc954 + 0x8224) = 0;
        *(undefined4 *)(iStack_bc954 + 0x8230) = 0;
        *(undefined4 *)(iStack_bc954 + 0x8234) = 0;
        *(undefined4 *)(iStack_bc954 + 0x8200) = 0;
        *(undefined4 *)(iStack_bc954 + 0x8204) = 0;
        *(undefined4 *)(iStack_bc954 + 0x8208) = 0;
      }
      *(undefined4 *)(iStack_bc954 + 0x8210) = 0;
      *(undefined4 *)(iStack_bc954 + 0x8214) = 0;
      *(undefined4 *)(iStack_bc954 + 0x820c) = 0;
      if (0xd8 < iStack_bc970) {
        puVar15 = &uStack_bc978;
        puVar12 = &uStack_bc980;
        pCVar4 = CArchive::operator>>(param_1,(long *)&uStack_bc96c);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar12);
        CArchive::operator>>(pCVar4,(long *)puVar15);
        if (DAT_00a0cab4 != 0) {
          *(uint *)(iStack_bc954 + 0x8220) = uStack_bc96c % 10;
          uStack_bc96c = uStack_bc96c / 10;
          *(uint *)(iStack_bc954 + 0x8224) = uStack_bc96c % 10;
          *(uint *)(iStack_bc954 + 0x8230) = uStack_bc980 % 10;
          *(uint *)(iStack_bc954 + 0x8234) = uStack_bc978 % 10;
        }
        puVar15 = &uStack_bc978;
        puVar12 = &uStack_bc980;
        pCVar4 = CArchive::operator>>(param_1,(long *)&uStack_bc96c);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar12);
        CArchive::operator>>(pCVar4,(long *)puVar15);
        if (DAT_00a0cab4 != 0) {
          *(int *)(iStack_bc954 + 0x8200) = (int)uStack_bc96c % 10;
          *(int *)(iStack_bc954 + 0x8204) = (int)uStack_bc980 % 10;
          *(int *)(iStack_bc954 + 0x8208) = (int)uStack_bc978 % 10;
        }
        puVar15 = &uStack_bc978;
        puVar12 = &uStack_bc980;
        pCVar4 = CArchive::operator>>(param_1,(long *)&uStack_bc96c);
        pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar12);
        CArchive::operator>>(pCVar4,(long *)puVar15);
        if (DAT_00a0cab4 != 0) {
          *(uint *)(iStack_bc954 + 0x8210) = uStack_bc96c % 10;
          *(uint *)(iStack_bc954 + 0x8214) = uStack_bc980 % 10;
          *(uint *)(iStack_bc954 + 0x820c) = uStack_bc978 % 10;
          if (599 < iStack_bc970) {
            uStack_bc978 = uStack_bc978 % 100;
            if (9 < uStack_bc978) {
              DAT_00a0ca88 = 300;
            }
            if (0x13 < uStack_bc978) {
              DAT_00a0ca88 = 600;
            }
          }
        }
      }
      if (iStack_bc970 < 0xdf) {
        piStack_bc95c[0xe6] = uStack_bca5c;
        piStack_bc95c[0xe7] = iStack_bca58;
        piStack_bc95c[0xe8] = 0;
        piStack_bc95c[0xe9] = 0;
        *(undefined4 *)(iStack_bc954 + 0x82d0) = 0;
        *(undefined4 *)(iStack_bc954 + 0x82d4) = 0;
        *(undefined4 *)(iStack_bc954 + 0x82d8) = 0;
        *(undefined8 *)(iStack_bc954 + 0x82f0) = 0xc046800000000000;
        *(undefined8 *)(iStack_bc954 + 0x8308) = 0xc046800000000000;
        *(undefined8 *)(iStack_bc954 + 0x8318) = 0xc046800000000000;
        *(undefined8 *)(iStack_bc954 + 0x8310) = *(undefined8 *)(iStack_bc954 + 0x8270);
      }
      else {
        CArchive::operator>>(param_1,piStack_bc95c + 0xe8);
        piStack_bc95c[0xe6] = uStack_bca5c - piStack_bc95c[0xe8];
        piStack_bc95c[0xe7] =
             (iStack_bca58 - piStack_bc95c[0xe9]) - (uint)(uStack_bca5c < (uint)piStack_bc95c[0xe8])
        ;
        lStack_bc9c0 = 0;
        lStack_bcad0 = 0;
        lStack_bca78 = 0;
        lStack_bcad8 = 0;
        CArchive::operator>>(param_1,&lStack_bc9c0);
        CArchive::operator>>(param_1,&lStack_bcad0);
        CArchive::operator>>(param_1,&lStack_bca78);
        CArchive::operator>>(param_1,&lStack_bcad8);
        *(int *)(iStack_bc954 + 0x82d0) = lStack_bc9c0 % 10;
        *(int *)(iStack_bc954 + 0x82d4) = (lStack_bc9c0 / 10) % 10;
        lStack_bc9c0 = (lStack_bc9c0 / 10) / 10;
        *(int *)(iStack_bc954 + 0x82d8) = lStack_bc9c0 % 10;
        *(double *)(iStack_bc954 + 0x82f0) = (double)lStack_bcad0 / 100.0;
        *(double *)(iStack_bc954 + 0x8308) = (double)lStack_bca78 / 100.0;
        *(double *)(iStack_bc954 + 0x8318) = (double)lStack_bcad8 / 100.0;
        uStack_bcd78 = 0;
        uStack_bcd90 = 0;
        uStack_bcd98 = 0;
        uStack_bcda0 = 0;
        uStack_bcda8 = 0;
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
        FUN_00420650();
      }
      if (iStack_bc970 < 0xe1) {
        *(undefined8 *)(iStack_bc954 + 0x8368) = 0;
        *(undefined8 *)(iStack_bc954 + 0x8370) = 0;
        *(undefined8 *)(iStack_bc954 + 0x8378) = 0;
        *(undefined8 *)(iStack_bc954 + 0x8380) = 0;
      }
      else {
        uStack_bcc3c = 0;
        uStack_bcc44 = 0;
        uStack_bcbf4 = 0;
        uStack_bcc04 = 0;
        FUN_00420650();
        *(undefined8 *)(iStack_bc954 + 0x8368) = uStack_bcc3c;
        FUN_00420650();
        *(undefined8 *)(iStack_bc954 + 0x8370) = uStack_bcc44;
        FUN_00420650();
        *(undefined8 *)(iStack_bc954 + 0x8378) = uStack_bcbf4;
        FUN_00420650();
        *(undefined8 *)(iStack_bc954 + 0x8380) = uStack_bcc04;
      }
      if (0xe1 < iStack_bc970) {
        CArchive::operator>>(param_1,(long *)&uStack_bc96c);
        *(uint *)(iStack_bc954 + 0x5d90) = uStack_bc96c % 100;
        CArchive::operator>>(param_1,(long *)(iStack_bc954 + 0x5d94));
      }
      if (0x1a3 < iStack_bc970) {
        for (iStack_bc958 = 0; iStack_bc958 < 0x101; iStack_bc958 = iStack_bc958 + 1) {
          iStack_bc964 = iStack_bc958 + 100;
          if (iStack_bc958 < 0x11) {
            puVar15 = &uStack_bc980;
            pCVar4 = CArchive::operator>>(param_1,(long *)&uStack_bc96c);
            CArchive::operator>>(pCVar4,(long *)puVar15);
          }
          else {
            plVar14 = (long *)(iStack_bc954 + 0x5d98 + iStack_bc964 * 4);
            pCVar4 = CArchive::operator>>
                               (param_1,(long *)(iStack_bc954 + 0x5268 + iStack_bc964 * 4));
            CArchive::operator>>(pCVar4,plVar14);
          }
        }
        for (iStack_bc958 = 0; iStack_bc958 < 0x101; iStack_bc958 = iStack_bc958 + 1) {
          iStack_bc964 = iStack_bc958 + 100;
          if (iStack_bc958 < 0x11) {
            puVar15 = &uStack_bc980;
            puVar12 = &uStack_bc96c;
            pCVar4 = (CArchive *)FUN_0047fc90();
            pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar12);
            CArchive::operator>>(pCVar4,(long *)puVar15);
            FUN_00420650();
          }
          else {
            plVar14 = (long *)(iStack_bc954 + 0x632c + iStack_bc964 * 4);
            plVar11 = (long *)(iStack_bc954 + 0x57fc + iStack_bc964 * 4);
            pCVar4 = (CArchive *)FUN_0047fc90();
            pCVar4 = CArchive::operator>>(pCVar4,plVar11);
            CArchive::operator>>(pCVar4,plVar14);
            FUN_00420650();
          }
        }
        for (uStack_bc974 = 1; (int)uStack_bc974 < 0x165; uStack_bc974 = uStack_bc974 + 1) {
          if ((*(uint *)(iStack_bc954 + 0x57fc + uStack_bc974 * 4) & 0xff000000) != 0) {
            *(undefined4 *)(iStack_bc954 + 0x57fc + uStack_bc974 * 4) = 0;
          }
        }
        for (iStack_bc958 = 0; iStack_bc958 < 0x21; iStack_bc958 = iStack_bc958 + 1) {
          iStack_bc964 = iStack_bc958 + 0x1e;
          if (iStack_bc958 < 0x11) {
            plVar14 = &lStack_bca34;
            puVar15 = &uStack_bc978;
            puVar12 = &uStack_bc980;
            pCVar4 = CArchive::operator>>(param_1,(long *)&uStack_bc96c);
            pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar12);
            pCVar4 = CArchive::operator>>(pCVar4,(long *)puVar15);
            CArchive::operator>>(pCVar4,plVar14);
          }
          else {
            plVar14 = (long *)(iStack_bc954 + 0x5160 + iStack_bc964 * 4);
            plVar11 = (long *)(iStack_bc954 + 0x5058 + iStack_bc964 * 4);
            plVar9 = (long *)(iStack_bc954 + 0x4d40 + iStack_bc964 * 4);
            pCVar4 = CArchive::operator>>
                               (param_1,(long *)(iStack_bc954 + 0x2fc4 + iStack_bc964 * 4));
            pCVar4 = CArchive::operator>>(pCVar4,plVar9);
            pCVar4 = CArchive::operator>>(pCVar4,plVar11);
            CArchive::operator>>(pCVar4,plVar14);
          }
        }
        for (iStack_bc958 = 0; iStack_bc958 < 0x21; iStack_bc958 = iStack_bc958 + 1) {
          if (iStack_bc958 < 0x11) {
            puVar15 = &uStack_bc96c;
            pCVar4 = (CArchive *)FUN_0047fc90();
            CArchive::operator>>(pCVar4,(long *)puVar15);
            for (iStack_bc9bc = 1; iStack_bc9bc < 0xb; iStack_bc9bc = iStack_bc9bc + 1) {
              FUN_00420650();
            }
          }
          else {
            plVar14 = (long *)(iStack_bc954 + 0x3754 + iStack_bc958 * 4);
            pCVar4 = (CArchive *)FUN_0047fc90();
            CArchive::operator>>(pCVar4,plVar14);
            for (iStack_bc9bc = 1; iStack_bc9bc < 0xb; iStack_bc9bc = iStack_bc9bc + 1) {
              FUN_00420650();
            }
          }
        }
      }
      if ((iStack_bc988 != 0) && (DAT_00a101a8 == 0)) {
        FUN_004b7740();
      }
    }
    if ((0xd3 < iStack_bc970) && (DAT_00a101a8 == 0)) {
      FUN_005747a0();
    }
    if ((iStack_bc988 != 0) && (DAT_00a101a8 == 0)) {
      *(undefined4 *)(iStack_bc988 + 0x1828) = 0;
      FUN_00515520();
      *(undefined4 *)(iStack_bc988 + 0x8574) = 0x2706;
    }
    if (DAT_00a101a8 == 0) {
      *(undefined4 *)(iStack_bc954 + 0x8440) = 1;
    }
    local_8._0_1_ = 7;
    FUN_00404540();
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_00404540();
    goto LAB_005796b1;
  }
  FUN_00446aa0();
  local_8 = 0;
  piStack_bca90 = (int *)FUN_004d1e10();
  (**(code **)(*piStack_bca90 + 0x10))();
  local_8._0_1_ = 1;
  puStack_bccf4 = &stack0xfff431d8;
  FUN_00403dd0();
  uStack_bccf8 = FUN_0044ef10();
  local_8._0_1_ = 2;
  cVar2 = FUN_00447350();
  if (cVar2 != '\0') {
    FUN_00518ac0();
    local_8._0_1_ = 3;
    FUN_00521d10();
    local_8._0_1_ = 2;
    FUN_004066b0();
    local_8._0_1_ = 1;
    FUN_00404540();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  cVar2 = FUN_00447350();
  if (cVar2 != '\0') {
    FUN_004d1e10();
    FUN_0049c2c0();
    local_8._0_1_ = 4;
    FUN_004a7410();
    local_8._0_1_ = 2;
    FUN_0049cc10();
    local_8._0_1_ = 1;
    FUN_00404540();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  cVar2 = FUN_00447350();
  if ((cVar2 != '\0') || (cVar2 = FUN_00447350(), cVar2 != '\0')) {
    cVar2 = FUN_00447350();
    if (cVar2 == '\0') {
      uStack_bca94 = 2;
    }
    else {
      uStack_bca94 = 1;
    }
    uStack_bcb74 = uStack_bca94;
    FUN_004d1e10();
    FUN_005daa80();
    local_8._0_1_ = 5;
    FUN_005e6670();
    local_8._0_1_ = 2;
    FUN_005db1b0();
    local_8._0_1_ = 1;
    FUN_00404540();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(iStack_bc954 + 0x1754) = 1;
  piStack_bc95c[0xe8] = uStack_bca5c - piStack_bc95c[0xe6];
  piStack_bc95c[0xe9] =
       (iStack_bca58 - piStack_bc95c[0xe7]) - (uint)(uStack_bca5c < (uint)piStack_bc95c[0xe6]);
  FUN_0056ff50();
  FUN_007a6b47();
  cVar2 = FUN_004640c0();
  if (cVar2 != '\0') {
    DAT_00a0b3e8 = 700;
  }
  lStack_bc9d0 = DAT_00a0b3e8;
  CArchive::operator<<(param_1,DAT_00a0b3e8);
  CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
            (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                     (piStack_bc95c + 0xb2));
  CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x2f98));
  CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x24e4));
  for (iStack_bc968 = 0; iStack_bc968 < 0x10; iStack_bc968 = iStack_bc968 + 1) {
    CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x23a4 + iStack_bc968 * 4));
    CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x2464 + iStack_bc968 * 4));
    FUN_00420820();
    CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x29f4 + iStack_bc968 * 4));
    for (iStack_bc97c = 0; iStack_bc97c < 0x10; iStack_bc97c = iStack_bc97c + 1) {
      CArchive::operator<<
                (param_1,*(long *)(iStack_bc954 + 0x17a4 + iStack_bc968 * 0x40 + iStack_bc97c * 4));
      CArchive::operator<<
                (param_1,*(long *)(iStack_bc954 + 0x25f4 + iStack_bc968 * 0x40 + iStack_bc97c * 4));
    }
  }
  FUN_00574a20();
  CArchive::operator<<(param_1,piStack_bc95c[0xce]);
  for (uStack_bc974 = 0; (int)uStack_bc974 < 0xd; uStack_bc974 = uStack_bc974 + 1) {
    CArchive::operator<<(param_1,local_9e54[uStack_bc974]);
  }
  FUN_0057aa90();
  CArchive::operator<<(param_1,piStack_bc95c[0xcf]);
  CArchive::operator<<(param_1,piStack_bc95c[0xd0]);
  CArchive::operator<<(param_1,piStack_bc95c[0xd1]);
  CArchive::operator<<(param_1,piStack_bc95c[0xd2]);
  CArchive::operator<<(param_1,piStack_bc95c[0xd3]);
  CArchive::operator<<(param_1,local_9e54[0x12]);
  lStack_bca1c = DAT_00a0ca78;
  if ((DAT_00a0ca90 != 0) && (lStack_bca1c = -0x65, 599 < lStack_bc9d0)) {
    if (DAT_00a0ca7c == 0) {
LAB_0057581b:
      DAT_00a0ca7c = 100;
    }
    else {
      if (DAT_00a0ca7c < 1) {
        iStack_bca98 = -DAT_00a0ca7c;
      }
      else {
        iStack_bca98 = DAT_00a0ca7c;
      }
      if (100 < iStack_bca98) goto LAB_0057581b;
    }
    iStack_bc9c8 = DAT_00a0ca7c;
    if (DAT_00a0ca7c < 1) {
      if (DAT_00a0ca7c < 1) {
        iStack_bcaa0 = -DAT_00a0ca7c;
      }
      else {
        iStack_bcaa0 = DAT_00a0ca7c;
      }
      lStack_bca1c = -(iStack_bcaa0 + 400);
    }
    else {
      if (DAT_00a0ca7c < 1) {
        iStack_bca9c = -DAT_00a0ca7c;
      }
      else {
        iStack_bca9c = DAT_00a0ca7c;
      }
      lStack_bca1c = -(iStack_bca9c + 200);
    }
  }
  CArchive::operator<<(param_1,lStack_bca1c);
  FUN_00420820();
  FUN_00420820();
  FUN_00420820();
  lStack_bca3c = *(int *)(iStack_bc954 + 0x2fa8);
  if (299 < DAT_00a0b3e8) {
    lStack_bca3c = *(int *)(iStack_bc954 + 0x2fc0) * 10 + lStack_bca3c;
  }
  CArchive::operator<<(param_1,lStack_bca3c);
  iStack_bc9e4 = *(int *)(iStack_bc954 + 0x7984);
  if (*(int *)(iStack_bc954 + 0x798c) != 0) {
    iStack_bc9e4 = iStack_bc9e4 + 10;
  }
  if (*(int *)(iStack_bc954 + 0x7988) != 0) {
    iStack_bc9e4 = -1 - iStack_bc9e4;
  }
  CArchive::operator<<(param_1,iStack_bc9e4);
  FUN_00420820();
  FUN_00420820();
  FUN_00420820();
  FUN_00420820();
  FUN_00420820();
  for (iStack_bc960 = 0; iStack_bc960 < 0x10; iStack_bc960 = iStack_bc960 + 1) {
    for (iStack_bca18 = 0; iStack_bca18 < 0x10; iStack_bca18 = iStack_bca18 + 1) {
      CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                         (iStack_bc954 + 0x2a88 + iStack_bc960 * 0x48 + iStack_bca18 * 4));
    }
  }
  for (iStack_bc960 = 0; iStack_bc960 < 0x10; iStack_bc960 = iStack_bc960 + 1) {
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (iStack_bc954 + 0x2a40 + iStack_bc960 * 4));
  }
  FUN_00420820();
  FUN_00420820();
  CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x8348));
  FUN_00420820();
  if (299 < DAT_00a0b3e8) {
    FUN_00420820();
    FUN_00420820();
  }
  CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x8268));
  FUN_00420820();
  FUN_00420820();
  FUN_00420820();
  FUN_00420820();
  FUN_00420820();
  FUN_00420820();
  if (DAT_00a0b3e8 < 300) {
    for (iStack_bc960 = 1; iStack_bc960 < 5; iStack_bc960 = iStack_bc960 + 1) {
      FUN_00420820();
      FUN_00420820();
      FUN_00420820();
    }
  }
  else {
    for (iStack_bc960 = 1; iStack_bc960 < 9; iStack_bc960 = iStack_bc960 + 1) {
      FUN_00420820();
      FUN_00420820();
      FUN_00420820();
      CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x7b60 + iStack_bc960 * 4));
    }
    uStack_bcc78 = 0;
    uStack_bcc80 = 0;
    uStack_bcc88 = 0;
    uStack_bcc90 = 0;
    uStack_bcc98 = 0;
    uStack_bcc0c = 0;
    lStack_bcb78 = 0;
    iStack_bc9cc = 0;
    FUN_00420820();
    FUN_00420820();
    FUN_00420820();
    CArchive::operator<<(param_1,lStack_bcb78);
    FUN_00420820();
    FUN_00420820();
    uStack_bcc0c = *(undefined8 *)(iStack_bc954 + 0x8248);
    FUN_00420820();
    if (*(int *)(iStack_bc954 + 0x8258) != 0) {
      iStack_bc9cc = iStack_bc9cc + 10;
    }
    iStack_bc9cc = iStack_bc9cc + *(int *)(iStack_bc954 + 0x8240) + 1;
    CArchive::operator<<(param_1,iStack_bc9cc);
  }
  for (iStack_bc960 = 0; iStack_bc960 < 10; iStack_bc960 = iStack_bc960 + 1) {
    FUN_00420820();
  }
  FUN_00420820();
  for (iStack_bc960 = 0; iStack_bc960 < 10; iStack_bc960 = iStack_bc960 + 1) {
    iStack_bc964 = iStack_bc960;
    if (iStack_bc960 == 9) {
      iStack_bc964 = 0xd;
    }
    lVar13 = *(long *)(iStack_bc954 + 0x5d98 + iStack_bc964 * 4);
    pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x5268 + iStack_bc964 * 4));
    CArchive::operator<<(pCVar4,lVar13);
  }
  for (iStack_bc960 = 0; iStack_bc960 < 10; iStack_bc960 = iStack_bc960 + 1) {
    iStack_bc964 = iStack_bc960;
    if (iStack_bc960 == 9) {
      iStack_bc964 = 0xd;
    }
    lVar13 = *(long *)(iStack_bc954 + 0x632c + iStack_bc964 * 4);
    pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x57fc + iStack_bc964 * 4));
    CArchive::operator<<(pCVar4,lVar13);
    FUN_00420820();
  }
  for (iStack_bc960 = 2; iStack_bc960 < 10; iStack_bc960 = iStack_bc960 + 1) {
    lVar13 = *(long *)(iStack_bc954 + 0x5160 + iStack_bc960 * 4);
    lVar10 = *(long *)(iStack_bc954 + 0x5058 + iStack_bc960 * 4);
    lVar7 = *(long *)(iStack_bc954 + 0x4d40 + iStack_bc960 * 4);
    pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x2fc4 + iStack_bc960 * 4));
    pCVar4 = CArchive::operator<<(pCVar4,lVar7);
    pCVar4 = CArchive::operator<<(pCVar4,lVar10);
    CArchive::operator<<(pCVar4,lVar13);
  }
  for (iStack_bc960 = 0xb; iStack_bc960 < 0x10; iStack_bc960 = iStack_bc960 + 1) {
    lVar13 = *(long *)(iStack_bc954 + 0x5160 + iStack_bc960 * 4);
    lVar10 = *(long *)(iStack_bc954 + 0x4f50 + iStack_bc960 * 4);
    lVar7 = *(long *)(iStack_bc954 + 0x5058 + iStack_bc960 * 4);
    lVar6 = *(long *)(iStack_bc954 + 0x4e48 + iStack_bc960 * 4);
    pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x2fc4 + iStack_bc960 * 4));
    pCVar4 = CArchive::operator<<(pCVar4,lVar6);
    pCVar4 = CArchive::operator<<(pCVar4,lVar7);
    pCVar4 = CArchive::operator<<(pCVar4,lVar10);
    CArchive::operator<<(pCVar4,lVar13);
  }
  for (iStack_bc960 = 0x10; iStack_bc960 < 0x14; iStack_bc960 = iStack_bc960 + 1) {
    lVar13 = *(long *)(iStack_bc954 + 0x5160 + iStack_bc960 * 4);
    lVar10 = *(long *)(iStack_bc954 + 0x5058 + iStack_bc960 * 4);
    lVar7 = *(long *)(iStack_bc954 + 0x4d40 + iStack_bc960 * 4);
    pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x2fc4 + iStack_bc960 * 4));
    pCVar4 = CArchive::operator<<(pCVar4,lVar7);
    pCVar4 = CArchive::operator<<(pCVar4,lVar10);
    CArchive::operator<<(pCVar4,lVar13);
  }
  lVar13 = *(long *)(iStack_bc954 + 0x7980);
  pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x797c));
  CArchive::operator<<(pCVar4,lVar13);
  lVar13 = *(long *)(iStack_bc954 + 0x8234);
  lVar10 = *(long *)(iStack_bc954 + 0x8230);
  pCVar4 = CArchive::operator<<
                     (param_1,*(int *)(iStack_bc954 + 0x8224) * 10 + *(int *)(iStack_bc954 + 0x8220)
                     );
  pCVar4 = CArchive::operator<<(pCVar4,lVar10);
  CArchive::operator<<(pCVar4,lVar13);
  lVar13 = *(long *)(iStack_bc954 + 0x8208);
  lVar10 = *(long *)(iStack_bc954 + 0x8204);
  pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x8200));
  pCVar4 = CArchive::operator<<(pCVar4,lVar10);
  CArchive::operator<<(pCVar4,lVar13);
  iStack_bc964 = *(int *)(iStack_bc954 + 0x820c);
  if (599 < lStack_bc9d0) {
    if (DAT_00a0ca88 < 0x12d) {
      iStack_bc964 = iStack_bc964 + 10;
    }
    if (599 < DAT_00a0ca88) {
      iStack_bc964 = iStack_bc964 + 0x14;
    }
  }
  lVar13 = *(long *)(iStack_bc954 + 0x8214);
  iVar3 = iStack_bc964;
  pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x8210));
  pCVar4 = CArchive::operator<<(pCVar4,lVar13);
  CArchive::operator<<(pCVar4,iVar3);
  if (0xde < lStack_bc9d0) {
    CArchive::operator<<(param_1,piStack_bc95c[0xe8]);
    lStack_bcaa8 = 0;
    lStack_bcaac = 0;
    lStack_bcad4 = 0;
    iStack_bcaa4 = *(int *)(iStack_bc954 + 0x82d0) + *(int *)(iStack_bc954 + 0x82d4) * 10 +
                   *(int *)(iStack_bc954 + 0x82d8) * 100;
    lStack_bcaa8 = FUN_008d98b0();
    lStack_bcaac = FUN_008d98b0();
    lStack_bcad4 = FUN_008d98b0();
    CArchive::operator<<(param_1,iStack_bcaa4);
    CArchive::operator<<(param_1,lStack_bcaa8);
    CArchive::operator<<(param_1,lStack_bcaac);
    CArchive::operator<<(param_1,lStack_bcad4);
    FUN_00420820();
    FUN_00420820();
    FUN_00420820();
    FUN_00420820();
    FUN_00420820();
  }
  if (0xe0 < lStack_bc9d0) {
    FUN_00420820();
    FUN_00420820();
    FUN_00420820();
    FUN_00420820();
  }
  if (0xe5 < lStack_bc9d0) {
    CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x5d90));
    CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x5d94));
  }
  if (0x1a3 < lStack_bc9d0) {
    for (iStack_bc960 = 0; iStack_bc960 < 0x101; iStack_bc960 = iStack_bc960 + 1) {
      iStack_bc964 = iStack_bc960 + 100;
      lVar13 = *(long *)(iStack_bc954 + 0x5d98 + iStack_bc964 * 4);
      pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x5268 + iStack_bc964 * 4));
      CArchive::operator<<(pCVar4,lVar13);
    }
    for (iStack_bc960 = 0; iStack_bc960 < 0x101; iStack_bc960 = iStack_bc960 + 1) {
      CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                         (iStack_bc954 + 0x30cc + iStack_bc960 * 4));
      iStack_bc964 = iStack_bc960 + 100;
      lVar13 = *(long *)(iStack_bc954 + 0x632c + iStack_bc964 * 4);
      pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x57fc + iStack_bc964 * 4));
      CArchive::operator<<(pCVar4,lVar13);
      FUN_00420820();
    }
    for (iStack_bc960 = 0; iStack_bc960 < 0x21; iStack_bc960 = iStack_bc960 + 1) {
      iStack_bc964 = iStack_bc960 + 0x1e;
      lVar13 = *(long *)(iStack_bc954 + 0x5160 + iStack_bc964 * 4);
      lVar10 = *(long *)(iStack_bc954 + 0x5058 + iStack_bc964 * 4);
      lVar7 = *(long *)(iStack_bc954 + 0x4d40 + iStack_bc964 * 4);
      pCVar4 = CArchive::operator<<(param_1,*(long *)(iStack_bc954 + 0x2fc4 + iStack_bc964 * 4));
      pCVar4 = CArchive::operator<<(pCVar4,lVar7);
      pCVar4 = CArchive::operator<<(pCVar4,lVar10);
      CArchive::operator<<(pCVar4,lVar13);
    }
    for (iStack_bc960 = 0; iStack_bc960 < 0x21; iStack_bc960 = iStack_bc960 + 1) {
      lVar13 = *(long *)(iStack_bc954 + 0x3754 + iStack_bc960 * 4);
      pCVar4 = CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                         (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                                   *)(iStack_bc954 + 0x3660 + iStack_bc960 * 4));
      CArchive::operator<<(pCVar4,lVar13);
      for (iStack_bca14 = 1; iStack_bca14 < 0xb; iStack_bca14 = iStack_bca14 + 1) {
        FUN_00420820();
      }
    }
  }
  local_8._0_1_ = 1;
  FUN_00404540();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404540();
  local_8 = 0xffffffff;
  FUN_00447100();
LAB_005796b1:
  if (DAT_00a101a8 == 0) {
    FUN_0057a780();
    FUN_004eee80();
    iVar3 = FUN_0042ddc0();
    if (iVar3 != 0) {
      FUN_005707f0();
    }
    (**(code **)(piStack_bc95c[0x39] + 8))();
    iVar3 = FUN_0042ddc0();
    if (iVar3 == 0) {
      FUN_00572880();
    }
    iVar3 = FUN_0042ddc0();
    if (iVar3 == 0) {
      if (0x13 < DAT_00a0b414) {
        (**(code **)(piStack_bc95c[0x40] + 8))();
      }
      FUN_005709a0();
      FUN_00571010();
    }
    else {
      FID_conflict_evaluation_error();
      local_8 = 0x10;
      iStack_bcadc = FUN_0044f260();
      while (iStack_bcadc != 0) {
        piVar5 = (int *)FUN_0044f2b0();
        iStack_bca40 = *piVar5;
        if (iStack_bca40 == 0) break;
        if (*(int *)(iStack_bca40 + 0x6c) == 0) {
          uStack_bcb98 = Left();
          uStack_bc9fc = uStack_bc9fc | 1;
          cVar2 = FUN_00447350();
          if (cVar2 != '\0') goto LAB_0057987c;
          uStack_bca60 = 0;
        }
        else {
LAB_0057987c:
          uStack_bca60 = 1;
        }
        cStack_bc9c4 = (char)uStack_bca60;
        if ((uStack_bc9fc & 1) != 0) {
          uStack_bc9fc = uStack_bc9fc & 0xfffffffe;
          FUN_00404540();
        }
        if (cStack_bc9c4 != '\0') {
          FUN_004142e0();
        }
      }
      CObList::Serialize(aCStack_bcd48,param_1);
      local_8 = 0xffffffff;
      FUN_004997c0();
    }
    iVar3 = FUN_0042ddc0();
    if (iVar3 == 0) {
      iStack_bcb38 = DAT_00a0b414;
      if (0x275 < DAT_00a0b414) {
        CStringT<>();
        local_8 = 0x1b;
        iVar3 = FUN_00571720();
        if (iVar3 != 0) {
          FUN_0078e67f();
          local_8._1_3_ = (uint3)((uint)local_8 >> 8);
          local_8._0_1_ = 0x1d;
          iStack_bca7c = 0;
          CStringT<>();
          local_8 = CONCAT31(local_8._1_3_,0x1e);
          CArchive__operator>>();
          for (iStack_bca30 = 0; iStack_bca30 < iStack_bca7c; iStack_bca30 = iStack_bca30 + 1) {
            FUN_0047fc90();
            CArchive__operator>>();
            uStack_bcb3c = ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::
                           Right(aCStack_bc9b0,(int)auStack_bcb40);
            cStack_bc9c3 = FUN_00481200();
            FUN_00404540();
            if (cStack_bc9c3 == '\0') {
              iStack_bca84 = 0;
              FUN_00404860();
            }
            else {
              iStack_bca84 = 1;
              FUN_00404900();
              ATL::CSimpleStringT<wchar_t,0>::GetAllocLength
                        ((CSimpleStringT<wchar_t,0> *)aCStack_bc9b0);
              uStack_bcb48 = Left();
              local_8._0_1_ = 0x1f;
              uStack_bcb44 = uStack_bcb48;
              FUN_00404860();
              local_8 = CONCAT31(local_8._1_3_,0x1e);
              FUN_00404540();
            }
            uStack_bcd18 = FUN_007a70b2();
            local_8._0_1_ = 0x20;
            puStack_bcd1c = &stack0xfff431d0;
            ATL::operator+((wchar_t *)&stack0xfff431d0,
                           (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                            *)L"%temp%");
            uStack_bcb54 = FUN_004b82c0();
            local_8._0_1_ = 0x21;
            uStack_bcb50 = uStack_bcb54;
            FUN_00404920();
            iStack_bcb60 = FUN_007a7cf7();
            local_8._0_1_ = 0x20;
            iStack_bcb58 = iStack_bcb60;
            FUN_00404540();
            if (iStack_bcb60 == 0) {
              FUN_005168b0();
              local_8 = CONCAT31(local_8._1_3_,0x1e);
              FUN_007a70db();
            }
            else {
              do {
                if (uStack_bca08 < 0x2711) {
                  uStack_bca80 = uStack_bca08;
                }
                else {
                  uStack_bca80 = 10000;
                }
                uStack_bca04 = uStack_bca80;
                uStack_bca08 = uStack_bca08 - 10000;
                uStack_bcb64 = FUN_007a6927();
                FUN_007a811a();
              } while (9999 < uStack_bca04);
              FUN_007a7834();
              if (iStack_bca84 != 0) {
                puStack_bccfc = &stack0xfff431d8;
                puStack_bcb68 = &stack0xfff431d8;
                puStack_bcd20 = &stack0xfff431d4;
                ATL::operator+((wchar_t *)&stack0xfff431d4,
                               (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                *)L"%temp%");
                uStack_bcd24 = FUN_004b82c0();
                local_8._0_1_ = 0x22;
                puStack_bcd28 = &stack0xfff431d4;
                puStack_bcb6c = &stack0xfff431d4;
                puStack_bcd2c = &stack0xfff431d0;
                ATL::operator+((wchar_t *)&stack0xfff431d0,
                               (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                *)L"%temp%");
                uStack_bccec = FUN_004b82c0();
                local_8._0_1_ = 0x20;
                FUN_0045f350();
              }
              local_8 = CONCAT31(local_8._1_3_,0x1e);
              FUN_007a70db();
            }
          }
          local_8 = CONCAT31(local_8._1_3_,0x1d);
          FUN_00404540();
          FUN_0057a6d4();
          return;
        }
        FUN_004f60a0();
        local_8 = 0xffffffff;
        FUN_00404540();
      }
    }
    else {
      iStack_bcba0 = DAT_00a0b3e8;
      if (0x275 < DAT_00a0b3e8) {
        _eh_vector_constructor_iterator_(local_ae78,4,0x3e9,CStringT<>,FUN_00404540);
        local_8 = 0x11;
        iStack_bc990 = 0;
        iStack_bc9f4 = 0;
        FUN_00446aa0();
        local_8 = CONCAT31(local_8._1_3_,0x12);
        iStack_bc9f8 = FUN_00572030();
LAB_005799b7:
        do {
          if (iStack_bc9f8 == 0) {
LAB_00579c1e:
            iStack_bc9f8 = FUN_00572050();
LAB_00579c2f:
            do {
              if ((iStack_bc9f8 == 0) || (iStack_bca10 = FUN_005720a0(), iStack_bca10 == 0)) {
                CArchive__operator<<();
                for (iStack_bc984 = 0; iStack_bc984 < iStack_bc990; iStack_bc984 = iStack_bc984 + 1)
                {
                  CStringT<>();
                  local_8._0_1_ = 0x17;
                  puStack_bcd10 = &stack0xfff431d8;
                  ATL::operator+((wchar_t *)&stack0xfff431d8,
                                 (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                  *)L"%temp%");
                  uStack_bcb14 = FUN_004b82c0();
                  local_8._0_1_ = 0x18;
                  uStack_bcb10 = uStack_bcb14;
                  FUN_00404860();
                  local_8 = CONCAT31(local_8._1_3_,0x17);
                  FUN_00404540();
                  uStack_bcb1c = 0x386277;
                  FUN_00404920();
                  iStack_bcb20 = FUN_0045f290();
                  if (iStack_bcb20 != 0) {
                    FUN_00464110();
                  }
                  CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                            (param_1,local_ae78 + iStack_bc984 * 4);
                  FUN_007a70b2();
                  local_8._0_1_ = 0x19;
                  puStack_bcd14 = &stack0xfff431d0;
                  ATL::operator+((wchar_t *)&stack0xfff431d0,
                                 (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                  *)L"%temp%");
                  uStack_bcb28 = FUN_004b82c0();
                  local_8._0_1_ = 0x1a;
                  uStack_bcb24 = uStack_bcb28;
                  FUN_00404920();
                  iStack_bcb34 = FUN_007a7cf7();
                  local_8._0_1_ = 0x19;
                  iStack_bcb2c = iStack_bcb34;
                  FUN_00404540();
                  if (iStack_bcb34 == 0) {
                    FUN_005168b0();
                    local_8._0_1_ = 0x17;
                    FUN_007a70db();
                    local_8 = CONCAT31(local_8._1_3_,0x12);
                    FUN_00404540();
                  }
                  else {
                    iStack_bca2c = 0;
                    do {
                      uStack_bc9dc = FUN_007a7ef8();
                      iStack_bca2c = iStack_bca2c + uStack_bc9dc;
                    } while (9999 < uStack_bc9dc);
                    CArchive__operator<<();
                    FUN_0048cb10();
                    iStack_bcabc = 0;
                    do {
                      uStack_bc9dc = FUN_007a7ef8();
                      iStack_bcabc = iStack_bcabc + uStack_bc9dc;
                      FUN_007a6b47();
                    } while (9999 < uStack_bc9dc);
                    FUN_007a7834();
                    local_8._0_1_ = 0x17;
                    FUN_007a70db();
                    local_8 = CONCAT31(local_8._1_3_,0x12);
                    FUN_00404540();
                  }
                }
                if ((iStack_bc9f4 != 0) && (*(int *)(DAT_00a0b410 + 0x855c) != 0)) {
                  FUN_005168b0();
                  *(undefined4 *)(DAT_00a0b410 + 0x8ecc) = 1;
                }
                local_8 = CONCAT31(local_8._1_3_,0x11);
                FUN_00447100();
                local_8 = 0xffffffff;
                _eh_vector_destructor_iterator_(local_ae78,4,0x3e9,FUN_00404540);
                ExceptionList = local_10;
                return;
              }
            } while (*(int *)(iStack_bca10 + 0x6c) == 0);
            iStack_bca6c = FUN_0049ac10();
LAB_00579c81:
            do {
              if (iStack_bca6c == 0) goto LAB_00579c2f;
              uStack_bca70 = FUN_0049ac30();
              iVar3 = FUN_0079d98a();
              if (iVar3 != 0) {
                uStack_bcaf8 = uStack_bca70;
                CStringT<>();
                local_8._0_1_ = 0x15;
                uStack_bcbd0 = 0xff;
                uStack_bcbcc = 0xff;
                uStack_bcbc8 = 0xff;
                iVar3 = FUN_0048efe0(auStack_bc9ac,auStack_bcd70,auStack_bce08,auStack_bce00,
                                     auStack_bcdf8);
                if (iVar3 != 0) {
                  uStack_bcafc = Left();
                  cStack_bc9c2 = FUN_00481200();
                  FUN_00404540();
                  if (cStack_bc9c2 == '\0') {
                    iStack_bc9f4 = iStack_bc9f4 + 1;
                  }
                  else {
                    uStack_bcb08 = Mid();
                    local_8._0_1_ = 0x16;
                    uStack_bcb04 = uStack_bcb08;
                    FUN_00404860();
                    local_8._0_1_ = 0x15;
                    FUN_00404540();
                    iStack_bca74 = 0;
                    for (iStack_bc984 = 0; iStack_bc984 <= iStack_bc990;
                        iStack_bc984 = iStack_bc984 + 1) {
                      cVar2 = FUN_00414010();
                      if (cVar2 != '\0') {
                        iStack_bca74 = 1;
                        break;
                      }
                    }
                    if (iStack_bca74 != 0) {
                      local_8 = CONCAT31(local_8._1_3_,0x12);
                      FUN_00404540();
                      goto LAB_00579c81;
                    }
                    FUN_00404860();
                    iStack_bc990 = iStack_bc990 + 1;
                    if (999 < iStack_bc990) {
                      FUN_004f60a0();
                      local_8 = CONCAT31(local_8._1_3_,0x12);
                      FUN_00404540();
                      goto LAB_00579c2f;
                    }
                  }
                }
                local_8 = CONCAT31(local_8._1_3_,0x12);
                FUN_00404540();
              }
            } while( true );
          }
          uStack_bca64 = FUN_00572100();
          iVar3 = FUN_0079d98a();
        } while (iVar3 == 0);
        uStack_bcbb0 = uStack_bca64;
        CStringT<>();
        local_8._0_1_ = 0x13;
        uStack_bcbac = 0xff;
        uStack_bcba8 = 0xff;
        uStack_bcba4 = 0xff;
        iVar3 = FUN_0048efe0(auStack_bc9a8,auStack_bcde0,auStack_bcdd8,auStack_bcdd0,auStack_bcdc0);
        if (iVar3 != 0) {
          uStack_bcbb4 = Left();
          cStack_bc9c1 = FUN_00481200();
          FUN_00404540();
          if (cStack_bc9c1 == '\0') {
            iStack_bc9f4 = iStack_bc9f4 + 1;
          }
          else {
            uStack_bcbc0 = Mid();
            local_8._0_1_ = 0x14;
            uStack_bcbbc = uStack_bcbc0;
            FUN_00404860();
            local_8._0_1_ = 0x13;
            FUN_00404540();
            iStack_bca68 = 0;
            for (iStack_bc984 = 0; iStack_bc984 <= iStack_bc990; iStack_bc984 = iStack_bc984 + 1) {
              cVar2 = FUN_00414010();
              if (cVar2 != '\0') {
                iStack_bca68 = 1;
                break;
              }
            }
            if (iStack_bca68 != 0) {
              local_8 = CONCAT31(local_8._1_3_,0x12);
              FUN_00404540();
              goto LAB_005799b7;
            }
            FUN_00404860();
            iStack_bc990 = iStack_bc990 + 1;
            if (999 < iStack_bc990) {
              FUN_004f60a0();
              local_8 = CONCAT31(local_8._1_3_,0x12);
              FUN_00404540();
              goto LAB_00579c1e;
            }
          }
        }
        local_8 = CONCAT31(local_8._1_3_,0x12);
        FUN_00404540();
        goto LAB_005799b7;
      }
    }
  }
  else {
    FUN_0057a780();
    FUN_004eee80();
    iStack_bca00 = FUN_0040c0e0();
    (**(code **)(*(int *)(iStack_bca00 + 0x1e4) + 8))();
    if (0x13 < DAT_00a0b414) {
      (**(code **)(*(int *)(iStack_bca00 + 0x238) + 8))();
    }
    FUN_00570ad0();
  }
  ExceptionList = local_10;
  return;
}



