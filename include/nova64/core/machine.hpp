#pragma once
#include <memory>
#include "nova64/bus/bus.hpp"
#include "nova64/cpu/cpu.hpp"
#include "nova64/cartridge/rom.hpp"
namespace nova64 { class Machine { Bus bus_; std::unique_ptr<Cpu> cpu_; std::shared_ptr<RomImage> rom_; bool paused_=true; public: Machine(); void load_rom(const std::filesystem::path&); void reset(); void run(uint64_t steps); void pause(){paused_=true;} void resume(){paused_=false;} bool paused()const{return paused_;} Cpu& cpu(){return *cpu_;} Bus& bus(){return bus_;} }; }
