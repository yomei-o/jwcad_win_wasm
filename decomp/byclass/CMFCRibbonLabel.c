/* CMFCRibbonLabel -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonLabel[1] */
/* 008c6093  FUN_008c6093  57 bytes, 0 callers */

void FUN_008c6093(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCRibbonLabel::vftable;
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




/* vtable slots: CMFCRibbonLabel[62], CMFCRibbonLabel[63] */
/* 008c60fc  FUN_008c60fc  42 bytes, 0 callers */

undefined4 FUN_008c60fc(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x100);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return param_1;
}




/* vtable slots: CMFCRibbonLabel[64] */
/* 008c6126  FUN_008c6126  120 bytes, 0 callers */

void FUN_008c6126(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = FUN_00863d99();
  if (iVar2 == 0) {
    in_ECX[0x47] = 2;
    in_ECX[0x48] = 4;
  }
  else {
    in_ECX[0x47] = 3;
    in_ECX[0x48] = 3;
  }
  pcVar1 = *(code **)(*in_ECX + 0x180);
  guard_check_icall(param_2);
  (*pcVar1)();
  iVar2 = in_ECX[0x48];
  *param_1 = in_ECX[0x43] + in_ECX[0x47] * 2;
  param_1[1] = in_ECX[0x44] + iVar2 * 2;
  return;
}




/* vtable slots: CMFCRibbonLabel[0] */
/* 008c619e  FUN_008c619e  6 bytes, 0 callers */

undefined ** FUN_008c619e(void)

{
  return &PTR_s_CMFCRibbonLabel_009a4408;
}




/* vtable slots: CMFCRibbonLabel[96] */
/* 008c61a4  FUN_008c61a4  305 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008c61a4(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x8c61b0;
  local_2c = param_1;
  local_34 = in_ECX;
  iVar2 = FUN_00863d99();
  iVar3 = 0;
  if ((iVar2 == 0) && (*(int *)(in_ECX + 0xf0) != 0)) {
    FUN_008721a4(&local_3c,1);
    if ((local_3c != 0) || (local_38 != 0)) {
      local_30 = local_38 * 2;
      iVar2 = FUN_004054a0(*(int *)(in_ECX + 0x60) + -0x10);
      local_8 = 0;
      local_28 = 10;
      do {
        local_24[0] = 0;
        local_24[1] = 0;
        pcVar1 = *(code **)(*param_1 + 0x68);
        local_18 = 10000;
        local_24[2] = local_28;
        guard_check_icall(iVar2 + 0x10,*(undefined4 *)(iVar2 + 4),local_24,0x410);
        iVar3 = (*pcVar1)();
        if ((iVar3 <= local_30) && (iVar3 <= local_24[2] - local_24[0])) break;
        local_28 = local_28 + 10;
        param_1 = local_2c;
      } while (local_28 < 200);
      *(int *)(local_34 + 0x10c) = local_24[2] - local_24[0];
      *(int *)(local_34 + 0x110) = iVar3;
      FUN_00406b10();
    }
  }
  else {
    iVar2 = FUN_00863d99();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*param_1 + 0x28);
      iVar2 = FUN_007c2511();
      guard_check_icall(iVar2 + 300);
      iVar3 = (*pcVar1)();
    }
    FUN_0086817e(param_1);
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*param_1 + 0x28);
      guard_check_icall(iVar3);
      (*pcVar1)();
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonLabel[95] */
/* 008c62d5  FUN_008c62d5  487 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c62d5(int *param_1)

{
  RECT *lprc;
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  undefined4 uVar5;
  int local_2c;
  int local_24;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  lprc = (RECT *)(in_ECX + 0x1d);
  BVar2 = IsRectEmpty(lprc);
  if (BVar2 == 0) {
    local_18.left = lprc->left;
    local_18.top = in_ECX[0x1e];
    local_18.right = in_ECX[0x1f];
    local_18.bottom = in_ECX[0x20];
    InflateRect(&local_18,-in_ECX[0x47],0);
    local_2c = -1;
    iVar3 = FUN_00863d99();
    if (iVar3 == 0) {
      piVar4 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar4 + 0x278);
      guard_check_icall(param_1,in_ECX,lprc->left,in_ECX[0x1e],in_ECX[0x1f],in_ECX[0x20]);
      (*pcVar1)();
    }
    else {
      local_18.bottom = local_18.bottom + -2;
      piVar4 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar4 + 0x4c);
      guard_check_icall(param_1,lprc->left,in_ECX[0x1e],in_ECX[0x1f],in_ECX[0x20]);
      iVar3 = (*pcVar1)();
      if (iVar3 != -1) {
        pcVar1 = *(code **)(*param_1 + 0x30);
        guard_check_icall(iVar3);
        local_2c = (*pcVar1)();
      }
    }
    local_24 = 0;
    iVar3 = FUN_00863d99();
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*param_1 + 0x28);
      iVar3 = FUN_007c2511();
      guard_check_icall(iVar3 + 300);
      local_24 = (*pcVar1)();
    }
    iVar3 = FUN_00863d99();
    if ((iVar3 != 0) || (uVar5 = 0x810, in_ECX[0x3c] == 0)) {
      uVar5 = 0x824;
    }
    iVar3 = FUN_00863d99();
    if ((iVar3 == 0) && (in_ECX[0x3c] != 0)) {
      iVar3 = (local_18.bottom - in_ECX[0x44]) - local_18.top;
      if (iVar3 / 2 < 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = -(iVar3 / 2);
      }
      InflateRect(&local_18,0,iVar3);
    }
    pcVar1 = *(code **)(*in_ECX + 0x260);
    guard_check_icall(param_1,in_ECX + 0x18,local_18.left,local_18.top,local_18.right,
                      local_18.bottom,uVar5,0xffffffff);
    (*pcVar1)();
    if (local_24 != 0) {
      pcVar1 = *(code **)(*param_1 + 0x28);
      guard_check_icall(local_24);
      (*pcVar1)();
    }
    if (local_2c != -1) {
      pcVar1 = *(code **)(*param_1 + 0x30);
      guard_check_icall(local_2c);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonLabel[43] */
/* 008c64bc  SetACCData  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCRibbonLabel::SetACCData(class CWnd *,class CAccessibilityData
   &)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCRibbonLabel::SetACCData(CMFCRibbonLabel *this,CWnd *param_1,CAccessibilityData *param_2)

{
  FUN_0086470d(param_1,param_2);
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0x29;
  Empty();
  return 1;
}



