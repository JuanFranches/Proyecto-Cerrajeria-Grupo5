// Cliente.h
#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
    int  idCliente;
    char nombre[30];
    char apellido[30];
    char telefono[20];
    char direccion[100];
    char email[50];
    bool eliminado;

public:
    Cliente();
    void Cargar();
    void Mostrar() const;
};
#endif
