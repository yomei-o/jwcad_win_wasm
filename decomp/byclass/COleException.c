/* COleException -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleException[1] */
/* 0078e93d  `scalar_deleting_destructor'  49 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall COleException::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall COleException::_scalar_deleting_destructor_(COleException *this,uint param_1)

{
  *(undefined ***)this = vftable;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xc);
    }
  }
  return this;
}




/* vtable slots: COleException[4] */
/* 0078ed41  FUN_0078ed41  98 bytes, 0 callers */

bool FUN_0078ed41(undefined2 *param_1,undefined4 param_2,undefined4 *param_3)

{
  DWORD DVar1;
  undefined4 uVar2;
  HLOCAL in_ECX;
  HLOCAL local_8;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  local_8 = in_ECX;
  DVar1 = FormatMessageW(0x1100,(LPCVOID)0x0,*(DWORD *)((int)in_ECX + 8),0x800,(LPWSTR)&local_8,0,
                         (va_list *)0x0);
  if (DVar1 != 0) {
    uVar2 = FUN_008f8e5e(param_1,param_2,local_8,0xffffffff);
    FUN_00404bd0(uVar2);
    LocalFree(local_8);
  }
  else {
    *param_1 = 0;
  }
  return DVar1 != 0;
}




/* vtable slots: COleException[0] */
/* 0078eda3  FUN_0078eda3  6 bytes, 0 callers */

undefined ** FUN_0078eda3(void)

{
  return &PTR_s_COleException_0097c0dc;
}



