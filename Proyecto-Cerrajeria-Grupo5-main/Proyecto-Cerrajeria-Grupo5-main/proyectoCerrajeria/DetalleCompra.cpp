// DetalleCompra.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include "DetalleCompra.h"

DetalleCompra::DetalleCompra(){ idCompra=0; idProducto=0; cantidad=0; precioUnitario=0; subtotal=0; }
void DetalleCompra::Cargar(){
    cout<<"ID compra: ";cin>>idCompra;
    cout<<"ID producto: ";cin>>idProducto;
    cout<<"Cantidad: ";cin>>cantidad;
    cout<<"Precio unitario: ";cin>>precioUnitario;
    subtotal = cantidad * precioUnitario;
}
void DetalleCompra::Mostrar() const{
    cout<<"Compra#"<<idCompra
        <<" | Prod: "<<idProducto
        <<" | Cant: "<<cantidad
        <<" | P.U.: $"<<precioUnitario
        <<" | Subtotal: $"<<subtotal<<"\n";
}
