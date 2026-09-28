/* CMFCBaseAccessibleObject::XAccessible -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCBaseAccessibleObject::XAccessible[1] */
/* 00863167  FUN_00863167  44 bytes, 0 callers */

undefined4 FUN_00863167(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[5] */
/* 008637e3  FUN_008637e3  77 bytes, 0 callers */

HRESULT FUN_008637e3(int param_1,IID *param_2,LPOLESTR *param_3,UINT param_4,LCID param_5,
                    DISPID *param_6)

{
  _func_6445 *p_Var1;
  IDispatch *This;
  HRESULT HVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  This = CCmdTarget::GetIDispatch((CCmdTarget *)(param_1 + -0x5c),0);
  p_Var1 = This->lpVtbl->GetIDsOfNames;
  guard_check_icall();
  HVar2 = (*p_Var1)(This,param_2,param_3,param_4,param_5,param_6);
  guard_check_icall();
  return HVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[4] */
/* 00863c6e  FUN_00863c6e  71 bytes, 0 callers */

HRESULT FUN_00863c6e(int param_1,UINT param_2,LCID param_3,ITypeInfo **param_4)

{
  _func_6444 *p_Var1;
  IDispatch *This;
  HRESULT HVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  This = CCmdTarget::GetIDispatch((CCmdTarget *)(param_1 + -0x5c),0);
  p_Var1 = This->lpVtbl->GetTypeInfo;
  guard_check_icall();
  HVar2 = (*p_Var1)(This,param_2,param_3,param_4);
  guard_check_icall();
  return HVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[3] */
/* 00863cb5  FUN_00863cb5  65 bytes, 0 callers */

HRESULT FUN_00863cb5(int param_1,UINT *param_2)

{
  _func_6443 *p_Var1;
  IDispatch *This;
  HRESULT HVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  This = CCmdTarget::GetIDispatch((CCmdTarget *)(param_1 + -0x5c),0);
  p_Var1 = This->lpVtbl->GetTypeInfoCount;
  guard_check_icall();
  HVar2 = (*p_Var1)(This,param_2);
  guard_check_icall();
  return HVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[6] */
/* 00863d20  FUN_00863d20  86 bytes, 0 callers */

HRESULT FUN_00863d20(int param_1,DISPID param_2,IID *param_3,LCID param_4,WORD param_5,
                    DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,UINT *param_9)

{
  _func_6446 *p_Var1;
  IDispatch *This;
  HRESULT HVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  This = CCmdTarget::GetIDispatch((CCmdTarget *)(param_1 + -0x5c),0);
  p_Var1 = This->lpVtbl->Invoke;
  guard_check_icall();
  HVar2 = (*p_Var1)(This,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  guard_check_icall();
  return HVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[0] */
/* 00864659  FUN_00864659  50 bytes, 0 callers */

undefined4 FUN_00864659(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  uVar1 = FUN_007c0c76(param_2,param_3);
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[2] */
/* 008646e1  FUN_008646e1  44 bytes, 0 callers */

undefined4 FUN_008646e1(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[25] */
/* 00864ea0  FUN_00864ea0  80 bytes, 0 callers */

undefined4
FUN_00864ea0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x98);
  guard_check_icall(param_2,param_3,param_4,param_5);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[24] */
/* 00864f4a  FUN_00864f4a  69 bytes, 0 callers */

undefined4 FUN_00864f4a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x94);
  guard_check_icall(param_2,param_3,param_4);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[22] */
/* 008650ac  FUN_008650ac  92 bytes, 0 callers */

undefined4
FUN_008650ac(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x8c);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[23] */
/* 008651c7  FUN_008651c7  86 bytes, 0 callers */

undefined4
FUN_008651c7(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x90);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6,param_7);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[21] */
/* 0086521d  FUN_0086521d  83 bytes, 0 callers */

undefined4
FUN_0086521d(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x88);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[9] */
/* 00865299  FUN_00865299  80 bytes, 0 callers */

undefined4
FUN_00865299(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x58);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[8] */
/* 008652e9  FUN_008652e9  60 bytes, 0 callers */

undefined4 FUN_008652e9(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x54);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[20] */
/* 008653b7  FUN_008653b7  83 bytes, 0 callers */

undefined4
FUN_008653b7(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x84);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[12] */
/* 00865492  FUN_00865492  80 bytes, 0 callers */

undefined4
FUN_00865492(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 100);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[18] */
/* 008654fa  FUN_008654fa  60 bytes, 0 callers */

undefined4 FUN_008654fa(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x7c);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[15] */
/* 0086558b  FUN_0086558b  80 bytes, 0 callers */

undefined4
FUN_0086558b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x70);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[16] */
/* 008655e3  FUN_008655e3  83 bytes, 0 callers */

undefined4
FUN_008655e3(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x74);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6,param_7);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[17] */
/* 008656c2  FUN_008656c2  80 bytes, 0 callers */

undefined4
FUN_008656c2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x78);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[10] */
/* 008657a2  FUN_008657a2  80 bytes, 0 callers */

undefined4
FUN_008657a2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x5c);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[7] */
/* 00865837  FUN_00865837  60 bytes, 0 callers */

undefined4 FUN_00865837(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x50);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[13] */
/* 00865915  FUN_00865915  80 bytes, 0 callers */

undefined4
FUN_00865915(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x68);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[19] */
/* 00865965  FUN_00865965  63 bytes, 0 callers */

undefined4 FUN_00865965(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x80);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[14] */
/* 00865a3b  FUN_00865a3b  80 bytes, 0 callers */

undefined4
FUN_00865a3b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x6c);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[11] */
/* 00865b13  FUN_00865b13  80 bytes, 0 callers */

undefined4
FUN_00865b13(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x60);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[26] */
/* 00865b63  FUN_00865b63  83 bytes, 0 callers */

undefined4
FUN_00865b63(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0x9c);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CMFCBaseAccessibleObject::XAccessible[27] */
/* 00865bb6  FUN_00865bb6  83 bytes, 0 callers */

undefined4
FUN_00865bb6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x40));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x5c) + 0xa0);
  guard_check_icall(param_2,param_3,param_4,param_5,param_6);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}



