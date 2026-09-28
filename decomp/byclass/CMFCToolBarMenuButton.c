/* CMFCToolBarMenuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarMenuButton[1] */
/* 00874f60  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCPropertyGridProperty::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCPropertyGridProperty::_scalar_deleting_destructor_(CMFCPropertyGridProperty *this,uint param_1)

{
  FUN_00874eb0();
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




/* vtable slots: CMFCToolBarMenuButton[0] */
/* 00876b7c  FUN_00876b7c  6 bytes, 0 callers */

undefined ** FUN_00876b7c(void)

{
  return &PTR_s_CMFCToolBarMenuButton_00a00a14;
}




/* vtable slots: CMFCToolBarMenuButton[6], CTasksPaneHistoryButton[6], CTasksPaneMenuButton[6] */
/* 00877450  FUN_00877450  1245 bytes, 3 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00877450(undefined4 param_1,LONG *param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7,undefined4 param_8)

{
  LPRECT lprc;
  int iVar1;
  LONG *pLVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  int *in_ECX;
  undefined4 uVar7;
  code *pcVar8;
  int local_5c;
  int local_58;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  LONG *local_38;
  undefined4 local_34;
  int *local_30;
  int *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_38 = param_2;
  lprc = (LPRECT)(in_ECX + 0x32);
  local_34 = param_1;
  local_30 = in_ECX;
  SetRectEmpty(lprc);
  SetRectEmpty((LPRECT)(in_ECX + 0x36));
  if (in_ECX[0x25] != 0) {
    FUN_008755b2(param_1,local_38,param_3,param_5,param_6,param_8,0);
    return;
  }
  iVar3 = FUN_007c2574();
  local_44 = *(int *)(iVar3 + 0x50);
  if (in_ECX[0x2c] != 0) {
    in_ECX[9] = in_ECX[9] & 0xfffeffff;
  }
  if (param_6 == 0) {
    pcVar8 = *(code **)(*in_ECX + 0x70);
    guard_check_icall();
    iVar3 = (*pcVar8)();
    uVar4 = 0;
    if (iVar3 != 0) goto LAB_008774f3;
  }
  else {
LAB_008774f3:
    uVar4 = 1;
  }
  pLVar2 = local_38;
  FUN_0088114d(local_34,local_38,uVar4,0);
  FUN_0081507c(&local_4c);
  if (DAT_00a127b4 != 0) {
    local_4c = local_4c * 2;
    local_48 = local_48 * 2;
  }
  local_28.left = *pLVar2;
  local_28.top = pLVar2[1];
  local_28.right = pLVar2[2];
  local_28.bottom = pLVar2[3];
  if (local_30[0x12] == 0) {
    local_40 = 0;
    piVar5 = &local_40;
    local_3c = 0;
  }
  else {
    piVar5 = (int *)FUN_007c2574();
    pcVar8 = *(code **)(*piVar5 + 0x140);
    guard_check_icall(&local_40);
    piVar5 = (int *)(*pcVar8)();
  }
  local_2c = (int *)*piVar5;
  local_3c = piVar5[1];
  if ((local_2c != (int *)0x0) || (local_3c != 0)) {
    InflateRect(&local_28,~((int)local_2c / 2),~((int)local_3c / 2));
  }
  local_18.left = *local_38;
  local_18.top = local_38[1];
  local_18.right = local_38[2];
  local_18.bottom = local_38[3];
  lprc->left = local_28.left;
  in_ECX[0x33] = local_28.top;
  in_ECX[0x34] = local_28.right;
  in_ECX[0x35] = local_28.bottom;
  piVar5 = (int *)FUN_007c2574();
  pcVar8 = *(code **)(*piVar5 + 0x2dc);
  guard_check_icall();
  uVar6 = (*pcVar8)();
  InflateRect(&local_18,-(-(uint)(param_4 != 0) & uVar6),-(~-(uint)(param_4 != 0) & uVar6));
  piVar5 = local_30;
  if (local_30[0x24] != 0) {
    if (param_4 == 0) {
      local_18.bottom = local_18.bottom + (-1 - local_48);
      local_30[0x33] = local_18.bottom;
    }
    else {
      local_18.right = local_18.right - (local_4c + (int)local_2c);
      local_30[0x32] = local_18.right + 1;
      if ((local_2c != (int *)0x0) || (local_3c != 0)) {
        OffsetRect((LPRECT)(local_30 + 0x32),1 - (int)local_2c / 2,1 - (int)local_3c / 2);
      }
    }
  }
  local_3c = piVar5[9];
  if (local_44 == 0) {
    if ((((piVar5[0x27] != 0) && (piVar5[8] != 0)) && (piVar5[8] != -1)) && (piVar5[0x2a] == 0)) {
      uVar6 = local_3c & 0xfffdffff;
      goto LAB_0087769a;
    }
    if (piVar5[0x23] != 0) {
      uVar6 = local_3c | 0x20000;
      goto LAB_0087769a;
    }
  }
  else {
    uVar6 = local_3c & 0xfffcffff;
LAB_0087769a:
    piVar5[9] = uVar6;
  }
  iVar3 = piVar5[0x11];
  piVar5[0x11] = 1;
  FUN_00881666(local_34,&local_18,param_3,param_4,param_5,param_6,param_7,param_8);
  piVar5[0x11] = iVar3;
  if (piVar5[0x24] == 0) goto LAB_008777f7;
  if (((piVar5[9] & 0x30000U) != 0) && (local_44 == 0)) {
    OffsetRect((LPRECT)(piVar5 + 0x32),1,1);
  }
  if ((((param_6 != 0) || ((piVar5[9] & 0x20000U) != 0)) || (piVar5[0x23] != 0)) &&
     (((piVar5[8] != 0 && (piVar5[8] != -1)) && (piVar5[0x2a] == 0)))) {
    iVar3 = ((LPRECT)(piVar5 + 0x32))->left;
    iVar1 = piVar5[0x33];
    local_5c = piVar5[0x34];
    local_58 = piVar5[0x35];
    if (param_4 == 0) {
      local_58 = iVar1 + 2;
    }
    else {
      local_5c = iVar3 + 2;
    }
    uVar4 = 0;
    if ((param_6 != 0) || ((local_30[9] & 0x30000U) != 0)) {
      uVar4 = 1;
    }
    piVar5 = local_30;
    if (local_30[0x27] == 0) {
      local_2c = (int *)FUN_007c2574();
      piVar5 = local_30;
      pcVar8 = *(code **)(*local_2c + 0x8c);
      guard_check_icall(local_34,local_30,iVar3,iVar1,local_5c,local_58,uVar4,param_4);
      (*pcVar8)();
    }
  }
  if (param_5 == 0) {
    if ((piVar5[9] & 0x40000U) == 0) goto LAB_008777ba;
LAB_008777d8:
    uVar4 = 1;
  }
  else {
    pcVar8 = *(code **)(*piVar5 + 0x60);
    guard_check_icall();
    iVar3 = (*pcVar8)();
    if (iVar3 == 0) goto LAB_008777d8;
LAB_008777ba:
    uVar4 = 0;
  }
  if ((param_4 == 0) || (piVar5[0x2a] != 0)) {
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
  }
  FUN_00814d1c(local_34,uVar7,piVar5 + 0x32,uVar4,&local_4c);
LAB_008777f7:
  piVar5[9] = local_3c;
  if (param_5 == 0) {
    if (((local_3c & 0x30000) == 0) && (piVar5[0x23] == 0)) {
      if (param_6 == 0) {
        return;
      }
      if ((local_3c & 0x150000) != 0) {
        return;
      }
      local_2c = (int *)FUN_007c2574();
      pcVar8 = *(code **)(*local_2c + 0x88);
      guard_check_icall(local_34,local_30,*local_38,local_38[1],local_38[2],local_38[3],2);
    }
    else if ((local_44 == 0) &&
            ((((piVar5[0x27] != 0 && (piVar5[8] != 0)) && (piVar5[8] != -1)) && (piVar5[0x2a] == 0))
            )) {
      local_18.right = local_18.right + 1;
      local_2c = (int *)FUN_007c2574();
      pcVar8 = *(code **)(*local_2c + 0x88);
      guard_check_icall(local_34,local_30,local_18.left,local_18.top,local_18.right,local_18.bottom,
                        2);
      (*pcVar8)();
      local_2c = (int *)FUN_007c2574();
      pcVar8 = *(code **)(*local_2c + 0x88);
      guard_check_icall(local_34,local_30,lprc->left,in_ECX[0x33],in_ECX[0x34],in_ECX[0x35],1);
    }
    else {
      local_2c = (int *)FUN_007c2574();
      pcVar8 = *(code **)(*local_2c + 0x88);
      guard_check_icall(local_34,local_30,*local_38,local_38[1],local_38[2],local_38[3],1);
    }
    (*pcVar8)();
  }
  return;
}



