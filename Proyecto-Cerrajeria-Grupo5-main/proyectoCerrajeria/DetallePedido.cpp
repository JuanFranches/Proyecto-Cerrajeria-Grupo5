#include <iostream>
#include <limits>
#include <cstdio>      // para FILE*, fopen, fread, fclose
using namespace std;
#include "DetallePedido.h"


DetallePedido::DetallePedido(){
    idPedido=0;
    tipoItem=1;
    idItem=0;
    cantidad=0;
    precioUnitario=0;
    subtotal=0;
}

void DetallePedido::Cargar(){

    // ID pedido: numérico y no repetido
    while (true) {
        cout << "ID pedido: ";
        if (cin >> idPedido) {
            // limpio el \n que queda en el buffer
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool repetido = false;

            FILE* p = fopen("detalles_pedido.dat", "rb");
            if (p != NULL) {
                DetallePedido aux;
                while (fread(&aux, sizeof(DetallePedido), 1, p) == 1) {
                    // como estamos dentro de la misma clase,
                    // podemos acceder a aux.idPedido aunque sea private
                    if (aux.idPedido == idPedido) {
                        repetido = true;
                        break;
                    }
                }
                fclose(p);
            }

            if (repetido) {
                cout << "Error: el ID de pedido " << idPedido
                     << " ya esta asignado a otro detalle.\n";
                continue;   // vuelve a pedir el ID
            }

            break;  // ID correcto → salimos del while
        }

        cout << "Error: el ID de pedido debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Tipo item (1=Producto, 2=Servicio): ";
        if (cin >> tipoItem && (tipoItem == 1 || tipoItem == 2)) break;
        cout << "Error: el tipo debe ser 1 (Producto) o 2 (Servicio). Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "ID item: ";
        if (cin >> idItem) break;
        cout << "Error: el ID de item debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Cantidad: ";
        if (cin >> cantidad) break;
        cout << "Error: la cantidad debe ser numerica. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Precio unitario: ";
        if (cin >> precioUnitario) break;
        cout << "Error: el precio unitario debe ser numerico. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    subtotal = cantidad * precioUnitario;
}

void DetallePedido::Mostrar() const{
    cout<<"Pedido#"<<idPedido
        <<" | Tipo: "<<(tipoItem==1?"Producto":"Servicio")
        <<" | ID item: "<<idItem
        <<" | Cant: "<<cantidad
        <<" | P.U.: $"<<precioUnitario
        <<" | Subtotal: $"<<subtotal<<"\n";
}
