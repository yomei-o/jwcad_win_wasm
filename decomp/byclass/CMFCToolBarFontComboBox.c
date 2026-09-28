/* CMFCToolBarFontComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarFontComboBox[1] */
/* 0082812f  FUN_0082812f  51 bytes, 0 callers */

void FUN_0082812f(byte param_1)

{
  FUN_00828079();
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




/* vtable slots: CMFCToolBarFontComboBox[60] */
/* 0082819b  FUN_0082819b  376 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0082819b(int param_1,undefined4 param_2,undefined4 param_3)

{
  short *psVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int in_ECX;
  byte bVar8;
  CObList *this;
  int local_28;
  undefined1 local_24 [4];
  int local_20;
  CObList *local_1c;
  CObject *local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x8281a7;
  local_1c = *(CObList **)(in_ECX + 0xfc);
  if (local_1c == (CObList *)0x0) {
    local_1c = (CObList *)&DAT_00a13a00;
  }
  this = local_1c;
  if (*(char *)(param_1 + 0x17) != 'M') {
    uVar3 = CONCAT22(0x94,CONCAT11(*(byte *)(param_1 + 0x1b),*(byte *)(in_ECX + 0xf9))) & 0xffff0ff0
    ;
    bVar8 = *(byte *)(in_ECX + 0xf9) & 0xf;
    if (((bVar8 == 0) || (bVar8 == (byte)(uVar3 >> 8))) &&
       ((bVar8 = (byte)uVar3, bVar8 == 0 || (bVar8 == (*(byte *)(param_1 + 0x1b) & 0xf0))))) {
      local_14[0] = *(int *)(local_1c + 4);
      psVar1 = (short *)(param_1 + 0x1c);
      do {
        if (local_14[0] == 0) {
          iVar5 = GetSystemMetrics(0x2a);
          if ((iVar5 != 0) && (*psVar1 == 0x40)) {
            return 0;
          }
          local_28 = FUN_0078e624(0x14);
          local_18 = (CObject *)0x0;
          local_8 = 0;
          if (local_28 != 0) {
            local_18 = (CObject *)
                       CMFCFontInfo(psVar1,param_3,*(undefined1 *)(param_1 + 0x17),
                                    *(undefined1 *)(param_1 + 0x1b),param_2);
          }
          local_14[0] = *(int *)(this + 4);
          local_8 = 0xffffffff;
          do {
            local_20 = local_14[0];
            if (local_14[0] == 0) {
              CObList::AddTail(this,local_18);
              return 1;
            }
            FUN_0044f2d0(local_14);
            uVar6 = FUN_00828579(&local_28);
            local_8 = 1;
            uVar7 = FUN_00828579(local_24);
            cVar2 = FUN_008280d5(uVar7,uVar6);
            FUN_00406b10();
            local_8 = 0xffffffff;
            FUN_00406b10();
            this = local_1c;
          } while (cVar2 == '\0');
          InsertBefore(local_20,local_18);
          return 1;
        }
        piVar4 = (int *)FUN_0044f2d0(local_14);
        cVar2 = FUN_00481200(*piVar4 + 4,psVar1);
      } while (cVar2 == '\0');
    }
  }
  return 0;
}




/* vtable slots: CMFCToolBarFontComboBox[5] */
/* 0082834d  CopyFrom  58 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarFontComboBox::CopyFrom(class CMFCToolBarButton
   const &)
   
   Library: Visual Studio 2012 Release */

void __thiscall
CMFCToolBarFontComboBox::CopyFrom(CMFCToolBarFontComboBox *this,CMFCToolBarButton *param_1)

{
  FUN_00825aeb(param_1);
  this[0xf8] = *(CMFCToolBarFontComboBox *)(param_1 + 0xf8);
  *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
  this[0xf9] = *(CMFCToolBarFontComboBox *)(param_1 + 0xf9);
  return;
}




/* vtable slots: CMFCToolBarFontComboBox[53] */
/* 00828387  FUN_00828387  128 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00828387(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  CMFCFontComboBox *this;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  this = (CMFCFontComboBox *)FUN_0078e624(0x90);
  piVar3 = (int *)0x0;
  if (this != (CMFCFontComboBox *)0x0) {
    piVar3 = (int *)CMFCFontComboBox::CMFCFontComboBox(this);
  }
  pcVar1 = *(code **)(*piVar3 + 0x164);
  guard_check_icall(*(uint *)(in_ECX + 0x8c) | 0x210,param_2,param_1,*(undefined4 *)(in_ECX + 0x20))
  ;
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*piVar3 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    piVar3 = (int *)0x0;
  }
  return piVar3;
}




/* vtable slots: CMFCToolBarFontComboBox[0] */
/* 00828611  FUN_00828611  6 bytes, 0 callers */

undefined ** FUN_00828611(void)

{
  return &PTR_s_CMFCToolBarFontComboBox_00a00834;
}




/* vtable slots: CMFCToolBarFontComboBox[2] */
/* 008286e8  FUN_008286e8  245 bytes, 0 callers */

void FUN_008286e8(CArchive *param_1)

{
  long *plVar1;
  int in_ECX;
  
  FUN_008829ae(param_1);
  plVar1 = (long *)(in_ECX + 0x74);
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x70));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x8c));
    CArchive::operator<<(param_1,*plVar1);
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0xb8));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x78));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0xf4));
    CArchive::operator<<(param_1,*(uchar *)(in_ECX + 0xf8));
  }
  else {
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x70));
    *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x54) + *(int *)(in_ECX + 0x70);
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x8c));
    CArchive::operator>>(param_1,plVar1);
    FUN_0047fc90(in_ECX + 0xb8);
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x78));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0xf4));
    CArchive::operator>>(param_1,(uchar *)(in_ECX + 0xf8));
    if (DAT_00a13a0c == 0) {
      FUN_0082861d();
    }
    FUN_008287dd();
    FUN_008279e7(*plVar1,1);
  }
  return;
}



