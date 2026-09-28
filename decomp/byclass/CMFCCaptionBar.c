/* CMFCCaptionBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCCaptionBar[1] */
/* 00878454  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCCaptionBar::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCCaptionBar::_scalar_deleting_destructor_(CMFCCaptionBar *this,uint param_1)

{
  ~CMFCCaptionBar(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x4c0);
    }
  }
  return this;
}




/* vtable slots: CMFCCaptionBar[152] */
/* 0087853c  FUN_0087853c  51 bytes, 0 callers */

void FUN_0087853c(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x210);
  guard_check_icall();
  (*pcVar1)();
  iVar2 = in_ECX[0x127];
  *param_1 = 0x7fff;
  param_1[1] = iVar2;
  return;
}




/* vtable slots: CMFCCaptionBar[10] */
/* 008786f4  FUN_008786f4  6 bytes, 0 callers */

undefined ** FUN_008786f4(void)

{
  return &PTR_FUN_00999cb8;
}




/* vtable slots: CMFCCaptionBar[0] */
/* 008786fa  FUN_008786fa  6 bytes, 0 callers */

undefined ** FUN_008786fa(void)

{
  return &PTR_s_CMFCCaptionBar_0099979c;
}




/* vtable slots: CMFCCaptionBar[205] */
/* 00878700  FUN_00878700  260 bytes, 0 callers */

int * FUN_00878700(int *param_1,int *param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0x418) == 1) {
    FUN_00566800(param_1,param_3);
  }
  else {
    local_8 = 0;
    iVar7 = 0;
    local_10 = 0;
    local_c = 0;
    iVar3 = 0;
    iVar5 = 0;
    if (0 < *(int *)(in_ECX + 0x418)) {
      do {
        uVar6 = local_c;
        piVar2 = (int *)FUN_0049a990(iVar7);
        if (*(int *)(*piVar2 + -0xc) != 0) {
          local_14 = 0;
          if (uVar6 != 0) {
            pcVar1 = *(code **)(*param_2 + 0x28);
            iVar3 = FUN_007c2511();
            guard_check_icall(iVar3 + 300);
            local_14 = (*pcVar1)();
            uVar6 = local_c;
          }
          uVar4 = FUN_0049a990(iVar7);
          FUN_00566800(&local_1c,uVar4);
          local_8 = local_8 + local_1c;
          if (local_10 <= local_18) {
            local_10 = local_18;
          }
          if (local_14 != 0) {
            pcVar1 = *(code **)(*param_2 + 0x28);
            guard_check_icall(local_14);
            (*pcVar1)();
            uVar6 = local_c;
          }
        }
        local_c = uVar6 ^ 1;
        iVar7 = iVar7 + 1;
        iVar3 = local_10;
        iVar5 = local_8;
      } while (iVar7 < *(int *)(in_ECX + 0x418));
    }
    *param_1 = iVar5;
    param_1[1] = iVar3;
  }
  return param_1;
}




/* vtable slots: CMFCCaptionBar[200] */
/* 008788f4  FUN_008788f4  201 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008788f4(undefined4 param_1,LONG param_2,LONG param_3,int param_4,LONG param_5)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x34);
  guard_check_icall(param_1,in_ECX,param_2,param_3,param_4,param_5,param_2,param_3,param_4,param_5,0
                   );
  (*pcVar1)();
  if (*(int *)(in_ECX + 0x2c4) != 0) {
    local_18.left = param_2;
    local_18.top = param_3;
    local_18.right = param_4;
    local_18.bottom = param_5;
    InflateRect(&local_18,-4,-4);
    local_18.right = local_18.right + (*(int *)(in_ECX + 0x4ac) - *(int *)(in_ECX + 0x4b4));
    piVar2 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar2 + 0xd0);
    guard_check_icall(param_1,in_ECX,local_18.left,local_18.top,local_18.right,local_18.bottom);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCCaptionBar[201] */
/* 008789bd  FUN_008789bd  98 bytes, 0 callers */

void FUN_008789bd(undefined4 param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  InflateRect((LPRECT)&param_2,2,0);
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0xd4);
  guard_check_icall(param_1,in_ECX,param_2,param_3,param_4,param_5,*(undefined4 *)(in_ECX + 0x2c0),
                    *(undefined4 *)(in_ECX + 0x488));
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCCaptionBar[203] */
/* 00878cf5  FUN_00878cf5  184 bytes, 0 callers */

void FUN_00878cf5(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int in_ECX;
  HDC hdc;
  undefined1 local_10 [12];
  
  if (*(HICON *)(in_ECX + 0x2cc) == (HICON)0x0) {
    if (0 < *(int *)(in_ECX + 0x2d4)) {
      if (*(int *)(in_ECX + 1000) == 0) {
        param_4 = *(int *)(in_ECX + 0x3f8) - *(int *)(in_ECX + 0x3f0);
        param_5 = *(int *)(in_ECX + 0x3fc) - *(int *)(in_ECX + 0x3f4);
      }
      else {
        param_4 = param_4 - param_2;
        param_5 = param_5 - param_3;
      }
      FUN_007eb6ca(local_10,param_4,param_5,0);
      FUN_007e8cae(param_1,param_2,param_3,0,0,0,0,0,0,0xff);
      FUN_007e98b8(local_10);
    }
  }
  else {
    hdc = (HDC)0x0;
    if (param_1 != 0) {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawIconEx(hdc,param_2,param_3,*(HICON *)(in_ECX + 0x2cc),param_4 - param_2,param_5 - param_3,0,
               (HBRUSH)0x0,3);
  }
  return;
}




/* vtable slots: CMFCCaptionBar[202] */
/* 00878dad  FUN_00878dad  299 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00878dad(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  int local_38 [2];
  int local_30;
  int *local_2c;
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = param_1;
  if (*(int *)(in_ECX + 0x418) == 1) {
    FUN_007c2378(param_6,&param_2,0x8024);
  }
  else {
    local_1c = param_2;
    iVar5 = 0;
    local_24 = 0;
    if (0 < *(int *)(in_ECX + 0x418)) {
      local_28 = in_ECX + 0x410;
      local_30 = in_ECX;
      do {
        uVar6 = local_24;
        piVar2 = (int *)FUN_0049a990(iVar5);
        if (*(int *)(*piVar2 + -0xc) != 0) {
          local_20 = 0;
          if (uVar6 != 0) {
            pcVar1 = *(code **)(*param_1 + 0x28);
            iVar3 = FUN_007c2511();
            guard_check_icall(iVar3 + 300);
            local_20 = (*pcVar1)();
          }
          uStack_14 = param_3;
          uStack_10 = param_4;
          uStack_c = param_5;
          local_18 = local_1c;
          uVar4 = FUN_0049a990(iVar5);
          param_1 = local_2c;
          FUN_00566800(local_38,uVar4);
          uVar4 = FUN_0049a990(iVar5);
          FUN_007c2378(uVar4,&local_18,0x8024);
          if (local_20 != 0) {
            pcVar1 = *(code **)(*param_1 + 0x28);
            guard_check_icall(local_20);
            (*pcVar1)();
          }
          local_1c = local_1c + local_38[0];
          uVar6 = local_24;
        }
        local_24 = uVar6 ^ 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(local_30 + 0x418));
    }
  }
  return;
}




/* vtable slots: CMFCCaptionBar[67] */
/* 00879913  FUN_00879913  113 bytes, 0 callers */

void FUN_00879913(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 < 0x203) {
    if (((uVar1 != 0x202) && (uVar1 != 0x100)) && (uVar1 != 0x104)) {
      iVar2 = uVar1 - 0x200;
LAB_0087993c:
      if ((iVar2 != 0) && (iVar2 != 1)) goto LAB_00879964;
    }
  }
  else if ((uVar1 != 0x204) && (uVar1 != 0x205)) {
    iVar2 = uVar1 - 0x207;
    goto LAB_0087993c;
  }
  iVar2 = *(int *)(in_ECX + 0x2c8);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x20) != 0)) {
    SendMessageW(*(HWND *)(iVar2 + 0x20),0x407,0,param_1);
  }
LAB_00879964:
  FUN_007ee372(param_1);
  return;
}



