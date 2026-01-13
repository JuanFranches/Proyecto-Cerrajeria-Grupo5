#include <iostream>
using namespace std;

#include "CompraManager.h"
#include "rlutil.h"

CompraManager::CompraManager() {}

void CompraManager::altaCompra() {
    Compra reg;
    cout << "\nALTA DE COMPRA\n";
    cout << "---------------------------\n";
    reg.Cargar();

    CompraArchivo repo("compras.dat");

    if (repo.guardar(reg)) {
        rlutil::setColor(rlutil::GREEN);
        cout << endl;
        cout << "COMPRA GUARDADA EN ARCHIVO!!!\n";
        rlutil::setColor(rlutil::WHITE);
    } else {
        rlutil::setColor(rlutil::RED);
        cout << "Error de apertura.\n";
        rlutil::setColor(rlutil::WHITE);
    }
}

void CompraManager::listarCompras() {
    FILE* p = fopen("compras.dat", "rb");
    if (p == NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "NO HAY COMPRAS CARGADAS.\n";
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    Compra reg;
    bool hayActivos = false;

    while (fread(&reg, sizeof(Compra), 1, p) == 1) {
        if (!reg.getEliminado()) {

            if (!hayActivos) {
                cout << "LISTADO DE COMPRAS:\n";
                hayActivos = true;
            }

            reg.Mostrar();
        }
    }

    fclose(p);

    if (!hayActivos) {
        rlutil::setColor(rlutil::RED);
        cout << "NO HAY COMPRAS CARGADAS.\n";
        rlutil::setColor(rlutil::WHITE);
    }
}

bool CompraManager::bajaCompra(int id) {
    FILE* p = fopen("compras.dat", "rb+");
    if (p == NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "Error al abrir el archivo.\n";
        rlutil::setColor(rlutil::WHITE);
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
