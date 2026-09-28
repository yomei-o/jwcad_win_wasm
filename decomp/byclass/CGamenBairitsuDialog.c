/* CGamenBairitsuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CGamenBairitsuDialog[1] */
/* 004c6010  FUN_004c6010  68 bytes, 0 callers */

undefined4 FUN_004c6010(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004c5f10();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x920);
    }
  }
  return in_ECX;
}




/* vtable slots: CGamenBairitsuDialog[24] */
/* 004c6060  FUN_004c6060  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004c6060(void)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_00413f30();
    FUN_004146a0(&local_18);
    FUN_00517510(&DAT_00a0c11c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CGamenBairitsuDialog[64] */
/* 004c60e0  FUN_004c60e0  620 bytes, 0 callers */

void FUN_004c60e0(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880();
  FUN_0078fb9c();
  DDX_Text(param_1,0x5be,(double *)(in_ECX + 0x178));
  FUN_0079f95a(param_1,in_ECX + 0x178,0x3f847ae147ae147b,0x40f86a0000000000);
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  return;
}




/* vtable slots: CGamenBairitsuDialog[10] */
/* 004c6350  FUN_004c6350  16 bytes, 0 callers */

void FUN_004c6350(void)

{
  FUN_004c6360();
  return;
}




/* vtable slots: CGamenBairitsuDialog[94] */
/* 004c6530  FUN_004c6530  1366 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004c6530(void)

{
  undefined4 *puVar1;
  int iVar2;
  double local_7c;
  double local_74;
  double local_6c;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 auStack_30 [4];
  undefined4 uStack_20;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00798993();
  *(undefined4 *)(local_54 + 0xb0) = 0;
  *(undefined4 *)(local_54 + 0xb4) = 0;
  *(undefined4 *)(local_54 + 0xb8) = 0;
  *(undefined4 *)(local_54 + 0x200) = *(undefined4 *)(local_54 + 0xbc);
  *(undefined4 *)(local_54 + 0x204) = *(undefined4 *)(local_54 + 0xc0);
  if (*(int *)(*(int *)(local_54 + 0xa8) + 0x7984) == 0) {
    FUN_007979e8();
  }
  local_58 = 0;
  if (*(double *)(*(int *)(local_54 + 0xa8) + 0x1728) - 1.0 <= 0.0) {
    local_6c = -(*(double *)(*(int *)(local_54 + 0xa8) + 0x1728) - 1.0);
  }
  else {
    local_6c = *(double *)(*(int *)(local_54 + 0xa8) + 0x1728) - 1.0;
  }
  if (local_6c <= 1e-07) {
    if (*(double *)(*(int *)(local_54 + 0xa8) + 0x7a18) <= 0.0) {
      local_74 = -*(double *)(*(int *)(local_54 + 0xa8) + 0x7a18);
    }
    else {
      local_74 = *(double *)(*(int *)(local_54 + 0xa8) + 0x7a18);
    }
    if (local_74 <= 1e-07) {
      if (*(double *)(*(int *)(local_54 + 0xa8) + 0x7a20) <= 0.0) {
        local_7c = -*(double *)(*(int *)(local_54 + 0xa8) + 0x7a20);
      }
      else {
        local_7c = *(double *)(*(int *)(local_54 + 0xa8) + 0x7a20);
      }
      if (local_7c <= 1e-07) goto LAB_004c66ff;
    }
  }
  local_58 = 1;
LAB_004c66ff:
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  *(undefined4 *)(local_54 + 0xd0) = 0;
  *(undefined4 *)(local_54 + 0xcc) = 0;
  *(undefined4 *)(local_54 + 200) = 0;
  *(undefined4 *)(local_54 + 0xc4) = 0;
  local_5c = 1;
  do {
    if (4 < local_5c) {
      *(undefined4 *)(local_54 + 0xc4) = auStack_30[1];
      *(undefined4 *)(local_54 + 0x60c) = *(undefined4 *)(local_54 + 0xc4);
      *(undefined4 *)(local_54 + 200) = auStack_30[2];
      *(undefined4 *)(local_54 + 0x610) = *(undefined4 *)(local_54 + 200);
      *(undefined4 *)(local_54 + 0xcc) = auStack_30[3];
      *(undefined4 *)(local_54 + 0x614) = *(undefined4 *)(local_54 + 0xcc);
      *(undefined4 *)(local_54 + 0xd0) = uStack_20;
      *(undefined4 *)(local_54 + 0x618) = *(undefined4 *)(local_54 + 0xd0);
      local_58 = 1;
      FUN_007979e8();
      FUN_007979e8();
      FUN_007979e8();
      FUN_007979e8();
      *(undefined4 *)(local_54 + 0x61c) = 0;
      if (DAT_00a0d8d0 != 0) {
        *(undefined4 *)(local_54 + 0x61c) = 1;
      }
      FUN_007979e8();
      local_58 = 1;
      FUN_007979e8();
      FUN_007979e8();
      FUN_007979e8();
      FUN_007979e8();
      FUN_007955d2();
      FUN_004044d0();
      FUN_00413f30();
      FUN_004146a0(&local_40);
      iVar2 = FUN_00517b40(DAT_00a0c11c,DAT_00a0c120,local_40,local_3c,local_38,local_34,&local_64);
      if (iVar2 != 0) {
        FUN_00797e71(0,local_64,local_60,0,0,5);
      }
      if (0 < DAT_00a0d620) {
        FUN_004dbab0();
      }
      return 1;
    }
    auStack_30[local_5c] = 0;
    if (*(double *)(*(int *)(local_54 + 0xa8) + 0x7a70 + local_5c * 8) == 1.0) {
      puVar1 = (undefined4 *)FUN_00408a30(0,0);
      iVar2 = FUN_004989a0(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      if ((iVar2 != 0) || (-1 < *(int *)(*(int *)(local_54 + 0xa8) + 0x7b60 + local_5c * 4)))
      goto LAB_004c6831;
    }
    else {
LAB_004c6831:
      auStack_30[local_5c] = 1;
    }
    local_5c = local_5c + 1;
  } while( true );
}




/* vtable slots: CGamenBairitsuDialog[96] */
/* 004c6a90  FUN_004c6a90  1172 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004c6a90(void)

{
  double *pdVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  double local_4c;
  double local_44;
  double local_34;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_007955d2(1);
  if ((DAT_00a0cc6c == 0) || (DAT_00a0cc74 == 0)) {
    *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x7a38) =
         *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x1728);
    iVar3 = *(int *)(in_ECX + 0xa8);
    FUN_004988c0(local_18,*(undefined4 *)(iVar3 + 0x7a18),*(undefined4 *)(iVar3 + 0x7a1c),
                 *(undefined4 *)(iVar3 + 0x7a20),*(undefined4 *)(iVar3 + 0x7a24));
    if (*(int *)(in_ECX + 0xb0) == 0) {
      if (*(int *)(in_ECX + 0xb4) == 0) {
        if (*(int *)(in_ECX + 0xb8) == 0) {
          if ((0.01 <= *(double *)(in_ECX + 0x178)) && (*(double *)(in_ECX + 0x178) <= 100000.0)) {
            if (*(double *)(*(int *)(in_ECX + 0xa8) + 0x1780) <= 0.0) {
              local_4c = -*(double *)(*(int *)(in_ECX + 0xa8) + 0x1780);
            }
            else {
              local_4c = *(double *)(*(int *)(in_ECX + 0xa8) + 0x1780);
            }
            *(double *)(*(int *)(in_ECX + 0xa8) + 0x1728) =
                 (*(double *)(in_ECX + 0x178) * *(double *)(*(int *)(in_ECX + 0xa8) + 6000)) /
                 (*(double *)(*(int *)(in_ECX + 0xa8) + 0x1778) / local_4c);
            *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x1790) = 0;
          }
        }
        else {
          *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x1728) = *(undefined8 *)(in_ECX + 0xd8);
          FUN_004988c0(local_28,*(undefined4 *)(in_ECX + 0xe0),*(undefined4 *)(in_ECX + 0xe4),
                       *(undefined4 *)(in_ECX + 0xe8),*(undefined4 *)(in_ECX + 0xec));
          if ((-1 < *(int *)(in_ECX + 0xf0)) && (*(int *)(in_ECX + 0xf0) < 0x10)) {
            iVar3 = *(int *)(*(int *)(in_ECX + 0xa8) + 0x24e4);
            *(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x24e4) = *(undefined4 *)(in_ECX + 0xf0);
            iVar4 = *(int *)(*(int *)(in_ECX + 0xa8) + 0x24e4);
            *(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x23a4 + iVar3 * 4) = 2;
            *(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x23a4 + iVar4 * 4) = 3;
            uVar7 = 0;
            uVar6 = 0x8059;
            uVar5 = 0x111;
            FUN_00404c80(0x111,0x8059,0);
            FUN_00406bc0(uVar5,uVar6,uVar7);
            uVar7 = 0;
            uVar6 = 0x8057;
            uVar5 = 0x111;
            FUN_00404c80(0x111,0x8057,0);
            FUN_00406bc0(uVar5,uVar6,uVar7);
          }
        }
      }
      else {
        local_34 = *(double *)(*(int *)(in_ECX + 0xa8) + 0x79a0);
        dVar2 = *(double *)(*(int *)(in_ECX + 0xa8) + 0x79a0);
        pdVar1 = (double *)(*(int *)(in_ECX + 0xa8) + 0x79a8);
        if (*pdVar1 <= dVar2 && dVar2 != *pdVar1) {
          local_34 = *(double *)(*(int *)(in_ECX + 0xa8) + 0x79a8);
        }
        local_34 = local_34 / (double)*(int *)(*(int *)(in_ECX + 0xa8) + 0x7984);
        if (1e-06 < local_34) {
          *(double *)(*(int *)(in_ECX + 0xa8) + 0x1728) =
               (*(double *)(*(int *)(in_ECX + 0xa8) + 0x7990) *
               *(double *)(*(int *)(in_ECX + 0xa8) + 6000)) / local_34;
          *(double *)(*(int *)(in_ECX + 0xa8) + 0x1728) =
               *(double *)(*(int *)(in_ECX + 0xa8) + 0x1728) + 0.001;
        }
      }
    }
    else {
      if (*(double *)(*(int *)(in_ECX + 0xa8) + 0x1780) <= 0.0) {
        local_44 = -*(double *)(*(int *)(in_ECX + 0xa8) + 0x1780);
      }
      else {
        local_44 = *(double *)(*(int *)(in_ECX + 0xa8) + 0x1780);
      }
      *(double *)(*(int *)(in_ECX + 0xa8) + 0x1728) =
           (*(double *)(*(int *)(in_ECX + 0xa8) + 6000) * 1.0) /
           (*(double *)(*(int *)(in_ECX + 0xa8) + 0x1778) / local_44);
    }
    DAT_00a0d8d0 = (uint)(*(int *)(in_ECX + 0x61c) != 0);
    FUN_00798a09();
  }
  else {
    *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x1790) = *(undefined8 *)(in_ECX + 0x178);
    FUN_00798a09();
  }
  return;
}



