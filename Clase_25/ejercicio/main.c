/******************************************************************
* Programa: Ejemplo Clase 25
*
* Objetivo:
    Agregar a la biblioteca la posibilidad de crear más de una lista

*
* Aspectos a destacar:
*
*   Array de punteros a estructuras creadas en forma dinámica
*
* Version: 0.1 del 07 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "People.h"


int main(int argc, char *argv[])
{
    PeopleList* pl = list_initPeopleList();

    Person* p = list_newPerson(); // creamos una estructura Person de forma dinámica
    // primero pedimos los datos
    while(list_enterPerson(p)==0) // guardamos los datos imgresados en la struct "p"
    {
        list_addPerson(pl,p); // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.

        p = list_newPerson(); // creamos la siguiente estructura Person de forma dinámica
    }
    free(p); // liberamos esta struct porque no se guardo en el array (cuando ingrese salir)

    list_remove(pl,2); // prueba borrado de posicion 2

    // luego los imprimirmos
    int i;
    for(i=0; i<list_getSize(pl);i++)
        list_printPerson(list_get(pl,i));
    //______________________

    // liberamos todo
    for(i=0; i<list_getSize(pl);i++)
        free(list_get(pl,i));

    list_free(pl);
    //________________

   return 0;
}


