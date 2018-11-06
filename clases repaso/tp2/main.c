#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"
#define CANTIDAD_EMPLEADOS 1000

int main()
{
    int opcionMenu = 1;
    int i;
    float totalSalario;
    float promedioSalario;
    int contadorSalarioEmpleados = 0;
    int contadorEmpleados = 0;
    int flag = 0;
    Empleado arrayEmpleados[CANTIDAD_EMPLEADOS];
    empleado_init(arrayEmpleados,CANTIDAD_EMPLEADOS);

     while(opcionMenu >= 1 && opcionMenu < 5)
    {
        utn_getNumero(&opcionMenu,"\n1 - CARGAR UN EMPLEADO \n2 - MODIFICAR UN EMPLEADO \n3 - DAR DE BAJA UN EMPLEADO \n4 - INFORMES \n5 - SALIR\n\n",
                                    "Error,reingrese una opcion valilda: ",1,5,2);

         switch(opcionMenu)
         {
            case 1:
                empleado_alta(arrayEmpleados,CANTIDAD_EMPLEADOS);
                contadorEmpleados++;
                flag = 1;
                break;

            case 2:
               if(flag == 1)
               {
                   empleado_listar(arrayEmpleados,CANTIDAD_EMPLEADOS);
                   empleado_modificar(arrayEmpleados,CANTIDAD_EMPLEADOS);
               }
                else
                {
                    printf("\nNo hay datos cargados.\n");
                }

                break;

            case 3:
                if(flag == 1)
                {
                    empleado_listar(arrayEmpleados,CANTIDAD_EMPLEADOS);
                    empleado_baja(arrayEmpleados,CANTIDAD_EMPLEADOS);
                    contadorEmpleados--;
                }
                else
                {
                    printf("\nNo hay datos cargados.\n");
                }

                break;

            case 4:
                if(flag == 1)
                {
                    totalSalario = 0;
                    promedioSalario = 0;
                    contadorSalarioEmpleados = 0;

                    empleado_ordenarPorApellido(arrayEmpleados,CANTIDAD_EMPLEADOS);
                    empleado_ordenarPorSector(arrayEmpleados,CANTIDAD_EMPLEADOS);
                    empleado_listar(arrayEmpleados,CANTIDAD_EMPLEADOS);

                    for(i=0;i<CANTIDAD_EMPLEADOS;i++)
                    {
                        if(!arrayEmpleados[i].isEmpty)
                        {
                            totalSalario = totalSalario + arrayEmpleados[i].salario;
                        }
                    }
                    promedioSalario = totalSalario / contadorEmpleados;

                    for(i=0;i<CANTIDAD_EMPLEADOS;i++)
                    {
                        if(arrayEmpleados[i].salario > promedioSalario && !arrayEmpleados[i].isEmpty)
                        {
                            contadorSalarioEmpleados++;
                        }
                    }

                    printf("\nEl total de salarios es %.2f",totalSalario);
                    printf("\nEl promedio de salarios es %.2f",promedioSalario);
                    printf("\nEl total de empleados que superan el promedio es %d",contadorSalarioEmpleados);
                    printf("\n\n");
                }
                else
                {
                    printf("\nNo hay datos cargados.\n");
                }

                break;

            case 5: printf("Chau chau...");
            break;

            default: printf("error ingrese una opcion valida");
         }
    }

    return 0;

}
