#ifndef PEDIDOCLIENTEARCHIVO_H
#define PEDIDOCLIENTEARCHIVO_H

#include <string>
#include "PedidoCliente.h"

class PedidoClienteArchivo {
public:
    PedidoClienteArchivo(std::string nombreArchivo = "pedidos.dat");

    bool guardar(PedidoCliente reg);
    PedidoCliente leer(int pos);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
