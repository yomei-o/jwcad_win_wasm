/* CAfxStringMgr -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CAfxStringMgr[0] */
/* 0078f440  FUN_0078f440  61 bytes, 0 callers */

undefined4 * FUN_0078f440(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 in_ECX;
  
  if ((-1 < param_1) &&
     (puVar1 = (undefined4 *)FUN_00900c73((param_1 + 1) * param_2 + 0x10),
     puVar1 != (undefined4 *)0x0)) {
    puVar1[1] = 0;
    *puVar1 = in_ECX;
    puVar1[3] = 1;
    puVar1[2] = param_1;
    return puVar1;
  }
  return (undefined4 *)0x0;
}




/* vtable slots: CAfxStringMgr[4], CFrameWnd[92], CFrameWndEx[92], CMDIChildWnd[92], CMDIChildWndEx[92], CMFCColorPopupMenu[92], CMFCDropDownFrame[92], CMFCPopupMenu[92], CMFCRibbonMiniToolBar[92], CMFCRibbonPanelMenu[92], CMFCShadowWnd[92], CMainFrame[92], CMiniDockFrameWnd[92], CMiniFrameWnd[92], COleCntrFrameWnd[92], COleCntrFrameWndEx[92], COleDocIPFrameWnd[92], COleDocIPFrameWndEx[92], COleIPFrameWnd[92], COleIPFrameWndEx[92] */
/* 0078f4b5  FUN_0078f4b5  3 bytes, 2 callers */

void FUN_0078f4b5(void)

{
  return;
}




/* vtable slots: CAfxStringMgr[1], CMemFile[25] */
/* 0078f4b8  FUN_0078f4b8  16 bytes, 0 callers */

void FUN_0078f4b8(undefined4 param_1)

{
  FUN_008f43b0(param_1);
  return;
}




/* vtable slots: CAfxStringMgr[3] */
/* 0078f4c8  FUN_0078f4c8  8 bytes, 0 callers */

int FUN_0078f4c8(void)

{
  int in_ECX;
  
  LOCK();
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  UNLOCK();
  return in_ECX + 4;
}




/* vtable slots: CAfxStringMgr[2] */
/* 0078f4d0  FUN_0078f4d0  48 bytes, 0 callers */

int FUN_0078f4d0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((-1 < param_2) && (iVar1 = FUN_00908899(param_1,(param_2 + 1) * param_3 + 0x10), iVar1 != 0))
  {
    *(int *)(iVar1 + 8) = param_2;
    return iVar1;
  }
  return 0;
}



