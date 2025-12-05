#include <iostream>
#include <limits>
#include <cstdio>
using namespace std;
#include "Servicio.h"

Servicio::Servicio(){
    idServicio=0; nombre[0]='\0'; descripcion[0]='\0'; precio=0; eliminado=false;
}

void Servicio::Cargar(){

    while (true) {
        cout << "ID servicio: ";
        if (cin >> idServicio) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool repetido = false;
            FILE* p = fopen("servicios.dat", "rb");
            if (p != NULL) {
                Servicio aux;
                while (fread(&aux, sizeof(Servicio), 1, p) == 1) {
                    if (aux.idServicio == idServicio && !aux.eliminado) {
                        repetido = true;
                        break;
                    }
                }
                fclose(p);
            }

            if (repetido) {
                cout << "Error: el ID " << idServicio
                     << " ya esta asignado a otro servicio.\n";
                continue;
            }

            break;
        }
        cout << "Error: el ID debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Nombre: ";       cin.getline(nombre,40);
    cout << "Descripcion: ";  cin.getline(descripcion,100);

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
