// Producto.h
#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    int  idProducto;
    char nombre[50];
    char descripcion[100];
    char tipo[50];
    float precio;
    int  stock;
    int  idProveedor;
    bool eliminado;

public:
    Producto();
    void Cargar();
    void Mostrar() const;

    int  getIdProducto() const;   void setIdProducto(int id);
    const char* getNombre() const;void setNombre(const char* n);
    float getPrecio() const;      void setPrecio(float p);
    bool  getEliminado() const;   void setEliminado(bool e);
};
#endif
