/* CInvalidArgException -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CInvalidArgException[1], CMemoryException[1], CNotSupportedException[1], CResourceException[1], CUserException[1] */
/* 0078e6ae  FUN_0078e6ae  52 bytes, 0 callers */

void FUN_0078e6ae(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSimpleException::vftable;
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




/* vtable slots: CInvalidArgException[4], CMemoryException[4], CNotSupportedException[4], CResourceException[4], CSimpleException[4], CUserException[4] */
/* 0078e80a  GetErrorMessage  91 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CSimpleException::GetErrorMessage(wchar_t *,unsigned int,unsigned
   int *)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall
CSimpleException::GetErrorMessage
          (CSimpleException *this,wchar_t *param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == (wchar_t *)0x0) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    if (param_3 != (uint *)0x0) {
      *param_3 = 0;
    }
    if (*(int *)(this + 0xc) == 0) {
      InitString(this);
    }
    if (*(int *)(this + 0x10) == 0) {
      *param_1 = L'\0';
    }
    else {
      uVar1 = FUN_008f8e5e(param_1,param_2,this + 0x14,0xffffffff);
      FUN_00404bd0(uVar1);
    }
    iVar2 = *(int *)(this + 0x10);
  }
  return iVar2;
}




/* vtable slots: CInvalidArgException[0] */
/* 0078e865  FUN_0078e865  6 bytes, 0 callers */

undefined ** FUN_0078e865(void)

{
  return &PTR_s_CInvalidArgException_0097c034;
}



