#include <iostream>
using namespace std;
#include "ProductoManager.h"

ProductoManager::ProductoManager(){}

void ProductoManager::altaProducto(){
    Producto reg;
    cout << "\nALTA DE PRODUCTO\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Producto guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void ProductoManager::listarProductos(){
    cout << "\nLISTADO DE PRODUCTOS\n";
    int cant = _repo.getCantidadRegistros();
    if(cant == 0){
        cout << "No hay archivo o esta vacio.\n";
        return;
    }
    Producto reg;
    for(int i=0; i<cant; i++){
        reg = _repo.leer(i);
        cout << "\n[Registro " << (i+1) << "]\n";
        reg.Mostrar();
    }
}
