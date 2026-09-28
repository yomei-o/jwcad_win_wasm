/* CDocument::CDocumentAdapter -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDocument::CDocumentAdapter[12] */
/* 0049ad70  FUN_0049ad70  17 bytes, 12 callers */

undefined4 FUN_0049ad70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}




/* vtable slots: CDocument::CDocumentAdapter[0] */
/* 004d1910  FUN_004d1910  46 bytes, 0 callers */

undefined4 FUN_004d1910(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004d1740();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0xc);
  }
  return in_ECX;
}




/* vtable slots: CDocument::CDocumentAdapter[5] */
/* 004d19e0  FUN_004d19e0  44 bytes, 0 callers */

void FUN_004d19e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0xc0))();
  }
  return;
}




/* vtable slots: CDocument::CDocumentAdapter[7] */
/* 004d1b10  FUN_004d1b10  44 bytes, 0 callers */

void FUN_004d1b10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0xb8))();
  }
  return;
}




/* vtable slots: CDocument::CDocumentAdapter[11] */
/* 004d1cd0  FUN_004d1cd0  56 bytes, 0 callers */

undefined4 FUN_004d1cd0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xcc))(param_1,param_2);
  }
  return uVar1;
}




/* vtable slots: CDocument::CDocumentAdapter[6] */
/* 004d1e90  FUN_004d1e90  60 bytes, 0 callers */

undefined4 FUN_004d1e90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xb0))(param_1,param_2,param_3);
  }
  return uVar1;
}




/* vtable slots: CDocument::CDocumentAdapter[4] */
/* 004d1fc0  FUN_004d1fc0  44 bytes, 0 callers */

void FUN_004d1fc0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0xb4))();
  }
  return;
}




/* vtable slots: CDocument::CDocumentAdapter[3] */
/* 004d2050  FUN_004d2050  110 bytes, 0 callers */

undefined4 FUN_004d2050(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    uVar1 = 0x80004003;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 8) + 0xa8) = 1;
    *(undefined4 *)(*(int *)(in_ECX + 8) + 0xa0) = 1;
    (**(code **)(**(int **)(in_ECX + 8) + 0x78))();
    uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xac))(param_1,param_2);
  }
  return uVar1;
}




/* vtable slots: CDocument::CDocumentAdapter[9] */
/* 004d2620  FUN_004d2620  52 bytes, 0 callers */

undefined4 FUN_004d2620(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xc4))(param_1);
  }
  return uVar1;
}




/* vtable slots: CDocument::CDocumentAdapter[10] */
/* 004d2720  FUN_004d2720  54 bytes, 0 callers */

void FUN_004d2720(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 200))(param_1,param_2);
  }
  return;
}




/* vtable slots: CDocument::CDocumentAdapter[8] */
/* 004d2f00  FUN_004d2f00  52 bytes, 0 callers */

undefined4 FUN_004d2f00(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xbc))(param_1);
  }
  return uVar1;
}



