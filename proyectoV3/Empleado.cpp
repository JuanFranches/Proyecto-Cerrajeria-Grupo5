// Empleado.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include "Empleado.h"

Empleado::Empleado(){
    idEmpleado=0; nombre[0]='\0'; apellido[0]='\0'; cargo[0]='\0';
    sueldo=0; fechaIngreso=Fecha(1,1,2000); eliminado=false;
}
void Empleado::Cargar(){
    cout<<"ID empleado: ";cin>>idEmpleado; cin.ignore();
    cout<<"Nombre: ";cin.getline(nombre,30);
    cout<<"Apellido: ";cin.getline(apellido,30);
    cout<<"Cargo: ";cin.getline(cargo,30);
    cout<<"Sueldo: ";cin>>sueldo;
    cout<<"Fecha ingreso:\n"; fechaIngreso.Cargar();
    eliminado=false;
}
void Empleado::Mostrar() const{
    if(eliminado){ cout<<"(Empleado eliminado)\n"; return; }
    cout<<"Emp#"<<idEmpleado<<" - "<<apellido<<", "<<nombre
        <<" | Cargo: "<<cargo
        <<" | Sueldo: $"<<sueldo
        <<" | Ingreso: "; fechaIngreso.Mostrar(); cout<<"\n";
}
