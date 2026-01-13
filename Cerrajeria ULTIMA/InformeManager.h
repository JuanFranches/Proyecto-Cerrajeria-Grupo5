#ifndef INFORMEMANAGER_H
#define INFORMEMANAGER_H

#include "CompraArchivo.h"
#include "Fecha.h"

class InformeManager {
private:
    CompraArchivo _archivoCompras;

    int  compararFechas(const Fecha& a, const Fecha& b) const;
    bool estaEnRango(const Fecha& f, const Fecha& desde, const Fecha& hasta) const;

public:
    InformeManager();
    void informeFacturacionTotal();

    void informeFacturacionPorPeriodo();


    void informeFacturacionProveedorPorPeriodo();
};

#endif
