/* CZokuseiSelHenkouDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZokuseiSelHenkouDialog[1] */
/* 006083e0  FUN_006083e0  68 bytes, 0 callers */

undefined4 FUN_006083e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00608100();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1788);
    }
  }
  return in_ECX;
}




/* vtable slots: CZokuseiSelHenkouDialog[24] */
/* 00608d60  FUN_00608d60  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00608d60(void)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_00413f30();
    FUN_004146a0(&local_18);
    FUN_00517510(&DAT_00a0c13c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CZokuseiSelHenkouDialog[64] */
/* 00608de0  FUN_00608de0  2031 bytes, 0 callers */

void FUN_00608de0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x717,in_ECX + 0xe8);
  FUN_0078fb9c(param_1,0x77e,in_ECX + 0x168);
  FUN_0078fb9c(param_1,0x96c,in_ECX + 0x1e8);
  FUN_0078fb9c(param_1,0x77f,in_ECX + 0x268);
  FUN_0078fb9c(param_1,0x70a,in_ECX + 0x2e8);
  FUN_0078fb9c(param_1,0x70c,in_ECX + 0x368);
  FUN_0078fb9c(param_1,0x70d,in_ECX + 1000);
  FUN_0078fb9c(param_1,0x70e,in_ECX + 0x468);
  FUN_0078fb9c(param_1,0x70f,in_ECX + 0x4e8);
  FUN_0078fb9c(param_1,0x710,in_ECX + 0x568);
  FUN_0078fb9c(param_1,0x711,in_ECX + 0x5e8);
  FUN_0078fb9c(param_1,0x712,in_ECX + 0x668);
  FUN_0078fb9c(param_1,0x713,in_ECX + 0x6e8);
  FUN_0078fb9c(param_1,0x714,in_ECX + 0x768);
  FUN_0078fb9c(param_1,0x715,in_ECX + 0x7e8);
  FUN_0078fb9c(param_1,0x716,in_ECX + 0x868);
  FUN_0078fb9c(param_1,0x97d,in_ECX + 0x8e8);
  FUN_0078fb9c(param_1,0x97e,in_ECX + 0x968);
  FUN_0078fb9c(param_1,0x97f,in_ECX + 0x9e8);
  FUN_0078fb9c(param_1,0x980,in_ECX + 0xa68);
  FUN_0078fb9c(param_1,0x981,in_ECX + 0xae8);
  FUN_0078fb9c(param_1,0x982,in_ECX + 0xb68);
  FUN_0078fb9c(param_1,0x70b,in_ECX + 0xbe8);
  FUN_0078fb9c(param_1,0x718,in_ECX + 0xc68);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0xce8);
  FUN_0078fb9c(param_1,0x97b,in_ECX + 0xd68);
  FUN_0078fb9c(param_1,0x728,in_ECX + 0xde8);
  FUN_0078fb9c(param_1,0x729,in_ECX + 0xe68);
  FUN_0078fb9c(param_1,0x97c,in_ECX + 0xee8);
  FUN_0078fb9c(param_1,0x719,in_ECX + 0xf68);
  FUN_0078fb9c(param_1,0x71a,in_ECX + 0xfe8);
  FUN_0078fb9c(param_1,0x71b,in_ECX + 0x1068);
  FUN_0078fb9c(param_1,0x71c,in_ECX + 0x10e8);
  FUN_0078fb9c(param_1,0x72a,in_ECX + 0x1168);
  FUN_0078fb9c(param_1,0x71e,in_ECX + 0x11e8);
  FUN_0078fb9c(param_1,0x71f,in_ECX + 0x1268);
  FUN_0078fb9c(param_1,0x720,in_ECX + 0x12e8);
  FUN_0078fb9c(param_1,0x721,in_ECX + 0x1368);
  FUN_0078fb9c(param_1,0x722,in_ECX + 0x13e8);
  FUN_0078fb9c(param_1,0x97a,in_ECX + 0x1468);
  FUN_0078fb9c(param_1,0x727,in_ECX + 0x14e8);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x1568);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x15e8);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0x1668);
  FUN_0078f6f8(param_1,0x70a,in_ECX + 0x16e8);
  FUN_0078f6f8(param_1,0x70c,in_ECX + 0x16ec);
  FUN_0078f6f8(param_1,0x70d,in_ECX + 0x16f0);
  FUN_0078f6f8(param_1,0x70e,in_ECX + 0x16f4);
  FUN_0078f6f8(param_1,0x70f,in_ECX + 0x16f8);
  FUN_0078f6f8(param_1,0x710,in_ECX + 0x16fc);
  FUN_0078f6f8(param_1,0x711,in_ECX + 0x1700);
  FUN_0078f6f8(param_1,0x712,in_ECX + 0x1704);
  FUN_0078f6f8(param_1,0x713,in_ECX + 0x1708);
  FUN_0078f6f8(param_1,0x714,in_ECX + 0x170c);
  FUN_0078f6f8(param_1,0x715,in_ECX + 0x1710);
  FUN_0078f6f8(param_1,0x716,in_ECX + 0x1714);
  FUN_0078f6f8(param_1,0x97d,in_ECX + 0x1718);
  FUN_0078f6f8(param_1,0x97e,in_ECX + 0x171c);
  FUN_0078f6f8(param_1,0x97f,in_ECX + 0x1720);
  FUN_0078f6f8(param_1,0x980,in_ECX + 0x1724);
  FUN_0078f6f8(param_1,0x981,in_ECX + 0x1728);
  FUN_0078f6f8(param_1,0x982,in_ECX + 0x172c);
  FUN_0078f6f8(param_1,0x70b,in_ECX + 0x1730);
  FUN_0078f6f8(param_1,0x718,in_ECX + 0x1734);
  FUN_0078f6f8(param_1,0x97b,in_ECX + 0x1738);
  FUN_0078f6f8(param_1,0x728,in_ECX + 0x173c);
  FUN_0078f6f8(param_1,0x729,in_ECX + 0x1740);
  FUN_0078f6f8(param_1,0x97c,in_ECX + 0x1744);
  FUN_0078f6f8(param_1,0x719,in_ECX + 0x1748);
  FUN_0078f6f8(param_1,0x71a,in_ECX + 0x174c);
  FUN_0078f6f8(param_1,0x71b,in_ECX + 0x1750);
  FUN_0078f6f8(param_1,0x71c,in_ECX + 0x1754);
  FUN_0078f6f8(param_1,0x72a,in_ECX + 0x1758);
  FUN_0078f6f8(param_1,0x71e,in_ECX + 0x175c);
  FUN_0078f6f8(param_1,0x71f,in_ECX + 0x1760);
  FUN_0078f6f8(param_1,0x720,in_ECX + 0x1764);
  FUN_0078f6f8(param_1,0x721,in_ECX + 0x1768);
  FUN_0078f6f8(param_1,0x722,in_ECX + 0x176c);
  FUN_0078f6f8(param_1,0x97a,in_ECX + 6000);
  FUN_0078f6f8(param_1,0x727,in_ECX + 0x1774);
  FUN_0078f6f8(param_1,0x717,in_ECX + 0x1778);
  FUN_0078f6f8(param_1,0x96c,in_ECX + 0x177c);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x1780);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0x1784);
  FUN_00608430(*(undefined4 *)(in_ECX + 0xb0));
  return;
}




/* vtable slots: CZokuseiSelHenkouDialog[10] */
/* 006095d0  FUN_006095d0  16 bytes, 0 callers */

void FUN_006095d0(void)

{
  FUN_00609740();
  return;
}




/* vtable slots: CZokuseiSelHenkouDialog[94] */
/* 0060abb0  FUN_0060abb0  225 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0060abb0(void)

{
  int iVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00798993();
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar1 = FUN_00517b40(DAT_00a0c13c,DAT_00a0c140,local_18,local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    iVar1 = FUN_004f74b0(0x2c);
    iVar1 = iVar1 + local_20;
    iVar2 = FUN_004f72f0(0x87);
    FUN_004dbab0(iVar2 + local_24,iVar1);
  }
  *(undefined4 *)(local_1c + 0xac) = 0;
  return 1;
}



