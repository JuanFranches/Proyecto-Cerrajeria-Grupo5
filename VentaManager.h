#ifndef VENTAMANAGER_H
#define VENTAMANAGER_H

#include "VentaArchivo.h"

class VentaManager {
private:
    VentaArchivo _archivo;

public:
    VentaManager();

    void altaVenta();
    void listarVentas();
    bool bajaVenta(int id);
    bool existeIdVenta(int id);

};

#endif
