/* std::D$00::?$moneypunct -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::D$00::?$moneypunct[2], std::D$0A::?$moneypunct[2], std::D::?$_Mpunct[2], std::D::?$collate[2], std::D::?$ctype[2], std::D::?$messages[2], std::D::?$numpunct[2], std::DDU_Mbstatet::?$codecvt[2], std::G$00::?$moneypunct[2], std::G$0A::?$moneypunct[2], std::G::?$_Mpunct[2], std::G::?$collate[2], std::G::?$ctype[2], std::G::?$messages[2], std::G::?$numpunct[2], std::GDU_Mbstatet::?$codecvt[2], std::_W$00::?$moneypunct[2], std::_W$0A::?$moneypunct[2], std::_W::?$_Mpunct[2], std::_W::?$collate[2], std::_W::?$ctype[2], std::_W::?$messages[2], std::_W::?$numpunct[2], std::_WDU_Mbstatet::?$codecvt[2], std::ctype_base[2], std::locale::_Locimp[2], std::locale::facet[2], std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$money_get[2], std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$num_get[2], std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[2], std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$money_put[2], std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[2], std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$time_put[2], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$money_get[2], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$num_get[2], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$time_get[2], std::std::std::G::GU?$char_traits::GV?$ostreambuf_iterator::?$money_put[2], std::std::std::G::GU?$char_traits::GV?$ostreambuf_iterator::?$num_put[2], std::std::std::G::GU?$char_traits::GV?$ostreambuf_iterator::?$time_put[2], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$money_get[2], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[2], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[2], std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$money_put[2], std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[2], std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$time_put[2] */
/* 00557f70  _Decref  34 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class std::_Facet_base * __thiscall std::locale::facet::_Decref(void)
   
   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

_Facet_base * __thiscall std::locale::facet::_Decref(facet *this)

{
  int iVar1;
  facet *pfVar2;
  
  pfVar2 = this + 4;
  LOCK();
  iVar1 = *(int *)pfVar2;
  *(int *)pfVar2 = *(int *)pfVar2 + -1;
  UNLOCK();
  if (iVar1 != 1) {
    this = (facet *)0x0;
  }
  return (_Facet_base *)this;
}




/* vtable slots: std::D$00::?$moneypunct[1], std::D$0A::?$moneypunct[1], std::D::?$_Mpunct[1], std::D::?$collate[1], std::D::?$ctype[1], std::D::?$messages[1], std::D::?$numpunct[1], std::DDU_Mbstatet::?$codecvt[1], std::G$00::?$moneypunct[1], std::G$0A::?$moneypunct[1], std::G::?$_Mpunct[1], std::G::?$collate[1], std::G::?$ctype[1], std::G::?$messages[1], std::G::?$numpunct[1], std::GDU_Mbstatet::?$codecvt[1], std::_W$00::?$moneypunct[1], std::_W$0A::?$moneypunct[1], std::_W::?$_Mpunct[1], std::_W::?$collate[1], std::_W::?$ctype[1], std::_W::?$messages[1], std::_W::?$numpunct[1], std::_WDU_Mbstatet::?$codecvt[1], std::ctype_base[1], std::locale::_Locimp[1], std::locale::facet[1], std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$money_get[1], std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$num_get[1], std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$time_get[1], std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$money_put[1], std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[1], std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$time_put[1], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$money_get[1], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$num_get[1], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$time_get[1], std::std::std::G::GU?$char_traits::GV?$ostreambuf_iterator::?$money_put[1], std::std::std::G::GU?$char_traits::GV?$ostreambuf_iterator::?$num_put[1], std::std::std::G::GU?$char_traits::GV?$ostreambuf_iterator::?$time_put[1], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$money_get[1], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[1], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$time_get[1], std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$money_put[1], std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[1], std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$time_put[1] */
/* 00558e30  FUN_00558e30  20 bytes, 0 callers */

void FUN_00558e30(void)

{
  int in_ECX;
  
  LOCK();
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  UNLOCK();
  return;
}




/* vtable slots: std::D$00::?$moneypunct[9], std::D$0A::?$moneypunct[9], std::D::?$_Mpunct[9], std::G$00::?$moneypunct[9], std::G$0A::?$moneypunct[9], std::G::?$_Mpunct[9], std::_W$00::?$moneypunct[9], std::_W$0A::?$moneypunct[9], std::_W::?$_Mpunct[9] */
/* 008aee34  FUN_008aee34  4 bytes, 15 callers */

undefined4 FUN_008aee34(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1c);
}




/* vtable slots: std::D$00::?$moneypunct[3], std::D$0A::?$moneypunct[3], std::D::?$_Mpunct[3], std::D::?$numpunct[3] */
/* 008dd723  FUN_008dd723  4 bytes, 0 callers */

undefined1 FUN_008dd723(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xc);
}




/* vtable slots: std::D$00::?$moneypunct[6], std::D$0A::?$moneypunct[6], std::D::?$_Mpunct[6], std::D::?$numpunct[6] */
/* 008dd727  FUN_008dd727  21 bytes, 0 callers */

undefined4 FUN_008dd727(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00552ff0(*(undefined4 *)(in_ECX + 0x10));
  return param_1;
}




/* vtable slots: std::D$00::?$moneypunct[5], std::D$0A::?$moneypunct[5], std::D::?$_Mpunct[5], std::D::?$numpunct[5], std::G$00::?$moneypunct[5], std::G$0A::?$moneypunct[5], std::G::?$_Mpunct[5], std::G::?$numpunct[5], std::_W$00::?$moneypunct[5], std::_W$0A::?$moneypunct[5], std::_W::?$_Mpunct[5] */
/* 008de0aa  FUN_008de0aa  21 bytes, 0 callers */

undefined4 FUN_008de0aa(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00552ff0(*(undefined4 *)(in_ECX + 8));
  return param_1;
}




/* vtable slots: std::D$00::?$moneypunct[4], std::D$0A::?$moneypunct[4], std::D::?$_Mpunct[4], std::D::?$numpunct[4] */
/* 008de789  FUN_008de789  4 bytes, 0 callers */

undefined1 FUN_008de789(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xd);
}




/* vtable slots: std::D$00::?$moneypunct[7], std::D$0A::?$moneypunct[7], std::D::?$_Mpunct[7], std::D::?$numpunct[7] */
/* 008de813  FUN_008de813  21 bytes, 0 callers */

undefined4 FUN_008de813(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00552ff0(*(undefined4 *)(in_ECX + 0x14));
  return param_1;
}




/* vtable slots: std::D$00::?$moneypunct[11], std::D$0A::?$moneypunct[11], std::D::?$_Mpunct[11], std::G$00::?$moneypunct[11], std::G$0A::?$moneypunct[11], std::G::?$_Mpunct[11], std::_W$00::?$moneypunct[11], std::_W$0A::?$moneypunct[11], std::_W::?$_Mpunct[11] */
/* 008eb207  FUN_008eb207  15 bytes, 0 callers */

void FUN_008eb207(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x24);
  return;
}




/* vtable slots: std::D$00::?$moneypunct[10], std::D$0A::?$moneypunct[10], std::D::?$_Mpunct[10], std::G$00::?$moneypunct[10], std::G$0A::?$moneypunct[10], std::G::?$_Mpunct[10], std::_W$00::?$moneypunct[10], std::_W$0A::?$moneypunct[10], std::_W::?$_Mpunct[10] */
/* 008eb326  FUN_008eb326  15 bytes, 0 callers */

void FUN_008eb326(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x20);
  return;
}




/* vtable slots: std::D$00::?$moneypunct[0], std::D$0A::?$moneypunct[0], std::D::?$_Mpunct[0] */
/* 008ece8e  FUN_008ece8e  46 bytes, 0 callers */

void FUN_008ece8e(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::_Mpunct<char>::vftable;
  Tidy();
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::D$00::?$moneypunct[8], std::D$0A::?$moneypunct[8], std::D::?$_Mpunct[8] */
/* 008ef880  FUN_008ef880  21 bytes, 0 callers */

undefined4 FUN_008ef880(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00552ff0(*(undefined4 *)(in_ECX + 0x18));
  return param_1;
}



