/* COleIPFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleIPFrameWnd[1] */
/* 007cfbbb  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall COleIPFrameWnd::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall COleIPFrameWnd::_scalar_deleting_destructor_(COleIPFrameWnd *this,uint param_1)

{
  FUN_007cfacd();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x198);
    }
  }
  return this;
}




/* vtable slots: COleIPFrameWnd[116], COleIPFrameWndEx[116] */
/* 007cfbee  FUN_007cfbee  203 bytes, 0 callers */

bool FUN_007cfbee(void)

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
        iVar2 = FUN_0078e96e(in_ECX[0x52],iVar2,lpMenuWidths,1,in_ECX[0x58] != 0);
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




/* vtable slots: COleIPFrameWnd[10] */
/* 007cfd92  FUN_007cfd92  6 bytes, 0 callers */

undefined ** FUN_007cfd92(void)

{
  return &PTR_FUN_00986668;
}




/* vtable slots: COleIPFrameWnd[0] */
/* 007cfd98  FUN_007cfd98  6 bytes, 0 callers */

undefined ** FUN_007cfd98(void)

{
  return &PTR_s_COleIPFrameWnd_009860e4;
}




/* vtable slots: COleIPFrameWnd[94] */
/* 007d0427  FUN_007d0427  429 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d0427(void)

{
  code *pcVar1;
  HWND pHVar2;
  int iVar3;
  int *piVar4;
  CWnd *in_ECX;
  undefined4 local_50;
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
  pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
  CWnd::FromHandle(pHVar2);
  local_50 = 0;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x16c);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x15c) != 0)) {
    local_50 = 1;
  }
  local_28 = 0;
  local_24 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_20 = 0x3fffffff;
  local_1c = 0x3fffffff;
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
    guard_check_icall(&local_28,1);
    (*pcVar1)();
    local_18.left = local_18.left + (local_28 - *(int *)(in_ECX + 0x168));
    local_18.top = local_18.top + (local_24 - *(int *)(in_ECX + 0x16c));
    local_18.right = local_18.right + (local_20 - *(int *)(in_ECX + 0x170));
    local_18.bottom = local_18.bottom + (local_1c - *(int *)(in_ECX + 0x174));
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x68);
  guard_check_icall(&local_18,local_50);
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



