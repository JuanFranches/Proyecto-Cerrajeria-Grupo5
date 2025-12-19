#ifndef DETALLEPEDIDOMANAGER_H
#define DETALLEPEDIDOMANAGER_H

#include "DetallePedidoArchivo.h"

class DetallePedidoManager {
public:
    DetallePedidoManager();
    void altaDetallePedido();
    void listarDetallePedidos();

private:
    DetallePedidoArchivo _repo;
};

#endif
