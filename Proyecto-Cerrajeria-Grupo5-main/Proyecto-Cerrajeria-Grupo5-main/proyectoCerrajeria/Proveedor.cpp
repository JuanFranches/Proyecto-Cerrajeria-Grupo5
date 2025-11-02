// Proveedor.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include <cstring>
#include "Proveedor.h"

Proveedor::Proveedor(){
    idProveedor=0; nombre[0]='\0'; telefono[0]='\0'; direccion[0]='\0'; email[0]='\0'; eliminado=false;
}
void Proveedor::Cargar(){
    cout<<"ID proveedor: ";cin>>idProveedor; cin.ignore();
    cout<<"Nombre: ";cin.getline(nombre,50);
    cout<<"Telefono: ";cin.getline(telefono,20);
    cout<<"Direccion: ";cin.getline(direccion,100);
    cout<<"Email: ";cin.getline(email,50);
    eliminado=false;
}
void Proveedor::Mostrar() const{
    if(eliminado){ cout<<"(Proveedor eliminado)\n"; return; }
    cout<<"Prov#"<<idProveedor<<" - "<<nombre
        <<" | Tel: "<<telefono
        <<" | Dir: "<<direccion
        <<" | Email: "<<email<<"\n";
}
int  Proveedor::getIdProveedor() const{ return idProveedor; }
void Proveedor::setIdProveedor(int id){ idProveedor=id; }
const char* Proveedor::getNombre() const{ return nombre; }
void Proveedor::setNombre(const char* n){ std::strncpy(nombre,n,49); nombre[49]='\0'; }
bool Proveedor::getEliminado() const{ return eliminado; }
void Proveedor::setEliminado(bool e){ eliminado=e; }
