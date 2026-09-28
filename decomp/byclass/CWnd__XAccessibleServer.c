/* CWnd::XAccessibleServer -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CWnd::XAccessibleServer[0] */
/* 00790afb  FUN_00790afb  58 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00790afb(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x18));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CWnd::XAccessibleServer[5] */
/* 0079286e  FUN_0079286e  29 bytes, 0 callers */

undefined4 FUN_0079286e(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 0;
    uVar1 = 0x80004001;
  }
  return uVar1;
}




/* vtable slots: CWnd::XAccessibleServer[4] */
/* 00792891  FUN_00792891  55 bytes, 0 callers */

undefined4 FUN_00792891(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    FUN_0079d9b9(*(undefined4 *)(param_1 + -0x18));
    *param_2 = *(undefined4 *)(param_1 + -0x14);
    guard_check_icall();
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CWnd::XAccessibleServer[2] */
/* 00794b2b  QueryInterface  64 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual long __stdcall CWnd::XAccessibleServer::QueryInterface(struct _GUID const &,void
   * *)
   
   Library: Visual Studio 2015 Release */

long CWnd::XAccessibleServer::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  undefined4 in_stack_0000000c;
  
  FUN_0079d9b9(*(undefined4 *)param_1[-2].Data4);
  lVar1 = FUN_007c0c76(param_2,in_stack_0000000c);
  guard_check_icall();
  return lVar1;
}




/* vtable slots: CWnd::XAccessibleServer[1] */
/* 00794e05  FUN_00794e05  58 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00794e05(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x18));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CWnd::XAccessibleServer[3] */
/* 0079530e  FUN_0079530e  75 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0079530e(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x18));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x34) + 0xec);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}



