/* std::_W::?$collate -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::_W::?$collate[0] */
/* 008e1192  FUN_008e1192  34 bytes, 0 callers */

void FUN_008e1192(byte param_1)

{
  ~collate<>();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::_W::?$collate[3] */
/* 008e84b7  do_compare  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall std::collate<wchar_t>::do_compare(wchar_t const *,wchar_t
   const *,wchar_t const *,wchar_t const *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __thiscall
std::collate<wchar_t>::do_compare
          (collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,
          wchar_t *param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = __Wcscoll(param_1,param_2,param_3,param_4,(_Collvec *)(this + 8));
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (uint)(iVar1 != 0);
  }
  return uVar2;
}




/* vtable slots: std::_W::?$collate[4] */
/* 008ec2ea  FUN_008ec2ea  136 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * FUN_008ec2ea(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  *param_1 = 0;
  param_1[4] = 0;
  param_1[5] = 7;
  *(undefined2 *)param_1 = 0;
  uVar1 = param_3 - param_2 >> 1;
  uVar3 = 0;
  if (uVar1 != 0) {
    uVar3 = uVar1;
    do {
      FID_conflict_resize(uVar3,0);
      puVar4 = param_1;
      if (7 < (uint)param_1[5]) {
        puVar4 = (undefined4 *)*param_1;
      }
      puVar2 = param_1;
      if (7 < (uint)param_1[5]) {
        puVar2 = (undefined4 *)*param_1;
      }
      uVar3 = FUN_008f031e(puVar2,(undefined2 *)((int)puVar4 + param_1[4] * 2),param_2,param_3,
                           in_ECX + 8);
    } while (((uint)param_1[4] < uVar3) && (uVar3 != 0));
  }
  FID_conflict_resize(uVar3,0);
  return param_1;
}



