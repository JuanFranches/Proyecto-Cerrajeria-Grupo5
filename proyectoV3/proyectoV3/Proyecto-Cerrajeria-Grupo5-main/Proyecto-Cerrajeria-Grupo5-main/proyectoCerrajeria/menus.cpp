// menus.cpp
// -----------------------------------------------------------------------------
// Capa de MENÚS + PERSISTENCIA EN ARCHIVOS BINARIOS (.dat) para TODOS los módulos.
// SOLO lo visto en clase: iostream + FILE* + fopen/fread/fwrite/fseek/ftell.
// Sin STL, sin string. Lectura/Escritura de registros completos (sizeof Clase).
// -----------------------------------------------------------------------------

#include <iostream>   // cout, cin
using namespace std;  // std::cout -> cout
#include <cstdio>     // FILE*, fopen, fread, fwrite, fseek, ftell

// Incluimos TODAS las clases porque vamos a leer/escribir registros de estas en .dat
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

// -----------------------------------------------------------------------------
// RUTAS DE ARCHIVO (una por módulo). Binarios .dat según Unidad de Archivos.
// -----------------------------------------------------------------------------
const char* RUTA_PRODUCTOS       = "productos.dat";
const char* RUTA_PROVEEDORES     = "proveedores.dat";
const char* RUTA_CLIENTES        = "clientes.dat";
const char* RUTA_EMPLEADOS       = "empleados.dat";
const char* RUTA_SERVICIOS       = "servicios.dat";
const char* RUTA_COMPRAS         = "compras.dat";          // cabecera
const char* RUTA_DET_COMPRAS     = "detalles_compra.dat";  // detalle
const char* RUTA_PEDIDOS         = "pedidos.dat";          // cabecera
const char* RUTA_DET_PEDIDOS     = "detalles_pedido.dat";  // detalle

// -----------------------------------------------------------------------------
// PROTOTIPOS INTERNOS (solo visibles en este .cpp)
// -----------------------------------------------------------------------------
static void pausa();
static void limpiarEntrada();

// Submenús
static void menuProductos();
static void menuProveedores();
static void menuClientes();
static void menuEmpleados();
static void menuServicios();
static void menuCompras();
static void menuDetalleCompras();
static void menuPedidos();
static void menuDetallePedidos();

// Operaciones de archivo (Alta = append, Listado = recorrer todo el archivo)
static void altaProducto();
static void listarProductos();

static void altaProveedor();
static void listarProveedores();

static void altaCliente();
static void listarClientes();

static void altaEmpleado();
static void listarEmpleados();

static void altaServicio();
static void listarServicios();

static void altaCompra();
static void listarCompras();

static void altaDetalleCompra();
static void listarDetalleCompras();

static void altaPedido();
static void listarPedidos();

static void altaDetallePedido();
static void listarDetallePedidos();

// =========================== MENU PRINCIPAL =================================
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

// ================================ AUXILIARES ================================
static void pausa(){
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(); // Espera un ENTER
}
static void limpiarEntrada(){
    cin.ignore(); // Descarta el '\n' luego de leer enteros/floats
}

// ============================ SUBMENUS (GENÉRICO) ===========================
static void menuProductos(){
    int op;
    do{
        cout << "\n--- MODULO PRODUCTOS ---\n";
        cout << "1) Alta (guardar en archivo)\n";
        cout << "2) Listar (leer de archivo)\n";
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

static void menuProveedores(){
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

static void menuClientes(){
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

static void menuEmpleados(){
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

static void menuServicios(){
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

static void menuCompras(){
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

static void menuDetalleCompras(){
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

static void menuPedidos(){
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

static void menuDetallePedidos(){
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

// ============================ ARCHIVOS: PATRON ===============================
// Alta (append):
//   1) Crear objeto, llamar Cargar()
//   2) fopen(archivo, "ab")
//   3) fwrite(&obj, sizeof(obj), 1, archivo)
//   4) cerrar, mensaje
//
// Listar (leer todo):
//   1) fopen(archivo, "rb")
//   2) while (fread(&obj, sizeof(obj), 1, archivo) == 1) { obj.Mostrar(); }
//   3) cerrar

// ---------- Productos ----------
static void altaProducto(){
    Producto reg;                 // 1) Creo el registro
    cout << "\nALTA DE PRODUCTO\n";
    reg.Cargar();                 //    Cargo datos por teclado

    FILE* p = fopen(RUTA_PRODUCTOS, "ab");    // 2) Abrir para append binario
    if(p == NULL){ cout << "Error de apertura.\n"; pausa(); return; }

    fwrite(&reg, sizeof(Producto), 1, p);     // 3) Escribir 1 registro
    fclose(p);                                 // 4) Cerrar
    cout << "Producto guardado en archivo.\n";
    pausa();
}
static void listarProductos(){
    FILE* p = fopen(RUTA_PRODUCTOS, "rb");    // 1) Abrir lectura binaria
    cout << "\nLISTADO DE PRODUCTOS\n";
    if(p == NULL){ cout << "No hay archivo o error de apertura.\n"; pausa(); return; }

    Producto reg;                              // 2) Buffer de lectura
    int i = 0;
    while(fread(&reg, sizeof(Producto), 1, p) == 1){ // 3) Leer hasta EOF
        cout << "\n[Registro " << (++i) << "]\n";
        reg.Mostrar();
    }
    fclose(p);                                  // 4) Cerrar
    if(i==0) cout << "(archivo vacio)\n";
    pausa();
}

// ---------- Proveedores ----------
static void altaProveedor(){
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
static void listarProveedores(){
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

// ---------- Clientes ----------
static void altaCliente(){
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
static void listarClientes(){
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

// ---------- Empleados ----------
static void altaEmpleado(){
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
static void listarEmpleados(){
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

// ---------- Servicios ----------
static void altaServicio(){
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
static void listarServicios(){
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

// ---------- Compras (cabecera) ----------
static void altaCompra(){
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
static void listarCompras(){
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

// ---------- Detalle de compras ----------
static void altaDetalleCompra(){
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
static void listarDetalleCompras(){
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

// ---------- Pedidos (cabecera) ----------
static void altaPedido(){
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
static void listarPedidos(){
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

// ---------- Detalle de pedidos ----------
static void altaDetallePedido(){
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
static void listarDetallePedidos(){
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
