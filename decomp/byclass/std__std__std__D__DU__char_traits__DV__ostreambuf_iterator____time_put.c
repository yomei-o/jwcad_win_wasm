/* std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$time_put -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$time_put[0] */
/* 008ecf0c  FUN_008ecf0c  34 bytes, 0 callers */

void FUN_008ecf0c(byte param_1)

{
  ~time_put<>();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$time_put[3] */
/* 008efb35  FUN_008efb35  271 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008efb35(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,tm *param_6,undefined1 param_7,char param_8)

{
  size_t sVar1;
  tm *ptVar2;
  int in_ECX;
  int iVar3;
  char *pcVar4;
  tm *local_3c;
  uint local_38;
  tm local_34;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_3c = param_6;
  local_38 = param_1;
  local_34.tm_yday._0_1_ = 0;
  local_34.tm_mon = 0;
  local_34.tm_year = 0xf;
  local_34.tm_sec = 0;
  local_8 = 1;
  if (param_8 == '\0') {
    local_34.tm_wday._0_3_ = CONCAT12(param_7,0x2521);
    local_34.tm_wday = (int)(uint3)local_34.tm_wday;
  }
  else {
    local_34.tm_wday._0_3_ = CONCAT12(param_8,0x2521);
    local_34.tm_wday = CONCAT13(param_7,(uint3)local_34.tm_wday);
  }
  iVar3 = 0x10;
  while( true ) {
    FUN_00559dc0(iVar3,0);
    ptVar2 = &local_34;
    if (0xf < (uint)local_34.tm_year) {
      ptVar2 = (tm *)local_34.tm_sec;
    }
    sVar1 = __Strftime((char *)ptVar2,local_34.tm_mon,(char *)&local_34.tm_wday,param_6,
                       *(void **)(in_ECX + 8));
    if (sVar1 != 0) break;
    iVar3 = iVar3 * 2;
  }
  if ((uint)local_34.tm_year < 0x10) {
    pcVar4 = (char *)((int)&local_34.tm_sec + sVar1);
    ptVar2 = &local_34;
    if ((uint)local_34.tm_year < 0x10) goto LAB_008efbee;
  }
  else {
    pcVar4 = (char *)((int)(int *)local_34.tm_sec + sVar1);
  }
  ptVar2 = (tm *)local_34.tm_sec;
LAB_008efbee:
  FUN_008ec953(local_38,(char *)((int)&ptVar2->tm_sec + 1),pcVar4,param_2,param_3);
  if (0xf < (uint)local_34.tm_year) {
    local_38 = local_34.tm_year + 1;
    local_3c = (tm *)local_34.tm_sec;
    if (0xfff < local_38) {
      FUN_0048ead0(&local_3c,&local_38);
    }
    FUN_008d8efe(local_3c,local_38);
  }
  FUN_008d9b68();
  return;
}



