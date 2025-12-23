#ifndef COMPRA_H
#define COMPRA_H

#include <iostream>
using namespace std;

#include "Fecha.h"

class Compra {
private:
    int   _idCompra;
    int   _idProveedor;
    int   _idEmpleado;
    Fecha _fecha;
    float _total;
    bool  _eliminado;

public:
    Compra();

    void Cargar();
    void Mostrar() const;

    int   getIdCompra()    const { return _idCompra; }
    int   getIdProveedor() const { return _idProveedor; }
    int   getIdEmpleado()  const { return _idEmpleado; }
    Fecha getFecha()       const { return _fecha; }
    float getTotal()       const { return _total; }
    bool  getEliminado()   const { return _eliminado; }

    void setEliminado(bool e);
};

#endif


