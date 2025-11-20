#include <iostream>
#include <limits>      // 👈 agregar esto
using namespace std;
#include "Compra.h"


Compra::Compra(){ idCompra=0; idProveedor=0; idEmpleado=0; fecha=Fecha(1,1,2000); total=0; }
void Compra::Cargar(){
    // ID compra
    while (true) {
        cout << "ID compra: ";
        if (cin >> idCompra) break;
        cout << "Error: el ID de compra debe ser un numero entero. Intentelo de nuevo.\n";
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

    // ID empleado
    while (true) {
        cout << "ID empleado: ";
        if (cin >> idEmpleado) break;
        cout << "Error: el ID de empleado debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Fecha de compra:\n";
    fecha.Cargar();

    // Total
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
