/* CMFCImageEditorPaletteBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCImageEditorPaletteBar[1], CMFCPrintPreviewToolBar[1], CMFCToolBar[1] */
/* 007fb18d  FUN_007fb18d  51 bytes, 0 callers */

void FUN_007fb18d(byte param_1)

{
  FUN_007faf4a();
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




/* vtable slots: CMFCImageEditorPaletteBar[10], CMFCToolBar[10] */
/* 007fe28a  FUN_007fe28a  6 bytes, 0 callers */

undefined ** FUN_007fe28a(void)

{
  return &PTR_FUN_0098c478;
}




/* vtable slots: CMFCImageEditorPaletteBar[0], CMFCToolBar[0] */
/* 007fe36e  FUN_007fe36e  6 bytes, 0 callers */

undefined ** FUN_007fe36e(void)

{
  return &PTR_s_CMFCToolBar_00a005c4;
}




/* vtable slots: CMFCImageEditorPaletteBar[145], CMFCMenuBar[145], CMFCOutlookBarPane[145], CMFCPopupMenuBar[145], CMFCPrintPreviewToolBar[145], CMFCTasksPaneToolBar[145], CMFCToolBar[145] */
/* 0080345e  FUN_0080345e  187 bytes, 2 callers */

void FUN_0080345e(CCmdTarget *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  CWnd *in_ECX;
  int iVar3;
  undefined **local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_c;
  
  CCmdUI::CCmdUI((CCmdUI *)&local_2c);
  local_c = *(uint *)(in_ECX + 0xc48);
  iVar3 = 0;
  local_2c = CMFCToolBarCmdUI::vftable;
  local_24 = 0;
  if (local_c != 0) {
    do {
      iVar2 = FUN_007fde79(local_24);
      if (iVar2 == 0) {
        return;
      }
      if ((DAT_00a13bac != 0) && (*(uint *)(DAT_00a13bac + 0x24) <= *(uint *)(iVar2 + 0x20))) {
        param_2 = param_2 & -(uint)(*(uint *)(DAT_00a13bac + 0x28) < *(uint *)(iVar2 + 0x20));
      }
      local_28 = *(undefined4 *)(iVar2 + 0x20);
      if (((((*(byte *)(iVar2 + 0x24) & 1) == 0) && (uVar1 = *(uint *)(iVar2 + 0x20), uVar1 != 0))
          && (0x1ef < uVar1 - 0xf000)) && (uVar1 < 0xff00)) {
        FUN_0078ff63(param_1,param_2);
      }
      local_24 = local_24 + 1;
    } while (local_24 < local_c);
  }
  if ((param_2 != 0) && (*(int *)(in_ECX + 0xbb0) != 0)) {
    iVar3 = 1;
  }
  CWnd::UpdateDialogControls(in_ECX,param_1,iVar3);
  return;
}




/* vtable slots: CMFCImageEditorPaletteBar[213] */
/* 008c9030  FUN_008c9030  19 bytes, 0 callers */

undefined4 FUN_008c9030(void)

{
  int iVar1;
  undefined1 local_c [8];
  
  iVar1 = FUN_007c23d4(local_c);
  return *(undefined4 *)(iVar1 + 4);
}



