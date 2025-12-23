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
    FILE* p = fopen("compras.dat", "rb");
    if (p == NULL) {
        cout << "No hay Compras cargadas.\n";
        return;
    }

    Compra reg;
    bool hayActivos = false;

    while (fread(&reg, sizeof(Compra), 1, p) == 1) {
        if (!reg.getEliminado()) {
            reg.Mostrar();
            hayActivos = true;
        }
    }

    fclose(p);

    if (!hayActivos) {
        cout << "No hay Compras cargadas.\n";
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

