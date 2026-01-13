#ifndef EMPLEADOMANAGER_H
#define EMPLEADOMANAGER_H

#include "EmpleadoArchivo.h"

class EmpleadoManager {
public:
    EmpleadoManager();
    void altaEmpleado();
    void listarEmpleados();
    bool bajaEmpleado(int id);

private:
    EmpleadoArchivo _repo;
};

#endif
