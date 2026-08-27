#pragma once
#include <array>
#include <cstdint>
#include "nova64/cpu/cp0.hpp"
#include "nova64/common/types.hpp"
namespace nova64 { struct TlbEntry {uint32_t page_mask=0,entry_hi=0,lo0=0,lo1=0;}; struct Translation {uint32_t physical; bool dirty;}; class Tlb {std::array<TlbEntry,32> e_{}; public: Translation translate(uint32_t va,bool write,uint32_t entryhi) const; int probe(uint32_t entryhi) const; TlbEntry read(unsigned i)const{return e_.at(i);} void write(unsigned i,TlbEntry e){e_.at(i&31)=e;} unsigned random(uint32_t wired)const; }; }
