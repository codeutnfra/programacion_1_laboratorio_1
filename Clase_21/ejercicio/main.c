/******************************************************************
* Programa: Ejemplo Clase 21
*
* Objetivo:
    Tomar el ejercicio anterior y cambiar el array estático por uno dinámico usando malloc.

*
* Aspectos a destacar:
*
*   Uso de memoria dinámica. Creación de una lista que crece en forma dinámica.
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
    int listSize=2;
    Person* people = (Person*)malloc(sizeof(Person)*listSize); // pedimos memoria para un array de 2 items

    Person p;
    int index=0;

    // primero pedimos los datos
    while(enterPerson(&p)==0) // guardamos los datos imgresados en la struct "p"
    {
       people[index]=p; // copiamos "p" a una posicion del array de estructuras.
       index++;

       // si no hay mas lugar, pedimos más memoria para hacer un array más grande
       if(index>=listSize)
       {
          printf("no hay mas lugar, redefinimos el array\r\n");
          listSize+=2; // agregamos dos mas
          people = (Person*)realloc(people,sizeof(Person)*listSize);
       }

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
