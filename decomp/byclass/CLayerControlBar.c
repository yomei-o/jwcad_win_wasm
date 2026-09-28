/* CLayerControlBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CLayerControlBar[1] */
/* 005551c0  FUN_005551c0  68 bytes, 0 callers */

undefined4 FUN_005551c0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005543a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x210);
    }
  }
  return in_ECX;
}




/* vtable slots: CLayerControlBar[90] */
/* 005553c0  FUN_005553c0  695 bytes, 0 callers */

undefined4 * FUN_005553c0(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined1 local_a0 [8];
  undefined1 local_98 [8];
  undefined1 local_90 [8];
  undefined1 local_88 [8];
  undefined1 local_80 [8];
  undefined1 local_78 [8];
  undefined1 local_70 [8];
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined1 local_58 [8];
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_0041c8d0(200,0x1e);
  if ((param_3 & 0x10) == 0) {
    if ((param_3 & 8) == 0) {
      if ((param_3 & 0x40) == 0) {
        if ((param_3 & 4) == 0) {
          if ((param_3 & 2) != 0) {
            if ((param_3 & 0x20) == 0) {
              piVar3 = (int *)FUN_00555680(local_60,0x10);
              if (param_2 < *piVar3) {
                piVar3 = (int *)FUN_00555680(local_70,8);
                if (param_2 < *piVar3) {
                  piVar3 = (int *)FUN_00555680(local_80,4);
                  if (param_2 < *piVar3) {
                    piVar3 = (int *)FUN_00555680(local_90,2);
                    if (param_2 < *piVar3) {
                      puVar2 = (undefined4 *)FUN_00555680(local_a0,1);
                      local_10 = *puVar2;
                      local_c = puVar2[1];
                    }
                    else {
                      puVar2 = (undefined4 *)FUN_00555680(local_98,2);
                      local_10 = *puVar2;
                      local_c = puVar2[1];
                    }
                  }
                  else {
                    puVar2 = (undefined4 *)FUN_00555680(local_88,4);
                    local_10 = *puVar2;
                    local_c = puVar2[1];
                  }
                }
                else {
                  puVar2 = (undefined4 *)FUN_00555680(local_78,8);
                  local_10 = *puVar2;
                  local_c = puVar2[1];
                }
              }
              else {
                puVar2 = (undefined4 *)FUN_00555680(local_68,0x10);
                local_10 = *puVar2;
                local_c = puVar2[1];
              }
            }
            else {
              iVar1 = FUN_00555680(local_18,1);
              if (param_2 < *(int *)(iVar1 + 4)) {
                iVar1 = FUN_00555680(local_28,2);
                if (param_2 < *(int *)(iVar1 + 4)) {
                  iVar1 = FUN_00555680(local_38,4);
                  if (param_2 < *(int *)(iVar1 + 4)) {
                    iVar1 = FUN_00555680(local_48,8);
                    if (param_2 < *(int *)(iVar1 + 4)) {
                      puVar2 = (undefined4 *)FUN_00555680(local_58,0x10);
                      local_10 = *puVar2;
                      local_c = puVar2[1];
                    }
                    else {
                      puVar2 = (undefined4 *)FUN_00555680(local_50,8);
                      local_10 = *puVar2;
                      local_c = puVar2[1];
                    }
                  }
                  else {
                    puVar2 = (undefined4 *)FUN_00555680(local_40,4);
                    local_10 = *puVar2;
                    local_c = puVar2[1];
                  }
                }
                else {
                  puVar2 = (undefined4 *)FUN_00555680(local_30,2);
                  local_10 = *puVar2;
                  local_c = puVar2[1];
                }
              }
              else {
                puVar2 = (undefined4 *)FUN_00555680(local_20,1);
                local_10 = *puVar2;
                local_c = puVar2[1];
              }
            }
          }
        }
        else {
          local_10 = *(undefined4 *)(local_8 + 0x1b8);
          local_c = *(undefined4 *)(local_8 + 0x1bc);
        }
      }
      else {
        local_10 = *(undefined4 *)(local_8 + 0x1b8);
        local_c = *(undefined4 *)(local_8 + 0x1bc);
      }
    }
    else {
      local_10 = *(undefined4 *)(local_8 + 0x1b8);
      local_c = *(undefined4 *)(local_8 + 0x1bc);
    }
  }
  else {
    local_10 = *(undefined4 *)(local_8 + 0x1b8);
    local_c = *(undefined4 *)(local_8 + 0x1bc);
  }
  *(undefined4 *)(local_8 + 0x1b8) = local_10;
  *(undefined4 *)(local_8 + 0x1bc) = local_c;
  *param_1 = local_10;
  param_1[1] = local_c;
  return param_1;
}




/* vtable slots: CLayerControlBar[10] */
/* 00555b20  FUN_00555b20  16 bytes, 0 callers */

void FUN_00555b20(void)

{
  FUN_00555b60();
  return;
}




/* vtable slots: CLayerControlBar[67] */
/* 005578d0  FUN_005578d0  85 bytes, 0 callers */

void FUN_005578d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00555b30();
  if (((iVar1 != 0) && (0x1ff < *(uint *)(param_1 + 4))) && (*(uint *)(param_1 + 4) < 0x20f)) {
    FUN_00557930(param_1);
  }
  FUN_007ad0e6(param_1);
  return;
}




/* vtable slots: CLayerControlBar[89], CMyCtrlBar[89], CMyToolBar[89], CSenCollControlBar[89], CSenCollControlBar2[89], CToolBar[89] */
/* 007ad9f4  CalcFixedLayout  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CSize __thiscall CToolBar::CalcFixedLayout(int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CToolBar::CalcFixedLayout(CToolBar *this,int param_1,int param_2)

{
  int in_stack_0000000c;
  
  FUN_007ada1d(param_1,param_2 != 0 | -(in_stack_0000000c != 0) & 2U,0xffffffff);
  return param_1;
}




/* vtable slots: CLayerControlBar[105], CMyCtrlBar[105], CMyToolBar[105], CSenCollControlBar[105], CSenCollControlBar2[105], CToolBar[105] */
/* 007adf96  FUN_007adf96  101 bytes, 0 callers */

void FUN_007adf96(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall(param_1,0,param_2,in_ECX[0x22],in_ECX[0x24],in_ECX[0x23],in_ECX[0x25],param_3);
  (*pcVar1)();
  return;
}




/* vtable slots: CLayerControlBar[106], CMyCtrlBar[106], CMyToolBar[106], CSenCollControlBar[106], CSenCollControlBar2[106], CToolBar[106] */
/* 007adffb  FUN_007adffb  214 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_007adffb(undefined4 param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  int iVar1;
  CControlBar *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  CControlBar::SetBorders(in_ECX,param_4,param_5,param_6,param_7);
  *(uint *)(in_ECX + 0xb0) = param_3 & 0x40ffff;
  if (param_8 == 0xe800) {
    *(uint *)(in_ECX + 0xb0) = param_3 & 0x40ffff | 8;
  }
  FUN_00790c5e(0x1000);
  FUN_007aef28();
  _AfxGetDropDownWidth();
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  iVar1 = FUN_00791f4f(L"ToolbarWindow32",0,param_3 & 0xffbf004e | param_2 | 0x4e,&local_18,param_1,
                       param_8,0);
  if (iVar1 != 0) {
    FUN_007aec2b(*(undefined4 *)(in_ECX + 0xe0),*(undefined4 *)(in_ECX + 0xe4),
                 *(undefined4 *)(in_ECX + 0xd8),*(undefined4 *)(in_ECX + 0xdc));
  }
  return iVar1 != 0;
}




/* vtable slots: CLayerControlBar[107], CMyCtrlBar[107], CMyToolBar[107], CSenCollControlBar[107], CSenCollControlBar2[107], CToolBar[107] */
/* 007ae19b  FUN_007ae19b  71 bytes, 0 callers */

void FUN_007ae19b(undefined4 param_1,LPRECT param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0x35] != 0) {
    FUN_007ae1ee();
  }
  pcVar1 = *(code **)(*in_ECX + 0x11c);
  guard_check_icall(0x41d,param_1,param_2);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    SetRectEmpty(param_2);
  }
  return;
}




/* vtable slots: CLayerControlBar[0], CMyCtrlBar[0], CMyToolBar[0], CSenCollControlBar[0], CSenCollControlBar2[0], CToolBar[0] */
/* 007ae1e8  FUN_007ae1e8  6 bytes, 0 callers */

undefined ** FUN_007ae1e8(void)

{
  return &PTR_s_CToolBar_0097fbd4;
}




/* vtable slots: CLayerControlBar[103], CMyCtrlBar[103], CMyToolBar[103], CSenCollControlBar[103], CSenCollControlBar2[103], CToolBar[103] */
/* 007ae369  OnBarStyleChange  55 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CToolBar::OnBarStyleChange(unsigned long,unsigned long)
   
   Library: Visual Studio 2015 Release */

void __thiscall CToolBar::OnBarStyleChange(CToolBar *this,ulong param_1,ulong param_2)

{
  if ((*(int *)(this + 0x20) != 0) && (((param_1 ^ param_2) & 0xf00) != 0)) {
    FUN_00797e71(0,0,0,0,0,0x33);
  }
  *(undefined4 *)(this + 0xd4) = 1;
  return;
}




/* vtable slots: CLayerControlBar[29], CMyCtrlBar[29], CMyToolBar[29], CSenCollControlBar[29], CSenCollControlBar2[29], CToolBar[29] */
/* 007ae73f  FUN_007ae73f  289 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_007ae73f(LONG param_1,LONG param_2,uint *param_3)

{
  code *pcVar1;
  POINT pt;
  uint uVar2;
  int iVar3;
  int iVar4;
  BOOL BVar5;
  int *in_ECX;
  int iVar6;
  undefined1 local_40 [4];
  uint local_3c;
  undefined1 local_2c [9];
  byte local_23;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_00793db2(param_1,param_2,param_3);
  if (uVar2 == 0xffffffff) {
    pcVar1 = *(code **)(*in_ECX + 0x11c);
    guard_check_icall(0x418,0,0);
    iVar3 = (*pcVar1)();
    iVar6 = 0;
    if (0 < iVar3) {
      do {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        pcVar1 = *(code **)(*in_ECX + 0x11c);
        local_18.bottom = 0;
        guard_check_icall(0x41d,iVar6,&local_18);
        iVar4 = (*pcVar1)();
        if (iVar4 != 0) {
          local_18.bottom = local_18.bottom + 1;
          local_18.right = local_18.right + 1;
          pt.y = param_2;
          pt.x = param_1;
          BVar5 = PtInRect(&local_18,pt);
          if (BVar5 != 0) {
            pcVar1 = *(code **)(*in_ECX + 0x11c);
            guard_check_icall(0x417,iVar6,local_2c);
            iVar4 = (*pcVar1)();
            if ((iVar4 != 0) && ((local_23 & 1) == 0)) {
              FUN_007aefe6(iVar6,local_40);
              if ((param_3 != (uint *)0x0) && (0x2b < *param_3)) {
                uVar2 = in_ECX[8];
                param_3[9] = 0xffffffff;
                param_3[4] = local_18.left;
                param_3[2] = uVar2;
                param_3[3] = local_3c;
                param_3[5] = local_18.top;
                param_3[6] = local_18.right;
                param_3[7] = local_18.bottom;
              }
              if (local_3c != 0) {
                return local_3c;
              }
              return 0xffffffff;
            }
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar3);
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}




/* vtable slots: CLayerControlBar[91], CMyCtrlBar[91], CMyToolBar[91], CSenCollControlBar[91], CSenCollControlBar2[91], CToolBar[91] */
/* 007ae860  FUN_007ae860  204 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007ae860(CCmdTarget *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  CWnd *in_ECX;
  undefined **local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_24;
  undefined1 local_1c [4];
  undefined4 local_18;
  byte local_13;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  CCmdUI::CCmdUI((CCmdUI *)&local_44);
  pcVar1 = *(code **)(*(int *)in_ECX + 0x11c);
  local_44 = CToolCmdUI::vftable;
  guard_check_icall(0x418,0,0);
  local_24 = (*pcVar1)();
  local_3c = 0;
  if (local_24 != 0) {
    do {
      FUN_007aefe6(local_3c,local_1c);
      local_40 = local_18;
      if ((local_13 & 1) == 0) {
        iVar2 = FUN_007900e9(0,0xbd11ffff,&local_44,0);
        if (iVar2 == 0) {
          iVar2 = FUN_007900e9(local_40,0xffffffff,&local_44,0);
          if (iVar2 == 0) {
            FUN_0078ff63(param_1,param_2);
          }
        }
      }
      local_3c = local_3c + 1;
    } while (local_3c < local_24);
  }
  CWnd::UpdateDialogControls(in_ECX,param_1,param_2);
  return;
}




/* vtable slots: CLayerControlBar[41], CMyCtrlBar[41], CMyToolBar[41], CSenCollControlBar[41], CSenCollControlBar2[41], CToolBar[41] */
/* 007af1af  FUN_007af1af  273 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_007af1af(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  BSTR pOVar1;
  int iVar2;
  undefined4 uVar3;
  UINT in_stack_ffffffcc;
  LPSTR in_stack_ffffffd0;
  int in_stack_ffffffd4;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  HINSTANCE local_1c;
  wchar_t *local_18;
  OLECHAR *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x7af1bb;
  if (param_3 == 0) {
    CStringT<>();
    local_8 = 0;
    FUN_00792c64(local_14);
    pOVar1 = SysAllocStringLen(local_14[0],*(UINT *)(local_14[0] + -6));
    if (pOVar1 == (BSTR)0x0) {
LAB_007af2bb:
                    /* WARNING: Subroutine does not return */
      FUN_00407010();
    }
    *param_5 = pOVar1;
  }
  else {
    CStringT<>();
    local_8 = 1;
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_007ae112(param_3 + -1,&local_1c,local_24,local_20);
    iVar2 = FID_conflict_LoadStringA(local_1c,in_stack_ffffffcc,in_stack_ffffffd0,in_stack_ffffffd4)
    ;
    if (iVar2 == 0) {
      FUN_00406b10();
      local_8 = 0xffffffff;
      FUN_00406b10();
      uVar3 = FUN_00796ab1(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
    AfxExtractSubString((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                        local_14,local_18,1,L'\n');
    pOVar1 = SysAllocStringLen(local_14[0],*(UINT *)(local_14[0] + -6));
    if (pOVar1 == (BSTR)0x0) goto LAB_007af2bb;
    *param_5 = pOVar1;
    FUN_00406b10();
  }
  FUN_00406b10();
  return 0;
}



