#ifndef PEDIDOCLIENTE_H
#define PEDIDOCLIENTE_H

#include "Fecha.h"

class PedidoCliente {
private:
    int   idPedido;
    int   idCliente;
    int   idEmpleado;
    Fecha fecha;
    float total;

public:
    PedidoCliente();

    void Cargar();
    void Mostrar() const;

    void  setIdPedido(int v);
    int   getIdPedido() const;

    void  setIdCliente(int v);
    int   getIdCliente() const;

    void  setIdEmpleado(int v);
    int   getIdEmpleado() const;

    void  setFecha(Fecha f);
    Fecha getFecha() const;

    void  setTotal(float v);
    float getTotal() const;
};

#endif
