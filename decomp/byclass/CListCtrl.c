/* CListCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CListCtrl[1] */
/* 00564be0  FUN_00564be0  68 bytes, 0 callers */

ExternalContextBase * FUN_00564be0(uint param_1)

{
  ExternalContextBase *in_ECX;
  
  Concurrency::details::ExternalContextBase::~ExternalContextBase(in_ECX);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x80);
    }
  }
  return in_ECX;
}




/* vtable slots: CListCtrl[10] */
/* 007a45ae  FUN_007a45ae  6 bytes, 0 callers */

undefined ** FUN_007a45ae(void)

{
  return &PTR_FUN_0097eefc;
}




/* vtable slots: CListCtrl[0], CMyListCtrl[0] */
/* 007a45cc  FUN_007a45cc  6 bytes, 0 callers */

undefined ** FUN_007a45cc(void)

{
  return &PTR_s_CListCtrl_0097eacc;
}




/* vtable slots: CListCtrl[73], CMFCListCtrl[73], CMFCShellListCtrl[73], CMyListCtrl[73] */
/* 007a477f  FUN_007a477f  64 bytes, 0 callers */

int FUN_007a477f(uint param_1,uint param_2,long param_3,long *param_4)

{
  code *pcVar1;
  int iVar2;
  CWnd *in_ECX;
  
  if (param_1 == 0x2b) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x164);
    guard_check_icall(param_3);
    (*pcVar1)();
    iVar2 = 1;
  }
  else {
    iVar2 = CWnd::OnChildNotify(in_ECX,param_1,param_2,param_3,param_4);
  }
  return iVar2;
}



