/* CFukushaDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFukushaDialog[1] */
/* 004acca0  FUN_004acca0  68 bytes, 0 callers */

undefined4 FUN_004acca0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004acbb0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xc90);
    }
  }
  return in_ECX;
}




/* vtable slots: CFukushaDialog[24] */
/* 004ad370  FUN_004ad370  89 bytes, 0 callers */

void FUN_004ad370(void)

{
  int in_ECX;
  
  *(undefined8 *)(in_ECX + 0xe0) = 0;
  *(undefined8 *)(in_ECX + 0xe8) = 0;
  *(undefined8 *)(in_ECX + 0xf0) = 0;
  *(undefined8 *)(in_ECX + 0xf8) = 0;
  *(undefined8 *)(in_ECX + 0x100) = 0;
  FUN_00792313();
  return;
}




/* vtable slots: CFukushaDialog[64] */
/* 004ad3d0  FUN_004ad3d0  404 bytes, 0 callers */

void FUN_004ad3d0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x82c,in_ECX + 0x110);
  FUN_0078fb9c(param_1,0x42e,in_ECX + 400);
  FUN_0078fb9c(param_1,0x47f,in_ECX + 0x210);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x2a8);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x340);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x3d8);
  FUN_0078fb9c(param_1,0x6e3,in_ECX + 0x5c0);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x640);
  FUN_0078fb9c(param_1,0x6d8,in_ECX + 0x788);
  FUN_0078fb9c(param_1,0x585,in_ECX + 0x808);
  FUN_0078fb9c(param_1,0x6e0,in_ECX + 0x9f0);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0xa70);
  FUN_0078fb9c(param_1,0x42d,in_ECX + 0xaf0);
  FUN_0078fb9c(param_1,0x42f,in_ECX + 0xb70);
  FUN_0078fb9c(param_1,0x430,in_ECX + 0xbf0);
  FUN_0078f6f8(param_1,0x82c,in_ECX + 0xc70);
  return;
}




/* vtable slots: CFukushaDialog[10] */
/* 004ad570  FUN_004ad570  16 bytes, 0 callers */

void FUN_004ad570(void)

{
  FUN_004ad580();
  return;
}




/* vtable slots: CFukushaDialog[94] */
/* 004ad900  FUN_004ad900  851 bytes, 0 callers */

undefined4 FUN_004ad900(void)

{
  int in_ECX;
  double local_34;
  double local_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925bc5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00798993(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  FUN_0058b040();
  (**(code **)(*(int *)(in_ECX + 0x640) + 0x17c))();
  if (*(int *)(*(int *)(in_ECX + 0xb8) + 0x85a0) == 0) {
    if (*(double *)(in_ECX + 0xe0) - 1.0 <= 0.0) {
      local_2c = -(*(double *)(in_ECX + 0xe0) - 1.0);
    }
    else {
      local_2c = *(double *)(in_ECX + 0xe0) - 1.0;
    }
    if (local_2c < 1e-07) {
      if (*(double *)(in_ECX + 0xe8) - 1.0 <= 0.0) {
        local_34 = -(*(double *)(in_ECX + 0xe8) - 1.0);
      }
      else {
        local_34 = *(double *)(in_ECX + 0xe8) - 1.0;
      }
      if (local_34 < 1e-07) {
        *(undefined8 *)(in_ECX + 0xe0) = 0;
        *(undefined8 *)(in_ECX + 0xe8) = 0;
      }
    }
    FUN_0058ae50(*(undefined8 *)(in_ECX + 0xe0),*(undefined8 *)(in_ECX + 0xe8));
    (**(code **)(*(int *)(in_ECX + 0x640) + 0x188))(*(undefined8 *)(in_ECX + 0xf0));
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0xb8) + 0x85a0) = 0;
    FUN_0058ae50(*(undefined8 *)(in_ECX + 200),*(undefined8 *)(in_ECX + 0xd0));
    (**(code **)(*(int *)(in_ECX + 0x640) + 0x188))(*(undefined8 *)(in_ECX + 0xd8));
  }
  FUN_0058b040();
  FUN_0058ae50(*(undefined8 *)(in_ECX + 0xf8),*(undefined8 *)(in_ECX + 0x100));
  *(undefined4 *)(in_ECX + 0xbc) = 1;
  FUN_004accf0(0,0);
  if (DAT_00a0cb50 < 1) {
    FUN_004ad590();
  }
  else {
    *(undefined4 *)(in_ECX + 0x108) = 0;
    *(undefined4 *)(in_ECX + 0xc74) = 1;
    *(undefined4 *)(in_ECX + 0xc78) = 0;
    *(undefined4 *)(in_ECX + 0xc7c) = 0;
    FUN_00797f20();
    FUN_005977f0();
    local_8 = 0;
    FUN_00403dd0();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00404770();
    FUN_00404920();
    FUN_00797ece();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CFukushaDialog[67] */
/* 004adde0  FUN_004adde0  965 bytes, 0 callers */

int FUN_004adde0(tagMSG *param_1)

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
      FUN_00406bc0();
      return 1;
    }
    if ((DAT_00a0cb1c != 0) || (DAT_00a0cc74 != 0)) {
      if (param_1->wParam == 0x25) {
        FUN_007955d2(1);
        fVar2 = (float10)FUN_004ae4a0();
        local_14 = (double)fVar2;
        local_34 = local_14;
        if (local_14 <= 0.0) {
          local_34 = -local_14;
        }
        if (local_34 < 1e-07) {
          fVar2 = (float10)FUN_004ae510();
          local_14 = (double)fVar2;
        }
        if (local_14 <= 0.0) {
          local_3c = -local_14;
        }
        else {
          local_3c = local_14;
        }
        FUN_004ae320(-local_3c,0);
        FUN_00406bc0();
        return 1;
      }
      if (param_1->wParam == 0x27) {
        FUN_007955d2(1);
        fVar2 = (float10)FUN_004ae4a0();
        local_1c = (double)fVar2;
        local_44 = local_1c;
        if (local_1c <= 0.0) {
          local_44 = -local_1c;
        }
        if (local_44 < 1e-07) {
          fVar2 = (float10)FUN_004ae510();
          local_1c = (double)fVar2;
        }
        if (local_1c <= 0.0) {
          local_4c = -local_1c;
        }
        else {
          local_4c = local_1c;
        }
        FUN_004ae320(local_4c,0);
        FUN_00406bc0();
        return 1;
      }
      if (param_1->wParam == 0x26) {
        FUN_007955d2(1);
        fVar2 = (float10)FUN_004ae4a0();
        local_24 = (double)fVar2;
        local_54 = local_24;
        if (local_24 <= 0.0) {
          local_54 = -local_24;
        }
        if (local_54 < 1e-07) {
          fVar2 = (float10)FUN_004ae510();
          local_24 = (double)fVar2;
        }
        if (local_24 <= 0.0) {
          local_5c = -local_24;
        }
        else {
          local_5c = local_24;
        }
        FUN_004ae320(0,local_5c);
        FUN_00406bc0();
        return 1;
      }
      if (param_1->wParam == 0x28) {
        FUN_007955d2(1);
        fVar2 = (float10)FUN_004ae4a0();
        local_2c = (double)fVar2;
        local_64 = local_2c;
        if (local_2c <= 0.0) {
          local_64 = -local_2c;
        }
        if (local_64 < 1e-07) {
          fVar2 = (float10)FUN_004ae510();
          local_2c = (double)fVar2;
        }
        if (local_2c <= 0.0) {
          local_6c = -local_2c;
        }
        else {
          local_6c = local_2c;
        }
        FUN_004ae320(0,-local_6c);
        FUN_00406bc0();
        return 1;
      }
    }
  }
  iVar1 = CDialog::PreTranslateMessage(in_ECX,param_1);
  return iVar1;
}



