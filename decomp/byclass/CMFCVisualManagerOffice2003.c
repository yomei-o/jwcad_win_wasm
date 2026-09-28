/* CMFCVisualManagerOffice2003 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCVisualManagerOffice2003[115], CMFCVisualManagerOffice2007[115] */
/* 0082de5a  FUN_0082de5a  61 bytes, 0 callers */

void FUN_0082de5a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x18);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[114], CMFCVisualManagerOffice2007[114] */
/* 0082de97  FUN_0082de97  61 bytes, 0 callers */

void FUN_0082de97(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x14);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[113], CMFCVisualManagerOffice2007[113] */
/* 0082e95e  FUN_0082e95e  58 bytes, 0 callers */

void FUN_0082e95e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xc);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[200], CMFCVisualManagerOffice2007[200] */
/* 0082ed03  FUN_0082ed03  7 bytes, 0 callers */

undefined4 FUN_0082ed03(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18c);
}




/* vtable slots: CMFCVisualManagerOffice2003[183], CMFCVisualManagerOffice2007[183], CMFCVisualManagerOfficeXP[183] */
/* 0082ed71  FUN_0082ed71  4 bytes, 0 callers */

undefined4 FUN_0082ed71(void)

{
  return 3;
}




/* vtable slots: CMFCVisualManagerOffice2003[46], CMFCVisualManagerOffice2007[46] */
/* 0082f50e  FUN_0082f50e  7 bytes, 0 callers */

undefined4 FUN_0082f50e(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x16c);
}




/* vtable slots: CMFCVisualManagerOffice2003[11], CMFCVisualManagerOffice2007[11] */
/* 0082f5dc  FUN_0082f5dc  9 bytes, 0 callers */

bool FUN_0082f5dc(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) != 0;
}




/* vtable slots: CMFCVisualManagerOffice2003[194], CMFCVisualManagerOffice2007[194], CMFCVisualManagerOfficeXP[194] */
/* 008a3b6a  FUN_008a3b6a  228 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a3b6a(void)

{
  HBITMAP pHVar1;
  HBRUSH pHVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_24 = 0xff;
  local_20 = 0xff;
  local_1c = 0xff;
  local_18 = 0xff;
  local_8 = 0;
  pHVar1 = CreateBitmap(8,8,1,1,&local_24);
  Attach(pHVar1);
  pHVar2 = CreatePatternBrush((HBITMAP)0x0);
  Attach(pHVar2);
  local_34 = 0xaa00aa;
  local_30 = 0xaa00aa;
  local_2c = 0xaa00aa;
  local_28 = 0xaa00aa;
  local_8 = CONCAT31(local_8._1_3_,1);
  pHVar1 = CreateBitmap(8,8,1,1,&local_34);
  Attach(pHVar1);
  pHVar2 = CreatePatternBrush((HBITMAP)0x0);
  Attach(pHVar2);
  FUN_00416100();
  FUN_00416100();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[195], CMFCVisualManagerOffice2007[195], CMFCVisualManagerOfficeXP[195] */
/* 008a3c7f  FUN_008a3c7f  395 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a3c7f(CObject *param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  CObject *pCVar3;
  int iVar4;
  BOOL BVar5;
  tagRECT local_38;
  RECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(param_1 + 0x8c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(iVar1 + 0x20),&local_18);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,param_1);
    if ((pCVar3 != (CObject *)0x0) &&
       (pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,
                                    *(CObject **)(param_1 + 0x6c)), pCVar3 != (CObject *)0x0)) {
      local_28.left = *param_2;
      local_28.top = param_2[1];
      local_28.right = param_2[2];
      local_28.bottom = param_2[3];
      FUN_0079e8b8(&local_28);
      pcVar2 = *(code **)(*(int *)pCVar3 + 0x164);
      guard_check_icall();
      iVar4 = (*pcVar2)();
      if (iVar4 == 0) {
        local_28.bottom = local_28.bottom + 1;
        local_28.left = local_18.left;
        local_28.right = local_18.right;
      }
      else {
        local_28.top = local_18.top;
        local_28.bottom = local_18.bottom;
      }
      local_38.left = 0;
      local_38.top = 0;
      local_38.right = 0;
      local_38.bottom = 0;
      BVar5 = IntersectRect(&local_38,&local_28,&local_18);
      if (BVar5 == 0) {
        return;
      }
    }
    iVar1 = *(int *)(iVar1 + 0xf30);
    if (iVar1 == 1) {
      param_2[3] = param_2[3] +
                   ((local_18.right - local_18.left < param_2[2] - *param_2) - 1 & 3) + 1;
    }
    else if (iVar1 == 2) {
      param_2[1] = param_2[1] -
                   (((local_18.right - local_18.left < param_2[2] - *param_2) - 1 & 3) + 1);
    }
    else if (iVar1 == 3) {
      param_2[2] = param_2[2] +
                   ((local_18.bottom - local_18.top < param_2[3] - param_2[1]) - 1 & 3) + 1;
    }
    else if (iVar1 == 4) {
      *param_2 = *param_2 -
                 (((local_18.bottom - local_18.top < param_2[3] - param_2[1]) - 1 & 3) + 1);
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[110], CMFCVisualManagerOffice2007[110], CMFCVisualManagerOfficeXP[110] */
/* 008a3e0a  FUN_008a3e0a  11 bytes, 0 callers */

undefined4 FUN_008a3e0a(void)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  return *(undefined4 *)(iVar1 + 0x30);
}




/* vtable slots: CMFCVisualManagerOffice2003[37], CMFCVisualManagerOfficeXP[37] */
/* 008a3e15  GetHighlightedMenuItemTextColor  65 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual unsigned long __thiscall
   CMFCVisualManagerOfficeXP::GetHighlightedMenuItemTextColor(class CMFCToolBarMenuButton *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOfficeXP::GetHighlightedMenuItemTextColor
          (CMFCVisualManagerOfficeXP *this,CMFCToolBarMenuButton *param_1)

{
  int iVar1;
  ulong uVar2;
  
  if ((*(uint *)(param_1 + 0x24) & 0x40000) == 0) {
    if ((((byte)this[200] < 0x81) || ((byte)this[0xc9] < 0x81)) || ((byte)this[0xca] < 0x81)) {
      uVar2 = 0xffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x38);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2003[164], CMFCVisualManagerOffice2007[164], CMFCVisualManagerOfficeXP[164] */
/* 008a3ec6  FUN_008a3ec6  103 bytes, 0 callers */

void FUN_008a3ec6(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
                 undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (param_4 == 0) {
    if ((param_3 != 0) || (param_2 != 0)) {
      uVar2 = *(undefined4 *)(in_ECX + 0xe8);
      goto LAB_008a3f0f;
    }
    iVar1 = FUN_007c2511();
    *param_5 = *(undefined4 *)(iVar1 + 0x60);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(undefined4 *)(iVar1 + 0x58);
LAB_008a3f0f:
    *param_5 = uVar2;
    if (param_2 != 0) {
      if (param_3 == 0) {
        uVar2 = *(undefined4 *)(in_ECX + 200);
      }
      else {
        uVar2 = *(undefined4 *)(in_ECX + 0xcc);
      }
      goto LAB_008a3efe;
    }
  }
  iVar1 = FUN_007c2511();
  uVar2 = *(undefined4 *)(iVar1 + 0x54);
LAB_008a3efe:
  *param_6 = uVar2;
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[45], CMFCVisualManagerOfficeXP[45] */
/* 008a3f50  FUN_008a3f50  190 bytes, 1 callers */

undefined4 FUN_008a3f50(int *param_1,int param_2)

{
  code *pcVar1;
  bool bVar2;
  AFX_GLOBAL_DATA *pAVar3;
  int iVar4;
  undefined4 uVar5;
  
  pAVar3 = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar4 = AFX_GLOBAL_DATA::IsHighContrastMode(pAVar3);
  if (iVar4 != 0) goto LAB_008a3ffc;
  if (DAT_00a127ac == 0) {
LAB_008a3f96:
    if ((param_1[9] & 0x40000U) != 0) goto LAB_008a3f9f;
LAB_008a3fa4:
    bVar2 = false;
  }
  else {
    pcVar1 = *(code **)(*param_1 + 0x60);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 != 0) {
      if (DAT_00a127ac == 0) goto LAB_008a3f96;
      goto LAB_008a3fa4;
    }
LAB_008a3f9f:
    bVar2 = true;
  }
  iVar4 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPaneButton_00a009f8);
  if (iVar4 != 0) {
    pAVar3 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    if (bVar2) {
      return *(undefined4 *)(pAVar3 + 0x38);
    }
    iVar4 = AFX_GLOBAL_DATA::IsHighContrastMode(pAVar3);
    if (iVar4 != 0) {
      iVar4 = FUN_007c2511();
      return *(undefined4 *)(iVar4 + 0x70);
    }
    iVar4 = FUN_007c2511();
    return *(undefined4 *)(iVar4 + 0x68);
  }
  if ((param_2 == 2) && ((param_1[9] & 0x30000U) != 0)) {
    iVar4 = FUN_007c2511();
    return *(undefined4 *)(iVar4 + 0x40);
  }
LAB_008a3ffc:
  uVar5 = FUN_007f3764(param_1,param_2);
  return uVar5;
}




/* vtable slots: CMFCVisualManagerOffice2003[35], CMFCVisualManagerOfficeXP[35] */
/* 008a469c  FUN_008a469c  93 bytes, 1 callers */

void FUN_008a469c(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,int param_8)

{
  int iVar1;
  int in_ECX;
  undefined1 local_c [8];
  
  iVar1 = FUN_0079efbc(in_ECX + 0x144);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  FUN_0079ec58(local_c,param_3,param_4);
  if (param_8 != 0) {
    param_5 = param_3;
    param_4 = param_6;
  }
  CDC::LineTo(param_1,param_5,param_4);
  FUN_0079efbc(iVar1);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[55], CMFCVisualManagerOffice2007[55], CMFCVisualManagerOfficeXP[55] */
/* 008a46fa  FUN_008a46fa  137 bytes, 0 callers */

void FUN_008a46fa(CDC *param_1,int param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6,
                 int param_7,int param_8,undefined4 param_9,undefined4 param_10,int param_11)

{
  int iVar1;
  ulong uVar2;
  int in_ECX;
  ulong uVar3;
  
  if (*(int *)(param_2 + 0x2c4) == 0) {
    FUN_007f3ca9(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                 param_11);
  }
  else {
    if (param_8 == 0) {
      if (param_11 != 0) {
        return;
      }
      iVar1 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar1 + 0x60);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x60);
    }
    else if (((param_11 == 0) || (param_7 == 0)) ||
            (uVar2 = *(ulong *)(in_ECX + 0xd4), uVar3 = uVar2, uVar2 == 0xffffffff)) {
      uVar2 = *(ulong *)(in_ECX + 0xe8);
      uVar3 = uVar2;
    }
    CDC::Draw3dRect(param_1,(tagRECT *)&param_3,uVar2,uVar3);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[52], CMFCVisualManagerOfficeXP[52] */
/* 008a4783  FUN_008a4783  74 bytes, 1 callers */

void FUN_008a4783(CDC *param_1)

{
  ulong uVar1;
  HBRUSH hbr;
  int iVar2;
  HDC hDC;
  
  hbr = GetSysColorBrush(0x18);
  if (param_1 == (CDC *)0x0) {
    hDC = (HDC)0x0;
  }
  else {
    hDC = *(HDC *)(param_1 + 4);
  }
  FillRect(hDC,(RECT *)&stack0x0000000c,hbr);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x58),uVar1);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[21], CMFCVisualManagerOffice2007[21], CMFCVisualManagerOfficeXP[21] */
/* 008a47cd  FUN_008a47cd  398 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a47cd(CDC *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,int param_6,int param_7)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int local_28;
  int local_24;
  CDC *local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = param_1;
  if (param_2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pcVar1 = *(code **)(*param_2 + 0xc);
  local_1c = in_ECX;
  guard_check_icall(&local_18);
  (*pcVar1)();
  if (param_2[1] == 0) {
    if ((param_2[2] != 0) || (param_2[5] != 0)) goto LAB_008a486d;
    local_1c = (int *)param_3;
  }
  else {
    if ((param_2[2] == 0) && (param_2[5] == 0)) {
LAB_008a486d:
      if (param_6 == 0) {
        pcVar1 = *(code **)(*in_ECX + 0x314);
        guard_check_icall(local_20,local_18.left,local_18.top,local_18.right,local_18.bottom,
                          in_ECX + 0x47,0);
        (*pcVar1)();
        in_ECX = local_1c;
      }
    }
    else if (param_6 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x314);
      guard_check_icall(local_20,local_18.left,local_18.top,local_18.right,local_18.bottom,
                        in_ECX + 0x49,0);
      in_ECX = local_1c;
      (*pcVar1)();
      local_1c = (int *)0x1;
      goto LAB_008a48a4;
    }
    local_1c = (int *)0x0;
  }
LAB_008a48a4:
  if (param_7 == -1) {
    pcVar1 = *(code **)(*param_2 + 0x14);
    guard_check_icall(param_4,param_5);
    param_7 = (*pcVar1)();
    if (param_7 == -1) goto LAB_008a4919;
  }
  FUN_0081507c(&local_28);
  pcVar1 = *(code **)(*in_ECX + 0x304);
  guard_check_icall(local_20,param_2,param_7,local_1c,param_6,
                    ((local_18.right - local_28) - local_18.left) / 2 + local_18.left,
                    ((local_18.bottom - local_24) - local_18.top) / 2 + local_18.top);
  (*pcVar1)();
LAB_008a4919:
  if ((((param_2[1] != 0) || (param_2[2] != 0)) || (param_2[5] != 0)) && (param_6 == 0)) {
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(local_20,&local_18,*(ulong *)(iVar2 + 0x60),*(ulong *)(iVar2 + 0x60));
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[193], CMFCVisualManagerOffice2007[193], CMFCVisualManagerOfficeXP[193] */
/* 008a495c  FUN_008a495c  144 bytes, 0 callers */

void FUN_008a495c(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  byte bVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_5 != 0) {
    bVar1 = 1;
    goto LAB_008a49a0;
  }
  if (*(int *)(param_2 + 8) == 0) {
    if (*(int *)(param_2 + 4) != 0) {
LAB_008a49c3:
      uVar2 = *(undefined4 *)(in_ECX + 0xcc);
      goto LAB_008a49d1;
    }
    if (*(int *)(param_2 + 0x20) == -1) {
      bVar1 = -(param_4 != 0) & 3;
      goto LAB_008a49a0;
    }
    if (((0xc0 < *(byte *)(param_2 + 0x20)) && (0xc0 < *(byte *)(param_2 + 0x21))) &&
       (0xc0 < *(byte *)(param_2 + 0x22))) goto LAB_008a49e7;
  }
  else {
    if (*(int *)(param_2 + 4) != 0) goto LAB_008a49c3;
    uVar2 = *(undefined4 *)(in_ECX + 200);
LAB_008a49d1:
    if ((((byte)uVar2 < 0xc1) && ((byte)((uint)uVar2 >> 8) < 0xc1)) &&
       ((byte)((uint)uVar2 >> 0x10) < 0xc1)) {
LAB_008a49e7:
      bVar1 = 3;
      goto LAB_008a49a0;
    }
  }
  bVar1 = 0;
LAB_008a49a0:
  local_c = 0;
  local_8 = 0;
  FUN_00814c80(param_1,param_3,&stack0x00000018,bVar1,&local_c);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[29], CMFCVisualManagerOfficeXP[29] */
/* 008a4be9  OnDrawEditBorder  78 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCVisualManagerOfficeXP::OnDrawEditBorder(class CDC *,class
   CRect,int,int,class CMFCToolBarEditBoxButton *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOfficeXP::OnDrawEditBorder
          (CMFCVisualManagerOfficeXP *this,CDC *param_1,LONG param_3,LONG param_4,LONG param_5,
          LONG param_6,undefined4 param_7,int param_8,undefined4 param_9)

{
  if (DAT_00a00d30 == 0) {
    CMFCVisualManager::OnDrawEditBorder
              ((CMFCVisualManager *)this,param_1,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  }
  else if (param_8 != 0) {
    CDC::Draw3dRect(param_1,(tagRECT *)&param_3,*(ulong *)(this + 0xe8),*(ulong *)(this + 0xe8));
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[84], CMFCVisualManagerOfficeXP[84] */
/* 008a4c37  FUN_008a4c37  366 bytes, 1 callers */

void FUN_008a4c37(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0079efbc(in_ECX + 0x134);
  if (iVar1 != 0) {
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_7,param_6 - param_4,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_5 - param_3,param_8,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_5 - param_9,param_4,param_9,param_6 - param_4,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_6 - param_10,param_5 - param_3,param_10,0xf00021);
    InflateRect((LPRECT)&param_7,-2,-2);
    InflateRect((LPRECT)&param_3,-2,-2);
    iVar2 = FUN_007c2511();
    FUN_0079efbc(iVar2 + 0xd0);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4 + 1,param_7,(param_6 - param_4) + -2,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_4,(param_5 - param_3) + -2,param_8,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_5 - param_9,param_4 + 1,param_9,(param_6 - param_4) + -2,
           0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_6 - param_10,(param_5 - param_3) + -2,param_10,
           0xf00021);
    FUN_0079efbc(iVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManagerOffice2003[79], CMFCVisualManagerOffice2007[79], CMFCVisualManagerOfficeXP[79] */
/* 008a4da6  FUN_008a4da6  222 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a4da6(CDC *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_44 [8];
  undefined1 local_3c [8];
  undefined **local_34 [2];
  undefined4 local_2c;
  int local_28;
  int local_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x8a4db2;
  local_24 = param_2;
  iStack_20 = param_3;
  local_1c = param_4;
  iStack_18 = param_5;
  piVar1 = (int *)FUN_0081507c(local_3c);
  uVar4 = 0;
  local_24 = local_1c - *piVar1;
  uVar3 = 0;
  if (((*(byte *)(local_28 + 200) < 0x80) || (*(byte *)(local_28 + 0xc9) < 0x80)) ||
     (*(byte *)(local_28 + 0xca) < 0x80)) {
    uVar3 = 3;
    uVar4 = 0xffffff;
  }
  local_2c = 0;
  local_28 = 0;
  FUN_00814d1c(param_1,0xe,&local_24,uVar3,&local_2c);
  FUN_0079df60(0,1,uVar4);
  local_8 = 0;
  iVar2 = FUN_0079efbc(local_34);
  if (iVar2 != 0) {
    FUN_0079ec58(local_44,local_24 + -1,param_3 + 2);
    CDC::LineTo(param_1,local_24 + -1,param_5 + -2);
    FUN_0079efbc(iVar2);
    local_34[0] = CPen::vftable;
    FUN_00416100();
    FUN_008d9b68();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManagerOffice2003[19], CMFCVisualManagerOfficeXP[19] */
/* 008a5218  FUN_008a5218  124 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008a5218(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,int param_5)

{
  ulong uVar1;
  HBRUSH hbr;
  int iVar2;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX == -0xfc) {
    hbr = (HBRUSH)0x0;
  }
  else {
    hbr = *(HBRUSH *)(in_ECX + 0x100);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  local_18.top = param_5 + -2;
  local_18.left = param_2;
  local_18.right = param_4;
  local_18.bottom = param_5;
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x5c);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar2 + 0x58),uVar1);
  iVar2 = FUN_007c2511();
  return *(undefined4 *)(iVar2 + 0x68);
}




/* vtable slots: CMFCVisualManagerOffice2003[31], CMFCVisualManagerOfficeXP[31] */
/* 008a5294  FUN_008a5294  389 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a5294(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  HBRUSH pHVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX == (int *)0xfffffef4) {
    pHVar2 = (HBRUSH)0x0;
  }
  else {
    pHVar2 = (HBRUSH)in_ECX[0x44];
  }
  FillRect((HDC)param_1[1],(RECT *)&param_2,pHVar2);
  InflateRect((LPRECT)&param_2,-1,-1);
  piVar9 = in_ECX + 0x3f;
  uVar10 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x314);
  piVar5 = param_1;
  iVar3 = param_2;
  iVar6 = param_3;
  iVar7 = param_4;
  iVar8 = param_5;
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,piVar9,0);
  (*pcVar1)();
  local_18.top = param_3;
  local_18.right = param_4;
  local_18.bottom = param_5;
  if ((param_6 == 1) || (param_6 == 3)) {
    local_18.left = (param_3 - param_5) + param_4;
  }
  else {
    local_18.left = (param_4 + param_2) / 2 - (param_5 - param_3) / 2;
    local_18.right = (local_18.left - param_3) + param_5;
  }
  InflateRect(&local_18,-2,-2);
  if ((in_ECX == (int *)0xffffff14) || (in_ECX[0x3c] == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x308);
    guard_check_icall(piVar5,iVar3,iVar6,iVar7,iVar8,piVar9,uVar10);
    (*pcVar1)();
  }
  pcVar1 = *(code **)(*param_1 + 0x30);
  iVar3 = FUN_007c2511();
  guard_check_icall(*(undefined4 *)(iVar3 + 0x58));
  uVar10 = (*pcVar1)();
  pcVar1 = *(code **)(*param_1 + 0x2c);
  guard_check_icall(in_ECX[0x2e]);
  uVar4 = (*pcVar1)();
  if (in_ECX == (int *)0xffffff14) {
    pHVar2 = (HBRUSH)0x0;
  }
  else {
    pHVar2 = (HBRUSH)in_ECX[0x3c];
  }
  FillRect((HDC)param_1[1],&local_18,pHVar2);
  pcVar1 = *(code **)(*param_1 + 0x30);
  guard_check_icall(uVar10);
  (*pcVar1)();
  pcVar1 = *(code **)(*param_1 + 0x2c);
  guard_check_icall(uVar4);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[32], CMFCVisualManagerOfficeXP[32] */
/* 008a5419  FUN_008a5419  224 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a5419(CDC *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,int param_7)

{
  code *pcVar1;
  int iVar2;
  HBRUSH hbr;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined **local_1c [2];
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x8a5425;
  param_3 = param_3 + -1;
  local_14 = param_1;
  iVar2 = FUN_007c2511();
  if (iVar2 == -0xd0) {
    hbr = (HBRUSH)0x0;
  }
  else {
    hbr = *(HBRUSH *)(iVar2 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  local_24 = 0;
  local_20 = 0;
  FUN_00814d1c(param_1,(-(uint)(param_6 != 0) & 0xfffffff9) + 7,&param_2,0,&local_24);
  if (param_7 != 0) {
    iVar2 = FUN_007c2511();
    FUN_0079df60(0,1,*(undefined4 *)(iVar2 + 0x58));
    local_8 = 0;
    uVar3 = FUN_0079efbc(local_1c);
    pcVar1 = *(code **)(*(int *)param_1 + 0x24);
    guard_check_icall(5);
    uVar4 = (*pcVar1)();
    InflateRect((LPRECT)&param_2,-1,-1);
    CDC::RoundRect(local_14,(tagRECT *)&param_2,(tagPOINT)0x200000002);
    FUN_0079efbc(uVar4);
    FUN_0079efbc(uVar3);
    local_1c[0] = CPen::vftable;
    FUN_00416100();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[16], CMFCVisualManagerOffice2007[16], CMFCVisualManagerOfficeXP[16] */
/* 008a54f9  FUN_008a54f9  514 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a54f9(CDC *param_1,int *param_2,int *param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HDC pHVar5;
  HBITMAP pHVar6;
  int iVar7;
  int in_ECX;
  CDC local_44 [4];
  HDC__ *local_40;
  CDrawingManager local_34 [8];
  undefined **local_2c;
  void *local_28;
  CDrawingManager local_24 [4];
  CGdiObject *local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x8a5505;
  local_1c = in_ECX;
  iVar4 = FUN_0079a141();
  if (iVar4 == 0) {
    CDC::CDC(local_44);
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    if (param_1 == (CDC *)0x0) {
      pHVar5 = (HDC)0x0;
    }
    else {
      pHVar5 = *(HDC *)(param_1 + 4);
    }
    pHVar5 = CreateCompatibleDC(pHVar5);
    iVar4 = FUN_0079e84a(pHVar5);
    if (iVar4 != 0) {
      iVar4 = param_2[3];
      iVar1 = param_2[2];
      iVar2 = param_2[1];
      iVar3 = *param_2;
      local_28 = (void *)0x0;
      local_18 = (iVar1 - iVar3) + param_4;
      local_14 = (iVar4 - iVar2) + param_4;
      local_2c = CBitmap::vftable;
      local_8._0_1_ = 2;
      pHVar6 = CreateCompatibleBitmap(*(HDC *)(param_1 + 4),local_18,local_14);
      iVar7 = Attach(pHVar6);
      if (iVar7 != 0) {
        local_20 = CDC::SelectGdiObject(local_40,local_28);
        if (local_20 == (CGdiObject *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        BitBlt(local_40,0,0,local_18,local_14,*(HDC *)(param_1 + 4),*param_2,param_2[1],0xcc0020);
        CDrawingManager::CDrawingManager(local_34,local_44);
        local_8._0_1_ = 3;
        FUN_00816e2b(0,0,iVar1 - iVar3,iVar4 - iVar2,param_4,param_5,param_6,param_7,param_8,
                     *(undefined4 *)(local_1c + 0xa8),param_9 == 0);
        BitBlt(local_40,*param_3 - *param_2,param_3[1] - param_2[1],param_3[2] - *param_3,
               param_3[3] - param_3[1],*(HDC *)(param_1 + 4),*param_3,param_3[1],0xcc0020);
        BitBlt(*(HDC *)(param_1 + 4),*param_2,param_2[1],local_18,local_14,local_40,0,0,0xcc0020);
        CDC::SelectGdiObject(local_40,*(void **)(local_20 + 4));
        FUN_0081510b();
      }
      local_2c = CBitmap::vftable;
      FUN_00416100();
    }
    FUN_0079e053();
  }
  else {
    CDrawingManager::CDrawingManager(local_24,param_1);
    local_8 = 0;
    FUN_00816e2b(*param_2,param_2[1],param_2[2],param_2[3],param_4,param_5,param_6,param_7,param_8,
                 *(undefined4 *)(in_ECX + 0xa8),param_9 == 0);
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[22], CMFCVisualManagerOfficeXP[22] */
/* 008a56fc  FUN_008a56fc  232 bytes, 1 callers */

void FUN_008a56fc(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int param_6,
                 uint param_7,int param_8)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  byte bVar4;
  undefined4 local_14;
  uint local_10;
  int *local_c;
  undefined4 local_8;
  
  iVar2 = param_8;
  local_10 = param_7 & 0x40000;
  if (param_6 == 0xf020) {
    local_8 = 3;
  }
  else if (param_6 == 0xf060) {
    local_8 = 5;
  }
  else {
    if (param_6 != 0xf120) {
      return;
    }
    local_8 = 4;
  }
  uVar3 = local_10;
  if ((param_8 != 0) && (local_10 == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x314);
    local_c = in_ECX;
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,
                      in_ECX + (uint)((param_7 & 0x20000) != 0) * 2 + 0x47,0);
    (*pcVar1)();
    CDC::Draw3dRect(param_1,(tagRECT *)&param_2,local_c[0x3a],local_c[0x3a]);
    uVar3 = local_10;
  }
  local_14 = 0;
  local_10 = 0;
  if (uVar3 == 0) {
    bVar4 = -(iVar2 != 0) & 3;
  }
  else {
    bVar4 = 1;
  }
  FUN_00814d1c(param_1,local_8,&param_2,bVar4,&local_14);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[83], CMFCVisualManagerOfficeXP[83] */
/* 008a57e4  FUN_008a57e4  437 bytes, 1 callers */

void FUN_008a57e4(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0079d98a(&PTR_s_CMFCTasksPaneFrameWnd_00a00c90);
  if (iVar1 == 0) {
    FUN_007f4a3f(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  }
  else {
    iVar1 = FUN_0079efbc(in_ECX + 0x134);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_7,param_6 - param_4,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_5 - param_3,param_8,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_5 - param_9,param_4,param_9,param_6 - param_4,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_6 - param_10,param_5 - param_3,param_10,0xf00021);
    InflateRect((LPRECT)&param_7,-2,-2);
    InflateRect((LPRECT)&param_3,-2,-2);
    iVar2 = FUN_007c2511();
    FUN_0079efbc(iVar2 + 0xa8);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4 + 1,param_7,(param_6 - param_4) + -2,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_4,(param_5 - param_3) + -2,param_8,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_5 - param_9,param_4 + 1,param_9,(param_6 - param_4) + -2,
           0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_6 - param_10,(param_5 - param_3) + -2,param_10,
           0xf00021);
    FUN_0079efbc(iVar1);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[123], CMFCVisualManagerOffice2007[123], CMFCVisualManagerOfficeXP[123] */
/* 008a5bd8  OnDrawPopupWindowButtonBorder  59 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawPopupWindowButtonBorder(class
   CDC *,class CRect,class CMFCDesktopAlertWndButton *)
    protected: virtual void __thiscall
   CMFCVisualManagerOfficeXP::OnDrawPopupWindowButtonBorder(class CDC *,class CRect,class
   CMFCDesktopAlertWndButton *)
   
   Library: Visual Studio 2015 Release */

void OnDrawPopupWindowButtonBorder(CDC *param_1)

{
  int in_ECX;
  int in_stack_00000018;
  
  if (((*(int *)(in_stack_00000018 + 0xb4) != 0) || (*(int *)(in_stack_00000018 + 0xac) != 0)) ||
     (*(int *)(in_stack_00000018 + 0x7a8) != 0)) {
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(in_ECX + 0xe8),
                    *(ulong *)(in_ECX + 0xe8));
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[88], CMFCVisualManagerOfficeXP[88] */
/* 008a5c40  FUN_008a5c40  121 bytes, 1 callers */

undefined4
FUN_008a5c40(CDC *param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6,
            int param_7,int param_8)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if (param_8 == 0) {
    if (param_7 != 0) {
      piVar3 = in_ECX + 0x47;
    }
  }
  else {
    piVar3 = in_ECX + (uint)(param_7 == 0) * 2 + 0x49;
  }
  pcVar1 = *(code **)(*in_ECX + 0x314);
  guard_check_icall(param_1,param_3,param_4,param_5,param_6,piVar3,0);
  (*pcVar1)();
  CDC::Draw3dRect(param_1,(tagRECT *)&param_3,in_ECX[0x3a],in_ECX[0x3a]);
  iVar2 = FUN_007c2511();
  return *(undefined4 *)(iVar2 + 0x28);
}




/* vtable slots: CMFCVisualManagerOffice2003[144], CMFCVisualManagerOfficeXP[144] */
/* 008a5cb9  FUN_008a5cb9  724 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a5cb9(CDC *param_1,int *param_2)

{
  code *pcVar1;
  CDC *this;
  int iVar2;
  int iVar3;
  ulong uVar4;
  BOOL BVar5;
  LONG LVar6;
  LONG LVar7;
  undefined1 local_4c [4];
  int local_48;
  int local_44;
  int local_40;
  CDrawingManager local_3c [4];
  CDC *local_38;
  tagRECT local_34;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x8a5cc5;
  local_38 = param_1;
  pcVar1 = *(code **)(*param_2 + 0x24c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (((iVar2 != 0) && (param_2[0x31] == 0)) ||
     (iVar2 = FUN_0079d98a(&PTR_s_CMFCRibbonEdit_00999d90), iVar2 != 0)) goto LAB_008a5f80;
  local_40 = FUN_00863d99();
  pcVar1 = *(code **)(*param_2 + 0xd0);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) goto LAB_008a5d44;
LAB_008a5d61:
    iVar2 = 0;
  }
  else {
LAB_008a5d44:
    pcVar1 = *(code **)(*param_2 + 0xdc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) goto LAB_008a5d61;
    iVar2 = 1;
  }
  pcVar1 = *(code **)(*param_2 + 0xe0);
  local_48 = iVar2;
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (((iVar3 != 0) && (local_40 != 0)) && (iVar2 == 0)) goto LAB_008a5f80;
  local_34.left = param_2[0x1d];
  local_34.top = param_2[0x1e];
  local_34.right = param_2[0x1f];
  local_34.bottom = param_2[0x20];
  local_24.left = param_2[0x49];
  local_24.top = param_2[0x4a];
  local_24.right = param_2[0x4b];
  local_24.bottom = param_2[0x4c];
  if (param_2[0x26] != 0) {
    InflateRect(&local_34,-1,-1);
  }
  if (local_48 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xe0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) goto LAB_008a5f80;
  }
  pcVar1 = *(code **)(*param_2 + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*param_2 + 0xd4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*param_2 + 0xe0);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) goto LAB_008a5f80;
    }
  }
  pcVar1 = *(code **)(*param_2 + 0xd8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) goto LAB_008a5e58;
LAB_008a5e69:
    uVar4 = *(ulong *)(local_44 + 0xe8);
    iVar2 = local_44;
  }
  else {
LAB_008a5e58:
    if (local_40 != 0) goto LAB_008a5e69;
    uVar4 = *(ulong *)(local_44 + 0xd4);
    iVar2 = local_44;
  }
  this = local_38;
  if (DAT_00a12704 == 0) {
    CDC::Draw3dRect(local_38,&local_34,uVar4,uVar4);
  }
  else {
    CDrawingManager::CDrawingManager(local_3c,local_38);
    local_8 = 0;
    FUN_00816b6a(&local_34,0xffffffff,*(undefined4 *)(iVar2 + 0xe8));
    local_8 = 0xffffffff;
    FUN_0081510b();
  }
  BVar5 = IsRectEmpty(&local_24);
  if (BVar5 == 0) {
    if (param_2[0x26] != 0) {
      local_24.top = local_24.top + 1;
      local_24.right = local_24.right + -1;
      local_24.bottom = local_24.bottom + -1;
    }
    if (DAT_00a12704 == 0) {
      iVar2 = FUN_0079efbc(iVar2 + 0x144);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      if (param_2[0x5c] == 0) {
        FUN_0079ec58(local_4c,local_24.left,local_24.top);
        LVar6 = local_24.left;
        LVar7 = local_24.bottom;
      }
      else {
        FUN_0079ec58(local_3c,local_24.left,local_24.top);
        LVar6 = local_24.right;
        LVar7 = local_24.top;
      }
      CDC::LineTo(this,LVar6,LVar7);
      FUN_0079efbc(iVar2);
    }
    else {
      CDrawingManager::CDrawingManager(local_3c,this);
      local_8 = 1;
      LVar6 = local_24.left;
      LVar7 = local_24.bottom;
      if (param_2[0x5c] != 0) {
        LVar6 = local_24.right;
        LVar7 = local_24.top;
      }
      FUN_008168e5(local_24.left,local_24.top,LVar6,LVar7,*(undefined4 *)(iVar2 + 0xe8));
      FUN_0081510b();
    }
  }
LAB_008a5f80:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[135], CMFCVisualManagerOfficeXP[135] */
/* 008a5f8e  FUN_008a5f8e  245 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a5f8e(CDC *param_1,int *param_2)

{
  code *pcVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  int *in_ECX;
  undefined4 local_28;
  code *local_24;
  int *local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = param_2[0x1d];
  local_20 = param_2;
  local_24 = *(code **)(*in_ECX + 0x314);
  local_18.top = param_2[0x1e];
  local_18.right = param_2[0x1f];
  pcVar1 = *(code **)(*param_2 + 0xd0);
  local_18.bottom = param_2[0x20] + -1;
  local_1c = in_ECX;
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    iVar3 = FUN_007c2511();
    local_1c = (int *)(iVar3 + 0xd0);
  }
  else {
    local_1c = local_1c + 0x47;
  }
  pcVar1 = local_24;
  guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom,local_1c,0);
  (*pcVar1)();
  uVar4 = local_20[0x71];
  iVar3 = FUN_007c2511();
  if (*(int *)(iVar3 + 0x198) != 0) {
    uVar4 = (uint)(uVar4 == 0);
  }
  local_28 = 0;
  local_24 = (code *)0x0;
  FUN_00814d1c(param_1,(-(uVar4 != 0) & 3U) + 0xe,&local_18,0,&local_28);
  iVar3 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar3 + 0x58);
  iVar3 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar3 + 0x58),uVar2);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[178], CMFCVisualManagerOffice2007[178], CMFCVisualManagerOfficeXP[178] */
/* 008a6083  FUN_008a6083  487 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a6083(CDC *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,int param_7,int param_8,int param_9,int param_10,int param_11,
                 int param_12)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  int *piVar4;
  HBRUSH local_3c;
  undefined **local_38;
  CDC *local_34;
  int local_30;
  undefined1 local_2c [4];
  int *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x8a608f;
  local_24.left = param_5;
  local_30 = param_4;
  local_24.top = param_6;
  local_34 = param_1;
  local_24.right = param_7;
  local_24.bottom = param_8;
  InflateRect(&local_24,-1,0);
  if ((param_11 != 0) || (piVar4 = local_28, param_12 != 0)) {
    pcVar1 = *(code **)(*local_28 + 0x314);
    guard_check_icall(local_34,param_5,param_6,param_7,param_8,local_28 + 0x47,0);
    (*pcVar1)();
    InflateRect(&local_24,-1,-2);
    param_1 = local_34;
    piVar4 = local_28;
  }
  if (local_30 != -1) {
    FUN_0079de5e(local_30);
    FillRect(*(HDC *)(param_1 + 4),&local_24,local_3c);
    FUN_00416100();
  }
  iVar2 = param_10;
  if ((param_9 == 0) || (param_10 == 0)) {
    FUN_0079df60(0,1,0xc5c5c5);
    local_8 = 0;
    local_30 = FUN_0079efbc(&local_38);
    if (local_30 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    FUN_0079ec58(local_2c,param_5,param_6);
    CDC::LineTo(param_1,param_5,param_8);
    FUN_0079ec58(local_2c,param_7 + -1,param_6);
    CDC::LineTo(param_1,param_7 + -1,param_8);
    if (param_9 != 0) {
      FUN_0079ec58(local_2c,param_5,param_6);
      CDC::LineTo(param_1,param_7,param_6);
    }
    if (iVar2 != 0) {
      FUN_0079ec58(local_2c,param_5,param_8 + -1);
      CDC::LineTo(param_1,param_7,param_8 + -1);
    }
    FUN_0079efbc(local_30);
    local_8 = 0xffffffff;
    local_38 = CPen::vftable;
    FUN_00416100();
  }
  else {
    CDC::Draw3dRect(param_1,(tagRECT *)&param_5,0xc5c5c5,0xc5c5c5);
  }
  if ((param_11 != 0) || (param_12 != 0)) {
    if (param_12 == 0) {
      uVar3 = piVar4[0x3a];
    }
    else {
      uVar3 = piVar4[0x35];
    }
    CDC::Draw3dRect(param_1,(tagRECT *)&param_5,uVar3,uVar3);
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[145], CMFCVisualManagerOfficeXP[145] */
/* 008a626b  FUN_008a626b  84 bytes, 1 callers */

void FUN_008a626b(CDC *param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,
                 LONG param_6)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x314);
  guard_check_icall(param_1,param_3,param_4,param_5,param_6,in_ECX + 0x47,0);
  (*pcVar1)();
  CDC::Draw3dRect(param_1,(tagRECT *)&param_3,in_ECX[0x3a],in_ECX[0x3a]);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[157], CMFCVisualManagerOfficeXP[157] */
/* 008a6364  FUN_008a6364  116 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a6364(CDC *param_1,undefined4 param_2,int param_3,LONG param_4,LONG param_5,LONG param_6
                 )

{
  ulong uVar1;
  HBRUSH hbr;
  int iVar2;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX == -0xfc) {
    hbr = (HBRUSH)0x0;
  }
  else {
    hbr = *(HBRUSH *)(in_ECX + 0x100);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,hbr);
  local_18.right = param_3 + 2;
  local_18.left = param_3;
  local_18.top = param_4;
  local_18.bottom = param_6;
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x5c);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar2 + 0x58),uVar1);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[112], CMFCVisualManagerOffice2007[112], CMFCVisualManagerOfficeXP[112] */
/* 008a67a9  FUN_008a67a9  605 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a67a9(CDC *param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                 int param_7)

{
  undefined4 uVar1;
  ulong uVar2;
  code *pcVar3;
  LONG *pLVar4;
  int iVar5;
  HBRUSH hbr;
  int *in_ECX;
  int iVar6;
  CDC *pCVar7;
  undefined4 local_74;
  undefined4 local_70;
  CDrawingManager local_6c [8];
  CDrawingManager local_64 [4];
  int local_60;
  int local_5c;
  int local_58;
  CDC *local_54;
  int *local_50;
  undefined4 *local_4c;
  RECT *local_48;
  tagRECT local_44;
  RECT local_34;
  int local_24;
  int local_20;
  int local_1c;
  int iStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x8a67b5;
  local_54 = param_1;
  iVar6 = 2;
  pLVar4 = &local_34.right;
  do {
    ((RECT *)(pLVar4 + -2))->left = 0;
    pLVar4[-1] = 0;
    *pLVar4 = 0;
    pLVar4[1] = 0;
    iVar6 = iVar6 + -1;
    pLVar4 = pLVar4 + 4;
  } while (iVar6 != 0);
  local_24 = param_2;
  local_1c = param_4;
  iStack_18 = param_5;
  local_34.left = param_2;
  local_34.top = param_3;
  local_34.right = param_4;
  local_34.bottom = param_5;
  if (param_7 == 0) {
    local_34.bottom = param_5 - (param_5 - param_3) / 2;
    local_20 = local_34.bottom + 1;
  }
  else {
    local_20 = param_3;
    local_1c = param_4 - (param_4 - param_2) / 2;
    local_34.left = local_1c;
  }
  local_44.top = 0;
  local_44.left = 7;
  local_44.right = 1;
  local_60 = (param_6 & 3) - 1;
  local_44.bottom = 9;
  local_58 = -1;
  if ((param_6 & 4) == 0) {
    iVar6 = -1;
    if ((param_6 & 8) != 0) {
      local_58 = 1;
      iVar6 = 1;
    }
  }
  else {
    local_58 = 0;
    iVar6 = 0;
  }
  local_5c = 0;
  local_48 = &local_34;
  local_4c = (undefined4 *)((int)&local_44.left + (-(uint)(param_7 != 0) & 8));
  local_50 = in_ECX;
  do {
    pCVar7 = local_54;
    if ((local_60 == local_5c) || (iVar6 == local_5c)) {
      pcVar3 = *(code **)(*local_50 + 0x314);
      guard_check_icall(local_54,local_48->left,local_48->top,local_48->right,local_48->bottom,
                        local_50 + (uint)(local_60 == local_5c) * 2 + 0x47,0);
      (*pcVar3)();
      iVar6 = local_58;
    }
    else {
      pCVar7 = param_1;
      if (DAT_00a12704 == 0) {
        iVar5 = FUN_007c2511();
        hbr = (HBRUSH)0x0;
        if (iVar5 != -0xd0) {
          hbr = *(HBRUSH *)(iVar5 + 0xd4);
        }
        FillRect(*(HDC *)(param_1 + 4),local_48,hbr);
        iVar5 = FUN_007c2511();
        uVar2 = *(ulong *)(iVar5 + 0x5c);
        iVar5 = FUN_007c2511();
        CDC::Draw3dRect(param_1,local_48,*(ulong *)(iVar5 + 0x5c),uVar2);
      }
      else {
        CDrawingManager::CDrawingManager(local_6c,param_1);
        local_8 = 0;
        iVar5 = FUN_007c2511();
        uVar1 = *(undefined4 *)(iVar5 + 0x5c);
        iVar5 = FUN_007c2511();
        FUN_00816b6a(local_48,*(undefined4 *)(iVar5 + 0x54),uVar1);
        local_8 = 0xffffffff;
        FUN_0081510b();
      }
    }
    local_74 = 0;
    local_70 = 0;
    FUN_00814d1c(pCVar7,*local_4c,local_48,param_6 >> 4 & 1,&local_74);
    local_5c = local_5c + 1;
    local_4c = local_4c + 1;
    local_48 = local_48 + 1;
    param_1 = pCVar7;
  } while (local_5c < 2);
  if (-1 < iVar6) {
    local_44.left = (&local_34)[iVar6].left;
    local_44.top = (&local_34)[iVar6].top;
    local_44.right = (&local_34)[iVar6].right;
    local_44.bottom = (&local_34)[iVar6].bottom;
    if (DAT_00a12704 == 0) {
      CDC::Draw3dRect(local_54,&local_44,local_50[0x3a],local_50[0x3a]);
    }
    else {
      CDrawingManager::CDrawingManager(local_64,local_54);
      local_8 = 1;
      FUN_00816b6a(&local_44,0xffffffff,local_50[0x3a]);
      FUN_0081510b();
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[101], CMFCVisualManagerOffice2007[101], CMFCVisualManagerOfficeXP[101] */
/* 008a6a06  FUN_008a6a06  86 bytes, 0 callers */

void FUN_008a6a06(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x58),uVar1);
  InflateRect((LPRECT)&stack0x0000000c,-1,-1);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x54);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x54),uVar1);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[102], CMFCVisualManagerOffice2007[102], CMFCVisualManagerOfficeXP[102] */
/* 008a6a5c  FUN_008a6a5c  38 bytes, 0 callers */

void FUN_008a6a5c(CDC *param_1,undefined4 param_2,tagRECT *param_3)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x54);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,param_3,*(ulong *)(iVar2 + 0x54),uVar1);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[64], CMFCVisualManagerOffice2007[64], CMFCVisualManagerOfficeXP[64] */
/* 008a6ec7  FUN_008a6ec7  137 bytes, 0 callers */

void FUN_008a6ec7(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,
                 undefined4 param_6,int param_7,int param_8)

{
  code *pcVar1;
  int *in_ECX;
  undefined4 local_c;
  int *local_8;
  
  if (param_7 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x314);
    local_8 = in_ECX;
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,
                      in_ECX + (uint)(param_8 != 0) * 2 + 0x47,0);
    (*pcVar1)();
    in_ECX = local_8;
  }
  local_c = 0;
  local_8 = (int *)0x0;
  FUN_00814d1c(param_1,5,&param_2,0,&local_c);
  if (param_7 != 0) {
    CDC::Draw3dRect(param_1,(tagRECT *)&param_2,in_ECX[0x3a],in_ECX[0x3a]);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[54], CMFCVisualManagerOfficeXP[54] */
/* 008a7deb  FUN_008a7deb  219 bytes, 1 callers */

ulong FUN_008a7deb(int param_1,int param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6,
                  undefined4 param_7,int param_8,int param_9,undefined4 param_10,int param_11)

{
  code *pcVar1;
  ulong uVar2;
  int iVar3;
  int *in_ECX;
  HBRUSH hbr;
  
  hbr = (HBRUSH)0x0;
  if (*(int *)(param_2 + 0x2c4) == 0) {
    uVar2 = CMFCVisualManager::OnFillCaptionBarButton();
  }
  else if (param_9 == 0) {
    iVar3 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar3 + 0x68);
    if (param_8 == 0) {
      if (param_11 == 0) {
        if (in_ECX != (int *)0xfffffef4) {
          hbr = (HBRUSH)in_ECX[0x44];
        }
        FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,hbr);
      }
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x314);
      guard_check_icall(param_1,param_3,param_4,param_5,param_6,in_ECX + 0x47,0);
      (*pcVar1)();
      if (((*(byte *)(in_ECX + 0x32) < 0x81) || (*(byte *)((int)in_ECX + 0xc9) < 0x81)) ||
         (*(byte *)((int)in_ECX + 0xca) < 0x81)) {
        uVar2 = 0xffffff;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2003[82], CMFCVisualManagerOfficeXP[82] */
/* 008a8069  FUN_008a8069  182 bytes, 1 callers */

undefined4 FUN_008a8069(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  CObject *pCVar4;
  int iVar5;
  HBRUSH pHVar6;
  int in_ECX;
  int *in_stack_00000018;
  int in_stack_0000001c;
  
  piVar2 = in_stack_00000018;
  iVar3 = FUN_0079d98a(&PTR_s_CMFCTasksPaneFrameWnd_00a00c90);
  pcVar1 = *(code **)(*piVar2 + 0x1a8);
  guard_check_icall();
  pCVar4 = (CObject *)(*pcVar1)();
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCBaseToolBar_0098b6e0,pCVar4);
  if (pCVar4 == (CObject *)0x0) {
    iVar5 = FUN_007c2511();
    if (iVar3 != 0) {
      pHVar6 = (HBRUSH)0x0;
      if (iVar5 != -0xd0) {
        pHVar6 = *(HBRUSH *)(iVar5 + 0xd4);
      }
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,pHVar6);
      iVar3 = FUN_007c2511();
      return *(undefined4 *)(iVar3 + 0x68);
    }
    if (in_stack_0000001c == 0) {
      iVar5 = iVar5 + 0xc0;
    }
    else {
      iVar5 = iVar5 + 0xb8;
    }
  }
  else {
    iVar5 = in_ECX + 0x134;
  }
  if (iVar5 == 0) {
    pHVar6 = (HBRUSH)0x0;
  }
  else {
    pHVar6 = *(HBRUSH *)(iVar5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,pHVar6);
  iVar3 = FUN_007c2511();
  return *(undefined4 *)(iVar3 + 0x74);
}




/* vtable slots: CMFCVisualManagerOffice2003[142], CMFCVisualManagerOfficeXP[142] */
/* 008a8144  FUN_008a8144  1375 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a8144(CDC *param_1,int *param_2)

{
  code *pcVar1;
  CDC *pCVar2;
  int iVar3;
  BOOL BVar4;
  code *pcVar5;
  HBRUSH pHVar6;
  int *piVar7;
  int *piVar8;
  CDC *pCVar9;
  LONG LVar10;
  LONG LVar11;
  LONG LVar12;
  LONG LVar13;
  undefined4 uVar14;
  CDrawingManager local_70 [4];
  ulong local_6c;
  CDrawingManager local_68 [4];
  code *local_64;
  CDC *local_60;
  int *local_5c;
  int *local_58;
  tagRECT local_54;
  RECT local_44;
  RECT local_34;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x8a8150;
  local_60 = param_1;
  pcVar5 = *(code **)(*param_2 + 0x24c);
  guard_check_icall();
  iVar3 = (*pcVar5)();
  if ((iVar3 != 0) && (param_2[0x31] == 0)) goto LAB_008a8698;
  local_54.left = param_2[0x1d];
  local_54.top = param_2[0x1e];
  local_54.right = param_2[0x1f];
  local_54.bottom = param_2[0x20];
  iVar3 = FUN_00863d99();
  piVar7 = (int *)0x1;
  if (iVar3 == 0) {
LAB_008a81b6:
    local_6c = 0;
  }
  else {
    pcVar5 = *(code **)(*param_2 + 0x204);
    guard_check_icall();
    iVar3 = (*pcVar5)();
    if (iVar3 != 0) goto LAB_008a81b6;
    local_6c = 1;
  }
  pcVar5 = *(code **)(*param_2 + 0xd0);
  guard_check_icall();
  iVar3 = (*pcVar5)();
  if (iVar3 == 0) {
    pcVar5 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar3 = (*pcVar5)();
    if (iVar3 != 0) goto LAB_008a81ea;
LAB_008a8202:
    piVar7 = (int *)0x0;
  }
  else {
LAB_008a81ea:
    pcVar5 = *(code **)(*param_2 + 0xdc);
    guard_check_icall();
    iVar3 = (*pcVar5)();
    if (iVar3 != 0) goto LAB_008a8202;
  }
  local_5c = piVar7;
  iVar3 = FUN_0079d98a(&PTR_s_CMFCRibbonEdit_00999d90);
  if (iVar3 != 0) {
    iVar3 = FUN_007c2511();
    local_6c = *(ulong *)(iVar3 + 0x58);
    local_44.left = param_2[0x4d];
    local_44.top = param_2[0x4e];
    local_44.right = param_2[0x4f];
    local_44.bottom = param_2[0x50];
    pHVar6 = (HBRUSH)0x0;
    if (param_2[0x26] != 0) {
      local_44.right = local_44.right + 1;
    }
    if (DAT_00a12704 == 0) {
      iVar3 = FUN_007c2511();
      pCVar2 = local_60;
      if (local_5c == (int *)0x0) {
        if (iVar3 == -0xd0) {
          pHVar6 = (HBRUSH)0x0;
        }
        else {
          pHVar6 = *(HBRUSH *)(iVar3 + 0xd4);
        }
        FillRect(*(HDC *)(local_60 + 4),&local_44,pHVar6);
        CDrawingManager::CDrawingManager(local_68,pCVar2);
        local_8 = 1;
        FUN_00818045(local_44.left,local_44.top,local_44.right,local_44.bottom,0xffffffff,0xffffffff
                     ,0,0xffffffff);
        local_8 = 0xffffffff;
        FUN_0081510b();
      }
      else {
        if (iVar3 != -200) {
          pHVar6 = *(HBRUSH *)(iVar3 + 0xcc);
        }
        FillRect(*(HDC *)(local_60 + 4),&local_44,pHVar6);
      }
      CDC::Draw3dRect(pCVar2,&local_54,local_6c,local_6c);
      goto LAB_008a8698;
    }
    CDrawingManager::CDrawingManager(local_68,local_60);
    local_8 = 0;
    iVar3 = FUN_007c2511();
    if (local_5c == (int *)0x0) {
      uVar14 = *(undefined4 *)(iVar3 + 0x54);
    }
    else {
      uVar14 = *(undefined4 *)(iVar3 + 0x6c);
    }
    FUN_00816b6a(&local_54,uVar14,local_6c);
LAB_008a85ba:
    FUN_0081510b();
    goto LAB_008a8698;
  }
  pcVar5 = *(code **)(*param_2 + 0xe0);
  guard_check_icall();
  iVar3 = (*pcVar5)();
  if ((iVar3 == 0) && (piVar7 == (int *)0x0)) goto LAB_008a8698;
  pcVar5 = *(code **)(*param_2 + 0xe0);
  guard_check_icall();
  iVar3 = (*pcVar5)();
  if ((iVar3 != 0) && ((local_6c != 0 && (piVar7 == (int *)0x0)))) goto LAB_008a8698;
  local_34.left = param_2[0x49];
  local_34.top = param_2[0x4a];
  local_34.right = param_2[0x4b];
  local_34.bottom = param_2[0x4c];
  if (param_2[0x26] != 0) {
    InflateRect(&local_54,-1,-1);
  }
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  BVar4 = IsRectEmpty(&local_34);
  if (BVar4 == 0) {
    local_24.left = param_2[0x4d];
    local_24.top = param_2[0x4e];
    local_24.right = param_2[0x4f];
    local_24.bottom = param_2[0x50];
    if (param_2[0x26] != 0) {
      local_34.top = local_34.top + 1;
      local_34.right = local_34.right + -1;
      local_34.bottom = local_34.bottom + -1;
      local_24.left = local_24.left + 1;
      local_24.top = local_24.top + 1;
      local_24.bottom = local_24.bottom + -1;
    }
  }
  BVar4 = IsRectEmpty(&local_34);
  if ((BVar4 == 0) && (local_5c != (int *)0x0)) {
    pcVar5 = *(code **)(*param_2 + 0x254);
    guard_check_icall();
    iVar3 = (*pcVar5)();
    pCVar2 = local_60;
    pcVar5 = *(code **)(*local_58 + 0x314);
    local_64 = pcVar5;
    if (iVar3 == 0) {
      uVar14 = 0;
      piVar7 = local_58 + 0x47;
      pCVar9 = local_60;
      LVar10 = local_24.left;
      LVar11 = local_24.top;
      LVar12 = local_24.right;
      LVar13 = local_24.bottom;
      local_5c = piVar7;
      guard_check_icall(local_60,local_24.left,local_24.top,local_24.right,local_24.bottom,piVar7,0)
      ;
      (*pcVar5)();
      CDrawingManager::CDrawingManager(local_68,pCVar2);
      local_8 = 2;
      FUN_00818045(local_24.left,local_24.top,local_24.right,local_24.bottom,0xffffffff,0xffffffff,0
                   ,0xffffffff);
      local_8 = 0xffffffff;
      FUN_0081510b();
      piVar8 = local_58;
    }
    else {
      pcVar5 = *(code **)(*param_2 + 0xd8);
      guard_check_icall();
      iVar3 = (*pcVar5)();
      if (iVar3 == 0) {
        pcVar5 = *(code **)(*param_2 + 0xe4);
        guard_check_icall();
        iVar3 = (*pcVar5)();
        if (iVar3 != 0) goto LAB_008a8434;
LAB_008a843f:
        iVar3 = 0x11c;
      }
      else {
LAB_008a8434:
        iVar3 = 0x124;
        if (local_6c != 0) goto LAB_008a843f;
      }
      pcVar5 = local_64;
      piVar7 = (int *)(iVar3 + (int)local_58);
      uVar14 = 0;
      pCVar9 = local_60;
      LVar10 = local_24.left;
      LVar11 = local_24.top;
      LVar12 = local_24.right;
      LVar13 = local_24.bottom;
      guard_check_icall(local_60,local_24.left,local_24.top,local_24.right,local_24.bottom,piVar7,0)
      ;
      (*pcVar5)();
      local_5c = local_58 + 0x47;
      piVar8 = local_58;
    }
    pcVar5 = *(code **)(*param_2 + 600);
    guard_check_icall(pCVar9,LVar10,LVar11,LVar12,LVar13,piVar7,uVar14);
    iVar3 = (*pcVar5)();
    pCVar2 = local_60;
    local_64 = *(code **)(*piVar8 + 0x314);
    if (iVar3 == 0) {
      guard_check_icall(local_60,local_34.left,local_34.top,local_34.right,local_34.bottom,local_5c,
                        0);
      (*local_64)();
      CDrawingManager::CDrawingManager(local_70,pCVar2);
      local_8 = 3;
      FUN_00818045(local_34.left,local_34.top,local_34.right,local_34.bottom,0xffffffff,0xffffffff,0
                   ,0xffffffff);
      goto LAB_008a85ba;
    }
    pcVar5 = *(code **)(*param_2 + 0xd8);
    guard_check_icall();
    iVar3 = (*pcVar5)();
    if (iVar3 == 0) {
      pcVar5 = *(code **)(*param_2 + 0xe4);
      guard_check_icall();
      iVar3 = (*pcVar5)();
      if (iVar3 != 0) goto LAB_008a8530;
LAB_008a853c:
      piVar7 = local_5c;
    }
    else {
LAB_008a8530:
      piVar7 = piVar8 + 0x49;
      if (local_6c != 0) goto LAB_008a853c;
    }
    pcVar5 = local_64;
    guard_check_icall(local_60,local_34.left,local_34.top,local_34.right,local_34.bottom,piVar7,0);
    (*pcVar5)();
    goto LAB_008a8698;
  }
  pcVar5 = *(code **)(*param_2 + 0xd8);
  guard_check_icall();
  iVar3 = (*pcVar5)();
  if (iVar3 == 0) {
    pcVar5 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar3 = (*pcVar5)();
    if (iVar3 != 0) goto LAB_008a85f4;
LAB_008a85ff:
    iVar3 = 0x11c;
  }
  else {
LAB_008a85f4:
    iVar3 = 0x124;
    if (local_6c != 0) goto LAB_008a85ff;
  }
  local_64 = (code *)((int)local_58 + iVar3);
  local_44.left = local_54.left;
  local_44.top = local_54.top;
  local_44.right = local_54.right;
  local_44.bottom = local_54.bottom;
  pcVar5 = *(code **)(*param_2 + 0xe0);
  guard_check_icall();
  iVar3 = (*pcVar5)();
  pcVar5 = local_64;
  if ((iVar3 != 0) && (local_6c == 0)) {
    if (local_5c == (int *)0x0) {
      pcVar5 = (code *)(local_58 + 0x4b);
      BVar4 = IsRectEmpty(&local_24);
      if (BVar4 == 0) {
        local_44.left = local_24.left;
        local_44.top = local_24.top;
        local_44.right = local_24.right;
        local_44.bottom = local_24.bottom;
      }
    }
    else {
      pcVar5 = (code *)(local_58 + 0x49);
    }
  }
  pcVar1 = *(code **)(*local_58 + 0x314);
  guard_check_icall(local_60,local_44.left,local_44.top,local_44.right,local_44.bottom,pcVar5,0);
  (*pcVar1)();
LAB_008a8698:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[156], CMFCVisualManagerOfficeXP[156] */
/* 008a86a3  OnFillRibbonMenuFrame  37 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCVisualManagerOfficeXP::OnFillRibbonMenuFrame(class CDC
   *,class CMFCRibbonMainPanel *,class CRect)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOfficeXP::OnFillRibbonMenuFrame(CMFCVisualManagerOfficeXP *this,int param_1)

{
  HBRUSH hbr;
  
  hbr = (HBRUSH)0x0;
  if (this != (CMFCVisualManagerOfficeXP *)0xfffffef4) {
    hbr = *(HBRUSH *)(this + 0x110);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[36], CMFCVisualManagerOfficeXP[36] */
/* 008a8824  FUN_008a8824  155 bytes, 1 callers */

void FUN_008a8824(CDC *param_1,int param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6,
                 undefined4 *param_7)

{
  uint uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  puVar3 = param_7;
  uVar1 = *(uint *)(param_2 + 0x24);
  InflateRect((LPRECT)&param_3,-1,0);
  pcVar2 = *(code **)(*in_ECX + 0x314);
  guard_check_icall(param_1,param_3,param_4,param_5,param_6,
                    (~(uVar1 >> 0xe) & 0x10 | 0x10c) + (int)in_ECX,param_2);
  (*pcVar2)();
  CDC::Draw3dRect(param_1,(tagRECT *)&param_3,in_ECX[0x3a],in_ECX[0x3a]);
  pcVar2 = *(code **)(*in_ECX + 0x94);
  guard_check_icall(param_2);
  uVar4 = (*pcVar2)();
  *puVar3 = uVar4;
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[1] */
/* 008a9124  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCVisualManagerOffice2003::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCVisualManagerOffice2003::_scalar_deleting_destructor_
          (CMFCVisualManagerOffice2003 *this,uint param_1)

{
  ~CMFCVisualManagerOffice2003(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x20c);
    }
  }
  return this;
}




/* vtable slots: CMFCVisualManagerOffice2003[199], CMFCVisualManagerOffice2007[199] */
/* 008a9187  FUN_008a9187  785 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a9187(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9)

{
  code *pcVar1;
  CDC *pCVar2;
  HRGN pHVar3;
  int iVar4;
  int *in_ECX;
  int iVar5;
  CDrawingManager local_78 [8];
  undefined **local_70;
  undefined4 local_6c;
  int local_68;
  CDC *local_64;
  int local_60;
  int local_5c;
  int local_58;
  tagRECT local_54;
  POINT local_44;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_64 = param_1;
  if (param_7 == 0) {
    local_60 = in_ECX[0x5e];
    local_68 = in_ECX[0x5f];
  }
  else {
    local_60 = in_ECX[0x65];
    local_68 = in_ECX[100];
  }
  if (param_6 == 0) {
    local_3c = param_2 + 3;
    local_38 = param_3 + 2;
    local_34 = param_4 + -3;
    local_30 = param_3 + 3;
    local_2c = param_4;
    local_28 = param_3;
    local_1c = param_2;
    local_18 = param_5;
  }
  else {
    local_3c = param_2 + 2;
    local_38 = param_3 + 1;
    local_34 = param_2 + 3;
    local_30 = param_5 + -3;
    local_2c = param_2;
    local_28 = param_5;
    local_1c = param_4;
    local_18 = param_3;
  }
  local_20 = param_5;
  local_24 = param_4;
  local_44.y = param_3;
  local_44.x = param_2;
  local_6c = 0;
  local_70 = CRgn::vftable;
  local_8 = 0;
  pHVar3 = CreatePolygonRgn(&local_44,6,2);
  Attach(pHVar3);
  pCVar2 = local_64;
  FUN_0079eeb5(&local_70);
  CDrawingManager::CDrawingManager(local_78,pCVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00817861(param_2,param_3,param_4,param_5,local_60,local_68,param_6,0,0);
  if (param_6 == 0) {
    InflateRect((LPRECT)&param_2,-2,0);
    param_3 = param_3 + 2;
  }
  else {
    InflateRect((LPRECT)&param_2,0,-2);
    param_2 = param_2 + 2;
  }
  pcVar1 = *(code **)(*in_ECX + 0x2e8);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  FUN_0081507c(&local_5c);
  iVar5 = param_6;
  if (DAT_00a127b4 != 0) {
    local_5c = local_5c * 2;
    local_58 = local_58 * 2;
  }
  local_60 = iVar4 * 2;
  if (param_8 != 0) {
    local_54.right = param_4;
    local_54.bottom = param_5;
    if (param_6 == 0) {
      local_54.top = param_3 + 1;
      local_54.left = (param_4 + iVar4 * -2) - local_5c;
    }
    else {
      local_54.top = (param_5 + iVar4 * -2) - local_58;
      local_54.left = param_2;
    }
    InflateRect(&local_54,-(((param_4 - local_54.left) - local_5c) / 2),
                -(((param_5 - local_54.top) - local_58) / 2));
    OffsetRect(&local_54,1,1);
    pCVar2 = local_64;
    iVar4 = 0x1e - (uint)(iVar5 != 0);
    FUN_00814c80(local_64,iVar4,&local_54,3,&local_5c);
    OffsetRect(&local_54,-1,-1);
    FUN_00814c80(pCVar2,iVar4,&local_54,0,&local_5c);
  }
  if (param_9 != 0) {
    local_54.left = param_2;
    if (iVar5 == 0) {
      local_54.right = local_5c + local_60 + param_2;
      local_54.top = param_3 + 1;
      local_54.bottom = param_5;
    }
    else {
      local_54.bottom = local_60 + local_58 + param_3;
      local_54.right = param_4;
      local_54.top = param_3;
    }
    InflateRect(&local_54,-(((local_54.right - param_2) - local_5c) / 2),
                -(((local_54.bottom - local_54.top) - local_58) / 2));
    iVar5 = 0x20 - (uint)(iVar5 != 0);
    OffsetRect(&local_54,1,1);
    pCVar2 = local_64;
    FUN_00814c80(local_64,iVar5,&local_54,3,&local_5c);
    OffsetRect(&local_54,-1,-1);
    FUN_00814c80(pCVar2,iVar5,&local_54,0,&local_5c);
  }
  FUN_0079eeb5(0);
  FUN_0081510b();
  local_70 = CRgn::vftable;
  FUN_00416100();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[198], CMFCVisualManagerOffice2007[198] */
/* 008a9498  FUN_008a9498  36 bytes, 0 callers */

COLORREF FUN_008a9498(void)

{
  COLORREF CVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x208) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    CVar1 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),0x1d);
    return CVar1;
  }
  iVar2 = FUN_007c2511();
  return *(COLORREF *)(iVar2 + 0x54);
}




/* vtable slots: CMFCVisualManagerOffice2003[99], CMFCVisualManagerOffice2007[99] */
/* 008a94bc  FUN_008a94bc  9 bytes, 0 callers */

void FUN_008a94bc(CMFCPropertyGridCtrl *param_1)

{
  CMFCVisualManager *in_ECX;
  
  CMFCVisualManager::GetPropertyGridGroupColor(in_ECX,param_1);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[100], CMFCVisualManagerOffice2007[100] */
/* 008a94c5  FUN_008a94c5  9 bytes, 0 callers */

void FUN_008a94c5(CMFCPropertyGridCtrl *param_1)

{
  CMFCVisualManager *in_ECX;
  
  CMFCVisualManager::GetPropertyGridGroupTextColor(in_ECX,param_1);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[0] */
/* 008a94ce  FUN_008a94ce  6 bytes, 0 callers */

undefined ** FUN_008a94ce(void)

{
  return &PTR_s_CMFCVisualManagerOffice2003_0099ff68;
}




/* vtable slots: CMFCVisualManagerOffice2003[190] */
/* 008a94d4  GetShowAllMenuItemsHeight  21 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManagerOffice2003::GetShowAllMenuItemsHeight(class CDC
   *,class CSize const &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

int __thiscall
CMFCVisualManagerOffice2003::GetShowAllMenuItemsHeight
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,CSize *param_2)

{
  int iVar1;
  
  iVar1 = CMFCVisualManager::GetShowAllMenuItemsHeight((CMFCVisualManager *)this,param_1,param_2);
  return iVar1 + 4;
}




/* vtable slots: CMFCVisualManagerOffice2003[116], CMFCVisualManagerOffice2007[116] */
/* 008a94e9  FUN_008a94e9  79 bytes, 0 callers */

void FUN_008a94e9(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar2;
  
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar1 == 0) {
      uVar2 = 0xb5b5b5;
      *param_1 = 0xe4e4e4;
      goto LAB_008a952f;
    }
  }
  iVar1 = FUN_007c2511();
  *param_1 = *(undefined4 *)(iVar1 + 0x54);
  iVar1 = FUN_007c2511();
  uVar2 = *(undefined4 *)(iVar1 + 0x58);
LAB_008a952f:
  *param_2 = uVar2;
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[117], CMFCVisualManagerOffice2007[117] */
/* 008a9538  FUN_008a9538  96 bytes, 0 callers */

undefined4 FUN_008a9538(void)

{
  code *pcVar1;
  int iVar2;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar2 = FUN_007c2511();
  if (8 < *(int *)(iVar2 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x28);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 1) {
        return 0xf17b3d;
      }
      if (iVar2 == 2) {
        return 0x6d92be;
      }
      if (iVar2 == 3) {
        return 0xa98286;
      }
    }
  }
  uVar3 = FUN_007f33a2();
  return uVar3;
}




/* vtable slots: CMFCVisualManagerOffice2003[67] */
/* 008a9598  FUN_008a9598  294 bytes, 1 callers */

void FUN_008a9598(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 param_8,
                 undefined4 param_9)

{
  code *pcVar1;
  int iVar2;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar3;
  int in_ECX;
  
  FUN_007f35cc(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  pcVar1 = *(code **)(*param_1 + 0x288);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    iVar2 = FUN_007c2511();
    if (8 < *(int *)(iVar2 + 0x1ac)) {
      this = (AFX_GLOBAL_DATA *)FUN_007c2511();
      iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
      if (((iVar2 == 0) && (param_1[0x4d] == 0)) && (*(int *)(in_ECX + 0x208) != 0)) {
        iVar2 = *param_1;
        pcVar1 = *(code **)(iVar2 + 0x20c);
        guard_check_icall();
        uVar3 = (*pcVar1)();
        pcVar1 = *(code **)(iVar2 + 0x1dc);
        guard_check_icall(uVar3);
        iVar2 = (*pcVar1)();
        if (iVar2 == -1) {
          iVar2 = FUN_007c2511();
          *param_5 = *(undefined4 *)(iVar2 + 0x6c);
        }
        iVar2 = FUN_007c2511();
        *param_2 = *(undefined4 *)(iVar2 + 0x58);
        iVar2 = FUN_007c2511();
        *param_3 = *(undefined4 *)(iVar2 + 0x60);
        pcVar1 = *(code **)(*param_1 + 0x28c);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) {
          iVar2 = FUN_007c2511();
          uVar3 = *(undefined4 *)(iVar2 + 100);
        }
        else {
          iVar2 = FUN_007c2511();
          uVar3 = *(undefined4 *)(iVar2 + 0x58);
        }
        *param_4 = uVar3;
        iVar2 = FUN_007c2511();
        *param_6 = *(undefined4 *)(iVar2 + 0x58);
        iVar2 = FUN_007c2511();
        *param_7 = *(undefined4 *)(iVar2 + 0x54);
      }
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[181] */
/* 008a96be  GetToolTipInfo  124 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManagerOffice2003::GetToolTipInfo(class CMFCToolTipInfo
   &,unsigned int)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCVisualManagerOffice2003::GetToolTipInfo
          (CMFCVisualManagerOffice2003 *this,CMFCToolTipInfo *param_1,uint param_2)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x10) = 1;
      *(undefined4 *)(param_1 + 8) = 1;
      *(undefined4 *)(param_1 + 4) = 1;
      *(undefined4 *)(param_1 + 0xc) = 1;
      iVar1 = FUN_007c2511();
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0x5c);
      iVar1 = FUN_007c2511();
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar1 + 0x54);
      iVar1 = FUN_007c2511();
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar1 + 0x68);
      iVar1 = FUN_007c2511();
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar1 + 0x58);
      return 1;
    }
  }
  iVar1 = CMFCVisualManager::GetToolTipInfo((CMFCVisualManager *)this,param_1,0xffffffff);
  return iVar1;
}




/* vtable slots: CMFCVisualManagerOffice2003[196], CMFCVisualManagerOffice2007[196] */
/* 008a973a  FUN_008a973a  25 bytes, 0 callers */

void FUN_008a973a(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    GetThemeSysColor(*(HTHEME *)(in_ECX + 4),5);
    return;
  }
  GetSysColor(5);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[47], CMFCVisualManagerOffice2007[47] */
/* 008a9767  FUN_008a9767  25 bytes, 0 callers */

bool FUN_008a9767(void)

{
  int iVar1;
  
  iVar1 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00);
  return iVar1 == 0;
}




/* vtable slots: CMFCVisualManagerOffice2003[201], CMFCVisualManagerOffice2007[201] */
/* 008a9780  FUN_008a9780  698 bytes, 0 callers */

void FUN_008a9780(void)

{
  code *pcVar1;
  HTHEME hTheme;
  int iVar2;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar3;
  COLORREF CVar4;
  COLORREF CVar5;
  HBRUSH pHVar6;
  int *in_ECX;
  undefined4 uVar7;
  undefined4 uVar8;
  
  iVar2 = FUN_007c2511();
  if ((8 < *(int *)(iVar2 + 0x1ac)) && (in_ECX[0x82] != 0)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x318);
      guard_check_icall();
      uVar3 = (*pcVar1)();
      if (in_ECX[0x56] == 2) {
        CVar4 = FUN_008188f6(uVar3,0x78);
        if (in_ECX[1] == 0) {
          CVar5 = GetSysColor(5);
        }
        else {
          CVar5 = GetThemeSysColor((HTHEME)in_ECX[1],5);
        }
        CVar5 = FUN_0081909d(uVar3,CVar5,0,0x3ff00000,2,1);
        uVar3 = 2;
LAB_008a98dd:
        uVar3 = FUN_0081909d(CVar4,CVar5,0,0x3ff00000,uVar3,1);
      }
      else {
        hTheme = (HTHEME)in_ECX[1];
        if (in_ECX[0x56] != 3) {
          if (hTheme == (HTHEME)0x0) {
            CVar5 = GetSysColor(5);
          }
          else {
            CVar5 = GetThemeSysColor(hTheme,5);
          }
          if (in_ECX[1] == 0) {
            CVar4 = GetSysColor(0x1d);
          }
          else {
            CVar4 = GetThemeSysColor((HTHEME)in_ECX[1],0x1d);
          }
          uVar3 = 1;
          goto LAB_008a98dd;
        }
        if (hTheme == (HTHEME)0x0) {
          CVar5 = GetSysColor(0xf);
        }
        else {
          CVar5 = GetThemeSysColor(hTheme,0xf);
        }
        uVar8 = FUN_0081909d(uVar3,CVar5,0,0x3fe80000,2,1);
        if (in_ECX[1] == 0) {
          CVar5 = GetSysColor(5);
        }
        else {
          CVar5 = GetThemeSysColor((HTHEME)in_ECX[1],5);
        }
        uVar3 = FUN_0081909d(uVar3,CVar5,0x47ae147b,0x3ff07ae1,1,1);
        uVar7 = 0x5f;
        uVar3 = FUN_0081909d(uVar8,uVar3,0,0x3ff00000,1,1);
        uVar3 = FUN_008188f6(uVar3,uVar7);
      }
      iVar2 = FUN_007c2511();
      uVar8 = 0x46;
      *(undefined4 *)(iVar2 + 0x54) = uVar3;
      iVar2 = FUN_007c2511(0x46);
      uVar3 = FUN_008188f6(*(undefined4 *)(iVar2 + 0x54),uVar8);
      iVar2 = FUN_007c2511();
      uVar8 = 0x82;
      *(undefined4 *)(iVar2 + 0x58) = uVar3;
      iVar2 = FUN_007c2511(0x82);
      uVar3 = FUN_008188f6(*(undefined4 *)(iVar2 + 0x54),uVar8);
      iVar2 = FUN_007c2511();
      uVar8 = 0x32;
      *(undefined4 *)(iVar2 + 0x5c) = uVar3;
      iVar2 = FUN_007c2511(0x32);
      uVar3 = FUN_008188f6(*(undefined4 *)(iVar2 + 0x54),uVar8);
      iVar2 = FUN_007c2511();
      uVar8 = 0x6e;
      *(undefined4 *)(iVar2 + 0x60) = uVar3;
      iVar2 = FUN_007c2511(0x6e);
      CVar5 = FUN_008188f6(*(undefined4 *)(iVar2 + 0x54),uVar8);
      iVar2 = FUN_007c2511();
      goto LAB_008a9a02;
    }
  }
  if (in_ECX[4] == 0) {
    CVar5 = GetSysColor(0xf);
  }
  else {
    CVar5 = GetThemeSysColor((HTHEME)in_ECX[4],0xf);
  }
  iVar2 = FUN_007c2511();
  *(COLORREF *)(iVar2 + 0x54) = CVar5;
  if (in_ECX[4] == 0) {
    CVar5 = GetSysColor(0x10);
  }
  else {
    CVar5 = GetThemeSysColor((HTHEME)in_ECX[4],0x10);
  }
  iVar2 = FUN_007c2511();
  *(COLORREF *)(iVar2 + 0x58) = CVar5;
  if (in_ECX[4] == 0) {
    CVar5 = GetSysColor(0x14);
  }
  else {
    CVar5 = GetThemeSysColor((HTHEME)in_ECX[4],0x14);
  }
  iVar2 = FUN_007c2511();
  *(COLORREF *)(iVar2 + 0x5c) = CVar5;
  if (in_ECX[4] == 0) {
    CVar5 = GetSysColor(0x15);
  }
  else {
    CVar5 = GetThemeSysColor((HTHEME)in_ECX[4],0x15);
  }
  iVar2 = FUN_007c2511();
  *(COLORREF *)(iVar2 + 0x60) = CVar5;
  if (in_ECX[4] == 0) {
    CVar5 = GetSysColor(0x16);
  }
  else {
    CVar5 = GetThemeSysColor((HTHEME)in_ECX[4],0x16);
  }
  iVar2 = FUN_007c2511();
LAB_008a9a02:
  *(COLORREF *)(iVar2 + 100) = CVar5;
  iVar2 = FUN_007c2511();
  CGdiObject::DeleteObject((CGdiObject *)(iVar2 + 0xd0));
  FUN_007c2511();
  iVar2 = FUN_007c2511();
  pHVar6 = CreateSolidBrush(*(COLORREF *)(iVar2 + 0x54));
  Attach(pHVar6);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[109], CMFCVisualManagerOffice2007[109] */
/* 008a9a3a  FUN_008a9a3a  244 bytes, 0 callers */

void FUN_008a9a3a(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,undefined4 param_10)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  AFX_GLOBAL_DATA *this;
  COLORREF CVar4;
  
  iVar3 = FUN_007c2511();
  if (8 < *(int *)(iVar3 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar3 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar3 == 0) {
      iVar3 = FUN_007c2511();
      uVar1 = *(undefined4 *)(iVar3 + 0x58);
      CVar4 = GetTextColor((HDC)param_1[2]);
      if (0 < param_6) {
        FUN_007a500d(param_2,param_3,param_6 + param_2,param_5,uVar1);
      }
      if (0 < param_7) {
        FUN_007a500d(param_2,param_3,param_4,param_7 + param_3,uVar1);
      }
      if (0 < param_8) {
        FUN_007a500d(param_4 - param_8,param_3,param_4,param_5,uVar1);
      }
      if (0 < param_9) {
        FUN_007a500d(param_2,param_5 - param_9,param_4,param_5,uVar1);
      }
      pcVar2 = *(code **)(*param_1 + 0x30);
      guard_check_icall(CVar4);
      (*pcVar2)();
      return;
    }
  }
  FUN_007f3958(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[17] */
/* 008a9b2e  FUN_008a9b2e  544 bytes, 1 callers */

void FUN_008a9b2e(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 CObject *param_7)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined1 local_1c [8];
  undefined4 local_14;
  int local_10;
  undefined1 local_c [4];
  int local_8;
  
  pCVar3 = param_7;
  local_14 = param_1;
  if (((param_7 != (CObject *)0x0) && (*(int *)(param_7 + 0x8c) != 0)) ||
     (iVar2 = FUN_007c2511(), iVar4 = param_6, *(int *)(iVar2 + 0x1ac) < 9)) {
    FUN_008a4017(param_1,param_2,param_3,param_4,param_5,param_6,pCVar3);
    return;
  }
  if (param_6 == 0) {
    param_3 = param_5 + -4;
  }
  else {
    param_2 = param_4 + -4;
  }
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,pCVar3);
  if (pCVar3 == (CObject *)0x0) {
    if (iVar4 == 0) goto LAB_008a9c9a;
  }
  else {
    if (iVar4 == 0) {
      if (DAT_00a127b4 == 0) {
        piVar5 = (int *)FUN_007c23d4(local_1c);
        iVar4 = *piVar5;
      }
      else {
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x358);
        guard_check_icall();
        iVar4 = (*pcVar1)();
      }
      piVar5 = (int *)FUN_007fe0a1(local_1c);
      if ((iVar4 - *piVar5) / 2 < 0) {
        iVar4 = 0;
      }
      else {
        piVar5 = (int *)FUN_007fe0a1(local_c);
        iVar4 = -((iVar4 - *piVar5) / 2);
      }
      InflateRect((LPRECT)&param_2,iVar4,0);
LAB_008a9c9a:
      iVar4 = (param_4 - param_2) + -4;
      local_8 = (int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2;
      iVar4 = (param_4 + local_8 * -4) - param_2;
      goto LAB_008a9cbc;
    }
    if (DAT_00a127b4 == 0) {
      iVar4 = FUN_007c23d4(local_c);
      iVar4 = *(int *)(iVar4 + 4);
    }
    else {
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x354);
      guard_check_icall();
      iVar4 = (*pcVar1)();
    }
    iVar2 = FUN_007fe0a1(local_c);
    if ((iVar4 - *(int *)(iVar2 + 4)) / 2 < 0) {
      iVar4 = 0;
    }
    else {
      iVar2 = FUN_007fe0a1(local_1c);
      iVar4 = -((iVar4 - *(int *)(iVar2 + 4)) / 2);
    }
    InflateRect((LPRECT)&param_2,0,iVar4);
  }
  iVar4 = (param_5 - param_3) + -4;
  local_8 = (int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2;
  iVar4 = (param_5 + local_8 * -4) - param_3;
LAB_008a9cbc:
  iVar4 = iVar4 / 2;
  if (0 < local_8) {
    do {
      if (param_6 == 0) {
        iVar2 = param_2 + iVar4;
        iVar7 = param_3;
      }
      else {
        iVar2 = param_2;
        iVar7 = param_3 + iVar4;
      }
      iVar6 = FUN_007c2511();
      FUN_007a500d(iVar2 + 1,iVar7 + 1,2,2,*(undefined4 *)(iVar6 + 0x24));
      FUN_007a500d(iVar2,iVar7,2,2,*(undefined4 *)(local_10 + 0x1a8));
      iVar4 = iVar4 + 4;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[111], CMFCVisualManagerOffice2007[111] */
/* 008a9d4e  FUN_008a9d4e  301 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a9d4e(CDC *param_1,LONG param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                 int param_7)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  ulong uVar4;
  CDrawingManager local_30 [4];
  int *local_2c;
  CDC *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x8a9d5a;
  local_24.left = param_2;
  local_24.top = param_3 + -1;
  local_28 = param_1;
  local_24.right = param_4 + 1;
  local_24.bottom = param_5 + 1;
  local_2c = in_ECX;
  if (param_7 == 1) {
    pcVar2 = *(code **)(*in_ECX + 0x314);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,in_ECX + 0x49,0);
    (*pcVar2)();
    uVar4 = local_2c[0x59];
  }
  else {
    if (param_7 != 2) {
      CDrawingManager::CDrawingManager(local_30,param_1);
      local_8 = 0;
      iVar3 = FUN_007c2511();
      uVar1 = *(undefined4 *)(iVar3 + 0x24);
      iVar3 = FUN_007c2511();
      FUN_00817861(param_2,param_3,param_4,param_5,*(undefined4 *)(iVar3 + 0x1c),uVar1,1,0,0);
      iVar3 = FUN_007c2511();
      uVar4 = *(ulong *)(iVar3 + 0x5c);
      iVar3 = FUN_007c2511();
      CDC::Draw3dRect(local_28,(tagRECT *)&param_2,*(ulong *)(iVar3 + 0x5c),uVar4);
      FUN_0081510b();
      goto LAB_008a9e70;
    }
    pcVar2 = *(code **)(*in_ECX + 0x314);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,in_ECX + 0x47,0);
    (*pcVar2)();
    uVar4 = local_2c[0x59];
  }
  CDC::Draw3dRect(local_28,&local_24,uVar4,uVar4);
LAB_008a9e70:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[34] */
/* 008a9e7b  OnDrawButtonBorder  103 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawButtonBorder(class CDC
   *,class CMFCToolBarButton *,class CRect,enum CMFCVisualManager::AFX_BUTTON_STATE)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnDrawButtonBorder
          (undefined4 param_1_00,undefined4 param_1,CObject *param_2,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  CObject *this;
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  
  this = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,param_2);
  if (((this != (CObject *)0x0) &&
      (iVar1 = CMFCCustomizeButton::IsPipeStyle((CMFCCustomizeButton *)this), iVar1 != 0)) &&
     (iVar1 = FUN_007c2511(), 8 < *(int *)(iVar1 + 0x1ac))) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      return;
    }
  }
  FUN_008a4467(param_1,param_2,param_4,param_5,param_6,param_7,param_8);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[53], CMFCVisualManagerOffice2007[53] */
/* 008a9ee2  FUN_008a9ee2  159 bytes, 0 callers */

void FUN_008a9ee2(CDC *param_1,int param_2)

{
  int iVar1;
  HBRUSH in_ECX;
  HBRUSH hbr;
  int in_stack_0000001c;
  int in_stack_00000020;
  
  if (in_stack_0000001c == -1) {
    hbr = (HBRUSH)0x0;
    if ((param_2 == 0) || (*(int *)(param_2 + 0x8c) == 0)) {
      iVar1 = FUN_007c2511();
      iVar1 = iVar1 + 0xd0;
    }
    else {
      iVar1 = FUN_007c2511();
      iVar1 = iVar1 + 0x98;
    }
    if (iVar1 != 0) {
      hbr = *(HBRUSH *)(iVar1 + 4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
  }
  else {
    FUN_0079de5e(in_stack_0000001c);
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,in_ECX);
    FUN_00416100();
  }
  if (in_stack_00000020 == 0) {
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,in_ECX[0x58].unused,in_ECX[0x60].unused);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[105] */
/* 008a9f81  FUN_008a9f81  103 bytes, 1 callers */

void FUN_008a9f81(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x20);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_7,param_6,param_9,param_8);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    FUN_007f3f12(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[28] */
/* 008a9fe8  FUN_008a9fe8  153 bytes, 1 callers */

void FUN_008a9fe8(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9)

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  int iVar2;
  ulong uVar3;
  int in_ECX;
  
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    iVar1 = param_6;
    if (iVar2 == 0) {
      if (((param_8 == 0) && (param_7 == 0)) && (param_6 == 0)) {
        return;
      }
      InflateRect((LPRECT)&param_2,-1,-1);
      if (iVar1 == 0) {
        uVar3 = *(ulong *)(in_ECX + 0xe8);
      }
      else {
        iVar1 = FUN_007c2511();
        uVar3 = *(ulong *)(iVar1 + 0x20);
      }
      CDC::Draw3dRect(param_1,(tagRECT *)&param_2,uVar3,uVar3);
      return;
    }
  }
  CMFCVisualManagerOfficeXP::OnDrawComboBorder();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[27] */
/* 008aa081  FUN_008aa081  531 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008aa081(CDC *param_1,int param_2,LONG param_3,LONG param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  CDC *local_1c;
  undefined **local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uVar4 = param_9;
  uStack_4 = 0x14;
  local_8 = 0x8aa08d;
  local_1c = param_1;
  local_14 = in_ECX;
  iVar3 = FUN_007c2511();
  if (8 < *(int *)(iVar3 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar3 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar3 == 0) {
      if (param_6 == 0) {
        if ((param_7 == 0) && (param_8 == 0)) {
          CDrawingManager::CDrawingManager((CDrawingManager *)&local_18,param_1);
          local_8 = 2;
          FUN_00817861(param_2,param_3,param_4,param_5,in_ECX[0x59],in_ECX[0x5a],1,0,0);
          if (DAT_00a12704 == 0) {
            iVar3 = FUN_007c2511();
            uVar1 = *(ulong *)(iVar3 + 0x6c);
            iVar3 = FUN_007c2511();
            CDC::Draw3dRect(param_1,(tagRECT *)&param_2,*(ulong *)(iVar3 + 0x6c),uVar1);
          }
          else {
            iVar3 = FUN_007c2511();
            FUN_00816b6a(&param_2,0xffffffff,*(undefined4 *)(iVar3 + 0x6c));
          }
        }
        else {
          pcVar2 = *(code **)(*in_ECX + 0x314);
          guard_check_icall(local_1c,param_2,param_3,param_4,param_5,
                            in_ECX + (uint)(param_7 != 0) * 2 + 0x47,0);
          (*pcVar2)();
          param_1 = local_1c;
          if (DAT_00a12704 == 0) {
            FUN_0079df60(0,1,local_14[0x3a]);
            param_1 = local_1c;
            local_8 = 1;
            iVar3 = FUN_0079efbc(&local_18);
            if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_0078e714();
            }
            FUN_0079ec58(&local_24,param_2,param_3);
            CDC::LineTo(param_1,param_2,param_5);
            FUN_0079efbc(iVar3);
            local_8 = 0xffffffff;
            local_18 = CPen::vftable;
            FUN_00416100();
            goto LAB_008aa22f;
          }
          CDrawingManager::CDrawingManager((CDrawingManager *)&local_18,local_1c);
          local_8 = 0;
          FUN_008168e5(param_2,param_3,param_2,param_5,local_14[0x3a]);
        }
        local_8 = 0xffffffff;
        FUN_0081510b();
      }
LAB_008aa22f:
      local_24 = 0;
      local_20 = 0;
      if (param_6 == 0) {
        if ((param_7 == 0) || (param_8 == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = 3;
        }
      }
      else {
        uVar4 = 1;
      }
      FUN_00814d1c(param_1,0,&param_2,uVar4,&local_24);
      return;
    }
  }
  FUN_008a4a29(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,uVar4);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[106], CMFCVisualManagerOffice2007[106] */
/* 008aa295  FUN_008aa295  206 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008aa295(int param_1)

{
  ulong uVar1;
  HRESULT HVar2;
  int iVar3;
  int in_ECX;
  CDC local_3c [20];
  COLORREF local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x8aa2a1;
  if (*(int *)(in_ECX + 0x18) == 0) {
    FUN_007f427f(param_1);
  }
  else {
    FUN_0079dfaa(param_1);
    local_8 = 0;
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetWindowRect(*(HWND *)(param_1 + 0x20),&local_24);
    local_24.bottom = local_24.bottom - local_24.top;
    local_24.right = local_24.right - local_24.left;
    local_28 = 0xffffffff;
    local_24.top = 0;
    local_24.left = 0;
    HVar2 = GetThemeColor(*(HTHEME *)(in_ECX + 0x18),5,0,0xed9,&local_28);
    if (HVar2 == 0) {
      CDC::Draw3dRect(local_3c,&local_24,local_28,local_28);
      InflateRect(&local_24,-1,-1);
      iVar3 = FUN_007c2511();
      uVar1 = *(ulong *)(iVar3 + 0x6c);
      iVar3 = FUN_007c2511();
      CDC::Draw3dRect(local_3c,&local_24,*(ulong *)(iVar3 + 0x6c),uVar1);
    }
    else {
      FUN_007f427f(param_1);
    }
    FUN_0079e0f8();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[98], CMFCVisualManagerOffice2007[98] */
/* 008aa363  OnDrawExpandingBox  87 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawExpandingBox(class CDC
   *,class CRect,int,unsigned long)
    public: virtual void __thiscall CMFCVisualManagerWindows::OnDrawExpandingBox(class CDC *,class
   CRect,int,unsigned long)
   
   Library: Visual Studio 2015 Release */

void OnDrawExpandingBox(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int param_6,
                       undefined4 param_7)

{
  CMFCVisualManager *in_ECX;
  HDC hdc;
  
  if (*(int *)(in_ECX + 0x2c) == 0) {
    CMFCVisualManager::OnDrawExpandingBox
              (in_ECX,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    if (param_1 == 0) {
      hdc = (HDC)0x0;
    }
    else {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(in_ECX + 0x2c),hdc,2,(param_6 != 0) + 1,(LPCRECT)&param_2,
                        (LPCRECT)0x0);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[86] */
/* 008aa3ba  OnDrawHeaderCtrlBorder  68 bytes, 1 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawHeaderCtrlBorder(class
   CMFCHeaderCtrl *,class CDC *,class CRect &,int,int)
    public: virtual void __thiscall CMFCVisualManagerWindows::OnDrawHeaderCtrlBorder(class
   CMFCHeaderCtrl *,class CDC *,class CRect &,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void OnDrawHeaderCtrlBorder(undefined4 param_1,int param_2,LPCRECT param_3,int param_4,int param_5)

{
  int iStateId;
  int in_ECX;
  HDC hdc;
  
  if (*(HTHEME *)(in_ECX + 0x20) != (HTHEME)0x0) {
    iStateId = 1;
    if (param_4 == 0) {
      if (param_5 != 0) {
        iStateId = 2;
      }
    }
    else {
      iStateId = 3;
    }
    hdc = (HDC)0x0;
    if (param_2 != 0) {
      hdc = *(HDC *)(param_2 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(in_ECX + 0x20),hdc,1,iStateId,param_3,(LPCRECT)0x0);
    return;
  }
  FUN_007f45f0();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[15] */
/* 008aa3fe  FUN_008aa3fe  91 bytes, 1 callers */

void FUN_008aa3fe(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  CObject *pCVar2;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x14c);
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,
                              *(CObject **)(param_2 + 0x158));
  if (pCVar2 != (CObject *)0x0) {
    *(undefined4 *)(in_ECX + 0x14c) = 0;
  }
  FUN_008a4e85(param_1,param_2,param_3,param_4,param_5,param_6);
  *(undefined4 *)(in_ECX + 0x14c) = uVar1;
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[58] */
/* 008aa459  OnDrawOutlookBarSplitter  263 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawOutlookBarSplitter(class CDC
   *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnDrawOutlookBarSplitter
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,int param_3,int param_4,int param_5,
          int param_6)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  int iVar2;
  int iVar3;
  CDrawingManager local_2c [8];
  int local_24;
  int local_20;
  CMFCVisualManagerOffice2003 *local_1c;
  int local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x8aa465;
  local_1c = this;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      CDrawingManager::CDrawingManager(local_2c,param_1);
      local_8 = 0;
      FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(this + 0x1b0),
                   *(undefined4 *)(this + 0x1ac),1,0,0);
      local_18 = 10;
      local_14 = (param_6 - param_4) + -3;
      iVar3 = (param_5 + param_3) / 2 + local_14 * -5;
      local_24 = param_4 + 2;
      local_20 = param_4 + 3;
      iVar1 = local_14 / 2;
      do {
        iVar2 = FUN_007c2511();
        FUN_007a500d(iVar3 + 1,local_20,iVar1,iVar1,*(undefined4 *)(iVar2 + 0x24));
        FUN_007a500d(iVar3,local_24,iVar1,iVar1,*(undefined4 *)(local_1c + 0x1a8));
        iVar3 = iVar3 + local_14;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
      FUN_0081510b();
      return;
    }
  }
  FUN_007f4b40(param_1,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[57] */
/* 008aa560  FUN_008aa560  89 bytes, 1 callers */

void FUN_008aa560(CDC *param_1,tagRECT *param_2,undefined4 param_3,undefined4 param_4)

{
  ulong uVar1;
  int iVar2;
  AFX_GLOBAL_DATA *this;
  int in_ECX;
  
  iVar2 = FUN_007c2511();
  if (8 < *(int *)(iVar2 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar2 == 0) {
      uVar1 = *(ulong *)(in_ECX + 0x1a8);
      iVar2 = FUN_007c2511();
      CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar2 + 0x24),uVar1);
      return;
    }
  }
  FUN_007f4b88(param_1,param_2,param_3,param_4);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[14], CMFCVisualManagerOffice2007[14] */
/* 008aa5b9  OnDrawPaneBorder  69 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawPaneBorder(class CDC *,class
   CBasePane *,class CRect &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnDrawPaneBorder
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,CBasePane *param_2,CRect *param_3)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  
  if ((*(int *)(param_2 + 0x8c) == 0) && (iVar1 = FUN_007c2511(), 8 < *(int *)(iVar1 + 0x1ac))) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      return;
    }
  }
  FUN_008a599a(param_1,param_2,param_3);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[20] */
/* 008aa5fe  OnDrawPaneCaption  183 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManagerOffice2003::OnDrawPaneCaption(class
   CDC *,class CDockablePane *,int,class CRect,class CRect)
   
   Library: Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2003::OnDrawPaneCaption
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,undefined4 param_2,int param_3,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8aa60a;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 0;
      if (param_3 == 0) {
        uVar4 = *(undefined4 *)(this + 0x168);
        uVar3 = *(undefined4 *)(this + 0x164);
      }
      else {
        uVar4 = *(undefined4 *)(this + 400);
        uVar3 = *(undefined4 *)(this + 0x194);
      }
      FUN_00817861(param_5,param_6,param_7,param_8,uVar3,uVar4,1,0,0);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x68);
      FUN_0081510b();
      return uVar2;
    }
  }
  uVar2 = FUN_008a5ad3(param_1,param_2,param_3,param_5,param_6,param_7,param_8,param_9,param_10,
                       param_11,param_12);
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2003[120], CMFCVisualManagerOffice2007[120] */
/* 008aa6b5  OnDrawPopupWindowBorder  29 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawPopupWindowBorder(class CDC
   *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnDrawPopupWindowBorder(CMFCVisualManagerOffice2003 *this,CDC *param_1)

{
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(this + 0xe8),
                  *(ulong *)(this + 0xe8));
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[121] */
/* 008aa6d2  FUN_008aa6d2  258 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ulong FUN_008aa6d2(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  int iVar2;
  ulong uVar3;
  int *in_ECX;
  int iVar4;
  CDrawingManager local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x8aa6de;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar1 == 0) {
      CDrawingManager::CDrawingManager(local_1c,param_1);
      local_8 = 0;
      FUN_00817861(param_2,param_3,param_4,param_5,in_ECX[0x6c],in_ECX[0x6b],1,0,0);
      if (*(int *)(param_6 + 0xa0) != 0) {
        iVar1 = *in_ECX;
        iVar4 = (param_2 + param_4) / 2;
        iVar2 = (param_3 + param_5) / 2;
        guard_check_icall(param_1,iVar4 + -0x14,iVar2 + -4,iVar4 + 0x14,iVar2 + 2,0,0);
        (**(code **)(iVar1 + 0x44))();
      }
      iVar1 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar1 + 0x5c);
      FUN_0081510b();
      return uVar3;
    }
  }
  uVar3 = CMFCVisualManagerOfficeXP::OnDrawPopupWindowCaption();
  return uVar3;
}




/* vtable slots: CMFCVisualManagerOffice2003[153] */
/* 008aa7d4  FUN_008aa7d4  228 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008aa7d4(CDC *param_1,CObject *param_2)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  undefined **local_1c [2];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8aa7e0;
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonQuickAccessToolBar_009a0c60,param_2)
  ;
  if ((pCVar2 == (CObject *)0x0) && (*(int *)(param_2 + 0x114) != 0)) {
    if (0 < *(int *)(param_2 + 0x114)) {
      if (*(int *)(**(int **)(param_2 + 0x110) + 0xe4) == 0) {
        return 0xffffffff;
      }
      FUN_0079df60(0,1,*(undefined4 *)(local_14 + 0x164));
      local_8 = 0;
      local_14 = FUN_0079efbc(local_1c);
      if (local_14 != 0) {
        pcVar1 = *(code **)(*(int *)param_1 + 0x24);
        guard_check_icall(5);
        iVar3 = (*pcVar1)();
        if (iVar3 != 0) {
          InflateRect((LPRECT)&stack0x0000000c,-1,-1);
          CDC::RoundRect(param_1,(tagRECT *)&stack0x0000000c,(tagPOINT)0x200000002);
          FUN_0079efbc(local_14);
          FUN_0079efbc(iVar3);
          local_1c[0] = CPen::vftable;
          FUN_00416100();
          return 0xffffffff;
        }
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  return 0xffffffff;
}




/* vtable slots: CMFCVisualManagerOffice2003[162] */
/* 008aa8b9  FUN_008aa8b9  194 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008aa8b9(CDC *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar6;
  int *in_ECX;
  CDrawingManager local_1c [8];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x8aa8c5;
  iVar5 = FUN_007c2511();
  if (8 < *(int *)(iVar5 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar5 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar5 == 0) {
      pcVar4 = *(code **)(*in_ECX + 0x284);
      guard_check_icall(*(undefined4 *)(param_2 + 0x1c4));
      local_14 = (*pcVar4)();
      uVar6 = *(undefined4 *)(param_2 + 0x74);
      uVar1 = *(undefined4 *)(param_2 + 0x78);
      uVar2 = *(undefined4 *)(param_2 + 0x7c);
      uVar3 = *(undefined4 *)(param_2 + 0x80);
      if (local_14 != -1) {
        CDrawingManager::CDrawingManager(local_1c,param_1);
        local_8 = 0;
        iVar5 = FUN_007c2511();
        FUN_00817861(uVar6,uVar1,uVar2,uVar3,local_14,*(undefined4 *)(iVar5 + 0x54),1,0,0);
        local_8 = 0xffffffff;
        FUN_0081510b();
      }
      iVar5 = FUN_007c2511();
      return *(undefined4 *)(iVar5 + 0x68);
    }
  }
  uVar6 = FUN_007f58e8(param_1,param_2);
  return uVar6;
}




/* vtable slots: CMFCVisualManagerOffice2003[134] */
/* 008aa97b  FUN_008aa97b  1123 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008aa97b(CDC *param_1,int *param_2,int param_3)

{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  CDC *pCVar4;
  int iVar5;
  AFX_GLOBAL_DATA *this;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  HRGN pHVar9;
  int iVar10;
  CDrawingManager local_a8 [8];
  undefined **local_a0 [2];
  int local_98;
  int local_94;
  int iStack_90;
  undefined **local_8c;
  int local_88;
  undefined **local_84;
  undefined4 local_80;
  int *local_7c;
  CDC *local_78;
  int local_74;
  int local_70;
  undefined **local_6c;
  int local_68;
  CDrawingManager local_64 [4];
  int local_60;
  int local_5c;
  int local_58;
  POINT local_54;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined **local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_8 = 0x8aa98a;
  local_78 = param_1;
  iVar5 = FUN_007c2511();
  if (8 < *(int *)(iVar5 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar5 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar5 == 0) {
      local_98 = param_2[0x22];
      iVar5 = *(int *)(local_98 + 0x53c);
      local_60 = iVar5;
      if (param_3 == 0) {
LAB_008aaa03:
        local_5c = 0;
      }
      else {
        if ((*(byte *)(iVar5 + 0x330) & 1) != 0) {
          pcVar1 = *(code **)(*param_2 + 0x1c4);
          guard_check_icall();
          iVar6 = (*pcVar1)();
          if (iVar6 == 0) goto LAB_008aaa03;
        }
        local_5c = 1;
      }
      pcVar1 = *(code **)(*param_2 + 0xd4);
      guard_check_icall();
      iVar6 = (*pcVar1)();
      if ((iVar6 == 0) || ((*(byte *)(iVar5 + 0x330) & 1) == 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      pcVar1 = *(code **)(*param_2 + 0xd0);
      guard_check_icall();
      iVar5 = (*pcVar1)();
      if ((iVar5 != 0) || (bVar2)) {
        pcVar1 = *(code **)(*param_2 + 0xe4);
        guard_check_icall();
        iVar5 = (*pcVar1)();
        if (iVar5 != 0) goto LAB_008aaa6c;
        local_58 = 1;
      }
      else {
LAB_008aaa6c:
        local_58 = 0;
      }
      local_74 = param_2[0x1d];
      local_6c = (undefined **)param_2[0x1f];
      local_68 = param_2[0x20];
      local_70 = param_2[0x1e] + 3;
      if (0 < *(int *)(local_60 + 0x2cc)) {
        local_94 = (int)local_6c + -1;
        iVar6 = 100 - *(int *)(local_60 + 0x2cc) / 2;
        iVar5 = 10;
        if (9 < iVar6) {
          iVar5 = iVar6;
        }
        iStack_90 = local_70;
        local_8c = local_6c;
        local_88 = local_68;
        iVar6 = FUN_007c2511(iVar5);
        uVar7 = FUN_008188f6(*(undefined4 *)(iVar6 + 0x58),iVar5);
        uVar8 = FUN_008188f6(uVar7,0x78);
        CDrawingManager::CDrawingManager(local_64,local_78);
        local_8 = 0;
        FUN_00817861(local_94,iStack_90,local_8c,local_88,uVar7,uVar8,1,0,0);
        local_8 = 0xffffffff;
        FUN_0081510b();
      }
      iVar5 = local_70;
      if ((local_5c == 0) && (local_58 == 0)) {
        FUN_007c2511();
        goto LAB_008aadd1;
      }
      local_6c = (undefined **)((int)local_6c + -2);
      iVar6 = FUN_007c2511();
      FUN_0079df60(0,1,*(undefined4 *)(iVar6 + 0x58));
      pCVar4 = local_78;
      local_8 = 1;
      local_60 = FUN_0079efbc(local_a0);
      if (local_60 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      local_80 = 0;
      local_54.x = local_74;
      local_4c = local_74 + 1;
      local_48 = local_68 + -1;
      local_3c = local_74 + 3;
      local_54.y = local_68;
      local_40 = iVar5 + 2;
      local_34 = (int)local_6c + -3;
      local_2c = (int)local_6c + -1;
      local_1c = local_6c;
      local_18 = local_68;
      local_84 = CRgn::vftable;
      local_8._0_1_ = 2;
      local_44 = local_4c;
      local_38 = iVar5;
      local_30 = iVar5;
      local_28 = local_40;
      local_24 = local_2c;
      local_20 = local_48;
      pHVar9 = CreatePolygonRgn(&local_54,8,2);
      Attach(pHVar9);
      FUN_0079eeb5(&local_84);
      CDrawingManager::CDrawingManager(local_a8,pCVar4);
      local_8 = CONCAT31(local_8._1_3_,3);
      local_88 = FUN_00863d92();
      piVar3 = local_7c;
      if (local_88 == 0) {
        pcVar1 = *(code **)(*local_7c + 0x284);
        guard_check_icall(*(undefined4 *)(local_98 + 0x19c));
        iVar5 = (*pcVar1)();
      }
      else {
        iVar5 = local_7c[0x65];
      }
      iVar6 = FUN_007c2511();
      iVar6 = *(int *)(iVar6 + 0x54);
      iVar10 = iVar5;
      if (iVar5 == -1) {
        iVar10 = FUN_008188f6(iVar6,0x78);
      }
      if (local_58 != 0) {
        if (local_5c == 0) {
          if (iVar5 != -1) {
            iVar10 = FUN_008188f6(iVar5,0x78);
            iVar6 = iVar5;
            goto LAB_008aac7c;
          }
          iVar6 = piVar3[0x65];
        }
        iVar10 = piVar3[100];
      }
LAB_008aac7c:
      FUN_00817861(local_74,local_70,local_6c,local_68,iVar6,iVar10,1,0,0);
      pCVar4 = local_78;
      FUN_0079eeb5(0);
      Polyline(*(HDC *)(pCVar4 + 4),&local_54,8);
      iVar5 = local_60;
      if (((local_58 != 0) && (local_5c != 0)) && (local_88 == 0)) {
        iVar5 = 0;
        do {
          (&local_54)[iVar5].x =
               (&local_54)[iVar5].x +
               (uint)((&local_54)[iVar5].x < ((int)local_6c + local_74) / 2) * 2 + -1;
          (&local_54)[iVar5].y =
               (&local_54)[iVar5].y +
               (uint)((&local_54)[iVar5].y < (local_70 + local_68) / 2) * 2 + -1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 8);
        FUN_0079df60(0,1,local_7c[0x65]);
        local_8._0_1_ = 4;
        FUN_0079efbc(&local_8c);
        Polyline(*(HDC *)(pCVar4 + 4),&local_54,8);
        iVar5 = local_60;
        FUN_0079efbc(local_60);
        local_8 = CONCAT31(local_8._1_3_,3);
        local_8c = CPen::vftable;
        FUN_00416100();
      }
      FUN_0079efbc(iVar5);
      FUN_007c2511();
      FUN_0081510b();
      local_84 = CRgn::vftable;
      FUN_00416100();
      local_a0[0] = CPen::vftable;
      FUN_00416100();
      goto LAB_008aadd1;
    }
  }
  FUN_007f5a68(param_1,param_2,param_3);
LAB_008aadd1:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[168] */
/* 008aaddf  FUN_008aaddf  155 bytes, 1 callers */

void FUN_008aaddf(int param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6
                 ,LONG param_7,LONG param_8,LONG param_9,LONG param_10,undefined4 param_11)

{
  HDC pHVar1;
  BOOL BVar2;
  int in_ECX;
  
  if (*(HTHEME *)(in_ECX + 0x1c) == (HTHEME)0x0) {
    FUN_007f6776(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                 param_11);
  }
  else {
    pHVar1 = (HDC)0x0;
    if (param_1 != 0) {
      pHVar1 = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(in_ECX + 0x1c),pHVar1,1,0,(LPCRECT)&param_3,(LPCRECT)0x0);
    BVar2 = IsRectEmpty((RECT *)&param_7);
    if (BVar2 == 0) {
      InflateRect((LPRECT)&param_7,-2,-2);
      pHVar1 = (HDC)0x0;
      if (param_1 != 0) {
        pHVar1 = *(HDC *)(param_1 + 4);
      }
      DrawThemeBackground(*(HTHEME *)(in_ECX + 0x1c),pHVar1,3,0,(LPCRECT)&param_7,(LPCRECT)0x0);
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[171], CMFCVisualManagerOffice2007[171] */
/* 008aae7a  FUN_008aae7a  230 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008aae7a(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  CDrawingManager local_18 [4];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x8aae86;
  iVar2 = (param_5 + param_3) / 2;
  if (DAT_00a12704 == 0) {
    local_14 = in_ECX;
    iVar1 = FUN_0079efbc(in_ECX + 0x13c);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    FUN_0079ec58(local_20,iVar2,param_4);
    CDC::LineTo(param_1,iVar2,param_6 + -1);
    FUN_0079efbc(local_14 + 0x1e8);
    FUN_0079ec58(local_28,iVar2 + 1,param_4 + 1);
    CDC::LineTo(param_1,iVar2 + 1,param_6);
    FUN_0079efbc(iVar1);
  }
  else {
    CDrawingManager::CDrawingManager(local_18,param_1);
    local_8 = 0;
    iVar1 = FUN_007c2511();
    FUN_008168e5(iVar2,param_4,iVar2,param_6 + -1,*(undefined4 *)(iVar1 + 0x60));
    iVar1 = FUN_007c2511();
    FUN_008168e5(iVar2 + 1,param_4 + 1,iVar2 + 1,param_6,*(undefined4 *)(iVar1 + 100));
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[166] */
/* 008aaf61  FUN_008aaf61  133 bytes, 1 callers */

void FUN_008aaf61(int param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6
                 )

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  HDC hdc;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x48) != 0) && (iVar1 = FUN_007c2511(), 8 < *(int *)(iVar1 + 0x1ac))) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar1 == 0) {
      InflateRect((LPRECT)&param_3,0,1);
      hdc = (HDC)0x0;
      if (param_1 != 0) {
        hdc = *(HDC *)(param_1 + 4);
      }
      DrawThemeBackground(*(HTHEME *)(in_ECX + 0x48),hdc,1,1,(LPCRECT)&param_3,(LPCRECT)0x0);
      return;
    }
  }
  FUN_007f690d(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[167] */
/* 008aafe6  FUN_008aafe6  149 bytes, 1 callers */

void FUN_008aafe6(int param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6
                 ,int param_7,int param_8,undefined4 param_9)

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  int in_ECX;
  HDC hdc;
  
  if ((*(int *)(in_ECX + 0x48) != 0) && (iVar1 = FUN_007c2511(), 8 < *(int *)(iVar1 + 0x1ac))) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar1 == 0) {
      if (param_8 == 0) {
        iVar1 = (param_7 != 0) + 1;
      }
      else {
        iVar1 = 3;
      }
      if (param_1 == 0) {
        hdc = (HDC)0x0;
      }
      else {
        hdc = *(HDC *)(param_1 + 4);
      }
      DrawThemeBackground(*(HTHEME *)(in_ECX + 0x48),hdc,4,iVar1,(LPCRECT)&param_3,(LPCRECT)0x0);
      return;
    }
  }
  FUN_007f6985(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[165] */
/* 008ab07b  FUN_008ab07b  482 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ab07b(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,undefined4 param_10)

{
  CDC *this;
  int iVar1;
  int iVar2;
  AFX_GLOBAL_DATA *this_00;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined **local_54 [2];
  undefined1 local_4c [4];
  int local_48;
  CDrawingManager local_44 [8];
  CDC *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x8ab087;
  local_3c = param_1;
  local_38 = param_2;
  iVar2 = FUN_007c2511();
  if (8 < *(int *)(iVar2 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar2 == 0) {
      if ((param_9 == 0) && (param_8 == 0)) {
        iVar2 = FUN_007c2511();
        uVar4 = *(undefined4 *)(iVar2 + 0x30);
      }
      else {
        iVar2 = FUN_007c2511();
        uVar4 = *(undefined4 *)(iVar2 + 0x60);
      }
      local_2c = (param_4 + param_6) / 2;
      local_30 = (param_5 + param_3) / 2;
      local_20 = local_2c + -7;
      local_24 = local_30 + -7;
      local_1c = local_30 + 8;
      local_18 = local_2c + 8;
      CDrawingManager::CDrawingManager(local_44,param_1);
      local_8 = 0;
      uVar3 = 0xffffffff;
      if (param_9 == 0) {
        if (param_8 != 0) {
          uVar3 = *(undefined4 *)(local_28 + 0x19c);
        }
      }
      else {
        uVar3 = *(undefined4 *)(local_28 + 0x198);
      }
      FUN_00815451(&local_24,uVar3,uVar4);
      this = local_3c;
      local_48 = local_30 + -3;
      local_34 = local_2c + -3;
      local_28 = local_2c + 4;
      local_38 = local_30 + 4;
      if (DAT_00a12704 == 0) {
        FUN_0079df60(0,1,uVar4);
        local_8 = CONCAT31(local_8._1_3_,1);
        local_34 = FUN_0079efbc(local_54);
        iVar1 = local_2c;
        FUN_0079ec58(local_4c,local_48,local_2c);
        CDC::LineTo(this,local_38,iVar1);
        iVar2 = local_30;
        if (param_7 == 0) {
          FUN_0079ec58(local_4c,local_30,iVar1 + -3);
          CDC::LineTo(this,iVar2,local_28);
        }
        FUN_0079efbc(local_34);
        local_54[0] = CPen::vftable;
        FUN_00416100();
      }
      else {
        FUN_008168e5(local_48,local_2c,local_30 + 4,local_2c,uVar4);
        if (param_7 == 0) {
          FUN_008168e5(local_30,local_34,local_30,local_28,uVar4);
        }
      }
      FUN_0081510b();
      goto LAB_008ab255;
    }
  }
  FUN_007f6ae5(local_3c,local_38,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
LAB_008ab255:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[163] */
/* 008ab25d  FUN_008ab25d  283 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008ab25d(CDC *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  int iVar6;
  AFX_GLOBAL_DATA *this;
  int iVar7;
  undefined4 uVar8;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar6 = FUN_007c2511();
  if (8 < *(int *)(iVar6 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar6 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if ((iVar6 == 0) && (in_ECX[5] != 0)) {
      iVar6 = param_3[0x1d];
      iVar1 = param_3[0x1e];
      iVar2 = param_3[0x1f];
      iVar3 = param_3[0x20];
      pcVar4 = *(code **)(*param_3 + 0xd0);
      guard_check_icall();
      iVar7 = (*pcVar4)();
      if (iVar7 != 0) {
        local_18.left = iVar6;
        local_18.top = iVar1;
        local_18.right = iVar2;
        local_18.bottom = iVar3;
        InflateRect(&local_18,-1,-1);
        pcVar4 = *(code **)(*in_ECX + 0x314);
        pcVar5 = *(code **)(*param_3 + 0xd8);
        guard_check_icall();
        iVar6 = (*pcVar5)();
        guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom,
                          (-(uint)(iVar6 != 0) & 8) + 0x11c + (int)in_ECX,0);
        (*pcVar4)();
        CDC::Draw3dRect(param_1,&local_18,in_ECX[0x3a],in_ECX[0x3a]);
      }
      return 0xffffffff;
    }
  }
  uVar8 = FUN_008a63d8(param_1,param_2,param_3);
  return uVar8;
}




/* vtable slots: CMFCVisualManagerOffice2003[95] */
/* 008ab378  FUN_008ab378  271 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ab378(CDC *param_1,tagRECT *param_2,int param_3,undefined4 param_4,int param_5)

{
  ulong uVar1;
  CDC *this;
  int iVar2;
  HBRUSH hbr;
  AFX_GLOBAL_DATA *this_00;
  tagRECT *ptVar3;
  undefined1 local_48 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined **local_38;
  HBRUSH local_34;
  CDC *local_30;
  tagRECT *local_2c;
  int local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x8ab384;
  local_30 = param_1;
  local_2c = param_2;
  FUN_0081507c(local_48);
  local_24.left = param_2->left;
  local_24.right = param_2->right;
  local_24.bottom = param_2->bottom;
  local_24.top = param_2->top - param_3;
  iVar2 = FUN_007c2511();
  this = local_30;
  hbr = (HBRUSH)0x0;
  if (iVar2 != -0xd0) {
    hbr = *(HBRUSH *)(iVar2 + 0xd4);
  }
  FillRect(*(HDC *)(local_30 + 4),&local_24,hbr);
  iVar2 = FUN_007c2511();
  if (param_5 == 0) {
    uVar1 = *(ulong *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    ptVar3 = local_2c;
    CDC::Draw3dRect(this,local_2c,*(ulong *)(iVar2 + 0x58),uVar1);
    goto LAB_008ab468;
  }
  if (*(int *)(iVar2 + 0x1ac) < 9) {
LAB_008ab403:
    iVar2 = FUN_007c2511();
    iVar2 = *(int *)(iVar2 + 0x6c);
  }
  else {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar2 != 0) goto LAB_008ab403;
    iVar2 = *(int *)(local_28 + 0x18c);
    if (iVar2 == -1) {
      iVar2 = *(int *)(local_28 + 200);
    }
  }
  FUN_0079de5e(iVar2);
  ptVar3 = local_2c;
  local_8 = 0;
  FillRect(*(HDC *)(this + 4),local_2c,local_34);
  CDC::Draw3dRect(this,ptVar3,*(ulong *)(local_28 + 0xe8),*(ulong *)(local_28 + 0xe8));
  local_8 = 0xffffffff;
  local_38 = CBrush::vftable;
  FUN_00416100();
LAB_008ab468:
  local_40 = 0;
  local_3c = 0;
  FUN_00814d1c(this,param_4,ptVar3,0,&local_40);
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[18] */
/* 008ab487  FUN_008ab487  655 bytes, 1 callers */

void FUN_008ab487(CDC *param_1,CObject *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  HDC hdc;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  CObject *local_10;
  CObject *local_c;
  int local_8;
  
  local_c = param_2;
  if (((*(int *)(param_2 + 0x8c) == 0) &&
      (local_8 = in_ECX, iVar1 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938), iVar1 == 0)) &&
     (iVar1 = FUN_007c2511(), 8 < *(int *)(iVar1 + 0x1ac))) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar1 == 0) {
      iVar1 = FUN_0079d98a(&PTR_s_CMFCRibbonStatusBar_009a090c);
      if (iVar1 == 0) {
        local_10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,param_2);
        if (local_10 != (CObject *)0x0) {
          local_c = (CObject *)FUN_0079efbc(in_ECX + 0x13c);
          if (local_c != (CObject *)0x0) {
            if (param_7 == 0) {
              piVar3 = (int *)FUN_007c23d4(local_18);
              piVar4 = (int *)FUN_007fe0a1(local_30);
              if ((*piVar3 - *piVar4) / 2 < 0) {
                iVar1 = 0;
              }
              else {
                piVar3 = (int *)FUN_007c23d4(local_28);
                piVar4 = (int *)FUN_007fe0a1(local_20);
                iVar1 = -((*piVar3 - *piVar4) / 2);
              }
              InflateRect((LPRECT)&param_3,iVar1,0);
              iVar2 = (param_6 - param_4) / 2 + param_4;
              iVar1 = iVar2 + -1;
              param_4 = iVar1;
              FUN_0079ec58(local_18,param_3,iVar1);
              CDC::LineTo(param_1,param_5 + -1,iVar1);
              FUN_0079efbc(local_8 + 0x1e8);
              FUN_0079ec58(local_18,param_3 + 1,iVar2);
              iVar1 = param_5;
            }
            else {
              iVar1 = FUN_007c23d4(local_20);
              iVar2 = FUN_007fe0a1(local_28);
              if ((*(int *)(iVar1 + 4) - *(int *)(iVar2 + 4)) / 2 < 0) {
                iVar1 = 0;
              }
              else {
                iVar1 = FUN_007c23d4(local_30);
                iVar2 = FUN_007fe0a1(local_18);
                iVar1 = -((*(int *)(iVar1 + 4) - *(int *)(iVar2 + 4)) / 2);
              }
              InflateRect((LPRECT)&param_3,0,iVar1);
              iVar1 = (param_5 - param_3) / 2 + param_3;
              iVar2 = iVar1 + -1;
              param_3 = iVar2;
              FUN_0079ec58(local_18,iVar2,param_4);
              CDC::LineTo(param_1,iVar2,param_6 + -1);
              FUN_0079efbc(local_8 + 0x1e8);
              FUN_0079ec58(local_18,iVar1,param_4 + 1);
              iVar2 = param_6;
            }
            CDC::LineTo(param_1,iVar1,iVar2);
            FUN_0079efbc(local_c);
            return;
          }
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
      }
      else if (*(int *)(in_ECX + 0x14) != 0) {
        InflateRect((LPRECT)&param_3,1,5);
        hdc = (HDC)0x0;
        if (param_1 != (CDC *)0x0) {
          hdc = *(HDC *)(param_1 + 4);
        }
        DrawThemeBackground(*(HTHEME *)(in_ECX + 0x14),hdc,1,0,(LPCRECT)&param_3,(LPCRECT)0x0);
        return;
      }
    }
  }
  FUN_008a65b2(param_1,local_c,param_3,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[191] */
/* 008ab717  FUN_008ab717  224 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ab717(CDC *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  int local_24;
  int local_20;
  int local_1c;
  CDC *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x8ab723;
  local_18 = param_1;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar1 == 0) {
      param_5 = (param_5 + param_3) / 2;
      param_3 = param_5 + -7;
      param_4 = (param_4 + param_2) / 2;
      param_2 = param_4 + -7;
      param_4 = param_4 + 9;
      param_5 = param_5 + 9;
      local_24 = param_4;
      local_20 = param_5;
      CDrawingManager::CDrawingManager((CDrawingManager *)&local_24,local_18);
      local_8 = 0;
      FUN_0081610f(param_2,param_3,param_4,param_5,*(undefined4 *)(local_1c + 0x164),
                   *(undefined4 *)(local_1c + 0xc0),0xffffffff,0x2d,8,0xffffffff);
      local_8 = 0xffffffff;
      FUN_0081510b();
    }
  }
  FUN_007f6f23(local_18,param_2,param_3,param_4,param_5,param_6);
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[23] */
/* 008ab7f7  FUN_008ab7f7  112 bytes, 1 callers */

void FUN_008ab7f7(int param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6
                 ,undefined4 param_7,uint param_8)

{
  HTHEME hTheme;
  CMFCVisualManagerOfficeXP *in_ECX;
  HDC hdc;
  
  if ((DAT_00a00c64 == 0) || (hTheme = *(HTHEME *)(in_ECX + 0x14), hTheme == (HTHEME)0x0)) {
    CMFCVisualManagerOfficeXP::OnDrawStatusBarPaneBorder
              (in_ECX,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    hTheme = *(HTHEME *)(in_ECX + 0x14);
    if (hTheme == (HTHEME)0x0) {
      return;
    }
  }
  if ((param_8 & 0x100) == 0) {
    if (param_1 == 0) {
      hdc = (HDC)0x0;
    }
    else {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(hTheme,hdc,1,0,(LPCRECT)&param_3,(LPCRECT)0x0);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[25], CMFCVisualManagerOffice2007[25] */
/* 008ab867  FUN_008ab867  121 bytes, 0 callers */

void FUN_008ab867(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x10);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10
                    ,param_11,param_12);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    FUN_007f7211(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                 param_11,param_12);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[26] */
/* 008ab8e0  OnDrawStatusBarSizeBox  71 bytes, 1 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawStatusBarSizeBox(class CDC
   *,class CMFCStatusBar *,class CRect)
    public: virtual void __thiscall CMFCVisualManagerWindows::OnDrawStatusBarSizeBox(class CDC
   *,class CMFCStatusBar *,class CRect)
   
   Library: Visual Studio 2015 Release */

void OnDrawStatusBarSizeBox
               (int param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6)

{
  HDC hdc;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) == 0) {
    FUN_007f73d8(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    hdc = (HDC)0x0;
    if (param_1 != 0) {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(in_ECX + 0x24),hdc,10,1,(LPCRECT)&param_3,(LPCRECT)0x0);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[61] */
/* 008ab927  FUN_008ab927  1967 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ab927(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int *param_8)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  AFX_GLOBAL_DATA *this;
  CDC *pCVar4;
  CDrawingManager local_110 [8];
  undefined **local_108;
  undefined **local_100;
  HBRUSH local_fc;
  undefined **local_f8;
  HBRUSH local_f4;
  undefined **local_f0;
  undefined **local_e8 [2];
  undefined **local_e0;
  HBRUSH local_dc;
  int local_d8;
  undefined **local_d4;
  undefined4 local_d0;
  undefined1 local_cc [4];
  int local_c8;
  int local_c4;
  int *local_c0;
  int *local_bc;
  int local_b8;
  int local_b4;
  CDC *local_b0;
  int local_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  RECT local_9c;
  RECT local_8c;
  tagRECT local_7c;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  tagRECT local_4c;
  POINT local_3c;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_8;
  uStack_4 = 0x100;
  local_8 = 0x8ab936;
  local_b0 = param_1;
  local_c0 = param_8;
  pcVar1 = *(code **)(*param_8 + 0x288);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if ((iVar3 != 0) && (iVar3 = FUN_007c2511(), 8 < *(int *)(iVar3 + 0x1ac))) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar3 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar3 == 0) {
      pcVar1 = *(code **)(*piVar2 + 0x290);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        pcVar1 = *(code **)(*piVar2 + 0x180);
        local_5c = iVar3;
        local_58 = iVar3;
        local_54 = iVar3;
        local_50 = iVar3;
        guard_check_icall(&local_5c);
        (*pcVar1)();
        iVar3 = FUN_007f38ad(param_6);
        if ((iVar3 == 0) && (param_7 == 0)) {
          iVar3 = param_5 - param_3;
        }
        else {
          iVar3 = 0;
        }
        if ((param_2 + 10 + iVar3 <= local_54) && (local_5c < param_4 + -10)) {
          local_b8 = piVar2[0x45];
          pcVar1 = *(code **)(*piVar2 + 0x1dc);
          guard_check_icall(param_6);
          local_c4 = (*pcVar1)();
          if ((local_c4 == -1) && (param_7 != 0)) {
            iVar3 = FUN_007c2511();
            local_c4 = *(int *)(iVar3 + 0x6c);
          }
          local_b4 = piVar2[0x24];
          if (local_b4 == 0) {
            OffsetRect((LPRECT)&param_2,0,-1);
            local_b4 = piVar2[0x24];
          }
          local_4c.left = param_2;
          local_c8 = 0;
          local_3c.x = param_2;
          local_30 = param_3;
          local_4c.top = param_3;
          local_28 = param_3;
          local_4c.right = param_4;
          local_4c.bottom = param_5;
          local_d8 = param_5 - param_3;
          local_34 = param_2 + local_d8;
          local_24 = param_4;
          local_1c = param_4;
          local_3c.y = param_5;
          local_2c = param_4 + -2;
          iVar3 = 0;
          local_18 = param_5;
          local_20 = param_3 + 2;
          do {
            if (local_54 < (&local_3c)[iVar3].x) {
              (&local_3c)[iVar3].x = local_54;
              local_c8 = 1;
            }
            if (local_b4 == 0) {
              (&local_3c)[iVar3].y = (param_5 - (&local_3c)[iVar3].y) + param_3;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < 5);
          local_d4 = CRgn::vftable;
          local_d0 = 0;
          local_8 = 0;
          CreatePolygonRgn(&local_3c,5,2);
          Attach();
          pCVar4 = local_b0;
          FUN_0079eeb5();
          piVar2 = local_c0;
          local_7c.left = 0;
          local_7c.top = 0;
          local_7c.right = 0;
          local_7c.bottom = 0;
          GetClientRect((HWND)local_c0[8],&local_7c);
          local_7c.right = local_5c + -1;
          FUN_0079ea67();
          CDrawingManager::CDrawingManager(local_110,pCVar4);
          local_8._0_1_ = 1;
          local_b4 = local_c4;
          if (param_6 == local_b8) {
            local_b4 = local_bc[99];
          }
          if (local_b4 == -1) {
            local_b4 = local_bc[0x59];
            local_b8 = local_bc[0x5a];
          }
          else {
            local_b8 = FUN_008189e7(local_b4,0x3ff3851eb851eb85,0x3ff3851eb851eb85,
                                    0x3ff3851eb851eb85);
          }
          if (piVar2[0x24] == 0) {
            local_4c.top = local_4c.top + 1;
          }
          local_8c.left = local_4c.left;
          local_8c.bottom = (local_4c.top + local_4c.bottom) / 2 + -1;
          local_8c.top = local_4c.top;
          local_8c.right = local_4c.right;
          FUN_0079de5e();
          local_8._0_1_ = 2;
          FillRect(*(HDC *)(local_b0 + 4),&local_8c,local_fc);
          local_6c = local_4c.left;
          local_64 = local_4c.right;
          local_68 = local_8c.bottom;
          local_60 = local_8c.bottom + 3;
          FUN_00817861(local_4c.left,local_8c.bottom,local_4c.right,local_60,local_b4,local_b8,1,0,0
                      );
          local_9c.left = local_4c.left;
          local_9c.right = local_4c.right;
          local_9c.bottom = local_4c.bottom;
          local_9c.top = local_60;
          FUN_0079de5e();
          pCVar4 = local_b0;
          local_8 = CONCAT31(local_8._1_3_,3);
          FillRect(*(HDC *)(local_b0 + 4),&local_9c,local_f4);
          FUN_0079eeb5();
          FUN_0079ea67();
          piVar2 = local_c0;
          iVar3 = FUN_007f38ad();
          if ((iVar3 == 0) && (param_7 == 0)) {
            pcVar1 = *(code **)(*piVar2 + 0x29c);
            guard_check_icall();
            iVar3 = (*pcVar1)();
            pCVar4 = local_b0;
            if (param_6 != iVar3) {
              local_6c = local_5c;
              local_64 = (local_4c.bottom - local_4c.top) + local_4c.left + -10;
              local_68 = local_58;
              local_60 = local_50;
              if (local_c0[0x24] == 0) {
                local_68 = local_58 + -2;
              }
              else {
                local_60 = local_50 + 1;
              }
              FUN_0079ea67();
            }
          }
          FUN_007c2511();
          FUN_0079df60();
          local_8._0_1_ = 4;
          FUN_007c2511();
          FUN_0079df60();
          local_8 = CONCAT31(local_8._1_3_,5);
          local_b8 = FUN_0079efbc();
          pcVar1 = *(code **)(*(int *)pCVar4 + 0x24);
          guard_check_icall();
          local_b4 = (*pcVar1)();
          Polyline(*(HDC *)(pCVar4 + 4),&local_3c,5);
          if (local_c8 != 0) {
            FUN_0079ec58(local_cc,local_54,param_3);
            CDC::LineTo(pCVar4,local_54,param_5);
          }
          pCVar4 = local_b0;
          iStack_a8 = local_58;
          iStack_a4 = local_54;
          iStack_a0 = local_50;
          local_ac = local_4c.right;
          FUN_0079ea67(&local_ac);
          iVar3 = FUN_007c2511();
          FUN_0079df60(0,1,*(undefined4 *)(iVar3 + 0x5c));
          local_8 = CONCAT31(local_8._1_3_,6);
          FUN_0079efbc(local_e8);
          piVar2 = local_c0;
          if (local_c0[0x24] != 0) {
            FUN_0079ec58(local_cc,local_4c.left + 1,local_4c.bottom);
            iVar3 = local_4c.top + 1;
            CDC::LineTo(local_b0,local_d8 + local_4c.left,iVar3);
            pCVar4 = local_b0;
            CDC::LineTo(local_b0,local_4c.right + -1,iVar3);
          }
          FUN_0079efbc(local_b8);
          FUN_0079efbc(local_b4);
          if (param_7 != 0) {
            local_4c.top = param_5;
            if (piVar2[0x24] == 0) {
              local_4c.top = param_3 + -1;
            }
            local_4c.left = param_2 + 2;
            local_4c.right = (local_4c.left - param_2) + param_4 + -1;
            local_4c.bottom = local_4c.top + 1;
            if (piVar2[0x24] == 0) {
              OffsetRect(&local_4c,-1,1);
            }
            if (local_54 <= local_4c.right) {
              local_4c.right = local_54;
            }
            FUN_0079de5e(local_c4);
            FillRect(*(HDC *)(pCVar4 + 4),&local_4c,local_dc);
            local_e0 = CBrush::vftable;
            FUN_00416100();
          }
          iVar3 = param_5 - param_3;
          if (piVar2[0x24] == 0) {
            iVar3 = iVar3 + DAT_00a0067c;
          }
          else {
            param_4 = param_4 - DAT_00a0067c;
          }
          param_2 = param_2 + iVar3;
          pcVar1 = *(code **)(*piVar2 + 0x1e4);
          guard_check_icall(param_6);
          iVar3 = (*pcVar1)();
          local_c8 = -1;
          if ((param_7 == 0) && (iVar3 != -1)) {
            pcVar1 = *(code **)(*(int *)local_b0 + 0x30);
            guard_check_icall();
            local_c8 = (*pcVar1)();
          }
          pCVar4 = local_b0;
          if (local_54 + -2 <= param_4) {
            param_4 = local_54 + -2;
          }
          pcVar1 = *(code **)(*local_bc + 0xfc);
          guard_check_icall(local_b0,param_2,param_3,param_4,param_5,param_6,param_7,piVar2,
                            0xffffffff);
          (*pcVar1)();
          if (local_c8 != -1) {
            pcVar1 = *(code **)(*(int *)pCVar4 + 0x30);
            guard_check_icall(local_c8);
            (*pcVar1)();
          }
          FUN_0079eeb5(0);
          local_e8[0] = CPen::vftable;
          FUN_00416100();
          local_108 = CPen::vftable;
          FUN_00416100();
          local_f0 = CPen::vftable;
          FUN_00416100();
          local_f8 = CBrush::vftable;
          FUN_00416100();
          local_100 = CBrush::vftable;
          FUN_00416100();
          FUN_0081510b();
          local_d4 = CRgn::vftable;
          FUN_00416100();
        }
        goto LAB_008ac0ce;
      }
    }
  }
  FUN_008a6afb(local_b0,param_2,param_3,param_4,param_5,param_6,param_7,piVar2);
LAB_008ac0ce:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[66] */
/* 008ac0d6  OnDrawTabsButtonBorder  47 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnDrawTabsButtonBorder(class CDC
   *,class CRect &,class CMFCButton *,unsigned int,class CMFCBaseTabCtrl *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnDrawTabsButtonBorder
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,CRect *param_2,CMFCButton *param_3,
          uint param_4,CMFCBaseTabCtrl *param_5)

{
  if ((*(int *)(param_3 + 0xac) != 0) || (*(int *)(param_3 + 0xb4) != 0)) {
    CDC::Draw3dRect(param_1,(tagRECT *)param_2,*(ulong *)(this + 0xe8),*(ulong *)(this + 0xe8));
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[94] */
/* 008ac105  FUN_008ac105  163 bytes, 1 callers */

void FUN_008ac105(CDC *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  undefined1 local_c [8];
  
  if (*(int *)(param_2 + 0x3c) == 0) {
    iVar5 = FUN_007c2511();
    uVar1 = *(undefined4 *)(iVar5 + 0x44);
    iVar5 = FUN_007c2511();
    uVar4 = *(undefined4 *)(iVar5 + 0x3c);
    iVar5 = FUN_007c2511();
    *(undefined4 *)(iVar5 + 0x44) = uVar4;
    FUN_008a6fdb(param_1,param_2,param_3,param_4,param_5);
    iVar5 = FUN_007c2511();
    *(undefined4 *)(iVar5 + 0x44) = uVar1;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0xc);
    iVar5 = *(int *)(param_2 + 0x10);
    iVar2 = *(int *)(param_2 + 0x14);
    iVar3 = *(int *)(param_2 + 0x18);
    uVar4 = FUN_0079efbc(in_ECX + 0x13c);
    iVar5 = (iVar5 + iVar3) / 2;
    FUN_0079ec58(local_c,uVar1,iVar5);
    CDC::LineTo(param_1,iVar2,iVar5);
    FUN_0079efbc(uVar4);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[93], CMFCVisualManagerOffice2007[93] */
/* 008ac1a8  FUN_008ac1a8  115 bytes, 0 callers */

void FUN_008ac1a8(CDC *param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_c [8];
  
  uVar1 = FUN_0079efbc(in_ECX + 0x1f0);
  FUN_0079ec58(local_c,param_2,param_3);
  CDC::LineTo(param_1,param_4 + -1,param_3);
  CDC::LineTo(param_1,param_4 + -1,param_5 + -1);
  CDC::LineTo(param_1,param_2,param_5 + -1);
  CDC::LineTo(param_1,param_2,param_3);
  FUN_0079efbc(uVar1);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[90] */
/* 008ac21b  FUN_008ac21b  1199 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ac21b(CDC *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  ulong uVar1;
  CDC *pCVar2;
  int iVar3;
  AFX_GLOBAL_DATA *this;
  int iVar4;
  HRGN pHVar5;
  undefined4 uVar6;
  COLORREF CVar7;
  int *piVar8;
  code *pcVar9;
  int iVar10;
  CDrawingManager local_b4 [8];
  undefined4 local_ac;
  undefined **local_a8;
  undefined4 local_a4;
  int local_a0;
  int local_9c;
  COLORREF local_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  CDC *local_7c;
  int local_78;
  int *local_74;
  int *local_70;
  int local_6c;
  int local_68;
  int local_64;
  int iStack_60;
  tagRECT local_5c;
  POINT local_4c;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  LONG local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa4;
  local_8 = 0x8ac22a;
  local_7c = param_1;
  local_78 = param_2;
  iVar3 = FUN_007c2511();
  if (8 < *(int *)(iVar3 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar4 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    iVar3 = local_78;
    if (iVar4 == 0) {
      local_74 = (int *)(param_2 + 0x34);
      local_a8 = CRgn::vftable;
      local_4c.x = *local_74;
      local_8c = *local_74;
      local_88 = *(int *)(param_2 + 0x38);
      local_84 = *(int *)(param_2 + 0x3c);
      local_80 = *(int *)(param_2 + 0x40);
      local_28 = *(int *)(local_78 + 0x38);
      local_4c.y = *(LONG *)(local_78 + 0x40);
      local_40 = local_28 + 4;
      local_3c = local_4c.x + 1;
      local_38 = local_28 + 2;
      local_34 = local_4c.x + 2;
      local_30 = local_28 + 1;
      local_2c = local_4c.x + 4;
      local_24 = *(undefined4 *)(local_78 + 0x3c);
      local_a4 = 0;
      local_8 = 0;
      local_44 = local_4c.x;
      local_20 = local_28;
      local_1c = local_24;
      local_18 = local_4c.y;
      pHVar5 = CreatePolygonRgn(&local_4c,7,2);
      Attach(pHVar5);
      FUN_0079eeb5(&local_a8);
      CDrawingManager::CDrawingManager(local_b4,param_1);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (*(int *)(iVar3 + 0x2c) == 0) {
        iVar4 = local_70[0x6f];
        iVar10 = local_70[0x70];
        piVar8 = local_74;
      }
      else {
        iVar4 = local_70[0x72];
        iVar10 = local_70[0x71];
        piVar8 = (int *)(iVar3 + 0x34);
      }
      FUN_00817861(*piVar8,piVar8[1],piVar8[2],piVar8[3],iVar10,iVar4,0,0,0);
      FUN_0079eeb5(0);
      iVar3 = local_78;
      if ((*(int *)(local_78 + 0x5c) == 0) ||
         (((local_88 - local_8c) - local_80) + local_84 <= *(int *)(local_78 + 0x54))) {
        local_a0 = 0;
      }
      else {
        local_a0 = 1;
        pcVar9 = *(code **)(*local_70 + 0x16c);
        guard_check_icall(param_1,local_78,5,param_3,param_4,param_5);
        (*pcVar9)();
      }
      pcVar9 = *(code **)(*(int *)param_1 + 0x28);
      iVar4 = FUN_007c2511();
      guard_check_icall(iVar4 + 300);
      local_90 = (*pcVar9)();
      local_98 = GetTextColor(*(HDC *)(param_1 + 8));
      if ((param_5 == 0) || (param_3 == 0)) {
        pcVar9 = *(code **)(*(int *)param_1 + 0x30);
        iVar4 = *(int *)(iVar3 + 0x60);
        if (iVar4 == -1) {
          if (*(int *)(iVar3 + 0x2c) == 0) {
            iVar4 = FUN_007c2511();
            iVar4 = *(int *)(iVar4 + 0x3c);
          }
          else {
            iVar4 = local_70[0x77];
          }
        }
      }
      else {
        pcVar9 = *(code **)(*(int *)param_1 + 0x30);
        iVar4 = *(int *)(iVar3 + 100);
        if (iVar4 == -1) {
          if (*(int *)(iVar3 + 0x2c) == 0) {
            iVar4 = FUN_007c2511();
            iVar4 = *(int *)(iVar4 + 0x3c);
          }
          else {
            iVar4 = local_70[0x77];
          }
        }
      }
      guard_check_icall(iVar4);
      (*pcVar9)();
      local_ac = FUN_0079f0b8(1);
      iVar3 = *(int *)(*(int *)(iVar3 + 4) + 8);
      local_74 = *(int **)(iVar3 + 0x3c0);
      iVar3 = *(int *)(iVar3 + 0x3bc);
      if (iVar3 == -1) {
        iVar3 = local_70[0x24];
      }
      iStack_60 = local_80;
      local_6c = iVar3;
      if (local_a0 != 0) {
        local_6c = *(int *)(local_78 + 0x54) + 5;
      }
      local_6c = local_6c + local_8c;
      local_68 = (int)local_74;
      if (local_74 == (int *)0xffffffff) {
        local_68 = local_70[0x25];
      }
      local_68 = local_88 + local_68;
      iVar4 = iVar3;
      if (param_5 != 0) {
        iVar4 = local_80 - local_88;
      }
      local_64 = local_6c;
      if (local_6c <= local_84 - iVar4) {
        if (param_5 != 0) {
          iVar3 = local_80 - local_88;
        }
        local_64 = local_84 - iVar3;
      }
      piVar8 = (int *)(local_78 + 8);
      FUN_007c2378(piVar8,&local_6c,0x8024);
      FUN_0079f0b8(local_ac);
      pcVar9 = *(code **)(*(int *)param_1 + 0x28);
      guard_check_icall(local_90);
      (*pcVar9)();
      pcVar9 = *(code **)(*(int *)param_1 + 0x30);
      guard_check_icall(local_98);
      (*pcVar9)();
      if ((param_5 != 0) && (*(int *)(*piVar8 + -0xc) != 0)) {
        FUN_0081507c(&local_9c);
        local_5c.left = local_8c;
        iVar3 = (-(((local_80 - local_88) + 1) / 2) - (local_9c + 1) / 2) + local_84;
        if (local_8c <= iVar3) {
          local_5c.left = iVar3;
        }
        iVar3 = (-(((local_80 - local_88) + 1) / 2) - (int)(local_98 + 1) / 2) + local_80;
        local_5c.top = local_88;
        if (local_88 <= iVar3) {
          local_5c.top = iVar3;
        }
        local_5c.right = local_5c.left + local_9c;
        local_5c.bottom = local_98 + local_5c.top;
        local_74 = (int *)local_5c.left;
        if ((local_5c.right <= local_84) && (local_5c.bottom <= local_80)) {
          if (param_3 != 0) {
            iVar3 = FUN_007c2511();
            uVar6 = FUN_0079efbc(iVar3 + 0xd0);
            CVar7 = GetBkColor(*(HDC *)(local_7c + 8));
            iVar3 = FUN_007c2511();
            uVar1 = *(ulong *)(iVar3 + 0x58);
            iVar3 = FUN_007c2511();
            pCVar2 = local_7c;
            CDC::Draw3dRect(local_7c,&local_5c,*(ulong *)(iVar3 + 0x6c),uVar1);
            pcVar9 = *(code **)(*(int *)pCVar2 + 0x2c);
            guard_check_icall(CVar7);
            (*pcVar9)();
            param_1 = local_7c;
            FUN_0079efbc(uVar6);
          }
          local_94 = 0;
          local_90 = 0;
          if (*(int *)(local_78 + 0x30) == 0) {
            uVar6 = 7;
          }
          else {
            uVar6 = 0;
          }
          FUN_00814c80(param_1,uVar6,&local_5c,0,&local_94);
        }
      }
      FUN_0081510b();
      local_a8 = CRgn::vftable;
      FUN_00416100();
      goto LAB_008ac6c2;
    }
  }
  FUN_008a72d6(param_1,param_2,param_3,param_4,param_5);
LAB_008ac6c2:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[30] */
/* 008ac6ca  FUN_008ac6ca  275 bytes, 1 callers */

void FUN_008ac6ca(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int param_6)

{
  code *pcVar1;
  int iVar2;
  AFX_GLOBAL_DATA *this;
  HBRUSH pHVar3;
  int *in_ECX;
  
  iVar2 = FUN_007c2511();
  if (8 < *(int *)(iVar2 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar2 == 0) {
      pHVar3 = (HBRUSH)0x0;
      if (in_ECX != (int *)0xfffffef4) {
        pHVar3 = (HBRUSH)in_ECX[0x44];
      }
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,pHVar3);
      InflateRect((LPRECT)&param_2,-1,-1);
      if (param_6 == 0) {
        pHVar3 = (HBRUSH)0x0;
        if (in_ECX != (int *)0xfffffe08) {
          pHVar3 = (HBRUSH)in_ECX[0x7f];
        }
        FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,pHVar3);
      }
      else {
        pcVar1 = *(code **)(*in_ECX + 0x314);
        guard_check_icall(param_1,param_2,param_3,param_4,param_5,in_ECX + 0x47,0);
        (*pcVar1)();
      }
      iVar2 = *in_ECX;
      guard_check_icall(param_1,param_2,param_3,param_4,param_5,0,0);
      (**(code **)(iVar2 + 0x44))();
      if (param_6 == 0) {
        return;
      }
      CDC::Draw3dRect(param_1,(tagRECT *)&param_2,in_ECX[0x39],in_ECX[0x39]);
      return;
    }
  }
  FUN_008a75c6(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[122], CMFCVisualManagerOffice2007[122] */
/* 008ac7dd  FUN_008ac7dd  366 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008ac7dd(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,
                 CMFCButton *param_6)

{
  code *pcVar1;
  CMFCButton *this;
  int iVar2;
  AFX_GLOBAL_DATA *this_00;
  HWND pHVar3;
  CWnd *pCVar4;
  int *in_ECX;
  HBRUSH local_28;
  HBRUSH local_20;
  tagRECT local_18;
  uint local_8;
  
  this = param_6;
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_007c2511();
  if (8 < *(int *)(iVar2 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar2 == 0) {
      iVar2 = CMFCButton::IsPressed(this);
      if (iVar2 == 0) {
        if ((*(int *)(this + 0xb4) == 0) && (*(int *)(this + 0xac) == 0)) {
          local_18.left = 0;
          local_18.top = 0;
          local_18.right = 0;
          local_18.bottom = 0;
          pHVar3 = GetParent(*(HWND *)(this + 0x20));
          pCVar4 = CWnd::FromHandle(pHVar3);
          GetClientRect(*(HWND *)(pCVar4 + 0x20),&local_18);
          pHVar3 = GetParent(*(HWND *)(this + 0x20));
          pCVar4 = CWnd::FromHandle(pHVar3);
          MapWindowPoints(*(HWND *)(pCVar4 + 0x20),*(HWND *)(this + 0x20),(LPPOINT)&local_18,2);
          pcVar1 = *(code **)(*in_ECX + 0x1dc);
          guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom);
          (*pcVar1)();
          return;
        }
        iVar2 = in_ECX[99];
        if (iVar2 == -1) {
          iVar2 = in_ECX[0x32];
        }
        FUN_0079de5e(iVar2);
        FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,local_28);
      }
      else {
        iVar2 = in_ECX[0x66];
        if (iVar2 == -1) {
          iVar2 = in_ECX[0x33];
        }
        FUN_0079de5e(iVar2);
        FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,local_20);
      }
      FUN_00416100();
      return;
    }
  }
  FUN_008a7798(param_1,param_2,param_3,param_4,param_5,this);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[60] */
/* 008ac94b  FUN_008ac94b  231 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008ac94b(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int *param_6)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  AFX_GLOBAL_DATA *this;
  HBRUSH hbr;
  undefined4 uVar4;
  undefined4 uVar5;
  CDrawingManager local_20 [8];
  int local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_6;
  uStack_4 = 0x10;
  local_8 = 0x8ac957;
  hbr = (HBRUSH)0x0;
  local_14 = param_1;
  if (param_6[0x4d] == 0) {
    pcVar1 = *(code **)(*param_6 + 0x280);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if ((iVar3 == 0) && (iVar3 = FUN_007c2511(), 8 < *(int *)(iVar3 + 0x1ac))) {
      this = (AFX_GLOBAL_DATA *)FUN_007c2511();
      iVar3 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
      if (iVar3 == 0) {
        CDrawingManager::CDrawingManager(local_20,local_14);
        local_8 = 0;
        uVar5 = *(undefined4 *)(local_18 + 0x164);
        uVar4 = *(undefined4 *)(local_18 + 0x168);
        if (piVar2[0x24] == 0) {
          uVar4 = uVar5;
          uVar5 = *(undefined4 *)(local_18 + 0x168);
        }
        FUN_00817861(param_2,param_3,param_4,param_5,uVar4,uVar5,1,0,0);
        FUN_0081510b();
        return;
      }
    }
    FUN_008a78ac(local_14,param_2,param_3,param_4,param_5,piVar2);
  }
  else {
    iVar3 = FUN_007c2511();
    if (iVar3 != -0x98) {
      hbr = *(HBRUSH *)(iVar3 + 0x9c);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[65] */
/* 008aca32  FUN_008aca32  556 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008aca32(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,
                 CMFCButton *param_6,CObject *param_7)

{
  code *pcVar1;
  CMFCButton *this;
  CObject *pCVar2;
  int iVar3;
  AFX_GLOBAL_DATA *this_00;
  HRGN pHVar4;
  HWND hWndTo;
  int iVar5;
  undefined **local_4c;
  undefined4 local_48;
  CDrawingManager local_44 [4];
  CObject *local_40;
  int *local_3c;
  CDC *local_38;
  undefined4 local_34;
  LONG local_30;
  undefined4 local_2c;
  LONG local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pCVar2 = param_7;
  this = param_6;
  uStack_4 = 0x3c;
  local_8 = 0x8aca3e;
  local_38 = param_1;
  local_40 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,param_7);
  if (local_40 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x280);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if ((iVar3 == 0) && (iVar3 = FUN_007c2511(), 8 < *(int *)(iVar3 + 0x1ac))) {
      this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
      iVar3 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
      if ((iVar3 == 0) && (*(int *)(pCVar2 + 0x134) == 0)) {
        pcVar1 = *(code **)(*(int *)pCVar2 + 0x288);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 == 0) {
          pcVar1 = *(code **)(*(int *)pCVar2 + 0x28c);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          if (iVar3 != 0) goto LAB_008acae3;
        }
        else {
LAB_008acae3:
          iVar3 = CMFCButton::IsPressed(this);
          if ((iVar3 != 0) || (*(int *)(this + 0xb4) != 0)) {
            CDrawingManager::CDrawingManager(local_44,local_38);
            local_8 = 0;
            iVar3 = CMFCButton::IsPressed(this);
            if (iVar3 == 0) {
              iVar3 = local_3c[100];
              iVar5 = local_3c[0x65];
            }
            else {
              iVar3 = local_3c[0x66];
              iVar5 = local_3c[0x67];
            }
            FUN_00817861(param_2,param_3,param_4,param_5,iVar5,iVar3,1,0,0);
            FUN_0081510b();
            goto LAB_008acc56;
          }
        }
        local_48 = 0;
        local_4c = CRgn::vftable;
        local_8 = 1;
        pHVar4 = CreateRectRgnIndirect((RECT *)&param_2);
        Attach(pHVar4);
        FUN_0079eeb5(&local_4c);
        pCVar2 = local_40;
        local_24.left = 0;
        local_24.top = 0;
        local_24.right = 0;
        local_24.bottom = 0;
        GetClientRect(*(HWND *)(local_40 + 0x20),&local_24);
        local_34 = 0;
        local_30 = 0;
        local_2c = 0;
        local_28 = 0;
        pcVar1 = *(code **)(*(int *)pCVar2 + 0x180);
        guard_check_icall(&local_34);
        (*pcVar1)();
        if (*(int *)(pCVar2 + 0x90) == 0) {
          local_24.top = local_30;
        }
        else {
          local_24.bottom = local_28;
        }
        if (this == (CMFCButton *)0x0) {
          hWndTo = (HWND)0x0;
        }
        else {
          hWndTo = *(HWND *)(this + 0x20);
        }
        MapWindowPoints(*(HWND *)(pCVar2 + 0x20),hWndTo,(LPPOINT)&local_24,2);
        pcVar1 = *(code **)(*local_3c + 0xf0);
        guard_check_icall(local_38,local_24.left,local_24.top,local_24.right,local_24.bottom,pCVar2)
        ;
        (*pcVar1)();
        FUN_0079eeb5(0);
        local_4c = CRgn::vftable;
        FUN_00416100();
        goto LAB_008acc56;
      }
    }
  }
  FUN_008a7924(local_38,param_2,param_3,param_4,param_5,this,pCVar2);
LAB_008acc56:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[68] */
/* 008acc5e  FUN_008acc5e  365 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_008acc5e(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int *param_6)

{
  code *pcVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  HBRUSH hbr;
  CDrawingManager local_24 [8];
  int local_1c;
  int local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar3 = param_6;
  uStack_4 = 0x14;
  local_8 = 0x8acc6a;
  local_14 = param_1;
  pcVar1 = *(code **)(*param_6 + 0x280);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if ((iVar4 != 0) || (iVar4 = FUN_007c2511(), *(int *)(iVar4 + 0x1ac) < 9)) {
LAB_008acdaa:
    uVar5 = FUN_007f96b7(local_14,param_2,param_3,param_4,param_5,piVar3);
    return uVar5;
  }
  this = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar4 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
  if ((iVar4 != 0) || (piVar3[0x4d] != 0)) goto LAB_008acdaa;
  pcVar1 = *(code **)(*piVar3 + 0x20c);
  pcVar2 = *(code **)(*piVar3 + 0x1dc);
  guard_check_icall();
  uVar5 = (*pcVar1)();
  guard_check_icall(uVar5);
  local_1c = (*pcVar2)();
  if (local_1c == -1) {
    pcVar1 = *(code **)(*piVar3 + 0x288);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      pcVar1 = *(code **)(*piVar3 + 0x28c);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) goto LAB_008acd4b;
    }
    iVar4 = FUN_007c2511();
    hbr = (HBRUSH)0x0;
    if (iVar4 != -200) {
      hbr = *(HBRUSH *)(iVar4 + 0xcc);
    }
    FillRect(*(HDC *)(local_14 + 4),(RECT *)&param_2,hbr);
  }
  else {
LAB_008acd4b:
    CDrawingManager::CDrawingManager(local_24,local_14);
    local_8 = 0;
    iVar4 = *(int *)(local_18 + 0x15c);
    if (local_1c != -1) {
      iVar4 = local_1c;
    }
    iVar6 = FUN_008188f6(iVar4,0x82);
    iVar7 = iVar6;
    if (piVar3[0x24] == 0) {
      iVar7 = iVar4;
      iVar4 = iVar6;
    }
    FUN_00817514(param_2,param_3,param_4,param_5,iVar4,iVar7,0x2d);
    FUN_0081510b();
  }
  return 1;
}




/* vtable slots: CMFCVisualManagerOffice2003[108], CMFCVisualManagerOffice2007[108] */
/* 008acdcb  FUN_008acdcb  183 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008acdcb(CDC *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8acdd7;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar1 == 0) {
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 0;
      if ((*(int *)(param_6 + 0x28) == 0) || (*(int *)(*(int *)(param_6 + 0x28) + 0x11c) == 0)) {
        uVar2 = FUN_0087a624();
        uVar4 = *(undefined4 *)(in_ECX + 0x15c);
        uVar3 = *(undefined4 *)(in_ECX + 0x160);
      }
      else {
        uVar2 = FUN_0087a624();
        uVar4 = *(undefined4 *)(in_ECX + 0x194);
        uVar3 = *(undefined4 *)(in_ECX + 400);
      }
      FUN_00817861(param_2,param_3,param_4,param_5,uVar3,uVar4,uVar2,0,0);
      FUN_0081510b();
      return;
    }
  }
  FUN_007f9665(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[13] */
/* 008ace82  FUN_008ace82  2191 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ace82(CDC *param_1,CObject *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,uint param_11)

{
  code *pcVar1;
  CDC *pCVar2;
  CObject *pCVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  int iVar6;
  AFX_GLOBAL_DATA *this;
  BOOL BVar7;
  HBRUSH hbr;
  uint uVar8;
  int *piVar9;
  CObject *pCVar10;
  CMFCCustomizeButton *this_00;
  int *in_ECX;
  int iVar11;
  tagRECT *ptVar12;
  HTHEME hTheme;
  HDC hdc;
  undefined4 uVar13;
  undefined4 uVar14;
  CDrawingManager local_84 [8];
  uint local_7c;
  uint local_78;
  int local_74;
  CObject *local_70;
  CObject *local_6c;
  int local_68;
  CObject *local_64;
  CDC *local_60;
  CObject *local_5c;
  int *local_58;
  tagRECT local_54;
  tagRECT local_44;
  undefined1 local_34 [12];
  LONG local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x8ace8e;
  local_70 = param_2;
  local_60 = param_1;
  if ((param_2 == (CObject *)0x0) || (param_1 == (CDC *)0x0)) goto LAB_008ad70c;
  local_58 = in_ECX;
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCReBar_0099792c,param_2);
  if (pCVar3 == (CObject *)0x0) {
    pHVar4 = GetParent(*(HWND *)(param_2 + 0x20));
    pCVar5 = CWnd::FromHandle(pHVar4);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCReBar_0099792c,(CObject *)pCVar5);
    if (pCVar3 == (CObject *)0x0) {
      pcVar1 = (code *)**(undefined4 **)param_2;
      guard_check_icall();
      (*pcVar1)();
      iVar6 = FUN_007c2511();
      if (8 < *(int *)(iVar6 + 0x1ac)) {
        this = (AFX_GLOBAL_DATA *)FUN_007c2511();
        iVar6 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
        if (((iVar6 == 0) && (*(int *)(param_2 + 0x8c) == 0)) &&
           (iVar6 = FUN_0079d960(&PTR_s_CMFCColorBar_00a007bc), iVar6 == 0)) {
          iVar6 = FUN_0079d98a(&PTR_s_CMFCStatusBar_009a0c24);
          piVar9 = local_58;
          if (((iVar6 == 0) || (DAT_00a00c64 == 0)) ||
             (hTheme = (HTHEME)local_58[5], hTheme == (HTHEME)0x0)) {
            iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonStatusBar_009a090c);
            if ((iVar6 == 0) || (piVar9[5] == 0)) {
              BVar7 = IsRectEmpty((RECT *)&param_7);
              pCVar2 = local_60;
              if (BVar7 != 0) {
                param_7 = param_3;
                param_8 = param_4;
                param_9 = param_5;
                param_10 = param_6;
                param_2 = local_70;
              }
              CDrawingManager::CDrawingManager(local_84,local_60);
              local_8 = 0;
              iVar6 = FUN_0079d98a(&PTR_s_CMFCCaptionBar_0099979c);
              if (iVar6 == 0) {
                iVar6 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
                if (iVar6 == 0) {
                  pcVar1 = *(code **)(*(int *)param_2 + 0x1c0);
                  guard_check_icall();
                  uVar8 = (*pcVar1)();
                  local_78 = uVar8 & 0xa000;
                  iVar6 = FUN_0079d98a(&PTR_s_CMFCToolBar_00a005c4);
                  if ((iVar6 == 0) ||
                     (iVar6 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00), iVar6 != 0)) {
                    local_68 = 0;
                  }
                  else {
                    local_68 = 1;
                  }
                  if ((uVar8 & 0xa000) == 0) {
                    local_74 = local_58[0x5c];
                    local_5c = (CObject *)local_58[0x5d];
                  }
                  else {
                    local_74 = local_58[0x59];
                    local_5c = (CObject *)local_58[0x5a];
                  }
                  if (local_68 == 0) {
                    local_78 = 0;
                    local_74 = local_58[0x57];
                    local_5c = (CObject *)local_58[0x58];
                    iVar6 = FUN_007c2511();
                    param_5 = param_3 + 10 + (*(int *)(iVar6 + 0x174) - *(int *)(iVar6 + 0x16c));
                  }
                  local_7c = -(uint)(local_68 != 0) & 0x19;
                  iVar6 = FUN_0079d98a(&PTR_s_CMFCDropDownToolBar_00a00b44);
                  pCVar3 = (CObject *)(~-(uint)(iVar6 != 0) & param_11);
                  local_6c = pCVar3;
                  local_64 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,param_2
                                               );
                  if ((pCVar3 == (CObject *)0x0) || (local_64 == (CObject *)0x0)) {
LAB_008ad37a:
                    local_44.left = param_3;
                    local_44.top = param_4;
                    local_44.right = param_5;
                    local_44.bottom = param_6;
                    if ((local_68 != 0) && (local_64 != (CObject *)0x0)) {
                      pcVar1 = *(code **)(*(int *)local_70 + 0x168);
                      guard_check_icall();
                      iVar6 = (*pcVar1)();
                      pCVar3 = local_64;
                      if (iVar6 != 0) {
                        pcVar1 = *(code **)(*(int *)local_64 + 0x1a0);
                        guard_check_icall();
                        iVar6 = (*pcVar1)();
                        if (iVar6 != 0) {
                          local_44.left = local_44.left - *(int *)(pCVar3 + 0x128);
                          local_44.right = local_44.right + *(int *)(pCVar3 + 300);
                          local_44.top = local_44.top - *(int *)(pCVar3 + 0x130);
                          local_44.bottom = local_44.bottom + *(int *)(pCVar3 + 0x134);
                        }
                      }
                    }
                    FUN_00817861(local_44.left,local_44.top,local_44.right,local_44.bottom,local_74,
                                 local_5c,local_78,local_7c,0);
                    local_68 = 0;
                    if (local_6c == (CObject *)0x0) goto LAB_008ad0b7;
                  }
                  else {
                    pcVar1 = *(code **)(*(int *)local_64 + 0x168);
                    guard_check_icall();
                    iVar6 = (*pcVar1)();
                    if (iVar6 == 0) goto LAB_008ad37a;
                    pcVar1 = *(code **)(*(int *)local_64 + 0x1a0);
                    guard_check_icall();
                    iVar6 = (*pcVar1)();
                    if ((iVar6 == 0) ||
                       (iVar6 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00), iVar6 != 0))
                    goto LAB_008ad37a;
                    local_68 = 1;
                    pHVar4 = GetParent(*(HWND *)(param_2 + 0x20));
                    pCVar5 = CWnd::FromHandle(pHVar4);
                    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,
                                                (CObject *)pCVar5);
                    local_6c = pCVar3;
                    if (pCVar3 != (CObject *)0x0) {
                      local_34._8_4_ = 0;
                      local_28 = 0;
                      MapWindowPoints(*(HWND *)(param_2 + 0x20),*(HWND *)(pCVar3 + 0x20),
                                      (LPPOINT)(local_34 + 8),1);
                      piVar9 = (int *)FUN_0079ece4(&local_44.right,local_34._8_4_,local_28);
                      local_34._8_4_ = *piVar9;
                      local_28 = piVar9[1];
                      local_24.left = 0;
                      local_24.top = 0;
                      local_24.right = 0;
                      local_24.bottom = 0;
                      GetClientRect(*(HWND *)(pCVar3 + 0x20),&local_24);
                      pcVar1 = *(code **)(*local_58 + 0x34);
                      guard_check_icall(local_60,local_6c,local_24.left,local_24.top,local_24.right,
                                        local_24.bottom,local_24.left,local_24.top,local_24.right,
                                        local_24.bottom,0);
                      (*pcVar1)();
                      FUN_0079f36c(&local_44.right,local_34._8_4_,local_28);
                    }
                    local_54.left = param_3;
                    local_54.top = param_4;
                    local_54.right = param_5;
                    local_54.bottom = param_6;
                    InflateRect(&local_54,-1,0);
                    FUN_00817861(local_54.left,local_54.top,local_54.right,local_54.bottom,local_74,
                                 local_5c,local_78,local_7c,0);
                    local_24.top = param_4 + 1;
                    local_24.left = param_3;
                    local_24.bottom = param_6;
                    local_24.right = param_3 + 1;
                    FUN_00817861(param_3,local_24.top,local_24.right,param_6,local_74,local_5c,
                                 local_78,0,0);
                    local_24.left = param_5 + -1;
                    local_24.top = param_4;
                    local_24.right = param_5;
                    local_24.bottom = param_6;
                    FUN_00817861(local_24.left,param_4,param_5,param_6,local_74,local_5c,local_78,0,
                                 0);
                  }
                  local_34._0_4_ = 0;
                  local_34._4_4_ = 0;
                  local_34._8_4_ = 0;
                  local_28 = 0;
                  local_5c = (CObject *)0x0;
                  SetRectEmpty((LPRECT)local_34);
                  pCVar3 = local_64;
                  this_00 = (CMFCCustomizeButton *)0x0;
                  if ((local_64 != (CObject *)0x0) &&
                     (iVar6 = FUN_007fdf7c(), this_00 = (CMFCCustomizeButton *)0x0, 0 < iVar6)) {
                    iVar6 = FUN_007fdf7c();
                    pCVar10 = (CObject *)FUN_007fde79(iVar6 + -1);
                    this_00 = (CMFCCustomizeButton *)
                              AfxDynamicDownCast((CRuntimeClass *)
                                                 &PTR_s_CMFCCustomizeButton_00a00ac4,pCVar10);
                    local_5c = (CObject *)this_00;
                    if (this_00 != (CMFCCustomizeButton *)0x0) {
                      local_34._0_4_ = *(undefined4 *)(this_00 + 0x54);
                      local_34._4_4_ = *(undefined4 *)(this_00 + 0x58);
                      local_34._8_4_ = *(undefined4 *)(this_00 + 0x5c);
                      local_28 = *(LONG *)(this_00 + 0x60);
                      pCVar3 = local_64;
                    }
                  }
                  if (local_68 != 0) {
                    local_6c = (CObject *)FUN_0079efbc(local_58 + 0x78);
                    if (local_6c == (CObject *)0x0) {
LAB_008ad70c:
                    /* WARNING: Subroutine does not return */
                      FUN_0078e714();
                    }
                    if (local_78 == 0) {
                      FUN_0079ec58(&local_44.right,param_5 + -1,param_4 + 2);
                      iVar11 = param_5 + -1;
                      iVar6 = param_6 + -2 + (local_34._4_4_ - local_28);
                    }
                    else {
                      FUN_0079ec58(&local_44.right,param_3 + 2,param_6 + -1);
                      iVar11 = (local_34._0_4_ - local_34._8_4_) + param_5;
                      iVar6 = param_6 + -1;
                    }
                    CDC::LineTo(local_60,iVar11,iVar6);
                    FUN_0079efbc(local_6c);
                  }
                  if ((((pCVar3 != (CObject *)0x0) && (iVar6 = FUN_007fdf7c(), 0 < iVar6)) &&
                      (this_00 != (CMFCCustomizeButton *)0x0)) &&
                     ((BVar7 = IsRectEmpty((RECT *)local_34), BVar7 == 0 &&
                      (iVar6 = CMFCCustomizeButton::IsPipeStyle(this_00), pCVar3 = local_70,
                      iVar6 != 0)))) {
                    uVar8 = FUN_00797acc();
                    local_6c = (CObject *)(uVar8 & 0x400000);
                    local_44.left = 0;
                    local_44.top = 0;
                    local_44.right = 0;
                    local_44.bottom = 0;
                    GetWindowRect(*(HWND *)(pCVar3 + 0x20),&local_44);
                    FUN_0079e8b8(local_34);
                    pCVar3 = local_64;
                    local_24.left = param_3;
                    local_24.top = param_4;
                    local_24.right = param_5;
                    local_24.bottom = param_6;
                    pcVar1 = *(code **)(*(int *)local_64 + 0x164);
                    guard_check_icall();
                    iVar6 = (*pcVar1)();
                    pCVar10 = local_5c;
                    if (iVar6 == 0) {
                      local_24.top = (local_34._4_4_ - local_44.bottom) + local_24.bottom;
                      *(int *)(local_5c + 0xf0) = 0;
                      *(LONG *)(local_5c + 0xec) = local_44.right - local_34._8_4_;
                    }
                    else {
                      if (local_6c == (CObject *)0x0) {
                        local_24.left = (local_24.right - local_44.right) + local_34._0_4_;
                      }
                      else {
                        local_24.left = (local_24.right - local_34._8_4_) + local_44.left;
                      }
                      *(int *)(local_5c + 0xec) = 0;
                      *(LONG *)(local_5c + 0xf0) = local_44.bottom - local_28;
                    }
                    local_68 = 0;
                    iVar6 = FUN_007fdf7c();
                    iVar6 = FUN_007fe765(iVar6 + -1);
                    if (iVar6 == 0) {
                      pcVar1 = *(code **)(*(int *)pCVar10 + 0x70);
                      guard_check_icall();
                      iVar6 = (*pcVar1)();
                      if (iVar6 != 0) goto LAB_008ad63d;
                      if ((*(uint *)(local_5c + 0x24) & 0x30000) != 0) {
                        local_68 = 1;
                      }
                    }
                    else {
LAB_008ad63d:
                      local_68 = 2;
                    }
                    local_70 = *(CObject **)(*local_58 + 0x31c);
                    local_6c = (CObject *)(uint)(*(int *)(local_5c + 0x11c) != 0);
                    local_7c = (uint)(0 < *(int *)(local_5c + 0xe8));
                    pcVar1 = *(code **)(*(int *)pCVar3 + 0x164);
                    guard_check_icall();
                    uVar13 = (*pcVar1)();
                    pCVar3 = local_70;
                    guard_check_icall(local_60,local_24.left,local_24.top,local_24.right,
                                      local_24.bottom,uVar13,local_68,local_7c,local_6c);
                    (*(code *)pCVar3)();
                  }
                }
                else {
                  if (local_58 == (int *)0xfffffef4) {
                    hbr = (HBRUSH)0x0;
                  }
                  else {
                    hbr = (HBRUSH)local_58[0x44];
                  }
                  FillRect(*(HDC *)(pCVar2 + 4),(RECT *)&param_7,hbr);
                  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenuBar_00a00938,
                                              param_2);
                  if (*(int *)(pCVar3 + 0xd40) == 0) {
                    local_24.left = param_3;
                    local_24.top = param_4;
                    local_24.right = param_5;
                    local_24.bottom = param_6;
                    local_24.right = FUN_0085358c();
                    local_24.right = local_24.right + local_24.left;
                    InflateRect(&local_24,0,-1);
                    uVar14 = 0x23;
                    uVar13 = 0;
                    iVar6 = local_58[0x59];
                    ptVar12 = &local_24;
                    iVar11 = local_58[0x5a];
                    goto LAB_008ad0a9;
                  }
                }
              }
              else {
                ptVar12 = (tagRECT *)&param_3;
                uVar14 = 0;
                if (*(int *)(param_2 + 0x2c4) == 0) {
                  uVar13 = 1;
                  iVar6 = local_58[0x6b];
                  iVar11 = local_58[0x6c];
                }
                else {
                  uVar13 = 0;
                  iVar6 = local_58[0x58];
                  iVar11 = local_58[0x57];
                }
LAB_008ad0a9:
                FUN_00817861(ptVar12->left,ptVar12->top,ptVar12->right,ptVar12->bottom,iVar11,iVar6,
                             uVar13,uVar14,0);
              }
LAB_008ad0b7:
              FUN_0081510b();
              goto LAB_008ad704;
            }
            hdc = *(HDC *)(local_60 + 4);
            hTheme = (HTHEME)piVar9[5];
          }
          else {
            hdc = *(HDC *)(local_60 + 4);
          }
          DrawThemeBackground(hTheme,hdc,0,0,(LPCRECT)&param_3,(LPCRECT)0x0);
          goto LAB_008ad704;
        }
      }
      FUN_008a7a00(local_60,local_70,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                   param_10,0);
      goto LAB_008ad704;
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x1c);
  guard_check_icall(local_60,local_70,param_3,param_4,param_5,param_6);
  (*pcVar1)();
LAB_008ad704:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[33] */
/* 008ad712  FUN_008ad712  395 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008ad712(undefined4 param_1,CObject *param_2,LONG param_3,LONG param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  CWnd *this;
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  CObject *this_00;
  int iVar4;
  AFX_GLOBAL_DATA *this_01;
  undefined4 uVar5;
  int local_24;
  CObject *local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = param_2;
  this_00 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,param_2);
  if (((this_00 != (CObject *)0x0) &&
      (iVar4 = CMFCCustomizeButton::IsPipeStyle((CMFCCustomizeButton *)this_00), iVar4 != 0)) &&
     (iVar4 = FUN_007c2511(), 8 < *(int *)(iVar4 + 0x1ac))) {
    this_01 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    local_18.left = AFX_GLOBAL_DATA::IsHighContrastMode(this_01);
    if (local_18.left == 0) {
      this = *(CWnd **)(this_00 + 0xf8);
      if (this != (CWnd *)0x0) {
        local_18.top = local_18.left;
        local_18.right = local_18.left;
        local_18.bottom = local_18.left;
        GetWindowRect(*(HWND *)(this + 0x20),&local_18);
        CWnd::ScreenToClient(this,&local_18);
        pcVar1 = *(code **)(*(int *)this + 0x164);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 == 0) {
          param_6 = local_18.bottom;
        }
        else {
          param_5 = local_18.right;
        }
        FUN_007fe00a(&local_24);
        InflateRect((LPRECT)&param_3,local_24,(int)local_20);
        local_20 = *(CObject **)(*local_1c + 0x31c);
        iVar4 = *(int *)(this_00 + 0x11c);
        iVar2 = *(int *)(this_00 + 0xe8);
        pcVar1 = *(code **)(*(int *)this + 0x164);
        guard_check_icall();
        uVar5 = (*pcVar1)();
        pCVar3 = local_20;
        guard_check_icall(param_1,param_3,param_4,param_5,param_6,uVar5,param_7,0 < iVar2,iVar4 != 0
                         );
        (*(code *)pCVar3)();
      }
      *(undefined4 *)(this_00 + 0x100) = 0;
      return;
    }
  }
  FUN_008a7c6e(param_1,local_20,param_3,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[78], CMFCVisualManagerOffice2007[78] */
/* 008ad89d  FUN_008ad89d  400 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008ad89d(CDC *param_1,int param_2,LONG param_3,LONG param_4,LONG param_5,int param_6)

{
  code *pcVar1;
  LONG LVar2;
  LONG LVar3;
  int iVar4;
  AFX_GLOBAL_DATA *this;
  int *piVar5;
  HBRUSH hbr;
  int iVar6;
  int *in_ECX;
  undefined4 uVar7;
  CDrawingManager local_30 [8];
  undefined1 local_28 [4];
  int local_24;
  undefined **local_20;
  HBRUSH local_1c;
  int *local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x8ad8a9;
  local_14 = param_1;
  local_18 = in_ECX;
  iVar4 = FUN_007c2511();
  if (8 < *(int *)(iVar4 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar4 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar4 == 0) {
      FUN_007c2511();
      iVar4 = *in_ECX;
      piVar5 = (int *)FUN_007fe1cf(local_28);
      pcVar1 = *(code **)(iVar4 + 0x2dc);
      guard_check_icall();
      local_24 = (*pcVar1)();
      local_24 = local_24 + *piVar5;
      if (param_6 != 0) {
        iVar4 = in_ECX[99];
        uVar7 = 0;
        param_2 = 0;
        if (iVar4 == -1) {
          iVar4 = local_18[0x32];
        }
        FUN_0079de5e(iVar4);
        local_8 = 0;
        FillRect(*(HDC *)(local_14 + 4),(RECT *)&param_2,local_1c);
        CDC::Draw3dRect(local_14,(tagRECT *)&param_2,local_18[0x3a],local_18[0x3a]);
        if ((((byte)iVar4 < 0x81) || ((byte)((uint)iVar4 >> 8) < 0x81)) ||
           ((byte)((uint)iVar4 >> 0x10) < 0x81)) {
          uVar7 = 0xffffff;
        }
        local_20 = CBrush::vftable;
        FUN_00416100();
        return uVar7;
      }
      if (in_ECX == (int *)0xfffffef4) {
        hbr = (HBRUSH)0x0;
      }
      else {
        hbr = (HBRUSH)in_ECX[0x44];
      }
      FillRect(*(HDC *)(local_14 + 4),(RECT *)&param_2,hbr);
      LVar3 = param_5;
      LVar2 = param_3;
      iVar4 = param_2;
      iVar6 = param_2 + local_24 + 2;
      CDrawingManager::CDrawingManager(local_30,local_14);
      local_8 = 1;
      FUN_00817861(iVar4,LVar2,iVar6,LVar3,local_18[0x5a],local_18[0x59],0,0,0);
      iVar4 = FUN_007c2511();
      uVar7 = *(undefined4 *)(iVar4 + 0x68);
      FUN_0081510b();
      return uVar7;
    }
  }
  uVar7 = FUN_008a7ec6(local_14,param_2,param_3,param_4,param_5,param_6);
  return uVar7;
}




/* vtable slots: CMFCVisualManagerOffice2003[85], CMFCVisualManagerOffice2007[85] */
/* 008ada2d  OnFillHeaderCtrlBackground  34 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnFillHeaderCtrlBackground(class
   CMFCHeaderCtrl *,class CDC *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnFillHeaderCtrlBackground
          (CMFCVisualManagerOffice2003 *this,undefined4 param_1,undefined4 param_2,
          undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  CMFCVisualManager::OnFillHeaderCtrlBackground
            ((CMFCVisualManager *)this,param_1,param_2,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[197] */
/* 008ada4f  FUN_008ada4f  553 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008ada4f(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int param_6,
                 CObject *param_7)

{
  code *pcVar1;
  int iVar2;
  AFX_GLOBAL_DATA *this;
  CObject *pCVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  CDrawingManager local_3c [8];
  undefined **local_34;
  HBRUSH local_30;
  CObject *local_2c;
  int local_28;
  CObject *local_24;
  undefined4 local_20;
  int local_1c;
  CDC *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pCVar3 = param_7;
  uStack_4 = 0x2c;
  local_8 = 0x8ada5b;
  local_18 = param_1;
  local_14 = param_6;
  local_2c = param_7;
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x1ac) < 9) goto LAB_008adc59;
  this = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
  if (iVar2 != 0) goto LAB_008adc59;
  local_20 = 1;
  local_1c = -1;
  iVar2 = -1;
  iVar4 = 0;
  if (pCVar3 == (CObject *)0x0) {
LAB_008adb87:
    if (local_14 == in_ECX + 0x11c) goto LAB_008adb95;
LAB_008adbb4:
    if ((local_14 == in_ECX + 0x124) && (*(int *)(in_ECX + 0x208) != 0)) {
      if (iVar4 == 0) {
        iVar5 = *(int *)(in_ECX + 0x198);
        iVar2 = *(int *)(in_ECX + 0x19c);
      }
      else {
        iVar5 = *(int *)(in_ECX + 0x198);
        iVar2 = iVar5;
      }
    }
    else {
      iVar5 = local_1c;
      if ((local_14 == in_ECX + 300) && (*(int *)(in_ECX + 0x208) != 0)) {
        if (iVar4 == 0) {
          iVar5 = *(int *)(in_ECX + 0x1a0);
          iVar2 = *(int *)(in_ECX + 0x1a4);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x1a0);
          iVar2 = iVar5;
        }
      }
    }
  }
  else {
    local_20 = *(undefined4 *)(pCVar3 + 0x4c);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar3);
    local_24 = pCVar3;
    if (((pCVar3 == (CObject *)0x0) || (*(int *)(pCVar3 + 0x6c) == 0)) ||
       (iVar4 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938), iVar4 == 0)) {
      iVar4 = 0;
      if (pCVar3 != (CObject *)0x0) {
        local_28 = 0;
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x70);
        guard_check_icall();
        iVar5 = (*pcVar1)();
        iVar4 = local_28;
        if (iVar5 != 0) {
          iVar2 = FUN_008188f6(*(undefined4 *)(in_ECX + 0x164),
                               (-(uint)(*(int *)(in_ECX + 0x208) != 0) & 0xffffffed) + 0x78);
          local_1c = FUN_008188f6(*(undefined4 *)(in_ECX + 0x168),0x6e);
          iVar4 = 0;
        }
      }
      goto LAB_008adb87;
    }
    iVar4 = 1;
    if (local_14 != in_ECX + 0x11c) goto LAB_008adb87;
    if (*(int *)(in_ECX + 0x18c) != -1) {
      FUN_0079de5e(*(int *)(in_ECX + 0x18c));
      FillRect(*(HDC *)(local_18 + 4),(RECT *)&param_2,local_30);
      local_34 = CBrush::vftable;
      FUN_00416100();
      return;
    }
LAB_008adb95:
    if (*(int *)(in_ECX + 0x208) == 0) goto LAB_008adbb4;
    iVar2 = *(int *)(in_ECX + 0x194);
    iVar5 = iVar2;
    if (iVar4 == 0) {
      iVar5 = *(int *)(in_ECX + 400);
    }
  }
  if ((iVar2 != -1) && (iVar5 != -1)) {
    CDrawingManager::CDrawingManager(local_3c,local_18);
    local_8 = 0;
    FUN_00817861(param_2,param_3,param_4,param_5,iVar2,iVar5,local_20,0,0);
    FUN_0081510b();
    return;
  }
LAB_008adc59:
  CMFCVisualManagerOfficeXP::OnFillHighlightedArea();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[59] */
/* 008adc78  OnFillOutlookBarCaption  152 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnFillOutlookBarCaption(class CDC
   *,class CRect,unsigned long &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnFillOutlookBarCaption
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8adc84;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 0;
      FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(this + 0x1b0),
                   *(undefined4 *)(this + 0x1ac),1,0,0);
      iVar1 = FUN_007c2511();
      *param_7 = *(undefined4 *)(iVar1 + 0x5c);
      FUN_0081510b();
      return;
    }
  }
  FUN_007f9bd1(param_1,param_3,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[56] */
/* 008add10  OnFillOutlookPageButton  215 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnFillOutlookPageButton(class CDC
   *,class CRect const &,int,int,unsigned long &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnFillOutlookPageButton
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,CRect *param_2,int param_3,int param_4,
          ulong *param_5)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  undefined4 uVar2;
  undefined4 uVar3;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8add1c;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      uVar3 = *(undefined4 *)(this + 0x15c);
      uVar2 = *(undefined4 *)(this + 0x160);
      if (param_4 == 0) {
        if (param_3 != 0) {
          uVar3 = *(undefined4 *)(this + 0x194);
          uVar2 = *(undefined4 *)(this + 400);
        }
      }
      else if (param_3 == 0) {
        uVar3 = *(undefined4 *)(this + 0x198);
        uVar2 = *(undefined4 *)(this + 0x19c);
      }
      else {
        uVar3 = *(undefined4 *)(this + 0x19c);
        uVar2 = *(undefined4 *)(this + 0x198);
      }
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 0;
      FUN_00817861(*(undefined4 *)param_2,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                   *(undefined4 *)(param_2 + 0xc),uVar3,uVar2,1,0,0);
      iVar1 = FUN_007c2511();
      *param_5 = *(ulong *)(iVar1 + 0x28);
      FUN_0081510b();
      return;
    }
  }
  FUN_007f9c00(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[119] */
/* 008adde7  OnFillPopupWindowBackground  136 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnFillPopupWindowBackground(class
   CDC *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnFillPopupWindowBackground
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8addf3;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 0;
      FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(this + 0x15c),
                   *(undefined4 *)(this + 0x160),1,0,0);
      FUN_0081510b();
      return;
    }
  }
  CMFCVisualManagerOfficeXP::OnFillPopupWindowBackground
            ((CMFCVisualManagerOfficeXP *)this,param_1,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[62] */
/* 008ade6f  FUN_008ade6f  426 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008ade6f(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,
                 undefined4 param_6,undefined4 param_7,int param_8,int *param_9)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  AFX_GLOBAL_DATA *this;
  int iVar4;
  HBRUSH hbr;
  CDrawingManager local_24 [8];
  int local_1c;
  CDC *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_9;
  uStack_4 = 0x14;
  local_8 = 0x8ade7b;
  local_18 = param_1;
  local_1c = param_6;
  pcVar1 = *(code **)(*param_9 + 0x280);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if ((iVar3 != 0) || (iVar3 = FUN_007c2511(), *(int *)(iVar3 + 0x1ac) < 9)) {
LAB_008adfef:
    FUN_008a86c8(local_18,param_2,param_3,param_4,param_5,local_1c,param_7,param_8,piVar2);
    return;
  }
  this = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar3 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
  if ((iVar3 != 0) || (hbr = (HBRUSH)0x0, piVar2[0x4d] != 0)) goto LAB_008adfef;
  local_1c = FUN_008188f6(*(undefined4 *)(local_14 + 0x15c),0x69);
  pcVar1 = *(code **)(*piVar2 + 0x1dc);
  guard_check_icall(param_7);
  iVar3 = (*pcVar1)();
  if (iVar3 == -1) {
    iVar3 = local_1c;
    if (*(int *)(local_14 + 0x74) == 0) {
      pcVar1 = *(code **)(*piVar2 + 0x28c);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      iVar3 = local_1c;
      if (iVar4 == 0) {
        pcVar1 = *(code **)(*piVar2 + 0x290);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        iVar3 = local_1c;
        if (iVar4 == 0) {
          if (param_8 == 0) {
            return;
          }
          goto LAB_008adfa0;
        }
      }
    }
  }
  else {
    pcVar1 = *(code **)(*piVar2 + 0x1dc);
    guard_check_icall(param_7);
    iVar3 = (*pcVar1)();
    iVar4 = FUN_007c2511();
    if (iVar3 != *(int *)(iVar4 + 0x6c)) goto LAB_008adfa0;
  }
  if (param_8 != 0) {
    iVar3 = FUN_007c2511();
    if (iVar3 != -200) {
      hbr = *(HBRUSH *)(iVar3 + 0xcc);
    }
    FillRect(*(HDC *)(local_18 + 4),(RECT *)&param_2,hbr);
    return;
  }
LAB_008adfa0:
  local_14 = FUN_008188f6(iVar3,0x78);
  CDrawingManager::CDrawingManager(local_24,local_18);
  local_8 = 0;
  iVar4 = local_14;
  if (piVar2[0x24] == 1) {
    iVar4 = iVar3;
    iVar3 = local_14;
  }
  FUN_00817861(param_2,param_3,param_4,param_5,iVar4,iVar3,1,0,0);
  FUN_0081510b();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[92], CMFCVisualManagerOffice2007[92] */
/* 008ae019  OnFillTasksGroupInterior  158 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnFillTasksGroupInterior(class CDC
   *,class CRect,int)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnFillTasksGroupInterior
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,int param_7)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  undefined4 uVar2;
  undefined4 uVar3;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8ae025;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 0;
      if (param_7 == 0) {
        uVar3 = *(undefined4 *)(this + 0x1cc);
        uVar2 = *(undefined4 *)(this + 0x1d0);
      }
      else {
        uVar3 = *(undefined4 *)(this + 0x1c8);
        uVar2 = *(undefined4 *)(this + 0x1c4);
      }
      FUN_00817861(param_3,param_4,param_5,param_6,uVar2,uVar3,1,0,0);
      FUN_0081510b();
      return;
    }
  }
  FUN_008a87db(param_1,param_3,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[89], CMFCVisualManagerOffice2007[89] */
/* 008ae0b7  OnFillTasksPaneBackground  136 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2003::OnFillTasksPaneBackground(class CDC
   *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2003::OnFillTasksPaneBackground
          (CMFCVisualManagerOffice2003 *this,CDC *param_1,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8ae0c3;
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 0;
      FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(this + 0x1b4),
                   *(undefined4 *)(this + 0x1b8),1,0,0);
      FUN_0081510b();
      return;
    }
  }
  CMFCVisualManager::OnFillTasksPaneBackground
            ((CMFCVisualManager *)this,param_1,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[192], CMFCVisualManagerOffice2007[192] */
/* 008ae13f  FUN_008ae13f  127 bytes, 0 callers */

void FUN_008ae13f(CDC *param_1)

{
  AFX_GLOBAL_DATA *this;
  int iVar1;
  HBRUSH hbr;
  HBRUSH in_ECX;
  
  this = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
  if (iVar1 == 0) {
    FUN_0079de5e(in_ECX[0x5a].unused);
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,in_ECX);
    FUN_00416100();
  }
  else {
    hbr = (HBRUSH)0x0;
    if (in_ECX != (HBRUSH)0xffffff04) {
      hbr = (HBRUSH)in_ECX[0x40].unused;
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
  }
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,in_ECX[0x39].unused,in_ECX[0x39].unused);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[40] */
/* 008ae1be  FUN_008ae1be  186 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008ae1be(CDC *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  AFX_GLOBAL_DATA *this;
  int *in_ECX;
  undefined1 local_20 [8];
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x8ae1ca;
  pcVar1 = *(code **)(*in_ECX + 0x2dc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  piVar3 = (int *)FUN_007fe1cf(local_20);
  iVar2 = *piVar3 + param_2 + 1 + iVar2 * 2;
  iVar4 = FUN_007c2511();
  if (8 < *(int *)(iVar4 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar4 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar4 == 0) {
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 0;
      FUN_00817861(param_2 + -1,param_3,iVar2,param_5,in_ECX[0x2f],in_ECX[0x59],0,0,0);
      FUN_0081510b();
      return;
    }
  }
  FUN_008a88fd(param_1,param_2 + -1,param_3,iVar2,param_5);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2003[12] */
/* 008ae278  FUN_008ae278  2732 bytes, 1 callers */

void FUN_008ae278(void)

{
  code *pcVar1;
  int iVar2;
  HWND hwnd;
  HTHEME pvVar3;
  undefined4 uVar4;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar5;
  COLORREF CVar6;
  HPEN pHVar7;
  CMFCBaseVisualManager *in_ECX;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 local_24;
  undefined8 local_1c;
  COLORREF local_14;
  COLORREF local_10;
  COLORREF local_c;
  COLORREF local_8;
  
  CMFCBaseVisualManager::UpdateSystemColors(in_ECX);
  if (DAT_00a00c60 == 0) {
    iVar2 = FUN_00404c80();
    hwnd = (HWND)0x0;
    if (iVar2 != 0) {
      hwnd = *(HWND *)(iVar2 + 0x20);
    }
    pvVar3 = GetWindowTheme(hwnd);
    if (pvVar3 != (HTHEME)0x0) goto LAB_008ae2ac;
    iVar2 = -1;
  }
  else {
LAB_008ae2ac:
    pcVar1 = *(code **)(*(int *)in_ECX + 0x28);
    guard_check_icall();
    iVar2 = (*pcVar1)();
  }
  *(int *)(in_ECX + 0x158) = iVar2;
  if ((DAT_00a00c68 == 0) && (iVar2 != -1)) {
    *(undefined4 *)(in_ECX + 0x158) = 0;
LAB_008ae2eb:
    uVar4 = 0;
  }
  else {
    if ((iVar2 != 1) && ((iVar2 != 2 && (iVar2 != 3)))) goto LAB_008ae2eb;
    uVar4 = 1;
  }
  *(undefined4 *)(in_ECX + 0x208) = uVar4;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x324);
  guard_check_icall();
  (*pcVar1)();
  FUN_008a895f();
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x1ac) < 9) {
LAB_008aec3f:
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1b4) = *(undefined4 *)(iVar2 + 0x6c);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1b8) = *(undefined4 *)(iVar2 + 0x6c);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1bc) = *(undefined4 *)(iVar2 + 0x54);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1c0) = *(undefined4 *)(iVar2 + 0x54);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1c4) = *(undefined4 *)(iVar2 + 0x54);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1c8) = *(undefined4 *)(iVar2 + 0x54);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1cc) = *(undefined4 *)(iVar2 + 0x6c);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1d0) = *(undefined4 *)(iVar2 + 0x6c);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1d4) = *(undefined4 *)(iVar2 + 0x6c);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1d8) = *(undefined4 *)(iVar2 + 0x6c);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1dc) = *(undefined4 *)(iVar2 + 0x20);
    iVar2 = FUN_007c2511();
    uVar4 = *(undefined4 *)(iVar2 + 100);
    *(undefined4 *)(in_ECX + 0x168) = uVar4;
    *(undefined4 *)(in_ECX + 0x160) = uVar4;
    CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x1f0));
    pHVar7 = CreatePen(0,1,*(COLORREF *)(in_ECX + 0x1dc));
    Attach(pHVar7);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x16c) = *(undefined4 *)(iVar2 + 0x24);
    return;
  }
  this = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
  if (iVar2 != 0) goto LAB_008aec3f;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x318);
  guard_check_icall();
  uVar4 = (*pcVar1)();
  iVar2 = *(int *)(in_ECX + 0x158);
  local_24 = 0x3ff0000000000000;
  local_1c = 0x3ff07ae147ae147b;
  if (iVar2 == 2) {
    uVar5 = FUN_008188f6(uVar4,0x78);
    *(undefined4 *)(in_ECX + 0x164) = uVar5;
    if (*(int *)(in_ECX + 4) == 0) {
      CVar6 = GetSysColor(0xf);
    }
    else {
      CVar6 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),0xf);
    }
    uVar5 = FUN_0081909d(uVar4,CVar6,0x3febd70a3d70a3d7,1,3);
    *(undefined4 *)(in_ECX + 0x15c) = uVar5;
    if (*(int *)(in_ECX + 4) == 0) {
      CVar6 = GetSysColor(5);
    }
    else {
      CVar6 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),5);
    }
    uVar8 = 0x100000002;
  }
  else {
    pvVar3 = *(HTHEME *)(in_ECX + 4);
    if (iVar2 != 3) {
      if (iVar2 == 1) {
        if (pvVar3 == (HTHEME)0x0) {
          CVar6 = GetSysColor(0xf);
        }
        else {
          CVar6 = GetThemeSysColor(pvVar3,0xf);
        }
        uVar5 = FUN_0081909d(uVar4,CVar6,0x3fedc28f5c28f5c3,2,1);
        *(undefined4 *)(in_ECX + 0x164) = uVar5;
        if (*(int *)(in_ECX + 4) == 0) {
          CVar6 = GetSysColor(0x16);
        }
        else {
          CVar6 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),0x16);
        }
        uVar5 = FUN_0081909d(uVar4,CVar6,0x3fefae147ae147ae,2,1);
        *(undefined4 *)(in_ECX + 0x15c) = uVar5;
        if (*(int *)(in_ECX + 4) == 0) {
          CVar6 = GetSysColor(5);
        }
        else {
          CVar6 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),5);
        }
        uVar5 = 1;
      }
      else {
        if (pvVar3 == (HTHEME)0x0) {
          CVar6 = GetSysColor(0xf);
        }
        else {
          CVar6 = GetThemeSysColor(pvVar3,0xf);
        }
        uVar5 = FUN_0081909d(uVar4,CVar6,0x3fedc28f5c28f5c3,2,1);
        *(undefined4 *)(in_ECX + 0x164) = uVar5;
        if (*(int *)(in_ECX + 4) == 0) {
          CVar6 = GetSysColor(0x16);
        }
        else {
          CVar6 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),0x16);
        }
        uVar5 = FUN_0081909d(uVar4,CVar6,0x3fefae147ae147ae,2,1);
        *(undefined4 *)(in_ECX + 0x15c) = uVar5;
        if (*(int *)(in_ECX + 4) == 0) {
          CVar6 = GetSysColor(5);
        }
        else {
          CVar6 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),5);
        }
        local_1c = 0x3ff0000000000000;
        uVar5 = 4;
      }
      uVar5 = FUN_0081909d(uVar4,CVar6,local_1c,1,uVar5);
      *(undefined4 *)(in_ECX + 0x168) = uVar5;
      goto LAB_008ae5a1;
    }
    if (pvVar3 == (HTHEME)0x0) {
      CVar6 = GetSysColor(0xf);
    }
    else {
      CVar6 = GetThemeSysColor(pvVar3,0xf);
    }
    uVar5 = FUN_0081909d(uVar4,CVar6,0x3fe8000000000000,2,1);
    *(undefined4 *)(in_ECX + 0x164) = uVar5;
    uVar5 = FUN_008188f6(uVar4,0x78);
    *(undefined4 *)(in_ECX + 0x15c) = uVar5;
    if (*(int *)(in_ECX + 4) == 0) {
      CVar6 = GetSysColor(0x14);
    }
    else {
      CVar6 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),0x14);
    }
    local_24 = 0x3fef5c28f5c28f5c;
    uVar8 = 0x100000001;
  }
  uVar5 = FUN_0081909d(uVar4,CVar6,local_24,uVar8);
  *(undefined4 *)(in_ECX + 0x168) = uVar5;
  if (*(int *)(in_ECX + 4) == 0) {
    CVar6 = GetSysColor(5);
  }
  else {
    CVar6 = GetThemeSysColor(*(HTHEME *)(in_ECX + 4),5);
  }
  uVar5 = FUN_0081909d(uVar4,CVar6,0x3ff07ae147ae147b,1,1);
LAB_008ae5a1:
  *(undefined4 *)(in_ECX + 0x160) = uVar5;
  *(undefined4 *)(in_ECX + 0x170) = *(undefined4 *)(in_ECX + 0x168);
  uVar5 = FUN_008188f6(*(undefined4 *)(in_ECX + 0x164),0x62);
  *(undefined4 *)(in_ECX + 0x174) = uVar5;
  if (*(int *)(in_ECX + 0x208) == 0) {
    *(undefined4 *)(in_ECX + 0x18c) = 0xffffffff;
    *(undefined4 *)(in_ECX + 400) = *(undefined4 *)(in_ECX + 200);
    *(undefined4 *)(in_ECX + 0x194) = *(undefined4 *)(in_ECX + 0xcc);
    uVar4 = FUN_008188f6(*(undefined4 *)(in_ECX + 200),0x78);
    *(undefined4 *)(in_ECX + 0x198) = uVar4;
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x178) = *(undefined4 *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    uVar4 = FUN_0081909d(*(undefined4 *)(in_ECX + 0x178),*(undefined4 *)(iVar2 + 0x54),
                         0x3ff0000000000000,1,1);
    *(undefined4 *)(in_ECX + 0x17c) = uVar4;
    uVar4 = FUN_008188f6(*(undefined4 *)(in_ECX + 0x164),0x4b);
    *(undefined4 *)(in_ECX + 0x180) = uVar4;
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x184) = *(undefined4 *)(iVar2 + 100);
    *(undefined4 *)(in_ECX + 0x188) = *(undefined4 *)(in_ECX + 0x164);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1a8) = *(undefined4 *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    local_1c._4_4_ = *(COLORREF *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1ac) = *(undefined4 *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(in_ECX + 0x1b0) = *(undefined4 *)(iVar2 + 0x60);
  }
  else {
    if (*(int *)(in_ECX + 0x158) == 1) {
      local_14 = 0x3d5de4;
      local_c = 0x58c4fa;
      local_10 = 0x58c4fa;
    }
    else {
      GetThemeColor(*(HTHEME *)(in_ECX + 0x10),1,0,0xeef,&local_c);
      GetThemeColor(*(HTHEME *)(in_ECX + 0x10),2,0,0xeef,&local_10);
      GetThemeColor(*(HTHEME *)(in_ECX + 4),0x12,0,0xeed,&local_14);
    }
    uVar5 = FUN_0081909d(local_c,local_10,0x3ff4cccccccccccd,1,1);
    *(undefined4 *)(in_ECX + 0x18c) = uVar5;
    uVar5 = FUN_0081909d(local_c,local_14,0x3ff8cccccccccccd,2,1);
    *(undefined4 *)(in_ECX + 400) = uVar5;
    uVar5 = FUN_0081909d(local_c,local_10,0x3ff07ae147ae147b,2,1);
    *(undefined4 *)(in_ECX + 0x194) = uVar5;
    uVar5 = FUN_0081909d(local_c,local_14,0x3ff07ae147ae147b,1,2);
    *(undefined4 *)(in_ECX + 0x198) = uVar5;
    CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x134));
    GetThemeColor(*(HTHEME *)(in_ECX + 0x10),2,0,0xeee,&local_8);
    CVar6 = FUN_0081909d(local_8,uVar4,0x3feae147ae147ae1,1,4);
    CreateSolidBrush(CVar6);
    Attach();
    iVar2 = *(int *)(in_ECX + 0x158);
    if ((iVar2 == 1) || (iVar2 == 3)) {
      *(undefined4 *)(in_ECX + 0x178) = 0x8e3907;
      if (iVar2 == 1) {
        uVar8 = 0x3ff9c28f5c28f5c3;
      }
      else {
        uVar8 = 0x3ff0000000000000;
      }
      uVar5 = FUN_0081909d(0x8e3907,uVar4,uVar8,3,1);
      *(undefined4 *)(in_ECX + 0x17c) = uVar5;
      GetThemeColor(*(HTHEME *)(in_ECX + 0x10),1,5,0xeef,&local_8);
    }
    else {
      uVar5 = FUN_0081909d(local_8,uVar4,0x3fe428f5c28f5c29,1,3);
      *(undefined4 *)(in_ECX + 0x178) = uVar5;
      GetThemeColor(*(HTHEME *)(in_ECX + 0x10),1,5,0xeef,&local_8);
      uVar5 = FUN_0081909d(local_8,uVar4,0x3ff3333333333333,1,3);
      *(undefined4 *)(in_ECX + 0x17c) = uVar5;
    }
    uVar5 = *(undefined4 *)(in_ECX + 0x178);
    iVar2 = FUN_007c2511();
    *(undefined4 *)(iVar2 + 0x60) = uVar5;
    iVar2 = *(int *)(in_ECX + 0x158);
    if (iVar2 != 3) {
      uVar5 = FUN_0081909d(local_8,uVar4,0x3ff6666666666666,1,3);
      iVar2 = FUN_007c2511();
      *(undefined4 *)(iVar2 + 0x58) = uVar5;
      iVar2 = *(int *)(in_ECX + 0x158);
    }
    uVar5 = FUN_008188f6(*(undefined4 *)(in_ECX + 0x164),((iVar2 == 3) - 1 & 0xffffffe2) + 0x50);
    *(undefined4 *)(in_ECX + 0x180) = uVar5;
    uVar5 = FUN_008188f6(*(undefined4 *)(in_ECX + 0x168),0x5c);
    *(undefined4 *)(in_ECX + 0x184) = uVar5;
    uVar5 = FUN_008188f6(*(undefined4 *)(in_ECX + 0x164),0x61);
    *(undefined4 *)(in_ECX + 0x188) = uVar5;
    uVar5 = FUN_008188f6(*(undefined4 *)(in_ECX + 0x174),0x28);
    *(undefined4 *)(in_ECX + 0x1a8) = uVar5;
    local_1c._4_4_ = FUN_008188f6(*(undefined4 *)(in_ECX + 0x174),0x51);
    *(undefined4 *)(in_ECX + 0xe8) = *(undefined4 *)(in_ECX + 0x1a8);
    uVar4 = FUN_008188f6(uVar4,0x50);
    *(undefined4 *)(in_ECX + 0x1b0) = *(undefined4 *)(in_ECX + 0x178);
    uVar10 = 0x3feeb851eb851eb8;
    uVar9 = 0x3feeb851eb851eb8;
    uVar8 = 0x3feeb851eb851eb8;
    *(undefined4 *)(in_ECX + 0xe4) = uVar4;
    *(undefined4 *)(in_ECX + 0x1ac) = *(undefined4 *)(in_ECX + 0x17c);
    iVar2 = FUN_007c2511(0x3feeb851eb851eb8,0x3feeb851eb851eb8,0x3feeb851eb851eb8);
    uVar4 = FUN_008189e7(*(undefined4 *)(iVar2 + 0x6c),uVar8,uVar9,uVar10);
    *(undefined4 *)(in_ECX + 0xc0) = uVar4;
    CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x10c));
    CreateSolidBrush(*(COLORREF *)(in_ECX + 0xc0));
    Attach();
  }
  *(undefined4 *)(in_ECX + 0x19c) = *(undefined4 *)(in_ECX + 0x194);
  *(undefined4 *)(in_ECX + 0x1a0) = *(undefined4 *)(in_ECX + 0x194);
  uVar4 = FUN_008188f6(*(undefined4 *)(in_ECX + 0x198),0x78);
  *(undefined4 *)(in_ECX + 0x1a4) = uVar4;
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x114));
  CreateSolidBrush(*(COLORREF *)(in_ECX + 0x168));
  Attach();
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x1e8));
  iVar2 = FUN_007c2511();
  CreatePen(0,1,*(COLORREF *)(iVar2 + 0x5c));
  Attach();
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x1f8));
  iVar2 = FUN_007c2511();
  CreateSolidBrush(*(COLORREF *)(iVar2 + 0x54));
  Attach();
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x200));
  CreateSolidBrush(*(COLORREF *)(in_ECX + 0x168));
  Attach();
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x13c));
  CreatePen(0,1,local_1c._4_4_);
  Attach();
  iVar2 = FUN_007c2511();
  *(undefined4 *)(in_ECX + 0xa8) = *(undefined4 *)(iVar2 + 0x54);
  uVar4 = FUN_0081909d(*(undefined4 *)(in_ECX + 0x164),*(undefined4 *)(in_ECX + 0x168),
                       0x3fed70a3d70a3d71,1,1);
  *(undefined4 *)(in_ECX + 0x16c) = uVar4;
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x1e0));
  CreatePen(0,1,*(COLORREF *)(in_ECX + 0x180));
  Attach();
  if ((*(int *)(in_ECX + 0x208) == 0) || (*(int *)(in_ECX + 0x28) == 0)) {
    *(undefined4 *)(in_ECX + 0x1b4) = *(undefined4 *)(in_ECX + 0x15c);
    *(undefined4 *)(in_ECX + 0x1b8) = *(undefined4 *)(in_ECX + 0x168);
    *(undefined4 *)(in_ECX + 0x1bc) = *(undefined4 *)(in_ECX + 0x15c);
    *(undefined4 *)(in_ECX + 0x1c0) = *(undefined4 *)(in_ECX + 0x168);
    uVar4 = 0x7d;
    iVar2 = FUN_007c2511();
    uVar4 = FUN_008188f6(*(undefined4 *)(iVar2 + 0x58),uVar4);
    uVar4 = FUN_0081909d(*(undefined4 *)(in_ECX + 0x178),uVar4,0x3ff0000000000000,1,1);
    *(undefined4 *)(in_ECX + 0x1c4) = uVar4;
    *(undefined4 *)(in_ECX + 0x1c8) = *(undefined4 *)(in_ECX + 0x17c);
    uVar4 = *(undefined4 *)(in_ECX + 0x168);
    *(undefined4 *)(in_ECX + 0x1cc) = uVar4;
    *(undefined4 *)(in_ECX + 0x1d0) = uVar4;
    *(undefined4 *)(in_ECX + 0x1d4) = uVar4;
    *(undefined4 *)(in_ECX + 0x1d8) = uVar4;
    *(undefined4 *)(in_ECX + 0x1dc) = uVar4;
  }
  else {
    GetThemeColor(*(HTHEME *)(in_ECX + 0x28),0,0,0xee2,(COLORREF *)(in_ECX + 0x1b8));
    GetThemeColor(*(HTHEME *)(in_ECX + 0x28),0,0,0xee3,(COLORREF *)(in_ECX + 0x1b4));
    GetThemeColor(*(HTHEME *)(in_ECX + 0x28),5,0,0xeda,(COLORREF *)(in_ECX + 0x1bc));
    GetThemeColor(*(HTHEME *)(in_ECX + 0x28),0xc,0,0xeda,(COLORREF *)(in_ECX + 0x1c4));
    *(COLORREF *)(in_ECX + 0x1c8) = *(COLORREF *)(in_ECX + 0x1bc);
    GetThemeColor(*(HTHEME *)(in_ECX + 0x28),5,0,0xeda,(COLORREF *)(in_ECX + 0x1cc));
    *(COLORREF *)(in_ECX + 0x1d0) = *(COLORREF *)(in_ECX + 0x1cc);
    GetThemeColor(*(HTHEME *)(in_ECX + 0x28),9,0,0xeed,(COLORREF *)(in_ECX + 0x1d4));
    *(COLORREF *)(in_ECX + 0x1d8) = *(COLORREF *)(in_ECX + 0x1d4);
    GetThemeColor(*(HTHEME *)(in_ECX + 0x28),5,0,0xed9,(COLORREF *)(in_ECX + 0x1dc));
    *(COLORREF *)(in_ECX + 0x1c0) = *(COLORREF *)(in_ECX + 0x1dc);
  }
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x1f0));
  CreatePen(0,1,*(COLORREF *)(in_ECX + 0x1dc));
  Attach();
  return;
}



