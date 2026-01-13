#include <iostream>
using namespace std;
#include "ProductoManager.h"
#include "rlutil.h"

ProductoManager::ProductoManager(){}

void ProductoManager::altaProducto(){
    Producto reg;
    cout << "\nALTA DE PRODUCTO\n";
    cout << "---------------------------\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        rlutil::setColor(rlutil::GREEN);
        cout << endl;
        cout << "PRODUCTO GUARDADO EN ARCHIVO!!!\n";
        rlutil::setColor(rlutil::WHITE);
        } else {
        rlutil::setColor(rlutil::RED);
        cout << "Error de apertura.\n";
        rlutil::setColor(rlutil::WHITE);
        }
}

void ProductoManager::listarProductos() {
    FILE* p = fopen("productos.dat", "rb");
    if (p == NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No hay Productos cargados.\n";
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    cout << "LISTADO DE PRODUCTOS\n";

    Producto reg;
    bool hayActivos = false;

    while (fread(&reg, sizeof(Producto), 1, p) == 1) {
        if (!reg.getEliminado()) {
            reg.Mostrar();
            hayActivos = true;
        }
    }

    fclose(p);

    if (!hayActivos) {
        rlutil::setColor(rlutil::RED);
        cout << "No hay Productos cargados.\n";
        rlutil::setColor(rlutil::WHITE);
    }
}

bool ProductoManager::bajaProducto(int id) {
    FILE* p = fopen("productos.dat", "rb+");
    if (p == NULL) {
        cout << "Error al abrir el archivo.\n";
        return false;
    }

    Producto reg;
    int pos = 0;

    while (fread(&reg, sizeof(Producto), 1, p) == 1) {
        if (reg.getIdProducto() == id && !reg.getEliminado()) {
            reg.setEliminado(true);

            fseek(p, pos * sizeof(Producto), SEEK_SET);
            fwrite(&reg, sizeof(Producto), 1, p);

            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}
