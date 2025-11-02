#include <iostream>
using namespace std;

#include "PedidoCliente.h"

// === Sin STL, solo tipos primitivos y composición con Fecha ===

PedidoCliente::PedidoCliente(){
    idPedido   = 0;
    idCliente  = 0;
    idEmpleado = 0;
    total      = 0.0f;      // Fecha queda con su ctor por defecto
}

void PedidoCliente::Cargar(){
    cout << "ID pedido: ";    cin >> idPedido;
    cout << "ID cliente: ";   cin >> idCliente;
    cout << "ID empleado: ";  cin >> idEmpleado;

    cout << "Fecha:\n";
    fecha.Cargar();           // composición: delega carga a Fecha

    cout << "Total ($): ";    cin >> total;
}

void PedidoCliente::Mostrar() const{
    cout << "Pedido #" << idPedido
         << " | Cliente: "  << idCliente
         << " | Empleado: " << idEmpleado
         << " | Fecha: ";
    fecha.Mostrar();          // muestra la fecha
    cout << " | Total: $" << total << "\n";
}

