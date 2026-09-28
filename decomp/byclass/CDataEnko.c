/* CDataEnko -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataEnko[22], CDataTen[22] */
/* 0040c0b0  GetClassID  47 bytes, 58 callers */

/* Library Function - Single Match
    public: struct _GUID __thiscall CPropertySet::GetClassID(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

_GUID * __thiscall CPropertySet::GetClassID(CPropertySet *this,_GUID *__return_storage_ptr__)

{
  undefined4 uVar1;
  
  __return_storage_ptr__->Data1 = *(ulong *)(this + 8);
  uVar1 = *(undefined4 *)(this + 0xc);
  __return_storage_ptr__->Data2 = (short)uVar1;
  __return_storage_ptr__->Data3 = (short)((uint)uVar1 >> 0x10);
  *(undefined4 *)__return_storage_ptr__->Data4 = *(undefined4 *)(this + 0x10);
  *(undefined4 *)(__return_storage_ptr__->Data4 + 4) = *(undefined4 *)(this + 0x14);
  return __return_storage_ptr__;
}




/* vtable slots: CDataEnko[1] */
/* 00420a80  FUN_00420a80  68 bytes, 0 callers */

undefined4 FUN_00420a80(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041fd50();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x98);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataEnko[14] */
/* 00421040  FUN_00421040  343 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00421040(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00403cd0(local_20c,&DAT_0095aa60,param_3,*(undefined8 *)(in_ECX + 8),
               *(undefined8 *)(in_ECX + 0x10),*(undefined8 *)(in_ECX + 0x68),
               (*(double *)(in_ECX + 0x78) * 180.0) / 3.141592653589793,
               (*(double *)(in_ECX + 0x80) * 180.0) / 3.141592653589793);
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x32,local_20c,uVar1);
  FUN_00403cd0();
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x46,local_20c,uVar1);
  return;
}




/* vtable slots: CDataEnko[15] */
/* 00425190  FUN_00425190  105 bytes, 0 callers */

undefined4 FUN_00425190(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
      uVar2 = FUN_00421490(param_1,param_2,param_3);
      FUN_0042e540();
    }
    else {
      FUN_0042e540();
      uVar2 = 0;
    }
  }
  return uVar2;
}




/* vtable slots: CDataEnko[3] */
/* 00428d10  FUN_00428d10  2018 bytes, 1 callers */

void FUN_00428d10(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  int in_ECX;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double local_a0;
  double local_90;
  double local_68;
  double local_60;
  double local_50;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  if (*(double *)(in_ECX + 0x88) == 1.0) {
    if (*(int *)(in_ECX + 0x90) == 0) {
      CStringT<>(&DAT_0095aa48);
      FUN_004a7e90(0);
      FUN_0049dea0(&stack0xffffff10,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),
                   *(undefined1 *)(in_ECX + 0x28));
      FUN_004a7e90(8);
      FUN_00403dd0(param_1 + 0x1c + (uint)*(byte *)(in_ECX + 0x28) * 4);
      FUN_004a7e90(6);
      FUN_0049dcf0();
      FUN_004a7e10(0x3e);
      fVar4 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 8));
      FUN_004a77a0(10,(double)fVar4);
      fVar4 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x10));
      FUN_004a77a0(0x14,(double)fVar4);
      fVar4 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x68));
      FUN_004a77a0(0x28,(double)fVar4);
      local_10 = *(double *)(in_ECX + 0x78) + *(double *)(in_ECX + 0x70);
      local_18 = (local_10 + *(double *)(in_ECX + 0x80)) * 57.29577951308232;
      for (local_10 = local_10 * 57.29577951308232; local_10 < 0.0; local_10 = local_10 + 360.0) {
      }
      for (; dVar1 = local_10, 360.0 <= local_10; local_10 = local_10 - 360.0) {
      }
      for (; local_18 < 0.0; local_18 = local_18 + 360.0) {
      }
      for (; 360.0 <= local_18; local_18 = local_18 - 360.0) {
      }
      if (*(double *)(in_ECX + 0x80) <= 0.0 && *(double *)(in_ECX + 0x80) != 0.0) {
        local_10 = local_18;
        local_18 = dVar1;
      }
      FUN_004a77a0(0x32,local_10);
      FUN_004a77a0(0x33,local_18);
    }
    else {
      CStringT<>("CIRCLE");
      FUN_004a7e90(0);
      FUN_0049dea0(&stack0xffffff10,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),
                   *(undefined1 *)(in_ECX + 0x28));
      FUN_004a7e90(8);
      FUN_00403dd0(param_1 + 0x1c + (uint)*(byte *)(in_ECX + 0x28) * 4);
      FUN_004a7e90(6);
      FUN_0049dcf0();
      FUN_004a7e10(0x3e);
      fVar4 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 8));
      FUN_004a77a0(10,(double)fVar4);
      fVar4 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x10));
      FUN_004a77a0(0x14,(double)fVar4);
      fVar4 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x68));
      FUN_004a77a0(0x28,(double)fVar4);
    }
  }
  else {
    fVar4 = (float10)FUN_008f8eb0(*(undefined8 *)(in_ECX + 0x70));
    dVar1 = (double)fVar4;
    fVar4 = (float10)FUN_008f8f00(*(undefined8 *)(in_ECX + 0x70));
    dVar2 = (double)fVar4;
    fVar4 = (float10)FUN_004a93a0(*(undefined8 *)(in_ECX + 0x68));
    dVar3 = (double)fVar4;
    dVar8 = dVar3 * *(double *)(in_ECX + 0x88);
    local_50 = 0.17453292519943295;
    fVar4 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 8));
    fVar5 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x10));
    local_28 = *(double *)(in_ECX + 0x80);
    if (*(int *)(in_ECX + 0x90) != 0) {
      local_28 = 6.283185307179586;
    }
    if (local_28 < 0.0) {
      local_50 = -0.17453292519943295;
    }
    fVar6 = (float10)FUN_008f8eb0(*(undefined8 *)(in_ECX + 0x78));
    fVar7 = (float10)FUN_008f8f00(*(undefined8 *)(in_ECX + 0x78));
    dVar9 = (double)fVar7 * dVar8;
    local_20 = 0.0;
    local_a0 = (double)fVar6 * dVar3 * dVar2 + dVar9 * dVar1 + (double)fVar5;
    local_90 = ((double)fVar6 * dVar3 * dVar1 - dVar9 * dVar2) + (double)fVar4;
    while( true ) {
      if (local_20 <= 0.0) {
        local_60 = -local_20;
      }
      else {
        local_60 = local_20;
      }
      if (local_28 <= 0.0) {
        local_68 = -local_28;
      }
      else {
        local_68 = local_28;
      }
      if (local_68 < local_60) {
        local_20 = local_28;
      }
      fVar6 = (float10)FUN_008f8eb0(*(double *)(in_ECX + 0x78) + local_20);
      fVar7 = (float10)FUN_008f8f00(*(double *)(in_ECX + 0x78) + local_20);
      dVar9 = (double)fVar7 * dVar8;
      dVar10 = ((double)fVar6 * dVar3 * dVar1 - dVar9 * dVar2) + (double)fVar4;
      dVar9 = (double)fVar6 * dVar3 * dVar2 + dVar9 * dVar1 + (double)fVar5;
      CStringT<>(&DAT_0095a9bc);
      FUN_004a7e90(0);
      FUN_0049dea0(&stack0xffffff10,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),
                   *(undefined1 *)(in_ECX + 0x28));
      FUN_004a7e90(8);
      FUN_00403dd0(param_1 + 0x1c + (uint)*(byte *)(in_ECX + 0x28) * 4);
      FUN_004a7e90(6);
      FUN_0049dcf0();
      FUN_004a7e10(0x3e);
      FUN_004a77a0(10,local_90);
      FUN_004a77a0(0x14,local_a0);
      FUN_004a77a0(0xb,dVar10);
      FUN_004a77a0(0x15,dVar9);
      if (local_20 == local_28) break;
      local_20 = local_20 + local_50;
      local_a0 = dVar9;
      local_90 = dVar10;
    }
  }
  return;
}




/* vtable slots: CDataEnko[23], CDataTen[23] */
/* 00429ca0  FUN_00429ca0  127 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_00429ca0(undefined4 *param_1)

{
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_0041f0a0(*(undefined8 *)(in_ECX + 8),*(undefined8 *)(in_ECX + 0x10),0);
  *param_1 = local_20;
  param_1[1] = local_1c;
  param_1[2] = local_18;
  param_1[3] = local_14;
  param_1[4] = local_10;
  param_1[5] = local_c;
  return param_1;
}




/* vtable slots: CDataEnko[11], CDataTen[12] */
/* 0042a230  FUN_0042a230  47 bytes, 1 callers */

undefined4 * FUN_0042a230(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 8);
  param_1[1] = *(undefined4 *)(in_ECX + 0xc);
  param_1[2] = *(undefined4 *)(in_ECX + 0x10);
  param_1[3] = *(undefined4 *)(in_ECX + 0x14);
  return param_1;
}




/* vtable slots: CDataEnko[0] */
/* 0042b0a0  FUN_0042b0a0  16 bytes, 0 callers */

undefined ** FUN_0042b0a0(void)

{
  return &PTR_s_CDataEnko_009fe040;
}




/* vtable slots: CDataEnko[12], CDataSunpou[12] */
/* 0042b2a0  FUN_0042b2a0  423 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
FUN_0042b2a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
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
  puStack_c = &LAB_00921720;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00408a60(local_14);
  FUN_00408a60();
  (**(code **)(*in_ECX + 0x34))(&local_24,&local_34);
  FUN_00446aa0();
  local_8 = 0;
  fVar1 = (float10)FUN_0043acd0(param_2,param_3,param_4,param_5,local_24,local_20,local_1c,local_18)
  ;
  fVar2 = (float10)FUN_0043acd0(param_2,param_3,param_4,param_5,local_34,local_30,local_2c,local_28)
  ;
  if ((double)fVar2 <= (double)fVar1) {
    *param_1 = local_34;
    param_1[1] = local_30;
    param_1[2] = local_2c;
    param_1[3] = local_28;
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    *param_1 = local_24;
    param_1[1] = local_20;
    param_1[2] = local_1c;
    param_1[3] = local_18;
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return param_1;
}




/* vtable slots: CDataEnko[17] */
/* 0042b7d0  FUN_0042b7d0  2342 bytes, 2 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0042b7d0(int param_1,double param_2,double param_3)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double *pdVar5;
  undefined4 uVar6;
  int in_ECX;
  float10 fVar7;
  float10 fVar8;
  double dVar9;
  double local_64e0;
  double local_64d0;
  double local_64c8;
  double local_64c0;
  double local_64b8;
  double local_64b0;
  double local_64a8;
  double local_64a0;
  double local_6498;
  double local_6490;
  double local_6488;
  double local_6478;
  double local_6470;
  double local_6468;
  double local_6430;
  double local_6428;
  double local_6418;
  double local_6408;
  double local_6400 [3195];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009217a0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pdVar5 = (double *)(in_ECX + 8);
  local_24 = *(undefined4 *)pdVar5;
  uStack_20 = *(undefined4 *)(in_ECX + 0xc);
  pdVar1 = (double *)(in_ECX + 0x10);
  local_1c = *(undefined4 *)pdVar1;
  uStack_18 = *(undefined4 *)(in_ECX + 0x14);
  dVar2 = *(double *)(in_ECX + 0x68);
  dVar9 = *(double *)(in_ECX + 0x70);
  dVar3 = *(double *)(in_ECX + 0x78);
  local_64c8 = *(double *)(in_ECX + 0x80);
  dVar4 = *(double *)(in_ECX + 0x88);
  local_6468 = dVar2;
  if (dVar2 <= dVar2 * dVar4) {
    local_6468 = dVar2 * dVar4;
  }
  if ((((*pdVar5 + local_6468 < *(double *)(param_1 + 0x8ee8)) ||
       (*(double *)(param_1 + 0x8ef8) <= *pdVar5 - local_6468 &&
        *pdVar5 - local_6468 != *(double *)(param_1 + 0x8ef8))) ||
      (*pdVar1 + local_6468 < *(double *)(param_1 + 0x8ef0))) ||
     (*(double *)(param_1 + 0x8f00) <= *pdVar1 - local_6468 &&
      *pdVar1 - local_6468 != *(double *)(param_1 + 0x8f00))) {
    uVar6 = 0;
  }
  else {
    local_6428 = param_2 - *pdVar5;
    local_6430 = param_3 - *pdVar1;
    local_6470 = local_6428;
    if (local_6428 <= 0.0) {
      local_6470 = -local_6428;
    }
    local_6478 = local_6430;
    if (local_6430 <= 0.0) {
      local_6478 = -local_6430;
    }
    if (1e-07 <= local_6470 + local_6478) {
      local_64e0 = dVar9;
      if (dVar9 <= 0.0) {
        local_64e0 = -dVar9;
      }
      if (1e-07 < local_64e0) {
        uVar6 = (undefined4)((ulonglong)dVar9 >> 0x20);
        fVar7 = (float10)FUN_008f8eb0(SUB84(dVar9,0),uVar6,local_14,*(undefined4 *)(in_ECX + 0x90));
        fVar8 = (float10)FUN_008f8f00(SUB84(dVar9,0),uVar6);
        dVar9 = (double)fVar8 * local_6430;
        local_6430 = (double)fVar7 * local_6430 - (double)fVar8 * local_6428;
        local_6428 = (double)fVar7 * local_6428 + dVar9;
      }
      if (dVar4 - 1.0 <= 0.0) {
        local_6488 = -(dVar4 - 1.0);
      }
      else {
        local_6488 = dVar4 - 1.0;
      }
      if (1e-07 < local_6488) {
        local_6430 = local_6430 / dVar4;
        if (local_6428 <= 0.0) {
          local_6490 = -local_6428;
        }
        else {
          local_6490 = local_6428;
        }
        if ((local_6490 < dVar2) && (dVar4 < 1.0)) {
          fVar7 = (float10)FUN_008f8d10(dVar2 * dVar2 - local_6428 * local_6428);
          local_6408 = (double)fVar7;
          if (local_6430 < 0.0) {
            local_6408 = -local_6408;
          }
          local_6430 = (local_6430 - local_6408) * dVar4 + local_6408;
        }
      }
      fVar7 = (float10)FUN_008f8d10(local_6428 * local_6428 + local_6430 * local_6430);
      local_6498 = (double)fVar7 - dVar2;
      if (local_6498 <= 0.0) {
        local_6498 = -local_6498;
      }
      local_6418 = local_6498;
      local_64a0 = local_64c8;
      if (local_64c8 <= 0.0) {
        local_64a0 = -local_64c8;
      }
      if (local_64a0 < 6.283185207179586) {
        if (local_64c8 == 0.0) {
          ExceptionList = local_10;
          return 0;
        }
        fVar7 = (float10)FUN_008f8d00(SUB84(local_6430,0),(int)((ulonglong)local_6430 >> 0x20),
                                      SUB84(local_6428,0),(int)((ulonglong)local_6428 >> 0x20));
        local_6400[0] = (double)fVar7 - dVar3;
        FUN_00446aa0();
        local_8 = 0;
        FUN_0040b250(SUB84(local_64c8,0),(int)((ulonglong)local_64c8 >> 0x20),local_6400);
        if (local_6400[0] <= 0.0) {
          local_64a8 = -local_6400[0];
        }
        else {
          local_64a8 = local_6400[0];
        }
        local_64b0 = local_64c8;
        if (local_64c8 <= 0.0) {
          local_64b0 = -local_64c8;
        }
        if (local_64b0 < local_64a8) {
          if (local_6400[0] <= 0.0) {
            local_64b8 = -local_6400[0];
          }
          else {
            local_64b8 = local_6400[0];
          }
          local_6400[0] = local_64b8;
          if (6.283185307179586 - local_64b8 <= 0.0) {
            local_64c0 = -(6.283185307179586 - local_64b8);
          }
          else {
            local_64c0 = 6.283185307179586 - local_64b8;
          }
          if (local_64c8 <= 0.0) {
            local_64c8 = -local_64c8;
          }
          if (local_64c8 - local_64b8 <= 0.0) {
            local_64d0 = -(local_64c8 - local_64b8);
          }
          else {
            local_64d0 = local_64c8 - local_64b8;
          }
          if (local_64d0 <= local_64c0) {
            local_6418 = dVar2 * local_64d0 + local_6498;
          }
          else {
            local_6418 = dVar2 * local_64c0 + local_6498;
          }
        }
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      if (local_6418 < *(double *)(param_1 + 0x8ed0) || local_6418 == *(double *)(param_1 + 0x8ed0))
      {
        *(double *)(param_1 + 0x8ee0) = local_6418;
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar6;
}




/* vtable slots: CDataEnko[5] */
/* 0042de00  FUN_0042de00  135 bytes, 13 callers */

undefined4 FUN_0042de00(void)

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
  iVar2 = FUN_004121b0(0x98);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0041f5f0(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_0042f810(local_18);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CDataEnko[2] */
/* 0042e7f0  FUN_0042e7f0  569 bytes, 0 callers */

void FUN_0042e7f0(undefined4 param_1)

{
  int iVar1;
  CArchive *pCVar2;
  int in_ECX;
  long *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  double local_18;
  double local_10;
  
  FUN_0042e690(param_1);
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    plVar3 = (long *)(in_ECX + 0x90);
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    pCVar2 = (CArchive *)FUN_00420650();
    CArchive::operator>>(pCVar2,plVar3);
    if (DAT_00a08ae4 != 0) {
      DAT_00a08ae4 = DAT_00a08ae4 + 1;
      if (10 < DAT_00a08ae4) {
        DAT_00a08ae4 = 1;
      }
      *(double *)(in_ECX + 8) = *(double *)(in_ECX + 8) + (double)(&DAT_00a08af0)[DAT_00a08ae4];
      *(double *)(in_ECX + 0x10) =
           *(double *)(in_ECX + 0x10) + *(double *)(&DAT_00a08ae8 + DAT_00a08ae4 * 8);
    }
  }
  else {
    local_18 = *(double *)(in_ECX + 8);
    local_10 = *(double *)(in_ECX + 0x10);
    if (DAT_00a08ae4 != 0) {
      DAT_00a08ae4 = DAT_00a08ae4 + 1;
      if (10 < DAT_00a08ae4) {
        DAT_00a08ae4 = 1;
      }
      local_18 = local_18 - (double)(&DAT_00a08af0)[DAT_00a08ae4];
      local_10 = local_10 - *(double *)(&DAT_00a08ae8 + DAT_00a08ae4 * 8);
    }
    lVar9 = *(long *)(in_ECX + 0x90);
    uVar8 = *(undefined8 *)(in_ECX + 0x88);
    uVar7 = *(undefined8 *)(in_ECX + 0x70);
    uVar6 = *(undefined8 *)(in_ECX + 0x80);
    uVar5 = *(undefined8 *)(in_ECX + 0x78);
    uVar4 = *(undefined8 *)(in_ECX + 0x68);
    FUN_00420820(local_18);
    FUN_00420820(local_10);
    FUN_00420820(uVar4);
    FUN_00420820(uVar5);
    FUN_00420820(uVar6);
    FUN_00420820(uVar7);
    pCVar2 = (CArchive *)FUN_00420820(uVar8);
    CArchive::operator<<(pCVar2,lVar9);
  }
  return;
}




/* vtable slots: CDataEnko[6] */
/* 0042f810  FUN_0042f810  229 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042f810(int param_1)

{
  int in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0042f720(param_1);
  FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
               *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
  *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(in_ECX + 0x68);
  *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(in_ECX + 0x70);
  *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(in_ECX + 0x78);
  *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(in_ECX + 0x80);
  *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(in_ECX + 0x88);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(in_ECX + 0x90);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(in_ECX + 0x94);
  return;
}




/* vtable slots: CDataEnko[4] */
/* 00430260  FUN_00430260  2581 bytes, 2 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00430260(int param_1)

{
  int *in_ECX;
  float10 fVar1;
  undefined1 auStack_1c8 [84];
  undefined4 uStack_174;
  uint uStack_170;
  undefined8 uStack_16c;
  int *piStack_164;
  undefined1 *local_160;
  undefined1 *local_15c;
  undefined1 *local_158;
  undefined1 *local_154;
  undefined1 *local_150;
  undefined1 *local_14c;
  undefined1 *local_148;
  undefined1 *local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  double local_120;
  double local_118;
  double local_110;
  double local_108;
  int local_100;
  int *local_fc;
  int local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  double local_e8;
  double local_e0;
  double local_d8;
  double local_d0;
  uint local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  double local_60;
  double local_58;
  double local_50;
  uint local_48;
  double local_40;
  double local_38;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  double local_20;
  double local_18;
  double local_10;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_100 = 0;
  local_fc = in_ECX;
  if (*(double *)(in_ECX + 0x22) == 1.0) {
    if (in_ECX[0x24] == 0) {
      piStack_164 = (int *)(uint)*(ushort *)((int)in_ECX + 0x2a);
      uStack_16c._4_4_ = (char *)(uint)*(byte *)(in_ECX + 10);
      uStack_16c._0_4_ = (uint)*(byte *)((int)in_ECX + 0x2e);
      uStack_170 = (uint)*(byte *)((int)in_ECX + 0x2f);
      uStack_174 = 0x430462;
      local_70 = FUN_0042afb0();
      piStack_164 = (int *)(uint)*(ushort *)((int)local_fc + 0x2a);
      uStack_16c._4_4_ = (char *)0x430478;
      local_6c = FUN_005db650();
      local_14c = auStack_1c8;
      FUN_0041f0e0(local_fc);
      local_12c = FUN_005dbd80();
      local_150 = auStack_1c8;
      local_68 = local_12c;
      FUN_0041f0e0(local_fc);
      local_130 = FUN_005dbfa0();
      piStack_164 = (int *)0x4304ea;
      local_64 = local_130;
      piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
      uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 2);
      uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 2) >> 0x20);
      uStack_170 = 0x430506;
      fVar1 = (float10)FUN_005ea230();
      local_60 = (double)fVar1;
      piStack_164 = (int *)0x43051c;
      piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
      uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 4);
      uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 4) >> 0x20);
      uStack_170 = 0x430538;
      fVar1 = (float10)FUN_005ea290();
      local_58 = (double)fVar1;
      piStack_164 = (int *)0x43054e;
      piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
      uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 0x1a);
      uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 0x1a) >> 0x20);
      uStack_170 = 0x43056a;
      fVar1 = (float10)FUN_005ea1f0();
      local_50 = (double)fVar1;
      local_118 = (*(double *)(local_fc + 0x1e) + *(double *)(local_fc + 0x1c) +
                  *(double *)(local_fc + 0x20)) * 57.29577951308232;
      for (local_110 = (*(double *)(local_fc + 0x1e) + *(double *)(local_fc + 0x1c)) *
                       57.29577951308232; local_110 < 0.0; local_110 = local_110 + 360.0) {
      }
      for (; 360.0 <= local_110; local_110 = local_110 - 360.0) {
      }
      for (; local_118 < 0.0; local_118 = local_118 + 360.0) {
      }
      for (; 360.0 <= local_118; local_118 = local_118 - 360.0) {
      }
      local_48 = (uint)(*(double *)(local_fc + 0x20) <= 0.0 && *(double *)(local_fc + 0x20) != 0.0);
      local_40 = local_110;
      local_38 = local_118;
      if (local_70 != -999) {
        piStack_164 = &local_70;
        uStack_16c._4_4_ = &DAT_0095aa48;
        uStack_16c._0_4_ = 0x4306f5;
        local_100 = (**(code **)(param_1 + 0x4c158))();
      }
      if (local_100 < 0) {
        piStack_164 = (int *)0x43070c;
        FUN_005e6520();
      }
    }
    else {
      piStack_164 = (int *)(uint)*(ushort *)((int)in_ECX + 0x2a);
      uStack_16c._4_4_ = (char *)(uint)*(byte *)(in_ECX + 10);
      uStack_16c._0_4_ = (uint)*(byte *)((int)in_ECX + 0x2e);
      uStack_170 = (uint)*(byte *)((int)in_ECX + 0x2f);
      uStack_174 = 0x4302ea;
      local_30 = FUN_0042afb0();
      piStack_164 = (int *)(uint)*(ushort *)((int)local_fc + 0x2a);
      uStack_16c._4_4_ = (char *)0x430300;
      local_2c = FUN_005db650();
      local_144 = auStack_1c8;
      FUN_0041f0e0(local_fc);
      local_124 = FUN_005dbd80();
      local_148 = auStack_1c8;
      local_28 = local_124;
      FUN_0041f0e0(local_fc);
      local_128 = FUN_005dbfa0();
      piStack_164 = (int *)0x430372;
      local_24 = local_128;
      piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
      uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 2);
      uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 2) >> 0x20);
      uStack_170 = 0x43038e;
      fVar1 = (float10)FUN_005ea230();
      local_20 = (double)fVar1;
      piStack_164 = (int *)0x4303a4;
      piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
      uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 4);
      uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 4) >> 0x20);
      uStack_170 = 0x4303c0;
      fVar1 = (float10)FUN_005ea290();
      local_18 = (double)fVar1;
      piStack_164 = (int *)0x4303d6;
      piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
      uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 0x1a);
      uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 0x1a) >> 0x20);
      uStack_170 = 0x4303f2;
      fVar1 = (float10)FUN_005ea1f0();
      local_10 = (double)fVar1;
      if (local_30 != -999) {
        piStack_164 = &local_30;
        uStack_16c._4_4_ = "CIRCLE";
        uStack_16c._0_4_ = 0x430412;
        local_100 = (**(code **)(param_1 + 0x4c158))();
      }
      if (local_100 < 0) {
        piStack_164 = (int *)0x430429;
        FUN_005e6520();
      }
    }
  }
  else if (in_ECX[0x24] == 0) {
    piStack_164 = (int *)(uint)*(ushort *)((int)in_ECX + 0x2a);
    uStack_16c._4_4_ = (char *)(uint)*(byte *)(in_ECX + 10);
    uStack_16c._0_4_ = (uint)*(byte *)((int)in_ECX + 0x2e);
    uStack_170 = (uint)*(byte *)((int)in_ECX + 0x2f);
    uStack_174 = 0x430949;
    local_f8 = FUN_0042afb0();
    piStack_164 = (int *)(uint)*(ushort *)((int)local_fc + 0x2a);
    uStack_16c._4_4_ = (char *)0x430962;
    local_f4 = FUN_005db650();
    local_15c = auStack_1c8;
    FUN_0041f0e0(local_fc);
    local_13c = FUN_005dbd80();
    local_160 = auStack_1c8;
    local_f0 = local_13c;
    FUN_0041f0e0(local_fc);
    local_140 = FUN_005dbfa0();
    piStack_164 = (int *)0x4309dd;
    local_ec = local_140;
    piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
    uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 2);
    uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 2) >> 0x20);
    uStack_170 = 0x4309f9;
    fVar1 = (float10)FUN_005ea230();
    local_e8 = (double)fVar1;
    piStack_164 = (int *)0x430a12;
    piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
    uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 4);
    uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 4) >> 0x20);
    uStack_170 = 0x430a2e;
    fVar1 = (float10)FUN_005ea290();
    local_e0 = (double)fVar1;
    piStack_164 = (int *)0x430a47;
    piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
    uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 0x1a);
    uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 0x1a) >> 0x20);
    uStack_170 = 0x430a63;
    fVar1 = (float10)FUN_005ea1f0();
    local_d8 = (double)fVar1;
    piStack_164 = (int *)0x430a7c;
    piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
    uStack_16c = *(double *)(local_fc + 0x1a) * *(double *)(local_fc + 0x22);
    uStack_170 = 0x430aa6;
    fVar1 = (float10)FUN_005ea1f0();
    local_d0 = (double)fVar1;
    uStack_16c._4_4_ = (char *)*(undefined8 *)(local_fc + 0x1c);
    piStack_164 = (int *)((ulonglong)*(undefined8 *)(local_fc + 0x1c) >> 0x20);
    uStack_16c._0_4_ = 0x430ac7;
    fVar1 = (float10)FUN_005ea2f0();
    local_c0 = (double)fVar1;
    local_120 = (*(double *)(local_fc + 0x1e) + *(double *)(local_fc + 0x20)) * 57.29577951308232;
    for (local_108 = *(double *)(local_fc + 0x1e) * 57.29577951308232; local_108 < 0.0;
        local_108 = local_108 + 360.0) {
    }
    for (; 360.0 <= local_108; local_108 = local_108 - 360.0) {
    }
    for (; local_120 < 0.0; local_120 = local_120 + 360.0) {
    }
    for (; 360.0 <= local_120; local_120 = local_120 - 360.0) {
    }
    local_c8 = (uint)(*(double *)(local_fc + 0x20) <= 0.0 && *(double *)(local_fc + 0x20) != 0.0);
    local_b8 = local_108;
    local_b0 = local_120;
    if (local_f8 != -999) {
      piStack_164 = &local_f8;
      uStack_16c._4_4_ = "ELLIPSE_ARC";
      uStack_16c._0_4_ = 0x430c4e;
      local_100 = (**(code **)(param_1 + 0x4c158))();
    }
    if (local_100 < 0) {
      piStack_164 = (int *)0x430c65;
      FUN_005e6520();
    }
  }
  else {
    piStack_164 = (int *)(uint)*(ushort *)((int)in_ECX + 0x2a);
    uStack_16c._4_4_ = (char *)(uint)*(byte *)(in_ECX + 10);
    uStack_16c._0_4_ = (uint)*(byte *)((int)in_ECX + 0x2e);
    uStack_170 = (uint)*(byte *)((int)in_ECX + 0x2f);
    uStack_174 = 0x430758;
    local_a8 = FUN_0042afb0();
    piStack_164 = (int *)(uint)*(ushort *)((int)local_fc + 0x2a);
    uStack_16c._4_4_ = (char *)0x430771;
    local_a4 = FUN_005db650();
    local_154 = auStack_1c8;
    FUN_0041f0e0(local_fc);
    local_134 = FUN_005dbd80();
    local_158 = auStack_1c8;
    local_a0 = local_134;
    FUN_0041f0e0(local_fc);
    local_138 = FUN_005dbfa0();
    piStack_164 = (int *)0x4307ec;
    local_9c = local_138;
    piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
    uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 2);
    uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 2) >> 0x20);
    uStack_170 = 0x430808;
    fVar1 = (float10)FUN_005ea230();
    local_98 = (double)fVar1;
    piStack_164 = (int *)0x430821;
    piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
    uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 4);
    uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 4) >> 0x20);
    uStack_170 = 0x43083d;
    fVar1 = (float10)FUN_005ea290();
    local_90 = (double)fVar1;
    piStack_164 = (int *)0x430856;
    piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
    uStack_16c._0_4_ = (uint)*(undefined8 *)(local_fc + 0x1a);
    uStack_16c._4_4_ = (char *)((ulonglong)*(undefined8 *)(local_fc + 0x1a) >> 0x20);
    uStack_170 = 0x430872;
    fVar1 = (float10)FUN_005ea1f0();
    local_88 = (double)fVar1;
    piStack_164 = (int *)0x43088b;
    piStack_164 = (int *)(**(code **)(*local_fc + 0x28))();
    uStack_16c = *(double *)(local_fc + 0x1a) * *(double *)(local_fc + 0x22);
    uStack_170 = 0x4308b5;
    fVar1 = (float10)FUN_005ea1f0();
    local_80 = (double)fVar1;
    uStack_16c._4_4_ = (char *)*(undefined8 *)(local_fc + 0x1c);
    piStack_164 = (int *)((ulonglong)*(undefined8 *)(local_fc + 0x1c) >> 0x20);
    uStack_16c._0_4_ = 0x4308d3;
    fVar1 = (float10)FUN_005ea2f0();
    local_78 = (double)fVar1;
    if (local_a8 != -999) {
      piStack_164 = &local_a8;
      uStack_16c._4_4_ = "ELLIPSE";
      uStack_16c._0_4_ = 0x4308f9;
      local_100 = (**(code **)(param_1 + 0x4c158))();
    }
    if (local_100 < 0) {
      piStack_164 = (int *)0x430910;
      FUN_005e6520();
    }
  }
  return;
}




/* vtable slots: CDataEnko[7] */
/* 00438980  FUN_00438980  297 bytes, 0 callers */

undefined4 FUN_00438980(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_00438910(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_00498960(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                           *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else if (*(double *)(in_ECX + 0x68) == *(double *)(param_1 + 0x68)) {
        if (*(double *)(in_ECX + 0x70) == *(double *)(param_1 + 0x70)) {
          if (*(double *)(in_ECX + 0x78) == *(double *)(param_1 + 0x78)) {
            if (*(double *)(in_ECX + 0x80) == *(double *)(param_1 + 0x80)) {
              if (*(double *)(in_ECX + 0x88) == *(double *)(param_1 + 0x88)) {
                if (*(int *)(in_ECX + 0x90) == *(int *)(param_1 + 0x90)) {
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
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}




/* vtable slots: CDataEnko[13] */
/* 0043af40  FUN_0043af40  1008 bytes, 10 callers */

undefined4 FUN_0043af40(double *param_1,double *param_2)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  undefined4 uVar5;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  
  fVar2 = (float10)FUN_0040c160();
  fVar3 = (float10)FUN_0040c1a0();
  fVar3 = (float10)FUN_008f8eb0((double)fVar3);
  *param_1 = (double)fVar2 * (double)fVar3;
  fVar2 = (float10)FUN_0040c160();
  fVar3 = (float10)FUN_0040c1a0();
  fVar3 = (float10)FUN_008f8f00((double)fVar3);
  fVar4 = (float10)FUN_0040c180();
  param_1[1] = (double)fVar2 * (double)fVar3 * (double)fVar4;
  fVar2 = (float10)FUN_0040c100();
  local_28 = (double)fVar2;
  fVar2 = (float10)FUN_0040c160();
  fVar3 = (float10)FUN_0040c1a0();
  fVar3 = (float10)FUN_008f8eb0((double)fVar3 + local_28);
  *param_2 = (double)fVar2 * (double)fVar3;
  fVar2 = (float10)FUN_0040c160();
  fVar3 = (float10)FUN_0040c1a0();
  fVar3 = (float10)FUN_008f8f00((double)fVar3 + local_28);
  fVar4 = (float10)FUN_0040c180();
  param_2[1] = (double)fVar2 * (double)fVar3 * (double)fVar4;
  uVar5 = 0;
  fVar2 = (float10)FUN_0040c1e0(0);
  FUN_005f89c0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
               *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14),
               ((double)fVar2 * 180.0) / 3.141592653589793,uVar5);
  FUN_005f8ce0(param_1);
  FUN_005f8ce0(param_2);
  local_18 = local_28;
  if (local_28 <= 0.0) {
    local_18 = -local_28;
  }
  if (local_18 - 6.283185307179586 <= 0.0) {
    if (local_28 <= 0.0) {
      local_28 = -local_28;
    }
    local_30 = -(local_28 - 6.283185307179586);
  }
  else {
    local_20 = local_28;
    if (local_28 <= 0.0) {
      local_20 = -local_28;
    }
    local_30 = local_20 - 6.283185307179586;
  }
  if ((local_30 <= 1e-07) || (iVar1 = FUN_0040c200(), iVar1 == 1)) {
    uVar5 = 0;
  }
  else {
    if (*param_2 - *param_1 <= 0.0) {
      local_38 = -(*param_2 - *param_1);
    }
    else {
      local_38 = *param_2 - *param_1;
    }
    if (local_38 <= 1e-07) {
      if (param_2[1] - param_1[1] <= 0.0) {
        local_40 = -(param_2[1] - param_1[1]);
      }
      else {
        local_40 = param_2[1] - param_1[1];
      }
      if (local_40 <= 1e-07) {
        return 1;
      }
    }
    uVar5 = 2;
  }
  return uVar5;
}



