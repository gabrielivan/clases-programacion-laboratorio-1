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




   //ABM DE PANTALLA
    printf("\n\nCARGAR PANTALLA\n\n");
    pantalla_alta(arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO LA CARGA DE PANTALLA\n\n");

//    printf("\n\nCARGAR SEGUNDA PANTALLA\n\n");
//    pantalla_alta(arrayPantallas,PANTALLAS);
//    printf("\n\nFINALIZO LA CARGA DE LA SEGUNDA PANTALLA\n\n");
//
    printf("\n\nMUESTRA DE PANTALLA\n\n");
    pantalla_mostrar(arrayPantallas,PANTALLAS);
    printf("\n\nFINALIZO LA MUESTRA DE PANTALLA\n\n");
//
//    printf("\n\nMODIFICAR PANTALLA\n\n");
//    pantalla_modificar(arrayPantallas,PANTALLAS);
//    printf("\n\nFINALIZO LA MODIFICACION DE PANTALLA\n\n");
//
//    printf("\n\nMUESTRA DE PANTALLA\n\n");
//    pantalla_mostrar(arrayPantallas,PANTALLAS);
//    printf("\n\nFINALIZO LA MUESTRA DE PANTALLA\n\n");
//
//    printf("\n\nBORRAR PANTALLA\n\n");
//    pantalla_baja(arrayPantallas,PANTALLAS);
//    printf("\n\nFINALIZO EL BORRADO DE PANTALLA\n\n");
//
//    printf("\n\nMUESTRA DE PANTALLA\n\n");
//    pantalla_mostrar(arrayPantallas,PANTALLAS);
//    printf("\n\nFINALIZO LA MUESTRA DE PANTALLA\n\n");

   //TERMINA EL ABM DE PANTALLA //HASTA ACA TODO DE FIESTA

   //ABM DE CONTRATACIONES

    printf("\n\nCARGAR CONTRATACION\n\n");
   int retornoAlta =  contratacion_alta(arrayContrataciones,arrayPantallas,CONTRATACIONES,PANTALLAS);
   if(retornoAlta == 0)
        printf("\n\nFINALIZO LA CARGA DE CONTRATACION\n\n");
    else printf("fallo la carga de contratacion");
    //ANDA BARABARO


    //recorro y printeo el array de contrataciones
    contratacion_mostrarTodo(arrayContrataciones,CONTRATACIONES);



    printf("\n\nMODIFICAR CONTRATACION\n\n");
    contratacion_modificar(arrayContrataciones,CONTRATACIONES,arrayPantallas,PANTALLAS);//tiene un error.
    printf("\n\nFINALIZO LA MODIFICACION DE PANTALLA\n\n");
//    //ACA ANDA TODO COMO EL ORTO POR QUE ?? Y BUENO POR QUE NO TE RECONOCE EL ID PARA INTERACTUAR ENTRE LAS 2 ENTIDADES EN ESTE CASO NO RECONOCE EL ID DE LA PANTALLA .

    contratacion_mostrarTodo(arrayContrataciones,CONTRATACIONES);

//    printf("\n\nBORRAR CONTRATACION\n\n");
//    contratacion_baja(arrayContrataciones,CONTRATACIONES,cuitIngresado,arrayPantallas,PANTALLAS);//tiene un error.
//    printf("\n\nFINALIZO EL BORRADO DE CONTRATACION\n\n");
//    //ACA ANDA TODO COMO EL ORTO TAMBIEN POR QUE ?? Y BUENO MAS DE LO MISMO....POR QUE NO TE RECONOCE EL ID PARA INTERACTUAR ENTRE LAS 2 ENTIDADES EN ESTE CASO NO RECONOCE EL ID DE LA PANTALLA
   return 0;
   }




