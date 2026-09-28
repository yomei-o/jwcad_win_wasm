/* std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$money_put -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$money_put[3] */
/* 008ef895  FUN_008ef895  301 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ef895(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6,char *param_7)

{
  code *pcVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 local_50 [12];
  undefined4 local_44;
  int local_40;
  uint local_3c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_38 [16];
  int local_28;
  char local_20 [10];
  char local_16;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x8ef8a1;
  local_44 = param_1;
  local_40 = param_5;
  FUN_00553da0(*(undefined4 *)(param_5 + 0x30));
  local_8 = 0;
  piVar2 = (int *)FUN_008db390(local_50);
  local_8 = 0xffffffff;
  FUN_005546e0();
  pcVar1 = *(code **)(*piVar2 + 0x1c);
  guard_check_icall("0123456789-","0123456789-",local_20);
  (*pcVar1)();
  uVar6 = 0;
  uVar5 = local_3c >> 8;
  local_3c = local_3c & 0xffffff00;
  if (*(int *)(param_7 + 0x10) != 0) {
    pcVar3 = param_7;
    if (0xf < *(uint *)(param_7 + 0x14)) {
      pcVar3 = *(char **)param_7;
    }
    if (*pcVar3 == local_16) {
      local_3c = CONCAT31((int3)uVar5,1);
      uVar6 = 1;
    }
  }
  uVar5 = uVar6;
  if (uVar6 < *(uint *)(param_7 + 0x10)) {
    do {
      pcVar3 = param_7;
      if (0xf < *(uint *)(param_7 + 0x14)) {
        pcVar3 = *(char **)param_7;
      }
      uVar4 = std::_Find_elem<char,12>(local_20,pcVar3[uVar5]);
    } while ((uVar4 < 10) && (uVar5 = uVar5 + 1, uVar5 < *(uint *)(param_7 + 0x10)));
  }
  if (0xf < *(uint *)(param_7 + 0x14)) {
    param_7 = *(char **)param_7;
  }
  FUN_00553080(param_7 + uVar6,uVar5 - uVar6);
  local_8 = 1;
  if (local_28 == 0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::push_back
              (local_38,local_20[0]);
  }
  uVar7 = 0;
  FUN_00557e70(local_38);
  FUN_008ee5c9(local_44,param_2,param_3,param_4,local_40,param_6,local_3c,uVar7);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate(local_38);
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$money_put[4] */
/* 008ef9c2  FUN_008ef9c2  371 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ef9c2(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,double param_7)

{
  code *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 ****ppppuVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  wchar_t *pwVar11;
  undefined4 uVar12;
  longlong lVar13;
  uint local_5c;
  undefined4 ***local_54 [5];
  uint local_40;
  wchar_t local_3c [26];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x8ef9ce;
  bVar2 = param_7 < 0.0;
  if (bVar2) {
    param_7 = -param_7;
  }
  uVar7 = 0;
  if (!NAN(param_7) && 1e+35 < param_7 != (param_7 == 1e+35)) {
    do {
      if (4999 < uVar7) break;
      param_7 = param_7 / 10000000000.0;
      uVar7 = uVar7 + 10;
    } while (1e+35 < param_7 != (param_7 == 1e+35));
  }
  uVar9 = 0x8efa40;
  iVar4 = FID_conflict__swprintf(local_3c,(wchar_t *)0x28,"%.0Lf",param_7);
  if (iVar4 < 0) {
    *param_1 = param_2;
    param_1[1] = param_3;
  }
  else {
    FUN_00553da0();
    local_8 = 0;
    piVar5 = (int *)FUN_008db390();
    local_8 = 0xffffffff;
    FUN_005546e0();
    pcVar1 = *(code **)(*piVar5 + 0x20);
    guard_check_icall();
    uVar3 = (*pcVar1)();
    local_5c = CONCAT31(local_5c._1_3_,uVar3);
    FUN_004d33c0(iVar4,0);
    local_8 = 1;
    ppppuVar6 = local_54;
    if (0xf < local_40) {
      ppppuVar6 = (undefined4 ****)local_54[0];
    }
    pwVar11 = local_3c;
    pcVar1 = *(code **)(*piVar5 + 0x1c);
    guard_check_icall(pwVar11,(int)pwVar11 + iVar4,ppppuVar6);
    uVar10 = 0x8efae1;
    (*pcVar1)();
    FUN_00559dc0(uVar7,local_5c);
    uVar8 = 0;
    uVar12 = 0;
    lVar13 = (ulonglong)local_5c << 0x20;
    FUN_00557e70(local_54);
    FUN_008ee5c9(param_1,param_2,param_3,param_4,param_5,param_6,bVar2,uVar8,uVar9,uVar10,pwVar11,
                 uVar12,lVar13);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_54);
  }
  FUN_008d9b68();
  return;
}



