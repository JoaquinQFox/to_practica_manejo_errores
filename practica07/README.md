# Práctica 07: Registro de alumnos

## Descripción general

Este programa permite registrar, buscar y listar alumnos desde un menú en consola. Cada alumno tiene un código, un nombre y una edad, y sus datos se mantienen en un vector mientras el programa está abierto. También permite guardar los registros en un archivo CSV y cargarlos después. El manejo de excepciones ayuda a informar errores de entrada, búsquedas sin resultados y problemas con los archivos, para que el usuario pueda continuar utilizando el sistema.

## ArchivoAlumnos.h

Declara las funciones cargarAlumnos() y guardarAlumnos(), encargadas de trabajar con los archivos CSV. La primera devuelve un vector con los alumnos leídos y la segunda recibe los registros que se desean guardar. Este archivo permite que el programa principal utilice ambas funciones sin incluir directamente su implementación.

## ArchivoAlumnos.cpp

Implementa la carga y el guardado con el formato codigo,nombre,edad, sin encabezado y con un alumno por línea. Durante la carga, comprueba que el archivo se pueda abrir, revisa la estructura de cada línea, convierte los datos numéricos y verifica que no haya códigos repetidos. Si encuentra datos inválidos o problemas de lectura, lanza una excepción y se conservan los alumnos que estaban en el sistema antes de la carga. Al guardar, escribe el vector en el archivo indicado y comprueba si hubo errores de apertura o escritura. Los nombres deben ingresarse sin comas para no alterar la separación de los campos.

## Compilar y ejecutar

```bash
g++ main.cpp Alumno.cpp ArchivoAlumnos.cpp -o main
./main
```
