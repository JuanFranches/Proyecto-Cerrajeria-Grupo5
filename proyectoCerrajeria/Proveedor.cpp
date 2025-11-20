#include <iostream>
using namespace std;
#include <cstring>
#include "Proveedor.h"
#include <limits>
Proveedor::Proveedor(){
    idProveedor=0; nombre[0]='\0'; telefono[0]='\0'; direccion[0]='\0'; email[0]='\0'; eliminado=false;
}
void Proveedor::Cargar(){
    while (true) {
        cout << "ID proveedor: ";
        if (cin >> idProveedor) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Error: el ID debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Nombre: ";
    cin.getline(nombre,50);

    while (true) {
        cout << "Telefono: ";
        cin.getline(telefono,20);

        bool ok = (telefono[0] != '\0');
        for (int i = 0; ok && telefono[i] != '\0'; ++i) {
            if (telefono[i] < '0' || telefono[i] > '9') {
                ok = false;
            }
        }

        if (ok) break;

        cout << "Error: el telefono debe contener solo numeros (sin espacios, + ni guiones).\n";
    }

    cout << "Direccion: ";
    cin.getline(direccion,100);


    while (true) {
        cout << "Email: ";
        cin.getline(email,50);

        bool tieneArroba = false;
        for (int i = 0; email[i] != '\0'; ++i) {
            if (email[i] == '@') {
                tieneArroba = true;
                break;
            }
        }

        if (tieneArroba) break;

        cout << "Error: el email debe contener un @ (ej: usuario@dominio.com).\n";
    }

    eliminado = false;
}


void Proveedor::Mostrar() const{
    if (eliminado) return;
    if (idProveedor == 0 || nombre[0] == '\0') return; // ignorar vacíos

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
