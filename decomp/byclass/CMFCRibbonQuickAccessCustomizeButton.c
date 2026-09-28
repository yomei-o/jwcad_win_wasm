/* CMFCRibbonQuickAccessCustomizeButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[1] */
/* 008b1960  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonQuickAccessCustomizeButton::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonQuickAccessCustomizeButton::_scalar_deleting_destructor_
          (CMFCRibbonQuickAccessCustomizeButton *this,uint param_1)

{
  ~CMFCRibbonQuickAccessCustomizeButton(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1dc);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[90] */
/* 008b1a60  CopyFrom  52 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonQuickAccessCustomizeButton::CopyFrom(class
   CMFCRibbonBaseElement const &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonQuickAccessCustomizeButton::CopyFrom
          (CMFCRibbonQuickAccessCustomizeButton *this,CMFCRibbonBaseElement *param_1)

{
  FUN_0086612f(param_1);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 0x1d8),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x1d8));
  return;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[63] */
/* 008b1af4  FUN_008b1af4  73 bytes, 0 callers */

undefined4 * FUN_008b1af4(undefined4 *param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  int *local_c;
  int *local_8;
  
  local_c = in_ECX;
  local_8 = in_ECX;
  FUN_0086715f(param_1,param_2);
  pcVar1 = *(code **)(*in_ECX + 0x114);
  guard_check_icall(&local_c,0xffffffff);
  (*pcVar1)();
  *param_1 = local_c + 1;
  param_1[1] = (int)local_8 * 2;
  return param_1;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[69] */
/* 008b1b3d  FUN_008b1b3d  155 bytes, 0 callers */

undefined4 * FUN_008b1b3d(undefined4 *param_1)

{
  double dVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_0081507c(param_1);
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar2 + 0x1e0);
  }
  if (dVar1 != 1.0) {
    FUN_007c2511();
    uVar3 = thunk_FUN_008d99f0();
    *param_1 = uVar3;
    FUN_007c2511();
    uVar3 = thunk_FUN_008d99f0();
    param_1[1] = uVar3;
  }
  return param_1;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[118] */
/* 008b1bd8  FUN_008b1bd8  152 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008b1bd8(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  int iVar5;
  int *in_ECX;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x1d4);
  guard_check_icall(&local_10,param_2);
  (*pcVar1)();
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((local_10 != 0) || (local_c != 0)) {
    BVar4 = IsRectEmpty((RECT *)(in_ECX + 0x1d));
    if ((BVar4 == 0) && (in_ECX[0x25] == 0)) {
      iVar5 = in_ECX[0x20];
      iVar2 = in_ECX[0x1e];
      iVar3 = ((RECT *)(in_ECX + 0x1d))->left;
      param_1[2] = local_10 + iVar3;
      iVar5 = (iVar5 + iVar2) / 2;
      *param_1 = iVar3;
      param_1[1] = iVar5;
      param_1[3] = local_c + iVar5;
    }
  }
  return param_1;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[0] */
/* 008b1d09  FUN_008b1d09  6 bytes, 0 callers */

undefined ** FUN_008b1d09(void)

{
  return &PTR_s_CMFCRibbonQuickAccessCustomizeBu_009a0ee4;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[48] */
/* 008b1d15  FUN_008b1d15  100 bytes, 0 callers */

int * FUN_008b1d15(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xe4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if (in_ECX[0x73] == 0) {
      FUN_00867dc1(param_1);
    }
    else {
      iVar2 = FUN_004054a0(in_ECX[0x76] + -0x10);
      *param_1 = iVar2 + 0x10;
    }
  }
  else {
    CStringT<>(&DAT_00956338);
  }
  return param_1;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[95] */
/* 008b1ead  FUN_008b1ead  272 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b1ead(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  BOOL BVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *in_ECX;
  undefined1 local_2c [8];
  RECT *local_24;
  undefined4 local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_24 = (RECT *)(in_ECX + 0x1d);
  local_20 = param_1;
  local_1c = in_ECX;
  BVar3 = IsRectEmpty(local_24);
  if (BVar3 == 0) {
    piVar4 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar4 + 0x238);
    guard_check_icall(param_1);
    (*pcVar1)();
    piVar4 = local_1c;
    iVar5 = 0x1d;
    iVar6 = local_1c[0x73];
    if (0 < iVar6) {
      iVar5 = FUN_007c2511();
      iVar6 = piVar4[0x73];
      iVar5 = (-(uint)(*(int *)(iVar5 + 0x198) != 0) & 0xfffffffa) + 0x1f;
    }
    pcVar1 = *(code **)(*piVar4 + 0xb8);
    guard_check_icall(-(uint)(iVar6 != 0) & 0x9a1184,0);
    (*pcVar1)();
    local_18.left = piVar4[0x1d];
    local_18.top = piVar4[0x1e];
    local_18.right = piVar4[0x1f];
    local_18.bottom = piVar4[0x20];
    OffsetRect(&local_18,0,1);
    FUN_0081507c(local_2c);
    uVar2 = local_20;
    FUN_00814d1c(local_20,iVar5,&local_18,2,local_2c);
    FUN_00814d1c(uVar2,iVar5,local_24,5,local_2c);
    piVar4 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar4 + 0x240);
    guard_check_icall(uVar2,local_1c);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[119] */
/* 008b1fbd  FUN_008b1fbd  35 bytes, 0 callers */

undefined4 FUN_008b1fbd(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x210);
  guard_check_icall(0xffffffff,0xffffffff);
  (*pcVar1)();
  return 0;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[132] */
/* 008b1fe0  FUN_008b1fe0  449 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008b1fe0(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  BOOL BVar4;
  CMFCRibbonPanelMenu *this;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  HWND local_30;
  int local_2c;
  int local_24;
  int iStack_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x8b1fec;
  if (in_ECX[0x38] == 0) {
    uVar2 = FUN_00797acc();
    iVar3 = in_ECX[0x21];
    local_2c = in_ECX[0x25];
    if ((in_ECX[0x25] == 0) && (local_2c = iVar3, iVar3 == 0)) {
      local_30 = (HWND)0x0;
    }
    else {
      local_30 = *(HWND *)(local_2c + 0x20);
    }
    local_24 = in_ECX[0x1d];
    iStack_20 = in_ECX[0x1e];
    local_1c = in_ECX[0x1f];
    local_18 = in_ECX[0x20];
    FUN_0079e8b8(&local_24);
    iVar3 = local_1c;
    if ((uVar2 & 0x400000) == 0) {
      iVar3 = local_24;
    }
    if (in_ECX[0x73] == 0) {
      in_ECX[0x38] = 1;
      in_ECX[0x32] = 1;
      pcVar1 = *(code **)(*in_ECX + 0x1b8);
      guard_check_icall();
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)in_ECX[0x21] + 0x350);
      guard_check_icall(local_2c,iVar3,local_18);
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        BVar4 = IsWindow(local_30);
        if (BVar4 != 0) {
          in_ECX[0x38] = 0;
        }
      }
    }
    else {
      this = (CMFCRibbonPanelMenu *)FUN_0078e624(0x2040);
      local_8 = 0;
      if (this == (CMFCRibbonPanelMenu *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)CMFCRibbonPanelMenu::CMFCRibbonPanelMenu
                                  (this,(CMFCRibbonBar *)in_ECX[0x21],
                                   (CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*> *)
                                   (in_ECX + 0x71),1);
      }
      local_8 = 0xffffffff;
      pcVar1 = *(code **)(*piVar5 + 0x1c8);
      guard_check_icall();
      iVar6 = (*pcVar1)();
      *(undefined4 *)(iVar6 + 0xde0) = 1;
      FUN_00820bbf(in_ECX);
      pcVar1 = *(code **)(*piVar5 + 0x210);
      guard_check_icall(in_ECX[0x21],iVar3,local_18,0,0,0);
      (*pcVar1)();
      FUN_00864a83(piVar5);
      if (-1 < *(int *)(in_ECX[0x21] + 0x2d4)) {
        RedrawWindow(*(HWND *)(in_ECX[0x21] + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
      }
    }
  }
  else {
    in_ECX[0x32] = 1;
    pcVar1 = *(code **)(*in_ECX + 0x1b8);
    guard_check_icall();
    (*pcVar1)();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonQuickAccessCustomizeButton[79] */
/* 008b2261  FUN_008b2261  33 bytes, 0 callers */

void FUN_008b2261(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x210);
  guard_check_icall(in_ECX[0x1d],in_ECX[0x1e]);
  (*pcVar1)();
  return;
}



