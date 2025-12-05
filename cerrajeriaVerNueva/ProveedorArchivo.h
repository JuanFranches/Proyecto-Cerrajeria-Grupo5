#ifndef PROVEEDORARCHIVO_H
#define PROVEEDORARCHIVO_H

#include <string>
#include "Proveedor.h"

class ProveedorArchivo {
public:
    ProveedorArchivo(std::string nombreArchivo = "proveedores.dat");

    bool guardar(Proveedor reg);
    Proveedor leer(int pos);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
