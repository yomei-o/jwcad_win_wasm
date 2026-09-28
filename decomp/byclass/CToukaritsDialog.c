/* CToukaritsDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CToukaritsDialog[1] */
/* 005f0630  FUN_005f0630  68 bytes, 0 callers */

undefined4 FUN_005f0630(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004dae50();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x388);
    }
  }
  return in_ECX;
}




/* vtable slots: CToukaritsDialog[64] */
/* 005f0680  DoDataExchange  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCWindowsManagerDialog::DoDataExchange(class CDataExchange
   *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCWindowsManagerDialog::DoDataExchange(CMFCWindowsManagerDialog *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x583,this + 0xa8);
  return;
}




/* vtable slots: CToukaritsDialog[10] */
/* 005f06c0  FUN_005f06c0  16 bytes, 0 callers */

void FUN_005f06c0(void)

{
  FUN_005f06d0();
  return;
}




/* vtable slots: CToukaritsDialog[94] */
/* 005f06e0  FUN_005f06e0  103 bytes, 0 callers */

undefined4 FUN_005f06e0(void)

{
  int in_ECX;
  
  FUN_00798993();
  (**(code **)(*(int *)(in_ECX + 0xa8) + 0x180))(in_ECX + 0x1f0,5);
  (**(code **)(*(int *)(in_ECX + 0xa8) + 0x188))((double)DAT_00a0f43c);
  return 1;
}




/* vtable slots: CToukaritsDialog[96] */
/* 005f0750  FUN_005f0750  227 bytes, 0 callers */

void FUN_005f0750(void)

{
  double dVar1;
  BOOL BVar2;
  int in_ECX;
  float10 fVar3;
  undefined4 local_c;
  
  local_c = 0xc0;
  BVar2 = IsWindow(*(HWND *)(in_ECX + 200));
  if (BVar2 != 0) {
    fVar3 = (float10)FUN_0058cc80();
    dVar1 = (double)fVar3;
    if (dVar1 != *(double *)(in_ECX + 0x380)) {
      *(double *)(in_ECX + 0x380) = dVar1;
      (**(code **)(*(int *)(in_ECX + 0xa8) + 0x188))(dVar1);
      (**(code **)(*(int *)(in_ECX + 0xa8) + 0x178))(in_ECX + 0x1f0);
    }
    local_c = (int)fVar3;
  }
  if (local_c < 0) {
    local_c = 0;
  }
  if (0xff < local_c) {
    local_c = 0xff;
  }
  DAT_00a0f43c = local_c;
  FUN_00798a09();
  return;
}



