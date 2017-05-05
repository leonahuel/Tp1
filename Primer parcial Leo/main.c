#include <stdio.h>
#include <stdlib.h>
#include "Leo.h"





#define USUARIOS_CANTIDAD 100
#define PRODUCTOS_CANTIDAD 1000

int main()
{
    int menuOpcionElegida;
    char menuPrinsipalMensaje[] =
                "\n1-Alta de usuario\
                 \n2-Modificar datos del usuario\
                 \n3-Baja del usuario\
                 \n4-Publicar Producto\
                 \n5-Modificar Publicacion\
                 \n6-Cancelar Publicacion\
                 \n7-Comprar Producto\
                 \n8-Listar Publicaciones de Usuario\
                 \n9-Listar Publicaciones\n\
                 \n10-Listar Usuarios\n\
                 \n11-Salir\n\
                 \nIngrese opcion: ";
    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 10";


    //Se crea el array de Usuarios y se inicializa
    sUsuario arrayUsuarios[USUARIOS_CANTIDAD];
    usuarios_init(arrayUsuarios,USUARIOS_CANTIDAD);

    //Se crea el array de Productos y se inicializa
    sProducto arrayProductos[PRODUCTOS_CANTIDAD];
    productos_init(arrayProductos,PRODUCTOS_CANTIDAD);



    // Carga datos de test
    controller_mock(arrayUsuarios,USUARIOS_CANTIDAD,arrayProductos, PRODUCTOS_CANTIDAD);

    do
    {
        clearScreen();
        menuOpcionElegida = 0;
        getValidInt(menuPrinsipalMensaje,menuPrinsipalMensajeError, &menuOpcionElegida , 0 , 9 , 2 );

        switch(menuOpcionElegida)
        {
        case 1: // ALTA USUARIO
            controller_altaUsuario(arrayUsuarios,USUARIOS_CANTIDAD);
            break;
        case 2: // MODIFICAR USUARIO
            controller_modificarUsuario(arrayUsuarios,USUARIOS_CANTIDAD);
            break;
        case 3: // BAJA USUARIO
            controller_bajaUsuario(arrayUsuarios,USUARIOS_CANTIDAD);
            break;
        case 4: // PUBLICAR PRODUCTO
            controller_publicarProducto(arrayProductos, PRODUCTOS_CANTIDAD,arrayUsuarios,USUARIOS_CANTIDAD);
            break;
        case 5: // MODIFICAR PUBLICACION
            controller_modificarPublicacion(arrayProductos, PRODUCTOS_CANTIDAD);
            break;
        case 6: // CANCELAR PRODUCTO
            controller_informeUsuario(arrayProductos, PRODUCTOS_CANTIDAD);
            controller_cancelarProducto(arrayProductos, PRODUCTOS_CANTIDAD);
            break;
        case 7: // COMPRA PRODUCTO
            controller_comprarProducto(arrayProductos, PRODUCTOS_CANTIDAD);

            break;
        case 8: // LISTAR PUBLICACIONES DE USUARIO
            controller_listarPublicacionesDeUsuario(arrayProductos,PRODUCTOS_CANTIDAD,arrayUsuarios,USUARIOS_CANTIDAD  );
            pause();
            break;
        case 9: //LISTAR PUBLICACIONES
            controller_listarPublicaciones(arrayProductos,PRODUCTOS_CANTIDAD);
            pause();
            break;
        case 10: //LISTAR USUARIOS
            controller_listarUsuarios(arrayUsuarios,USUARIOS_CANTIDAD);
            pause();
            break;
        case 11:
            //Salir
            break;
        default:
            printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
            pause();
            break;
        }

    }while(menuOpcionElegida != 11);

    return 0;
}
