#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDE

#define USUARIO_EMPTY 0
    #define USUARIO_USED 1
    #define USUARIO_DELETE 2

    typedef struct
    {
        unsigned int idUsuario;
        unsigned int numero;
        char nombre[50];
        char apellido[50];
        int flagEstado;

    }sUsuario;

    #endif //ABONADO_H_INCLUDED

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int usuarios_init(sUsuario* pUsuarios, int length);

/** \brief Agrega a la lista de usuarios un nuevo elemento, el id no lo recibe lo calcula
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \param numero int Numero del usuario
 * \param nombre[] char Nombre del usuario
 * \param apellido[] char
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int usuarios_append(sUsuario* pUsuarios, int length, int numero, char nombre[],char apellido[]);


/** \brief Busca en la lista un usuario que coincida con el Id recibido
 *
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \param idUsuario int ID del usuario
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el usuario] - (0) si Ok
 *
 */
sUsuario* usuarios_find(sUsuario* pUsuarios, int length, int idUsuario);


/** \brief Elimina de manera logica un usuario de la lista
 *         colocando el flag de flagEstado en TRUE
 *
 * \param sUsuario* pUsuarios Puntero al array de usuarios
 * \param length int Longitud del array
 * \param idUsuarios int ID del usuario
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el usuario] - (0) si Ok
 *
 */
int usuarios_remove(sUsuario* pUsuarios, int length, int idUsuario);


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
int usuarios_update(sUsuario* pUsuarios, int length, int idUsuario, char* nombre, char* apellido);


