/* CMFCImagePaintArea -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCImagePaintArea[1] */
/* 008c7c87  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCImagePaintArea::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCImagePaintArea::_scalar_deleting_destructor_(CMFCImagePaintArea *this,uint param_1)

{
  ~CMFCImagePaintArea(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xf8);
    }
  }
  return this;
}




/* vtable slots: CMFCImagePaintArea[90] */
/* 008c7d1b  FUN_008c7d1b  661 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008c7d1b(int param_1)

{
  ulong uVar1;
  CDC *pCVar2;
  int iVar3;
  HBRUSH hbr;
  COLORREF CVar4;
  int iVar5;
  void *pvVar6;
  undefined **local_68 [2];
  undefined1 local_60 [4];
  CGdiObject *local_5c;
  int local_58;
  int local_54;
  int local_50;
  CDC *local_4c;
  int local_48;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x8c7d27;
  pCVar2 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  local_4c = pCVar2;
  CopyRect(&local_24,(RECT *)(param_1 + 0x1c));
  iVar3 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar3 != -0x98) {
    hbr = *(HBRUSH *)(iVar3 + 0x9c);
  }
  FillRect(*(HDC *)(pCVar2 + 4),&local_24,hbr);
  InflateRect(&local_24,-1,-1);
  local_44.left = local_24.left;
  local_44.top = local_24.top;
  local_44.right = *(int *)(local_50 + 0xa4) * *(int *)(local_50 + 200) + local_24.left;
  local_44.bottom = *(int *)(local_50 + 0xa8) * *(int *)(local_50 + 0xcc) + local_24.top;
  local_24.right = local_44.right;
  local_24.bottom = local_44.bottom;
  InflateRect(&local_24,1,1);
  iVar3 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar3 + 0x24);
  iVar3 = FUN_007c2511();
  CDC::Draw3dRect(local_4c,&local_44,*(ulong *)(iVar3 + 0x30),uVar1);
  iVar3 = FUN_007c2511();
  FUN_0079df60(0,1,*(undefined4 *)(iVar3 + 0x20));
  local_8 = 0;
  local_54 = FUN_0079efbc(local_68);
  iVar3 = local_50;
  iVar5 = local_44.left + *(int *)(local_50 + 200);
  local_48 = local_44.top;
  if (iVar5 <= local_44.right - *(int *)(local_50 + 200)) {
    do {
      local_48 = iVar5;
      FUN_0079ec58(local_60,iVar5,local_44.top + 1);
      CDC::LineTo(local_4c,local_48,local_44.bottom + -1);
      iVar5 = local_48 + *(int *)(iVar3 + 200);
      local_48 = local_44.top;
    } while (iVar5 <= local_44.right - *(int *)(iVar3 + 200));
  }
  while (local_48 = local_48 + *(int *)(iVar3 + 0xcc),
        local_48 <= local_44.bottom - *(int *)(iVar3 + 0xcc)) {
    FUN_0079ec58(local_60,local_44.left + 1,local_48);
    CDC::LineTo(local_4c,local_44.right + -1,local_48);
  }
  FUN_0079efbc(local_54);
  if (*(int *)(iVar3 + 0xac) != 0) {
    local_5c = CDC::SelectGdiObject
                         (*(HDC__ **)(iVar3 + 0x98),*(void **)(*(int *)(iVar3 + 0xac) + 4));
    local_48 = 0;
    if (0 < *(int *)(iVar3 + 0xa4)) {
      do {
        local_54 = 0;
        if (0 < *(int *)(iVar3 + 0xa8)) {
          do {
            CVar4 = GetPixel(*(HDC *)(iVar3 + 0x98),local_48,local_54);
            local_58 = FUN_007eabe8(CVar4,0);
            if (local_58 != -1) {
              local_34.left = *(int *)(local_50 + 200) * local_48 + local_44.left;
              local_34.top = *(int *)(local_50 + 0xcc) * local_54 + local_44.top;
              local_34.right = local_34.left + *(int *)(iVar3 + 200);
              local_34.bottom = local_34.top + *(int *)(iVar3 + 0xcc);
              InflateRect(&local_34,-1,-1);
              FUN_007a506d(&local_34,local_58);
              iVar3 = local_50;
            }
            local_54 = local_54 + 1;
          } while (local_54 < *(int *)(iVar3 + 0xa8));
        }
        local_48 = local_48 + 1;
      } while (local_48 < *(int *)(iVar3 + 0xa4));
    }
    pvVar6 = (void *)0x0;
    if (local_5c != (CGdiObject *)0x0) {
      pvVar6 = *(void **)(local_5c + 4);
    }
    CDC::SelectGdiObject(*(HDC__ **)(iVar3 + 0x98),pvVar6);
  }
  local_68[0] = CPen::vftable;
  FUN_00416100();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCImagePaintArea[10] */
/* 008c81e5  FUN_008c81e5  6 bytes, 0 callers */

undefined ** FUN_008c81e5(void)

{
  return &PTR_FUN_009a5138;
}




/* vtable slots: CMFCImagePaintArea[20] */
/* 008c8b6a  PreSubclassWindow  197 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCImagePaintArea::PreSubclassWindow(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCImagePaintArea::PreSubclassWindow(CMFCImagePaintArea *this)

{
  int iVar1;
  HCURSOR pHVar2;
  
  FUN_0079dd6d();
  iVar1 = FUN_0079dd6d();
  pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3f10);
  *(HCURSOR *)(this + 0xb0) = pHVar2;
  FUN_0079dd6d();
  iVar1 = FUN_0079dd6d();
  pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3f0e);
  *(HCURSOR *)(this + 0xb4) = pHVar2;
  FUN_0079dd6d();
  iVar1 = FUN_0079dd6d();
  pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3f0f);
  *(HCURSOR *)(this + 0xb8) = pHVar2;
  FUN_0079dd6d();
  iVar1 = FUN_0079dd6d();
  pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3f0c);
  *(HCURSOR *)(this + 0xbc) = pHVar2;
  FUN_0079dd6d();
  iVar1 = FUN_0079dd6d();
  pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3f0d);
  *(HCURSOR *)(this + 0xc0) = pHVar2;
  FUN_0079dd6d();
  iVar1 = FUN_0079dd6d();
  pHVar2 = LoadCursorW(*(HINSTANCE *)(iVar1 + 0xc),(LPCWSTR)0x3f11);
  *(HCURSOR *)(this + 0xc4) = pHVar2;
  guard_check_icall();
  return;
}



