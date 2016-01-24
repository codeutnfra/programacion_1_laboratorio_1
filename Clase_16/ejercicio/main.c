/******************************************************************
* Programa: Ejemplo Clase 16
*
* Objetivo:
    Realizar una función para cargar los datos de una persona en una struct, para ello se debe definir una estructura con los
    campos nombre, edad, dni. La función tendrá el siguiente prototipo:

        int loadPerson(struct S_Person* pPerson);

    La función deberá devolver un 1 si los datos ingresados son correctos, y un 0 si no lo son.

    Hacer otra función que reciba un puntero a la estructura e imprima por pantalla los datos, el prototipo es:

        void printPerson(struct S_Person* pPerson);

    Escribir un programa para probar las funciones.
*
* Aspectos a destacar:
*
*   Pasaje por referencia de estructuras y acceso a sus campos.
*
* Version: 0.1 del 08 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

struct S_Person
{
    char name[32];
    int age;
    char id[32];
};

/** \brief Pide al usuario los datos de una persona y los carga en la estructura pasada por referencia
 * \param struct S_Person* pPerson: Puntero a estructura
 * \return 1: OK, 0: Error
 */
int loadPerson(struct S_Person* pPerson)
{
    getString("Ingrese el nombre:",pPerson->name);

    pPerson->age = getInt("Ingrese la edad:");
    if(pPerson->age<=0 || pPerson->age>100)
        return 0; //error

    if(getStringNumeros("Ingrese el DNI:",pPerson->id)==0)
        return 0; // error

    return 1;
}

/** \brief Imprime los datos de una persona
 * \param struct S_Person* pPerson: Puntero a estructura
 * \return void
 */
void printPerson(struct S_Person* pPerson)
{
    printf("Nombre:%s Edad:%d DNI:%s",pPerson->name,pPerson->age,pPerson->id);
}

int main()
{
    struct S_Person p;

    if(loadPerson(&p))
    {
        printf("Datos correctos\r\n");
        printPerson(&p);
    }
    else
    {
        printf("Datos incorrectos");
    }
    return 0;
}
