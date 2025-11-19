//pedidoCliente.cpp
#include <iostream>
using namespace std;

#include "PedidoCliente.h"

PedidoCliente::PedidoCliente(){
    idPedido   = 0;
    idCliente  = 0;
    idEmpleado = 0;
    total      = 0.0f;   /// fecha usa su ctor por defecto
}

void PedidoCliente::Cargar(){
    cout << "ID pedido: ";
    cin >> idPedido;

    cout << "ID cliente: ";
    cin >> idCliente;

    cout << "ID empleado: ";
    cin >> idEmpleado;

    cout << "Fecha:" << endl;
    fecha.Cargar();      /// delega en Fecha

    cout << "Total ($): ";
    cin >> total;
}

void PedidoCliente::Mostrar() const{
    cout << "Pedido #"   << idPedido
         << " | Cliente: "  << idCliente
         << " | Empleado: " << idEmpleado
         << " | Fecha: ";
    fecha.Mostrar();
    cout << " | Total: $" << total << endl;
}

/// Getters / Setters

void PedidoCliente::setIdPedido(int v){
    idPedido = v;
}
int PedidoCliente::getIdPedido() const{
    return idPedido;
}

void PedidoCliente::setIdCliente(int v){
    idCliente = v;
}
int PedidoCliente::getIdCliente() const{
    return idCliente;
}

void PedidoCliente::setIdEmpleado(int v){
    idEmpleado = v;
}
int PedidoCliente::getIdEmpleado() const{
    return idEmpleado;
}

void PedidoCliente::setFecha(Fecha f){
    fecha = f;
}
Fecha PedidoCliente::getFecha() const{
    return fecha;
}

void PedidoCliente::setTotal(float v){
    total = v;
}
float PedidoCliente::getTotal() const{
    return total;
}
