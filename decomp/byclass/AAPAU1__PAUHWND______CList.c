/* AAPAU1::PAUHWND__::?$CList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: AAPAU1::PAUHWND__::?$CList[0], AAPAV1::IAAIPAVCMFCToolBarButton::?$CMap[0], AAU12::CMFCDynamicLayoutData::UItem::?$CList[0], AAU1::UAFX_AUTOHIDE_DOCKSITE_SAVE_INFO::?$CList[0], ABU12::CTaskDialog::U_CTaskDialogButton::?$CArray[0], ABV1::VCVariantBoolPair::?$CArray[0], ABW412::CArchive::W4LoadArrayObjType::?$CArray[0], CCellObj[0], CCommandLineInfo[0], CDataHenkei[0], CDataHndl[0], CDataRecoveryHandler[0], CDockingManager[0], CDrawingManager[0], CMFCAcceleratorKey[0], CMFCBaseVisualManager[0], CMFCCaptionButton[0], CMFCCaptionButtonEx[0], CMFCCaptionMenuButton[0], CMFCCmdUsageCount[0], CMFCControlContainer[0], CMFCFontInfo[0], CMFCTabInfo[0], CMFCTasksPanePropertyPage[0], CMFCToolBarImages[0], CRecentDockSiteInfo[0], CRecentPaneContainerInfo[0], CSmartDockingInfo[0], CSmartDockingManager[0], CTagManager[0], CZahyouWritRead[0], CZoom[0], CZukei[0], CZukeiObject[0], HABH::?$CArray[0], HH::?$CArray[0], HH::?$CList[0], HH::PAU1::PAUHICON__::?$CMap[0], HH::PAU1::PAUHWND__::?$CMap[0], HHHH::?$CMap[0], HHII::?$CMap[0], IAAI::?$CList[0], II::?$CArray[0], II::?$CList[0], IIHH::?$CMap[0], IIII::?$CMap[0], IIKK::?$CMap[0], JJ::?$CArray[0], KK::?$CArray[0], KK::?$CList[0], NN::?$CArray[0], PAU1::IIPAUHICON__::?$CMap[0], PAU1::IIPAUHWND__::?$CMap[0], PAU1::PAUAFX_DYNAMIC_LAYOUT_ITEM::?$CList[0], PAU1::PAUHINSTANCE__::?$CList[0], PAU1::PAUHWND__::?$CArray[0], PAU1::PAUHWND__::?$CList[0], PAU1::PAU_ITEMIDLIST::?$CList[0], PAV12::CMFCVisualManagerBitmapCache::PAVCMFCVisualManagerBitmapCacheItem::?$CArray[0], PAV1::IIPAVCMFCRibbonStatusBarPane::?$CMap[0], PAV1::IIPAVCPane::?$CMap[0], PAV1::PAVCFrameWnd::?$CList[0], PAV1::PAVCMDIChildWndEx::?$CList[0], PAV1::PAVCMFCButton::?$CList[0], PAV1::PAVCMFCPropertyGridProperty::?$CList[0], PAV1::PAVCMFCRibbonBaseElement::?$CArray[0], PAV1::PAVCMFCRibbonContextCaption::?$CArray[0], PAV1::PAVCMFCRibbonKeyTip::?$CArray[0], PAV1::PAVCMFCRibbonPanel::?$CArray[0], PAV1::PAVCPropertyPage::?$CList[0], PAV2::PAVCImageList::PAV1::PAVCWnd::?$CMap[0], PAV3::PB_WPAVCDocument::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[0], PAV3::PB_WPAVCObList::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[0], PAXAAPAX::AAPAU1::PAUHMENU__::?$CMap[0], PB_W::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::KKV?$CStringT::?$CMap[0], PB_W::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::PAV1::PAVCDocument::?$CMap[0], PB_W::PB_WV12::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[0], PB_WHH::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[0], PB_W_N_N::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[0], U1::UCMFCRestoredTabInfo::?$CList[0], U1::UtagPOINT::?$CList[0], V1::VCSize::?$CArray[0] */
/* 0079d95a  FUN_0079d95a  6 bytes, 0 callers */

undefined ** FUN_0079d95a(void)

{
  return &PTR_s_CObject_0097de90;
}




/* vtable slots: AAPAU1::PAUHWND__::?$CList[1] */
/* 00844de7  FUN_00844de7  100 bytes, 0 callers */

void FUN_00844de7(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944167;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *in_ECX = CList<HWND__*,HWND__*&>::vftable;
  RemoveAll(uVar1);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: AAPAU1::PAUHWND__::?$CList[2], IAAI::?$CList[2] */
/* 00848f15  FUN_00848f15  102 bytes, 0 callers */

void FUN_00848f15(CArchive *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined1 local_8 [4];
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      FUN_00799245(param_1,local_8,1);
      AddTail(local_8);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    for (puVar2 = *(undefined4 **)(in_ECX + 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      FUN_00799245(param_1,puVar2 + 2,1);
    }
  }
  return;
}



