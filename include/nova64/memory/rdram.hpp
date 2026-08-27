#pragma once
#include <cstdint>
#include <vector>
namespace nova64 { class Rdram { std::vector<uint8_t> bytes_; public: explicit Rdram(uint32_t size=8*1024*1024); uint8_t read8(uint32_t); void write8(uint32_t,uint8_t); uint16_t read16(uint32_t); uint32_t read32(uint32_t); uint64_t read64(uint32_t); void write16(uint32_t,uint16_t); void write32(uint32_t,uint32_t); void write64(uint32_t,uint64_t); uint32_t size() const; const std::vector<uint8_t>& bytes() const{return bytes_;} }; }
