/* std::locale::facet -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::locale::facet[0] */
/* 005552d0  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: void * __thiscall std::_Func_impl<bool (__cdecl*)(enum Concurrency::agent_status const
   &),class std::allocator<int>,bool,enum Concurrency::agent_status const &>::`scalar deleting
   destructor'(unsigned int)
    public: void * __thiscall std::_Func_impl<class <lambda_0b644b0099f9cbc573e00435de85ed83>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *>::`scalar deleting
   destructor'(unsigned int)
    public: void * __thiscall std::_Func_impl<class <lambda_4471c1faea23acf00f5de6f001106c5d>,class
   std::allocator<int>,void,class Concurrency::message<enum Concurrency::agent_status> *>::`scalar
   deleting destructor'(unsigned int)
    public: void * __thiscall std::_Func_impl<class <lambda_585d1183dd7288406f8b545e733d6ea7>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *>::`scalar deleting
   destructor'(unsigned int)
     6 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2015 Release */

undefined4 FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00554650();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,8);
  }
  return in_ECX;
}



