/* COleCntrFrameWndEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleCntrFrameWndEx[1] */
/* 00855b8a  FUN_00855b8a  51 bytes, 0 callers */

void FUN_00855b8a(byte param_1)

{
  FUN_00855a2c();
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




/* vtable slots: COleCntrFrameWndEx[113] */
/* 00855c26  FUN_00855c26  8 bytes, 0 callers */

void FUN_00855c26(void)

{
  FUN_00855bd9();
  return;
}




/* vtable slots: COleCntrFrameWndEx[10] */
/* 00855c65  FUN_00855c65  6 bytes, 0 callers */

undefined ** FUN_00855c65(void)

{
  return &PTR_FUN_00996380;
}




/* vtable slots: COleCntrFrameWndEx[0] */
/* 00855c6b  FUN_00855c6b  6 bytes, 0 callers */

undefined ** FUN_00855c6b(void)

{
  return &PTR_s_COleCntrFrameWndEx_00996120;
}




/* vtable slots: COleCntrFrameWndEx[114] */
/* 00855d02  FUN_00855d02  37 bytes, 0 callers */

void FUN_00855d02(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x128) + 0x3c);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: COleCntrFrameWndEx[112] */
/* 00855d27  FUN_00855d27  67 bytes, 0 callers */

undefined4 FUN_00855d27(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(in_ECX[0x4a] + 0x50);
  guard_check_icall(param_1);
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1c4);
  guard_check_icall(0);
  (*pcVar1)();
  return uVar2;
}




/* vtable slots: COleCntrFrameWndEx[25] */
/* 00855e6a  PreCreateWindow  33 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall COleCntrFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall COleCntrFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void PreCreateWindow(undefined4 param_1)

{
  CFrameWnd *in_ECX;
  
  CDockingManager::Create((CDockingManager *)(in_ECX + 0x128),in_ECX);
  PreCreateWindow(param_1);
  return;
}




/* vtable slots: COleCntrFrameWndEx[94] */
/* 00855e8b  FUN_00855e8b  181 bytes, 0 callers */

void FUN_00855e8b(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00855bd9();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x128) + 0x38);
  guard_check_icall(0);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x128) + 0x34);
  guard_check_icall(param_1);
  (*pcVar1)();
  iVar2 = FUN_00799e17();
  if (iVar2 != 0) {
    iVar2 = FUN_0079d98a(&PTR_s_CPreviewViewEx_009a3618);
    if ((iVar2 != 0) && (*(int *)(in_ECX + 600) != 0)) {
      FUN_00797e71(0,*(int *)(in_ECX + 0x220),*(int *)(in_ECX + 0x224),
                   *(int *)(in_ECX + 0x228) - *(int *)(in_ECX + 0x220),
                   *(int *)(in_ECX + 0x22c) - *(int *)(in_ECX + 0x224),0x14);
    }
  }
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x120) + 0x178);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}



