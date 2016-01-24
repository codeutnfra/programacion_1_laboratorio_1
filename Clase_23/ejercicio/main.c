/******************************************************************
* Programa: Ejemplo Clase 23
*
* Objetivo:
    A partir del ejercicio anterior, crear la biblioteca “People” que pueda manejar una lista de “Personas” (agregar a
   la lista personas)
*
* Aspectos a destacar:
*
*   Array de punteros a estructuras creadas en forma dinámica
*
* Version: 0.1 del 06 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "People.h"


int main(int argc, char *argv[])
{
    list_initPeopleList();

    Person* p = list_newPerson(); // creamos una estructura Person de forma dinámica
    // primero pedimos los datos
    while(list_enterPerson(p)==0) // guardamos los datos imgresados en la struct "p"
    {
        list_addPerson(p); // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.

        p = list_newPerson(); // creamos la siguiente estructura Person de forma dinámica
    }
    free(p); // liberamos esta struct porque no se guardo en el array (cuando ingrese salir)

    // luego los imprimirmos
    int i;
    for(i=0; i<list_getSize();i++)
        list_printPerson(list_get(i));
    //______________________

    // liberamos todo
    for(i=0; i<list_getSize();i++)
        free(list_get(i));

    list_free();
    //________________

   return 0;
}


