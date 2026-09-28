/* std::_Iostream_error_category2 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::_Iostream_error_category2[0] */
/* 00555240  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: void * __thiscall std::shared_ptr<struct _EXCEPTION_RECORD const >::`scalar deleting
   destructor'(unsigned int)
    public: virtual void * __thiscall std::_Generic_error_category::`scalar deleting
   destructor'(unsigned int)
    public: virtual void * __thiscall std::_Iostream_error_category::`scalar deleting
   destructor'(unsigned int)
    public: virtual void * __thiscall std::_System_error_category::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4 FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004472a0();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,8);
  }
  return in_ECX;
}




/* vtable slots: std::_Iostream_error_category2[3] */
/* 0055a360  default_error_condition  32 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual class std::error_condition __thiscall
   std::_System_error_category::default_error_condition(int)const 
    public: virtual class std::error_condition __thiscall
   std::error_category::default_error_condition(int)const 
   
   Library: Visual Studio */

undefined4 default_error_condition(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_ECX;
  
  FUN_0041c8d0(param_2,in_ECX);
  return param_1;
}




/* vtable slots: std::_Iostream_error_category2[4] */
/* 0055b150  equivalent  71 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual bool __thiscall std::error_category::equivalent(class std::error_code const
   &,int)const 
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

bool __thiscall
std::error_category::equivalent(error_category *this,error_code *param_1,int param_2)

{
  bool bVar1;
  error_category *peVar2;
  int iVar3;
  
  peVar2 = (error_category *)FUN_0044f260();
  bVar1 = operator==(this,peVar2);
  if ((bVar1) && (iVar3 = FUN_00404920(), iVar3 == param_2)) {
    return true;
  }
  return false;
}




/* vtable slots: std::_Iostream_error_category2[5] */
/* 0055b1a0  FUN_0055b1a0  49 bytes, 0 callers */

void FUN_0055b1a0(undefined4 param_1,undefined4 param_2)

{
  error_condition *peVar1;
  int *in_ECX;
  error_condition *peVar2;
  error_condition local_10 [12];
  
  peVar2 = local_10;
  peVar1 = (error_condition *)(**(code **)(*in_ECX + 0xc))(peVar2,param_1,param_2);
  std::operator==(peVar1,peVar2);
  return;
}




/* vtable slots: std::_Iostream_error_category2[2] */
/* 0055b7b0  FUN_0055b7b0  97 bytes, 0 callers */

undefined4 FUN_0055b7b0(undefined4 param_1,int param_2)

{
  char *pcVar1;
  
  if (param_2 == 1) {
    FUN_00553080("iostream stream error",0x15);
  }
  else {
    pcVar1 = std::_Syserror_map(param_2);
    FUN_00552ff0(pcVar1);
  }
  return param_1;
}




/* vtable slots: std::_Iostream_error_category2[1] */
/* 0055b890  FUN_0055b890  16 bytes, 0 callers */

char * FUN_0055b890(void)

{
  return "iostream";
}



