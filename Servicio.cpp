#include <iostream>
#include <limits>
#include <cstdio>
using namespace std;
#include "Servicio.h"
#include "rlutil.h"

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
                rlutil::setColor(rlutil::RED);
                cout << "Error: el ID " << idServicio
                     << " ya esta asignado a otro servicio.\n";
                rlutil::setColor(rlutil::WHITE);
                continue;
            }

            break;
        }
        rlutil::setColor(rlutil::RED);
        cout << "Error: el ID debe ser un numero entero. Intentelo de nuevo.\n";
        rlutil::setColor(rlutil::WHITE);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Ubicacion: ";       cin.getline(nombre,40);
    cout << "Descripcion: ";  cin.getline(descripcion,100);

    while (true) {
        cout << "Precio: ";
        if (cin >> precio) break;
        rlutil::setColor(rlutil::RED);
        cout << "Error: el precio debe ser numerico. Intentelo de nuevo.\n";
        rlutil::setColor(rlutil::WHITE);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    eliminado = false;
}

void Servicio::Mostrar() const{
    if(eliminado){ cout<<"(Servicio eliminado)\n"; return; }
    cout << "---------------------------\n";
    cout<<"ID: "<<idServicio<<"\n";
    cout<<"Ubicacion: "<<nombre<<"\n";
    cout<<"Descripcion: "<<descripcion<<"\n";
    cout<<"Precio: $"<<precio<<"\n";
}

void  Servicio::setEliminado(bool e){ eliminado=e; }

