/* CZukei -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukei[1] */
/* 00769c70  FUN_00769c70  68 bytes, 0 callers */

undefined4 FUN_00769c70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00769b60();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa8);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukei[16], CZukeiObject[16] */
/* 0076a170  FUN_0076a170  256 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0076a170(void)

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
    local_63ec = 0;
  }
  else {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044b6f0(local_6400,*(undefined4 *)(local_63e8 + 4));
    *(int *)(*(int *)(local_63e8 + 4) + 0x8560) = *(int *)(*(int *)(local_63e8 + 4) + 0x8560) + -1;
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukei[46], CZukei25D[46], CZukeiHikage[46], CZukeiKage1[46], CZukeiKage2[46], CZukeiKage3[46], CZukeiKijunten[46], CZukeiObject[46], CZukeiPrintHanni[46] */
/* 0076c9c0  FUN_0076c9c0  2306 bytes, 40 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0076c9c0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00404900(&DAT_00956338);
  bVar1 = false;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x857c) = 0;
  iVar2 = FUN_0079d98a(&PTR_s_CZukeiAuto_00977bfc);
  if ((iVar2 != 0) && (DAT_00a0c7bc != 0)) {
    bVar1 = true;
  }
  if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) != 0) {
    if (bVar1) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x857c) = 1;
      return 0;
    }
    if (((1 < DAT_00a0c7c4) && (*(int *)(*(int *)(in_ECX + 4) + 0x908c) == 0)) &&
       (iVar2 = FUN_00777690(param_1,0,1,param_2,param_3,param_4,param_5,param_6,param_7),
       iVar2 != 0)) {
      return 0;
    }
    switch(param_2) {
    case 1:
      goto switchD_0076caca_caseD_1;
    case 2:
      if (param_3 == 1) {
        FUN_005168b0(0x1472,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x808c;
      return 0;
    case 3:
      if (param_3 == 1) {
        FUN_005168b0(0x142d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8061;
      return 0;
    case 4:
      if (param_3 == 1) {
        FUN_005168b0(0x144b,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8062;
      return 0;
    case 5:
      if (param_3 == 1) {
        FUN_005168b0(0x1432,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8050;
      return 0;
    case 6:
      if (param_3 == 1) {
        FUN_005168b0(0x272a,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(in_ECX + 0x94) = 0;
      FUN_007751e0(1,param_4,param_5,param_6,param_7);
      return 0;
    case 7:
      if (param_3 == 1) {
        FUN_005168b0(0x1431,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x806a;
      return 0;
    case 8:
      if (param_3 == 1) {
        FUN_005168b0(0x1430,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8073;
      return 0;
    case 9:
      if (param_3 == 1) {
        FUN_005168b0(0x142f,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8069;
      return 0;
    case 10:
      if (param_3 == 1) {
        FUN_005168b0(0x142e,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x807c;
      return 0;
    case 0xb:
      if (param_3 == 1) {
        FUN_005168b0(0x142c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x804f;
      return 0;
    case 0xc:
      if (param_3 == 1) {
        FUN_005168b0(0x144c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        return 0;
      }
      if (param_3 != 2) {
        return 0;
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8082;
      return 0;
    default:
      if (param_3 == 1) {
        FUN_005168b0(0x271d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                     *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
      }
      *(undefined4 *)(in_ECX + 0x94) = 0;
      return 0;
    }
  }
  FUN_00778870();
  if (((param_2 != 9) && (param_2 != 5)) && (param_2 != 6)) {
    if (bVar1) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x857c) = 1;
      return 0;
    }
    if (((1 < DAT_00a0c7c4) && (*(int *)(*(int *)(in_ECX + 4) + 0x908c) == 0)) &&
       (iVar2 = FUN_00777690(param_1,0,0,param_2,param_3,param_4,param_5,param_6,param_7),
       iVar2 != 0)) {
      return 0;
    }
  }
  if (param_3 == 1) {
    if ((DAT_00a0c7d4 != 0) && (param_2 == 6)) {
      *(undefined4 *)(in_ECX + 0x94) = 0;
    }
    if (param_2 == 9) {
      FUN_005168b0(0x144f,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
    }
    else if ((param_2 == 6) && (*(int *)(in_ECX + 0x9c) + 1 < *(int *)(in_ECX + 0x94))) {
      FUN_005168b0(0x148d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
    }
    else {
      FUN_005168b0(param_2 + 10000,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
    }
  }
  if (param_3 == 2) {
    iVar2 = *(int *)(in_ECX + 4);
    FUN_004988c0(local_18,*(undefined4 *)(iVar2 + 0x8f68),*(undefined4 *)(iVar2 + 0x8f6c),
                 *(undefined4 *)(iVar2 + 0x8f70),*(undefined4 *)(iVar2 + 0x8f74));
    if (param_2 == 4) {
      *(undefined4 *)(in_ECX + 0xc) = 1;
      iVar2 = *(int *)(in_ECX + 4);
      iVar2 = FUN_0040dbb0(0,*(undefined4 *)(iVar2 + 0x8f68),*(undefined4 *)(iVar2 + 0x8f6c),
                           *(undefined4 *)(iVar2 + 0x8f70),*(undefined4 *)(iVar2 + 0x8f74));
      if (iVar2 != 0) {
        *(undefined4 *)(in_ECX + 0xc) = 0;
      }
      iVar2 = *(int *)(in_ECX + 4);
      puVar3 = (undefined4 *)
               FUN_004988c0(local_28,*(undefined4 *)(iVar2 + 0x8f68),*(undefined4 *)(iVar2 + 0x8f6c)
                            ,*(undefined4 *)(iVar2 + 0x8f70),*(undefined4 *)(iVar2 + 0x8f74));
      FUN_004988c0(local_38,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
    }
    switch(param_2) {
    case 1:
      if (*(int *)(*(int *)(in_ECX + 4) + 0x8564) == 0x8003) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8004;
      }
      else {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8003;
      }
      break;
    case 2:
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8005;
      break;
    case 3:
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x804e;
      break;
    case 4:
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8013;
      break;
    case 5:
      FUN_0076e360(param_4,param_5,param_6,param_7);
      break;
    case 6:
      FUN_007751e0(0,param_4,param_5,param_6,param_7);
      break;
    case 7:
      if (*(int *)(*(int *)(in_ECX + 4) + 0x9058) == 0) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8096;
      }
      else {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8024;
      }
      break;
    case 8:
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8017;
      break;
    case 9:
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8093;
      break;
    case 10:
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x801a;
      break;
    case 0xb:
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8020;
      break;
    case 0xc:
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8026;
    }
    *(undefined4 *)(in_ECX + 0x94) = 0;
  }
  return 0;
switchD_0076caca_caseD_1:
  if (param_3 == 1) {
    FUN_005168b0(0x144d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                 *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
    return 0;
  }
  if (param_3 != 2) {
    return 0;
  }
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9090) = 0x8065;
  return 0;
}




/* vtable slots: CZukei[47], CZukei25D[47], CZukeiHikage[47], CZukeiHikaku[47], CZukeiKage1[47], CZukeiKage2[47], CZukeiKage3[47], CZukeiKigouHenkei[47], CZukeiKijunten[47], CZukeiKyori[47], CZukeiObject[47], CZukeiPrintHanni[47], CZukeiTen[47], CZukeiTenkuu[47] */
/* 0076d330  FUN_0076d330  3934 bytes, 28 callers */

undefined4
FUN_0076d330(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  double local_28;
  double local_20;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int *local_8;
  
  FUN_00404900(&DAT_00956338);
  local_18 = 0;
  *(undefined4 *)(local_8[1] + 0x857c) = 0;
  iVar1 = FUN_0079d98a(&PTR_s_CZukeiAuto_00977bfc);
  if ((iVar1 != 0) && (DAT_00a0c7bc != 0)) {
    local_18 = 1;
  }
  local_c = 0;
  if (((param_2 == 100) || (param_2 == 200)) && (*(int *)(local_8[1] + 0x908c) == -1)) {
    if (param_3 == 3) {
      if (param_2 == 100) {
        FUN_004efbb0();
      }
      else {
        FUN_004efbb0();
      }
    }
    else {
      if (param_2 == 100) {
        local_8[0x25] = 0;
        if (*(int *)(local_8[1] + 0x90dc) == 2) {
          if (*(int *)(local_8[1] + 0x1824) == 0) {
            FUN_00508a50();
          }
          else {
            FUN_004fd3b0();
          }
          return 0;
        }
      }
      else {
        local_8[0x25] = local_8[0x27] + 2;
      }
      FUN_007751e0(0,param_4,param_5,param_6,param_7);
      *(undefined4 *)(local_8[1] + 0x908c) = 0;
      *(undefined4 *)(local_8[1] + 37000) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
    }
    local_c = 0;
  }
  else if (*(int *)(local_8[1] + 0x907c) == 0) {
    if (((((param_2 != 3) && (param_2 != 4)) &&
         ((param_2 != 5 && ((param_2 != 6 && (param_2 != 9)))))) && (param_2 != 0xc)) &&
       (param_2 != 0x16)) {
      if (local_18 != 0) {
        *(undefined4 *)(local_8[1] + 0x857c) = 1;
        return 0;
      }
      if (((*(int *)(local_8[1] + 0x908c) == 0) && (1 < DAT_00a0c7c4)) &&
         (iVar1 = FUN_00777690(param_1,1,2,param_2,param_3,param_4,param_5,param_6,param_7),
         iVar1 != 0)) {
        return 0;
      }
    }
    if ((DAT_00a0c7cc == 0) || ((param_2 != 4 && (param_2 != 5)))) {
      local_10 = param_2 + -3;
      switch(param_2) {
      case 3:
        local_c = (**(code **)(*local_8 + 0x48))();
        break;
      case 4:
        if (param_3 == 1) {
          FUN_005168b0(0x2779,*(undefined4 *)(local_8[1] + 0x8f50),
                       *(undefined4 *)(local_8[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00504100();
        }
        break;
      case 5:
        if (param_3 == 1) {
          FUN_005168b0(0x277a,*(undefined4 *)(local_8[1] + 0x8f50),
                       *(undefined4 *)(local_8[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00503e90();
        }
        break;
      case 6:
        local_c = (**(code **)(*local_8 + 0x4c))();
        break;
      default:
        local_c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        break;
      case 9:
        local_c = (**(code **)(*local_8 + 0x50))();
        break;
      case 0xc:
      case 0x16:
        local_c = (**(code **)(*local_8 + 0x54))();
      }
    }
    else {
      if (param_3 == 1) {
        FUN_005168b0(0x271d,*(undefined4 *)(local_8[1] + 0x8f50),
                     *(undefined4 *)(local_8[1] + 0x8f54),1,0);
      }
      local_c = 0;
    }
  }
  else if (((DAT_00a0c7c4 < 2) || (*(int *)(local_8[1] + 0x908c) != 0)) ||
          (iVar1 = FUN_00777690(param_1,1,3,param_2,param_3,param_4,param_5,param_6,param_7),
          iVar1 == 0)) {
    local_14 = param_2 + -1;
    switch(local_14) {
    case 0:
      if (*(int *)(local_8[1] + 0x908c) == -1) {
        if (param_3 == 3) {
          FUN_004efbb0();
        }
        else {
          iVar1 = FUN_00772770(2,1,*(undefined8 *)(local_8[1] + 0x17c0),param_4,param_5,param_6,
                               param_7,&local_20);
          if (iVar1 != 0) {
            local_20 = local_20 + 90.0;
            if (local_20 <= -90.0) {
              local_20 = local_20 + 180.0;
            }
            if (90.0 < local_20) {
              local_20 = local_20 - 180.0;
            }
            (**(code **)(*local_8 + 0xc4))(local_20);
            FUN_00516c40(1,local_20);
            FUN_0076a130();
            DAT_00a0ba70 = 1;
            *(undefined4 *)(local_8[1] + 0x908c) = 0;
            *(undefined4 *)(local_8[1] + 37000) = 0;
            FUN_00404c80();
            FUN_0056d7d0();
          }
        }
      }
      else if (param_3 == 1) {
        FUN_005168b0(0x2726,*(undefined4 *)(local_8[1] + 0x8f50),
                     *(undefined4 *)(local_8[1] + 0x8f54),1,0);
      }
      else {
        iVar1 = FUN_00772770(param_3,1,*(undefined8 *)(local_8[1] + 0x17c0),param_4,param_5,param_6,
                             param_7,&local_28);
        if (iVar1 != 0) {
          local_28 = local_28 + 90.0;
          if (local_28 <= -90.0) {
            local_28 = local_28 + 180.0;
          }
          if (90.0 < local_28) {
            local_28 = local_28 - 180.0;
          }
          (**(code **)(*local_8 + 0xc4))(local_28);
          FUN_00516c40(1,local_28);
          FUN_0076a130();
          DAT_00a0ba70 = 1;
          FUN_00404c80();
          FUN_0056d7d0();
        }
      }
      break;
    case 1:
      local_c = FUN_00771030(param_3,param_4,param_5,param_6,param_7);
      break;
    case 2:
      local_c = FUN_007748b0();
      break;
    case 3:
      if (*(int *)(local_8[1] + 0x908c) == -1) {
        if (param_3 == 3) {
          FUN_004efbb0();
        }
        else {
          iVar1 = FUN_00772770(2,1,*(undefined8 *)(local_8[1] + 0x17c0),param_4,param_5,param_6,
                               param_7,&local_30);
          if (iVar1 != 0) {
            (**(code **)(*local_8 + 0xc4))(local_30);
            FUN_00516c40(1,local_30);
            FUN_0076a130();
            DAT_00a0ba70 = 1;
            *(undefined4 *)(local_8[1] + 0x908c) = 0;
            *(undefined4 *)(local_8[1] + 37000) = 0;
            FUN_00404c80();
            FUN_0056d7d0();
          }
        }
      }
      else if (param_3 == 1) {
        FUN_005168b0(0x2720,*(undefined4 *)(local_8[1] + 0x8f50),
                     *(undefined4 *)(local_8[1] + 0x8f54),1,0);
      }
      else {
        iVar1 = FUN_00772770(param_3,1,*(undefined8 *)(local_8[1] + 0x17c0),param_4,param_5,param_6,
                             param_7,&local_38);
        if (iVar1 != 0) {
          (**(code **)(*local_8 + 0xc4))(local_38);
          FUN_00516c40(1,local_38);
          FUN_0076a130();
          DAT_00a0ba70 = 1;
          FUN_00404c80();
          FUN_0056d7d0();
        }
      }
      break;
    case 4:
      local_c = FUN_00770b60();
      break;
    case 5:
      if (*(int *)(local_8[1] + 0x908c) == -1) {
        if (param_3 == 3) {
          FUN_004efbb0();
        }
        else {
          (**(code **)(*local_8 + 0xc0))(1,param_4,param_5,param_6,param_7);
          *(undefined4 *)(local_8[1] + 0x908c) = 0;
          *(undefined4 *)(local_8[1] + 37000) = 0;
          FUN_00404c80();
          FUN_0056d7d0();
        }
      }
      else if (param_3 == 1) {
        FUN_005168b0(0x272e,*(undefined4 *)(local_8[1] + 0x8f50),
                     *(undefined4 *)(local_8[1] + 0x8f54),1,0);
      }
      else if (param_3 == 2) {
        (**(code **)(*local_8 + 0xc0))(1,param_4,param_5,param_6,param_7);
      }
      break;
    case 6:
      local_c = FUN_00770b60();
      break;
    case 7:
      if (param_3 == 1) {
        FUN_005168b0(0x2729,*(undefined4 *)(local_8[1] + 0x8f50),
                     *(undefined4 *)(local_8[1] + 0x8f54),1,0);
      }
      else {
        iVar1 = FUN_00772770(param_3,0xffffffff,*(undefined8 *)(local_8[1] + 0x17c0),param_4,param_5
                             ,param_6,param_7,&local_40);
        if (iVar1 != 0) {
          (**(code **)(*local_8 + 0xc4))(local_40);
          FUN_00516c40(1,local_40);
          FUN_0076a130();
          DAT_00a0ba70 = 1;
          FUN_00404c80();
          FUN_0056d7d0();
        }
      }
      break;
    case 8:
      local_c = FUN_007748b0();
      break;
    case 9:
      local_c = FUN_00771ca0(param_3,param_4,param_5,param_6,param_7);
      break;
    case 10:
      if (*(int *)(local_8[1] + 0x908c) == -1) {
        if (param_3 == 3) {
          FUN_004efbb0();
        }
        else {
          FUN_0076bba0(&local_48,param_4,param_5,param_6,param_7);
          (**(code **)(*local_8 + 200))(local_48);
          FUN_00516c40(0,local_48);
          FUN_0076a130();
          *(undefined4 *)(local_8[1] + 0x908c) = 0;
          *(undefined4 *)(local_8[1] + 37000) = 0;
          FUN_00404c80();
          FUN_0056d7d0();
        }
      }
      else if (param_3 == 1) {
        FUN_005168b0(0x2727,*(undefined4 *)(local_8[1] + 0x8f50),
                     *(undefined4 *)(local_8[1] + 0x8f54),1,0);
      }
      else if (param_3 == 2) {
        FUN_0076bba0(&local_50,param_4,param_5,param_6,param_7);
        (**(code **)(*local_8 + 200))(local_50);
        FUN_00516c40(0,local_50);
        FUN_0076a130();
      }
      break;
    case 0xb:
      if (*(int *)(local_8[1] + 0x908c) == -1) {
        if (param_3 == 3) {
          FUN_004efbb0();
        }
        else {
          (**(code **)(*local_8 + 0xc0))(0,param_4,param_5,param_6,param_7);
          *(undefined4 *)(local_8[1] + 0x908c) = 0;
          *(undefined4 *)(local_8[1] + 37000) = 0;
          FUN_00404c80();
          FUN_0056d7d0();
        }
      }
      else if (param_3 == 1) {
        FUN_005168b0(0x272f,*(undefined4 *)(local_8[1] + 0x8f50),
                     *(undefined4 *)(local_8[1] + 0x8f54),1,0);
      }
      else if (param_3 == 2) {
        (**(code **)(*local_8 + 0xc0))(0,param_4,param_5,param_6,param_7);
      }
      break;
    default:
      local_c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      break;
    case 0xd:
      local_c = FUN_00773c90(param_3,param_4,param_5,param_6,param_7);
      break;
    case 0xe:
      local_c = FUN_0076a270(param_3,param_4,param_5,param_6,param_7);
      break;
    case 0xf:
      local_c = FUN_007730b0(param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_c = 0;
  }
  return local_c;
}




/* vtable slots: CZukei[49], CZukei25D[49], CZukei2Sen[49], CZukeiBunkatsu[49], CZukeiChuushinSen[49], CZukeiHikage[49], CZukeiHikaku[49], CZukeiKage1[49], CZukeiKage2[49], CZukeiKage3[49], CZukeiKijunten[49], CZukeiKyokuSen[49], CZukeiKyori[49], CZukeiObject[49], CZukeiPrintHanni[49], CZukeiRenzokuSen[49], CZukeiSetuDaEn[49], CZukeiTen[49], CZukeiTenkuu[49] */
/* 0076e300  FUN_0076e300  34 bytes, 0 callers */

void FUN_0076e300(undefined8 param_1)

{
  int in_ECX;
  
  *(undefined8 *)(in_ECX + 0x70) = param_1;
  FUN_0076a130();
  return;
}




/* vtable slots: CZukei[50], CZukei25D[50], CZukeiChuushinSen[50], CZukeiHikage[50], CZukeiHikaku[50], CZukeiKage1[50], CZukeiKage2[50], CZukeiKage3[50], CZukeiKijunten[50], CZukeiKyokuSen[50], CZukeiObject[50], CZukeiPrintHanni[50], CZukeiSetuDaEn[50], CZukeiTen[50], CZukeiTenkuu[50] */
/* 0076e330  FUN_0076e330  37 bytes, 0 callers */

void FUN_0076e330(undefined8 param_1)

{
  int in_ECX;
  
  *(undefined8 *)(in_ECX + 0x80) = param_1;
  FUN_0076a130();
  return;
}




/* vtable slots: CZukei[10], CZukei25D[10], CZukei2Sen[10], CZukeiAuto[10], CZukeiHikage[10], CZukeiHikaku[10], CZukeiKage1[10], CZukeiKage2[10], CZukeiKage3[10], CZukeiKigouHenkei[10], CZukeiKijunten[10], CZukeiKyokuSen[10], CZukeiKyori[10], CZukeiObject[10], CZukeiPrintHanni[10], CZukeiRenzokuSen[10], CZukeiRitsumen[10], CZukeiSessen[10], CZukeiSetuDaEn[10], CZukeiSetuEn[10], CZukeiTakakukei[10], CZukeiTategu[10], CZukeiTen[10], CZukeiTenkuu[10] */
/* 0076e630  FUN_0076e630  139 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0076e630(int param_1)

{
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 != 0) {
    FUN_004988c0(local_18,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                 *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
    FUN_004988c0(local_28,*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                 *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));
  }
  return;
}




/* vtable slots: CZukei[9], CZukeiKijunten[9], CZukeiObject[9] */
/* 0076e6c0  FUN_0076e6c0  265 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_0076e6c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  int in_ECX;
  bool bVar2;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  bVar2 = *(int *)(*(int *)(in_ECX + 4) + 0x8560) == 0;
  if (bVar2) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 1;
    puVar1 = (undefined4 *)FUN_004988c0(local_18,param_2,param_3,param_4,param_5);
    FUN_004988c0(local_28,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    FUN_004efbb0(0x14cb,0,0);
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 2;
    FUN_004988c0(local_38,param_2,param_3,param_4,param_5);
    FUN_004efbb0(0x14b4,0,0);
  }
  return !bVar2;
}




/* vtable slots: CZukei[11], CZukeiKijunten[11], CZukeiObject[11] */
/* 0076e7d0  FUN_0076e7d0  564 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0076e7d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093cdb0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8560) == 0) {
    iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&param_2,1);
    if (iVar2 == 1) {
      puVar1 = (undefined4 *)FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
      FUN_004988c0(local_34,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      FUN_004efbb0(0x14cb,0,0);
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 1;
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar3 = 0;
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar3 = 0;
    }
  }
  else {
    iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&param_2,1);
    if (iVar2 == 1) {
      FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
      FUN_004efbb0(0x14b4,0,0);
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 2;
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar3 = 1;
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar3 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar3;
}



