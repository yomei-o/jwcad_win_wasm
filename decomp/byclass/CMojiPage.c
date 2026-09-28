/* CMojiPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMojiPage[1] */
/* 00585030  FUN_00585030  68 bytes, 0 callers */

undefined4 FUN_00585030(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00584920();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x18b0);
    }
  }
  return in_ECX;
}




/* vtable slots: CMojiPage[64] */
/* 00585100  FUN_00585100  5219 bytes, 0 callers */

void FUN_00585100(CDataExchange *param_1)

{
  undefined1 local_a0 [4];
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 local_94 [4];
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [4];
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c [4];
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_70 [4];
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [4];
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092ee86;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00405880();
  DDX_Text(param_1,0x9a6,(double *)(local_14 + 0x8b8));
  FUN_0079f95a(param_1,local_14 + 0x8b8,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9a7,(double *)(local_14 + 0x8c0));
  FUN_0079f95a(param_1,local_14 + 0x8c0,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9a8,(double *)(local_14 + 0x8c8));
  FUN_0079f95a(param_1,local_14 + 0x8c8,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9a9,(double *)(local_14 + 0x8d0));
  FUN_0079f95a(param_1,local_14 + 0x8d0,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9aa,(double *)(local_14 + 0x8d8));
  FUN_0079f95a(param_1,local_14 + 0x8d8,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9ab,(double *)(local_14 + 0x8e0));
  FUN_0079f95a(param_1,local_14 + 0x8e0,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9ac,(double *)(local_14 + 0x8e8));
  FUN_0079f95a(param_1,local_14 + 0x8e8,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9ad,(double *)(local_14 + 0x8f0));
  FUN_0079f95a(param_1,local_14 + 0x8f0,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9ae,(double *)(local_14 + 0x8f8));
  FUN_0079f95a(param_1,local_14 + 0x8f8,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x9af,(double *)(local_14 + 0x900));
  FUN_0079f95a(param_1,local_14 + 0x900,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x5fc,(double *)(local_14 + 0x908));
  FUN_0079f95a(param_1,local_14 + 0x908,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x5fd,(double *)(local_14 + 0x910));
  FUN_0079f95a(param_1,local_14 + 0x910,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x5fe,(double *)(local_14 + 0x918));
  FUN_0079f95a(param_1,local_14 + 0x918,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x5ff,(double *)(local_14 + 0x920));
  FUN_0079f95a(param_1,local_14 + 0x920,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x600,(double *)(local_14 + 0x928));
  FUN_0079f95a(param_1,local_14 + 0x928,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x601,(double *)(local_14 + 0x930));
  FUN_0079f95a(param_1,local_14 + 0x930,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x602,(double *)(local_14 + 0x938));
  FUN_0079f95a(param_1,local_14 + 0x938,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x603,(double *)(local_14 + 0x940));
  FUN_0079f95a(param_1,local_14 + 0x940,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x604,(double *)(local_14 + 0x948));
  FUN_0079f95a(param_1,local_14 + 0x948,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x605,(double *)(local_14 + 0x950));
  FUN_0079f95a(param_1,local_14 + 0x950,0x3f847ae147ae147b,0x407f400000000000);
  DDX_Text(param_1,0x606,(double *)(local_14 + 0x958));
  FUN_0079f95a(param_1,local_14 + 0x958,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x607,(double *)(local_14 + 0x960));
  FUN_0079f95a(param_1,local_14 + 0x960,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x608,(double *)(local_14 + 0x968));
  FUN_0079f95a(param_1,local_14 + 0x968,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x609,(double *)(local_14 + 0x970));
  FUN_0079f95a(param_1,local_14 + 0x970,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x60a,(double *)(local_14 + 0x978));
  FUN_0079f95a(param_1,local_14 + 0x978,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x60b,(double *)(local_14 + 0x980));
  FUN_0079f95a(param_1,local_14 + 0x980,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x60c,(double *)(local_14 + 0x988));
  FUN_0079f95a(param_1,local_14 + 0x988,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x60d,(double *)(local_14 + 0x990));
  FUN_0079f95a(param_1,local_14 + 0x990,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x60e,(double *)(local_14 + 0x998));
  FUN_0079f95a(param_1,local_14 + 0x998,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x60f,(double *)(local_14 + 0x9a0));
  FUN_0079f95a(param_1,local_14 + 0x9a0,0xc059000000000000,0x407f400000000000);
  DDX_Text(param_1,0x610,(double *)(local_14 + 0x9a8));
  FUN_0079f95a(param_1,local_14 + 0x9a8,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x611,(double *)(local_14 + 0x9b0));
  FUN_0079f95a(param_1,local_14 + 0x9b0,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x612,(double *)(local_14 + 0x9b8));
  FUN_0079f95a(param_1,local_14 + 0x9b8,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x613,(double *)(local_14 + 0x9c0));
  FUN_0079f95a(param_1,local_14 + 0x9c0,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x614,(double *)(local_14 + 0x9c8));
  FUN_0079f95a(param_1,local_14 + 0x9c8,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x615,(double *)(local_14 + 0x9d0));
  FUN_0079f95a(param_1,local_14 + 0x9d0,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x616,(double *)(local_14 + 0x9d8));
  FUN_0079f95a(param_1,local_14 + 0x9d8,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x617,(double *)(local_14 + 0x9e0));
  FUN_0079f95a(param_1,local_14 + 0x9e0,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x618,(double *)(local_14 + 0x9e8));
  FUN_0079f95a(param_1,local_14 + 0x9e8,0x3ff0000000000000,0x4022000000000000);
  DDX_Text(param_1,0x619,(double *)(local_14 + 0x9f0));
  FUN_0079f95a(param_1,local_14 + 0x9f0,0x3ff0000000000000,0x4022000000000000);
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f75d();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x61a,(double *)(local_14 + 0x1600));
  FUN_0079f95a(param_1,local_14 + 0x1600,0x3ff0000000000000,0x4024000000000000);
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x61b,(double *)(local_14 + 0x1718));
  FUN_0079f95a(param_1,local_14 + 0x1718,0xbff0000000000000,0x4024000000000000);
  local_18 = (uint)(*(int *)(local_14 + 0xff8) != 0);
  local_1c = (uint)(local_18 == 0);
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  local_24 = FUN_00586a40(local_28,0);
  local_8 = 0;
  local_20 = local_24;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  FUN_00404920();
  FUN_00797ece();
  local_30 = FUN_00586a40(local_34,1);
  local_8 = 1;
  local_2c = local_30;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_3c = FUN_00586a40(local_40,2);
  local_8 = 2;
  local_38 = local_3c;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_48 = FUN_00586a40(local_4c,3);
  local_8 = 3;
  local_44 = local_48;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_54 = FUN_00586a40(local_58,4);
  local_8 = 4;
  local_50 = local_54;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_60 = FUN_00586a40(local_64,5);
  local_8 = 5;
  local_5c = local_60;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_6c = FUN_00586a40(local_70,6);
  local_8 = 6;
  local_68 = local_6c;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_78 = FUN_00586a40(local_7c,7);
  local_8 = 7;
  local_74 = local_78;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_84 = FUN_00586a40(local_88,8);
  local_8 = 8;
  local_80 = local_84;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_90 = FUN_00586a40(local_94,9);
  local_8 = 9;
  local_8c = local_90;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_9c = FUN_00586a40(local_a0,10);
  local_8 = 10;
  local_98 = local_9c;
  FUN_00404920();
  FUN_00797ece();
  local_8 = 0xffffffff;
  FUN_00404540();
  local_18 = (uint)(*(int *)(local_14 + 0x160c) != 0);
  FUN_007979e8();
  FUN_007979e8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f643();
  FUN_0078f643();
  FUN_0078f643();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CMojiPage[10] */
/* 00586570  FUN_00586570  16 bytes, 0 callers */

void FUN_00586570(void)

{
  FUN_00586590();
  return;
}




/* vtable slots: CMojiPage[0] */
/* 00586580  FUN_00586580  16 bytes, 0 callers */

undefined ** FUN_00586580(void)

{
  return &PTR_s_CMojiPage_0096c010;
}



