#include <iostream>
using namespace std;
#include "ServicioManager.h"

ServicioManager::ServicioManager(){}

void ServicioManager::altaServicio(){
    Servicio reg;
    cout << "\nALTA DE SERVICIO\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Servicio guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void ServicioManager::listarServicios(){
    cout << "\nLISTADO DE SERVICIOS\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    Servicio reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
