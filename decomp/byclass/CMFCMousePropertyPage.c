/* CMFCMousePropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCMousePropertyPage[1] */
/* 008cba0f  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCMousePropertyPage::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCMousePropertyPage::_scalar_deleting_destructor_(CMFCMousePropertyPage *this,uint param_1)

{
  ~CMFCMousePropertyPage(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,600);
    }
  }
  return this;
}




/* vtable slots: CMFCMousePropertyPage[64] */
/* 008cba72  DoDataExchange  90 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCMousePropertyPage::DoDataExchange(class CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCMousePropertyPage::DoDataExchange(CMFCMousePropertyPage *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x40f7,this + 0xd0);
  FUN_0078fb9c(param_1,0x40fa,this + 0x150);
  FUN_0078fb9c(param_1,0x4082,this + 0x1d0);
  DDX_Text(param_1,0x4082,this + 0x250);
  return;
}




/* vtable slots: CMFCMousePropertyPage[10] */
/* 008cbb22  FUN_008cbb22  6 bytes, 0 callers */

undefined ** FUN_008cbb22(void)

{
  return &PTR_FUN_009a64b8;
}




/* vtable slots: CMFCMousePropertyPage[0] */
/* 008cbb28  FUN_008cbb28  6 bytes, 0 callers */

undefined ** FUN_008cbb28(void)

{
  return &PTR_s_CMFCMousePropertyPage_009a6250;
}




/* vtable slots: CMFCMousePropertyPage[94] */
/* 008cbb2e  FUN_008cbb2e  802 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008cbb2e(void)

{
  int *piVar1;
  undefined4 *puVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  LPARAM lParam;
  _IMAGELIST *p_Var7;
  undefined4 uVar8;
  LRESULT LVar9;
  HWND pHVar10;
  CWnd *pCVar11;
  CObject *pCVar12;
  int in_ECX;
  undefined1 local_88 [4];
  undefined4 *local_84;
  int local_7c;
  int local_6c;
  undefined4 local_68;
  int local_64;
  undefined1 local_60 [4];
  LRESULT local_5c;
  HICON local_58;
  undefined1 local_54 [16];
  RECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0x8cbb3a;
  if (DAT_00a13c90 != 0) {
    FUN_00798993();
    FUN_00813876(10);
    local_8 = 0;
    FUN_008a22d6(local_88);
    iVar5 = FUN_007c2511();
    iVar5 = *(int *)(iVar5 + 0x118);
    iVar6 = FUN_007c2511();
    CImageList::Create((CImageList *)(in_ECX + 0xc4),*(int *)(iVar6 + 0x114),iVar5,1,local_7c,1);
    if ((CImageList *)(in_ECX + 0xc4) == (CImageList *)0x0) {
      lParam = 0;
    }
    else {
      lParam = *(LPARAM *)(in_ECX + 200);
    }
    p_Var7 = (_IMAGELIST *)SendMessageW(*(HWND *)(in_ECX + 0xf0),0x1003,1,lParam);
    CImageList::FromHandle(p_Var7);
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetClientRect(*(HWND *)(in_ECX + 0xf0),&local_24);
    FUN_007a4672(0,&DAT_00956338,0,(local_24.right - local_24.left) + -1,0xffffffff);
    local_64 = 0;
    iVar5 = local_64;
    puVar2 = local_84;
    while (local_64 = iVar5, puVar2 != (undefined4 *)0x0) {
      if (puVar2 == (undefined4 *)0x0) goto LAB_008cbe4b;
      piVar1 = puVar2 + 2;
      puVar2 = (undefined4 *)*puVar2;
      iVar5 = FUN_004054a0(*piVar1 + -0x10);
      iVar5 = iVar5 + 0x10;
      local_68 = 0xffffffff;
      local_8 = CONCAT31(local_8._1_3_,1);
      local_6c = iVar5;
      uVar8 = FUN_008a22a7(iVar5);
      local_58 = (HICON)FUN_008a2289(uVar8);
      if (local_58 != (HICON)0x0) {
        FUN_0079dd6d();
        iVar6 = FUN_0079dd6d();
        local_58 = LoadIconW(*(HINSTANCE *)(iVar6 + 0xc),(LPCWSTR)((uint)local_58 & 0xffff));
        if (local_58 != (HICON)0x0) {
          local_68 = FUN_007d78d8(*(undefined4 *)(in_ECX + 200),0xffffffff,local_58);
          DestroyIcon(local_58);
        }
      }
      local_58 = (HICON)SendMessageW(*(HWND *)(in_ECX + 0xf0),0x1004,0,0);
      local_5c = 0;
      LVar9 = SendMessageW(*(HWND *)(in_ECX + 0xf0),0x1004,0,0);
      if (0 < LVar9) {
        do {
          FUN_007a44a9(local_60,local_5c,0);
          cVar4 = FUN_008c9dd6(local_60,&local_6c);
          if (cVar4 != '\0') {
            local_58 = (HICON)local_5c;
            FUN_00406b10();
            break;
          }
          FUN_00406b10();
          local_5c = local_5c + 1;
          LVar9 = SendMessageW(*(HWND *)(in_ECX + 0xf0),0x1004,0,0);
        } while (local_5c < LVar9);
      }
      FUN_007a46c5(3,local_58,iVar5,0,0,local_68,0);
      uVar8 = FUN_008a22a7(iVar5);
      SetItem(local_58,0,4,0,0,0,0,uVar8);
      LVar9 = SendMessageW(*(HWND *)(in_ECX + 0xf0),0x1057,0,iVar5);
      if (local_64 < LVar9) {
        local_64 = LVar9;
      }
      local_8 = local_8 & 0xffffff00;
      FUN_00406b10();
      iVar5 = local_64;
    }
    FUN_0079cfec(*(undefined4 *)(in_ECX + 200),0,local_54);
    CopyRect(&local_34,&local_44);
    SendMessageW(*(HWND *)(in_ECX + 0xf0),0x101e,0,
                 local_34.right + 10 + (iVar5 - local_34.left) & 0xffff);
    pHVar10 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar11 = CWnd::FromHandle(pHVar10);
    pCVar12 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarsCustomizeDialog_0099a930,
                                 (CObject *)pCVar11);
    if (pCVar12 != (CObject *)0x0) {
      pcVar3 = *(code **)(*(int *)pCVar12 + 0x17c);
      guard_check_icall(in_ECX + 0x150);
      (*pcVar3)();
      CListCtrl::SetItemState((CListCtrl *)(in_ECX + 0xd0),0,3,3);
      SendMessageW(*(HWND *)(in_ECX + 0xf0),0x1013,0,0);
      FUN_0081389c();
      FUN_008d9b68();
      return;
    }
  }
LAB_008cbe4b:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}


