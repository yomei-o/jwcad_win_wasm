/* CVSListBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CVSListBox[1] */
/* 007e346e  FUN_007e346e  51 bytes, 0 callers */

void FUN_007e346e(byte param_1)

{
  FUN_007e3204();
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




/* vtable slots: CVSListBox[91], CVSToolsListBox[91] */
/* 007e374f  FUN_007e374f  140 bytes, 0 callers */

int FUN_007e374f(undefined4 *param_1,undefined4 param_2,LRESULT param_3)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (((in_ECX == (int *)0x0) || (in_ECX[8] == 0)) || (in_ECX[0x44] == 0)) {
    iVar2 = -1;
  }
  else {
    if (param_3 < 0) {
      param_3 = SendMessageW(*(HWND *)(in_ECX[0x44] + 0x20),0x1004,0,0);
    }
    iVar2 = FUN_007a46c5(3,param_3,*param_1,0,0,0xffffffff,0);
    SetItem(iVar2,0,4,0,0,0,0,param_2);
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x17c);
      guard_check_icall(0);
      (*pcVar1)();
    }
  }
  return iVar2;
}




/* vtable slots: CVSListBox[112], CVSListBoxBase[112], CVSToolsListBox[112] */
/* 007e39b5  FUN_007e39b5  113 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007e39b5(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7e39c1;
  pcVar1 = *(code **)(*in_ECX + 0x16c);
  CStringT<>(&DAT_00956338);
  local_8 = 0;
  guard_check_icall(local_14,0,0xffffffff);
  uVar2 = (*pcVar1)();
  local_8 = 0xffffffff;
  FUN_00406b10();
  in_ECX[0x36] = 1;
  pcVar1 = *(code **)(*in_ECX + 400);
  guard_check_icall(uVar2);
  (*pcVar1)();
  return;
}




/* vtable slots: CVSListBox[100], CVSToolsListBox[100] */
/* 007e3a26  FUN_007e3a26  286 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007e3a26(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 500) = 0;
  *(undefined4 *)(in_ECX + 0x1f0) = 0;
  if (((in_ECX != 0) && (*(int *)(in_ECX + 0x20) != 0)) && (*(int *)(in_ECX + 0x110) != 0)) {
    FUN_00797df8();
    iVar2 = FUN_007e3b45(param_1);
    if (iVar2 != 0) {
      FUN_007954d8(*(undefined4 *)(iVar2 + 0x20));
      FUN_007d69e9(*(undefined4 *)(in_ECX + 0xe0));
      local_28.left = 0;
      local_28.top = 0;
      local_28.right = 0;
      local_28.bottom = 0;
      CListCtrl::GetItemRect(*(CListCtrl **)(in_ECX + 0x110),param_1,&local_28,2);
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetClientRect(*(HWND *)(iVar2 + 0x20),&local_18);
      FUN_00797e71(0,0xffffffff,0xffffffff,local_28.right - local_28.left,
                   local_18.bottom - local_18.top,0x16);
      *(int *)(in_ECX + 500) = in_ECX;
      *(undefined4 *)(in_ECX + 0x1f0) = 1;
      iVar2 = *(int *)(in_ECX + 0x88);
      while( true ) {
        if (iVar2 == 0) {
          return 1;
        }
        piVar1 = (int *)(iVar2 + 8);
        iVar2 = *(int *)(iVar2 + 4);
        if (*piVar1 == 0) break;
        FUN_007979e8(0);
      }
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
  }
  return 0;
}




/* vtable slots: CVSListBox[93], CVSToolsListBox[93] */
/* 007e3bde  GetCount  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CVSListBox::GetCount(void)const 
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CVSListBox::GetCount(CVSListBox *this)

{
  LRESULT LVar1;
  
  if (((this != (CVSListBox *)0x0) && (*(int *)(this + 0x20) != 0)) && (*(int *)(this + 0x110) != 0)
     ) {
    LVar1 = SendMessageW(*(HWND *)(*(int *)(this + 0x110) + 0x20),0x1004,0,0);
    return LVar1;
  }
  return -1;
}




/* vtable slots: CVSListBox[98], CVSToolsListBox[98] */
/* 007e3c22  GetItemData  35 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CVSListBox::GetItemData(int)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall CVSListBox::GetItemData(CVSListBox *this,int param_1)

{
  ulong uVar1;
  
  if (((this != (CVSListBox *)0x0) && (*(int *)(this + 0x20) != 0)) && (*(int *)(this + 0x110) != 0)
     ) {
    uVar1 = FUN_007a439d();
    return uVar1;
  }
  return 0;
}




/* vtable slots: CVSListBox[96], CVSToolsListBox[96] */
/* 007e3c45  FUN_007e3c45  58 bytes, 0 callers */

undefined4 FUN_007e3c45(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (((in_ECX == 0) || (*(int *)(in_ECX + 0x20) == 0)) || (*(int *)(in_ECX + 0x110) == 0)) {
    CStringT<>(&DAT_00956338);
  }
  else {
    FUN_007a44a9(param_1,param_2,0);
  }
  return param_1;
}




/* vtable slots: CVSListBox[113], CVSToolsListBox[113] */
/* 007e3c7f  FUN_007e3c7f  15 bytes, 0 callers */

undefined4 FUN_007e3c7f(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x110) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0x110) + 0x20);
}




/* vtable slots: CVSListBox[10], CVSToolsListBox[10] */
/* 007e3c8e  FUN_007e3c8e  6 bytes, 0 callers */

undefined ** FUN_007e3c8e(void)

{
  return &PTR_FUN_0098a520;
}




/* vtable slots: CVSListBox[0], CVSToolsListBox[0] */
/* 007e3d25  FUN_007e3d25  6 bytes, 0 callers */

undefined ** FUN_007e3d25(void)

{
  return &PTR_s_CVSListBox_0098a050;
}




/* vtable slots: CVSListBox[94], CVSToolsListBox[94] */
/* 007e3d37  GetSelItem  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CVSListBox::GetSelItem(void)const 
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CVSListBox::GetSelItem(CVSListBox *this)

{
  LRESULT LVar1;
  
  if (((this != (CVSListBox *)0x0) && (*(int *)(this + 0x20) != 0)) && (*(int *)(this + 0x110) != 0)
     ) {
    LVar1 = SendMessageW(*(HWND *)(*(int *)(this + 0x110) + 0x20),0x100c,0xffffffff,2);
    return LVar1;
  }
  return -1;
}




/* vtable slots: CVSListBox[101], CVSListBoxBase[101], CVSToolsListBox[101] */
/* 007e3e70  FUN_007e3e70  511 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_007e3e70(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  HWND__ *pHVar5;
  CWnd *pCVar6;
  CVSListBoxBase *in_ECX;
  code *pcVar7;
  bool bVar8;
  undefined1 local_1c [4];
  uint local_18;
  undefined1 *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  puVar1 = &LAB_00947ace;
  local_8 = 0x7e3e7c;
  if (*(int *)(in_ECX + 0xd4) != 0) {
    pcVar7 = *(code **)(*(int *)in_ECX + 0x178);
    guard_check_icall();
    puVar2 = (undefined1 *)(*pcVar7)();
    local_14 = puVar2;
    puVar1 = (undefined1 *)CVSListBoxBase::GetButtonID(in_ECX,param_1);
    if ((puVar1 == (undefined1 *)0xfffffff2) || (puVar1 == (undefined1 *)0xfffffff3)) {
      if (-1 < (int)puVar2) {
        local_18 = (uint)(puVar1 == (undefined1 *)0xfffffff3);
        if (puVar1 == (undefined1 *)0xfffffff3) {
          bVar8 = puVar2 == (undefined1 *)0x0;
        }
        else {
          pcVar7 = *(code **)(*(int *)in_ECX + 0x174);
          guard_check_icall();
          iVar3 = (*pcVar7)();
          puVar1 = (undefined1 *)(iVar3 + -1);
          bVar8 = puVar2 == puVar1;
        }
        if (!bVar8) {
          SendMessageW(*(HWND *)(in_ECX + 0x20),0xb,0,0);
          pcVar7 = *(code **)(*(int *)in_ECX + 0x180);
          guard_check_icall(local_1c,puVar2);
          (*pcVar7)();
          local_8 = 0;
          pcVar7 = *(code **)(*(int *)in_ECX + 0x188);
          guard_check_icall(puVar2);
          uVar4 = (*pcVar7)();
          *(undefined4 *)(in_ECX + 0xdc) = 0;
          pcVar7 = *(code **)(*(int *)in_ECX + 0x170);
          guard_check_icall(local_14);
          (*pcVar7)();
          *(undefined4 *)(in_ECX + 0xdc) = 1;
          local_14 = local_14 + (local_18 ^ 1) * 2 + -1;
          pcVar7 = *(code **)(*(int *)in_ECX + 0x16c);
          guard_check_icall(local_1c,uVar4,local_14);
          (*pcVar7)();
          puVar1 = local_14;
          pcVar7 = *(code **)(*(int *)in_ECX + 0x17c);
          guard_check_icall(local_14);
          (*pcVar7)();
          SendMessageW(*(HWND *)(in_ECX + 0x20),0xb,1,0);
          pcVar7 = *(code **)(*(int *)in_ECX + 0x1c4);
          guard_check_icall();
          pHVar5 = (HWND__ *)(*pcVar7)();
          pCVar6 = CWnd::FromHandle(pHVar5);
          if (pCVar6 != (CWnd *)0x0) {
            InvalidateRect(*(HWND *)(pCVar6 + 0x20),(RECT *)0x0,1);
          }
          if (local_18 == 0) {
            pcVar7 = *(code **)(*(int *)in_ECX + 0x1b8);
          }
          else {
            pcVar7 = *(code **)(*(int *)in_ECX + 0x1b4);
          }
          guard_check_icall(puVar1);
          (*pcVar7)();
          puVar1 = (undefined1 *)FUN_00406b10();
        }
      }
    }
    else if (puVar1 == (undefined1 *)0xfffffff4) {
      if (-1 < (int)puVar2) {
        pcVar7 = *(code **)(*(int *)in_ECX + 0x1a8);
        guard_check_icall(puVar2);
        iVar3 = (*pcVar7)();
        puVar1 = (undefined1 *)0x0;
        if (iVar3 != 0) {
          pcVar7 = *(code **)(*(int *)in_ECX + 0x170);
          guard_check_icall(puVar2);
          puVar1 = (undefined1 *)(*pcVar7)();
        }
      }
    }
    else if (puVar1 == (undefined1 *)0xfffffff5) {
      pcVar7 = *(code **)(*(int *)in_ECX + 0x1c0);
      guard_check_icall();
      puVar1 = (undefined1 *)(*pcVar7)();
    }
  }
  return puVar1;
}




/* vtable slots: CVSListBox[61], CVSListBoxBase[61], CVSToolsListBox[61] */
/* 007e406f  FUN_007e406f  126 bytes, 0 callers */

undefined4 FUN_007e406f(undefined4 param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  HWND__ *pHVar4;
  CWnd *pCVar5;
  int *in_ECX;
  undefined4 *puVar6;
  int iVar7;
  
  iVar7 = 0;
  puVar6 = (undefined4 *)in_ECX[0x21];
  while( true ) {
    if (puVar6 == (undefined4 *)0x0) {
      uVar3 = FUN_00793275(param_1,param_2);
      return uVar3;
    }
    piVar1 = puVar6 + 2;
    puVar6 = (undefined4 *)*puVar6;
    if (*piVar1 == 0) break;
    if (*(int *)(*piVar1 + 0x20) == param_2) {
      pcVar2 = *(code **)(*in_ECX + 0x1c4);
      guard_check_icall();
      pHVar4 = (HWND__ *)(*pcVar2)();
      pCVar5 = CWnd::FromHandle(pHVar4);
      if (pCVar5 != (CWnd *)0x0) {
        FUN_00797df8();
      }
      pcVar2 = *(code **)(*in_ECX + 0x194);
      guard_check_icall(iVar7);
      (*pcVar2)();
      return 1;
    }
    iVar7 = iVar7 + 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CVSListBox[114], CVSToolsListBox[114] */
/* 007e410c  OnCreateList  213 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual class CWnd * __thiscall CVSListBox::OnCreateList(void)
   
   Library: Visual Studio 2015 Release */

CWnd * __thiscall CVSListBox::OnCreateList(CVSListBox *this)

{
  undefined4 *puVar1;
  CWnd *pCVar2;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x7e4118;
  if (((this != (CVSListBox *)0x0) && (*(int *)(this + 0x20) != 0)) && (*(int *)(this + 0x110) == 0)
     ) {
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    SetRectEmpty(&local_24);
    puVar1 = (undefined4 *)FUN_0078e624(0x80);
    local_8 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_007907c8();
      *puVar1 = CListCtrl::vftable;
    }
    local_8 = 0xffffffff;
    *(undefined4 **)(this + 0x110) = puVar1;
    FUN_007920d9(0x200,L"SysListView32",&DAT_00956338,0x5000420d,&local_24,this,1,0);
    SendMessageW(*(HWND *)(*(int *)(this + 0x110) + 0x20),0x1036,0,0x20);
    FUN_007a4672(0,&DAT_00956338,0,0xffffffff,0xffffffff);
  }
  pCVar2 = (CWnd *)FUN_008d9b68();
  return pCVar2;
}




/* vtable slots: CVSListBox[103], CVSListBoxBase[103], CVSToolsListBox[103] */
/* 007e42c9  FUN_007e42c9  187 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007e42c9(undefined2 *param_1)

{
  int iVar1;
  int *in_ECX;
  code *pcVar2;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7e42d5;
  pcVar2 = *(code **)(*in_ECX + 0x178);
  guard_check_icall();
  iVar1 = (*pcVar2)();
  if (iVar1 < 0) {
    return;
  }
  if (param_1 == (undefined2 *)0x0) {
    param_1 = &DAT_00956338;
  }
  CStringT<>(param_1);
  local_8 = 0;
  if (*(int *)(local_14[0] + -0xc) == 0) {
    if (in_ECX[0x36] == 0) goto LAB_007e436a;
    pcVar2 = *(code **)(*in_ECX + 0x170);
  }
  else {
    pcVar2 = *(code **)(*in_ECX + 0x184);
    guard_check_icall(iVar1,local_14);
    (*pcVar2)();
    if (in_ECX[0x36] == 0) {
      pcVar2 = *(code **)(*in_ECX + 0x1b0);
    }
    else {
      pcVar2 = *(code **)(*in_ECX + 0x1ac);
    }
  }
  guard_check_icall(iVar1);
  (*pcVar2)();
LAB_007e436a:
  in_ECX[0x36] = 0;
  FUN_00406b10();
  return;
}




/* vtable slots: CVSListBox[104], CVSListBoxBase[104], CVSToolsListBox[104] */
/* 007e43f1  FUN_007e43f1  6 bytes, 0 callers */

undefined4 FUN_007e43f1(void)

{
  return 0xffffffff;
}




/* vtable slots: CVSListBox[102], CVSListBoxBase[102], CVSToolsListBox[102] */
/* 007e45c8  FUN_007e45c8  98 bytes, 0 callers */

void FUN_007e45c8(ushort param_1,char param_2)

{
  code *pcVar1;
  int iVar2;
  UINT UVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x178);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  UVar3 = MapVirtualKeyW((uint)param_1,2);
  if (((param_2 == '\0') && (-1 < iVar2)) && (((UVar3 & 0xffff) == 0x20 || (param_1 == 0x71)))) {
    pcVar1 = *(code **)(*in_ECX + 400);
    guard_check_icall(iVar2);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CVSListBox[115], CVSToolsListBox[115] */
/* 007e49fc  FUN_007e49fc  134 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007e49fc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (((in_ECX != 0) && (*(int *)(in_ECX + 0x20) != 0)) && (*(int *)(in_ECX + 0x110) != 0)) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
    iVar1 = *(int *)(in_ECX + 0x110);
    iVar4 = local_18.right - local_18.left;
    iVar2 = GetSystemMetrics(0x2d);
    iVar3 = GetSystemMetrics(2);
    SendMessageW(*(HWND *)(iVar1 + 0x20),0x101e,0,(iVar4 + iVar2 * -2) - iVar3 & 0xffff);
  }
  return;
}




/* vtable slots: CVSListBox[20], CVSListBoxBase[20], CVSToolsListBox[20] */
/* 007e4a9e  FUN_007e4a9e  29 bytes, 0 callers */

void FUN_007e4a9e(void)

{
  _AFX_THREAD_STATE *p_Var1;
  
  guard_check_icall();
  p_Var1 = AfxGetThreadState();
  if (*(int *)(p_Var1 + 0x14) == 0) {
    FUN_007e3d62();
    return;
  }
  return;
}




/* vtable slots: CVSListBox[67], CVSToolsListBox[67] */
/* 007e4abb  FUN_007e4abb  493 bytes, 0 callers */

undefined4 FUN_007e4abb(int param_1)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  uint uVar6;
  WPARAM wParam;
  LRESULT LVar7;
  int iVar8;
  undefined4 uVar9;
  int *in_ECX;
  tagPOINT local_10;
  uint local_8;
  
  bVar2 = false;
  if (((*(int *)(param_1 + 4) == 0x201) && (in_ECX[0x44] != 0)) &&
     (iVar3 = FUN_007e3c09(), iVar3 == 0)) {
    if (in_ECX[0x44] == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(uint *)(in_ECX[0x44] + 0x20);
    }
    pHVar4 = GetFocus();
    pCVar5 = CWnd::FromHandle(pHVar4);
    if (pCVar5 == (CWnd *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(uint *)(pCVar5 + 0x20);
    }
    if (local_8 == uVar6) {
      in_ECX[0x45] = -1;
      in_ECX[0x46] = -1;
      local_10.x = *(int *)(param_1 + 0x14);
      local_10.y = *(int *)(param_1 + 0x18);
      ScreenToClient(*(HWND *)(in_ECX[0x44] + 0x20),&local_10);
      wParam = FUN_007a45f0(local_10.x,local_10.y,&local_8);
      if (((-1 < (int)wParam) && ((local_8 & 4) != 0)) &&
         (LVar7 = SendMessageW(*(HWND *)(in_ECX[0x44] + 0x20),0x102c,wParam,3),
         ((byte)LVar7 & 3) == 3)) {
        in_ECX[0x45] = local_10.x;
        in_ECX[0x46] = local_10.y;
        pHVar4 = SetCapture((HWND)in_ECX[8]);
        CWnd::FromHandle(pHVar4);
        return 1;
      }
      goto LAB_007e4c99;
    }
  }
  if ((*(int *)(param_1 + 4) == 0x202) && (iVar3 = FUN_004208d0(0xffffffff,0xffffffff), iVar3 != 0))
  {
    ReleaseCapture();
    local_10.x = *(int *)(param_1 + 0x14);
    local_10.y = *(int *)(param_1 + 0x18);
    ScreenToClient(*(HWND *)(in_ECX[0x44] + 0x20),&local_10);
    local_8 = FUN_007a45f0(local_10.x,local_10.y,0);
    if (-1 < (int)local_8) {
      iVar3 = _abs(local_10.x - in_ECX[0x45]);
      iVar8 = GetSystemMetrics(0x44);
      if (iVar3 < iVar8) {
        iVar3 = _abs(local_10.y - in_ECX[0x46]);
        iVar8 = GetSystemMetrics(0x45);
        if (iVar3 < iVar8) {
          bVar2 = true;
        }
      }
    }
    in_ECX[0x45] = -1;
    in_ECX[0x46] = -1;
    if (bVar2) {
      pcVar1 = *(code **)(*in_ECX + 400);
      guard_check_icall(local_8);
      (*pcVar1)();
    }
    return 1;
  }
LAB_007e4c99:
  uVar9 = FUN_007949fb(param_1);
  return uVar9;
}




/* vtable slots: CVSListBox[92], CVSToolsListBox[92] */
/* 007e4ca8  FUN_007e4ca8  186 bytes, 0 callers */

undefined4 FUN_007e4ca8(WPARAM param_1)

{
  code *pcVar1;
  WPARAM WVar2;
  LRESULT LVar3;
  int iVar4;
  int *in_ECX;
  
  if (((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) && (in_ECX[0x44] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x178);
    guard_check_icall();
    WVar2 = (*pcVar1)();
    LVar3 = SendMessageW(*(HWND *)(in_ECX[0x44] + 0x20),0x1008,param_1,0);
    if ((LVar3 != 0) && (WVar2 == param_1)) {
      pcVar1 = *(code **)(*in_ECX + 0x174);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 != 0) {
        pcVar1 = *(code **)(*in_ECX + 0x174);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 <= (int)param_1) {
          param_1 = param_1 - 1;
        }
        pcVar1 = *(code **)(*in_ECX + 0x17c);
        guard_check_icall(param_1);
        (*pcVar1)();
        return 1;
      }
    }
  }
  return 0;
}




/* vtable slots: CVSListBox[95], CVSToolsListBox[95] */
/* 007e4d62  SelectItem  76 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CVSListBox::SelectItem(int)
   
   Library: Visual Studio 2012 Release */

int __thiscall CVSListBox::SelectItem(CVSListBox *this,int param_1)

{
  int iVar1;
  LRESULT LVar2;
  
  if ((((this != (CVSListBox *)0x0) && (*(int *)(this + 0x20) != 0)) &&
      (*(CListCtrl **)(this + 0x110) != (CListCtrl *)0x0)) &&
     (iVar1 = CListCtrl::SetItemState(*(CListCtrl **)(this + 0x110),param_1,3,3), iVar1 != 0)) {
    LVar2 = SendMessageW(*(HWND *)(*(int *)(this + 0x110) + 0x20),0x1013,param_1,0);
    return LVar2;
  }
  return 0;
}




/* vtable slots: CVSListBox[99], CVSToolsListBox[99] */
/* 007e4e59  SetItemData  47 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CVSListBox::SetItemData(int,unsigned long)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CVSListBox::SetItemData(CVSListBox *this,int param_1,ulong param_2)

{
  if (((this != (CVSListBox *)0x0) && (*(int *)(this + 0x20) != 0)) && (*(int *)(this + 0x110) != 0)
     ) {
    SetItem(param_1,0,4,0,0,0,0,param_2);
  }
  return;
}




/* vtable slots: CVSListBox[97], CVSToolsListBox[97] */
/* 007e4e88  SetItemText  42 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual void __thiscall CVSListBox::SetItemText(int,class ATL::CStringT<char,class
   StrTraitMFC<char,class ATL::ChTraitsCRT<char> > > const &)
    protected: virtual void __thiscall CVSListBox::SetItemText(int,class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > const &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

void SetItemText(int param_1,undefined4 *param_2)

{
  int in_ECX;
  
  if (((in_ECX != 0) && (*(int *)(in_ECX + 0x20) != 0)) &&
     (*(CListCtrl **)(in_ECX + 0x110) != (CListCtrl *)0x0)) {
    CListCtrl::SetItemText(*(CListCtrl **)(in_ECX + 0x110),param_1,0,(wchar_t *)*param_2);
  }
  return;
}



