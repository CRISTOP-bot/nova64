# Publicar una release

Nova64 usa tags semánticos y publica únicamente después de que CI compile y pase CTest.

```bash
git add .
git commit -m "Prepare Nova64 v0.1.0"
git tag -a v0.1.0 -m "Nova64 v0.1.0"
git push origin main --follow-tags
```

El workflow `release.yml` genera un paquete Linux x86_64 y crea el GitHub Release asociado al tag. No se incluyen ROMs, BIOS ni assets protegidos.

La milestone 2 debe permanecer como `Unreleased` hasta que sus pruebas específicas de CP0/TLB/MMU pasen en CI.
