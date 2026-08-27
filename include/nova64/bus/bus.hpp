#pragma once
#include <cstdint>
#include <memory>
#include "nova64/common/types.hpp"
namespace nova64 { class Rdram; class RomImage; class Mmio;
class Bus { std::unique_ptr<Rdram> ram_; std::shared_ptr<const RomImage> rom_; std::unique_ptr<Mmio> mmio_; public: explicit Bus(uint32_t ram_size=8*1024*1024); ~Bus(); void attach_rom(std::shared_ptr<const RomImage>); uint64_t read(uint64_t,AccessSize); void write(uint64_t,uint64_t,AccessSize); Rdram& ram(); };
}
