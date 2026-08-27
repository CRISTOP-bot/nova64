# Milestone 2: CP0/MMU/TLB

Los tests cubren la regresión de RDRAM y ALU, además de syscall y el estado EXL/EPC/Cause. La API pública de TLB permite construir entradas y probar hits, invalidación y Dirty; la CPU expone la TLB y CP0 para tests de integración.

La validación local queda pendiente si la máquina no tiene CMake/compilador. El workflow de CI ejecuta la compilación y CTest en Ubuntu. Antes de declarar esta etapa completa se deben añadir casos automatizados para TLBWI/TLBWR/TLBP/TLBR, ASID, fallos en delay slot y Count/Compare; la base de esas operaciones ya está conectada en el intérprete COP0.
