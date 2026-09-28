/* CRecentFileList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRecentFileList[7] */
/* 007c723a  `scalar_deleting_destructor'  34 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CRecentFileList::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CRecentFileList::_scalar_deleting_destructor_(CRecentFileList *this,uint param_1)

{
  ~CRecentFileList(this);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x20);
  }
  return this;
}




/* vtable slots: CRecentFileList[1] */
/* 007c72b9  FUN_007c72b9  208 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007c72b9(undefined4 param_1,undefined2 *param_2)

{
  code *pcVar1;
  int iVar2;
  CRecentFileList *in_ECX;
  wchar_t *local_18;
  IShellItem *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7c72c5;
  iVar2 = FUN_0079dd6d();
  if ((*(int *)(iVar2 + 4) == 0) || (iVar2 = FUN_007a393a(), iVar2 == 0)) {
    pcVar1 = *(code **)(*(int *)in_ECX + 8);
    guard_check_icall(param_1);
    (*pcVar1)();
    return;
  }
  if (param_2 == (undefined2 *)0x0) {
    param_2 = &DAT_00956338;
  }
  CStringT<>(param_2);
  local_8 = 0;
  pcVar1 = *(code **)(*(int *)in_ECX + 8);
  guard_check_icall(param_1);
  (*pcVar1)();
  local_14[0] = (IShellItem *)0x0;
  local_8._0_1_ = 2;
  iVar2 = FUN_007c4e13(param_1,0,&DAT_009a9b8c,local_14);
  if (-1 < iVar2) {
    CRecentFileList::Add(in_ECX,local_14[0],local_18);
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_14[0] != (IShellItem *)0x0) {
      pcVar1 = *(code **)(*(int *)local_14[0] + 8);
      guard_check_icall(local_14[0]);
      (*pcVar1)();
    }
    FUN_00406b10();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CRecentFileList[2] */
/* 007c738a  FUN_007c738a  197 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007c738a(LPCVOID param_1)

{
  CSimpleStringT<wchar_t,0> *pCVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  wchar_t local_210 [260];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((param_1 == (LPCVOID)0x0) || (uVar2 = FUN_008f899d(param_1), 0x103 < uVar2)) {
                    /* WARNING: Subroutine does not return */
    FUN_007a6c8a(3,0xffffffff,0);
  }
  FUN_007a7361(local_210,param_1);
  iVar4 = 0;
  if (*(int *)(in_ECX + 4) != 1 && -1 < *(int *)(in_ECX + 4) + -1) {
    do {
      iVar3 = FUN_007a7278(*(undefined4 *)(*(int *)(in_ECX + 8) + iVar4 * 4),local_210);
      if (iVar3 != 0) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 4) + -1);
    for (; 0 < iVar4; iVar4 = iVar4 + -1) {
      pCVar1 = (CSimpleStringT<wchar_t,0> *)(*(int *)(in_ECX + 8) + iVar4 * 4);
      ATL::CSimpleStringT<wchar_t,0>::operator=(pCVar1,pCVar1 + -4);
    }
  }
  pCVar1 = *(CSimpleStringT<wchar_t,0> **)(in_ECX + 8);
  iVar4 = FUN_008f899d(local_210);
  ATL::CSimpleStringT<wchar_t,0>::SetString(pCVar1,local_210,iVar4);
  SHAddToRecentDocs(3,param_1);
  return;
}




/* vtable slots: CRecentFileList[3] */
/* 007c7450  FUN_007c7450  466 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007c7450(CSimpleStringT<char,0> *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  char *pcVar1;
  undefined2 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  undefined1 local_210 [520];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (((param_3 != 0) && (iVar3 = FUN_007c110d(param_3,param_4), iVar3 == 0)) ||
     (*(int *)(in_ECX + 4) <= param_2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((param_3 == 0) ||
     (iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + param_2 * 4) + -0xc), iVar3 == 0)) {
    return 0;
  }
  pcVar4 = ATL::CSimpleStringT<char,0>::PrepareWrite(param_1,iVar3 + 1);
  if (pcVar4 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e73e();
  }
  uVar5 = FUN_008f8e5e(pcVar4,iVar3 + 1,*(undefined4 *)(*(int *)(in_ECX + 8) + param_2 * 4),
                       0xffffffff);
  FUN_00404bd0(uVar5);
  iVar6 = FUN_007c60f4(pcVar4,0,0);
  iVar8 = (iVar3 - iVar6) + 1;
  iVar6 = iVar8 * 2;
  if (iVar8 == param_4) {
    uVar2 = *(undefined2 *)(pcVar4 + iVar6);
    pcVar1 = pcVar4 + param_4 * 2;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    iVar7 = FUN_007a7278(param_3,pcVar4);
    *(undefined2 *)(pcVar4 + iVar6) = uVar2;
    if (iVar7 != 0) {
      FUN_007a7375(pcVar1,local_210,0x104);
      uVar5 = FUN_008f8e5e(pcVar4,iVar3 + 1,local_210,0xffffffff);
      FUN_00404bd0(uVar5);
      goto LAB_007c75f3;
    }
  }
  if (*(int *)(in_ECX + 0x18) != -1) {
    FUN_007a7375(pcVar4 + iVar6,local_210,0x104);
    uVar5 = FUN_008f8e5e(pcVar4 + iVar6,(iVar3 - iVar8) + 1,local_210,0xffffffff);
    FUN_00404bd0(uVar5);
    FUN_007c7ac2(pcVar4,*(undefined4 *)(in_ECX + 0x18),param_5);
  }
LAB_007c75f3:
  ReleaseBuffer(0xffffffff);
  return 1;
}




/* vtable slots: CRecentFileList[5] */
/* 007c7623  FUN_007c7623  191 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007c7623(void)

{
  code *pcVar1;
  wchar_t *_Dest;
  int iVar2;
  CSimpleStringT<wchar_t,0> *pCVar3;
  int in_ECX;
  undefined1 local_24 [4];
  wchar_t *local_20;
  int local_1c;
  int *local_18;
  wchar_t *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x7c762f;
  local_20 = (wchar_t *)(*(int *)(*(int *)(in_ECX + 0x10) + -0xc) + 10);
  _Dest = (wchar_t *)
          FUN_0078e661(-(uint)((int)(ZEXT48(local_20) * 2 >> 0x20) != 0) |
                       (uint)(ZEXT48(local_20) * 2));
  local_14 = _Dest;
  iVar2 = FUN_0079dd6d();
  local_18 = *(int **)(iVar2 + 4);
  local_1c = 0;
  if (0 < *(int *)(in_ECX + 4)) {
    do {
      iVar2 = local_1c + 1;
      FID_conflict__swprintf(_Dest,local_20,*(undefined4 *)(in_ECX + 0x10),iVar2);
      pcVar1 = *(code **)(*local_18 + 0x84);
      guard_check_icall(local_24,*(undefined4 *)(in_ECX + 0xc),local_14,&DAT_00956338);
      pCVar3 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
      local_8 = 0;
      ATL::CSimpleStringT<wchar_t,0>::operator=
                ((CSimpleStringT<wchar_t,0> *)(*(int *)(in_ECX + 8) + local_1c * 4),pCVar3);
      local_8 = 0xffffffff;
      FUN_00406b10();
      _Dest = local_14;
      local_1c = iVar2;
    } while (iVar2 < *(int *)(in_ECX + 4));
  }
  thunk_FUN_008f43b0(_Dest);
  return;
}




/* vtable slots: CRecentFileList[0] */
/* 007c76e2  FUN_007c76e2  72 bytes, 0 callers */

void FUN_007c76e2(int param_1)

{
  CSimpleStringT<wchar_t,0> *this;
  int in_ECX;
  
  if ((-1 < param_1) && (param_1 < *(int *)(in_ECX + 4))) {
    Empty();
    for (; this = (CSimpleStringT<wchar_t,0> *)(*(int *)(in_ECX + 8) + param_1 * 4),
        param_1 < *(int *)(in_ECX + 4) + -1; param_1 = param_1 + 1) {
      ATL::CSimpleStringT<wchar_t,0>::operator=(this,this + 4);
    }
    Empty();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CRecentFileList[4] */
/* 007c772b  FUN_007c772b  743 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007c772b(int *param_1)

{
  short sVar1;
  code *pcVar2;
  UINT_PTR uIDNewItem;
  UINT uPosition;
  LPCWSTR lpNewItem;
  DWORD DVar3;
  int iVar4;
  short *psVar5;
  uint uVar6;
  errno_t eVar7;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *pCVar8;
  undefined4 *puVar9;
  int *in_ECX;
  short *psVar10;
  int iVar11;
  wchar_t *pwVar12;
  int in_stack_fffffda4;
  UINT in_stack_fffffda8;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_248 [4];
  int local_244;
  short *local_240;
  int *local_23c;
  int local_238;
  int local_234;
  WCHAR local_230 [260];
  wchar_t local_28 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_8 = 0x7c773a;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar11 = 0;
  local_238 = 0;
  local_23c = in_ECX;
  if ((*(int *)(in_ECX[7] + -0xc) == 0) && (param_1[3] != 0)) {
    FID_conflict_GetMenuStringA
              ((HMENU)param_1[1],(UINT)(in_ECX + 7),(LPSTR)0x0,in_stack_fffffda4,in_stack_fffffda8);
  }
  if (*(int *)(*(int *)in_ECX[2] + -0xc) == 0) {
    if (*(int *)(in_ECX[7] + -0xc) != 0) {
      pcVar2 = *(code **)(*param_1 + 0xc);
      guard_check_icall(in_ECX[7]);
      (*pcVar2)();
    }
    pcVar2 = *(code **)*param_1;
    guard_check_icall(0);
    (*pcVar2)();
  }
  else if (param_1[3] != 0) {
    local_234 = 0;
    if (0 < in_ECX[1]) {
      do {
        DeleteMenu(*(HMENU *)(param_1[3] + 4),param_1[1] + local_234,0);
        local_234 = local_234 + 1;
      } while (local_234 < in_ECX[1]);
    }
    DVar3 = GetCurrentDirectoryW(0x104,local_230);
    if ((DVar3 != 0) && (DVar3 < 0x104)) {
      local_244 = FUN_008f899d(local_230);
      local_230[local_244] = L'\\';
      local_244 = local_244 + 1;
      if (0x207 < (uint)(local_244 * 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_008d927f();
      }
      local_230[local_244] = L'\0';
      CStringT<>();
      local_8 = 0;
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      if (0 < in_ECX[1]) {
        do {
          pcVar2 = *(code **)(*in_ECX + 0xc);
          guard_check_icall(&local_240,iVar11,local_230,local_244,1);
          iVar4 = (*pcVar2)();
          psVar10 = local_240;
          if (iVar4 == 0) break;
          psVar5 = (short *)ATL::CSimpleStringT<char,0>::PrepareWrite
                                      ((CSimpleStringT<char,0> *)&local_234,
                                       *(int *)(local_240 + -6) * 2);
          sVar1 = *psVar10;
          while (sVar1 != 0) {
            if (sVar1 == 0x26) {
              *psVar5 = 0x26;
              psVar5 = psVar5 + 1;
              sVar1 = *psVar10;
            }
            psVar10 = psVar10 + 1;
            *psVar5 = sVar1;
            psVar5 = psVar5 + 1;
            iVar11 = local_238;
            sVar1 = *psVar10;
          }
          *psVar5 = 0;
          ReleaseBuffer(0xffffffff);
          uVar6 = (local_23c[5] + iVar11 & 0xfU) + 1;
          if (uVar6 < 0xb) {
            if (uVar6 != 10) {
              pwVar12 = L"&%d ";
              goto LAB_007c7933;
            }
            eVar7 = _wcscpy_s(local_28,10,L"1&0 ");
            FUN_00404bd0(eVar7);
          }
          else {
            pwVar12 = L"%d ";
LAB_007c7933:
            FID_conflict__swprintf(local_28,(wchar_t *)0xa,pwVar12,uVar6);
          }
          iVar11 = param_1[3];
          pCVar8 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *)
                   CStringT<>(local_28);
          local_8._0_1_ = 2;
          puVar9 = (undefined4 *)ATL::operator+(local_248,pCVar8);
          uIDNewItem = param_1[1];
          uPosition = param_1[2];
          lpNewItem = (LPCWSTR)*puVar9;
          param_1[1] = uIDNewItem + 1;
          param_1[2] = uPosition + 1;
          InsertMenuW(*(HMENU *)(iVar11 + 4),uPosition,0x400,uIDNewItem,lpNewItem);
          FUN_00406b10();
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_00406b10();
          iVar11 = local_238 + 1;
          in_ECX = local_23c;
          local_238 = iVar11;
        } while (iVar11 < local_23c[1]);
      }
      param_1[2] = param_1[2] + -1;
      iVar11 = GetMenuItemCount(*(HMENU *)(param_1[3] + 4));
      param_1[8] = iVar11;
      param_1[6] = 1;
      FUN_00406b10();
      FUN_00406b10();
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CRecentFileList[6] */
/* 007c7a13  FUN_007c7a13  175 bytes, 0 callers */

void FUN_007c7a13(void)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  longlong lVar4;
  wchar_t *_Format;
  wchar_t *_Dest;
  int iVar5;
  int in_ECX;
  
  _Format = (wchar_t *)(*(int *)(*(int *)(in_ECX + 0x10) + -0xc) + 10);
  lVar4 = ZEXT48(_Format) * 2;
  _Dest = (wchar_t *)FUN_0078e661(-(uint)((int)((ulonglong)lVar4 >> 0x20) != 0) | (uint)lVar4);
  iVar5 = FUN_0079dd6d();
  piVar2 = *(int **)(iVar5 + 4);
  pcVar3 = *(code **)(*piVar2 + 0x88);
  guard_check_icall(*(undefined4 *)(in_ECX + 0xc),0,0);
  (*pcVar3)();
  iVar5 = 0;
  if (0 < *(int *)(in_ECX + 4)) {
    do {
      iVar1 = iVar5 + 1;
      FID_conflict__swprintf(_Dest,_Format,*(undefined4 *)(in_ECX + 0x10),iVar1);
      iVar5 = *(int *)(*(int *)(in_ECX + 8) + iVar5 * 4);
      if (*(int *)(iVar5 + -0xc) != 0) {
        pcVar3 = *(code **)(*piVar2 + 0x88);
        guard_check_icall(*(undefined4 *)(in_ECX + 0xc),_Dest,iVar5);
        (*pcVar3)();
      }
      iVar5 = iVar1;
    } while (iVar1 < *(int *)(in_ECX + 4));
  }
  thunk_FUN_008f43b0(_Dest);
  return;
}



