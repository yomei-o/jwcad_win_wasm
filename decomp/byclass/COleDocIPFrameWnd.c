/* COleDocIPFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDocIPFrameWnd[117], COleDocIPFrameWndEx[117], COleIPFrameWnd[117], COleIPFrameWndEx[117] */
/* 007cfce9  FUN_007cfce9  136 bytes, 0 callers */

void FUN_007cfce9(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0x52] != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1d8);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      FUN_0078ec2b(in_ECX[0x52],iVar2,in_ECX[100]);
      pcVar1 = *(code **)(*(int *)in_ECX[0x4e] + 0x2c);
      guard_check_icall((int *)in_ECX[0x4e],in_ECX[0x52]);
      (*pcVar1)();
      DestroyMenu((HMENU)in_ECX[0x52]);
      in_ECX[0x52] = 0;
      if ((HOLEMENU)in_ECX[0x59] != (HOLEMENU)0x0) {
        OleDestroyMenuDescriptor((HOLEMENU)in_ECX[0x59]);
        in_ECX[0x59] = 0;
      }
      in_ECX[100] = 0;
    }
  }
  return;
}




/* vtable slots: COleDocIPFrameWnd[118], COleDocIPFrameWndEx[118], COleIPFrameWnd[118], COleIPFrameWndEx[118] */
/* 007cfd71  FUN_007cfd71  33 bytes, 0 callers */

undefined4 FUN_007cfd71(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x16c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  return *(undefined4 *)(*(int *)(iVar2 + 0x28) + 0x4c);
}




/* vtable slots: COleDocIPFrameWnd[90], COleIPFrameWnd[90] */
/* 007cfd9e  FUN_007cfd9e  102 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_007cfd9e(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(uint *)(in_ECX + 0xd0) = param_1;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar1 = FUN_00791f4f(0,0,param_2,&local_18,param_3,param_1,param_4);
  if (iVar1 != 0) {
    LoadAccelTable(param_1 & 0xffff);
  }
  return iVar1 != 0;
}




/* vtable slots: COleDocIPFrameWnd[112], COleIPFrameWnd[112] */
/* 007cfefb  FUN_007cfefb  39 bytes, 0 callers */

void FUN_007cfefb(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1c4);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: COleDocIPFrameWnd[119], COleDocIPFrameWndEx[119], COleIPFrameWnd[119], COleIPFrameWndEx[119] */
/* 007d004a  FUN_007d004a  50 bytes, 0 callers */

void FUN_007d004a(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x16c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (*(int *)(iVar2 + 0x15c) == 0) {
    FUN_007cf86d();
    return;
  }
  return;
}




/* vtable slots: COleDocIPFrameWnd[115], COleDocIPFrameWndEx[115], COleIPFrameWnd[115], COleIPFrameWndEx[115] */
/* 007d0183  FUN_007d0183  174 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007d0183(int param_1,undefined2 *param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined2 *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7d018f;
  if (in_ECX[0x4e] == 0) goto LAB_007d0214;
  CStringT<>();
  local_8 = 0;
  if (param_2 == (undefined2 *)0x0) {
    if (param_1 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x174);
      guard_check_icall(param_1,local_14);
      (*pcVar1)();
      param_2 = local_14[0];
      if (local_14[0] != (undefined2 *)0x0) goto LAB_007d01d9;
    }
    param_2 = &DAT_00956338;
  }
LAB_007d01d9:
  piVar2 = (int *)in_ECX[0x4e];
  pcVar1 = *(code **)(*piVar2 + 0x30);
  puVar4 = (undefined4 *)CStringT<>(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  guard_check_icall(piVar2,*puVar4);
  (*pcVar1)();
  FUN_00406b10();
  FUN_00406b10();
LAB_007d0214:
  iVar3 = in_ECX[0x36];
  in_ECX[0x36] = param_1;
  in_ECX[0x35] = param_1;
  return iVar3;
}




/* vtable slots: COleDocIPFrameWnd[67], COleIPFrameWnd[67] */
/* 007d02dc  FUN_007d02dc  143 bytes, 0 callers */

undefined4 FUN_007d02dc(LPMSG param_1)

{
  code *pcVar1;
  int iVar2;
  HACCEL hAccelSrc;
  BOOL BVar3;
  HRESULT HVar4;
  undefined4 uVar5;
  int *in_ECX;
  UINT *pUVar6;
  tagOIFI *ptVar7;
  LPMSG lpMsg;
  WORD *lpwCmd;
  tagOIFI local_1c;
  int *local_8;
  
  local_8 = in_ECX;
  iVar2 = FUN_0079c475(param_1);
  if (iVar2 == 0) {
    if (param_1->message - 0x100 < 10) {
      pcVar1 = *(code **)(*in_ECX + 0x1ac);
      guard_check_icall();
      hAccelSrc = (HACCEL)(*pcVar1)();
      if (hAccelSrc != (HACCEL)0x0) {
        lpwCmd = (WORD *)0x0;
        lpMsg = param_1;
        iVar2 = CopyAcceleratorTableW(hAccelSrc,(LPACCEL)0x0,0);
        BVar3 = IsAccelerator(hAccelSrc,iVar2,lpMsg,lpwCmd);
        if (BVar3 != 0) goto LAB_007d0361;
      }
      pUVar6 = (UINT *)(in_ECX + 0x49);
      ptVar7 = &local_1c;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        ptVar7->cb = *pUVar6;
        pUVar6 = pUVar6 + 1;
        ptVar7 = (tagOIFI *)&ptVar7->fMDIApp;
      }
      HVar4 = OleTranslateAccelerator((LPOLEINPLACEFRAME)local_8[0x4e],&local_1c,param_1);
      if (HVar4 == 0) goto LAB_007d0361;
    }
    uVar5 = 0;
  }
  else {
LAB_007d0361:
    uVar5 = 1;
  }
  return uVar5;
}




/* vtable slots: COleDocIPFrameWnd[114], COleDocIPFrameWndEx[114], COleIPFrameWnd[114], COleIPFrameWndEx[114] */
/* 007d05d4  FUN_007d05d4  91 bytes, 0 callers */

void FUN_007d05d4(RECT *param_1,RECT *param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX[0x62] == 0) {
    in_ECX[0x62] = 1;
    CopyRect((LPRECT)(in_ECX + 0x5a),param_1);
    CopyRect((LPRECT)(in_ECX + 0x5e),param_2);
    pcVar1 = *(code **)(*in_ECX + 0x178);
    guard_check_icall(1);
    (*pcVar1)();
    in_ECX[0x62] = 0;
  }
  return;
}




/* vtable slots: COleDocIPFrameWnd[1] */
/* 0089a169  FUN_0089a169  57 bytes, 0 callers */

void FUN_0089a169(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = COleDocIPFrameWnd::vftable;
  FUN_007cfacd();
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




/* vtable slots: COleDocIPFrameWnd[116], COleDocIPFrameWndEx[116] */
/* 0089a1a2  FUN_0089a1a2  193 bytes, 0 callers */

bool FUN_0089a1a2(void)

{
  LPOLEMENUGROUPWIDTHS lpMenuWidths;
  code *pcVar1;
  int iVar2;
  HMENU pHVar3;
  int iVar4;
  HOLEMENU pvVar5;
  int *in_ECX;
  bool bVar6;
  
  pcVar1 = *(code **)(*in_ECX + 0x1d8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  pHVar3 = CreateMenu();
  in_ECX[0x52] = (int)pHVar3;
  bVar6 = false;
  if (pHVar3 != (HMENU)0x0) {
    lpMenuWidths = (LPOLEMENUGROUPWIDTHS)(in_ECX + 0x53);
    _memset(lpMenuWidths,0,0x18);
    pcVar1 = *(code **)(*(int *)in_ECX[0x4e] + 0x24);
    guard_check_icall((int *)in_ECX[0x4e],in_ECX[0x52],lpMenuWidths);
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      if (iVar2 == 0) {
        bVar6 = true;
      }
      else {
        iVar2 = FUN_0078e96e(in_ECX[0x52],iVar2,lpMenuWidths,1,1);
        in_ECX[100] = iVar2;
        pvVar5 = OleCreateMenuDescriptor((HMENU)in_ECX[0x52],lpMenuWidths);
        in_ECX[0x59] = (int)pvVar5;
        bVar6 = pvVar5 != (HOLEMENU)0x0;
      }
    }
    else {
      DestroyMenu((HMENU)in_ECX[0x52]);
      in_ECX[0x52] = 0;
      bVar6 = false;
    }
  }
  return bVar6;
}




/* vtable slots: COleDocIPFrameWnd[10] */
/* 0089a293  FUN_0089a293  6 bytes, 0 callers */

undefined ** FUN_0089a293(void)

{
  return &PTR_FUN_0099dd44;
}




/* vtable slots: COleDocIPFrameWnd[0] */
/* 0089a299  FUN_0089a299  6 bytes, 0 callers */

undefined ** FUN_0089a299(void)

{
  return &PTR_s_COleDocIPFrameWnd_0099db18;
}




/* vtable slots: COleDocIPFrameWnd[94] */
/* 0089a29f  FUN_0089a29f  436 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0089a29f(void)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  int *piVar4;
  CWnd *in_ECX;
  undefined4 local_4c;
  tagRECT local_48;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x16c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if ((iVar2 == 0) || (local_4c = 0, *(int *)(iVar2 + 0x15c) == 0)) {
    local_4c = 1;
  }
  pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
  CWnd::FromHandle(pHVar3);
  local_28 = 0;
  local_24 = 0;
  local_20 = 0x3fffffff;
  local_1c = 0x3fffffff;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_00794e3f(0,0xffff,0xe900,1,&local_38,&local_28,1);
  local_18.left = *(int *)(in_ECX + 0x168) - local_38;
  local_18.top = *(int *)(in_ECX + 0x16c) - local_34;
  local_18.bottom = *(int *)(in_ECX + 0x174) + (0x3fffffff - local_2c);
  local_18.right = *(int *)(in_ECX + 0x170) + (0x3fffffff - local_30);
  piVar4 = (int *)FUN_00797a56(0xe900);
  if (piVar4 != (int *)0x0) {
    local_28 = *(int *)(in_ECX + 0x168);
    local_24 = *(int *)(in_ECX + 0x16c);
    local_20 = *(int *)(in_ECX + 0x170);
    local_1c = *(int *)(in_ECX + 0x174);
    pcVar1 = *(code **)(*piVar4 + 0x68);
    guard_check_icall(&local_28,local_4c);
    (*pcVar1)();
    local_18.left = local_18.left + (local_28 - *(int *)(in_ECX + 0x168));
    local_18.top = local_18.top + (local_24 - *(int *)(in_ECX + 0x16c));
    local_18.right = local_18.right + (local_20 - *(int *)(in_ECX + 0x170));
    local_18.bottom = local_18.bottom + (local_1c - *(int *)(in_ECX + 0x174));
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x68);
  guard_check_icall(&local_18,local_4c);
  (*pcVar1)();
  local_48.left = 0;
  local_48.top = 0;
  local_48.right = 0;
  local_48.bottom = 0;
  IntersectRect(&local_48,&local_18,(RECT *)(in_ECX + 0x178));
  FUN_0079129f(0,*(undefined4 *)(in_ECX + 0x20),&local_48);
  FUN_0079e8b8(&local_18);
  CWnd::ScreenToClient(in_ECX,&local_18);
  FUN_00794e3f(0,0xffff,0xe900,0,0,&local_18,1);
  return;
}



