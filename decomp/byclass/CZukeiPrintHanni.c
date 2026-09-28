/* CZukeiPrintHanni -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiPrintHanni[1] */
/* 006d0f90  FUN_006d0f90  68 bytes, 0 callers */

undefined4 FUN_006d0f90(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006d0f10();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x11e0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiPrintHanni[6] */
/* 006d12a0  FUN_006d12a0  1036 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d12a0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093df7b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00a0c784 = 1;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(local_63e8[1] + 0x8644)) {
    if (local_63e8[0x344] != *(int *)(local_63e8[1] + 0x3048)) {
      local_63e8[0x344] = *(int *)(local_63e8[1] + 0x3048);
      iVar2 = local_63e8[1];
      FUN_00404c80(uVar1);
      iVar3 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0x2d8) = *(undefined4 *)(iVar2 + 0x3048);
      FUN_00404c80();
      FUN_004fca20();
      FUN_00550370();
    }
    if (*(double *)(local_63e8 + 0x3b2) != *(double *)(local_63e8[1] + 0x3028)) {
      *(undefined8 *)(local_63e8 + 0x3b2) = *(undefined8 *)(local_63e8[1] + 0x3028);
      FUN_00404c80(uVar1);
      FUN_004fca20();
      FUN_005adde0();
    }
    if (*(int *)(local_63e8[1] + 0x8560) == 0) {
      FUN_004efbb0(0x14d6,0,0);
      uVar4 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_007979e8(uVar4);
      uVar4 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_007979e8(uVar4);
      uVar4 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_007979e8(uVar4);
    }
    if (*(int *)(local_63e8[1] + 0x8560) == 1) {
      FUN_004efbb0(0x14d7,0,0);
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar4);
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar4);
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_007979e8(uVar4);
    }
    FUN_00446aa0();
    local_8 = 0;
    FUN_0040c0e0();
    FUN_0079dea2(local_63e8[1]);
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)(*local_63e8 + 0x20))();
    FUN_0044dd90(local_6404,local_63e8[1]);
    if (*(int *)(local_63e8[1] + 0x8560) != 0) {
      FUN_0044dd20(local_6404,local_63e8[1]);
      for (local_63ec = 0; local_63ec < 4; local_63ec = local_63ec + 1) {
        FUN_00450b70(local_6404,local_63e8[1],local_63e8 + local_63ec * 0x1a + 0x346);
      }
    }
    iVar2 = FUN_0045af10(local_63e8[1]);
    if ((iVar2 == 0) && (*(int *)(local_63e8[1] + 0x8560) == 0)) {
      for (local_63f0 = 0; local_63f0 < 4; local_63f0 = local_63f0 + 1) {
        FUN_00450af0(local_6404,local_63e8[1],local_63e8 + local_63f0 * 0x1a + 0x346);
      }
    }
    FUN_00404c80();
    FUN_004fca20();
    FUN_005ae8a0();
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiPrintHanni[16] */
/* 006d16b0  FUN_006d16b0  287 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006d16b0(void)

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
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8560) < 1) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd20(local_6400,*(undefined4 *)(local_63e8 + 4));
    FUN_00458a80(local_6400,*(undefined4 *)(local_63e8 + 4),0);
    FUN_00404c80();
    FUN_0056d7d0();
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    local_63ec = 1;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiPrintHanni[0] */
/* 006d17d0  FUN_006d17d0  16 bytes, 0 callers */

undefined ** FUN_006d17d0(void)

{
  return &PTR_s_CZukeiPrintHanni_00979f6c;
}




/* vtable slots: CZukeiPrintHanni[34] */
/* 006d1930  FUN_006d1930  298 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d1930(void)

{
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b0f6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6404,*(undefined4 *)(local_63e8 + 4));
  local_63ec = *(int *)(local_63e8 + 4);
  if (local_63ec == 0) {
    local_63f0 = 0;
  }
  else {
    local_63f0 = local_63ec + 0x88;
  }
  FUN_0060b020(local_63f0,*(undefined4 *)(local_63e8 + 4),0);
  local_8._0_1_ = 2;
  FUN_004578a0(0);
  local_8._0_1_ = 1;
  FUN_0060b110();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiPrintHanni[25] */
/* 006d1a60  FUN_006d1a60  119 bytes, 0 callers */

void FUN_006d1a60(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  FUN_004e96f0(0x204,0,*(int *)(*(int *)(in_ECX + 4) + 0x8f5c) << 0x10 |
                       *(uint *)(*(int *)(in_ECX + 4) + 0x8f58));
  FUN_004e96f0(0x205,0,*(int *)(*(int *)(in_ECX + 4) + 0x8f5c) << 0x10 |
                       *(uint *)(*(int *)(in_ECX + 4) + 0x8f58));
  return;
}




/* vtable slots: CZukeiPrintHanni[26] */
/* 006d1ae0  FUN_006d1ae0  2353 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d1ae0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined2 *extraout_ECX;
  undefined4 uStack_69b0;
  undefined4 uStack_69ac;
  undefined1 *puStack_69a8;
  wchar_t *pwStack_69a4;
  undefined1 *puStack_69a0;
  undefined2 *puStack_699c;
  undefined2 local_6990 [10];
  undefined1 *local_697c;
  undefined4 local_6978;
  undefined1 *local_6974;
  undefined1 *local_6970;
  undefined8 local_696c;
  undefined1 local_6964 [4];
  int local_6960;
  int local_695c;
  undefined4 local_6958;
  undefined4 local_6954;
  undefined4 local_6950;
  undefined4 local_694c;
  int local_6948;
  int local_6944;
  undefined4 local_693c;
  undefined4 local_6938;
  int local_6934;
  int local_6930;
  undefined4 local_692c;
  int local_6928;
  int local_6924;
  int local_6920;
  int local_691c;
  int local_6918;
  int local_6914;
  int local_6910;
  undefined2 local_690c [2];
  int *local_6908;
  undefined1 local_6904 [4];
  int local_6900;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  wchar_t *local_24;
  int local_20;
  undefined2 *local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e002;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8560) != 0) {
    return;
  }
  ExceptionList = &local_10;
  local_6900 = in_ECX;
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) != *(int *)(*(int *)(local_6900 + 4) + 0x8644)) {
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(local_6900 + 0xed0) = 0;
  if ((DAT_00a0cc74 != 0) || (DAT_00a0cc6c != 0)) {
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    *(undefined4 *)(local_6900 + 0xed0) = 1;
  }
  if (*(int *)(local_6900 + 0xa8) < 1) {
    FUN_006d4920();
  }
  else {
    local_694c = DAT_00a0cab0;
    local_6950 = DAT_00a0cab4;
    DAT_00a0cab0 = 1;
    DAT_00a0cab4 = 1;
    local_696c = *(undefined8 *)(*(int *)(local_6900 + 4) + 0x3028);
    iVar2 = *(int *)(local_6900 + 4);
    local_24 = *(wchar_t **)(iVar2 + 0x3038);
    local_20 = *(int *)(iVar2 + 0x303c);
    local_1c = *(undefined2 **)(iVar2 + 0x3040);
    local_18 = *(undefined4 *)(iVar2 + 0x3044);
    local_692c = *(undefined4 *)(*(int *)(local_6900 + 4) + 0x3030);
    puStack_699c = (undefined2 *)0x6d1c39;
    FUN_006d17e0();
    puStack_699c = (undefined2 *)0x6d1c46;
    FUN_006d0fe0();
    local_6914 = 0;
    local_6918 = 0;
    local_691c = 0;
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 200) != 0) {
      local_6914 = 1;
    }
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xcc) != 0) {
      local_6918 = 1;
    }
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xd0) != 0) {
      local_691c = 1;
    }
    local_6920 = 1;
    FUN_00446aa0();
    local_8 = 0;
    puStack_699c = (undefined2 *)0x6d1d04;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    local_6908 = (int *)FUN_0040c0e0();
    FUN_0044f310();
    puStack_699c = (undefined2 *)0x6d1d33;
    FUN_00403dd0();
    local_8._0_1_ = 2;
    puStack_699c = (undefined2 *)0x6d1d48;
    FUN_00404860();
    iVar2 = (**(code **)(*local_6908 + 0x60))();
    if (iVar2 != 0) {
      puStack_699c = (undefined2 *)0x4;
      puStack_69a0 = (undefined1 *)0x15fc;
      pwStack_69a4 = L"薉隤\xffff붃隤\xffff理\xe905ƴ";
      local_6960 = FUN_004f60a0();
      if (local_6960 == 6) {
        local_6970 = (undefined1 *)&puStack_699c;
        puStack_69a0 = local_6904;
        pwStack_69a4 = L"薋霄\xffff䢋脄裁";
        puStack_699c = extraout_ECX;
        FUN_00403dd0();
        puStack_69a0 = (undefined1 *)0x6d1db5;
        local_695c = FUN_004be180();
        if (local_695c == 0) {
          puStack_699c = (undefined2 *)0x0;
          puStack_69a0 = (undefined1 *)0x0;
          pwStack_69a4 = L"Jww|*.JWW|Jwc|*.JWC|Dxf|*.DXF|";
          puStack_69a8 = (undefined1 *)0x6;
          uStack_69ac = 0x6d1de1;
          uStack_69ac = FUN_00404920();
          local_6974 = (undefined1 *)&uStack_69b0;
          FUN_00403dd0(local_6904);
          local_6958 = FUN_0044ec60(local_6964);
          local_8._0_1_ = 3;
          uStack_69b0 = 0x6d1e2a;
          local_6954 = local_6958;
          uStack_69b0 = FUN_00404920();
          local_6978 = FUN_007b3573(0);
          local_8._0_1_ = 5;
          FUN_00404540();
          iVar2 = FUN_007b3f8f();
          if (iVar2 != 1) {
            local_8._0_1_ = 2;
            FUN_007b384d();
            local_8._0_1_ = 1;
            FUN_00404540();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            goto LAB_006d23ef;
          }
          puStack_699c = (undefined2 *)0x6d1eac;
          SetCurrentDirectoryW((LPCWSTR)&DAT_00a08f74);
          puStack_699c = (undefined2 *)0x6d1ebe;
          local_693c = FUN_007b4284();
          local_8._0_1_ = 6;
          puStack_699c = (undefined2 *)0x6d1ee6;
          local_6938 = local_693c;
          FUN_00404860();
          local_8._0_1_ = 5;
          FUN_00404540();
          puStack_699c = (undefined2 *)0x6d1f02;
          puStack_699c = (undefined2 *)FUN_00404920();
          puStack_69a0 = (undefined1 *)0x6d1f19;
          (**(code **)(*local_6908 + 0xe0))();
          local_8._0_1_ = 2;
          FUN_007b384d();
        }
      }
    }
    local_6944 = *(int *)(DAT_00a0b410 + 0x4322);
    iVar2 = FUN_004146c0();
    if ((iVar2 == 0) && (*(int *)(local_6944 + 0xd4) == 0)) {
      FUN_006d2890();
      local_6920 = FUN_006d4920();
    }
    if (0 < local_6920) {
      (**(code **)(*local_6908 + 0x78))();
      for (local_6910 = 0; local_6910 < *(int *)(local_6900 + 0xa8); local_6910 = local_6910 + 1) {
        puStack_699c = (undefined2 *)0x6d2001;
        FUN_00403dd0();
        local_8._0_1_ = 7;
        puStack_699c = local_690c;
        puStack_69a0 = (undefined1 *)0x6d2018;
        cVar1 = FUN_00414010();
        if (cVar1 == '\0') {
          if (local_6914 != 0) {
            *(undefined4 *)(DAT_00a0b410 + 0x42ae) = 1;
          }
          local_697c = &stack0xffff9668;
          puStack_699c = local_690c;
          puStack_69a0 = (undefined1 *)0x6d2061;
          FUN_00403dd0();
          puStack_699c = DAT_00a0b410;
          puStack_69a0 = (undefined1 *)0x6d2071;
          local_6948 = FUN_004dd3e0();
          if (local_6948 != 0) {
            *(undefined4 *)(DAT_00a0b410 + 0x42ae) = 0;
            if (local_6914 != 0) {
              *(undefined8 *)(*(int *)(local_6900 + 4) + 0x3028) = local_696c;
              pwStack_69a4 = local_24;
              puStack_69a0 = (undefined1 *)local_20;
              puStack_699c = local_1c;
              puStack_69a8 = local_44;
              uStack_69ac = 0x6d20ea;
              FUN_004988c0();
              *(undefined4 *)(*(int *)(local_6900 + 4) + 0x3030) = local_692c;
            }
            FUN_00404c80();
            FUN_004fca20();
            FUN_005adde0();
            if (local_691c != 0) {
              puStack_699c = (undefined2 *)0x6d212c;
              FUN_006d0fe0();
            }
            if (local_6918 == 0) {
              puStack_699c = (undefined2 *)0x8057;
              puStack_69a0 = (undefined1 *)0x111;
              pwStack_69a4 = L"좋铨\xe175櫿栀聙";
              FUN_00404c80();
              pwStack_69a4 = L"j奨\x80栀đ";
              FUN_004e96f0();
              puStack_699c = (undefined2 *)0x8059;
              puStack_69a0 = (undefined1 *)0x111;
              pwStack_69a4 = 
              L"좋糨\xe175菿\xecbdﾖÿॵ붃雨\xffff琀譞҅ﾗ诿ш趉雠\xffff붃雠\xffff琀謔\xe095ﾖ臿裂"
              ;
              FUN_00404c80();
              pwStack_69a4 = 
              L"붃雬\xffff甀茉\xe8bdﾖÿ年薋霄\xffff䢋褄\xe08dﾖ菿\xe0bdﾖÿᑴ開雠\xffff슁\x88"
              ;
              FUN_004e96f0();
            }
            else {
              puStack_699c = (undefined2 *)0x6d2142;
              FUN_006d17e0();
            }
            if ((local_6918 != 0) || (local_691c != 0)) {
              local_6924 = *(int *)(local_6900 + 4);
              if (local_6924 == 0) {
                local_6928 = 0;
              }
              else {
                local_6928 = local_6924 + 0x88;
              }
              FUN_0040c0e0();
              puStack_699c = local_6990;
              puStack_69a0 = (undefined1 *)local_6928;
              pwStack_69a4 = L"趋霄\xffffꇨ\x06謀ҍﾗ\xe8ff✦";
              FUN_0044b760();
            }
            FUN_006d2890();
            iVar2 = FUN_006d4920();
            if (iVar2 < 0) {
              local_8._0_1_ = 2;
              FUN_00404540();
              break;
            }
          }
          local_8._0_1_ = 2;
          FUN_00404540();
        }
        else {
          local_8._0_1_ = 2;
          FUN_00404540();
        }
      }
      DAT_00a0cab0 = 1;
      DAT_00a0cab4 = 1;
      puStack_699c = &DAT_00956338;
      puStack_69a0 = (undefined1 *)0x6d2248;
      cVar1 = FUN_004640c0();
      if (cVar1 == '\0') {
        FUN_004e8be0();
      }
      else {
        FUN_00404920();
        puStack_699c = (undefined2 *)0x6d2268;
        FUN_004e8d60();
        puStack_699c = (undefined2 *)0x6d2277;
        FUN_00404900();
      }
      *(undefined8 *)(*(int *)(local_6900 + 4) + 0x3028) = local_696c;
      pwStack_69a4 = local_24;
      puStack_69a0 = (undefined1 *)local_20;
      puStack_699c = local_1c;
      puStack_69a8 = local_34;
      uStack_69ac = 0x6d22d0;
      FUN_004988c0();
      *(undefined4 *)(*(int *)(local_6900 + 4) + 0x3030) = local_692c;
      FUN_00404c80();
      FUN_004fca20();
      FUN_005adde0();
      puStack_699c = (undefined2 *)0x6d2309;
      FUN_006d17e0();
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xd4) == 0) {
        local_6930 = *(int *)(local_6900 + 4);
        if (local_6930 == 0) {
          local_6934 = 0;
        }
        else {
          local_6934 = local_6930 + 0x88;
        }
        FUN_0040c0e0();
        puStack_699c = local_6990;
        puStack_69a0 = (undefined1 *)local_6934;
        pwStack_69a4 = 
        L"趋隸\xffffඉ쪰\xa0開隴\xffffᖉ쪴\xa0趋霄\xffff\xeae8\x04였ﱅ贁\x8dﾗ\xe8ff↋ￓ䗆ü趍陴\xffff㯨಼윀ﱅ\xffff\xffff趍霈\xffff⫨흍\xebff謋ҍﾗ\xe8ff┽"
        ;
        FUN_0044b760();
      }
      DAT_00a0cab0 = local_694c;
      DAT_00a0cab4 = local_6950;
    }
    FUN_006d2890();
    local_8._0_1_ = 1;
    FUN_00404540();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  FUN_00404c80();
  FUN_0056d7d0();
LAB_006d23ef:
  *(undefined4 *)(DAT_00a0b410 + 0x4870) = 0;
  FUN_00516f70();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiPrintHanni[27] */
/* 006d2430  FUN_006d2430  291 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d2430(void)

{
  uint uVar1;
  int iVar2;
  undefined1 local_63fc [20];
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(local_63e8[1] + 0x8644)) {
    FUN_00404c80(uVar1);
    iVar2 = FUN_004fca20();
    *(undefined4 *)(local_63e8[1] + 0x3048) = *(undefined4 *)(*(int *)(iVar2 + 0x1a0) + 0x2d8);
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(local_63e8[1]);
  local_8._0_1_ = 1;
  FUN_0044dd20(local_63fc,local_63e8[1]);
  (**(code **)(*local_63e8 + 0x18))(local_63e8[1] + 0x8f78);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiPrintHanni[29] */
/* 006d2560  FUN_006d2560  532 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d2560(void)

{
  undefined4 *puVar1;
  undefined1 local_6488 [20];
  int local_6474;
  int local_6470;
  undefined4 local_174;
  undefined1 local_9c [104];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e056;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6474 + 4));
  local_8._0_1_ = 1;
  FUN_0041f760();
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004552a0(local_9c);
  FUN_0044dd20(local_6488,*(undefined4 *)(local_6474 + 4));
  for (local_6470 = 0; local_6470 < 4; local_6470 = local_6470 + 1) {
    puVar1 = (undefined4 *)(local_6474 + 0xd20 + local_6470 * 0x68);
    FUN_004988c0(local_24,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    puVar1 = (undefined4 *)(local_6474 + 0xd30 + local_6470 * 0x68);
    FUN_004988c0(local_34,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    FUN_00450860(local_6488,*(undefined4 *)(local_6474 + 4),local_9c,1,1);
    local_174 = 1;
  }
  for (local_6470 = 0; local_6470 < 4; local_6470 = local_6470 + 1) {
    FUN_00450b70(local_6488,*(undefined4 *)(local_6474 + 4),local_6474 + 0xd18 + local_6470 * 0x68);
  }
  local_8._0_1_ = 1;
  FUN_0041fd70();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiPrintHanni[31] */
/* 006d2780  FUN_006d2780  264 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d2780(void)

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
  *(int *)(*(int *)(in_ECX + 4) + 0x3030) = *(int *)(*(int *)(in_ECX + 4) + 0x3030) + 1;
  if (2 < *(int *)(*(int *)(in_ECX + 4) + 0x3030)) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x3030) = 0;
  }
  local_63e8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd20(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiPrintHanni[9] */
/* 006d29d0  FUN_006d29d0  151 bytes, 1 callers */

bool FUN_006d29d0(undefined4 param_1,double param_2,double param_3)

{
  int *in_ECX;
  bool bVar1;
  
  bVar1 = *(int *)(in_ECX[1] + 0x8560) == 0;
  if (!bVar1) {
    *(double *)(in_ECX[1] + 0x3038) = param_2 - *(double *)(in_ECX + 0x3ae);
    *(double *)(in_ECX[1] + 0x3040) = param_3 - *(double *)(in_ECX + 0x3b0);
    *(undefined4 *)(in_ECX[1] + 0x8560) = 0;
    (**(code **)(*in_ECX + 0x18))(&param_2);
    FUN_00517a30();
  }
  return bVar1;
}




/* vtable slots: CZukeiPrintHanni[11] */
/* 006d2a70  FUN_006d2a70  562 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006d2a70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined1 local_6410 [8];
  undefined4 local_6408;
  undefined4 local_6404;
  undefined4 local_6400;
  int local_63fc;
  int *local_63f8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009367d0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  local_63fc = *(int *)(local_63f8[1] + 0x8560);
  if (local_63fc == 0) {
    *(double *)(local_63f8[1] + 0x8f78) =
         *(double *)(local_63f8[1] + 0x3038) + *(double *)(local_63f8 + 0x3ae);
    *(double *)(local_63f8[1] + 0x8f80) =
         *(double *)(local_63f8[1] + 0x3040) + *(double *)(local_63f8 + 0x3b0);
    iVar1 = local_63f8[1];
    FUN_004fd520(local_6410,*(undefined4 *)(iVar1 + 0x8f78),*(undefined4 *)(iVar1 + 0x8f7c),
                 *(undefined4 *)(iVar1 + 0x8f80),*(undefined4 *)(iVar1 + 0x8f84));
    *(undefined4 *)(local_63f8[1] + 0x8560) = 1;
    (**(code **)(*local_63f8 + 0x18))(local_63f8[1] + 0x8f78);
    local_6400 = 0;
    local_8 = 0xffffffff;
    FUN_00447100();
    local_6404 = local_6400;
  }
  else {
    iVar1 = FUN_00451eb0(local_63f8[1],&local_24,1);
    if (iVar1 == 1) {
      FUN_00517a30();
      local_6404 = FUN_006d29d0(param_1,local_24,local_20,local_1c,local_18);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_6408 = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6404 = local_6408;
    }
  }
  ExceptionList = local_10;
  return local_6404;
}




/* vtable slots: CZukeiPrintHanni[8] */
/* 006d2cb0  FUN_006d2cb0  1647 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d2cb0(void)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int local_6454;
  int local_6450;
  int local_644c;
  undefined1 local_74 [16];
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  double local_34;
  double local_2c;
  undefined8 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e090;
  local_10 = ExceptionList;
  uVar4 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  FUN_00404c80(uVar4);
  iVar5 = FUN_004fca20();
  if (*(int *)(iVar5 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8644)) {
    iVar5 = *(int *)(*(int *)(in_ECX + 4) + 0x8560);
    local_644c = (int)((double)(*(int *)(*(int *)(in_ECX + 4) + 0x8f08) / 2) /
                      *(double *)(*(int *)(in_ECX + 4) + 0x3028));
    iVar6 = (int)((double)(*(int *)(*(int *)(in_ECX + 4) + 0x8f0c) / 2) /
                 *(double *)(*(int *)(in_ECX + 4) + 0x3028));
    local_6450 = iVar6;
    if (*(int *)(*(int *)(in_ECX + 4) + 0x3030) != 0) {
      local_6450 = local_644c;
      local_644c = iVar6;
    }
    FUN_00404c80(uVar4);
    iVar6 = FUN_004fca20();
    switch(*(undefined4 *)(*(int *)(iVar6 + 0x1a0) + 0x2d8)) {
    case 0:
    case 3:
    case 6:
      *(double *)(in_ECX + 0xeb8) = (double)-local_644c;
      break;
    case 1:
    case 4:
    case 7:
      *(undefined8 *)(in_ECX + 0xeb8) = 0;
      break;
    default:
      *(double *)(in_ECX + 0xeb8) = (double)local_644c;
    }
    FUN_00404c80();
    iVar6 = FUN_004fca20();
    switch(*(undefined4 *)(*(int *)(iVar6 + 0x1a0) + 0x2d8)) {
    case 0:
    case 1:
    case 2:
      *(double *)(in_ECX + 0xec0) = (double)-local_6450;
      break;
    case 3:
    case 4:
    case 5:
      *(undefined8 *)(in_ECX + 0xec0) = 0;
      break;
    default:
      *(double *)(in_ECX + 0xec0) = (double)local_6450;
    }
    FUN_00408a60();
    if (iVar5 == 0) {
      iVar5 = *(int *)(in_ECX + 4);
      FUN_004988c0(local_44,*(undefined4 *)(iVar5 + 0x3038),*(undefined4 *)(iVar5 + 0x303c),
                   *(undefined4 *)(iVar5 + 0x3040),*(undefined4 *)(iVar5 + 0x3044));
    }
    else {
      local_34 = *(double *)(*(int *)(in_ECX + 4) + 0x8f78) - *(double *)(in_ECX + 0xeb8);
      local_2c = *(double *)(*(int *)(in_ECX + 4) + 0x8f80) - *(double *)(in_ECX + 0xec0);
    }
    *(double *)(in_ECX + 0x10) = local_34 - (double)local_644c;
    *(double *)(in_ECX + 0x18) = local_2c - (double)local_6450;
    *(double *)(in_ECX + 0x20) = (double)(local_644c << 1) + *(double *)(in_ECX + 0x10);
    *(double *)(in_ECX + 0x28) = (double)(local_6450 << 1) + *(double *)(in_ECX + 0x18);
    FUN_00446aa0();
    local_8 = 0;
    for (local_6454 = 0; local_6454 < 4; local_6454 = local_6454 + 1) {
      FUN_004552a0(in_ECX + 0xd18 + local_6454 * 0x68);
      *(undefined1 *)(in_ECX + 0xd40 + local_6454 * 0x68) = 1;
      *(undefined2 *)(in_ECX + 0xd42 + local_6454 * 0x68) = 1;
    }
    FUN_00408a60();
    FUN_004988c0(local_54,*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),
                 *(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c));
    FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
    uVar1 = *(undefined8 *)(in_ECX + 0x20);
    local_24._0_4_ = (undefined4)uVar1;
    local_24._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar2 = local_24._4_4_;
    uVar3 = (undefined4)local_24;
    local_24 = uVar1;
    FUN_0040da20(uVar3,uVar2,local_1c,local_18);
    FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
    FUN_004988c0(local_64,*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24),
                 *(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(in_ECX + 0x2c));
    FUN_0040da20((undefined4)local_24,local_24._4_4_,local_1c,local_18);
    FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
    uVar1 = *(undefined8 *)(in_ECX + 0x10);
    local_24._0_4_ = (undefined4)uVar1;
    local_24._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar2 = local_24._4_4_;
    uVar3 = (undefined4)local_24;
    local_24 = uVar1;
    FUN_0040da20(uVar3,uVar2,local_1c,local_18);
    FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
    FUN_004988c0(local_74,*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),
                 *(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c));
    FUN_0040da20((undefined4)local_24,local_24._4_4_,local_1c,local_18);
    FUN_0040da70((undefined4)local_24,local_24._4_4_,local_1c,local_18);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiPrintHanni[4] */
/* 006d3360  FUN_006d3360  308 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d3360(void)

{
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b0f6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6404,*(undefined4 *)(local_63e8 + 4));
  DAT_00a0c784 = 0;
  local_63ec = *(int *)(local_63e8 + 4);
  if (local_63ec == 0) {
    local_63f0 = 0;
  }
  else {
    local_63f0 = local_63ec + 0x88;
  }
  FUN_0060b020(local_63f0,*(undefined4 *)(local_63e8 + 4),0);
  local_8._0_1_ = 2;
  FUN_004578a0(0);
  local_8._0_1_ = 1;
  FUN_0060b110();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiPrintHanni[3] */
/* 006d34a0  FUN_006d34a0  201 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006d34a0(void)

{
  undefined1 local_63fc [20];
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(local_63e8[1]);
  local_8._0_1_ = 1;
  FUN_0044dd20(local_63fc,local_63e8[1]);
  (**(code **)(*local_63e8 + 0x68))();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



