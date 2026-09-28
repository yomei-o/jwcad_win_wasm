/* CZukeiShinshuku -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiShinshuku[1] */
/* 00715d60  FUN_00715d60  68 bytes, 0 callers */

undefined4 FUN_00715d60(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00715bd0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa068);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiShinshuku[6] */
/* 00715f50  FUN_00715f50  1403 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00715f50(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  int local_63f0;
  int local_63ec;
  int local_63e8;
  undefined1 local_63e4 [25552];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940006;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8ebc) = 0;
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    if (*(int *)(*(int *)(in_ECX + 0x1f8) + 0x1c) == 0) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_004c9cb0();
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      FUN_004c9cb0();
    }
    FUN_00562600();
    ExceptionList = local_10;
    return;
  }
  local_63e8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_00464040();
  local_8._0_1_ = 1;
  FUN_0079dea2();
  local_8._0_1_ = 2;
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_004cad70();
  *(double *)(local_63e8 + 0xa060) = (double)fVar2;
  if ((*(int *)(local_63e8 + 0x208) != 0) && (*(int *)(local_63e8 + 0x20c) == 10)) {
    FUN_004efbb0(0x158d,0,0);
    FUN_00478c70(*(undefined4 *)(local_63e8 + 4),local_63e4,local_6408,
                 *(undefined4 *)(local_63e8 + 0x208),*param_1,param_1[1],param_1[2],param_1[3],0,
                 *(undefined8 *)(local_63e8 + 0xa060));
    FUN_00717df0();
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    local_8._0_1_ = 1;
    FUN_0079dfff();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004640a0();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(local_63e8 + 0x210) == 6) {
    iVar1 = *(int *)(*(int *)(local_63e8 + 4) + 0x8f58);
    if (*(int *)(local_63e8 + 0x270) == iVar1 || *(int *)(local_63e8 + 0x270) - iVar1 < 0) {
      local_63ec = -(*(int *)(local_63e8 + 0x270) - *(int *)(*(int *)(local_63e8 + 4) + 0x8f58));
    }
    else {
      local_63ec = *(int *)(local_63e8 + 0x270) - *(int *)(*(int *)(local_63e8 + 4) + 0x8f58);
    }
    iVar1 = *(int *)(*(int *)(local_63e8 + 4) + 0x8f5c);
    if (*(int *)(local_63e8 + 0x274) == iVar1 || *(int *)(local_63e8 + 0x274) - iVar1 < 0) {
      local_63f0 = -(*(int *)(local_63e8 + 0x274) - *(int *)(*(int *)(local_63e8 + 4) + 0x8f5c));
    }
    else {
      local_63f0 = *(int *)(local_63e8 + 0x274) - *(int *)(*(int *)(local_63e8 + 4) + 0x8f5c);
    }
    if (2 < local_63ec + local_63f0) {
      FUN_00717cc0();
      *(undefined4 *)(local_63e8 + 0x210) = 0;
      local_63f4 = 0;
      iVar1 = FUN_0044a270(3,*(undefined4 *)(local_63e8 + 4),local_63e8 + 0x220,&local_63f4,0);
      if (iVar1 == 0) {
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_004640a0();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      *(undefined4 *)(local_63e8 + 0x200) = local_63f4;
      FUN_00404c80();
      FUN_004fca20();
      FUN_004cacd0();
      FUN_00470200(*(undefined4 *)(local_63e8 + 4),*(undefined4 *)(local_63e8 + 0x200),
                   *(undefined4 *)(local_63e8 + 0x220),*(undefined4 *)(local_63e8 + 0x224),
                   *(undefined4 *)(local_63e8 + 0x228),*(undefined4 *)(local_63e8 + 0x22c),
                   *(undefined4 *)(local_63e8 + 0x220),*(undefined4 *)(local_63e8 + 0x224),
                   *(undefined4 *)(local_63e8 + 0x228),*(undefined4 *)(local_63e8 + 0x22c));
      FUN_00717650();
      FUN_004508b0(0x10,local_6408,*(undefined4 *)(local_63e8 + 4),
                   *(undefined4 *)(local_63e8 + 0x220),*(undefined4 *)(local_63e8 + 0x224),
                   *(undefined4 *)(local_63e8 + 0x228),*(undefined4 *)(local_63e8 + 0x22c),0);
      FUN_00719c30(5,*(undefined4 *)(local_63e8 + 0x220),*(undefined4 *)(local_63e8 + 0x224),
                   *(undefined4 *)(local_63e8 + 0x228),*(undefined4 *)(local_63e8 + 0x22c));
      *(undefined4 *)(local_63e8 + 0xa058) = 0;
      goto LAB_00716462;
    }
  }
  if (0 < *(int *)(local_63e8 + 0xa058)) {
    *(int *)(local_63e8 + 0xa058) = *(int *)(local_63e8 + 0xa058) + -1;
    local_8._0_1_ = 1;
    FUN_0079dfff();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004640a0();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
LAB_00716462:
  FUN_00717df0();
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
  local_8._0_1_ = 1;
  FUN_0079dfff();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004640a0();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShinshuku[16] */
/* 007164d0  FUN_007164d0  1577 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007164d0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_6418 [20];
  undefined4 local_6404;
  undefined4 local_6400;
  undefined4 local_63fc;
  undefined4 local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094004b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    local_63f0 = FUN_0040c0e0(local_14);
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    if ((*(int *)(local_63e8 + 0x208) == 0) || (*(int *)(local_63e8 + 0x20c) != 10)) {
      iVar2 = FUN_004146c0();
      if (iVar2 == 0) {
        if (*(int *)(local_63e8 + 0x20c) == 1) {
          FUN_00717cc0();
          *(undefined4 *)(local_63e8 + 0x20c) = 0;
          FUN_00717650();
          uVar5 = 0;
          uVar3 = 1;
          uVar4 = 1;
          FUN_00404c80(1,1,0);
          FUN_004fca20();
          FUN_004cab90(uVar4,uVar3,uVar5);
          FUN_00717df0();
          *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
          local_63f8 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          local_63ec = local_63f8;
        }
        else {
          while (0 < *(int *)(local_63e8 + 0x278)) {
            if (*(int *)(local_63e8 + 0x27c + *(int *)(local_63e8 + 0x278) * 4) != 3) {
              FUN_00717cc0();
              if (*(int *)(local_63e8 + 0x27c + *(int *)(local_63e8 + 0x278) * 4) == 5) {
                FUN_004546a0(local_6418,*(undefined4 *)(local_63e8 + 4));
                puVar1 = (undefined4 *)(local_63e8 + 0x1248 + *(int *)(local_63e8 + 0x278) * 0x10);
                FUN_00719d70(5,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
              }
              else {
                FUN_00719d70(0,*(undefined4 *)(local_63e8 + 0x250),
                             *(undefined4 *)(local_63e8 + 0x254),*(undefined4 *)(local_63e8 + 600),
                             *(undefined4 *)(local_63e8 + 0x25c));
              }
              FUN_00458a80(local_6418,*(undefined4 *)(local_63e8 + 4),0);
              FUN_00717650();
              if (0 < *(int *)(local_63e8 + 0x278)) {
                *(int *)(local_63e8 + 0x278) = *(int *)(local_63e8 + 0x278) + -1;
              }
              FUN_00717df0();
              *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
              local_6404 = 1;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              ExceptionList = local_10;
              return local_6404;
            }
            if ((*(int *)(local_63e8 + 0x20c) == 3) || (*(int *)(local_63e8 + 0x20c) == 4)) {
              FUN_00717cc0();
              *(undefined4 *)(local_63e8 + 0x20c) = 0;
              FUN_00717650();
              puVar1 = (undefined4 *)(local_63e8 + 0x1248 + *(int *)(local_63e8 + 0x278) * 0x10);
              FUN_00719d70(3,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
              if (0 < *(int *)(local_63e8 + 0x278)) {
                *(int *)(local_63e8 + 0x278) = *(int *)(local_63e8 + 0x278) + -1;
              }
              uVar5 = 0;
              uVar3 = 1;
              uVar4 = 1;
              FUN_00404c80(1,1,0);
              FUN_004fca20();
              FUN_004cab90(uVar4,uVar3,uVar5);
              FUN_00717df0();
              *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
              local_6400 = 1;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_00447100();
              local_8 = 0xffffffff;
              FUN_0079dfff();
              ExceptionList = local_10;
              return local_6400;
            }
            if (0 < *(int *)(local_63e8 + 0x278)) {
              *(int *)(local_63e8 + 0x278) = *(int *)(local_63e8 + 0x278) + -1;
            }
          }
          FUN_00719d70(0,*(undefined4 *)(local_63e8 + 0x250),*(undefined4 *)(local_63e8 + 0x254),
                       *(undefined4 *)(local_63e8 + 600),*(undefined4 *)(local_63e8 + 0x25c));
          FUN_00717df0();
          *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
          local_63fc = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          local_63ec = local_63fc;
        }
      }
      else {
        *(undefined4 *)(local_63e8 + 0x278) = 0;
        FUN_00717df0();
        *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
        local_63f4 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        local_63ec = local_63f4;
      }
    }
    else {
      FUN_0044dd90(local_6418,*(undefined4 *)(local_63e8 + 4));
      *(undefined4 *)(local_63e8 + 0x208) = 0;
      *(undefined4 *)(local_63e8 + 0x20c) = 0;
      FUN_00717df0();
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
      local_63ec = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
  }
  else {
    iVar2 = FUN_00562880();
    if (iVar2 != 0) {
      uVar4 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_004c9cb0(uVar4);
      *(undefined4 *)(local_63e8 + 0x1fc) = 0;
    }
    local_63ec = 1;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiShinshuku[63] */
/* 00716b00  FUN_00716b00  15 bytes, 0 callers */

undefined4 FUN_00716b00(void)

{
  return 0;
}




/* vtable slots: CZukeiShinshuku[0] */
/* 00716b10  FUN_00716b10  16 bytes, 0 callers */

undefined ** FUN_00716b10(void)

{
  return &PTR_s_CZukeiShinshuku_0097aa88;
}




/* vtable slots: CZukeiShinshuku[23] */
/* 00717eb0  FUN_00717eb0  231 bytes, 0 callers */

undefined4 FUN_00717eb0(void)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if (((in_ECX[0x83] == 10) || (in_ECX[0x83] != 0)) || (in_ECX[0x7f] != 0)) {
    FUN_005168b0(0x273c,*(undefined4 *)(in_ECX[1] + 0x8f24),*(undefined4 *)(in_ECX[1] + 0x8f28),0,0)
    ;
    uVar1 = 0;
  }
  else {
    if (DAT_00a0cc6c == 0) {
      (**(code **)(*in_ECX + 100))();
    }
    else {
      *(undefined4 *)(in_ECX[1] + 0x908c) = 0xffffffff;
      *(undefined4 *)(in_ECX[1] + 37000) = 0xe;
      *(undefined4 *)(in_ECX[1] + 0x907c) = 1;
      FUN_005168b0(0x158c,*(undefined4 *)(in_ECX[1] + 0x8f24),*(undefined4 *)(in_ECX[1] + 0x8f28),0,
                   0);
      FUN_005170e0();
    }
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CZukeiShinshuku[46] */
/* 00717fa0  FUN_00717fa0  1048 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00717fa0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_63f0;
  int local_63ec;
  int *local_63e8;
  undefined4 local_b8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939aa0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0c7c0 == 0) {
    FUN_00446aa0(local_14);
    local_8 = 0;
    local_63f0 = 0;
    if (*(int *)(local_63e8[1] + 0x8588) == 0) {
      if (*(int *)(local_63e8[1] + 0x9078) == 0) {
        if (((local_63e8[0x7f] != 0) && (param_2 == 0xc)) &&
           (*(int *)(local_63e8[0x7e] + 0x1c) != 0)) {
          if (param_3 == 1) {
            FUN_005168b0(0x18b1,*(undefined4 *)(local_63e8[1] + 0x8f50),
                         *(undefined4 *)(local_63e8[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            (**(code **)(*local_63e8 + 0x68))();
          }
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        if (param_2 == 8) {
          if (param_3 == 1) {
            FUN_005168b0(0x158c,*(undefined4 *)(local_63e8[1] + 0x8f50),
                         *(undefined4 *)(local_63e8[1] + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            local_b8 = 1;
            iVar1 = FUN_0044a270(3,local_63e8[1],&param_4,&local_63ec,0);
            if (iVar1 == 0) {
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 0;
            }
            iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
            if ((iVar1 == 0) && (iVar1 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078), iVar1 == 0)) {
              FUN_005168b0(0x14de,*(undefined4 *)(local_63e8[1] + 0x8f24),
                           *(undefined4 *)(local_63e8[1] + 0x8f28),0,0);
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return 0;
            }
            FUN_00717cc0();
            local_63e8[0x82] = local_63ec;
            FUN_00455870(local_63e8[0x82],param_4,param_5,param_6,param_7);
            uVar4 = 0;
            uVar3 = 1;
            uVar2 = 1;
            FUN_00404c80(1,1,0);
            FUN_004fca20();
            FUN_004cab90(uVar2,uVar3,uVar4);
            local_63e8[0x83] = 10;
          }
        }
        else {
          local_63f0 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        }
      }
      else {
        local_63f0 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_63f0 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    local_63f0 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return local_63f0;
}




/* vtable slots: CZukeiShinshuku[25] */
/* 007183c0  FUN_007183c0  366 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007183c0(void)

{
  int in_ECX;
  undefined4 uVar1;
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
  *(undefined4 *)(in_ECX + 0x1fc) = 1;
  local_63e8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044de00(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd20(local_63fc,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c990(*(undefined4 *)(local_63e8 + 4),local_63fc);
  FUN_00449d60(local_63fc,*(undefined4 *)(local_63e8 + 4),1);
  uVar1 = 0xb;
  FUN_00404c80(0xb);
  FUN_004fca20();
  FUN_004c9cb0(uVar1);
  FUN_005634f0();
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShinshuku[26] */
/* 00718530  FUN_00718530  158 bytes, 0 callers */

void FUN_00718530(void)

{
  int in_ECX;
  undefined4 uVar1;
  
  uVar1 = 0;
  FUN_00404c80(0);
  FUN_004fca20();
  FUN_004c9cb0(uVar1);
  if ((*(int *)(in_ECX + 0x1fc) != 0) &&
     (FUN_00716b20(), *(int *)(*(int *)(in_ECX + 4) + 0x8588) != 0)) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8588) = 0xffffd9bb;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x906c) = 0;
    FUN_00404c80();
    FUN_0056d200();
    return;
  }
  *(undefined4 *)(in_ECX + 0x1fc) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
  FUN_00404c80();
  FUN_0056d200();
  return;
}




/* vtable slots: CZukeiShinshuku[50] */
/* 007185d0  FUN_007185d0  66 bytes, 0 callers */

void FUN_007185d0(double param_1)

{
  if (1e-07 <= param_1) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_004ca970(param_1);
  }
  return;
}




/* vtable slots: CZukeiShinshuku[15] */
/* 00718620  FUN_00718620  1094 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00718620(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_6428 [20];
  undefined4 local_6414;
  undefined4 local_6410;
  undefined4 local_640c;
  int local_6408;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009379cb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    local_6408 = in_ECX;
    local_640c = FUN_0040c0e0(local_14);
    iVar2 = FUN_004146c0();
    if (iVar2 == 0) {
      if (*(int *)(local_6408 + 0x5168) < 1) {
        FUN_00719c30(0,*(undefined4 *)(local_6408 + 0x250),*(undefined4 *)(local_6408 + 0x254),
                     *(undefined4 *)(local_6408 + 600),*(undefined4 *)(local_6408 + 0x25c));
        FUN_00717df0();
        *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
        local_6410 = 0;
      }
      else {
        FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
        local_8 = 0;
        FUN_00446aa0();
        local_8._0_1_ = 1;
        if (*(int *)(local_6408 + 0x516c + *(int *)(local_6408 + 0x5168) * 4) == 3) {
          FUN_00717cc0();
          puVar1 = (undefined4 *)(local_6408 + 0x6138 + *(int *)(local_6408 + 0x5168) * 0x10);
          FUN_004988c0(local_34,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
          *(undefined4 *)(local_6408 + 0x20c) = 3;
          FUN_00717650();
          puVar1 = (undefined4 *)(local_6408 + 0x6138 + *(int *)(local_6408 + 0x5168) * 0x10);
          FUN_00719c30(3,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
          if (0 < *(int *)(local_6408 + 0x5168)) {
            *(int *)(local_6408 + 0x5168) = *(int *)(local_6408 + 0x5168) + -1;
          }
          FUN_00717df0();
          *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
          local_6410 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
        else {
          FUN_00717cc0();
          if (*(int *)(local_6408 + 0x516c + *(int *)(local_6408 + 0x5168) * 4) == 5) {
            puVar1 = (undefined4 *)(local_6408 + 0x6138 + *(int *)(local_6408 + 0x5168) * 0x10);
            local_24 = *puVar1;
            local_20 = puVar1[1];
            local_1c = puVar1[2];
            local_18 = puVar1[3];
            FUN_004509b0(0xf,local_6428,*(undefined4 *)(local_6408 + 4),local_24,local_20,local_1c,
                         local_18);
            FUN_00719c30(5,local_24,local_20,local_1c,local_18);
          }
          else {
            FUN_00719c30(0,*(undefined4 *)(local_6408 + 0x250),*(undefined4 *)(local_6408 + 0x254),
                         *(undefined4 *)(local_6408 + 600),*(undefined4 *)(local_6408 + 0x25c));
          }
          FUN_00453bd0(local_6428,*(undefined4 *)(local_6408 + 4),0);
          FUN_00717650();
          if (0 < *(int *)(local_6408 + 0x5168)) {
            *(int *)(local_6408 + 0x5168) = *(int *)(local_6408 + 0x5168) + -1;
          }
          FUN_00717df0();
          *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
          local_6414 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          local_6410 = local_6414;
        }
      }
    }
    else {
      *(undefined4 *)(local_6408 + 0x5168) = 0;
      FUN_00717df0();
      *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
      local_6410 = 1;
    }
  }
  else {
    local_6410 = 1;
  }
  ExceptionList = local_10;
  return local_6410;
}




/* vtable slots: CZukeiShinshuku[12] */
/* 00718a70  FUN_00718a70  75 bytes, 0 callers */

undefined4
FUN_00718a70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_005635b0(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiShinshuku[10] */
/* 00718ac0  FUN_00718ac0  916 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00718ac0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c17b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8._0_1_ = 1;
  iVar1 = *(int *)(in_ECX + 4);
  local_24 = *(undefined4 *)(iVar1 + 0x8f68);
  local_20 = *(undefined4 *)(iVar1 + 0x8f6c);
  local_1c = *(undefined4 *)(iVar1 + 0x8f70);
  local_18 = *(undefined4 *)(iVar1 + 0x8f74);
  if ((*(int *)(*(int *)(in_ECX + 4) + 0x9068) == 0) &&
     (*(int *)(*(int *)(in_ECX + 4) + 0x906c) == 0)) {
    FUN_00717df0();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else if (*(int *)(in_ECX + 0x20c) == 0) {
    FUN_00717cc0();
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9068) != 0) {
      iVar1 = *(int *)(in_ECX + 4);
      FUN_004988c0(local_34,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
                   *(undefined4 *)(iVar1 + 0x8f70),*(undefined4 *)(iVar1 + 0x8f74));
      *(undefined4 *)(in_ECX + 0x20c) = 1;
      iVar1 = FUN_00717650();
      if (iVar1 == 0) {
        FUN_00717df0();
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b0) = 0;
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b4) = 0;
    }
    if (*(int *)(*(int *)(in_ECX + 4) + 0x906c) != 0) {
      *(undefined4 *)(in_ECX + 0x20c) = 3;
      iVar1 = *(int *)(in_ECX + 4);
      FUN_004988c0(local_44,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
                   *(undefined4 *)(iVar1 + 0x8f70),*(undefined4 *)(iVar1 + 0x8f74));
      iVar1 = FUN_00717650();
      if (iVar1 == 0) {
        FUN_00717df0();
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      FUN_00719c30(3,*(undefined4 *)(in_ECX + 0x260),*(undefined4 *)(in_ECX + 0x264),
                   *(undefined4 *)(in_ECX + 0x268),*(undefined4 *)(in_ECX + 0x26c));
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b0) = 0;
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b4) = 0;
    }
    FUN_00717df0();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_00717df0();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShinshuku[9] */
/* 00718e60  FUN_00718e60  1490 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00718e60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094014b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8._0_1_ = 1;
    if ((*(int *)(in_ECX + 0x208) == 0) || (*(int *)(in_ECX + 0x20c) != 10)) {
      if (*(int *)(in_ECX + 0x210) == 6) {
        FUN_00717df0();
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else if (*(int *)(in_ECX + 0x20c) == 0) {
        FUN_00717cc0();
        FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
        *(undefined4 *)(in_ECX + 0x20c) = 1;
        iVar2 = FUN_00717650();
        if (iVar2 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          if (*(int *)(in_ECX + 0x208) != 0) {
            iVar2 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
            if (iVar2 == 0) {
              uVar4 = 0;
              uVar3 = 0;
              uVar1 = 1;
              FUN_00404c80(1,0,0);
              FUN_004fca20();
              FUN_004cab90(uVar1,uVar3,uVar4);
            }
            else {
              uVar4 = 0;
              uVar3 = 1;
              uVar1 = 1;
              FUN_00404c80(1,1,0);
              FUN_004fca20();
              FUN_004cab90(uVar1,uVar3,uVar4);
            }
          }
          FUN_00717df0();
          *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
      }
      else if (*(int *)(in_ECX + 0x20c) == 1) {
        FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
        *(undefined4 *)(in_ECX + 0x20c) = 2;
        FUN_00717df0();
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 1;
      }
      else if ((*(int *)(in_ECX + 0x20c) == 3) || (*(int *)(in_ECX + 0x20c) == 4)) {
        iVar2 = FUN_0044a270(3,*(undefined4 *)(in_ECX + 4),&param_2,in_ECX + 0x208,0);
        if (iVar2 == 0) {
          FUN_00717df0();
          *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          iVar2 = FUN_0071ab70(*(undefined4 *)(in_ECX + 0x208));
          if (iVar2 == 0) {
            FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
            *(undefined4 *)(in_ECX + 0x20c) = 4;
            FUN_00717df0();
            *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 1;
          }
          else {
            *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            uVar1 = 0;
          }
        }
      }
      else {
        FUN_00717df0();
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
    else {
      FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      FUN_00717df0();
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 1;
    }
  }
  else {
    FUN_005637b0(param_1,param_2,param_3,param_4,param_5);
    uVar1 = 0;
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiShinshuku[13] */
/* 00719440  FUN_00719440  317 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00719440(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x210) == 6) {
    FUN_00717cc0();
    *(undefined4 *)(in_ECX + 0x20c) = 3;
    *(undefined4 *)(in_ECX + 0x210) = 0;
    FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 0x220),*(undefined4 *)(in_ECX + 0x224),
                 *(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c));
    FUN_00717650();
    FUN_00719c30(3,*(undefined4 *)(in_ECX + 0x260),*(undefined4 *)(in_ECX + 0x264),
                 *(undefined4 *)(in_ECX + 0x268),*(undefined4 *)(in_ECX + 0x26c));
    if (*(int *)(in_ECX + 0x204) != 0) {
      iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar1 == 0) {
        uVar4 = 1;
        uVar3 = 0;
        uVar2 = 1;
        FUN_00404c80(1,0,1);
        FUN_004fca20();
        FUN_004cab90(uVar2,uVar3,uVar4);
      }
      else {
        uVar4 = 0;
        uVar3 = 1;
        uVar2 = 1;
        FUN_00404c80(1,1,0);
        FUN_004fca20();
        FUN_004cab90(uVar2,uVar3,uVar4);
      }
    }
    FUN_00717df0();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  }
  return 0;
}




/* vtable slots: CZukeiShinshuku[11] */
/* 00719580  FUN_00719580  1702 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00719580(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 uVar4;
  int *local_642c;
  int local_6428;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined1 local_54 [16];
  undefined1 local_44 [32];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094019b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6428 = in_ECX;
  local_14 = uVar1;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    if ((*(int *)(local_6428 + 0x208) == 0) || (*(int *)(local_6428 + 0x20c) != 10)) {
      if (*(int *)(local_6428 + 0x20c) == 1) {
        iVar2 = FUN_00451eb0(*(undefined4 *)(local_6428 + 4),&param_2,1);
        if (iVar2 == 0) {
          FUN_00717df0();
          *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar4 = 0;
        }
        else {
          FUN_00717df0();
          *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
          uVar4 = FUN_00718e60(param_1,param_2,param_3,param_4,param_5);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
        }
      }
      else if ((*(int *)(local_6428 + 0x20c) == 1) || (*(int *)(local_6428 + 0x210) == 6)) {
        if (*(int *)(local_6428 + 0x210) == 6) {
          FUN_00717cc0();
          *(undefined4 *)(local_6428 + 0x20c) = 3;
          *(undefined4 *)(local_6428 + 0x210) = 0;
          FUN_004988c0(local_54,*(undefined4 *)(local_6428 + 0x220),
                       *(undefined4 *)(local_6428 + 0x224),*(undefined4 *)(local_6428 + 0x228),
                       *(undefined4 *)(local_6428 + 0x22c));
          FUN_00717650();
          FUN_00719c30(3,*(undefined4 *)(local_6428 + 0x260),*(undefined4 *)(local_6428 + 0x264),
                       *(undefined4 *)(local_6428 + 0x268),*(undefined4 *)(local_6428 + 0x26c));
          FUN_00717df0();
          *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar4 = 0;
        }
        else {
          FUN_00717df0();
          *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00447100();
          local_8 = 0xffffffff;
          FUN_0079dfff();
          uVar4 = 0;
        }
      }
      else {
        local_100 = 1;
        local_fc = 1;
        local_f8 = 1;
        local_642c = (int *)0x0;
        iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6428 + 4),&param_2,&local_642c,1);
        if (iVar2 != 0) {
          iVar2 = FUN_0079d98a(&PTR_s_CDataSunpou_009fe078);
          if (iVar2 != 0) {
            local_642c = local_642c + 0x1a;
            FUN_0040db00(param_2,param_3,param_4,param_5);
          }
          if (*(int *)(local_6428 + 0x214) != 0) {
            if (*(int **)(local_6428 + 0x214) != (int *)0x0) {
              (**(code **)(**(int **)(local_6428 + 0x214) + 4))(1);
            }
            *(undefined4 *)(local_6428 + 0x214) = 0;
          }
          if (local_642c != (int *)0x0) {
            uVar4 = (**(code **)(*local_642c + 0x14))();
            *(undefined4 *)(local_6428 + 0x214) = uVar4;
          }
          *(undefined4 *)(local_6428 + 0x200) = *(undefined4 *)(local_6428 + 0x214);
          *(undefined4 *)(local_6428 + 0x210) = 6;
          puVar3 = (undefined4 *)
                   CMFCCaptionButtonEx::GetRect(*(CMFCCaptionButtonEx **)(local_6428 + 0x200));
          FUN_004988c0(local_44,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
          uVar4 = *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f5c);
          *(undefined4 *)(local_6428 + 0x270) = *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8f58);
          *(undefined4 *)(local_6428 + 0x274) = uVar4;
        }
        FUN_00717df0();
        *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar4 = 0;
      }
    }
    else {
      iVar2 = FUN_00451eb0(*(undefined4 *)(local_6428 + 4),&param_2,1);
      if (iVar2 == 0) {
        FUN_00717df0();
        *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar4 = 0;
      }
      else {
        FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
        FUN_00717df0();
        *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        uVar4 = 1;
      }
    }
  }
  else {
    iVar2 = FUN_00564350(param_1,param_2,param_3,param_4,param_5);
    if (iVar2 != 0) {
      uVar4 = 0;
      FUN_00404c80(0,uVar1);
      FUN_004fca20();
      FUN_004c9cb0(uVar4);
      FUN_00716b20();
      *(undefined4 *)(local_6428 + 0x1fc) = 0;
    }
    uVar4 = 0;
  }
  ExceptionList = local_10;
  return uVar4;
}




/* vtable slots: CZukeiShinshuku[4] */
/* 00719eb0  FUN_00719eb0  401 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00719eb0(void)

{
  undefined1 local_640c [20];
  undefined4 local_63f8;
  undefined4 local_63f4;
  int *local_63f0;
  int *local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092999b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044c830(local_640c,*(undefined4 *)(local_63e8 + 4));
  if (*(int *)(local_63e8 + 0x214) != 0) {
    local_63ec = *(int **)(local_63e8 + 0x214);
    if (local_63ec == (int *)0x0) {
      local_63f4 = 0;
    }
    else {
      local_63f4 = (**(code **)(*local_63ec + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0x214) = 0;
  }
  if (*(int *)(local_63e8 + 0x218) != 0) {
    local_63f0 = *(int **)(local_63e8 + 0x218);
    if (local_63f0 == (int *)0x0) {
      local_63f8 = 0;
    }
    else {
      local_63f8 = (**(code **)(*local_63f0 + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0x218) = 0;
  }
  FUN_00404c80();
  FUN_004fca20();
  FUN_004cacd0();
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShinshuku[3] */
/* 0071a050  FUN_0071a050  2834 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0071a050(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined1 local_6530 [8];
  undefined4 local_6528;
  double local_6524;
  double local_651c;
  undefined1 local_6514 [20];
  double local_6500;
  undefined1 *local_64f8;
  CWaitCursor local_64f1;
  int local_64f0;
  undefined1 local_64ec [25336];
  undefined4 local_1f4;
  undefined1 local_11c [16];
  undefined1 local_10c [16];
  undefined1 local_fc [16];
  undefined1 local_ec [16];
  undefined1 local_dc [16];
  undefined1 local_cc [16];
  undefined1 local_bc [8];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940217;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_004fb910();
  CWaitCursor::CWaitCursor(&local_64f1);
  local_8 = 0;
  local_6528 = FUN_0040c0e0(uVar2);
  FUN_00446aa0();
  local_8._0_1_ = 1;
  FUN_0079dea2();
  local_8._0_1_ = 2;
  FUN_00404c80();
  FUN_004fca20();
  fVar4 = (float10)FUN_004cad70();
  *(double *)(local_64f0 + 0xa060) = (double)fVar4;
  uVar7 = 0;
  FUN_00404c80(0);
  FUN_004fca20();
  FUN_004ca970(uVar7);
  if ((*(int *)(local_64f0 + 0x208) == 0) || (*(int *)(local_64f0 + 0x20c) != 10)) {
    if (*(int *)(local_64f0 + 0x20c) == 2) {
      iVar3 = FUN_0045b6c0(0,*(undefined4 *)(local_64f0 + 0x208),local_64f0 + 0x240);
      if (iVar3 == 0) {
        FUN_00717df0();
        *(undefined4 *)(*(int *)(local_64f0 + 4) + 0x8560) = 0;
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_00408b00();
      }
      else {
        FUN_0045d390(local_cc,*(undefined4 *)(local_64f0 + 4),*(undefined4 *)(local_64f0 + 0x240),
                     *(undefined4 *)(local_64f0 + 0x244),*(undefined4 *)(local_64f0 + 0x248),
                     *(undefined4 *)(local_64f0 + 0x24c),*(undefined4 *)(local_64f0 + 0x208),
                     local_6530);
        iVar3 = FUN_0079d98a();
        if (iVar3 != 0) {
          if (*(double *)(local_64f0 + 0xa060) <= 0.0) {
            local_651c = -*(double *)(local_64f0 + 0xa060);
          }
          else {
            local_651c = *(double *)(local_64f0 + 0xa060);
          }
          if (1e-07 < local_651c) {
            iVar3 = *(int *)(local_64f0 + 0x208);
            iVar1 = *(int *)(local_64f0 + 0x208);
            FUN_005f8940(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                         *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
                         *(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),
                         *(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24),0);
            local_44 = *(undefined4 *)(local_64f0 + 0x230);
            uStack_40 = *(undefined4 *)(local_64f0 + 0x234);
            local_3c = *(undefined4 *)(local_64f0 + 0x238);
            local_38 = *(undefined4 *)(local_64f0 + 0x23c);
            local_34 = *(double *)(local_64f0 + 0x240);
            local_2c = *(undefined8 *)(local_64f0 + 0x248);
            FUN_005f92e0(&local_44);
            FUN_005f92e0(&local_34);
            if (local_34 < (double)CONCAT44(uStack_40,local_44) ||
                local_34 == (double)CONCAT44(uStack_40,local_44)) {
              local_34 = local_34 - *(double *)(local_64f0 + 0xa060);
            }
            else {
              local_34 = local_34 + *(double *)(local_64f0 + 0xa060);
            }
            local_2c = 0;
            FUN_005f8ce0(&local_34);
            FUN_004988c0(local_dc,(undefined4)local_34,local_34._4_4_,(undefined4)local_2c,
                         local_2c._4_4_);
          }
        }
        FUN_00717cc0();
        FUN_0044cfb0(local_6514,*(undefined4 *)(local_64f0 + 4),0,
                     *(undefined4 *)(local_64f0 + 0x208),*(undefined4 *)(local_64f0 + 0x240),
                     *(undefined4 *)(local_64f0 + 0x244),*(undefined4 *)(local_64f0 + 0x248),
                     *(undefined4 *)(local_64f0 + 0x24c),*(undefined4 *)(local_64f0 + 0x230),
                     *(undefined4 *)(local_64f0 + 0x234),*(undefined4 *)(local_64f0 + 0x238),
                     *(undefined4 *)(local_64f0 + 0x23c));
        local_1f4 = 0;
        *(undefined4 *)(local_64f0 + 0x20c) = 0;
        FUN_00717650();
        FUN_00719c30(2,*(undefined4 *)(local_64f0 + 0x250),*(undefined4 *)(local_64f0 + 0x254),
                     *(undefined4 *)(local_64f0 + 600),*(undefined4 *)(local_64f0 + 0x25c));
        FUN_00404c80();
        FUN_0056d7d0();
        uVar6 = 1;
        uVar5 = 1;
        FUN_00404c80(1,1,0);
        FUN_004fca20();
        FUN_004cab90(uVar5,uVar6);
        FUN_00717df0();
        *(undefined4 *)(*(int *)(local_64f0 + 4) + 0x8560) = 0;
        local_8._0_1_ = 1;
        FUN_0079dfff();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_00408b00();
      }
    }
    else if (*(int *)(local_64f0 + 0x20c) == 4) {
      FUN_00717cc0();
      FUN_00464040();
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar3 = FUN_0079d98a();
      if (iVar3 != 0) {
        if (DAT_00a0cc50 == 0) {
          FUN_00455870(*(undefined4 *)(local_64f0 + 0x204),*(undefined4 *)(local_64f0 + 0x260),
                       *(undefined4 *)(local_64f0 + 0x264),*(undefined4 *)(local_64f0 + 0x268),
                       *(undefined4 *)(local_64f0 + 0x26c));
        }
        else {
          CMFCCaptionButtonEx::GetRect(*(CMFCCaptionButtonEx **)(local_64f0 + 0x208));
          FUN_00715db0(&local_54);
          FUN_00455870(*(undefined4 *)(local_64f0 + 0x204),local_54,local_50,local_4c,local_48);
        }
      }
      local_64f8 = *(undefined1 **)(local_64f0 + 0x204);
      FUN_0041f760();
      local_8 = CONCAT31(local_8._1_3_,5);
      iVar3 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
      if (iVar3 != 0) {
        if (*(double *)(local_64f0 + 0xa060) <= 0.0) {
          local_6524 = -*(double *)(local_64f0 + 0xa060);
        }
        else {
          local_6524 = *(double *)(local_64f0 + 0xa060);
        }
        if (1e-07 < local_6524) {
          FUN_00420110(*(undefined4 *)(local_64f0 + 0x204));
          FUN_005f8940(local_b4,local_b0,local_ac,local_a8,local_a4,local_a0,local_9c,local_98,0);
          CMFCCaptionButtonEx::GetRect(*(CMFCCaptionButtonEx **)(local_64f0 + 0x208));
          FUN_005f92e0(&local_24);
          if (local_1c < 0.0) {
            local_6500 = *(double *)(local_64f0 + 0xa060);
          }
          else {
            local_6500 = -*(double *)(local_64f0 + 0xa060);
          }
          FUN_004988c0(local_ec,local_b4,local_b0,local_ac,local_a8);
          FUN_005f92e0(&local_24);
          local_1c = local_6500;
          FUN_005f8ce0(&local_24);
          FUN_004988c0(local_fc,local_24,local_20,(undefined4)local_1c,local_1c._4_4_);
          FUN_004988c0(local_10c,local_a4,local_a0,local_9c,local_98);
          FUN_005f92e0(&local_24);
          local_1c = local_6500;
          FUN_005f8ce0(&local_24);
          FUN_004988c0(local_11c,local_24,local_20,(undefined4)local_1c,local_1c._4_4_);
          local_64f8 = local_bc;
        }
      }
      iVar3 = FUN_0046e550(*(undefined4 *)(local_64f0 + 4),local_64f8,
                           *(undefined4 *)(local_64f0 + 0x208));
      if (iVar3 == 0) {
        *(undefined4 *)(local_64f0 + 0xa058) = 2;
      }
      FUN_00717650();
      FUN_00719c30(4,*(undefined4 *)(local_64f0 + 0x250),*(undefined4 *)(local_64f0 + 0x254),
                   *(undefined4 *)(local_64f0 + 600),*(undefined4 *)(local_64f0 + 0x25c));
      FUN_00717df0();
      *(undefined4 *)(*(int *)(local_64f0 + 4) + 0x8560) = 0;
      local_8._0_1_ = 4;
      FUN_0041fd70();
      local_8._0_1_ = 2;
      FUN_004640a0();
      local_8._0_1_ = 1;
      FUN_0079dfff();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00408b00();
    }
    else {
      *(undefined4 *)(local_64f0 + 0x20c) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      FUN_00717df0();
      *(undefined4 *)(*(int *)(local_64f0 + 4) + 0x8560) = 0;
      local_8._0_1_ = 1;
      FUN_0079dfff();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_00408b00();
    }
  }
  else {
    FUN_00464040();
    local_8._0_1_ = 3;
    FUN_00478c70(*(undefined4 *)(local_64f0 + 4),local_64ec,local_6514,
                 *(undefined4 *)(local_64f0 + 0x208),*(undefined4 *)(local_64f0 + 0x230),
                 *(undefined4 *)(local_64f0 + 0x234),*(undefined4 *)(local_64f0 + 0x238),
                 *(undefined4 *)(local_64f0 + 0x23c),1,*(undefined8 *)(local_64f0 + 0xa060));
    *(undefined4 *)(local_64f0 + 0x20c) = 0;
    *(undefined4 *)(local_64f0 + 0x208) = 0;
    FUN_00717df0();
    *(undefined4 *)(*(int *)(local_64f0 + 4) + 0x8560) = 0;
    local_8._0_1_ = 2;
    FUN_004640a0();
    local_8._0_1_ = 1;
    FUN_0079dfff();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_00408b00();
  }
  ExceptionList = local_10;
  return;
}



