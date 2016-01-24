/******************************************************************
* Programa: Ejemplo Clase 4
*
* Objetivo:
*   A-  Desarrollar una biblioteca "utn.h" que posea funciones para
*       pedirle al usuario el ingreso de datos
*           - getInt()
*           - getFloat()
*           - getChar()
*
*   B-  Diseñar un programa para jugar a adivinar un número entre 0 y 100.
*       El juego tiene que dar pistas de si el número introducido por el
*       jugador está por encima o por debajo. El juego termina cuando se
*       adivina el número o se decide terminar de jugar ingresando un número
*       negativo. Permitir jugar tantas veces como lo desee el jugador y al
*       salir mostrar su mejor puntuación. Utilizar la biblioteca del punto 1.
*
* Aspectos a destacar:
*   -Se practica la declaración de funciones y se muestra como crear una
*    biblioteca propia y utilizarla en un programa.
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int numeroOculto;
    int numeroIngresado;
    char teclaIngresada;
    int jugar;

    teclaIngresada = 's';
    while (teclaIngresada == 's')
    {
        numeroOculto = getNumeroAleatorio(1,100,1);
        //printf("%d\n",numeroOculto );

        jugar = 1;
        while(jugar == 1)
        {
            numeroIngresado = getInt("Ingrese un numero (0 - 99) \n");
            if(numeroIngresado < 0)
            {
                jugar = 0;
            }
            else if(numeroIngresado == numeroOculto)
            {
                printf("FELICITACIONES GANASTE!!! \n");
                jugar = 0;
            }
            else if(numeroIngresado > numeroOculto)
            {
                printf("EL NUMERO QUE INGRESASTE ES GRANDE!!! \n");
            }
            else if(numeroIngresado < numeroOculto)
            {
                printf("EL NUMERO QUE INGRESASTE ES CHICO!!! \n");
            }
        }

        teclaIngresada = getChar("Desea jugar nuevamente? (s/n)\n");

    }

    return 0;
}




