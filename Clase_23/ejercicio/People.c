#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "People.h"


// definimos en forma global el array, la variable que lleva la cuenta del size, y el indice
int listSize;
Person** people;
int index;

/** \brief Inicializa el array de estructuras Person
 * \return void
 */
void list_initPeopleList(void)
{
    index=0;
    listSize=2;
    people = (Person**)malloc(sizeof(Person*)*listSize); // Ahora cada item del array es un puntero a una estructura
}

/** \brief Agrega una referencia a una struct Person al array
 *  \param Person p : Puntero a estructura Person
 *  \return void
 */
void list_addPerson(Person* p)
{
    people[index]=p; // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.
    index++;

    // si no hay mas lugar, pedimos más memoria para hacer un array más grande
    if(index>=listSize)
    {
      printf("no hay mas lugar, redefinimos el array\r\n");
      listSize+=2; // agregamos dos mas
      people = (Person**)realloc(people,sizeof(Person*)*listSize);
    }

}

/** \brief Crea una estructura del tipo Person en forma dinámica
 * \return Devuelve un puntero a la estructura creada
 */
Person* list_newPerson(void)
{
    Person* p = (Person*)malloc(sizeof(Person)); // creamos una estructura Person de forma dinámica
    return p;
}

/** \brief Devuelve la cantidad de items en el array
 * \return Cantidad de items en el array
 */
int list_getSize(void)
{
    return index;
}

/** \brief Devuelve un item del array
 * \param indice a obtener
 * \return Puntero a estructura Person que se encuentra en esa posición del array, o NULL.
 */
Person* list_get(int i)
{
    if(i<index)
        return people[i];

    return NULL;
}

/** \brief Libera la memoria pedida para crear el array
 * \return void
 */
void list_free(void)
{
    free(people);

}

/** \brief Pide al usuario que se ingresen los datos de una persona y los carga en una estructura pasada por referencia.
 * \param Person p : Puntero a estructura Person
 * \return 1 si se ingreso salir, de lo contrario 0
 */
int list_enterPerson(Person* p)
{
     printf("Ingrese el nombre:");
     scanf("%s",p->name);
     if(strncmp(p->name,"salir",5)==0)
         return 1;
     printf("Ingrese la edad:");
     scanf("%d",&(p->age));
     return 0;
}

/** \brief Imprime los datos de una estructura Person
 * \param Person p : Puntero a estructura Person
 * \return void
 */
void list_printPerson(Person* p)
{
    printf("Nombre:\t%s \tedad:%d\r\n",p->name,p->age);
}

