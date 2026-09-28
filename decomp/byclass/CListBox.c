/* CListBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CListBox[1] */
/* 00798e78  FUN_00798e78  51 bytes, 0 callers */

void FUN_00798e78(byte param_1)

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




/* vtable slots: CListBox[89], CMFCToolBarsCommandsListBox[89] */
/* 00798f80  FUN_00798f80  51 bytes, 1 callers */

void FUN_00798f80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"LISTBOX",0,param_1,param_2,param_3,param_4,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CListBox[0], CMFCToolBarsCommandsListBox[0] */
/* 0079906f  FUN_0079906f  6 bytes, 0 callers */

undefined ** FUN_0079906f(void)

{
  return &PTR_s_CListBox_0097d1fc;
}




/* vtable slots: CListBox[73], CMFCToolBarsCommandsListBox[73] */
/* 00799187  FUN_00799187  190 bytes, 1 callers */

int FUN_00799187(uint param_1,uint param_2,long param_3,long *param_4)

{
  int iVar1;
  long lVar2;
  CWnd *in_ECX;
  code *pcVar3;
  
  if (param_1 == 0x2b) {
    pcVar3 = *(code **)(*(int *)in_ECX + 0x168);
LAB_0079922d:
    guard_check_icall(param_3);
    (*pcVar3)();
    return 1;
  }
  if (param_1 == 0x2c) {
    pcVar3 = *(code **)(*(int *)in_ECX + 0x16c);
    goto LAB_0079922d;
  }
  if (param_1 == 0x2d) {
    pcVar3 = *(code **)(*(int *)in_ECX + 0x174);
    goto LAB_0079922d;
  }
  if (param_1 == 0x2e) {
    pcVar3 = *(code **)(*(int *)in_ECX + 0x178);
  }
  else {
    if (param_1 != 0x2f) {
      if (param_1 != 0x39) {
        iVar1 = CWnd::OnChildNotify(in_ECX,param_1,param_2,param_3,param_4);
        return iVar1;
      }
      pcVar3 = *(code **)(*(int *)in_ECX + 0x170);
      guard_check_icall(param_3);
      lVar2 = (*pcVar3)();
      goto LAB_007991dd;
    }
    pcVar3 = *(code **)(*(int *)in_ECX + 0x17c);
  }
  guard_check_icall(param_2 & 0xffff,param_2 >> 0x10);
  lVar2 = (*pcVar3)();
LAB_007991dd:
  *param_4 = lVar2;
  return 1;
}



