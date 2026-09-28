/* CJw_winDoc -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CJw_winDoc[1] */
/* 004d1940  FUN_004d1940  68 bytes, 0 callers */

undefined4 FUN_004d1940(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004d17a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1dd8);
    }
  }
  return in_ECX;
}




/* vtable slots: CJw_winDoc[29] */
/* 004d1bc0  FUN_004d1bc0  258 bytes, 0 callers */

void FUN_004d1bc0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_00404c80();
  if (iVar1 != 0) {
    uVar5 = 0;
    uVar4 = 0x80e1;
    uVar3 = 0x111;
    FUN_00404c80(0x111,0x80e1,0);
    FUN_00406bc0(uVar3,uVar4,uVar5);
  }
  FUN_00571b50();
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  RemoveAll();
  FUN_00454510();
  while (iVar1 = FUN_004146c0(), iVar1 == 0) {
    piVar2 = (int *)FUN_00414c00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  RemoveAll();
  FUN_00454510();
  guard_check_icall();
  return;
}




/* vtable slots: CJw_winDoc[20], CMiniDoc[20] */
/* 004d1d10  FUN_004d1d10  149 bytes, 0 callers */

undefined4 FUN_004d1d10(void)

{
  CDocumentAdapter *this;
  undefined4 uVar1;
  CDocument *in_ECX;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927744;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x98) == 0) {
    local_8 = 0;
    this = (CDocumentAdapter *)FUN_0078e624(0xc);
    local_8._0_1_ = 1;
    if (this == (CDocumentAdapter *)0x0) {
      local_20 = 0;
    }
    else {
      local_20 = CDocument::CDocumentAdapter::CDocumentAdapter(this,in_ECX);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    *(undefined4 *)(in_ECX + 0x98) = local_20;
    uVar1 = FUN_004d1db3();
    return uVar1;
  }
  if (*(int *)(in_ECX + 0x98) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x98) + 4))();
  }
  ExceptionList = local_10;
  return *(undefined4 *)(in_ECX + 0x98);
}




/* vtable slots: CJw_winDoc[10] */
/* 004d1e30  FUN_004d1e30  16 bytes, 0 callers */

void FUN_004d1e30(void)

{
  FUN_004d1e80();
  return;
}




/* vtable slots: CJw_winDoc[0] */
/* 004d1e70  FUN_004d1e70  16 bytes, 0 callers */

undefined ** FUN_004d1e70(void)

{
  return &PTR_s_CJw_winDoc_009ffb9c;
}




/* vtable slots: CJw_winDoc[24], CMiniDoc[24] */
/* 004d1ff0  FUN_004d1ff0  17 bytes, 0 callers */

undefined4 FUN_004d1ff0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x48);
}




/* vtable slots: CJw_winDoc[30] */
/* 004d20c0  FUN_004d20c0  1376 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004d20c0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_6ec;
  undefined4 local_6e8;
  int local_6e0;
  int local_6dc;
  undefined1 local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092778b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_007a9f42(local_14);
  iVar1 = DAT_00a0b410;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    DAT_00a0eef0 = 0;
    puVar4 = (undefined4 *)FUN_00408a30(0,0);
    FUN_004988c0(local_34,*puVar4,puVar4[1],puVar4[2],puVar4[3]);
    *(undefined8 *)(iVar1 + 0x17b0) = 0x3ff0000000000000;
    *(undefined4 *)(in_ECX + 0x170) = 0;
    FUN_004948d0();
    iVar2 = FUN_0040c0e0();
    *(undefined4 *)(iVar2 + 0x398) = local_6ec;
    *(undefined4 *)(iVar2 + 0x39c) = local_6e8;
    FUN_00404900();
    FUN_00404900();
    for (local_6dc = 0; local_6dc < 0x10; local_6dc = local_6dc + 1) {
      *(undefined4 *)(in_ECX + 0xee0 + local_6dc * 4) = 0;
      *(undefined4 *)(in_ECX + 0xea0 + local_6dc * 4) = 0;
      *(undefined4 *)(iVar1 + 0x2a7c + local_6dc * 4) = 0;
      for (local_6e0 = 0; local_6e0 < 0x10; local_6e0 = local_6e0 + 1) {
        *(undefined4 *)(in_ECX + 0x1320 + local_6dc * 0x40 + local_6e0 * 4) = 0;
        *(undefined4 *)(in_ECX + 0xf20 + local_6dc * 0x40 + local_6e0 * 4) = 0;
        *(undefined4 *)(iVar1 + 0x267c + local_6dc * 0x40 + local_6e0 * 4) = 0;
      }
    }
    FUN_004dec90();
    FUN_004dec50();
    FUN_00404900();
    *(undefined4 *)(iVar1 + 0x2ac4) = 0;
    *(undefined4 *)(iVar1 + 0x8298) = 0;
    *(undefined4 *)(iVar1 + 0x829c) = 0;
    *(undefined4 *)(iVar1 + 0x8294) = 0;
    *(undefined4 *)(iVar1 + 0x1828) = 0;
    if ((DAT_00a0b3f8 != 0) && (DAT_00a0b3f4 == 1)) {
      FUN_00404900();
      for (local_6dc = 0; local_6dc < 0x10; local_6dc = local_6dc + 1) {
        *(undefined4 *)(iVar1 + 0x242c + local_6dc * 4) = 2;
        FUN_00404900();
        for (local_6e0 = 0; local_6e0 < 0x10; local_6e0 = local_6e0 + 1) {
          *(undefined4 *)(iVar1 + 0x182c + local_6dc * 0x40 + local_6e0 * 4) = 2;
          FUN_00404900();
        }
        *(undefined4 *)(iVar1 + 0x182c + local_6dc * 0x40) = 3;
        *(undefined4 *)(iVar1 + 0x24ec + local_6dc * 4) = 0;
      }
      *(undefined4 *)(iVar1 + 0x242c) = 3;
      *(undefined4 *)(iVar1 + 0x256c) = 0;
      FUN_004ea430();
      FUN_004b8cf0();
      FUN_00525de0();
      local_8 = 0;
      FUN_00529070();
      local_8 = 0xffffffff;
      FUN_00525eb0();
    }
    if (DAT_00a0b3f4 == 0) {
      DAT_00a0b3f4 = 1;
      FUN_004ea430();
      FUN_004b8cf0();
      FUN_00525de0();
      local_8 = 1;
      FUN_00529070();
      local_8 = 0xffffffff;
      FUN_00525eb0();
    }
    FUN_0044fc20();
    *(undefined4 *)(iVar1 + 0x17dc) = 0;
    *(undefined4 *)(iVar1 + 0x84c8) = 1;
    *(undefined4 *)(iVar1 + 0x8574) = 999;
    *(undefined4 *)(iVar1 + 0x8358) = 0;
    *(undefined4 *)(iVar1 + 0x835c) = 0;
    *(undefined4 *)(iVar1 + 0x8360) = 0;
    uVar3 = 1;
  }
  ExceptionList = local_10;
  return uVar3;
}




/* vtable slots: CJw_winDoc[2] */
/* 004d2820  FUN_004d2820  1598 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x004d2cfb) */

void FUN_004d2820(void)

{
  char cVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  uint uStack_6a38;
  undefined4 local_6984;
  undefined4 local_6980;
  int local_697c;
  int local_6978;
  int local_6974;
  int local_6970;
  int local_696c;
  int local_6968;
  undefined1 local_6964 [4];
  undefined4 local_6960;
  CSimpleStringT<wchar_t,0> local_695c [4];
  CSimpleStringT<wchar_t,0> local_6958 [4];
  int local_6954;
  int local_6950;
  int *local_694c;
  undefined1 local_6948 [4];
  int local_6944;
  int local_6940;
  int local_693c;
  wchar_t local_218 [256];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927833;
  local_10 = ExceptionList;
  uStack_6a38 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_6a38;
  ExceptionList = &local_10;
  local_18 = uStack_6a38;
  FUN_0078e67f();
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_00446aa0();
  local_8._0_1_ = 2;
  FUN_004fb9f0();
  iVar2 = FUN_0042ddc0();
  if (iVar2 == 0) {
    if (DAT_00a0b3f4 == 0) {
      DAT_00a0b3f4 = 1;
      FUN_004dec90();
      FUN_004ea430();
      FUN_004b8cf0();
      FUN_00525de0();
      local_8._0_1_ = 4;
      FUN_00529070();
      local_8._0_1_ = 2;
      FUN_00525eb0();
    }
    FUN_004dec50();
  }
  else {
    FUN_00464040();
    local_8._0_1_ = 3;
    FUN_00464180();
    local_8._0_1_ = 2;
    FUN_004640a0();
  }
  local_694c = (int *)FUN_004d1e10();
  (**(code **)(*local_694c + 0x18))();
  local_8._0_1_ = 5;
  (**(code **)(*local_694c + 0x10))();
  local_8._0_1_ = 6;
  ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_6958);
  ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_695c);
  Left(local_6948);
  local_8._0_1_ = 7;
  FUN_00403dd0(local_6958);
  FUN_0044ef10(local_6964);
  local_8._0_1_ = 8;
  FUN_00575010();
  iVar2 = FUN_0042ddc0();
  if (iVar2 == 0) {
    FUN_00464040();
    local_8._0_1_ = 10;
    FUN_00464180(DAT_00a0b410,1);
    FUN_004d1a10();
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_004640a0();
  }
  else {
    if ((DAT_00a0b3e8 < 700) && (DAT_00a0cb14 == 0)) {
      local_6944 = 0;
      local_6968 = FUN_00572030();
      local_6950 = local_6968;
      while ((local_6944 == 0 && (local_6950 != 0))) {
        local_696c = FUN_00572100(&local_6950);
        local_6940 = local_696c;
        local_6970 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078);
        if ((local_6970 != 0) && (local_6974 = local_6940, *(int *)(local_6940 + 0x1c0) != 0)) {
          local_6944 = 1;
        }
      }
      local_6978 = FUN_00572050();
      local_6950 = local_6978;
      while ((local_6944 == 0 &&
             (local_697c = FUN_005720a0(&local_6950), local_6954 = local_697c, local_697c != 0))) {
        if (*(int *)(local_697c + 0x6c) != 0) {
          local_6984 = FUN_0049ac10();
          local_6980 = local_6984;
          while ((local_6944 == 0 && (local_6940 = FUN_0049ac30(&local_6984,0), local_6940 != 0))) {
            iVar2 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078);
            if ((iVar2 != 0) && (*(int *)(local_6940 + 0x1c0) != 0)) {
              local_6944 = 1;
            }
          }
        }
      }
      if (local_6944 != 0) {
        FUN_004f60a0(0x279f,0,0xffffffff);
      }
    }
    FUN_00464040();
    local_8._0_1_ = 9;
    FUN_00464180(DAT_00a0b410,1);
    FUN_00571010();
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_004640a0();
  }
  pwVar3 = __wgetcwd(local_218,0x100);
  if (pwVar3 == (wchar_t *)0x0) {
    local_6960 = 0;
    local_218[0] = L'\0';
  }
  uVar4 = FUN_00404920();
  iVar2 = FUN_00904434(uVar4);
  if ((iVar2 == 0) && (*(int *)(local_693c + 0x1d28) != 0)) {
    cVar1 = FUN_00447350(L".JWC",local_6964);
    if (cVar1 == '\0') {
      if (DAT_00a0ef7c == 0) {
        uVar4 = FUN_00404920();
        FUN_007a3c25(L"Folder",L"File",uVar4);
        FUN_00404860(local_6948);
      }
    }
    else {
      uVar4 = FUN_00404920();
      FUN_007a3c25(L"Folder",L"FileC",uVar4);
      FUN_00404860(local_6948);
    }
  }
  if (local_218[0] != L'\0') {
    FUN_00904434(local_218);
  }
  iVar2 = FUN_0042ddc0();
  if (iVar2 == 0) {
    FUN_00457f70(2);
  }
  local_8._0_1_ = 7;
  FUN_00404540();
  local_8._0_1_ = 6;
  FUN_00404540();
  local_8._0_1_ = 5;
  FUN_00404540();
  local_8._0_1_ = 2;
  FUN_00404540();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00447100();
  FUN_004d2eba();
  return;
}




/* vtable slots: CJw_winDoc[25], CMiniDoc[25] */
/* 004d2f40  FUN_004d2f40  22 bytes, 0 callers */

void FUN_004d2f40(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x48) = param_1;
  return;
}




/* vtable slots: CJw_winDoc[32], CMiniDoc[32] */
/* 00573d20  FUN_00573d20  2687 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00573d20(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_6998 [4];
  undefined4 local_6994;
  undefined4 local_6990;
  int local_698c;
  undefined4 local_6988;
  int local_6984;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6980 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_697c [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6978 [4];
  undefined4 local_6974;
  undefined4 local_6970;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_696c;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6968;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6964;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6960;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_695c [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6958 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6954 [4];
  undefined4 local_6950;
  undefined4 local_694c;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6948;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6944;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6940;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_693c;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6938 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6934 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6930 [4];
  undefined4 local_692c;
  undefined4 local_6928;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6924;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6920;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_691c;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6918;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6914 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6910 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_690c;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6908;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6904;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6900;
  undefined4 local_68fc;
  int local_68f8;
  undefined4 local_68f0;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_68ec [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_68e8 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_68e4 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_68e0 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_68dc [4];
  int local_68d8;
  ushort local_68d4;
  CSimpleStringT<wchar_t,0> local_68d0 [26812];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092dcd7;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xe0) == 0) {
    if (DAT_00a0b410 == 0) {
      local_68f8 = 0;
    }
    else {
      local_68f8 = DAT_00a0b410 + 0x88;
    }
    local_68d8 = local_68f8;
  }
  else {
    local_68d8 = *(int *)(in_ECX + 0xe0);
  }
  CStringT<>();
  local_8 = 0;
  FUN_00403dd0();
  iVar1 = FUN_004be180();
  if (iVar1 == 0) {
    if (*(int *)(local_68d8 + 0x846c) == 1) {
      *(undefined4 *)(local_68d8 + 0x846c) = 0;
      FUN_00404860();
      local_68fc = FUN_007aa2dc();
      local_8 = 0xffffffff;
      FUN_00404540();
      uVar2 = local_68fc;
    }
    else {
      ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_68d0);
      local_68d4 = FUN_004473c0();
      local_68d4 = local_68d4 & 0xff;
      CStringT<>();
      local_8._0_1_ = 1;
      CStringT<>();
      local_8._0_1_ = 2;
      CStringT<>();
      local_8._0_1_ = 3;
      CStringT<>();
      local_8._0_1_ = 4;
      local_68f0 = 0;
      local_6904 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *)
                   ATL::operator+(local_6914,local_68ec);
      local_8._0_1_ = 5;
      local_6900 = local_6904;
      local_690c = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *)
                   ATL::operator+(local_6910,local_6904);
      local_8._0_1_ = 6;
      local_6908 = local_690c;
      ATL::operator+(local_68dc,local_690c);
      local_8._0_1_ = 8;
      FUN_00404540();
      local_8._0_1_ = 9;
      FUN_00404540();
      if ((local_68d4 == 99) || (local_68d4 == 0x43)) {
        ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_68d0);
        local_68d4 = FUN_004473c0();
        local_68d4 = local_68d4 & 0xff;
        if ((local_68d4 == 0x6a) || (local_68d4 == 0x4a)) {
          local_691c = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                        *)ATL::operator+(local_6938,local_68e8);
          local_8._0_1_ = 10;
          local_6918 = local_691c;
          local_6924 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                        *)ATL::operator+(local_6934,local_691c);
          local_8._0_1_ = 0xb;
          local_6920 = local_6924;
          local_692c = ATL::operator+(local_6930,local_6924);
          local_8._0_1_ = 0xc;
          local_6928 = local_692c;
          FUN_00404860();
          local_8._0_1_ = 0xb;
          FUN_00404540();
          local_8._0_1_ = 10;
          FUN_00404540();
          local_8._0_1_ = 9;
          FUN_00404540();
          if (DAT_00a0b3e4 == 0) {
            local_68f0 = 1;
          }
        }
        else {
          local_6940 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                        *)ATL::operator+(local_695c,local_68e0);
          local_8._0_1_ = 0xd;
          local_693c = local_6940;
          local_6948 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                        *)ATL::operator+(local_6958,local_6940);
          local_8._0_1_ = 0xe;
          local_6944 = local_6948;
          local_6950 = ATL::operator+(local_6954,local_6948);
          local_8._0_1_ = 0xf;
          local_694c = local_6950;
          FUN_00404860();
          local_8._0_1_ = 0xe;
          FUN_00404540();
          local_8._0_1_ = 0xd;
          FUN_00404540();
          local_8._0_1_ = 9;
          FUN_00404540();
          if (DAT_00a0b3e4 == 0) {
            local_68f0 = 1;
          }
        }
      }
      else if ((local_68d4 == 0x66) || (local_68d4 == 0x46)) {
        local_6964 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                      *)ATL::operator+(local_6980,local_68e4);
        local_8._0_1_ = 0x10;
        local_6960 = local_6964;
        local_696c = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                      *)ATL::operator+(local_697c,local_6964);
        local_8._0_1_ = 0x11;
        local_6968 = local_696c;
        local_6974 = ATL::operator+(local_6978,local_696c);
        local_8._0_1_ = 0x12;
        local_6970 = local_6974;
        FUN_00404860();
        local_8._0_1_ = 0x11;
        FUN_00404540();
        local_8._0_1_ = 0x10;
        FUN_00404540();
        local_8._0_1_ = 9;
        FUN_00404540();
        if (DAT_00a0b3e4 == 0) {
          local_68f0 = 1;
        }
      }
      FUN_00403dd0();
      local_6984 = FUN_00517dc0();
      if (local_6984 == 0) {
        FUN_00403dd0();
        local_698c = FUN_004be3a0();
        if (local_698c == 0) {
LAB_005746f3:
          FUN_00404860();
          FUN_00404920();
          uVar2 = FUN_007aa2dc();
          local_8._0_1_ = 4;
          FUN_00404540();
          local_8._0_1_ = 3;
          FUN_00404540();
          local_8._0_1_ = 2;
          FUN_00404540();
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00404540();
        }
        else {
          while( true ) {
            FUN_00446aa0();
            local_8._0_1_ = 0x13;
            FUN_00404920();
            FUN_00404920();
            FUN_00403dd0(local_68d0);
            local_6994 = FUN_0044ec60(local_6998);
            local_8._0_1_ = 0x14;
            local_6990 = local_6994;
            FUN_00404920();
            FUN_007b3573(0);
            local_8._0_1_ = 0x16;
            FUN_00404540();
            iVar1 = FUN_007b3f8f();
            if (iVar1 != 1) break;
            SetCurrentDirectoryW((LPCWSTR)&DAT_00a08f74);
            FUN_007b4284();
            local_8._0_1_ = 0x17;
            FUN_00404860();
            local_8._0_1_ = 0x16;
            FUN_00404540();
            FUN_004e1730();
            FUN_00403dd0();
            iVar1 = FUN_004be180();
            if (iVar1 == 0) {
              FUN_007a847b();
              local_8._0_1_ = 0x18;
              FUN_00404920();
              iVar1 = FUN_007a86f9();
              if (iVar1 == 0) {
                FUN_007a869f();
LAB_005745c9:
                local_8._0_1_ = 0x16;
                FUN_007a8621();
                FUN_00403dd0();
                iVar1 = FUN_004be3a0();
                if (iVar1 == 0) {
                  local_8._0_1_ = 0x13;
                  FUN_007b384d();
                  local_8._0_1_ = 9;
                  FUN_00447100();
                  goto LAB_005746f3;
                }
                local_8._0_1_ = 0x13;
                FUN_007b384d();
                local_8._0_1_ = 9;
                FUN_00447100();
              }
              else {
                FUN_007a869f();
                iVar1 = FUN_004f60a0();
                if (iVar1 == 1) goto LAB_005745c9;
                local_8._0_1_ = 0x16;
                FUN_007a8621();
                local_8._0_1_ = 0x13;
                FUN_007b384d();
                local_8._0_1_ = 9;
                FUN_00447100();
              }
            }
            else {
              local_8._0_1_ = 0x13;
              FUN_007b384d();
              local_8._0_1_ = 9;
              FUN_00447100();
            }
          }
          SetCurrentDirectoryW((LPCWSTR)&DAT_00a08f74);
          local_8._0_1_ = 0x13;
          FUN_007b384d();
          local_8._0_1_ = 9;
          FUN_00447100();
          local_8._0_1_ = 4;
          FUN_00404540();
          local_8._0_1_ = 3;
          FUN_00404540();
          local_8._0_1_ = 2;
          FUN_00404540();
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00404540();
          uVar2 = 1;
        }
      }
      else {
        local_6988 = 0;
        local_8._0_1_ = 4;
        FUN_00404540();
        local_8._0_1_ = 3;
        FUN_00404540();
        local_8._0_1_ = 2;
        FUN_00404540();
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
        local_8 = 0xffffffff;
        FUN_00404540();
        uVar2 = local_6988;
      }
    }
  }
  else {
    local_8 = 0xffffffff;
    FUN_00404540();
    uVar2 = 1;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CJw_winDoc[48], CMiniDoc[48] */
/* 007a919a  FUN_007a919a  10 bytes, 0 callers */

void FUN_007a919a(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(in_ECX + 0x7c);
  return;
}




/* vtable slots: CJw_winDoc[53], CMiniDoc[53] */
/* 007a91a4  FUN_007a91a4  110 bytes, 0 callers */

undefined4 FUN_007a91a4(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x68);
  guard_check_icall();
  local_8 = (*pcVar1)();
  do {
    if (local_8 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0xd8);
      guard_check_icall();
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    pcVar1 = *(code **)(*in_ECX + 0x6c);
    guard_check_icall(&local_8);
    (*pcVar1)();
    iVar2 = FUN_0079296c();
  } while ((iVar2 == 0) || (*(int *)(iVar2 + 0x84) < 1));
  return 1;
}




/* vtable slots: CJw_winDoc[46], CMiniDoc[46] */
/* 007a9212  FUN_007a9212  80 bytes, 1 callers */

void FUN_007a9212(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x7c);
  *(undefined4 *)(in_ECX + 0x94) = 0;
  while (local_8 != 0) {
    piVar2 = (int *)FUN_00792938(&local_8);
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      pcVar1 = (code *)**(undefined4 **)*piVar2;
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  RemoveAll();
  return;
}




/* vtable slots: CJw_winDoc[23], CMiniDoc[23] */
/* 007a9262  FUN_007a9262  8 bytes, 0 callers */

void FUN_007a9262(void)

{
  Empty();
  return;
}




/* vtable slots: CJw_winDoc[57], CMiniDoc[57] */
/* 007a9316  FUN_007a9316  59 bytes, 0 callers */

bool FUN_007a9316(void)

{
  DWORD DVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  
  DVar1 = GetFileAttributesW((LPCWSTR)in_ECX[9]);
  iVar2 = *in_ECX;
  if ((DVar1 & 1) == 0) {
    iVar3 = in_ECX[9];
  }
  else {
    iVar3 = 0;
  }
  guard_check_icall(iVar3,1);
  iVar2 = (**(code **)(iVar2 + 0xe0))();
  return iVar2 != 0;
}




/* vtable slots: CJw_winDoc[56], CMiniDoc[56] */
/* 007a9473  FUN_007a9473  619 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007a9473(int param_1,int param_2)

{
  code *pcVar1;
  wchar_t *pwVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  undefined4 uVar5;
  undefined1 local_30 [4];
  int *local_2c;
  int *local_28;
  int local_24;
  int local_20;
  wchar_t *local_1c [5];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x7a947f;
  local_28 = in_ECX;
  CStringT<>(param_1);
  uVar5 = 0;
  local_8 = 0;
  if (*(int *)(local_1c[0] + -6) == 0) {
    local_2c = (int *)in_ECX[10];
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)local_1c,(CSimpleStringT<wchar_t,0> *)(in_ECX + 9));
    if ((param_2 != 0) && (*(int *)(local_1c[0] + -6) == 0)) {
      ATL::CSimpleStringT<wchar_t,0>::operator=
                ((CSimpleStringT<wchar_t,0> *)local_1c,(CSimpleStringT<wchar_t,0> *)(in_ECX + 8));
      pwVar2 = _wcspbrk(local_1c[0],L":/\\");
      if ((pwVar2 != (wchar_t *)0x0) && (iVar3 = (int)pwVar2 - (int)local_1c[0] >> 1, iVar3 != -1))
      {
        ReleaseBuffer(iVar3);
      }
      if (0x100 < *(int *)(local_1c[0] + -6)) {
        FUN_00406c20(0x100);
      }
      iVar3 = FUN_0079dd6d();
      if (*(int *)(iVar3 + 4) != 0) {
        iVar3 = FUN_0079dd6d();
        pcVar1 = *(code **)(**(int **)(iVar3 + 4) + 0xfc);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 != 0) {
          iVar3 = FUN_0079dd6d();
          pcVar1 = *(code **)(**(int **)(iVar3 + 4) + 0xfc);
          guard_check_icall();
          piVar4 = (int *)(*pcVar1)();
          pcVar1 = *(code **)(*piVar4 + 0x74);
          guard_check_icall(&local_24,local_28);
          (*pcVar1)();
          local_8 = CONCAT31(local_8._1_3_,1);
          if (*(int *)(local_24 + -0xc) != 0) {
            ATL::CSimpleStringT<wchar_t,0>::operator=
                      ((CSimpleStringT<wchar_t,0> *)local_1c,(CSimpleStringT<wchar_t,0> *)&local_24)
            ;
          }
          FUN_00406b10();
        }
      }
      CStringT<>();
      local_8._0_1_ = 2;
      pcVar1 = *(code **)(*local_2c + 100);
      guard_check_icall(&local_20,4);
      iVar3 = (*pcVar1)();
      if ((iVar3 != 0) && (*(int *)(local_20 + -0xc) != 0)) {
        local_24 = 0;
        piVar4 = (int *)FUN_007ab24a(local_30,&DAT_0097f7a8,&local_24);
        local_8._0_1_ = 3;
        FUN_00404cf0(*piVar4,*(undefined4 *)(*piVar4 + -0xc));
        FUN_00406b10();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00406b10();
      in_ECX = local_28;
    }
    FUN_0079dd6d();
    iVar3 = FUN_007b2c5a(local_1c,(-(uint)(param_2 != 0) & 0xfffffffd) + 0xf004,0x804,0,local_2c);
    if (iVar3 == 0) {
      FUN_00406b10();
      return 0;
    }
  }
  FUN_0079dd6d();
  FUN_0078ff40();
  local_8._0_1_ = 4;
  pcVar1 = *(code **)(*in_ECX + 0x80);
  guard_check_icall(local_1c[0]);
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    if (param_1 == 0) {
      local_8._0_1_ = 5;
      Remove(local_1c[0],0);
    }
  }
  else {
    if (param_2 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x58);
      guard_check_icall(local_1c[0],1);
      (*pcVar1)();
      pcVar1 = *(code **)(*in_ECX + 0xd0);
      guard_check_icall(2);
      (*pcVar1)();
    }
    uVar5 = 1;
  }
  FUN_00408b00();
  FUN_00406b10();
  return uVar5;
}




/* vtable slots: CJw_winDoc[51], CMiniDoc[51] */
/* 007a96f4  FUN_007a96f4  125 bytes, 0 callers */

int FUN_007a96f4(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  int local_c;
  int *local_8;
  
  local_c = *(int *)(in_ECX + 0x7c);
  do {
    do {
      iVar2 = local_c;
      if (iVar2 == 0) {
        return 0;
      }
      local_c = iVar2;
      puVar3 = (undefined4 *)FUN_00792938(&local_c);
      local_8 = (int *)*puVar3;
      pcVar1 = *(code **)(*local_8 + 0x20);
      guard_check_icall(param_1);
      uVar4 = (*pcVar1)();
      iVar5 = FUN_0079066d(uVar4);
    } while (iVar5 == 0);
    pcVar1 = *(code **)(*local_8 + 0x24);
    guard_check_icall();
    iVar5 = (*pcVar1)();
  } while (iVar5 != param_2);
  return iVar2;
}




/* vtable slots: CJw_winDoc[35], CMiniDoc[35] */
/* 007a9771  FUN_007a9771  109 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_007a9771(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = FUN_0078e624(0x18);
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_007a8e37();
  }
  pcVar1 = *(code **)(*piVar3 + 0x24);
  guard_check_icall(param_1,param_2,param_3);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*piVar3 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    piVar3 = (int *)0x0;
  }
  return piVar3;
}




/* vtable slots: CJw_winDoc[26], CMiniDoc[26] */
/* 007a97de  FUN_007a97de  4 bytes, 0 callers */

undefined4 FUN_007a97de(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}




/* vtable slots: CJw_winDoc[14], CMiniDoc[14] */
/* 007a97e2  FUN_007a97e2  6 bytes, 0 callers */

undefined ** FUN_007a97e2(void)

{
  return &PTR_DAT_0097f744;
}




/* vtable slots: CJw_winDoc[27], CMiniDoc[27] */
/* 007a97e8  FUN_007a97e8  28 bytes, 0 callers */

undefined4 FUN_007a97e8(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00797af6(param_1);
  }
  return uVar1;
}




/* vtable slots: CJw_winDoc[44], CMiniDoc[44] */
/* 007a9863  FUN_007a9863  328 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007a9863(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  code *pcVar1;
  HDC hDC;
  CDC *pCVar2;
  HDC pHVar3;
  int iVar4;
  HBITMAP pHVar5;
  void *pvVar6;
  CGdiObject *pCVar7;
  CDC local_4c [4];
  HDC__ *local_48;
  undefined4 *local_3c;
  HDC local_38;
  CDC *local_34;
  int *local_30;
  undefined **local_2c;
  void *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x7a986f;
  local_3c = param_2;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  hDC = GetDC((HWND)0x0);
  local_38 = hDC;
  pCVar2 = CDC::FromHandle(hDC);
  CDC::CDC(local_4c);
  pCVar7 = (CGdiObject *)0x0;
  local_28 = (void *)0x0;
  local_2c = CBitmap::vftable;
  local_1c = param_1;
  local_18 = param_1;
  pHVar3 = (HDC)0x0;
  local_8 = 1;
  local_24 = 0;
  local_20 = 0;
  if (pCVar2 != (CDC *)0x0) {
    pHVar3 = *(HDC *)(pCVar2 + 4);
  }
  local_34 = pCVar2;
  pHVar3 = CreateCompatibleDC(pHVar3);
  iVar4 = FUN_0079e84a(pHVar3);
  if (iVar4 == 0) {
    ReleaseDC((HWND)0x0,hDC);
  }
  else {
    pHVar5 = CreateCompatibleBitmap(*(HDC *)(pCVar2 + 4),local_1c - local_24,local_18 - local_20);
    iVar4 = Attach(pHVar5);
    if (iVar4 != 0) {
      local_34 = local_4c;
      pCVar7 = CDC::SelectGdiObject(local_48,local_28);
    }
    CDC::SelectGdiObject(local_48,local_28);
    pcVar1 = *(code **)(*local_30 + 0x10c);
    guard_check_icall(local_4c,&local_24);
    (*pcVar1)();
    if (local_34 != pCVar2) {
      if (pCVar7 == (CGdiObject *)0x0) {
        pvVar6 = (void *)0x0;
      }
      else {
        pvVar6 = *(void **)(pCVar7 + 4);
      }
      CDC::SelectGdiObject(local_48,pvVar6);
    }
    ReleaseDC((HWND)0x0,local_38);
    pvVar6 = CGdiObject::Detach((CGdiObject *)&local_2c);
    *local_3c = pvVar6;
  }
  local_2c = CBitmap::vftable;
  FUN_00416100();
  FUN_0079e053();
  FUN_008d9b68();
  return;
}




/* vtable slots: CJw_winDoc[43], CMiniDoc[43] */
/* 007a9a73  FUN_007a9a73  39 bytes, 0 callers */

void FUN_007a9a73(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xf8);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CJw_winDoc[28], CMiniDoc[28] */
/* 007a9a9a  FUN_007a9a9a  52 bytes, 0 callers */

void FUN_007a9a9a(void)

{
  int *in_ECX;
  code *pcVar1;
  
  if ((in_ECX[0xe] == 0) && (in_ECX[0x27] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x84);
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0xe8);
  }
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CJw_winDoc[33], CMiniDoc[33] */
/* 007a9ace  FUN_007a9ace  196 bytes, 0 callers */

void FUN_007a9ace(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar3 = FUN_007a9a55();
  if ((iVar3 == 0) || (in_ECX[0x13] != 0)) {
    iVar3 = in_ECX[0x27];
    in_ECX[0x27] = 0;
    iVar1 = in_ECX[0xe];
    while (iVar1 != 0) {
      piVar4 = (int *)FUN_0079296c();
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      pcVar2 = *(code **)(*in_ECX + 0xdc);
      guard_check_icall(piVar4);
      (*pcVar2)();
      pcVar2 = *(code **)(*piVar4 + 0x60);
      guard_check_icall();
      (*pcVar2)();
      iVar1 = in_ECX[0xe];
    }
    in_ECX[0x27] = iVar3;
    pcVar2 = *(code **)(*in_ECX + 0xd0);
    guard_check_icall(3);
    (*pcVar2)();
    pcVar2 = *(code **)(*in_ECX + 0x74);
    guard_check_icall();
    (*pcVar2)();
    if (in_ECX[0x27] != 0) {
      pcVar2 = *(code **)(*in_ECX + 4);
      guard_check_icall(1);
      (*pcVar2)();
    }
  }
  return;
}




/* vtable slots: CJw_winDoc[3], CMiniDoc[3] */
/* 007a9b93  FUN_007a9b93  81 bytes, 0 callers */

undefined4 FUN_007a9b93(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = FUN_007900e9(param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    if (*(int **)(in_ECX + 0x28) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x28) + 0xc);
      guard_check_icall(param_1,param_2,param_3,param_4);
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) goto LAB_007a9bdc;
    }
    uVar3 = 0;
  }
  else {
LAB_007a9bdc:
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CJw_winDoc[65], CMiniDoc[65] */
/* 007a9be4  FUN_007a9be4  299 bytes, 0 callers */

undefined4 FUN_007a9be4(void)

{
  code *pcVar1;
  int iVar2;
  CWnd *pCVar3;
  int iVar4;
  HWND hWnd;
  BOOL BVar5;
  undefined4 uVar6;
  int *in_ECX;
  int *piVar7;
  int *local_c;
  int local_8;
  
  local_c = in_ECX;
  FUN_0079dd6d();
  local_8 = FUN_007b252e();
  do {
    if (local_8 == 0) goto LAB_007a9c46;
    local_c = (int *)FUN_007b254f(&local_8);
    pcVar1 = *(code **)*in_ECX;
    guard_check_icall();
    iVar2 = (*pcVar1)();
  } while (local_c[0x1a] != iVar2);
  piVar7 = in_ECX;
  pCVar3 = CWnd::FromHandle((HWND__ *)in_ECX[0x15]);
  iVar2 = FUN_007c65d0(pCVar3,piVar7);
  in_ECX[0x1c] = iVar2;
LAB_007a9c46:
  uVar6 = 0;
  if (in_ECX[0x1c] != 0) {
    pCVar3 = CWnd::GetDescendantWindow(*(HWND__ **)(in_ECX[0x1c] + 0x20),0xe900,0);
    if (pCVar3 != (CWnd *)0x0) {
      iVar2 = FUN_007a198a(pCVar3,0);
      if (iVar2 != 0) {
        FUN_007a1ad4(iVar2);
        CObList::AddHead((CObList *)(in_ECX + 0xb),(CObject *)pCVar3);
      }
    }
    FUN_00797c9f(0x200,0,0);
    pcVar1 = *(code **)(*in_ECX + 0x68);
    guard_check_icall();
    local_c = (int *)(*pcVar1)();
    while (local_c != (int *)0x0) {
      pcVar1 = *(code **)(*in_ECX + 0x6c);
      guard_check_icall(&local_c);
      iVar2 = (*pcVar1)();
      FUN_00797c9f(0x200,0,0);
      iVar4 = FUN_00799e17();
      if (iVar4 == 0) {
        hWnd = (HWND)0x0;
        if (iVar2 != 0) {
          hWnd = *(HWND *)(iVar2 + 0x20);
        }
        BVar5 = IsChild(*(HWND *)(in_ECX[0x1c] + 0x20),hWnd);
        if (BVar5 != 0) {
          FUN_0079c886(iVar2);
        }
      }
    }
    uVar6 = 1;
  }
  return uVar6;
}




/* vtable slots: CJw_winDoc[52], CMiniDoc[52] */
/* 007a9d0f  FUN_007a9d0f  129 bytes, 0 callers */

void FUN_007a9d0f(int param_1)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  
  iVar1 = FUN_0079dd6d();
  if (*(int **)(iVar1 + 4) != (int *)0x0) {
    pcVar3 = *(code **)(**(int **)(iVar1 + 4) + 0xfc);
    guard_check_icall();
    piVar2 = (int *)(*pcVar3)();
    if (piVar2 != (int *)0x0) {
      if ((param_1 == 0) || (param_1 == 1)) {
        pcVar3 = *(code **)(*piVar2 + 0x48);
      }
      else if (param_1 == 2) {
        pcVar3 = *(code **)(*piVar2 + 0x4c);
      }
      else {
        if (param_1 != 3) {
          return;
        }
        pcVar3 = *(code **)(*piVar2 + 0x30);
        guard_check_icall();
        iVar1 = (*pcVar3)();
        if (iVar1 != 0) {
          return;
        }
        pcVar3 = *(code **)(*piVar2 + 0x50);
      }
      guard_check_icall();
      (*pcVar3)();
    }
  }
  return;
}




/* vtable slots: CJw_winDoc[4], CMiniDoc[4] */
/* 007a9e00  FUN_007a9e00  64 bytes, 0 callers */

void FUN_007a9e00(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX[0x2a] != 0) {
    if (in_ECX[0x14] != 0) {
      FUN_007c3851();
      in_ECX[0x14] = 0;
    }
    in_ECX[0x27] = 1;
  }
  in_ECX[0x13] = 1;
  pcVar1 = *(code **)(*in_ECX + 0x84);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CJw_winDoc[61], CMiniDoc[61] */
/* 007a9e40  FUN_007a9e40  88 bytes, 0 callers */

void FUN_007a9e40(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = FUN_0079dd6d();
  if (*(int **)(iVar2 + 4) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0xfc);
    guard_check_icall();
    piVar3 = (int *)(*pcVar1)();
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 0x28);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        pcVar1 = *(code **)(*piVar3 + 0x40);
        guard_check_icall();
        (*pcVar1)();
      }
    }
  }
  return;
}




/* vtable slots: CJw_winDoc[62], CMiniDoc[62] */
/* 007a9e98  FUN_007a9e98  116 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007a9e98(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 local_80 [4];
  undefined4 local_7c;
  undefined1 local_38 [48];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x70;
  local_8 = 0x7a9ea4;
  if (param_1 == 0) {
    return 0x80070057;
  }
  FUN_007c69d9(0);
  local_8 = 0;
  FUN_007c6c85(param_1);
  FUN_007a6256(local_38,3,0x1000,0);
  local_7c = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  pcVar1 = *(code **)(*in_ECX + 8);
  guard_check_icall(local_80);
  (*pcVar1)();
  FUN_007a664f();
  uVar2 = FUN_007a9f28();
  return uVar2;
}




/* vtable slots: CJw_winDoc[31], CMiniDoc[31] */
/* 007a9f8e  FUN_007a9f8e  152 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007a9f8e(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  longlong lVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 auStack_78 [4];
  undefined4 uStack_74;
  int *local_20;
  int local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_8 = 0x7a9f9a;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_20 = (int *)FUN_0078e624(0x14);
  local_8 = 0;
  if (local_20 == (int *)0x0) {
    local_1c = 0;
  }
  else {
    local_1c = CFileException(0,0xffffffff,0);
  }
  iVar3 = local_1c;
  local_8 = 0xffffffff;
  uVar6 = 0x20;
  pcVar1 = *(code **)(*in_ECX + 0x8c);
  iVar5 = param_1;
  iVar7 = local_1c;
  guard_check_icall(param_1,0x20,local_1c);
  local_20 = (int *)(*pcVar1)();
  if (local_20 == (int *)0x0) {
    pcVar1 = *(code **)(*in_ECX + 0x88);
    local_8 = 1;
    guard_check_icall(param_1,iVar3,0,0xf101);
    (*pcVar1)();
    uVar6 = FUN_007aa032();
    return uVar6;
  }
  if (iVar3 != 0) {
    FUN_0078e7c3();
  }
  pcVar1 = *(code **)(*in_ECX + 0x74);
  guard_check_icall(iVar5,uVar6,iVar7);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 100);
  guard_check_icall(1);
  (*pcVar1)();
  piVar2 = local_20;
  FUN_007a6256(local_20,3,0x1000,0);
  uStack_74 = 0;
  local_8._0_1_ = 4;
  local_8._1_3_ = 0;
  FUN_0079dd6d();
  FUN_0078ff40();
  local_8 = CONCAT31(local_8._1_3_,5);
  pcVar1 = *(code **)(*piVar2 + 0x34);
  guard_check_icall();
  lVar4 = (*pcVar1)();
  if (lVar4 != 0) {
    pcVar1 = *(code **)(*in_ECX + 8);
    guard_check_icall(auStack_78);
    (*pcVar1)();
  }
  FUN_007a664f();
  pcVar1 = *(code **)(*in_ECX + 0x90);
  guard_check_icall(piVar2,0);
  (*pcVar1)();
  FUN_00408b00();
  local_8 = 3;
  pcVar1 = *(code **)(*in_ECX + 100);
  guard_check_icall(0);
  (*pcVar1)();
  FUN_007a6389();
  return 1;
}




/* vtable slots: CJw_winDoc[63], CMiniDoc[63] */
/* 007aa1c3  OnPreviewHandlerQueryFocus  60 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CDocument::OnPreviewHandlerQueryFocus(struct HWND__ * *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __thiscall CDocument::OnPreviewHandlerQueryFocus(CDocument *this,HWND__ **param_1)

{
  DWORD DVar1;
  HWND pHVar2;
  
  if (param_1 == (HWND__ **)0x0) {
    DVar1 = 0x80070057;
  }
  else {
    pHVar2 = GetFocus();
    DVar1 = 0;
    *param_1 = pHVar2;
    if ((pHVar2 == (HWND)0x0) && (DVar1 = GetLastError(), 0 < (int)DVar1)) {
      DVar1 = DVar1 & 0xffff | 0x80070000;
    }
  }
  return DVar1;
}




/* vtable slots: CJw_winDoc[64], CMiniDoc[64] */
/* 007aa1ff  FUN_007aa1ff  41 bytes, 0 callers */

undefined4 FUN_007aa1ff(undefined4 param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0xd4);
  uVar3 = 1;
  if (piVar1 != (int *)0x0) {
    pcVar2 = *(code **)(*piVar1 + 0x10);
    guard_check_icall(piVar1,param_1);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: CJw_winDoc[42], CMiniDoc[42] */
/* 007aa228  FUN_007aa228  180 bytes, 0 callers */

void FUN_007aa228(void)

{
  code *pcVar1;
  int *piVar2;
  BOOL BVar3;
  HWND hWnd;
  int *in_ECX;
  
  in_ECX[0x12] = 0;
  pcVar1 = *(code **)(*in_ECX + 0x108);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x74);
  guard_check_icall();
  (*pcVar1)();
  piVar2 = (int *)in_ECX[0x35];
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 8);
    guard_check_icall(piVar2);
    (*pcVar1)();
    in_ECX[0x35] = 0;
  }
  if (in_ECX[0x1c] != 0) {
    BVar3 = IsWindow(*(HWND *)(in_ECX[0x1c] + 0x20));
    if (BVar3 != 0) {
      FUN_0079c896(0,1);
      if (in_ECX[0x1c] == 0) {
        hWnd = (HWND)0x0;
      }
      else {
        hWnd = *(HWND *)(in_ECX[0x1c] + 0x20);
      }
      DestroyWindow(hWnd);
      in_ECX[0x1c] = 0;
    }
  }
  piVar2 = (int *)in_ECX[0x1a];
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 8);
    guard_check_icall(piVar2);
    (*pcVar1)();
    in_ECX[0x1a] = 0;
  }
  in_ECX[0x15] = 0;
  SetRectEmpty((LPRECT)(in_ECX + 0x16));
  in_ECX[0x1b] = 0;
  return;
}




/* vtable slots: CJw_winDoc[49], CMiniDoc[49] */
/* 007aa89c  ReadNextChunkValue  47 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CDocument::ReadNextChunkValue(struct ATL::IFilterChunkValue * *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2015 Release */

int __thiscall CDocument::ReadNextChunkValue(CDocument *this,IFilterChunkValue **param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((*(int *)(this + 0x94) == 0) || (param_1 == (IFilterChunkValue **)0x0)) {
    iVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_00792938(this + 0x94);
    *param_1 = (IFilterChunkValue *)*puVar1;
    iVar2 = 1;
  }
  return iVar2;
}




/* vtable slots: CJw_winDoc[36], CMiniDoc[36] */
/* 007aa9c5  FUN_007aa9c5  71 bytes, 0 callers */

void FUN_007aa9c5(int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *param_1;
  if (param_2 == 0) {
    guard_check_icall();
    (**(code **)(iVar1 + 0x50))();
  }
  else {
    guard_check_icall();
    (**(code **)(iVar1 + 0x48))();
  }
  pcVar2 = *(code **)(*param_1 + 4);
  guard_check_icall(1);
  (*pcVar2)();
  return;
}




/* vtable slots: CJw_winDoc[50], CMiniDoc[50] */
/* 007aaa0c  FUN_007aaa0c  66 bytes, 0 callers */

void FUN_007aaa0c(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xcc);
  guard_check_icall(param_1,param_2);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_008d8efe(*(undefined4 *)(iVar2 + 8),0);
    FUN_007a1ad4(iVar2);
  }
  return;
}




/* vtable slots: CJw_winDoc[34], CMiniDoc[34] */
/* 007aaa8c  FUN_007aaa8c  401 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007aaa8c(wchar_t *param_1,int *param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  int local_224;
  int local_220;
  undefined1 local_21c [532];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x218;
  local_8 = 0x7aaa9b;
  local_224 = param_4;
  CStringT<>();
  local_8 = 0;
  if (param_2 != (int *)0x0) {
    iVar2 = FUN_0079d98a(&PTR_s_CUserException_0097df04);
    if (iVar2 != 0) goto LAB_007aac07;
    iVar2 = FUN_0079d98a(&PTR_s_CArchiveException_0097f324);
    if (iVar2 == 0) {
      iVar2 = FUN_0079d98a(&PTR_s_CFileException_0097f380);
      if (iVar2 != 0) {
        if (*(int *)(param_2[4] + -0xc) == 0) {
          if (param_1 == (wchar_t *)0x0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_008f899d(param_1);
          }
          ATL::CSimpleStringT<wchar_t,0>::SetString
                    ((CSimpleStringT<wchar_t,0> *)(param_2 + 4),param_1,iVar2);
        }
        pcVar3 = ATL::CSimpleStringT<char,0>::PrepareWrite
                           ((CSimpleStringT<char,0> *)&local_220,0x104);
        pcVar1 = *(code **)(*param_2 + 0xc);
        guard_check_icall(pcVar3,0x103,&local_224);
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) {
          iVar2 = param_2[2];
          if ((iVar2 == 2) || (iVar2 == 3)) {
            param_4 = 0xf121;
          }
          else if (iVar2 == 5) {
            param_4 = (param_3 != 0) + 0xf123;
          }
          else if (iVar2 == 0xd) {
            param_4 = 0xf122;
          }
        }
        ReleaseBuffer(0xffffffff);
      }
    }
    else {
      iVar2 = param_2[2];
      if ((((iVar2 == 3) || (iVar2 == 5)) || (iVar2 == 6)) || (iVar2 == 7)) {
        param_4 = 0xf120;
      }
    }
  }
  if (*(int *)(local_220 + -0xc) == 0) {
    FUN_007a7375(param_1,local_21c,0x104);
    FUN_007c1390(&local_220,param_4,local_21c);
  }
  FUN_0079f557(local_220,0x30,local_224);
LAB_007aac07:
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CJw_winDoc[54], CMiniDoc[54] */
/* 007aac1d  FUN_007aac1d  417 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007aac1d(void)

{
  CSimpleStringT<wchar_t,0> *pCVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int *in_ECX;
  int *piVar6;
  UINT in_stack_ffffffd4;
  LPSTR in_stack_ffffffd8;
  int in_stack_ffffffdc;
  int local_1c;
  undefined4 local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7aac29;
  pcVar2 = *(code **)(*in_ECX + 0x60);
  guard_check_icall();
  iVar3 = (*pcVar2)();
  if (iVar3 != 0) {
    piVar6 = (int *)0x0;
    iVar3 = FUN_0079dd6d();
    if (*(int *)(iVar3 + 4) != 0) {
      iVar3 = FUN_0079dd6d();
      pcVar2 = *(code **)(**(int **)(iVar3 + 4) + 0xfc);
      guard_check_icall();
      piVar6 = (int *)(*pcVar2)();
      if (piVar6 != (int *)0x0) {
        pcVar2 = *(code **)(*piVar6 + 0x30);
        guard_check_icall();
        iVar3 = (*pcVar2)();
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
    CStringT<>();
    local_8 = 0;
    pCVar1 = (CSimpleStringT<wchar_t,0> *)(in_ECX + 9);
    if (*(int *)(*(int *)pCVar1 + -0xc) == 0) {
      ATL::CSimpleStringT<wchar_t,0>::operator=
                ((CSimpleStringT<wchar_t,0> *)local_14,(CSimpleStringT<wchar_t,0> *)(in_ECX + 8));
      if (piVar6 != (int *)0x0) {
        pcVar2 = *(code **)(*piVar6 + 0x74);
        guard_check_icall(&local_1c);
        (*pcVar2)();
        local_8._0_1_ = 1;
        if (*(int *)(local_1c + -0xc) != 0) {
          ATL::CSimpleStringT<wchar_t,0>::operator=
                    ((CSimpleStringT<wchar_t,0> *)local_14,(CSimpleStringT<wchar_t,0> *)&local_1c);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00406b10();
      }
      iVar3 = local_14[0];
      if ((*(int *)(local_14[0] + -0xc) == 0) &&
         (iVar4 = FID_conflict_LoadStringA
                            ((HINSTANCE)0xf003,in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc
                            ), iVar3 = local_14[0], iVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
    }
    else {
      ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)local_14,pCVar1);
      pcVar5 = ATL::CSimpleStringT<char,0>::PrepareWrite((CSimpleStringT<char,0> *)local_14,0x104);
      FUN_007a7375(*(undefined4 *)pCVar1,pcVar5,0x104);
      ReleaseBuffer(0xffffffff);
      iVar3 = local_14[0];
    }
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_007c1390(&local_18,0xf103,iVar3);
    iVar3 = FUN_0079f557(local_18,3,0xf103);
    if (iVar3 == 2) {
LAB_007aad86:
      FUN_00406b10();
      FUN_00406b10();
      return 0;
    }
    if (iVar3 == 6) {
      pcVar2 = *(code **)(*in_ECX + 0xe4);
      guard_check_icall();
      iVar3 = (*pcVar2)();
      if (iVar3 == 0) goto LAB_007aad86;
    }
    FUN_00406b10();
    FUN_00406b10();
  }
  return 1;
}




/* vtable slots: CJw_winDoc[47], CMiniDoc[47] */
/* 007aae5f  FUN_007aae5f  134 bytes, 0 callers */

undefined4 FUN_007aae5f(CObject *param_1)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  
  if (param_1 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)param_1 + 8);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0xcc);
      pcVar2 = *(code **)(*(int *)param_1 + 0x24);
      guard_check_icall();
      uVar4 = (*pcVar2)();
      pcVar2 = *(code **)(*(int *)param_1 + 0x20);
      guard_check_icall();
      uVar5 = (*pcVar2)();
      guard_check_icall(uVar5,uVar4);
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        CObList::AddTail((CObList *)(in_ECX + 0x1e),param_1);
      }
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CJw_winDoc[22], CMiniDoc[22] */
/* 007aafa5  FUN_007aafa5  232 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007aafa5(int param_1,int param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  undefined1 local_410 [512];
  wchar_t local_210 [260];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  uVar2 = FUN_008f899d(param_1);
  if (uVar2 < 0x104) {
    iVar3 = FUN_007a7361(local_210,param_1);
    if (iVar3 != 0) {
      iVar3 = FUN_008f899d(local_210);
      ATL::CSimpleStringT<wchar_t,0>::SetString
                ((CSimpleStringT<wchar_t,0> *)(in_ECX + 9),local_210,iVar3);
      in_ECX[0x28] = 0;
      iVar3 = FUN_007a7375(local_210,local_410,0x100);
      if (iVar3 == 0) {
        pcVar1 = *(code **)(*in_ECX + 0x54);
        guard_check_icall(local_410);
        (*pcVar1)();
      }
      if (param_2 != 0) {
        iVar3 = FUN_0079dd6d();
        pcVar1 = *(code **)(**(int **)(iVar3 + 4) + 0xa8);
        guard_check_icall(*(undefined4 *)(in_ECX + 9));
        (*pcVar1)();
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_007a6c8a(3,0xffffffff,param_1);
}




/* vtable slots: CJw_winDoc[21], CMiniDoc[21] */
/* 007ab1cd  FUN_007ab1cd  63 bytes, 0 callers */

void FUN_007ab1cd(wchar_t *param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 == (wchar_t *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008f899d(param_1);
  }
  ATL::CSimpleStringT<wchar_t,0>::SetString((CSimpleStringT<wchar_t,0> *)(in_ECX + 8),param_1,iVar2)
  ;
  pcVar1 = *(code **)(*in_ECX + 0xe8);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CJw_winDoc[58], CMiniDoc[58] */
/* 007ab405  FUN_007ab405  336 bytes, 0 callers */

void FUN_007ab405(void)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  int local_c;
  int local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x68);
  guard_check_icall();
  local_8 = (*pcVar1)();
  while (local_8 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x6c);
    guard_check_icall(&local_8);
    iVar2 = (*pcVar1)();
    BVar3 = IsWindowVisible(*(HWND *)(iVar2 + 0x20));
    if ((BVar3 != 0) && (iVar2 = FUN_0079296c(), iVar2 != 0)) {
      *(undefined4 *)(iVar2 + 0x84) = 0xffffffff;
    }
  }
  iVar2 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x68);
  guard_check_icall();
  local_8 = (*pcVar1)();
  while (local_8 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x6c);
    guard_check_icall(&local_8);
    iVar4 = (*pcVar1)();
    BVar3 = IsWindowVisible(*(HWND *)(iVar4 + 0x20));
    if (((BVar3 != 0) && (iVar4 = FUN_0079296c(), iVar4 != 0)) && (*(int *)(iVar4 + 0x84) == -1)) {
      iVar2 = iVar2 + 1;
      *(int *)(iVar4 + 0x84) = iVar2;
    }
  }
  local_c = 1;
  pcVar1 = *(code **)(*in_ECX + 0x68);
  guard_check_icall();
  local_8 = (*pcVar1)();
  while (local_8 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x6c);
    guard_check_icall(&local_8);
    iVar4 = (*pcVar1)();
    BVar3 = IsWindowVisible(*(HWND *)(iVar4 + 0x20));
    if (((BVar3 != 0) && (piVar5 = (int *)FUN_0079296c(), piVar5 != (int *)0x0)) &&
       (piVar5[0x21] == local_c)) {
      if (iVar2 == 1) {
        piVar5[0x21] = 0;
      }
      pcVar1 = *(code **)(*piVar5 + 0x1a4);
      guard_check_icall(1);
      (*pcVar1)();
      local_c = local_c + 1;
    }
  }
  return;
}



