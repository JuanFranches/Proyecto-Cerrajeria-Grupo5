#ifndef PRODUCTOARCHIVO_H
#define PRODUCTOARCHIVO_H

#include <string>
#include "Producto.h"

class ProductoArchivo {
public:
    ProductoArchivo(std::string nombreArchivo = "productos.dat");

    bool guardar(Producto reg);
    Producto leer(int pos);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
