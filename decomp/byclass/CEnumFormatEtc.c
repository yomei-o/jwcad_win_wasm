/* CEnumFormatEtc -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CEnumFormatEtc[1] */
/* 007b9d51  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CEnumFormatEtc::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CEnumFormatEtc::_scalar_deleting_destructor_(CEnumFormatEtc *this,uint param_1)

{
  ~CEnumFormatEtc(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x40);
    }
  }
  return this;
}




/* vtable slots: CEnumFormatEtc[14] */
/* 007ba2b3  FUN_007ba2b3  6 bytes, 0 callers */

undefined ** FUN_007ba2b3(void)

{
  return &PTR_DAT_00981998;
}




/* vtable slots: CEnumFormatEtc[20] */
/* 007ba39d  FUN_007ba39d  51 bytes, 0 callers */

undefined4 FUN_007ba39d(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  CEnumArray *in_ECX;
  
  iVar1 = CEnumArray::OnNext(in_ECX,param_1);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (*(int *)((int)param_1 + 4) != 0) {
      iVar1 = FUN_0078f1ce(*(undefined4 *)((int)param_1 + 4));
      *(int *)((int)param_1 + 4) = iVar1;
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e73e();
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}



