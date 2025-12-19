#include <iostream>
using namespace std;
#include "DetalleCompraManager.h"

DetalleCompraManager::DetalleCompraManager(){}

void DetalleCompraManager::altaDetalleCompra(){
    DetalleCompra reg;
    cout << "\nALTA DE DETALLE DE COMPRA\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Detalle de compra guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void DetalleCompraManager::listarDetalleCompras(){
    cout << "\nLISTADO DE DETALLES DE COMPRAS\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    DetalleCompra reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
