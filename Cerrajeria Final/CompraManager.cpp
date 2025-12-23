#include <iostream>
using namespace std;

#include "CompraManager.h"

CompraManager::CompraManager()
    : _archivo("compras.dat")
{
}

void CompraManager::altaCompra() {
    Compra reg;
    reg.Cargar();

    if (_archivo.guardar(reg)) {
        cout << "Compra grabada correctamente.\n";
    } else {
        cout << "ERROR al grabar la compra.\n";
    }
}

void CompraManager::listarCompras() {
    int cant = _archivo.getCantidadRegistros();

    if (cant == 0) {
        cout << "No hay compras registradas.\n";
        return;
    }

    for (int i = 0; i < cant; i++) {
        Compra reg = _archivo.leer(i);

        if (!reg.getEliminado()) {
            cout << "\n=== COMPRA #" << reg.getIdCompra() << " ===\n";
            reg.Mostrar();
        }
    }
}

bool CompraManager::bajaCompra(int id) {
    int cant = _archivo.getCantidadRegistros();

    bool encontrada = false;


    CompraArchivo temp("temp_compras.dat");

    for (int i = 0; i < cant; i++) {
        Compra reg = _archivo.leer(i);


        if (reg.getIdCompra() == id) {
            reg.setEliminado(true);
            encontrada = true;
        }

        temp.guardar(reg);
    }

    if (!encontrada) return false;


    remove("compras.dat");
    rename("temp_compras.dat", "compras.dat");

    return true;
}

