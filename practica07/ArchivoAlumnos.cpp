#include "ArchivoAlumnos.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<Alumno> cargarAlumnos(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw std::runtime_error("Archivo no encontrado o sin permiso de lectura.");
    }

    std::vector<Alumno> alumnos;
    std::string linea;
    int numeroLinea = 0;

    while (getline(archivo, linea)) {
        ++numeroLinea;

        try {
            std::istringstream fila(linea);
            std::string textoCodigo, nombre, textoEdad;

            if (!std::getline(fila, textoCodigo, ',') ||
                !std::getline(fila, nombre, ',') || !getline(fila, textoEdad) ||
                textoEdad.find(',') != std::string::npos) {
                throw std::invalid_argument("Formato esperado: codigo,nombre,edad.");
            }

            size_t pos;

            int codigo = stoi(textoCodigo, &pos);
            if (pos != textoCodigo.length()) {
                throw std::invalid_argument("Codigo invalido.");
            }

            int edad = stoi(textoEdad, &pos);
            if (pos != textoEdad.length()) {
                throw std::invalid_argument("Edad invalida.");
            }

            Alumno alumno(codigo, nombre, edad);
            for (const Alumno& registrado : alumnos) {
                if (registrado.getCodigo() == codigo) {
                    throw std::invalid_argument("Codigo repetido.");
                }
            }

            alumnos.push_back(alumno);

        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("Datos invalidos en el archivo");
        }
    }

    if (archivo.bad()) throw std::runtime_error("Error al leer el CSV.");
    return alumnos;
}