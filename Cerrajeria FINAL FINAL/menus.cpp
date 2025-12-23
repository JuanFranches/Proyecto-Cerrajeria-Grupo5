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
                cout << "Opcion invalida.\n";
                pausa();
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
                gProductoManager.altaProducto();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                gProductoManager.listarProductos();
                pausa();
                rlutil::cls();
                break;

            case 3: {
                cout << "Ingrese ID del producto a dar de baja: ";
                int id = leerOpcion();

                bool ok = gProductoManager.bajaProducto(id);

                if (ok) {
                    cout << "Producto dado de baja correctamente.\n";
                } else {
                    cout << "No se encontro un producto con ese ID.\n";
                }
                pausa();
                rlutil::cls();
                break;
            }

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
                gProveedorManager.altaProveedor();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                gProveedorManager.listarProveedores();
                pausa();
                rlutil::cls();
                break;

            case 3: {
                cout << "Ingrese ID del proveedor a dar de baja: ";
                int id = leerOpcion();
                bool ok = gProveedorManager.bajaProveedor(id);

                if (ok) {
                    cout << "Proveedor dado de baja correctamente.\n";
                } else {
                    cout << "No se encontro un proveedor con ese ID.\n";
                }
                pausa();
                rlutil::cls();
                break;
            }

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
                gClienteManager.altaCliente();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                gClienteManager.listarClientes();
                pausa();
                rlutil::cls();
                break;

            case 3: {
                cout << "Ingrese ID del cliente a dar de baja: ";
                int id = leerOpcion();

                bool ok = gClienteManager.bajaCliente(id);

                if (ok) {
                    cout << "Cliente dado de baja correctamente.\n";
                } else {
                    cout << "No se encontro un cliente con ese ID.\n";
                }
                pausa();
                rlutil::cls();
                break;
            }

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
                gEmpleadoManager.altaEmpleado();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                gEmpleadoManager.listarEmpleados();
                pausa();
                rlutil::cls();
                break;

            case 3: {
                cout << "Ingrese ID del empleado a dar de baja: ";
                int id = leerOpcion();

                bool ok = gEmpleadoManager.bajaEmpleado(id);

                if (ok) {
                    cout << "Empleado dado de baja correctamente.\n";
                } else {
                    cout << "No se encontro un empleado con ese ID.\n";
                }
                pausa();
                rlutil::cls();
                break;
            }

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

                gServicioManager.altaServicio();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                gServicioManager.listarServicios();
                pausa();
                rlutil::cls();
                break;

            case 3: {
                cout << "Ingrese ID del servicio a dar de baja: ";
                int id = leerOpcion();

                bool ok = gServicioManager.bajaServicio(id);
                if (ok) cout << "Servicio dado de baja correctamente.\n";
                else   cout << "No se encontro un servicio con ese ID.\n";

                pausa();
                rlutil::cls();
                break;
            }

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
                gCompraManager.altaCompra();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                gCompraManager.listarCompras();
                pausa();
                rlutil::cls();
                break;

            case 3: {
                cout << "Ingrese ID de la compra a dar de baja: ";
                int id = leerOpcion();

                if (gCompraManager.bajaCompra(id)) {
                    cout << "Compra dada de baja correctamente.\n";
                } else {
                    cout << "No se encontro una compra con ese ID.\n";
                }

                pausa();
                rlutil::cls();
                break;
            }

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
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
                cout << "Opcion invalida.\n";
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
                gVentaManager.altaVenta();
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                gVentaManager.listarVentas();
                pausa();
                rlutil::cls();
                break;

            case 3: {
                cout << "Ingrese ID de la venta a dar de baja: ";
                int id = leerOpcion();

                if (gVentaManager.bajaVenta(id)) {
                    cout << "Venta dada de baja correctamente.\n";
                } else {
                    cout << "No se encontro una venta con ese ID.\n";
                }
                pausa();
                break;
            }

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
                pausa();
                rlutil::cls();
                break;
        }

    } while (opcion != 0);
}
