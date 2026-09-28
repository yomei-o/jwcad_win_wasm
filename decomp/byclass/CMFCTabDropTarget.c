/* CMFCTabDropTarget -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTabDropTarget[1] */
/* 008073e5  FUN_008073e5  48 bytes, 0 callers */

void FUN_008073e5(byte param_1)

{
  FUN_0088bbef();
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




/* vtable slots: CMFCTabDropTarget[21] */
/* 008094ed  FUN_008094ed  94 bytes, 0 callers */

undefined4
FUN_008094ed(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((DAT_00a127ac != 0) && (iVar2 = FUN_007b9bc6(DAT_00a13be8,0), iVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x2b0);
    guard_check_icall(param_2,param_3,param_4,param_5);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  return 0;
}




/* vtable slots: CMFCTabDropTarget[25] */
/* 0080954c  FUN_0080954c  39 bytes, 0 callers */

void FUN_0080954c(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x2b4);
    guard_check_icall();
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCTabDropTarget[22] */
/* 00809574  FUN_00809574  194 bytes, 0 callers */

undefined4
FUN_00809574(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((DAT_00a127ac != 0) && (iVar2 = FUN_007b9bc6(DAT_00a13be8,0), iVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x2b8);
    guard_check_icall(param_2,param_3,param_4,param_5);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x218);
    puVar5 = &param_4;
    guard_check_icall(puVar5);
    iVar2 = (*pcVar1)();
    if (iVar2 != -1) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x20c);
      guard_check_icall(puVar5);
      iVar4 = (*pcVar1)();
      if (iVar2 != iVar4) {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x214);
        guard_check_icall(iVar2);
        (*pcVar1)();
      }
    }
  }
  return 0;
}




/* vtable slots: CMFCTabDropTarget[24] */
/* 00809637  FUN_00809637  101 bytes, 0 callers */

uint FUN_00809637(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((DAT_00a127ac != 0) && (iVar2 = FUN_007b9bc6(DAT_00a13be8,0), iVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x2ac);
    guard_check_icall(param_2,param_3,param_5,param_6);
    iVar2 = (*pcVar1)();
    return -(uint)(iVar2 != 0) & param_3;
  }
  return 0;
}




/* vtable slots: CMFCTabDropTarget[14], CMFCToolBarDropTarget[14], COleDropTarget[14] */
/* 0088c199  FUN_0088c199  6 bytes, 0 callers */

undefined ** FUN_0088c199(void)

{
  return &PTR_DAT_0099bd84;
}




/* vtable slots: CMFCTabDropTarget[26], CMFCToolBarDropTarget[26], COleDropTarget[26] */
/* 0088c24d  FUN_0088c24d  626 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0088c24d(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  POINT pt;
  POINT pt_00;
  int *piVar1;
  uint uVar2;
  int iVar3;
  BOOL BVar4;
  int *in_ECX;
  DWORD DVar5;
  uint uVar6;
  code *pcVar7;
  undefined1 local_50 [16];
  int *local_40;
  int *local_3c;
  uint local_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x88c259;
  local_3c = param_1;
  iVar3 = FUN_0079d98a(&PTR_s_CView_0097d804);
  if (iVar3 != 0) {
    pcVar7 = *(code **)(*param_1 + 0x184);
    guard_check_icall(param_2,param_3,param_4);
    iVar3 = (*pcVar7)();
    if (iVar3 == -0x80000000) {
      local_24.left = 0;
      local_24.top = 0;
      local_24.right = 0;
      local_24.bottom = 0;
      GetClientRect((HWND)param_1[8],&local_24);
      local_34.left = local_24.left;
      local_34.top = local_24.top;
      local_34.right = local_24.right;
      local_34.bottom = local_24.bottom;
      local_38 = 0xffff;
      InflateRect(&local_34,-DAT_00a13c3c,-DAT_00a13c3c);
      pt.y = param_4;
      pt.x = param_3;
      BVar4 = PtInRect(&local_24,pt);
      if ((BVar4 != 0) &&
         (pt_00.y = param_4, pt_00.x = param_3, BVar4 = PtInRect(&local_34,pt_00), piVar1 = local_3c
         , BVar4 == 0)) {
        if (param_3 < local_34.left) {
          local_38 = 0xff00;
        }
        else if (local_34.right <= param_3) {
          local_38 = 0xff01;
        }
        if (param_4 < local_34.top) {
          local_38 = local_38 & 0xff;
        }
        else if (local_34.bottom <= param_4) {
          local_38 = local_38 & 0xff | 0x100;
        }
        local_40 = (int *)FUN_007b676c(local_3c,0);
        uVar2 = local_38;
        if (local_40 == (int *)0x0) {
          pcVar7 = *(code **)(*piVar1 + 0x168);
          guard_check_icall(local_38,0,0);
        }
        else {
          pcVar7 = *(code **)(*local_40 + 0x1ac);
          guard_check_icall(local_3c,local_38,0);
        }
        iVar3 = (*pcVar7)();
        if ((iVar3 != 0) && (uVar2 != 0xffff)) {
          local_38 = GetTickCount();
          uVar6 = in_ECX[10];
          if (uVar2 == uVar6) {
            DVar5 = in_ECX[0xb];
          }
          else {
            in_ECX[0xb] = local_38;
            in_ECX[0xc] = DAT_00a13c40;
            DVar5 = local_38;
          }
          if ((uint)in_ECX[0xc] < local_38 - DVar5) {
            if (local_40 == (int *)0x0) {
              pcVar7 = *(code **)(*local_3c + 0x168);
              guard_check_icall(uVar2,0,1);
            }
            else {
              pcVar7 = *(code **)(*local_40 + 0x1ac);
              guard_check_icall(local_3c,uVar2,1);
            }
            (*pcVar7)();
            uVar6 = in_ECX[10];
            in_ECX[0xb] = local_38;
            in_ECX[0xc] = DAT_00a13c44;
          }
          if (uVar6 == 0xffff) {
            pcVar7 = *(code **)(*in_ECX + 100);
            guard_check_icall(local_3c);
            (*pcVar7)();
          }
          in_ECX[10] = uVar2;
          goto LAB_0088c4b7;
        }
      }
      if (in_ECX[10] != 0xffff) {
        FUN_007b98e9();
        local_8 = 0;
        FUN_007b98fd(in_ECX[9],0);
        pcVar7 = *(code **)(*in_ECX + 0x54);
        guard_check_icall(local_3c,local_50,param_2,param_3,param_4);
        (*pcVar7)();
        in_ECX[10] = 0xffff;
        local_8 = 1;
        FUN_007b9c1f();
      }
    }
  }
LAB_0088c4b7:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCTabDropTarget[23], CMFCToolBarDropTarget[23], COleDropTarget[23] */
/* 0088c4bf  FUN_0088c4bf  62 bytes, 0 callers */

void FUN_0088c4bf(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = FUN_0079d98a(&PTR_s_CView_0097d804);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x17c);
    guard_check_icall(param_2,param_3,param_4,param_5);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCTabDropTarget[20], CMFCToolBarDropTarget[20], COleDropTarget[20] */
/* 0088c5d3  Revoke  59 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall COleDropTarget::Revoke(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall COleDropTarget::Revoke(COleDropTarget *this)

{
  LPUNKNOWN pUnk;
  CWnd *pCVar1;
  BOOL fLock;
  BOOL fLastUnlockReleases;
  
  if (*(int *)(this + 0x20) != 0) {
    RevokeDragDrop(*(HWND *)(this + 0x20));
    fLastUnlockReleases = 1;
    fLock = 0;
    pUnk = (LPUNKNOWN)FUN_007c0cc0(&DAT_009a9c9c);
    CoLockObjectExternal(pUnk,fLock,fLastUnlockReleases);
    pCVar1 = CWnd::FromHandle(*(HWND__ **)(this + 0x20));
    *(undefined4 *)(pCVar1 + 0x6c) = 0;
    *(undefined4 *)(this + 0x20) = 0;
  }
  return;
}



