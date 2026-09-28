/* std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$time_put -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$time_put[0] */
/* 008e1282  FUN_008e1282  34 bytes, 0 callers */

void FUN_008e1282(byte param_1)

{
  ~time_put<>();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$time_put[3] */
/* 008ec03f  FUN_008ec03f  284 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008ec03f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,tm *param_6,char param_7,char param_8)

{
  wchar_t ****ppppwVar1;
  size_t sVar2;
  wchar_t ****in_ECX;
  wchar_t ****ppppwVar3;
  int iVar4;
  wchar_t ***local_40;
  tm *local_3c;
  wchar_t ***local_38 [4];
  size_t local_28;
  uint local_24;
  wchar_t local_20 [2];
  undefined4 local_1c;
  undefined2 uStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_3c = param_6;
  local_20[0] = L'!';
  local_20[1] = L'%';
  uStack_18 = 0;
  local_28 = 0;
  local_24 = 7;
  local_38[0] = (wchar_t ***)0x0;
  local_8 = 1;
  if (param_8 == '\0') {
    local_1c = (uint)(ushort)(short)param_7;
  }
  else {
    local_1c = CONCAT22((short)param_7,(short)param_8);
  }
  iVar4 = 0x10;
  local_40 = (wchar_t ***)in_ECX;
  while( true ) {
    FID_conflict_append(iVar4,0);
    ppppwVar1 = local_38;
    if (7 < local_24) {
      ppppwVar1 = (wchar_t ****)local_38[0];
    }
    sVar2 = __Wcsftime((wchar_t *)ppppwVar1,local_28,local_20,param_6,in_ECX[2]);
    if (sVar2 != 0) break;
    iVar4 = iVar4 * 2;
  }
  ppppwVar1 = local_38;
  if (7 < local_24) {
    ppppwVar1 = (wchar_t ****)local_38[0];
  }
  ppppwVar3 = local_38;
  if (7 < local_24) {
    ppppwVar3 = (wchar_t ****)local_38[0];
  }
  FUN_008dff7e(param_1,(wchar_t *)((int)ppppwVar3 + 2),(wchar_t *)((int)ppppwVar1 + sVar2 * 2),
               param_2,param_3);
  if (7 < local_24) {
    local_3c = (tm *)(local_24 * 2 + 2);
    local_40 = local_38[0];
    if ((tm *)0xfff < local_3c) {
      FUN_0048ead0(&local_40,&local_3c);
    }
    FUN_008d8efe(local_40,local_3c);
  }
  FUN_008d9b68();
  return;
}



