// Fecha.cpp
#include <iostream>  // iostream (pedido)
using namespace std; // using (pedido)
#include "Fecha.h"


Fecha::Fecha(int d, int m, int a){ dia=d; mes=m; anio=a; }
void Fecha::Cargar(){ cout<<"Dia: ";cin>>dia; cout<<"Mes: ";cin>>mes; cout<<"Anio: ";cin>>anio; }
void Fecha::Mostrar() const{ cout<<dia<<"/"<<mes<<"/"<<anio; }

int  Fecha::getDia()  const{ return dia; }
int  Fecha::getMes()  const{ return mes; }
int  Fecha::getAnio() const{ return anio; }
void Fecha::setDia(int d){ dia=d; }
void Fecha::setMes(int m){ mes=m; }
void Fecha::setAnio(int a){ anio=a; }
