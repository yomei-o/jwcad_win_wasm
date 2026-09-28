/* CLayerButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CLayerButton[1] */
/* 00551a00  FUN_00551a00  68 bytes, 0 callers */

undefined4 FUN_00551a00(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00551980();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xb8);
    }
  }
  return in_ECX;
}




/* vtable slots: CLayerButton[90] */
/* 00551a50  FUN_00551a50  594 bytes, 0 callers */

void FUN_00551a50(tagDRAWITEMSTRUCT *param_1)

{
  uint uVar1;
  int cWidth;
  int cHeight;
  CBitmapButton *in_ECX;
  int cEscapement;
  int cOrientation;
  int cWeight;
  DWORD bItalic;
  DWORD bUnderline;
  DWORD bStrikeOut;
  DWORD iCharSet;
  DWORD iOutPrecision;
  DWORD iClipPrecision;
  DWORD iQuality;
  DWORD iPitchAndFamily;
  wchar_t *pszFaceName;
  undefined1 local_3c [8];
  undefined1 local_34 [8];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20 [4];
  CBitmapButton *local_1c;
  int local_18;
  CDC *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bffd;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = in_ECX;
  CBitmapButton::DrawItem(in_ECX,param_1);
  local_18 = 0;
  if (((*(uint *)(param_1 + 0x10) & 1) != 0) || ((*(uint *)(param_1 + 0x10) & 0x10) != 0)) {
    local_18 = 1;
  }
  local_14 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  FUN_0079f0b8(2);
  local_2c = (**(code **)(*(int *)local_14 + 0x24))(8,uVar1);
  FUN_00480c40();
  local_8 = 0;
  CStringT<>();
  local_8._0_1_ = 1;
  FUN_004059f0(local_20,&DAT_00969338,*(undefined4 *)(local_1c + 0xb4));
  pszFaceName = L"Courier";
  iPitchAndFamily = 0x30;
  iQuality = 0;
  iClipPrecision = 0;
  iOutPrecision = 0;
  iCharSet = 1;
  bStrikeOut = 0;
  bUnderline = 0;
  bItalic = 0;
  cWeight = 400;
  cOrientation = 0;
  cEscapement = 0;
  cWidth = FUN_004f72f0(10);
  cHeight = FUN_004f74b0(10);
  FID_conflict_CreateFontW
            (cHeight,cWidth,cEscapement,cOrientation,cWeight,bItalic,bUnderline,bStrikeOut,iCharSet,
             iOutPrecision,iClipPrecision,iQuality,iPitchAndFamily,pszFaceName);
  local_24 = (**(code **)(*(int *)local_14 + 0x28))(local_34);
  FUN_004bbd50(local_18 + 5,local_18 + 5,local_20);
  (**(code **)(*(int *)local_14 + 0x28))(local_24);
  (**(code **)(*(int *)local_14 + 0x24))(7);
  local_28 = (**(code **)(*(int *)local_14 + 0x24))(5);
  CMenu::CheckMenuRadioItem
            ((CMenu *)local_14,local_18 + 2,local_18 + 4,local_18 + 0x11,local_18 + 0x13);
  FUN_0079df60(0,1,0xff);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0079efbc(local_3c);
  if ((*(uint *)(local_1c + 0xb4) & 1) != 0) {
    CMenu::CheckMenuRadioItem
              ((CMenu *)local_14,local_18 + 2,local_18 + 2,local_18 + 10,local_18 + 4);
  }
  if ((*(uint *)(local_1c + 0xb4) & 2) != 0) {
    CMenu::CheckMenuRadioItem
              ((CMenu *)local_14,local_18 + 10,local_18 + 2,local_18 + 0x11,local_18 + 4);
  }
  FUN_0079efbc(local_28);
  FUN_0079efbc(local_2c);
  local_8._0_1_ = 1;
  FUN_0041c990();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404540();
  local_8 = 0xffffffff;
  FUN_00480fe0();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CLayerButton[10] */
/* 00551ce0  FUN_00551ce0  16 bytes, 0 callers */

void FUN_00551ce0(void)

{
  FUN_00551cf0();
  return;
}



