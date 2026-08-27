# Memoria, TLB y MMU

Flujo de un acceso de CPU:

```text
CPU virtual -> MMU -> TLB o KSEG directo -> Bus físico -> RDRAM/ROM/MMIO
```

KSEG0 (`0x80000000`) y KSEG1 (`0xA0000000`) se traducen a `VA & 0x1fffffff`. Los demás segmentos pasan por TLB. Cada entrada contiene PageMask, EntryHi y EntryLo0/1 con PFN, Global, Valid y Dirty. Un miss produce TLB refill; una entrada inválida produce TLB invalid y una escritura sin Dirty produce TLB modified.
