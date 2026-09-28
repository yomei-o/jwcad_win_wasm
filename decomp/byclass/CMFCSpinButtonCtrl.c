/* CMFCSpinButtonCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCSpinButtonCtrl[1] */
/* 0082a45c  FUN_0082a45c  57 bytes, 0 callers */

void FUN_0082a45c(byte param_1)

{
  ExternalContextBase *in_ECX;
  
  *(undefined ***)in_ECX = CMFCSpinButtonCtrl::vftable;
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




/* vtable slots: CMFCSpinButtonCtrl[10] */
/* 0082a495  FUN_0082a495  6 bytes, 0 callers */

undefined ** FUN_0082a495(void)

{
  return &PTR_FUN_0098ff78;
}




/* vtable slots: CMFCSpinButtonCtrl[91] */
/* 0082a4bf  FUN_0082a4bf  283 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0082a4bf(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  HBRUSH hbr;
  uint uVar3;
  int in_ECX;
  code *pcVar4;
  undefined4 uVar5;
  CDrawingManager local_38 [8];
  int *local_30;
  CDC *local_2c;
  code *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x82a4cb;
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  local_2c = param_1;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_24);
  if (DAT_00a12704 == 0) {
    iVar2 = FUN_007c2511();
    hbr = (HBRUSH)0x0;
    if (iVar2 != -200) {
      hbr = *(HBRUSH *)(iVar2 + 0xcc);
    }
    FillRect(*(HDC *)(param_1 + 4),&local_24,hbr);
  }
  else {
    CDrawingManager::CDrawingManager(local_38,param_1);
    local_8 = 0;
    uVar5 = 0xffffffff;
    iVar2 = FUN_007c2511(0xffffffff);
    FUN_00816b6a(&local_24,*(undefined4 *)(iVar2 + 0x6c),uVar5);
    local_8 = 0xffffffff;
    FUN_0081510b();
  }
  local_28 = (code *)(uint)(*(int *)(in_ECX + 0x80) != 0);
  if (*(int *)(in_ECX + 0x84) != 0) {
    local_28 = (code *)((uint)local_28 | 2);
  }
  if (*(int *)(in_ECX + 0x88) != 0) {
    local_28 = (code *)((uint)local_28 | 4);
  }
  if (*(int *)(in_ECX + 0x8c) != 0) {
    local_28 = (code *)((uint)local_28 | 8);
  }
  iVar2 = FUN_00797c32();
  pcVar4 = local_28;
  if (iVar2 == 0) {
    pcVar4 = (code *)((uint)local_28 | 0x10);
  }
  local_30 = (int *)FUN_007c2574();
  local_28 = *(code **)(*local_30 + 0x1c0);
  uVar3 = FUN_00797b3d();
  pcVar1 = local_28;
  guard_check_icall(local_2c,local_24.left,local_24.top,local_24.right,local_24.bottom,pcVar4,
                    uVar3 >> 6 & 1);
  (*pcVar1)();
  FUN_008d9b68();
  return;
}



