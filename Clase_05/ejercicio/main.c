/******************************************************************
* Programa: Ejemplo Clase 5
*
* Objetivo:
*   Solicitar al usuario 5 números, permitir listarlos por pantalla
*   indicando el máximo, el mínimo y el promedio
*   Permitir Modificar el valor de cualquiera de los números cargados
*   indicando el índice del mismo y su nuevo valor.
*
* Aspectos a destacar:
*   -Utilización de array
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD 5 // constante con tamaño del array

int main()
{
    int arrayDeNumeros[CANTIDAD];
    int numeroIngresado;
    int indiceArray;
    int valorIngresado;
    int opcionMenu = 0;

    for(indiceArray = 0 ; indiceArray < CANTIDAD ; indiceArray++ )
    {
            numeroIngresado = getInt("Ingrese el valor: \n");
            arrayDeNumeros[indiceArray] = numeroIngresado;
    }

    while(opcionMenu != 3)
    {
         opcionMenu = getInt("\n1 - Mostrar \n2 - Modificar \n3 - Salir\n");
         switch(opcionMenu)
         {
            case 1:
                printf("\n\nINDICE - VALOR\n");
                for(indiceArray = 0 ; indiceArray < CANTIDAD ; indiceArray++ )
                {
                    printf("  %d    -   %d \n",indiceArray,arrayDeNumeros[indiceArray]);
                }
                break;

            case 2:
                indiceArray = getInt("\nIngrese el indice a modificar: ");
                if(indiceArray >= 0 && indiceArray < CANTIDAD)
                {
                    valorIngresado = getInt("Ingrese el valor: \n");
                    arrayDeNumeros[indiceArray] = valorIngresado;
                }
                else
                {
                    printf("\nEl indice ingresado esta fuera de rango!!!!");
                }
                break;
         } // fin switch
    } // fin while

    return 0;
}

