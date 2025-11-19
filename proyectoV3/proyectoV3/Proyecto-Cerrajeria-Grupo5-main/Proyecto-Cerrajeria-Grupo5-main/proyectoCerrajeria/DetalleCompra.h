// DetalleCompra.h
#ifndef DETALLECOMPRA_H
#define DETALLECOMPRA_H

class DetalleCompra {
private:
    int   idCompra;
    int   idProducto;
    int   cantidad;
    float precioUnitario;
    float subtotal;

public:
    DetalleCompra();
    void Cargar();
    void Mostrar() const;
};
#endif
