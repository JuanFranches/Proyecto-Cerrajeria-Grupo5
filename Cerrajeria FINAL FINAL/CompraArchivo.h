#ifndef COMPRAARCHIVO_H
#define COMPRAARCHIVO_H

#include "Compra.h"

class CompraArchivo {
private:
    char _nombre[30];

public:
    CompraArchivo(const char* nombre = "compras.dat");

    bool   guardar(const Compra& reg);
    Compra leer(int pos);
    int    getCantidadRegistros();
};

#endif
