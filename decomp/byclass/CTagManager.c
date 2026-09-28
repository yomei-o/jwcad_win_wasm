/* CTagManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTagManager[4] */
/* 0054004e  FUN_0054004e  4319 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0054004e(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  char in_SF;
  char in_OF;
  
  if ((in_OF != in_SF) &&
     ((*(double *)(unaff_EBP + 0x14) != 0.0 || (*(double *)(unaff_EBP + 0x1c) != 0.0)))) {
    *(double *)(unaff_EBP + -0x65a4) = *(double *)(unaff_EBP + 0x14) * 100.0;
    *(double *)(unaff_EBP + -0x65c4) = *(double *)(unaff_EBP + 0x1c) * 100.0;
    *(double *)(unaff_EBP + -0x65ac) =
         *(double *)(*(int *)(unaff_EBP + -0x64c4) + 0x3ec0) * *(double *)(unaff_EBP + -0x65c4) -
         *(double *)(*(int *)(unaff_EBP + -0x64c4) + 0x7e08) * *(double *)(unaff_EBP + -0x65a4);
    if (*(double *)(unaff_EBP + -0x65ac) <= 1e-05) {
      if (*(int *)(unaff_EBP + 0x10) < 0) {
        *(undefined4 *)(unaff_EBP + -0x64cc) = 1;
        while (*(int *)(unaff_EBP + -0x64cc) <= *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x2770c)) {
          *(undefined4 *)
           (*(int *)(unaff_EBP + -0x64c4) + 0x280bc + *(int *)(unaff_EBP + -0x64cc) * 4) = 11000;
          *(int *)(unaff_EBP + -0x64cc) = *(int *)(unaff_EBP + -0x64cc) + 1;
        }
      }
      if (*(int *)(unaff_EBP + 0x10) == 0) {
        *(undefined4 *)(unaff_EBP + -0x64cc) = 1;
        while (*(int *)(unaff_EBP + -0x64cc) < 0x7919) {
          *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x280bc + *(int *)(unaff_EBP + -0x64cc) * 4) =
               *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x280bc + *(int *)(unaff_EBP + -0x64cc) * 4)
               + 1;
          *(int *)(unaff_EBP + -0x64cc) = *(int *)(unaff_EBP + -0x64cc) + 1;
        }
      }
      *(undefined4 *)(unaff_EBP + -0x659c) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0041fd70();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0041fd70();
      uVar2 = *(undefined4 *)(unaff_EBP + -0x659c);
      goto LAB_00541111;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x64cc) = 1;
  while (*(int *)(unaff_EBP + -0x64cc) <= *(int *)(unaff_EBP + 0x28)) {
    if (*(double *)(*(int *)(unaff_EBP + -0x64c4) + 0x7e98 + *(int *)(unaff_EBP + -0x64cc) * 8) <=
        0.0) {
      *(undefined4 *)(unaff_EBP + -0x6514) = 0;
    }
    else {
      *(int *)(unaff_EBP + -0x6514) =
           (int)*(double *)
                 (*(int *)(unaff_EBP + -0x64c4) + 0x7e98 + *(int *)(unaff_EBP + -0x64cc) * 8);
    }
    *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 + *(int *)(unaff_EBP + -0x64cc) * 4) =
         (int)((double)*(int *)(unaff_EBP + -0x6514) * *(double *)(unaff_EBP + 0x14) +
              *(double *)(*(int *)(unaff_EBP + -0x64c4) + 8 + *(int *)(unaff_EBP + -0x64cc) * 8));
    *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc + *(int *)(unaff_EBP + -0x64cc) * 4) =
         (int)((double)*(int *)(unaff_EBP + -0x6514) * *(double *)(unaff_EBP + 0x1c) +
              *(double *)
               (*(int *)(unaff_EBP + -0x64c4) + 0x3f50 + *(int *)(unaff_EBP + -0x64cc) * 8));
    *(int *)(unaff_EBP + -0x64cc) = *(int *)(unaff_EBP + -0x64cc) + 1;
  }
  FUN_00548950();
  *(undefined4 *)(unaff_EBP + -0x64c8) = *(undefined4 *)(*(int *)(unaff_EBP + -0x64c4) + 0x2675c);
  *(undefined4 *)(unaff_EBP + -0x64c8) =
       *(undefined4 *)(*(int *)(unaff_EBP + -0x64c4) + 0x257a4 + *(int *)(unaff_EBP + -0x64c8) * 4);
  *(int *)(unaff_EBP + -0x64e4) = *(int *)(unaff_EBP + 0x28) + 1;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 + *(int *)(unaff_EBP + -0x64e4) * 4) =
       *(undefined4 *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 + *(int *)(unaff_EBP + -0x64c8) * 4);
  *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc + *(int *)(unaff_EBP + -0x64e4) * 4) =
       *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc + *(int *)(unaff_EBP + -0x64c8) * 4) + -100;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x64c4) + 0x1bb04 + *(int *)(unaff_EBP + 0x24) * 4) =
       *(undefined4 *)(unaff_EBP + -0x64e4);
  *(undefined4 *)(unaff_EBP + -0x6520) = 0;
  *(undefined4 *)(unaff_EBP + -0x6518) = 0;
  *(undefined4 *)(unaff_EBP + -0x64e0) = 1;
  while (*(int *)(unaff_EBP + -0x64e0) <= *(int *)(unaff_EBP + 0x2c)) {
    *(undefined4 *)(unaff_EBP + -0x64c8) =
         *(undefined4 *)
          (*(int *)(unaff_EBP + -0x64c4) + 0x26758 + *(int *)(unaff_EBP + -0x64e0) * 4);
    if (0 < *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x257a4 + *(int *)(unaff_EBP + -0x64c8) * 4)) {
      *(undefined4 *)(*(int *)(unaff_EBP + -0x64c4) + 0x1f9ac + *(int *)(unaff_EBP + 0x24) * 4) =
           *(undefined4 *)
            (*(int *)(unaff_EBP + -0x64c4) + 0x257a4 + *(int *)(unaff_EBP + -0x64c8) * 4);
      *(undefined4 *)(unaff_EBP + -0x64d8) = *(undefined4 *)(unaff_EBP + -0x64e4);
      *(undefined4 *)(unaff_EBP + -0x64d4) =
           *(undefined4 *)
            (*(int *)(unaff_EBP + -0x64c4) + 0x257a4 + *(int *)(unaff_EBP + -0x64c8) * 4);
      *(undefined4 *)(unaff_EBP + -0x651c) = 1;
      FUN_005484a0();
      if (*(int *)(unaff_EBP + -0x650c) != *(int *)(unaff_EBP + -0x64e4)) {
        *(undefined4 *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 + *(int *)(unaff_EBP + -0x64dc) * 4)
             = *(undefined4 *)
                (*(int *)(unaff_EBP + -0x64c4) + 0xfd28 + *(int *)(unaff_EBP + -0x64d4) * 4);
        *(undefined4 *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc + *(int *)(unaff_EBP + -0x64dc) * 4)
             = *(undefined4 *)
                (*(int *)(unaff_EBP + -0x64c4) + 0x11ccc + *(int *)(unaff_EBP + -0x64d4) * 4);
        *(double *)(unaff_EBP + -0x6528) =
             (double)*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                             *(int *)(unaff_EBP + -0x64dc) * 4) * *(double *)(unaff_EBP + -0x6568);
        *(double *)(unaff_EBP + -0x6530) =
             (double)*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                             *(int *)(unaff_EBP + -0x64dc) * 4) * *(double *)(unaff_EBP + -0x6568);
        *(undefined8 *)(unaff_EBP + -0x6500) = *(undefined8 *)(unaff_EBP + -0x6528);
        *(undefined8 *)(unaff_EBP + -0x64f8) = *(undefined8 *)(unaff_EBP + -0x6530);
        if (*(int *)(unaff_EBP + 0x38) != 0) {
          *(undefined8 *)(unaff_EBP + -0xe8) =
               *(undefined8 *)(*(int *)(unaff_EBP + -0x64c4) + 0x3ea8);
          *(undefined8 *)(unaff_EBP + -0xe0) =
               *(undefined8 *)(*(int *)(unaff_EBP + -0x64c4) + 0x7df0);
          *(undefined8 *)(unaff_EBP + -0xd8) =
               *(undefined8 *)(*(int *)(unaff_EBP + -0x64c4) + 0x3eb0);
          *(undefined8 *)(unaff_EBP + -0xd0) =
               *(undefined8 *)(*(int *)(unaff_EBP + -0x64c4) + 0x7df8);
          FUN_00545fc0(unaff_EBP + -0xf0,*(undefined8 *)(unaff_EBP + -0x6528),
                       *(undefined8 *)(unaff_EBP + -0x6530),*(undefined8 *)(unaff_EBP + 0x14),
                       *(undefined8 *)(unaff_EBP + 0x1c),unaff_EBP + -0x6500,unaff_EBP + -0x64f8,
                       unaff_EBP + -0x6550);
        }
        do {
          if (1999 < *(int *)(unaff_EBP + -0x6518)) {
            *(undefined4 *)(unaff_EBP + -0x6598) = 0xfffffffe;
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_0041fd70();
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_0041fd70();
            uVar2 = *(undefined4 *)(unaff_EBP + -0x6598);
            goto LAB_00541111;
          }
          *(int *)(unaff_EBP + -0x6518) = *(int *)(unaff_EBP + -0x6518) + 1;
          *(undefined4 *)
           (*(int *)(unaff_EBP + -0x64c4) + 0xfd28 + *(int *)(unaff_EBP + -0x64f0) * 4) =
               *(undefined4 *)
                (*(int *)(unaff_EBP + -0x64c4) + 0xfd28 + *(int *)(unaff_EBP + -0x64dc) * 4);
          *(undefined4 *)
           (*(int *)(unaff_EBP + -0x64c4) + 0x11ccc + *(int *)(unaff_EBP + -0x64f0) * 4) =
               *(undefined4 *)
                (*(int *)(unaff_EBP + -0x64c4) + 0x11ccc + *(int *)(unaff_EBP + -0x64dc) * 4);
          *(undefined8 *)(unaff_EBP + -0x65b4) = *(undefined8 *)(unaff_EBP + -0x6528);
          *(undefined8 *)(unaff_EBP + -0x65bc) = *(undefined8 *)(unaff_EBP + -0x6530);
          *(undefined4 *)(unaff_EBP + -0x6570) = *(undefined4 *)(unaff_EBP + -0x64d8);
          *(undefined4 *)(unaff_EBP + -0x6574) = *(undefined4 *)(unaff_EBP + -0x64d4);
          *(undefined4 *)(unaff_EBP + -26000) = *(undefined4 *)(unaff_EBP + -0x651c);
          *(undefined4 *)(unaff_EBP + -0x64d8) = *(undefined4 *)(unaff_EBP + -0x653c);
          *(undefined4 *)(unaff_EBP + -0x64d4) = *(undefined4 *)(unaff_EBP + -0x650c);
          *(undefined4 *)(unaff_EBP + -0x6594) = *(undefined4 *)(unaff_EBP + -0x6538);
          *(undefined4 *)(unaff_EBP + -0x651c) = *(undefined4 *)(unaff_EBP + -0x6534);
          FUN_00546790(*(undefined4 *)(unaff_EBP + -0x6570),*(undefined4 *)(unaff_EBP + -0x6574),
                       *(undefined4 *)(unaff_EBP + -26000),*(undefined4 *)(unaff_EBP + -0x64d8),
                       *(undefined4 *)(unaff_EBP + -0x64d4),*(undefined4 *)(unaff_EBP + -0x6594),
                       *(undefined4 *)(unaff_EBP + -0x651c),unaff_EBP + -0x653c,unaff_EBP + -0x650c,
                       unaff_EBP + -0x6538,unaff_EBP + -0x6534,*(undefined4 *)(unaff_EBP + -0x64e4),
                       *(int *)(unaff_EBP + 0x24) + 1);
          *(double *)(unaff_EBP + -0x6528) =
               (double)*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                               *(int *)(unaff_EBP + -0x64dc) * 4) * *(double *)(unaff_EBP + -0x6568)
          ;
          *(double *)(unaff_EBP + -0x6530) =
               (double)*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                               *(int *)(unaff_EBP + -0x64dc) * 4) * *(double *)(unaff_EBP + -0x6568)
          ;
          if (*(int *)(unaff_EBP + 0x38) == 0) {
            *(undefined4 *)(unaff_EBP + -0x6504) = 0;
            *(undefined8 *)(unaff_EBP + -0x6558) = *(undefined8 *)(unaff_EBP + -0x65b4);
            *(undefined8 *)(unaff_EBP + -0x6560) = *(undefined8 *)(unaff_EBP + -0x65bc);
            *(undefined8 *)(unaff_EBP + -0x6500) = *(undefined8 *)(unaff_EBP + -0x6528);
            *(undefined8 *)(unaff_EBP + -0x64f8) = *(undefined8 *)(unaff_EBP + -0x6530);
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x6504) = 0;
            *(undefined8 *)(unaff_EBP + -0x6558) = *(undefined8 *)(unaff_EBP + -0x6500);
            *(undefined8 *)(unaff_EBP + -0x6560) = *(undefined8 *)(unaff_EBP + -0x64f8);
            *(undefined8 *)(unaff_EBP + -0x657c) = *(undefined8 *)(unaff_EBP + -0x6550);
            FUN_00545fc0(unaff_EBP + -0xf0,*(undefined8 *)(unaff_EBP + -0x6528),
                         *(undefined8 *)(unaff_EBP + -0x6530),*(undefined8 *)(unaff_EBP + 0x14),
                         *(undefined8 *)(unaff_EBP + 0x1c),unaff_EBP + -0x6584,unaff_EBP + -0x658c,
                         unaff_EBP + -0x6550);
            *(undefined8 *)(unaff_EBP + -0x6500) = *(undefined8 *)(unaff_EBP + -0x6584);
            *(undefined8 *)(unaff_EBP + -0x64f8) = *(undefined8 *)(unaff_EBP + -0x658c);
            if (((1.0 < *(double *)(unaff_EBP + -0x657c)) &&
                (*(double *)(unaff_EBP + -0x6550) <= -1.0 &&
                 *(double *)(unaff_EBP + -0x6550) != -1.0)) ||
               ((*(double *)(unaff_EBP + -0x657c) <= -1.0 &&
                 *(double *)(unaff_EBP + -0x657c) != -1.0 &&
                (1.0 < *(double *)(unaff_EBP + -0x6550))))) {
              *(undefined8 *)(unaff_EBP + -0x80) = *(undefined8 *)(unaff_EBP + -0x65b4);
              *(undefined8 *)(unaff_EBP + -0x78) = *(undefined8 *)(unaff_EBP + -0x65bc);
              *(undefined8 *)(unaff_EBP + -0x70) = *(undefined8 *)(unaff_EBP + -0x6528);
              *(undefined8 *)(unaff_EBP + -0x68) = *(undefined8 *)(unaff_EBP + -0x6530);
              FUN_00446aa0();
              *(undefined1 *)(unaff_EBP + -4) = 2;
              FUN_00408a60();
              iVar1 = FUN_004619b0(unaff_EBP + -0xf0,unaff_EBP + -0x88,
                                   *(undefined4 *)(unaff_EBP + -0x80),
                                   *(undefined4 *)(unaff_EBP + -0x7c),
                                   *(undefined4 *)(unaff_EBP + -0x78),
                                   *(undefined4 *)(unaff_EBP + -0x74),unaff_EBP + -0x20);
              if (iVar1 != 0) {
                *(undefined4 *)(unaff_EBP + -0x6504) = 1;
                *(undefined8 *)(unaff_EBP + -0x6500) = *(undefined8 *)(unaff_EBP + -0x20);
                *(undefined8 *)(unaff_EBP + -0x64f8) = *(undefined8 *)(unaff_EBP + -0x18);
              }
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_00447100();
            }
          }
          while( true ) {
            if (*(int *)(unaff_EBP + 0x10) == 0) {
              FUN_0053f410();
            }
            else {
              if (0 < *(int *)(unaff_EBP + 0x10)) {
                if ((0.01 < *(double *)
                             (*(int *)(unaff_EBP + -0x64c4) + 0x7e98 +
                             *(int *)(unaff_EBP + -0x64d8) * 8)) ||
                   (0.01 < *(double *)
                            (*(int *)(unaff_EBP + -0x64c4) + 0x7e98 +
                            *(int *)(unaff_EBP + -0x64d4) * 8))) {
                  iVar1 = FUN_0053f880(*(undefined4 *)(unaff_EBP + 8),
                                       *(undefined4 *)(unaff_EBP + 0xc),
                                       *(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + -0x6520,
                                       *(undefined8 *)(unaff_EBP + -0x6558),
                                       *(undefined8 *)(unaff_EBP + -0x6560),
                                       *(undefined8 *)(unaff_EBP + -0x6500),
                                       *(undefined8 *)(unaff_EBP + -0x64f8),
                                       *(undefined4 *)(unaff_EBP + 0x38));
                  if (iVar1 == 0) {
                    *(undefined4 *)(unaff_EBP + -0x6520) = 0;
                  }
                }
                else {
                  *(undefined4 *)(unaff_EBP + -0x6520) = 0;
                }
              }
              if (*(int *)(unaff_EBP + 0x10) < 0) {
                FUN_005487c0();
              }
            }
            if ((*(int *)(unaff_EBP + 0x38) == 0) || (*(int *)(unaff_EBP + -0x6504) == 0)) break;
            *(undefined4 *)(unaff_EBP + -0x6504) = 0;
            *(undefined8 *)(unaff_EBP + -0x6558) = *(undefined8 *)(unaff_EBP + -0x6500);
            *(undefined8 *)(unaff_EBP + -0x6560) = *(undefined8 *)(unaff_EBP + -0x64f8);
            *(undefined8 *)(unaff_EBP + -0x6500) = *(undefined8 *)(unaff_EBP + -0x6584);
            *(undefined8 *)(unaff_EBP + -0x64f8) = *(undefined8 *)(unaff_EBP + -0x658c);
          }
          if (*(int *)(unaff_EBP + -0x64e0) < *(int *)(unaff_EBP + 0x2c)) {
            *(undefined4 *)(unaff_EBP + -0x64c8) =
                 *(undefined4 *)
                  (*(int *)(unaff_EBP + -0x64c4) + 0x19b5c + *(int *)(unaff_EBP + -0x64d8) * 4);
            *(undefined4 *)
             (*(int *)(unaff_EBP + -0x64c4) + 0x257a4 + *(int *)(unaff_EBP + -0x64c8) * 4) = 0;
            *(int *)(unaff_EBP + -0x6508) = *(int *)(unaff_EBP + -0x64e0) + 1;
            while (*(int *)(unaff_EBP + -0x6508) <= *(int *)(unaff_EBP + 0x2c)) {
              *(undefined4 *)(unaff_EBP + -0x64c8) =
                   *(undefined4 *)
                    (*(int *)(unaff_EBP + -0x64c4) + 0x26758 + *(int *)(unaff_EBP + -0x6508) * 4);
              if (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x257a4 +
                          *(int *)(unaff_EBP + -0x64c8) * 4) != 0) {
                *(undefined4 *)(unaff_EBP + -0x64d0) =
                     *(undefined4 *)
                      (*(int *)(unaff_EBP + -0x64c4) + 0x257a4 + *(int *)(unaff_EBP + -0x64c8) * 4);
                if (*(int *)(unaff_EBP + -0x64d0) < 1) {
                  *(int *)(unaff_EBP + -0x6540) = -*(int *)(unaff_EBP + -0x64d0);
                }
                else {
                  *(undefined4 *)(unaff_EBP + -0x6540) = *(undefined4 *)(unaff_EBP + -0x64d0);
                }
                *(undefined4 *)(unaff_EBP + -0x64d0) = *(undefined4 *)(unaff_EBP + -0x6540);
                if (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x13c70 +
                            *(int *)(unaff_EBP + -0x64d0) * 4) == 0) {
                  *(int *)(unaff_EBP + -0x64e8) =
                       *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                               *(int *)(unaff_EBP + -0x64d4) * 4) -
                       *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                               *(int *)(unaff_EBP + -0x64d8) * 4);
                  *(int *)(unaff_EBP + -0x64ec) =
                       *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                               *(int *)(unaff_EBP + -0x64d4) * 4) -
                       *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                               *(int *)(unaff_EBP + -0x64d8) * 4);
                  if ((*(int *)(unaff_EBP + -0x64e8) != 0) || (*(int *)(unaff_EBP + -0x64ec) != 0))
                  {
                    if (*(int *)(unaff_EBP + -0x64e8) < 1) {
                      *(int *)(unaff_EBP + -0x6544) = -*(int *)(unaff_EBP + -0x64e8);
                    }
                    else {
                      *(undefined4 *)(unaff_EBP + -0x6544) = *(undefined4 *)(unaff_EBP + -0x64e8);
                    }
                    if (*(int *)(unaff_EBP + -0x64ec) < 1) {
                      *(int *)(unaff_EBP + -0x6548) = -*(int *)(unaff_EBP + -0x64ec);
                    }
                    else {
                      *(undefined4 *)(unaff_EBP + -0x6548) = *(undefined4 *)(unaff_EBP + -0x64ec);
                    }
                    if (*(int *)(unaff_EBP + -0x6548) < *(int *)(unaff_EBP + -0x6544)) {
                      if (*(int *)(unaff_EBP + -0x64e8) < 1) {
                        if ((*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                                     *(int *)(unaff_EBP + -0x64d4) * 4) <=
                             *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                                     *(int *)(unaff_EBP + -0x64d0) * 4)) &&
                           (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                                    *(int *)(unaff_EBP + -0x64d0) * 4) <=
                            *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                                    *(int *)(unaff_EBP + -0x64d8) * 4))) goto LAB_00540ed4;
                      }
                      else if ((*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                                        *(int *)(unaff_EBP + -0x64d8) * 4) <=
                                *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                                        *(int *)(unaff_EBP + -0x64d0) * 4)) &&
                              (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                                       *(int *)(unaff_EBP + -0x64d0) * 4) <=
                               *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0xfd28 +
                                       *(int *)(unaff_EBP + -0x64d4) * 4))) {
LAB_00540ed4:
                        *(undefined4 *)
                         (*(int *)(unaff_EBP + -0x64c4) + 0x257a4 +
                         *(int *)(unaff_EBP + -0x64c8) * 4) = 0;
                      }
                    }
                    else if (*(int *)(unaff_EBP + -0x64ec) < 1) {
                      if ((*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                   *(int *)(unaff_EBP + -0x64d4) * 4) <=
                           *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                   *(int *)(unaff_EBP + -0x64d0) * 4)) &&
                         (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                  *(int *)(unaff_EBP + -0x64d0) * 4) <=
                          *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                  *(int *)(unaff_EBP + -0x64d8) * 4))) goto LAB_00540ed4;
                    }
                    else if ((*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                      *(int *)(unaff_EBP + -0x64d8) * 4) <=
                              *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                      *(int *)(unaff_EBP + -0x64d0) * 4)) &&
                            (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                     *(int *)(unaff_EBP + -0x64d0) * 4) <=
                             *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                     *(int *)(unaff_EBP + -0x64d4) * 4))) goto LAB_00540ed4;
                  }
                }
                else if (((*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                   *(int *)(unaff_EBP + -0x64f0) * 4) <
                           *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                   *(int *)(unaff_EBP + -0x64d0) * 4)) ||
                         (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                  *(int *)(unaff_EBP + -0x64dc) * 4) <
                          *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                  *(int *)(unaff_EBP + -0x64d0) * 4))) &&
                        ((*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                  *(int *)(unaff_EBP + -0x64d0) * 4) <=
                          *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                  *(int *)(unaff_EBP + -0x64f0) * 4) ||
                         (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                  *(int *)(unaff_EBP + -0x64d0) * 4) <=
                          *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                                  *(int *)(unaff_EBP + -0x64dc) * 4))))) {
                  if (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                              *(int *)(unaff_EBP + -0x64f0) * 4) <
                      *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x11ccc +
                              *(int *)(unaff_EBP + -0x64dc) * 4)) {
                    if (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x13c70 +
                                *(int *)(unaff_EBP + -0x64d0) * 4) < 1) {
                      *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x257a4 +
                              *(int *)(unaff_EBP + -0x64c8) * 4) =
                           -*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x257a4 +
                                    *(int *)(unaff_EBP + -0x64c8) * 4);
                    }
                  }
                  else if (0 < *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x13c70 +
                                       *(int *)(unaff_EBP + -0x64d0) * 4)) {
                    *(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x257a4 +
                            *(int *)(unaff_EBP + -0x64c8) * 4) =
                         -*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x257a4 +
                                  *(int *)(unaff_EBP + -0x64c8) * 4);
                  }
                }
              }
              *(int *)(unaff_EBP + -0x6508) = *(int *)(unaff_EBP + -0x6508) + 1;
            }
          }
        } while (*(int *)(unaff_EBP + -0x650c) < *(int *)(unaff_EBP + -0x64e4));
        if (*(int *)(unaff_EBP + -0x64e0) < *(int *)(unaff_EBP + 0x2c)) {
          *(int *)(unaff_EBP + -0x6510) = *(int *)(unaff_EBP + -0x64e0) + 1;
          while (*(int *)(unaff_EBP + -0x6510) <= *(int *)(unaff_EBP + 0x2c)) {
            *(undefined4 *)(unaff_EBP + -0x64c8) =
                 *(undefined4 *)
                  (*(int *)(unaff_EBP + -0x64c4) + 0x26758 + *(int *)(unaff_EBP + -0x6510) * 4);
            if (*(int *)(*(int *)(unaff_EBP + -0x64c4) + 0x257a4 + *(int *)(unaff_EBP + -0x64c8) * 4
                        ) < 1) {
              *(undefined4 *)
               (*(int *)(unaff_EBP + -0x64c4) + 0x257a4 + *(int *)(unaff_EBP + -0x64c8) * 4) = 0;
            }
            *(int *)(unaff_EBP + -0x6510) = *(int *)(unaff_EBP + -0x6510) + 1;
          }
        }
      }
    }
    *(int *)(unaff_EBP + -0x64e0) = *(int *)(unaff_EBP + -0x64e0) + 1;
  }
  *(undefined4 *)(unaff_EBP + -0x656c) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0041fd70();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0041fd70();
  uVar2 = *(undefined4 *)(unaff_EBP + -0x656c);
LAB_00541111:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}




/* vtable slots: CTagManager[1] */
/* 0081998f  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CTagManager::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CTagManager::_scalar_deleting_destructor_(CTagManager *this,uint param_1)

{
  ~CTagManager(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,8);
    }
  }
  return this;
}



