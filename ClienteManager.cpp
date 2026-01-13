#include <iostream>
using namespace std;
#include "ClienteManager.h"
#include "rlutil.h"

ClienteManager::ClienteManager(){}

void ClienteManager::altaCliente(){
    Cliente reg;
    cout << "\nALTA DE CLIENTE\n";
    cout << "---------------------------\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        rlutil::setColor(rlutil::GREEN);
        cout << endl;
        cout << "CLIENTE GUARDADO EN ARCHIVO!!!\n";
        rlutil::setColor(rlutil::WHITE);
    } else {
        rlutil::setColor(rlutil::RED);
        cout << "Error de apertura.\n";
        rlutil::setColor(rlutil::WHITE);
    }
}

void ClienteManager::listarClientes() {
    FILE* p = fopen("clientes.dat", "rb");
    if (p == NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "NO HAY CLIENTES CARGADOS.\n";
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    Cliente reg;
    bool hayActivos = false;

    while (fread(&reg, sizeof(Cliente), 1, p) == 1) {
        if (!reg.getEliminado()) {

            if (!hayActivos) {
                cout << "LISTADO DE CLIENTES:\n";
                hayActivos = true;
            }

            reg.Mostrar();
        }
    }

    fclose(p);

    if (!hayActivos) {
        rlutil::setColor(rlutil::RED);
        cout << "NO HAY CLIENTES CARGADOS.\n";
        rlutil::setColor(rlutil::WHITE);
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

