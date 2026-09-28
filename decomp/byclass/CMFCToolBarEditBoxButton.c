/* CMFCToolBarEditBoxButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarEditBoxButton[1] */
/* 008d222d  FUN_008d222d  51 bytes, 0 callers */

void FUN_008d222d(byte param_1)

{
  FUN_008d21a7();
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




/* vtable slots: CMFCToolBarEditBoxButton[5] */
/* 008d2299  FUN_008d2299  58 bytes, 0 callers */

void FUN_008d2299(int param_1)

{
  int in_ECX;
  
  FUN_00880ee9(param_1);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 0x70);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x7c),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x7c));
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[51] */
/* 008d22d3  FUN_008d22d3  111 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_008d22d3(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  iVar2 = FUN_0078e624(0xd8);
  piVar3 = (int *)0x0;
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_008d217b(in_ECX);
  }
  iVar2 = FUN_00798f4d(*(undefined4 *)(in_ECX + 0x74),param_2,param_1,*(undefined4 *)(in_ECX + 0x20)
                      );
  if (iVar2 == 0) {
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    piVar3 = (int *)0x0;
  }
  return piVar3;
}




/* vtable slots: CMFCToolBarEditBoxButton[53] */
/* 008d2342  FUN_008d2342  82 bytes, 0 callers */

void FUN_008d2342(tagRECT *param_1)

{
  int iVar1;
  HWND pHVar2;
  CWnd *this;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x78);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    GetWindowRect(*(HWND *)(iVar1 + 0x20),param_1);
    pHVar2 = GetParent(*(HWND *)(*(int *)(in_ECX + 0x78) + 0x20));
    this = CWnd::FromHandle(pHVar2);
    CWnd::ScreenToClient(this,param_1);
    InflateRect(param_1,1,1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCToolBarEditBoxButton[14] */
/* 008d2395  FUN_008d2395  12 bytes, 0 callers */

undefined4 FUN_008d2395(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x78) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0x78) + 0x20);
}




/* vtable slots: CMFCToolBarEditBoxButton[34] */
/* 008d23a1  FUN_008d23a1  122 bytes, 0 callers */

int * FUN_008d23a1(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x18) == 0) || (*(int *)(in_ECX + 0x84) == 0)) ||
     (*(int *)(*(int *)(in_ECX + 0x2c) + -0xc) == 0)) {
    *param_1 = *(int *)(in_ECX + 0x54);
    param_1[1] = *(int *)(in_ECX + 0x58);
    param_1[2] = *(int *)(in_ECX + 0x5c);
    param_1[3] = *(int *)(in_ECX + 0x60);
  }
  else {
    iVar1 = *(int *)(in_ECX + 100);
    iVar2 = *(int *)(in_ECX + 0x58);
    iVar3 = *(int *)(in_ECX + 0x54);
    iVar4 = *(int *)(in_ECX + 0x5c);
    iVar5 = *(int *)(in_ECX + 0x68);
    iVar6 = *(int *)(in_ECX + 0x60);
    *param_1 = ((iVar3 - iVar1) + *(int *)(in_ECX + 0x5c)) / 2;
    param_1[1] = iVar2;
    param_1[2] = (iVar3 + iVar1 + iVar4) / 2;
    param_1[3] = iVar5 + iVar6 + iVar2;
  }
  return param_1;
}




/* vtable slots: CMFCToolBarEditBoxButton[0] */
/* 008d2421  FUN_008d2421  6 bytes, 0 callers */

undefined ** FUN_008d2421(void)

{
  return &PTR_s_CMFCToolBarEditBoxButton_00a00d14;
}




/* vtable slots: CMFCToolBarEditBoxButton[21] */
/* 008d2427  HaveHotBorder  32 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBarEditBoxButton::HaveHotBorder(void)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

int __thiscall CMFCToolBarEditBoxButton::HaveHotBorder(CMFCToolBarEditBoxButton *this)

{
  uint uVar1;
  
  if ((*(int *)(this + 0x78) != 0) && (*(int *)(*(int *)(this + 0x78) + 0x20) != 0)) {
    uVar1 = FUN_00797b3d();
    if ((uVar1 & 0x10000000) != 0) {
      return 0;
    }
  }
  return 1;
}




/* vtable slots: CMFCToolBarEditBoxButton[16] */
/* 008d2469  FUN_008d2469  191 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_008d2469(int param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  CObject *in_ECX;
  bool bVar4;
  CObList local_30 [4];
  undefined4 *local_2c;
  CObject *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x8d2475;
  if (((*(int *)(in_ECX + 0x78) == 0) || (*(int *)(*(int *)(in_ECX + 0x78) + 0x20) == 0)) ||
     (param_1 != 0x400)) {
    bVar4 = false;
  }
  else {
    FUN_00792c64(in_ECX + 0x7c);
    CObList::CObList(local_30,10);
    local_8 = 0;
    iVar3 = FUN_007fdeef(*(undefined4 *)(in_ECX + 0x20),local_30);
    if (0 < iVar3) {
      while (local_2c != (undefined4 *)0x0) {
        if (local_2c == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        puVar1 = (undefined4 *)*local_2c;
        local_14 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarEditBoxButton_00a00d14,
                                      (CObject *)local_2c[2]);
        local_2c = puVar1;
        if ((local_14 != (CObject *)0x0) && (local_14 != in_ECX)) {
          pcVar2 = *(code **)(*(int *)local_14 + 0xd0);
          guard_check_icall(in_ECX + 0x7c);
          (*pcVar2)();
        }
      }
    }
    FUN_007a184a();
    bVar4 = *(int *)(in_ECX + 0x80) == 0;
  }
  return bVar4;
}




/* vtable slots: CMFCToolBarEditBoxButton[7] */
/* 008d2529  FUN_008d2529  339 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008d2529(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar1 = in_ECX[0x1e];
  if (in_ECX[0x14] == 0) {
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
      FUN_00797f20(0);
    }
    pcVar2 = *(code **)(*in_ECX + 0xd8);
    guard_check_icall(0);
    (*pcVar2)();
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    in_ECX[0x21] = param_4;
    if (param_4 == 0) {
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
        FUN_00797f20(0);
        pcVar2 = *(code **)(*in_ECX + 0xd8);
        guard_check_icall(0);
        (*pcVar2)();
      }
      in_ECX[0x19] = 0;
      in_ECX[0x1a] = 0;
      FUN_00881448(param_1,param_2,param_3,0);
    }
    else {
      if (((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) && (in_ECX[0x10] == 0)) {
        FUN_00797f20(4);
        pcVar2 = *(code **)(*in_ECX + 0xd8);
        guard_check_icall(1);
        (*pcVar2)();
      }
      if ((in_ECX[6] == 0) || (*(int *)(in_ECX[0xb] + -0xc) == 0)) {
        in_ECX[0x19] = 0;
        in_ECX[0x1a] = 0;
      }
      else {
        local_10 = in_ECX[0x1c];
        local_18 = 0;
        local_14 = 0;
        local_c = *(int *)(param_3 + 4);
        FUN_007c2378(in_ECX + 0xb,&local_18,0x411);
        in_ECX[0x19] = local_10 - local_18;
        in_ECX[0x1a] = local_c - local_14;
      }
      iVar1 = in_ECX[0x1a];
      iVar3 = *(int *)(param_3 + 4);
      *param_1 = in_ECX[0x1c];
      param_1[1] = iVar1 + iVar3;
    }
  }
  return param_1;
}




/* vtable slots: CMFCToolBarEditBoxButton[10] */
/* 008d267c  FUN_008d267c  384 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008d267c(int param_1)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  int iVar4;
  int iVar5;
  WPARAM wParam;
  int *in_ECX;
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x8d2688;
  FUN_00881617(param_1);
  iVar4 = in_ECX[0x1e];
  if ((iVar4 != 0) && (*(int *)(iVar4 + 0x20) != 0)) {
    pHVar2 = GetParent(*(HWND *)(iVar4 + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    if (pCVar3 == (CWnd *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if ((param_1 != 0) && (*(int *)(pCVar3 + 0x20) == *(int *)(param_1 + 0x20))) goto LAB_008d27ef;
    FUN_00792c64(in_ECX + 0x1f);
    pcVar1 = *(code **)(*(int *)in_ECX[0x1e] + 0x60);
    guard_check_icall();
    (*pcVar1)();
    if ((int *)in_ECX[0x1e] != (int *)0x0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x1e] + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    in_ECX[0x1e] = 0;
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    local_24.left = in_ECX[0x15];
    local_24.top = in_ECX[0x16];
    local_24.right = in_ECX[0x17];
    local_24.bottom = in_ECX[0x18];
    InflateRect(&local_24,-3,-1);
    iVar4 = FUN_007c2511();
    local_24.bottom = *(int *)(iVar4 + 0x1cc) + local_24.top;
    pcVar1 = *(code **)(*in_ECX + 0xcc);
    guard_check_icall(param_1,&local_24);
    iVar4 = (*pcVar1)();
    in_ECX[0x1e] = iVar4;
    if (iVar4 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x30);
      guard_check_icall();
      (*pcVar1)();
      iVar4 = in_ECX[0x1e];
      iVar5 = FUN_007c2511();
      wParam = 0;
      if (iVar5 != -0x11c) {
        wParam = *(WPARAM *)(iVar5 + 0x120);
      }
      SendMessageW(*(HWND *)(iVar4 + 0x20),0x30,wParam,1);
      CStringT<>();
      local_8 = 0;
      FUN_00792c64(&local_28);
      if (*(int *)(local_28 + -0xc) == 0) {
        in_ECX[0x20] = 1;
        FUN_00797ece(*(undefined4 *)(in_ECX + 0x1f));
        in_ECX[0x20] = 0;
      }
      else {
        ATL::CSimpleStringT<wchar_t,0>::operator=
                  ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x1f),
                   (CSimpleStringT<wchar_t,0> *)&local_28);
      }
      FUN_00406b10();
    }
  }
LAB_008d27ef:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[8] */
/* 008d27fd  OnClick  35 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBarEditBoxButton::OnClick(class CWnd *,int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

int __thiscall
CMFCToolBarEditBoxButton::OnClick(CMFCToolBarEditBoxButton *this,CWnd *param_1,int param_2)

{
  uint uVar1;
  
  if (((*(int *)(this + 0x78) != 0) && (*(int *)(*(int *)(this + 0x78) + 0x20) != 0)) &&
     (uVar1 = FUN_00797b3d(), (uVar1 & 0x10000000) != 0)) {
    return 1;
  }
  return 0;
}




/* vtable slots: CMFCToolBarEditBoxButton[6] */
/* 008d28dc  FUN_008d28dc  484 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008d28dc(int *param_1,undefined4 *param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  undefined4 uVar6;
  undefined4 local_34;
  undefined4 local_28;
  int local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (((in_ECX[0x1e] == 0) || (*(int *)(in_ECX[0x1e] + 0x20) == 0)) ||
     (uVar3 = FUN_00797b3d(), (uVar3 & 0x10000000) == 0)) {
    FUN_00881666(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    return;
  }
  bVar2 = true;
  if (param_5 == 0) {
    if ((in_ECX[9] & 0x40000U) != 0) goto LAB_008d29ab;
LAB_008d294b:
    local_34 = 0;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x60);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 != 0) goto LAB_008d294b;
LAB_008d29ab:
    local_34 = 1;
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  pcVar1 = *(code **)(*in_ECX + 0xd4);
  local_c = 0;
  guard_check_icall(&local_18);
  (*pcVar1)();
  piVar5 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar5 + 0x74);
  if ((DAT_00a00d30 == 0) || (in_ECX[0x22] != 0)) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  guard_check_icall(param_1,local_18,local_14,local_10,local_c,local_34,uVar6);
  (*pcVar1)();
  if (in_ECX[6] == 0) {
    return;
  }
  if (param_4 == 0) {
    return;
  }
  if (*(int *)(in_ECX[0xb] + -0xc) == 0) {
    return;
  }
  if (param_5 == 0) {
    if ((in_ECX[9] & 0x40000U) != 0) goto LAB_008d2a27;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x60);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) goto LAB_008d2a27;
  }
  bVar2 = false;
LAB_008d2a27:
  pcVar1 = *(code **)(*param_1 + 0x30);
  if (bVar2) {
    iVar4 = FUN_007c2511();
    uVar6 = *(undefined4 *)(iVar4 + 0x38);
  }
  else if (param_6 == 0) {
    iVar4 = FUN_007c2511();
    uVar6 = *(undefined4 *)(iVar4 + 0x28);
  }
  else {
    uVar6 = FUN_007fe047();
  }
  guard_check_icall(uVar6);
  (*pcVar1)();
  local_28 = *param_2;
  local_24 = ((param_2[3] - in_ECX[0x1a]) + local_c) / 2;
  uStack_20 = param_2[2];
  uStack_1c = param_2[3];
  FUN_007c2378(in_ECX + 0xb,&local_28,0x11);
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[27] */
/* 008d2ac0  FUN_008d2ac0  171 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008d2ac0(CDC *param_1,int *param_2,undefined4 param_3)

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_008822bb(param_1,param_2,param_3);
  iVar2 = (param_2[2] - (iVar2 + 10)) - *param_2;
  local_18.top = param_2[1];
  local_18.right = param_2[2];
  local_18.bottom = param_2[3];
  local_18.left = 8;
  if (7 < iVar2) {
    local_18.left = iVar2;
  }
  local_18.left = local_18.right - local_18.left;
  InflateRect(&local_18,-2,-2);
  iVar2 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar2 != -200) {
    hbr = *(HBRUSH *)(iVar2 + 0xcc);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_18,hbr);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar2 + 0x58),uVar1);
  return param_2[2] - *param_2;
}




/* vtable slots: CMFCToolBarEditBoxButton[23] */
/* 008d2b6b  FUN_008d2b6b  45 bytes, 0 callers */

void FUN_008d2b6b(void)

{
  int iVar1;
  int iVar2;
  WPARAM wParam;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x78);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    iVar2 = FUN_007c2511();
    wParam = 0;
    if (iVar2 != -0x11c) {
      wParam = *(WPARAM *)(iVar2 + 0x120);
    }
    SendMessageW(*(HWND *)(iVar1 + 0x20),0x30,wParam,1);
  }
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[12] */
/* 008d2c34  FUN_008d2c34  115 bytes, 0 callers */

void FUN_008d2c34(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if ((*(int *)(in_ECX + 0x78) != 0) && (*(int *)(*(int *)(in_ECX + 0x78) + 0x20) != 0)) {
    uVar1 = FUN_00797b3d();
    if ((uVar1 & 0x10000000) != 0) {
      iVar2 = FUN_007c2511();
      iVar3 = (((*(int *)(in_ECX + 0x60) - *(int *)(in_ECX + 0x68)) - *(int *)(in_ECX + 0x58)) -
              *(int *)(iVar2 + 0x1cc)) / 2;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      FUN_00797e71(0,*(int *)(in_ECX + 0x54) + 3,*(int *)(in_ECX + 0x58) + iVar3,
                   (*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x54)) + -6,*(int *)(iVar2 + 0x1cc),
                   0x14);
      FUN_00415ec0(0xffffffff,0,0);
    }
  }
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[33] */
/* 008d2cc7  FUN_008d2cc7  88 bytes, 0 callers */

void FUN_008d2cc7(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  if ((in_ECX[0x1e] != 0) && (*(int *)(in_ECX[0x1e] + 0x20) != 0)) {
    if (param_1 == 0) {
      FUN_00797f20(0);
    }
    else {
      FUN_00797f20(4);
      pcVar1 = *(code **)(*in_ECX + 0x30);
      guard_check_icall();
      (*pcVar1)();
    }
    pcVar1 = *(code **)(*in_ECX + 0xd8);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[13] */
/* 008d2d1f  FUN_008d2d1f  44 bytes, 0 callers */

void FUN_008d2d1f(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  in_ECX[0x1c] = param_1;
  in_ECX[0x17] = in_ECX[0x15] + param_1;
  pcVar1 = *(code **)(*in_ECX + 0x30);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[43] */
/* 008d2d4b  FUN_008d2d4b  123 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008d2d4b(void)

{
  int iVar1;
  code *pcVar2;
  BOOL BVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined4 *in_stack_00000010;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8d2d57;
  iVar1 = in_ECX[0x1e];
  if ((iVar1 == 0) || (BVar3 = IsWindow(*(HWND *)(iVar1 + 0x20)), BVar3 == 0)) {
    uVar5 = 0;
  }
  else {
    CStringT<>();
    local_8 = 0;
    pcVar2 = *(code **)(*in_ECX + 0xa8);
    guard_check_icall(local_14);
    iVar4 = (*pcVar2)();
    if (iVar4 == 0) {
      local_14[0] = *in_stack_00000010;
    }
    FUN_007af3f5(iVar1,local_14[0],0,0);
    FUN_00406b10();
    uVar5 = 1;
  }
  return uVar5;
}




/* vtable slots: CMFCToolBarEditBoxButton[2] */
/* 008d2ec9  FUN_008d2ec9  148 bytes, 0 callers */

void FUN_008d2ec9(CArchive *param_1)

{
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *pCVar1;
  int in_ECX;
  
  FUN_008829ae(param_1);
  pCVar1 = (CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)(in_ECX + 0x7c);
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x70));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x74));
    if (*(int *)(in_ECX + 0x78) == 0) {
      Empty();
    }
    else {
      FUN_00792c64(pCVar1);
    }
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>(param_1,pCVar1);
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x8c));
  }
  else {
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x70));
    *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x54) + *(int *)(in_ECX + 0x70);
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x74));
    FUN_0047fc90(pCVar1);
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x8c));
  }
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[46] */
/* 008d2f5d  FUN_008d2f5d  113 bytes, 0 callers */

undefined4 FUN_008d2f5d(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar2 = FUN_00882aa5(param_1,param_2);
  uVar3 = 0;
  if (iVar2 != 0) {
    *(undefined4 *)(param_2 + 0x18) = 0x2a;
    *(undefined4 *)(param_2 + 0x1c) = 0x100000;
    pcVar1 = *(code **)(*in_ECX + 0xa4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 4;
    }
    iVar2 = FUN_008f899d(L"Edit");
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(param_2 + 0x14),L"Edit",iVar2);
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(param_2 + 4),
               (CSimpleStringT<wchar_t,0> *)(in_ECX + 0xb));
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CMFCToolBarEditBoxButton[52] */
/* 008d2fce  FUN_008d2fce  72 bytes, 0 callers */

void FUN_008d2fce(CSimpleStringT<wchar_t,0> *param_1)

{
  CSimpleStringT<wchar_t,0> *this;
  char cVar1;
  int in_ECX;
  
  this = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x7c);
  cVar1 = FUN_00414010(this,param_1);
  if (cVar1 == '\0') {
    ATL::CSimpleStringT<wchar_t,0>::operator=(this,param_1);
    if (*(int *)(in_ECX + 0x78) != 0) {
      *(undefined4 *)(in_ECX + 0x80) = 1;
      FUN_00797ece(*(undefined4 *)this);
      *(undefined4 *)(in_ECX + 0x80) = 0;
    }
  }
  return;
}




/* vtable slots: CMFCToolBarEditBoxButton[35] */
/* 008d3084  FUN_008d3084  96 bytes, 0 callers */

void FUN_008d3084(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  in_ECX[9] = param_1;
  if (in_ECX[0x1e] == 0) {
    return;
  }
  if (*(int *)(in_ECX[0x1e] + 0x20) == 0) {
    return;
  }
  if (DAT_00a127ac == 0) {
LAB_008d30c6:
    if ((in_ECX[9] & 0x40000U) == 0) {
LAB_008d30d3:
      uVar3 = 1;
      goto LAB_008d30d6;
    }
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x60);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      if (DAT_00a127ac == 0) goto LAB_008d30c6;
      goto LAB_008d30d3;
    }
  }
  uVar3 = 0;
LAB_008d30d6:
  FUN_007979e8(uVar3);
  return;
}



