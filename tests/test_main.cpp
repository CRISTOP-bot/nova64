#include "nova64/memory/rdram.hpp"
#include "nova64/cpu/cpu.hpp"
#include "nova64/bus/bus.hpp"
#include <cassert>
int main(){
 nova64::Rdram r(64); r.write32(0,0x12345678); assert(r.read32(0)==0x12345678);
 nova64::Bus b(64); nova64::Cpu c(b); c.reset(0);
 b.ram().write32(0,0x2001002a); c.step(); assert(c.reg(1)==42);
 b.ram().write32(4,0x24210001); c.step(); assert(c.reg(1)==43);
 b.ram().write32(8,0x0000000c); c.step(); assert((c.cp0().cause()>>2&31)==8); assert(c.cp0().epc()==8); assert((c.cp0().status()&2)!=0);
 c.cp0().eret(); assert((c.cp0().status()&2)==0);
 return 0;
}
