#include <iostream>
using namespace std;
#include <cstdio>


#include "Fecha.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Servicio.h"
#include "Compra.h"
#include "DetalleCompra.h"
#include "PedidoCliente.h"
#include "DetallePedido.h"


const char* RUTA_PRODUCTOS       = "productos.dat";
const char* RUTA_PROVEEDORES     = "proveedores.dat";
const char* RUTA_CLIENTES        = "clientes.dat";
const char* RUTA_EMPLEADOS       = "empleados.dat";
const char* RUTA_SERVICIOS       = "servicios.dat";
const char* RUTA_COMPRAS         = "compras.dat";
const char* RUTA_DET_COMPRAS     = "detalles_compra.dat";
const char* RUTA_PEDIDOS         = "pedidos.dat";
const char* RUTA_DET_PEDIDOS     = "detalles_pedido.dat";


void pausa();
void limpiarEntrada();


void menuProductos();
void menuProveedores();
void menuClientes();
void menuEmpleados();
void menuServicios();
void menuCompras();
void menuDetalleCompras();
void menuPedidos();
void menuDetallePedidos();


void altaProducto();
void listarProductos();

void altaProveedor();
void listarProveedores();

void altaCliente();
void listarClientes();

void altaEmpleado();
void listarEmpleados();

void altaServicio();
void listarServicios();

void altaCompra();
void listarCompras();

void altaDetalleCompra();
void listarDetalleCompras();

void altaPedido();
void listarPedidos();

void altaDetallePedido();
void listarDetallePedidos();


void menuPrincipal(){
    int opcion;
    do{
        cout << "\n=========== SISTEMA DE GESTION DE CERRAJERIA ===========\n";
        cout << "1) Productos\n";
        cout << "2) Proveedores\n";
        cout << "3) Clientes\n";
        cout << "4) Empleados\n";
        cout << "5) Servicios\n";
        cout << "6) Compras (cabecera)\n";
        cout << "7) Detalle de compras\n";
        cout << "8) Pedidos de clientes (cabecera)\n";
        cout << "9) Detalle de pedidos\n";
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
            case 7: menuDetalleCompras();  break;
            case 8: menuPedidos();         break;
            case 9: menuDetallePedidos();  break;
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
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaProducto();    break;
            case 2: listarProductos(); break;
            case 0:                    break;
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
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaProveedor();     break;
            case 2: listarProveedores(); break;
            case 0:                       break;
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
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaCliente();   break;
            case 2: listarClientes();break;
            case 0:                   break;
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
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaEmpleado();    break;
            case 2: listarEmpleados(); break;
            case 0:                      break;
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
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaServicio();    break;
            case 2: listarServicios(); break;
            case 0:                      break;
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
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaCompra();   break;
            case 2: listarCompras();break;
            case 0:                   break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}

void menuDetalleCompras(){
    int op;
    do{
        cout << "\n--- MODULO DETALLE DE COMPRAS ---\n";
        cout << "1) Alta\n";
        cout << "2) Listar\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaDetalleCompra();    break;
            case 2: listarDetalleCompras(); break;
            case 0:                           break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}

void menuPedidos(){
    int op;
    do{
        cout << "\n--- MODULO PEDIDOS (CABECERA) ---\n";
        cout << "1) Alta\n";
        cout << "2) Listar\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaPedido();   break;
            case 2: listarPedidos();break;
            case 0:                   break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}

void menuDetallePedidos(){
    int op;
    do{
        cout << "\n--- MODULO DETALLE DE PEDIDOS ---\n";
        cout << "1) Alta\n";
        cout << "2) Listar\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> op; limpiarEntrada();

        switch(op){
            case 1: altaDetallePedido();   break;
            case 2: listarDetallePedidos();break;
            case 0:                          break;
            default: cout << "Opcion invalida.\n"; pausa(); break;
        }
    } while(op != 0);
}



void altaProducto(){
    Producto reg;
    cout << "\nALTA DE PRODUCTO\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_PRODUCTOS, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    cout << "Producto guardado en archivo.\n";
    pausa();
}
void listarProductos(){
    FILE* p = fopen(RUTA_PRODUCTOS, "rb");
    cout << "\nLISTADO DE PRODUCTOS\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    Producto reg;
    int i = 0;
    while(fread(&reg, sizeof(Producto), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}


void altaProveedor(){
    Proveedor reg;
    cout << "\nALTA DE PROVEEDOR\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_PROVEEDORES, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    cout << "Proveedor guardado en archivo.\n";
    pausa();
}
void listarProveedores(){
    FILE* p = fopen(RUTA_PROVEEDORES, "rb");
    cout << "\nLISTADO DE PROVEEDORES\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    Proveedor reg;
    int i=0;
    while(fread(&reg, sizeof(Proveedor), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}


void altaCliente(){
    Cliente reg;
    cout << "\nALTA DE CLIENTE\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_CLIENTES, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    cout << "Cliente guardado en archivo.\n";
    pausa();
}
void listarClientes(){
    FILE* p = fopen(RUTA_CLIENTES, "rb");
    cout << "\nLISTADO DE CLIENTES\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    Cliente reg;
    int i=0;
    while(fread(&reg, sizeof(Cliente), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}


void altaEmpleado(){
    Empleado reg;
    cout << "\nALTA DE EMPLEADO\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_EMPLEADOS, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    cout << "Empleado guardado en archivo.\n";
    pausa();
}
void listarEmpleados(){
    FILE* p = fopen(RUTA_EMPLEADOS, "rb");
    cout << "\nLISTADO DE EMPLEADOS\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    Empleado reg;
    int i=0;
    while(fread(&reg, sizeof(Empleado), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}


void altaServicio(){
    Servicio reg;
    cout << "\nALTA DE SERVICIO\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_SERVICIOS, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(Servicio), 1, p);
    fclose(p);
    cout << "Servicio guardado en archivo.\n";
    pausa();
}
void listarServicios(){
    FILE* p = fopen(RUTA_SERVICIOS, "rb");
    cout << "\nLISTADO DE SERVICIOS\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    Servicio reg;
    int i=0;
    while(fread(&reg, sizeof(Servicio), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}


void altaCompra(){
    Compra reg;
    cout << "\nALTA DE COMPRA (CABECERA)\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_COMPRAS, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(Compra), 1, p);
    fclose(p);
    cout << "Compra guardada en archivo.\n";
    pausa();
}
void listarCompras(){
    FILE* p = fopen(RUTA_COMPRAS, "rb");
    cout << "\nLISTADO DE COMPRAS\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    Compra reg;
    int i=0;
    while(fread(&reg, sizeof(Compra), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}


void altaDetalleCompra(){
    DetalleCompra reg;
    cout << "\nALTA DE DETALLE DE COMPRA\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_DET_COMPRAS, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(DetalleCompra), 1, p);
    fclose(p);
    cout << "Detalle de compra guardado en archivo.\n";
    pausa();
}
void listarDetalleCompras(){
    FILE* p = fopen(RUTA_DET_COMPRAS, "rb");
    cout << "\nLISTADO DE DETALLES DE COMPRAS\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    DetalleCompra reg;
    int i=0;
    while(fread(&reg, sizeof(DetalleCompra), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}


void altaPedido(){
    PedidoCliente reg;
    cout << "\nALTA DE PEDIDO (CABECERA)\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_PEDIDOS, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(PedidoCliente), 1, p);
    fclose(p);
    cout << "Pedido guardado en archivo.\n";
    pausa();
}
void listarPedidos(){
    FILE* p = fopen(RUTA_PEDIDOS, "rb");
    cout << "\nLISTADO DE PEDIDOS\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    PedidoCliente reg;
    int i=0;
    while(fread(&reg, sizeof(PedidoCliente), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}


void altaDetallePedido(){
    DetallePedido reg;
    cout << "\nALTA DE DETALLE DE PEDIDO\n";
    reg.Cargar();

    FILE* p = fopen(RUTA_DET_PEDIDOS, "ab");
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(DetallePedido), 1, p);
    fclose(p);
    cout << "Detalle de pedido guardado en archivo.\n";
    pausa();
}
void listarDetallePedidos(){
    FILE* p = fopen(RUTA_DET_PEDIDOS, "rb");
    cout << "\nLISTADO DE DETALLES DE PEDIDOS\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    DetallePedido reg;
    int i=0;
    while(fread(&reg, sizeof(DetallePedido), 1, p) == 1){
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}
