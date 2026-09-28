/* ATL::IDocument -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: ATL::IDocument[0] */
/* 004d1990  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    protected: virtual void * __thiscall Concurrency::details::_Chore::`scalar deleting
   destructor'(unsigned int)
    public: virtual void * __thiscall std::error_category::`scalar deleting destructor'(unsigned
   int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4 FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004d18a0();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,8);
  }
  return in_ECX;
}




/* vtable slots: ATL::IDocument[1], CDocument::CDocumentAdapter[1] */
/* 004d19c0  Reference  29 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual unsigned int __thiscall Concurrency::details::ResourceManager::Reference(void)
   
   Library: Visual Studio */

uint __thiscall Concurrency::details::ResourceManager::Reference(ResourceManager *this)

{
  int iVar1;
  ResourceManager *pRVar2;
  
  pRVar2 = this + 4;
  LOCK();
  iVar1 = *(int *)pRVar2;
  *(int *)pRVar2 = *(int *)pRVar2 + 1;
  UNLOCK();
  return iVar1 + 1;
}




/* vtable slots: ATL::IDocument[2], CDocument::CDocumentAdapter[2] */
/* 004d26d0  FUN_004d26d0  77 bytes, 0 callers */

undefined4 FUN_004d26d0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  piVar2 = in_ECX + 1;
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    if (in_ECX != (undefined4 *)0x0) {
      (**(code **)*in_ECX)(1);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = in_ECX[1];
  }
  return uVar3;
}




/* vtable slots: ATL::IDocument[3], ATL::IDocument[4], ATL::IDocument[5], ATL::IDocument[6], ATL::IDocument[7], ATL::IDocument[8], ATL::IDocument[9], ATL::IDocument[10], ATL::IDocument[11], ATL::IDocument[12], CBaseTabbedPane[203], CGamenJoken[1], CGamenJoken[2], CGamenJoken[3], CGamenJoken[4], CGamenJoken[5], CMFCBaseTabCtrl[89], CMFCBaseTabCtrl[90], CMFCBaseTabCtrl[97], CMFCBaseTabCtrl[129], CMFCBaseTabCtrl[130], CMFCBaseTabCtrl[133], CMFCBaseTabCtrl[147], CMFCRibbonBaseElement[62], CMFCRibbonBaseElement[95], CScrollView[103], CSimpleException[1], CSyncObject[5], CVSListBoxBase[91], CVSListBoxBase[92], CVSListBoxBase[93], CVSListBoxBase[94], CVSListBoxBase[95], CVSListBoxBase[96], CVSListBoxBase[97], CVSListBoxBase[98], CVSListBoxBase[99], CVSListBoxBase[100], CVSListBoxBase[113], CVSListBoxBase[114], CVSListBoxBase[115], CZukei[3], CZukei[8], CZukeiObject[3], CZukeiObject[8], std::_Facet_base[1], std::_Facet_base[2] */
/* 008f1a71  FUN_008f1a71  27 bytes, 0 callers */

void FUN_008f1a71(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)FUN_008f1a6b();
  if (pcVar1 != (code *)0x0) {
    guard_check_icall();
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0090ec39();
}



