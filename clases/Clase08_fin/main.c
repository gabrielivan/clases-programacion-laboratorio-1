#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


#define CANTIDAD_EMPLEADOS 3
typedef struct sEmpleado
{
    char nombre[50];
    char apellido[50];
    float salario;
}Empleado;



void sortEmpleadosPorNombre(Empleado* pEmpleado,int limite)
{
    int swap;
    int i;
    Empleado bufferEmpleado;
    do
    {
        swap = 0;
        for(i=0;i<limite-1;i++)
        {
            if(strcmp(pEmpleado[i].nombre,pEmpleado[i+1].nombre) > 0)
            {
                swap = 1;
                bufferEmpleado = pEmpleado[i];
                pEmpleado[i] = pEmpleado[i+1];
                pEmpleado[i+1] = bufferEmpleado;
            }
        }
    }while(swap);


}



void ordenarPorNombre(char pNombres[][50],char pApellidos[][50],char pDni[][50], int limite)
{
    int swap;
    int i;
    char bufferStr[256];
    do
    {
        swap = 0;
        for(i=0;i<limite-1;i++)
        {
          if(strcmp(pNombres[i],pNombres[i+1]) > 0)
            {
            swap = 1;
            strcpy(bufferStr,pNombres[i]);
            strcpy(pNombres[i],pNombres[i+1]);
            strcpy(pNombres[i+1],bufferStr);

            strcpy(bufferStr,pApellidos[i]);
            strcpy(pApellidos[i],pApellidos[i+1]);
            strcpy(pApellidos[i+1],bufferStr);

            strcpy(bufferStr,pDni[i]);
            strcpy(pDni[i],pDni[i+1]);
            strcpy(pDni[i+1],bufferStr);

            }
        }
    }while(swap);
}



int main()
{
    char nombres[CANTIDAD_EMPLEADOS][50] = {"AAA","CCC","BBB"};
    char apellidos[CANTIDAD_EMPLEADOS][50] = {"AAA","CCC","BBB"};
    char dni[CANTIDAD_EMPLEADOS][50] = {"AAA","CCC","BBB"};

    Empleado arrayEmpleados[CANTIDAD_EMPLEADOS];
    Empleado* pEmpleado;
    pEmpleado = arrayEmpleados;

    strcpy(arrayEmpleados[1].apellido, "LOPEZ");
    strcpy((pEmpleado+1)->apellido, "GOMEZ");

    int i;

    /*for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        utn_getNombre(nombres[i],50,"\nNombre?","\nError",2);
    }*/

    ordenarPorNombre(nombres,apellidos,dni,CANTIDAD_EMPLEADOS);

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("\n%s - %s - %s\n",nombres[i],apellidos[i],dni[i]);
    }
    return 0;
}






