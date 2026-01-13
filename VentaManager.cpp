#include <iostream>
using namespace std;

#include "VentaManager.h"
#include "rlutil.h"

VentaManager::VentaManager()
    : _archivo("ventas.dat")
{
}

void VentaManager::altaVenta() {
    Venta reg;
    int id;

    cout << "ALTA DE VENTA\n";
    cout << "----------------------\n";

    while (true) {
        cout << "ID de venta: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            rlutil::setColor(rlutil::RED);
            cout << "ID invalido.\n";
            rlutil::setColor(rlutil::WHITE);
            continue;
        }

        if (existeIdVenta(id)) {
            rlutil::setColor(rlutil::RED);
            cout << "Ese ID de venta ya existe. Intente otro.\n";
            rlutil::setColor(rlutil::WHITE);
            continue;
        }

        break;
    }

    reg.setIdVenta(id);
    reg.setEliminado(false);
    reg.Cargar();

    if (_archivo.guardar(reg)) {
        rlutil::setColor(rlutil::GREEN);
        cout << "\nVENTA GUARDADA CORRECTAMENTE\n";
        rlutil::setColor(rlutil::WHITE);
    } else {
        rlutil::setColor(rlutil::RED);
        cout << "\nERROR AL GUARDAR LA VENTA\n";
        rlutil::setColor(rlutil::WHITE);
    }
}

void VentaManager::listarVentas() {
    FILE* p = fopen("ventas.dat", "rb");
    if (p == NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "NO HAY VENTAS REGISTRADAS.\n";
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    Venta reg;
    bool hayActivas = false;

    while (fread(&reg, sizeof(Venta), 1, p) == 1) {
        if (!reg.getEliminado()) {

            if (!hayActivas) {
                cout << "LISTADO DE VENTAS:\n";
                hayActivas = true;
            }

            reg.Mostrar();
        }
    }

    fclose(p);

    if (!hayActivas) {
        rlutil::setColor(rlutil::RED);
        cout << "NO HAY VENTAS REGISTRADAS.\n";
        rlutil::setColor(rlutil::WHITE);
    }
}

bool VentaManager::bajaVenta(int id) {
    FILE* p = fopen("ventas.dat", "rb+");
    if (p == NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "Error al abrir el archivo.\n";
        rlutil::setColor(rlutil::WHITE);
        return false;
    }

    Venta reg;
    int pos = 0;

    while (fread(&reg, sizeof(Venta), 1, p) == 1) {
        if (reg.getIdVenta() == id && !reg.getEliminado()) {

            reg.setEliminado(true);

            fseek(p, pos * sizeof(Venta), SEEK_SET);
            fwrite(&reg, sizeof(Venta), 1, p);

            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

bool VentaManager::existeIdVenta(int id) {
    FILE* p = fopen("ventas.dat", "rb");
    if (p == NULL) return false;

    Venta reg;

    while (fread(&reg, sizeof(Venta), 1, p) == 1) {
        if (reg.getIdVenta() == id && !reg.getEliminado()) {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}
