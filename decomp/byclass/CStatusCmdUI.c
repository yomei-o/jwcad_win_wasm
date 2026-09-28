/* CStatusCmdUI -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CStatusCmdUI[0] */
/* 007beacf  Enable  60 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CStatusCmdUI::Enable(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CStatusCmdUI::Enable(CStatusCmdUI *this,int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(this + 0x18) = 1;
  uVar1 = *(uint *)(*(int *)(this + 8) * 0x14 + 8 + *(int *)(*(CStatusBar **)(this + 0x14) + 0xa4))
          & 0xfbffffff;
  if (param_1 == 0) {
    uVar1 = uVar1 | 0x4000000;
  }
  CStatusBar::SetPaneStyle(*(CStatusBar **)(this + 0x14),*(int *)(this + 8),uVar1);
  return;
}




/* vtable slots: CStatusCmdUI[1] */
/* 007bee59  SetCheck  53 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CStatusCmdUI::SetCheck(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CStatusCmdUI::SetCheck(CStatusCmdUI *this,int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(this + 8) * 0x14 + 8 + *(int *)(*(CStatusBar **)(this + 0x14) + 0xa4))
          & 0xfffffdff;
  if (param_1 != 0) {
    uVar1 = uVar1 | 0x200;
  }
  CStatusBar::SetPaneStyle(*(CStatusBar **)(this + 0x14),*(int *)(this + 8),uVar1);
  return;
}




/* vtable slots: CStatusCmdUI[3] */
/* 007bf162  FUN_007bf162  23 bytes, 0 callers */

void FUN_007bf162(undefined4 param_1)

{
  int in_ECX;
  
  FUN_007bf084(*(undefined4 *)(in_ECX + 8),param_1,1);
  return;
}



