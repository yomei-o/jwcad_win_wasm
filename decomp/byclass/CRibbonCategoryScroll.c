/* CRibbonCategoryScroll -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRibbonCategoryScroll[90] */
/* 00871c94  FUN_00871c94  34 bytes, 0 callers */

void FUN_00871c94(int param_1)

{
  int in_ECX;
  
  FUN_0086612f(param_1);
  *(undefined4 *)(in_ECX + 0x1c4) = *(undefined4 *)(param_1 + 0x1c4);
  return;
}




/* vtable slots: CRibbonCategoryScroll[84] */
/* 0087289d  FUN_0087289d  61 bytes, 0 callers */

undefined4 FUN_0087289d(void)

{
  code *pcVar1;
  BOOL BVar2;
  undefined4 uVar3;
  int in_ECX;
  
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x74));
  if (BVar2 != 0) {
    return 0;
  }
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x88) + 0xe0);
  guard_check_icall(*(undefined4 *)(in_ECX + 0x1c4),0);
  uVar3 = (*pcVar1)();
  return uVar3;
}




/* vtable slots: CRibbonCategoryScroll[153] */
/* 0087290c  FUN_0087290c  29 bytes, 0 callers */

void FUN_0087290c(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x150);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CRibbonCategoryScroll[95] */
/* 00872bfd  FUN_00872bfd  58 bytes, 0 callers */

void FUN_00872bfd(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  int *piVar3;
  int in_ECX;
  
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x74));
  if (BVar2 == 0) {
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0x21c);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CRibbonCategoryScroll[134] */
/* 0087329e  FUN_0087329e  125 bytes, 0 callers */

void FUN_0087329e(LONG param_1,LONG param_2)

{
  int iVar1;
  code *pcVar2;
  POINT pt;
  BOOL BVar3;
  int *in_ECX;
  
  BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x1d));
  if (BVar3 == 0) {
    iVar1 = in_ECX[0x32];
    pt.y = param_2;
    pt.x = param_1;
    BVar3 = PtInRect((RECT *)(in_ECX + 0x1d),pt);
    in_ECX[0x32] = BVar3;
    if (iVar1 != BVar3) {
      if (*(int *)(in_ECX[0x22] + 0x540) == 0) {
        if (*(int *)(in_ECX[0x22] + 0x53c) != 0) {
          FUN_008b3ecf();
        }
      }
      else {
        FUN_008b8e7b();
      }
      pcVar2 = *(code **)(*in_ECX + 0x1b8);
      guard_check_icall();
      (*pcVar2)();
    }
  }
  else {
    in_ECX[0x32] = 0;
  }
  return;
}



