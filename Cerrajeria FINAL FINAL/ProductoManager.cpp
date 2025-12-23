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

void ProductoManager::listarProductos() {
    FILE* p = fopen("productos.dat", "rb");
    if (p == NULL) {
        cout << "No hay Productos cargados.\n";
        return;
    }

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
        cout << "No hay Productos cargados.\n";
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
