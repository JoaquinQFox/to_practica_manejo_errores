#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

int main() {
    std::string nombre;
    while (true) {
        std::cout << "Nombre del archivo (0 para salir): ";
        if (!std::getline(std::cin, nombre) || nombre == "0") break;

        try {
            std::ifstream archivo(nombre);
            if (!archivo.is_open()) {
                throw std::runtime_error("El archivo no existe o no se puede abrir.");
            }

            std::cout << "\n";
            std::string linea;
            while (std::getline(archivo, linea)) {
                std::cout << linea << '\n';
            }
            std::cout << "\n";

            if (archivo.bad()) {
                throw std::runtime_error("No se pudo completar la lectura.");
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
        std::cout << "Puede leer otro archivo.\n";
    }
    return 0;
}
