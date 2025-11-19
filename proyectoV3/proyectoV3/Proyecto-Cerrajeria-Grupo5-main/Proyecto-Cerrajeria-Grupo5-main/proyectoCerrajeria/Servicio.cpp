// Servicio.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include "Servicio.h"

Servicio::Servicio(){
    idServicio=0; nombre[0]='\0'; descripcion[0]='\0'; precio=0; eliminado=false;
}
void Servicio::Cargar(){
    cout<<"ID servicio: ";cin>>idServicio; cin.ignore();
    cout<<"Nombre: ";cin.getline(nombre,40);
    cout<<"Descripcion: ";cin.getline(descripcion,100);
    cout<<"Precio: ";cin>>precio;
    eliminado=false;
}
void Servicio::Mostrar() const{
    if(eliminado){ cout<<"(Servicio eliminado)\n"; return; }
    cout<<"Serv#"<<idServicio<<" - "<<nombre
        <<" | $"<<precio<<"\nDesc: "<<descripcion<<"\n";
}
