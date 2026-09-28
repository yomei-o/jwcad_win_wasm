/* CMFCRibbonMainPanel -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonMainPanel[52], CMFCRibbonPanel[52] */
/* 0086a374  FUN_0086a374  33 bytes, 0 callers */

void FUN_0086a374(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xd8);
  guard_check_icall(in_ECX[0x139]);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonMainPanel[56], CMFCRibbonPanel[56] */
/* 0086b566  FUN_0086b566  402 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0086b566(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined1 local_58 [4];
  int local_54;
  undefined1 local_50 [4];
  int *local_4c;
  int local_48;
  tagTEXTMETRICW local_44;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_48 = param_1;
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2e0) + 0x180);
  guard_check_icall(param_1);
  (*pcVar1)();
  iVar4 = 0;
  local_54 = 0;
  if (*(int *)(in_ECX + 0x108) != 0) {
    GetTextMetricsW(*(HDC *)(local_48 + 8),&local_44);
    iVar2 = FUN_008721a4(local_58,0);
    if (local_44.tmHeight < *(int *)(iVar2 + 4)) {
      iVar2 = FUN_008721a4(local_50,0);
      local_44.tmHeight = *(int *)(iVar2 + 4);
    }
    local_54 = local_44.tmHeight + 6;
  }
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2e0) + 0xf8);
  local_54 = local_54 * 3;
  guard_check_icall(local_50,local_48);
  iVar2 = (*pcVar1)();
  if (local_54 <= *(int *)(iVar2 + 4)) {
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x2e0) + 0xf8);
    guard_check_icall(local_60,local_48);
    iVar2 = (*pcVar1)();
    local_54 = *(int *)(iVar2 + 4);
  }
  if (0 < *(int *)(in_ECX + 0x4e4)) {
    do {
      puVar3 = (undefined4 *)FUN_00799cf8(iVar4);
      local_4c = (int *)*puVar3;
      pcVar1 = *(code **)(*local_4c + 0x180);
      guard_check_icall(local_48);
      (*pcVar1)();
      pcVar1 = *(code **)(*local_4c + 0xf8);
      guard_check_icall(local_60,local_48);
      iVar2 = (*pcVar1)();
      if (local_54 <= *(int *)(iVar2 + 4)) {
        pcVar1 = *(code **)(*local_4c + 0xf8);
        guard_check_icall(local_68,local_48);
        iVar2 = (*pcVar1)();
        local_54 = *(int *)(iVar2 + 4);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x4e4));
  }
  return *(int *)(in_ECX + 0xb4) * 2 + 3 + local_54;
}




/* vtable slots: CMFCRibbonMainPanel[48], CMFCRibbonPanel[48] */
/* 0086b79c  FUN_0086b79c  60 bytes, 0 callers */

int FUN_0086b79c(int param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(in_ECX + 0x4e4)) {
    do {
      piVar1 = (int *)FUN_00799cf8(iVar2);
      if (*piVar1 == param_1) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(in_ECX + 0x4e4));
  }
  return -1;
}




/* vtable slots: CMFCRibbonMainPanel[41], CMFCRibbonPanel[41] */
/* 0086bc83  FUN_0086bc83  32 bytes, 0 callers */

int FUN_0086bc83(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = 0;
  if (*(int *)(in_ECX + 0x10c) != 0) {
    return *(int *)(in_ECX + 0x10c);
  }
  if (*(int *)(in_ECX + 0x108) != 0) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x108) + 0x53c);
  }
  return iVar1;
}




/* vtable slots: CMFCRibbonMainPanel[69], CMFCRibbonPanel[69] */
/* 0086bebe  FUN_0086bebe  724 bytes, 0 callers */

void FUN_0086bebe(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int *in_ECX;
  int local_c;
  int *local_8;
  
  iVar1 = in_ECX[0x1a];
  in_ECX[0x1a] = param_1;
  if (param_1 == 0) {
    in_ECX[0x28] = 0;
    local_c = 0;
    local_8 = (int *)0x0;
  }
  else {
    local_c = in_ECX[0x28];
    pcVar2 = *(code **)(*in_ECX + 0xb8);
    guard_check_icall(param_2,param_3,0);
    local_8 = (int *)(*pcVar2)();
    if (local_8 != (int *)0x0) {
      if (local_c != 0) {
        pcVar2 = *(code **)(*local_8 + 0xd8);
        guard_check_icall();
        iVar5 = (*pcVar2)();
        if (iVar5 == 0) goto LAB_0086bf65;
      }
      pcVar2 = *(code **)(*local_8 + 0x218);
      guard_check_icall(param_2,param_3);
      (*pcVar2)();
    }
  }
LAB_0086bf65:
  bVar3 = false;
  bVar4 = false;
  if (local_8 != (int *)in_ECX[0xb7]) {
    if (((in_ECX[0x42] != 0) && (*(int *)(in_ECX[0x42] + 0x53c) != 0)) && (local_8 != (int *)0x0)) {
      FUN_008b3ecf();
    }
    if (in_ECX[0x43] != 0) {
      FUN_008b8e7b();
    }
    if (in_ECX[0xb7] != 0) {
      *(undefined4 *)(in_ECX[0xb7] + 200) = 0;
      pcVar2 = *(code **)(*(int *)in_ECX[0xb7] + 0x220);
      guard_check_icall(0);
      (*pcVar2)();
      if ((in_ECX[0x1e] != 0) && (*(int *)(in_ECX[0xb7] + 0xcc) != 0)) {
        *(undefined4 *)(in_ECX[0xb7] + 0xcc) = 0;
        bVar4 = true;
        pcVar2 = *(code **)(*(int *)in_ECX[0xb7] + 0x224);
        guard_check_icall(0);
        (*pcVar2)();
      }
      pcVar2 = *(code **)(*in_ECX + 0x108);
      guard_check_icall(in_ECX[0xb7]);
      (*pcVar2)();
      in_ECX[0xb7] = 0;
    }
    bVar3 = true;
  }
  if (local_8 != (int *)0x0) {
    if ((in_ECX[0x1e] == 0) && (local_c != 0)) {
      pcVar2 = *(code **)(*local_8 + 0xd8);
      guard_check_icall();
      iVar5 = (*pcVar2)();
      if (iVar5 == 0) goto LAB_0086c0ed;
    }
    in_ECX[0xb7] = (int)local_8;
    if (local_8[0x32] == 0) {
      pcVar2 = *(code **)(*local_8 + 0x220);
      guard_check_icall(1);
      (*pcVar2)();
      *(undefined4 *)(in_ECX[0xb7] + 200) = 1;
      if (bVar4) {
        *(undefined4 *)(in_ECX[0xb7] + 0xcc) = 1;
        pcVar2 = *(code **)(*(int *)in_ECX[0xb7] + 0x224);
        guard_check_icall(1);
        (*pcVar2)();
      }
      pcVar2 = *(code **)(*in_ECX + 0x108);
      guard_check_icall(in_ECX[0xb7]);
      (*pcVar2)();
    }
  }
LAB_0086c0ed:
  if ((iVar1 != param_1) && (in_ECX[0x42] != 0)) {
    pcVar2 = *(code **)(*in_ECX + 0xa4);
    guard_check_icall();
    iVar5 = (*pcVar2)();
    if (iVar5 != 0) {
      pcVar2 = *(code **)(*in_ECX + 0xa4);
      guard_check_icall();
      iVar5 = (*pcVar2)();
      RedrawWindow(*(HWND *)(iVar5 + 0x20),(RECT *)(in_ECX + 0x33),(HRGN)0x0,0x105);
    }
  }
  if ((in_ECX[0x20] != 0) && (iVar1 != param_1)) {
    FUN_008b9055(in_ECX[0x1a]);
  }
  if ((bVar3) && ((int *)in_ECX[0x43] != (int *)0x0)) {
    pcVar2 = *(code **)(*(int *)in_ECX[0x43] + 0x454);
    guard_check_icall(in_ECX[0xb7]);
    (*pcVar2)();
  }
  return;
}




/* vtable slots: CMFCRibbonMainPanel[46], CMFCRibbonPanel[46] */
/* 0086c192  FUN_0086c192  234 bytes, 0 callers */

int FUN_0086c192(LONG param_1,LONG param_2,int param_3)

{
  code *pcVar1;
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  BOOL BVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x354));
  if ((BVar2 != 0) ||
     (pt.y = param_2, pt.x = param_1, BVar2 = PtInRect((RECT *)(in_ECX + 0x354),pt), BVar2 == 0)) {
    BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x188));
    if ((BVar2 == 0) &&
       (pt_00.y = param_2, pt_00.x = param_1, BVar2 = PtInRect((RECT *)(in_ECX + 0x188),pt_00),
       BVar2 != 0)) {
      return in_ECX + 0x114;
    }
    iVar4 = 0;
    if (0 < *(int *)(in_ECX + 0x4e4)) {
      do {
        piVar3 = (int *)FUN_00799cf8(iVar4);
        piVar3 = (int *)*piVar3;
        BVar2 = IsRectEmpty((RECT *)(piVar3 + 0x1d));
        if ((BVar2 == 0) &&
           (pt_01.y = param_2, pt_01.x = param_1, BVar2 = PtInRect((RECT *)(piVar3 + 0x1d),pt_01),
           BVar2 != 0)) {
          pcVar1 = *(code **)(*piVar3 + 300);
          guard_check_icall(param_1,param_2);
          iVar4 = (*pcVar1)();
          return iVar4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(in_ECX + 0x4e4));
    }
    if ((param_3 == 0) ||
       (pt_02.y = param_2, pt_02.x = param_1, BVar2 = PtInRect((RECT *)(in_ECX + 0xbc),pt_02),
       BVar2 == 0)) {
      return 0;
    }
  }
  return in_ECX + 0x2e0;
}




/* vtable slots: CMFCRibbonMainPanel[47], CMFCRibbonPanel[47] */
/* 0086c27c  HitTestEx  88 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCRibbonPanel::HitTestEx(class CPoint)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCRibbonPanel::HitTestEx(CMFCRibbonPanel *this,LONG param_2,LONG param_3)

{
  int iVar1;
  POINT pt;
  int *piVar2;
  BOOL BVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(this + 0x4e4)) {
    do {
      piVar2 = (int *)FUN_00799cf8(iVar4);
      iVar1 = *piVar2;
      BVar3 = IsRectEmpty((RECT *)(iVar1 + 0x74));
      if ((BVar3 == 0) &&
         (pt.y = param_3, pt.x = param_2, BVar3 = PtInRect((RECT *)(iVar1 + 0x74),pt), BVar3 != 0))
      {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(this + 0x4e4));
  }
  return -1;
}




/* vtable slots: CMFCRibbonMainPanel[53], CMFCRibbonPanel[53] */
/* 0086c2d4  FUN_0086c2d4  234 bytes, 0 callers */

undefined4 FUN_0086c2d4(int *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  if (param_2 == -1) {
    param_2 = *(int *)(in_ECX + 0x4e4);
  }
  if ((param_2 < 0) || (*(int *)(in_ECX + 0x4e4) < param_2)) {
    uVar5 = 0;
  }
  else {
    pcVar1 = *(code **)(*param_1 + 0x164);
    guard_check_icall(*(undefined4 *)(in_ECX + 0x108));
    (*pcVar1)();
    pcVar1 = *(code **)(*param_1 + 0x194);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (((iVar2 == 0) && (*(int *)(in_ECX + 0x70) != 0)) && (0 < *(int *)(in_ECX + 0x4e4))) {
      iVar2 = 0;
      do {
        puVar3 = (undefined4 *)FUN_00799cf8(iVar2);
        pcVar1 = *(code **)(*(int *)*puVar3 + 0x194);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 == 0) {
          *(undefined4 *)(in_ECX + 0x70) = 0;
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(in_ECX + 0x4e4));
    }
    if (param_2 == *(int *)(in_ECX + 0x4e4)) {
      FUN_0079c90d(*(undefined4 *)(in_ECX + 0x4e4),param_1);
    }
    else {
      FUN_00867e50(param_2,param_1,1);
    }
    uVar5 = 1;
  }
  return uVar5;
}




/* vtable slots: CMFCRibbonMainPanel[54], CMFCRibbonPanel[54] */
/* 0086c3be  FUN_0086c3be  131 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0086c3be(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  
  if ((param_1 < 0) || (*(int *)(in_ECX + 0x4e4) < param_1)) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_0078e624(0x110);
    iVar3 = 0;
    if (iVar1 != 0) {
      iVar3 = FUN_00862fba(0);
    }
    *(undefined4 *)(iVar3 + 0x88) = *(undefined4 *)(in_ECX + 0x108);
    if (param_1 == *(int *)(in_ECX + 0x4e4)) {
      FUN_0079c90d(*(undefined4 *)(in_ECX + 0x4e4),iVar3);
    }
    else {
      FUN_00867e50(param_1,iVar3,1);
    }
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonMainPanel[71], CMFCRibbonPanel[71] */
/* 0086c6fa  FUN_0086c6fa  188 bytes, 0 callers */

void FUN_0086c6fa(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  BOOL BVar5;
  int *in_ECX;
  HWND local_8;
  
  in_ECX[0x28] = 0;
  if (in_ECX[0xb7] != 0) {
    pcVar1 = *(code **)(*in_ECX + 0xa4);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      local_8 = (HWND)0x0;
    }
    else {
      local_8 = *(HWND *)(iVar4 + 0x20);
    }
    piVar2 = (int *)in_ECX[0xb7];
    pcVar1 = *(code **)(*piVar2 + 0x214);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    BVar5 = IsWindow(local_8);
    if ((BVar5 != 0) && (piVar2[0x34] != 0)) {
      piVar2[0x34] = 0;
      pcVar1 = *(code **)(*in_ECX + 0x108);
      guard_check_icall(piVar2);
      (*pcVar1)();
      piVar3 = (int *)in_ECX[0xb7];
      if ((piVar3 != (int *)0x0) && (piVar3 != piVar2)) {
        pcVar1 = *(code **)(*in_ECX + 0x108);
        guard_check_icall(piVar3);
        (*pcVar1)();
      }
    }
  }
  return;
}




/* vtable slots: CMFCRibbonMainPanel[63], CMFCRibbonPanel[63] */
/* 0086c7b6  FUN_0086c7b6  106 bytes, 0 callers */

undefined4 FUN_0086c7b6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x4e4)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x22c);
      guard_check_icall(param_1,param_2,param_3,param_4);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x4e4));
  }
  return 0;
}




/* vtable slots: CMFCRibbonMainPanel[64], CMFCRibbonPanel[64] */
/* 0086c820  FUN_0086c820  294 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0086c820(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  BOOL BVar3;
  int in_ECX;
  int local_20;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = 0;
  if (0 < *(int *)(in_ECX + 0x4e4)) {
    do {
      piVar2 = (int *)FUN_00799cf8(local_20);
      piVar2 = (int *)*piVar2;
      local_18.left = piVar2[0x1d];
      pcVar1 = *(code **)(*piVar2 + 0x128);
      local_18.top = piVar2[0x1e];
      local_18.right = piVar2[0x1f];
      local_18.bottom = piVar2[0x20];
      BVar3 = IsRectEmpty(&local_18);
      guard_check_icall(BVar3 == 0);
      (*pcVar1)();
      pcVar1 = *(code **)(*piVar2 + 0x124);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_20 = local_20 + 1;
    } while (local_20 < *(int *)(in_ECX + 0x4e4));
  }
  local_18.left = *(LONG *)(in_ECX + 0x354);
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2e0) + 0x128);
  local_18.top = *(LONG *)(in_ECX + 0x358);
  local_18.right = *(LONG *)(in_ECX + 0x35c);
  local_18.bottom = *(LONG *)(in_ECX + 0x360);
  BVar3 = IsRectEmpty(&local_18);
  guard_check_icall(BVar3 == 0);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2e0) + 0x124);
  guard_check_icall(param_1);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x114) + 0x124);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonMainPanel[55], CMFCRibbonPanel[55] */
/* 0086cfe0  FUN_0086cfe0  2570 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0086cfe0(uint param_1)

{
  code *pcVar1;
  uint uVar2;
  CMFCRibbonPanel *pCVar3;
  LONG LVar4;
  ushort uVar5;
  int iVar6;
  CObject *pCVar7;
  undefined4 *puVar8;
  int iVar9;
  HWND pHVar10;
  CWnd *pCVar11;
  BOOL BVar12;
  CMFCRibbonPanel *in_ECX;
  undefined **local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  CObject *local_50;
  HWND local_4c;
  CObject *local_48;
  uint local_44;
  int *local_40;
  CMFCRibbonPanel *local_3c;
  CObject *local_38;
  tagRECT local_34;
  undefined1 local_24 [12];
  CObject *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x86cfec;
  local_44 = param_1;
  if (*(int *)(in_ECX + 0x4e4) == 0) goto LAB_0086d9e2;
  local_4c = *(HWND *)(in_ECX + 0x2dc);
  local_3c = in_ECX;
  if (local_4c != (HWND)0x0) {
    pcVar1 = *(code **)(local_4c->unused + 0x244);
    guard_check_icall(param_1);
    iVar6 = (*pcVar1)();
    if (iVar6 != 0) goto LAB_0086d9e2;
  }
  uVar2 = local_44;
  pCVar7 = (CObject *)0x0;
  local_4c = (HWND)0x0;
  local_38 = (CObject *)0x0;
  if (0x24 < local_44) {
    if (local_44 == 0x25) {
LAB_0086d3bb:
      if (((*(int *)(in_ECX + 0x78) != 0) && (local_44 == 0x25)) && (*(int *)(in_ECX + 0x10c) != 0))
      {
        local_40 = *(int **)(in_ECX + 0x2dc);
        if (local_40 == (int *)0x0) {
LAB_0086d40a:
          local_40 = (int *)0x0;
        }
        else {
          pcVar1 = *(code **)(*local_40 + 0x204);
          guard_check_icall();
          iVar6 = (*pcVar1)();
          if (iVar6 == 0) goto LAB_0086d40a;
          local_40 = (int *)0x1;
        }
        pHVar10 = GetParent(*(HWND *)(*(int *)(in_ECX + 0x10c) + 0x20));
        pCVar11 = CWnd::FromHandle(pHVar10);
        AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar11);
        if ((local_40 == (int *)0x0) && (iVar6 = FUN_0081d529(), iVar6 != 0)) {
          iVar6 = FUN_008b7533();
          if ((iVar6 != 0) && (*(CMFCRibbonPanel **)(iVar6 + 0x848) == in_ECX)) {
            FUN_008b425a(*(undefined4 *)(iVar6 + 0x844),1);
          }
          FUN_0081c095(0);
          goto LAB_0086d9e2;
        }
      }
    }
    else if (local_44 != 0x26) {
      if (local_44 == 0x27) {
        if ((*(int *)(in_ECX + 0x78) != 0) &&
           (local_40 = *(int **)(in_ECX + 0x2dc), local_40 != (int *)0x0)) {
          pcVar1 = *(code **)(*local_40 + 0x138);
          guard_check_icall();
          iVar6 = (*pcVar1)();
          if (iVar6 != 0) {
            pcVar1 = *(code **)(**(int **)(in_ECX + 0x2dc) + 0xe4);
            guard_check_icall();
            iVar6 = (*pcVar1)();
            in_ECX = local_3c;
            if (iVar6 == 0) {
              pcVar1 = *(code **)(**(int **)(local_3c + 0x2dc) + 0x13c);
              guard_check_icall();
              (*pcVar1)();
              if (*(int *)(*(int *)(local_3c + 0x2dc) + 0x9c) != 0) {
                SendMessageW(*(HWND *)(*(int *)(*(int *)(local_3c + 0x2dc) + 0x9c) + 0x20),0x100,
                             0x24,0);
              }
              goto LAB_0086d9e2;
            }
          }
        }
        goto LAB_0086d3bb;
      }
      if (local_44 != 0x28) goto LAB_0086d201;
    }
LAB_0086d47a:
    if (*(CObject **)(in_ECX + 0x2dc) == (CObject *)0x0) {
      if (((local_44 == 0x27) || (local_44 == 0x28)) || (local_44 == 9)) goto LAB_0086d07c;
LAB_0086d663:
      pCVar7 = (CObject *)FUN_0086b888();
      local_38 = pCVar7;
    }
    else {
      if ((((*(int *)(in_ECX + 0x110) != 0) &&
           (((local_44 == 0x28 || (local_44 == 0x26)) && (*(int *)(in_ECX + 0x10c) != 0)))) &&
          ((*(int *)(*(int *)(in_ECX + 0x10c) + 0x20) != 0 && (*(int *)(in_ECX + 0x104) != 0)))) &&
         ((*(int *)(*(int *)(in_ECX + 0x104) + 0x20) != 0 &&
          (pCVar7 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                       *(CObject **)(in_ECX + 0x2dc)), pCVar3 = local_3c,
          pCVar7 != (CObject *)0x0)))) {
        local_34.left = *(LONG *)(pCVar7 + 0x74);
        local_34.top = *(LONG *)(pCVar7 + 0x78);
        local_34.right = *(LONG *)(pCVar7 + 0x7c);
        local_34.bottom = *(LONG *)(pCVar7 + 0x80);
        CMFCRibbonPanel::GetGalleryRect(local_3c);
        LVar4 = local_34.top;
        if (local_44 == 0x28) {
          in_ECX = pCVar3;
          if ((int)local_18[0] < local_34.bottom) {
            iVar6 = GetScrollPos(*(HWND *)(*(int *)(pCVar3 + 0x104) + 0x20),2);
            iVar9 = FUN_00792a77(2);
            if (iVar6 < iVar9) {
              iVar6 = local_34.bottom - local_34.top;
              goto LAB_0086d565;
            }
          }
        }
        else {
          in_ECX = pCVar3;
          if ((local_34.top < (int)local_24._4_4_) &&
             (iVar6 = GetScrollPos(*(HWND *)(*(int *)(pCVar3 + 0x104) + 0x20),2), 0 < iVar6)) {
            iVar6 = -(local_34.bottom - LVar4);
LAB_0086d565:
            in_ECX = pCVar3;
            if (iVar6 != 0) {
              FUN_00870a41(iVar6,1);
              RedrawWindow(*(HWND *)(*(int *)(pCVar3 + 0x10c) + 0x20),(RECT *)local_24,(HRGN)0x0,
                           0x105);
              SetScrollPos(*(HWND *)(*(int *)(pCVar3 + 0x104) + 0x20),2,*(int *)(pCVar3 + 0xb8),1);
            }
          }
        }
      }
      local_60 = 0;
      local_54 = 0;
      local_58 = 0;
      local_5c = 0;
      local_64 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
      local_8 = 0;
      FUN_0086bdcc(&local_64);
      uVar2 = local_44;
      local_40 = (int *)0x0;
      local_38 = (CObject *)
                 FUN_008b2f04(local_44,&local_64,*(int *)(in_ECX + 0xcc),*(int *)(in_ECX + 0xd0),
                              *(int *)(in_ECX + 0xd4),*(int *)(in_ECX + 0xd8),
                              *(int *)(in_ECX + 0x2dc),0,0,&local_40);
      in_ECX = local_3c;
      if ((*(int *)(local_3c + 0x78) != 0) && (local_38 == (CObject *)0x0)) {
        if (uVar2 == 0x28) {
          local_38 = (CObject *)FUN_0086b332();
        }
        else {
          local_38 = (CObject *)FUN_0086b888();
        }
      }
      local_8 = 0xffffffff;
      local_64 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
      pCVar7 = local_38;
      if (local_60 != 0) {
        thunk_FUN_008f43b0(local_60);
        pCVar7 = local_38;
      }
    }
LAB_0086d086:
    if ((pCVar7 != (CObject *)0x0) &&
       (local_18[0] = *(CObject **)(in_ECX + 0x2dc), local_18[0] != pCVar7)) {
      if (local_18[0] != (CObject *)0x0) {
        if (*(int *)(local_18[0] + 200) != 0) {
          *(int *)(local_18[0] + 200) = 0;
          pcVar1 = *(code **)(**(int **)(in_ECX + 0x2dc) + 0x220);
          guard_check_icall(0);
          (*pcVar1)();
          local_18[0] = *(CObject **)(local_3c + 0x2dc);
          in_ECX = local_3c;
        }
        if (*(int *)(local_18[0] + 0xcc) != 0) {
          *(int *)(local_18[0] + 0xcc) = 0;
          pcVar1 = *(code **)(**(int **)(in_ECX + 0x2dc) + 0x224);
          guard_check_icall(0);
          (*pcVar1)();
          local_18[0] = *(CObject **)(local_3c + 0x2dc);
          in_ECX = local_3c;
        }
        pcVar1 = *(code **)(*(int *)local_18[0] + 0x1b8);
        guard_check_icall();
        (*pcVar1)();
        *(int *)(in_ECX + 0x2dc) = 0;
      }
      iVar6 = FUN_007c2511();
      if (((*(int *)(iVar6 + 0x19c) != 0) && (*(int *)(in_ECX + 0x10c) != 0)) &&
         (*(int *)(in_ECX + 0x78) != 0)) {
        local_24._0_4_ = *(undefined4 *)(local_38 + 0x74);
        local_24._4_4_ = *(undefined4 *)(local_38 + 0x78);
        local_24._8_4_ = local_24._0_4_;
        local_18[0] = (CObject *)local_24._4_4_;
        ClientToScreen(*(HWND *)(*(int *)(in_ECX + 0x10c) + 0x20),(LPPOINT)(local_24 + 8));
        pcVar1 = *(code **)(**(int **)(local_3c + 0x10c) + 0x254);
        guard_check_icall(CONCAT22(local_18[0]._0_2_,local_24._8_2_));
        (*pcVar1)();
        in_ECX = local_3c;
        pcVar1 = *(code **)(*(int *)local_3c + 0xc0);
        guard_check_icall(local_38);
        iVar6 = (*pcVar1)();
        if (*(int *)(in_ECX + 0x10c) == 0) {
          pHVar10 = (HWND)0x0;
        }
        else {
          pHVar10 = *(HWND *)(*(int *)(in_ECX + 0x10c) + 0x20);
        }
        NotifyWinEvent(0x8005,pHVar10,-4,iVar6 + 1);
      }
      *(CObject **)(in_ECX + 0x2dc) = local_38;
      pcVar1 = *(code **)(*(int *)local_38 + 0x220);
      guard_check_icall(1);
      (*pcVar1)();
      if (*(int *)(in_ECX + 0x110) != 0) {
        FUN_0086c512(local_38);
      }
      *(int *)(local_38 + 200) = 1;
      *(int *)(local_38 + 0xcc) = 1;
      pcVar1 = *(code **)(*(int *)local_38 + 0x224);
      guard_check_icall(1);
      (*pcVar1)();
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x2dc) + 0x1b8);
      guard_check_icall();
      (*pcVar1)();
      in_ECX = local_3c;
      if (*(int *)(local_3c + 0x10c) != 0) {
        pHVar10 = GetParent(*(HWND *)(*(int *)(local_3c + 0x10c) + 0x20));
        pCVar11 = CWnd::FromHandle(pHVar10);
        local_38 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenu_009a1ee8,
                                      (CObject *)pCVar11);
        pCVar3 = local_3c;
        if (local_38 != (CObject *)0x0) {
          if (*(int *)(local_38 + 0xf7c) != 0) {
            iVar6 = *(int *)(in_ECX + 0x2dc);
            local_24._0_4_ = *(int *)(iVar6 + 0x74);
            local_24._4_4_ = *(undefined4 *)(iVar6 + 0x78);
            local_24._8_4_ = *(int *)(iVar6 + 0x7c);
            local_18[0] = *(CObject **)(iVar6 + 0x80);
            local_34.left = 0;
            local_34.top = 0;
            local_34.right = 0;
            local_34.bottom = 0;
            GetClientRect(*(HWND *)(*(int *)(local_3c + 0x10c) + 0x20),&local_34);
            in_ECX = pCVar3;
            if (local_34.bottom < (int)local_18[0]) {
              pcVar1 = *(code **)(*(int *)local_38 + 0x1e8);
              guard_check_icall();
              iVar6 = (*pcVar1)();
              while (iVar6 != 0) {
                FUN_00820b8d(*(int *)(*(int *)(in_ECX + 0x10c) + 0xd4c) + 1);
                FUN_0081bc2d(0);
                iVar6 = *(int *)(in_ECX + 0x2dc);
                local_24._0_4_ = *(int *)(iVar6 + 0x74);
                local_24._4_4_ = *(int *)(iVar6 + 0x78);
                local_24._8_4_ = *(int *)(iVar6 + 0x7c);
                local_18[0] = *(CObject **)(iVar6 + 0x80);
                if ((int)local_18[0] <= local_34.bottom) goto LAB_0086d86a;
                pcVar1 = *(code **)(*(int *)local_38 + 0x1e8);
                guard_check_icall();
                iVar6 = (*pcVar1)();
                in_ECX = local_3c;
              }
            }
            else if ((int)local_24._4_4_ < local_34.top) {
              pcVar1 = *(code **)(*(int *)local_38 + 0x1e4);
              guard_check_icall();
              iVar6 = (*pcVar1)();
              while (iVar6 != 0) {
                FUN_00820b8d(*(int *)(*(int *)(in_ECX + 0x10c) + 0xd4c) + -1);
                FUN_0081bc2d(0);
                iVar6 = *(int *)(in_ECX + 0x2dc);
                local_24._0_4_ = *(int *)(iVar6 + 0x74);
                local_24._4_4_ = *(int *)(iVar6 + 0x78);
                local_24._8_4_ = *(int *)(iVar6 + 0x7c);
                local_18[0] = *(CObject **)(iVar6 + 0x80);
                if (local_34.top <= (int)local_24._4_4_) goto LAB_0086d86a;
                pcVar1 = *(code **)(*(int *)local_38 + 0x1e4);
                guard_check_icall();
                iVar6 = (*pcVar1)();
                in_ECX = local_3c;
              }
            }
          }
          goto LAB_0086d888;
        }
      }
    }
    goto LAB_0086d8b9;
  }
  if (local_44 == 0x24) {
    if (*(int *)(in_ECX + 0x78) == 0) goto LAB_0086d086;
LAB_0086d07c:
    pCVar7 = (CObject *)FUN_0086b332();
    local_38 = pCVar7;
    goto LAB_0086d086;
  }
  if (local_44 == 9) goto LAB_0086d47a;
  if ((local_44 != 0xd) && (local_44 != 0x20)) {
    if (local_44 == 0x23) {
      if (*(int *)(in_ECX + 0x78) == 0) goto LAB_0086d086;
      goto LAB_0086d663;
    }
LAB_0086d201:
    if (*(int *)(in_ECX + 0x78) != 0) {
      iVar6 = FUN_0082b24e(local_44);
      if (iVar6 != 0) {
        local_44 = FUN_0082b498(uVar2);
      }
      local_40 = (int *)0x0;
      pCVar7 = (CObject *)0x0;
      if (0 < *(int *)(in_ECX + 0x4e4)) {
        do {
          puVar8 = (undefined4 *)FUN_00799cf8(local_40);
          local_50 = (CObject *)*puVar8;
          pcVar1 = *(code **)(*(int *)local_50 + 0x1e4);
          guard_check_icall(local_44);
          iVar6 = (*pcVar1)();
          pCVar7 = local_50;
          if (iVar6 != 0) break;
          CStringT<>(*(int *)(local_50 + 0x60));
          local_8 = 1;
          iVar6 = FUN_0044e690(0x26,0);
          if ((-1 < iVar6) && (iVar6 < *(int *)(local_48 + -0xc) + -1)) {
            uVar5 = FUN_004473c0(iVar6 + 1);
            local_18[0] = (CObject *)(uint)uVar5;
            CharUpperW((LPWSTR)local_18);
            if (((uint)local_18[0] & 0xffff) == local_44) {
              pcVar1 = *(code **)(*(int *)pCVar7 + 0xdc);
              guard_check_icall();
              iVar6 = (*pcVar1)();
              if (iVar6 == 0) {
                local_38 = local_50;
                local_4c = (HWND)0x1;
              }
              local_8 = 0xffffffff;
              FUN_00406b10();
              pCVar7 = local_38;
              goto LAB_0086d086;
            }
          }
          local_8 = 0xffffffff;
          FUN_00406b10();
          local_40 = (int *)((int)local_40 + 1);
        } while ((int)local_40 < *(int *)(in_ECX + 0x4e4));
        goto LAB_0086d9e2;
      }
    }
    goto LAB_0086d086;
  }
  goto LAB_0086d8c3;
LAB_0086d86a:
  RedrawWindow(*(HWND *)(*(int *)(local_3c + 0x10c) + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
  in_ECX = local_3c;
LAB_0086d888:
  local_40 = *(int **)(local_38 + 0x116c);
  if (local_40 != (int *)0x0) {
    pcVar1 = *(code **)(*local_40 + 0x1fc);
    guard_check_icall(*(int *)(in_ECX + 0x10c),*(int *)(in_ECX + 0x2dc));
    (*pcVar1)();
  }
LAB_0086d8b9:
  if (local_4c == (HWND)0x0) goto LAB_0086d9e2;
LAB_0086d8c3:
  if ((*(CObject **)(in_ECX + 0x2dc) != (CObject *)0x0) &&
     (local_48 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButton_00998478,
                                    *(CObject **)(in_ECX + 0x2dc)), local_48 != (CObject *)0x0)) {
    pcVar1 = *(code **)(*(int *)local_48 + 0x138);
    guard_check_icall();
    iVar6 = (*pcVar1)();
    pCVar7 = local_48;
    if (iVar6 == 0) {
      pcVar1 = *(code **)(*(int *)local_48 + 0xdc);
      guard_check_icall();
      iVar6 = (*pcVar1)();
      if (iVar6 == 0) {
        local_4c = (HWND)FUN_008b7533();
        if ((local_4c != (HWND)0x0) && ((CMFCRibbonPanel *)local_4c[0x212].unused == in_ECX)) {
          FUN_008b2abe(1);
        }
        pcVar1 = *(code **)(*(int *)local_48 + 0x264);
        guard_check_icall(*(int *)(local_48 + 0x74),*(int *)(local_48 + 0x78));
        (*pcVar1)();
        if ((local_4c != (HWND)0x0) && (iVar6 = FUN_00792b4c(), iVar6 != 0)) {
          FUN_00792b4c();
          FUN_00797df8();
        }
      }
    }
    else {
      local_4c = (HWND)0x0;
      if (*(int *)(in_ECX + 0x10c) != 0) {
        local_4c = *(HWND *)(*(int *)(in_ECX + 0x10c) + 0x20);
      }
      pcVar1 = *(code **)(*(int *)local_48 + 0x13c);
      guard_check_icall();
      (*pcVar1)();
      if (((local_4c == (HWND)0x0) || (BVar12 = IsWindow(local_4c), BVar12 != 0)) &&
         (*(int *)(pCVar7 + 0x9c) != 0)) {
        SendMessageW(*(HWND *)(*(int *)(pCVar7 + 0x9c) + 0x20),0x100,0x24,0);
      }
    }
  }
LAB_0086d9e2:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonMainPanel[68], CMFCRibbonPanel[68] */
/* 0086da16  FUN_0086da16  145 bytes, 0 callers */

void FUN_0086da16(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x4e4)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 500);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x4e4));
  }
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2e0) + 500);
  guard_check_icall(param_1);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x114) + 500);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonMainPanel[42], CMFCRibbonPanel[42] */
/* 0086daa7  FUN_0086daa7  206 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0086daa7(int param_1)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined4 uVar5;
  undefined **local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x86dab3;
  local_18 = in_ECX + 8;
  local_14 = in_ECX;
  FUN_007ed2e1();
  uVar5 = 0;
  local_2c = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
  local_28 = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  local_8 = 0;
  FUN_0086bdcc(&local_2c);
  param_1 = param_1 + -1;
  if ((-1 < param_1) && (param_1 < local_24)) {
    pcVar1 = *(code **)(*in_ECX + 0xa4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if ((iVar3 == 0) || (*(int *)(iVar3 + 0x20) == 0)) {
      uVar5 = 1;
    }
    else {
      puVar4 = (undefined4 *)FUN_00799cf8(param_1);
      pcVar1 = *(code **)(*(int *)*puVar4 + 0xac);
      pcVar2 = *(code **)(*local_14 + 0xa4);
      guard_check_icall();
      uVar5 = (*pcVar2)();
      guard_check_icall(uVar5,local_18);
      uVar5 = (*pcVar1)();
    }
  }
  local_2c = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
  if (local_28 != 0) {
    thunk_FUN_008f43b0(local_28);
  }
  return uVar5;
}




/* vtable slots: CMFCRibbonMainPanel[65], CMFCRibbonPanel[65] */
/* 0086db75  FUN_0086db75  152 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0086db75(int param_1)

{
  code *pcVar1;
  int *piVar2;
  BOOL BVar3;
  undefined4 uVar4;
  int in_ECX;
  int local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = 0;
  if (0 < *(int *)(in_ECX + 0x4e4)) {
    do {
      piVar2 = (int *)FUN_00799cf8(local_1c);
      piVar2 = (int *)*piVar2;
      pcVar1 = *(code **)(*piVar2 + 0x128);
      if (param_1 == 0) {
LAB_0086dbd4:
        uVar4 = 0;
      }
      else {
        local_18.left = piVar2[0x1d];
        local_18.top = piVar2[0x1e];
        local_18.right = piVar2[0x1f];
        local_18.bottom = piVar2[0x20];
        BVar3 = IsRectEmpty(&local_18);
        if (BVar3 != 0) goto LAB_0086dbd4;
        uVar4 = 1;
      }
      guard_check_icall(uVar4);
      (*pcVar1)();
      local_1c = local_1c + 1;
    } while (local_1c < *(int *)(in_ECX + 0x4e4));
  }
  return;
}




/* vtable slots: CMFCRibbonMainPanel[62], CMFCRibbonPanel[62] */
/* 0086dc1a  FUN_0086dc1a  128 bytes, 0 callers */

void FUN_0086dc1a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x4e4)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x228);
      guard_check_icall(param_1,param_2,param_3);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x4e4));
  }
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x114) + 0x228);
  guard_check_icall(param_1,param_2,param_3);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonMainPanel[66], CMFCRibbonPanel[66] */
/* 0086df6c  FUN_0086df6c  121 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0086df6c(int param_1)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int *in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = *(LONG *)(param_1 + 0x74);
  local_18.top = *(LONG *)(param_1 + 0x78);
  local_18.right = *(LONG *)(param_1 + 0x7c);
  local_18.bottom = *(LONG *)(param_1 + 0x80);
  BVar2 = IsRectEmpty(&local_18);
  if (BVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0xa4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != 0)) {
      InvalidateRect(*(HWND *)(iVar3 + 0x20),&local_18,1);
      UpdateWindow(*(HWND *)(iVar3 + 0x20));
    }
  }
  return;
}




/* vtable slots: CMFCRibbonMainPanel[61], CMFCRibbonPanel[61] */
/* 0086e050  FUN_0086e050  3444 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0086e050(undefined4 param_1,RECT *param_2)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  BOOL BVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  CObject *pCVar10;
  int *in_ECX;
  int iVar11;
  undefined1 local_c0 [8];
  uint local_b8;
  CObject *local_b4;
  undefined1 local_b0 [4];
  int *local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  undefined1 local_94 [4];
  int *local_90;
  int local_8c;
  int local_88;
  int local_84;
  int *local_80;
  int local_7c;
  int local_78;
  int local_74;
  CObject *local_70;
  int local_6c;
  CObject *local_68;
  undefined4 local_64;
  int *local_60;
  int *local_5c;
  int local_58;
  int *local_54;
  RECT local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  CObject *local_34;
  int local_30;
  CObject *local_2c;
  int local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc0;
  local_8 = 0x86e05f;
  local_64 = param_1;
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  local_5c = in_ECX;
  BVar4 = EqualRect(param_2,&local_24);
  if (BVar4 != 0) goto LAB_0086edbc;
  local_78 = FUN_0079d98a(&PTR_s_CMFCRibbonUndoButton_009a46b8);
  in_ECX[0x2e] = 0;
  local_50.left = param_2->left;
  local_58 = param_2->top;
  local_50.right = param_2->right;
  local_50.bottom = param_2->bottom;
  bVar2 = 0 < local_50.bottom;
  bVar3 = !bVar2;
  if (bVar3) {
    local_50.bottom = local_58 + 0x7fa4;
  }
  local_b8 = (uint)bVar3;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  local_a0 = local_50.bottom;
  local_98 = local_58;
  local_50.top = local_58;
  if ((bVar2) || (*(int *)(in_ECX[0x44] + 0x35c) != 0)) {
    local_a8 = GetSystemMetrics(2);
    in_ECX = local_5c;
  }
  else {
    local_a8 = 0;
  }
  piVar9 = local_5c;
  local_9c = 0;
  local_80 = in_ECX + 0x33;
  local_70 = (CObject *)local_50.left;
  local_68 = (CObject *)local_50.left;
  *local_80 = local_50.left;
  in_ECX[0x34] = local_50.top;
  in_ECX[0x35] = local_50.right;
  in_ECX[0x36] = local_50.bottom;
  if (in_ECX[0x25] == 0) {
    in_ECX[0x35] = in_ECX[0x35] + local_a8;
    local_b4 = (CObject *)local_50.right;
  }
  else {
    local_b4 = (CObject *)(local_50.right + -local_a8);
  }
  local_74 = 0;
  local_a4 = 0;
  local_8c = 0;
  local_6c = 0;
  local_90 = in_ECX + 0x37;
  iVar6 = in_ECX[0x139];
  if (in_ECX[0x25] == 0) {
    local_60 = (int *)0x0;
    *local_90 = in_ECX[0x33];
    in_ECX[0x38] = in_ECX[0x34];
    in_ECX[0x39] = in_ECX[0x35];
    in_ECX[0x3a] = in_ECX[0x36];
    if (iVar6 < 1) {
LAB_0086e53b:
      if (local_78 == 0) {
        piVar9 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar9 + 0x2dc);
        guard_check_icall();
        iVar6 = (*pcVar1)();
        piVar5 = (int *)FUN_007fe1cf(local_c0);
        piVar9 = local_5c;
        local_6c = *piVar5 + iVar6 * 2;
        if (local_5c[0x42] != 0) {
          piVar5 = (int *)FUN_008721a4(local_c0,0);
          local_6c = *piVar5;
        }
      }
    }
    else {
      do {
        puVar7 = (undefined4 *)FUN_00799cf8(local_60);
        piVar5 = (int *)*puVar7;
        local_54 = piVar5;
        iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonGalleryIcon_009a0628);
        if ((iVar6 == 0) && (iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonLabel_009a4408), iVar6 == 0)) {
          pcVar1 = *(code **)(*piVar5 + 0x180);
          guard_check_icall(local_64);
          (*pcVar1)();
          pcVar1 = *(code **)(*local_54 + 0xec);
          guard_check_icall(1);
          (*pcVar1)();
          pcVar1 = *(code **)(*local_54 + 0x114);
          guard_check_icall(local_c0,0);
          (*pcVar1)();
          iVar6 = FUN_00420890(0,0);
          if (iVar6 != 0) {
            pcVar1 = *(code **)(*local_54 + 0xec);
            guard_check_icall(0);
            (*pcVar1)();
          }
          pcVar1 = *(code **)(*local_54 + 0xbc);
          guard_check_icall(1);
          (*pcVar1)();
          pcVar1 = *(code **)(*local_54 + 0xf4);
          guard_check_icall(&local_88,local_64);
          (*pcVar1)();
          local_88 = local_88 + 6;
          if (local_8c <= local_84) {
            local_8c = local_84;
          }
          pcVar1 = *(code **)(*local_54 + 0x114);
          guard_check_icall(local_94,1);
          piVar5 = (int *)(*pcVar1)();
          if (local_6c <= *piVar5) {
            pcVar1 = *(code **)(*local_54 + 0x114);
            guard_check_icall(local_b0,1);
            piVar5 = (int *)(*pcVar1)();
            local_6c = *piVar5;
          }
        }
        local_60 = (int *)((int)local_60 + 1);
      } while ((int)local_60 < piVar9[0x139]);
      if (local_6c == 0) goto LAB_0086e53b;
    }
    iVar6 = piVar9[0x139];
    local_60 = (int *)0x0;
    if (0 < iVar6) {
      do {
        puVar7 = (undefined4 *)FUN_00799cf8(local_60);
        piVar5 = (int *)*puVar7;
        local_54 = piVar5;
        iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonGalleryIcon_009a0628);
        if (((iVar6 == 0) && (iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonLabel_009a4408), iVar6 == 0)) &&
           (piVar5[0x3e] != 0)) {
          pcVar1 = *(code **)(*piVar5 + 0xf4);
          guard_check_icall(&local_7c,local_64);
          (*pcVar1)();
          if ((local_7c == 0) && (local_78 == 0)) {
            local_54[0x1d] = 0;
            local_54[0x1e] = 0;
            local_54[0x1f] = 0;
            local_54[0x20] = 0;
          }
          else {
            local_54[0x2b] = local_6c;
            local_7c = local_80[2] - *local_80;
            local_24.right = (LONG)(local_70 + local_7c);
            local_78 = local_8c;
            local_24.top = local_98 + local_58;
            local_24.left = (LONG)local_70;
            local_24.bottom = local_8c + local_24.top;
            local_54[0x1d] = (int)local_70;
            local_54[0x1e] = local_24.top;
            local_54[0x1f] = local_24.right;
            local_54[0x20] = local_24.bottom;
            local_58 = local_58 + local_8c;
            piVar9 = local_5c;
          }
        }
        iVar6 = piVar9[0x139];
        local_60 = (int *)((int)local_60 + 1);
      } while ((int)local_60 < iVar6);
    }
    piVar9[0x3a] = local_58;
  }
  else {
    local_78 = local_a0;
    in_ECX[0x37] = in_ECX[0x33];
    in_ECX[0x38] = in_ECX[0x34];
    in_ECX[0x39] = in_ECX[0x35];
    in_ECX[0x3a] = in_ECX[0x36];
    in_ECX[0x3b] = in_ECX[0x33];
    local_54 = (int *)0x0;
    in_ECX[0x3c] = in_ECX[0x34];
    in_ECX[0x3d] = in_ECX[0x35];
    in_ECX[0x3e] = in_ECX[0x36];
    local_60 = (int *)local_58;
    if (0 < iVar6) {
      do {
        piVar5 = (int *)FUN_00799cf8(local_54);
        piVar5 = (int *)*piVar5;
        local_ac = piVar5;
        local_90 = (int *)FUN_0079d98a(&PTR_s_CMFCRibbonLabel_009a4408);
        iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonGalleryIcon_009a0628);
        if ((iVar6 == 0) && (local_90 == (int *)0x0)) {
          if (piVar5[0x3e] == 0) {
            local_74 = 1;
          }
          else {
            local_a4 = 1;
          }
          pcVar1 = *(code **)(*piVar5 + 0x180);
          guard_check_icall(local_64);
          (*pcVar1)();
          pcVar1 = *(code **)(*piVar5 + 0xec);
          guard_check_icall(1);
          (*pcVar1)();
          pcVar1 = *(code **)(*piVar5 + 0x114);
          guard_check_icall(local_c0,0);
          (*pcVar1)();
          iVar6 = FUN_00420890(0,0);
          if (iVar6 != 0) {
            pcVar1 = *(code **)(*piVar5 + 0xec);
            guard_check_icall(0);
            (*pcVar1)();
          }
          pcVar1 = *(code **)(*piVar5 + 0xbc);
          guard_check_icall(1);
          (*pcVar1)();
          pcVar1 = *(code **)(*piVar5 + 0xf4);
          guard_check_icall(&local_88,local_64);
          (*pcVar1)();
          local_88 = local_80[2] - *local_80;
          if (piVar5[0x3e] == 0) {
            local_78 = local_78 - local_84;
            local_50.left = (LONG)local_70;
            local_50.right = (LONG)(local_70 + local_88);
            local_50.bottom = local_78 + local_84;
            local_a0 = local_78 + -4;
            local_5c[0x3c] = local_78;
            local_50.top = local_78;
            local_30 = local_78;
            local_28 = local_50.bottom;
          }
          else {
            local_24.top = (LONG)local_60;
            local_24.left = (LONG)local_70;
            local_24.right = (LONG)(local_70 + local_88);
            local_28 = (int)local_60 + local_84;
            local_58 = local_58 + local_84;
            local_98 = local_28 + 4;
            local_30 = (int)local_60;
            local_5c[0x3a] = local_28;
            local_60 = (int *)local_28;
            local_24.bottom = local_28;
          }
          local_2c = local_70 + local_88;
          local_34 = local_70;
          local_ac[0x1d] = (int)local_70;
          local_ac[0x1e] = local_30;
          local_ac[0x1f] = (int)local_2c;
          local_ac[0x20] = local_28;
          piVar9 = local_5c;
        }
        iVar6 = piVar9[0x139];
        local_54 = (int *)((int)local_54 + 1);
      } while ((int)local_54 < iVar6);
    }
  }
  local_78 = piVar9[0x36];
  iVar8 = piVar9[0x25];
  local_ac = (int *)0x1;
  if (iVar8 == 0) {
    piVar9[0x36] = local_58;
  }
  local_60 = (int *)0x0;
  if (0 < iVar6) {
    do {
      iVar6 = local_58;
      puVar7 = (undefined4 *)FUN_00799cf8(local_60);
      local_54 = (int *)*puVar7;
      local_80 = (int *)FUN_0079d98a(&PTR_s_CMFCRibbonLabel_009a4408);
      iVar8 = FUN_0079d98a(&PTR_s_CMFCRibbonGalleryIcon_009a0628);
      piVar5 = local_54;
      if (iVar8 == 0) {
        if (local_80 == (int *)0x0) {
          if (local_54[0x3e] == 0) {
            local_74 = 1;
          }
          else {
            local_a4 = 1;
          }
        }
        else {
LAB_0086e743:
          if ((int)local_70 < (int)local_68) {
            local_58 = local_78;
            iVar6 = local_78;
          }
          if (0 < (int)local_60) {
            local_58 = iVar6 + 1;
          }
          CStringT<>(local_54[0x18]);
          piVar5 = local_54;
          local_8 = 0;
          local_24.left = 0;
          local_24.top = 0;
          local_24.right = 0;
          local_24.bottom = 0;
          if (local_90[-3] == 0) {
            if (local_ac == (int *)0x0) {
              pcVar1 = *(code **)(*(int *)piVar9[0x44] + 0x2a0);
              guard_check_icall();
              iVar6 = (*pcVar1)();
              local_58 = local_58 + iVar6;
            }
            local_9c = 0;
          }
          else {
            pcVar1 = *(code **)(*local_54 + 0x180);
            guard_check_icall(local_64);
            (*pcVar1)();
            pcVar1 = *(code **)(*piVar5 + 0xf4);
            guard_check_icall(local_c0,local_64);
            iVar6 = (*pcVar1)();
            local_80 = *(int **)(iVar6 + 4);
            local_9c = (int)local_80 + local_58;
            local_24.left = (LONG)local_70;
            local_24.top = local_58;
            local_24.right = (LONG)local_b4;
            pcVar1 = *(code **)(*(int *)local_5c[0x44] + 0x2a0);
            local_24.bottom = local_9c;
            guard_check_icall();
            iVar6 = (*pcVar1)();
            local_58 = (int)local_80 + local_58 + iVar6;
            local_ac = (int *)0x0;
          }
          piVar9 = local_5c;
          local_54[0x1d] = local_24.left;
          local_54[0x1e] = local_24.top;
          local_54[0x1f] = local_24.right;
          local_54[0x20] = local_24.bottom;
          if (local_5c[0x25] == 0) {
            local_5c[0x36] = local_24.bottom;
          }
          local_8 = 0xffffffff;
          local_68 = local_70;
          FUN_00406b10();
          local_78 = local_9c;
        }
      }
      else {
        if (local_80 != (int *)0x0) goto LAB_0086e743;
        local_ac = (int *)0x0;
        pcVar1 = *(code **)(*local_54 + 0xec);
        guard_check_icall(0);
        (*pcVar1)();
        pcVar1 = *(code **)(*piVar5 + 0xf4);
        guard_check_icall(&local_50.right,local_64);
        piVar9 = (int *)(*pcVar1)();
        local_34 = local_68;
        if (((int)local_b4 < (int)(local_68 + *piVar9)) && (local_68 != local_70)) {
          local_58 = local_58 + piVar9[1];
          local_34 = local_70;
        }
        local_68 = local_34 + *piVar9;
        local_9c = local_58 + piVar9[1];
        piVar5[0x1d] = (int)local_34;
        piVar5[0x1e] = local_58;
        piVar5[0x1f] = (int)local_68;
        piVar5[0x20] = local_9c;
        piVar9 = local_5c;
        local_78 = local_9c;
        local_30 = local_58;
        local_2c = local_68;
        local_28 = local_9c;
        if (local_5c[0x25] == 0) {
          local_5c[0x36] = local_9c;
        }
      }
      iVar6 = piVar9[0x139];
      local_60 = (int *)((int)local_60 + 1);
    } while ((int)local_60 < iVar6);
    iVar8 = piVar9[0x25];
  }
  if (iVar8 == 0) {
    iVar8 = piVar9[0x36];
    if (local_a0 <= piVar9[0x36]) {
      iVar8 = local_a0;
    }
    piVar9[0x36] = iVar8;
  }
  piVar9[0x2a] = piVar9[0x35] - piVar9[0x33];
  if (local_74 == 0) {
    SetRectEmpty((LPRECT)(piVar9 + 0x3b));
  }
  else if (piVar9[0x25] == 0) {
    local_54 = (int *)(piVar9[0x36] + 4);
    local_90 = (int *)0x0;
    piVar9[0x3b] = piVar9[0x33];
    piVar9[0x3c] = piVar9[0x34];
    piVar9[0x3d] = piVar9[0x35];
    piVar9[0x3e] = piVar9[0x36];
    local_5c[0x3c] = (int)local_54;
    piVar9 = local_5c;
    if (0 < iVar6) {
      do {
        piVar5 = (int *)FUN_00799cf8(local_90);
        piVar5 = (int *)*piVar5;
        local_60 = piVar5;
        iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonGalleryIcon_009a0628);
        if (((iVar6 == 0) && (iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonLabel_009a4408), iVar6 == 0)) &&
           (piVar5[0x3e] == 0)) {
          pcVar1 = *(code **)(*piVar5 + 0xf4);
          guard_check_icall(&local_88,local_64);
          (*pcVar1)();
          if ((local_88 == 0) && (local_84 == 0)) {
            local_60[0x1d] = 0;
            local_60[0x1e] = 0;
            local_60[0x1f] = 0;
            local_60[0x20] = 0;
          }
          else {
            local_34 = local_70;
            local_60[0x2b] = local_6c;
            local_88 = piVar9[0x35] - piVar9[0x33];
            local_84 = local_8c;
            local_2c = local_70 + local_88;
            local_30 = (int)local_54 + local_98;
            local_28 = local_8c + local_30;
            piVar9[0x36] = local_28;
            local_60[0x1d] = (int)local_70;
            local_60[0x1e] = local_30;
            local_60[0x1f] = (int)local_2c;
            local_60[0x20] = local_28;
            local_54 = (int *)((int)local_54 + local_8c);
            piVar9 = local_5c;
          }
        }
        local_90 = (int *)((int)local_90 + 1);
      } while ((int)local_90 < piVar9[0x139]);
    }
    piVar9[0x3e] = (int)local_54;
  }
  iVar6 = local_a4;
  if (local_a4 == 0) {
    SetRectEmpty((LPRECT)(piVar9 + 0x37));
  }
  local_90 = (int *)0x0;
  if (0 < piVar9[0x139]) {
    do {
      puVar7 = (undefined4 *)FUN_00799cf8(local_90);
      local_68 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                    (CObject *)*puVar7);
      if (local_68 != (CObject *)0x0) {
        *(undefined4 *)(local_68 + 0x1cc) = 0;
        *(undefined4 *)(local_68 + 0x1d0) = 0;
        *(undefined4 *)(local_68 + 0x1d4) = 0;
        *(undefined4 *)(local_68 + 0x1d8) = 0;
        local_50.left = *(LONG *)(local_68 + 0x74);
        local_50.top = *(LONG *)(local_68 + 0x78);
        local_50.right = *(LONG *)(local_68 + 0x7c);
        local_50.bottom = *(LONG *)(local_68 + 0x80);
        BVar4 = IsRectEmpty(&local_50);
        piVar9 = local_5c;
        if (BVar4 == 0) {
          pcVar1 = *(code **)(*local_5c + 0xb8);
          guard_check_icall((CObject *)(local_50.left + -2),(local_50.bottom + local_50.top) / 2,0);
          pCVar10 = (CObject *)(*pcVar1)();
          pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                       pCVar10);
          *(uint *)(local_68 + 0x1cc) = (uint)(pCVar10 == (CObject *)0x0);
          pcVar1 = *(code **)(*piVar9 + 0xb8);
          guard_check_icall((CObject *)(local_50.right + 2),(local_50.bottom + local_50.top) / 2,0);
          pCVar10 = (CObject *)(*pcVar1)();
          pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                       pCVar10);
          *(uint *)(local_68 + 0x1d0) = (uint)(pCVar10 == (CObject *)0x0);
          pcVar1 = *(code **)(*piVar9 + 0xb8);
          guard_check_icall((int)(local_50.right + local_50.left) / 2,local_50.top + -2,0);
          pCVar10 = (CObject *)(*pcVar1)();
          pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                       pCVar10);
          *(uint *)(local_68 + 0x1d4) = (uint)(pCVar10 == (CObject *)0x0);
          pcVar1 = *(code **)(*piVar9 + 0xb8);
          guard_check_icall((int)(local_50.right + local_50.left) / 2,local_50.bottom + 2,0);
          pCVar10 = (CObject *)(*pcVar1)();
          pCVar10 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                       pCVar10);
          *(uint *)(local_68 + 0x1d8) = (uint)(pCVar10 == (CObject *)0x0);
        }
      }
      local_90 = (int *)((int)local_90 + 1);
      iVar6 = local_a4;
    } while ((int)local_90 < piVar9[0x139]);
  }
  iVar8 = local_98;
  if ((local_b8 == 0) || (*(int *)(piVar9[0x44] + 0x35c) != 0)) {
    iVar11 = local_98;
    if (iVar6 != 0) {
      iVar11 = piVar9[0x3a] + 1;
    }
    if (local_74 == 0) {
      iVar6 = piVar9[0x36];
    }
    else {
      iVar6 = piVar9[0x3c] + -1;
    }
    FUN_00797e71(0,piVar9[0x35] - local_a8,iVar11,local_a8,(iVar6 - iVar11) + -1,0x14);
    _memset(&local_40,0,0x1c);
    local_38 = 0;
    pCVar10 = (CObject *)(local_9c + (piVar9[0x38] - piVar9[0x3a]));
    local_40 = 0x1c;
    local_3c = 7;
    if (local_a0 - iVar8 < (int)pCVar10) {
      local_34 = pCVar10;
      local_30 = local_a0 - iVar8;
      FUN_00795359(2,&local_40,1);
      EnableScrollBar(*(HWND *)(piVar9[0x41] + 0x20),2,0);
      FUN_007979e8(1);
    }
    else if (local_b8 == 0) {
      EnableScrollBar(*(HWND *)(piVar9[0x41] + 0x20),2,3);
    }
  }
LAB_0086edbc:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonMainPanel[60], CMFCRibbonPanel[60] */
/* 00870721  FUN_00870721  800 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00870721(undefined4 param_1,RECT *param_2)

{
  code *pcVar1;
  RECT *pRVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  BOOL BVar6;
  int in_ECX;
  int iVar7;
  int local_44;
  int local_40;
  int local_38;
  int local_34;
  int local_30;
  RECT *local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int *local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = param_2;
  local_44 = 0;
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  local_30 = 0;
  local_40 = 0;
  local_24 = in_ECX;
  if (*(int *)(in_ECX + 0x108) != 0) {
    piVar3 = (int *)FUN_008721a4(&local_38,1);
    local_40 = *piVar3;
  }
  local_20 = 0;
  local_28 = (int *)0x0;
  if (0 < *(int *)(in_ECX + 0x4e4)) {
    do {
      puVar4 = (undefined4 *)FUN_00799cf8(local_28);
      local_1c = (int *)*puVar4;
      if ((int)local_28 < *(int *)(in_ECX + 0xb8)) {
        local_1c[0x1d] = -1;
        local_1c[0x1e] = -1;
        local_1c[0x1f] = -1;
        local_1c[0x20] = -1;
      }
      else {
        pcVar1 = *(code **)(*local_1c + 0x180);
        guard_check_icall(param_1);
        (*pcVar1)();
        pcVar1 = *(code **)(*local_1c + 0xec);
        guard_check_icall(0);
        (*pcVar1)();
        pcVar1 = *(code **)(*local_1c + 0xbc);
        guard_check_icall(1);
        (*pcVar1)();
        pcVar1 = *(code **)(*local_1c + 0xf4);
        guard_check_icall(&local_38,param_1);
        (*pcVar1)();
        pRVar2 = local_2c;
        if ((local_38 == 0) && (local_34 == 0)) {
          local_1c[0x1d] = 0;
          local_1c[0x1e] = 0;
          local_1c[0x1f] = 0;
          local_1c[0x20] = 0;
        }
        else {
          BVar6 = IsRectEmpty(local_2c);
          if ((BVar6 == 0) &&
             (local_38 = pRVar2->right - pRVar2->left, *(int *)(in_ECX + 0x7c) != 0)) {
            piVar3 = (int *)FUN_007fe1cf(&local_18.right);
            local_1c[0x2b] = *piVar3;
          }
          iVar7 = *(int *)(in_ECX + 0xb0) + pRVar2->left;
          iVar5 = pRVar2->top + local_30 + *(int *)(in_ECX + 0xb4);
          local_1c[0x1d] = iVar7;
          local_1c[0x1e] = iVar5;
          local_1c[0x1f] = local_38 + iVar7;
          local_1c[0x20] = local_34 + iVar5;
          if (local_20 <= local_38) {
            local_20 = local_38;
          }
          local_30 = local_30 + local_34;
          in_ECX = local_24;
          if (local_2c->bottom < local_30) {
            *(undefined4 *)(local_24 + 0x98) = 1;
          }
        }
      }
      local_28 = (int *)((int)local_28 + 1);
    } while ((int)local_28 < *(int *)(in_ECX + 0x4e4));
  }
  if (*(int *)(in_ECX + 0x7c) != 0) {
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0x2dc);
    guard_check_icall();
    iVar5 = (*pcVar1)();
    piVar3 = (int *)FUN_007fe1cf(&local_18.right);
    local_20 = local_20 + *piVar3 + iVar5 * 2;
    in_ECX = local_24;
  }
  *(int *)(in_ECX + 0xa8) = local_20;
  BVar6 = IsRectEmpty(local_2c);
  if ((BVar6 != 0) && (0 < *(int *)(in_ECX + 0x4e4))) {
    do {
      local_28 = (int *)FUN_00799cf8(local_44);
      local_28 = (int *)*local_28;
      local_1c = local_28 + 0x1d;
      local_18.left = *local_1c;
      local_18.top = local_28[0x1e];
      local_18.right = local_28[0x1f];
      local_18.bottom = local_28[0x20];
      BVar6 = IsRectEmpty(&local_18);
      if (BVar6 == 0) {
        local_18.right = local_18.left + local_20;
        if ((0 < local_40) &&
           (iVar5 = FUN_0079d98a(&PTR_s_CMFCRibbonSeparator_00998170), iVar5 != 0)) {
          local_18.left = local_18.left + *(int *)(local_24 + 0xb0) + local_40;
        }
        *local_1c = local_18.left;
        local_1c[1] = local_18.top;
        local_1c[2] = local_18.right;
        local_1c[3] = local_18.bottom;
      }
      pcVar1 = *(code **)(*local_28 + 0x124);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_44 = local_44 + 1;
      in_ECX = local_24;
    } while (local_44 < *(int *)(local_24 + 0x4e4));
  }
  *(int *)(in_ECX + 0xcc) = local_2c->left;
  *(LONG *)(in_ECX + 0xd0) = local_2c->top;
  *(LONG *)(in_ECX + 0xd4) = local_2c->right;
  *(LONG *)(in_ECX + 0xd8) = local_2c->bottom;
  *(int *)(local_24 + 0xd8) = *(int *)(local_24 + 0xd0) + local_30;
  *(int *)(local_24 + 0xd4) = *(int *)(in_ECX + 0xcc) + *(int *)(local_24 + 0xa8);
  return;
}




/* vtable slots: CMFCRibbonMainPanel[43], CMFCRibbonPanel[43] */
/* 00870beb  FUN_00870beb  153 bytes, 0 callers */

undefined4 FUN_00870beb(undefined4 param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  int iVar1;
  int in_ECX;
  
  Empty();
  Empty();
  Empty();
  Empty();
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,(CSimpleStringT<wchar_t,0> *)(in_ECX + 0xfc));
  *(undefined4 *)(param_2 + 0x18) = 0x16;
  iVar1 = FUN_008f899d(L"Group");
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 4,L"Group",iVar1);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(in_ECX + 0xcc);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(in_ECX + 0xd0);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(in_ECX + 0xd4);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(in_ECX + 0xd8);
  if (((*(int *)(in_ECX + 0x108) != 0) &&
      (iVar1 = *(int *)(*(int *)(in_ECX + 0x108) + 0x53c), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x20) != 0)) {
    FUN_0079e8b8(param_2 + 0x24);
  }
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return 1;
}




/* vtable slots: CMFCRibbonMainPanel[38], CMFCRibbonPanel[38] */
/* 00870f96  FUN_00870f96  177 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00870f96(short param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined **local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  if (param_1 != 3) {
    return 0x80070057;
  }
  if (param_3 == 0) {
LAB_0087101d:
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    local_24 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    local_20 = 0;
    local_14 = 0;
    local_18 = 0;
    local_1c = 0;
    local_8 = 0;
    FUN_0086bdcc(&local_24);
    param_3 = param_3 + -1;
    if ((param_3 < 0) || (local_1c <= param_3)) {
      uVar3 = 0x80070057;
    }
    else {
      piVar2 = (int *)FUN_00799cf8(param_3);
      if ((int *)*piVar2 == (int *)0x0) {
        local_24 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
        if (local_20 != 0) {
          thunk_FUN_008f43b0(local_20);
        }
        goto LAB_0087101d;
      }
      pcVar1 = *(code **)(*(int *)*piVar2 + 0x15c);
      guard_check_icall();
      (*pcVar1)();
    }
    local_24 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    if (local_20 != 0) {
      thunk_FUN_008f43b0(local_20);
    }
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonMainPanel[37], CMFCRibbonPanel[37] */
/* 00871047  FUN_00871047  343 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00871047(LONG param_1,LONG param_2,undefined2 *param_3)

{
  code *pcVar1;
  POINT pt;
  int iVar2;
  int iVar3;
  int *piVar4;
  BOOL BVar5;
  int *in_ECX;
  int iVar6;
  undefined **local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  tagPOINT local_2c;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x871053;
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = 3;
    iVar6 = 0;
    *(undefined4 *)(param_3 + 4) = 0;
    pcVar1 = *(code **)(*in_ECX + 0xa4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x20) != 0)) && (in_ECX[0x42] != 0)) &&
       ((iVar2 = *(int *)(in_ECX[0x42] + 0x53c), iVar2 != 0 && (*(int *)(iVar2 + 0x20) != 0)))) {
      local_2c.x = param_1;
      local_2c.y = param_2;
      pcVar1 = *(code **)(*in_ECX + 0xa4);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      ScreenToClient(*(HWND *)(iVar3 + 0x20),&local_2c);
      local_40 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
      local_3c = 0;
      local_30 = 0;
      local_34 = 0;
      local_38 = 0;
      local_8 = 0;
      FUN_0086bdcc(&local_40);
      if (0 < local_38) {
        do {
          piVar4 = (int *)FUN_00799cf8(iVar6);
          piVar4 = (int *)*piVar4;
          if (piVar4 != (int *)0x0) {
            local_24.left = piVar4[0x1d];
            local_24.top = piVar4[0x1e];
            local_24.right = piVar4[0x1f];
            local_24.bottom = piVar4[0x20];
            pt.y = local_2c.y;
            pt.x = local_2c.x;
            BVar5 = PtInRect(&local_24,pt);
            if (BVar5 != 0) {
              *(int *)(param_3 + 4) = iVar6 + 1;
              pcVar1 = *(code **)(*piVar4 + 0xac);
              guard_check_icall(iVar2,in_ECX + 8);
              (*pcVar1)();
              break;
            }
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < local_38);
      }
      local_40 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
      if (local_3c != 0) {
        thunk_FUN_008f43b0(local_3c);
      }
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonMainPanel[35], CMFCRibbonPanel[35] */
/* 0087119e  FUN_0087119e  287 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0087119e(int *param_1,int *param_2,int *param_3,int *param_4,short param_5,undefined4 param_6,
            int param_7)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) && (param_3 != (int *)0x0)) &&
     (param_4 != (int *)0x0)) {
    if (param_5 == 3) {
      if (param_7 == 0) {
        pcVar1 = *(code **)(*in_ECX + 0xa4);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if ((iVar2 == 0) || (*(int *)(iVar2 + 0x20) == 0)) {
          return 1;
        }
        local_18 = in_ECX[0x33];
        local_14 = in_ECX[0x34];
        local_10 = in_ECX[0x35];
        local_c = in_ECX[0x36];
        pcVar1 = *(code **)(*in_ECX + 0xa4);
        guard_check_icall();
        (*pcVar1)();
        FUN_0079e8b8(&local_18);
        *param_1 = local_18;
        *param_2 = local_14;
        *param_3 = local_10 - local_18;
        local_c = local_c - local_14;
      }
      else {
        if (param_7 < 1) {
          return 0;
        }
        pcVar1 = *(code **)(*in_ECX + 0xa8);
        guard_check_icall(param_7);
        (*pcVar1)();
        *param_1 = in_ECX[0x11];
        *param_2 = in_ECX[0x12];
        *param_3 = in_ECX[0x13] - in_ECX[0x11];
        local_c = in_ECX[0x14] - in_ECX[0x12];
      }
      *param_4 = local_c;
    }
    return 0;
  }
  return 0x80070057;
}




/* vtable slots: CMFCRibbonMainPanel[36], CMFCRibbonPanel[36] */
/* 008712bd  FUN_008712bd  337 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_008712bd(int param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined2 *param_6)

{
  int iVar1;
  int iVar2;
  CCmdTarget *this;
  IDispatch *pIVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined **local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  if ((param_6 == (undefined2 *)0x0) || (*param_6 = 0, param_2 != 3)) {
    return 0x80070057;
  }
  uVar4 = 0;
  local_28 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
  local_24 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_8 = 0;
  FUN_0086bdcc(&local_28);
  if (param_1 == 3) {
LAB_008713b1:
    if (param_4 == 0) {
      if (*(int *)(in_ECX + 0x108) != 0) {
        iVar2 = FUN_008724e9(in_ECX);
        iVar2 = iVar2 + -1;
        if (-1 < iVar2) {
LAB_008713db:
          this = (CCmdTarget *)FUN_00872476(iVar2);
          if (this != (CCmdTarget *)0x0) {
            *param_6 = 9;
            pIVar3 = CCmdTarget::GetIDispatch(this,1);
            *(IDispatch **)(param_6 + 4) = pIVar3;
            goto LAB_0087136e;
          }
        }
      }
    }
    else {
      *param_6 = 3;
      *(int *)(param_6 + 4) = param_4 + -1;
      if (0 < param_4 + -1) goto LAB_0087136e;
LAB_00871366:
      *param_6 = 0;
    }
  }
  else {
    if ((param_1 != 4) && (param_1 != 5)) {
      if (param_1 != 6) {
        if (param_1 == 7) {
          if (param_4 != 0) goto LAB_0087136b;
          *(undefined4 *)(param_6 + 4) = 1;
        }
        else {
          if ((param_1 != 8) || (param_4 != 0)) goto LAB_0087136b;
          *(int *)(param_6 + 4) = local_20;
        }
        *param_6 = 3;
        goto LAB_0087136e;
      }
      goto LAB_008713b1;
    }
    if (param_4 != 0) {
      *param_6 = 3;
      *(int *)(param_6 + 4) = param_4 + 1;
      if (param_4 + 1 <= local_20) goto LAB_0087136e;
      goto LAB_00871366;
    }
    if (*(int *)(in_ECX + 0x108) != 0) {
      local_14 = FUN_008724e9(in_ECX);
      local_14 = local_14 + 1;
      iVar1 = FUN_0087248d();
      iVar2 = local_14;
      if (iVar1 <= local_14) goto LAB_0087136b;
      goto LAB_008713db;
    }
  }
LAB_0087136b:
  uVar4 = 1;
LAB_0087136e:
  local_28 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
  if (local_24 != 0) {
    thunk_FUN_008f43b0(local_24);
  }
  return uVar4;
}




/* vtable slots: CMFCRibbonMainPanel[21], CMFCRibbonPanel[21] */
/* 0087140e  FUN_0087140e  93 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0087140e(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined **local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    local_24 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    local_20 = 0;
    local_14 = 0;
    local_18 = 0;
    local_1c = 0;
    local_8 = 0;
    FUN_0086bdcc(&local_24);
    *param_1 = local_1c;
    local_24 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    if (local_20 != 0) {
      thunk_FUN_008f43b0(local_20);
    }
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonMainPanel[20], CMFCRibbonPanel[20] */
/* 0087146b  get_accParent  44 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual long __thiscall CMFCRibbonPanel::get_accParent(struct IDispatch * *)
   
   Library: Visual Studio 2015 Release */

long __thiscall CMFCRibbonPanel::get_accParent(CMFCRibbonPanel *this,IDispatch **param_1)

{
  IDispatch *pIVar1;
  
  if (param_1 != (IDispatch **)0x0) {
    pIVar1 = CCmdTarget::GetIDispatch(*(CCmdTarget **)(this + 0x108),1);
    *param_1 = pIVar1;
    if (pIVar1 != (IDispatch *)0x0) {
      return 0;
    }
  }
  return -0x7ff8ffa9;
}




/* vtable slots: CMFCRibbonMainPanel[1] */
/* 008b4e76  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonMainPanel::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonMainPanel::_scalar_deleting_destructor_(CMFCRibbonMainPanel *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_0086a1db();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x514);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonMainPanel[51] */
/* 008b4ee2  FUN_008b4ee2  66 bytes, 0 callers */

void FUN_008b4ee2(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uVar3;
  
  pcVar1 = *(code **)(*param_1 + 0x164);
  guard_check_icall(*(undefined4 *)(in_ECX + 0x108));
  (*pcVar1)();
  uVar3 = 1;
  uVar2 = FUN_008b5662(param_1,1);
  FUN_00867e50(uVar2,param_1,uVar3);
  return;
}




/* vtable slots: CMFCRibbonMainPanel[44] */
/* 008b4f24  FUN_008b4f24  187 bytes, 0 callers */

void FUN_008b4f24(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  CObject *pCVar3;
  
  FUN_0086a87a(param_1);
  pCVar3 = (CObject *)0x0;
  *(undefined4 *)(in_ECX + 0x4f0) = *(undefined4 *)(param_1 + 0x4f0);
  *(undefined4 *)(in_ECX + 0x4f4) = *(undefined4 *)(param_1 + 0x4f4);
  *(undefined4 *)(in_ECX + 0x50c) = *(undefined4 *)(param_1 + 0x50c);
  *(undefined4 *)(in_ECX + 0x510) = 0;
  *(undefined4 *)(in_ECX + 0x4f8) = *(undefined4 *)(param_1 + 0x4f8);
  if (*(int *)(param_1 + 0x510) != 0) {
    if (0 < *(int *)(param_1 + 0x4e4)) {
      do {
        piVar1 = (int *)FUN_00799cf8(pCVar3);
        if (*piVar1 == *(int *)(param_1 + 0x510)) {
          puVar2 = (undefined4 *)FUN_00799cf8(pCVar3);
          pCVar3 = (CObject *)*puVar2;
          *(CObject **)(in_ECX + 0x510) = pCVar3;
          goto LAB_008b4fc0;
        }
        pCVar3 = pCVar3 + 1;
      } while ((int)pCVar3 < *(int *)(param_1 + 0x4e4));
      pCVar3 = *(CObject **)(in_ECX + 0x510);
    }
LAB_008b4fc0:
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonRecentFilesList_009a17b8,pCVar3);
    if (pCVar3 != (CObject *)0x0) {
      FUN_008c58f7();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonMainPanel[58] */
/* 008b5040  FUN_008b5040  673 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b5040(int *param_1)

{
  code *pcVar1;
  int iVar2;
  RECT *lprc;
  BOOL BVar3;
  COLORREF CVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *in_ECX;
  int local_60;
  tagRECT local_48;
  RECT local_38;
  tagRECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  lprc = (RECT *)(in_ECX + 0x33);
  BVar3 = IsRectEmpty(lprc);
  if (BVar3 == 0) {
    local_60 = 0;
    pcVar1 = *(code **)(*param_1 + 0x50);
    local_38.left = 0;
    local_38.top = 0;
    local_38.right = 0;
    local_38.bottom = 0;
    guard_check_icall(&local_38);
    (*pcVar1)();
    local_48.left = 0;
    local_48.top = 0;
    local_48.right = 0;
    local_48.bottom = 0;
    BVar3 = IntersectRect(&local_48,lprc,&local_38);
    if (BVar3 != 0) {
      CVar4 = GetTextColor((HDC)param_1[2]);
      piVar5 = (int *)FUN_007c2574();
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      pcVar1 = *(code **)(*piVar5 + 0x220);
      guard_check_icall(param_1,in_ECX,lprc->left,in_ECX[0x34],in_ECX[0x35],in_ECX[0x36],0,0,0,0);
      uVar6 = (*pcVar1)();
      pcVar1 = *(code **)(*in_ECX + 0xa4);
      guard_check_icall();
      uVar7 = (*pcVar1)();
      FUN_008b52e1(param_1,uVar7);
      local_28.left = 0;
      local_28.top = 0;
      local_18.left = in_ECX[0x13f];
      local_28.right = 0;
      local_28.bottom = 0;
      local_18.top = in_ECX[0x140];
      local_18.right = in_ECX[0x141];
      local_18.bottom = in_ECX[0x142];
      SetRectEmpty(&local_28);
      iVar2 = in_ECX[0x144];
      if (iVar2 != 0) {
        local_28.left = *(LONG *)(iVar2 + 0x74);
        local_28.top = *(LONG *)(iVar2 + 0x78);
        local_28.right = *(int *)(iVar2 + 0x7c);
        local_28.bottom = *(LONG *)(iVar2 + 0x80);
        piVar5 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar5 + 0x274);
        guard_check_icall(param_1,in_ECX,local_28.left,local_28.top,local_28.right,local_28.bottom);
        (*pcVar1)();
      }
      BVar3 = IsRectEmpty(&local_28);
      if (BVar3 == 0) {
        local_18.right = local_28.right;
      }
      piVar5 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar5 + 0x270);
      guard_check_icall(param_1,in_ECX,in_ECX[0x13f],in_ECX[0x140],in_ECX[0x141],in_ECX[0x142]);
      (*pcVar1)();
      piVar5 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar5 + 0x26c);
      guard_check_icall(param_1,in_ECX,local_18.left,local_18.top,local_18.right,local_18.bottom);
      (*pcVar1)();
      pcVar1 = *(code **)(*param_1 + 0x30);
      guard_check_icall(uVar6);
      (*pcVar1)();
      if (0 < in_ECX[0x139]) {
        do {
          piVar5 = (int *)FUN_00799cf8(local_60);
          piVar5 = (int *)*piVar5;
          local_18.left = piVar5[0x1d];
          local_18.top = piVar5[0x1e];
          local_18.right = piVar5[0x1f];
          local_18.bottom = piVar5[0x20];
          BVar3 = IntersectRect(&local_48,&local_18,&local_38);
          if (BVar3 != 0) {
            pcVar1 = *(code **)(*param_1 + 0x30);
            guard_check_icall(uVar6);
            (*pcVar1)();
            pcVar1 = *(code **)(*piVar5 + 0x17c);
            guard_check_icall(param_1);
            (*pcVar1)();
          }
          local_60 = local_60 + 1;
        } while (local_60 < in_ECX[0x139]);
      }
      pcVar1 = *(code **)(*param_1 + 0x30);
      guard_check_icall(CVar4);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonMainPanel[49] */
/* 008b5679  FUN_008b5679  125 bytes, 0 callers */

undefined4 FUN_008b5679(LPRECT param_1)

{
  LONG LVar1;
  LONG LVar2;
  LONG LVar3;
  int iVar4;
  int in_ECX;
  
  iVar4 = *(int *)(in_ECX + 0x510);
  if (iVar4 != 0) {
    LVar1 = *(LONG *)(iVar4 + 0x78);
    LVar2 = *(LONG *)(iVar4 + 0x7c);
    LVar3 = *(LONG *)(iVar4 + 0x80);
    param_1->left = *(LONG *)(iVar4 + 0x74);
    param_1->top = LVar1;
    param_1->right = LVar2;
    param_1->bottom = LVar3;
    InflateRect(param_1,-1,-1);
    if (((DAT_00a00b24 == 0) || (DAT_00a127ac != 0)) ||
       (iVar4 = FUN_007c2511(), *(int *)(iVar4 + 0x1ac) < 9)) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_007c2574();
      iVar4 = *(int *)(iVar4 + 0x7c);
    }
    param_1->bottom = param_1->bottom + (-3 - iVar4);
    param_1->right = param_1->right + (-3 - iVar4);
    return 1;
  }
  return 0;
}




/* vtable slots: CMFCRibbonMainPanel[0] */
/* 008b57d5  FUN_008b57d5  6 bytes, 0 callers */

undefined ** FUN_008b57d5(void)

{
  return &PTR_s_CMFCRibbonMainPanel_009a1678;
}




/* vtable slots: CMFCRibbonMainPanel[70] */
/* 008b57e1  FUN_008b57e1  171 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008b57e1(LONG param_1,LONG param_2)

{
  int iVar1;
  code *pcVar2;
  POINT pt;
  undefined4 uVar3;
  CWnd *this;
  BOOL BVar4;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar3 = FUN_0086c5ed(param_1,param_2);
  iVar1 = in_ECX[0x143];
  if (iVar1 != 0) {
    local_18.left = *(LONG *)(iVar1 + 0x74);
    local_18.top = *(LONG *)(iVar1 + 0x78);
    local_18.right = *(LONG *)(iVar1 + 0x7c);
    local_18.bottom = *(LONG *)(iVar1 + 0x80);
    FUN_0079e8b8(&local_18);
    pcVar2 = *(code **)(*in_ECX + 0xa4);
    guard_check_icall();
    this = (CWnd *)(*pcVar2)();
    CWnd::ScreenToClient(this,&local_18);
    pt.y = param_2;
    pt.x = param_1;
    BVar4 = PtInRect(&local_18,pt);
    if (BVar4 != 0) {
      pcVar2 = *(code **)(*(int *)in_ECX[0x143] + 0x198);
      guard_check_icall();
      (*pcVar2)();
      uVar3 = 0;
    }
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonMainPanel[67] */
/* 008b5a0b  OnDrawMenuBorder  40 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCRibbonMainPanel::OnDrawMenuBorder(class CDC *,class
   CMFCRibbonPanelMenuBar *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonMainPanel::OnDrawMenuBorder
          (CMFCRibbonMainPanel *this,CDC *param_1,CMFCRibbonPanelMenuBar *param_2)

{
  HWND pHVar1;
  CWnd *pCVar2;
  
  pHVar1 = GetParent(*(HWND *)(param_2 + 0x20));
  pCVar2 = CWnd::FromHandle(pHVar1);
  FUN_008b52e1(param_1,pCVar2);
  return;
}




/* vtable slots: CMFCRibbonMainPanel[50] */
/* 008b5b3d  FUN_008b5b3d  135 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b5b3d(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0042fb40(0,0xffffffff);
  in_ECX[0x1b] = 1;
  in_ECX[0x29] = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0x7fff;
  local_c = 0x7fff;
  pcVar1 = *(code **)(*in_ECX + 0xec);
  guard_check_icall(param_1,&local_18);
  (*pcVar1)();
  FUN_0042f500(in_ECX[0x134],in_ECX[0x2a]);
  in_ECX[0x1b] = 0;
  return;
}




/* vtable slots: CMFCRibbonMainPanel[59] */
/* 008b5bc4  FUN_008b5bc4  1458 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b5bc4(undefined4 param_1,LONG *param_2)

{
  double dVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  BOOL BVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  undefined1 local_74 [8];
  int local_6c;
  int local_68;
  int *local_64;
  CObject *local_60;
  int local_5c;
  int *local_58;
  undefined8 local_54;
  int local_4c;
  int local_48;
  LONG *local_44;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int *local_2c;
  RECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_40 = param_1;
  local_38 = *(int **)(in_ECX + 0x4f4);
  local_44 = param_2;
  local_34 = in_ECX;
  local_3c = FUN_008b5662();
  iVar7 = local_34;
  ((LPRECT)(in_ECX + 0x4fc))->left = *param_2;
  *(LONG *)(in_ECX + 0x500) = param_2[1];
  *(LONG *)(in_ECX + 0x504) = param_2[2];
  *(LONG *)(in_ECX + 0x508) = param_2[3];
  InflateRect((LPRECT)(in_ECX + 0x4fc),-*(int *)(local_34 + 0xb0),-*(int *)(local_34 + 0xb4));
  *(int *)(iVar7 + 0x500) = *(int *)(iVar7 + 0x500) + *(int *)(iVar7 + 0x4f4);
  local_6c = 0;
  local_4c = 0;
  if (*(int *)(iVar7 + 0x108) != 0) {
    piVar3 = (int *)FUN_008721a4(local_74,1);
    local_4c = *piVar3;
  }
  local_48 = 0;
  local_30 = 0;
  if (0 < local_3c) {
    do {
      puVar4 = (undefined4 *)FUN_00799cf8(local_48);
      local_2c = (int *)*puVar4;
      pcVar2 = *(code **)(*local_2c + 0x180);
      guard_check_icall(local_40);
      (*pcVar2)();
      pcVar2 = *(code **)(*local_2c + 0xbc);
      guard_check_icall(1);
      (*pcVar2)();
      pcVar2 = *(code **)(*local_2c + 0xf4);
      guard_check_icall(&local_54,local_40);
      (*pcVar2)();
      if (((int)local_54 == 0) && (local_54._4_4_ == 0)) {
        local_2c[0x1d] = 0;
        local_2c[0x1e] = 0;
        local_2c[0x1f] = 0;
        local_2c[0x20] = 0;
      }
      else {
        local_18.left = *local_44 + *(int *)(iVar7 + 0xb0);
        local_18.right = (int)local_54 + local_18.left;
        local_18.top = local_44[1] + *(int *)(iVar7 + 0xb4) + (int)local_38;
        local_18.bottom = local_54._4_4_ + local_18.top;
        local_2c[0x1d] = local_18.left;
        local_2c[0x1e] = local_18.top;
        local_2c[0x1f] = local_18.right;
        local_2c[0x20] = local_18.bottom;
        if (local_30 <= (int)local_54) {
          local_30 = (int)local_54;
        }
        local_38 = (int *)((int)local_38 + local_54._4_4_);
        iVar7 = local_34;
      }
      local_48 = local_48 + 1;
    } while (local_48 < local_3c);
  }
  local_48 = local_30 + *(int *)(iVar7 + 0xb0) * 2;
  *(LONG *)(iVar7 + 0x504) = ((LPRECT)(iVar7 + 0x4fc))->left + local_48;
  *(int *)(iVar7 + 0x508) = *(int *)(iVar7 + 0xb4) + (int)local_38;
  InflateRect((LPRECT)(iVar7 + 0x4fc),1,1);
  local_30 = 0;
  iVar6 = local_48 + *(int *)(iVar7 + 0xb0) * 2;
  *(int *)(iVar7 + 0xa8) = iVar6;
  if (0 < local_3c) {
    local_60 = (CObject *)(iVar7 + 0x4dc);
    do {
      puVar4 = (undefined4 *)FUN_00799cf8(local_30);
      local_2c = (int *)*puVar4;
      local_58 = local_2c + 0x1d;
      local_28.left = *local_58;
      local_28.top = local_2c[0x1e];
      local_28.right = local_2c[0x1f];
      local_28.bottom = local_2c[0x20];
      BVar5 = IsRectEmpty(&local_28);
      iVar7 = local_4c;
      if (BVar5 == 0) {
        local_28.right = local_28.left + local_48;
        if ((0 < local_4c) &&
           (iVar6 = FUN_0079d98a(&PTR_s_CMFCRibbonSeparator_00998170), iVar6 != 0)) {
          local_28.left = local_28.left + 4 + iVar7;
        }
        *local_58 = local_28.left;
        local_58[1] = local_28.top;
        local_58[2] = local_28.right;
        local_58[3] = local_28.bottom;
      }
      local_30 = local_30 + 1;
    } while (local_30 < local_3c);
    iVar6 = *(int *)(local_34 + 0xa8);
    iVar7 = local_34;
  }
  if (*(CObject **)(iVar7 + 0x510) != (CObject *)0x0) {
    local_60 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonRecentFilesList_009a17b8,
                                  *(CObject **)(iVar7 + 0x510));
    if ((local_60 != (CObject *)0x0) && (*(int *)(local_60 + 0x114) == 0)) {
      FUN_008b53c6();
    }
    pcVar2 = *(code **)(**(int **)(iVar7 + 0x510) + 0x110);
    guard_check_icall(0);
    (*pcVar2)();
    pcVar2 = *(code **)(**(int **)(local_34 + 0x510) + 0x180);
    guard_check_icall(local_40);
    (*pcVar2)();
    pcVar2 = *(code **)(**(int **)(local_34 + 0x510) + 0xf4);
    guard_check_icall(&local_5c,local_40);
    (*pcVar2)();
    iVar7 = FUN_007c2511();
    if (*(int *)(iVar7 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar7 + 0x1e0);
    }
    if (dVar1 == 1.0) {
      iVar7 = *(int *)(local_34 + 0x4f8);
    }
    else {
      FUN_007c2511();
      local_54 = (double)*(int *)(local_34 + 0x4f8);
      iVar7 = thunk_FUN_008d99f0();
    }
    if (local_5c <= iVar7) {
      local_5c = iVar7;
    }
    local_18.bottom = *(int *)(local_34 + 0x508);
    local_18.top = *(int *)(local_34 + 0x500);
    if (local_18.bottom - local_18.top < (int)local_58) {
      local_18.bottom = local_18.top + (int)local_58;
      *(LONG *)(local_34 + 0x508) = local_18.bottom;
    }
    local_18.left = *(int *)(local_34 + 0x504);
    local_18.right = local_18.left + local_5c;
    if (local_60 == (CObject *)0x0) {
      InflateRect(&local_18,0,-1);
    }
    local_28.left = local_18.left;
    local_28.top = local_18.top;
    local_28.right = local_18.right;
    local_28.bottom = local_18.bottom;
    iVar7 = *(int *)(local_34 + 0x510);
    *(LONG *)(iVar7 + 0x74) = local_18.left;
    *(LONG *)(iVar7 + 0x78) = local_18.top;
    *(LONG *)(iVar7 + 0x7c) = local_18.right;
    *(LONG *)(iVar7 + 0x80) = local_18.bottom;
    *(int *)(local_34 + 0xa8) = *(int *)(local_34 + 0xa8) + local_5c;
    iVar6 = *(int *)(local_34 + 0xa8);
    iVar7 = local_34;
  }
  if (0 < *(int *)(iVar7 + 0x4f0)) {
    local_2c = (int *)0x0;
    local_30 = (*local_44 - *(int *)(iVar7 + 0xb0)) + iVar6;
    local_3c = *(int *)(iVar7 + 0xb4) + *(int *)(iVar7 + 0x508);
    local_4c = 0;
    do {
      puVar4 = (undefined4 *)FUN_00799cf8((*(int *)(iVar7 + 0x4e4) - local_4c) + -1);
      local_38 = (int *)*puVar4;
      pcVar2 = *(code **)(*local_38 + 0x180);
      guard_check_icall(local_40);
      (*pcVar2)();
      pcVar2 = *(code **)(*local_38 + 0xf4);
      guard_check_icall(&local_68,local_40);
      (*pcVar2)();
      if ((local_68 == 0) && (local_64 == (int *)0x0)) {
        local_38[0x1d] = 0;
        local_38[0x1e] = 0;
        local_38[0x1f] = 0;
        local_38[0x20] = 0;
      }
      else {
        local_68 = local_68 + 3;
        if (local_30 - local_68 < *local_44 + *(int *)(iVar7 + 0xb0)) {
          local_3c = local_3c + (int)local_2c;
          local_30 = (*local_44 - *(int *)(iVar7 + 0xb0)) + *(int *)(iVar7 + 0xa8);
          local_2c = (int *)0x0;
        }
        local_18.left = local_30 - local_68;
        local_18.right = local_18.left + local_68;
        local_18.bottom = (int)local_64 + local_3c;
        local_38[0x1d] = local_18.left;
        local_38[0x1e] = local_3c;
        local_38[0x1f] = local_18.right;
        local_38[0x20] = local_18.bottom;
        if ((int)local_2c <= (int)local_64) {
          local_2c = local_64;
        }
        local_30 = local_18.left + -4;
        iVar7 = local_34;
        local_18.top = local_3c;
      }
      local_4c = local_4c + 1;
    } while (local_4c < *(int *)(iVar7 + 0x4f0));
    local_38 = (int *)((int)local_2c + local_3c);
  }
  iVar6 = 0;
  if (0 < *(int *)(iVar7 + 0x4e4)) {
    do {
      puVar4 = (undefined4 *)FUN_00799cf8(iVar6);
      pcVar2 = *(code **)(*(int *)*puVar4 + 0x124);
      guard_check_icall(local_40);
      (*pcVar2)();
      iVar6 = local_6c + 1;
      iVar7 = local_34;
      local_6c = iVar6;
    } while (iVar6 < *(int *)(local_34 + 0x4e4));
  }
  *(LONG *)(iVar7 + 0xcc) = *local_44;
  *(LONG *)(iVar7 + 0xd0) = local_44[1];
  *(LONG *)(iVar7 + 0xd4) = local_44[2];
  *(LONG *)(iVar7 + 0xd8) = local_44[3];
  *(int *)(local_34 + 0xd8) = *(int *)(local_34 + 0xd0) + *(int *)(local_34 + 0xb4) + (int)local_38;
  *(LONG *)(local_34 + 0xd4) =
       *(LONG *)(iVar7 + 0xcc) + *(int *)(local_34 + 0xb0) + *(int *)(local_34 + 0xa8);
  return;
}



