//pedidoCliente.h
#ifndef PEDIDOCLIENTE_H
#define PEDIDOCLIENTE_H

#include "Fecha.h"

class PedidoCliente {
private:
    int   idPedido;
    int   idCliente;
    int   idEmpleado;
    Fecha fecha;     /// composición
    float total;

public:
    /// Constructores
    PedidoCliente();

    /// Cargar / Mostrar
    void Cargar();
    void Mostrar() const;

    /// Getters / Setters
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

#endif // PEDIDOCLIENTE_H
