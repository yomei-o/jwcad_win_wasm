/* CJw_winApp -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CJw_winApp[1] */
/* 004dafe0  FUN_004dafe0  68 bytes, 0 callers */

undefined4 FUN_004dafe0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004da380();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x79d0);
    }
  }
  return in_ECX;
}




/* vtable slots: CJw_winApp[62], CWinApp[62] */
/* 004ddc00  FUN_004ddc00  16 bytes, 0 callers */

undefined4 FUN_004ddc00(void)

{
  return 5000;
}




/* vtable slots: CJw_winApp[10] */
/* 004de210  FUN_004de210  16 bytes, 0 callers */

void FUN_004de210(void)

{
  FUN_004de230();
  return;
}




/* vtable slots: CJw_winApp[20] */
/* 004de2f0  FUN_004de2f0  2387 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004de2f0(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  LPCWSTR lpLibFileName;
  HMODULE pHVar5;
  FARPROC pFVar6;
  int in_ECX;
  CCommandLineInfo local_708 [72];
  int local_6c0;
  DWORD local_6b8;
  DWORD local_6b4;
  DWORD local_6b0;
  DWORD local_6ac;
  wchar_t *local_6a8;
  undefined4 local_6a4;
  undefined4 local_6a0;
  undefined4 local_69c;
  undefined4 local_698;
  int local_694;
  wchar_t *local_690;
  undefined4 local_68c;
  undefined4 local_688;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_684 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_680 [4];
  undefined4 local_67c;
  undefined4 local_678;
  wchar_t *local_674;
  wchar_t *local_670;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_66c [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_668 [4];
  undefined4 local_664;
  undefined4 local_660;
  wchar_t *local_65c;
  wchar_t *local_658;
  undefined4 local_650;
  undefined4 local_64c;
  undefined4 local_648;
  undefined1 local_644 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_640 [4];
  undefined4 local_63c;
  undefined4 local_638;
  undefined4 local_634;
  int local_630;
  int local_62c;
  int local_628;
  int local_624;
  FARPROC local_620;
  int local_61c;
  HMODULE local_618;
  int local_614;
  undefined1 local_610 [4];
  CSimpleStringT<wchar_t,0> local_60c [8];
  int local_604;
  CHAR local_600 [2];
  char cStack_5fe;
  WCHAR local_218 [258];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009280e6;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_604 = in_ECX;
  local_14 = uVar2;
  CStringT<>(*(undefined4 *)(in_ECX + 0x68));
  local_8 = 0;
  local_624 = ReverseFind(0x5c);
  if (0 < local_624) {
    local_6a8 = (wchar_t *)Left(local_644,local_624 + 1);
    local_8._0_1_ = 1;
    local_690 = local_6a8;
    local_63c = ATL::operator+(local_640,local_6a8);
    local_8._0_1_ = 2;
    local_638 = local_63c;
    FUN_00404860(local_63c);
    local_8._0_1_ = 1;
    FUN_00404540();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
  }
  FUN_008f43b0(*(undefined4 *)(local_604 + 0x68),uVar2);
  uVar3 = FUN_00404920();
  uVar3 = FUN_0090479f(uVar3);
  *(undefined4 *)(local_604 + 0x68) = uVar3;
  local_648 = *(undefined4 *)(local_604 + 0x48);
  iVar4 = FUN_00430240(local_648,L"/INIT");
  if ((iVar4 != 0) && (iVar4 = FUN_0079f557(&DAT_009620c8,1,0), iVar4 == 1)) {
    DAT_00a08ad8 = 1;
  }
  FUN_007a3a4a(0x66);
  FUN_004dec90();
  CStringT<>();
  local_8._0_1_ = 3;
  local_650 = FUN_005977f0(0x1833);
  local_8._0_1_ = 4;
  local_64c = local_650;
  FUN_00404860(local_650);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_00404770();
  iVar4 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(local_60c);
  if (iVar4 == 1) {
    uVar1 = FUN_004473c0(0);
    *(undefined2 *)(local_604 + 0x2f4) = uVar1;
  }
  FUN_004dbc90();
  FUN_004dbf00(0);
  FUN_005d1aa0();
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_00404900(L"Text|*.TXT|Bitmap|*.BMP|");
  *(undefined4 *)(local_604 + 0x2cc) = 0;
  FUN_005d1b50();
LAB_004de553:
  do {
    if (local_6c0 == 0) {
LAB_004de8a8:
      pHVar5 = LoadLibraryW(L".\\common_lib.dll");
      *(HMODULE *)(local_604 + 0x2d4) = pHVar5;
      if (*(int *)(local_604 + 0x2d4) == 0) {
        local_6b4 = GetLastError();
        MessageBoxW((HWND)0x0,L"can\'t open common_lib.dll",(LPCWSTR)0x0,0);
      }
      pHVar5 = LoadLibraryW(L".\\common_lib_AP202.dll");
      *(HMODULE *)(local_604 + 0x2d8) = pHVar5;
      if (*(int *)(local_604 + 0x2d8) == 0) {
        local_6b8 = GetLastError();
        MessageBoxW((HWND)0x0,L"can\'t open common_lib_AP202.dll",(LPCWSTR)0x0,0);
      }
      pHVar5 = LoadLibraryW(L"user32.dll");
      *(HMODULE *)(local_604 + 0x2f0) = pHVar5;
      if (*(int *)(local_604 + 0x2f0) == 0) {
        local_6ac = GetLastError();
        *(undefined4 *)(local_604 + 0x2ec) = 0;
      }
      else {
        pFVar6 = GetProcAddress(*(HMODULE *)(local_604 + 0x2f0),"SetLayeredWindowAttributes");
        *(FARPROC *)(local_604 + 0x2ec) = pFVar6;
      }
      if (*(int *)(local_604 + 0x2ec) == 0) {
        local_6b0 = GetLastError();
      }
      iVar4 = AfxOleInit();
      if (iVar4 == 0) {
        FUN_004f60a0(0x68,0,0xffffffff);
        local_688 = 0;
        local_8._0_1_ = 3;
        FUN_005d1ae0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
        local_8 = 0xffffffff;
        FUN_00404540();
      }
      else {
        FUN_004dd210();
        FUN_007b16c4(10);
        local_630 = FUN_004121b0(0x8c);
        local_8._0_1_ = 0xb;
        if (local_630 == 0) {
          local_634 = 0;
        }
        else {
          local_634 = FUN_007b318f(0x140,&PTR_s_CJw_winDoc_009ffb9c,&PTR_s_CMainFrame_0096a270,
                                   &PTR_s_CJw_winView_00963ef8);
        }
        local_68c = local_634;
        local_8 = CONCAT31(local_8._1_3_,5);
        local_6a4 = local_634;
        FUN_007b233a(local_634);
        uVar2 = FUN_007a36e9(L"Init",&DAT_0096220c,0);
        if (uVar2 < 6) {
          local_694 = 0;
          iVar4 = FUN_004ee740();
          if (((iVar4 != 0) || (local_694 != 0)) &&
             (iVar4 = FUN_004f60a0(0x27a2,1,0xffffffff), iVar4 == 1)) {
            uVar3 = FUN_00404920();
            FUN_004eea00(uVar3);
          }
        }
        *(undefined4 *)(local_604 + 0x4c) = 3;
        FUN_007b0c2f();
        local_8._0_1_ = 0xc;
        FUN_007b181b(local_708);
        iVar4 = FUN_007b257b(local_708);
        if (iVar4 == 0) {
          local_698 = 0;
          local_8._0_1_ = 5;
          CCommandLineInfo::~CCommandLineInfo(local_708);
          local_8._0_1_ = 3;
          FUN_005d1ae0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00404540();
          local_688 = local_698;
        }
        else {
          FUN_004dd1a0(1);
          local_69c = *(undefined4 *)(local_604 + 0x4c);
          FUN_005668c0(local_69c);
          local_6a0 = 1;
          local_8._0_1_ = 5;
          CCommandLineInfo::~CCommandLineInfo(local_708);
          local_8._0_1_ = 3;
          FUN_005d1ae0();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00404540();
          local_688 = local_6a0;
        }
      }
      ExceptionList = local_10;
      return local_688;
    }
    FUN_005d1ca0(local_610);
    local_8._0_1_ = 6;
    lpLibFileName = (LPCWSTR)FUN_00404920();
    local_618 = LoadLibraryW(lpLibFileName);
    if (local_618 != (HMODULE)0x0) {
      local_620 = GetProcAddress(local_618,"GetPluginInfo");
      local_61c = (*local_620)(0,local_600,999);
      if ((local_61c == 0) || (cStack_5fe != 'I')) {
        FreeLibrary(local_618);
        local_8 = CONCAT31(local_8._1_3_,5);
        FUN_00404540();
      }
      else {
        local_614 = 2;
        while (local_61c = (*local_620)(local_614 + 1,local_600,999), local_61c != 0) {
          local_628 = MultiByteToWideChar(0,0,local_600,-1,local_218,0x202);
          iVar4 = FUN_00429b90(local_218,0);
          if (iVar4 < 0) {
            local_65c = (wchar_t *)ATL::operator+(local_66c,(wchar_t *)(local_604 + 0x138));
            local_8._0_1_ = 7;
            local_658 = local_65c;
            local_664 = ATL::operator+(local_668,local_65c);
            local_8._0_1_ = 8;
            local_660 = local_664;
            FUN_00404860(local_664);
            local_8._0_1_ = 7;
            FUN_00404540();
            local_8._0_1_ = 6;
            FUN_00404540();
            local_628 = (*local_620)(local_614,local_600,999);
            local_628 = MultiByteToWideChar(0,0,local_600,-1,local_218,0x202);
            local_674 = (wchar_t *)ATL::operator+(local_684,(wchar_t *)(local_604 + 0x138));
            local_8._0_1_ = 9;
            local_670 = local_674;
            local_67c = ATL::operator+(local_680,local_674);
            local_8._0_1_ = 10;
            local_678 = local_67c;
            FUN_00404860(local_67c);
            local_8._0_1_ = 9;
            FUN_00404540();
            local_8._0_1_ = 6;
            FUN_00404540();
          }
          local_614 = local_614 + 2;
        }
        *(HMODULE *)(local_604 + 0x13c + *(int *)(local_604 + 0x2cc) * 4) = local_618;
        local_62c = *(int *)(local_604 + 0x2cc) + 1;
        *(int *)(local_604 + 0x2cc) = local_62c;
        if (99 < local_62c) {
          local_8 = CONCAT31(local_8._1_3_,5);
          FUN_00404540();
          goto LAB_004de8a8;
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        FUN_00404540();
      }
      goto LAB_004de553;
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_00404540();
  } while( true );
}




/* vtable slots: CJw_winApp[24] */
/* 004e8ca0  FUN_004e8ca0  178 bytes, 0 callers */

/* WARNING: Removing unreachable block (ram,0x004e8d17) */

undefined4 FUN_004e8ca0(int param_1)

{
  undefined4 local_c;
  
  local_c = FUN_007b175d(param_1);
  if (param_1 == 0) {
    local_c = 1;
    FUN_00406bc0(0x111,0x86,0);
    DAT_00a101b4 = DAT_00a101b4 + 1;
    if (100 < DAT_00a101b4) {
      DAT_00a101b4 = 0;
      FUN_004e1290();
    }
  }
  return local_c;
}




/* vtable slots: CJw_winApp[41] */
/* 004e8d60  FUN_004e8d60  2447 bytes, 7 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_004e8d60(undefined2 *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_6964 [12];
  int *local_6958;
  int *local_6954;
  undefined4 local_6950;
  undefined4 local_694c;
  int *local_6948;
  int *local_6944;
  undefined1 local_6940 [4];
  undefined4 local_693c;
  undefined4 local_6938;
  int local_6934;
  int *local_6930;
  int local_692c;
  int *local_6928;
  undefined4 local_6920;
  undefined4 local_691c;
  undefined4 local_6914;
  int *local_6910;
  int local_690c;
  int *local_6908;
  int *local_6900;
  int local_68f8;
  undefined4 local_68f4;
  int local_68f0;
  uint local_68ec;
  char local_68e2;
  char local_68e1;
  undefined1 local_68dc [4];
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> local_68d8 [4];
  int *local_68d4;
  int local_68d0;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928823;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_68ec = 0;
  if (0 < DAT_00a0ef7c) {
    return (int *)0x0;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x79c8) = 0;
  local_68d0 = in_ECX;
  FUN_00404900();
  CStringT<>();
  local_8 = 0;
  FUN_004059f0();
  local_694c = ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::Right
                         (local_68d8,(int)local_6964);
  local_68e2 = FUN_00447350();
  FUN_00404540();
  if ((local_68e2 != '\0') && (iVar2 = FUN_004bf150(), iVar2 != 0)) {
    param_1 = (undefined2 *)FUN_00404920();
  }
  if (param_1 == &DAT_00956338) goto LAB_004e91a0;
  CStringT<>();
  local_8._0_1_ = 1;
  CStringT<>();
  local_690c = FUN_004e0be0();
  if (local_690c == 0) {
    local_68f8 = 0;
    FUN_00403dd0();
    local_8._0_1_ = 2;
    if (DAT_00a088f4 != 0) {
      FUN_00404900();
    }
    FUN_0048b0e0();
    FUN_00404920();
    iVar2 = FUN_00429b90();
    if ((iVar2 < 0) || (cVar1 = FUN_004640c0(), cVar1 == '\0')) {
      cVar1 = FUN_00447350();
      if ((cVar1 == '\0') && (cVar1 = FUN_00447350(), cVar1 == '\0')) {
        local_6914 = Left();
        local_68ec = local_68ec | 1;
        cVar1 = FUN_00447350();
        if (cVar1 != '\0') goto LAB_004e9043;
        local_68f4 = 0;
      }
      else {
LAB_004e9043:
        local_68f4 = 1;
      }
      local_68e1 = (char)local_68f4;
      if ((local_68ec & 1) != 0) {
        local_68ec = local_68ec & 0xfffffffe;
        FUN_00404540();
      }
      if ((local_68e1 != '\0') && (iVar2 = FUN_004e0a80(), iVar2 != 0)) {
        local_68f8 = 1;
      }
    }
    else {
      FUN_00404900();
      iVar2 = FUN_00404c80();
      if (iVar2 != 0) {
        FUN_00404c80();
        FUN_0056d7d0();
        local_6910 = (int *)0x0;
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
        local_8 = 0xffffffff;
        FUN_00404540();
        ExceptionList = local_10;
        return local_6910;
      }
    }
    if (local_68f8 == 0) {
      local_6920 = FUN_005977f0();
      local_8._0_1_ = 3;
      local_691c = local_6920;
      FUN_00403dd0();
      local_8._0_1_ = 5;
      FUN_00404770();
      FUN_00404920();
      FUN_004f6110();
      local_6928 = (int *)0x0;
      local_8._0_1_ = 2;
      FUN_00404540();
      local_8._0_1_ = 1;
      FUN_00404540();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00404540();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return local_6928;
    }
    *(undefined4 *)(local_68d0 + 0x2c10) = 1;
    local_8._0_1_ = 1;
    FUN_00404540();
  }
  else {
    *(undefined4 *)(local_68d0 + 0x2c10) = 0;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404540();
LAB_004e91a0:
  iVar2 = FUN_00404c80();
  if ((iVar2 != 0) && (DAT_00a0b410 != 0)) {
    local_68d4 = (int *)FUN_0040c0e0();
    FUN_0044f310();
    FUN_00403dd0();
    local_8._0_1_ = 6;
    iVar2 = (**(code **)(*local_68d4 + 0x60))();
    if (iVar2 == 0) {
      cVar1 = FUN_00447350();
      if (cVar1 != '\0') {
        FUN_00480c60();
        iVar2 = FUN_004de030();
        if ((iVar2 != 0) && (cVar1 = FID_conflict_operator<(), cVar1 != '\0')) {
          iVar2 = FUN_004f60a0();
          if (iVar2 != 1) {
            local_6958 = local_68d4;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00404540();
            local_8 = 0xffffffff;
            FUN_00404540();
            ExceptionList = local_10;
            return local_6958;
          }
          (**(code **)(*local_68d4 + 0x78))();
        }
      }
    }
    else {
      cVar1 = FUN_004640c0();
      if (cVar1 != '\0') {
        FUN_00403dd0();
        local_692c = FUN_004be180();
        if (local_692c != 0) {
          (**(code **)(*local_68d4 + 0x78))();
        }
        FUN_004e1b10();
        FUN_004efb70();
        local_6900 = (int *)FUN_007b2bdd();
        if (*(int *)(local_68d0 + 0x2c30) != 0) {
          FUN_004bf0e0();
        }
        local_6930 = local_6900;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
        local_8 = 0xffffffff;
        FUN_00404540();
        ExceptionList = local_10;
        return local_6930;
      }
      local_68f0 = FUN_004f60a0();
      if (local_68f0 == 6) {
        FUN_00403dd0();
        local_6934 = FUN_004be180();
        if (local_6934 != 0) {
          local_68f0 = 7;
        }
      }
      if (local_68f0 == 6) {
        FUN_00446aa0();
        local_8._0_1_ = 7;
        FUN_00404920();
        FUN_00403dd0(local_68dc);
        local_693c = FUN_0044ec60(local_6940);
        local_8._0_1_ = 8;
        local_6938 = local_693c;
        FUN_00404920();
        FUN_007b3573(0);
        local_8._0_1_ = 10;
        FUN_00404540();
        iVar2 = FUN_007b3f8f();
        if (iVar2 != 1) {
          SetCurrentDirectoryW((LPCWSTR)&DAT_00a08f74);
          local_6944 = local_68d4;
          local_8._0_1_ = 7;
          FUN_007b384d();
          local_8._0_1_ = 6;
          FUN_00447100();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00404540();
          ExceptionList = local_10;
          return local_6944;
        }
        SetCurrentDirectoryW((LPCWSTR)&DAT_00a08f74);
        FUN_007b4284();
        local_8._0_1_ = 0xb;
        FUN_00404920();
        (**(code **)(*local_68d4 + 0xe0))();
        (**(code **)(*local_68d4 + 0x78))();
        local_8._0_1_ = 10;
        FUN_00404540();
        local_8._0_1_ = 7;
        FUN_007b384d();
        local_8._0_1_ = 6;
        FUN_00447100();
      }
      else {
        if (local_68f0 != 7) {
          local_6948 = local_68d4;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00404540();
          local_8 = 0xffffffff;
          FUN_00404540();
          ExceptionList = local_10;
          return local_6948;
        }
        (**(code **)(*local_68d4 + 0x78))();
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
  }
  FUN_004efb70();
  FUN_00404900();
  local_6908 = (int *)FUN_007b2bdd();
  if (*(int *)(local_68d0 + 0x2c30) != 0) {
    FUN_004bf0e0();
    local_6950 = FUN_0040c0e0();
    FUN_004f00f0();
  }
  local_6954 = local_6908;
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return local_6954;
}




/* vtable slots: CJw_winApp[22] */
/* 004e9720  FUN_004e9720  3324 bytes, 0 callers */

undefined4 FUN_004e9720(int param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_44 [8];
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  ushort local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092885d;
  local_10 = ExceptionList;
  uVar3 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((*(int *)(in_ECX + 0x44ac) != 0) && (*(int *)(param_1 + 4) == 0x100)) &&
     (*(int *)(param_1 + 8) == 0x1b)) {
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  local_20 = 0;
  if (*(int *)(param_1 + 4) == 0xa0) {
    FUN_004fb910(0);
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(param_1 + 4) == 0x200) {
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(param_1 + 4) == 0x201) {
    *(undefined4 *)(in_ECX + 0x4e34) = 0;
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(param_1 + 4) == 0x202) {
    *(undefined4 *)(in_ECX + 0x4e34) = 0;
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(param_1 + 4) == 0x204) {
    *(undefined4 *)(in_ECX + 0x4e34) = 0;
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(param_1 + 4) == 0x205) {
    *(undefined4 *)(in_ECX + 0x4e34) = 0;
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(param_1 + 4) == 0x207) {
    *(undefined4 *)(in_ECX + 0x4e34) = 0;
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(param_1 + 4) == 0x208) {
    *(undefined4 *)(in_ECX + 0x4e34) = 0;
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  local_18 = in_ECX;
  if (*(int *)(param_1 + 4) == 0x101) {
    if (*(int *)(param_1 + 8) == 0x10) {
      *(undefined4 *)(in_ECX + 0x4490) = 0;
      *(undefined4 *)(in_ECX + 0x448c) = 0;
      local_14 = GetKeyState(1);
      if ((local_14 & 0x80) == 0) {
        FUN_00404c80();
        FUN_0056d7d0();
      }
    }
    if (*(int *)(param_1 + 8) == 0x11) {
      *(undefined4 *)(local_18 + 0x4498) = 0;
      *(undefined4 *)(local_18 + 0x4494) = 0;
      uVar2 = GetKeyState(1);
      if ((uVar2 & 0x80) == 0) {
        FUN_00404c80();
        FUN_0056d7d0();
      }
    }
    *(undefined4 *)(local_18 + 0x44a8) = 0;
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(param_1 + 4) == 0x100) {
    local_28 = 0;
    if (*(int *)(param_1 + 8) == 0x10) {
      *(undefined4 *)(in_ECX + 0x4490) = 1;
      *(undefined4 *)(in_ECX + 0x448c) = 1;
      local_28 = 1;
      uVar2 = GetKeyState(1);
      if ((uVar2 & 0x80) == 0) {
        FUN_00404c80();
        FUN_0056d7d0();
      }
    }
    if (*(int *)(param_1 + 8) == 0x11) {
      *(undefined4 *)(local_18 + 0x4498) = 1;
      *(undefined4 *)(local_18 + 0x4494) = 1;
      local_28 = 1;
      uVar2 = GetKeyState(1);
      if ((uVar2 & 0x80) == 0) {
        FUN_00404c80();
        FUN_0056d7d0();
      }
    }
    if (local_28 != 0) {
      *(undefined4 *)(local_18 + 0x44a8) = 0;
      uVar4 = FUN_0079d649(param_1);
      ExceptionList = local_10;
      return uVar4;
    }
    if (*(int *)(local_18 + 0x44ac) != 0) {
      uVar4 = FUN_0079d649(param_1);
      ExceptionList = local_10;
      return uVar4;
    }
    if (((((*(int *)(param_1 + 8) == 0x28) || (*(int *)(param_1 + 8) == 0x26)) ||
         ((*(int *)(param_1 + 8) == 0x27 ||
          ((*(int *)(param_1 + 8) == 0x25 || (*(int *)(param_1 + 8) == 0x22)))))) ||
        (*(int *)(param_1 + 8) == 0x21)) || (*(int *)(param_1 + 8) == 0x24)) {
      if (((*(int *)(local_18 + 0x433c) != 1) || (*(int *)(local_18 + 0x4494) != 0)) &&
         ((*(int *)(local_18 + 0x433c) != 0 || (*(int *)(local_18 + 0x4494) != 1)))) {
        if (((*(int *)(local_18 + 0x5084) != 0) && (*(int *)(local_18 + 0x4494) == 0)) ||
           ((*(int *)(local_18 + 0x5084) == 0 && (*(int *)(local_18 + 0x4494) == 1)))) {
          *(uint *)(local_18 + 0x44a4) = *(uint *)(param_1 + 8) & 0xff;
          *(int *)(local_18 + 0x44a4) = *(int *)(local_18 + 0x44a4) + 1000;
          uVar6 = 0;
          uVar5 = 0;
          uVar4 = 0x1505;
          FUN_00404c80(0x1505,0,0,uVar3);
          FUN_00799e17();
          FUN_00406bc0(uVar4,uVar5,uVar6);
          if (*(int *)(local_18 + 0x44a4) != 0) {
            local_20 = 1;
          }
        }
        if (local_20 != 0) {
          ExceptionList = local_10;
          return 1;
        }
        uVar4 = FUN_0079d649(param_1);
        ExceptionList = local_10;
        return uVar4;
      }
      local_20 = FUN_0079d649(param_1);
      local_24 = 0;
      if (*(int *)(param_1 + 8) == 0x24) {
        local_24 = 0x1508;
      }
      if (*(int *)(param_1 + 8) == 0x21) {
        local_24 = 0x1506;
      }
      if (*(int *)(param_1 + 8) == 0x22) {
        local_24 = 0x1507;
      }
      if (*(int *)(param_1 + 8) == 0x25) {
        local_24 = 0x1501;
      }
      if (*(int *)(param_1 + 8) == 0x27) {
        local_24 = 0x1502;
      }
      if (*(int *)(param_1 + 8) == 0x26) {
        local_24 = 0x1503;
      }
      if (*(int *)(param_1 + 8) == 0x28) {
        local_24 = 0x1504;
      }
      if (local_24 == 0) {
        ExceptionList = local_10;
        return local_20;
      }
      FUN_00406bc0(local_24,0,0);
      ExceptionList = local_10;
      return local_20;
    }
    if (*(int *)(local_18 + 0x44b0) != 0) {
      uVar4 = FUN_0079d649(param_1);
      ExceptionList = local_10;
      return uVar4;
    }
    local_1c = *(uint *)(param_1 + 8) & 0xff;
    if (1 < *(int *)(local_18 + 0x44b4)) {
      if (local_1c == 0xba) {
        uVar4 = FUN_0079d649(param_1);
        ExceptionList = local_10;
        return uVar4;
      }
      if ((local_1c == 0xc0) && (*(int *)(local_18 + 0x44b4) == 2)) {
        local_1c = 0xba;
      }
      if ((local_1c == 0xdc) && (*(int *)(local_18 + 0x44b4) == 3)) {
        local_1c = 0xba;
      }
    }
    if (((((local_1c == 0xba) && (*(int *)(local_18 + 0x44b4) != 0)) &&
         (*(int *)(local_18 + 0x448c) == 0)) && (*(int *)(local_18 + 0x4494) == 0)) ||
       ((0x2f < local_1c && (local_1c < 0x3a)))) {
      if (*(uint *)(local_18 + 0x44a8) != local_1c) {
        *(uint *)(local_18 + 0x44a8) = local_1c;
        if (local_1c == 0xba) {
          *(undefined4 *)(local_18 + 0x44a4) = 0xffffff46;
        }
        else {
          *(uint *)(local_18 + 0x44a4) = -100 - (local_1c - 0x30);
        }
        uVar6 = 0;
        uVar5 = 0;
        uVar4 = 0x1505;
        FUN_00404c80(0x1505,0,0,uVar3);
        FUN_00799e17();
        FUN_00406bc0(uVar4,uVar5,uVar6);
        if (*(int *)(local_18 + 0x44a4) != 0) {
          local_20 = 1;
        }
      }
      if (local_20 != 0) {
        ExceptionList = local_10;
        return 1;
      }
      uVar4 = FUN_0079d649(param_1);
      ExceptionList = local_10;
      return uVar4;
    }
    if (*(int *)(param_1 + 8) == 0xd) {
      if (*(int *)(local_18 + 0x4e38) != 0) {
        uVar6 = 0;
        uVar5 = 0;
        uVar4 = 0x1500;
        FUN_00404c80(0x1500,0,0,uVar3);
        FUN_00799e17();
        FUN_00406bc0(uVar4,uVar5,uVar6);
        ExceptionList = local_10;
        return 1;
      }
      uVar4 = FUN_0079d649(param_1);
      ExceptionList = local_10;
      return uVar4;
    }
    if (local_1c == 0x20) {
      *(undefined4 *)(local_18 + 0x44a4) = 600;
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = 0x1505;
      FUN_00404c80(0x1505,0,0,uVar3);
      FUN_00799e17();
      FUN_00406bc0(uVar4,uVar5,uVar6);
      if (*(int *)(local_18 + 0x44a4) != 0) {
        local_20 = 1;
      }
      if (local_20 != 0) {
        ExceptionList = local_10;
        return 1;
      }
      uVar4 = FUN_0079d649(param_1);
      ExceptionList = local_10;
      return uVar4;
    }
    if ((0x40 < local_1c) && (local_1c < 0x5b)) {
      if ((*(int *)(local_18 + 0x44b8) != 0) &&
         ((((local_1c == 0x4d || (local_1c == 0x4a)) || (local_1c == 0x4b)) ||
          (((local_1c == 0x4c || (local_1c == 0x55)) || ((local_1c == 0x49 || (local_1c == 0x4f)))))
          ))) {
        uVar4 = FUN_0079d649(param_1);
        ExceptionList = local_10;
        return uVar4;
      }
      if (*(int *)(local_18 + 0x4494) == 0) {
        *(uint *)(local_18 + 0x44a4) = local_1c;
        if (DAT_00a0cc6c != 0) {
          *(int *)(local_18 + 0x44a4) = *(int *)(local_18 + 0x44a4) + 300;
        }
      }
      else {
        *(uint *)(local_18 + 0x44a4) = local_1c - 0x40;
        if (*(int *)(local_18 + 0x448c) != 0) {
          *(int *)(local_18 + 0x44a4) = *(int *)(local_18 + 0x44a4) + 0x32;
        }
        cVar1 = FUN_00447350(&DAT_00956338,local_18 + 0x54e0 + *(int *)(local_18 + 0x44a4) * 4);
        if (cVar1 != '\0') {
          uVar4 = FUN_0079d649(param_1);
          ExceptionList = local_10;
          return uVar4;
        }
      }
      if (*(uint *)(local_18 + 0x44a8) != local_1c) {
        *(uint *)(local_18 + 0x44a8) = local_1c;
        uVar6 = 0;
        uVar5 = 0;
        uVar4 = 0x1505;
        FUN_00404c80(0x1505,0,0,uVar3);
        FUN_00799e17();
        FUN_00406bc0(uVar4,uVar5,uVar6);
        if (*(int *)(local_18 + 0x44a4) != 0) {
          local_20 = 1;
        }
      }
      if (local_20 != 0) {
        ExceptionList = local_10;
        return 1;
      }
      uVar4 = FUN_0079d649(param_1);
      ExceptionList = local_10;
      return uVar4;
    }
    if ((local_1c == 8) && (*(int *)(local_18 + 0x44a8) == 0x1b)) {
      *(undefined4 *)(local_18 + 0x4e34) = 1;
    }
    if (((((local_1c == 9) || (local_1c == 0x1b)) || (local_1c == 0x71)) ||
        (((local_1c == 0x72 || (local_1c == 0x73)) ||
         ((local_1c == 0x74 || ((local_1c == 0x75 || (local_1c == 0x76)))))))) ||
       ((local_1c == 0x77 || (((local_1c == 0x78 || (local_1c == 0x7a)) || (local_1c == 0x7b)))))) {
      if (*(int *)(local_18 + 0x4494) != 0) {
        uVar4 = FUN_0079d649(param_1);
        ExceptionList = local_10;
        return uVar4;
      }
      *(uint *)(local_18 + 0x44a4) = local_1c;
      if (*(int *)(local_18 + 0x448c) != 0) {
        *(int *)(local_18 + 0x44a4) = *(int *)(local_18 + 0x44a4) + 300;
      }
      if ((*(uint *)(local_18 + 0x44a8) != local_1c) ||
         ((local_1c == 0x1b && (*(int *)(local_18 + 0x4e34) == 1)))) {
        *(uint *)(local_18 + 0x44a8) = local_1c;
        uVar6 = 0;
        uVar5 = 0;
        uVar4 = 0x1505;
        FUN_00404c80(0x1505,0,0,uVar3);
        FUN_00799e17();
        FUN_00406bc0(uVar4,uVar5,uVar6);
        if (*(int *)(local_18 + 0x44a4) != 0) {
          local_20 = 1;
        }
      }
      if (local_20 != 0) {
        ExceptionList = local_10;
        return 1;
      }
      uVar4 = FUN_0079d649(param_1);
      ExceptionList = local_10;
      return uVar4;
    }
  }
  if (((*(int *)(local_18 + 0x2c30) != 0) && (*(int *)(*(int *)(DAT_00a0b410 + 0x867c) + 0x20) != 0)
      ) && ((*(int *)(param_1 + 4) == 0x20a || (*(int *)(param_1 + 4) == 0xce11)))) {
    if (((*(uint *)(param_1 + 8) & 0xffff0000) == 0xff880000) ||
       ((*(uint *)(param_1 + 8) & 0xffff) == 0xff88)) {
      FUN_00406bc0(0x14d2,1,0);
    }
    else if (((*(uint *)(param_1 + 8) & 0xffff0000) == 0x780000) ||
            ((*(uint *)(param_1 + 8) & 0xffff) == 0x78)) {
      FUN_00406bc0(0x14d2,0xffffffff,0);
    }
    uVar4 = FUN_0079d649(param_1);
    ExceptionList = local_10;
    return uVar4;
  }
  if (*(int *)(local_18 + 0x4494) == 0) {
    if (DAT_00a0d8a0 < 1) {
      local_2c = -DAT_00a0d8a0;
    }
    else {
      local_2c = DAT_00a0d8a0;
    }
    if (local_2c != 1) {
      if (DAT_00a0d8a0 < 1) {
        local_30 = -DAT_00a0d8a0;
      }
      else {
        local_30 = DAT_00a0d8a0;
      }
      if (local_30 != 3) goto LAB_004ea40e;
    }
  }
  if ((*(int *)(param_1 + 4) == 0x20a) || (*(int *)(param_1 + 4) == 0xce11)) {
    *(undefined4 *)(local_18 + 0x4e34) = 0;
    if (*(int *)(DAT_00a0b410 + 0x90d0) != 0) {
      ExceptionList = local_10;
      return 1;
    }
    if (*(int *)(DAT_00a0b410 + 0x90c8) != 0) {
      ExceptionList = local_10;
      return 1;
    }
    if (*(int *)(DAT_00a0b410 + 0x90cc) != 0) {
      ExceptionList = local_10;
      return 1;
    }
    FUN_004470a0(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
    FUN_004eed00(local_44);
    if (DAT_00a0b410 == 0) {
      local_34 = 0;
    }
    else {
      local_34 = DAT_00a0b410 + 0x88;
    }
    FUN_0060b020(local_34,DAT_00a0b410,0);
    local_8 = 0;
    if (((*(uint *)(param_1 + 8) & 0xffff0000) == 0xff880000) ||
       ((*(uint *)(param_1 + 8) & 0xffff) == 0xff88)) {
      if ((*(int *)(local_18 + 0x4494) == 0) && (-1 < DAT_00a0d8a0)) {
        FUN_004578a0(0x79);
      }
      else {
        FUN_004578a0(0x7a);
      }
    }
    else {
      if (((*(uint *)(param_1 + 8) & 0xffff0000) != 0x780000) &&
         ((*(uint *)(param_1 + 8) & 0xffff) != 0x78)) {
        local_38 = FUN_0079d649(param_1);
        local_8 = 0xffffffff;
        FUN_0060b110();
        ExceptionList = local_10;
        return local_38;
      }
      if ((*(int *)(local_18 + 0x4494) == 0) && (-1 < DAT_00a0d8a0)) {
        FUN_004578a0(0x7a);
      }
      else {
        FUN_004578a0(0x79);
      }
    }
    local_3c = 1;
    local_8 = 0xffffffff;
    FUN_0060b110();
    ExceptionList = local_10;
    return local_3c;
  }
LAB_004ea40e:
  uVar4 = FUN_0079d649(param_1);
  ExceptionList = local_10;
  return uVar4;
}




/* vtable slots: CJw_winApp[58], CWinApp[58] */
/* 004eecc0  FUN_004eecc0  23 bytes, 0 callers */

uint FUN_004eecc0(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xac) & 0x10;
}




/* vtable slots: CJw_winApp[59], CWinApp[59] */
/* 004eece0  FUN_004eece0  23 bytes, 0 callers */

uint FUN_004eece0(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xac) & 0x20;
}




/* vtable slots: CJw_winApp[2] */
/* 004eee80  FUN_004eee80  3297 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004eee80(CArchive *param_1)

{
  int iVar1;
  CArchive *pCVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long lVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  long lVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  long lVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  long *plVar26;
  undefined8 uVar27;
  long lVar28;
  int iVar29;
  long *plVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  long *plVar33;
  undefined8 uVar34;
  long lVar35;
  int iVar36;
  undefined8 uVar37;
  long *plVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  long *plVar41;
  long lVar42;
  int iVar43;
  undefined8 uVar44;
  long *plVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  long lVar48;
  long *plVar49;
  undefined8 uVar50;
  undefined8 uVar51;
  long *plVar52;
  undefined8 uVar53;
  long lVar54;
  long *plVar55;
  undefined8 uVar56;
  undefined8 uVar57;
  long *plVar58;
  undefined8 uVar59;
  long lVar60;
  long lVar61;
  undefined8 uVar62;
  undefined8 uVar63;
  long local_60;
  int local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    if (0x14 < *(int *)(local_5c + 0x2c34)) {
      plVar3 = (long *)(local_5c + 0x2d08);
      plVar4 = (long *)(local_5c + 0x2d00);
      plVar58 = (long *)(local_5c + 0x3160);
      plVar55 = (long *)(local_5c + 0x315c);
      iVar1 = local_5c + 0x3020;
      plVar52 = (long *)(local_5c + 0x3158);
      plVar49 = (long *)(local_5c + 0x3154);
      plVar45 = (long *)(local_5c + 0x3150);
      iVar43 = local_5c + 0x2d48;
      plVar41 = (long *)(local_5c + 0x314c);
      plVar38 = (long *)(local_5c + 0x3148);
      iVar36 = local_5c + 0x2e98;
      plVar33 = (long *)(local_5c + 0x3144);
      plVar30 = (long *)(local_5c + 0x3140);
      iVar29 = local_5c + 0x2fe8;
      plVar26 = (long *)(local_5c + 0x313c);
      FUN_00420650(local_5c + 0x2d20);
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650();
      CArchive::operator>>(pCVar2,plVar26);
      FUN_00420650();
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650(iVar29);
      CArchive::operator>>(pCVar2,plVar30);
      FUN_00420650();
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650();
      CArchive::operator>>(pCVar2,plVar33);
      FUN_00420650();
      FUN_00420650(iVar36);
      pCVar2 = (CArchive *)FUN_00420650();
      CArchive::operator>>(pCVar2,plVar38);
      FUN_00420650();
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650();
      CArchive::operator>>(pCVar2,plVar41);
      FUN_00420650(iVar43);
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650();
      CArchive::operator>>(pCVar2,plVar45);
      FUN_00420650();
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650();
      CArchive::operator>>(pCVar2,plVar49);
      FUN_00420650();
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650();
      CArchive::operator>>(pCVar2,plVar52);
      FUN_00420650();
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650(iVar1);
      CArchive::operator>>(pCVar2,plVar55);
      FUN_00420650();
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650();
      CArchive::operator>>(pCVar2,plVar58);
      FUN_00420650();
      FUN_00420650();
      pCVar2 = (CArchive *)FUN_00420650();
      pCVar2 = CArchive::operator>>(pCVar2,plVar4);
      CArchive::operator>>(pCVar2,plVar3);
      FUN_00420650();
      FUN_00420650();
    }
    if (0xd5 < *(int *)(local_5c + 0x2c34)) {
      CArchive::operator>>(param_1,&local_60);
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      FUN_00420650();
      if (DAT_00a0cab8 != 0) {
        *(long *)(local_5c + 0x31e8) = local_60;
        *(undefined8 *)(local_5c + 0x31f0) = local_30;
        *(undefined8 *)(local_5c + 0x31f8) = local_28;
        *(undefined8 *)(local_5c + 0x3200) = local_20;
        *(undefined8 *)(local_5c + 0x3240) = local_58;
        *(undefined8 *)(local_5c + 0x3248) = local_50;
        *(undefined8 *)(local_5c + 0x3250) = local_48;
      }
    }
  }
  else {
    uVar63 = *(undefined8 *)(local_5c + 0x2cb0);
    uVar62 = *(undefined8 *)(local_5c + 0x2ca8);
    lVar61 = *(long *)(local_5c + 0x2d08);
    lVar60 = *(long *)(local_5c + 0x2d00);
    uVar59 = *(undefined8 *)(local_5c + 0x2ce8);
    uVar57 = *(undefined8 *)(local_5c + 0x2cd8);
    uVar56 = *(undefined8 *)(local_5c + 0x2cc8);
    lVar54 = *(long *)(local_5c + 0x3160);
    uVar53 = *(undefined8 *)(local_5c + 0x3028);
    uVar51 = *(undefined8 *)(local_5c + 0x2ec8);
    uVar50 = *(undefined8 *)(local_5c + 0x2d68);
    lVar48 = *(long *)(local_5c + 0x315c);
    uVar47 = *(undefined8 *)(local_5c + 0x3020);
    uVar46 = *(undefined8 *)(local_5c + 0x2ec0);
    uVar44 = *(undefined8 *)(local_5c + 0x2d60);
    lVar42 = *(long *)(local_5c + 0x3158);
    uVar40 = *(undefined8 *)(local_5c + 0x3018);
    uVar39 = *(undefined8 *)(local_5c + 0x2eb8);
    uVar37 = *(undefined8 *)(local_5c + 0x2d58);
    lVar35 = *(long *)(local_5c + 0x3154);
    uVar34 = *(undefined8 *)(local_5c + 0x3010);
    uVar32 = *(undefined8 *)(local_5c + 0x2eb0);
    uVar31 = *(undefined8 *)(local_5c + 0x2d50);
    lVar28 = *(long *)(local_5c + 0x3150);
    uVar27 = *(undefined8 *)(local_5c + 0x3008);
    uVar25 = *(undefined8 *)(local_5c + 0x2ea8);
    uVar24 = *(undefined8 *)(local_5c + 0x2d48);
    lVar23 = *(long *)(local_5c + 0x314c);
    uVar22 = *(undefined8 *)(local_5c + 0x3000);
    uVar21 = *(undefined8 *)(local_5c + 0x2ea0);
    uVar20 = *(undefined8 *)(local_5c + 0x2d40);
    lVar19 = *(long *)(local_5c + 0x3148);
    uVar18 = *(undefined8 *)(local_5c + 0x2ff8);
    uVar17 = *(undefined8 *)(local_5c + 0x2e98);
    uVar16 = *(undefined8 *)(local_5c + 0x2d38);
    lVar15 = *(long *)(local_5c + 0x3144);
    uVar14 = *(undefined8 *)(local_5c + 0x2ff0);
    uVar13 = *(undefined8 *)(local_5c + 0x2e90);
    uVar12 = *(undefined8 *)(local_5c + 0x2d30);
    lVar11 = *(long *)(local_5c + 0x3140);
    uVar10 = *(undefined8 *)(local_5c + 0x2fe8);
    uVar9 = *(undefined8 *)(local_5c + 0x2e88);
    uVar8 = *(undefined8 *)(local_5c + 0x2d28);
    lVar7 = *(long *)(local_5c + 0x313c);
    uVar6 = *(undefined8 *)(local_5c + 0x2fe0);
    uVar5 = *(undefined8 *)(local_5c + 0x2e80);
    FUN_00420820(*(undefined8 *)(local_5c + 0x2d20));
    FUN_00420820(uVar5);
    pCVar2 = (CArchive *)FUN_00420820(uVar6);
    CArchive::operator<<(pCVar2,lVar7);
    FUN_00420820(uVar8);
    FUN_00420820(uVar9);
    pCVar2 = (CArchive *)FUN_00420820(uVar10);
    CArchive::operator<<(pCVar2,lVar11);
    FUN_00420820(uVar12);
    FUN_00420820(uVar13);
    pCVar2 = (CArchive *)FUN_00420820(uVar14);
    CArchive::operator<<(pCVar2,lVar15);
    FUN_00420820(uVar16);
    FUN_00420820(uVar17);
    pCVar2 = (CArchive *)FUN_00420820(uVar18);
    CArchive::operator<<(pCVar2,lVar19);
    FUN_00420820(uVar20);
    FUN_00420820(uVar21);
    pCVar2 = (CArchive *)FUN_00420820(uVar22);
    CArchive::operator<<(pCVar2,lVar23);
    FUN_00420820(uVar24);
    FUN_00420820(uVar25);
    pCVar2 = (CArchive *)FUN_00420820(uVar27);
    CArchive::operator<<(pCVar2,lVar28);
    FUN_00420820(uVar31);
    FUN_00420820(uVar32);
    pCVar2 = (CArchive *)FUN_00420820(uVar34);
    CArchive::operator<<(pCVar2,lVar35);
    FUN_00420820(uVar37);
    FUN_00420820(uVar39);
    pCVar2 = (CArchive *)FUN_00420820(uVar40);
    CArchive::operator<<(pCVar2,lVar42);
    FUN_00420820(uVar44);
    FUN_00420820(uVar46);
    pCVar2 = (CArchive *)FUN_00420820(uVar47);
    CArchive::operator<<(pCVar2,lVar48);
    FUN_00420820(uVar50);
    FUN_00420820(uVar51);
    pCVar2 = (CArchive *)FUN_00420820(uVar53);
    CArchive::operator<<(pCVar2,lVar54);
    FUN_00420820(uVar56);
    FUN_00420820(uVar57);
    pCVar2 = (CArchive *)FUN_00420820(uVar59);
    pCVar2 = CArchive::operator<<(pCVar2,lVar60);
    CArchive::operator<<(pCVar2,lVar61);
    FUN_00420820(uVar62);
    FUN_00420820(uVar63);
    uVar63 = *(undefined8 *)(local_5c + 0x3250);
    uVar62 = *(undefined8 *)(local_5c + 0x3248);
    uVar59 = *(undefined8 *)(local_5c + 0x3240);
    uVar57 = *(undefined8 *)(local_5c + 0x3200);
    uVar56 = *(undefined8 *)(local_5c + 0x31f8);
    uVar53 = *(undefined8 *)(local_5c + 0x31f0);
    CArchive::operator<<(param_1,*(long *)(local_5c + 0x31e8));
    FUN_00420820(uVar53);
    FUN_00420820(uVar56);
    FUN_00420820(uVar57);
    FUN_00420820(uVar59);
    FUN_00420820(uVar62);
    FUN_00420820(uVar63);
  }
  return;
}




/* vtable slots: CJw_winApp[55], CWinApp[55] */
/* 004f0680  FUN_004f0680  23 bytes, 0 callers */

uint FUN_004f0680(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xac) & 2;
}




/* vtable slots: CJw_winApp[57], CWinApp[57] */
/* 004f06a0  FUN_004f06a0  23 bytes, 0 callers */

uint FUN_004f06a0(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xac) & 8;
}




/* vtable slots: CJw_winApp[56], CWinApp[56] */
/* 004f06c0  FUN_004f06c0  23 bytes, 0 callers */

uint FUN_004f06c0(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xac) & 4;
}




/* vtable slots: CJw_winApp[54], CWinApp[54] */
/* 004f06e0  FUN_004f06e0  23 bytes, 0 callers */

uint FUN_004f06e0(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xac) & 1;
}




/* vtable slots: CJw_winApp[30], CWinApp[30], CWinThread[30] */
/* 0079d406  FUN_0079d406  32 bytes, 0 callers */

void FUN_0079d406(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (in_ECX[10] != 0) {
    pcVar1 = *(code **)(*in_ECX + 4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CJw_winApp[29], CWinApp[29], CWinThread[29] */
/* 0079d4d7  FUN_0079d4d7  27 bytes, 0 callers */

void FUN_0079d4d7(void)

{
  HWND pHVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x24) == 0) && (*(int *)(in_ECX + 0x20) == 0)) {
    pHVar1 = GetActiveWindow();
    CWnd::FromHandle(pHVar1);
  }
  return;
}




/* vtable slots: CJw_winApp[25], CWinApp[25], CWinThread[25] */
/* 0079d516  IsIdleMessage  16 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CWinThread::IsIdleMessage(struct tagMSG *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CWinThread::IsIdleMessage(CWinThread *this,tagMSG *param_1)

{
  int iVar1;
  
  iVar1 = AfxInternalIsIdleMessage(param_1);
  return iVar1;
}




/* vtable slots: CJw_winApp[28], CWinApp[28], CWinThread[28] */
/* 0079d659  FUN_0079d659  300 bytes, 0 callers */

undefined4 FUN_0079d659(int param_1,tagMSG *param_2)

{
  code *pcVar1;
  CWnd *pCVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  undefined4 *puVar5;
  undefined4 local_24 [7];
  int *local_8;
  
  if (param_2 != (tagMSG *)0x0) {
    local_8 = in_ECX;
    if (param_1 != 0) {
      if (param_1 != 2) {
        return 0;
      }
      pCVar2 = CWnd::FromHandle(param_2->hwnd);
      if (((((pCVar2 != (CWnd *)0x0) && (iVar3 = FUN_00792b4c(), iVar3 != 0)) &&
           (iVar4 = FUN_007930a1(), iVar4 != 0)) &&
          ((*(int *)(iVar3 + 0x94) != 0 && (iVar3 = FUN_00404c80(), in_ECX[8] != 0)))) &&
         ((iVar4 = IsEnterKey(param_2), iVar4 != 0 || (param_2->message == 0x202)))) {
        SendMessageW(*(HWND *)(iVar3 + 0x20),0x111,0xe146,0);
        return 1;
      }
    }
    FUN_00404c80();
    if (((param_1 == 0) && (in_ECX[9] != 0)) && (param_2->message - 0x100 < 10)) {
      iVar3 = FUN_007c06c0(&LAB_0078e794);
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      if (*(int *)(iVar3 + 0x140) == 0) {
        *(undefined4 *)(iVar3 + 0x140) = 1;
        puVar5 = local_24;
        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar5 = param_2->hwnd;
          param_2 = (tagMSG *)&param_2->message;
          puVar5 = puVar5 + 1;
        }
        iVar4 = FUN_00797c32();
        if (iVar4 != 0) {
          pcVar1 = *(code **)(*local_8 + 0x58);
          guard_check_icall(local_24);
          iVar4 = (*pcVar1)();
          if (iVar4 != 0) {
            *(undefined4 *)(iVar3 + 0x140) = 0;
            return 1;
          }
        }
        *(undefined4 *)(iVar3 + 0x140) = 0;
      }
    }
  }
  return 0;
}




/* vtable slots: CJw_winApp[45], CWinApp[45] */
/* 0079f5ea  FUN_0079f5ea  25 bytes, 0 callers */

void FUN_0079f5ea(void)

{
  FUN_0079f6c8();
  return;
}




/* vtable slots: CJw_winApp[35], CWinApp[35] */
/* 007a35a4  FUN_007a35a4  325 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007a35a4(undefined4 param_1,LPCWSTR param_2,int *param_3,uint *param_4)

{
  code *pcVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  HKEY hKey;
  LSTATUS LVar5;
  LPBYTE lpData;
  int iVar6;
  int *in_ECX;
  int iVar7;
  HKEY local_28;
  undefined4 local_24;
  undefined4 local_20;
  DWORD local_1c;
  DWORD local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x7a35b0;
  iVar7 = 0;
  *param_3 = 0;
  *param_4 = 0;
  if (in_ECX[0x16] == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x84);
    guard_check_icall(local_14,param_1,param_2,0);
    (*pcVar1)();
    local_8 = 1;
    uVar2 = *(uint *)(local_14[0] + -0xc);
    local_1c = uVar2;
    if (uVar2 != 0) {
      *param_4 = uVar2 >> 1;
      iVar6 = FUN_0078e661(uVar2 >> 1);
      *param_3 = iVar6;
      if (0 < (int)uVar2) {
        do {
          cVar3 = FUN_004473c0(iVar7 + 1);
          cVar4 = FUN_004473c0(iVar7);
          iVar6 = iVar7;
          if (iVar7 < 0) {
            iVar6 = iVar7 + 1;
          }
          iVar7 = iVar7 + 2;
          *(char *)((iVar6 >> 1) + *param_3) = cVar4 + cVar3 * '\x10' + -0x51;
        } while (iVar7 < (int)local_1c);
      }
      iVar7 = 1;
    }
    FUN_00406b10();
    return iVar7;
  }
  hKey = (HKEY)GetSectionKey(param_1,0);
  if (hKey == (HKEY)0x0) {
    return 0;
  }
  local_24 = 0;
  local_20 = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_28 = hKey;
  LVar5 = RegQueryValueExW(hKey,param_2,(LPDWORD)0x0,&local_1c,(LPBYTE)0x0,&local_18);
  *param_4 = local_18;
  if (LVar5 == 0) {
    lpData = (LPBYTE)FUN_0078e661(local_18);
    *param_3 = (int)lpData;
    LVar5 = RegQueryValueExW(hKey,param_2,(LPDWORD)0x0,&local_1c,lpData,&local_18);
    if (LVar5 == 0) {
      iVar7 = 1;
      goto LAB_007a3641;
    }
  }
  thunk_FUN_008f43b0(*param_3);
  *param_3 = 0;
LAB_007a3641:
  ATL::CRegKey::Close((CRegKey *)&local_28);
  return iVar7;
}




/* vtable slots: CJw_winApp[31], CWinApp[31] */
/* 007a36e9  FUN_007a36e9  107 bytes, 14 callers */

UINT FUN_007a36e9(LPCWSTR param_1,LPCWSTR param_2,UINT param_3)

{
  HKEY hKey;
  LSTATUS LVar1;
  int in_ECX;
  DWORD local_10;
  UINT local_c;
  DWORD local_8;
  
  if (*(int *)(in_ECX + 0x58) == 0) {
    param_3 = GetPrivateProfileIntW(param_1,param_2,param_3,*(LPCWSTR *)(in_ECX + 0x6c));
  }
  else {
    hKey = (HKEY)GetSectionKey(param_1,0);
    if (hKey != (HKEY)0x0) {
      local_8 = 4;
      LVar1 = RegQueryValueExW(hKey,param_2,(LPDWORD)0x0,&local_10,(LPBYTE)&local_c,&local_8);
      RegCloseKey(hKey);
      if (LVar1 == 0) {
        param_3 = local_c;
      }
    }
  }
  return param_3;
}




/* vtable slots: CJw_winApp[33], CWinApp[33] */
/* 007a3754  FUN_007a3754  382 bytes, 15 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_007a3754(int *param_1,LPCWSTR param_2,LPCWSTR param_3,WCHAR *param_4)

{
  uint uVar1;
  HKEY hKey;
  LPBYTE lpData;
  int iVar2;
  int in_ECX;
  DWORD local_2024;
  int *local_2020;
  DWORD local_201c;
  int local_2018;
  WCHAR local_2014 [4096];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094474b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2020 = param_1;
  local_14 = uVar1;
  if (*(int *)(in_ECX + 0x58) == 0) {
    if (param_4 == (WCHAR *)0x0) {
      param_4 = L"";
    }
    GetPrivateProfileStringW(param_2,param_3,param_4,local_2014,0x1000,*(LPCWSTR *)(in_ECX + 0x6c));
    param_4 = local_2014;
  }
  else {
    hKey = (HKEY)GetSectionKey(param_2,0);
    if (hKey != (HKEY)0x0) {
      CStringT<>(uVar1);
      local_8 = 0;
      local_2024 = 0;
      local_201c = 0;
      local_2020 = (int *)RegQueryValueExW(hKey,param_3,(LPDWORD)0x0,&local_2024,(LPBYTE)0x0,
                                           &local_201c);
      if (local_2020 == (int *)0x0) {
        lpData = (LPBYTE)ATL::CSimpleStringT<char,0>::PrepareWrite
                                   ((CSimpleStringT<char,0> *)&local_2018,local_201c >> 1);
        local_2020 = (int *)RegQueryValueExW(hKey,param_3,(LPDWORD)0x0,&local_2024,lpData,
                                             &local_201c);
        ReleaseBuffer(0xffffffff);
      }
      RegCloseKey(hKey);
      if (local_2020 == (int *)0x0) {
        iVar2 = FUN_004054a0(local_2018 + -0x10);
        *param_1 = iVar2 + 0x10;
      }
      else {
        CStringT<>(param_4);
      }
      FUN_00406b10();
      ExceptionList = local_10;
      return param_1;
    }
  }
  CStringT<>(param_4);
  ExceptionList = local_10;
  return param_1;
}




/* vtable slots: CJw_winApp[64], CWinApp[64] */
/* 007a3926  FUN_007a3926  20 bytes, 0 callers */

undefined4 FUN_007a3926(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0xb8) != 0) && (*(int *)(in_ECX + 0xb4) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CJw_winApp[36], CWinApp[36] */
/* 007a3ac5  FUN_007a3ac5  215 bytes, 0 callers */

uint FUN_007a3ac5(undefined4 param_1,LPCWSTR param_2,BYTE *param_3,uint param_4)

{
  code *pcVar1;
  longlong lVar2;
  HKEY hKey;
  LSTATUS LVar3;
  int iVar4;
  int *in_ECX;
  uint uVar5;
  
  uVar5 = 0;
  if (in_ECX[0x16] == 0) {
    lVar2 = (ulonglong)(param_4 * 2 + 1) * 2;
    iVar4 = FUN_0078e661(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    if (param_4 != 0) {
      do {
        *(ushort *)(iVar4 + uVar5 * 4) = (param_3[uVar5] & 0xf) + 0x41;
        *(ushort *)(iVar4 + 2 + uVar5 * 4) = (param_3[uVar5] >> 4) + 0x41;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_4);
    }
    *(undefined2 *)(iVar4 + uVar5 * 4) = 0;
    pcVar1 = *(code **)(*in_ECX + 0x88);
    guard_check_icall(param_1,param_2,iVar4);
    uVar5 = (*pcVar1)();
    thunk_FUN_008f43b0(iVar4);
  }
  else {
    hKey = (HKEY)GetSectionKey(param_1,0);
    uVar5 = 0;
    if (hKey != (HKEY)0x0) {
      LVar3 = RegSetValueExW(hKey,param_2,0,3,param_3,param_4);
      RegCloseKey(hKey);
      uVar5 = (uint)(LVar3 == 0);
    }
  }
  return uVar5;
}




/* vtable slots: CJw_winApp[32], CWinApp[32] */
/* 007a3b9c  FUN_007a3b9c  137 bytes, 17 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_007a3b9c(LPCWSTR param_1,LPCWSTR param_2,undefined4 param_3)

{
  HKEY hKey;
  LSTATUS LVar1;
  uint uVar2;
  int in_ECX;
  wchar_t local_28 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x58) == 0) {
    FID_conflict__swprintf(local_28,(wchar_t *)0x10,&DAT_0095b714,param_3);
    uVar2 = WritePrivateProfileStringW(param_1,param_2,local_28,*(LPCWSTR *)(in_ECX + 0x6c));
  }
  else {
    hKey = (HKEY)GetSectionKey(param_1,0);
    uVar2 = 0;
    if (hKey != (HKEY)0x0) {
      LVar1 = RegSetValueExW(hKey,param_2,0,4,(BYTE *)&param_3,4);
      RegCloseKey(hKey);
      uVar2 = (uint)(LVar1 == 0);
    }
  }
  return uVar2;
}




/* vtable slots: CJw_winApp[34], CWinApp[34] */
/* 007a3c25  FUN_007a3c25  157 bytes, 19 callers */

uint FUN_007a3c25(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  HKEY hKey;
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x58) == 0) {
    uVar2 = WritePrivateProfileStringW(param_1,param_2,param_3,*(LPCWSTR *)(in_ECX + 0x6c));
    return uVar2;
  }
  if (param_2 == (LPCWSTR)0x0) {
    hKey = (HKEY)FUN_007a3485(0);
    if (hKey != (HKEY)0x0) {
      iVar1 = RegDeleteKeyW(hKey,param_1);
      goto LAB_007a3c98;
    }
  }
  else {
    hKey = (HKEY)GetSectionKey(param_1,0);
    if (param_3 == (LPCWSTR)0x0) {
      if (hKey != (HKEY)0x0) {
        iVar1 = RegDeleteValueW(hKey,param_2);
LAB_007a3c98:
        RegCloseKey(hKey);
        return (uint)(iVar1 == 0);
      }
    }
    else if (hKey != (HKEY)0x0) {
      iVar1 = FUN_008f899d(param_3);
      iVar1 = RegSetValueExW(hKey,param_2,0,1,(BYTE *)param_3,iVar1 * 2 + 2);
      goto LAB_007a3c98;
    }
  }
  return 0;
}




/* vtable slots: CJw_winApp[53], CWinApp[53] */
/* 007b1289  FUN_007b1289  97 bytes, 0 callers */

undefined4 FUN_007b1289(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 uVar4;
  int local_8;
  
  local_8 = 0;
  iVar2 = FUN_007c4582(&local_8);
  if ((-1 < iVar2) && (local_8 == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0xfc);
    uVar4 = 1;
    guard_check_icall();
    piVar3 = (int *)(*pcVar1)();
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 0x38);
      guard_check_icall();
      uVar4 = (*pcVar1)();
    }
    FUN_007c452d(uVar4);
  }
  return 0;
}




/* vtable slots: CJw_winApp[26], CWinApp[26] */
/* 007b138a  FUN_007b138a  116 bytes, 0 callers */

undefined4 FUN_007b138a(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  iVar2 = *(int *)(in_ECX + 0x94);
  if ((iVar2 == 0) || ((*(int *)(iVar2 + 0x14) != 7 && (*(int *)(iVar2 + 0x14) != 6)))) {
    iVar2 = FUN_0079dd6d();
    if (*(char *)(iVar2 + 0x14) == '\0') {
      FUN_007b1fdd();
    }
  }
  FUN_007c32a7();
  pcVar1 = *(code **)(in_ECX + 0xa4);
  if (pcVar1 != (code *)0x0) {
    guard_check_icall();
    (*pcVar1)();
  }
  uVar3 = 0;
  if (*(HMODULE *)(in_ECX + 0x80) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(in_ECX + 0x80));
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  iVar2 = FUN_0079d182();
  if (iVar2 != 0) {
    iVar2 = FUN_0079d182();
    uVar3 = *(undefined4 *)(iVar2 + 8);
  }
  return uVar3;
}




/* vtable slots: CJw_winApp[63], CWinApp[63] */
/* 007b13fe  FUN_007b13fe  220 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007b13fe(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0xd8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0xdc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) goto LAB_007b14c4;
  }
  if ((DAT_00a12174 == 0) && (in_ECX[0x24] == 0)) {
    iVar2 = FUN_0078e624(0xcc);
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_007c7d65(in_ECX[0x2b],in_ECX[0x2c]);
    }
    in_ECX[0x24] = (int)piVar3;
    pcVar1 = *(code **)(*piVar3 + 0xc);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      if ((int *)in_ECX[0x24] != (int *)0x0) {
        pcVar1 = *(code **)(*(int *)in_ECX[0x24] + 4);
        guard_check_icall(1);
        (*pcVar1)();
      }
      in_ECX[0x24] = 0;
    }
  }
LAB_007b14c4:
  DAT_00a12174 = 1;
  return in_ECX[0x24];
}




/* vtable slots: CJw_winApp[0], CWinApp[0] */
/* 007b14e0  FUN_007b14e0  6 bytes, 0 callers */

undefined ** FUN_007b14e0(void)

{
  return &PTR_s_CWinApp_00980318;
}




/* vtable slots: CJw_winApp[49], CWinApp[49] */
/* 007b14e6  FUN_007b14e6  76 bytes, 0 callers */

void FUN_007b14e6(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_00404c80();
  if (piVar2 != (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x60) = 0;
    PostMessageW((HWND)piVar2[8],0x36a,0,0);
    pcVar1 = *(code **)(*piVar2 + 0x80);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CJw_winApp[43], CWinApp[43] */
/* 007b1533  FUN_007b1533  90 bytes, 0 callers */

undefined4 FUN_007b1533(void)

{
  code *pcVar1;
  int *in_ECX;
  
  if (DAT_00a1216c != 0) {
    if (in_ECX[0x17] == 0) {
      in_ECX[0x17] = DAT_00a1216c;
    }
    DAT_00a1216c = 0;
  }
  if ((int *)in_ECX[0x17] == (int *)0x0) {
    DAT_00a003b0 = 0;
  }
  else {
    pcVar1 = *(code **)(*(int *)in_ECX[0x17] + 0xc);
    guard_check_icall(0);
    (*pcVar1)();
  }
  pcVar1 = *(code **)(*in_ECX + 0x10c);
  guard_check_icall();
  (*pcVar1)();
  return 1;
}




/* vtable slots: CJw_winApp[66], CWinApp[66] */
/* 007b164e  FUN_007b164e  118 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b164e(void)

{
  DWORD DVar1;
  LPWSTR pWVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  WCHAR local_228 [260];
  undefined4 local_20 [6];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  DVar1 = GetModuleFileNameW(*(HMODULE *)(in_ECX + 0x44),local_228,0x104);
  if ((DVar1 == 0) || (DVar1 == 0x104)) {
    uVar3 = 0;
  }
  else {
    pWVar2 = PathFindExtensionW(local_228);
    *pWVar2 = L'\0';
    puVar5 = &DAT_00980728;
    puVar6 = local_20;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    *(undefined2 *)puVar6 = *(undefined2 *)puVar5;
    uVar3 = AfxLoadLangResourceDLL(local_20,local_228);
  }
  return uVar3;
}




/* vtable slots: CJw_winApp[27], CWinApp[27] */
/* 007b1c29  FUN_007b1c29  159 bytes, 0 callers */

uint FUN_007b1c29(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  undefined4 uVar6;
  
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    if ((*(int *)(param_2 + 4) == 1) || (*(int *)(param_2 + 4) == 0xf)) {
      uVar2 = FUN_0079d786(param_1,param_2);
    }
    else {
      bVar5 = *(int *)(param_2 + 4) == 0x111;
      iVar3 = 0xf108;
      if (bVar5) {
        iVar3 = 0xf109 - (uint)(*(int *)(param_2 + 0xc) != 0);
      }
      uVar2 = (uint)bVar5;
      iVar1 = FUN_0079d98a(&PTR_s_CMemoryException_0097bfc4);
      if (iVar1 == 0) {
        iVar1 = FUN_0079d98a(&PTR_s_CUserException_0097df04);
        if (iVar1 != 0) {
          return uVar2;
        }
        uVar6 = 0x10;
        pcVar4 = *(code **)(*param_1 + 0x14);
      }
      else {
        uVar6 = 0x1030;
        pcVar4 = *(code **)(*param_1 + 0x14);
      }
      guard_check_icall(uVar6,iVar3);
      (*pcVar4)();
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CJw_winApp[52], CWinApp[52] */
/* 007b1cc9  FUN_007b1cc9  604 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007b1cc9(int param_1,int *param_2)

{
  wchar_t *pwVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *in_ECX;
  code *pcVar9;
  BSTR local_38;
  int local_34;
  int local_30;
  int *local_2c;
  undefined4 local_28;
  GUID local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x7b1cd5;
  CStringT<>();
  local_8 = 0;
  CStringT<>();
  local_8._0_1_ = 1;
  iVar4 = FUN_004054a0(*param_2 + -0x10);
  local_34 = iVar4 + 0x10;
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (*(int *)(iVar4 + 4) == 0) {
    local_24.Data1 = 0;
    local_24.Data2 = 0;
    local_24.Data3 = 0;
    local_24.Data4[0] = '\0';
    local_24.Data4[1] = '\0';
    local_24.Data4[2] = '\0';
    local_24.Data4[3] = '\0';
    local_24.Data4[4] = '\0';
    local_24.Data4[5] = '\0';
    local_24.Data4[6] = '\0';
    local_24.Data4[7] = '\0';
    CoCreateGuid(&local_24);
    CStringT<>();
    local_8._0_1_ = 3;
    FUN_004059f0(&local_34,L"%08lX-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",local_24.Data1,
                 local_24._4_4_ & 0xffff,(uint)local_24._4_4_ >> 0x10,local_24.Data4._0_4_ & 0xff,
                 (uint)local_24.Data4._0_4_ >> 8 & 0xff,(uint)local_24.Data4._0_4_ >> 0x10 & 0xff,
                 (uint)local_24.Data4._0_4_ >> 0x18,local_24.Data4._4_4_ & 0xff,
                 (uint)local_24.Data4._4_4_ >> 8 & 0xff,(uint)local_24.Data4._4_4_ >> 0x10 & 0xff,
                 (uint)local_24.Data4._4_4_ >> 0x18);
    local_8._0_1_ = 2;
    FUN_00406b10();
    uVar3 = (undefined1)local_8;
  }
  local_8._0_1_ = uVar3;
  pwVar1 = (wchar_t *)in_ECX[0x12];
  if (pwVar1 == (wchar_t *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_008f899d(pwVar1);
  }
  ATL::CSimpleStringT<wchar_t,0>::SetString((CSimpleStringT<wchar_t,0> *)&local_28,pwVar1,iVar4);
  uVar5 = FUN_008f899d(L"RestartByRestartManager");
  FUN_00404cf0(L"RestartByRestartManager",uVar5);
  uVar5 = FUN_008f899d(&DAT_0095bad4);
  FUN_00404cf0(&DAT_0095bad4,uVar5);
  FUN_00404cf0(local_34,*(undefined4 *)(local_34 + -0xc));
  iVar4 = FUN_00429b90(local_30,0);
  if (iVar4 == -1) {
    uVar5 = FUN_008f899d(&DAT_00980924);
    FUN_00404cf0(&DAT_00980924,uVar5);
    FUN_00404cf0(local_30,*(undefined4 *)(local_30 + -0xc));
  }
  pcVar9 = *(code **)(*in_ECX + 0xfc);
  guard_check_icall();
  local_2c = (int *)(*pcVar9)();
  if (local_2c != (int *)0x0) {
    pcVar9 = *(code **)(*local_2c + 0x24);
    guard_check_icall(&local_34);
    (*pcVar9)();
  }
  local_2c = (int *)*in_ECX;
  if (param_1 == 0) {
    pcVar9 = *(code **)((int)local_2c + 0xf0);
    guard_check_icall();
    uVar7 = (*pcVar9)();
    puVar8 = (undefined4 *)FUN_007b0bff(local_28);
    local_8 = CONCAT31(local_8._1_3_,5);
    uVar5 = 0;
    uVar6 = 0;
    pcVar9 = (code *)0x0;
  }
  else {
    pcVar9 = *(code **)((int)local_2c + 0xf8);
    guard_check_icall();
    uVar5 = (*pcVar9)();
    pcVar9 = *(code **)(*in_ECX + 0xf4);
    guard_check_icall();
    uVar6 = (*pcVar9)();
    pcVar9 = *(code **)(*in_ECX + 0xf0);
    guard_check_icall();
    uVar7 = (*pcVar9)();
    puVar8 = (undefined4 *)FUN_007b0bff(local_28);
    local_8 = CONCAT31(local_8._1_3_,4);
    pcVar9 = FUN_007b1147;
  }
  pcVar2 = *(code **)((int)local_2c + 0xcc);
  guard_check_icall(*puVar8,uVar7,pcVar9,uVar6,uVar5,0);
  (*pcVar2)();
  SysFreeString(local_38);
  FUN_00406b10();
  FUN_00406b10();
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CJw_winApp[51], CWinApp[51] */
/* 007b1f25  RegisterWithRestartManager  55 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CWinApp::RegisterWithRestartManager(wchar_t const *,unsigned
   long,unsigned long (__stdcall*)(void *),void *,unsigned long,unsigned long)
   
   Library: Visual Studio 2015 Release */

long __thiscall
CWinApp::RegisterWithRestartManager
          (CWinApp *this,wchar_t *param_1,ulong param_2,_func_ulong_void_ptr *param_3,void *param_4,
          ulong param_5,ulong param_6)

{
  long lVar1;
  int iVar2;
  
  lVar1 = FUN_007c4db4(param_1,param_2);
  if (lVar1 == 0) {
    if ((param_3 != (_func_ulong_void_ptr *)0x0) &&
       (iVar2 = FUN_007c4d4f(param_3,param_4,param_5,param_6), iVar2 != 0)) {
      return iVar2;
    }
    lVar1 = 0;
  }
  return lVar1;
}




/* vtable slots: CJw_winApp[65], CWinApp[65] */
/* 007b1f5c  FUN_007b1f5c  96 bytes, 0 callers */

undefined4 FUN_007b1f5c(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  uVar4 = 0;
  pcVar1 = *(code **)(*in_ECX + 0xfc);
  guard_check_icall();
  piVar2 = (int *)(*pcVar1)();
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0x3c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*piVar2 + 0x5c);
      guard_check_icall();
      uVar4 = (*pcVar1)();
      pcVar1 = *(code **)(*piVar2 + 100);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return uVar4;
}




/* vtable slots: CJw_winApp[21], CWinApp[21] */
/* 007b1fbc  FUN_007b1fbc  33 bytes, 0 callers */

void FUN_007b1fbc(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) == 0) {
    iVar1 = FUN_007c37cc();
    if (iVar1 != 0) {
      FUN_007b125f(0);
    }
  }
  FUN_0079d794();
  return;
}




/* vtable slots: CJw_winApp[50], CWinApp[50] */
/* 007b202a  FUN_007b202a  76 bytes, 0 callers */

void FUN_007b202a(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_00404c80();
  if (piVar2 != (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x60) = 0;
    PostMessageW((HWND)piVar2[8],0x36a,0,0);
    pcVar1 = *(code **)(*piVar2 + 0x84);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CJw_winApp[48], CWinApp[48] */
/* 007b2077  FUN_007b2077  73 bytes, 0 callers */

void FUN_007b2077(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_00404c80();
  if (piVar2 != (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x60) = 0;
    PostMessageW((HWND)piVar2[8],0x36a,0,0);
    pcVar1 = *(code **)(*piVar2 + 0x7c);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CJw_winApp[39], CWinApp[39] */
/* 007b2802  FUN_007b2802  408 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007b2802(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  LSTATUS LVar6;
  int in_ECX;
  LONG local_238;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_234 [4];
  int local_230;
  LPCWSTR local_22c;
  HKEY local_228;
  LPCWSTR local_224;
  WCHAR local_220 [268];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x228;
  local_8 = 0x7b2811;
  local_228 = (HKEY)0x0;
  local_238 = 0;
  local_230 = FUN_007b252e();
  while (local_230 != 0) {
    piVar3 = (int *)FUN_007b254f(&local_230);
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 0xc);
      guard_check_icall(0,0xfffffffc,0,0);
      (*pcVar1)();
    }
  }
  if (*(int *)(in_ECX + 0x58) != 0) {
    if (*(int *)(in_ECX + 0x6c) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    CStringT<>(L"Software\\");
    iVar2 = *(int *)(in_ECX + 0x58);
    local_8 = 0;
    if (iVar2 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_008f899d(iVar2);
    }
    FUN_00404cf0(iVar2,uVar4);
    pwVar5 = (wchar_t *)ATL::operator+(local_234,(wchar_t *)&local_224);
    local_8._0_1_ = 1;
    ATL::operator+((CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *)
                   &local_22c,pwVar5);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00406b10();
    FUN_007b238d(0x80000001,&local_22c,0);
    LVar6 = RegOpenKeyExW((HKEY)0x80000001,local_224,0,8,&local_228);
    if (LVar6 == 0) {
      LVar6 = RegEnumKeyW(local_228,0,local_220,0x104);
      if (LVar6 == 0x103) {
        FUN_007b238d(0x80000001,&local_224,0);
      }
      RegCloseKey(local_228);
    }
    RegQueryValueW((HKEY)0x80000001,local_22c,local_220,&local_238);
    FUN_00406b10();
    FUN_00406b10();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CJw_winApp[42], CWinApp[42] */
/* 007b29ba  FUN_007b29ba  55 bytes, 0 callers */

void FUN_007b29ba(int param_1)

{
  code *pcVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    if (*(int **)(in_ECX + 0x8c) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x8c) + 4);
      guard_check_icall(param_1,*(undefined4 *)(in_ECX + 0x54));
      (*pcVar1)();
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CJw_winApp[46], CWinApp[46] */
/* 007b2a18  FUN_007b2a18  125 bytes, 0 callers */

void FUN_007b2a18(int param_1)

{
  HCURSOR pHVar1;
  int in_ECX;
  
  if ((((param_1 == 0) || (param_1 == 1)) || (param_1 == -1)) && (DAT_00a12244 != (HCURSOR)0x0)) {
    FUN_007c2e0f(2);
    *(int *)(in_ECX + 0x84) = *(int *)(in_ECX + 0x84) + param_1;
    if (*(int *)(in_ECX + 0x84) < 1) {
      *(undefined4 *)(in_ECX + 0x84) = 0;
      SetCursor(*(HCURSOR *)(in_ECX + 0x88));
    }
    else {
      pHVar1 = SetCursor(DAT_00a12244);
      if ((0 < param_1) && (*(int *)(in_ECX + 0x84) == 1)) {
        *(HCURSOR *)(in_ECX + 0x88) = pHVar1;
      }
    }
    FUN_007c2e83(2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CJw_winApp[47], CWinApp[47] */
/* 007b2adb  FUN_007b2adb  42 bytes, 0 callers */

undefined4 FUN_007b2adb(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x5c) == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x5c) + 0x38);
    guard_check_icall(param_1);
    uVar2 = (*pcVar1)();
  }
  return uVar2;
}




/* vtable slots: CJw_winApp[40], CWinApp[40] */
/* 007b2c09  FUN_007b2c09  46 bytes, 0 callers */

void FUN_007b2c09(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x5c) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x5c) + 0x1c);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CJw_winApp[44], CWinApp[44] */
/* 007b2c38  FUN_007b2c38  34 bytes, 0 callers */

undefined4 FUN_007b2c38(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x5c) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x5c) + 0x24);
    guard_check_icall();
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  return 1;
}



