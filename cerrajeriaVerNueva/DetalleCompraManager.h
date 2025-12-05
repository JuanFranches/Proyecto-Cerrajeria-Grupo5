#ifndef DETALLECOMPRAMANAGER_H
#define DETALLECOMPRAMANAGER_H

#include "DetalleCompraArchivo.h"

class DetalleCompraManager {
public:
    DetalleCompraManager();
    void altaDetalleCompra();
    void listarDetalleCompras();

private:
    DetalleCompraArchivo _repo;
};

#endif
