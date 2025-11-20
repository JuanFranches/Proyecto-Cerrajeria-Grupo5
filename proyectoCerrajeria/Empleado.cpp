#include <iostream>
#include <limits>
using namespace std;
#include "Empleado.h"


Empleado::Empleado(){
    idEmpleado=0; nombre[0]='\0'; apellido[0]='\0'; cargo[0]='\0';
    sueldo=0; fechaIngreso=Fecha(1,1,2000); eliminado=false;
}
void Empleado::Cargar(){
    // ID con validación
    while (true) {
        cout << "ID empleado: ";
        if (cin >> idEmpleado) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        cout << "Error: el ID debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Nombre: ";    cin.getline(nombre,30);
    cout << "Apellido: ";  cin.getline(apellido,30);
    cout << "Cargo: ";     cin.getline(cargo,30);

    // Sueldo
    while (true) {
        cout << "Sueldo: ";
        if (cin >> sueldo) break;
        cout << "Error: el sueldo debe ser numerico. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Fecha ingreso:\n";
    fechaIngreso.Cargar();

    eliminado = false;
}

void Empleado::Mostrar() const{
    if(eliminado){ cout<<"(Empleado eliminado)\n"; return; }
    cout<<"Emp#"<<idEmpleado<<" - "<<apellido<<", "<<nombre
        <<" | Cargo: "<<cargo
        <<" | Sueldo: $"<<sueldo
        <<" | Ingreso: "; fechaIngreso.Mostrar(); cout<<"\n";
}
