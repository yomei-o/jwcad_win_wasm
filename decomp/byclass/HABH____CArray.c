/* HABH::?$CArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: HABH::?$CArray[1] */
/* 007be771  FUN_007be771  48 bytes, 0 callers */

void FUN_007be771(byte param_1)

{
  ~CArray<>();
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




/* vtable slots: HABH::?$CArray[2] */
/* 007bee19  Serialize  64 bytes, 0 callers */

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
    FUN_0079ca8b(uVar1,0xffffffff);
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 8));
  }
  FUN_0041edc0(param_1,*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  return;
}



