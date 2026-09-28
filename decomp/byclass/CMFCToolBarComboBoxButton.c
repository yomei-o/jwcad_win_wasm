/* CMFCToolBarComboBoxButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarComboBoxButton[1] */
/* 0082557a  FUN_0082557a  51 bytes, 0 callers */

void FUN_0082557a(byte param_1)

{
  FUN_00825493();
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




/* vtable slots: CMFCToolBarComboBoxButton[5], CMFCToolBarFontSizeComboBox[5] */
/* 00825aeb  FUN_00825aeb  226 bytes, 2 callers */

void FUN_00825aeb(int param_1)

{
  uint *puVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *in_ECX;
  int local_8;
  
  FUN_00880ee9(param_1);
  FUN_00813b58();
  local_8 = *(int *)(param_1 + 0xc0);
  while (local_8 != 0) {
    uVar4 = FUN_00792938(&local_8);
    AddTail(uVar4);
  }
  pcVar2 = *(code **)(*in_ECX + 0xe4);
  guard_check_icall();
  (*pcVar2)();
  RemoveAll();
  puVar3 = *(undefined4 **)(param_1 + 0xdc);
  while (puVar3 != (undefined4 *)0x0) {
    puVar1 = puVar3 + 2;
    puVar3 = (undefined4 *)*puVar3;
    CList<unsigned_int,unsigned_int>::AddTail
              ((CList<unsigned_int,unsigned_int> *)(in_ECX + 0x36),*puVar1);
  }
  pcVar2 = *(code **)(*in_ECX + 0xe0);
  guard_check_icall();
  (*pcVar2)();
  in_ECX[0x23] = *(int *)(param_1 + 0x8c);
  in_ECX[0x1c] = *(int *)(param_1 + 0x70);
  in_ECX[0x1d] = *(int *)(param_1 + 0x74);
  in_ECX[0x1e] = *(int *)(param_1 + 0x78);
  in_ECX[0x22] = *(int *)(param_1 + 0x88);
  in_ECX[0x21] = *(int *)(param_1 + 0x84);
  return;
}




/* vtable slots: CMFCToolBarComboBoxButton[59], CMFCToolBarFontComboBox[59], CMFCToolBarFontSizeComboBox[59] */
/* 00825ec4  FUN_00825ec4  18 bytes, 0 callers */

undefined4 FUN_00825ec4(undefined4 param_1)

{
  CStringT<>();
  return param_1;
}




/* vtable slots: CMFCToolBarComboBoxButton[0] */
/* 00825ed6  FUN_00825ed6  6 bytes, 0 callers */

undefined ** FUN_00825ed6(void)

{
  return &PTR_s_CMFCToolBarComboBoxButton_00a00810;
}




/* vtable slots: CMFCToolBarComboBoxButton[2], CMFCToolBarFontSizeComboBox[2] */
/* 00827af5  FUN_00827af5  588 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00827af5(CArchive *param_1)

{
  long *plVar1;
  code *pcVar2;
  undefined4 *puVar3;
  LRESULT LVar4;
  uint uVar5;
  int *in_ECX;
  WPARAM wParam;
  int iVar6;
  uint local_18;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x827b01;
  FUN_008829ae(param_1);
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,in_ECX[0x1c]);
    CArchive::operator<<(param_1,in_ECX[0x23]);
    CArchive::operator<<(param_1,in_ECX[0x1d]);
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x2e));
    CArchive::operator<<(param_1,in_ECX[0x1e]);
    CArchive::operator<<(param_1,in_ECX[0x22]);
    if (in_ECX[0x2d] != 0) {
      FUN_00813b58();
      pcVar2 = *(code **)(*in_ECX + 0xe4);
      guard_check_icall();
      (*pcVar2)();
      RemoveAll();
      wParam = 0;
      LVar4 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x146,0,0);
      if (0 < LVar4) {
        do {
          CStringT<>();
          local_8 = 0;
          GetLBText(wParam,local_14);
          AddTail(local_14);
          uVar5 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x150,wParam,0);
          CList<unsigned_int,unsigned_int>::AddTail
                    ((CList<unsigned_int,unsigned_int> *)(in_ECX + 0x36),uVar5);
          local_8 = 0xffffffff;
          FUN_00406b10();
          wParam = wParam + 1;
          LVar4 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x146,0,0);
        } while ((int)wParam < LVar4);
      }
    }
    pcVar2 = *(code **)(in_ECX[0x2f] + 8);
    guard_check_icall(param_1);
    (*pcVar2)();
    puVar3 = (undefined4 *)in_ECX[0x37];
    while (puVar3 != (undefined4 *)0x0) {
      plVar1 = puVar3 + 2;
      puVar3 = (undefined4 *)*puVar3;
      CArchive::operator<<(param_1,*plVar1);
    }
  }
  else {
    CArchive::operator>>(param_1,in_ECX + 0x1c);
    in_ECX[0x17] = in_ECX[0x15] + in_ECX[0x1c];
    CArchive::operator>>(param_1,in_ECX + 0x23);
    CArchive::operator>>(param_1,in_ECX + 0x1d);
    FUN_0047fc90(in_ECX + 0x2e);
    CArchive::operator>>(param_1,in_ECX + 0x1e);
    CArchive::operator>>(param_1,in_ECX + 0x22);
    pcVar2 = *(code **)(in_ECX[0x2f] + 8);
    guard_check_icall(param_1);
    (*pcVar2)();
    pcVar2 = *(code **)(*in_ECX + 0xe4);
    guard_check_icall();
    (*pcVar2)();
    RemoveAll();
    iVar6 = 0;
    if (0 < in_ECX[0x32]) {
      do {
        CArchive::operator>>(param_1,(long *)&local_18);
        CList<unsigned_int,unsigned_int>::AddTail
                  ((CList<unsigned_int,unsigned_int> *)(in_ECX + 0x36),local_18);
        iVar6 = iVar6 + 1;
      } while (iVar6 < in_ECX[0x32]);
    }
    pcVar2 = *(code **)(*in_ECX + 0xe0);
    guard_check_icall();
    (*pcVar2)();
    FUN_008279e7(in_ECX[0x1d],1);
  }
  return;
}



