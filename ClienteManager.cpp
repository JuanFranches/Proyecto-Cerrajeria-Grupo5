#include <iostream>
using namespace std;
#include "ClienteManager.h"

ClienteManager::ClienteManager(){}

void ClienteManager::altaCliente(){
    Cliente reg;
    cout << "\nALTA DE CLIENTE\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Cliente guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void ClienteManager::listarClientes(){
    cout << "\nLISTADO DE CLIENTES\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    Cliente reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
