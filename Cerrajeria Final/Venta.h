#ifndef VENTA_H
#define VENTA_H

#include <iostream>
using namespace std;

#include "Fecha.h"

class Venta {
private:
    int   _idVenta;
    int   _idCliente;
    int   _idEmpleado;
    Fecha _fecha;
    float _total;
    bool  _eliminado;

public:
    Venta();

    void Cargar();
    void Mostrar() const;

    int   getIdVenta()    const { return _idVenta; }
    int   getIdCliente()  const { return _idCliente; }
    int   getIdEmpleado() const { return _idEmpleado; }
    Fecha getFecha()      const { return _fecha; }
    float getTotal()      const { return _total; }
    bool  getEliminado()  const { return _eliminado; }
    void setIdVenta(int id) { _idVenta = id; }

    void  setEliminado(bool e);
};

#endif
