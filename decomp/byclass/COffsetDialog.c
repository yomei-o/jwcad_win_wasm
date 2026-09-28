/* COffsetDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COffsetDialog[1] */
/* 0059ed20  FUN_0059ed20  68 bytes, 0 callers */

undefined4 FUN_0059ed20(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0059ecd0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x438);
    }
  }
  return in_ECX;
}




/* vtable slots: COffsetDialog[64] */
/* 0059ed70  FUN_0059ed70  117 bytes, 0 callers */

void FUN_0059ed70(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,1,in_ECX + 0xb8);
  FUN_0078fb9c(param_1,0x788,in_ECX + 800);
  FUN_0078fb9c(param_1,0x9d7,in_ECX + 0x3a0);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x138);
  return;
}




/* vtable slots: COffsetDialog[10] */
/* 0059edf0  FUN_0059edf0  16 bytes, 0 callers */

void FUN_0059edf0(void)

{
  FUN_0059ee00();
  return;
}




/* vtable slots: COffsetDialog[94] */
/* 0059ee60  FUN_0059ee60  231 bytes, 0 callers */

undefined4 FUN_0059ee60(void)

{
  int in_ECX;
  
  FUN_00798993();
  if (-0x2a88 < DAT_00a0c19c) {
    FUN_00797e71(0,DAT_00a0c19c,DAT_00a0c1a0,0,0,5);
  }
  FUN_0058b040();
  FUN_0058ae50(*(undefined8 *)(in_ECX + 0x420),*(undefined8 *)(in_ECX + 0x428));
  FUN_00517410();
  if (*(int *)(in_ECX + 0xac) == 0) {
    FUN_00797f20();
  }
  else {
    FUN_00797f20();
  }
  if (*(int *)(in_ECX + 0x430) == 0) {
    FUN_00797f20();
  }
  else {
    FUN_00797f20();
  }
  return 1;
}




/* vtable slots: COffsetDialog[96] */
/* 0059f0c0  FUN_0059f0c0  236 bytes, 0 callers */

void FUN_0059f0c0(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)FUN_0058b290();
  *(double *)(in_ECX + 0x420) = (double)fVar1;
  fVar1 = (float10)(**(code **)(*(int *)(in_ECX + 0x138) + 0x178))();
  *(double *)(in_ECX + 0x428) = (double)fVar1;
  if (*(int *)(in_ECX + 0x430) != 0) {
    *(double *)(in_ECX + 0x420) = *(double *)(in_ECX + 0x420) * 1000.0;
    *(double *)(in_ECX + 0x428) = *(double *)(in_ECX + 0x428) * 1000.0;
    if (DAT_00a0d62c != 0) {
      *(double *)(in_ECX + 0x420) = *(double *)(in_ECX + 0x420) / DAT_00a0d630;
      *(double *)(in_ECX + 0x428) = *(double *)(in_ECX + 0x428) / DAT_00a0d630;
    }
  }
  FUN_0058b070();
  FUN_00798a09();
  return;
}




/* vtable slots: COffsetDialog[67] */
/* 0059f270  FUN_0059f270  1116 bytes, 0 callers */

int FUN_0059f270(tagMSG *param_1)

{
  int iVar1;
  CDialog *in_ECX;
  float10 fVar2;
  double local_6c;
  double local_64;
  double local_5c;
  double local_54;
  double local_4c;
  double local_44;
  double local_3c;
  double local_34;
  double local_2c;
  double local_24;
  double local_1c;
  double local_14;
  
  if (param_1->message == 0x100) {
    FUN_00404c80();
    FUN_00799e17();
    if (param_1->wParam == 0xd) {
      FUN_007955d2(1);
      (**(code **)(*(int *)in_ECX + 0x180))();
      return 1;
    }
    if (param_1->wParam == 0x11) {
      iVar1 = CDialog::PreTranslateMessage(in_ECX,param_1);
      return iVar1;
    }
    if ((DAT_00a0cc74 != 0) || (DAT_00a0cb1c != 0)) {
      DAT_00a0cc74 = 0;
      if (param_1->wParam == 0x25) {
        FUN_007955d2(1);
        fVar2 = (float10)FUN_0058b290();
        local_14 = (double)fVar2;
        local_34 = local_14;
        if (local_14 <= 0.0) {
          local_34 = -local_14;
        }
        if (local_34 < 1e-07) {
          fVar2 = (float10)(**(code **)(*(int *)(in_ECX + 0x138) + 0x178))();
          local_14 = (double)fVar2;
        }
        if (local_14 <= 0.0) {
          local_3c = -local_14;
        }
        else {
          local_3c = local_14;
        }
        FUN_0058ae50(-local_3c,0);
        (**(code **)(*(int *)in_ECX + 0x180))();
        return 1;
      }
      if (param_1->wParam == 0x27) {
        FUN_007955d2(1);
        fVar2 = (float10)FUN_0058b290();
        local_1c = (double)fVar2;
        local_44 = local_1c;
        if (local_1c <= 0.0) {
          local_44 = -local_1c;
        }
        if (local_44 < 1e-07) {
          fVar2 = (float10)(**(code **)(*(int *)(in_ECX + 0x138) + 0x178))();
          local_1c = (double)fVar2;
        }
        if (local_1c <= 0.0) {
          local_4c = -local_1c;
        }
        else {
          local_4c = local_1c;
        }
        FUN_0058ae50(local_4c,0);
        (**(code **)(*(int *)in_ECX + 0x180))();
        return 1;
      }
      if (param_1->wParam == 0x26) {
        FUN_007955d2(1);
        fVar2 = (float10)FUN_0058b290();
        local_24 = (double)fVar2;
        local_54 = local_24;
        if (local_24 <= 0.0) {
          local_54 = -local_24;
        }
        if (local_54 < 1e-07) {
          fVar2 = (float10)(**(code **)(*(int *)(in_ECX + 0x138) + 0x178))();
          local_24 = (double)fVar2;
        }
        if (local_24 <= 0.0) {
          local_5c = -local_24;
        }
        else {
          local_5c = local_24;
        }
        FUN_0058ae50(0,local_5c);
        (**(code **)(*(int *)in_ECX + 0x180))();
        return 1;
      }
      if (param_1->wParam == 0x28) {
        FUN_007955d2(1);
        fVar2 = (float10)FUN_0058b290();
        local_2c = (double)fVar2;
        local_64 = local_2c;
        if (local_2c <= 0.0) {
          local_64 = -local_2c;
        }
        if (local_64 < 1e-07) {
          fVar2 = (float10)(**(code **)(*(int *)(in_ECX + 0x138) + 0x178))();
          local_2c = (double)fVar2;
        }
        if (local_2c <= 0.0) {
          local_6c = -local_2c;
        }
        else {
          local_6c = local_2c;
        }
        FUN_0058ae50(0,-local_6c);
        (**(code **)(*(int *)in_ECX + 0x180))();
        return 1;
      }
    }
  }
  iVar1 = CDialog::PreTranslateMessage(in_ECX,param_1);
  return iVar1;
}



