# Nova64

Emulador de Nintendo 64 para Linux, escrito principalmente en C++20. El proyecto comienza por una base ejecutable y verificable: RDRAM big-endian, bus, cargador de ROM `.z64/.v64/.n64`, intérprete MIPS III inicial y herramienta de inspección.

> Nova64 no incluye ROMs, BIOS ni assets comerciales. Usa únicamente archivos que poseas legalmente.

## Compilar

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j$(nproc)
ctest --test-dir build --output-on-failure
./build/nova64 rom.z64
./build/nova64-disasm rom.z64
```

Debian/Ubuntu: `sudo apt install build-essential cmake`
Arch: `sudo pacman -S base-devel cmake`

La opción `NOVA64_ENABLE_SDL=ON` se reservará para el frontend SDL; la base actual no exige dependencias gráficas, por lo que también funciona en CI/headless.

## Estado y roadmap

Fase 0–1 implementadas: CMake, tests, RDRAM, bus inicial, loader endian-aware e intérprete MIPS con registros, HI/LO, branches, jumps, ALU y loads/stores básicos.

Siguiente: CP0/TLB y excepciones arquitectónicas; luego MMIO/PI/SI/VI/AI, scheduler, SDL/OpenGL, RSP/RDP y audio. Cada subsistema se incorporará con tests antes de conectarlo al frontend.

La implementación actual evita falsos dispositivos: los periféricos aún no anunciados no se presentan como emulados.
