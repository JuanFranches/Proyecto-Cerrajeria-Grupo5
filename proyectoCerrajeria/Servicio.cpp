#include <iostream>
#include <limits>      // 👈 agregar esto
using namespace std;
#include "Servicio.h"

Servicio::Servicio(){
    idServicio=0; nombre[0]='\0'; descripcion[0]='\0'; precio=0; eliminado=false;
}
void Servicio::Cargar(){
    // ID con validación
    while (true) {
        cout << "ID servicio: ";
        if (cin >> idServicio) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Error: el ID debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Nombre: ";       cin.getline(nombre,40);
    cout << "Descripcion: ";  cin.getline(descripcion,100);

    // Precio
    while (true) {
        cout << "Precio: ";
        if (cin >> precio) break;
        cout << "Error: el precio debe ser numerico. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    eliminado = false;
}

void Servicio::Mostrar() const{
    if(eliminado){ cout<<"(Servicio eliminado)\n"; return; }
    cout<<"Serv#"<<idServicio<<" - "<<nombre
        <<" | $"<<precio<<"\nDesc: "<<descripcion<<"\n";
}
