/* CMFCRibbonTab -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonTab[1] */
/* 008717aa  FUN_008717aa  51 bytes, 0 callers */

void FUN_008717aa(byte param_1)

{
  FUN_00863031();
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




/* vtable slots: CMFCRibbonTab[90] */
/* 00871c66  CopyFrom  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonTab::CopyFrom(class CMFCRibbonBaseElement const &)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCRibbonTab::CopyFrom(CMFCRibbonTab *this,CMFCRibbonBaseElement *param_1)

{
  CMFCRibbonBaseElement::CopyFrom((CMFCRibbonBaseElement *)this,param_1);
  *(undefined4 *)(this + 0x10c) = *(undefined4 *)(param_1 + 0x10c);
  *(undefined4 *)(this + 0x114) = *(undefined4 *)(param_1 + 0x114);
  return;
}




/* vtable slots: CMFCRibbonTab[118] */
/* 008721d0  FUN_008721d0  281 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008721d0(int *param_1,undefined4 param_2)

{
  RECT *lprc;
  code *pcVar1;
  BOOL BVar2;
  int *in_ECX;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  int iStack_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x1d4);
  guard_check_icall(&local_30,param_2);
  (*pcVar1)();
  if ((local_30 != 0) || (local_2c != 0)) {
    lprc = (RECT *)(in_ECX + 0x1d);
    BVar2 = IsRectEmpty(lprc);
    if (BVar2 == 0) {
      local_18.left = lprc->left;
      local_18.top = in_ECX[0x1e];
      local_18.right = in_ECX[0x1f];
      local_18.bottom = in_ECX[0x20];
      local_28 = lprc->left;
      iStack_24 = in_ECX[0x1e];
      local_20 = in_ECX[0x1f];
      local_1c = in_ECX[0x20];
      FUN_007c2378(in_ECX[0x22] + 0x8c,&local_28,0x424);
      iVar3 = (local_18.right - local_18.left) - (local_20 - local_28);
      if (iVar3 / 2 < 4) {
        iVar3 = -4;
      }
      else {
        iVar3 = -(iVar3 / 2);
      }
      InflateRect(&local_18,iVar3,0);
      iVar3 = (local_18.right + local_18.left) / 2 - local_30 / 2;
      *param_1 = iVar3;
      param_1[1] = local_1c + -2;
      param_1[2] = iVar3 + local_30;
      param_1[3] = local_2c + local_1c + -2;
      return param_1;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}




/* vtable slots: CMFCRibbonTab[0] */
/* 00872553  FUN_00872553  6 bytes, 0 callers */

undefined ** FUN_00872553(void)

{
  return &PTR_s_CMFCRibbonTab_00998e0c;
}




/* vtable slots: CMFCRibbonTab[48] */
/* 00872559  FUN_00872559  119 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00872559(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x110) == 0) {
    CStringT<>(&DAT_00956338);
  }
  else {
    uVar1 = FUN_004054a0(*(int *)(*(int *)(in_ECX + 0x88) + 0x8c) + -0x10);
    FUN_007fa476(0x26);
    iVar2 = FUN_004054a0(uVar1);
    *param_1 = iVar2 + 0x10;
    FUN_00406b10();
  }
  return param_1;
}




/* vtable slots: CMFCRibbonTab[87] */
/* 00872833  FUN_00872833  106 bytes, 0 callers */

void FUN_00872833(void)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x88);
  if (((iVar1 != 0) && (piVar2 = *(int **)(iVar1 + 0x53c), piVar2 != (int *)0x0)) &&
     (piVar2[8] != 0)) {
    if ((piVar2[0x492] == 0) && ((*(byte *)(piVar2 + 0xcc) & 1) != 0)) {
      FUN_008b3695(0,*(undefined4 *)(in_ECX + 0x74),*(undefined4 *)(in_ECX + 0x78));
      FUN_008b390c(0,*(undefined4 *)(in_ECX + 0x74),*(undefined4 *)(in_ECX + 0x78));
    }
    else {
      pcVar3 = *(code **)(*piVar2 + 0x32c);
      guard_check_icall(iVar1,0);
      (*pcVar3)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonTab[95] */
/* 00872ac4  FUN_00872ac4  313 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00872ac4(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  BOOL BVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  int local_28;
  int iStack_24;
  int local_20;
  int iStack_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x1d));
  if (BVar3 == 0) {
    piVar4 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar4 + 0x218);
    if (*(int *)(in_ECX[0x22] + 100) == 0) {
      pcVar2 = *(code **)(*in_ECX + 0x1c4);
      guard_check_icall();
      (*pcVar2)();
    }
    guard_check_icall(param_1);
    uVar5 = (*pcVar1)();
    pcVar1 = *(code **)(*param_1 + 0x30);
    guard_check_icall(uVar5);
    uVar5 = (*pcVar1)();
    local_18.left = in_ECX[0x1d];
    local_18.top = in_ECX[0x1e];
    local_18.right = in_ECX[0x1f];
    local_18.bottom = in_ECX[0x20];
    local_28 = in_ECX[0x1d];
    iStack_24 = in_ECX[0x1e];
    local_20 = in_ECX[0x1f];
    iStack_1c = in_ECX[0x20];
    FUN_007c2378(in_ECX[0x22] + 0x8c,&local_28,0x424);
    iVar6 = (local_18.right - local_18.left) - (local_20 - local_28);
    if (iVar6 / 2 < 4) {
      iVar6 = -4;
    }
    else {
      iVar6 = -(iVar6 / 2);
    }
    InflateRect(&local_18,iVar6,0);
    local_18.top = local_18.top + 3;
    FUN_007c2378(in_ECX[0x22] + 0x8c,&local_18,0x24);
    pcVar1 = *(code **)(*param_1 + 0x30);
    guard_check_icall(uVar5);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonTab[119] */
/* 00872fcc  FUN_00872fcc  113 bytes, 0 callers */

undefined4 FUN_00872fcc(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = *(int **)(in_ECX[0x22] + 0x53c);
  pcVar2 = *(code **)(*in_ECX + 0xdc);
  guard_check_icall();
  iVar3 = (*pcVar2)();
  if (iVar3 == 0) {
    if (*(int *)(in_ECX[0x22] + 0x540) != 0) {
      return 1;
    }
    pcVar2 = *(code **)(*piVar1 + 0x32c);
    guard_check_icall(in_ECX[0x22],0);
    (*pcVar2)();
    if ((*(byte *)(piVar1 + 0xcc) & 1) == 0) {
      FUN_008b425a(in_ECX[0x22],1);
    }
  }
  return 0;
}




/* vtable slots: CMFCRibbonTab[135] */
/* 0087303d  FUN_0087303d  202 bytes, 0 callers */

void FUN_0087303d(void)

{
  int iVar1;
  code *pcVar2;
  clock_t cVar3;
  UINT UVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *in_ECX;
  
  if (*(int *)(in_ECX[0x22] + 100) != 0) {
    if (*(int *)(in_ECX[0x22] + 0x570) != -1) {
      cVar3 = _clock();
      iVar1 = *(int *)(in_ECX[0x22] + 0x570);
      UVar4 = GetDoubleClickTime();
      if (cVar3 - iVar1 < (int)UVar4) {
        return;
      }
    }
    iVar1 = *(int *)(in_ECX[0x22] + 0x53c);
    if ((*(byte *)(iVar1 + 0x330) & 1) == 0) {
      uVar6 = 0;
    }
    else {
      pcVar2 = *(code **)(*in_ECX + 0xe4);
      guard_check_icall();
      iVar5 = (*pcVar2)();
      if (iVar5 != 0) {
        pcVar2 = *(code **)(*in_ECX + 0x198);
        guard_check_icall();
        (*pcVar2)();
      }
      uVar6 = 1;
    }
    FUN_00873f34(uVar6);
    piVar7 = (int *)FUN_0079296c();
    pcVar2 = *(code **)(*piVar7 + 0x178);
    guard_check_icall(1);
    (*pcVar2)();
    RedrawWindow(*(HWND *)(iVar1 + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CMFCRibbonTab[132] */
/* 00873188  FUN_00873188  42 bytes, 0 callers */

void FUN_00873188(void)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(*(int *)(in_ECX + 0x88) + 0x53c) + 0x32c);
  guard_check_icall(*(int *)(in_ECX + 0x88),0);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonTab[110] */
/* 00873988  FUN_00873988  103 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00873988(void)

{
  int iVar1;
  BOOL BVar2;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x74));
  if (BVar2 == 0) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x88) + 0x53c);
    local_18.left = ((RECT *)(in_ECX + 0x74))->left;
    local_18.top = *(LONG *)(in_ECX + 0x78);
    local_18.right = *(LONG *)(in_ECX + 0x7c);
    local_18.bottom = *(LONG *)(in_ECX + 0x80);
    InflateRect(&local_18,10,10);
    RedrawWindow(*(HWND *)(iVar1 + 0x20),&local_18,(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CMFCRibbonTab[43] */
/* 00873c1c  FUN_00873c1c  285 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00873c1c(undefined4 param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  CSimpleStringT<wchar_t,0> *pCVar4;
  int *in_ECX;
  wchar_t *pwVar5;
  wchar_t local_14 [6];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x873c28;
  if (((in_ECX[0x22] != 0) && (iVar3 = *(int *)(in_ECX[0x22] + 0x53c), iVar3 != 0)) &&
     (*(int *)(iVar3 + 0x20) != 0)) {
    uVar1 = *(uint *)(iVar3 + 0x330);
    iVar3 = FUN_0086470d(param_1,param_2);
    if (iVar3 != 0) {
      *(undefined4 *)(param_2 + 0x1c) = 0x300000;
      if ((uVar1 & 1) == 0) {
        if (*(int *)(in_ECX[0x22] + 100) != 0) {
          *(undefined4 *)(param_2 + 0x1c) = 0x300002;
        }
        pwVar5 = L"Switch";
      }
      else {
        *(undefined4 *)(param_2 + 0x1c) = 0x40300000;
        pcVar2 = *(code **)(*in_ECX + 0xe4);
        guard_check_icall();
        iVar3 = (*pcVar2)();
        if (iVar3 == 0) {
          pwVar5 = L"Open";
        }
        else {
          *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 10;
          pwVar5 = L"Close";
        }
      }
      iVar3 = FUN_008f899d(pwVar5);
      ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 0x14,pwVar5,iVar3);
      pwVar5 = *(wchar_t **)(in_ECX[0x22] + 0x8c);
      if (pwVar5 == (wchar_t *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_008f899d(pwVar5);
      }
      ATL::CSimpleStringT<wchar_t,0>::SetString(param_2,pwVar5,iVar3);
      *(undefined4 *)(param_2 + 0x18) = 0x25;
      pCVar4 = (CSimpleStringT<wchar_t,0> *)
               ATL::operator+(local_14,(CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                        *)L"Alt, ");
      local_8 = 0;
      ATL::CSimpleStringT<wchar_t,0>::operator=(param_2 + 0xc,pCVar4);
      FUN_00406b10();
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCRibbonTab[37] */
/* 008741b0  accHitTest  33 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCRibbonTab::accHitTest(long,long,struct tagVARIANT *)
   
   Library: Visual Studio 2015 Release */

long __thiscall
CMFCRibbonTab::accHitTest(CMFCRibbonTab *this,long param_1,long param_2,tagVARIANT *param_3)

{
  long lVar1;
  
  if (param_3 == (tagVARIANT *)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    *(undefined4 *)((int)&param_3->n1 + 8) = 0;
    (param_3->n1).n2.vt = 3;
    lVar1 = 0;
  }
  return lVar1;
}




/* vtable slots: CMFCRibbonTab[35] */
/* 008742be  FUN_008742be  180 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_008742be(int *param_1,int *param_2,int *param_3,int *param_4,short param_5,undefined4 param_6,
            int param_7)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
     (param_4 == (int *)0x0)) {
    uVar2 = 0x80070057;
  }
  else if (((*(int *)(in_ECX + 0x88) == 0) ||
           (iVar1 = *(int *)(*(int *)(in_ECX + 0x88) + 0x53c), iVar1 == 0)) ||
          (*(int *)(iVar1 + 0x20) == 0)) {
    uVar2 = 1;
  }
  else {
    if ((param_5 == 3) && (param_7 == 0)) {
      local_18 = *(int *)(in_ECX + 0x74);
      local_14 = *(int *)(in_ECX + 0x78);
      local_10 = *(int *)(in_ECX + 0x7c);
      local_c = *(int *)(in_ECX + 0x80);
      FUN_0079e8b8(&local_18);
      *param_1 = local_18;
      *param_2 = local_14;
      *param_3 = local_10 - local_18;
      *param_4 = local_c - local_14;
    }
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonTab[36] */
/* 00874453  FUN_00874453  175 bytes, 0 callers */

undefined4
FUN_00874453(int param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined2 *param_6)

{
  int iVar1;
  CCmdTarget *this;
  int iVar2;
  undefined4 *puVar3;
  IDispatch *pIVar4;
  int in_ECX;
  
  *param_6 = 0;
  if (param_2 != 3) {
    return 0x80070057;
  }
  if (*(int *)(in_ECX + 0x88) == 0) {
    return 1;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x88) + 0x53c);
  if (iVar1 == 0) {
    return 1;
  }
  if (*(int *)(iVar1 + 0x20) == 0) {
    return 1;
  }
  if (iVar1 == -0x1250) {
    return 1;
  }
  if (param_1 != 3) {
    if ((param_1 == 4) || (param_1 == 5)) {
      if (param_4 != 0) {
        return 1;
      }
      iVar2 = FUN_008c4d7f(in_ECX);
      iVar2 = iVar2 + 1;
      if (*(int *)(iVar1 + 0x1364) <= iVar2) {
        return 1;
      }
      goto LAB_008744dc;
    }
    if (param_1 != 6) {
      return 1;
    }
  }
  if (param_4 != 0) {
    return 1;
  }
  iVar2 = FUN_008c4d7f(in_ECX);
  iVar2 = iVar2 + -1;
  if (iVar2 < 0) {
    return 1;
  }
LAB_008744dc:
  puVar3 = (undefined4 *)FUN_00799cf8(iVar2);
  this = (CCmdTarget *)*puVar3;
  if (this == (CCmdTarget *)0x0) {
    return 1;
  }
  *param_6 = 9;
  pIVar4 = CCmdTarget::GetIDispatch(this,1);
  *(IDispatch **)(param_6 + 4) = pIVar4;
  return 0;
}




/* vtable slots: CMFCRibbonTab[33] */
/* 00874569  FUN_00874569  97 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00874569(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  BSTR pOVar1;
  undefined4 uVar2;
  OLECHAR *local_14;
  
  if ((param_1 == 3) && (param_3 == 0)) {
    CStringT<>(L"Switch");
    pOVar1 = SysAllocStringLen(local_14,*(UINT *)(local_14 + -6));
    if (pOVar1 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00407010();
    }
    *param_5 = pOVar1;
    FUN_00406b10();
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonTab[20] */
/* 00874607  get_accParent  75 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCRibbonTab::get_accParent(struct IDispatch * *)
   
   Library: Visual Studio 2015 Release */

long __thiscall CMFCRibbonTab::get_accParent(CMFCRibbonTab *this,IDispatch **param_1)

{
  int iVar1;
  IDispatch *pIVar2;
  uint uVar3;
  
  uVar3 = 0x80070057;
  if ((((*(int *)(this + 0x88) != 0) &&
       (iVar1 = *(int *)(*(int *)(this + 0x88) + 0x53c), iVar1 != 0)) &&
      (*(int *)(iVar1 + 0x20) != 0)) &&
     ((param_1 != (IDispatch **)0x0 && ((CCmdTarget *)(iVar1 + 0x1250) != (CCmdTarget *)0x0)))) {
    pIVar2 = CCmdTarget::GetIDispatch((CCmdTarget *)(iVar1 + 0x1250),1);
    *param_1 = pIVar2;
    uVar3 = (uint)(pIVar2 == (IDispatch *)0x0);
  }
  return uVar3;
}



