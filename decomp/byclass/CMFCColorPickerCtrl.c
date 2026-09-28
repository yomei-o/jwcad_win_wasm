/* CMFCColorPickerCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCColorPickerCtrl[1] */
/* 008cf43e  FUN_008cf43e  51 bytes, 0 callers */

void FUN_008cf43e(byte param_1)

{
  FUN_008cf36d();
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




/* vtable slots: CMFCColorPickerCtrl[91] */
/* 008cfa02  DrawCursor  390 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual void __thiscall CMFCColorPickerCtrl::DrawCursor(class CDC *,class CRect const
   &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCColorPickerCtrl::DrawCursor(CMFCColorPickerCtrl *this,CDC *param_1,CRect *param_2)

{
  HWND pHVar1;
  CWnd *pCVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined **local_3c [2];
  undefined **local_34;
  int local_30;
  POINT local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x8cfa0e;
  local_30 = (*(int *)(param_2 + 8) - *(int *)param_2) / 2;
  if (*(int *)(this + 0x80) == 2) {
    pHVar1 = GetFocus();
    pCVar2 = CWnd::FromHandle(pHVar1);
    uVar6 = -(uint)(pCVar2 != (CWnd *)this) & 0xffffff;
    FUN_007a500d(*(int *)param_2 + local_30 + -1,*(undefined4 *)(param_2 + 4),3,5,uVar6);
    FUN_007a500d(*(int *)param_2 + local_30 + -1,*(int *)(param_2 + 0xc) + -5,3,5,uVar6);
    FUN_007a500d(*(undefined4 *)param_2,*(int *)(param_2 + 4) + local_30 + -1,5,3,uVar6);
    FUN_007a500d(*(int *)(param_2 + 8) + -5,*(int *)(param_2 + 4) + local_30 + -1,5,3,uVar6);
  }
  else if (*(int *)(this + 0x80) == 1) {
    local_2c.x = *(LONG *)param_2;
    local_20 = *(int *)(param_2 + 4);
    local_2c.y = local_30 + local_20;
    local_24 = *(int *)(param_2 + 8) + -1;
    local_18 = *(int *)(param_2 + 0xc) + -1;
    local_1c = local_24;
    iVar3 = FUN_007c2511();
    FUN_0079df60(0,1,*(undefined4 *)(iVar3 + 0x28));
    local_8 = 0;
    pHVar1 = GetFocus();
    pCVar2 = CWnd::FromHandle(pHVar1);
    if (pCVar2 == (CWnd *)this) {
      iVar3 = FUN_007c2511();
      uVar4 = *(undefined4 *)(iVar3 + 0x28);
    }
    else {
      iVar3 = FUN_007c2511();
      uVar4 = *(undefined4 *)(iVar3 + 0x20);
    }
    FUN_0079de5e(uVar4);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar4 = FUN_0079efbc(local_3c);
    uVar5 = FUN_0079efbc(&local_34);
    Polygon(*(HDC *)(param_1 + 4),&local_2c,3);
    FUN_0079efbc(uVar4);
    FUN_0079efbc(uVar5);
    local_3c[0] = CBrush::vftable;
    FUN_00416100();
    local_34 = CPen::vftable;
    FUN_00416100();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorPickerCtrl[90] */
/* 008cfc13  FUN_008cfc13  790 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008cfc13(int *param_1)

{
  code *pcVar1;
  CDC *pCVar2;
  CPalette *pCVar3;
  HDC pHVar4;
  int iVar5;
  HBITMAP pHVar6;
  undefined4 uVar7;
  COLORREF CVar8;
  void *pvVar9;
  int *in_ECX;
  ulong uVar10;
  CDC *this;
  CDC local_70 [4];
  HDC__ *local_6c;
  undefined **local_60;
  void *local_5c;
  CGdiObject *local_58;
  CPalette *local_54;
  int local_50;
  CDC *local_4c;
  CDC *local_48;
  int local_44 [3];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x8cfc1f;
  if ((param_1 == (int *)0x0) || (*param_1 != 4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pCVar2 = CDC::FromHandle((HDC__ *)param_1[6]);
  local_48 = pCVar2;
  pCVar3 = CDC::SelectPalette(pCVar2,(CPalette *)in_ECX[0x2b],0);
  RealizePalette(*(HDC *)(pCVar2 + 4));
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  pcVar1 = *(code **)(*(int *)pCVar2 + 0x50);
  guard_check_icall(&local_34);
  (*pcVar1)();
  CopyRect(&local_24,(RECT *)(param_1 + 7));
  this = local_48;
  local_50 = 0;
  local_4c = local_48;
  CDC::CDC(local_70);
  local_5c = (void *)0x0;
  local_60 = CBitmap::vftable;
  local_8 = 1;
  local_58 = (CGdiObject *)0x0;
  local_54 = (CPalette *)0x0;
  pHVar4 = CreateCompatibleDC(*(HDC *)(this + 4));
  iVar5 = FUN_0079e84a(pHVar4);
  pCVar2 = this;
  if (iVar5 != 0) {
    pHVar6 = CreateCompatibleBitmap
                       (*(HDC *)(this + 4),local_24.right - local_24.left,
                        local_24.bottom - local_24.top);
    iVar5 = Attach(pHVar6);
    if (iVar5 != 0) {
      local_50 = 1;
      local_58 = CDC::SelectGdiObject(local_6c,local_5c);
      pCVar2 = local_70;
      local_4c = pCVar2;
      local_54 = CDC::SelectPalette(pCVar2,(CPalette *)in_ECX[0x2b],0);
      RealizePalette(local_6c);
      FUN_007c2511();
      FUN_007e58d9(in_ECX,pCVar2,0);
    }
  }
  iVar5 = in_ECX[0x20];
  if (iVar5 == 0) {
    CVar8 = GetTextColor(*(HDC *)(pCVar2 + 8));
    iVar5 = (local_24.bottom - local_24.top) / 2;
    FUN_007a500d(0,0,local_24.right - local_24.left,iVar5,in_ECX[0x28]);
    pCVar2 = local_4c;
    FUN_007a500d(0,iVar5,local_24.right - local_24.left,iVar5,in_ECX[0x29]);
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x30);
    guard_check_icall(CVar8);
    (*pcVar1)();
    iVar5 = FUN_007c2511();
    uVar10 = *(ulong *)(iVar5 + 0x30);
    iVar5 = FUN_007c2511();
  }
  else {
    if (iVar5 == 1) {
      FUN_008cff2a(pCVar2);
      FUN_007c2511();
      local_44[0] = in_ECX[0x2a];
      local_44[1] = 0;
      local_44[2] = (local_24.right - local_44[0]) - local_24.left;
      local_38 = local_24.bottom - local_24.top;
      FUN_007e58d9(in_ECX,pCVar2,local_44);
      pcVar1 = *(code **)(*in_ECX + 0x16c);
      uVar7 = FUN_008d04d5(local_44);
      guard_check_icall(pCVar2,uVar7);
      (*pcVar1)();
      this = local_48;
      goto LAB_008cfe9e;
    }
    if (iVar5 != 2) {
      if (iVar5 == 3) {
        FUN_008cf72d();
      }
      else {
        if (iVar5 != 4) goto LAB_008cfe9e;
        FUN_008cf4cc();
      }
      FUN_008cfb88(pCVar2);
      goto LAB_008cfe9e;
    }
    FUN_008cfff0(pCVar2);
    pcVar1 = *(code **)(*in_ECX + 0x16c);
    uVar7 = FUN_008d04d5(local_44);
    guard_check_icall(pCVar2,uVar7);
    (*pcVar1)();
    iVar5 = FUN_007c2511();
    uVar10 = *(ulong *)(iVar5 + 0x24);
    iVar5 = FUN_007c2511();
  }
  CDC::Draw3dRect(pCVar2,&local_24,*(ulong *)(iVar5 + 0x30),uVar10);
  this = local_48;
LAB_008cfe9e:
  if (local_50 != 0) {
    BitBlt(*(HDC *)(this + 4),local_34,local_30,local_2c - local_34,local_28 - local_30,local_6c,
           local_34,local_30,0xcc0020);
    if (local_54 != (CPalette *)0x0) {
      CDC::SelectPalette(local_70,local_54,0);
    }
    pvVar9 = (void *)0x0;
    if (local_58 != (CGdiObject *)0x0) {
      pvVar9 = *(void **)(local_58 + 4);
    }
    CDC::SelectGdiObject(local_6c,pvVar9);
  }
  if (pCVar3 != (CPalette *)0x0) {
    CDC::SelectPalette(this,pCVar3,0);
  }
  local_60 = CBitmap::vftable;
  FUN_00416100();
  FUN_0079e053();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorPickerCtrl[10] */
/* 008d059e  FUN_008d059e  6 bytes, 0 callers */

undefined ** FUN_008d059e(void)

{
  return &PTR_FUN_009a72d0;
}




/* vtable slots: CMFCColorPickerCtrl[25] */
/* 008d0f61  PreCreateWindow  28 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CMFCColorPickerCtrl::PreCreateWindow(struct tagCREATESTRUCTA
   &)
    protected: virtual int __thiscall CMFCColorPickerCtrl::PreCreateWindow(struct tagCREATESTRUCTW
   &)
   
   Library: Visual Studio 2015 Release */

void PreCreateWindow(int param_1)

{
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe | 10;
  PreCreateWindow(param_1);
  return;
}




/* vtable slots: CMFCColorPickerCtrl[20] */
/* 008d0f7d  FUN_008d0f7d  22 bytes, 0 callers */

void FUN_008d0f7d(void)

{
  FUN_00797c5d(1,0xb,0);
  guard_check_icall();
  return;
}



