# Roadmap técnico

1. **Base CPU (actual):** estado de CPU, decoder implícito validado por instrucciones, intérprete y RDRAM.
2. **CP0/MMU:** excepción precisa, delay slot, TLB de 32 entradas, traducción kseg y registros CP0.
3. **Bus/dispositivos:** mapa MMIO tipado, MI, PI y DMA ROM↔RDRAM; SI/PIF y VI/AI con scheduler por ciclos.
4. **Arranque:** pruebas MIPS sintéticas y trazas deterministas; no se asume BIOS propietaria.
5. **RSP/RDP:** intérpretes independientes con tests de memoria vectorial y comandos sintéticos.
6. **Frontends:** SDL2 para ventana/input/audio y renderer OpenGL detrás de una interfaz de vídeo.
7. **Persistencia/debug:** saves, snapshots versionados, disassembler y debugger.
8. **Rendimiento:** perfiles, block interpreter y posteriormente JIT opcional.

Cada paso debe añadir tests y conservar un modo headless reproducible.
