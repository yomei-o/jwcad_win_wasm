/* COleDropSource -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDropSource[1] */
/* 007d0a71  FUN_007d0a71  48 bytes, 0 callers */

void FUN_007d0a71(byte param_1)

{
  FUN_0078feea();
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




/* vtable slots: COleDropSource[21] */
/* 007d0ba9  GiveFeedback  15 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual long __thiscall COleDropSource::GiveFeedback(unsigned long)
   
   Library: Visual Studio 2015 Release */

long __thiscall COleDropSource::GiveFeedback(COleDropSource *this,ulong param_1)

{
  return -(uint)(*(int *)(this + 0x34) != 0) & 0x40102;
}




/* vtable slots: COleDropSource[22] */
/* 007d0bf4  FUN_007d0bf4  289 bytes, 1 callers */

undefined4 FUN_007d0bf4(CWnd *param_1)

{
  POINT pt;
  SHORT SVar1;
  DWORD DVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  BOOL BVar5;
  DWORD DVar6;
  int in_ECX;
  tagMSG local_20;
  
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  SVar1 = GetKeyState(1);
  if (SVar1 < 0) {
    *(uint *)(in_ECX + 0x3c) = *(uint *)(in_ECX + 0x3c) | 1;
    *(uint *)(in_ECX + 0x38) = *(uint *)(in_ECX + 0x38) | 2;
  }
  else {
    SVar1 = GetKeyState(2);
    if (SVar1 < 0) {
      *(uint *)(in_ECX + 0x3c) = *(uint *)(in_ECX + 0x3c) | 2;
      *(uint *)(in_ECX + 0x38) = *(uint *)(in_ECX + 0x38) | 1;
    }
  }
  DVar2 = GetTickCount();
  pHVar3 = SetCapture(*(HWND *)(param_1 + 0x20));
  CWnd::FromHandle(pHVar3);
  while (*(int *)(in_ECX + 0x34) == 0) {
    pHVar3 = GetCapture();
    pCVar4 = CWnd::FromHandle(pHVar3);
    if (pCVar4 != param_1) break;
    BVar5 = PeekMessageW(&local_20,(HWND)0x0,0x200,0x209,1);
    if (BVar5 == 0) {
      BVar5 = PeekMessageW(&local_20,(HWND)0x0,0x100,0x109,1);
      if (BVar5 != 0) goto LAB_007d0ca0;
    }
    else {
LAB_007d0ca0:
      if ((((local_20.message == 0x202) || (local_20.message == 0x205)) ||
          (local_20.message == 0x201)) ||
         ((local_20.message == 0x204 || ((local_20.message == 0x100 && (local_20.wParam == 0x1b)))))
         ) break;
      pt.y = local_20.pt.y;
      pt.x = local_20.pt.x;
      BVar5 = PtInRect((RECT *)(in_ECX + 0x24),pt);
      *(uint *)(in_ECX + 0x34) = (uint)(BVar5 == 0);
    }
    DVar6 = GetTickCount();
    if (DAT_00a124cc < DVar6 - DVar2) {
      *(undefined4 *)(in_ECX + 0x34) = 1;
    }
  }
  ReleaseCapture();
  return *(undefined4 *)(in_ECX + 0x34);
}




/* vtable slots: COleDropSource[20] */
/* 007d0d15  QueryContinueDrag  53 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual long __thiscall COleDropSource::QueryContinueDrag(int,unsigned long)
   
   Library: Visual Studio 2015 Release */

long __thiscall COleDropSource::QueryContinueDrag(COleDropSource *this,int param_1,ulong param_2)

{
  long lVar1;
  
  if ((param_1 == 0) && ((*(uint *)(this + 0x38) & param_2) == 0)) {
    if ((*(uint *)(this + 0x3c) & param_2) == 0) {
      lVar1 = 0x40101 - (uint)(*(int *)(this + 0x34) != 0);
    }
    else {
      lVar1 = 0;
    }
  }
  else {
    *(undefined4 *)(this + 0x34) = 0;
    lVar1 = 0x40101;
  }
  return lVar1;
}



