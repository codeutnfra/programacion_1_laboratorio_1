/******************************************************************
* Programa: Ejemplo Clase 8
*
* Objetivo:
*   Realizar una agenda para guardar los datos de hasta 200 personas
*   de las cuales se toman los siguientes datos:
*       Nombre
*       Apellido
*       legajo (NO SE PUEDE REPETIR)
*   Usar una estructura para representar a la persona.
*
*   a- Realizar un programa con un menú de opciones para hacer altas ,
*      bajas y modificaciones (ABM) de una agenda.
*   b- Mostrar un listado ordenado por Apellido
*
* Aspectos a destacar:
*   Manipulación y chequeo de cadena de caracteres
*   estructuras
*   bajas logicas
*
* Version: 0.1 del 01 enero de 2016
* Autor: Mauricio Dávila
* Revision: Ernesto Gigliotti
*
* *******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"

#define QTY_PERSONAS 200

typedef struct{
    char nombre[50];
    char apellido[50];
    int legajo;
}Persona;

void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor);



int main()
{
    // arrays de clientes
    Persona arrayPersonas[QTY_PERSONAS];
    //_________________________________________________
    Persona auxiliarCliente;

    char auxiliarNombreStr[50];
    char auxiliarApellidoStr[50];
    char auxiliarLegajoStr[50];
    int auxiliarLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i,j;

    inicializarArrayPersonas(arrayPersonas,QTY_PERSONAS,-1); /**< Se indica con -1 que esa posicion esta vacia */
    while(opcion != 6)
    {
         opcion = getInt("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n\n");
         switch(opcion)
         {
            case 1:

                indiceLugarLibre = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,-1);
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

                if(buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,auxiliarLegajo) != -1)
                {
                    printf("\n\nEL LEGAJO YA EXISTE!!!\n");
                    break;
                }


                strcpy(arrayPersonas[indiceLugarLibre].nombre,auxiliarNombreStr);
                strcpy(arrayPersonas[indiceLugarLibre].apellido,auxiliarApellidoStr);
                arrayPersonas[indiceLugarLibre].legajo = auxiliarLegajo;

                break;

            case 2:
                if (!getStringNumeros("Ingrese el legajo a dar de baja: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }
                arrayPersonas[indiceResultadoBusqueda].legajo=-1;
                break;

            case 3:
                if (!getStringNumeros("Ingrese el legajo a modificar: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }

                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,atoi(auxiliarLegajoStr));

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

                strcpy(arrayPersonas[indiceResultadoBusqueda].nombre,auxiliarNombreStr);
                strcpy(arrayPersonas[indiceResultadoBusqueda].apellido,auxiliarApellidoStr);

                break;

            case 4:
                printf("\nLISTAR\n");
                for(i=0;i < QTY_PERSONAS; i++)
                {
                    if(arrayPersonas[i].legajo != -1)
                    {
                        printf("\n%s - %s - %d",arrayPersonas[i].nombre,arrayPersonas[i].apellido,arrayPersonas[i].legajo);
                    }
                }
                break;

            case 5:
                printf("\nORDENADO\n");

                for(i=0; i < QTY_PERSONAS - 1; i++)
                {
                    if(arrayPersonas[i].legajo == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < QTY_PERSONAS; j++)
                    {
                        if(arrayPersonas[j].legajo == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayPersonas[i].apellido,arrayPersonas[j].apellido) > 0)
                        {
                            auxiliarCliente = arrayPersonas[j];
                            arrayPersonas[j] = arrayPersonas[i];
                            arrayPersonas[i] = auxiliarCliente;
                        }
                    }
                }
                break;
         }
    }


    return 0;
}

/**
 * \brief Inicializa un array de Personas con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posición
 * \return void
 *
 */
void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayPersonas[i].legajo = valor;
    }
}

/**
 * \brief Busca la primer ocurrencia de un valor en un array de Personas
 * \param array Es el array en el cual buscar
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayPersonas[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}


