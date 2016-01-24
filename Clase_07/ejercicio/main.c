/******************************************************************
* Programa: Ejemplo Clase 7
*
* Objetivo:
*   Realizar una agenda para guardar los datos de hasta 200 personas
*   de las cuales se toman los siguientes datos:
*       Nombre
*       Apellido
*       legajo (NO SE PUEDE REPETIR)
*
*   a- Realizar un programa con un menú de opciones para hacer altas ,
*      bajas y modificaciones (ABM) de una agenda.
*   b- Mostrar un listado ordenado por Apellido
*
* Aspectos a destacar:
*   Manipulación y chequeo de cadena de caracteres
*   arrays paraleos
*   bajas logicas
*
* Version: 0.1 del 01 enero de 2016
* Autor: Mauricio
*
* *******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"

#define QTY_CLIENTES 200

void inicializarArrayInt(int array[],int cantidad_de_elementos,int valor);
int buscarPrimerOcurrencia(int array[],int cantidad_de_elementos,int valor);


int main()
{
    // arrays paralelos donde se guarda la información
    char arrayNombres[QTY_CLIENTES][50];
    char arrayApellidos[QTY_CLIENTES][50];
    int arrayLegajos[QTY_CLIENTES] ;
    //_________________________________________________

    char auxiliarNombreStr[50];
    char auxiliarApellidoStr[50];
    char auxiliarLegajoStr[50];
    int auxiliarLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i,j;

    inicializarArrayInt(arrayLegajos,QTY_CLIENTES,-1); /**< Se indica con -1 que esa posicion esta vacia */
    while(opcion != 6)
    {
         opcion = getInt("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n\n");
         switch(opcion)
         {
            case 1:

                indiceLugarLibre = buscarPrimerOcurrencia(arrayLegajos,QTY_CLIENTES,-1);
                if(indiceLugarLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }

                printf("\nALTA\n");
                if (!getStringLetras("Ingrese el nombre: ",auxiliarNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxiliarApellidoStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese el legajo: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                auxiliarLegajo = atoi(auxiliarLegajoStr);

                if(buscarPrimerOcurrencia(arrayLegajos,QTY_CLIENTES,auxiliarLegajo) != -1)
                {
                    printf("\n\nEL LEGAJO YA EXISTE!!!\n");
                    break;
                }


                strcpy(arrayNombres[indiceLugarLibre],auxiliarNombreStr);
                strcpy(arrayApellidos[indiceLugarLibre],auxiliarApellidoStr);
                arrayLegajos[indiceLugarLibre] = auxiliarLegajo;

                break;

            case 2:
                if (!getStringNumeros("Ingrese el legajo a dar de baja: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayLegajos,QTY_CLIENTES,atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }
                arrayLegajos[indiceResultadoBusqueda]=-1;
                break;

            case 3:
                if (!getStringNumeros("Ingrese el legajo a modificar: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }

                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayLegajos,QTY_CLIENTES,atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }

                if (!getStringLetras("Ingrese el nombre: ",auxiliarNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxiliarApellidoStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                strcpy(arrayNombres[indiceResultadoBusqueda],auxiliarNombreStr);
                strcpy(arrayApellidos[indiceResultadoBusqueda],auxiliarApellidoStr);

                break;

            case 4:
                printf("\nLISTAR\n");
                for(i=0;i < QTY_CLIENTES; i++)
                {
                    if(arrayLegajos[i] != -1)
                    {
                        printf("\n%s - %s - %d",arrayNombres[i],arrayApellidos[i],arrayLegajos[i]);
                    }
                }
                break;

            case 5:
                printf("\nORDENADO\n");

                for(i=0; i < QTY_CLIENTES - 1; i++)
                {
                    if(arrayLegajos[i] == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < QTY_CLIENTES; j++)
                    {
                        if(arrayLegajos[j] == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayApellidos[i],arrayApellidos[j]))
                        {
                            strcpy(auxiliarNombreStr,arrayNombres[i]);
                            strcpy(arrayNombres[i],arrayNombres[j]);
                            strcpy(arrayNombres[j],auxiliarNombreStr);

                            strcpy(auxiliarApellidoStr,arrayApellidos[i]);
                            strcpy(arrayApellidos[i],arrayApellidos[j]);
                            strcpy(arrayApellidos[j],auxiliarApellidoStr) ;

                            auxiliarLegajo = arrayLegajos[i];
                            arrayLegajos[i] = arrayLegajos[j];
                            arrayLegajos[j] = auxiliarLegajo;
                        }
                    }
                }
                break;


         }
    }


    return 0;
}

/**
 * \brief Inicializa un array de enteros con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidad_de_elementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posicion
 * \return -
 *
 */
void inicializarArrayInt(int array[],int cantidad_de_elementos,int valor)
{
    int i;
    for(i=0;i < cantidad_de_elementos; i++)
    {
        array[i] = valor;
    }
}

/**
 * \brief Busca la primer ocurrencia de un valor en un array de enteros
 * \param array Es el array en el cual buscar
 * \param cantidad_de_elementos Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int buscarPrimerOcurrencia(int array[],int cantidad_de_elementos,int valor)
{
    int i;
    for(i=0;i < cantidad_de_elementos; i++)
    {
        if(array[i] == valor)
        {
            return i;
        }
    }
    return -1;
}


