#include <iostream>
using namespace std;
#include "DetallePedidoManager.h"

DetallePedidoManager::DetallePedidoManager(){}

void DetallePedidoManager::altaDetallePedido(){
    DetallePedido reg;
    cout << "\nALTA DE DETALLE DE PEDIDO\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Detalle de pedido guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void DetallePedidoManager::listarDetallePedidos(){
    cout << "\nLISTADO DE DETALLES DE PEDIDOS\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    DetallePedido reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
