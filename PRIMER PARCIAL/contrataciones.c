#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "contrataciones.h"


/**
*\brief Genera automáticamente un ID único
*\param void
*\return Retorna el número de ID
*/

static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

/**
*\brief Busca el indice libre en un array
*\param array Es el array que reciba para recorrer
*\param len Es el tamaño del array
*\return Retorna el indice del lugar libre si no retorna -1
*/

static int contratacion_getLugarLibre(Contratacion* array, int len)
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

/**
*\brief Inicializa todos los elementos de un array con un valor de vacio
*\param array Es el array que reciba para recorrer
*\param len Es el tamaño del array
*\return Retorna 0 si esta todo bien sino en caso de error retorna -1
*/

int contratacion_init(Contratacion* array, int len)
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

void contratacion_mostrarByCuit(Contratacion* array, int len,char cuit[])//en este caso el cuit es el cliente, poruqe es el unico dato que tenemos del cliente para relacionarlo con una contratacion..
{                                                                        //esto tambien se podria leer como contratacion by cliente .... recibe el cuit del cliente y te muestra que contratacion tiene
    int i;
    if(array != NULL && len > 0)
    {
         limpiarMemoria();
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && strncmp(array[i].cuit,cuit,14) == 0)
            {
                printf("El ID de la contratacion es: %d \n",array[i].id);
                printf("El nombre de archivo de video de la contratacion es: %s \n",array[i].nombreVideo);
                printf("Los dias de la contratacion son: %d \n",array[i].dias);
                printf("El ID de la pantalla es: %d \n",array[i].pantallaId);
            }
             limpiarMemoria();
        }
    }

}

/**
*\brief Busca un elemento por el ID del otro dentro de un array de estructuras
*\param array Es el array que reciba para recorrer
*\param len Es el tamaño del array
*\param pantallaId Es el ID que recibe para buscar
*\return Retorna el puntero del elemento si no retorna NULL
*/

Contratacion* contratacion_getByPantalla(Contratacion* array,int len,int pantallaId)//te trae una contratacion by pantalla en este caso le mandas el id de la pantalla(que es uno de los tantos datos que tiene la estructura pantalla),para que atraves de ese id te de una contratacion es decir...
                                                                                    //es decir que te da la contratacion que tiene esa pantalla que vos le mandaste
{

    for(int i = 0; i < len; i++)
    {
        if(array[i].pantallaId == pantallaId)//pregunta si el array de contrataciones que vos le mandaste en el campo pantallaId es igual al id que vos le acabas de mandar de una pantalla.
        {
            return &array[i];
        }
    }
    return NULL;
}

/**
*\brief Realiza el alta de un elemento del array
*\param array Es el array que reciba para recorrer
*\param arrayPantalla Es el otro array a recorrer
*\param len es el tamaño del array
*\return Retorna 0 sino en caso de error retorna -1
*/

int contratacion_alta(Contratacion* array,Pantalla* arrayPantalla, int len,int lenPantalla)//en este caso dar de alta una entidad compleja es mas dificil,porque primero necesita el id de la otra entidad en este caso el id de la pantalla para que vos puedas cargar una contratacion en esa pantalla
{
    int retorno = -1;
    int indice;
    char cuit[14];
    int dias;
    char nombreVideo[100];
    int idIngresado;

    if(utn_getNumero(&idIngresado,"Ingrese el id de la pantalla: ","Error,ingrese un id valido: ",0,10000,2)== -1)//le pedis el id de la pantalla la cual quiere hacer una contratacion
    {
        return retorno;
    }
    if(pantalla_getById(arrayPantalla,lenPantalla,idIngresado)!= NULL)//necesitas que te traigan la pantalla para que le puedas hacer la contratacion
    {
        if( array != NULL && len > 0 )
        //si entraste aca significa que ya te dieron una pantalla por que el id que ingresaste coincidio con el de la pantalla entonces recien ahi cargas la contratacion
        {
           if(
                !utn_getCuit(cuit,"Ingrese cuit del cliente: ","\nNo es un cuit valido,reingrese: ",2) &&
                !utn_getNombre(nombreVideo,100,"Ingrese el nombre del archivo de video: ","\nNombre no valido,reingre el nombre:\n",2) &&
                !utn_getNumero(&dias,"Ingrese la duracion de la publicidad en dias: ","\nError reingrese el dia: ",1,365,2)
               )

            {
                indice = contratacion_getLugarLibre(array,len);// tomas un lugar libre para cargar los datos ahi ...

                strncpy(array[indice].cuit,cuit,14);
                strncpy(array[indice].nombreVideo,nombreVideo,100);
                array[indice].dias = dias;
                array[indice].isEmpty = 0;
                array[indice].id = getNextId();
                array[indice].pantallaId = idIngresado;//significa que como ya tenes el id de la pantalla   agarras el id  y se lo asignas a tu pantallaid(que es de contrataciones)
                                                        //en resumen acabas de poner en tu campo (pantallaid)de tu estructura (contrataciones) un id de una pantalla existente de la estructura(pantalla)
                retorno = 0;

            }

        }

    }
    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param arrayPantalla Es el puntero que recibe del elemento del otro array
*\param len Es el tamaño del array
*\param lenPantalla es el tamaño del arrayPantalla
*\return Retorna 0 si esta todo bien sino retorna -1
*/

int contratacion_modificar(Contratacion* array, int len, Pantalla* arrayPantallas, int lenPantallas)
{
    int auxDias;
    char cuitIngresado[14];
    int retorno = -1;
    int idIngresado;
    Contratacion* contratacionElegida;
    //lo primero que pide es un dato del cliente que hizo la contratacion en este caso el unico dato que tenemos es el cuit del cliente
    utn_getCuit(cuitIngresado,"Ingrese el cuit del cliente: ","\nError ingrese un cuit valido: ",2);

    printf("CONTATACIONES DEL CLIENTE: %s ",cuitIngresado);

    contratacion_mostrarByCuit(array,len,cuitIngresado); //mostramos todas las contrataciones que tiene ese cliente(cuit)

    utn_getNumero(&idIngresado,"Ingrese el id de la pantalla: ","\nError,ingrese un id valido: ",0,10000,2); //tomamos el id de la pantalla en la cual tenes una contratacion

    contratacionElegida = contratacion_getByPantalla(array,len,idIngresado); //tomamos una contratacion por el id de la pantalla
    if(contratacionElegida != NULL)
    {
        if(!utn_getNumero(&auxDias,"Ingrese la cantidad de dias de contratacion: ","\nError reingrese el dia: ",1,365,2))
        {
            contratacionElegida->dias = auxDias;
            retorno = 0;
        }

    }
        else
        {
            printf("El id de la pantalla no pertence al cuit ingresado");
        }
    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param arrayPantalla Es el puntero que recibe del elemento del otro array
*\param len Es el tamaño del array
*\param lenPantalla es el tamaño del arrayPantalla
*\return Retorna 0 si esta todo bien sino retorna -1
*/

int contratacion_baja(Contratacion* array, int len,Pantalla* arrayPantallas, int lenPantallas)
{
    int retorno = -1;
    char cuitIngresado[14];
    int idIngresado;
    Contratacion* contratacionElegida;

    //lo primero que pide es un dato del cliente que hizo la contratacion en este caso el unico dato que tenemos es el cuit del cliente
    utn_getCuit(cuitIngresado,"Ingrese el cuit del cliente: ","\nError ingrese un cuit valido: ",2);
    printf("CONTATACIONES DEL CLIENTE: %s ",cuitIngresado);

    contratacion_mostrarByCuit(array,len,cuitIngresado); //mostramos todas las contrataciones que tiene ese cliente(cuit)

    utn_getNumero(&idIngresado,"Ingrese el id de la pantalla: ","\nError,ingrese un id valido: ",0,10000,2);//tomamos el id de la pantalla en la cual tenes una contratacion

    contratacionElegida = contratacion_getByPantalla(array,len,idIngresado);//tomamos una contratacion por el id de la pantalla

     if(contratacionElegida != NULL && contratacionElegida->isEmpty == 0)
    {
        contratacionElegida->isEmpty = 1;
    }
    else
    {
        printf("El id de la pantalla no pertence al cuit ingresado");
    }
    return retorno;
}


void contratacion_mostrar(Contratacion* array, int len)
{
    Contratacion* contratacion;
    int idIngresado;


    if(utn_getNumero(&idIngresado,"Ingrese el id de la pantalla que tiene su contratacion: ","\nError reingrese un id correcto: ",0,1000,2) == -1)
    {
        return;
    }

    contratacion = contratacion_getByPantalla(array,len,idIngresado);

    if(contratacion != NULL)
    {
        if(array != NULL && len > 0)
        {
            printf("\n El nombre del archivo video es: %s",contratacion->nombreVideo);
            printf("\n Los dias de duracion de la contratacion es: %d",contratacion->dias);
            printf("\n\n");
        }
    }
   limpiarMemoria();
}

/**
*\brief Lista los datos de todos los elementos del array
*\param array Es el array que recibe para recorrer
*\param len Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

void contratacion_mostrarTodo(Contratacion* array, int len)
{
     limpiarMemoria();

    for(int i = 0; i < len; i++)
    {
        if(array[i].isEmpty == 0)
        {
            printf("El ID de la contratacion es: %d\n",array[i].id);
            printf("El ID de la pantalla es: %d\n",array[i].pantallaId);
            printf("El nombre del archivo de video de la contratacion es: %s\n",array[i].nombreVideo);
            printf("Los dias de la contratacion son: %d\n",array[i].dias);
            printf("El CUIT del cliente  de esta contratacion es: %s\n",array[i].cuit);
        }
         printf("\n\n");
        limpiarMemoria();
    }
}

int cont_altaForzada(Contratacion* arrayContratacion,int lenArrayContratacion,
                     Pantalla* arrayPantallas, int lenPantallas,
                     int idPantalla,char* nombreVideo,char* cuit,int dias)
{
    int retorno = -1;
    int i;
    int posPant;
    if(lenArrayContratacion > 0 && arrayContratacion != NULL)
    {
        i = contratacion_getLugarLibre(arrayContratacion,lenArrayContratacion);
        if(i >= 0)
        {
            posPant = pantalla_buscarPorId(arrayPantallas,lenPantallas,idPantalla);
            if(posPant>=0)
            {
                arrayContratacion[i].dias = dias;
                strcpy(arrayContratacion[i].cuit,cuit);
                strcpy(arrayContratacion[i].nombreVideo,nombreVideo);
                //TODO
                arrayContratacion[i].pantallaId = idPantalla; // relacion
                arrayContratacion[i].isEmpty = 0;
                arrayContratacion[i].id = getNextId();
            }
        }
        retorno = 0;
    }
    return retorno;
}

