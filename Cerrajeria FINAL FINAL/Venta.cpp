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
    cout << "ID del cliente: ";
    cin >> _idCliente;

    cout << "ID del empleado: ";
    cin >> _idEmpleado;

    cout << "Fecha de la venta:\n";
    _fecha.Cargar();

    cout << "Total de la venta: ";
    cin >> _total;

    _eliminado = false;
}


void Venta::Mostrar() const {
    rlutil::cls();
    cout << "ID venta: "    << _idVenta    << endl;
    cout << "ID cliente: "  << _idCliente  << endl;
    cout << "ID empleado: " << _idEmpleado << endl;
    cout << "Fecha: ";
    _fecha.Mostrar();
    cout << "Total: $"      << _total      << endl;
    cout << "Eliminado: "   << (_eliminado ? "SI" : "NO") << endl;
    cout << "------------------------------" << endl;
}

void Venta::setEliminado(bool e) {
    _eliminado = e;
}
