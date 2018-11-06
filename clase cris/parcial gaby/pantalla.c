#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

static int getNextId()//anda barbaro !
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}


static int pantalla_getLugarLibre(Pantalla* array, int len)//anda barabaro !
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int pantalla_init(Pantalla* array, int len)//inizialisa todas las pantallas en 1
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

Pantalla* pantalla_getById(Pantalla* array, int len,int id)//te trae una pantalla o un null el null te lo retorna cuando no hay una pantalla para retornar. te retorna una pantalla siempre y cuando alla una,es decir que el isEmpty este en 0 y que el id que ingresaron sea igual al id de la pantalla existente.
{
    Pantalla* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].id == id)//pregunta si en el array de pantallas que vos le mandaste no esta en empty y el id es igual al id que le mandaron.
            {
                retorno = &array[i];//te retorna la pantalla entera.
                break;
            }
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* array, int len)//para dar de alta una pantalla solo se le pide los datos al usuario y ya esta.
{
    int retorno = -1;
    int indice;

    char nombre[50];
    char direccion[200];
    float precio;
    int tipo;

    indice = pantalla_getLugarLibre(array,len);

    if( array != NULL && len > 0 &&
        indice >= 0 && indice < len
        && array[indice].isEmpty)
    {
        if( !utn_getNumero(&tipo,"1- cargar LCD \n2- cargar LED\n","\nError, ingrese una opcion valida.",1,2,2) &&
            !utn_getNombre(nombre,50,"Nombre de la pantalla: ","\nError,nombre invalido.\n",2) &&
            !utn_getDescription(direccion,200,"Direccion de la pantalla: ","\nError,direccion invalida.",2)&&
            !utn_getNumeroConComa(&precio,"ingrese el precio de la pantalla: ","\nError,reingrese el precio.",0,99999,2))
        {
            array[indice].tipo = tipo;
            strncpy(array[indice].nombre,nombre,50);
            strncpy(array[indice].direccion,direccion,200);
            array[indice].precio = precio;
            array[indice].isEmpty = 0;
            array[indice].id = getNextId();
            retorno = 0;
        }
    }
    return retorno;
}

int pantalla_modificar(Pantalla* array, int len)//para modificar una pantalla tiene mas pimienta por que primero se le pide el id de la pantalla a modificar,se valida el id y despues a pantalla se le carga una pantalla con el id que ingresaron y despues verificamos que alla una pantalla y si la hay se modifica.
{
    Pantalla* pantalla;//pantalla a modificar
    char auxNombre[50];
    char auxDireccion[200];
    float auxPrecio;
    int tipo;
    int idIngresado;
    int retorno = -1;

    if(utn_getNumero(&idIngresado,"Ingrese el ID de la pantalla a modificar: ","\nError ingrese un ID valido!",0,10000,2) == -1)
    {
        return retorno;
    }
    //aca te toma el id que este en el rango que le pusiste ... pero no te esta validando que antes de modificar estes modificando un id existente por ejemplo vos pones el 2 en idIngresado.... pero no hay un 2 de id de pantalla solamente esta el 0 y el 1 por que cargaron 2 pantallas que pasa con esto ? que te imprime cualquier cosa.
    pantalla = pantalla_getById(array,len,idIngresado);
    if(pantalla != NULL)
    {
        if(array != NULL && len > 0 && //en este if ?? no valga la rebundancia ? por que yo ya verifique arriba... que si pantalla es dinstinto de null y aca lo vuelvo a verificar?
            !pantalla->isEmpty)
        {
              if(!utn_getNumero(&tipo,"\n1- tipo LCD \n2- tipo LED ","\nError, ingrese una opcion valida: ",1,2,2) &&
                 !utn_getNombre(auxNombre,50,"\nIngrese el nuevo nombre: ","\nError,nombre invalido.",2)&&
                 !utn_getDescription(auxDireccion,200,"\nIngrese la nueva direccion: ","\nError,direccion invalida",2)&&
                 !utn_getNumeroConComa(&auxPrecio,"\nIngrese el nuevo precio: ","\nError,precio invalido.",0,10000,2))
             {
                pantalla->tipo = tipo;
                strncpy(pantalla->nombre,auxNombre,50);
                strncpy(pantalla->direccion,auxDireccion,200);
                pantalla->precio = auxPrecio;

                retorno = 0;
             }

        }
    }
    return retorno;
}

int pantalla_baja(Pantalla* array, int len)//esto tiene mas pimienta aun que la de modificar por que ?? bueno por que lo que te pide es el id como en todas pero la diferencia es que una pantalla puede tener muchas contrataciones entonces cuando vos la das de baja tenes que dar de baja las contrataciones que tenia esto asi dice el enunciado....
{
    Pantalla* pantalla;//pantalla a borrar
    int retorno = -1;
    int idIngresado;

  if(utn_getNumero(&idIngresado,"Ingrese el ID de la pantalla a borrar: ","\nError,ingrese un ID valido: ",0,10000,2) == -1)
    {
        return retorno;
    }
    //aca te toma el id que este en el rango que le pusiste ... pero no te esta validando que antes de modificar estes modificando un id existente por ejemplo vos pones el 2 en idIngresado.... pero no hay un 2 de id de pantalla solamente esta el 0 y el 1 por que cargaron 2 pantallas que pasa con esto ? que te modifica o borra cualquier cosa.
    pantalla = pantalla_getById(array,len,idIngresado);
    if(pantalla != NULL)
    {
        if(array != NULL && len > 0 &&
            pantalla->isEmpty == 0)
        {
            pantalla->isEmpty = 1;//estas solamente dando de baja la pantalla pero no las contrataciones.....

            retorno = 0;
        }
        else
        {
            printf("\nNo hay pantalla.");
        }
    }
    return retorno;
}

int pantalla_mostrar(Pantalla* array, int len)
{
    Pantalla* pantalla;
    int retorno = -1;
    int idIngresado;

    if(utn_getNumero(&idIngresado,"Ingrese el ID de la pantalla a mostrar","Error ingrese un ID valido!",0,10000,2) == -1)
    {
        return retorno;
    }
    pantalla = pantalla_getById(array,len,idIngresado);

    if(pantalla != NULL)
    {
        if(array != NULL && len > 0 )
        {
            printf("\n El nombre de la pantalla es: %s",pantalla->nombre);

            if(pantalla->tipo == 1)
            {
                printf("\n La pantalla es tipo LCD");
            }
            else
            {
                printf("\n La pantalla es tipo LED");
            }

            printf("\n La direccion de la pantalla es: %s",pantalla->direccion);
            printf("\n El precio de la pantalla es: %.2f",pantalla->precio);
            printf("\n\n");

            retorno = 0;
        }
        fflush(stdin);
        //__fpurge(stdin);
    }
    return retorno;
}

//void pantalla_ordenar(Pantalla* array, int len)
//{
//    int aux;
//	for(int i = 0; i < len -1; i++)
//    {
//        for(int j = i + 1; j < len; j++)
//        {
//            if(array[i].precio > array[j].precio)
//            {
//                aux = array[i];
//                array[i] = array[j];
//                array[j] = aux;
//            }
//        }
//    }
//}

void pantalla_mostrarTodo(Pantalla* array, int len)
{
    for(int i = 0; i < len; i++)
    {
//        if(array[i].isEmpty == 0)
//        {
            printf("id pantalla es: %d esta vacio... %d nombre %s precio %f dire %s",array[i].id,array[i].isEmpty, array[i].nombre,array[i].precio, array[i].direccion);

        //}
    }
}

