/* CMFCHeaderCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCHeaderCtrl[1] */
/* 0082909b  FUN_0082909b  51 bytes, 0 callers */

void FUN_0082909b(byte param_1)

{
  FUN_00828fd8();
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




/* vtable slots: CMFCHeaderCtrl[10] */
/* 00829149  FUN_00829149  6 bytes, 0 callers */

undefined ** FUN_00829149(void)

{
  return &PTR_FUN_0098faf8;
}




/* vtable slots: CMFCHeaderCtrl[0] */
/* 0082914f  FUN_0082914f  6 bytes, 0 callers */

undefined ** FUN_0082914f(void)

{
  return &PTR_s_CMFCHeaderCtrl_0098f84c;
}




/* vtable slots: CMFCHeaderCtrl[92] */
/* 0082919e  FUN_0082919e  964 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void FUN_0082919e(CDC *param_1,uint param_2,CHeaderCtrl *param_3,int param_4,CHeaderCtrl *param_5,
                 int param_6,int param_7,undefined4 param_8)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  LRESULT LVar4;
  CImageList *pCVar5;
  CGdiObject *pCVar6;
  undefined4 uVar7;
  CHeaderCtrl *pCVar8;
  CHeaderCtrl *pCVar9;
  CDC *pCVar10;
  undefined1 local_294 [4];
  int local_290;
  int local_28c;
  undefined4 local_27c [2];
  undefined1 *local_274;
  void *local_270;
  undefined4 local_26c;
  uint local_268;
  int local_260;
  undefined1 local_24c [4];
  undefined8 local_248;
  int local_240;
  CDC *local_23c;
  CHeaderCtrl *local_238;
  tagRECT local_234;
  tagRECT local_224;
  undefined1 local_214 [524];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x284;
  local_8 = 0x8291ad;
  local_23c = param_1;
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x158);
  guard_check_icall(local_238,local_23c,&param_3,param_7,param_8);
  (*pcVar1)();
  pCVar8 = local_238;
  if (-1 < (int)param_2) {
    local_240 = 0;
    iVar3 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                      ((CMap<unsigned_int,unsigned_int,int,int> *)(local_238 + 0x80),param_2,
                       &local_240);
    pCVar10 = local_23c;
    if ((iVar3 != 0) && (local_240 != 0)) {
      local_224.left = (LONG)param_3;
      local_224.top = param_4;
      local_224.right = (LONG)param_5;
      local_224.bottom = param_6;
      InflateRect(&local_224,-5,-5);
      local_224.left = local_224.right + -(local_224.bottom - local_224.top);
      if (param_7 != 0) {
        local_224.right = local_224.right + 1;
        local_224.bottom = local_224.bottom + 1;
      }
      param_5 = (CHeaderCtrl *)(local_224.left + -1);
      local_248 = (double)(local_224.right - local_224.left);
      iVar3 = thunk_FUN_008d99f0();
      InflateRect(&local_224,0,-iVar3);
      pCVar10 = local_23c;
      *(uint *)(local_238 + 0xa4) = (uint)(0 < local_240);
      local_248 = (double)CONCAT44(*(undefined4 *)(*(int *)local_238 + 0x178),(undefined4)local_248)
      ;
      guard_check_icall(local_23c,local_224.left,local_224.top,local_224.right,local_224.bottom);
      pCVar8 = local_238;
      (*local_248._4_4_)();
    }
    _memset(local_27c,0,0x30);
    local_27c[0] = 0x36;
    local_274 = local_214;
    local_26c = 0xff;
    LVar4 = SendMessageW(*(HWND *)(pCVar8 + 0x20),0x120b,param_2,(LPARAM)local_27c);
    if (LVar4 != 0) {
      if ((((local_268 & 0x800) != 0) && (-1 < local_260)) &&
         (pCVar5 = CHeaderCtrl::GetImageList(pCVar8,0), pCVar5 != (CImageList *)0x0)) {
        local_238 = (CHeaderCtrl *)0x0;
        local_240 = 0;
        FUN_007fa90e(*(undefined4 *)(pCVar5 + 4),&local_238,&local_240);
        local_248 = (double)CONCAT44(param_3 + 1,(undefined4)local_248);
        if (pCVar10 == (CDC *)0x0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined4 *)(pCVar10 + 4);
        }
        FUN_0079cf15(*(undefined4 *)(pCVar5 + 4),local_260,uVar7,param_3 + 1,
                     ((param_6 - local_240) + param_4) / 2,0);
        param_3 = param_3 + (int)local_238;
      }
      if (((local_268 & 0x3000) != 0) && (local_270 != (void *)0x0)) {
        pCVar6 = CGdiObject::FromHandle(local_270);
        local_248 = (double)CONCAT44(pCVar6,(undefined4)local_248);
        GetObjectW(*(HANDLE *)(pCVar6 + 4),0x18,local_294);
        local_224.left = (LONG)param_3;
        local_224.top = param_4;
        local_224.right = (LONG)param_5;
        local_224.bottom = param_6;
        if ((local_268 & 0x1000) == 0) {
          pCVar8 = param_3 + 1;
          pCVar9 = pCVar8 + local_290;
          param_3 = pCVar9;
        }
        else {
          pCVar9 = param_5 + -1;
          pCVar8 = pCVar9 + -local_290;
          param_5 = pCVar8;
        }
        if (((param_6 - param_4) - local_28c) / 2 < 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = ((param_6 - param_4) - local_28c) / 2;
        }
        CDC::DrawState(local_23c,pCVar8,param_4 + iVar3,(int)pCVar9 - (int)pCVar8,local_28c,
                       local_248._4_4_,0,0);
      }
      if (((local_268 & 0x4000) != 0) && (local_274 != (undefined1 *)0x0)) {
        local_234.left = (LONG)param_3;
        local_234.top = param_4;
        local_234.right = (LONG)param_5;
        local_234.bottom = param_6;
        InflateRect(&local_234,-5,0);
        CStringT<>(local_274);
        local_8 = 0;
        uVar7 = 0x8824;
        if ((local_268 & 2) == 0) {
          if ((local_268 & 1) != 0) {
            uVar7 = 0x8826;
          }
        }
        else {
          uVar7 = 0x8825;
        }
        FUN_007c2378(local_24c,&local_234,uVar7);
        FUN_00406b10();
      }
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCHeaderCtrl[94] */
/* 00829562  FUN_00829562  62 bytes, 0 callers */

void FUN_00829562(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x15c);
  guard_check_icall(in_ECX,param_1,&stack0x00000008,*(undefined4 *)(in_ECX + 0xa4));
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCHeaderCtrl[93] */
/* 008295a0  FUN_008295a0  117 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008295a0(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x154);
  guard_check_icall(in_ECX,param_1,local_18.left,local_18.top,local_18.right,local_18.bottom);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCHeaderCtrl[20] */
/* 00829a72  PreSubclassWindow  16 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCHeaderCtrl::PreSubclassWindow(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCHeaderCtrl::PreSubclassWindow(CMFCHeaderCtrl *this)

{
  CommonInit(this);
  guard_check_icall();
  return;
}



