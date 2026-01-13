#ifndef PROVEEDOR_H
#define PROVEEDOR_H

class Proveedor {
private:
    int  idProveedor;
    char nombre[50];
    char telefono[20];
    char direccion[100];
    char email[50];
    bool eliminado;

public:
    Proveedor();
    void Cargar();
    void Mostrar() const;

    int  getIdProveedor() const;
    void setIdProveedor(int id);
    const char* getNombre() const;
    void setNombre(const char* n);
    bool getEliminado() const;
    void setEliminado(bool e);
};

#endif
