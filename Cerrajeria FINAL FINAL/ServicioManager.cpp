#include <iostream>
using namespace std;
#include "ServicioManager.h"

ServicioManager::ServicioManager(){}

void ServicioManager::altaServicio(){
    Servicio reg;
    cout << "\nALTA DE SERVICIO\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Servicio guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void ServicioManager::listarServicios() {
    FILE* p = fopen("Servicios.dat", "rb");
    if (p == NULL) {
        cout << "No hay Servicios cargados.\n";
        return;
    }

    Servicio reg;
    bool hayActivos = false;

    while (fread(&reg, sizeof(Servicio), 1, p) == 1) {
        if (!reg.getEliminado()) {
            reg.Mostrar();
            hayActivos = true;
        }
    }

    fclose(p);

    if (!hayActivos) {
        cout << "No hay Servicios cargados.\n";
    }
}

bool ServicioManager::bajaServicio(int id) {
    FILE* p = fopen("Servicios.dat", "rb+");
    if (p == NULL) {
        cout << "Error al abrir el archivo.\n";
        return false;
    }

    Servicio reg;
    int pos = 0;

    while (fread(&reg, sizeof(Servicio), 1, p) == 1) {
        if (reg.getIdServicio() == id && !reg.getEliminado()) {
            reg.setEliminado(true);

            fseek(p, pos * sizeof(Servicio), SEEK_SET);
            fwrite(&reg, sizeof(Servicio), 1, p);

            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}
