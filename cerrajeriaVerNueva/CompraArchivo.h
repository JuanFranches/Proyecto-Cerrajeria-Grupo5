#ifndef COMPRAARCHIVO_H
#define COMPRAARCHIVO_H

#include <string>
#include "Compra.h"

class CompraArchivo {
public:
    CompraArchivo(std::string nombreArchivo = "compras.dat");

    bool guardar(Compra reg);
    Compra leer(int pos);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
