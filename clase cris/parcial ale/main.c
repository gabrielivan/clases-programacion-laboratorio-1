#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#include "contrataciones.h"

#define QTY_PANTALLAS 5
#define QTY_CONTRATACIONES 5

#define NUMERO 100
#define FLOTANTE 100

    /**1) Alta de pantalla: Se solicitan al usuario los datos de la pantalla, para que el sistema
    pueda​ ​ funcionar​ ​ se​ ​ deberá​ ​ generar​ ​ un​ ​ ID​ ​ único​ ​ para​ ​ cada​ ​ pantalla.

    2) Modificar datos de pantalla: Se ingresa el ID de la pantalla, permitiendo modificar sus
    datos.

    3) Baja de pantalla: Se ingresa el ID de la pantalla, se eliminará la pantalla junto con todas
    las​ ​ contrataciones​ ​ de​ ​ publicidad​ ​ para​ ​ esta​ ​ pantalla.

    4) Contratar una publicidad: ​ Se listaran todas las pantallas y se le pedirá al usuario que
    elija la pantalla donde se quiere publicar, ingresando su ID. Luego se pedirán los datos
    asociados a la publicidad: cuit del cliente, cantidad de días que dura la publicación y
    nombre​ ​ del​ ​ archivo​ ​ de​ ​ video​ ​ (p.ej.​ ​ Video1.avi).

    5) Modificar condiciones de publicación: ​ Se pedirá que se ingrese el cuit del cliente y se
    listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus
    campos. Luego de ingresar el ID de la pantalla, se permitirá modificar la cantidad de días
    contratados​ ​ para​ ​ la​ ​ misma.

    6) Cancelar contratación: ​ Se pedirá que se ingrese el cuit del cliente y se listaran todas las
    pantallas de video que el cliente tiene contratadas mostrando todos sus campos. Luego
    ingresar​ ​ el​ ​ ID​ ​ de​ ​ la​ ​ pantalla​ ​ de​ ​ la​ ​ cual​ ​ se​ ​ quiere​ ​ cancelar​ ​ la​ ​ contratación.

    7) Consulta facturación: Se deberá ingresar el cuit del cliente y se deberá listar el importe
    a​ ​ pagar​ ​ por​ ​ cada​ ​ contratación.

    8) Listar contrataciones: ​ Se deberán listar las contrataciones indicando nombre de la
    pantalla,​ ​ nombre​ ​ de​ ​ video,​ ​ cantidad​ ​ de​ ​ días​ ​ y ​ ​ cuit​ ​ de​ ​ cliente.

    9) Listar​ ​ pantallas:​ ​ Se​ ​ deberán​ ​ listar​ ​ las​ ​ pantallas​ ​ existentes​ ​ indicando​ ​ todos​ ​ sus​ ​ campos.
*/

int main()
{
    Pantalla arrayPantallas[QTY_PANTALLAS];
    Contratacion arrayContratacion[QTY_CONTRATACIONES];
    int opcion;
    int i;
    int idIngresado;
    char cuitIngresado[100];
    Pantalla* pantallaBuscada;
    Contratacion* contratacionBuscada;
    float importeTotal;
    float importePantalla;
    int diasContratados;
    float precioPantalla;
    char nombrePantalla[100];
    float importeMayor;
    int idMayorImporte;
    int flag = 0;

    pantalla_init(arrayPantallas,QTY_PANTALLAS,1);
    contratacion_init(arrayContratacion,QTY_CONTRATACIONES,1);


    pantalla_ingresoForzado(arrayPantallas,QTY_PANTALLAS,"Samsung 20 pulgadas","Azcuenaga 3000",0,5);
    pantalla_ingresoForzado(arrayPantallas,QTY_PANTALLAS,"Philips 32 pulgadas","Av.Cordoba 2560",0,10);
    pantalla_ingresoForzado(arrayPantallas,QTY_PANTALLAS,"LG Full HD","Av.Lalala 1430",1,30);
    pantalla_ingresoForzado(arrayPantallas,QTY_PANTALLAS,"BGH 25 pulgadas","Bulnes 500",0,12);
    pantalla_ingresoForzado(arrayPantallas,QTY_PANTALLAS,"Samsung ULTRA HD 45 pulgadas","Av.Santa Fe 5000",0,100);
    contratacion_ingresoForzado(arrayContratacion,QTY_CONTRATACIONES,"23-55666444-9","PROMO.MPG",10,1);
    contratacion_ingresoForzado(arrayContratacion,QTY_CONTRATACIONES,"29-11111111-4","PROMO1.MPG",20,1);
    contratacion_ingresoForzado(arrayContratacion,QTY_CONTRATACIONES,"25-45777222-8","PROMO2.MP4",30,1);
    contratacion_ingresoForzado(arrayContratacion,QTY_CONTRATACIONES,"21-12321321-7","PROMO654.MPEG",50,1);
    contratacion_ingresoForzado(arrayContratacion,QTY_CONTRATACIONES,"29-11111111-4","XXX.MP4",5,1);

do
{
    limpiarPantalla();
    opcion = 0;
    printf("\n1) ALTA DE PANTALLA\n2) MODIFICAR DATOS DE PANTALLA\n3) BAJA DE PANTALLA");
    printf("\n4) CONTRATAR PUBLICIDAD\n5) MODIFICAR CONTRATACION\n6) BAJA PUBLICIDAD\n7) CONSULTA FACTURACION");
    printf("\n8) LISTAR CONTRATACIONES\n9) LISTAR PANTALLAS\n10) INFORMES\n");

    input_ScanInt("\nIngrese una opcion: ",&opcion);

    switch(opcion)
    {
        case 1 :
            printf("\n-- ALTA PANTALLA --");
            pantalla_alta(arrayPantallas,QTY_PANTALLAS);
        break;
        case 2 :
            printf("\n-- MODIFICAR DATOS DE PANTALLA --");
            input_ScanInt("\nIngresar ID a modificar: ",&idIngresado);
            pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
            pantalla_modificar(pantallaBuscada,QTY_PANTALLAS);
        break;
        case 3 :
            printf("\n-- BAJA DE PANTALLA --");
            input_ScanInt("\nIngresar ID a dar de baja: ",&idIngresado);
            pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
            pantalla_eliminar(pantallaBuscada,QTY_PANTALLAS);
        break;
        case 4 :
            printf("\n-- CONTRATAR PUBLICIDAD --");
            pantalla_ordenarId(arrayPantallas,QTY_PANTALLAS);
            input_ScanInt("\nIngresar ID seleccionado: ",&idIngresado);
            contratacion_alta(arrayContratacion,QTY_CONTRATACIONES,idIngresado);
        break;
        case 5 :
            printf("\n-- MODIFICAR CONTRATACION --");
            input_ScanInt("\nIngresar ID a modificar: ",&idIngresado);
            contratacionBuscada = contratacion_getByID(arrayContratacion,QTY_CONTRATACIONES,idIngresado);
            contratacion_modificar(contratacionBuscada,QTY_CONTRATACIONES);
        break;
        case 6 :
            printf("\n-- BAJA PUBLICIDAD --");
            contratacion_mostrar(arrayContratacion,QTY_CONTRATACIONES);
            input_getCuit(cuitIngresado,100,"\nIngrese CUIT","\nError");
                for(i=0;i<QTY_CONTRATACIONES;i++)
                {
                    if(arrayContratacion[i].cuit == cuitIngresado)
                    {
                    idIngresado = arrayContratacion[i].id;
                    contratacionBuscada = contratacion_getByID(arrayContratacion,QTY_CONTRATACIONES,idIngresado);
                    contratacion_eliminar(contratacionBuscada,QTY_CONTRATACIONES);
                    }
                }
        break;
        case 7 :
            printf("\n-- CONSULTA FACTURACION --");
            pantalla_ordenarId(arrayPantallas,QTY_CONTRATACIONES);

                for(i=0;i<QTY_CONTRATACIONES;i++)
                {
                    if(!arrayContratacion[i].isEmpty)
                    {
                        printf("\nCLIENTE CUIT %s\n",arrayContratacion[i].cuit);
                    }
                }


            input_getCuit(cuitIngresado,100,"\nIngrese CUIT: ","\nError");
            importeTotal = 0;

                for(i=0;i<QTY_CONTRATACIONES;i++)
                {
                    if(!strcmp(arrayContratacion[i].cuit,cuitIngresado))
                    {
                    printf("\n CUIT %s\n",cuitIngresado);
                    idIngresado = arrayContratacion[i].idPantalla;
                    diasContratados = arrayContratacion[i].dias;

                    pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
                    precioPantalla = pantallaBuscada->precio;

                    importePantalla = diasContratados * precioPantalla;
                    importeTotal = importeTotal + importePantalla;

                    printf("\nCUIT -- %s\nIMPORTE -- $%.2f",arrayContratacion[i].cuit,importePantalla);
                    continue;
                    }

                }
            printf("\nIMPORTE TOTAL -- $%.2f",importeTotal);
            printf("\nPresione cualquier tecla para continuar...\n");
            getchar();
        break;
        case 8 :
            printf("\n-- LISTAR CONTRATACIONES --");
            limpiarMemoria();
            contratacion_ordenarId(arrayContratacion,QTY_CONTRATACIONES);

            for(i=0;i<QTY_CONTRATACIONES;i++)
            {
                    idIngresado = arrayContratacion[i].id;
                    contratacionBuscada = contratacion_getByID(arrayContratacion,QTY_CONTRATACIONES,idIngresado);
                    idIngresado = arrayContratacion[i].idPantalla;
                    pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
                    strncpy(nombrePantalla,pantallaBuscada->nombre,100);
                    contratacion_listar(contratacionBuscada,QTY_CONTRATACIONES,nombrePantalla);
            }

            printf("\nPresione cualquier tecla para continuar...\n");
            getchar();
        break;
        case 9 :
            limpiarMemoria();
            printf("\n-- LISTAR PANTALLAS --");
            pantalla_ordenarId(arrayPantallas,QTY_PANTALLAS);

                for(i=0;i<QTY_PANTALLAS;i++)
                {
                    idIngresado = i + 1;
                    pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
                    pantalla_listar(pantallaBuscada,QTY_PANTALLAS);
                }

            printf("\nPresione cualquier tecla para continuar...\n");

            getchar();
        break;
        case 10 :
            limpiarMemoria();
            contratacion_ordenarId(arrayContratacion,QTY_CONTRATACIONES);

            for(i=0;i<QTY_CONTRATACIONES;i++)
            {
                importeTotal = 0;

                if(!arrayContratacion[i].isEmpty)
                {
                    printf("\nCLIENTE CUIT %s\n",arrayContratacion[i].cuit);
                    idIngresado = arrayContratacion[i].idPantalla;
                    diasContratados = arrayContratacion[i].dias;

                    pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
                    precioPantalla = pantallaBuscada->precio;

                    importePantalla = diasContratados * precioPantalla;
                    importeTotal = importeTotal + importePantalla;

                        if(importeTotal>importeMayor || flag == 0)
                        {
                        importeMayor = importeTotal;
                        idMayorImporte = arrayContratacion[i].id;
                        flag = 1;
                        }

                    printf("\nCUIT -- %s\nIMPORTE -- $%.2f",arrayContratacion[i].cuit,importePantalla);
                   }

             }
                contratacionBuscada = contratacion_getByID(arrayContratacion,QTY_CONTRATACIONES,idMayorImporte);

                printf("\n\nCLIENTE MAYOR IMPORTE -- %d",idMayorImporte);
                printf("\nCUIT -- %s",contratacionBuscada->cuit);
                printf("\nIMPORTE -- $%.2f",importeMayor);




            printf("\nPresione cualquier tecla para continuar...\n");
            getchar();
        break;
        }

}while(opcion != 11);



    return 0;
}
