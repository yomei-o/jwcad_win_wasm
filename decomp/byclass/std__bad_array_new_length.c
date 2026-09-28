/* std::bad_array_new_length -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::bad_array_new_length[0] */
/* 004813e0  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall Concurrency::details::_Interruption_exception::`scalar
   deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::__non_rtti_object::`scalar deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall std::bad_alloc::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::bad_array_new_length::`scalar deleting
   destructor'(unsigned int)
     39 names - too many to list
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4 FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00481020();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0xc);
  }
  return in_ECX;
}



