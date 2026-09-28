/* CRecentPaneContainerInfo -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRecentPaneContainerInfo[1] */
/* 0085f1e1  FUN_0085f1e1  48 bytes, 0 callers */

void FUN_0085f1e1(byte param_1)

{
  FUN_0085f0af();
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




/* vtable slots: CRecentPaneContainerInfo[4] */
/* 0085f397  SetInfo  119 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CRecentPaneContainerInfo::SetInfo(class CRecentPaneContainerInfo
   &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CRecentPaneContainerInfo::SetInfo(CRecentPaneContainerInfo *this,CRecentPaneContainerInfo *param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_008ba7d2();
  }
  if (*(CPaneContainer **)(this + 0x38) != (CPaneContainer *)0x0) {
    CPaneContainer::Release(*(CPaneContainer **)(this + 0x38));
  }
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_008ba7d2();
  }
  if (*(CPaneContainer **)(this + 0x3c) != (CPaneContainer *)0x0) {
    CPaneContainer::Release(*(CPaneContainer **)(this + 0x3c));
  }
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  RemoveAll();
  FUN_007d5dab(param_1 + 0x1c);
  return;
}




/* vtable slots: CRecentPaneContainerInfo[3] */
/* 0085f555  StoreDockInfo  194 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CRecentPaneContainerInfo::StoreDockInfo(class CPaneContainer
   *,class CDockablePane *,class CDockablePane *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CRecentPaneContainerInfo::StoreDockInfo
          (CRecentPaneContainerInfo *this,CPaneContainer *param_1,CDockablePane *param_2,
          CDockablePane *param_3)

{
  int iVar1;
  undefined4 uVar2;
  CDockablePane *pCVar3;
  
  if (param_1 != (CPaneContainer *)0x0) {
    FUN_008ba7d2();
    pCVar3 = param_2;
    if (param_3 != (CDockablePane *)0x0) {
      pCVar3 = param_3;
    }
    uVar2 = FUN_008bbd38(pCVar3);
    *(undefined4 *)(this + 0x18) = uVar2;
  }
  iVar1 = *(int *)(this + 0x38);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x3c) == 0)) {
    *(int *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) + -1;
    if (*(int *)(*(int *)(this + 0x38) + 0x30) < 1) {
      CPaneContainer::ReleaseEmptyPaneContainer(*(CPaneContainer **)(*(int *)(iVar1 + 0x1c) + 0x3c))
      ;
    }
    *(undefined4 *)(this + 0x38) = 0;
  }
  iVar1 = *(int *)(this + 0x3c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x3c) == 0)) {
    *(int *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) + -1;
    if (*(int *)(*(int *)(this + 0x3c) + 0x30) < 1) {
      CPaneContainer::ReleaseEmptyPaneContainer(*(CPaneContainer **)(*(int *)(iVar1 + 0x1c) + 0x3c))
      ;
    }
    *(undefined4 *)(this + 0x3c) = 0;
  }
  GetWindowRect(*(HWND *)(param_2 + 0x20),(LPRECT)(this + 4));
  if (param_3 == (CDockablePane *)0x0) {
    *(CPaneContainer **)(this + 0x38) = param_1;
    uVar2 = *(undefined4 *)(param_2 + 0x2d0);
  }
  else {
    *(CPaneContainer **)(this + 0x3c) = param_1;
    uVar2 = *(undefined4 *)(param_3 + 0x2d0);
  }
  *(undefined4 *)(this + 0x14) = uVar2;
  return;
}



