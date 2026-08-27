# Arquitectura

`Cpu` ejecuta instrucciones y mantiene `PC`, `HI/LO` y GPR. Antes de cada acceso, `Mmu` clasifica la dirección: KSEG0/KSEG1 usan mapeo directo; KUSEG y KSEG2/3 consultan `Tlb`. El resultado físico se entrega a `Bus`, que continúa aislando RDRAM, ROM y MMIO.

`Cp0` contiene el estado privilegiado. Un fallo de traducción, permiso o alineación llama a `raise`, actualiza `BadVAddr`, `Cause`, `EPC` y `Status.EXL`, y salta al vector general `0x80000180`. La marca `BD` conserva la semántica de delay slot. `ERET` restaura el nivel previo.

La TLB tiene 32 entradas, dos páginas por entrada y campos EntryHi/EntryLo/PageMask. Las operaciones TLB se ejecutan desde COP0; el backend no depende de SDL, OpenGL ni del endianness del host.
