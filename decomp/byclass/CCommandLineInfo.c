/* CCommandLineInfo -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CCommandLineInfo[1] */
/* 007b10e4  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CCommandLineInfo::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CCommandLineInfo::_scalar_deleting_destructor_(CCommandLineInfo *this,uint param_1)

{
  ~CCommandLineInfo(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2c);
    }
  }
  return this;
}




/* vtable slots: CCommandLineInfo[3] */
/* 007b18bc  ParseParam  42 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CCommandLineInfo::ParseParam(char const *,int,int)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CCommandLineInfo::ParseParam(CCommandLineInfo *this,char *param_1,int param_2,int param_3)

{
  if (param_2 == 0) {
    FUN_007b1b89(param_1);
  }
  else {
    ParseParamFlag(this,param_1);
  }
  ParseLast(this,param_3);
  return;
}




/* vtable slots: CCommandLineInfo[4] */
/* 007b18e6  ParseParam  81 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CCommandLineInfo::ParseParam(char const *,int,int)
    public: virtual void __thiscall CCommandLineInfo::ParseParam(wchar_t const *,int,int)
   
   Library: Visual Studio 2015 Release */

void ParseParam(undefined4 param_1,int param_2,int param_3)

{
  CCommandLineInfo *in_ECX;
  undefined4 local_14;
  
  if (param_2 == 0) {
    FUN_007b1bd5(param_1);
  }
  else {
    CStringT<>(param_1);
    CCommandLineInfo::ParseParamFlag(in_ECX,local_14);
    FUN_00406b10();
  }
  CCommandLineInfo::ParseLast(in_ECX,param_3);
  return;
}



