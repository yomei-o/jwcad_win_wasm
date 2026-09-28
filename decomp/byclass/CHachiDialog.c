/* CHachiDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CHachiDialog[1] */
/* 004c7b70  FUN_004c7b70  68 bytes, 0 callers */

undefined4 FUN_004c7b70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004c7af0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x6b0);
    }
  }
  return in_ECX;
}




/* vtable slots: CHachiDialog[24] */
/* 004c7fd0  FUN_004c7fd0  51 bytes, 0 callers */

void FUN_004c7fd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_004c8100();
    DAT_00a0bf0c = *(undefined4 *)(in_ECX + 0x6a8);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CHachiDialog[64] */
/* 004c8010  DoDataExchange  238 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual void __thiscall CMFCRibbonCustomizePropertyPage::DoDataExchange(class
   CDataExchange *)
    protected: virtual void __thiscall CMFCToolBarButtonCustomizeDialog::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void DoDataExchange(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x47c,in_ECX + 0xc0);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x288);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x140);
  FUN_0078fb9c(param_1,0x58b,in_ECX + 0x3d0);
  FUN_0078fb9c(param_1,0x6d9,in_ECX + 0x5a8);
  FUN_0078fb9c(param_1,0x6da,in_ECX + 0x628);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x528);
  FUN_0078f75d(param_1,0x699,in_ECX + 0x6a8);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x6ac);
  return;
}




/* vtable slots: CHachiDialog[10] */
/* 004c8130  FUN_004c8130  16 bytes, 0 callers */

void FUN_004c8130(void)

{
  FUN_004c8140();
  return;
}




/* vtable slots: CHachiDialog[94] */
/* 004c81e0  FUN_004c81e0  325 bytes, 0 callers */

undefined4 FUN_004c81e0(void)

{
  int in_ECX;
  
  FUN_00798993();
  if ((DAT_00a0bf0c < 0) || (4 < DAT_00a0bf0c)) {
    *(undefined4 *)(in_ECX + 0x6a8) = 0;
  }
  else {
    *(int *)(in_ECX + 0x6a8) = DAT_00a0bf0c;
  }
  FUN_004c7bc0();
  if ((-1 < *(int *)(in_ECX + 0x6a8)) && (*(int *)(in_ECX + 0x6a8) < 5)) {
    FUN_004c8580(*(undefined8 *)(&DAT_00a0bf50 + *(int *)(in_ECX + 0x6a8) * 8));
    FUN_004c8500(*(undefined8 *)(&DAT_00a0bf78 + *(int *)(in_ECX + 0x6a8) * 8));
    FUN_004c8480(*(undefined8 *)(&DAT_00a0bf28 + *(int *)(in_ECX + 0x6a8) * 8));
    *(undefined4 *)(in_ECX + 0x6ac) = *(undefined4 *)(&DAT_00a0bf10 + *(int *)(in_ECX + 0x6a8) * 4);
  }
  if (*(int *)(in_ECX + 0x6ac) == 0) {
    *(undefined4 *)(in_ECX + 0x3c8) = 1;
    *(undefined4 *)(in_ECX + 0x280) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x3c8) = 0;
    *(undefined4 *)(in_ECX + 0x280) = 0;
  }
  FUN_0058c740();
  FUN_007955d2();
  return 1;
}



