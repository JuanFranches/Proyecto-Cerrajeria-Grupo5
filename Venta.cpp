#include <iostream>
using namespace std;

#include "Venta.h"
#include "rlutil.h"

Venta::Venta() {
    _idVenta    = 0;
    _idCliente  = 0;
    _idEmpleado = 0;
    _total      = 0.0f;
    _eliminado  = false;
}

void Venta::Cargar() {

    while (true) {
        cout << "ID del cliente: ";
        cin >> _idCliente;

        if (!cin.fail() && _idCliente > 0) break;

        cin.clear();
        cin.ignore(1000, '\n');
        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Intente nuevamente.\n\n";
        rlutil::setColor(rlutil::WHITE);
    }

    while (true) {
        cout << "ID del empleado: ";
        cin >> _idEmpleado;

        if (!cin.fail() && _idEmpleado > 0) break;

        cin.clear();
        cin.ignore(1000, '\n');
        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Intente nuevamente.\n\n";
        rlutil::setColor(rlutil::WHITE);
    }

    cout << "Fecha de la venta:\n";
    _fecha.Cargar();

    while (true) {
        cout << "Total de la venta: ";
        cin >> _total;

        if (!cin.fail() && _total >= 0) break;

        cin.clear();
        cin.ignore(1000, '\n');
        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Intente nuevamente.\n\n";
        rlutil::setColor(rlutil::WHITE);
    }

    _eliminado = false;
}

void Venta::Mostrar() const {
    cout << "------------------------------" << endl;
    cout << "ID venta: "    << _idVenta    << endl;
    cout << "ID cliente: "  << _idCliente  << endl;
    cout << "ID empleado: " << _idEmpleado << endl;
    cout << "Fecha: ";
    _fecha.Mostrar();
    cout << endl;
    cout << "Total: $"      << _total      << endl;
}

void Venta::setEliminado(bool e) {
    _eliminado = e;
}
