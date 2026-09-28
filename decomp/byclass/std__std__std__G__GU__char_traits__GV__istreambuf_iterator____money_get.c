/* std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$money_get -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$money_get[4] */
/* 008e8569  FUN_008e8569  168 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e8569(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,uint *param_8,
                 double *param_9)

{
  uint *puVar1;
  double *pdVar2;
  char cVar3;
  undefined4 ***pppuVar4;
  float10 fVar5;
  undefined4 **local_4c;
  int local_48;
  undefined4 **local_44 [4];
  int local_34;
  uint local_30;
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pdVar2 = param_9;
  puVar1 = param_8;
  uStack_4 = 0x40;
  local_8 = 0x8e8575;
  FUN_008e4b7b(local_44,&param_2,&param_4,param_6,param_7,local_2c);
  local_8 = 0;
  cVar3 = equal(&param_4);
  if (cVar3 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  if (local_34 != 0) {
    pppuVar4 = local_44;
    if (0xf < local_30) {
      pppuVar4 = (undefined4 ***)local_44[0];
    }
    local_48 = 0;
    fVar5 = (float10)FUN_008dd60c(pppuVar4,&local_4c,0,&local_48);
    if (((undefined4 ***)local_4c != pppuVar4) && (local_48 == 0)) {
      *pdVar2 = (double)fVar5;
      goto LAB_008e85f4;
    }
  }
  *puVar1 = *puVar1 | 2;
LAB_008e85f4:
  *param_1 = param_2;
  param_1[1] = param_3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_44);
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$money_get[3] */
/* 008e8611  FUN_008e8611  218 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e8611(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,uint *param_8,
                 undefined4 *param_9)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  char ****ppppcVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined2 auStack_8c [10];
  undefined4 uStack_78;
  char ***pppcStack_74;
  undefined4 *puStack_70;
  undefined1 *puStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 *puStack_60;
  undefined4 *local_4c;
  uint local_48;
  char ***local_44 [4];
  uint local_34;
  uint local_30;
  undefined1 local_2c [20];
  undefined2 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar2 = param_9;
  puVar1 = param_8;
  uStack_4 = 0x3c;
  local_8 = 0x8e861d;
  puStack_60 = local_2c;
  local_4c = param_1;
  uStack_64 = param_7;
  uStack_68 = param_6;
  puStack_6c = (undefined1 *)&param_4;
  puStack_70 = &param_2;
  pppcStack_74 = (char ***)local_44;
  uStack_78 = 0x8e8645;
  FUN_008e4b7b();
  local_48 = local_34;
  uVar7 = 0;
  puStack_60 = (undefined1 *)&param_4;
  local_8 = 0;
  uStack_64 = 0x8e865c;
  cVar4 = equal();
  uVar3 = local_48;
  if (cVar4 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  if (local_48 == 0) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    puStack_60 = (undefined1 *)0x0;
    uStack_64 = local_48;
    uStack_68 = 0x8e8679;
    FID_conflict_resize();
    ppppcVar5 = local_44;
    if (0xf < local_30) {
      ppppcVar5 = (char ****)local_44[0];
    }
    if (*(char *)ppppcVar5 == '-') {
      puVar6 = puVar2;
      if (7 < (uint)puVar2[5]) {
        puVar6 = (undefined4 *)*puVar2;
      }
      *(undefined2 *)puVar6 = local_18;
      uVar7 = 1;
    }
    for (; uVar7 < uVar3; uVar7 = uVar7 + 1) {
      ppppcVar5 = local_44;
      if (0xf < local_30) {
        ppppcVar5 = (char ****)local_44[0];
      }
      puVar6 = puVar2;
      if (7 < (uint)puVar2[5]) {
        puVar6 = (undefined4 *)*puVar2;
      }
      *(undefined2 *)((int)puVar6 + uVar7 * 2) = auStack_8c[*(char *)((int)ppppcVar5 + uVar7)];
    }
  }
  *local_4c = param_2;
  local_4c[1] = param_3;
  puStack_60 = (undefined1 *)0x8e86e1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_44);
  puStack_60 = (undefined1 *)0x8e86e8;
  FUN_008d9b68();
  return;
}



