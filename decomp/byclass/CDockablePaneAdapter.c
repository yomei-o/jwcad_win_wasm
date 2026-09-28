/* CDockablePaneAdapter -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDockablePaneAdapter[1] */
/* 0085ec13  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CDockablePaneAdapter::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CDockablePaneAdapter::_scalar_deleting_destructor_(CDockablePaneAdapter *this,uint param_1)

{
  *(undefined ***)this = vftable;
  CDockablePane::~CDockablePane((CDockablePane *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x380);
    }
  }
  return this;
}




/* vtable slots: CDockablePaneAdapter[10] */
/* 0085ec4c  FUN_0085ec4c  6 bytes, 0 callers */

undefined ** FUN_0085ec4c(void)

{
  return &PTR_FUN_009970cc;
}




/* vtable slots: CDockablePaneAdapter[0] */
/* 0085ec52  FUN_0085ec52  6 bytes, 0 callers */

undefined ** FUN_0085ec52(void)

{
  return &PTR_s_CDockablePaneAdapter_00a00984;
}




/* vtable slots: CDockablePaneAdapter[233], CMFCOutlookBarPaneAdapter[233] */
/* 0085ec71  FUN_0085ec71  7 bytes, 0 callers */

undefined4 FUN_0085ec71(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x37c);
}




/* vtable slots: CDockablePaneAdapter[139], CMFCOutlookBarPaneAdapter[139] */
/* 0085ec78  FUN_0085ec78  319 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x0085ed86) */

undefined4 FUN_0085ec78(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x85ec84;
  FUN_008592c1(&local_20,L"Panes",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_14,L"%TsDockablePaneAdapter-%d",local_20,param_2);
  }
  else {
    FUN_004059f0(local_14,L"%TsDockablePaneAdapter-%d%x",local_20,param_2,param_3);
  }
  local_8._0_1_ = 2;
  local_18 = (int *)FUN_00859490(0,0);
  pcVar1 = *(code **)(*local_18 + 0x10);
  guard_check_icall(local_14[0]);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    CStringT<>();
    local_8._0_1_ = 3;
    pcVar1 = *(code **)(*local_18 + 0x4c);
    guard_check_icall(L"BarName",&local_1c);
    (*pcVar1)();
    if (*(int *)(local_1c + -0xc) != 0) {
      FUN_00797ece(local_1c);
    }
    uVar3 = FUN_0088ec45(param_1,param_2,param_3);
    FUN_00406b10();
  }
  FUN_00406b10();
  FUN_00406b10();
  return uVar3;
}




/* vtable slots: CDockablePaneAdapter[140], CMFCOutlookBarPaneAdapter[140] */
/* 0085edec  FUN_0085edec  312 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x0085eef3) */

undefined4 FUN_0085edec(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x85edf8;
  FUN_008592c1(&local_20,L"Panes",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_14,L"%TsDockablePaneAdapter-%d",local_20,param_2);
  }
  else {
    FUN_004059f0(local_14,L"%TsDockablePaneAdapter-%d%x",local_20,param_2,param_3);
  }
  local_8._0_1_ = 2;
  local_18 = (int *)FUN_00859490(0,0);
  pcVar1 = *(code **)(*local_18 + 0xc);
  guard_check_icall(local_14[0]);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    CStringT<>();
    local_8._0_1_ = 3;
    FUN_00792c64(&local_1c);
    pcVar1 = *(code **)(*local_18 + 0x30);
    guard_check_icall(L"BarName",local_1c);
    (*pcVar1)();
    local_8._0_1_ = 2;
    FUN_00406b10();
  }
  uVar3 = FUN_00890e4a(param_1,param_2,param_3);
  FUN_00406b10();
  FUN_00406b10();
  return uVar3;
}




/* vtable slots: CDockablePaneAdapter[232], CMFCOutlookBarPaneAdapter[232] */
/* 0085ef24  FUN_0085ef24  248 bytes, 0 callers */

undefined4 FUN_0085ef24(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  HWND pHVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *in_ECX;
  
  if (in_ECX == (int *)0x0) {
    pHVar3 = (HWND)0x0;
  }
  else {
    pHVar3 = (HWND)in_ECX[8];
  }
  pHVar3 = SetParent((HWND)param_1[8],pHVar3);
  CWnd::FromHandle(pHVar3);
  in_ECX[0xdf] = (int)param_1;
  iVar4 = FUN_0079d98a(&PTR_s_CBasePane_0098a7f8);
  iVar6 = *in_ECX;
  if (iVar4 == 0) {
    guard_check_icall(in_ECX[0xde]);
    (**(code **)(iVar6 + 0x1ec))();
  }
  else {
    pcVar1 = *(code **)(*param_1 + 0x198);
    guard_check_icall();
    uVar5 = (*pcVar1)();
    guard_check_icall(uVar5);
    (**(code **)(iVar6 + 0x1ec))();
    pcVar1 = *(code **)(*param_1 + 0x1ac);
    guard_check_icall();
    iVar6 = (*pcVar1)();
    in_ECX[0x21] = iVar6;
    pcVar1 = *(code **)(*in_ECX + 0x1b4);
    pcVar2 = *(code **)(*param_1 + 0x1b0);
    guard_check_icall();
    uVar5 = (*pcVar2)();
    guard_check_icall(uVar5);
    (*pcVar1)();
    iVar6 = FUN_0079d98a(&PTR_s_CPane_0098ac24);
    if (iVar6 != 0) {
      in_ECX[0xa6] = param_1[0xa6];
      in_ECX[0xa7] = param_1[0xa7];
      in_ECX[0xa8] = param_1[0xa8];
      in_ECX[0xa9] = param_1[0xa9];
    }
  }
  return 1;
}



