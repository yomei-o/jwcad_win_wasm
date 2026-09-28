/* CMFCAcceleratorKeyAssignCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCAcceleratorKeyAssignCtrl[1] */
/* 008d8abf  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCAcceleratorKeyAssignCtrl::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCAcceleratorKeyAssignCtrl::_scalar_deleting_destructor_
          (CMFCAcceleratorKeyAssignCtrl *this,uint param_1)

{
  ~CMFCAcceleratorKeyAssignCtrl(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x98);
    }
  }
  return this;
}




/* vtable slots: CMFCAcceleratorKeyAssignCtrl[10] */
/* 008d8af2  FUN_008d8af2  6 bytes, 0 callers */

undefined ** FUN_008d8af2(void)

{
  return &PTR_FUN_009a99e8;
}




/* vtable slots: CMFCAcceleratorKeyAssignCtrl[67] */
/* 008d8b07  FUN_008d8b07  342 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008d8b07(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  CMFCAcceleratorKeyAssignCtrl *in_ECX;
  int iVar5;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8d8b13;
  iVar5 = 1;
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 0x100) {
LAB_008d8b5e:
    if (*(int *)(in_ECX + 0x80) != 0) {
      iVar3 = iVar5;
      if ((*(uint *)(param_1 + 0xc) & 0x40000000) == 0) {
        CMFCAcceleratorKeyAssignCtrl::ResetKey(in_ECX);
      }
      goto LAB_008d8b7c;
    }
LAB_008d8b85:
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 == 0x10) {
      uVar4 = 4;
    }
    else if (iVar2 == 0x11) {
      uVar4 = 8;
    }
    else {
      if (iVar2 != 0x12) {
        if (*(int *)(in_ECX + 0x94) == 0) {
          *(undefined4 *)(in_ECX + 0x94) = 1;
          return 1;
        }
        *(undefined2 *)(in_ECX + 0x86) = *(undefined2 *)(param_1 + 8);
        if (iVar5 != 0) {
          in_ECX[0x84] = (CMFCAcceleratorKeyAssignCtrl)((byte)in_ECX[0x84] | 1);
          *(undefined4 *)(in_ECX + 0x80) = 1;
        }
        goto LAB_008d8bdd;
      }
      uVar4 = 0x10;
    }
    FUN_008d8c8e(uVar4,iVar5);
  }
  else {
    iVar3 = 0;
    if (iVar2 != 0x101) {
      if (iVar2 == 0x104) goto LAB_008d8b5e;
      if (iVar2 != 0x105) {
        if (((iVar2 == 0x201) || (iVar2 == 0x204)) || (iVar2 == 0x207)) {
          *(undefined4 *)(in_ECX + 0x94) = 1;
          FUN_00797df8();
          return 1;
        }
        goto LAB_008d8c53;
      }
    }
LAB_008d8b7c:
    iVar5 = iVar3;
    if (*(int *)(in_ECX + 0x80) == 0) goto LAB_008d8b85;
  }
LAB_008d8bdd:
  if (((byte)in_ECX[0x84] & 0x1d) != 1) {
LAB_008d8c06:
    CStringT<>();
    local_8 = 0;
    FUN_0082afd5(local_14);
    FUN_00797ece(local_14[0]);
    FUN_00406b10();
    return 1;
  }
  sVar1 = *(short *)(in_ECX + 0x86);
  if (sVar1 != 9) {
    if (sVar1 == 0x1b) {
      CMFCAcceleratorKeyAssignCtrl::ResetKey(in_ECX);
      return 1;
    }
    if (sVar1 != 0xe5) goto LAB_008d8c06;
  }
  CMFCAcceleratorKeyAssignCtrl::ResetKey(in_ECX);
LAB_008d8c53:
  uVar4 = FUN_007949fb(param_1);
  return uVar4;
}



