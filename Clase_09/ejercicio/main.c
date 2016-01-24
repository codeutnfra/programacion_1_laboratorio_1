/******************************************************************
* Programa: Ejemplo Clase 9
*
* Objetivo:
*   El juego de cartas del siete y medio. Consiste en ir pidiendo
*   cartas intentando sumar 7.5 puntos sin pasarse. Gana el jugador
*   que más se acerca a 7.5. Se utiliza una baraja española. Sota,
*   caballo y rey valen medio punto. Las demás cartas puntúan según
*   su valor numérico (de 1 a 7). Utilizar la biblioteca utn.h.
*
* Aspectos a destacar:
*   -Utilización de array
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión : Ernesto Gigliotti
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "juego.h"




int main()
{

    Carta arrayDeCartas[49];
    int opcion;
    float puntosAcumulados;
    int i;
    char jugar='s';


    crearMazo(arrayDeCartas);

    while(jugar == 's')
    {

        puntosAcumulados = 0;
        mezclarMazo(arrayDeCartas);
        for(i = 0 ; i <= CANTIDAD_CARTAS ; i++ )
        {


            printf("Su carta es %d de %s\n", arrayDeCartas[i].numero ,arrayDeCartas[i].palo) ;

            puntosAcumulados = puntosAcumulados + arrayDeCartas[i].valor;
            if(puntosAcumulados == 7.5)
            {
                printf("GANO!!!!!!!!!!");
                break;
            }
            else if(puntosAcumulados > 7.5)
            {
                printf("PERDIO!!!!!!!!!!");
                break;
            }
            else
            {
                printf("Su puntaje es %0.1f\n", puntosAcumulados);
                opcion = getInt("Plantarse (1) - Otra carta (2)");
                if (opcion == 1)
                {
                    break;
                }

            }

        }

        jugar = getChar("Para jugar nuevamente pulse (s) \n");
    }

    return 0;
}

