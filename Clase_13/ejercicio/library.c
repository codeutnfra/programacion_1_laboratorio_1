#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "library.h"


/**
 * \brief Inicializa el status en un array de libros
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setStatus(book bookArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        bookArray[i].status = value;
    }
}



/**
 * \brief Busca la primer ocurrencia de un libro mediante su codigo
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findBookByCode(book bookArray[],int arrayLenght,int code)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(bookArray[i].code == code && bookArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findEmptyPlace(book bookArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(bookArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}



/**
 * \brief Busca el precio promedio
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay bookos activos (-1) y si lo hay el precio de ese booko
 *
 */
void orderArrayByTitle(book bookArray[],int arrayLenght)
{
    book bookAux;
    int i,j;

    for(i=0; i < arrayLenght - 1; i++)
    {
        if(bookArray[i].status == 0)
        {
            continue;
        }
        for(j=i+1; j < arrayLenght; j++)
        {
            if(bookArray[j].status == 0)
            {
                continue;
            }
            if(strcmp(bookArray[j].title,bookArray[i].title)<0)
            {
                bookAux = bookArray[j];
                bookArray[j] = bookArray[i];
                bookArray[i] = bookAux;
            }
            else if(strcmp(bookArray[j].title,bookArray[i].title) == 0)
            {
                if(bookArray[i].code > bookArray[j].code)
                {
                    bookAux = bookArray[j];
                    bookArray[j] = bookArray[i];
                    bookArray[i] = bookAux;
                }
            }
        }
    }
}

/**
 * \brief Carga los valores del libro
 * \param bookArray Es el array de libros
 * \param freePlaceIndex Indica la posicion a setear
 * \param codeAux Codigo del libro
 * \param titleAux Titulo del libro
 * \param authorIdAux Id del autor
 * \param stockIdAux Cantidad de ejemplaes disponibles
 * \return -
 *
 */
void setBook(book bookArray[],int freePlaceIndex, int codeAux,char titleAux[], int authorIdAux,int stockAux)
{

    bookArray[freePlaceIndex].authorId = authorIdAux;
    strcpy(bookArray[freePlaceIndex].title,titleAux);
    bookArray[freePlaceIndex].stock = stockAux;
    bookArray[freePlaceIndex].code = codeAux;
    bookArray[freePlaceIndex].status = 1;
}

/**
 * \brief Muestra los libros activos por pantalla
 * \param bookArray Es el array de libros
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void showArray(book bookArray[],int arrayLenght)
{
    int i;
    printf("\n| CODIGO  |                      TITULO              | AUTOR | STOCK |");
    for(i=0;i < arrayLenght; i++)
    {
        if(bookArray[i].status != 0)
        {
            printf("\n| %6d  | %-40s | %5d | %5d |",bookArray[i].code,bookArray[i].title,bookArray[i].authorId,bookArray[i].stock);
        }
    }

}
