#include <stdio.h>
#include <stdlib.h>
#include "../clases-programacion-laboratorio-master/utn.h"

int main()
{
    char nombre[STRINGLEN];
    int resultado = utn_getNombre(nombre,"Ingrese un nombre:","Error, reingrese",3);
    if(resultado == 0)
    {
        printf("\nEl nombre ingresado es %s", nombre);
    }
    else
    {
        printf("Se agotaron los intentos");

    }
    return 0;
}
