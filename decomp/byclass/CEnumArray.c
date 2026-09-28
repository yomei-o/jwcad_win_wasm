/* CEnumArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CEnumArray[0], CEnumFormatEtc[0], CMFCTabDropTarget[0], CMFCToolBarDropSource[0], CMFCToolBarDropTarget[0], COleDataSource[0], COleDropSource[0], COleDropTarget[0], COleMessageFilter[0] */
/* 007900d2  FUN_007900d2  6 bytes, 0 callers */

undefined ** FUN_007900d2(void)

{
  return &PTR_s_CCmdTarget_0097c1f8;
}




/* vtable slots: CEnumArray[1] */
/* 007d06d5  FUN_007d06d5  48 bytes, 0 callers */

void FUN_007d06d5(byte param_1)

{
  FUN_007d0672();
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




/* vtable slots: CEnumArray[23], CEnumFormatEtc[23] */
/* 007d0838  OnClone  67 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual class CEnumArray * __thiscall CEnumArray::OnClone(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

CEnumArray * __thiscall CEnumArray::OnClone(CEnumArray *this)

{
  int iVar1;
  CEnumArray *pCVar2;
  
  iVar1 = FUN_0078e624(0x3c);
  pCVar2 = (CEnumArray *)0x0;
  if (iVar1 != 0) {
    pCVar2 = (CEnumArray *)
             FUN_007d062f(*(undefined4 *)(this + 0x20),*(undefined4 *)(this + 0x28),
                          *(undefined4 *)(this + 0x30),0);
  }
  *(undefined4 *)(pCVar2 + 0x2c) = *(undefined4 *)(this + 0x2c);
  return pCVar2;
}




/* vtable slots: CEnumArray[20] */
/* 007d087b  OnNext  56 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CEnumArray::OnNext(void *)
   
   Library: Visual Studio 2015 Release */

int __thiscall CEnumArray::OnNext(CEnumArray *this,void *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(this + 0x2c);
  uVar1 = *(uint *)(this + 0x30);
  if (uVar2 < uVar1) {
    FUN_0043add0(param_1,*(undefined4 *)(this + 0x20),
                 *(int *)(this + 0x20) * uVar2 + *(int *)(this + 0x28),*(undefined4 *)(this + 0x20))
    ;
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + 1;
  }
  return (uint)(uVar2 < uVar1);
}




/* vtable slots: CEnumArray[22], CEnumFormatEtc[22] */
/* 007d08b3  FUN_007d08b3  5 bytes, 0 callers */

void FUN_007d08b3(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  return;
}




/* vtable slots: CEnumArray[21], CEnumFormatEtc[21] */
/* 007d08b8  FUN_007d08b8  23 bytes, 0 callers */

bool FUN_007d08b8(void)

{
  uint uVar1;
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x30) <= *(uint *)(in_ECX + 0x2c)) {
    return false;
  }
  uVar1 = *(uint *)(in_ECX + 0x2c) + 1;
  *(uint *)(in_ECX + 0x2c) = uVar1;
  return uVar1 < *(uint *)(in_ECX + 0x30);
}



