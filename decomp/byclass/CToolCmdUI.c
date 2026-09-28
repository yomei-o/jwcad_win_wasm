/* CToolCmdUI -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CToolCmdUI[0] */
/* 007ae0d1  Enable  65 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CToolCmdUI::Enable(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CToolCmdUI::Enable(CToolCmdUI *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(this + 0x18) = 1;
  uVar1 = CToolBar::GetButtonStyle(*(CToolBar **)(this + 0x14),*(int *)(this + 8));
  uVar2 = uVar1 & 0xfffbffff;
  if (param_1 == 0) {
    uVar2 = uVar1 & 0xfff9ffff | 0x40000;
  }
  FUN_007ae9ff(*(undefined4 *)(this + 8),uVar2);
  return;
}




/* vtable slots: CToolCmdUI[1] */
/* 007aebe6  SetCheck  69 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CToolCmdUI::SetCheck(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CToolCmdUI::SetCheck(CToolCmdUI *this,int param_1)

{
  uint uVar1;
  
  uVar1 = CToolBar::GetButtonStyle(*(CToolBar **)(this + 0x14),*(int *)(this + 8));
  uVar1 = uVar1 & 0xffeeffff;
  if (param_1 == 1) {
    uVar1 = uVar1 | 0x10000;
  }
  else if (param_1 == 2) {
    uVar1 = uVar1 | 0x100000;
  }
  FUN_007ae9ff(*(undefined4 *)(this + 8),uVar1 | 2);
  return;
}



