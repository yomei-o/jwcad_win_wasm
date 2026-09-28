/* std::_System_error -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::_System_error[1], std::bad_alloc[1], std::bad_array_new_length[1], std::bad_cast[1], std::bad_exception[1], std::exception[1], std::ios_base::failure[1], std::length_error[1], std::logic_error[1], std::out_of_range[1], std::runtime_error[1], std::system_error[1] */
/* 004947c0  what  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual char const * __thiscall std::exception::what(void)const 
   
   Library: Visual Studio */

char * __thiscall std::exception::what(exception *this)

{
  char *local_c;
  
  if (*(int *)(this + 4) == 0) {
    local_c = "Unknown exception";
  }
  else {
    local_c = *(char **)(this + 4);
  }
  return local_c;
}




/* vtable slots: std::_System_error[0] */
/* 00555270  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

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
  
  FUN_00481020();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x14);
  }
  return in_ECX;
}



