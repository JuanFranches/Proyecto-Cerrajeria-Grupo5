#include <iostream>
using namespace std;

#include "Compra.h"


Compra::Compra() {
    _idCompra    = 0;
    _idProveedor = 0;
    _idEmpleado  = 0;
    _total       = 0.0f;
    _eliminado   = false;
}


void Compra::Cargar() {
    cout << "ID de la compra: ";
    cin >> _idCompra;

    cout << "ID del proveedor: ";
    cin >> _idProveedor;

    cout << "ID del empleado: ";
    cin >> _idEmpleado;

    cout << "Fecha de la compra:\n";
    _fecha.Cargar();

    cout << "Total de la compra: ";
    cin >> _total;

    _eliminado = false;
}


void Compra::Mostrar() const {
    cout << "ID compra: "    << _idCompra    << endl;
    cout << "ID proveedor: " << _idProveedor << endl;
    cout << "ID empleado: "  << _idEmpleado  << endl;
    cout << "Fecha: ";
    _fecha.Mostrar();
    cout << "Total: $"       << _total       << endl;
    cout << "Eliminado: "    << (_eliminado ? "SI" : "NO") << endl;
    cout << "------------------------------" << endl;
}

void Compra::setEliminado(bool e) {
    _eliminado = e;
}

