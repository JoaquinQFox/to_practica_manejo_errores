#include "Alumno.h"
#include "ArchivoAlumnos.h"
#include "AlumnoNoEncontradoException.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::string leerTexto(const std::string& mensaje) {
    std::cout << mensaje;
    std::string texto;
    std::getline(std::cin, texto);
    return texto;
}


int leerEntero(const std::string& mensaje) {
    std::string texto = leerTexto(mensaje);

    try {
        size_t posicion;
        int numero = stoi(texto, &posicion);

        if (posicion != texto.length()) {
            throw std::invalid_argument("Numero invalido.");
        }

        return numero;
    }
    catch (const std::invalid_argument&) {
        throw std::invalid_argument("Debe ingresar un numero entero valido.");
    }
}

int main() {
}
