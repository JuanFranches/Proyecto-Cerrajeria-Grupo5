#include <iostream>
using namespace std;

#include "InformeManager.h"
#include "Compra.h"

InformeManager::InformeManager()
    : _archivoCompras("compras.dat")
{
}


int InformeManager::compararFechas(const Fecha& a, const Fecha& b) const {
    if (a.getAnio() < b.getAnio()) return -1;
    if (a.getAnio() > b.getAnio()) return 1;

    if (a.getMes() < b.getMes()) return -1;
    if (a.getMes() > b.getMes()) return 1;

    if (a.getDia() < b.getDia()) return -1;
    if (a.getDia() > b.getDia()) return 1;

    return 0;
}

bool InformeManager::estaEnRango(const Fecha& f,
                                 const Fecha& desde,
                                 const Fecha& hasta) const {
    return compararFechas(f, desde) >= 0 &&
           compararFechas(f, hasta) <= 0;
}


void InformeManager::informeFacturacionPorPeriodo() {
    Fecha desde, hasta;

    cout << "\nINFORME: FACTURACION TOTAL EN UN PERIODO\n\n";

    cout << "Ingrese FECHA DESDE:\n";
    desde.Cargar();

    cout << "Ingrese FECHA HASTA:\n";
    hasta.Cargar();

    int   cant = _archivoCompras.getCantidadRegistros();
    float totalPeriodo = 0.0f;

    for (int i = 0; i < cant; i++) {
        Compra reg = _archivoCompras.leer(i);



        if (estaEnRango(reg.getFecha(), desde, hasta)) {
            totalPeriodo += reg.getTotal();
        }
    }

    cout << "\nFACTURACION TOTAL DESDE ";
    desde.Mostrar();
    cout << "HASTA ";
    hasta.Mostrar();
    cout << "TOTAL: $" << totalPeriodo << "\n\n";
}


void InformeManager::informeFacturacionProveedorPorPeriodo() {
    Fecha desde, hasta;
    int   idProv;

    cout << "\nINFORME: FACTURACION DE UN PROVEEDOR EN UN PERIODO\n\n";

    cout << "Ingrese ID de proveedor: ";
    cin >> idProv;

    cout << "Ingrese FECHA DESDE:\n";
    desde.Cargar();

    cout << "Ingrese FECHA HASTA:\n";
    hasta.Cargar();

    int   cant = _archivoCompras.getCantidadRegistros();
    float totalPeriodo = 0.0f;

    for (int i = 0; i < cant; i++) {
        Compra reg = _archivoCompras.leer(i);


        if (reg.getIdProveedor() == idProv &&
            estaEnRango(reg.getFecha(), desde, hasta)) {
            totalPeriodo += reg.getTotal();
        }
    }

    cout << "\nFACTURACION DEL PROVEEDOR " << idProv << " DESDE ";
    desde.Mostrar();
    cout << "HASTA ";
    hasta.Mostrar();
    cout << "TOTAL: $" << totalPeriodo << "\n\n";
}
void InformeManager::informeFacturacionTotal() {
    cout << "\nINFORME: FACTURACION TOTAL DE COMPRAS\n\n";

    int   cant = _archivoCompras.getCantidadRegistros();
    float totalGeneral = 0.0f;

    for (int i = 0; i < cant; i++) {
        Compra reg = _archivoCompras.leer(i);


        if (reg.getEliminado()) continue;

        totalGeneral += reg.getTotal();
    }

    cout << "FACTURACION TOTAL (compras no dadas de baja): $"
         << totalGeneral << "\n\n";
}
