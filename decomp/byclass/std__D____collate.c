/* std::D::?$collate -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::D::?$collate[0] */
/* 008ecebc  FUN_008ecebc  34 bytes, 0 callers */

void FUN_008ecebc(byte param_1)

{
  ~collate<>();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::D::?$collate[3] */
/* 008eec0b  do_compare  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall std::collate<char>::do_compare(char const *,char const *,char
   const *,char const *)const 
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __thiscall
std::collate<char>::do_compare
          (collate<char> *this,char *param_1,char *param_2,char *param_3,char *param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = __Strcoll(param_1,param_2,param_3,param_4,(_Collvec *)(this + 8));
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (uint)(iVar1 != 0);
  }
  return uVar2;
}




/* vtable slots: std::D::?$collate[5] */
/* 008ef862  do_hash  30 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual long __thiscall std::collate<char>::do_hash(char const *,char const *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

long __thiscall std::collate<char>::do_hash(collate<char> *this,char *param_1,char *param_2)

{
  uint uVar1;
  
  uVar1 = _Fnv1a_append_bytes(0x811c9dc5,(uchar *)param_1,(int)param_2 - (int)param_1);
  return uVar1;
}




/* vtable slots: std::D::?$collate[4] */
/* 008efc44  FUN_008efc44  134 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_008efc44(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,char *param_2,
            char *param_3)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *_String1;
  uint uVar2;
  int in_ECX;
  
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *param_1 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  uVar2 = 0;
  if ((int)param_3 - (int)param_2 != 0) {
    uVar2 = (int)param_3 - (int)param_2;
    do {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize
                (param_1,uVar2,'\0');
      pbVar1 = param_1;
      if (0xf < *(uint *)(param_1 + 0x14)) {
        pbVar1 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)param_1;
      }
      _String1 = param_1;
      if (0xf < *(uint *)(param_1 + 0x14)) {
        _String1 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)param_1;
      }
      uVar2 = __Strxfrm((char *)_String1,(char *)(pbVar1 + *(int *)(param_1 + 0x10)),param_2,param_3
                        ,(_Collvec *)(in_ECX + 8));
    } while ((*(uint *)(param_1 + 0x10) < uVar2) && (uVar2 != 0));
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize(param_1,uVar2,'\0');
  return param_1;
}



