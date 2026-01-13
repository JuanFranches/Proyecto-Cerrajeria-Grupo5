#include <iostream>
using namespace std;

#include "InformeVentasManager.h"
#include "Venta.h"

InformeVentasManager::InformeVentasManager()
    : _archivoVentas("ventas.dat")
{
}


int InformeVentasManager::compararFechas(const Fecha& a, const Fecha& b) const {
    if (a.getAnio() < b.getAnio()) return -1;
    if (a.getAnio() > b.getAnio()) return 1;

    if (a.getMes() < b.getMes()) return -1;
    if (a.getMes() > b.getMes()) return 1;

    if (a.getDia() < b.getDia()) return -1;
    if (a.getDia() > b.getDia()) return 1;

    return 0;
}

bool InformeVentasManager::estaEnRango(const Fecha& f,
                                       const Fecha& desde,
                                       const Fecha& hasta) const {
    return compararFechas(f, desde) >= 0 &&
           compararFechas(f, hasta) <= 0;
}


void InformeVentasManager::informeFacturacionVentasPorPeriodo() {
    Fecha desde, hasta;

    cout << "\nINFORME: FACTURACION DE VENTAS EN UN PERIODO\n\n";

    cout << "Ingrese FECHA DESDE:\n";
    desde.Cargar();

    cout << "Ingrese FECHA HASTA:\n";
    hasta.Cargar();

    int   cant = _archivoVentas.getCantidadRegistros();
    float totalPeriodo = 0.0f;

    for (int i = 0; i < cant; i++) {
        Venta reg = _archivoVentas.leer(i);

        if (reg.getEliminado()) continue;

        if (estaEnRango(reg.getFecha(), desde, hasta)) {
            totalPeriodo += reg.getTotal();
        }
    }

    cout << "\nFACTURACION DE VENTAS DESDE ";
    desde.Mostrar();
    cout << "HASTA ";
    hasta.Mostrar();
    cout << "TOTAL: $" << totalPeriodo << "\n\n";
}


void InformeVentasManager::informeFacturacionClientePorPeriodo() {
    Fecha desde, hasta;
    int   idCliente;

    cout << "\nINFORME: FACTURACION DE UN CLIENTE EN UN PERIODO\n\n";

    cout << "Ingrese ID de cliente: ";
    cin >> idCliente;

    cout << "Ingrese FECHA DESDE:\n";
    desde.Cargar();

    cout << "Ingrese FECHA HASTA:\n";
    hasta.Cargar();

    int   cant = _archivoVentas.getCantidadRegistros();
    float totalPeriodo = 0.0f;

    for (int i = 0; i < cant; i++) {
        Venta reg = _archivoVentas.leer(i);

        if (reg.getEliminado()) continue;

        if (reg.getIdCliente() == idCliente &&
            estaEnRango(reg.getFecha(), desde, hasta)) {
            totalPeriodo += reg.getTotal();
        }
    }

    cout << "\nFACTURACION DEL CLIENTE " << idCliente << " DESDE ";
    desde.Mostrar();
    cout << "HASTA ";
    hasta.Mostrar();
    cout << "TOTAL: $" << totalPeriodo << "\n\n";
}


void InformeVentasManager::informeFacturacionVentasTotal() {
    cout << "\nINFORME: FACTURACION TOTAL DE VENTAS\n\n";

    int   cant = _archivoVentas.getCantidadRegistros();
    float totalGeneral = 0.0f;

    for (int i = 0; i < cant; i++) {
        Venta reg = _archivoVentas.leer(i);

        if (reg.getEliminado()) continue;

        totalGeneral += reg.getTotal();
    }

    cout << "FACTURACION TOTAL (ventas no dadas de baja): $"
         << totalGeneral << "\n\n";
}
