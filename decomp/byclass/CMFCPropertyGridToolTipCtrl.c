/* CMFCPropertyGridToolTipCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCPropertyGridToolTipCtrl[1] */
/* 00829c77  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCPropertyGridToolTipCtrl::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCPropertyGridToolTipCtrl::_scalar_deleting_destructor_
          (CMFCPropertyGridToolTipCtrl *this,uint param_1)

{
  ~CMFCPropertyGridToolTipCtrl(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xa0);
    }
  }
  return this;
}




/* vtable slots: CMFCPropertyGridToolTipCtrl[89] */
/* 00829caa  FUN_00829caa  129 bytes, 0 callers */

void FUN_00829caa(int param_1)

{
  code *pcVar1;
  HCURSOR pHVar2;
  wchar_t *pwVar3;
  int iVar4;
  int *in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  uVar5 = 0x10;
  in_ECX[0x27] = param_1;
  pHVar2 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  pwVar3 = (wchar_t *)AfxRegisterWndClass(0x800,pHVar2,uVar5,uVar6);
  iVar4 = 0;
  if (pwVar3 != (wchar_t *)0x0) {
    iVar4 = FUN_008f899d(pwVar3);
  }
  ATL::CSimpleStringT<wchar_t,0>::SetString((CSimpleStringT<wchar_t,0> *)&DAT_00a13a24,pwVar3,iVar4)
  ;
  pcVar1 = *(code **)(*in_ECX + 0x5c);
  uVar5 = 0;
  if (param_1 != 0) {
    uVar5 = *(undefined4 *)(param_1 + 0x20);
  }
  guard_check_icall(0,DAT_00a13a24,&DAT_00956338,0x80000000,0,0,0,0,uVar5,0,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCPropertyGridToolTipCtrl[10] */
/* 00829d4e  FUN_00829d4e  6 bytes, 0 callers */

undefined ** FUN_00829d4e(void)

{
  return &PTR_FUN_0098fd10;
}




/* vtable slots: CMFCPropertyGridToolTipCtrl[0] */
/* 00829d54  FUN_00829d54  6 bytes, 0 callers */

undefined ** FUN_00829d54(void)

{
  return &PTR_s_CMFCPropertyGridToolTipCtrl_0098fb08;
}




/* vtable slots: CMFCPropertyGridToolTipCtrl[67] */
/* 00829ff1  FUN_00829ff1  138 bytes, 0 callers */

undefined4 FUN_00829ff1(int param_1)

{
  HWND hWndTo;
  undefined4 uVar1;
  CMFCPropertyGridToolTipCtrl *in_ECX;
  tagPOINT local_c;
  
  if (*(int *)(param_1 + 4) - 0x200U < 0xf) {
    if (*(int *)(param_1 + 4) != 0x200) {
      CMFCPropertyGridToolTipCtrl::Hide(in_ECX);
    }
    local_c.x = (LONG)*(ushort *)(param_1 + 0xc);
    local_c.y = (LONG)*(ushort *)(param_1 + 0xe);
    hWndTo = (HWND)0x0;
    if (*(int *)(in_ECX + 0x9c) != 0) {
      hWndTo = *(HWND *)(*(int *)(in_ECX + 0x9c) + 0x20);
    }
    MapWindowPoints(*(HWND *)(in_ECX + 0x20),hWndTo,&local_c,1);
    SendMessageW(*(HWND *)(*(int *)(in_ECX + 0x9c) + 0x20),*(UINT *)(param_1 + 4),
                 *(WPARAM *)(param_1 + 8),CONCAT22((undefined2)local_c.y,(undefined2)local_c.x));
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_007949fb(param_1);
  }
  return uVar1;
}



