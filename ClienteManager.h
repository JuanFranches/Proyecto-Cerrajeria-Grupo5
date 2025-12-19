#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "ClienteArchivo.h"

class ClienteManager {
public:
    ClienteManager();
    void altaCliente();
    void listarClientes();

private:
    ClienteArchivo _repo;
};

#endif
