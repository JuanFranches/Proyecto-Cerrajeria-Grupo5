#include <iostream>
using namespace std;
#include "ProveedorManager.h"

ProveedorManager::ProveedorManager(){}

void ProveedorManager::altaProveedor(){
    Proveedor reg;
    cout << "\nALTA DE PROVEEDOR\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Proveedor guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void ProveedorManager::listarProveedores(){
    cout << "\nLISTADO DE PROVEEDORES\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    Proveedor reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
