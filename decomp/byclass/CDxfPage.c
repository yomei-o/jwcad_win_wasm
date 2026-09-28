/* CDxfPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDxfPage[1] */
/* 004a9cc0  FUN_004a9cc0  68 bytes, 0 callers */

undefined4 FUN_004a9cc0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004a9a90();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x288);
    }
  }
  return in_ECX;
}




/* vtable slots: CDxfPage[64] */
/* 004a9d90  FUN_004a9d90  934 bytes, 0 callers */

void FUN_004a9d90(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x89d,in_ECX + 0x188);
  FUN_0078fb9c(param_1,0x8a6,in_ECX + 0x208);
  FUN_0078f6f8(param_1,0x898,in_ECX + 0xc4);
  FUN_0078f6f8(param_1,0x89b,in_ECX + 0xcc);
  FUN_0078f6f8(param_1,0x89a,in_ECX + 0xd0);
  FUN_0078f6f8(param_1,0x89c,in_ECX + 0xd4);
  FUN_0078f6f8(param_1,0x89d,in_ECX + 0xd8);
  FUN_0078f6f8(param_1,0x8a6,in_ECX + 0xdc);
  FUN_0078f6f8(param_1,0x89f,in_ECX + 0xe0);
  FUN_0078f5ed(param_1,0x912,in_ECX + 0xe4);
  FUN_0078f5ed(param_1,0x913,in_ECX + 0xe8);
  FUN_0078f5ed(param_1,0x914,in_ECX + 0xec);
  FUN_0078f5ed(param_1,0x915,in_ECX + 0xf0);
  FUN_0078f5ed(param_1,0x916,in_ECX + 0xf4);
  FUN_0078f5ed(param_1,0x917,in_ECX + 0xf8);
  FUN_0078f5ed(param_1,0x918,in_ECX + 0xfc);
  FUN_0078f5ed(param_1,0x919,in_ECX + 0x100);
  FUN_0078f6f8(param_1,0x8a0,in_ECX + 0x104);
  FUN_0078f6f8(param_1,0x897,in_ECX + 0x108);
  DDX_Text(param_1,0x90a,in_ECX + 0x10c);
  DDX_Text(param_1,0x90b,in_ECX + 0x110);
  DDX_Text(param_1,0x90c,in_ECX + 0x114);
  DDX_Text(param_1,0x90d,in_ECX + 0x118);
  DDX_Text(param_1,0x90e,in_ECX + 0x11c);
  DDX_Text(param_1,0x90f,in_ECX + 0x120);
  DDX_Text(param_1,0x910,in_ECX + 0x124);
  DDX_Text(param_1,0x911,in_ECX + 0x128);
  FUN_0078f801(param_1,0x98b,in_ECX + 0x130);
  FUN_0078f5bc(param_1,*(undefined4 *)(in_ECX + 0x130),0,0x12);
  FUN_0078f801(param_1,0x989,in_ECX + 0x134);
  FUN_0078f5bc(param_1,*(undefined4 *)(in_ECX + 0x134),0,0x12);
  FUN_0078f801(param_1,0x98a,in_ECX + 0x138);
  FUN_0078f5bc(param_1,*(undefined4 *)(in_ECX + 0x138),0,0x12);
  if (*(int *)(in_ECX + 0xd4) == 0) {
    *(undefined4 *)(in_ECX + 0xd8) = 1;
    *(undefined4 *)(in_ECX + 0xdc) = 0;
    FUN_007979e8(1);
    FUN_007979e8(0);
  }
  else {
    *(undefined4 *)(in_ECX + 0xd8) = 0;
    *(undefined4 *)(in_ECX + 0xdc) = 1;
    FUN_007979e8(0);
    FUN_007979e8(1);
  }
  return;
}




/* vtable slots: CDxfPage[10] */
/* 004aa190  FUN_004aa190  16 bytes, 0 callers */

void FUN_004aa190(void)

{
  FUN_004aa1b0();
  return;
}




/* vtable slots: CDxfPage[0] */
/* 004aa1a0  FUN_004aa1a0  16 bytes, 0 callers */

undefined ** FUN_004aa1a0(void)

{
  return &PTR_s_CDxfPage_0095c9c0;
}




/* vtable slots: CDxfPage[94] */
/* 004aa450  FUN_004aa450  107 bytes, 0 callers */

undefined4 FUN_004aa450(void)

{
  int in_ECX;
  
  FUN_00798993();
  FUN_004ddc30(&DAT_00a0ed88);
  FUN_004aa4e0();
  FUN_007955d2(1);
  if (*(int *)(in_ECX + 0xdc) == 0) {
    *(undefined4 *)(in_ECX + 0xd8) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xd8) = 0;
  }
  FUN_007955d2(0);
  return 1;
}



