#ifndef SERVICIOARCHIVO_H
#define SERVICIOARCHIVO_H

#include <string>
#include "Servicio.h"

class ServicioArchivo {
public:
    ServicioArchivo(std::string nombreArchivo = "servicios.dat");

    bool guardar(Servicio reg);
    Servicio leer(int pos);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
