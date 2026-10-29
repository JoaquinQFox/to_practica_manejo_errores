# Práctica 07: Registro de alumnos

## Descripción general

Este programa permite registrar, buscar y listar alumnos desde un menú en consola. Cada alumno tiene un código, un nombre y una edad, y sus datos se mantienen en un vector mientras el programa está abierto. También permite guardar los registros en un archivo CSV y cargarlos después.

El manejo de excepciones permite informar errores de entrada, búsquedas sin resultados y problemas con los archivos, evitando que el programa finalice inesperadamente ante estas situaciones.


## Alumno.cpp

Implementa los métodos de la clase `Alumno`. El constructor verifica que el código sea positivo y lanza una excepción `std::invalid_argument` cuando no cumple esta condición. Los métodos getters permiten acceder a los atributos y `mostrar()` imprime los datos del alumno.

## AlumnoNoEncontradoException.h

Define una excepción personalizada que hereda de `std::runtime_error`. Se utiliza cuando se intenta buscar un alumno cuyo código no se encuentra registrado.

La excepción recibe el código buscado y genera un mensaje indicando que el alumno no existe.


## ArchivoAlumnos.cpp

Implementa la carga y el guardado con el formato `codigo,nombre,edad`, sin encabezado y con un alumno por línea.

Durante la carga, comprueba que el archivo se pueda abrir, revisa la estructura de cada línea, convierte los datos numéricos y verifica que no haya códigos repetidos. Si encuentra datos inválidos o problemas de lectura, lanza una excepción y se conservan los alumnos que estaban en el sistema antes de la carga.

Al guardar, escribe el vector en el archivo indicado y comprueba si hubo errores de apertura o escritura. Si el archivo ya existe, su contenido se reemplaza por los registros actuales.

Los nombres deben ingresarse sin comas para no alterar la separación de los campos.

## main.cpp

Contiene el menú principal y las funciones `leerTexto()` y `leerEntero()`, utilizadas para recibir datos desde la consola.

El programa mantiene los alumnos en un `std::vector<Alumno>` y permite realizar las siguientes operaciones:

1. **Registrar alumno:** solicita código, nombre y edad. Comprueba que el código sea positivo y que no esté repetido.
2. **Buscar alumno:** solicita un código y recorre el vector para localizar al alumno. Si lo encuentra, muestra sus datos; de lo contrario, lanza `AlumnoNoEncontradoException`.
3. **Listar alumnos:** muestra los alumnos registrados o informa cuando el vector está vacío.
4. **Cargar alumnos:** solicita la ruta de un archivo CSV y carga sus registros, reemplazando los alumnos que se encuentran en memoria.
5. **Guardar alumnos:** solicita la ruta de un archivo CSV y guarda los registros actuales.
6. **Salir:** finaliza la ejecución del programa.

Las operaciones se encuentran dentro de bloques `try-catch` para controlar los errores y permitir que el usuario continúe utilizando el menú.

## Manejo de excepciones

El programa utiliza excepciones para controlar las siguientes situaciones:

- **Código inválido:** se lanza `std::invalid_argument` cuando el código del alumno no es positivo.
- **Código repetido:** se lanza `std::invalid_argument` al intentar registrar un código existente.
- **Entrada incorrecta:** se informa cuando el usuario introduce un valor que no corresponde a un número entero válido.
- **Alumno inexistente:** se lanza `AlumnoNoEncontradoException` cuando no se encuentra el código solicitado.
- **Archivo inexistente:** se lanza `std::runtime_error` cuando no es posible abrir un archivo para lectura.
- **Datos CSV inválidos:** se lanza una excepción cuando los registros no cumplen el formato esperado.
- **Error de escritura:** se lanza `std::runtime_error` cuando no se puede abrir o escribir correctamente el archivo de salida.


## Compilar y ejecutar

Desde la carpeta `practica07`, ejecutar:

```bash
g++ main.cpp Alumno.cpp ArchivoAlumnos.cpp -o main
./main
```