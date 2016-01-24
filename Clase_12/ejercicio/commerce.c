#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "commerce.h"


/**
 * \brief Inicializa el status en un array de productos
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a estatus
 * \return -
 *
 */
void setStatus(Product productArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        productArray[i].status = value;
    }
}

/**
 * \brief Busca la primer ocurrencia de un producto mediante su codigo
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findProductByCode(Product productArray[],int arrayLenght,int code)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(productArray[i].code == code && productArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findEmptyPlace(Product productArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(productArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca el precio mas bajo del array de productos
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay productos activos (-1) y si lo hay el precio de ese producto
 *
 */
float getCheaperPrice(Product productArray[],int arrayLenght)
{
    int i;
    float cheaperPrice = -1;

    for(i=0;i < arrayLenght; i++)
    {
        if(productArray[i].status == 1)
        {
            cheaperPrice = productArray[i].price;
            break;
        }
    }

    if(cheaperPrice == -1) /**< Si se cumple indica que no existen productos activos en el array */
        return -1;

    for(i=0;i < arrayLenght; i++)
    {
        if(cheaperPrice > productArray[i].price && productArray[i].status == 1)
        {
            cheaperPrice = productArray[i].price;
        }
    }

    return cheaperPrice;
}

/**
 * \brief Busca el precio promedio
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay productos activos (-1) y si lo hay el precio de ese producto
 *
 */
float getAveragePrice(Product productArray[],int arrayLenght)
{
    int i;
    float totalPrice = 0;
    int activeProducts = 0;

    for(i=0;i < arrayLenght; i++)
    {
        if(productArray[i].status == 1)
        {
            totalPrice = totalPrice + productArray[i].price;
            activeProducts++;
        }
    }
    if(activeProducts == 0)
        return -1;

    return (totalPrice / (float)activeProducts);
}

/**
 * \brief Busca el precio promedio
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay productos activos (-1) y si lo hay el precio de ese producto
 *
 */
void orderArrayByDescription(Product productArray[],int arrayLenght)
{
    Product productAux;
    int i,j;

    for(i=0; i < MAX_QTY - 1; i++)
    {
        if(productArray[i].status == 0)
        {
            continue;
        }
        for(j=i+1; j < MAX_QTY; j++)
        {
            if(productArray[j].status == 0)
            {
                continue;
            }
            if(strcmp(productArray[j].description,productArray[i].description) > 0)
            {
                productAux = productArray[j];
                productArray[j] = productArray[i];
                productArray[i] = productAux;
            }
            else if(strcmp(productArray[j].description,productArray[i].description) == 0)
            {
                if(productArray[i].qty > productArray[j].qty)
                {
                    productAux = productArray[j];
                    productArray[j] = productArray[i];
                    productArray[i] = productAux;
                }
            }
        }
    }
}
