#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H

#include <string>
#include "Cliente.h"

class ClienteArchivo {
public:
    ClienteArchivo(std::string nombreArchivo = "clientes.dat");

    bool guardar(Cliente reg);
    Cliente leer(int pos);
    int   getCantidadRegistros();

private:
    std::string _nombreArchivo;
};

#endif
