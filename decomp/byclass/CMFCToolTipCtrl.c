/* CMFCToolTipCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolTipCtrl[89], CToolTipCtrl[89] */
/* 007af462  Create  85 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CToolTipCtrl::Create(class CWnd *,unsigned long)
   
   Library: Visual Studio 2015 Release */

int __thiscall CToolTipCtrl::Create(CToolTipCtrl *this,CWnd *param_1,ulong param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_00790c5e(0x1000);
  uVar3 = 0;
  uVar1 = 0;
  if (param_1 != (CWnd *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
  }
  iVar2 = FUN_00792137(0,L"tooltips_class32",0,param_2 | 0x80000000,0x80000000,0x80000000,0x80000000
                       ,0x80000000,uVar1,0,0);
  if (iVar2 != 0) {
    if (param_1 != (CWnd *)0x0) {
      uVar3 = *(undefined4 *)(param_1 + 0x20);
    }
    *(undefined4 *)(this + 0x5c) = uVar3;
  }
  return iVar2;
}




/* vtable slots: CMFCToolTipCtrl[90], CToolTipCtrl[90] */
/* 007af4b7  FUN_007af4b7  64 bytes, 0 callers */

undefined4 FUN_007af4b7(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall(param_1,param_2);
  iVar2 = (*pcVar1)();
  uVar3 = 0;
  if (iVar2 != 0) {
    iVar2 = FUN_00797c9f(0,param_3,0);
    if (iVar2 != 0) {
      uVar3 = 1;
    }
  }
  return uVar3;
}




/* vtable slots: CMFCToolTipCtrl[91], CToolTipCtrl[91] */
/* 007af53d  FUN_007af53d  46 bytes, 0 callers */

undefined4 FUN_007af53d(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x60);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 4);
  guard_check_icall(1);
  (*pcVar1)();
  return 1;
}




/* vtable slots: CMFCToolTipCtrl[1] */
/* 0089a557  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolTipCtrl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCToolTipCtrl::_scalar_deleting_destructor_(CMFCToolTipCtrl *this,uint param_1)

{
  ~CMFCToolTipCtrl(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x118);
    }
  }
  return this;
}




/* vtable slots: CMFCToolTipCtrl[93] */
/* 0089a6c9  FUN_0089a6c9  339 bytes, 0 callers */

int * FUN_0089a6c9(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  undefined1 local_10 [8];
  int *local_8;
  
  iVar5 = 0;
  local_8 = *(int **)(in_ECX + 0xac);
  if (local_8 == (int *)0x0) {
    iVar2 = *(int *)(in_ECX + 0xa8);
    if (((iVar2 != 0) && (iVar4 = *(int *)(in_ECX + 0xa4), iVar4 != 0)) &&
       (*(int *)(iVar4 + 4) != 0)) {
      if (*(int *)(iVar2 + 4) == 0) {
        iVar2 = *(int *)(iVar2 + 0x34);
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x38);
      }
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      else {
        iVar5 = *(int *)(iVar4 + 0x54);
        iVar2 = *(int *)(iVar4 + 0x58);
      }
      goto LAB_0089a7bf;
    }
  }
  else {
    pcVar1 = *(code **)(*local_8 + 0x268);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      local_8 = *(int **)(in_ECX + 0xac);
      if (local_8[0x57] != 0) {
        iVar5 = local_8[100];
        *(uint *)(in_ECX + 0xe4) = (uint)(iVar5 == 0);
        pcVar1 = *(code **)(*local_8 + 0x114);
        guard_check_icall(param_1,(uint)(iVar5 == 0));
        (*pcVar1)();
        return param_1;
      }
      iVar2 = 0;
      iVar4 = 0;
      if ((local_8[100] != 0) && (-1 < local_8[0x52])) {
        pcVar1 = *(code **)(*local_8 + 0x114);
        guard_check_icall(local_10,0);
        piVar3 = (int *)(*pcVar1)();
        iVar2 = *piVar3;
        iVar4 = piVar3[1];
      }
      if ((iVar2 != 0) || (iVar4 != 0)) {
        *(undefined4 *)(in_ECX + 0xe4) = 0;
        *param_1 = iVar2;
        param_1[1] = iVar4;
        return param_1;
      }
      local_8 = *(int **)(in_ECX + 0xac);
      iVar2 = 0;
      if (-1 < local_8[0x51]) {
        pcVar1 = *(code **)(*local_8 + 0x114);
        guard_check_icall(local_10,1);
        piVar3 = (int *)(*pcVar1)();
        iVar5 = *piVar3;
        iVar2 = piVar3[1];
      }
      *(undefined4 *)(in_ECX + 0xe4) = 1;
LAB_0089a7bf:
      param_1[1] = iVar2;
      goto LAB_0089a813;
    }
  }
  param_1[1] = 0;
LAB_0089a813:
  *param_1 = iVar5;
  return param_1;
}




/* vtable slots: CMFCToolTipCtrl[10] */
/* 0089a81c  FUN_0089a81c  6 bytes, 0 callers */

undefined ** FUN_0089a81c(void)

{
  return &PTR_FUN_0099dfa0;
}




/* vtable slots: CMFCToolTipCtrl[0] */
/* 0089a822  FUN_0089a822  6 bytes, 0 callers */

undefined ** FUN_0089a822(void)

{
  return &PTR_s_CMFCToolTipCtrl_0099dd4c;
}




/* vtable slots: CMFCToolTipCtrl[95] */
/* 0089a8a0  FUN_0089a8a0  235 bytes, 0 callers */

void FUN_0089a8a0(CDC *param_1,int param_2,int param_3,int param_4,int param_5,ulong param_6)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  undefined1 local_c [8];
  
  iVar2 = *(int *)(in_ECX + 0xf4) / 2;
  if ((iVar2 == 0) || (iVar1 = *(int *)(in_ECX + 0xf8) / 2, iVar1 == 0)) {
    CDC::Draw3dRect(param_1,(tagRECT *)&param_2,param_6,param_6);
  }
  else {
    FUN_0079ec58(local_c,param_2 + iVar2,param_3);
    CDC::LineTo(param_1,(param_4 - iVar2) + -1,param_3);
    CDC::LineTo(param_1,param_4 + -1,param_3 + iVar1);
    CDC::LineTo(param_1,param_4 + -1,(param_5 - iVar1) + -1);
    CDC::LineTo(param_1,(param_4 - iVar2) + -1,param_5 + -1);
    CDC::LineTo(param_1,param_2 + iVar2,param_5 + -1);
    CDC::LineTo(param_1,param_2,(param_5 - iVar1) + -1);
    CDC::LineTo(param_1,param_2,param_3 + iVar1);
    CDC::LineTo(param_1,param_2 + iVar2,param_3);
  }
  return;
}




/* vtable slots: CMFCToolTipCtrl[98] */
/* 0089a98b  FUN_0089a98b  214 bytes, 0 callers */

int * FUN_0089a98b(int *param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
                  undefined4 param_6,int param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  CMFCToolTipCtrl *in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(in_ECX + 0xb8) == 0) {
    param_1[1] = 0;
  }
  else {
    pcVar1 = *(code **)(*param_2 + 0x28);
    iVar4 = FUN_007c2511();
    guard_check_icall(iVar4 + 0x124);
    uVar2 = (*pcVar1)();
    param_5 = CMFCToolTipCtrl::GetFixedWidth(in_ECX);
    if ((param_5 < 1) || (iVar4 = *(int *)(in_ECX + 0xec), 0x20 < iVar4)) {
      param_5 = *(int *)(in_ECX + 0xcc) + param_3;
    }
    else {
      param_5 = param_5 + param_3;
      if ((0 < iVar4) && (*(int *)(in_ECX + 0xb4) != 0)) {
        param_5 = (param_5 - *(int *)(in_ECX + 0xfc)) - iVar4;
      }
    }
    iVar3 = FUN_007c2378(in_ECX + 0xe8,&param_3,(-(uint)(param_7 != 0) & 0x300) + 0x110);
    pcVar1 = *(code **)(*param_2 + 0x28);
    guard_check_icall(uVar2);
    (*pcVar1)();
    iVar4 = param_5 - param_3;
    param_1[1] = iVar3;
  }
  *param_1 = iVar4;
  return param_1;
}




/* vtable slots: CMFCToolTipCtrl[96] */
/* 0089aa61  FUN_0089aa61  331 bytes, 0 callers */

undefined4
FUN_0089aa61(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_20 [12];
  undefined4 local_14;
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  iVar1 = *(int *)(in_ECX + 0xac);
  local_14 = param_1;
  local_8 = in_ECX;
  if (iVar1 == 0) {
    if ((*(int *)(in_ECX + 0xa8) == 0) || (*(int *)(in_ECX + 0xa4) == 0)) {
      return 0;
    }
    FUN_007eb6ca(local_20,0,0,0);
    local_c = (int *)DAT_00a127b4;
    iVar1 = *(int *)(local_8 + 0xa8);
    uVar3 = *(undefined4 *)(iVar1 + 0x24);
    uVar4 = *(undefined4 *)(iVar1 + 8);
    local_10 = *(undefined4 *)(iVar1 + 0xc);
    DAT_00a127b4 = 0;
    *(undefined4 *)(*(int *)(local_8 + 0xa8) + 8) = 0;
    *(undefined4 *)(*(int *)(local_8 + 0xa8) + 0xc) = 1;
    *(undefined4 *)(*(int *)(local_8 + 0xa8) + 0x24) = 0;
    FUN_00881666(local_14,&param_2,*(undefined4 *)(local_8 + 0xa4),1,0,0,1,1);
    *(undefined4 *)(*(int *)(local_8 + 0xa8) + 0x24) = uVar3;
    *(undefined4 *)(*(int *)(local_8 + 0xa8) + 8) = uVar4;
    *(undefined4 *)(*(int *)(local_8 + 0xa8) + 0xc) = local_10;
    DAT_00a127b4 = local_c;
    FUN_007e98b8(local_20);
  }
  else {
    local_10 = *(undefined4 *)(iVar1 + 0xd4);
    *(undefined4 *)(iVar1 + 0xd4) = 0;
    local_c = *(int **)(in_ECX + 0xac);
    pcVar2 = *(code **)(*local_c + 0x120);
    guard_check_icall(param_1,*(undefined4 *)(in_ECX + 0xe4),param_2,param_3,param_4,param_5);
    (*pcVar2)();
    *(undefined4 *)(*(int *)(local_8 + 0xac) + 0xd4) = local_10;
  }
  return 1;
}




/* vtable slots: CMFCToolTipCtrl[97] */
/* 0089abac  FUN_0089abac  347 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_0089abac(int *param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
                  undefined4 param_6,int param_7)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  uint uVar5;
  undefined1 local_20 [4];
  int local_1c;
  code *local_18;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x89abb8;
  *param_1 = 0;
  param_1[1] = 0;
  local_1c = in_ECX;
  CStringT<>();
  local_8 = 0;
  FUN_00792c64(local_14);
  FUN_005946a0(&DAT_00966468,L"    ");
  if ((*(int *)(in_ECX + 0xb8) == 0) || (*(int *)(*(int *)(in_ECX + 0xe8) + -0xc) == 0)) {
    bVar2 = false;
    uVar5 = 0x124;
  }
  else {
    uVar5 = 0x120;
    bVar2 = true;
  }
  local_18 = *(code **)(*param_2 + 0x28);
  if ((*(int *)(local_1c + 0xc0) == 0) || (!bVar2)) {
    iVar3 = FUN_007c2511();
    iVar3 = iVar3 + 0x124;
  }
  else {
    iVar3 = FUN_007c2511();
    iVar3 = iVar3 + 300;
  }
  guard_check_icall(iVar3);
  local_18 = (code *)(*local_18)();
  iVar3 = FUN_0044e690(10,0);
  if (iVar3 < 0) {
    if (param_7 != 0) {
      piVar4 = (int *)FUN_00566800(local_20,local_14);
      iVar3 = piVar4[1];
      *param_1 = *piVar4;
      param_1[1] = iVar3;
      goto LAB_0089acde;
    }
    if (*(int *)(local_1c + 0xac) != 0) {
      uVar5 = uVar5 | 0x800;
    }
    iVar3 = FUN_007c2378(local_14,&param_3,uVar5);
    param_1[1] = iVar3;
  }
  else {
    iVar3 = FUN_007c2378(local_14,&param_3,(-(uint)(param_7 != 0) & 0x400) + 0x800);
    param_1[1] = iVar3;
  }
  *param_1 = param_5 - param_3;
LAB_0089acde:
  pcVar1 = *(code **)(*param_2 + 0x28);
  guard_check_icall(local_18);
  (*pcVar1)();
  FUN_00406b10();
  return param_1;
}




/* vtable slots: CMFCToolTipCtrl[99] */
/* 0089ad07  FUN_0089ad07  41 bytes, 0 callers */

void FUN_0089ad07(CDC *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined1 local_c [8];
  
  FUN_0079ec58(local_c,param_2,param_4);
  CDC::LineTo(param_1,param_3,param_4);
  return;
}




/* vtable slots: CMFCToolTipCtrl[94] */
/* 0089ada1  FUN_0089ada1  228 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0089ada1(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,
                 undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  HBRUSH local_2c;
  CDrawingManager local_18 [4];
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uVar3 = param_7;
  uVar2 = param_6;
  uStack_4 = 0x20;
  local_8 = 0x89adad;
  local_14 = param_1;
  if (*(int *)(in_ECX + 0xd4) == -1) {
    piVar4 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar4 + 0x2d8);
    guard_check_icall(local_14,in_ECX,param_2,param_3,param_4,param_5,uVar2,uVar3);
    (*pcVar1)();
  }
  else if (*(int *)(in_ECX + 0xd8) == -1) {
    FUN_0079de5e(*(int *)(in_ECX + 0xd4));
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,local_2c);
    FUN_00416100();
  }
  else {
    CDrawingManager::CDrawingManager(local_18,param_1);
    local_8 = 0;
    iVar5 = *(int *)(in_ECX + 0xd0);
    if (iVar5 == -1) {
      iVar5 = 0x5a;
    }
    FUN_00817514(param_2,param_3,param_4,param_5,*(undefined4 *)(in_ECX + 0xd8),
                 *(undefined4 *)(in_ECX + 0xd4),iVar5);
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCToolTipCtrl[92] */
/* 0089b6ec  SetDescription  78 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CMFCToolTipCtrl::SetDescription(class ATL::CStringT<char,class
   StrTraitMFC<char,class ATL::ChTraitsCRT<char> > >)
    public: virtual void __thiscall CMFCToolTipCtrl::SetDescription(class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > >)
   
   Library: Visual Studio 2015 Release */

void SetDescription(void)

{
  int in_ECX;
  
  FUN_0089a5f9();
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xe8),
             (CSimpleStringT<wchar_t,0> *)&stack0x00000004);
  FUN_005946a0(&DAT_00966468,L"    ");
  FUN_00406b10();
  return;
}



