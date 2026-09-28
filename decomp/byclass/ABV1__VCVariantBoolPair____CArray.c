/* ABV1::VCVariantBoolPair::?$CArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: ABV1::VCVariantBoolPair::?$CArray[1] */
/* 007a1cf9  FUN_007a1cf9  48 bytes, 0 callers */

void FUN_007a1cf9(byte param_1)

{
  FUN_007a1c7b();
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




/* vtable slots: ABV1::VCVariantBoolPair::?$CArray[2] */
/* 007a2fd1  Serialize  64 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CArray<int,int const &>::Serialize(class CArchive &)
    public: virtual void __thiscall CArray<int,int>::Serialize(class CArchive &)
    public: virtual void __thiscall CArray<unsigned int,unsigned int>::Serialize(class CArchive &)
    public: virtual void __thiscall CArray<long,long>::Serialize(class CArchive &)
     25 names - too many to list
   
   Library: Visual Studio 2015 Release */

void Serialize(CArchive *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    uVar1 = FUN_007a6ad2();
    FUN_007a3049(uVar1,0xffffffff);
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 8));
  }
  FUN_007a1bca(param_1,*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  return;
}



