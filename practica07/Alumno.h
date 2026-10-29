#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

class Alumno {
private:
    int codigo;
    std::string nombre;
    int edad;

public:
    Alumno(int codigo, const std::string& nombre, int edad);
    int getCodigo() const;
    const std::string& getNombre() const;
    int getEdad() const;
    void mostrar() const;
};

#endif
