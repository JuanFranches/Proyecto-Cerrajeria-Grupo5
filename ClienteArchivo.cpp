#include "ClienteArchivo.h"
#include <cstdio>

ClienteArchivo::ClienteArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ClienteArchivo::guardar(Cliente reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if(p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

Cliente ClienteArchivo::leer(int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    Cliente reg;
    if(p == NULL) return reg;

    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}

int ClienteArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Cliente);
    fclose(p);
    return cant;
}
