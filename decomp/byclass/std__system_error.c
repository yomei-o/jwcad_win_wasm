/* std::system_error -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::system_error[0] */
/* 00555390  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall `void __cdecl Concurrency::wait(unsigned
   int)'::`7'::TimerObj::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::_System_error::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::ios_base::failure::`scalar deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall std::future_error::`scalar deleting destructor'(unsigned int)
     5 names - too many to list
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4 FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005547b0();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x14);
  }
  return in_ECX;
}



