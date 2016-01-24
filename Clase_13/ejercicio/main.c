/******************************************************************
* Programa: Ejemplo Clase 13
*
* Objetivo:
*       Se solicita realizar una aplicación que permita administrar
*       los libros de una libreria.
*
*	    Datos Libro:
*           Código del libro (1 a  5.000) Validar
*           Título  (máximo 50 caracteres)  Validar
*           Código del Autor  (1 a 500)  Validar
*           Stock  (numerico)
*
*       ALTAS: No es necesario el ingreso de todos los libros.
*
*       MODIFICAR: Se ingresará el Código del Libro, permitiendo modificar:
*           Código del libro
*           Título
*           Código del Autor
*           Stock
*
*       BAJA: Se ingresa el Código del Libro.
*
*       ORDENAR: Se ordenara el array por titulo y ante igualdad por codigo
*
*       LISTAR LIBROS: Realizar un solo listado con todos los libros
*
*
* Aspectos a destacar:
*
*   manejo de menú
*   manejo de estructuras
*   funcion main() compacta
*   variables y funciones en Ingles
*   Alta de datos para testing
*
* Version: 0.1 del 05 enero de 2016
* Autor: Mauricio
*
* *******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "library.h"


int main()
{
    // arrays de libros
    book bookArray[MAX_QTY];
    //________________________________________________


    // variables auxiliares
    char titleAux[51];

    int authorIdAux;
    int codeAux;
    int stockAux;
    //________________________________________________

    int freePlaceIndex;
    int foundIndex;
    int option = 0;

    setStatus(bookArray,MAX_QTY,0);

    // Alta de datos para testing
    setBook(bookArray,1,1,"What you need before you can learn",1,777);
    setBook(bookArray,2,2,"Using a Compiler",2,33);
    setBook(bookArray,3,3,"A Taste of C",3,98);
    setBook(bookArray,4,4,"Why Learn C",1,876);
    //________________________________________________

    while(option != 6)
    {
         option = getInt("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE LIBRO

                freePlaceIndex = findEmptyPlace(bookArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }

                codeAux = getValidInt("Ingrese el codigo del libro: ","El codigo del libro debe ser numerico\n", 1, 15000);
                if(findBookByCode(bookArray,MAX_QTY,codeAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    break;
                }


                authorIdAux =  getValidInt("Ingrese el ID del autor del libro: ","El ID del autor debe ser numerico\n", 1, 500);

                stockAux = getValidInt("Ingrese la cantidad de libros: ","La cantidad debe ser numerica\n", 1, 10000);

                getValidString("Ingrese el titulo: ","El titlo debe estar compuesto solo por letras\n", titleAux);

                setBook(bookArray,freePlaceIndex,codeAux,titleAux,authorIdAux,stockAux);

                break;

            case 2: // BAJA

                codeAux = getValidInt("Ingrese el codigo de libro a dar de baja: ","El codigo del libro debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(bookArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    break;
                }
                bookArray[foundIndex].status = 0;
                break;

            case 3: // MODIFICAR


                codeAux = getValidInt("Ingrese el codigo del libro a modificar: ","El codigo del libro debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(bookArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    break;
                }


                authorIdAux =  getValidInt("Ingrese el ID del autor del libro: ","El ID del autor debe ser numerico\n", 1, 500);

                stockAux = getValidInt("Ingrese la cantidad de libros: ","La cantidad debe ser numerica\n", 1, 10000);

                getValidString("Ingrese el titulo: ","El titulo debe estar compuesto solo por letras\n", titleAux);

                setBook(bookArray,foundIndex,codeAux,titleAux,authorIdAux,stockAux);

                break;

            case 4: // LISTAR
                showArray(bookArray,MAX_QTY);

                break;

            case 5: // ORDENAR
                orderArrayByTitle(bookArray,MAX_QTY);
                break;


         }
    }


    return 0;
}
