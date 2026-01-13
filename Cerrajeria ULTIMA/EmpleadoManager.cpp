#include <iostream>
using namespace std;
#include "EmpleadoManager.h"
#include "rlutil.h"

EmpleadoManager::EmpleadoManager(){}

void EmpleadoManager::altaEmpleado(){
    Empleado reg;
    cout << "\nALTA DE EMPLEADO\n";
    cout << "---------------------------\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
            rlutil::setColor(rlutil::GREEN);
        cout << "EMPLEADO GUARDADO EN ARCHIVO!!!\n";
            rlutil::setColor(rlutil::WHITE);
    } else {
        cout << "Error de apertura.\n";
    }
}

void EmpleadoManager::listarEmpleados() {
    FILE* p = fopen("empleados.dat", "rb");
    if (p == NULL) {
            rlutil::setColor(rlutil::RED);
        cout << "No hay Empleados cargados.\n";
            rlutil::setColor(rlutil::WHITE);
        return;
    }

    cout << "LISTADO DE EMPLEADOS\n";

    Empleado reg;
    bool hayActivos = false;

    while (fread(&reg, sizeof(Empleado), 1, p) == 1) {
        if (!reg.getEliminado()) {
            reg.Mostrar();
            hayActivos = true;
        }
    }

    fclose(p);

    if (!hayActivos) {
            rlutil::setColor(rlutil::RED);
        cout << "No hay Empleados cargados.\n";
            rlutil::setColor(rlutil::WHITE);
    }
}

bool EmpleadoManager::bajaEmpleado(int id) {
    FILE* p = fopen("empleados.dat", "rb+");
    if (p == NULL) {
        cout << "Error al abrir el archivo.\n";
        return false;
    }

    Empleado reg;
    int pos = 0;

    while (fread(&reg, sizeof(Empleado), 1, p) == 1) {
        if (reg.getIdEmpleado() == id && !reg.getEliminado()) {
            reg.setEliminado(true);

            fseek(p, pos * sizeof(Empleado), SEEK_SET);
            fwrite(&reg, sizeof(Empleado), 1, p);

            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}
