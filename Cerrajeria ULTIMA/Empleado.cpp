#include <iostream>
#include <limits>
#include <cstdio>
using namespace std;
#include "Empleado.h"
#include "rlutil.h"

Empleado::Empleado(){
    idEmpleado=0; nombre[0]='\0'; apellido[0]='\0'; cargo[0]='\0';
    sueldo=0; fechaIngreso=Fecha(1,1,2000); eliminado=false;
}

void Empleado::Cargar(){
    while (true) {
        cout << "ID empleado: ";
        if (cin >> idEmpleado) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool repetido = false;
            FILE* p = fopen("empleados.dat", "rb");
            if (p != NULL) {
                Empleado aux;
                while (fread(&aux, sizeof(Empleado), 1, p) == 1) {
                    if (aux.idEmpleado == idEmpleado && !aux.eliminado) {
                        repetido = true;
                        break;
                    }
                }
                fclose(p);
            }

            if (repetido) {
                    rlutil::setColor(rlutil::RED);
                cout << "Error: el ID " << idEmpleado
                     << " ya esta asignado a otro empleado.\n";
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

    cout << "Nombre: ";    cin.getline(nombre,30);
    cout << "Apellido: ";  cin.getline(apellido,30);
    cout << "Cargo: ";     cin.getline(cargo,30);

    while (true) {
        cout << "Sueldo: ";
        if (cin >> sueldo) break;
        rlutil::setColor(rlutil::RED);
        cout << "Error: el sueldo debe ser numerico. Intentelo de nuevo.\n";
        rlutil::setColor(rlutil::WHITE);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Fecha ingreso:\n";
    fechaIngreso.Cargar();

    eliminado = false;
}

void Empleado::Mostrar() const {
    if (eliminado) return;

    cout << "---------------------------\n";
    cout << "ID Empleado: " << idEmpleado << "\n";
    cout << "Apellido: " << apellido << "\n";
    cout << "Nombre: " << nombre << "\n";
    cout << "Cargo: " << cargo << "\n";
    cout << "Sueldo: $" << sueldo << "\n";
    cout << "Fecha de ingreso: ";
    fechaIngreso.Mostrar();
    cout << "\n";
}

void Empleado::setEliminado(bool e){ eliminado=e; }
