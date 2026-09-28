/* COleDataSource -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDataSource[1] */
/* 007b9d81  FUN_007b9d81  48 bytes, 0 callers */

void FUN_007b9d81(byte param_1)

{
  FUN_007b9ce3();
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




/* vtable slots: COleDataSource[14] */
/* 007ba2b9  FUN_007ba2b9  6 bytes, 0 callers */

undefined ** FUN_007ba2b9(void)

{
  return &PTR_DAT_0098192c;
}




/* vtable slots: COleDataSource[22] */
/* 007ba3d1  FUN_007ba3d1  350 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007ba3d1(int param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int *in_ECX;
  CSharedFile local_6c [56];
  COleStreamFile local_34 [28];
  int local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_8 = 0x7ba3dd;
  uVar4 = *(uint *)(param_1 + 0x10);
  if ((uVar4 & 1) != 0) {
    local_18 = param_2[1];
    pcVar1 = *(code **)(*in_ECX + 0x50);
    local_14 = in_ECX;
    guard_check_icall(param_1,&local_18);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      *param_2 = 1;
      param_2[1] = local_18;
      return 1;
    }
    FUN_007ba754(2,0x1000);
    local_8 = 0;
    if (*param_2 == 1) {
      FUN_007ba8a1(param_2[1],0);
    }
    pcVar1 = *(code **)(*local_14 + 0x54);
    guard_check_icall(param_1,local_6c);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      *param_2 = 1;
      pvVar3 = CSharedFile::Detach(local_6c);
      param_2[1] = (int)pvVar3;
      FUN_007ba784();
      return 1;
    }
    if (*param_2 == 1) {
      CSharedFile::Detach(local_6c);
    }
    local_8 = 0xffffffff;
    FUN_007ba784();
    uVar4 = *(uint *)(param_1 + 0x10);
    in_ECX = local_14;
  }
  if ((uVar4 & 4) != 0) {
    FUN_007c69d9(0);
    local_8 = 1;
    if (*param_2 == 4) {
      FUN_007c6c85(param_2[1]);
    }
    else {
      iVar2 = COleStreamFile::CreateMemoryStream(local_34,(CFileException *)0x0);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e73e();
      }
    }
    pcVar1 = *(code **)(*in_ECX + 0x54);
    guard_check_icall(param_1,local_34);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      *param_2 = 4;
      iVar2 = FUN_007c6d02();
      param_2[1] = iVar2;
      FUN_007c6ad9();
      return 1;
    }
    if (*param_2 == 4) {
      FUN_007c6d02();
    }
    FUN_007c6ad9();
  }
  return 0;
}



