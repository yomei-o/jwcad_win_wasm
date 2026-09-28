/* COleDataSource::XDataObject -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDataSource::XDataObject[1] */
/* 007b9e39  FUN_007b9e39  18 bytes, 0 callers */

void FUN_007b9e39(void)

{
  FUN_007c0c2e();
  return;
}




/* vtable slots: COleDataSource::XDataObject[9] */
/* 007b9eb2  FUN_007b9eb2  18 bytes, 0 callers */

undefined4 FUN_007b9eb2(void)

{
  undefined4 *in_stack_00000014;
  
  *in_stack_00000014 = 0;
  return 0x80040003;
}




/* vtable slots: COleDataSource::XDataObject[10] */
/* 007b9ec4  FUN_007b9ec4  8 bytes, 0 callers */

undefined4 FUN_007b9ec4(void)

{
  return 0x80040003;
}




/* vtable slots: COleDataSource::XDataObject[11] */
/* 007b9f20  FUN_007b9f20  18 bytes, 0 callers */

undefined4 FUN_007b9f20(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return 0x80040003;
}




/* vtable slots: COleDataSource::XDataObject[8] */
/* 007b9f32  FUN_007b9f32  142 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007b9f32(int param_1,uint param_2,int *param_3)

{
  tagFORMATETC *ptVar1;
  undefined4 uVar2;
  uint uVar3;
  tagFORMATETC local_34;
  undefined4 local_1c;
  int local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  if (param_3 == (int *)0x0) {
    return 0x80004003;
  }
  local_1c = 0x8007000e;
  *param_3 = 0;
  local_8 = 0;
  local_18 = FUN_0078e624(0x40);
  local_8._0_1_ = 1;
  if (local_18 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_007b9c52();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  for (uVar3 = 0; uVar3 < *(uint *)(param_1 + -8); uVar3 = uVar3 + 1) {
    ptVar1 = (tagFORMATETC *)(uVar3 * 0x24 + *(int *)(param_1 + -0x10));
    if ((ptVar1[1].lindex & param_2) != 0) {
      _AfxOleCopyFormatEtc(&local_34,ptVar1);
      FUN_007b9db1(&local_34);
    }
  }
  *param_3 = local_18 + 0x38;
  uVar2 = FUN_007b9fd1();
  return uVar2;
}




/* vtable slots: COleDataSource::XDataObject[6] */
/* 007ba0a7  FUN_007ba0a7  8 bytes, 0 callers */

undefined4 FUN_007ba0a7(void)

{
  return 0x40130;
}




/* vtable slots: COleDataSource::XDataObject[3] */
/* 007ba0f6  FUN_007ba0f6  195 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_007ba0f6(int param_1,undefined2 *param_2,void *param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  uVar3 = 0;
  if ((param_2 == (undefined2 *)0x0) || (param_3 == (void *)0x0)) {
    guard_check_icall();
    return 0x80070057;
  }
  iVar2 = FUN_007ba2bf(param_2,1);
  if (iVar2 != 0) {
    _memset(param_3,0,0xc);
    if (*(int *)(iVar2 + 0x14) == 0) {
      pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0x58);
      guard_check_icall(param_2,param_3);
      iVar2 = (*pcVar1)();
      uVar3 = ~-(uint)(iVar2 != 0) & 0x80040064;
      goto LAB_007ba16d;
    }
    iVar2 = FUN_0078ee7a(*param_2,param_3,(int *)(iVar2 + 0x14));
    if (iVar2 != 0) goto LAB_007ba16d;
  }
  uVar3 = 0x80040064;
LAB_007ba16d:
  guard_check_icall();
  return uVar3;
}




/* vtable slots: COleDataSource::XDataObject[4] */
/* 007ba1db  FUN_007ba1db  182 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_007ba1db(int param_1,undefined2 *param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  uVar3 = 0;
  if ((param_2 == (undefined2 *)0x0) || (param_3 == (undefined4 *)0x0)) {
    guard_check_icall();
    return 0x80070057;
  }
  *(undefined4 *)(param_2 + 8) = *param_3;
  iVar2 = FUN_007ba2bf(param_2,1);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x14) == 0) {
      pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0x58);
      guard_check_icall(param_2,param_3);
      iVar2 = (*pcVar1)();
      uVar3 = ~-(uint)(iVar2 != 0) & 0x80040064;
      goto LAB_007ba245;
    }
    iVar2 = FUN_0078ee7a(*param_2,param_3,(int *)(iVar2 + 0x14));
    if (iVar2 != 0) goto LAB_007ba245;
  }
  uVar3 = 0x80040064;
LAB_007ba245:
  guard_check_icall();
  return uVar3;
}




/* vtable slots: COleDataSource::XDataObject[5] */
/* 007ba530  QueryGetData  50 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __stdcall COleDataSource::XDataObject::QueryGetData(struct tagFORMATETC *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long COleDataSource::XDataObject::QueryGetData(tagFORMATETC *param_1)

{
  long lVar1;
  int iVar2;
  int in_stack_00000008;
  
  if (in_stack_00000008 == 0) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    iVar2 = FUN_007ba2bf(in_stack_00000008,1);
    lVar1 = (-(uint)(iVar2 != 0) & 0x7ffbff9c) + 0x80040064;
  }
  return lVar1;
}




/* vtable slots: COleDataSource::XDataObject[0] */
/* 007ba562  FUN_007ba562  24 bytes, 0 callers */

void FUN_007ba562(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007c0c76(param_2,param_3);
  return;
}




/* vtable slots: COleDataSource::XDataObject[2] */
/* 007ba57a  FUN_007ba57a  18 bytes, 0 callers */

void FUN_007ba57a(void)

{
  FUN_007c0ca1();
  return;
}




/* vtable slots: COleDataSource::XDataObject[7] */
/* 007ba5ce  FUN_007ba5ce  126 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007ba5ce(int param_1,int param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  if ((param_2 == 0) || (param_3 == 0)) {
    guard_check_icall();
    uVar3 = 0x80070057;
  }
  else {
    iVar2 = FUN_007ba2bf(param_2,2);
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0x5c);
      guard_check_icall(param_2,param_3,param_4);
      (*pcVar1)();
      uVar3 = FUN_007ba66c(param_3,param_4);
      return uVar3;
    }
    guard_check_icall();
    uVar3 = 0x80040064;
  }
  return uVar3;
}



