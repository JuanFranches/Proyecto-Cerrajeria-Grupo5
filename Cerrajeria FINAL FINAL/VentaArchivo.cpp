#include <cstdio>
#include <cstring>
#include "VentaArchivo.h"

VentaArchivo::VentaArchivo(const char* nombre) {
    strcpy(_nombre, nombre);
}

bool VentaArchivo::guardar(const Venta& reg) {
    FILE* p = fopen(_nombre, "ab");
    if (p == NULL) return false;

    bool ok = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);

    return ok;
}

Venta VentaArchivo::leer(int pos) {
    Venta reg;
    FILE* p = fopen(_nombre, "rb");
    if (p == NULL) return reg;

    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&reg, sizeof(Venta), 1, p);
    fclose(p);

    return reg;
}

int VentaArchivo::getCantidadRegistros() {
    FILE* p = fopen(_nombre, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    long bytes = ftell(p);
    fclose(p);

    return (int)(bytes / sizeof(Venta));
}
