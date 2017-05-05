#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"


static int usuarios_findEmptyPlace(sUsuario* pUsuarios, int length);
static int usuarios_findNextId(sUsuario* pUsuarios, int length);

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int usuarios_init(sUsuario* pUsuarios, int length)
{
    int i;
    int retorno=-1;
    if(pUsuarios != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            (pUsuarios+i)->flagEstado = USUARIOS_EMPTY;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Agrega a la lista de usuarios un nuevo elemento, el id no lo recibe lo calcula
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \param numero int Numero del usuario
 * \param nombre[] char Nombre del usuario
 * \param apellido[] char
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int usuarios_append(sUsuario* pUsuarios, int length, int numero, char nombre[],char apellido[])
{

    int retorno=-1;
    int id,index;
    if(pUsuarios != NULL && length > 0)
    {
        index = usuarios_findEmptyPlace(pUsuarios, length);
        if(index != -1)
        {
            id = usuarios_findNextId(pUsuarios, length);
            strcpy((pUsuarios+index)->nombre,nombre);
            strcpy((pUsuarios+index)->apellido,apellido);
            (pUsuarios+index)->numero = numero;
            (pUsuarios+index)->idUsuario = id;
            (pUsuarios+index)->flagEstado = USUARIO_USED;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Busca en la lista un usuario que coincida con el Id recibido
 *
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \param idUsuario int ID del usuario
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el usuario] - (0) si Ok
 *
 */
sUsuario* usuarios_find(sUsuario* pUsuarios, int length, int idUsuario)
{
    sUsuario* pRetorno = NULL;
    int i;
    if(pUsuarios != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pUsuarios+i)->idUsuario == idUsuario && (pUsuarios+i)->flagEstado == USUARIO_USED)
            {
                pRetorno = (pUsuarios+i);
                break;
            }
        }
    }
    return pRetorno;
}


/** \brief Elimina de manera logica un usuario de la lista
 *         colocando el flag de flagEstado en TRUE
 *
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \param idUsuario int ID del usuario
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el usuario]
 *                    ( 0) si Ok
 *
 */
int usuarios_remove(sUsuario* pUsuarios, int length, int idUsuario)
{
    sUsuario* pAuxUsuario;
    int retorno = -1;

    pAuxUsuario = usuaros_find(pUsuarios, length, idUsuario);
    if(pAuxUsuario != NULL)
    {
        pAuxUsuario->flagEstado = USUARIO_DELETE;
        retorno = 0;
    }

    return retorno;
}


/** \brief Modifica el nombre y el apellido de un usuario existente
 *
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \param idUsuario int ID del usuario
 * \param nombre int Nombre del usuario
 * \param apellido int Apellido del usuario
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o si la longitud del nombre/apellido es < 1] - (0) si Ok
 *
 */
int usuarios_update(sUsuiaro* pUsuarios, int length, int idUsuario, char* nombre, char* apellido)
{
    int retorno=-1;
    sUsuario* pAuxUsuario;

    if(pUsuarios!= NULL && length > 0)
    {
        pAuxUsuario = usuarios_find(pUsuarios, length,idUsuario);
        if(pAuxUsuario!= NULL)
        {
            strcpy(pAuxUsuario->nombre,nombre);
            strcpy(pAuxUsuario->apellido,apellido);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief  Busca en el array la primer posicion libre
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
static int usuarios_findEmptyPlace(sUsuario* pUsuarios, int length)
{
    int i;
    int retorno=-1;
    if(pUsuarios != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pUsuarios+i)->flagEstado == USUARIO_EMPTY)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}


/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
static int usuarios_findNextId(sUsuario* pUsuarios, int length)
{
    int i, maxId=-1;
    int retorno=-1;
    if(pUsuarios != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pUsuarios+i)->flagEstado == USUARIO_USED || (pUsuarios+i)->flagEstado == USUARIO_DELETE)
            {
                if((pUsuarios+i)->idUsuario > maxId || maxId == -1)
                    maxId = (pUsuarios+i)->idUsuario;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}
