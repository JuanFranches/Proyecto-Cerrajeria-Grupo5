#include <iostream>
using namespace std;
#include "rlutil.h"
#include "Compra.h"


Compra::Compra() {
    _idCompra    = 0;
    _idProveedor = 0;
    _idEmpleado  = 0;
    _total       = 0.0f;
    _eliminado   = false;
}


void Compra::Cargar() {

    while (true) {
        cout << "ID de la compra: ";
        cin >> _idCompra;

        if (!cin.fail() && _idCompra > 0) break;

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. Intente nuevamente.\n\n";
    }

    while (true) {
        cout << "ID del proveedor: ";
        cin >> _idProveedor;

        if (!cin.fail() && _idProveedor > 0) break;

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. Intente nuevamente.\n\n";
    }

    while (true) {
        cout << "ID del empleado: ";
        cin >> _idEmpleado;

        if (!cin.fail() && _idEmpleado > 0) break;

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. Intente nuevamente.\n\n";
    }

    cout << "Fecha de la compra:\n";
    _fecha.Cargar();

    while (true) {
        cout << "Total de la compra: ";
        cin >> _total;

        if (!cin.fail() && _total >= 0) break;

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. Intente nuevamente.\n\n";
    }

    _eliminado = false;
}


void Compra::Mostrar() const {
    rlutil::cls();
    cout << "LISTADO DE COMPRAS" << endl << endl;
    cout << "ID compra: "    << _idCompra    << endl;
    cout << "ID proveedor: " << _idProveedor << endl;
    cout << "ID empleado: "  << _idEmpleado  << endl;
    cout << "Fecha: ";
    _fecha.Mostrar();
    cout << endl;
    cout << "Total: $"       << _total       << endl;
    cout << "Eliminado: "    << (_eliminado ? "SI" : "NO") << endl;
    cout << "------------------------------" << endl;
}

void Compra::setEliminado(bool e) {
    _eliminado = e;
}

