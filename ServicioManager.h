#ifndef SERVICIOMANAGER_H
#define SERVICIOMANAGER_H

#include "ServicioArchivo.h"

class ServicioManager {
public:
    ServicioManager();
    void altaServicio();
    void listarServicios();
    bool bajaServicio(int id);

private:
    ServicioArchivo _repo;
};

#endif
