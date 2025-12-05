#ifndef COMPRAMANAGER_H
#define COMPRAMANAGER_H

#include "CompraArchivo.h"

class CompraManager {
public:
    CompraManager();
    void altaCompra();
    void listarCompras();

private:
    CompraArchivo _repo;
};

#endif
