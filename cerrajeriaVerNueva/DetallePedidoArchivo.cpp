#include "DetallePedidoArchivo.h"
#include <cstdio>

DetallePedidoArchivo::DetallePedidoArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool DetallePedidoArchivo::guardar(DetallePedido reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if(p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(DetallePedido), 1, p);
    fclose(p);
    return ok;
}

DetallePedido DetallePedidoArchivo::leer(int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    DetallePedido reg;
    if(p == NULL) return reg;
    fseek(p, pos * sizeof(DetallePedido), SEEK_SET);
    fread(&reg, sizeof(DetallePedido), 1, p);
    fclose(p);
    return reg;
}

int DetallePedidoArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(DetallePedido);
    fclose(p);
    return cant;
}
