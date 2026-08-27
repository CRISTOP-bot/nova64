# Contribuir

Mantén la emulación independiente de SDL/OpenGL. Todo comportamiento nuevo del hardware debe tener un test determinista. Usa C++20, tipos de ancho fijo y accesos endian explícitos. No se aceptan ROMs comerciales, BIOS propietarias ni capturas de juegos.

```bash
cmake -S . -B build -DNOVA64_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```
