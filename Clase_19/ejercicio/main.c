/******************************************************************
* Programa: Ejemplo Clase 19
*
* Objetivo:

 Realizar un programa que permita ingresar los datos de una persona (usar funciones de utn.h):
    char name[32];
    char surname[32];
    int age;

    1) Crear un archivo binario llamado BIN.DAT el cual contendrá estructuras con los campos anteriores y guardar al
    final del mismo la estructura con los datos ingresados. Luego se preguntará si se desea agregar mas datos o salir.

    2) Utilizando el archivo BIN.DAT (se supone que tiene datos válidos cargados), realizar un programa que permita buscar
    un apellido que ingresa el usuario y una vez encontrado muestre los datos en pantalla. De no encontrar el nombre se
    debe informar por medio de un mensaje de error.
*
* Aspectos a destacar:
*
*   Uso de archivos. Uso de memoria dinámica.
*
* Version: 0.1 del 09 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

struct S_Person
{
    char name[32];
    char surname[32];
    int age;
};

/** \brief Pide al usuario los datos y los guarda en la struct
 * \param struct S_Person* p puntero a struct donde se almacenan los datos ingresados
 * \return void
 */
void loadData(struct S_Person* p)
{
    getString("Ingrese el nombre:",p->name);
    getString("Ingrese el apellido:",p->surname);
    p->age=getInt("Ingrese la edad:");
}



/** \brief Guarda una struct al final de un archivo binario bin.dat
 * \param struct S_Person* p puntero a struct a ser escrita
 * \return 0: error, 1:OK
 */
int savePerson(struct S_Person* p)
{
    FILE* fp;
    fp=fopen("bin.dat","ab+"); // append binario, lo crea si no existe
    if(fp==NULL)
    {
        printf("Error opening file");
        return 0;
    }
    fwrite(p,sizeof(struct S_Person),1,fp); // escribo una struct al final

    fclose(fp);
    return 1;
}




/** \brief Busca en el archivo la struct con el apellido pasado como argumento y la devuelve
 * \param char* surname apellido
 * \return Puntero a struct que se leyo del archivo o NULL si no existe el apellido
 */
struct S_Person* readPerson(char* surname)
{
    FILE* fp;
    fp=fopen("bin.dat","rb"); // lectura binaria
    if(fp==NULL)
    {
        printf("Error opening file");
        return NULL;
    }

    struct S_Person* pRet = malloc(sizeof(struct S_Person));
    int flagFound=0;
    while(fread(pRet,sizeof(struct S_Person),1,fp)!=0)
    {
        //printf("Leo %s %s %d\r\n",pRet->name,pRet->surname,pRet->age);
        if(strcmp(surname,pRet->surname)==0)
        {
            flagFound=1;
            break;
        }
    }
    fclose(fp);
    if(flagFound)
        return pRet;
    free(pRet);
    return NULL;
};

int main()
{
    struct S_Person p;
    char out='s';
    while(out=='s')
    {
        loadData(&p);
        savePerson(&p);
        out = getChar("Ingresar uno nuevo? s/n:");
    }

    char surnameToFind[64];
    getString("Ingrese apellido a buscar en archivo:",surnameToFind);

    struct S_Person* pFound = readPerson(surnameToFind);

    if(pFound!=NULL)
    {
        printf("Se encontro: nombre:%s apellido:%s edad:%d\r\n",pFound->name,pFound->surname,pFound->age);
        free(pFound);
    }
    else
        printf("el apellido ingresado no esta en el archivo");

    return 0;
}
