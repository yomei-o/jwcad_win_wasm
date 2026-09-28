/* CMFCToolBarsMenuPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsMenuPropertyPage[1] */
/* 0089ccd7  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarsMenuPropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarsMenuPropertyPage::_scalar_deleting_destructor_
          (CMFCToolBarsMenuPropertyPage *this,uint param_1)

{
  ~CMFCToolBarsMenuPropertyPage(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x5f8);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarsMenuPropertyPage[64] */
/* 0089cd98  DoDataExchange  285 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsMenuPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCToolBarsMenuPropertyPage::DoDataExchange
          (CMFCToolBarsMenuPropertyPage *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x409f,this + 0xc0);
  FUN_0078fb9c(param_1,0x40f1,this + 0x440);
  FUN_0078fb9c(param_1,0x40f2,this + 0x2c0);
  FUN_0078fb9c(param_1,0x4088,this + 0x340);
  FUN_0078fb9c(param_1,0x4087,this + 0x140);
  FUN_0078fb9c(param_1,0x40ef,this + 0x3c0);
  FUN_0078fb9c(param_1,0x407c,this + 0x1c0);
  FUN_0078fb9c(param_1,0x40ee,this + 0x4c0);
  FUN_0078fb9c(param_1,0x407b,this + 0x240);
  FUN_0078fb9c(param_1,0x40ed,this + 0x540);
  DDX_Text(param_1,0x407a,this + 0x5c0);
  FUN_0078f643(param_1,0x40ee,this + 0x5c4);
  FUN_0078f643(param_1,0x40ed,this + 0x5c8);
  FUN_0078f5ed(param_1,0x40f1,this + 0x5cc);
  FUN_0078f6f8(param_1,0x40f2,this + 0x5d0);
  return;
}




/* vtable slots: CMFCToolBarsMenuPropertyPage[10] */
/* 0089ceb5  FUN_0089ceb5  6 bytes, 0 callers */

undefined ** FUN_0089ceb5(void)

{
  return &PTR_FUN_0099e2f0;
}




/* vtable slots: CMFCToolBarsMenuPropertyPage[0] */
/* 0089cebb  FUN_0089cebb  6 bytes, 0 callers */

undefined ** FUN_0089cebb(void)

{
  return &PTR_s_CMFCToolBarsMenuPropertyPage_0099e06c;
}




/* vtable slots: CMFCToolBarsMenuPropertyPage[94] */
/* 0089cfc7  FUN_0089cfc7  1446 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0089cfc7(void)

{
  undefined4 *puVar1;
  code *pcVar2;
  int *piVar3;
  CWnd *pCVar4;
  CObject *pCVar5;
  int iVar6;
  int *lParam;
  LRESULT LVar7;
  HWND pHVar8;
  uint uVar9;
  int in_ECX;
  WPARAM WVar10;
  UINT in_stack_ffffffb4;
  LPSTR in_stack_ffffffb8;
  int in_stack_ffffffbc;
  undefined1 local_3c [4];
  undefined4 *local_38;
  int *local_20;
  LPARAM local_1c;
  undefined4 *local_18;
  WPARAM local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x89cfd3;
  FUN_00798993();
  iVar6 = *(int *)(in_ECX + 0x5d4);
  local_18 = DAT_00a127ec;
  while (iVar6 == 0) {
    if (local_18 == (undefined4 *)0x0) {
      FUN_007979e8(0);
      FUN_00797a56(0x40f0);
      FUN_007979e8(0);
      iVar6 = FID_conflict_LoadStringA
                        ((HINSTANCE)0x3e87,in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc);
      if (iVar6 == 0) goto LAB_0089d568;
      FUN_007955d2(0);
      goto LAB_0089d3a7;
    }
    puVar1 = (undefined4 *)*local_18;
    pCVar5 = (CObject *)local_18[2];
    local_18 = puVar1;
    if (pCVar5 == (CObject *)0x0) goto LAB_0089d568;
    pCVar4 = CWnd::FromHandlePermanent(*(HWND__ **)(pCVar5 + 0x20));
    if (pCVar4 != (CWnd *)0x0) {
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCMenuBar_00a00b00,pCVar5);
      *(CObject **)(in_ECX + 0x5d4) = pCVar5;
    }
    iVar6 = *(int *)(in_ECX + 0x5d4);
  }
  local_14 = 0xffffffff;
  *(int *)(iVar6 + 0xd88) = in_ECX;
  *(int *)(in_ECX + 0x5e0) = (*(int **)(in_ECX + 0x5d4))[0x353];
  pcVar2 = *(code **)(**(int **)(in_ECX + 0x5d4) + 0x3b0);
  guard_check_icall(0xffffffff);
  (*pcVar2)();
  FUN_0082ba9e(*(undefined4 *)(in_ECX + 0x5e0),*(undefined4 *)(in_ECX + 0x5d4));
  iVar6 = FUN_0079dd6d();
  piVar3 = *(int **)(*(int *)(iVar6 + 4) + 0x5c);
  local_20 = piVar3;
  if ((*(int *)(in_ECX + 0x5f0) != 0) && (piVar3 != (int *)0x0)) {
    pcVar2 = *(code **)(*piVar3 + 0x10);
    guard_check_icall();
    local_18 = (undefined4 *)(*pcVar2)();
joined_r0x0089d0fb:
    if (local_18 != (undefined4 *)0x0) {
      pcVar2 = *(code **)(*piVar3 + 0x14);
      guard_check_icall(&local_18);
      lParam = (int *)(*pcVar2)();
      iVar6 = FUN_0079d98a(&PTR_s_CMultiDocTemplate_0099f534);
      piVar3 = local_20;
      if ((iVar6 != 0) && (lParam[0x22] != 0)) {
        for (WVar10 = 0; LVar7 = SendMessageW(*(HWND *)(in_ECX + 0x560),0x146,0,0),
            (int)WVar10 < LVar7; WVar10 = WVar10 + 1) {
          LVar7 = SendMessageW(*(HWND *)(in_ECX + 0x560),0x150,WVar10,0);
          if ((LVar7 != 0) && (piVar3 = local_20, *(int *)(LVar7 + 0x54) == lParam[0x15]))
          goto joined_r0x0089d0fb;
        }
        CStringT<>();
        local_8 = 0;
        pcVar2 = *(code **)(*lParam + 100);
        guard_check_icall(&local_1c,2);
        (*pcVar2)();
        WVar10 = SendMessageW(*(HWND *)(in_ECX + 0x560),0x143,0,local_1c);
        SendMessageW(*(HWND *)(in_ECX + 0x560),0x151,WVar10,(LPARAM)lParam);
        if (lParam[0x22] == *(int *)(in_ECX + 0x5e0)) {
          local_14 = WVar10;
        }
        local_8 = 0xffffffff;
        FUN_00406b10();
        piVar3 = local_20;
      }
      goto joined_r0x0089d0fb;
    }
  }
  CStringT<>();
  local_8 = 1;
  iVar6 = FID_conflict_LoadStringA
                    ((HINSTANCE)0x3eea,in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc);
  if (iVar6 != 0) {
    WVar10 = SendMessageW(*(HWND *)(in_ECX + 0x560),0x143,0,local_1c);
    SendMessageW(*(HWND *)(in_ECX + 0x560),0x151,WVar10,0);
    if (local_14 == 0xffffffff) {
      *(undefined4 *)(in_ECX + 0x5ec) = 1;
      local_14 = WVar10;
    }
    *(undefined4 *)(in_ECX + 0x5e4) = *(undefined4 *)(in_ECX + 0x5e0);
    SendMessageW(*(HWND *)(in_ECX + 0x560),0x14e,local_14,0);
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,2);
    iVar6 = FID_conflict_LoadStringA
                      ((HINSTANCE)0x42d6,in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc);
    if (iVar6 != 0) {
      SendMessageW(*(HWND *)(in_ECX + 0x460),0x14a,0xffffffff,local_14);
      iVar6 = FID_conflict_LoadStringA
                        ((HINSTANCE)0x42d7,in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc);
      if (iVar6 != 0) {
        SendMessageW(*(HWND *)(in_ECX + 0x460),0x14a,0xffffffff,local_14);
        iVar6 = FID_conflict_LoadStringA
                          ((HINSTANCE)0x42d8,in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc);
        if (iVar6 != 0) {
          SendMessageW(*(HWND *)(in_ECX + 0x460),0x14a,0xffffffff,local_14);
          iVar6 = FID_conflict_LoadStringA
                            ((HINSTANCE)0x42d9,in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc
                            );
          if (iVar6 != 0) {
            SendMessageW(*(HWND *)(in_ECX + 0x460),0x14a,0xffffffff,local_14);
            iVar6 = FID_conflict_LoadStringA
                              ((HINSTANCE)0x42da,in_stack_ffffffb4,in_stack_ffffffb8,
                               in_stack_ffffffbc);
            if (iVar6 != 0) {
              SendMessageW(*(HWND *)(in_ECX + 0x460),0x14a,0xffffffff,local_14);
              if (*(int *)(in_ECX + 0x5cc) == 999) {
                LVar7 = SendMessageW(*(HWND *)(in_ECX + 0x460),0x146,0,0);
                *(LRESULT *)(in_ECX + 0x5cc) = LVar7 + -1;
              }
              FUN_007955d2(0);
              FUN_0089daf4();
              FUN_00406b10();
              FUN_00406b10();
LAB_0089d3a7:
              CStringT<>();
              local_8 = 3;
              iVar6 = FID_conflict_LoadStringA
                                ((HINSTANCE)0x3eec,in_stack_ffffffb4,in_stack_ffffffb8,
                                 in_stack_ffffffbc);
              if (iVar6 != 0) {
                SendMessageW(*(HWND *)(in_ECX + 0x4e0),0x143,0,local_1c);
                SendMessageW(*(HWND *)(in_ECX + 0x4e0),0x14e,0,0);
                local_8 = 0xffffffff;
                FUN_00406b10();
                if (DAT_00a13a20 == 0) {
                  FUN_00797f20(0);
                  FUN_00797f20(0);
                  FUN_00797f20(0);
                  FUN_00797f20(0);
                  FUN_00797f20(0);
                }
                else {
                  FUN_00813876(10);
                  local_8 = 4;
                  FUN_00828e21(local_3c);
                  local_18 = local_38;
                  while (local_18 != (undefined4 *)0x0) {
                    piVar3 = local_18 + 2;
                    local_18 = (undefined4 *)*local_18;
                    iVar6 = FUN_004054a0(*piVar3 + -0x10);
                    SendMessageW(*(HWND *)(in_ECX + 0x4e0),0x143,0,iVar6 + 0x10);
                    FUN_00406b10();
                  }
                  LVar7 = SendMessageW(*(HWND *)(in_ECX + 0x4e0),0x146,0,0);
                  FUN_007979e8(1 < LVar7);
                  LVar7 = SendMessageW(*(HWND *)(in_ECX + 0x4e0),0x146,0,0);
                  FUN_007979e8(1 < LVar7);
                  local_8 = 0xffffffff;
                  FUN_0081389c();
                }
                pHVar8 = GetParent(*(HWND *)(in_ECX + 0x20));
                pCVar4 = CWnd::FromHandle(pHVar8);
                pCVar5 = AfxDynamicDownCast((CRuntimeClass *)
                                            &PTR_s_CMFCToolBarsCustomizeDialog_0099a930,
                                            (CObject *)pCVar4);
                if (pCVar5 != (CObject *)0x0) {
                  uVar9 = *(uint *)(pCVar5 + 0x15c);
                  if ((uVar9 & 1) == 0) {
                    FUN_00797f20(0);
                    uVar9 = *(uint *)(pCVar5 + 0x15c);
                  }
                  if ((uVar9 & 4) == 0) {
                    FUN_00797f20(0);
                    FUN_00797f20(0);
                  }
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0089d568:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



