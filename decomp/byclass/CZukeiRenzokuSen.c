/* CZukeiRenzokuSen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiRenzokuSen[1] */
/* 006d7c50  FUN_006d7c50  68 bytes, 0 callers */

undefined4 FUN_006d7c50(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006d7b90();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x4d0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiRenzokuSen[6] */
/* 006d7ca0  FUN_006d7ca0  2892 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x006d8419) */
/* WARNING: Removing unreachable block (ram,0x006d85c5) */
/* WARNING: Removing unreachable block (ram,0x006d83e8) */

void FUN_006d7ca0(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  float10 fVar5;
  undefined1 local_6818 [20];
  undefined4 local_6804;
  undefined4 local_6800;
  undefined4 local_67fc;
  int local_67f8;
  int local_67f4;
  int *local_67f0;
  undefined1 local_41c [16];
  undefined1 local_40c [16];
  undefined1 local_3fc [400];
  undefined2 local_26c [200];
  undefined2 local_dc [100];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e32b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8ebc) = 0;
  local_67f0 = in_ECX;
  local_14 = uVar1;
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2(local_67f0[1]);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar2 = FUN_0040c0e0();
  FUN_00404c80(uVar1,uVar2);
  iVar3 = FUN_004fca20();
  local_67f0[0x2b] = *(int *)(*(int *)(iVar3 + 0x1a0) + 0xe0);
  FUN_00404c80();
  FUN_004fca20();
  fVar5 = (float10)FUN_005b8450();
  *(double *)(local_67f0 + 0x116) = (double)fVar5;
  FUN_00404c80();
  FUN_004fca20();
  fVar5 = (float10)FUN_005b8390();
  *(double *)(local_67f0 + 0x114) = (double)fVar5;
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  *(undefined8 *)(local_67f0 + 0x112) = *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0xc0);
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  local_67f0[0x119] = *(int *)(*(int *)(iVar3 + 0x1a0) + 200);
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  local_67f0[0x2d] = *(int *)(*(int *)(iVar3 + 0x1a0) + 0x780);
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(double *)(*(int *)(iVar3 + 0x1a0) + 0xc0) < 0.7853980633974483) {
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    if (*(double *)(*(int *)(iVar3 + 0x1a0) + 0xc0) < 0.2617992877991494) {
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      if (-1e-07 <= *(double *)(*(int *)(iVar3 + 0x1a0) + 0xc0)) {
        DAT_00a0be90 = 0;
      }
    }
    else {
      DAT_00a0be90 = 1;
    }
  }
  else {
    DAT_00a0be90 = 2;
  }
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  DAT_00a0be98 = *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0xd0);
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  DAT_00a0bea0 = (uint)(*(int *)(*(int *)(iVar3 + 0x1a0) + 200) != 0);
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  DAT_00a0bea4 = (uint)(*(int *)(*(int *)(iVar3 + 0x1a0) + 0x6f8) != 0);
  if (local_67f0[0x2d] != local_67f0[0x2e]) {
    (**(code **)(*local_67f0 + 0x10))();
    local_67f0[0x2e] = local_67f0[0x2d];
    local_67f0[0x3e] = 0;
    local_67f0[0x2a] = 0;
  }
  if (local_67f0[0x2d] == 0) {
    if (local_67f0[0x2c] != local_67f0[0x2b]) {
      local_67f0[0x2c] = local_67f0[0x2b];
      if (((local_67f0[0x2b] == 1) && (local_67f0[0x2f] == 0)) && (local_67f0[0x2a] == 3)) {
        local_67f0[0x11a] = 0;
        local_67f0[0x2a] = 2;
        FUN_0044dd90(local_6818,local_67f0[1]);
        FUN_0044de00(local_6818,local_67f0[1]);
      }
      if (local_67f0[0x2b] == 0) {
        (**(code **)(*local_67f0 + 0x68))();
      }
    }
    if (local_67f0[0x11a] != 0) {
      if (local_67f0[0x11b] == *(int *)(local_67f0[1] + 0x8f58) ||
          local_67f0[0x11b] - *(int *)(local_67f0[1] + 0x8f58) < 0) {
        local_67f4 = -(local_67f0[0x11b] - *(int *)(local_67f0[1] + 0x8f58));
      }
      else {
        local_67f4 = local_67f0[0x11b] - *(int *)(local_67f0[1] + 0x8f58);
      }
      if (local_67f0[0x11c] == *(int *)(local_67f0[1] + 0x8f5c) ||
          local_67f0[0x11c] - *(int *)(local_67f0[1] + 0x8f5c) < 0) {
        local_67f8 = -(local_67f0[0x11c] - *(int *)(local_67f0[1] + 0x8f5c));
      }
      else {
        local_67f8 = local_67f0[0x11c] - *(int *)(local_67f0[1] + 0x8f5c);
      }
      if (local_67f4 + local_67f8 < 3) {
        FUN_004efbb0(0x150b,0,0);
        local_8 = local_8 & 0xffffff00;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      local_67f0[0x34] = 0;
      local_67f0[0x11a] = 0;
      local_67f0[0x2a] = 2;
    }
    if ((local_67f0[0x2a] == 0) || (local_67f0[0x2a] == 1)) {
      *(undefined4 *)(local_67f0[1] + 0x8ebc) = 1;
      if (local_67f0[0x2b] == 0) {
        FUN_004efbb0(0x14c8,0,0);
      }
      else {
        uVar2 = 0x62;
        FUN_005977f0(0x150a);
        uVar2 = FUN_00404920(uVar2);
        FUN_006d74b0(local_3fc,uVar2);
        FUN_00404770();
        FUN_004efbb0(0x14b8,local_3fc,0);
      }
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (local_67f0[0x2a] == 2) {
      FUN_004efbb0(0x1509,0,0);
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (local_67f0[0x2a] == 3) {
      local_67fc = 0;
      local_26c[0] = 0;
      local_6800 = 0;
      local_dc[0] = 0;
      if (local_67f0[0x2f] != 0) {
        FUN_006d7490(local_26c,L"       ");
        uVar2 = 0x62;
        FUN_005977f0(0x1516);
        uVar2 = FUN_00404920(uVar2);
        FUN_0060afc0(local_dc,uVar2);
        FUN_00404770();
        FUN_005f0840(local_dc,&DAT_0095b620);
        if (local_67f0[0x132] == 0x231d) {
          FUN_005977f0(0x1b5e);
          uVar2 = FUN_00404920();
          FUN_006d7470(local_26c,uVar2);
          FUN_00404770();
          FUN_006d7470(local_26c,local_dc);
          uVar2 = 0x62;
          FUN_005977f0(0x1460);
          uVar2 = FUN_00404920(uVar2);
          FUN_0060afc0(local_dc,uVar2);
          FUN_00404770();
          FUN_006d7470(local_26c,local_dc);
          FUN_005977f0(7000);
          uVar2 = FUN_00404920();
          FUN_006d7470(local_26c,uVar2);
          FUN_00404770();
        }
        else {
          iVar3 = FUN_00436970(*param_1,param_1[1],param_1[2],param_1[3],local_67f0[0x12e],
                               local_67f0[0x12f],local_67f0[0x130],local_67f0[0x131]);
          if (iVar3 == 0) {
            local_6804 = 0;
            local_26c[0] = 0;
          }
          else {
            FUN_006d7470(local_26c,&DAT_0097a1c4);
            FUN_006d7470(local_26c,local_dc);
            uVar2 = 0x62;
            FUN_005977f0(0x145f);
            uVar2 = FUN_00404920(uVar2);
            FUN_0060afc0(local_dc,uVar2);
            FUN_00404770();
            FUN_006d7470(local_26c,local_dc);
            FUN_006d7470(local_26c,&DAT_0097a1cc);
          }
        }
      }
      FUN_004efbb0(0x14c9,local_26c,0);
      puVar4 = (undefined4 *)FUN_004988c0(local_40c,*param_1,param_1[1],param_1[2],param_1[3]);
      FUN_004988c0(local_41c,*puVar4,puVar4[1],puVar4[2],puVar4[3]);
      FUN_0044dd90(local_6818,local_67f0[1]);
      FUN_0044de00(local_6818,local_67f0[1]);
      (**(code **)(*local_67f0 + 0x20))();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    if ((local_67f0[0x2a] == 0) || (local_67f0[0x2a] == 1)) {
      *(undefined4 *)(local_67f0[1] + 0x8ebc) = 1;
      FUN_004efbb0(0x14c8,0,0);
    }
    if (local_67f0[0x2a] == 3) {
      FUN_004efbb0(0x14c9,0,0);
      FUN_006df0f0(*param_1,param_1[1],param_1[2],param_1[3]);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiRenzokuSen[16] */
/* 006d87f0  FUN_006d87f0  2179 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006d87f0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_6494 [8];
  undefined1 local_648c [8];
  undefined4 local_6484;
  undefined4 local_6480;
  undefined4 local_647c;
  undefined4 local_6478;
  undefined4 local_6474;
  undefined4 local_6470;
  undefined4 local_646c;
  undefined4 local_6468;
  int local_6464;
  undefined4 local_6460;
  undefined4 local_645c;
  undefined1 local_6458 [20];
  int local_6444;
  undefined4 local_6440;
  CMFCCaptionButtonEx *local_643c;
  int local_6438;
  undefined1 local_64 [32];
  undefined1 local_44 [32];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e37b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6438 + 4));
  local_8._0_1_ = 1;
  local_6440 = FUN_0040c0e0();
  *(undefined4 *)(local_6438 + 0x308) = 0;
  *(undefined4 *)(local_6438 + 0x3a8) = 0;
  if (*(int *)(local_6438 + 0xb4) == 0) {
    FUN_0044dd90(local_6458,*(undefined4 *)(local_6438 + 4));
    FUN_0044de00(local_6458,*(undefined4 *)(local_6438 + 4));
    if (((*(int *)(local_6438 + 0xa8) == 3) || (*(int *)(local_6438 + 0xa8) == 2)) &&
       (*(int *)(local_6438 + 0xbc) == 0)) {
      if ((*(int *)(local_6438 + 0xac) == 1) && (*(int *)(local_6438 + 0xa8) == 3)) {
        *(undefined4 *)(local_6438 + 0xa8) = 2;
      }
      else {
        *(undefined4 *)(local_6438 + 0xa8) = 0;
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_646c = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_645c = local_646c;
    }
    else {
      local_6444 = FUN_00572180();
      do {
        if (local_6444 == 0) {
          local_6470 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return local_6470;
        }
        local_643c = (CMFCCaptionButtonEx *)FUN_00572140(&local_6444,0);
        if (local_643c == (CMFCCaptionButtonEx *)0x0) {
          local_6474 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return local_6474;
        }
        iVar2 = FUN_00610960();
      } while (iVar2 != 0);
      *(undefined4 *)(local_6438 + 0xc4) = 0;
      iVar2 = FUN_0040c140();
      if (((iVar2 == 0) && (iVar2 = FUN_00610960(), iVar2 == 0)) &&
         (iVar2 = FUN_004423b0(), iVar2 == 0)) {
        *(undefined4 *)(local_6438 + 0xd0) = 0;
        *(undefined4 *)(local_6438 + 0xc0) = 0;
        *(undefined4 *)(local_6438 + 0x468) = 0;
        if ((*(int *)(local_6438 + 0xbc) == 1) || (*(int *)(local_6438 + 0xa8) != 0)) {
          *(undefined4 *)(local_6438 + 0xa8) = 0;
          *(undefined4 *)(local_6438 + 0xbc) = 0;
          FUN_00404c80();
          FUN_0056d7d0();
          local_6478 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_645c = local_6478;
        }
        else {
          local_647c = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_645c = local_647c;
        }
      }
      else {
        iVar2 = FUN_004423b0();
        if ((iVar2 == 1) && (*(int *)(local_6438 + 0xbc) == 1)) {
          *(undefined4 *)(local_6438 + 0xd0) = 0;
          *(undefined4 *)(local_6438 + 0xc0) = 0;
          *(undefined4 *)(local_6438 + 0x468) = 0;
          *(undefined4 *)(local_6438 + 0xa8) = 0;
          *(undefined4 *)(local_6438 + 0xbc) = 0;
          FUN_00404c80();
          FUN_0056d7d0();
          local_6480 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_645c = local_6480;
        }
        else {
          iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
          if (iVar2 == 0) {
            iVar2 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
            if (iVar2 != 0) {
              FUN_00420020(local_643c);
              *(int *)(local_6438 + 0xc0) = local_6438 + 0x1d8;
              *(undefined4 *)(local_6438 + 0xa8) = 3;
              *(undefined4 *)(local_6438 + 0xbc) = 1;
            }
          }
          else {
            FUN_00420110(local_643c);
            FUN_00420110(local_643c);
            puVar3 = (undefined4 *)CMFCCaptionButtonEx::GetRect(local_643c);
            FUN_004988c0(local_44,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
            puVar3 = (undefined4 *)CMFCCaptionButtonEx::GetRect(local_643c);
            FUN_004988c0(local_64,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
            *(int *)(local_6438 + 0xc0) = local_6438 + 0x108;
            *(undefined4 *)(local_6438 + 0xa8) = 3;
            *(undefined4 *)(local_6438 + 0xbc) = 1;
          }
          FUN_00458a80(local_6458,*(undefined4 *)(local_6438 + 4),0);
          iVar2 = FUN_004146c0();
          if (iVar2 == 0) {
            FUN_004d2660();
          }
          FUN_00404c80();
          FUN_0056d7d0();
          local_6484 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_645c = local_6484;
        }
      }
    }
  }
  else if (*(int *)(local_6438 + 0xf8) < 1) {
    local_645c = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    iVar2 = FUN_004146c0();
    if (iVar2 == 0) {
      local_6444 = FUN_00572180();
      local_6464 = FUN_00572000(&local_6444);
      FUN_004988c0(local_24,*(undefined4 *)(local_6464 + 8),*(undefined4 *)(local_6464 + 0xc),
                   *(undefined4 *)(local_6464 + 0x10),*(undefined4 *)(local_6464 + 0x14));
      puVar3 = (undefined4 *)
               FUN_004b6d60(local_648c,*(undefined4 *)(local_6438 + 0xe8),
                            *(undefined4 *)(local_6438 + 0xec),*(undefined4 *)(local_6438 + 0xf0),
                            *(undefined4 *)(local_6438 + 0xf4));
      uVar1 = puVar3[1];
      *(undefined4 *)(local_6438 + 0xfc) = *puVar3;
      *(undefined4 *)(local_6438 + 0x100) = uVar1;
      FUN_004fd520(local_6494,*(undefined4 *)(local_6438 + 0xe8),*(undefined4 *)(local_6438 + 0xec),
                   *(undefined4 *)(local_6438 + 0xf0),*(undefined4 *)(local_6438 + 0xf4));
      if (0 < *(int *)(local_6438 + 0xf8)) {
        *(int *)(local_6438 + 0xf8) = *(int *)(local_6438 + 0xf8) + -1;
      }
      if (*(int *)(local_6438 + 0xf8) < 1) {
        *(undefined4 *)(local_6438 + 0xa8) = 0;
      }
      FUN_00458a80(local_6458,*(undefined4 *)(local_6438 + 4),0);
      iVar2 = FUN_004146c0();
      if (iVar2 == 0) {
        FUN_004d2660();
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_6468 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_645c = local_6468;
    }
    else {
      local_6460 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_645c = local_6460;
    }
  }
  ExceptionList = local_10;
  return local_645c;
}




/* vtable slots: CZukeiRenzokuSen[0] */
/* 006d9080  FUN_006d9080  16 bytes, 0 callers */

undefined ** FUN_006d9080(void)

{
  return &PTR_s_CZukeiRenzokuSen_0097a0b0;
}




/* vtable slots: CZukeiRenzokuSen[23] */
/* 006d9090  FUN_006d9090  160 bytes, 0 callers */

undefined4 FUN_006d9090(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0x2d] == 1) {
    uVar1 = 0;
  }
  else {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(in_ECX[1] + 0x8654)) {
      if (in_ECX[0x2b] == 0) {
        if (DAT_00a0cc6c == 0) {
          FUN_00404c80();
          FUN_004fca20();
          FUN_006d99f0();
        }
        else {
          FUN_00404c80();
          FUN_004fca20();
          FUN_006d9a10();
        }
        uVar1 = 1;
      }
      else {
        (**(code **)(*in_ECX + 0x70))();
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}




/* vtable slots: CZukeiRenzokuSen[46] */
/* 006d9130  FUN_006d9130  231 bytes, 0 callers */

undefined4
FUN_006d9130(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_c [2];
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_c[0] = 0xffffffff;
      iVar2 = FUN_00778a40(1,local_c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,10);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiRenzokuSen[47] */
/* 006d9220  FUN_006d9220  1035 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006d9220(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_6404;
  undefined4 local_6400;
  int local_63fc;
  int local_63f8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937a9b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (DAT_00a0c7c0 == 0) {
    local_63f8 = in_ECX;
    if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
      local_6404 = 0xffffffff;
      iVar3 = FUN_00778a40(2,&local_6404,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9074),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,10);
      if (iVar3 != 0) {
        ExceptionList = local_10;
        return 0;
      }
    }
    local_6400 = 0;
    FUN_00446aa0(uVar1);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
    local_8._0_1_ = 1;
    if ((*(int *)(local_63f8 + 0xac) == 0) && (*(int *)(*(int *)(local_63f8 + 4) + 0x907c) == 0)) {
      if (param_2 == 0xc) {
        if (param_3 == 1) {
          FUN_005168b0(0x1804,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f50),
                       *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          local_63fc = 0;
          local_d0 = 1;
          local_cc = 1;
          iVar3 = FUN_0044a270(3,*(undefined4 *)(local_63f8 + 4),&param_4,&local_63fc,1);
          if (iVar3 != 0) {
            iVar3 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
            if (iVar3 == 0) {
              FUN_005168b0(0x277e,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 0;
            }
            if ((*(int *)(local_63f8 + 0xa8) == 0) || (*(int *)(local_63f8 + 0xa8) == 1)) {
              *(undefined4 *)(local_63f8 + 0x308) = 1;
              FUN_00420020(local_63fc);
            }
            else {
              *(undefined4 *)(local_63f8 + 0x3a8) = 1;
              FUN_00420020(local_63fc);
            }
            FUN_004988c0(local_24,*(undefined4 *)(local_63fc + 8),*(undefined4 *)(local_63fc + 0xc),
                         *(undefined4 *)(local_63fc + 0x10),*(undefined4 *)(local_63fc + 0x14));
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 1;
          }
        }
      }
      else {
        local_6400 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
    }
    else {
      local_6400 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    uVar2 = local_6400;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    uVar2 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiRenzokuSen[25] */
/* 006d9630  FUN_006d9630  103 bytes, 0 callers */

void FUN_006d9630(void)

{
  int *in_ECX;
  undefined4 uVar1;
  
  uVar1 = 0;
  FUN_00404c80(0);
  FUN_004fca20();
  FUN_005b8360(uVar1);
  (**(code **)(*in_ECX + 0x10))();
  in_ECX[0xc2] = 0;
  in_ECX[0xea] = 0;
  *(undefined4 *)(in_ECX[1] + 0x8578) = 1;
  FUN_00404c80();
  FUN_0056d200();
  return;
}




/* vtable slots: CZukeiRenzokuSen[26], CZukeiRenzokuSen[27] */
/* 006d96a0  FUN_006d96a0  19 bytes, 1 callers */

void FUN_006d96a0(void)

{
  FUN_006d9740();
  return;
}




/* vtable slots: CZukeiRenzokuSen[28] */
/* 006d96c0  FUN_006d96c0  63 bytes, 0 callers */

void FUN_006d96c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x460) == 0) {
    *(undefined4 *)(in_ECX + 0x460) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x460) = 0;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiRenzokuSen[36] */
/* 006d9700  FUN_006d9700  52 bytes, 0 callers */

void FUN_006d9700(void)

{
  int *in_ECX;
  
  if ((in_ECX[0x2f] != 0) && (in_ECX[0x2a] == 3)) {
    (**(code **)(*in_ECX + 100))();
  }
  return;
}




/* vtable slots: CZukeiRenzokuSen[50] */
/* 006d9a30  FUN_006d9a30  219 bytes, 0 callers */

void FUN_006d9a30(double param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80(param_1);
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x6f8) == 0) {
    param_1 = param_1 / *(double *)
                         (*(int *)(in_ECX + 4) + 0x2578 +
                         *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
  }
  else if (DAT_00a0d62c != 0) {
    param_1 = param_1 / DAT_00a0d630;
  }
  FUN_00404c80(param_1);
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xe0) == 0) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_005b82c0(param_1);
  }
  else {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_005b8310(param_1);
  }
  return;
}




/* vtable slots: CZukeiRenzokuSen[51] */
/* 006d9b10  FUN_006d9b10  283 bytes, 0 callers */

void FUN_006d9b10(undefined4 param_1,undefined4 param_2,double param_3)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a22d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80(uVar1,param_3);
  iVar2 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0x6f8) == 0) {
    param_3 = param_3 / *(double *)
                         (*(int *)(in_ECX + 4) + 0x2578 +
                         *(int *)(*(int *)(in_ECX + 4) + 0x256c) * 8);
  }
  else if (DAT_00a0d62c != 0) {
    param_3 = param_3 / DAT_00a0d630;
  }
  FUN_00404c80(uVar1,param_3);
  iVar2 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xe0) == 0) {
    FUN_00404c80(param_3);
    FUN_004fca20();
    FUN_005b82c0(param_3);
  }
  else {
    FUN_00404c80(param_3);
    FUN_004fca20();
    FUN_005b8310(param_3);
  }
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiRenzokuSen[9] */
/* 006d9ef0  FUN_006d9ef0  2430 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006d9ef0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_648c;
  int *local_6488;
  undefined4 local_160;
  undefined4 local_15c;
  undefined1 local_b4 [16];
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
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e420;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  *(undefined4 *)(local_6488[1] + 0x8560) = 0;
  local_6488[0x132] = param_1;
  if (local_6488[0x2d] == 0) {
    if ((local_6488[0x2a] == 0) || (local_6488[0x2a] == 1)) {
      puVar1 = (undefined4 *)FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
      FUN_004988c0(local_44,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
      local_6488[0x30] = 0;
      local_6488[0x31] = 0;
      local_6488[0x2f] = 0;
      if (local_6488[0x2b] == 0) {
        local_6488[0x11a] = 0;
        local_6488[0x2a] = 3;
      }
      else {
        if (param_1 == 0x231d) {
          local_6488[0x34] = 0;
          local_6488[0x11a] = 0;
          local_6488[0x2a] = 2;
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        if (local_6488[0x11a] == 0) {
          iVar2 = *(int *)(local_6488[1] + 0x8f5c);
          local_6488[0x11b] = *(int *)(local_6488[1] + 0x8f58);
          local_6488[0x11c] = iVar2;
          local_6488[0x11a] = 1;
          local_6488[0x34] = 0;
        }
        else {
          local_160 = 1;
          local_15c = 1;
          local_648c = (int *)0x0;
          iVar2 = FUN_0044a270(3,local_6488[1],&param_2,&local_648c,1);
          if (iVar2 == 0) {
            local_6488[0x34] = 0;
            local_6488[0x11a] = 0;
          }
          else {
            if (local_6488[0x33] != 0) {
              if ((int *)local_6488[0x33] != (int *)0x0) {
                (**(code **)(*(int *)local_6488[0x33] + 4))(1);
              }
              local_6488[0x33] = 0;
            }
            if (local_648c != (int *)0x0) {
              iVar2 = (**(code **)(*local_648c + 0x14))();
              local_6488[0x33] = iVar2;
            }
            local_6488[0x34] = local_6488[0x33];
            FUN_004988c0(local_64,param_2,param_3,param_4,param_5);
            local_6488[0x11a] = 0;
            local_6488[0x2a] = 3;
          }
        }
      }
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (local_6488[0x2a] == 2) {
      iVar2 = FUN_00436970(param_2,param_3,param_4,param_5,local_6488[0x11e],local_6488[0x11f],
                           local_6488[0x120],local_6488[0x121]);
      if (iVar2 == 0) {
        local_6488[0x2a] = 3;
        FUN_004988c0(local_74,param_2,param_3,param_4,param_5);
        FUN_004988c0(local_84,param_2,param_3,param_4,param_5);
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        FUN_005168b0(0x14df,*(undefined4 *)(local_6488[1] + 0x8f24),
                     *(undefined4 *)(local_6488[1] + 0x8f28),0,0);
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else if (local_6488[0x2a] == 3) {
      iVar2 = FUN_00436970(param_2,param_3,param_4,param_5,local_6488[0x12e],local_6488[0x12f],
                           local_6488[0x130],local_6488[0x131]);
      if (iVar2 == 0) {
        puVar1 = (undefined4 *)FUN_004988c0(local_94,param_2,param_3,param_4,param_5);
        puVar1 = (undefined4 *)FUN_004988c0(local_a4,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
        FUN_004988c0(local_b4,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
        local_6488[0x2a] = 4;
        (**(code **)(*local_6488 + 0xc))();
        if (local_6488[0x2a] == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          local_6488[0x2a] = 3;
          uVar3 = 1;
          FUN_00404c80(1);
          FUN_004fca20();
          FUN_005b8360(uVar3);
          local_6488[0xc2] = 0;
          local_6488[0xea] = 0;
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
      }
      else if (local_6488[0x2f] == 0) {
        FUN_005168b0(0x14df,*(undefined4 *)(local_6488[1] + 0x8f24),
                     *(undefined4 *)(local_6488[1] + 0x8f28),0,0);
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        uVar3 = 0;
        FUN_00404c80(0);
        FUN_004fca20();
        FUN_005b8360(uVar3);
        (**(code **)(*local_6488 + 0x10))();
        *(undefined4 *)(local_6488[1] + 0x8578) = 1;
        FUN_00404c80();
        FUN_0056d200();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else if ((local_6488[0x2a] == 0) || (local_6488[0x2a] == 1)) {
    FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
    iVar2 = *(int *)(local_6488[1] + 0x8f5c);
    local_6488[0x3f] = *(int *)(local_6488[1] + 0x8f58);
    local_6488[0x40] = iVar2;
    local_6488[0x3e] = 0;
    local_6488[0x2a] = 3;
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    if (local_6488[0x2a] == 3) {
      FUN_006df0f0(param_2,param_3,param_4,param_5);
      local_6488[0x2a] = 0;
      *(undefined4 *)(local_6488[1] + 0x8578) = 1;
      FUN_00404c80();
      FUN_0056d200();
    }
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukeiRenzokuSen[13] */
/* 006da870  FUN_006da870  58 bytes, 0 callers */

void FUN_006da870(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x2c))(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CZukeiRenzokuSen[11] */
/* 006da8b0  FUN_006da8b0  1043 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006da8b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 local_6438;
  undefined4 local_6434;
  undefined4 local_6430;
  int local_642c;
  int *local_6428;
  undefined1 local_54 [16];
  undefined1 local_44 [16];
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
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e460;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8560) = 0;
  local_6428 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  if ((local_6428[0x2d] == 1) && (local_6428[0x2a] == 3)) {
    local_6430 = FUN_0040c0e0();
    iVar1 = FUN_004146c0();
    if (iVar1 == 0) {
      local_6438 = FUN_00572180();
      local_642c = FUN_00572000(&local_6438);
      local_34 = *(undefined4 *)(local_642c + 0x18);
      local_30 = *(undefined4 *)(local_642c + 0x1c);
      local_2c = *(undefined4 *)(local_642c + 0x20);
      local_28 = *(undefined4 *)(local_642c + 0x24);
      *(undefined8 *)(local_642c + 0x18) = 0xc448650127cc3dc8;
      iVar1 = FUN_00451eb0(local_6428[1],&local_24,1);
      if (iVar1 == 0) {
        FUN_004988c0(local_44,local_34,local_30,local_2c,local_28);
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6434 = 0;
      }
      else {
        FUN_004988c0(local_54,local_34,local_30,local_2c,local_28);
        local_6428[0x3f] = -30000;
        FUN_006df0f0(local_24,local_20,local_1c,local_18);
        local_6428[0x2a] = 0;
        *(undefined4 *)(local_6428[1] + 0x8578) = 1;
        FUN_00404c80();
        FUN_0056d200();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6434 = 0;
      }
    }
    else {
      local_6434 = 0;
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    if ((local_6428[0x2f] == 1) &&
       ((local_6428[0x132] == 0x231d &&
        (iVar1 = FUN_0045c5b0(local_6428[1],param_2,param_3,param_4,param_5,local_6428[0x12e],
                              local_6428[0x12f],local_6428[0x130],local_6428[0x131]), iVar1 != 0))))
    {
      uVar2 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_005b8360(uVar2);
      (**(code **)(*local_6428 + 0x10))();
      *(undefined4 *)(local_6428[1] + 0x8578) = 1;
      FUN_00404c80();
      FUN_0056d200();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = FUN_00451eb0(local_6428[1],&local_24,1);
    if (iVar1 == 1) {
      local_6434 = FUN_006d9ef0(0x231d,local_24,local_20,local_1c,local_18);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6434 = 0;
    }
  }
  ExceptionList = local_10;
  return local_6434;
}




/* vtable slots: CZukeiRenzokuSen[8] */
/* 006dacd0  FUN_006dacd0  910 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006dacd0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e4ab;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  FUN_00446aa0(uVar1);
  local_8._0_1_ = 1;
  if (((*(int *)(in_ECX + 0xa8) == 0) || (*(int *)(in_ECX + 0xa8) == 1)) ||
     (*(int *)(in_ECX + 0xa8) == 2)) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(in_ECX + 0xac) != 0) {
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    if (*(int *)(in_ECX + 0xbc) == 0) {
      if (*(int *)(in_ECX + 0xd0) == 0) {
        iVar2 = FUN_006db410();
        if (iVar2 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          ExceptionList = local_10;
          return;
        }
      }
      else {
        *(undefined4 *)(in_ECX + 0xc0) = 0;
        iVar2 = FUN_006dc260(*(undefined4 *)(in_ECX + 0xd0));
        if (iVar2 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          ExceptionList = local_10;
          return;
        }
      }
    }
    else {
      if (*(int *)(in_ECX + 0xc0) == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return;
      }
      iVar2 = FUN_006dc260(*(undefined4 *)(in_ECX + 0xc0));
      if (iVar2 == 0) goto LAB_006db01a;
    }
    if (*(int *)(in_ECX + 0xa8) == 4) {
      *(undefined4 *)(in_ECX + 0xbc) = 1;
    }
    goto LAB_006daff7;
  }
  if (*(int *)(in_ECX + 0xbc) == 0) {
    iVar2 = FUN_006de7a0();
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      ExceptionList = local_10;
      return;
    }
  }
  else {
    if (*(int *)(in_ECX + 0xc0) == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      ExceptionList = local_10;
      return;
    }
    iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
    if (iVar2 == 0) {
      iVar2 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
      if (iVar2 == 0) goto LAB_006dafd8;
      iVar2 = FUN_006dbca0(*(undefined4 *)(in_ECX + 0xc0));
    }
    else {
      iVar2 = FUN_006dcff0(*(undefined4 *)(in_ECX + 0xc0));
    }
    if (iVar2 == 0) {
LAB_006db01a:
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100(uVar1,0);
      local_8 = 0xffffffff;
      FUN_0079dfff();
      ExceptionList = local_10;
      return;
    }
  }
LAB_006dafd8:
  if (*(int *)(in_ECX + 0xa8) == 4) {
    *(undefined4 *)(in_ECX + 0xbc) = 1;
  }
LAB_006daff7:
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiRenzokuSen[4] */
/* 006db060  FUN_006db060  640 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006db060(void)

{
  int iVar1;
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  undefined4 local_63f0;
  int *local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937dcb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044dd90(local_6408,*(undefined4 *)(local_63e8 + 4));
  FUN_0044de00(local_6408,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(local_63e8 + 0xc4) = 0;
  if (*(int *)(local_63e8 + 0xc0) != 0) {
    iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
    if (iVar1 != 0) {
      *(int *)(local_63e8 + 0xc0) = local_63e8 + 0x170;
    }
  }
  *(undefined4 *)(local_63e8 + 0xa8) = 4;
  local_63f0 = 0;
  FUN_006d9c30(local_6408,local_63e4,0);
  if (*(int *)(local_63e8 + 200) != 0) {
    FUN_00615500(1);
  }
  *(undefined4 *)(local_63e8 + 0xa8) = 0;
  *(undefined4 *)(local_63e8 + 0xc0) = 0;
  *(undefined4 *)(local_63e8 + 0xc4) = 0;
  *(undefined4 *)(local_63e8 + 0xd0) = 0;
  *(undefined4 *)(local_63e8 + 0x308) = 0;
  *(undefined4 *)(local_63e8 + 0x3a8) = 0;
  *(undefined4 *)(local_63e8 + 0xbc) = 0;
  *(undefined4 *)(local_63e8 + 0x460) = 0;
  *(undefined4 *)(local_63e8 + 0x468) = 0;
  *(undefined4 *)(local_63e8 + 0xd0) = 0;
  if (*(int *)(local_63e8 + 0xcc) != 0) {
    local_63ec = *(int **)(local_63e8 + 0xcc);
    if (local_63ec == (int *)0x0) {
      local_63f4 = 0;
    }
    else {
      local_63f4 = (**(code **)(*local_63ec + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0xcc) = 0;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiRenzokuSen[3] */
/* 006db2e0  FUN_006db2e0  300 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006db2e0(void)

{
  uint uVar1;
  int *in_ECX;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920cbb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(in_ECX[1]);
  local_8 = 0;
  local_63ec = FUN_0040c0e0(uVar1);
  FUN_00446aa0();
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6400,local_63e8[1]);
  FUN_0044de00(local_6400,local_63e8[1]);
  *(undefined4 *)(local_63e8[1] + 0x8560) = 0;
  (**(code **)(*local_63e8 + 0x20))();
  local_63e8[0x118] = 0;
  local_63e8[0x34] = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



