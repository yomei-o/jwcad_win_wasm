/* CUserDefinedLTypeDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CUserDefinedLTypeDialog[1] */
/* 005f74c0  FUN_005f74c0  68 bytes, 0 callers */

undefined4 FUN_005f74c0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0049cdb0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x560);
    }
  }
  return in_ECX;
}




/* vtable slots: CUserDefinedLTypeDialog[64] */
/* 005f7fd0  FUN_005f7fd0  475 bytes, 0 callers */

void FUN_005f7fd0(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x5d3,in_ECX + 0x110);
  FUN_0078fb9c(param_1,0x5d4,in_ECX + 400);
  FUN_0078fb9c(param_1,0x5d5,in_ECX + 0x210);
  FUN_0078fb9c(param_1,0x5d6,in_ECX + 0x290);
  FUN_0078fb9c(param_1,0x8a7,in_ECX + 0x310);
  FUN_0078fb9c(param_1,0x8a8,in_ECX + 0x390);
  FUN_0078fb9c(param_1,0x5d7,in_ECX + 0x410);
  FUN_0078fb9c(param_1,0x5d8,in_ECX + 0x490);
  DDX_Text(param_1,0x5d3,(double *)(in_ECX + 0x510));
  DDX_Text(param_1,0x5d4,(double *)(in_ECX + 0x518));
  DDX_Text(param_1,0x5d5,(double *)(in_ECX + 0x520));
  DDX_Text(param_1,0x5d6,(double *)(in_ECX + 0x528));
  DDX_Text(param_1,0x8a7,(double *)(in_ECX + 0x530));
  DDX_Text(param_1,0x8a8,(double *)(in_ECX + 0x538));
  DDX_Text(param_1,0x5d7,(double *)(in_ECX + 0x540));
  DDX_Text(param_1,0x5d8,(double *)(in_ECX + 0x548));
  FUN_0078f801(param_1,0x5db,in_ECX + 0x550);
  FUN_0078f5ed(param_1,0x909,in_ECX + 0x554);
  FUN_0078f643(param_1,0x583,in_ECX + 0x558);
  return;
}




/* vtable slots: CUserDefinedLTypeDialog[10] */
/* 005f8260  FUN_005f8260  16 bytes, 0 callers */

void FUN_005f8260(void)

{
  FUN_005f8270();
  return;
}




/* vtable slots: CUserDefinedLTypeDialog[94] */
/* 005f8280  FUN_005f8280  40 bytes, 0 callers */

undefined4 FUN_005f8280(void)

{
  FUN_00798993();
  FUN_005f81b0();
  FUN_005f7510();
  return 1;
}




/* vtable slots: CUserDefinedLTypeDialog[96] */
/* 005f82d0  FUN_005f82d0  135 bytes, 0 callers */

void FUN_005f82d0(void)

{
  double *pdVar1;
  int in_ECX;
  undefined4 local_c;
  
  FUN_007955d2(1);
  for (local_c = 1; local_c <= *(int *)(in_ECX + 0x108); local_c = local_c + 1) {
    pdVar1 = *(double **)(in_ECX + 0xa8 + local_c * 4);
    if (*pdVar1 <= 0.01 && *pdVar1 != 0.01) {
      **(undefined8 **)(in_ECX + 0xa8 + local_c * 4) = 0x3f847ae147ae147b;
    }
  }
  FUN_007955d2(0);
  FUN_005f7510();
  FUN_00798a09();
  return;
}



