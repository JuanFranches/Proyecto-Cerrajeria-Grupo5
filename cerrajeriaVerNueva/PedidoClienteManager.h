#ifndef PEDIDOCLIENTEMANAGER_H
#define PEDIDOCLIENTEMANAGER_H

#include "PedidoClienteArchivo.h"

class PedidoClienteManager {
public:
    PedidoClienteManager();
    void altaPedido();
    void listarPedidos();

private:
    PedidoClienteArchivo _repo;
};

#endif
