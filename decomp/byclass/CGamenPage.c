/* CGamenPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CGamenPage[1] */
/* 004c1160  FUN_004c1160  68 bytes, 0 callers */

undefined4 FUN_004c1160(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004c09a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1a70);
    }
  }
  return in_ECX;
}




/* vtable slots: CGamenPage[64] */
/* 004c16b0  FUN_004c16b0  7721 bytes, 0 callers */

void FUN_004c16b0(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880();
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
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text(param_1,0x9b3,(double *)(in_ECX + 0x1448));
  FUN_0079f95a(param_1,in_ECX + 0x1448,0,0x406fe00000000000);
  DDX_Text(param_1,0x9b4,(double *)(in_ECX + 0x1450));
  FUN_0079f95a(param_1,in_ECX + 0x1450,0,0x406fe00000000000);
  DDX_Text(param_1,0x9b5,(double *)(in_ECX + 0x1458));
  FUN_0079f95a(param_1,in_ECX + 0x1458,0,0x406fe00000000000);
  DDX_Text(param_1,0x9b0,(double *)(in_ECX + 0x1460));
  FUN_0079f95a(param_1,in_ECX + 0x1460,0,0x406fe00000000000);
  DDX_Text(param_1,0x9b1,(double *)(in_ECX + 0x1468));
  FUN_0079f95a(param_1,in_ECX + 0x1468,0,0x406fe00000000000);
  DDX_Text(param_1,0x9b2,(double *)(in_ECX + 0x1470));
  FUN_0079f95a(param_1,in_ECX + 0x1470,0,0x406fe00000000000);
  DDX_Text(param_1,0x623,(double *)(in_ECX + 0x1478));
  FUN_0079f95a(param_1,in_ECX + 0x1478,0,0x406fe00000000000);
  DDX_Text(param_1,0x624,(double *)(in_ECX + 0x1480));
  FUN_0079f95a(param_1,in_ECX + 0x1480,0,0x406fe00000000000);
  DDX_Text(param_1,0x625,(double *)(in_ECX + 0x1488));
  FUN_0079f95a(param_1,in_ECX + 0x1488,0,0x406fe00000000000);
  DDX_Text(param_1,0x626,(double *)(in_ECX + 0x1490));
  FUN_0079f95a(param_1,in_ECX + 0x1490,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x647,(double *)(in_ECX + 0x1498));
  FUN_0079f95a(param_1,in_ECX + 0x1498,0,0x406fe00000000000);
  DDX_Text(param_1,0x648,(double *)(in_ECX + 0x14a0));
  FUN_0079f95a(param_1,in_ECX + 0x14a0,0,0x406fe00000000000);
  DDX_Text(param_1,0x649,(double *)(in_ECX + 0x14a8));
  FUN_0079f95a(param_1,in_ECX + 0x14a8,0,0x406fe00000000000);
  DDX_Text(param_1,0x64a,(double *)(in_ECX + 0x14b0));
  FUN_0079f95a(param_1,in_ECX + 0x14b0,0x3ff0000000000000,0x407f400000000000);
  DDX_Text(param_1,0x627,(double *)(in_ECX + 0x14b8));
  FUN_0079f95a(param_1,in_ECX + 0x14b8,0,0x406fe00000000000);
  DDX_Text(param_1,0x62f,(double *)(in_ECX + 0x14c0));
  FUN_0079f95a(param_1,in_ECX + 0x14c0,0,0x406fe00000000000);
  DDX_Text(param_1,0x630,(double *)(in_ECX + 0x14c8));
  FUN_0079f95a(param_1,in_ECX + 0x14c8,0,0x406fe00000000000);
  DDX_Text(param_1,0x631,(double *)(in_ECX + 0x14d0));
  FUN_0079f95a(param_1,in_ECX + 0x14d0,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x64b,(double *)(in_ECX + 0x14d8));
  FUN_0079f95a(param_1,in_ECX + 0x14d8,0,0x406fe00000000000);
  DDX_Text(param_1,0x64c,(double *)(in_ECX + 0x14e0));
  FUN_0079f95a(param_1,in_ECX + 0x14e0,0,0x406fe00000000000);
  DDX_Text(param_1,0x64d,(double *)(in_ECX + 0x14e8));
  FUN_0079f95a(param_1,in_ECX + 0x14e8,0,0x406fe00000000000);
  DDX_Text(param_1,0x64e,(double *)(in_ECX + 0x14f0));
  FUN_0079f95a(param_1,in_ECX + 0x14f0,0x3ff0000000000000,0x407f400000000000);
  DDX_Text(param_1,0x628,(double *)(in_ECX + 0x14f8));
  FUN_0079f95a(param_1,in_ECX + 0x14f8,0,0x406fe00000000000);
  DDX_Text(param_1,0x632,(double *)(in_ECX + 0x1500));
  FUN_0079f95a(param_1,in_ECX + 0x1500,0,0x406fe00000000000);
  DDX_Text(param_1,0x633,(double *)(in_ECX + 0x1508));
  FUN_0079f95a(param_1,in_ECX + 0x1508,0,0x406fe00000000000);
  DDX_Text(param_1,0x634,(double *)(in_ECX + 0x1510));
  FUN_0079f95a(param_1,in_ECX + 0x1510,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x64f,(double *)(in_ECX + 0x1518));
  FUN_0079f95a(param_1,in_ECX + 0x1518,0,0x406fe00000000000);
  DDX_Text(param_1,0x650,(double *)(in_ECX + 0x1520));
  FUN_0079f95a(param_1,in_ECX + 0x1520,0,0x406fe00000000000);
  DDX_Text(param_1,0x651,(double *)(in_ECX + 0x1528));
  FUN_0079f95a(param_1,in_ECX + 0x1528,0,0x406fe00000000000);
  DDX_Text(param_1,0x652,(double *)(in_ECX + 0x1530));
  FUN_0079f95a(param_1,in_ECX + 0x1530,0x3ff0000000000000,0x407f400000000000);
  DDX_Text(param_1,0x629,(double *)(in_ECX + 0x1538));
  FUN_0079f95a(param_1,in_ECX + 0x1538,0,0x406fe00000000000);
  DDX_Text(param_1,0x635,(double *)(in_ECX + 0x1540));
  FUN_0079f95a(param_1,in_ECX + 0x1540,0,0x406fe00000000000);
  DDX_Text(param_1,0x636,(double *)(in_ECX + 0x1548));
  FUN_0079f95a(param_1,in_ECX + 0x1548,0,0x406fe00000000000);
  DDX_Text(param_1,0x637,(double *)(in_ECX + 0x1550));
  FUN_0079f95a(param_1,in_ECX + 0x1550,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x653,(double *)(in_ECX + 0x1558));
  FUN_0079f95a(param_1,in_ECX + 0x1558,0,0x406fe00000000000);
  DDX_Text(param_1,0x654,(double *)(in_ECX + 0x1560));
  FUN_0079f95a(param_1,in_ECX + 0x1560,0,0x406fe00000000000);
  DDX_Text(param_1,0x655,(double *)(in_ECX + 0x1568));
  FUN_0079f95a(param_1,in_ECX + 0x1568,0,0x406fe00000000000);
  DDX_Text(param_1,0x656,(double *)(in_ECX + 0x1570));
  FUN_0079f95a(param_1,in_ECX + 0x1570,0x3ff0000000000000,0x407f400000000000);
  DDX_Text(param_1,0x62a,(double *)(in_ECX + 0x1578));
  FUN_0079f95a(param_1,in_ECX + 0x1578,0,0x406fe00000000000);
  DDX_Text(param_1,0x638,(double *)(in_ECX + 0x1580));
  FUN_0079f95a(param_1,in_ECX + 0x1580,0,0x406fe00000000000);
  DDX_Text(param_1,0x639,(double *)(in_ECX + 0x1588));
  FUN_0079f95a(param_1,in_ECX + 0x1588,0,0x406fe00000000000);
  DDX_Text(param_1,0x63a,(double *)(in_ECX + 0x1590));
  FUN_0079f95a(param_1,in_ECX + 0x1590,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x658,(double *)(in_ECX + 0x1598));
  FUN_0079f95a(param_1,in_ECX + 0x1598,0,0x406fe00000000000);
  DDX_Text(param_1,0x659,(double *)(in_ECX + 0x15a0));
  FUN_0079f95a(param_1,in_ECX + 0x15a0,0,0x406fe00000000000);
  DDX_Text(param_1,0x65a,(double *)(in_ECX + 0x15a8));
  FUN_0079f95a(param_1,in_ECX + 0x15a8,0,0x406fe00000000000);
  DDX_Text(param_1,0x65b,(double *)(in_ECX + 0x15b0));
  FUN_0079f95a(param_1,in_ECX + 0x15b0,0x3ff0000000000000,0x407f400000000000);
  DDX_Text(param_1,0x62b,(double *)(in_ECX + 0x15b8));
  FUN_0079f95a(param_1,in_ECX + 0x15b8,0,0x406fe00000000000);
  DDX_Text(param_1,0x63b,(double *)(in_ECX + 0x15c0));
  FUN_0079f95a(param_1,in_ECX + 0x15c0,0,0x406fe00000000000);
  DDX_Text(param_1,0x63c,(double *)(in_ECX + 0x15c8));
  FUN_0079f95a(param_1,in_ECX + 0x15c8,0,0x406fe00000000000);
  DDX_Text(param_1,0x63d,(double *)(in_ECX + 0x15d0));
  FUN_0079f95a(param_1,in_ECX + 0x15d0,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x65c,(double *)(in_ECX + 0x15d8));
  FUN_0079f95a(param_1,in_ECX + 0x15d8,0,0x406fe00000000000);
  DDX_Text(param_1,0x65d,(double *)(in_ECX + 0x15e0));
  FUN_0079f95a(param_1,in_ECX + 0x15e0,0,0x406fe00000000000);
  DDX_Text(param_1,0x65e,(double *)(in_ECX + 0x15e8));
  FUN_0079f95a(param_1,in_ECX + 0x15e8,0,0x406fe00000000000);
  DDX_Text(param_1,0x65f,(double *)(in_ECX + 0x15f0));
  FUN_0079f95a(param_1,in_ECX + 0x15f0,0x3ff0000000000000,0x407f400000000000);
  DDX_Text(param_1,0x62c,(double *)(in_ECX + 0x15f8));
  FUN_0079f95a(param_1,in_ECX + 0x15f8,0,0x406fe00000000000);
  DDX_Text(param_1,0x63e,(double *)(in_ECX + 0x1600));
  FUN_0079f95a(param_1,in_ECX + 0x1600,0,0x406fe00000000000);
  DDX_Text(param_1,0x63f,(double *)(in_ECX + 0x1608));
  FUN_0079f95a(param_1,in_ECX + 0x1608,0,0x406fe00000000000);
  DDX_Text(param_1,0x640,(double *)(in_ECX + 0x1610));
  FUN_0079f95a(param_1,in_ECX + 0x1610,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x660,(double *)(in_ECX + 0x1618));
  FUN_0079f95a(param_1,in_ECX + 0x1618,0,0x406fe00000000000);
  DDX_Text(param_1,0x661,(double *)(in_ECX + 0x1620));
  FUN_0079f95a(param_1,in_ECX + 0x1620,0,0x406fe00000000000);
  DDX_Text(param_1,0x662,(double *)(in_ECX + 0x1628));
  FUN_0079f95a(param_1,in_ECX + 0x1628,0,0x406fe00000000000);
  DDX_Text(param_1,0x663,(double *)(in_ECX + 0x1630));
  FUN_0079f95a(param_1,in_ECX + 0x1630,0x3ff0000000000000,0x407f400000000000);
  DDX_Text(param_1,0x62d,(double *)(in_ECX + 0x1638));
  FUN_0079f95a(param_1,in_ECX + 0x1638,0,0x406fe00000000000);
  DDX_Text(param_1,0x641,(double *)(in_ECX + 0x1640));
  FUN_0079f95a(param_1,in_ECX + 0x1640,0,0x406fe00000000000);
  DDX_Text(param_1,0x642,(double *)(in_ECX + 0x1648));
  FUN_0079f95a(param_1,in_ECX + 0x1648,0,0x406fe00000000000);
  DDX_Text(param_1,0x643,(double *)(in_ECX + 0x1650));
  FUN_0079f95a(param_1,in_ECX + 0x1650,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x664,(double *)(in_ECX + 0x1658));
  FUN_0079f95a(param_1,in_ECX + 0x1658,0,0x406fe00000000000);
  DDX_Text(param_1,0x665,(double *)(in_ECX + 0x1660));
  FUN_0079f95a(param_1,in_ECX + 0x1660,0,0x406fe00000000000);
  DDX_Text(param_1,0x666,(double *)(in_ECX + 0x1668));
  FUN_0079f95a(param_1,in_ECX + 0x1668,0,0x406fe00000000000);
  DDX_Text(param_1,0x667,(double *)(in_ECX + 0x1670));
  FUN_0079f95a(param_1,in_ECX + 0x1670,0x3ff0000000000000,0x407f400000000000);
  DDX_Text(param_1,0x62e,(double *)(in_ECX + 0x1678));
  FUN_0079f95a(param_1,in_ECX + 0x1678,0,0x406fe00000000000);
  DDX_Text(param_1,0x644,(double *)(in_ECX + 0x1680));
  FUN_0079f95a(param_1,in_ECX + 0x1680,0,0x406fe00000000000);
  DDX_Text(param_1,0x645,(double *)(in_ECX + 0x1688));
  FUN_0079f95a(param_1,in_ECX + 0x1688,0,0x406fe00000000000);
  DDX_Text(param_1,0x646,(double *)(in_ECX + 0x1690));
  FUN_0079f95a(param_1,in_ECX + 0x1690,0x3ff0000000000000,0x4030000000000000);
  DDX_Text(param_1,0x657,(double *)(in_ECX + 0x1698));
  FUN_0079f95a(param_1,in_ECX + 0x1698,0,0x406fe00000000000);
  DDX_Text(param_1,0x669,(double *)(in_ECX + 0x16a0));
  FUN_0079f95a(param_1,in_ECX + 0x16a0,0,0x406fe00000000000);
  DDX_Text(param_1,0x66a,(double *)(in_ECX + 0x16a8));
  FUN_0079f95a(param_1,in_ECX + 0x16a8,0,0x406fe00000000000);
  DDX_Text(param_1,0x668,(double *)(in_ECX + 0x16b0));
  FUN_0079f95a(param_1,in_ECX + 0x16b0,0,0x406fe00000000000);
  DDX_Text(param_1,0x66b,(double *)(in_ECX + 0x16b8));
  FUN_0079f95a(param_1,in_ECX + 0x16b8,0,0x406fe00000000000);
  DDX_Text(param_1,0x66c,(double *)(in_ECX + 0x16c0));
  FUN_0079f95a(param_1,in_ECX + 0x16c0,0,0x406fe00000000000);
  DDX_Text(param_1,0x66d,(double *)(in_ECX + 0x16c8));
  FUN_0079f95a(param_1,in_ECX + 0x16c8,0,0x406fe00000000000);
  DDX_Text(param_1,0x66e,(double *)(in_ECX + 0x16d0));
  FUN_0079f95a(param_1,in_ECX + 0x16d0,0,0x406fe00000000000);
  DDX_Text(param_1,0x66f,(double *)(in_ECX + 0x16d8));
  FUN_0079f95a(param_1,in_ECX + 0x16d8,0,0x406fe00000000000);
  DDX_Text(param_1,0x670,(double *)(in_ECX + 0x16e0));
  FUN_0079f95a(param_1,in_ECX + 0x16e0,0,0x406fe00000000000);
  DDX_Text(param_1,0x671,(double *)(in_ECX + 0x16e8));
  FUN_0079f95a(param_1,in_ECX + 0x16e8,0,0x406fe00000000000);
  DDX_Text(param_1,0x672,(double *)(in_ECX + 0x16f0));
  FUN_0079f95a(param_1,in_ECX + 0x16f0,0,0x406fe00000000000);
  DDX_Text(param_1,0x9e5,(double *)(in_ECX + 0x16f8));
  FUN_0079f95a(param_1,in_ECX + 0x16f8,0x3fb999999999999a,0x4024000000000000);
  DDX_Text(param_1,0x9e6,(double *)(in_ECX + 0x1700));
  FUN_0079f95a(param_1,in_ECX + 0x1700,0x3fb999999999999a,0x4024000000000000);
  DDX_Text(param_1,0x9e7,(double *)(in_ECX + 0x1708));
  FUN_0079f95a(param_1,in_ECX + 0x1708,0x3fb999999999999a,0x4024000000000000);
  DDX_Text(param_1,0x9e8,(double *)(in_ECX + 0x1710));
  FUN_0079f95a(param_1,in_ECX + 0x1710,0x3fb999999999999a,0x4024000000000000);
  DDX_Text(param_1,0x9e9,(double *)(in_ECX + 0x1718));
  FUN_0079f95a(param_1,in_ECX + 0x1718,0x3fb999999999999a,0x4024000000000000);
  DDX_Text(param_1,0x9ea,(double *)(in_ECX + 0x1720));
  FUN_0079f95a(param_1,in_ECX + 0x1720,0x3fb999999999999a,0x4024000000000000);
  DDX_Text(param_1,0x9eb,(double *)(in_ECX + 0x1728));
  FUN_0079f95a(param_1,in_ECX + 0x1728,0x3fb999999999999a,0x4024000000000000);
  DDX_Text(param_1,0x9ec,(double *)(in_ECX + 0x1730));
  FUN_0079f95a(param_1,in_ECX + 0x1730,0x3fb999999999999a,0x4024000000000000);
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  DDX_Text(param_1,0x421,(double *)(in_ECX + 0x1a48));
  FUN_0078f5ed();
  DDX_Text();
  DDX_Text();
  DDX_Text();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  FUN_007979e8();
  if (0.0 < *(double *)(in_ECX + 0x1a48) || *(double *)(in_ECX + 0x1a48) == 0.0) {
    FUN_007979e8();
  }
  else {
    FUN_007979e8();
  }
  FUN_004c13b0();
  return;
}




/* vtable slots: CGamenPage[10] */
/* 004c34e0  FUN_004c34e0  16 bytes, 0 callers */

void FUN_004c34e0(void)

{
  FUN_004c3500();
  return;
}




/* vtable slots: CGamenPage[0] */
/* 004c34f0  FUN_004c34f0  16 bytes, 0 callers */

undefined ** FUN_004c34f0(void)

{
  return &PTR_s_CGamenPage_0095ebc8;
}




/* vtable slots: CGamenPage[94] */
/* 004c3c30  FUN_004c3c30  24 bytes, 0 callers */

undefined4 FUN_004c3c30(void)

{
  FUN_00798993();
  return 1;
}



