/* CCheckListBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CCheckListBox[94], CCheckListBox[95], CListBox[94], CListBox[95], CMFCToolBarsCommandsListBox[94], CMFCToolBarsCommandsListBox[95], CMFCToolBarsListCheckBox[94], CMFCToolBarsListCheckBox[95] */
/* 00798ede  FUN_00798ede  8 bytes, 0 callers */

void FUN_00798ede(void)

{
  FUN_007922d4();
  return;
}




/* vtable slots: CCheckListBox[89], CMFCToolBarsListCheckBox[89] */
/* 008cd8f4  Create  32 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CCheckListBox::Create(unsigned long,struct tagRECT const &,class
   CWnd *,unsigned int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
CCheckListBox::Create(CCheckListBox *this,ulong param_1,tagRECT *param_2,CWnd *param_3,uint param_4)

{
  int iVar1;
  
  if ((param_1 & 0x20) == 0) {
    param_1 = param_1 | 0x10;
  }
  iVar1 = FUN_00798f80(param_1,param_2,param_3,param_4);
  return iVar1;
}




/* vtable slots: CCheckListBox[90], CMFCToolBarsListCheckBox[90] */
/* 008cd940  FUN_008cd940  510 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008cd940(int param_1)

{
  code *pcVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  CDC *pCVar5;
  LRESULT LVar6;
  int iVar7;
  DWORD DVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int in_ECX;
  int local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x8cd94c;
  bVar3 = FUN_00797b3d();
  if (((bVar3 & 0x50) == 0x50) && (*(int *)(in_ECX + 0x80) == 0)) {
    uVar4 = FUN_008cd714();
    SendMessageW(*(HWND *)(in_ECX + 0x20),0x1a0,0,uVar4 & 0xffff);
  }
  pCVar5 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  local_14 = pCVar5;
  if (pCVar5 != (CDC *)0x0) {
    if ((-1 < *(int *)(param_1 + 8)) && ((*(byte *)(param_1 + 0xc) & 3) != 0)) {
      LVar6 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x1a1,*(WPARAM *)(param_1 + 8),0);
      iVar7 = FUN_00797c32();
      if ((iVar7 == 0) || (iVar7 = FUN_008cdd2f(*(undefined4 *)(param_1 + 8)), iVar7 == 0)) {
        bVar2 = true;
        DVar8 = 0x808080;
      }
      else {
        bVar2 = false;
        DVar8 = GetSysColor(8);
      }
      pcVar1 = *(code **)(*(int *)pCVar5 + 0x30);
      guard_check_icall(DVar8);
      uVar9 = (*pcVar1)();
      DVar8 = GetSysColor(5);
      pcVar1 = *(code **)(*(int *)local_14 + 0x2c);
      guard_check_icall(DVar8);
      uVar10 = (*pcVar1)();
      if ((!bVar2) && ((*(byte *)(param_1 + 0x10) & 1) != 0)) {
        pcVar1 = *(code **)(*(int *)local_14 + 0x30);
        DVar8 = GetSysColor(0xe);
        guard_check_icall(DVar8);
        (*pcVar1)();
        pcVar1 = *(code **)(*(int *)local_14 + 0x2c);
        DVar8 = GetSysColor(0xd);
        guard_check_icall(DVar8);
        (*pcVar1)();
      }
      if (*(int *)(in_ECX + 0x80) == 0) {
        FUN_008cd714();
      }
      CStringT<>();
      local_8 = 0;
      GetText(*(undefined4 *)(param_1 + 8),&local_18);
      pcVar1 = *(code **)(*(int *)local_14 + 0x60);
      iVar7 = (LVar6 - *(int *)(in_ECX + 0x80)) / 2;
      if (iVar7 < 0) {
        iVar7 = 0;
      }
      guard_check_icall(*(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0x20) + iVar7,2,
                        (undefined4 *)(param_1 + 0x1c),local_18,*(undefined4 *)(local_18 + -0xc),0);
      pCVar5 = local_14;
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar5 + 0x30);
      guard_check_icall(uVar9);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar5 + 0x2c);
      guard_check_icall(uVar10);
      (*pcVar1)();
      FUN_00406b10();
    }
    if ((*(byte *)(param_1 + 0xc) & 4) != 0) {
      DrawFocusRect(*(HDC *)(pCVar5 + 4),(RECT *)(param_1 + 0x1c));
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CCheckListBox[10] */
/* 008cdc9c  FUN_008cdc9c  6 bytes, 0 callers */

undefined ** FUN_008cdc9c(void)

{
  return &PTR_FUN_009a6bd8;
}




/* vtable slots: CCheckListBox[0], CMFCToolBarsListCheckBox[0] */
/* 008cdca2  FUN_008cdca2  6 bytes, 0 callers */

undefined ** FUN_008cdca2(void)

{
  return &PTR_s_CCheckListBox_009a6a48;
}




/* vtable slots: CCheckListBox[73], CMFCToolBarsListCheckBox[73] */
/* 008cdd6b  OnChildNotify  82 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CCheckListBox::OnChildNotify(unsigned int,unsigned
   int,long,long *)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CCheckListBox::OnChildNotify
          (CCheckListBox *this,uint param_1,uint param_2,long param_3,long *param_4)

{
  int iVar1;
  long lVar2;
  
  if (param_1 == 0x2b) {
    FUN_008ce5a4(param_3);
  }
  else if (param_1 == 0x2c) {
    FUN_008cea89(param_3);
  }
  else if (param_1 == 0x2d) {
    FUN_008ce523(param_3);
  }
  else {
    if (param_1 != 0x39) {
      iVar1 = FUN_00799187();
      return iVar1;
    }
    lVar2 = FUN_008ce4ca(param_3);
    *param_4 = lVar2;
  }
  return 1;
}




/* vtable slots: CCheckListBox[96], CMFCToolBarsListCheckBox[96] */
/* 008cddfd  OnGetCheckPosition  23 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CRect __thiscall CCheckListBox::OnGetCheckPosition(class CRect,class
   CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall CCheckListBox::OnGetCheckPosition(undefined4 param_1,undefined4 *param_2)

{
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  *param_2 = in_stack_00000018;
  param_2[1] = in_stack_0000001c;
  param_2[2] = in_stack_00000020;
  param_2[3] = in_stack_00000024;
  return;
}




/* vtable slots: CCheckListBox[56], CMFCToolBarsListCheckBox[56] */
/* 008ceca2  FUN_008ceca2  248 bytes, 0 callers */

undefined4 FUN_008ceca2(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  LPARAM lParam;
  LRESULT LVar1;
  int lParam_00;
  int iVar2;
  uint uVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  
  if ((0 < param_3) && (LVar1 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x18b,0,0), param_3 <= LVar1))
  {
    iVar7 = *(int *)(in_ECX + 0x84);
    lParam_00 = param_3 + -1;
    iVar2 = FUN_008cdb3f(lParam_00);
    iVar7 = (iVar2 + 1) % (int)((iVar7 == 6) + 2);
    FUN_008ceb3e(lParam_00,iVar7);
    uVar3 = FUN_00797b3d();
    if (((uVar3 & 0x808) != 0) &&
       (LVar1 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x187,param_3 - 1,0), LVar1 != 0)) {
      FUN_008cec07(iVar7);
    }
    pHVar4 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar5 = CWnd::FromHandle(pHVar4);
    lParam = *(LPARAM *)(in_ECX + 0x20);
    uVar3 = FUN_00797a2b();
    SendMessageW(*(HWND *)(pCVar5 + 0x20),0x111,uVar3 & 0xffff | 0x280000,lParam);
    SendMessageW(*(HWND *)(in_ECX + 0x20),0x185,1,lParam_00);
    return 0;
  }
  uVar6 = FUN_00795fbc(param_1,param_2,param_3,param_4);
  return uVar6;
}




/* vtable slots: CCheckListBox[51], CMFCToolBarsListCheckBox[51] */
/* 008ced9a  FUN_008ced9a  178 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_008ced9a(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  LRESULT LVar2;
  int iVar3;
  BSTR pOVar4;
  undefined4 uVar5;
  OLECHAR *in_ECX;
  UINT in_stack_ffffffdc;
  LPSTR in_stack_ffffffe0;
  int in_stack_ffffffe4;
  
  if ((0 < param_3) && (LVar2 = SendMessageW(*(HWND *)(in_ECX + 0x10),0x18b,0,0), param_3 <= LVar2))
  {
    iVar1 = *(int *)(in_ECX + 0x42);
    iVar3 = FUN_008cdb3f(param_3 + -1);
    CStringT<>();
    FID_conflict_LoadStringA
              ((HINSTANCE)((iVar3 + 1) % (int)((iVar1 == 6) + 2) + 0xf2e1),in_stack_ffffffdc,
               in_stack_ffffffe0,in_stack_ffffffe4);
    pOVar4 = SysAllocStringLen(in_ECX,*(UINT *)(in_ECX + -6));
    if (pOVar4 != (BSTR)0x0) {
      *param_5 = pOVar4;
      FUN_00406b10();
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    FUN_00407010();
  }
  uVar5 = FUN_007965d5(param_1,param_2,param_3,param_4,param_5);
  return uVar5;
}




/* vtable slots: CCheckListBox[44], CMFCToolBarsListCheckBox[44] */
/* 008cee4d  FUN_008cee4d  88 bytes, 0 callers */

undefined4
FUN_008cee4d(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined2 *param_5)

{
  LRESULT LVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((0 < param_3) && (LVar1 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x18b,0,0), param_3 <= LVar1))
  {
    *param_5 = 3;
    *(undefined4 *)(param_5 + 4) = 0x2c;
    return 0;
  }
  uVar2 = FUN_00796c2a(param_1,param_2,param_3,param_4,param_5);
  return uVar2;
}




/* vtable slots: CCheckListBox[45], CMFCToolBarsListCheckBox[45] */
/* 008ceea5  FUN_008ceea5  91 bytes, 0 callers */

int FUN_008ceea5(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,short *param_5
                )

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00796da3(param_1,param_2,param_3,param_4,param_5);
  if (((-1 < iVar1) && (*param_5 == 3)) && (param_3 != 0)) {
    iVar2 = FUN_008cdb3f(param_3 + -1);
    if (iVar2 == 1) {
      *(uint *)(param_5 + 4) = *(uint *)(param_5 + 4) | 0x10;
    }
    else if (iVar2 == 2) {
      *(uint *)(param_5 + 4) = *(uint *)(param_5 + 4) | 0x20;
    }
  }
  return iVar1;
}




/* vtable slots: CCheckListBox[1] */
/* 008cef6d  FUN_008cef6d  51 bytes, 0 callers */

void FUN_008cef6d(byte param_1)

{
  ExternalContextBase *in_ECX;
  
  Concurrency::details::ExternalContextBase::~ExternalContextBase(in_ECX);
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



