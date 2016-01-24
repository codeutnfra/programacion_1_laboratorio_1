#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "juego.h"


/**
 * \brief Carga en cada posición del array una carta
 * \param arrayDeCartas es el arreglo de cartas que sera cargado
 *
 */
void crearMazo(Carta arrayDeCartas[])
{
    const char *palos[] = {"COPA","ORO","BASTO","ESPADA"};
    int numero,j;
    int indice;

    for(j=0 ; j<4 ; j++)
    {
        for (numero=1 ; numero<13 ; numero++)
        {
            indice = numero + (12 * j);
            arrayDeCartas[indice].numero = numero;
            strcpy(arrayDeCartas[indice].palo,palos[j]);
            if(numero == 8 || numero == 9)
            {
                arrayDeCartas[indice].valor = 0;
            }
            else if(numero<8)
            {
                arrayDeCartas[indice].valor = numero;
            }
            else
            {
                arrayDeCartas[indice].valor = 0.5;
            }

        }
    }
}


/**
 * \brief Recibe el array de cartas y realiza un ordenamiento aleatorio
 * \param arrayDeCartas es el arreglo de cartas
 *
 * \note
 *     Para determinar si se modifica la posición de un elemento se usa una función aleatoria
 *     y luego con la operación módulo (%) nos da el resto de dividir rand() entre 2.
 *     Este resto puede ir de 0 a 1. De la misma forma, el módulo de rand()
 *     entre N+1 va de 0 a N.
 *
 */
void mezclarMazo(Carta arrayDeCartas[])
{
    int i,j;
    Carta auxiliar;

    getNumeroAleatorio(0 , 1, 1);
    for(i = 0 ; i < CANTIDAD_CARTAS - 1 ; i++ )
    {
        for(j = i+1 ; j < CANTIDAD_CARTAS ; j++ )
        {
            if (getNumeroAleatorio(0 , 1, 0))
            {
                auxiliar = arrayDeCartas[i];
                arrayDeCartas[i] = arrayDeCartas [j];
                arrayDeCartas[j] = auxiliar;
            }
        }

    }

}

