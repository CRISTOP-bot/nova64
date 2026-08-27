#include "nova64/cartridge/rom.hpp"
#include <iostream>
int main(int c,char**v){if(c!=2){std::cerr<<"uso: nova64-disasm ROM\n";return 2;}try{auto r=nova64::RomImage::load(v[1]);for(uint32_t a=0;a+4<=r.size()&&a<0x200;a+=4){uint32_t x=uint32_t(r.read8(a))<<24|uint32_t(r.read8(a+1))<<16|uint32_t(r.read8(a+2))<<8|r.read8(a+3);std::cout<<std::hex<<a<<": "<<x<<"\n";}return 0;}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}}
