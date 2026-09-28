/* CHeaderCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CHeaderCtrl[1] */
/* 007a3ff2  FUN_007a3ff2  51 bytes, 0 callers */

void FUN_007a3ff2(byte param_1)

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




/* vtable slots: CHeaderCtrl[89], CMFCHeaderCtrl[89] */
/* 007a413a  FUN_007a413a  61 bytes, 0 callers */

void FUN_007a413a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_00790c5e(0x400);
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"SysHeader32",0,param_1,param_2,param_3,param_4,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CHeaderCtrl[90], CMFCHeaderCtrl[90], CMFCRibbonSpinButtonCtrl[90], CMFCSpinButtonCtrl[90], CMyTabCtrl[90], CProgressCtrl[90], CSpinButtonCtrl[90], CTabCtrl[90] */
/* 007a42c0  FUN_007a42c0  69 bytes, 0 callers */

void FUN_007a42c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall(param_2,param_3,param_4,param_5);
  iVar2 = (*pcVar1)();
  if ((iVar2 != 0) && (param_1 != 0)) {
    FUN_00797c9f(0,param_1,0);
  }
  return;
}




/* vtable slots: CHeaderCtrl[0] */
/* 007a45c0  FUN_007a45c0  6 bytes, 0 callers */

undefined ** FUN_007a45c0(void)

{
  return &PTR_s_CHeaderCtrl_0097eb3c;
}




/* vtable slots: CHeaderCtrl[73], CMFCHeaderCtrl[73], CMyTabCtrl[73], CTabCtrl[73] */
/* 007a473f  FUN_007a473f  64 bytes, 0 callers */

int FUN_007a473f(uint param_1,uint param_2,long param_3,long *param_4)

{
  code *pcVar1;
  int iVar2;
  CWnd *in_ECX;
  
  if (param_1 == 0x2b) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x16c);
    guard_check_icall(param_3);
    (*pcVar1)();
    iVar2 = 1;
  }
  else {
    iVar2 = CWnd::OnChildNotify(in_ECX,param_1,param_2,param_3,param_4);
  }
  return iVar2;
}



