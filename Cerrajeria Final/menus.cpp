#include <iostream>
using namespace std;

#include "ProductoManager.h"
#include "ProveedorManager.h"
#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "ServicioManager.h"
#include "CompraManager.h"
#include "menus.h"

void pausa();
void limpiarEntrada();

void menuProductos();
void menuProveedores();
void menuClientes();
void menuEmpleados();
void menuServicios();
void menuCompras();

ProductoManager       gProductoManager;
ProveedorManager      gProveedorManager;
ClienteManager        gClienteManager;
EmpleadoManager       gEmpleadoManager;
ServicioManager       gServicioManager;
CompraManager         gCompraManager;

void menuPrincipal(){
    int opcion;
    do{
        cout << "\n=========== SISTEMA DE GESTION DE CERRAJERIA ===========\n";
        cout << "1) Productos\n";
        cout << "2) Proveedores\n";
        cout << "3) Clientes\n";
        cout << "4) Empleados\n";
        cout << "5) Servicios\n";
        cout << "6) Compras\n";
        cout << "0) Salir\n";
        cout << "Opcion: ";
        cin >> opcion; limpiarEntrada();

        switch(opcion){
            case 1: menuProductos();       break;
            case 2: menuProveedores();     break;
            case 3: menuClientes();        break;
            case 4: menuEmpleados();       break;
            case 5: menuServicios();       break;
            case 6: menuCompras();         break;
            case 0: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(opcion != 0);
}

void pausa(){
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
}
void limpiarEntrada(){
    cin.ignore();
}

void menuProductos(){
    int op;
    do{
        cout << "\n--- MODULO PRODUCTOS ---\n";
        cout << "1) Alta \n";
        cout << "2) Listar \n";
        cout << "3) Baja \n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: gProductoManager.altaProducto();    pausa(); break;
            case 2: gProductoManager.listarProductos(); pausa(); break;
            case 3: {
                    int id;
                    cout << "Ingrese ID del Producto a dar de baja: ";
                    cin >> id;
                    limpiarEntrada();

                        if (gProductoManager.bajaProducto(id)) {
                        cout << "Productos eliminado correctamente.\n";
                            } else {
                            cout << "Producto no encontrado o ya eliminado.\n";
        }
        pausa();
        break;
    }
            case 0:                                    break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}

void menuProveedores(){
    int op;
    do{
        cout << "\n--- MODULO PROVEEDORES ---\n";
        cout << "1) Alta\n";
        cout << "2) Listar\n";
        cout << "3) Baja\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: gProveedorManager.altaProveedor();     pausa(); break;
            case 2: gProveedorManager.listarProveedores(); pausa(); break;
            case 3: {
                    int id;
                    cout << "Ingrese ID del proveedor a dar de baja: ";
                    cin >> id;
                    limpiarEntrada();

                        if (gProveedorManager.bajaProveedor(id)) {
                        cout << "Proveedor eliminado correctamente.\n";
                            } else {
                            cout << "Proveedor no encontrado o ya eliminado.\n";
        }
        pausa();
        break;
    }
            case 0:                                      break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}

void menuClientes(){
    int op;
    do{
        cout << "\n--- MODULO CLIENTES ---\n";
        cout << "1) Alta\n";
        cout << "2) Listar\n";
        cout << "3) Baja\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: gClienteManager.altaCliente();    pausa(); break;
            case 2: gClienteManager.listarClientes(); pausa(); break;
            case 3: {
                    int id;
                    cout << "Ingrese ID del Cliente a dar de baja: ";
                    cin >> id;
                    limpiarEntrada();

                        if (gClienteManager.bajaCliente(id)) {
                        cout << "Cliente eliminado correctamente.\n";
                            } else {
                            cout << "Cliente no encontrado o ya eliminado.\n";
        }
        pausa();
        break;
    }
            case 0:                                  break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}

void menuEmpleados(){
    int op;
    do{
        cout << "\n--- MODULO EMPLEADOS ---\n";
        cout << "1) Alta\n";
        cout << "2) Listar\n";
        cout << "3) Baja\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: gEmpleadoManager.altaEmpleado();    pausa(); break;
            case 2: gEmpleadoManager.listarEmpleados(); pausa(); break;
            case 3: {
                    int id;
                    cout << "Ingrese ID del Empleado a dar de baja: ";
                    cin >> id;
                    limpiarEntrada();

                        if (gEmpleadoManager.bajaEmpleado(id)) {
                        cout << "Empleado eliminado correctamente.\n";
                            } else {
                            cout << "Empleado no encontrado o ya eliminado.\n";
        }
        pausa();
        break;
    }
            case 0:                                    break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}

void menuServicios(){
    int op;
    do{
        cout << "\n--- MODULO SERVICIOS ---\n";
        cout << "1) Alta\n";
        cout << "2) Listar\n";
        cout << "3) Baja\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: gServicioManager.altaServicio();    pausa(); break;
            case 2: gServicioManager.listarServicios(); pausa(); break;
            case 3: {
                    int id;
                    cout << "Ingrese ID del Servicio a dar de baja: ";
                    cin >> id;
                    limpiarEntrada();

                        if (gServicioManager.bajaServicio(id)) {
                        cout << "Servicio eliminado correctamente.\n";
                            } else {
                            cout << "Servicio no encontrado o ya eliminado.\n";
        }
        pausa();
        break;
    }
            case 0:                                   break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}

void menuCompras(){
    int op;
    do{
        cout << "\n--- MODULO COMPRAS (CABECERA) ---\n";
        cout << "1) Alta\n";
        cout << "2) Listar\n";
        cout << "3) Baja\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: gCompraManager.altaCompra();    pausa(); break;
            case 2: gCompraManager.listarCompras(); pausa(); break;
            case 3: {
                    int id;
                    cout << "Ingrese ID del Compra a dar de baja: ";
                    cin >> id;
                    limpiarEntrada();

                        if (gCompraManager.bajaCompra(id)) {
                        cout << "Compra eliminada correctamente.\n";
                            } else {
                            cout << "Compra no encontrada o ya eliminada.\n";
        }
        pausa();
        break;
    }
            case 0:                                break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}
