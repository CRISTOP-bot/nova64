#pragma once
#include "nova64/mmu/tlb.hpp"
namespace nova64 { class Mmu { Tlb tlb_; public: Tlb& tlb(){return tlb_;} uint32_t translate(uint64_t va,AccessType type,uint32_t entryhi) const; }; }
