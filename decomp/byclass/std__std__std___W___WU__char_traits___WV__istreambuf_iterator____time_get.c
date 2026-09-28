/* std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[0] */
/* 008e1232  FUN_008e1232  46 bytes, 0 callers */

void FUN_008e1232(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::time_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>_>_>::
            vftable;
  Tidy();
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[9] */
/* 008e9f1c  FUN_008e9f1c  961 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008e9f1c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,int param_8,char param_9)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  undefined1 local_20 [4];
  uint local_1c;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  iVar6 = param_6;
  uStack_4 = 0x10;
  local_8 = 0x8e9f28;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  local_14 = FUN_00552880(local_20);
  local_8 = 0xffffffff;
  FUN_005546e0();
  puVar1 = param_7;
  local_1c = 0;
  *param_7 = 0;
  if (param_9 < 'b') {
    if (param_9 != 'a') {
      if (param_9 < 'S') {
        if (param_9 == 'R') {
          pcVar7 = "%H : %M";
        }
        else {
          if (param_9 == 'A') goto LAB_008ea0d3;
          if (param_9 == 'B') goto LAB_008ea1d7;
          if (param_9 == 'C') {
            uVar3 = FUN_008e4957();
            uVar4 = *puVar1;
            *puVar1 = uVar4 | uVar3;
            if (((uVar4 | uVar3) & 2) != 0) goto LAB_008ea2b4;
            uVar4 = (local_1c - 0x13) * 100;
LAB_008ea057:
            *(uint *)(param_8 + 0x14) = uVar4;
            goto LAB_008ea2b4;
          }
          if (param_9 != 'D') {
            if (param_9 != 'H') {
              if (param_9 == 'I') {
                uVar3 = FUN_008e4957();
                uVar4 = *puVar1;
                *puVar1 = uVar4 | uVar3;
                if (((uVar4 | uVar3) & 2) == 0) {
                  *(uint *)(param_8 + 8) = -(uint)(local_1c != 0xc) & local_1c;
                }
                goto LAB_008ea2b4;
              }
              if (param_9 != 'M') goto LAB_008ea218;
            }
            goto LAB_008ea199;
          }
          pcVar7 = "%m / %d / %y";
        }
        goto LAB_008ea1b6;
      }
      if (param_9 == 'S') {
LAB_008ea199:
        uVar4 = FUN_008e4957();
        *puVar1 = *puVar1 | uVar4;
        goto LAB_008ea2b4;
      }
      if (param_9 != 'T') {
        if ((param_9 == 'U') || (param_9 == 'W')) goto LAB_008ea199;
        if (param_9 != 'X') {
          if (param_9 != 'Y') goto LAB_008ea218;
          puVar5 = (undefined4 *)
                   get_year(local_18,param_2,param_3,param_4,param_5,iVar6,param_7,param_8);
          goto LAB_008ea0ef;
        }
      }
      pcVar7 = "%H : %M : %S";
      goto LAB_008ea1b6;
    }
LAB_008ea0d3:
    puVar5 = (undefined4 *)
             FUN_008ec4f0(local_20,param_2,param_3,param_4,param_5,iVar6,param_7,param_8);
  }
  else {
    if (param_9 < 'o') {
      if (param_9 != 'n') {
        if (param_9 != 'b') {
          if (param_9 == 'c') {
            pcVar7 = "%b %d %H : %M : %S %Y";
            goto LAB_008ea1b6;
          }
          if ((param_9 != 'd') && (param_9 != 'e')) {
            if (param_9 == 'h') goto LAB_008ea1d7;
            if (param_9 != 'j') {
              if (param_9 == 'm') {
                uVar3 = FUN_008e4957();
                uVar4 = *puVar1;
                *puVar1 = uVar4 | uVar3;
                if (((uVar4 | uVar3) & 2) == 0) {
                  *(uint *)(param_8 + 0x10) = local_1c - 1;
                }
                goto LAB_008ea2b4;
              }
              goto LAB_008ea218;
            }
          }
          goto LAB_008ea199;
        }
LAB_008ea1d7:
        puVar5 = (undefined4 *)
                 get_monthname(local_20,param_2,param_3,param_4,param_5,iVar6,param_7,param_8);
        goto LAB_008ea0ef;
      }
LAB_008ea274:
      pcVar7 = " ";
    }
    else {
      if (param_9 == 'p') {
        iVar6 = FUN_008df092(&param_2,&param_4,0,":AM:am:PM:pm",0);
        if (iVar6 < 0) {
          *puVar1 = *puVar1 | 2;
        }
        else if (1 < iVar6) {
          *(int *)(param_8 + 8) = *(int *)(param_8 + 8) + 0xc;
        }
        goto LAB_008ea2b4;
      }
      if (param_9 == 'r') {
        pcVar7 = "%I : %M : %S %p";
      }
      else {
        if (param_9 == 't') goto LAB_008ea274;
        if (param_9 == 'w') goto LAB_008ea199;
        if (param_9 != 'x') {
          if (param_9 == 'y') {
            uVar3 = FUN_008e4957();
            uVar4 = *puVar1;
            *puVar1 = uVar4 | uVar3;
            if (((uVar4 | uVar3) & 2) != 0) goto LAB_008ea2b4;
            uVar4 = local_1c;
            if ((int)local_1c < 0x45) {
              uVar4 = local_1c + 100;
            }
            goto LAB_008ea057;
          }
LAB_008ea218:
          *param_7 = 2;
          goto LAB_008ea2b4;
        }
        pcVar7 = "%d / %m / %y";
      }
    }
LAB_008ea1b6:
    puVar5 = (undefined4 *)
             FUN_008e4056(local_20,param_2,param_3,param_4,param_5,iVar6,param_7,param_8,pcVar7);
  }
LAB_008ea0ef:
  param_2 = *puVar5;
  param_3 = puVar5[1];
LAB_008ea2b4:
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[5] */
/* 008ea788  FUN_008ea788  1195 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008ea788(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,int param_8)

{
  code *pcVar1;
  uint *puVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x8ea794;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  piVar5 = (int *)FUN_00552880(local_1c);
  local_8 = 0xffffffff;
  FUN_005546e0();
  local_18 = FUN_008dd70b();
  if (local_18 == 0) {
    local_18 = 2;
  }
  cVar4 = equal(&param_4);
  puVar2 = param_7;
  if (cVar4 == '\0') {
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar5 + 0x10);
    guard_check_icall(4,CONCAT22((undefined2)param_4,param_3._2_2_));
    cVar4 = (*pcVar1)();
    if (cVar4 == '\0') {
      puVar6 = (undefined4 *)
               get_monthname(local_1c,param_2,
                             CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),
                             CONCAT22(param_4._2_2_,(undefined2)param_4),param_5,param_6,puVar2,
                             param_8);
      param_2 = *puVar6;
      uVar7 = puVar6[1];
      local_18 = 2;
LAB_008ea8bf:
      param_3._0_1_ = (char)uVar7;
      param_3._1_1_ = (undefined1)((uint)uVar7 >> 8);
      param_3._2_2_ = (undefined2)((uint)uVar7 >> 0x10);
    }
    else if (local_18 == 2) {
      piVar9 = (int *)(param_8 + 0x10);
      uVar8 = FUN_008e4957(local_14,&param_2,&param_4,1,0xc,piVar9,piVar5);
      *puVar2 = *puVar2 | uVar8;
      *piVar9 = *piVar9 + -1;
    }
    else {
      if (local_18 != 1) {
        puVar6 = (undefined4 *)
                 get_year(local_24,param_2,
                          CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),
                          CONCAT22(param_4._2_2_,(undefined2)param_4),param_5,param_6,puVar2,param_8
                         );
        param_2 = *puVar6;
        uVar7 = puVar6[1];
        goto LAB_008ea8bf;
      }
      uVar8 = FUN_008e4957(local_14,&param_2,&param_4,1,0x1f,param_8 + 0xc,piVar5);
      *puVar2 = *puVar2 | uVar8;
    }
  }
  while (cVar4 = equal(&param_4), cVar4 == '\0') {
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar5 + 0x10);
    guard_check_icall(0x48,CONCAT22((undefined2)param_4,param_3._2_2_));
    cVar4 = (*pcVar1)();
    if (cVar4 == '\0') break;
    Inc();
  }
  cVar4 = equal(&param_4);
  if (cVar4 != '\0') goto LAB_008ea978;
  if ((char)param_3 == '\0') {
    Peek();
  }
  pcVar1 = *(code **)(*piVar5 + 0x38);
  guard_check_icall(CONCAT22((undefined2)param_4,param_3._2_2_),0);
  cVar4 = (*pcVar1)();
  if (((cVar4 != ':') && (cVar4 != ',')) && (cVar4 != '/')) goto LAB_008ea978;
  do {
    Inc();
LAB_008ea978:
    cVar4 = equal(&param_4);
    if (cVar4 != '\0') break;
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar5 + 0x10);
    guard_check_icall(0x48,CONCAT22((undefined2)param_4,param_3._2_2_));
    cVar4 = (*pcVar1)();
  } while (cVar4 != '\0');
  cVar4 = equal(&param_4);
  if (cVar4 == '\0') {
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar5 + 0x10);
    guard_check_icall(4,CONCAT22((undefined2)param_4,param_3._2_2_));
    cVar4 = (*pcVar1)();
    iVar3 = local_18;
    if (cVar4 == '\0') {
      if (local_18 == 2) {
        *puVar2 = *puVar2 | 2;
      }
      else {
        puVar6 = (undefined4 *)
                 get_monthname(local_24,param_2,
                               CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),
                               CONCAT22(param_4._2_2_,(undefined2)param_4),param_5,param_6,puVar2,
                               param_8);
        param_2 = *puVar6;
        uVar7 = puVar6[1];
        param_3._0_1_ = (char)uVar7;
        param_3._1_1_ = (undefined1)((uint)uVar7 >> 8);
        param_3._2_2_ = (undefined2)((uint)uVar7 >> 0x10);
        if (iVar3 == 4) {
          local_18 = 3;
        }
      }
    }
    else if ((local_18 == 1) || (local_18 == 3)) {
      piVar9 = (int *)(param_8 + 0x10);
      uVar8 = FUN_008e4957(local_14,&param_2,&param_4,1,0xc,piVar9,piVar5);
      *puVar2 = *puVar2 | uVar8;
      *piVar9 = *piVar9 + -1;
    }
    else {
      uVar8 = FUN_008e4957(local_14,&param_2,&param_4,1,0x1f,param_8 + 0xc,piVar5);
      *puVar2 = *puVar2 | uVar8;
    }
  }
  while (cVar4 = equal(&param_4), cVar4 == '\0') {
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar5 + 0x10);
    guard_check_icall(0x48,CONCAT22((undefined2)param_4,param_3._2_2_));
    cVar4 = (*pcVar1)();
    if (cVar4 == '\0') break;
    Inc();
  }
  cVar4 = equal(&param_4);
  if (cVar4 != '\0') goto LAB_008eab14;
  if ((char)param_3 == '\0') {
    Peek();
  }
  pcVar1 = *(code **)(*piVar5 + 0x38);
  guard_check_icall(CONCAT22((undefined2)param_4,param_3._2_2_),0);
  cVar4 = (*pcVar1)();
  if (((cVar4 != ':') && (cVar4 != ',')) && (cVar4 != '/')) goto LAB_008eab14;
  do {
    Inc();
LAB_008eab14:
    cVar4 = equal(&param_4);
    if (cVar4 != '\0') break;
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar5 + 0x10);
    guard_check_icall(0x48,CONCAT22((undefined2)param_4,param_3._2_2_));
    cVar4 = (*pcVar1)();
  } while (cVar4 != '\0');
  cVar4 = equal(&param_4);
  if (cVar4 == '\0') {
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar5 + 0x10);
    guard_check_icall(4,CONCAT22((undefined2)param_4,param_3._2_2_));
    cVar4 = (*pcVar1)();
    if (cVar4 == '\0') {
      if (local_18 != 4) goto LAB_008eab34;
      puVar6 = (undefined4 *)
               get_monthname(local_24,param_2,
                             CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),
                             CONCAT22(param_4._2_2_,(undefined2)param_4),param_5,param_6,puVar2,
                             param_8);
    }
    else {
      if (local_18 == 4) {
        piVar9 = (int *)(param_8 + 0x10);
        uVar8 = FUN_008e4957(local_14,&param_2,&param_4,1,0xc,piVar9,piVar5);
        *puVar2 = *puVar2 | uVar8;
        *piVar9 = *piVar9 + -1;
        goto LAB_008eac0a;
      }
      if (local_18 == 3) {
        uVar8 = FUN_008e4957(local_14,&param_2,&param_4,1,0x1f,param_8 + 0xc,piVar5);
        *puVar2 = *puVar2 | uVar8;
        goto LAB_008eac0a;
      }
      puVar6 = (undefined4 *)
               get_year(local_2c,param_2,
                        CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),
                        CONCAT22(param_4._2_2_,(undefined2)param_4),param_5,param_6,puVar2,param_8);
    }
    param_2 = *puVar6;
    uVar7 = puVar6[1];
    param_3._0_1_ = (char)uVar7;
    param_3._1_1_ = (undefined1)((uint)uVar7 >> 8);
    param_3._2_2_ = (undefined2)((uint)uVar7 >> 0x10);
  }
  else {
LAB_008eab34:
    *puVar2 = *puVar2 | 2;
  }
LAB_008eac0a:
  cVar4 = equal(&param_4);
  if (cVar4 != '\0') {
    *puVar2 = *puVar2 | 1;
  }
  *param_1 = param_2;
  param_1[1] = CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3));
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[7] */
/* 008eac75  FUN_008eac75  66 bytes, 0 callers */

void FUN_008eac75(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  uint *in_stack_0000001c;
  int in_stack_00000020;
  
  iVar1 = FUN_008df4bd(&param_2,&stack0x00000010,0,*(undefined4 *)(in_ECX + 0xc),0);
  if (iVar1 < 0) {
    *in_stack_0000001c = *in_stack_0000001c | 2;
  }
  else {
    *(int *)(in_stack_00000020 + 0x10) = iVar1 >> 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[4] */
/* 008eadd9  FUN_008eadd9  290 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008eadd9(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                 undefined4 param_5,int param_6,uint *param_7,int param_8)

{
  code *pcVar1;
  uint *puVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8eade5;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  piVar4 = (int *)FUN_00552880(local_1c);
  local_8 = 0xffffffff;
  FUN_005546e0();
  uVar5 = FUN_008e4957();
  puVar2 = param_7;
  *param_7 = *param_7 | uVar5;
  if (*param_7 == 0) {
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar4 + 0x38);
    guard_check_icall(CONCAT22(param_4,param_3._2_2_),0);
    cVar3 = (*pcVar1)();
    if (cVar3 != ':') goto LAB_008eae8b;
    Inc();
    uVar5 = FUN_008e4957(local_14,&param_2,&param_4,0,0x3b,param_8 + 4,piVar4);
    *puVar2 = *puVar2 | uVar5;
  }
  else {
LAB_008eae8b:
    *puVar2 = *puVar2 | 2;
  }
  if (*puVar2 == 0) {
    if ((char)param_3 == '\0') {
      Peek();
    }
    pcVar1 = *(code **)(*piVar4 + 0x38);
    guard_check_icall(CONCAT22(param_4,param_3._2_2_),0);
    cVar3 = (*pcVar1)();
    if (cVar3 == ':') {
      Inc();
      uVar5 = FUN_008e4957(local_14,&param_2,&param_4,0,0x3c,param_8,piVar4);
      *puVar2 = *puVar2 | uVar5;
      goto LAB_008eaee5;
    }
  }
  *puVar2 = *puVar2 | 2;
LAB_008eaee5:
  *param_1 = param_2;
  param_1[1] = CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3));
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[6] */
/* 008eaf3d  FUN_008eaf3d  66 bytes, 0 callers */

void FUN_008eaf3d(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  uint *in_stack_0000001c;
  int in_stack_00000020;
  
  iVar1 = FUN_008df4bd(&param_2,&stack0x00000010,0,*(undefined4 *)(in_ECX + 8),0);
  if (iVar1 < 0) {
    *in_stack_0000001c = *in_stack_0000001c | 2;
  }
  else {
    *(int *)(in_stack_00000020 + 0x18) = iVar1 >> 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[8] */
/* 008eb014  FUN_008eb014  149 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008eb014(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,int param_8)

{
  uint uVar1;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8eb020;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  FUN_00552880(local_18);
  local_8 = 0xffffffff;
  FUN_005546e0();
  local_14 = 0;
  uVar1 = FUN_008e4957();
  *param_7 = *param_7 | uVar1;
  if ((uVar1 & 2) == 0) {
    if (local_14 < 0x45) {
      local_14 = local_14 + 100;
    }
    else if (99 < local_14) {
      local_14 = local_14 + -0x76c;
    }
    *(int *)(param_8 + 0x14) = local_14;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}



