/* CMFCVisualManagerOffice2007 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCVisualManagerOffice2007[1] */
/* 0082cf56  FUN_0082cf56  51 bytes, 0 callers */

void FUN_0082cf56(byte param_1)

{
  FUN_0082c8b1();
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




/* vtable slots: CMFCVisualManagerOffice2007[74] */
/* 0082cf89  FUN_0082cf89  20 bytes, 0 callers */

void FUN_0082cf89(LPRECT param_1)

{
  OffsetRect(param_1,-3,0);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[70] */
/* 0082cf9d  AlwaysHighlight3DTabs  12 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManagerOffice2007::AlwaysHighlight3DTabs(void)const 
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCVisualManagerOffice2007::AlwaysHighlight3DTabs(CMFCVisualManagerOffice2007 *this)

{
  int iVar1;
  
  iVar1 = CanDrawImage(this);
  return (uint)(iVar1 != 0);
}




/* vtable slots: CMFCVisualManagerOffice2007[202] */
/* 0082d2e3  FUN_0082d2e3  2667 bytes, 0 callers */

void FUN_0082d2e3(void)

{
  code *pcVar1;
  int in_ECX;
  int iVar2;
  CMFCToolTipInfo local_38 [52];
  
  *(undefined4 *)(in_ECX + 0x8fb4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fb8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fbc) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fc0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fc4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fc8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fcc) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fd0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fd4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fd8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fdc) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fe0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fe4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fe8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8fec) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8ff0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8ff4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8ff8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8ffc) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x9000) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x9004) = 0xffffffff;
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1f68) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_007e7dd4();
  FUN_007e7dd4();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1810) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1988) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1b00) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_007e7dd4();
  FUN_007e7dd4();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1c78) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1df0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f40));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f38));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f28));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f48));
  *(undefined4 *)(in_ECX + 0x903c) = 0xffffffff;
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f30));
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x20e0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2258) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x23d0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2548) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x26c0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2838) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x29b0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_007e7dd4();
  FUN_007e7dd4();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2b28) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2ca0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2e18) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x2f90) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x3108) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x3280) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x33f8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x3570) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x36e8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x3860) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x39d8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x3b50) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  *(undefined4 *)(in_ECX + 0x9064) = 0xff000000;
  *(undefined4 *)(in_ECX + 0x906c) = 0xff000000;
  *(undefined4 *)(in_ECX + 0x9070) = 0xff000000;
  *(undefined4 *)(in_ECX + 0x9068) = 0xff000000;
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f08));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f10));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f18));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x8f20));
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x3cc8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x3e40) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x3fb8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4130) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x42a8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4420) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4598) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4710) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4888) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4a00) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4b78) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_007e7dd4();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4cf0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4e68) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x4fe0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x5158) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x52d0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x5448) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x55c0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x5738) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x58b0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x5a28) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x5ba0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x5d18) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x5e90) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x6008) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x6180) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x62f8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x6470) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x65e8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x6760) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x68d8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x6a50) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_007e7dd4();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x6bc8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x6d40) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x6eb8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_007e7dd4();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7030) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x71a8) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7320) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7498) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7610) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7788) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7900) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7a78) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7bf0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7d68) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x7ee0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x8058) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x81d0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x8348) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x84c0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x8638) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x87b0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  *(undefined4 *)(in_ECX + 0x90a0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x90a4) = 0xffffffff;
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x8928) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  FUN_0082dd4e();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x8aa0) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x8c18) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  FUN_0082dd4e();
  FUN_0082dd4e();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x8d90) + 0x28);
  guard_check_icall();
  (*pcVar1)();
  iVar2 = 7;
  do {
    FUN_0082d26f();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = FUN_007c2511();
  *(undefined4 *)(in_ECX + 0x9040) = *(undefined4 *)(iVar2 + 0x6c);
  *(undefined4 *)(in_ECX + 0x218) = 0;
  CMFCToolTipInfo::CMFCToolTipInfo(local_38);
  CMFCToolTipInfo::operator=((CMFCToolTipInfo *)(in_ECX + 0xc004),local_38);
  RemoveAll();
  *(undefined4 *)(in_ECX + 0x9134) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x9138) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x913c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x9140) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x20c) = 0;
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[51] */
/* 0082ecdd  GetCaptionBarTextColor  38 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::GetCaptionBarTextColor(class CMFCCaptionBar *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2007::GetCaptionBarTextColor
          (CMFCVisualManagerOffice2007 *this,CMFCCaptionBar *param_1)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    uVar2 = CMFCVisualManager::GetCaptionBarTextColor((CMFCVisualManager *)this,param_1);
  }
  else {
    uVar2 = *(ulong *)(this + 0x9040);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[37] */
/* 0082ed0a  GetHighlightedMenuItemTextColor  38 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::GetHighlightedMenuItemTextColor(class CMFCToolBarMenuButton *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2007::GetHighlightedMenuItemTextColor
          (CMFCVisualManagerOffice2007 *this,CMFCToolBarMenuButton *param_1)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    uVar2 = CMFCVisualManagerOfficeXP::GetHighlightedMenuItemTextColor
                      ((CMFCVisualManagerOfficeXP *)this,param_1);
  }
  else {
    uVar2 = *(ulong *)(this + 0x8fa0);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[39] */
/* 0082ed75  GetMenuItemTextColor  58 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall CMFCVisualManagerOffice2007::GetMenuItemTextColor(class
   CMFCToolBarMenuButton *,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2007::GetMenuItemTextColor
          (CMFCVisualManagerOffice2007 *this,CMFCToolBarMenuButton *param_1,int param_2,int param_3)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    uVar2 = CMFCVisualManager::GetMenuItemTextColor
                      ((CMFCVisualManager *)this,param_1,param_2,param_3);
  }
  else if (param_3 == 0) {
    uVar2 = *(ulong *)(this + 0x8f9c);
  }
  else {
    uVar2 = *(ulong *)(this + 0x8fa4);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[130] */
/* 0082edaf  FUN_0082edaf  39 bytes, 0 callers */

void FUN_0082edaf(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = (uint)(param_2 != 0) * 8;
  uVar2 = *(undefined4 *)(iVar1 + 0x220 + in_ECX);
  *param_1 = *(undefined4 *)(iVar1 + 0x21c + in_ECX);
  param_1[1] = uVar2;
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[177] */
/* 0082ee2e  GetRibbonEditBackgroundColor  73 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::GetRibbonEditBackgroundColor(class CMFCRibbonRichEditCtrl
   *,int,int,int)
    public: virtual unsigned long __thiscall
   CMFCVisualManagerWindows7::GetRibbonEditBackgroundColor(class CMFCRibbonRichEditCtrl
   *,int,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong GetRibbonEditBackgroundColor
                (CMFCRibbonRichEditCtrl *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  ulong uVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    uVar2 = CMFCVisualManager::GetRibbonEditBackgroundColor
                      ((CMFCVisualManager *)in_ECX,param_1,param_2,param_3,param_4);
  }
  else {
    uVar2 = *(ulong *)(in_ECX + 0x90a8);
    if (param_4 == 0) {
      if (param_2 != 0) {
        uVar2 = *(ulong *)(in_ECX + 0x90b0);
      }
    }
    else {
      uVar2 = *(ulong *)(in_ECX + 0x90ac);
    }
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[175] */
/* 0082ee77  FUN_0082ee77  204 bytes, 0 callers */

int FUN_0082ee77(CMFCRibbonBaseElement *param_1)

{
  code *pcVar1;
  int iVar2;
  CObject *this;
  int iVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*(int *)param_1 + 0xdc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*(int *)param_1 + 0xd0);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        iVar2 = *(int *)(in_ECX + 0x9134);
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x9138);
      }
      if ((((*(int *)(in_ECX + 0x9140) != -1) && (*(int *)(in_ECX + 0x913c) != -1)) &&
          (this = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonStatusBar_009a090c,
                                     *(CObject **)(param_1 + 0x84)), this != (CObject *)0x0)) &&
         (iVar3 = CMFCRibbonStatusBar::IsExtendedElement((CMFCRibbonStatusBar *)this,param_1),
         iVar3 == 0)) {
        pcVar1 = *(code **)(*(int *)param_1 + 0xd0);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) {
          iVar2 = *(int *)(in_ECX + 0x913c);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x9140);
        }
      }
      if (iVar2 != -1) {
        return iVar2;
      }
    }
  }
  iVar2 = FUN_007f3282(param_1);
  return iVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[170] */
/* 0082ef43  FUN_0082ef43  201 bytes, 0 callers */

undefined4 FUN_0082ef43(int *param_1)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    return *(undefined4 *)(in_ECX + 0xa4);
  }
  if (param_1 != (int *)0x0) {
    pcVar1 = *(code **)(*param_1 + 0x1c8);
    guard_check_icall();
    pCVar3 = (CObject *)(*pcVar1)();
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenuBar_009a1a6c,pCVar3);
    if (((pCVar3 != (CObject *)0x0) && (iVar2 = FUN_0082f53f(), iVar2 == 0)) &&
       (*(int *)(pCVar3 + 0xdd8) == 0)) {
      if (*(int *)(pCVar3 + 0xde0) == 0) {
        if (*(int *)(pCVar3 + 0xeb4) != 0) {
          return 0;
        }
        if (*(int *)(pCVar3 + 0xde8) == 0) {
          if ((*(int *)(pCVar3 + 0xea4) != 0) && (*(int *)(in_ECX + 0xc000) != 10)) {
            return 0;
          }
        }
        else if (*(int *)(in_ECX + 0x86cc) != 0) {
          return *(undefined4 *)(in_ECX + 0x8780);
        }
      }
      else if (*(int *)(in_ECX + 0x8554) != 0) {
        return *(undefined4 *)(in_ECX + 0x8608);
      }
    }
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x2f4);
  guard_check_icall();
  uVar4 = (*pcVar1)();
  return uVar4;
}




/* vtable slots: CMFCVisualManagerOffice2007[149] */
/* 0082f00c  FUN_0082f00c  17 bytes, 0 callers */

byte FUN_0082f00c(void)

{
  int in_ECX;
  
  return -(*(int *)(in_ECX + 0xc000) != 10) & 0xd;
}




/* vtable slots: CMFCVisualManagerOffice2007[150] */
/* 0082f01d  GetRibbonQuickAccessToolBarRightMargin  33 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall
   CMFCVisualManagerOffice2007::GetRibbonQuickAccessToolBarRightMargin(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
CMFCVisualManagerOffice2007::GetRibbonQuickAccessToolBarRightMargin
          (CMFCVisualManagerOffice2007 *this)

{
  int iVar1;
  
  iVar1 = CanDrawImage(this);
  if ((iVar1 != 0) && (*(int *)(this + 0x404c) != 0)) {
    return *(int *)(this + 0x4108);
  }
  return 0;
}




/* vtable slots: CMFCVisualManagerOffice2007[151] */
/* 0082f03e  FUN_0082f03e  27 bytes, 0 callers */

undefined4 FUN_0082f03e(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    uVar1 = *(undefined4 *)(in_ECX + 0x9084);
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 0x908c);
  }
  return uVar1;
}




/* vtable slots: CMFCVisualManagerOffice2007[176] */
/* 0082f059  GetRibbonStatusBarTextColor  38 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::GetCaptionBarTextColor(class CMFCCaptionBar *)
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::GetHighlightedMenuItemTextColor(class CMFCToolBarMenuButton *)
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::GetRibbonStatusBarTextColor(class CMFCRibbonStatusBar *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2007::GetRibbonStatusBarTextColor
          (CMFCVisualManagerOffice2007 *this,CMFCRibbonStatusBar *param_1)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    uVar2 = FUN_007f3155(param_1);
  }
  else {
    uVar2 = *(ulong *)(this + 0x8fa8);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[0] */
/* 0082f07f  FUN_0082f07f  6 bytes, 0 callers */

undefined ** FUN_0082f07f(void)

{
  return &PTR_s_CMFCVisualManagerOffice2007_00990284;
}




/* vtable slots: CMFCVisualManagerOffice2007[190] */
/* 0082f085  GetShowAllMenuItemsHeight  59 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManagerOffice2007::GetShowAllMenuItemsHeight(class CDC
   *,class CSize const &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
CMFCVisualManagerOffice2007::GetShowAllMenuItemsHeight
          (CMFCVisualManagerOffice2007 *this,CDC *param_1,CSize *param_2)

{
  int iVar1;
  
  iVar1 = CanDrawImage(this);
  if ((iVar1 == 0) || (*(int *)(this + 0x2bbc) == 0)) {
    iVar1 = CMFCVisualManagerOffice2003::GetShowAllMenuItemsHeight
                      ((CMFCVisualManagerOffice2003 *)this,param_1,param_2);
  }
  else {
    iVar1 = (*(int *)(this + 0x2c5c) - *(int *)(this + 0x2c54)) + 6;
  }
  return iVar1;
}




/* vtable slots: CMFCVisualManagerOffice2007[118] */
/* 0082f0c0  GetSmartDockingTheme  38 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual enum AFX_SMARTDOCK_THEME __thiscall
   CMFCVisualManagerOffice2007::GetSmartDockingTheme(void)
    public: virtual enum AFX_SMARTDOCK_THEME __thiscall
   CMFCVisualManagerVS2008::GetSmartDockingTheme(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 GetSmartDockingTheme(void)

{
  int iVar1;
  AFX_GLOBAL_DATA *this;
  
  iVar1 = FUN_007c2511();
  if (8 < *(int *)(iVar1 + 0x1ac)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar1 == 0) {
      return 2;
    }
  }
  return 1;
}




/* vtable slots: CMFCVisualManagerOffice2007[24] */
/* 0082f0e6  FUN_0082f0e6  78 bytes, 0 callers */

int FUN_0082f0e6(undefined4 param_1,int param_2)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    iVar1 = FUN_007f3595(param_1,param_2);
  }
  else {
    if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if ((*(uint *)(param_2 + 0x14) & 0x4000000) == 0) {
      iVar1 = *(int *)(param_2 + 0x24);
      if (iVar1 == -1) {
        iVar1 = *(int *)(in_ECX + 0x8fa8);
      }
    }
    else {
      iVar1 = *(int *)(in_ECX + 0x8fac);
    }
  }
  return iVar1;
}




/* vtable slots: CMFCVisualManagerOffice2007[67] */
/* 0082f1ed  FUN_0082f1ed  161 bytes, 0 callers */

void FUN_0082f1ed(int *param_1,undefined4 param_2,int *param_3,int *param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  code *pcVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008a9598(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  else {
    FUN_008a9598(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    pcVar1 = *(code **)(*param_1 + 0x280);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((iVar2 != 0) && (param_1[0x4d] == 0)) {
      if (*(int *)(in_ECX + 0x9064) != -0x1000000) {
        *param_3 = *(int *)(in_ECX + 0x9064);
      }
      if (*(int *)(in_ECX + 0x9068) != -0x1000000) {
        *param_4 = *(int *)(in_ECX + 0x9068);
      }
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[72] */
/* 0082f28e  FUN_0082f28e  206 bytes, 0 callers */

int FUN_0082f28e(int *param_1)

{
  code *pcVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  int local_c;
  int local_8;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x280);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      local_c = 0x3838;
      local_8 = 0x377c;
    }
    else {
      local_c = 0x3b28;
      local_8 = 0x3a6c;
    }
    pcVar1 = *(code **)(*param_1 + 0x288);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*param_1 + 0x2a8);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        pcVar1 = *(code **)(*param_1 + 0x28c);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) {
          pcVar1 = *(code **)(*param_1 + 0x290);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if ((iVar2 == 0) && (*(int *)(in_ECX + local_8) != 0)) {
            return *(int *)(in_ECX + local_c) / 2;
          }
        }
      }
    }
  }
  return 0;
}




/* vtable slots: CMFCVisualManagerOffice2007[71] */
/* 0082f35c  FUN_0082f35c  113 bytes, 0 callers */

undefined4 FUN_0082f35c(int *param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar2 != 0) && (param_1[0x4d] == 0)) {
    pcVar1 = *(code **)(*param_1 + 0x288);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*param_1 + 0x1dc);
      guard_check_icall(param_2);
      iVar2 = (*pcVar1)();
      if (iVar2 == -1) {
        if (param_3 != 0) {
          return *(undefined4 *)(in_ECX + 0x906c);
        }
        return *(undefined4 *)(in_ECX + 0x9070);
      }
    }
  }
  return 0xffffffff;
}




/* vtable slots: CMFCVisualManagerOffice2007[181] */
/* 0082f3ec  GetToolTipInfo  61 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManagerOffice2007::GetToolTipInfo(class CMFCToolTipInfo
   &,unsigned int)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCVisualManagerOffice2007::GetToolTipInfo
          (CMFCVisualManagerOffice2007 *this,CMFCToolTipInfo *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = CanDrawImage(this);
  if ((iVar1 == 0) || (*(int *)(this + 0x218) == 0)) {
    iVar1 = CMFCVisualManagerOffice2003::GetToolTipInfo
                      ((CMFCVisualManagerOffice2003 *)this,param_1,0xffffffff);
  }
  else {
    CMFCToolTipInfo::operator=(param_1,(CMFCToolTipInfo *)(this + 0xc004));
    iVar1 = 1;
  }
  return iVar1;
}




/* vtable slots: CMFCVisualManagerOffice2007[45] */
/* 0082f429  FUN_0082f429  229 bytes, 0 callers */

undefined4 FUN_0082f429(int *param_1,int param_2)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar3 == 0) {
    uVar4 = FUN_008a3f50(param_1,param_2);
    return uVar4;
  }
  if (DAT_00a127ac == 0) {
LAB_0082f476:
    if ((param_1[9] & 0x40000U) != 0) goto LAB_0082f47f;
LAB_0082f484:
    bVar2 = false;
  }
  else {
    pcVar1 = *(code **)(*param_1 + 0x60);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      if (DAT_00a127ac == 0) goto LAB_0082f476;
      goto LAB_0082f484;
    }
LAB_0082f47f:
    bVar2 = true;
  }
  if ((param_1[0x1b] == 0) || (iVar3 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00), iVar3 == 0)) {
    if (bVar2) {
      return *(undefined4 *)(in_ECX + 0x8f98);
    }
    if ((param_2 != 2) && (param_2 != 1)) {
      return *(undefined4 *)(in_ECX + 0x8f90);
    }
    return *(undefined4 *)(in_ECX + 0x8f94);
  }
  if (DAT_00a127ac == 0) {
    if (bVar2) {
      return *(undefined4 *)(in_ECX + 0x8f8c);
    }
    if ((param_2 != 2) && (param_2 != 1)) {
      pcVar1 = *(code **)(*param_1 + 0x70);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) goto LAB_0082f4a4;
    }
    uVar4 = *(undefined4 *)(in_ECX + 0x8f88);
  }
  else {
LAB_0082f4a4:
    uVar4 = *(undefined4 *)(in_ECX + 0x8f84);
  }
  return uVar4;
}




/* vtable slots: CMFCVisualManagerOffice2007[49] */
/* 0082f515  GetToolbarDisabledTextColor  28 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::GetToolbarDisabledTextColor(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2007::GetToolbarDisabledTextColor(CMFCVisualManagerOffice2007 *this)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 != 0) {
    return *(ulong *)(this + 0x8f98);
  }
  uVar2 = FUN_007f380f();
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[38] */
/* 0082f531  IsHighlightWholeMenuItem  9 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManagerOffice2007::IsHighlightWholeMenuItem(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
CMFCVisualManagerOffice2007::IsHighlightWholeMenuItem(CMFCVisualManagerOffice2007 *this)

{
  CanDrawImage(this);
  return 1;
}




/* vtable slots: CMFCVisualManagerOffice2007[125] */
/* 0082f56d  IsOwnerDrawCaption  30 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManagerOffice2007::IsOwnerDrawCaption(void)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCVisualManagerOffice2007::IsOwnerDrawCaption(CMFCVisualManagerOffice2007 *this)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 != 0) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsDwmCompositionEnabled(this_00);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCVisualManagerOffice2007[44] */
/* 0082f58b  FUN_0082f58b  8 bytes, 0 callers */

undefined4 FUN_0082f58b(void)

{
  CMFCVisualManagerOffice2007 *in_ECX;
  
  CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  return 0;
}




/* vtable slots: CMFCVisualManagerOffice2007[17] */
/* 0082f64d  FUN_0082f64d  655 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0082f64d(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 CObject *param_7)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int iVar4;
  int *piVar5;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined1 local_24 [4];
  int local_20;
  undefined1 local_1c [4];
  int local_18;
  CMFCVisualManagerOffice2007 *local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  pCVar3 = param_7;
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_14 = in_ECX;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  iVar4 = param_6;
  if ((iVar2 == 0) ||
     (((pCVar3 != (CObject *)0x0 && (*(int *)(pCVar3 + 0x8c) != 0)) ||
      (*(int *)(in_ECX + 0x234) == 0)))) {
    FUN_008a9b2e(param_1,param_2,param_3,param_4,param_5,param_6,pCVar3);
    return;
  }
  local_10 = *(int *)(in_ECX + 0x284);
  local_c = *(int *)(in_ECX + 0x288);
  if ((local_10 == 0) && (local_c == 0)) {
    return;
  }
  if (param_6 == 0) {
    param_3 = param_5 - local_c;
  }
  else {
    param_2 = param_4 - local_10;
  }
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,pCVar3);
  if (pCVar3 == (CObject *)0x0) {
    if (iVar4 == 0) goto LAB_0082f7cc;
  }
  else {
    if (iVar4 == 0) {
      if (DAT_00a127b4 == 0) {
        piVar5 = (int *)FUN_007c23d4(local_1c);
        iVar4 = *piVar5;
      }
      else {
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x358);
        guard_check_icall();
        iVar4 = (*pcVar1)();
      }
      piVar5 = (int *)FUN_007fe0a1(local_1c);
      if ((iVar4 - *piVar5) / 2 < 0) {
        iVar4 = 0;
      }
      else {
        piVar5 = (int *)FUN_007fe0a1(local_24);
        iVar4 = -((iVar4 - *piVar5) / 2);
      }
      InflateRect((LPRECT)&param_2,iVar4,0);
LAB_0082f7cc:
      local_20 = ((param_4 - param_2) - local_10) / local_10;
      local_18 = (param_4 - local_20 * local_10) - param_2;
      goto LAB_0082f7ea;
    }
    if (DAT_00a127b4 == 0) {
      iVar4 = FUN_007c23d4(local_1c);
      iVar4 = *(int *)(iVar4 + 4);
    }
    else {
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x354);
      guard_check_icall();
      iVar4 = (*pcVar1)();
    }
    iVar2 = FUN_007fe0a1(local_1c);
    if ((iVar4 - *(int *)(iVar2 + 4)) / 2 < 0) {
      iVar4 = 0;
    }
    else {
      iVar2 = FUN_007fe0a1(local_24);
      iVar4 = -((iVar4 - *(int *)(iVar2 + 4)) / 2);
    }
    InflateRect((LPRECT)&param_2,0,iVar4);
  }
  local_20 = ((param_5 - param_3) - local_c) / local_c;
  local_18 = (param_5 - local_20 * local_c) - param_3;
LAB_0082f7ea:
  local_18 = local_18 / 2;
  if (0 < local_20) {
    local_14 = local_14 + 0x230;
    do {
      if (param_6 == 0) {
        iVar4 = param_2 + local_18;
        iVar2 = param_3;
      }
      else {
        iVar4 = param_2;
        iVar2 = param_3 + local_18;
      }
      FUN_007e94b8(param_1,iVar4,iVar2,local_10 + iVar4,local_c + iVar2,0,0,0,0,0,0,0,0xff);
      iVar4 = local_c;
      if (param_6 == 0) {
        iVar4 = local_10;
      }
      local_18 = local_18 + iVar4;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[34] */
/* 0082f8dc  FUN_0082f8dc  348 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0082f8dc(CDC *param_1,CObject *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  BOOL BVar4;
  uint uVar5;
  CMFCVisualManagerOffice2007 *in_ECX;
  CDrawingManager local_20 [8];
  CObject *local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x82f8e8;
  local_14 = param_1;
  local_18 = param_2;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    CMFCVisualManagerOffice2003::OnDrawButtonBorder();
  }
  else if ((((param_7 == 1) || (param_7 == 2)) && (*(int *)(in_ECX + 0x150) != 0)) &&
          (((DAT_00a00b24 != 0 && (DAT_00a127ac == 0)) &&
           (pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,
                                        param_2), pCVar3 != (CObject *)0x0)))) {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x70);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      if ((*(int *)(pCVar3 + 0x6c) != 0) &&
         (iVar2 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938), iVar2 != 0)) {
        return;
      }
      iVar2 = *(int *)(pCVar3 + 0x8c);
      if (((iVar2 != 0) &&
          (((BVar4 = IsWindowVisible(*(HWND *)(iVar2 + 0x20)), BVar4 != 0 ||
            (*(int *)(iVar2 + 0xf48) != 0)) && (*(int *)(iVar2 + 0xf44) == 0)))) &&
         (uVar5 = FUN_00797acc(), (uVar5 & 0x400000) == 0)) {
        pcVar1 = *(code **)(*(int *)in_ECX + 0x30c);
        guard_check_icall(pCVar3,&param_3);
        (*pcVar1)();
        CDrawingManager::CDrawingManager(local_20,local_14);
        local_8 = 0;
        FUN_00816e2b(param_3,param_4,param_5,param_6,*(undefined4 *)(in_ECX + 0x7c),100,0x4b,0,0,
                     *(undefined4 *)(in_ECX + 0xa8),1);
        FUN_0081510b();
      }
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[35] */
/* 0082fa38  FUN_0082fa38  170 bytes, 0 callers */

void FUN_0082fa38(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,int param_8)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined1 local_c [8];
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008a469c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    iVar1 = FUN_0079efbc(in_ECX + 0x144);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if (param_8 == 0) {
      FUN_0079ec58(local_c,param_3 + 2,param_4);
      param_3 = param_5 + -2;
    }
    else {
      FUN_0079ec58(local_c,param_3,param_4 + 2);
      param_4 = param_6 + -2;
    }
    CDC::LineTo(param_1,param_3,param_4);
    FUN_0079efbc(iVar1);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[52] */
/* 0082fae3  FUN_0082fae3  166 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0082fae3(CDC *param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,
                 LONG param_6)

{
  ulong uVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  CDrawingManager local_24 [12];
  undefined4 local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x82faef;
  local_18 = param_2;
  local_14 = param_1;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008a4783(local_14,local_18,param_3,param_4,param_5,param_6);
  }
  else {
    CDrawingManager::CDrawingManager(local_24,param_1);
    local_8 = 0;
    iVar2 = FUN_007c2511();
    FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(iVar2 + 0x54),0xffffff,1,0,0);
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x60);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(local_14,(tagRECT *)&param_3,*(ulong *)(iVar2 + 0x60),uVar1);
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[105] */
/* 0082fb89  FUN_0082fb89  229 bytes, 0 callers */

void FUN_0082fb89(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7,int param_8,int param_9)

{
  code *pcVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_8;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008a9f81(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  else {
    local_8 = param_6 * 4;
    if (param_9 == 0) {
      local_8 = local_8 + 3;
    }
    else if (param_7 != 0) {
      if (param_8 == 0) {
        local_8 = local_8 + 1;
      }
      else {
        local_8 = local_8 + 2;
      }
    }
    iVar2 = FUN_007c2511();
    if (*(int *)(iVar2 + 0x198) != 0) {
      pcVar1 = *(code **)(*(int *)(in_ECX + 0x7320) + 0x24);
      guard_check_icall();
      (*pcVar1)();
    }
    uVar5 = 0xff;
    uVar4 = 1;
    uVar3 = 1;
    iVar2 = *(int *)(in_ECX + 0x7320);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,1,1,local_8,0xff);
    (**(code **)(iVar2 + 0x18))();
    iVar2 = FUN_007c2511();
    if (*(int *)(iVar2 + 0x198) != 0) {
      pcVar1 = *(code **)(*(int *)(in_ECX + 0x7320) + 0x24);
      guard_check_icall(param_1,param_2,param_3,param_4,param_5,uVar3,uVar4,local_8,uVar5);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[28] */
/* 0082fc6e  OnDrawComboBorder  199 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2007::OnDrawComboBorder(class CDC *,class
   CRect,int,int,int,class CMFCToolBarComboBoxButton *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2007::OnDrawComboBorder
          (CMFCVisualManagerOffice2007 *this,CDC *param_1,LONG param_3,LONG param_4,LONG param_5,
          LONG param_6,int param_7,int param_8,int param_9,undefined4 param_10)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  CDrawingManager local_1c [8];
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uVar1 = param_10;
  uStack_4 = 0xc;
  local_8 = 0x82fc7a;
  local_14 = param_1;
  iVar2 = CanDrawImage(this);
  if (iVar2 == 0) {
    FUN_008a9fe8(local_14,param_3,param_4,param_5,param_6,param_7,param_8,param_9,uVar1);
  }
  else {
    InflateRect((LPRECT)&param_3,-1,-1);
    uVar3 = *(ulong *)(this + 0x8fc4);
    if (param_7 == 0) {
      if ((param_9 != 0) || (param_8 != 0)) {
        if (param_8 == 0) {
          uVar3 = *(ulong *)(this + 0x8fd0);
        }
        else {
          uVar3 = *(ulong *)(this + 0x8fcc);
        }
      }
    }
    else {
      uVar3 = *(ulong *)(this + 0x8fc8);
    }
    if (DAT_00a12704 == 0) {
      CDC::Draw3dRect(param_1,(tagRECT *)&param_3,uVar3,uVar3);
    }
    else {
      CDrawingManager::CDrawingManager(local_1c,param_1);
      local_8 = 0;
      FUN_00816b6a(&param_3,0xffffffff,uVar3);
      FUN_0081510b();
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[27] */
/* 0082fd35  FUN_0082fd35  725 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0082fd35(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  int iVar5;
  CMFCVisualManagerOffice2007 *pCVar6;
  CDrawingManager local_34 [8];
  CDrawingManager local_2c [8];
  undefined4 local_24;
  CMFCVisualManagerOffice2007 *local_20;
  int local_1c;
  CDC *local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  iVar5 = param_9;
  uStack_4 = 0x24;
  local_8 = 0x82fd41;
  local_18 = param_1;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008aa081(local_18,param_2,param_3,param_4,param_5,param_6,param_7,param_8,iVar5);
    return;
  }
  bVar1 = true;
  if ((iVar5 == 0) || (*(int *)(iVar5 + 0x84) == 0)) {
    bVar1 = false;
  }
  if ((param_8 == 0) && (param_7 == 0)) {
    local_1c = 0;
  }
  else {
    local_1c = 1;
  }
  local_20 = in_ECX + (-(uint)bVar1 & 0x69c0) + 0x1f68;
  if (*(int *)(local_20 + 0x94) != 0) {
    param_3 = param_3 + -1;
    uVar4 = 0;
    param_4 = param_4 + 1;
    param_5 = param_5 + 1;
    if (param_6 == 0) {
      if (param_7 == 0) {
        if (param_8 != 0) {
          uVar4 = 1;
        }
      }
      else {
        uVar4 = 2;
      }
    }
    else {
      uVar4 = 3;
    }
    iVar5 = *(int *)local_20;
    guard_check_icall(local_18,param_2,param_3,param_4,param_5,uVar4,0xff);
    (**(code **)(iVar5 + 0x10))();
    param_3 = param_3 + 1;
    param_4 = param_4 + -1;
    param_5 = param_5 + -1;
    iVar5 = param_6;
    goto LAB_0082ffdb;
  }
  if (bVar1) {
    pCVar6 = *(CMFCVisualManagerOffice2007 **)(in_ECX + 0x90cc);
    uVar4 = *(undefined4 *)(in_ECX + 0x90d0);
    uVar3 = *(ulong *)(in_ECX + 0x90d4);
  }
  else {
    pCVar6 = *(CMFCVisualManagerOffice2007 **)(in_ECX + 0x8fd4);
    uVar4 = *(undefined4 *)(in_ECX + 0x8fd8);
    uVar3 = *(ulong *)(in_ECX + 0x8fdc);
  }
  if (param_6 == 0) {
    if (local_1c == 0) goto LAB_0082fe91;
    if (param_7 == 0) {
      if (bVar1) {
        pCVar6 = *(CMFCVisualManagerOffice2007 **)(in_ECX + 0x90f0);
        uVar4 = *(undefined4 *)(in_ECX + 0x90f4);
        uVar3 = *(ulong *)(in_ECX + 0x90f8);
      }
      else {
        pCVar6 = *(CMFCVisualManagerOffice2007 **)(in_ECX + 0x8ff8);
        uVar4 = *(undefined4 *)(in_ECX + 0x8ffc);
        uVar3 = *(ulong *)(in_ECX + 0x9000);
      }
    }
    else {
      if (!bVar1) {
        pCVar6 = *(CMFCVisualManagerOffice2007 **)(in_ECX + 0x8fec);
        uVar4 = *(undefined4 *)(in_ECX + 0x8ff0);
        uVar3 = *(ulong *)(in_ECX + 0x8ff4);
        goto LAB_0082fe91;
      }
      pCVar6 = *(CMFCVisualManagerOffice2007 **)(in_ECX + 0x90e4);
      uVar4 = *(undefined4 *)(in_ECX + 0x90e8);
      uVar3 = *(ulong *)(in_ECX + 0x90ec);
    }
LAB_0082feac:
    param_3 = param_3 + -1;
    param_4 = param_4 + 1;
    param_5 = param_5 + 1;
LAB_0082feb5:
    local_20 = pCVar6;
    local_14 = uVar4;
    if (DAT_00a12704 == 0) {
      CDC::Draw3dRect(local_18,(tagRECT *)&param_2,uVar3,uVar3);
    }
    else {
      CDrawingManager::CDrawingManager(local_2c,local_18);
      local_8 = 0;
      FUN_00816b6a(&param_2,0xffffffff,uVar3);
      local_8 = 0xffffffff;
      FUN_0081510b();
    }
    if (param_6 != 0) goto LAB_0082ff24;
    param_3 = param_3 + 1;
    param_4 = param_4 + -1;
    param_5 = param_5 + -1;
    uVar4 = local_14;
    pCVar6 = local_20;
    if (local_1c != 0) {
      param_2 = param_2 + 1;
    }
  }
  else {
    if (bVar1) {
      pCVar6 = *(CMFCVisualManagerOffice2007 **)(in_ECX + 0x90d8);
      uVar4 = *(undefined4 *)(in_ECX + 0x90dc);
      uVar3 = *(ulong *)(in_ECX + 0x90e0);
      goto LAB_0082feb5;
    }
    pCVar6 = *(CMFCVisualManagerOffice2007 **)(in_ECX + 0x8fe0);
    uVar4 = *(undefined4 *)(in_ECX + 0x8fe4);
    uVar3 = *(ulong *)(in_ECX + 0x8fe8);
LAB_0082fe91:
    if (bVar1) {
LAB_0082fea8:
      if (param_6 == 0) goto LAB_0082feac;
      goto LAB_0082feb5;
    }
    if (param_6 == 0) goto LAB_0082feac;
    local_20 = (CMFCVisualManagerOffice2007 *)uVar4;
    local_14 = pCVar6;
    if (uVar3 != 0xffffffff) goto LAB_0082fea8;
LAB_0082ff24:
    param_3 = param_3 + 1;
    param_4 = param_4 + -1;
    param_5 = param_5 + -1;
  }
  iVar5 = param_6;
  CDrawingManager::CDrawingManager(local_34,local_18);
  local_8 = 1;
  FUN_00817861(param_2,param_3,param_4,param_5,pCVar6,uVar4,1,0,0);
  if (iVar5 == 0) {
    if (local_1c != 0) {
      param_2 = param_2 + -1;
    }
  }
  else {
    param_3 = param_3 + -1;
    param_4 = param_4 + 1;
    param_5 = param_5 + 1;
  }
  local_8 = 0xffffffff;
  FUN_0081510b();
LAB_0082ffdb:
  param_5 = param_5 + -2;
  local_24 = 0;
  local_20 = (CMFCVisualManagerOffice2007 *)0x0;
  FUN_00814d1c(local_18,0,&param_2,iVar5 != 0,&local_24);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[154] */
/* 0083000a  FUN_0083000a  136 bytes, 0 callers */

void FUN_0083000a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar1 == 0) || (*(int *)(in_ECX + 0x1784) == 0)) {
    FUN_007f433e(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,param_6 != 0,1,1,0,0,0,0,0xff);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[29] */
/* 00830092  OnDrawEditBorder  177 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2007::OnDrawEditBorder(class CDC *,class
   CRect,int,int,class CMFCToolBarEditBoxButton *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2007::OnDrawEditBorder
          (CMFCVisualManagerOffice2007 *this,CDC *param_1,LONG param_3,LONG param_4,LONG param_5,
          LONG param_6,int param_7,int param_8,undefined4 param_9)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  CDrawingManager local_1c [8];
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uVar1 = param_9;
  uStack_4 = 0xc;
  local_8 = 0x83009e;
  local_14 = param_1;
  iVar2 = CanDrawImage(this);
  if (iVar2 == 0) {
    CMFCVisualManagerOfficeXP::OnDrawEditBorder
              ((CMFCVisualManagerOfficeXP *)this,local_14,param_3,param_4,param_5,param_6,param_7,
               param_8,uVar1);
  }
  else {
    InflateRect((LPRECT)&param_3,-1,-1);
    uVar3 = *(ulong *)(this + 0x8fb4);
    if (param_7 == 0) {
      if (param_8 != 0) {
        uVar3 = *(ulong *)(this + 0x8fbc);
      }
    }
    else {
      uVar3 = *(ulong *)(this + 0x8fb8);
    }
    if (DAT_00a12704 == 0) {
      CDC::Draw3dRect(param_1,(tagRECT *)&param_3,uVar3,uVar3);
    }
    else {
      CDrawingManager::CDrawingManager(local_1c,param_1);
      local_8 = 0;
      FUN_00816b6a(&param_3,0xffffffff,uVar3);
      FUN_0081510b();
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[84] */
/* 00830143  FUN_00830143  415 bytes, 0 callers */

void FUN_00830143(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008a4c37(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  }
  else {
    iVar1 = FUN_0079efbc(in_ECX + 0x134);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_7,param_6 - param_4,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_5 - param_3,param_8,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_5 - param_9,param_4,param_9,param_6 - param_4,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_6 - param_10,param_5 - param_3,param_10,0xf00021);
    InflateRect((LPRECT)&param_7,-2,-2);
    InflateRect((LPRECT)&param_3,-2,-2);
    iVar2 = FUN_007c2511();
    FUN_0079efbc(iVar2 + 0xd0);
    PatBlt(*(HDC *)(param_1 + 4),param_3,param_4 + 1,param_7,(param_6 - param_4) + -1,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_4,(param_5 - param_3) + -2,param_8,0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_5 - param_9,param_4 + 1,param_9,(param_6 - param_4) + -1,
           0xf00021);
    PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_6 - param_10,(param_5 - param_3) + -2,param_10,
           0xf00021);
    FUN_0079efbc(iVar1);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[86] */
/* 008302e3  FUN_008302e3  370 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008302e3(undefined4 param_1,CDC *param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  int iVar3;
  undefined4 uVar4;
  CDrawingManager local_28 [8];
  undefined **local_20 [2];
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x8302ef;
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    OnDrawHeaderCtrlBorder(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    local_14 = *(undefined4 *)(in_ECX + 0x9010);
    uVar2 = *(undefined4 *)(in_ECX + 0x9008);
    uVar4 = *(undefined4 *)(in_ECX + 0x900c);
    if (param_4 == 0) {
      if (param_5 != 0) {
        uVar2 = *(undefined4 *)(in_ECX + 0x9014);
        uVar4 = *(undefined4 *)(in_ECX + 0x9018);
        local_14 = *(undefined4 *)(in_ECX + 0x901c);
      }
    }
    else {
      uVar2 = *(undefined4 *)(in_ECX + 0x9020);
      uVar4 = *(undefined4 *)(in_ECX + 0x9024);
      local_14 = *(undefined4 *)(in_ECX + 0x9028);
    }
    CDrawingManager::CDrawingManager(local_28,param_2);
    local_8 = 0;
    FUN_00817861(*param_3,param_3[1],param_3[2],param_3[3],uVar4,uVar2,1,0,0);
    local_8 = 0xffffffff;
    FUN_0081510b();
    FUN_0079df60(0,0,local_14);
    local_8 = 1;
    uVar2 = FUN_0079efbc(local_20);
    if ((param_4 == 0) && (param_5 == 0)) {
      FUN_0079ec58(local_18,param_3[2] + -1,param_3[1]);
      CDC::LineTo(param_2,param_3[2] + -1,param_3[3] + -1);
      iVar1 = param_3[3];
      iVar3 = *param_3 + -1;
    }
    else {
      FUN_0079ec58(local_28,param_3[2] + -1,param_3[1]);
      CDC::LineTo(param_2,param_3[2] + -1,param_3[3] + -1);
      CDC::LineTo(param_2,*param_3,param_3[3] + -1);
      iVar3 = *param_3;
      iVar1 = param_3[1];
    }
    CDC::LineTo(param_2,iVar3,iVar1 + -1);
    FUN_0079efbc(uVar2);
    local_20[0] = CPen::vftable;
    FUN_00416100();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[15] */
/* 00830455  FUN_00830455  542 bytes, 0 callers */

void FUN_00830455(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int *piVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  CObject *local_c;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) goto LAB_0083046b;
  if (param_2 == (int *)0x0) {
LAB_008305f1:
    local_c = (CObject *)0x0;
    piVar4 = param_2;
    if (param_2 != (int *)0x0) {
      do {
        if (piVar4[0x56] == 0) break;
        local_c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,
                                     *(CObject **)(piVar4[0x56] + 0x6c));
        piVar4 = (int *)FUN_0081d529();
      } while (piVar4 != (int *)0x0);
      if ((local_c != (CObject *)0x0) &&
         (iVar2 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938), iVar2 == 0)) {
LAB_0083046b:
        FUN_008aa3fe(param_1,param_2,param_3,param_4,param_5,param_6);
        return;
      }
    }
  }
  else {
    pcVar1 = *(code **)(*param_2 + 0x1c8);
    guard_check_icall();
    pCVar3 = (CObject *)(*pcVar1)();
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenuBar_009a1a6c,pCVar3);
    if (pCVar3 == (CObject *)0x0) goto LAB_008305f1;
    iVar2 = FUN_0082f53f();
    if (iVar2 == 0) {
      if (*(int *)(pCVar3 + 0xdd8) == 0) {
        if ((*(int *)(pCVar3 + 0xde0) != 0) && (*(int *)(in_ECX + 0x8554) != 0)) {
          iVar2 = *(int *)(in_ECX + 0x84c0);
          guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
          goto LAB_00830669;
        }
        if (*(int *)(pCVar3 + 0xeb4) == 0) {
          if ((*(int *)(pCVar3 + 0xde8) != 0) && (*(int *)(in_ECX + 0x86cc) != 0)) {
            iVar2 = *(int *)(in_ECX + 0x8638);
            guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
            goto LAB_00830669;
          }
          if (*(int *)(pCVar3 + 0xea4) == 0) goto LAB_008305f1;
        }
        if (*(int *)(in_ECX + 0xc000) != 10) {
          return;
        }
        iVar2 = *(int *)(in_ECX + 0x42a8);
        guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
        goto LAB_00830669;
      }
      goto LAB_008305f1;
    }
    if (*(int *)(in_ECX + 0x4efc) != 0) {
      iVar2 = *(int *)(in_ECX + 0x4e68);
      guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
      goto LAB_00830669;
    }
  }
  iVar2 = *(int *)(in_ECX + 0x2548);
  guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
LAB_00830669:
  (**(code **)(iVar2 + 0x14))();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[41] */
/* 00830673  FUN_00830673  255 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00830673(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  CMFCToolBarImages *this;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  this = (CMFCToolBarImages *)(in_ECX + (-(uint)(param_8 != 0) & 0x118) + 0x1298);
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar1 == 0) || (*(int *)(this + 4) == 0)) {
    FUN_007f479e(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    local_18.right = *(LONG *)(this + 0x54);
    local_18.bottom = *(LONG *)(this + 0x58);
    local_18.left = 0;
    local_18.top = 0;
    if ((*(uint *)(param_2 + 0x24) & 0x40000) != 0) {
      OffsetRect(&local_18,0,local_18.bottom);
    }
    iVar1 = FUN_007c2511();
    if (*(int *)(iVar1 + 0x198) != 0) {
      CMFCToolBarImages::Mirror(this);
    }
    FUN_007e94b8(param_1,param_3,param_4,param_5,param_6,0,1,1,local_18.left,local_18.top,
                 local_18.right,local_18.bottom,0xff);
    iVar1 = FUN_007c2511();
    if (*(int *)(iVar1 + 0x198) != 0) {
      CMFCToolBarImages::Mirror(this);
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[42] */
/* 00830772  FUN_00830772  272 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00830772(int param_1,undefined4 param_2,int param_3,LONG param_4,undefined4 param_5,
                 LONG param_6,int param_7,undefined4 param_8)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  HBRUSH local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar1 == 0) || (*(int *)(in_ECX + 0x3024) == 0)) {
    FUN_007f47db(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    local_18.right = param_3 + 1;
    local_18.top = param_4;
    local_18.bottom = param_6;
    local_18.left = param_3 + -1;
    InflateRect(&local_18,0,-1);
    if (param_7 == 0) {
      iVar1 = FUN_007c2511();
      FUN_0079de5e(*(undefined4 *)(iVar1 + 0x20));
      InflateRect(&local_18,0,-3);
      local_18.right = local_18.right + -1;
      FillRect(*(HDC *)(param_1 + 4),&local_18,local_28);
      FUN_00416100();
    }
    else {
      iVar1 = *(int *)(in_ECX + 0x2f90);
      guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom,0,0xff);
      (**(code **)(iVar1 + 0x10))();
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[19] */
/* 00830882  FUN_00830882  119 bytes, 0 callers */

int FUN_00830882(CDC *param_1,LONG param_2,LONG param_3,LONG param_4,int param_5)

{
  CMFCVisualManagerOffice2007 *pCVar1;
  HBRUSH hbr;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  LONG local_18;
  int local_14;
  LONG LStack_10;
  int iStack_c;
  CDC *local_8;
  
  local_8 = param_1;
  pCVar1 = in_ECX + 0x8f48;
  if (((pCVar1 != (CMFCVisualManagerOffice2007 *)0x0) && (*(int *)(in_ECX + 0x8f4c) != 0)) ||
     (pCVar1 = in_ECX + 0xfc, hbr = (HBRUSH)0x0, pCVar1 != (CMFCVisualManagerOffice2007 *)0x0)) {
    hbr = *(HBRUSH *)(pCVar1 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  local_14 = param_5 + -2;
  local_18 = param_2;
  LStack_10 = param_4;
  iStack_c = param_5;
  CMFCVisualManagerOffice2007::DrawSeparator(in_ECX,local_8,(CRect *)&local_18,1);
  iVar2 = *(int *)(in_ECX + 0x903c);
  if (iVar2 == -1) {
    iVar2 = *(int *)(in_ECX + 0x8f9c);
  }
  return iVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[31] */
/* 008308f9  FUN_008308f9  285 bytes, 0 callers */

void FUN_008308f9(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar4;
  
  if (param_6 == 1) {
    iVar2 = 0xf50;
  }
  else {
    iVar2 = ((param_6 == 3) - 1 & 0x118) + 0x1068;
  }
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (((iVar3 == 0) || (*(int *)(in_ECX + 0x2754) == 0)) || (*(int *)(in_ECX + iVar2 + 0x8c) == 0))
  {
    FUN_008a5294(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar2 = *(int *)(in_ECX + 0x26c0);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,0,0xff);
    (**(code **)(iVar2 + 0x10))();
    if ((param_6 == 1) || (param_6 == 3)) {
      bVar1 = -(param_6 != 3) & 2;
      uVar4 = 2;
    }
    else {
      bVar1 = 1;
      uVar4 = 1;
    }
    FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,0,uVar4,bVar1,0,0,0,0,0xff);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[32] */
/* 00830a16  FUN_00830a16  190 bytes, 0 callers */

void FUN_00830a16(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 local_10;
  CMFCVisualManagerOffice2007 *local_c;
  undefined4 local_8;
  
  local_8 = param_1;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  uVar1 = local_8;
  if (iVar2 == 0) {
    FUN_008a5419(local_8,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  else {
    local_c = in_ECX + 0x3108;
    if ((param_6 != 0) && (*(int *)(in_ECX + 0x3314) != 0)) {
      local_c = in_ECX + 0x3280;
    }
    iVar2 = *(int *)local_c;
    param_3 = param_3 + -1;
    guard_check_icall(local_8,param_2,param_3,param_4,param_5,param_7 != 0,0xff);
    (**(code **)(iVar2 + 0x10))();
    local_10 = 0;
    local_c = (CMFCVisualManagerOffice2007 *)0x0;
    FUN_00814d1c(uVar1,(-(uint)(param_6 != 0) & 0xfffffff9) + 7,&param_2,0,&local_10);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[22] */
/* 00830ad4  FUN_00830ad4  339 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00830ad4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint param_7,int param_8)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  int iVar4;
  int local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008a56fc(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    return;
  }
  if (param_6 == 0xf020) {
    iVar2 = 0xd20;
  }
  else if (param_6 == 0xf060) {
    iVar2 = 0x690;
  }
  else {
    if (param_6 != 0xf120) {
      return;
    }
    iVar2 = 0x8c0;
  }
  local_18.left = 0;
  local_18.top = 0;
  local_20 = 0;
  local_18.right = *(LONG *)(in_ECX + iVar2 + 0x54);
  iVar3 = *(int *)(in_ECX + iVar2 + 0x58);
  local_18.bottom = iVar3;
  if ((param_7 & 0x40000) == 0) {
    if ((param_7 & 0x20000) == 0) {
      if (param_8 == 0) goto LAB_00830bd8;
      iVar4 = 0;
    }
    else {
      iVar4 = (uint)(param_8 != 0) * 2 + -1;
      if (param_8 == 0) goto LAB_00830bd8;
    }
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x6180) + 0x10);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,iVar4,0xff);
    (*pcVar1)();
    iVar3 = *(int *)(in_ECX + iVar2 + 0x58);
  }
  else {
    local_20 = 3;
  }
LAB_00830bd8:
  OffsetRect(&local_18,0,iVar3 * local_20);
  FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,0,1,1,local_18.left,local_18.top,
               local_18.right,local_18.bottom,0xff);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[83] */
/* 00830c27  FUN_00830c27  436 bytes, 0 callers */

void FUN_00830c27(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar1 != 0) && (iVar1 = FUN_0079d98a(&PTR_s_CMFCTasksPaneFrameWnd_00a00c90), iVar1 != 0)) {
    iVar1 = FUN_0079efbc(in_ECX + 0x134);
    if (iVar1 != 0) {
      PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_7,param_6 - param_4,0xf00021);
      PatBlt(*(HDC *)(param_1 + 4),param_3,param_4,param_5 - param_3,param_8,0xf00021);
      PatBlt(*(HDC *)(param_1 + 4),param_5 - param_9,param_4,param_9,param_6 - param_4,0xf00021);
      PatBlt(*(HDC *)(param_1 + 4),param_3,param_6 - param_10,param_5 - param_3,param_10,0xf00021);
      InflateRect((LPRECT)&param_7,-2,-2);
      InflateRect((LPRECT)&param_3,-2,-2);
      iVar2 = FUN_007c2511();
      FUN_0079efbc(iVar2 + 0xd0);
      PatBlt(*(HDC *)(param_1 + 4),param_3,param_4 + 1,param_7,(param_6 - param_4) + -1,0xf00021);
      PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_4,(param_5 - param_3) + -2,param_8,0xf00021);
      PatBlt(*(HDC *)(param_1 + 4),param_5 - param_9,param_4 + 1,param_9,(param_6 - param_4) + -1,
             0xf00021);
      PatBlt(*(HDC *)(param_1 + 4),param_3 + 1,param_6 - param_10,(param_5 - param_3) + -2,param_10,
             0xf00021);
      FUN_0079efbc(iVar1);
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  FUN_008a57e4(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[58] */
/* 00830ddc  FUN_00830ddc  308 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00830ddc(CDC *param_1,LONG param_2,int param_3,int param_4,int param_5)

{
  CDC *this;
  int iVar1;
  undefined4 uVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 local_2c;
  undefined4 local_28;
  CDrawingManager local_24 [8];
  undefined1 local_1c [4];
  CMFCVisualManagerOffice2003 *local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x830de8;
  local_14 = param_1;
  local_18 = (CMFCVisualManagerOffice2003 *)in_ECX;
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    CMFCVisualManagerOffice2003::OnDrawOutlookBarSplitter
              (local_18,local_14,param_2,param_3,param_4,param_5);
  }
  else {
    CDrawingManager::CDrawingManager(local_24,param_1);
    local_8 = 0;
    FUN_00817861(param_2,param_3,param_4,param_5,*(undefined4 *)(in_ECX + 0x1b0),
                 *(undefined4 *)(in_ECX + 0x1ac),1,0,0);
    OffsetRect((LPRECT)&param_2,0,1);
    this = local_14;
    local_2c = 0;
    local_28 = 0;
    FUN_007e94b8(local_14,param_2,param_3,param_4,param_5,0,1,1,0,0,0,0,0xff);
    OffsetRect((LPRECT)&param_2,0,-1);
    uVar2 = FUN_0079efbc(local_18 + 0x1e0);
    FUN_0079ec58(local_1c,param_2,param_3);
    CDC::LineTo(this,param_4,param_3);
    FUN_0079ec58(&local_2c,param_2,param_5 + -1);
    CDC::LineTo(this,param_4,param_5 + -1);
    FUN_0079efbc(uVar2);
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[57] */
/* 00830f10  FUN_00830f10  68 bytes, 0 callers */

void FUN_00830f10(CDC *param_1,tagRECT *param_2,undefined4 param_3,undefined4 param_4)

{
  ulong uVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008aa560(param_1,param_2,param_3,param_4);
  }
  else {
    uVar1 = *(ulong *)(in_ECX + 0x180);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar2 + 0x24),uVar1);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[20] */
/* 00830f54  FUN_00830f54  352 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ulong FUN_00830f54(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,
                  undefined4 param_11)

{
  CDC *this;
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  HBRUSH hbr;
  undefined1 local_2c [8];
  undefined **local_24 [2];
  undefined1 local_1c [4];
  CMFCVisualManagerOffice2003 *local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x830f60;
  local_14 = param_1;
  local_18 = (CMFCVisualManagerOffice2003 *)in_ECX;
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (((iVar1 == 0) || (param_2 == 0)) || (hbr = (HBRUSH)0x0, *(int *)(param_2 + 0x8c) != 0)) {
    uVar3 = CMFCVisualManagerOffice2003::OnDrawPaneCaption
                      (local_18,local_14,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                       param_9,param_10,param_11);
  }
  else {
    iVar1 = FUN_007c2511();
    FUN_0079df60(0,1,*(undefined4 *)(iVar1 + 0x54));
    this = local_14;
    local_8 = 0;
    uVar2 = FUN_0079efbc(local_24);
    param_7 = param_7 + 2;
    FUN_0079ec58(local_1c,param_4,param_7);
    CDC::LineTo(this,param_4,param_5);
    FUN_0079ec58(local_1c,param_4 + 1,param_5);
    CDC::LineTo(this,param_6 + -1,param_5);
    FUN_0079ec58(local_2c,param_6 + -1,param_5 + 1);
    CDC::LineTo(this,param_6 + -1,param_7);
    FUN_0079efbc(uVar2);
    param_4 = param_4 + 1;
    param_5 = param_5 + 1;
    param_6 = param_6 + -1;
    iVar1 = FUN_007c2511();
    if (param_3 == 0) {
      iVar1 = iVar1 + 0xc0;
    }
    else {
      iVar1 = iVar1 + 0xb8;
    }
    if (iVar1 != 0) {
      hbr = *(HBRUSH *)(iVar1 + 4);
    }
    FillRect(*(HDC *)(this + 4),(RECT *)&param_4,hbr);
    iVar1 = FUN_007c2511();
    if (param_3 == 0) {
      uVar3 = *(ulong *)(iVar1 + 0x84);
    }
    else {
      uVar3 = *(ulong *)(iVar1 + 0x74);
    }
    local_24[0] = CPen::vftable;
    FUN_00416100();
  }
  return uVar3;
}




/* vtable slots: CMFCVisualManagerOffice2007[121] */
/* 008310b4  OnDrawPopupWindowCaption  59 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::OnDrawPopupWindowCaption(class CDC *,class CRect,class
   CMFCDesktopAlertWnd *)
   
   Library: Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2007::OnDrawPopupWindowCaption
          (CMFCVisualManagerOffice2007 *this,undefined4 param_1,undefined4 param_3,
          undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = FUN_008aa6d2(param_1,param_3,param_4,param_5,param_6,param_7);
  iVar2 = CanDrawImage(this);
  if (iVar2 != 0) {
    uVar1 = *(ulong *)(this + 0x9080);
  }
  return uVar1;
}




/* vtable slots: CMFCVisualManagerOffice2007[88] */
/* 008310ef  FUN_008310ef  172 bytes, 0 callers */

undefined4
FUN_008310ef(undefined4 param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,
            LONG param_6,int param_7,int param_8)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar2 == 0) || (cVar1 = '\0', *(int *)(in_ECX + 0x6214) == 0)) {
    uVar3 = FUN_008a5c40(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    InflateRect((LPRECT)&param_3,-2,-1);
    if (param_8 != 0) {
      cVar1 = (param_7 == 0) + '\x01';
    }
    iVar2 = *(int *)(in_ECX + 0x6180);
    guard_check_icall(param_1,param_3,param_4,param_5,param_6,cVar1,0xff);
    (**(code **)(iVar2 + 0x10))();
    uVar3 = *(undefined4 *)(in_ECX + 0x8f94);
  }
  return uVar3;
}




/* vtable slots: CMFCVisualManagerOffice2007[132] */
/* 0083119b  FUN_0083119b  331 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0083119b(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar4;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_007f510a(param_1,param_2);
    return;
  }
  pcVar1 = *(code **)(*param_2 + 0xd0);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xd4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      iVar2 = 0;
      goto LAB_0083120a;
    }
  }
  iVar2 = 1;
LAB_0083120a:
  pcVar1 = *(code **)(*param_2 + 0xd8);
  guard_check_icall();
  local_1c = (*pcVar1)();
  pcVar1 = *(code **)(*param_2 + 0xe4);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    local_1c = 1;
    iVar2 = 1;
  }
  local_18.left = param_2[0x1d];
  local_18.top = param_2[0x1e];
  local_18.right = param_2[0x1f];
  local_18.bottom = param_2[0x20];
  OffsetRect(&local_18,1,-1);
  if (local_1c == 0) {
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = iVar2 * 2;
  }
  uVar4 = 3;
  if ((*(int *)(in_ECX + 0x6cf8) - *(int *)(in_ECX + 0x6cf0) <= local_18.right - local_18.left) &&
     (*(int *)(in_ECX + 0x6cfc) - *(int *)(in_ECX + 0x6cf4) <= local_18.bottom - local_18.top)) {
    uVar4 = 1;
  }
  iVar2 = *(int *)(in_ECX + 0x6bc8);
  guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom,uVar4,uVar4,
                    iVar3,0xff);
  (**(code **)(iVar2 + 0x18))();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[144] */
/* 008312e6  FUN_008312e6  311 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008312e6(CDC *param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  ulong uVar3;
  CDrawingManager local_34 [8];
  CDC *local_2c;
  CMFCVisualManagerOffice2007 *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x8312f2;
  local_2c = param_1;
  local_28 = in_ECX;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008a5cb9(param_1,param_2);
  }
  iVar2 = FUN_0079d98a(&PTR_s_CMFCRibbonEdit_00999d90);
  if (iVar2 == 0) goto LAB_00831415;
  local_24.left = param_2[0x1d];
  local_24.top = param_2[0x1e];
  local_24.right = param_2[0x1f];
  local_24.bottom = param_2[0x20];
  uVar3 = *(ulong *)(local_28 + 0x90b8);
  pcVar1 = *(code **)(*param_2 + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xd0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*param_2 + 0xe4);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        pcVar1 = *(code **)(*param_2 + 0xd4);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) goto LAB_008313cd;
      }
    }
    pcVar1 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      uVar3 = *(ulong *)(local_28 + 0x90c0);
    }
    else {
      uVar3 = *(ulong *)(local_28 + 0x90c4);
    }
  }
  else {
    uVar3 = *(ulong *)(local_28 + 0x90bc);
  }
LAB_008313cd:
  local_24.left = param_2[0x4d];
  if (DAT_00a12704 == 0) {
    CDC::Draw3dRect(local_2c,&local_24,uVar3,uVar3);
  }
  else {
    CDrawingManager::CDrawingManager(local_34,local_2c);
    local_8 = 0;
    FUN_00816b6a(&local_24,0xffffffff,uVar3);
    FUN_0081510b();
  }
LAB_00831415:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[153] */
/* 0083141d  FUN_0083141d  162 bytes, 0 callers */

undefined4
FUN_0083141d(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  CMFCRibbonBar *this;
  int iVar1;
  undefined4 uVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    uVar2 = FUN_008aa7d4(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar1 = FUN_0079d98a(&PTR_s_CMFCRibbonQuickAccessToolBar_009a0c60);
    if ((((iVar1 != 0) && (*(int *)(in_ECX + 0x4d84) != 0)) &&
        (this = *(CMFCRibbonBar **)(param_2 + 0x84), this != (CMFCRibbonBar *)0x0)) &&
       (((byte)this[0x330] & 2) == 0)) {
      iVar1 = CMFCRibbonBar::IsQuickAccessToolbarOnTop(this);
      if (iVar1 == 0) {
        iVar1 = *(int *)(in_ECX + 0x4cf0);
        guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
        (**(code **)(iVar1 + 0x10))();
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[148] */
/* 008314bf  FUN_008314bf  1734 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008314bf(CDC *param_1,CMFCRibbonBar *param_2,int param_3,int param_4,int param_5,
                 int param_6,CMFCVisualManagerOffice2007 *param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  double dVar1;
  byte bVar2;
  CMFCVisualManagerOffice2007 *pCVar3;
  int iVar4;
  HWND pHVar5;
  uint uVar6;
  CWnd *pCVar7;
  int iVar8;
  CObject *pCVar9;
  CSimpleStringT<wchar_t,0> *pCVar10;
  BOOL BVar11;
  CMFCVisualManagerOffice2007 *in_ECX;
  CMFCVisualManagerOffice2007 *pCVar12;
  code *pcVar13;
  CDC *pCVar14;
  int local_90;
  int local_8c;
  int local_88;
  int iStack_84;
  int local_80;
  int iStack_7c;
  uint local_78;
  code *local_74;
  int local_70;
  int local_6c;
  int iStack_68;
  code *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  HICON__ *local_44;
  int local_40;
  int local_3c;
  int local_38;
  CWnd *local_34;
  int local_30;
  uint local_2c;
  CDC *local_28;
  CMFCRibbonBar *local_24;
  CMFCVisualManagerOffice2007 *local_20;
  int local_1c;
  code *local_18;
  CMFCVisualManagerOffice2007 *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x8314ce;
  local_28 = param_1;
  local_24 = param_2;
  local_14[0] = in_ECX;
  iVar4 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar4 == 0) {
    FUN_007f5466(local_28,local_24,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10)
    ;
  }
  else {
    pHVar5 = GetParent(*(HWND *)(param_2 + 0x20));
    local_34 = CWnd::FromHandle(pHVar5);
    local_2c = FUN_00797b3d();
    uVar6 = FUN_00797acc();
    local_78 = uVar6 >> 0x16 & 1;
    local_3c = FUN_0082f5a7(local_34);
    local_38 = *(int *)(param_2 + 0x308);
    pHVar5 = GetParent(*(HWND *)(param_2 + 0x20));
    pCVar7 = CWnd::FromHandle(pHVar5);
    FUN_0085aaf0(&local_90,pCVar7);
    iStack_68 = param_6;
    local_54 = *(int *)(local_14[0] + 0x2518);
    local_50 = *(int *)(local_14[0] + 0x251c);
    local_4c = *(int *)(local_14[0] + 0x2520);
    local_48 = *(int *)(local_14[0] + 0x2524);
    iVar4 = *(int *)(local_24 + 0xe1c);
    iStack_84 = *(int *)(local_24 + 0xe20);
    local_80 = *(int *)(local_24 + 0xe24);
    iStack_7c = *(int *)(local_24 + 0xe28);
    if (local_80 < iVar4) {
      param_7 = (CMFCVisualManagerOffice2007 *)(iVar4 + 1);
    }
    local_6c = param_5 + local_90;
    local_74 = (code *)(param_3 - local_90);
    local_70 = param_4 - local_8c;
    local_44 = (HICON__ *)(*(uint *)(local_24 + 0x330) >> 1 & 1);
    local_88 = iVar4;
    local_18 = local_74;
    if ((((local_44 == (HICON__ *)0x0) &&
         (iVar8 = CMFCRibbonBar::IsQuickAccessToolbarOnTop(local_24), iVar8 != 0)) &&
        (iVar4 < local_80)) &&
       ((1 < *(int *)(local_24 + 0xebc) || (*(int *)(local_14[0] + 0xc000) == 10)))) {
      local_30 = 1;
    }
    else {
      local_30 = 0;
    }
    pCVar14 = local_28;
    pCVar12 = local_14[0];
    if (local_38 == 0) {
      if (*(int *)(local_14[0] + 0xc000) < 0x14) {
        if (local_3c == 0) {
          local_20 = *(CMFCVisualManagerOffice2007 **)(local_14[0] + 0x8f58);
          local_40 = *(int *)(local_14[0] + 0x8f5c);
        }
        else {
          local_20 = *(CMFCVisualManagerOffice2007 **)(local_14[0] + 0x8f50);
          local_40 = *(int *)(local_14[0] + 0x8f54);
        }
        local_64 = local_18 + local_54;
        local_60 = local_70 + local_50;
        local_5c = local_6c - local_4c;
        local_58 = iStack_68 - local_48;
        CDrawingManager::CDrawingManager((CDrawingManager *)&local_4c,local_28);
        local_8 = 0;
        FUN_00817362(local_64,local_60,local_5c,local_58,local_20,local_40,local_40,local_20,0,0x32)
        ;
        pCVar14 = local_28;
        local_18 = *(code **)(*(int *)(local_14[0] + 0x23d0) + 0x14);
        guard_check_icall(local_28,local_74,local_70,local_6c,iStack_68,local_3c == 0,0xff);
        pCVar12 = local_14[0];
        (*local_18)();
        local_8 = 0xffffffff;
        FUN_0081510b();
      }
      else {
        local_18 = *(code **)(*(int *)(local_14[0] + 0x23d0) + 0x10);
        guard_check_icall(local_28,local_74,local_70,local_6c,iStack_68,local_3c == 0,0xff);
        pCVar12 = local_14[0];
        (*local_18)();
      }
    }
    if (local_30 == 0) {
      if ((local_44 != (HICON__ *)0x0) &&
         (local_44 = CGlobalUtils::GetWndIcon((CGlobalUtils *)&PTR_vftable_00a0095c,local_34),
         local_44 != (HICON__ *)0x0)) {
        local_30 = GetSystemMetrics(0x32);
        local_40 = GetSystemMetrics(0x31);
        iVar4 = GetSystemMetrics(4);
        if (iVar4 < param_6 - param_4) {
          iVar4 = GetSystemMetrics(4);
        }
        else {
          iVar4 = param_6 - param_4;
        }
        local_20 = (CMFCVisualManagerOffice2007 *)(iVar4 + param_3);
        iVar4 = (int)(local_20 + (-local_40 - param_3)) / 2;
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        local_18 = (code *)(iVar4 + param_3);
        iVar4 = ((param_6 - param_4) - local_30) / 2;
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        CDC::DrawState(pCVar14,local_18,iVar4 + param_4,local_40,local_30,local_44,0,0);
        if ((int)param_7 < (int)local_20) {
          param_7 = local_20;
        }
      }
    }
    else {
      local_20 = pCVar12 + 0x4130;
      if (local_38 == 0) {
        local_20 = pCVar12 + 0x3fb8;
      }
      if (*(int *)(local_20 + 0x94) != 0) {
        local_54 = local_88 - (*(int *)(local_20 + 0x138) + -2);
        local_4c = local_80;
        local_50 = iStack_84 + -1;
        local_48 = iStack_7c + 1;
        local_88 = *(int *)(local_24 + 0x1238);
        iStack_84 = *(int *)(local_24 + 0x123c);
        local_80 = *(int *)(local_24 + 0x1240);
        iStack_7c = *(int *)(local_24 + 0x1244);
        pcVar13 = *(code **)(*(int *)local_14[0] + 600);
        local_30 = local_54;
        local_18 = (code *)local_50;
        guard_check_icall();
        local_4c = (*pcVar13)();
        pCVar12 = local_20;
        local_4c = local_4c + local_80 + 1;
        pcVar13 = local_18;
        if (local_48 - (int)local_18 < *(int *)(local_20 + 0x134) - *(int *)(local_20 + 300)) {
          pcVar13 = (code *)(local_48 - (*(int *)(local_20 + 0x134) - *(int *)(local_20 + 300)));
          local_50 = (int)pcVar13;
        }
        if (local_38 != 0) {
          iVar4 = GetSystemMetrics(0x20);
          local_18 = (code *)(iVar4 / 2);
          iVar4 = FUN_007c2511();
          if (*(int *)(iVar4 + 0x1e8) == 0) {
            dVar1 = 1.0;
          }
          else {
            dVar1 = *(double *)(iVar4 + 0x1e0);
          }
          if (dVar1 == 1.0) {
            local_50 = 1;
          }
          else {
            local_50 = -2;
          }
          local_50 = (int)pcVar13 + local_50;
          local_54 = local_30 + 1;
          local_4c = local_4c - (int)local_18;
        }
        pCVar14 = local_28;
        local_18 = *(code **)(*(int *)pCVar12 + 0x10);
        guard_check_icall(local_28,local_54,local_50,local_4c,local_48,local_3c == 0,0xff);
        (*local_18)();
      }
    }
    CStringT<>();
    local_8 = 1;
    FUN_00792c64(&local_1c);
    pCVar12 = local_14[0];
    pcVar13 = *(code **)(*(int *)pCVar14 + 0x28);
    guard_check_icall(local_14[0] + 0x8f38);
    local_18 = (code *)(*pcVar13)();
    if (local_18 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    iVar4 = FUN_004054a0(local_1c + -0x10);
    local_14[0] = (CMFCVisualManagerOffice2007 *)(iVar4 + 0x10);
    CStringT<>();
    local_20 = (CMFCVisualManagerOffice2007 *)0x0;
    local_8._0_1_ = 3;
    if ((local_2c & 0x8000) != 0) {
      local_20 = (CMFCVisualManagerOffice2007 *)(local_2c >> 0xe & 1);
      pCVar9 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,(CObject *)local_34);
      if (pCVar9 != (CObject *)0x0) {
        pCVar10 = (CSimpleStringT<wchar_t,0> *)FUN_0082f3cd(&local_2c);
        local_8._0_1_ = 4;
        ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)local_14,pCVar10);
        local_8._0_1_ = 3;
        FUN_00406b10();
        pCVar3 = local_14[0];
        if (*(int *)(local_14[0] + -0xc) == 0) {
          ATL::CSimpleStringT<wchar_t,0>::operator=
                    ((CSimpleStringT<wchar_t,0> *)&local_24,(CSimpleStringT<wchar_t,0> *)&local_1c);
        }
        else {
          iVar4 = FUN_00429b90(local_14[0],0);
          if ((iVar4 != -1) && (*(int *)(pCVar3 + -0xc) < *(int *)(local_1c + -0xc))) {
            if (iVar4 == 0) {
              local_20 = (CMFCVisualManagerOffice2007 *)0x0;
              pCVar10 = (CSimpleStringT<wchar_t,0> *)Left(&local_2c,*(int *)(pCVar3 + -0xc) + 3);
              local_8._0_1_ = 5;
              ATL::CSimpleStringT<wchar_t,0>::operator=
                        ((CSimpleStringT<wchar_t,0> *)local_14,pCVar10);
              local_8._0_1_ = 3;
              FUN_00406b10();
              pCVar10 = (CSimpleStringT<wchar_t,0> *)
                        ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::
                        Right((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                              &local_1c,(int)&local_2c);
              local_8 = CONCAT31(local_8._1_3_,6);
              ATL::CSimpleStringT<wchar_t,0>::operator=
                        ((CSimpleStringT<wchar_t,0> *)&local_24,pCVar10);
            }
            else {
              pCVar10 = (CSimpleStringT<wchar_t,0> *)
                        ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::
                        Right((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                              &local_1c,(int)&local_2c);
              local_8._0_1_ = 7;
              ATL::CSimpleStringT<wchar_t,0>::operator=
                        ((CSimpleStringT<wchar_t,0> *)local_14,pCVar10);
              local_8._0_1_ = 3;
              FUN_00406b10();
              pCVar10 = (CSimpleStringT<wchar_t,0> *)
                        Left(&local_44,*(int *)(local_1c + -0xc) - *(int *)(local_14[0] + -0xc));
              local_8 = CONCAT31(local_8._1_3_,8);
              ATL::CSimpleStringT<wchar_t,0>::operator=
                        ((CSimpleStringT<wchar_t,0> *)&local_24,pCVar10);
            }
            local_8._0_1_ = 3;
            FUN_00406b10();
          }
        }
      }
    }
    bVar2 = 1;
    iVar4 = FUN_007c2511();
    if ((*(int *)(iVar4 + 0x17c) != 0) ||
       (BVar11 = IsZoomed(*(HWND *)(local_34 + 0x20)), BVar11 == 0)) {
      bVar2 = 0;
    }
    pCVar14 = local_28;
    FUN_0082e608(local_28,&param_7,local_14,&local_24,local_20,local_3c,local_78,
                 *(int *)(pCVar12 + 0x210),local_38,(-(uint)bVar2 & 0xfffffff6) + 10,
                 (-(uint)bVar2 & 0x1000000) - 1);
    pcVar13 = *(code **)(*(int *)pCVar14 + 0x28);
    guard_check_icall(local_18);
    (*pcVar13)();
    FUN_00406b10();
    FUN_00406b10();
    FUN_00406b10();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[152] */
/* 00831b86  FUN_00831b86  279 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00831b86(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HWND pHVar5;
  CWnd *pCVar6;
  undefined4 uVar7;
  CMFCVisualManagerOffice2007 *in_ECX;
  int local_1c;
  int local_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar3 == 0) {
    FUN_007f56d8(param_1,param_2);
    return;
  }
  pcVar1 = *(code **)(*param_2 + 0xd0);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xd4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      iVar3 = 0;
      goto LAB_00831bf5;
    }
  }
  iVar3 = 1;
LAB_00831bf5:
  local_1c = 0;
  pcVar1 = *(code **)(*param_2 + 0xd8);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  iVar2 = iVar3;
  if ((iVar4 == 0) && (iVar2 = local_1c, iVar3 != 0)) {
    local_1c = 2;
    iVar2 = local_1c;
  }
  local_1c = iVar2;
  iVar3 = param_2[0x71];
  if (((iVar3 == 0) && (iVar2 = param_2[0x21], iVar2 != 0)) && (*(int *)(iVar2 + 0x20) != 0)) {
    pHVar5 = GetParent(*(HWND *)(iVar2 + 0x20));
    pCVar6 = CWnd::FromHandle(pHVar5);
    uVar7 = FUN_0082f5a7(pCVar6);
    iVar3 = param_2[0x71];
  }
  else {
    uVar7 = 1;
  }
  local_18 = param_2[0x1d];
  iStack_14 = param_2[0x1e];
  iStack_10 = param_2[0x1f];
  iStack_c = param_2[0x20];
  FUN_0082ded4(param_1,&local_18,param_2[0x29],local_1c,0,uVar7,iVar3 != 0);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[133] */
/* 00831c9d  FUN_00831c9d  462 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00831c9d(CDC *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  CMFCVisualManagerOffice2007 *pCVar2;
  code *pcVar3;
  CMFCVisualManagerOffice2007 *pCVar4;
  int local_28;
  int local_24;
  CMFCVisualManagerOffice2007 *local_20;
  CDrawingManager local_1c [4];
  CMFCVisualManagerOffice2007 *local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x831ca9;
  local_14 = param_1;
  local_24 = param_2;
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_007f57aa(local_14,local_24,param_3,param_4,param_5,param_6);
    return;
  }
  local_20 = in_ECX + 0xbd98;
  pCVar4 = in_ECX + 0x42a8;
  local_18 = pCVar4;
  iVar1 = FUN_00872525();
  if ((*(int *)(local_24 + 0x19c) == 0) || ((iVar1 != 0 && (*(int *)(iVar1 + 0xc4) != 0)))) {
    pCVar2 = in_ECX + 0xbd98;
  }
  else {
    iVar1 = *(int *)(local_24 + 0x19c) * 0x648;
    pCVar4 = in_ECX + iVar1 + 0x8c78;
    pCVar2 = in_ECX + iVar1 + 0x90ec;
    local_20 = pCVar2;
    local_18 = pCVar4;
  }
  iVar1 = *(int *)(local_24 + 0x540);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xeb4) == 0) {
      if ((*(int *)(iVar1 + 0xea4) != 0) && (*(int *)(in_ECX + 0xc000) < 0x14)) {
        pcVar3 = *(code **)(*(int *)pCVar4 + 0x1c);
        goto LAB_00831e16;
      }
    }
    else if ((param_3 < 0) || (param_4 < 0)) {
      CDrawingManager::CDrawingManager(local_1c,local_14);
      local_8 = 0;
      FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(in_ECX + 0x15c),
                   *(undefined4 *)(in_ECX + 0x160),1,0,0);
      FUN_0081510b();
      return;
    }
  }
  if (pCVar2 != (CMFCVisualManagerOffice2007 *)0x0) {
    local_28 = *(int *)(pCVar4 + 0x130) - *(int *)(pCVar4 + 0x128);
    local_24 = param_6 - param_4;
    iVar1 = CMFCVisualManagerBitmapCache::FindIndex
                      ((CMFCVisualManagerBitmapCache *)pCVar2,(CSize *)&local_28);
    pCVar2 = local_20;
    if ((iVar1 != -1) ||
       (iVar1 = CMFCVisualManagerBitmapCache::CacheY
                          ((CMFCVisualManagerBitmapCache *)local_20,param_6 - param_4,
                           (CMFCControlRenderer *)pCVar4), iVar1 != -1)) {
      CMFCVisualManagerBitmapCache::Get((CMFCVisualManagerBitmapCache *)pCVar2,iVar1);
      FUN_0082eb09(local_14,param_3,param_4,param_5,param_6,*(undefined4 *)(pCVar4 + 0x158),
                   *(int *)(pCVar4 + 0x130) - *(int *)(pCVar4 + 0x160),0,0xff);
      return;
    }
  }
  pcVar3 = *(code **)(*(int *)pCVar4 + 0x10);
LAB_00831e16:
  guard_check_icall(local_14,param_3,param_4,param_5,param_6,0,0xff);
  (*pcVar3)();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[162] */
/* 00831e6b  FUN_00831e6b  244 bytes, 0 callers */

int FUN_00831e6b(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar4 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar4 == 0) || (iVar4 = *(int *)(param_2 + 0x1c4), iVar4 == 0)) {
    iVar4 = FUN_008aa8b9(param_1,param_2);
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0x74);
    iVar2 = *(int *)(in_ECX + iVar4 * 0x648 + 0x8b00);
    guard_check_icall(param_1,*(undefined4 *)(param_2 + 0x74),*(undefined4 *)(param_2 + 0x78),
                      *(undefined4 *)(param_2 + 0x7c),*(undefined4 *)(param_2 + 0x80),0,0xff);
    (**(code **)(iVar2 + 0x10))();
    if (0 < *(int *)(param_2 + 0x1cc)) {
      iVar2 = *(int *)(*(int *)(param_2 + 0x84) + 0x7a8);
      iVar3 = *(int *)(in_ECX + 0x8d90);
      guard_check_icall(param_1,uVar1,*(undefined4 *)(iVar2 + 0x108),*(int *)(param_2 + 0x1cc),
                        *(undefined4 *)(iVar2 + 0x110),0,0xff);
      (**(code **)(iVar3 + 0x14))();
    }
    iVar4 = *(int *)(in_ECX + iVar4 * 0x648 + 0x8b00 + 0x5e0);
  }
  return iVar4;
}




/* vtable slots: CMFCVisualManagerOffice2007[135] */
/* 00831f5f  FUN_00831f5f  295 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00831f5f(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar5;
  undefined4 local_24;
  int *local_20;
  CMFCVisualManagerOffice2007 *local_1c;
  int local_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = param_2;
  local_1c = in_ECX;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008a5f8e(param_1,param_2);
  }
  else {
    local_18 = param_2[0x1d];
    local_1c = local_1c + (-(uint)(param_2[0x71] != 0) & 0xfffffe88) + 0x4888;
    iStack_14 = param_2[0x1e];
    iStack_10 = param_2[0x1f];
    iStack_c = param_2[0x20];
    pcVar1 = *(code **)(*param_2 + 0xd8);
    uVar5 = 0;
    guard_check_icall();
    iVar3 = (*pcVar1)();
    iVar2 = *param_2;
    if (iVar3 == 0) {
      guard_check_icall();
      iVar2 = (**(code **)(iVar2 + 0xd0))();
      if (iVar2 != 0) {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 1;
      guard_check_icall();
      iVar2 = (**(code **)(iVar2 + 0xd0))();
      if (iVar2 != 0) {
        uVar5 = 2;
      }
    }
    iVar2 = *(int *)local_1c;
    guard_check_icall(param_1,local_18,iStack_14,iStack_10,iStack_c,uVar5,0xff);
    (**(code **)(iVar2 + 0x10))();
    uVar4 = local_20[0x71];
    iVar2 = FUN_007c2511();
    if (*(int *)(iVar2 + 0x198) != 0) {
      uVar4 = (uint)(uVar4 == 0);
    }
    local_24 = 0;
    local_20 = (int *)0x0;
    FUN_00814d1c(param_1,(-(uVar4 != 0) & 3U) + 0xe,&local_18,0,&local_24);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[134] */
/* 00832086  FUN_00832086  616 bytes, 0 callers */

undefined4 FUN_00832086(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  CMFCVisualManagerOffice2007 *pCVar12;
  CMFCVisualManagerOffice2007 *in_ECX;
  byte bVar13;
  int local_30;
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  
  iVar7 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar7 == 0) {
    uVar8 = FUN_008aa97b(param_1,param_2,param_3);
    return uVar8;
  }
  bVar4 = true;
  iVar7 = param_2[0x22];
  iVar11 = *(int *)(iVar7 + 0x53c);
  if (param_3 == 0) {
LAB_008320f6:
    cVar6 = '\0';
    cVar5 = '\0';
  }
  else {
    if ((*(byte *)(iVar11 + 0x330) & 1) != 0) {
      pcVar3 = *(code **)(*param_2 + 0x1c4);
      guard_check_icall();
      iVar9 = (*pcVar3)();
      if (iVar9 == 0) goto LAB_008320f6;
    }
    cVar6 = '\x01';
    cVar5 = '\x01';
  }
  pcVar3 = *(code **)(*param_2 + 0xd8);
  guard_check_icall();
  iVar9 = (*pcVar3)();
  pcVar3 = *(code **)(*param_2 + 0xd4);
  guard_check_icall();
  iVar10 = (*pcVar3)();
  if ((iVar10 == 0) || ((*(byte *)(iVar11 + 0x330) & 1) == 0)) {
    bVar4 = false;
  }
  pcVar3 = *(code **)(*param_2 + 0xd0);
  guard_check_icall();
  iVar10 = (*pcVar3)();
  if ((iVar10 != 0) || (bVar4)) {
    pcVar3 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar10 = (*pcVar3)();
    if (iVar10 != 0) goto LAB_0083216e;
    bVar4 = true;
  }
  else {
LAB_0083216e:
    bVar4 = false;
  }
  local_14 = 0;
  local_30 = param_2[0x1d];
  iVar10 = param_2[0x1e];
  iVar1 = param_2[0x1f];
  iVar2 = param_2[0x20];
  if (((0x13 < *(int *)(in_ECX + 0xc000)) && (*(int *)(in_ECX + 0x462c) != 0)) &&
     (local_14 = *(int *)(iVar11 + 0x2cc), 0 < local_14)) {
    local_30 = local_30 + 1;
  }
  bVar13 = -cVar6 & 3;
  if (iVar9 == 0) {
    if (!bVar4) goto LAB_008321c9;
  }
  else {
    if (!bVar4) goto LAB_008321c9;
    bVar13 = cVar5 + 1;
  }
  bVar13 = bVar13 + 1;
LAB_008321c9:
  local_20 = *(undefined4 *)(in_ECX + 0x9084);
  pCVar12 = in_ECX + 0x4420;
  local_1c = *(undefined4 *)(in_ECX + 37000);
  if ((*(int *)(iVar7 + 0x19c) != 0) || (iVar11 = FUN_00863d92(), iVar11 != 0)) {
    iVar11 = FUN_00863d92();
    if ((iVar11 == 0) && (bVar13 != 4)) {
      iVar7 = *(int *)(iVar7 + 0x19c) * 0x648;
      iVar11 = iVar7 + 0x8df0;
      iVar9 = iVar7 + 0x90e4;
      iVar7 = iVar7 + 0x90e8;
    }
    else {
      iVar9 = 0x9d74;
      iVar11 = 0x9a80;
      iVar7 = 0x9d78;
    }
    local_1c = *(undefined4 *)(in_ECX + iVar7);
    local_20 = *(undefined4 *)(in_ECX + iVar9);
    pCVar12 = in_ECX + iVar11;
  }
  iVar7 = *(int *)pCVar12;
  guard_check_icall(param_1,local_30,iVar10,iVar1,iVar2 + 1,bVar13,0xff);
  (**(code **)(iVar7 + 0x10))();
  if (0 < local_14) {
    pcVar3 = *(code **)(*(int *)(in_ECX + 0x4598) + 0x10);
    if (local_14 * 0xff < 0x639c) {
      iVar7 = (local_14 * 0xff) / 100;
    }
    else {
      iVar7 = 0xff;
    }
    guard_check_icall(param_1,iVar1,iVar10,iVar1 + 1,iVar2,0,iVar7);
    (*pcVar3)();
  }
  if (cVar5 == '\0') {
    local_1c = local_20;
  }
  return local_1c;
}




/* vtable slots: CMFCVisualManagerOffice2007[174] */
/* 008322ee  FUN_008322ee  234 bytes, 0 callers */

void FUN_008322ee(undefined4 param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,
                 LONG param_6,undefined4 param_7,undefined4 param_8)

{
  double dVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar2 == 0) || (*(int *)(in_ECX + 0x129c) == 0)) {
    FUN_007f5def(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    iVar2 = FUN_007c2511();
    if (*(int *)(iVar2 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar2 + 0x1e0);
    }
    if (dVar1 == 1.0) {
      uVar4 = 1;
      uVar3 = 1;
    }
    else {
      InflateRect((LPRECT)&param_3,-5,-5);
      uVar4 = 3;
      uVar3 = 3;
    }
    FUN_007e94b8(param_1,param_3,param_4,param_5,param_6,0,uVar3,uVar4,0,0,0,0,0xff);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[139] */
/* 008323d8  FUN_008323d8  598 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008323d8(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  CMFCVisualManagerOffice2007 *pCVar2;
  int iVar3;
  int iVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_2c;
  int local_28;
  int *local_24;
  undefined4 local_20;
  CMFCVisualManagerOffice2007 *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = param_1;
  local_24 = param_2;
  local_1c = in_ECX;
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar3 == 0) {
    FUN_007f600a(param_1,param_2);
    return;
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x238);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  pCVar2 = local_1c;
  local_18.left = param_2[0x1d];
  local_18.top = param_2[0x1e];
  local_18.right = param_2[0x1f];
  local_18.bottom = param_2[0x20];
  uVar6 = local_20;
  if (param_2[0x31] == 0) {
    if (*(int *)(local_1c + 0x6f4c) == 0) goto LAB_00832607;
    pcVar1 = *(code **)(*param_2 + 0x114);
    guard_check_icall(&local_2c,1);
    (*pcVar1)();
    uVar6 = local_20;
    local_18.bottom = local_28 + 0x19 + local_18.top;
    iVar3 = *(int *)(pCVar2 + 0x6eb8);
    local_18.top = local_18.top + 3;
    local_18.left = ((local_18.right + local_18.left) / 2 - local_2c / 2) + -0xb;
    local_18.right = local_18.left + local_2c + 0x16;
    guard_check_icall(local_20,local_18.left,local_18.top,local_18.right,local_18.bottom,0,0xff);
  }
  else if (*(int *)(local_1c + 0x723c) == 0) {
    if (*(int *)(local_1c + 0x70c4) == 0) goto LAB_00832607;
    iVar3 = *(int *)(local_1c + 0x7164) - *(int *)(local_1c + 0x715c);
    if (local_18.bottom - local_18.top < iVar3) {
      iVar3 = (local_18.bottom - local_18.top) / 2;
    }
    InflateRect(&local_18,-1,0);
    uVar6 = local_20;
    local_18.top = local_18.bottom - iVar3;
    iVar3 = *(int *)(pCVar2 + 0x7030);
    guard_check_icall(local_20,local_18.left,local_18.top,local_18.right,local_18.bottom,0,0xff);
  }
  else {
    pcVar1 = *(code **)(*param_2 + 0xe4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      pcVar1 = *(code **)(*param_2 + 0xd8);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      iVar3 = *param_2;
      if (iVar4 == 0) {
        guard_check_icall();
        iVar3 = (**(code **)(iVar3 + 0xd0))();
        if (iVar3 == 0) {
          pcVar1 = *(code **)(*param_2 + 0xd4);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          if (iVar3 == 0) goto LAB_00832562;
        }
        uVar5 = 1;
      }
      else {
        guard_check_icall();
        iVar3 = (**(code **)(iVar3 + 0xd0))();
        if (iVar3 != 0) goto LAB_0083252e;
LAB_00832562:
        uVar5 = 0;
      }
    }
    else {
LAB_0083252e:
      uVar5 = 2;
    }
    uVar6 = local_20;
    iVar3 = *(int *)(pCVar2 + 0x71a8);
    guard_check_icall(local_20,local_18.left,local_18.top,local_18.right,local_18.bottom,uVar5,0xff)
    ;
  }
  (**(code **)(iVar3 + 0x10))();
  param_2 = local_24;
LAB_00832607:
  pcVar1 = *(code **)(*(int *)local_1c + 0x230);
  guard_check_icall(uVar6,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[141] */
/* 0083262e  FUN_0083262e  252 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0083262e(undefined4 param_1,undefined4 param_2,int param_3,LONG param_4,int param_5,
                 LONG param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  local_20 = param_2;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar2 == 0) || (*(int *)(in_ECX + 0x6f4c) == 0)) {
    FUN_007f6122(local_1c,local_20,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    param_3 = (*(int *)(in_ECX + 0x6fe0) - *(int *)(in_ECX + 0x6fe8)) + param_5;
    iVar2 = *(int *)(in_ECX + 0x6eb8);
    guard_check_icall(local_1c,param_3,param_4,param_5,param_6,0,0xff);
    (**(code **)(iVar2 + 0x10))();
    local_18.left = param_3;
    local_18.top = param_4;
    local_18.right = param_5;
    local_18.bottom = param_6;
    OffsetRect(&local_18,0,1);
    uVar1 = local_1c;
    local_24 = 0;
    local_20 = 0;
    FUN_00814d1c(local_1c,0,&local_18,3,&local_24);
    local_24 = 0;
    local_20 = 0;
    FUN_00814d1c(uVar1,0,&param_3,0,&local_24);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[160] */
/* 0083272a  FUN_0083272a  98 bytes, 0 callers */

void FUN_0083272a(CDC *param_1,undefined4 param_2,LONG param_3,LONG param_4,int param_5,LONG param_6
                 )

{
  ulong uVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_007f61e3(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    param_5 = param_5 + -5;
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x58);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&param_3,*(ulong *)(iVar2 + 0x58),uVar1);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[159] */
/* 0083278c  FUN_0083278c  290 bytes, 0 callers */

void FUN_0083278c(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  uint uVar3;
  undefined4 local_8;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_007f620e(param_1,param_2);
    return;
  }
  local_8 = 0;
  pcVar1 = *(code **)(*param_2 + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  uVar3 = 2;
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_2 + 0xd8);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    pcVar1 = *(code **)(*param_2 + 0xd0);
    if (iVar2 == 0) {
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        pcVar1 = *(code **)(*param_2 + 0xd4);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) goto LAB_0083284d;
      }
      local_8 = 1;
    }
    else {
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        local_8 = 2;
      }
    }
  }
  else {
    local_8 = 3;
  }
LAB_0083284d:
  iVar2 = FUN_008afefc();
  if (iVar2 == 0) {
    iVar2 = FUN_008afec2();
    uVar3 = ~-(uint)(iVar2 != 0) & 1;
  }
  pcVar1 = *(code **)(*(int *)(in_ECX + uVar3 * 0x178 + 0x7498) + 0x10);
  guard_check_icall(param_1,param_2[0x1d],param_2[0x1e],param_2[0x1f],param_2[0x20],local_8,0xff);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[173] */
/* 008328ae  FUN_008328ae  322 bytes, 0 callers */

void FUN_008328ae(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  CMFCVisualManagerOffice2007 *this;
  int unaff_EBX;
  int unaff_EBP;
  int local_c [3];
  
  local_c[2] = 8;
  local_c[1] = 0x20;
  local_c[0] = 0x8328bc;
  __EH_prolog3_align();
  *(CMFCVisualManagerOffice2007 **)(unaff_EBP + -0x1c) = this;
  piVar1 = *(int **)(unaff_EBX + 0xc);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBX + 8);
  *(int **)(unaff_EBP + -0x18) = piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  local_c[0] = 0x8328d6;
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(this);
  if ((iVar3 == 0) || (*(int *)(this + 0x8844) == 0)) {
    iVar3 = *(int *)(unaff_EBX + 0x20);
    *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBX + 0x10);
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBX + 0x14);
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBX + 0x18);
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBX + 0x1c);
    *(int **)(unaff_EBP + -0x20) = local_c;
    local_c[0] = FUN_004054a0(iVar3 + -0x10);
    local_c[0] = local_c[0] + 0x10;
    FUN_007f624f(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x18),
                 *(undefined4 *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x2c),
                 *(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + -0x24));
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0xdc);
    local_c[0] = 0x8328fb;
    guard_check_icall();
    local_c[0] = 0x832900;
    uVar4 = (*pcVar2)();
    iVar3 = *(int *)(this + 0x87b0);
    local_c[0] = 0xff;
    *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
    pcVar2 = *(code **)(iVar3 + 0x10);
    guard_check_icall(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBX + 0x10),
                      *(undefined4 *)(unaff_EBX + 0x14),*(undefined4 *)(unaff_EBX + 0x18),
                      *(undefined4 *)(unaff_EBX + 0x1c),0);
    iVar3 = *(int *)(unaff_EBP + -0x1c);
    (*pcVar2)();
    FUN_0044ff70();
    piVar1 = *(int **)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(*piVar1 + 0x30);
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar4 = *(undefined4 *)(iVar3 + 0x90a0);
    }
    else {
      uVar4 = *(undefined4 *)(iVar3 + 0x90a4);
    }
    guard_check_icall(uVar4);
    uVar4 = (**(code **)(unaff_EBP + -0x1c))();
    pcVar2 = *(code **)(*piVar1 + 0x68);
    guard_check_icall(*(int *)(unaff_EBX + 0x20),*(undefined4 *)(*(int *)(unaff_EBX + 0x20) + -0xc),
                      unaff_EBX + 0x10,0x25);
    (*pcVar2)();
    pcVar2 = *(code **)(**(int **)(unaff_EBP + -0x14) + 0x30);
    guard_check_icall(uVar4);
    (*pcVar2)();
  }
  local_c[0] = 0x8329e8;
  FUN_00406b10();
  local_c[0] = 0x8329ed;
  __EH_epilog3_align();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[138] */
/* 008329f0  FUN_008329f0  389 bytes, 0 callers */

void FUN_008329f0(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar3 == 0) {
    FUN_007f63a9(param_1,param_2,param_3);
    return;
  }
  iVar3 = param_2[0x1d];
  iVar1 = param_2[0x1e];
  local_18 = param_2[0x1f];
  local_14 = param_2[0x20];
  if (0x13 < *(int *)(in_ECX + 0xc000)) {
    local_18 = local_18 + -1;
    local_14 = local_14 + -1;
  }
  pcVar2 = *(code **)(*param_2 + 0xd0);
  guard_check_icall();
  iVar4 = (*pcVar2)();
  if (iVar4 == 0) {
    pcVar2 = *(code **)(*param_2 + 0xd4);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) goto LAB_00832a72;
    local_c = 0;
  }
  else {
LAB_00832a72:
    local_c = 1;
  }
  local_8 = 0;
  pcVar2 = *(code **)(*param_2 + 0xdc);
  if (*(int *)(in_ECX + 0x15e4) < 4) {
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) goto LAB_00832ae6;
  }
  else {
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) {
      local_8 = 3;
      goto LAB_00832ae6;
    }
  }
  pcVar2 = *(code **)(*param_2 + 0xd8);
  guard_check_icall();
  iVar4 = (*pcVar2)();
  if (iVar4 == 0) {
    if (local_c != 0) {
      local_8 = 1;
    }
  }
  else {
    local_8 = local_c * 2;
  }
LAB_00832ae6:
  if (*(int *)(in_ECX + 0x6ae4) != 0) {
    pcVar2 = *(code **)(*(int *)(in_ECX + 0x6a50) + 0x10);
    guard_check_icall(param_1,iVar3,iVar1,local_18,local_14,local_8,0xff);
    (*pcVar2)();
  }
  if (*(int *)(in_ECX + 0x166c) != 0) {
    FUN_007e94b8(param_1,iVar3,iVar1,local_18,local_14,local_8,1,1,0,0,0,0,0xff);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[147] */
/* 00832b75  OnDrawRibbonMainPanelButtonBorder  33 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall
   CMFCVisualManagerOffice2007::OnDrawRibbonMainPanelButtonBorder(class CDC *,class CMFCRibbonButton
   *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2007::OnDrawRibbonMainPanelButtonBorder
          (CMFCVisualManagerOffice2007 *this,CDC *param_1,CMFCRibbonButton *param_2)

{
  int iVar1;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    FUN_007f64a5(param_1,param_2);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[155] */
/* 00832b96  FUN_00832b96  117 bytes, 0 callers */

void FUN_00832b96(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_007f64cc(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else if (0x13 < *(int *)(in_ECX + 0xc000)) {
    iVar1 = *(int *)(in_ECX + 0x4fe0);
    guard_check_icall(param_1,param_3,param_4,param_5 + 2,param_6,0,0xff);
    (**(code **)(iVar1 + 0x14))();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[145] */
/* 00832c0b  FUN_00832c0b  101 bytes, 0 callers */

void FUN_00832c0b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008a626b(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar1 = *(int *)(in_ECX + 0x29b0);
    guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
    (**(code **)(iVar1 + 0x10))();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[136] */
/* 00832c70  FUN_00832c70  802 bytes, 0 callers */

undefined4
FUN_00832c70(undefined4 param_1,int param_2,LONG param_3,int param_4,LONG param_5,int param_6,
            undefined4 param_7,int param_8,undefined4 param_9,int param_10)

{
  LONG LVar1;
  LONG LVar2;
  CMFCVisualManagerOffice2007 *pCVar3;
  CMFCVisualManagerOffice2007 *pCVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  CMFCVisualManagerOffice2007 *in_ECX;
  int iVar9;
  code *pcVar10;
  CMFCVisualManagerBitmapCache *pCVar11;
  int local_2c;
  CMFCVisualManagerBitmapCache *local_28;
  CMFCVisualManagerOffice2007 *local_24;
  undefined4 local_20;
  CMFCVisualManagerOffice2007 *local_1c;
  CMFCVisualManagerOffice2007 *local_18;
  CMFCVisualManagerOffice2007 *local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  local_c = param_1;
  local_10 = param_2;
  local_14 = in_ECX;
  iVar5 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar5 == 0) {
    uVar6 = FUN_007f656a(local_c,local_10,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_10);
    return uVar6;
  }
  local_20 = *(undefined4 *)(in_ECX + 0x9090);
  iVar5 = FUN_0079d98a(&PTR_s_CMFCRibbonMainPanel_009a1678);
  if (iVar5 != 0) {
    pcVar10 = *(code **)(*(int *)in_ECX + 0x2f4);
    guard_check_icall();
    iVar5 = (*pcVar10)();
    InflateRect((LPRECT)&param_3,iVar5,iVar5);
    pcVar10 = *(code **)(*(int *)(in_ECX + 0x4e68) + 0x10);
    guard_check_icall(local_c,param_3,param_4,param_5,param_6,0,0xff);
    goto LAB_00832f49;
  }
  local_8 = *(int *)(param_2 + 0x68);
  if (local_8 != 0) {
    local_20 = *(undefined4 *)(in_ECX + 0x9094);
  }
  iVar5 = *(int *)(param_2 + 0x108);
  local_18 = in_ECX + 0x4b78;
  local_14 = in_ECX + 0x4a00;
  local_1c = in_ECX + 0xbdf0;
  local_24 = in_ECX + 0xbdc4;
  iVar7 = FUN_0086bc5b();
  if ((*(int *)(iVar5 + 0x19c) != 0) && ((iVar7 == 0 || (*(int *)(iVar7 + 0xc4) == 0)))) {
    local_18 = in_ECX + 0x8c18;
    local_14 = in_ECX + 0x8aa0;
    local_1c = in_ECX + 0xbd6c;
    local_24 = in_ECX + 0xbd40;
    if (local_8 == 0) {
      local_20 = *(undefined4 *)(in_ECX + 0x90fc);
    }
    else {
      local_20 = *(undefined4 *)(in_ECX + 0x9100);
    }
  }
  iVar7 = FUN_0086c441();
  pCVar4 = local_14;
  pCVar3 = local_24;
  LVar2 = param_5;
  iVar5 = param_4;
  LVar1 = param_3;
  if (iVar7 != 0) {
    return local_20;
  }
  if (param_10 - param_8 < 1) {
    return local_20;
  }
  if (*(int *)(local_14 + 0x94) == 0) {
    return local_20;
  }
  iVar7 = *(int *)(local_18 + 0x94);
  iVar9 = param_6;
  if (iVar7 != 0) {
    iVar9 = param_6 - (param_10 - param_8);
  }
  local_10 = iVar9;
  if (local_24 == (CMFCVisualManagerOffice2007 *)0x0) {
LAB_00832e9f:
    local_8 = (uint)(local_8 != 0);
    pcVar10 = *(code **)(*(int *)pCVar4 + 0x10);
    guard_check_icall(local_c,LVar1,iVar5,LVar2,iVar9,local_8,0xff);
    (*pcVar10)();
  }
  else {
    local_2c = *(int *)(local_14 + 0x130) - *(int *)(local_14 + 0x128);
    local_28 = (CMFCVisualManagerBitmapCache *)(iVar9 - param_4);
    local_24 = (CMFCVisualManagerOffice2007 *)local_28;
    iVar8 = CMFCVisualManagerBitmapCache::FindIndex
                      ((CMFCVisualManagerBitmapCache *)pCVar3,(CSize *)&local_2c);
    if ((iVar8 == -1) &&
       (iVar8 = CMFCVisualManagerBitmapCache::CacheY
                          ((CMFCVisualManagerBitmapCache *)pCVar3,(int)local_24,
                           (CMFCControlRenderer *)pCVar4), iVar8 == -1)) goto LAB_00832e9f;
    CMFCVisualManagerBitmapCache::Get((CMFCVisualManagerBitmapCache *)pCVar3,iVar8);
    local_8 = (uint)(local_8 != 0);
    FUN_0082eb09(local_c,LVar1,iVar5,LVar2,iVar9,*(undefined4 *)(pCVar4 + 0x158),
                 *(int *)(pCVar4 + 0x130) - *(int *)(pCVar4 + 0x160),local_8,0xff);
  }
  iVar9 = local_10;
  pCVar3 = local_18;
  iVar5 = param_6;
  if (iVar7 == 0) {
    return local_20;
  }
  if (local_1c != (CMFCVisualManagerOffice2007 *)0x0) {
    pCVar11 = (CMFCVisualManagerBitmapCache *)(param_6 - local_10);
    local_2c = *(int *)(local_18 + 0x130) - *(int *)(local_18 + 0x128);
    local_28 = pCVar11;
    iVar7 = CMFCVisualManagerBitmapCache::FindIndex
                      ((CMFCVisualManagerBitmapCache *)local_1c,(CSize *)&local_2c);
    pCVar4 = local_1c;
    if ((iVar7 != -1) ||
       (iVar7 = CMFCVisualManagerBitmapCache::CacheY
                          ((CMFCVisualManagerBitmapCache *)local_1c,(int)pCVar11,
                           (CMFCControlRenderer *)pCVar3), iVar7 != -1)) {
      CMFCVisualManagerBitmapCache::Get((CMFCVisualManagerBitmapCache *)pCVar4,iVar7);
      FUN_0082eb09(local_c,LVar1,iVar9,LVar2,iVar5,*(undefined4 *)(pCVar3 + 0x158),
                   *(int *)(pCVar3 + 0x130) - *(int *)(pCVar3 + 0x160),local_8,0xff);
      return local_20;
    }
  }
  pcVar10 = *(code **)(*(int *)pCVar3 + 0x10);
  guard_check_icall(local_c,LVar1,iVar9,LVar2,iVar5,local_8,0xff);
LAB_00832f49:
  (*pcVar10)();
  return local_20;
}




/* vtable slots: CMFCVisualManagerOffice2007[137] */
/* 00832f92  FUN_00832f92  306 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00832f92(int *param_1,int param_2,int param_3,LONG param_4,int param_5,LONG param_6)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  int local_18;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_007f6673(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar2 = FUN_0079d98a(&PTR_s_CMFCRibbonMainPanel_009a1678);
    if (iVar2 == 0) {
      CStringT<>(*(undefined4 *)(param_2 + 0xfc));
      if (*(int *)(local_18 + -0xc) != 0) {
        if (*(int *)(param_2 + 0x1b8) == 0) {
          InflateRect((LPRECT)&param_3,-1,-1);
          if ((param_5 - param_3 & 1U) == 0) {
            param_5 = param_5 + -1;
          }
          iVar2 = 0;
        }
        else {
          param_5 = *(int *)(param_2 + 0x188);
          InflateRect((LPRECT)&param_3,-1,-1);
          iVar2 = -1;
        }
        OffsetRect((LPRECT)&param_3,iVar2,-1);
        pcVar1 = *(code **)(*param_1 + 0x30);
        if (*(int *)(param_2 + 0x68) == 0) {
          uVar3 = *(undefined4 *)(in_ECX + 0x9098);
        }
        else {
          uVar3 = *(undefined4 *)(in_ECX + 0x909c);
        }
        guard_check_icall(uVar3);
        uVar3 = (*pcVar1)();
        iVar2 = *param_1;
        guard_check_icall(local_18,*(undefined4 *)(local_18 + -0xc),&param_3,0x8825);
        (**(code **)(iVar2 + 0x68))();
        pcVar1 = *(code **)(*param_1 + 0x30);
        guard_check_icall(uVar3);
        (*pcVar1)();
      }
      FUN_00406b10();
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[168] */
/* 008330c4  FUN_008330c4  595 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008330c4(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  HRGN pHVar5;
  CMFCVisualManagerOffice2007 *in_ECX;
  int iVar6;
  CMFCVisualManagerOffice2007 *pCVar7;
  undefined **local_38;
  int local_34;
  int local_30;
  CMFCVisualManagerOffice2007 *local_2c;
  undefined4 local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x8330d0;
  local_28 = param_1;
  local_30 = param_2;
  local_2c = in_ECX;
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar3 == 0) {
    FUN_008aaddf(local_28,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                 param_11);
  }
  else {
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x7ee0) + 0x10);
    guard_check_icall(local_28,param_3,param_4,param_5,param_6,0,0xff);
    (*pcVar1)();
    pCVar7 = local_2c;
    iVar3 = local_30;
    local_38 = *(undefined ***)(local_2c + 0x8020);
    local_34 = *(int *)(local_2c + 0x8024);
    local_24.left = param_3 + *(int *)(local_2c + 0x8018);
    local_24.top = param_4 + *(int *)(local_2c + 0x801c);
    local_24.right = param_5 - (int)local_38;
    local_24.bottom = param_6 - local_34;
    if (param_11 == 0) {
      IntersectRect((LPRECT)&param_7,(LPRECT)&param_7,&local_24);
      BVar4 = IsRectEmpty((RECT *)&param_7);
      if ((BVar4 == 0) || (*(int *)(local_30 + 0x114) != *(int *)(local_30 + 0x10c))) {
        local_38 = CRgn::vftable;
        local_34 = 0;
        local_8 = 0;
        pHVar5 = CreateRectRgnIndirect(&local_24);
        Attach(pHVar5);
        FUN_0079eeb5(&local_38);
        BVar4 = IsRectEmpty((RECT *)&param_7);
        if (BVar4 == 0) {
          param_7 = (local_24.left - local_24.right) + param_9;
          iVar3 = *(int *)(pCVar7 + 0x8058);
          guard_check_icall(local_28,param_7,param_8,param_9,param_10,0,0xff);
          (**(code **)(iVar3 + 0x10))();
          pCVar7 = local_2c;
        }
        else {
          param_7 = local_24.left;
          param_8 = local_24.top;
          param_10 = local_24.bottom;
          param_9 = local_24.left;
        }
        iVar3 = param_9;
        if (param_9 != local_24.right) {
          iVar2 = *(int *)(pCVar7 + 0x81d0);
          iVar6 = param_9 + (*(int *)(pCVar7 + 0x8300) - *(int *)(pCVar7 + 0x82f8));
          param_7 = param_9;
          param_9 = iVar6;
          guard_check_icall(local_28,iVar3,param_8,iVar6,param_10,0,0xff);
          (**(code **)(iVar2 + 0x10))();
        }
        FUN_0079eeb5(0);
        local_38 = CRgn::vftable;
        FUN_00416100();
      }
    }
    else if (*(int *)(local_30 + 0x114) != *(int *)(local_30 + 0x10c)) {
      iVar6 = CMFCControlRenderer::GetImageCount((CMFCControlRenderer *)(local_2c + 0x8348));
      iVar2 = *(int *)(local_2c + 0x8348);
      guard_check_icall(local_28,local_24.left,local_24.top,local_24.right,local_24.bottom,
                        (*(int *)(iVar3 + 0x114) - *(int *)(iVar3 + 0x10c)) % iVar6,0xff);
      (**(code **)(iVar2 + 0x10))();
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[157] */
/* 00833317  FUN_00833317  132 bytes, 0 callers */

void FUN_00833317(CDC *param_1,undefined4 param_2,int param_3,LONG param_4,int param_5,LONG param_6)

{
  int iVar1;
  HBRUSH hbr;
  CMFCVisualManagerOffice2007 *in_ECX;
  int local_1c;
  LONG LStack_18;
  int local_14;
  LONG LStack_10;
  undefined4 local_c;
  CDC *local_8;
  
  local_8 = param_1;
  local_c = param_2;
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008a6364(local_8,local_c,param_3,param_4,param_5,param_6);
  }
  else {
    param_5 = param_5 + 2;
    hbr = (HBRUSH)0x0;
    if (in_ECX != (CMFCVisualManagerOffice2007 *)0xffffff04) {
      hbr = *(HBRUSH *)(in_ECX + 0x100);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,hbr);
    local_14 = param_3 + 2;
    local_1c = param_3;
    LStack_18 = param_4;
    LStack_10 = param_6;
    CMFCVisualManagerOffice2007::DrawSeparator(in_ECX,local_8,(CRect *)&local_1c,0);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[166] */
/* 0083339b  FUN_0083339b  152 bytes, 0 callers */

void FUN_0083339b(CDC *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008aaf61(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    CMFCVisualManagerOffice2007::DrawSeparator
              (in_ECX,param_1,(CRect *)&param_3,(CPen *)(in_ECX + 0x8f30),(CPen *)(in_ECX + 0x8f28),
               1);
    param_4 = param_4 + -2;
    param_6 = param_6 + 2;
    iVar1 = (param_5 - param_3) / 2;
    param_5 = iVar1 + 1 + param_3;
    param_3 = param_3 + -1 + iVar1;
    CMFCVisualManagerOffice2007::DrawSeparator
              (in_ECX,param_1,(CRect *)&param_3,(CPen *)(in_ECX + 0x8f30),(CPen *)(in_ECX + 0x8f28),
               0);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[167] */
/* 00833433  FUN_00833433  136 bytes, 0 callers */

void FUN_00833433(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,undefined4 param_9)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar2;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008aafe6(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  else {
    uVar2 = 0;
    if (param_8 == 0) {
      if (param_7 != 0) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 2;
    }
    iVar1 = *(int *)(in_ECX + 0x7a78);
    guard_check_icall(param_1,param_3,param_4,param_5,param_6,1,1,uVar2,0xff);
    (**(code **)(iVar1 + 0x18))();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[165] */
/* 008334bb  FUN_008334bb  156 bytes, 0 callers */

void FUN_008334bb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,int param_9,
                 undefined4 param_10)

{
  byte bVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008ab07b(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  }
  else {
    bVar1 = 0;
    if (param_9 == 0) {
      if (param_8 != 0) {
        bVar1 = 1;
      }
    }
    else {
      bVar1 = -(param_8 != 0) & 2;
    }
    iVar2 = *(int *)(in_ECX + (-(uint)(param_7 != 0) & 0x178) + 0x7bf0);
    guard_check_icall(param_1,param_3,param_4,param_5,param_6,1,1,bVar1,0xff);
    (**(code **)(iVar2 + 0x18))();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[163] */
/* 00833557  FUN_00833557  373 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00833557(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  CMFCVisualManagerOffice2007 *in_ECX;
  bool bVar10;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar6 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar6 == 0) {
    uVar7 = FUN_008ab25d(param_1,param_2,param_3);
  }
  else {
    iVar6 = param_3[0x1d];
    iVar1 = param_3[0x1e];
    iVar2 = param_3[0x1f];
    iVar3 = param_3[0x20];
    pcVar4 = *(code **)(*param_3 + 0xd0);
    guard_check_icall();
    iVar8 = (*pcVar4)();
    pcVar4 = *(code **)(*param_3 + 0xe0);
    guard_check_icall();
    iVar9 = (*pcVar4)();
    iVar5 = param_3[0x72];
    if ((iVar8 != 0) || (iVar9 != 0)) {
      local_18.left = iVar6;
      local_18.top = iVar1;
      local_18.right = iVar2;
      local_18.bottom = iVar3;
      InflateRect(&local_18,-1,-1);
      bVar10 = false;
      pcVar4 = *(code **)(*param_3 + 0xd8);
      guard_check_icall();
      iVar6 = (*pcVar4)();
      if (iVar6 == 0) {
        if (iVar9 != 0) {
          bVar10 = iVar8 == 0;
        }
      }
      else if (iVar8 != 0) {
        bVar10 = true;
      }
      iVar6 = *(int *)(in_ECX + 0x7900);
      guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom,bVar10,
                        0xff);
      (**(code **)(iVar6 + 0x10))();
    }
    pcVar4 = *(code **)(*param_3 + 0xdc);
    guard_check_icall();
    iVar6 = (*pcVar4)();
    if (iVar6 == 0) {
      if (iVar8 == 0) {
        uVar7 = *(undefined4 *)(in_ECX + 0x8fa8);
      }
      else {
        uVar7 = *(undefined4 *)(in_ECX + 0x8f94);
      }
    }
    else if (iVar5 == 0) {
      uVar7 = *(undefined4 *)(in_ECX + 0x8fac);
    }
    else {
      uVar7 = *(undefined4 *)(in_ECX + 0x8fb0);
    }
  }
  return uVar7;
}




/* vtable slots: CMFCVisualManagerOffice2007[131] */
/* 008336cc  OnDrawRibbonTabsFrame  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::OnDrawRibbonTabsFrame(class CDC *,class CMFCRibbonBar *,class CRect)
   
   Library: Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2007::OnDrawRibbonTabsFrame
          (CMFCVisualManagerOffice2007 *this,undefined4 param_1,undefined4 param_2,
          undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    uVar2 = FUN_007f6d23(param_1,param_2,param_4,param_5,param_6,param_7);
  }
  else {
    uVar2 = *(ulong *)(this + 0x9084);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[95] */
/* 00833705  FUN_00833705  150 bytes, 0 callers */

void FUN_00833705(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008ab378(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    iVar1 = *(int *)(in_ECX + 0x3570);
    guard_check_icall(param_1,*param_2,param_2[1] + -1,param_2[2],param_2[3],param_5 != 0,0xff);
    (**(code **)(iVar1 + 0x10))();
    local_c = 0;
    local_8 = 0;
    FUN_00814d1c(param_1,param_4,param_2,0,&local_c);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[18] */
/* 0083379b  FUN_0083379b  744 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0083379b(CDC *param_1,CObject *param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  HWND pHVar7;
  CWnd *pCVar8;
  CMFCVisualManagerOffice2007 *in_ECX;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 local_3c [8];
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  CObject *local_24;
  CDC *local_20;
  CMFCVisualManagerOffice2007 *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = param_1;
  local_24 = param_2;
  local_1c = in_ECX;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  pCVar3 = local_24;
  if (((iVar2 == 0) || (param_2 == (CObject *)0x0)) || (*(int *)(param_2 + 0x8c) != 0)) {
    FUN_008ab487(local_20,local_24,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  local_34 = param_3;
  local_30 = param_4;
  local_2c = param_5;
  local_28 = param_6;
  iVar2 = FUN_0079d98a(&PTR_s_CMFCRibbonStatusBar_009a090c);
  if (iVar2 == 0) {
    iVar2 = FUN_0079d98a(&PTR_s_CMFCRibbonBar_009a1608);
    if (iVar2 == 0) {
      uVar4 = FUN_0079d98a(&PTR_s_CMFCRibbonPanelMenuBar_009a1a6c);
      if (param_7 == 0) {
        uVar9 = 0;
        if (uVar4 != 0) {
          uVar9 = uVar4 & ~-(uint)(*(int *)(pCVar3 + 0xddc) != 0);
        }
        iVar2 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
        if (iVar2 != 0) {
          if ((uVar9 == 0) && (iVar2 = FUN_0079d98a(&PTR_s_CMFCColorBar_00a007bc), iVar2 == 0)) {
            iVar2 = *(int *)local_1c;
            piVar5 = (int *)FUN_007fe1cf(local_3c);
            pcVar1 = *(code **)(iVar2 + 0x2dc);
            guard_check_icall();
            iVar6 = (*pcVar1)();
            pCVar3 = local_24;
            iVar2 = *piVar5;
            local_18.left = 0;
            local_18.top = 0;
            local_18.right = 0;
            local_18.bottom = 0;
            GetClientRect(*(HWND *)(local_24 + 0x20),&local_18);
            if (local_18.right - local_2c < 0x32) {
              local_2c = local_18.right;
            }
            local_34 = ~-(uint)(*(int *)(pCVar3 + 0xd40) != 0) & iVar2 + iVar6 + 1 + param_3;
            pHVar7 = GetParent(*(HWND *)(pCVar3 + 0x20));
            pCVar8 = CWnd::FromHandle(pHVar7);
            if (((pCVar8 != (CWnd *)0x0) &&
                (iVar2 = FUN_0079d98a(&PTR_s_CMFCPopupMenu_00a00790), iVar2 != 0)) &&
               (*(int *)(pCVar8 + 0x1168) == 0)) {
              pcVar1 = *(code **)(*(int *)local_1c + 0x2dc);
              guard_check_icall();
              iVar2 = (*pcVar1)();
              piVar5 = (int *)FUN_007fe1cf(local_3c);
              local_34 = iVar2 * 3 + (*piVar5 + 1) * 2 + param_3;
            }
          }
          CMFCVisualManagerOffice2007::DrawSeparator(local_1c,local_20,(CRect *)&local_34,1);
          return;
        }
        iVar2 = (int)(local_2c - local_34) / 5;
        local_34 = local_34 + iVar2;
        local_2c = local_2c - iVar2;
LAB_008339f4:
        CMFCVisualManagerOffice2007::DrawSeparator
                  (local_1c,local_20,(CRect *)&local_34,(CPen *)(local_1c + 0x8f30),
                   (CPen *)(local_1c + 0x1e8),(uint)(param_7 == 0));
        return;
      }
      if (uVar4 == 0) {
        iVar2 = (local_28 - local_30) / 5;
        local_30 = local_30 + iVar2;
        local_28 = local_28 - iVar2;
        goto LAB_008339f4;
      }
    }
    if ((int)(param_5 - param_3) < *(int *)(local_1c + 0x151c)) {
      param_3 = param_5 - *(int *)(local_1c + 0x151c);
    }
    uVar11 = 1;
    uVar10 = 1;
  }
  else {
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonStatusBar_009a090c,pCVar3);
    param_4 = param_4 + -5;
    param_3 = param_3 - 1;
    param_6 = param_6 + (-(uint)(*(int *)(pCVar3 + 0x16f8) != 0) & 0xfffffffd) + 5;
    param_5 = param_5 + 1;
    uVar11 = 3;
    uVar10 = 2;
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  FUN_007e94b8(local_20,param_3,param_4,param_5,param_6,0,uVar10,uVar11,0,0,0,0,0xff);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[191] */
/* 00833a83  FUN_00833a83  125 bytes, 0 callers */

void FUN_00833a83(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar1 == 0) || (*(int *)(in_ECX + 0x2bbc) == 0)) {
    FUN_008ab717(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar1 = *(int *)(in_ECX + 0x2b28);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,1,1,param_6 == 2,0xff);
    (**(code **)(iVar1 + 0x18))();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[23] */
/* 00833b00  FUN_00833b00  172 bytes, 0 callers */

void FUN_00833b00(undefined4 param_1,int param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6
                 ,undefined4 param_7,uint param_8)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008ab7f7(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else if ((*(int *)(param_2 + 0x2d4) == 0) || ((param_8 & 0x8000000) == 0)) {
    OffsetRect((LPRECT)&param_3,1,0);
    FUN_007e94b8(param_1,param_3,param_4,param_5,param_6,0,2,3,0,0,0,0,0xff);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[26] */
/* 00833bac  FUN_00833bac  124 bytes, 0 callers */

void FUN_00833bac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar1 == 0) || (*(int *)(in_ECX + 0x57c) == 0)) {
    OnDrawStatusBarSizeBox(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    FUN_007e94b8(param_1,param_3,param_4,param_5,param_6,0,2,2,0,0,0,0,0xff);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[61] */
/* 00833c28  FUN_00833c28  998 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00833c28(CDC *param_1,LONG param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int *param_8)

{
  code *pcVar1;
  CDC *this;
  int iVar2;
  HRGN pHVar3;
  int iVar4;
  byte bVar5;
  CMFCVisualManagerOffice2007 *in_ECX;
  int *piVar6;
  undefined1 local_68 [8];
  undefined4 local_60;
  undefined **local_5c;
  undefined4 local_58;
  int *local_54;
  undefined1 local_50 [4];
  int local_4c;
  CMFCVisualManagerOffice2007 *local_48;
  CDC *local_44;
  int local_40;
  CMFCVisualManagerOffice2007 *local_3c;
  int local_38;
  POINT local_34;
  LONG local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x833c34;
  local_44 = param_1;
  local_38 = param_7;
  local_54 = param_8;
  local_3c = in_ECX;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*param_8 + 0x288);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    param_7 = local_38;
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*param_8 + 0x2a8);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      param_7 = local_38;
      if (iVar2 == 0) {
        pcVar1 = *(code **)(*param_8 + 0x28c);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        param_7 = local_38;
        if (iVar2 == 0) {
          pcVar1 = *(code **)(*param_8 + 0x290);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          param_7 = local_38;
          if (iVar2 == 0) {
            local_40 = param_8[0x24];
            local_48 = (CMFCVisualManagerOffice2007 *)param_8[0x45];
            pcVar1 = *(code **)(*param_8 + 0x1e4);
            guard_check_icall(param_6);
            local_4c = (*pcVar1)();
            pcVar1 = *(code **)(*param_8 + 0x280);
            guard_check_icall();
            iVar2 = (*pcVar1)();
            if (iVar2 == 0) {
              if (local_4c == -1) {
                if (local_38 == 0) {
                  local_4c = *(int *)(in_ECX + 0x8f84);
                }
                else {
                  local_4c = *(int *)(in_ECX + 0x8f88);
                }
              }
              bVar5 = -(local_38 != 0) & 3;
              if ((CMFCVisualManagerOffice2007 *)param_6 == local_48) {
                bVar5 = (-(local_38 != 0) & 3U) + 1;
              }
              local_40 = (-(uint)(local_40 != 0) & 0xfffffe88) + 0x3860;
              iVar2 = *(int *)(in_ECX + local_40);
              guard_check_icall(local_44,param_2,param_3,param_4,param_5,bVar5,0xff);
              (**(code **)(iVar2 + 0x10))();
              piVar6 = local_54;
              if (local_54[0x4d] != 0) {
                iVar2 = FUN_007c2511();
                local_4c = *(int *)(iVar2 + 0x28);
              }
            }
            else {
              if ((local_38 != 0) ||
                 (local_4c = 1, (CMFCVisualManagerOffice2007 *)param_6 == local_48)) {
                local_4c = 2;
              }
              local_58 = 0;
              local_5c = CRgn::vftable;
              local_8 = 0;
              local_34.x = param_2;
              local_2c = param_2;
              local_28 = param_3;
              local_20 = param_3;
              if (local_40 == 0) {
                local_18 = param_5 + 2;
                iVar2 = (param_5 + 1) - param_3;
                param_3 = param_3 + 1;
                param_5 = param_5 + 1;
                local_24 = param_4;
                local_1c = param_4 - iVar2;
              }
              else {
                local_18 = param_5 + 1;
                local_24 = param_4 - (param_5 - param_3);
                local_1c = param_4;
              }
              local_1c = local_1c + 1;
              local_24 = local_24 + 1;
              local_34.y = local_18;
              pHVar3 = CreatePolygonRgn(&local_34,4,2);
              Attach(pHVar3);
              pcVar1 = *(code **)(*(int *)local_44 + 0x1c);
              guard_check_icall();
              local_60 = (*pcVar1)();
              FUN_0079ef02(&local_5c,1);
              this = local_44;
              local_48 = local_3c + (-(uint)(local_40 != 0) & 0xfffffe88) + 0x3b50;
              pcVar1 = *(code **)(*(int *)local_48 + 0x10);
              guard_check_icall(local_44,param_2,param_3,param_4,param_5,local_4c,0xff);
              (*pcVar1)();
              local_48 = (CMFCVisualManagerOffice2007 *)
                         FUN_0079efbc(local_3c + (uint)(local_38 != 0) * 8 + 0x8f18);
              iVar2 = local_40;
              if (local_40 == 0) {
                FUN_0079ec58(local_50,local_24,local_20);
                iVar4 = local_1c;
              }
              else {
                FUN_0079ec58(local_50,local_24 + -1,local_20);
                iVar4 = local_1c + -1;
              }
              CDC::LineTo(this,iVar4,local_18 + -1);
              FUN_0079efbc(local_3c + (uint)(local_38 != 0) * 8 + 0x8f08);
              if (iVar2 == 0) {
                FUN_0079ec58(local_50,local_24 + -2,local_20 + 1);
                iVar4 = local_18 + -2;
                iVar2 = local_1c;
              }
              else {
                FUN_0079ec58(local_68,local_24 + -1,local_20 + 1);
                iVar4 = local_18 + -1;
                iVar2 = local_1c + -2;
              }
              CDC::LineTo(this,iVar2,iVar4);
              FUN_0079efbc(local_48);
              FUN_0079eeb5(0);
              iVar2 = FUN_007c2511();
              local_4c = *(int *)(iVar2 + 0x68);
              pcVar1 = *(code **)(*(int *)this + 0x20);
              guard_check_icall(local_60);
              (*pcVar1)();
              local_8 = 0xffffffff;
              local_5c = CRgn::vftable;
              FUN_00416100();
              piVar6 = local_54;
            }
            pcVar1 = *(code **)(*(int *)local_3c + 0xfc);
            guard_check_icall(local_44,param_2,param_3,param_4,param_5,param_6,local_38,piVar6,
                              local_4c);
            (*pcVar1)();
            goto LAB_00834006;
          }
        }
      }
    }
  }
  FUN_008ab927(local_44,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
LAB_00834006:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[66] */
/* 0083400e  OnDrawTabsButtonBorder  42 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2007::OnDrawTabsButtonBorder(class CDC
   *,class CRect &,class CMFCButton *,unsigned int,class CMFCBaseTabCtrl *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2007::OnDrawTabsButtonBorder
          (CMFCVisualManagerOffice2007 *this,CDC *param_1,CRect *param_2,CMFCButton *param_3,
          uint param_4,CMFCBaseTabCtrl *param_5)

{
  int iVar1;
  
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    CMFCVisualManagerOffice2003::OnDrawTabsButtonBorder
              ((CMFCVisualManagerOffice2003 *)this,param_1,param_2,param_3,param_4,param_5);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[94] */
/* 00834038  OnDrawTask  67 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2007::OnDrawTask(class CDC *,class
   CMFCTasksPaneTask *,class CImageList *,int,int)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2007::OnDrawTask
          (CMFCVisualManagerOffice2007 *this,CDC *param_1,CMFCTasksPaneTask *param_2,
          CImageList *param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = CanDrawImage(this);
  if ((iVar1 == 0) || (*(int *)(param_2 + 0x3c) == 0)) {
    FUN_008ac105(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    DrawSeparator(this,param_1,(CRect *)(param_2 + 0xc),1);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[90] */
/* 0083407b  FUN_0083407b  1076 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0083407b(CDC *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  COLORREF CVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar5;
  int iVar6;
  CDC *pCVar7;
  int *piVar8;
  code *pcVar9;
  undefined4 local_68;
  undefined4 local_64;
  CDrawingManager local_60 [8];
  int local_58;
  COLORREF local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  CDC *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int iStack_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x834087;
  local_3c = param_1;
  local_40 = param_2;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    FUN_008ac21b(param_1,param_2,param_3,param_4,param_5);
    goto LAB_008344a7;
  }
  local_38 = (int *)(param_2 + 0x34);
  local_50 = *local_38;
  local_4c = *(int *)(param_2 + 0x38);
  local_48 = *(int *)(param_2 + 0x3c);
  local_44 = *(int *)(param_2 + 0x40);
  CDrawingManager::CDrawingManager(local_60,local_3c);
  local_8 = 0;
  if (*(int *)(local_40 + 0x2c) == 0) {
    if (*(int *)(in_ECX + 0xc000) < 0x14) {
      piVar8 = local_38;
      if (param_3 == 0) {
        uVar3 = *(undefined4 *)(in_ECX + 0x1bc);
        uVar5 = *(undefined4 *)(in_ECX + 0x1c0);
      }
      else {
        uVar3 = *(undefined4 *)(in_ECX + 0x9044);
        uVar5 = *(undefined4 *)(in_ECX + 0x9048);
      }
      goto LAB_00834160;
    }
    if (param_3 == 0) {
      uVar3 = *(undefined4 *)(in_ECX + 0x1bc);
      uVar5 = *(undefined4 *)(in_ECX + 0x1c0);
    }
    else {
      uVar3 = *(undefined4 *)(in_ECX + 0x9044);
      uVar5 = *(undefined4 *)(in_ECX + 0x9048);
    }
LAB_00834192:
    FUN_00817362(*local_38,local_38[1],local_38[2],local_38[3],uVar3,uVar5,uVar5,uVar3,0,0x32);
  }
  else {
    if (0x13 < *(int *)(in_ECX + 0xc000)) {
      if (param_3 == 0) {
        uVar3 = *(undefined4 *)(in_ECX + 0x1c4);
        uVar5 = *(undefined4 *)(in_ECX + 0x1c8);
      }
      else {
        uVar3 = *(undefined4 *)(in_ECX + 0x904c);
        uVar5 = *(undefined4 *)(in_ECX + 0x9050);
      }
      goto LAB_00834192;
    }
    if (param_3 == 0) {
      uVar3 = *(undefined4 *)(in_ECX + 0x1c4);
      uVar5 = *(undefined4 *)(in_ECX + 0x1c8);
    }
    else {
      uVar3 = *(undefined4 *)(in_ECX + 0x904c);
      uVar5 = *(undefined4 *)(in_ECX + 0x9050);
    }
    piVar8 = (int *)(local_40 + 0x34);
LAB_00834160:
    FUN_00817861(*piVar8,piVar8[1],piVar8[2],piVar8[3],uVar5,uVar3,1,0,0);
  }
  pCVar7 = local_3c;
  if ((*(int *)(local_40 + 0x5c) == 0) ||
     (((local_4c - local_50) - local_44) + local_48 <= *(int *)(local_40 + 0x54))) {
    local_38 = (int *)0x0;
  }
  else {
    pcVar9 = *(code **)(*(int *)in_ECX + 0x16c);
    local_38 = (int *)0x1;
    guard_check_icall(local_3c,local_40,5,param_3,param_4,param_5);
    (*pcVar9)();
  }
  pcVar9 = *(code **)(*(int *)pCVar7 + 0x28);
  iVar2 = FUN_007c2511();
  guard_check_icall(iVar2 + 300);
  local_64 = (*pcVar9)();
  local_54 = GetTextColor(*(HDC *)(pCVar7 + 8));
  if ((param_5 == 0) || (param_3 == 0)) {
    pcVar9 = *(code **)(*(int *)pCVar7 + 0x30);
    iVar2 = *(int *)(local_40 + 0x60);
    if (iVar2 == -1) {
      if (*(int *)(local_40 + 0x2c) == 0) {
        iVar2 = *(int *)(in_ECX + 0x905c);
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x9054);
      }
    }
  }
  else {
    pcVar9 = *(code **)(*(int *)pCVar7 + 0x30);
    iVar2 = *(int *)(local_40 + 100);
    if (iVar2 == -1) {
      if (*(int *)(local_40 + 0x2c) == 0) {
        iVar2 = *(int *)(in_ECX + 0x9060);
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x9058);
      }
    }
  }
  guard_check_icall(iVar2);
  (*pcVar9)();
  uVar3 = FUN_0079f0b8(1);
  pCVar7 = local_3c;
  iVar2 = *(int *)(*(int *)(local_40 + 4) + 8);
  iVar6 = *(int *)(iVar2 + 0x3bc);
  local_30 = *(int *)(iVar2 + 0x3c0);
  if (iVar6 == -1) {
    iVar6 = *(int *)(in_ECX + 0x90);
  }
  iStack_28 = local_44;
  local_34 = iVar6;
  if (local_38 != (int *)0x0) {
    local_34 = *(int *)(local_40 + 0x54) + 5;
  }
  local_34 = local_34 + local_50;
  if (local_30 == -1) {
    local_30 = *(int *)(in_ECX + 0x94);
  }
  local_30 = local_4c + local_30;
  iVar2 = iVar6;
  if (param_5 != 0) {
    iVar2 = local_44 - local_4c;
  }
  local_2c = local_34;
  if (local_34 <= local_48 - iVar2) {
    if (param_5 != 0) {
      iVar6 = local_44 - local_4c;
    }
    local_2c = local_48 - iVar6;
  }
  piVar8 = (int *)(local_40 + 8);
  FUN_007c2378(piVar8,&local_34,0x8024);
  FUN_0079f0b8(uVar3);
  pcVar9 = *(code **)(*(int *)pCVar7 + 0x28);
  guard_check_icall(local_64);
  (*pcVar9)();
  pcVar9 = *(code **)(*(int *)pCVar7 + 0x30);
  guard_check_icall(local_54);
  (*pcVar9)();
  if ((param_5 != 0) && (*(int *)(*piVar8 + -0xc) != 0)) {
    FUN_0081507c(&local_58);
    local_24.left = local_50;
    iVar2 = (-(((local_44 - local_4c) + 1) / 2) - (local_58 + 1) / 2) + local_48;
    if (local_50 <= iVar2) {
      local_24.left = iVar2;
    }
    iVar2 = (-(((local_44 - local_4c) + 1) / 2) - (int)(local_54 + 1) / 2) + local_44;
    local_24.top = local_4c;
    if (local_4c <= iVar2) {
      local_24.top = iVar2;
    }
    local_24.right = local_24.left + local_58;
    local_24.bottom = local_54 + local_24.top;
    local_38 = (int *)local_24.left;
    if ((local_24.right <= local_48) && (local_24.bottom <= local_44)) {
      if (param_3 != 0) {
        iVar2 = FUN_007c2511();
        uVar3 = FUN_0079efbc(iVar2 + 0xd0);
        CVar4 = GetBkColor(*(HDC *)(local_3c + 8));
        iVar2 = FUN_007c2511();
        uVar1 = *(ulong *)(iVar2 + 0x58);
        iVar2 = FUN_007c2511();
        pCVar7 = local_3c;
        CDC::Draw3dRect(local_3c,&local_24,*(ulong *)(iVar2 + 0x6c),uVar1);
        pcVar9 = *(code **)(*(int *)pCVar7 + 0x2c);
        guard_check_icall(CVar4);
        (*pcVar9)();
        pCVar7 = local_3c;
        FUN_0079efbc(uVar3);
      }
      local_68 = 0;
      local_64 = 0;
      FUN_00814c80(pCVar7,(-(uint)(*(int *)(local_40 + 0x30) != 0) & 0xfffffff9) + 7,&local_24,0,
                   &local_68);
    }
  }
  FUN_0081510b();
LAB_008344a7:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[30] */
/* 008344af  FUN_008344af  227 bytes, 0 callers */

void FUN_008344af(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int param_6)

{
  code *pcVar1;
  int iVar2;
  HBRUSH hbr;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar2 == 0) || (*(int *)(in_ECX + 0x34c) == 0)) {
    FUN_008ac6ca(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    hbr = (HBRUSH)0x0;
    if (in_ECX != (CMFCVisualManagerOffice2007 *)0xffffff04) {
      hbr = *(HBRUSH *)(in_ECX + 0x100);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
    if (param_6 != 0) {
      pcVar1 = *(code **)(*(int *)(in_ECX + 0x2ca0) + 0x10);
      guard_check_icall(param_1,param_2,param_3,param_4,param_5,0,0xff);
      (*pcVar1)();
    }
    FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,0,1,1,0,0,0,0,0xff);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[180] */
/* 00834592  FUN_00834592  90 bytes, 0 callers */

undefined4 FUN_00834592(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5)

{
  int iVar1;
  undefined4 uVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (((iVar1 == 0) || (in_ECX == (CMFCVisualManagerOffice2007 *)0xffff70c0)) ||
     (*(int *)(in_ECX + 0x8f44) == 0)) {
    uVar2 = FUN_00793e28(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,*(HBRUSH *)(in_ECX + 0x8f44));
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOffice2007[60] */
/* 008345ec  FUN_008345ec  363 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008345ec(CDC *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  code *pcVar1;
  int iVar2;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  CDrawingManager local_20 [12];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x8345f8;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar2 != 0) && (param_6[0x4d] == 0)) {
    pcVar1 = *(code **)(*param_6 + 0x288);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*param_6 + 0x2a8);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        pcVar1 = *(code **)(*param_6 + 0x28c);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) {
          pcVar1 = *(code **)(*param_6 + 0x290);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if (iVar2 == 0) {
            local_14 = param_6[0x24];
            pcVar1 = *(code **)(*param_6 + 0x280);
            guard_check_icall();
            iVar2 = (*pcVar1)();
            if (iVar2 != 0) {
              local_14 = (-(uint)(local_14 != 0) & 0xfffffe88) + 0x3b50;
              iVar2 = *(int *)(in_ECX + local_14);
              guard_check_icall(param_1,param_2,param_3,param_4,param_5,0,0xff);
              (**(code **)(iVar2 + 0x10))();
              return;
            }
            CDrawingManager::CDrawingManager(local_20,param_1);
            uVar4 = *(undefined4 *)(in_ECX + 0x15c);
            local_8 = 0;
            uVar3 = *(undefined4 *)(in_ECX + 0x160);
            if (local_14 == 0) {
              uVar3 = uVar4;
              uVar4 = *(undefined4 *)(in_ECX + 0x160);
            }
            FUN_00817861(param_2,param_3,param_4,param_5,uVar3,uVar4,1,0,0);
            FUN_0081510b();
            return;
          }
        }
      }
    }
  }
  FUN_008ac94b(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[65] */
/* 00834757  FUN_00834757  571 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00834757(undefined4 param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,
                 CMFCButton *param_6,CObject *param_7)

{
  code *pcVar1;
  CMFCButton *this;
  CObject *pCVar2;
  CObject *pCVar3;
  int iVar4;
  HRGN pHVar5;
  HWND hWndTo;
  int iVar6;
  undefined4 uVar7;
  undefined **local_44;
  undefined4 local_40;
  CMFCVisualManagerOffice2007 *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  LONG local_30;
  undefined4 local_2c;
  LONG local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pCVar2 = param_7;
  this = param_6;
  uStack_4 = 0x3c;
  local_8 = 0x834763;
  local_38 = param_1;
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,param_7);
  iVar4 = CMFCVisualManagerOffice2007::CanDrawImage(local_3c);
  if (((iVar4 != 0) && (pCVar3 != (CObject *)0x0)) && (*(int *)(pCVar2 + 0x134) == 0)) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x280);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x288);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) {
        pcVar1 = *(code **)(*(int *)pCVar2 + 0x2a8);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 == 0) {
          pcVar1 = *(code **)(*(int *)pCVar2 + 0x28c);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          if (iVar4 == 0) {
            pcVar1 = *(code **)(*(int *)pCVar2 + 0x290);
            guard_check_icall();
            iVar4 = (*pcVar1)();
            if (iVar4 == 0) {
              iVar4 = CMFCButton::IsPressed(this);
              if ((iVar4 != 0) || (*(int *)(this + 0xb4) != 0)) {
                local_40 = 0;
                local_44 = CRgn::vftable;
                local_8 = 0;
                pHVar5 = CreateRectRgnIndirect((RECT *)&param_2);
                Attach(pHVar5);
                FUN_0079eeb5(&local_44);
                local_24.left = 0;
                local_24.top = 0;
                local_24.right = 0;
                local_24.bottom = 0;
                GetClientRect(*(HWND *)(pCVar3 + 0x20),&local_24);
                local_34 = 0;
                local_30 = 0;
                local_2c = 0;
                local_28 = 0;
                pcVar1 = *(code **)(*(int *)pCVar3 + 0x180);
                guard_check_icall(&local_34);
                (*pcVar1)();
                if (*(int *)(pCVar3 + 0x90) == 0) {
                  local_24.top = local_30;
                }
                else {
                  local_24.bottom = local_28;
                }
                if (this == (CMFCButton *)0x0) {
                  hWndTo = (HWND)0x0;
                }
                else {
                  hWndTo = *(HWND *)(this + 0x20);
                }
                MapWindowPoints(*(HWND *)(pCVar3 + 0x20),hWndTo,(LPPOINT)&local_24,2);
                pcVar1 = *(code **)(*(int *)local_3c + 0xf0);
                guard_check_icall(local_38,local_24.left,local_24.top,local_24.right,local_24.bottom
                                  ,pCVar3);
                (*pcVar1)();
                FUN_0079eeb5(0);
                iVar4 = *(int *)(local_3c + 0x33f8);
                uVar7 = 0xff;
                iVar6 = CMFCButton::IsPressed(this);
                guard_check_icall(local_38,param_2,param_3,param_4,param_5,(iVar6 != 0) + '\x01',
                                  uVar7);
                (**(code **)(iVar4 + 0x10))();
                local_44 = CRgn::vftable;
                FUN_00416100();
                goto LAB_0083498a;
              }
            }
          }
        }
      }
    }
  }
  FUN_008aca32(local_38,param_2,param_3,param_4,param_5,this,pCVar2);
LAB_0083498a:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[68] */
/* 00834992  FUN_00834992  417 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00834992(CDC *param_1,LONG param_2,int param_3,int param_4,LONG param_5,int *param_6)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  HBRUSH hbr;
  undefined4 uVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined1 local_28 [8];
  undefined **local_20 [2];
  CMFCVisualManagerOffice2007 *local_18;
  CDC *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_6;
  uStack_4 = 0x18;
  local_8 = 0x83499e;
  local_14 = param_1;
  local_18 = in_ECX;
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar3 != 0) && (piVar2[0x4d] == 0)) {
    pcVar1 = *(code **)(*piVar2 + 0x288);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      pcVar1 = *(code **)(*piVar2 + 0x2a8);
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
          if (iVar3 == 0) {
            pcVar1 = *(code **)(*piVar2 + 0x280);
            guard_check_icall();
            iVar3 = (*pcVar1)();
            if (iVar3 != 0) {
              iVar3 = FUN_007c2511();
              hbr = (HBRUSH)0x0;
              if (iVar3 != -200) {
                hbr = *(HBRUSH *)(iVar3 + 0xcc);
              }
              FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
              if (piVar2[0x24] != 0) {
                FUN_0079df60(0,1,*(undefined4 *)(local_18 + 0x9064));
                local_8 = 0;
                uVar4 = FUN_0079efbc(local_20);
                pcVar1 = *(code **)(*piVar2 + 0x17c);
                guard_check_icall();
                iVar3 = (*pcVar1)();
                FUN_0079ec58(local_28,param_2,iVar3 + param_3 + 1);
                pcVar1 = *(code **)(*piVar2 + 0x17c);
                guard_check_icall();
                iVar3 = (*pcVar1)();
                CDC::LineTo(local_14,param_4,iVar3 + param_3 + 1);
                FUN_0079efbc(uVar4);
                local_20[0] = CPen::vftable;
                FUN_00416100();
              }
              return 1;
            }
            return 0;
          }
        }
      }
    }
  }
  uVar4 = FUN_008acc5e(local_14,param_2,param_3,param_4,param_5,piVar2);
  return uVar4;
}




/* vtable slots: CMFCVisualManagerOffice2007[13] */
/* 00834b33  FUN_00834b33  1196 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00834b33(CDC *param_1,CObject *param_2,int param_3,LONG param_4,int param_5,int param_6,
                 LONG param_7,LONG param_8,LONG param_9,LONG param_10,undefined4 param_11)

{
  code *pcVar1;
  CMFCVisualManagerOffice2007 *pCVar2;
  CDC *pCVar3;
  int iVar4;
  uint uVar5;
  CObject *pCVar6;
  HBRUSH pHVar7;
  HWND pHVar8;
  CWnd *pCVar9;
  int iVar10;
  int iVar11;
  CMFCVisualManagerOffice2007 *in_ECX;
  int iVar12;
  undefined4 uVar13;
  LONG LVar14;
  tagRECT *ptVar15;
  undefined4 uVar16;
  CDrawingManager local_54 [4];
  int local_50;
  int local_4c;
  int local_48;
  CObject *local_44;
  CMFCVisualManagerOffice2007 *local_40;
  CObject *local_3c;
  CDC *local_38;
  undefined1 local_34 [8];
  int local_2c;
  uint local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x834b3f;
  local_38 = param_1;
  local_44 = param_2;
  pcVar1 = (code *)**(undefined4 **)param_2;
  local_40 = in_ECX;
  guard_check_icall();
  (*pcVar1)();
  iVar4 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar4 != 0) && (*(int *)(param_2 + 0x8c) == 0)) {
    iVar4 = FUN_0079d960(&PTR_s_CMFCColorBar_00a007bc);
    if (iVar4 == 0) {
      iVar4 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00);
      if (iVar4 != 0) {
        pcVar1 = *(code **)(*(int *)param_2 + 0x1c0);
        guard_check_icall();
        uVar5 = (*pcVar1)();
        local_3c = (CObject *)(uVar5 & 0xa000);
        if (local_3c == (CObject *)0x0) {
          uVar16 = *(undefined4 *)(in_ECX + 0x8f7c);
          uVar13 = *(undefined4 *)(in_ECX + 0x8f80);
        }
        else {
          uVar16 = *(undefined4 *)(in_ECX + 0x8f78);
          uVar13 = *(undefined4 *)(in_ECX + 0x8f74);
        }
        CDrawingManager::CDrawingManager((CDrawingManager *)&local_2c,local_38);
        local_8 = 0;
        FUN_00817362(param_3,param_4,param_5,param_6,uVar16,uVar13,uVar13,uVar16,
                     local_3c == (CObject *)0x0,0x32);
LAB_00834c10:
        FUN_0081510b();
        goto LAB_00834fd7;
      }
      iVar4 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
      if (iVar4 != 0) {
        pHVar7 = (HBRUSH)0x0;
        if (in_ECX != (CMFCVisualManagerOffice2007 *)0xfffffef4) {
          pHVar7 = *(HBRUSH *)(in_ECX + 0x110);
        }
        FillRect(*(HDC *)(local_38 + 4),(RECT *)&param_7,pHVar7);
        pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenuBar_00a00938,param_2);
        if (*(int *)(pCVar6 + 0xd40) == 0) {
          local_24.left = param_3;
          local_24.top = param_4;
          local_24.right = param_5;
          local_24.bottom = param_6;
          local_24.right = FUN_0085358c();
          local_24.right = local_24.right + local_24.left;
          InflateRect(&local_24,0,-1);
          pCVar3 = local_38;
          pHVar7 = (HBRUSH)0x0;
          if (in_ECX != (CMFCVisualManagerOffice2007 *)0xffffff04) {
            pHVar7 = *(HBRUSH *)(in_ECX + 0x100);
          }
          FillRect(*(HDC *)(local_38 + 4),&local_24,pHVar7);
          local_24.left = local_24.right;
          local_24.right = local_24.right + 2;
          CMFCVisualManagerOffice2007::DrawSeparator(in_ECX,pCVar3,(CRect *)&local_24,0);
        }
        goto LAB_00834fd7;
      }
      iVar4 = FUN_0079d98a(&PTR_s_CMFCStatusBar_009a0c24);
      if (iVar4 == 0) {
        iVar4 = FUN_0079d98a(&PTR_s_CMFCRibbonStatusBar_009a090c);
        if (iVar4 != 0) {
          pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonStatusBar_009a090c,param_2);
          pHVar8 = GetParent(*(HWND *)(param_2 + 0x20));
          pCVar9 = CWnd::FromHandle(pHVar8);
          FUN_0085aaf0(&local_2c,pCVar9);
          local_24.left = 0;
          local_24.top = 0;
          local_24.right = 0;
          local_24.bottom = 0;
          pcVar1 = *(code **)(*(int *)pCVar6 + 0x368);
          guard_check_icall(&local_24);
          local_50 = (*pcVar1)();
          iVar4 = *(int *)(pCVar6 + 0x16f8);
          local_3c = (CObject *)local_24.left;
          if (local_50 == 0) {
            local_3c = (CObject *)param_5;
          }
          local_48 = iVar4;
          pHVar8 = GetParent(*(HWND *)(local_44 + 0x20));
          pCVar9 = CWnd::FromHandle(pHVar8);
          pCVar2 = local_40;
          iVar11 = FUN_0082f5a7(pCVar9);
          iVar12 = (int)local_3c + local_2c;
          iVar10 = *(int *)(pCVar2 + 0x1988);
          local_3c = (CObject *)(uint)(iVar11 == 0);
          guard_check_icall(local_38,param_3 - local_2c,param_4,iVar12,
                            param_6 + (~-(uint)(iVar4 != 0) & local_28),local_3c,0xff);
          (**(code **)(iVar10 + 0x10))();
          if (local_50 == 0) goto LAB_00834fd7;
          local_24.right = local_24.right + local_2c;
          iVar4 = *(int *)(local_40 + 0x1b00);
          local_24.bottom = local_24.bottom + (~-(uint)(local_48 != 0) & local_28);
          ptVar15 = &local_24;
          local_24.left = local_24.left - *(int *)(local_40 + 0x1c38);
          pCVar6 = local_3c;
          goto LAB_00834dca;
        }
        iVar4 = FUN_0079d98a(&PTR_s_CMFCOutlookBarToolBar_0099ca8c);
        if (iVar4 == 0) goto LAB_00834fae;
        if (*(int *)(in_ECX + 0x3d5c) == 0) {
          CDrawingManager::CDrawingManager(local_54,local_38);
          local_8 = 1;
          FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(in_ECX + 0x164),
                       *(undefined4 *)(in_ECX + 0x168),1,0,0);
          goto LAB_00834c10;
        }
        iVar4 = *(int *)(in_ECX + 0x3cc8);
        guard_check_icall(local_38,param_3,param_4,param_5,param_6,0,0xff);
      }
      else {
        pHVar8 = GetParent(*(HWND *)(param_2 + 0x20));
        pCVar9 = CWnd::FromHandle(pHVar8);
        FUN_0085aaf0(&local_4c,pCVar9);
        pCVar6 = local_44;
        local_34._0_4_ = 0;
        local_24.left = param_3;
        local_34._4_4_ = 0;
        local_2c = 0;
        local_28 = 0;
        local_24.top = param_4;
        local_24.right = param_5;
        local_24.bottom = param_6;
        pcVar1 = *(code **)(*(int *)local_44 + 0x324);
        guard_check_icall(local_34);
        local_3c = (CObject *)(*pcVar1)();
        LVar14 = local_34._0_4_;
        if (local_3c == (CObject *)0x0) {
          LVar14 = local_24.right;
        }
        pHVar8 = GetParent(*(HWND *)(pCVar6 + 0x20));
        pCVar9 = CWnd::FromHandle(pHVar8);
        iVar10 = FUN_0082f5a7(pCVar9);
        local_24.left = local_24.left - local_4c;
        local_24.right = LVar14 + local_4c;
        local_24.bottom = local_24.bottom + local_48;
        iVar4 = *(int *)(in_ECX + 0x1988);
        local_44 = (CObject *)(uint)(iVar10 == 0);
        guard_check_icall(local_38,local_24.left,local_24.top,local_24.right,local_24.bottom,
                          local_44,0xff);
        (**(code **)(iVar4 + 0x10))();
        if (local_3c == (CObject *)0x0) goto LAB_00834fd7;
        local_2c = local_2c + local_4c;
        local_28 = local_28 + local_48;
        iVar4 = *(int *)(local_40 + 0x1b00);
        ptVar15 = (tagRECT *)local_34;
        local_34._0_4_ = local_34._0_4_ - *(int *)(local_40 + 0x1c38);
        pCVar6 = local_44;
LAB_00834dca:
        guard_check_icall(local_38,ptVar15->left,ptVar15->top,ptVar15->right,ptVar15->bottom,pCVar6,
                          0xff);
      }
      (**(code **)(iVar4 + 0x10))();
      goto LAB_00834fd7;
    }
  }
LAB_00834fae:
  FUN_008ace82(local_38,local_44,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11);
LAB_00834fd7:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[33] */
/* 00834fdf  FUN_00834fdf  679 bytes, 0 callers */

void FUN_00834fdf(undefined4 param_1,CObject *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  CObject *pCVar4;
  CObject *pCVar5;
  CMFCVisualManagerOffice2007 *pCVar6;
  CMFCVisualManagerOffice2007 *in_ECX;
  uint uVar7;
  uint uVar8;
  
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar3 == 0) ||
     (pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,param_2),
     pCVar4 != (CObject *)0x0)) goto LAB_00835200;
  if ((DAT_00a127ac != 0) && ((DAT_00a127b0 == 0 && (*(int *)(param_2 + 0x3c) == 0)))) {
    return;
  }
  uVar1 = *(uint *)(param_2 + 0x24);
  uVar8 = 0;
  uVar7 = uVar1 >> 0x12 & 1;
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBasePane_0098a7f8,
                              *(CObject **)(param_2 + 0x6c));
  pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,param_2);
  if (pCVar4 == (CObject *)0x0) {
LAB_0083517f:
    uVar8 = 0xffffffff;
    if ((uVar1 & 0x10000) == 0) {
      uVar8 = 0xffffffff;
      if (uVar7 != 0) {
        return;
      }
LAB_00835230:
      if ((uVar1 & 0x20000) == 0) {
        if (param_7 == 2) {
          uVar8 = (uVar8 & -(uint)(uVar8 != 0xffffffff)) + 1;
        }
        if (uVar8 == 0xffffffff) {
          return;
        }
      }
      else {
        uVar8 = 2;
      }
    }
    else {
      if (uVar7 == 0) {
        if ((param_7 == 1) || (param_7 == 2)) {
          uVar8 = 3;
        }
        goto LAB_00835230;
      }
      uVar8 = 0;
    }
    pCVar6 = in_ECX + 0x33f8;
  }
  else if (pCVar5 == (CObject *)0x0) {
    iVar3 = FUN_0079d98a(&PTR_s_CMFCColorBar_00a007bc);
    if (iVar3 == 0) {
      iVar3 = FUN_0079d98a(&PTR_s_CMFCOutlookBarToolBar_0099ca8c);
      if (iVar3 != 0) goto LAB_00835200;
      goto LAB_0083517f;
    }
    if ((uVar1 & 0x10000) == 0) {
      pCVar6 = (CMFCVisualManagerOffice2007 *)0x0;
      if (uVar7 != 0) goto LAB_00835200;
    }
    else {
      pCVar6 = in_ECX + 0x29b0;
      if (uVar7 != 0) {
        uVar8 = 1;
        goto LAB_0083525a;
      }
    }
    uVar8 = 0;
    if (param_7 == 2) {
      pCVar6 = in_ECX + 0x2ca0;
    }
  }
  else {
    iVar3 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00);
    if (iVar3 == 0) {
      iVar3 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
      if (iVar3 == 0) {
        iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBar_00a005c4);
        if (iVar3 != 0) {
          pcVar2 = *(code **)(*(int *)pCVar5 + 0x70);
          guard_check_icall();
          iVar3 = (*pcVar2)();
          if (iVar3 != 0) {
            pcVar2 = *(code **)(*(int *)in_ECX + 0x30c);
            guard_check_icall(pCVar5,&param_3);
            (*pcVar2)();
          }
        }
        goto LAB_0083517f;
      }
      if ((uVar1 & 0x10000) == 0) {
        if ((param_7 != 1) && (param_7 != 2)) {
          return;
        }
        pCVar6 = in_ECX + uVar7 * 0x178 + 0x2ca0;
      }
      else {
        param_6 = param_6 + 1;
        pCVar6 = in_ECX + 0x29b0;
        uVar8 = uVar7;
      }
    }
    else {
      if ((param_7 != 1) && (param_7 != 2)) {
        return;
      }
      pcVar2 = *(code **)(*(int *)pCVar5 + 0x70);
      guard_check_icall();
      iVar3 = (*pcVar2)();
      if (iVar3 != 0) {
        pcVar2 = *(code **)(*(int *)in_ECX + 0x30c);
        guard_check_icall(pCVar5,&param_3);
        (*pcVar2)();
      }
      pCVar6 = in_ECX + 0x2838;
      uVar8 = (uint)(iVar3 != 0);
    }
  }
LAB_0083525a:
  if (pCVar6 != (CMFCVisualManagerOffice2007 *)0x0) {
    iVar3 = *(int *)pCVar6;
    guard_check_icall(param_1,param_3,param_4,param_5,param_6,uVar8,0xff);
    (**(code **)(iVar3 + 0x10))();
    return;
  }
LAB_00835200:
  FUN_008ad712(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[54] */
/* 00835286  OnFillCaptionBarButton  96 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned long __thiscall
   CMFCVisualManagerOffice2007::OnFillCaptionBarButton(class CDC *,class CMFCCaptionBar *,class
   CRect,int,int,int,int,int)
   
   Library: Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOffice2007::OnFillCaptionBarButton
          (CMFCVisualManagerOffice2007 *this,undefined4 param_1,int param_2,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,
          undefined4 param_10,undefined4 param_11,int param_12)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = FUN_008a7deb(param_1,param_2,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                       param_11,param_12);
  iVar2 = CanDrawImage(this);
  if ((((iVar2 != 0) && (*(int *)(param_2 + 0x2c4) != 0)) && (param_12 != 0)) && (param_9 == 0)) {
    uVar1 = *(ulong *)(this + 0x8f84);
  }
  return uVar1;
}




/* vtable slots: CMFCVisualManagerOffice2007[197] */
/* 008352e6  FUN_008352e6  301 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008352e6(CDC *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,CMFCVisualManagerOffice2007 *param_6,CObject *param_7)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int iVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  CDrawingManager local_20 [8];
  undefined4 local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x8352f2;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 != 0) {
    iVar2 = -1;
    local_18 = 1;
    local_14 = -1;
    if (param_7 != (CObject *)0x0) {
      local_18 = *(undefined4 *)(param_7 + 0x4c);
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,param_7);
      if (pCVar3 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)param_7 + 0x70);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 != 0) {
          local_14 = *(int *)(in_ECX + 0x198);
          iVar2 = *(int *)(in_ECX + 0x19c);
        }
      }
    }
    if (param_6 == in_ECX + 0x11c) {
      iVar2 = *(int *)(in_ECX + 0x194);
      iVar4 = *(int *)(in_ECX + 400);
    }
    else if (param_6 == in_ECX + 0x124) {
      iVar2 = *(int *)(in_ECX + 0x19c);
      iVar4 = *(int *)(in_ECX + 0x198);
    }
    else {
      iVar4 = local_14;
      if (param_6 == in_ECX + 300) {
        iVar2 = *(int *)(in_ECX + 0x1a4);
        iVar4 = *(int *)(in_ECX + 0x1a0);
      }
    }
    if ((iVar2 != -1) && (iVar4 != -1)) {
      CDrawingManager::CDrawingManager(local_20,param_1);
      local_8 = 0;
      FUN_00817861(param_2,param_3,param_4,param_5,iVar2,iVar4,local_18,0,0);
      FUN_0081510b();
      return;
    }
  }
  FUN_008ada4f(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[82] */
/* 00835413  FUN_00835413  182 bytes, 0 callers */

undefined4
FUN_00835413(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int *param_6,
            int param_7)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  CObject *pCVar5;
  CMFCVisualManagerOffice2007 *in_ECX;
  HBRUSH hbr;
  int iVar6;
  
  iVar6 = param_7;
  piVar2 = param_6;
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar3 == 0) {
    uVar4 = FUN_008a8069(param_1,param_2,param_3,param_4,param_5,piVar2,iVar6);
    return uVar4;
  }
  pcVar1 = *(code **)(*piVar2 + 0x1a8);
  guard_check_icall();
  pCVar5 = (CObject *)(*pcVar1)();
  pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCBaseToolBar_0098b6e0,pCVar5);
  hbr = (HBRUSH)0x0;
  if (pCVar5 == (CObject *)0x0) {
    if (iVar6 != 0) {
      iVar3 = FUN_007c2511();
      iVar3 = iVar3 + 0xb8;
      goto LAB_00835486;
    }
  }
  else {
    iVar6 = 0;
  }
  iVar3 = FUN_007c2511();
  iVar3 = iVar3 + 0xc0;
LAB_00835486:
  if (iVar3 != 0) {
    hbr = *(HBRUSH *)(iVar3 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  iVar3 = FUN_007c2511();
  if (iVar6 == 0) {
    uVar4 = *(undefined4 *)(iVar3 + 0x84);
  }
  else {
    uVar4 = *(undefined4 *)(iVar3 + 0x74);
  }
  return uVar4;
}




/* vtable slots: CMFCVisualManagerOffice2007[59] */
/* 008354c9  OnFillOutlookBarCaption  60 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2007::OnFillOutlookBarCaption(class CDC
   *,class CRect,unsigned long &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2007::OnFillOutlookBarCaption
          (CMFCVisualManagerOffice2007 *this,undefined4 param_1,undefined4 param_3,
          undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  
  CMFCVisualManagerOffice2003::OnFillOutlookBarCaption
            ((CMFCVisualManagerOffice2003 *)this,param_1,param_3,param_4,param_5,param_6,param_7);
  iVar1 = CanDrawImage(this);
  if (iVar1 != 0) {
    *param_7 = *(undefined4 *)(this + 0x9080);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[56] */
/* 00835505  FUN_00835505  331 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00835505(CDC *param_1,CRect *param_2,int param_3,int param_4,ulong *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  char cVar5;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined4 uVar6;
  undefined4 uVar7;
  CDrawingManager local_1c [8];
  CMFCVisualManagerOffice2007 *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x835511;
  local_14 = in_ECX;
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar3 == 0) {
    CMFCVisualManagerOffice2003::OnFillOutlookPageButton
              ((CMFCVisualManagerOffice2003 *)in_ECX,param_1,param_2,param_3,param_4,param_5);
    return;
  }
  cVar5 = '\0';
  uVar6 = *(undefined4 *)param_2;
  uVar7 = *(undefined4 *)(param_2 + 4);
  uVar1 = *(undefined4 *)(param_2 + 8);
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  if (*(int *)(in_ECX + 0x3ed4) == 0) {
    uVar6 = *(undefined4 *)(in_ECX + 0x15c);
    uVar7 = *(undefined4 *)(in_ECX + 0x160);
    if (param_4 == 0) {
      if (param_3 != 0) {
        uVar6 = *(undefined4 *)(in_ECX + 0x194);
        uVar7 = *(undefined4 *)(in_ECX + 400);
      }
    }
    else if (param_3 == 0) {
      uVar6 = *(undefined4 *)(in_ECX + 0x198);
      uVar7 = *(undefined4 *)(in_ECX + 0x19c);
    }
    else {
      uVar6 = *(undefined4 *)(in_ECX + 0x19c);
      uVar7 = *(undefined4 *)(in_ECX + 0x198);
    }
    CDrawingManager::CDrawingManager(local_1c,param_1);
    local_8 = 0;
    FUN_00817861(*(undefined4 *)param_2,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                 *(undefined4 *)(param_2 + 0xc),uVar6,uVar7,1,0,0);
    FUN_0081510b();
    local_14 = in_ECX;
    goto LAB_00835621;
  }
  if (param_4 == 0) {
    if (param_3 != 0) {
      uVar4 = *(ulong *)(in_ECX + 0x9078);
      cVar5 = '\x01';
      goto LAB_00835572;
    }
  }
  else {
    uVar4 = *(ulong *)(in_ECX + 0x907c);
    cVar5 = (param_3 != 0) + '\x02';
LAB_00835572:
    *param_5 = uVar4;
  }
  iVar3 = *(int *)(in_ECX + 0x3e40);
  guard_check_icall(param_1,uVar6,uVar7,uVar1,uVar2,cVar5,0xff);
  (**(code **)(iVar3 + 0x10))();
LAB_00835621:
  *param_5 = *(ulong *)(local_14 + 0x9074);
  if (param_4 == 0) {
    if (param_3 == 0) {
      return;
    }
    uVar4 = *(ulong *)(local_14 + 0x9078);
  }
  else {
    uVar4 = *(ulong *)(local_14 + 0x907c);
  }
  *param_5 = uVar4;
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[119] */
/* 00835650  OnFillPopupWindowBackground  115 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2007::OnFillPopupWindowBackground(class
   CDC *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2007::OnFillPopupWindowBackground
          (CMFCVisualManagerOffice2007 *this,CDC *param_1,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x83565c;
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    CMFCVisualManagerOffice2003::OnFillPopupWindowBackground
              ((CMFCVisualManagerOffice2003 *)this,param_1,param_3,param_4,param_5,param_6);
  }
  else {
    CDrawingManager::CDrawingManager(local_18,param_1);
    local_8 = 0;
    FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(this + 0x9130),
                 *(undefined4 *)(this + 0x912c),1,0,0);
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[142] */
/* 008356c3  FUN_008356c3  3076 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008356c3(CDC *param_1,CMFCVisualManagerOffice2007 *param_2)

{
  CMFCVisualManagerBitmapCache *this;
  int iVar1;
  undefined4 uVar2;
  BOOL BVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  int iVar4;
  CMFCVisualManagerOffice2007 *pCVar5;
  CMFCVisualManagerOffice2007 *pCVar6;
  code *pcVar7;
  CMFCVisualManagerOffice2007 *pCVar8;
  int iVar9;
  uint uVar10;
  int local_7c;
  CMFCVisualManagerOffice2007 *local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  CMFCVisualManagerOffice2007 *local_64;
  int local_60;
  uint local_5c;
  undefined8 local_58;
  CMFCVisualManagerOffice2007 *local_50;
  CDC *local_4c;
  int local_48;
  CMFCVisualManagerOffice2007 *local_44;
  int local_40;
  CMFCVisualManagerOffice2007 *local_3c;
  int local_38;
  CMFCVisualManagerOffice2007 *local_34;
  uint local_30;
  CMFCVisualManagerOffice2007 *local_2c;
  CMFCVisualManagerOffice2007 *local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x8356cf;
  local_4c = param_1;
  local_28 = param_2;
  local_3c = in_ECX;
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008a8144(local_4c,param_2);
    goto LAB_008362bf;
  }
  local_60 = FUN_00863d99();
  local_74 = *(int *)(param_2 + 0x74);
  local_70 = *(int *)(param_2 + 0x78);
  local_6c = *(int *)(param_2 + 0x7c);
  local_68 = *(int *)(param_2 + 0x80);
  pcVar7 = *(code **)(*(int *)local_28 + 0xdc);
  local_2c = (CMFCVisualManagerOffice2007 *)0x0;
  guard_check_icall();
  local_64 = (CMFCVisualManagerOffice2007 *)(*pcVar7)();
  pcVar7 = *(code **)(*(int *)local_28 + 0xd4);
  guard_check_icall();
  local_40 = (*pcVar7)();
  pcVar7 = *(code **)(*(int *)local_28 + 0xe4);
  guard_check_icall();
  uVar2 = (*pcVar7)();
  local_58 = (double)CONCAT44(uVar2,(undefined4)local_58);
  pcVar7 = *(code **)(*(int *)local_28 + 0xd8);
  guard_check_icall();
  iVar1 = (*pcVar7)();
  if ((iVar1 == 0) || (local_48 = 1, local_60 != 0)) {
    local_48 = 0;
  }
  pcVar7 = *(code **)(*(int *)local_28 + 0xe0);
  guard_check_icall();
  local_30 = (*pcVar7)();
  pcVar7 = *(code **)(*(int *)local_28 + 0xd0);
  guard_check_icall();
  iVar1 = (*pcVar7)();
  if ((iVar1 != 0) || (local_38 = 0, local_40 != 0)) {
    local_38 = 1;
  }
  pcVar7 = *(code **)(*(int *)local_28 + 0x24c);
  guard_check_icall();
  iVar1 = (*pcVar7)();
  if ((iVar1 == 0) ||
     (local_44 = (CMFCVisualManagerOffice2007 *)0x1, *(int *)(local_28 + 0xc4) != 0)) {
    local_44 = (CMFCVisualManagerOffice2007 *)0x0;
  }
  local_5c = ~-(uint)(local_40 != 0) & (uint)local_64;
  pcVar7 = *(code **)(*(int *)local_28 + 0xe4);
  guard_check_icall();
  iVar1 = (*pcVar7)();
  pCVar6 = local_28;
  if ((iVar1 != 0) && (local_60 == 0)) {
    local_30 = 1;
    local_48 = 0;
    local_38 = 0;
  }
  local_34 = *(CMFCVisualManagerOffice2007 **)(local_28 + 0x98);
  iVar1 = FUN_0079d98a(&PTR_s_CMFCRibbonEdit_00999d90);
  if (iVar1 != 0) {
    local_74 = *(int *)(pCVar6 + 0x134);
    uVar2 = *(undefined4 *)(local_3c + 0x90a8);
    if (local_5c == 0) {
      if ((local_30 != 0) || (local_38 != 0)) {
        uVar2 = *(undefined4 *)(local_3c + 0x90b0);
      }
    }
    else {
      uVar2 = *(undefined4 *)(local_3c + 0x90ac);
    }
    CDrawingManager::CDrawingManager((CDrawingManager *)&local_58,local_4c);
    local_8 = 0;
    FUN_00817861(local_74,local_70,local_6c,local_68,uVar2,uVar2,1,0,0);
    FUN_0081510b();
    goto LAB_008362bf;
  }
  if ((local_30 != 0) && (local_60 != 0)) {
    pcVar7 = *(code **)(*(int *)pCVar6 + 0x204);
    guard_check_icall();
    iVar1 = (*pcVar7)();
    local_30 = -(uint)(iVar1 != 0) & local_30;
    pCVar6 = local_28;
  }
  if ((local_34 == (CMFCVisualManagerOffice2007 *)0x0) || (*(int *)(pCVar6 + 0xe4) == 0)) {
    if (local_44 != (CMFCVisualManagerOffice2007 *)0x0) {
      if (local_48 == 0) {
        if (local_38 == 0) {
          if (local_30 == 0) {
            pCVar6 = (CMFCVisualManagerOffice2007 *)0x0;
          }
          else {
            pCVar6 = (CMFCVisualManagerOffice2007 *)0x2;
          }
        }
        else {
          pCVar6 = (CMFCVisualManagerOffice2007 *)0x1;
        }
      }
      else {
        pCVar6 = (CMFCVisualManagerOffice2007 *)(-(uint)(local_38 != 0) & 2);
      }
      if (((local_40 != 0) && (local_58._4_4_ == (CMFCVisualManagerBitmapCache *)0x0)) &&
         (iVar1 = CMFCControlRenderer::GetImageCount((CMFCControlRenderer *)(local_3c + 0x6d40)),
         3 < iVar1)) {
        pCVar6 = (CMFCVisualManagerOffice2007 *)0x3;
      }
      pCVar5 = local_3c + 0x6d40;
      local_34 = local_3c + 0xbe1c;
      if (*(int *)(*(int *)(local_28 + 0x88) + 0x19c) != 0) {
        iVar1 = *(int *)(*(int *)(local_28 + 0x88) + 0x19c) * 0x648;
        pCVar5 = local_3c + iVar1 + 0x8f68;
        local_34 = local_3c + iVar1 + 0x9118;
      }
      local_2c = pCVar5;
      if (local_34 != (CMFCVisualManagerOffice2007 *)0x0) {
        local_7c = *(int *)(pCVar5 + 0x130) - *(int *)(pCVar5 + 0x128);
        local_78 = (CMFCVisualManagerOffice2007 *)(local_68 - local_70);
        local_58 = (double)CONCAT44(local_78,(undefined4)local_58);
        iVar1 = CMFCVisualManagerBitmapCache::FindIndex
                          ((CMFCVisualManagerBitmapCache *)local_34,(CSize *)&local_7c);
        if (iVar1 == -1) {
          iVar1 = CMFCVisualManagerBitmapCache::CacheY
                            ((CMFCVisualManagerBitmapCache *)local_34,(int)local_58._4_4_,
                             (CMFCControlRenderer *)pCVar5);
          if (iVar1 == -1) goto LAB_00835e80;
        }
        CMFCVisualManagerBitmapCache::Get((CMFCVisualManagerBitmapCache *)local_34,iVar1);
        FUN_0082eb09(local_4c,local_74,local_70,local_6c,local_68,*(undefined4 *)(pCVar5 + 0x158),
                     *(int *)(pCVar5 + 0x130) - *(int *)(pCVar5 + 0x160),pCVar6,0xff);
        goto LAB_008362bf;
      }
LAB_00835e80:
      pCVar5 = (CMFCVisualManagerOffice2007 *)0x0;
      goto LAB_00835e82;
    }
    if (local_5c != 0) {
      if (local_40 != 0) goto LAB_00835eb9;
LAB_008361d4:
      pCVar6 = (CMFCVisualManagerOffice2007 *)0x0;
      pCVar5 = pCVar6;
      goto LAB_00836205;
    }
    if (((local_48 == 0) && (local_30 == 0)) && (local_38 == 0)) {
      pCVar5 = (CMFCVisualManagerOffice2007 *)0x0;
      pCVar6 = (CMFCVisualManagerOffice2007 *)0x0;
LAB_008361f8:
      local_40 = -1;
      goto LAB_00836211;
    }
LAB_00835eb9:
    local_24.left = *(LONG *)(pCVar6 + 0x124);
    local_24.top = *(LONG *)(pCVar6 + 0x128);
    local_24.right = *(LONG *)(pCVar6 + 300);
    local_24.bottom = *(LONG *)(pCVar6 + 0x130);
    BVar3 = IsRectEmpty(&local_24);
    pCVar6 = local_28;
    if (BVar3 != 0) {
      pCVar6 = (CMFCVisualManagerOffice2007 *)0xffffffff;
      pCVar5 = (CMFCVisualManagerOffice2007 *)0x0;
      local_2c = local_3c + 0x6180;
      local_58 = (double)(*(int *)(local_3c + 0x62b4) - *(int *)(local_3c + 0x62ac));
      if ((local_58 * 1.5 < (double)(local_68 - local_70)) && (*(int *)(local_3c + 0x638c) != 0)) {
        local_2c = local_3c + 0x62f8;
      }
      if (local_5c != 0) {
        if (local_40 != 0) {
          iVar1 = CMFCControlRenderer::GetImageCount((CMFCControlRenderer *)local_2c);
          pCVar6 = (CMFCVisualManagerOffice2007 *)0x4;
          if (iVar1 < 5) goto LAB_008361d4;
        }
        goto LAB_00836205;
      }
      pCVar8 = (CMFCVisualManagerOffice2007 *)(-(uint)(local_30 != 0) & 3);
      pCVar6 = pCVar8 + -1;
      if ((local_38 != 0) && (pCVar6 = pCVar8, local_48 != 0)) {
        pCVar6 = (CMFCVisualManagerOffice2007 *)0x1;
      }
      goto LAB_008361f8;
    }
    local_24.left = *(LONG *)(local_28 + 0x134);
    local_24.top = *(LONG *)(local_28 + 0x138);
    local_24.right = *(LONG *)(local_28 + 0x13c);
    local_24.bottom = *(LONG *)(local_28 + 0x140);
    local_74 = *(int *)(local_28 + 0x124);
    local_70 = *(int *)(local_28 + 0x128);
    local_6c = *(int *)(local_28 + 300);
    local_68 = *(int *)(local_28 + 0x130);
    local_44 = local_3c + (-(uint)(*(int *)(local_28 + 0x170) != 0) & 0x2f0) + 0x6470;
    local_64 = local_3c + (-(uint)(*(int *)(local_28 + 0x170) != 0) & 0x2f0) + 0x65e8;
    iVar1 = *(int *)local_28;
    local_2c = (CMFCVisualManagerOffice2007 *)0xffffffff;
    local_28 = (CMFCVisualManagerOffice2007 *)0xffffffff;
    pcVar7 = *(code **)(iVar1 + 0xe4);
    guard_check_icall();
    local_34 = (CMFCVisualManagerOffice2007 *)(*pcVar7)();
    pcVar7 = *(code **)(*(int *)pCVar6 + 0x254);
    guard_check_icall();
    local_50 = (CMFCVisualManagerOffice2007 *)(*pcVar7)();
    pcVar7 = *(code **)(*(int *)pCVar6 + 600);
    guard_check_icall();
    iVar1 = (*pcVar7)();
    if (*(int *)(local_3c + 0xc000) < 0x14) {
      pCVar5 = (CMFCVisualManagerOffice2007 *)(-(uint)(local_30 != 0) & 3);
      local_2c = pCVar5 + -1;
      pCVar6 = local_2c;
      if (local_5c != 0) goto LAB_008360ee;
      if ((local_34 == (CMFCVisualManagerOffice2007 *)0x0) || (local_60 != 0)) {
        if (local_48 == 0) {
          local_28 = pCVar5;
          pCVar6 = local_2c;
          if (local_38 != 0) goto LAB_008360eb;
        }
        else {
          pCVar6 = local_2c;
          if (local_38 != 0) {
            if (local_50 == (CMFCVisualManagerOffice2007 *)0x0) {
              pCVar5 = (CMFCVisualManagerOffice2007 *)(-(uint)(local_30 != 0) & (uint)local_2c);
            }
            else {
              pCVar5 = (CMFCVisualManagerOffice2007 *)0x1;
            }
            local_28 = (CMFCVisualManagerOffice2007 *)(-(uint)(local_30 != 0) & (uint)local_2c);
            goto LAB_008360eb;
          }
        }
      }
      else {
        local_28 = (CMFCVisualManagerOffice2007 *)0x2;
        pCVar5 = (CMFCVisualManagerOffice2007 *)((uint)(local_30 == 0) * 2 + 2);
LAB_008360eb:
        local_2c = pCVar5;
        pCVar6 = local_28;
      }
LAB_008360ee:
      local_28 = pCVar6;
      pCVar6 = local_2c;
      if (local_2c != (CMFCVisualManagerOffice2007 *)0xffffffff) goto LAB_008360f6;
    }
    else {
      if (local_5c == 0) {
        if ((local_34 == (CMFCVisualManagerOffice2007 *)0x0) || (local_60 != 0)) {
          if (local_40 != 0) {
            local_2c = (CMFCVisualManagerOffice2007 *)0x5;
            local_28 = (CMFCVisualManagerOffice2007 *)0x4;
          }
          if (local_30 != 0) {
            local_2c = (CMFCVisualManagerOffice2007 *)0x2;
            local_28 = (CMFCVisualManagerOffice2007 *)0x2;
          }
          if ((local_50 != (CMFCVisualManagerOffice2007 *)0x0) || (pCVar6 = local_28, iVar1 != 0)) {
            local_28 = (CMFCVisualManagerOffice2007 *)0x4;
            pCVar6 = local_28;
            if (local_48 == 0) {
              local_2c = (CMFCVisualManagerOffice2007 *)(-(uint)(local_30 != 0) & 3);
              if (iVar1 != 0) {
                local_28 = (CMFCVisualManagerOffice2007 *)0x0;
LAB_008360e4:
                pCVar5 = (CMFCVisualManagerOffice2007 *)((uint)(local_30 == 0) * 2 + 3);
                goto LAB_008360eb;
              }
            }
            else {
              if (local_50 != (CMFCVisualManagerOffice2007 *)0x0) {
                pCVar6 = (CMFCVisualManagerOffice2007 *)0x1;
                goto LAB_008360f6;
              }
              if (iVar1 != 0) goto LAB_008360e4;
            }
          }
          goto LAB_008360ee;
        }
LAB_0083604f:
        local_28 = (CMFCVisualManagerOffice2007 *)0x2;
        pCVar6 = (CMFCVisualManagerOffice2007 *)0x5;
      }
      else {
        if ((local_50 == (CMFCVisualManagerOffice2007 *)0x0) && (iVar1 == 0)) goto LAB_008362bf;
        pCVar6 = (CMFCVisualManagerOffice2007 *)0x4;
        local_28 = (CMFCVisualManagerOffice2007 *)0x4;
        if (iVar1 != 0) {
          local_28 = (CMFCVisualManagerOffice2007 *)0x0;
          if ((local_34 != (CMFCVisualManagerOffice2007 *)0x0) && (local_60 == 0))
          goto LAB_0083604f;
          if (local_48 != 0) {
            local_28 = (CMFCVisualManagerOffice2007 *)0x1;
          }
        }
      }
LAB_008360f6:
      pcVar7 = *(code **)(*(int *)local_44 + 0x10);
      guard_check_icall(local_4c,local_24.left,local_24.top,local_24.right,local_24.bottom,pCVar6,
                        0xff);
      (*pcVar7)();
    }
    if (local_28 == (CMFCVisualManagerOffice2007 *)0xffffffff) goto LAB_008362bf;
    pcVar7 = *(code **)(*(int *)local_64 + 0x10);
    guard_check_icall(local_4c,local_74,local_70,local_6c,local_68,local_28,0xff);
  }
  else {
    local_44 = pCVar6 + 0x124;
    local_24.left = *(LONG *)local_44;
    local_24.top = *(LONG *)(pCVar6 + 0x128);
    local_24.right = *(LONG *)(pCVar6 + 300);
    local_24.bottom = *(LONG *)(pCVar6 + 0x130);
    BVar3 = IsRectEmpty(&local_24);
    if (BVar3 != 0) {
      if (local_34 == (CMFCVisualManagerOffice2007 *)0x1) {
        iVar1 = 0x52d0;
        iVar9 = 0xbe48;
      }
      else if (local_34 == (CMFCVisualManagerOffice2007 *)0x2) {
        iVar1 = 0x5448;
        iVar9 = 0xbe74;
      }
      else if (local_34 == (CMFCVisualManagerOffice2007 *)0x3) {
        iVar1 = 0x5738;
        iVar9 = 0xbecc;
      }
      else {
        iVar1 = 0x55c0;
        iVar9 = 0xbea0;
      }
      pCVar5 = local_3c + iVar9;
      local_58 = (double)CONCAT44(pCVar5,(undefined4)local_58);
      local_2c = local_3c + iVar1;
      pCVar6 = (CMFCVisualManagerOffice2007 *)(-(uint)(local_30 != 0) & 3);
      if ((local_5c == 0) || (local_40 != 0)) {
        if (local_48 == 0) {
          if (local_38 != 0) {
            pCVar6 = pCVar6 + 1;
          }
        }
        else if (local_38 != 0) {
          pCVar6 = (CMFCVisualManagerOffice2007 *)0x2;
        }
      }
      else {
        pCVar6 = (CMFCVisualManagerOffice2007 *)0x0;
      }
LAB_00835e82:
      if (local_5c == 0) goto LAB_008361f8;
LAB_00836205:
      local_40 = *(int *)(local_3c + 0x8f98);
LAB_00836211:
      if ((local_2c != (CMFCVisualManagerOffice2007 *)0x0) &&
         (pCVar6 != (CMFCVisualManagerOffice2007 *)0xffffffff)) {
        if (pCVar5 != (CMFCVisualManagerOffice2007 *)0x0) {
          local_7c = local_6c - local_74;
          local_78 = (CMFCVisualManagerOffice2007 *)(local_68 - local_70);
          iVar1 = CMFCVisualManagerBitmapCache::FindIndex
                            ((CMFCVisualManagerBitmapCache *)pCVar5,(CSize *)&local_7c);
          if ((iVar1 != -1) ||
             (iVar1 = CMFCVisualManagerBitmapCache::Cache
                                ((CMFCVisualManagerBitmapCache *)pCVar5,(CSize *)&local_7c,
                                 (CMFCControlRenderer *)local_2c), iVar1 != -1)) {
            CMFCVisualManagerBitmapCache::Get((CMFCVisualManagerBitmapCache *)pCVar5,iVar1);
            FUN_0082dde7(local_4c,local_74,local_70,local_6c,local_68,pCVar6,0xff);
            goto LAB_008362bf;
          }
        }
        pcVar7 = *(code **)(*(int *)local_2c + 0x10);
        guard_check_icall(local_4c,local_74,local_70,local_6c,local_68,pCVar6,0xff);
        (*pcVar7)();
      }
      goto LAB_008362bf;
    }
    local_74 = *(int *)(local_28 + 0x134);
    local_70 = *(int *)(local_28 + 0x138);
    local_6c = *(int *)(local_28 + 0x13c);
    local_68 = *(int *)(local_28 + 0x140);
    local_24.left = *(LONG *)local_44;
    local_24.top = *(LONG *)(local_44 + 4);
    local_24.right = *(LONG *)(local_44 + 8);
    local_24.bottom = *(LONG *)(local_44 + 0xc);
    if (local_34 == (CMFCVisualManagerOffice2007 *)0x1) {
      iVar1 = 0x58b0;
      iVar9 = 0xbef8;
LAB_0083598a:
      iVar4 = 0x6008;
      local_2c = (CMFCVisualManagerOffice2007 *)0xbfd4;
    }
    else if (local_34 == (CMFCVisualManagerOffice2007 *)0x2) {
      iVar1 = 0x58b0;
      local_2c = (CMFCVisualManagerOffice2007 *)0xbf24;
      iVar4 = 0x5a28;
      iVar9 = 0xbef8;
    }
    else {
      if (local_34 == (CMFCVisualManagerOffice2007 *)0x3) {
        iVar1 = 0x5e90;
        iVar9 = 0xbfa8;
        goto LAB_0083598a;
      }
      iVar1 = 0x5ba0;
      local_2c = (CMFCVisualManagerOffice2007 *)0xbf7c;
      iVar4 = 0x5d18;
      iVar9 = 0xbf50;
    }
    local_58 = (double)CONCAT44(local_3c + (int)local_2c,(undefined4)local_58);
    local_78 = local_3c + iVar9;
    uVar10 = 0;
    local_34 = local_3c + iVar4;
    local_50 = local_3c + iVar1;
    local_2c = (CMFCVisualManagerOffice2007 *)0x0;
    pcVar7 = *(code **)(*(int *)local_28 + 0x254);
    guard_check_icall();
    local_64 = (CMFCVisualManagerOffice2007 *)(*pcVar7)();
    pcVar7 = *(code **)(*(int *)local_28 + 600);
    guard_check_icall();
    local_44 = (CMFCVisualManagerOffice2007 *)(*pcVar7)();
    pCVar6 = local_28;
    if (*(int *)(local_3c + 0xc000) < 0x14) {
      local_30 = -(uint)(local_30 != 0) & 3;
      if (local_5c == 0) {
        pcVar7 = *(code **)(*(int *)local_28 + 0xe4);
        guard_check_icall();
        iVar1 = (*pcVar7)();
        if ((iVar1 == 0) || (local_60 != 0)) {
          uVar10 = local_30;
          if (local_48 == 0) {
            if (local_38 != 0) {
              local_2c = (CMFCVisualManagerOffice2007 *)0x1;
              uVar10 = local_30 + 1;
            }
          }
          else if (local_64 != (CMFCVisualManagerOffice2007 *)0x0) {
            local_2c = (CMFCVisualManagerOffice2007 *)0x1;
            local_30 = 2;
            uVar10 = local_30;
          }
        }
        else {
          pcVar7 = *(code **)(*(int *)pCVar6 + 0xe0);
          guard_check_icall();
          iVar1 = (*pcVar7)();
          local_2c = (CMFCVisualManagerOffice2007 *)0x3;
          uVar10 = -(uint)(iVar1 != 0) & 3;
          local_30 = uVar10;
        }
      }
      else {
        local_30 = 0;
        uVar10 = local_30;
      }
    }
    else {
      if ((local_30 != 0) && (uVar10 = 3, local_38 != 0)) {
        local_2c = (CMFCVisualManagerOffice2007 *)0x5;
      }
      if (local_5c == 0) {
        pcVar7 = *(code **)(*(int *)local_28 + 0xe4);
        guard_check_icall();
        iVar1 = (*pcVar7)();
        if ((iVar1 == 0) || (local_60 != 0)) {
          if (local_40 != 0) {
            uVar10 = 6;
            local_2c = (CMFCVisualManagerOffice2007 *)0x5;
          }
          if ((local_64 != (CMFCVisualManagerOffice2007 *)0x0) ||
             (local_44 != (CMFCVisualManagerOffice2007 *)0x0)) {
            if (local_30 == 0) {
              uVar10 = (-(uint)(local_64 != (CMFCVisualManagerOffice2007 *)0x0) & 0xfffffffb) + 6;
            }
            else {
              uVar10 = (local_64 != (CMFCVisualManagerOffice2007 *)0x0) + 3;
            }
            local_2c = (CMFCVisualManagerOffice2007 *)
                       ((uint)(local_44 == (CMFCVisualManagerOffice2007 *)0x0) * 4 + 1);
            local_30 = uVar10;
          }
          if ((local_48 != 0) && (local_64 != (CMFCVisualManagerOffice2007 *)0x0)) {
            uVar10 = 2;
          }
        }
        else {
          pcVar7 = *(code **)(*(int *)local_28 + 0xe0);
          guard_check_icall();
          iVar1 = (*pcVar7)();
          local_2c = (CMFCVisualManagerOffice2007 *)0x3;
          uVar10 = (-(uint)(iVar1 != 0) & 0xfffffffd) + 6;
          local_30 = uVar10;
        }
      }
      else if (local_30 != 0) {
        local_2c = (CMFCVisualManagerOffice2007 *)0x4;
        uVar10 = 5;
      }
    }
    pCVar6 = local_78;
    if (local_78 == (CMFCVisualManagerOffice2007 *)0x0) {
LAB_00835c1b:
      pcVar7 = *(code **)(*(int *)local_50 + 0x10);
      guard_check_icall(local_4c,local_74,local_70,local_6c,local_68,uVar10,0xff);
      (*pcVar7)();
    }
    else {
      local_7c = local_6c - local_74;
      local_78 = (CMFCVisualManagerOffice2007 *)(local_68 - local_70);
      iVar1 = CMFCVisualManagerBitmapCache::FindIndex
                        ((CMFCVisualManagerBitmapCache *)pCVar6,(CSize *)&local_7c);
      if ((iVar1 == -1) &&
         (iVar1 = CMFCVisualManagerBitmapCache::Cache
                            ((CMFCVisualManagerBitmapCache *)pCVar6,(CSize *)&local_7c,
                             (CMFCControlRenderer *)local_50), iVar1 == -1)) goto LAB_00835c1b;
      CMFCVisualManagerBitmapCache::Get((CMFCVisualManagerBitmapCache *)pCVar6,iVar1);
      FUN_0082dde7(local_4c,local_74,local_70,local_6c,local_68,uVar10,0xff);
    }
    this = local_58._4_4_;
    pCVar6 = local_34;
    if (local_58._4_4_ != (CMFCVisualManagerBitmapCache *)0x0) {
      local_58 = (double)CONCAT44(local_24.bottom - local_24.top,local_24.right - local_24.left);
      iVar1 = CMFCVisualManagerBitmapCache::FindIndex(this,(CSize *)&local_58);
      pCVar6 = local_34;
      if ((iVar1 != -1) ||
         (iVar1 = CMFCVisualManagerBitmapCache::Cache
                            (this,(CSize *)&local_58,(CMFCControlRenderer *)local_34), iVar1 != -1))
      {
        CMFCVisualManagerBitmapCache::Get(this,iVar1);
        FUN_0082dde7(local_4c,local_24.left,local_24.top,local_24.right,local_24.bottom,local_2c,
                     0xff);
        goto LAB_008362bf;
      }
    }
    pcVar7 = *(code **)(*(int *)pCVar6 + 0x10);
    guard_check_icall(local_4c,local_24.left,local_24.top,local_24.right,local_24.bottom,local_2c,
                      0xff);
  }
  (*pcVar7)();
LAB_008362bf:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[143] */
/* 008362c7  OnFillRibbonEdit  213 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCVisualManagerOffice2007::OnFillRibbonEdit(class CDC *,class
   CMFCRibbonRichEditCtrl *,class CRect,int,int,int,unsigned long &,unsigned long &,unsigned long &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOffice2007::OnFillRibbonEdit
          (CMFCVisualManagerOffice2007 *this,CDC *param_1,undefined4 param_2,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,undefined4 param_9,
          int param_10,undefined4 *param_11,undefined4 *param_12,undefined4 *param_13)

{
  int iVar1;
  undefined4 uVar2;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8362d3;
  iVar1 = CanDrawImage(this);
  if (iVar1 == 0) {
    CMFCVisualManager::OnFillRibbonEdit
              ((CMFCVisualManager *)this,param_1,param_2,param_4,param_5,param_6,param_7,param_8,
               param_9,param_10,param_11,param_12,param_13);
  }
  else {
    uVar2 = *(undefined4 *)(this + 0x90a8);
    if (param_10 == 0) {
      if (param_8 != 0) {
        uVar2 = *(undefined4 *)(this + 0x90b0);
      }
    }
    else {
      uVar2 = *(undefined4 *)(this + 0x90ac);
    }
    CDrawingManager::CDrawingManager(local_18,param_1);
    local_8 = 0;
    FUN_00817861(param_4,param_5,param_6,param_7,uVar2,uVar2,1,0,0);
    if (param_10 == 0) {
      *param_11 = *(undefined4 *)(this + 0x8f9c);
      *param_13 = *(undefined4 *)(this + 0x8f9c);
      uVar2 = *(undefined4 *)(this + 0x90c8);
      param_11 = param_12;
    }
    else {
      iVar1 = FUN_007c2511();
      uVar2 = *(undefined4 *)(iVar1 + 0x38);
    }
    *param_11 = uVar2;
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[146] */
/* 0083639c  FUN_0083639c  193 bytes, 0 callers */

undefined4 FUN_0083639c(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar2 == 0) {
    uVar3 = FUN_007f9f7b(param_1,param_2);
  }
  else {
    pcVar1 = *(code **)(*param_2 + 0xd0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*param_2 + 0xdc);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) {
        uVar3 = *(undefined4 *)(in_ECX + 0x8f9c);
      }
      else {
        uVar3 = *(undefined4 *)(in_ECX + 0x8fa4);
      }
    }
    else {
      uVar3 = *(undefined4 *)(in_ECX + 0x8fa0);
    }
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x5158) + 0x10);
    guard_check_icall(param_1,param_2[0x1d],param_2[0x1e],param_2[0x1f],param_2[0x20],iVar2 != 0,
                      0xff);
    (*pcVar1)();
  }
  return uVar3;
}




/* vtable slots: CMFCVisualManagerOffice2007[156] */
/* 0083645d  FUN_0083645d  92 bytes, 0 callers */

void FUN_0083645d(int param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,LONG param_6
                 )

{
  int iVar1;
  HBRUSH hbr;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    CMFCVisualManagerOfficeXP::OnFillRibbonMenuFrame();
  }
  else {
    hbr = (HBRUSH)0x0;
    if (in_ECX != (CMFCVisualManagerOffice2007 *)0xfffffef4) {
      hbr = *(HBRUSH *)(in_ECX + 0x110);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,hbr);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[169] */
/* 008364b9  FUN_008364b9  179 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008364b9(CDC *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  CDrawingManager local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8364c5;
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup();
  }
  else if (*(int *)(in_ECX + 0x8554) == 0) {
    CDrawingManager::CDrawingManager(local_1c,param_1);
    local_8 = 0;
    FUN_00817861(param_3,param_4,param_5,param_6,*(undefined4 *)(in_ECX + 0x15c),
                 *(undefined4 *)(in_ECX + 0x160),1,0,0);
    FUN_0081510b();
  }
  else {
    iVar1 = *(int *)(in_ECX + 0x84c0);
    guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
    (**(code **)(iVar1 + 0x1c))();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[62] */
/* 0083656c  FUN_0083656c  360 bytes, 0 callers */

void FUN_0083656c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,int *param_9)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar3 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if ((iVar3 == 0) || (param_9[0x4d] != 0)) {
LAB_008366ad:
    FUN_008ade6f(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return;
  }
  pcVar1 = *(code **)(*param_9 + 0x280);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) goto LAB_008366ad;
  pcVar1 = *(code **)(*param_9 + 0x288);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) goto LAB_008366ad;
  pcVar1 = *(code **)(*param_9 + 0x2a8);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) goto LAB_008366ad;
  pcVar1 = *(code **)(*param_9 + 0x28c);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) goto LAB_008366ad;
  pcVar1 = *(code **)(*param_9 + 0x290);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) goto LAB_008366ad;
  iVar3 = *(int *)(in_ECX + 0xc000);
  if (iVar3 < 0x14) {
    if (param_8 == 0) {
      if (param_7 != param_9[0x45]) {
        return;
      }
      goto LAB_00836649;
    }
  }
  else {
LAB_00836649:
    if (param_8 == 0) {
      iVar3 = (0x13 < iVar3) - 1;
      goto LAB_00836663;
    }
  }
  iVar3 = (0x13 < iVar3) + 2;
LAB_00836663:
  if (param_7 == param_9[0x45]) {
    iVar3 = iVar3 + 1;
  }
  iVar2 = *(int *)(in_ECX + (-(uint)(param_9[0x24] != 0) & 0xfffffe88) + 0x3860);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,iVar3,0xff);
  (**(code **)(iVar2 + 0x10))();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[36] */
/* 008366d4  FUN_008366d4  120 bytes, 0 callers */

void FUN_008366d4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  CMFCVisualManagerOffice2007 *in_ECX;
  
  iVar1 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar1 == 0) {
    FUN_008a8824(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    iVar1 = *(int *)(in_ECX + (*(uint *)(param_2 + 0x24) >> 0x12 & 1) * 0x178 + 0x2ca0);
    guard_check_icall(param_1,param_3,param_4,param_5,param_6,0,0xff);
    (**(code **)(iVar1 + 0x10))();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[40] */
/* 0083674c  FUN_0083674c  133 bytes, 0 callers */

void FUN_0083674c(int param_1,int param_2,LONG param_3,int param_4,LONG param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  HBRUSH hbr;
  CMFCVisualManagerOffice2007 *in_ECX;
  undefined1 local_c [4];
  int local_8;
  
  local_8 = param_1;
  iVar2 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  iVar3 = local_8;
  if (iVar2 == 0) {
    FUN_008ae1be(local_8,param_2,param_3,param_4,param_5);
    param_1 = iVar3;
  }
  param_2 = param_2 + -1;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x2dc);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  piVar4 = (int *)FUN_007fe1cf(local_c);
  param_4 = param_2 + 2 + *piVar4 + iVar3 * 2;
  hbr = (HBRUSH)0x0;
  if (in_ECX != (CMFCVisualManagerOffice2007 *)0xfffffefc) {
    hbr = *(HBRUSH *)(in_ECX + 0x108);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[129] */
/* 008367d1  FUN_008367d1  262 bytes, 0 callers */

undefined4 FUN_008367d1(int param_1,uint param_2)

{
  code *pcVar1;
  AFX_GLOBAL_DATA *this;
  int iVar2;
  uint *puVar3;
  int *in_ECX;
  uint uVar4;
  uint local_10;
  uint local_c;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsDwmCompositionEnabled(this);
    if (iVar2 == 0) {
      if ((*(byte *)(param_1 + 0x60) & 0x20) == 0) {
        local_c = param_2;
      }
      else {
        local_c = 1;
      }
      iVar2 = FUN_00797c32();
      uVar4 = -(uint)(iVar2 != 0) & local_c;
      local_c = 0;
      local_10 = 0;
      pcVar1 = *(code **)(*in_ECX + 500);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        local_c = FUN_0079d98a(&PTR_s_CMDIFrameWnd_0099f564);
        local_10 = FUN_0082f5a7(param_1);
      }
      puVar3 = (uint *)FUN_007e3332(*(undefined4 *)(param_1 + 0x20));
      *puVar3 = uVar4;
      SendMessageW(*(HWND *)(param_1 + 0x20),0x85,0,0);
      pcVar1 = *(code **)(*in_ECX + 500);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (((iVar2 != 0) && (local_c != 0)) && (local_10 != uVar4)) {
        RedrawWindow(*(HWND *)(param_1 + 0x120),(RECT *)0x0,(HRGN)0x0,0x81);
      }
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCVisualManagerOffice2007[128] */
/* 008368d7  FUN_008368d7  2148 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008368d7(CWnd *param_1,undefined4 param_2,LONG param_3,LONG param_4,LONG param_5,
                 LONG param_6)

{
  code *pcVar1;
  CMFCVisualManagerOffice2007 *pCVar2;
  undefined1 uVar3;
  int iVar4;
  BOOL BVar5;
  HRGN pHVar6;
  CWnd *pCVar7;
  CMDIFrameWnd *this;
  CMDIChildWnd *pCVar8;
  CObject *pCVar9;
  HICON__ *pHVar10;
  CObject *pCVar11;
  CSimpleStringT<wchar_t,0> *pCVar12;
  int iVar13;
  int iVar14;
  CMFCVisualManagerOffice2007 *in_ECX;
  uint uVar15;
  CDC local_b4 [4];
  int local_b0;
  undefined **local_a0;
  undefined4 local_9c;
  int local_98;
  uint local_94;
  undefined4 local_90;
  CWnd *local_8c;
  undefined4 local_88;
  uint local_84;
  CMFCVisualManagerOffice2007 *local_80;
  int local_7c;
  undefined1 local_78 [4];
  CWnd *local_74;
  int local_70;
  int local_6c;
  uint local_68;
  tagRECT local_64;
  int local_54;
  CObject *local_50;
  int local_4c;
  CObject *local_48;
  tagRECT local_44;
  int local_34;
  int local_30;
  int local_2c;
  CObject *local_28;
  undefined1 local_24 [8];
  LONG local_1c;
  CObject *local_18;
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0xb8;
  local_8 = 0xe6;
  uStack_7 = 0x8368;
  local_74 = param_1;
  local_88 = param_2;
  local_80 = in_ECX;
  iVar4 = CMFCVisualManagerOffice2007::CanDrawImage(in_ECX);
  if (iVar4 == 0) {
    FUN_007c234c(local_74,local_88,param_3,param_4,param_5,param_6);
    goto LAB_00837133;
  }
  if ((param_1 == (CWnd *)0x0) || (*(int *)(param_1 + 0x20) == 0)) goto LAB_00837133;
  FUN_0079dfaa(param_1);
  local_8 = 0;
  uStack_7 = 0;
  if (local_b0 == 0) {
    local_90 = FUN_007c234c(local_74,local_88,param_3,param_4,param_5,param_6);
  }
  else {
    local_9c = 0;
    local_a0 = CRgn::vftable;
    local_90 = 1;
    local_8 = 1;
    uStack_7 = 0;
    BVar5 = IsRectEmpty((RECT *)&param_3);
    if (BVar5 == 0) {
      pHVar6 = CreateRectRgnIndirect((RECT *)&param_3);
      Attach(pHVar6);
      FUN_0079eeb5(&local_a0);
    }
    pCVar7 = (CWnd *)GetRibbonBar(param_1);
    local_8c = pCVar7;
    if (((pCVar7 == (CWnd *)0x0) || (BVar5 = IsWindowVisible(*(HWND *)(pCVar7 + 0x20)), BVar5 == 0))
       || (*(int *)(pCVar7 + 0x328) == 0)) {
      local_68 = 0;
    }
    else {
      local_68 = 1;
    }
    local_44.left = 0;
    local_44.top = 0;
    local_44.right = 0;
    local_44.bottom = 0;
    GetWindowRect(*(HWND *)(param_1 + 0x20),&local_44);
    CWnd::ScreenToClient(param_1,&local_44);
    local_64.left = 0;
    local_64.top = 0;
    local_64.right = 0;
    local_64.bottom = 0;
    GetClientRect(*(HWND *)(param_1 + 0x20),&local_64);
    OffsetRect(&local_64,-local_44.left,-local_44.top);
    FUN_0079ea67(&local_64);
    OffsetRect(&local_44,-local_44.left,-local_44.top);
    local_7c = FUN_0082f5a7(param_1);
    if (local_7c != 0) {
      pcVar1 = *(code **)(*(int *)in_ECX + 500);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (((iVar4 != 0) && (iVar4 = FUN_0079d98a(&PTR_s_CMDIChildWnd_0099f74c), iVar4 != 0)) &&
         ((this = (CMDIFrameWnd *)FUN_008a2a09(), this != (CMDIFrameWnd *)0x0 &&
          (pCVar8 = CMDIFrameWnd::MDIGetActive(this,(int *)0x0), pCVar8 != (CMDIChildWnd *)0x0)))) {
        if ((*(int *)(pCVar8 + 0x20) == *(int *)(param_1 + 0x20)) &&
           (iVar4 = FUN_0082f5a7(this), iVar4 != 0)) {
          local_7c = 1;
        }
        else {
          local_7c = 0;
        }
      }
    }
    pCVar7 = local_74;
    local_34 = local_44.left;
    local_30 = local_44.top;
    local_2c = local_44.right;
    local_28 = (CObject *)local_44.bottom;
    pCVar9 = (CObject *)FUN_00797b3d();
    local_18 = pCVar9;
    CGlobalUtils::GetSystemBorders((CGlobalUtils *)&PTR_vftable_00a0095c,(ulong)&local_98);
    local_28 = (CObject *)(local_94 + local_30);
    if (local_68 == 0) {
      iVar4 = GetSystemMetrics(4);
      local_28 = (CObject *)((int)local_28 + iVar4);
      local_8c = (CWnd *)FUN_00797acc();
      pHVar10 = CGlobalUtils::GetWndIcon((CGlobalUtils *)&PTR_vftable_00a0095c,pCVar7);
      CStringT<>();
      local_8 = 2;
      FUN_00792c64(&local_6c);
      local_70 = FUN_004054a0(local_6c + -0x10);
      local_70 = local_70 + 0x10;
      CStringT<>();
      local_8 = 4;
      uVar3 = local_8;
      local_8 = 4;
      uVar15 = 0;
      if (((uint)pCVar9 & 0x8000) != 0) {
        local_84 = (uint)pCVar9 >> 0xe & 1;
        pCVar11 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,(CObject *)pCVar7);
        uVar15 = local_84;
        uVar3 = local_8;
        if (pCVar11 != (CObject *)0x0) {
          pCVar12 = (CSimpleStringT<wchar_t,0> *)FUN_0082f3cd(local_78);
          local_8 = 5;
          ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)&local_70,pCVar12);
          local_8 = 4;
          FUN_00406b10();
          iVar4 = local_70;
          if (*(int *)(local_70 + -0xc) == 0) {
            ATL::CSimpleStringT<wchar_t,0>::operator=
                      ((CSimpleStringT<wchar_t,0> *)&local_68,(CSimpleStringT<wchar_t,0> *)&local_6c
                      );
            uVar15 = local_84;
            uVar3 = local_8;
          }
          else {
            iVar13 = FUN_00429b90(local_70,0);
            uVar15 = local_84;
            uVar3 = local_8;
            if ((iVar13 != -1) && (*(int *)(iVar4 + -0xc) < *(int *)(local_6c + -0xc))) {
              if (iVar13 == 0) {
                local_84 = 0;
                pCVar12 = (CSimpleStringT<wchar_t,0> *)Left(local_78,*(int *)(iVar4 + -0xc) + 3);
                local_8 = 6;
                ATL::CSimpleStringT<wchar_t,0>::operator=
                          ((CSimpleStringT<wchar_t,0> *)&local_70,pCVar12);
                local_8 = 4;
                FUN_00406b10();
                pCVar12 = (CSimpleStringT<wchar_t,0> *)
                          ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::
                          Right((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                                 *)&local_6c,(int)local_78);
                local_8 = 7;
              }
              else {
                pCVar12 = (CSimpleStringT<wchar_t,0> *)
                          ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::
                          Right((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                                 *)&local_6c,(int)local_78);
                local_8 = 8;
                ATL::CSimpleStringT<wchar_t,0>::operator=
                          ((CSimpleStringT<wchar_t,0> *)&local_70,pCVar12);
                local_8 = 4;
                FUN_00406b10();
                pCVar12 = (CSimpleStringT<wchar_t,0> *)
                          Left(local_78,*(int *)(local_6c + -0xc) - *(int *)(local_70 + -0xc));
                local_8 = 9;
              }
              ATL::CSimpleStringT<wchar_t,0>::operator=
                        ((CSimpleStringT<wchar_t,0> *)&local_68,pCVar12);
              local_8 = 4;
              FUN_00406b10();
              uVar15 = local_84;
              uVar3 = local_8;
            }
          }
        }
      }
      local_8 = uVar3;
      if (((uint)pCVar9 & 0x1000000) != 0) {
        local_34 = local_34 - local_98;
        local_30 = local_30 - local_94;
        local_2c = local_2c + local_98;
      }
      FUN_0082e0fd(local_b4,local_34,local_30,local_2c,local_28,pCVar9,local_8c,&local_70,&local_68,
                   pHVar10,uVar15,local_7c,*(undefined4 *)(in_ECX + 0x210),local_88);
      FUN_00406b10();
      FUN_00406b10();
      if (((uint)local_18 & 0x1000000) == 0) {
        local_8 = 1;
        FUN_00406b10();
LAB_00836eac:
        local_44.top = (LONG)local_28;
        FUN_0079ea67(&local_34);
        iVar4 = FUN_0079d98a(&PTR_s_CMDIChildWnd_0099f74c);
        if (iVar4 == 0) {
          iVar4 = *(int *)(in_ECX + 0x20e0);
          local_68 = (uint)(local_7c == 0);
          guard_check_icall(local_b4,local_44.left,local_44.top,local_44.right,local_44.bottom,
                            local_68,0xff);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x2258);
          local_68 = (uint)(local_7c == 0);
          guard_check_icall(local_b4,local_44.left,local_44.top,local_44.right,local_44.bottom,
                            local_68,0xff);
        }
        pCVar2 = local_80;
        (**(code **)(iVar4 + 0x14))();
        local_54 = 0;
        iVar4 = 0;
        local_50 = (CObject *)0x0;
        local_4c = 0;
        local_48 = (CObject *)0x0;
        pCVar7 = CWnd::GetDescendantWindow(*(HWND__ **)(local_74 + 0x20),0xe801,1);
        local_8c = pCVar7;
        if (((pCVar7 != (CWnd *)0x0) && (*(int *)(pCVar7 + 0x20) != 0)) &&
           (BVar5 = IsWindowVisible(*(HWND *)(pCVar7 + 0x20)), BVar5 != 0)) {
          local_18 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCStatusBar_009a0c24,
                                        (CObject *)pCVar7);
          if (local_18 == (CObject *)0x0) {
            pCVar9 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonStatusBar_009a090c,
                                        (CObject *)pCVar7);
            if (pCVar9 == (CObject *)0x0) goto LAB_008370d8;
            pcVar1 = *(code **)(*(int *)pCVar9 + 0x368);
            guard_check_icall(&local_54);
            local_74 = (CWnd *)(*pcVar1)();
            iVar4 = *(int *)(pCVar9 + 0x16f8);
          }
          else {
            pcVar1 = *(code **)(*(int *)local_18 + 0x324);
            guard_check_icall(&local_54);
            local_74 = (CWnd *)(*pcVar1)();
          }
          local_24._0_4_ = 0;
          local_24._4_4_ = 0;
          local_1c = 0;
          local_18 = (CObject *)0x0;
          GetClientRect(*(HWND *)(local_8c + 0x20),(LPRECT)local_24);
          iVar13 = (int)local_18 - local_24._4_4_;
          local_18 = (CObject *)local_44.bottom;
          local_1c = local_44.right;
          local_24._4_4_ = local_44.bottom + (-iVar13 - (~-(uint)(iVar4 != 0) & local_94));
          local_24._0_4_ = local_44.left;
          if (local_74 != (CWnd *)0x0) {
            local_54 = local_54 + ((local_44.right - local_4c) - local_98);
            local_48 = (CObject *)local_44.bottom;
            local_4c = local_44.right;
            local_50 = (CObject *)local_24._4_4_;
          }
          iVar4 = *(int *)(pCVar2 + 0x1988);
          guard_check_icall(local_b4,local_44.left,local_24._4_4_,local_44.right,local_44.bottom,
                            local_68,0xff);
          (**(code **)(iVar4 + 0x10))();
          if (local_74 != (CWnd *)0x0) {
            iVar4 = *(int *)(local_80 + 0x1b00);
            local_54 = local_54 - *(int *)(local_80 + 0x1c38);
            guard_check_icall(local_b4,local_54,local_50,local_4c,local_48,local_68,0xff);
            (**(code **)(iVar4 + 0x10))();
          }
        }
LAB_008370d8:
        FUN_0079eeb5(0);
      }
      else {
        FUN_00406b10();
      }
    }
    else if (((uint)pCVar9 & 0x1000000) == 0) {
      pcVar1 = *(code **)(*(int *)local_8c + 0x1a4);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      local_28 = (CObject *)((int)local_28 + iVar4);
      local_24._0_4_ = *(undefined4 *)(in_ECX + 0x2518);
      local_24._4_4_ = *(undefined4 *)(in_ECX + 0x251c);
      local_1c = *(LONG *)(in_ECX + 0x2520);
      local_18 = *(CObject **)(in_ECX + 0x2524);
      if (*(int *)(in_ECX + 0xc000) < 0x14) {
        if (local_7c == 0) {
          local_88 = *(undefined4 *)(in_ECX + 0x8f58);
          local_68 = *(uint *)(in_ECX + 0x8f5c);
        }
        else {
          local_88 = *(undefined4 *)(in_ECX + 0x8f50);
          local_68 = *(uint *)(in_ECX + 0x8f54);
        }
        iVar14 = local_34 + local_24._0_4_;
        pCVar9 = (CObject *)(local_24._4_4_ + local_30);
        iVar4 = local_2c - local_1c;
        iVar13 = (int)local_28 - (int)local_18;
        CDrawingManager::CDrawingManager((CDrawingManager *)&local_1c,local_b4);
        local_8 = 10;
        FUN_00817362(iVar14,pCVar9,iVar4,iVar13,local_88,local_68,local_68,local_88,0,0x32);
        local_8 = 1;
        FUN_0081510b();
        iVar4 = *(int *)(in_ECX + 0x23d0);
        guard_check_icall(local_b4,local_34,local_30,local_2c,local_28,local_7c == 0,0xff);
        (**(code **)(iVar4 + 0x14))();
        in_ECX = local_80;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x23d0);
        guard_check_icall(local_b4,local_34,local_30,local_2c,local_28,local_7c == 0,0xff);
        (**(code **)(iVar4 + 0x10))();
        in_ECX = local_80;
      }
      goto LAB_00836eac;
    }
    local_a0 = CRgn::vftable;
    FUN_00416100();
  }
  FUN_0079e0f8();
LAB_00837133:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOffice2007[126] */
/* 0083713b  OnSetWindowRegion  349 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual int __thiscall CMFCVisualManagerOffice2007::OnSetWindowRegion(class CWnd *,class
   CSize)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCVisualManagerOffice2007::OnSetWindowRegion
          (CMFCVisualManagerOffice2007 *this,CObject *param_1,int param_3,int param_4)

{
  int iVar1;
  AFX_GLOBAL_DATA *this_00;
  CObject *pCVar2;
  uint uVar3;
  HRGN pHVar4;
  int iVar5;
  undefined **local_18;
  HRGN local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x837147;
  if (((param_1 != (CObject *)0x0) && (*(int *)(param_1 + 0x20) != 0)) &&
     (iVar1 = CanDrawImage(this), iVar1 != 0)) {
    this_00 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar1 = AFX_GLOBAL_DATA::IsDwmCompositionEnabled(this_00);
    if (iVar1 != 0) {
      return 0;
    }
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,param_1);
    if (pCVar2 == (CObject *)0x0) {
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonBar_009a1608,param_1);
      if (pCVar2 != (CObject *)0x0) {
        return 0;
      }
      uVar3 = FUN_00797b3d();
      if ((uVar3 & 0x1000000) != 0) {
        SetWindowRgn(*(HWND *)(param_1 + 0x20),(HRGN)0x0,1);
        return 1;
      }
      iVar1 = 9;
    }
    else {
      iVar1 = 3;
    }
    if (iVar1 != 0) {
      local_14 = (HRGN)0x0;
      local_18 = CRgn::vftable;
      local_8 = 0;
      pHVar4 = CreateRoundRectRgn(0,0,param_3 + 1,param_4 + 1,iVar1,iVar1);
      iVar5 = Attach(pHVar4);
      if (iVar5 != 0) {
        iVar5 = FUN_0079d98a(&PTR_s_CMDIChildWnd_0099f74c);
        if (iVar5 != 0) {
          local_8._0_1_ = 1;
          pHVar4 = CreateRectRgn(0,iVar1,param_3,param_4);
          Attach(pHVar4);
          CombineRgn(local_14,local_14,(HRGN)0x0,2);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00416100();
        }
        pHVar4 = CGdiObject::Detach((CGdiObject *)&local_18);
        SetWindowRgn(*(HWND *)(param_1 + 0x20),pHVar4,1);
        local_18 = CRgn::vftable;
        FUN_00416100();
        return 1;
      }
      local_18 = CRgn::vftable;
      FUN_00416100();
    }
  }
  return 0;
}




/* vtable slots: CMFCVisualManagerOffice2007[12] */
/* 00837298  FUN_00837298  29404 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00837298(void)

{
  DWORD *pDVar1;
  code *pcVar2;
  undefined4 uVar3;
  COLORREF CVar4;
  AFX_GLOBAL_DATA *this;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *this_00;
  CSimpleStringT<wchar_t,0> *pCVar8;
  DWORD DVar9;
  int *in_ECX;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  wchar_t **ppwVar13;
  uint uVar14;
  int *piVar15;
  float10 fVar16;
  int local_414;
  undefined1 local_410 [4];
  CTagManager local_40c [4];
  int local_408;
  char local_401;
  wchar_t local_400 [2];
  int *local_3fc;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_3f8 [4];
  undefined1 local_3f4 [4];
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> local_3f0 [4];
  int local_3ec;
  int local_3e8;
  int local_3e4;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_3e0 [4];
  uint local_3dc;
  int local_3d8;
  int local_3d4;
  COLORREF local_3d0;
  undefined4 local_3cc;
  undefined1 local_3c8 [4];
  CTagManager local_3c4 [8];
  int local_3bc;
  wchar_t **local_3b8;
  uint local_3b4;
  int local_3b0 [7];
  LOGFONTW local_394 [5];
  undefined1 local_1b4 [4];
  CSimpleStringT<wchar_t,0> local_1b0 [76];
  undefined1 local_164 [4];
  CSimpleStringT<wchar_t,0> local_160 [76];
  undefined1 local_114 [4];
  CSimpleStringT<wchar_t,0> local_110 [76];
  undefined1 local_c4 [4];
  CSimpleStringT<wchar_t,0> local_c0 [76];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  IMAGE_STATE local_34;
  wchar_t *local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  undefined4 local_24;
  wchar_t *local_20;
  undefined4 local_1c;
  wchar_t *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x404;
  local_8._0_1_ = 0xa7;
  local_8._1_3_ = 0x8372;
  local_3b4 = 0;
  pcVar2 = *(code **)(*in_ECX + 0x328);
  local_3fc = in_ECX;
  guard_check_icall();
  (*pcVar2)();
  FUN_008ae278();
  this = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar5 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
  if ((iVar5 != 0) || (iVar5 = FUN_007c2511(), *(int *)(iVar5 + 0x1ac) < 9)) goto LAB_0083e56e;
  in_ECX[0x29] = 1;
  local_414 = 0;
  if ((DAT_00a13b04 != 0) || (SetStyle(0,0), DAT_00a13b04 != 0)) {
    iVar6 = FUN_0079dd6d();
    iVar5 = DAT_00a13b04;
    local_414 = *(int *)(iVar6 + 0xc);
    iVar6 = FUN_0079dd6d();
    *(int *)(iVar6 + 0xc) = iVar5;
  }
  FUN_00819947();
  local_8 = 0;
  puVar7 = (undefined4 *)FUN_0082f13b(&local_3b8,DAT_00a13b00);
  local_8._0_1_ = 1;
  iVar5 = FUN_00819cc6(*puVar7,L"STYLE_XML");
  local_8._0_1_ = 0;
  FUN_00406b10();
  if (iVar5 == 0) {
    if (local_414 != 0) {
      iVar5 = FUN_0079dd6d();
      *(int *)(iVar5 + 0xc) = local_414;
    }
  }
  else {
    CStringT<>();
    local_8._0_1_ = 2;
    FUN_008199bf();
    FUN_0081b5aa();
    FUN_00406b10();
    CStringT<>();
    piVar11 = in_ECX + 0x3000;
    *piVar11 = 0x14;
    local_8._0_1_ = 3;
    if (*(int *)(local_408 + -0xc) != 0) {
      local_3e4 = 0;
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8._0_1_ = 4;
        CStringT<>();
        local_8._0_1_ = 5;
        FUN_0081b3f4(&local_3b4,&local_3e4);
        local_8._0_1_ = 4;
        FUN_00406b10();
        if (local_3e4 == 0x7d7) {
          CStringT<>();
          local_8._0_1_ = 6;
          FUN_0081b3f4(&local_3b4,piVar11);
          local_8._0_1_ = 4;
          FUN_00406b10();
          if (*piVar11 < 10) {
            *piVar11 = *piVar11 * 10;
          }
          in_ECX[0x83] = 1;
LAB_008374f6:
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            this_00 = ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::
                      TrimRight(local_3f0);
            ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::TrimLeft
                      ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)this_00
                      );
            ATL::CSimpleStringT<wchar_t,0>::operator=
                      ((CSimpleStringT<wchar_t,0> *)&DAT_00a13b0c,
                       (CSimpleStringT<wchar_t,0> *)local_3f0);
          }
        }
        else if (in_ECX[0x83] != 0) goto LAB_008374f6;
        local_8._0_1_ = 3;
        CTagManager::~CTagManager(local_3c4);
      }
    }
    if (in_ECX[0x83] == 0) {
      if (local_414 != 0) {
        iVar5 = FUN_0079dd6d();
        *(int *)(iVar5 + 0xc) = local_414;
      }
    }
    else {
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8._0_1_ = 7;
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 8;
        FUN_0081b2a5(&local_3b4,iVar5 + 0x68);
        local_8._0_1_ = 7;
        FUN_00406b10();
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 9;
        iVar5 = FUN_0081b2a5(&local_3b4,iVar5 + 0x54);
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_00406b10();
        if (iVar5 != 0) {
          iVar5 = FUN_007c2511();
          CGdiObject::DeleteObject((CGdiObject *)(iVar5 + 0xd0));
          FUN_007c2511();
          iVar5 = FUN_007c2511();
          CreateSolidBrush(*(COLORREF *)(iVar5 + 0x54));
          Attach();
          iVar5 = FUN_007c2511();
          in_ECX[0x2a] = *(int *)(iVar5 + 0x54);
        }
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 10;
        iVar5 = FUN_0081b2a5(&local_3b4,iVar5 + 0x7c);
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_00406b10();
        if (iVar5 != 0) {
          iVar5 = FUN_007c2511();
          uVar3 = *(undefined4 *)(iVar5 + 0x7c);
          iVar5 = FUN_007c2511();
          *(undefined4 *)(iVar5 + 0x80) = uVar3;
          iVar5 = FUN_007c2511();
          CGdiObject::DeleteObject((CGdiObject *)(iVar5 + 0xb8));
          FUN_007c2511();
          iVar5 = FUN_007c2511();
          CreateSolidBrush(*(COLORREF *)(iVar5 + 0x7c));
          Attach();
        }
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 0xb;
        iVar5 = FUN_0081b2a5(&local_3b4,iVar5 + 0x74);
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_00406b10();
        if (iVar5 != 0) {
          iVar5 = FUN_007c2511();
          uVar3 = *(undefined4 *)(iVar5 + 0x74);
          iVar5 = FUN_007c2511();
          *(undefined4 *)(iVar5 + 0x84) = uVar3;
        }
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 0xc;
        FUN_0081b2a5(&local_3b4,iVar5 + 0x80);
        local_8._0_1_ = 7;
        FUN_00406b10();
        iVar5 = FUN_007c2511();
        CGdiObject::DeleteObject((CGdiObject *)(iVar5 + 0xc0));
        FUN_007c2511();
        iVar5 = FUN_007c2511();
        CreateSolidBrush(*(COLORREF *)(iVar5 + 0x80));
        Attach();
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 0xd;
        FUN_0081b2a5(&local_3b4,iVar5 + 0x84);
        local_8._0_1_ = 7;
        FUN_00406b10();
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 0xe;
        FUN_0081b2a5(&local_3b4,iVar5 + 0x58);
        local_8._0_1_ = 7;
        FUN_00406b10();
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 0xf;
        FUN_0081b2a5(&local_3b4,iVar5 + 0x60);
        local_8._0_1_ = 7;
        FUN_00406b10();
        iVar5 = FUN_007c2511();
        CStringT<>();
        local_8._0_1_ = 0x10;
        FUN_0081b2a5(&local_3b4,iVar5 + 100);
        local_8._0_1_ = 7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x11;
        FUN_0081b2a5(&local_3b4,&local_3b8);
        local_8._0_1_ = 7;
        FUN_00406b10();
        CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x4d));
        CreateSolidBrush((COLORREF)local_3b8);
        Attach();
        CStringT<>();
        local_8._0_1_ = 0x12;
        FUN_0081b2a5(&local_3b4,in_ECX + 0x65);
        local_8._0_1_ = 7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x13;
        FUN_0081b2a5(&local_3b4,in_ECX + 100);
        local_8._0_1_ = 7;
        FUN_00406b10();
        in_ECX[0x67] = in_ECX[100];
        piVar11 = in_ECX + 0x66;
        *piVar11 = in_ECX[0x65];
        CStringT<>();
        piVar12 = local_3fc;
        local_8._0_1_ = 0x14;
        FUN_0081b2a5(&local_3b4,local_3fc + 0x67);
        local_8._0_1_ = 7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x15;
        FUN_0081b2a5(&local_3b4,piVar11);
        local_8._0_1_ = 7;
        FUN_00406b10();
        in_ECX = local_3fc;
        piVar12[0x69] = *piVar11;
        piVar11 = local_3fc + 0x68;
        *piVar11 = local_3fc[0x67];
        CStringT<>();
        local_8._0_1_ = 0x16;
        FUN_0081b2a5(&local_3b4,piVar12 + 0x69);
        local_8._0_1_ = 7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x17;
        FUN_0081b2a5(&local_3b4,piVar11);
        local_8._0_1_ = 7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x18;
        FUN_0081b2a5(&local_3b4,in_ECX + 0x35);
        local_8._0_1_ = 7;
        FUN_00406b10();
        iVar5 = FUN_007c2511();
        local_3d0 = *(COLORREF *)(iVar5 + 0x3c);
        iVar5 = FUN_007c2511();
        local_3cc = *(undefined4 *)(iVar5 + 0x40);
        CStringT<>();
        local_8 = CONCAT31(local_8._1_3_,0x19);
        local_3dc = 1;
        local_3b4 = 1;
        iVar5 = FUN_0081b2a5(local_3f4,&local_3d0);
        if (iVar5 == 0) {
LAB_00837b6b:
          local_401 = '\0';
        }
        else {
          CStringT<>();
          local_3dc = 3;
          local_8 = 0x1a;
          local_3b4 = local_3dc;
          iVar5 = FUN_0081b2a5(&local_3e4,&local_3cc);
          local_401 = '\x01';
          if (iVar5 == 0) goto LAB_00837b6b;
        }
        if ((local_3dc & 2) != 0) {
          local_3dc = local_3dc & 0xfffffffd;
          FUN_00406b10();
        }
        local_8 = 7;
        if ((local_3dc & 1) != 0) {
          FUN_00406b10();
        }
        CVar4 = local_3d0;
        if (local_401 != '\0') {
          iVar5 = FUN_007c2511();
          *(COLORREF *)(iVar5 + 0x3c) = CVar4;
          iVar5 = FUN_007c2511();
          CGdiObject::DeleteObject((CGdiObject *)(iVar5 + 0xa0));
          FUN_007c2511();
          CreateSolidBrush(local_3d0);
          Attach();
          uVar3 = local_3cc;
          iVar5 = FUN_007c2511();
          *(undefined4 *)(iVar5 + 0x40) = uVar3;
        }
        CStringT<>();
        local_8._0_1_ = 0x1b;
        FUN_0081b2a5(&local_3b4,in_ECX + 0x2a);
        local_8._0_1_ = 7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x1c;
        iVar5 = FUN_0081b557(&local_3b4,in_ECX + 0x3001);
        in_ECX[0x86] = iVar5;
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager((CTagManager *)&local_3c);
      }
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        CStringT<>();
        local_8._0_1_ = 0x1e;
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0x1f;
          local_3b0[1] = 0x1f8;
          FUN_007c2511();
          iVar5 = FUN_007e5c5c();
          if (iVar5 != 0) {
            CStringT<>();
            local_8._0_1_ = 0x20;
            FUN_0081b3a1(&local_3cc,local_394);
            local_8._0_1_ = 0x1f;
            FUN_00406b10();
            CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x23ce));
            CreateFontIndirectW(local_394);
            Attach();
          }
          CStringT<>();
          local_8._0_1_ = 0x21;
          FUN_0081b2a5(&local_3cc,in_ECX + 0x23d4);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x22;
          FUN_0081b2a5(&local_3cc,in_ECX + 0x23d5);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x23;
          FUN_0081b2a5(&local_3cc,in_ECX + 0x23d6);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x24;
          FUN_0081b2a5(&local_3cc,in_ECX + 0x23d7);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x25;
          FUN_0081b2a5(&local_3cc,in_ECX + 0x23d8);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x26;
          FUN_0081b2a5(&local_3cc,in_ECX + 0x23d9);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x27;
          FUN_0081b2a5(&local_3cc,in_ECX + 0x23da);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x28;
          FUN_0081b2a5(&local_3cc,in_ECX + 0x23db);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x29;
          FUN_0081b1d3(&local_3cc,in_ECX + 0x84);
          local_8._0_1_ = 0x1f;
          FUN_00406b10();
          FUN_0082f5e5(&local_3b8,L"IDB_OFFICE2007_MAINBORDER_CAPTION");
          local_8._0_1_ = 0x2a;
          CStringT<>();
          local_8._0_1_ = 0x2b;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          iVar5 = GetSystemMetrics(0x1f);
          iVar6 = GetSystemMetrics(0x1e);
          in_ECX[0x87] = iVar6;
          in_ECX[0x88] = iVar5;
          iVar5 = GetSystemMetrics(0x35);
          iVar6 = GetSystemMetrics(0x34);
          in_ECX[0x89] = iVar6;
          in_ECX[0x8a] = iVar5;
          CStringT<>();
          local_8._0_1_ = 0x2c;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_3dc = 0;
            do {
              uVar14 = local_3dc;
              CStringT<>();
              CStringT<>();
              local_8._0_1_ = 0x2f;
              if (uVar14 == 1) {
                iVar5 = FUN_008f899d();
                ATL::CSimpleStringT<wchar_t,0>::SetString
                          ((CSimpleStringT<wchar_t,0> *)&local_3d0,L"_S",iVar5);
              }
              iVar5 = FUN_008199bf();
              if (iVar5 != 0) {
                FUN_00819947();
                local_8._0_1_ = 0x30;
                CStringT<>();
                local_8._0_1_ = 0x31;
                FUN_0081b4ae(&local_3cc,in_ECX + uVar14 * 2 + 0x87);
                local_8._0_1_ = 0x30;
                FUN_00406b10();
                local_3ec = 0;
                local_3e8 = 0;
                CStringT<>();
                local_8._0_1_ = 0x32;
                iVar5 = FUN_0081b4ae(&local_3d8,&local_3ec);
                local_8._0_1_ = 0x30;
                FUN_00406b10();
                if (iVar5 != 0) {
                  FUN_007e7dd4();
                  iVar5 = local_3dc + 6;
                  in_ECX[iVar5 * 0x46 + 0xf] = 1;
                  in_ECX[iVar5 * 0x46 + 0x15] = local_3ec;
                  in_ECX[iVar5 * 0x46 + 0x16] = local_3e8;
                  puVar7 = (undefined4 *)
                           ATL::operator+((wchar_t *)local_3b0,
                                          (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                           *)L"IDB_OFFICE2007_SYS_BTN_CLOSE");
                  local_8._0_1_ = 0x33;
                  FUN_0082f5e5(&local_3b8,*puVar7);
                  local_8._0_1_ = 0x34;
                  FUN_007ea7e7();
                  FUN_00406b10();
                  local_8._0_1_ = 0x30;
                  FUN_00406b10();
                  FUN_007e7dd4();
                  iVar5 = local_3dc + 8;
                  in_ECX[iVar5 * 0x46 + 0xf] = 1;
                  in_ECX[iVar5 * 0x46 + 0x15] = local_3ec;
                  in_ECX[iVar5 * 0x46 + 0x16] = local_3e8;
                  puVar7 = (undefined4 *)
                           ATL::operator+((wchar_t *)&local_3d4,
                                          (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                           *)L"IDB_OFFICE2007_SYS_BTN_RESTORE");
                  local_8._0_1_ = 0x35;
                  FUN_0082f5e5(local_3c8,*puVar7);
                  local_8._0_1_ = 0x36;
                  FUN_007ea7e7();
                  FUN_00406b10();
                  local_8._0_1_ = 0x30;
                  FUN_00406b10();
                  FUN_007e7dd4();
                  iVar5 = local_3dc + 10;
                  in_ECX[iVar5 * 0x46 + 0xf] = 1;
                  in_ECX[iVar5 * 0x46 + 0x15] = local_3ec;
                  in_ECX[iVar5 * 0x46 + 0x16] = local_3e8;
                  puVar7 = (undefined4 *)
                           ATL::operator+(local_400,
                                          (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                           *)L"IDB_OFFICE2007_SYS_BTN_MAXIMIZE");
                  local_8._0_1_ = 0x37;
                  FUN_0082f5e5(local_410,*puVar7);
                  local_8._0_1_ = 0x38;
                  FUN_007ea7e7();
                  FUN_00406b10();
                  local_8._0_1_ = 0x30;
                  FUN_00406b10();
                  FUN_007e7dd4();
                  uVar14 = local_3dc;
                  iVar5 = local_3dc + 0xc;
                  in_ECX[iVar5 * 0x46 + 0xf] = 1;
                  in_ECX[iVar5 * 0x46 + 0x15] = local_3ec;
                  in_ECX[iVar5 * 0x46 + 0x16] = local_3e8;
                  puVar7 = (undefined4 *)
                           ATL::operator+((wchar_t *)local_3f8,
                                          (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                           *)L"IDB_OFFICE2007_SYS_BTN_MINIMIZE");
                  local_8._0_1_ = 0x39;
                  FUN_0082f5e5(&local_68,*puVar7);
                  local_8._0_1_ = 0x3a;
                  FUN_007ea7e7();
                  FUN_00406b10();
                  local_8._0_1_ = 0x30;
                  FUN_00406b10();
                }
                FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_SYS_BTN_BACK");
                local_8._0_1_ = 0x3b;
                CStringT<>();
                local_8._0_1_ = 0x3c;
                FUN_0081a003();
                FUN_00406b10();
                FUN_00406b10();
                CTagManager::~CTagManager((CTagManager *)&local_4c);
              }
              FUN_00406b10();
              FUN_00406b10();
              local_3dc = uVar14 + 1;
            } while ((int)local_3dc < 2);
            CTagManager::~CTagManager((CTagManager *)&local_5c);
          }
          FUN_00406b10();
          local_8._0_1_ = 0x1e;
          CTagManager::~CTagManager((CTagManager *)&local_3c);
        }
        FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_MAINBORDER");
        local_8._0_1_ = 0x3d;
        CStringT<>();
        local_8._0_1_ = 0x3e;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x1e;
        FUN_00406b10();
        FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_MDICHILDBORDER");
        local_8._0_1_ = 0x3f;
        CStringT<>();
        local_8._0_1_ = 0x40;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x1e;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x41;
        iVar5 = FUN_0081b2a5(&local_3d8,in_ECX + 0x23dc);
        local_8 = CONCAT31(local_8._1_3_,0x1e);
        FUN_00406b10();
        if (iVar5 != 0) {
          CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x23d0));
          FUN_004b05a0();
        }
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager(local_3c4);
      }
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8._0_1_ = 0x42;
        CStringT<>();
        local_8._0_1_ = 0x43;
        iVar5 = FUN_0081b2a5(&local_3bc,in_ECX + 0x30);
        local_8 = CONCAT31(local_8._1_3_,0x42);
        FUN_00406b10();
        if (iVar5 != 0) {
          CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x43));
          FUN_004b05a0();
        }
        in_ECX[0x2f] = -0x1000000;
        CStringT<>();
        local_8._0_1_ = 0x44;
        FUN_0081b2a5(&local_3bc,in_ECX + 0x2f);
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x45;
        FUN_0081b2a5(&local_3d8,in_ECX + 0x39);
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x46;
        iVar5 = FUN_0081b2a5(&local_3cc,in_ECX + 0x240d);
        local_8 = CONCAT31(local_8._1_3_,0x42);
        FUN_00406b10();
        if (iVar5 != 0) {
          CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x4f));
          FUN_004b6200();
        }
        CStringT<>();
        local_8._0_1_ = 0x47;
        iVar5 = FUN_0081b2a5(&local_3bc,in_ECX + 0x240e);
        local_8 = CONCAT31(local_8._1_3_,0x42);
        FUN_00406b10();
        if (iVar5 != 0) {
          CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x23ca));
          FUN_004b6200();
        }
        local_3e4 = -1;
        CStringT<>();
        local_8._0_1_ = 0x48;
        iVar5 = FUN_0081b2a5(&local_3bc,&local_3e4);
        local_8 = CONCAT31(local_8._1_3_,0x42);
        FUN_00406b10();
        if (iVar5 != 0) {
          CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x23d2));
          FUN_004b05a0();
        }
        CStringT<>();
        local_8._0_1_ = 0x49;
        FUN_0081b2a5(&local_3bc,in_ECX + 0x240f);
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x4a;
        iVar5 = FUN_0081b2a5(&local_3d8,in_ECX + 0x3a);
        local_8 = CONCAT31(local_8._1_3_,0x42);
        FUN_00406b10();
        if (iVar5 != 0) {
          CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x51));
          FUN_004b6200();
        }
        CStringT<>();
        local_8._0_1_ = 0x4b;
        FUN_0081b3f4(&local_3bc,in_ECX + 0x29);
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_MENU_ITEM_BACK");
        local_8._0_1_ = 0x4c;
        CStringT<>();
        local_8._0_1_ = 0x4d;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_MENU_ITEM_MARKER_C");
        local_8._0_1_ = 0x4e;
        CStringT<>();
        local_8._0_1_ = 0x4f;
        FUN_0081b501();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(&local_68,L"IDB_OFFICE2007_MENU_ITEM_MARKER_R");
        local_8._0_1_ = 0x50;
        CStringT<>();
        local_8._0_1_ = 0x51;
        FUN_0081b501();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(local_400,L"IDB_OFFICE2007_MENU_ITEM_SHOWALL");
        local_8._0_1_ = 0x52;
        CStringT<>();
        local_8._0_1_ = 0x53;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(local_410,L"IDB_OFFICE2007_MENU_BTN");
        local_8._0_1_ = 0x54;
        CStringT<>();
        local_8._0_1_ = 0x55;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(&local_3b8,L"IDB_OFFICE2007_MENU_BTN_DISABLED");
        local_8._0_1_ = 0x56;
        CStringT<>();
        local_8._0_1_ = 0x57;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(local_3b0,L"IDB_OFFICE2007_MENU_BTN_VERT_SEPARATOR");
        local_8._0_1_ = 0x58;
        CStringT<>();
        local_8._0_1_ = 0x59;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(local_3c8,L"IDB_OFFICE2007_MENU_BTN_SCROLL_T");
        local_8._0_1_ = 0x5a;
        CStringT<>();
        local_8._0_1_ = 0x5b;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        FUN_0082f5e5(&local_3d4,L"IDB_OFFICE2007_MENU_BTN_SCROLL_B");
        local_8._0_1_ = 0x5c;
        CStringT<>();
        local_8._0_1_ = 0x5d;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x5e;
        FUN_0081b2a5(&local_3d8,in_ECX + 0x23e7);
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x5f;
        FUN_0081b2a5(&local_3cc,in_ECX + 0x23e8);
        local_8._0_1_ = 0x42;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0x60;
        FUN_0081b2a5(local_3f4,in_ECX + 0x23e9);
        FUN_00406b10();
        local_3d0 = in_ECX[0x23e7];
        CStringT<>();
        local_8._0_1_ = 0x61;
        iVar5 = FUN_008199bf();
        if (iVar5 == 0) {
          CStringT<>();
          local_8._0_1_ = 0x66;
          FUN_0081b2a5(&local_3bc,&local_3d0);
          local_8 = CONCAT31(local_8._1_3_,0x61);
          FUN_00406b10();
          CMenuImages::SetColor(0,local_3d0);
          CMenuImages::SetColor(5,local_3d0);
        }
        else {
          FUN_00819947();
          local_8._0_1_ = 0x62;
          CStringT<>();
          local_8._0_1_ = 99;
          FUN_0081b2a5(&local_3bc,&local_3d0);
          local_8._0_1_ = 0x62;
          FUN_00406b10();
          CMenuImages::SetColor(0,local_3d0);
          CStringT<>();
          local_8._0_1_ = 100;
          FUN_0081b2a5(&local_3d8,&local_3d0);
          local_8 = CONCAT31(local_8._1_3_,0x62);
          FUN_00406b10();
          CMenuImages::SetColor(5,local_3d0);
          local_34 = 1;
          iVar5 = 0;
          local_30 = L"Gray";
          local_2c = 2;
          local_28 = L"LtGray";
          local_24 = 3;
          local_20 = L"White";
          local_1c = 4;
          local_18[0] = L"DkGray";
          do {
            CStringT<>();
            local_8._0_1_ = 0x65;
            iVar6 = FUN_0081b2a5(&local_3bc,&local_3d0);
            local_8 = CONCAT31(local_8._1_3_,0x62);
            FUN_00406b10();
            if (iVar6 != 0) {
              CMenuImages::SetColor((&local_34)[iVar5 * 2],local_3d0);
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < 4);
          CTagManager::~CTagManager(local_3c4);
        }
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager((CTagManager *)&local_3c);
      }
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        CStringT<>();
        local_8._0_1_ = 0x68;
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0x69;
          CStringT<>();
          local_8._0_1_ = 0x6a;
          iVar5 = FUN_0081b2a5(&local_3bc,in_ECX + 0x2e);
          local_8 = CONCAT31(local_8._1_3_,0x69);
          FUN_00406b10();
          if (iVar5 != 0) {
            CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x3f));
            FUN_004b05a0();
          }
          CStringT<>();
          local_8._0_1_ = 0x6b;
          FUN_0081b2a5(&local_3bc,in_ECX + 0x58);
          local_8._0_1_ = 0x69;
          FUN_00406b10();
          in_ECX[0x57] = in_ECX[0x58];
          CStringT<>();
          local_8._0_1_ = 0x6c;
          FUN_0081b2a5(&local_3d8,in_ECX + 0x57);
          FUN_00406b10();
          local_8._0_1_ = 0x68;
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          piVar12 = local_3fc;
          piVar11 = in_ECX + 0x5a;
          piVar10 = in_ECX + 0x59;
          iVar5 = local_3fc[0x57];
          local_8._0_1_ = 0x6d;
          *piVar11 = in_ECX[0x58];
          *piVar10 = iVar5;
          iVar5 = FUN_0081909d(iVar5,in_ECX[0x58],0x3ff0000000000000,1,1);
          piVar12[0x5b] = iVar5;
          CStringT<>();
          local_8._0_1_ = 0x6e;
          FUN_0081b2a5(&local_3bc,piVar11);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x6f;
          FUN_0081b2a5(&local_3d8,piVar10);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          piVar12 = piVar12 + 0x5c;
          piVar15 = local_3fc + 0x5d;
          *piVar12 = *piVar11;
          *piVar15 = *piVar10;
          CStringT<>();
          local_8._0_1_ = 0x70;
          FUN_0081b2a5(&local_3cc,piVar12);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x71;
          FUN_0081b2a5(&local_3b4,piVar15);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          CStringT<>();
          in_ECX = local_3fc;
          local_8._0_1_ = 0x72;
          FUN_0081b2a5(&local_3e4,local_3fc + 0x5f);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x73;
          FUN_0081b2a5(local_3f4,in_ECX + 0x5e);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_GRIPPER");
          local_8._0_1_ = 0x74;
          CStringT<>();
          local_8._0_1_ = 0x75;
          FUN_0081b501();
          FUN_00406b10();
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_TEAR");
          local_8._0_1_ = 0x76;
          CStringT<>();
          local_8._0_1_ = 0x77;
          FUN_0081b501();
          FUN_00406b10();
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          FUN_0082f5e5(&local_68,L"IDB_OFFICE2007_TOOLBAR_BTN");
          local_8._0_1_ = 0x78;
          CStringT<>();
          local_8._0_1_ = 0x79;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          FUN_0082f5e5(local_400,L"IDB_OFFICE2007_TOOLBAR_BORDER");
          local_8._0_1_ = 0x7a;
          CStringT<>();
          local_8._0_1_ = 0x7b;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          iVar5 = FUN_007c2511();
          iVar5 = *(int *)(iVar5 + 0x68);
          in_ECX[0x23e4] = iVar5;
          in_ECX[0x23e5] = iVar5;
          CStringT<>();
          local_8._0_1_ = 0x7c;
          FUN_0081b2a5(&local_3dc,in_ECX + 0x23e4);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x7d;
          FUN_0081b2a5(&local_3d4,in_ECX + 0x23e5);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x7e;
          FUN_0081b2a5(local_3c8,in_ECX + 0x23e6);
          local_8._0_1_ = 0x6d;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x7f;
          iVar5 = FUN_0081b2a5(local_3b0,in_ECX + 0x60);
          local_8 = CONCAT31(local_8._1_3_,0x6d);
          FUN_00406b10();
          if (iVar5 != 0) {
            CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x78));
            FUN_004b6200();
          }
          CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x23cc));
          FUN_00818965();
          FUN_004b6200();
          CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x7a));
          CreatePen(0,1,0xffffff);
          Attach();
          local_8._0_1_ = 0x68;
          CTagManager::~CTagManager((CTagManager *)&local_3c);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          piVar11 = in_ECX + 0x23dd;
          *piVar11 = in_ECX[0x5a];
          piVar15 = in_ECX + 0x23de;
          local_8._0_1_ = 0x80;
          *piVar15 = local_3fc[0x59];
          CStringT<>();
          local_8._0_1_ = 0x81;
          FUN_0081b2a5(local_3b0,piVar11);
          local_8._0_1_ = 0x80;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x82;
          FUN_0081b2a5(local_3c8,piVar15);
          local_8._0_1_ = 0x80;
          FUN_00406b10();
          piVar12 = local_3fc + 0x23df;
          piVar10 = local_3fc + 0x23e0;
          *piVar12 = *piVar11;
          *piVar10 = *piVar15;
          CStringT<>();
          local_8._0_1_ = 0x83;
          FUN_0081b2a5(&local_3d4,piVar12);
          local_8._0_1_ = 0x80;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x84;
          FUN_0081b2a5(&local_3bc,piVar10);
          local_8._0_1_ = 0x80;
          FUN_00406b10();
          piVar11 = local_3fc + 0x23e1;
          *piVar11 = local_3fc[0x23e4];
          piVar12 = local_3fc + 0x23e2;
          *piVar12 = local_3fc[0x23e5];
          piVar10 = local_3fc + 0x23e3;
          *piVar10 = local_3fc[0x23e6];
          CStringT<>();
          local_8._0_1_ = 0x85;
          FUN_0081b2a5(&local_3d8,piVar11);
          local_8._0_1_ = 0x80;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x86;
          FUN_0081b2a5(&local_3cc,piVar12);
          local_8._0_1_ = 0x80;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x87;
          FUN_0081b2a5(&local_3b4,piVar10);
          local_8._0_1_ = 0x80;
          FUN_00406b10();
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_MENUBAR_BTN");
          local_8._0_1_ = 0x88;
          CStringT<>();
          in_ECX = local_3fc;
          local_8._0_1_ = 0x89;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          local_8._0_1_ = 0x68;
          CTagManager::~CTagManager((CTagManager *)&local_3ec);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0x8a;
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_POPUPMENU_BORDER");
          local_8._0_1_ = 0x8b;
          CStringT<>();
          local_8._0_1_ = 0x8c;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x8d;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 0x8e;
            FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_POPUPMENU_RESIZEBAR");
            local_8._0_1_ = 0x8f;
            CStringT<>();
            local_8._0_1_ = 0x90;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x8e;
            FUN_00406b10();
            FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_POPUPMENU_RESIZEBAR_ICON_HV");
            local_8._0_1_ = 0x91;
            CStringT<>();
            local_8._0_1_ = 0x92;
            FUN_0081b501();
            FUN_00406b10();
            local_8._0_1_ = 0x8e;
            FUN_00406b10();
            FUN_0082f5e5(&local_68,L"IDB_OFFICE2007_POPUPMENU_RESIZEBAR_ICON_HVT");
            local_8._0_1_ = 0x93;
            CStringT<>();
            local_8._0_1_ = 0x94;
            FUN_0081b501();
            FUN_00406b10();
            local_8._0_1_ = 0x8e;
            FUN_00406b10();
            FUN_0082f5e5(local_400,L"IDB_OFFICE2007_POPUPMENU_RESIZEBAR_ICON_V");
            local_8._0_1_ = 0x95;
            CStringT<>();
            local_8._0_1_ = 0x96;
            FUN_0081b501();
            FUN_00406b10();
            FUN_00406b10();
            CTagManager::~CTagManager(local_3c4);
          }
          FUN_00406b10();
          local_8._0_1_ = 0x68;
          CTagManager::~CTagManager((CTagManager *)&local_3ec);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0x97;
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_STATUSBAR_BACK");
          local_8._0_1_ = 0x98;
          CStringT<>();
          local_8._0_1_ = 0x99;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0x97;
          FUN_00406b10();
          FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_STATUSBAR_BACK_EXT");
          local_8._0_1_ = 0x9a;
          CStringT<>();
          local_8._0_1_ = 0x9b;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0x97;
          FUN_00406b10();
          FUN_0082f5e5(&local_68,L"IDB_OFFICE2007_STATUSBAR_PANEBORDER");
          local_8._0_1_ = 0x9c;
          CStringT<>();
          local_8._0_1_ = 0x9d;
          FUN_0081b501();
          FUN_00406b10();
          local_8._0_1_ = 0x97;
          FUN_00406b10();
          FUN_0082f5e5(local_400,L"IDB_OFFICE2007_STATUSBAR_SIZEBOX");
          local_8._0_1_ = 0x9e;
          CStringT<>();
          local_8._0_1_ = 0x9f;
          FUN_0081b501();
          FUN_00406b10();
          local_8._0_1_ = 0x97;
          FUN_00406b10();
          in_ECX[0x23ea] = in_ECX[0x23e1];
          in_ECX[0x23eb] = in_ECX[0x23e3];
          in_ECX[0x23ec] = in_ECX[0x23e3];
          CStringT<>();
          local_8._0_1_ = 0xa0;
          FUN_0081b2a5(local_3c8,in_ECX + 0x23ea);
          local_8._0_1_ = 0x97;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xa1;
          FUN_0081b2a5(&local_3d4,in_ECX + 0x23eb);
          local_8._0_1_ = 0x97;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xa2;
          FUN_0081b2a5(&local_3bc,in_ECX + 0x23ec);
          FUN_00406b10();
          local_8._0_1_ = 0x68;
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xa3;
          CStringT<>();
          piVar11 = local_3fc;
          local_8._0_1_ = 0xa4;
          FUN_0081b2a5(local_3b0,local_3fc + 0x6b);
          local_8._0_1_ = 0xa3;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xa5;
          FUN_0081b2a5(local_3c8,piVar11 + 0x6c);
          local_8._0_1_ = 0xa3;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xa6;
          FUN_0081b2a5(&local_3d4,piVar11 + 0x2410);
          FUN_00406b10();
          CTagManager::~CTagManager(local_3c4);
        }
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager((CTagManager *)&local_4c);
      }
      piVar11 = local_3fc;
      if (local_3fc[0x2f] == -0x1000000) {
        local_3fc[0x2f] = local_3fc[0x2e];
      }
      CGdiObject::DeleteObject((CGdiObject *)(local_3fc + 0x41));
      FUN_004b05a0();
      iVar5 = FUN_007c2511();
      piVar11[0x23ed] = *(int *)(iVar5 + 0x6c);
      iVar5 = FUN_007c2511();
      piVar11[0x23ee] = *(int *)(iVar5 + 0x20);
      piVar11[0x23ef] = piVar11[0x3a];
      iVar5 = FUN_007c2511();
      piVar11[0x23f0] = *(int *)(iVar5 + 0x3c);
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8._0_1_ = 0xa7;
        CStringT<>();
        local_8._0_1_ = 0xa8;
        FUN_0081b2a5(local_3b0,piVar11 + 0x23ed);
        local_8._0_1_ = 0xa7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xa9;
        FUN_0081b2a5(local_3c8,piVar11 + 0x23ef);
        local_8._0_1_ = 0xa7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xaa;
        FUN_0081b2a5(&local_3d4,piVar11 + 0x23ee);
        local_8._0_1_ = 0xa7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xab;
        FUN_0081b2a5(&local_3bc,piVar11 + 0x23f0);
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager(local_3c4);
      }
      iVar5 = FUN_007c2511();
      piVar11[0x23f1] = *(int *)(iVar5 + 0x6c);
      iVar6 = FUN_007c2511();
      iVar5 = piVar11[0x3a];
      piVar12 = piVar11 + 0x2400;
      piVar11[0x23f2] = *(int *)(iVar6 + 0x20);
      piVar11[0x23f4] = iVar5;
      piVar11[0x23f3] = iVar5;
      piVar11[0x23f7] = piVar11[0x23f1];
      *piVar12 = iVar5;
      piVar11[0x23fd] = iVar5;
      iVar5 = FUN_007c2511();
      piVar11[0x2401] = *(int *)(iVar5 + 0x3c);
      piVar11[0x23f5] = piVar11[0x59];
      piVar11[0x23f6] = piVar11[0x5a];
      iVar5 = FUN_007c2511();
      iVar5 = *(int *)(iVar5 + 0x1c);
      piVar11[0x23f8] = iVar5;
      piVar11[0x23f9] = iVar5;
      piVar11[0x23fe] = piVar11[0x65];
      piVar11[0x23ff] = piVar11[100];
      piVar11[0x23fb] = piVar11[0x67];
      piVar11[0x23fc] = piVar11[0x66];
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8._0_1_ = 0xac;
        CStringT<>();
        local_8._0_1_ = 0xad;
        FUN_0081b2a5(local_3b0,piVar11 + 0x23f1);
        local_8._0_1_ = 0xac;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xae;
        FUN_0081b2a5(local_3c8,piVar11 + 0x23f4);
        local_8._0_1_ = 0xac;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xaf;
        FUN_0081b2a5(&local_3d4,piVar11 + 0x23f2);
        local_8._0_1_ = 0xac;
        FUN_00406b10();
        piVar11[0x23f3] = piVar11[0x23f4];
        CStringT<>();
        local_8._0_1_ = 0xb0;
        FUN_0081b2a5(&local_3bc,piVar11 + 0x23f3);
        local_8._0_1_ = 0xac;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xb1;
        FUN_0081b2a5(&local_3d8,piVar11 + 0x2401);
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xb2;
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xb3;
          CStringT<>();
          local_8._0_1_ = 0xb4;
          FUN_0081b2a5(local_3b0,piVar11 + 0x23f5);
          local_8._0_1_ = 0xb3;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xb5;
          FUN_0081b2a5(local_3c8,piVar11 + 0x23f6);
          local_8._0_1_ = 0xb3;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xb6;
          FUN_0081b2a5(&local_3d4,piVar11 + 0x23f7);
          local_8._0_1_ = 0xb3;
          FUN_00406b10();
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_COMBOBOX_BTN");
          local_8._0_1_ = 0xb7;
          CStringT<>();
          local_8._0_1_ = 0xb8;
          iVar5 = FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0xb3;
          FUN_00406b10();
          if (iVar5 == 0) {
            CStringT<>();
            local_8._0_1_ = 0xb9;
            FUN_0081b2a5(local_3b0,piVar11 + 0x23fe);
            local_8._0_1_ = 0xb3;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xba;
            FUN_0081b2a5(local_3c8,piVar11 + 0x23ff);
            local_8._0_1_ = 0xb3;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xbb;
            FUN_0081b2a5(&local_3d4,piVar11 + 0x23f8);
            local_8._0_1_ = 0xb3;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xbc;
            FUN_0081b2a5(&local_3bc,piVar11 + 0x23f9);
            local_8._0_1_ = 0xb3;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xbd;
            FUN_0081b2a5(&local_3d8,piVar11 + 0x23fb);
            local_8._0_1_ = 0xb3;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xbe;
            FUN_0081b2a5(&local_3cc,piVar11 + 0x23fc);
            local_8._0_1_ = 0xb3;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xbf;
            FUN_0081b2a5(&local_3e4,piVar12);
            local_8._0_1_ = 0xb3;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xc0;
            FUN_0081b2a5(local_3f4,piVar11 + 0x23fa);
            local_8._0_1_ = 0xb3;
            FUN_00406b10();
            piVar11[0x23fd] = *piVar12;
            CStringT<>();
            local_8._0_1_ = 0xc1;
            FUN_0081b2a5(&local_3dc,piVar11 + 0x23fd);
            FUN_00406b10();
          }
          CTagManager::~CTagManager((CTagManager *)&local_3c);
        }
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager(local_3c4);
      }
      piVar11[0x242e] = piVar11[0x23ed];
      piVar11[0x242f] = piVar11[0x23ee];
      piVar11[0x2430] = piVar11[0x23ef];
      piVar11[0x2431] = piVar11[0x23ef];
      piVar11[0x2432] = piVar11[0x23f0];
      piVar11[0x2435] = piVar11[0x23f7];
      piVar11[0x243e] = *piVar12;
      piVar11[0x243b] = piVar11[0x23fd];
      piVar11[0x2433] = piVar11[0x23f5];
      piVar11[0x2434] = piVar11[0x23f6];
      piVar11[0x2436] = piVar11[0x23f8];
      piVar11[0x2437] = piVar11[0x23f9];
      piVar11[0x243c] = piVar11[0x23fe];
      piVar11[0x243d] = piVar11[0x23ff];
      piVar11[0x2439] = piVar11[0x23fb];
      piVar11[0x243a] = piVar11[0x23fc];
      piVar11[0x6d] = piVar11[0x58];
      piVar11[0x6e] = piVar11[0x58];
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8._0_1_ = 0xc2;
        CStringT<>();
        local_8._0_1_ = 0xc3;
        FUN_0081b2a5(local_3b0,piVar11 + 0x6d);
        local_8._0_1_ = 0xc2;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xc4;
        FUN_0081b2a5(local_3c8,piVar11 + 0x6e);
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xc5;
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          CStringT<>();
          local_8._0_1_ = 199;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            CStringT<>();
            local_8._0_1_ = 0xc9;
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0xca;
              CStringT<>();
              local_8._0_1_ = 0xcb;
              FUN_0081b2a5(local_3b0,piVar11 + 0x6f);
              local_8._0_1_ = 0xca;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xcc;
              FUN_0081b2a5(local_3c8,piVar11 + 0x70);
              local_8._0_1_ = 0xca;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xcd;
              FUN_0081b2a5(&local_3d4,piVar11 + 0x2411);
              local_8._0_1_ = 0xca;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xce;
              FUN_0081b2a5(&local_3bc,piVar11 + 0x2412);
              local_8._0_1_ = 0xca;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xcf;
              FUN_0081b2a5(&local_3d8,piVar11 + 0x2417);
              local_8._0_1_ = 0xca;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xd0;
              FUN_0081b2a5(&local_3cc,piVar11 + 0x2418);
              FUN_00406b10();
              local_8._0_1_ = 0xc9;
              CTagManager::~CTagManager(local_3c4);
            }
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0xd1;
              CStringT<>();
              local_8._0_1_ = 0xd2;
              FUN_0081b2a5(local_3b0,piVar11 + 0x74);
              local_8._0_1_ = 0xd1;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xd3;
              FUN_0081b2a5(local_3c8,piVar11 + 0x73);
              FUN_00406b10();
              CTagManager::~CTagManager(local_3c4);
            }
            FUN_00406b10();
            local_8._0_1_ = 199;
            CTagManager::~CTagManager((CTagManager *)&local_4c);
          }
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            CStringT<>();
            local_8._0_1_ = 0xd5;
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0xd6;
              CStringT<>();
              local_8._0_1_ = 0xd7;
              FUN_0081b2a5(local_3b0,piVar11 + 0x71);
              local_8._0_1_ = 0xd6;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xd8;
              FUN_0081b2a5(local_3c8,piVar11 + 0x72);
              local_8._0_1_ = 0xd6;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xd9;
              FUN_0081b2a5(&local_3d4,piVar11 + 0x2413);
              local_8._0_1_ = 0xd6;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xda;
              FUN_0081b2a5(&local_3bc,piVar11 + 0x2414);
              local_8._0_1_ = 0xd6;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xdb;
              FUN_0081b2a5(&local_3d8,piVar11 + 0x2415);
              local_8._0_1_ = 0xd6;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xdc;
              FUN_0081b2a5(&local_3cc,piVar11 + 0x2416);
              FUN_00406b10();
              local_8._0_1_ = 0xd5;
              CTagManager::~CTagManager(local_3c4);
            }
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0xdd;
              CStringT<>();
              local_8._0_1_ = 0xde;
              FUN_0081b2a5(local_3b0,piVar11 + 0x76);
              local_8._0_1_ = 0xdd;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0xdf;
              FUN_0081b2a5(local_3c8,piVar11 + 0x75);
              FUN_00406b10();
              CTagManager::~CTagManager(local_3c4);
            }
            FUN_00406b10();
            local_8._0_1_ = 199;
            CTagManager::~CTagManager((CTagManager *)&local_4c);
          }
          CStringT<>();
          local_8._0_1_ = 0xe0;
          iVar5 = FUN_0081b2a5(local_3b0,piVar11 + 0x77);
          local_8 = CONCAT31(local_8._1_3_,199);
          FUN_00406b10();
          if (iVar5 != 0) {
            CGdiObject::DeleteObject((CGdiObject *)(piVar11 + 0x7c));
            FUN_004b6200();
          }
          FUN_00406b10();
          local_8._0_1_ = 0xc5;
          CTagManager::~CTagManager((CTagManager *)&local_3c);
        }
        FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_TASKPANE_SCROLL_BTN");
        local_8._0_1_ = 0xe1;
        CStringT<>();
        local_8._0_1_ = 0xe2;
        FUN_0081b2f8();
        FUN_00406b10();
        FUN_00406b10();
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager((CTagManager *)&local_3ec);
      }
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8._0_1_ = 0xe3;
        CStringT<>();
        local_8._0_1_ = 0xe4;
        FUN_0081b2a5(local_3b0,piVar11 + 0x241b);
        local_8._0_1_ = 0xe3;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xe5;
        FUN_0081b2a5(local_3c8,piVar11 + 0x241c);
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xe6;
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          CStringT<>();
          local_8._0_1_ = 0xe8;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            local_44 = 0;
            local_40 = 0;
            local_3c = 0;
            local_38 = 0;
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_64 = 0;
            local_60 = 0;
            local_5c = 0;
            local_58 = 0;
            local_74 = 0;
            local_70 = 0;
            local_6c = 0;
            local_68 = 0;
            puVar7 = (undefined4 *)FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_TAB_3D");
            local_8._0_1_ = 0xe9;
            FUN_0089b7c9(*puVar7,&local_74,&local_64,&local_54,&local_44);
            local_8._0_1_ = 0xeb;
            FUN_00406b10();
            iVar5 = FUN_0081a0cf(&local_3b4,local_c4);
            if (iVar5 != 0) {
              pcVar2 = *(code **)(piVar11[0xdba] + 0xc);
              guard_check_icall(local_c4);
              (*pcVar2)();
              pcVar2 = *(code **)(piVar11[0xe18] + 0xc);
              guard_check_icall(local_c4);
              (*pcVar2)();
            }
            FUN_00813eb2();
          }
          FUN_00406b10();
          local_8._0_1_ = 0xe6;
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          CStringT<>();
          local_8._0_1_ = 0xed;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            local_44 = 0;
            local_40 = 0;
            local_3c = 0;
            local_38 = 0;
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_64 = 0;
            local_60 = 0;
            local_5c = 0;
            local_58 = 0;
            local_74 = 0;
            local_70 = 0;
            local_6c = 0;
            local_68 = 0;
            puVar7 = (undefined4 *)FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_TAB_FLAT");
            local_8._0_1_ = 0xee;
            FUN_0089b7c9(*puVar7,&local_74,&local_64,&local_54,&local_44);
            local_8 = CONCAT31(local_8._1_3_,0xf0);
            FUN_00406b10();
            iVar5 = FUN_0081a0cf(&local_3b4,local_c4);
            if (iVar5 != 0) {
              pcVar2 = *(code **)(piVar11[0xe76] + 0xc);
              guard_check_icall(local_c4);
              (*pcVar2)();
              pcVar2 = *(code **)(piVar11[0xed4] + 0xc);
              guard_check_icall(local_c4);
              (*pcVar2)();
            }
            local_8._0_1_ = 0xed;
            FUN_00813eb2();
          }
          CStringT<>();
          local_8._0_1_ = 0xf1;
          FUN_0081b2a5(local_3b0,piVar11 + 0x2419);
          local_8._0_1_ = 0xed;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xf2;
          FUN_0081b2a5(local_3c8,piVar11 + 0x241a);
          local_8._0_1_ = 0xed;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xf3;
          iVar5 = FUN_0081b2a5(&local_3d4,&local_3d0);
          local_8 = CONCAT31(local_8._1_3_,0xed);
          FUN_00406b10();
          if (iVar5 != 0) {
            CGdiObject::DeleteObject((CGdiObject *)(piVar11 + 0x23c2));
            FUN_004b6200();
          }
          CStringT<>();
          local_8._0_1_ = 0xf4;
          iVar5 = FUN_0081b2a5(local_3b0,&local_3d0);
          local_8 = CONCAT31(local_8._1_3_,0xed);
          FUN_00406b10();
          if (iVar5 != 0) {
            CGdiObject::DeleteObject((CGdiObject *)(piVar11 + 0x23c4));
            FUN_004b6200();
          }
          CStringT<>();
          local_8._0_1_ = 0xf5;
          iVar5 = FUN_0081b2a5(local_3b0,&local_3d0);
          local_8 = CONCAT31(local_8._1_3_,0xed);
          FUN_00406b10();
          if (iVar5 != 0) {
            CGdiObject::DeleteObject((CGdiObject *)(piVar11 + 0x23c6));
            FUN_004b6200();
          }
          CStringT<>();
          local_8._0_1_ = 0xf6;
          iVar5 = FUN_0081b2a5(local_3b0,&local_3d0);
          local_8._0_1_ = 0xed;
          FUN_00406b10();
          if (iVar5 != 0) {
            CGdiObject::DeleteObject((CGdiObject *)(piVar11 + 0x23c8));
            FUN_004b6200();
          }
          FUN_00406b10();
          CTagManager::~CTagManager(local_3c4);
        }
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager((CTagManager *)&local_3ec);
      }
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8._0_1_ = 0xf7;
        CStringT<>();
        local_8._0_1_ = 0xf8;
        FUN_0081b2a5(local_3b0,piVar11 + 0x2402);
        local_8._0_1_ = 0xf7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xf9;
        FUN_0081b2a5(local_3c8,piVar11 + 0x2403);
        local_8._0_1_ = 0xf7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xfa;
        FUN_0081b2a5(&local_3d4,piVar11 + 0x2404);
        local_8._0_1_ = 0xf7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xfb;
        FUN_0081b2a5(&local_3bc,piVar11 + 0x2405);
        local_8._0_1_ = 0xf7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xfc;
        FUN_0081b2a5(&local_3d8,piVar11 + 0x2406);
        local_8._0_1_ = 0xf7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xfd;
        FUN_0081b2a5(&local_3cc,piVar11 + 0x2407);
        local_8._0_1_ = 0xf7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xfe;
        FUN_0081b2a5(&local_3b4,piVar11 + 0x2408);
        local_8._0_1_ = 0xf7;
        FUN_00406b10();
        CStringT<>();
        local_8._0_1_ = 0xff;
        FUN_0081b2a5(&local_3e4,piVar11 + 0x2409);
        local_8 = CONCAT31(local_8._1_3_,0xf7);
        FUN_00406b10();
        CStringT<>();
        local_8 = 0x100;
        FUN_0081b2a5(local_3f4,piVar11 + 0x240a);
        local_8 = 0xf7;
        FUN_00406b10();
        local_8._0_1_ = 3;
        CTagManager::~CTagManager((CTagManager *)&local_3ec);
      }
      piVar11[0x2421] = piVar11[0x23e1];
      piVar11[0x2422] = piVar11[0x23e2];
      piVar11[0x2423] = piVar11[0x23e3];
      piVar11[0x2424] = piVar11[0x23e4];
      piVar11[0x2425] = piVar11[0x23e5];
      piVar11[0x2426] = piVar11[0x23e4];
      piVar11[0x2427] = piVar11[0x23e5];
      iVar5 = FUN_007c2511();
      piVar11[0x242a] = *(int *)(iVar5 + 100);
      iVar5 = FUN_007c2511();
      iVar5 = *(int *)(iVar5 + 0x6c);
      piVar11[0x242c] = iVar5;
      piVar11[0x242d] = iVar5;
      iVar5 = FUN_007c2511();
      piVar11[0x242b] = *(int *)(iVar5 + 0x1c);
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8 = 0x101;
        CStringT<>();
        local_8._0_1_ = 2;
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 3;
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_CATEGORY_BACK");
          local_8._0_1_ = 4;
          CStringT<>();
          local_8._0_1_ = 5;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 6;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 7;
            FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_CATEGORY_TAB");
            local_8._0_1_ = 8;
            CStringT<>();
            local_8._0_1_ = 9;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 7;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 10;
            FUN_0081b2a5(local_3c8,piVar11 + 0x2421);
            local_8._0_1_ = 7;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xb;
            FUN_0081b2a5(&local_3d4,piVar11 + 0x2422);
            local_8._0_1_ = 7;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xc;
            FUN_0081b2a5(&local_3bc,piVar11 + 0x2423);
            FUN_00406b10();
            local_8._0_1_ = 6;
            CTagManager::~CTagManager((CTagManager *)&local_3c);
          }
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_CATEGORY_TAB_SEP");
          local_8._0_1_ = 0xd;
          CStringT<>();
          local_8._0_1_ = 0xe;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 6;
          FUN_00406b10();
          FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_RIBBON_BTN_PAGE_L");
          local_8._0_1_ = 0xf;
          CStringT<>();
          local_8._0_1_ = 0x10;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 6;
          FUN_00406b10();
          FUN_0082f5e5(&local_68,L"IDB_OFFICE2007_RIBBON_BTN_PAGE_R");
          local_8._0_1_ = 0x11;
          CStringT<>();
          local_8._0_1_ = 0x12;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          FUN_00406b10();
          local_8._0_1_ = 2;
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          CStringT<>();
          local_8._0_1_ = 0x14;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 0x15;
            FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_PANEL_BACK_T");
            local_8._0_1_ = 0x16;
            CStringT<>();
            local_8._0_1_ = 0x17;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x15;
            FUN_00406b10();
            FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_RIBBON_PANEL_BACK_B");
            local_8._0_1_ = 0x18;
            CStringT<>();
            local_8._0_1_ = 0x19;
            FUN_0081b2f8();
            FUN_00406b10();
            FUN_00406b10();
            CTagManager::~CTagManager((CTagManager *)&local_3c);
          }
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x1a;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 0x1b;
            FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_BTN_LAUNCH");
            local_8._0_1_ = 0x1c;
            CStringT<>();
            local_8._0_1_ = 0x1d;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x1b;
            FUN_00406b10();
            FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_RIBBON_BTN_LAUNCH_ICON");
            local_8._0_1_ = 0x1e;
            CStringT<>();
            local_8._0_1_ = 0x1f;
            FUN_0081b501();
            FUN_00406b10();
            local_8._0_1_ = 0x1b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x20;
            FUN_0081b2a5(local_3c8,piVar11 + 0x2426);
            local_8._0_1_ = 0x1b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x21;
            FUN_0081b2a5(&local_3d4,piVar11 + 0x2427);
            local_8._0_1_ = 0x1b;
            FUN_00406b10();
            FUN_007c2511();
            fVar16 = (float10)FUN_007c2673();
            FUN_007eba06((double)fVar16);
            CTagManager::~CTagManager((CTagManager *)&local_3c);
          }
          local_8._0_1_ = 0x13;
          FUN_00406b10();
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_PANEL_SEPARATOR");
          local_8._0_1_ = 0x22;
          CStringT<>();
          local_8._0_1_ = 0x23;
          FUN_0081b501();
          FUN_00406b10();
          local_8._0_1_ = 0x13;
          FUN_00406b10();
          FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_RIBBON_PANEL_QAT");
          local_8._0_1_ = 0x24;
          CStringT<>();
          local_8._0_1_ = 0x25;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x26;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 0x27;
            FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_BTN_GROUP_F");
            local_8._0_1_ = 0x28;
            CStringT<>();
            local_8._0_1_ = 0x29;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_RIBBON_BTN_GROUP_M");
            local_8._0_1_ = 0x2a;
            CStringT<>();
            local_8._0_1_ = 0x2b;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_68,L"IDB_OFFICE2007_RIBBON_BTN_GROUP_L");
            local_8._0_1_ = 0x2c;
            CStringT<>();
            local_8._0_1_ = 0x2d;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(local_400,L"IDB_OFFICE2007_RIBBON_BTN_GROUP_S");
            local_8._0_1_ = 0x2e;
            CStringT<>();
            local_8._0_1_ = 0x2f;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(local_410,L"IDB_OFFICE2007_RIBBON_BTN_GROUPMENU_F_C");
            local_8._0_1_ = 0x30;
            CStringT<>();
            local_8._0_1_ = 0x31;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_3b8,L"IDB_OFFICE2007_RIBBON_BTN_GROUPMENU_F_M");
            local_8._0_1_ = 0x32;
            CStringT<>();
            local_8._0_1_ = 0x33;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(local_3c8,L"IDB_OFFICE2007_RIBBON_BTN_GROUPMENU_M_C");
            local_8._0_1_ = 0x34;
            CStringT<>();
            local_8._0_1_ = 0x35;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_3d4,L"IDB_OFFICE2007_RIBBON_BTN_GROUPMENU_M_M");
            local_8._0_1_ = 0x36;
            CStringT<>();
            local_8._0_1_ = 0x37;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_3bc,L"IDB_OFFICE2007_RIBBON_BTN_GROUPMENU_L_C");
            local_8._0_1_ = 0x38;
            CStringT<>();
            local_8._0_1_ = 0x39;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_3d8,L"IDB_OFFICE2007_RIBBON_BTN_GROUPMENU_L_M");
            local_8._0_1_ = 0x3a;
            CStringT<>();
            local_8._0_1_ = 0x3b;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_3cc,L"IDB_OFFICE2007_RIBBON_BTN_NORMAL_S");
            local_8._0_1_ = 0x3c;
            CStringT<>();
            local_8._0_1_ = 0x3d;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_3e4,L"IDB_OFFICE2007_RIBBON_BTN_NORMAL_B");
            local_8._0_1_ = 0x3e;
            CStringT<>();
            local_8._0_1_ = 0x3f;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(local_3f4,L"IDB_OFFICE2007_RIBBON_BTN_DEFAULT");
            local_8._0_1_ = 0x40;
            CStringT<>();
            local_8._0_1_ = 0x41;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_3dc,L"IDB_OFFICE2007_RIBBON_BTN_DEFAULT_ICON");
            local_8._0_1_ = 0x42;
            CStringT<>();
            local_8._0_1_ = 0x43;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_58,L"IDB_OFFICE2007_RIBBON_BTN_DEFAULT_IMAGE");
            local_8._0_1_ = 0x44;
            CStringT<>();
            local_8._0_1_ = 0x45;
            FUN_0081b501();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_BTN_DEFAULT_QAT");
            local_8._0_1_ = 0x46;
            CStringT<>();
            local_8._0_1_ = 0x47;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            if (piVar11[0x1c8f] == 0) {
              FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_BTN_DEFAULT_QAT_ICON");
              local_8._0_1_ = 0x48;
              CStringT<>();
              local_8._0_1_ = 0x49;
              FUN_0081b2f8();
              FUN_00406b10();
              local_8._0_1_ = 0x27;
              FUN_00406b10();
            }
            FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_BTN_MENU_H_C");
            local_8._0_1_ = 0x4a;
            CStringT<>();
            local_8._0_1_ = 0x4b;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_58,L"IDB_OFFICE2007_RIBBON_BTN_MENU_H_M");
            local_8._0_1_ = 0x4c;
            CStringT<>();
            local_8._0_1_ = 0x4d;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_BTN_MENU_V_C");
            local_8._0_1_ = 0x4e;
            CStringT<>();
            local_8._0_1_ = 0x4f;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_RIBBON_BTN_MENU_V_M");
            local_8._0_1_ = 0x50;
            CStringT<>();
            local_8._0_1_ = 0x51;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_68,L"IDB_OFFICE2007_RIBBON_BTN_CHECK");
            local_8._0_1_ = 0x52;
            CStringT<>();
            local_8._0_1_ = 0x53;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_007c2511();
            fVar16 = (float10)FUN_007c2673();
            FUN_0089c9f3((double)fVar16);
            FUN_0082f5e5(local_400,L"IDB_OFFICE2007_RIBBON_BTN_PALETTE_T");
            local_8._0_1_ = 0x54;
            CStringT<>();
            local_8._0_1_ = 0x55;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(local_410,L"IDB_OFFICE2007_RIBBON_BTN_PALETTE_M");
            local_8._0_1_ = 0x56;
            CStringT<>();
            local_8._0_1_ = 0x57;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0x27;
            FUN_00406b10();
            FUN_0082f5e5(&local_3b8,L"IDB_OFFICE2007_RIBBON_BTN_PALETTE_B");
            local_8._0_1_ = 0x58;
            CStringT<>();
            local_8._0_1_ = 0x59;
            FUN_0081b2f8();
            FUN_00406b10();
            FUN_00406b10();
            CTagManager::~CTagManager((CTagManager *)&local_3c);
          }
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x5a;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 0x5b;
            CStringT<>();
            local_8._0_1_ = 0x5c;
            FUN_0081b2a5(local_3b0,piVar11 + 0x242a);
            local_8._0_1_ = 0x5b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x5d;
            FUN_0081b2a5(local_3c8,piVar11 + 0x242c);
            local_8._0_1_ = 0x5b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x5e;
            FUN_0081b2a5(&local_3d4,piVar11 + 0x242b);
            local_8._0_1_ = 0x5b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x5f;
            FUN_0081b2a5(&local_3bc,piVar11 + 0x242d);
            local_8._0_1_ = 0x5b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x60;
            FUN_0081b2a5(&local_3d8,piVar11 + 0x242e);
            local_8._0_1_ = 0x5b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x61;
            FUN_0081b2a5(&local_3cc,piVar11 + 0x2430);
            local_8._0_1_ = 0x5b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x62;
            FUN_0081b2a5(local_3f4,piVar11 + 0x242f);
            local_8._0_1_ = 0x5b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 99;
            FUN_0081b2a5(&local_3dc,piVar11 + 0x2431);
            local_8._0_1_ = 0x5b;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 100;
            FUN_0081b2a5(&local_3b8,piVar11 + 0x2432);
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x65;
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0x66;
              CStringT<>();
              local_8._0_1_ = 0x67;
              FUN_0081b2a5(&local_3b8,piVar11 + 0x2433);
              local_8._0_1_ = 0x66;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0x68;
              FUN_0081b2a5(local_3b0,piVar11 + 0x2434);
              local_8._0_1_ = 0x66;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0x69;
              FUN_0081b2a5(local_3c8,piVar11 + 0x2435);
              local_8._0_1_ = 0x66;
              FUN_00406b10();
              FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_COMBOBOX_BTN");
              local_8._0_1_ = 0x6a;
              CStringT<>();
              local_8._0_1_ = 0x6b;
              iVar5 = FUN_0081b2f8();
              FUN_00406b10();
              local_8._0_1_ = 0x66;
              FUN_00406b10();
              if (iVar5 == 0) {
                CStringT<>();
                local_8._0_1_ = 0x6c;
                FUN_0081b2a5(&local_3b8,piVar11 + 0x243c);
                local_8._0_1_ = 0x66;
                FUN_00406b10();
                CStringT<>();
                local_8._0_1_ = 0x6d;
                FUN_0081b2a5(local_3b0,piVar11 + 0x243d);
                local_8._0_1_ = 0x66;
                FUN_00406b10();
                CStringT<>();
                local_8._0_1_ = 0x6e;
                FUN_0081b2a5(local_3c8,piVar11 + 0x2436);
                local_8._0_1_ = 0x66;
                FUN_00406b10();
                CStringT<>();
                local_8._0_1_ = 0x6f;
                FUN_0081b2a5(&local_3d4,piVar11 + 0x2437);
                local_8._0_1_ = 0x66;
                FUN_00406b10();
                CStringT<>();
                local_8._0_1_ = 0x70;
                FUN_0081b2a5(&local_3bc,piVar11 + 0x2439);
                local_8._0_1_ = 0x66;
                FUN_00406b10();
                CStringT<>();
                local_8._0_1_ = 0x71;
                FUN_0081b2a5(&local_3d8,piVar11 + 0x243a);
                local_8._0_1_ = 0x66;
                FUN_00406b10();
                CStringT<>();
                local_8._0_1_ = 0x72;
                FUN_0081b2a5(&local_3cc,piVar11 + 0x243e);
                local_8._0_1_ = 0x66;
                FUN_00406b10();
                CStringT<>();
                local_8._0_1_ = 0x73;
                FUN_0081b2a5(local_3f4,piVar11 + 0x2438);
                local_8._0_1_ = 0x66;
                FUN_00406b10();
                piVar11[0x243b] = piVar11[0x243e];
                CStringT<>();
                local_8._0_1_ = 0x74;
                FUN_0081b2a5(&local_3dc,piVar11 + 0x243b);
                FUN_00406b10();
              }
              CTagManager::~CTagManager((CTagManager *)&local_3c);
            }
            FUN_00406b10();
            CTagManager::~CTagManager((CTagManager *)&local_5c);
          }
          local_8._0_1_ = 0x13;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x75;
          FUN_0081b2a5(&local_3b8,piVar11 + 0x2424);
          local_8._0_1_ = 0x13;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0x76;
          FUN_0081b2a5(local_3b0,piVar11 + 0x2425);
          FUN_00406b10();
          local_8._0_1_ = 2;
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          CStringT<>();
          local_8._0_1_ = 0x78;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 0x79;
            FUN_0089b85b();
            local_8._0_1_ = 0x7a;
            FUN_0089b85b();
            local_8._0_1_ = 0x7b;
            FUN_0089b85b();
            local_8._0_1_ = 0x7c;
            FUN_0089b85b();
            local_3d8 = piVar11[0x2421];
            local_3bc = piVar11[0x2422];
            local_8._0_1_ = 0x7d;
            local_3d4 = local_3d8;
            CStringT<>();
            local_8._0_1_ = 0x7e;
            FUN_0081b34e(&local_3b8,local_1b4);
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0x7f;
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0x80;
              CStringT<>();
              local_8._0_1_ = 0x81;
              FUN_0081b34e(&local_3b8,local_114);
              local_8._0_1_ = 0x80;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0x82;
              FUN_0081b2a5(local_3b0,&local_3d4);
              local_8._0_1_ = 0x80;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0x83;
              FUN_0081b2a5(local_3c8,&local_3bc);
              FUN_00406b10();
              CTagManager::~CTagManager((CTagManager *)&local_3c);
            }
            CStringT<>();
            local_8._0_1_ = 0x84;
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0x85;
              CStringT<>();
              local_8._0_1_ = 0x86;
              FUN_0081b34e(&local_3b8,local_164);
              local_8._0_1_ = 0x85;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0x87;
              FUN_0081b2a5(local_3b0,&local_3d8);
              FUN_00406b10();
              local_8._0_1_ = 0x84;
              CTagManager::~CTagManager((CTagManager *)&local_3c);
            }
            CStringT<>();
            local_8._0_1_ = 0x88;
            FUN_0081b34e(&local_3b8,local_c4);
            local_8._0_1_ = 0x84;
            FUN_00406b10();
            FUN_0082f5e5(&local_30,L"IDB_OFFICE2007_RIBBON_CONTEXT_R_");
            local_8._0_1_ = 0x89;
            FUN_0082f5e5(&local_2c,L"IDB_OFFICE2007_RIBBON_CONTEXT_O_");
            local_8._0_1_ = 0x8a;
            FUN_0082f5e5(&local_28,L"IDB_OFFICE2007_RIBBON_CONTEXT_Y_");
            local_8._0_1_ = 0x8b;
            FUN_0082f5e5(&local_24,L"IDB_OFFICE2007_RIBBON_CONTEXT_G_");
            local_8._0_1_ = 0x8c;
            FUN_0082f5e5(&local_20,L"IDB_OFFICE2007_RIBBON_CONTEXT_B_");
            local_8._0_1_ = 0x8d;
            FUN_0082f5e5(&local_1c,L"IDB_OFFICE2007_RIBBON_CONTEXT_I_");
            local_8._0_1_ = 0x8e;
            FUN_0082f5e5(local_18,L"IDB_OFFICE2007_RIBBON_CONTEXT_V_");
            ppwVar13 = &local_30;
            local_8._0_1_ = 0x8f;
            piVar11 = piVar11 + 0x250e;
            local_3b0[0] = 7;
            do {
              local_3b8 = ppwVar13;
              pCVar8 = (CSimpleStringT<wchar_t,0> *)
                       ATL::operator+((CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                       *)&local_48,(wchar_t *)ppwVar13);
              local_8._0_1_ = 0x90;
              ATL::CSimpleStringT<wchar_t,0>::operator=(local_c0,pCVar8);
              local_8._0_1_ = 0x8f;
              FUN_00406b10();
              pCVar8 = (CSimpleStringT<wchar_t,0> *)
                       ATL::operator+((CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                       *)&local_58,(wchar_t *)ppwVar13);
              local_8._0_1_ = 0x91;
              ATL::CSimpleStringT<wchar_t,0>::operator=(local_110,pCVar8);
              local_8._0_1_ = 0x8f;
              FUN_00406b10();
              pCVar8 = (CSimpleStringT<wchar_t,0> *)ATL::operator+(local_3e0,(wchar_t *)ppwVar13);
              local_8._0_1_ = 0x92;
              ATL::CSimpleStringT<wchar_t,0>::operator=(local_160,pCVar8);
              local_8._0_1_ = 0x8f;
              FUN_00406b10();
              pCVar8 = (CSimpleStringT<wchar_t,0> *)ATL::operator+(local_3f8,(wchar_t *)ppwVar13);
              local_8._0_1_ = 0x93;
              ATL::CSimpleStringT<wchar_t,0>::operator=(local_1b0,pCVar8);
              local_8._0_1_ = 0x8f;
              FUN_00406b10();
              pcVar2 = *(code **)(piVar11[0x5e] + 0xc);
              guard_check_icall(local_c4);
              (*pcVar2)();
              pcVar2 = *(code **)(piVar11[-0xbc] + 0xc);
              guard_check_icall(local_164);
              (*pcVar2)();
              pcVar2 = *(code **)(*piVar11 + 0xc);
              guard_check_icall(local_114,0);
              (*pcVar2)();
              pcVar2 = *(code **)(piVar11[-0x5e] + 0xc);
              guard_check_icall(local_1b4,0);
              (*pcVar2)();
              piVar11[0xbd] = local_3d4;
              ppwVar13 = local_3b8 + 1;
              piVar11[0xbe] = local_3bc;
              piVar11[0xbc] = local_3d8;
              piVar11 = piVar11 + 0x192;
              local_3b0[0] = local_3b0[0] + -1;
            } while (local_3b0[0] != 0);
            local_8._0_1_ = 0x84;
            local_3b8 = ppwVar13;
            _eh_vector_destructor_iterator_(&local_30,4,7,FUN_00404540);
            FUN_00406b10();
            FUN_00406b10();
            FUN_00813eb2();
            FUN_00813eb2();
            FUN_00813eb2();
            FUN_00813eb2();
            CTagManager::~CTagManager(local_3c4);
            piVar11 = local_3fc;
          }
          CStringT<>();
          local_8._0_1_ = 0x94;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            CStringT<>();
            local_8._0_1_ = 0x96;
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0x97;
              FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_CONTEXT_PANEL_BACK_T");
              local_8._0_1_ = 0x98;
              CStringT<>();
              local_8._0_1_ = 0x99;
              FUN_0081b2f8();
              FUN_00406b10();
              local_8._0_1_ = 0x97;
              FUN_00406b10();
              FUN_0082f5e5(&local_58,L"IDB_OFFICE2007_RIBBON_CONTEXT_PANEL_BACK_B");
              local_8._0_1_ = 0x9a;
              CStringT<>();
              local_8._0_1_ = 0x9b;
              FUN_0081b2f8();
              FUN_00406b10();
              FUN_00406b10();
              CTagManager::~CTagManager((CTagManager *)&local_3c);
            }
            CStringT<>();
            local_8._0_1_ = 0x9c;
            iVar5 = FUN_008199bf();
            if (iVar5 != 0) {
              FUN_00819947();
              local_8._0_1_ = 0x9d;
              CStringT<>();
              local_8._0_1_ = 0x9e;
              FUN_0081b2a5(&local_3b8,piVar11 + 0x2441);
              local_8._0_1_ = 0x9d;
              FUN_00406b10();
              CStringT<>();
              local_8._0_1_ = 0x9f;
              FUN_0081b2a5(local_3b0,piVar11 + 0x2442);
              FUN_00406b10();
              local_8._0_1_ = 0x9c;
              CTagManager::~CTagManager((CTagManager *)&local_3c);
            }
            CStringT<>();
            local_8._0_1_ = 0xa0;
            FUN_0081b2a5(&local_3b8,piVar11 + 0x243f);
            local_8._0_1_ = 0x9c;
            FUN_00406b10();
            CStringT<>();
            local_8._0_1_ = 0xa1;
            FUN_0081b2a5(local_3b0,piVar11 + 0x2440);
            FUN_00406b10();
            FUN_00406b10();
            FUN_00406b10();
            local_8._0_1_ = 0x94;
            CTagManager::~CTagManager(local_3c4);
          }
          FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_CONTEXT_SEPARATOR");
          local_8._0_1_ = 0xa2;
          CStringT<>();
          local_8._0_1_ = 0xa3;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          FUN_00406b10();
          FUN_00406b10();
          local_8._0_1_ = 2;
          CTagManager::~CTagManager((CTagManager *)&local_6c);
        }
        FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_BTN_MAIN");
        local_8._0_1_ = 0xa4;
        CStringT<>();
        local_8._0_1_ = 0xa5;
        FUN_0081b2f8();
        FUN_00406b10();
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_00406b10();
        if (piVar11[0x1b17] != 0) {
          FUN_007c2511();
          fVar16 = (float10)FUN_007c2673();
          FUN_0089c9f3((double)fVar16);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xa6;
          FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_PANEL_MAIN");
          local_8._0_1_ = 0xa7;
          CStringT<>();
          local_8._0_1_ = 0xa8;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0xa6;
          FUN_00406b10();
          FUN_0082f5e5(&local_58,L"IDB_OFFICE2007_RIBBON_PANEL_MAIN_BORDER");
          local_8._0_1_ = 0xa9;
          CStringT<>();
          local_8._0_1_ = 0xaa;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0xa6;
          FUN_00406b10();
          FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_BTN_PANEL_MAIN");
          local_8._0_1_ = 0xab;
          CStringT<>();
          local_8._0_1_ = 0xac;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          local_8 = CONCAT31(local_8._1_3_,2);
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xad;
          FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_CAPTION_QA");
          local_8._0_1_ = 0xae;
          CStringT<>();
          local_8._0_1_ = 0xaf;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0xad;
          FUN_00406b10();
          FUN_0082f5e5(&local_58,L"IDB_OFFICE2007_RIBBON_CAPTION_QA_GLASS");
          local_8._0_1_ = 0xb0;
          CStringT<>();
          local_8._0_1_ = 0xb1;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          local_8 = CONCAT31(local_8._1_3_,2);
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xb2;
          FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_BTN_STATUS_PANE");
          local_8._0_1_ = 0xb3;
          CStringT<>();
          local_8._0_1_ = 0xb4;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xb5;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 0xb6;
            FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_SLIDER_THUMB");
            local_8._0_1_ = 0xb7;
            CStringT<>();
            local_8._0_1_ = 0xb8;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0xb6;
            FUN_00406b10();
            FUN_0082f5e5(&local_58,L"IDB_OFFICE2007_RIBBON_SLIDER_BTN_PLUS");
            local_8._0_1_ = 0xb9;
            CStringT<>();
            local_8._0_1_ = 0xba;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0xb6;
            FUN_00406b10();
            FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_SLIDER_BTN_MINUS");
            local_8._0_1_ = 0xbb;
            CStringT<>();
            local_8._0_1_ = 0xbc;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0xb6;
            FUN_00406b10();
            FUN_007c2511();
            fVar16 = (float10)FUN_007c2673();
            FUN_0089c9f3((double)fVar16);
            FUN_007c2511();
            fVar16 = (float10)FUN_007c2673();
            FUN_0089c9f3((double)fVar16);
            FUN_007c2511();
            fVar16 = (float10)FUN_007c2673();
            FUN_0089c9f3((double)fVar16);
            CTagManager::~CTagManager(local_3c4);
            piVar11 = local_3fc;
          }
          CStringT<>();
          local_8._0_1_ = 0xbd;
          iVar5 = FUN_008199bf();
          if (iVar5 != 0) {
            FUN_00819947();
            local_8._0_1_ = 0xbe;
            FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_PROGRESS_BACK");
            local_8._0_1_ = 0xbf;
            CStringT<>();
            local_8._0_1_ = 0xc0;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0xbe;
            FUN_00406b10();
            FUN_0082f5e5(&local_58,L"IDB_OFFICE2007_RIBBON_PROGRESS_NORMAL");
            local_8._0_1_ = 0xc1;
            CStringT<>();
            local_8._0_1_ = 0xc2;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0xbe;
            FUN_00406b10();
            FUN_0082f5e5(local_3e0,L"IDB_OFFICE2007_RIBBON_PROGRESS_NORMAL_EXT");
            local_8._0_1_ = 0xc3;
            CStringT<>();
            local_8._0_1_ = 0xc4;
            FUN_0081b2f8();
            FUN_00406b10();
            local_8._0_1_ = 0xbe;
            FUN_00406b10();
            FUN_0082f5e5(local_3f8,L"IDB_OFFICE2007_RIBBON_PROGRESS_INFINITY");
            local_8._0_1_ = 0xc5;
            CStringT<>();
            local_8._0_1_ = 0xc6;
            FUN_0081b2f8();
            FUN_00406b10();
            FUN_00406b10();
            CTagManager::~CTagManager(local_3c4);
          }
          FUN_00406b10();
          FUN_00406b10();
          local_8 = CONCAT31(local_8._1_3_,2);
          CTagManager::~CTagManager((CTagManager *)&local_3c);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 199;
          FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_BORDER_QAT");
          local_8._0_1_ = 200;
          CStringT<>();
          local_8._0_1_ = 0xc9;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 199;
          FUN_00406b10();
          FUN_0082f5e5(&local_58,L"IDB_OFFICE2007_RIBBON_BORDER_FLOATY");
          local_8._0_1_ = 0xca;
          CStringT<>();
          local_8._0_1_ = 0xcb;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          local_8 = CONCAT31(local_8._1_3_,2);
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xcc;
          FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_RIBBON_KEYTIP_BACK");
          local_8._0_1_ = 0xcd;
          CStringT<>();
          local_8._0_1_ = 0xce;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0xcc;
          FUN_00406b10();
          CStringT<>();
          pDVar1 = (DWORD *)(piVar11 + 0x2428);
          local_8._0_1_ = 0xcf;
          FUN_0081b2a5(local_3b0,pDVar1);
          local_8 = CONCAT31(local_8._1_3_,0xcc);
          FUN_00406b10();
          local_3b0[0] = 0;
          if (*pDVar1 == 0xffffffff) {
            if ((piVar11[0x86] == 0) || (DVar9 = piVar11[0x300c], DVar9 == 0xffffffff)) {
              local_3b0[0] = 1;
              DVar9 = GetSysColor(0x17);
            }
            *pDVar1 = DVar9;
          }
          CStringT<>();
          local_8._0_1_ = 0xd0;
          FUN_0081b2a5(&local_3b8,piVar11 + 0x2429);
          local_8 = CONCAT31(local_8._1_3_,0xcc);
          FUN_00406b10();
          if (piVar11[0x2429] == -1) {
            iVar5 = FUN_007c2511();
            if (local_3b0[0] == 0) {
              iVar5 = FUN_00818965();
            }
            else {
              iVar5 = *(int *)(iVar5 + 0x38);
            }
            piVar11[0x2429] = iVar5;
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xd1;
          CStringT<>();
          local_8._0_1_ = 0xd2;
          FUN_0081b2a5(&local_3b8,piVar11 + 0x244d);
          local_8._0_1_ = 0xd1;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xd3;
          FUN_0081b2a5(local_3b0,piVar11 + 0x244e);
          local_8._0_1_ = 0xd1;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xd4;
          FUN_0081b2a5(local_3c8,piVar11 + 0x244f);
          local_8._0_1_ = 0xd1;
          FUN_00406b10();
          CStringT<>();
          local_8 = CONCAT31(local_8._1_3_,0xd5);
          FUN_0081b2a5(&local_3d4,piVar11 + 0x2450);
          FUN_00406b10();
          CTagManager::~CTagManager(local_3c4);
        }
        FUN_00406b10();
        local_8._0_1_ = 3;
        local_8._1_3_ = 0;
        CTagManager::~CTagManager((CTagManager *)&local_3ec);
      }
      iVar5 = piVar11[0x2410];
      piVar11[0x2420] = iVar5;
      piVar11[0x241d] = iVar5;
      piVar11[0x241e] = iVar5;
      piVar11[0x241f] = iVar5;
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8 = 0x1d6;
        CStringT<>();
        local_8._0_1_ = 0xd7;
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xd8;
          CStringT<>();
          local_8._0_1_ = 0xd9;
          FUN_0081b2a5(&local_3b8,piVar11 + 0x2420);
          FUN_00406b10();
          local_8._0_1_ = 0xd7;
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xda;
          FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_OUTLOOK_BTN_PAGE");
          local_8._0_1_ = 0xdb;
          CStringT<>();
          local_8._0_1_ = 0xdc;
          FUN_0081b2f8();
          FUN_00406b10();
          local_8._0_1_ = 0xda;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xdd;
          FUN_0081b2a5(local_3b0,piVar11 + 0x241d);
          local_8._0_1_ = 0xda;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xde;
          FUN_0081b2a5(local_3c8,piVar11 + 0x241e);
          local_8._0_1_ = 0xda;
          FUN_00406b10();
          CStringT<>();
          local_8._0_1_ = 0xdf;
          FUN_0081b2a5(&local_3d4,piVar11 + 0x241f);
          FUN_00406b10();
          local_8._0_1_ = 0xd7;
          CTagManager::~CTagManager(local_3c4);
        }
        iVar5 = FUN_008199bf();
        if (iVar5 != 0) {
          FUN_00819947();
          local_8._0_1_ = 0xe0;
          FUN_0082f5e5(&local_48,L"IDB_OFFICE2007_OUTLOOK_BAR_BACK");
          local_8._0_1_ = 0xe1;
          CStringT<>();
          local_8._0_1_ = 0xe2;
          FUN_0081b2f8();
          FUN_00406b10();
          FUN_00406b10();
          CTagManager::~CTagManager(local_3c4);
        }
        FUN_00406b10();
        local_8._0_1_ = 3;
        local_8._1_3_ = 0;
        CTagManager::~CTagManager((CTagManager *)&local_3ec);
      }
      piVar11[0x244b] = piVar11[0x58];
      piVar11[0x244c] = piVar11[0x57];
      iVar5 = FUN_008199bf();
      if (iVar5 != 0) {
        FUN_00819947();
        local_8 = 0x1e3;
        CStringT<>();
        local_8._0_1_ = 0xe4;
        FUN_0081b2a5(&local_3b8,piVar11 + 0x244b);
        local_8._0_1_ = 0xe3;
        FUN_00406b10();
        CStringT<>();
        local_8 = CONCAT31(local_8._1_3_,0xe5);
        FUN_0081b2a5(local_3b0,piVar11 + 0x244c);
        FUN_00406b10();
        local_8._0_1_ = 3;
        local_8._1_3_ = 0;
        CTagManager::~CTagManager(local_3c4);
      }
      if (local_414 != 0) {
        iVar5 = FUN_0079dd6d();
        *(int *)(iVar5 + 0xc) = local_414;
      }
    }
    FUN_00406b10();
  }
  CTagManager::~CTagManager(local_40c);
LAB_0083e56e:
  FUN_008d9b68();
  return;
}



