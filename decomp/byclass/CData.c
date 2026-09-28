/* CData -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CData[1] */
/* 00420a30  FUN_00420a30  65 bytes, 0 callers */

undefined4 FUN_00420a30(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041fd30();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x68);
    }
  }
  return in_ECX;
}




/* vtable slots: CData[19], CData3DEnko[19], CData3DSen[19], CData3DSolid[19], CDataBlock[19], CDataEnko[19], CDataList[19], CDataMoji[19], CDataSen[19], CDataSolid[19], CDataSunpou[19], CDataTen[19] */
/* 00420c80  FUN_00420c80  55 bytes, 1 callers */

void FUN_00420c80(double param_1)

{
  int in_ECX;
  
  *(double *)(in_ECX + 8) = *(double *)(in_ECX + 8) + param_1;
  *(double *)(in_ECX + 0x18) = *(double *)(in_ECX + 0x18) + param_1;
  return;
}




/* vtable slots: CData[20], CData3DEnko[20], CData3DSen[20], CData3DSolid[20], CDataBlock[20], CDataEnko[20], CDataList[20], CDataMoji[20], CDataSen[20], CDataSolid[20], CDataSunpou[20], CDataTen[20] */
/* 00420cc0  FUN_00420cc0  55 bytes, 1 callers */

void FUN_00420cc0(double param_1)

{
  int in_ECX;
  
  *(double *)(in_ECX + 0x10) = *(double *)(in_ECX + 0x10) + param_1;
  *(double *)(in_ECX + 0x20) = *(double *)(in_ECX + 0x20) + param_1;
  return;
}




/* vtable slots: CData[18], CData3DEnko[18], CData3DSen[18], CData3DSolid[18], CDataEnko[18], CDataMoji[18], CDataSen[18], CDataSolid[18], CDataSunpou[18], CDataTen[18], CMFCColorPropertySheet[93], CMFCToolBarsCustomizeDialog[93], CMyPropertySheet[93], CPropertySheet[93], CSunpouZukeiKa[14], CZukei[14], CZukei25D[14], CZukei2Sen[14], CZukeiBunkatsu[14], CZukeiChuushinSen[14], CZukeiCorner[14], CZukeiEnko[14], CZukeiFukusen[14], CZukeiFukusha[14], CZukeiGazou[14], CZukeiHachi[14], CZukeiHenkou[14], CZukeiHikage[14], CZukeiHikaku[14], CZukeiHouraku[14], CZukeiKage1[14], CZukeiKage2[14], CZukeiKage3[14], CZukeiKigouHenkei[14], CZukeiKijunten[14], CZukeiKyokuSen[14], CZukeiKyori[14], CZukeiMoji[14], CZukeiObject[14], CZukeiParametric[14], CZukeiPrintHanni[14], CZukeiRenzokuSen[14], CZukeiRitsumen[14], CZukeiSeiri[14], CZukeiSen[14], CZukeiSentaku[14], CZukeiSessen[14], CZukeiSetuDaEn[14], CZukeiSetuEn[14], CZukeiShinshuku[14], CZukeiSunpo[14], CZukeiTakakukei[14], CZukeiTategu[14], CZukeiTen[14], CZukeiTenkuu[14], CZukeiTourokuZukei[14], CZukeiZahyouFile[14], CZukeiZukeiToroku[14] */
/* 00420d00  FUN_00420d00  15 bytes, 1 callers */

undefined4 FUN_00420d00(void)

{
  return 0;
}




/* vtable slots: CData[14], CDataBlock[14], CDataList[14], CJw_winView[102], CSunpouZukeiKa[53], CZukeiCorner[53], CZukeiFukusen[53], CZukeiFukusha[53], CZukeiGaibuHenkei[53], CZukeiGazou[53], CZukeiHachi[53], CZukeiHenkou[53], CZukeiHouraku[53], CZukeiJwmKeisan[53], CZukeiKeisan[53], CZukeiMoji[53], CZukeiParametric[53], CZukeiSeiri[53], CZukeiSentaku[53], CZukeiShinshuku[53], CZukeiShoukyo[53], CZukeiSokutei[53], CZukeiTourokuZukei[53], CZukeiZahyouFile[53], CZukeiZukeiToroku[53] */
/* 00421030  FUN_00421030  13 bytes, 0 callers */

void FUN_00421030(void)

{
  return;
}




/* vtable slots: CData[15] */
/* 00424ed0  FUN_00424ed0  690 bytes, 9 callers */

undefined4 FUN_00424ed0(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint local_c;
  
  iVar3 = FUN_0042dc90();
  if ((((iVar3 != 0) || (*(int *)(DAT_00a0b410 + 0x8558) != 0)) || (*(int *)(param_2 + 0x8218) != 0)
      ) && (iVar3 = FUN_0042b020(), iVar3 == 9)) {
    return 0;
  }
  if (param_3 == 0) goto LAB_0042517a;
  uVar1 = *(undefined4 *)(param_3 + 0x62fc);
  iVar3 = FUN_004b7540();
  if (((iVar3 != 0) && (iVar3 = FUN_0042b720(param_2), iVar3 != 0)) &&
     ((*(byte *)(in_ECX + 0x61) & 0x40) != 0)) {
    *(undefined4 *)(param_3 + 0x62fc) = 1;
  }
  iVar3 = param_2;
  uVar4 = FUN_0042b020(param_2);
  FUN_00456e10(param_1,uVar4,iVar3);
  if (*(int *)(param_3 + 0x62fc) != 0) {
    iVar3 = FUN_0042dc90();
    if ((iVar3 == 0) && (*(int *)(DAT_00a0b410 + 0x8558) == 0)) {
      if (0 < DAT_00a0b444) {
        DAT_00a0b440 = DAT_00a0b444;
        *(undefined4 *)(param_3 + 0x62fc) = uVar1;
        goto LAB_0042517a;
      }
    }
    else if (0 < DAT_00a0b448) {
      DAT_00a0b440 = DAT_00a0b448;
      *(undefined4 *)(param_3 + 0x62fc) = uVar1;
      goto LAB_0042517a;
    }
  }
  *(undefined4 *)(param_3 + 0x62fc) = uVar1;
  iVar3 = FUN_0042dc90();
  if ((((iVar3 != 0) || (*(int *)(DAT_00a0b410 + 0x8558) != 0)) || (DAT_00a0c784 != 0)) ||
     (DAT_00a0ca6c != 0)) {
    local_c = *(uint *)(param_2 + 0x632c + (uint)*(ushort *)(in_ECX + 0x2a) * 4);
    if ((*(short *)(in_ECX + 0x2c) != 0) &&
       ((DAT_00a0ca90 == 1 || (100 < *(ushort *)(in_ECX + 0x2a))))) {
      local_c = (uint)*(ushort *)(in_ECX + 0x2c);
    }
    iVar3 = FUN_0042dc90();
    if ((iVar3 == 0) && (*(int *)(DAT_00a0b410 + 0x8558) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      DAT_00a0b440 = FUN_00463390(param_1,param_2,*(undefined2 *)(in_ECX + 0x2a),local_c,
                                  DAT_00a0ca98 != 0,DAT_00a0ca98 != 0);
    }
    else if (DAT_00a0c784 == 1) {
      if (DAT_00a0ca98 == 0) {
        if (100 < *(ushort *)(in_ECX + 0x2a)) {
          DAT_00a0b440 = 1;
        }
      }
      else {
        DAT_00a0b440 = FUN_00463390(param_1,param_2,*(undefined2 *)(in_ECX + 0x2a),local_c,1,1);
      }
    }
    else if (DAT_00a0ca6c != 0) {
      DAT_00a0b440 = FUN_00463390(param_1,param_2,*(undefined2 *)(in_ECX + 0x2a),local_c,1,1);
    }
  }
LAB_0042517a:
  *(undefined1 *)(in_ECX + 0x61) = 0;
  return 1;
}




/* vtable slots: CData[23], CDataBlock[23], CDataList[23] */
/* 00429c10  FUN_00429c10  133 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_00429c10(undefined4 *param_1)

{
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_00429d40();
  FUN_0041f0a0(local_30,local_28,0);
  *param_1 = local_20;
  param_1[1] = local_1c;
  param_1[2] = local_18;
  param_1[3] = local_14;
  param_1[4] = local_10;
  param_1[5] = local_c;
  return param_1;
}




/* vtable slots: CData[22], CDataList[22], CDataMoji[22] */
/* 00429d40  FUN_00429d40  200 bytes, 2 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_00429d40(undefined4 *param_1)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_00408a30(0,0);
  FUN_00498ac0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
               *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
  FUN_00498ac0(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
               *(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24));
  FUN_00498bf0(0x4000000000000000);
  *param_1 = local_18;
  param_1[1] = local_14;
  param_1[2] = local_10;
  param_1[3] = local_c;
  return param_1;
}




/* vtable slots: CData[11], CDataBlock[11], CDataList[11], CDataMoji[11], CDataSen[11], CDataTen[11] */
/* 0042a1a0  FUN_0042a1a0  130 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

double * FUN_0042a1a0(double *param_1)

{
  double dVar1;
  double dVar2;
  int in_ECX;
  
  FUN_00408a60();
  dVar1 = *(double *)(in_ECX + 0x10);
  dVar2 = *(double *)(in_ECX + 0x20);
  *param_1 = (*(double *)(in_ECX + 8) + *(double *)(in_ECX + 0x18)) / 2.0;
  param_1[1] = (dVar1 + dVar2) / 2.0;
  return param_1;
}




/* vtable slots: CData[0] */
/* 0042b090  FUN_0042b090  16 bytes, 0 callers */

undefined ** FUN_0042b090(void)

{
  return &PTR_s_CData_009fe008;
}




/* vtable slots: CData[12], CDataBlock[12], CDataList[12], CDataMoji[12], CDataSen[12], CDataSolid[12] */
/* 0042b0f0  FUN_0042b0f0  412 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
FUN_0042b0f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int in_ECX;
  float10 fVar1;
  float10 fVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009216e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  fVar1 = (float10)FUN_0043acd0(param_2,param_3,param_4,param_5,*(undefined4 *)(in_ECX + 8),
                                *(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),
                                *(undefined4 *)(in_ECX + 0x14));
  fVar2 = (float10)FUN_0043acd0(param_2,param_3,param_4,param_5,*(undefined4 *)(in_ECX + 0x18),
                                *(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 0x20),
                                *(undefined4 *)(in_ECX + 0x24));
  if ((double)fVar2 <= (double)fVar1) {
    *param_1 = *(undefined4 *)(in_ECX + 0x18);
    param_1[1] = *(undefined4 *)(in_ECX + 0x1c);
    param_1[2] = *(undefined4 *)(in_ECX + 0x20);
    param_1[3] = *(undefined4 *)(in_ECX + 0x24);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    *param_1 = *(undefined4 *)(in_ECX + 8);
    param_1[1] = *(undefined4 *)(in_ECX + 0xc);
    param_1[2] = *(undefined4 *)(in_ECX + 0x10);
    param_1[3] = *(undefined4 *)(in_ECX + 0x14);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return param_1;
}




/* vtable slots: CData[16], CData[17], CDataBlock[17], CDataList[17], CZukei[12], CZukei[13], CZukei25D[13], CZukeiChuushinSen[13], CZukeiEnko[12], CZukeiEnko[13], CZukeiHikage[13], CZukeiHikaku[9], CZukeiHikaku[11], CZukeiHikaku[12], CZukeiHikaku[13], CZukeiKage1[12], CZukeiKage1[13], CZukeiKage2[12], CZukeiKage2[13], CZukeiKage3[12], CZukeiKage3[13], CZukeiKijunten[12], CZukeiKijunten[13], CZukeiKyokuSen[13], CZukeiKyori[12], CZukeiKyori[13], CZukeiObject[12], CZukeiObject[13], CZukeiPrintHanni[12], CZukeiPrintHanni[13], CZukeiRitsumen[12], CZukeiRitsumen[13], CZukeiSessen[12], CZukeiSessen[13], CZukeiSetuDaEn[12], CZukeiSetuDaEn[13], CZukeiSetuEn[12], CZukeiSetuEn[13], CZukeiTakakukei[12], CZukeiTakakukei[13], CZukeiTategu[12], CZukeiTategu[13], CZukeiTen[12], CZukeiTen[13], CZukeiTenkuu[13] */
/* 0042b7c0  FUN_0042b7c0  15 bytes, 1 callers */

undefined4 FUN_0042b7c0(void)

{
  return 0;
}




/* vtable slots: CData[5], CJw_winApp[60], CJw_winApp[61], CSunpouZukeiKa[15], CWinApp[60], CWinApp[61], CZukei[15], CZukei[23], CZukei25D[15], CZukei25D[23], CZukei2Sen[15], CZukeiAuto[15], CZukeiBunkatsu[15], CZukeiBunkatsu[23], CZukeiChuushinSen[15], CZukeiChuushinSen[23], CZukeiGaibuHenkei[15], CZukeiGazou[15], CZukeiHenkou[15], CZukeiHenkou[16], CZukeiHikage[15], CZukeiHikage[23], CZukeiHikaku[15], CZukeiHikaku[23], CZukeiHouraku[15], CZukeiJwmKeisan[15], CZukeiKage1[15], CZukeiKage1[23], CZukeiKage2[23], CZukeiKage3[15], CZukeiKage3[23], CZukeiKeisan[15], CZukeiKijunten[15], CZukeiKijunten[23], CZukeiKyokuSen[15], CZukeiKyokuSen[23], CZukeiKyori[23], CZukeiObject[15], CZukeiObject[23], CZukeiPrintHanni[15], CZukeiPrintHanni[23], CZukeiRenzokuSen[15], CZukeiSeiri[15], CZukeiSentaku[15], CZukeiSessen[15], CZukeiSessen[23], CZukeiSetuDaEn[15], CZukeiSetuDaEn[23], CZukeiSetuEn[15], CZukeiSetuEn[23], CZukeiSokutei[15], CZukeiTen[15], CZukeiTen[23], CZukeiTenkuu[15], CZukeiTenkuu[23], CZukeiZukeiToroku[15], std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[13], std::std::_W::_WU?$char_traits::?$basic_streambuf[13] */
/* 0042ddf0  FUN_0042ddf0  13 bytes, 2 callers */

undefined4 FUN_0042ddf0(void)

{
  return 0;
}




/* vtable slots: CData[2] */
/* 0042e690  FUN_0042e690  345 bytes, 11 callers */

void FUN_0042e690(CArchive *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0042ddc0();
  iVar2 = DAT_00a0b414;
  if (iVar1 == 0) {
    if (0x13 < DAT_00a0b414) {
      CArchive::operator>>(param_1,(long *)(in_ECX + 4));
    }
    CArchive::operator>>(param_1,(uchar *)(in_ECX + 0x28));
    CArchive::operator>>(param_1,(ushort *)(in_ECX + 0x2a));
    if (0x15e < iVar2) {
      CArchive::operator>>(param_1,(ushort *)(in_ECX + 0x2c));
    }
    CArchive::operator>>(param_1,(ushort *)(in_ECX + 0x2e));
    CArchive::operator>>(param_1,(ushort *)(in_ECX + 0x2f));
    if (0x13 < iVar2) {
      CArchive::operator>>(param_1,(ushort *)(in_ECX + 0x44));
      iVar2 = FUN_00429b90(L"$EDTBLK",0);
      if (iVar2 == -1) {
        *(ushort *)(in_ECX + 0x44) = *(ushort *)(in_ECX + 0x44) & 0xfffe;
      }
    }
  }
  else {
    CArchive::operator<<(param_1,*(long *)(in_ECX + 4));
    CArchive::operator<<(param_1,*(uchar *)(in_ECX + 0x28));
    CArchive::operator<<(param_1,*(ushort *)(in_ECX + 0x2a));
    if (0x15e < DAT_00a0b3e8) {
      CArchive::operator<<(param_1,*(ushort *)(in_ECX + 0x2c));
    }
    CArchive::operator<<(param_1,(ushort)*(byte *)(in_ECX + 0x2e));
    CArchive::operator<<(param_1,(ushort)*(byte *)(in_ECX + 0x2f));
    CArchive::operator<<(param_1,*(ushort *)(in_ECX + 0x44));
  }
  return;
}




/* vtable slots: CData[9], CData3DEnko[9], CData3DSen[9], CData3DSolid[9], CDataBlock[9], CDataEnko[9], CDataList[9], CDataMoji[9], CDataSen[9], CDataSolid[9], CDataTen[9] */
/* 0042f660  FUN_0042f660  24 bytes, 15 callers */

void FUN_0042f660(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x2a) = param_1;
  return;
}




/* vtable slots: CData[8], CData3DEnko[8], CData3DSen[8], CData3DSolid[8], CDataBlock[8], CDataEnko[8], CDataList[8], CDataMoji[8], CDataSen[8], CDataSolid[8], CDataTen[8] */
/* 0042f6b0  FUN_0042f6b0  53 bytes, 24 callers */

void FUN_0042f6b0(byte param_1)

{
  int in_ECX;
  undefined1 local_c;
  
  if ((*(byte *)(in_ECX + 0x28) & 0x40) == 0) {
    local_c = param_1;
  }
  else {
    local_c = param_1 | 0x40;
  }
  *(byte *)(in_ECX + 0x28) = local_c;
  return;
}




/* vtable slots: CData[6] */
/* 0042f720  FUN_0042f720  230 bytes, 9 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042f720(int param_1)

{
  int in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined1 *)(param_1 + 0x28) = *(undefined1 *)(in_ECX + 0x28);
  *(undefined2 *)(param_1 + 0x2c) = *(undefined2 *)(in_ECX + 0x2c);
  *(undefined2 *)(param_1 + 0x2a) = *(undefined2 *)(in_ECX + 0x2a);
  *(undefined1 *)(param_1 + 0x2e) = *(undefined1 *)(in_ECX + 0x2e);
  *(undefined1 *)(param_1 + 0x2f) = *(undefined1 *)(in_ECX + 0x2f);
  FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 0x30),*(undefined4 *)(in_ECX + 0x34),
               *(undefined4 *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x3c));
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(in_ECX + 0x40);
  *(undefined2 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 0x5b) = 0;
  *(undefined1 *)(param_1 + 0x5c) = 0;
  *(undefined1 *)(param_1 + 0x5d) = 0;
  *(undefined1 *)(param_1 + 0x5e) = 0;
  *(undefined1 *)(param_1 + 0x5f) = 0;
  *(undefined1 *)(param_1 + 0x61) = 0;
  *(ushort *)(param_1 + 0x44) = *(ushort *)(in_ECX + 0x44) & 0xfff1;
  return;
}




/* vtable slots: CData[21], CData3DSen[21], CData3DSolid[21], CDataBlock[21], CDataList[21], CDataMoji[21], CDataSen[21], CDataSolid[21], CDataSunpou[21], CDataTen[21] */
/* 00433d30  FUN_00433d30  97 bytes, 1 callers */

void FUN_00433d30(double param_1)

{
  int in_ECX;
  
  *(double *)(in_ECX + 8) = *(double *)(in_ECX + 8) * param_1;
  *(double *)(in_ECX + 0x18) = *(double *)(in_ECX + 0x18) * param_1;
  *(double *)(in_ECX + 0x10) = *(double *)(in_ECX + 0x10) * param_1;
  *(double *)(in_ECX + 0x20) = *(double *)(in_ECX + 0x20) * param_1;
  return;
}




/* vtable slots: CData[7] */
/* 00438910  FUN_00438910  106 bytes, 10 callers */

undefined4 FUN_00438910(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) == *(char *)(param_1 + 0x28)) {
    if (*(short *)(in_ECX + 0x2a) == *(short *)(param_1 + 0x2a)) {
      if (*(char *)(in_ECX + 0x2e) == *(char *)(param_1 + 0x2e)) {
        if (*(char *)(in_ECX + 0x2f) == *(char *)(param_1 + 0x2f)) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
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




/* vtable slots: CData[13], CDataBlock[13], CDataList[13], CDataMoji[13], CDataSen[13], CDataSolid[13] */
/* 0043ae00  FUN_0043ae00  315 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0043ae00(double *param_1,double *param_2)

{
  int in_ECX;
  double local_3c;
  double local_34;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
               *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
  FUN_004988c0(local_28,*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
               *(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24));
  if (*param_2 - *param_1 <= 0.0) {
    local_34 = -(*param_2 - *param_1);
  }
  else {
    local_34 = *param_2 - *param_1;
  }
  if (local_34 <= 1e-07) {
    if (param_2[1] - param_1[1] <= 0.0) {
      local_3c = -(param_2[1] - param_1[1]);
    }
    else {
      local_3c = param_2[1] - param_1[1];
    }
    if (local_3c <= 1e-07) {
      return 1;
    }
  }
  return 2;
}




/* vtable slots: CData[10], CData3DEnko[10], CData3DSen[10], CData3DSolid[10], CDataBlock[10], CDataEnko[10], CDataMoji[10], CDataSen[10], CDataSolid[10], CDataSunpou[10], CDataTen[10] */
/* 0043b440  FUN_0043b440  18 bytes, 1 callers */

undefined1 FUN_0043b440(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x2f);
}



