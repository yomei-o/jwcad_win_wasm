/* CMFCRibbonPanel -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonPanel[1] */
/* 0086a317  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonPanel::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCRibbonPanel::_scalar_deleting_destructor_(CMFCRibbonPanel *this,uint param_1)

{
  FUN_0086a1db();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x4f0);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonPanel[51] */
/* 0086a34a  FUN_0086a34a  42 bytes, 0 callers */

void FUN_0086a34a(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xd4);
  guard_check_icall(param_1,in_ECX[0x139]);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonPanel[44] */
/* 0086a87a  FUN_0086a87a  396 bytes, 1 callers */

void FUN_0086a87a(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  int local_8;
  
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xfc),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0xfc));
  *(undefined4 *)(in_ECX + 0x100) = *(undefined4 *)(param_1 + 0x100);
  iVar4 = 0;
  *(undefined4 *)(in_ECX + 0x108) = *(undefined4 *)(param_1 + 0x108);
  *(undefined4 *)(in_ECX + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(in_ECX + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(param_1 + 0x90);
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x4d0)) {
    do {
      puVar2 = (undefined4 *)FUN_005db5d0(iVar4);
      FUN_0042f500(*(undefined4 *)(in_ECX + 0x4d0),*puVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x4d0));
  }
  if (0 < *(int *)(param_1 + 0x4e4)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      puVar2 = (undefined4 *)*puVar2;
      pcVar1 = *(code **)*puVar2;
      guard_check_icall();
      (*pcVar1)();
      piVar3 = (int *)FUN_0079d90c();
      pcVar1 = *(code **)(*piVar3 + 0x168);
      guard_check_icall(puVar2);
      (*pcVar1)();
      pcVar1 = *(code **)(*piVar3 + 0x170);
      guard_check_icall(puVar2);
      (*pcVar1)();
      FUN_0079c90d(*(undefined4 *)(in_ECX + 0x4e4),piVar3);
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(param_1 + 0x4e4));
  }
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x114) + 0x168);
  guard_check_icall(param_1 + 0x114);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x114) + 0x170);
  guard_check_icall(param_1 + 0x114);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonPanel[58] */
/* 0086aa99  FUN_0086aa99  927 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0086aa99(int *param_1)

{
  RECT *lprc;
  RECT *lprc_00;
  code *pcVar1;
  BOOL BVar2;
  COLORREF CVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  undefined4 uVar8;
  int local_44;
  RECT local_38;
  tagRECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  lprc = (RECT *)(in_ECX + 0xcc);
  local_18.left = IsRectEmpty(lprc);
  if (local_18.left == 0) {
    pcVar1 = *(code **)(*param_1 + 0x50);
    local_18.top = local_18.left;
    local_18.right = local_18.left;
    local_18.bottom = local_18.left;
    guard_check_icall(&local_18);
    (*pcVar1)();
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    BVar2 = IntersectRect(&local_28,(RECT *)(in_ECX + 0xcc),&local_18);
    if (BVar2 != 0) {
      CVar3 = GetTextColor((HDC)param_1[2]);
      if ((*(int *)(in_ECX + 0x108) == 0) || (*(int *)(in_ECX + 0x110) != 0)) {
        iVar6 = FUN_007c2511();
        uVar5 = *(undefined4 *)(iVar6 + 0x68);
      }
      else {
        piVar4 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar4 + 0x220);
        guard_check_icall(param_1,in_ECX,lprc->left,*(undefined4 *)(in_ECX + 0xd0),
                          *(undefined4 *)(in_ECX + 0xd4),*(undefined4 *)(in_ECX + 0xd8),
                          *(undefined4 *)(in_ECX + 0xbc),*(undefined4 *)(in_ECX + 0xc0),
                          *(undefined4 *)(in_ECX + 0xc4),*(undefined4 *)(in_ECX + 200));
        uVar5 = (*pcVar1)();
      }
      lprc_00 = (RECT *)(in_ECX + 0xbc);
      BVar2 = IsRectEmpty(lprc_00);
      if ((BVar2 == 0) && (BVar2 = IntersectRect(&local_28,lprc_00,&local_18), BVar2 != 0)) {
        piVar4 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar4 + 0x224);
        guard_check_icall(param_1,in_ECX,lprc_00->left,*(undefined4 *)(in_ECX + 0xc0),
                          *(undefined4 *)(in_ECX + 0xc4),*(undefined4 *)(in_ECX + 200));
        (*pcVar1)();
      }
      local_38.left = *(LONG *)(in_ECX + 0x188);
      local_38.top = *(LONG *)(in_ECX + 0x18c);
      local_38.right = *(LONG *)(in_ECX + 400);
      local_38.bottom = *(LONG *)(in_ECX + 0x194);
      BVar2 = IntersectRect(&local_28,&local_38,&local_18);
      if (BVar2 != 0) {
        pcVar1 = *(code **)(*(int *)(in_ECX + 0x114) + 0x17c);
        guard_check_icall(param_1);
        (*pcVar1)();
      }
      pcVar1 = *(code **)(*param_1 + 0x30);
      guard_check_icall(uVar5);
      (*pcVar1)();
      local_38.left = *(int *)(in_ECX + 0x354);
      local_38.top = *(int *)(in_ECX + 0x358);
      local_38.right = *(int *)(in_ECX + 0x35c);
      local_38.bottom = *(int *)(in_ECX + 0x360);
      BVar2 = IsRectEmpty(&local_38);
      if (BVar2 == 0) {
        local_38.left = *(int *)(in_ECX + 0x354);
        local_38.top = *(int *)(in_ECX + 0x358);
        local_38.right = *(int *)(in_ECX + 0x35c);
        local_38.bottom = *(int *)(in_ECX + 0x360);
        BVar2 = IntersectRect(&local_28,&local_38,&local_18);
        if (BVar2 != 0) {
          pcVar1 = *(code **)(*(int *)(in_ECX + 0x2e0) + 0x17c);
          guard_check_icall(param_1);
          (*pcVar1)();
        }
      }
      else if (*(int *)(in_ECX + 0x110) == 0) {
        if ((*(int *)(in_ECX + 0x7c) != 0) && (iVar6 = *(int *)(in_ECX + 0x10c), iVar6 != 0)) {
          uVar8 = *(undefined4 *)(iVar6 + 0xd40);
          *(undefined4 *)(iVar6 + 0xd40) = 0;
          piVar4 = (int *)FUN_007c2574();
          pcVar1 = *(code **)(*piVar4 + 0x34);
          guard_check_icall(param_1,*(undefined4 *)(in_ECX + 0x10c),lprc->left,
                            *(undefined4 *)(in_ECX + 0xd0),*(undefined4 *)(in_ECX + 0xd4),
                            *(undefined4 *)(in_ECX + 0xd8),lprc->left,*(undefined4 *)(in_ECX + 0xd0)
                            ,*(undefined4 *)(in_ECX + 0xd4),*(undefined4 *)(in_ECX + 0xd8),0);
          (*pcVar1)();
          *(undefined4 *)(*(int *)(in_ECX + 0x10c) + 0xd40) = uVar8;
        }
        local_44 = 0;
        if (0 < *(int *)(in_ECX + 0x4e4)) {
          do {
            piVar4 = (int *)FUN_00799cf8(local_44);
            piVar4 = (int *)*piVar4;
            local_38.left = piVar4[0x1d];
            local_38.top = piVar4[0x1e];
            local_38.right = piVar4[0x1f];
            local_38.bottom = piVar4[0x20];
            BVar2 = IntersectRect(&local_28,&local_38,&local_18);
            if (BVar2 != 0) {
              pcVar1 = *(code **)(*param_1 + 0x30);
              uVar8 = uVar5;
              guard_check_icall(uVar5);
              (*pcVar1)();
              iVar6 = piVar4[0x32];
              if (*(int *)(in_ECX + 0x78) != 0) {
                pcVar1 = *(code **)(*piVar4 + 0xe4);
                guard_check_icall(uVar8);
                iVar7 = (*pcVar1)();
                if ((iVar7 != 0) && (*(int *)(in_ECX + 0x2dc) == 0)) {
                  piVar4[0x32] = 1;
                }
              }
              pcVar1 = *(code **)(*piVar4 + 0x17c);
              guard_check_icall(param_1);
              (*pcVar1)();
              piVar4[0x32] = iVar6;
            }
            local_44 = local_44 + 1;
          } while (local_44 < *(int *)(in_ECX + 0x4e4));
        }
      }
      else {
        FUN_0086cad4(param_1);
      }
      pcVar1 = *(code **)(*param_1 + 0x30);
      guard_check_icall(CVar3);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonPanel[0] */
/* 0086bd2f  FUN_0086bd2f  6 bytes, 0 callers */

undefined ** FUN_0086bd2f(void)

{
  return &PTR_s_CMFCRibbonPanel_00998c78;
}




/* vtable slots: CMFCRibbonPanel[70] */
/* 0086c5ed  FUN_0086c5ed  269 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0086c5ed(LONG param_1,LONG param_2)

{
  code *pcVar1;
  POINT pt;
  int iVar2;
  CObject *pCVar3;
  BOOL BVar4;
  HWND hWnd;
  int *in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  in_ECX[0x28] = 1;
  if ((int *)in_ECX[0xb7] == (int *)0x0) goto LAB_0086c6e4;
  pcVar1 = *(code **)(*(int *)in_ECX[0xb7] + 0x138);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if ((iVar2 == 0) ||
     (pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButton_00998478,
                                  (CObject *)in_ECX[0xb7]), pCVar3 == (CObject *)0x0)) {
LAB_0086c677:
    *(undefined4 *)(in_ECX[0xb7] + 0xd0) = 1;
    pcVar1 = *(code **)(*in_ECX + 0x108);
    guard_check_icall(in_ECX[0xb7]);
    (*pcVar1)();
  }
  else {
    local_18.left = *(LONG *)(pCVar3 + 0x134);
    local_18.top = *(LONG *)(pCVar3 + 0x138);
    local_18.right = *(LONG *)(pCVar3 + 0x13c);
    local_18.bottom = *(LONG *)(pCVar3 + 0x140);
    BVar4 = IsRectEmpty(&local_18);
    if ((BVar4 == 0) && (pt.y = param_2, pt.x = param_1, BVar4 = PtInRect(&local_18,pt), BVar4 != 0)
       ) goto LAB_0086c677;
  }
  hWnd = (HWND)0x0;
  if (in_ECX[0x43] != 0) {
    hWnd = *(HWND *)(in_ECX[0x43] + 0x20);
  }
  pcVar1 = *(code **)(*(int *)in_ECX[0xb7] + 0x210);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  if ((hWnd != (HWND)0x0) && (BVar4 = IsWindow(hWnd), BVar4 == 0)) {
    return 0;
  }
LAB_0086c6e4:
  return in_ECX[0xb7];
}




/* vtable slots: CMFCRibbonPanel[50] */
/* 0086dc9a  FUN_0086dc9a  722 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0086dc9a(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  int iVar3;
  undefined1 local_40 [4];
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  int local_28 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_30 = param_1;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  SystemParametersInfoW(0x30,0,local_28,0);
  pcVar1 = *(code **)(in_ECX[0xb8] + 0x180);
  guard_check_icall(param_1);
  (*pcVar1)();
  pcVar1 = *(code **)(in_ECX[0xb8] + 0xf8);
  guard_check_icall(local_40,local_30);
  piVar2 = (int *)(*pcVar1)();
  iVar3 = *piVar2;
  local_38 = iVar3;
  FUN_0042fb40(0,0xffffffff);
  RemoveAll();
  in_ECX[0x29] = 0;
  local_2c = 1;
  in_ECX[0x1b] = 1;
  local_34 = -1;
  if ((in_ECX[0x1c] == 0) || (in_ECX[0x20] != 0)) {
    if (in_ECX[0x21] == 0) {
      local_3c = iVar3 + 1;
      do {
        local_28[4] = 0;
        local_28[5] = 0;
        local_28[7] = param_2;
        iVar3 = local_3c;
        local_28[6] = local_3c;
        while (iVar3 < local_28[2] - local_28[0]) {
          pcVar1 = *(code **)(*in_ECX + 0xec);
          guard_check_icall(local_30,local_28 + 4);
          (*pcVar1)();
          if ((local_34 != -1) && (local_34 < in_ECX[0x2a])) goto LAB_0086dee2;
          if ((in_ECX[0x2b] == local_2c) && (iVar3 = in_ECX[0x2a], 0 < iVar3)) {
            if ((in_ECX[0x2b] == 2) && (in_ECX[0x20] == 0)) {
              FUN_0042fb40(0,0xffffffff);
              iVar3 = in_ECX[0x2a];
            }
            FUN_0042f500(in_ECX[0x134],iVar3);
            iVar3 = local_28[6] - local_28[4];
            piVar2 = (int *)FUN_007e3332(in_ECX[0x2c] + in_ECX[0x2a]);
            *piVar2 = iVar3;
            local_34 = in_ECX[0x2a];
            goto LAB_0086dee2;
          }
          local_28[6] = local_28[6] + 0x10;
          iVar3 = local_28[6] - local_28[4];
        }
        if (in_ECX[0x134] == 0) {
          FUN_0042f500(in_ECX[0x134],0x7fff);
        }
LAB_0086dee2:
        local_2c = local_2c + 1;
      } while (local_2c < 4);
    }
    else {
      local_28[4] = 0;
      local_28[5] = 0;
      local_28[6] = (local_28[2] - local_28[0]) + -10;
      local_28[7] = param_2;
      pcVar1 = *(code **)(*in_ECX + 0xec);
      guard_check_icall(local_30,local_28 + 4);
      (*pcVar1)();
      FUN_0042f500(in_ECX[0x134],in_ECX[0x2a]);
    }
  }
  else {
    local_28[4] = 0;
    local_28[5] = 0;
    local_28[6] = 0x7fff;
    local_28[7] = param_2;
    do {
      pcVar1 = *(code **)(*in_ECX + 0xec);
      guard_check_icall(local_30,local_28 + 4);
      (*pcVar1)();
      if (in_ECX[0x18] == 0) break;
      if ((local_34 == -1) || (in_ECX[0x2a] < local_34)) {
        iVar3 = in_ECX[0x2a];
        local_34 = iVar3;
        if ((iVar3 <= local_38) || ((iVar3 <= (local_38 * 3) / 2 && (in_ECX[0x139] == 1)))) {
          if (in_ECX[0x134] == 0) goto LAB_0086def5;
          break;
        }
        FUN_0042f500(in_ECX[0x134],iVar3);
        local_28[6] = iVar3;
      }
      local_28[6] = local_28[6] + -0x10;
    } while (in_ECX[0x2c] * 2 < local_28[6] - local_28[4]);
  }
  iVar3 = local_38;
LAB_0086def5:
  FUN_0042f500(in_ECX[0x134],iVar3);
  in_ECX[0x1b] = 0;
  return;
}




/* vtable slots: CMFCRibbonPanel[59] */
/* 0086edc4  FUN_0086edc4  6493 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0086edc4(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  code *pcVar7;
  int *piVar8;
  int **ppiVar9;
  undefined4 uVar10;
  undefined **local_130 [7];
  int *local_114;
  int *local_110;
  int *local_10c;
  int *local_108;
  int *local_104;
  int local_100;
  int local_fc;
  int *local_f8;
  int *local_f4;
  int *local_f0;
  int *local_ec;
  int *local_e8;
  int *local_e4;
  int *local_e0;
  int *local_dc;
  undefined4 local_d8;
  int *local_d4;
  int *local_d0;
  int local_cc;
  int *local_c8;
  int *local_c4;
  int *local_c0;
  int *local_bc;
  int local_b8;
  int *local_b4;
  int *local_b0;
  int *local_ac;
  RECT local_a8;
  RECT local_98;
  RECT local_88;
  RECT local_78;
  RECT local_68;
  RECT local_58;
  undefined **local_48;
  RECT local_44;
  RECT local_34;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x148;
  local_8 = 0x86edd3;
  local_d0 = param_2;
  local_d8 = param_1;
  local_b0 = in_ECX;
  SetRectEmpty((LPRECT)(in_ECX + 0x2f));
  SetRectEmpty((LPRECT)(in_ECX + 0x37));
  SetRectEmpty((LPRECT)(in_ECX + 0x3b));
  if (in_ECX[0x44] == 0) {
    if (in_ECX[0x1e] == 0) {
      in_ECX[0xda] = in_ECX[0x42];
      in_ECX[0x67] = in_ECX[0x42];
      in_ECX[0xb6] = (int)in_ECX;
      pcVar7 = *(code **)(in_ECX[0xb8] + 0x180);
      guard_check_icall(local_d8);
      (*pcVar7)();
      pcVar7 = *(code **)(in_ECX[0xb8] + 0xf8);
      guard_check_icall(&local_f8,local_d8);
      puVar1 = (undefined4 *)(*pcVar7)();
      piVar5 = local_b0;
      local_114 = (int *)*puVar1;
      in_ECX[0x33] = *local_d0;
      in_ECX[0x34] = local_d0[1];
      in_ECX[0x35] = local_d0[2];
      in_ECX[0x36] = local_d0[3];
      local_b0[0x62] = 0;
      local_b0[99] = 0;
      local_b0[100] = 0;
      local_b0[0x65] = 0;
      if (local_b0[0x19] != 0) {
        FUN_00870d6f(local_d8);
        goto LAB_00870719;
      }
      local_b0[0xd5] = 0;
      local_b0[0xd6] = 0;
      local_b0[0xd7] = 0;
      local_b0[0xd8] = 0;
      local_b0[0x2a] = 0;
      local_b0[0x2b] = 0;
      local_b0[0x18] = 1;
      FUN_0086b0ef(&local_f8,local_d8);
      local_110 = local_f8;
      if (piVar5[0x27] == 0) {
        piVar4 = (int *)(local_d0[2] - *local_d0);
        if (local_d0[2] - *local_d0 <= (int)local_f8) {
          piVar4 = local_f8;
        }
        piVar5[0x35] = piVar5[0x33] + (int)piVar4;
      }
      local_d4 = (int *)(((local_d0[3] - local_d0[1]) - piVar5[0x2d]) - (int)local_f4);
      local_e8 = (int *)((local_d0[2] - *local_d0) - piVar5[0x2c]);
      local_f0 = local_f4;
      local_c4 = (int *)0x0;
      if (0 < piVar5[0x139]) {
        do {
          puVar1 = (undefined4 *)FUN_00799cf8(local_c4);
          local_ac = (int *)*puVar1;
          pcVar7 = *(code **)(*local_ac + 0x180);
          guard_check_icall(local_d8);
          (*pcVar7)();
          if (piVar5[0x20] != 0) {
            pcVar7 = *(code **)(*local_ac + 0xec);
          }
          else {
            pcVar7 = *(code **)(*local_ac + 0x110);
          }
          guard_check_icall(piVar5[0x20] != 0);
          (*pcVar7)();
          iVar3 = piVar5[0x20];
          local_ac[0x2a] = -1;
          local_ac[0x30] = iVar3;
          local_c4 = (int *)((int)local_c4 + 1);
        } while ((int)local_c4 < piVar5[0x139]);
      }
      local_ac = (int *)0x0;
      if ((piVar5[0x1c] != 0) && (piVar5[0x20] == 0)) {
LAB_0086f086:
        while( true ) {
          local_b8 = 0;
          local_bc = (int *)0x0;
          local_b4 = (int *)0x0;
          CMap<>(10);
          piVar4 = (int *)piVar5[0x139];
          local_8 = 1;
          local_cc = 0;
          piVar8 = (int *)0x0;
          if (0 < (int)piVar4) {
            do {
              puVar1 = (undefined4 *)FUN_00799cf8(local_cc);
              local_ac = (int *)*puVar1;
              pcVar7 = *(code **)(*local_ac + 0xf4);
              guard_check_icall(&local_e0,local_d8);
              (*pcVar7)();
              if ((local_e0 == (int *)0x0) && (local_dc == (int *)0x0)) {
                local_ac[0x1d] = 0;
                local_ac[0x1e] = 0;
                local_ac[0x1f] = 0;
                local_ac[0x20] = 0;
              }
              else {
                pcVar7 = *(code **)(*local_ac + 0x118);
                guard_check_icall();
                iVar3 = (*pcVar7)();
                if (iVar3 == 0) {
                  pcVar7 = *(code **)(*local_ac + 0x144);
                  guard_check_icall();
                  iVar3 = (*pcVar7)();
                  piVar4 = local_ac;
                  if (iVar3 != 0) {
                    local_dc = local_d4;
                  }
                  if ((int)local_d4 < (int)local_dc + (int)local_bc) {
                    if (local_bc == (int *)0x0) goto LAB_0086f990;
                    local_b8 = local_b8 + (int)local_b4;
                    local_bc = (int *)0x0;
                    local_b4 = (int *)0x0;
                  }
                  local_c4 = (int *)(*local_d0 + piVar5[0x2c] + local_b8);
                  local_24.top = piVar5[0x2d] + local_d0[1] + (int)local_bc;
                  local_24.right = (int)local_e0 + (int)local_c4;
                  local_24.bottom = (int)local_dc + local_24.top;
                  local_ac = (int *)0x1;
                  piVar4[0x1d] = (int)local_c4;
                  piVar4[0x1e] = local_24.top;
                  piVar4[0x1f] = local_24.right;
                  piVar4[0x20] = local_24.bottom;
                  local_24.left = (LONG)local_c4;
                  iVar3 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                                    ((CMap<unsigned_int,unsigned_int,int,int> *)local_130,
                                     (uint)local_c4,(int *)&local_ac);
                  piVar5 = local_ac;
                  if (iVar3 != 0) {
                    piVar5 = (int *)((int)local_ac + 1);
                  }
                  puVar1 = (undefined4 *)FUN_007e3332(local_c4);
                  *puVar1 = piVar5;
                  if ((int)local_b4 <= (int)local_e0) {
                    local_b4 = local_e0;
                  }
                  local_bc = (int *)((int)local_bc + (int)local_dc);
                  piVar5 = local_b0;
                }
                else {
                  local_fc = piVar5[0x2d] + local_d0[1];
                  local_100 = (int)local_b4 + *local_d0 + piVar5[0x2c] + local_b8;
                  local_f8 = (int *)((int)local_e0 + local_100);
                  local_f4 = (int *)((int)local_d4 + local_fc);
                  local_ac[0x1d] = local_100;
                  local_ac[0x1e] = local_fc;
                  local_ac[0x1f] = (int)local_f8;
                  local_ac[0x20] = (int)local_f4;
                  local_b8 = (int)local_b4 + (int)local_e0 + local_b8 + local_b0[0x2c];
                  local_bc = (int *)0x0;
                  local_b4 = (int *)0x0;
                  piVar5 = local_b0;
                }
              }
              piVar4 = (int *)piVar5[0x139];
              local_cc = local_cc + 1;
              piVar8 = local_b4;
            } while (local_cc < (int)piVar4);
          }
          if (local_b8 + (int)piVar8 <= (int)local_e8) {
            piVar5[0x2a] = local_b8 + (int)piVar8;
            local_8 = 3;
            local_130[0] = CMap<int,int,int,int>::vftable;
            RemoveAll();
            local_8 = 0xffffffff;
            goto LAB_00870244;
          }
          if (piVar8 == (int *)0x0) break;
          local_b8 = 0;
          local_c4 = (int *)0x0;
          if (0 < (int)piVar4) {
            do {
              if (local_b8 != 0) goto LAB_0086f421;
              local_c0 = (int *)FUN_00799cf8(local_c4);
              local_c0 = (int *)*local_c0;
              local_58.left = local_c0[0x1d];
              local_58.top = local_c0[0x1e];
              local_58.right = local_c0[0x1f];
              local_58.bottom = local_c0[0x20];
              BVar2 = IsRectEmpty(&local_58);
              piVar5 = local_c0;
              if (BVar2 == 0) {
                pcVar7 = *(code **)(*local_c0 + 0x18c);
                guard_check_icall();
                iVar3 = (*pcVar7)();
                if (iVar3 != 0) {
                  pcVar7 = *(code **)(*piVar5 + 400);
                  guard_check_icall();
                  (*pcVar7)();
                  local_b8 = 1;
                }
              }
              local_c4 = (int *)((int)local_c4 + 1);
              piVar4 = (int *)local_b0[0x139];
              piVar5 = local_b0;
            } while ((int)local_c4 < (int)piVar4);
            if (local_b8 == 0) goto LAB_0086f444;
LAB_0086f421:
            local_8 = 5;
            goto LAB_0086f428;
          }
LAB_0086f444:
          local_bc = (int *)0x0;
          local_c4 = (int *)0x3;
          if ((int)piVar4 < 4) {
            local_c4 = piVar4;
          }
          local_b4 = (int *)((int)piVar4 + -1);
          do {
            if ((int)local_b4 < 0) break;
            local_c8 = piVar5 + 0x137;
            puVar1 = (undefined4 *)FUN_00799cf8(local_b4);
            local_c0 = (int *)*puVar1;
            local_a8.left = local_c0[0x1d];
            local_a8.top = local_c0[0x1e];
            local_a8.right = local_c0[0x1f];
            local_a8.bottom = local_c0[0x20];
            BVar2 = IsRectEmpty(&local_a8);
            piVar5 = local_c0;
            if (BVar2 == 0) {
              iVar3 = FUN_0086c47d();
              if (iVar3 != 0) {
                pcVar7 = *(code **)(*piVar5 + 0xf0);
                guard_check_icall();
                iVar3 = (*pcVar7)();
                if (iVar3 != 0) {
                  local_bc = (int *)((int)local_bc + 1);
                  if (local_bc == local_c4) {
                    local_ac = (int *)0x0;
                    local_b8 = 1;
                    if (0 < (int)local_bc) {
                      do {
                        puVar1 = (undefined4 *)FUN_00799cf8((int)local_ac + (int)local_b4);
                        local_c0 = (int *)*puVar1;
                        local_98.left = local_c0[0x1d];
                        local_98.top = local_c0[0x1e];
                        local_98.right = local_c0[0x1f];
                        local_98.bottom = local_c0[0x20];
                        BVar2 = IsRectEmpty(&local_98);
                        if (BVar2 == 0) {
                          pcVar7 = *(code **)(*local_c0 + 0xec);
                          guard_check_icall(1);
                          (*pcVar7)();
                        }
                        else {
                          local_ac = (int *)((int)local_ac + 1);
                        }
                        local_ac = (int *)((int)local_ac + 1);
                      } while ((int)local_ac < (int)local_bc);
                    }
                  }
                  goto LAB_0086f58f;
                }
              }
              local_bc = (int *)0x0;
            }
LAB_0086f58f:
            local_b4 = (int *)((int)local_b4 + -1);
            piVar5 = local_b0;
          } while (local_b8 == 0);
          if (local_b8 == 0) {
            local_ac = (int *)0xffffffff;
            local_bc = (int *)0x0;
            local_ec = (int *)(local_b0[0x139] + -1);
            do {
              if ((int)local_ec < 0) {
                local_bc = (int *)(uint)(2 < local_b0[0x139]);
                piVar5 = local_b0;
                local_ac = local_bc;
                if (local_b0[0x139] <= (int)local_bc) goto LAB_0086f8dd;
                local_c4 = local_b0 + 0x137;
                goto LAB_0086f78d;
              }
              local_c8 = local_b0 + 0x137;
              puVar1 = (undefined4 *)FUN_00799cf8(local_ec);
              local_c0 = (int *)*puVar1;
              local_c4 = local_c0 + 0x1d;
              local_88.left = *local_c4;
              local_88.top = local_c0[0x1e];
              local_88.right = local_c0[0x1f];
              local_88.bottom = local_c0[0x20];
              BVar2 = IsRectEmpty(&local_88);
              if (BVar2 == 0) {
                if (((local_ac == (int *)0xffffffff) || ((int *)*local_c4 == local_ac)) &&
                   (local_ac = (int *)*local_c4, local_c0[0x2f] != 0)) {
                  pcVar7 = *(code **)(*local_c0 + 0x10c);
                  guard_check_icall();
                  iVar3 = (*pcVar7)();
                  if (iVar3 != 0) {
                    local_bc = (int *)((int)local_bc + 1);
                    if (local_bc == (int *)0x3) {
                      local_b8 = 1;
                      local_b4 = (int *)0x0;
                      do {
                        puVar1 = (undefined4 *)FUN_00799cf8((int)local_b4 + (int)local_ec);
                        local_c0 = (int *)*puVar1;
                        local_44.left = local_c0[0x1d];
                        local_44.top = local_c0[0x1e];
                        local_44.right = local_c0[0x1f];
                        local_44.bottom = local_c0[0x20];
                        BVar2 = IsRectEmpty(&local_44);
                        if (BVar2 == 0) {
                          pcVar7 = *(code **)(*local_c0 + 0xec);
                          guard_check_icall(1);
                          (*pcVar7)();
                        }
                        else {
                          local_b4 = (int *)((int)local_b4 + 1);
                        }
                        local_b4 = (int *)((int)local_b4 + 1);
                      } while ((int)local_b4 < 3);
                    }
                    goto LAB_0086f72a;
                  }
                }
                local_ac = (int *)0xffffffff;
                local_bc = (int *)0x0;
              }
LAB_0086f72a:
              local_ec = (int *)((int)local_ec + -1);
            } while (local_b8 == 0);
            local_8 = 7;
          }
          else {
            local_8 = 6;
          }
LAB_0086f88b:
          local_130[0] = CMap<int,int,int,int>::vftable;
          RemoveAll();
          piVar5 = local_b0;
        }
        goto LAB_0086f990;
      }
      local_c4 = (int *)piVar5[0x36];
      local_b8 = 0;
      local_cc = 0;
      local_108 = (int *)0x0;
      local_e4 = (int *)0x0;
      if ((piVar5[0x1b] == 0) &&
         (iVar3 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                            ((CMap<unsigned_int,unsigned_int,int,int> *)(piVar5 + 299),
                             (uint)local_e8,(int *)&local_e4), iVar3 != 0)) {
        local_e8 = local_e4;
      }
      local_48 = CArray<int,int>::vftable;
      local_44.left = 0;
      local_44.bottom = 0;
      local_44.right = 0;
      local_e4 = (int *)0x0;
      local_44.top = 0;
      local_8 = 0;
      if (piVar5[0x20] == 0) {
        local_dc = (int *)0x0;
        local_c8 = (int *)0x0;
        local_104 = (int *)0x0;
        local_ec = (int *)0x0;
        local_c0 = (int *)0x0;
        if (0 < piVar5[0x139]) {
          do {
            puVar1 = (undefined4 *)FUN_00799cf8(local_c0);
            local_b4 = (int *)*puVar1;
            pcVar7 = *(code **)(*local_b4 + 0xf4);
            ppiVar9 = &local_f8;
            uVar10 = local_d8;
            guard_check_icall(ppiVar9,local_d8);
            (*pcVar7)();
            pcVar7 = *(code **)(*local_b4 + 0x104);
            guard_check_icall();
            iVar3 = (*pcVar7)();
            if (((iVar3 == 0) || (local_b4[0x2e] != 0)) || (local_b4[0x2f] != 0)) {
              local_10c = (int *)0x0;
            }
            else {
              local_10c = (int *)0x1;
            }
            local_bc = (int *)0x0;
            pcVar7 = *(code **)(*local_b4 + 0x118);
            guard_check_icall(ppiVar9,uVar10);
            iVar3 = (*pcVar7)();
            if (iVar3 != 0) {
              if ((local_dc == (int *)0x0) || (local_c8 != (int *)0x0)) {
                local_bc = (int *)0x0;
              }
              else {
                local_bc = (int *)0x1;
              }
            }
            if ((local_10c != (int *)0x0) || (local_bc != (int *)0x0)) {
              pcVar7 = *(code **)(*local_b4 + 0x118);
              guard_check_icall();
              iVar3 = (*pcVar7)();
              if (iVar3 == 0) {
                local_104 = local_f8;
                local_ec = local_f4;
              }
              else if ((local_104 != (int *)0x0) || (local_ec != (int *)0x0)) {
                local_f4 = local_ec;
              }
              piVar4 = local_f4;
              if (local_c4 != (int *)0x7fff) {
                piVar4 = local_d4;
              }
              local_24.top = local_d0[1];
              local_24.left = *local_d0 + piVar5[0x2c] + (int)local_ac;
              local_24.right = local_24.left + (int)local_f8;
              local_24.bottom = local_24.top + (int)piVar4;
              local_b4[0x2a] = 999;
              local_b4[0x1d] = local_24.left;
              local_b4[0x1e] = local_24.top;
              local_b4[0x1f] = local_24.right;
              local_b4[0x20] = local_24.bottom;
              local_108 = (int *)((int)local_ac + local_b0[0x2c] + (int)local_f8);
              piVar5 = local_b0;
              local_ac = local_108;
            }
            local_c0 = (int *)((int)local_c0 + 1);
            local_dc = local_10c;
            local_c8 = local_bc;
          } while ((int)local_c0 < piVar5[0x139]);
        }
      }
      local_c0 = (int *)0x0;
      if (0 < piVar5[0x139]) {
        local_bc = (int *)0x0;
        do {
          puVar1 = (undefined4 *)FUN_00799cf8(local_c0);
          local_b4 = (int *)*puVar1;
          pcVar7 = *(code **)(*local_b4 + 0xf4);
          guard_check_icall(&local_34.right,local_d8);
          (*pcVar7)();
          if ((local_34.right == 0) && (local_34.bottom == 0)) {
LAB_0086fcdb:
            local_b4[0x1d] = 0;
            local_b4[0x1e] = 0;
            local_b4[0x1f] = 0;
            local_b4[0x20] = 0;
          }
          else if (local_b4[0x2a] == -1) {
            pcVar7 = *(code **)(*local_b4 + 0x118);
            guard_check_icall();
            iVar3 = (*pcVar7)();
            if (iVar3 != 0) goto LAB_0086fcdb;
            piVar4 = local_bc;
            if ((int)local_e8 < piVar5[0x2c] + -1 + local_34.right + (int)local_ac) {
              if (local_ac != local_108) {
                piVar4 = (int *)((int)local_bc + local_b8);
                if (piVar5[0x20] != 0) {
                  piVar4 = (int *)((int)piVar4 + piVar5[0x2d]);
                }
                local_bc = piVar4;
                FUN_0042f500(local_e4,local_ac);
                piVar5[0x2b] = piVar5[0x2b] + 1;
                local_b8 = 0;
                local_ac = local_108;
                local_e4 = (int *)local_44.top;
                goto LAB_0086fdb1;
              }
            }
            else {
LAB_0086fdb1:
              if (local_34.bottom + (int)piVar4 <= (int)local_d4) {
                local_24.top = piVar5[0x2d] + local_d0[1] + (int)piVar4;
                local_24.left = *local_d0 + piVar5[0x2c] + (int)local_ac;
                local_24.right = local_24.left + local_34.right;
                local_24.bottom = local_34.bottom + local_24.top;
                local_b4[0x1d] = local_24.left;
                local_b4[0x1e] = local_24.top;
                local_b4[0x1f] = local_24.right;
                local_b4[0x20] = local_24.bottom;
                local_b4[0x2a] = local_b0[0x2b];
                if (local_b8 <= local_34.bottom) {
                  local_b8 = local_34.bottom;
                }
                local_ac = (int *)((int)local_ac + local_b0[0x2c] + local_34.right + -1);
                iVar3 = local_b0[0x2a];
                if (local_b0[0x2a] <= (int)local_ac + -1) {
                  iVar3 = (int)local_ac + -1;
                }
                local_b0[0x2a] = iVar3;
                piVar5 = local_b0;
                if (local_cc <= local_24.bottom) {
                  local_cc = local_24.bottom;
                }
                goto LAB_0086fe63;
              }
            }
            FUN_00870d6f(local_d8);
            if (local_44.left != 0) {
              thunk_FUN_008f43b0(local_44.left);
            }
            goto LAB_00870719;
          }
LAB_0086fe63:
          local_c0 = (int *)((int)local_c0 + 1);
        } while ((int)local_c0 < piVar5[0x139]);
      }
      FUN_0042f500(local_e4,local_ac);
      iVar3 = piVar5[0x2b];
      piVar5[0x2b] = iVar3 + 1;
      if (local_c4 == (int *)0x7fff) {
        iVar6 = local_cc + piVar5[0x2d] + (int)local_f0;
        piVar5[0x36] = iVar6;
        local_d4 = (int *)(((iVar6 - piVar5[0x34]) - piVar5[0x2d]) - (int)local_f0);
      }
      if ((piVar5[0x21] == 0) && (1 < iVar3 + 1)) {
        local_c8 = (int *)0x0;
        while( true ) {
          local_cc = 0;
          piVar4 = (int *)0x0;
          local_ac = (int *)0xffffffff;
          if (local_44.top < 1) break;
          iVar3 = 0;
          do {
            piVar5 = (int *)FUN_005db5d0(piVar4);
            if (iVar3 < *piVar5) {
              piVar5 = (int *)FUN_005db5d0(piVar4);
              iVar3 = *piVar5;
              local_ac = piVar4;
            }
            piVar4 = (int *)((int)piVar4 + 1);
          } while ((int)piVar4 < local_44.top);
          piVar5 = local_b0;
          local_cc = iVar3;
          if ((int)local_ac < 0) break;
          local_d0 = (int *)0x270f;
          piVar4 = (int *)0x0;
          local_c0 = (int *)0x0;
          local_b4 = (int *)0x0;
          if (local_b0[0x139] < 1) break;
          do {
            puVar1 = (undefined4 *)FUN_00799cf8(local_c0);
            local_dc = (int *)*puVar1;
            if ((int *)local_dc[0x2a] == local_ac) {
              local_34.left = local_dc[0x1d];
              local_34.top = local_dc[0x1e];
              local_34.right = local_dc[0x1f];
              local_34.bottom = local_dc[0x20];
              BVar2 = IsRectEmpty(&local_34);
              piVar4 = local_b4;
              piVar5 = local_b0;
              if ((BVar2 == 0) && ((int)(local_34.right - local_34.left) < (int)local_d0)) {
                local_b4 = local_dc;
                piVar4 = local_dc;
                local_d0 = (int *)(local_34.right - local_34.left);
              }
            }
            local_c0 = (int *)((int)local_c0 + 1);
          } while ((int)local_c0 < piVar5[0x139]);
          piVar8 = local_ac;
          if (piVar4 == (int *)0x0) break;
          do {
            piVar8 = (int *)((int)piVar8 + 1);
            local_bc = piVar8;
            if (local_44.top <= (int)piVar8) goto LAB_00870062;
            piVar4 = (int *)FUN_005db5d0(piVar8);
          } while (local_cc <= *piVar4 + (int)local_d0);
          local_cc = 0;
          local_c8 = (int *)0x0;
          local_c0 = (int *)0x0;
          if (0 < piVar5[0x139]) {
            do {
              piVar4 = (int *)FUN_00799cf8(local_c0);
              iVar3 = *piVar4;
              if (*(int **)(iVar3 + 0xa8) == piVar8) {
                local_68.left = *(int *)(iVar3 + 0x74);
                local_68.top = *(int *)(iVar3 + 0x78);
                local_68.right = *(int *)(iVar3 + 0x7c);
                local_68.bottom = *(int *)(iVar3 + 0x80);
                if (local_cc < local_68.right + local_b0[0x2c]) {
                  local_cc = *(int *)(iVar3 + 0x7c) + local_b0[0x2c];
                }
                local_c8 = *(int **)(iVar3 + 0x78);
                piVar8 = local_bc;
                piVar5 = local_b0;
              }
              else if (*(int **)(iVar3 + 0xa8) == local_ac) {
                local_dc = (int *)(iVar3 + 0x74);
                local_58.left = *local_dc;
                local_58.top = *(int *)(iVar3 + 0x78);
                local_58.right = *(int *)(iVar3 + 0x7c);
                local_58.bottom = *(int *)(iVar3 + 0x80);
                local_78.left = local_b4[0x1d];
                local_78.top = local_b4[0x1e];
                local_78.right = local_b4[0x1f];
                local_78.bottom = local_b4[0x20];
                piVar8 = local_bc;
                piVar5 = local_b0;
                if (local_78.left < local_58.left) {
                  OffsetRect(&local_58,-(local_b0[0x2c] + (int)local_d0),0);
                  *local_dc = local_58.left;
                  local_dc[1] = local_58.top;
                  local_dc[2] = local_58.right;
                  local_dc[3] = local_58.bottom;
                  piVar8 = local_bc;
                  piVar5 = local_b0;
                }
              }
              local_c0 = (int *)((int)local_c0 + 1);
            } while ((int)local_c0 < piVar5[0x139]);
          }
          local_24.left = local_b4[0x1d];
          local_24.top = local_b4[0x1e];
          local_24.right = local_b4[0x1f];
          local_24.bottom = local_b4[0x20];
          local_f8 = (int *)((local_24.right - local_24.left) + local_cc);
          local_fc = (int)local_c8;
          local_f4 = (int *)((int)local_c8 + (local_24.bottom - local_24.top));
          local_100 = local_cc;
          local_b4[0x1d] = local_cc;
          local_b4[0x2a] = (int)local_bc;
          local_b4[0x1e] = (int)local_c8;
          local_b4[0x1f] = (int)local_f8;
          local_b4[0x20] = (int)local_f4;
          piVar4 = (int *)FUN_005db5d0(local_bc);
          piVar5 = local_d0;
          *piVar4 = *piVar4 + (int)local_d0;
          piVar4 = (int *)FUN_005db5d0(local_ac);
          local_c8 = (int *)0x1;
          *piVar4 = *piVar4 - (int)piVar5;
          piVar5 = local_b0;
        }
LAB_00870062:
        if (local_c8 != (int *)0x0) {
          piVar5[0x2a] = 0;
          iVar3 = 0;
          local_c0 = (int *)0x0;
          if (0 < piVar5[0x139]) {
            do {
              piVar5 = (int *)FUN_00799cf8(local_c0);
              iVar6 = *piVar5;
              local_68.left = *(int *)(iVar6 + 0x74);
              local_68.top = *(int *)(iVar6 + 0x78);
              local_68.right = *(int *)(iVar6 + 0x7c);
              local_68.bottom = *(int *)(iVar6 + 0x80);
              iVar3 = local_b0[0x2a];
              if (iVar3 <= local_68.right) {
                iVar3 = *(int *)(iVar6 + 0x7c);
              }
              local_c0 = (int *)((int)local_c0 + 1);
              local_b0[0x2a] = iVar3;
              piVar5 = local_b0;
            } while ((int)local_c0 < local_b0[0x139]);
          }
          piVar5[0x2a] = (iVar3 - piVar5[0x33]) - piVar5[0x2c];
        }
      }
      if ((((local_c4 != (int *)0x7fff) && (piVar5[0x20] == 0)) && (iVar3 = piVar5[0x2b], 1 < iVar3)
          ) && ((local_dc = (int *)(((int)local_d4 - iVar3 * local_b8) / (iVar3 + 1)),
                0 < (int)local_dc && (local_c0 = (int *)0x0, 0 < piVar5[0x139])))) {
        do {
          piVar5 = (int *)FUN_00799cf8(local_c0);
          iVar3 = *piVar5;
          local_c8 = *(int **)(iVar3 + 0xa8);
          local_104 = (int *)(iVar3 + 0x74);
          local_58.left = *local_104;
          local_58.top = *(int *)(iVar3 + 0x78);
          local_58.right = *(int *)(iVar3 + 0x7c);
          local_58.bottom = *(int *)(iVar3 + 0x80);
          if ((local_c8 != (int *)0x3e7) && (BVar2 = IsRectEmpty(&local_58), BVar2 == 0)) {
            OffsetRect(&local_58,0,((int)local_c8 + 1) * (int)local_dc - (int)local_c8);
            *local_104 = local_58.left;
            local_104[1] = local_58.top;
            local_104[2] = local_58.right;
            local_104[3] = local_58.bottom;
          }
          local_c0 = (int *)((int)local_c0 + 1);
          piVar5 = local_b0;
        } while ((int)local_c0 < local_b0[0x139]);
      }
      if (((piVar5[0x21] != 0) && (0 < local_b8)) && (0 < piVar5[0x139])) {
        piVar5 = (int *)FUN_00799cf8(piVar5[0x139] + -1);
        iVar3 = *piVar5;
        local_58.left = *(int *)(iVar3 + 0x74);
        local_58.top = *(int *)(iVar3 + 0x78);
        local_58.right = *(int *)(iVar3 + 0x7c);
        local_58.bottom = local_58.top + local_b8;
        *(LONG *)(iVar3 + 0x74) = local_58.left;
        *(LONG *)(iVar3 + 0x78) = local_58.top;
        *(LONG *)(iVar3 + 0x7c) = local_58.right;
        *(LONG *)(iVar3 + 0x80) = local_58.bottom;
        piVar5 = local_b0;
      }
      local_8 = 0xffffffff;
      if (local_44.left != 0) {
        thunk_FUN_008f43b0(local_44.left);
      }
LAB_00870244:
      if (piVar5[0x20] != 0) goto LAB_00870719;
      if (piVar5[0x1c] == 0) {
LAB_00870585:
        piVar4 = (int *)(piVar5[0x2a] + -1);
      }
      else {
        if ((piVar5[0x1d] != 0) || (piVar5[0x24] != 0)) {
          local_e8 = (int *)0x0;
          local_c4 = (int *)0xffffffff;
          local_ac = (int *)0xffffffff;
          local_d4 = (int *)0xffffffff;
          if (0 < piVar5[0x139]) {
            do {
              piVar5 = (int *)FUN_00799cf8(local_e8);
              iVar3 = *piVar5;
              local_24.left = *(undefined4 *)(iVar3 + 0x74);
              local_24.top = *(int *)(iVar3 + 0x78);
              local_24.right = *(int *)(iVar3 + 0x7c);
              local_24.bottom = *(int *)(iVar3 + 0x80);
              BVar2 = IsRectEmpty(&local_24);
              piVar5 = local_b0;
              piVar4 = local_e8;
              if (BVar2 == 0) {
                if (local_ac == (int *)0xffffffff) {
                  local_ac = local_e8;
                  local_d4 = local_e8;
                  local_c4 = (int *)local_24.left;
                }
                if (local_c4 == (int *)local_24.left) {
                  local_d4 = local_e8;
                }
                else {
                  if (local_b0[0x1d] != 0) {
                    FUN_0086a4f6(local_ac,local_d4,local_f0);
                  }
                  if (piVar5[0x24] != 0) {
                    FUN_0086c491(local_ac,local_d4);
                  }
                  local_ac = piVar4;
                  local_d4 = piVar4;
                  local_c4 = (int *)local_24.left;
                }
              }
              local_e8 = (int *)((int)piVar4 + 1);
            } while ((int)local_e8 < piVar5[0x139]);
          }
          if (piVar5[0x1d] != 0) {
            FUN_0086a4f6(local_ac,local_d4,local_f0);
          }
          if (piVar5[0x24] != 0) {
            FUN_0086c491(local_ac,local_d4);
          }
        }
        if ((piVar5[0x1c] == 0) || (piVar5[0x20] != 0)) goto LAB_00870585;
        piVar4 = (int *)FUN_0086a395();
      }
      if (((int)piVar4 < (int)local_110) && (piVar5[0x27] == 0)) {
        local_c8 = (int *)(((int)local_110 - (int)piVar4) / 2);
        local_c0 = (int *)0x0;
        if (0 < piVar5[0x139]) {
          do {
            piVar5 = (int *)FUN_00799cf8(local_c0);
            iVar3 = *piVar5;
            local_dc = (int *)(iVar3 + 0x74);
            local_58.left = *local_dc;
            local_58.top = *(int *)(iVar3 + 0x78);
            local_58.right = *(int *)(iVar3 + 0x7c);
            local_58.bottom = *(int *)(iVar3 + 0x80);
            OffsetRect(&local_58,(int)local_c8,0);
            local_c0 = (int *)((int)local_c0 + 1);
            *local_dc = local_58.left;
            local_dc[1] = local_58.top;
            local_dc[2] = local_58.right;
            local_dc[3] = local_58.bottom;
            piVar5 = local_b0;
          } while ((int)local_c0 < local_b0[0x139]);
        }
        piVar4 = (int *)piVar5[0x2a];
        if (piVar5[0x2a] <= (int)local_110) {
          piVar4 = local_110;
        }
        piVar5[0x2a] = (int)piVar4;
        piVar4 = local_110;
      }
      if (piVar5[0x139] == 0) {
        piVar8 = local_110;
        if ((int)local_110 <= (int)local_114) {
          piVar8 = local_114;
        }
        iVar3 = piVar5[0x2c];
        piVar5[0x2a] = (int)piVar8 + iVar3;
      }
      else {
        iVar3 = piVar5[0x2c];
      }
      if ((int)piVar4 < (int)local_114) {
        iVar3 = piVar5[0x33] + iVar3 + (int)local_114;
      }
      else {
        iVar3 = piVar5[0x33] + iVar3 * 2 + (int)piVar4;
      }
      piVar5[0x35] = iVar3;
      if (piVar5[0x6e] != 0) {
        local_34.left = in_ECX[0x33];
        local_34.top = in_ECX[0x34];
        local_34.right = in_ECX[0x35];
        local_34.bottom = in_ECX[0x36];
        InflateRect(&local_34,-1,-1);
        local_34.top = (local_34.bottom - (int)local_f0) + 1;
        local_34.left = local_34.right - (int)local_f0;
        local_34.bottom = local_34.bottom + -1;
        local_34.right = local_34.right + -1;
        local_b0[0x62] = local_34.left;
        local_b0[99] = local_34.top;
        local_b0[100] = local_34.right;
        local_b0[0x65] = local_34.bottom;
        piVar5 = local_b0;
      }
      if (piVar5[0x18] != 0) {
        ((LPRECT)(in_ECX + 0x2f))->left = piVar5[0x33];
        in_ECX[0x30] = piVar5[0x34];
        in_ECX[0x31] = piVar5[0x35];
        in_ECX[0x32] = piVar5[0x36];
        local_b0[0x30] = (local_b0[0x32] - (int)local_f0) + -1;
      }
      goto LAB_00870719;
    }
    pcVar7 = *(code **)(*in_ECX + 0xf0);
  }
  else {
    pcVar7 = *(code **)(*in_ECX + 0xf4);
  }
  guard_check_icall(param_1,local_d0);
  (*pcVar7)();
LAB_00870719:
  FUN_008d9b68();
  return;
LAB_0086f78d:
  do {
    local_e4 = (int *)FUN_00799cf8(local_bc);
    local_e4 = (int *)*local_e4;
    local_78.left = local_e4[0x1d];
    local_78.top = local_e4[0x1e];
    local_78.right = local_e4[0x1f];
    local_78.bottom = local_e4[0x20];
    BVar2 = IsRectEmpty(&local_78);
    piVar4 = local_e4;
    piVar8 = local_bc;
    piVar5 = local_b0;
    if ((BVar2 == 0) && (iVar3 = FUN_0086c47d(), piVar8 = local_bc, piVar5 = local_b0, iVar3 != 0))
    {
      pcVar7 = *(code **)(*piVar4 + 0xf0);
      guard_check_icall();
      iVar3 = (*pcVar7)();
      piVar5 = local_b0;
      piVar8 = local_bc;
      if ((iVar3 != 0) &&
         (((int)local_bc < local_b0[0x139] + -1 &&
          (piVar4 = (int *)FUN_00799cf8((int)local_bc + 1), *(int *)(*piVar4 + 0xbc) != 0)))) {
        local_cc = 0;
        piVar5 = (int *)FUN_00799cf8((int)piVar8 + 1);
        iVar3 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                          ((CMap<unsigned_int,unsigned_int,int,int> *)local_130,
                           *(uint *)(*piVar5 + 0x74),&local_cc);
        piVar5 = local_b0;
        if ((iVar3 != 0) && (local_cc < 3)) {
          local_e4[0x2e] = 0;
          local_e4[0x2f] = 1;
          local_8 = 8;
          goto LAB_0086f88b;
        }
        break;
      }
    }
    local_bc = (int *)((int)piVar8 + 1);
  } while ((int)local_bc < piVar5[0x139]);
LAB_0086f8dd:
  if (piVar5[0x139] <= (int)local_ac) goto LAB_0086f990;
  do {
    puVar1 = (undefined4 *)FUN_00799cf8(local_ac);
    local_c0 = (int *)*puVar1;
    local_68.left = local_c0[0x1d];
    local_68.top = local_c0[0x1e];
    local_68.right = local_c0[0x1f];
    local_68.bottom = local_c0[0x20];
    BVar2 = IsRectEmpty(&local_68);
    piVar5 = local_c0;
    if ((BVar2 == 0) && (local_c0[0x2f] != 0)) {
      pcVar7 = *(code **)(*local_c0 + 0x10c);
      guard_check_icall();
      iVar3 = (*pcVar7)();
      if (iVar3 != 0) {
        piVar5[0x2f] = 0;
        piVar5[0x2e] = 1;
        local_b8 = 1;
      }
    }
    local_ac = (int *)((int)local_ac + 1);
  } while ((int)local_ac < local_b0[0x139]);
  if (local_b8 == 0) goto LAB_0086f990;
  local_8 = 9;
  piVar5 = local_b0;
LAB_0086f428:
  local_130[0] = CMap<int,int,int,int>::vftable;
  RemoveAll();
  goto LAB_0086f086;
LAB_0086f990:
  FUN_00870d6f(local_d8);
  local_8 = 10;
  local_130[0] = CMap<int,int,int,int>::vftable;
  RemoveAll();
  goto LAB_00870719;
}



