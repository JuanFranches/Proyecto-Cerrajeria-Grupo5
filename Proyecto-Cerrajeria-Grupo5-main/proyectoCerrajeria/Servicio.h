
#ifndef SERVICIO_H
#define SERVICIO_H

class Servicio {
private:
    int  idServicio;
    char nombre[40];
    char descripcion[100];
    float precio;
    bool  eliminado;

public:
    Servicio();
    void Cargar();
    void Mostrar() const;
};
#endif
