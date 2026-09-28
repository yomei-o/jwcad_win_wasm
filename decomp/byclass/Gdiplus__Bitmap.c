/* Gdiplus::Bitmap -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: Gdiplus::Bitmap[0], Gdiplus::Image[0] */
/* 007e71c6  FUN_007e71c6  57 bytes, 0 callers */

void FUN_007e71c6(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = Gdiplus::Image::vftable;
  GdipDisposeImage(in_ECX[1]);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      GdipFree(in_ECX);
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: Gdiplus::Bitmap[1], Gdiplus::Image[1] */
/* 007e7e7f  FUN_007e7e7f  74 bytes, 0 callers */

undefined4 * FUN_007e7e7f(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  iVar2 = GdipCloneImage(*(undefined4 *)(in_ECX + 4),&local_8);
  if (iVar2 != 0) {
    *(int *)(in_ECX + 8) = iVar2;
  }
  puVar3 = (undefined4 *)GdipAlloc(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 8);
    *puVar3 = Gdiplus::Image::vftable;
    puVar3[1] = local_8;
    puVar3[2] = uVar1;
  }
  return puVar3;
}



