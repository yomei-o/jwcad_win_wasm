/* CFileDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFileDialog[1] */
/* 007b3915  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CFileDialog::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CFileDialog::_scalar_deleting_destructor_(CFileDialog *this,uint param_1)

{
  FUN_007b384d();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x4e8);
    }
  }
  return this;
}




/* vtable slots: CFileDialog[93] */
/* 007b3f8f  FUN_007b3f8f  343 bytes, 20 callers */

int FUN_007b3f8f(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  HWND hWnd;
  HWND__ *pHVar4;
  BOOL BVar5;
  _AFX_THREAD_STATE *p_Var6;
  CDialog *in_ECX;
  
  iVar3 = FUN_008f899d(*(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x1c));
  _memset((void *)(*(int *)(*(int *)(in_ECX + 0xa8) + 0x1c) + (iVar3 + 1) * 2),0,
          (*(int *)(*(int *)(in_ECX + 0xa8) + 0x20) - (iVar3 + 1)) * 2);
  hWnd = GetFocus();
  bVar2 = false;
  pHVar4 = CDialog::PreModal(in_ECX);
  *(HWND__ **)(*(int *)(in_ECX + 0xa8) + 4) = pHVar4;
  FUN_0079134d();
  if ((*(int *)(*(int *)(in_ECX + 0xa8) + 4) != 0) &&
     (BVar5 = IsWindowEnabled(*(HWND *)(*(int *)(in_ECX + 0xa8) + 4)), BVar5 != 0)) {
    bVar2 = true;
    EnableWindow(*(HWND *)(*(int *)(in_ECX + 0xa8) + 4),0);
  }
  p_Var6 = AfxGetThreadState();
  if ((*(int *)(in_ECX + 0xac) == 1) || ((*(uint *)(*(int *)(in_ECX + 0xa8) + 0x34) & 0x80000) == 0)
     ) {
    FUN_00790fd2(in_ECX);
  }
  else {
    *(CDialog **)(p_Var6 + 0x18) = in_ECX;
  }
  if (*(int *)(in_ECX + 0xac) == 1) {
    FUN_007b39ac();
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xbc) + 0xc);
    guard_check_icall(*(int **)(in_ECX + 0xbc),*(undefined4 *)(*(int *)(in_ECX + 0xa8) + 4));
    iVar3 = (*pcVar1)();
    iVar3 = (iVar3 != 0) + 1;
  }
  else if (*(int *)(in_ECX + 0xc4) == 0) {
    iVar3 = FUN_007b50c6(*(undefined4 *)(in_ECX + 0xa8));
  }
  else {
    iVar3 = FUN_007b4ffe(*(undefined4 *)(in_ECX + 0xa8));
  }
  *(undefined4 *)(p_Var6 + 0x18) = 0;
  if (bVar2) {
    EnableWindow(*(HWND *)(*(int *)(in_ECX + 0xa8) + 4),1);
  }
  BVar5 = IsWindow(hWnd);
  if (BVar5 != 0) {
    SetFocus(hWnd);
  }
  CDialog::PostModal(in_ECX);
  if (iVar3 == 0) {
    iVar3 = 2;
  }
  return iVar3;
}




/* vtable slots: CFileDialog[14] */
/* 007b4277  FUN_007b4277  6 bytes, 0 callers */

undefined ** FUN_007b4277(void)

{
  return &PTR_DAT_00980acc;
}




/* vtable slots: CFileDialog[0] */
/* 007b44ea  FUN_007b44ea  6 bytes, 0 callers */

undefined ** FUN_007b44ea(void)

{
  return &PTR_s_CFileDialog_00980ab0;
}




/* vtable slots: CFileDialog[103] */
/* 007b46b3  FUN_007b46b3  25 bytes, 0 callers */

void FUN_007b46b3(void)

{
  HWND pHVar1;
  int in_ECX;
  
  pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
  CWnd::FromHandle(pHVar1);
  FUN_00791d1f(0);
  return;
}




/* vtable slots: CFileDialog[102], CFrameWndEx[122], CMDIFrameWndEx[129], CMFCAutoHideBar[191], CMFCBaseToolBar[191], CMFCCaptionBar[191], CMFCOutlookBarPane[261], COleDocIPFrameWndEx[129], COleIPFrameWndEx[129], CPane[191] */
/* 007b4715  FUN_007b4715  3 bytes, 0 callers */

void FUN_007b4715(void)

{
  return;
}




/* vtable slots: CFileDialog[62] */
/* 007b4718  FUN_007b4718  254 bytes, 0 callers */

undefined4 FUN_007b4718(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  LRESULT LVar3;
  int *in_ECX;
  code *pcVar4;
  
  iVar1 = FUN_00793ba8(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 == -0x25f) {
    pcVar4 = *(code **)(*in_ECX + 0x1a8);
LAB_007b4800:
    guard_check_icall();
    (*pcVar4)();
  }
  else {
    if (iVar1 == -0x25e) {
      pcVar4 = *(code **)(*in_ECX + 0x194);
      guard_check_icall();
      uVar2 = (*pcVar4)();
    }
    else {
      if (iVar1 == -0x25d) {
        LVar3 = SendMessageW((HWND)in_ECX[8],0x111,0xe146,0);
        if (LVar3 != 0) {
          return 1;
        }
        SendMessageW((HWND)in_ECX[8],0x365,0,0);
        return 1;
      }
      if (iVar1 != -0x25c) {
        if (iVar1 == -0x25b) {
          pcVar4 = *(code **)(*in_ECX + 0x1a4);
        }
        else if (iVar1 == -0x25a) {
          pcVar4 = *(code **)(*in_ECX + 0x1a0);
        }
        else {
          if (iVar1 != -0x259) {
            return 0;
          }
          pcVar4 = *(code **)(*in_ECX + 0x19c);
        }
        goto LAB_007b4800;
      }
      pcVar4 = *(code **)(*in_ECX + 400);
      guard_check_icall(*(undefined4 *)(param_2 + 0x10));
      uVar2 = (*pcVar4)();
    }
    *param_3 = uVar2;
  }
  return 1;
}




/* vtable slots: CFileDialog[99] */
/* 007b4a82  FUN_007b4a82  1404 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_007b4a82(void)

{
  code *pcVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  LPWSTR pWVar7;
  undefined1 *puVar8;
  int in_ECX;
  uint uVar9;
  int local_40;
  LPWSTR local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  LPCWSTR local_20;
  undefined2 *local_1c;
  LPWSTR local_18;
  LPWSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x7b4a8e;
  if (*(int *)(in_ECX + 0xac) != 1) {
    return &LAB_009453fa;
  }
  pcVar1 = *(code **)(**(int **)(in_ECX + 0xbc) + 0x50);
  guard_check_icall(*(int **)(in_ECX + 0xbc),&local_28);
  iVar4 = (*pcVar1)();
  if (iVar4 < 0) {
    if ((*(uint *)(*(int *)(in_ECX + 0xa8) + 0x34) & 0x200) == 0) goto LAB_007b4f36;
    local_34 = (int *)0x0;
    pcVar1 = *(code **)**(undefined4 **)(in_ECX + 0xbc);
    guard_check_icall(*(undefined4 **)(in_ECX + 0xbc),&DAT_00980d04,&local_34);
    iVar4 = (*pcVar1)();
    if (iVar4 < 0) goto LAB_007b4f36;
    local_30 = (int *)0x0;
    pcVar1 = *(code **)(*local_34 + 0x6c);
    guard_check_icall(local_34,&local_30);
    iVar4 = (*pcVar1)();
    local_28 = local_34;
    if (-1 < iVar4) {
      pcVar1 = *(code **)(*local_30 + 0x24);
      guard_check_icall(local_30,&local_2c);
      iVar4 = (*pcVar1)();
      if (-1 < iVar4) {
        local_40 = 0;
        pcVar1 = *(code **)(*local_2c + 0xc);
        guard_check_icall(local_2c,1,&local_24,&local_40);
        iVar4 = (*pcVar1)();
        if (iVar4 == 0) {
          CStringT<>();
          local_8 = 1;
          local_1c = *(undefined2 **)(*(int *)(in_ECX + 0xa8) + 0x1c);
          local_14[0] = (LPWSTR)0x0;
          pcVar1 = *(code **)(*local_24 + 0x14);
          guard_check_icall(local_24,0x80058000,local_14);
          iVar4 = (*pcVar1)();
          pWVar7 = local_18;
          if (-1 < iVar4) {
            PathRemoveFileSpecW(local_14[0]);
            puVar3 = local_1c;
            FUN_008f8e5e(local_1c,*(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x20),local_14[0],
                         0xffffffff);
            if (local_14[0] == (LPWSTR)0x0) {
              iVar4 = 0;
            }
            else {
              iVar4 = FUN_008f899d(local_14[0]);
            }
            local_1c = puVar3 + iVar4 + 1;
            CoTaskMemFree(local_14[0]);
            pWVar7 = local_18;
          }
          do {
            local_14[0] = (LPWSTR)0x0;
            pcVar1 = *(code **)(*local_24 + 0x14);
            guard_check_icall(local_24,0x80058000,local_14);
            iVar4 = (*pcVar1)();
            if (-1 < iVar4) {
              local_3c = local_14[0];
              if ((local_14[0] == (LPWSTR)0x0) ||
                 (local_38 = FUN_008f899d(local_14[0]), local_38 == 0)) {
                Empty();
                pWVar7 = local_18;
              }
              else {
                uVar2 = *(uint *)(pWVar7 + -6);
                uVar9 = (int)local_3c - (int)pWVar7 >> 1;
                pwVar6 = (wchar_t *)
                         ATL::CSimpleStringT<char,0>::PrepareWrite
                                   ((CSimpleStringT<char,0> *)&local_18,local_38);
                pWVar7 = local_18;
                iVar4 = local_38;
                if (uVar2 < uVar9) {
                  _memcpy_s(pwVar6,*(int *)(local_18 + -4) * 2,local_3c,local_38 * 2);
                }
                else {
                  ATL::CSimpleStringT<wchar_t,0>::CopyCharsOverlapped
                            (pwVar6,*(uint *)(local_18 + -4),pwVar6 + uVar9,local_38);
                }
                FUN_00406c20(iVar4);
              }
              if (1 < *(int *)(pWVar7 + -2)) {
                FUN_00405930(*(int *)(pWVar7 + -6));
                pWVar7 = local_18;
              }
              PathRemoveFileSpecW(pWVar7);
              ReleaseBuffer(0xffffffff);
              puVar3 = local_1c;
              local_3c = *(LPWSTR *)(pWVar7 + -6);
              if (local_14[0][(int)local_3c] == L'\\') {
                local_3c = (LPWSTR)((int)local_3c + 1);
              }
              FUN_008f8e5e(local_1c,(*(int *)(*(int *)(in_ECX + 0xa8) + 0x20) -
                                    ((int)local_1c - *(int *)(*(int *)(in_ECX + 0xa8) + 0x1c) >> 1))
                                    + -1,local_14[0] + (int)local_3c,0xffffffff);
              iVar4 = 0;
              if (local_14[0] + (int)local_3c != (LPWSTR)0x0) {
                iVar4 = FUN_008f899d(local_14[0] + (int)local_3c);
              }
              local_1c = puVar3 + iVar4 + 1;
              CoTaskMemFree(local_14[0]);
            }
            pcVar1 = *(code **)(*local_24 + 8);
            guard_check_icall(local_24);
            (*pcVar1)();
            iVar4 = *(int *)(in_ECX + 0xa8);
            if ((undefined2 *)(*(int *)(iVar4 + 0x1c) + *(int *)(iVar4 + 0x20) * 2 + -2) <= local_1c
               ) goto LAB_007b4ebe;
            pcVar1 = *(code **)(*local_2c + 0xc);
            guard_check_icall(local_2c,1,&local_24,&local_40);
            iVar4 = (*pcVar1)();
          } while (iVar4 == 0);
          iVar4 = *(int *)(in_ECX + 0xa8);
LAB_007b4ebe:
          if (local_1c < (undefined2 *)(*(int *)(iVar4 + 0x1c) + (*(int *)(iVar4 + 0x20) + -1) * 2))
          {
            *local_1c = 0;
          }
          else {
            *(undefined2 *)(*(int *)(iVar4 + 0x1c) + -4 + *(int *)(iVar4 + 0x20) * 2) = 0;
            *(undefined2 *)
             (*(int *)(*(int *)(in_ECX + 0xa8) + 0x1c) + -2 +
             *(int *)(*(int *)(in_ECX + 0xa8) + 0x20) * 2) = 0;
          }
          local_8 = 0xffffffff;
          FUN_00406b10();
        }
        pcVar1 = *(code **)(*local_2c + 8);
        guard_check_icall(local_2c);
        (*pcVar1)();
      }
      pcVar1 = *(code **)(*local_30 + 8);
      guard_check_icall(local_30);
      (*pcVar1)();
      local_28 = local_34;
    }
  }
  else {
    local_34 = (int *)FUN_007b4213();
    if (local_34 != (int *)0x0) {
      local_18 = (LPWSTR)0x0;
      pcVar1 = *(code **)(*local_34 + 0x78);
      guard_check_icall(local_34,&local_18);
      iVar4 = (*pcVar1)();
      if (-1 < iVar4) {
        pcVar1 = *(code **)(*local_34 + 0x7c);
        guard_check_icall(local_34,local_28,local_18,*(undefined4 *)(in_ECX + 0x20),0);
        (*pcVar1)();
        pcVar1 = *(code **)(*(int *)local_18 + 8);
        guard_check_icall(local_18);
        (*pcVar1)();
      }
      pcVar1 = *(code **)(*local_34 + 8);
      guard_check_icall(local_34);
      (*pcVar1)();
    }
    local_1c = (undefined2 *)0x0;
    pcVar1 = *(code **)(*local_28 + 0x14);
    guard_check_icall(local_28,0x80058000,&local_1c);
    iVar4 = (*pcVar1)();
    if (-1 < iVar4) {
      CStringT<>(local_1c);
      local_8 = 0;
      if (1 < *(int *)(local_18 + -2)) {
        FUN_00405930(*(int *)(local_18 + -6));
      }
      PathRemoveFileSpecW(local_18);
      ReleaseBuffer(0xffffffff);
      iVar4 = *(int *)(local_18 + -6);
      if (local_1c[iVar4] == 0x5c) {
        iVar4 = iVar4 + 1;
      }
      FUN_008f8e5e(*(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x1c),
                   *(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x20),local_1c,0xffffffff);
      FUN_008f8e5e(*(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x24),
                   *(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x28),local_1c + iVar4,0xffffffff);
      iVar4 = *(int *)(*(int *)(in_ECX + 0xa8) + 0x1c);
      iVar5 = FUN_008f899d(iVar4);
      *(undefined2 *)(iVar4 + iVar5 * 2 + 2) = 0;
      CoTaskMemFree(local_1c);
      local_8 = 0xffffffff;
      FUN_00406b10();
    }
  }
  pcVar1 = *(code **)(*local_28 + 8);
  guard_check_icall(local_28);
  (*pcVar1)();
LAB_007b4f36:
  iVar4 = 0;
  FUN_007b4284(&local_20);
  local_8 = 2;
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,3);
  pWVar7 = PathFindFileNameW(local_20);
  if (pWVar7 != (LPWSTR)0x0) {
    iVar5 = FUN_008f899d(pWVar7);
    ATL::CSimpleStringT<wchar_t,0>::SetString((CSimpleStringT<wchar_t,0> *)&local_40,pWVar7,iVar5);
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,4);
  pWVar7 = PathFindExtensionW(local_20);
  if ((pWVar7 != (LPWSTR)0x0) && (*pWVar7 == L'.')) {
    pwVar6 = pWVar7 + 1;
    if (pwVar6 != (wchar_t *)0x0) {
      iVar4 = FUN_008f899d(pwVar6);
    }
    ATL::CSimpleStringT<wchar_t,0>::SetString((CSimpleStringT<wchar_t,0> *)&local_3c,pwVar6,iVar4);
  }
  *(WCHAR *)(*(int *)(in_ECX + 0xa8) + 0x38) = local_20[-6] - *(short *)(local_40 + -0xc);
  *(WCHAR *)(*(int *)(in_ECX + 0xa8) + 0x3a) = local_20[-6] - *(short *)((int)local_3c + -0xc);
  FUN_00406b10();
  FUN_00406b10();
  puVar8 = (undefined1 *)FUN_00406b10();
  return puVar8;
}



