/* CMemFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMemFile[1] */
/* 007b589a  FUN_007b589a  48 bytes, 0 callers */

void FUN_007b589a(byte param_1)

{
  FUN_007b583b();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CMemFile[18], CSharedFile[18] */
/* 007b58ca  FUN_007b58ca  24 bytes, 0 callers */

void FUN_007b58ca(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x50);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMemFile[22] */
/* 007b58e2  FUN_007b58e2  16 bytes, 0 callers */

void FUN_007b58e2(undefined4 param_1)

{
  FUN_00900c73(param_1);
  return;
}




/* vtable slots: CMemFile[20], CSharedFile[20] */
/* 007b58f2  FUN_007b58f2  56 bytes, 2 callers */

void FUN_007b58f2(void)

{
  code *pcVar1;
  int *in_ECX;
  
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if ((in_ECX[9] != 0) && (in_ECX[10] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 100);
    guard_check_icall(in_ECX[9]);
    (*pcVar1)();
  }
  in_ECX[9] = 0;
  return;
}




/* vtable slots: CMemFile[21], CSharedFile[21] */
/* 007b5941  FUN_007b5941  207 bytes, 0 callers */

int FUN_007b5941(int param_1,uint param_2,int *param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  
  if (param_1 == 3) {
    if (in_ECX[5] != 0) {
      return 1;
    }
  }
  else if (param_1 == 2) {
    in_ECX[6] = in_ECX[6] + param_2;
    if ((uint)in_ECX[8] < (uint)in_ECX[6]) {
      in_ECX[8] = in_ECX[6];
    }
  }
  else if ((param_3 != (int *)0x0) && (param_4 != (int *)0x0)) {
    if (param_1 == 1) {
      uVar3 = in_ECX[6] + param_2;
      if ((uVar3 < (uint)in_ECX[6]) || (uVar3 < param_2)) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      if ((uint)in_ECX[7] < uVar3) {
        pcVar1 = *(code **)(*in_ECX + 0x68);
        guard_check_icall(uVar3);
        (*pcVar1)();
      }
    }
    *param_3 = in_ECX[6] + in_ECX[9];
    iVar2 = in_ECX[6];
    if (param_1 == 1) {
      uVar3 = in_ECX[7];
      if (iVar2 + param_2 <= (uint)in_ECX[7]) {
        uVar3 = iVar2 + param_2;
      }
      iVar2 = in_ECX[9] + uVar3;
      *param_4 = iVar2;
    }
    else {
      if (param_2 == 0xffffffff) {
        param_2 = in_ECX[7] - iVar2;
      }
      uVar3 = in_ECX[8];
      if (iVar2 + param_2 <= (uint)in_ECX[8]) {
        uVar3 = iVar2 + param_2;
      }
      iVar2 = in_ECX[9];
      *param_4 = iVar2 + uVar3;
      in_ECX[6] = in_ECX[6] + ((iVar2 + uVar3) - *param_3);
      iVar2 = *param_4;
    }
    return iVar2 - *param_3;
  }
  return 0;
}




/* vtable slots: CMemFile[13], CSharedFile[13] */
/* 007b5a11  FUN_007b5a11  6 bytes, 7 callers */

undefined4 FUN_007b5a11(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x20);
}




/* vtable slots: CMemFile[3], CSharedFile[3] */
/* 007b5a17  FUN_007b5a17  6 bytes, 0 callers */

undefined4 FUN_007b5a17(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}




/* vtable slots: CMemFile[0] */
/* 007b5a1d  FUN_007b5a1d  6 bytes, 0 callers */

undefined ** FUN_007b5a1d(void)

{
  return &PTR_s_CMemFile_00981098;
}




/* vtable slots: CMemFile[26], CSharedFile[26] */
/* 007b5a23  FUN_007b5a23  94 bytes, 0 callers */

void FUN_007b5a23(uint param_1)

{
  int iVar1;
  int *in_ECX;
  uint uVar2;
  
  uVar2 = in_ECX[7];
  if (param_1 <= uVar2) {
    return;
  }
  if (in_ECX[5] != 0) {
    do {
      uVar2 = uVar2 + in_ECX[5];
    } while (uVar2 < param_1);
    iVar1 = *in_ECX;
    if (in_ECX[9] == 0) {
      guard_check_icall();
      iVar1 = (**(code **)(iVar1 + 0x58))();
    }
    else {
      guard_check_icall(in_ECX[9],uVar2);
      iVar1 = (**(code **)(iVar1 + 0x5c))();
    }
    if (iVar1 != 0) {
      in_ECX[9] = iVar1;
      in_ECX[7] = uVar2;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e73e();
}




/* vtable slots: CMemFile[24], CSharedFile[24] */
/* 007b5a88  Memcpy  30 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned char * __thiscall CHtmlStream::Memcpy(unsigned char *,unsigned char
   const *,unsigned int)
    protected: virtual unsigned char * __thiscall CMemFile::Memcpy(unsigned char *,unsigned char
   const *,unsigned long)
   
   Library: Visual Studio */

undefined4 Memcpy(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0043add0(param_1,param_3,param_2,param_3);
  return param_1;
}




/* vtable slots: CMemFile[14], CSharedFile[14] */
/* 007b5aa6  FUN_007b5aa6  93 bytes, 0 callers */

int FUN_007b5aa6(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_2 != 0) {
    if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    uVar1 = in_ECX[6];
    if (uVar1 <= (uint)in_ECX[8]) {
      if (((uint)in_ECX[8] < uVar1 + param_2) || (uVar1 + param_2 < uVar1)) {
        param_2 = in_ECX[8] - uVar1;
      }
      iVar2 = *in_ECX;
      guard_check_icall(param_1,in_ECX[9] + uVar1,param_2);
      (**(code **)(iVar2 + 0x60))();
      in_ECX[6] = in_ECX[6] + param_2;
      return param_2;
    }
  }
  return 0;
}




/* vtable slots: CMemFile[23] */
/* 007b5b04  FUN_007b5b04  20 bytes, 0 callers */

void FUN_007b5b04(undefined4 param_1,undefined4 param_2)

{
  FUN_00908899(param_1,param_2);
  return;
}




/* vtable slots: CMemFile[11], CSharedFile[11] */
/* 007b5b18  FUN_007b5b18  120 bytes, 0 callers */

uint FUN_007b5b18(uint param_1,int param_2,int param_3)

{
  code *pcVar1;
  int *in_ECX;
  uint uVar2;
  bool bVar3;
  
  uVar2 = in_ECX[6];
  if (param_3 != 0) {
    if (param_3 != 1) {
      if (param_3 != 2) {
        return uVar2;
      }
      if ((0 < param_2) || ((-1 < param_2 && (param_1 != 0)))) goto LAB_007b5b86;
      uVar2 = in_ECX[8];
    }
    bVar3 = CARRY4(uVar2,param_1);
    param_1 = uVar2 + param_1;
    param_2 = param_2 + (uint)bVar3;
  }
  if (-1 < param_2) {
    if ((uint)in_ECX[8] < param_1) {
      pcVar1 = *(code **)(*in_ECX + 0x68);
      guard_check_icall(param_1);
      (*pcVar1)();
    }
    in_ECX[6] = param_1;
    return param_1;
  }
LAB_007b5b86:
                    /* WARNING: Subroutine does not return */
  FUN_007a6c8a(9,0xffffffff,0);
}




/* vtable slots: CMemFile[12], CSharedFile[12] */
/* 007b5b91  FUN_007b5b91  85 bytes, 0 callers */

void FUN_007b5b91(uint param_1,int param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (param_2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e73e();
  }
  if ((uint)in_ECX[7] < param_1) {
    pcVar1 = *(code **)(*in_ECX + 0x68);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  if (param_1 < (uint)in_ECX[6]) {
    in_ECX[6] = param_1;
  }
  in_ECX[8] = param_1;
  return;
}




/* vtable slots: CMemFile[15], CSharedFile[15] */
/* 007b5be7  FUN_007b5be7  121 bytes, 1 callers */

void FUN_007b5be7(int param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  
  if (param_2 == 0) {
    return;
  }
  if (param_1 != 0) {
    uVar4 = in_ECX[6];
    uVar1 = uVar4 + param_2;
    if (uVar4 <= uVar1) {
      uVar5 = in_ECX[7];
      if (uVar5 < uVar1) {
        pcVar2 = *(code **)(*in_ECX + 0x68);
        guard_check_icall(uVar1);
        (*pcVar2)();
        uVar4 = in_ECX[6];
        uVar5 = in_ECX[7];
      }
      if (uVar4 + param_2 <= uVar5) {
        iVar3 = *in_ECX;
        guard_check_icall(in_ECX[9] + uVar4,param_1,param_2);
        (**(code **)(iVar3 + 0x60))();
        in_ECX[6] = in_ECX[6] + param_2;
        if ((uint)in_ECX[6] <= (uint)in_ECX[8]) {
          return;
        }
        in_ECX[8] = in_ECX[6];
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



