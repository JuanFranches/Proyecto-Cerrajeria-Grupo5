#include "ProveedorArchivo.h"
#include <cstdio>

ProveedorArchivo::ProveedorArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ProveedorArchivo::guardar(Proveedor reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if(p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return ok;
}

Proveedor ProveedorArchivo::leer(int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    Proveedor reg;
    if(p == NULL) return reg;
    fseek(p, pos * sizeof(Proveedor), SEEK_SET);
    fread(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return reg;
}

int ProveedorArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Proveedor);
    fclose(p);
    return cant;
}
