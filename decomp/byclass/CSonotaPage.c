/* CSonotaPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSonotaPage[1] */
/* 005ce1d0  FUN_005ce1d0  68 bytes, 0 callers */

undefined4 FUN_005ce1d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005cd940();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xee8);
    }
  }
  return in_ECX;
}




/* vtable slots: CSonotaPage[64] */
/* 005ce2a0  FUN_005ce2a0  3523 bytes, 0 callers */

void FUN_005ce2a0(CDataExchange *param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933615;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00405880();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x419,(double *)(in_ECX + 0x350));
  FUN_0079f95a(param_1,in_ECX + 0x350,0x3ff0000000000000,0x408f400000000000);
  DDX_Text(param_1,0x41f,(double *)(in_ECX + 0x358));
  FUN_0079f95a(param_1,in_ECX + 0x358,0xc022000000000000,0x4022000000000000);
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x6fc,(double *)(in_ECX + 0x460));
  FUN_0079f95a(param_1,in_ECX + 0x460,0x4024000000000000,0x40f86a0000000000);
  DDX_Text(param_1,0x5d2,(double *)(in_ECX + 0x468));
  FUN_0079f95a(param_1,in_ECX + 0x468,0x4024000000000000,0x40f86a0000000000);
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x41e,(double *)(in_ECX + 0x710));
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  DDX_Text(param_1,0x422,(double *)(in_ECX + 0x7c8));
  FUN_0079f95a(param_1,in_ECX + 0x7c8,0x4000000000000000,0x408f400000000000);
  DDX_Text(param_1,0x41d,(double *)(in_ECX + 2000));
  FUN_0079f95a(param_1,in_ECX + 2000,0x3fe0000000000000,0x4000000000000000);
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x6fd,(double *)(in_ECX + 0xad8));
  DDX_Text(param_1,0x6fe,(double *)(in_ECX + 0xae0));
  DDX_Text(param_1,0x6ff,(double *)(in_ECX + 0xae8));
  DDX_Text(param_1,0x700,(double *)(in_ECX + 0xaf0));
  DDX_Text(param_1,0x702,(double *)(in_ECX + 0xaf8));
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  DDX_Text();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f801();
  FUN_0078f5bc(param_1,*(undefined4 *)(in_ECX + 0xbc8),1,100);
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  DDX_Text();
  CStringT<>();
  local_8 = 0;
  if (*(double *)(in_ECX + 0x468) == 999.0) {
    FUN_00797f20();
    FUN_00797f20();
    FUN_005977f0();
    local_8._0_1_ = 1;
    FUN_00404860();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    FUN_00404920();
    FUN_00797ece();
    FUN_007979e8();
  }
  else {
    FUN_00797f20();
    FUN_007979e8();
    FUN_00797f20();
    FUN_007979e8();
  }
  if (*(int *)(in_ECX + 0x580) == 0) {
    FUN_007979e8();
    FUN_007979e8();
    FUN_005977f0();
    local_8._0_1_ = 3;
    FUN_00404860();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    FUN_00404920();
    FUN_00797ece();
  }
  else {
    FUN_007979e8();
    FUN_007979e8();
    FUN_005977f0();
    local_8._0_1_ = 2;
    FUN_00404860();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    FUN_00404920();
    FUN_00797ece();
  }
  if (*(int *)(in_ECX + 0xb10) == 0) {
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
  }
  if (*(int *)(in_ECX + 0xb24) == 0) {
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
    if (*(int *)(in_ECX + 0xee0) == 0) {
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
    }
    FUN_007979e8();
  }
  switch(*(undefined4 *)(in_ECX + 200)) {
  default:
    FUN_005977f0();
    local_8._0_1_ = 4;
    FUN_00404920();
    FUN_00797ece();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    break;
  case 1:
    FUN_005977f0();
    local_8._0_1_ = 5;
    FUN_00404920();
    FUN_00797ece();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    break;
  case 2:
    FUN_005977f0();
    local_8._0_1_ = 6;
    FUN_00404920();
    FUN_00797ece();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    break;
  case 3:
    FUN_005977f0();
    local_8._0_1_ = 7;
    FUN_00404920();
    FUN_00797ece();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
  }
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CSonotaPage[10] */
/* 005cf080  FUN_005cf080  16 bytes, 0 callers */

void FUN_005cf080(void)

{
  FUN_005cf0a0();
  return;
}




/* vtable slots: CSonotaPage[0] */
/* 005cf090  FUN_005cf090  16 bytes, 0 callers */

undefined ** FUN_005cf090(void)

{
  return &PTR_s_CSonotaPage_00973468;
}



