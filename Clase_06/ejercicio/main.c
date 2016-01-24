/******************************************************************
* Programa: Ejemplo Clase 6
*
* Objetivo:
*   1-Agregar a la  biblioteca utn.h  funciones para validar diferentes
*     tipos de valores:
*       Solo números, ej. 123436679
*       Solo letras, ej. abBD
*       Alfanumericos, ej. ab555gT6
*       Teléfono, ej. 4XXX-XXXX
*   2-Realizar un programa que pida al usuario el ingreso de un dato y
*     determine con cuales de los tipos cumple
*
* Aspectos a destacar:
*   Manipulación y chequeo de cadena de caracteres
*
* Version: 0.1 del 30 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"

#define MAXINPUT 100 // constante con tamaño del array

int main()
{
    char input[MAXINPUT] ;
    int length;

    printf("Ingrese un algo: ");
    scanf ("%s", input);
    length = strlen (input);
    if(length > 0)
    {
        if (esNumerico(input))
        {
            printf ("Si es un numero\n");
        }

        if (esTelefono(input))
        {
            printf ("Si es un telefono\n");
        }

        if (esAlfaNumerico(input))
        {
            printf ("Si es alfanumerico\n");
        }

        if (esSoloLetras(input))
        {
            printf ("Si es solo letras\n");
        }

    }


}



