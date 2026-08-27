#pragma once
#include <cstdint>
#include <unordered_map>
namespace nova64 { class Mmio { std::unordered_map<uint32_t,uint32_t> regs_; public: uint32_t read32(uint32_t); void write32(uint32_t,uint32_t); }; }
