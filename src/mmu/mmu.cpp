#include "nova64/mmu/mmu.hpp"
#include <stdexcept>
namespace nova64 { uint32_t Mmu::translate(uint64_t va,AccessType type,uint32_t hi)const{uint32_t a=uint32_t(va);uint32_t top=a>>29;if(top==4||top==5)return a&0x1fffffff;bool wr=type==AccessType::Write;return tlb_.translate(a,wr,hi).physical;} }
