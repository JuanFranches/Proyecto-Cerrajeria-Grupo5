#ifndef VENTAARCHIVO_H
#define VENTAARCHIVO_H

#include "Venta.h"

class VentaArchivo {
private:
    char _nombre[30];

public:
    VentaArchivo(const char* nombre = "ventas.dat");

    bool  guardar(const Venta& reg);
    Venta leer(int pos);
    int   getCantidadRegistros();
};

#endif
