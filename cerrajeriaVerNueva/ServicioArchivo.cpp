#include "ServicioArchivo.h"
#include <cstdio>

ServicioArchivo::ServicioArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ServicioArchivo::guardar(Servicio reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if(p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Servicio), 1, p);
    fclose(p);
    return ok;
}

Servicio ServicioArchivo::leer(int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    Servicio reg;
    if(p == NULL) return reg;
    fseek(p, pos * sizeof(Servicio), SEEK_SET);
    fread(&reg, sizeof(Servicio), 1, p);
    fclose(p);
    return reg;
}

int ServicioArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Servicio);
    fclose(p);
    return cant;
}
