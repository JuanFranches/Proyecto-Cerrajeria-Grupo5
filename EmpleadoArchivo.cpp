#include "EmpleadoArchivo.h"
#include <cstdio>

EmpleadoArchivo::EmpleadoArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool EmpleadoArchivo::guardar(Empleado reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if(p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;
}

Empleado EmpleadoArchivo::leer(int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    Empleado reg;
    if(p == NULL) return reg;
    fseek(p, pos * sizeof(Empleado), SEEK_SET);
    fread(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return reg;
}

int EmpleadoArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Empleado);
    fclose(p);
    return cant;
}
