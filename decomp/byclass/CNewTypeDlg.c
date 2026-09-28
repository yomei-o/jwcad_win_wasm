/* CNewTypeDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CNewTypeDlg[1] */
/* 007ca946  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CNewTypeDlg::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CNewTypeDlg::_scalar_deleting_destructor_(CNewTypeDlg *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_00797fb6();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xb0);
    }
  }
  return this;
}




/* vtable slots: CNewTypeDlg[10] */
/* 007cad5a  FUN_007cad5a  6 bytes, 0 callers */

undefined ** FUN_007cad5a(void)

{
  return &PTR_FUN_00985870;
}




/* vtable slots: CNewTypeDlg[94] */
/* 007cb4e0  FUN_007cb4e0  321 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007cb4e0(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  WPARAM wParam;
  LRESULT LVar6;
  int in_ECX;
  undefined4 uVar7;
  int local_1c;
  int *local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7cb4ec;
  iVar3 = FUN_00797a56(100);
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  SendMessageW(*(HWND *)(iVar3 + 0x20),0x184,0,0);
  local_1c = *(int *)(*(int *)(in_ECX + 0xa8) + 4);
  while (local_1c != 0) {
    puVar4 = (undefined4 *)FUN_00792938(&local_1c);
    piVar1 = (int *)*puVar4;
    local_18 = piVar1;
    CStringT<>();
    local_8 = 0;
    pcVar2 = *(code **)(*piVar1 + 100);
    guard_check_icall(local_14,2);
    iVar5 = (*pcVar2)();
    if ((iVar5 != 0) && (*(int *)(local_14[0] + -0xc) != 0)) {
      wParam = SendMessageW(*(HWND *)(iVar3 + 0x20),0x180,0,local_14[0]);
      if (wParam == 0xffffffff) {
        FUN_007986de(0xffffffff);
        FUN_00406b10();
        return 0;
      }
      SendMessageW(*(HWND *)(iVar3 + 0x20),0x19a,wParam,(LPARAM)local_18);
    }
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  LVar6 = SendMessageW(*(HWND *)(iVar3 + 0x20),0x18b,0,0);
  if (LVar6 == 0) {
    uVar7 = 0xffffffff;
  }
  else {
    if (LVar6 != 1) {
      SendMessageW(*(HWND *)(iVar3 + 0x20),0x186,0,0);
      goto LAB_007cb60f;
    }
    LVar6 = SendMessageW(*(HWND *)(iVar3 + 0x20),0x199,0,0);
    *(LRESULT *)(in_ECX + 0xac) = LVar6;
    uVar7 = 1;
  }
  FUN_007986de(uVar7);
LAB_007cb60f:
  uVar7 = FUN_00798993();
  return uVar7;
}




/* vtable slots: CNewTypeDlg[96] */
/* 007cb622  FUN_007cb622  80 bytes, 0 callers */

void FUN_007cb622(void)

{
  int iVar1;
  WPARAM wParam;
  int in_ECX;
  LRESULT LVar2;
  
  iVar1 = FUN_00797a56(100);
  if (iVar1 != 0) {
    LVar2 = 0;
    wParam = SendMessageW(*(HWND *)(iVar1 + 0x20),0x188,0,0);
    if (wParam != 0xffffffff) {
      LVar2 = SendMessageW(*(HWND *)(iVar1 + 0x20),0x199,wParam,0);
    }
    *(LRESULT *)(in_ECX + 0xac) = LVar2;
    FUN_00798a09();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



