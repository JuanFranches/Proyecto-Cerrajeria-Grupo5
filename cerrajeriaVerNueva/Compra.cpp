#include <iostream>
#include <limits>
#include <cstdio>
using namespace std;
#include "Compra.h"

Compra::Compra(){
    idCompra=0; idProveedor=0; idEmpleado=0; fecha=Fecha(1,1,2000); total=0;
}

void Compra::Cargar(){
    while (true) {
        cout << "ID compra: ";
        if (cin >> idCompra) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool repetido = false;
            FILE* p = fopen("compras.dat", "rb");
            if (p != NULL) {
                Compra aux;
                while (fread(&aux, sizeof(Compra), 1, p) == 1) {
                    if (aux.idCompra == idCompra) {
                        repetido = true;
                        break;
                    }
                }
                fclose(p);
            }

            if (repetido) {
                cout << "Error: el ID " << idCompra
                     << " ya esta asignado a otra compra.\n";
                continue;
            }

            break;
        }
        cout << "Error: el ID de compra debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "ID proveedor: ";
        if (cin >> idProveedor) break;
        cout << "Error: el ID de proveedor debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "ID empleado: ";
        if (cin >> idEmpleado) break;
        cout << "Error: el ID de empleado debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Fecha de compra:\n";
    fecha.Cargar();

    while (true) {
        cout << "Total: ";
        if (cin >> total) break;
        cout << "Error: el total debe ser numerico. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Compra::Mostrar() const{
    cout<<"Compra#"<<idCompra
        <<" | Prov: "<<idProveedor
        <<" | Emp: "<<idEmpleado
        <<" | Fecha: "; fecha.Mostrar();
    cout<<" | Total: $"<<total<<"\n";
}
