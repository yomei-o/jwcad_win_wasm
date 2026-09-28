/* CDataTen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataTen[1] */
/* 00420bc0  FUN_00420bc0  68 bytes, 0 callers */

undefined4 FUN_00420bc0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041fe70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x80);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataTen[14] */
/* 00421400  FUN_00421400  143 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00421400(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00403cd0(local_20c,L"Point  %d (%g,%g)                                        ",param_3,
               *(undefined8 *)(in_ECX + 8),*(undefined8 *)(in_ECX + 0x10));
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x32,local_20c,uVar1);
  return;
}




/* vtable slots: CDataTen[15] */
/* 004253f0  FUN_004253f0  151 bytes, 1 callers */

undefined4 FUN_004253f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  iVar1 = FUN_00424ed0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    local_c = 0;
  }
  else {
    iVar1 = FUN_0042b460(param_2);
    if (iVar1 == 0) {
      if ((*(int *)(in_ECX + 0x6c) == 0) || (900 < *(int *)(in_ECX + 0x6c))) {
        local_c = FUN_00424200(param_1,param_2,param_3);
      }
      else {
        local_c = FUN_00425490(param_1,param_2,param_3);
      }
      FUN_0042e540();
    }
    else {
      FUN_0042e540();
      local_c = 0;
    }
  }
  return local_c;
}




/* vtable slots: CDataTen[3] */
/* 00429a10  FUN_00429a10  307 bytes, 0 callers */

void FUN_00429a10(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  
  iVar1 = DAT_00a0eed4;
  if (DAT_00a0eed4 == 0) {
    CStringT<>("POINT");
    FUN_004a7e90(0);
  }
  else {
    CStringT<>("CIRCLE");
    FUN_004a7e90(0);
  }
  FUN_0049dea0(&stack0xffffffe0,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),
               *(undefined1 *)(in_ECX + 0x28));
  FUN_004a7e90(8);
  FUN_0049dcf0();
  FUN_004a7e10(0x3e);
  fVar2 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 8));
  FUN_004a77a0(10,(double)fVar2);
  fVar2 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x10));
  FUN_004a77a0(0x14,(double)fVar2);
  if (iVar1 != 0) {
    fVar2 = (float10)FUN_004a93a0(0x3fd999999999999a);
    FUN_004a77a0(0x28,(double)fVar2);
  }
  return;
}




/* vtable slots: CDataTen[0] */
/* 0042b0e0  FUN_0042b0e0  16 bytes, 0 callers */

undefined ** FUN_0042b0e0(void)

{
  return &PTR_s_CDataTen_009fe05c;
}




/* vtable slots: CDataTen[17] */
/* 0042d990  FUN_0042d990  348 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0042d990(int param_1,double param_2,double param_3)

{
  double *pdVar1;
  double *pdVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined8 local_2c;
  undefined8 local_24;
  
  pdVar2 = (double *)(in_ECX + 8);
  pdVar1 = (double *)(in_ECX + 0x10);
  if (*(double *)(param_1 + 0x8ee8) < *pdVar2 || *(double *)(param_1 + 0x8ee8) == *pdVar2) {
    if (*pdVar2 < *(double *)(param_1 + 0x8ef8) || *pdVar2 == *(double *)(param_1 + 0x8ef8)) {
      if (*(double *)(param_1 + 0x8ef0) < *pdVar1 || *(double *)(param_1 + 0x8ef0) == *pdVar1) {
        if (*pdVar1 < *(double *)(param_1 + 0x8f00) || *pdVar1 == *(double *)(param_1 + 0x8f00)) {
          if (param_2 - *pdVar2 <= 0.0) {
            local_24 = -(param_2 - *pdVar2);
          }
          else {
            local_24 = param_2 - *pdVar2;
          }
          if (param_3 - *pdVar1 <= 0.0) {
            local_2c = -(param_3 - *pdVar1);
          }
          else {
            local_2c = param_3 - *pdVar1;
          }
          local_24 = local_24 + local_2c;
          if (local_24 < *(double *)(param_1 + 0x8ed0) || local_24 == *(double *)(param_1 + 0x8ed0))
          {
            *(double *)(param_1 + 0x8ee0) = local_24 / 2.0;
            uVar3 = 1;
          }
          else {
            uVar3 = 0;
          }
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CDataTen[5] */
/* 0042e040  FUN_0042e040  135 bytes, 13 callers */

undefined4 FUN_0042e040(void)

{
  uint uVar1;
  int iVar2;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092182f;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_004121b0(0x80);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0041fb60(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_0042faa0(local_18);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CDataTen[2] */
/* 0042f340  FUN_0042f340  437 bytes, 0 callers */

void FUN_0042f340(CArchive *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined8 uVar3;
  
  iVar1 = FUN_0042ddc0();
  if (((iVar1 != 0) && (*(undefined1 *)(in_ECX + 0x28) = 1, 0xfb < DAT_00a0b3e8)) &&
     (*(int *)(in_ECX + 0x6c) != 0)) {
    *(undefined1 *)(in_ECX + 0x28) = 100;
  }
  FUN_0042e690();
  iVar2 = FUN_0042ddc0();
  iVar1 = DAT_00a0b414;
  if (iVar2 == 0) {
    FUN_00420650(in_ECX + 8);
    FUN_00420650();
    if (0x15 < iVar1) {
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x68));
    }
    *(undefined4 *)(in_ECX + 0x6c) = 0;
    if (iVar1 == 0xfc) {
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x6c));
      FUN_00420650();
      FUN_00420650();
    }
    if ((299 < iVar1) && (*(char *)(in_ECX + 0x28) == 'd')) {
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x6c));
      FUN_00420650();
      FUN_00420650();
    }
  }
  else {
    uVar3 = *(undefined8 *)(in_ECX + 0x10);
    FUN_00420820(*(undefined8 *)(in_ECX + 8));
    FUN_00420820(uVar3);
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x68));
    if ((0xfb < DAT_00a0b3e8) && (*(char *)(in_ECX + 0x28) == 'd')) {
      CArchive::operator<<(param_1,*(long *)(in_ECX + 0x6c));
      FUN_00420820(*(undefined8 *)(in_ECX + 0x70));
      FUN_00420820(*(undefined8 *)(in_ECX + 0x78));
    }
  }
  return;
}




/* vtable slots: CDataTen[6] */
/* 0042faa0  FUN_0042faa0  151 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042faa0(int param_1)

{
  int in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0042f720(param_1);
  FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
               *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(in_ECX + 0x68);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(in_ECX + 0x6c);
  *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(in_ECX + 0x70);
  *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(in_ECX + 0x78);
  return;
}




/* vtable slots: CDataTen[4] */
/* 00431ae0  FUN_00431ae0  1094 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00431ae0(int param_1)

{
  int *in_ECX;
  float10 fVar1;
  undefined1 auStack_274 [84];
  undefined4 uStack_220;
  uint uStack_21c;
  uint uStack_218;
  undefined8 uStack_214;
  uint uStack_20c;
  double local_208;
  double local_200;
  undefined1 *local_1f8;
  undefined4 local_1f4;
  int local_1f0;
  double local_1ec;
  int local_1e4;
  int *local_1e0;
  int local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  int local_1a0;
  undefined8 local_19c;
  undefined4 local_194;
  char local_18c [328];
  int local_44;
  undefined4 local_40;
  double local_3c;
  double local_34;
  int local_2c;
  double local_24;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009218b0;
  local_10 = ExceptionList;
  uStack_20c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1e4 = 0;
  local_1e0 = in_ECX;
  local_14 = uStack_20c;
  if (in_ECX[0x1b] < 1) {
    if (in_ECX[0x1b] == 0) {
      local_1f0 = 3;
    }
    else {
      local_1f0 = -in_ECX[0x1b];
    }
    local_2c = local_1f0;
    uStack_214._4_4_ = (char *)(uint)*(ushort *)((int)in_ECX + 0x2a);
    uStack_214._0_4_ = (char *)(uint)*(byte *)(in_ECX + 10);
    uStack_218 = (uint)*(byte *)((int)in_ECX + 0x2e);
    uStack_21c = (uint)*(byte *)((int)in_ECX + 0x2f);
    uStack_220 = 0x431e2c;
    local_44 = FUN_0042afb0();
    uStack_214._4_4_ = (char *)(uint)*(ushort *)((int)local_1e0 + 0x2a);
    uStack_214._0_4_ = (char *)0x431e42;
    local_40 = FUN_005db650();
    uStack_214._4_4_ = (char *)0x431e58;
    uStack_214._4_4_ = (char *)(**(code **)(*local_1e0 + 0x28))();
    uStack_218 = (uint)*(undefined8 *)(local_1e0 + 2);
    uStack_214._0_4_ = (char *)((ulonglong)*(undefined8 *)(local_1e0 + 2) >> 0x20);
    uStack_21c = 0x431e74;
    fVar1 = (float10)FUN_005ea230();
    local_3c = (double)fVar1;
    uStack_214._4_4_ = (char *)0x431e8a;
    uStack_214._4_4_ = (char *)(**(code **)(*local_1e0 + 0x28))();
    uStack_218 = (uint)*(undefined8 *)(local_1e0 + 4);
    uStack_214._0_4_ = (char *)((ulonglong)*(undefined8 *)(local_1e0 + 4) >> 0x20);
    uStack_21c = 0x431ea6;
    fVar1 = (float10)FUN_005ea290();
    local_34 = (double)fVar1;
    uStack_214._0_4_ = (char *)*(undefined8 *)(local_1e0 + 0x1c);
    uStack_214._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_1e0 + 0x1c) >> 0x20);
    uStack_218 = 0x431ec4;
    fVar1 = (float10)FUN_005ea2f0();
    local_24 = (double)fVar1;
    local_1c = *(undefined8 *)(local_1e0 + 0x1e);
    if (local_44 != -999) {
      uStack_214._4_4_ = (char *)&local_44;
      uStack_214._0_4_ = "POINT_MARKER";
      uStack_218 = 0x431ef4;
      local_1e4 = (**(code **)(param_1 + 0x4c158))();
    }
    if (local_1e4 < 0) {
      uStack_214._4_4_ = (char *)0x431f0b;
      FUN_005e6520();
    }
  }
  else {
    uStack_214._4_4_ = (char *)0x431b36;
    ATL::_ATL_WIN_MODULE70::_ATL_WIN_MODULE70((_ATL_WIN_MODULE70 *)&local_1dc);
    local_8 = 0;
    uStack_214._4_4_ = (char *)(uint)*(ushort *)((int)local_1e0 + 0x2a);
    uStack_214._0_4_ = (char *)(uint)*(byte *)(local_1e0 + 10);
    uStack_218 = (uint)*(byte *)((int)local_1e0 + 0x2e);
    uStack_21c = (uint)*(byte *)((int)local_1e0 + 0x2f);
    uStack_220 = 0x431b71;
    local_1dc = FUN_0042afb0();
    uStack_214._4_4_ = (char *)(uint)*(ushort *)((int)local_1e0 + 0x2a);
    uStack_214._0_4_ = (char *)0x431b8a;
    local_1d8 = FUN_005db650();
    local_1d4 = 1;
    local_1f8 = auStack_274;
    FUN_0041f0e0(local_1e0);
    local_1f4 = FUN_005dbfa0();
    local_1cc = 2;
    uStack_214._4_4_ = (char *)0x431be8;
    local_1d0 = local_1f4;
    uStack_214._4_4_ = (char *)(**(code **)(*local_1e0 + 0x28))();
    uStack_218 = (uint)*(undefined8 *)(local_1e0 + 2);
    uStack_214._0_4_ = (char *)((ulonglong)*(undefined8 *)(local_1e0 + 2) >> 0x20);
    uStack_21c = 0x431c04;
    fVar1 = (float10)FUN_005ea230();
    local_1ec = (double)fVar1;
    uStack_218 = 0x431c25;
    uStack_214 = local_1ec;
    FUN_00420c40();
    uStack_214._0_4_ = (char *)*(undefined8 *)(local_1e0 + 0x1c);
    uStack_214._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_1e0 + 0x1c) >> 0x20);
    uStack_218 = 0x431c3d;
    fVar1 = (float10)FUN_008f8eb0();
    local_200 = (double)fVar1;
    local_1ec = local_1ec - local_200 * 0.1;
    uStack_218 = 0x431c85;
    uStack_214 = local_1ec;
    FUN_00420c40();
    uStack_214._4_4_ = (char *)0x431c98;
    uStack_214._4_4_ = (char *)(**(code **)(*local_1e0 + 0x28))();
    uStack_218 = (uint)*(undefined8 *)(local_1e0 + 4);
    uStack_214._0_4_ = (char *)((ulonglong)*(undefined8 *)(local_1e0 + 4) >> 0x20);
    uStack_21c = 0x431cb4;
    fVar1 = (float10)FUN_005ea290();
    local_1ec = (double)fVar1;
    uStack_218 = 0x431cd5;
    uStack_214 = local_1ec;
    FUN_00420c40();
    uStack_214._0_4_ = (char *)*(undefined8 *)(local_1e0 + 0x1c);
    uStack_214._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_1e0 + 0x1c) >> 0x20);
    uStack_218 = 0x431ced;
    fVar1 = (float10)FUN_008f8f00();
    local_208 = (double)fVar1;
    local_1ec = local_1ec - local_208 * 0.1;
    uStack_218 = 0x431d35;
    uStack_214 = local_1ec;
    FUN_00420c40();
    local_1a0 = local_1e0[0x1b];
    local_19c = *(undefined8 *)(local_1e0 + 0x1e);
    local_194 = 0;
    uStack_214._4_4_ = "label";
    uStack_214._0_4_ = local_18c;
    uStack_218 = 0x431d72;
    FUN_0041efc0();
    if (local_1dc != -999) {
      uStack_214._4_4_ = (char *)&local_1dc;
      uStack_214._0_4_ = "LABEL";
      uStack_218 = 0x431d98;
      local_1e4 = (**(code **)(param_1 + 0x4c158))();
    }
    if (local_1e4 < 0) {
      uStack_214._4_4_ = (char *)0x431daf;
      FUN_005e6520();
    }
    local_8 = 0xffffffff;
    uStack_214._4_4_ = (char *)0x431dc1;
    FUN_0041feb0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataTen[7] */
/* 00438e70  FUN_00438e70  213 bytes, 0 callers */

undefined4 FUN_00438e70(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = FUN_0079d98a(&PTR_s_CDataTen_009fe05c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_00438910(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_004989a0(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                           *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
      if (iVar1 == 0) {
        if (*(int *)(in_ECX + 0x68) == *(int *)(param_1 + 0x68)) {
          if (*(int *)(in_ECX + 0x6c) == *(int *)(param_1 + 0x6c)) {
            if (*(double *)(in_ECX + 0x70) == *(double *)(param_1 + 0x70)) {
              if (*(double *)(in_ECX + 0x78) == *(double *)(param_1 + 0x78)) {
                uVar2 = 1;
              }
              else {
                uVar2 = 0;
              }
            }
            else {
              uVar2 = 0;
            }
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}




/* vtable slots: CDataTen[13] */
/* 0043b3c0  FUN_0043b3c0  124 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0043b3c0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  puVar1 = (undefined4 *)
           FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                        *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
  FUN_004988c0(local_28,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  return 1;
}



