#ifndef EMPLEADOARCHIVO_H
#define EMPLEADOARCHIVO_H

#include <string>
#include "Empleado.h"

class EmpleadoArchivo {
public:
    EmpleadoArchivo(std::string nombreArchivo = "empleados.dat");

    bool guardar(Empleado reg);
    Empleado leer(int pos);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
