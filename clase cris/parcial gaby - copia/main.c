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
    Pantalla arrayPantallas[PANTALLAS];
    Contratacion arrayContrataciones[CONTRATACIONES];

    pantalla_init(arrayPantallas,PANTALLAS);
    contratacion_init(arrayContrataciones,CONTRATACIONES);

    pantalla_altaForzada(arrayPantallas,PANTALLAS,"Samsung","LasFlores",1000,1);
    pantalla_altaForzada(arrayPantallas,PANTALLAS,"LG","Belgrano",1000,1);
    pantalla_altaForzada(arrayPantallas,PANTALLAS,"Lenovo","Cerrito",1000,1);
    pantalla_altaForzada(arrayPantallas,PANTALLAS,"Apple","Lavalle",1500,2);
    pantalla_altaForzada(arrayPantallas,PANTALLAS,"Huawey","Mitre",2000,2);

    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,0,"videoavi","20-91191191-5",7);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,1,"videoavi","20-91191191-5",14);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,2,"videoavi","30-91191191-5",21);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,3,"videoavi","30-91191191-5",28);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,4,"videoavi","40-91191191-5",35);
    cont_altaForzada(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS,5,"videoavi","40-91191191-5",42);




   //ABM DE PANTALLA
    printf("\n\nMUESTRA DE PANTALLA\n\n");
    pantalla_mostrarTodo(arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO LA MUESTRA DE PANTALLA\n\n");

    printf("\n\nMODIFICAR PANTALLA\n\n");
    pantalla_modificar(arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO LA MODIFICACION DE PANTALLA\n\n");

    printf("\n\nMUESTRA DE PANTALLA\n\n");
    pantalla_mostrarTodo(arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO LA MUESTRA DE PANTALLA\n\n");

    printf("\n\nBORRAR PANTALLA\n\n");
    pantalla_baja(arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO EL BORRADO DE PANTALLA\n\n");

    printf("\n\nMUESTRA DE PANTALLA\n\n");
    pantalla_mostrarTodo(arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO LA MUESTRA DE PANTALLA\n\n");

   //TERMINA EL ABM DE PANTALLA //HASTA ACA TODO DE FIESTA

   //ABM DE CONTRATACIONES

    //ANDA BARABARO
    printf("MUESTRA DE TODAS LAS CONTRATACIONES\n");
    contratacion_mostrarTodo(arrayContrataciones,CONTRATACIONES);
    printf("FINALIZO LA MUESTRA DE TODAS LAS CONTRATACIONES\n");

    printf("\n\nMODIFICAR CONTRATACION\n\n");
    contratacion_modificar(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO LA MODIFICACION DE PANTALLA\n\n");

    printf("MUESTRA DE TODAS LAS CONTRATACIONES\n");
    contratacion_mostrarTodo(arrayContrataciones,CONTRATACIONES);
    printf("FINALIZO LA MUESTRA DE TODAS LAS CONTRATACIONES\n");

    printf("\n\nBORRAR CONTRATACION\n\n");
    contratacion_baja(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO EL BORRADO DE CONTRATACION\n\n");

    printf("MUESTRA DE TODAS LAS CONTRATACIONES\n");
    contratacion_mostrarTodo(arrayContrataciones,CONTRATACIONES);
    printf("FINALIZO LA MUESTRA DE TODAS LAS CONTRATACIONES\n");

   return 0;
   }




