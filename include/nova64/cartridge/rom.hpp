#pragma once
#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>
namespace nova64 {
struct RomHeader { std::string name; uint16_t country{}; uint32_t crc1{},crc2{}; char id[3]{}; };
class RomImage { std::vector<uint8_t> data_; RomHeader header_{}; public:
 static RomImage load(const std::filesystem::path& path);
 const std::vector<uint8_t>& data() const { return data_; } const RomHeader& header() const { return header_; }
 uint8_t read8(uint32_t off) const; uint32_t size() const { return static_cast<uint32_t>(data_.size()); }
};
}
