// Cliente.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include "Cliente.h"

Cliente::Cliente(){
    idCliente=0; nombre[0]='\0'; apellido[0]='\0'; telefono[0]='\0'; direccion[0]='\0'; email[0]='\0'; eliminado=false;
}
void Cliente::Cargar(){
    cout<<"ID cliente: ";cin>>idCliente; cin.ignore();
    cout<<"Nombre: ";cin.getline(nombre,30);
    cout<<"Apellido: ";cin.getline(apellido,30);
    cout<<"Telefono: ";cin.getline(telefono,20);
    cout<<"Direccion: ";cin.getline(direccion,100);
    cout<<"Email: ";cin.getline(email,50);
    eliminado=false;
}
void Cliente::Mostrar() const{
    if(eliminado){ cout<<"(Cliente eliminado)\n"; return; }
    cout<<"Cliente#"<<idCliente<<" - "<<apellido<<", "<<nombre
        <<" | Tel: "<<telefono
        <<" | Dir: "<<direccion
        <<" | Email: "<<email<<"\n";
}
