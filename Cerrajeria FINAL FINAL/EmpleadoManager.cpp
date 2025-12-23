#include <iostream>
using namespace std;
#include "EmpleadoManager.h"

EmpleadoManager::EmpleadoManager(){}

void EmpleadoManager::altaEmpleado(){
    Empleado reg;
    cout << "\nALTA DE EMPLEADO\n";
    reg.Cargar();
    if(_repo.guardar(reg)){
        cout << "Empleado guardado en archivo.\n";
    } else {
        cout << "Error de apertura.\n";
    }
}

void EmpleadoManager::listarEmpleados() {
    FILE* p = fopen("empleados.dat", "rb");
    if (p == NULL) {
        cout << "No hay Empleados cargados.\n";
        return;
    }

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
        cout << "No hay Empleados cargados.\n";
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
