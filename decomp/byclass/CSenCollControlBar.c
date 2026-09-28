/* CSenCollControlBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSenCollControlBar[1] */
/* 005bb7a0  FUN_005bb7a0  68 bytes, 0 callers */

undefined4 FUN_005bb7a0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005bb6f0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x118);
    }
  }
  return in_ECX;
}




/* vtable slots: CSenCollControlBar[90], CSenCollControlBar2[90] */
/* 005bb7f0  FUN_005bb7f0  740 bytes, 0 callers */

undefined4 * FUN_005bb7f0(undefined4 *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_a8 [8];
  undefined1 local_a0 [8];
  undefined1 local_98 [8];
  undefined1 local_90 [8];
  undefined1 local_88 [8];
  undefined1 local_80 [8];
  undefined1 local_78 [8];
  undefined1 local_70 [8];
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined1 local_58 [8];
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_0041c8d0(200,0x1e);
  if (*(int *)(local_8 + 0x114) == 0) {
    if ((param_3 & 0x10) == 0) {
      if ((param_3 & 8) == 0) {
        if ((param_3 & 0x40) == 0) {
          if ((param_3 & 4) == 0) {
            if ((param_3 & 2) != 0) {
              if ((param_3 & 0x20) == 0) {
                piVar3 = (int *)FUN_005bbae0(local_68,0x10);
                if (param_2 < *piVar3) {
                  piVar3 = (int *)FUN_005bbae0(local_78,8);
                  if (param_2 < *piVar3) {
                    piVar3 = (int *)FUN_005bbae0(local_88,4);
                    if (param_2 < *piVar3) {
                      piVar3 = (int *)FUN_005bbae0(local_98,2);
                      if (param_2 < *piVar3) {
                        puVar1 = (undefined4 *)FUN_005bbae0(local_a8,1);
                        local_10 = *puVar1;
                        local_c = puVar1[1];
                      }
                      else {
                        puVar1 = (undefined4 *)FUN_005bbae0(local_a0,2);
                        local_10 = *puVar1;
                        local_c = puVar1[1];
                      }
                    }
                    else {
                      puVar1 = (undefined4 *)FUN_005bbae0(local_90,4);
                      local_10 = *puVar1;
                      local_c = puVar1[1];
                    }
                  }
                  else {
                    puVar1 = (undefined4 *)FUN_005bbae0(local_80,8);
                    local_10 = *puVar1;
                    local_c = puVar1[1];
                  }
                }
                else {
                  puVar1 = (undefined4 *)FUN_005bbae0(local_70,0x10);
                  local_10 = *puVar1;
                  local_c = puVar1[1];
                }
              }
              else {
                iVar2 = FUN_005bbae0(local_20,1);
                if (param_2 < *(int *)(iVar2 + 4)) {
                  iVar2 = FUN_005bbae0(local_30,2);
                  if (param_2 < *(int *)(iVar2 + 4)) {
                    iVar2 = FUN_005bbae0(local_40,4);
                    if (param_2 < *(int *)(iVar2 + 4)) {
                      iVar2 = FUN_005bbae0(local_50,8);
                      if (param_2 < *(int *)(iVar2 + 4)) {
                        puVar1 = (undefined4 *)FUN_005bbae0(local_60,0x10);
                        local_10 = *puVar1;
                        local_c = puVar1[1];
                      }
                      else {
                        puVar1 = (undefined4 *)FUN_005bbae0(local_58,8);
                        local_10 = *puVar1;
                        local_c = puVar1[1];
                      }
                    }
                    else {
                      puVar1 = (undefined4 *)FUN_005bbae0(local_48,4);
                      local_10 = *puVar1;
                      local_c = puVar1[1];
                    }
                  }
                  else {
                    puVar1 = (undefined4 *)FUN_005bbae0(local_38,2);
                    local_10 = *puVar1;
                    local_c = puVar1[1];
                  }
                }
                else {
                  puVar1 = (undefined4 *)FUN_005bbae0(local_28,1);
                  local_10 = *puVar1;
                  local_c = puVar1[1];
                }
              }
            }
          }
          else {
            local_10 = *(undefined4 *)(local_8 + 0x100);
            local_c = *(undefined4 *)(local_8 + 0x104);
          }
        }
        else {
          local_10 = *(undefined4 *)(local_8 + 0x100);
          local_c = *(undefined4 *)(local_8 + 0x104);
        }
      }
      else {
        local_10 = *(undefined4 *)(local_8 + 0x100);
        local_c = *(undefined4 *)(local_8 + 0x104);
      }
    }
    else {
      local_10 = *(undefined4 *)(local_8 + 0x100);
      local_c = *(undefined4 *)(local_8 + 0x104);
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_005bbae0(local_18,4);
    local_10 = *puVar1;
    local_c = puVar1[1];
  }
  *(undefined4 *)(local_8 + 0x100) = local_10;
  *(undefined4 *)(local_8 + 0x104) = local_c;
  *param_1 = local_10;
  param_1[1] = local_c;
  return param_1;
}




/* vtable slots: CSenCollControlBar[10] */
/* 005bbd00  FUN_005bbd00  16 bytes, 0 callers */

void FUN_005bbd00(void)

{
  FUN_005bbd20();
  return;
}



