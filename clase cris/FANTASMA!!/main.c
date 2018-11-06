#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#include "contrataciones.h"

#define PANTALLAS 5
#define CONTRATACIONES 5


int main()
{
    int opcionMenu = 1;
    int i;
    int idPantallaDeContratacionElegida;
    char cuitIngresado[14];
    float importeTotal;
    float importePantalla;
    int diasContratados;
    float precioPantalla;
    Pantalla* pantallaBuscada;

    Pantalla arrayPantallas[PANTALLAS];
    Contratacion arrayContrataciones[CONTRATACIONES];

    pantalla_init(arrayPantallas,PANTALLAS);
    contratacion_init(arrayContrataciones,CONTRATACIONES);

    pantalla_altaForzada(arrayPantallas,PANTALLAS,"Samsung","LasFlores",1000,1); //0 "20-91191191-5" "40-91191191-5"
    pantalla_altaForzada(arrayPantallas,PANTALLAS,"LG","Belgrano",1000,1); //1 "20-91191191-5"
    pantalla_altaForzada(arrayPantallas,PANTALLAS,"Lenovo","Cerrito",1000,1); //2 "30-91191191-5"
    pantalla_altaForzada(arrayPantallas,PANTALLAS,"Apple","Lavalle",1500,2); //3 "30-91191191-5"
    pantalla_altaForzada(arrayPantallas,PANTALLAS,"Huawey","Mitre",2000,2); //4"40-91191191-5"

    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,0,"videoavi","20-91191191-5",7);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,1,"videoavi","20-91191191-5",14);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,2,"videoavi","30-91191191-5",21);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,3,"videoavi","30-91191191-5",28);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,4,"videoavi","40-91191191-5",35);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,0,"videoavi","40-91191191-5",42);

    while(opcionMenu >= 1 && opcionMenu < 11)
    {
        utn_getNumero(&opcionMenu,"\n1 - CARGAR UNA PANTALLA \n2 - MODIFICAR UNA PANTALLA \n3 - DAR DE BAJA UNA PANTALLA \n4 - CARGAR UNA CONTRATACION \n5 - MODIFICAR UNA CONTRATACION \n6 - DAR DE BAJA UNA CONTRATACION \n7 - CONSULTAR FACTURACION \n8 - LISTAR CONTRATACIONES \n9 - LISTAR PANTALLAS \n10 - INFORMES \n11 - SALIR\n",
                                    "Error,reingrese una opcion valilda: ",1,11,2);

         switch(opcionMenu)
         {
            case 1:
                    pantalla_alta(arrayPantallas,PANTALLAS);
                    break;

            case 2:
                   pantalla_modificar(arrayPantallas,PANTALLAS);
                   break;

            case 3:
                   pantalla_baja(arrayPantallas,PANTALLAS);
                   break;

            case 4:
                    contratacion_alta(arrayContrataciones,arrayPantallas,CONTRATACIONES,PANTALLAS);
                    break;

            case 5:
                   contratacion_modificar(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS);
                   break;

            case 6:
                   contratacion_baja(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS);
                   break;

            case 7:
                    for(i=0;i<CONTRATACIONES;i++)
                    {
                        if(!arrayContrataciones[i].isEmpty)
                        {
                            printf("\nCLIENTE CUIT %s\n",arrayContrataciones[i].cuit);//te muestra todos los cuit que hay en el arrayde contrataciones
                        }
                    }

                utn_getCuit(cuitIngresado,"Ingrese su cuit: ","Error cuit invalido! ",2);
                importeTotal = 0;
                printf("\n CUIT %s \n",cuitIngresado);
                for(i=0;i<CONTRATACIONES;i++)
                {
                    if(!strncmp(arrayContrataciones[i].cuit,cuitIngresado,13))
                    {
                        idPantallaDeContratacionElegida = arrayContrataciones[i].pantallaId;
                        diasContratados = arrayContrataciones[i].dias;

                        pantallaBuscada = pantalla_getById(arrayPantallas,PANTALLAS,idPantallaDeContratacionElegida);
                        precioPantalla = pantallaBuscada->precio;

                        importePantalla = diasContratados * precioPantalla;
                        importeTotal += importePantalla;

                        printf("\nCUIT -- %s\nIMPORTE -- $%.2f",arrayContrataciones[i].cuit,importePantalla);

                    }

                }
                printf("\nIMPORTE TOTAL -- $%.2f",importeTotal);
                break;

            case 8:
                    contratacion_mostrarTodo(arrayContrataciones,CONTRATACIONES);
                    break;

            case 9:
                   pantalla_mostrarTodo(arrayPantallas,PANTALLAS);
                   break;

            case 10:

                   break;

         }

    }
    return 0;
}


