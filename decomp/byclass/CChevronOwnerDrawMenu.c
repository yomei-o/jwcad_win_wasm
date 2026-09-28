/* CChevronOwnerDrawMenu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CChevronOwnerDrawMenu[1] */
/* 007b5cea  FUN_007b5cea  48 bytes, 0 callers */

void FUN_007b5cea(byte param_1)

{
  FUN_007994b2();
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




/* vtable slots: CChevronOwnerDrawMenu[3] */
/* 007b5dc2  FUN_007b5dc2  1290 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007b5dc2(int param_1)

{
  CDC *pCVar1;
  BOOL BVar2;
  int iVar3;
  HDC pHVar4;
  int iVar5;
  DWORD DVar6;
  DWORD DVar7;
  void *pvVar8;
  code *pcVar9;
  LONG *pLVar10;
  LONG *pLVar11;
  undefined1 local_d4 [4];
  int local_d0;
  int local_cc;
  tagMENUITEMINFOW local_bc;
  CDC local_8c [16];
  CDC local_7c [4];
  HDC__ *local_78;
  undefined4 local_6c;
  undefined1 local_68 [4];
  int local_64;
  LONG *local_60;
  int local_5c;
  BOOL local_58;
  int local_54;
  int local_50;
  LPCWSTR local_4c;
  DWORD local_48;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc4;
  local_8 = 0x7b5dd1;
  local_54 = param_1;
  CStringT<>(&DAT_00956338);
  local_8 = 0;
  pCVar1 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  pcVar9 = *(code **)(*(int *)pCVar1 + 0x1c);
  guard_check_icall();
  local_6c = (*pcVar9)();
  _memset(&local_bc,0,0x30);
  iVar3 = local_64;
  local_58 = 0;
  local_bc.cbSize = 0x30;
  local_bc.fMask = 0x40;
  BVar2 = GetMenuItemInfoW(*(HMENU *)(local_64 + 4),*(UINT *)(param_1 + 8),0,&local_bc);
  if (BVar2 != 0) {
    local_bc.dwTypeData =
         (LPWSTR)ATL::CSimpleStringT<char,0>::PrepareWrite
                           ((CSimpleStringT<char,0> *)&local_4c,local_bc.cch);
    local_bc.cch = local_bc.cch + 1;
    local_58 = GetMenuItemInfoW(*(HMENU *)(iVar3 + 4),*(UINT *)(param_1 + 8),0,&local_bc);
    ReleaseBuffer(0xffffffff);
  }
  pLVar11 = *(LONG **)(param_1 + 0x2c);
  local_34.bottom = local_54 + 0x1c;
  local_60 = pLVar11;
  CopyRect(&local_44,(RECT *)local_34.bottom);
  if ((pLVar11 == (LONG *)0x0) || (iVar3 = FUN_0079d98a(&PTR_s_CBitmap_0097dfac), iVar3 == 0)) {
    local_5c = 0;
    local_48 = GetSystemMetrics(0x32);
    local_d0 = GetSystemMetrics(0x31);
  }
  else {
    local_5c = 1;
    GetObjectW((HANDLE)pLVar11[1],0x18,local_d4);
    local_48 = local_cc;
  }
  local_24.left = 0;
  local_24.bottom = ((local_44.bottom - local_44.top) / 2 - (int)local_48 / 2) + local_44.top;
  local_24.top = local_24.bottom + -1;
  local_24.bottom = local_48 + local_24.bottom;
  local_24.right = local_d0 + 1;
  local_50 = local_d0;
  local_48 = GetSysColor(4);
  CDC::CDC(local_8c);
  local_8 = CONCAT31(local_8._1_3_,1);
  pHVar4 = CreateCompatibleDC((HDC)0x0);
  FUN_0079e84a(pHVar4);
  pcVar9 = *(code **)(*(int *)pCVar1 + 0x28);
  guard_check_icall(local_64 + 8);
  (*pcVar9)();
  iVar5 = FUN_00566800(local_68,&local_4c);
  iVar3 = local_54;
  local_50 = *(int *)(iVar5 + 4);
  if ((*(byte *)(local_54 + 0x10) & 1) == 0) {
    FUN_007a506d(local_34.bottom,local_48);
    pcVar9 = *(code **)(*(int *)pCVar1 + 0x2c);
    guard_check_icall(local_48);
    (*pcVar9)();
    if ((*(uint *)(local_54 + 0x10) & 2) == 0) {
      if ((local_5c != 0) && ((*(uint *)(local_54 + 0x10) & 8) != 0)) {
        DVar6 = GetSysColor(0x14);
        DVar7 = GetSysColor(0x10);
        FUN_007a4cbf(local_24.left,local_24.top,(local_24.right - local_24.left) + 1,
                     (local_24.bottom - local_24.top) + 1,DVar7,DVar6);
      }
      if (local_58 != 0) {
        pcVar9 = *(code **)(*(int *)pCVar1 + 0x2c);
        guard_check_icall(local_48);
        (*pcVar9)();
        iVar3 = 7;
        pcVar9 = *(code **)(*(int *)pCVar1 + 0x30);
        goto LAB_007b6187;
      }
    }
    else {
      pcVar9 = *(code **)(*(int *)pCVar1 + 0x30);
      DVar6 = GetSysColor(0x14);
      guard_check_icall(DVar6);
      (*pcVar9)();
      FUN_0079f0b8(1);
      if (local_58 != 0) {
        iVar3 = local_50 / 2;
        ExtTextOutW(*(HDC *)(pCVar1 + 4),local_24.right + 4,
                    local_24.top + 1 + ((local_24.bottom - local_24.top) / 2 - iVar3),2,(RECT *)0x0,
                    local_4c,*(UINT *)(local_4c + -6),(INT *)0x0);
        pcVar9 = *(code **)(*(int *)pCVar1 + 0x30);
        DVar6 = GetSysColor(0x11);
        guard_check_icall(DVar6);
        (*pcVar9)();
        ExtTextOutW(*(HDC *)(pCVar1 + 4),local_24.right + 3,
                    ((local_24.bottom - local_24.top) / 2 - iVar3) + local_24.top,0,(RECT *)0x0,
                    local_4c,*(UINT *)(local_4c + -6),(INT *)0x0);
        pLVar11 = local_60;
      }
    }
  }
  else {
    CopyRect(&local_34,(RECT *)(local_54 + 0x1c));
    local_34.left = local_24.right + 2;
    DVar6 = GetSysColor(0xd);
    FUN_007a506d(&local_34,DVar6);
    if ((local_5c != 0) && ((*(byte *)(iVar3 + 0x10) & 10) == 0)) {
      DVar6 = GetSysColor(0x10);
      DVar7 = GetSysColor(0x14);
      FUN_007a4cbf(local_24.left,local_24.top,(local_24.right - local_24.left) + 1,
                   (local_24.bottom - local_24.top) + 1,DVar7,DVar6);
    }
    if (local_58 != 0) {
      pcVar9 = *(code **)(*(int *)pCVar1 + 0x2c);
      DVar6 = GetSysColor(0xd);
      guard_check_icall(DVar6);
      (*pcVar9)();
      pcVar9 = *(code **)(*(int *)pCVar1 + 0x30);
      DVar6 = local_48;
      if ((*(byte *)(local_54 + 0x10) & 2) == 0) {
        iVar3 = 0xe;
LAB_007b6187:
        DVar6 = GetSysColor(iVar3);
      }
      guard_check_icall(DVar6);
      (*pcVar9)();
      ExtTextOutW(*(HDC *)(pCVar1 + 4),local_24.right + 3,
                  ((local_24.bottom - local_24.top) / 2 - local_50 / 2) + local_24.top,2,(RECT *)0x0
                  ,local_4c,*(UINT *)(local_4c + -6),(INT *)0x0);
    }
  }
  if (local_5c == 0) goto LAB_007b629a;
  local_34.bottom = 0;
  local_34.right = (LONG)CBitmap::vftable;
  local_8._0_1_ = 2;
  if ((*(uint *)(local_54 + 0x10) & 2) == 0) {
    pLVar10 = local_60;
    if ((*(uint *)(local_54 + 0x10) & 8) != 0) {
      FUN_0079e20c(pLVar11,&local_34.right,local_48,0xffffff);
      goto LAB_007b6202;
    }
  }
  else {
    FUN_0079e561(pLVar11,&local_34.right,local_48);
LAB_007b6202:
    pLVar10 = &local_34.right;
  }
  CDC::CDC(local_7c);
  local_8._0_1_ = 3;
  pHVar4 = CreateCompatibleDC((HDC)0x0);
  FUN_0079e84a(pHVar4);
  pvVar8 = (void *)0x0;
  if (pLVar10 != (LONG *)0x0) {
    pvVar8 = (void *)pLVar10[1];
  }
  CDC::SelectGdiObject(local_78,pvVar8);
  InflateRect(&local_24,-1,-1);
  BitBlt(*(HDC *)(pCVar1 + 4),local_24.left,local_24.top,local_24.right,local_24.bottom,local_78,0,0
         ,0xcc0020);
  FUN_0079e053();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_34.right = (LONG)CBitmap::vftable;
  FUN_00416100();
LAB_007b629a:
  pcVar9 = *(code **)(*(int *)pCVar1 + 0x20);
  guard_check_icall(local_6c);
  (*pcVar9)();
  FUN_0079e053();
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CChevronOwnerDrawMenu[0], CMenu[0] */
/* 007b635a  FUN_007b635a  6 bytes, 0 callers */

undefined ** FUN_007b635a(void)

{
  return &PTR_s_CMenu_00981130;
}




/* vtable slots: CChevronOwnerDrawMenu[4] */
/* 007b6360  FUN_007b6360  324 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007b6360(int param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  tagMENUITEMINFOW local_68;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  int local_20;
  int local_1c;
  CSimpleStringT<char,0> local_18 [4];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x7b636c;
  local_1c = in_ECX;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar5 = GetSystemMetrics(0x32);
    local_34 = GetSystemMetrics(0x31);
  }
  else {
    GetObjectW(*(HANDLE *)(*(int *)(param_1 + 0x14) + 4),0x18,local_38);
    iVar5 = local_30;
  }
  iVar5 = iVar5 + 2;
  local_14 = local_34 + 2;
  CStringT<>();
  local_8 = 0;
  _memset(&local_68,0,0x30);
  local_68.cbSize = 0x30;
  local_68.fMask = 0x40;
  BVar1 = GetMenuItemInfoW(*(HMENU *)(in_ECX + 4),*(UINT *)(param_1 + 8),0,&local_68);
  iVar4 = local_14;
  if (BVar1 != 0) {
    local_68.dwTypeData = (LPWSTR)ATL::CSimpleStringT<char,0>::PrepareWrite(local_18,local_68.cch);
    local_68.cch = local_68.cch + 1;
    BVar1 = GetMenuItemInfoW(*(HMENU *)(in_ECX + 4),*(UINT *)(param_1 + 8),0,&local_68);
    ReleaseBuffer(0xffffffff);
    iVar4 = local_14;
    if (BVar1 != 0) {
      FUN_0079dfaa(0);
      local_8 = CONCAT31(local_8._1_3_,1);
      uVar2 = FUN_0079efbc(local_1c + 8);
      FUN_00566800(&local_20,local_18);
      FUN_0079efbc(uVar2);
      iVar4 = local_14 + local_20 + 3;
      FUN_0079e0f8();
    }
  }
  iVar3 = GetSystemMetrics(0xf);
  if (iVar5 < iVar3) {
    iVar5 = GetSystemMetrics(0xf);
  }
  *(int *)(param_1 + 0x10) = iVar5;
  *(int *)(param_1 + 0xc) = iVar4;
  FUN_00406b10();
  return;
}



