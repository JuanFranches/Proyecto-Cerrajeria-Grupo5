// DetallePedido.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include "DetallePedido.h"

DetallePedido::DetallePedido(){ idPedido=0; tipoItem=1; idItem=0; cantidad=0; precioUnitario=0; subtotal=0; }
void DetallePedido::Cargar(){
    cout<<"ID pedido: ";cin>>idPedido;
    cout<<"Tipo item (1=Producto, 2=Servicio): ";cin>>tipoItem;
    cout<<"ID item: ";cin>>idItem;
    cout<<"Cantidad: ";cin>>cantidad;
    cout<<"Precio unitario: ";cin>>precioUnitario;
    subtotal = cantidad * precioUnitario;
}
void DetallePedido::Mostrar() const{
    cout<<"Pedido#"<<idPedido
        <<" | Tipo: "<<(tipoItem==1?"Producto":"Servicio")
        <<" | ID item: "<<idItem
        <<" | Cant: "<<cantidad
        <<" | P.U.: $"<<precioUnitario
        <<" | Subtotal: $"<<subtotal<<"\n";
}
