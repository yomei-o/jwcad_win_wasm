/* CMDIClientAreaWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMDIClientAreaWnd[1] */
/* 00892282  FUN_00892282  51 bytes, 0 callers */

void FUN_00892282(byte param_1)

{
  FUN_00892020();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CMDIClientAreaWnd[26] */
/* 00892561  FUN_00892561  1054 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00892561(tagRECT *param_1,uint param_2)

{
  CWnd *pCVar1;
  code *pcVar2;
  int iVar3;
  CObject *pCVar4;
  int iVar5;
  HWND hWnd;
  uint uVar6;
  BOOL BVar7;
  CWnd *in_ECX;
  int iVar8;
  undefined4 local_60;
  int local_5c;
  tagRECT local_58;
  tagRECT local_48;
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x2b38) == 0) {
    if (*(int *)(in_ECX + 0x2b30) == 0) {
      pCVar1 = in_ECX + 0x80;
      if ((pCVar1 != (CWnd *)0x0) && (*(int *)(in_ECX + 0xa0) != 0)) {
        if (*(int *)(in_ECX + 0x2a98) == 0) {
          FUN_00797f20(0);
        }
        else {
          local_58.left = 0;
          local_58.top = 0;
          local_58.right = 0;
          local_58.bottom = 0;
          GetWindowRect(*(HWND *)(in_ECX + 0xa0),&local_58);
          FUN_00797e71(0,param_1->left,param_1->top,param_1->right - param_1->left,
                       param_1->bottom - param_1->top,0x14);
          local_28.left = 0;
          local_28.top = 0;
          local_28.right = 0;
          local_28.bottom = 0;
          GetClientRect(*(HWND *)(in_ECX + 0xa0),&local_28);
          local_48.left = *(LONG *)(in_ECX + 0x36c);
          local_48.top = *(LONG *)(in_ECX + 0x370);
          local_48.right = *(LONG *)(in_ECX + 0x374);
          local_48.bottom = *(LONG *)(in_ECX + 0x378);
          param_1->top = param_1->top + (local_48.top - local_28.top);
          param_1->bottom = param_1->bottom + (local_48.bottom - local_28.bottom);
          param_1->left = param_1->left + (local_48.left - local_28.left);
          param_1->right = param_1->right + (local_48.right - local_28.right);
          FUN_00797f20(8);
          local_18.left = 0;
          local_18.top = 0;
          local_18.right = 0;
          local_18.bottom = 0;
          GetWindowRect(*(HWND *)(in_ECX + 0xa0),&local_18);
          EqualRect(&local_58,&local_18);
        }
        local_38.left = 0;
        local_38.top = 0;
        local_38.right = 0;
        local_38.bottom = 0;
        GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_38);
        iVar3 = param_1->bottom - param_1->top;
        iVar8 = local_38.top - local_38.bottom;
        FUN_00797e71(0,param_1->left,param_1->top,param_1->right - param_1->left,iVar3,0x14);
        pCVar4 = (CObject *)FUN_0079296c();
        pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar4);
        if (pCVar4 != (CObject *)0x0) {
          pcVar2 = *(code **)(*(int *)pCVar4 + 0x200);
          CopyRect(&local_48,param_1);
          guard_check_icall(&local_38,&local_48);
          (*pcVar2)();
        }
        if (*(int *)(in_ECX + 0x2a98) == 0) {
          local_18.left = 0;
          local_18.top = 0;
          local_18.right = 0;
          local_18.bottom = 0;
          GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
          iVar5 = FUN_0079296c();
          hWnd = GetWindow(*(HWND *)(iVar5 + 0x120),5);
          while ((hWnd != (HWND)0x0 &&
                 (uVar6 = GetWindowLongW(hWnd,-0x10), (uVar6 & 0x1000000) == 0))) {
            if ((uVar6 & 0x20000000) != 0) {
              local_28.left = 0;
              local_28.top = 0;
              local_28.right = 0;
              local_28.bottom = 0;
              GetWindowRect(hWnd,&local_28);
              CWnd::ScreenToClient(in_ECX,&local_28);
              OffsetRect(&local_28,0,iVar8 + iVar3);
              if (local_28.top < local_18.top) {
                local_28.top = local_18.top;
              }
              SetWindowPos(hWnd,(HWND)0x0,local_28.left,local_28.top,0,0,0x15);
            }
            hWnd = GetWindow(hWnd,2);
          }
        }
      }
      CWnd::CalcWindowRect(in_ECX,param_1,param_2);
      pcVar2 = *(code **)(*(int *)pCVar1 + 0x20c);
      guard_check_icall();
      iVar3 = (*pcVar2)();
      local_5c = 0;
      pcVar2 = *(code **)(*(int *)pCVar1 + 0x1ac);
      guard_check_icall();
      iVar8 = (*pcVar2)();
      if (0 < iVar8) {
        do {
          pcVar2 = *(code **)(*(int *)pCVar1 + 0x1b0);
          guard_check_icall(local_5c);
          iVar8 = (*pcVar2)();
          if ((iVar8 != 0) && (*(int *)(iVar8 + 0x20) != 0)) {
            uVar6 = FUN_00797b3d();
            if (((uVar6 & 0x20000000) != 0) && (uVar6 = FUN_00797b3d(), (uVar6 & 0x80000) == 0)) {
              FUN_00797f20(9);
            }
            local_60 = 0x10;
            if (local_5c != iVar3) {
              local_60 = 0x1c;
            }
            local_18.right = param_1->right - param_1->left;
            local_18.bottom = param_1->bottom - param_1->top;
            local_18.left = 0;
            local_18.top = 0;
            local_28.left = 0;
            local_28.top = 0;
            local_28.right = 0;
            local_28.bottom = 0;
            GetClientRect(*(HWND *)(iVar8 + 0x20),&local_28);
            FUN_0079e8b8(&local_28);
            local_38.left = 0;
            local_38.top = 0;
            local_38.right = 0;
            local_38.bottom = 0;
            GetWindowRect(*(HWND *)(iVar8 + 0x20),&local_38);
            local_18.left = local_18.left + (local_38.left - local_28.left);
            local_18.top = local_18.top + (local_38.top - local_28.top);
            local_18.right = local_18.right + (local_38.right - local_28.right);
            local_18.bottom = local_18.bottom + (local_38.bottom - local_28.bottom);
            BVar7 = EqualRect(&local_28,&local_18);
            if (BVar7 != 0) {
              return;
            }
            uVar6 = FUN_00797b3d();
            if ((uVar6 & 0x80000) == 0) {
              FUN_00797e71(&DAT_00a11c68,local_18.left,local_18.top,local_18.right - local_18.left,
                           local_18.bottom - local_18.top,local_60);
            }
          }
          local_5c = local_5c + 1;
          pcVar2 = *(code **)(*(int *)pCVar1 + 0x1ac);
          guard_check_icall();
          iVar8 = (*pcVar2)();
        } while (local_5c < iVar8);
      }
    }
    else {
      FUN_0089297f(param_1,param_2);
      CWnd::CalcWindowRect(in_ECX,param_1,param_2);
    }
  }
  return;
}




/* vtable slots: CMDIClientAreaWnd[89] */
/* 00892e46  FUN_00892e46  591 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00892e46(CObject *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  BOOL BVar3;
  CMFCTabCtrl *this;
  int iVar4;
  HWND pHVar5;
  CWnd *pCVar6;
  int iVar7;
  CImageList *this_00;
  CWnd *pCVar8;
  undefined4 *puVar9;
  CWnd *in_ECX;
  CImageList *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x892e52;
  local_28 = (CImageList *)0x0;
  if (param_1 == (CObject *)0x0) {
    if (((*(int *)(in_ECX + 0x2af4) != 0) && (0 < *(int *)(in_ECX + 0x2b48))) &&
       (*(int *)(in_ECX + 0x2b30) != 0)) {
      pCVar2 = (CObject *)RemoveTail();
      param_1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,pCVar2);
      if ((param_1 != (CObject *)0x0) && (BVar3 = IsWindow(*(HWND *)(param_1 + 0x20)), BVar3 != 0))
      {
        local_28 = (CImageList *)0x1;
        goto LAB_00892ed1;
      }
    }
    this = (CMFCTabCtrl *)FUN_0078e624(0x2a18);
    local_8 = 0;
    if (this == (CMFCTabCtrl *)0x0) {
      param_1 = (CObject *)0x0;
    }
    else {
      param_1 = (CObject *)CMFCTabCtrl::CMFCTabCtrl(this);
    }
    local_8 = 0xffffffff;
  }
LAB_00892ed1:
  if (*(int *)(in_ECX + 0x2ad8) != 0) {
    FUN_00808230(1);
  }
  pCVar8 = in_ECX;
  if (*(int *)(in_ECX + 0x2b30) == 0) {
    pCVar8 = (CWnd *)FUN_0079296c();
  }
  if (local_28 == (CImageList *)0x0) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    iVar4 = FUN_0080f284(*(undefined4 *)(in_ECX + 0x2acc),&local_24,pCVar8,0xffffffff,
                         *(undefined4 *)(in_ECX + 0x2ac8),*(undefined4 *)(in_ECX + 0x2ad4));
    if (iVar4 == 0) {
      if ((param_1 != (CObject *)(in_ECX + 0x80)) && (param_1 != (CObject *)0x0)) {
        pcVar1 = *(code **)(*(int *)param_1 + 4);
        guard_check_icall(1);
        (*pcVar1)();
      }
      goto LAB_0089308d;
    }
    if (*(int *)(in_ECX + 0x2aa0) != 0) {
      *(int *)(param_1 + 0x1e8) = 1;
    }
  }
  else {
    pHVar5 = GetParent(*(HWND *)(param_1 + 0x20));
    pCVar6 = CWnd::FromHandle(pHVar5);
    if (pCVar6 != pCVar8) {
      if (pCVar8 == (CWnd *)0x0) {
        pHVar5 = (HWND)0x0;
      }
      else {
        pHVar5 = *(HWND *)(pCVar8 + 0x20);
      }
      pHVar5 = SetParent(*(HWND *)(param_1 + 0x20),pHVar5);
      CWnd::FromHandle(pHVar5);
    }
    FUN_0080fb98(*(undefined4 *)(in_ECX + 0x2acc));
    pcVar1 = *(code **)(*(int *)param_1 + 0x278);
    guard_check_icall(*(undefined4 *)(in_ECX + 0x2ac8));
    (*pcVar1)();
    FUN_0080f53f(*(undefined4 *)(in_ECX + 0x2ad4));
  }
  FUN_00892463(param_1);
  if (*(int *)(in_ECX + 0x2a98) == 0) {
    FUN_00797f20(0);
  }
  if (*(int *)(in_ECX + 0x2b30) == 0) {
    iVar4 = FUN_007c2511();
    iVar4 = *(int *)(iVar4 + 0x118);
    iVar7 = FUN_007c2511();
    pCVar8 = in_ECX + 0x2aa4;
  }
  else {
    local_28 = (CImageList *)0x0;
    iVar4 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                      ((CMap<unsigned_int,unsigned_int,int,int> *)(in_ECX + 0x2b14),(uint)param_1,
                       (int *)&local_28);
    pCVar8 = (CWnd *)local_28;
    if ((iVar4 == 0) || (local_28 == (CImageList *)0x0)) {
      this_00 = (CImageList *)FUN_0078e624(8);
      local_8 = 1;
      if (this_00 == (CImageList *)0x0) {
        pCVar8 = (CWnd *)0x0;
      }
      else {
        pCVar8 = (CWnd *)CImageList::CImageList(this_00);
      }
      local_8 = 0xffffffff;
      puVar9 = (undefined4 *)FUN_007e3332(param_1);
      *puVar9 = pCVar8;
    }
    else {
      CImageList::DeleteImageList(local_28);
    }
    iVar4 = FUN_007c2511();
    iVar4 = *(int *)(iVar4 + 0x118);
    iVar7 = FUN_007c2511();
  }
  CImageList::Create((CImageList *)pCVar8,*(int *)(iVar7 + 0x114),iVar4,0x21,0,1);
LAB_0089308d:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMDIClientAreaWnd[10] */
/* 008937d5  FUN_008937d5  6 bytes, 0 callers */

undefined ** FUN_008937d5(void)

{
  return &PTR_FUN_0099c888;
}




/* vtable slots: CMDIClientAreaWnd[0] */
/* 00893825  FUN_00893825  6 bytes, 0 callers */

undefined ** FUN_00893825(void)

{
  return &PTR_s_CMDIClientAreaWnd_0099c578;
}




/* vtable slots: CMDIClientAreaWnd[20] */
/* 00894b12  FUN_00894b12  39 bytes, 0 callers */

void FUN_00894b12(void)

{
  code *pcVar1;
  int *in_ECX;
  
  guard_check_icall();
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall(in_ECX + 0x20);
  (*pcVar1)();
  return;
}




/* vtable slots: CMDIClientAreaWnd[2] */
/* 00894e69  FUN_00894e69  953 bytes, 0 callers */

void FUN_00894e69(CArchive *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  int iVar5;
  WPARAM wParam;
  HWND pHVar6;
  CWnd *pCVar7;
  CObject *in_ECX;
  CObject *local_c;
  CObject *local_8;
  
  local_c = in_ECX;
  local_8 = in_ECX;
  FUN_00895222(param_1);
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    if (((byte)param_1[0x18] & 1) != 0) {
      FUN_00892c0a(0);
      FUN_00813b58();
      *(int *)(in_ECX + 0x2b38) = 1;
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x2a9c));
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x2b30));
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x2a98));
      CArchive::operator>>(param_1,(long *)&local_c);
      *(CObject **)(in_ECX + 0x2b90) = local_c;
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x2b58));
      CArchive::operator>>(param_1,(long *)(in_ECX + 0x2b5c));
      if (*(int *)(in_ECX + 0x2a9c) == 0) {
        if (*(int *)(in_ECX + 0x2b30) == 0) {
          FUN_008952ef(param_1);
        }
        else {
          local_8 = (CObject *)0x0;
          CArchive::operator>>(param_1,(long *)&local_8);
          local_c = local_8;
          if (0 < (int)local_8) {
            do {
              pcVar1 = *(code **)(*(int *)in_ECX + 0x164);
              guard_check_icall(0);
              pCVar3 = (CObject *)(*pcVar1)();
              local_8 = pCVar3;
              FUN_008957a8(param_1,pCVar3,1);
              pcVar1 = *(code **)(*(int *)pCVar3 + 0x1ac);
              guard_check_icall();
              iVar5 = (*pcVar1)();
              if (iVar5 == 0) {
                pcVar1 = *(code **)(*(int *)local_8 + 0x60);
                guard_check_icall();
                (*pcVar1)();
                pcVar1 = *(code **)(*(int *)local_8 + 4);
                guard_check_icall(1);
                (*pcVar1)();
              }
              else {
                CObList::AddTail((CObList *)(in_ECX + 11000),local_8);
              }
              local_c = local_c + -1;
            } while (local_c != (CObject *)0x0);
            local_c = (CObject *)0x0;
          }
          if (0 < *(int *)(in_ECX + 0x2b04)) {
            AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,
                               *(CObject **)(*(int *)(in_ECX + 0x2b00) + 8));
            FUN_008132c9(0);
          }
          FUN_00893152(1,in_ECX + 0x2ac8);
        }
      }
      else {
        FUN_008957a8(param_1,in_ECX + 0x80,0);
        FUN_00893443(1,in_ECX + 0x2ac8);
      }
      *(int *)(in_ECX + 0x2b38) = 0;
      if (*(int *)(in_ECX + 0x2b30) == 0) {
        if (*(int *)(in_ECX + 0x2a9c) != 0) {
          FUN_0089665e(1);
          pcVar1 = *(code **)(*(int *)(in_ECX + 0x80) + 0x184);
          guard_check_icall();
          (*pcVar1)();
        }
      }
      else {
        FUN_008960f1(1);
        local_8 = *(CObject **)(in_ECX + 0x2afc);
        while (local_8 != (CObject *)0x0) {
          puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
          pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,
                                      (CObject *)*puVar2);
          pcVar1 = *(code **)(*(int *)pCVar3 + 0x184);
          local_c = pCVar3;
          guard_check_icall();
          (*pcVar1)();
          if (*(int *)(pCVar3 + 0x298) != 0) {
            iVar5 = *(int *)pCVar3;
            pcVar1 = *(code **)(iVar5 + 0x20c);
            guard_check_icall();
            uVar4 = (*pcVar1)();
            pcVar1 = *(code **)(iVar5 + 0x1b0);
            guard_check_icall(uVar4);
            iVar5 = (*pcVar1)();
            wParam = 0;
            if (iVar5 != 0) {
              wParam = *(WPARAM *)(iVar5 + 0x20);
            }
            PostMessageW(*(HWND *)(in_ECX + 0x20),0x222,wParam,0);
          }
        }
      }
      pHVar6 = GetParent(*(HWND *)(in_ECX + 0x20));
      pCVar7 = CWnd::FromHandle(pHVar6);
      pcVar1 = *(code **)(*(int *)pCVar7 + 0x178);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  else {
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x2a9c));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x2b30));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x2a98));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x2b90));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x2b58));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x2b5c));
    if (*(int *)(in_ECX + 0x2a9c) == 0) {
      if (*(int *)(in_ECX + 0x2b30) == 0) {
        FUN_008952ef(param_1);
      }
      else {
        iVar5 = *(int *)(in_ECX + 0x2b04);
        CArchive::operator<<(param_1,iVar5);
        if (0 < iVar5) {
          local_8 = *(CObject **)(in_ECX + 0x2afc);
          while (local_8 != (CObject *)0x0) {
            puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
            pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,
                                        (CObject *)*puVar2);
            FUN_008957a8(param_1,pCVar3,0);
          }
        }
      }
    }
    else {
      FUN_008957a8(param_1,in_ECX + 0x80,0);
    }
  }
  return;
}



