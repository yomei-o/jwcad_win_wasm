/* std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$money_get -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$money_get[4] */
/* 008eec5e  FUN_008eec5e  168 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008eec5e(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,uint *param_8,
                 double *param_9)

{
  uint *puVar1;
  double *pdVar2;
  bool bVar3;
  undefined4 ***pppuVar4;
  float10 fVar5;
  undefined4 **local_40;
  int local_3c;
  undefined4 **local_38 [4];
  int local_28;
  uint local_24;
  undefined1 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pdVar2 = param_9;
  puVar1 = param_8;
  uStack_4 = 0x34;
  local_8 = 0x8eec6a;
  FUN_008ed63a(local_38,&param_2,&param_4,param_6,param_7,local_20);
  local_8 = 0;
  bVar3 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (bVar3) {
    *puVar1 = *puVar1 | 1;
  }
  if (local_28 != 0) {
    pppuVar4 = local_38;
    if (0xf < local_24) {
      pppuVar4 = (undefined4 ***)local_38[0];
    }
    local_3c = 0;
    fVar5 = (float10)FUN_008dd60c(pppuVar4,&local_40,0,&local_3c);
    if (((undefined4 ***)local_40 != pppuVar4) && (local_3c == 0)) {
      *pdVar2 = (double)fVar5;
      goto LAB_008eece9;
    }
  }
  *puVar1 = *puVar1 | 2;
LAB_008eece9:
  *param_1 = param_2;
  param_1[1] = param_3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_38);
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$money_get[3] */
/* 008eed06  FUN_008eed06  210 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008eed06(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,uint *param_8,
                 basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_9)

{
  uint *puVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  uint uVar2;
  bool bVar3;
  char ****ppppcVar4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar5;
  uint uVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_50 [16];
  undefined4 *local_40;
  uint local_3c;
  char ***local_38 [4];
  uint local_28;
  uint local_24;
  undefined1 local_20 [10];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_16;
  undefined4 local_8;
  undefined4 uStack_4;
  
  this = param_9;
  puVar1 = param_8;
  uStack_4 = 0x30;
  local_8 = 0x8eed12;
  local_40 = param_1;
  FUN_008ed63a(local_38,&param_2,&param_4,param_6,param_7,local_20);
  local_3c = local_28;
  uVar6 = 0;
  local_8 = 0;
  bVar3 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  uVar2 = local_3c;
  if (bVar3) {
    *puVar1 = *puVar1 | 1;
  }
  if (local_3c == 0) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize(this,local_3c,'\0')
    ;
    ppppcVar4 = local_38;
    if (0xf < local_24) {
      ppppcVar4 = (char ****)local_38[0];
    }
    if (*(char *)ppppcVar4 == '-') {
      pbVar5 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar5 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      *pbVar5 = local_16;
      uVar6 = 1;
    }
    for (; uVar6 < uVar2; uVar6 = uVar6 + 1) {
      ppppcVar4 = local_38;
      if (0xf < local_24) {
        ppppcVar4 = (char ****)local_38[0];
      }
      pbVar5 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar5 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      pbVar5[uVar6] = abStack_50[*(char *)((int)ppppcVar4 + uVar6)];
    }
  }
  *local_40 = param_2;
  local_40[1] = param_3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_38);
  FUN_008d9b68();
  return;
}



