#include <iostream>
#include <limits>
#include <cstdio>
using namespace std;
#include "Cliente.h"

Cliente::Cliente(){
    idCliente=0;
    nombre[0]='\0';
    apellido[0]='\0';
    telefono[0]='\0';
    direccion[0]='\0';
    email[0]='\0';
    eliminado=false;
}

void Cliente::Cargar(){
    while (true) {
        cout << "ID cliente: ";
        if (!(cin >> idCliente)) {
            cout << "Error: el ID debe ser un numero entero. Intentelo de nuevo.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bool repetido = false;

        FILE* p = fopen("clientes.dat", "rb");
        if (p != NULL) {
            Cliente aux;
            while (fread(&aux, sizeof(Cliente), 1, p) == 1) {
                if (aux.idCliente == idCliente && !aux.eliminado) {
                    repetido = true;
                    break;
                }
            }
            fclose(p);
        }

        if (repetido) {
            cout << "Error: el ID " << idCliente
                 << " ya esta asignado a otro cliente. Intente con otro numero.\n";
            continue;
        }

        break;
    }

    cout << "Nombre: ";
    cin.getline(nombre,30);

    cout << "Apellido: ";
    cin.getline(apellido,30);

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

        cout << "Error: el telefono debe contener solo numeros (sin espacios ni guiones).\n";
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

void Cliente::Mostrar() const{
    if(eliminado){
        cout<<"(Cliente eliminado)\n";
        return;
    }
    cout<<"Cliente#"<<idCliente<<" - "<<apellido<<", "<<nombre
        <<" | Tel: "<<telefono
        <<" | Dir: "<<direccion
        <<" | Email: "<<email<<"\n";
}
