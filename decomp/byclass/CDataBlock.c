/* CDataBlock -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataBlock[1] */
/* 00499e30  FUN_00499e30  68 bytes, 0 callers */

undefined4 FUN_00499e30(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00499800();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x98);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataBlock[18] */
/* 00499f10  FUN_00499f10  70 bytes, 0 callers */

undefined4 FUN_00499f10(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_004b5070(in_ECX);
  uVar1 = (**(code **)(**(int **)(in_ECX + 0x94) + 0x48))(param_1);
  FUN_004bad50();
  return uVar1;
}




/* vtable slots: CDataBlock[15] */
/* 0049a3d0  FUN_0049a3d0  162 bytes, 1 callers */

undefined4 FUN_0049a3d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar2 = DAT_00a0cb5c;
  uVar1 = DAT_00a0cb58;
  DAT_00a0cb58 = 1;
  DAT_00a0cb5c = 0;
  FUN_004b5070(in_ECX);
  if (*(int *)(in_ECX + 0x94) != 0) {
    *(undefined1 *)(*(int *)(in_ECX + 0x94) + 0x61) = *(undefined1 *)(in_ECX + 0x28);
    (**(code **)(**(int **)(in_ECX + 0x94) + 0x3c))(param_1,param_2,param_3);
  }
  FUN_004bad50();
  DAT_00a0cb58 = uVar1;
  DAT_00a0cb5c = uVar2;
  return 1;
}




/* vtable slots: CDataBlock[3] */
/* 0049a640  FUN_0049a640  463 bytes, 0 callers */

void FUN_0049a640(void)

{
  uint extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  float10 fVar1;
  undefined8 local_40;
  uint uStack_38;
  undefined1 *local_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  undefined1 *local_28;
  undefined1 local_24 [4];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924a45;
  local_10 = ExceptionList;
  uStack_38 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = (undefined1 *)((int)&local_40 + 4);
  local_40._0_4_ = L"INSERT";
  CStringT<>();
  local_40 = (double)((ulonglong)local_40._4_4_ << 0x20);
  FUN_004a7e90();
  local_40 = (double)CONCAT44(0x49a68a,(wchar_t *)local_40);
  CStringT<>();
  local_8 = 0;
  local_2c = (undefined1 *)&local_40;
  local_40 = (double)(ulonglong)extraout_ECX;
  FUN_00414640(&local_40);
  local_20 = (undefined4 *)FUN_0049d480(local_24);
  local_8._0_1_ = 1;
  local_40 = (double)CONCAT44(*local_20,*(undefined4 *)(*(int *)(local_14 + 0x94) + 0x68));
  local_1c = local_20;
  FUN_004059f0(local_18,L"-%03d-%s");
  local_8 = (uint)local_8._1_3_ << 8;
  local_40 = (double)CONCAT44(0x49a6f1,(wchar_t *)local_40);
  FUN_00404540();
  local_30 = (undefined1 *)((int)&local_40 + 4);
  local_40._0_4_ = (wchar_t *)local_18;
  local_40._4_4_ = extraout_ECX_00;
  FUN_00403dd0();
  local_40 = (double)CONCAT44(local_40._4_4_,2);
  FUN_004a7e90();
  local_34 = (undefined1 *)((int)&local_40 + 4);
  local_40._0_4_ = (wchar_t *)(uint)*(byte *)(local_14 + 0x28);
  local_40._4_4_ = extraout_ECX_01;
  FUN_0049dea0((int)&local_40 + 4,*(undefined1 *)(local_14 + 0x2f),*(undefined1 *)(local_14 + 0x2e))
  ;
  local_40 = (double)CONCAT44(local_40._4_4_,8);
  FUN_004a7e90();
  local_40 = *(double *)(local_14 + 0x68);
  fVar1 = (float10)FUN_004a93e0();
  local_40 = (double)fVar1;
  FUN_004a77a0(10);
  local_40 = *(double *)(local_14 + 0x70);
  fVar1 = (float10)FUN_004a9450();
  local_40 = (double)fVar1;
  FUN_004a77a0(0x14);
  local_40 = *(double *)(local_14 + 0x78);
  FUN_004a77a0(0x29);
  local_40 = *(double *)(local_14 + 0x80);
  FUN_004a77a0(0x2a);
  local_40 = (*(double *)(local_14 + 0x88) * 180.0) / 3.141592653589793;
  FUN_004a77a0(0x32);
  local_8 = 0xffffffff;
  local_40 = (double)CONCAT44(0x49a7fe,(wchar_t *)local_40);
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataBlock[22] */
/* 0049abe0  GetLastImageRect  47 bytes, 0 callers */

/* Library Function - Single Match
    public: class CRect __thiscall CMFCToolBarImages::GetLastImageRect(void)const 
   
   Library: Visual Studio 2010 Debug */

undefined4 * __thiscall CMFCToolBarImages::GetLastImageRect(CMFCToolBarImages *this)

{
  undefined4 *in_stack_00000004;
  
  *in_stack_00000004 = *(undefined4 *)(this + 0x68);
  in_stack_00000004[1] = *(undefined4 *)(this + 0x6c);
  in_stack_00000004[2] = *(undefined4 *)(this + 0x70);
  in_stack_00000004[3] = *(undefined4 *)(this + 0x74);
  return in_stack_00000004;
}




/* vtable slots: CDataBlock[0] */
/* 0049ad50  FUN_0049ad50  16 bytes, 0 callers */

undefined ** FUN_0049ad50(void)

{
  return &PTR_s_CDataBlock_009fe144;
}




/* vtable slots: CDataBlock[16] */
/* 0049aeb0  FUN_0049aeb0  177 bytes, 0 callers */

undefined4
FUN_0049aeb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = DAT_00a0cb58;
  DAT_00a0cb58 = 1;
  FUN_004b5070(in_ECX);
  if ((*(byte *)(in_ECX + 0x28) & 0x40) != 0) {
    *(byte *)(*(int *)(in_ECX + 0x94) + 0x28) = *(byte *)(*(int *)(in_ECX + 0x94) + 0x28) | 0x40;
  }
  uVar2 = (**(code **)(**(int **)(in_ECX + 0x94) + 0x40))(param_1,param_2,param_3,param_4,param_5);
  FUN_004bad50();
  DAT_00a0cb58 = uVar1;
  return uVar2;
}




/* vtable slots: CDataBlock[5] */
/* 0049b160  FUN_0049b160  135 bytes, 1 callers */

undefined4 FUN_0049b160(void)

{
  uint uVar1;
  int iVar2;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092182f;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_004121b0(0x98);
  local_8 = 0;
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_004995e0(uVar1);
  }
  local_8 = 0xffffffff;
  FUN_0049b680(local_18);
  ExceptionList = local_10;
  return local_18;
}




/* vtable slots: CDataBlock[2] */
/* 0049b2c0  FUN_0049b2c0  324 bytes, 0 callers */

void FUN_0049b2c0(CArchive *param_1)

{
  int iVar1;
  long *plVar2;
  CArchive *this;
  int in_ECX;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  FUN_0042e690();
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    plVar2 = (long *)(in_ECX + 0x94);
    FUN_00420650(in_ECX + 0x68);
    FUN_00420650();
    FUN_00420650();
    FUN_00420650();
    this = (CArchive *)FUN_00420650();
    CArchive::operator>>(this,plVar2);
    *(undefined4 *)(in_ECX + 0x90) = 1;
  }
  else {
    uVar6 = *(undefined8 *)(in_ECX + 0x88);
    uVar5 = *(undefined8 *)(in_ECX + 0x80);
    uVar4 = *(undefined8 *)(in_ECX + 0x78);
    uVar3 = *(undefined8 *)(in_ECX + 0x70);
    FUN_00420820(*(undefined8 *)(in_ECX + 0x68));
    FUN_00420820(uVar3);
    FUN_00420820(uVar4);
    FUN_00420820(uVar5);
    FUN_00420820(uVar6);
    if (*(int *)(in_ECX + 0x90) == 0) {
      CArchive::operator<<(param_1,*(long *)(*(int *)(in_ECX + 0x94) + 0x68));
    }
    else {
      CArchive::operator<<(param_1,*(long *)(in_ECX + 0x94));
    }
  }
  return;
}




/* vtable slots: CDataBlock[6] */
/* 0049b680  FUN_0049b680  197 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0049b680(int param_1)

{
  int in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0042f720(param_1);
  FUN_004988c0(local_18,*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c),
               *(undefined4 *)(in_ECX + 0x70),*(undefined4 *)(in_ECX + 0x74));
  *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(in_ECX + 0x78);
  *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(in_ECX + 0x80);
  *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(in_ECX + 0x88);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(in_ECX + 0x90);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(in_ECX + 0x94);
  return;
}




/* vtable slots: CDataBlock[4] */
/* 0049b930  FUN_0049b930  769 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0049b930(int param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  int *piStack_17c;
  uint uStack_178;
  undefined1 local_15c [4];
  undefined4 *local_158;
  undefined4 *local_154;
  int local_150;
  undefined1 local_14c [4];
  int *local_148;
  int local_144;
  undefined1 local_140 [260];
  double local_3c;
  double local_34;
  double local_2c;
  double local_24;
  double local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924b4b;
  local_10 = ExceptionList;
  uStack_178 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_150 = 0;
  local_148 = in_ECX;
  local_14 = uStack_178;
  if ((*(byte *)(in_ECX + 10) & 0x40) == 0) {
    piStack_17c = (int *)0x0;
    local_144 = FUN_0042afb0(*(undefined1 *)((int)in_ECX + 0x2f),*(undefined1 *)((int)in_ECX + 0x2e)
                             ,(char)in_ECX[10]);
  }
  else {
    local_144 = 0;
  }
  piStack_17c = (int *)0x49b9c3;
  CStringT<>();
  local_8 = 0;
  FUN_00414640(&piStack_17c);
  local_158 = (undefined4 *)FUN_004efde0(local_15c);
  local_8._0_1_ = 1;
  piStack_17c = (int *)*local_158;
  local_154 = local_158;
  FUN_0049aa30(local_14c,"-%03d-%s",*(undefined4 *)(local_148[0x25] + 0x68));
  local_8 = (uint)local_8._1_3_ << 8;
  piStack_17c = (int *)0x49ba46;
  FUN_00404540();
  piStack_17c = (int *)0x49ba51;
  piStack_17c = (int *)FUN_00404920();
  FUN_0041efc0(local_140);
  piStack_17c = (int *)0x49ba74;
  piStack_17c = (int *)(**(code **)(*local_148 + 0x28))();
  fVar5 = (float10)FUN_005ea230((int)*(undefined8 *)(local_148 + 0x1a),
                                (int)((ulonglong)*(undefined8 *)(local_148 + 0x1a) >> 0x20));
  local_3c = (double)fVar5;
  piStack_17c = (int *)0x49baa6;
  piStack_17c = (int *)(**(code **)(*local_148 + 0x28))();
  fVar5 = (float10)FUN_005ea290((int)*(undefined8 *)(local_148 + 0x1c),
                                (int)((ulonglong)*(undefined8 *)(local_148 + 0x1c) >> 0x20));
  local_34 = (double)fVar5;
  piStack_17c = (int *)((ulonglong)*(undefined8 *)(local_148 + 0x22) >> 0x20);
  fVar5 = (float10)FUN_005ea2f0((int)*(undefined8 *)(local_148 + 0x22));
  local_2c = (double)fVar5;
  iVar3 = *(int *)(param_1 + 8);
  piStack_17c = (int *)0x49baff;
  iVar4 = (**(code **)(*local_148 + 0x28))();
  dVar1 = *(double *)(local_148 + 0x1e);
  dVar2 = *(double *)(iVar3 + 0x24f0 + iVar4 * 8);
  iVar3 = *(int *)(param_1 + 8);
  piStack_17c = (int *)0x49bb40;
  iVar4 = (**(code **)(*(int *)local_148[0x25] + 0x28))();
  local_24 = (dVar1 * dVar2) / *(double *)(iVar3 + 0x24f0 + iVar4 * 8);
  iVar3 = *(int *)(param_1 + 8);
  piStack_17c = (int *)0x49bb6f;
  iVar4 = (**(code **)(*local_148 + 0x28))();
  dVar1 = *(double *)(local_148 + 0x20);
  dVar2 = *(double *)(iVar3 + 0x24f0 + iVar4 * 8);
  iVar3 = *(int *)(param_1 + 8);
  piStack_17c = (int *)0x49bbb3;
  iVar4 = (**(code **)(*(int *)local_148[0x25] + 0x28))();
  local_1c = (dVar1 * dVar2) / *(double *)(iVar3 + 0x24f0 + iVar4 * 8);
  if (local_144 != -999) {
    piStack_17c = &local_144;
    local_150 = (**(code **)(param_1 + 0x4c158))("SFIG_LOCATE");
  }
  if (local_150 < 0) {
    piStack_17c = (int *)0x49bc03;
    FUN_005e6520();
  }
  local_8 = 0xffffffff;
  piStack_17c = (int *)0x49bc15;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CDataBlock[7] */
/* 0049bc40  FUN_0049bc40  359 bytes, 0 callers */

undefined4 FUN_0049bc40(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = FUN_0079d98a(&PTR_s_CDataBlock_009fe144);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_00438910(param_1);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else if (*(int *)(param_1 + 0x90) == 0) {
      iVar2 = FUN_00498960(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                           *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x74));
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else if (*(double *)(in_ECX + 0x78) == *(double *)(param_1 + 0x78)) {
        if (*(double *)(in_ECX + 0x80) == *(double *)(param_1 + 0x80)) {
          if (*(double *)(in_ECX + 0x88) == *(double *)(param_1 + 0x88)) {
            if ((*(int *)(in_ECX + 0x94) == 0) || (*(int *)(param_1 + 0x94) == 0)) {
              uVar3 = 0;
            }
            else {
              cVar1 = FID_conflict_operator__
                                (*(undefined4 *)(*(int *)(param_1 + 0x94) + 0x70),
                                 *(undefined4 *)(*(int *)(param_1 + 0x94) + 0x74));
              if (cVar1 == '\0') {
                uVar3 = 0;
              }
              else {
                iVar2 = (**(code **)(**(int **)(in_ECX + 0x94) + 0x1c))
                                  (*(undefined4 *)(param_1 + 0x94));
                if (iVar2 == 0) {
                  uVar3 = 0;
                }
                else {
                  uVar3 = 1;
                }
              }
            }
          }
          else {
            uVar3 = 0;
          }
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



