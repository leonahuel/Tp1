#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    float nro1=0, nro2=0;
    float resultado = 0;
    int flag1=0, flag2=0;

    do
    {
        system("cls");

        if (flag1 == 0)
        {
        printf("\n1- Ingresar 1er numero(n1 = %.2f): ", nro1);
        scanf("%f", &nro1);
        flag1=1;
        }

        if (flag2 == 0)
        {
        printf("\n2- Ingresar 2do numero (n2 = %.2f): ", nro2);
        scanf("%f", &nro2);
        flag2=1;
        }


        printf("\n  1- Ingresar 1er numero(nro1 = %2.2f) ", nro1);
        printf("\n  2- Ingresar 2do numero (nro2 = %2.2f) ", nro2);
        printf("\n  3- sumar + ");
        printf("\n  4- restar - ");
        printf("\n  5- dividir / ");
        printf("\n  6- multiplicar * ");
        printf("\n  7- factorial ");
        printf("\n  8- todas las operaciones ");
        printf("\n  9- Salir\n");


        printf("\nElija la opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\n1- Ingresar 1er numero(nro1 = %.2f): ", nro1);
                scanf("%f", &nro1);
                break;

            case 2:
                printf("\n2- Ingresar 2do numero (nro2 = %.2f): ", nro2);
                scanf("%f", &nro2);
                break;

            case 3:
                resultado = sumar (nro1,nro2);
                printf ("\nEl resultado de la suma es: %.2f\n\n", resultado);
                system("pause");
                break;
            case 4:
                resultado = restar (nro1,nro2);
                printf ("\nEl resultado de la resta es: %.2f\n\n", resultado);
                system("pause");
                break;
            case 5:
                while(nro1 == 0 && nro2 == 0)
                {
                    printf(" error. reingrese numeros\n");

                    printf("\nIngresar 1er numero (nro1 = %.2f): ", nro1);
                    scanf("%f", &nro1);

                    printf("\nIngresar 2do numero (nro2 = %.2f): ", nro2);
                    scanf("%f", &nro2);
                }
                while(nro1 != 0 && nro2 == 0)
                    {
                        printf(" error. reingrese numeros\n");

                        printf("\nIngresar 1er numero (nro1 = %.2f): ", nro1);
                        scanf("%f", &nro1);

                        printf("\nIngresar 2do numero (nro2 = %.2f): ", nro2);
                        scanf("%f", &nro2);
                    }

                resultado = dividir (nro1,nro2);
                printf ("\nEl resultado de la division es: %.2f\n\n", resultado);

                system("pause");
                break;
            case 6:
                resultado = multiplicar (nro1,nro2);
                printf ("\nEl resultado de la multiplicacion es: %.2f\n\n", resultado);
                system("pause");
                break;
            case 7:
                resultado = factorial (nro1);
                printf ("\nEl factorial de nro1 es: %.2f\n\n", resultado);
                system("pause");
                break;
            case 8:
                resultado = sumar (nro1,nro2);
                printf ("\nEl resultado de la suma es: %.2f\n\n", resultado);

                resultado = restar (nro1,nro2);
                printf ("\nEl resultado de la resta es: %.2f\n\n", resultado);

                resultado = multiplicar (nro1,nro2);
                printf ("\nEl resultado de la multiplicacion es: %.2f\n\n", resultado);

                resultado = factorial (nro1);
                printf ("\nEl factorial de nro1 es: %.2f\n\n", resultado);

                system("pause");
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }while(seguir=='s');


    return 0;
}
