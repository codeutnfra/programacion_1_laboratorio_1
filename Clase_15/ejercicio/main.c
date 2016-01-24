/******************************************************************
* Programa: Ejemplo Clase 15
*
* Objetivo:
*   Escribir 4 funciones que reciban un array de numeros int y su tamaño, e impriman los numeros por pantalla.
*
*   1era funcion: Recibe el array como vector y accede a los datos utilizando notación vectorial ([])
*
*   2da funcion: Recibe el array como vector y accede a los datos utilizando aritmetica de punteros
*
*   3era funcion: Recibe el array como puntero y accede a los datos utilizando notación vectorial ([])
*
*   4da funcion: Recibe el array como puntero y accede a los datos utilizando aritmetica de punteros
*
* Aspectos a destacar:
*
*   Aritmetica de punteros
*
* Version: 0.1 del 06 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/** \brief Imprime los items de un array
 * \param int array[]: Array del tipo int
 * \param int len: tamaño del array
 * \return void
 */
void printArray1(int array[], int len)
{
    int i;
    for(i=0; i<len;i++)
        printf("%d ",array[i]);

    printf("\r\n");
}

/** \brief Imprime los items de un array
 * \param int array[]: Array del tipo int
 * \param int len: tamaño del array
 * \return void
 */
void printArray2(int array[], int len)
{
    int i;
    for(i=0; i<len;i++)
        printf("%d ",*(array+i));


    printf("\r\n");
}

/** \brief Imprime los items de un array
 * \param int* array: Array del tipo int
 * \param int len: tamaño del array
 * \return void
 */
void printArray3(int* array, int len)
{
    int i;
    for(i=0; i<len;i++)
        printf("%d ",array[i]);

    printf("\r\n");
}

/** \brief Imprime los items de un array
 * \param int* array: Array del tipo int
 * \param int len: tamaño del array
 * \return void
 */
void printArray4(int* array, int len)
{
    int i;
    for(i=0; i<len;i++)
        printf("%d ",*(array+i));

    printf("\r\n");
}

int main()
{
    int array[10];
    int i;

    getNumeroAleatorio(0,100,1); // inicializo semilla random

    // carga array con numeros aleatorios
    for(i=0; i<10;i++)
        array[i] = getNumeroAleatorio(0,100,0);

    // imprimo array usando las diferentes funciones
    printArray1(array,10);
    printArray2(array,10);
    printArray3(array,10);
    printArray4(array,10);

    return 0;
}
