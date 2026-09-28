/* CJw_winView -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CJw_winView[0] */
/* 004faa6f  FUN_004faa6f  11 bytes, 0 callers */

void FUN_004faa6f(void)

{
  FUN_004faa80();
  return;
}




/* vtable slots: CJw_winView[1] */
/* 004faa80  FUN_004faa80  68 bytes, 1 callers */

undefined4 FUN_004faa80(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004f9bb0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x9428);
    }
  }
  return in_ECX;
}




/* vtable slots: CJw_winView[10] */
/* 004fcbf0  FUN_004fcbf0  16 bytes, 0 callers */

void FUN_004fcbf0(void)

{
  FUN_004fcda0();
  return;
}




/* vtable slots: CJw_winView[1] */
/* 004fcc00  FUN_004fcc00  25 bytes, 0 callers */

void FUN_004fcc00(void)

{
  FUN_0040c0e0();
  return;
}




/* vtable slots: CJw_winView[0] */
/* 004fcd40  FUN_004fcd40  16 bytes, 0 callers */

undefined ** FUN_004fcd40(void)

{
  return &PTR_s_CJw_winView_00963ef8;
}




/* vtable slots: CJw_winView[100] */
/* 00501f60  FUN_00501f60  157 bytes, 0 callers */

void FUN_00501f60(int param_1,undefined4 param_2,undefined4 param_3)

{
  BOOL BVar1;
  tagMSG local_2c;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1 != 0) {
    local_10 = FUN_004fc9b0();
    *(int *)(local_c + 0x8530) = local_10;
    if ((local_10 == 0) && (BVar1 = PeekMessageW(&local_2c,(HWND)0x0,0x201,0x20e,0), BVar1 != 0)) {
      local_8 = local_2c.message - 0x201;
      switch(local_8) {
      case 0:
      case 1:
      case 2:
        *(undefined4 *)(local_c + 0x17e8) = 1;
        break;
      case 3:
      case 4:
      case 5:
        *(undefined4 *)(local_c + 0x17ec) = 1;
      }
    }
  }
  FUN_007b684c(param_1,param_2,param_3);
  return;
}




/* vtable slots: CJw_winView[103] */
/* 00503020  FUN_00503020  2043 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00503020(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  double dVar5;
  double dVar6;
  double local_64ec;
  int local_64cc;
  int local_64c8;
  undefined1 local_84 [16];
  undefined1 local_74 [16];
  undefined1 local_64 [48];
  CRect local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929956;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x90e0) == 0) {
    *(undefined4 *)(in_ECX + 0x8598) = 1;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_00464040();
    local_8._0_1_ = 1;
    FUN_004553a0();
    FUN_00413f30();
    FUN_00413f30();
    FUN_00413f30();
    std::allocator<char>::allocator<char>((allocator<char> *)(in_ECX + 0x84e4));
    FUN_00416570();
    CRect::NormalizeRect((CRect *)(in_ECX + 0x84e4));
    puVar1 = (undefined4 *)CRect::Size((CRect *)(in_ECX + 0x84e4));
    uVar3 = puVar1[1];
    *(undefined4 *)(in_ECX + 0x17a8) = *puVar1;
    *(undefined4 *)(in_ECX + 0x17ac) = uVar3;
    *(int *)(in_ECX + 0x17a8) = *(int *)(in_ECX + 0x17a8) / 2;
    *(int *)(in_ECX + 0x17ac) = *(int *)(in_ECX + 0x17ac) / 2;
    if (*(int *)(in_ECX + 0x84ec) == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004640a0();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      fVar4 = (float10)FUN_004b7630(*(undefined4 *)(in_ECX + 0x84e4),
                                    *(undefined4 *)(in_ECX + 0x84e8),
                                    *(undefined4 *)(in_ECX + 0x84ec),
                                    *(undefined4 *)(in_ECX + 0x84f0));
      *(double *)(in_ECX + 0x17f8) = (double)fVar4;
      *(int *)(in_ECX + 0x8f2c) = *(int *)(in_ECX + 0x84ec) + -0x50;
      local_24 = *(undefined4 *)(in_ECX + 0x84e4);
      local_20 = *(undefined4 *)(in_ECX + 0x84e8);
      local_1c = *(undefined4 *)(in_ECX + 0x84ec);
      local_18 = *(undefined4 *)(in_ECX + 0x84f0);
      iVar2 = FUN_004f72f0();
      *(double *)(in_ECX + 0x8ed0) =
           (((double)iVar2 / 10.0) * *(double *)(in_ECX + 0x17f8)) / *(double *)(in_ECX + 0x17b0);
      dVar5 = (((double)(*(int *)(in_ECX + 0x84ec) + 4) * *(double *)(in_ECX + 0x17f8)) /
              *(double *)(in_ECX + 0x17b0)) / 2.0;
      dVar6 = (((double)(*(int *)(in_ECX + 0x84f0) + 4) * *(double *)(in_ECX + 0x17f8)) /
              *(double *)(in_ECX + 0x17b0)) / 2.0;
      *(double *)(in_ECX + 0x7a80) = -dVar5 + *(double *)(in_ECX + 0x7aa0);
      *(double *)(in_ECX + 0x7a88) = -dVar6 + *(double *)(in_ECX + 0x7aa8);
      *(double *)(in_ECX + 0x7a90) = dVar5 + *(double *)(in_ECX + 0x7aa0);
      *(double *)(in_ECX + 0x7a98) = dVar6 + *(double *)(in_ECX + 0x7aa8);
      fVar4 = (float10)FUN_008f8d10(dVar5 * dVar5 + dVar6 * dVar6);
      *(double *)(in_ECX + 0x17b8) = (double)fVar4 * 2.0;
      if (*(char *)(in_ECX + 0x859c) != '\0') {
        if (*(int *)(in_ECX + 0x84c8) == 0) {
          (**(code **)(**(int **)(in_ECX + 0x8590) + 0x14))();
          if (*(int *)(in_ECX + 0x176c) != 0) {
            FUN_0041d3f0();
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_004640a0();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return;
        }
        FUN_00404c80();
        FUN_0056d200();
      }
      FUN_004bb4f0();
      dVar5 = (*(double *)(in_ECX + 0x17b0) * 1.0) / *(double *)(in_ECX + 0x17f8);
      iVar2 = FUN_004f72f0();
      if ((double)iVar2 <= dVar5) {
        uVar3 = FUN_004f72f0();
        *(undefined4 *)(in_ECX + 0x82c0) = uVar3;
      }
      else {
        *(int *)(in_ECX + 0x82c0) = (int)dVar5;
      }
      if (*(double *)(in_ECX + 0x1808) <= 0.0) {
        local_64ec = -*(double *)(in_ECX + 0x1808);
      }
      else {
        local_64ec = *(double *)(in_ECX + 0x1808);
      }
      _DAT_00a0ca70 =
           ((*(double *)(in_ECX + 0x1800) / local_64ec) * *(double *)(in_ECX + 0x17b0)) /
           *(double *)(in_ECX + 0x17f8);
      FUN_004b5a50();
      FUN_0041f760();
      local_8 = CONCAT31(local_8._1_3_,2);
      puVar1 = (undefined4 *)FUN_0041c8d0(0xffffffff,0);
      puVar1 = (undefined4 *)FUN_004b8a00(local_64,*puVar1,puVar1[1]);
      puVar1 = (undefined4 *)FUN_004988c0(local_74,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      FUN_004988c0(local_84,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      uVar3 = FUN_0040c0e0();
      FUN_00570750();
      if (in_ECX == 0) {
        local_64c8 = 0;
      }
      else {
        local_64c8 = in_ECX + 0x88;
      }
      FUN_0044b760(local_64c8,param_1,uVar3);
      FUN_00454810();
      if (in_ECX == 0) {
        local_64cc = 0;
      }
      else {
        local_64cc = in_ECX + 0x88;
      }
      FUN_0046e9c0(local_64cc,param_1);
      if (*(int *)(in_ECX + 0x8590) == 0) {
        FUN_004b7110();
      }
      else {
        FUN_0044c880(in_ECX,param_1);
        FUN_004b7110();
        FUN_00449de0();
        FUN_0044cc30(in_ECX,param_1);
        FUN_0044c720(in_ECX,param_1);
      }
      FUN_0044c610(in_ECX,param_1);
      if (*(int *)(in_ECX + 0x176c) != 0) {
        FUN_0041d3f0();
      }
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004640a0();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    FUN_00413f30();
    (**(code **)(*param_1 + 0x50))();
    CRect::NormalizeRect(local_34);
    FUN_004faa50();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CJw_winView[99] */
/* 00506900  FUN_00506900  4072 bytes, 0 callers */

void FUN_00506900(void)

{
  int iVar1;
  HDC__ *pHVar2;
  int *piVar3;
  CPrintDialog local_2e0 [276];
  undefined4 local_1cc;
  CDC local_1c8 [16];
  int local_1b8;
  int local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929f2f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007b6a49(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_14[0x2155] = local_14[8];
  FUN_004db970(local_14);
  if (local_14 == (int *)0x0) {
    local_1c = (int *)0x0;
  }
  else {
    local_1c = local_14 + 0x22;
  }
  iVar1 = FUN_00404c80();
  *(int **)(iVar1 + 0x14b0) = local_1c;
  FUN_00404c80();
  local_18 = FUN_004fca20();
  if (local_14[0x217b] == 0) {
    local_20 = FUN_004121b0(0x240);
    local_8 = 0;
    if (local_20 == 0) {
      local_24 = 0;
    }
    else {
      local_24 = FUN_004115b0(local_18);
    }
    local_1a8 = local_24;
    local_8 = 0xffffffff;
    local_14[0x217b] = local_24;
  }
  if (local_14[0x217c] == 0) {
    local_28 = FUN_004121b0(0xd60);
    local_8 = 1;
    if (local_28 == 0) {
      local_2c = 0;
    }
    else {
      local_2c = FUN_004aa880(local_18);
    }
    local_12c = local_2c;
    local_8 = 0xffffffff;
    local_14[0x217c] = local_2c;
  }
  if (local_14[0x217d] == 0) {
    local_34 = FUN_004121b0(0x810);
    local_8 = 2;
    if (local_34 == 0) {
      local_38 = 0;
    }
    else {
      if (local_14 == (int *)0x0) {
        local_30 = (int *)0x0;
      }
      else {
        local_30 = local_14 + 0x22;
      }
      local_38 = FUN_004b1910(local_18,local_30);
    }
    local_130 = local_38;
    local_8 = 0xffffffff;
    local_14[0x217d] = local_38;
  }
  if (local_14[0x217e] == 0) {
    local_3c = FUN_004121b0(0xc90);
    local_8 = 3;
    if (local_3c == 0) {
      local_40 = 0;
    }
    else {
      local_40 = FUN_004ac8d0(local_18);
    }
    local_134 = local_40;
    local_8 = 0xffffffff;
    local_14[0x217e] = local_40;
  }
  if (local_14[0x217f] == 0) {
    local_44 = FUN_004121b0(0x5e8);
    local_8 = 4;
    if (local_44 == 0) {
      local_48 = 0;
    }
    else {
      local_48 = FUN_004c87b0(local_18);
    }
    local_138 = local_48;
    local_8 = 0xffffffff;
    local_14[0x217f] = local_48;
  }
  if (local_14[0x2180] == 0) {
    local_4c = FUN_004121b0(0xee8);
    local_8 = 5;
    if (local_4c == 0) {
      local_50 = 0;
    }
    else {
      local_50 = FUN_00580020(local_18);
    }
    local_13c = local_50;
    local_8 = 0xffffffff;
    local_14[0x2180] = local_50;
  }
  if (local_14[0x2192] == 0) {
    local_54 = FUN_004121b0(0x550);
    local_8 = 6;
    if (local_54 == 0) {
      local_58 = 0;
    }
    else {
      local_58 = FUN_0056f560(local_18);
    }
    local_140 = local_58;
    local_8 = 0xffffffff;
    local_14[0x2192] = local_58;
  }
  if (local_14[0x2181] == 0) {
    local_5c = FUN_004121b0(0x3e0);
    local_8 = 7;
    if (local_5c == 0) {
      local_60 = 0;
    }
    else {
      local_60 = FUN_005cb400(local_18);
    }
    local_144 = local_60;
    local_8 = 0xffffffff;
    local_14[0x2181] = local_60;
  }
  if (local_14[0x2182] == 0) {
    local_64 = FUN_004121b0(0x6b0);
    local_8 = 8;
    if (local_64 == 0) {
      local_68 = 0;
    }
    else {
      local_68 = FUN_004c76e0(local_18);
    }
    local_148 = local_68;
    local_8 = 0xffffffff;
    local_14[0x2182] = local_68;
  }
  if (local_14[0x2183] == 0) {
    local_6c = FUN_004121b0(0x340);
    local_8 = 9;
    if (local_6c == 0) {
      local_70 = 0;
    }
    else {
      local_70 = FUN_004b2420(local_18);
    }
    local_14c = local_70;
    local_8 = 0xffffffff;
    local_14[0x2183] = local_70;
  }
  if (local_14[0x2184] == 0) {
    local_74 = FUN_004121b0(0xad0);
    local_8 = 10;
    if (local_74 == 0) {
      local_78 = 0;
    }
    else {
      local_78 = FUN_005c7d50(local_18,local_14);
    }
    local_150 = local_78;
    local_8 = 0xffffffff;
    local_14[0x2184] = local_78;
  }
  if (local_14[0x2185] == 0) {
    local_7c = FUN_004121b0(0x630);
    local_8 = 0xb;
    if (local_7c == 0) {
      local_80 = 0;
    }
    else {
      local_80 = FUN_00419d70(local_18);
    }
    local_154 = local_80;
    local_8 = 0xffffffff;
    local_14[0x2185] = local_80;
  }
  if (local_14[0x2186] == 0) {
    local_84 = FUN_004121b0(0x750);
    local_8 = 0xc;
    if (local_84 == 0) {
      local_88 = 0;
    }
    else {
      local_88 = FUN_004183e0(local_18);
    }
    local_158 = local_88;
    local_8 = 0xffffffff;
    local_14[0x2186] = local_88;
  }
  if (local_14[0x2187] == 0) {
    local_8c = FUN_004121b0(0x13e0);
    local_8 = 0xd;
    if (local_8c == 0) {
      local_90 = 0;
    }
    else {
      local_90 = FUN_005bc5b0(local_18);
    }
    local_15c = local_90;
    local_8 = 0xffffffff;
    local_14[0x2187] = local_90;
  }
  if (local_14[0x2188] == 0) {
    local_94 = FUN_004121b0(0x10a8);
    local_8 = 0xe;
    if (local_94 == 0) {
      local_98 = 0;
    }
    else {
      local_98 = FUN_005ea3a0(local_18);
    }
    local_160 = local_98;
    local_8 = 0xffffffff;
    local_14[0x2188] = local_98;
  }
  if (local_14[0x2189] == 0) {
    local_9c = FUN_004121b0(0x398);
    local_8 = 0xf;
    if (local_9c == 0) {
      local_a0 = 0;
    }
    else {
      local_a0 = FUN_00551180(local_18);
    }
    local_164 = local_a0;
    local_8 = 0xffffffff;
    local_14[0x2189] = local_a0;
  }
  if (local_14[0x218a] == 0) {
    local_a4 = FUN_004121b0(0x490);
    local_8 = 0x10;
    if (local_a4 == 0) {
      local_a8 = 0;
    }
    else {
      local_a8 = FUN_005bac30(local_18);
    }
    local_168 = local_a8;
    local_8 = 0xffffffff;
    local_14[0x218a] = local_a8;
  }
  if (local_14[0x218b] == 0) {
    local_ac = FUN_004121b0(0xb40);
    local_8 = 0x11;
    if (local_ac == 0) {
      local_b0 = 0;
    }
    else {
      local_b0 = FUN_004c9840(local_18);
    }
    local_16c = local_b0;
    local_8 = 0xffffffff;
    local_14[0x218b] = local_b0;
  }
  if (local_14[0x218c] == 0) {
    local_b4 = FUN_004121b0(0xb98);
    local_8 = 0x12;
    if (local_b4 == 0) {
      local_b8 = 0;
    }
    else {
      local_b8 = FUN_005d8b50(local_18);
    }
    local_170 = local_b8;
    local_8 = 0xffffffff;
    local_14[0x218c] = local_b8;
  }
  if (local_14[0x218d] == 0) {
    local_bc = FUN_004121b0(0xf78);
    local_8 = 0x13;
    if (local_bc == 0) {
      local_c0 = 0;
    }
    else {
      local_c0 = FUN_005f5750(local_18);
    }
    local_174 = local_c0;
    local_8 = 0xffffffff;
    local_14[0x218d] = local_c0;
  }
  if (local_14[0x218e] == 0) {
    local_c4 = FUN_004121b0(0x710);
    local_8 = 0x14;
    if (local_c4 == 0) {
      local_c8 = 0;
    }
    else {
      local_c8 = FUN_005b8510(local_18);
    }
    local_178 = local_c8;
    local_8 = 0xffffffff;
    local_14[0x218e] = local_c8;
  }
  if (local_14[0x218f] == 0) {
    local_cc = FUN_004121b0(0x8a8);
    local_8 = 0x15;
    if (local_cc == 0) {
      local_d0 = 0;
    }
    else {
      local_d0 = FUN_005cb920(local_18);
    }
    local_17c = local_d0;
    local_8 = 0xffffffff;
    local_14[0x218f] = local_d0;
  }
  if (local_14[0x2191] == 0) {
    local_d4 = FUN_004121b0(0x478);
    local_8 = 0x16;
    if (local_d4 == 0) {
      local_d8 = 0;
    }
    else {
      local_d8 = FUN_005adba0(local_18);
    }
    local_180 = local_d8;
    local_8 = 0xffffffff;
    local_14[0x2191] = local_d8;
  }
  if (local_14[0x2190] == 0) {
    local_dc = FUN_004121b0(0xb8);
    local_8 = 0x17;
    if (local_dc == 0) {
      local_e0 = 0;
    }
    else {
      local_e0 = FUN_0049bff0(local_18);
    }
    local_184 = local_e0;
    local_8 = 0xffffffff;
    local_14[0x2190] = local_e0;
  }
  if (local_14[0x2193] == 0) {
    local_e4 = FUN_004121b0(0x8f0);
    local_8 = 0x18;
    if (local_e4 == 0) {
      local_e8 = 0;
    }
    else {
      local_e8 = FUN_005f4b40(local_18);
    }
    local_188 = local_e8;
    local_8 = 0xffffffff;
    local_14[0x2193] = local_e8;
  }
  if (local_14[0x2194] == 0) {
    local_ec = FUN_004121b0(0x978);
    local_8 = 0x19;
    if (local_ec == 0) {
      local_f0 = 0;
    }
    else {
      local_f0 = FUN_00417150(local_18);
    }
    local_18c = local_f0;
    local_8 = 0xffffffff;
    local_14[0x2194] = local_f0;
  }
  if (local_14[0x2195] == 0) {
    local_f4 = FUN_004121b0(0x808);
    local_8 = 0x1a;
    if (local_f4 == 0) {
      local_f8 = 0;
    }
    else {
      local_f8 = FUN_005b7780(local_18);
    }
    local_190 = local_f8;
    local_8 = 0xffffffff;
    local_14[0x2195] = local_f8;
  }
  if (local_14[0x2196] == 0) {
    local_fc = FUN_004121b0(0xf00);
    local_8 = 0x1b;
    if (local_fc == 0) {
      local_100 = 0;
    }
    else {
      local_100 = FUN_00404010(local_18);
    }
    local_194 = local_100;
    local_8 = 0xffffffff;
    local_14[0x2196] = local_100;
  }
  if (local_14[0x2197] == 0) {
    local_104 = FUN_004121b0(0xce8);
    local_8 = 0x1c;
    if (local_104 == 0) {
      local_108 = 0;
    }
    else {
      local_108 = FUN_0054b280(local_14,local_18);
    }
    local_198 = local_108;
    local_8 = 0xffffffff;
    local_14[0x2197] = local_108;
  }
  if (local_14[0x2198] == 0) {
    local_10c = FUN_004121b0(0x1448);
    local_8 = 0x1d;
    if (local_10c == 0) {
      local_110 = 0;
    }
    else {
      local_110 = FUN_005ecc00(local_14,local_18);
    }
    local_19c = local_110;
    local_8 = 0xffffffff;
    local_14[0x2198] = local_110;
  }
  if (local_14[0x2199] == 0) {
    local_114 = FUN_004121b0(0x660);
    local_8 = 0x1e;
    if (local_114 == 0) {
      local_118 = 0;
    }
    else {
      local_118 = FUN_004c5160(local_18);
    }
    local_1a0 = local_118;
    local_8 = 0xffffffff;
    local_14[0x2199] = local_118;
  }
  if (local_14[0x219a] == 0) {
    local_11c = FUN_004121b0(0x528);
    local_8 = 0x1f;
    if (local_11c == 0) {
      local_120 = 0;
    }
    else {
      local_120 = FUN_0057d920(local_18);
    }
    local_1a4 = local_120;
    local_8 = 0xffffffff;
    local_14[0x219a] = local_120;
  }
  *(int *)(local_14[0x2180] + 0xbc) = local_14[0x219a];
  CPrintDialog::CPrintDialog(local_2e0,0,0x14000c,(CWnd *)0x0);
  local_8 = 0x20;
  CDC::CDC(local_1c8);
  local_8 = CONCAT31(local_8._1_3_,0x21);
  FUN_007b53dc();
  pHVar2 = CPrintDialog::CreatePrinterDC(local_2e0);
  iVar1 = FUN_0079e84a(pHVar2);
  if (iVar1 == 0) {
    piVar3 = (int *)FUN_0041c8d0(0x30a,0x465);
    iVar1 = piVar3[1];
    local_14[0x2178] = *piVar3;
    local_14[0x2179] = iVar1;
  }
  else {
    local_1b0 = FUN_004fcb60(8);
    local_1b8 = FUN_004fcb60(10);
    local_1b4 = FUN_004fcb60(0x58);
    local_1ac = FUN_004fcb60(0x5a);
    piVar3 = (int *)FUN_0041c8d0((local_1b0 * 100) / local_1b4,(local_1b8 * 100) / local_1ac);
    iVar1 = piVar3[1];
    local_14[0x2178] = *piVar3;
    local_14[0x2179] = iVar1;
  }
  local_128 = local_14[0x2178];
  local_124 = local_14[0x2179];
  FUN_0079dea2(local_14);
  local_8 = CONCAT31(local_8._1_3_,0x22);
  FUN_0079f13b(4);
  FUN_004fd380(&local_128,1);
  local_124 = -local_124;
  local_1cc = DAT_00a08800;
  (**(code **)(*local_14 + 0x198))(0,0,0);
  if (local_14[0x2164] == 0) {
    if (DAT_00a0cbd4 == 0) {
      FUN_0050dc90();
    }
    else {
      FUN_0050da90();
    }
  }
  iVar1 = FUN_004d2f60(3,DAT_00a0cb04 * 60000,0);
  if (iVar1 == 0) {
    FUN_004f6110(L"Can\'t set Timer#2",0x30,0);
  }
  local_8._0_1_ = 0x21;
  FUN_0079dfff();
  local_8 = CONCAT31(local_8._1_3_,0x20);
  FUN_0079e053();
  local_8 = 0xffffffff;
  FUN_004470c0();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CJw_winView[98] */
/* 0050be50  FUN_0050be50  29 bytes, 0 callers */

void FUN_0050be50(CDC *param_1,CPrintInfo *param_2)

{
  CView *in_ECX;
  
  CView::OnPrepareDC(in_ECX,param_1,param_2);
  return;
}




/* vtable slots: CJw_winView[104] */
/* 0050be70  FUN_0050be70  223 bytes, 0 callers */

int FUN_0050be70(int param_1)

{
  int iVar1;
  int in_ECX;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint local_c;
  
  FUN_004e1b10(0,0);
  FUN_004f7770();
  bVar2 = *(int *)(param_1 + 0xc) != 0;
  if (!bVar2) {
    uVar5 = 0;
    uVar4 = 0xe106;
    uVar3 = 0x111;
    FUN_00404c80(0x111,0xe106,0);
    FUN_00406bc0(uVar3,uVar4,uVar5);
  }
  local_c = (uint)bVar2;
  *(undefined4 *)(param_1 + 0xc) = 1;
  iVar1 = FUN_007b6f18(param_1);
  *(uint *)(param_1 + 0xc) = local_c;
  if (iVar1 == 0) {
    FUN_004fdba0(*(undefined4 *)(in_ECX + 0x8564));
    iVar1 = 0;
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined4 *)(in_ECX + 0x85bc) = 1;
    FUN_004fdba0(0x8053);
    uVar5 = 0;
    uVar4 = 0x8054;
    uVar3 = 0x111;
    FUN_00404c80(0x111,0x8054,0);
    FUN_00799e17();
    FUN_00406bc0(uVar3,uVar4,uVar5);
    iVar1 = 0;
  }
  return iVar1;
}




/* vtable slots: CJw_winView[106] */
/* 0050bf50  FUN_0050bf50  4118 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0050bf50(int *param_1,int param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  double dVar5;
  double dVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 uVar22;
  int in_ECX;
  float10 fVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  int local_c904;
  int local_c900;
  int local_c8fc;
  int local_c8f8;
  int *local_c8f4;
  int local_c8ec;
  uint local_c8e4;
  int local_c8dc;
  undefined1 local_134 [16];
  undefined1 local_124 [32];
  undefined1 local_104 [16];
  undefined1 local_f4 [16];
  undefined1 local_e4 [16];
  undefined1 local_d4 [16];
  undefined1 local_c4 [16];
  undefined1 local_b4 [32];
  undefined1 local_94 [16];
  undefined1 local_84 [16];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a2b8;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00413f30(local_14);
  FUN_00413f30();
  FUN_00413f30();
  iVar15 = FUN_004fcb60(4);
  FUN_004fcb60(6);
  local_74 = *(undefined4 *)(in_ECX + 0x84e4);
  local_70 = *(undefined4 *)(in_ECX + 0x84e8);
  local_6c = *(undefined4 *)(in_ECX + 0x84ec);
  local_68 = *(undefined4 *)(in_ECX + 0x84f0);
  uVar7 = *(undefined4 *)(in_ECX + 0x17a8);
  uVar8 = *(undefined4 *)(in_ECX + 0x17ac);
  uVar1 = *(undefined8 *)(in_ECX + 0x17f8);
  local_64 = *(undefined4 *)(in_ECX + 0x7aa0);
  local_60 = *(undefined4 *)(in_ECX + 0x7aa4);
  local_5c = *(undefined4 *)(in_ECX + 0x7aa8);
  local_58 = *(undefined4 *)(in_ECX + 0x7aac);
  uVar2 = *(undefined8 *)(in_ECX + 0x17b0);
  uVar3 = *(undefined8 *)(in_ECX + 0x8ed0);
  local_54 = *(undefined4 *)(in_ECX + 0x7a80);
  local_50 = *(undefined4 *)(in_ECX + 0x7a84);
  local_4c = *(undefined4 *)(in_ECX + 0x7a88);
  local_48 = *(undefined4 *)(in_ECX + 0x7a8c);
  local_44 = *(undefined4 *)(in_ECX + 0x7a90);
  local_40 = *(undefined4 *)(in_ECX + 0x7a94);
  local_3c = *(undefined4 *)(in_ECX + 0x7a98);
  local_38 = *(undefined4 *)(in_ECX + 0x7a9c);
  uVar4 = *(undefined8 *)(in_ECX + 0x17b8);
  uVar9 = *(undefined4 *)(in_ECX + 0x82c0);
  local_34 = *(undefined4 *)(in_ECX + 0x7a60);
  local_30 = *(undefined4 *)(in_ECX + 0x7a64);
  local_2c = *(undefined4 *)(in_ECX + 0x7a68);
  local_28 = *(undefined4 *)(in_ECX + 0x7a6c);
  local_24 = *(undefined4 *)(in_ECX + 0x7a70);
  local_20 = *(undefined4 *)(in_ECX + 0x7a74);
  local_1c = *(undefined4 *)(in_ECX + 0x7a78);
  local_18 = *(undefined4 *)(in_ECX + 0x7a7c);
  *(undefined4 *)(in_ECX + 0x84e4) = *(undefined4 *)(param_2 + 0x24);
  *(undefined4 *)(in_ECX + 0x84e8) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(in_ECX + 0x84ec) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(in_ECX + 0x84f0) = *(undefined4 *)(param_2 + 0x30);
  CRect::NormalizeRect((CRect *)(in_ECX + 0x84e4));
  puVar16 = (undefined4 *)CRect::Size((CRect *)(in_ECX + 0x84e4));
  uVar22 = puVar16[1];
  *(undefined4 *)(in_ECX + 0x17a8) = *puVar16;
  *(undefined4 *)(in_ECX + 0x17ac) = uVar22;
  *(int *)(in_ECX + 0x17a8) = *(int *)(in_ECX + 0x17a8) / 2;
  *(int *)(in_ECX + 0x17ac) = *(int *)(in_ECX + 0x17ac) / 2;
  *(double *)(in_ECX + 0x17f8) = (double)iVar15 / (double)*(int *)(in_ECX + 0x84ec);
  FUN_004988c0(local_104,*(undefined4 *)(in_ECX + 0x3038),*(undefined4 *)(in_ECX + 0x303c),
               *(undefined4 *)(in_ECX + 0x3040),*(undefined4 *)(in_ECX + 0x3044));
  *(undefined8 *)(in_ECX + 0x17b0) = *(undefined8 *)(in_ECX + 0x3028);
  (**(code **)(*param_1 + 0x50))(local_84);
  iVar15 = FUN_004f72f0();
  *(double *)(in_ECX + 0x8ed0) =
       (((double)iVar15 / 10.0) * *(double *)(in_ECX + 0x17f8)) / *(double *)(in_ECX + 0x17b0);
  dVar24 = (((double)(*(int *)(in_ECX + 0x84ec) + 4) * *(double *)(in_ECX + 0x17f8)) /
           *(double *)(in_ECX + 0x17b0)) / 2.0;
  dVar25 = (((double)(*(int *)(in_ECX + 0x84f0) + 4) * *(double *)(in_ECX + 0x17f8)) /
           *(double *)(in_ECX + 0x17b0)) / 2.0;
  *(double *)(in_ECX + 0x7a80) = -dVar24 + *(double *)(in_ECX + 0x7aa0);
  *(double *)(in_ECX + 0x7a88) = -dVar25 + *(double *)(in_ECX + 0x7aa8);
  *(double *)(in_ECX + 0x7a90) = dVar24 + *(double *)(in_ECX + 0x7aa0);
  *(double *)(in_ECX + 0x7a98) = dVar25 + *(double *)(in_ECX + 0x7aa8);
  fVar23 = (float10)FUN_008f8d10(dVar24 * dVar24 + dVar25 * dVar25);
  *(double *)(in_ECX + 0x17b8) = (double)fVar23 * 2.0;
  FUN_004988c0(local_f4,*(undefined4 *)(in_ECX + 0x7a80),*(undefined4 *)(in_ECX + 0x7a84),
               *(undefined4 *)(in_ECX + 0x7a88),*(undefined4 *)(in_ECX + 0x7a8c));
  FUN_004988c0(local_e4,*(undefined4 *)(in_ECX + 0x7a90),*(undefined4 *)(in_ECX + 0x7a94),
               *(undefined4 *)(in_ECX + 0x7a98),*(undefined4 *)(in_ECX + 0x7a9c));
  dVar24 = (*(double *)(in_ECX + 0x17b0) * 1.0) / *(double *)(in_ECX + 0x17f8);
  iVar15 = FUN_004f72f0();
  if ((double)iVar15 <= dVar24) {
    uVar22 = FUN_004f72f0();
    *(undefined4 *)(in_ECX + 0x82c0) = uVar22;
  }
  else {
    *(int *)(in_ECX + 0x82c0) = (int)dVar24;
  }
  FUN_00446aa0();
  local_8 = 0;
  if (*(int *)(in_ECX + 0x7c10) == 0) {
    if (in_ECX == 0) {
      local_c900 = 0;
    }
    else {
      local_c900 = in_ECX + 0x88;
    }
    uVar22 = FUN_0040c0e0();
    FUN_0044b760(local_c900,param_1,uVar22);
  }
  else {
    if (*(int *)(in_ECX + 0x7c14) == 0) {
      (**(code **)(*(int *)(in_ECX + 0x88) + 4))();
      FUN_004b5e60();
      *(undefined4 *)(in_ECX + 0x7c10) = 0;
      if (in_ECX == 0) {
        local_c904 = 0;
      }
      else {
        local_c904 = in_ECX + 0x88;
      }
      uVar22 = FUN_0040c0e0();
      FUN_0044b760(local_c904,param_1,uVar22);
      *(undefined4 *)(in_ECX + 0x7c10) = 1;
    }
    else {
      *(undefined4 *)(in_ECX + 0x8284) = 1;
      *(undefined4 *)(in_ECX + 0x7c34) = *(undefined4 *)(in_ECX + 0x84e4);
      *(undefined4 *)(in_ECX + 0x7c38) = *(undefined4 *)(in_ECX + 0x84e8);
      *(undefined4 *)(in_ECX + 0x7c3c) = *(undefined4 *)(in_ECX + 0x84ec);
      *(undefined4 *)(in_ECX + 0x7c40) = *(undefined4 *)(in_ECX + 0x84f0);
    }
    for (local_c8dc = 0; local_c8dc < *(int *)(in_ECX + 0x8284); local_c8dc = local_c8dc + 1) {
      FUN_004988c0(local_94,*(undefined4 *)(in_ECX + 0x3038),*(undefined4 *)(in_ECX + 0x303c),
                   *(undefined4 *)(in_ECX + 0x3040),*(undefined4 *)(in_ECX + 0x3044));
      iVar15 = GetSystemMetrics(0x3d);
      iVar17 = GetSystemMetrics(0x3e);
      uVar18 = FUN_00416ff0();
      iVar19 = FUN_00416780();
      local_c8e4 = (uint)(((((double)(int)uVar18 +
                            *(double *)(&DAT_0095c9b0 + ((int)uVar18 >> 0x1f) * -8)) *
                           ((double)iVar19 + *(double *)(&DAT_0095c9b0 + (iVar19 >> 0x1f) * -8))) /
                          (double)(iVar15 * iVar17)) / 20.0 + 1.0);
      if ((int)local_c8e4 < 1) {
        local_c8e4 = 1;
      }
      iVar15 = FUN_00416780();
      iVar20 = (int)(iVar15 + local_c8e4) / (int)local_c8e4;
      dVar26 = ((double)iVar20 * *(double *)(in_ECX + 0x17f8)) / *(double *)(in_ECX + 0x17b0);
      iVar15 = *(int *)(in_ECX + 0x7c3c + local_c8dc * 0x10);
      iVar17 = *(int *)(in_ECX + 0x7c34 + local_c8dc * 0x10);
      iVar19 = *(int *)(in_ECX + 0x84ec);
      iVar10 = *(int *)(in_ECX + 0x84e4);
      dVar24 = *(double *)(in_ECX + 0x17f8);
      dVar25 = *(double *)(in_ECX + 0x17b0);
      iVar11 = *(int *)(in_ECX + 0x7c40 + local_c8dc * 0x10);
      iVar12 = *(int *)(in_ECX + 0x7c38 + local_c8dc * 0x10);
      iVar13 = *(int *)(in_ECX + 0x84f0);
      iVar14 = *(int *)(in_ECX + 0x84e8);
      dVar5 = *(double *)(in_ECX + 0x17f8);
      dVar6 = *(double *)(in_ECX + 0x17b0);
      iVar21 = FUN_00416780();
      *(double *)(in_ECX + 0x7aa0) =
           *(double *)(in_ECX + 0x7aa0) +
           ((double)((((iVar15 + iVar17) - iVar19) - iVar10) / 2) * dVar24) / dVar25;
      *(double *)(in_ECX + 0x7aa8) =
           *(double *)(in_ECX + 0x7aa8) +
           ((double)(-(((iVar11 + iVar12) - iVar13) - iVar14) / 2) * dVar5) / dVar6 +
           (((double)iVar21 * *(double *)(in_ECX + 0x17f8)) / *(double *)(in_ECX + 0x17b0)) / 2.0;
      *(double *)(in_ECX + 0x7aa8) = *(double *)(in_ECX + 0x7aa8) - dVar26 / 2.0;
      *(int *)(in_ECX + 0x17ac) = iVar20 / 2;
      *(uint *)(in_ECX + 0x17a8) = uVar18 >> 1;
      iVar15 = FUN_004121b0();
      local_8._0_1_ = 1;
      if (iVar15 == 0) {
        local_c8f4 = (int *)0x0;
      }
      else {
        local_c8f4 = (int *)FUN_004aa560();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00404c80();
      FUN_0046ba20();
      (**(code **)(*local_c8f4 + 0x164))(0x15d);
      FUN_00797f20();
      FUN_004701c0(0,local_c8e4 & 0xffff);
      for (local_c8ec = 0; local_c8ec < (int)local_c8e4; local_c8ec = local_c8ec + 1) {
        FUN_00470190();
        puVar16 = (undefined4 *)(in_ECX + 0x7c34 + local_c8dc * 0x10);
        FUN_004b5b70(param_1,iVar20,*puVar16,puVar16[1],puVar16[2],puVar16[3]);
        if (DAT_00a088f4 == 0) {
          FUN_00446aa0();
          local_8._0_1_ = 2;
          *(undefined4 *)(DAT_00a0b410 + 0x8558) = 1;
          if (in_ECX == 0) {
            local_c8f8 = 0;
          }
          else {
            local_c8f8 = in_ECX + 0x88;
          }
          uVar22 = FUN_0040c0e0();
          FUN_0044b760(local_c8f8,in_ECX + 0x7c18,uVar22);
          *(undefined4 *)(DAT_00a0b410 + 0x8558) = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
        }
        else {
          if (in_ECX == 0) {
            local_c8fc = 0;
          }
          else {
            local_c8fc = in_ECX + 0x88;
          }
          uVar22 = FUN_0040c0e0();
          FUN_0044b760(local_c8fc,param_1,uVar22);
        }
        puVar16 = (undefined4 *)(in_ECX + 0x7c34 + local_c8dc * 0x10);
        FUN_004b71e0(param_1,iVar20,local_c8ec * iVar20,*puVar16,puVar16[1],puVar16[2],puVar16[3],0)
        ;
        *(double *)(in_ECX + 0x7aa8) = *(double *)(in_ECX + 0x7aa8) - dVar26;
      }
      if ((local_c8f4 != (int *)0x0) &&
         ((**(code **)(*local_c8f4 + 0x60))(), local_c8f4 != (int *)0x0)) {
        (**(code **)(*local_c8f4 + 4))();
      }
    }
  }
  *(undefined4 *)(in_ECX + 0x84e4) = local_74;
  *(undefined4 *)(in_ECX + 0x84e8) = local_70;
  *(undefined4 *)(in_ECX + 0x84ec) = local_6c;
  *(undefined4 *)(in_ECX + 0x84f0) = local_68;
  *(undefined4 *)(in_ECX + 0x17a8) = uVar7;
  *(undefined4 *)(in_ECX + 0x17ac) = uVar8;
  *(undefined8 *)(in_ECX + 0x17f8) = uVar1;
  FUN_004988c0(local_d4,local_64,local_60,local_5c,local_58);
  *(undefined8 *)(in_ECX + 0x17b0) = uVar2;
  *(undefined8 *)(in_ECX + 0x8ed0) = uVar3;
  FUN_004988c0(local_c4,local_54,local_50,local_4c,local_48);
  FUN_004988c0(local_b4,local_44,local_40,local_3c,local_38);
  *(undefined8 *)(in_ECX + 0x17b8) = uVar4;
  *(undefined4 *)(in_ECX + 0x82c0) = uVar9;
  FUN_004988c0(local_124,local_34,local_30,local_2c,local_28);
  FUN_004988c0(local_134,local_24,local_20,local_1c,local_18);
  (**(code **)(*param_1 + 0x50))();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CJw_winView[25] */
/* 00516f50  FUN_00516f50  25 bytes, 0 callers */

void FUN_00516f50(undefined4 param_1)

{
  PreCreateWindow(param_1);
  return;
}




/* vtable slots: CJw_winView[3] */
/* 00517ca0  FUN_00517ca0  57 bytes, 0 callers */

bool FUN_00517ca0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040c0e0();
  return *(int *)(iVar1 + 0xee0 + param_1 * 4) != 0;
}




/* vtable slots: CJw_winView[2] */
/* 00517ce0  FUN_00517ce0  57 bytes, 0 callers */

bool FUN_00517ce0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040c0e0();
  return *(int *)(iVar1 + 0xea0 + param_1 * 4) != 0;
}




/* vtable slots: CJw_winView[5] */
/* 00517d20  FUN_00517d20  66 bytes, 0 callers */

bool FUN_00517d20(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040c0e0();
  return *(int *)(iVar1 + 0x1320 + param_1 * 0x40 + param_2 * 4) != 0;
}




/* vtable slots: CJw_winView[4] */
/* 00517d70  FUN_00517d70  66 bytes, 0 callers */

bool FUN_00517d70(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040c0e0();
  return *(int *)(iVar1 + 0xf20 + param_1 * 0x40 + param_2 * 4) != 0;
}




/* vtable slots: CJw_winView[26] */
/* 007b66f9  FUN_007b66f9  114 bytes, 0 callers */

void FUN_007b66f9(LPRECT param_1,int param_2)

{
  DWORD dwExStyle;
  uint uVar1;
  CWnd *in_ECX;
  int iVar2;
  
  if (param_1 != (LPRECT)0x0) {
    if (param_2 == 0) {
      CWnd::CalcWindowRect(in_ECX,param_1,0);
    }
    else {
      dwExStyle = FUN_00797acc();
      AdjustWindowRectEx(param_1,0,0,dwExStyle);
      uVar1 = FUN_00797b3d();
      if ((uVar1 & 0x200000) != 0) {
        iVar2 = DAT_00a12208;
        if ((uVar1 & 0x800000) != 0) {
          iVar2 = DAT_00a12208 + -1;
        }
        param_1->right = param_1->right + iVar2;
      }
      if ((uVar1 & 0x100000) != 0) {
        iVar2 = DAT_00a1220c;
        if ((uVar1 & 0x800000) != 0) {
          iVar2 = DAT_00a1220c + -1;
        }
        param_1->bottom = param_1->bottom + iVar2;
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CJw_winView[30], CPreviewView[30], CPreviewViewEx[30], CScrollView[30] */
/* 007b67d5  FUN_007b67d5  113 bytes, 0 callers */

undefined4 FUN_007b67d5(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = FUN_00797b3d();
  if ((((-(uint)(param_1 != 0) & 0x100000) + 0x100000 & uVar1) == 0) &&
     (iVar2 = FUN_007b676c(in_ECX,1), iVar2 != 0)) {
    uVar1 = GetDlgCtrlID(*(HWND *)(in_ECX + 0x20));
    if (uVar1 - 0xe900 < 0x100) {
      if (param_1 == 0) {
        iVar2 = (uVar1 & 0xf) + 0xea00;
      }
      else {
        iVar2 = (uVar1 - 0xe900 >> 4) + 0xea10;
      }
      uVar3 = FUN_00797a56(iVar2);
      return uVar3;
    }
  }
  return 0;
}




/* vtable slots: CJw_winView[3], CPreviewView[3], CPreviewViewEx[3], CScrollView[3] */
/* 007b686d  FUN_007b686d  121 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007b686d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  CView *in_ECX;
  CPushRoutingView local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7b6879;
  iVar2 = FUN_007900e9(param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    if (*(int *)(in_ECX + 0x80) == 0) {
      uVar3 = 0;
    }
    else {
      CPushRoutingView::CPushRoutingView(local_1c,in_ECX);
      local_8 = 0;
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xc);
      guard_check_icall(param_1,param_2,param_3,param_4);
      uVar3 = (*pcVar1)();
      FUN_007b6579();
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CJw_winView[97], CPreviewView[97], CPreviewViewEx[97], CScrollView[97] */
/* 007b6945  FUN_007b6945  8 bytes, 0 callers */

undefined4 FUN_007b6945(void)

{
  return 0x80000000;
}




/* vtable slots: CJw_winView[96], CPreviewView[96], CPreviewViewEx[96], CScrollView[96] */
/* 007b694d  FUN_007b694d  6 bytes, 0 callers */

undefined4 FUN_007b694d(void)

{
  return 0xffffffff;
}




/* vtable slots: CJw_winView[108], CPreviewView[108], CPreviewViewEx[108], CScrollView[108] */
/* 007b6953  FUN_007b6953  246 bytes, 0 callers */

void FUN_007b6953(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int *param_5)

{
  code *pcVar1;
  CObject *pCVar2;
  CObject *pCVar3;
  int *in_ECX;
  
  if ((int *)param_5[0x2f] != (int *)0x0) {
    pcVar1 = *(code **)(*(int *)param_5[0x2f] + 0x1ac);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
  }
  pCVar2 = (CObject *)FUN_0079296c();
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,pCVar2);
  if (pCVar3 == (CObject *)0x0) {
    pCVar2 = (CObject *)FUN_00404c80();
  }
  pcVar1 = *(code **)(*(int *)pCVar2 + 0x194);
  guard_check_icall(0,param_5[0x36]);
  (*pcVar1)();
  FUN_0079c896(*(undefined4 *)(param_5[0x36] + 0xc),1);
  pCVar3 = (CObject *)FUN_0079296c();
  if (pCVar2 != pCVar3) {
    pcVar1 = *(code **)(*in_ECX + 400);
    guard_check_icall(1);
    (*pcVar1)();
  }
  pcVar1 = *(code **)(*param_5 + 0x60);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)pCVar2 + 0x178);
  guard_check_icall(1);
  (*pcVar1)();
  SendMessageW(*(HWND *)(pCVar2 + 0x20),0x362,0xe001,0);
  UpdateWindow(*(HWND *)(pCVar2 + 0x20));
  return;
}



