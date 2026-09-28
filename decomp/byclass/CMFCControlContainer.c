/* CMFCControlContainer -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCControlContainer[3], CMFCToolBarCmdUI[4], PAU1::PAU_ITEMIDLIST::?$CList[3] */
/* 0046004d  FUN_0046004d  623 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_0046004d(void)

{
  int iVar1;
  undefined4 in_EDX;
  int unaff_EBP;
  
code_r0x0046004d:
  *(undefined4 *)(unaff_EBP + -0x274) = in_EDX;
  FUN_004988c0(unaff_EBP + -0x170,*(undefined4 *)(unaff_EBP + -0x158),
               *(undefined4 *)(unaff_EBP + -0x154),*(undefined4 *)(unaff_EBP + -0x150),
               *(undefined4 *)(unaff_EBP + -0x14c));
  FUN_004988c0(unaff_EBP + -0x210,*(undefined4 *)(unaff_EBP + -0x30),
               *(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28),
               *(undefined4 *)(unaff_EBP + -0x24));
  if (*(int *)(unaff_EBP + -0x288) == 3) {
    if (*(int *)(unaff_EBP + -0x298) == 0) {
      FUN_004988c0(unaff_EBP + -0x200,*(undefined4 *)(unaff_EBP + -0x50),
                   *(undefined4 *)(unaff_EBP + -0x4c),*(undefined4 *)(unaff_EBP + -0x48),
                   *(undefined4 *)(unaff_EBP + -0x44));
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x274) = 0;
    }
  }
  do {
    if ((*(int *)(unaff_EBP + -0x274) != 0) &&
       (iVar1 = FUN_0045fa30(*(undefined4 *)(unaff_EBP + -0x274),*(undefined4 *)(unaff_EBP + -0x27c)
                             ,*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                             *(undefined4 *)(unaff_EBP + 0x18),*(undefined4 *)(unaff_EBP + 0x1c),
                             unaff_EBP + -0x20), iVar1 == 1)) {
      if (*(double *)(unaff_EBP + 0x10) - *(double *)(unaff_EBP + -0x20) <= 0.0) {
        *(double *)(unaff_EBP + -0x2fc) =
             -(*(double *)(unaff_EBP + 0x10) - *(double *)(unaff_EBP + -0x20));
      }
      else {
        *(double *)(unaff_EBP + -0x2fc) =
             *(double *)(unaff_EBP + 0x10) - *(double *)(unaff_EBP + -0x20);
      }
      if (*(double *)(unaff_EBP + 0x18) - *(double *)(unaff_EBP + -0x18) <= 0.0) {
        *(double *)(unaff_EBP + -0x2ec) =
             -(*(double *)(unaff_EBP + 0x18) - *(double *)(unaff_EBP + -0x18));
      }
      else {
        *(double *)(unaff_EBP + -0x2ec) =
             *(double *)(unaff_EBP + 0x18) - *(double *)(unaff_EBP + -0x18);
      }
      *(double *)(unaff_EBP + -0x2e4) =
           *(double *)(unaff_EBP + -0x2fc) + *(double *)(unaff_EBP + -0x2ec);
      if (*(double *)(unaff_EBP + -0x2e4) <= *(double *)(unaff_EBP + -0x2b0) &&
          *(double *)(unaff_EBP + -0x2b0) != *(double *)(unaff_EBP + -0x2e4)) {
        *(undefined4 *)(unaff_EBP + -0x290) = 1;
        *(undefined8 *)(unaff_EBP + -0x2b0) = *(undefined8 *)(unaff_EBP + -0x2e4);
        FUN_004988c0(unaff_EBP + -0x1f0,*(undefined4 *)(unaff_EBP + -0x20),
                     *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18),
                     *(undefined4 *)(unaff_EBP + -0x14));
      }
    }
    *(int *)(unaff_EBP + -0x280) = *(int *)(unaff_EBP + -0x280) + 1;
    if (*(int *)(unaff_EBP + -0x288) < *(int *)(unaff_EBP + -0x280)) {
      *(undefined4 *)(unaff_EBP + -0x2c0) = *(undefined4 *)(unaff_EBP + -0x290);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0041fd50();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0041fd70();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return *(undefined4 *)(unaff_EBP + -0x2c0);
    }
    *(undefined4 *)(unaff_EBP + -0x274) = 0;
    *(undefined4 *)(unaff_EBP + -0x2a0) = *(undefined4 *)(unaff_EBP + -0x280);
    switch(*(undefined4 *)(unaff_EBP + -0x2a0)) {
    case 0:
      *(int *)(unaff_EBP + -0x274) = unaff_EBP + -0x160;
      break;
    case 1:
      *(undefined4 *)(unaff_EBP + -0x274) = *(undefined4 *)(unaff_EBP + -0x294);
      FUN_004988c0(unaff_EBP + -0x250,*(undefined4 *)(unaff_EBP + -0x158),
                   *(undefined4 *)(unaff_EBP + -0x154),*(undefined4 *)(unaff_EBP + -0x150),
                   *(undefined4 *)(unaff_EBP + -0x14c));
      FUN_004988c0(unaff_EBP + -0x240,*(undefined4 *)(unaff_EBP + -0x60),
                   *(undefined4 *)(unaff_EBP + -0x5c),*(undefined4 *)(unaff_EBP + -0x58),
                   *(undefined4 *)(unaff_EBP + -0x54));
      iVar1 = FUN_0040c120();
      if (iVar1 == 1) {
        FUN_004988c0(unaff_EBP + -0x230,*(undefined4 *)(unaff_EBP + -0x30),
                     *(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28),
                     *(undefined4 *)(unaff_EBP + -0x24));
      }
      if (*(int *)(unaff_EBP + -0x288) == 3) {
        if (*(int *)(unaff_EBP + -0x298) == 0) {
          FUN_004988c0(unaff_EBP + -0x220,*(undefined4 *)(unaff_EBP + -0x40),
                       *(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x38),
                       *(undefined4 *)(unaff_EBP + -0x34));
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x274) = 0;
        }
      }
      break;
    case 2:
      goto switchD_0045ff20_caseD_2;
    case 3:
      *(int *)(unaff_EBP + -0x274) = *(int *)(unaff_EBP + -0x278) + 0x1c0;
    }
  } while( true );
switchD_0045ff20_caseD_2:
  in_EDX = *(undefined4 *)(unaff_EBP + -0x294);
  goto code_r0x0046004d;
}




/* vtable slots: CMFCControlContainer[1] */
/* 007c1aa1  FUN_007c1aa1  48 bytes, 0 callers */

void FUN_007c1aa1(byte param_1)

{
  FUN_007c1a47();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}



