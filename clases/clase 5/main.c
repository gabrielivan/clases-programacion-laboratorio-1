#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../arrayLib/array.h"
#include "../utnLib/utn.h"

#define CANTIDAD_EMPLEADOS 6

int main()
{
    int edades[CANTIDAD_EMPLEADOS] = {50,10,30,1,10,22};

/*
    int i;
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"\nEdad?","\nEdad fuera de rango",0,200)==-1)
        {
            edades[i] = DATO_INVALIDO;
        }
    }
*/
    int cantidad;
    char nombre[4];
    char bufferNombre[4097];
    scanf("%s",bufferNombre);
    cantidad = strlen(bufferNombre);

    strncpy(nombre,bufferNombre,3);
    printf("\n---> %s",nombre);




//    array_ordenar2(edades,CANTIDAD_EMPLEADOS,0);
//    array_mostrar(edades,CANTIDAD_EMPLEADOS);
    return 0;
}






