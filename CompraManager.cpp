#include <iostream>
using namespace std;
#include "CompraManager.h"

CompraManager::CompraManager(){}

void CompraManager::altaCompra(){
    Compra reg;
    cout << "\nALTA DE COMPRA (CABECERA)\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Compra guardada en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void CompraManager::listarCompras(){
    cout << "\nLISTADO DE COMPRAS\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    Compra reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
