#ifndef DETALLEPEDIDO_H
#define DETALLEPEDIDO_H

class DetallePedido {
private:
    int   idPedido;
    int   tipoItem;
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
