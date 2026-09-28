/* COleStreamFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleStreamFile[1] */
/* 007c6c26  FUN_007c6c26  48 bytes, 0 callers */

void FUN_007c6c26(byte param_1)

{
  FUN_007c6ad9();
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




/* vtable slots: COleStreamFile[18] */
/* 007c6c56  FUN_007c6c56  47 bytes, 0 callers */

void FUN_007c6c56(void)

{
  int *piVar1;
  code *pcVar2;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x14);
  if (piVar1 != (int *)0x0) {
    pcVar2 = *(code **)(*piVar1 + 0x24);
    guard_check_icall(piVar1);
    (*pcVar2)();
    FUN_007c0ecc((int *)(in_ECX + 0x14));
  }
  Empty();
  return;
}




/* vtable slots: COleStreamFile[20] */
/* 007c6ca0  FUN_007c6ca0  47 bytes, 1 callers */

void FUN_007c6ca0(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX[5] != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x4c);
    guard_check_icall();
    (*pcVar1)();
    FUN_007c0ecc(in_ECX + 5);
  }
  Empty();
  return;
}




/* vtable slots: COleStreamFile[10] */
/* 007c6d0a  FUN_007c6d0a  97 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007c6d0a(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x7c6d16;
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x34);
  guard_check_icall(*(int **)(in_ECX + 0x14),local_18);
  iVar2 = (*pcVar1)();
  if (iVar2 < 0) {
    FUN_007c7046(iVar2);
  }
  iVar3 = 0;
  local_8 = 0;
  iVar2 = FUN_0078e624(0x1c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (iVar2 != 0) {
    iVar3 = FUN_007c69d9(local_18[0]);
  }
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(in_ECX + 8);
  return iVar3;
}




/* vtable slots: COleStreamFile[19] */
/* 007c6d88  FUN_007c6d88  34 bytes, 0 callers */

void FUN_007c6d88(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x20);
  guard_check_icall(*(int **)(in_ECX + 0x14),0);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_007c7046(iVar2);
  }
  return;
}




/* vtable slots: COleStreamFile[13] */
/* 007c6daa  FUN_007c6daa  71 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_007c6daa(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_50 [8];
  undefined8 local_48;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x30);
  guard_check_icall(*(int **)(in_ECX + 0x14),local_50,1);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_007c7046(iVar2);
  }
  return local_48;
}




/* vtable slots: COleStreamFile[3] */
/* 007c6df1  FUN_007c6df1  54 bytes, 0 callers */

undefined8 FUN_007c6df1(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int local_c;
  int local_8;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x14);
  local_c = in_ECX;
  local_8 = in_ECX;
  guard_check_icall(*(int **)(in_ECX + 0x14),0,0,1,&local_c);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_007c7046(iVar2);
  }
  return CONCAT44(local_8,local_c);
}




/* vtable slots: COleStreamFile[0] */
/* 007c6e27  FUN_007c6e27  6 bytes, 0 callers */

undefined ** FUN_007c6e27(void)

{
  return &PTR_s_COleStreamFile_009851b4;
}




/* vtable slots: COleStreamFile[22] */
/* 007c6e2d  FUN_007c6e2d  28 bytes, 0 callers */

void FUN_007c6e2d(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004054a0(*(int *)(in_ECX + 0x18) + -0x10);
  *param_1 = iVar1 + 0x10;
  return;
}




/* vtable slots: COleStreamFile[16] */
/* 007c6e49  FUN_007c6e49  52 bytes, 0 callers */

void FUN_007c6e49(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x28);
  guard_check_icall(*(int **)(in_ECX + 0x14),param_1,param_2,param_3,param_4,2);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_007c7046(iVar2);
  }
  return;
}




/* vtable slots: COleStreamFile[14] */
/* 007c6e7d  Read  39 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned int __thiscall COleStreamFile::Read(void *,unsigned int)
   
   Library: Visual Studio 2012 Release */

uint __thiscall COleStreamFile::Read(COleStreamFile *this,void *param_1,uint param_2)

{
  int iVar1;
  COleStreamFile *local_8;
  
  local_8 = this;
  iVar1 = FUN_007c7000(*(undefined4 *)(this + 0x14),param_1,param_2,&local_8);
  if (iVar1 != 0) {
    FUN_007c7046(iVar1);
  }
  return (uint)local_8;
}




/* vtable slots: COleStreamFile[11] */
/* 007c6ea4  FUN_007c6ea4  59 bytes, 0 callers */

undefined8 FUN_007c6ea4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int local_c;
  int local_8;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x14);
  local_c = in_ECX;
  local_8 = in_ECX;
  guard_check_icall(*(int **)(in_ECX + 0x14),param_1,param_2,param_3,&local_c);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_007c7046(iVar2);
  }
  return CONCAT44(local_8,local_c);
}




/* vtable slots: COleStreamFile[12] */
/* 007c6edf  FUN_007c6edf  44 bytes, 0 callers */

void FUN_007c6edf(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x18);
  guard_check_icall(*(int **)(in_ECX + 0x14),param_1,param_2);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_007c7046(iVar2);
  }
  return;
}




/* vtable slots: COleStreamFile[17] */
/* 007c6f0b  FUN_007c6f0b  52 bytes, 0 callers */

void FUN_007c6f0b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x2c);
  guard_check_icall(*(int **)(in_ECX + 0x14),param_1,param_2,param_3,param_4,2);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_007c7046(iVar2);
  }
  return;
}




/* vtable slots: COleStreamFile[15] */
/* 007c6f3f  FUN_007c6f3f  66 bytes, 0 callers */

void FUN_007c6f3f(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_8 [4];
  
  if (param_2 != 0) {
    if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x14) + 0x10);
    guard_check_icall(*(int **)(in_ECX + 0x14),param_1,param_2,local_8);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      FUN_007c7046(iVar2);
    }
  }
  return;
}



