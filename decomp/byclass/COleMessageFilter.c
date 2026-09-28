/* COleMessageFilter -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleMessageFilter[1] */
/* 007cc2fa  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall COleMessageFilter::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
COleMessageFilter::_scalar_deleting_destructor_(COleMessageFilter *this,uint param_1)

{
  ~COleMessageFilter(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x44);
    }
  }
  return this;
}




/* vtable slots: COleMessageFilter[20] */
/* 007cc33c  FUN_007cc33c  4 bytes, 0 callers */

void FUN_007cc33c(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  return;
}




/* vtable slots: COleMessageFilter[21] */
/* 007cc340  FUN_007cc340  12 bytes, 0 callers */

void FUN_007cc340(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
  }
  return;
}




/* vtable slots: COleMessageFilter[14] */
/* 007cc34c  FUN_007cc34c  6 bytes, 0 callers */

undefined ** FUN_007cc34c(void)

{
  return &PTR_DAT_00985930;
}




/* vtable slots: COleMessageFilter[23] */
/* 007cc3b0  IsSignificantMessage  86 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall COleMessageFilter::IsSignificantMessage(struct tagMSG *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release */

int __thiscall COleMessageFilter::IsSignificantMessage(COleMessageFilter *this,tagMSG *param_1)

{
  BOOL BVar1;
  uint uVar2;
  tagMSG local_20;
  
  uVar2 = 0;
  while ((BVar1 = PeekMessageW(&local_20,(HWND)0x0,*(UINT *)((int)&DAT_009858d8 + uVar2),
                               *(UINT *)((int)&DAT_009858d8 + uVar2),2), BVar1 == 0 ||
         (((local_20.message == 0x100 || (local_20.message == 0x104)) &&
          (((uint)local_20.lParam >> 0x10 & 0x4000) != 0))))) {
    uVar2 = uVar2 + 4;
    if (0x3b < uVar2) {
      return 0;
    }
  }
  return 1;
}




/* vtable slots: COleMessageFilter[24] */
/* 007cc4e9  FUN_007cc4e9  68 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007cc4e9(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_008149b2(param_1,0,0,0);
  iVar1 = FUN_00814ace();
  if (iVar1 == 1) {
    uVar2 = FUN_007cc53e();
    return uVar2;
  }
  FUN_00814a3f();
  return 0xffffffff;
}




/* vtable slots: COleMessageFilter[22] */
/* 007cc553  OnMessagePending  70 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall COleMessageFilter::OnMessagePending(struct tagMSG const *)
   
   Library: Visual Studio 2012 Release */

int __thiscall COleMessageFilter::OnMessagePending(COleMessageFilter *this,tagMSG *param_1)

{
  BOOL BVar1;
  int iVar2;
  tagMSG local_20;
  
  iVar2 = 0;
  BVar1 = PeekMessageW(&local_20,(HWND)0x0,0xf,0xf,3);
  if (BVar1 != 0) {
    iVar2 = 1;
    do {
      DispatchMessageW(&local_20);
      BVar1 = PeekMessageW(&local_20,(HWND)0x0,0xf,0xf,3);
    } while (BVar1 != 0);
  }
  return iVar2;
}




/* vtable slots: COleMessageFilter[25] */
/* 007cc599  FUN_007cc599  69 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007cc599(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_008149b2(param_1,1,0,0);
  iVar1 = FUN_00814ace();
  if (iVar1 == 1) {
    uVar2 = FUN_007cc5ef();
    return uVar2;
  }
  FUN_00814a3f();
  return 0xffffffff;
}



