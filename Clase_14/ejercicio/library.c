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
void setBookStatus(book bookArray[],int arrayLenght,int value)
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
int findBookEmptyPlace(book bookArray[],int arrayLenght)
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
void orderBookArrayByTitle(book bookArray[],int arrayLenght)
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
void showBookArray(book bookArray[],int arrayLenght)
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


/**
 * \brief Inicializa el status en un array de autores
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setAuthorStatus(author authorArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        authorArray[i].status = value;
    }
}

/**
 * \brief Busca la primer ocurrencia de un autor mediante su codigo
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param authorIdAux Es el id que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findAuthorById(author authorArray[],int arrayLenght,int authorIdAux)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(authorArray[i].authorId == authorIdAux && authorArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Carga los valores del autor
 * \param authorArray Es el array de autores
 * \param freePlaceIndex Indica la posicion a setear
 * \param authorIdAux Id del autor
 * \param nameAux Nombre del autor
 * \param lastNameAux Apellido del autor
 * \return -
 *
 */
void setAuthor(author authorArray[],int freePlaceIndex, int authorIdAux,char nameAux[],char lastNameAux[])
{

    authorArray[freePlaceIndex].authorId = authorIdAux;
    strcpy(authorArray[freePlaceIndex].name,nameAux);
    strcpy(authorArray[freePlaceIndex].lastName,lastNameAux);
    authorArray[freePlaceIndex].status = 1;

}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findAuthorEmptyPlace(author authorArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(authorArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Muestra los autores activos por pantalla
 * \param authorArray Es el array de autores
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void showAuthorArray(author authorArray[],int arrayLenght)
{
    int i;
    printf("\n| CODIGO  |      NOMBRE      |    APELLIDO     ");
    for(i=0;i < arrayLenght; i++)
    {
        if(authorArray[i].status != 0)
        {
            printf("\n| %6d  | %-15s  | %-15s",authorArray[i].authorId,authorArray[i].name,authorArray[i].lastName);
        }
    }

}


/**
 * \brief Muestra los libros activos por pantalla indicando el apellido del Autor
 * \param bookArray Es el array de libros
 * \param arrayLenght Indica la logitud del array libros
 * \param authorArray Es el array de autores
 * \param arrayLenght Indica la logitud del array autores
 * \return -
 */
void showBookAuthorArray(book bookArray[],int arrayLenght,author authorArray[],int authorArrayLenght)
{
    int i;
    char auxAuthor[51];
    int authorIdAux;
    printf("\n| CODIGO  |                    TITULO            |     AUTOR       | STOCK |");
    for(i=0;i < arrayLenght; i++)
    {
        if(bookArray[i].status != 0)
        {
            authorIdAux = findAuthorById(authorArray,authorArrayLenght,bookArray[i].authorId);
            if( authorIdAux != -1)
            {
                strcpy(auxAuthor,authorArray[authorIdAux].lastName);
            }
            else
            {
                sprintf(auxAuthor, "? (Id:%d)", bookArray[i].authorId);
            }
            printf("\n| %6d  | %-36s | %15s | %5d |",bookArray[i].code,bookArray[i].title,auxAuthor,bookArray[i].stock);
        }
    }

}
