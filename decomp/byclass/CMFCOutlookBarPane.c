/* CMFCOutlookBarPane -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCOutlookBarPane[101] */
/* 007c24ce  FUN_007c24ce  12 bytes, 0 callers */

uint FUN_007c24ce(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0x9c) & 0x5000;
}




/* vtable slots: CMFCOutlookBarPane[1] */
/* 0080cbed  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCOutlookBarPane::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCOutlookBarPane::_scalar_deleting_destructor_(CMFCOutlookBarPane *this,uint param_1)

{
  ~CMFCOutlookBarPane(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1de0);
    }
  }
  return this;
}




/* vtable slots: CMFCOutlookBarPane[152] */
/* 0080cef2  FUN_0080cef2  81 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_0080cef2(int *param_1)

{
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  *param_1 = local_18.right - local_18.left;
  param_1[1] = local_18.bottom - local_18.top;
  return param_1;
}




/* vtable slots: CMFCOutlookBarPane[270] */
/* 0080cff8  Create  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCOutlookBarPane::Create(class CWnd *,unsigned long,unsigned
   int,unsigned long)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCOutlookBarPane::Create
          (CMFCOutlookBarPane *this,CWnd *param_1,ulong param_2,uint param_3,ulong param_4)

{
  int iVar1;
  
  iVar1 = FUN_007fc712(param_1,param_2,param_3);
  if (iVar1 != 0) {
    *(ulong *)(this + 0xa0) = param_4;
  }
  return (uint)(iVar1 != 0);
}




/* vtable slots: CMFCOutlookBarPane[255] */
/* 0080d021  FUN_0080d021  72 bytes, 0 callers */

CObject * FUN_0080d021(undefined4 param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  CObject *pCVar3;
  
  pCVar2 = (CObject *)FUN_007fc74e(param_1);
  if (pCVar2 == (CObject *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCOutlookBarPaneButton_00a009f8,pCVar2);
  if (pCVar3 == (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    pCVar2 = (CObject *)0x0;
  }
  return pCVar2;
}




/* vtable slots: CMFCOutlookBarPane[258] */
/* 0080d52f  EnableContextMenuItems  148 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CMFCOutlookBarPane::EnableContextMenuItems(class
   CMFCToolBarButton *,class CMenu *)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCOutlookBarPane::EnableContextMenuItems
          (CMFCOutlookBarPane *this,CMFCToolBarButton *param_1,CMenu *param_2)

{
  if (DAT_00a127ac != 0) {
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4212,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4213,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4214,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4211,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4215,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x420e,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x420f,1);
  }
  FUN_007fd73b(param_1,param_2);
  return 1;
}




/* vtable slots: CMFCOutlookBarPane[10] */
/* 0080d5c3  FUN_0080d5c3  6 bytes, 0 callers */

undefined ** FUN_0080d5c3(void)

{
  return &PTR_FUN_0098d5f8;
}




/* vtable slots: CMFCOutlookBarPane[0] */
/* 0080d5c9  FUN_0080d5c9  6 bytes, 0 callers */

undefined ** FUN_0080d5c9(void)

{
  return &PTR_s_CMFCOutlookBarPane_00a006a0;
}




/* vtable slots: CMFCOutlookBarPane[173] */
/* 0080d5cf  FUN_0080d5cf  94 bytes, 0 callers */

bool FUN_0080d5cf(undefined4 param_1,undefined4 *param_2)

{
  CObject *pCVar1;
  tagPOINT local_c;
  
  if (param_2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_c.x = 0;
  local_c.y = 0;
  GetCursorPos(&local_c);
  *param_2 = 0;
  pCVar1 = (CObject *)FUN_007ee24c(local_c.x,local_c.y,0,0,&PTR_s_CMFCOutlookBar_00a00680);
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCOutlookBar_00a00680,pCVar1);
  if (pCVar1 != (CObject *)0x0) {
    *param_2 = pCVar1;
  }
  return pCVar1 != (CObject *)0x0;
}




/* vtable slots: CMFCOutlookBarPane[176] */
/* 0080d62e  FUN_0080d62e  198 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0080d62e(undefined4 param_1,int param_2)

{
  POINT pt;
  HWND pHVar1;
  CWnd *pCVar2;
  BOOL BVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  tagPOINT local_24;
  uint local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = 1;
  if (param_2 == 1) {
    uVar5 = 0;
    local_24.x = 0;
    local_24.y = 0;
    GetCursorPos(&local_24);
    pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar2 = CWnd::FromHandle(pHVar1);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(pCVar2 + 0x20),&local_18);
    pt.y = local_24.y;
    pt.x = local_24.x;
    BVar3 = PtInRect(&local_18,pt);
    local_1c = (uint)(BVar3 == 0);
    if (BVar3 == 0) {
      iVar4 = FUN_0079d98a(&PTR_s_CMFCOutlookBar_00a00680);
      if (iVar4 == 0) {
        pHVar1 = GetParent(*(HWND *)(pCVar2 + 0x20));
        pCVar2 = CWnd::FromHandle(pHVar1);
        if (pCVar2 != (CWnd *)0x0) {
          uVar5 = *(undefined4 *)(pCVar2 + 0x20);
        }
        *(undefined4 *)(in_ECX + 0x1dcc) = uVar5;
      }
      else {
        *(HWND *)(in_ECX + 0x1dcc) = *(HWND *)(pCVar2 + 0x20);
      }
    }
  }
  return local_1c;
}




/* vtable slots: CMFCOutlookBarPane[246] */
/* 0080d82b  FUN_0080d82b  254 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0080d82b(undefined4 param_1,undefined4 param_2,LONG param_3,LONG param_4)

{
  code *pcVar1;
  POINT pt;
  POINT pt_00;
  int *piVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 uVar5;
  CWnd *in_ECX;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  piVar2 = (int *)FUN_00880f70(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPaneButton_00a009f8);
    pcVar1 = *(code **)(*piVar2 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    if (iVar3 != 0) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect(*(HWND *)(in_ECX + 0xe88),&local_18);
      CWnd::ScreenToClient(in_ECX,&local_18);
      pt.y = param_4;
      pt.x = param_3;
      BVar4 = PtInRect(&local_18,pt);
      if (BVar4 == 0) {
        local_28.left = 0;
        local_28.top = 0;
        local_28.right = 0;
        local_28.bottom = 0;
        GetWindowRect(*(HWND *)(in_ECX + 0x1630),&local_28);
        CWnd::ScreenToClient(in_ECX,&local_28);
        pt_00.y = param_4;
        pt_00.x = param_3;
        BVar4 = PtInRect(&local_28,pt_00);
        if (BVar4 == 0) {
          uVar5 = FUN_008008a0(param_1,param_2,param_3,param_4);
          return uVar5;
        }
        FUN_0080ddf8();
      }
      else {
        FUN_0080dfc4();
      }
    }
  }
  return 0;
}




/* vtable slots: CMFCOutlookBarPane[269] */
/* 0080d929  FUN_0080d929  200 bytes, 0 callers */

void FUN_0080d929(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_24 [12];
  undefined **local_18;
  HBRUSH local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0xd54) == 0) {
    FUN_0079de5e(*(undefined4 *)(in_ECX + 0xd48));
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,local_14);
    local_18 = CBrush::vftable;
    FUN_00416100();
  }
  else {
    local_c = in_ECX + 0xd50;
    FUN_007eb6ca(local_24,0,0,0);
    iVar3 = *(int *)(in_ECX + 0xda4);
    local_10 = *(int *)(in_ECX + 0xda8);
    iVar1 = param_5;
    iVar2 = param_4;
    iVar5 = param_2;
    local_8 = iVar3;
    if (param_2 < param_4) {
      do {
        iVar4 = param_3;
        if (param_3 < iVar1) {
          do {
            FUN_007e8cae(param_1,iVar5,iVar4,0,0,0,0,0,0,0xff);
            iVar4 = iVar4 + local_10;
            iVar1 = param_5;
            iVar2 = param_4;
            iVar3 = local_8;
          } while (iVar4 < param_5);
        }
        iVar5 = iVar5 + iVar3;
      } while (iVar5 < iVar2);
    }
    FUN_007e98b8(local_24);
  }
  return;
}




/* vtable slots: CMFCOutlookBarPane[67] */
/* 0080dbcc  FUN_0080dbcc  402 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0080dbcc(int param_1)

{
  int iVar1;
  POINT pt;
  POINT pt_00;
  BOOL BVar2;
  int in_ECX;
  tagPOINT local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0x200) && (iVar1 != 0x201)) {
    if (iVar1 != 0x202) goto LAB_0080dd46;
    KillTimer(*(HWND *)(in_ECX + 0x20),0xec13);
    KillTimer(*(HWND *)(in_ECX + 0x20),0xec14);
  }
  local_20.x = 0;
  local_20.y = 0;
  GetCursorPos(&local_20);
  ScreenToClient(*(HWND *)(in_ECX + 0x20),&local_20);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x1630),&local_18);
  MapWindowPoints(*(HWND *)(in_ECX + 0x1630),*(HWND *)(in_ECX + 0x20),(LPPOINT)&local_18,2);
  pt.y = local_20.y;
  pt.x = local_20.x;
  BVar2 = PtInRect(&local_18,pt);
  if ((BVar2 != 0) &&
     (SendMessageW(*(HWND *)(in_ECX + 0x1630),*(UINT *)(param_1 + 4),*(WPARAM *)(param_1 + 8),
                   *(LPARAM *)(param_1 + 8)), *(int *)(param_1 + 4) == 0x201)) {
    SetTimer(*(HWND *)(in_ECX + 0x20),0xec14,200,(TIMERPROC)0x0);
    if (*(int *)(in_ECX + 0x1ddc) == 0) {
      FUN_0080ddf8();
    }
    else {
      FUN_0080de74();
    }
  }
  GetClientRect(*(HWND *)(in_ECX + 0xe88),&local_18);
  MapWindowPoints(*(HWND *)(in_ECX + 0xe88),*(HWND *)(in_ECX + 0x20),(LPPOINT)&local_18,2);
  pt_00.y = local_20.y;
  pt_00.x = local_20.x;
  BVar2 = PtInRect(&local_18,pt_00);
  if ((BVar2 != 0) &&
     (SendMessageW(*(HWND *)(in_ECX + 0xe88),*(UINT *)(param_1 + 4),*(WPARAM *)(param_1 + 8),
                   *(LPARAM *)(param_1 + 8)), *(int *)(param_1 + 4) == 0x201)) {
    SetTimer(*(HWND *)(in_ECX + 0x20),0xec13,200,(TIMERPROC)0x0);
    if (*(int *)(in_ECX + 0x1ddc) == 0) {
      FUN_0080dfc4();
    }
    else {
      FUN_0080df1b();
    }
  }
LAB_0080dd46:
  FUN_008036ce(param_1);
  return;
}




/* vtable slots: CMFCOutlookBarPane[212] */
/* 0080dd5e  FUN_0080dd5e  74 bytes, 0 callers */

void FUN_0080dd5e(void)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_00803b44();
  in_ECX[0x771] = 0;
  in_ECX[0x770] = 0;
  pcVar1 = *(code **)(*in_ECX + 0x3e4);
  guard_check_icall();
  (*pcVar1)();
  if (in_ECX[8] != 0) {
    UpdateWindow((HWND)in_ECX[8]);
    InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
  }
  return;
}




/* vtable slots: CMFCOutlookBarPane[268] */
/* 0080e12c  FUN_0080e12c  201 bytes, 0 callers */

undefined4 FUN_0080e12c(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  CObject *pCVar4;
  CObject *pCVar5;
  int iVar6;
  int *in_ECX;
  int *local_c;
  int *local_8;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    in_ECX[0x2e4] = 0;
    local_c = in_ECX;
    local_8 = in_ECX;
    if (*(int *)(param_1 + 0xc) == in_ECX[0x319]) {
      local_8 = (int *)in_ECX[0x317];
      local_c = *(int **)(param_1 + 4);
      do {
        if (local_8 == (int *)0x0) {
          return 0;
        }
        if (local_c == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        puVar3 = (undefined4 *)FUN_0044f2d0(&local_8);
        pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,
                                    (CObject *)*puVar3);
        pCVar5 = (CObject *)FUN_0049acb0(&local_c);
        pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,pCVar5);
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x94);
        guard_check_icall(pCVar5);
        iVar6 = (*pcVar1)();
      } while (iVar6 != 0);
    }
    pcVar1 = *(code **)(*in_ECX + 0x388);
    guard_check_icall();
    (*pcVar1)();
    uVar2 = 1;
  }
  return uVar2;
}



