#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Productos.h"


static int productos_findEmptyPlace(sProducto* pProductos, int length);
static int productos_findNextId(sProducto* pProductos, int length);


/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sProducto* pProductos Puntero al array de Productos
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int productos_init(sProducto* pProductos, int length)
{
    int i;
    int retorno=-1;
    if(pProductos != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            (pProductos+i)->flagEstado = PRODUCTO_EMPTY;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Agrega a la lista de productos un nuevo producto, fija el estado como "Publicado"
 * \param sProductos* pProducto Puntero al array de Productos
 * \param length int Longitud del array
 * \param idProducto int Id del producto
 * \param nombre del usuario
 * \param precio del producto
 * \param stock
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int productos_open(sProducto* pProductos, int length, int idUsuario, int nombre, int precio, int stock)
{

    int retorno=-1;
    int id,index;
    if(pProductos!= NULL && length > 0)
    {
        index = productos_findEmptyPlace(pProductos, length);
        if(index != -1)
        {
            id = productos_findNextId(pProductos, length);
            (pProductos+index)->estado = ENCURSO;
            (pLlamadas+index)->idProducto = id;
            (pLlamadas+index)->idUsuario = idUsuario;
            (pLlamadas+index)->nombre = nombre;
            (pLlamadas+index)->precio = precio;
            (pLlamadas+index)->stock = stock;
            (pLlamadas+index)->flagEstado = PRODUCTO_USED;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Busca en la lista una producto que coincida con el Id recibido
 *
 * \param sProductos* pProducto Puntero al array de Productos
 * \param length int Longitud del array
 * \param idProductos int Id de productos buscado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el producto] - (0) si Ok
 *
 */
sLlamada* productos_find(sProducto* pProductos, int length, int idProducto)
{
    sProducto* pRetorno = NULL;
    int i;
    if(pProductos != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pProductos+i)->idProducto == idProducto && (pProductos+i)->flagEstado == PRODUCTO_USED)
            {
                pRetorno = (pProductos+i);
                break;
            }
        }
    }
    return pRetorno;
}


/** \brief Cancela una Publicacion Cargada
 * \param sProductos* pProducto Puntero al array de Productos
 * \param length int Longitud del array
 * \param idUsuario int Id del usuario que realiza la carga del  producto
 * \param nombre del usuario
 * \param precio del producto
 * \param cantidad de productos vendidos
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int productos_close(sProducto* pProductos, int length, int idProducto, int nombre , int precio, int CantidadVendida, int Stock );
{
    int retorno=-1;
    sProducto* pAuxProducto;

    if(pProductos != NULL && length > 0)
    {
        pAuxProducto = productos_find(pProductos, length,idProducto,nombre,precio,CantidadVendida,stock);
        if(pAuxProducto != NULL)
        {
            pAuxProducto->nombre = nombre;
            pAuxProducto->precio = precio;
            pAuxProducto->antidadVendida = antidadVendida;
            pAuxProducto->stock = stock;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief  Busca en el array la primer posicion libre
 * \param sProducto* pProductos Puntero al array de productos
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
static int productos_findEmptyPlace(sProducto* pProductos, int length)
{
    int i;
    int retorno=-1;
    if(pProductos != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pProductos+i)->flagEstado == PRODUCTO_EMPTY)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}


