/* CMFCTasksPane -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTasksPane[1] */
/* 008d3829  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCTasksPane::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCTasksPane::_scalar_deleting_destructor_(CMFCTasksPane *this,uint param_1)

{
  FUN_008d36d4();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1290);
    }
  }
  return this;
}




/* vtable slots: CMFCTasksPane[133] */
/* 008d3f8a  FUN_008d3f8a  59 bytes, 0 callers */

void FUN_008d3f8a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined **ppuVar2;
  int in_ECX;
  
  uVar1 = FUN_00797b3d();
  ppuVar2 = &PTR_s_CMultiPaneFrameWnd_00a00968;
  if ((uVar1 & 0x40) == 0) {
    ppuVar2 = &PTR_s_CMFCTasksPaneFrameWnd_00a00c90;
  }
  *(undefined ***)(in_ECX + 0x188) = ppuVar2;
  FUN_007ef5ff(param_1,param_2,param_3,param_4);
  return;
}




/* vtable slots: CMFCTasksPane[153] */
/* 008d47b9  FUN_008d47b9  241 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008d47b9(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int *piVar4;
  int *in_ECX;
  undefined1 *puVar5;
  undefined1 *local_6c;
  int local_68;
  undefined1 local_60 [44];
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x8d47c5;
  FUN_007e522a(param_1,in_ECX);
  local_8 = 0;
  puVar5 = local_60;
  if (local_68 == 0) {
    puVar5 = local_6c;
  }
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  GetClientRect((HWND)in_ECX[8],&local_24);
  local_34.left = local_24.left;
  local_34.top = local_24.top;
  local_34.right = local_24.right;
  local_34.bottom = local_24.bottom;
  SetRectEmpty(&local_34);
  pcVar1 = *(code **)(*in_ECX + 0x3c4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    local_34.left = local_24.left;
    local_34.top = local_24.top;
    local_34.right = local_24.right;
    local_34.bottom = local_24.bottom;
    InflateRect(&local_24,-1,-1);
  }
  pcVar1 = *(code **)(*in_ECX + 0x3cc);
  guard_check_icall(puVar5,local_24.left,local_24.top,local_24.right,local_24.bottom);
  (*pcVar1)();
  BVar3 = IsRectEmpty(&local_34);
  if (BVar3 == 0) {
    piVar4 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar4 + 0x180);
    guard_check_icall(puVar5,&local_34);
    (*pcVar1)();
  }
  FUN_007e54da();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCTasksPane[224] */
/* 008d48aa  FUN_008d48aa  215 bytes, 0 callers */

void FUN_008d48aa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  
  iVar6 = 0;
  iVar1 = *(int *)(in_ECX + 0x470);
  if (0 < *(int *)(in_ECX + 0x33c)) {
    do {
      piVar3 = (int *)FUN_00799cf8(iVar6);
      iVar2 = *piVar3;
      iVar4 = FUN_008aee34();
      if (((iVar4 == 0x17) || (iVar4 == 0x18)) || (iVar4 == 0x19)) {
        if (((*(int *)(iVar2 + 0xc) == 0) && (1 < iVar1)) && (*(int *)(in_ECX + 0x36c) == 0)) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        *(undefined4 *)(iVar2 + 0xc) = uVar5;
      }
      iVar4 = FUN_008aee34();
      if (iVar4 == 0x17) {
        *(uint *)(iVar2 + 0x10) = (uint)(0 < *(int *)(in_ECX + 0x38c));
      }
      iVar4 = FUN_008aee34();
      if (iVar4 == 0x18) {
        *(uint *)(iVar2 + 0x10) = (uint)(*(int *)(in_ECX + 0x38c) < *(int *)(in_ECX + 0x530) + -1);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0x33c));
  }
  FUN_00891d28();
  FUN_0088e2f7(param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CMFCTasksPane[245] */
/* 008d4a7a  FUN_008d4a7a  162 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008d4a7a(int param_1,undefined4 param_2,CSimpleStringT<wchar_t,0> *param_3)

{
  short sVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  wchar_t local_40c [514];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  piVar2 = (int *)FUN_007b299b(param_2);
  if (*(int *)(*piVar2 + -0xc) != 0) {
    _memset(local_40c,0,0x402);
    puVar3 = (undefined4 *)FUN_007b299b(param_2);
    sVar1 = FUN_007a8394(*puVar3,local_40c,0x200);
    if (sVar1 == 0) {
      iVar4 = FUN_008f899d(local_40c);
      ATL::CSimpleStringT<wchar_t,0>::SetString(param_3,local_40c,iVar4);
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCTasksPane[10] */
/* 008d4b1d  FUN_008d4b1d  6 bytes, 0 callers */

undefined ** FUN_008d4b1d(void)

{
  return &PTR_FUN_009a8bf0;
}




/* vtable slots: CMFCTasksPane[0] */
/* 008d4c02  FUN_008d4c02  6 bytes, 0 callers */

undefined ** FUN_008d4c02(void)

{
  return &PTR_s_CMFCTasksPane_00a00d6c;
}




/* vtable slots: CMFCTasksPane[30] */
/* 008d4c20  GetScrollBarCtrl  31 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual class CScrollBar * __thiscall CMFCPropertyGridCtrl::GetScrollBarCtrl(int)const 
    public: virtual class CScrollBar * __thiscall CMFCTasksPane::GetScrollBarCtrl(int)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

int GetScrollBarCtrl(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (((param_1 == 0) || (iVar1 = in_ECX + 0x4a0, iVar1 == 0)) || (*(int *)(in_ECX + 0x4c0) == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}




/* vtable slots: CMFCTasksPane[246] */
/* 008d4c5b  FUN_008d4c5b  61 bytes, 0 callers */

undefined4 * FUN_008d4c5b(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x3c4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    *param_1 = 1;
    param_1[1] = 1;
  }
  else {
    *param_1 = 0;
    param_1[1] = 0;
  }
  return param_1;
}




/* vtable slots: CMFCTasksPane[249] */
/* 008d4c98  FUN_008d4c98  159 bytes, 0 callers */

int FUN_008d4c98(LONG param_1,LONG param_2)

{
  int iVar1;
  POINT pt;
  POINT pt_00;
  BOOL BVar2;
  int *piVar3;
  __POSITION *p_Var4;
  int iVar5;
  int in_ECX;
  int local_8;
  
  if ((*(int *)(in_ECX + 0x368) == 0) ||
     (pt.y = param_2, pt.x = param_1, BVar2 = PtInRect((RECT *)(in_ECX + 0x444),pt), BVar2 == 0)) {
LAB_008d4d25:
    iVar5 = 0;
  }
  else {
    piVar3 = (int *)FUN_00799cf8(*(undefined4 *)(in_ECX + 0x38c));
    p_Var4 = CObList::FindIndex((CObList *)(in_ECX + 0x464),*piVar3);
    if (p_Var4 == (__POSITION *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    iVar1 = *(int *)(p_Var4 + 8);
    local_8 = *(int *)(in_ECX + 0x484);
    do {
      if (local_8 == 0) goto LAB_008d4d25;
      iVar5 = FUN_0049acb0(&local_8);
    } while ((*(int *)(iVar5 + 4) != iVar1) ||
            (pt_00.y = param_2, pt_00.x = param_1, BVar2 = PtInRect((RECT *)(iVar5 + 0x34),pt_00),
            BVar2 == 0));
  }
  return iVar5;
}




/* vtable slots: CMFCTasksPane[139] */
/* 008d4d59  FUN_008d4d59  398 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008d4d59(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_b4 [72];
  undefined1 local_6c [52];
  undefined4 local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  int *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa4;
  local_8 = 0x8d4d68;
  FUN_008592c1(&local_20,L"MFCTasksPanes",param_1);
  local_2c = 0;
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_18,L"%TsMFCTasksPane-%d",local_20,param_2);
  }
  else {
    FUN_004059f0(local_18,L"%TsMFCTasksPane-%d%x",local_20,param_2,param_3);
  }
  local_1c = 0;
  local_34 = (int *)0x0;
  local_30 = 0;
  local_8._0_1_ = 2;
  local_24 = (int *)FUN_00859490(0,1);
  pcVar1 = *(code **)(*local_24 + 0x10);
  guard_check_icall(local_18[0]);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if (local_34 != (int *)0x0) {
      pcVar1 = *(code **)(*local_34 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    FUN_00406b10();
    FUN_00406b10();
    local_2c = 0;
  }
  else {
    pcVar1 = *(code **)(*local_24 + 0x44);
    guard_check_icall(L"Settings",&local_1c,&local_38);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      local_8._0_1_ = 3;
      FUN_007b57de(local_1c,local_38,0);
      local_8._0_1_ = 4;
      FUN_007a6256(local_6c,1,0x1000,0);
      local_8 = CONCAT31(local_8._1_3_,5);
      pcVar1 = *(code **)(*local_28 + 8);
      guard_check_icall(local_b4);
      (*pcVar1)();
      FUN_007a6389();
      FUN_007b583b();
      uVar3 = FUN_008d4f09(local_18[0]);
      return uVar3;
    }
    if (local_34 != (int *)0x0) {
      pcVar1 = *(code **)(*local_34 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    FUN_00406b10();
    FUN_00406b10();
  }
  return local_2c;
}




/* vtable slots: CMFCTasksPane[238] */
/* 008d4fb7  FUN_008d4fb7  184 bytes, 0 callers */

void FUN_008d4fb7(void)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  BOOL BVar5;
  CWnd *pCVar6;
  CWnd *in_ECX;
  
  pcVar1 = *(code **)(*(int *)in_ECX + 0x3c4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    return;
  }
  pHVar3 = GetFocus();
  pCVar4 = CWnd::FromHandle(pHVar3);
  if ((pCVar4 != (CWnd *)0x0) &&
     (BVar5 = IsChild(*(HWND *)(in_ECX + 0x20),*(HWND *)(pCVar4 + 0x20)), BVar5 != 0)) {
    while (pCVar4 != in_ECX) {
      pHVar3 = GetParent(*(HWND *)(pCVar4 + 0x20));
      pCVar6 = CWnd::FromHandle(pHVar3);
      if (pCVar6 == in_ECX) {
        iVar2 = FUN_0079272f();
        SendMessageW(*(HWND *)(pCVar4 + 0x20),0x111,*(WPARAM *)(iVar2 + 8),*(LPARAM *)(iVar2 + 0xc))
        ;
        break;
      }
      pHVar3 = GetParent(*(HWND *)(pCVar4 + 0x20));
      pCVar4 = CWnd::FromHandle(pHVar3);
    }
  }
  iVar2 = DAT_00a13a1c;
  if (DAT_00a13a1c == 0) {
    iVar2 = FUN_00792b4c();
    pHVar3 = (HWND)0x0;
    if (iVar2 == 0) goto LAB_008d5058;
  }
  pHVar3 = *(HWND *)(iVar2 + 0x20);
LAB_008d5058:
  BVar5 = IsWindow(pHVar3);
  if (BVar5 == 0) {
    return;
  }
  FUN_00797df8();
  return;
}




/* vtable slots: CMFCTasksPane[236] */
/* 008d518c  OnClickTask  37 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCTasksPane::OnClickTask(int,int,unsigned int,unsigned long)
   
   Library: Visual Studio 2010 Release */

void __thiscall
CMFCTasksPane::OnClickTask(CMFCTasksPane *this,int param_1,int param_2,uint param_3,ulong param_4)

{
  CWnd *pCVar1;
  
  if (param_3 != 0) {
    pCVar1 = CWnd::GetOwner((CWnd *)this);
    PostMessageW(*(HWND *)(pCVar1 + 0x20),0x111,param_3,0);
  }
  return;
}




/* vtable slots: CMFCTasksPane[243] */
/* 008d53a5  FUN_008d53a5  1006 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008d53a5(undefined4 param_1)

{
  RECT *pRVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  __POSITION *p_Var5;
  HRGN pHVar6;
  BOOL BVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  int *in_ECX;
  undefined **local_48;
  HRGN local_44;
  code *local_40;
  int local_3c;
  int *local_38;
  RECT *local_34;
  int local_30;
  undefined4 local_2c;
  int *local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x8d53b1;
  local_2c = param_1;
  local_48 = (undefined **)in_ECX[0x113];
  local_44 = (HRGN)in_ECX[0x114];
  local_40 = *(code **)(*in_ECX + 0x3c8);
  local_28 = in_ECX;
  guard_check_icall(param_1,in_ECX[0x111],in_ECX[0x112] - in_ECX[0xe9] * in_ECX[0xe6],local_48,
                    local_44);
  piVar8 = local_28;
  (*local_40)();
  piVar4 = (int *)FUN_005db5d0(piVar8[0xe3]);
  p_Var5 = CObList::FindIndex((CObList *)(piVar8 + 0x119),*piVar4);
  if (p_Var5 != (__POSITION *)0x0) {
    iVar10 = *(int *)(p_Var5 + 8);
    local_44 = (HRGN)0x0;
    local_48 = CRgn::vftable;
    local_8 = 0;
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    local_3c = iVar10;
    pHVar6 = CreateRectRgnIndirect(&local_24);
    Attach(pHVar6);
    local_40 = (code *)piVar8[0x121];
    pRVar1 = local_34;
    while (local_34 = pRVar1, local_40 != (code *)0x0) {
      piVar4 = (int *)FUN_0044f2d0(&local_40);
      iVar2 = *piVar4;
      pRVar1 = local_34;
      local_30 = iVar2;
      if (*(int *)(iVar2 + 4) == iVar10) {
        if (((*(int *)(iVar2 + 0x30) == 0) || (*(int *)(*(int *)(iVar2 + 8) + -0xc) == 0)) ||
           ((piVar8[0xde] != 0 && ((iVar2 == piVar8[0x151] && (0 < piVar8[0x104])))))) {
          pRVar1 = (RECT *)(iVar2 + 0x44);
          local_34 = pRVar1;
          BVar7 = IsRectEmpty(pRVar1);
          if (BVar7 == 0) {
            local_38 = (int *)FUN_007c2574();
            pcVar3 = *(code **)(*local_38 + 0x170);
            guard_check_icall(local_2c,pRVar1->left,*(undefined4 *)(iVar2 + 0x48),
                              *(undefined4 *)(iVar2 + 0x4c),*(undefined4 *)(iVar2 + 0x50),0);
            (*pcVar3)();
          }
          BVar7 = IsRectEmpty((RECT *)(local_30 + 0x34));
          if (BVar7 == 0) {
            piVar8 = (int *)FUN_007c2574();
            pcVar3 = *(code **)(*piVar8 + 0x168);
            guard_check_icall(local_2c,local_30,local_28[0x14f] == local_30,0,local_28[0xda]);
            (*pcVar3)();
          }
          BVar7 = IsRectEmpty(local_34);
          piVar8 = local_28;
          iVar10 = local_3c;
          pRVar1 = local_34;
          if (BVar7 == 0) {
            pcVar3 = *(code **)(*local_28 + 0x3d8);
            guard_check_icall(&local_24.right);
            (*pcVar3)();
            if ((0 < local_24.right) || (0 < local_24.bottom)) {
              local_38 = (int *)FUN_007c2574();
              pcVar3 = *(code **)(*local_38 + 0x174);
              guard_check_icall(local_2c,local_34->left,local_34->top,local_34->right,
                                local_34->bottom,*(undefined4 *)(local_30 + 0x2c),
                                *(int *)(*(int *)(local_30 + 8) + -0xc) == 0);
              (*pcVar3)();
              piVar8 = local_28;
            }
            local_34 = *(RECT **)(local_30 + 0x10);
            iVar10 = local_3c;
            pRVar1 = (RECT *)0x0;
            if (local_34 != (RECT *)0x0) {
              local_30 = local_30 + 0xc;
              do {
                puVar9 = (undefined4 *)FUN_0044f2d0(&local_34);
                local_38 = (int *)*puVar9;
                if ((local_38[0xd] != 0) && (local_38[0xb] == 0)) {
                  SetRectRgn(local_44,local_38[3],local_38[4],local_38[5],local_38[6]);
                  FUN_0079eeb5(&local_48);
                  piVar8 = (int *)FUN_007c2574();
                  pcVar3 = *(code **)(*piVar8 + 0x178);
                  guard_check_icall(local_2c,local_38,local_28 + 0x148,
                                    local_38 == (int *)local_28[0x117],0);
                  (*pcVar3)();
                  FUN_0079eeb5(0);
                }
                iVar10 = local_3c;
                pRVar1 = (RECT *)0x0;
                piVar8 = local_28;
              } while (local_34 != (RECT *)0x0);
            }
          }
        }
        else {
          BVar7 = IsRectEmpty((RECT *)(iVar2 + 0x34));
          pRVar1 = local_34;
          if (BVar7 == 0) {
            piVar8 = (int *)FUN_007c2574();
            pcVar3 = *(code **)(*piVar8 + 0x168);
            guard_check_icall(local_2c,local_30,local_28[0x14f] == local_30,0,local_28[0xda]);
            (*pcVar3)();
            iVar10 = local_3c;
            pRVar1 = local_34;
            piVar8 = local_28;
          }
        }
      }
    }
    CGdiObject::DeleteObject((CGdiObject *)&local_48);
    if (piVar8[0xdb] != 0) {
      InvalidateRect((HWND)piVar8[0x15a],(RECT *)0x0,1);
      UpdateWindow((HWND)piVar8[0x15a]);
    }
    if (piVar8[0xdd] != 0) {
      if (0 < piVar8[0xe6]) {
        piVar8 = (int *)FUN_007c2574();
        pcVar3 = *(code **)(*piVar8 + 0x17c);
        guard_check_icall(local_2c,local_28 + 0x109,1,7,(uint)local_28[0xe4] >> 0x1f);
        (*pcVar3)();
      }
      iVar10 = FUN_008d4d38();
      if (iVar10 != 0) {
        piVar8 = (int *)FUN_007c2574();
        pcVar3 = *(code **)(*piVar8 + 0x17c);
        guard_check_icall(local_2c,local_28 + 0x10d,1,0,0 < local_28[0xe4]);
        (*pcVar3)();
      }
    }
    local_48 = CRgn::vftable;
    FUN_00416100();
    FUN_008d9b68();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCTasksPane[242] */
/* 008d5794  FUN_008d5794  55 bytes, 0 callers */

void FUN_008d5794(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x164);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCTasksPane[237] */
/* 008d609d  FUN_008d609d  134 bytes, 0 callers */

void FUN_008d609d(void)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  BOOL BVar5;
  CWnd *pCVar6;
  CWnd *in_ECX;
  
  pcVar1 = *(code **)(*(int *)in_ECX + 0x3c4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pHVar3 = GetFocus();
    pCVar4 = CWnd::FromHandle(pHVar3);
    if ((pCVar4 != (CWnd *)0x0) &&
       (BVar5 = IsChild(*(HWND *)(in_ECX + 0x20),*(HWND *)(pCVar4 + 0x20)), BVar5 != 0)) {
      while (pCVar4 != in_ECX) {
        pHVar3 = GetParent(*(HWND *)(pCVar4 + 0x20));
        pCVar6 = CWnd::FromHandle(pHVar3);
        if (pCVar6 == in_ECX) {
          iVar2 = FUN_0079272f();
          SendMessageW(*(HWND *)(pCVar4 + 0x20),0x111,*(WPARAM *)(iVar2 + 8),
                       *(LPARAM *)(iVar2 + 0xc));
          return;
        }
        pHVar3 = GetParent(*(HWND *)(pCVar4 + 0x20));
        pCVar4 = CWnd::FromHandle(pHVar3);
      }
    }
  }
  return;
}




/* vtable slots: CMFCTasksPane[232] */
/* 008d6170  FUN_008d6170  27 bytes, 0 callers */

void FUN_008d6170(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x38c);
  if (0 < iVar1) {
    *(int *)(in_ECX + 0x38c) = iVar1 + -1;
    FUN_008d3e45(iVar1 + -1,iVar1);
  }
  return;
}




/* vtable slots: CMFCTasksPane[223] */
/* 008d618b  FUN_008d618b  113 bytes, 0 callers */

void FUN_008d618b(int param_1)

{
  CMFCCaptionButton *pCVar1;
  CDockablePane *in_ECX;
  code *pcVar2;
  
  if (param_1 == 0x17) {
    pcVar2 = *(code **)(*(int *)in_ECX + 0x3a0);
  }
  else {
    if (param_1 != 0x18) {
      if (param_1 != 0x19) {
        return;
      }
      pCVar1 = CDockablePane::FindButtonByHit(in_ECX,0x19);
      if (pCVar1 == (CMFCCaptionButton *)0x0) {
        return;
      }
      *(undefined4 *)(in_ECX + 0x380) = 1;
      pcVar2 = *(code **)(*(int *)in_ECX + 0x3ac);
      guard_check_icall(pCVar1);
      (*pcVar2)();
      *(undefined4 *)(in_ECX + 0x380) = 0;
      return;
    }
    pcVar2 = *(code **)(*(int *)in_ECX + 0x3a4);
  }
  guard_check_icall();
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCTasksPane[233] */
/* 008d61fc  FUN_008d61fc  34 bytes, 0 callers */

void FUN_008d61fc(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x38c);
  if (iVar1 < *(int *)(in_ECX + 0x530) + -1) {
    *(int *)(in_ECX + 0x38c) = iVar1 + 1;
    FUN_008d3e45(iVar1 + 1,iVar1);
  }
  return;
}




/* vtable slots: CMFCTasksPane[234] */
/* 008d621e  OnPressHomeButton  23 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCTasksPane::OnPressHomeButton(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCTasksPane::OnPressHomeButton(CMFCTasksPane *this)

{
  int iVar1;
  
  iVar1 = GetActivePage(this);
  if (iVar1 != 0) {
    SetActivePage(this,0);
  }
  return;
}




/* vtable slots: CMFCTasksPane[235] */
/* 008d6235  OnPressOtherButton  67 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCTasksPane::OnPressOtherButton(class CMFCCaptionMenuButton
   *,class CWnd *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCTasksPane::OnPressOtherButton(CMFCTasksPane *this,CMFCCaptionMenuButton *param_1,CWnd *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != (CMFCCaptionMenuButton *)0x0) {
    uVar1 = 0;
    if (this != (CMFCTasksPane *)0xfffffbac) {
      uVar1 = *(undefined4 *)(this + 0x458);
    }
    FUN_008b91bc(uVar1,param_2);
    if ((*(int *)(param_1 + 0x30) != 0) && (-1 < DAT_00a00958)) {
      SetActivePage(this,DAT_00a00958);
    }
  }
  return;
}




/* vtable slots: CMFCTasksPane[149] */
/* 008d6278  FUN_008d6278  312 bytes, 0 callers */

undefined4 FUN_008d6278(uint param_1)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  __POSITION *p_Var5;
  CMFCTasksPane *in_ECX;
  tagPOINT local_18;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_18.x = param_1 & 0xffff;
  local_18.y = param_1 >> 0x10;
  ScreenToClient(*(HWND *)(in_ECX + 0x20),&local_18);
  pcVar1 = *(code **)(*(int *)in_ECX + 0x3e4);
  guard_check_icall(local_18.x,local_18.y);
  piVar2 = (int *)(*pcVar1)();
  local_8 = piVar2;
  piVar3 = (int *)FUN_008d823e(local_18.x,local_18.y);
  local_10 = piVar3;
  if ((piVar2 == (int *)0x0) && (piVar3 == (int *)0x0)) {
    iVar4 = CMFCTasksPane::GetActivePage(in_ECX);
    p_Var5 = CObList::FindIndex((CObList *)(in_ECX + 0x464),iVar4);
    if (p_Var5 == (__POSITION *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    local_c = *(int **)(p_Var5 + 8);
    if (local_c != (int *)0x0) {
      pcVar1 = *(code **)(*local_c + 0xc);
      guard_check_icall();
      (*pcVar1)();
      *(undefined4 *)(in_ECX + 0xf4) = *(undefined4 *)(in_ECX + 0x444);
      *(undefined4 *)(in_ECX + 0xf8) = *(undefined4 *)(in_ECX + 0x448);
      *(undefined4 *)(in_ECX + 0xfc) = *(undefined4 *)(in_ECX + 0x44c);
      *(undefined4 *)(in_ECX + 0x100) = *(undefined4 *)(in_ECX + 0x450);
      FUN_0079e8b8(in_ECX + 0xf4);
      piVar2 = local_8;
      piVar3 = local_10;
    }
  }
  FUN_007ed2e1();
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0xc);
    guard_check_icall();
    (*pcVar1)();
    if (local_8 == *(int **)(in_ECX + 0x540)) {
      *(uint *)(in_ECX + 0xec) = *(uint *)(in_ECX + 0xec) | 0x200004;
    }
  }
  if (piVar3 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar3 + 0xc);
    guard_check_icall();
    (*pcVar1)();
    if (piVar3 == *(int **)(in_ECX + 0x460)) {
      *(uint *)(in_ECX + 0xec) = *(uint *)(in_ECX + 0xec) | 4;
    }
  }
  return 1;
}




/* vtable slots: CMFCTasksPane[226] */
/* 008d67f7  FUN_008d67f7  27 bytes, 0 callers */

void FUN_008d67f7(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x380) == 0) {
    FUN_00890908(param_1,param_2);
  }
  return;
}




/* vtable slots: CMFCTasksPane[145] */
/* 008d688f  FUN_008d688f  218 bytes, 0 callers */

void FUN_008d688f(CFrameWnd *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  CDockablePane *in_ECX;
  undefined **local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_18;
  CDockablePane *local_10;
  int local_c;
  int local_8;
  
  local_10 = in_ECX;
  CCmdUI::CCmdUI((CCmdUI *)&local_38);
  local_18 = *(undefined4 *)(in_ECX + 0x48c);
  local_30 = 0;
  local_c = *(int *)(in_ECX + 0x484);
  local_38 = CMFCTasksPaneToolBarCmdUI::vftable;
  while (local_c != 0) {
    piVar3 = (int *)FUN_0044f2d0(&local_c);
    local_8 = *(int *)(*piVar3 + 0x10);
    while (local_8 != 0) {
      piVar3 = (int *)FUN_0044f2d0(&local_8);
      iVar1 = *piVar3;
      if ((DAT_00a13bac != 0) && (*(uint *)(DAT_00a13bac + 0x24) <= *(uint *)(iVar1 + 0x24))) {
        param_2 = param_2 & -(uint)(*(uint *)(DAT_00a13bac + 0x28) < *(uint *)(iVar1 + 0x24));
      }
      local_34 = *(undefined4 *)(iVar1 + 0x24);
      uVar2 = *(uint *)(iVar1 + 0x24);
      if (((uVar2 != 0) && (0x1ef < uVar2 - 0xf000)) && (uVar2 < 0xff00)) {
        FUN_0078ff63(param_1,param_2);
      }
    }
    local_30 = local_30 + 1;
    local_8 = 0;
    in_ECX = local_10;
  }
  CDockablePane::OnUpdateCmdUI(in_ECX,param_1,param_2);
  return;
}




/* vtable slots: CMFCTasksPane[67] */
/* 008d6aed  FUN_008d6aed  247 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008d6aed(int *param_1)

{
  code *pcVar1;
  POINT pt;
  int *piVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 uVar5;
  int *in_ECX;
  int local_24;
  uint local_20;
  uint local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1[1] == 0x203) {
    local_1c = in_ECX[0x121];
    while (local_1c != 0) {
      piVar2 = (int *)FUN_0044f2d0(&local_1c);
      local_24 = *(int *)(*piVar2 + 0x10);
      if (local_24 != 0) {
        local_20 = *piVar2 + 0xc;
        do {
          piVar2 = (int *)FUN_0044f2d0(&local_24);
          if (*(int *)(*piVar2 + 0x2c) == *param_1) goto LAB_008d6bcb;
        } while (local_24 != 0);
      }
    }
    local_1c = (uint)*(ushort *)(param_1 + 3);
    local_20 = (uint)*(ushort *)((int)param_1 + 0xe);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetClientRect((HWND)in_ECX[8],&local_18);
    pcVar1 = *(code **)(*in_ECX + 0x3c4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      InflateRect(&local_18,-1,-1);
    }
    pt.y = local_20;
    pt.x = local_1c;
    BVar4 = PtInRect(&local_18,pt);
    if (BVar4 != 0) {
      return 1;
    }
  }
LAB_008d6bcb:
  uVar5 = FUN_00890abd(param_1);
  return uVar5;
}




/* vtable slots: CMFCTasksPane[248] */
/* 008d6c96  FUN_008d6c96  3265 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008d6c96(int param_1)

{
  code *pcVar1;
  RECT *pRVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  __POSITION *p_Var6;
  undefined4 uVar7;
  RECT *pRVar8;
  HWND__ *pHVar9;
  RECT *pRVar10;
  BOOL BVar11;
  int *in_ECX;
  CWnd *pCVar12;
  int iVar13;
  undefined1 local_134 [4];
  int local_130;
  int local_12c;
  CWnd *local_128;
  int local_124;
  CWnd *local_120;
  int local_11c;
  CWnd *local_118;
  undefined1 *local_114;
  CWnd *local_110;
  int local_10c;
  CWnd *local_108;
  int local_104;
  CWnd *local_100;
  int local_fc;
  CWnd *local_f8;
  int local_f4;
  CWnd *local_f0;
  int local_ec;
  RECT *local_e8;
  int local_e4;
  int local_e0;
  undefined4 local_dc;
  int *local_d8;
  int local_d4 [2];
  HDC local_cc;
  int local_c0;
  CWnd *local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  RECT *local_a4;
  RECT *local_a0;
  int local_9c;
  CWnd *local_98;
  CWnd *local_94;
  tagRECT local_90;
  tagTEXTMETRICW local_80;
  CWnd *local_44;
  CWnd *pCStack_40;
  int iStack_3c;
  CWnd *pCStack_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x124;
  local_8 = 0x8d6ca5;
  local_d8 = in_ECX;
  iVar3 = FUN_007c2511();
  if (*(int *)(iVar3 + 0x180) != 0) {
    in_ECX[0xde] = 0;
  }
  if ((((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) && (in_ECX[0x123] != 0)) &&
     ((-1 < in_ECX[0x112] && (in_ECX[0x112] < in_ECX[0x114])))) {
    iVar3 = in_ECX[0x111];
    if ((-1 < iVar3) && (iVar3 < in_ECX[0x113])) {
      local_90.left = in_ECX[0x111];
      local_90.top = in_ECX[0x112];
      local_90.right = in_ECX[0x113];
      local_90.bottom = in_ECX[0x114];
      iVar3 = in_ECX[0xeb];
      if (iVar3 == -1) {
        iVar3 = FUN_007c2574();
        iVar3 = *(int *)(iVar3 + 0x80);
      }
      iVar4 = in_ECX[0xec];
      if (iVar4 == -1) {
        iVar4 = FUN_007c2574();
        iVar4 = *(int *)(iVar4 + 0x84);
      }
      InflateRect(&local_90,-iVar4,-iVar3);
      FUN_0079dea2(in_ECX);
      local_8 = 0;
      local_dc = FUN_0079efbc(in_ECX + 0xf7);
      GetTextMetricsW(local_cc,&local_80);
      if (local_80.tmHeight <= in_ECX[0xfe]) {
        local_80.tmHeight = in_ECX[0xfe];
      }
      in_ECX[0xea] = 0;
      in_ECX[0xe9] = local_80.tmHeight;
      pCVar12 = (CWnd *)(local_90.top - in_ECX[0xe6] * local_80.tmHeight);
      local_94 = pCVar12;
      piVar5 = (int *)FUN_005db5d0(in_ECX[0xe3]);
      p_Var6 = CObList::FindIndex((CObList *)(in_ECX + 0x119),*piVar5);
      if (p_Var6 == (__POSITION *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      local_b8 = *(int *)(p_Var6 + 8);
      local_b0 = in_ECX[0x121];
      while (local_b0 != 0) {
        piVar5 = (int *)FUN_0044f2d0(&local_b0);
        iVar3 = *piVar5;
        local_ac = iVar3;
        if (*(int *)(iVar3 + 4) == local_b8) {
          FUN_0079efbc(in_ECX + 0xf7);
          local_98 = (CWnd *)(iVar3 + 8);
          if (*(int *)(*(int *)local_98 + -0xc) == 0) {
            iVar4 = 0;
            local_94 = pCVar12;
          }
          else {
            iVar3 = FUN_007c2511();
            uVar7 = FUN_0079efbc(iVar3 + 300);
            FUN_00566800(local_134,local_98);
            FUN_0079efbc(uVar7);
            local_9c = in_ECX[0xf0];
            if (local_9c == -1) {
              iVar3 = FUN_007c2574();
              local_9c = *(int *)(iVar3 + 0x94);
            }
            iVar13 = in_ECX[0xee];
            if (iVar13 == -1) {
              iVar3 = FUN_007c2574();
              iVar13 = *(int *)(iVar3 + 0x8c);
            }
            pcVar1 = *(code **)(*in_ECX + 0x3c4);
            guard_check_icall();
            iVar3 = (*pcVar1)();
            if (iVar3 != 0) {
              if (local_9c < 5) {
                local_9c = 5;
              }
              if (in_ECX[0xee] == -1) {
                iVar13 = 0x12;
              }
            }
            iVar4 = local_9c + local_130;
            iVar3 = local_ac;
            if (local_9c + local_130 <= iVar13) {
              iVar4 = iVar13;
            }
          }
          if (((*(int *)(iVar3 + 0x5c) != 0) &&
              (*(int *)(iVar3 + 0x54) < (local_90.right - local_90.left) - iVar4)) &&
             (iVar4 < *(int *)(iVar3 + 0x58))) {
            local_94 = local_94 + (*(int *)(iVar3 + 0x58) - iVar4);
          }
          pCVar12 = local_94 + iVar4;
          if (param_1 == 0) {
            local_fc = local_90.left;
            local_f4 = local_90.right;
            *(LONG *)(iVar3 + 0x34) = local_90.left;
            *(CWnd **)(iVar3 + 0x38) = local_94;
            *(LONG *)(iVar3 + 0x3c) = local_90.right;
            *(CWnd **)(iVar3 + 0x40) = pCVar12;
            iVar3 = local_ac;
            local_f8 = local_94;
            local_f0 = pCVar12;
          }
          local_98 = pCVar12;
          local_94 = pCVar12;
          FUN_008d7f52(local_d4);
          if ((((in_ECX[0xda] == 0) || (*(int *)(iVar3 + 0x30) == 0)) ||
              (*(int *)(*(int *)(iVar3 + 8) + -0xc) == 0)) ||
             (((in_ECX[0xde] != 0 && (iVar3 == in_ECX[0x151])) &&
              ((0 < in_ECX[0x104] && (param_1 == 0)))))) {
            local_9c = 1;
            local_a4 = (RECT *)0x1;
            pcVar1 = *(code **)(*in_ECX + 0x3d8);
            guard_check_icall(&local_e4);
            (*pcVar1)();
            local_b4 = *(int *)(iVar3 + 0x10);
            if (local_b4 != 0) {
              local_c0 = iVar3 + 0xc;
              do {
                pCVar12 = local_94;
                piVar5 = (int *)FUN_0044f2d0(&local_b4);
                iVar3 = *piVar5;
                pHVar9 = *(HWND__ **)(iVar3 + 0x2c);
                local_a8 = iVar3;
                if (pHVar9 == (HWND__ *)0x0) {
                  if (*(int *)(iVar3 + 0x34) == 0) {
                    if (param_1 == 0) {
                      SetRectEmpty((LPRECT)(iVar3 + 0xc));
                    }
LAB_008d73a1:
                    if ((local_a4 != (RECT *)0x0) &&
                       (pCVar12 = local_94, *(int *)(iVar3 + 0x34) != 0)) goto LAB_008d73d7;
                  }
                  else {
                    if (local_9c != 0) {
                      iVar4 = in_ECX[0xf3];
                      if (iVar4 == -1) {
                        iVar4 = FUN_007c2574();
                        iVar4 = *(int *)(iVar4 + 0xa0);
                      }
                      local_94 = pCVar12 + iVar4;
                    }
                    local_9c = in_ECX[0xf1];
                    if (local_9c == -1) {
                      iVar4 = FUN_007c2574();
                      local_9c = *(int *)(iVar4 + 0x98);
                    }
                    local_a4 = (RECT *)in_ECX[0xf2];
                    if (local_a4 == (RECT *)0xffffffff) {
                      iVar4 = FUN_007c2574();
                      local_a4 = *(RECT **)(iVar4 + 0x9c);
                    }
                    if (*(int *)(iVar3 + 0x24) == 0) {
                      iVar4 = in_ECX[0xe2];
                    }
                    else {
                      iVar4 = in_ECX[0xe1];
                    }
                    if (iVar4 == 0) {
                      iVar4 = FUN_007c2511();
                      uVar7 = FUN_0079efbc(iVar4 + 0x13c);
                      FUN_00566800(&local_ec,iVar3 + 8);
                      FUN_0079efbc(uVar7);
                      local_a0 = local_e8;
                      if ((int)local_e8 <= in_ECX[0xfe]) {
                        local_a0 = (RECT *)in_ECX[0xfe];
                      }
                      if ((*(int *)(iVar3 + 0x3c) != 0) && ((int)local_a0 < 0xb)) {
                        local_a0 = (RECT *)0xa;
                      }
                      pRVar8 = local_a0;
                      if (param_1 == 0) {
                        local_11c = local_9c + local_90.left;
                        local_114 = (undefined1 *)
                                    ((int)&local_a4->left +
                                    local_90.left + local_9c + in_ECX[0xfd] + local_ec);
                        local_110 = local_94 + (int)&local_a0->left;
                        local_118 = local_94;
                        *(int *)(iVar3 + 0xc) = local_11c;
                        *(CWnd **)(iVar3 + 0x10) = local_94;
                        *(undefined1 **)(iVar3 + 0x14) = local_114;
                        *(CWnd **)(iVar3 + 0x18) = local_110;
                        iVar3 = *(int *)(iVar3 + 0xc);
                        if (iVar3 <= local_90.right - local_9c) {
                          iVar3 = local_90.right - local_9c;
                        }
                        *(int *)(local_a8 + 0x14) = iVar3;
                      }
                    }
                    else {
                      local_24.left = local_90.left;
                      local_24.top = local_90.top;
                      local_24.right = local_90.right;
                      local_24.bottom = local_90.bottom;
                      InflateRect(&local_24,-local_9c,0);
                      pCStack_38 = local_94 + in_ECX[0xfe];
                      local_24.top = (LONG)local_94;
                      local_44 = (CWnd *)((int)&local_a4->left + in_ECX[0xfd] + local_24.left);
                      pCStack_40 = local_94;
                      iStack_3c = local_24.right;
                      local_24.bottom = (LONG)pCStack_38;
                      iVar3 = FUN_007c2511();
                      uVar7 = FUN_0079efbc(iVar3 + 0x13c);
                      pcVar1 = *(code **)(local_d4[0] + 0x68);
                      guard_check_icall(*(int *)(local_a8 + 8),
                                        *(undefined4 *)(*(int *)(local_a8 + 8) + -0xc),&local_44,
                                        0x410);
                      pRVar8 = (RECT *)(*pcVar1)();
                      local_a4 = pRVar8;
                      FUN_0079efbc(uVar7);
                      if ((*(int *)(local_a8 + 0x3c) != 0) && ((int)pRVar8 < 0xb)) {
                        pRVar8 = (RECT *)0xa;
                        local_a4 = (RECT *)0xa;
                      }
                      pRVar2 = (RECT *)in_ECX[0xfe];
                      if ((int)pRVar8 <= (int)pRVar2) {
                        pRVar8 = pRVar2;
                        local_a4 = pRVar2;
                      }
                      local_24.bottom = local_24.top + (int)pRVar8;
                      if (param_1 == 0) {
                        *(LONG *)(local_a8 + 0xc) = local_24.left;
                        *(LONG *)(local_a8 + 0x10) = local_24.top;
                        *(LONG *)(local_a8 + 0x14) = local_24.right;
                        *(LONG *)(local_a8 + 0x18) = local_24.bottom;
                        pRVar8 = local_a4;
                      }
                    }
                    iVar3 = in_ECX[0xf3];
                    if (iVar3 == -1) {
                      iVar3 = FUN_007c2574();
                      iVar3 = *(int *)(iVar3 + 0xa0);
                    }
                    local_9c = 0;
                    local_94 = local_94 + (int)((int)&pRVar8->left + iVar3);
                    local_a4 = (RECT *)0x0;
                    iVar3 = local_a8;
                  }
                }
                else {
                  if ((local_9c != 0) && (*(int *)(iVar3 + 0x34) != 0)) {
                    iVar4 = local_e0;
                    if ((in_ECX[0xdf] != 0) && (iVar4 = in_ECX[0xf3], iVar4 == -1)) {
                      iVar4 = FUN_007c2574();
                      iVar4 = *(int *)(iVar4 + 0xa0);
                      pHVar9 = *(HWND__ **)(iVar3 + 0x2c);
                    }
                    local_94 = pCVar12 + iVar4;
                  }
                  CWnd::FromHandle(pHVar9);
                  iVar4 = local_a8;
                  if (param_1 == 0) {
                    local_34.left = local_90.left;
                    local_34.right = local_90.right;
                    if (*(int *)(local_a8 + 0x34) == 0) {
                      iVar3 = 0;
                    }
                    else {
                      iVar3 = *(int *)(local_a8 + 0x20);
                    }
                    local_34.bottom = (LONG)(local_94 + iVar3);
                    local_34.top = (LONG)(in_ECX[0x112] + 1);
                    if (in_ECX[0x112] + 1 <= (int)local_94) {
                      local_34.top = (LONG)local_94;
                    }
                    local_bc = (CWnd *)(local_34.top + (*(int *)(local_a8 + 0x20) - local_34.bottom)
                                       );
                    if (in_ECX[0x114] < local_34.bottom) {
                      local_34.bottom = (LONG)in_ECX[0x114];
                    }
                    iVar3 = local_e4;
                    if ((in_ECX[0xdf] != 0) && (iVar3 = in_ECX[0xf1], in_ECX[0xf1] == -1)) {
                      iVar3 = FUN_007c2574();
                      iVar3 = *(int *)(iVar3 + 0x98);
                    }
                    InflateRect(&local_34,-iVar3,0);
                    local_a0 = (RECT *)(iVar4 + 0xc);
                    local_a0->left = local_34.left;
                    *(LONG *)(iVar4 + 0x10) = local_34.top;
                    *(LONG *)(iVar4 + 0x14) = local_34.right;
                    *(LONG *)(iVar4 + 0x18) = local_34.bottom;
                    pcVar1 = *(code **)(*in_ECX + 0x3c4);
                    guard_check_icall();
                    iVar4 = (*pcVar1)();
                    iVar3 = local_a8;
                    if (iVar4 != 0) {
                      BVar11 = IsRectEmpty(local_a0);
                      iVar3 = local_a8;
                      pcVar1 = *(code **)(*in_ECX + 0x3dc);
                      pCVar12 = local_bc;
                      if (BVar11 != 0) {
                        pCVar12 = (CWnd *)0x0;
                      }
                      guard_check_icall(*(undefined4 *)(local_a8 + 0x2c),pCVar12);
                      (*pcVar1)();
                    }
                  }
                  if (*(int *)(iVar3 + 0x34) == 0) goto LAB_008d73a1;
                  pCVar12 = local_94 + *(int *)(iVar3 + 0x20);
                  local_9c = 1;
                  local_a4 = (RECT *)0x1;
LAB_008d73d7:
                  if (in_ECX[0xdf] == 0) {
                    local_94 = pCVar12 + local_e0;
                  }
                  else {
                    iVar4 = in_ECX[0xf3];
                    if (iVar4 == -1) {
                      iVar4 = FUN_007c2574();
                      iVar4 = *(int *)(iVar4 + 0xa0);
                    }
                    local_94 = pCVar12 + iVar4;
                  }
                }
                if ((((param_1 == 0) && (in_ECX[0xde] != 0)) && (local_ac == in_ECX[0x151])) &&
                   (iVar4 = in_ECX[0x104], (int)(local_98 + iVar4) < (int)local_94)) {
                  if (iVar4 < 0) {
                    iVar4 = 0;
                  }
                  pCVar12 = local_98 + iVar4;
                  pRVar2 = *(RECT **)(iVar3 + 0x18);
                  pRVar8 = (RECT *)(pCVar12 + -1);
                  local_a0 = pRVar2;
                  if ((int)pRVar8 <= (int)pRVar2) {
                    local_a0 = pRVar8;
                  }
                  pRVar10 = *(RECT **)(iVar3 + 0x10);
                  if (((int)*(RECT **)(iVar3 + 0x10) <= (int)local_a0) &&
                     (pRVar10 = pRVar2, (int)pRVar8 <= (int)pRVar2)) {
                    pRVar10 = pRVar8;
                  }
                  *(RECT **)(iVar3 + 0x18) = pRVar10;
                  in_ECX[0xea] = (int)(local_94 + (in_ECX[0xea] - (int)pCVar12));
                  local_bc = local_94;
                  local_94 = pCVar12;
                }
                iVar3 = local_ac;
              } while (local_b4 != 0);
            }
            pCVar12 = local_94;
            if (param_1 == 0) {
              local_12c = local_90.left;
              local_128 = local_98;
              local_124 = local_90.right;
              *(LONG *)(iVar3 + 0x44) = local_90.left;
              *(CWnd **)(iVar3 + 0x48) = local_98;
              *(LONG *)(iVar3 + 0x4c) = local_90.right;
              *(CWnd **)(iVar3 + 0x50) = local_94;
              local_120 = local_94;
            }
          }
          else if (param_1 == 0) {
            local_108 = pCVar12 + -1;
            *(LONG *)(iVar3 + 0x44) = local_90.left;
            local_a0 = *(RECT **)(local_ac + 0x10);
            *(CWnd **)(iVar3 + 0x48) = local_108;
            *(LONG *)(iVar3 + 0x4c) = local_90.right;
            *(CWnd **)(iVar3 + 0x50) = local_108;
            local_100 = local_108;
            local_10c = local_90.left;
            local_104 = local_90.right;
            while (pCVar12 = local_94, local_a0 != (RECT *)0x0) {
              piVar5 = (int *)FUN_0044f2d0(&local_a0);
              if (*(int *)(*piVar5 + 0x2c) == 0) {
                SetRectEmpty((LPRECT)(*piVar5 + 0xc));
              }
            }
          }
          iVar3 = in_ECX[0xed];
          if (iVar3 == -1) {
            iVar3 = FUN_007c2574();
            iVar3 = *(int *)(iVar3 + 0x88);
          }
          pCVar12 = pCVar12 + iVar3;
          local_94 = pCVar12;
        }
      }
      local_b0 = 0;
      if (param_1 == 0) {
        local_98 = (CWnd *)in_ECX[0x122];
        local_b0 = 0;
        do {
          if (local_98 == (CWnd *)0x0) goto LAB_008d7794;
          piVar5 = (int *)FUN_0049ad10(&local_98);
          iVar3 = *piVar5;
        } while (*(int *)(iVar3 + 4) != local_b8);
        if (((*(int *)(iVar3 + 0x28) != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (in_ECX[0xe7] == 0))
        {
          local_98 = *(CWnd **)(iVar3 + 0x14);
          do {
            if (local_98 == (CWnd *)0x0) goto LAB_008d7794;
            piVar5 = (int *)FUN_0049ad10(&local_98);
          } while (*(int *)(*piVar5 + 0x34) == 0);
          iVar4 = local_90.bottom - *(int *)(iVar3 + 0x50);
          if (0 < iVar4) {
            local_98 = *(CWnd **)(iVar3 + 0x10);
            while (local_98 != (CWnd *)0x0) {
              piVar5 = (int *)FUN_0044f2d0(&local_98);
              in_ECX = local_d8;
              if (*(int *)(*piVar5 + 0x34) != 0) {
                OffsetRect((LPRECT)(*piVar5 + 0xc),0,iVar4);
                in_ECX = local_d8;
              }
            }
            OffsetRect((LPRECT)(iVar3 + 0x34),0,iVar4);
            OffsetRect((LPRECT)(iVar3 + 0x44),0,iVar4);
          }
        }
LAB_008d7794:
        local_b0 = in_ECX[0x121];
        iVar3 = local_b4;
        while (local_b4 = iVar3, local_b0 != 0) {
          piVar5 = (int *)FUN_0044f2d0(&local_b0);
          iVar4 = *piVar5;
          iVar3 = local_b4;
          if (*(int *)(iVar4 + 4) == local_b8) {
            if (((in_ECX[0xda] == 0) || (*(int *)(iVar4 + 0x30) == 0)) ||
               (*(int *)(*(int *)(iVar4 + 8) + -0xc) == 0)) {
              local_a0 = (RECT *)0x0;
            }
            else {
              local_a0 = (RECT *)0x1;
            }
            if (((in_ECX[0xde] == 0) || (iVar4 != in_ECX[0x151])) || (in_ECX[0x104] < 1)) {
              pCVar12 = (CWnd *)0x0;
            }
            else {
              pCVar12 = (CWnd *)0x1;
            }
            local_b4 = *(int *)(iVar4 + 0x10);
            iVar3 = 0;
            local_98 = pCVar12;
            if (local_b4 != 0) {
              local_c0 = iVar4 + 0xc;
              do {
                pRVar8 = local_a0;
                piVar5 = (int *)FUN_0044f2d0(&local_b4);
                iVar3 = *piVar5;
                if (*(int *)(iVar3 + 0x2c) != 0) {
                  local_98 = CWnd::FromHandle(*(HWND__ **)(iVar3 + 0x2c));
                  if (((pRVar8 == (RECT *)0x0) || (pCVar12 != (CWnd *)0x0)) &&
                     (*(int *)(iVar3 + 0x34) != 0)) {
                    pRVar8 = (RECT *)(iVar3 + 0xc);
                    BVar11 = IsRectEmpty(pRVar8);
                    if (BVar11 != 0) goto LAB_008d78aa;
                    FUN_00797e71(0,pRVar8->left,*(undefined4 *)(iVar3 + 0x10),
                                 *(int *)(iVar3 + 0x14) - pRVar8->left,
                                 *(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x10),0x14);
                    uVar7 = 4;
                  }
                  else {
LAB_008d78aa:
                    uVar7 = 0;
                  }
                  FUN_00797f20(uVar7);
                }
                in_ECX = local_d8;
                iVar3 = 0;
              } while (local_b4 != 0);
            }
          }
        }
      }
      FUN_0079efbc(local_dc);
      if (in_ECX[0xed] == -1) {
        FUN_007c2574();
      }
      if (in_ECX[0xeb] == -1) {
        FUN_007c2574();
      }
      FUN_0079dfff();
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCTasksPane[140] */
/* 008d79d8  FUN_008d79d8  384 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_008d79d8(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined8 uVar3;
  undefined1 local_ac [72];
  undefined1 local_64 [52];
  undefined4 local_30;
  int *local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x9c;
  local_8 = 0x8d79e7;
  FUN_008592c1(&local_20,L"MFCTasksPanes",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_18,L"%TsMFCTasksPane-%d",local_20,param_2);
  }
  else {
    FUN_004059f0(local_18,L"%TsMFCTasksPane-%d%x",local_20,param_2,param_3);
  }
  local_8._0_1_ = 2;
  FUN_007b57a7(0x400);
  local_8._0_1_ = 3;
  FUN_007a6256(local_64,0,0x1000,0);
  local_8._0_1_ = 4;
  pcVar1 = *(code **)(*in_ECX + 8);
  guard_check_icall(local_ac);
  (*pcVar1)();
  FUN_007a67a4();
  local_8._0_1_ = 3;
  FUN_007a6389();
  uVar3 = FUN_007b5a11();
  local_28 = (undefined4)((ulonglong)uVar3 >> 0x20);
  local_30 = (undefined4)uVar3;
  local_24 = FUN_007b592a();
  if (local_24 != 0) {
    local_2c = (int *)0x0;
    local_28 = 0;
    local_8._0_1_ = 5;
    local_1c = (int *)FUN_00859490(0,0);
    pcVar1 = *(code **)(*local_1c + 0xc);
    guard_check_icall(local_18[0]);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*local_1c + 0x28);
      guard_check_icall(L"Settings",local_24,local_30);
      (*pcVar1)();
    }
    FUN_008f43b0(local_24);
    if (local_2c != (int *)0x0) {
      pcVar1 = *(code **)(*local_2c + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  FUN_007b583b();
  FUN_008d7b6c();
  return;
}




/* vtable slots: CMFCTasksPane[2] */
/* 008d7ba3  FUN_008d7ba3  582 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008d7ba3(CArchive *param_1)

{
  int iVar1;
  int *piVar2;
  CSimpleStringT<wchar_t,0> *pCVar3;
  CMFCTasksPane *in_ECX;
  int iVar4;
  CStringArray local_44 [8];
  undefined4 local_3c;
  CStringArray local_30 [8];
  int local_28;
  undefined4 local_1c;
  int local_18;
  long local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x8d7baf;
  FUN_00890e53(param_1);
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3ac));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3b0));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3b4));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3b8));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3bc));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3c0));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3c4));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3c8));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x3cc));
    iVar4 = CMFCTasksPane::GetActivePage(in_ECX);
    CArchive::operator<<(param_1,iVar4);
    FUN_007bf4a7();
    local_18 = *(int *)(in_ECX + 0x468);
    local_8 = 1;
    while (local_18 != 0) {
      piVar2 = (int *)FUN_0044f2d0(&local_18);
      FUN_007bf724(local_3c,*piVar2 + 4);
    }
    CStringArray::Serialize(local_44,param_1);
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x49c));
  }
  else {
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3ac));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3b0));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3b4));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3b8));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3bc));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3c0));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3c4));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3c8));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x3cc));
    local_14[0] = 0;
    CArchive::operator>>(param_1,local_14);
    local_18 = local_14[0];
    if ((local_14[0] < 0) || (*(int *)(in_ECX + 0x470) <= local_14[0])) {
      local_18 = 0;
    }
    FUN_007bf4a7();
    local_8 = 0;
    CStringArray::Serialize(local_30,param_1);
    if (local_28 == *(int *)(in_ECX + 0x470)) {
      local_14[0] = *(long *)(in_ECX + 0x468);
      local_1c = 0;
      if (local_14[0] != 0) {
        iVar4 = 0;
        do {
          if (local_28 <= iVar4) break;
          piVar2 = (int *)FUN_0044f2d0(local_14);
          iVar1 = *piVar2;
          pCVar3 = (CSimpleStringT<wchar_t,0> *)FUN_0049a990(iVar4);
          iVar4 = iVar4 + 1;
          ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(iVar1 + 4),pCVar3)
          ;
        } while (local_14[0] != 0);
      }
    }
    CMFCTasksPane::SetActivePage(in_ECX,local_18);
    *(undefined4 *)(in_ECX + 0x398) = 0;
    FUN_008d3b09();
    FUN_0047fc90(in_ECX + 0x49c);
    FUN_008d838b();
  }
  FUN_007bf4be();
  return;
}




/* vtable slots: CMFCTasksPane[228] */
/* 008d7e99  FUN_008d7e99  185 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008d7e99(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00891212();
  iVar1 = FUN_0078e624(0x30);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_008aed24(0x17,1);
  }
  FUN_007b00e7(*(undefined4 *)(in_ECX + 0x33c),uVar2);
  iVar1 = FUN_0078e624(0x30);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_008aed24(0x18,1);
  }
  FUN_007b00e7(*(undefined4 *)(in_ECX + 0x33c),uVar2);
  iVar1 = FUN_0078e624(0x3c);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008b90ee(0x19,0);
  }
  *(undefined4 *)(iVar1 + 0x34) = 0;
  FUN_007b00e7(*(undefined4 *)(in_ECX + 0x33c),iVar1);
  return;
}




/* vtable slots: CMFCTasksPane[239] */
/* 008d8206  FUN_008d8206  42 bytes, 0 callers */

void FUN_008d8206(WPARAM param_1)

{
  CWnd *pCVar1;
  CWnd *in_ECX;
  
  pCVar1 = CWnd::GetOwner(in_ECX);
  if (param_1 == 0xffffffff) {
    param_1 = 0xe001;
  }
  SendMessageW(*(HWND *)(pCVar1 + 0x20),0x362,param_1,0);
  return;
}




/* vtable slots: CMFCTasksPane[227] */
/* 008d8230  FUN_008d8230  14 bytes, 0 callers */

void FUN_008d8230(void)

{
  CMFCCaptionButton *pCVar1;
  CDockablePane *in_ECX;
  
  if (*(int *)(in_ECX + 0x380) != 0) {
    return;
  }
  if (*(uint *)(in_ECX + 0x35c) != 0) {
    pCVar1 = CDockablePane::FindButtonByHit(in_ECX,*(uint *)(in_ECX + 0x35c));
    *(undefined4 *)(in_ECX + 0x35c) = 0;
    ReleaseCapture();
    if (pCVar1 != (CMFCCaptionButton *)0x0) {
      *(undefined4 *)(pCVar1 + 4) = 0;
      FUN_00890cc8(pCVar1);
    }
  }
  if (*(uint *)(in_ECX + 0x358) != 0) {
    pCVar1 = CDockablePane::FindButtonByHit(in_ECX,*(uint *)(in_ECX + 0x358));
    *(undefined4 *)(in_ECX + 0x358) = 0;
    ReleaseCapture();
    if (pCVar1 != (CMFCCaptionButton *)0x0) {
      *(undefined4 *)(pCVar1 + 8) = 0;
      FUN_00890cc8(pCVar1);
    }
  }
  *(undefined4 *)(in_ECX + 0x360) = 0;
  return;
}




/* vtable slots: CMFCTasksPane[240] */
/* 008d830b  FUN_008d830b  59 bytes, 0 callers */

void FUN_008d830b(void)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_008d838b();
  FUN_008d3b09();
  pcVar1 = *(code **)(*in_ECX + 0x3e0);
  guard_check_icall(0);
  (*pcVar1)();
  RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x105);
  return;
}



