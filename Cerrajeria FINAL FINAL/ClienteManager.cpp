#include <iostream>
using namespace std;
#include "ClienteManager.h"

ClienteManager::ClienteManager(){}

void ClienteManager::altaCliente(){
    Cliente reg;
    cout << "\nALTA DE CLIENTE\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Cliente guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void ClienteManager::listarClientes() {
    FILE* p = fopen("clientes.dat", "rb");
    if (p == NULL) {
        cout << "No hay Clientes cargados.\n";
        return;
    }

    Cliente reg;
    bool hayActivos = false;

    while (fread(&reg, sizeof(Cliente), 1, p) == 1) {
        if (!reg.getEliminado()) {
            reg.Mostrar();
            hayActivos = true;
        }
    }

    fclose(p);

    if (!hayActivos) {
        cout << "No hay Clientes cargados.\n";
    }
}

bool ClienteManager::bajaCliente(int id) {
    FILE* p = fopen("clientes.dat", "rb+");
    if (p == NULL) {
        cout << "Error al abrir el archivo.\n";
        return false;
    }

    Cliente reg;
    int pos = 0;

    while (fread(&reg, sizeof(Cliente), 1, p) == 1) {
        if (reg.getIdCliente() == id && !reg.getEliminado()) {
            reg.setEliminado(true);

            fseek(p, pos * sizeof(Cliente), SEEK_SET);
            fwrite(&reg, sizeof(Cliente), 1, p);

            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

