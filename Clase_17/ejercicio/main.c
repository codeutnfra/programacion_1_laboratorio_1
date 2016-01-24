/******************************************************************
* Programa: Ejemplo Clase 17
*
* Objetivo:
    Construir una función “getDynamicString” que permita al usuario
    ingresar un texto y devuelva un puntero a un espacio de memoria
    donde esta almacenado el texto ingresado.
    Se requiere el uso de memoria dinámica.
*
* Aspectos a destacar:
*
*   malloc, realloc, free
*
* Version: 0.1 del 16 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>

/** \brief Permite al usuario ingresar un texto y lo devuelve en un nuevo espacio de memoria.
 * \param char* msg. Mensaje a ser impreso
 * \return Puntero a cadena de caracteres con texto ingresado. Se debe liberar con free().
 */
char* getDynamicString(char* msg)
{
    printf(msg);

    char* pData = (char*)malloc(sizeof(char)*1024);

    scanf("%1023s",pData); // cantidad maxima 1023 (dejamos 1 byte para terminador)

    int len = strlen(pData);

    pData = (char*)realloc(pData,sizeof(char)*(len+1)); //realloc de len (cantidad de letras) + 1  byte por caracter terminador

    return pData;
}

int main()
{
    char* pName = getDynamicString("Ingresa tu nombre:");

    printf("tu nombre es: %s",pName);

    free(pName);

    return 0;
}
