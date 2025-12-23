#include <iostream>
using namespace std;
#include "ProveedorManager.h"

ProveedorManager::ProveedorManager(){}

void ProveedorManager::altaProveedor(){
    Proveedor reg;
    cout << "\nALTA DE PROVEEDOR\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Proveedor guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void ProveedorManager::listarProveedores() {
    FILE* p = fopen("proveedores.dat", "rb");
    if (p == NULL) {
        cout << "No hay proveedores cargados.\n";
        return;
    }

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
        cout << "No hay proveedores cargados.\n";
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

