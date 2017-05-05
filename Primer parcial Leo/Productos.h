#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

    #define PRODUCTO_EMPTY 0
    #define PRODUCTO_USED 1


    typedef struct
    {
        int idProducto;
        int idUsuario;
        int nombre;
        int precio;
        int stock;
        int cantidadVendida;
        int flagEstado;

    }sProducto;

#endif // PRODUCTO_H_INCLUDED

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sProductos* pProducto Puntero al array de Productos
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int productos_init(sProducto* pProductos, int length);

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
int productos_open(sProducto* pProductos, int length, int idUsuario, int nombre, int precio, int stock );

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


/** \brief Busca en la lista una producto que coincida con el Id recibido
 *
 * \param sProductos* pProducto Puntero al array de Productos
 * \param length int Longitud del array
 * \param idProductos int Id de productos buscado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el producto] - (0) si Ok
 *
 */
sProducto* productos_find(sProducto* pProductos, int length, int idProducto);




