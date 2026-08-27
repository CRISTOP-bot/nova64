#pragma once
#include <array>
#include <cstdint>
#include "nova64/common/types.hpp"
#include "nova64/cpu/cp0.hpp"
#include "nova64/mmu/mmu.hpp"
namespace nova64 { class Bus;
struct CpuState { std::array<uint64_t,32> gpr{}; uint64_t hi=0,lo=0,pc=0xFFFFFFFFA4000040ull,next_pc=0xFFFFFFFFA4000044ull; bool halted=false; };
class Cpu { CpuState s_{}; Bus* bus_{}; Mmu mmu_{}; Cp0 cp0_{}; bool delay_slot_=false; uint64_t current_pc_=0; uint64_t physical(uint64_t,AccessType); void exception(ExceptionCode,uint64_t,bool); public: explicit Cpu(Bus& b):bus_(&b){} void reset(uint64_t pc=0xFFFFFFFFA4000040ull); void step(); void run(uint64_t max_steps); uint64_t reg(unsigned i)const{return i?s_.gpr.at(i):0;} void set_reg(unsigned i,uint64_t v){if(i)s_.gpr.at(i)=v;} const CpuState& state()const{return s_;} CpuState& state(){return s_;} Cp0& cp0(){return cp0_;} const Cp0& cp0()const{return cp0_;} Tlb& tlb(){return mmu_.tlb();} };
}
