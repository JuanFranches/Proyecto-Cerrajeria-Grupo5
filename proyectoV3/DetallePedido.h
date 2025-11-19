// DetallePedido.h
#ifndef DETALLEPEDIDO_H
#define DETALLEPEDIDO_H

class DetallePedido {
private:
    int   idPedido;
    int   tipoItem;        // 1=Producto, 2=Servicio
    int   idItem;
    int   cantidad;
    float precioUnitario;
    float subtotal;

public:
    DetallePedido();
    void Cargar();
    void Mostrar() const;
};
#endif
