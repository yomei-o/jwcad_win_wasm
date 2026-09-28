/* CMFCRibbonLaunchButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonLaunchButton[118] */
/* 0086b7d8  FUN_0086b7d8  176 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_0086b7d8(int *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  int *in_ECX;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x71] == 0) {
    FUN_008677b0(param_1,param_2,param_3);
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x1d4);
    guard_check_icall(&local_10,param_2);
    (*pcVar1)();
    if (((local_10 == 0) && (local_c == 0)) ||
       (BVar4 = IsRectEmpty((RECT *)(in_ECX + 0x1d)), BVar4 != 0)) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
    }
    else {
      iVar2 = in_ECX[0x20];
      iVar3 = *(int *)(in_ECX[0x71] + 0xd4);
      *param_1 = iVar3 - local_10;
      param_1[1] = iVar2;
      param_1[2] = iVar3;
      param_1[3] = local_c + iVar2;
    }
  }
  return param_1;
}




/* vtable slots: CMFCRibbonLaunchButton[62] */
/* 0086bcfa  GetRegularSize  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CSize __thiscall CMFCRibbonLaunchButton::GetRegularSize(class CDC *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

CDC * __thiscall CMFCRibbonLaunchButton::GetRegularSize(CMFCRibbonLaunchButton *this,CDC *param_1)

{
  undefined4 in_stack_00000008;
  
  if (*(int *)(this + 0x1c4) == 0) {
    FUN_00867aa7(param_1,in_stack_00000008);
  }
  else {
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return param_1;
}




/* vtable slots: CMFCRibbonLaunchButton[0] */
/* 0086bd29  FUN_0086bd29  6 bytes, 0 callers */

undefined ** FUN_0086bd29(void)

{
  return &PTR_s_CMFCRibbonLaunchButton_00998738;
}




/* vtable slots: CMFCRibbonLaunchButton[153] */
/* 0086c963  FUN_0086c963  57 bytes, 0 callers */

void FUN_0086c963(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x94) == (int *)0x0) {
    FUN_00863dc7(0);
  }
  else {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x94) + 0x450);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonLaunchButton[95] */
/* 0086c9c8  FUN_0086c9c8  84 bytes, 0 callers */

void FUN_0086c9c8(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  int *piVar3;
  int in_ECX;
  
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x74));
  if (BVar2 == 0) {
    if (*(int *)(in_ECX + 0x1c4) == 0) {
      FUN_00868468(param_1);
    }
    else {
      piVar3 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar3 + 0x228);
      guard_check_icall(param_1);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonLaunchButton[43] */
/* 00870bc8  SetACCData  35 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCRibbonLaunchButton::SetACCData(class CWnd *,class
   CAccessibilityData &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
CMFCRibbonLaunchButton::SetACCData
          (CMFCRibbonLaunchButton *this,CWnd *param_1,CAccessibilityData *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00869cab(param_1,param_2);
  if (iVar1 != 0) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x40000000;
  }
  return (uint)(iVar1 != 0);
}



