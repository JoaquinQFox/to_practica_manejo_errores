#include "Alumno.h"
#include <iostream>
#include <stdexcept>

Alumno::Alumno(int codigo, const std::string& nombre, int edad)
    : codigo(codigo), nombre(nombre), edad(edad) {

    if (codigo <= 0) {
        throw std::invalid_argument("El codigo debe ser positivo.");
    }
}

int Alumno::getCodigo() const {
    return codigo;
}

const std::string& Alumno::getNombre() const {
    return nombre;
}

int Alumno::getEdad() const {
    return edad;
}

void Alumno::mostrar() const {
        std::cout << "Codigo: " << codigo << ", Nombre: " << nombre << ", Edad: " << edad << "\n";
}
