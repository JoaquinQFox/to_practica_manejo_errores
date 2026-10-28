# Práctica 03: Lectura de archivos

## Descripción general

Este programa permite abrir un archivo de texto y mostrar su contenido en la consola. El usuario escribe el nombre o la ruta del archivo que desea consultar y, al terminar la lectura, puede elegir otro. La práctica muestra cómo manejar problemas al trabajar con archivos sin cerrar el programa de forma inesperada. Para salir, se debe escribir 0.


## Funcionamiento del Programa
- **Lectura Interactiva:** Solicita al usuario el nombre de un archivo de texto de manera continua para procesar su contenido.
- **Control de Errores:** Utiliza bloques `try-catch` para capturar fallos. Si el archivo ingresado no existe o no se puede abrir, el programa no se interrumpe; muestra un mensaje de advertencia y permite al usuario ingresar un nuevo nombre.
- **Opción de Salida:** Finaliza la ejecución de forma segura cuando el usuario ingresa el número `0`.

## Archivos Incluidos
- **main.cpp:** Contiene el código fuente con la lógica de lectura y el manejo de excepciones.
- **ejemplo.txt:** Archivo de prueba con texto predefinido que sirve para verificar que el programa lee e imprime correctamente el contenido en pantalla cuando el archivo sí existe.


## Compilar y ejecutar

```bash
g++ main.cpp -o main
./main
```
