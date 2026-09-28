/* CMFCColorPropertySheet -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCColorPropertySheet[94], CMFCToolBarsCustomizeDialog[94], CMyPropertySheet[94], CPropertySheet[94] */
/* 004dd210  FUN_004dd210  16 bytes, 1 callers */

undefined4 FUN_004dd210(void)

{
  return 1;
}




/* vtable slots: CMFCColorPropertySheet[92], CMFCToolBarsCustomizeDialog[92], CMyPropertySheet[92], CPropertySheet[92] */
/* 007a0003  FUN_007a0003  274 bytes, 0 callers */

void FUN_007a0003(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_8;
  
  FUN_008f43b0(*(undefined4 *)(in_ECX + 0xa0));
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  iVar5 = 0;
  iVar6 = 0;
  if (0 < *(int *)(in_ECX + 0xbc)) {
    do {
      iVar3 = FUN_007a065c(iVar6);
      iVar5 = iVar5 + **(int **)(iVar3 + 0xa8);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0xbc));
  }
  piVar4 = (int *)FUN_00900c73(iVar5);
  if (piVar4 != (int *)0x0) {
    piVar1 = (int *)((int)piVar4 + iVar5);
    if (piVar1 < piVar4) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    uVar2 = *(uint *)(in_ECX + 0x84);
    *(int **)(in_ECX + 0xa0) = piVar4;
    iVar5 = *(int *)(in_ECX + 0xbc);
    local_8 = 0;
    piVar7 = piVar4;
    if (0 < iVar5) {
      do {
        iVar5 = FUN_007a065c(local_8);
        if ((piVar7 < piVar4) || (piVar1 < piVar7)) goto LAB_007a010b;
        FUN_0043add0(piVar7,(int)piVar1 - (int)piVar7,*(undefined4 **)(iVar5 + 0xa8),
                     **(undefined4 **)(iVar5 + 0xa8));
        iVar6 = *(int *)(iVar5 + 0xb4);
        if (*(int *)(iVar6 + -0xc) != 0) {
          piVar7[1] = piVar7[1] | 0x1000;
          piVar7[10] = iVar6;
        }
        iVar5 = *(int *)(iVar5 + 0xb8);
        if (*(int *)(iVar5 + -0xc) != 0) {
          piVar7[1] = piVar7[1] | 0x2000;
          piVar7[0xb] = iVar5;
        }
        FUN_007a11b1(piVar7,uVar2 & 0x1000020);
        piVar7 = (int *)((int)piVar7 + *piVar7);
        local_8 = local_8 + 1;
        iVar5 = *(int *)(in_ECX + 0xbc);
      } while (local_8 < iVar5);
    }
    *(int *)(in_ECX + 0x98) = iVar5;
    return;
  }
LAB_007a010b:
                    /* WARNING: Subroutine does not return */
  FUN_0078e73e();
}




/* vtable slots: CMFCColorPropertySheet[34], CMFCToolBarsCustomizeDialog[34], CMyPropertySheet[34], CPropertySheet[34] */
/* 007a02b0  ContinueModal  40 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CPropertySheet::ContinueModal(void)
   
   Library: Visual Studio 2015 Release */

int __thiscall CPropertySheet::ContinueModal(CPropertySheet *this)

{
  int iVar1;
  LRESULT LVar2;
  
  iVar1 = FUN_00791f48();
  if (iVar1 == 0) {
    return 0;
  }
  LVar2 = SendMessageW(*(HWND *)(this + 0x20),0x476,0,0);
  return (uint)(LVar2 != 0);
}




/* vtable slots: CMFCColorPropertySheet[89], CMFCToolBarsCustomizeDialog[89], CMyPropertySheet[89], CPropertySheet[89] */
/* 007a02d8  FUN_007a02d8  324 bytes, 1 callers */

undefined4 FUN_007a02d8(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  _AFX_THREAD_STATE *p_Var2;
  int iVar3;
  int iVar4;
  HGLOBAL hMem;
  undefined4 *puVar5;
  BOOL BVar6;
  int *in_ECX;
  
  if ((~((uint)in_ECX[0x21] >> 0xe) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  p_Var2 = AfxGetThreadState();
  if (param_2 == -1) {
    *(undefined4 *)(p_Var2 + 0x1c) = 0x90c020c4;
    if ((in_ECX[0x21] & 0x1000020U) == 0) {
      *(undefined4 *)(p_Var2 + 0x1c) = 0x90c820c4;
    }
  }
  else {
    *(int *)(p_Var2 + 0x1c) = param_2;
  }
  *(undefined4 *)(p_Var2 + 0x20) = param_3;
  FUN_00790c5e(0x10);
  FUN_00790c5e(0xfc000);
  FUN_007910b4();
  pcVar1 = *(code **)(*in_ECX + 0x170);
  guard_check_icall();
  (*pcVar1)();
  in_ECX[0x21] = in_ECX[0x21] | 0x500;
  in_ECX[0x35] = 1;
  in_ECX[0x29] = (int)FUN_0079ff64;
  iVar3 = 0;
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0x20);
  }
  in_ECX[0x22] = iVar3;
  FUN_00790fd2(in_ECX);
  iVar3 = FUN_007a168a(in_ECX + 0x20);
  if (iVar3 != -1) {
    iVar4 = FUN_0079134d();
    if (iVar4 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x120);
      guard_check_icall();
      (*pcVar1)();
    }
    hMem = GlobalAlloc(0x40,4);
    puVar5 = GlobalLock(hMem);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = 1;
      GlobalUnlock(hMem);
      BVar6 = SetPropW((HWND)in_ECX[8],(LPCWSTR)PTR_u_AfxClosePending_00a0036c,hMem);
      if (BVar6 != 0) {
        if (iVar3 == 0) {
          return 0;
        }
        return 1;
      }
      GlobalFree(hMem);
    }
    pcVar1 = *(code **)(*in_ECX + 0x60);
    guard_check_icall();
    (*pcVar1)();
  }
  return 0;
}




/* vtable slots: CMFCColorPropertySheet[90], CMFCToolBarsCustomizeDialog[90], CMyPropertySheet[90], CPropertySheet[90] */
/* 007a041d  FUN_007a041d  469 bytes, 1 callers */

int FUN_007a041d(void)

{
  code *pcVar1;
  CWinApp *this;
  int iVar2;
  undefined4 uVar3;
  HWND hWnd;
  BOOL BVar4;
  HWND pHVar5;
  uint uVar6;
  int *in_ECX;
  HWND local_10;
  int local_c;
  int local_8;
  
  FUN_00790c5e(0x10);
  FUN_00790c5e(0xfc000);
  FUN_007910b4();
  pcVar1 = *(code **)(*in_ECX + 0x170);
  guard_check_icall();
  (*pcVar1)();
  iVar2 = FUN_0079dd6d();
  this = *(CWinApp **)(iVar2 + 4);
  if (this != (CWinApp *)0x0) {
    CWinApp::EnableModeless(this,0);
  }
  if (in_ECX[0x33] == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(in_ECX[0x33] + 0x20);
  }
  hWnd = (HWND)FUN_0079f613(uVar3,&local_10);
  local_c = 0;
  in_ECX[0x22] = (int)hWnd;
  if (hWnd != (HWND)0x0) {
    BVar4 = IsWindowEnabled(hWnd);
    if (BVar4 != 0) {
      EnableWindow(hWnd,0);
      local_c = 1;
    }
  }
  pHVar5 = GetCapture();
  if (pHVar5 != (HWND)0x0) {
    SendMessageW(pHVar5,0x1f,0,0);
  }
  in_ECX[0x1a] = 0;
  if ((in_ECX[0x21] & 0x4000U) == 0) {
    in_ECX[0x18] = in_ECX[0x18] | 0x10;
  }
  FUN_00790fd2(in_ECX);
  if ((in_ECX[0x21] & 0x4000U) == 0) {
    in_ECX[0x21] = in_ECX[0x21] | 0x400;
    iVar2 = FUN_007a168a(in_ECX + 0x20);
    in_ECX[0x21] = in_ECX[0x21] & 0xfffffbff;
    FUN_0079134d();
    if ((iVar2 == 0) || (iVar2 == -1)) {
      in_ECX[0x18] = in_ECX[0x18] & 0xffffffef;
    }
    local_8 = in_ECX[0x1a];
    pcVar1 = *(code **)(*in_ECX + 0x88);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      uVar6 = FUN_00797b3d();
      local_8 = FUN_00794fd5((uVar6 & 0x100 | 0x400) >> 8);
    }
    if (in_ECX[8] != 0) {
      FUN_00797e71(0,0,0,0,0,0x97);
    }
  }
  else {
    local_8 = FUN_007a168a(in_ECX + 0x20);
    FUN_0079134d();
    in_ECX[8] = 0;
  }
  if (local_c != 0) {
    EnableWindow(hWnd,1);
  }
  if (hWnd != (HWND)0x0) {
    pHVar5 = GetActiveWindow();
    if (pHVar5 == (HWND)in_ECX[8]) {
      SetActiveWindow(hWnd);
    }
  }
  if ((in_ECX[0x21] & 0x4000U) == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x60);
    guard_check_icall();
    (*pcVar1)();
  }
  if (this != (CWinApp *)0x0) {
    CWinApp::EnableModeless(this,1);
  }
  if (local_10 != (HWND)0x0) {
    EnableWindow(local_10,1);
  }
  return local_8;
}




/* vtable slots: CMFCColorPropertySheet[61], CMyPropertySheet[61], CPropertySheet[61] */
/* 007a09cd  FUN_007a09cd  116 bytes, 1 callers */

undefined4 FUN_007a09cd(uint param_1,HWND param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  
  iVar1 = FUN_00793275(param_1,param_2);
  if (iVar1 == 0) {
    if ((param_2 != (HWND)0x0) && ((short)(param_1 >> 0x10) == 0)) {
      uVar3 = SendMessageW(param_2,0x87,0,0);
      if ((uVar3 & 0x2010) != 0) {
        uVar3 = GetWindowLongW(param_2,-0x10);
        uVar3 = uVar3 & 0xf;
        if ((((uVar3 == 0) || (uVar3 == 1)) || (uVar3 == 8)) || (uVar3 == 0xb)) {
          *(uint *)(in_ECX + 0x68) = param_1 & 0xffff;
        }
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCColorPropertySheet[1] */
/* 008d1f00  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCColorPropertySheet::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCColorPropertySheet::_scalar_deleting_destructor_(CMFCColorPropertySheet *this,uint param_1)

{
  *(undefined ***)this = vftable;
  CPropertySheet::~CPropertySheet((CPropertySheet *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xe8);
    }
  }
  return this;
}




/* vtable slots: CMFCColorPropertySheet[10] */
/* 008d1f39  FUN_008d1f39  6 bytes, 0 callers */

undefined ** FUN_008d1f39(void)

{
  return &PTR_FUN_009a7a4c;
}




/* vtable slots: CMFCColorPropertySheet[0] */
/* 008d1f3f  FUN_008d1f3f  6 bytes, 0 callers */

undefined ** FUN_008d1f3f(void)

{
  return &PTR_s_CMFCColorPropertySheet_009a7868;
}




/* vtable slots: CMFCColorPropertySheet[91] */
/* 008d1f45  OnInitDialog  39 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCColorPropertySheet::OnInitDialog(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCColorPropertySheet::OnInitDialog(CMFCColorPropertySheet *this)

{
  int iVar1;
  
  iVar1 = FUN_007a0b0c();
  FUN_00797c9f(0,0x10000,0);
  FUN_008d2012();
  return iVar1;
}




/* vtable slots: CMFCColorPropertySheet[62] */
/* 008d1f6c  FUN_008d1f6c  53 bytes, 0 callers */

void FUN_008d1f6c(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 != 0) {
    if (*(int *)(param_2 + 8) == -0x227) {
      FUN_008d2012();
    }
    FUN_00793ba8(param_1,param_2,param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorPropertySheet[72] */
/* 008d1fb5  FUN_008d1fb5  40 bytes, 0 callers */

void FUN_008d1fb5(void)

{
  code *pcVar1;
  int *in_ECX;
  
  guard_check_icall();
  if (in_ECX[0x35] != 0) {
    pcVar1 = *(code **)(*in_ECX + 4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCColorPropertySheet[67] */
/* 008d1fdd  PreTranslateMessage  53 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CMFCColorPropertySheet::PreTranslateMessage(struct tagMSG *)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCColorPropertySheet::PreTranslateMessage(CMFCColorPropertySheet *this,tagMSG *param_1)

{
  int iVar1;
  
  if ((*(HACCEL *)(this + 0xe0) != (HACCEL)0x0) &&
     (iVar1 = TranslateAcceleratorW(*(HWND *)(this + 0x20),*(HACCEL *)(this + 0xe0),param_1),
     iVar1 != 0)) {
    return 1;
  }
  iVar1 = FUN_007a1270(param_1);
  return iVar1;
}



