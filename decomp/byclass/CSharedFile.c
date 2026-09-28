/* CSharedFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSharedFile[1] */
/* 007ba7d4  FUN_007ba7d4  48 bytes, 0 callers */

void FUN_007ba7d4(byte param_1)

{
  FUN_007ba784();
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




/* vtable slots: CSharedFile[22] */
/* 007ba804  Alloc  37 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual unsigned char * __thiscall CSharedFile::Alloc(unsigned long)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

uchar * __thiscall CSharedFile::Alloc(CSharedFile *this,ulong param_1)

{
  HGLOBAL hMem;
  uchar *puVar1;
  
  hMem = GlobalAlloc(*(UINT *)(this + 0x2c),param_1);
  *(HGLOBAL *)(this + 0x30) = hMem;
  puVar1 = (uchar *)0x0;
  if (hMem != (HGLOBAL)0x0) {
    puVar1 = GlobalLock(hMem);
  }
  return puVar1;
}




/* vtable slots: CSharedFile[25] */
/* 007ba847  FUN_007ba847  25 bytes, 0 callers */

void FUN_007ba847(void)

{
  int in_ECX;
  
  GlobalUnlock(*(HGLOBAL *)(in_ECX + 0x30));
  GlobalFree(*(HGLOBAL *)(in_ECX + 0x30));
  return;
}




/* vtable slots: CSharedFile[0] */
/* 007ba860  FUN_007ba860  6 bytes, 0 callers */

undefined ** FUN_007ba860(void)

{
  return &PTR_s_CSharedFile_00981a04;
}




/* vtable slots: CSharedFile[23] */
/* 007ba866  FUN_007ba866  59 bytes, 0 callers */

LPVOID FUN_007ba866(undefined4 param_1,SIZE_T param_2)

{
  HGLOBAL hMem;
  LPVOID pvVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) != 0) {
    GlobalUnlock(*(HGLOBAL *)(in_ECX + 0x30));
    hMem = GlobalReAlloc(*(HGLOBAL *)(in_ECX + 0x30),param_2,*(UINT *)(in_ECX + 0x2c));
    if (hMem != (HGLOBAL)0x0) {
      *(HGLOBAL *)(in_ECX + 0x30) = hMem;
      pvVar1 = GlobalLock(hMem);
      return pvVar1;
    }
  }
  return (LPVOID)0x0;
}



