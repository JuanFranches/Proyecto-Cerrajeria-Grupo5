#ifndef INFORMEVENTASMANAGER_H
#define INFORMEVENTASMANAGER_H

#include "VentaArchivo.h"
#include "Fecha.h"

class InformeVentasManager {
private:
    VentaArchivo _archivoVentas;

    int  compararFechas(const Fecha& a, const Fecha& b) const;
    bool estaEnRango(const Fecha& f, const Fecha& desde, const Fecha& hasta) const;

public:
    InformeVentasManager();


    void informeFacturacionVentasPorPeriodo();


    void informeFacturacionClientePorPeriodo();


    void informeFacturacionVentasTotal();
};

#endif
