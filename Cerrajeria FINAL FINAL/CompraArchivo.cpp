#include <cstdio>
#include <cstring>
#include "CompraArchivo.h"

CompraArchivo::CompraArchivo(const char* nombre) {
    strcpy(_nombre, nombre);
}

bool CompraArchivo::guardar(const Compra& reg) {
    FILE* p = fopen(_nombre, "ab");
    if (p == NULL) return false;

    bool ok = fwrite(&reg, sizeof(Compra), 1, p);
    fclose(p);
    return ok;
}

Compra CompraArchivo::leer(int pos) {
    Compra reg;
    FILE* p = fopen(_nombre, "rb");
    if (p == NULL) return reg;

    fseek(p, pos * sizeof(Compra), SEEK_SET);
    fread(&reg, sizeof(Compra), 1, p);
    fclose(p);

    return reg;
}

int CompraArchivo::getCantidadRegistros() {
    FILE* p = fopen(_nombre, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    long bytes = ftell(p);
    fclose(p);

    return (int)(bytes / sizeof(Compra));
}

