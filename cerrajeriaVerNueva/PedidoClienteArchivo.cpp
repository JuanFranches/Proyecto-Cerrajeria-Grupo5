#include "PedidoClienteArchivo.h"
#include <cstdio>

PedidoClienteArchivo::PedidoClienteArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool PedidoClienteArchivo::guardar(PedidoCliente reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if(p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(PedidoCliente), 1, p);
    fclose(p);
    return ok;
}

PedidoCliente PedidoClienteArchivo::leer(int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    PedidoCliente reg;
    if(p == NULL) return reg;
    fseek(p, pos * sizeof(PedidoCliente), SEEK_SET);
    fread(&reg, sizeof(PedidoCliente), 1, p);
    fclose(p);
    return reg;
}

int PedidoClienteArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(PedidoCliente);
    fclose(p);
    return cant;
}
