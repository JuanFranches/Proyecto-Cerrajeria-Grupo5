#include <iostream>
using namespace std;
#include "PedidoClienteManager.h"

PedidoClienteManager::PedidoClienteManager(){}

void PedidoClienteManager::altaPedido(){
    PedidoCliente reg;
    cout << "\nALTA DE PEDIDO (CABECERA)\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Pedido guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void PedidoClienteManager::listarPedidos(){
    cout << "\nLISTADO DE PEDIDOS\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    PedidoCliente reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
