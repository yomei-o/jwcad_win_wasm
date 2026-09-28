/* CSmartDockingGroupGuidesManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSmartDockingGroupGuidesManager[1] */
/* 008c2b9e  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSmartDockingGroupGuidesManager::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CSmartDockingGroupGuidesManager::_scalar_deleting_destructor_
          (CSmartDockingGroupGuidesManager *this,uint param_1)

{
  FUN_008c2a3d();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1148);
    }
  }
  return this;
}




/* vtable slots: CSmartDockingGroupGuidesManager[6] */
/* 008c2c70  FUN_008c2c70  239 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008c2c70(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  if ((CSmartDockingGroupGuidesWnd *)(in_ECX + 8) == (CSmartDockingGroupGuidesWnd *)0x0) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x28) == 0) {
    return 0;
  }
  if (param_5 != -1) {
    if (param_5 == 0) {
      if (*(int *)(in_ECX + 0x113c) == 0) goto LAB_008c2cdf;
      *(undefined4 *)(in_ECX + 0x113c) = 0;
    }
    else {
      if ((param_5 != 1) || (*(int *)(in_ECX + 0x113c) != 0)) goto LAB_008c2cdf;
      *(undefined4 *)(in_ECX + 0x113c) = 1;
    }
    CSmartDockingGroupGuidesWnd::Update((CSmartDockingGroupGuidesWnd *)(in_ECX + 8));
  }
LAB_008c2cdf:
  GetClientRect(*(HWND *)(in_ECX + 0x28),&local_18);
  iVar1 = (local_18.left - local_18.right) + param_1 + param_3 >> 1;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  iVar2 = (local_18.top - local_18.bottom) + param_2 + param_4 >> 1;
  GetWindowRect(*(HWND *)(in_ECX + 0x28),&local_28);
  if ((local_28.left == iVar1) && (local_28.top == iVar2)) {
    return 0;
  }
  FUN_00797e71(&DAT_00a11d68,iVar1,iVar2,0xffffffff,0xffffffff,1);
  return 1;
}




/* vtable slots: CSmartDockingGroupGuidesManager[3] */
/* 008c2fbf  FUN_008c2fbf  587 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008c2fbf(undefined4 param_1)

{
  CSmartDockingGroupGuidesWnd *this;
  code *pcVar1;
  HRGN pHVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  int local_60;
  tagRECT local_54;
  tagRECT local_44;
  POINT local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x8c2fcb;
  if (*(int *)(in_ECX + 0x1138) != 0) goto LAB_008c3202;
  local_8 = 0;
  pHVar2 = CreateRectRgn(0,0,0,0);
  Attach(pHVar2);
  local_60 = 4;
  piVar6 = (int *)(in_ECX + 0xa0);
  do {
    pcVar1 = *(code **)(*piVar6 + 0x28);
    guard_check_icall(local_60);
    (*pcVar1)();
    pHVar2 = (HRGN)0x0;
    if (piVar6 != (int *)0xfffffd30) {
      pHVar2 = (HRGN)piVar6[0xb5];
    }
    CombineRgn((HRGN)0x0,(HRGN)0x0,pHVar2,2);
    piVar6 = piVar6 + 0xc6;
    local_60 = local_60 + 1;
  } while (local_60 < 9);
  uVar4 = DAT_00a13b94;
  if (DAT_00a13b94 == 0) {
    iVar3 = FUN_008c39e3();
    if (iVar3 == 2) {
      uVar4 = 0x42e7;
      goto LAB_008c306d;
    }
  }
  else {
LAB_008c306d:
    *(undefined4 *)(in_ECX + 0x1050) = 1;
    *(undefined4 *)(in_ECX + 0x104c) = 0;
    CMFCToolBarImages::Load((CMFCToolBarImages *)(in_ECX + 0x1018),uVar4,(HINSTANCE__ *)0x0,0);
    FUN_007eb999();
    CMFCToolBarImages::SetTransparentColor((CMFCToolBarImages *)(in_ECX + 0x1018),DAT_00a13b58);
  }
  local_44.left = 0;
  local_44.top = 0;
  local_44.right = 0;
  local_44.bottom = 0;
  GetRgnBox((HRGN)0x0,&local_44);
  InflateRect(&local_44,-DAT_00a13b54,-DAT_00a13b54);
  local_34.x = local_44.left;
  local_28 = local_44.bottom;
  local_34.y = (local_44.top + local_44.bottom) / 2;
  local_2c = (local_44.right + local_44.left) / 2;
  local_18 = local_44.top;
  local_24 = local_44.right;
  local_20 = local_34.y;
  local_1c = local_2c;
  pHVar2 = CreatePolygonRgn(&local_34,4,1);
  Attach(pHVar2);
  if (in_ECX == -0x1130) {
    pHVar2 = (HRGN)0x0;
  }
  else {
    pHVar2 = *(HRGN *)(in_ECX + 0x1134);
  }
  CombineRgn((HRGN)0x0,(HRGN)0x0,pHVar2,2);
  local_54.left = 0;
  local_54.top = 0;
  local_54.right = 0;
  local_54.bottom = 0;
  GetRgnBox((HRGN)0x0,&local_54);
  this = (CSmartDockingGroupGuidesWnd *)(in_ECX + 8);
  pcVar1 = *(code **)(*(int *)this + 0x58);
  uVar5 = FUN_008c27cd();
  guard_check_icall(8,uVar5,&DAT_00956338,0x80000000,&local_54,param_1,0,0);
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    *(int *)(in_ECX + 0x88) = in_ECX;
    FUN_00797c9f(0,0x80000,0);
    if ((DAT_00a13b9c == 0) && (iVar3 = FUN_008c39e3(), iVar3 != 2)) {
      FUN_007c2511();
      uVar5 = 0;
      if (this != (CSmartDockingGroupGuidesWnd *)0x0) {
        uVar5 = *(undefined4 *)(in_ECX + 0x28);
      }
      FUN_007e5fc4(uVar5,DAT_00a13b58,0,1);
    }
    else {
      CSmartDockingGroupGuidesWnd::Update(this);
    }
    *(undefined4 *)(in_ECX + 0x1140) = 1;
    *(undefined4 *)(in_ECX + 0x1138) = 1;
  }
  FUN_00416100();
LAB_008c3202:
  FUN_008d9b68();
  return;
}




/* vtable slots: CSmartDockingGroupGuidesManager[4] */
/* 008c343f  FUN_008c343f  103 bytes, 1 callers */

void FUN_008c343f(void)

{
  code *pcVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(in_ECX + 0x1138) != 0) {
    piVar3 = (int *)(in_ECX + 0xa0);
    iVar2 = 5;
    do {
      pcVar1 = *(code **)(*piVar3 + 0x2c);
      guard_check_icall();
      (*pcVar1)();
      piVar3 = piVar3 + 0xc6;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    pcVar1 = *(code **)(*(int *)(in_ECX + 8) + 0x60);
    guard_check_icall();
    (*pcVar1)();
    CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x1130));
    *(undefined4 *)(in_ECX + 0x1138) = 0;
  }
  return;
}




/* vtable slots: CSmartDockingGroupGuidesManager[7] */
/* 008c39a8  GetGuide  35 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CSmartDockingGroupGuide * __thiscall
   CSmartDockingGroupGuidesManager::GetGuide(enum CSmartDockingStandaloneGuide::SDMarkerPlace)
   
   Library: Visual Studio 2015 Release */

CSmartDockingGroupGuide * __thiscall
CSmartDockingGroupGuidesManager::GetGuide
          (CSmartDockingGroupGuidesManager *this,SDMarkerPlace param_1)

{
  CSmartDockingGroupGuide *pCVar1;
  
  if (param_1 - 4 < 5) {
    pCVar1 = (CSmartDockingGroupGuide *)(this + param_1 * 0x318 + -0xbc0);
  }
  else {
    pCVar1 = (CSmartDockingGroupGuide *)0x0;
  }
  return pCVar1;
}




/* vtable slots: CSmartDockingGroupGuidesManager[0] */
/* 008c39d7  FUN_008c39d7  6 bytes, 0 callers */

undefined ** FUN_008c39d7(void)

{
  return &PTR_s_CSmartDockingGroupGuidesManager_009a3c70;
}




/* vtable slots: CSmartDockingGroupGuidesManager[5], CSmartDockingStandaloneGuide[5] */
/* 008c40b9  Show  43 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CSmartDockingGroupGuidesManager::Show(int)
    public: virtual void __thiscall CSmartDockingStandaloneGuide::Show(int)
   
   Library: Visual Studio 2015 Release */

void Show(int param_1)

{
  BOOL BVar1;
  int in_ECX;
  
  BVar1 = IsWindow(*(HWND *)(in_ECX + 0x28));
  if (BVar1 != 0) {
    FUN_00797f20(-(param_1 != 0) & 5);
  }
  return;
}



