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
    std::vector<Alumno> alumnos;

    while (true) {
        std::cout << "\nSISTEMA DE REGISTRO DE ALUMNOS\n"
             << "1. Registrar alumno\n"
             << "2. Buscar alumno\n"
             << "3. Listar alumnos\n"
             << "4. Cargar alumnos desde archivo\n"
             << "5. Guardar alumnos en archivo\n" 
             << "6. Salir\n";
        try {
            int opcion = leerEntero("\nOpcion: ");

            if (opcion == 6) break;

            switch (opcion) {
                case 1: {
                    std::cout << "\nREGISTRAR NUEVO ALUMNO\n";
                    int codigo = leerEntero("Codigo: ");
                    std::string nombre = leerTexto("Nombre: ");
                    int edad = leerEntero("Edad: ");
                    Alumno nuevo(codigo, nombre, edad);

                    for (const Alumno& alumno : alumnos) {
                        if (alumno.getCodigo() == codigo) {
                            throw std::invalid_argument("El codigo ya esta registrado.");
                        }
                    }

                    alumnos.push_back(nuevo);
                    std::cout << "\nAlumno registrado!\n";

                    break;
                }

                case 2: {
                    // TODO

                    break;
                }

                case 3:
                    std::cout << "\nLISTA DE ALUMNOS\n";
                    if (alumnos.empty())
                        std::cout << "No hay alumnos registrados.\n";

                    for (const Alumno& alumno : alumnos) 
                        alumno.mostrar();
                    break;

                case 4: {
                    // TODO

                    break;
                }

                case 5: {
                    // TODO

                    break;
                }

                default:
                    std::cout << "\nOpcion no valida\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "\nEntrada incorrecta: " << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cout << "\nError: " << e.what() << '\n';
        }
    }
    return 0;
}
