# CPU y CP0

El intérprete implementa ALU, branches/jumps, loads/stores, HI/LO, syscall, break, reserved instruction, overflow, COP0 básico y ERET. Los accesos desalineados generan Address Error en vez de ser corregidos silenciosamente.

`Cp0::raise` escribe código en Cause.ExcCode, conserva BD cuando el fallo está en el delay slot, guarda EPC y activa EXL. El vector usado por esta etapa es `0xFFFFFFFF80000180`. Count avanza por instrucción y Compare limpia la señal de timer cuando se escribe.
