/* CMFCRibbonBaseElement -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonBaseElement[82], CMFCRibbonBaseElement[109], CMFCRibbonButton[82], CMFCRibbonButton[109], CMFCRibbonButtonsGroup[82], CMFCRibbonButtonsGroup[109], CMFCRibbonCaptionButton[82], CMFCRibbonCaptionButton[109], CMFCRibbonColorButton[109], CMFCRibbonColorMenuButton[82], CMFCRibbonColorMenuButton[109], CMFCRibbonDefaultPanelButton[82], CMFCRibbonDefaultPanelButton[109], CMFCRibbonEdit[82], CMFCRibbonEdit[109], CMFCRibbonGallery[109], CMFCRibbonGalleryIcon[82], CMFCRibbonLabel[82], CMFCRibbonLabel[109], CMFCRibbonLaunchButton[82], CMFCRibbonLaunchButton[109], CMFCRibbonQuickAccessCustomizeButton[82], CMFCRibbonQuickAccessCustomizeButton[109], CMFCRibbonQuickAccessToolBar[82], CMFCRibbonQuickAccessToolBar[109], CMFCRibbonRecentFilesList[82], CMFCRibbonRecentFilesList[109], CMFCRibbonSeparator[82], CMFCRibbonSeparator[109], CMFCRibbonTab[82], CMFCRibbonTab[109], CMFCRibbonUndoButton[109], CMFCVisualManager[189], CMFCVisualManagerOffice2003[189], CMFCVisualManagerOffice2007[189], CMFCVisualManagerOfficeXP[189], CRibbonCategoryScroll[82], CRibbonCategoryScroll[109], CRibbonUndoLabel[82], CRibbonUndoLabel[109] */
/* 007f320c  FUN_007f320c  7 bytes, 0 callers */

undefined4 FUN_007f320c(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa4);
}




/* vtable slots: CMFCRibbonBaseElement[72], CMFCRibbonButtonsGroup[72], CMFCRibbonQuickAccessToolBar[72], CMFCRibbonRecentFilesList[72], CMFCRibbonSeparator[72], CMFCRibbonTab[72], CMFCVisualManager[92], CMFCVisualManager[158], CMFCVisualManagerOffice2003[158], CMFCVisualManagerOffice2007[158], CMFCVisualManagerOfficeXP[158] */
/* 007f63a6  FUN_007f63a6  3 bytes, 0 callers */

void FUN_007f63a6(void)

{
  return;
}




/* vtable slots: CMFCRibbonBaseElement[52], CMFCRibbonButton[52], CMFCRibbonButtonsGroup[52], CMFCRibbonCaptionButton[52], CMFCRibbonColorButton[52], CMFCRibbonColorMenuButton[52], CMFCRibbonDefaultPanelButton[52], CMFCRibbonGallery[52], CMFCRibbonGalleryIcon[52], CMFCRibbonLabel[52], CMFCRibbonLaunchButton[52], CMFCRibbonQuickAccessCustomizeButton[52], CMFCRibbonQuickAccessToolBar[52], CMFCRibbonRecentFilesList[52], CMFCRibbonSeparator[52], CMFCRibbonTab[52], CMFCRibbonUndoButton[52], CMFCVisualManagerOffice2003[48], CMFCVisualManagerOffice2007[48], CMFCVisualManagerOfficeXP[48], CRibbonCategoryScroll[52], CRibbonUndoLabel[52] */
/* 00825dd2  FUN_00825dd2  7 bytes, 1 callers */

undefined4 FUN_00825dd2(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 200);
}




/* vtable slots: CMFCRibbonBaseElement[1] */
/* 00863101  FUN_00863101  51 bytes, 0 callers */

void FUN_00863101(byte param_1)

{
  FUN_00863031();
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




/* vtable slots: CMFCRibbonBaseElement[120], CMFCRibbonButton[120], CMFCRibbonCaptionButton[120], CMFCRibbonColorButton[120], CMFCRibbonColorMenuButton[120], CMFCRibbonDefaultPanelButton[120], CMFCRibbonEdit[120], CMFCRibbonGallery[120], CMFCRibbonGalleryIcon[120], CMFCRibbonLabel[120], CMFCRibbonLaunchButton[120], CMFCRibbonQuickAccessCustomizeButton[120], CMFCRibbonSeparator[120], CMFCRibbonTab[120], CMFCRibbonUndoButton[120], CRibbonCategoryScroll[120], CRibbonUndoLabel[120] */
/* 00863193  FUN_00863193  159 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00863193(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  iVar2 = FUN_0078e624(0x98);
  uVar4 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_008c5baa(in_ECX,0);
  }
  FUN_0079c90d(*(undefined4 *)(param_1 + 8),uVar3);
  if (*(int *)(in_ECX[0x1a] + -0xc) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x138);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      iVar2 = FUN_0078e624(0x98);
      if (iVar2 != 0) {
        uVar4 = FUN_008c5baa(in_ECX,1);
      }
      FUN_0079c90d(*(undefined4 *)(param_1 + 8),uVar4);
    }
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[93], CMFCRibbonTab[93] */
/* 00863232  FUN_00863232  399 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

WPARAM FUN_00863232(int param_1)

{
  code *pcVar1;
  wchar_t *pwVar2;
  LRESULT LVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  WPARAM WVar6;
  WPARAM local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x86323e;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x20) == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar5 = in_ECX[0x29];
  if (((iVar5 == 0) || (iVar5 == -1)) || (iVar5 - 0xe110U < 0x10)) {
LAB_008633b7:
    WVar6 = 0xffffffff;
  }
  else {
    WVar6 = 0;
    local_14[0] = 0;
    LVar3 = SendMessageW(*(HWND *)(param_1 + 0x20),0x18b,0,0);
    if (0 < LVar3) {
      do {
        piVar4 = (int *)SendMessageW(*(HWND *)(param_1 + 0x20),0x199,WVar6,0);
        if ((piVar4 != (int *)0x0) && (piVar4[0x29] == in_ECX[0x29])) {
          pcVar1 = *(code **)(*piVar4 + 0x138);
          guard_check_icall();
          iVar5 = (*pcVar1)();
          if ((iVar5 == 0) || (WVar6 = local_14[0], *(int *)(param_1 + 0x88) != 0))
          goto LAB_008633b7;
        }
        WVar6 = WVar6 + 1;
        local_14[0] = WVar6;
        LVar3 = SendMessageW(*(HWND *)(param_1 + 0x20),0x18b,0,0);
      } while ((int)WVar6 < LVar3);
    }
    pcVar1 = *(code **)(*in_ECX + 0x1ac);
    guard_check_icall();
    (*pcVar1)();
    iVar5 = FUN_004054a0(in_ECX[0x1b] + -0x10);
    local_14[0] = iVar5 + 0x10;
    local_8 = 0;
    if (*(int *)(iVar5 + 4) == 0) {
      pwVar2 = (wchar_t *)in_ECX[0x18];
      if (pwVar2 == (wchar_t *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_008f899d(pwVar2);
      }
      ATL::CSimpleStringT<wchar_t,0>::SetString((CSimpleStringT<wchar_t,0> *)local_14,pwVar2,iVar5);
    }
    FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
    FUN_007fa476(0x26);
    FUN_005946a0(&DAT_0098dde0,&DAT_0095bc0c);
    WVar6 = SendMessageW(*(HWND *)(param_1 + 0x20),0x180,0,local_14[0]);
    SendMessageW(*(HWND *)(param_1 + 0x20),0x19a,WVar6,(LPARAM)in_ECX);
    FUN_00406b10();
  }
  return WVar6;
}




/* vtable slots: CMFCRibbonBaseElement[80], CMFCRibbonButton[80], CMFCRibbonButtonsGroup[80], CMFCRibbonCaptionButton[80], CMFCRibbonColorButton[80], CMFCRibbonColorMenuButton[80], CMFCRibbonEdit[80], CMFCRibbonGallery[80], CMFCRibbonLaunchButton[80], CMFCRibbonQuickAccessCustomizeButton[80], CMFCRibbonQuickAccessToolBar[80], CMFCRibbonRecentFilesList[80], CMFCRibbonSeparator[80], CMFCRibbonTab[80], CMFCRibbonUndoButton[80], CRibbonCategoryScroll[80], CRibbonUndoLabel[80] */
/* 00863459  CanBeAddedToQuickAccessToolBar  31 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCRibbonBaseElement::CanBeAddedToQuickAccessToolBar(void)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCRibbonBaseElement::CanBeAddedToQuickAccessToolBar(CMFCRibbonBaseElement *this)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(this + 0xa4);
  if ((uVar1 != 0) && (uVar1 != 0xffffffff)) {
    iVar2 = IsStandardCommand(uVar1);
    if (iVar2 == 0) {
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCRibbonBaseElement[60], CMFCRibbonButton[60], CMFCRibbonButtonsGroup[60], CMFCRibbonCaptionButton[60], CMFCRibbonColorButton[60], CMFCRibbonColorMenuButton[60], CMFCRibbonDefaultPanelButton[60], CMFCRibbonEdit[60], CMFCRibbonGallery[60], CMFCRibbonGalleryIcon[60], CMFCRibbonLabel[60], CMFCRibbonLaunchButton[60], CMFCRibbonQuickAccessCustomizeButton[60], CMFCRibbonQuickAccessToolBar[60], CMFCRibbonRecentFilesList[60], CMFCRibbonSeparator[60], CMFCRibbonTab[60], CMFCRibbonUndoButton[60], CRibbonCategoryScroll[60], CRibbonUndoLabel[60] */
/* 00863478  FUN_00863478  79 bytes, 0 callers */

undefined4 FUN_00863478(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  code *pcVar3;
  
  pcVar3 = *(code **)(*in_ECX + 0xe8);
  guard_check_icall();
  iVar1 = (*pcVar3)();
  if ((iVar1 == 0) && (in_ECX[0x2e] == 0)) {
    if (in_ECX[0x2f] == 0) {
      pcVar3 = *(code **)(*in_ECX + 0x108);
    }
    else {
      pcVar3 = *(code **)(*in_ECX + 0x10c);
    }
    guard_check_icall();
    uVar2 = (*pcVar3)();
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonBaseElement[102], CMFCRibbonButtonsGroup[102], CMFCRibbonQuickAccessToolBar[102], CMFCRibbonRecentFilesList[102], CMFCRibbonSeparator[102], CMFCRibbonTab[102] */
/* 008634c7  FUN_008634c7  102 bytes, 2 callers */

void FUN_008634c7(void)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x9c) != 0) &&
     (BVar2 = IsWindow(*(HWND *)(*(int *)(in_ECX + 0x9c) + 0x20)), BVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x9c) + 0x1cc);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return;
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x9c) + 0x130) = 0;
    FUN_0081c095(0);
  }
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[90] */
/* 0086352d  CopyFrom  232 bytes, 4 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonBaseElement::CopyFrom(class CMFCRibbonBaseElement
   const &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonBaseElement::CopyFrom(CMFCRibbonBaseElement *this,CMFCRibbonBaseElement *param_1)

{
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 0x60),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x60));
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 100),(CSimpleStringT<wchar_t,0> *)(param_1 + 100))
  ;
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 0x68),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x68));
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 0x6c),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x6c));
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 0x70),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x70));
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  *(undefined4 *)(this + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
  *(undefined4 *)(this + 0x100) = *(undefined4 *)(param_1 + 0x100);
  *(undefined4 *)(this + 0x104) = *(undefined4 *)(param_1 + 0x104);
  return;
}




/* vtable slots: CMFCRibbonBaseElement[103], CMFCRibbonButton[103], CMFCRibbonCaptionButton[103], CMFCRibbonColorButton[103], CMFCRibbonColorMenuButton[103], CMFCRibbonDefaultPanelButton[103], CMFCRibbonEdit[103], CMFCRibbonGallery[103], CMFCRibbonGalleryIcon[103], CMFCRibbonLabel[103], CMFCRibbonLaunchButton[103], CMFCRibbonQuickAccessCustomizeButton[103], CMFCRibbonSeparator[103], CMFCRibbonTab[103], CMFCRibbonUndoButton[103], CRibbonCategoryScroll[103], CRibbonUndoLabel[103] */
/* 00863668  FUN_00863668  20 bytes, 0 callers */

uint FUN_00863668(uint param_1)

{
  uint in_ECX;
  
  return ~-(uint)(param_1 != in_ECX) & in_ECX;
}




/* vtable slots: CMFCRibbonBaseElement[105], CMFCRibbonSeparator[105], CMFCRibbonTab[105] */
/* 0086367c  FUN_0086367c  24 bytes, 1 callers */

uint FUN_0086367c(int param_1)

{
  uint in_ECX;
  
  return ~-(uint)(*(int *)(in_ECX + 0xa0) != param_1) & in_ECX;
}




/* vtable slots: CMFCRibbonBaseElement[104], CMFCRibbonSeparator[104], CMFCRibbonTab[104] */
/* 00863694  FUN_00863694  24 bytes, 1 callers */

uint FUN_00863694(int param_1)

{
  uint in_ECX;
  
  return ~-(uint)(*(int *)(in_ECX + 0xa4) != param_1) & in_ECX;
}




/* vtable slots: CMFCRibbonBaseElement[106], CMFCRibbonButton[106], CMFCRibbonCaptionButton[106], CMFCRibbonColorButton[106], CMFCRibbonColorMenuButton[106], CMFCRibbonDefaultPanelButton[106], CMFCRibbonEdit[106], CMFCRibbonGallery[106], CMFCRibbonGalleryIcon[106], CMFCRibbonLabel[106], CMFCRibbonLaunchButton[106], CMFCRibbonQuickAccessCustomizeButton[106], CMFCRibbonSeparator[106], CMFCRibbonTab[106], CMFCRibbonUndoButton[106], CRibbonCategoryScroll[106], CRibbonUndoLabel[106] */
/* 008636ac  FUN_008636ac  24 bytes, 0 callers */

uint FUN_008636ac(int param_1)

{
  uint in_ECX;
  
  return ~-(uint)(*(int *)(in_ECX + 0x8c) != param_1) & in_ECX;
}




/* vtable slots: CMFCRibbonBaseElement[63], CMFCRibbonBaseElement[64], CMFCRibbonButtonsGroup[63], CMFCRibbonButtonsGroup[64], CMFCRibbonCaptionButton[63], CMFCRibbonGalleryIcon[63], CMFCRibbonQuickAccessToolBar[63], CMFCRibbonQuickAccessToolBar[64], CMFCRibbonRecentFilesList[63], CMFCRibbonRecentFilesList[64], CMFCRibbonSeparator[63], CMFCRibbonSeparator[64], CMFCRibbonTab[63], CMFCRibbonTab[64] */
/* 008636c4  FUN_008636c4  42 bytes, 0 callers */

undefined4 FUN_008636c4(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xf8);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return param_1;
}




/* vtable slots: CMFCRibbonBaseElement[49], CMFCRibbonButton[49], CMFCRibbonButtonsGroup[49], CMFCRibbonCaptionButton[49], CMFCRibbonColorButton[49], CMFCRibbonColorMenuButton[49], CMFCRibbonDefaultPanelButton[49], CMFCRibbonEdit[49], CMFCRibbonGallery[49], CMFCRibbonLabel[49], CMFCRibbonLaunchButton[49], CMFCRibbonQuickAccessCustomizeButton[49], CMFCRibbonQuickAccessToolBar[49], CMFCRibbonRecentFilesList[49], CMFCRibbonSeparator[49], CMFCRibbonTab[49], CMFCRibbonUndoButton[49], CRibbonCategoryScroll[49], CRibbonUndoLabel[49] */
/* 008636ee  FUN_008636ee  28 bytes, 0 callers */

void FUN_008636ee(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004054a0(*(int *)(in_ECX + 0x70) + -0x10);
  *param_1 = iVar1 + 0x10;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[144], CMFCRibbonButton[144], CMFCRibbonButtonsGroup[144], CMFCRibbonCaptionButton[144], CMFCRibbonColorButton[144], CMFCRibbonColorMenuButton[144], CMFCRibbonDefaultPanelButton[144], CMFCRibbonEdit[144], CMFCRibbonGallery[144], CMFCRibbonGalleryIcon[144], CMFCRibbonLabel[144], CMFCRibbonLaunchButton[144], CMFCRibbonQuickAccessCustomizeButton[144], CMFCRibbonQuickAccessToolBar[144], CMFCRibbonRecentFilesList[144], CMFCRibbonSeparator[144], CMFCRibbonTab[144], CMFCRibbonUndoButton[144], CRibbonCategoryScroll[144], CRibbonUndoLabel[144] */
/* 0086370a  FUN_0086370a  18 bytes, 0 callers */

undefined4 FUN_0086370a(void)

{
  undefined4 *puVar1;
  undefined1 local_c [8];
  
  puVar1 = (undefined4 *)FUN_0081507c(local_c);
  return *puVar1;
}




/* vtable slots: CMFCRibbonBaseElement[113], CMFCRibbonButton[113], CMFCRibbonCaptionButton[113], CMFCRibbonColorMenuButton[113], CMFCRibbonDefaultPanelButton[113], CMFCRibbonEdit[113], CMFCRibbonGalleryIcon[113], CMFCRibbonLabel[113], CMFCRibbonLaunchButton[113], CMFCRibbonQuickAccessCustomizeButton[113], CMFCRibbonSeparator[113], CMFCRibbonTab[113], CRibbonCategoryScroll[113], CRibbonUndoLabel[113] */
/* 0086371c  FUN_0086371c  33 bytes, 1 callers */

uint FUN_0086371c(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xe4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  return -(uint)(iVar2 != 0) & (uint)in_ECX;
}




/* vtable slots: CMFCRibbonBaseElement[123], CMFCRibbonButtonsGroup[123], CMFCRibbonQuickAccessToolBar[123], CMFCRibbonRecentFilesList[123], CMFCRibbonSeparator[123], CMFCRibbonTab[123] */
/* 0086373d  FUN_0086373d  19 bytes, 0 callers */

void FUN_0086373d(int param_1)

{
  undefined4 in_ECX;
  
  FUN_0079c90d(*(undefined4 *)(param_1 + 8),in_ECX);
  return;
}




/* vtable slots: CMFCRibbonBaseElement[122], CMFCRibbonSeparator[122], CMFCRibbonTab[122] */
/* 00863750  FUN_00863750  30 bytes, 1 callers */

void FUN_00863750(int param_1,int param_2)

{
  int in_ECX;
  
  if (param_1 == *(int *)(in_ECX + 0xa4)) {
    FUN_0079c90d(*(undefined4 *)(param_2 + 8),in_ECX);
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[130], CMFCRibbonBaseElement[131], CMFCRibbonButton[130], CMFCRibbonButton[131], CMFCRibbonCaptionButton[130], CMFCRibbonCaptionButton[131], CMFCRibbonColorButton[130], CMFCRibbonColorButton[131], CMFCRibbonColorMenuButton[130], CMFCRibbonColorMenuButton[131], CMFCRibbonDefaultPanelButton[130], CMFCRibbonDefaultPanelButton[131], CMFCRibbonEdit[130], CMFCRibbonEdit[131], CMFCRibbonGallery[130], CMFCRibbonGallery[131], CMFCRibbonGalleryIcon[130], CMFCRibbonGalleryIcon[131], CMFCRibbonLabel[130], CMFCRibbonLabel[131], CMFCRibbonLaunchButton[130], CMFCRibbonLaunchButton[131], CMFCRibbonQuickAccessCustomizeButton[130], CMFCRibbonQuickAccessCustomizeButton[131], CMFCRibbonSeparator[130], CMFCRibbonSeparator[131], CMFCRibbonTab[130], CMFCRibbonTab[131], CMFCRibbonUndoButton[130], CMFCRibbonUndoButton[131], CRibbonCategoryScroll[130], CRibbonCategoryScroll[131], CRibbonUndoLabel[130], CRibbonUndoLabel[131] */
/* 0086376e  FUN_0086376e  51 bytes, 0 callers */

void FUN_0086376e(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x11c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    IsRectEmpty((RECT *)(in_ECX + 0x1d));
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[115], CMFCRibbonButton[115], CMFCRibbonCaptionButton[115], CMFCRibbonColorButton[115], CMFCRibbonColorMenuButton[115], CMFCRibbonDefaultPanelButton[115], CMFCRibbonEdit[115], CMFCRibbonGallery[115], CMFCRibbonGalleryIcon[115], CMFCRibbonLabel[115], CMFCRibbonLaunchButton[115], CMFCRibbonQuickAccessCustomizeButton[115], CMFCRibbonSeparator[115], CMFCRibbonTab[115], CMFCRibbonUndoButton[115], CRibbonCategoryScroll[115], CRibbonUndoLabel[115] */
/* 008637a1  FUN_008637a1  33 bytes, 0 callers */

uint FUN_008637a1(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xd4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  return -(uint)(iVar2 != 0) & (uint)in_ECX;
}




/* vtable slots: CMFCRibbonBaseElement[114], CMFCRibbonButton[114], CMFCRibbonCaptionButton[114], CMFCRibbonColorMenuButton[114], CMFCRibbonDefaultPanelButton[114], CMFCRibbonEdit[114], CMFCRibbonGalleryIcon[114], CMFCRibbonLabel[114], CMFCRibbonLaunchButton[114], CMFCRibbonQuickAccessCustomizeButton[114], CMFCRibbonSeparator[114], CMFCRibbonTab[114], CRibbonCategoryScroll[114], CRibbonUndoLabel[114] */
/* 008637c2  FUN_008637c2  33 bytes, 1 callers */

uint FUN_008637c2(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xd0);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  return -(uint)(iVar2 != 0) & (uint)in_ECX;
}




/* vtable slots: CMFCRibbonBaseElement[141], CMFCRibbonButton[141], CMFCRibbonCaptionButton[141], CMFCRibbonColorButton[141], CMFCRibbonColorMenuButton[141], CMFCRibbonDefaultPanelButton[141], CMFCRibbonEdit[141], CMFCRibbonGallery[141], CMFCRibbonGalleryIcon[141], CMFCRibbonLabel[141], CMFCRibbonLaunchButton[141], CMFCRibbonQuickAccessCustomizeButton[141], CMFCRibbonSeparator[141], CMFCRibbonTab[141], CMFCRibbonUndoButton[141], CRibbonCategoryScroll[141], CRibbonUndoLabel[141] */
/* 00863836  GetItemIDsList  55 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCRibbonBaseElement::GetItemIDsList(class CList<unsigned
   int,unsigned int> &)const 
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonBaseElement::GetItemIDsList
          (CMFCRibbonBaseElement *this,CList<unsigned_int,unsigned_int> *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0xa4);
  if ((iVar1 != 0) && (iVar1 != -1)) {
    iVar1 = FUN_007e9a96(iVar1,0);
    if (iVar1 == 0) {
      CList<unsigned_int,unsigned_int>::AddTail(param_1,*(uint *)(this + 0xa4));
    }
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[118], CMFCRibbonButtonsGroup[118], CMFCRibbonQuickAccessToolBar[118], CMFCRibbonRecentFilesList[118], CMFCRibbonSeparator[118] */
/* 0086386d  FUN_0086386d  23 bytes, 0 callers */

void FUN_0086386d(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[117], CMFCRibbonButton[117], CMFCRibbonButtonsGroup[117], CMFCRibbonCaptionButton[117], CMFCRibbonColorButton[117], CMFCRibbonColorMenuButton[117], CMFCRibbonDefaultPanelButton[117], CMFCRibbonEdit[117], CMFCRibbonGallery[117], CMFCRibbonGalleryIcon[117], CMFCRibbonLabel[117], CMFCRibbonLaunchButton[117], CMFCRibbonQuickAccessCustomizeButton[117], CMFCRibbonQuickAccessToolBar[117], CMFCRibbonRecentFilesList[117], CMFCRibbonSeparator[117], CMFCRibbonTab[117], CMFCRibbonUndoButton[117], CRibbonCategoryScroll[117], CRibbonUndoLabel[117] */
/* 00863884  GetKeyTipSize  256 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual class CSize __thiscall CMFCRibbonBaseElement::GetKeyTipSize(class CDC *)
   
   Library: Visual Studio 2015 Release */

CDC * __thiscall CMFCRibbonBaseElement::GetKeyTipSize(CMFCRibbonBaseElement *this,CDC *param_1)

{
  short sVar1;
  int iVar2;
  CSimpleStringT<wchar_t,0> *pCVar3;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x863890;
  if (((*(int *)(this + 0xc4) == 0) && (*(int *)(this + 0x94) != 0)) &&
     (*(int *)(*(int *)(this + 100) + -0xc) < 2)) {
    iVar2 = FUN_0044e690(0x26,0);
    if ((-1 < iVar2) && (iVar2 < *(int *)(*(int *)(this + 0x60) + -0xc) + -1)) {
      local_18 = iVar2 + 1;
      sVar1 = FUN_004473c0(local_18);
      if (sVar1 != 0x26) {
        pCVar3 = (CSimpleStringT<wchar_t,0> *)FUN_00450000(&local_20,local_18,1);
        local_8 = 0;
        ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(this + 100),pCVar3);
        local_8 = 0xffffffff;
        FUN_00406b10();
      }
    }
  }
  if (*(int *)(*(int *)(this + 100) + -0xc) == 0) {
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    CStringT<>(&DAT_00970a18);
    FUN_00566800(&local_24,local_14);
    FUN_00566800(&local_1c,this + 100);
    if (local_1c <= local_24) {
      local_1c = local_24;
    }
    iVar2 = local_18;
    if (local_18 <= local_20) {
      iVar2 = local_20;
    }
    *(int *)param_1 = local_1c + 10;
    *(int *)(param_1 + 4) = iVar2 + 2;
    FUN_00406b10();
  }
  return param_1;
}




/* vtable slots: CMFCRibbonBaseElement[76], CMFCRibbonButton[76], CMFCRibbonButtonsGroup[76], CMFCRibbonCaptionButton[76], CMFCRibbonColorButton[76], CMFCRibbonColorMenuButton[76], CMFCRibbonEdit[76], CMFCRibbonGallery[76], CMFCRibbonGalleryIcon[76], CMFCRibbonLabel[76], CMFCRibbonLaunchButton[76], CMFCRibbonQuickAccessCustomizeButton[76], CMFCRibbonQuickAccessToolBar[76], CMFCRibbonRecentFilesList[76], CMFCRibbonSeparator[76], CMFCRibbonTab[76], CMFCRibbonUndoButton[76], CRibbonCategoryScroll[76], CRibbonUndoLabel[76] */
/* 00863984  GetParentPanel  54 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CMFCRibbonPanel * __thiscall
   CMFCRibbonBaseElement::GetParentPanel(void)const 
   
   Library: Visual Studio 2015 Release */

CMFCRibbonPanel * __thiscall CMFCRibbonBaseElement::GetParentPanel(CMFCRibbonBaseElement *this)

{
  int iVar1;
  CMFCRibbonPanel *pCVar2;
  CMFCRibbonCategory *this_00;
  
  iVar1 = *(int *)(this + 0x94);
  if (iVar1 == 0) {
    this_00 = *(CMFCRibbonCategory **)(this + 0x88);
    if (this_00 == (CMFCRibbonCategory *)0x0) {
      return (CMFCRibbonPanel *)0x0;
    }
  }
  else {
    this_00 = *(CMFCRibbonCategory **)(iVar1 + 0xeb4);
    if (this_00 == (CMFCRibbonCategory *)0x0) {
      return *(CMFCRibbonPanel **)(iVar1 + 0xea4);
    }
  }
  pCVar2 = CMFCRibbonCategory::FindPanelWithElem(this_00,this);
  return pCVar2;
}




/* vtable slots: CMFCRibbonBaseElement[41], CMFCRibbonButton[41], CMFCRibbonButtonsGroup[41], CMFCRibbonCaptionButton[41], CMFCRibbonColorButton[41], CMFCRibbonColorMenuButton[41], CMFCRibbonDefaultPanelButton[41], CMFCRibbonEdit[41], CMFCRibbonGallery[41], CMFCRibbonLabel[41], CMFCRibbonLaunchButton[41], CMFCRibbonQuickAccessCustomizeButton[41], CMFCRibbonQuickAccessToolBar[41], CMFCRibbonRecentFilesList[41], CMFCRibbonSeparator[41], CMFCRibbonTab[41], CMFCRibbonUndoButton[41], CRibbonCategoryScroll[41], CRibbonUndoLabel[41] */
/* 008639ba  GetParentWnd  40 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual class CWnd * __thiscall CMFCRibbonBaseElement::GetParentWnd(void)const 
   
   Library: Visual Studio 2015 Release */

CWnd * __thiscall CMFCRibbonBaseElement::GetParentWnd(CMFCRibbonBaseElement *this)

{
  CWnd *pCVar1;
  
  pCVar1 = *(CWnd **)(this + 0x84);
  if ((pCVar1 == (CWnd *)0x0) && (pCVar1 = *(CWnd **)(this + 0x94), pCVar1 == (CWnd *)0x0)) {
    if (*(int *)(this + 0x88) != 0) {
      return *(CWnd **)(*(int *)(this + 0x88) + 0x53c);
    }
    pCVar1 = (CWnd *)0x0;
  }
  return pCVar1;
}




/* vtable slots: CMFCRibbonBaseElement[112], CMFCRibbonButton[112], CMFCRibbonCaptionButton[112], CMFCRibbonColorMenuButton[112], CMFCRibbonDefaultPanelButton[112], CMFCRibbonEdit[112], CMFCRibbonGalleryIcon[112], CMFCRibbonLabel[112], CMFCRibbonLaunchButton[112], CMFCRibbonQuickAccessCustomizeButton[112], CMFCRibbonSeparator[112], CMFCRibbonTab[112], CRibbonCategoryScroll[112], CRibbonUndoLabel[112] */
/* 008639e2  FUN_008639e2  33 bytes, 0 callers */

uint FUN_008639e2(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xd8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  return -(uint)(iVar2 != 0) & (uint)in_ECX;
}




/* vtable slots: CMFCRibbonBaseElement[0] */
/* 00863a1b  FUN_00863a1b  6 bytes, 0 callers */

undefined ** FUN_00863a1b(void)

{
  return &PTR_s_CMFCRibbonBaseElement_00997f04;
}




/* vtable slots: CMFCRibbonBaseElement[61], CMFCRibbonButton[61], CMFCRibbonButtonsGroup[61], CMFCRibbonCaptionButton[61], CMFCRibbonColorButton[61], CMFCRibbonColorMenuButton[61], CMFCRibbonDefaultPanelButton[61], CMFCRibbonEdit[61], CMFCRibbonGallery[61], CMFCRibbonGalleryIcon[61], CMFCRibbonLabel[61], CMFCRibbonLaunchButton[61], CMFCRibbonQuickAccessCustomizeButton[61], CMFCRibbonQuickAccessToolBar[61], CMFCRibbonRecentFilesList[61], CMFCRibbonSeparator[61], CMFCRibbonTab[61], CMFCRibbonUndoButton[61], CRibbonCategoryScroll[61], CRibbonUndoLabel[61] */
/* 00863a27  FUN_00863a27  98 bytes, 0 callers */

void FUN_00863a27(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int *in_ECX;
  code *pcVar4;
  undefined1 local_1c [8];
  undefined1 local_14 [8];
  undefined1 local_c [8];
  
  if (in_ECX[0x2f] == 0) {
    if (in_ECX[0x2e] == 0) {
      pcVar4 = *(code **)(*in_ECX + 0xf8);
      puVar2 = local_1c;
    }
    else {
      pcVar4 = *(code **)(*in_ECX + 0xfc);
      puVar2 = local_14;
    }
  }
  else {
    pcVar4 = *(code **)(*in_ECX + 0x100);
    puVar2 = local_c;
  }
  guard_check_icall(puVar2,param_2);
  puVar3 = (undefined4 *)(*pcVar4)();
  uVar1 = puVar3[1];
  *param_1 = *puVar3;
  param_1[1] = uVar1;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[48], CMFCRibbonButtonsGroup[48], CMFCRibbonQuickAccessToolBar[48], CMFCRibbonRecentFilesList[48], CMFCRibbonSeparator[48] */
/* 00863a89  FUN_00863a89  438 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00863a89(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  int local_18;
  int local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x863a95;
  pcVar1 = *(code **)(*in_ECX + 0xe4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    CStringT<>(&DAT_00956338);
    return param_1;
  }
  iVar2 = FUN_004054a0(in_ECX[0x1b] + -0x10);
  local_14[0] = iVar2 + 0x10;
  local_8 = 0;
  if ((in_ECX[0x31] != 0) && (*(int *)(iVar2 + 4) == 0)) {
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)local_14,(CSimpleStringT<wchar_t,0> *)(in_ECX + 0x18));
    FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
    FUN_007fa476(0x26);
    FUN_005946a0(&DAT_0098dde0,&DAT_0095bc0c);
  }
  iVar6 = local_14[0];
  iVar2 = in_ECX[0x21];
  if (((iVar2 == 0) && (iVar2 = in_ECX[0x25], iVar2 == 0)) && (iVar2 = 0, in_ECX[0x22] != 0)) {
    iVar2 = *(int *)(in_ECX[0x22] + 0x53c);
  }
  if (in_ECX[0x41] == 0) goto LAB_00863c1c;
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = FUN_007e5618(iVar2);
  if ((iVar3 != 0) &&
     ((FUN_007e5618(iVar2), piVar4 = DAT_00a13a1c, DAT_00a13a1c != (int *)0x0 ||
      (piVar4 = (int *)FUN_00792b4c(), piVar4 != (int *)0x0)))) {
    iVar2 = FUN_0082b064(in_ECX[0x29],&local_18,piVar4,1);
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*piVar4 + 0x170);
      guard_check_icall();
      uVar5 = (*pcVar1)();
      iVar2 = FUN_0082b064(in_ECX[0x29],&local_18,uVar5,0);
      if (iVar2 == 0) goto LAB_00863c0d;
    }
    uVar5 = FUN_008f899d(&DAT_0098bc20);
    FUN_00404cf0(&DAT_0098bc20,uVar5);
    FUN_00404cf0(local_18,*(undefined4 *)(local_18 + -0xc));
    ATL::CSimpleStringT<wchar_t,0>::AppendChar((CSimpleStringT<wchar_t,0> *)local_14,L')');
    iVar6 = local_14[0];
  }
LAB_00863c0d:
  local_8 = local_8 & 0xffffff00;
  FUN_00406b10();
LAB_00863c1c:
  iVar2 = FUN_004054a0(iVar6 + -0x10);
  *param_1 = iVar2 + 0x10;
  FUN_00406b10();
  return param_1;
}




/* vtable slots: CMFCRibbonBaseElement[124], CMFCRibbonButton[124], CMFCRibbonCaptionButton[124], CMFCRibbonColorButton[124], CMFCRibbonColorMenuButton[124], CMFCRibbonDefaultPanelButton[124], CMFCRibbonEdit[124], CMFCRibbonGallery[124], CMFCRibbonGalleryIcon[124], CMFCRibbonLabel[124], CMFCRibbonLaunchButton[124], CMFCRibbonQuickAccessCustomizeButton[124], CMFCRibbonSeparator[124], CMFCRibbonTab[124], CMFCRibbonUndoButton[124], CRibbonCategoryScroll[124], CRibbonUndoLabel[124] */
/* 00863cf6  GetVisibleElements  37 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonBaseElement::GetVisibleElements(class CArray<class
   CMFCRibbonBaseElement *,class CMFCRibbonBaseElement *> &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonBaseElement::GetVisibleElements
          (CMFCRibbonBaseElement *this,
          CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*> *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsRectEmpty((RECT *)(this + 0x74));
  if (BVar1 == 0) {
    FUN_0079c90d(*(undefined4 *)(param_1 + 8),this);
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[75], CMFCRibbonButton[75], CMFCRibbonCaptionButton[75], CMFCRibbonColorMenuButton[75], CMFCRibbonDefaultPanelButton[75], CMFCRibbonEdit[75], CMFCRibbonGalleryIcon[75], CMFCRibbonLabel[75], CMFCRibbonLaunchButton[75], CMFCRibbonQuickAccessCustomizeButton[75], CMFCRibbonSeparator[75], CMFCRibbonTab[75], CRibbonCategoryScroll[75], CRibbonUndoLabel[75] */
/* 00863d1b  FUN_00863d1b  5 bytes, 1 callers */

void FUN_00863d1b(void)

{
  return;
}




/* vtable slots: CMFCRibbonBaseElement[58], CMFCRibbonButtonsGroup[58], CMFCRibbonQuickAccessToolBar[58], CMFCRibbonRecentFilesList[58], CMFCRibbonSeparator[58], CMFCRibbonTab[58] */
/* 00863d76  FUN_00863d76  7 bytes, 0 callers */

undefined4 FUN_00863d76(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xf0);
}




/* vtable slots: CMFCRibbonBaseElement[56], CMFCRibbonButton[56], CMFCRibbonButtonsGroup[56], CMFCRibbonCaptionButton[56], CMFCRibbonColorButton[56], CMFCRibbonColorMenuButton[56], CMFCRibbonDefaultPanelButton[56], CMFCRibbonEdit[56], CMFCRibbonGallery[56], CMFCRibbonGalleryIcon[56], CMFCRibbonLabel[56], CMFCRibbonLaunchButton[56], CMFCRibbonQuickAccessCustomizeButton[56], CMFCRibbonQuickAccessToolBar[56], CMFCRibbonRecentFilesList[56], CMFCRibbonSeparator[56], CMFCRibbonTab[56], CMFCRibbonUndoButton[56], CRibbonCategoryScroll[56], CRibbonUndoLabel[56] */
/* 00863d7d  FUN_00863d7d  7 bytes, 0 callers */

undefined4 FUN_00863d7d(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xd8);
}




/* vtable slots: CMFCRibbonBaseElement[55], CMFCRibbonButton[55], CMFCRibbonButtonsGroup[55], CMFCRibbonCaptionButton[55], CMFCRibbonColorButton[55], CMFCRibbonColorMenuButton[55], CMFCRibbonDefaultPanelButton[55], CMFCRibbonEdit[55], CMFCRibbonGallery[55], CMFCRibbonGalleryIcon[55], CMFCRibbonLabel[55], CMFCRibbonLaunchButton[55], CMFCRibbonQuickAccessCustomizeButton[55], CMFCRibbonQuickAccessToolBar[55], CMFCRibbonRecentFilesList[55], CMFCRibbonSeparator[55], CMFCRibbonTab[55], CMFCRibbonUndoButton[55], CRibbonCategoryScroll[55], CRibbonUndoLabel[55] */
/* 00863d84  FUN_00863d84  7 bytes, 0 callers */

undefined4 FUN_00863d84(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xd4);
}




/* vtable slots: CMFCRibbonBaseElement[57], CMFCRibbonButton[57], CMFCRibbonButtonsGroup[57], CMFCRibbonCaptionButton[57], CMFCRibbonColorButton[57], CMFCRibbonColorMenuButton[57], CMFCRibbonDefaultPanelButton[57], CMFCRibbonEdit[57], CMFCRibbonGallery[57], CMFCRibbonGalleryIcon[57], CMFCRibbonLabel[57], CMFCRibbonLaunchButton[57], CMFCRibbonQuickAccessCustomizeButton[57], CMFCRibbonQuickAccessToolBar[57], CMFCRibbonRecentFilesList[57], CMFCRibbonSeparator[57], CMFCRibbonTab[57], CMFCRibbonUndoButton[57], CRibbonCategoryScroll[57], CRibbonUndoLabel[57] */
/* 00863d8b  FUN_00863d8b  7 bytes, 0 callers */

undefined4 FUN_00863d8b(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe0);
}




/* vtable slots: CMFCRibbonBaseElement[53], CMFCRibbonButton[53], CMFCRibbonButtonsGroup[53], CMFCRibbonCaptionButton[53], CMFCRibbonColorButton[53], CMFCRibbonColorMenuButton[53], CMFCRibbonDefaultPanelButton[53], CMFCRibbonEdit[53], CMFCRibbonGallery[53], CMFCRibbonGalleryIcon[53], CMFCRibbonLabel[53], CMFCRibbonLaunchButton[53], CMFCRibbonQuickAccessCustomizeButton[53], CMFCRibbonQuickAccessToolBar[53], CMFCRibbonRecentFilesList[53], CMFCRibbonSeparator[53], CMFCRibbonTab[53], CMFCRibbonUndoButton[53], CRibbonCategoryScroll[53], CRibbonUndoLabel[53] */
/* 00863d92  FUN_00863d92  7 bytes, 3 callers */

undefined4 FUN_00863d92(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xcc);
}




/* vtable slots: CMFCRibbonBaseElement[54], CMFCRibbonButton[54], CMFCRibbonButtonsGroup[54], CMFCRibbonCaptionButton[54], CMFCRibbonColorButton[54], CMFCRibbonColorMenuButton[54], CMFCRibbonDefaultPanelButton[54], CMFCRibbonEdit[54], CMFCRibbonGallery[54], CMFCRibbonGalleryIcon[54], CMFCRibbonLabel[54], CMFCRibbonLaunchButton[54], CMFCRibbonQuickAccessCustomizeButton[54], CMFCRibbonQuickAccessToolBar[54], CMFCRibbonRecentFilesList[54], CMFCRibbonSeparator[54], CMFCRibbonTab[54], CMFCRibbonUndoButton[54], CRibbonCategoryScroll[54], CRibbonUndoLabel[54] */
/* 00863db4  FUN_00863db4  7 bytes, 0 callers */

undefined4 FUN_00863db4(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xd0);
}




/* vtable slots: CMFCRibbonBaseElement[126], CMFCRibbonButton[126], CMFCRibbonButtonsGroup[126], CMFCRibbonColorButton[126], CMFCRibbonColorMenuButton[126], CMFCRibbonDefaultPanelButton[126], CMFCRibbonEdit[126], CMFCRibbonGallery[126], CMFCRibbonGalleryIcon[126], CMFCRibbonLabel[126], CMFCRibbonLaunchButton[126], CMFCRibbonQuickAccessCustomizeButton[126], CMFCRibbonQuickAccessToolBar[126], CMFCRibbonRecentFilesList[126], CMFCRibbonSeparator[126], CMFCRibbonUndoButton[126], CRibbonCategoryScroll[126], CRibbonUndoLabel[126] */
/* 00863dbb  FUN_00863dbb  12 bytes, 0 callers */

bool FUN_00863dbb(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x84) == 0;
}




/* vtable slots: CMFCRibbonBaseElement[128], CMFCRibbonButton[128], CMFCRibbonButtonsGroup[128], CMFCRibbonCaptionButton[128], CMFCRibbonColorMenuButton[128], CMFCRibbonDefaultPanelButton[128], CMFCRibbonEdit[128], CMFCRibbonGallery[128], CMFCRibbonGalleryIcon[128], CMFCRibbonLabel[128], CMFCRibbonLaunchButton[128], CMFCRibbonQuickAccessCustomizeButton[128], CMFCRibbonQuickAccessToolBar[128], CMFCRibbonRecentFilesList[128], CMFCRibbonSeparator[128], CMFCRibbonTab[128], CRibbonCategoryScroll[128], CRibbonUndoLabel[128] */
/* 00863f56  NotifyHighlightListItem  58 bytes, 2 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonBaseElement::NotifyHighlightListItem(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonBaseElement::NotifyHighlightListItem(CMFCRibbonBaseElement *this,int param_1)

{
  CMFCRibbonBar *pCVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  
  pCVar1 = GetTopLevelRibbonBar(this);
  if (pCVar1 != (CMFCRibbonBar *)0x0) {
    pHVar2 = GetParent(*(HWND *)(pCVar1 + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    if (pCVar3 != (CWnd *)0x0) {
      SendMessageW(*(HWND *)(pCVar3 + 0x20),DAT_00a13cac,param_1,(LPARAM)this);
    }
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[87], CMFCRibbonButtonsGroup[87], CMFCRibbonQuickAccessToolBar[87], CMFCRibbonRecentFilesList[87], CMFCRibbonSeparator[87] */
/* 00863f90  FUN_00863f90  8 bytes, 0 callers */

void FUN_00863f90(void)

{
  FUN_00863dc7(1);
  return;
}




/* vtable slots: CMFCRibbonBaseElement[108], CMFCRibbonButton[108], CMFCRibbonButtonsGroup[108], CMFCRibbonCaptionButton[108], CMFCRibbonColorButton[108], CMFCRibbonColorMenuButton[108], CMFCRibbonDefaultPanelButton[108], CMFCRibbonEdit[108], CMFCRibbonGallery[108], CMFCRibbonLabel[108], CMFCRibbonLaunchButton[108], CMFCRibbonQuickAccessCustomizeButton[108], CMFCRibbonQuickAccessToolBar[108], CMFCRibbonRecentFilesList[108], CMFCRibbonSeparator[108], CMFCRibbonTab[108], CMFCRibbonUndoButton[108], CRibbonCategoryScroll[108], CRibbonUndoLabel[108] */
/* 00863f98  FUN_00863f98  19 bytes, 0 callers */

undefined4 FUN_00863f98(void)

{
  undefined4 in_ECX;
  
  FUN_008b19c6(in_ECX);
  return 1;
}




/* vtable slots: CMFCRibbonBaseElement[73], CMFCRibbonLabel[73], CMFCRibbonSeparator[73], CMFCRibbonTab[73] */
/* 00863fab  FUN_00863fab  38 bytes, 1 callers */

void FUN_00863fab(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (*(int *)(in_ECX[0x1b] + -0xc) == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1ac);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[116], CMFCRibbonButton[116], CMFCRibbonButtonsGroup[116], CMFCRibbonCaptionButton[116], CMFCRibbonColorButton[116], CMFCRibbonColorMenuButton[116], CMFCRibbonDefaultPanelButton[116], CMFCRibbonEdit[116], CMFCRibbonGallery[116], CMFCRibbonGalleryIcon[116], CMFCRibbonLabel[116], CMFCRibbonLaunchButton[116], CMFCRibbonQuickAccessCustomizeButton[116], CMFCRibbonQuickAccessToolBar[116], CMFCRibbonRecentFilesList[116], CMFCRibbonSeparator[116], CMFCRibbonTab[116], CMFCRibbonUndoButton[116], CRibbonCategoryScroll[116], CRibbonUndoLabel[116] */
/* 00864179  FUN_00864179  153 bytes, 0 callers */

void FUN_00864179(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  int *piVar6;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 100) + -0xc) != 0) {
    piVar6 = (int *)FUN_007c2574();
    pcVar5 = *(code **)(*piVar6 + 0x2b4);
    piVar6 = (int *)(in_ECX + 0x68);
    if (param_3 == 0) {
      piVar6 = (int *)(in_ECX + 100);
    }
    uVar1 = *param_2;
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    uVar4 = param_2[3];
    FUN_004054a0(*piVar6 + -0x10);
    guard_check_icall(param_1,in_ECX,uVar1,uVar2,uVar3,uVar4);
    (*pcVar5)();
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[86], CMFCRibbonButton[86], CMFCRibbonButtonsGroup[86], CMFCRibbonCaptionButton[86], CMFCRibbonColorButton[86], CMFCRibbonColorMenuButton[86], CMFCRibbonDefaultPanelButton[86], CMFCRibbonEdit[86], CMFCRibbonGallery[86], CMFCRibbonGalleryIcon[86], CMFCRibbonLabel[86], CMFCRibbonLaunchButton[86], CMFCRibbonQuickAccessCustomizeButton[86], CMFCRibbonQuickAccessToolBar[86], CMFCRibbonRecentFilesList[86], CMFCRibbonSeparator[86], CMFCRibbonTab[86], CMFCRibbonUndoButton[86], CRibbonCategoryScroll[86], CRibbonUndoLabel[86] */
/* 00864212  FUN_00864212  55 bytes, 0 callers */

undefined4
FUN_00864212(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x120);
  guard_check_icall(param_1,1,param_2,param_3,param_4,param_5);
  (*pcVar1)();
  return 1;
}




/* vtable slots: CMFCRibbonBaseElement[94], CMFCRibbonButtonsGroup[94], CMFCRibbonQuickAccessToolBar[94], CMFCRibbonRecentFilesList[94], CMFCRibbonTab[94] */
/* 00864249  FUN_00864249  220 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00864249(int *param_1,int param_2,int param_3,int param_4,LONG param_5,LONG param_6,
                 LONG param_7)

{
  undefined4 uVar1;
  code *pcVar2;
  int *piVar3;
  int in_ECX;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  uVar1 = *(undefined4 *)(in_ECX + 0xd4);
  local_8 = 0;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  if (*(int *)(in_ECX + 0xf4) != 0) {
    piVar3 = (int *)FUN_007c2574();
    pcVar2 = *(code **)(*piVar3 + 0x268);
    guard_check_icall(param_1,param_4,param_5,param_4 + param_3,param_7,0,0,0);
    (*pcVar2)();
  }
  local_24.left = param_4 + param_3;
  local_24.top = param_5;
  local_24.right = param_6;
  local_24.bottom = param_7;
  InflateRect(&local_24,-3,0);
  pcVar2 = *(code **)(*param_1 + 0x68);
  guard_check_icall(param_2,*(undefined4 *)(param_2 + -0xc),&local_24,0x824);
  (*pcVar2)();
  *(undefined4 *)(in_ECX + 0xd4) = uVar1;
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonBaseElement[119], CMFCRibbonButtonsGroup[119], CMFCRibbonQuickAccessToolBar[119], CMFCRibbonRecentFilesList[119], CMFCRibbonSeparator[119] */
/* 00864399  FUN_00864399  300 bytes, 2 callers */

undefined4 FUN_00864399(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  CMFCRibbonBar *pCVar4;
  int *piVar5;
  undefined4 uVar6;
  CMFCRibbonBaseElement *in_ECX;
  
  if (*(int *)(in_ECX + 0xd4) == 0) {
    BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x74));
    if (BVar2 == 0) {
      uVar6 = FUN_00863dc7(1);
      return uVar6;
    }
    pcVar1 = *(code **)(*(int *)in_ECX + 0x130);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if ((iVar3 != 0) && (iVar3 = FUN_0086c441(), iVar3 != 0)) {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x138);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        iVar3 = FUN_00863dc7(1);
        if (iVar3 != 0) {
          if (*(int *)(in_ECX + 0x94) != 0) {
            pCVar4 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX);
            piVar5 = (int *)FUN_007e5618(*(undefined4 *)(in_ECX + 0x94));
            pcVar1 = *(code **)(*piVar5 + 0x60);
            guard_check_icall();
            (*pcVar1)();
            if ((pCVar4 != (CMFCRibbonBar *)0x0) && (iVar3 = FUN_00792b4c(), iVar3 != 0)) {
              FUN_00792b4c();
              FUN_00797df8();
            }
          }
          return 1;
        }
      }
      else {
        pCVar4 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX);
        if (pCVar4 != (CMFCRibbonBar *)0x0) {
          CMFCRibbonBar::HideKeyTips(pCVar4);
        }
        iVar3 = FUN_00870e21(0);
        if ((iVar3 != 0) && (piVar5 = (int *)FUN_008b73dc(in_ECX), piVar5 != (int *)0x0)) {
          pcVar1 = *(code **)(*piVar5 + 0x1dc);
          guard_check_icall(param_1);
          uVar6 = (*pcVar1)();
          return uVar6;
        }
      }
    }
  }
  return 0;
}




/* vtable slots: CMFCRibbonBaseElement[132], CMFCRibbonButtonsGroup[132], CMFCRibbonQuickAccessToolBar[132], CMFCRibbonRecentFilesList[132], CMFCRibbonSeparator[132] */
/* 008644c5  FUN_008644c5  174 bytes, 3 callers */

void FUN_008644c5(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  CMFCRibbonBaseElement *pCVar4;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x130);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_0086b14c();
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 0x198);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  if (in_ECX[0x25] == 0) {
    if ((int *)in_ECX[0x21] != (int *)0x0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x21] + 0x334);
      guard_check_icall();
      piVar3 = (int *)(*pcVar1)();
      if (piVar3 != (int *)0x0) {
        pcVar1 = *(code **)(*piVar3 + 0x198);
        guard_check_icall();
        (*pcVar1)();
      }
    }
    if ((CMFCRibbonCategory *)in_ECX[0x22] != (CMFCRibbonCategory *)0x0) {
      pCVar4 = CMFCRibbonCategory::GetDroppedDown((CMFCRibbonCategory *)in_ECX[0x22]);
      if (pCVar4 != (CMFCRibbonBaseElement *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x198);
        guard_check_icall();
        (*pcVar1)();
      }
    }
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[79], CMFCRibbonButtonsGroup[79], CMFCRibbonQuickAccessToolBar[79], CMFCRibbonRecentFilesList[79], CMFCRibbonSeparator[79], CMFCRibbonTab[79] */
/* 00864573  OnShowPopupMenu  70 bytes, 4 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonBaseElement::OnShowPopupMenu(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCRibbonBaseElement::OnShowPopupMenu(CMFCRibbonBaseElement *this)

{
  CMFCRibbonBar *pCVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  
  pCVar1 = GetTopLevelRibbonBar(this);
  if (pCVar1 != (CMFCRibbonBar *)0x0) {
    pHVar2 = GetParent(*(HWND *)(pCVar1 + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    if ((pCVar3 != (CWnd *)0x0) && (*(int *)(this + 0xfc) == 0)) {
      *(undefined4 *)(this + 0xfc) = 1;
      SendMessageW(*(HWND *)(pCVar3 + 0x20),DAT_00a13cb0,0,(LPARAM)this);
    }
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[138], CMFCRibbonButton[138], CMFCRibbonCaptionButton[138], CMFCRibbonColorButton[138], CMFCRibbonColorMenuButton[138], CMFCRibbonDefaultPanelButton[138], CMFCRibbonEdit[138], CMFCRibbonGallery[138], CMFCRibbonGalleryIcon[138], CMFCRibbonLabel[138], CMFCRibbonLaunchButton[138], CMFCRibbonQuickAccessCustomizeButton[138], CMFCRibbonSeparator[138], CMFCRibbonTab[138], CMFCRibbonUndoButton[138], CRibbonCategoryScroll[138], CRibbonUndoLabel[138] */
/* 008645b9  FUN_008645b9  83 bytes, 0 callers */

void FUN_008645b9(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(in_ECX + 0xa4);
    if (((uVar1 != 0) && (0x1ef < uVar1 - 0xf000)) && (uVar1 < 0xff00)) {
      *(int *)(param_1 + 0x28) = in_ECX;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(in_ECX + 0xa4);
      FUN_0078ff63(param_2,param_3);
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCRibbonBaseElement[110], CMFCRibbonButton[110], CMFCRibbonButtonsGroup[110], CMFCRibbonCaptionButton[110], CMFCRibbonColorButton[110], CMFCRibbonColorMenuButton[110], CMFCRibbonDefaultPanelButton[110], CMFCRibbonGallery[110], CMFCRibbonGalleryIcon[110], CMFCRibbonLabel[110], CMFCRibbonLaunchButton[110], CMFCRibbonQuickAccessCustomizeButton[110], CMFCRibbonQuickAccessToolBar[110], CMFCRibbonRecentFilesList[110], CMFCRibbonSeparator[110], CMFCRibbonUndoButton[110], CRibbonCategoryScroll[110], CRibbonUndoLabel[110] */
/* 0086468b  FUN_0086468b  86 bytes, 1 callers */

void FUN_0086468b(void)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int *in_ECX;
  
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x1d));
  if (BVar2 == 0) {
    iVar3 = in_ECX[0x25];
    if ((iVar3 == 0) || (*(int *)(iVar3 + 0x20) == 0)) {
      pcVar1 = *(code **)(*in_ECX + 0xa4);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        return;
      }
      if (*(int *)(iVar3 + 0x20) == 0) {
        return;
      }
    }
    RedrawWindow(*(HWND *)(iVar3 + 0x20),(RECT *)(in_ECX + 0x1d),(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[43], CMFCRibbonButtonsGroup[43], CMFCRibbonRecentFilesList[43], CMFCRibbonSeparator[43] */
/* 0086470d  FUN_0086470d  675 bytes, 4 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0086470d(undefined4 param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  code *pcVar1;
  int *piVar2;
  short sVar3;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *this;
  int iVar4;
  CSimpleStringT<wchar_t,0> *pCVar5;
  int *piVar6;
  int *in_ECX;
  wchar_t *pwVar7;
  int *piVar8;
  CSimpleStringT<wchar_t,0> *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x864719;
  local_14[0] = in_ECX;
  FUN_007ed2e1();
  local_18 = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x18);
  pCVar5 = local_18;
  if (*(int *)(*(int *)local_18 + -0xc) == 0) {
    pCVar5 = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x1b);
  }
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,pCVar5);
  FUN_007fa476(0x26);
  this = ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimRight
                   ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)param_2);
  ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimLeft
            ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)this);
  iVar4 = FUN_00863d99();
  *(uint *)(param_2 + 0x18) = (-(uint)(iVar4 != 0) & 0xffffffe1) + 0x2b;
  ATL::CSimpleStringT<wchar_t,0>::operator=
            (param_2 + 8,(CSimpleStringT<wchar_t,0> *)(in_ECX + 0x1c));
  *(undefined4 *)(param_2 + 0x20) = 1;
  iVar4 = FUN_00863d99();
  pwVar7 = L"Execute";
  if (iVar4 == 0) {
    pwVar7 = L"Press";
  }
  iVar4 = FUN_008f899d(pwVar7);
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 0x14,pwVar7,iVar4);
  *(undefined4 *)(param_2 + 0x1c) = 0x100000;
  pcVar1 = *(code **)(*in_ECX + 0xe0);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if (iVar4 != 0) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x10;
  }
  pcVar1 = *(code **)(*in_ECX + 0xdc);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if (iVar4 != 0) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 1;
  }
  pcVar1 = *(code **)(*in_ECX + 0xd8);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if (iVar4 == 0) {
    iVar4 = FUN_00863d99();
    if (iVar4 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0xd0);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 != 0) goto LAB_00864821;
    }
  }
  else {
LAB_00864821:
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 4;
  }
  *(int *)(param_2 + 0x24) = in_ECX[0x1d];
  *(int *)(param_2 + 0x28) = in_ECX[0x1e];
  *(int *)(param_2 + 0x2c) = in_ECX[0x1f];
  *(int *)(param_2 + 0x30) = in_ECX[0x20];
  FUN_0079e8b8(param_2 + 0x24);
  piVar6 = local_14[0];
  pcVar1 = *(code **)(*local_14[0] + 0x118);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if (iVar4 == 0) {
    iVar4 = FUN_004054a0(local_14[0][0x19] + -0x10);
    piVar8 = (int *)(iVar4 + 0x10);
    local_8 = 0;
    piVar2 = piVar8;
    if ((((local_14[0][0x31] == 0) && (local_14[0][0x25] != 0)) && (*(int *)(iVar4 + 4) < 2)) &&
       ((local_14[0] = piVar8, iVar4 = FUN_0044e690(0x26,0), piVar2 = local_14[0], -1 < iVar4 &&
        (iVar4 < *(int *)(piVar6[0x18] + -0xc) + -1)))) {
      local_18 = (CSimpleStringT<wchar_t,0> *)(iVar4 + 1);
      sVar3 = FUN_004473c0(local_18);
      piVar2 = local_14[0];
      if (sVar3 != 0x26) {
        pCVar5 = (CSimpleStringT<wchar_t,0> *)FUN_00450000(&local_18,local_18,1);
        local_8._0_1_ = 1;
        ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)local_14,pCVar5);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00406b10();
        piVar8 = local_14[0];
        piVar2 = local_14[0];
      }
    }
    local_14[0] = piVar2;
    if (*(int *)((int)piVar8 + -0xc) != 0) {
      iVar4 = FUN_008f899d(L"Alt, ");
      ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 0xc,L"Alt, ",iVar4);
      iVar4 = piVar6[0x22];
      if (iVar4 != 0) {
        piVar6 = (int *)ATL::operator+((CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                        *)&local_18,(wchar_t *)(iVar4 + 0xf4));
        local_8._0_1_ = 2;
        FUN_00404cf0(*piVar6,*(undefined4 *)(*piVar6 + -0xc));
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00406b10();
      }
      FUN_00404cf0(piVar8,*(undefined4 *)((int)piVar8 + -0xc));
    }
    FUN_00406b10();
    return 1;
  }
  pwVar7 = *(wchar_t **)local_18;
  if (*(int *)(pwVar7 + -6) == 0) {
    pwVar7 = L"Separator";
  }
  else if (pwVar7 == (wchar_t *)0x0) {
    iVar4 = 0;
    goto LAB_0086486c;
  }
  iVar4 = FUN_008f899d(pwVar7);
LAB_0086486c:
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_2,pwVar7,iVar4);
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0x15;
  Empty();
  return 1;
}




/* vtable slots: CMFCRibbonBaseElement[59], CMFCRibbonButton[59], CMFCRibbonButtonsGroup[59], CMFCRibbonCaptionButton[59], CMFCRibbonColorButton[59], CMFCRibbonColorMenuButton[59], CMFCRibbonDefaultPanelButton[59], CMFCRibbonEdit[59], CMFCRibbonGallery[59], CMFCRibbonGalleryIcon[59], CMFCRibbonLabel[59], CMFCRibbonLaunchButton[59], CMFCRibbonQuickAccessCustomizeButton[59], CMFCRibbonQuickAccessToolBar[59], CMFCRibbonRecentFilesList[59], CMFCRibbonSeparator[59], CMFCRibbonTab[59], CMFCRibbonUndoButton[59], CRibbonCategoryScroll[59], CRibbonUndoLabel[59] */
/* 008649b0  FUN_008649b0  169 bytes, 0 callers */

void FUN_008649b0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 == 0) {
    if (in_ECX[0x2e] != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x108);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      in_ECX[0x2e] = 0;
      in_ECX[0x2f] = (uint)(iVar2 != 0);
    }
  }
  else if (in_ECX[0x2e] == 0) {
    if (in_ECX[0x2f] == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x108);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        in_ECX[0x2e] = 0;
        in_ECX[0x2f] = 1;
      }
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x10c);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        in_ECX[0x2f] = 0;
        in_ECX[0x2e] = 1;
      }
    }
  }
  return;
}




/* vtable slots: CMFCRibbonBaseElement[51], CMFCRibbonButtonsGroup[51], CMFCRibbonQuickAccessToolBar[51], CMFCRibbonRecentFilesList[51], CMFCRibbonSeparator[51], CMFCRibbonTab[51] */
/* 00864a59  FUN_00864a59  42 bytes, 1 callers */

void FUN_00864a59(wchar_t *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 == (wchar_t *)0x0) {
    param_1 = L"";
  }
  iVar1 = FUN_008f899d(param_1);
  ATL::CSimpleStringT<wchar_t,0>::SetString
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x70),param_1,iVar1);
  return;
}




/* vtable slots: CMFCRibbonBaseElement[44], CMFCRibbonButton[44], CMFCRibbonButtonsGroup[44], CMFCRibbonCaptionButton[44], CMFCRibbonColorButton[44], CMFCRibbonColorMenuButton[44], CMFCRibbonDefaultPanelButton[44], CMFCRibbonEdit[44], CMFCRibbonGallery[44], CMFCRibbonGalleryIcon[44], CMFCRibbonLabel[44], CMFCRibbonLaunchButton[44], CMFCRibbonQuickAccessCustomizeButton[44], CMFCRibbonQuickAccessToolBar[44], CMFCRibbonRecentFilesList[44], CMFCRibbonSeparator[44], CMFCRibbonTab[44], CMFCRibbonUndoButton[44], CRibbonCategoryScroll[44], CRibbonUndoLabel[44] */
/* 00864b29  FUN_00864b29  16 bytes, 1 callers */

void FUN_00864b29(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa4) = param_1;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[68], CMFCRibbonButton[68], CMFCRibbonButtonsGroup[68], CMFCRibbonCaptionButton[68], CMFCRibbonColorMenuButton[68], CMFCRibbonDefaultPanelButton[68], CMFCRibbonEdit[68], CMFCRibbonGalleryIcon[68], CMFCRibbonLabel[68], CMFCRibbonLaunchButton[68], CMFCRibbonQuickAccessCustomizeButton[68], CMFCRibbonQuickAccessToolBar[68], CMFCRibbonRecentFilesList[68], CMFCRibbonSeparator[68], CMFCRibbonTab[68], CRibbonCategoryScroll[68], CRibbonUndoLabel[68] */
/* 00864b39  FUN_00864b39  168 bytes, 1 callers */

void FUN_00864b39(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  in_ECX[0x2f] = 0;
  in_ECX[0x2e] = 0;
  if ((in_ECX[0x24] == 0) && (param_1 == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x104);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      return;
    }
    pcVar1 = *(code **)(*in_ECX + 0x108);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      in_ECX[0x2f] = 0;
      return;
    }
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x10c);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      in_ECX[0x2e] = 1;
      return;
    }
    pcVar1 = *(code **)(*in_ECX + 0x108);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      return;
    }
  }
  in_ECX[0x2f] = 1;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[46], CMFCRibbonButton[46], CMFCRibbonButtonsGroup[46], CMFCRibbonCaptionButton[46], CMFCRibbonColorButton[46], CMFCRibbonColorMenuButton[46], CMFCRibbonDefaultPanelButton[46], CMFCRibbonEdit[46], CMFCRibbonGallery[46], CMFCRibbonGalleryIcon[46], CMFCRibbonLabel[46], CMFCRibbonLaunchButton[46], CMFCRibbonQuickAccessCustomizeButton[46], CMFCRibbonQuickAccessToolBar[46], CMFCRibbonRecentFilesList[46], CMFCRibbonSeparator[46], CMFCRibbonTab[46], CMFCRibbonUndoButton[46], CRibbonCategoryScroll[46], CRibbonUndoLabel[46] */
/* 00864be1  FUN_00864be1  86 bytes, 0 callers */

void FUN_00864be1(wchar_t *param_1,wchar_t *param_2)

{
  int iVar1;
  int in_ECX;
  wchar_t *pwVar2;
  
  if (param_1 == (wchar_t *)0x0) {
    param_1 = L"";
  }
  iVar1 = FUN_008f899d(param_1);
  ATL::CSimpleStringT<wchar_t,0>::SetString
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 100),param_1,iVar1);
  pwVar2 = L"";
  if (param_2 != (wchar_t *)0x0) {
    pwVar2 = param_2;
  }
  iVar1 = FUN_008f899d(pwVar2);
  ATL::CSimpleStringT<wchar_t,0>::SetString
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x68),pwVar2,iVar1);
  return;
}




/* vtable slots: CMFCRibbonBaseElement[92], CMFCRibbonSeparator[92], CMFCRibbonTab[92] */
/* 00864c37  SetOriginal  34 bytes, 2 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonBaseElement::SetOriginal(class CMFCRibbonBaseElement
   *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonBaseElement::SetOriginal(CMFCRibbonBaseElement *this,CMFCRibbonBaseElement *param_1)

{
  CMFCRibbonBaseElement *pCVar1;
  CMFCRibbonBaseElement *pCVar2;
  
  pCVar2 = param_1;
  while (pCVar1 = param_1, pCVar1 != (CMFCRibbonBaseElement *)0x0) {
    pCVar2 = pCVar1;
    param_1 = *(CMFCRibbonBaseElement **)(pCVar1 + 0x8c);
  }
  *(CMFCRibbonBaseElement **)(this + 0x8c) = pCVar2;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[91], CMFCRibbonButton[91], CMFCRibbonCaptionButton[91], CMFCRibbonColorButton[91], CMFCRibbonColorMenuButton[91], CMFCRibbonDefaultPanelButton[91], CMFCRibbonEdit[91], CMFCRibbonGallery[91], CMFCRibbonGalleryIcon[91], CMFCRibbonLabel[91], CMFCRibbonLaunchButton[91], CMFCRibbonQuickAccessCustomizeButton[91], CMFCRibbonSeparator[91], CMFCRibbonTab[91], CMFCRibbonUndoButton[91], CRibbonCategoryScroll[91], CRibbonUndoLabel[91] */
/* 00864c59  FUN_00864c59  16 bytes, 1 callers */

void FUN_00864c59(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x94) = param_1;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[77], CMFCRibbonSeparator[77], CMFCRibbonTab[77] */
/* 00864c69  FUN_00864c69  16 bytes, 0 callers */

void FUN_00864c69(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x84) = param_1;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[45], CMFCRibbonButtonsGroup[45], CMFCRibbonQuickAccessToolBar[45], CMFCRibbonRecentFilesList[45], CMFCRibbonSeparator[45], CMFCRibbonTab[45] */
/* 00864c79  FUN_00864c79  197 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00864c79(wchar_t *param_1)

{
  CSimpleStringT<wchar_t,0> *this;
  int iVar1;
  CSimpleStringT<wchar_t,0> *pCVar2;
  int in_ECX;
  int local_18;
  CSimpleStringT<wchar_t,0> *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x864c85;
  this = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x60);
  if (param_1 == (wchar_t *)0x0) {
    param_1 = L"";
  }
  local_18 = in_ECX;
  local_14[0] = this;
  iVar1 = FUN_008f899d(param_1);
  ATL::CSimpleStringT<wchar_t,0>::SetString(local_14[0],param_1,iVar1);
  iVar1 = FUN_0044e690(10,0);
  if (-1 < iVar1) {
    FUN_00450000(local_14,iVar1 + 1,*(int *)(*(int *)this + -0xc) - (iVar1 + 1));
    local_8 = 0;
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(local_18 + 100),(CSimpleStringT<wchar_t,0> *)local_14);
    local_8 = 0xffffffff;
    FUN_00406b10();
    pCVar2 = (CSimpleStringT<wchar_t,0> *)Left(&local_18,iVar1);
    local_8 = 1;
    ATL::CSimpleStringT<wchar_t,0>::operator=(this,pCVar2);
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimLeft
            ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)this);
  ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimRight
            ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)this);
  return;
}




/* vtable slots: CMFCRibbonBaseElement[47], CMFCRibbonButton[47], CMFCRibbonButtonsGroup[47], CMFCRibbonCaptionButton[47], CMFCRibbonColorButton[47], CMFCRibbonColorMenuButton[47], CMFCRibbonDefaultPanelButton[47], CMFCRibbonEdit[47], CMFCRibbonGallery[47], CMFCRibbonGalleryIcon[47], CMFCRibbonLabel[47], CMFCRibbonLaunchButton[47], CMFCRibbonQuickAccessCustomizeButton[47], CMFCRibbonQuickAccessToolBar[47], CMFCRibbonRecentFilesList[47], CMFCRibbonSeparator[47], CMFCRibbonTab[47], CMFCRibbonUndoButton[47], CRibbonCategoryScroll[47], CRibbonUndoLabel[47] */
/* 00864d3e  FUN_00864d3e  16 bytes, 0 callers */

void FUN_00864d3e(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb0) = param_1;
  return;
}




/* vtable slots: CMFCRibbonBaseElement[50], CMFCRibbonButton[50], CMFCRibbonButtonsGroup[50], CMFCRibbonCaptionButton[50], CMFCRibbonColorButton[50], CMFCRibbonColorMenuButton[50], CMFCRibbonDefaultPanelButton[50], CMFCRibbonEdit[50], CMFCRibbonGallery[50], CMFCRibbonGalleryIcon[50], CMFCRibbonLabel[50], CMFCRibbonLaunchButton[50], CMFCRibbonQuickAccessCustomizeButton[50], CMFCRibbonQuickAccessToolBar[50], CMFCRibbonRecentFilesList[50], CMFCRibbonSeparator[50], CMFCRibbonTab[50], CMFCRibbonUndoButton[50], CRibbonCategoryScroll[50], CRibbonUndoLabel[50] */
/* 00864d4e  FUN_00864d4e  42 bytes, 0 callers */

void FUN_00864d4e(wchar_t *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 == (wchar_t *)0x0) {
    param_1 = L"";
  }
  iVar1 = FUN_008f899d(param_1);
  ATL::CSimpleStringT<wchar_t,0>::SetString
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x6c),param_1,iVar1);
  return;
}




/* vtable slots: CMFCRibbonBaseElement[85], CMFCRibbonButton[85], CMFCRibbonButtonsGroup[85], CMFCRibbonCaptionButton[85], CMFCRibbonColorButton[85], CMFCRibbonColorMenuButton[85], CMFCRibbonDefaultPanelButton[85], CMFCRibbonEdit[85], CMFCRibbonGallery[85], CMFCRibbonGalleryIcon[85], CMFCRibbonLabel[85], CMFCRibbonLaunchButton[85], CMFCRibbonQuickAccessCustomizeButton[85], CMFCRibbonQuickAccessToolBar[85], CMFCRibbonRecentFilesList[85], CMFCRibbonSeparator[85], CMFCRibbonTab[85], CMFCRibbonUndoButton[85], CRibbonCategoryScroll[85], CRibbonUndoLabel[85] */
/* 00864d78  FUN_00864d78  74 bytes, 0 callers */

undefined4 FUN_00864d78(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (((iVar2 == 0) || (in_ECX[0x2e] != 0)) || (in_ECX[0x2f] != 0)) {
    uVar3 = 0;
  }
  else {
    in_ECX[0x20] = in_ECX[0x1e] + param_2;
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonBaseElement[107], CMFCRibbonButton[107], CMFCRibbonButtonsGroup[107], CMFCRibbonCaptionButton[107], CMFCRibbonColorButton[107], CMFCRibbonColorMenuButton[107], CMFCRibbonDefaultPanelButton[107], CMFCRibbonEdit[107], CMFCRibbonGallery[107], CMFCRibbonGalleryIcon[107], CMFCRibbonLabel[107], CMFCRibbonLaunchButton[107], CMFCRibbonQuickAccessCustomizeButton[107], CMFCRibbonQuickAccessToolBar[107], CMFCRibbonRecentFilesList[107], CMFCRibbonSeparator[107], CMFCRibbonTab[107], CMFCRibbonUndoButton[107], CRibbonCategoryScroll[107], CRibbonUndoLabel[107] */
/* 00864dc2  FUN_00864dc2  185 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_00864dc2(void)

{
  undefined1 *puVar1;
  int iVar2;
  int in_ECX;
  UINT in_stack_ffffffdc;
  LPSTR in_stack_ffffffe0;
  int in_stack_ffffffe4;
  wchar_t *local_14;
  
  puVar1 = &LAB_0092da1d;
  if (((*(int *)(in_ECX + 0x100) != 0) &&
      (puVar1 = *(undefined1 **)(in_ECX + 0xa4), puVar1 != (undefined1 *)0x0)) &&
     (puVar1 != (undefined1 *)0xffffffff)) {
    CStringT<>();
    iVar2 = FID_conflict_LoadStringA
                      (*(HINSTANCE *)(in_ECX + 0xa4),in_stack_ffffffdc,in_stack_ffffffe0,
                       in_stack_ffffffe4);
    if (iVar2 != 0) {
      Empty();
      Empty();
      if (*(int *)(local_14 + -6) != 0) {
        AfxExtractSubString((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                            (in_ECX + 0x70),local_14,0,L'\n');
        AfxExtractSubString((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                            (in_ECX + 0x6c),local_14,1,L'\n');
        FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
        FUN_007fa476(0x26);
        FUN_005946a0(&DAT_0098dde0,&DAT_0095bc0c);
      }
    }
    puVar1 = (undefined1 *)FUN_00406b10();
  }
  return puVar1;
}




/* vtable slots: CMFCRibbonBaseElement[38], CMFCRibbonButton[38], CMFCRibbonButtonsGroup[38], CMFCRibbonCaptionButton[38], CMFCRibbonColorButton[38], CMFCRibbonColorMenuButton[38], CMFCRibbonDefaultPanelButton[38], CMFCRibbonEdit[38], CMFCRibbonGallery[38], CMFCRibbonGalleryIcon[38], CMFCRibbonLabel[38], CMFCRibbonLaunchButton[38], CMFCRibbonQuickAccessCustomizeButton[38], CMFCRibbonRecentFilesList[38], CMFCRibbonSeparator[38], CMFCRibbonTab[38], CMFCRibbonUndoButton[38], CRibbonCategoryScroll[38], CRibbonUndoLabel[38] */
/* 00864e81  FUN_00864e81  31 bytes, 0 callers */

undefined4 FUN_00864e81(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x15c);
  guard_check_icall();
  (*pcVar1)();
  return 0;
}




/* vtable slots: CMFCRibbonBaseElement[37], CMFCRibbonButton[37], CMFCRibbonButtonsGroup[37], CMFCRibbonCaptionButton[37], CMFCRibbonColorButton[37], CMFCRibbonColorMenuButton[37], CMFCRibbonDefaultPanelButton[37], CMFCRibbonEdit[37], CMFCRibbonGallery[37], CMFCRibbonGalleryIcon[37], CMFCRibbonLabel[37], CMFCRibbonLaunchButton[37], CMFCRibbonQuickAccessCustomizeButton[37], CMFCRibbonRecentFilesList[37], CMFCRibbonSeparator[37], CMFCRibbonUndoButton[37], CRibbonCategoryScroll[37], CRibbonUndoLabel[37] */
/* 00864ef6  FUN_00864ef6  84 bytes, 0 callers */

undefined4 FUN_00864ef6(LONG param_1,LONG param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int in_ECX;
  tagPOINT local_c;
  
  if (param_3 == (undefined2 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    if ((*(int *)(in_ECX + 0x84) != 0) && (*(int *)(*(int *)(in_ECX + 0x84) + 0x20) != 0)) {
      *(undefined4 *)(param_3 + 4) = 0;
      *param_3 = 3;
      local_c.x = param_1;
      local_c.y = param_2;
      ScreenToClient(*(HWND *)(*(int *)(in_ECX + 0x84) + 0x20),&local_c);
    }
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonBaseElement[35], CMFCRibbonButton[35], CMFCRibbonButtonsGroup[35], CMFCRibbonCaptionButton[35], CMFCRibbonColorButton[35], CMFCRibbonColorMenuButton[35], CMFCRibbonDefaultPanelButton[35], CMFCRibbonEdit[35], CMFCRibbonGallery[35], CMFCRibbonGalleryIcon[35], CMFCRibbonLabel[35], CMFCRibbonLaunchButton[35], CMFCRibbonQuickAccessCustomizeButton[35], CMFCRibbonRecentFilesList[35], CMFCRibbonSeparator[35], CMFCRibbonUndoButton[35], CRibbonCategoryScroll[35], CRibbonUndoLabel[35] */
/* 00864f95  FUN_00864f95  279 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00864f95(int *param_1,int *param_2,int *param_3,int *param_4,short param_5,undefined4 param_6,
            int param_7)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
     (param_4 == (int *)0x0)) {
    return 0x80070057;
  }
  if (param_5 == 3) {
    if (param_7 == 0) {
      local_18 = in_ECX[0x1d];
      local_14 = in_ECX[0x1e];
      local_10 = in_ECX[0x1f];
      local_c = in_ECX[0x20];
      if ((in_ECX[0x21] == 0) || (*(int *)(in_ECX[0x21] + 0x20) == 0)) {
        pcVar1 = *(code **)(*in_ECX + 0xa4);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if ((iVar2 == 0) || (*(int *)(iVar2 + 0x20) == 0)) goto LAB_0086505a;
      }
      FUN_0079e8b8(&local_18);
      *param_1 = local_18;
      *param_2 = local_14;
      *param_3 = local_10 - local_18;
      local_c = local_c - local_14;
    }
    else {
      if (param_7 < 1) goto LAB_0086505a;
      pcVar1 = *(code **)(*in_ECX + 0xa8);
      guard_check_icall(param_7);
      (*pcVar1)();
      *param_1 = in_ECX[0x11];
      *param_2 = in_ECX[0x12];
      *param_3 = in_ECX[0x13] - in_ECX[0x11];
      local_c = in_ECX[0x14] - in_ECX[0x12];
    }
    *param_4 = local_c;
    uVar3 = 0;
  }
  else {
LAB_0086505a:
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonBaseElement[36], CMFCRibbonButton[36], CMFCRibbonButtonsGroup[36], CMFCRibbonCaptionButton[36], CMFCRibbonColorButton[36], CMFCRibbonColorMenuButton[36], CMFCRibbonDefaultPanelButton[36], CMFCRibbonEdit[36], CMFCRibbonGallery[36], CMFCRibbonGalleryIcon[36], CMFCRibbonLabel[36], CMFCRibbonLaunchButton[36], CMFCRibbonQuickAccessCustomizeButton[36], CMFCRibbonRecentFilesList[36], CMFCRibbonSeparator[36], CMFCRibbonUndoButton[36], CRibbonCategoryScroll[36], CRibbonUndoLabel[36] */
/* 00865108  FUN_00865108  191 bytes, 0 callers */

undefined4
FUN_00865108(int param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined2 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  IDispatch *pIVar3;
  int iVar4;
  int in_ECX;
  CCmdTarget *this;
  
  if (*(int *)(in_ECX + 0x108) == 0) {
    return 1;
  }
  *param_6 = 0;
  if (param_2 != 3) {
    return 0x80070057;
  }
  iVar1 = *(int *)(in_ECX + 0x90);
  if (iVar1 == 0) {
    return 1;
  }
  if (param_1 == 3) {
LAB_008651a6:
    if (param_4 != 0) {
      return 1;
    }
    iVar4 = FUN_008c4d7f(in_ECX);
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      this = (CCmdTarget *)(*(int *)(in_ECX + 0x84) + 0x1250);
      goto LAB_00865182;
    }
  }
  else {
    if ((param_1 != 4) && (param_1 != 5)) {
      if (param_1 != 6) {
        return 1;
      }
      goto LAB_008651a6;
    }
    if (param_4 != 0) {
      return 1;
    }
    iVar4 = FUN_008c4d7f(in_ECX);
    iVar4 = iVar4 + 1;
    if (*(int *)(iVar1 + 0x114) <= iVar4) {
      this = *(CCmdTarget **)(*(int *)(in_ECX + 0x84) + 0x7a8);
      goto LAB_00865182;
    }
  }
  puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
  this = (CCmdTarget *)*puVar2;
LAB_00865182:
  if (this == (CCmdTarget *)0x0) {
    return 1;
  }
  *param_6 = 9;
  pIVar3 = CCmdTarget::GetIDispatch(this,1);
  *(IDispatch **)(param_6 + 4) = pIVar3;
  return 0;
}




/* vtable slots: CMFCRibbonBaseElement[20], CMFCRibbonButton[20], CMFCRibbonButtonsGroup[20], CMFCRibbonCaptionButton[20], CMFCRibbonColorButton[20], CMFCRibbonColorMenuButton[20], CMFCRibbonDefaultPanelButton[20], CMFCRibbonEdit[20], CMFCRibbonGallery[20], CMFCRibbonGalleryIcon[20], CMFCRibbonLabel[20], CMFCRibbonLaunchButton[20], CMFCRibbonQuickAccessCustomizeButton[20], CMFCRibbonRecentFilesList[20], CMFCRibbonSeparator[20], CMFCRibbonUndoButton[20], CRibbonCategoryScroll[20], CRibbonUndoLabel[20] */
/* 008657f2  get_accParent  69 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCRibbonBaseElement::get_accParent(struct IDispatch * *)
   
   Library: Visual Studio 2015 Release */

long __thiscall
CMFCRibbonBaseElement::get_accParent(CMFCRibbonBaseElement *this,IDispatch **param_1)

{
  long lVar1;
  IDispatch *pIVar2;
  
  if (param_1 == (IDispatch **)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    *param_1 = (IDispatch *)0x0;
    if (((*(int *)(this + 0x108) == 0) || (*(int *)(this + 0x84) == 0)) ||
       (*(int *)(*(int *)(this + 0x84) + 0x20) == 0)) {
      lVar1 = 1;
    }
    else {
      pIVar2 = (IDispatch *)FUN_008b33a1();
      if (pIVar2 != (IDispatch *)0x0) {
        *param_1 = pIVar2;
      }
      lVar1 = 0;
    }
  }
  return lVar1;
}



