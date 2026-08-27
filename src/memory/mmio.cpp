#include "nova64/memory/mmio.hpp"
namespace nova64 { uint32_t Mmio::read32(uint32_t a){auto i=regs_.find(a);return i==regs_.end()?0:i->second;} void Mmio::write32(uint32_t a,uint32_t v){regs_[a]=v;} }
