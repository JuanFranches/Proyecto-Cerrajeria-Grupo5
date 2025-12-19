#include "DetalleCompraArchivo.h"
#include <cstdio>

DetalleCompraArchivo::DetalleCompraArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool DetalleCompraArchivo::guardar(DetalleCompra reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if(p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(DetalleCompra), 1, p);
    fclose(p);
    return ok;
}

DetalleCompra DetalleCompraArchivo::leer(int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    DetalleCompra reg;
    if(p == NULL) return reg;
    fseek(p, pos * sizeof(DetalleCompra), SEEK_SET);
    fread(&reg, sizeof(DetalleCompra), 1, p);
    fclose(p);
    return reg;
}

int DetalleCompraArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(DetalleCompra);
    fclose(p);
    return cant;
}
