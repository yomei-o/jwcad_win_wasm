/* CZukeiSetuEn -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiSetuEn[1] */
/* 00706360  FUN_00706360  68 bytes, 0 callers */

undefined4 FUN_00706360(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00706200();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x468);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiSetuEn[6] */
/* 007063b0  FUN_007063b0  1640 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00706626) */

void FUN_007063b0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  undefined4 uVar4;
  undefined1 local_65d8 [20];
  ulonglong local_65c4;
  undefined4 local_65b4;
  undefined4 local_65b0;
  undefined4 local_65ac;
  undefined4 local_65a8;
  double local_65a4;
  undefined4 local_659c;
  int local_6598;
  undefined1 local_1c4 [16];
  undefined1 local_1b4 [16];
  undefined2 local_1a4 [200];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093faa6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb4) == 0) {
    local_6598 = in_ECX;
    FUN_00404c80(local_14);
    FUN_004fca20();
    fVar3 = (float10)FUN_004ab530();
    *(double *)(local_6598 + 0xc0) = (double)fVar3;
    FUN_00404c80();
    FUN_004fca20();
    fVar3 = (float10)FUN_004ac890();
    *(double *)(local_6598 + 0xd0) = (double)fVar3;
    if (*(double *)(local_6598 + 0xc0) <= 0.0) {
      local_65c4 = *(ulonglong *)(local_6598 + 0xc0) ^ 0x8000000000000000;
    }
    else {
      local_65c4 = *(ulonglong *)(local_6598 + 0xc0);
    }
    *(ulonglong *)(local_6598 + 0xc0) = local_65c4;
    local_65a4 = *(double *)(local_6598 + 0xc0) *
                 *(double *)
                  (*(int *)(local_6598 + 4) + 0x2578 +
                  *(int *)(*(int *)(local_6598 + 4) + 0x256c) * 8);
    if (*(double *)(local_6598 + 0xc0) <= 1e-07) {
      *(undefined4 *)(local_6598 + 0xac) = 0;
    }
    else {
      *(undefined4 *)(local_6598 + 0xac) = 1;
    }
    if (*(int *)(local_6598 + 0xac) != *(int *)(local_6598 + 0xb0)) {
      *(undefined4 *)(local_6598 + 0xb0) = *(undefined4 *)(local_6598 + 0xac);
      *(undefined8 *)(local_6598 + 200) = *(undefined8 *)(local_6598 + 0xc0);
      *(undefined8 *)(local_6598 + 0x3b8) =
           *(undefined8 *)
            (*(int *)(local_6598 + 4) + 0x2578 + *(int *)(*(int *)(local_6598 + 4) + 0x256c) * 8);
      *(undefined4 *)(local_6598 + 0xb8) = 0;
    }
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_6598 + 4));
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0044dd90(local_65d8,*(undefined4 *)(local_6598 + 4));
    local_659c = 0;
    local_1a4[0] = 0;
    if ((*(int *)(local_6598 + 0xb8) == 0) || (*(int *)(local_6598 + 0xb8) == 1)) {
      if (*(int *)(local_6598 + 0xac) != 0) {
        if (DAT_00a0d62c == 0) {
          FUN_00480580(local_1a4,L"    [ r = %.3lf ]",SUB84(local_65a4,0),
                       (int)((ulonglong)local_65a4 >> 0x20));
        }
        else {
          uVar1 = FUN_00404920();
          FUN_00480580(local_1a4,L"    [ r = %.3lf%s ]",local_65a4 / DAT_00a0d630,uVar1);
        }
      }
      FUN_004efbb0(0x14fc,local_1a4,0);
    }
    if (*(int *)(local_6598 + 0xb8) == 2) {
      if (*(int *)(local_6598 + 0xac) != 0) {
        if (DAT_00a0d62c == 0) {
          FUN_00480580(local_1a4,L"    [ r = %.3lf ]",SUB84(local_65a4,0),
                       (int)((ulonglong)local_65a4 >> 0x20));
        }
        else {
          uVar1 = FUN_00404920();
          FUN_00480580(local_1a4,L"    [ r = %.3lf%s ]",local_65a4 / DAT_00a0d630,uVar1);
        }
      }
      FUN_004efbb0(0x14fd,local_1a4,0);
    }
    if (*(int *)(local_6598 + 0xb8) == 3) {
      if (*(int *)(local_6598 + 0xac) != 0) {
        if ((*(double *)(local_6598 + 200) != *(double *)(local_6598 + 0xc0)) ||
           (*(double *)(local_6598 + 0x3b8) !=
            *(double *)
             (*(int *)(local_6598 + 4) + 0x2578 + *(int *)(*(int *)(local_6598 + 4) + 0x256c) * 8)))
        {
          *(undefined8 *)(local_6598 + 200) = *(undefined8 *)(local_6598 + 0xc0);
          *(undefined8 *)(local_6598 + 0x3b8) =
               *(undefined8 *)
                (*(int *)(local_6598 + 4) + 0x2578 + *(int *)(*(int *)(local_6598 + 4) + 0x256c) * 8
                );
          FUN_00707d60();
        }
        FUN_004988c0(local_1b4,*param_1,param_1[1],param_1[2],param_1[3]);
        local_65b0 = FUN_0070b570();
        local_65ac = FUN_005977f0(7000);
        local_8._0_1_ = 2;
        local_65a8 = local_65ac;
        uVar2 = FUN_00404920();
        uVar1 = *(undefined4 *)(local_6598 + 0x130);
        uVar4 = local_65b0;
        local_65b4 = FUN_005977f0(0x1b5e);
        uVar1 = FUN_00404920(uVar1,uVar4,uVar2);
        FUN_00480580(local_1a4,L"     %s %d - %d %s",uVar1);
        FUN_00404770();
        local_8._0_1_ = 1;
        FUN_00404770();
        FUN_004efbb0(0x14ff,local_1a4,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      *(undefined4 *)(local_6598 + 0x120) = 0;
      FUN_004988c0(local_1c4,*param_1,param_1[1],param_1[2],param_1[3]);
      FUN_004efbb0(0x14fe,0,0);
      FUN_00709940();
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0x18))(param_1);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuEn[16] */
/* 00706a20  FUN_00706a20  212 bytes, 0 callers */

undefined4 FUN_00706a20(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[0x2d] == 0) {
    if ((in_ECX[0x2e] == 0) || (in_ECX[0x2e] == 1)) {
      uVar2 = 0;
    }
    else if (in_ECX[0x2e] == 2) {
      in_ECX[0x2e] = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      uVar2 = 1;
    }
    else if (in_ECX[0x2e] == 3) {
      in_ECX[0x2e] = 2;
      FUN_00404c80();
      FUN_0056d7d0();
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    iVar1 = (**(code **)(*(int *)in_ECX[0x2d] + 0x40))();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      if (*(int *)(in_ECX[0x2d] + 0xb4) < 0) {
        (**(code **)(*in_ECX + 100))();
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}




/* vtable slots: CZukeiSetuEn[0] */
/* 00706b00  FUN_00706b00  16 bytes, 0 callers */

undefined ** FUN_00706b00(void)

{
  return &PTR_s_CZukeiSetuEn_0097a7c8;
}




/* vtable slots: CZukeiSetuEn[46] */
/* 00706b10  FUN_00706b10  252 bytes, 0 callers */

undefined4
FUN_00706b10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_10 = 0xffffffff;
      local_c = 0x13;
      if (*(int *)(in_ECX + 0xb4) != 0) {
        local_c = 0x26;
      }
      iVar2 = FUN_00778a40(1,&local_10,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,local_c);
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




/* vtable slots: CZukeiSetuEn[47] */
/* 00706c10  FUN_00706c10  252 bytes, 0 callers */

undefined4
FUN_00706c10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
      local_10 = 0xffffffff;
      local_c = 0x13;
      if (*(int *)(in_ECX + 0xb4) != 0) {
        local_c = 0x26;
      }
      iVar2 = FUN_00778a40(2,&local_10,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9074),param_1,
                           param_2,param_3,param_4,param_5,param_6,param_7,local_c);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiSetuEn[25] */
/* 00706d10  FUN_00706d10  320 bytes, 0 callers */

void FUN_00706d10(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) != 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      (**(code **)(**(int **)(iVar1 + 0x1a0) + 0x60))();
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined4 *)(iVar1 + 0x1a0) = 0;
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x17d8) = 0;
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == 0) {
      iVar1 = *(int *)(in_ECX + 4);
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      *(undefined4 *)(iVar2 + 0x1a0) = *(undefined4 *)(iVar1 + 0x85f0);
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      (**(code **)(**(int **)(iVar1 + 0x1a0) + 0x18c))();
      uVar3 = 5;
      FUN_00404c80(5);
      FUN_004fca20();
      FUN_00797f20(uVar3);
      uVar3 = 1;
      FUN_00404c80(1);
      FUN_004fca20();
      FUN_004aafb0(uVar3);
    }
    if (*(int **)(in_ECX + 0xb4) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0xb4) + 4))(1);
    }
    *(undefined4 *)(in_ECX + 0xb4) = 0;
  }
  return;
}




/* vtable slots: CZukeiSetuEn[26] */
/* 00706e50  FUN_00706e50  186 bytes, 0 callers */

void FUN_00706e50(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093279f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  FUN_004fca20();
  fVar2 = (float10)FUN_004ac890();
  *(double *)(in_ECX + 0xd0) = (double)fVar2;
  iVar1 = FUN_004121b0();
  local_8 = 0;
  if (iVar1 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = FUN_00641460(*(undefined4 *)(in_ECX + 4),1,*(undefined8 *)(in_ECX + 0xd0));
  }
  *(undefined4 *)(in_ECX + 0xb4) = local_1c;
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuEn[27] */
/* 00706f10  FUN_00706f10  48 bytes, 0 callers */

void FUN_00706f10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0x6c))();
  }
  return;
}




/* vtable slots: CZukeiSetuEn[28] */
/* 00706f40  FUN_00706f40  48 bytes, 0 callers */

void FUN_00706f40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0x70))();
  }
  return;
}




/* vtable slots: CZukeiSetuEn[29] */
/* 00706f70  FUN_00706f70  48 bytes, 0 callers */

void FUN_00706f70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0x74))();
  }
  return;
}




/* vtable slots: CZukeiSetuEn[30] */
/* 00706fa0  FUN_00706fa0  48 bytes, 0 callers */

void FUN_00706fa0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0x78))();
  }
  return;
}




/* vtable slots: CZukeiSetuEn[31] */
/* 00706fd0  FUN_00706fd0  48 bytes, 0 callers */

void FUN_00706fd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0x7c))();
  }
  return;
}




/* vtable slots: CZukeiSetuEn[32] */
/* 00707000  FUN_00707000  51 bytes, 0 callers */

void FUN_00707000(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0x80))();
  }
  return;
}




/* vtable slots: CZukeiSetuEn[50] */
/* 00707040  FUN_00707040  91 bytes, 0 callers */

void FUN_00707040(double param_1)

{
  if (1e-07 <= param_1) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_004ac6e0(param_1);
    FUN_00404c80();
    FUN_004fca20();
    FUN_007955d2();
  }
  return;
}




/* vtable slots: CZukeiSetuEn[51] */
/* 007070a0  FUN_007070a0  138 bytes, 0 callers */

void FUN_007070a0(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80(param_3,DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  FUN_004fca20();
  FUN_004ac6e0(param_3);
  FUN_00404c80();
  FUN_004fca20();
  FUN_007955d2();
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSetuEn[9] */
/* 00707130  FUN_00707130  1955 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00707130(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  double local_647c;
  int *local_642c;
  int local_6428;
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093fae0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb4) == 0) {
    if (param_1 == 0x231d) {
      uVar1 = FUN_00707a50(param_2,param_3,param_4,param_5);
    }
    else {
      local_6428 = in_ECX;
      if ((*(int *)(in_ECX + 0xb8) == 3) && (*(int *)(in_ECX + 0xac) != 0)) {
        FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
        *(undefined4 *)(local_6428 + 0xb8) = 7;
        uVar1 = 1;
      }
      else {
        FUN_00446aa0(local_14);
        local_8 = 0;
        local_100 = 1;
        local_fc = 1;
        iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6428 + 4),&param_2,&local_642c,0);
        if (iVar2 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          iVar2 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
          if (iVar2 != 0) {
            fVar3 = (float10)FUN_0040c180();
            local_647c = (double)fVar3;
            if (local_647c - 1.0 <= 0.0) {
              local_647c = -(local_647c - 1.0);
            }
            else {
              local_647c = local_647c - 1.0;
            }
            if (1e-07 <= local_647c) {
              FUN_005168b0(0x145e,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 0;
            }
          }
          if ((*(int *)(local_6428 + 0xb8) == 0) || (*(int *)(local_6428 + 0xb8) == 1)) {
            if (*(int *)(local_6428 + 0x124) != 0) {
              if (*(int **)(local_6428 + 0x124) != (int *)0x0) {
                (**(code **)(**(int **)(local_6428 + 0x124) + 4))(1);
              }
              *(undefined4 *)(local_6428 + 0x124) = 0;
            }
            if (local_642c != (int *)0x0) {
              uVar1 = (**(code **)(*local_642c + 0x14))();
              *(undefined4 *)(local_6428 + 0x124) = uVar1;
            }
            *(undefined4 *)(local_6428 + 0x118) = *(undefined4 *)(local_6428 + 0x124);
            FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
            *(undefined4 *)(local_6428 + 0xb8) = 2;
            FUN_00404c80();
            FUN_0056d7d0();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
          else if (*(int *)(local_6428 + 0xb8) == 2) {
            if (local_642c == *(int **)(local_6428 + 0x118)) {
              FUN_005168b0(0x14e7,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
            else {
              if (*(int *)(local_6428 + 0x128) != 0) {
                if (*(int **)(local_6428 + 0x128) != (int *)0x0) {
                  (**(code **)(**(int **)(local_6428 + 0x128) + 4))(1);
                }
                *(undefined4 *)(local_6428 + 0x128) = 0;
              }
              if (local_642c != (int *)0x0) {
                uVar1 = (**(code **)(*local_642c + 0x14))();
                *(undefined4 *)(local_6428 + 0x128) = uVar1;
              }
              *(undefined4 *)(local_6428 + 0x11c) = *(undefined4 *)(local_6428 + 0x128);
              FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
              if ((*(int *)(local_6428 + 0xac) == 0) ||
                 (FUN_00707d60(), 0 < *(int *)(local_6428 + 0x130))) {
                *(undefined4 *)(local_6428 + 0xb8) = 3;
                FUN_00404c80();
                FUN_0056d7d0();
                local_8 = 0xffffffff;
                FUN_00447100();
                uVar1 = 0;
              }
              else {
                FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                             *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
                local_8 = 0xffffffff;
                FUN_00447100();
                uVar1 = 0;
              }
            }
          }
          else if (*(int *)(local_6428 + 0xb8) == 3) {
            if ((local_642c == *(int **)(local_6428 + 0x118)) ||
               (local_642c == *(int **)(local_6428 + 0x11c))) {
              FUN_005168b0(0x14e7,*(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f28),0,0);
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 0;
            }
            else {
              if (*(int *)(local_6428 + 300) != 0) {
                if (*(int **)(local_6428 + 300) != (int *)0x0) {
                  (**(code **)(**(int **)(local_6428 + 300) + 4))(1);
                }
                *(undefined4 *)(local_6428 + 300) = 0;
              }
              if (local_642c != (int *)0x0) {
                uVar1 = (**(code **)(*local_642c + 0x14))();
                *(undefined4 *)(local_6428 + 300) = uVar1;
              }
              *(undefined4 *)(local_6428 + 0x120) = *(undefined4 *)(local_6428 + 300);
              FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
              *(undefined4 *)(local_6428 + 0xb8) = 7;
              local_8 = 0xffffffff;
              FUN_00447100();
              uVar1 = 1;
            }
          }
          else {
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
        }
      }
    }
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xb4) + 0x24))(param_1,param_2,param_3,param_4,param_5)
    ;
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiSetuEn[11] */
/* 007078e0  FUN_007078e0  360 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007078e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938a20;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb4) == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    FUN_00446aa0(local_14);
    local_8 = 0;
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    local_18 = param_5;
    iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
    if (iVar2 == 0) {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_00707a50(local_24,local_20,local_1c,local_18);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xb4) + 0x2c))(param_1,param_2,param_3,param_4,param_5)
    ;
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiSetuEn[4] */
/* 007097b0  FUN_007097b0  48 bytes, 0 callers */

void FUN_007097b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0x10))();
  }
  return;
}




/* vtable slots: CZukeiSetuEn[3] */
/* 007097e0  FUN_007097e0  339 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007097e0(void)

{
  int in_ECX;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920cbb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb4) == 0) {
    local_63e8 = in_ECX;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    local_63ec = FUN_0040c0e0();
    FUN_00446aa0();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    if (*(int *)(local_63e8 + 0xac) == 0) {
      FUN_00709940();
    }
    else {
      FUN_0070b570();
    }
    *(undefined4 *)(local_63e8 + 0xb8) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = local_8 & 0xffffff00;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xb4) + 0xc))(local_14);
  }
  ExceptionList = local_10;
  return;
}



