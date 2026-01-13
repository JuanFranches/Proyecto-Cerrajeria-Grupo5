#include <iostream>
using namespace std;

#include "ProductoManager.h"
#include "ProveedorManager.h"
#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "ServicioManager.h"
#include "CompraManager.h"
#include "menus.h"
#include "InformeManager.h"
#include "VentaManager.h"
#include "InformeVentasManager.h"
#include "rlutil.h"

void pausa();
void limpiarEntrada();

void menuProductos();
void menuProveedores();
void menuClientes();
void menuEmpleados();
void menuServicios();
void menuCompras();

ProductoManager   gProductoManager;
ProveedorManager  gProveedorManager;
ClienteManager    gClienteManager;
EmpleadoManager   gEmpleadoManager;
ServicioManager   gServicioManager;
CompraManager     gCompraManager;
VentaManager      gVentaManager;
InformeManager    gInformeManager;
InformeVentasManager  gInformeVentasManager;

int leerOpcion() {
    int op;

    while (true) {
        cin >> op;

        if (!cin.fail()) {
            cin.ignore(1000, '\n');
            return op;
        }


        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. Debe ingresar un numero: ";
    }
}

void mensajeErrorFondo(const char* msg) {
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::WHITE);

    cout << " " << msg << " ";

    rlutil::setBackgroundColor(rlutil::BLACK);
    cout << "\n";
}

void menuPrincipal() {
    int opcion;

    do {
        rlutil::cls();
        cout << "\n=========== MENU PRINCIPAL ===========\n";
        cout << "1) Productos\n";
        cout << "2) Proveedores\n";
        cout << "3) Clientes\n";
        cout << "4) Empleados\n";
        cout << "5) Servicios\n";
        cout << "6) Compras\n";
        cout << "7) Ventas\n";
        cout << "8) Informes\n";
        cout << "0) Salir\n";
        cout << "Opcion: ";

        opcion = leerOpcion();
        rlutil::cls();

        switch (opcion) {
            case 1: menuProductos();   break;
            case 2: menuProveedores(); break;
            case 3: menuClientes();    break;
            case 4: menuEmpleados();   break;
            case 5: menuServicios();   break;
            case 6: menuCompras();     break;
            case 7: menuVentas();      break;
            case 8: menuInformes();    break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                mensajeErrorFondo("OPCION INVALIDA");
                pausa();
                rlutil::cls();
                break;
        }
    } while (opcion != 0);
}

void pausa(){
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
}

void limpiarEntrada(){
    cin.ignore();
}

void menuProductos() {
    int opcion;

    do {
        cout << "\n--- MENU PRODUCTOS ---\n";
        cout << "1) Alta producto\n";
        cout << "2) Listar productos\n";
        cout << "3) Baja de producto\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                rlutil::cls();
                gProductoManager.altaProducto();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                rlutil::cls();
                gProductoManager.listarProductos();
                pausa();
                rlutil::cls();
                break;

            case 3: {

                rlutil::cls();
                gProductoManager.listarProductos();

                int id;
                cout << "\nIngrese ID del producto a dar de baja: ";
                cin >> id;
                limpiarEntrada();

                if (gProductoManager.bajaProducto(id)) {
                        rlutil::setColor(rlutil::GREEN);
                    cout << "Producto dado de baja correctamente.\n";
                        rlutil::setColor(rlutil::WHITE);
                } else {
                        rlutil::setColor(rlutil::RED);
                    cout << "Producto no encontrado o ya eliminado.\n";
                        rlutil::setColor(rlutil::WHITE);
                }

                pausa();
                rlutil::cls();
                break;
            }

            case 0:

                break;

            default:
                rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida. Intente nuevamente.\n";
                rlutil::setColor(rlutil::WHITE);
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}

void menuProveedores() {
    int opcion;

    do {
        cout << "\n--- MENU PROVEEDORES ---\n";
        cout << "1) Alta proveedor\n";
        cout << "2) Listar proveedores\n";
        cout << "3) Baja de proveedor\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                rlutil::cls();
                gProveedorManager.altaProveedor();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                rlutil::cls();
                gProveedorManager.listarProveedores();
                pausa();
                rlutil::cls();
                break;

            case 3: {

                rlutil::cls();
                gProveedorManager.listarProveedores();

                int id;
                cout << "\nIngrese ID del Proveedor a dar de baja: ";
                cin >> id;
                limpiarEntrada();

                if (gProveedorManager.bajaProveedor(id)) {
                        rlutil::setColor(rlutil::GREEN);
                    cout << "Proveedor dado de baja correctamente.\n";
                        rlutil::setColor(rlutil::WHITE);
                } else {
                        rlutil::setColor(rlutil::RED);
                    cout << "Proveedor no encontrado o ya eliminado.\n";
                        rlutil::setColor(rlutil::WHITE);
                }

                pausa();
                rlutil::cls();
                break;
            }

            case 0:

                break;

            default:
                rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida. Intente nuevamente.\n";
                rlutil::setColor(rlutil::WHITE);
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}


void menuClientes() {
    int opcion;

    do {
        cout << "\n--- MENU CLIENTES ---\n";
        cout << "1) Alta cliente\n";
        cout << "2) Listar clientes\n";
        cout << "3) Baja de cliente\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";

        opcion = leerOpcion();
        switch (opcion) {
            case 1:
                rlutil::cls();
                gClienteManager.altaCliente();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                rlutil::cls();
                gClienteManager.listarClientes();
                pausa();
                rlutil::cls();
                break;

            case 3: {
                rlutil::cls();
                gClienteManager.listarClientes();

                int id;
                cout << "\nIngrese ID del cliente a dar de baja: ";
                cin >> id;
                limpiarEntrada();

                if (gClienteManager.bajaCliente(id)) {
                        rlutil::setColor(rlutil::GREEN);
                    cout << "Cliente dado de baja correctamente.\n";
                        rlutil::setColor(rlutil::WHITE);
                } else {
                        rlutil::setColor(rlutil::RED);
                    cout << "Cliente no encontrado o ya eliminado.\n";
                        rlutil::setColor(rlutil::WHITE);
                }

                pausa();
                rlutil::cls();
                break;
            }

            case 0:

                break;

            default:
                    rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida. Intente nuevamente.\n";
                    rlutil::setColor(rlutil::WHITE);
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}


void menuEmpleados() {
    int opcion;

    do {
        cout << "\n--- MENU EMPLEADOS ---\n";
        cout << "1) Alta empleado\n";
        cout << "2) Listar empleados\n";
        cout << "3) Baja de empleado\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                rlutil::cls();
                gEmpleadoManager.altaEmpleado();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                rlutil::cls();
                gEmpleadoManager.listarEmpleados();
                pausa();
                rlutil::cls();
                break;

            case 3: {

                rlutil::cls();
                gEmpleadoManager.listarEmpleados();

                int id;
                cout << "\nIngrese ID del Empleado a dar de baja: ";
                cin >> id;
                limpiarEntrada();

                if (gEmpleadoManager.bajaEmpleado(id)) {
                        rlutil::setColor(rlutil::GREEN);
                    cout << "Empleado dado de baja correctamente.\n";
                        rlutil::setColor(rlutil::WHITE);
                } else {
                        rlutil::setColor(rlutil::RED);
                    cout << "Empleado no encontrado o ya eliminado.\n";
                        rlutil::setColor(rlutil::WHITE);
                }

                pausa();
                rlutil::cls();
                break;
            }

            case 0:

                break;

            default:
                    rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida. Intente nuevamente.\n";
                    rlutil::setColor(rlutil::WHITE);
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}


void menuServicios() {
    int opcion;

    do {
        cout << "\n--- MENU SERVICIOS ---\n";
        cout << "1) Alta servicio\n";
        cout << "2) Listar servicios\n";
        cout << "3) Baja de servicio\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                rlutil::cls();
                gServicioManager.altaServicio();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                rlutil::cls();
                gServicioManager.listarServicios();
                pausa();
                rlutil::cls();
                break;

            case 3: {

                rlutil::cls();
                gServicioManager.listarServicios();

                int id;
                cout << "\nIngrese ID del Servicio a dar de baja: ";
                cin >> id;
                limpiarEntrada();

                if (gServicioManager.bajaServicio(id)) {
                        rlutil::setColor(rlutil::GREEN);
                    cout << "Servicio dado de baja correctamente.\n";
                        rlutil::setColor(rlutil::WHITE);
                } else {
                        rlutil::setColor(rlutil::RED);
                    cout << "Servicio no encontrado o ya eliminado.\n";
                        rlutil::setColor(rlutil::WHITE);
                }

                pausa();
                rlutil::cls();
                break;
            }

            case 0:

                break;

            default:
                    rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida. Intente nuevamente.\n";
                    rlutil::setColor(rlutil::WHITE);
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}


void menuCompras() {
    int opcion;

    do {
        cout << "\n--- MENU COMPRAS ---\n";
        cout << "1) Alta compra\n";
        cout << "2) Listar compras\n";
        cout << "3) Baja de compra\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                rlutil::cls();
                gCompraManager.altaCompra();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                rlutil::cls();
                gCompraManager.listarCompras();
                pausa();
                rlutil::cls();
                break;

            case 3: {

                rlutil::cls();
                gCompraManager.listarCompras();

                int id;
                cout << "\nIngrese ID de la Compra a dar de baja: ";
                cin >> id;
                limpiarEntrada();

                if (gCompraManager.bajaCompra(id)) {
                        rlutil::setColor(rlutil::GREEN);
                    cout << "Compra dada de baja correctamente.\n";
                        rlutil::setColor(rlutil::WHITE);
                } else {
                        rlutil::setColor(rlutil::RED);
                    cout << "Compra no encontrada o ya eliminada.\n";
                        rlutil::setColor(rlutil::WHITE);
                }

                pausa();
                rlutil::cls();
                break;
            }

            case 0:
                break;

            default:
                rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida. Intente nuevamente.\n";
                rlutil::setColor(rlutil::WHITE);
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}
void menuInformes() {
    int opcion;

    do {
        cout << "\n--- MENU DE INFORMES ---\n";
        cout << "1) Facturacion de COMPRAS en un periodo\n";
        cout << "2) Facturacion de un PROVEEDOR (compras) en un periodo\n";
        cout << "3) Facturacion TOTAL de COMPRAS\n";
        cout << "----------------------------------------\n";
        cout << "4) Facturacion de VENTAS en un periodo\n";
        cout << "5) Facturacion de un CLIENTE (ventas) en un periodo\n";
        cout << "6) Facturacion TOTAL de VENTAS\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";

        opcion = leerOpcion();

        switch (opcion) {

            case 1:
                gInformeManager.informeFacturacionPorPeriodo();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                gInformeManager.informeFacturacionProveedorPorPeriodo();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 3:
                gInformeManager.informeFacturacionTotal();
                rlutil::anykey();
                rlutil::cls();
                break;


            case 4:
                gInformeVentasManager.informeFacturacionVentasPorPeriodo();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 5:
                gInformeVentasManager.informeFacturacionClientePorPeriodo();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 6:
                gInformeVentasManager.informeFacturacionVentasTotal();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}

void menuVentas() {
    int opcion;

    do {
        cout << "\n--- MENU VENTAS ---\n";
        cout << "1) Alta venta\n";
        cout << "2) Listar ventas\n";
        cout << "3) Baja de venta\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                rlutil::cls();
                gVentaManager.altaVenta();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                rlutil::cls();
                gVentaManager.listarVentas();
                pausa();
                rlutil::cls();
                break;

            case 3: {

                rlutil::cls();
                gVentaManager.listarVentas();

                int id;
                cout << "\nIngrese ID de la Ventas a dar de baja: ";
                cin >> id;
                limpiarEntrada();

                if (gVentaManager.bajaVenta(id)) {
                        rlutil::setColor(rlutil::GREEN);
                    cout << "Venta dada de baja correctamente.\n";
                        rlutil::setColor(rlutil::WHITE);
                } else {
                        rlutil::setColor(rlutil::RED);
                    cout << "Venta no encontrada o ya eliminada.\n";
                        rlutil::setColor(rlutil::WHITE);
                }

                pausa();
                rlutil::cls();
                break;
            }

            case 0:
                break;

            default:
                rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida. Intente nuevamente.\n";
                rlutil::setColor(rlutil::WHITE);
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}
