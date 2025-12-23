#include <iostream>
using namespace std;

#include "VentaManager.h"

VentaManager::VentaManager()
    : _archivo("ventas.dat")
{
}

void VentaManager::altaVenta() {
    int id;

    cout << "Ingrese ID de venta: ";
    cin >> id;

    while (existeIdVenta(id)) {
        cout << "ERROR: El ID ya existe. Ingrese otro ID: ";
        cin >> id;
    }

    Venta reg;
    reg.setIdVenta(id);
    reg.setEliminado(false);

    reg.Cargar();

    if (_archivo.guardar(reg)) {
        cout << "Venta grabada correctamente.\n";
    } else {
        cout << "ERROR al grabar la venta.\n";
    }
}

void VentaManager::listarVentas() {
    int cant = _archivo.getCantidadRegistros();

    if (cant == 0) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    bool algunaActiva = false;

    for (int i = 0; i < cant; i++) {
        Venta reg = _archivo.leer(i);

        if (!reg.getEliminado()) {
            algunaActiva = true;

            cout << "=== VENTA #" << reg.getIdVenta() << " ===\n";
            reg.Mostrar();
            cout << "\n";
        }
    }


    if (!algunaActiva) {
        cout << "No hay ventas registradas.\n";
    }
}

bool VentaManager::bajaVenta(int id) {
    int cant = _archivo.getCantidadRegistros();
    bool encontrada = false;

    VentaArchivo temp("temp_ventas.dat");

    for (int i = 0; i < cant; i++) {
        Venta reg = _archivo.leer(i);

        if (reg.getIdVenta() == id) {
            reg.setEliminado(true);
            encontrada = true;
        }

        temp.guardar(reg);
    }

    if (!encontrada) return false;


    remove("ventas.dat");
    rename("temp_ventas.dat", "ventas.dat");

    return true;
}

bool VentaManager::existeIdVenta(int id) {
    int cant = _archivo.getCantidadRegistros();

    for (int i = 0; i < cant; i++) {
        Venta reg = _archivo.leer(i);


        if (!reg.getEliminado() && reg.getIdVenta() == id) {
            return true;
        }
    }

    return false;
}
