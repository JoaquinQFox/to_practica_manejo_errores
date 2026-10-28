# Práctica 07: Registro de alumnos

## Descripción general

Este programa permite registrar, buscar y listar alumnos desde un menú en consola. Cada alumno tiene un código, un nombre y una edad, y sus datos se mantienen en un vector mientras el programa está abierto. También permite guardar los registros en un archivo CSV y cargarlos después. El manejo de excepciones ayuda a informar errores de entrada, búsquedas sin resultados y problemas con los archivos, para que el usuario pueda continuar utilizando el sistema.


## Compilar y ejecutar

```bash
g++ main.cpp Alumno.cpp ArchivoAlumnos.cpp -o main
./main
```
