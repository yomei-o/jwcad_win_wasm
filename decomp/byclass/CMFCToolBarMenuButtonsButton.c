/* CMFCToolBarMenuButtonsButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarMenuButtonsButton[1] */
/* 0088ba69  `scalar_deleting_destructor'  54 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarMenuButtonsButton::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarMenuButtonsButton::_scalar_deleting_destructor_
          (CMFCToolBarMenuButtonsButton *this,uint param_1)

{
  *(undefined ***)this = vftable;
  CMFCToolBarButton::~CMFCToolBarButton((CMFCToolBarButton *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x74);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarMenuButtonsButton[5] */
/* 0088ba9f  CopyFrom  28 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCToolBarMenuButtonsButton::CopyFrom(class CMFCToolBarButton
   const &)
   
   Library: Visual Studio 2012 Release */

void __thiscall
CMFCToolBarMenuButtonsButton::CopyFrom
          (CMFCToolBarMenuButtonsButton *this,CMFCToolBarButton *param_1)

{
  FUN_00880ee9(param_1);
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(param_1 + 0x70);
  return;
}




/* vtable slots: CMFCToolBarMenuButtonsButton[0] */
/* 0088bae8  FUN_0088bae8  6 bytes, 0 callers */

undefined ** FUN_0088bae8(void)

{
  return &PTR_s_CMFCToolBarMenuButtonsButton_0099bc48;
}




/* vtable slots: CMFCToolBarMenuButtonsButton[7] */
/* 0088baee  FUN_0088baee  37 bytes, 0 callers */

void FUN_0088baee(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = GetSystemMetrics(0x37);
  iVar2 = GetSystemMetrics(0x36);
  param_1[1] = iVar1;
  *param_1 = iVar2;
  return;
}




/* vtable slots: CMFCToolBarMenuButtonsButton[6] */
/* 0088bb13  FUN_0088bb13  64 bytes, 0 callers */

void FUN_0088bb13(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  undefined4 in_stack_00000018;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x58);
  guard_check_icall(param_1,*param_2,param_2[1],param_2[2],param_2[3],*(undefined4 *)(in_ECX + 0x70)
                    ,*(undefined4 *)(in_ECX + 0x24),in_stack_00000018);
  (*pcVar1)();
  return;
}



