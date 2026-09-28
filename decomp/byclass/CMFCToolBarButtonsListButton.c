/* CMFCToolBarButtonsListButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarButtonsListButton[1] */
/* 008c6dbd  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarButtonsListButton::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarButtonsListButton::_scalar_deleting_destructor_
          (CMFCToolBarButtonsListButton *this,uint param_1)

{
  ~CMFCToolBarButtonsListButton(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x140);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarButtonsListButton[90] */
/* 008c6e54  FUN_008c6e54  573 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008c6e54(int param_1)

{
  CMFCToolBarImages *this;
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined1 local_150 [12];
  int local_144;
  CDC *local_140;
  int local_13c;
  undefined4 local_138;
  code *local_134;
  int *local_130;
  int *local_12c;
  undefined1 local_128 [244];
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x140;
  local_8 = 0x8c6e63;
  local_144 = in_ECX;
  if (*(int *)(in_ECX + 0x138) == 0) {
    FUN_008c7556();
  }
  local_140 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  CopyRect(&local_34,(RECT *)(param_1 + 0x1c));
  this = *(CMFCToolBarImages **)(in_ECX + 0x9c);
  if (this != (CMFCToolBarImages *)0x0) {
    iVar3 = FUN_007c2511();
    CMFCToolBarImages::SetTransparentColor(this,*(ulong *)(iVar3 + 0x1c));
    iVar3 = FUN_007eb6ca(local_150,0,0,0);
    if (iVar3 == 0) goto LAB_008c7084;
    local_13c = *(int *)(in_ECX + 0x84);
    while (local_13c != 0) {
      local_12c = (int *)FUN_0044f2d0(&local_13c);
      iVar3 = local_144;
      local_12c = (int *)*local_12c;
      if (local_12c == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      local_24.left = local_12c[0x15];
      local_24.top = local_12c[0x16];
      local_24.right = local_12c[0x17];
      local_24.bottom = local_12c[0x18];
      OffsetRect(&local_24,0,-*(int *)(local_144 + 300));
      piVar2 = local_12c;
      if (local_34.bottom <= local_24.top) break;
      if (local_34.top < local_24.bottom) {
        local_138 = 0;
        local_130 = (int *)local_12c[9];
        local_134 = (code *)local_12c[0xf];
        iVar4 = FUN_00797c32();
        if (iVar4 == 0) {
          piVar2[9] = piVar2[9] | 0x40000;
        }
        else if (piVar2 == *(int **)(iVar3 + 0x128)) {
          local_138 = 1;
        }
        piVar2[0xf] = 1;
        pcVar1 = *(code **)(*piVar2 + 0x18);
        guard_check_icall(local_140,&local_24,*(undefined4 *)(iVar3 + 0x9c),1,0,local_138,1,1);
        (*pcVar1)();
        local_12c[9] = (int)local_130;
        local_12c[0xf] = (int)local_134;
      }
    }
    FUN_007e98b8(local_150);
  }
  FUN_008253cd();
  local_8 = 0;
  InflateRect(&local_34,1,1);
  local_130 = (int *)FUN_007c2574();
  local_134 = *(code **)(*local_130 + 0x70);
  iVar3 = FUN_00797c32();
  pcVar1 = local_134;
  guard_check_icall(local_140,local_34.left,local_34.top,local_34.right,local_34.bottom,iVar3 == 0,0
                    ,1,local_128);
  (*pcVar1)();
  FUN_00825493();
LAB_008c7084:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCToolBarButtonsListButton[10] */
/* 008c7092  FUN_008c7092  6 bytes, 0 callers */

undefined ** FUN_008c7092(void)

{
  return &PTR_FUN_009a4f18;
}




/* vtable slots: CMFCToolBarButtonsListButton[30] */
/* 008c7098  GetScrollBarCtrl  31 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CScrollBar * __thiscall
   CMFCToolBarButtonsListButton::GetScrollBarCtrl(int)const 
   
   Library: Visual Studio 2015 Release */

CScrollBar * __thiscall
CMFCToolBarButtonsListButton::GetScrollBarCtrl(CMFCToolBarButtonsListButton *this,int param_1)

{
  CScrollBar *pCVar1;
  
  if (((param_1 == 0) || (pCVar1 = (CScrollBar *)(this + 0xa8), pCVar1 == (CScrollBar *)0x0)) ||
     (*(int *)(this + 200) == 0)) {
    pCVar1 = (CScrollBar *)0x0;
  }
  return pCVar1;
}



