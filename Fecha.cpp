#include <iostream>
using namespace std;
#include "Fecha.h"
#include "rlutil.h"

Fecha::Fecha(int d, int m, int a){
    if(fechaValida(d,m,a)){
        dia=d; mes=m; anio=a;
    } else {
        dia = mes = anio = 0;
    }
}

bool Fecha::fechaValida(int d, int m, int a){
    if(a <= 0) return false;
    if(m < 1 || m > 12) return false;

    int diasPorMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(d < 1 || d > diasPorMes[m - 1]) return false;

    return true;
}

void Fecha::Cargar() {
    int d, m, a;

    while (true) {
        cout << "Dia: ";
        cin >> d;

        if (!cin.fail() && d >= 1 && d <= 31) {
            break;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Intente nuevamente.\n\n";
        rlutil::setColor(rlutil::WHITE);
    }

    while (true) {
        cout << "Mes: ";
        cin >> m;

        if (!cin.fail() && m >= 1 && m <= 12) {
            break;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Intente nuevamente.\n\n";
        rlutil::setColor(rlutil::WHITE);
    }

    while (true) {
        cout << "Anio: ";
        cin >> a;

        if (!cin.fail() && a > 0) {
            break;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Intente nuevamente.\n\n";
        rlutil::setColor(rlutil::WHITE);
    }

    if (!fechaValida(d, m, a)) {
        cout << "\nFecha invalida. Reingrese todo.\n\n";
        Cargar();
        return;
    }

    dia = d;
    mes = m;
    anio = a;
}


void Fecha::Mostrar() const{
    cout << dia << "/" << mes << "/" << anio;
}

int Fecha::getDia() const{ return dia; }
int Fecha::getMes() const{ return mes; }
int Fecha::getAnio() const{ return anio; }

void Fecha::setDia(int d){
    if(fechaValida(d, mes, anio)) dia = d;
}

void Fecha::setMes(int m){
    if(fechaValida(dia, m, anio)) mes = m;
}

void Fecha::setAnio(int a){
    if(fechaValida(dia, mes, a)) anio = a;
}
