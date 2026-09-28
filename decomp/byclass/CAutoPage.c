/* CAutoPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CAutoPage[1] */
/* 004121d0  FUN_004121d0  68 bytes, 0 callers */

undefined4 FUN_004121d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00411ec0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x4d8);
    }
  }
  return in_ECX;
}




/* vtable slots: CAutoPage[64] */
/* 00412370  FUN_00412370  3184 bytes, 0 callers */

void FUN_00412370(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880();
  FUN_0078fb9c();
  DDX_Text(param_1,0x964,(double *)(in_ECX + 0x310));
  DDX_Text(param_1,0x93c,(double *)(in_ECX + 0x318));
  DDX_Text(param_1,0x93d,(double *)(in_ECX + 800));
  DDX_Text(param_1,0x93e,(double *)(in_ECX + 0x328));
  DDX_Text(param_1,0x93f,(double *)(in_ECX + 0x330));
  DDX_Text(param_1,0x940,(double *)(in_ECX + 0x338));
  DDX_Text(param_1,0x941,(double *)(in_ECX + 0x340));
  DDX_Text(param_1,0x942,(double *)(in_ECX + 0x348));
  DDX_Text(param_1,0x943,(double *)(in_ECX + 0x350));
  DDX_Text(param_1,0x944,(double *)(in_ECX + 0x358));
  DDX_Text(param_1,0x945,(double *)(in_ECX + 0x360));
  DDX_Text(param_1,0x946,(double *)(in_ECX + 0x368));
  DDX_Text(param_1,0x947,(double *)(in_ECX + 0x370));
  DDX_Text(param_1,0x948,(double *)(in_ECX + 0x378));
  DDX_Text(param_1,0x949,(double *)(in_ECX + 0x380));
  DDX_Text(param_1,0x94a,(double *)(in_ECX + 0x388));
  DDX_Text(param_1,0x94b,(double *)(in_ECX + 0x390));
  DDX_Text(param_1,0x94c,(double *)(in_ECX + 0x398));
  DDX_Text(param_1,0x94d,(double *)(in_ECX + 0x3a0));
  DDX_Text(param_1,0x94e,(double *)(in_ECX + 0x3a8));
  DDX_Text(param_1,0x94f,(double *)(in_ECX + 0x3b0));
  DDX_Text(param_1,0x950,(double *)(in_ECX + 0x3b8));
  DDX_Text(param_1,0x951,(double *)(in_ECX + 0x3c0));
  DDX_Text(param_1,0x95e,(double *)(in_ECX + 0x3c8));
  DDX_Text(param_1,0x95f,(double *)(in_ECX + 0x3d0));
  DDX_Text(param_1,0x960,(double *)(in_ECX + 0x3d8));
  DDX_Text(param_1,0x961,(double *)(in_ECX + 0x3e0));
  DDX_Text(param_1,0x962,(double *)(in_ECX + 1000));
  DDX_Text(param_1,0x963,(double *)(in_ECX + 0x3f0));
  DDX_Text(param_1,0x952,(double *)(in_ECX + 0x3f8));
  DDX_Text(param_1,0x953,(double *)(in_ECX + 0x400));
  DDX_Text(param_1,0x954,(double *)(in_ECX + 0x408));
  DDX_Text(param_1,0x955,(double *)(in_ECX + 0x410));
  DDX_Text(param_1,0x956,(double *)(in_ECX + 0x418));
  DDX_Text(param_1,0x957,(double *)(in_ECX + 0x420));
  DDX_Text(param_1,0x958,(double *)(in_ECX + 0x428));
  DDX_Text(param_1,0x959,(double *)(in_ECX + 0x430));
  DDX_Text(param_1,0x95a,(double *)(in_ECX + 0x438));
  DDX_Text(param_1,0x95b,(double *)(in_ECX + 0x440));
  DDX_Text(param_1,0x95c,(double *)(in_ECX + 0x448));
  DDX_Text(param_1,0x95d,(double *)(in_ECX + 0x450));
  FUN_0078fb9c();
  if (*(int *)(in_ECX + 0xc4) != 0) {
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    FUN_007979e8();
    FUN_00412220();
  }
  if (DAT_00a0ef50 != 0) {
    FUN_0079f95a(param_1,in_ECX + 0x310,0x3fe0000000000000,0x3ff0000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x318,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 800,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x328,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x330,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x338,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x340,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x348,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x350,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x358,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x360,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x368,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x370,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x378,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x380,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x388,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x390,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x398,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3a0,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3a8,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3b0,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3b8,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3c0,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3c8,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3d0,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3d8,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3e0,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 1000,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3f0,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x3f8,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x400,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x408,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x410,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x418,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x420,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x428,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x430,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x438,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x440,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x448,0xc069000000000000,0x4069000000000000);
    FUN_0079f95a(param_1,in_ECX + 0x450,0xc069000000000000,0x4069000000000000);
  }
  return;
}




/* vtable slots: CAutoPage[10] */
/* 00412fe0  FUN_00412fe0  16 bytes, 0 callers */

void FUN_00412fe0(void)

{
  FUN_004136c0();
  return;
}




/* vtable slots: CAutoPage[0] */
/* 00412ff0  FUN_00412ff0  16 bytes, 0 callers */

undefined ** FUN_00412ff0(void)

{
  return &PTR_s_CAutoPage_009560c8;
}




/* vtable slots: CAutoPage[108], CDxfPage[108], CGamenPage[108], CKeyPage[108], CMFCCustomColorsPropertyPage[108], CMFCMousePropertyPage[108], CMFCPropertyPage[108], CMFCStandardColorsPropertyPage[108], CMFCToolBarsCommandsPropertyPage[108], CMFCToolBarsKeyboardPropertyPage[108], CMFCToolBarsListPropertyPage[108], CMFCToolBarsMenuPropertyPage[108], CMFCToolBarsOptionsPropertyPage[108], CMFCToolBarsToolsPropertyPage[108], CMojiPage[108], CPropertyPage[108], CSenPage[108], CSonotaPage[108], CSonotaPage1[108] */
/* 007a06e0  GetParentSheet  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CPropertySheet * __thiscall CPropertyPage::GetParentSheet(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

CPropertySheet * __thiscall CPropertyPage::GetParentSheet(CPropertyPage *this)

{
  CObject *pCVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  
  pHVar2 = *(HWND *)(this + 0x20);
  while( true ) {
    pHVar2 = GetParent(pHVar2);
    pCVar3 = CWnd::FromHandle(pHVar2);
    if (pCVar3 == (CWnd *)0x0) {
      return (CPropertySheet *)0x0;
    }
    pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPropertySheet_0097e564,(CObject *)pCVar3);
    if (pCVar1 != (CObject *)0x0) break;
    pHVar2 = *(HWND *)(pCVar3 + 0x20);
  }
  return (CPropertySheet *)pCVar1;
}




/* vtable slots: CAutoPage[99], CDxfPage[99], CGamenPage[99], CKeyPage[99], CMFCCustomColorsPropertyPage[99], CMFCMousePropertyPage[99], CMFCPropertyPage[99], CMFCStandardColorsPropertyPage[99], CMFCToolBarsCommandsPropertyPage[99], CMFCToolBarsKeyboardPropertyPage[99], CMFCToolBarsListPropertyPage[99], CMFCToolBarsMenuPropertyPage[99], CMFCToolBarsOptionsPropertyPage[99], CMFCToolBarsToolsPropertyPage[99], CMojiPage[99], CPropertyPage[99], CSenPage[99], CSonotaPage[99], CSonotaPage1[99] */
/* 007a0987  FUN_007a0987  30 bytes, 0 callers */

undefined4 FUN_007a0987(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x180);
  guard_check_icall();
  (*pcVar1)();
  return 1;
}




/* vtable slots: CAutoPage[102], CDxfPage[102], CGamenPage[102], CKeyPage[102], CMFCCustomColorsPropertyPage[102], CMFCMousePropertyPage[102], CMFCPropertyPage[102], CMFCStandardColorsPropertyPage[102], CMFCToolBarsCommandsPropertyPage[102], CMFCToolBarsKeyboardPropertyPage[102], CMFCToolBarsListPropertyPage[102], CMFCToolBarsMenuPropertyPage[102], CMFCToolBarsOptionsPropertyPage[102], CMojiPage[102], CPropertyPage[102], CSenPage[102], CSonotaPage[102], CSonotaPage1[102] */
/* 007a0d54  FUN_007a0d54  14 bytes, 1 callers */

bool FUN_007a0d54(void)

{
  int iVar1;
  
  iVar1 = FUN_007955d2(1);
  return iVar1 != 0;
}




/* vtable slots: CAutoPage[62], CDxfPage[62], CGamenPage[62], CKeyPage[62], CMFCCustomColorsPropertyPage[62], CMFCMousePropertyPage[62], CMFCPropertyPage[62], CMFCStandardColorsPropertyPage[62], CMFCToolBarsCommandsPropertyPage[62], CMFCToolBarsKeyboardPropertyPage[62], CMFCToolBarsListPropertyPage[62], CMFCToolBarsMenuPropertyPage[62], CMFCToolBarsOptionsPropertyPage[62], CMFCToolBarsToolsPropertyPage[62], CMojiPage[62], CPropertyPage[62], CSenPage[62], CSonotaPage[62], CSonotaPage1[62] */
/* 007a0da5  FUN_007a0da5  369 bytes, 0 callers */

undefined4 FUN_007a0da5(undefined4 param_1,int *param_2,uint *param_3)

{
  int iVar1;
  HWND pHVar2;
  uint uVar3;
  undefined4 uVar4;
  int *in_ECX;
  code *pcVar5;
  
  iVar1 = FUN_00793ba8(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  if (((HWND)*param_2 != (HWND)in_ECX[8]) &&
     (pHVar2 = GetParent((HWND)in_ECX[8]), (HWND)*param_2 != pHVar2)) {
LAB_007a0f0f:
    return 0;
  }
  switch(param_2[2]) {
  case -0xd1:
    pcVar5 = *(code **)(*in_ECX + 0x19c);
    goto LAB_007a0e59;
  case -0xd0:
    pcVar5 = *(code **)(*in_ECX + 0x1ac);
    guard_check_icall();
    uVar3 = (*pcVar5)();
    break;
  case -0xcf:
    pcVar5 = *(code **)(*in_ECX + 0x1a4);
    goto LAB_007a0eb7;
  case -0xce:
    pcVar5 = *(code **)(*in_ECX + 0x1a0);
LAB_007a0eb7:
    guard_check_icall();
    uVar4 = (*pcVar5)();
    uVar3 = FUN_007a0918(uVar4);
    break;
  case -0xcd:
    SendMessageW((HWND)in_ECX[8],0x111,0xe146,0);
    return 1;
  default:
    goto LAB_007a0f0f;
  case -0xcb:
    pcVar5 = *(code **)(*in_ECX + 400);
    guard_check_icall();
    (*pcVar5)();
    return 1;
  case -0xca:
    pcVar5 = *(code **)(*in_ECX + 0x18c);
    guard_check_icall();
    iVar1 = (*pcVar5)();
    uVar3 = (-(uint)(iVar1 != 0) & 0xfffffffe) + 2;
    break;
  case -0xc9:
    pcVar5 = *(code **)(*in_ECX + 0x198);
LAB_007a0e59:
    guard_check_icall();
    iVar1 = (*pcVar5)();
    uVar3 = (uint)(iVar1 == 0);
    break;
  case -200:
    pcVar5 = *(code **)(*in_ECX + 0x1b0);
    guard_check_icall();
    iVar1 = (*pcVar5)();
    if ((((iVar1 == 0) || ((*(byte *)(iVar1 + 0x60) & 0x10) != 0)) || (*(int *)(iVar1 + 0xd4) != 0))
       || ((*(uint *)(iVar1 + 0x84) & 0x4000) != 0)) {
      pcVar5 = *(code **)(*in_ECX + 0x194);
      guard_check_icall();
      iVar1 = (*pcVar5)();
      uVar3 = (iVar1 != 0) - 1;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  *param_3 = uVar3;
  return 1;
}




/* vtable slots: CAutoPage[100], CDxfPage[100], CGamenPage[100], CKeyPage[100], CMFCCustomColorsPropertyPage[100], CMFCMousePropertyPage[100], CMFCPropertyPage[100], CMFCStandardColorsPropertyPage[100], CMFCToolBarsCommandsPropertyPage[100], CMFCToolBarsKeyboardPropertyPage[100], CMFCToolBarsListPropertyPage[100], CMFCToolBarsMenuPropertyPage[100], CMFCToolBarsOptionsPropertyPage[100], CMFCToolBarsToolsPropertyPage[100], CMojiPage[100], CPropertyPage[100], CSenPage[100], CSonotaPage[100], CSonotaPage1[100] */
/* 007a0f41  FUN_007a0f41  27 bytes, 0 callers */

void FUN_007a0f41(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x184);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CAutoPage[101], CDxfPage[101], CGamenPage[101], CKeyPage[101], CMFCCustomColorsPropertyPage[101], CMFCMousePropertyPage[101], CMFCStandardColorsPropertyPage[101], CMFCToolBarsCommandsPropertyPage[101], CMFCToolBarsKeyboardPropertyPage[101], CMFCToolBarsListPropertyPage[101], CMFCToolBarsMenuPropertyPage[101], CMFCToolBarsOptionsPropertyPage[101], CMFCToolBarsToolsPropertyPage[101], CMojiPage[101], CPropertyPage[101], CSenPage[101], CSonotaPage[101], CSonotaPage1[101] */
/* 007a0f5c  FUN_007a0f5c  225 bytes, 1 callers */

undefined4 FUN_007a0f5c(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  AFX_DYNAMIC_LAYOUT_ITEM *pAVar7;
  int iVar8;
  undefined4 *puVar9;
  int *in_ECX;
  undefined1 local_1c [8];
  int *local_14;
  undefined1 local_10 [4];
  CObject *local_c;
  CMFCDynamicLayout *local_8;
  
  if (in_ECX[0x2c] != 0) {
    local_14 = in_ECX;
    pHVar4 = GetParent((HWND)in_ECX[8]);
    pCVar5 = CWnd::FromHandle(pHVar4);
    pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPropertySheet_0097e564,(CObject *)pCVar5);
    local_c = pCVar6;
    if (pCVar6 != (CObject *)0x0) {
      local_8 = *(CMFCDynamicLayout **)(pCVar6 + 0x58);
      if (local_8 != (CMFCDynamicLayout *)0x0) {
        pAVar7 = CMFCDynamicLayout::FindItem(local_8,(HWND__ *)in_ECX[8]);
        if ((pAVar7 == (AFX_DYNAMIC_LAYOUT_ITEM *)0x0) && (*(int *)(local_8 + 0x1c) != 0)) {
          pcVar1 = *(code **)(*(int *)pCVar6 + 0x178);
          guard_check_icall();
          iVar8 = (*pcVar1)();
          if (iVar8 != 0) {
            puVar9 = (undefined4 *)FUN_007c41af(local_10,100,100);
            uVar2 = *puVar9;
            uVar3 = puVar9[1];
            puVar9 = (undefined4 *)FUN_007c41c2(local_1c);
            FUN_007c3b65(local_14[8],*puVar9,puVar9[1],uVar2,uVar3);
            in_ECX = local_14;
          }
        }
      }
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x148);
  guard_check_icall();
  (*pcVar1)();
  if (in_ECX[0x2c] == 0) {
    FUN_007955d2(0);
  }
  else {
    in_ECX[0x2c] = 0;
  }
  return 1;
}




/* vtable slots: CAutoPage[106], CDxfPage[106], CGamenPage[106], CKeyPage[106], CMFCCustomColorsPropertyPage[106], CMFCMousePropertyPage[106], CMFCPropertyPage[106], CMFCStandardColorsPropertyPage[106], CMFCToolBarsCommandsPropertyPage[106], CMFCToolBarsKeyboardPropertyPage[106], CMFCToolBarsListPropertyPage[106], CMFCToolBarsMenuPropertyPage[106], CMFCToolBarsOptionsPropertyPage[106], CMFCToolBarsToolsPropertyPage[106], CMojiPage[106], CPropertyPage[106], CSenPage[106], CSonotaPage[106], CSonotaPage1[106] */
/* 007a1139  FUN_007a1139  88 bytes, 0 callers */

undefined4 FUN_007a1139(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar2 = FUN_007955d2(1);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x1b0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x20) != 0)) && (*(int *)(iVar2 + 0xd4) != 0)) &&
       ((*(uint *)(iVar2 + 0x84) & 0x1000020) != 0)) {
      PostMessageW(*(HWND *)(iVar2 + 0x20),0,0,0);
    }
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CAutoPage[107], CDxfPage[107], CGamenPage[107], CKeyPage[107], CMFCCustomColorsPropertyPage[107], CMFCMousePropertyPage[107], CMFCPropertyPage[107], CMFCStandardColorsPropertyPage[107], CMFCToolBarsCommandsPropertyPage[107], CMFCToolBarsKeyboardPropertyPage[107], CMFCToolBarsListPropertyPage[107], CMFCToolBarsMenuPropertyPage[107], CMFCToolBarsOptionsPropertyPage[107], CMFCToolBarsToolsPropertyPage[107], CMojiPage[107], CPropertyPage[107], CSenPage[107], CSonotaPage[107], CSonotaPage1[107] */
/* 007a1191  FUN_007a1191  32 bytes, 0 callers */

bool FUN_007a1191(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  return iVar2 == 0;
}




/* vtable slots: CAutoPage[67], CDxfPage[67], CGamenPage[67], CKeyPage[67], CMFCCustomColorsPropertyPage[67], CMFCMousePropertyPage[67], CMFCStandardColorsPropertyPage[67], CMFCToolBarsCommandsPropertyPage[67], CMFCToolBarsKeyboardPropertyPage[67], CMFCToolBarsListPropertyPage[67], CMFCToolBarsMenuPropertyPage[67], CMFCToolBarsOptionsPropertyPage[67], CMFCToolBarsToolsPropertyPage[67], CMojiPage[67], CPropertyPage[67], CSenPage[67], CSonotaPage[67], CSonotaPage1[67] */
/* 007a125f  PreTranslateMessage  17 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CPropertyPage::PreTranslateMessage(struct tagMSG *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CPropertyPage::PreTranslateMessage(CPropertyPage *this,tagMSG *param_1)

{
  FUN_007949fb(param_1);
  return 0;
}



