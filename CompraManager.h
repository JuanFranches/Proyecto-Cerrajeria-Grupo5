#ifndef COMPRAMANAGER_H
#define COMPRAMANAGER_H

#include "CompraArchivo.h"

class CompraManager {
private:
    CompraArchivo _archivo;

public:
    CompraManager();

    void altaCompra();
    void listarCompras();
    bool bajaCompra(int id);
};

#endif
