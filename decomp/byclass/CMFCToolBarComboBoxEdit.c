/* CMFCToolBarComboBoxEdit -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarComboBoxEdit[1] */
/* 008255ad  FUN_008255ad  57 bytes, 0 callers */

void FUN_008255ad(byte param_1)

{
  ExternalContextBase *in_ECX;
  
  *(undefined ***)in_ECX = CMFCToolBarComboBoxEdit::vftable;
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




/* vtable slots: CMFCToolBarComboBoxEdit[10] */
/* 00825ebe  FUN_00825ebe  6 bytes, 0 callers */

undefined ** FUN_00825ebe(void)

{
  return &PTR_FUN_0098f610;
}




/* vtable slots: CMFCToolBarComboBoxEdit[67] */
/* 008276fc  FUN_008276fc  747 bytes, 0 callers */

undefined4 FUN_008276fc(int param_1)

{
  int iVar1;
  SHORT SVar2;
  LRESULT LVar3;
  undefined4 uVar4;
  CWnd *pCVar5;
  HWND pHVar6;
  int iVar7;
  int in_ECX;
  LPARAM lParam;
  
  lParam = 0;
  if ((*(int *)(param_1 + 4) == 0x20a) &&
     (iVar7 = *(int *)(*(int *)(in_ECX + 0x80) + 0xb4), iVar7 != 0)) {
    LVar3 = SendMessageW(*(HWND *)(iVar7 + 0x20),0x157,0,0);
    if (LVar3 == 0) goto LAB_0082775c;
LAB_00827736:
    SendMessageW(*(HWND *)(*(int *)(*(int *)(in_ECX + 0x80) + 0xb4) + 0x20),*(UINT *)(param_1 + 4),
                 *(WPARAM *)(param_1 + 8),*(LPARAM *)(param_1 + 0xc));
LAB_00827754:
    uVar4 = 1;
  }
  else {
LAB_0082775c:
    if (*(int *)(param_1 + 4) == 0x100) {
      SVar2 = GetKeyState(0x12);
      if (-1 < SVar2) {
        SVar2 = GetKeyState(0x11);
        if ((-1 < SVar2) && (iVar7 = *(int *)(*(int *)(in_ECX + 0x80) + 0xb4), iVar7 != 0)) {
          iVar1 = *(int *)(param_1 + 8);
          if (iVar1 == 0xd) {
LAB_008277e3:
            FUN_00797df8();
            LVar3 = SendMessageW(*(HWND *)(*(int *)(*(int *)(in_ECX + 0x80) + 0xb4) + 0x20),0x157,0,
                                 0);
            if (LVar3 != 0) goto LAB_00827736;
            pCVar5 = CWnd::GetOwner(*(CWnd **)(*(int *)(in_ECX + 0x80) + 0xb4));
            if (pCVar5 != (CWnd *)0x0) {
              FUN_00792c64(*(int *)(in_ECX + 0x80) + 0xb8);
              pCVar5 = CWnd::GetOwner(*(CWnd **)(*(int *)(in_ECX + 0x80) + 0xb4));
              iVar7 = *(int *)(*(int *)(in_ECX + 0x80) + 0xb4);
              if (iVar7 != 0) {
                lParam = *(LPARAM *)(iVar7 + 0x20);
              }
              PostMessageW(*(HWND *)(pCVar5 + 0x20),0x111,
                           (uint)*(ushort *)(*(int *)(in_ECX + 0x80) + 0x20),lParam);
            }
            goto LAB_00827754;
          }
          if (((((iVar1 == 0x21) || (iVar1 == 0x22)) || (iVar1 == 0x23)) ||
              ((iVar1 == 0x24 || (iVar1 == 0x26)))) || (iVar1 == 0x28)) {
            LVar3 = SendMessageW(*(HWND *)(iVar7 + 0x20),0x157,0,0);
            if (LVar3 != 0) goto LAB_008277e3;
          }
        }
      }
      iVar7 = *(int *)(param_1 + 8);
      if (iVar7 == 9) {
        pHVar6 = GetParent(*(HWND *)(in_ECX + 0x20));
        pCVar5 = CWnd::FromHandle(pHVar6);
        if (pCVar5 != (CWnd *)0x0) {
          pHVar6 = GetParent(*(HWND *)(in_ECX + 0x20));
          pCVar5 = CWnd::FromHandle(pHVar6);
          pHVar6 = GetNextDlgTabItem(*(HWND *)(pCVar5 + 0x20),*(HWND *)(in_ECX + 0x20),0);
          CWnd::FromHandle(pHVar6);
LAB_008279cc:
          FUN_00797df8();
          goto LAB_00827754;
        }
      }
      else if (iVar7 == 0x1b) {
        iVar7 = *(int *)(*(int *)(in_ECX + 0x80) + 0xb4);
        if (iVar7 != 0) {
          SendMessageW(*(HWND *)(iVar7 + 0x20),0x14f,0,0);
        }
        iVar7 = FUN_00792b4c();
        if (iVar7 != 0) {
          FUN_00792b4c();
          goto LAB_008279cc;
        }
      }
      else if ((iVar7 == 0x26) || (iVar7 == 0x28)) {
        SVar2 = GetKeyState(0x12);
        if (-1 < SVar2) {
          SVar2 = GetKeyState(0x11);
          if ((-1 < SVar2) && (iVar7 = *(int *)(*(int *)(in_ECX + 0x80) + 0xb4), iVar7 != 0)) {
            LVar3 = SendMessageW(*(HWND *)(iVar7 + 0x20),0x157,0,0);
            if (LVar3 == 0) {
              SendMessageW(*(HWND *)(*(int *)(*(int *)(in_ECX + 0x80) + 0xb4) + 0x20),0x14f,1,0);
              pHVar6 = GetParent(*(HWND *)(*(int *)(*(int *)(in_ECX + 0x80) + 0xb4) + 0x20));
              pCVar5 = CWnd::FromHandle(pHVar6);
              if (pCVar5 != (CWnd *)0x0) {
                pHVar6 = GetParent(*(HWND *)(*(int *)(*(int *)(in_ECX + 0x80) + 0xb4) + 0x20));
                pCVar5 = CWnd::FromHandle(pHVar6);
                InvalidateRect(*(HWND *)(pCVar5 + 0x20),(RECT *)(*(int *)(in_ECX + 0x80) + 0x90),1);
              }
            }
            goto LAB_00827754;
          }
        }
      }
    }
    uVar4 = FUN_007949fb(param_1);
  }
  return uVar4;
}



