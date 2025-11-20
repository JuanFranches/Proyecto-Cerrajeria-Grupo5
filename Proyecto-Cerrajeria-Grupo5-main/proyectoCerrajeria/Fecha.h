#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia, mes, anio;

    bool fechaValida(int d, int m, int a);

public:

    Fecha(int d=0, int m=0, int a=0);

    void Cargar();
    void Mostrar() const;

    int  getDia()  const;
    int  getMes()  const;
    int  getAnio() const;

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
};

#endif
