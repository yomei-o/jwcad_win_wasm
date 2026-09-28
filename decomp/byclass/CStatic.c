/* CStatic -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CStatic[1] */
/* 00404b30  FUN_00404b30  68 bytes, 0 callers */

ExternalContextBase * FUN_00404b30(uint param_1)

{
  ExternalContextBase *in_ECX;
  
  Concurrency::details::ExternalContextBase::~ExternalContextBase(in_ECX);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x80);
    }
  }
  return in_ECX;
}




/* vtable slots: CStatic[89], CVSListBox[89], CVSListBoxBase[89], CVSToolsListBox[89] */
/* 00798fe6  FUN_00798fe6  52 bytes, 0 callers */

void FUN_00798fe6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"STATIC",param_1,param_2,param_3,param_4,param_5,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CStatic[0] */
/* 0079907b  FUN_0079907b  6 bytes, 0 callers */

undefined ** FUN_0079907b(void)

{
  return &PTR_s_CStatic_0097d1c4;
}



