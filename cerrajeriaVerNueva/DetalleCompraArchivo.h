#ifndef DETALLECOMPRAARCHIVO_H
#define DETALLECOMPRAARCHIVO_H

#include <string>
#include "DetalleCompra.h"

class DetalleCompraArchivo {
public:
    DetalleCompraArchivo(std::string nombreArchivo = "detalles_compra.dat");

    bool guardar(DetalleCompra reg);
    DetalleCompra leer(int pos);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
