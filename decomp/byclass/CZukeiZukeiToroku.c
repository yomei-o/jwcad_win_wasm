/* CZukeiZukeiToroku -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiZukeiToroku[6] */
/* 007505b0  FUN_007505b0  274 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007505b0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_330 [808];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0040c0e0();
  iVar1 = FUN_00572b10();
  if ((iVar1 == 0) && (*(int *)(in_ECX + 0x1fc) == 0)) {
    *(undefined4 *)(in_ECX + 0x1fc) = 1;
    FUN_0074fb00();
  }
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    if (*(int *)(in_ECX + 0x1f8) == 0) {
      FUN_005977f0(0x154b);
      uVar2 = FUN_00404920();
      FUN_0053e560(local_330,L"   %s",uVar2);
      FUN_00404770();
      FUN_004efbb0(0x151b,local_330,0);
    }
    else {
      FUN_0040ac80(param_1);
    }
  }
  else {
    FUN_006f7cc0(param_1);
  }
  return;
}




/* vtable slots: CZukeiZukeiToroku[16] */
/* 007506d0  FUN_007506d0  463 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007506d0(void)

{
  int iVar1;
  undefined1 local_6410 [24];
  undefined4 local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939d2b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63f0 = FUN_0040c0e0(local_14);
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  if (*(int *)(local_63e8 + 0x1fc) == 0) {
    FUN_0044de00(local_6410,*(undefined4 *)(local_63e8 + 4));
    FUN_0044c830(local_6410,*(undefined4 *)(local_63e8 + 4));
    FUN_007520f0();
    local_63f8 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_63f4 = local_63f8;
  }
  else {
    local_63ec = FUN_006f85c0();
    if (local_63ec == 0) {
      iVar1 = FUN_00572b10();
      if (iVar1 == 0) {
        FUN_00458a80(local_6410,*(undefined4 *)(local_63e8 + 4),0);
        *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
      }
      else {
        *(undefined4 *)(local_63e8 + 0x1fc) = 0;
        FUN_0074fb00();
        FUN_00404c80();
        FUN_0056d7d0();
      }
    }
    local_63f4 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_63f4;
}




/* vtable slots: CZukeiZukeiToroku[0] */
/* 00750c10  FUN_00750c10  16 bytes, 0 callers */

undefined ** FUN_00750c10(void)

{
  return &PTR_s_CZukeiZukeiToroku_0097b3a8;
}




/* vtable slots: CZukeiZukeiToroku[46] */
/* 00751420  FUN_00751420  1051 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00751420(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int in_ECX;
  undefined4 local_640c;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941a1b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0c7c0 == 0) {
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    local_640c = 0;
    if (*(int *)(in_ECX + 0x1fc) == 0) {
      if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
        if (param_2 == 5) {
          if (param_3 == 1) {
            FUN_005168b0(0x272c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            *(undefined4 *)(in_ECX + 0x1f8) = 1;
            FUN_00653df0(1);
            FUN_00652e80(0);
            FUN_004988c0(local_24,param_4,param_5,param_6,param_7);
            FUN_0040c9d0();
            *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = 1;
          }
        }
        else if (param_2 == 6) {
          if (param_3 == 1) {
            FUN_005168b0(0x272d,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            *(undefined4 *)(in_ECX + 0x1f8) = 1;
            FUN_00653df0(0);
            FUN_00652e80(1);
            FUN_004988c0(local_34,param_4,param_5,param_6,param_7);
            FUN_0040c9d0();
            *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = 1;
          }
        }
        else {
          local_640c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        }
      }
      else if (param_2 == 4) {
        if (param_3 == 1) {
          FUN_005168b0(0x1817,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                       *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          FUN_00406bc0(0x111,0x8046,0);
        }
      }
      else {
        local_640c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
    else {
      local_640c = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
    }
  }
  else {
    local_640c = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  ExceptionList = local_10;
  return local_640c;
}




/* vtable slots: CZukeiZukeiToroku[47] */
/* 00751840  FUN_00751840  182 bytes, 0 callers */

void FUN_00751840(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int in_ECX;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(in_ECX + 0x1fc) == 0) {
      FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      FUN_006fa580(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}




/* vtable slots: CZukeiZukeiToroku[34] */
/* 00751900  FUN_00751900  357 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00751900(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined1 local_640c [20];
  int local_63f8;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a30b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x1fc) = 0;
  local_63f8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
  local_8._0_1_ = 1;
  iVar1 = *(int *)(local_63f8 + 4);
  FUN_00454cb0(0,*(undefined4 *)(local_63f8 + 4),*(undefined4 *)(iVar1 + 0x8f10),
               *(undefined4 *)(iVar1 + 0x8f14),*(undefined4 *)(iVar1 + 0x8f18),
               *(undefined4 *)(iVar1 + 0x8f1c));
  FUN_0044de00(local_640c,*(undefined4 *)(local_63f8 + 4));
  uVar3 = 0;
  puVar2 = (undefined4 *)FUN_004b75a0(local_24);
  FUN_004508b0(0x10,local_640c,*(undefined4 *)(local_63f8 + 4),*puVar2,puVar2[1],puVar2[2],puVar2[3]
               ,uVar3);
  FUN_0074fb00();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZukeiToroku[30] */
/* 00751a70  FUN_00751a70  31 bytes, 0 callers */

void FUN_00751a70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    FUN_006fbbb0();
  }
  return;
}




/* vtable slots: CZukeiZukeiToroku[31] */
/* 00751a90  FUN_00751a90  1410 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00751a90(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_64f8 [4];
  undefined4 local_64f4;
  FILE *local_64f0;
  CWaitCursor local_64e5;
  CSimpleStringT<wchar_t,0> local_64e4 [4];
  int local_64e0;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941ab8;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    local_64e0 = in_ECX;
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    FUN_0044de00();
    local_64f4 = FUN_0040c0e0();
    iVar2 = FUN_00573cb0();
    if (iVar2 == 0) {
      FUN_004fb910();
      DAT_00a0b3d0 = 1;
      CStringT<>();
      local_8._0_1_ = 2;
      FUN_0040c0e0();
      FUN_00403dd0();
      local_8._0_1_ = 3;
      FUN_0058d590(*(undefined4 *)(local_64e0 + 4));
      local_8._0_1_ = 4;
      iVar2 = FUN_0058e240();
      if (iVar2 == 1) {
        FUN_0040c0e0();
        FUN_00404860();
        FUN_00404860();
        FUN_00404920();
        local_64f0 = (FILE *)previous_character();
        if (local_64f0 == (FILE *)0x0) {
          FUN_00404920();
          local_64f0 = (FILE *)previous_character();
          if ((local_64f0 != (FILE *)0x0) && (iVar2 = _fclose(local_64f0), iVar2 != 0)) {
            local_8._0_1_ = 3;
            FUN_0058dae0();
            local_8._0_1_ = 2;
            FUN_00404540();
            local_8._0_1_ = 1;
            FUN_00404540();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return;
          }
        }
        else {
          _fclose(local_64f0);
          FUN_00403dd0();
          iVar2 = FUN_004f62a0();
          if (iVar2 != 1) {
            local_8._0_1_ = 3;
            FUN_0058dae0();
            local_8._0_1_ = 2;
            FUN_00404540();
            local_8._0_1_ = 1;
            FUN_00404540();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return;
          }
        }
        iVar2 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_64e4);
        if (iVar2 < 5) {
          local_8._0_1_ = 3;
          FUN_0058dae0();
          local_8._0_1_ = 2;
          FUN_00404540();
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return;
        }
        ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::Right
                  ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)local_64e4,
                   (int)local_64f8);
        local_8._0_1_ = 5;
        FUN_0048b0e0();
        cVar1 = FUN_00447350();
        if (cVar1 == '\0') {
          FUN_00404920();
          FUN_007a7076();
          local_8._0_1_ = 6;
          CWaitCursor::CWaitCursor(&local_64e5);
          local_8._0_1_ = 7;
          FUN_00518ac0();
          local_8._0_1_ = 8;
          FUN_0051f610();
          local_8._0_1_ = 7;
          FUN_004066b0();
          local_8._0_1_ = 6;
          FUN_00408b00();
          local_8._0_1_ = 5;
          FUN_007a70db();
        }
        else {
          FUN_00403dd0(local_64e4);
          FUN_00750c20(local_64f4);
        }
        local_8._0_1_ = 4;
        FUN_00404540();
      }
      else {
        FUN_0040c0e0();
        FUN_00404860();
      }
      FUN_004f0bc0();
      DAT_00a0b3d0 = 0;
      FUN_0044c830();
      FUN_007520f0();
      local_8._0_1_ = 3;
      FUN_0058dae0();
      local_8._0_1_ = 2;
      FUN_00404540();
      local_8._0_1_ = 1;
      FUN_00404540();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_005168b0(0x1451,*(undefined4 *)(*(int *)(local_64e0 + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(local_64e0 + 4) + 0x8f28));
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    FUN_006fbbf0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZukeiToroku[51] */
/* 00752020  FUN_00752020  43 bytes, 0 callers */

void FUN_00752020(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_00404540();
  }
  else {
    FUN_00404540();
  }
  return;
}




/* vtable slots: CZukeiZukeiToroku[9] */
/* 00752150  FUN_00752150  476 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00752150(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined1 local_6410 [20];
  undefined4 local_63fc;
  int local_63f8;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941b0b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    local_63f8 = in_ECX;
    if (*(int *)(in_ECX + 0x1f8) == 0) {
      FUN_00517640(param_2,param_3,param_4,param_5);
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
      local_8._0_1_ = 1;
      FUN_0044de00(local_6410,*(undefined4 *)(local_63f8 + 4));
      uVar3 = 0;
      puVar2 = (undefined4 *)FUN_004b75a0(local_24);
      FUN_004508b0(0x10,local_6410,*(undefined4 *)(local_63f8 + 4),*puVar2,puVar2[1],puVar2[2],
                   puVar2[3],uVar3);
      local_63fc = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      iVar1 = FUN_0040dbb0(param_1,param_2,param_3,param_4,param_5);
      if (iVar1 != 0) {
        *(undefined4 *)(local_63f8 + 0x1f8) = 0;
      }
      local_63fc = 0;
    }
  }
  else {
    local_63fc = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return local_63fc;
}




/* vtable slots: CZukeiZukeiToroku[11] */
/* 00752330  FUN_00752330  422 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00752330(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
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
  if (in_ECX[0x7f] == 0) {
    if (in_ECX[0x7e] == 0) {
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      FUN_00446aa0(local_14);
      local_8 = 0;
      iVar2 = FUN_00451eb0(in_ECX[1],&local_24,1);
      if (iVar2 == 1) {
        uVar1 = (**(code **)(*in_ECX + 0x24))(param_1,local_24,local_20,local_1c,local_18);
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
    else {
      iVar2 = FUN_0040deb0(param_1,param_2,param_3,param_4,param_5);
      if (iVar2 != 0) {
        in_ECX[0x7e] = 0;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiZukeiToroku[4] */
/* 007524e0  FUN_007524e0  205 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007524e0(void)

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
  if (*(int *)(*(int *)(in_ECX + 4) + 0x8564) != 0x8046) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}



