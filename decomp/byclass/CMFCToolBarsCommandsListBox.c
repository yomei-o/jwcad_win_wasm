/* CMFCToolBarsCommandsListBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsCommandsListBox[1] */
/* 008d860a  FUN_008d860a  57 bytes, 0 callers */

void FUN_008d860a(byte param_1)

{
  ExternalContextBase *in_ECX;
  
  *(undefined ***)in_ECX = CMFCToolBarsCommandsListBox::vftable;
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




/* vtable slots: CMFCToolBarsCommandsListBox[90] */
/* 008d8643  FUN_008d8643  238 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008d8643(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  int local_30;
  CDC *local_2c;
  int *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x8d864f;
  local_28 = in_ECX;
  local_2c = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  CopyRect(&local_24,(RECT *)(param_1 + 0x1c));
  if (*(int *)(param_1 + 8) != -1) {
    piVar2 = (int *)SendMessageW((HWND)in_ECX[8],0x199,*(WPARAM *)(param_1 + 8),0);
    local_30 = FUN_004054a0(piVar2[0xb] + -0x10);
    local_30 = local_30 + 0x10;
    local_8 = 0;
    GetText(*(undefined4 *)(param_1 + 8),piVar2 + 0xb);
    local_28 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*local_28 + 0x138);
    guard_check_icall(local_2c,local_24.left,local_24.top,local_24.right,local_24.bottom,0);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar2 + 0x6c);
    guard_check_icall(local_2c,&local_24,((byte)*(undefined4 *)(param_1 + 0x10) & 0x11) == 0x11);
    (*pcVar1)();
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(piVar2 + 0xb),(CSimpleStringT<wchar_t,0> *)&local_30);
    FUN_00406b10();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCToolBarsCommandsListBox[10] */
/* 008d8731  FUN_008d8731  6 bytes, 0 callers */

undefined ** FUN_008d8731(void)

{
  return &PTR_FUN_009a9680;
}




/* vtable slots: CMFCToolBarsCommandsListBox[91] */
/* 008d8737  FUN_008d8737  33 bytes, 0 callers */

void FUN_008d8737(int param_1)

{
  int in_ECX;
  
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x10) < *(uint *)(in_ECX + 0x84)) {
      *(uint *)(param_1 + 0x10) = *(uint *)(in_ECX + 0x84);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCToolBarsCommandsListBox[20] */
/* 008d88d1  FUN_008d88d1  49 bytes, 0 callers */

void FUN_008d88d1(void)

{
  int in_ECX;
  int local_c;
  int local_8;
  
  local_c = in_ECX;
  local_8 = in_ECX;
  guard_check_icall();
  FUN_007fe1cf(&local_c);
  *(int *)(in_ECX + 0x80) = local_c + 6;
  *(int *)(in_ECX + 0x84) = local_8 + 6;
  return;
}



