/* PAU1::PAU_ITEMIDLIST::?$CList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: PAU1::PAU_ITEMIDLIST::?$CList[4] */
/* 00530043  FUN_00530043  14777 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00530043(void)

{
  double *pdVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBP;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
code_r0x00530043:
  *(int *)(unaff_EBP + -0x84a4) = *(int *)(unaff_EBP + -0x84a4) % 100;
  if (9 < *(int *)(unaff_EBP + -0x84a4)) {
    DAT_00a0b3c8 = DAT_00a0b3c8 + 2;
  }
  *(int *)(unaff_EBP + -0x84a4) = *(int *)(unaff_EBP + -0x84a4) % 10;
  if (0 < *(int *)(unaff_EBP + -0x84a4)) {
    DAT_00a0b3c8 = DAT_00a0b3c8 + 1;
  }
  *(undefined4 *)(unaff_EBP + -0x84a4) = 0;
LAB_005300a5:
  if (((-1 < *(int *)(unaff_EBP + -0x855c)) && (*(int *)(unaff_EBP + -0x855c) < 2)) &&
     (DAT_00a0cb30 = 0, 0 < *(int *)(unaff_EBP + -0x855c))) {
    DAT_00a0cb30 = 1;
  }
  if ((-1 < *(int *)(unaff_EBP + -0x8548)) && (*(int *)(unaff_EBP + -0x8548) < 2)) {
    DAT_00a0cb50 = *(undefined4 *)(unaff_EBP + -0x8548);
  }
  if ((-1 < *(int *)(unaff_EBP + -0x8558)) && (*(int *)(unaff_EBP + -0x8558) < 2)) {
    DAT_00a0cb2c = *(undefined4 *)(unaff_EBP + -0x8558);
  }
LAB_0053010f:
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"CU_SET");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x84f4) = 0;
    *(undefined4 *)(unaff_EBP + -0x84f0) = *(undefined4 *)(unaff_EBP + -0x84f4);
    *(undefined4 *)(unaff_EBP + -0x84ec) = *(undefined4 *)(unaff_EBP + -0x84f0);
    *(undefined4 *)(unaff_EBP + -0x84b0) = *(undefined4 *)(unaff_EBP + -0x84ec);
    *(undefined4 *)(unaff_EBP + -0x84e8) = *(undefined4 *)(unaff_EBP + -0x84b0);
    *(undefined4 *)(unaff_EBP + -0x84e4) = *(undefined4 *)(unaff_EBP + -0x84e8);
    *(undefined4 *)(unaff_EBP + -0x8544) = *(undefined4 *)(unaff_EBP + -0x84e4);
    *(undefined4 *)(unaff_EBP + -0x85b0) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x85ac) = *(undefined4 *)(unaff_EBP + -0x85b0);
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                         unaff_EBP + -0x8544,unaff_EBP + -0x84e4,unaff_EBP + -0x84e8,
                         unaff_EBP + -0x84b0,unaff_EBP + -0x84ec,unaff_EBP + -0x84f0,
                         unaff_EBP + -0x84f4,unaff_EBP + -0x85ac,unaff_EBP + -0x85b0);
    if (iVar3 == 0) goto LAB_005293fd;
    if ((*(int *)(unaff_EBP + -0x8544) < 0) || (1 < *(int *)(unaff_EBP + -0x8544))) {
      *(undefined4 *)(unaff_EBP + -0x8544) = 0;
    }
    DAT_00a0be50 = *(undefined4 *)(unaff_EBP + -0x8544);
    if ((*(int *)(unaff_EBP + -0x84e4) < 0) || (1 < *(int *)(unaff_EBP + -0x84e4))) {
      *(undefined4 *)(unaff_EBP + -0x84e4) = 0;
    }
    DAT_00a0be54 = *(undefined4 *)(unaff_EBP + -0x84e4);
    if ((*(int *)(unaff_EBP + -0x84e8) < -1) || (4 < *(int *)(unaff_EBP + -0x84e8))) {
      *(undefined4 *)(unaff_EBP + -0x84e8) = 3;
    }
    DAT_00a0be58 = *(undefined4 *)(unaff_EBP + -0x84e8);
    if (*(int *)(unaff_EBP + -0x84b0) < 1) {
      *(int *)(unaff_EBP + -0x865c) = -*(int *)(unaff_EBP + -0x84b0);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x865c) = *(undefined4 *)(unaff_EBP + -0x84b0);
    }
    if (*(int *)(unaff_EBP + -0x865c) < 1) {
LAB_005302c5:
      *(undefined4 *)(unaff_EBP + -0x84b0) = 2;
    }
    else {
      if (*(int *)(unaff_EBP + -0x84b0) < 1) {
        *(int *)(unaff_EBP + -0x8660) = -*(int *)(unaff_EBP + -0x84b0);
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x8660) = *(undefined4 *)(unaff_EBP + -0x84b0);
      }
      if (10 < *(int *)(unaff_EBP + -0x8660)) goto LAB_005302c5;
    }
    DAT_00a0be5c = *(undefined4 *)(unaff_EBP + -0x84b0);
    if ((*(int *)(unaff_EBP + -0x84ec) < 0) || (1 < *(int *)(unaff_EBP + -0x84ec))) {
      *(undefined4 *)(unaff_EBP + -0x84ec) = 1;
    }
    DAT_00a0be60 = *(undefined4 *)(unaff_EBP + -0x84ec);
    if ((*(int *)(unaff_EBP + -0x84f0) < 0) || (1 < *(int *)(unaff_EBP + -0x84f0))) {
      *(undefined4 *)(unaff_EBP + -0x84f0) = 1;
    }
    DAT_00a0be64 = *(undefined4 *)(unaff_EBP + -0x84f0);
    if ((*(int *)(unaff_EBP + -0x84f4) < 0) || (2 < *(int *)(unaff_EBP + -0x84f4))) {
      *(undefined4 *)(unaff_EBP + -0x84f4) = 0;
    }
    DAT_00a0be68 = *(undefined4 *)(unaff_EBP + -0x84f4);
    if ((-1 < *(int *)(unaff_EBP + -0x85ac)) && (*(int *)(unaff_EBP + -0x85ac) < 2)) {
      DAT_00a0be6c = *(undefined4 *)(unaff_EBP + -0x85ac);
    }
    *(int *)(unaff_EBP + -0x84bc) = *(int *)(unaff_EBP + -0x85b0) % 10;
    if ((-1 < *(int *)(unaff_EBP + -0x84bc)) && (*(int *)(unaff_EBP + -0x84bc) < 2)) {
      DAT_00a0be70 = *(undefined4 *)(unaff_EBP + -0x84bc);
    }
    *(int *)(unaff_EBP + -0x84bc) = *(int *)(unaff_EBP + -0x85b0) / 10;
    *(int *)(unaff_EBP + -0x84bc) = *(int *)(unaff_EBP + -0x84bc) % 10;
    if ((-1 < *(int *)(unaff_EBP + -0x84bc)) && (*(int *)(unaff_EBP + -0x84bc) < 2)) {
      DAT_00a0be4c = *(undefined4 *)(unaff_EBP + -0x84bc);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"MS_SET");
  if (iVar3 == 0) {
    iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"HATCH_");
    if (iVar3 == 0) {
      iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LAYNAM_");
      if (iVar3 == 0) {
        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LAYCOL_");
        if (iVar3 == 0) {
          iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LAYWID_");
          if (iVar3 == 0) {
            iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LAYTYP_");
            if (iVar3 == 0) {
              iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LTYPE_HC");
              if (iVar3 == 0) {
                iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_LAY00");
                if (iVar3 == 0) {
                  *(undefined4 *)(unaff_EBP + -0x8494) = 0xffffffff;
                  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_LAY01");
                  if (iVar3 != 0) {
                    *(undefined4 *)(unaff_EBP + -0x8494) = 0;
                  }
                  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_LAY11");
                  if (iVar3 != 0) {
                    *(undefined4 *)(unaff_EBP + -0x8494) = 10;
                  }
                  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_LAY21");
                  if (iVar3 != 0) {
                    *(undefined4 *)(unaff_EBP + -0x8494) = 0x14;
                  }
                  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_LAY31");
                  if (iVar3 != 0) {
                    *(undefined4 *)(unaff_EBP + -0x8494) = 0x1e;
                  }
                  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_LAY41");
                  if (iVar3 != 0) {
                    *(undefined4 *)(unaff_EBP + -0x8494) = 0x28;
                  }
                  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_LAY51");
                  if (iVar3 != 0) {
                    *(undefined4 *)(unaff_EBP + -0x8494) = 0x32;
                  }
                  if (*(int *)(unaff_EBP + -0x8494) < 0) {
                    *(undefined4 *)(unaff_EBP + -0x8494) = 0xffffffff;
                    iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_RV01");
                    if (iVar3 != 0) {
                      *(undefined4 *)(unaff_EBP + -0x8494) = 0;
                    }
                    iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_RV11");
                    if (iVar3 != 0) {
                      *(undefined4 *)(unaff_EBP + -0x8494) = 10;
                    }
                    iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_RV21");
                    if (iVar3 != 0) {
                      *(undefined4 *)(unaff_EBP + -0x8494) = 0x14;
                    }
                    iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_RV31");
                    if (iVar3 != 0) {
                      *(undefined4 *)(unaff_EBP + -0x8494) = 0x1e;
                    }
                    iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_RV41");
                    if (iVar3 != 0) {
                      *(undefined4 *)(unaff_EBP + -0x8494) = 0x28;
                    }
                    iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_RV51");
                    if (iVar3 != 0) {
                      *(undefined4 *)(unaff_EBP + -0x8494) = 0x32;
                    }
                    if (*(int *)(unaff_EBP + -0x8494) < 0) {
                      iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"COM_RV_C");
                      if (iVar3 == 0) {
                        *(undefined4 *)(unaff_EBP + -0x8494) = 0xffffffff;
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LD_AM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 0;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LD_PM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 1;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"RD_AM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 2;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"RD_PM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 3;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LD1_AM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 0;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LD1_PM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 1;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"RD1_AM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 2;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"RD1_PM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 3;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LD2_AM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 4;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LD2_PM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 5;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"RD2_AM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 6;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"RD2_PM");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 7;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LD2_RV");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 8;
                        }
                        iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"RD2_RV");
                        if (iVar3 != 0) {
                          *(undefined4 *)(unaff_EBP + -0x8494) = 9;
                        }
                        if (*(int *)(unaff_EBP + -0x8494) < 0) {
                          iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"GCOM_1");
                          if (iVar3 == 0) {
                            iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"N_KEY");
                            if (iVar3 != 0) {
                              *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
                              *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
                              *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
                              *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
                              FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d",
                                           unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,
                                           unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18);
                              if ((-1 < *(int *)(unaff_EBP + -0x1e24)) &&
                                 (*(int *)(unaff_EBP + -0x1e24) < 2)) {
                                DAT_00a0cc90 = *(undefined4 *)(unaff_EBP + -0x1e24);
                              }
                              if ((-1 < *(int *)(unaff_EBP + -0x1e20)) &&
                                 (*(int *)(unaff_EBP + -0x1e20) < 2)) {
                                DAT_00a0cc98 = *(undefined4 *)(unaff_EBP + -0x1e20);
                              }
                              if ((-1 < *(int *)(unaff_EBP + -0x1e1c)) &&
                                 (*(int *)(unaff_EBP + -0x1e1c) < 2)) {
                                DAT_00a0c7b8 = *(undefined4 *)(unaff_EBP + -0x1e1c);
                              }
                              if ((-1 < *(int *)(unaff_EBP + -0x1e18)) &&
                                 (*(int *)(unaff_EBP + -0x1e18) < 4)) {
                                DAT_00a0cc94 = *(undefined4 *)(unaff_EBP + -0x1e18);
                              }
                            }
                            iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"KEY_");
                            if (iVar3 != 0) {
                              *(undefined2 *)(unaff_EBP + -0x8504) = 0;
                              *(undefined4 *)(unaff_EBP + -0x8494) = 0;
                              *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffdcd8;
                              *(undefined4 *)(unaff_EBP + -0x1e28) = 0xffffdcd8;
                              iVar3 = FUN_00417110(unaff_EBP + -0x430,&DAT_00963734,
                                                   unaff_EBP + -0x8504,1);
                              if (((iVar3 == 0) ||
                                  (*(uint *)(unaff_EBP + -0x8494) =
                                        (uint)*(ushort *)(unaff_EBP + -0x8504),
                                  *(int *)(unaff_EBP + -0x8494) < 0x41)) ||
                                 (0x5a < *(int *)(unaff_EBP + -0x8494))) goto LAB_005293fd;
                              FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d",
                                           unaff_EBP + -0x1e28,unaff_EBP + -0x1e24);
                              if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                *(int *)(unaff_EBP + -0x866c) = -*(int *)(unaff_EBP + -0x1e28);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x866c) =
                                     *(undefined4 *)(unaff_EBP + -0x1e28);
                              }
                              if (-1 < *(int *)(unaff_EBP + -0x866c)) {
                                if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                  *(int *)(unaff_EBP + -0x8670) = -*(int *)(unaff_EBP + -0x1e28);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x8670) =
                                       *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                                if (*(int *)(unaff_EBP + -0x8670) < 0xc9) {
                                  *(undefined4 *)(&DAT_00a0cc9c + *(int *)(unaff_EBP + -0x8494) * 4)
                                       = *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                              }
                              if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                *(int *)(unaff_EBP + -0x8674) = -*(int *)(unaff_EBP + -0x1e28);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x8674) =
                                     *(undefined4 *)(unaff_EBP + -0x1e28);
                              }
                              if (1099 < *(int *)(unaff_EBP + -0x8674)) {
                                if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                  *(int *)(unaff_EBP + -0x8678) = -*(int *)(unaff_EBP + -0x1e28);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x8678) =
                                       *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                                if (*(int *)(unaff_EBP + -0x8678) < 0x4b1) {
                                  *(undefined4 *)(&DAT_00a0cc9c + *(int *)(unaff_EBP + -0x8494) * 4)
                                       = *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                              }
                              *(int *)(unaff_EBP + -0x8494) = *(int *)(unaff_EBP + -0x8494) + 300;
                              if (*(int *)(unaff_EBP + -0x1e24) < 1) {
                                *(int *)(unaff_EBP + -0x867c) = -*(int *)(unaff_EBP + -0x1e24);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x867c) =
                                     *(undefined4 *)(unaff_EBP + -0x1e24);
                              }
                              if (-1 < *(int *)(unaff_EBP + -0x867c)) {
                                if (*(int *)(unaff_EBP + -0x1e24) < 1) {
                                  *(int *)(unaff_EBP + -0x8680) = -*(int *)(unaff_EBP + -0x1e24);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x8680) =
                                       *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                                if (*(int *)(unaff_EBP + -0x8680) < 0xc9) {
                                  *(undefined4 *)(&DAT_00a0cc9c + *(int *)(unaff_EBP + -0x8494) * 4)
                                       = *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                              }
                              if (*(int *)(unaff_EBP + -0x1e24) < 1) {
                                *(int *)(unaff_EBP + -0x8684) = -*(int *)(unaff_EBP + -0x1e24);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x8684) =
                                     *(undefined4 *)(unaff_EBP + -0x1e24);
                              }
                              if (1099 < *(int *)(unaff_EBP + -0x8684)) {
                                if (*(int *)(unaff_EBP + -0x1e24) < 1) {
                                  *(int *)(unaff_EBP + -0x8688) = -*(int *)(unaff_EBP + -0x1e24);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x8688) =
                                       *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                                if (*(int *)(unaff_EBP + -0x8688) < 0x4b1) {
                                  *(undefined4 *)(&DAT_00a0cc9c + *(int *)(unaff_EBP + -0x8494) * 4)
                                       = *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                              }
                            }
                            iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"KEYF");
                            if (iVar3 != 0) {
                              *(undefined4 *)(unaff_EBP + -0x8494) = 0;
                              *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffdcd8;
                              *(undefined4 *)(unaff_EBP + -0x1e28) = 0xffffdcd8;
                              iVar3 = FUN_00417110(unaff_EBP + -0x430,&DAT_0095b714,
                                                   unaff_EBP + -0x8494);
                              if ((iVar3 == 0) ||
                                 (((*(int *)(unaff_EBP + -0x8494) =
                                         *(int *)(unaff_EBP + -0x8494) + 0x6f,
                                   *(int *)(unaff_EBP + -0x8494) < 0x71 ||
                                   (0x78 < *(int *)(unaff_EBP + -0x8494))) &&
                                  ((*(int *)(unaff_EBP + -0x8494) < 0x7a ||
                                   (0x7b < *(int *)(unaff_EBP + -0x8494))))))) goto LAB_005293fd;
                              FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d",
                                           unaff_EBP + -0x1e28,unaff_EBP + -0x1e24);
                              if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                *(int *)(unaff_EBP + -0x868c) = -*(int *)(unaff_EBP + -0x1e28);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x868c) =
                                     *(undefined4 *)(unaff_EBP + -0x1e28);
                              }
                              if (-1 < *(int *)(unaff_EBP + -0x868c)) {
                                if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                  *(int *)(unaff_EBP + -0x8690) = -*(int *)(unaff_EBP + -0x1e28);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x8690) =
                                       *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                                if (*(int *)(unaff_EBP + -0x8690) < 0xc9) {
                                  *(undefined4 *)(&DAT_00a0cc9c + *(int *)(unaff_EBP + -0x8494) * 4)
                                       = *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                              }
                              if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                *(int *)(unaff_EBP + -0x8694) = -*(int *)(unaff_EBP + -0x1e28);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x8694) =
                                     *(undefined4 *)(unaff_EBP + -0x1e28);
                              }
                              if (1099 < *(int *)(unaff_EBP + -0x8694)) {
                                if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                  *(int *)(unaff_EBP + -0x8698) = -*(int *)(unaff_EBP + -0x1e28);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x8698) =
                                       *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                                if (*(int *)(unaff_EBP + -0x8698) < 0x4b1) {
                                  *(undefined4 *)(&DAT_00a0cc9c + *(int *)(unaff_EBP + -0x8494) * 4)
                                       = *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                              }
                              *(int *)(unaff_EBP + -0x8494) = *(int *)(unaff_EBP + -0x8494) + 300;
                              if (*(int *)(unaff_EBP + -0x1e24) < 1) {
                                *(int *)(unaff_EBP + -0x869c) = -*(int *)(unaff_EBP + -0x1e24);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x869c) =
                                     *(undefined4 *)(unaff_EBP + -0x1e24);
                              }
                              if (-1 < *(int *)(unaff_EBP + -0x869c)) {
                                if (*(int *)(unaff_EBP + -0x1e24) < 1) {
                                  *(int *)(unaff_EBP + -0x86a0) = -*(int *)(unaff_EBP + -0x1e24);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x86a0) =
                                       *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                                if (*(int *)(unaff_EBP + -0x86a0) < 0xc9) {
                                  *(undefined4 *)(&DAT_00a0cc9c + *(int *)(unaff_EBP + -0x8494) * 4)
                                       = *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                              }
                              if (*(int *)(unaff_EBP + -0x1e24) < 1) {
                                *(int *)(unaff_EBP + -0x86a4) = -*(int *)(unaff_EBP + -0x1e24);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x86a4) =
                                     *(undefined4 *)(unaff_EBP + -0x1e24);
                              }
                              if (1099 < *(int *)(unaff_EBP + -0x86a4)) {
                                if (*(int *)(unaff_EBP + -0x1e24) < 1) {
                                  *(int *)(unaff_EBP + -0x86a8) = -*(int *)(unaff_EBP + -0x1e24);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x86a8) =
                                       *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                                if (*(int *)(unaff_EBP + -0x86a8) < 0x4b1) {
                                  *(undefined4 *)(&DAT_00a0cc9c + *(int *)(unaff_EBP + -0x8494) * 4)
                                       = *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                              }
                            }
                            iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"KEYSP");
                            if (iVar3 == 0) {
                              iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"KEY76");
                              if (iVar3 == 0) {
                                iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"WD_COM");
                                if (iVar3 != 0) {
                                  DAT_00a0de64 = 0;
                                  *(undefined4 *)(unaff_EBP + -0x8490) = 0;
                                  while (*(int *)(unaff_EBP + -0x8490) < 0x33) {
                                    *(undefined4 *)
                                     (&DAT_00a0de68 + *(int *)(unaff_EBP + -0x8490) * 4) = 0;
                                    *(int *)(unaff_EBP + -0x8490) =
                                         *(int *)(unaff_EBP + -0x8490) + 1;
                                  }
                                  *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e0c) = 0;
                                  FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                                               L"%d %d %d %d %d %d %d %d %d",unaff_EBP + -0x1e24,
                                               unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                                               unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,
                                               unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,
                                               unaff_EBP + -0x1e08,unaff_EBP + -0x1e04);
                                  if (0 < *(int *)(unaff_EBP + -0x1e24)) {
                                    DAT_00a0de6c = 0x804e;
                                  }
                                  if (0 < *(int *)(unaff_EBP + -0x1e20)) {
                                    DAT_00a0de70 = 0x801a;
                                  }
                                  if (0 < *(int *)(unaff_EBP + -0x1e1c)) {
                                    DAT_00a0de74 = 0x8017;
                                  }
                                  if (0 < *(int *)(unaff_EBP + -0x1e18)) {
                                    DAT_00a0de78 = 0x8020;
                                  }
                                  if (0 < *(int *)(unaff_EBP + -0x1e14)) {
                                    DAT_00a0de7c = 0x8069;
                                  }
                                  if (0 < *(int *)(unaff_EBP + -0x1e10)) {
                                    DAT_00a0de80 = 0x8026;
                                  }
                                  if (((0 < *(int *)(unaff_EBP + -0x1e24)) ||
                                      (0 < *(int *)(unaff_EBP + -0x1e20))) ||
                                     ((0 < *(int *)(unaff_EBP + -0x1e1c) ||
                                      (((0 < *(int *)(unaff_EBP + -0x1e18) ||
                                        (0 < *(int *)(unaff_EBP + -0x1e14))) ||
                                       (0 < *(int *)(unaff_EBP + -0x1e10))))))) {
                                    DAT_00a0de64 = 6;
                                  }
                                  DAT_00a0ed74 = 0;
                                  if (*(int *)(unaff_EBP + -0x1e0c) < 0) {
                                    DAT_00a0ed74 = 0xffffffff;
                                  }
                                }
                                iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"AC_COM");
                                if (iVar3 != 0) {
                                  *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
                                  FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                                               L"%d %d %d %d %d %d %d %d %d",unaff_EBP + -0x1e24,
                                               unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                                               unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,
                                               unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,
                                               unaff_EBP + -0x1e08,unaff_EBP + -0x1e04);
                                  if ((-1 < *(int *)(unaff_EBP + -0x1e24)) &&
                                     (*(int *)(unaff_EBP + -0x1e24) < 3)) {
                                    DAT_00a0c7c4 = *(undefined4 *)(unaff_EBP + -0x1e24);
                                  }
                                  if (((-1 < *(int *)(unaff_EBP + -0x1e20)) &&
                                      (*(int *)(unaff_EBP + -0x1e20) < 0x100)) &&
                                     ((-1 < *(int *)(unaff_EBP + -0x1e1c) &&
                                      (((*(int *)(unaff_EBP + -0x1e1c) < 0x100 &&
                                        (-1 < *(int *)(unaff_EBP + -0x1e18))) &&
                                       (*(int *)(unaff_EBP + -0x1e18) < 0x100)))))) {
                                    DAT_00a0ef6c = (uint)CONCAT12(*(undefined1 *)
                                                                   (unaff_EBP + -0x1e18),
                                                                  CONCAT11(*(undefined1 *)
                                                                            (unaff_EBP + -0x1e1c),
                                                                           *(undefined1 *)
                                                                            (unaff_EBP + -0x1e20)));
                                  }
                                  if (((-1 < *(int *)(unaff_EBP + -0x1e14)) &&
                                      (*(int *)(unaff_EBP + -0x1e14) < 0x100)) &&
                                     (((-1 < *(int *)(unaff_EBP + -0x1e10) &&
                                       ((*(int *)(unaff_EBP + -0x1e10) < 0x100 &&
                                        (-1 < *(int *)(unaff_EBP + -0x1e0c))))) &&
                                      (*(int *)(unaff_EBP + -0x1e0c) < 0x100)))) {
                                    DAT_00a0ef70 = (uint)CONCAT12(*(undefined1 *)
                                                                   (unaff_EBP + -0x1e0c),
                                                                  CONCAT11(*(undefined1 *)
                                                                            (unaff_EBP + -0x1e10),
                                                                           *(undefined1 *)
                                                                            (unaff_EBP + -0x1e14)));
                                  }
                                  if ((-1 < *(int *)(unaff_EBP + -0x1e08)) &&
                                     (*(int *)(unaff_EBP + -0x1e08) < 2)) {
                                    DAT_00a0c7cc = *(undefined4 *)(unaff_EBP + -0x1e08);
                                  }
                                }
                                iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"TNKZ_SET");
                                if (iVar3 != 0) {
                                  *(undefined4 *)(unaff_EBP + -0x1e0c) = 0;
                                  *(undefined4 *)(unaff_EBP + -0x1e10) = 0;
                                  *(undefined4 *)(unaff_EBP + -0x1e14) = 0;
                                  *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
                                  *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
                                  *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
                                  *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
                                  *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1df8) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1dfc) = 0xffffffff;
                                  *(undefined4 *)(unaff_EBP + -0x1e00) = 0xffffffff;
                                  FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                                               L"%d %d %d %d %d %d %d %d %d %d %d %d",
                                               unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,
                                               unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                                               unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,
                                               unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                                               unaff_EBP + -0x1e04,unaff_EBP + -0x1e00,
                                               unaff_EBP + -0x1dfc,unaff_EBP + -0x1df8);
                                  if ((*(int *)(unaff_EBP + -0x1e24) == 0) ||
                                     ((9 < *(int *)(unaff_EBP + -0x1e24) &&
                                      (*(int *)(unaff_EBP + -0x1e24) < 0x1f5)))) {
                                    *(double *)(**(int **)(unaff_EBP + -0x848c) + 0x83e8) =
                                         (double)*(int *)(unaff_EBP + -0x1e24);
                                  }
                                  *(int *)(unaff_EBP + -0x84a0) =
                                       *(int *)(unaff_EBP + -0x1e20) / 1000;
                                  *(int *)(unaff_EBP + -0x84a0) = *(int *)(unaff_EBP + -0x84a0) % 10
                                  ;
                                  if ((-1 < *(int *)(unaff_EBP + -0x84a0)) &&
                                     (*(int *)(unaff_EBP + -0x84a0) < 2)) {
                                    DAT_00a0bed8 = *(undefined4 *)(unaff_EBP + -0x84a0);
                                  }
                                  *(int *)(unaff_EBP + -0x84a0) =
                                       *(int *)(unaff_EBP + -0x1e20) / 100;
                                  *(int *)(unaff_EBP + -0x84a0) = *(int *)(unaff_EBP + -0x84a0) % 10
                                  ;
                                  if ((-1 < *(int *)(unaff_EBP + -0x84a0)) &&
                                     (*(int *)(unaff_EBP + -0x84a0) < 2)) {
                                    DAT_00a0beb0 = *(undefined4 *)(unaff_EBP + -0x84a0);
                                  }
                                  *(int *)(unaff_EBP + -0x84a0) = *(int *)(unaff_EBP + -0x1e20) / 10
                                  ;
                                  *(int *)(unaff_EBP + -0x84a0) = *(int *)(unaff_EBP + -0x84a0) % 10
                                  ;
                                  if ((-1 < *(int *)(unaff_EBP + -0x84a0)) &&
                                     (*(int *)(unaff_EBP + -0x84a0) < 2)) {
                                    DAT_00a0beb4 = *(int *)(unaff_EBP + -0x84a0);
                                  }
                                  *(int *)(unaff_EBP + -0x84a0) = *(int *)(unaff_EBP + -0x1e20) % 10
                                  ;
                                  if ((-1 < *(int *)(unaff_EBP + -0x84a0)) &&
                                     (*(int *)(unaff_EBP + -0x84a0) < 2)) {
                                    DAT_00a0beb4 = *(int *)(unaff_EBP + -0x84a0) * 10 +
                                                   DAT_00a0beb4 % 10;
                                  }
                                  if ((-1 < *(int *)(unaff_EBP + -0x1e1c)) &&
                                     (*(int *)(unaff_EBP + -0x1e1c) < 2)) {
                                    DAT_00a0becc = *(undefined4 *)(unaff_EBP + -0x1e1c);
                                  }
                                  if ((0 < *(int *)(unaff_EBP + -0x1e18) % 10) &&
                                     (*(int *)(unaff_EBP + -0x1e18) % 10 < 10)) {
                                    DAT_00a0bec8 = *(undefined4 *)(unaff_EBP + -0x1e18);
                                  }
                                  if ((0 < *(int *)(unaff_EBP + -0x1e14)) &&
                                     (*(int *)(unaff_EBP + -0x1e14) < 0x3f3)) {
                                    *(int *)(unaff_EBP + -0x85c4) =
                                         *(int *)(unaff_EBP + -0x1e14) % 100;
                                    if ((*(int *)(unaff_EBP + -0x85c4) < 1) ||
                                       (10 < *(int *)(unaff_EBP + -0x85c4))) {
                                      *(undefined4 *)(unaff_EBP + -0x85c4) = 2;
                                    }
                                    *(int *)(unaff_EBP + -0x85c0) =
                                         *(int *)(unaff_EBP + -0x1e14) / 100;
                                    if ((*(int *)(unaff_EBP + -0x85c0) < 1) ||
                                       (10 < *(int *)(unaff_EBP + -0x85c0))) {
                                      *(undefined4 *)(unaff_EBP + -0x85c0) = 3;
                                    }
                                    DAT_00a0beb8 = *(int *)(unaff_EBP + -0x85c0) * 100 +
                                                   *(int *)(unaff_EBP + -0x85c4);
                                  }
                                  if (*(int *)(unaff_EBP + -0x1e10) < 1) {
                                    *(int *)(unaff_EBP + -0x86bc) = -*(int *)(unaff_EBP + -0x1e10);
                                  }
                                  else {
                                    *(undefined4 *)(unaff_EBP + -0x86bc) =
                                         *(undefined4 *)(unaff_EBP + -0x1e10);
                                  }
                                  if (0 < *(int *)(unaff_EBP + -0x86bc)) {
                                    if (*(int *)(unaff_EBP + -0x1e10) < 1) {
                                      *(int *)(unaff_EBP + -0x86c0) = -*(int *)(unaff_EBP + -0x1e10)
                                      ;
                                    }
                                    else {
                                      *(undefined4 *)(unaff_EBP + -0x86c0) =
                                           *(undefined4 *)(unaff_EBP + -0x1e10);
                                    }
                                    if (*(int *)(unaff_EBP + -0x86c0) < 0x65) {
                                      if (*(int *)(unaff_EBP + -0x1e10) < 1) {
                                        *(int *)(unaff_EBP + -0x86c4) =
                                             -*(int *)(unaff_EBP + -0x1e10);
                                      }
                                      else {
                                        *(undefined4 *)(unaff_EBP + -0x86c4) =
                                             *(undefined4 *)(unaff_EBP + -0x1e10);
                                      }
                                      *(undefined4 *)(unaff_EBP + -0x84c4) =
                                           *(undefined4 *)(unaff_EBP + -0x86c4);
                                      if (6 < *(int *)(unaff_EBP + -0x84c4)) {
                                        do {
                                          if ((int)(0xe10 % (longlong)*(int *)(unaff_EBP + -0x84c4))
                                              == 0) goto LAB_00533585;
                                          *(int *)(unaff_EBP + -0x84c4) =
                                               *(int *)(unaff_EBP + -0x84c4) + 1;
                                        } while (*(int *)(unaff_EBP + -0x84c4) < 100);
                                        *(undefined4 *)(unaff_EBP + -0x84c4) = 100;
                                      }
LAB_00533585:
                                      if (*(int *)(unaff_EBP + -0x1e10) < 0) {
                                        *(int *)(unaff_EBP + -0x84c4) =
                                             -*(int *)(unaff_EBP + -0x84c4);
                                      }
                                      DAT_00a0bebc = *(undefined4 *)(unaff_EBP + -0x84c4);
                                    }
                                  }
                                  if (((0 < *(int *)(unaff_EBP + -0x1e0c) % 10) &&
                                      (*(int *)(unaff_EBP + -0x1e0c) % 10 < 10)) &&
                                     (*(int *)(unaff_EBP + -0x1e0c) < 100)) {
                                    DAT_00a0bec0 = *(undefined4 *)(unaff_EBP + -0x1e0c);
                                  }
                                  if ((0 < *(int *)(unaff_EBP + -0x1e08)) &&
                                     (*(int *)(unaff_EBP + -0x1e08) < 0x271a)) {
                                    DAT_00a0bec4 = *(undefined4 *)(unaff_EBP + -0x1e08);
                                  }
                                  if ((9 < *(int *)(unaff_EBP + -0x1e04)) &&
                                     (*(int *)(unaff_EBP + -0x1e04) < 0x1f5)) {
                                    DAT_00a0bed0 = *(undefined4 *)(unaff_EBP + -0x1e04);
                                  }
                                }
                                iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"TNK3_NM1");
                                if (iVar3 != 0) {
                                  uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x8498),10);
                                  *(undefined4 *)(unaff_EBP + -0x86c8) = uVar2;
                                  if (*(int *)(unaff_EBP + -0x86c8) != 0) {
                                    **(undefined2 **)(unaff_EBP + -0x86c8) = 0;
                                  }
                                  uVar4 = FUN_008f899d(*(undefined4 *)(unaff_EBP + -0x8498));
                                  if (0x14 < uVar4) {
                                    *(undefined2 *)(*(int *)(unaff_EBP + -0x8498) + 0x28) = 0;
                                  }
                                  if (**(short **)(unaff_EBP + -0x8498) != 0) {
                                    FUN_00404900(*(undefined4 *)(unaff_EBP + -0x8498));
                                  }
                                }
                                iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"TNK3_NM2");
                                if (iVar3 != 0) {
                                  uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x8498),10);
                                  *(undefined4 *)(unaff_EBP + -0x86cc) = uVar2;
                                  if (*(int *)(unaff_EBP + -0x86cc) != 0) {
                                    **(undefined2 **)(unaff_EBP + -0x86cc) = 0;
                                  }
                                  uVar4 = FUN_008f899d(*(undefined4 *)(unaff_EBP + -0x8498));
                                  if (0x14 < uVar4) {
                                    *(undefined2 *)(*(int *)(unaff_EBP + -0x8498) + 0x28) = 0;
                                  }
                                  if (**(short **)(unaff_EBP + -0x8498) != 0) {
                                    FUN_00404900(*(undefined4 *)(unaff_EBP + -0x8498));
                                  }
                                }
                                iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"TNKN_SET");
                                if (iVar3 != 0) {
                                  *(undefined4 *)(unaff_EBP + -0x8490) = 1;
                                  while (*(int *)(unaff_EBP + -0x8490) < 9) {
                                    FUN_004d3340(unaff_EBP + -0x888,
                                                 *(undefined4 *)(unaff_EBP + -0x8498));
                                    uVar2 = FUN_00457e50(unaff_EBP + -0x888,0x2c);
                                    *(undefined4 *)(unaff_EBP + -0x8550) = uVar2;
                                    if (*(int *)(unaff_EBP + -0x8550) != 0) {
                                      **(undefined2 **)(unaff_EBP + -0x8550) = 0;
                                    }
                                    uVar2 = FUN_00457e50(unaff_EBP + -0x888,10);
                                    *(undefined4 *)(unaff_EBP + -0x8550) = uVar2;
                                    if (*(int *)(unaff_EBP + -0x8550) != 0) {
                                      **(undefined2 **)(unaff_EBP + -0x8550) = 0;
                                    }
                                    uVar4 = FUN_008f899d(unaff_EBP + -0x888);
                                    if (6 < uVar4) {
                                      *(undefined4 *)(unaff_EBP + -0x86d0) = 0xc;
                                      if (0x3ff < *(uint *)(unaff_EBP + -0x86d0)) {
                    /* WARNING: Subroutine does not return */
                                        FUN_008d927f();
                                      }
                                      *(undefined2 *)
                                       (unaff_EBP + -0x888 + *(int *)(unaff_EBP + -0x86d0)) = 0;
                                    }
                                    if (*(int *)(unaff_EBP + -0x8490) == 1) {
                                      FUN_00404900(unaff_EBP + -0x888);
                                    }
                                    if (*(int *)(unaff_EBP + -0x8490) == 2) {
                                      FUN_00404900(unaff_EBP + -0x888);
                                    }
                                    if (*(int *)(unaff_EBP + -0x8490) == 3) {
                                      FUN_00404900(unaff_EBP + -0x888);
                                    }
                                    if (*(int *)(unaff_EBP + -0x8490) == 4) {
                                      FUN_00404900(unaff_EBP + -0x888);
                                    }
                                    if (*(int *)(unaff_EBP + -0x8490) == 5) {
                                      FUN_00404900(unaff_EBP + -0x888);
                                    }
                                    if (*(int *)(unaff_EBP + -0x8490) == 6) {
                                      FUN_00404900(unaff_EBP + -0x888);
                                    }
                                    if (*(int *)(unaff_EBP + -0x8490) == 7) {
                                      FUN_00404900(unaff_EBP + -0x888);
                                    }
                                    if (*(int *)(unaff_EBP + -0x8490) == 8) {
                                      FUN_00404900(unaff_EBP + -0x888);
                                    }
                                    uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x8498),0x2c);
                                    *(undefined4 *)(unaff_EBP + -0x8498) = uVar2;
                                    if (*(int *)(unaff_EBP + -0x8498) == 0) break;
                                    *(int *)(unaff_EBP + -0x8498) =
                                         *(int *)(unaff_EBP + -0x8498) + 2;
                                    *(int *)(unaff_EBP + -0x8490) =
                                         *(int *)(unaff_EBP + -0x8490) + 1;
                                  }
                                }
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
                                *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
                                *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
                                *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
                                *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
                                *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
                                *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
                                *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
                                *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
                                FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                                             L"%d %d %d %d %d %d %d %d %d",unaff_EBP + -0x1e24,
                                             unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                                             unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,
                                             unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,
                                             unaff_EBP + -0x1e08,unaff_EBP + -0x1e04);
                                if ((-1 < *(int *)(unaff_EBP + -0x1e24)) &&
                                   (*(int *)(unaff_EBP + -0x1e24) < 2)) {
                                  DAT_00a0bfb0 = *(undefined4 *)(unaff_EBP + -0x1e24);
                                }
                                if ((0 < *(int *)(unaff_EBP + -0x1e20)) &&
                                   (*(int *)(unaff_EBP + -0x1e20) < 0xb5)) {
                                  DAT_00a0bfb4 = *(undefined4 *)(unaff_EBP + -0x1e20);
                                }
                              }
                            }
                            else {
                              *(undefined4 *)(unaff_EBP + -0x1e28) = 0xffffdcd8;
                              FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),&DAT_0095b714,
                                           unaff_EBP + -0x1e28);
                              if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                *(int *)(unaff_EBP + -0x86ac) = -*(int *)(unaff_EBP + -0x1e28);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x86ac) =
                                     *(undefined4 *)(unaff_EBP + -0x1e28);
                              }
                              if (-1 < *(int *)(unaff_EBP + -0x86ac)) {
                                if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                  *(int *)(unaff_EBP + -0x86b0) = -*(int *)(unaff_EBP + -0x1e28);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x86b0) =
                                       *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                                if (*(int *)(unaff_EBP + -0x86b0) < 0xc9) {
                                  DAT_00a0d5fc = *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                              }
                              if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                *(int *)(unaff_EBP + -0x86b4) = -*(int *)(unaff_EBP + -0x1e28);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x86b4) =
                                     *(undefined4 *)(unaff_EBP + -0x1e28);
                              }
                              if (1099 < *(int *)(unaff_EBP + -0x86b4)) {
                                if (*(int *)(unaff_EBP + -0x1e28) < 1) {
                                  *(int *)(unaff_EBP + -0x86b8) = -*(int *)(unaff_EBP + -0x1e28);
                                }
                                else {
                                  *(undefined4 *)(unaff_EBP + -0x86b8) =
                                       *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                                if (*(int *)(unaff_EBP + -0x86b8) < 0x4b1) {
                                  DAT_00a0d5fc = *(undefined4 *)(unaff_EBP + -0x1e28);
                                }
                              }
                            }
                          }
                          else {
                            *(undefined4 *)(unaff_EBP + -0x8494) = 0;
                            iVar3 = FUN_00417110(unaff_EBP + -0x42c,&DAT_0095b714,
                                                 unaff_EBP + -0x8494);
                            if ((((iVar3 != 0) && (*(int *)(unaff_EBP + -0x8494) % 10 == 0)) &&
                                (-1 < *(int *)(unaff_EBP + -0x8494))) &&
                               (*(int *)(unaff_EBP + -0x8494) < 0x5b)) {
                              FUN_00404900(&DAT_00956338);
                              *(undefined4 *)(unaff_EBP + -0x8490) = 0;
                              while (*(int *)(unaff_EBP + -0x8490) < 10) {
                                FUN_00404900(&DAT_00956338);
                                *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                              }
                              *(undefined4 *)(unaff_EBP + -0x8490) = 0;
                              while (*(int *)(unaff_EBP + -0x8490) < 0xb) {
                                FUN_00525d60(unaff_EBP + -0x1888,&DAT_00955904,
                                             *(undefined4 *)(unaff_EBP + -0x8498));
                                *(int *)(unaff_EBP + -0x84c0) = unaff_EBP + -0x1888;
                                uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x84c0),0x2c);
                                *(undefined4 *)(unaff_EBP + -0x84c8) = uVar2;
                                if (*(int *)(unaff_EBP + -0x84c8) != 0) {
                                  **(undefined2 **)(unaff_EBP + -0x84c8) = 0;
                                }
                                uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x84c0),10);
                                *(undefined4 *)(unaff_EBP + -0x84c8) = uVar2;
                                if (*(int *)(unaff_EBP + -0x84c8) != 0) {
                                  **(undefined2 **)(unaff_EBP + -0x84c8) = 0;
                                }
                                while (**(short **)(unaff_EBP + -0x84c0) == 0x20) {
                                  *(int *)(unaff_EBP + -0x84c0) = *(int *)(unaff_EBP + -0x84c0) + 2;
                                }
                                while( true ) {
                                  iVar3 = FUN_008f899d(*(undefined4 *)(unaff_EBP + -0x84c0));
                                  *(int *)(unaff_EBP + -0x84c8) =
                                       *(int *)(unaff_EBP + -0x84c0) + -2 + iVar3 * 2;
                                  if (**(short **)(unaff_EBP + -0x84c8) != 0x20) break;
                                  **(undefined2 **)(unaff_EBP + -0x84c8) = 0;
                                }
                                iVar3 = FUN_008f899d(unaff_EBP + -0x1888);
                                if ((iVar3 != 0) && (*(int *)(unaff_EBP + -0x8490) < 10)) {
                                  FUN_004059f0(&DAT_00a0dcc4 +
                                               (*(int *)(unaff_EBP + -0x8494) +
                                               *(int *)(unaff_EBP + -0x8490)) * 4,&DAT_00955904,
                                               *(undefined4 *)(unaff_EBP + -0x84c0));
                                }
                                iVar3 = FUN_008f899d(unaff_EBP + -0x1888);
                                if ((iVar3 != 0) && (*(int *)(unaff_EBP + -0x8490) == 10)) {
                                  FUN_004059f0(&DAT_00a0dc8c +
                                               (*(int *)(unaff_EBP + -0x8494) / 10) * 4,
                                               &DAT_00955904,*(undefined4 *)(unaff_EBP + -0x84c0));
                                }
                                uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x8498),0x2c);
                                *(undefined4 *)(unaff_EBP + -0x8498) = uVar2;
                                if (*(int *)(unaff_EBP + -0x8498) == 0) break;
                                *(int *)(unaff_EBP + -0x8498) = *(int *)(unaff_EBP + -0x8498) + 2;
                                *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                              }
                            }
                          }
                        }
                        else {
                          *(undefined4 *)(unaff_EBP + -0x8490) = 0;
                          while (*(int *)(unaff_EBP + -0x8490) < 0xc) {
                            *(undefined4 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4)
                                 = 0;
                            *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                          }
                          FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                                       L"%d %d %d %d %d %d %d %d %d %d %d %d",unaff_EBP + -0x1e28,
                                       unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                                       unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,
                                       unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,unaff_EBP + -0x1e04,
                                       unaff_EBP + -0x1e00,unaff_EBP + -0x1dfc);
                          *(undefined4 *)(unaff_EBP + -0x8490) = 0;
                          while (*(int *)(unaff_EBP + -0x8490) < 0xc) {
                            if ((((*(int *)(unaff_EBP + -0x8494) != 0) &&
                                 (*(int *)(unaff_EBP + -0x8494) != 4)) ||
                                ((*(int *)(unaff_EBP + -0x8490) != 5 &&
                                 ((*(int *)(unaff_EBP + -0x8490) != 6 &&
                                  (*(int *)(unaff_EBP + -0x8490) != 9)))))) &&
                               (((*(int *)(unaff_EBP + -0x8494) != 2 &&
                                 (*(int *)(unaff_EBP + -0x8494) != 6)) ||
                                (((((*(int *)(unaff_EBP + -0x8490) != 0 &&
                                    (*(int *)(unaff_EBP + -0x8490) != 3)) &&
                                   (*(int *)(unaff_EBP + -0x8490) != 4)) &&
                                  ((*(int *)(unaff_EBP + -0x8490) != 5 &&
                                   (*(int *)(unaff_EBP + -0x8490) != 6)))) &&
                                 (*(int *)(unaff_EBP + -0x8490) != 9)))))) {
                              if (*(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4)
                                  < 1) {
                                *(int *)(unaff_EBP + -0x8668) =
                                     -*(int *)(unaff_EBP + -0x1e28 +
                                              *(int *)(unaff_EBP + -0x8490) * 4);
                              }
                              else {
                                *(undefined4 *)(unaff_EBP + -0x8668) =
                                     *(undefined4 *)
                                      (unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4);
                              }
                              if (*(int *)(unaff_EBP + -0x8668) < 0xc9) {
                                *(undefined4 *)(unaff_EBP + -0x85ec) =
                                     *(undefined4 *)(unaff_EBP + -0x8490);
                                if (*(int *)(unaff_EBP + -0x85ec) == 0) {
                                  *(undefined4 *)(unaff_EBP + -0x85ec) = 0xc;
                                }
                                *(undefined4 *)
                                 (&DAT_00a0d8fc +
                                 *(int *)(unaff_EBP + -0x85ec) * 4 +
                                 *(int *)(unaff_EBP + -0x8494) * 0x40) =
                                     *(undefined4 *)
                                      (unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4);
                              }
                            }
                            *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                          }
                        }
                      }
                      else {
                        *(undefined4 *)(unaff_EBP + -0x8490) = 1;
                        while (*(int *)(unaff_EBP + -0x8490) < 0xb) {
                          *(undefined4 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) =
                               0xffffffff;
                          *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                        }
                        FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),&DAT_0095b714,
                                     unaff_EBP + -0x1e24);
                        if (-1 < *(int *)(unaff_EBP + -0x1e24)) {
                          *(int *)(unaff_EBP + -0x85b4) = (*(int *)(unaff_EBP + -0x1e24) / 10) % 10;
                          *(int *)(unaff_EBP + -0x85b8) = *(int *)(unaff_EBP + -0x1e24) % 10;
                          if ((*(int *)(unaff_EBP + -0x85b4) < 0) ||
                             (5 < *(int *)(unaff_EBP + -0x85b4))) {
                            *(undefined4 *)(unaff_EBP + -0x85b4) = 2;
                          }
                          if ((*(int *)(unaff_EBP + -0x85b8) < 0) ||
                             (5 < *(int *)(unaff_EBP + -0x85b8))) {
                            *(undefined4 *)(unaff_EBP + -0x85b8) = 3;
                          }
                          DAT_00a0ef64 = *(int *)(unaff_EBP + -0x85b4) * 10 +
                                         *(int *)(unaff_EBP + -0x85b8);
                        }
                      }
                    }
                    else {
                      *(undefined4 *)(unaff_EBP + -0x8490) = 1;
                      while (*(int *)(unaff_EBP + -0x8490) < 0xb) {
                        *(undefined4 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) =
                             0xffffffff;
                        *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                      }
                      FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                                   L"%x %x %x %x %x %x %x %x %x %x",unaff_EBP + -0x1e24,
                                   unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                                   unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,
                                   unaff_EBP + -0x1e08,unaff_EBP + -0x1e04,unaff_EBP + -0x1e00);
                      *(undefined4 *)(unaff_EBP + -0x8490) = 1;
                      while (*(int *)(unaff_EBP + -0x8490) < 0xb) {
                        if ((-1 < *(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4))
                           && (*(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) < 4
                              )) {
                          *(undefined2 *)
                           (&DAT_00a0dbbc +
                           (*(int *)(unaff_EBP + -0x8494) + *(int *)(unaff_EBP + -0x8490)) * 2) =
                               *(undefined2 *)
                                (unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4);
                        }
                        if ((*(int *)(unaff_EBP + -0x8494) == 0) &&
                           (((*(int *)(unaff_EBP + -0x8490) == 5 ||
                             (*(int *)(unaff_EBP + -0x8490) == 7)) &&
                            (*(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) == 4)
                            ))) {
                          *(undefined2 *)
                           (&DAT_00a0dbbc +
                           (*(int *)(unaff_EBP + -0x8494) + *(int *)(unaff_EBP + -0x8490)) * 2) =
                               *(undefined2 *)
                                (unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4);
                        }
                        *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                      }
                    }
                  }
                  else {
                    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                                 L"%x %x %x %x %x %x %x %x %x %x",
                                 unaff_EBP + -0x20b4 + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x20b0 + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x20ac + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x20a8 + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x20a4 + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x20a0 + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x209c + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x2098 + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x2094 + *(int *)(unaff_EBP + -0x8494) * 4,
                                 unaff_EBP + -0x2090 + *(int *)(unaff_EBP + -0x8494) * 4);
                  }
                }
                else {
                  *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
                  *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
                  *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
                  FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%x %x %x",unaff_EBP + -0x1e24,
                               unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c);
                  if (*(int *)(unaff_EBP + -0x1e24) != 0) {
                    *(undefined4 *)(unaff_EBP + -0x1e24) = 1;
                  }
                  DAT_00a0e010 = *(undefined4 *)(unaff_EBP + -0x1e24);
                  if (*(int *)(unaff_EBP + -0x1e20) != 0) {
                    *(undefined4 *)(unaff_EBP + -0x1e20) = 1;
                  }
                  DAT_00a0e00c = *(undefined4 *)(unaff_EBP + -0x1e20);
                  if (*(int *)(unaff_EBP + -0x1e1c) != 0) {
                    *(undefined4 *)(unaff_EBP + -0x1e1c) = 1;
                  }
                  DAT_00a0e008 = *(undefined4 *)(unaff_EBP + -0x1e1c);
                }
              }
              else {
                *(undefined4 *)(unaff_EBP + -0x8490) = 0;
                while (*(int *)(unaff_EBP + -0x8490) < 0xb) {
                  *(undefined4 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) =
                       0xffffffff;
                  *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                }
                FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                             unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                             unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,
                             unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,unaff_EBP + -0x1e04);
                if ((0 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 0x15)) {
                  DAT_00a0c7f0 = *(undefined4 *)(unaff_EBP + -0x1e24);
                }
                if ((0 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 0x15)) {
                  DAT_00a0c7f4 = *(undefined4 *)(unaff_EBP + -0x1e20);
                }
                if ((-1 < *(int *)(unaff_EBP + -0x1e1c)) && (*(int *)(unaff_EBP + -0x1e1c) < 2)) {
                  DAT_00a0c7ec = *(undefined4 *)(unaff_EBP + -0x1e1c);
                }
                iVar3 = FUN_00420d10(*(undefined4 *)(unaff_EBP + -0x1e18));
                if (iVar3 != 0) {
                  DAT_00a0b42c = *(undefined4 *)(unaff_EBP + -0x1e18);
                }
                iVar3 = FUN_0046a2a0(*(undefined4 *)(unaff_EBP + -0x1e14));
                if (iVar3 != 0) {
                  DAT_00a0b41c = *(undefined4 *)(unaff_EBP + -0x1e14);
                }
                *(undefined4 *)(unaff_EBP + -0x85e8) = *(undefined4 *)(unaff_EBP + -0x1e10);
                if (*(int *)(unaff_EBP + -0x85e8) == 0) {
                  DAT_00a0b438 = 0;
                }
                else if (*(int *)(unaff_EBP + -0x85e8) == 1) {
                  DAT_00a0b438 = 0x100;
                }
                else if (*(int *)(unaff_EBP + -0x85e8) == 2) {
                  DAT_00a0b438 = 0x200;
                }
              }
            }
            else {
              *(undefined4 *)(unaff_EBP + -0x8494) = 0;
              iVar3 = FUN_00417110(unaff_EBP + -0x42a,&DAT_0095bce4,unaff_EBP + -0x8494);
              if (((iVar3 != 0) && (-1 < *(int *)(unaff_EBP + -0x8494))) &&
                 (*(int *)(unaff_EBP + -0x8494) < 0x10)) {
                *(undefined4 *)(unaff_EBP + -0x8490) = 0;
                while (*(int *)(unaff_EBP + -0x8490) < 0x10) {
                  *(undefined4 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) =
                       0xffffffff;
                  *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                }
                FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                             L"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",unaff_EBP + -0x1e28,
                             unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                             unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,
                             unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,unaff_EBP + -0x1e04,
                             unaff_EBP + -0x1e00,unaff_EBP + -0x1dfc,unaff_EBP + -0x1df8,
                             unaff_EBP + -0x1df4,unaff_EBP + -0x1df0,unaff_EBP + -0x1dec);
                *(undefined4 *)(unaff_EBP + -0x8490) = 0;
                while (*(int *)(unaff_EBP + -0x8490) < 0x10) {
                  if (((-1 < *(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4)) &&
                      (*(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) < 0x14)) &&
                     (*(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) != 10)) {
                    *(undefined2 *)
                     (&DAT_00a0eaec +
                     *(int *)(unaff_EBP + -0x8490) * 2 + *(int *)(unaff_EBP + -0x8494) * 0x24) =
                         *(undefined2 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4);
                  }
                  *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
                }
              }
            }
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x8494) = 0;
            iVar3 = FUN_00417110(unaff_EBP + -0x42a,&DAT_0095bce4,unaff_EBP + -0x8494);
            if (((iVar3 != 0) && (-1 < *(int *)(unaff_EBP + -0x8494))) &&
               (*(int *)(unaff_EBP + -0x8494) < 0x10)) {
              *(undefined4 *)(unaff_EBP + -0x8490) = 0;
              while (*(int *)(unaff_EBP + -0x8490) < 0x10) {
                *(undefined4 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) =
                     0xffffff9d;
                *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
              }
              FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                           L"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",unaff_EBP + -0x1e28,
                           unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                           unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,
                           unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,unaff_EBP + -0x1e04,
                           unaff_EBP + -0x1e00,unaff_EBP + -0x1dfc,unaff_EBP + -0x1df8,
                           unaff_EBP + -0x1df4,unaff_EBP + -0x1df0,unaff_EBP + -0x1dec);
              *(undefined4 *)(unaff_EBP + -0x8490) = 0;
              while (*(int *)(unaff_EBP + -0x8490) < 0x10) {
                if ((-3 < *(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4)) &&
                   (*(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) < 0x7531)) {
                  *(undefined4 *)
                   (&DAT_00a0e5dc +
                   *(int *)(unaff_EBP + -0x8490) * 4 + *(int *)(unaff_EBP + -0x8494) * 0x48) =
                       *(undefined4 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4);
                }
                *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
              }
            }
          }
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x8494) = 0;
          iVar3 = FUN_00417110(unaff_EBP + -0x42a,&DAT_0095bce4,unaff_EBP + -0x8494);
          if (((iVar3 != 0) && (-1 < *(int *)(unaff_EBP + -0x8494))) &&
             (*(int *)(unaff_EBP + -0x8494) < 0x10)) {
            *(undefined4 *)(unaff_EBP + -0x8490) = 0;
            while (*(int *)(unaff_EBP + -0x8490) < 0x10) {
              *(undefined4 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) = 0xffffffff;
              *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
            }
            FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                         L"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",unaff_EBP + -0x1e28,
                         unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                         unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,
                         unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,unaff_EBP + -0x1e04,
                         unaff_EBP + -0x1e00,unaff_EBP + -0x1dfc,unaff_EBP + -0x1df8,
                         unaff_EBP + -0x1df4,unaff_EBP + -0x1df0,unaff_EBP + -0x1dec);
            *(undefined4 *)(unaff_EBP + -0x8490) = 0;
            while (*(int *)(unaff_EBP + -0x8490) < 0x10) {
              if ((-1 < *(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4)) &&
                 (*(int *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4) < 10)) {
                *(undefined2 *)
                 (&DAT_00a0e354 +
                 *(int *)(unaff_EBP + -0x8490) * 2 + *(int *)(unaff_EBP + -0x8494) * 0x24) =
                     *(undefined2 *)(unaff_EBP + -0x1e28 + *(int *)(unaff_EBP + -0x8490) * 4);
              }
              *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
            }
          }
        }
      }
      else {
        FUN_0053ded0(unaff_EBP + -0x438,*(undefined4 *)(unaff_EBP + -0x8498),0);
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0xffffffff;
      iVar3 = FUN_00417110(unaff_EBP + -0x42c,&DAT_0095bce4,unaff_EBP + -0x8494);
      if (((iVar3 != 0) && (-1 < *(int *)(unaff_EBP + -0x8494))) &&
         (*(int *)(unaff_EBP + -0x8494) < 6)) {
        if (*(int *)(unaff_EBP + -0x8494) == 0) {
          *(undefined4 *)(unaff_EBP + -0x8490) = 0xffffffff;
          uVar2 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),&DAT_0095b714,
                               unaff_EBP + -0x8490);
          *(undefined4 *)(unaff_EBP + -0x849c) = uVar2;
          *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + -1;
          if (((*(int *)(unaff_EBP + -0x849c) != 0) && (-1 < *(int *)(unaff_EBP + -0x8490))) &&
             (*(int *)(unaff_EBP + -0x8490) < 5)) {
            DAT_00a0bf0c = *(undefined4 *)(unaff_EBP + -0x8490);
          }
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x8490) = 1;
          while (*(int *)(unaff_EBP + -0x8490) < 0xb) {
            *(undefined8 *)(unaff_EBP + -0x1ea0 + *(int *)(unaff_EBP + -0x8490) * 8) = 0;
            *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
          }
          uVar2 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                               L"%lg %lg %lg %lg %lg %lg %lg %lg %lg %lg",unaff_EBP + -0x1e98,
                               unaff_EBP + -0x1e90,unaff_EBP + -0x1e88,unaff_EBP + -0x1e80,
                               unaff_EBP + -0x1e78,unaff_EBP + -0x1e70,unaff_EBP + -0x1e68,
                               unaff_EBP + -0x1e60,unaff_EBP + -0x1e58,unaff_EBP + -0x1e50);
          *(undefined4 *)(unaff_EBP + -0x849c) = uVar2;
          *(int *)(unaff_EBP + -0x8494) = *(int *)(unaff_EBP + -0x8494) + -1;
          *(undefined8 *)(&DAT_00a0bf28 + *(int *)(unaff_EBP + -0x8494) * 8) =
               *(undefined8 *)(unaff_EBP + -0x1e98);
          if (1e-07 < *(double *)(unaff_EBP + -0x1e90)) {
            *(undefined8 *)(&DAT_00a0bf50 + *(int *)(unaff_EBP + -0x8494) * 8) =
                 *(undefined8 *)(unaff_EBP + -0x1e90);
          }
          if (1e-07 < *(double *)(unaff_EBP + -0x1e88)) {
            *(undefined8 *)(&DAT_00a0bf78 + *(int *)(unaff_EBP + -0x8494) * 8) =
                 *(undefined8 *)(unaff_EBP + -0x1e88);
          }
          if (*(double *)(unaff_EBP + -0x1e80) <= 0.5) {
            *(undefined4 *)(&DAT_00a0bf10 + *(int *)(unaff_EBP + -0x8494) * 4) = 0;
          }
          else {
            *(undefined4 *)(&DAT_00a0bf10 + *(int *)(unaff_EBP + -0x8494) * 4) = 1;
          }
        }
      }
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d",unaff_EBP + -0x1e24,
                 unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,
                 unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c);
    if ((0 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 0xb)) {
      DAT_00a0cb78 = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 2)) {
      DAT_00a0cb88 = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e1c)) && (*(int *)(unaff_EBP + -0x1e1c) < 2)) {
      DAT_00a0cb8c = *(undefined4 *)(unaff_EBP + -0x1e1c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 2)) {
      DAT_00a0cb80 = *(undefined4 *)(unaff_EBP + -0x1e18);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 2)) {
      DAT_00a0cb84 = *(undefined4 *)(unaff_EBP + -0x1e14);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e10)) && (*(int *)(unaff_EBP + -0x1e10) < 3)) {
      DAT_00a0cb7c = *(undefined4 *)(unaff_EBP + -0x1e10);
    }
    *(undefined4 *)(unaff_EBP + -0x8490) = 0;
    while (*(int *)(unaff_EBP + -0x8490) < 2) {
      uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x8498),0x2c);
      *(undefined4 *)(unaff_EBP + -0x8498) = uVar2;
      if (*(int *)(unaff_EBP + -0x8498) == 0) break;
      *(int *)(unaff_EBP + -0x8498) = *(int *)(unaff_EBP + -0x8498) + 2;
      FUN_00525d60(unaff_EBP + -0xc88,&DAT_00955904,*(undefined4 *)(unaff_EBP + -0x8498));
      uVar2 = FUN_00457e50(unaff_EBP + -0xc88,0x2c);
      *(undefined4 *)(unaff_EBP + -0x8554) = uVar2;
      if (*(int *)(unaff_EBP + -0x8554) != 0) {
        **(undefined2 **)(unaff_EBP + -0x8554) = 0;
      }
      uVar2 = FUN_00457e50(unaff_EBP + -0xc88,10);
      *(undefined4 *)(unaff_EBP + -0x8554) = uVar2;
      if (*(int *)(unaff_EBP + -0x8554) != 0) {
        **(undefined2 **)(unaff_EBP + -0x8554) = 0;
      }
      *(undefined4 *)(unaff_EBP + -0x87b8) = 10;
      *(int *)(unaff_EBP + -0x8664) = *(int *)(unaff_EBP + -0x87b8) << 1;
      if (0x3ff < *(uint *)(unaff_EBP + -0x8664)) {
                    /* WARNING: Subroutine does not return */
        FUN_008d927f();
      }
      *(undefined2 *)(unaff_EBP + -0xc88 + *(int *)(unaff_EBP + -0x8664)) = 0;
      if (*(int *)(unaff_EBP + -0x8490) == 0) {
        FUN_004059f0(&DAT_00a0cb90,&DAT_00955904,unaff_EBP + -0xc88);
      }
      else {
        FUN_004059f0(&DAT_00a0cb94,&DAT_00955904,unaff_EBP + -0xc88);
      }
      uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x8498),0x2c);
      *(undefined4 *)(unaff_EBP + -0x8498) = uVar2;
      if (*(int *)(unaff_EBP + -0x8498) == 0) break;
      *(int *)(unaff_EBP + -0x8498) = *(int *)(unaff_EBP + -0x8498) + 2;
      *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
    }
  }
LAB_005293fd:
  while( true ) {
    do {
      do {
        iVar3 = FUN_004f0900(unaff_EBP + -0x1c88,0x200,*(undefined4 *)(unaff_EBP + -0x84b4),
                             *(undefined4 *)(unaff_EBP + -0x85a8));
        if (iVar3 == 0) {
          if (*(int *)(unaff_EBP + -0x84b4) != 0) {
            _fclose(*(FILE **)(unaff_EBP + -0x84b4));
            *(undefined4 *)(unaff_EBP + -0x84b4) = 0;
          }
          FUN_004b7740();
          if (*(int *)(unaff_EBP + -0x86d4) != 0) {
            FUN_0053dc90();
          }
          if ((*(int *)(unaff_EBP + -0x854c) == 1) &&
             (*(int *)(*(int *)(unaff_EBP + -0x848c) + 800) != -2)) {
            FUN_0053d830();
          }
          *(undefined4 *)(unaff_EBP + -0x8490) = 1;
          while (*(int *)(unaff_EBP + -0x8490) < 0x65) {
            if (-1 < *(int *)(unaff_EBP + -0x20b8 + *(int *)(unaff_EBP + -0x8490) * 4)) {
              iVar3 = *(int *)(unaff_EBP + -0x20b8 + *(int *)(unaff_EBP + -0x8490) * 4);
              *(int *)(unaff_EBP + -0x85f0) = (int)(iVar3 + (iVar3 >> 0x1f & 0xfU)) >> 4;
              if ((-1 < *(int *)(unaff_EBP + -0x85f0)) && (*(int *)(unaff_EBP + -0x85f0) < 0x10)) {
                *(undefined4 *)(&DAT_00a0e014 + *(int *)(unaff_EBP + -0x8490) * 4) =
                     *(undefined4 *)(unaff_EBP + -0x85f0);
              }
              uVar4 = *(uint *)(unaff_EBP + -0x20b8 + *(int *)(unaff_EBP + -0x8490) * 4) &
                      0x8000000f;
              if ((int)uVar4 < 0) {
                uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
              }
              *(uint *)(unaff_EBP + -0x8618) = uVar4;
              if ((-1 < *(int *)(unaff_EBP + -0x8618)) && (*(int *)(unaff_EBP + -0x8618) < 0x10)) {
                *(undefined4 *)(&DAT_00a0e1b4 + *(int *)(unaff_EBP + -0x8490) * 4) =
                     *(undefined4 *)(unaff_EBP + -0x8618);
              }
            }
            *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
          }
          *(undefined4 *)(unaff_EBP + -0x84f8) =
               *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x256c);
          *(uint *)(unaff_EBP + -0x849c) =
               (uint)*(ushort *)
                      (&DAT_00a0e354 +
                      *(int *)(**(int **)(unaff_EBP + -0x848c) + 0x24ec +
                              *(int *)(unaff_EBP + -0x84f8) * 4) * 2 +
                      *(int *)(unaff_EBP + -0x84f8) * 0x24);
          iVar3 = FUN_00420d10(*(undefined4 *)(unaff_EBP + -0x849c));
          if (iVar3 != 0) {
            DAT_00a0b428 = *(int *)(unaff_EBP + -0x849c);
          }
          if (DAT_00a0ca90 == 0) {
            DAT_00a0b424 = 0;
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x849c) =
                 *(undefined4 *)
                  (&DAT_00a0e5dc +
                  *(int *)(**(int **)(unaff_EBP + -0x848c) + 0x24ec +
                          *(int *)(unaff_EBP + -0x84f8) * 4) * 4 +
                  *(int *)(unaff_EBP + -0x84f8) * 0x48);
            if ((-1 < *(int *)(unaff_EBP + -0x849c)) && (*(int *)(unaff_EBP + -0x849c) < 0x7531)) {
              DAT_00a0b424 = *(undefined4 *)(unaff_EBP + -0x849c);
              *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x7470 + DAT_00a0b428 * 4) =
                   DAT_00a0b424;
            }
          }
          *(uint *)(unaff_EBP + -0x84fc) =
               (uint)*(ushort *)
                      (&DAT_00a0eaec +
                      *(int *)(**(int **)(unaff_EBP + -0x848c) + 0x24ec +
                              *(int *)(unaff_EBP + -0x84f8) * 4) * 2 +
                      *(int *)(unaff_EBP + -0x84f8) * 0x24);
          iVar3 = FUN_0046a2a0(*(undefined4 *)(unaff_EBP + -0x84fc));
          if (iVar3 != 0) {
            DAT_00a0b418 = *(undefined4 *)(unaff_EBP + -0x84fc);
          }
          if ((*(int *)(*(int *)(unaff_EBP + -0x848c) + 0x324) != 0) &&
             (**(int **)(unaff_EBP + -0x848c) != 0)) {
            *(undefined4 *)(unaff_EBP + -0x86d8) = **(undefined4 **)(unaff_EBP + -0x848c);
            if (*(int *)(unaff_EBP + -0x86d8) == 0) {
              *(undefined4 *)(unaff_EBP + -0x86dc) = 0;
            }
            else {
              *(int *)(unaff_EBP + -0x86dc) = *(int *)(unaff_EBP + -0x86d8) + 0x88;
            }
            FUN_0060b020(*(undefined4 *)(unaff_EBP + -0x86dc),**(undefined4 **)(unaff_EBP + -0x848c)
                         ,0);
            *(undefined1 *)(unaff_EBP + -4) = 6;
            FUN_004578a0(0);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_0060b110();
          }
          iVar3 = FUN_00404c80();
          if (iVar3 != 0) {
            uVar7 = 0;
            uVar6 = 0x8059;
            uVar2 = 0x111;
            FUN_00404c80(0x111,0x8059,0);
            FUN_00406bc0(uVar2,uVar6,uVar7);
            uVar7 = 0;
            uVar6 = 0x8057;
            uVar2 = 0x111;
            FUN_00404c80(0x111,0x8057,0);
            FUN_00406bc0(uVar2,uVar6,uVar7);
            uVar7 = 0;
            uVar6 = 0x80b5;
            uVar2 = 0x111;
            FUN_00404c80(0x111,0x80b5,0);
            FUN_00406bc0(uVar2,uVar6,uVar7);
          }
          *(undefined4 *)(unaff_EBP + -0x87c4) = 1;
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_00447100();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_00404540();
          ExceptionList = *(void **)(unaff_EBP + -0xc);
          return *(undefined4 *)(unaff_EBP + -0x87c4);
        }
        *(undefined4 *)(unaff_EBP + -0x8490) = 0;
        while ((*(short *)(unaff_EBP + -0x1c88 + *(int *)(unaff_EBP + -0x8490) * 2) == 0x20 ||
               (*(short *)(unaff_EBP + -0x1c88 + *(int *)(unaff_EBP + -0x8490) * 2) == 9))) {
          *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
        }
        FUN_004d3340(unaff_EBP + -0x438,unaff_EBP + -0x1c88 + *(int *)(unaff_EBP + -0x8490) * 2);
        iVar3 = FUN_0053e180(unaff_EBP + -0x438,&DAT_0096685c);
        if (iVar3 != 0) {
          uVar2 = FUN_005339fc();
          return uVar2;
        }
        iVar3 = FUN_0053e180(unaff_EBP + -0x438,&DAT_00966864);
        if (iVar3 != 0) {
          uVar2 = FUN_005339fc();
          return uVar2;
        }
        iVar3 = FUN_0053e180(unaff_EBP + -0x438,&DAT_0096686c);
        if (iVar3 != 0) {
          uVar2 = FUN_005339fc();
          return uVar2;
        }
        uVar2 = FUN_008f899d(unaff_EBP + -0x438);
        *(undefined4 *)(unaff_EBP + -0x87bc) = uVar2;
      } while ((*(int *)(unaff_EBP + -0x87bc) < 5) || (*(short *)(unaff_EBP + -0x438) == 0x23));
      uVar2 = FUN_00457e50(unaff_EBP + -0x438,0x3d);
      *(undefined4 *)(unaff_EBP + -0x8498) = uVar2;
    } while (*(int *)(unaff_EBP + -0x8498) == 0);
    *(int *)(unaff_EBP + -0x8498) = *(int *)(unaff_EBP + -0x8498) + 2;
    iVar3 = FUN_0053e180(unaff_EBP + -0x438,*(int *)(unaff_EBP + -0x848c) + 0x330);
    if (iVar3 != 0) {
      iVar3 = FUN_0053e180(unaff_EBP + -0x434,L"KAGE");
      if (iVar3 != 0) {
        *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
        FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d",unaff_EBP + -0x1e24,
                     unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,unaff_EBP + -0x1e14
                     ,unaff_EBP + -0x1e10);
        if (-1 < *(int *)(unaff_EBP + -0x1e24)) {
          DAT_00a0bea8 = *(undefined4 *)(unaff_EBP + -0x1e24);
        }
      }
      iVar3 = FUN_0053e180(unaff_EBP + -0x434,L"FLG_0");
      if (iVar3 != 0) {
        *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
        FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d",unaff_EBP + -0x1e24,
                     unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,unaff_EBP + -0x1e14
                     ,unaff_EBP + -0x1e10);
        if ((-1 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 0x100)) {
          DAT_00a08adc = *(uint *)(unaff_EBP + -0x1e24);
        }
      }
      iVar3 = FUN_0053e180(unaff_EBP + -0x434,L"FLG_1");
      if (iVar3 != 0) {
        *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
        FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d",unaff_EBP + -0x1e24,
                     unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,unaff_EBP + -0x1e14
                     ,unaff_EBP + -0x1e10);
        *(undefined4 *)(unaff_EBP + -0x8490) = 0;
        if (0 < *(int *)(unaff_EBP + -0x1e24)) {
          *(undefined4 *)(unaff_EBP + -0x8490) = 1;
        }
        DAT_00a0cabc = *(undefined4 *)(unaff_EBP + -0x8490);
        *(undefined4 *)(unaff_EBP + -0x8490) = 0;
        if (0 < *(int *)(unaff_EBP + -0x1e20)) {
          *(undefined4 *)(unaff_EBP + -0x8490) = *(undefined4 *)(unaff_EBP + -0x1e20);
        }
        *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x83d8) =
             *(undefined4 *)(unaff_EBP + -0x8490);
        *(undefined4 *)(unaff_EBP + -0x8490) = 0;
        if (0 < *(int *)(unaff_EBP + -0x1e1c)) {
          *(undefined4 *)(unaff_EBP + -0x8490) = *(undefined4 *)(unaff_EBP + -0x1e1c);
        }
        *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x83a8) =
             *(undefined4 *)(unaff_EBP + -0x8490);
      }
    }
    iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"JWW_USER");
    if (iVar3 == 0) break;
    uVar2 = FUN_004f7820(unaff_EBP + -0x87b4,*(undefined4 *)(unaff_EBP + -0x8498));
    *(undefined4 *)(unaff_EBP + -0x87c0) = uVar2;
    *(undefined4 *)(unaff_EBP + -0x87c8) = *(undefined4 *)(unaff_EBP + -0x87c0);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00404860(*(undefined4 *)(unaff_EBP + -0x87c8));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00404540();
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,unaff_EBP + -0x38);
  if (iVar3 != 0) goto code_r0x0052998f;
  goto LAB_00529b41;
code_r0x0052998f:
  *(undefined4 *)(unaff_EBP + -0x8508) = 0xffffffff;
  FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),&DAT_0095703c,unaff_EBP + -0x8508);
  if (*(int *)(unaff_EBP + -0x8508) < 0) goto LAB_005293fd;
  FUN_00404900(&DAT_00956338);
  if (*(int *)(unaff_EBP + -0x8508) == 0) {
    DAT_00a08ae0 = 0;
    goto LAB_005293fd;
  }
  if (0 < *(int *)(unaff_EBP + -0x8508)) {
    DAT_00a08ae0 = *(undefined4 *)(unaff_EBP + -0x8508);
  }
  uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x8498),0x2c);
  *(undefined4 *)(unaff_EBP + -0x8498) = uVar2;
  if (*(int *)(unaff_EBP + -0x8498) != 0) {
    FUN_00525d60(unaff_EBP + -0x1488,&DAT_00955904,*(int *)(unaff_EBP + -0x8498) + 2);
    uVar2 = FUN_00457e50(unaff_EBP + -0x1488,0x2c);
    *(undefined4 *)(unaff_EBP + -0x850c) = uVar2;
    if (*(int *)(unaff_EBP + -0x850c) != 0) {
      **(undefined2 **)(unaff_EBP + -0x850c) = 0;
    }
    uVar2 = FUN_00457e50(unaff_EBP + -0x1488,10);
    *(undefined4 *)(unaff_EBP + -0x850c) = uVar2;
    if (*(int *)(unaff_EBP + -0x850c) != 0) {
      **(undefined2 **)(unaff_EBP + -0x850c) = 0;
    }
    *(undefined4 *)(unaff_EBP + -0x86e0) = 0x14;
    if (0x3ff < *(uint *)(unaff_EBP + -0x86e0)) {
                    /* WARNING: Subroutine does not return */
      FUN_008d927f();
    }
    *(undefined2 *)(unaff_EBP + -0x1488 + *(int *)(unaff_EBP + -0x86e0)) = 0;
    CStringT<>(unaff_EBP + -0x1488);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005acca0(0);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005ad8b0(unaff_EBP + -0x8620);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_00525ee0();
    FUN_00404860(unaff_EBP + -0x8620);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00404540();
  }
LAB_00529b41:
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"REF_FILE");
  if (iVar3 != 0) {
    uVar2 = FUN_004f7820(unaff_EBP + -0x87b0,*(undefined4 *)(unaff_EBP + -0x8498));
    *(undefined4 *)(unaff_EBP + -0x87cc) = uVar2;
    *(undefined4 *)(unaff_EBP + -0x87d0) = *(undefined4 *)(unaff_EBP + -0x87cc);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_00404860(*(undefined4 *)(unaff_EBP + -0x87d0));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00404540();
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"OldVerSave");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),&DAT_0095b714,unaff_EBP + -0x1e24);
    DAT_00a0b3e8 = 700;
    if (*(int *)(unaff_EBP + -0x1e24) < 700) {
      DAT_00a0b3e8 = 600;
    }
    if (*(int *)(unaff_EBP + -0x1e24) < 600) {
      DAT_00a0b3e8 = 0x1a4;
    }
    if (*(int *)(unaff_EBP + -0x1e24) < 0x1a4) {
      DAT_00a0b3e8 = 0x15f;
    }
    if (*(int *)(unaff_EBP + -0x1e24) < 0x15f) {
      DAT_00a0b3e8 = 300;
    }
    if (*(int *)(unaff_EBP + -0x1e24) < 300) {
      DAT_00a0b3e8 = 0xe6;
    }
    if (*(int *)(unaff_EBP + -0x1e24) < 0xe6) {
      DAT_00a0b3e8 = 0xe1;
    }
    if (*(int *)(unaff_EBP + -0x1e24) < 0xe1) {
      DAT_00a0b3e8 = 0xdf;
    }
    if (*(int *)(unaff_EBP + -0x1e24) < 0xdf) {
      DAT_00a0b3e8 = 0xdc;
    }
    if (*(int *)(unaff_EBP + -0x1e24) < 0xdc) {
      DAT_00a0b3e8 = 600;
    }
    if (*(int *)(unaff_EBP + -0x1e24) == 0) {
      DAT_00a0b3e8 = 700;
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"AutoSaveDir");
  if (iVar3 != 0) {
    iVar3 = FUN_008f899d(*(undefined4 *)(unaff_EBP + -0x8498));
    if (*(short *)(*(int *)(unaff_EBP + -0x8498) + -2 + iVar3 * 2) == 10) {
      iVar3 = FUN_008f899d(*(undefined4 *)(unaff_EBP + -0x8498));
      *(undefined2 *)(*(int *)(unaff_EBP + -0x8498) + -2 + iVar3 * 2) = 0;
    }
    uVar2 = FUN_008f899d(*(undefined4 *)(unaff_EBP + -0x8498));
    *(undefined4 *)(unaff_EBP + -0x86e4) = uVar2;
    *(undefined4 *)(unaff_EBP + -0x849c) = 0;
    while (*(int *)(unaff_EBP + -0x849c) < *(int *)(unaff_EBP + -0x86e4)) {
      if ((*(short *)(*(int *)(unaff_EBP + -0x8498) + *(int *)(unaff_EBP + -0x849c) * 2) == 0x5c) &&
         (*(int *)(unaff_EBP + -0x849c) == *(int *)(unaff_EBP + -0x86e4) + -1)) {
        *(undefined2 *)(*(int *)(unaff_EBP + -0x8498) + *(int *)(unaff_EBP + -0x849c) * 2) = 0;
      }
      *(int *)(unaff_EBP + -0x849c) = *(int *)(unaff_EBP + -0x849c) + 1;
    }
    DAT_00a0cb08 = 0;
    uVar2 = StringFindCharRev(unaff_EBP + -0x438,0x2a);
    *(undefined4 *)(unaff_EBP + -0x85f4) = uVar2;
    if (*(int *)(unaff_EBP + -0x85f4) != 0) {
      **(undefined2 **)(unaff_EBP + -0x85f4) = 0;
      DAT_00a0cb08 = 1;
      *(undefined4 *)(unaff_EBP + -0x849c) = 0xffffffff;
      FUN_00417110(*(int *)(unaff_EBP + -0x85f4) + 2,&DAT_0095b714,unaff_EBP + -0x849c);
      if ((4 < *(int *)(unaff_EBP + -0x849c)) && (*(int *)(unaff_EBP + -0x849c) < 100)) {
        DAT_00a0cb10 = *(undefined4 *)(unaff_EBP + -0x849c);
        FUN_007a3b9c(L"AutoSave",L"MaxNumbar",*(undefined4 *)(unaff_EBP + -0x849c));
        if (*(int *)(unaff_EBP + -0x849c) < DAT_00a0cb0c) {
          DAT_00a0cb0c = 0;
          FUN_007a3b9c(L"AutoSave",L"Numbar",1);
        }
      }
      *(int *)(unaff_EBP + -0x87d8) = *(int *)(unaff_EBP + -0x8498) - (unaff_EBP + -0x438) >> 1;
      *(int *)(unaff_EBP + -0x87dc) = 0x200 - *(int *)(unaff_EBP + -0x87d8);
      if (**(short **)(unaff_EBP + -0x8498) == 0) {
        _wcscpy_s(*(wchar_t **)(unaff_EBP + -0x8498),*(rsize_t *)(unaff_EBP + -0x87dc),
                  (wchar_t *)&DAT_00a08f74);
      }
    }
    FUN_00404900(*(undefined4 *)(unaff_EBP + -0x8498));
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"R_STR0_00");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8514) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x8510) = *(undefined4 *)(unaff_EBP + -0x8514);
    *(undefined4 *)(unaff_EBP + -0x85d4) = *(undefined4 *)(unaff_EBP + -0x8510);
    *(undefined4 *)(unaff_EBP + -0x85d0) = 0;
    *(undefined8 *)(unaff_EBP + -0x8764) = 0;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lg %d %d %d %d",unaff_EBP + -0x8764,
                 unaff_EBP + -0x85d4,unaff_EBP + -0x8510,unaff_EBP + -0x8514,unaff_EBP + -0x85d0);
    if (1e-07 < *(double *)(unaff_EBP + -0x8764)) {
      DAT_00a0d630 = *(undefined8 *)(unaff_EBP + -0x8764);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x85d4)) && (*(int *)(unaff_EBP + -0x85d4) < 2)) {
      DAT_00a0d62c = *(undefined4 *)(unaff_EBP + -0x85d4);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x8510)) && (*(int *)(unaff_EBP + -0x8510) < 2)) {
      DAT_00a0bcc8 = *(undefined4 *)(unaff_EBP + -0x8510);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x8514)) && (*(int *)(unaff_EBP + -0x8514) < 2)) {
      DAT_00a0bd34 = *(undefined4 *)(unaff_EBP + -0x8514);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x85d0)) && (*(int *)(unaff_EBP + -0x85d0) < 2)) {
      DAT_00a0d648 = *(undefined4 *)(unaff_EBP + -0x85d0);
    }
    uVar2 = FUN_00457e50(*(undefined4 *)(unaff_EBP + -0x8498),0x2c);
    *(undefined4 *)(unaff_EBP + -0x8498) = uVar2;
    if (*(int *)(unaff_EBP + -0x8498) != 0) {
      *(int *)(unaff_EBP + -0x8498) = *(int *)(unaff_EBP + -0x8498) + 2;
      FUN_00525d60(unaff_EBP + -0x1088,&DAT_00955904,*(undefined4 *)(unaff_EBP + -0x8498));
      uVar2 = FUN_00457e50(unaff_EBP + -0x1088,0x2c);
      *(undefined4 *)(unaff_EBP + -0x8518) = uVar2;
      if (*(int *)(unaff_EBP + -0x8518) != 0) {
        **(undefined2 **)(unaff_EBP + -0x8518) = 0;
      }
      uVar2 = FUN_00457e50(unaff_EBP + -0x1088,10);
      *(undefined4 *)(unaff_EBP + -0x8518) = uVar2;
      if (*(int *)(unaff_EBP + -0x8518) != 0) {
        **(undefined2 **)(unaff_EBP + -0x8518) = 0;
      }
      *(undefined4 *)(unaff_EBP + -0x84cc) = 6;
      *(int *)(unaff_EBP + -0x86f0) = *(int *)(unaff_EBP + -0x84cc) << 1;
      if (0x3ff < *(uint *)(unaff_EBP + -0x86f0)) {
                    /* WARNING: Subroutine does not return */
        FUN_008d927f();
      }
      *(undefined2 *)(unaff_EBP + -0x1088 + *(int *)(unaff_EBP + -0x86f0)) = 0;
      FUN_004059f0(&DAT_00a0d644,&DAT_00955904,unaff_EBP + -0x1088);
    }
    if (*(int *)(unaff_EBP + -0x85c8) == 0) {
      *(undefined4 *)(unaff_EBP + -0x85c8) = 1;
      DAT_00a0d64c = 0;
      *(undefined4 *)(unaff_EBP + -0x84cc) = 0;
      while (*(int *)(unaff_EBP + -0x84cc) < 0x3d) {
        *(undefined4 *)(&DAT_00a0d650 + *(int *)(unaff_EBP + -0x84cc) * 4) = 0;
        *(undefined4 *)(&DAT_00a0d758 + *(int *)(unaff_EBP + -0x84cc) * 4) = 0;
        *(int *)(unaff_EBP + -0x84cc) = *(int *)(unaff_EBP + -0x84cc) + 1;
      }
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"R_CROSS_SET");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x1778) = 1;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d",unaff_EBP + -0x1e24,
                 unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,
                 unaff_EBP + -0x1e10);
    if ((-1 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 2)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x1780) =
           *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 3)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x1784) =
           *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e1c)) && (*(int *)(unaff_EBP + -0x1e1c) < 4)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x1798) =
           *(undefined4 *)(unaff_EBP + -0x1e1c);
    }
    if ((1 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 0x33)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x179c) =
           *(undefined4 *)(unaff_EBP + -0x1e18);
    }
    if ((1 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 0x33)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x17a0) =
           *(undefined4 *)(unaff_EBP + -0x1e14);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e10)) && (*(int *)(unaff_EBP + -0x1e10) < 2)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x17a4) =
           *(undefined4 *)(unaff_EBP + -0x1e10);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"R_CROSS_ST");
  if (iVar3 != 0) {
    if (*(int *)(unaff_EBP + -0x85c8) == 0) {
      *(undefined4 *)(unaff_EBP + -0x85c8) = 1;
      DAT_00a0d64c = 0;
      *(undefined4 *)(unaff_EBP + -0x851c) = 0;
      while (*(int *)(unaff_EBP + -0x851c) < 0x3d) {
        *(undefined4 *)(&DAT_00a0d650 + *(int *)(unaff_EBP + -0x851c) * 4) = 0;
        *(undefined4 *)(&DAT_00a0d758 + *(int *)(unaff_EBP + -0x851c) * 4) = 0;
        *(int *)(unaff_EBP + -0x851c) = *(int *)(unaff_EBP + -0x851c) + 1;
      }
    }
    *(undefined4 *)(unaff_EBP + -0x84b8) = 0;
    iVar3 = FUN_00417110(unaff_EBP + -0x424,&DAT_0095b714,unaff_EBP + -0x84b8);
    if ((((iVar3 != 0) && (0 < *(int *)(unaff_EBP + -0x84b8))) &&
        (*(int *)(unaff_EBP + -0x84b8) < 0x1f)) &&
       (FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d",
                     &DAT_00a0d650 + *(int *)(unaff_EBP + -0x84b8) * 4,
                     &DAT_00a0d758 + *(int *)(unaff_EBP + -0x84b8) * 4,
                     &DAT_00a0d6c8 + *(int *)(unaff_EBP + -0x84b8) * 4,
                     &DAT_00a0d7d0 + *(int *)(unaff_EBP + -0x84b8) * 4),
       DAT_00a0d64c < *(int *)(unaff_EBP + -0x84b8))) {
      DAT_00a0d64c = *(int *)(unaff_EBP + -0x84b8);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_0");
  if (iVar3 != 0) {
    if (*(int *)(*(int *)(unaff_EBP + -0x848c) + 0x324) != 0) goto LAB_005293fd;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1df8) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1dfc) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e00) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%x %d %x %d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04,unaff_EBP + -0x1e00,unaff_EBP + -0x1dfc,unaff_EBP + -0x1df8);
    *(int *)(unaff_EBP + -0x85a0) =
         (int)(*(int *)(unaff_EBP + -0x1e24) + (*(int *)(unaff_EBP + -0x1e24) >> 0x1f & 0xfU)) >> 4;
    uVar4 = *(uint *)(unaff_EBP + -0x1e24) & 0x8000000f;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
    }
    *(uint *)(unaff_EBP + -0x8574) = uVar4;
    if ((-1 < *(int *)(unaff_EBP + -0x85a0)) && (*(int *)(unaff_EBP + -0x85a0) < 0x10)) {
      *(undefined4 *)(unaff_EBP + -0x84fc) =
           *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x256c);
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x256c) =
           *(undefined4 *)(unaff_EBP + -0x85a0);
      *(undefined4 *)(unaff_EBP + -0x849c) = *(undefined4 *)(unaff_EBP + -0x85a0);
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x242c + *(int *)(unaff_EBP + -0x84fc) * 4)
           = 2;
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x242c + *(int *)(unaff_EBP + -0x849c) * 4)
           = 3;
    }
    if ((-1 < *(int *)(unaff_EBP + -0x8574)) && (*(int *)(unaff_EBP + -0x8574) < 0x10)) {
      *(undefined4 *)(unaff_EBP + -0x84fc) =
           *(undefined4 *)
            (**(int **)(unaff_EBP + -0x848c) + 0x24ec +
            *(int *)(**(int **)(unaff_EBP + -0x848c) + 0x256c) * 4);
      *(undefined4 *)
       (**(int **)(unaff_EBP + -0x848c) + 0x24ec +
       *(int *)(**(int **)(unaff_EBP + -0x848c) + 0x256c) * 4) =
           *(undefined4 *)(unaff_EBP + -0x8574);
      *(undefined4 *)(unaff_EBP + -0x849c) = *(undefined4 *)(unaff_EBP + -0x8574);
      *(undefined4 *)
       (**(int **)(unaff_EBP + -0x848c) + 0x182c +
        *(int *)(**(int **)(unaff_EBP + -0x848c) + 0x256c) * 0x40 +
       *(int *)(unaff_EBP + -0x84fc) * 4) = 2;
      *(undefined4 *)
       (**(int **)(unaff_EBP + -0x848c) + 0x182c +
        *(int *)(**(int **)(unaff_EBP + -0x848c) + 0x256c) * 0x40 +
       *(int *)(unaff_EBP + -0x849c) * 4) = 3;
    }
    DAT_00a08b58 = 1;
    if (*(int *)(unaff_EBP + -0x1e20) < 1) {
      *(int *)(unaff_EBP + -0x86f4) = -*(int *)(unaff_EBP + -0x1e20);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x86f4) = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if (9999 < *(int *)(unaff_EBP + -0x86f4)) {
      *(int *)(unaff_EBP + -0x1e20) = *(int *)(unaff_EBP + -0x1e20) % 10000;
      DAT_00a08b58 = 0;
    }
    DAT_00a0cacc = 0;
    if (*(int *)(unaff_EBP + -0x1e20) < 1) {
      *(int *)(unaff_EBP + -0x86f8) = -*(int *)(unaff_EBP + -0x1e20);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x86f8) = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if (0x3fb < *(int *)(unaff_EBP + -0x86f8)) {
      if (*(int *)(unaff_EBP + -0x1e20) < 1) {
        *(int *)(unaff_EBP + -0x86fc) = -*(int *)(unaff_EBP + -0x1e20);
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x86fc) = *(undefined4 *)(unaff_EBP + -0x1e20);
      }
      if (*(int *)(unaff_EBP + -0x86fc) < 0x4b1) {
        *(int *)(unaff_EBP + -0x1e20) = *(int *)(unaff_EBP + -0x1e20) % 1000;
        DAT_00a0cacc = 1;
      }
    }
    if (*(int *)(unaff_EBP + -0x1e20) < 1) {
      *(int *)(unaff_EBP + -0x8700) = -*(int *)(unaff_EBP + -0x1e20);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x8700) = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if (0x13 < *(int *)(unaff_EBP + -0x8700)) {
      if (*(int *)(unaff_EBP + -0x1e20) < 1) {
        *(int *)(unaff_EBP + -0x8704) = -*(int *)(unaff_EBP + -0x1e20);
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x8704) = *(undefined4 *)(unaff_EBP + -0x1e20);
      }
      if (*(int *)(unaff_EBP + -0x8704) < 0xc9) {
        DAT_00a0cad4 = *(int *)(unaff_EBP + -0x1e20);
        DAT_00a0cad8 = DAT_00a0cad4 * DAT_00a0cad4;
      }
    }
    if (-1 < *(int *)(unaff_EBP + -0x1e1c)) {
      *(undefined4 *)(unaff_EBP + -0x84a8) = 0xffffffff;
      if (*(int *)(unaff_EBP + -0x1e1c) == 0x100) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 0xe;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0x50) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 0xd;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0x10) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 0xc;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0x5a) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 0xb;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0x4a) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 10;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0x3a) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 9;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0x2a) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 8;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0xa0) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 0;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0xa1) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 1;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0xa2) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 2;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0xa3) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 3;
      }
      if (*(int *)(unaff_EBP + -0x1e1c) == 0xa4) {
        *(undefined4 *)(unaff_EBP + -0x84a8) = 4;
      }
      if ((**(int **)(unaff_EBP + -0x848c) != 0) && (-1 < *(int *)(unaff_EBP + -0x84a8))) {
        FUN_00449cb0(**(undefined4 **)(unaff_EBP + -0x848c),*(undefined4 *)(unaff_EBP + -0x84a8));
      }
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 2)) {
      DAT_00a0c7e4 = *(undefined4 *)(unaff_EBP + -0x1e18);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 2)) {
      DAT_00a0c7e8 = *(undefined4 *)(unaff_EBP + -0x1e14);
    }
    if (*(int *)(unaff_EBP + -0x1e10) < 1) {
      *(int *)(unaff_EBP + -0x8708) = -*(int *)(unaff_EBP + -0x1e10);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x8708) = *(undefined4 *)(unaff_EBP + -0x1e10);
    }
    if (0x31 < *(int *)(unaff_EBP + -0x8708)) {
      if (*(int *)(unaff_EBP + -0x1e10) < 1) {
        *(int *)(unaff_EBP + -0x870c) = -*(int *)(unaff_EBP + -0x1e10);
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x870c) = *(undefined4 *)(unaff_EBP + -0x1e10);
      }
      if (*(int *)(unaff_EBP + -0x870c) < 0x3e9) {
        DAT_00a0d8ec = *(int *)(unaff_EBP + -0x1e10);
      }
    }
    if (DAT_00a0cad4 < 1) {
      *(int *)(unaff_EBP + -0x8710) = -DAT_00a0cad4;
    }
    else {
      *(int *)(unaff_EBP + -0x8710) = DAT_00a0cad4;
    }
    *(int *)(unaff_EBP + -0x85f8) = *(int *)(unaff_EBP + -0x8710) << 1;
    if (DAT_00a0d8ec < 1) {
      *(int *)(unaff_EBP + -0x8714) = -DAT_00a0d8ec;
    }
    else {
      *(int *)(unaff_EBP + -0x8714) = DAT_00a0d8ec;
    }
    if (*(int *)(unaff_EBP + -0x8714) < *(int *)(unaff_EBP + -0x85f8)) {
      if (DAT_00a0d8ec < 1) {
        DAT_00a0d8ec = -*(int *)(unaff_EBP + -0x85f8);
      }
      else {
        DAT_00a0d8ec = *(int *)(unaff_EBP + -0x85f8);
      }
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e0c)) && (*(int *)(unaff_EBP + -0x1e0c) < 2)) {
      DAT_00a0bc40 = *(undefined4 *)(unaff_EBP + -0x1e0c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e08)) && (*(int *)(unaff_EBP + -0x1e08) < 3)) {
      DAT_00a0b3e4 = *(undefined4 *)(unaff_EBP + -0x1e08);
    }
    if (-1 < *(int *)(unaff_EBP + -0x1e04)) {
      *(undefined4 *)(unaff_EBP + -0x8578) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -34000) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x84d4) = 0xffffffff;
      *(int *)(unaff_EBP + -0x8578) = *(int *)(unaff_EBP + -0x1e04) % 10;
      *(int *)(unaff_EBP + -34000) = *(int *)(unaff_EBP + -0x1e04) / 10;
      *(int *)(unaff_EBP + -34000) = *(int *)(unaff_EBP + -34000) % 10;
      *(int *)(unaff_EBP + -0x84d4) = *(int *)(unaff_EBP + -0x1e04) / 100;
      *(int *)(unaff_EBP + -0x84d4) = *(int *)(unaff_EBP + -0x84d4) % 10;
      if ((-1 < *(int *)(unaff_EBP + -0x8578)) && (*(int *)(unaff_EBP + -0x8578) < 9)) {
        DAT_00a0b478 = *(undefined4 *)(unaff_EBP + -0x8578);
      }
      if ((-1 < *(int *)(unaff_EBP + -34000)) && (*(int *)(unaff_EBP + -34000) < 5)) {
        DAT_00a0b480 = *(undefined4 *)(unaff_EBP + -34000);
      }
      if ((-1 < *(int *)(unaff_EBP + -0x84d4)) && (*(int *)(unaff_EBP + -0x84d4) < 2)) {
        DAT_00a0bc88 = *(undefined4 *)(unaff_EBP + -0x84d4);
      }
    }
    if ((7 < *(int *)(unaff_EBP + -0x1e00)) && (*(int *)(unaff_EBP + -0x1e00) < 0x21)) {
      DAT_00a0c1a4 = *(undefined4 *)(unaff_EBP + -0x1e00);
    }
    if ((0x76b < *(int *)(unaff_EBP + -0x1dfc)) && (*(int *)(unaff_EBP + -0x1dfc) < 0x899)) {
      DAT_00a0bc44 = *(undefined4 *)(unaff_EBP + -0x1dfc);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1df8)) && (*(int *)(unaff_EBP + -0x1df8) < 2)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x3034) =
           *(undefined4 *)(unaff_EBP + -0x1df8);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_1");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xfffffff6;
    uVar2 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                         unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,
                         unaff_EBP + -0x1e18,unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,
                         unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,unaff_EBP + -0x1e04);
    *(undefined4 *)(unaff_EBP + -0x87e0) = uVar2;
    DAT_00a0cb04 = *(undefined4 *)(unaff_EBP + -0x1e24);
    DAT_00a0cbd0 = *(undefined4 *)(unaff_EBP + -0x1e20);
    *(undefined4 *)(unaff_EBP + -0x8490) = 1;
    if (*(int *)(unaff_EBP + -0x1e1c) != 0) {
      *(undefined4 *)(unaff_EBP + -0x8490) = 0;
    }
    DAT_00a0caec = *(undefined4 *)(unaff_EBP + -0x8490);
    *(undefined4 *)(unaff_EBP + -0x8490) = 1;
    if (*(int *)(unaff_EBP + -0x1e18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x8490) = 0;
    }
    DAT_00a0caf0 = *(undefined4 *)(unaff_EBP + -0x8490);
    bVar5 = *(int *)(unaff_EBP + -0x1e14) != 0;
    if (bVar5) {
      DAT_00a0d864 = 0;
    }
    DAT_00a0cb1c = (uint)bVar5;
    DAT_00a0cb24 = 0;
    if (9 < *(int *)(unaff_EBP + -0x1e10)) {
      DAT_00a0cb24 = *(int *)(unaff_EBP + -0x1e10) / 10;
    }
    *(int *)(unaff_EBP + -0x1e10) = *(int *)(unaff_EBP + -0x1e10) % 10;
    DAT_00a0cb20 = (uint)(*(int *)(unaff_EBP + -0x1e10) != 0);
    if (6 < *(int *)(unaff_EBP + -0x87e0)) {
      *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x1e0c) % 10;
      if ((*(int *)(unaff_EBP + -0x8490) == 0) || (*(int *)(unaff_EBP + -0x8490) == 1)) {
        DAT_00a0cae8 = *(undefined4 *)(unaff_EBP + -0x8490);
      }
      *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x1e0c) / 10;
      *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) % 10;
      if ((*(int *)(unaff_EBP + -0x8490) == 0) || (*(int *)(unaff_EBP + -0x8490) == 1)) {
        DAT_00a0cc3c = *(undefined4 *)(unaff_EBP + -0x8490);
      }
      *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x1e0c) / 100;
      if ((*(int *)(unaff_EBP + -0x8490) == 0) || (*(int *)(unaff_EBP + -0x8490) == 1)) {
        DAT_00a0cc40 = *(undefined4 *)(unaff_EBP + -0x8490);
      }
    }
    *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x1e08) % 10;
    if ((-1 < *(int *)(unaff_EBP + -0x8490)) && (*(int *)(unaff_EBP + -0x8490) < 2)) {
      DAT_00a0cab0 = *(undefined4 *)(unaff_EBP + -0x8490);
    }
    *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x1e08) % 100;
    *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) / 10;
    if ((-1 < *(int *)(unaff_EBP + -0x8490)) && (*(int *)(unaff_EBP + -0x8490) < 2)) {
      DAT_00a0cab4 = *(undefined4 *)(unaff_EBP + -0x8490);
    }
    *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x1e08) / 100;
    if ((-1 < *(int *)(unaff_EBP + -0x8490)) && (*(int *)(unaff_EBP + -0x8490) < 2)) {
      DAT_00a0cab8 = *(undefined4 *)(unaff_EBP + -0x8490);
    }
    if ((-10 < *(int *)(unaff_EBP + -0x1e04)) && (*(int *)(unaff_EBP + -0x1e04) < 10)) {
      DAT_00a0cb18 = *(undefined4 *)(unaff_EBP + -0x1e04);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_2");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    DAT_00a0ca6c = *(undefined4 *)(unaff_EBP + -0x1e24);
    if (*(int *)(unaff_EBP + -0x1e20) < 1) {
      *(int *)(unaff_EBP + -0x8718) = -*(int *)(unaff_EBP + -0x1e20);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x8718) = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if ((*(int *)(unaff_EBP + -0x8718) < 0x65) && (*(int *)(unaff_EBP + -0x1e20) != 0)) {
      DAT_00a0ca78 = *(undefined4 *)(unaff_EBP + -0x1e20);
      if (*(int *)(unaff_EBP + -0x1e20) == -100) {
        *(undefined4 *)(unaff_EBP + -0x871c) = 1;
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x871c) = 0;
      }
      DAT_00a0ca90 = *(int *)(unaff_EBP + -0x871c);
    }
    DAT_00a0ca68 = *(int *)(unaff_EBP + -0x1e1c) % 10;
    *(int *)(unaff_EBP + -0x1e1c) = *(int *)(unaff_EBP + -0x1e1c) / 10;
    if (0 < *(int *)(unaff_EBP + -0x1e1c) % 10) {
      *(int *)(**(int **)(unaff_EBP + -0x848c) + 0x3048) = *(int *)(unaff_EBP + -0x1e1c) % 10 + -1;
    }
    DAT_00a0cadc = *(undefined4 *)(unaff_EBP + -0x1e18);
    DAT_00a0cbd4 = *(undefined4 *)(unaff_EBP + -0x1e14);
    DAT_00a0cb64 = *(undefined4 *)(unaff_EBP + -0x1e10);
    DAT_00a0c78c = *(undefined4 *)(unaff_EBP + -0x1e0c);
    DAT_00a0c7d8 = *(undefined4 *)(unaff_EBP + -0x1e08);
    if ((-1 < *(int *)(unaff_EBP + -0x1e04)) && (*(int *)(unaff_EBP + -0x1e04) < 2)) {
      DAT_00a0b3ec = *(undefined4 *)(unaff_EBP + -0x1e04);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_3");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined8 *)(unaff_EBP + -0x875c) = 0x3ff0000000000000;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %lg %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x875c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    if ((-1 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 6)) {
      DAT_00a0cb68 = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 6)) {
      DAT_00a0cb6c = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    FUN_004f0700();
    DAT_00a0c798 = *(undefined4 *)(unaff_EBP + -0x1e1c);
    if ((1 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 0x3e9)) {
      DAT_00a0b454 = *(undefined4 *)(unaff_EBP + -0x1e18);
    }
    DAT_00a0c7a0 = *(undefined4 *)(unaff_EBP + -0x1e14);
    DAT_00a0c79c = *(undefined4 *)(unaff_EBP + -0x1e10);
    if ((0.5 <= *(double *)(unaff_EBP + -0x875c)) && (*(double *)(unaff_EBP + -0x875c) <= 2.0)) {
      DAT_00a0c7a8 = *(undefined8 *)(unaff_EBP + -0x875c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e08)) && (*(int *)(unaff_EBP + -0x1e08) < 2)) {
      DAT_00a0b3f8 = *(undefined4 *)(unaff_EBP + -0x1e08);
    }
    *(int *)(unaff_EBP + -0x849c) = *(int *)(unaff_EBP + -0x1e04) % 10;
    if ((-1 < *(int *)(unaff_EBP + -0x849c)) && (*(int *)(unaff_EBP + -0x849c) < 3)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x82a8) =
           *(undefined4 *)(unaff_EBP + -0x849c);
    }
    *(int *)(unaff_EBP + -0x849c) = *(int *)(unaff_EBP + -0x1e04) / 10;
    *(int *)(unaff_EBP + -0x849c) = *(int *)(unaff_EBP + -0x849c) % 10;
    if ((-1 < *(int *)(unaff_EBP + -0x849c)) && (*(int *)(unaff_EBP + -0x849c) < 7)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x82ac) =
           *(undefined4 *)(unaff_EBP + -0x849c);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_4");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 6000) = *(undefined4 *)(unaff_EBP + -0x1e24);
    DAT_00a0c7b0 = *(undefined4 *)(unaff_EBP + -0x1e20);
    *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x82b8) = *(undefined4 *)(unaff_EBP + -0x1e1c)
    ;
    *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x82bc) = *(undefined4 *)(unaff_EBP + -0x1e18)
    ;
    if ((-1 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 4)) {
      DAT_00a0c7bc = *(undefined4 *)(unaff_EBP + -0x1e14);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e10)) && (*(int *)(unaff_EBP + -0x1e10) < 2)) {
      DAT_00a0c7c0 = *(undefined4 *)(unaff_EBP + -0x1e10);
    }
    DAT_00a0c7d4 = 0;
    if (9 < *(int *)(unaff_EBP + -0x1e0c)) {
      DAT_00a0c7d4 = 1;
      *(int *)(unaff_EBP + -0x1e0c) = *(int *)(unaff_EBP + -0x1e0c) % 10;
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e0c)) && (*(int *)(unaff_EBP + -0x1e0c) < 4)) {
      DAT_00a0c7d0 = *(uint *)(unaff_EBP + -0x1e0c) & 1;
      DAT_00a0c7dc = *(uint *)(unaff_EBP + -0x1e0c) & 2;
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e08)) && (*(int *)(unaff_EBP + -0x1e08) < 2)) {
      DAT_00a0cc38 = *(undefined4 *)(unaff_EBP + -0x1e08);
    }
    if ((4 < *(int *)(unaff_EBP + -0x1e04)) && (*(int *)(unaff_EBP + -0x1e04) < 0x1f)) {
      *(double *)(**(int **)(unaff_EBP + -0x848c) + 0x8ed8) = (double)*(int *)(unaff_EBP + -0x1e04);
      iVar3 = FUN_004f72f0((int)(*(double *)(**(int **)(unaff_EBP + -0x848c) + 0x8ed8) * 10.0));
      *(double *)(**(int **)(unaff_EBP + -0x848c) + 0x8ed0) =
           (((double)iVar3 / 10.0) * *(double *)(**(int **)(unaff_EBP + -0x848c) + 0x17f8)) /
           *(double *)(**(int **)(unaff_EBP + -0x848c) + 0x17b0);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_5");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    if ((-1 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 2)) {
      DAT_00a0cc64 = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 3)) {
      DAT_00a0c0bc = (uint)(*(int *)(unaff_EBP + -0x1e20) != 1);
      DAT_00a0c0a4 = (uint)(*(int *)(unaff_EBP + -0x1e20) != 2);
      if (DAT_00a0c0bc == 0) {
        DAT_00a0c0a4 = 0;
      }
    }
    if (((-1 < *(int *)(unaff_EBP + -0x1e1c)) && (*(int *)(unaff_EBP + -0x1e1c) < 2)) &&
       (DAT_00a0c08c = 0, 0 < *(int *)(unaff_EBP + -0x1e1c))) {
      DAT_00a0c08c = 1;
    }
    if (((-1 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 2)) &&
       (DAT_00a0c074 = 0, 0 < *(int *)(unaff_EBP + -0x1e18))) {
      DAT_00a0c074 = 1;
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 2)) {
      DAT_00a0d860 = *(undefined4 *)(unaff_EBP + -0x1e14);
    }
    if (((-1 < *(int *)(unaff_EBP + -0x1e10)) && (*(int *)(unaff_EBP + -0x1e10) < 3)) &&
       (DAT_00a0d864 = *(int *)(unaff_EBP + -0x1e10), DAT_00a0d864 != 0)) {
      DAT_00a0cb1c = 0;
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e0c)) && (*(int *)(unaff_EBP + -0x1e0c) < 2)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x7a04) =
           *(undefined4 *)(unaff_EBP + -0x1e0c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e08)) && (*(int *)(unaff_EBP + -0x1e08) < 2)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x7a08) =
           *(undefined4 *)(unaff_EBP + -0x1e08);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e04)) && (*(int *)(unaff_EBP + -0x1e04) < 2)) {
      DAT_00a0c788 = *(undefined4 *)(unaff_EBP + -0x1e04);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_6");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    if ((0 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 0x65)) {
      DAT_00a0ef60 = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 3)) {
      DAT_00a0c0c4 = (uint)(*(int *)(unaff_EBP + -0x1e20) != 1);
      DAT_00a0c0ac = (uint)(*(int *)(unaff_EBP + -0x1e20) != 2);
      if (DAT_00a0c0c4 == 0) {
        DAT_00a0c0ac = 0;
      }
    }
    if (((-1 < *(int *)(unaff_EBP + -0x1e1c)) && (*(int *)(unaff_EBP + -0x1e1c) < 2)) &&
       (DAT_00a0c094 = 0, 0 < *(int *)(unaff_EBP + -0x1e1c))) {
      DAT_00a0c094 = 1;
    }
    if (((-1 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 2)) &&
       (DAT_00a0c07c = 0, 0 < *(int *)(unaff_EBP + -0x1e18))) {
      DAT_00a0c07c = 1;
    }
    if ((9 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 0xe11)) {
      DAT_00a0caf4 = *(undefined4 *)(unaff_EBP + -0x1e14);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e10)) && (*(int *)(unaff_EBP + -0x1e10) < 2)) {
      DAT_00a0cb00 = *(undefined4 *)(unaff_EBP + -0x1e10);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e0c)) && (*(int *)(unaff_EBP + -0x1e0c) < 2)) {
      DAT_00a0caf8 = *(undefined4 *)(unaff_EBP + -0x1e0c);
    }
    *(int *)(unaff_EBP + -0x85fc) = *(int *)(unaff_EBP + -0x1e08) / 10;
    *(int *)(unaff_EBP + -0x8600) = *(int *)(unaff_EBP + -0x1e08) % 10;
    if ((-1 < *(int *)(unaff_EBP + -0x85fc)) && (*(int *)(unaff_EBP + -0x85fc) < 5)) {
      DAT_00a0ef74 = *(undefined4 *)(unaff_EBP + -0x85fc);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x8600)) && (*(int *)(unaff_EBP + -0x8600) < 6)) {
      DAT_00a0ef78 = *(undefined4 *)(unaff_EBP + -0x8600);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e04)) && (*(int *)(unaff_EBP + -0x1e04) < 2)) {
      DAT_00a0c7c8 = *(undefined4 *)(unaff_EBP + -0x1e04);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_7");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    if ((-1 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 2)) {
      DAT_00a0ef58 = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 0xc)) {
      DAT_00a0b384 = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e1c)) && (*(int *)(unaff_EBP + -0x1e1c) < 2)) {
      DAT_00a088c8 = *(undefined4 *)(unaff_EBP + -0x1e1c);
    }
    if ((9 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 0x3e9)) {
      DAT_00a0b3a0 = *(undefined4 *)(unaff_EBP + -0x1e18);
    }
    if ((9 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 0x3e9)) {
      DAT_00a0b3a4 = *(undefined4 *)(unaff_EBP + -0x1e14);
    }
    if ((4 < *(int *)(unaff_EBP + -0x1e10)) && (*(int *)(unaff_EBP + -0x1e10) < 0x3e9)) {
      DAT_00a0b3a8 = *(undefined4 *)(unaff_EBP + -0x1e10);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e0c)) && (*(int *)(unaff_EBP + -0x1e0c) < 0xb)) {
      DAT_00a0b3ac = *(undefined4 *)(unaff_EBP + -0x1e0c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e08)) && (*(int *)(unaff_EBP + -0x1e08) < 2)) {
      DAT_00a0bfa8 = *(undefined4 *)(unaff_EBP + -0x1e08);
    }
    if (-1 < *(int *)(unaff_EBP + -0x1e04)) {
      DAT_00a0b38c = 0;
      DAT_00a0b388 = (uint)(*(int *)(unaff_EBP + -0x1e04) % 10 == 1);
      if (9 < *(int *)(unaff_EBP + -0x1e04)) {
        DAT_00a0b38c = 1;
      }
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_8");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    if (-1 < *(int *)(unaff_EBP + -0x1e24)) {
      DAT_00a0cb70 = (uint)(0 < *(int *)(unaff_EBP + -0x1e24) % 10);
      if (9 < *(int *)(unaff_EBP + -0x1e24) % 100) {
        DAT_00a0cb70 = DAT_00a0cb70 | 2;
      }
      if (99 < *(int *)(unaff_EBP + -0x1e24)) {
        DAT_00a0cb70 = DAT_00a0cb70 | 8;
      }
    }
    if ((((*(int *)(unaff_EBP + -0x1e1c) == 0) || (*(int *)(unaff_EBP + -0x1e1c) == 1)) ||
        (*(int *)(unaff_EBP + -0x1e1c) == 10)) || (*(int *)(unaff_EBP + -0x1e1c) == 0xb)) {
      DAT_00a0cc20 = *(undefined4 *)(unaff_EBP + -0x1e1c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 10)) {
      DAT_00a0be40 = *(undefined4 *)(unaff_EBP + -0x1e18);
    }
    if (-1 < *(int *)(unaff_EBP + -0x1e14)) {
      DAT_00a0d61c = (uint)(*(int *)(unaff_EBP + -0x1e14) % 10 == 1);
      *(int *)(unaff_EBP + -0x1e14) = *(int *)(unaff_EBP + -0x1e14) / 10;
      if (*(int *)(unaff_EBP + -0x1e14) % 10 == 1) {
        DAT_00a0d61c = DAT_00a0d61c + 2;
      }
      *(int *)(unaff_EBP + -0x1e14) = *(int *)(unaff_EBP + -0x1e14) / 10;
      if (*(int *)(unaff_EBP + -0x1e14) % 10 == 1) {
        DAT_00a0d61c = DAT_00a0d61c + 4;
      }
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e10)) && (*(int *)(unaff_EBP + -0x1e10) < 2)) {
      DAT_00a0d628 = *(undefined4 *)(unaff_EBP + -0x1e10);
    }
    if ((*(int *)(unaff_EBP + -0x1e0c) == 0) || (*(int *)(unaff_EBP + -0x1e0c) == 1)) {
      if (*(int *)(unaff_EBP + -0x1e0c) == 0) {
        DAT_00a0ca9c = 0;
      }
      if (*(int *)(unaff_EBP + -0x1e0c) == 1) {
        DAT_00a0ca9c = 1;
      }
    }
    if (*(int *)(unaff_EBP + -0x1e08) == 1) {
      DAT_00a0caa4 = 1;
    }
    if ((*(int *)(unaff_EBP + -0x1e04) == 0) || (*(int *)(unaff_EBP + -0x1e04) == 1)) {
      if (*(int *)(unaff_EBP + -0x1e04) == 0) {
        DAT_00a0caac = 0;
      }
      if (*(int *)(unaff_EBP + -0x1e04) == 1) {
        DAT_00a0caac = 1;
      }
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_9");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    if (-1 < *(int *)(unaff_EBP + -0x1e24)) {
      *(double *)(**(int **)(unaff_EBP + -0x848c) + 0x6990) =
           (double)*(int *)(unaff_EBP + -0x1e24) / 10.0;
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 10)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x82c4) =
           *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if (-1 < *(int *)(unaff_EBP + -0x1e1c)) {
      if (*(int *)(unaff_EBP + -0x1e1c) < 1000) {
        *(undefined4 *)(unaff_EBP + -0x8720) = 0;
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x8720) = 1;
      }
      DAT_00a0f438 = *(undefined4 *)(unaff_EBP + -0x8720);
      DAT_00a0f43c = *(int *)(unaff_EBP + -0x1e1c) % 1000;
      if (0xff < DAT_00a0f43c) {
        DAT_00a0f43c = 0xff;
      }
    }
    if (0 < *(int *)(unaff_EBP + -0x1e18)) {
      DAT_00a08adc = DAT_00a08adc | 2;
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_A");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    *(undefined4 *)(unaff_EBP + -0x849c) = *(undefined4 *)(unaff_EBP + -0x1e24);
    if ((-1 < *(int *)(unaff_EBP + -0x849c)) && (*(int *)(unaff_EBP + -0x849c) < 0x65)) {
      DAT_00a0caa0 = 100 - *(int *)(unaff_EBP + -0x849c);
    }
    *(undefined4 *)(unaff_EBP + -0x857c) = *(undefined4 *)(unaff_EBP + -0x1e20);
    if ((-1 < *(int *)(unaff_EBP + -0x857c)) && (*(int *)(unaff_EBP + -0x857c) < 0x2711)) {
      *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x857c) / 1000;
      if ((-1 < *(int *)(unaff_EBP + -0x8490)) && (*(int *)(unaff_EBP + -0x8490) < 0xb)) {
        DAT_00a0d620 = *(undefined4 *)(unaff_EBP + -0x8490);
      }
      *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x857c) % 1000;
      if ((0 < *(int *)(unaff_EBP + -0x8490)) && (*(int *)(unaff_EBP + -0x8490) < 0x65)) {
        _DAT_00a0d624 = *(undefined4 *)(unaff_EBP + -0x8490);
      }
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_COMM_G");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e08) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x1e10,unaff_EBP + -0x1e0c,unaff_EBP + -0x1e08,
                 unaff_EBP + -0x1e04);
    if ((-0x32 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 500)) {
      _DAT_00a0c0e4 = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-0x32 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 500)) {
      _DAT_00a0c0e8 = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_MESH_0");
  if (iVar3 != 0) {
    if (*(int *)(*(int *)(unaff_EBP + -0x848c) + 0x324) != 0) goto LAB_005293fd;
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    *(undefined8 *)(unaff_EBP + -0x86ec) = 0xbff0000000000000;
    *(undefined8 *)(unaff_EBP + -0x8734) = *(undefined8 *)(unaff_EBP + -0x86ec);
    *(undefined8 *)(unaff_EBP + -0x876c) = *(undefined8 *)(unaff_EBP + -0x8734);
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %lg %lg %lg %d",unaff_EBP + -0x1e24,
                 unaff_EBP + -0x1e20,unaff_EBP + -0x876c,unaff_EBP + -0x8734,unaff_EBP + -0x86ec,
                 unaff_EBP + -0x1e1c);
    if ((-1 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 6)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x7a0c) =
           *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 2)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x7a10) =
           *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if (0.001 <= *(double *)(unaff_EBP + -0x876c)) {
      *(undefined8 *)(**(int **)(unaff_EBP + -0x848c) + 0x7a28) =
           *(undefined8 *)(unaff_EBP + -0x876c);
    }
    if (0.001 <= *(double *)(unaff_EBP + -0x8734)) {
      *(undefined8 *)(**(int **)(unaff_EBP + -0x848c) + 0x7a30) =
           *(undefined8 *)(unaff_EBP + -0x8734);
    }
    if ((5.0 <= *(double *)(unaff_EBP + -0x86ec)) && (*(double *)(unaff_EBP + -0x86ec) <= 100.0)) {
      *(undefined8 *)(**(int **)(unaff_EBP + -0x848c) + 0x7a18) =
           *(undefined8 *)(unaff_EBP + -0x86ec);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e1c)) && (*(int *)(unaff_EBP + -0x1e1c) < 2)) {
      *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x7a14) =
           *(undefined4 *)(unaff_EBP + -0x1e1c);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"ZOOM");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e10) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xfffffffb;
    *(undefined8 *)(unaff_EBP + -0x873c) = 0;
    *(undefined8 *)(unaff_EBP + -0x8744) = 0;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %lg %lg %d %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x873c,unaff_EBP + -0x8744,unaff_EBP + -0x1e10,
                 unaff_EBP + -0x1e0c);
    if ((-1 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 10)) {
      DAT_00a0d87c = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 10)) {
      DAT_00a0d880 = *(undefined4 *)(unaff_EBP + -0x1e20);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e1c)) && (*(int *)(unaff_EBP + -0x1e1c) < 10)) {
      DAT_00a0d884 = *(undefined4 *)(unaff_EBP + -0x1e1c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 10)) {
      DAT_00a0d888 = *(undefined4 *)(unaff_EBP + -0x1e18);
    }
    if ((1 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 0x33)) {
      DAT_00a0d8c8 = *(int *)(unaff_EBP + -0x1e14);
    }
    if ((0.01 <= *(double *)(unaff_EBP + -0x873c)) && (*(double *)(unaff_EBP + -0x873c) <= 1.0)) {
      DAT_00a0d868 = *(undefined8 *)(unaff_EBP + -0x873c);
    }
    if ((1.1 <= *(double *)(unaff_EBP + -0x8744)) && (*(double *)(unaff_EBP + -0x8744) <= 5.0)) {
      DAT_00a0d870 = *(undefined8 *)(unaff_EBP + -0x8744);
    }
    if ((0x31 < *(int *)(unaff_EBP + -0x1e10)) && (*(int *)(unaff_EBP + -0x1e10) < 0x3e9)) {
      DAT_00a0d8cc = *(int *)(unaff_EBP + -0x1e10);
    }
    if (DAT_00a0d8cc < DAT_00a0d8c8 * 2) {
      DAT_00a0d8cc = DAT_00a0d8c8 << 1;
    }
    if (*(int *)(unaff_EBP + -0x1e0c) < 1) {
      *(int *)(unaff_EBP + -0x8724) = -*(int *)(unaff_EBP + -0x1e0c);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x8724) = *(undefined4 *)(unaff_EBP + -0x1e0c);
    }
    bVar5 = 9 < *(int *)(unaff_EBP + -0x8724);
    if (bVar5) {
      *(int *)(unaff_EBP + -0x1e0c) = *(int *)(unaff_EBP + -0x1e0c) % 10;
    }
    DAT_00a0d8a4 = (uint)bVar5;
    if ((-5 < *(int *)(unaff_EBP + -0x1e0c)) && (*(int *)(unaff_EBP + -0x1e0c) < 5)) {
      DAT_00a0d8a0 = *(undefined4 *)(unaff_EBP + -0x1e0c);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LAYSCALE");
  if (iVar3 != 0) {
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                 L"%lg %lg %lg %lg %lg %lg %lg %lg %lg %lg %lg %lg %lg %lg %lg %lg",
                 *(int *)(unaff_EBP + -0x848c) + 8,*(int *)(unaff_EBP + -0x848c) + 0x10,
                 *(int *)(unaff_EBP + -0x848c) + 0x18,*(int *)(unaff_EBP + -0x848c) + 0x20,
                 *(int *)(unaff_EBP + -0x848c) + 0x28,*(int *)(unaff_EBP + -0x848c) + 0x30,
                 *(int *)(unaff_EBP + -0x848c) + 0x38,*(int *)(unaff_EBP + -0x848c) + 0x40,
                 *(int *)(unaff_EBP + -0x848c) + 0x48,*(int *)(unaff_EBP + -0x848c) + 0x50,
                 *(int *)(unaff_EBP + -0x848c) + 0x58,*(int *)(unaff_EBP + -0x848c) + 0x60,
                 *(int *)(unaff_EBP + -0x848c) + 0x68,*(int *)(unaff_EBP + -0x848c) + 0x70,
                 *(int *)(unaff_EBP + -0x848c) + 0x78,*(int *)(unaff_EBP + -0x848c) + 0x80);
    *(undefined4 *)(unaff_EBP + -0x86d4) = 1;
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LTYPE_0");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8494) = 0;
    iVar3 = FUN_00417110(unaff_EBP + -0x42a,&DAT_0095bce4,unaff_EBP + -0x8494);
    if (((iVar3 != 0) && (1 < *(int *)(unaff_EBP + -0x8494))) &&
       (*(int *)(unaff_EBP + -0x8494) < 10)) {
      *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
      *(undefined4 *)(unaff_EBP + -0x84ac) = 0;
      FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lx %d %d %d",unaff_EBP + -0x84ac,
                   unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c);
      if (*(int *)(unaff_EBP + -0x84ac) != 0) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x304c + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x84ac);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e24)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x4dc8 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e24);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e20)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x50e0 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e20);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e1c)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x51e8 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e1c);
      }
    }
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LTYPE_R");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8494) = 0;
    iVar3 = FUN_00417110(unaff_EBP + -0x42a,&DAT_0095bce4,unaff_EBP + -0x8494);
    if (((iVar3 != 0) && (0 < *(int *)(unaff_EBP + -0x8494))) && (*(int *)(unaff_EBP + -0x8494) < 6)
       ) {
      *(int *)(unaff_EBP + -0x8494) = *(int *)(unaff_EBP + -0x8494) + 10;
      *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
      *(undefined4 *)(unaff_EBP + -0x84ac) = 0;
      FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lx %d %d %d %d",unaff_EBP + -0x84ac,
                   unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18);
      if (*(int *)(unaff_EBP + -0x84ac) != 0) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x304c + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x84ac);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e24)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x4ed0 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e24);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e20)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x50e0 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e20);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e1c)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x4fd8 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e1c);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e18)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x51e8 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e18);
      }
    }
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LTYPE_L");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8494) = 0;
    iVar3 = FUN_00417110(unaff_EBP + -0x42a,&DAT_0095bce4,unaff_EBP + -0x8494);
    if (((iVar3 != 0) && (0 < *(int *)(unaff_EBP + -0x8494))) && (*(int *)(unaff_EBP + -0x8494) < 5)
       ) {
      *(int *)(unaff_EBP + -0x8494) = *(int *)(unaff_EBP + -0x8494) + 0xf;
      *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
      *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
      *(undefined4 *)(unaff_EBP + -0x84ac) = 0;
      FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lx %d %d %d",unaff_EBP + -0x84ac,
                   unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c);
      if (*(int *)(unaff_EBP + -0x84ac) != 0) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x304c + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x84ac);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e24)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x4dc8 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e24);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e20)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x50e0 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e20);
      }
      if (0 < *(int *)(unaff_EBP + -0x1e1c)) {
        *(undefined4 *)
         (**(int **)(unaff_EBP + -0x848c) + 0x51e8 + *(int *)(unaff_EBP + -0x8494) * 4) =
             *(undefined4 *)(unaff_EBP + -0x1e1c);
      }
    }
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"LCOLLOR_");
  if (iVar3 != 0) {
    if (*(short *)(unaff_EBP + -0x428) == 0x47) {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0xd;
    }
    else if (*(short *)(unaff_EBP + -0x428) == 0x48) {
      *(undefined4 *)(unaff_EBP + -0x8494) = 9;
    }
    else if (*(short *)(unaff_EBP + -0x428) == 0x53) {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0xf;
    }
    else if (*(short *)(unaff_EBP + -0x428) == 0x4b) {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0x10;
    }
    else if (*(short *)(unaff_EBP + -0x428) == 0x42) {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0;
    }
    else if (*(short *)(unaff_EBP + -0x428) == 0x5a) {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0x13;
    }
    else if (*(short *)(unaff_EBP + -0x428) == 0x4d) {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0x12;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0;
      iVar3 = FUN_00417110(unaff_EBP + -0x428,&DAT_0095bce4,unaff_EBP + -0x8494);
      if (((iVar3 == 0) || (*(int *)(unaff_EBP + -0x8494) < 1)) ||
         (8 < *(int *)(unaff_EBP + -0x8494))) goto LAB_005293fd;
    }
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d",unaff_EBP + -0x1e24,
                 unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18);
    if (*(int *)(unaff_EBP + -0x1e24) < 0) {
      *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    }
    if (0xff < *(int *)(unaff_EBP + -0x1e24)) {
      *(undefined4 *)(unaff_EBP + -0x1e24) = 0xff;
    }
    if (*(int *)(unaff_EBP + -0x1e20) < 0) {
      *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    }
    if (0xff < *(int *)(unaff_EBP + -0x1e20)) {
      *(undefined4 *)(unaff_EBP + -0x1e20) = 0xff;
    }
    if (*(int *)(unaff_EBP + -0x1e1c) < 0) {
      *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    }
    if (0xff < *(int *)(unaff_EBP + -0x1e1c)) {
      *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xff;
    }
    *(uint *)(**(int **)(unaff_EBP + -0x848c) + 0x52f0 + *(int *)(unaff_EBP + -0x8494) * 4) =
         (uint)CONCAT12(*(undefined1 *)(unaff_EBP + -0x1e1c),
                        CONCAT11(*(undefined1 *)(unaff_EBP + -0x1e20),
                                 *(undefined1 *)(unaff_EBP + -0x1e24)));
    if (*(short *)(unaff_EBP + -0x428) == 0x47) {
      *(undefined4 *)(unaff_EBP + -0x8580) = *(undefined4 *)(unaff_EBP + -0x1e18);
      if ((*(int *)(unaff_EBP + -0x8580) < 0) || (0x10 < *(int *)(unaff_EBP + -0x8580))) {
        *(undefined4 *)(unaff_EBP + -0x8580) = 0;
      }
      DAT_00a0b444 = *(undefined4 *)(unaff_EBP + -0x8580);
    }
    if (*(int *)(unaff_EBP + -0x1e18) < 1) {
      *(undefined4 *)(unaff_EBP + -0x1e18) = 1;
    }
    if (0x10 < *(int *)(unaff_EBP + -0x1e18)) {
      *(undefined4 *)(unaff_EBP + -0x1e18) = 0x10;
    }
    *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x5e20 + *(int *)(unaff_EBP + -0x8494) * 4) =
         *(undefined4 *)(unaff_EBP + -0x1e18);
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"P_dpi");
  if (iVar3 != 0) {
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),&DAT_0095b714,unaff_EBP + -0x1e24);
    if (*(int *)(unaff_EBP + -0x1e24) == 300) {
      DAT_00a0ca88 = 300;
    }
    if (*(int *)(unaff_EBP + -0x1e24) == 600) {
      DAT_00a0ca88 = 600;
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"PCOLLOR_");
  if (iVar3 != 0) {
    if (*(short *)(unaff_EBP + -0x428) == 0x47) {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0xd;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x8494) = 0;
      iVar3 = FUN_00417110(unaff_EBP + -0x428,&DAT_0095bce4,unaff_EBP + -0x8494);
      if (((iVar3 == 0) || (*(int *)(unaff_EBP + -0x8494) < 1)) ||
         (8 < *(int *)(unaff_EBP + -0x8494))) goto LAB_005293fd;
    }
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    *(undefined8 *)(unaff_EBP + -0x874c) = 0;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %lg",unaff_EBP + -0x1e24,
                 unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,unaff_EBP + -0x874c);
    if (*(int *)(unaff_EBP + -0x1e24) < 0) {
      *(undefined4 *)(unaff_EBP + -0x1e24) = 0;
    }
    if (0xff < *(int *)(unaff_EBP + -0x1e24)) {
      *(undefined4 *)(unaff_EBP + -0x1e24) = 0xff;
    }
    if (*(int *)(unaff_EBP + -0x1e20) < 0) {
      *(undefined4 *)(unaff_EBP + -0x1e20) = 0;
    }
    if (0xff < *(int *)(unaff_EBP + -0x1e20)) {
      *(undefined4 *)(unaff_EBP + -0x1e20) = 0xff;
    }
    if (*(int *)(unaff_EBP + -0x1e1c) < 0) {
      *(undefined4 *)(unaff_EBP + -0x1e1c) = 0;
    }
    if (0xff < *(int *)(unaff_EBP + -0x1e1c)) {
      *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xff;
    }
    *(uint *)(**(int **)(unaff_EBP + -0x848c) + 0x5884 + *(int *)(unaff_EBP + -0x8494) * 4) =
         (uint)CONCAT12(*(undefined1 *)(unaff_EBP + -0x1e1c),
                        CONCAT11(*(undefined1 *)(unaff_EBP + -0x1e20),
                                 *(undefined1 *)(unaff_EBP + -0x1e24)));
    if (*(short *)(unaff_EBP + -0x428) == 0x47) {
      *(undefined4 *)(unaff_EBP + -0x8584) = *(undefined4 *)(unaff_EBP + -0x1e18);
      if ((*(int *)(unaff_EBP + -0x8584) < 0) || (500 < *(int *)(unaff_EBP + -0x8584))) {
        *(undefined4 *)(unaff_EBP + -0x8584) = 0;
      }
      DAT_00a0b448 = *(undefined4 *)(unaff_EBP + -0x8584);
    }
    if (*(int *)(unaff_EBP + -0x1e18) < 1) {
      *(undefined4 *)(unaff_EBP + -0x1e18) = 1;
    }
    if (500 < *(int *)(unaff_EBP + -0x1e18)) {
      *(undefined4 *)(unaff_EBP + -0x1e18) = 500;
    }
    *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x63b4 + *(int *)(unaff_EBP + -0x8494) * 4) =
         *(undefined4 *)(unaff_EBP + -0x1e18);
    if (((0.1 <= *(double *)(unaff_EBP + -0x874c)) && (*(double *)(unaff_EBP + -0x874c) <= 10.0)) &&
       (*(int *)(unaff_EBP + -0x8494) < 9)) {
      *(undefined8 *)(**(int **)(unaff_EBP + -0x848c) + 0x6948 + *(int *)(unaff_EBP + -0x8494) * 8)
           = *(undefined8 *)(unaff_EBP + -0x874c);
    }
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"MSET");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1e04) = 0xfffffff6;
    *(undefined4 *)(unaff_EBP + -0x1e0c) = 0xfffffff6;
    *(undefined4 *)(unaff_EBP + -0x1e14) = 0xfffffff6;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xfffffff6;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xfffffff6;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xfffffff6;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xfffffff6;
    *(undefined8 *)(unaff_EBP + -0x85dc) = 0xbff0000000000000;
    *(undefined8 *)(unaff_EBP + -0x8754) = 0xc08f400000000000;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %lg %d %lg %d",
                 unaff_EBP + -0x1e24,unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18,
                 unaff_EBP + -0x1e14,unaff_EBP + -0x85dc,unaff_EBP + -0x1e0c,unaff_EBP + -0x8754,
                 unaff_EBP + -0x1e04);
    if ((-1 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 0xb)) {
      DAT_00a0b4f0._0_4_ = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    if ((0 < *(int *)(unaff_EBP + -0x1e20)) && (*(int *)(unaff_EBP + -0x1e20) < 10)) {
      DAT_00a0b47c = *(int *)(unaff_EBP + -0x1e20) + -1;
    }
    if ((*(int *)(unaff_EBP + -0x1e1c) < 1) || (4 < *(int *)(unaff_EBP + -0x1e1c))) {
      DAT_00a0b468 = 0;
    }
    else {
      DAT_00a0b468 = *(undefined4 *)(unaff_EBP + -0x1e1c);
    }
    DAT_00a0b46c = 700;
    if ((499 < *(int *)(unaff_EBP + -0x1e18)) && (*(int *)(unaff_EBP + -0x1e18) < 0x1389)) {
      DAT_00a0b46c = *(undefined4 *)(unaff_EBP + -0x1e18);
    }
    DAT_00a0b470 = 0x30;
    if ((0x27 < *(int *)(unaff_EBP + -0x1e14)) && (*(int *)(unaff_EBP + -0x1e14) < 0x191)) {
      DAT_00a0b470 = *(undefined4 *)(unaff_EBP + -0x1e14);
    }
    if (*(double *)(unaff_EBP + -0x85dc) <= 0.0) {
      *(ulonglong *)(unaff_EBP + -0x87ec) = *(ulonglong *)(unaff_EBP + -0x85dc) ^ 0x8000000000000000
      ;
    }
    else {
      *(undefined8 *)(unaff_EBP + -0x87ec) = *(undefined8 *)(unaff_EBP + -0x85dc);
    }
    if (10.0 <= *(double *)(unaff_EBP + -0x87ec)) {
      if (*(double *)(unaff_EBP + -0x85dc) <= 0.0) {
        *(ulonglong *)(unaff_EBP + -0x87f4) =
             *(ulonglong *)(unaff_EBP + -0x85dc) ^ 0x8000000000000000;
      }
      else {
        *(undefined8 *)(unaff_EBP + -0x87f4) = *(undefined8 *)(unaff_EBP + -0x85dc);
      }
      if (*(double *)(unaff_EBP + -0x87f4) <= 1000.0) {
        DAT_00a0ba78 = *(undefined8 *)(unaff_EBP + -0x85dc);
      }
    }
    if (-1 < *(int *)(unaff_EBP + -0x1e0c)) {
      if (*(int *)(unaff_EBP + -0x1e0c) < 10) {
        *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x82e0) = 0;
      }
      else {
        *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x82e0) = 1;
      }
      *(int *)(unaff_EBP + -0x1e0c) = *(int *)(unaff_EBP + -0x1e0c) % 10;
      if ((-1 < *(int *)(unaff_EBP + -0x1e0c)) && (*(int *)(unaff_EBP + -0x1e0c) < 3)) {
        *(undefined4 *)(**(int **)(unaff_EBP + -0x848c) + 0x82c8) =
             *(undefined4 *)(unaff_EBP + -0x1e0c);
      }
    }
    if ((-1.0 <= *(double *)(unaff_EBP + -0x8754)) && (*(double *)(unaff_EBP + -0x8754) <= 10.0)) {
      *(undefined8 *)(**(int **)(unaff_EBP + -0x848c) + 0x82d0) =
           *(undefined8 *)(unaff_EBP + -0x8754);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x1e04)) && (*(int *)(unaff_EBP + -0x1e04) < 2)) {
      DAT_00a0bc30 = *(undefined4 *)(unaff_EBP + -0x1e04);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"MHEN");
  if (iVar3 != 0) {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x848c) + 800) = 0xfffffffe;
    *(undefined4 *)(unaff_EBP + -0x1e18) = 0xfffffffe;
    *(undefined4 *)(unaff_EBP + -0x1e1c) = 0xfffffffe;
    *(undefined4 *)(unaff_EBP + -0x1e20) = 0xfffffffe;
    *(undefined4 *)(unaff_EBP + -0x1e24) = 0xfffffffe;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d",unaff_EBP + -0x1e24,
                 unaff_EBP + -0x1e20,unaff_EBP + -0x1e1c,unaff_EBP + -0x1e18);
    if ((-2 < *(int *)(unaff_EBP + -0x1e24)) && (*(int *)(unaff_EBP + -0x1e24) < 10)) {
      *(undefined4 *)(*(int *)(unaff_EBP + -0x848c) + 800) = *(undefined4 *)(unaff_EBP + -0x1e24);
    }
    FUN_004f1580(*(undefined4 *)(unaff_EBP + -0x8498),&DAT_00a0ba84,&DAT_00a0bc28,&DAT_00a0bc2c);
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"MPEN");
  if (iVar3 != 0) {
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d %d",
                 *(int *)(unaff_EBP + -0x848c) + 0x2cc,*(int *)(unaff_EBP + -0x848c) + 0x2d0,
                 *(int *)(unaff_EBP + -0x848c) + 0x2d4,*(int *)(unaff_EBP + -0x848c) + 0x2d8,
                 *(int *)(unaff_EBP + -0x848c) + 0x2dc,*(int *)(unaff_EBP + -0x848c) + 0x2e0,
                 *(int *)(unaff_EBP + -0x848c) + 0x2e4,*(int *)(unaff_EBP + -0x848c) + 0x2e8,
                 *(int *)(unaff_EBP + -0x848c) + 0x2ec,*(int *)(unaff_EBP + -0x848c) + 0x2f0);
    *(undefined4 *)(unaff_EBP + -0x854c) = 1;
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"MWIDE");
  if (iVar3 != 0) {
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lg %lg %lg %lg %lg %lg %lg %lg %lg %lg",
                 *(int *)(unaff_EBP + -0x848c) + 0xc0,*(int *)(unaff_EBP + -0x848c) + 200,
                 *(int *)(unaff_EBP + -0x848c) + 0xd0,*(int *)(unaff_EBP + -0x848c) + 0xd8,
                 *(int *)(unaff_EBP + -0x848c) + 0xe0,*(int *)(unaff_EBP + -0x848c) + 0xe8,
                 *(int *)(unaff_EBP + -0x848c) + 0xf0,*(int *)(unaff_EBP + -0x848c) + 0xf8,
                 *(int *)(unaff_EBP + -0x848c) + 0x100,*(int *)(unaff_EBP + -0x848c) + 0x108);
    *(undefined4 *)(unaff_EBP + -0x854c) = 1;
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"MHIGH");
  if (iVar3 != 0) {
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lg %lg %lg %lg %lg %lg %lg %lg %lg %lg",
                 *(int *)(unaff_EBP + -0x848c) + 0x170,*(int *)(unaff_EBP + -0x848c) + 0x178,
                 *(int *)(unaff_EBP + -0x848c) + 0x180,*(int *)(unaff_EBP + -0x848c) + 0x188,
                 *(int *)(unaff_EBP + -0x848c) + 400,*(int *)(unaff_EBP + -0x848c) + 0x198,
                 *(int *)(unaff_EBP + -0x848c) + 0x1a0,*(int *)(unaff_EBP + -0x848c) + 0x1a8,
                 *(int *)(unaff_EBP + -0x848c) + 0x1b0,*(int *)(unaff_EBP + -0x848c) + 0x1b8);
    *(undefined4 *)(unaff_EBP + -0x854c) = 1;
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"MDIST");
  if (iVar3 != 0) {
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lg %lg %lg %lg %lg %lg %lg %lg %lg %lg",
                 *(int *)(unaff_EBP + -0x848c) + 0x220,*(int *)(unaff_EBP + -0x848c) + 0x228,
                 *(int *)(unaff_EBP + -0x848c) + 0x230,*(int *)(unaff_EBP + -0x848c) + 0x238,
                 *(int *)(unaff_EBP + -0x848c) + 0x240,*(int *)(unaff_EBP + -0x848c) + 0x248,
                 *(int *)(unaff_EBP + -0x848c) + 0x250,*(int *)(unaff_EBP + -0x848c) + 600,
                 *(int *)(unaff_EBP + -0x848c) + 0x260,*(int *)(unaff_EBP + -0x848c) + 0x268);
    *(undefined4 *)(unaff_EBP + -0x854c) = 1;
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"MOFST");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8588) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x858c) = 0xffffffff;
    *(undefined8 *)(unaff_EBP + -0x8844) = 0;
    *(undefined8 *)(unaff_EBP + -0x8824) = 0;
    *(undefined8 *)(unaff_EBP + -0x87fc) = 0;
    *(undefined8 *)(unaff_EBP + -0x8804) = 0;
    *(undefined8 *)(unaff_EBP + -0x880c) = 0;
    *(undefined8 *)(unaff_EBP + -0x883c) = 0;
    FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %lg %lg %lg %lg %lg %lg %d",
                 unaff_EBP + -0x8588,unaff_EBP + -0x8844,unaff_EBP + -0x8824,unaff_EBP + -0x87fc,
                 unaff_EBP + -0x8804,unaff_EBP + -0x880c,unaff_EBP + -0x883c,unaff_EBP + -0x858c);
    if ((-1 < *(int *)(unaff_EBP + -0x8588)) && (*(int *)(unaff_EBP + -0x8588) < 2)) {
      DAT_00a0b9c8 = *(undefined4 *)(unaff_EBP + -0x8588);
    }
    DAT_00a0b9d0 = *(undefined8 *)(unaff_EBP + -0x8844);
    DAT_00a0b9d8 = *(undefined8 *)(unaff_EBP + -0x8824);
    DAT_00a0b9e0 = *(undefined8 *)(unaff_EBP + -0x87fc);
    DAT_00a0ba20 = *(undefined8 *)(unaff_EBP + -0x8804);
    DAT_00a0ba28 = *(undefined8 *)(unaff_EBP + -0x880c);
    DAT_00a0ba30 = *(undefined8 *)(unaff_EBP + -0x883c);
    if ((-1 < *(int *)(unaff_EBP + -0x858c)) && (*(int *)(unaff_EBP + -0x858c) < 2)) {
      DAT_00a0bbb0 = *(undefined4 *)(unaff_EBP + -0x858c);
    }
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_STR1");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x860c) = 0;
    *(undefined4 *)(unaff_EBP + -0x8608) = *(undefined4 *)(unaff_EBP + -0x860c);
    *(undefined4 *)(unaff_EBP + -0x8604) = *(undefined4 *)(unaff_EBP + -0x8608);
    *(undefined4 *)(unaff_EBP + -0x84d8) = *(undefined4 *)(unaff_EBP + -0x8604);
    *(undefined8 *)(unaff_EBP + -0x8814) = 0;
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %lg %d %d",unaff_EBP + -0x84d8
                         ,unaff_EBP + -0x8604,unaff_EBP + -0x8814,unaff_EBP + -0x8608,
                         unaff_EBP + -0x860c);
    if (iVar3 != 0) {
      if ((-0xb < *(int *)(unaff_EBP + -0x84d8)) && (*(int *)(unaff_EBP + -0x84d8) < 0xb)) {
        if (*(int *)(unaff_EBP + -0x84d8) == 0) {
          *(undefined4 *)(unaff_EBP + -0x84d8) = 1;
        }
        DAT_00a0bcd0 = *(undefined4 *)(unaff_EBP + -0x84d8);
      }
      DAT_00a0bcc4 = *(undefined4 *)(unaff_EBP + -0x8604);
      DAT_00a0bcf0 = *(undefined8 *)(unaff_EBP + -0x8814);
      DAT_00a0bcc8 = *(undefined4 *)(unaff_EBP + -0x8608);
      DAT_00a0bd34 = *(undefined4 *)(unaff_EBP + -0x860c);
      FUN_004f1580(*(undefined4 *)(unaff_EBP + -0x8498),&DAT_00a0ba88,&DAT_00a0bda8,&DAT_00a0bdac);
    }
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_STR2");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x863c) = 0;
    *(undefined4 *)(unaff_EBP + -0x861c) = *(undefined4 *)(unaff_EBP + -0x863c);
    *(undefined4 *)(unaff_EBP + -0x8614) = *(undefined4 *)(unaff_EBP + -0x861c);
    *(undefined4 *)(unaff_EBP + -0x8610) = *(undefined4 *)(unaff_EBP + -0x8614);
    *(undefined4 *)(unaff_EBP + -0x8728) = *(undefined4 *)(unaff_EBP + -0x8610);
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d",unaff_EBP + -0x8728,
                         unaff_EBP + -0x8610,unaff_EBP + -0x8614,unaff_EBP + -0x861c,
                         unaff_EBP + -0x863c);
    if (iVar3 == 0) goto LAB_005293fd;
    DAT_00a0bd3c = *(undefined4 *)(unaff_EBP + -0x8728);
    DAT_00a0bd40 = *(undefined4 *)(unaff_EBP + -0x8610);
    DAT_00a0bd38 = *(undefined4 *)(unaff_EBP + -0x8614);
    DAT_00a0bd5c = *(undefined4 *)(unaff_EBP + -0x861c);
    DAT_00a0bd44 = *(undefined4 *)(unaff_EBP + -0x863c);
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_STR3");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8630) = 0;
    *(undefined4 *)(unaff_EBP + -0x862c) = *(undefined4 *)(unaff_EBP + -0x8630);
    *(undefined4 *)(unaff_EBP + -0x8628) = *(undefined4 *)(unaff_EBP + -0x862c);
    *(undefined4 *)(unaff_EBP + -0x8624) = *(undefined4 *)(unaff_EBP + -0x8628);
    *(undefined4 *)(unaff_EBP + -0x872c) = *(undefined4 *)(unaff_EBP + -0x8624);
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d",unaff_EBP + -0x872c,
                         unaff_EBP + -0x8624,unaff_EBP + -0x8628,unaff_EBP + -0x862c,
                         unaff_EBP + -0x8630);
    if (iVar3 == 0) goto LAB_005293fd;
    DAT_00a0bd24 = *(undefined4 *)(unaff_EBP + -0x872c);
    DAT_00a0bd28 = *(undefined4 *)(unaff_EBP + -0x8624);
    DAT_00a0bd2c = *(undefined4 *)(unaff_EBP + -0x8628);
    DAT_00a0bd30 = *(undefined4 *)(unaff_EBP + -0x862c);
    DAT_00a0bd20 = *(undefined4 *)(unaff_EBP + -0x8630);
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_SET1");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8634) = 0;
    *(undefined4 *)(unaff_EBP + -0x84e0) = *(undefined4 *)(unaff_EBP + -0x8634);
    *(undefined4 *)(unaff_EBP + -0x84dc) = *(undefined4 *)(unaff_EBP + -0x84e0);
    *(undefined4 *)(unaff_EBP + -0x8520) = *(undefined4 *)(unaff_EBP + -0x84dc);
    *(undefined8 *)(unaff_EBP + -0x8834) = 0;
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %lg",unaff_EBP + -0x8520
                         ,unaff_EBP + -0x84dc,unaff_EBP + -0x84e0,unaff_EBP + -0x8634,
                         unaff_EBP + -0x8834);
    if (iVar3 == 0) goto LAB_005293fd;
    if ((0 < *(int *)(unaff_EBP + -0x8520)) && (*(int *)(unaff_EBP + -0x8520) < 100)) {
      *(int *)(unaff_EBP + -0x8524) = *(int *)(unaff_EBP + -0x8520) % 10;
      *(int *)(unaff_EBP + -0x8528) = *(int *)(unaff_EBP + -0x8520) / 10;
      if (*(int *)(unaff_EBP + -0x8524) < 1) {
        *(undefined4 *)(unaff_EBP + -0x8524) = 1;
      }
      if (9 < *(int *)(unaff_EBP + -0x8524)) {
        *(undefined4 *)(unaff_EBP + -0x8524) = 9;
      }
      _DAT_00a0bcd4 = *(undefined4 *)(unaff_EBP + -0x8524);
      if (*(int *)(unaff_EBP + -0x8528) < 1) {
        *(undefined4 *)(unaff_EBP + -0x8528) = 1;
      }
      if (9 < *(int *)(unaff_EBP + -0x8528)) {
        *(undefined4 *)(unaff_EBP + -0x8528) = 9;
      }
      DAT_00a0bcd8 = *(undefined4 *)(unaff_EBP + -0x8528);
    }
    if ((0 < *(int *)(unaff_EBP + -0x84dc)) && (*(int *)(unaff_EBP + -0x84dc) < 100)) {
      *(int *)(unaff_EBP + -0x852c) = *(int *)(unaff_EBP + -0x84dc) % 10;
      *(int *)(unaff_EBP + -0x8530) = *(int *)(unaff_EBP + -0x84dc) / 10;
      if (*(int *)(unaff_EBP + -0x852c) < 1) {
        *(undefined4 *)(unaff_EBP + -0x852c) = 1;
      }
      if (9 < *(int *)(unaff_EBP + -0x852c)) {
        *(undefined4 *)(unaff_EBP + -0x852c) = 9;
      }
      _DAT_00a0bcdc = *(undefined4 *)(unaff_EBP + -0x852c);
      if (*(int *)(unaff_EBP + -0x8530) < 1) {
        *(undefined4 *)(unaff_EBP + -0x8530) = 1;
      }
      if (9 < *(int *)(unaff_EBP + -0x8530)) {
        *(undefined4 *)(unaff_EBP + -0x8530) = 9;
      }
      DAT_00a0bce0 = *(undefined4 *)(unaff_EBP + -0x8530);
    }
    if ((0 < *(int *)(unaff_EBP + -0x84e0)) && (*(int *)(unaff_EBP + -0x84e0) < 100)) {
      *(int *)(unaff_EBP + -0x8534) = *(int *)(unaff_EBP + -0x84e0) % 10;
      *(int *)(unaff_EBP + -0x8538) = *(int *)(unaff_EBP + -0x84e0) / 10;
      if (*(int *)(unaff_EBP + -0x8534) < 1) {
        *(undefined4 *)(unaff_EBP + -0x8534) = 1;
      }
      if (9 < *(int *)(unaff_EBP + -0x8534)) {
        *(undefined4 *)(unaff_EBP + -0x8534) = 9;
      }
      _DAT_00a0bce4 = *(undefined4 *)(unaff_EBP + -0x8534);
      if (*(int *)(unaff_EBP + -0x8538) < 1) {
        *(undefined4 *)(unaff_EBP + -0x8538) = 1;
      }
      if (9 < *(int *)(unaff_EBP + -0x8538)) {
        *(undefined4 *)(unaff_EBP + -0x8538) = 9;
      }
      DAT_00a0bce8 = *(undefined4 *)(unaff_EBP + -0x8538);
    }
    DAT_00a0bccc = *(undefined4 *)(unaff_EBP + -0x8634);
    DAT_00a0bcf8 = *(undefined8 *)(unaff_EBP + -0x8834);
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_SET2");
  if (iVar3 != 0) {
    *(undefined8 *)(unaff_EBP + -0x877c) = 0;
    *(undefined8 *)(unaff_EBP + -0x8774) = *(undefined8 *)(unaff_EBP + -0x877c);
    *(undefined8 *)(unaff_EBP + -0x881c) = *(undefined8 *)(unaff_EBP + -0x8774);
    *(undefined4 *)(unaff_EBP + -0x8638) = 0;
    *(undefined4 *)(unaff_EBP + -0x8640) = *(undefined4 *)(unaff_EBP + -0x8638);
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lg %lg %d %lg %d",
                         unaff_EBP + -0x881c,unaff_EBP + -0x8774,unaff_EBP + -0x8640,
                         unaff_EBP + -0x877c,unaff_EBP + -0x8638);
    if (iVar3 == 0) goto LAB_005293fd;
    DAT_00a0bd00 = *(undefined8 *)(unaff_EBP + -0x881c);
    DAT_00a0bd08 = *(undefined8 *)(unaff_EBP + -0x8774);
    DAT_00a0bd48 = *(undefined4 *)(unaff_EBP + -0x8640);
    DAT_00a0bd50 = *(undefined8 *)(unaff_EBP + -0x877c);
    DAT_00a0bd58 = *(undefined4 *)(unaff_EBP + -0x8638);
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_SET3");
  if (iVar3 != 0) {
    *(undefined8 *)(unaff_EBP + -0x87a4) = 0;
    *(undefined8 *)(unaff_EBP + -0x879c) = *(undefined8 *)(unaff_EBP + -0x87a4);
    *(undefined8 *)(unaff_EBP + -0x8794) = *(undefined8 *)(unaff_EBP + -0x879c);
    *(undefined8 *)(unaff_EBP + -0x878c) = *(undefined8 *)(unaff_EBP + -0x8794);
    *(undefined8 *)(unaff_EBP + -0x8784) = *(undefined8 *)(unaff_EBP + -0x878c);
    *(undefined8 *)(unaff_EBP + -0x882c) = *(undefined8 *)(unaff_EBP + -0x8784);
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%lg %lg %lg %lg %lg %lg",
                         unaff_EBP + -0x882c,unaff_EBP + -0x8784,unaff_EBP + -0x878c,
                         unaff_EBP + -0x8794,unaff_EBP + -0x879c,unaff_EBP + -0x87a4);
    if (iVar3 == 0) goto LAB_005293fd;
    DAT_00a0bd60 = *(undefined8 *)(unaff_EBP + -0x882c);
    DAT_00a0bd68 = *(undefined8 *)(unaff_EBP + -0x8784);
    DAT_00a0bd70 = *(undefined8 *)(unaff_EBP + -0x878c);
    DAT_00a0bd78 = *(undefined8 *)(unaff_EBP + -0x8794);
    DAT_00a0bd80 = *(undefined8 *)(unaff_EBP + -0x879c);
    DAT_00a0bd18 = *(undefined8 *)(unaff_EBP + -0x87a4);
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_SET4");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x85e0) = 0;
    *(undefined4 *)(unaff_EBP + -0x8644) = 0;
    *(undefined4 *)(unaff_EBP + -0x8590) = 0;
    *(undefined4 *)(unaff_EBP + -0x8598) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x859c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x85bc) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x87a8) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x87e4) = 0xffffffff;
    uVar2 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d",
                         unaff_EBP + -0x85e0,unaff_EBP + -0x8644,unaff_EBP + -0x8590,
                         unaff_EBP + -0x8598,unaff_EBP + -0x859c,unaff_EBP + -0x85bc,
                         unaff_EBP + -0x87a8,unaff_EBP + -0x87e4);
    *(undefined4 *)(unaff_EBP + -0x8594) = uVar2;
    if (0 < *(int *)(unaff_EBP + -0x8594)) {
      DAT_00a0bda0 = (uint)(0 < *(int *)(unaff_EBP + -0x85e0) % 10);
      if (*(int *)(unaff_EBP + -0x85e0) < 10) {
        DAT_00a0bda4 = 0;
      }
      else {
        DAT_00a0bda4 = 1;
      }
    }
    if (1 < *(int *)(unaff_EBP + -0x8594)) {
      if (*(int *)(unaff_EBP + -0x8644) == 0) {
        DAT_00a0bd88 = 0;
      }
      else {
        DAT_00a0bd88 = 1;
      }
    }
    if (((2 < *(int *)(unaff_EBP + -0x8594)) && (-1 < *(int *)(unaff_EBP + -0x8590))) &&
       (*(int *)(unaff_EBP + -0x8590) < 7)) {
      DAT_00a0bd9c = *(undefined4 *)(unaff_EBP + -0x8590);
    }
    if (((3 < *(int *)(unaff_EBP + -0x8594)) && (-1 < *(int *)(unaff_EBP + -0x8598))) &&
       (*(int *)(unaff_EBP + -0x8598) < 4)) {
      DAT_00a0bdb4 = *(undefined4 *)(unaff_EBP + -0x8598);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x859c)) && (*(int *)(unaff_EBP + -0x859c) < 2)) {
      DAT_00a0bdbc = *(undefined4 *)(unaff_EBP + -0x859c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x85bc)) && (*(int *)(unaff_EBP + -0x85bc) < 2)) {
      DAT_00a0bdb8 = *(undefined4 *)(unaff_EBP + -0x85bc);
    }
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"S_SET5");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8490) = 1;
    while (*(int *)(unaff_EBP + -0x8490) < 0xb) {
      *(undefined8 *)(unaff_EBP + -0x1f18 + *(int *)(unaff_EBP + -0x8490) * 8) = 0;
      *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
    }
    uVar2 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),
                         L"%lg %lg %lg %lg %lg %lg %lg %lg %lg %lg",unaff_EBP + -0x1f10,
                         unaff_EBP + -0x1f08,unaff_EBP + -0x1f00,unaff_EBP + -0x1ef8,
                         unaff_EBP + -0x1ef0,unaff_EBP + -0x1ee8,unaff_EBP + -0x1ee0,
                         unaff_EBP + -0x1ed8,unaff_EBP + -0x1ed0,unaff_EBP + -0x1ec8);
    *(undefined4 *)(unaff_EBP + -0x849c) = uVar2;
    if (10 < *(int *)(unaff_EBP + -0x849c)) {
      *(undefined4 *)(unaff_EBP + -0x849c) = 10;
    }
    if (0 < *(int *)(unaff_EBP + -0x849c)) {
      DAT_00a0bdc0 = *(undefined4 *)(unaff_EBP + -0x849c);
      *(undefined4 *)(unaff_EBP + -0x8490) = 1;
      while (*(int *)(unaff_EBP + -0x8490) <= *(int *)(unaff_EBP + -0x849c)) {
        if (80.0 < *(double *)(unaff_EBP + -0x1f18 + *(int *)(unaff_EBP + -0x8490) * 8)) {
          *(undefined8 *)(unaff_EBP + -0x1f18 + *(int *)(unaff_EBP + -0x8490) * 8) =
               0x4054000000000000;
        }
        pdVar1 = (double *)(unaff_EBP + -0x1f18 + *(int *)(unaff_EBP + -0x8490) * 8);
        if (*pdVar1 <= -80.0 && *pdVar1 != -80.0) {
          *(undefined8 *)(unaff_EBP + -0x1f18 + *(int *)(unaff_EBP + -0x8490) * 8) =
               0xc054000000000000;
        }
        *(undefined8 *)(&DAT_00a0bdc8 + *(int *)(unaff_EBP + -0x8490) * 8) =
             *(undefined8 *)(unaff_EBP + -0x1f18 + *(int *)(unaff_EBP + -0x8490) * 8);
        *(int *)(unaff_EBP + -0x8490) = *(int *)(unaff_EBP + -0x8490) + 1;
      }
    }
    goto LAB_005293fd;
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"ZF_SET");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8648) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x864c) = *(undefined4 *)(unaff_EBP + -0x8648);
    *(undefined4 *)(unaff_EBP + -0x8568) = *(undefined4 *)(unaff_EBP + -0x864c);
    *(undefined4 *)(unaff_EBP + -0x856c) = *(undefined4 *)(unaff_EBP + -0x8568);
    *(undefined4 *)(unaff_EBP + -0x8570) = *(undefined4 *)(unaff_EBP + -0x856c);
    *(undefined4 *)(unaff_EBP + -0x8540) = *(undefined4 *)(unaff_EBP + -0x8570);
    *(undefined4 *)(unaff_EBP + -0x853c) = *(undefined4 *)(unaff_EBP + -0x8540);
    *(undefined4 *)(unaff_EBP + -0x85cc) = *(undefined4 *)(unaff_EBP + -0x853c);
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d",
                         unaff_EBP + -0x85cc,unaff_EBP + -0x853c,unaff_EBP + -0x8540,
                         unaff_EBP + -0x8570,unaff_EBP + -0x856c,unaff_EBP + -0x8568,
                         unaff_EBP + -0x864c,unaff_EBP + -0x8648);
    if (iVar3 == 0) goto LAB_005293fd;
    if ((-2 < *(int *)(unaff_EBP + -0x85cc)) && (*(int *)(unaff_EBP + -0x85cc) < 6)) {
      DAT_00a0be80 = *(undefined4 *)(unaff_EBP + -0x85cc);
    }
    if ((-2 < *(int *)(unaff_EBP + -0x853c)) && (*(int *)(unaff_EBP + -0x853c) < 6)) {
      DAT_00a0be84 = *(undefined4 *)(unaff_EBP + -0x853c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x8540)) && (*(int *)(unaff_EBP + -0x8540) < 2)) {
      DAT_00a0d638 = *(undefined4 *)(unaff_EBP + -0x8540);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x8570)) && (*(int *)(unaff_EBP + -0x8570) < 2)) {
      DAT_00a0d63c = *(undefined4 *)(unaff_EBP + -0x8570);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x856c)) && (*(int *)(unaff_EBP + -0x856c) < 2)) {
      DAT_00a0d640 = *(undefined4 *)(unaff_EBP + -0x856c);
    }
    if ((-1 < *(int *)(unaff_EBP + -0x8568)) && (*(int *)(unaff_EBP + -0x8568) < 2)) {
      DAT_00a0be88 = *(undefined4 *)(unaff_EBP + -0x8568);
    }
  }
  iVar3 = FUN_0053e180(unaff_EBP + -0x438,L"SL_SET");
  if (iVar3 != 0) {
    *(undefined4 *)(unaff_EBP + -0x8650) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x8654) = *(undefined4 *)(unaff_EBP + -0x8650);
    *(undefined4 *)(unaff_EBP + -0x8658) = *(undefined4 *)(unaff_EBP + -0x8654);
    *(undefined4 *)(unaff_EBP + -0x8558) = *(undefined4 *)(unaff_EBP + -0x8658);
    *(undefined4 *)(unaff_EBP + -0x8548) = *(undefined4 *)(unaff_EBP + -0x8558);
    *(undefined4 *)(unaff_EBP + -0x855c) = *(undefined4 *)(unaff_EBP + -0x8548);
    *(undefined4 *)(unaff_EBP + -0x84a4) = *(undefined4 *)(unaff_EBP + -0x855c);
    *(undefined4 *)(unaff_EBP + -0x8560) = *(undefined4 *)(unaff_EBP + -0x84a4);
    *(undefined4 *)(unaff_EBP + -0x8564) = *(undefined4 *)(unaff_EBP + -0x8560);
    iVar3 = FUN_00417110(*(undefined4 *)(unaff_EBP + -0x8498),L"%d %d %d %d %d %d %d %d %d",
                         unaff_EBP + -0x8564,unaff_EBP + -0x8560,unaff_EBP + -0x84a4,
                         unaff_EBP + -0x855c,unaff_EBP + -0x8548,unaff_EBP + -0x8558,
                         unaff_EBP + -0x8658,unaff_EBP + -0x8654,unaff_EBP + -0x8650);
    if (iVar3 != 0) {
      if (-1 < *(int *)(unaff_EBP + -0x8564)) {
        *(int *)(unaff_EBP + -0x87ac) = *(int *)(unaff_EBP + -0x8564) % 10;
        *(int *)(unaff_EBP + -0x85e4) = *(int *)(unaff_EBP + -0x8564) / 10;
        *(int *)(unaff_EBP + -0x85e4) = *(int *)(unaff_EBP + -0x85e4) % 10;
        *(int *)(unaff_EBP + -0x85a4) = *(int *)(unaff_EBP + -0x8564) / 100;
        *(int *)(unaff_EBP + -0x85a4) = *(int *)(unaff_EBP + -0x85a4) % 10;
        DAT_00a0b3c0 = (uint)(*(int *)(unaff_EBP + -0x87ac) == 1);
        if (*(int *)(unaff_EBP + -0x85e4) == 1) {
          DAT_00a0b3c0 = DAT_00a0b3c0 | 2;
        }
        if (*(int *)(unaff_EBP + -0x85a4) == 1) {
          DAT_00a0b3c0 = DAT_00a0b3c0 | 4;
        }
        if (*(int *)(unaff_EBP + -0x85a4) == 2) {
          DAT_00a0b3c0 = DAT_00a0b3c0 | 8;
        }
      }
      if ((-1 < *(int *)(unaff_EBP + -0x8560)) && (*(int *)(unaff_EBP + -0x8560) < 0xd)) {
        DAT_00a0b3c4 = *(undefined4 *)(unaff_EBP + -0x8560);
      }
      if ((*(int *)(unaff_EBP + -0x84a4) < 0) || (0x100f < *(int *)(unaff_EBP + -0x84a4)))
      goto LAB_005300a5;
      DAT_00a0b3c8 = 0;
      *(int *)(unaff_EBP + -0x84a4) = *(int *)(unaff_EBP + -0x84a4) % 10000;
      if (1999 < *(int *)(unaff_EBP + -0x84a4)) {
        DAT_00a0b3c8 = DAT_00a0b3c8 + 0x10;
      }
      if (999 < *(int *)(unaff_EBP + -0x84a4)) {
        DAT_00a0b3c8 = DAT_00a0b3c8 + 8;
      }
      *(int *)(unaff_EBP + -0x84a4) = *(int *)(unaff_EBP + -0x84a4) % 1000;
      if (99 < *(int *)(unaff_EBP + -0x84a4)) {
        DAT_00a0b3c8 = DAT_00a0b3c8 + 4;
      }
      goto code_r0x00530043;
    }
    goto LAB_005293fd;
  }
  goto LAB_0053010f;
}




/* vtable slots: PAU1::PAU_ITEMIDLIST::?$CList[5], PAU1::PAU_ITEMIDLIST::?$CList[15] */
/* 00650068  __break  1 bytes, 0 callers */

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}




/* vtable slots: PAU1::PAU_ITEMIDLIST::?$CList[1] */
/* 007e1fbc  FUN_007e1fbc  100 bytes, 0 callers */

void FUN_007e1fbc(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944167;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *in_ECX = CList<_ITEMIDLIST*,_ITEMIDLIST*>::vftable;
  RemoveAll(uVar1);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  ExceptionList = local_10;
  return;
}



