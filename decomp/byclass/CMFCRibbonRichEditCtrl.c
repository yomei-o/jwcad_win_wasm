/* CMFCRibbonRichEditCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonRichEditCtrl[1] */
/* 0087e2d4  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonRichEditCtrl::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonRichEditCtrl::_scalar_deleting_destructor_(CMFCRibbonRichEditCtrl *this,uint param_1)

{
  ~CMFCRibbonRichEditCtrl(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x98);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonRichEditCtrl[10] */
/* 0087e8e1  FUN_0087e8e1  6 bytes, 0 callers */

undefined ** FUN_0087e8e1(void)

{
  return &PTR_FUN_0099a450;
}




/* vtable slots: CMFCRibbonRichEditCtrl[0] */
/* 0087e901  FUN_0087e901  6 bytes, 0 callers */

undefined ** FUN_0087e901(void)

{
  return &PTR_s_CMFCRibbonRichEditCtrl_0099a04c;
}




/* vtable slots: CMFCRibbonRichEditCtrl[67] */
/* 0087f984  FUN_0087f984  1270 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0087f984(int *param_1)

{
  code *pcVar1;
  SHORT SVar2;
  undefined4 uVar3;
  int iVar4;
  HWND pHVar5;
  CWnd *pCVar6;
  int iVar7;
  int *piVar8;
  CMFCRibbonRichEditCtrl *in_ECX;
  UINT Msg;
  WPARAM wParam;
  undefined1 local_24 [12];
  undefined1 *local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x87f990;
  iVar4 = param_1[1];
  if (iVar4 == 0x14) {
    return 1;
  }
  if (*(int *)(in_ECX + 0x8c) != 0) goto LAB_0087f9ac;
  if (iVar4 == 0x201) {
    local_14 = *(int **)(in_ECX + 0x80);
    if (((local_14[0x79] != 0) && (local_14[0x33] == 0)) && (*param_1 != *(int *)(in_ECX + 0x20))) {
      pcVar1 = *(code **)(*local_14 + 0x224);
      guard_check_icall();
      (*pcVar1)();
      iVar4 = param_1[1];
      goto LAB_0087fa07;
    }
  }
  else {
LAB_0087fa07:
    if (iVar4 == 0x200) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xdc);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) {
        iVar4 = GetSystemMetrics(0x17);
        SVar2 = GetAsyncKeyState((iVar4 != 0) + 1);
        if (SVar2 < 0) {
          pHVar5 = GetFocus();
          pCVar6 = CWnd::FromHandle(pHVar5);
          if (pCVar6 != (CWnd *)in_ECX) {
            return 1;
          }
        }
        if (*(int *)(in_ECX + 0x84) == 0) {
          local_24._8_4_ = *(undefined4 *)(in_ECX + 0x20);
          *(undefined4 *)(in_ECX + 0x84) = 1;
          local_24._0_4_ = 0x10;
          local_24._4_4_ = 2;
          TrackMouseEvent((LPTRACKMOUSEEVENT)local_24);
          RedrawWindow(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
        }
        if (*(int *)(in_ECX + 0x88) == 0) {
          pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xa4);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          if (iVar4 != 0) {
            local_24._8_4_ = (HWND)0x0;
            local_18 = (undefined1 *)0x0;
            GetCursorPos((LPPOINT)(local_24 + 8));
            *(undefined4 *)(in_ECX + 0x88) = 1;
            RedrawWindow(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
            pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xa4);
            guard_check_icall();
            iVar4 = (*pcVar1)();
            ScreenToClient(*(HWND *)(iVar4 + 0x20),(LPPOINT)(local_24 + 8));
            pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xa4);
            guard_check_icall();
            iVar4 = (*pcVar1)();
            SendMessageW(*(HWND *)(iVar4 + 0x20),0x200,0,CONCAT22(local_18._0_2_,local_24._8_2_));
          }
        }
      }
    }
  }
  if (param_1[1] == 0x100) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xdc);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 != 0) goto LAB_0087f9ac;
    iVar4 = CMFCRibbonRichEditCtrl::ProcessClipboardAccelerators(in_ECX,param_1[2]);
    if (iVar4 != 0) {
      return 1;
    }
    iVar4 = param_1[2];
    if (iVar4 == 9) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xd4);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) {
        return 1;
      }
      goto LAB_0087f9ac;
    }
    if (iVar4 != 0xd) {
      if (iVar4 == 0x1b) {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xe4);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if ((iVar4 != 0) && (DAT_00a139c8 != 0)) {
          iVar4 = 0;
          wParam = 0;
          Msg = 0x10;
          pHVar5 = *(HWND *)(DAT_00a139c8 + 0x20);
          goto LAB_0087fc6a;
        }
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xe4);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 == 0) {
          FUN_00797ece();
          local_18 = &stack0xffffffc8;
          FUN_004054a0(*(int *)(in_ECX + 0x90) + -0x10);
          FUN_0088028e();
        }
        iVar4 = FUN_00792b4c();
        if (iVar4 != 0) {
          pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xe4);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          if (iVar4 == 0) {
            FUN_00792b4c();
            FUN_00797df8();
            return 1;
          }
        }
      }
      else {
        if (((iVar4 != 0x21) && (iVar4 != 0x22)) && (iVar4 != 0x26)) {
          if (iVar4 != 0x28) goto LAB_0087f9ac;
          if ((*(int **)(in_ECX + 0x80))[0x77] != 0) {
            pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xe4);
            guard_check_icall();
            iVar4 = (*pcVar1)();
            if (iVar4 == 0) {
              pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0x298);
              guard_check_icall();
              (*pcVar1)();
              return 1;
            }
          }
        }
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xe4);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 != 0) {
          iVar4 = param_1[3];
          wParam = param_1[2];
          pHVar5 = (HWND)0x0;
          if (DAT_00a139c8 != 0) {
            pHVar5 = *(HWND *)(DAT_00a139c8 + 0x20);
          }
          Msg = 0x100;
LAB_0087fc6a:
          SendMessageW(pHVar5,Msg,wParam,iVar4);
          return 1;
        }
      }
      goto LAB_0087f9ac;
    }
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x80) + 0xe4);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 != 0) goto LAB_0087f9ac;
    CStringT<>();
    local_8 = 0;
    FUN_00792c64();
    local_18 = &stack0xffffffc8;
    FUN_004054a0(local_14 + -4);
    FUN_0088028e();
    FUN_00863dc7();
    if (*(int *)(*(int *)(in_ECX + 0x80) + 0x94) != 0) {
      pHVar5 = GetParent(*(HWND *)(*(int *)(*(int *)(in_ECX + 0x80) + 0x94) + 0x20));
      pCVar6 = CWnd::FromHandle(pHVar5);
      if (pCVar6 == (CWnd *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(pCVar6 + 0x20);
      }
      iVar7 = 0;
      if (DAT_00a139c8 != 0) {
        iVar7 = *(int *)(DAT_00a139c8 + 0x20);
      }
      if (iVar4 == iVar7) {
        piVar8 = (int *)FUN_007e5618();
        pcVar1 = *(code **)(*piVar8 + 0x60);
        guard_check_icall();
        (*pcVar1)();
        goto LAB_0087fe2e;
      }
    }
    iVar4 = FUN_00792b4c();
    if (iVar4 != 0) {
      *(undefined4 *)(*(int *)(in_ECX + 0x80) + 0x1e8) = 0;
      FUN_00792b4c();
      FUN_00797df8();
LAB_0087fe2e:
      FUN_00406b10();
      return 1;
    }
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
LAB_0087f9ac:
  uVar3 = FUN_007949fb();
  return uVar3;
}



