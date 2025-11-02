// Compra.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include "Compra.h"

Compra::Compra(){ idCompra=0; idProveedor=0; idEmpleado=0; fecha=Fecha(1,1,2000); total=0; }
void Compra::Cargar(){
    cout<<"ID compra: ";cin>>idCompra;
    cout<<"ID proveedor: ";cin>>idProveedor;
    cout<<"ID empleado: ";cin>>idEmpleado;
    cout<<"Fecha de compra:\n"; fecha.Cargar();
    cout<<"Total: ";cin>>total;
}
void Compra::Mostrar() const{
    cout<<"Compra#"<<idCompra
        <<" | Prov: "<<idProveedor
        <<" | Emp: "<<idEmpleado
        <<" | Fecha: "; fecha.Mostrar();
    cout<<" | Total: $"<<total<<"\n";
}
