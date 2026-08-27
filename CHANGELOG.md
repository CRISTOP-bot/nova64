# Changelog

Todos los cambios relevantes de Nova64 se documentan aquí.

## [Unreleased]

### Añadido

- CP0 modular con Status, Cause, EPC, BadVAddr, Count, Compare, EntryHi, EntryLo, PageMask, Index, Random, Wired, Context, XContext y PRId.
- Excepciones MIPS iniciales y vector general.
- TLB/MMU iniciales con mapeo KSEG0/KSEG1 y traducción por TLB.
- Operaciones COP0 para TLBP, TLBR, TLBWI, TLBWR y ERET.
- Tests iniciales de syscall, EPC, Cause, EXL y ERET.

### Pendiente

- Validación completa de la milestone 2 en CI.
- Controlador MI, interrupciones y periféricos N64.
- SDL/OpenGL, RSP, RDP y audio.

## [0.1.0] - 2026-08-26

### Añadido

- RDRAM big-endian con accesos de 8/16/32/64 bits.
- Bus inicial para RDRAM, ROM y MMIO.
- Loader de ROM `.z64`, `.v64` y `.n64`.
- Intérprete MIPS inicial con ALU, branches, jumps, HI/LO y loads/stores básicos.
- CLI `nova64` y herramienta `nova64-disasm`.
- CMake, CTest y GitHub Actions.

> Esta versión es una base de desarrollo y no debe considerarse todavía un emulador compatible con juegos comerciales.
