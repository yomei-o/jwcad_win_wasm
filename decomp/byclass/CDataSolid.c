/* CDataSolid -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataSolid[1] */
/* 00420b20  FUN_00420b20  68 bytes, 0 callers */

undefined4 FUN_00420b20(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041fd90();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,600);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataSolid[14] */
/* 00421260  FUN_00421260  260 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00421260(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00403cd0(local_20c,L"Solid  %d (%g,%g)-(%g,%g)-(%g,%g)-(%g,%g)                             ",
               param_3,*(undefined8 *)(in_ECX + 8),*(undefined8 *)(in_ECX + 0x10),
               *(undefined8 *)(in_ECX + 0x18),*(undefined8 *)(in_ECX + 0x20),
               *(undefined8 *)(in_ECX + 0x68),*(undefined8 *)(in_ECX + 0x70),
               *(undefined8 *)(in_ECX + 0x78),*(undefined8 *)(in_ECX + 0x80));
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x32,local_20c,uVar1);
  return;
}




/* vtable slots: CDataSolid[15] */
/* 00425270  FUN_00425270  105 bytes, 0 callers */

undefined4 FUN_00425270(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00424ed0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_0042b460(param_2);
    if (iVar1 == 0) {
      uVar2 = FUN_004238c0(param_1,param_2,param_3);
      FUN_0042e540();
    }
    else {
      FUN_0042e540();
      uVar2 = 0;
    }
  }
  return uVar2;
}




/* vtable slots: CDataSolid[3] */
/* 00429650  FUN_00429650  760 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00429650(int param_1)

{
  short sVar1;
  int in_ECX;
  float10 fVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921650;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  sVar1 = *(short *)(in_ECX + 0x2a);
  if (*(byte *)(in_ECX + 0x28) < 100) {
    CStringT<>("SOLID");
    FUN_004a7e90(0);
    FUN_0049dea0(&stack0xffffff38,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),
                 *(undefined1 *)(in_ECX + 0x28));
    FUN_004a7e90(8);
    FUN_00403dd0(param_1 + 0x1c + (uint)*(byte *)(in_ECX + 0x28) * 4);
    FUN_004a7e90(6);
    if (sVar1 == 10) {
      FUN_0049dcf0();
      FUN_004a7e10(0x3e);
    }
    else {
      FUN_0049dcf0();
      FUN_004a7e10(0x3e);
    }
    fVar2 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 8));
    FUN_004a77a0(10,(double)fVar2);
    fVar2 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x10));
    FUN_004a77a0(0x14,(double)fVar2);
    fVar2 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x18));
    FUN_004a77a0(0xb,(double)fVar2);
    fVar2 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x20));
    FUN_004a77a0(0x15,(double)fVar2);
    fVar2 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x78));
    FUN_004a77a0(0xc,(double)fVar2);
    fVar2 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x80));
    FUN_004a77a0(0x16,(double)fVar2);
    fVar2 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x68));
    FUN_004a77a0(0xd,(double)fVar2);
    fVar2 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x70));
    FUN_004a77a0(0x17,(double)fVar2);
  }
  else {
    FUN_0041f5f0();
    local_8 = 0;
    FUN_00437050();
    FUN_00428d10();
    local_8 = 0xffffffff;
    FUN_0041fd50();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataSolid[22] */
/* 00429e30  FUN_00429e30  660 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_00429e30(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  int local_30;
  undefined1 local_28 [16];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(byte *)(in_ECX + 0x28) < 100) {
    FUN_00408a30(0,0);
    local_30 = 1;
    FUN_004988c0(local_28,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                 *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
    iVar1 = FUN_004989a0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                         *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
    if (iVar1 != 0) {
      FUN_00498ac0(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
                   *(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24));
      local_30 = 2;
    }
    iVar1 = FUN_004989a0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                         *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
    if (iVar1 != 0) {
      iVar1 = FUN_004989a0(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
                           *(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24));
      if (iVar1 != 0) {
        FUN_00498ac0(*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c),
                     *(undefined4 *)(in_ECX + 0x70),*(undefined4 *)(in_ECX + 0x74));
        local_30 = local_30 + 1;
      }
    }
    iVar1 = FUN_004989a0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                         *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
    if (iVar1 != 0) {
      iVar1 = FUN_004989a0(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
                           *(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24));
      if (iVar1 != 0) {
        iVar1 = FUN_004989a0(*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c),
                             *(undefined4 *)(in_ECX + 0x70),*(undefined4 *)(in_ECX + 0x74));
        if (iVar1 != 0) {
          FUN_00498ac0(*(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c),
                       *(undefined4 *)(in_ECX + 0x80),*(undefined4 *)(in_ECX + 0x84));
          local_30 = local_30 + 1;
        }
      }
    }
    FUN_00498bf0((double)local_30);
    *param_1 = local_18;
    param_1[1] = local_14;
    param_1[2] = local_10;
    param_1[3] = local_c;
  }
  else {
    *param_1 = *(undefined4 *)(in_ECX + 8);
    param_1[1] = *(undefined4 *)(in_ECX + 0xc);
    param_1[2] = *(undefined4 *)(in_ECX + 0x10);
    param_1[3] = *(undefined4 *)(in_ECX + 0x14);
  }
  return param_1;
}




/* vtable slots: CDataSolid[11] */
/* 0042a260  FUN_0042a260  3253 bytes, 2 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
FUN_0042a260(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  double local_66cc;
  double local_66c4;
  double local_66bc;
  double local_66b4;
  double local_66ac;
  int local_669c;
  double local_6698;
  int local_6684;
  undefined1 local_2ac [16];
  undefined1 local_29c [16];
  undefined1 local_28c [16];
  undefined1 local_27c [16];
  undefined1 local_26c [16];
  undefined1 local_25c [16];
  undefined1 local_24c [16];
  undefined1 local_23c [16];
  undefined1 local_22c [16];
  undefined1 local_21c [16];
  undefined1 local_20c [16];
  undefined1 local_1fc [16];
  undefined1 local_1ec [16];
  undefined1 local_1dc [16];
  undefined1 local_1cc [16];
  undefined1 local_1bc [16];
  undefined1 local_1ac [16];
  undefined1 local_19c [16];
  undefined1 local_18c [16];
  undefined1 local_17c [16];
  undefined1 local_16c [16];
  undefined1 local_15c [16];
  undefined1 local_14c [16];
  undefined1 local_13c [168];
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
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
  undefined8 local_44;
  undefined8 local_3c;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092169b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00408a60(local_14);
  FUN_00408a60();
  FUN_00408a30(0,0);
  local_6698 = 9e+20;
  *(undefined4 *)(in_ECX + 0xb8) = 0xffffffff;
  FUN_005f8a10();
  if (*(byte *)(in_ECX + 0x28) < 100) {
    for (local_6684 = 1; local_6684 < 5; local_6684 = local_6684 + 1) {
      if (local_6684 == 1) {
        FUN_004988c0(local_16c,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                     *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
        FUN_004988c0(local_17c,*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
                     *(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24));
      }
      if (local_6684 == 2) {
        FUN_004988c0(local_18c,*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
                     *(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24));
        FUN_004988c0(local_1ac,*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c),
                     *(undefined4 *)(in_ECX + 0x70),*(undefined4 *)(in_ECX + 0x74));
      }
      if (local_6684 == 3) {
        FUN_004988c0(local_1bc,*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c),
                     *(undefined4 *)(in_ECX + 0x70),*(undefined4 *)(in_ECX + 0x74));
        FUN_004988c0(local_1cc,*(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c),
                     *(undefined4 *)(in_ECX + 0x80),*(undefined4 *)(in_ECX + 0x84));
      }
      if (local_6684 == 4) {
        FUN_004988c0(local_22c,*(undefined4 *)(in_ECX + 0x78),*(undefined4 *)(in_ECX + 0x7c),
                     *(undefined4 *)(in_ECX + 0x80),*(undefined4 *)(in_ECX + 0x84));
        FUN_004988c0(local_1dc,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                     *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
      }
      iVar1 = FUN_005f9950(local_24,uStack_20,local_1c,uStack_18,local_34,uStack_30,local_2c,
                           uStack_28,0);
      if (iVar1 != 0) {
        fVar3 = (float10)FUN_005f8ca0(1,param_2,param_3,param_4,param_5);
        local_66cc = (double)fVar3;
        local_66c4 = local_66cc;
        if (local_66cc <= 0.0) {
          local_66c4 = -local_66cc;
        }
        if (local_66c4 < local_6698) {
          if (local_66cc <= 0.0) {
            local_66cc = -local_66cc;
          }
          local_6698 = local_66cc;
          local_44 = ((double)CONCAT44(uStack_20,local_24) + (double)CONCAT44(uStack_30,local_34)) /
                     2.0;
          local_3c = ((double)CONCAT44(uStack_18,local_1c) + (double)CONCAT44(uStack_28,local_2c)) /
                     2.0;
          *(undefined4 *)(in_ECX + 0xb8) = 0;
          FUN_004988c0(local_1ec,local_24,uStack_20,local_1c,uStack_18);
          FUN_004988c0(local_1fc,local_34,uStack_30,local_2c,uStack_28);
        }
      }
    }
    *param_1 = (undefined4)local_44;
    param_1[1] = local_44._4_4_;
    param_1[2] = (undefined4)local_3c;
    param_1[3] = local_3c._4_4_;
  }
  else {
    FUN_0041f5f0();
    local_8 = 0;
    FUN_00437050();
    iVar1 = FUN_0040c120();
    *(undefined4 *)(in_ECX + 0xb8) = 1;
    FUN_00420020();
    if ((iVar1 < 2) || (99 < iVar1)) {
      FUN_004988c0(local_20c,param_2,param_3,param_4,param_5);
      FUN_00446aa0();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_0045b790();
      fVar3 = (float10)FUN_0043ad70(local_24,uStack_20,local_1c,uStack_18,param_2,param_3,param_4,
                                    param_5);
      local_6698 = (double)fVar3;
      if (99 < iVar1) {
        FUN_004988c0(local_21c,param_2,param_3,param_4,param_5);
        FUN_0045b790();
        fVar3 = (float10)FUN_0043ad70(local_24,uStack_20,local_1c,uStack_18,param_2,param_3,param_4,
                                      param_5);
        if ((double)fVar3 < local_6698) {
          *(undefined4 *)(in_ECX + 0xb8) = 1;
          fVar3 = (float10)FUN_0043ad70(local_24,uStack_20,local_1c,uStack_18,param_2,param_3,
                                        param_4,param_5);
          local_6698 = (double)fVar3;
          FUN_00420020();
        }
        fVar3 = (float10)FUN_0040c100();
        local_66ac = (double)fVar3;
        if (local_66ac <= 0.0) {
          local_66ac = -local_66ac;
        }
        if (6.283185207179586 < local_66ac) {
          *param_1 = *(undefined4 *)(in_ECX + 8);
          param_1[1] = *(undefined4 *)(in_ECX + 0xc);
          param_1[2] = *(undefined4 *)(in_ECX + 0x10);
          param_1[3] = *(undefined4 *)(in_ECX + 0x14);
          local_8 = local_8 & 0xffffff00;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0041fd50();
          ExceptionList = local_10;
          return param_1;
        }
      }
      FUN_004988c0(local_19c,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                   *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
      FUN_00408a60();
      FUN_00408a60();
      FUN_00408a60();
      FUN_0043af40(&local_64,&local_74);
      FUN_004988c0(local_23c,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                   *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
      if (iVar1 == -1) {
        FUN_0043a8d0();
      }
      local_669c = 2;
      if (iVar1 == 1) {
        local_669c = 1;
      }
      for (local_6684 = 1; local_6684 <= local_669c; local_6684 = local_6684 + 1) {
        if (local_6684 == 1) {
          FUN_004988c0(local_24c,local_54,local_50,local_4c,local_48);
          FUN_004988c0(local_25c,local_64,local_60,local_5c,local_58);
        }
        if (local_6684 == 2) {
          FUN_004988c0(local_26c,local_54,local_50,local_4c,local_48);
          FUN_004988c0(local_27c,local_74,local_70,local_6c,local_68);
        }
        if (iVar1 == 1) {
          FUN_004988c0(local_28c,local_64,local_60,local_5c,local_58);
          FUN_004988c0(local_29c,local_74,local_70,local_6c,local_68);
        }
        if ((99 < iVar1) && (fVar3 = (float10)FUN_0040c160(), 1e-07 < (double)fVar3)) {
          FUN_00408a60();
          FUN_00408a60();
          (**(code **)(*(int *)(in_ECX + 0x1c0) + 0x34))(&local_84);
          if (local_6684 == 1) {
            FUN_004988c0(local_2ac,local_84,local_80,local_7c,local_78);
          }
          if (local_6684 == 2) {
            FUN_004988c0(local_13c,local_94,local_90,local_8c,local_88);
          }
        }
        iVar2 = FUN_005f9950(local_24,uStack_20,local_1c,uStack_18,local_34,uStack_30,local_2c,
                             uStack_28,0);
        if (iVar2 != 0) {
          fVar3 = (float10)FUN_005f8ca0(1,param_2,param_3,param_4,param_5);
          local_66bc = (double)fVar3;
          local_66b4 = local_66bc;
          if (local_66bc <= 0.0) {
            local_66b4 = -local_66bc;
          }
          if (local_66b4 < local_6698) {
            if (local_66bc <= 0.0) {
              local_66bc = -local_66bc;
            }
            local_6698 = local_66bc;
            local_44 = ((double)CONCAT44(uStack_20,local_24) + (double)CONCAT44(uStack_30,local_34))
                       / 2.0;
            local_3c = ((double)CONCAT44(uStack_18,local_1c) + (double)CONCAT44(uStack_28,local_2c))
                       / 2.0;
            *(undefined4 *)(in_ECX + 0xb8) = 0;
            FUN_004988c0(local_14c,local_24,uStack_20,local_1c,uStack_18);
            FUN_004988c0(local_15c,local_34,uStack_30,local_2c,uStack_28);
          }
        }
      }
      *param_1 = (undefined4)local_44;
      param_1[1] = local_44._4_4_;
      param_1[2] = (undefined4)local_3c;
      param_1[3] = local_3c._4_4_;
      local_8 = local_8 & 0xffffff00;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0041fd50();
    }
    else {
      *param_1 = *(undefined4 *)(in_ECX + 8);
      param_1[1] = *(undefined4 *)(in_ECX + 0xc);
      param_1[2] = *(undefined4 *)(in_ECX + 0x10);
      param_1[3] = *(undefined4 *)(in_ECX + 0x14);
      local_8 = 0xffffffff;
      FUN_0041fd50();
    }
  }
  ExceptionList = local_10;
  return param_1;
}




/* vtable slots: CDataSolid[0] */
/* 0042b0c0  FUN_0042b0c0  16 bytes, 0 callers */

undefined ** FUN_0042b0c0(void)

{
  return &PTR_s_CDataSolid_009fe094;
}




/* vtable slots: CDataSolid[17] */
/* 0042c630  FUN_0042c630  4525 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0042c630(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  double dVar5;
  double dVar6;
  double local_388;
  double local_380;
  double local_378;
  double local_370;
  double local_368;
  double local_360;
  double local_358;
  double local_350;
  double local_348;
  double local_340;
  double local_338;
  double local_330;
  double local_328;
  int local_2d4;
  double local_2d0;
  undefined1 local_2c4 [16];
  undefined1 local_2b4 [16];
  undefined1 local_2a4 [16];
  undefined1 local_294 [16];
  undefined1 local_284 [16];
  undefined1 local_274 [16];
  undefined1 local_264 [16];
  undefined1 local_254 [16];
  undefined1 local_244 [16];
  undefined1 local_234 [16];
  undefined1 local_224 [16];
  undefined1 local_214 [16];
  undefined1 local_204 [16];
  undefined1 local_1f4 [16];
  undefined1 local_1e4 [16];
  undefined1 local_1d4 [16];
  undefined1 local_1c4 [16];
  undefined1 local_1b4 [16];
  undefined1 local_1a4 [16];
  undefined1 local_194 [16];
  undefined1 local_184 [256];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  double local_54;
  double local_4c;
  double local_44;
  double local_3c;
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
  puStack_c = &LAB_009217eb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (*(byte *)(in_ECX + 0x28) < 100) {
    if ((((*(double *)(param_1 + 0x8ee8) < *(double *)(in_ECX + 8) ||
           *(double *)(param_1 + 0x8ee8) == *(double *)(in_ECX + 8)) ||
         (*(double *)(param_1 + 0x8ee8) < *(double *)(in_ECX + 0x18) ||
          *(double *)(param_1 + 0x8ee8) == *(double *)(in_ECX + 0x18))) ||
        (*(double *)(param_1 + 0x8ee8) < *(double *)(in_ECX + 0x68) ||
         *(double *)(param_1 + 0x8ee8) == *(double *)(in_ECX + 0x68))) ||
       (*(double *)(param_1 + 0x8ee8) < *(double *)(in_ECX + 0x78) ||
        *(double *)(param_1 + 0x8ee8) == *(double *)(in_ECX + 0x78))) {
      if (((*(double *)(in_ECX + 8) < *(double *)(param_1 + 0x8ef8) ||
            *(double *)(in_ECX + 8) == *(double *)(param_1 + 0x8ef8)) ||
          (*(double *)(in_ECX + 0x18) < *(double *)(param_1 + 0x8ef8) ||
           *(double *)(in_ECX + 0x18) == *(double *)(param_1 + 0x8ef8))) ||
         ((*(double *)(in_ECX + 0x68) < *(double *)(param_1 + 0x8ef8) ||
           *(double *)(in_ECX + 0x68) == *(double *)(param_1 + 0x8ef8) ||
          (*(double *)(in_ECX + 0x78) < *(double *)(param_1 + 0x8ef8) ||
           *(double *)(in_ECX + 0x78) == *(double *)(param_1 + 0x8ef8))))) {
        if (((*(double *)(param_1 + 0x8ef0) < *(double *)(in_ECX + 0x10) ||
              *(double *)(param_1 + 0x8ef0) == *(double *)(in_ECX + 0x10)) ||
            (*(double *)(param_1 + 0x8ef0) < *(double *)(in_ECX + 0x20) ||
             *(double *)(param_1 + 0x8ef0) == *(double *)(in_ECX + 0x20))) ||
           ((*(double *)(param_1 + 0x8ef0) < *(double *)(in_ECX + 0x70) ||
             *(double *)(param_1 + 0x8ef0) == *(double *)(in_ECX + 0x70) ||
            (*(double *)(param_1 + 0x8ef0) < *(double *)(in_ECX + 0x80) ||
             *(double *)(param_1 + 0x8ef0) == *(double *)(in_ECX + 0x80))))) {
          if ((((*(double *)(in_ECX + 0x10) < *(double *)(param_1 + 0x8f00) ||
                 *(double *)(in_ECX + 0x10) == *(double *)(param_1 + 0x8f00)) ||
               (*(double *)(in_ECX + 0x20) < *(double *)(param_1 + 0x8f00) ||
                *(double *)(in_ECX + 0x20) == *(double *)(param_1 + 0x8f00))) ||
              (*(double *)(in_ECX + 0x70) < *(double *)(param_1 + 0x8f00) ||
               *(double *)(in_ECX + 0x70) == *(double *)(param_1 + 0x8f00))) ||
             (*(double *)(in_ECX + 0x80) < *(double *)(param_1 + 0x8f00) ||
              *(double *)(in_ECX + 0x80) == *(double *)(param_1 + 0x8f00))) {
            if ((double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 8) <= 0.0) {
              local_360 = -((double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 8));
            }
            else {
              local_360 = (double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 8);
            }
            if ((double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x10) <= 0.0) {
              local_358 = -((double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x10));
            }
            else {
              local_358 = (double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x10);
            }
            if (*(double *)(param_1 + 0x8ed0) <= local_360 + local_358) {
              if ((double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x18) <= 0.0) {
                local_348 = -((double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x18));
              }
              else {
                local_348 = (double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x18);
              }
              if ((double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x20) <= 0.0) {
                local_340 = -((double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x20));
              }
              else {
                local_340 = (double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x20);
              }
              if (*(double *)(param_1 + 0x8ed0) <= local_348 + local_340) {
                if ((double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x68) <= 0.0) {
                  local_350 = -((double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x68));
                }
                else {
                  local_350 = (double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x68);
                }
                if ((double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x70) <= 0.0) {
                  local_338 = -((double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x70));
                }
                else {
                  local_338 = (double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x70);
                }
                if (*(double *)(param_1 + 0x8ed0) <= local_350 + local_338) {
                  if ((double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x78) <= 0.0) {
                    local_328 = -((double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x78));
                  }
                  else {
                    local_328 = (double)CONCAT44(param_3,param_2) - *(double *)(in_ECX + 0x78);
                  }
                  if ((double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x80) <= 0.0) {
                    local_388 = -((double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x80));
                  }
                  else {
                    local_388 = (double)CONCAT44(param_5,param_4) - *(double *)(in_ECX + 0x80);
                  }
                  if (*(double *)(param_1 + 0x8ed0) <= local_328 + local_388) {
                    for (local_2d4 = 0; local_2d4 < 4; local_2d4 = local_2d4 + 1) {
                      FUN_00408a60(uVar1);
                      FUN_00408a60();
                      switch(local_2d4) {
                      case 0:
                        FUN_004988c0(local_264,*(undefined4 *)(in_ECX + 8),
                                     *(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),
                                     *(undefined4 *)(in_ECX + 0x14));
                        FUN_004988c0(local_274,*(undefined4 *)(in_ECX + 0x18),
                                     *(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 0x20),
                                     *(undefined4 *)(in_ECX + 0x24));
                        break;
                      case 1:
                        FUN_004988c0(local_194,*(undefined4 *)(in_ECX + 0x18),
                                     *(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 0x20),
                                     *(undefined4 *)(in_ECX + 0x24));
                        FUN_004988c0(local_284,*(undefined4 *)(in_ECX + 0x68),
                                     *(undefined4 *)(in_ECX + 0x6c),*(undefined4 *)(in_ECX + 0x70),
                                     *(undefined4 *)(in_ECX + 0x74));
                        break;
                      case 2:
                        FUN_004988c0(local_294,*(undefined4 *)(in_ECX + 0x68),
                                     *(undefined4 *)(in_ECX + 0x6c),*(undefined4 *)(in_ECX + 0x70),
                                     *(undefined4 *)(in_ECX + 0x74));
                        FUN_004988c0(local_2a4,*(undefined4 *)(in_ECX + 0x78),
                                     *(undefined4 *)(in_ECX + 0x7c),*(undefined4 *)(in_ECX + 0x80),
                                     *(undefined4 *)(in_ECX + 0x84));
                        break;
                      case 3:
                        FUN_004988c0(local_2b4,*(undefined4 *)(in_ECX + 0x78),
                                     *(undefined4 *)(in_ECX + 0x7c),*(undefined4 *)(in_ECX + 0x80),
                                     *(undefined4 *)(in_ECX + 0x84));
                        FUN_004988c0(local_2c4,*(undefined4 *)(in_ECX + 8),
                                     *(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),
                                     *(undefined4 *)(in_ECX + 0x14));
                      }
                      dVar5 = local_54 - local_44;
                      dVar6 = local_4c - local_3c;
                      local_380 = dVar5;
                      if (dVar5 <= 0.0) {
                        local_380 = -dVar5;
                      }
                      local_378 = dVar6;
                      if (dVar6 <= 0.0) {
                        local_378 = -dVar6;
                      }
                      if (local_380 <= local_378) {
                        if (dVar6 == 0.0) {
                          if ((double)CONCAT44(param_3,param_2) - local_44 <= 0.0) {
                            local_370 = -((double)CONCAT44(param_3,param_2) - local_44);
                          }
                          else {
                            local_370 = (double)CONCAT44(param_3,param_2) - local_44;
                          }
                          if ((double)CONCAT44(param_5,param_4) - local_3c <= 0.0) {
                            local_330 = -((double)CONCAT44(param_5,param_4) - local_3c);
                          }
                          else {
                            local_330 = (double)CONCAT44(param_5,param_4) - local_3c;
                          }
                          local_2d0 = local_370 + local_330;
                        }
                        else {
                          local_2d0 = (double)CONCAT44(param_3,param_2) -
                                      ((((double)CONCAT44(param_5,param_4) - local_3c) * dVar5) /
                                       dVar6 + local_44);
                        }
                      }
                      else {
                        local_2d0 = (double)CONCAT44(param_5,param_4) -
                                    ((((double)CONCAT44(param_3,param_2) - local_44) * dVar6) /
                                     dVar5 + local_3c);
                      }
                      if (local_2d0 <= 0.0) {
                        local_368 = -local_2d0;
                      }
                      else {
                        local_368 = local_2d0;
                      }
                      if (local_368 < *(double *)(param_1 + 0x8ed0)) {
                        *(double *)(param_1 + 0x8ee0) = local_368;
                        ExceptionList = local_10;
                        return 1;
                      }
                    }
                    uVar4 = 0;
                  }
                  else {
                    *(double *)(param_1 + 0x8ee0) = local_328 + local_388;
                    uVar4 = 1;
                  }
                }
                else {
                  *(double *)(param_1 + 0x8ee0) = local_350 + local_338;
                  uVar4 = 1;
                }
              }
              else {
                *(double *)(param_1 + 0x8ee0) = local_348 + local_340;
                uVar4 = 1;
              }
            }
            else {
              *(double *)(param_1 + 0x8ee0) = local_360 + local_358;
              uVar4 = 1;
            }
          }
          else {
            uVar4 = 0;
          }
        }
        else {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    FUN_00408a60(uVar1);
    FUN_00408a60();
    FUN_0041f5f0();
    local_8 = 0;
    iVar2 = FUN_00437050(local_184);
    if (iVar2 == 0) {
      local_8 = 0xffffffff;
      FUN_0041fd50();
      uVar4 = 0;
    }
    else {
      iVar2 = FUN_0042b7d0(param_1,param_2,param_3,param_4,param_5);
      if (iVar2 == 0) {
        iVar2 = FUN_0043af40(&local_34,&local_24);
        iVar3 = FUN_0040c120();
        if ((iVar3 < 100) && (iVar2 == 0)) {
          local_8 = 0xffffffff;
          FUN_0041fd50();
          uVar4 = 0;
        }
        else {
          FUN_0041f760();
          local_8._0_1_ = 1;
          iVar2 = FUN_0040c120();
          if (iVar2 == 0) {
            FUN_004988c0(local_214,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                         *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
            FUN_004988c0(local_204,local_34,local_30,local_2c,local_28);
            iVar2 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
            if (iVar2 != 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fd70();
              local_8 = 0xffffffff;
              FUN_0041fd50();
              ExceptionList = local_10;
              return 1;
            }
            FUN_004988c0(local_1e4,local_24,local_20,local_1c,local_18);
            iVar2 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
            if (iVar2 != 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fd70();
              local_8 = 0xffffffff;
              FUN_0041fd50();
              ExceptionList = local_10;
              return 1;
            }
          }
          iVar2 = FUN_0040c120();
          if (iVar2 == 1) {
            FUN_004988c0(local_1d4,local_34,local_30,local_2c,local_28);
            FUN_004988c0(local_1c4,local_24,local_20,local_1c,local_18);
            iVar2 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
            if (iVar2 != 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fd70();
              local_8 = 0xffffffff;
              FUN_0041fd50();
              ExceptionList = local_10;
              return 1;
            }
          }
          iVar2 = FUN_0040c120();
          if (iVar2 == -1) {
            FUN_00408a60();
            iVar2 = FUN_0043a8d0(&local_84);
            if (iVar2 != 0) {
              FUN_004988c0(local_1b4,local_84,local_80,local_7c,local_78);
              FUN_004988c0(local_1a4,local_34,local_30,local_2c,local_28);
              iVar2 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
              if (iVar2 != 0) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0041fd70();
                local_8 = 0xffffffff;
                FUN_0041fd50();
                ExceptionList = local_10;
                return 1;
              }
              FUN_004988c0(local_1f4,local_24,local_20,local_1c,local_18);
              iVar2 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
              if (iVar2 != 0) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0041fd70();
                local_8 = 0xffffffff;
                FUN_0041fd50();
                ExceptionList = local_10;
                return 1;
              }
            }
          }
          iVar2 = FUN_0040c120();
          if (99 < iVar2) {
            iVar2 = (**(code **)(*(int *)(in_ECX + 0x1c0) + 0x44))
                              (param_1,param_2,param_3,param_4,param_5);
            if (iVar2 != 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fd70();
              local_8 = 0xffffffff;
              FUN_0041fd50();
              ExceptionList = local_10;
              return 1;
            }
            FUN_00408a60();
            FUN_00408a60();
            iVar2 = (**(code **)(*(int *)(in_ECX + 0x1c0) + 0x34))(&local_64,&local_74);
            if (iVar2 == 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fd70();
              local_8 = 0xffffffff;
              FUN_0041fd50();
              ExceptionList = local_10;
              return 0;
            }
            FUN_004988c0(local_224,local_64,local_60,local_5c,local_58);
            FUN_004988c0(local_234,local_34,local_30,local_2c,local_28);
            iVar2 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
            if (iVar2 != 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fd70();
              local_8 = 0xffffffff;
              FUN_0041fd50();
              ExceptionList = local_10;
              return 1;
            }
            FUN_004988c0(local_244,local_74,local_70,local_6c,local_68);
            FUN_004988c0(local_254,local_24,local_20,local_1c,local_18);
            iVar2 = FUN_0042c100(param_1,param_2,param_3,param_4,param_5);
            if (iVar2 != 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fd70();
              local_8 = 0xffffffff;
              FUN_0041fd50();
              ExceptionList = local_10;
              return 1;
            }
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0041fd70();
          local_8 = 0xffffffff;
          FUN_0041fd50();
          uVar4 = 0;
        }
      }
      else {
        local_8 = 0xffffffff;
        FUN_0041fd50();
        uVar4 = 1;
      }
    }
  }
  ExceptionList = local_10;
  return uVar4;
}




/* vtable slots: CDataSolid[5] */
/* 0042df20  FUN_0042df20  135 bytes, 5 callers */

undefined4 FUN_0042df20(void)

{
  uint uVar1;
  int iVar2;
  undefined4 in_ECX;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092182f;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_004121b0(600);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0041f780(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_004201b0(in_ECX);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CDataSolid[2] */
/* 0042ebf0  FUN_0042ebf0  1302 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042ebf0(CArchive *param_1)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  
  FUN_0042e690();
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    FUN_007a5922();
    FUN_00420650(in_ECX + 8);
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    if ((*(char *)(in_ECX + 0x28) == 'i') || (*(char *)(in_ECX + 0x28) == 'j')) {
      *(undefined8 *)(in_ECX + 0xa0) = *(undefined8 *)(in_ECX + 0x80);
      *(undefined8 *)(in_ECX + 0x80) = 0;
    }
    if (*(short *)(in_ECX + 0x2a) == 10) {
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x98));
    }
    if (DAT_00a0b414 < 0xe2) {
      *(undefined1 *)(in_ECX + 0x28) = 1;
    }
    if ((9 < *(byte *)(in_ECX + 0x28)) && (*(byte *)(in_ECX + 0x28) < 100)) {
      *(undefined1 *)(in_ECX + 0x28) = 1;
    }
  }
  else if (DAT_00a0b3e8 < 0xe6) {
    local_28 = *(double *)(in_ECX + 8);
    local_20 = *(double *)(in_ECX + 0x10);
    local_48 = *(double *)(in_ECX + 0x18);
    local_40 = *(double *)(in_ECX + 0x20);
    local_38 = *(double *)(in_ECX + 0x68);
    local_30 = *(double *)(in_ECX + 0x70);
    local_58 = *(double *)(in_ECX + 0x78);
    local_50 = *(double *)(in_ECX + 0x80);
    if (99 < *(byte *)(in_ECX + 0x28)) {
      if (*(double *)(in_ECX + 0x80) < 10.0) {
        local_28 = local_28 - *(double *)(in_ECX + 0x18);
        local_40 = local_20 - *(double *)(in_ECX + 0x18) * 0.57735;
        local_48 = *(double *)(in_ECX + 0x18) * 2.0 + local_28;
        local_38 = *(double *)(in_ECX + 8);
        local_30 = *(double *)(in_ECX + 0x18) * 1.73205 + local_40;
        FUN_004988c0();
        local_20 = local_40;
      }
      else {
        local_58 = local_28 - *(double *)(in_ECX + 0x18);
        local_40 = local_20 - *(double *)(in_ECX + 0x18);
        local_48 = *(double *)(in_ECX + 0x18) * 2.0 + local_58;
        local_50 = *(double *)(in_ECX + 0x18) * 2.0 + local_40;
        local_38 = local_48;
        local_30 = local_50;
        local_28 = local_58;
        local_20 = local_40;
      }
    }
    FUN_00420820(local_28);
    FUN_00420820(local_20);
    FUN_00420820(local_48);
    FUN_00420820(local_40);
    FUN_00420820(local_38);
    FUN_00420820(local_30);
    FUN_00420820(local_58);
    FUN_00420820(local_50);
    if (*(short *)(in_ECX + 0x2a) == 10) {
      CArchive::operator<<(param_1,*(long *)(in_ECX + 0x98));
    }
  }
  else {
    if ((*(char *)(in_ECX + 0x28) == 'i') || (*(char *)(in_ECX + 0x28) == 'j')) {
      *(undefined8 *)(in_ECX + 0x80) = *(undefined8 *)(in_ECX + 0xa0);
    }
    uVar8 = *(undefined8 *)(in_ECX + 0x80);
    uVar7 = *(undefined8 *)(in_ECX + 0x78);
    uVar6 = *(undefined8 *)(in_ECX + 0x70);
    uVar5 = *(undefined8 *)(in_ECX + 0x68);
    uVar4 = *(undefined8 *)(in_ECX + 0x20);
    uVar3 = *(undefined8 *)(in_ECX + 0x18);
    uVar2 = *(undefined8 *)(in_ECX + 0x10);
    FUN_00420820(*(undefined8 *)(in_ECX + 8));
    FUN_00420820(uVar2);
    FUN_00420820(uVar3);
    FUN_00420820(uVar4);
    FUN_00420820(uVar5);
    FUN_00420820(uVar6);
    FUN_00420820(uVar7);
    FUN_00420820(uVar8);
    if (*(short *)(in_ECX + 0x2a) == 10) {
      CArchive::operator<<(param_1,*(long *)(in_ECX + 0x98));
    }
    if ((*(char *)(in_ECX + 0x28) == 'i') || (*(char *)(in_ECX + 0x28) == 'j')) {
      *(undefined8 *)(in_ECX + 0x80) = 0;
    }
  }
  return;
}




/* vtable slots: CDataSolid[6] */
/* 0042f990  FUN_0042f990  25 bytes, 1 callers */

void FUN_0042f990(void)

{
  undefined4 in_ECX;
  
  FUN_004201b0(in_ECX);
  return;
}




/* vtable slots: CDataSolid[4] */
/* 00430e00  FUN_00430e00  530 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00430e00(int param_1)

{
  int local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  int local_b8;
  int local_b4;
  int local_b0;
  undefined1 local_ac [152];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092186b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_b4 = 0;
  FUN_0041f5f0(local_14);
  local_8 = 0;
  if (99 < *(byte *)(local_b0 + 0x28)) {
    FUN_00437050(local_ac);
    local_b4 = FUN_0040c120();
  }
  if ((local_b4 < 10) || (0x13 < local_b4)) {
    local_b8 = 0;
    FUN_0041fbd0();
    local_8 = CONCAT31(local_8._1_3_,1);
    local_dc = FUN_0042afb0(*(undefined1 *)(local_b0 + 0x2f),*(undefined1 *)(local_b0 + 0x2e),
                            *(undefined1 *)(local_b0 + 0x28),*(undefined2 *)(local_b0 + 0x2a));
    local_d8 = FUN_005db650(*(undefined2 *)(local_b0 + 0x2a));
    if (*(short *)(local_b0 + 0x2a) == 10) {
      local_d8 = FUN_005db680(*(undefined4 *)(local_b0 + 0x98),1);
    }
    local_d4 = *(undefined4 *)(local_b0 + 0xa8);
    local_d0 = 0;
    if (0 < *(int *)(local_b0 + 0xb0)) {
      local_d0 = 1;
      Add(*(undefined4 *)(local_b0 + 0xac));
    }
    if (local_dc != -999) {
      local_b8 = (**(code **)(param_1 + 0x4c158))("FILL_AREA_STYLE_COLOUR",&local_dc);
    }
    if (local_b8 < 0) {
      FUN_005e6520();
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0041fe90();
    local_8 = 0xffffffff;
    FUN_0041fd50();
  }
  else {
    FUN_00430260(param_1);
    local_8 = 0xffffffff;
    FUN_0041fd50();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataSolid[7] */
/* 00438b60  FUN_00438b60  323 bytes, 0 callers */

undefined4 FUN_00438b60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = FUN_0079d98a(&PTR_s_CDataSolid_009fe094);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_00438910(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else if ((*(short *)(in_ECX + 0x2a) == 10) &&
            (*(int *)(in_ECX + 0x98) != *(int *)(param_1 + 0x98))) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_00498960(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                           *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_00498960(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
                             *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24));
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          iVar1 = FUN_00498960(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                               *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x74));
          if (iVar1 == 0) {
            uVar2 = 0;
          }
          else {
            iVar1 = FUN_00498960(*(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x7c),
                                 *(undefined4 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x84));
            if (iVar1 == 0) {
              uVar2 = 0;
            }
            else {
              uVar2 = 1;
            }
          }
        }
      }
    }
  }
  return uVar2;
}



