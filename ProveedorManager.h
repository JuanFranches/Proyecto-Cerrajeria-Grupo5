#ifndef PROVEEDORMANAGER_H
#define PROVEEDORMANAGER_H

#include "ProveedorArchivo.h"

class ProveedorManager {
public:
    ProveedorManager();
    void altaProveedor();
    void listarProveedores();
    bool bajaProveedor(int id);

private:
    ProveedorArchivo _repo;
};

#endif
