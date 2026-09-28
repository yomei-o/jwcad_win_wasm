/* CDataSen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataSen[1] */
/* 00420ad0  FUN_00420ad0  65 bytes, 0 callers */

undefined4 FUN_00420ad0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041fd70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x68);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataSen[14] */
/* 004211a0  FUN_004211a0  181 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004211a0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_20c [516];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00403cd0(local_20c,L"Line  %d (%g,%g)-(%g,%g)                             ",param_3,
               *(undefined8 *)(in_ECX + 8),*(undefined8 *)(in_ECX + 0x10),
               *(undefined8 *)(in_ECX + 0x18),*(undefined8 *)(in_ECX + 0x20));
  uVar1 = FUN_008f899d();
  (**(code **)(*param_1 + 0x5c))(0x32,0x32,local_20c,uVar1);
  return;
}




/* vtable slots: CDataSen[15] */
/* 00425200  FUN_00425200  105 bytes, 2 callers */

undefined4 FUN_00425200(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
      uVar2 = FUN_00423750(param_1,param_2,param_3);
      FUN_0042e540();
    }
    else {
      FUN_0042e540();
      uVar2 = 0;
    }
  }
  return uVar2;
}




/* vtable slots: CDataSen[3] */
/* 00429500  FUN_00429500  326 bytes, 0 callers */

void FUN_00429500(int param_1)

{
  int in_ECX;
  float10 fVar1;
  
  CStringT<>(&DAT_0095a9bc);
  FUN_004a7e90(0);
  FUN_0049dea0(&stack0xffffffe8,*(undefined1 *)(in_ECX + 0x2f),*(undefined1 *)(in_ECX + 0x2e),
               *(undefined1 *)(in_ECX + 0x28));
  FUN_004a7e90(8);
  FUN_00403dd0(param_1 + 0x1c + (uint)*(byte *)(in_ECX + 0x28) * 4);
  FUN_004a7e90(6);
  FUN_0049dcf0();
  FUN_004a7e10(0x3e);
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 8));
  FUN_004a77a0(10,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x10));
  FUN_004a77a0(0x14,(double)fVar1);
  fVar1 = (float10)FUN_004a93e0(*(undefined8 *)(in_ECX + 0x18));
  FUN_004a77a0(0xb,(double)fVar1);
  fVar1 = (float10)FUN_004a9450(*(undefined8 *)(in_ECX + 0x20));
  FUN_004a77a0(0x15,(double)fVar1);
  return;
}




/* vtable slots: CDataSen[22] */
/* 00429e10  FUN_00429e10  28 bytes, 1 callers */

undefined4 FUN_00429e10(undefined4 param_1)

{
  FUN_00429d40(param_1);
  return param_1;
}




/* vtable slots: CDataSen[0] */
/* 0042b0b0  FUN_0042b0b0  16 bytes, 0 callers */

undefined ** FUN_0042b0b0(void)

{
  return &PTR_s_CDataSen_009fe024;
}




/* vtable slots: CDataSen[17] */
/* 0042c100  FUN_0042c100  1313 bytes, 3 callers */

undefined4 FUN_0042c100(int param_1,double param_2,double param_3)

{
  undefined4 uVar1;
  int in_ECX;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if ((*(double *)(param_1 + 0x8ee8) < *(double *)(in_ECX + 8) ||
       *(double *)(param_1 + 0x8ee8) == *(double *)(in_ECX + 8)) ||
     (*(double *)(param_1 + 0x8ee8) < *(double *)(in_ECX + 0x18) ||
      *(double *)(param_1 + 0x8ee8) == *(double *)(in_ECX + 0x18))) {
    if ((*(double *)(in_ECX + 8) < *(double *)(param_1 + 0x8ef8) ||
         *(double *)(in_ECX + 8) == *(double *)(param_1 + 0x8ef8)) ||
       (*(double *)(in_ECX + 0x18) < *(double *)(param_1 + 0x8ef8) ||
        *(double *)(in_ECX + 0x18) == *(double *)(param_1 + 0x8ef8))) {
      if ((*(double *)(param_1 + 0x8ef0) < *(double *)(in_ECX + 0x10) ||
           *(double *)(param_1 + 0x8ef0) == *(double *)(in_ECX + 0x10)) ||
         (*(double *)(param_1 + 0x8ef0) < *(double *)(in_ECX + 0x20) ||
          *(double *)(param_1 + 0x8ef0) == *(double *)(in_ECX + 0x20))) {
        if ((*(double *)(in_ECX + 0x10) < *(double *)(param_1 + 0x8f00) ||
             *(double *)(in_ECX + 0x10) == *(double *)(param_1 + 0x8f00)) ||
           (*(double *)(in_ECX + 0x20) < *(double *)(param_1 + 0x8f00) ||
            *(double *)(in_ECX + 0x20) == *(double *)(param_1 + 0x8f00))) {
          local_60 = *(double *)(in_ECX + 0x18) - *(double *)(in_ECX + 8);
          local_68 = *(double *)(in_ECX + 0x20) - *(double *)(in_ECX + 0x10);
          local_38 = local_60;
          if (local_60 <= 0.0) {
            local_38 = -local_60;
          }
          local_40 = local_68;
          if (local_68 <= 0.0) {
            local_40 = -local_68;
          }
          if (local_38 <= local_40) {
            if (local_68 == 0.0) {
              if (param_2 - *(double *)(in_ECX + 8) <= 0.0) {
                local_48 = -(param_2 - *(double *)(in_ECX + 8));
              }
              else {
                local_48 = param_2 - *(double *)(in_ECX + 8);
              }
              if (param_3 - *(double *)(in_ECX + 0x10) <= 0.0) {
                local_50 = -(param_3 - *(double *)(in_ECX + 0x10));
              }
              else {
                local_50 = param_3 - *(double *)(in_ECX + 0x10);
              }
              local_10 = local_48 + local_50;
            }
            else {
              local_10 = param_2 - (((param_3 - *(double *)(in_ECX + 0x10)) * local_60) / local_68 +
                                   *(double *)(in_ECX + 8));
            }
          }
          else {
            local_10 = param_3 - (((param_2 - *(double *)(in_ECX + 8)) * local_68) / local_60 +
                                 *(double *)(in_ECX + 0x10));
          }
          if (local_10 <= 0.0) {
            local_58 = -local_10;
          }
          else {
            local_58 = local_10;
          }
          local_10 = local_58;
          if (local_60 <= 0.0) {
            local_60 = -local_60;
          }
          if (local_68 <= 0.0) {
            local_68 = -local_68;
          }
          if (local_60 <= local_68) {
            local_18 = *(double *)(in_ECX + 0x10);
            local_20 = *(double *)(in_ECX + 0x20);
            if (local_20 < local_18) {
              local_20 = *(double *)(in_ECX + 0x10);
              local_18 = *(double *)(in_ECX + 0x20);
            }
            if (param_3 < local_18) {
              if (param_3 - local_18 <= 0.0) {
                local_80 = -(param_3 - local_18);
              }
              else {
                local_80 = param_3 - local_18;
              }
              local_10 = local_58 + local_80;
            }
            if (local_20 < param_3) {
              if (param_3 - local_20 <= 0.0) {
                local_88 = -(param_3 - local_20);
              }
              else {
                local_88 = param_3 - local_20;
              }
              local_10 = local_10 + local_88;
            }
          }
          else {
            local_18 = *(double *)(in_ECX + 8);
            local_20 = *(double *)(in_ECX + 0x18);
            if (local_20 < local_18) {
              local_20 = *(double *)(in_ECX + 8);
              local_18 = *(double *)(in_ECX + 0x18);
            }
            if (param_2 < local_18) {
              if (param_2 - local_18 <= 0.0) {
                local_70 = -(param_2 - local_18);
              }
              else {
                local_70 = param_2 - local_18;
              }
              local_10 = local_58 + local_70;
            }
            if (local_20 < param_2) {
              if (param_2 - local_20 <= 0.0) {
                local_78 = -(param_2 - local_20);
              }
              else {
                local_78 = param_2 - local_20;
              }
              local_10 = local_10 + local_78;
            }
          }
          if (local_10 < *(double *)(param_1 + 0x8ed0) || local_10 == *(double *)(param_1 + 0x8ed0))
          {
            *(double *)(param_1 + 0x8ee0) = local_10;
            uVar1 = 1;
          }
          else {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CDataSen[5] */
/* 0042de90  FUN_0042de90  132 bytes, 17 callers */

undefined4 FUN_0042de90(void)

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
  iVar2 = FUN_004121b0(0x68);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_0041f760(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_00420110(in_ECX);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CDataSen[2] */
/* 0042ea30  FUN_0042ea30  446 bytes, 0 callers */

void FUN_0042ea30(void)

{
  int iVar1;
  int in_ECX;
  undefined8 uVar2;
  undefined8 uVar3;
  double local_1c;
  double local_14;
  
  FUN_0042e690();
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    *(byte *)(in_ECX + 0x28) = *(byte *)(in_ECX + 0x28) % 100;
    FUN_007a5922();
    FUN_00420650(in_ECX + 8);
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    if (DAT_00a08ae4 != 0) {
      DAT_00a08ae4 = DAT_00a08ae4 + 1;
      if (10 < DAT_00a08ae4) {
        DAT_00a08ae4 = 1;
      }
      *(double *)(in_ECX + 8) =
           *(double *)(in_ECX + 8) - *(double *)(&DAT_00a08ae8 + DAT_00a08ae4 * 8);
      *(double *)(in_ECX + 0x10) =
           *(double *)(in_ECX + 0x10) - (double)(&DAT_00a08af0)[DAT_00a08ae4];
    }
  }
  else {
    local_1c = *(double *)(in_ECX + 8);
    local_14 = *(double *)(in_ECX + 0x10);
    if (DAT_00a08ae4 != 0) {
      DAT_00a08ae4 = DAT_00a08ae4 + 1;
      if (10 < DAT_00a08ae4) {
        DAT_00a08ae4 = 1;
      }
      local_1c = local_1c + *(double *)(&DAT_00a08ae8 + DAT_00a08ae4 * 8);
      local_14 = local_14 + (double)(&DAT_00a08af0)[DAT_00a08ae4];
    }
    uVar3 = *(undefined8 *)(in_ECX + 0x20);
    uVar2 = *(undefined8 *)(in_ECX + 0x18);
    FUN_00420820(local_1c);
    FUN_00420820(local_14);
    FUN_00420820(uVar2);
    FUN_00420820(uVar3);
  }
  return;
}




/* vtable slots: CDataSen[6] */
/* 0042f900  FUN_0042f900  143 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042f900(undefined4 param_1)

{
  int in_ECX;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0042f720(param_1);
  FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
               *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
  FUN_004988c0(local_28,*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
               *(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24));
  return;
}




/* vtable slots: CDataSen[4] */
/* 00430c80  FUN_00430c80  382 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00430c80(int param_1)

{
  int *in_ECX;
  float10 fVar1;
  undefined1 auStack_b8 [84];
  undefined4 uStack_64;
  uint uStack_60;
  undefined8 uStack_5c;
  int *piStack_54;
  undefined1 *local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int *local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_40 = 0;
  piStack_54 = (int *)(uint)*(ushort *)((int)in_ECX + 0x2a);
  uStack_5c = (ulonglong)CONCAT14((char)in_ECX[10],(uint)*(byte *)((int)in_ECX + 0x2e));
  uStack_60 = (uint)*(byte *)((int)in_ECX + 0x2f);
  uStack_64 = 0x430cc2;
  local_3c = in_ECX;
  local_38 = FUN_0042afb0();
  piStack_54 = (int *)(uint)*(ushort *)((int)local_3c + 0x2a);
  uStack_5c = CONCAT44(0x430cd5,(undefined4)uStack_5c);
  local_34 = FUN_005db650();
  local_4c = auStack_b8;
  FUN_0041f0e0(local_3c);
  local_44 = FUN_005dbd80();
  local_50 = auStack_b8;
  local_30 = local_44;
  FUN_0041f0e0(local_3c);
  local_48 = FUN_005dbfa0();
  piStack_54 = (int *)0x430d29;
  local_2c = local_48;
  piStack_54 = (int *)(**(code **)(*local_3c + 0x28))();
  uStack_5c = *(ulonglong *)(local_3c + 2);
  uStack_60 = 0x430d42;
  fVar1 = (float10)FUN_005ea230();
  local_28 = (double)fVar1;
  piStack_54 = (int *)0x430d52;
  piStack_54 = (int *)(**(code **)(*local_3c + 0x28))();
  uStack_5c = *(ulonglong *)(local_3c + 4);
  uStack_60 = 0x430d6b;
  fVar1 = (float10)FUN_005ea290();
  local_20 = (double)fVar1;
  piStack_54 = (int *)0x430d7b;
  piStack_54 = (int *)(**(code **)(*local_3c + 0x28))();
  uStack_5c = *(ulonglong *)(local_3c + 6);
  uStack_60 = 0x430d94;
  fVar1 = (float10)FUN_005ea230();
  local_18 = (double)fVar1;
  piStack_54 = (int *)0x430da4;
  piStack_54 = (int *)(**(code **)(*local_3c + 0x28))();
  uStack_5c = *(ulonglong *)(local_3c + 8);
  uStack_60 = 0x430dbd;
  fVar1 = (float10)FUN_005ea290();
  local_10 = (double)fVar1;
  if (local_38 != -999) {
    piStack_54 = &local_38;
    uStack_5c = 0x95a9bc00430ddd;
    local_40 = (**(code **)(param_1 + 0x4c158))();
  }
  if (local_40 < 0) {
    piStack_54 = (int *)0x430dee;
    FUN_005e6520();
  }
  return;
}




/* vtable slots: CDataSen[7] */
/* 00438ab0  FUN_00438ab0  174 bytes, 0 callers */

undefined4 FUN_00438ab0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0079d98a(&PTR_s_CDataSen_009fe024);
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
      else {
        iVar1 = FUN_00498960(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
                             *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24));
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}



