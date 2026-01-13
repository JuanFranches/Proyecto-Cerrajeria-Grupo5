#ifndef PRODUCTOMANAGER_H
#define PRODUCTOMANAGER_H

#include "ProductoArchivo.h"

class ProductoManager {
public:
    ProductoManager();
    void altaProducto();
    void listarProductos();
    bool bajaProducto(int id);

private:
    ProductoArchivo _repo;
};

#endif
