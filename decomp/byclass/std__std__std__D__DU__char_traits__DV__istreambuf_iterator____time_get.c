/* std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[3], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$time_get[3], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[3] */
/* 008e8512  FUN_008e8512  4 bytes, 0 callers */

undefined4 FUN_008e8512(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[0] */
/* 008ecede  FUN_008ecede  46 bytes, 0 callers */

void FUN_008ecede(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::vftable;
  Tidy();
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[9] */
/* 008eedd8  FUN_008eedd8  961 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008eedd8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,int param_8,char param_9)

{
  uint *puVar1;
  bool bVar2;
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
  local_8 = 0x8eede4;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  local_14 = FUN_008db390(local_20);
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
          if (param_9 == 'A') goto LAB_008eef8f;
          if (param_9 == 'B') goto LAB_008ef093;
          if (param_9 == 'C') {
            uVar3 = FUN_008ed421();
            uVar4 = *puVar1;
            *puVar1 = uVar4 | uVar3;
            if (((uVar4 | uVar3) & 2) != 0) goto LAB_008ef170;
            uVar4 = (local_1c - 0x13) * 100;
LAB_008eef13:
            *(uint *)(param_8 + 0x14) = uVar4;
            goto LAB_008ef170;
          }
          if (param_9 != 'D') {
            if (param_9 != 'H') {
              if (param_9 == 'I') {
                uVar3 = FUN_008ed421();
                uVar4 = *puVar1;
                *puVar1 = uVar4 | uVar3;
                if (((uVar4 | uVar3) & 2) == 0) {
                  *(uint *)(param_8 + 8) = -(uint)(local_1c != 0xc) & local_1c;
                }
                goto LAB_008ef170;
              }
              if (param_9 != 'M') goto LAB_008ef0d4;
            }
            goto LAB_008ef055;
          }
          pcVar7 = "%m / %d / %y";
        }
        goto LAB_008ef072;
      }
      if (param_9 == 'S') {
LAB_008ef055:
        uVar4 = FUN_008ed421();
        *puVar1 = *puVar1 | uVar4;
        goto LAB_008ef170;
      }
      if (param_9 != 'T') {
        if ((param_9 == 'U') || (param_9 == 'W')) goto LAB_008ef055;
        if (param_9 != 'X') {
          if (param_9 != 'Y') goto LAB_008ef0d4;
          puVar5 = (undefined4 *)
                   get_year(local_18,param_2,param_3,param_4,param_5,iVar6,param_7,param_8);
          goto LAB_008eefab;
        }
      }
      pcVar7 = "%H : %M : %S";
      goto LAB_008ef072;
    }
LAB_008eef8f:
    puVar5 = (undefined4 *)
             FUN_008ec4f0(local_20,param_2,param_3,param_4,param_5,iVar6,param_7,param_8);
  }
  else {
    if (param_9 < 'o') {
      if (param_9 != 'n') {
        if (param_9 != 'b') {
          if (param_9 == 'c') {
            pcVar7 = "%b %d %H : %M : %S %Y";
            goto LAB_008ef072;
          }
          if ((param_9 != 'd') && (param_9 != 'e')) {
            if (param_9 == 'h') goto LAB_008ef093;
            if (param_9 != 'j') {
              if (param_9 == 'm') {
                uVar3 = FUN_008ed421();
                uVar4 = *puVar1;
                *puVar1 = uVar4 | uVar3;
                if (((uVar4 | uVar3) & 2) == 0) {
                  *(uint *)(param_8 + 0x10) = local_1c - 1;
                }
                goto LAB_008ef170;
              }
              goto LAB_008ef0d4;
            }
          }
          goto LAB_008ef055;
        }
LAB_008ef093:
        puVar5 = (undefined4 *)
                 get_monthname(local_20,param_2,param_3,param_4,param_5,iVar6,param_7,param_8);
        goto LAB_008eefab;
      }
LAB_008ef130:
      pcVar7 = " ";
    }
    else {
      if (param_9 == 'p') {
        iVar6 = FUN_008dafb9(&param_2,&param_4,0,":AM:am:PM:pm",0);
        if (iVar6 < 0) {
          *puVar1 = *puVar1 | 2;
        }
        else if (1 < iVar6) {
          *(int *)(param_8 + 8) = *(int *)(param_8 + 8) + 0xc;
        }
        goto LAB_008ef170;
      }
      if (param_9 == 'r') {
        pcVar7 = "%I : %M : %S %p";
      }
      else {
        if (param_9 == 't') goto LAB_008ef130;
        if (param_9 == 'w') goto LAB_008ef055;
        if (param_9 != 'x') {
          if (param_9 == 'y') {
            uVar3 = FUN_008ed421();
            uVar4 = *puVar1;
            *puVar1 = uVar4 | uVar3;
            if (((uVar4 | uVar3) & 2) != 0) goto LAB_008ef170;
            uVar4 = local_1c;
            if ((int)local_1c < 0x45) {
              uVar4 = local_1c + 100;
            }
            goto LAB_008eef13;
          }
LAB_008ef0d4:
          *param_7 = 2;
          goto LAB_008ef170;
        }
        pcVar7 = "%d / %m / %y";
      }
    }
LAB_008ef072:
    puVar5 = (undefined4 *)
             FUN_008ed2f1(local_20,param_2,param_3,param_4,param_5,iVar6,param_7,param_8,pcVar7);
  }
LAB_008eefab:
  param_2 = *puVar5;
  param_3 = puVar5[1];
LAB_008ef170:
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (bVar2) {
    *puVar1 = *puVar1 | 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[5] */
/* 008ef199  FUN_008ef199  1166 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008ef199(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,int param_8)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  int *local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x8ef1a5;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  piVar4 = (int *)FUN_008db390(local_20);
  local_8 = 0xffffffff;
  local_18 = piVar4;
  FUN_005546e0();
  iVar5 = FUN_008dd70b();
  if (iVar5 == 0) {
    iVar5 = 2;
  }
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  puVar9 = param_7;
  if (!bVar2) {
    uVar8 = CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3));
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
      uVar8 = CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3));
    }
    if (((uint)(int)*(short *)(piVar4[3] + (uint)param_3._1_1_ * 2) >> 2 & 1) == 0) {
      puVar6 = (undefined4 *)
               get_monthname(local_20,param_2,uVar8,param_4,param_5,param_6,puVar9,param_8);
      iVar5 = 2;
LAB_008ef2b6:
      param_2 = *puVar6;
      uVar8 = puVar6[1];
      param_3._0_1_ = (char)uVar8;
      param_3._1_1_ = (byte)((uint)uVar8 >> 8);
      param_3._2_2_ = (undefined2)((uint)uVar8 >> 0x10);
    }
    else if (iVar5 == 2) {
      piVar4 = (int *)(param_8 + 0x10);
      uVar7 = FUN_008ed421(local_14,&param_2,&param_4,1,0xc,piVar4,local_18);
      *puVar9 = *puVar9 | uVar7;
      *piVar4 = *piVar4 + -1;
      piVar4 = local_18;
    }
    else {
      if (iVar5 != 1) {
        puVar6 = (undefined4 *)
                 get_year(local_20,param_2,uVar8,param_4,param_5,param_6,puVar9,param_8);
        goto LAB_008ef2b6;
      }
      uVar7 = FUN_008ed421(local_14,&param_2,&param_4,1,0x1f,param_8 + 0xc,piVar4);
      *puVar9 = *puVar9 | uVar7;
    }
  }
  while (bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                           ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                            (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4),
        !bVar2) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    if ((*(byte *)(piVar4[3] + (uint)param_3._1_1_ * 2) & 0x48) == 0) break;
    std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
  }
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (!bVar2) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    pcVar1 = *(code **)(*piVar4 + 0x28);
    guard_check_icall(CONCAT13(param_4._0_1_,CONCAT21(param_3._2_2_,param_3._1_1_)),0);
    cVar3 = (*pcVar1)();
    if (((cVar3 == ':') || (cVar3 == ',')) || (cVar3 == '/')) {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
  }
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  piVar4 = local_18;
  while (!bVar2) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    puVar9 = param_7;
    if ((*(byte *)(piVar4[3] + (uint)param_3._1_1_ * 2) & 0x48) == 0) break;
    std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                      ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                       (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
    puVar9 = param_7;
  }
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (!bVar2) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    if (((uint)(int)*(short *)(local_18[3] + (uint)param_3._1_1_ * 2) >> 2 & 1) == 0) {
      if (iVar5 == 2) {
        *puVar9 = *puVar9 | 2;
      }
      else {
        puVar6 = (undefined4 *)
                 get_monthname(local_20,param_2,
                               CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),param_4
                               ,param_5,param_6,puVar9,param_8);
        param_2 = *puVar6;
        uVar8 = puVar6[1];
        param_3._0_1_ = (char)uVar8;
        param_3._1_1_ = (byte)((uint)uVar8 >> 8);
        param_3._2_2_ = (undefined2)((uint)uVar8 >> 0x10);
        if (iVar5 == 4) {
          iVar5 = 3;
        }
      }
    }
    else if ((iVar5 == 1) || (iVar5 == 3)) {
      piVar4 = (int *)(param_8 + 0x10);
      uVar7 = FUN_008ed421(local_14,&param_2,&param_4,1,0xc,piVar4,local_18);
      *puVar9 = *puVar9 | uVar7;
      *piVar4 = *piVar4 + -1;
    }
    else {
      uVar7 = FUN_008ed421(local_14,&param_2,&param_4,1,0x1f,param_8 + 0xc,local_18);
      *puVar9 = *puVar9 | uVar7;
    }
  }
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  piVar4 = local_18;
  while (bVar2 == false) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    if ((*(byte *)(piVar4[3] + (uint)param_3._1_1_ * 2) & 0x48) == 0) break;
    std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                      ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                       (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  }
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (!bVar2) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    pcVar1 = *(code **)(*piVar4 + 0x28);
    guard_check_icall(CONCAT13(param_4._0_1_,CONCAT21(param_3._2_2_,param_3._1_1_)),0);
    cVar3 = (*pcVar1)();
    if (((cVar3 == ':') || (cVar3 == ',')) || (cVar3 == '/')) {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
  }
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  piVar4 = local_18;
  while (!bVar2) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    puVar9 = param_7;
    if ((*(byte *)(piVar4[3] + (uint)param_3._1_1_ * 2) & 0x48) == 0) break;
    std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                      ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                       (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
    puVar9 = param_7;
  }
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (bVar2) {
LAB_008ef531:
    *puVar9 = *puVar9 | 2;
  }
  else {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    if (((uint)(int)*(short *)(local_18[3] + (uint)param_3._1_1_ * 2) >> 2 & 1) == 0) {
      if (iVar5 != 4) goto LAB_008ef531;
      puVar6 = (undefined4 *)
               get_monthname(local_20,param_2,
                             CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),param_4,
                             param_5,param_6,puVar9,param_8);
    }
    else {
      if (iVar5 == 4) {
        piVar4 = (int *)(param_8 + 0x10);
        uVar7 = FUN_008ed421(local_14,&param_2,&param_4,1,0xc,piVar4,local_18);
        *puVar9 = *puVar9 | uVar7;
        *piVar4 = *piVar4 + -1;
        goto LAB_008ef5fe;
      }
      if (iVar5 == 3) {
        uVar7 = FUN_008ed421(local_14,&param_2,&param_4,1,0x1f,param_8 + 0xc,local_18);
        *puVar9 = *puVar9 | uVar7;
        goto LAB_008ef5fe;
      }
      puVar6 = (undefined4 *)
               get_year(local_28,param_2,
                        CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3)),param_4,
                        param_5,param_6,puVar9,param_8);
    }
    param_2 = *puVar6;
    uVar8 = puVar6[1];
    param_3._0_1_ = (char)uVar8;
    param_3._1_1_ = (byte)((uint)uVar8 >> 8);
    param_3._2_2_ = (undefined2)((uint)uVar8 >> 0x10);
  }
LAB_008ef5fe:
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (bVar2) {
    *puVar9 = *puVar9 | 1;
  }
  *param_1 = param_2;
  param_1[1] = CONCAT22(param_3._2_2_,CONCAT11(param_3._1_1_,(char)param_3));
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[7] */
/* 008ef627  FUN_008ef627  66 bytes, 0 callers */

void FUN_008ef627(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  uint *in_stack_0000001c;
  int in_stack_00000020;
  
  iVar1 = FUN_008dafb9(&param_2,&stack0x00000010,0,*(undefined4 *)(in_ECX + 0xc),0);
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




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[4] */
/* 008ef669  FUN_008ef669  290 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008ef669(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
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
  local_8 = 0x8ef675;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  piVar4 = (int *)FUN_008db390(local_1c);
  local_8 = 0xffffffff;
  FUN_005546e0();
  uVar5 = FUN_008ed421();
  puVar2 = param_7;
  *param_7 = *param_7 | uVar5;
  if (*param_7 == 0) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    pcVar1 = *(code **)(*piVar4 + 0x28);
    guard_check_icall(CONCAT13(param_4,param_3._1_3_),0);
    cVar3 = (*pcVar1)();
    if (cVar3 != ':') goto LAB_008ef71b;
    std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
              ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    uVar5 = FUN_008ed421(local_14,&param_2,&param_4,0,0x3b,param_8 + 4,piVar4);
    *puVar2 = *puVar2 | uVar5;
  }
  else {
LAB_008ef71b:
    *puVar2 = *puVar2 | 2;
  }
  if (*puVar2 == 0) {
    if ((char)param_3 == '\0') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
    }
    pcVar1 = *(code **)(*piVar4 + 0x28);
    guard_check_icall(CONCAT13(param_4,param_3._1_3_),0);
    cVar3 = (*pcVar1)();
    if (cVar3 == ':') {
      std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc
                ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2);
      uVar5 = FUN_008ed421(local_14,&param_2,&param_4,0,0x3c,param_8,piVar4);
      *puVar2 = *puVar2 | uVar5;
      goto LAB_008ef775;
    }
  }
  *puVar2 = *puVar2 | 2;
LAB_008ef775:
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[6] */
/* 008ef78b  FUN_008ef78b  66 bytes, 0 callers */

void FUN_008ef78b(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  uint *in_stack_0000001c;
  int in_stack_00000020;
  
  iVar1 = FUN_008dafb9(&param_2,&stack0x00000010,0,*(undefined4 *)(in_ECX + 8),0);
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




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[8] */
/* 008ef7cd  FUN_008ef7cd  149 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008ef7cd(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint *param_7,int param_8)

{
  uint uVar1;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8ef7d9;
  FUN_00553da0(*(undefined4 *)(param_6 + 0x30));
  local_8 = 0;
  FUN_008db390(local_18);
  local_8 = 0xffffffff;
  FUN_005546e0();
  local_14 = 0;
  uVar1 = FUN_008ed421();
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



