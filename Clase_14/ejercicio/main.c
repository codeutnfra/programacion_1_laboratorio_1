/******************************************************************
* Programa: Ejemplo Clase 14
*
* Objetivo:
* Partiendo del ejercicio de la clase 13 incorporar la entidad AUTOR
* con los siguientes datos:
*
*	    Datos del Autor:
*           Código del Autor  (1 a 500)  Validar
*           Nombre (máximo 50 caracteres)  Validar
*          	Apellido (máximo 50 caracteres)  Validar
*
*       ALTAS: No es necesario el ingreso de todos los autores.
*
*       BAJA: Se ingresa el Código del autor
*
*       LISTAR LIBROS:
*           Realizar un solo listado con todos los libros, en el
*           debera figurar el apellido del autor.
*
* Aspectos a destacar:
*
*   manejo de menú anidados
*   manejo de mas de una entidad
*   main() minimalista
*   sprintf
*
* Version: 0.1 del 05 enero de 2016
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "library.h"



void adminBooks (book bookArray[]);
void adminAuthors(author authorArray[]);

int main()
{
    // arrays de libros
    book bookArray[MAX_QTY];
    setBookStatus(bookArray,MAX_QTY,0);
    //________________________________________________

    // arrays de libros
    author authorArray[MAX_QTY];
    setAuthorStatus(authorArray,MAX_QTY,0);
    //________________________________________________


    // Alta de datos para testing
    setBook(bookArray,1,1,"What you need before you can learn C",1,777);
    setBook(bookArray,2,2,"Using a Compiler",2,33);
    setBook(bookArray,3,3,"A Taste of C",3,98);
    setBook(bookArray,4,4,"Why Learn C",1,876);

    setAuthor(authorArray,1,1,"Brian","Kernighan");
    setAuthor(authorArray,2,2,"Dennis","Ritchie");
    setAuthor(authorArray,3,3,"Linus","Torvalds");
    setAuthor(authorArray,4,4,"Richard","Stallman");
    //________________________________________________

    int option = 0;

    while(option != 4)
    {
        system("@cls||clear");
        printf("\n------------  MENU PRINCIPAL ------------");
        option = getInt("\n1 - ABM LIBROS \n2 - ABM AUTORES \n3 - LISTAR LIBROS\n4 - SALIR\n\n\n");
        switch(option)
        {
            case 1: // ABM LIBROS
                adminBooks(bookArray);
                break;
            case 2: // ABM AUTORES
                adminAuthors(authorArray);
                break;
            case 3: // LISTAR
                system("@cls||clear");
                showBookAuthorArray(bookArray,MAX_QTY,authorArray,MAX_QTY);
                getChar("\n\nENTER (para continuar)");

                break;

        }
    }


    return 0;
}


void adminAuthors(author authorArray[])
{
    // variables auxiliares
    char nameAux[51];
    char lastNameAux[51];
    int authorIdAux;
    //________________________________________________

    int freePlaceIndex;
    int foundIndex;
    int option = 0;

    while(option != 4)
    {
         system("@cls||clear");
         printf("\n------------  ABM AUTORES ------------");
         option = getInt("\n1 - ALTA \n2 - BAJA \n3 - LISTAR\n4 - REGRESAR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE autor

                freePlaceIndex = findAuthorEmptyPlace(authorArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                authorIdAux = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, 500);
                if(findAuthorById(authorArray,MAX_QTY,authorIdAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                getValidString("Ingrese el nombre del autor: ","El nombre debe estar compuesto solo por letras\n", nameAux);

                getValidString("Ingrese el apellido del autor: ","El nombre debe estar compuesto solo por letras\n", lastNameAux);

                setAuthor(authorArray,freePlaceIndex,authorIdAux,nameAux,lastNameAux);

                break;

            case 2: // BAJA AUTOR

                authorIdAux = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, 500);
                foundIndex = findAuthorById(authorArray,MAX_QTY,authorIdAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                authorArray[foundIndex].status = 0;
                break;

            case 3: // LISTAR
                system("@cls||clear");
                showAuthorArray(authorArray,MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;


         }
    }
}








void adminBooks(book bookArray[])
{
    // variables auxiliares
    char titleAux[51];

    int authorIdAux;
    int codeAux;
    int stockAux;
    //________________________________________________

    int freePlaceIndex;
    int foundIndex;
    int option = 0;

    while(option != 6)
    {
         system("@cls||clear");
         printf("\n------------  ABM LIBROS ------------");
         option = getInt("\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - REGRESAR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE LIBRO

                freePlaceIndex = findBookEmptyPlace(bookArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                codeAux = getValidInt("Ingrese el codigo del libro: ","El codigo del libro debe ser numerico\n", 1, 15000);
                if(findBookByCode(bookArray,MAX_QTY,codeAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                authorIdAux =  getValidInt("Ingrese el ID del autor del libro: ","El ID del autor debe ser numerico\n", 1, 500);

                stockAux = getValidInt("Ingrese la cantidad de libros: ","La cantidad debe ser numerica\n", 1, 10000);

                getValidString("Ingrese el titulo: ","El titlo debe estar compuesto solo por letras\n", titleAux);

                setBook(bookArray,freePlaceIndex,codeAux,titleAux,authorIdAux,stockAux);

                break;

            case 2: // BAJA LIBRO

                codeAux = getValidInt("Ingrese el codigo de libro a dar de baja: ","El codigo del libro debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(bookArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                bookArray[foundIndex].status = 0;
                break;

            case 3: // MODIFICAR LIBRO

                codeAux = getValidInt("Ingrese el codigo del libro a modificar: ","El codigo del libro debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(bookArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }


                authorIdAux =  getValidInt("Ingrese el ID del autor del libro: ","El ID del autor debe ser numerico\n", 1, 500);

                stockAux = getValidInt("Ingrese la cantidad de libros: ","La cantidad debe ser numerica\n", 1, 10000);

                getValidString("Ingrese el titulo: ","El titulo debe estar compuesto solo por letras\n", titleAux);

                setBook(bookArray,foundIndex,codeAux,titleAux,authorIdAux,stockAux);

                break;

            case 4: // LISTAR
                system("@cls||clear");
                showBookArray(bookArray,MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;

            case 5: // ORDENAR
                orderBookArrayByTitle(bookArray,MAX_QTY);
                getChar("\n\nOrdenados. ENTER (para continuar)");
                break;


         }
    }
}
