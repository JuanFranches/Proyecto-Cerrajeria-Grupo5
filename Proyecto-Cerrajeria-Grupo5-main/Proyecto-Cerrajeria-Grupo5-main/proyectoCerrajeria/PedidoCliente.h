#ifndef PEDIDOCLIENTE_H
#define PEDIDOCLIENTE_H

#include <iostream>
using namespace std;

#include "Fecha.h"   // la clase Fecha debe tener Cargar() y Mostrar()

class PedidoCliente {
private:
    int   idPedido;
    int   idCliente;
    int   idEmpleado;
    Fecha fecha;     // composición
    float total;

public:
    // --- Constructores ---
    PedidoCliente(){
        idPedido = 0; idCliente = 0; idEmpleado = 0;
        total = 0.0f; // fecha queda con su ctor por defecto
    }

    // --- Cargar / Mostrar ---
    void Cargar(){
        cout << "ID pedido: ";    cin >> idPedido;
        cout << "ID cliente: ";   cin >> idCliente;
        cout << "ID empleado: ";  cin >> idEmpleado;
        cout << "Fecha:\n";       fecha.Cargar();
        cout << "Total ($): ";    cin >> total;
    }

    void Mostrar() const{
        cout << "Pedido #" << idPedido
             << " | Cliente: "  << idCliente
             << " | Empleado: " << idEmpleado
             << " | Fecha: ";
        fecha.Mostrar();
        cout << " | Total: $" << total << "\n";
    }

    // --- Getters/Setters simples (opcionales) ---
    void setIdPedido(int v){ idPedido=v; }
    int  getIdPedido() const{ return idPedido; }
    void setIdCliente(int v){ idCliente=v; }
    int  getIdCliente() const{ return idCliente; }
    void setIdEmpleado(int v){ idEmpleado=v; }
    int  getIdEmpleado() const{ return idEmpleado; }
    void setFecha(Fecha f){ fecha=f; }
    Fecha getFecha() const{ return fecha; }
    void setTotal(float v){ total=v; }
    float getTotal() const{ return total; }
};

#endif // PEDIDOCLIENTE_H
