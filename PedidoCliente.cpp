#include <iostream>
#include <limits>
#include <cstdio>
using namespace std;
#include "PedidoCliente.h"

PedidoCliente::PedidoCliente(){
    idPedido   = 0;
    idCliente  = 0;
    idEmpleado = 0;
    total      = 0.0f;
}

void PedidoCliente::Cargar(){

    while (true) {
        cout << "ID pedido: ";
        if (cin >> idPedido) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool repetido = false;
            FILE* p = fopen("pedidos.dat", "rb");
            if (p != NULL) {
                PedidoCliente aux;
                while (fread(&aux, sizeof(PedidoCliente), 1, p) == 1) {
                    if (aux.idPedido == idPedido) {
                        repetido = true;
                        break;
                    }
                }
                fclose(p);
            }

            if (repetido) {
                cout << "Error: el ID " << idPedido
                     << " ya esta asignado a otro pedido.\n";
                continue;
            }

            break;
        }
        cout << "Error: el ID de pedido debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "ID cliente: ";
        if (cin >> idCliente) break;
        cout << "Error: el ID de cliente debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "ID empleado: ";
        if (cin >> idEmpleado) break;
        cout << "Error: el ID de empleado debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Fecha:\n";
    fecha.Cargar();

    while (true) {
        cout << "Total ($): ";
        if (cin >> total) break;
        cout << "Error: el total debe ser numerico. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void PedidoCliente::Mostrar() const{
    cout << "Pedido #"   << idPedido
         << " | Cliente: "  << idCliente
         << " | Empleado: " << idEmpleado
         << " | Fecha: ";
    fecha.Mostrar();
    cout << " | Total: $" << total << endl;
}

void PedidoCliente::setIdPedido(int v){    idPedido = v; }
int  PedidoCliente::getIdPedido() const{   return idPedido; }

void PedidoCliente::setIdCliente(int v){   idCliente = v; }
int  PedidoCliente::getIdCliente() const{  return idCliente; }

void PedidoCliente::setIdEmpleado(int v){  idEmpleado = v; }
int  PedidoCliente::getIdEmpleado() const{ return idEmpleado; }

void PedidoCliente::setFecha(Fecha f){     fecha = f; }
Fecha PedidoCliente::getFecha() const{     return fecha; }

void PedidoCliente::setTotal(float v){     total = v; }
float PedidoCliente::getTotal() const{     return total; }
