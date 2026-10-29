#ifndef ARCHIVO_ALUMNOS_H
#define ARCHIVO_ALUMNOS_H

#include "Alumno.h"
#include <string>
#include <vector>

std::vector<Alumno> cargarAlumnos(const std::string& nombreArchivo);
void guardarAlumnos(const std::vector<Alumno>& alumnos, const std::string& nombreArchivo);

#endif
