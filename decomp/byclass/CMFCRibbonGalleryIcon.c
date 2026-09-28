/* CMFCRibbonGalleryIcon -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonGalleryIcon[1] */
/* 008af0e0  FUN_008af0e0  51 bytes, 0 callers */

void FUN_008af0e0(byte param_1)

{
  FUN_00865d91();
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




/* vtable slots: CMFCRibbonGalleryIcon[90] */
/* 008af414  CopyFrom  58 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCRibbonGalleryIcon::CopyFrom(class CMFCRibbonBaseElement
   const &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonGalleryIcon::CopyFrom(CMFCRibbonGalleryIcon *this,CMFCRibbonBaseElement *param_1)

{
  FUN_0086612f(param_1);
  *(undefined4 *)(this + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
  *(undefined4 *)(this + 0x1c4) = *(undefined4 *)(param_1 + 0x1c4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  return;
}




/* vtable slots: CMFCRibbonGalleryIcon[49] */
/* 008af6d9  FUN_008af6d9  44 bytes, 0 callers */

undefined4 FUN_008af6d9(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x294);
  guard_check_icall(param_1);
  (*pcVar1)();
  return param_1;
}




/* vtable slots: CMFCRibbonGalleryIcon[41] */
/* 008afb39  FUN_008afb39  41 bytes, 0 callers */

void FUN_008afb39(void)

{
  code *pcVar1;
  CMFCRibbonBaseElement *in_ECX;
  
  if (*(int **)(in_ECX + 0x1c4) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0xa4);
    guard_check_icall();
    (*pcVar1)();
    return;
  }
  CMFCRibbonBaseElement::GetParentWnd(in_ECX);
  return;
}




/* vtable slots: CMFCRibbonGalleryIcon[109] */
/* 008afbb9  FUN_008afbb9  24 bytes, 0 callers */

undefined4 FUN_008afbb9(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1c4) != 0) {
    return *(undefined4 *)(*(int *)(in_ECX + 0x1c4) + 0xa4);
  }
  return *(undefined4 *)(in_ECX + 0xa4);
}




/* vtable slots: CMFCRibbonGalleryIcon[62] */
/* 008afd2c  FUN_008afd2c  69 bytes, 0 callers */

void FUN_008afd2c(int *param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x28c);
  guard_check_icall(param_1);
  (*pcVar1)();
  if (*(int *)(*(int *)(in_ECX + 0x1c4) + 0x358) == 0) {
    *param_1 = *param_1 + 8;
    param_1[1] = param_1[1] + 8;
  }
  return;
}




/* vtable slots: CMFCRibbonGalleryIcon[0] */
/* 008afd77  FUN_008afd77  6 bytes, 0 callers */

undefined ** FUN_008afd77(void)

{
  return &PTR_s_CMFCRibbonGalleryIcon_009a0628;
}




/* vtable slots: CMFCRibbonGalleryIcon[48] */
/* 008afd7d  FUN_008afd7d  44 bytes, 0 callers */

undefined4 FUN_008afd7d(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x290);
  guard_check_icall(param_1);
  (*pcVar1)();
  return param_1;
}




/* vtable slots: CMFCRibbonGalleryIcon[83] */
/* 008afe72  FUN_008afe72  26 bytes, 0 callers */

undefined4 FUN_008afe72(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x1c8) == -1) || (*(int *)(in_ECX + 0x1c8) == -2)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonGalleryIcon[129] */
/* 008afecf  FUN_008afecf  45 bytes, 0 callers */

bool FUN_008afecf(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x1c4) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x29c);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    return iVar2 == 0;
  }
  return true;
}




/* vtable slots: CMFCRibbonGalleryIcon[108] */
/* 008aff09  FUN_008aff09  43 bytes, 0 callers */

undefined4 FUN_008aff09(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x1b0);
  guard_check_icall(param_1);
  (*pcVar1)();
  return 1;
}




/* vtable slots: CMFCRibbonGalleryIcon[84] */
/* 008b0138  FUN_008b0138  47 bytes, 0 callers */

undefined4 FUN_008b0138(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xd4) != 0) {
    return 0;
  }
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x288);
  guard_check_icall();
  (*pcVar1)();
  return 1;
}




/* vtable slots: CMFCRibbonGalleryIcon[153] */
/* 008b0167  FUN_008b0167  245 bytes, 0 callers */

void FUN_008b0167(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  CMFCRibbonGallery *this;
  int in_ECX;
  int *local_8;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x284);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x288);
    iVar2 = *(int *)(in_ECX + 0x8c);
    if (*(int *)(in_ECX + 0x8c) == 0) {
      iVar2 = in_ECX;
    }
    guard_check_icall(iVar2);
    (*pcVar1)();
    if (-1 < *(int *)(in_ECX + 0x1c8)) {
      local_8 = *(int **)(in_ECX + 0x94);
      if ((local_8 == (int *)0x0) &&
         (local_8 = *(int **)(*(int *)(in_ECX + 0x1c4) + 0x94), local_8 == (int *)0x0)) {
        FUN_00863dc7(0);
      }
      else {
        this = *(CMFCRibbonGallery **)(in_ECX + 0x1c4);
        if (*(int *)(this + 0x32c) != 0) {
          CMFCRibbonGallery::SetNotifyParentID(this,1);
          this = *(CMFCRibbonGallery **)(in_ECX + 0x1c4);
        }
        *(undefined4 *)(this + 0xcc) = 0;
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x1c4) + 0x224);
        guard_check_icall(0);
        (*pcVar1)();
        pcVar1 = *(code **)(*local_8 + 0x450);
        guard_check_icall(*(undefined4 *)(in_ECX + 0x1c4),param_1,param_2);
        (*pcVar1)();
      }
    }
  }
  return;
}




/* vtable slots: CMFCRibbonGalleryIcon[95] */
/* 008b04ec  FUN_008b04ec  463 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b04ec(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  byte bVar5;
  undefined4 local_30;
  RECT *local_2c;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = (RECT *)(in_ECX + 0x1d);
  BVar2 = IsRectEmpty(local_2c);
  if (BVar2 == 0) {
    if (in_ECX[0x72] < 0) {
      piVar4 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar4 + 0x27c);
      guard_check_icall(param_1);
      (*pcVar1)();
      iVar3 = in_ECX[0x72];
      if (iVar3 == -1) {
        bVar5 = 7;
      }
      else {
        bVar5 = -(iVar3 != -2) & 0x1d;
      }
      local_28.left = local_2c->left;
      local_28.top = local_2c->top;
      local_28.right = local_2c->right;
      local_c = local_2c->bottom;
      if (iVar3 == -3) {
        if ((local_28.right - local_28.left) + 2 < local_c - local_28.top) {
          local_c = local_28.top + 2 + (local_28.right - local_28.left);
        }
      }
      local_28.bottom = local_c;
      local_18 = local_28.left;
      local_14 = local_28.top;
      local_10 = local_28.right;
      OffsetRect(&local_28,0,1);
      local_30 = 0;
      local_2c = (RECT *)0x0;
      FUN_00814d1c(param_1,bVar5,&local_28,3,&local_30);
      local_30 = 0;
      local_2c = (RECT *)0x0;
      FUN_00814d1c(param_1,bVar5,&local_18,in_ECX[0x35] != 0,&local_30);
    }
    else {
      pcVar1 = *(code **)(*(int *)in_ECX[0x71] + 0xdc);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        local_2c = (RECT *)in_ECX[0x71];
        if ((*(int *)((int)local_2c + 0x368) != 0) || (*(int *)((int)local_2c + 0x364) == 0)) {
          pcVar1 = *(code **)(*in_ECX + 0x270);
          guard_check_icall(param_1);
          (*pcVar1)();
          local_2c = (RECT *)in_ECX[0x71];
        }
        pcVar1 = *(code **)(local_2c->left + 0x2a4);
        guard_check_icall(param_1,in_ECX[0x1d],in_ECX[0x1e],in_ECX[0x1f],in_ECX[0x20],in_ECX[0x72]);
        (*pcVar1)();
        if ((*(int *)(in_ECX[0x71] + 0x368) != 0) || (*(int *)(in_ECX[0x71] + 0x364) == 0)) {
          pcVar1 = *(code **)(*in_ECX + 0x274);
          guard_check_icall(param_1);
          (*pcVar1)();
        }
      }
    }
  }
  return;
}




/* vtable slots: CMFCRibbonGalleryIcon[136] */
/* 008b0767  FUN_008b0767  267 bytes, 0 callers */

void FUN_008b0767(int param_1)

{
  code *pcVar1;
  int *piVar2;
  CObject *pCVar3;
  int *in_ECX;
  int iVar4;
  tagPOINT local_c;
  
  local_c.x = (LONG)in_ECX;
  local_c.y = (LONG)in_ECX;
  if (param_1 == 0) {
    local_c.x = 0;
    local_c.y = 0;
    GetCursorPos(&local_c);
    if (in_ECX[0x25] == 0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x71] + 0xa4);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      ScreenToClient(*(HWND *)(iVar4 + 0x20),&local_c);
      pcVar1 = *(code **)(*(int *)in_ECX[0x71] + 300);
      guard_check_icall(local_c.x,local_c.y);
      pCVar3 = (CObject *)(*pcVar1)();
    }
    else {
      ScreenToClient(*(HWND *)(in_ECX[0x25] + 0x20),&local_c);
      pcVar1 = *(code **)(*in_ECX + 0x130);
      guard_check_icall();
      piVar2 = (int *)(*pcVar1)();
      if (piVar2 == (int *)0x0) goto LAB_008b083d;
      pcVar1 = *(code **)(*piVar2 + 0xb8);
      guard_check_icall(local_c.x,local_c.y,0);
      pCVar3 = (CObject *)(*pcVar1)();
    }
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,pCVar3);
    if ((pCVar3 != (CObject *)0x0) && (-1 < *(int *)(pCVar3 + 0x1c8))) {
      return;
    }
  }
LAB_008b083d:
  iVar4 = in_ECX[0x72];
  if (-1 < iVar4) {
    pcVar1 = *(code **)(*(int *)in_ECX[0x71] + 0x200);
    if (param_1 == 0) {
      iVar4 = -1;
    }
    guard_check_icall(iVar4);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonGalleryIcon[132] */
/* 008b087c  FUN_008b087c  95 bytes, 0 callers */

void FUN_008b087c(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX[0x72] == -3) {
    in_ECX[0x34] = 0;
    in_ECX[0x32] = 0;
    pcVar1 = *(code **)(*in_ECX + 0x1b8);
    guard_check_icall();
    (*pcVar1)();
    pcVar1 = *(code **)(*(int *)in_ECX[0x71] + 0x13c);
    guard_check_icall();
    (*pcVar1)();
  }
  else {
    FUN_00869675(param_1,param_2);
  }
  return;
}




/* vtable slots: CMFCRibbonGalleryIcon[43] */
/* 008b0f86  FUN_008b0f86  431 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008b0f86(undefined4 param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  code *pcVar1;
  wchar_t *pwVar2;
  int iVar3;
  CSimpleStringT<wchar_t,0> *pCVar4;
  int *in_ECX;
  UINT in_stack_ffffffd8;
  LPSTR in_stack_ffffffdc;
  int in_stack_ffffffe0;
  undefined1 local_18 [4];
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8b0f92;
  FUN_00869cab(param_1,param_2);
  iVar3 = in_ECX[0x72];
  if (iVar3 == -3) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x40000000;
    *(undefined4 *)(param_2 + 0x18) = 0x3a;
    iVar3 = FUN_008f899d(L"Open");
    ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 0x14,L"Open",iVar3);
    pcVar1 = *(code **)(*in_ECX + 0xe4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 8;
      iVar3 = FUN_008f899d(L"Close");
      ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 0x14,L"Close",iVar3);
    }
  }
  else if ((iVar3 != -2) && (iVar3 != -1)) {
    *(undefined4 *)(param_2 + 0x1c) = 0x300000;
    pcVar1 = *(code **)(*in_ECX + 0xd0);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 6;
    }
    pcVar1 = *(code **)(*in_ECX + 0xe0);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x10;
    }
    pcVar1 = *(code **)(*in_ECX + 0xc0);
    guard_check_icall(local_14);
    pCVar4 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
    local_8 = 1;
    ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,pCVar4);
    local_8 = 0xffffffff;
    FUN_00406b10();
    *(undefined4 *)(param_2 + 0x18) = 0x22;
    iVar3 = FUN_008f899d(L"DoubleClick");
    ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 0x14,L"DoubleClick",iVar3);
    return 1;
  }
  if (in_ECX[0x72] == -3) {
    if (in_ECX[0x71] != 0) {
      pwVar2 = *(wchar_t **)(in_ECX[0x71] + 0x60);
      if (pwVar2 == (wchar_t *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_008f899d(pwVar2);
      }
      ATL::CSimpleStringT<wchar_t,0>::SetString(param_2,pwVar2,iVar3);
    }
  }
  else {
    FID_conflict_LoadStringA
              ((HINSTANCE)((in_ECX[0x72] != -1) + 0x42db),in_stack_ffffffd8,in_stack_ffffffdc,
               in_stack_ffffffe0);
  }
  pcVar1 = *(code **)(*in_ECX + 0xc0);
  guard_check_icall(local_18);
  pCVar4 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
  local_8 = 0;
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2 + 4,pCVar4);
  FUN_00406b10();
  return 1;
}



