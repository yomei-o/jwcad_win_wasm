/* CMFCToolBarButtonCustomizeDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarButtonCustomizeDialog[1] */
/* 0088330d  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarButtonCustomizeDialog::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarButtonCustomizeDialog::_scalar_deleting_destructor_
          (CMFCToolBarButtonCustomizeDialog *this,uint param_1)

{
  FUN_00883215();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x548);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarButtonCustomizeDialog[64] */
/* 00883340  DoDataExchange  177 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarButtonCustomizeDialog::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCToolBarButtonCustomizeDialog::DoDataExchange
          (CMFCToolBarButtonCustomizeDialog *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x4092,this + 0xa8);
  FUN_0078fb9c(param_1,0x4091,this + 0x128);
  FUN_0078fb9c(param_1,0x4093,this + 0x1a8);
  FUN_0078fb9c(param_1,0x4074,this + 0x228);
  FUN_0078fb9c(param_1,0x407d,this + 0x2a8);
  FUN_0078fb9c(param_1,0x407c,this + 0x328);
  FUN_0078fb9c(param_1,0x407e,this + 0x468);
  DDX_Text(param_1,0x4074,this + 0x4e8);
  DDX_Text(param_1,0x40db,this + 0x4ec);
  return;
}




/* vtable slots: CMFCToolBarButtonCustomizeDialog[10] */
/* 00883551  FUN_00883551  6 bytes, 0 callers */

undefined ** FUN_00883551(void)

{
  return &PTR_FUN_0099a928;
}




/* vtable slots: CMFCToolBarButtonCustomizeDialog[94] */
/* 00883b36  FUN_00883b36  711 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00883b36(void)

{
  LPRECT lpRect;
  code *pcVar1;
  int iVar2;
  uint uVar3;
  CSimpleStringT<wchar_t,0> *pCVar4;
  int *piVar5;
  int iVar6;
  int in_ECX;
  HWND hWnd;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x883b42;
  FUN_00798993();
  iVar2 = FUN_00797a56(0x4079);
  if (iVar2 != 0) {
    local_14[0] = FUN_00797a56(0x407b);
    if (local_14[0] != 0) {
      iVar2 = FUN_00404c80();
      if (iVar2 != 0) {
        FUN_00404c80();
        uVar3 = FUN_00797acc();
        if ((uVar3 & 0x400000) != 0) {
          FUN_00797c9f(0,0x400000,0);
        }
      }
      if (*(int *)(in_ECX + 0x4f4) == 0) {
        FUN_007979e8(0);
        FUN_007979e8(0);
        if (*(int *)(in_ECX + 0x4fc) < 0) {
          FUN_007979e8(0);
          FUN_007979e8(0);
        }
      }
      else {
        FUN_008c7ad2(*(int *)(in_ECX + 0x4f4));
        FUN_0088411a();
        FUN_008c7a62(*(undefined4 *)(in_ECX + 0x4fc));
      }
      if ((*(int *)(in_ECX + 0x50c) == 0) || (*(int *)(*(int *)(in_ECX + 0x4f0) + 0x3c) != 0)) {
        hWnd = *(HWND *)(in_ECX + 200);
      }
      else {
        hWnd = *(HWND *)(in_ECX + 0x148);
      }
      SendMessageW(hWnd,0xf1,1,0);
      if (*(int *)(in_ECX + 0x500) == 0) {
        if (*(int *)(in_ECX + 0x504) == 0) goto LAB_00883df8;
        FUN_007979ae(0x407a,1);
        *(undefined4 *)(in_ECX + 0x504) = 1;
        FUN_007979e8(0);
      }
      else {
        FUN_007979ae((uint)(*(int *)(in_ECX + 0x504) != 0) * 2 + 0x4079,1);
      }
      iVar2 = FUN_0044e690(9,0);
      if (iVar2 < 0) {
        ATL::CSimpleStringT<wchar_t,0>::operator=
                  ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x4e8),
                   (CSimpleStringT<wchar_t,0> *)(*(int *)(in_ECX + 0x4f0) + 0x2c));
      }
      else {
        pCVar4 = (CSimpleStringT<wchar_t,0> *)Left(local_14,iVar2);
        local_8 = 0;
        ATL::CSimpleStringT<wchar_t,0>::operator=
                  ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x4e8),pCVar4);
        local_8 = 0xffffffff;
        FUN_00406b10();
        FUN_00450000(local_14,iVar2 + 1,
                     *(int *)(*(int *)(*(int *)(in_ECX + 0x4f0) + 0x2c) + -0xc) - (iVar2 + 1));
        local_8 = 1;
        ATL::CSimpleStringT<wchar_t,0>::operator=
                  ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x53c),
                   (CSimpleStringT<wchar_t,0> *)local_14);
        local_8 = 0xffffffff;
        FUN_00406b10();
      }
      piVar5 = (int *)FUN_0079296c();
      if (piVar5 != (int *)0x0) {
        pcVar1 = *(code **)(*piVar5 + 0x174);
        guard_check_icall(*(undefined4 *)(*(int *)(in_ECX + 0x4f0) + 0x20),in_ECX + 0x4ec);
        (*pcVar1)();
      }
      if (*(int *)(in_ECX + 0x508) != 0) {
        FUN_007979e8(0);
      }
      if (*(int *)(*(int *)(in_ECX + 0x4f0) + 0x18) != 0) {
        FUN_007979e8(0);
      }
      lpRect = (LPRECT)(in_ECX + 0x52c);
      GetClientRect(*(HWND *)(in_ECX + 0x1c8),lpRect);
      MapWindowPoints(*(HWND *)(in_ECX + 0x1c8),*(HWND *)(in_ECX + 0x20),(LPPOINT)lpRect,2);
      iVar2 = 0x10;
      if (DAT_00a128d4 < 0x11) {
        iVar2 = DAT_00a128d4;
      }
      iVar6 = 0x10;
      if (DAT_00a128d8 < 0x11) {
        iVar6 = DAT_00a128d8;
      }
      *(LONG *)(in_ECX + 0x534) = lpRect->left + iVar2;
      *(int *)(in_ECX + 0x538) = *(int *)(in_ECX + 0x530) + iVar6;
      FUN_008833f1();
      FUN_007955d2(0);
      return 1;
    }
  }
LAB_00883df8:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCToolBarButtonCustomizeDialog[96] */
/* 00883dfe  FUN_00883dfe  420 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00883dfe(void)

{
  code *pcVar1;
  int in_ECX;
  int iVar2;
  UINT uID;
  LPSTR in_stack_ffffffdc;
  int in_stack_ffffffe0;
  undefined4 local_14;
  
  uID = 1;
  FUN_007955d2();
  iVar2 = *(int *)(in_ECX + 0x4fc);
  if (*(int *)(in_ECX + 0x50c) == 0) {
    if (*(int *)(in_ECX + 0x540) == 0) {
      iVar2 = FUN_00881280(*(undefined4 *)(*(int *)(in_ECX + 0x4f0) + 0x20));
    }
    else {
      iVar2 = 0;
    }
  }
  if ((*(int *)(in_ECX + 0x500) == 0) || (-1 < iVar2)) {
    if ((*(int *)(in_ECX + 0x504) == 0) || (*(int *)(*(int *)(in_ECX + 0x4e8) + -0xc) != 0)) {
      if (*(int *)(*(int *)(in_ECX + 0x4f0) + 0x18) == 0) {
        *(int *)(*(int *)(in_ECX + 0x4f0) + 8) = *(int *)(in_ECX + 0x504);
      }
      if (*(int *)(in_ECX + 0x508) == 0) {
        *(undefined4 *)(*(int *)(in_ECX + 0x4f0) + 0xc) = *(undefined4 *)(in_ECX + 0x500);
      }
      else {
        FUN_0082be6d();
        FUN_0082bdca(*(undefined4 *)(*(int *)(in_ECX + 0x4f0) + 0x20),
                     *(undefined4 *)(in_ECX + 0x500),iVar2);
      }
      *(undefined4 *)(*(int *)(in_ECX + 0x4f0) + 4) = *(undefined4 *)(in_ECX + 0x50c);
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x4f0) + 0xc0);
      guard_check_icall(iVar2);
      (*pcVar1)();
      ATL::CSimpleStringT<wchar_t,0>::operator=
                ((CSimpleStringT<wchar_t,0> *)(*(int *)(in_ECX + 0x4f0) + 0x2c),
                 (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x4e8));
      if (*(int *)(*(int *)(in_ECX + 0x53c) + -0xc) != 0) {
        ATL::CSimpleStringT<wchar_t,0>::AppendChar
                  ((CSimpleStringT<wchar_t,0> *)(*(int *)(in_ECX + 0x4f0) + 0x2c),L'\t');
        FUN_00404cf0(*(int *)(in_ECX + 0x53c),*(undefined4 *)(*(int *)(in_ECX + 0x53c) + -0xc));
      }
      FUN_00798a09();
      return;
    }
    CStringT<>();
    iVar2 = FID_conflict_LoadStringA((HINSTANCE)0x3e82,uID,in_stack_ffffffdc,in_stack_ffffffe0);
    if (iVar2 == 0) goto LAB_00883f9d;
    FUN_0079f557(local_14,0,0);
  }
  else {
    CStringT<>();
    iVar2 = FID_conflict_LoadStringA((HINSTANCE)0x3e81,uID,in_stack_ffffffdc,in_stack_ffffffe0);
    if (iVar2 == 0) {
LAB_00883f9d:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    FUN_0079f557(local_14,0,0);
  }
  FUN_00797df8();
  FUN_00406b10();
  return;
}



