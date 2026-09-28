/* CFukushaZokuseiHenDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFukushaZokuseiHenDialog[1] */
/* 004ae800  FUN_004ae800  68 bytes, 0 callers */

undefined4 FUN_004ae800(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004ae780();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x470);
    }
  }
  return in_ECX;
}




/* vtable slots: CFukushaZokuseiHenDialog[24] */
/* 004ae850  FUN_004ae850  124 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004ae850(void)

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
    FUN_00517510(&DAT_00a0c164,local_18,local_14,local_10,local_c);
  }
  DAT_00a0cc8c = 0;
  FUN_00792313();
  return;
}




/* vtable slots: CFukushaZokuseiHenDialog[64] */
/* 004ae8d0  FUN_004ae8d0  794 bytes, 0 callers */

void FUN_004ae8d0(undefined4 param_1)

{
  uint uID;
  int iVar1;
  undefined4 uVar2;
  LPSTR in_stack_ffffffe8;
  int extraout_var;
  int cchBufferMax;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925c7d;
  local_10 = ExceptionList;
  uID = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00405880(param_1);
  cchBufferMax = extraout_var;
  FUN_0078fb9c(param_1,0x9fc,extraout_var + 0xc0);
  FUN_0078fb9c(param_1,0x52a,cchBufferMax + 0x140);
  FUN_0078f6f8(param_1,0x52a,cchBufferMax + 0x1c0);
  FUN_0078fb9c(param_1,0x842,cchBufferMax + 0x1c8);
  FUN_0078f6f8(param_1,0x842,cchBufferMax + 0x248);
  FUN_0078fb9c(param_1,0x52e,cchBufferMax + 0x250);
  FUN_0078fb9c(param_1,0x52d,cchBufferMax + 0x2d0);
  FUN_0078fb9c(param_1,0x428,cchBufferMax + 0x350);
  FUN_0078f6f8(param_1,0x52b,cchBufferMax + 0x3d0);
  FUN_0078f6f8(param_1,0x52c,cchBufferMax + 0x3d4);
  FUN_0078f6f8(param_1,0x52d,cchBufferMax + 0x3d8);
  FUN_0078f6f8(param_1,0x52e,cchBufferMax + 0x3dc);
  FUN_0078fb9c(param_1,0x530,cchBufferMax + 0x3e0);
  FUN_0078f6f8(param_1,0x530,cchBufferMax + 0x460);
  FUN_0078f6f8(param_1,0x8ca,cchBufferMax + 0x464);
  FUN_0078f6f8(param_1,0x9fc,cchBufferMax + 0x468);
  if (*(int *)(cchBufferMax + 0xa8) != 0) {
    *(undefined4 *)(cchBufferMax + 0xa8) = 0;
    if (*(int *)(cchBufferMax + 0xac) == 0) {
      FUN_007979e8(0);
    }
    if (*(int *)(cchBufferMax + 0xb0) == 0) {
      FUN_007979e8(0);
    }
    if (*(int *)(cchBufferMax + 0xb4) != 0) {
      CStringT<>();
      local_8 = 0;
      iVar1 = FID_conflict_LoadStringA((HINSTANCE)0x17fd,uID,in_stack_ffffffe8,cchBufferMax);
      if (iVar1 == 0) {
        ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::operator=
                  ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                   &stack0xffffffe8,"");
      }
      uVar2 = FUN_00404920();
      FUN_00797ece(uVar2);
      iVar1 = FID_conflict_LoadStringA((HINSTANCE)0x17fe,uID,in_stack_ffffffe8,cchBufferMax);
      if (iVar1 == 0) {
        ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::operator=
                  ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                   &stack0xffffffe8,"");
      }
      uVar2 = FUN_00404920();
      FUN_00797ece(uVar2);
      iVar1 = FID_conflict_LoadStringA((HINSTANCE)0x182c,uID,in_stack_ffffffe8,cchBufferMax);
      if (iVar1 == 0) {
        ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::operator=
                  ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                   &stack0xffffffe8,"");
      }
      uVar2 = FUN_00404920();
      FUN_00797ece(uVar2);
      local_8 = 0xffffffff;
      FUN_00404540();
    }
    if (*(int *)(cchBufferMax + 0xb4) < 0) {
      FUN_00797f20(0);
    }
    if (*(int *)(cchBufferMax + 0xb8) == 0) {
      FUN_00797f20(0);
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CFukushaZokuseiHenDialog[10] */
/* 004aebf0  FUN_004aebf0  16 bytes, 0 callers */

void FUN_004aebf0(void)

{
  FUN_004aec00();
  return;
}




/* vtable slots: CFukushaZokuseiHenDialog[94] */
/* 004aecf0  FUN_004aecf0  194 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004aecf0(void)

{
  int iVar1;
  int local_24;
  int local_20;
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
  iVar1 = FUN_00517b40(DAT_00a0c164,DAT_00a0c168,local_18,local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_24 + 0x80,local_20 + 0x50);
  }
  return 1;
}



