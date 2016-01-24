/******************************************************************
* Programa: Ejemplo Clase 12
*
* Objetivo Agregado:
*   Al ejercicio de la clase 11 incorporar la siguiente funcionalidad
*
*   5. LISTAR: Realizar un solo listado de los datos ordenados por
*              los siguientes criterios:
*       o Descripción (descendente)
*       o Cantidad (ascendente)
*   6. INFORMAR:
*       A. Los datos del/os producto/s de menor Importe.
*       B. Los datos del/os producto/s que superan el valor de precio promedio
*
*   7. MINIMIZAR:
*       Realizar las funciones necesarias a fin de minimizar la función main()
*
*******************************************************************
*******************************************************************
* Objetivo Original:
*   Un comercio necesita administrar sus productos, y para ello se
*   deberá realizar un programa de acuerdo a lo siguiente:
*
*   Datos:
*       Código de Producto (1 a 1000) (Validar)
*       Descripción (máximo 50 caracteres)  (Validar)
*       Importe (Validar)
*       Cantidad (Validar)
*
*   1. ALTAS: No es necesario el ingreso de todos los productos.
*   2. MODIFICAR: Se ingresará el Código de Producto, permitiendo modificar:
*       o Descripción
*       o Importe
*       o Cantidad
*   3. BAJA: Se ingresa el Código de Producto y se limpiarán los datos asociados
*   4. LISTAR: Realizar un solo listado de los datos ordenados por los siguientes criterios:
*       o Descripción (descendente)
*
* Aspectos a destacar:
*
*   manejo de menú
*   manejo de estructuras
*   funcion main() compacta
*   variables y funciones en Ingles
*
* Version: 0.1 del 04 enero de 2016
* Autor: Mauricio Dávila
* Revisión : Ernesto Gigliotti
*
* *******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "commerce.h"


int main()
{
    // arrays de productos
    Product productArray[MAX_QTY];
    //________________________________________________

    char descriptionAux[51];
    int codeAux;
    int qtyAux;
    float priceAux;

    char codeAuxStr[50];
    char qtyAuxStr[50];
    char priceAuxStr[50];

    int freePlaceIndex;
    int foundIndex;
    int option = 0;

    int i;

    setStatus(productArray,MAX_QTY,0);

    while(option != 7)
    {
         option = getInt("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - INFORMAR PRODUCTOS BARATOS\n6 - INFORMAR PRODUCTOS POR SOBRE EL PROMEDIO\n7 - SALIR\n\n\n");
         switch(option)
         {
            case 1:

                freePlaceIndex = findEmptyPlace(productArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }

                printf("\nALTA\n");

                if (!getStringNumeros("Ingrese el codigo: ",codeAuxStr))
                {
                    printf ("El codigo debe ser numerico\n");
                    break;
                }
                codeAux = atoi(codeAuxStr);

                if(findProductByCode(productArray,MAX_QTY,codeAux) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    break;
                }


                if (!getStringLetras("Ingrese la descripcion: ",descriptionAux))
                {
                    printf ("La descripcion debe estar compuesta solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese la cantidad: ",qtyAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                qtyAux = atoi(qtyAuxStr);

                if (!getStringNumerosFlotantes("Ingrese el valor: ",priceAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                priceAux = atof(priceAuxStr);

                productArray[freePlaceIndex].code = codeAux;
                strcpy(productArray[freePlaceIndex].description,descriptionAux);
                productArray[freePlaceIndex].price = priceAux;
                productArray[freePlaceIndex].qty = qtyAux;
                productArray[freePlaceIndex].status = 1;

                break;

            case 2:
                if (!getStringNumeros("Ingrese el codigo de producto a dar de baja: ",codeAuxStr))
                {
                    printf ("El codigo de producto debe ser numerico\n");
                    break;
                }
                codeAux = atoi(codeAuxStr);
                foundIndex = findProductByCode(productArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    break;
                }
                productArray[foundIndex].status = 0;
                break;

            case 3:
                if (!getStringNumeros("Ingrese el codigo de producto a modificar: ",codeAuxStr))
                {
                    printf ("El codigo de producto debe ser numerico\n");
                    break;
                }
                codeAux = atoi(codeAuxStr);
                foundIndex = findProductByCode(productArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    break;
                }



               if (!getStringLetras("Ingrese la descripcion: ",descriptionAux))
                {
                    printf ("La descripcion debe estar compuesta solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese la cantidad: ",qtyAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                qtyAux = atoi(qtyAuxStr);

                if (!getStringNumerosFlotantes("Ingrese el valor: ",priceAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                priceAux = atof(priceAuxStr);

                strcpy(productArray[foundIndex].description,descriptionAux);
                productArray[foundIndex].price = priceAux;
                productArray[foundIndex].qty = qtyAux;
                productArray[foundIndex].status = 1;
                break;

            case 4:
                printf("\nLISTAR\n");

                orderArrayByDescription(productArray,MAX_QTY);
                for(i=0;i < MAX_QTY; i++)
                {
                    if(productArray[i].status != 0)
                    {
                        printf("\n%d - %s - %d - %.2f",productArray[i].code,productArray[i].description,productArray[i].qty,productArray[i].price);
                    }
                }
                break;

            case 5:
                printf("\nINFORMAR PRODUCTOS MAS BARATOS\n");
                priceAux = getCheaperPrice(productArray,MAX_QTY);
                if(priceAux == -1)
                {
                     printf("\nNO HAY PRODUCTOS\n");
                     break;
                }
                for(i=0;i < MAX_QTY; i++)
                {
                    if(productArray[i].price == priceAux && productArray[i].status == 1)
                    {
                        printf("\n%d - %s - %d - %.2f",productArray[i].code,productArray[i].description,productArray[i].qty,productArray[i].price);
                    }
                }
                break;

            case 6:
                printf("\nINFORMAR PRODUCTOS POR ENCIMA DEL PROMEDIO\n");
                priceAux = getAveragePrice(productArray,MAX_QTY);
                if(priceAux == -1)
                {
                     printf("\nNO HAY PRODUCTOS\n");
                     break;
                }
                for(i=0;i < MAX_QTY; i++)
                {
                    if(productArray[i].price > priceAux && productArray[i].status == 1)
                    {
                        printf("\n%d - %s - %d - %.2f",productArray[i].code,productArray[i].description,productArray[i].qty,productArray[i].price);
                    }
                }
                break;

         }
    }


    return 0;
}


