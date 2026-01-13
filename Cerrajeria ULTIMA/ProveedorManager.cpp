#include <iostream>
using namespace std;
#include "ProveedorManager.h"
#include "rlutil.h"

ProveedorManager::ProveedorManager(){}

void ProveedorManager::altaProveedor(){
    Proveedor reg;
    cout << "\nALTA DE PROVEEDOR\n";
    cout << "---------------------------\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        rlutil::setColor(rlutil::GREEN);
        cout << endl;
        cout << "PROVEEDOR GUARDADO EN ARCHIVO!!!\n";
        rlutil::setColor(rlutil::WHITE);
        } else {
        rlutil::setColor(rlutil::RED);
        cout << "Error de apertura.\n";
        rlutil::setColor(rlutil::WHITE);
        }
}

void ProveedorManager::listarProveedores() {
    FILE* p = fopen("proveedores.dat", "rb");
    if (p == NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No hay proveedores cargados.\n";
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    cout << "LISTADO DE PROVEEDORES\n";

    Proveedor reg;
    bool hayActivos = false;

    while (fread(&reg, sizeof(Proveedor), 1, p) == 1) {
        if (!reg.getEliminado()) {
            reg.Mostrar();
            hayActivos = true;
        }
    }

    fclose(p);

    if (!hayActivos) {
        rlutil::setColor(rlutil::RED);
        cout << "No hay proveedores cargados.\n";
        rlutil::setColor(rlutil::WHITE);
    }
}

bool ProveedorManager::bajaProveedor(int id) {
    FILE* p = fopen("proveedores.dat", "rb+");
    if (p == NULL) {
        cout << "Error al abrir el archivo.\n";
        return false;
    }

    Proveedor reg;
    int pos = 0;

    while (fread(&reg, sizeof(Proveedor), 1, p) == 1) {
        if (reg.getIdProveedor() == id && !reg.getEliminado()) {
            reg.setEliminado(true);

            fseek(p, pos * sizeof(Proveedor), SEEK_SET);
            fwrite(&reg, sizeof(Proveedor), 1, p);

            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

