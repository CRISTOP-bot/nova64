#include "nova64/core/machine.hpp"
#include "nova64/memory/rdram.hpp"
#include <iostream>
int main(int argc,char**argv){if(argc<2){std::cerr<<"Uso: nova64 [--debug] ROM\n";return 2;}try{int i=1;bool debug=false;if(std::string(argv[i])=="--debug"){debug=true;++i;}if(i>=argc)return 2;nova64::Machine m;m.load_rom(argv[i]);auto&h=m.cpu();std::cout<<"Nova64: ROM cargada ("<<m.bus().ram().size()<<" bytes RDRAM), PC=0x"<<std::hex<<h.state().pc<<std::dec<<"\n";if(debug)std::cout<<"debug: interprete MIPS activo\n";m.run(1000000);return 0;}catch(const std::exception&e){std::cerr<<"Nova64: "<<e.what()<<"\n";return 1;}}
