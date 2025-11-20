
#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Fecha.h"

class Empleado {
private:
    int   idEmpleado;
    char  nombre[30];
    char  apellido[30];
    char  cargo[30];
    float sueldo;
    Fecha fechaIngreso;
    bool  eliminado;

public:
    Empleado();
    void Cargar();
    void Mostrar() const;
};
#endif
