#include <iostream>
using namespace std;
#include "EmpleadoManager.h"

EmpleadoManager::EmpleadoManager(){}

void EmpleadoManager::altaEmpleado(){
    Empleado reg;
    cout << "\nALTA DE EMPLEADO\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Empleado guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void EmpleadoManager::listarEmpleados(){
    cout << "\nLISTADO DE EMPLEADOS\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    Empleado reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
