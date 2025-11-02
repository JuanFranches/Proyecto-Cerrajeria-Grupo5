// PedidoCliente.h
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
};
#endif
