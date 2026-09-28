/* CWnd::XAccessible -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CWnd::XAccessible[0] */
/* 00790ac1  FUN_00790ac1  58 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00790ac1(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CWnd::XAccessible[4] */
/* 00792901  FUN_00792901  27 bytes, 0 callers */

void FUN_00792901(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007913fa(param_2,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CWnd::XAccessible[6] */
/* 00792bf3  FUN_00792bf3  8 bytes, 0 callers */

undefined4 FUN_00792bf3(void)

{
  return 0x80004001;
}




/* vtable slots: CWnd::XAccessible[5] */
/* 00792c28  FUN_00792c28  29 bytes, 0 callers */

undefined4 FUN_00792c28(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 1;
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CWnd::XAccessible[3] */
/* 00793015  Invoke  80 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual long __stdcall CWnd::XAccessible::Invoke(long,struct _GUID const &,unsigned
   long,unsigned short,struct tagDISPPARAMS *,struct tagVARIANT *,struct tagEXCEPINFO *,unsigned int
   *)
   
   Library: Visual Studio 2015 Release */

long CWnd::XAccessible::Invoke
               (long param_1,_GUID *param_2,ulong param_3,ushort param_4,tagDISPPARAMS *param_5,
               tagVARIANT *param_6,tagEXCEPINFO *param_7,uint *param_8)

{
  long lVar1;
  undefined2 in_stack_00000012;
  undefined4 in_stack_00000024;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  lVar1 = FUN_0079146b(param_1,param_2,param_3,_param_4,param_5,param_6,param_7,param_8,
                       in_stack_00000024);
  guard_check_icall();
  return lVar1;
}




/* vtable slots: CWnd::XAccessible[2] */
/* 00794aeb  QueryInterface  64 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual long __stdcall CWnd::XAccessible::QueryInterface(struct _GUID const &,void * *)
   
   Library: Visual Studio 2015 Release */

long CWnd::XAccessible::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  undefined4 in_stack_0000000c;
  
  FUN_0079d9b9(*(undefined4 *)(param_1[-2].Data4 + 4));
  lVar1 = FUN_007c0c76(param_2,in_stack_0000000c);
  guard_check_icall();
  return lVar1;
}




/* vtable slots: CWnd::XAccessible[1] */
/* 00794dcb  FUN_00794dcb  58 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00794dcb(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CWnd::XAccessible[25] */
/* 00795fe8  FUN_00795fe8  89 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00795fe8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xe0);
  guard_check_icall(param_2,param_3,param_4,param_5);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[24] */
/* 007960a6  FUN_007960a6  81 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007960a6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xdc);
  guard_check_icall(param_2,param_3,param_4);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[22] */
/* 00796194  FUN_00796194  101 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796194(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xd4);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[23] */
/* 00796278  FUN_00796278  95 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796278(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xd8);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6,param_7);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[21] */
/* 00796343  FUN_00796343  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796343(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xd0);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[9] */
/* 0079648b  FUN_0079648b  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_0079648b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xa0);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[8] */
/* 00796540  FUN_00796540  75 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00796540(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0x9c);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[20] */
/* 00796604  FUN_00796604  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796604(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xcc);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[12] */
/* 007966d9  FUN_007966d9  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_007966d9(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xac);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[18] */
/* 0079678e  FUN_0079678e  75 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0079678e(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xc4);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[15] */
/* 00796852  FUN_00796852  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796852(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xb8);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[16] */
/* 00796933  FUN_00796933  95 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796933(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xbc);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6,param_7);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[17] */
/* 00796a0b  FUN_00796a0b  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796a0b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xc0);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[10] */
/* 00796ae0  FUN_00796ae0  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796ae0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xa4);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[7] */
/* 00796b95  FUN_00796b95  75 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00796b95(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0x98);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[13] */
/* 00796c59  FUN_00796c59  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796c59(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xb0);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[19] */
/* 00796d0e  FUN_00796d0e  75 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00796d0e(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 200);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[14] */
/* 00796dd2  FUN_00796dd2  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796dd2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xb4);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[11] */
/* 00796ea7  FUN_00796ea7  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796ea7(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xa8);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[26] */
/* 00796f4d  FUN_00796f4d  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796f4d(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xe4);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CWnd::XAccessible[27] */
/* 00796fa9  FUN_00796fa9  92 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00796fa9(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x14));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x30) + 0xe8);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}



