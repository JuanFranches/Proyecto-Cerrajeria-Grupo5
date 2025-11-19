// Producto.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include <cstring>
#include "Producto.h"

Producto::Producto(){
    idProducto=0; nombre[0]='\0'; descripcion[0]='\0'; tipo[0]='\0';
    precio=0; stock=0; idProveedor=0; eliminado=false;
}
void Producto::Cargar(){
    cout<<"ID producto: ";cin>>idProducto; cin.ignore();
    cout<<"Nombre: ";cin.getline(nombre,50);
    cout<<"Descripcion: ";cin.getline(descripcion,100);
    cout<<"Tipo: ";cin.getline(tipo,50);
    cout<<"Precio: ";cin>>precio;
    cout<<"Stock: ";cin>>stock;
    cout<<"ID proveedor: ";cin>>idProveedor;
    eliminado=false;
}
void Producto::Mostrar() const{
    if(eliminado){ cout<<"(Producto eliminado)\n"; return; }
    cout<<"---------------------------\n";
    cout<<"ID: "<<idProducto<<"\n";
    cout<<"Nombre: "<<nombre<<"\n";
    cout<<"Descripcion: "<<descripcion<<"\n";
    cout<<"Tipo: "<<tipo<<"\n";
    cout<<"Precio: $"<<precio<<"\n";
    cout<<"Stock: "<<stock<<"\n";
    cout<<"ID Proveedor: "<<idProveedor<<"\n";
}
int  Producto::getIdProducto() const{ return idProducto; }
void Producto::setIdProducto(int id){ idProducto=id; }
const char* Producto::getNombre() const{ return nombre; }
void Producto::setNombre(const char* n){ std::strncpy(nombre,n,49); nombre[49]='\0'; }
float Producto::getPrecio() const{ return precio; }
void  Producto::setPrecio(float p){ precio=p; }
bool  Producto::getEliminado() const{ return eliminado; }
void  Producto::setEliminado(bool e){ eliminado=e; }
