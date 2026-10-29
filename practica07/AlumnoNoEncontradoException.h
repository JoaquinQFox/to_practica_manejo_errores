#ifndef ALUMNO_NO_ENCONTRADO_EXCEPTION_H
#define ALUMNO_NO_ENCONTRADO_EXCEPTION_H

#include <stdexcept>
#include <string>

class AlumnoNoEncontradoException : public std::runtime_error {
public:
    AlumnoNoEncontradoException(int codigo)
        : std::runtime_error("No existe un alumno con codigo " + std::to_string(codigo) + ".") {}
};

#endif
