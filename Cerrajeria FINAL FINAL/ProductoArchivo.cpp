#include "ProductoArchivo.h"
#include <cstdio>

ProductoArchivo::ProductoArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ProductoArchivo::guardar(Producto reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if(p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}

Producto ProductoArchivo::leer(int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    Producto reg;
    if(p == NULL) return reg;
    fseek(p, pos * sizeof(Producto), SEEK_SET);
    fread(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return reg;
}

int ProductoArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Producto);
    fclose(p);
    return cant;
}
