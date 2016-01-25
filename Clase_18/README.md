# Clase 18

### Material

#### Apuntes:

En el directorio "apuntes" se podrán encontrar los siguientes archivos:
* Archivos.pdf

#### Video tutoriales:

* https://www.youtube.com/watch?v=-plDyLl2a4A&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=18

### Ejercicio
#### Objetivo:

    Crear una struct con dos campos de cadena de caracteres, uno llamado “key” y otro llamado “value”.
    struct S_Data
    {
        char* key;
        char* value;
    };

    Hacer una función que  reciba el nombre de un archivo y un array de estas estructuras.La función leerá un archivo de texto con el siguiente formato:

    clave=valor
    clave=valor

    La función deberá leer cada línea del archivo y separar por el caracter “=” la clave y el valor, y deberá cargarlo en una struct del array,
    generando de forma dinámica las variables para almacenar ambas palabras, y luego guardando los punteros en la struct.
    Prototipo de la función:

    int loadDataFile(char* fileName,struct S_Data* array,int arrayLen)

    La función devolverá la cantidad de items que se cargaron en el array, y nunca se superará el tamaño del array

- Version: 0.1 del 09 enero de 2016
- Autor: Ernesto Gigliotti
- Revisión: Mauricio Dávila

#### Aspectos a destacar:
*   Uso de archivos. Uso de memoria dinámica.