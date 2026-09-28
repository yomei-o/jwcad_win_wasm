/* std::G::?$collate -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::G::?$collate[0] */
/* 008e1170  FUN_008e1170  34 bytes, 0 callers */

void FUN_008e1170(byte param_1)

{
  ~collate<>();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::G::?$collate[3] */
/* 008e8486  do_compare  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall std::collate<unsigned short>::do_compare(unsigned short const
   *,unsigned short const *,unsigned short const *,unsigned short const *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __thiscall
std::collate<unsigned_short>::do_compare
          (collate<unsigned_short> *this,ushort *param_1,ushort *param_2,ushort *param_3,
          ushort *param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _LStrcoll<unsigned_short>(param_1,param_2,param_3,param_4,(_Collvec *)(this + 8));
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (uint)(iVar1 != 0);
  }
  return uVar2;
}




/* vtable slots: std::G::?$collate[5], std::_W::?$collate[5] */
/* 008eb0a9  do_hash  33 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual long __thiscall std::collate<unsigned short>::do_hash(unsigned short const
   *,unsigned short const *)const 
    protected: virtual long __thiscall std::collate<wchar_t>::do_hash(wchar_t const *,wchar_t const
   *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void do_hash(uchar *param_1,int param_2)

{
  std::_Fnv1a_append_bytes(0x811c9dc5,param_1,param_2 - (int)param_1 & 0xfffffffe);
  return;
}




/* vtable slots: std::G::?$collate[4] */
/* 008ec262  FUN_008ec262  136 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ushort * FUN_008ec262(ushort *param_1,ushort *param_2,ushort *param_3)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  int in_ECX;
  ushort *puVar4;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 7;
  param_1[0xb] = 0;
  *param_1 = 0;
  uVar1 = (int)param_3 - (int)param_2 >> 1;
  uVar3 = 0;
  if (uVar1 != 0) {
    uVar3 = uVar1;
    do {
      FID_conflict_resize(uVar3,0);
      puVar4 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        puVar4 = *(ushort **)param_1;
      }
      puVar2 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        puVar2 = *(ushort **)param_1;
      }
      uVar3 = std::_LStrxfrm<unsigned_short>
                        (puVar2,puVar4 + *(int *)(param_1 + 8),param_2,param_3,
                         (_Collvec *)(in_ECX + 8));
    } while ((*(uint *)(param_1 + 8) < uVar3) && (uVar3 != 0));
  }
  FID_conflict_resize(uVar3,0);
  return param_1;
}



