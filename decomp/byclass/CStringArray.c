/* CStringArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CStringArray[1] */
/* 007bf5dd  FUN_007bf5dd  48 bytes, 0 callers */

void FUN_007bf5dd(byte param_1)

{
  FUN_007bf4be();
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




/* vtable slots: CStringArray[0] */
/* 007bf63c  FUN_007bf63c  6 bytes, 0 callers */

undefined ** FUN_007bf63c(void)

{
  return &PTR_s_CStringArray_00a0047c;
}




/* vtable slots: CStringArray[2] */
/* 007bf6b8  Serialize  108 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CStringArray::Serialize(class CArchive &)
   
   Library: Visual Studio 2015 Release */

void __thiscall CStringArray::Serialize(CStringArray *this,CArchive *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    uVar1 = FUN_007a6ad2();
    FUN_007bf7c0(uVar1,0xffffffff);
    iVar2 = 0;
    if (0 < *(int *)(this + 8)) {
      do {
        FUN_0047fc90(*(int *)(this + 4) + iVar2 * 4);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(this + 8));
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(this + 8));
    iVar2 = 0;
    if (0 < *(int *)(this + 8)) {
      do {
        CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                  (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                           (*(int *)(this + 4) + iVar2 * 4));
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(this + 8));
    }
  }
  return;
}



