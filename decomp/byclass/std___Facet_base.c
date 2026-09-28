/* std::_Facet_base -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::_Facet_base[0] */
/* 00555210  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall Concurrency::ISource<unsigned int>::`scalar deleting
   destructor'(unsigned int)
    public: virtual void * __thiscall Concurrency::ISource<enum Concurrency::agent_status>::`scalar
   deleting destructor'(unsigned int)
    public: virtual void * __thiscall Concurrency::ITarget<unsigned int>::`scalar deleting
   destructor'(unsigned int)
    public: virtual void * __thiscall Concurrency::ITarget<enum Concurrency::agent_status>::`scalar
   deleting destructor'(unsigned int)
     11 names - too many to list
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4 FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005544c0();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,4);
  }
  return in_ECX;
}



