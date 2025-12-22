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
    FILE* p = fopen("compras.dat", "rb+");
    if (p == NULL) {
        cout << "Error al abrir el archivo.\n";
        return false;
    }

    Compra reg;
    int pos = 0;

    while (fread(&reg, sizeof(Compra), 1, p) == 1) {
        if (reg.getIdCompra() == id && !reg.getEliminado()) {
            reg.setEliminado(true);

            fseek(p, pos * sizeof(Compra), SEEK_SET);
            fwrite(&reg, sizeof(Compra), 1, p);

            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}
