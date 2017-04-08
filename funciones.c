#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float sumar (float nro1, float nro2)
{
    float suma;
    suma = nro1 + nro2;
    return suma;
}
float restar (float nro1, float nro2)
{
    float resta;
    resta = nro1 - nro2;
    return resta;
}

float dividir (float nro1, float nro2)
{
    float divi;
     divi = nro1 / nro2;
    return divi;
}

float multiplicar (float nro1, float nro2)
{
    float multi;
      multi = nro1 * nro2;
    return multi;
}

float factorial (float nro1)
{
    int i;
    float fac = 1;

    for(i=1; i <= nro1; i++)
        {
            fac = fac * i;
        }

    return fac;
}


