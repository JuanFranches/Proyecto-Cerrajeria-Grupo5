#include <iostream>
using namespace std;
#include "ServicioManager.h"
#include "rlutil.h"

ServicioManager::ServicioManager(){}

void ServicioManager::altaServicio(){
    Servicio reg;
    cout << "\nALTA DE SERVICIO\n";
    cout << "---------------------------\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        rlutil::setColor(rlutil::GREEN);
        cout << endl;
        cout << "SERVICIO GUARDADO EN ARCHIVO!!!\n";
        rlutil::setColor(rlutil::WHITE);
        } else {
        rlutil::setColor(rlutil::RED);
        cout << "Error de apertura.\n";
        rlutil::setColor(rlutil::WHITE);
        }
}

void ServicioManager::listarServicios() {
    FILE* p = fopen("Servicios.dat", "rb");
    if (p == NULL){
        rlutil::setColor(rlutil::RED);
        cout << "No hay Servicios cargados.\n";
        rlutil::setColor(rlutil::WHITE);
        return;

}

    cout << "LISTADO DE SERVICIOS\n";

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
        rlutil::setColor(rlutil::RED);
        cout << "No hay Servicios cargados.\n";
        rlutil::setColor(rlutil::WHITE);
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
