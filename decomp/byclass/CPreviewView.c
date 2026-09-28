/* CPreviewView -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPreviewView[99], CPreviewViewEx[99], CScrollView[99] */
/* 007b6a49  FUN_007b6a49  32 bytes, 1 callers */

void FUN_007b6a49(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x198);
  guard_check_icall(0,0,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CPreviewView[106], CPreviewViewEx[106], CScrollView[106] */
/* 007b6bad  FUN_007b6bad  36 bytes, 0 callers */

void FUN_007b6bad(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x19c);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CPreviewView[102], CPreviewViewEx[102], CScrollView[102] */
/* 007b6c49  FUN_007b6c49  16 bytes, 0 callers */

void FUN_007b6c49(void)

{
  int in_ECX;
  
  InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,1);
  return;
}




/* vtable slots: CPreviewView[25], CPreviewViewEx[25], CScrollView[25] */
/* 007b6d1a  PreCreateWindow  60 bytes, 1 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CView::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall CView::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

undefined4 PreCreateWindow(int param_1)

{
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_00790c5e(8);
    *(wchar_t **)(param_1 + 0x28) = L"AfxFrameOrView140su";
  }
  if ((*(uint *)(param_1 + 0x20) & 0x800000) != 0) {
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x200;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xff7fffff;
  }
  return 1;
}




/* vtable slots: CPreviewView[1] */
/* 007b7c85  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CPreviewView::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CPreviewView::_scalar_deleting_destructor_(CPreviewView *this,uint param_1)

{
  FUN_007b7bb6();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x168);
    }
  }
  return this;
}




/* vtable slots: CPreviewView[110], CPreviewViewEx[110] */
/* 007b7d44  CalcScaleRatio  47 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual class CSize __thiscall CPreviewView::CalcScaleRatio(class CSize,class CSize)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

void __thiscall
CPreviewView::CalcScaleRatio
          (undefined4 param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  iVar1 = MulDiv(param_5,param_4,param_6);
  if (param_3 < iVar1) {
    param_4 = param_3;
    param_6 = param_5;
  }
  param_2[1] = param_6;
  *param_2 = param_4;
  return;
}




/* vtable slots: CPreviewView[10] */
/* 007b84e1  FUN_007b84e1  6 bytes, 0 callers */

undefined ** FUN_007b84e1(void)

{
  return &PTR_FUN_009818c0;
}




/* vtable slots: CPreviewView[0] */
/* 007b84e7  FUN_007b84e7  6 bytes, 0 callers */

undefined ** FUN_007b84e7(void)

{
  return &PTR_s_CPreviewView_009814f8;
}




/* vtable slots: CPreviewView[100], CPreviewViewEx[100] */
/* 007b8511  OnActivateView  114 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CPreviewView::OnActivateView(int,class CView *,class CView *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CPreviewView::OnActivateView(CPreviewView *this,int param_1,CView *param_2,CView *param_3)

{
  HWND pHVar1;
  CWnd *pCVar2;
  BOOL BVar3;
  
  if (param_1 != 0) {
    pHVar1 = GetFocus();
    pCVar2 = CWnd::FromHandle(pHVar1);
    if ((pCVar2 == (CWnd *)0x0) ||
       ((*(int *)(this + 0xdc) != 0 &&
        (BVar3 = IsWindow(*(HWND *)(*(int *)(this + 0xdc) + 0x20)), BVar3 != 0)))) {
      if (pCVar2 == (CWnd *)0x0) {
        pHVar1 = (HWND)0x0;
      }
      else {
        pHVar1 = *(HWND *)(pCVar2 + 0x20);
      }
      BVar3 = IsChild(*(HWND *)(*(int *)(this + 0xdc) + 0x20),pHVar1);
      if (BVar3 == 0) {
        FUN_00797a56(0xe304);
        FUN_00797df8();
      }
    }
  }
  return;
}




/* vtable slots: CPreviewView[112] */
/* 007b85af  FUN_007b85af  209 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007b85af(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_b8;
  wchar_t local_b4 [86];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xb0;
  local_8 = 0x7b85be;
  iVar1 = FUN_0079d18b();
  iVar1 = *(int *)(iVar1 + 0x20);
  CStringT<>();
  local_8 = 0;
  iVar2 = AfxExtractSubString((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                              &local_b8,*(wchar_t **)(*(int *)(in_ECX + 0x164) + 0x1c),
                              (uint)(param_2 != 1),L'\n');
  if (iVar2 != 0) {
    if (param_2 == 1) {
      iVar2 = FID_conflict__swprintf(local_b4,(wchar_t *)0x50,local_b8,param_1);
    }
    else {
      iVar2 = FID_conflict__swprintf
                        (local_b4,(wchar_t *)0x50,local_b8,param_1,param_2 + -1 + param_1);
    }
    if (0 < iVar2) {
      SendMessageW(*(HWND *)(iVar1 + 0x20),0x362,0,(LPARAM)local_b4);
    }
  }
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CPreviewView[103], CPreviewViewEx[103] */
/* 007b8680  FUN_007b8680  1324 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007b8680(CDC *param_1)

{
  uint uVar1;
  code *pcVar2;
  CDC *pCVar3;
  uint uVar4;
  DWORD DVar5;
  HPEN pHVar6;
  int yBottom;
  int xRight;
  int *piVar7;
  HBRUSH hbr;
  CScrollView *in_ECX;
  int iVar8;
  undefined4 uVar9;
  undefined1 local_90 [8];
  undefined1 local_88 [8];
  undefined1 local_80 [8];
  undefined1 local_78 [16];
  undefined4 local_68;
  undefined **local_64;
  undefined4 local_60;
  undefined **local_5c;
  undefined4 local_58;
  int local_54;
  CDC *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  code *local_3c;
  uint local_38;
  RECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x7b868f;
  local_50 = param_1;
  if ((*(int *)(in_ECX + 0xbc) != 0) && (*(int *)(in_ECX + 200) != 0)) {
    FUN_007b84ed(&local_44);
    local_60 = 0;
    local_64 = CPen::vftable;
    local_8 = 0;
    DVar5 = GetSysColor(6);
    pHVar6 = CreatePen(0,2,DVar5);
    Attach(pHVar6);
    local_58 = 0;
    local_5c = CPen::vftable;
    local_8 = CONCAT31(local_8._1_3_,1);
    DVar5 = GetSysColor(0x10);
    pHVar6 = CreatePen(0,3,DVar5);
    Attach(pHVar6);
    local_38 = 0;
    *(undefined4 *)(*(int *)(in_ECX + 0x164) + 0x10) = 1;
    if (*(int *)(in_ECX + 0x148) != 0) {
      local_4c = local_40;
      local_54 = 0;
      local_48 = local_44;
      do {
        uVar4 = local_38;
        pcVar2 = *(code **)(*(int *)(in_ECX + 0xc4) + 0x1c);
        guard_check_icall();
        local_68 = (*pcVar2)();
        local_3c = *(code **)(**(int **)(in_ECX + 0xc0) + 0x10);
        iVar8 = 0;
        if (local_50 != (CDC *)0x0) {
          iVar8 = *(int *)(local_50 + 4);
        }
        guard_check_icall(iVar8);
        (*local_3c)();
        *(uint *)(*(int *)(in_ECX + 0x164) + 0x14) = *(int *)(in_ECX + 0x144) + uVar4;
        uVar1 = *(uint *)(in_ECX + 0x144) + uVar4;
        if (((*(uint *)(in_ECX + 0x144) <= uVar1) && (uVar4 <= uVar1)) &&
           (uVar1 <= *(ushort *)(*(int *)(**(int **)(in_ECX + 0x164) + 0xa8) + 0x1e))) {
          pcVar2 = *(code **)(**(int **)(in_ECX + 0xbc) + 0x188);
          guard_check_icall(*(undefined4 *)(in_ECX + 0xc0),*(int **)(in_ECX + 0x164));
          (*pcVar2)();
        }
        iVar8 = *(int *)(in_ECX + 0x164);
        yBottom = GetDeviceCaps(*(HDC *)(*(int *)(in_ECX + 0xc0) + 8),10);
        xRight = GetDeviceCaps(*(HDC *)(*(int *)(in_ECX + 0xc0) + 8),8);
        SetRect((LPRECT)(iVar8 + 0x24),0,0,xRight,yBottom);
        DPtoLP(*(HDC *)(*(int *)(in_ECX + 0xc0) + 8),(LPPOINT)(*(int *)(in_ECX + 0x164) + 0x24),2);
        pCVar3 = local_50;
        pcVar2 = *(code **)(*(int *)local_50 + 0x1c);
        guard_check_icall();
        (*pcVar2)();
        local_3c = (code *)(*(int *)(in_ECX + 0xe0) + local_54);
        if (*(int *)((int)local_3c + 0x18) == 0) {
          pcVar2 = *(code **)(*(int *)in_ECX + 0x1bc);
          guard_check_icall(local_38);
          (*pcVar2)();
          if (*(int *)(in_ECX + 0x13c) != 0) {
            piVar7 = (int *)CScrollView::GetDeviceScrollPosition(in_ECX);
            local_48 = -*piVar7;
            local_4c = -piVar7[1];
            if (*(int *)(in_ECX + 0xb0) != 0) {
              local_24.left = 0;
              local_24.top = 0;
              local_24.right = 0;
              local_24.bottom = 0;
              GetClientRect(*(HWND *)(in_ECX + 0x20),&local_24);
              if (*(int *)(in_ECX + 0x98) < local_24.right - local_24.left) {
                local_48 = ((local_24.right - local_24.left) - *(int *)(in_ECX + 0x98)) / 2;
              }
              if (*(int *)(in_ECX + 0x9c) < local_24.bottom - local_24.top) {
                local_4c = ((local_24.bottom - local_24.top) - *(int *)(in_ECX + 0x9c)) / 2;
              }
            }
          }
        }
        pcVar2 = *(code **)(*(int *)pCVar3 + 0x34);
        guard_check_icall(1);
        (*pcVar2)();
        FUN_007b987c(local_78,local_48,local_4c);
        FUN_0079f36c(local_80,0,0);
        pcVar2 = *(code **)(*(int *)pCVar3 + 0x24);
        guard_check_icall(5);
        (*pcVar2)();
        FUN_0079efbc(&local_64);
        pcVar2 = local_3c;
        FUN_005887e0(local_3c);
        FUN_0079efbc(&local_5c);
        FUN_0079ec58(local_88,*(int *)((int)pcVar2 + 8) + 1,*(int *)((int)pcVar2 + 4) + 3);
        CDC::LineTo(pCVar3,*(int *)((int)pcVar2 + 8) + 1,*(int *)((int)pcVar2 + 0xc) + 1);
        FUN_0079ec58(local_90,*(int *)pcVar2 + 3,*(int *)((int)pcVar2 + 0xc) + 1);
        CDC::LineTo(pCVar3,*(int *)((int)pcVar2 + 8) + 1,*(int *)((int)pcVar2 + 0xc) + 1);
        local_34.left = *(int *)pcVar2 + 1;
        local_34.top = *(int *)((int)pcVar2 + 4) + 1;
        local_34.right = *(int *)((int)pcVar2 + 8) + -2;
        local_34.bottom = *(int *)((int)pcVar2 + 0xc) + -2;
        hbr = GetStockObject(0);
        pCVar3 = local_50;
        FillRect(*(HDC *)(local_50 + 4),&local_34,hbr);
        uVar9 = 0xffffffff;
        pcVar2 = *(code **)(*(int *)pCVar3 + 0x20);
        guard_check_icall(0xffffffff);
        (*pcVar2)();
        if (((*(int **)(in_ECX + 0x164))[4] == 0) ||
           ((uint)*(ushort *)(*(int *)(**(int **)(in_ECX + 0x164) + 0xa8) + 0x1e) <
            *(int *)(in_ECX + 0x144) + local_38)) {
          pcVar2 = *(code **)(**(int **)(in_ECX + 0xc0) + 0x18);
          guard_check_icall(uVar9);
          (*pcVar2)();
          pcVar2 = *(code **)(*(int *)(in_ECX + 0xc4) + 0x20);
          guard_check_icall(local_68);
          (*pcVar2)();
          if ((local_38 == 0) && (1 < *(uint *)(in_ECX + 0x144))) {
            FUN_007b93c9(*(uint *)(in_ECX + 0x144) - 1,1);
          }
          break;
        }
        local_38 = local_38 + 1;
        pcVar2 = *(code **)(*(int *)in_ECX + 0x1c0);
        guard_check_icall(*(int *)(in_ECX + 0x144),local_38);
        (*pcVar2)();
        CPreviewDC::SetScaleRatio
                  (*(CPreviewDC **)(in_ECX + 0xc0),*(int *)((int)local_3c + 0x18),
                   *(int *)((int)local_3c + 0x1c));
        local_44 = 0;
        local_40 = 0;
        iVar8 = **(int **)(in_ECX + 0xc0);
        guard_check_icall(0xd,0,0,&local_44);
        (**(code **)(iVar8 + 0x74))();
        FUN_007cf161(&local_44);
        local_44 = local_48 + *(int *)local_3c + local_44 + 1;
        local_40 = local_40 + 1 + local_4c + *(int *)((int)local_3c + 4);
        FUN_007cf4df(local_44,local_40);
        FUN_007ce66b();
        pcVar2 = *(code **)(**(int **)(in_ECX + 0xbc) + 0x1a8);
        guard_check_icall(*(undefined4 *)(in_ECX + 0xc0),*(undefined4 *)(in_ECX + 0x164));
        (*pcVar2)();
        pcVar2 = *(code **)(**(int **)(in_ECX + 0xc0) + 0x18);
        guard_check_icall();
        (*pcVar2)();
        pcVar2 = *(code **)(*(int *)(in_ECX + 0xc4) + 0x20);
        guard_check_icall(local_68);
        (*pcVar2)();
        local_54 = local_54 + 0x28;
      } while (local_38 < *(uint *)(in_ECX + 0x148));
    }
    CGdiObject::DeleteObject((CGdiObject *)&local_64);
    CGdiObject::DeleteObject((CGdiObject *)&local_5c);
    local_5c = CPen::vftable;
    FUN_00416100();
    local_64 = CPen::vftable;
    FUN_00416100();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CPreviewView[98], CPreviewViewEx[98] */
/* 007b8d6b  OnPrepareDC  40 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CPreviewView::OnPrepareDC(class CDC *,struct CPrintInfo *)
   
   Library: Visual Studio 2015 Release */

void __thiscall CPreviewView::OnPrepareDC(CPreviewView *this,CDC *param_1,CPrintInfo *param_2)

{
  if (*(int *)(this + 0x13c) == 0) {
    CView::OnPrepareDC((CView *)this,param_1,param_2);
    return;
  }
  if (*(int *)(*(int *)(this + 0xe0) + 0x18) != 0) {
    FUN_007cd3a4();
    return;
  }
  return;
}




/* vtable slots: CPreviewView[111], CPreviewViewEx[111] */
/* 007b92f7  FUN_007b92f7  210 bytes, 0 callers */

void FUN_007b92f7(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *in_ECX;
  int iVar6;
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  local_8 = in_ECX;
  FUN_007b7cb8(&local_14);
  local_c = param_1 * 0x28;
  pcVar1 = *(code **)(in_ECX[0x31] + 0x74);
  guard_check_icall(0xc,0,0,local_8[0x38] + local_c + 0x10);
  (*pcVar1)();
  piVar3 = local_8;
  iVar6 = local_c + local_8[0x38];
  iVar4 = MulDiv(*(int *)(iVar6 + 0x10),DAT_00a12220,local_8[0x55]);
  *(int *)(iVar6 + 0x10) = iVar4;
  iVar4 = MulDiv(*(int *)(iVar6 + 0x14),DAT_00a12224,piVar3[0x56]);
  *(int *)(iVar6 + 0x14) = iVar4;
  pcVar1 = *(code **)(*piVar3 + 0x1b8);
  guard_check_icall(local_1c,local_14,local_10,*(undefined4 *)(iVar6 + 0x10),
                    *(undefined4 *)(iVar6 + 0x14));
  puVar5 = (undefined4 *)(*pcVar1)();
  uVar2 = puVar5[1];
  iVar4 = local_8[0x38];
  *(undefined4 *)(local_c + 0x20 + iVar4) = *puVar5;
  *(undefined4 *)(local_c + 0x24 + iVar4) = uVar2;
  FUN_007b9725(param_1);
  return;
}




/* vtable slots: CPreviewView[26], CPreviewViewEx[26], CScrollView[26] */
/* 007cc94d  FUN_007cc94d  161 bytes, 0 callers */

void FUN_007cc94d(LPRECT param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint dwExStyle;
  DWORD dwStyle;
  int in_ECX;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = in_ECX;
  dwExStyle = FUN_00797acc();
  if (param_2 == 1) {
    AdjustWindowRectEx(param_1,0,0,dwExStyle);
    if (*(int *)(in_ECX + 0x8c) != -1) {
      iVar1 = param_1->top;
      local_10 = 0;
      local_c = 0;
      iVar2 = param_1->bottom;
      iVar3 = *(int *)(local_8 + 0x9c);
      local_8 = (*(int *)(local_8 + 0x98) - param_1->right) + param_1->left;
      FUN_007ccf34(&local_10);
      if (0 < (iVar3 - iVar2) + iVar1) {
        param_1->right = param_1->right + local_10;
      }
      if (0 < local_8) {
        param_1->bottom = param_1->bottom + local_c;
      }
    }
  }
  else {
    dwStyle = FUN_00797b3d();
    AdjustWindowRectEx(param_1,dwStyle,0,dwExStyle & 0xfffffdff);
  }
  return;
}




/* vtable slots: CPreviewView[109], CPreviewViewEx[109], CScrollView[109] */
/* 007cd11e  FUN_007cd11e  54 bytes, 0 callers */

int * FUN_007cd11e(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_4 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 / 10;
  }
  *param_1 = param_2;
  if (param_5 != 0) {
    iVar1 = param_3 / 10;
  }
  param_1[1] = iVar1;
  return param_1;
}




/* vtable slots: CPreviewView[90], CPreviewViewEx[90], CScrollView[90] */
/* 007cd641  FUN_007cd641  278 bytes, 0 callers */

int FUN_007cd641(uint param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  int iVar5;
  
  iVar2 = FUN_00792ad2(0);
  uVar4 = param_1 & 0xff;
  if (uVar4 == 0) {
    iVar5 = iVar2 - in_ECX[0x2a];
  }
  else if (uVar4 == 1) {
    iVar5 = iVar2 + in_ECX[0x2a];
  }
  else if (uVar4 == 2) {
    iVar5 = iVar2 - in_ECX[0x28];
  }
  else if (uVar4 == 3) {
    iVar5 = iVar2 + in_ECX[0x28];
  }
  else {
    iVar5 = param_2;
    if (uVar4 != 5) {
      if (uVar4 == 6) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar2;
        if (uVar4 == 7) {
          iVar5 = 0x7fffffff;
        }
      }
    }
  }
  iVar3 = FUN_00792ad2(1);
  uVar4 = param_1 >> 8 & 0xff;
  if (uVar4 == 0) {
    param_2 = iVar3 - in_ECX[0x2b];
  }
  else if (uVar4 == 1) {
    param_2 = iVar3 + in_ECX[0x2b];
  }
  else if (uVar4 == 2) {
    param_2 = iVar3 - in_ECX[0x29];
  }
  else if (uVar4 == 3) {
    param_2 = iVar3 + in_ECX[0x29];
  }
  else if (uVar4 != 5) {
    if (uVar4 == 6) {
      param_2 = 0;
    }
    else {
      param_2 = iVar3;
      if (uVar4 == 7) {
        param_2 = 0x7fffffff;
      }
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x16c);
  guard_check_icall(iVar5 - iVar2,param_2 - iVar3,param_3);
  iVar2 = (*pcVar1)();
  if ((iVar2 != 0) && (param_3 != 0)) {
    UpdateWindow((HWND)in_ECX[8]);
  }
  return iVar2;
}




/* vtable slots: CPreviewView[91], CPreviewViewEx[91], CScrollView[91] */
/* 007cd757  FUN_007cd757  274 bytes, 0 callers */

undefined4 FUN_007cd757(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *in_ECX;
  
  uVar2 = FUN_00797b3d();
  pcVar1 = *(code **)(*in_ECX + 0x78);
  guard_check_icall(1);
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    uVar4 = uVar2 & 0x200000;
  }
  else {
    uVar4 = FUN_00797c32();
  }
  if (uVar4 == 0) {
    param_2 = 0;
  }
  pcVar1 = *(code **)(*in_ECX + 0x78);
  guard_check_icall(0);
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    uVar2 = uVar2 & 0x100000;
  }
  else {
    uVar2 = FUN_00797c32();
  }
  if (uVar2 == 0) {
    param_1 = 0;
  }
  iVar3 = FUN_00792ad2(0);
  iVar5 = FUN_00792a77(0);
  param_1 = iVar3 + param_1;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (iVar5 < param_1) {
    param_1 = iVar5;
  }
  iVar5 = FUN_00792ad2(1);
  iVar6 = FUN_00792a77(1);
  param_2 = iVar5 + param_2;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (iVar6 < param_2) {
    param_2 = iVar6;
  }
  if ((param_1 == iVar3) && (param_2 == iVar5)) {
    uVar7 = 0;
  }
  else {
    if (param_3 != 0) {
      FUN_0079513c(iVar3 - param_1,iVar5 - param_2,0,0);
      if (param_1 != iVar3) {
        FUN_007953ac(0,param_1,1);
      }
      if (param_2 != iVar5) {
        FUN_007953ac(1,param_2,1);
      }
    }
    uVar7 = 1;
  }
  return uVar7;
}



