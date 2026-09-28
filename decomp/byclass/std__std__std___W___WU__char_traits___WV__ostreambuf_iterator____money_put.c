/* std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$money_put -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$money_put[3] */
/* 008eb603  FUN_008eb603  303 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008eb603(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6,short *param_7)

{
  code *pcVar1;
  int *piVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 local_5c [12];
  undefined4 local_50;
  int local_4c;
  uint local_48;
  undefined1 local_44 [16];
  int local_34;
  undefined4 local_2c [5];
  short local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x8eb60f;
  local_50 = param_1;
  local_4c = param_5;
  FUN_00553da0(*(undefined4 *)(param_5 + 0x30));
  local_8 = 0;
  piVar2 = (int *)FUN_00552880(local_5c);
  local_8 = 0xffffffff;
  FUN_005546e0();
  pcVar1 = *(code **)(*piVar2 + 0x2c);
  guard_check_icall("0123456789-","0123456789-",local_2c);
  (*pcVar1)();
  uVar6 = 0;
  uVar5 = local_48 >> 8;
  local_48 = local_48 & 0xffffff00;
  if (*(int *)(param_7 + 8) != 0) {
    psVar3 = param_7;
    if (7 < *(uint *)(param_7 + 10)) {
      psVar3 = *(short **)param_7;
    }
    if (*psVar3 == local_18) {
      local_48 = CONCAT31((int3)uVar5,1);
      uVar6 = 1;
    }
  }
  uVar5 = uVar6;
  if (uVar6 < *(uint *)(param_7 + 8)) {
    do {
      psVar3 = param_7;
      if (7 < *(uint *)(param_7 + 10)) {
        psVar3 = *(short **)param_7;
      }
      uVar4 = _Find_elem<>(local_2c,psVar3[uVar5]);
    } while ((uVar4 < 10) && (uVar5 = uVar5 + 1, uVar5 < *(uint *)(param_7 + 8)));
  }
  if (7 < *(uint *)(param_7 + 10)) {
    param_7 = *(short **)param_7;
  }
  FUN_008e0db8(param_7 + uVar6,uVar5 - uVar6);
  local_8 = 1;
  if (local_34 == 0) {
    FID_conflict_push_back(local_2c[0]);
  }
  uVar7 = 0;
  FID_conflict__Construct_lv_contents(local_44);
  FUN_008e7aaf(local_50,param_2,param_3,param_4,local_4c,param_6,local_48,uVar7);
  FID_conflict__Tidy_deallocate();
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$money_put[4] */
/* 008eb732  FUN_008eb732  373 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008eb732(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,double param_7)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 ****ppppuVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  wchar_t *pwVar11;
  undefined4 uVar12;
  longlong lVar13;
  undefined4 ***local_54 [5];
  uint local_40;
  wchar_t local_3c [26];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x8eb73e;
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
  uVar9 = 0x8eb7b0;
  iVar3 = FID_conflict__swprintf(local_3c,(wchar_t *)0x28,"%.0Lf",param_7);
  if (iVar3 < 0) {
    *param_1 = param_2;
    param_1[1] = param_3;
  }
  else {
    FUN_00553da0();
    local_8 = 0;
    piVar4 = (int *)FUN_00552880();
    local_8 = 0xffffffff;
    FUN_005546e0();
    pcVar1 = *(code **)(*piVar4 + 0x30);
    guard_check_icall();
    uVar5 = (*pcVar1)();
    FUN_005531e0(iVar3,0);
    local_8 = 1;
    ppppuVar6 = local_54;
    if (7 < local_40) {
      ppppuVar6 = (undefined4 ****)local_54[0];
    }
    pwVar11 = local_3c;
    pcVar1 = *(code **)(*piVar4 + 0x2c);
    guard_check_icall(pwVar11,(int)pwVar11 + iVar3,ppppuVar6);
    uVar10 = 0x8eb854;
    (*pcVar1)();
    FID_conflict_append(uVar7,uVar5 & 0xffff);
    uVar8 = 0;
    uVar12 = 0;
    lVar13 = (ulonglong)(uVar5 & 0xffff) << 0x20;
    FID_conflict__Construct_lv_contents(local_54);
    FUN_008e7aaf(param_1,param_2,param_3,param_4,param_5,param_6,bVar2,uVar8,uVar9,uVar10,pwVar11,
                 uVar12,lVar13);
    FID_conflict__Tidy_deallocate();
  }
  FUN_008d9b68();
  return;
}



