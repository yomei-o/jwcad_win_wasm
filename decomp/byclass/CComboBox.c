/* CComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CComboBox[1] */
/* 004140d0  FUN_004140d0  68 bytes, 1 callers */

ExternalContextBase * FUN_004140d0(uint param_1)

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




/* vtable slots: CComboBox[89], CFontComboBox[89], CLocalComboBox[89], CMFCFontComboBox[89], CMy02ComboBox[89], CMy0ComboBox[89], CMy2ComboBox[89], CMy2ComboBox1[89], CMyComboBox[89] */
/* 00798f1a  FUN_00798f1a  51 bytes, 1 callers */

void FUN_00798f1a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"COMBOBOX",0,param_1,param_2,param_3,param_4,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CComboBox[0], CFontComboBox[0], CLocalComboBox[0], CMFCFontComboBox[0], CMy02ComboBox[0], CMy0ComboBox[0], CMy2ComboBox[0], CMy2ComboBox1[0], CMyComboBox[0] */
/* 00799063  FUN_00799063  6 bytes, 0 callers */

undefined ** FUN_00799063(void)

{
  return &PTR_s_CComboBox_0097d39c;
}




/* vtable slots: CComboBox[73], CFontComboBox[73], CLocalComboBox[73], CMFCFontComboBox[73], CMy02ComboBox[73], CMy0ComboBox[73], CMy2ComboBox[73], CMy2ComboBox1[73], CMyComboBox[73] */
/* 00799104  FUN_00799104  131 bytes, 0 callers */

int FUN_00799104(uint param_1,uint param_2,long param_3,long *param_4)

{
  int iVar1;
  long lVar2;
  CWnd *in_ECX;
  code *pcVar3;
  
  if (param_1 == 0x2b) {
    pcVar3 = *(code **)(*(int *)in_ECX + 0x168);
  }
  else if (param_1 == 0x2c) {
    pcVar3 = *(code **)(*(int *)in_ECX + 0x16c);
  }
  else {
    if (param_1 != 0x2d) {
      if (param_1 == 0x39) {
        pcVar3 = *(code **)(*(int *)in_ECX + 0x170);
        guard_check_icall(param_3);
        lVar2 = (*pcVar3)();
        *param_4 = lVar2;
        return 1;
      }
      iVar1 = CWnd::OnChildNotify(in_ECX,param_1,param_2,param_3,param_4);
      return iVar1;
    }
    pcVar3 = *(code **)(*(int *)in_ECX + 0x174);
  }
  guard_check_icall(param_3);
  (*pcVar3)();
  return 1;
}



