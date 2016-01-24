# Clase 16

### Material

#### Apuntes:

En el directorio "apuntes" se podrán encontrar los siguientes archivos:
* Punteros_II.pdf

#### Video tutoriales:

* https://www.youtube.com/watch?v=pQbN5631cqg&list=PLZU3OfSJlsrfKiKElmKxjCsyQQF_1ApuV&index=16

### Ejercicio
#### Objetivo:

    Realizar una función para cargar los datos de una persona en una struct, para ello se debe definir una estructura con los
    campos nombre, edad, dni. La función tendrá el siguiente prototipo:

        int loadPerson(struct S_Person* pPerson);

    La función deberá devolver un 1 si los datos ingresados son correctos, y un 0 si no lo son.

    Hacer otra función que reciba un puntero a la estructura e imprima por pantalla los datos, el prototipo es:

        void printPerson(struct S_Person* pPerson);

    Escribir un programa para probar las funciones.

- Version: 0.1 del 08 enero de 2016
- Autor: Ernesto Gigliotti
- Revisión: Mauricio Dávila

#### Aspectos a destacar:
*   Pasaje por referencia de estructuras y acceso a sus campos.