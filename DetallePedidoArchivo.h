#ifndef DETALLEPEDIDOARCHIVO_H
#define DETALLEPEDIDOARCHIVO_H

#include <string>
#include "DetallePedido.h"

class DetallePedidoArchivo {
public:
    DetallePedidoArchivo(std::string nombreArchivo = "detalles_pedido.dat");

    bool guardar(DetallePedido reg);
    DetallePedido leer(int pos);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
