#ifndef EMPLEADOMANAGER_H
#define EMPLEADOMANAGER_H

#include "EmpleadoArchivo.h"

class EmpleadoManager {
public:
    EmpleadoManager();
    void altaEmpleado();
    void listarEmpleados();

private:
    EmpleadoArchivo _repo;
};

#endif
