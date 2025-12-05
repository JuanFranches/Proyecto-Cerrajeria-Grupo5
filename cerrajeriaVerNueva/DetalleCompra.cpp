#include <iostream>
#include <limits>
using namespace std;
#include "DetalleCompra.h"

DetalleCompra::DetalleCompra(){
    idCompra=0; idProducto=0; cantidad=0; precioUnitario=0; subtotal=0;
}

void DetalleCompra::Cargar(){
    while (true) {
        cout << "ID compra: ";
        if (cin >> idCompra) break;
        cout << "Error: el ID de compra debe ser un numero entero. Intentelo de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        cout << "ID producto: ";
        if (cin >> idProducto) break;
        cout << "Error: el ID de producto debe ser un numero entero. Intentelo de nuevo.\n";
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

void DetalleCompra::Mostrar() const{
    cout<<"Compra#"<<idCompra
        <<" | Prod: "<<idProducto
        <<" | Cant: "<<cantidad
        <<" | P.U.: $"<<precioUnitario
        <<" | Subtotal: $"<<subtotal<<"\n";
}
