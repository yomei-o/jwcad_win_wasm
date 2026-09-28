/* CMFCVisualManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCVisualManager[188], CMFCVisualManagerOffice2003[188], CMFCVisualManagerOffice2007[188], CMFCVisualManagerOfficeXP[188] */
/* 0079272b  FUN_0079272b  4 bytes, 1 callers */

undefined4 FUN_0079272b(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x70);
}




/* vtable slots: CMFCVisualManager[1] */
/* 007f2768  FUN_007f2768  51 bytes, 0 callers */

void FUN_007f2768(byte param_1)

{
  FUN_007f2659();
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




/* vtable slots: CMFCVisualManager[114], CMFCVisualManager[115], CMFCVisualManagerOfficeXP[114], CMFCVisualManagerOfficeXP[115] */
/* 007f2c11  FUN_007f2c11  5 bytes, 0 callers */

undefined4 FUN_007f2c11(void)

{
  return 0;
}




/* vtable slots: CMFCVisualManager[113], CMFCVisualManagerOfficeXP[113] */
/* 007f2d4b  FUN_007f2d4b  5 bytes, 0 callers */

undefined4 FUN_007f2d4b(void)

{
  return 0;
}




/* vtable slots: CMFCVisualManager[179], CMFCVisualManagerOffice2003[179], CMFCVisualManagerOffice2007[179], CMFCVisualManagerOfficeXP[179] */
/* 007f2f30  FUN_007f2f30  170 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007f2f30(int *param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  
  GetTextColor((HDC)param_1[2]);
  pcVar1 = *(code **)(*param_1 + 0x30);
  guard_check_icall();
  (*pcVar1)();
  FUN_007c2511();
  uVar2 = *(undefined4 *)(in_ECX + 0x10);
  FUN_004054a0(param_2 + -0x10);
  uVar2 = FUN_007e59dc(uVar2,param_1,0,0);
  pcVar1 = *(code **)(*param_1 + 0x30);
  guard_check_icall();
  (*pcVar1)();
  FUN_00406b10();
  return uVar2;
}




/* vtable slots: CMFCVisualManager[110], CMFCVisualManager[176], CMFCVisualManagerOffice2003[176], CMFCVisualManagerOfficeXP[176] */
/* 007f3155  FUN_007f3155  11 bytes, 1 callers */

undefined4 FUN_007f3155(void)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  return *(undefined4 *)(iVar1 + 0x68);
}




/* vtable slots: CMFCVisualManager[80], CMFCVisualManager[81], CMFCVisualManagerOffice2003[80], CMFCVisualManagerOffice2003[81], CMFCVisualManagerOffice2007[80], CMFCVisualManagerOffice2007[81], CMFCVisualManagerOfficeXP[80], CMFCVisualManagerOfficeXP[81] */
/* 007f3160  FUN_007f3160  17 bytes, 0 callers */

void FUN_007f3160(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}




/* vtable slots: CMFCVisualManager[51], CMFCVisualManagerOffice2003[51], CMFCVisualManagerOfficeXP[51] */
/* 007f3171  GetCaptionBarTextColor  37 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::GetCaptionBarTextColor(class
   CMFCCaptionBar *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::GetCaptionBarTextColor(CMFCVisualManager *this,CMFCCaptionBar *param_1)

{
  ulong uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x2c4) == 0) {
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x6c);
  }
  else {
    uVar1 = GetSysColor(0x17);
  }
  return uVar1;
}




/* vtable slots: CMFCVisualManager[37] */
/* 007f3196  FUN_007f3196  37 bytes, 0 callers */

undefined4 FUN_007f3196(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(uint *)(param_1 + 0x24) & 0x40000) == 0) {
    iVar1 = FUN_007c2511();
    uVar2 = *(undefined4 *)(iVar1 + 0x40);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(undefined4 *)(iVar1 + 0x38);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManager[185], CMFCVisualManagerOffice2003[185], CMFCVisualManagerOffice2007[185], CMFCVisualManagerOfficeXP[185] */
/* 007f31bb  GetMenuImageFrameOffset  29 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CRect __thiscall CMFCVisualManager::GetMenuImageFrameOffset(void)const 
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::GetMenuImageFrameOffset(CMFCVisualManager *this)

{
  undefined4 *in_stack_00000004;
  
  in_stack_00000004[2] = 0;
  *in_stack_00000004 = 2;
  in_stack_00000004[1] = 1;
  in_stack_00000004[3] = 2;
  return;
}




/* vtable slots: CMFCVisualManager[39], CMFCVisualManagerOffice2003[39], CMFCVisualManagerOfficeXP[39] */
/* 007f31dc  GetMenuItemTextColor  48 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::GetMenuItemTextColor(class
   CMFCToolBarMenuButton *,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::GetMenuItemTextColor
          (CMFCVisualManager *this,CMFCToolBarMenuButton *param_1,int param_2,int param_3)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = FUN_007c2511();
  if (param_2 == 0) {
    if (param_3 == 0) {
      uVar2 = *(ulong *)(iVar1 + 0x70);
    }
    else {
      uVar2 = *(ulong *)(iVar1 + 0x38);
    }
  }
  else if (param_3 == 0) {
    uVar2 = *(ulong *)(iVar1 + 0x40);
  }
  else {
    uVar2 = *(ulong *)(iVar1 + 0x1c);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManager[99] */
/* 007f3213  GetPropertyGridGroupColor  37 bytes, 2 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::GetPropertyGridGroupColor(class
   CMFCPropertyGridCtrl *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::GetPropertyGridGroupColor(CMFCVisualManager *this,CMFCPropertyGridCtrl *param_1)

{
  int iVar1;
  ulong uVar2;
  
  if (*(int *)(param_1 + 0x394) == 0) {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x1c);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x54);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManager[100] */
/* 007f3238  GetPropertyGridGroupTextColor  37 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::GetPropertyGridGroupTextColor(class
   CMFCPropertyGridCtrl *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::GetPropertyGridGroupTextColor
          (CMFCVisualManager *this,CMFCPropertyGridCtrl *param_1)

{
  int iVar1;
  ulong uVar2;
  
  if (*(int *)(param_1 + 0x394) == 0) {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x30);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x60);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManager[177], CMFCVisualManagerOffice2003[177], CMFCVisualManagerOfficeXP[177] */
/* 007f325d  GetRibbonEditBackgroundColor  37 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::GetRibbonEditBackgroundColor(class
   CMFCRibbonRichEditCtrl *,int,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::GetRibbonEditBackgroundColor
          (CMFCVisualManager *this,CMFCRibbonRichEditCtrl *param_1,int param_2,int param_3,
          int param_4)

{
  int iVar1;
  ulong uVar2;
  
  if ((param_2 == 0) || (param_4 != 0)) {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x54);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x6c);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManager[175], CMFCVisualManagerOffice2003[175], CMFCVisualManagerOfficeXP[175] */
/* 007f3282  FUN_007f3282  106 bytes, 1 callers */

undefined4 FUN_007f3282(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*param_1 + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_1 + 0xd0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      iVar2 = FUN_007c2511();
      uVar3 = *(undefined4 *)(iVar2 + 0x44);
    }
    else {
      iVar2 = FUN_007c2511();
      uVar3 = *(undefined4 *)(iVar2 + 0x48);
    }
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0xc4);
    guard_check_icall();
    uVar3 = (*pcVar1)();
  }
  return uVar3;
}




/* vtable slots: CMFCVisualManager[170], CMFCVisualManagerOffice2003[170], CMFCVisualManagerOfficeXP[170] */
/* 007f32ec  FUN_007f32ec  9 bytes, 0 callers */

undefined4 FUN_007f32ec(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa4);
}




/* vtable slots: CMFCVisualManager[151], CMFCVisualManagerOffice2003[151], CMFCVisualManagerOfficeXP[151] */
/* 007f32f5  FUN_007f32f5  44 bytes, 0 callers */

undefined4 FUN_007f32f5(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0xc4);
    guard_check_icall();
    uVar2 = (*pcVar1)();
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManager[164] */
/* 007f3321  FUN_007f3321  66 bytes, 0 callers */

void FUN_007f3321(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
                 undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_007c2511();
  if (param_4 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x60);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x58);
  }
  *param_5 = uVar2;
  iVar1 = FUN_007c2511();
  if (param_2 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x54);
  }
  else if (param_3 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x5c);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x58);
  }
  *param_6 = uVar2;
  return;
}




/* vtable slots: CMFCVisualManager[0] */
/* 007f3363  FUN_007f3363  6 bytes, 0 callers */

undefined ** FUN_007f3363(void)

{
  return &PTR_s_CMFCVisualManager_0098b238;
}




/* vtable slots: CMFCVisualManager[190], CMFCVisualManagerOfficeXP[190] */
/* 007f3369  GetShowAllMenuItemsHeight  24 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManager::GetShowAllMenuItemsHeight(class CDC *,class
   CSize const &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

int __thiscall
CMFCVisualManager::GetShowAllMenuItemsHeight(CMFCVisualManager *this,CDC *param_1,CSize *param_2)

{
  int iVar1;
  CMFCVisualManager *local_c;
  CMFCVisualManager *pCStack_8;
  
  local_c = this;
  pCStack_8 = this;
  iVar1 = FUN_0081507c(&local_c);
  return *(int *)(iVar1 + 4) + 6;
}




/* vtable slots: CMFCVisualManager[116] */
/* 007f3381  FUN_007f3381  33 bytes, 0 callers */

void FUN_007f3381(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  *param_1 = *(undefined4 *)(iVar1 + 0x54);
  iVar1 = FUN_007c2511();
  *param_2 = *(undefined4 *)(iVar1 + 0x58);
  return;
}




/* vtable slots: CMFCVisualManager[117], CMFCVisualManagerOfficeXP[117] */
/* 007f33a2  FUN_007f33a2  9 bytes, 1 callers */

undefined4 FUN_007f33a2(void)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  return *(undefined4 *)(iVar1 + 0x7c);
}




/* vtable slots: CMFCVisualManager[24], CMFCVisualManagerOffice2003[24], CMFCVisualManagerOfficeXP[24] */
/* 007f3595  FUN_007f3595  54 bytes, 1 callers */

int FUN_007f3595(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    if ((*(uint *)(param_2 + 0x14) & 0x4000000) == 0) {
      iVar1 = *(int *)(param_2 + 0x24);
      if (iVar1 == -1) {
        iVar1 = FUN_007c2511();
        iVar1 = *(int *)(iVar1 + 0x28);
      }
    }
    else {
      iVar1 = FUN_007c2511();
      iVar1 = *(int *)(iVar1 + 0x38);
    }
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManager[67], CMFCVisualManagerOfficeXP[67] */
/* 007f35cc  FUN_007f35cc  369 bytes, 1 callers */

void FUN_007f35cc(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 int *param_5,undefined4 *param_6,undefined4 *param_7,int *param_8,int *param_9)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  pcVar1 = *(code **)(iVar3 + 0x20c);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(iVar3 + 0x1dc);
  guard_check_icall(uVar2);
  iVar3 = (*pcVar1)();
  pcVar1 = *(code **)(*param_1 + 0x288);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if ((iVar4 == 0) || (iVar3 == -1)) {
    if (param_1[0x4d] == 0) {
      iVar3 = FUN_007c2511();
      iVar3 = *(int *)(iVar3 + 0x54);
    }
    else {
      iVar3 = FUN_007c2511();
      iVar3 = *(int *)(iVar3 + 0x1c);
    }
  }
  *param_5 = iVar3;
  if (param_1[0x4d] == 0) {
    iVar3 = FUN_007c2511();
    *param_2 = *(undefined4 *)(iVar3 + 0x58);
    iVar3 = FUN_007c2511();
    *param_3 = *(undefined4 *)(iVar3 + 0x68);
    pcVar1 = *(code **)(*param_1 + 0x28c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      iVar3 = FUN_007c2511();
      uVar2 = *(undefined4 *)(iVar3 + 0x5c);
    }
    else {
      iVar3 = FUN_007c2511();
      uVar2 = *(undefined4 *)(iVar3 + 0x58);
    }
    *param_4 = uVar2;
    iVar3 = FUN_007c2511();
    *param_6 = *(undefined4 *)(iVar3 + 0x60);
    iVar3 = FUN_007c2511();
    *param_7 = *(undefined4 *)(iVar3 + 100);
    iVar3 = FUN_007c2511();
    iVar3 = iVar3 + 0xd0;
  }
  else {
    iVar3 = FUN_007c2511();
    *param_2 = *(undefined4 *)(iVar3 + 0x20);
    iVar3 = FUN_007c2511();
    *param_3 = *(undefined4 *)(iVar3 + 0x28);
    pcVar1 = *(code **)(*param_1 + 0x28c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      iVar3 = FUN_007c2511();
      uVar2 = *(undefined4 *)(iVar3 + 0x24);
    }
    else {
      iVar3 = FUN_007c2511();
      uVar2 = *(undefined4 *)(iVar3 + 0x20);
    }
    *param_4 = uVar2;
    iVar3 = FUN_007c2511();
    *param_6 = *(undefined4 *)(iVar3 + 0x30);
    iVar3 = FUN_007c2511();
    *param_7 = *(undefined4 *)(iVar3 + 0x34);
    iVar3 = FUN_007c2511();
    iVar3 = iVar3 + 0x98;
  }
  *param_8 = iVar3;
  iVar3 = FUN_007c2511();
  *param_9 = iVar3 + 0xb0;
  return;
}




/* vtable slots: CMFCVisualManager[71], CMFCVisualManagerOffice2003[71], CMFCVisualManagerOfficeXP[71] */
/* 007f373d  FUN_007f373d  6 bytes, 0 callers */

undefined4 FUN_007f373d(void)

{
  return 0xffffffff;
}




/* vtable slots: CMFCVisualManager[181], CMFCVisualManagerOfficeXP[181] */
/* 007f3743  GetToolTipInfo  33 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManager::GetToolTipInfo(class CMFCToolTipInfo
   &,unsigned int)
   
   Library: Visual Studio 2012 Release */

int __thiscall
CMFCVisualManager::GetToolTipInfo(CMFCVisualManager *this,CMFCToolTipInfo *param_1,uint param_2)

{
  CMFCToolTipInfo local_38 [52];
  
  CMFCToolTipInfo::CMFCToolTipInfo(local_38);
  CMFCToolTipInfo::operator=(param_1,local_38);
  return 1;
}




/* vtable slots: CMFCVisualManager[45] */
/* 007f3764  FUN_007f3764  171 bytes, 1 callers */

undefined4 FUN_007f3764(int *param_1,int param_2)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar4;
  
  if (DAT_00a127ac == 0) {
LAB_007f3793:
    if ((param_1[9] & 0x40000U) == 0) {
LAB_007f37a1:
      bVar2 = false;
      goto LAB_007f37a3;
    }
  }
  else {
    pcVar1 = *(code **)(*param_1 + 0x60);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      if (DAT_00a127ac == 0) goto LAB_007f3793;
      goto LAB_007f37a1;
    }
  }
  bVar2 = true;
LAB_007f37a3:
  iVar3 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPaneButton_00a009f8);
  if (iVar3 == 0) {
    if (!bVar2) {
      if (param_2 == 2) {
        uVar4 = FUN_007fe047();
        return uVar4;
      }
      iVar3 = FUN_007c2511();
      return *(undefined4 *)(iVar3 + 0x68);
    }
    iVar3 = FUN_007c2511();
  }
  else {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar3 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar3 == 0) {
      iVar3 = FUN_007c2511();
      if (bVar2) {
        return *(undefined4 *)(iVar3 + 0x1c);
      }
      return *(undefined4 *)(iVar3 + 0x6c);
    }
    iVar3 = FUN_007c2511();
    if (!bVar2) {
      return *(undefined4 *)(iVar3 + 0x70);
    }
  }
  return *(undefined4 *)(iVar3 + 0x38);
}




/* vtable slots: CMFCVisualManager[49], CMFCVisualManagerOffice2003[49], CMFCVisualManagerOfficeXP[49] */
/* 007f380f  FUN_007f380f  9 bytes, 1 callers */

undefined4 FUN_007f380f(void)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  return *(undefined4 *)(iVar1 + 0x38);
}




/* vtable slots: CMFCVisualManager[48] */
/* 007f3818  FUN_007f3818  9 bytes, 0 callers */

undefined4 FUN_007f3818(void)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  return *(undefined4 *)(iVar1 + 0x54);
}




/* vtable slots: CMFCVisualManager[109], CMFCVisualManagerOfficeXP[109] */
/* 007f3958  FUN_007f3958  165 bytes, 1 callers */

void FUN_007f3958(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  COLORREF CVar4;
  
  iVar3 = FUN_007c2511();
  uVar1 = *(undefined4 *)(iVar3 + 0x58);
  CVar4 = GetTextColor((HDC)param_1[2]);
  if (0 < param_6) {
    FUN_007a500d(param_2,param_3,param_6 + param_2,param_5,uVar1);
  }
  if (0 < param_7) {
    FUN_007a500d(param_2,param_3,param_4,param_7 + param_3,uVar1);
  }
  if (0 < param_8) {
    FUN_007a500d(param_4 - param_8,param_3,param_4,param_5,uVar1);
  }
  if (0 < param_9) {
    FUN_007a500d(param_2,param_5 - param_9,param_4,param_5,uVar1);
  }
  pcVar2 = *(code **)(*param_1 + 0x30);
  guard_check_icall(CVar4);
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCVisualManager[17] */
/* 007f39fd  FUN_007f39fd  173 bytes, 1 callers */

void FUN_007f39fd(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  
  iVar2 = param_7;
  if ((param_7 == 0) || (*(int *)(param_7 + 0x8c) == 0)) {
    iVar1 = FUN_007c2511();
    uVar4 = *(ulong *)(iVar1 + 0x5c);
    if (iVar2 != 0) goto LAB_007f3a2c;
  }
  else {
    iVar1 = FUN_007c2511();
    uVar4 = *(ulong *)(iVar1 + 0x24);
LAB_007f3a2c:
    if (*(int *)(iVar2 + 0x8c) != 0) {
      iVar2 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar2 + 0x20);
      goto LAB_007f3a47;
    }
  }
  iVar2 = FUN_007c2511();
  uVar3 = *(ulong *)(iVar2 + 0x58);
LAB_007f3a47:
  if (param_6 == 0) {
    InflateRect((LPRECT)&param_2,-3,0);
    param_5 = (param_5 + param_3) / 2;
    param_3 = param_5 + -1;
    param_5 = param_5 + 2;
  }
  else {
    InflateRect((LPRECT)&param_2,0,-3);
    param_4 = (param_4 + param_2) / 2;
    param_2 = param_4 + -1;
    param_4 = param_4 + 2;
  }
  CDC::Draw3dRect(param_1,(tagRECT *)&param_2,uVar4,uVar3);
  return;
}




/* vtable slots: CMFCVisualManager[111] */
/* 007f3aaa  FUN_007f3aaa  169 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007f3aaa(CDC *param_1,LONG param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7)

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar2 != -0x98) {
    hbr = *(HBRUSH *)(iVar2 + 0x9c);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  local_18.top = param_3 + -1;
  local_18.left = param_2;
  local_18.right = param_4 + 1;
  local_18.bottom = param_5 + 1;
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x30);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar2 + 0x30),uVar1);
  InflateRect(&local_18,-1,-1);
  DrawEdge(*(HDC *)(param_1 + 4),&local_18,(uint)(param_7 == 1) * 4 + 4,0xf);
  return 1;
}




/* vtable slots: CMFCVisualManager[34] */
/* 007f3b53  OnDrawButtonBorder  93 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnDrawButtonBorder(class CDC *,class
   CMFCToolBarButton *,class CRect,enum CMFCVisualManager::AFX_BUTTON_STATE)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnDrawButtonBorder(undefined4 param_1_00,CDC *param_1)

{
  int iVar1;
  ulong uVar2;
  int in_stack_0000001c;
  ulong uVar3;
  
  iVar1 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPaneButton_00a009f8);
  if (iVar1 == 0) {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x58);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x60);
  }
  if (in_stack_0000001c == 1) {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x5c);
  }
  else {
    if (in_stack_0000001c != 2) {
      return;
    }
    uVar3 = uVar2;
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x5c);
  }
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,uVar2,uVar3);
  return;
}




/* vtable slots: CMFCVisualManager[35] */
/* 007f3bb0  FUN_007f3bb0  89 bytes, 0 callers */

void FUN_007f3bb0(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[0x14] != 0) {
    pcVar1 = *(code **)(*param_2 + 0x70);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      return;
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x88);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[53], CMFCVisualManagerOfficeXP[53] */
/* 007f3c09  FUN_007f3c09  160 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f3c09(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  HBRUSH pHVar3;
  COLORREF in_stack_0000001c;
  int in_stack_00000020;
  
  if (in_stack_0000001c == 0xffffffff) {
    iVar2 = FUN_007c2511();
    pHVar3 = (HBRUSH)0x0;
    if (iVar2 != -0xd0) {
      pHVar3 = *(HBRUSH *)(iVar2 + 0xd4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,pHVar3);
  }
  else {
    pHVar3 = CreateSolidBrush(in_stack_0000001c);
    Attach(pHVar3);
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,(HBRUSH)0x0);
    FUN_00416100();
  }
  if (in_stack_00000020 == 0) {
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x5c),uVar1);
  }
  return;
}




/* vtable slots: CMFCVisualManager[55] */
/* 007f3ca9  FUN_007f3ca9  85 bytes, 1 callers */

void FUN_007f3ca9(CDC *param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  int in_stack_0000001c;
  int in_stack_00000020;
  
  if (in_stack_0000001c == 0) {
    if ((in_stack_00000020 == 0) && (*(int *)(param_2 + 0x2c4) == 0)) {
      return;
    }
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x60);
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x5c);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x5c);
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x60);
  }
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,uVar2,uVar3);
  return;
}




/* vtable slots: CMFCVisualManager[52] */
/* 007f3cfe  FUN_007f3cfe  117 bytes, 0 callers */

void FUN_007f3cfe(CDC *param_1)

{
  ulong uVar1;
  HBRUSH hbr;
  int iVar2;
  HDC hDC;
  
  hbr = GetSysColorBrush(0x18);
  if (param_1 == (CDC *)0x0) {
    hDC = (HDC)0x0;
  }
  else {
    hDC = *(HDC *)(param_1 + 4);
  }
  FillRect(hDC,(RECT *)&stack0x0000000c,hbr);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x5c);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x58),uVar1);
  InflateRect((LPRECT)&stack0x0000000c,-1,-1);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x5c),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[21] */
/* 007f3d73  FUN_007f3d73  348 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f3d73(CDC *param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,int param_7)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  byte bVar4;
  ulong uVar5;
  undefined4 local_34;
  undefined4 local_30;
  CDC *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = param_1;
  pcVar1 = *(code **)(*param_2 + 0xc);
  guard_check_icall(&local_18);
  (*pcVar1)();
  if (param_7 == -1) {
    pcVar1 = *(code **)(*param_2 + 0x14);
    guard_check_icall(param_4,param_5);
    param_7 = (*pcVar1)();
  }
  local_28.left = local_18.left;
  local_28.top = local_18.top;
  local_28.right = local_18.right;
  local_28.bottom = local_18.bottom;
  bVar4 = 1;
  if ((param_2[1] != 0) && ((param_2[2] != 0 || (param_2[5] != 0)))) {
    OffsetRect(&local_28,1,1);
  }
  if (param_6 == 0) {
    if (param_2[8] == -1) {
      bVar4 = -(param_3 != 0) & 3;
    }
    else if (((*(byte *)(param_2 + 8) < 0xc1) || (*(byte *)((int)param_2 + 0x21) < 0xc1)) ||
            (*(byte *)((int)param_2 + 0x22) < 0xc1)) {
      bVar4 = 0;
    }
    else {
      bVar4 = 3;
    }
  }
  local_34 = 0;
  local_30 = 0;
  FUN_00814d1c(local_2c,param_7,&local_28,bVar4,&local_34);
  if (param_6 == 0) {
    if ((param_2[1] == 0) || ((param_2[2] == 0 && (param_2[5] == 0)))) {
      if ((param_2[2] == 0) && ((param_2[1] == 0 && (param_2[5] == 0)))) {
        return;
      }
      iVar2 = FUN_007c2511();
      uVar5 = *(ulong *)(iVar2 + 0x58);
      iVar2 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar2 + 0x5c);
    }
    else {
      iVar2 = FUN_007c2511();
      uVar5 = *(ulong *)(iVar2 + 100);
      iVar2 = FUN_007c2511();
      CDC::Draw3dRect(local_2c,&local_18,*(ulong *)(iVar2 + 0x60),uVar5);
      InflateRect(&local_18,-1,-1);
      iVar2 = FUN_007c2511();
      uVar5 = *(ulong *)(iVar2 + 0x5c);
      iVar2 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar2 + 0x60);
    }
    CDC::Draw3dRect(local_2c,&local_18,uVar3,uVar5);
  }
  return;
}




/* vtable slots: CMFCVisualManager[104], CMFCVisualManagerOffice2003[104], CMFCVisualManagerOffice2007[104], CMFCVisualManagerOfficeXP[104] */
/* 007f3ecf  FUN_007f3ecf  67 bytes, 0 callers */

void FUN_007f3ecf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a4);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_7 != 0,param_6,0,param_8);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[105], CMFCVisualManagerOfficeXP[105] */
/* 007f3f12  FUN_007f3f12  401 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f3f12(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  HBRUSH pHVar5;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000024;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined **local_18;
  HBRUSH local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x7f3f1e;
  if (DAT_00a12704 == 0) {
    if (in_stack_0000001c != 0) {
      DrawFocusRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008);
    }
    InflateRect((LPRECT)&stack0x00000008,-1,-1);
    iVar2 = FUN_007c2511();
    if (in_stack_00000024 == 0) {
      uVar4 = *(undefined4 *)(iVar2 + 0x54);
    }
    else {
      uVar4 = *(undefined4 *)(iVar2 + 0x6c);
    }
    FUN_007a506d(&stack0x00000008,uVar4);
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x5c);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar2 + 0x60),uVar1);
    InflateRect((LPRECT)&stack0x00000008,-1,-1);
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 100);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar2 + 0x58),uVar1);
    if (in_stack_00000018 == 1) {
      local_20 = 0;
      local_1c = 0;
      FUN_00814d1c(param_1,2,&stack0x00000008,0,&local_20);
    }
    else if (in_stack_00000018 == 2) {
      InflateRect((LPRECT)&stack0x00000008,-1,-1);
      local_14 = (HBRUSH)0x0;
      local_18 = CBrush::vftable;
      local_8 = 1;
      iVar2 = FUN_007c2511();
      pHVar5 = CreateHatchBrush(5,*(COLORREF *)(iVar2 + 0x28));
      Attach(pHVar5);
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,local_14);
      local_18 = CBrush::vftable;
      FUN_00416100();
    }
  }
  else {
    CDrawingManager::CDrawingManager((CDrawingManager *)&local_20,param_1);
    local_8 = 0;
    InflateRect((LPRECT)&stack0x00000008,-1,-1);
    iVar2 = FUN_007c2511();
    uVar4 = *(undefined4 *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    if (in_stack_00000024 == 0) {
      uVar3 = *(undefined4 *)(iVar2 + 0x54);
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x6c);
    }
    FUN_00816b6a(&stack0x00000008,uVar3,uVar4);
    if (in_stack_00000018 == 1) {
      local_28 = 0;
      local_24 = 0;
      FUN_00814d1c(param_1,2,&stack0x00000008,0,&local_28);
    }
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManager[28] */
/* 007f40a3  FUN_007f40a3  141 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f40a3(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,
                 undefined4 param_6,int param_7,int param_8)

{
  ulong uVar1;
  int iVar2;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((param_8 != 0) || (param_7 != 0)) {
    if (*(int *)(in_ECX + 0x50) == 0) {
      iVar2 = FUN_007c2511();
      uVar1 = *(ulong *)(iVar2 + 0x5c);
      iVar2 = FUN_007c2511();
      CDC::Draw3dRect(param_1,(tagRECT *)&param_2,*(ulong *)(iVar2 + 0x58),uVar1);
    }
    else {
      local_18.left = param_2;
      local_18.top = param_3;
      local_18.right = param_4;
      local_18.bottom = param_5;
      InflateRect(&local_18,-1,-1);
      iVar2 = FUN_007c2511();
      uVar1 = *(ulong *)(iVar2 + 0x60);
      iVar2 = FUN_007c2511();
      CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar2 + 0x60),uVar1);
    }
  }
  return;
}




/* vtable slots: CMFCVisualManager[27] */
/* 007f4130  FUN_007f4130  335 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f4130(CDC *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  COLORREF CVar3;
  int iVar4;
  HBRUSH hbr;
  ulong uVar5;
  ulong uVar6;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  undefined4 local_20;
  undefined4 local_1c;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x7f413c;
  CVar3 = GetTextColor(*(HDC *)(param_1 + 8));
  if (DAT_00a12704 == 0) {
    iVar4 = FUN_007c2511();
    hbr = (HBRUSH)0x0;
    if (iVar4 != -0xd0) {
      hbr = *(HBRUSH *)(iVar4 + 0xd4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
    iVar4 = FUN_007c2511();
    uVar6 = *(ulong *)(iVar4 + 0x5c);
    iVar4 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar4 + 0x5c),uVar6);
    if (in_stack_0000001c == 0) {
      if (in_stack_00000020 == 0) goto LAB_007f4244;
      iVar4 = FUN_007c2511();
      uVar6 = *(ulong *)(iVar4 + 0x58);
      iVar4 = FUN_007c2511();
      uVar5 = *(ulong *)(iVar4 + 0x5c);
    }
    else {
      OffsetRect((LPRECT)&stack0x00000008,1,1);
      iVar4 = FUN_007c2511();
      uVar6 = *(ulong *)(iVar4 + 0x5c);
      iVar4 = FUN_007c2511();
      uVar5 = *(ulong *)(iVar4 + 0x58);
    }
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,uVar5,uVar6);
    goto LAB_007f4244;
  }
  CDrawingManager::CDrawingManager(local_18,param_1);
  local_8 = 0;
  iVar4 = FUN_007c2511();
  uVar1 = *(undefined4 *)(iVar4 + 0x5c);
  iVar4 = FUN_007c2511();
  FUN_00816b6a(&stack0x00000008,*(undefined4 *)(iVar4 + 0x54),uVar1);
  if (in_stack_0000001c == 0) {
    if (in_stack_00000020 != 0) goto LAB_007f419a;
  }
  else {
    OffsetRect((LPRECT)&stack0x00000008,1,1);
LAB_007f419a:
    iVar4 = FUN_007c2511();
    FUN_00816b6a(&stack0x00000008,0xffffffff,*(undefined4 *)(iVar4 + 0x58));
  }
  local_8 = 0xffffffff;
  FUN_0081510b();
LAB_007f4244:
  local_20 = 0;
  local_1c = 0;
  FUN_00814d1c(param_1,0,&stack0x00000008,in_stack_00000018 != 0,&local_20);
  pcVar2 = *(code **)(*(int *)param_1 + 0x30);
  guard_check_icall(CVar3);
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCVisualManager[106], CMFCVisualManagerOfficeXP[106] */
/* 007f427f  FUN_007f427f  191 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f427f(int param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  CDC local_38 [20];
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x7f428b;
  FUN_0079dfaa(param_1);
  local_8 = 0;
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  GetWindowRect(*(HWND *)(param_1 + 0x20),&local_24);
  local_24.bottom = local_24.bottom - local_24.top;
  local_24.right = local_24.right - local_24.left;
  local_24.top = 0;
  local_24.left = 0;
  iVar1 = FUN_00797b3d();
  if (iVar1 < 0) {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x58);
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x58);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x5c);
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x60);
  }
  CDC::Draw3dRect(local_38,&local_24,uVar2,uVar3);
  InflateRect(&local_24,-1,-1);
  iVar1 = FUN_007c2511();
  uVar3 = *(ulong *)(iVar1 + 0x6c);
  iVar1 = FUN_007c2511();
  CDC::Draw3dRect(local_38,&local_24,*(ulong *)(iVar1 + 0x6c),uVar3);
  FUN_0079e0f8();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[154], CMFCVisualManagerOffice2003[154], CMFCVisualManagerOfficeXP[154] */
/* 007f433e  FUN_007f433e  319 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f433e(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  int iVar2;
  AFX_GLOBAL_DATA *this;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  CDrawingManager local_38 [8];
  undefined **local_30 [2];
  CDC *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x7f434a;
  local_24.top = (param_5 + param_3) / 2;
  local_28 = param_1;
  local_24.left = (param_4 + param_2) / 2;
  local_24.right = local_24.left + 1;
  local_24.bottom = local_24.top + 1;
  InflateRect(&local_24,5,5);
  iVar2 = FUN_007c2511();
  if (8 < *(int *)(iVar2 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar2 == 0) {
      CDrawingManager::CDrawingManager(local_38,param_1);
      local_8 = 1;
      if (param_6 == 0) {
        uVar5 = 0x2c7547;
        puVar3 = &LAB_0080d0a0;
      }
      else {
        iVar2 = FUN_007c2511();
        uVar5 = *(undefined4 *)(iVar2 + 0x20);
        iVar2 = FUN_007c2511();
        puVar3 = *(undefined1 **)(iVar2 + 0x38);
      }
      FUN_00815451(&local_24,puVar3,uVar5);
      FUN_0081510b();
      goto LAB_007f4475;
    }
  }
  if (param_6 == 0) {
    uVar5 = 0x7f00;
  }
  else {
    iVar2 = FUN_007c2511();
    uVar5 = *(undefined4 *)(iVar2 + 0x38);
  }
  FUN_0079de5e(uVar5);
  local_8 = 0;
  uVar5 = FUN_0079efbc(local_30);
  pcVar1 = *(code **)(*(int *)local_28 + 0x24);
  guard_check_icall(8);
  uVar4 = (*pcVar1)();
  Ellipse(*(HDC *)(local_28 + 4),local_24.left,local_24.top,local_24.right,local_24.bottom);
  FUN_0079efbc(uVar5);
  FUN_0079efbc(uVar4);
  local_30[0] = CBrush::vftable;
  FUN_00416100();
LAB_007f4475:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[29] */
/* 007f447d  OnDrawEditBorder  33 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnDrawEditBorder(class CDC *,class
   CRect,int,int,class CMFCToolBarEditBoxButton *)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnDrawEditBorder(undefined4 param_1_00,int param_1)

{
  int in_stack_0000001c;
  
  if (in_stack_0000001c != 0) {
    DrawEdge(*(HDC *)(param_1 + 4),(LPRECT)&stack0x00000008,10,0xf);
  }
  return;
}




/* vtable slots: CMFCVisualManager[98], CMFCVisualManagerOfficeXP[98] */
/* 007f449e  OnDrawExpandingBox  209 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnDrawExpandingBox(class CDC *,class
   CRect,int,unsigned long)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManager::OnDrawExpandingBox
          (undefined4 param_1_00,CDC *param_1,int param_3,int param_4,int param_5,int param_6,
          int param_7,ulong param_8)

{
  int iVar1;
  undefined1 local_28 [8];
  undefined **local_20 [2];
  undefined4 local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x7f44aa;
  CDC::Draw3dRect(param_1,(tagRECT *)&param_3,param_8,param_8);
  InflateRect((LPRECT)&param_3,-2,-2);
  iVar1 = FUN_007c2511();
  FUN_0079df60(0,1,*(undefined4 *)(iVar1 + 0x68));
  local_8 = 0;
  local_18 = FUN_0079efbc(local_20);
  local_14 = (param_5 + param_3) / 2;
  iVar1 = (param_6 + param_4) / 2;
  FUN_0079ec58(local_28,param_3,iVar1);
  CDC::LineTo(param_1,param_5,iVar1);
  iVar1 = local_14;
  if (param_7 == 0) {
    FUN_0079ec58(local_28,local_14,param_4);
    CDC::LineTo(param_1,iVar1,param_6);
  }
  FUN_0079efbc(local_18);
  local_20[0] = CPen::vftable;
  FUN_00416100();
  return;
}




/* vtable slots: CMFCVisualManager[84] */
/* 007f456f  FUN_007f456f  129 bytes, 0 callers */

void FUN_007f456f(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x60);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x54),uVar1);
  InflateRect((LPRECT)&stack0x0000000c,-1,-1);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x5c),uVar1);
  InflateRect((LPRECT)&stack0x0000000c,-1,-1);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x54);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x54),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[86], CMFCVisualManagerOfficeXP[86] */
/* 007f45f0  FUN_007f45f0  134 bytes, 1 callers */

void FUN_007f45f0(int param_1,CDC *param_2,tagRECT *param_3,int param_4)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (param_4 == 0) {
    if (*(int *)(param_1 + 0xac) == 0) {
      iVar1 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar1 + 0x58);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x5c);
    }
    else {
      iVar1 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar1 + 0x20);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x24);
    }
    CDC::Draw3dRect(param_2,param_3,uVar2,uVar3);
  }
  else {
    if (*(int *)(param_1 + 0xac) == 0) {
      iVar1 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar1 + 0x58);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x58);
    }
    else {
      iVar1 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar1 + 0x20);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x20);
    }
    CDC::Draw3dRect(param_2,param_3,uVar2,uVar3);
    param_3->left = param_3->left + 1;
    param_3->top = param_3->top + 1;
  }
  return;
}




/* vtable slots: CMFCVisualManager[87], CMFCVisualManagerOffice2003[87], CMFCVisualManagerOffice2007[87], CMFCVisualManagerOfficeXP[87] */
/* 007f4676  OnDrawHeaderCtrlSortArrow  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnDrawHeaderCtrlSortArrow(class
   CMFCHeaderCtrl *,class CDC *,class CRect &,int)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManager::OnDrawHeaderCtrlSortArrow
          (CMFCVisualManager *this,CMFCHeaderCtrl *param_1,CDC *param_2,CRect *param_3,int param_4)

{
  DoDrawHeaderSortArrow
            (this,param_2,*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),
             *(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc),param_4,
             *(undefined4 *)(param_1 + 0xac));
  return;
}




/* vtable slots: CMFCVisualManager[79] */
/* 007f46a1  FUN_007f46a1  167 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f46a1(CDC *param_1,int param_2,LONG param_3,int param_4,LONG param_5,int param_6)

{
  ulong uVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c;
  tagRECT local_28;
  int local_18;
  LONG LStack_14;
  int local_10;
  LONG LStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18 = param_2;
  LStack_14 = param_3;
  local_10 = param_4;
  LStack_c = param_5;
  piVar2 = (int *)FUN_0081507c(&local_30);
  local_18 = local_10 - *piVar2;
  local_30 = 0;
  local_2c = 0;
  FUN_00814d1c(param_1,0xe,&local_18,-(param_6 != 0) & 3,&local_30);
  local_28.right = local_18 + -1;
  local_28.top = param_3;
  local_28.bottom = param_5;
  local_28.left = local_18 + -3;
  InflateRect(&local_28,0,-2);
  iVar3 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar3 + 0x24);
  iVar3 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_28,*(ulong *)(iVar3 + 0x20),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[15] */
/* 007f4748  FUN_007f4748  86 bytes, 0 callers */

void FUN_007f4748(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x60);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 100),uVar1);
  InflateRect((LPRECT)&stack0x0000000c,-1,-1);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x5c),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[41], CMFCVisualManagerOffice2003[41], CMFCVisualManagerOfficeXP[41] */
/* 007f479e  FUN_007f479e  61 bytes, 1 callers */

void FUN_007f479e(undefined4 param_1,int param_2)

{
  int in_stack_00000020;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = 0;
  FUN_00814d1c(param_1,(-(in_stack_00000020 != 0) & 10U) + 2,&stack0x0000000c,
               *(uint *)(param_2 + 0x24) >> 0x12 & 1,&local_c);
  return;
}




/* vtable slots: CMFCVisualManager[42], CMFCVisualManagerOffice2003[42], CMFCVisualManagerOfficeXP[42] */
/* 007f47db  FUN_007f47db  114 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f47db(CDC *param_1,undefined4 param_2,int param_3,LONG param_4,undefined4 param_5,
                 LONG param_6,int param_7)

{
  ulong uVar1;
  int iVar2;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.right = param_3 + 1;
  local_18.top = param_4;
  local_18.bottom = param_6;
  local_18.left = param_3 + -1;
  InflateRect(&local_18,0,(-(uint)(param_7 != 0) & 3) - 4);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x5c);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar2 + 0x58),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[19] */
/* 007f484d  FUN_007f484d  124 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007f484d(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,int param_5)

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar2 != -0x98) {
    hbr = *(HBRUSH *)(iVar2 + 0x9c);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  local_18.top = param_5 + -2;
  local_18.left = param_2;
  local_18.right = param_4;
  local_18.bottom = param_5;
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x24);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar2 + 0x20),uVar1);
  iVar2 = FUN_007c2511();
  return *(undefined4 *)(iVar2 + 0x28);
}




/* vtable slots: CMFCVisualManager[31] */
/* 007f48c9  FUN_007f48c9  35 bytes, 0 callers */

void FUN_007f48c9(void)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  FUN_007a506d(&stack0x00000008,*(undefined4 *)(iVar1 + 0x80));
  return;
}




/* vtable slots: CMFCVisualManager[32] */
/* 007f48ec  FUN_007f48ec  162 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f48ec(CDC *param_1,LONG param_2,int param_3,LONG param_4,LONG param_5,int param_6,
                 int param_7)

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  undefined4 local_20;
  undefined4 local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.top = param_3 + -2;
  local_18.left = param_2;
  local_18.right = param_4;
  local_18.bottom = param_5;
  iVar2 = FUN_007c2511();
  if (iVar2 == -0xd0) {
    hbr = (HBRUSH)0x0;
  }
  else {
    hbr = *(HBRUSH *)(iVar2 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_18,hbr);
  local_20 = 0;
  local_1c = 0;
  FUN_00814d1c(param_1,(-(uint)(param_6 != 0) & 0xfffffff9) + 7,&param_2,0,&local_20);
  if (param_7 != 0) {
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&param_2,*(ulong *)(iVar2 + 0x5c),uVar1);
  }
  return;
}




/* vtable slots: CMFCVisualManager[16] */
/* 007f498e  OnDrawMenuShadow  89 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnDrawMenuShadow(class CDC *,class CRect
   const &,class CRect const &,int,int,int,class CBitmap *,class CBitmap *,int)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManager::OnDrawMenuShadow
          (CMFCVisualManager *this,CDC *param_1,CRect *param_2,CRect *param_3,int param_4,
          int param_5,int param_6,CBitmap *param_7,CBitmap *param_8,int param_9)

{
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7f499a;
  CDrawingManager::CDrawingManager(local_18,param_1);
  local_8 = 0;
  FUN_00816e2b(*(undefined4 *)param_2,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
               *(undefined4 *)(param_2 + 0xc),param_4,param_5,param_6,param_7,param_8,0xffffffff,
               param_9 == 0);
  FUN_0081510b();
  return;
}




/* vtable slots: CMFCVisualManager[22] */
/* 007f49e7  OnDrawMenuSystemButton  88 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnDrawMenuSystemButton(class CDC *,class
   CRect,unsigned int,unsigned int,int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnDrawMenuSystemButton(undefined4 param_1_00,int param_1)

{
  uint uVar1;
  int in_stack_00000018;
  uint in_stack_0000001c;
  
  uVar1 = 0;
  if (in_stack_00000018 == 0xf020) {
    uVar1 = 1;
  }
  else if (in_stack_00000018 != 0xf060) {
    if (in_stack_00000018 != 0xf120) {
      return;
    }
    uVar1 = 3;
  }
  if ((in_stack_0000001c & 0x20000) != 0) {
    uVar1 = uVar1 | 0x200;
  }
  if ((in_stack_0000001c & 0x40000) != 0) {
    uVar1 = uVar1 | 0x100;
  }
  DrawFrameControl(*(HDC *)(param_1 + 4),(LPRECT)&stack0x00000008,1,uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[83] */
/* 007f4a3f  FUN_007f4a3f  257 bytes, 1 callers */

void FUN_007f4a3f(CDC *param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  int in_stack_00000020;
  int in_stack_00000024;
  ulong uVar3;
  
  if (*(int *)(param_2 + 0x188) == 1) {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x60);
    uVar2 = 0x7f;
  }
  else {
    if (*(int *)(param_2 + 0x188) != 2) {
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x60);
      iVar1 = FUN_007c2511();
      CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar1 + 0x54),uVar2);
      InflateRect((LPRECT)&stack0x0000000c,-1,-1);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x58);
      goto LAB_007f4ac8;
    }
    iVar1 = FUN_007c2511();
    uVar2 = 0x7f0000;
    uVar3 = *(ulong *)(iVar1 + 0x60);
  }
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,uVar2,uVar3);
  InflateRect((LPRECT)&stack0x0000000c,-1,-1);
LAB_007f4ac8:
  iVar1 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar1 + 0x5c),uVar2);
  InflateRect((LPRECT)&stack0x0000000c,2 - in_stack_00000024,2 - in_stack_00000020);
  iVar1 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar1 + 0x54);
  iVar1 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar1 + 0x54),uVar2);
  InflateRect((LPRECT)&stack0x0000000c,1,1);
  iVar1 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar1 + 0x54);
  iVar1 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar1 + 0x54),uVar2);
  return;
}




/* vtable slots: CMFCVisualManager[58], CMFCVisualManagerOfficeXP[58] */
/* 007f4b40  FUN_007f4b40  72 bytes, 1 callers */

void FUN_007f4b40(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  
  iVar2 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar2 != -0xd0) {
    hbr = *(HBRUSH *)(iVar2 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar2 + 0x5c),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[57], CMFCVisualManagerOfficeXP[57] */
/* 007f4b88  FUN_007f4b88  166 bytes, 1 callers */

void FUN_007f4b88(CDC *param_1,tagRECT *param_2,int param_3,int param_4)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (param_3 == 0) {
    if (param_4 != 0) goto LAB_007f4bdd;
  }
  else {
    if (param_4 != 0) {
      iVar1 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar1 + 0x54);
      iVar1 = FUN_007c2511();
      CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar1 + 0x60),uVar3);
      InflateRect(param_2,-1,-1);
      iVar1 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar1 + 0x5c);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x58);
      goto LAB_007f4c12;
    }
LAB_007f4bdd:
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x60);
    iVar1 = FUN_007c2511();
    CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar1 + 0x54),uVar3);
    InflateRect(param_2,-1,-1);
  }
  iVar1 = FUN_007c2511();
  uVar3 = *(ulong *)(iVar1 + 0x58);
  iVar1 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar1 + 0x5c);
LAB_007f4c12:
  CDC::Draw3dRect(param_1,param_2,uVar2,uVar3);
  InflateRect(param_2,-1,-1);
  return;
}




/* vtable slots: CMFCVisualManager[14] */
/* 007f4c2e  FUN_007f4c2e  438 bytes, 1 callers */

void FUN_007f4c2e(int *param_1,int *param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  COLORREF CVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  pcVar1 = *(code **)(*param_2 + 0x170);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_2 + 0x1c0);
    guard_check_icall();
    uVar3 = (*pcVar1)();
    if ((uVar3 & 0xf00) != 0) {
      CVar4 = GetBkColor((HDC)param_1[2]);
      if (param_2[0x23] == 0) {
        iVar2 = FUN_007c2511();
        uVar5 = *(undefined4 *)(iVar2 + 0x5c);
      }
      else {
        iVar2 = FUN_007c2511();
        uVar5 = *(undefined4 *)(iVar2 + 0x24);
      }
      if (param_2[0x23] == 0) {
        iVar2 = FUN_007c2511();
        uVar6 = *(undefined4 *)(iVar2 + 0x58);
      }
      else {
        iVar2 = FUN_007c2511();
        uVar6 = *(undefined4 *)(iVar2 + 0x20);
      }
      if ((uVar3 & 0x100) != 0) {
        FUN_007a500d(0,0,1,(param_3[3] - param_3[1]) + -1,uVar5);
      }
      if ((uVar3 & 0x200) != 0) {
        FUN_007a500d(0,0,(param_3[2] - *param_3) + -1,1,uVar5);
      }
      if ((uVar3 & 0x400) != 0) {
        FUN_007a500d(param_3[2],0,0xffffffff,param_3[3] - param_3[1],uVar6);
      }
      if ((uVar3 & 0x800) != 0) {
        FUN_007a500d(0,param_3[3],(param_3[2] - *param_3) + -1,0xffffffff,uVar6);
      }
      pcVar1 = *(code **)(*param_2 + 0x1cc);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        FUN_007a500d(0,0,param_3[2] - *param_3,1,uVar6);
        FUN_007a500d(0,1,param_3[2] - *param_3,1,uVar5);
      }
      if ((uVar3 & 0x100) != 0) {
        *param_3 = *param_3 + 1;
      }
      if ((uVar3 & 0x200) != 0) {
        param_3[1] = param_3[1] + 1;
      }
      if ((uVar3 & 0x400) != 0) {
        param_3[2] = param_3[2] + -1;
      }
      if ((uVar3 & 0x800) != 0) {
        param_3[3] = param_3[3] + -1;
      }
      pcVar1 = *(code **)(*param_1 + 0x2c);
      guard_check_icall(CVar4);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCVisualManager[20] */
/* 007f4de4  OnDrawPaneCaption  112 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::OnDrawPaneCaption(class CDC *,class
   CDockablePane *,int,class CRect,class CRect)
   
   Library: Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::OnDrawPaneCaption
          (undefined4 param_1_00,int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  HBRUSH local_14;
  
  iVar1 = FUN_007c2511();
  if (param_3 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x80);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x7c);
  }
  FUN_0079de5e(uVar2);
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000010,local_14);
  iVar1 = FUN_007c2511();
  if (param_3 == 0) {
    uVar3 = *(ulong *)(iVar1 + 0x84);
  }
  else {
    uVar3 = *(ulong *)(iVar1 + 0x74);
  }
  FUN_00416100();
  return uVar3;
}




/* vtable slots: CMFCVisualManager[97], CMFCVisualManagerOffice2003[97], CMFCVisualManagerOffice2007[97], CMFCVisualManagerOfficeXP[97] */
/* 007f4e54  FUN_007f4e54  284 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f4e54(CDC *param_1,CWnd *param_2,int param_3,LONG param_4,int param_5,LONG param_6,
                 int param_7)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  ulong uVar4;
  CDC *pCVar5;
  CWnd *pCVar6;
  LONG LVar7;
  LONG LVar8;
  int iVar9;
  LONG LVar10;
  int iVar11;
  LONG LVar12;
  int iVar13;
  LONG LVar14;
  undefined4 uVar15;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_007c2511();
  local_28.left = *(int *)(iVar2 + 0x16c);
  local_28.top = *(LONG *)(iVar2 + 0x170);
  local_28.right = *(LONG *)(iVar2 + 0x174);
  local_28.bottom = *(LONG *)(iVar2 + 0x178);
  CWnd::ScreenToClient(param_2,&local_28);
  local_18.left = param_3;
  local_18.top = param_4;
  local_18.right = param_5;
  local_18.bottom = param_6;
  if (local_28.left <= param_3) {
    local_18.left = local_28.left;
  }
  uVar15 = 0;
  iVar2 = *in_ECX;
  pCVar5 = param_1;
  pCVar6 = param_2;
  LVar7 = local_18.left;
  LVar8 = param_4;
  iVar9 = param_5;
  LVar10 = param_6;
  iVar11 = param_3;
  LVar12 = param_4;
  iVar13 = param_5;
  LVar14 = param_6;
  guard_check_icall(param_1,param_2,local_18.left,param_4,param_5,param_6,param_3,param_4,param_5,
                    param_6,0);
  (**(code **)(iVar2 + 0x34))();
  if (param_7 == 0) {
    return;
  }
  pcVar1 = *(code **)(*(int *)param_2 + 0x194);
  guard_check_icall(pCVar5,pCVar6,LVar7,LVar8,iVar9,LVar10,iVar11,LVar12,iVar13,LVar14,uVar15);
  uVar3 = (*pcVar1)();
  local_18.left = param_3;
  local_18.top = param_4;
  local_18.right = param_5;
  local_18.bottom = param_6;
  iVar2 = FUN_007c2511();
  uVar4 = *(ulong *)(iVar2 + 0x60);
  if ((uVar3 & 0x1000) == 0) {
    if ((uVar3 & 0x4000) == 0) {
      if ((uVar3 & 0x2000) != 0) {
        local_18.top = local_18.bottom;
        goto LAB_007f4f51;
      }
      if ((uVar3 & 0x8000) == 0) {
        return;
      }
      local_18.bottom = local_18.top;
    }
    else {
      local_18.right = local_18.left;
    }
    iVar2 = FUN_007c2511();
    uVar4 = *(ulong *)(iVar2 + 0x5c);
  }
  else {
    local_18.left = local_18.right;
  }
LAB_007f4f51:
  CDC::Draw3dRect(param_1,&local_18,uVar4,uVar4);
  return;
}




/* vtable slots: CMFCVisualManager[120] */
/* 007f4f70  FUN_007f4f70  86 bytes, 0 callers */

void FUN_007f4f70(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x60);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar2 + 100),uVar1);
  InflateRect((LPRECT)&stack0x00000008,-1,-1);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar2 + 0x5c),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[123] */
/* 007f4fc6  FUN_007f4fc6  159 bytes, 0 callers */

void FUN_007f4fc6(CDC *param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  CMFCButton *in_stack_00000018;
  
  iVar1 = CMFCButton::IsPressed(in_stack_00000018);
  if (iVar1 == 0) {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x60);
    iVar1 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar1 + 100),uVar3);
    InflateRect((LPRECT)&stack0x00000008,-1,-1);
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x58);
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x5c);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 100);
    iVar1 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar1 + 0x60),uVar3);
    InflateRect((LPRECT)&stack0x00000008,-1,-1);
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x5c);
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x58);
  }
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,uVar2,uVar3);
  return;
}




/* vtable slots: CMFCVisualManager[88] */
/* 007f50b9  OnDrawPropertySheetListItem  81 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::OnDrawPropertySheetListItem(class
   CDC *,class CMFCPropertySheet *,class CRect,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall CMFCVisualManager::OnDrawPropertySheetListItem(undefined4 param_1_00,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  ulong uVar2;
  int in_stack_0000001c;
  int in_stack_00000020;
  
  uVar2 = 0xffffffff;
  if (in_stack_00000020 != 0) {
    iVar1 = FUN_007c2511();
    hbr = (HBRUSH)0x0;
    if (iVar1 != -0xa0) {
      hbr = *(HBRUSH *)(iVar1 + 0xa4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x40);
  }
  if (in_stack_0000001c != 0) {
    DrawFocusRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManager[132], CMFCVisualManagerOffice2003[132], CMFCVisualManagerOfficeXP[132] */
/* 007f510a  FUN_007f510a  235 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f510a(CDC *param_1,int *param_2)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  CDrawingManager local_34 [8];
  CDC *local_2c;
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x7f5116;
  local_2c = param_1;
  pcVar1 = *(code **)(*param_2 + 0xd0);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  bVar2 = true;
  if (iVar3 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xd4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      local_28 = 0;
      goto LAB_007f515a;
    }
  }
  local_28 = 1;
LAB_007f515a:
  pcVar1 = *(code **)(*param_2 + 0xd8);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      bVar2 = false;
    }
  }
  local_24.left = param_2[0x1d];
  local_24.top = param_2[0x1e];
  local_24.right = param_2[0x1f];
  local_24.bottom = param_2[0x20];
  InflateRect(&local_24,-2,-2);
  CDrawingManager::CDrawingManager(local_34,local_2c);
  local_8 = 0;
  iVar3 = FUN_007c2511();
  if (local_28 == 0) {
    uVar5 = *(undefined4 *)(iVar3 + 0x58);
  }
  else {
    uVar5 = *(undefined4 *)(iVar3 + 0x60);
  }
  iVar3 = FUN_007c2511();
  if (bVar2) {
    uVar4 = *(undefined4 *)(iVar3 + 100);
  }
  else {
    uVar4 = *(undefined4 *)(iVar3 + 0x54);
  }
  FUN_00815451(&local_24,uVar4,uVar5);
  FUN_0081510b();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[153], CMFCVisualManagerOfficeXP[153] */
/* 007f5460  FUN_007f5460  6 bytes, 0 callers */

undefined4 FUN_007f5460(void)

{
  return 0xffffffff;
}




/* vtable slots: CMFCVisualManager[148], CMFCVisualManagerOffice2003[148], CMFCVisualManagerOfficeXP[148] */
/* 007f5466  FUN_007f5466  625 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f5466(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
                 int param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  code *pcVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  HICON__ *hIcon;
  int iVar5;
  int cxWidth;
  int iVar6;
  int iVar7;
  int iVar8;
  HDC hdc;
  int *piVar9;
  int *in_ECX;
  int local_14;
  
  pHVar3 = GetParent(*(HWND *)(param_2 + 0x20));
  pCVar4 = CWnd::FromHandle(pHVar3);
  iVar1 = *(int *)(param_2 + 0x308);
  FUN_00797acc();
  if ((*(byte *)(param_2 + 0x330) & 2) != 0) {
    hIcon = CGlobalUtils::GetWndIcon((CGlobalUtils *)&PTR_vftable_00a0095c,pCVar4);
    if (hIcon != (HICON__ *)0x0) {
      iVar5 = GetSystemMetrics(0x32);
      cxWidth = GetSystemMetrics(0x31);
      iVar6 = GetSystemMetrics(4);
      if (iVar6 < param_6 - param_4) {
        iVar6 = GetSystemMetrics(4);
      }
      else {
        iVar6 = param_6 - param_4;
      }
      iVar6 = iVar6 + param_3;
      iVar7 = ((iVar6 - param_3) - cxWidth) / 2;
      if (iVar7 < 0) {
        iVar7 = 0;
      }
      iVar8 = ((param_6 - param_4) - iVar5) / 2;
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      if (param_1 == (int *)0x0) {
        hdc = (HDC)0x0;
      }
      else {
        hdc = (HDC)param_1[1];
      }
      DrawIconEx(hdc,iVar7 + param_3,param_4 + iVar8,hIcon,cxWidth,iVar5,0,(HBRUSH)0x0,3);
      if (param_7 < iVar6) {
        param_7 = iVar6;
      }
    }
  }
  pcVar2 = *(code **)(*param_1 + 0x28);
  FUN_007c2511();
  guard_check_icall();
  iVar5 = (*pcVar2)();
  if (iVar5 != 0) {
    FUN_0079f0b8();
    CStringT<>();
    FUN_00792c64();
    piVar9 = (int *)FUN_00566800();
    iVar5 = *piVar9;
    if (iVar5 < param_9 - param_7) {
      param_7 = param_7 + ((param_9 - param_7) - iVar5) / 2;
    }
    if (iVar5 + param_7 < param_9) {
      param_9 = iVar5 + param_7;
    }
    if (param_7 < param_9) {
      if (iVar1 == 0) {
        pcVar2 = *(code **)(*param_1 + 0x30);
        guard_check_icall();
        (*pcVar2)();
        FUN_007c2378();
        pcVar2 = *(code **)(*param_1 + 0x30);
        guard_check_icall();
        (*pcVar2)();
      }
      else {
        pcVar2 = *(code **)(*in_ECX + 0x2cc);
        FUN_004054a0(local_14 + -0x10);
        guard_check_icall(param_1);
        (*pcVar2)();
      }
    }
    FUN_0079f0b8();
    pcVar2 = *(code **)(*param_1 + 0x28);
    guard_check_icall();
    (*pcVar2)();
    FUN_00406b10();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManager[152], CMFCVisualManagerOffice2003[152], CMFCVisualManagerOfficeXP[152] */
/* 007f56d8  FUN_007f56d8  210 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f56d8(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  int *piVar5;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  int *local_20;
  undefined4 local_1c;
  int local_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  pcVar1 = *(code **)(*in_ECX + 0x238);
  local_24 = param_2;
  piVar5 = param_2;
  local_20 = in_ECX;
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  iVar3 = param_2[0x29];
  if (iVar3 == 0xf020) {
    uVar4 = 3;
  }
  else if (iVar3 == 0xf030) {
    uVar4 = 6;
  }
  else if (iVar3 == 0xf060) {
    uVar4 = 5;
  }
  else {
    if (iVar3 != 0xf120) {
      return;
    }
    uVar4 = 4;
  }
  local_2c = 0;
  local_28 = 0;
  pcVar1 = *(code **)(*param_2 + 0xdc);
  guard_check_icall(param_1,piVar5);
  iVar3 = (*pcVar1)();
  uVar2 = local_1c;
  local_18 = param_2[0x1d];
  iStack_14 = param_2[0x1e];
  iStack_10 = param_2[0x1f];
  iStack_c = param_2[0x20];
  FUN_00814d1c(local_1c,uVar4,&local_18,iVar3 != 0,&local_2c);
  pcVar1 = *(code **)(*local_20 + 0x240);
  guard_check_icall(uVar2,local_24);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[133], CMFCVisualManagerOffice2003[133], CMFCVisualManagerOfficeXP[133] */
/* 007f57aa  FUN_007f57aa  317 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f57aa(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  HBRUSH hbr;
  int iVar3;
  undefined1 local_2c [8];
  CDrawingManager local_24 [8];
  undefined **local_1c [2];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x7f57b6;
  param_5 = param_5 + -2;
  param_6 = param_6 + -2;
  iVar2 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar2 != -0xd0) {
    hbr = *(HBRUSH *)(iVar2 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,hbr);
  iVar2 = *(int *)(param_2 + 0x104);
  iVar1 = *(int *)(param_2 + 0x10c);
  iVar3 = FUN_007c2511();
  FUN_0079df60(0,1,*(undefined4 *)(iVar3 + 0x58));
  local_8 = 0;
  iVar3 = FUN_0079efbc(local_1c);
  if (iVar3 != 0) {
    FUN_0079ec58(local_2c,param_3,param_4);
    CDC::LineTo(param_1,iVar2 + 1,param_4);
    FUN_0079ec58(local_2c,iVar1 + -2,param_4);
    CDC::LineTo(param_1,param_5,param_4);
    CDC::LineTo(param_1,param_5,param_6);
    CDC::LineTo(param_1,param_3,param_6);
    CDC::LineTo(param_1,param_3,param_4);
    FUN_0079efbc(iVar3);
    CDrawingManager::CDrawingManager(local_24,param_1);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00816e2b(param_3,param_4,param_5,param_6,2,100,0x4b,0,0,*(undefined4 *)(local_14 + 0xa8),1);
    FUN_0081510b();
    local_1c[0] = CPen::vftable;
    FUN_00416100();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManager[162], CMFCVisualManagerOfficeXP[162] */
/* 007f58e8  FUN_007f58e8  139 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007f58e8(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  HBRUSH local_20;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x284);
  guard_check_icall(*(undefined4 *)(param_2 + 0x1c4));
  iVar2 = (*pcVar1)();
  local_18.left = *(LONG *)(param_2 + 0x74);
  local_18.top = *(LONG *)(param_2 + 0x78);
  local_18.right = *(LONG *)(param_2 + 0x7c);
  local_18.bottom = *(LONG *)(param_2 + 0x80);
  if (iVar2 != -1) {
    FUN_0079de5e(iVar2);
    FillRect(*(HDC *)(param_1 + 4),&local_18,local_20);
    FUN_00416100();
  }
  iVar2 = FUN_007c2511();
  return *(undefined4 *)(iVar2 + 0x68);
}




/* vtable slots: CMFCVisualManager[134], CMFCVisualManagerOfficeXP[134] */
/* 007f5a68  FUN_007f5a68  902 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f5a68(CDC *param_1,int *param_2,int param_3)

{
  code *pcVar1;
  int *piVar2;
  CDC *pCVar3;
  int iVar4;
  undefined4 uVar5;
  HRGN pHVar6;
  HBRUSH hbr;
  int iVar7;
  undefined1 local_a4 [8];
  undefined **local_9c;
  HBRUSH local_98;
  undefined **local_94 [2];
  int *local_8c;
  undefined **local_88 [2];
  undefined **local_80;
  undefined4 local_7c;
  int *local_78;
  int local_74;
  int local_70;
  CDC *local_6c;
  int local_68;
  RECT local_64;
  POINT local_54;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_8 = 0x7f5a77;
  local_6c = param_1;
  local_8c = param_2;
  local_70 = *(int *)(param_2[0x22] + 0x53c);
  if (param_3 == 0) {
LAB_007f5ac8:
    local_74 = 0;
  }
  else {
    if ((*(byte *)(local_70 + 0x330) & 1) != 0) {
      pcVar1 = *(code **)(*param_2 + 0x1c4);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) goto LAB_007f5ac8;
    }
    local_74 = 1;
  }
  pcVar1 = *(code **)(*param_2 + 0xd4);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if ((iVar4 == 0) || ((*(byte *)(local_70 + 0x330) & 1) == 0)) {
    local_68 = 0;
  }
  else {
    local_68 = 1;
  }
  pcVar1 = *(code **)(*param_2 + 0xd0);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if ((iVar4 != 0) || (local_68 != 0)) {
    pcVar1 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      local_68 = 1;
      goto LAB_007f5b3f;
    }
  }
  local_68 = 0;
LAB_007f5b3f:
  iVar4 = FUN_007c2511();
  FUN_0079df60(0,1,*(undefined4 *)(iVar4 + 0x58));
  local_8 = 0;
  local_70 = FUN_0079efbc(local_88);
  if (local_70 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_64.left = param_2[0x1d];
  local_64.right = param_2[0x1f];
  local_64.bottom = param_2[0x20];
  local_64.top = param_2[0x1e] + 3;
  iVar4 = *(int *)(*(int *)(param_2[0x22] + 0x53c) + 0x2cc);
  if (0 < iVar4) {
    iVar7 = 100 - iVar4 / 2;
    iVar4 = 10;
    if (9 < iVar7) {
      iVar4 = iVar7;
    }
    iVar7 = FUN_007c2511(iVar4);
    uVar5 = FUN_008188f6(*(undefined4 *)(iVar7 + 0x54),iVar4);
    FUN_0079df60(0,1,uVar5);
    pCVar3 = local_6c;
    local_8._0_1_ = 1;
    FUN_0079efbc(local_94);
    FUN_0079ec58(local_a4,local_64.right + -1,local_64.top);
    CDC::LineTo(pCVar3,local_64.right + -1,local_64.bottom);
    local_8 = (uint)local_8._1_3_ << 8;
    local_94[0] = CPen::vftable;
    FUN_00416100();
  }
  if ((local_74 == 0) && (local_68 == 0)) {
    FUN_0079efbc(local_70);
    FUN_007c2511();
  }
  else {
    local_40 = local_64.top + 2;
    local_1c = local_64.right + -2;
    local_7c = 0;
    local_4c = local_64.left + 1;
    local_54.x = local_64.left;
    local_48 = local_64.bottom + -1;
    local_3c = local_64.left + 3;
    local_34 = local_64.right + -5;
    local_2c = local_64.right + -3;
    local_54.y = local_64.bottom;
    local_38 = local_64.top;
    local_30 = local_64.top;
    local_18 = local_64.bottom;
    local_80 = CRgn::vftable;
    local_8 = CONCAT31(local_8._1_3_,2);
    local_64.right = local_1c;
    local_44 = local_4c;
    local_28 = local_40;
    local_24 = local_2c;
    local_20 = local_48;
    pHVar6 = CreatePolygonRgn(&local_54,8,2);
    Attach(pHVar6);
    pCVar3 = local_6c;
    if (local_74 != 0) {
      FUN_0079eeb5(&local_80);
      piVar2 = local_8c;
      iVar4 = FUN_00863d92();
      if (iVar4 == 0) {
        pcVar1 = *(code **)(*local_78 + 0x284);
        guard_check_icall(*(undefined4 *)(piVar2[0x22] + 0x19c));
        iVar4 = (*pcVar1)();
      }
      else {
        iVar4 = FUN_007c2511();
        iVar4 = *(int *)(iVar4 + 0x5c);
      }
      if (iVar4 == -1) {
        iVar4 = FUN_007c2511();
        if (local_68 == 0) {
          iVar4 = iVar4 + 0xd0;
        }
        else {
          iVar4 = iVar4 + 200;
        }
        hbr = (HBRUSH)0x0;
        if (iVar4 != 0) {
          hbr = *(HBRUSH *)(iVar4 + 4);
        }
        FillRect(*(HDC *)(pCVar3 + 4),&local_64,hbr);
      }
      else {
        FUN_0079de5e(iVar4);
        FillRect(*(HDC *)(pCVar3 + 4),&local_64,local_98);
        local_9c = CBrush::vftable;
        FUN_00416100();
      }
      FUN_0079eeb5(0);
    }
    Polyline(*(HDC *)(pCVar3 + 4),&local_54,8);
    FUN_0079efbc(local_70);
    FUN_007c2511();
    local_80 = CRgn::vftable;
    FUN_00416100();
  }
  local_88[0] = CPen::vftable;
  FUN_00416100();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[174], CMFCVisualManagerOffice2003[174], CMFCVisualManagerOfficeXP[174] */
/* 007f5def  FUN_007f5def  93 bytes, 1 callers */

void FUN_007f5def(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  OffsetRect((LPRECT)&stack0x0000000c,1,1);
  local_c = 0;
  local_8 = 0;
  FUN_00814d1c(param_1,2,&stack0x0000000c,3,&local_c);
  OffsetRect((LPRECT)&stack0x0000000c,-1,-1);
  local_c = 0;
  local_8 = 0;
  FUN_00814d1c(param_1,2,&stack0x0000000c,0,&local_c);
  return;
}




/* vtable slots: CMFCVisualManager[139], CMFCVisualManagerOffice2003[139], CMFCVisualManagerOfficeXP[139] */
/* 007f600a  FUN_007f600a  107 bytes, 1 callers */

void FUN_007f600a(undefined4 param_1,int param_2)

{
  int *in_ECX;
  code *pcVar1;
  
  if (*(int *)(param_2 + 0xc4) == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x230);
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x238);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x230);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x240);
  }
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[140], CMFCVisualManagerOffice2003[140], CMFCVisualManagerOffice2007[140], CMFCVisualManagerOfficeXP[140] */
/* 007f6075  FUN_007f6075  173 bytes, 0 callers */

void FUN_007f6075(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined1 local_c [8];
  
  if (param_2[0x31] == 0) {
    iVar1 = param_2[0x1d];
    iVar2 = param_2[0x1e];
    iVar3 = param_2[0x1f];
    pcVar4 = *(code **)(*param_2 + 0x114);
    guard_check_icall(local_c,1);
    iVar5 = (*pcVar4)();
    pcVar4 = *(code **)(*param_2 + 0x120);
    guard_check_icall(param_1,1,iVar1,iVar2 + 10,iVar3,*(int *)(iVar5 + 4) + iVar2 + 10);
    (*pcVar4)();
    FUN_00866368(local_c,param_1,0);
  }
  else {
    pcVar4 = *(code **)(*param_2 + 0x120);
    guard_check_icall(param_1,1,param_2[0x1d],param_2[0x1e],param_2[0x1f],param_2[0x20]);
    (*pcVar4)();
  }
  return;
}




/* vtable slots: CMFCVisualManager[141], CMFCVisualManagerOffice2003[141], CMFCVisualManagerOfficeXP[141] */
/* 007f6122  FUN_007f6122  193 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f6122(CDC *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6)

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  undefined4 local_20;
  undefined4 local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  param_3 = (param_4 - param_6) + param_5;
  InflateRect((LPRECT)&param_3,-1,-1);
  iVar2 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar2 != -0xd0) {
    hbr = *(HBRUSH *)(iVar2 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,hbr);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&param_3,*(ulong *)(iVar2 + 0x58),uVar1);
  local_18.left = param_3;
  local_18.top = param_4;
  local_18.right = param_5;
  local_18.bottom = param_6;
  OffsetRect(&local_18,0,1);
  local_20 = 0;
  local_1c = 0;
  FUN_00814d1c(param_1,0,&local_18,3,&local_20);
  local_20 = 0;
  local_1c = 0;
  FUN_00814d1c(param_1,0,&param_3,0,&local_20);
  return;
}




/* vtable slots: CMFCVisualManager[160], CMFCVisualManagerOffice2003[160], CMFCVisualManagerOfficeXP[160] */
/* 007f61e3  FUN_007f61e3  43 bytes, 1 callers */

void FUN_007f61e3(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x58),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[159], CMFCVisualManagerOffice2003[159], CMFCVisualManagerOfficeXP[159] */
/* 007f620e  FUN_007f620e  65 bytes, 1 callers */

void FUN_007f620e(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x238);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x240);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[173], CMFCVisualManagerOffice2003[173], CMFCVisualManagerOfficeXP[173] */
/* 007f624f  FUN_007f624f  343 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f624f(CDC *param_1,int *param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6,
                 int param_7)

{
  code *pcVar1;
  CDC *this;
  HBRUSH hbr;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  int in_ECX;
  HDC pHVar5;
  DWORD local_34;
  CDC *local_30;
  code *local_2c;
  DWORD local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_30 = param_1;
  pHVar5 = (HDC)0x0;
  local_8 = 0;
  local_2c = (code *)in_ECX;
  local_34 = GetSysColor(0x17);
  local_28 = local_34;
  if (*(int *)(in_ECX + 0x44) == 0) {
    hbr = GetSysColorBrush(0x18);
    if (param_1 != (CDC *)0x0) {
      pHVar5 = *(HDC *)(param_1 + 4);
    }
    FillRect(pHVar5,(RECT *)&param_3,hbr);
  }
  else {
    local_24.left = param_3;
    local_24.top = param_4;
    local_24.right = param_5;
    local_24.bottom = param_6;
    InflateRect(&local_24,2,2);
    if (local_30 == (CDC *)0x0) {
      pHVar5 = (HDC)0x0;
    }
    else {
      pHVar5 = *(HDC *)(local_30 + 4);
    }
    DrawThemeBackground(*(HTHEME *)((int)local_2c + 0x44),pHVar5,1,0,&local_24,(LPCRECT)0x0);
    GetThemeColor(*(HTHEME *)((int)local_2c + 0x44),1,0,0xedb,&local_34);
    GetThemeColor(*(HTHEME *)((int)local_2c + 0x44),1,0,0xedc,&local_28);
  }
  FUN_0044ff70();
  this = local_30;
  local_2c = *(code **)(*(int *)local_30 + 0x30);
  pcVar1 = *(code **)(*param_2 + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  DVar3 = local_34;
  if (iVar2 != 0) {
    iVar2 = FUN_007c2511();
    DVar3 = *(DWORD *)(iVar2 + 0x38);
  }
  pcVar1 = local_2c;
  guard_check_icall(DVar3);
  uVar4 = (*pcVar1)();
  iVar2 = *(int *)this;
  guard_check_icall(param_7,*(undefined4 *)(param_7 + -0xc),&param_3,0x25);
  (**(code **)(iVar2 + 0x68))();
  pcVar1 = *(code **)(*(int *)this + 0x30);
  guard_check_icall(uVar4);
  (*pcVar1)();
  CDC::Draw3dRect(this,(tagRECT *)&param_3,local_28,local_28);
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[138], CMFCVisualManagerOffice2003[138], CMFCVisualManagerOfficeXP[138] */
/* 007f63a9  FUN_007f63a9  252 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f63a9(undefined4 param_1,int *param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uVar4;
  int *piVar5;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x238);
  uVar3 = param_1;
  piVar5 = param_2;
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  uVar4 = DAT_00a12574;
  if (*(int *)(param_3 + 0x68) == 0) {
    uVar4 = DAT_00a12584;
  }
  local_1c = 0;
  pcVar1 = *(code **)(*param_2 + 0xdc);
  guard_check_icall(uVar3,piVar5);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xd0);
    guard_check_icall(uVar3,piVar5);
    iVar2 = (*pcVar1)();
    uVar3 = local_1c;
    if (iVar2 == 0) {
      if ((((byte)uVar4 < 0xc1) || ((byte)((uint)uVar4 >> 8) < 0xc1)) ||
         ((byte)((uint)uVar4 >> 0x10) < 0xc1)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 3;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = param_2[0x1d];
  iStack_14 = param_2[0x1e];
  iStack_10 = param_2[0x1f];
  iStack_c = param_2[0x20];
  FUN_00814d1c(param_1,0x23,&local_18,uVar3,&local_20);
  pcVar1 = *(code **)(*in_ECX + 0x240);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[147], CMFCVisualManagerOffice2003[147], CMFCVisualManagerOfficeXP[147] */
/* 007f64a5  FUN_007f64a5  39 bytes, 1 callers */

void FUN_007f64a5(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x240);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[155], CMFCVisualManagerOffice2003[155], CMFCVisualManagerOfficeXP[155] */
/* 007f64cc  FUN_007f64cc  86 bytes, 1 callers */

void FUN_007f64cc(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x58),uVar1);
  InflateRect((LPRECT)&stack0x0000000c,1,1);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x5c);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x5c),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[145] */
/* 007f6522  FUN_007f6522  72 bytes, 0 callers */

void FUN_007f6522(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  
  iVar2 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar2 != -0x98) {
    hbr = *(HBRUSH *)(iVar2 + 0x9c);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x24);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x20),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[136], CMFCVisualManagerOffice2003[136], CMFCVisualManagerOfficeXP[136] */
/* 007f656a  FUN_007f656a  265 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_007f656a(CDC *param_1,int param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6)

{
  code *pcVar1;
  ulong uVar2;
  int iVar3;
  HBRUSH hbr;
  CDC *this;
  CDrawingManager local_20 [8];
  undefined4 local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x7f6576;
  local_14 = param_1;
  iVar3 = FUN_007c2511();
  local_18 = *(undefined4 *)(iVar3 + 0x68);
  iVar3 = FUN_0086c441();
  if (iVar3 != 0) {
    pcVar1 = *(code **)(*(int *)(param_2 + 0x2e0) + 0xd4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    param_1 = local_14;
    if (iVar3 != 0) {
      iVar3 = FUN_007c2511();
      this = local_14;
      hbr = (HBRUSH)0x0;
      if (iVar3 != -0xa0) {
        hbr = *(HBRUSH *)(iVar3 + 0xa4);
      }
      FillRect(*(HDC *)(local_14 + 4),(RECT *)&param_3,hbr);
      iVar3 = FUN_007c2511();
      local_18 = *(undefined4 *)(iVar3 + 0x40);
      goto LAB_007f6620;
    }
  }
  this = local_14;
  if (*(int *)(param_2 + 0x68) != 0) {
    CDrawingManager::CDrawingManager(local_20,param_1);
    local_8 = 0;
    FUN_00818045(param_3,param_4,param_5,param_6,0xffffffff,0xffffffff,0,0xffffffff);
    local_8 = 0xffffffff;
    FUN_0081510b();
    this = local_14;
  }
LAB_007f6620:
  iVar3 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar3 + 0x5c);
  iVar3 = FUN_007c2511();
  CDC::Draw3dRect(this,(tagRECT *)&param_3,*(ulong *)(iVar3 + 0x5c),uVar2);
  OffsetRect((LPRECT)&param_3,-1,-1);
  iVar3 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar3 + 0x58);
  iVar3 = FUN_007c2511();
  CDC::Draw3dRect(this,(tagRECT *)&param_3,*(ulong *)(iVar3 + 0x58),uVar2);
  return local_18;
}




/* vtable slots: CMFCVisualManager[137], CMFCVisualManagerOffice2003[137], CMFCVisualManagerOfficeXP[137] */
/* 007f6673  FUN_007f6673  259 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f6673(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  HBRUSH local_18;
  int local_14;
  
  pcVar1 = *(code **)(*param_1 + 0x30);
  if (*(int *)(param_2 + 0x68) == 0) {
    iVar2 = FUN_007c2511();
    uVar3 = *(undefined4 *)(iVar2 + 0x84);
  }
  else {
    iVar2 = FUN_007c2511();
    uVar3 = *(undefined4 *)(iVar2 + 0x74);
  }
  guard_check_icall(uVar3);
  uVar3 = (*pcVar1)();
  InflateRect((LPRECT)&param_3,-1,-1);
  param_5 = param_5 + -2;
  if (*(int *)(param_2 + 0x68) == 0) {
    iVar2 = FUN_007c2511();
    uVar4 = *(undefined4 *)(iVar2 + 0x80);
  }
  else {
    iVar2 = FUN_007c2511();
    uVar4 = *(undefined4 *)(iVar2 + 0x7c);
  }
  FUN_0079de5e(uVar4);
  FillRect((HDC)param_1[1],(RECT *)&param_3,local_18);
  CStringT<>(*(undefined4 *)(param_2 + 0xfc));
  if (*(int *)(param_2 + 0x1b8) != 0) {
    param_5 = *(int *)(param_2 + 0x188);
  }
  iVar2 = *param_1;
  guard_check_icall(local_14,*(undefined4 *)(local_14 + -0xc),&param_3,0x8825);
  (**(code **)(iVar2 + 0x68))();
  pcVar1 = *(code **)(*param_1 + 0x30);
  guard_check_icall(uVar3);
  (*pcVar1)();
  FUN_00406b10();
  FUN_00416100();
  return;
}




/* vtable slots: CMFCVisualManager[168], CMFCVisualManagerOfficeXP[168] */
/* 007f6776  FUN_007f6776  185 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f6776(CDC *param_1)

{
  ulong uVar1;
  BOOL BVar2;
  int iVar3;
  HBRUSH hbr;
  undefined4 uVar4;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7f6782;
  if (DAT_00a12704 == 0) {
    BVar2 = IsRectEmpty((RECT *)&stack0x0000001c);
    if (BVar2 == 0) {
      iVar3 = FUN_007c2511();
      hbr = (HBRUSH)0x0;
      if (iVar3 != -0xa0) {
        hbr = *(HBRUSH *)(iVar3 + 0xa4);
      }
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000001c,hbr);
    }
    iVar3 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar3 + 0x5c);
    iVar3 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar3 + 0x58),uVar1);
  }
  else {
    CDrawingManager::CDrawingManager(local_18,param_1);
    local_8 = 0;
    BVar2 = IsRectEmpty((RECT *)&stack0x0000001c);
    if (BVar2 == 0) {
      uVar4 = 0xffffffff;
      iVar3 = FUN_007c2511(0xffffffff);
      FUN_00816b6a(&stack0x0000001c,*(undefined4 *)(iVar3 + 0x3c),uVar4);
    }
    iVar3 = FUN_007c2511();
    FUN_00816b6a(&stack0x0000000c,0xffffffff,*(undefined4 *)(iVar3 + 0x58));
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManager[157] */
/* 007f6899  FUN_007f6899  116 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f6899(CDC *param_1,undefined4 param_2,int param_3,LONG param_4,LONG param_5,LONG param_6
                 )

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar2 != -0x98) {
    hbr = *(HBRUSH *)(iVar2 + 0x9c);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,hbr);
  local_18.right = param_3 + 2;
  local_18.left = param_3;
  local_18.top = param_4;
  local_18.bottom = param_6;
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x24);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar2 + 0x20),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[166], CMFCVisualManagerOfficeXP[166] */
/* 007f690d  FUN_007f690d  120 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f690d(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7f6919;
  InflateRect((LPRECT)&stack0x0000000c,0,1);
  if (DAT_00a12704 == 0) {
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x5c);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x58),uVar1);
  }
  else {
    CDrawingManager::CDrawingManager(local_18,param_1);
    local_8 = 0;
    iVar2 = FUN_007c2511();
    FUN_00816b6a(&stack0x0000000c,0xffffffff,*(undefined4 *)(iVar2 + 0x58));
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManager[167], CMFCVisualManagerOfficeXP[167] */
/* 007f6985  FUN_007f6985  352 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f6985(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  code *pcVar1;
  int *in_ECX;
  undefined **local_64 [2];
  undefined **local_5c [2];
  undefined4 local_54;
  CDC *local_50;
  CDrawingManager local_4c [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  POINT local_3c;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x7f6991;
  local_50 = param_1;
  pcVar1 = *(code **)(*in_ECX + 0x290);
  guard_check_icall(param_2,param_7,param_8,param_9,&local_40,&local_44);
  (*pcVar1)();
  InflateRect((LPRECT)&param_3,-1,-2);
  param_4 = (param_6 + param_4) / 2 - (param_5 - param_3);
  param_6 = param_4 + (param_5 - param_3) * 2;
  if (DAT_00a12704 == 0) {
    FUN_0079df60(0,1,local_40);
    local_8 = 1;
    local_54 = FUN_0079efbc(local_64);
    FUN_0079de5e(local_44);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_48 = FUN_0079efbc(local_5c);
    local_3c.x = param_3;
    local_34 = param_3;
    local_2c = (param_5 - param_3) / 2;
    local_30 = param_6 - local_2c;
    local_3c.y = param_4;
    local_2c = local_2c + param_3;
    local_28 = param_6;
    local_24 = param_5;
    local_1c = param_5;
    local_18 = param_4;
    local_20 = local_30;
    Polygon(*(HDC *)(local_50 + 4),&local_3c,5);
    FUN_0079efbc(local_54);
    FUN_0079efbc(local_48);
    local_5c[0] = CBrush::vftable;
    FUN_00416100();
    local_64[0] = CPen::vftable;
    FUN_00416100();
  }
  else {
    CDrawingManager::CDrawingManager(local_4c,param_1);
    local_8 = 0;
    FUN_00816b6a(&param_3,local_44,local_40);
    FUN_0081510b();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[165], CMFCVisualManagerOfficeXP[165] */
/* 007f6ae5  FUN_007f6ae5  370 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f6ae5(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10)

{
  code *pcVar1;
  CDC *this;
  int *in_ECX;
  int iVar2;
  undefined1 local_58 [8];
  undefined **local_50 [2];
  int local_48;
  undefined4 local_44;
  CDrawingManager local_40 [8];
  int local_38;
  int local_34;
  int local_30;
  CDC *local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x7f6af1;
  local_2c = param_1;
  pcVar1 = *(code **)(*in_ECX + 0x290);
  guard_check_icall(param_2,param_8,param_9,param_10,&local_28,&local_44);
  (*pcVar1)();
  local_30 = (param_4 + param_6) / 2;
  local_20 = local_30 + -7;
  iVar2 = (param_5 + param_3) / 2;
  local_18 = local_30 + 8;
  local_24 = iVar2 + -7;
  local_1c = iVar2 + 8;
  CDrawingManager::CDrawingManager(local_40,local_2c);
  local_8 = 0;
  FUN_00815451(&local_24,local_44,local_28);
  this = local_2c;
  local_48 = iVar2 + 4;
  local_34 = local_30 + -3;
  local_38 = local_30 + 4;
  if (DAT_00a12704 == 0) {
    FUN_0079df60(0,1,local_28);
    local_8 = CONCAT31(local_8._1_3_,1);
    local_2c = (CDC *)FUN_0079efbc(local_50);
    FUN_0079ec58(local_58,iVar2 + -3,local_30);
    CDC::LineTo(this,local_48,local_30);
    if (param_7 == 0) {
      FUN_0079ec58(local_58,iVar2,local_34);
      CDC::LineTo(this,iVar2,local_38);
    }
    FUN_0079efbc(local_2c);
    local_50[0] = CPen::vftable;
    FUN_00416100();
  }
  else {
    FUN_008168e5(iVar2 + -3,local_30,iVar2 + 4,local_30,local_28);
    if (param_7 == 0) {
      FUN_008168e5(iVar2,local_34,iVar2,local_38,local_28);
    }
  }
  FUN_0081510b();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[163] */
/* 007f6c57  FUN_007f6c57  204 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007f6c57(CDC *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar6 = param_3[0x1d];
  iVar1 = param_3[0x1e];
  iVar2 = param_3[0x1f];
  iVar3 = param_3[0x20];
  pcVar4 = *(code **)(*param_3 + 0xd0);
  guard_check_icall();
  iVar5 = (*pcVar4)();
  if (iVar5 != 0) {
    local_18.left = iVar6;
    local_18.top = iVar1;
    local_18.right = iVar2;
    local_18.bottom = iVar3;
    InflateRect(&local_18,-1,-1);
    pcVar4 = *(code **)(*param_3 + 0xd8);
    guard_check_icall();
    iVar6 = (*pcVar4)();
    if (iVar6 == 0) {
      iVar6 = FUN_007c2511();
      uVar8 = *(ulong *)(iVar6 + 0x58);
    }
    else {
      iVar6 = FUN_007c2511();
      uVar8 = *(ulong *)(iVar6 + 0x5c);
    }
    pcVar4 = *(code **)(*param_3 + 0xd8);
    guard_check_icall();
    iVar6 = (*pcVar4)();
    if (iVar6 == 0) {
      iVar6 = FUN_007c2511();
      uVar7 = *(ulong *)(iVar6 + 0x5c);
    }
    else {
      iVar6 = FUN_007c2511();
      uVar7 = *(ulong *)(iVar6 + 0x58);
    }
    CDC::Draw3dRect(param_1,&local_18,uVar7,uVar8);
  }
  return 0xffffffff;
}




/* vtable slots: CMFCVisualManager[131], CMFCVisualManagerOffice2003[131], CMFCVisualManagerOfficeXP[131] */
/* 007f6d23  FUN_007f6d23  126 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007f6d23(CDC *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined1 local_20 [8];
  undefined **local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x7f6d2f;
  iVar1 = FUN_007c2511();
  FUN_0079df60(0,1,*(undefined4 *)(iVar1 + 0x58));
  local_8 = 0;
  iVar1 = FUN_0079efbc(local_18);
  if (iVar1 != 0) {
    FUN_0079ec58(local_20,param_3,param_4);
    CDC::LineTo(param_1,param_5,param_4);
    FUN_0079efbc(iVar1);
    local_18[0] = CPen::vftable;
    FUN_00416100();
    return 0xffffffff;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManager[18] */
/* 007f6e6e  FUN_007f6e6e  181 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f6e6e(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = param_3;
  local_18.top = param_4;
  local_18.right = param_5;
  local_18.bottom = param_6;
  if (param_7 == 0) {
    iVar1 = (param_6 - param_4) / 2;
    local_18.top = param_4 + -1 + iVar1;
    local_18.bottom = iVar1 + 1 + param_4;
  }
  else {
    iVar1 = (param_5 - param_3) / 2;
    local_18.left = param_3 + -1 + iVar1;
    local_18.right = iVar1 + 1 + param_3;
  }
  if (*(int *)(param_2 + 0x8c) == 0) {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x5c);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x24);
  }
  if (*(int *)(param_2 + 0x8c) == 0) {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x58);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x20);
  }
  CDC::Draw3dRect(param_1,&local_18,uVar2,uVar3);
  return;
}




/* vtable slots: CMFCVisualManager[191], CMFCVisualManagerOfficeXP[191] */
/* 007f6f23  FUN_007f6f23  37 bytes, 1 callers */

void FUN_007f6f23(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = 0;
  FUN_00814d1c(param_1,8,&stack0x00000008,0,&local_c);
  return;
}




/* vtable slots: CMFCVisualManager[101] */
/* 007f714b  FUN_007f714b  86 bytes, 0 callers */

void FUN_007f714b(CDC *param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x5c);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x58),uVar1);
  InflateRect((LPRECT)&stack0x0000000c,-1,-1);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x54);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(iVar2 + 0x54),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[102] */
/* 007f71a1  FUN_007f71a1  38 bytes, 0 callers */

void FUN_007f71a1(CDC *param_1,undefined4 param_2,tagRECT *param_3)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x58);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,param_3,*(ulong *)(iVar2 + 0x54),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[23] */
/* 007f71c7  OnDrawStatusBarPaneBorder  74 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnDrawStatusBarPaneBorder(class CDC *,class
   CMFCStatusBar *,class CRect,unsigned int,unsigned int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnDrawStatusBarPaneBorder(undefined4 param_1_00,CDC *param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  uint in_stack_00000020;
  
  if ((in_stack_00000020 & 0x100) == 0) {
    iVar1 = FUN_007c2511();
    if ((in_stack_00000020 & 0x200) == 0) {
      uVar3 = *(ulong *)(iVar1 + 0x5c);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x58);
    }
    else {
      uVar3 = *(ulong *)(iVar1 + 0x58);
      iVar1 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar1 + 0x5c);
    }
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,uVar2,uVar3);
  }
  return;
}




/* vtable slots: CMFCVisualManager[25], CMFCVisualManagerOfficeXP[25] */
/* 007f7211  FUN_007f7211  455 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f7211(CDC *param_1,undefined4 param_2,int param_3,LONG param_4,int param_5,LONG param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11,int param_12)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HRGN pHVar5;
  HBRUSH local_40;
  CDrawingManager local_38 [4];
  int local_34;
  undefined **local_30;
  undefined4 local_2c;
  int local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  iVar3 = param_8;
  uStack_4 = 0x34;
  local_8 = 0x7f721d;
  local_28 = param_9;
  if (param_7 != 0) {
    local_24.left = param_3;
    local_24.top = param_4;
    local_24.bottom = param_6;
    local_24.right = ((param_5 - param_3) * param_8) / param_7 + param_3;
    if (param_10 == -1) {
      FUN_0079de5e(param_9);
      FillRect(*(HDC *)(param_1 + 4),&local_24,local_40);
      FUN_00416100();
    }
    else {
      CDrawingManager::CDrawingManager(local_38,param_1);
      local_8 = 0;
      FUN_00817861(local_24.left,local_24.top,local_24.right,local_24.bottom,local_28,param_10,0,0,0
                  );
      local_8 = 0xffffffff;
      FUN_0081510b();
      iVar3 = param_8;
    }
    if (param_12 != 0) {
      CStringT<>();
      local_8 = 1;
      FUN_004059f0(&local_28,L"%d%%",(iVar3 * 100) / param_7);
      pcVar1 = *(code **)(*(int *)param_1 + 0x30);
      iVar3 = FUN_007c2511();
      guard_check_icall(*(undefined4 *)(iVar3 + 0x68));
      uVar4 = (*pcVar1)();
      iVar2 = local_28;
      pcVar1 = *(code **)(*(int *)param_1 + 0x68);
      local_34 = local_28 + -0x10;
      guard_check_icall(local_28,*(undefined4 *)(local_28 + -0xc),&param_3,0x825);
      (*pcVar1)();
      local_2c = 0;
      local_30 = CRgn::vftable;
      local_8 = CONCAT31(local_8._1_3_,2);
      pHVar5 = CreateRectRgnIndirect(&local_24);
      Attach(pHVar5);
      FUN_0079eeb5(&local_30);
      pcVar1 = *(code **)(*(int *)param_1 + 0x30);
      iVar3 = param_11;
      if (param_11 == -1) {
        iVar3 = FUN_007c2511();
        iVar3 = *(int *)(iVar3 + 0x40);
      }
      guard_check_icall(iVar3);
      (*pcVar1)();
      iVar3 = *(int *)param_1;
      guard_check_icall(iVar2,*(undefined4 *)(iVar2 + -0xc),&param_3,0x825);
      (**(code **)(iVar3 + 0x68))();
      FUN_0079eeb5(0);
      pcVar1 = *(code **)(*(int *)param_1 + 0x30);
      guard_check_icall(uVar4);
      (*pcVar1)();
      local_30 = CRgn::vftable;
      FUN_00416100();
      FUN_00406b10();
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[26], CMFCVisualManagerOfficeXP[26] */
/* 007f73d8  FUN_007f73d8  222 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007f73d8(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_stack_00000014;
  int in_stack_00000018;
  LPCWSTR local_18;
  
  pcVar1 = *(code **)(*param_1 + 0x28);
  iVar2 = FUN_007c2511();
  guard_check_icall(iVar2 + 0x164);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    CStringT<>(&DAT_00970a14);
    uVar3 = FUN_0079f228(10);
    pcVar1 = *(code **)(*param_1 + 0x30);
    iVar4 = FUN_007c2511();
    guard_check_icall(*(undefined4 *)(iVar4 + 0x58));
    uVar5 = (*pcVar1)();
    ExtTextOutW((HDC)param_1[1],in_stack_00000014,in_stack_00000018,4,(RECT *)&stack0x0000000c,
                local_18,*(UINT *)(local_18 + -6),(INT *)0x0);
    pcVar1 = *(code **)(*param_1 + 0x28);
    guard_check_icall(iVar2);
    (*pcVar1)();
    pcVar1 = *(code **)(*param_1 + 0x30);
    guard_check_icall(uVar5);
    (*pcVar1)();
    FUN_0079f228(uVar3);
    FUN_00406b10();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManager[61] */
/* 007f74b7  FUN_007f74b7  5148 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f74b7(CDC *param_1,undefined **param_2,undefined **param_3,undefined **param_4,
                 undefined **param_5,int param_6,int param_7,int *param_8)

{
  undefined *puVar1;
  CDC *pCVar2;
  int iVar3;
  undefined4 uVar4;
  undefined ***pppuVar5;
  undefined **ppuVar6;
  HBRUSH hbr;
  int iVar7;
  HRGN pHVar8;
  code *pcVar9;
  LONG *pLVar10;
  code *pcVar11;
  undefined **ppuVar12;
  int *piVar13;
  RECT *pRVar14;
  HBRUSH local_128;
  undefined **local_124;
  undefined4 local_120;
  undefined **local_11c [2];
  undefined **local_114;
  undefined **local_110;
  undefined **local_10c;
  undefined **local_108;
  undefined4 local_104;
  undefined **local_100;
  undefined **local_fc;
  undefined **local_f8;
  POINT *local_f4;
  undefined1 local_f0 [4];
  code *local_ec;
  undefined **local_e8;
  undefined **local_e4;
  code *local_e0;
  CDC *local_dc;
  uint local_d8;
  int *local_d4;
  code *local_d0;
  undefined **local_cc;
  int *local_c8;
  RECT local_c4;
  tagRECT local_b4;
  int local_a4;
  undefined **local_a0;
  undefined **local_9c;
  undefined **local_98;
  int local_94;
  undefined **local_90;
  code *local_8c;
  undefined **local_88;
  tagRECT local_84;
  POINT local_74;
  undefined **local_6c;
  undefined **local_68;
  code *local_64;
  undefined **local_60;
  code *local_5c;
  int local_58;
  code *local_54;
  undefined **local_50;
  code *local_4c;
  undefined **local_48;
  undefined **local_44;
  int local_40;
  undefined **local_3c;
  undefined **local_38;
  POINT local_34;
  undefined **local_2c;
  undefined **local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x11c;
  local_8 = 0x7f74c6;
  local_c8 = param_8;
  local_dc = param_1;
  pcVar11 = *(code **)(*param_8 + 0x1dc);
  guard_check_icall(param_6);
  local_e8 = (undefined **)(*pcVar11)();
  local_c4.left = 0;
  local_c4.top = 0;
  pcVar11 = *(code **)(*(int *)param_1 + 0x50);
  local_c4.right = 0;
  local_c4.bottom = 0;
  pRVar14 = &local_c4;
  guard_check_icall(pRVar14);
  (*pcVar11)();
  pcVar11 = *(code **)(*local_c8 + 0x280);
  guard_check_icall();
  iVar3 = (*pcVar11)();
  if (iVar3 == 0) {
    pcVar11 = *(code **)(*local_c8 + 0x290);
    guard_check_icall(pRVar14);
    iVar3 = (*pcVar11)();
    if (iVar3 == 0) {
      local_100 = CRgn::vftable;
      local_fc = (undefined **)0x0;
      local_a4 = 0;
      local_a0 = (undefined **)0x0;
      local_9c = (undefined **)0x0;
      local_98 = (undefined **)0x0;
      local_8 = 6;
      pcVar11 = *(code **)(*local_c8 + 0x180);
      piVar13 = &local_a4;
      guard_check_icall(piVar13);
      (*pcVar11)();
      local_cc = (undefined **)0x0;
      pcVar11 = *(code **)(*local_c8 + 0x288);
      guard_check_icall();
      iVar3 = (*pcVar11)();
      if (iVar3 == 0) {
        pcVar11 = *(code **)(*local_c8 + 0x28c);
        guard_check_icall(piVar13);
        iVar3 = (*pcVar11)();
        if (iVar3 != 0) goto LAB_007f7d17;
        local_ec = (code *)0x0;
LAB_007f7c9e:
        iVar3 = 0;
      }
      else {
LAB_007f7d17:
        piVar13 = local_c8;
        local_ec = (code *)0x1;
        iVar3 = FUN_007f38ad(param_6);
        if ((iVar3 != 0) || (param_7 != 0)) goto LAB_007f7c9e;
        pcVar11 = *(code **)(*piVar13 + 0x28c);
        guard_check_icall();
        iVar3 = (*pcVar11)();
        if (iVar3 != 0) goto LAB_007f7c9e;
        iVar3 = (int)param_5 - (int)param_3;
      }
      if (((int)local_9c < (int)((int)param_2 + iVar3 + 10)) ||
         ((int)((int)param_4 + -10) <= local_a4)) {
        local_100 = CRgn::vftable;
        goto LAB_007f88c1;
      }
      pcVar11 = *(code **)(*local_c8 + 0x28c);
      guard_check_icall();
      local_d8 = (*pcVar11)();
      if ((param_7 == 0) || (local_ec != (code *)0x0)) {
LAB_007f7d73:
        if (((local_e8 != (undefined **)0xffffffff) || (local_ec != (code *)0x0)) ||
           (local_d4[0x1d] != 0)) {
LAB_007f7d85:
          local_104 = 0;
          local_108 = CRgn::vftable;
          local_8._0_1_ = 7;
          ppuVar6 = local_e8;
          if (local_e8 == (undefined **)0xffffffff) {
            iVar3 = FUN_007c2511();
            ppuVar6 = *(undefined ***)(iVar3 + 0x1c);
          }
          FUN_0079de5e(ppuVar6);
          local_84.left = (LONG)param_2;
          local_8 = CONCAT31(local_8._1_3_,8);
          local_84.top = (LONG)param_3;
          local_84.right = (LONG)param_4;
          local_84.bottom = (LONG)param_5;
          if (local_ec == (code *)0x0) {
            InflateRect(&local_84,-1,0);
            if (local_c8[0x24] == 0) {
              local_84.bottom = local_84.bottom + -1;
            }
            else {
              local_84.top = local_84.top + 1;
            }
            if ((int)local_9c <= local_84.right) {
              local_84.right = (LONG)local_9c;
            }
          }
          else {
            local_74.x = (LONG)param_2;
            local_6c = param_2;
            local_74.y = (LONG)param_5;
            local_64 = (code *)((int)param_2 + 2);
            local_5c = (code *)((int)param_2 + ((int)param_5 - (int)param_3));
            local_54 = local_5c + 4;
            local_58 = (int)param_3 + 2;
            local_44 = param_4;
            local_4c = (code *)((int)param_4 + -2);
            local_40 = (int)param_3 + 2;
            local_3c = param_4;
            iVar3 = 0;
            local_10c = (undefined **)local_c8[0x24];
            local_68 = param_5;
            local_60 = param_5;
            local_50 = param_3;
            local_48 = param_3;
            local_38 = param_5;
            do {
              if ((int)local_9c < (&local_74)[iVar3].x) {
                (&local_74)[iVar3].x = (LONG)local_9c;
                local_cc = (undefined **)0x1;
              }
              if (local_10c == (undefined **)0x0) {
                (&local_74)[iVar3].y = (int)param_3 + (-1 - (&local_74)[iVar3].y) + (int)param_5;
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < 8);
            pHVar8 = CreatePolygonRgn(&local_74,8,2);
            Attach(pHVar8);
            FUN_0079eeb5(&local_108);
          }
          param_1 = local_dc;
          local_10c = *(undefined ***)(*local_d4 + 0xf8);
          guard_check_icall(local_dc,local_84.left,local_84.top,local_84.right,local_84.bottom,
                            local_11c,param_6,param_7,local_c8);
          (*(code *)local_10c)();
          FUN_0079eeb5(0);
          piVar13 = local_c8;
          if (local_ec != (code *)0x0) {
            local_b4.left = 0;
            local_b4.top = 0;
            local_b4.right = 0;
            local_b4.bottom = 0;
            GetClientRect((HWND)local_c8[8],&local_b4);
            local_b4.right = local_a4 + -1;
            FUN_0079ea67(&local_b4);
            iVar3 = FUN_007f38ad(param_6);
            if ((iVar3 == 0) && (param_7 == 0)) {
              pcVar11 = *(code **)(*piVar13 + 0x29c);
              guard_check_icall();
              iVar3 = (*pcVar11)();
              pCVar2 = local_dc;
              if (param_6 != iVar3) {
                local_94 = local_a4;
                local_8c = (code *)(local_84.left + local_84.bottom + (-10 - local_84.top));
                local_90 = local_a0;
                iVar3 = (local_d8 != 0) + 1;
                local_88 = local_98;
                if (local_c8[0x24] == 0) {
                  local_90 = (undefined **)((int)local_a0 - iVar3);
                }
                else {
                  local_88 = (undefined **)((int)local_98 + iVar3);
                }
                FUN_0079ea67(&local_94);
                param_1 = pCVar2;
              }
            }
            Polyline(*(HDC *)(param_1 + 4),&local_74,8);
            if (local_cc != (undefined **)0x0) {
              FUN_0079ec58(&local_8c,local_9c,param_3);
              CDC::LineTo(param_1,(int)local_9c,(int)param_5);
            }
            param_1 = local_dc;
            local_24.top = (LONG)local_a0;
            local_24.right = (LONG)local_9c;
            local_24.bottom = (LONG)local_98;
            local_24.left = local_84.right;
            FUN_0079ea67(&local_24);
          }
          local_11c[0] = CBrush::vftable;
          FUN_00416100();
          local_8 = CONCAT31(local_8._1_3_,6);
          local_108 = CRgn::vftable;
          FUN_00416100();
        }
      }
      else {
        if (local_e8 != (undefined **)0xffffffff) goto LAB_007f7d85;
        if (local_d4[0x1d] != 0) goto LAB_007f7d73;
      }
      iVar3 = param_7;
      iVar7 = FUN_007c2511();
      FUN_0079df60(0,1,*(undefined4 *)(iVar7 + 0x5c));
      local_8._0_1_ = 9;
      iVar7 = FUN_007c2511();
      FUN_0079df60(0,1,*(undefined4 *)(iVar7 + 0x58));
      local_8._0_1_ = 10;
      iVar7 = FUN_007c2511();
      FUN_0079df60(0,1,*(undefined4 *)(iVar7 + 0x60));
      local_8 = CONCAT31(local_8._1_3_,0xb);
      if (local_ec == (code *)0x0) {
        if ((int)local_9c < (int)param_4) {
          local_24.left = (LONG)param_2;
          local_24.top = (LONG)param_3;
          local_24.bottom = (LONG)param_5;
          local_24.right = (LONG)local_9c;
          pHVar8 = CreateRectRgnIndirect(&local_24);
          Attach(pHVar8);
          param_1 = local_dc;
          FUN_0079eeb5(&local_100);
        }
        if (local_c8[0x24] != 0) {
          pppuVar5 = &local_e4;
          if (local_d4[0x1e] == 0) {
            pppuVar5 = &local_114;
          }
          local_d0 = (code *)FUN_0079efbc(pppuVar5);
          iVar3 = param_7;
          if (local_d0 == (code *)0x0) goto LAB_007f88ce;
          ppuVar6 = param_5;
          if (param_7 == 0) {
            ppuVar6 = (undefined **)((int)param_5 + -1);
          }
          FUN_0079ec58(&local_8c,param_4,ppuVar6);
          CDC::LineTo(param_1,(int)param_4,(int)param_3 + 2);
          CDC::LineTo(param_1,(int)((int)param_4 + -2),(int)param_3);
          if (local_d4[0x1e] != 0) {
            FUN_0079efbc(&local_f8);
          }
          CDC::LineTo(param_1,(int)((int)param_2 + 2),(int)param_3);
          CDC::LineTo(param_1,(int)param_2,(int)param_3 + 2);
          CDC::LineTo(param_1,(int)param_2,(int)param_5);
          if (local_d4[0x1e] == 0) goto LAB_007f84d5;
          FUN_0079efbc(&local_114);
          ppuVar6 = param_5;
          if (iVar3 == 0) {
            ppuVar6 = (undefined **)((int)param_5 + -1);
          }
          FUN_0079ec58(&local_8c,(code *)((int)param_4 + -1),ppuVar6);
          ppuVar6 = param_4;
          ppuVar12 = (undefined **)((int)param_3 + 1);
          goto LAB_007f84c6;
        }
        local_d0 = (code *)FUN_0079efbc(&local_f8);
        piVar13 = local_d4;
        if (local_d0 == (code *)0x0) {
LAB_007f88ce:
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        if (local_d4[0x1e] == 0) {
          FUN_0079efbc(&local_114);
        }
        FUN_0079ec58(&local_8c,param_2,param_3);
        CDC::LineTo(param_1,(int)param_2,(int)param_5 + -2);
        if (piVar13[0x1e] != 0) {
          FUN_0079efbc(&local_e4);
        }
        CDC::LineTo(param_1,(int)((int)param_2 + 2),(int)param_5);
        CDC::LineTo(param_1,(int)((int)param_4 + -2),(int)param_5);
        CDC::LineTo(param_1,(int)param_4,(int)param_5 + -2);
        CDC::LineTo(param_1,(int)param_4,(int)param_3 + -1);
        FUN_0079efbc(&local_114);
        if (piVar13[0x1e] != 0) {
          FUN_0079ec58(&local_8c,(code *)((int)param_2 + 3),(int)param_5 + -1);
          CDC::LineTo(param_1,(int)((int)param_4 + -2),(int)param_5 + -1);
          CDC::LineTo(param_1,(int)((int)param_4 + -1),(int)param_5 + -2);
          ppuVar6 = param_4;
          ppuVar12 = (undefined **)((int)param_3 + -1);
          goto LAB_007f84c6;
        }
      }
      else {
        local_d0 = (code *)FUN_0079efbc(&local_f8);
        if (local_d0 == (code *)0x0) goto LAB_007f88ce;
        if (local_c8[0x24] == 0) {
          if (local_cc != (undefined **)0x0) goto LAB_007f84d5;
          ppuVar12 = local_38;
          if (iVar3 != 0) {
            ppuVar12 = (undefined **)((int)local_38 + -1);
          }
          FUN_0079ec58(&local_8c,(code *)((int)local_44 + -1),local_40);
          ppuVar6 = local_3c;
        }
        else {
          FUN_0079ec58(&local_8c,local_64 + 1,local_60);
          CDC::LineTo(param_1,(int)(local_5c + 1),local_58);
          FUN_0079ec58(&local_8c,local_5c + 1,local_58);
          CDC::LineTo(param_1,(int)(local_5c + 2),local_58);
          FUN_0079ec58(&local_8c,local_5c + 2,local_58);
          CDC::LineTo(param_1,(int)(local_5c + 3),local_58);
          FUN_0079ec58(&local_8c,local_54 + -1,(int)local_50 + 1);
          CDC::LineTo(param_1,(int)(local_4c + 1),(int)local_48 + 1);
          if (((iVar3 == 0) && (local_cc == (undefined **)0x0)) && (local_d4[0x1e] != 0)) {
            FUN_0079efbc(&local_114);
            FUN_0079ec58(&local_8c,(code *)((int)local_44 + -2),local_40 + -1);
            CDC::LineTo(param_1,(int)((int)local_44 + -1),local_40 + -1);
          }
          FUN_0079ec58(&local_8c,(code *)((int)local_44 + -1),local_40);
          ppuVar6 = local_3c;
          ppuVar12 = local_38;
        }
LAB_007f84c6:
        CDC::LineTo(param_1,(int)((int)ppuVar6 + -1),(int)ppuVar12);
      }
LAB_007f84d5:
      if (param_7 != 0) {
        local_84.top = (LONG)param_5;
        if (local_c8[0x24] == 0) {
          local_84.top = (LONG)((int)param_3 + -2);
        }
        local_84.left = (LONG)param_2;
        local_84.right = (LONG)param_4;
        local_84.bottom = local_84.top + 2;
        pcVar11 = *(code **)(*local_c8 + 0x1dc);
        guard_check_icall(param_6);
        iVar3 = (*pcVar11)();
        if (local_ec == (code *)0x0) {
LAB_007f855b:
          if (iVar3 == -1) {
            iVar3 = FUN_007c2511();
            hbr = (HBRUSH)0x0;
            if (iVar3 != -0xd0) {
              hbr = *(HBRUSH *)(iVar3 + 0xd4);
            }
            FillRect(*(HDC *)(param_1 + 4),&local_84,hbr);
            goto LAB_007f85b3;
          }
        }
        else {
          if (local_d8 == 0) {
            OffsetRect(&local_84,1,0);
            local_84.left = local_84.left + 1;
          }
          else {
            local_84.left = local_84.left + 3;
          }
          if (iVar3 == -1) {
            iVar3 = FUN_007c2511();
            iVar3 = *(int *)(iVar3 + 0x6c);
            goto LAB_007f855b;
          }
        }
        FUN_0079de5e(iVar3);
        FillRect(*(HDC *)(param_1 + 4),&local_84,local_128);
        FUN_00416100();
      }
LAB_007f85b3:
      FUN_0079efbc(local_d0);
      if (local_ec != (code *)0x0) {
        pcVar11 = *(code **)(*local_c8 + 0x28c);
        guard_check_icall();
        iVar3 = (*pcVar11)();
        if ((iVar3 == 0) || (param_7 == 0)) {
          local_d0 = (code *)((int)param_5 - (int)param_3);
        }
        else {
          iVar3 = ((int)param_5 - (int)param_3) * 3;
          local_d0 = (code *)((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2);
        }
        pcVar11 = *(code **)(*local_c8 + 0x28c);
        guard_check_icall();
        iVar7 = (*pcVar11)();
        iVar3 = DAT_00a0067c;
        if ((iVar7 != 0) && (param_7 != 0)) {
          iVar3 = (int)((DAT_00a0067c * 3 >> 0x1f & 3U) + DAT_00a0067c * 3) >> 2;
        }
        param_2 = (undefined **)((int)param_2 + (int)local_d0);
        param_4 = (undefined **)((int)param_4 - iVar3);
        pcVar11 = *(code **)(*local_c8 + 0x28c);
        guard_check_icall();
        iVar3 = (*pcVar11)();
        if ((iVar3 != 0) && (param_7 != 0)) {
          pcVar11 = *(code **)(*local_c8 + 0x240);
          guard_check_icall(param_6);
          iVar3 = (*pcVar11)();
          if (iVar3 != 0) {
            OffsetRect((LPRECT)&param_2,DAT_00a0067c,0);
          }
        }
      }
      FUN_0079eeb5(0);
      local_e4 = CPen::vftable;
      FUN_00416100();
      local_114 = CPen::vftable;
      FUN_00416100();
      local_f8 = CPen::vftable;
      FUN_00416100();
      local_100 = CRgn::vftable;
      goto LAB_007f8712;
    }
    FUN_007f245a(10);
    local_8 = 1;
    uVar4 = FUN_007f279b(param_2,param_3);
    local_f4 = (POINT *)FUN_007f3821(uVar4,param_2,(int)param_3 + 2);
    uVar4 = FUN_007f27d0(param_4,param_3);
    local_d8 = FUN_007f3866(uVar4,param_4,(int)param_3 + 2);
    local_d0 = (code *)((int)param_3 + 2);
    pcVar9 = (code *)((int)param_2 + 1);
    pcVar11 = (code *)((int)param_4 + -1);
    if ((int)local_d0 < (int)(param_5 + -1)) {
      local_cc = param_3 + 1;
      local_ec = pcVar11;
      local_e0 = pcVar9;
      do {
        uVar4 = FUN_007f3821(local_f4,pcVar9,local_d0);
        local_f4 = (POINT *)FUN_007f3821(uVar4,pcVar9,local_cc);
        uVar4 = FUN_007f3866(local_d8,pcVar11,local_d0);
        local_d8 = FUN_007f3866(uVar4,pcVar11,local_cc);
        pcVar9 = pcVar9 + 1;
        local_cc = (undefined **)((int)local_cc + 2);
        local_d0 = local_d0 + 2;
        pcVar11 = pcVar11 + -1;
      } while ((int)local_d0 < (int)(param_5 + -1));
    }
    local_ec = pcVar11;
    local_e0 = pcVar9;
    if (local_c8[0x24] == 1) {
      local_e0 = pcVar9 + -1;
      local_ec = local_ec + 1;
    }
    local_10c = (undefined **)(local_ec + 1);
    local_110 = (undefined **)(local_e0 + -1);
    pcVar11 = local_e0;
    if ((int)local_d0 < (int)param_5 + -1) {
      local_cc = (undefined **)(local_d0 + 1);
      do {
        local_e0 = local_e0 + 1;
        pcVar9 = (code *)((int)local_cc + -1);
        local_fc = local_cc;
        uVar4 = FUN_007f3821(local_f4,pcVar11,pcVar9);
        local_f4 = (POINT *)FUN_007f3821(uVar4,local_e0,local_cc);
        uVar4 = FUN_007f3866(local_d8,local_ec,pcVar9);
        local_d0 = local_ec + -2;
        local_d8 = FUN_007f3866(uVar4,local_ec + -1,local_cc);
        ppuVar6 = local_cc;
        if (pcVar9 == (code *)((int)param_5 + -2)) {
          uVar4 = FUN_007f3821(local_f4,local_e0,local_cc);
          local_f4 = (POINT *)FUN_007f3821(uVar4,local_e0 + 2,ppuVar6);
          uVar4 = FUN_007f3866(local_d8,local_ec,ppuVar6);
          local_d8 = FUN_007f3866(uVar4,local_d0,ppuVar6);
        }
        pcVar11 = pcVar11 + 1;
        local_ec = local_ec + -1;
        local_cc = (undefined **)((int)ppuVar6 + 1);
      } while ((int)local_fc < (int)param_5 + -1);
    }
    local_e0 = pcVar11;
    piVar13 = local_c8;
    FUN_007f3821(local_f4,local_e0 + 2,param_5);
    FUN_007f3866(local_d8,local_ec + -2,param_5);
    local_f4 = (POINT *)FUN_0078e661(-(uint)((int)((ulonglong)(uint)local_24.left * 8 >> 0x20) != 0)
                                     | (uint)((ulonglong)(uint)local_24.left * 8));
    if (local_2c != (undefined **)0x0) {
      pLVar10 = &local_f4->y;
      ppuVar6 = local_2c;
      do {
        ppuVar12 = (undefined **)*ppuVar6;
        puVar1 = ppuVar6[3];
        ((POINT *)(pLVar10 + -1))->x = (LONG)ppuVar6[2];
        *pLVar10 = (LONG)puVar1;
        if (piVar13[0x24] == 1) {
          *pLVar10 = ((int)param_3 - (int)puVar1) + (int)param_5;
        }
        pLVar10 = pLVar10 + 2;
        ppuVar6 = ppuVar12;
      } while (ppuVar12 != (undefined **)0x0);
    }
    local_104 = 0;
    local_108 = CRgn::vftable;
    local_8 = CONCAT31(local_8._1_3_,2);
    pHVar8 = CreatePolygonRgn(local_f4,local_24.left,2);
    Attach(pHVar8);
    FUN_0079eeb5(&local_108);
    ppuVar6 = local_e8;
    if (local_e8 == (undefined **)0xffffffff) {
      iVar3 = FUN_007c2511();
      ppuVar6 = *(undefined ***)(iVar3 + 0x1c);
    }
    FUN_0079de5e(ppuVar6);
    param_1 = local_dc;
    local_8._0_1_ = 3;
    local_fc = *(undefined ***)(*local_d4 + 0xf8);
    guard_check_icall(local_dc,param_2,param_3,param_4,param_5,local_11c,param_6,param_7,piVar13);
    (*(code *)local_fc)();
    FUN_0079eeb5(0);
    iVar3 = FUN_007c2511();
    FUN_0079df60(0,1,*(undefined4 *)(iVar3 + 0x58));
    local_8 = CONCAT31(local_8._1_3_,4);
    local_fc = (undefined **)FUN_0079efbc(&local_9c);
    local_d8 = 0;
    if (0 < local_24.left) {
      pLVar10 = &local_f4[-1].y;
      do {
        if ((local_d8 & 1) != 0) {
          local_cc = (undefined **)((POINT *)(pLVar10 + -1))->x;
          local_e0 = (code *)*pLVar10;
          local_e8 = (undefined **)pLVar10[1];
          local_d0 = (code *)pLVar10[2];
          iVar3 = (int)((int)param_4 + (int)param_2) / 2;
          if ((iVar3 < (int)local_cc) && (iVar3 < (int)local_e8)) {
            local_cc = (undefined **)((int)local_cc + -1);
            local_e8 = (undefined **)((int)local_e8 + -1);
          }
          if ((int)local_d0 < (int)local_e0) {
            FUN_0079ec58(&local_8c,local_e8,local_d0);
            ppuVar6 = local_cc;
            pcVar11 = local_e0;
          }
          else {
            FUN_0079ec58(local_f0,local_cc,local_e0);
            ppuVar6 = local_e8;
            pcVar11 = local_d0;
          }
          CDC::LineTo(param_1,(int)ppuVar6,(int)pcVar11);
        }
        local_d8 = local_d8 + 1;
        pLVar10 = pLVar10 + 2;
      } while ((int)local_d8 < local_24.left);
    }
    thunk_FUN_008f43b0(local_f4);
    FUN_0079efbc(local_fc);
    param_2 = local_110;
    param_4 = local_10c;
    local_9c = CPen::vftable;
    FUN_00416100();
    local_11c[0] = CBrush::vftable;
    FUN_00416100();
    local_108 = CRgn::vftable;
    FUN_00416100();
    local_8 = 5;
    local_34.y = (LONG)CList<tagPOINT,tagPOINT>::vftable;
    RemoveAll();
    local_8 = 0xffffffff;
  }
  else {
    pcVar11 = *(code **)(*local_c8 + 0x17c);
    guard_check_icall(pRVar14);
    iVar3 = (*pcVar11)();
    ppuVar6 = local_e8;
    local_cc = (undefined **)(iVar3 / 2);
    if (local_c8[0x24] == 0) {
      local_2c = (undefined **)((int)local_cc + (int)param_2);
      param_5 = (undefined **)((int)param_5 + -1);
      local_34.x = (LONG)param_2;
      local_24.left = (int)param_4 - (int)local_cc;
      local_24.right = (LONG)param_4;
    }
    else {
      param_3 = (undefined **)((int)param_3 + 1);
      local_2c = param_2;
      local_34.x = (int)param_2 + (int)local_cc;
      local_24.left = (LONG)param_4;
      local_24.right = (int)param_4 - (int)local_cc;
      param_2 = (undefined **)((int)param_2 + 2);
    }
    local_d0 = (code *)0x0;
    local_34.y = (LONG)param_3;
    local_28 = param_5;
    local_24.top = (LONG)param_5;
    local_24.bottom = (LONG)param_3;
    FUN_0079de5e(local_e8);
    local_8 = 0;
    if ((param_7 == 0) && (ppuVar6 != (undefined **)0xffffffff)) {
      local_d0 = (code *)FUN_0079efbc(&local_108);
    }
    Polygon(*(HDC *)(param_1 + 4),&local_34,4);
    if (local_d0 != (code *)0x0) {
      FUN_0079efbc(local_d0);
    }
    local_108 = CBrush::vftable;
LAB_007f8712:
    local_8 = 0xffffffff;
    FUN_00416100();
  }
  pcVar11 = *(code **)(*local_c8 + 0x1e4);
  iVar3 = param_6;
  guard_check_icall(param_6);
  iVar7 = (*pcVar11)();
  local_d0 = (code *)0xffffffff;
  if ((param_7 == 0) && (iVar7 != -1)) {
    pcVar11 = *(code **)(*(int *)param_1 + 0x30);
    guard_check_icall(iVar7);
    local_d0 = (code *)(*pcVar11)();
  }
  pcVar11 = *(code **)(*local_c8 + 0x288);
  guard_check_icall(iVar3);
  iVar3 = (*pcVar11)();
  if (iVar3 == 0) {
    pcVar11 = *(code **)(*local_c8 + 0x28c);
    guard_check_icall();
    iVar3 = (*pcVar11)();
    if (iVar3 != 0) goto LAB_007f87aa;
  }
  else {
LAB_007f87aa:
    local_b4.left = 0;
    local_b4.top = 0;
    local_b4.right = 0;
    local_b4.bottom = 0;
    pcVar11 = *(code **)(*local_c8 + 0x180);
    guard_check_icall(&local_b4);
    (*pcVar11)();
    if ((int)(local_b4.right + -2) <= (int)param_4) {
      param_4 = (undefined **)(local_b4.right + -2);
    }
  }
  local_120 = 0;
  local_124 = CRgn::vftable;
  local_8 = 0xc;
  pHVar8 = CreateRectRgnIndirect(&local_c4);
  Attach(pHVar8);
  FUN_0079eeb5(&local_124);
  pCVar2 = local_dc;
  pcVar11 = *(code **)(*local_d4 + 0xfc);
  guard_check_icall(local_dc,param_2,param_3,param_4,param_5,param_6,param_7,local_c8,0xffffffff);
  (*pcVar11)();
  if (local_d0 != (code *)0xffffffff) {
    pcVar11 = *(code **)(*(int *)pCVar2 + 0x30);
    guard_check_icall(local_d0);
    (*pcVar11)();
  }
  FUN_0079eeb5(0);
  local_124 = CRgn::vftable;
LAB_007f88c1:
  FUN_00416100();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[64] */
/* 007f88d4  FUN_007f88d4  130 bytes, 0 callers */

void FUN_007f88d4(CDC *param_1)

{
  int iVar1;
  HBRUSH hbr;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  int in_stack_0000001c;
  int in_stack_00000020;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = in_stack_0000001c;
  if (in_stack_0000001c != 0) {
    iVar1 = FUN_007c2511();
    hbr = (HBRUSH)0x0;
    if (iVar1 != -0xd0) {
      hbr = *(HBRUSH *)(iVar1 + 0xd4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  }
  local_c = 0;
  local_8 = 0;
  FUN_00814d1c(param_1,5,&stack0x00000008,0,&local_c);
  if (iVar2 != 0) {
    iVar2 = FUN_007c2511();
    if (in_stack_00000020 == 0) {
      uVar4 = *(ulong *)(iVar2 + 0x60);
      iVar2 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar2 + 0x5c);
    }
    else {
      uVar4 = *(ulong *)(iVar2 + 0x5c);
      iVar2 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar2 + 0x60);
    }
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,uVar3,uVar4);
  }
  return;
}




/* vtable slots: CMFCVisualManager[63], CMFCVisualManagerOffice2003[63], CMFCVisualManagerOffice2007[63], CMFCVisualManagerOfficeXP[63] */
/* 007f8956  FUN_007f8956  804 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f8956(CDC *param_1,code *param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                 int param_7,int *param_8,int param_9)

{
  int iVar1;
  code **ppcVar2;
  int *piVar3;
  code *pcVar4;
  code *local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined1 local_3c [4];
  undefined4 local_38;
  int *local_34;
  int *local_30;
  code *local_2c;
  CDC *local_28;
  code *local_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar3 = param_8;
  uStack_4 = 0x4c;
  local_8 = 0x7f8962;
  local_28 = param_1;
  local_38 = param_6;
  local_34 = param_8;
  pcVar4 = *(code **)(*param_8 + 0x284);
  guard_check_icall();
  iVar1 = (*pcVar4)();
  if ((iVar1 != 0) && (param_7 != 0)) {
    param_4 = piVar3[0x80];
    local_2c = *(code **)(*local_30 + 0x100);
    guard_check_icall(local_28,piVar3[0x80],piVar3[0x81],piVar3[0x82],piVar3[0x83],local_34,
                      local_34[0x7e],local_34[0x7f],0);
    (*local_2c)();
    piVar3 = local_34;
  }
  CStringT<>();
  local_8 = 0;
  pcVar4 = *(code **)(*piVar3 + 0x1bc);
  guard_check_icall(local_38,local_3c);
  (*pcVar4)();
  pcVar4 = *(code **)(*piVar3 + 0x280);
  guard_check_icall();
  iVar1 = (*pcVar4)();
  if (iVar1 == 0) {
    pcVar4 = *(code **)(*piVar3 + 0x238);
    guard_check_icall(&local_4c);
    (*pcVar4)();
    pcVar4 = *(code **)(*piVar3 + 0x1c4);
    guard_check_icall(local_38);
    local_40 = (*pcVar4)();
    pcVar4 = *(code **)(*piVar3 + 0x1d8);
    guard_check_icall(local_38);
    local_44 = (*pcVar4)();
    if (local_40 == -1) {
      local_4c = (code *)(-(uint)(local_44 != 0) & (uint)local_4c);
    }
    local_2c = local_4c;
    if (param_4 - (int)param_2 < (int)(local_4c + DAT_00a0067c * 2)) goto LAB_007f8c67;
    if (local_44 == 0) {
      pcVar4 = *(code **)(*piVar3 + 0x23c);
      guard_check_icall();
      local_44 = (*pcVar4)();
      if ((local_44 != 0) && (local_40 != -1)) {
        iVar1 = 0;
        if (local_28 != (CDC *)0x0) {
          iVar1 = *(int *)(local_28 + 4);
        }
        FUN_0079cf15(*(undefined4 *)(local_44 + 4),local_40,iVar1,param_2 + 4,
                     ((param_5 - param_3) - local_48) / 2 + param_3,1);
      }
    }
    else {
      CDC::DrawState(local_28,param_2 + 4,((param_5 - param_3) - local_48) / 2 + param_3,local_4c,
                     local_48,local_44,0,0);
    }
    piVar3 = local_34;
    local_24 = local_4c + (int)(param_2 + 6);
    iStack_20 = param_3;
    local_1c = param_4;
    iStack_18 = param_5;
    if (param_4 - (int)local_24 < (int)local_4c * 2) {
      pcVar4 = *(code **)(*local_34 + 0x290);
      guard_check_icall();
      iVar1 = (*pcVar4)();
      if (iVar1 == 0) {
        local_1c = local_1c + -3;
      }
    }
    iVar1 = param_9;
    if (param_9 == -1) {
      pcVar4 = *(code **)(*local_30 + 0x11c);
      guard_check_icall(piVar3,local_38,param_7);
      iVar1 = (*pcVar4)();
      if (iVar1 != -1) goto LAB_007f8bee;
    }
    else {
LAB_007f8bee:
      pcVar4 = *(code **)(*(int *)local_28 + 0x30);
      guard_check_icall(iVar1);
      (*pcVar4)();
    }
    local_2c = (code *)((-(uint)(piVar3[0x4c] != 0) & 0x800) + 0x8024);
    pcVar4 = *(code **)(*piVar3 + 0x288);
    guard_check_icall();
    iVar1 = (*pcVar4)();
    if (iVar1 == 0) {
      pcVar4 = *(code **)(*piVar3 + 0x28c);
      guard_check_icall();
      iVar1 = (*pcVar4)();
      pcVar4 = local_2c;
      if (iVar1 != 0) goto LAB_007f8c50;
    }
    else {
LAB_007f8c50:
      pcVar4 = (code *)((uint)local_2c | 1);
    }
    ppcVar2 = &local_24;
  }
  else {
    iVar1 = piVar3[0x4c];
    pcVar4 = *(code **)(*local_30 + 0x128);
    guard_check_icall(&param_2);
    (*pcVar4)();
    ppcVar2 = &param_2;
    pcVar4 = (code *)((-(uint)(iVar1 != 0) & 0x800) + 0x25);
  }
  FUN_007c2378(local_3c,ppcVar2,pcVar4);
LAB_007f8c67:
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[73], CMFCVisualManagerOffice2003[73], CMFCVisualManagerOffice2007[73], CMFCVisualManagerOfficeXP[73] */
/* 007f8c7a  FUN_007f8c7a  105 bytes, 0 callers */

void FUN_007f8c7a(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9)

{
  HBRUSH hbr;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_c [8];
  
  uVar1 = param_9;
  hbr = (HBRUSH)0x0;
  if (param_8 != 0) {
    hbr = *(HBRUSH *)(param_8 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_4,hbr);
  uVar1 = FUN_0079efbc(uVar1);
  FUN_0079ec58(local_c,param_4,param_5);
  iVar2 = param_6;
  iVar3 = param_5;
  if (param_3 != 0) {
    iVar2 = param_4;
    iVar3 = param_7;
  }
  CDC::LineTo(param_1,iVar2,iVar3);
  FUN_0079efbc(uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[66] */
/* 007f8ce3  FUN_007f8ce3  107 bytes, 0 callers */

void FUN_007f8ce3(CDC *param_1,tagRECT *param_2,CMFCButton *param_3,byte param_4)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = CMFCButton::IsPressed(param_3);
  if ((iVar2 == 0) && ((param_4 & 1) == 0)) {
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x60);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar2 + 0x5c),uVar1);
  }
  else {
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x5c);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar2 + 0x60),uVar1);
    param_2->left = param_2->left + 2;
    param_2->top = param_2->top + 2;
  }
  InflateRect(param_2,-2,-2);
  return;
}




/* vtable slots: CMFCVisualManager[93] */
/* 007f9082  FUN_007f9082  152 bytes, 0 callers */

void FUN_007f9082(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c [8];
  
  iVar1 = FUN_007c2511();
  if (param_6 == 0) {
    iVar1 = iVar1 + 0xe0;
  }
  else {
    iVar1 = iVar1 + 0xd8;
  }
  uVar2 = FUN_0079efbc(iVar1);
  FUN_0079ec58(local_c,param_2,param_3);
  CDC::LineTo(param_1,param_2,param_5 + -1);
  CDC::LineTo(param_1,param_4 + -1,param_5 + -1);
  CDC::LineTo(param_1,param_4 + -1,param_3);
  if (param_7 == 0) {
    param_3 = param_3 + -1;
    param_2 = param_4 + -1;
  }
  CDC::LineTo(param_1,param_2,param_3);
  FUN_0079efbc(uVar2);
  return;
}




/* vtable slots: CMFCVisualManager[90] */
/* 007f911a  FUN_007f911a  882 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f911a(CDC *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  ulong uVar2;
  CDC *pCVar3;
  COLORREF CVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  code *pcVar8;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  CDC *local_44;
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int iStack_2c;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_48 = param_2;
  local_44 = param_1;
  if ((param_2 != 0) && (*(int *)(param_2 + 4) != 0)) {
    local_18 = *(int *)(param_2 + 0x34);
    local_14 = *(int *)(param_2 + 0x38);
    local_10 = *(int *)(param_2 + 0x3c);
    local_c = *(int *)(param_2 + 0x40);
    CVar4 = GetBkColor(*(HDC *)(param_1 + 8));
    iVar6 = local_48;
    if (*(int *)(local_48 + 0x2c) == 0) {
      iVar5 = FUN_007c2511();
      uVar7 = *(undefined4 *)(iVar5 + 0x54);
    }
    else {
      iVar5 = FUN_007c2511();
      uVar7 = *(undefined4 *)(iVar5 + 0x3c);
    }
    FUN_007a506d(&local_18,uVar7);
    pcVar8 = *(code **)(*(int *)param_1 + 0x2c);
    guard_check_icall(CVar4);
    (*pcVar8)();
    if ((*(int *)(iVar6 + 0x5c) == 0) ||
       (((local_14 - local_18) - local_c) + local_10 <= *(int *)(iVar6 + 0x54))) {
      local_58 = 0;
    }
    else {
      local_58 = 1;
      pcVar8 = *(code **)(*local_40 + 0x16c);
      guard_check_icall(param_1,iVar6,5,param_3,param_4,param_5);
      (*pcVar8)();
    }
    pcVar8 = *(code **)(*(int *)param_1 + 0x28);
    iVar5 = FUN_007c2511();
    guard_check_icall(iVar5 + 300);
    local_50 = (*pcVar8)();
    GetTextColor(*(HDC *)(param_1 + 8));
    if ((param_5 == 0) || (param_3 == 0)) {
      pcVar8 = *(code **)(*(int *)param_1 + 0x30);
      iVar5 = *(int *)(iVar6 + 0x60);
    }
    else {
      iVar5 = *(int *)(iVar6 + 100);
      pcVar8 = *(code **)(*(int *)param_1 + 0x30);
    }
    if (iVar5 == -1) {
      if (*(int *)(iVar6 + 0x2c) == 0) {
        iVar5 = FUN_007c2511();
        iVar5 = *(int *)(iVar5 + 0x70);
      }
      else {
        iVar5 = FUN_007c2511();
        iVar5 = *(int *)(iVar5 + 0x6c);
      }
    }
    guard_check_icall(iVar5);
    local_3c = (*pcVar8)();
    local_5c = FUN_0079f0b8(1);
    iVar6 = *(int *)(*(int *)(iVar6 + 4) + 8);
    local_4c = *(int *)(iVar6 + 0x3bc);
    local_34 = *(int *)(iVar6 + 0x3c0);
    if (local_4c == -1) {
      local_4c = local_40[0x24];
    }
    iStack_2c = local_c;
    local_38 = local_4c;
    if (local_58 != 0) {
      local_38 = *(int *)(local_48 + 0x54) + 5;
    }
    local_38 = local_18 + local_38;
    if (local_34 == -1) {
      local_34 = local_40[0x25];
    }
    local_34 = local_14 + local_34;
    iVar6 = local_4c;
    if (param_5 != 0) {
      iVar6 = local_c - local_14;
    }
    local_30 = local_38;
    if (local_38 <= local_10 - iVar6) {
      local_30 = local_4c;
      if (param_5 != 0) {
        local_30 = local_c - local_14;
      }
      local_30 = local_10 - local_30;
    }
    piVar1 = (int *)(local_48 + 8);
    FUN_007c2378(piVar1,&local_38,0x24);
    FUN_0079f0b8(local_5c);
    pcVar8 = *(code **)(*(int *)param_1 + 0x28);
    guard_check_icall(local_50);
    (*pcVar8)();
    pcVar8 = *(code **)(*(int *)param_1 + 0x30);
    guard_check_icall(local_3c);
    (*pcVar8)();
    if ((param_5 != 0) && (*(int *)(*piVar1 + -0xc) != 0)) {
      FUN_0081507c(&local_54);
      local_28.left = local_18;
      iVar6 = (-(((local_c - local_14) + 1) / 2) - (local_54 + 1) / 2) + local_10;
      if (local_18 <= iVar6) {
        local_28.left = iVar6;
      }
      iVar6 = (-(((local_c - local_14) + 1) / 2) - (local_50 + 1) / 2) + local_c;
      local_28.top = local_14;
      if (local_14 <= iVar6) {
        local_28.top = iVar6;
      }
      local_28.right = local_28.left + local_54;
      local_28.bottom = local_50 + local_28.top;
      if ((local_28.right <= local_10) && (local_28.bottom <= local_c)) {
        local_3c = local_28.left;
        if (param_3 != 0) {
          iVar6 = FUN_007c2511();
          uVar7 = FUN_0079efbc(iVar6 + 0xd0);
          CVar4 = GetBkColor(*(HDC *)(local_44 + 8));
          iVar6 = FUN_007c2511();
          uVar2 = *(ulong *)(iVar6 + 0x58);
          iVar6 = FUN_007c2511();
          pCVar3 = local_44;
          CDC::Draw3dRect(local_44,&local_28,*(ulong *)(iVar6 + 0x6c),uVar2);
          pcVar8 = *(code **)(*(int *)pCVar3 + 0x2c);
          guard_check_icall(CVar4);
          (*pcVar8)();
          param_1 = local_44;
          FUN_0079efbc(uVar7);
        }
        local_60 = 0;
        local_5c = 0;
        FUN_00814c80(param_1,(-(uint)(*(int *)(local_48 + 0x30) != 0) & 0xfffffff9) + 7,&local_28,0,
                     &local_60);
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManager[91], CMFCVisualManagerOffice2003[91], CMFCVisualManagerOffice2007[91], CMFCVisualManagerOfficeXP[91] */
/* 007f948d  FUN_007f948d  149 bytes, 0 callers */

void FUN_007f948d(int param_1,int param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  HDC hdc;
  
  if (*(HICON *)(param_2 + 0x5c) != (HICON)0x0) {
    iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 4) + 8) + 0x3c0);
    if (iVar1 == -1) {
      iVar1 = *(int *)(in_ECX + 0x94);
    }
    param_3 = param_3 / 2;
    if (param_3 < 0) {
      param_3 = 0;
    }
    iVar2 = *(int *)(param_2 + 0x40) - *(int *)(param_2 + 0x58);
    iVar1 = (iVar2 - (*(int *)(param_2 + 0x38) + iVar1)) / 2;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    hdc = (HDC)0x0;
    if (param_1 != 0) {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawIconEx(hdc,*(int *)(param_2 + 0x34) + param_3,iVar2 - iVar1,*(HICON *)(param_2 + 0x5c),
               *(int *)(param_2 + 0x54),*(int *)(param_2 + 0x58),0,(HBRUSH)0x0,3);
  }
  return;
}




/* vtable slots: CMFCVisualManager[30] */
/* 007f9522  OnDrawTearOffCaption  89 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnDrawTearOffCaption(class CDC *,class
   CRect,int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnDrawTearOffCaption(undefined4 param_1_00,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  undefined4 uVar2;
  int in_stack_00000018;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -0xd0) {
    hbr = *(HBRUSH *)(iVar1 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  InflateRect((LPRECT)&stack0x00000008,-2,-1);
  iVar1 = FUN_007c2511();
  if (in_stack_00000018 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x80);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x7c);
  }
  FUN_007a506d(&stack0x00000008,uVar2);
  return;
}




/* vtable slots: CMFCVisualManager[96], CMFCVisualManagerOffice2003[96], CMFCVisualManagerOffice2007[96], CMFCVisualManagerOfficeXP[96] */
/* 007f957b  FUN_007f957b  38 bytes, 0 callers */

void FUN_007f957b(CDC *param_1,tagRECT *param_2)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x54);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar2 + 0x54),uVar1);
  return;
}




/* vtable slots: CMFCVisualManager[122] */
/* 007f95a1  FUN_007f95a1  196 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f95a1(int param_1)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int *in_ECX;
  HBRUSH hbr;
  int in_stack_00000018;
  tagRECT local_18;
  uint local_8;
  
  iVar2 = in_stack_00000018;
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  hbr = (HBRUSH)0x0;
  if (*(int *)(in_stack_00000018 + 0x7a8) == 0) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    pHVar3 = GetParent(*(HWND *)(in_stack_00000018 + 0x20));
    pCVar4 = CWnd::FromHandle(pHVar3);
    GetClientRect(*(HWND *)(pCVar4 + 0x20),&local_18);
    pHVar3 = GetParent(*(HWND *)(iVar2 + 0x20));
    pCVar4 = CWnd::FromHandle(pHVar3);
    MapWindowPoints(*(HWND *)(pCVar4 + 0x20),*(HWND *)(iVar2 + 0x20),(LPPOINT)&local_18,2);
    pcVar1 = *(code **)(*in_ECX + 0x1dc);
    guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom);
    (*pcVar1)();
  }
  else {
    iVar2 = FUN_007c2511();
    if (iVar2 != -0x98) {
      hbr = *(HBRUSH *)(iVar2 + 0x9c);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  }
  return;
}




/* vtable slots: CMFCVisualManager[60], CMFCVisualManager[108], CMFCVisualManagerOfficeXP[108] */
/* 007f9665  FUN_007f9665  41 bytes, 2 callers */

void FUN_007f9665(int param_1)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -0xd0) {
    hbr = *(HBRUSH *)(iVar1 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[65] */
/* 007f968e  OnEraseTabsButton  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnEraseTabsButton(class CDC *,class
   CRect,class CMFCButton *,class CMFCBaseTabCtrl *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnEraseTabsButton(undefined4 param_1_00,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -0xd0) {
    hbr = *(HBRUSH *)(iVar1 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[68], CMFCVisualManagerOfficeXP[68] */
/* 007f96b7  FUN_007f96b7  87 bytes, 1 callers */

bool FUN_007f96b7(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_stack_00000018;
  
  iVar3 = *in_stack_00000018;
  pcVar1 = *(code **)(iVar3 + 0x20c);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(iVar3 + 0x1dc);
  guard_check_icall(uVar2);
  iVar3 = (*pcVar1)();
  if (iVar3 != -1) {
    FUN_007a506d(&stack0x00000008,iVar3);
  }
  return iVar3 != -1;
}




/* vtable slots: CMFCVisualManager[13] */
/* 007f970e  FUN_007f970e  383 bytes, 1 callers */

void FUN_007f970e(int param_1,CObject *param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6)

{
  code *pcVar1;
  CObject *pCVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int iVar5;
  BOOL BVar6;
  RECT *lprc;
  int *in_ECX;
  HBRUSH hbr;
  HDC hDC;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CReBar_0098511c,param_2);
  if (pCVar2 != (CObject *)0x0) {
LAB_007f9862:
    iVar5 = *in_ECX;
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6);
    (**(code **)(iVar5 + 0x1c))();
    return;
  }
  pHVar3 = GetParent(*(HWND *)(param_2 + 0x20));
  pCVar4 = CWnd::FromHandle(pHVar3);
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CReBar_0098511c,(CObject *)pCVar4);
  if (pCVar2 != (CObject *)0x0) goto LAB_007f9862;
  iVar5 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPane_00a006a0);
  if (iVar5 != 0) {
    pcVar1 = *(code **)(*(int *)param_2 + 0x434);
    guard_check_icall(param_1,param_3,param_4,param_5,param_6);
    (*pcVar1)();
    return;
  }
  iVar5 = FUN_0079d98a(&PTR_s_CMFCCaptionBar_0099979c);
  if (iVar5 == 0) {
    iVar5 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
    hbr = (HBRUSH)0x0;
    if ((iVar5 == 0) || (*(int *)(param_2 + 0xd80) == 0)) {
      if (*(int *)(param_2 + 0x8c) == 0) {
        iVar5 = FUN_007c2511();
        iVar5 = iVar5 + 0xd0;
      }
      else {
        iVar5 = FUN_007c2511();
        iVar5 = iVar5 + 0x98;
      }
      BVar6 = IsRectEmpty((RECT *)&stack0x0000001c);
      lprc = (RECT *)&param_3;
      if (BVar6 == 0) {
        lprc = (RECT *)&stack0x0000001c;
      }
      if (iVar5 != 0) {
        hbr = *(HBRUSH *)(iVar5 + 4);
      }
      hDC = *(HDC *)(param_1 + 4);
      goto LAB_007f9815;
    }
    iVar5 = FUN_007c2511();
    iVar5 = iVar5 + 200;
  }
  else {
    if (*(int *)(param_2 + 0x2c4) == 0) {
      iVar5 = *(int *)(param_2 + 700);
      if (iVar5 == -1) {
        iVar5 = FUN_007c2511();
        iVar5 = *(int *)(iVar5 + 0x58);
      }
      FUN_007a506d(&stack0x0000001c,iVar5);
      return;
    }
    iVar5 = FUN_007c2511();
    iVar5 = iVar5 + 0xd0;
  }
  hbr = (HBRUSH)0x0;
  if (iVar5 != 0) {
    hbr = *(HBRUSH *)(iVar5 + 4);
  }
  lprc = (RECT *)&stack0x0000001c;
  hDC = *(HDC *)(param_1 + 4);
LAB_007f9815:
  FillRect(hDC,lprc,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[33] */
/* 007f988d  OnFillButtonInterior  237 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnFillButtonInterior(class CDC *,class
   CMFCToolBarButton *,class CRect,enum CMFCVisualManager::AFX_BUTTON_STATE)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManager::OnFillButtonInterior
          (CMFCVisualManager *this,CDC *param_1,CObject *param_2,LONG param_4,LONG param_5,
          LONG param_6,LONG param_7,int param_8)

{
  int iVar1;
  CObject *pCVar2;
  CDrawingManager local_2c [8];
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x7f9899;
  iVar1 = FUN_0079d98a(&PTR_s_CMFCShowAllButton_0099966c);
  if (iVar1 != 0) {
    if (param_8 == 2) {
      CDrawingManager::CDrawingManager(local_2c,param_1);
      local_8 = 0;
      FUN_00818045(param_4,param_5,param_6,param_7,0xffffffff,0xffffffff,0,0xffffffff);
      FUN_0081510b();
    }
    goto LAB_007f9972;
  }
  if (*(int *)(this + 0x60) == 0) {
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,param_2);
    if ((pCVar2 == (CObject *)0x0) || (*(int *)(pCVar2 + 0x6c) == 0)) goto LAB_007f9972;
    iVar1 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
    if (iVar1 == 0) goto LAB_007f9972;
  }
  iVar1 = FUN_0079d98a(&PTR_s_CMFCOutlookBarPaneButton_00a009f8);
  if ((((iVar1 == 0) && (DAT_00a127ac == 0)) && (param_8 != 2)) &&
     ((*(uint *)(param_2 + 0x24) & 0x110000) != 0)) {
    local_24.left = param_4;
    local_24.top = param_5;
    local_24.right = param_6;
    local_24.bottom = param_7;
    InflateRect(&local_24,-DAT_00a12218,-DAT_00a1221c);
    FUN_007e9a70(param_1,&local_24);
  }
LAB_007f9972:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManager[54] */
/* 007f997a  OnFillCaptionBarButton  80 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::OnFillCaptionBarButton(class CDC
   *,class CMFCCaptionBar *,class CRect,int,int,int,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::OnFillCaptionBarButton(undefined4 param_1_00,int param_1,int param_2)

{
  ulong uVar1;
  int iVar2;
  HBRUSH hbr;
  int in_stack_00000024;
  
  hbr = (HBRUSH)0x0;
  if (*(int *)(param_2 + 0x2c4) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = FUN_007c2511();
    if (iVar2 != -0xd0) {
      hbr = *(HBRUSH *)(iVar2 + 0xd4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
    iVar2 = FUN_007c2511();
    if (in_stack_00000024 == 0) {
      uVar1 = *(ulong *)(iVar2 + 0x68);
    }
    else {
      uVar1 = *(ulong *)(iVar2 + 0x38);
    }
  }
  return uVar1;
}




/* vtable slots: CMFCVisualManager[78] */
/* 007f99ca  OnFillCommandsListBackground  225 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::OnFillCommandsListBackground(class
   CDC *,class CRect,int)
   
   Library: Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::OnFillCommandsListBackground
          (undefined4 param_1_00,int param_1,int param_3,int param_4,int param_5,int param_6,
          int param_7)

{
  int iVar1;
  HBRUSH pHVar2;
  ulong uVar3;
  
  iVar1 = FUN_007c2511();
  if (param_7 == 0) {
    pHVar2 = (HBRUSH)0x0;
    if (iVar1 != -0xd0) {
      pHVar2 = *(HBRUSH *)(iVar1 + 0xd4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,pHVar2);
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x68);
  }
  else {
    pHVar2 = (HBRUSH)0x0;
    if (iVar1 != -0xa0) {
      pHVar2 = *(HBRUSH *)(iVar1 + 0xa4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,pHVar2);
    InflateRect((LPRECT)&param_3,-1,-1);
    param_5 = param_5 + -1;
    param_6 = param_6 + -1;
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4 + 1,1,param_6 - param_4,0x5a0049);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_5 - param_3,1,0x5a0049);
    PatBlt(*(HDC *)(param_1 + 4),param_5,param_4,1,param_6 - param_4,0x5a0049);
    PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_6,param_5 - param_3,1,0x5a0049);
    iVar1 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar1 + 0x40);
  }
  return uVar3;
}




/* vtable slots: CMFCVisualManager[85], CMFCVisualManagerOfficeXP[85] */
/* 007f9aab  OnFillHeaderCtrlBackground  70 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnFillHeaderCtrlBackground(class
   CMFCHeaderCtrl *,class CDC *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManager::OnFillHeaderCtrlBackground(undefined4 param_1_00,int param_1,int param_2)

{
  int iVar1;
  HBRUSH hbr;
  
  hbr = (HBRUSH)0x0;
  if (*(int *)(param_1 + 0xac) == 0) {
    iVar1 = FUN_007c2511();
    iVar1 = iVar1 + 0xd0;
  }
  else {
    iVar1 = FUN_007c2511();
    iVar1 = iVar1 + 0x98;
  }
  if (iVar1 != 0) {
    hbr = *(HBRUSH *)(iVar1 + 4);
  }
  FillRect(*(HDC *)(param_2 + 4),(RECT *)&stack0x0000000c,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[43], CMFCVisualManagerOffice2003[43], CMFCVisualManagerOffice2007[43], CMFCVisualManagerOfficeXP[43] */
/* 007f9af1  FUN_007f9af1  56 bytes, 0 callers */

void FUN_007f9af1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x84);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[59], CMFCVisualManagerOfficeXP[59] */
/* 007f9bd1  FUN_007f9bd1  47 bytes, 1 callers */

void FUN_007f9bd1(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_stack_00000018;
  
  puVar1 = in_stack_00000018;
  iVar2 = FUN_007c2511();
  FUN_007a506d(&stack0x00000008,*(undefined4 *)(iVar2 + 0x58));
  iVar2 = FUN_007c2511();
  *puVar1 = *(undefined4 *)(iVar2 + 0x5c);
  return;
}




/* vtable slots: CMFCVisualManager[56], CMFCVisualManagerOfficeXP[56] */
/* 007f9c00  FUN_007f9c00  51 bytes, 1 callers */

void FUN_007f9c00(int param_1,RECT *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -0xd0) {
    hbr = *(HBRUSH *)(iVar1 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),param_2,hbr);
  iVar1 = FUN_007c2511();
  *param_5 = *(undefined4 *)(iVar1 + 0x68);
  return;
}




/* vtable slots: CMFCVisualManager[119] */
/* 007f9c33  OnFillPopupWindowBackground  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnFillPopupWindowBackground(class CDC *,class
   CRect)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnFillPopupWindowBackground(undefined4 param_1_00,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -0xd0) {
    hbr = *(HBRUSH *)(iVar1 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[143], CMFCVisualManagerOffice2003[143], CMFCVisualManagerOfficeXP[143] */
/* 007f9e93  OnFillRibbonEdit  232 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnFillRibbonEdit(class CDC *,class
   CMFCRibbonRichEditCtrl *,class CRect,int,int,int,unsigned long &,unsigned long &,unsigned long &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManager::OnFillRibbonEdit
          (undefined4 param_1_00,CDC *param_1,undefined4 param_2,LONG param_4,LONG param_5,
          LONG param_6,LONG param_7,int param_8,undefined4 param_9,int param_10)

{
  int iVar1;
  HBRUSH pHVar2;
  undefined4 uVar3;
  CDrawingManager local_20 [8];
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x7f9e9f;
  if ((param_8 == 0) || (param_10 != 0)) {
    CDrawingManager::CDrawingManager(local_18,param_1);
    local_8 = 1;
    if (DAT_00a12704 == 0) {
      iVar1 = FUN_007c2511();
      pHVar2 = (HBRUSH)0x0;
      if (iVar1 != -0xd0) {
        pHVar2 = *(HBRUSH *)(iVar1 + 0xd4);
      }
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_4,pHVar2);
      FUN_00818045(param_4,param_5,param_6,param_7,0xffffffff,0xffffffff,0,0xffffffff);
    }
    else {
      uVar3 = 0xffffffff;
      iVar1 = FUN_007c2511(0xffffffff);
      FUN_00816b6a(&param_4,*(undefined4 *)(iVar1 + 0x54),uVar3);
    }
  }
  else {
    if (DAT_00a12704 == 0) {
      iVar1 = FUN_007c2511();
      pHVar2 = (HBRUSH)0x0;
      if (iVar1 != -200) {
        pHVar2 = *(HBRUSH *)(iVar1 + 0xcc);
      }
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_4,pHVar2);
      return;
    }
    CDrawingManager::CDrawingManager(local_20,param_1);
    local_8 = 0;
    uVar3 = 0xffffffff;
    iVar1 = FUN_007c2511(0xffffffff);
    FUN_00816b6a(&param_4,*(undefined4 *)(iVar1 + 0x6c),uVar3);
  }
  FUN_0081510b();
  return;
}




/* vtable slots: CMFCVisualManager[146], CMFCVisualManagerOffice2003[146], CMFCVisualManagerOfficeXP[146] */
/* 007f9f7b  FUN_007f9f7b  39 bytes, 1 callers */

void FUN_007f9f7b(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x238);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManager[156] */
/* 007f9fa2  OnFillRibbonMenuFrame  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnFillRibbonMenuFrame(class CDC *,class
   CMFCRibbonMainPanel *,class CRect)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnFillRibbonMenuFrame(undefined4 param_1_00,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -200) {
    hbr = *(HBRUSH *)(iVar1 + 0xcc);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[169], CMFCVisualManagerOffice2003[169], CMFCVisualManagerOfficeXP[169] */
/* 007f9fcb  OnFillRibbonQuickAccessToolBarPopup  41 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup(class CDC
   *,class CMFCRibbonPanelMenuBar *,class CRect)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup(undefined4 param_1_00,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -0xd0) {
    hbr = *(HBRUSH *)(iVar1 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[103], CMFCVisualManagerOffice2003[103], CMFCVisualManagerOffice2007[103], CMFCVisualManagerOfficeXP[103] */
/* 007f9ff4  FUN_007f9ff4  32 bytes, 0 callers */

void FUN_007f9ff4(void)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  FUN_007a506d(&stack0x0000000c,*(undefined4 *)(iVar1 + 0x54));
  return;
}




/* vtable slots: CMFCVisualManager[62] */
/* 007fa014  FUN_007fa014  212 bytes, 1 callers */

void FUN_007fa014(int param_1)

{
  code *pcVar1;
  int *piVar2;
  AFX_GLOBAL_DATA *this;
  int iVar3;
  int iVar4;
  HBRUSH hbr;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  int in_stack_00000020;
  int *in_stack_00000024;
  HDC hDC;
  
  piVar2 = in_stack_00000024;
  iVar4 = in_stack_00000018;
  if (in_stack_00000020 != 0) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar3 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar3 == 0) {
      pcVar1 = *(code **)(*piVar2 + 0x288);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        pcVar1 = *(code **)(*piVar2 + 0x28c);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 == 0) {
          pcVar1 = *(code **)(*piVar2 + 0x290);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          if (iVar3 == 0) goto LAB_007fa0c8;
        }
      }
      pcVar1 = *(code **)(*piVar2 + 0x1dc);
      guard_check_icall(in_stack_0000001c);
      iVar3 = (*pcVar1)();
      if (iVar3 == -1) {
        iVar4 = FUN_007c2511();
        hbr = (HBRUSH)0x0;
        if (iVar4 != -200) {
          hbr = *(HBRUSH *)(iVar4 + 0xcc);
        }
        hDC = *(HDC *)(param_1 + 4);
        goto LAB_007fa0db;
      }
    }
  }
LAB_007fa0c8:
  if (iVar4 == 0) {
    hbr = (HBRUSH)0x0;
  }
  else {
    hbr = *(HBRUSH *)(iVar4 + 4);
  }
  hDC = *(HDC *)(param_1 + 4);
LAB_007fa0db:
  FillRect(hDC,(RECT *)&stack0x00000008,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[89], CMFCVisualManagerOfficeXP[89] */
/* 007fa0e8  OnFillTasksPaneBackground  41 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnFillTasksPaneBackground(class CDC *,class
   CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnFillTasksPaneBackground(undefined4 param_1_00,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -200) {
    hbr = *(HBRUSH *)(iVar1 + 0xcc);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[182], CMFCVisualManagerOffice2003[182], CMFCVisualManagerOffice2007[182], CMFCVisualManagerOfficeXP[182] */
/* 007fa111  FUN_007fa111  138 bytes, 0 callers */

void FUN_007fa111(int param_1)

{
  COLORREF *pColor;
  COLORREF *pColor_00;
  HDC pHVar1;
  HBRUSH hbr;
  int in_ECX;
  COLORREF *in_stack_0000001c;
  COLORREF *in_stack_00000020;
  
  pColor_00 = in_stack_00000020;
  pColor = in_stack_0000001c;
  if (*(int *)(in_ECX + 0x44) == 0) {
    hbr = GetSysColorBrush(0x18);
    if (param_1 == 0) {
      pHVar1 = (HDC)0x0;
    }
    else {
      pHVar1 = *(HDC *)(param_1 + 4);
    }
    FillRect(pHVar1,(RECT *)&stack0x0000000c,hbr);
  }
  else {
    if (param_1 == 0) {
      pHVar1 = (HDC)0x0;
    }
    else {
      pHVar1 = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(in_ECX + 0x44),pHVar1,1,0,(LPCRECT)&stack0x0000000c,(LPCRECT)0x0
                       );
    GetThemeColor(*(HTHEME *)(in_ECX + 0x44),1,0,0xedb,pColor);
    GetThemeColor(*(HTHEME *)(in_ECX + 0x44),1,0,0xedf,pColor_00);
  }
  return;
}




/* vtable slots: CMFCVisualManager[36] */
/* 007fa19b  OnHighlightMenuItem  41 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManager::OnHighlightMenuItem(class CDC *,class
   CMFCToolBarMenuButton *,class CRect,unsigned long &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCVisualManager::OnHighlightMenuItem(undefined4 param_1_00,int param_1)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar1 != -0xa0) {
    hbr = *(HBRUSH *)(iVar1 + 0xa4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
  return;
}




/* vtable slots: CMFCVisualManager[40] */
/* 007fa1c4  FUN_007fa1c4  101 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007fa1c4(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5)

{
  ulong uVar1;
  int iVar2;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7fa1d0;
  CDrawingManager::CDrawingManager(local_18,param_1);
  local_8 = 0;
  FUN_00818045(param_2,param_3,param_4,param_5,0xffffffff,0xffffffff,0,0xffffffff);
  iVar2 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar2 + 0x5c);
  iVar2 = FUN_007c2511();
  CDC::Draw3dRect(param_1,(tagRECT *)&param_2,*(ulong *)(iVar2 + 0x58),uVar1);
  FUN_0081510b();
  return;
}




/* vtable slots: CMFCVisualManager[126], CMFCVisualManagerOffice2003[126], CMFCVisualManagerOfficeXP[126] */
/* 007fa229  FUN_007fa229  417 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007fa229(int param_1,int param_2,int param_3)

{
  AFX_GLOBAL_DATA *this;
  int iVar1;
  BOOL BVar2;
  HRGN pHVar3;
  undefined **local_20;
  HRGN local_1c;
  undefined **local_18;
  HRGN local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x7fa235;
  this = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar1 = AFX_GLOBAL_DATA::IsDwmCompositionEnabled(this);
  if (iVar1 == 0) {
    iVar1 = FUN_0079d98a(&PTR_s_CFrameWndEx_00994040);
    if (iVar1 == 0) {
      iVar1 = FUN_0079d98a(&PTR_s_CMDIFrameWndEx_009945d0);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x44c);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x230);
    }
    if (((iVar1 != 0) && (BVar2 = IsWindowVisible(*(HWND *)(iVar1 + 0x20)), BVar2 != 0)) &&
       (*(int *)(iVar1 + 0x328) != 0)) {
      local_1c = (HRGN)0x0;
      local_20 = CRgn::vftable;
      local_8 = 0;
      pHVar3 = CreateRectRgn(0,0,param_2,param_3);
      Attach(pHVar3);
      local_14 = (HRGN)0x0;
      local_18 = CRgn::vftable;
      local_8 = CONCAT31(local_8._1_3_,1);
      pHVar3 = CreateRectRgn(0,0,5,5);
      Attach(pHVar3);
      CombineRgn(local_1c,local_14,local_1c,3);
      CGdiObject::DeleteObject((CGdiObject *)&local_18);
      pHVar3 = CreateEllipticRgn(0,0,0xb,0xb);
      Attach(pHVar3);
      CombineRgn(local_1c,local_14,local_1c,2);
      CGdiObject::DeleteObject((CGdiObject *)&local_18);
      pHVar3 = CreateRectRgn(param_2 + -5,0,param_2,5);
      Attach(pHVar3);
      CombineRgn(local_1c,local_14,local_1c,3);
      CGdiObject::DeleteObject((CGdiObject *)&local_18);
      pHVar3 = CreateEllipticRgn(param_2 + -10,0,param_2 + 1,0xb);
      Attach(pHVar3);
      CombineRgn(local_1c,local_14,local_1c,2);
      pHVar3 = CGdiObject::Detach((CGdiObject *)&local_20);
      SetWindowRgn(*(HWND *)(param_1 + 0x20),pHVar3,1);
      local_18 = CRgn::vftable;
      FUN_00416100();
      local_20 = CRgn::vftable;
      FUN_00416100();
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCVisualManager[161], CMFCVisualManagerOffice2003[161], CMFCVisualManagerOffice2007[161], CMFCVisualManagerOfficeXP[161] */
/* 007fa4f6  RibbonCategoryColorToRGB  217 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManager::RibbonCategoryColorToRGB(enum
   AFX_RibbonCategoryColor)
   
   Library: Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManager::RibbonCategoryColorToRGB(CMFCVisualManager *this,AFX_RibbonCategoryColor param_1)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this_00);
    if (iVar1 == 0) {
      if (param_1 == 1) {
        return 0xa0a0ff;
      }
      if (param_1 == 2) {
        return 0x37bdef;
      }
      if (param_1 == 3) {
        return 0x1be5fd;
      }
      if (param_1 != 4) {
        if (param_1 == 5) {
          return 0xc4b580;
        }
        if (param_1 != 6) {
          if (param_1 != 7) {
            return 0xffffffff;
          }
          return 0xd1b2d6;
        }
        return 0xe0a372;
      }
      return 0x59be71;
    }
  }
  if (param_1 == 1) {
    return 0xff;
  }
  if (param_1 == 2) {
    return 0x80ff;
  }
  if (param_1 == 3) {
    return 0xffff;
  }
  if (param_1 != 4) {
    if (param_1 == 5) {
      return 0xff0000;
    }
    if (param_1 != 6) {
      if (param_1 != 7) {
        return 0xffffffff;
      }
      return 0xff00ff;
    }
    return 0x800000;
  }
  return 0xff00;
}



