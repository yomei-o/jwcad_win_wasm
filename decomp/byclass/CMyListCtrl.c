/* CMyListCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyListCtrl[1] */
/* 00564c30  FUN_00564c30  68 bytes, 0 callers */

undefined4 FUN_00564c30(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00564b70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x98);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyListCtrl[10] */
/* 00565120  FUN_00565120  16 bytes, 0 callers */

void FUN_00565120(void)

{
  FUN_00565220();
  return;
}




/* vtable slots: CMyListCtrl[67] */
/* 00565570  FUN_00565570  150 bytes, 0 callers */

void FUN_00565570(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_28;
  undefined4 local_c;
  
  if ((((*(int *)(param_1 + 4) == 0x100) && (*(int *)(param_1 + 8) == 0xd)) &&
      (*(int *)(in_ECX + 0x84) != -1)) && (*(int *)(in_ECX + 0x90) == 0)) {
    local_48 = 4;
    local_44 = *(undefined4 *)(in_ECX + 0x84);
    local_40 = 0;
    iVar1 = FUN_005650f0(&local_48);
    if (iVar1 != 0) {
      local_c = local_28;
      uVar3 = 0;
      uVar2 = FUN_005659b0(0);
      FUN_00406bc0(0x1406,uVar2,uVar3);
    }
  }
  FUN_007949fb(param_1);
  return;
}



