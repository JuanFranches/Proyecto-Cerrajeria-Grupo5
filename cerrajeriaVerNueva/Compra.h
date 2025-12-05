#ifndef COMPRA_H
#define COMPRA_H

#include "Fecha.h"

class Compra {
private:
    int   idCompra;
    int   idProveedor;
    int   idEmpleado;
    Fecha fecha;
    float total;

public:
    Compra();
    void Cargar();
    void Mostrar() const;

    int getIdCompra() const { return idCompra; }
};

#endif
