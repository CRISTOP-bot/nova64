#include "nova64/core/machine.hpp"
namespace nova64 { Machine::Machine():bus_(),cpu_(std::make_unique<Cpu>(bus_)){} void Machine::load_rom(const std::filesystem::path&p){rom_=std::make_shared<RomImage>(RomImage::load(p));bus_.attach_rom(rom_);reset();} void Machine::reset(){cpu_->reset();paused_=false;} void Machine::run(uint64_t n){if(!paused_)cpu_->run(n);} }
