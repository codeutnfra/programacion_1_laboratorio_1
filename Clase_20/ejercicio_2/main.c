/******************************************************************
* Programa: Ejemplo Clase 20- Ejercicio 2
*
* Objetivo:
    Modificar el ejercicio anterior para guardar las personas en un array estatico e imprimirlas al salir

*
* Aspectos a destacar:
*
*   arrays de estructuras y punteros a estructuras
*
* Version: 0.1 del 06 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct S_Person
{
       char name[20];
       int age;
};
typedef struct S_Person Person;

int enterPerson(Person* p);
void printPerson(Person* p);

int main(int argc, char *argv[])
{
    Person people[1000]; // hacemos un array muy grande para que no se llene nunca
    Person p;
    int index=0;

    // primero pedimos los datos
    while(enterPerson(&p)==0) // guardamos los datos imgresados en la struct "p"
    {
       people[index]=p; // copiamos "p" a una posicion del array de estructuras.
       index++;
    }

    // luego los imprimirmos
    int i;
    for(i=0; i<index;i++)
        printPerson(&people[i]);


   return 0;
}

/** \brief Pide al usuario los datos de una persona y los almacena en la struct
 * \param Person* p puntero a tipo Person donde se guardarán los datos
 * \return 1: si se ingresa salir, 0 de lo contrario
 */
int enterPerson(Person* p)
{
     printf("Ingrese el nombre:");
     scanf("%s",p->name);
     if(strncmp(p->name,"salir",5)==0)
         return 1;
     printf("Ingrese la edad:");
     scanf("%d",&(p->age));
     return 0;
}


/** \brief Imprime los datos de una persona
 * \param Person* p puntero a tipo Person donde se guardarán los datos
 * \return void
 */
void printPerson(Person* p)
{
    printf("Nombre:\t%s \tedad:%d\r\n",p->name,p->age);
}
