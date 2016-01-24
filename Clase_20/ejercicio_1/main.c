/******************************************************************
* Programa: Ejemplo Clase 20- Ejercicio 1
*
* Objetivo:
    Ingresar datos de 1 persona e imprimirlos. Crear la estructura "Persona":
        nombre [32]
        edad
    Si se ingresa “salir” como nombre, se debe salir del programa, de lo contrario se pediran los datos de nuevo.

*
* Aspectos a destacar:
*
*   Punteros a estructuras
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
   Person p;

   while(enterPerson(&p)==0)
       printPerson(&p);

   system("PAUSE");
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
