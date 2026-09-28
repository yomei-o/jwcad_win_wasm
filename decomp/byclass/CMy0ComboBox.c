/* CMy0ComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMy0ComboBox[1] */
/* 00589ca0  FUN_00589ca0  68 bytes, 0 callers */

undefined4 FUN_00589ca0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00589c80();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x158);
    }
  }
  return in_ECX;
}




/* vtable slots: CMy0ComboBox[10] */
/* 00589cf0  FUN_00589cf0  16 bytes, 0 callers */

void FUN_00589cf0(void)

{
  FUN_00589db0();
  return;
}




/* vtable slots: CMy0ComboBox[94] */
/* 00589d00  FUN_00589d00  176 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00589d00(int param_1)

{
  double local_84;
  int local_7c;
  int local_74;
  int local_70;
  undefined1 local_6c [100];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_7c = FUN_004b0eb0();
  local_70 = 0;
  for (local_74 = 0; local_74 < local_7c; local_74 = local_74 + 1) {
    FUN_00588bf0(local_74,local_6c);
    local_84 = 9e+20;
    FUN_00417110(local_6c,&DAT_0095590c,&local_84);
    if (local_84 < 8e+20) {
      *(double *)(param_1 + local_70 * 8) = local_84;
      local_70 = local_70 + 1;
    }
  }
  return local_70;
}




/* vtable slots: CMy0ComboBox[97], CMyComboBox[97] */
/* 00589f40  FUN_00589f40  127 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00589f40(void)

{
  int in_ECX;
  undefined1 local_44 [60];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (DAT_00a0cbd8 != 0) {
    FUN_00406bf0(DAT_00a0cbd8,1);
  }
  if (*(int *)(in_ECX + 0x128) != 0) {
    FUN_00589c10(local_44,L"%.10lg",*(undefined8 *)(in_ECX + 0x80));
    FUN_00797ece();
  }
  return;
}




/* vtable slots: CMy0ComboBox[98] */
/* 00589fc0  FUN_00589fc0  93 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00589fc0(undefined8 param_1)

{
  int *in_ECX;
  undefined1 local_44 [60];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00589c10(local_44,L"%.10lg",param_1);
  FUN_00797ece();
  (**(code **)(*in_ECX + 0x18c))();
  return;
}




/* vtable slots: CMy0ComboBox[96] */
/* 0058a020  FUN_0058a020  284 bytes, 0 callers */

void FUN_0058a020(int param_1,int param_2)

{
  uint uVar1;
  float10 fVar2;
  int local_1c;
  undefined1 local_18 [4];
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009200cd;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0cbd8 != 0) {
    FUN_00406bf0(DAT_00a0cbd8,1);
  }
  if (param_2 != 0) {
    if (0xf < param_2) {
      param_2 = 0xf;
    }
    CStringT<>(uVar1);
    local_8 = 0;
    FUN_00792c64();
    FUN_004b10f0();
    FUN_00404920();
    FUN_00797ece();
    for (local_1c = 0; local_1c < param_2; local_1c = local_1c + 1) {
      FUN_004059f0(local_18,L"%.10lg",*(undefined8 *)(param_1 + local_1c * 8));
      FUN_00404920();
      FUN_004142b0();
    }
    fVar2 = (float10)FUN_0058cc80();
    (**(code **)(*local_14 + 0x188))((double)fVar2);
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CMy0ComboBox[95], CMyComboBox[95] */
/* 0058a140  FUN_0058a140  47 bytes, 0 callers */

void FUN_0058a140(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x180))(in_ECX + 0x20,in_ECX[0x4a]);
  return;
}




/* vtable slots: CMy0ComboBox[99] */
/* 0058a170  FUN_0058a170  354 bytes, 0 callers */

void FUN_0058a170(void)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  double local_2c;
  double local_24;
  int local_1c;
  undefined1 local_18 [4];
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f23d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CStringT<>(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  fVar3 = (float10)FUN_0058cc80();
  local_24 = (double)fVar3;
  FUN_004059f0(local_18,L"%.10lg",local_24);
  uVar1 = FUN_00404920(&DAT_0095590c,&local_24);
  FUN_00417110(uVar1);
  uVar1 = FUN_00404920();
  FUN_0057e1c0(0,uVar1);
  local_1c = 1;
  do {
    iVar2 = FUN_004b0eb0();
    if (iVar2 <= local_1c) {
LAB_0058a266:
      FUN_004b1140();
      iVar2 = FUN_004b0eb0();
      if (0xf < iVar2) {
        FUN_004b0eb0();
        FUN_0054bc60();
      }
      iVar2 = (**(code **)(*local_14 + 0x178))();
      local_14[0x4a] = iVar2;
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return;
    }
    GetLBText(local_1c,local_18);
    uVar1 = FUN_00404920();
    FUN_00417110(uVar1);
    if (local_2c == local_24) {
      FUN_0054bc60();
      goto LAB_0058a266;
    }
    local_1c = local_1c + 1;
  } while( true );
}




/* vtable slots: CMy0ComboBox[67], CMyComboBox[67] */
/* 0058c3a0  FUN_0058c3a0  918 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0058c3a0(int param_1)

{
  int *piStack_260;
  undefined1 *puStack_25c;
  uint uStack_258;
  undefined1 *local_254;
  undefined4 local_250;
  undefined4 local_24c;
  int local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  int local_228;
  int local_224;
  int *local_220;
  undefined1 local_21c [4];
  undefined1 local_218 [516];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f2a0;
  local_10 = ExceptionList;
  uStack_258 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puStack_25c = (undefined1 *)param_1;
  piStack_260 = (int *)0x58c3e0;
  local_14 = uStack_258;
  local_24c = FUN_007949fb();
  if ((*(int *)(param_1 + 4) != 0x20a) && (*(int *)(param_1 + 4) != 0xce11)) {
LAB_0058c498:
    puStack_25c = (undefined1 *)0x58c4a3;
    CStringT<>();
    local_8 = 0;
    if (*(int *)(param_1 + 4) == 0x100) {
      if (DAT_00a0d864 != 0) {
        if (*(int *)(param_1 + 8) == 0x25) {
          local_22c = 1;
          local_8 = 0xffffffff;
          puStack_25c = (undefined1 *)0x58c4ec;
          FUN_00404540();
          ExceptionList = local_10;
          return local_22c;
        }
        if (*(int *)(param_1 + 8) == 0x27) {
          local_230 = 1;
          local_8 = 0xffffffff;
          puStack_25c = (undefined1 *)0x58c51c;
          FUN_00404540();
          ExceptionList = local_10;
          return local_230;
        }
        if (*(int *)(param_1 + 8) == 0x26) {
          local_234 = 1;
          local_8 = 0xffffffff;
          puStack_25c = (undefined1 *)0x58c54c;
          FUN_00404540();
          ExceptionList = local_10;
          return local_234;
        }
        if (*(int *)(param_1 + 8) == 0x28) {
          local_238 = 1;
          local_8 = 0xffffffff;
          puStack_25c = (undefined1 *)0x58c57c;
          FUN_00404540();
          ExceptionList = local_10;
          return local_238;
        }
        if (*(int *)(param_1 + 8) == 0x21) {
          local_23c = 1;
          local_8 = 0xffffffff;
          puStack_25c = (undefined1 *)0x58c5ac;
          FUN_00404540();
          ExceptionList = local_10;
          return local_23c;
        }
        if (*(int *)(param_1 + 8) == 0x22) {
          local_240 = 1;
          local_8 = 0xffffffff;
          puStack_25c = (undefined1 *)0x58c5dc;
          FUN_00404540();
          ExceptionList = local_10;
          return local_240;
        }
        if (*(int *)(param_1 + 8) == 0x24) {
          local_244 = 1;
          local_8 = 0xffffffff;
          puStack_25c = (undefined1 *)0x58c60c;
          FUN_00404540();
          ExceptionList = local_10;
          return local_244;
        }
      }
      if (*(int *)(param_1 + 8) == 0xd) {
        puStack_25c = local_21c;
        piStack_260 = (int *)0x58c636;
        FUN_00792c64();
        puStack_25c = (undefined1 *)0x58c64c;
        (**(code **)(*local_220 + 0x18c))();
        if ((local_220[0x4e] == 1) && (local_220[0x48] == 0)) {
          puStack_25c = local_218;
          local_254 = (undefined1 *)&piStack_260;
          piStack_260 = local_220;
          FUN_00403dd0(local_21c);
          local_248 = FUN_004f47b0();
          if (local_248 != 0) {
            puStack_25c = local_218;
            piStack_260 = (int *)&DAT_00955904;
            FUN_004059f0(local_21c);
            puStack_25c = (undefined1 *)0x58c6c9;
            puStack_25c = (undefined1 *)FUN_00404920();
            piStack_260 = (int *)0x58c6d5;
            FUN_00797ece();
            local_220[0x48] = 1;
          }
        }
      }
      else {
        local_220[0x48] = 0;
      }
    }
    local_250 = local_24c;
    local_8 = 0xffffffff;
    puStack_25c = (undefined1 *)0x58c715;
    FUN_00404540();
    ExceptionList = local_10;
    return local_250;
  }
  if (DAT_00a0d8a0 < 1) {
    local_224 = -DAT_00a0d8a0;
  }
  else {
    local_224 = DAT_00a0d8a0;
  }
  if (local_224 != 1) {
    if (DAT_00a0d8a0 < 1) {
      local_228 = -DAT_00a0d8a0;
    }
    else {
      local_228 = DAT_00a0d8a0;
    }
    if (local_228 != 3) goto LAB_0058c498;
  }
  ExceptionList = local_10;
  return 1;
}



