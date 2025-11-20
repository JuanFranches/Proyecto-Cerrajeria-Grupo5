#include <iostream>
#include <limits>
using namespace std;
#include <cstring>
#include "Producto.h"


Producto::Producto(){
    idProducto=0; nombre[0]='\0'; descripcion[0]='\0'; tipo[0]='\0';
    precio=0; stock=0; idProveedor=0; eliminado=false;
}
void Producto::Cargar(){
    // ID con validación
    while (true) {
        cout << "ID producto: ";
        if (cin >> idProducto) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Error: el ID debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Nombre: ";       cin.getline(nombre,50);
    cout << "Descripcion: ";  cin.getline(descripcion,100);
    cout << "Tipo: ";         cin.getline(tipo,50);

    // Precio
    while (true) {
        cout << "Precio: ";
        if (cin >> precio) break;
        cout << "Error: el precio debe ser numerico. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Stock
    while (true) {
        cout << "Stock: ";
        if (cin >> stock) break;
        cout << "Error: el stock debe ser numerico. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // ID proveedor
    while (true) {
        cout << "ID proveedor: ";
        if (cin >> idProveedor) break;
        cout << "Error: el ID de proveedor debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    eliminado = false;
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
