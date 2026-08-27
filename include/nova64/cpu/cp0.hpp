#pragma once
#include <cstdint>
namespace nova64 {
enum class ExceptionCode:uint8_t { Interrupt=0, TlbMod=1, TlbLoad=2, TlbStore=3, AddressLoad=4, AddressStore=5, BusInstruction=6, BusData=7, Syscall=8, Break=9, Reserved=10, Overflow=12 };
class Cp0 { uint32_t index_=0,entrylo0_=0,entrylo1_=0,page_mask_=0,wired_=0,context_=0,xcontext_=0,badvaddr_=0,count_=0,compare_=0,entryhi_=0,status_=0,cause_=0,epc_=0,prid_=0x00000B22; public:
 uint64_t read(unsigned r) const; void write(unsigned r,uint64_t v); void tick(uint32_t n=1); void raise(ExceptionCode,uint64_t bad,uint64_t pc,bool delay); void eret(); bool interrupt_pending()const; uint32_t status()const{return status_;} uint32_t cause()const{return cause_;} uint64_t epc()const{return epc_;} uint64_t badvaddr()const{return badvaddr_;} uint32_t entryhi()const{return entryhi_;} uint32_t entrylo0()const{return entrylo0_;} uint32_t entrylo1()const{return entrylo1_;} uint32_t page_mask()const{return page_mask_;} uint32_t index()const{return index_;} uint32_t random()const{return wired_>=31?31:31;}
 void set_index(uint32_t v){index_=v&31;} void set_entrylo0(uint32_t v){entrylo0_=v;} void set_entrylo1(uint32_t v){entrylo1_=v;} void set_entryhi(uint32_t v){entryhi_=v;} void set_page_mask(uint32_t v){page_mask_=v&0x01FFE000;} void set_wired(uint32_t v){wired_=v&31;}
}; }
