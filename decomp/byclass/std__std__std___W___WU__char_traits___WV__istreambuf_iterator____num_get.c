/* std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[12] */
/* 008e91e4  FUN_008e91e4  238 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e91e4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,short *param_8)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  char *local_48 [2];
  int local_40;
  short *local_3c;
  char local_35;
  char local_34;
  char local_33 [43];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_7;
  uStack_4 = 0x3c;
  local_8 = 0x8e91f0;
  local_3c = param_8;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  uVar3 = FUN_008e4581();
  local_8 = 0xffffffff;
  FUN_005546e0();
  if (local_34 == '\0') {
    *puVar1 = 2;
    *local_3c = 0;
  }
  else {
    local_35 = local_34 == '-';
    pcVar5 = &local_34;
    if ((bool)local_35) {
      pcVar5 = local_33;
    }
    uVar4 = __Stoulx(pcVar5,local_48,uVar3,&local_40);
    *local_3c = (short)uVar4;
    if (((local_48[0] == pcVar5) || (local_40 != 0)) || (0xffff < uVar4)) {
      *puVar1 = 2;
      *local_3c = -1;
    }
    else if (local_35 != '\0') {
      *local_3c = -(short)uVar4;
    }
  }
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[11] */
/* 008e92d2  FUN_008e92d2  64 bytes, 0 callers */

void FUN_008e92d2(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 local_10 [8];
  undefined4 local_8;
  
  puVar3 = (undefined4 *)
           FUN_008e93d6(local_10,param_2,param_3,param_4,param_5,param_6,param_7,&local_8);
  uVar1 = puVar3[1];
  uVar2 = *puVar3;
  *param_8 = local_8;
  param_1[1] = uVar1;
  *param_1 = uVar2;
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[10] */
/* 008e9312  FUN_008e9312  196 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e9312(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,undefined4 *param_8)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  char *local_44 [2];
  int local_3c;
  undefined4 *local_38;
  char local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_7;
  uStack_4 = 0x38;
  local_8 = 0x8e931e;
  local_38 = param_8;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  uVar3 = FUN_008e4581();
  local_8 = 0xffffffff;
  FUN_005546e0();
  if (local_34[0] == '\0') {
    *puVar1 = 2;
    *local_38 = 0;
  }
  else {
    uVar3 = __Stolx(local_34,local_44,uVar3,&local_3c);
    *local_38 = uVar3;
    if ((local_44[0] == local_34) || (local_3c != 0)) {
      *puVar1 = 2;
    }
  }
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[9] */
/* 008e93d6  FUN_008e93d6  196 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e93d6(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,undefined4 *param_8)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  char *local_44 [2];
  int local_3c;
  undefined4 *local_38;
  char local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_7;
  uStack_4 = 0x38;
  local_8 = 0x8e93e2;
  local_38 = param_8;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  uVar3 = FUN_008e4581();
  local_8 = 0xffffffff;
  FUN_005546e0();
  if (local_34[0] == '\0') {
    *puVar1 = 2;
    *local_38 = 0;
  }
  else {
    uVar3 = __Stoulx(local_34,local_44,uVar3,&local_3c);
    *local_38 = uVar3;
    if ((local_44[0] == local_34) || (local_3c != 0)) {
      *puVar1 = 2;
    }
  }
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[6] */
/* 008e949a  FUN_008e949a  251 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
FUN_008e949a(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,uint *param_7,float *param_8)

{
  uint *puVar1;
  float *pfVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  int local_330;
  char *local_32c;
  float local_328;
  int local_324;
  char local_320 [792];
  uint local_8;
  
  pfVar2 = param_8;
  puVar1 = param_7;
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_324 = 1000000000;
  iVar4 = FUN_008e2912();
  if (local_320[0] == '\0') {
LAB_008e9558:
    fVar5 = (float10)0;
    *puVar1 = 2;
  }
  else {
    local_328 = std::_Stofx_v2(local_320,&local_32c,iVar4,&local_330);
    *pfVar2 = local_328;
    if ((local_32c == local_320) || (local_330 != 0)) goto LAB_008e9558;
    if ((local_324 == 1000000000) || (local_324 == 0)) goto LAB_008e9564;
    fVar5 = (float10)FUN_008dea38(local_328,local_324 << 2);
  }
  *pfVar2 = (float)fVar5;
LAB_008e9564:
  cVar3 = equal(&param_4);
  if (cVar3 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[5] */
/* 008e9595  FUN_008e9595  241 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
FUN_008e9595(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,uint *param_7,double *param_8)

{
  uint *puVar1;
  double *pdVar2;
  char cVar3;
  undefined4 uVar4;
  float10 fVar5;
  int local_32c;
  char *local_328;
  int local_324;
  char local_320 [792];
  uint local_8;
  
  pdVar2 = param_8;
  puVar1 = param_7;
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_324 = 1000000000;
  uVar4 = FUN_008e2912();
  if (local_320[0] == '\0') {
LAB_008e9649:
    fVar5 = (float10)0;
    *puVar1 = 2;
  }
  else {
    fVar5 = (float10)FUN_008dd60c(local_320,&local_328,uVar4,&local_32c);
    *pdVar2 = (double)fVar5;
    if ((local_328 == local_320) || (local_32c != 0)) goto LAB_008e9649;
    if ((local_324 == 1000000000) || (local_324 == 0)) goto LAB_008e9655;
    fVar5 = (float10)FUN_0090e7f8((double)fVar5,local_324 << 2);
  }
  *pdVar2 = (double)fVar5;
LAB_008e9655:
  cVar3 = equal(&param_4);
  if (cVar3 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[4] */
/* 008e9686  FUN_008e9686  62 bytes, 0 callers */

void FUN_008e9686(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined8 *param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 local_14 [8];
  undefined8 local_c;
  
  puVar3 = (undefined4 *)
           FUN_008e9595(local_14,param_2,param_3,param_4,param_5,param_6,param_7,&local_c);
  uVar1 = *puVar3;
  uVar2 = puVar3[1];
  *param_8 = local_c;
  *param_1 = uVar1;
  param_1[1] = uVar2;
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[3] */
/* 008e96c4  FUN_008e96c4  188 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e96c4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,undefined4 *param_8)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  char *local_44 [2];
  int local_3c;
  undefined4 *local_38;
  char local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_7;
  uStack_4 = 0x34;
  local_8 = 0x8e96d0;
  local_38 = param_8;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  uVar3 = FUN_008e4581();
  local_8 = 0xffffffff;
  FUN_005546e0();
  if (local_34[0] != '\0') {
    uVar3 = __Stoulx(local_34,local_44,uVar3,&local_3c);
    *local_38 = uVar3;
    if ((local_44[0] != local_34) && (local_3c == 0)) goto LAB_008e9758;
  }
  *puVar1 = 2;
  *local_38 = 0;
LAB_008e9758:
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[8] */
/* 008e9780  FUN_008e9780  203 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e9780(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,undefined8 *param_8)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  char *local_44 [2];
  int local_3c;
  undefined8 *local_38;
  char local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_7;
  uStack_4 = 0x38;
  local_8 = 0x8e978c;
  local_38 = param_8;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  uVar3 = FUN_008e4581();
  local_8 = 0xffffffff;
  FUN_005546e0();
  if (local_34[0] == '\0') {
    *puVar1 = 2;
    *(undefined4 *)local_38 = 0;
    *(undefined4 *)((int)local_38 + 4) = 0;
  }
  else {
    uVar4 = __Stollx(local_34,local_44,uVar3,&local_3c);
    *local_38 = uVar4;
    if ((local_44[0] == local_34) || (local_3c != 0)) {
      *puVar1 = 2;
    }
  }
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[7] */
/* 008e984b  FUN_008e984b  203 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e984b(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,undefined8 *param_8)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  char *local_44 [2];
  int local_3c;
  undefined8 *local_38;
  char local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_7;
  uStack_4 = 0x38;
  local_8 = 0x8e9857;
  local_38 = param_8;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  uVar3 = FUN_008e4581();
  local_8 = 0xffffffff;
  FUN_005546e0();
  if (local_34[0] == '\0') {
    *puVar1 = 2;
    *(undefined4 *)local_38 = 0;
    *(undefined4 *)((int)local_38 + 4) = 0;
  }
  else {
    uVar4 = __Stoullx(local_34,local_44,uVar3,&local_3c);
    *local_38 = uVar4;
    if ((local_44[0] == local_34) || (local_3c != 0)) {
      *puVar1 = 2;
    }
  }
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[13] */
/* 008e9916  FUN_008e9916  581 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008e9916(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 ****param_6,uint *param_7,undefined1 *param_8)

{
  code *pcVar1;
  uint *puVar2;
  undefined1 *puVar3;
  char cVar4;
  int *piVar5;
  undefined4 ****ppppuVar6;
  int iVar7;
  undefined1 local_78 [8];
  char *local_70;
  undefined4 ***local_6c;
  int *local_68;
  undefined4 ***local_64 [4];
  undefined4 local_54;
  uint local_50;
  undefined4 ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  char local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar3 = param_8;
  puVar2 = param_7;
  uStack_4 = 0x68;
  local_8 = 0x8e9922;
  local_70 = param_1;
  local_6c = param_6;
  if (((uint)param_6[5] & 0x4000) == 0) {
    FUN_00553da0(param_6[0xc]);
    local_8 = 5;
    local_70 = (char *)FUN_008e4581(local_68,local_34,&param_2,&param_4,local_6c[5],local_78);
    local_8 = 0xffffffff;
    FUN_005546e0();
    if (local_34[0] == '\0') {
      *puVar3 = 0;
    }
    else {
      iVar7 = __Stolx(local_34,&local_70,local_70,&local_6c);
      if ((local_70 == local_34) || ((undefined4 ****)local_6c != (undefined4 ****)0x0)) {
        *puVar3 = 1;
      }
      else {
        *puVar3 = iVar7 != 0;
        if ((iVar7 == 0) || (iVar7 == 1)) goto LAB_008e9aa0;
      }
    }
    *puVar2 = 2;
  }
  else {
    FUN_00553da0(param_6[0xc]);
    local_8 = 0;
    piVar5 = (int *)FUN_00552aa0(local_78);
    local_68 = piVar5;
    FUN_005546e0();
    local_8 = 0xffffffff;
    local_3c = 0;
    local_38 = 7;
    local_4c[0] = (undefined4 ****)0x0;
    FUN_0055a050(1,0);
    local_8 = 2;
    pcVar1 = *(code **)(*piVar5 + 0x18);
    guard_check_icall(local_64);
    (*pcVar1)();
    local_8._0_1_ = 3;
    ppppuVar6 = local_64;
    if (7 < local_50) {
      ppppuVar6 = (undefined4 ****)local_64[0];
    }
    FUN_008e836c(ppppuVar6,local_54);
    local_8._0_1_ = 2;
    FID_conflict__Tidy_deallocate();
    FID_conflict_push_back(0);
    pcVar1 = *(code **)(*local_68 + 0x1c);
    guard_check_icall(local_64);
    (*pcVar1)();
    local_8._0_1_ = 4;
    ppppuVar6 = local_64;
    if (7 < local_50) {
      ppppuVar6 = (undefined4 ****)local_64[0];
    }
    FUN_008e836c(ppppuVar6,local_54);
    local_8 = CONCAT31(local_8._1_3_,2);
    FID_conflict__Tidy_deallocate();
    ppppuVar6 = local_4c;
    if (7 < local_38) {
      ppppuVar6 = (undefined4 ****)local_4c[0];
    }
    iVar7 = FUN_008df4bd(&param_2,&param_4,2,ppppuVar6,1);
    if (iVar7 == 0) {
      *puVar3 = 0;
    }
    else if (iVar7 == 1) {
      *puVar3 = 1;
    }
    else {
      *puVar3 = 0;
      *puVar2 = 2;
    }
    local_8 = 0xffffffff;
    param_1 = local_70;
    if (7 < local_38) {
      local_68 = (int *)(local_38 * 2 + 2);
      local_6c = local_4c[0];
      if ((int *)0xfff < local_68) {
        FUN_0048ead0(&local_6c,&local_68);
      }
      FUN_008d8efe(local_6c,local_68);
      param_1 = local_70;
    }
  }
LAB_008e9aa0:
  cVar4 = equal(&param_4);
  if (cVar4 != '\0') {
    *puVar2 = *puVar2 | 1;
  }
  *(undefined4 *)param_1 = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  FUN_008d9b68();
  return;
}



