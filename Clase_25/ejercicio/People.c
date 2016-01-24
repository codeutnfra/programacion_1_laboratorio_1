#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "People.h"


/** \brief Inicializa el array de estructuras Person
 * \return void
 */
PeopleList* list_initPeopleList(void)
{
    PeopleList* pl = (PeopleList*)malloc(sizeof(PeopleList)); // creamos una estructura que contiene las variables que antes eran globales

    pl->index=0;
    pl->listSize=2;
    pl->people = (Person**)malloc(sizeof(Person*)*pl->listSize); // Ahora cada item del array es un puntero a una estructura

    return pl;
}

// A partir de aca, todas las funciones que interactuaban con la lista (que era global) ahora reciben como primer argumento, la struct PeopleList
//***********************************************************************************************************************************************

/** \brief Agrega una referencia a una struct Person al array
 *  \param Person p : Puntero a estructura Person
 *  \return void
 */
void list_addPerson(PeopleList* pl, Person* p)
{
    pl->people[pl->index]=p; // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.
    pl->index++;

    // si no hay mas lugar, pedimos más memoria para hacer un array más grande
    if(pl->index>=pl->listSize)
    {
      printf("no hay mas lugar, redefinimos el array\r\n");
      pl->listSize+=2; // agregamos dos mas
      pl->people = (Person**)realloc(pl->people,sizeof(Person*)*pl->listSize);
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
int list_getSize(PeopleList* pl)
{
    return pl->index;
}

/** \brief Devuelve un item del array
 * \param indice a obtener
 * \return Puntero a estructura Person que se encuentra en esa posición del array, o NULL.
 */
Person* list_get(PeopleList* pl,int i)
{
    if(i<pl->index)
        return pl->people[i];

    return NULL;
}

/** \brief Libera la memoria pedida para crear el array
 * \return void
 */
void list_free(PeopleList* pl)
{
    free(pl->people);
}



/** \brief Elimina un item del array
 * \param indice a borrar
 * \return void
 */
void list_remove(PeopleList* pl,int indexToDelete)
{
    int i;
    if(pl->index!=0 && indexToDelete<pl->index)
    {
        for(i=indexToDelete ; i<(pl->index-1); i++)
        {
            pl->people[i] = pl->people[i+1];
        }
        pl->index--;
    }
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

