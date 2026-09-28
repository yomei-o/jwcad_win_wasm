/* CSmartDockingStandaloneGuide -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSmartDockingStandaloneGuide[1] */
/* 008c2c04  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSmartDockingStandaloneGuide::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CSmartDockingStandaloneGuide::_scalar_deleting_destructor_
          (CSmartDockingStandaloneGuide *this,uint param_1)

{
  FUN_008c2ae8();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2f0);
    }
  }
  return this;
}




/* vtable slots: CSmartDockingStandaloneGuide[6] */
/* 008c2d5f  AdjustPos  171 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CSmartDockingStandaloneGuide::AdjustPos(class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CSmartDockingStandaloneGuide::AdjustPos
          (CSmartDockingStandaloneGuide *this,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 4);
  if (iVar1 == 0) {
    param_2 = param_2 + 0x10;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        param_2 = (param_4 + param_2 >> 1) - (*(int *)(this + 0x2d8) >> 1);
        param_3 = param_3 + 0x10;
      }
      else {
        if (iVar1 != 3) {
          return;
        }
        param_2 = (param_4 + param_2 >> 1) - (*(int *)(this + 0x2d8) >> 1);
        param_3 = (param_5 - *(int *)(this + 0x2dc)) + -0x10;
      }
      goto LAB_008c2de6;
    }
    param_2 = (param_4 - *(int *)(this + 0x2d8)) + -0x10;
  }
  param_3 = (param_5 + param_3 >> 1) - (*(int *)(this + 0x2dc) >> 1);
LAB_008c2de6:
  if ((this != (CSmartDockingStandaloneGuide *)0xfffffff8) && (*(int *)(this + 0x28) != 0)) {
    FUN_00797e71(&DAT_00a11d68,param_2,param_3,0xffffffff,0xffffffff,0x11);
  }
  return;
}




/* vtable slots: CSmartDockingStandaloneGuide[3] */
/* 008c320a  FUN_008c320a  320 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c320a(int param_1,undefined4 param_2)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  in_ECX[1] = param_1;
  if (DAT_00a13b9c == 0) {
    iVar3 = FUN_008c39e3();
    if (iVar3 != 2) {
      bVar2 = false;
      goto LAB_008c3245;
    }
  }
  bVar2 = true;
LAB_008c3245:
  pcVar1 = *(code **)(*in_ECX + 0x24);
  guard_check_icall(&DAT_00a13b48);
  (*pcVar1)();
  uVar4 = FUN_007e8b71(in_ECX[0x4b],DAT_00a13b58);
  Attach(uVar4);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetRgnBox((HRGN)in_ECX[0xb5],&local_18);
  iVar3 = in_ECX[0x4c];
  in_ECX[0xb6] = local_18.right - local_18.left;
  in_ECX[0xb7] = local_18.bottom - local_18.top;
  if (iVar3 == 0) {
    iVar3 = in_ECX[0x4b];
  }
  if ((in_ECX[1] == 2) || (in_ECX[1] == 3)) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  FUN_008c334a(&local_18,iVar3,0,param_2,in_ECX[0xba],uVar4);
  FUN_00797c9f(0,0x80000,0);
  if (!bVar2) {
    FUN_007c2511();
    if (in_ECX == (int *)0xfffffff8) {
      iVar3 = 0;
    }
    else {
      iVar3 = in_ECX[10];
    }
    FUN_007e5fc4(iVar3,DAT_00a13b58,0,1);
  }
  in_ECX[0xb9] = 1;
  FUN_00797c9f(0,8,0);
  return;
}




/* vtable slots: CSmartDockingStandaloneGuide[4] */
/* 008c34a6  FUN_008c34a6  39 bytes, 1 callers */

void FUN_008c34a6(void)

{
  code *pcVar1;
  BOOL BVar2;
  int in_ECX;
  
  BVar2 = IsWindow(*(HWND *)(in_ECX + 0x28));
  if (BVar2 != 0) {
    pcVar1 = *(code **)(*(int *)(in_ECX + 8) + 0x60);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CSmartDockingStandaloneGuide[7] */
/* 008c3a6b  FUN_008c3a6b  115 bytes, 0 callers */

void FUN_008c3a6b(int param_1)

{
  CSmartDockingStandaloneGuideWnd *this;
  int iVar1;
  HBITMAP__ *pHVar2;
  int in_ECX;
  
  this = (CSmartDockingStandaloneGuideWnd *)(in_ECX + 8);
  if (*(int *)(in_ECX + 0x2e0) == param_1) {
    CSmartDockingStandaloneGuideWnd::UpdateLayered(this);
  }
  else {
    *(int *)(in_ECX + 0x2e0) = param_1;
    CSmartDockingStandaloneGuideWnd::Highlight(this,param_1);
    if ((*(int *)(in_ECX + 0x2e8) != 0) && (iVar1 = FUN_008c39e3(), iVar1 != 2)) {
      return;
    }
    pHVar2 = *(HBITMAP__ **)(in_ECX + 0x130);
    if (pHVar2 == (HBITMAP__ *)0x0) {
      pHVar2 = *(HBITMAP__ **)(in_ECX + 300);
    }
    if ((param_1 != 0) && (pHVar2 = *(HBITMAP__ **)(in_ECX + 0x244), pHVar2 == (HBITMAP__ *)0x0)) {
      pHVar2 = *(HBITMAP__ **)(in_ECX + 300);
    }
    CSmartDockingStandaloneGuideWnd::Assign(this,pHVar2,1);
  }
  return;
}




/* vtable slots: CSmartDockingStandaloneGuide[8] */
/* 008c3d76  IsPtIn  178 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual int __thiscall CSmartDockingStandaloneGuide::IsPtIn(class CPoint)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall
CSmartDockingStandaloneGuide::IsPtIn(CSmartDockingStandaloneGuide *this,int param_2,int param_3)

{
  BOOL BVar1;
  HRGN pHVar2;
  
  if (((this != (CSmartDockingStandaloneGuide *)0xfffffff8) && (*(int *)(this + 0x28) != 0)) &&
     (BVar1 = IsWindowVisible(*(HWND *)(this + 0x28)), BVar1 != 0)) {
    ScreenToClient(*(HWND *)(this + 0x28),(LPPOINT)&param_2);
    if (*(int *)(this + 0x2e4) != 0) {
      BVar1 = PtInRegion(*(HRGN *)(this + 0x2d4),param_2,param_3);
      return BVar1;
    }
    pHVar2 = CreateRectRgn(0,0,0,0);
    Attach(pHVar2);
    GetWindowRgn(*(HWND *)(this + 0x28),(HRGN)0x0);
    BVar1 = PtInRegion((HRGN)0x0,param_2,param_3);
    FUN_00416100();
    return BVar1;
  }
  return 0;
}



