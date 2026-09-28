/* CSonotaPage1 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSonotaPage1[1] */
/* 005d0c70  FUN_005d0c70  68 bytes, 0 callers */

undefined4 FUN_005d0c70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005d02e0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,3000);
    }
  }
  return in_ECX;
}




/* vtable slots: CSonotaPage1[64] */
/* 005d0d40  FUN_005d0d40  2444 bytes, 0 callers */

void FUN_005d0d40(CDataExchange *param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920ed5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00405880();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  DDX_Text(param_1,0x7a5,(double *)(in_ECX + 0x508));
  FUN_0079f95a(param_1,in_ECX + 0x508,0xc08f400000000000,0x408f400000000000);
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  DDX_Text();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x79f,(double *)(in_ECX + 0x848));
  FUN_0079f95a(param_1,in_ECX + 0x848,0x3f847ae147ae147b,0x3ff0000000000000);
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x7a0,(double *)(in_ECX + 0x950));
  FUN_0079f95a(param_1,in_ECX + 0x950,0x3ff199999999999a,0x4014000000000000);
  FUN_0078fb9c();
  DDX_Text(param_1,0x79a,(double *)(in_ECX + 0x9d8));
  FUN_0079f95a(param_1,in_ECX + 0x9d8,0,0x4022000000000000);
  DDX_Text(param_1,0x79b,(double *)(in_ECX + 0x9e0));
  FUN_0079f95a(param_1,in_ECX + 0x9d8,0,0x4022000000000000);
  DDX_Text(param_1,0x79c,(double *)(in_ECX + 0x9e8));
  FUN_0079f95a(param_1,in_ECX + 0x9d8,0,0x4022000000000000);
  DDX_Text(param_1,0x79d,(double *)(in_ECX + 0x9f0));
  FUN_0079f95a(param_1,in_ECX + 0x9d8,0,0x4022000000000000);
  DDX_Text(param_1,0x79e,(double *)(in_ECX + 0x9f8));
  FUN_0079f95a(param_1,in_ECX + 0x9f8,0x4000000000000000,0x4049000000000000);
  DDX_Text(param_1,0x7a1,(double *)(in_ECX + 0xa00));
  FUN_0079f95a(param_1,in_ECX + 0xa00,0x4049000000000000,0x408f400000000000);
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_00403dd0();
  local_8 = 0;
  FUN_005977f0();
  local_8._0_1_ = 1;
  FUN_00404950();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404770();
  FUN_00404920();
  FUN_00797ece();
  if (*(int *)(in_ECX + 0x6b4) == 0) {
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
  }
  else {
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
  }
  if (DAT_00a08ae0 < 1) {
    FUN_00797f20();
  }
  if (DAT_00a0c7c4 < 1) {
    FUN_00797f20();
  }
  else {
    FUN_00797f20();
    if (DAT_00a0cad0 == 0) {
      FUN_007979e8();
    }
    else {
      FUN_007979e8();
    }
  }
  if (DAT_00a0cb00 == 0) {
    FUN_007979e8();
  }
  if (DAT_00a0cad0 == 0) {
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
  }
  else {
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
    FUN_007979e8();
  }
  FUN_0078f801();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CSonotaPage1[10] */
/* 005d16d0  FUN_005d16d0  16 bytes, 0 callers */

void FUN_005d16d0(void)

{
  FUN_005d16f0();
  return;
}




/* vtable slots: CSonotaPage1[0] */
/* 005d16e0  FUN_005d16e0  16 bytes, 0 callers */

undefined ** FUN_005d16e0(void)

{
  return &PTR_s_CSonotaPage1_00973848;
}




/* vtable slots: CSonotaPage1[94] */
/* 005d1980  FUN_005d1980  48 bytes, 0 callers */

undefined4 FUN_005d1980(void)

{
  int in_ECX;
  
  FUN_00798993();
  FUN_007979e8(*(undefined4 *)(in_ECX + 0xa94));
  return 1;
}



